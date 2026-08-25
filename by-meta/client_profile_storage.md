*** UID:0001QL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Profile Storage

## UID0000MS Eight-Section Persistence Synchronization - 2026-08-25

The modern `.usr` stream is an ordered eight-group binary contract shared by [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) and [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md). The writer and loader must remain inverse at the source level without adding safety behavior absent from the executable.

| Group | On-disk shape | Exact load semantics |
| --- | --- | --- |
| 1 | Ten `uint16` lengths plus UTF-16 profile-text payloads. | Length over `0x7f` returns immediately and leaks the open stream; accepted payload is NUL-terminated. |
| 2 | Ten single UTF-16 legacy-shortcut characters. | Exactly ten reads; each two-wide destination receives a local terminator. |
| 3 | Twenty `uint16` lengths plus UTF-16 friend-name payloads. | Rebuilds `m_friendNames[20]` through StringBase detach/read/lock. |
| 4 | One `uint16` length plus selected-profile payload. | Unchecked direct read into the 0x100-wide field and terminator at the file-provided index. |
| 5 | Optional `uint32 count`; each row is `uint32 length` plus UTF-16 payload. | On successful count read, clears `m_blockListenNames`, trusts both values, and pushes each row. |
| 6 | Literal dword `1`; twenty UTF-16 code/mode pairs. | Any successfully read dword enables twenty rows; only `L'S'` sets the byte-like mode true. |
| 7 | Dword `30`; each row is type wchar, `uint16` length, and UTF-16 payload. | Count is trusted. `T/S/I` become states `1/2/3`; unknown type retains default. Length `>=0x80` leaves payload unread and desynchronizes later input. |
| 8 | Dword `2`; each row is user/monster `L'1'` or `L'0'`. | Count is trusted and the two character comparisons become booleans. |

Writer I/O results are ignored. Loader `fread` results are ignored except where a successful optional-section count/presence read gates the section. Do not clamp optional counts, consume oversized macro payloads, close on the group-one oversize return, or bound the selected-profile read; each would change original malformed-file behavior.

Legacy `.cfg` migration reads ten profile-text rows, ten legacy shortcuts, twenty friend names, and one selected-profile quoted UTF-16 field through a 512-wide scratch buffer, truncating only the selected-profile copy at index 255. It closes and deletes the legacy file after successful import. Migration uses `(isSpellMode != 1) + 2`, preserving the distinction between exact byte value one and all other values.

Current source storage is direct `Config` field access. The sole `RegistryConfig` cast is for nonvirtual `InitializeUserDataDefaults()`. The current friend field is `m_friendNames`; older `m_profileStringSlots` and broad derived-storage casts are historical assumptions only.

## Status

- Confidence: strong for file paths and serialized layout; medium for final field names.
- Scope: local user profile/settings files, legacy migration, and the cross-module selected-profile sidecar portrait contract.
- Evidence basis: `simroot_v2/recovered/LoadUserProfileData_004F95B0.cpp`, `SaveUserSettings_0050ABA0.cpp`, `ImportLegacyUserProfileData_004F9280.cpp`, `RefreshSelectedProfileData_005063E0.cpp`, `class_RegistryConfig.cpp`, macro-dialog/hotkey consumers, IDA MCP lookup/caller/decompile checks on 2026-05-25, and the accepted 2026-07-28 UID0001DU receiver/source-route reanalysis.

## Source Ownership

Profile persistence belongs in [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md), not in [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) or [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md).

`ProfileStorage.cpp` should own:

- `ImportLegacyUserProfileData` at `0x004f9280-0x004f95a2`;
- `LoadUserProfileData` at `0x004f95b0-0x004f9d28`;
- `SaveUserSettings` at `0x0050aba0-0x0050b078`.

The serialized fields are offsets inside [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md), so `ProfileStorage.cpp` depends on the config object layout but does not own `RegistryConfig`.

Selected-profile sidecar behavior crosses this persistence contract but has a different source route. [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) is `void MapPane::RefreshSelectedProfileData()` in [UID:0000L3][MapPane](by-file/MapPane.md). [UID:00027P][0x0066dd60-0x0066dd78.ImageExtensionPointerTable](by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md) is its one MapPane.cpp file-local extension table, and [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md) is non-emitting MapPane source-literal evidence. [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) is the separate ProfileDialog.cpp forwarding trigger through [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md).

## `.usr` Paths

Modern profile files are binary files under:

```text
%USERPROFILE%\Documents\NexusTK\users\<user-id>.usr
```

Observed behavior:

- `LoadUserProfileData` calls `RegistryConfig::InitializeUserDataDefaults` before reading any file.
- The loader creates/checks `Documents\NexusTK` and `Documents\NexusTK\users`, then tries the documents-path `.usr` file.
- If the documents-path file is absent, the loader falls back to the current-directory path `users/<user-id>.usr`.
- If both modern `.usr` paths are absent, it calls `ImportLegacyUserProfileData`.
- If `SHGetFolderPathW(CSIDL_PERSONAL)` fails, or if `Documents\NexusTK` / `Documents\NexusTK\users` cannot be created and the error is not `ERROR_ALREADY_EXISTS`, the loader returns with default user-data state. The current-directory `.usr` fallback and legacy `.cfg` importer are not reached in those failure paths.
- `SaveUserSettings` writes only to the documents-path `.usr` file. It calls SetFileAttributesW with `FILE_ATTRIBUTE_NORMAL` and deletes the previous file without checking either result, then opens a new file with `wb`; open failure can therefore leave no profile file.
- `<user-id>` is produced by the shared helper at `0x005a2da0` with a `0x28` wide-character capacity.

## `.usr` Binary Layout

All observed strings are Windows `wchar_t` data, so the stored character units are 16-bit little-endian in this build. Length-prefixed strings store a character count, not a byte count, and do not include a trailing null terminator.

| Order | Encoding | Target config offset | Count | Notes |
| --- | --- | --- | --- | --- |
| 1 | `uint16 length` + one `fwrite` of `2 * length` bytes | `+0x28de9c + i * 0x100` | 10 | Fixed wide-string slots; writer narrows `wcslen` to uint16 and stores no NUL. |
| 2 | one wide char per slot | `+0x28e89c + i * 0x100` | 10 | Legacy single-character shortcut slots; loader writes a null after the stored char. |
| 3 | narrowed `uint16 length` + one `fwrite` of `2 * length` bytes | `+0x2911e0 + i * 4` | 20 | Pointer-backed `SimpleUString`-style handles. |
| 4 | `uint16 length` + `length` wide chars | `+0x2912b8` | 1 | Current selected profile/name field; appended to opcode `79` by sidecar refresh. Sidecar filenames use the local-player-name helper at `0x005a2dc0`, not this field. |
| 5 | `uint32 count`, then `uint32 length` + `fwrite(text, 2, length)` per entry | vector at `+0x2918fc/+0x291900/+0x291904` | variable | Dynamic block-listen name vector of four-byte pointer-backed string handles. |
| 6 | literal `uint32 1`, then 20 pairs of wide chars | `+0x28f29c + i * 4` | 20 | Leading dword is an optional-tail presence/version marker, not row count. Writer emits code plus `S` when byte `+2` is nonzero, else `I`; byte `+3` is not serialized. |
| 7 | `uint32 count`, then [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) serialized rows | state view at `+0x28f2f0 + i * 0x108`; internal row base at `+0x28f2ec + i * 0x108` | writer uses 30 | Integrated macro/hotkey records. Type code `T` maps to state `1` text macro, `S` maps to state `2` spell-tab binding, and `I` maps to state `3` inventory/item-tab binding; text/key payload is a fixed wide string with max `0x7f` stored chars. |
| 8 | literal `uint32 2`, then two wide-char booleans per row | `+0x2911dc + i * 2` | 2 | Only a source byte exactly equal to 1 emits `L'1'`; every other byte value emits `L'0'`. |

The loader treats sections 5 through 8 as progressive optional tails: it proceeds only if the next `uint32` can be read. This supports older shorter files.

Serialization caveat resolved to an exact corrupt-state hazard: the writer emits no type character when a [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) state is outside `1..3`, but still writes the uint16 length and text, while the loader consumes one type character per row. IDA MCP decompilation of `RegistryConfig::InitializeUserDataDefaults` shows all 30 rows default to state `2`; normal default/load/UI paths write only states `1`, `2`, or `3`. Reconstructed source must preserve the malformed-stream behavior rather than inventing a default type or clean-state guard.

## Save Failure And Caller Contract

- `SHGetFolderPathW(CSIDL_PERSONAL)` must return exactly `S_OK`. Each directory creation accepts failure only when the immediately sampled `GetLastError()` is `ERROR_ALREADY_EXISTS`; other failures return before file mutation.
- `GetLocalPlayerName(wchar_t *destination, size_t capacity)` receives capacity `0x28` and its result is ignored. Caller-local `swprintf_s`, not a project `WideFormatWrapper`, builds both directory paths.
- The writer ignores every `fwrite`, `fputwc`, and `fclose` result. Mid-stream write failure continues into later sections and can leave a partial/truncated stream. There is no temporary file, atomic rename, retry, rollback, exception, user-visible error, or status result.
- Eight exact xrefs exist: MapPane exit `0x00504850` and FriendList `0x0053f8f8` save unconditionally; raw OptionPane `0x0053dd8c`, modeled OptionPane `0x0053dfb8`, SpellMacro `0x0053ed6e`, NewMacro `0x0053f15c`, IntegrateMacro `0x005420a7`, and TargetOption `0x0054252a` gate the call on `g_activeMapPane` where reachable. FriendList performs optional opcode `0x77` synchronization before its unconditional save.
- Raw OptionPane `[0x0053dd70,0x0053dda6)` has no function record or inbound start/pointer route and remains support-only rather than an emitter. Its following `[0x0053dda6,0x0053ddb0)` range is ten `0xcc` bytes.
- `Config *g_pConfig` points to the runtime `RegistryConfig` instance. ProfileStorage source uses an explicit derived cast for the embedded user-profile fields; this relationship does not move serialization ownership into RegistryConfig.

## Legacy `.cfg` Import

Legacy profile import reads from:

```text
.\users\<user-id>.cfg
```

The legacy file is a quoted-wide-string format. It imports only the older prefix of the profile block:

- 10 quoted strings into `+0x28de9c`;
- 10 quoted strings into `+0x28e89c`;
- 20 quoted strings into `+0x2911e0`;
- one quoted string into `+0x2912b8`, truncated at `0xff` characters if needed.

After a successful import, `ImportLegacyUserProfileData` deletes the `.cfg` file. It does not write the new `.usr` directly; later save paths persist the modern layout.

## Shortcut Migration

After `.usr` load, `LoadUserProfileData` migrates legacy and compact shortcut state:

- nonempty legacy single-character slots at `+0x28e89c + i * 0x100` are copied into compact slots at `+0x28f29c + i * 4`, marked with byte `+2 = 1`, and cleared;
- compact slots with nonzero code points are promoted into [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows at `+0x28f2f0 + i * 0x108`;
- promoted macro/hotkey state is `2` when compact byte `+2` is `1`, otherwise `3`; the resolved labels are state `2` / `S` for spell-tab bindings and state `3` / `I` for inventory/item-tab bindings;
- the promoted code point is written at entry offset `+4`, and the compact code point is cleared.

This means the compact section is an intermediate compatibility layer rather than the final runtime representation.

## Selected Profile Sidecars

`MapPane::RefreshSelectedProfileData` uses the local-player-name buffer [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md) through helper `0x005a2dc0` as the sidecar filename stem. It uses the ProfileStorage-related selected profile/name field at `g_pConfig + 0x2912b8` as the profile text appended to outbound opcode `79`.

Observed sidecar behavior:

- It checks `bmp`, `pcx`, `jpg`, `jpeg`, and `pnm` files in `Documents\NexusTK\users` using the local-player-name stem.
- If any sidecar image exists, it launches `FaceRipper.exe <path>` and waits up to `10000` ms.
- It then looks for `<local-player-name>.jpf` in `Documents\NexusTK\users`, with `./users/<local-player-name>.jpf` as a fallback.
- Missing or invalid `.jpf` data sends profile refresh packet opcode `79` with length `0` plus the selected profile name.
- Present `.jpf` data must be smaller than `0x2710` bytes.
- The `.jpf` payload is decoded through [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md); only a decoded span of `48 x 56` causes the profile name to be appended to the outbound packet.
- All three live invocation sites prepare a MapPane receiver. The packet path restores the complete MapPane object with `lea ecx,[esi-0xa0]`; both ProfileDialog routes load `g_activeMapPane`. Incoming `this` is optimized unused inside the callee, so the old cdecl-shaped decompile does not change its source member contract.
- The exact five extensions come from UID00027P; the extension/path/FaceRipper/JPF literals in UID0003IV are regenerated by ordinary MapPane source and intentionally have no separate emitter. ProfileStorage.cpp emits neither the member, table, nor literal block.

## IDA MCP Evidence

- `lookup_funcs` confirms `0x004f9280` size `0x322`, `0x004f95b0` size `0x778`, `0x0050aba0` size `0x4d8`, and `0x005063e0` size `0x582`.
- `callers` confirms `ImportLegacyUserProfileData` is called only from `LoadUserProfileData`.
- `callers` confirms `LoadUserProfileData` is called from `0x004f7d10` at `0x004f8a83`.
- `xrefs_to` confirms `SaveUserSettings` is shared by eight exact callsites: `0x00504850`, `0x0053dd8c`, `0x0053dfb8`, `0x0053ed6e`, `0x0053f15c`, `0x0053f8f8`, `0x005420a7`, and `0x0054252a`.
- `callers` confirms `MapPane::RefreshSelectedProfileData` is called from `MapPane::HandlePacket` at `0x005089e3` and from profile dialog flow at `0x0053fe65`; IDA also models `0x0053fe90` as a two-instruction ProfileDialog-neighborhood tail-jump wrapper that loads `g_activeMapPane` before forwarding to the same member.
- `decompile 0x0048ebc0` confirms the macro/hotkey defaults: 30 rows at `+0x28f2ec/+0x28f2f0`, state `2`, slot ordinals `0..29`, and default key text `a..z, A..D`.
- `decompile 0x004b83d0`, `0x00580320`, `0x005805e0`, and `0x005a3ae0` confirms the same row contract is edited by `IntegrateMacroEditControlPane` and consumed by `LivingObjectPane::ExecuteHotkeyAction`; `GeneralPurposePanel` child index `2` is inventory, child index `3` is spell inventory, and `OnKeyEvent` maps those tabs to states `3`/`I` and `2`/`S` respectively.

## Historical Ownership Correction - 2026-07-28

- Earlier B003/current-meta wording placed UID0001AS in ProfileStorage.cpp because the method performs profile filesystem, JPF, image decode, and opcode-79 work and the decompiler did not expose an incoming `this` use.
- That behavior remains valid and is intentionally preserved in this meta page. The source-owner conclusion is superseded: every caller prepares a MapPane receiver, the body lies in a MapPane code cluster, and the only extension table lies between MapPane data tables. The current human source is a MapPane member with ProfileStorage/config dependencies, not a ProfileStorage free helper.
- This correction leaves all modern `.usr`, legacy `.cfg`, optional-tail, shortcut migration, malformed-stream, save failure, caller, and selected-profile-field contracts intact. It changes only the implementation ownership and one-definition topology of the sidecar method/table/literals and adds the separate ProfileDialog trigger.

## Cross-References

- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)
- [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md)
- [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md)
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md)
- [UID:00027P][0x0066dd60-0x0066dd78.ImageExtensionPointerTable](by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md)
- [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md)
- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
