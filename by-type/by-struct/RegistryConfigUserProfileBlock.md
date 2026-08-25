*** UID:0001VR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RegistryConfigUserProfileBlock is a layout documentation slice inside RegistryConfig, not a confirmed standalone source struct.
// Emit exact nested row types such as MacroHotkeyRecord separately; keep this aggregate layout page comment-only.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RegistryConfigUserProfileBlock

## UID0000MS Current Profile Slice Synchronization - 2026-08-25

The current declaration authority is base [UID:000031][Config](by-class/Config.md), not a duplicate nested struct and not a broad `RegistryConfig` overlay. Profile persistence accesses these members directly through `Config`; only `InitializeUserDataDefaults()` requires a narrow runtime-derived cast.

| Offset | Current source-facing member | Count / width | Persistence role |
| --- | --- | --- | --- |
| `+0x28de9c` | `wchar_t m_profileTextSlots[10][0x80]` | 10 rows, 0x100 bytes each | Modern group 1 and legacy quoted group 1. |
| `+0x28e89c` | `wchar_t m_legacyShortcutText[10][0x80]` | 10 rows, 0x100 bytes each | Modern group 2, legacy quoted group 2, and migration source. |
| `+0x28f29c` | `CompactShortcutRecord m_compactShortcutRecords[20]` | 20 rows, 4 bytes each | Modern group 6 and migration intermediate. |
| `+0x28f2ec` | `MacroHotkeyRecord m_macroHotkeys[30]` | 30 rows, 0x108 / 264 bytes each | Modern group 7 and final migration destination. |
| `+0x2911dc` | `TargetOptionRow m_targetOptionRows[2]` | 2 rows, 2 bytes each | Modern group 8. |
| `+0x2911e0` | `mystr::StringBase<wchar_t> m_friendNames[20]` | 20 pointer-backed string objects | Modern/legacy friend-name group 3. |
| `+0x2912b8` | `wchar_t m_selectedProfileName[0x100]` | 256 UTF-16 units | Modern/legacy selected-profile group 4. |
| `+0x2918fc` | `SimpleUStringVector m_blockListenNames` | 12-byte begin/end/capacity triplet | Optional modern group 5. |

`m_friendNames` is the current accepted spelling for the exact `+0x2911e0` storage. Earlier `m_profileStringSlots` wording elsewhere on this page is historical provenance and no longer current source authority.

### Compact Shortcut Record

No standalone `CompactShortcutRecord.md` page exists; this attached Config slice is the current ordinary documentation owner for the nested record. Each row is exactly four bytes: `wchar_t code` at `+0`, byte-like `unsigned char isSpellMode` at `+2`, and compiler-natural tail alignment at `+3`. Load sets the mode from exact `L'S'` equality; save writes `S` for any nonzero mode and `I` for zero. Migration to macros must use `(isSpellMode != 1) + 2`, not a truthy ternary: exact byte one maps to macro state two, while zero and other non-one values map to state three. Runtime dispatch still treats arbitrary nonzero as command/spell mode, so the field must remain byte-like rather than narrowed to C++ `bool`.

### Macro Record And Malformed-State Contract

`MacroHotkeyRecord` remains 264 bytes: row ordinal/prefix at `+0`, state at `+4`, and `wchar_t text[0x80]` at `+8`. States `1`, `2`, and `3` serialize as `T`, `S`, and `I`. An unknown state emits no type character but still emits the length and payload. On load, an unknown type leaves the existing default state; a text length `>=0x80` leaves the payload unread and desynchronizes subsequent input. These behaviors are part of the original stream contract, not errors to normalize.

The complete eight-group order and all malformed-input semantics are synchronized with [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md), [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md), and [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md).

## Status

- Confidence: strong for offsets used by profile load/save; medium for semantic field names.
- Owner class: [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- Owner module: [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md), consumed by [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- Evidence basis: IDA MCP caller/decompile checks on 2026-05-25, 2026-05-31, 2026-06-11, and the accepted 2026-07-14 SaveUserSettings pass for `LoadUserProfileData`, `SaveUserSettings`, `ImportLegacyUserProfileData`, `RefreshSelectedProfileData`, `RegistryConfig::InitializeUserDataDefaults`, and macro dialog/hotkey consumers.
- Parent attachment: validator ownership remains attached to method-owning [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md), currently `88/90`; binary construction proves the runtime storage itself is inherited from the Config base.

## Role

This is not a confirmed standalone C++ struct name. It is a documentation name for the user-profile/settings slice in the large Config base storage of the runtime `RegistryConfig` object. `RegistryConfig::InitializeUserDataDefaults` resets this inherited slice, while `ProfileStorage.cpp` overlays it from `.usr` / legacy `.cfg` files and serializes it back to disk.

Profile storage helpers consume the slice through base-typed [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) `g_pConfig`; that makes [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) an IO consumer rather than the owner of the declaration. Startup allocates `0x291918` bytes, calls the Config constructor, and then patches the RegistryConfig vtable, so neither RegistryConfig-only storage nor an explicit derived cast is the source declaration route. The current complete placeholder-free base-Config declaration resolves the member arrangement; this page remains comment-only because it is a documentation slice, not a separate nested source aggregate.

## Adjacent Chat Display/Handle Settings Block

The chat display/handle settings immediately precede the chat-color pairs. These offsets are owned by `RegistryConfig` storage and consumed by [UID:0000I5][Chatting](by-file/Chatting.md).

| Offset | Size | Recommended role name | Evidence |
| --- | ---: | --- | --- |
| `+0x28de78` | 4 | `m_chatVisibleLineCount` / visible chat line count | Read by `InitializeMainUiGraph` before calling `ChattingModifyHeightPane::SetLineCount`; written by `ChattingModifyHeightPane::OnMouseEvent` after drag commit. |
| `+0x28de7c` | 4 | `m_chatHandleModeIndex` / chat display mode index | Loaded and persisted by `ChattingHandlePane`; cycled modulo 3 by handle hit-test index 2. |
| `+0x28de80` | 1 | `m_secondaryChatEnabled` | Loaded and persisted by `ChattingHandlePane`; controls the secondary chat widget and gates ChattingBackPane/resize-handle behavior. |
| `+0x28de81` | 1 | `m_chatHandleLeftToggle` | Loaded and persisted by `ChattingHandlePane`; toggled by handle hit-test index 0. |

Exact original field spellings remain unproven, but the roles and offsets are source-quality for first-draft `Chatting.cpp` consumers.

## Adjacent Chat Color Block

B001 source-quality report `0002EX-0002F0-chatting-source-quality-20260615` documents the immediately preceding chat-color byte block at `g_pConfig + 0x28de82..0x28de8d`. This block is owned by `RegistryConfig` storage and consumed by [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md) and [UID:0002F0][0x0047ff80-0x00480640.ChatPacketType10Handler](by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md), but it is not part of the later profile-string slice beginning at `+0x28de9c`.

| Offset pair | Role-only category | Evidence |
| --- | --- | --- |
| `+0x28de82/+0x28de83` | Talk color pair | Imported/saved by `ChattingColorPane`; not used by the type-10 handler. |
| `+0x28de84/+0x28de85` | Shout color pair | Imported/saved by `ChattingColorPane`; used by type-10 subtype `4`. |
| `+0x28de86/+0x28de87` | Whisper color pair | Imported/saved by `ChattingColorPane`; used by type-10 subtype `0`. |
| `+0x28de88/+0x28de89` | Group color pair | Imported/saved by `ChattingColorPane`; used by type-10 subtype `11`. |
| `+0x28de8a/+0x28de8b` | Clan color pair | Imported/saved by `ChattingColorPane`; used by type-10 subtype `12`. |
| `+0x28de8c/+0x28de8d` | System color pair | Imported/saved by `ChattingColorPane`; used by type-10 subtypes `5` and `17`. |

For source-facing reconstruction, use an indexed role model: `ChatColorPair m_chatColorPairs[ChatColorCategory_Count]` at `+0x28de82`, where each pair has `unsigned char foreground` followed by `unsigned char background`. Category order is `Talk`, `Shout`, `Whisper`, `Group`, `Clan`, `System`. The exact original member spelling is not proven, but `foreground/background` is stronger than `primary/secondary` because `ColorStringChattingMessage` stores the two values as foreground and background palette ids.

## Registry Load Routes For Adjacent Chat Settings

B003 2026-06-19 [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md) implementation confirms the registry load route for the adjacent chat settings:

- `RegistryConfig::LoadFromRegistry` reads `ChatWindow` as a four-byte `REG_DWORD` and decodes it into `+0x28de78` `m_chatVisibleLineCount`, `+0x28de7c` `m_chatHandleModeIndex`, `+0x28de80` `m_secondaryChatEnabled`, and `+0x28de81` `m_chatHandleLeftToggle`.
- If `ChatWindow` is missing or invalid, the binary defaults to visible line count `8`, handle mode index `1`, and both toggle bytes enabled.
- `RegistryConfig::LoadFromRegistry` reads `ChatColor` as an exact 0x0c-byte `REG_BINARY` payload into `+0x28de82..+0x28de8d`, matching `ChatColorPair m_chatColorPairs[6]`.
- The source roles above are class-owned `RegistryConfig` fields, not profile-file owned storage. ProfileStorage remains a consumer of the broader user-profile slice.

Adjacent load-side `RegistryConfig` fields outside this struct's main profile slice, if a future layout page wants to centralize them, include `+0x28de10` `m_serverEntryCount`, `+0x28de14` `m_multiServerInfoVersion`, `+0x28de30` `m_fontIndex`, `+0x28de32` `m_iconsPaneReducedMode`, `+0x28de34` `m_registryClassIdSeed`, `+0x28de38` `m_adapterPhysicalAddressDigest`, and `+0x28db10` `m_serverEntries`.

## Layout Slice

Offsets are relative to `g_pConfig` / the active `RegistryConfig` object.

| Offset | Size / stride | Observed type | Current role |
| --- | --- | --- | --- |
| `+0x28de9c` | `10 * 0x100` bytes | `wchar_t[10][0x80]` | Fixed profile wide-string slots loaded/saved as length-prefixed strings. |
| `+0x28e89c` | `10 * 0x100` bytes | `wchar_t[10][0x80]` | Direct base-Config `m_legacyShortcutText` rows. Modern load migrates nonempty first chars out of this array. Retained [UID:0003UJ][0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut](by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md) maps signed-short ordinal zero to row 9 and nonzero to value minus one, reads the first UTF-16 code unit, classifies its sign-extended low byte, returns on nonalpha, maps full-wide ASCII letters to command slots `1..52`, and uses `0xff` only for classifier-accepted full-wide non-ASCII values. |
| `+0x28f29c` | `20 * 4` bytes | `CompactShortcutRecord m_compactShortcutRecords[20]` | Each exact four-byte record stores `wchar_t code` at `+0`, `unsigned char isSpellMode` at `+2`, and compiler-natural tail alignment at `+3`; no lifecycle path treats the final byte as a source field. [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) is the runtime dispatcher: `isSpellMode != 0` routes to [UID:0003UC][0x005a4530-0x005a4908.UserPaneUseCommandSlot](by-memory/0x005a4530-0x005a4908.UserPaneUseCommandSlot.md), while zero routes to [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md). |
| `+0x28f2ec` | `30 * 0x108` bytes | [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) array | Integrated macro/hotkey records. Internal row base has slot ordinal at `+0`; serialized action state is at row `+4` / `g_pConfig + 0x28f2f0 + i * 0x108`, followed by `wchar_t[0x80]` text/key payload at row `+8`. |
| `+0x2911dc` | `2 * 2` bytes | byte flag pairs | Two pairs of boolean bytes loaded from `L'1'` / `L'0'` character pairs. |
| `+0x2911e0` | `20 * 4` bytes | `SimpleUString[20]`-style handles | Twenty small string object slots loaded/saved as `uint16 length` plus text. |
| `+0x2912b8` | `0x200` bytes | `wchar_t[0x100]` | Selected profile/name field. Exact constructor [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) reads nonempty text into the selected-profile editor; ProfileDialog action handling writes accepted text here; `RefreshSelectedProfileData` appends it to outbound opcode `79`. Sidecar filenames are instead keyed by the local-player-name helper at `0x005a2dc0`. |
| `+0x2918fc` | `0x0c` bytes | vector begin/end/capacity pointers | Block-listen wide-string vector used by social block/listen prompts; final original member spelling remains open. |

Use these as role-accurate documentation names: `m_profileTextSlots[10][0x80]` at `+0x28de9c`, `m_legacyShortcutText[10][0x80]` at `+0x28e89c`, `m_compactShortcutRecords[20]` at `+0x28f29c`, `m_macroHotkeys[30]` at `+0x28f2ec`, `m_targetOptionRows[2]` at `+0x2911dc`, `m_profileStringSlots[20]` at `+0x2911e0`, `m_selectedProfileName[0x100]` at `+0x2912b8`, and `m_blockListenNames` at `+0x2918fc/+0x291900/+0x291904`. Their behavioral roles are proved, but the names are not proven original spelling and this list is not a declaration-complete Config layout.

## Runtime Flow

- [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md) clears/defaults this slice at `0x0048ebc0`, including seeding all 30 [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) rows with state `2` and default keys `a..z, A..D`.
- [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) resets defaults, reads the `.usr` file into this slice, then promotes legacy/compact shortcut state into the [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) array.
- [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) overlays only the older prefix of this slice from quoted strings in `.\users\<user-id>.cfg`.
- [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) is the retained runtime consumer of the compact shortcut records. It maps selector `0` to record `9`, selectors `1..9` to records `0..8`, selector `10` to record `19`, and selectors `11..19` to records `10..18`; then it maps record key `a..z` to slots `1..26` and `A..Z` to slots `27..52`. This proves the compact records are runtime shortcut bindings, not just profile migration scratch.
- [UID:0003UJ][0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut](by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md) is a retained no-live-route but source-bearing UserPane runtime consumer of the legacy shortcut text rows at `+0x28e89c`. It reads only the first wide character of the selected row after unsigned wrap-aware debounce gating through zero-initialized [UID:00030B][0x0069bf74-0x0069bf78.g_lastFunctionKeyTick](by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md), applies the signed-low-byte classifier, returns for nonalpha, and distinguishes ASCII slot mapping from the accepted non-ASCII `0xff` fallback.
- [UID:0003UB][0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md) is the behavior-complete runtime consumer of all 30 integrated macro rows. Its caller supplies page bases `0`, `10`, or `20`; the method rotates the page-relative digit, then dispatches `Text`, `Spell`, or `Item` using the exact row state and payload.
- [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) writes this slice back to `Documents\NexusTK\users\<user-id>.usr`.
- [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) is the exact constructor read consumer of `m_selectedProfileName[0x100]`: it tests `wcslen(...) != 0` and inserts that text into the owned profile editor without changing the field, owner, extent, or persistence contract.
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) reads `+0x2912b8` as the selected profile name appended to packet opcode `79`; it gets sidecar filename stems from the local-player-name helper at `0x005a2dc0`.

## MacroDialogs Split Consumers

2026-06-28 B010 UID0001DR implementation confirms the older/spell/newer MacroDialogs child methods consume three direct slices here, while [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) remains the later integrated macro table:

| Storage slice | Child consumers | Role |
| --- | --- | --- |
| `m_profileTextSlots[10][0x80]` at `+0x28de9c` | [UID:00049C][0x0053e520-0x0053e8cf.MacroDialogConstructor](by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md), [UID:00049E][0x0053e8f0-0x0053e959.MacroDialogOnControlCommand](by-memory/0x0053e8f0-0x0053e959.MacroDialogOnControlCommand.md) | Older macro text rows are loaded into controls `2..11` and copied back on OK command `1`. |
| `m_legacyShortcutText[10][0x80]` at `+0x28e89c` | [UID:00049F][0x0053e960-0x0053ecd0.SpellMacroDialogConstructor](by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md), [UID:00049H][0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand](by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand.md) | Spell macro rows are seeded from legacy shortcut text; confirm writes `GetSpellKey()` and a zero terminator. |
| `m_compactShortcutRecords[20]` at `+0x28f29c` | [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md), [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md), [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) | NewMacroDialog page load/save reads and writes compact key/mode records for two ten-row pages. |
| `m_macroHotkeys[30]` at `+0x28f2ec` | [UID:00045D][0x00541b30-0x00541e29.IntegrateMacroDialogConstructor](by-memory/0x00541b30-0x00541e29.IntegrateMacroDialogConstructor.md), [UID:00045L][0x005421f0-0x00542265.IntegrateMacroDialogRefreshMacroEditFields](by-memory/0x005421f0-0x00542265.IntegrateMacroDialogRefreshMacroEditFields.md), and [UID:00006M][IntegrateMacroEditControlPane](by-class/IntegrateMacroEditControlPane.md) | IntegrateMacroDialog constructs the first page's ten edit rows against `g_pConfig->m_macroHotkeys[0..9]`; refresh later binds page-relative rows with `(currentPage * 10 + row) * 0x108`. This is the integrated macro table, distinct from NewMacroDialog's compact records. |

## Consumer Groups

| Consumer | Slice role |
| --- | --- |
| [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md) / [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md) | Owns/defaults the storage before profile overlay; establishes `RegistryConfig` class ownership. |
| [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) / [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) | Reads modern `.usr` data, imports legacy `.cfg` data, and migrates older shortcut records into the integrated macro/hotkey table. |
| [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) | Serializes the slice back to the user `.usr` file. |
| [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) | Exact read-only constructor consumer of selected-profile text at `+0x2912b8`; preloads only nonempty text into the dialog editor through guarded `InsertTextRange`. |
| [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) | Uses the selected-profile field at `+0x2912b8` as packet text for profile refresh opcode `79`; sidecar image and `.jpf` filenames use the local-player-name helper at `0x005a2dc0`. |
| [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) | Runtime consumer of compact shortcut records at `+0x28f29c`: key byte supplies the `1..52` slot value; nonzero mode dispatches to `UserPane::UseCommandSlot`; zero mode dispatches to `UserPane::UseInventorySlot`. |
| [UID:0003UJ][0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut](by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md) | Retained source-bearing UserPane consumer of direct legacy rows at `+0x28e89c`; signed-short zero/nonzero row mapping, nonalpha return, full-wide ASCII slots `1..52`, and classifier-accepted non-ASCII `0xff` before `UserPane::UseCommandSlot`. |
| [UID:0003UB][0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md) | Runtime consumer of the 30 `MacroHotkeyRecord` rows at `+0x28f2ec`: three-page index normalization; opcode `0x0e`/subtype `0` ACP Text packet; duplicated alphabetic Spell/Item mapping to one-based command/inventory slots. |
| [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) / [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md) split children [UID:00049C][0x0053e520-0x0053e8cf.MacroDialogConstructor](by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md)-[UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md) | UI consumers for older text rows, spell legacy shortcut rows, and compact shortcut record rows; they do not directly edit the integrated `m_macroHotkeys` table at `+0x28f2ec`. |
| [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) and macro/hotkey UI/runtime docs | Explain the nested 30-row macro table at `+0x28f2ec` and its edit/dispatch consumers. |
| [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) / [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md) | Proves the dynamic vector at `+0x2918fc/+0x291900/+0x291904` is the block-listen name list used for show/add/delete prompts and packet persistence. |

## 2026-06-11 Gate Recheck

Live IDA MCP still models the profile-block and macro-row evidence with the same function boundaries: `0x0048ebc0` size `0x30f`, `0x004f95b0` size `0x778`, `0x0050aba0` size `0x4d8`, `0x005421f0` size `0x75`, `0x0057ff60` size `0x3c`, `0x00580320` size `0x13d`, `0x005805e0` size `0x5e`, `0x005a3ae0` size `0x259`, `0x005a3e30` size `0x1c3`, and `0x005a4530` size `0x3d8`.

The focused decompilation recheck ties the documented offsets together:

- `RegistryConfig::InitializeUserDataDefaults` writes the fixed string groups starting at decimal `2678428` / `0x28de9c` (Verified with int_convert.py), seeds compact shortcut state at decimal `2683550` / `0x28f29e` (Verified with int_convert.py), then seeds the 30 macro rows at decimal `2683628` / `0x28f2ec` (Verified with int_convert.py).
- The same default pass uses state offset decimal `2683632` / `0x28f2f0` (Verified with int_convert.py), text/key payload offset decimal `2683636` / `0x28f2f4` (Verified with int_convert.py), row stride decimal `264` / `0x108` (Verified with int_convert.py), and advances by `66` dwords / `0x42` dwords (Verified with int_convert.py).
- The default pass also touches the trailing flag pair at decimal `2691548` / `0x2911dc` (Verified with int_convert.py), the 20 string-object handles at decimal `2691552` / `0x2911e0` (Verified with int_convert.py), the selected profile/name field at decimal `2691768` / `0x2912b8` (Verified with int_convert.py), and the dynamic vector begin/end fields at decimal `2693372` / `0x2918fc` and decimal `2693376` / `0x291900` (Verified with int_convert.py).
- `IntegrateMacroDialog::RefreshMacroEditFields` binds ten visible rows per page by computing `g_pConfig + 0x28f2ec + (page * 10 + row) * 0x108` and passing that pointer to `IntegrateMacroEditControlPane::SetMacroData`.
- `IntegrateMacroEditControlPane::SetMacroData`, `OnKeyEvent`, and `SyncEditControl` operate on the same row contract: row `+4` is the state, row `+8` is the displayed or edited text/key payload, state `1` enables text editing, and states `2`/`3` are written from the active spell/inventory panel source.
- `UserPane::ExecuteHotkeyAction` consumes the same table at `g_pConfig + 0x28f2f0 + adjustedIndex * 0x108`; state `1` sends converted text opcode `14`, state `2` dispatches through `UserPane::UseCommandSlot` at `0x005a4530`, and state `3` dispatches through `UserPane::UseInventorySlot` at `0x005a3e30`.

## 2026-06-16 Source-Quality Refresh

MCP evidence collected during session `b001_selflookpane_0001H7_20260616` reconfirmed the profile-block function boundaries and then-current source-quality blockers:

- `RegistryConfig_InitializeUserDataDefaults` at `0x0048ebc0` remains a modeled `0x30f`-byte method. Decompilation writes the ten localized fixed profile strings at `+0x28de9c`, clears ten legacy shortcut strings at `+0x28e89c`, clears selected-profile storage at `+0x2912b8`, seeds compact shortcut records at `+0x28f29c`, seeds 30 macro rows at `+0x28f2ec/+0x28f2f0`, writes the two flag pairs at `+0x2911dc`, initializes 20 string handles at `+0x2911e0`, and destroys/reset-clears the vector elements between `+0x2918fc` and `+0x291900`.
- `LoadUserProfileData` at `0x004f95b0` still calls the defaults method, appends variable-length wide strings into the `+0x2918fc` vector while loading `.usr` section 5, migrates compact shortcut records into the macro table, and leaves unknown macro type characters on the safe default state.
- `SaveUserSettings` at `0x0050aba0` serializes the vector count from `(*(this+0x291900) - *(this+0x2918fc)) >> 2`, then writes each string object from the vector span before serializing compact shortcut, macro, and flag-pair sections.
- Existing block-listen source docs and memory docs now provide the missing consumer proof for that vector: `BlockListenInputPane` show/list, add, delete, and find flows iterate or mutate `g_pConfig + 0x2918fc` through `+0x291900`, then persist settings and send block-listen packet opcodes.
- At that evidence epoch, the macro/hotkey consumer refresh supported the state labels through then-current `LivingObjectPane_ExecuteHotkeyAction` naming: state `1` sent text macro opcode `14`, state `2` used the `0x005a4530` spell-tab path, and state `3` used the `0x005a3e30` inventory/item path. The later UID0003UB source-quality pass superseded the owner as UserPane and resolved the two helpers as `UseCommandSlot` and `UseInventorySlot`.

IDA database source-quality edits made during that historical evidence pass were: `dword_67A7C8` -> `g_pConfig`, `sub_48EBC0` -> `RegistryConfig_InitializeUserDataDefaults`, `sub_4F9280` -> `ImportLegacyUserProfileData`, `sub_4F95B0` -> `LoadUserProfileData`, `sub_50ABA0` -> `SaveUserSettings`, `sub_5063E0` -> `RefreshSelectedProfileData`, `sub_5421F0` -> `IntegrateMacroDialog_RefreshMacroEditFields`, `sub_57FF60` -> `IntegrateMacroEditControlPane_SetMacroData`, `sub_580320` -> `IntegrateMacroEditControlPane_OnKeyEvent`, `sub_5805E0` -> `IntegrateMacroEditControlPane_SyncEditControl`, and `sub_5A3AE0` -> then-current `LivingObjectPane_ExecuteHotkeyAction`. The later documentation correction to UserPane ownership is authoritative; no IDA mutation is part of the UID0003UB callback.

## Exact SaveUserSettings Field Lifecycle

The accepted writer at [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) accesses this inherited runtime slice through base-typed `g_pConfig` storage and serializes every field group in this exact order. A former explicit `static_cast<RegistryConfig *>(g_pConfig)` source proposal is superseded because construction proves the storage belongs to Config and no complete Config declaration currently exposes these members:

| Order | Field / layout | Writer encoding and preserved edge |
| --- | --- | --- |
| 1 | `m_profileTextSlots[10][0x80]` at `+0x28de9c`, stride `0x100` | narrowed uint16 `wcslen`, then one `fwrite` of `2 * length` bytes; no NUL |
| 2 | `m_legacyShortcutText[10][0x80]` at `+0x28e89c`, stride `0x100` | first wchar only for each row; no count, length, or terminator |
| 3 | `m_profileStringSlots[20]` at `+0x2911e0`, stride 4 | narrowed uint16 length plus byte-size pointer-backed wide text |
| 4 | `m_selectedProfileName[0x100]` at `+0x2912b8` | uint16 length plus byte-size text, no NUL |
| 5 | `m_blockListenNames` at `+0x2918fc/+0x291900/+0x291904` | uint32 pointer-difference count; per-row uint32 length then `fwrite(text, 2, length)` |
| 6 | `m_compactShortcutRecords[20]` at `+0x28f29c`, stride 4 | literal dword `1`, code wchar, and `S` for nonzero byte `+2` or `I` for zero; byte `+3` is not serialized |
| 7 | `m_macroHotkeys[30]` at `+0x28f2ec`, stride `0x108` | dword `30`; `T/S/I` for states 1/2/3; uint16 length and byte-size `text`; invalid state omits type but still writes length/text |
| 8 | `m_targetOptionRows[2]` at `+0x2911dc`, stride 2 | dword `2`; two wchar booleans per row; only source byte exactly 1 maps to `1` |

The group-6 dword is an optional-tail presence/version marker, not the fixed 20-row count. The compact record's byte `+3` has no save/load lifecycle. The target-option byte roles are `userEnabled` and `monsterEnabled`; each is compared for equality with byte value 1 rather than generic nonzero truth. The writer ignores every write/close result and can leave a partial stream; these properties belong to ProfileStorage behavior, while this page owns the exact field lifecycle/layout.

These role-accurate names are resolved sufficiently for current human source and no longer block UID0001AV emission. Exact original private spelling remains a confidence cap; the complete base-Config declaration now resolves the arrangement, behavior, type, and layout. The formal for this page remains comment-only because it is a documentation slice inside `RegistryConfig`, not a standalone source struct; no duplicate aggregate declaration is introduced.

## Attachment And Reconstruction Notes

- `CANONICAL_OWNER` and `EMITTER_UIDS` are [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md). The parent class and this page clear the current attachment/emission gate.
- The broader [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) file page is also above the gate at `90/90`, but the class page is the more precise owner for an object-layout slice.
- `RECONSTRUCTION_CPP CODE` carries a comment-only marker. The slice is reconstructable source data, but it is not a confirmed standalone source struct; exact nested row types such as [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) emit separately. Fixed arrays, compact records, pointer-backed string slots, and the block-listen vector have role-accurate documentation names; the complete Config declaration owns their source layout, so this slice remains non-standalone to avoid duplicate declaration rather than because an interval is unresolved.

## UID0003UB Declaration Boundary And Runtime Use

[UID:0003UB][0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md) reads `g_pConfig + 0x28f2ec + index * 0x108` with no null guard. Its merged key-handler caller supplies page bases `0`, `10`, and `20`; the method rotates the relative digit within a decade, sends state-1 ACP text as opcode `0x0e`/subtype `0` with an explicit one-byte length, maps state-2 alphabetic bindings to one-based `UserPane::UseCommandSlot` calls, and maps state-3 bindings to one-based `UserPane::UseInventorySlot` calls.

The runtime storage is part of Config: startup allocates exactly `0x291918` bytes, invokes the Config constructor, and only then installs the RegistryConfig vtable. Constructor/default/save/load/UI consumers corroborate the macro row base and stride. Exhaustive declaration analysis rejects a nested `m_userProfile` route, RegistryConfig-only member, explicit derived cast, direct undeclared Config member, raw-offset/reinterpret accessor, unobserved accessor call, field-only partial layout, and a full declaration padded with generic reserved arrays. The earlier UID0003UB evidence stage still had open fixed-row, launcher-union, and high-storage blockers; B005's complete Config callback later resolved those intervals with typed source-era fields. This page remains a comment-only evidence slice and does not duplicate the now-complete Config declaration.

## Score Rationale

- Completion is `90` because the page records the owner/consumer split, parent attachment, complete profile layout slice, exact eight-section writer lifecycle, consumer groups, function-boundary evidence, verified offset conversions, nested macro-row lifecycle, block-listen vector proof, direct complete-Config arrangement, and comment-only no-duplicate declaration disposition.
- Confidence is `92` because offsets and dataflow are corroborated across defaulting, profile load/save, macro UI binding, edit-control mutation, runtime UserPane hotkey dispatch, and block-listen consumers, while the complete 0x291918 Config declaration closes the former placement blocker. Confidence remains below final only because several private member/type spellings are inferred from behavior rather than symbols.

## Open Questions

- The ten fixed wide-string slots and twenty pointer-backed string slots now use resolved role-accurate names `m_profileTextSlots`, `m_legacyShortcutText`, and `m_profileStringSlots`. Exact original spellings remain unavailable, but no caller/type/serialization ambiguity blocks current source.
- Exact source field names for the adjacent chat-color block at `+0x28de82..+0x28de8d` are still unresolved; current evidence supports only role-based category pairs.
- Final original spelling for the compact shortcut record type remains open, but the source-facing runtime contract is closed: `0x005a4530` is `UserPane::UseCommandSlot`, `0x005a3e30` is `UserPane::UseInventorySlot`, `isSpellMode != 0` routes to command/spell slots, and zero routes to inventory/item slots. The serialized labels are resolved as `S` = spell-tab binding/state `2` and `I` = inventory/item-tab binding/state `3`.
- No encompassing-declaration blocker remains. The complete placeholder-free Config declaration covers the fixed tables, launcher union, profile slice, startup/high storage, natural alignment, and exact object end; this comment-only page stays non-emitting solely to avoid a duplicate aggregate.
- The dynamic vector role is resolved as block-listen name storage by BlockListenInputPanes show/add/delete evidence. Exact original member spelling remains open, but `m_blockListenNames` is the recommended source-facing name for current reconstruction.

## Cross-References

- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md)
- [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md)
- [UID:0000IE][Config](by-file/Config.md)
- [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md)
- [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md)
- [UID:00049C][0x0053e520-0x0053e8cf.MacroDialogConstructor](by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md)
- [UID:00049E][0x0053e8f0-0x0053e959.MacroDialogOnControlCommand](by-memory/0x0053e8f0-0x0053e959.MacroDialogOnControlCommand.md)
- [UID:00049F][0x0053e960-0x0053ecd0.SpellMacroDialogConstructor](by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md)
- [UID:00049H][0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand](by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnControlCommand.md)
- [UID:00049J][0x0053ed90-0x0053f07f.NewMacroDialogConstructor](by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md)
- [UID:00049N][0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries](by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md)
- [UID:00049O][0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage](by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md)
- [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) `g_pConfig` singleton storage and class/runtime-layout access.
- [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md) Registry/config defaulting evidence for the owning class.
- [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md) Profile load and legacy import aggregate.
- [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) Save-user-settings serializer.
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) Selected-profile sidecar refresh.
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-08-01 B006 UID0004E0 support callback: preserved `90/92`, owner/emitter UID0000BW, reconstructable state, comment-only formal disposition, complete Config-owned layout, and all established default/load/save/action/refresh consumers. Added only the exact UID0004E0 constructor link at `+0x2912b8`, documenting its guarded nonempty selected-profile read without changing role, field extent, source ownership, score, metadata, or code.

- 2026-07-16 B002 UID0003UJ accepted callback:
  - Preserved `90/92`, owner/emitter, comment-only formal block, complete profile lifecycle, and all unrelated fields/consumers.
  - Corrected UID0003UJ rows to direct Config storage, signed-short row mapping, signed-low-byte classification, nonalpha return, ASCII slots `1..52`, and classifier-accepted non-ASCII `0xff`.
  - Recorded zero-initialized UID00030B debounce support and superseded the old invalid/nonalphabetic-sentinel collapse without duplicating the complete Config declaration.
- 2026-06-30 B007 RegistryConfig empty-emitter implementation callback:
  - Score/metadata unchanged. Populated formal comment-only layout-slice marker.
  - Preserved the no-standalone disposition: this page documents a profile/settings slice inside `RegistryConfig`; [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) now emits as the exact nested row type through [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md).
- 2026-06-28 B002 UID00045D implementation callback: no score change. Added the IntegrateMacroDialog constructor support sync showing that [UID:00045D][0x00541b30-0x00541e29.IntegrateMacroDialogConstructor](by-memory/0x00541b30-0x00541e29.IntegrateMacroDialogConstructor.md) consumes `m_macroHotkeys[0..9]` at `+0x28f2ec` during first-page row construction, while [UID:00045L][0x005421f0-0x00542265.IntegrateMacroDialogRefreshMacroEditFields](by-memory/0x005421f0-0x00542265.IntegrateMacroDialogRefreshMacroEditFields.md) handles page-relative rebinding later.
- 2026-06-28 B010 UID0001DR implementation callback: no score change. Added MacroDialogs split consumer links for `m_profileTextSlots`, `m_legacyShortcutText`, and `m_compactShortcutRecords`, and clarified that UID0001DR children do not directly consume the integrated `m_macroHotkeys` / `MacroHotkeyRecord` table.
- 2026-06-22 B015 [UID:0003UJ][0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut](by-memory/0x005a9250-0x005a930a.UserPaneTryDispatchFunctionKeyShortcut.md) support sync:
  - Added the retained function-key helper as a runtime consumer of the legacy `wchar_t[10][0x80]` shortcut text rows at `+0x28e89c`, including ordinal-to-row mapping and alphabetic slot mapping.
- 2026-06-22 B013 [UID:0003UA][0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey](by-memory/0x005a3a20-0x005a3ad4.UserPaneDispatchConfiguredShortcutHotkey.md) source-quality incorporation:
  - Expanded `+0x28f29c` from generic compact shortcut records to `CompactShortcutRecord m_compactShortcutRecords[20]` with runtime dispatch proof.
  - Added selector remapping, ASCII key-to-slot mapping, and mode-byte runtime routes: nonzero goes to `LivingObjectPane::UseCommandSlot`, zero goes to inventory/item slot dispatch. Score unchanged because the layout was already attached and reconstructable; this closes the compact-record consumer behavior.
- 2026-06-19 B003 [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md) implementation callback:
  - Score unchanged. Added the load-side registry route for `ChatWindow` and `ChatColor`, including default chat-window values and confirmation that the 0x0c-byte chat color block maps to `m_chatColorPairs[6]`.
- Completion/confidence metadata: existed before as `0/0`; changed to `74/82`. Summary: the major profile/settings slice offsets and row/table relationships are now IDA-backed, but final names for several fixed strings, small strings, and the dynamic vector remain open. Evidence: `sub_48EBC0` default writes, `sub_4F95B0` load/import flow, `sub_50ABA0` save flow, `sub_5063E0` selected-profile use, and the macro dialog/hotkey consumers documented in [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md).
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: this is source-owned `RegistryConfig` profile state that must be represented by fields or nested records in the rebuilt client. Evidence: IDA-confirmed reads/writes from profile storage, config defaults, UI dialogs, and runtime hotkey dispatch. Parent UID and C++ reconstruction remain blank because the whole slice is not yet at final source-placement or `95+` code-readiness confidence.
- 2026-06-06 A004 owner/consumer refresh:
  - What existed before: completion was `74`, `AUTOGEN_PARENT_UID` was blank, and the page mixed RegistryConfig ownership with ProfileStorage consumers without an explicit attachment decision.
  - Changed to: completion `82`, parent [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md), explicit owner/consumer split, consumer-group table, and final-C++ blockers.
  - Summary/evidence: existing IDA-backed docs prove RegistryConfig defaulting ownership, ProfileStorage load/save consumers, selected-profile sidecar use, macro/hotkey nested-row behavior, and `g_pConfig` access. Confidence remains `82` because final source member names and the dynamic vector role are still open.
- 2026-06-11 A004 Batch 146 parent-gate refresh:
  - Before: `82/82`.
  - After: `85/86`.
  - Summary/evidence: live IDA MCP reconfirmed profile default/load/save and macro-row consumer boundaries, then decompilation tied the profile slice offsets to `RegistryConfig::InitializeUserDataDefaults`, `IntegrateMacroDialog::RefreshMacroEditFields`, `IntegrateMacroEditControlPane` mutation/sync, and `LivingObjectPane::ExecuteHotkeyAction`. Decimal offsets from the decompilation were rechecked with `int_convert.py`, supporting the strict direct-parent gate for the nested [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md) row type while leaving final C++ blank.
- 2026-06-15 B001 source-quality execution: no score change. Added the adjacent role-only chat-color byte block at `+0x28de82..+0x28de8d` so packet/chat-color docs can refer to a stable `RegistryConfig` layout note without inventing exact original field names.
- 2026-06-16 C001 source-quality refresh:
  - Before: `85/86`.
  - After: `87/88`.
  - Summary/evidence: live IDA MCP reconfirmed default/load/save/profile/macro/hotkey boundaries and decompilation, existing block-listen file/memory docs resolved the `+0x2918fc/+0x291900/+0x291904` dynamic vector role as block-listen names, and IDA function/global names were updated for the supported config/profile/macro identities. Remaining blockers are now narrower: final source-facing names for fixed profile string groups, small string slots, chat-color bytes, and exact block-listen member spelling.
- 2026-06-17 B003 ProfileSidecarRefresh source-quality execution: no score change. Corrected the `+0x2912b8` role to selected-profile packet text for opcode `79`; sidecar filename stems are instead produced by the local-player-name helper at `0x005a2dc0`.
- 2026-06-17 B002 ChattingColorPane source-quality execution: no score change. Refined the adjacent chat-color byte block to `ChatColorPair m_chatColorPairs[ChatColorCategory_Count]` with foreground/background byte names and category order `Talk`, `Shout`, `Whisper`, `Group`, `Clan`, `System`.
- 2026-06-17 B001 ChattingModifyHeightPane source-quality execution: no score change. Added the adjacent chat display/handle settings block at `+0x28de78..+0x28de81`, including `m_chatVisibleLineCount`, `m_chatHandleModeIndex`, `m_secondaryChatEnabled`, and `m_chatHandleLeftToggle` role names.
- 2026-06-22 B013 ProfileLoadAndLegacyImport source-quality incorporation:
  - Before: `87/88`.
  - After: `88/88`.
  - Summary/evidence: B013 converted the remaining profile-storage field blockers into role-accurate source names for first-draft C++: `m_profileTextSlots`, `m_legacyShortcutText`, `m_compactShortcutRecords`, `m_macroHotkeys`, `m_targetOptionRows`, `m_profileStringSlots`, `m_selectedProfileName`, and `m_blockListenNames`. Exact original spelling remains open but no longer blocks reconstructable source emission.
- 2026-07-14 B005 SaveUserSettings synchronization: score, owner/emitter, and comment-only formal remain unchanged at `88/88`. Added the complete ordered writer lifecycle, exact widths/counts, compact byte `+3` exclusion, vector uint32 widths, target-option byte roles/equality semantics, invalid macro-state malformed-stream behavior, and explicit closure of role-name blockers while retaining lexical uncertainty.
- 2026-07-15 B005 UID0003UB callback synchronization: score, owner/emitter, position, reconstructable state, and comment-only formal remain unchanged at `88/88`. Corrected current runtime ownership/helper names to UserPane, added the complete 30-row Text/Spell/Item consumer, distinguished inherited Config storage from RegistryConfig method ownership, and recorded the exhaustive declaration-boundary rejection that requires UID0003UB's blank formal.

## 2026-07-15 UID0003UP Complete Profile-Storage Synchronization

- Current declaration authority is the complete base-`Config` x86/MSVC layout of size `0x291918`. It declares the typed 100-row character/server macro table and count, launcher protocol union, ANSI `m_loginServerAddress`, semantic option bytes, profile/high storage, `m_serverEndpointText`, MIDI list, startup state, log text, block-list vector, `m_musicFolderPath`, and minimap tail.
- Exact current offsets include `m_mapMovementStatusOption=+0x28de75`, `m_profileTextSlots=+0x28de9c`, `m_macroHotkeys=+0x28f2ec`, `m_serverEndpointText=+0x291230`, `m_midiTrackPaths=+0x2912b4`, `m_logDataText=+0x2916cc`, and `m_musicFolderPath=+0x29190c`.
- Any earlier present-tense claim on this page that the final Config layout remained unresolved, required a RegistryConfig cast, used opaque/reserved/numeric/schematic storage, or placed the MP3/music directory at `+0x291230` is now explicitly historical and superseded.
- At the B005 UID0003UP callback stage, the profile block remained a documentation/type view at `88/88`; that is historical callback provenance. The current page remains the same comment-only view and retains its owner/emitter, serialization evidence, malformed macro-state behavior, UI consumers, and source-name confidence limits, while the direct compact-record closure raises current metadata to `90/92`.
- The accepted declaration closes the former final-layout blocker: ten fixed wchar rows, ten legacy first-wchar values, twenty pointer-backed strings, selected-profile text, block-list vector, twenty compact shortcut/code-mode pairs, thirty naturally aligned MacroHotkeyRecords, startup/high fields, and tail flags all have typed source-era storage.
- ProfileStorage owns the free eight-section writer; RegistryConfig defaults/persists inherited storage. Neither relationship moves declaration ownership out of Config.

## 2026-07-15 UID0003UA Compact Record And Runtime Synchronization

- The current complete base-Config declaration supplies direct `CompactShortcutRecord m_compactShortcutRecords[20]` storage at `+0x28f29c`. This layout slice remains attached to UID0000BW and comment-only; it documents inherited runtime storage but does not emit a second struct or move declaration ownership out of Config.
- Each row is exactly 0x4 bytes: two-byte `wchar_t code`, one-byte `unsigned char isSpellMode`, and one byte of compiler-natural tail alignment. Defaults, modern load, legacy migration, save, dialog edit/load, and runtime dispatch all agree on the first two fields and never independently touch the tail byte.
- UID0003UA maps selectors `0` and `10` to rows `9` and `19`, maps other supported selectors to `selector-1`, passes the sign-extended low byte of `code` to `_isalpha`, then uses full-wchar lowercase and uppercase ranges to produce slots `1..52`; an accepted-but-out-of-range alphabetic value preserves the `0xff` fallback. Non-alphabetic values return.
- `isSpellMode` is not narrowed to `bool`: runtime tests arbitrary byte zero/nonzero, persistence writes an exact byte, and setcc/UI writers remain byte-shaped. Nonzero routes to UserPane command/spell slots; zero routes to UserPane inventory/item slots. Historical LivingObjectPane helper ownership is superseded.
- Direct base-typed `g_pConfig` access, complete Config construction before RegistryConfig vtable promotion, and the absence of any nested-profile boundary reject `m_userProfile`, RegistryConfig-only storage, a derived cast, raw offset access, duplicate aggregate, packed overlay, explicit tail field, and unresolved declaration blocker.
- Current `90/92` reflects complete role/offset/lifecycle/source-placement closure with only private lexical spellings capped. The exact comment-only managed block is intentionally unchanged.
