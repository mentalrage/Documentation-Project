*** UID:0001VR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RegistryConfigUserProfileBlock

## Status

- Confidence: strong for offsets used by profile load/save; medium for semantic field names.
- Owner class: [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- Owner module: [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md), consumed by [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- Evidence basis: IDA MCP caller/decompile checks on 2026-05-25 and 2026-05-31 for `LoadUserProfileData`, `SaveUserSettings_50ABA0`, `ImportLegacyUserProfileData`, `RefreshSelectedProfileData`, `RegistryConfig::InitializeUserDataDefaults`, and macro dialog/hotkey consumers.

## Role

This is not a confirmed standalone C++ struct name. It is a documentation name for the user-profile/settings slice inside the large `RegistryConfig` object. `RegistryConfig::InitializeUserDataDefaults` resets this slice, while `ProfileStorage.cpp` overlays it from `.usr` / legacy `.cfg` files and serializes it back to disk.

## Layout Slice

Offsets are relative to `g_pConfig` / the active `RegistryConfig` object.

| Offset | Size / stride | Observed type | Current role |
| --- | --- | --- | --- |
| `+0x28de9c` | `10 * 0x100` bytes | `wchar_t[10][0x80]` | Fixed profile wide-string slots loaded/saved as length-prefixed strings. |
| `+0x28e89c` | `10 * 0x100` bytes | `wchar_t[10][0x80]` | Legacy single-character shortcut/input slots. Modern load migrates nonempty first chars out of this array. |
| `+0x28f29c` | `20 * 4` bytes | compact shortcut records | Each record stores a UTF-16 code point at `+0`, a mode flag byte at `+2`, and one byte of padding/unknown. |
| `+0x28f2ec` | `30 * 0x108` bytes | [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) array | Integrated macro/hotkey records. Internal row base has slot ordinal at `+0`; serialized action state is at row `+4` / `g_pConfig + 0x28f2f0 + i * 0x108`, followed by `wchar_t[0x80]` text/key payload at row `+8`. |
| `+0x2911dc` | `2 * 2` bytes | byte flag pairs | Two pairs of boolean bytes loaded from `L'1'` / `L'0'` character pairs. |
| `+0x2911e0` | `20 * 4` bytes | `SimpleUString[20]`-style handles | Twenty small string object slots loaded/saved as `uint16 length` plus text. |
| `+0x2912b8` | `0x200` bytes | `wchar_t[0x100]` | Selected profile/name field. Also used by `RefreshSelectedProfileData` to form `<profile>.jpf` and packet opcode `79`. |
| `+0x2918fc` | `0x0c` bytes | vector begin/end/capacity pointers | Dynamic wide-string vector. Current callers suggest blocked/listen-name list storage, but final field name remains open. |

## Runtime Flow

- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md) clears/defaults this slice at `0x0048ebc0`, including seeding all 30 [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows with state `2` and default keys `a..z, A..D`.
- [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) resets defaults, reads the `.usr` file into this slice, then promotes legacy/compact shortcut state into the [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) array.
- [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) overlays only the older prefix of this slice from quoted strings in `.\users\<user-id>.cfg`.
- [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) writes this slice back to `Documents\NexusTK\users\<user-id>.usr`.
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) reads `+0x2912b8` as the selected profile name and sends packet opcode `79` with optional `.jpf` payload.

## Open Questions

- Final field names for the ten fixed wide-string slots, twenty small string slots, and dynamic vector need caller-by-caller naming before this becomes a source header.
- Final source names for the [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) dispatch helpers at `0x005a4530` and `0x005a3e30` should be reviewed during `LivingObjectPane` cleanup. The serialized labels are now resolved as `S` = spell-tab binding/state `2` and `I` = inventory/item-tab binding/state `3`.
- Confirm whether the dynamic vector at `+0x2918fc` should be named as block-listen storage, friend history, or a broader user-name list after all consumers are reviewed.

## Cross-References

- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000IE][Config](by-file/Config.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- Completion/confidence metadata: existed before as `0/0`; changed to `74/82`. Summary: the major profile/settings slice offsets and row/table relationships are now IDA-backed, but final names for several fixed strings, small strings, and the dynamic vector remain open. Evidence: `sub_48EBC0` default writes, `sub_4F95B0` load/import flow, `sub_50ABA0` save flow, `sub_5063E0` selected-profile use, and the macro dialog/hotkey consumers documented in [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md).
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: this is source-owned `RegistryConfig` profile state that must be represented by fields or nested records in the rebuilt client. Evidence: IDA-confirmed reads/writes from profile storage, config defaults, UI dialogs, and runtime hotkey dispatch. Parent UID and C++ reconstruction remain blank because the whole slice is not yet at final source-placement or `95+` code-readiness confidence.
