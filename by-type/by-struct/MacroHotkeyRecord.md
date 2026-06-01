*** UID:0001V1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MacroHotkeyRecord

## Status

- Confidence: strong for layout, state values, loader/writer behavior, UI edit behavior, and hotkey dispatch consumers; medium for final source-facing type name and generated dispatch-helper names.
- Owner class: [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- Owner modules: [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) for defaults, [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) for file load/save, and [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) for UI editing.
- Storage: inside [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md), row base `g_pConfig + 0x28f2ec + index * 0x108`.
- Evidence basis: IDA MCP decompile/caller checks on 2026-05-25 and 2026-05-31 for `0x0048ebc0`, `0x004f95b0`, `0x0050aba0`, `0x00541b30`, `0x005421f0`, `0x0057ff60`, `0x00580320`, `0x005805e0`, and `0x005a3ae0`. `simroot_v2` is only a lead source for names/grouping, not authority.

## Layout

This is the 30-row integrated macro/hotkey table. The row has a small ordinal prefix used by the macro UI, followed by the serialized action state and text/key payload.

Offsets are relative to `g_pConfig + 0x28f2ec + index * 0x108`:

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `uint16` | Stored slot ordinal/index; defaults to `index`. |
| `+0x02` | `uint16` | Padding/reserved in current evidence. |
| `+0x04` | `uint32` | Action state serialized in `.usr` as `T`, `S`, or `I`. |
| `+0x08` | `wchar_t[0x80]` | Text macro payload or one-character action key plus null terminator. |

The profile serializer commonly addresses the row from the action-state field at `g_pConfig + 0x28f2f0 + index * 0x108`; that view uses `state` at `+0x00` and payload text at `+0x04`.

## State Values

| State | `.usr` char | Observed behavior |
| --- | --- | --- |
| `1` | `T` | Text macro. `IntegrateMacroEditControlPane` enables embedded text editing and `LivingObjectPane::ExecuteHotkeyAction` sends opcode `14` with converted text. |
| `2` | `S` | Spell-tab-bound action. `IntegrateMacroEditControlPane::OnKeyEvent` writes this state when the active `GeneralPurposePanel` child index is `3` (spell inventory tab), then `LivingObjectPane::ExecuteHotkeyAction` dispatches the stored alphabetic slot through `0x005a4530` / current `UseCommandSlot` naming. |
| `3` | `I` | Inventory/item-tab-bound action. `IntegrateMacroEditControlPane::OnKeyEvent` writes this state when the active `GeneralPurposePanel` child index is `2` (inventory tab), then `LivingObjectPane::ExecuteHotkeyAction` dispatches the stored alphabetic slot through `0x005a3e30` / current `UseSpellSlot` naming. |

The `S`/`I` labels are resolved from the source tab rather than the current generated dispatch names. IDA decompilation of `GeneralPurposePanel::GeneralPurposePanel` shows child index `2` is `inventoryPane` and child index `3` is `spellInventoryPane`; IDA decompilation of `0x00580320` writes state `2` only when active index is `3`, otherwise state `3` for active index `2`. The generated names around `0x005a3e30` and `0x005a4530` should still be treated as provisional during final source naming because the item/spell dispatch helpers are tightly coupled and current names may be misleading.

## Default And File Behavior

- `RegistryConfig::InitializeUserDataDefaults` seeds all 30 rows with ordinal `index`, state `2`, and default key text `a..z, A..D`.
- `LoadUserProfileData` calls those defaults before reading `.usr` data. If a file contains an unknown row type character, the switch does not write a new state, so the default state `2` remains.
- `SaveUserSettings_50ABA0` writes 30 rows and maps states `1`, `2`, and `3` to `T`, `S`, and `I`. A state outside `1..3` would produce a malformed row because no type character is written, but no current default/load/UI path is known to create such a state.
- `IntegrateMacroDialog` binds ten rows per page across three pages. `IntegrateMacroEditControlPane::OnKeyEvent` writes state `1` for semicolon/text-entry mode and writes state `2` or `3` based on the active source tab when an alphabetic key is selected.

## 2026-05-31 IDA Recheck

- `sub_48EBC0` starts by resetting the user-profile slice and then initializes exactly 30 macro rows. The loop starts its state pointer at `this + 0x28f2f0`, advances by `66` dwords (`0x108` bytes), writes the slot ordinal at row `+0x00`, writes default state `2` at row `+0x04`, and stores a one-character wide key plus terminator at row `+0x08`.
- `sub_4F95B0` calls `sub_48EBC0` before overlaying `.usr` data. Its macro loop reads a count, uses a state pointer at `g_pConfig + 0x28f2f0`, maps wide chars `I`, `S`, and `T` to states `3`, `2`, and `1`, reads the payload into `state + 4` / row `+0x08`, and advances by `66` dwords per row. Unknown type chars leave the previous default state in place.
- `sub_50ABA0` writes exactly 30 rows. Its switch maps state `1` to `T`, state `2` to `S`, and state `3` to `I`, then writes the payload from `g_pConfig + 0x28f2f4 + index * 0x108`.
- `sub_5421F0` refreshes ten edit controls per page and passes row base `g_pConfig + 0x28f2ec + row * 0x108` into `sub_57FF60`; `sub_57FF60` stores that row pointer and displays row `+0x08` text when state `1` is active.
- `sub_580320` writes row `+0x08` and row `+0x0a` for a single selected key, then stores state `2` for active `GeneralPurposePanel` child index `3` or state `3` for child index `2`. The semicolon/text-entry path stores state `1`.
- `sub_5805E0` syncs the text edit into row `+0x08` when the row state is `1`.
- `sub_5A3AE0` dispatches runtime hotkeys from the same table: state `1` sends a converted text macro packet, state `2` calls `sub_5A4530`, and state `3` calls `sub_5A3E30`. Those dispatch helper names remain below final confidence.

## Cross-References

- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:00006L][IntegrateMacroDialog](by-class/IntegrateMacroDialog.md)
- [UID:00006M][IntegrateMacroEditControlPane](by-class/IntegrateMacroEditControlPane.md)
- [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md)

## Changes

- Completion/confidence metadata: existed before as `0/0`; changed to `82/88`. Summary: the row layout, defaulting, `.usr` load/save mapping, macro dialog editing, and runtime dispatch consumers are now documented with direct IDA MCP evidence. Evidence: `sub_48EBC0`, `sub_4F95B0`, `sub_50ABA0`, `sub_5421F0`, `sub_57FF60`, `sub_580320`, `sub_5805E0`, and `sub_5A3AE0`.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: the table is NexusTK-owned profile/runtime source data that must be represented in a rebuilt client. Evidence: IDA-confirmed storage in `RegistryConfig`, direct file serialization in profile storage, UI editing, and runtime hotkey dispatch. Parent UID and C++ reconstruction remain blank because final source placement, helper names, and surrounding profile structure are not at the `95+` final-source gate.
