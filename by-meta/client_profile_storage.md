*** UID:0001QL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Profile Storage

## Status

- Confidence: strong for file paths and serialized layout; medium for final field names.
- Scope: local user profile/settings files, legacy migration, and selected-profile sidecar portrait refresh.
- Evidence basis: `simroot_v2/recovered/LoadUserProfileData_004F95B0.cpp`, `SaveUserSettings_0050ABA0.cpp`, `ImportLegacyUserProfileData_004F9280.cpp`, `RefreshSelectedProfileData_005063E0.cpp`, `class_RegistryConfig.cpp`, macro-dialog/hotkey consumers, and IDA MCP lookup/caller/decompile checks on 2026-05-25.

## Source Ownership

Profile storage belongs in [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md), not in [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) or [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md).

`ProfileStorage.cpp` should own:

- `ImportLegacyUserProfileData` at `0x004f9280-0x004f95a2`;
- `LoadUserProfileData` at `0x004f95b0-0x004f9d28`;
- `SaveUserSettings_50ABA0` at `0x0050aba0-0x0050b078`;
- `RefreshSelectedProfileData` at `0x005063e0-0x00506962`, unless a later split creates a narrower profile-image helper file.

The serialized fields are offsets inside [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md), so `ProfileStorage.cpp` depends on the config object layout but does not own `RegistryConfig`.

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
- `SaveUserSettings_50ABA0` writes only to the documents-path `.usr` file. It clears normal attributes, deletes the previous file, then opens a new file with `wb`.
- `<user-id>` is produced by the shared helper at `0x005a2da0` with a `0x28` wide-character capacity.

## `.usr` Binary Layout

All observed strings are Windows `wchar_t` data, so the stored character units are 16-bit little-endian in this build. Length-prefixed strings store a character count, not a byte count, and do not include a trailing null terminator.

| Order | Encoding | Target config offset | Count | Notes |
| --- | --- | --- | --- | --- |
| 1 | `uint16 length` + `length` wide chars | `+0x28de9c + i * 0x100` | 10 | Fixed wide-string slots, max `0x7f` characters. |
| 2 | one wide char per slot | `+0x28e89c + i * 0x100` | 10 | Legacy single-character shortcut slots; loader writes a null after the stored char. |
| 3 | `uint16 length` + simple-string text | `+0x2911e0 + i * 4` | 20 | `SimpleUString`-style string object slots. |
| 4 | `uint16 length` + `length` wide chars | `+0x2912b8` | 1 | Current selected profile/name field; also used by sidecar `.jpf` refresh. |
| 5 | `uint32 count`, then `uint32 length` + text per entry | vector at `+0x2918fc/+0x291900/+0x291904` | variable | Dynamic wide-string vector. Current consumers suggest blocked/listen-name style state, but final field name is open. |
| 6 | `uint32 present`, then 20 pairs of wide chars | `+0x28f29c + i * 4` | 20 | Compact shortcut records: code point plus mode char. Writer emits mode `S` when byte `+2` is nonzero, else `I`. |
| 7 | `uint32 count`, then [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) serialized rows | state view at `+0x28f2f0 + i * 0x108`; internal row base at `+0x28f2ec + i * 0x108` | writer uses 30 | Integrated macro/hotkey records. Type code `T` maps to state `1` text macro, `S` maps to state `2` spell-tab binding, and `I` maps to state `3` inventory/item-tab binding; text/key payload is a fixed wide string with max `0x7f` stored chars. |
| 8 | `uint32 count`, then two wide-char booleans per pair | `+0x2911dc + i * 2` | writer uses 2 | Each flag char is `1` or `0`; loader stores two bytes per pair. |

The loader treats sections 5 through 8 as progressive optional tails: it proceeds only if the next `uint32` can be read. This supports older shorter files.

Serialization caveat resolved to a corrupt-state hazard: the writer emits no type character when a [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) state is outside `1..3`, while the loader always consumes one type character per row. IDA MCP decompilation of `RegistryConfig::InitializeUserDataDefaults` shows all 30 rows default to state `2`; `LoadUserProfileData` calls that default pass before reading the file, so an unknown type character leaves the safe default state in place; macro edit controls observed so far write only states `1`, `2`, or `3`. Therefore `type == 0` is not expected in normal profile state, but final source should still guard against corrupted runtime state if the writer is cleaned up.

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

`RefreshSelectedProfileData` uses the selected profile/name at `g_pConfig + 0x2912b8`.

Observed sidecar behavior:

- It checks `bmp`, `pcx`, `jpg`, `jpeg`, and `pnm` files in `Documents\NexusTK\users`.
- If any sidecar image exists, it launches `FaceRipper.exe <path>` and waits up to `10000` ms.
- It then looks for `<profile>.jpf` in `Documents\NexusTK\users`, with `./users/<profile>.jpf` as a fallback.
- Missing or invalid `.jpf` data sends profile refresh packet opcode `79` with length `0` plus the profile name.
- Present `.jpf` data must be smaller than `0x2710` bytes.
- The `.jpf` payload is decoded through [UID:000175][0x004d05f0-0x004d0c58.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c58.ImageDecodeWrappers.md); only a decoded span of `48 x 56` causes the profile name to be appended to the outbound packet.

## IDA MCP Evidence

- `lookup_funcs` confirms `0x004f9280` size `0x322`, `0x004f95b0` size `0x778`, `0x0050aba0` size `0x4d8`, and `0x005063e0` size `0x582`.
- `callers` confirms `ImportLegacyUserProfileData` is called only from `LoadUserProfileData`.
- `callers` confirms `LoadUserProfileData` is called from `0x004f7d10` at `0x004f8a83`.
- `callers` confirms `SaveUserSettings_50ABA0` is shared by seven current UI/settings paths: `0x005047f0`, `0x0053ddb0`, `0x0053ecf0`, `0x0053f0a0`, `0x0053f830`, `0x00541fa0`, and `0x005424b0`.
- `callers` confirms `RefreshSelectedProfileData` is called from `MapPane::HandlePacket` at `0x005089e3` and from profile dialog flow at `0x0053fe65`; IDA also models `0x0053fe90` as a two-instruction ProfileDialog-neighborhood tail-jump wrapper into the same helper.
- `decompile 0x0048ebc0` confirms the macro/hotkey defaults: 30 rows at `+0x28f2ec/+0x28f2f0`, state `2`, slot ordinals `0..29`, and default key text `a..z, A..D`.
- `decompile 0x004b83d0`, `0x00580320`, `0x005805e0`, and `0x005a3ae0` confirms the same row contract is edited by `IntegrateMacroEditControlPane` and consumed by `LivingObjectPane::ExecuteHotkeyAction`; `GeneralPurposePanel` child index `2` is inventory, child index `3` is spell inventory, and `OnKeyEvent` maps those tabs to states `3`/`I` and `2`/`S` respectively.

## Cross-References

- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)
- [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md)
- [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md)
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md)
- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
