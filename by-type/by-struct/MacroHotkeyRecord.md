*** UID:0001V1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0001VR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MacroHotkeyRecord
{
    enum State {
        Text = 1,
        Spell = 2,
        Item = 3
    };

    unsigned short ordinal;
    State state;
    wchar_t text[0x80];
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MacroHotkeyRecord

## UID0000MS Persistence-State Synchronization - 2026-08-25

Each `MacroHotkeyRecord` remains exactly `0x108` / 264 bytes inside `Config::m_macroHotkeys[30]`: the row prefix/ordinal begins at `+0`, the serialized action state is the dword at `+4`, and `wchar_t text[0x80]` begins at `+8`. Profile persistence does not change this layout or ownership.

The writer maps state `1` to `L'T'`, state `2` to `L'S'`, and state `3` to `L'I'`. For any other state it emits no type character but still writes the `uint16` text length and UTF-16 payload; this malformed-stream behavior is intentional and must not be replaced with a default character. The loader maps only `T/S/I` back to `1/2/3`; an unknown character leaves the default state. A file-provided text length below `0x80` is read and NUL-terminated. A length `>=0x80` leaves the payload unread, desynchronizing the following stream exactly as the executable does.

Legacy compact-shortcut migration writes `macro.state = (shortcut.isSpellMode != 1) + 2`. Exact mode byte one maps to state two; zero or any other byte maps to state three. A generic truthiness conversion would not preserve that behavior.

## Status

- Confidence: strong for layout, state values, loader/writer behavior, UI edit behavior, and hotkey dispatch consumers; medium for final source-facing type name and generated dispatch-helper names.
- Owner class: [UID:0000BW][RegistryConfig](by-class/RegistryConfig.md)
- Direct layout parent: [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- Owner modules: [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) for defaults, [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) for file load/save, and [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) for UI editing.
- Storage: inside [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md), row base `g_pConfig + 0x28f2ec + index * 0x108`.
- Evidence basis: IDA MCP decompile/caller checks on 2026-05-25, 2026-05-31, and a focused 2026-06-11 recheck for `0x0048ebc0`, `0x004f95b0`, `0x0050aba0`, `0x00541b30`, `0x005421f0`, `0x0057ff60`, `0x00580320`, `0x005805e0`, and `0x005a3ae0`. `simroot_v2` is only a lead source for names/grouping, not authority.

## Layout

This is the 30-row integrated macro/hotkey table. The row has a small ordinal prefix used by the macro UI, followed by the serialized action state and text/key payload.

Offsets are relative to `g_pConfig + 0x28f2ec + index * 0x108`:

| Offset | Type | Meaning |
| --- | --- | --- |
| `+0x00` | `uint16` | Stored slot ordinal/index; defaults to `index`. |
| `+0x02..+0x03` | compiler-natural alignment | No authored source member; x86/MSVC aligns the four-byte `State` at `+0x04`. |
| `+0x04` | `uint32` | Action state serialized in `.usr` as `T`, `S`, or `I`. |
| `+0x08` | `wchar_t[0x80]` | Text macro payload or one-character action key plus null terminator. |

The profile serializer commonly addresses the row from the action-state field at `g_pConfig + 0x28f2f0 + index * 0x108`; that view uses `state` at `+0x00` and payload text at `+0x04`.

The 2026-06-11 decompilation recheck reconfirmed the row base as decimal `2683628` / `0x28f2ec` (Verified with int_convert.py), the state field as decimal `2683632` / `0x28f2f0` (Verified with int_convert.py), the payload field as decimal `2683636` / `0x28f2f4` (Verified with int_convert.py), and the row stride as decimal `264` / `0x108` (Verified with int_convert.py). `RegistryConfig::InitializeUserDataDefaults` advances by `66` dwords / `0x42` dwords (Verified with int_convert.py), matching one `0x108`-byte row.

## State Values

| State | `.usr` char | Observed behavior |
| --- | --- | --- |
| `1` | `T` | Text macro. `IntegrateMacroEditControlPane` enables embedded text editing and `UserPane::ExecuteHotkeyAction` sends opcode `14` with converted text. |
| `2` | `S` | Spell-tab-bound action. `IntegrateMacroEditControlPane::OnKeyEvent` writes this state when the active `GeneralPurposePanel` child index is `3` (spell inventory tab), then `UserPane::ExecuteHotkeyAction` dispatches the stored alphabetic slot through `0x005a4530` / `UserPane::UseCommandSlot`. |
| `3` | `I` | Inventory/item-tab-bound action. `IntegrateMacroEditControlPane::OnKeyEvent` writes this state when the active `GeneralPurposePanel` child index is `2` (inventory tab), then `UserPane::ExecuteHotkeyAction` dispatches the stored alphabetic slot through `0x005a3e30` / `UserPane::UseInventorySlot`. |

The `S`/`I` labels are resolved from the source tab rather than from stale generated names. IDA decompilation of `GeneralPurposePanel::GeneralPurposePanel` shows child index `2` is `inventoryPane` and child index `3` is `spellInventoryPane`; IDA decompilation of `0x00580320` writes state `2` only when active index is `3`, otherwise state `3` for active index `2`. Cross-consumer evidence resolves `0x005a4530` as `UserPane::UseCommandSlot` and `0x005a3e30` as `UserPane::UseInventorySlot`. Historical `LivingObjectPane` ownership and `UseSpellSlot` naming are superseded.

## Default And File Behavior

- `RegistryConfig::InitializeUserDataDefaults` seeds all 30 rows with ordinal `index`, state `2`, and default key text `a..z, A..D`.
- `LoadUserProfileData` calls those defaults before reading `.usr` data. If a file contains an unknown row type character, the switch does not write a new state, so the default state `2` remains.
- [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) writes literal count `30`, then maps states `1`, `2`, and `3` to `T`, `S`, and `I`. For a state outside `1..3`, it emits no type wchar but still emits the uint16 `wcslen(text)` and byte-size `text` payload, preserving a malformed-stream hazard. No current default/load/UI path is known to create such a state, but source must not invent a default type.
- The declared payload member is exactly source-facing `text`. Historical loader expressions using `.payload` are superseded and have been synchronized to this declaration; row text remains at `+0x08`, or `+0x04` when addressed from the state-field view.
- `IntegrateMacroDialog` binds ten rows per page across three pages. `IntegrateMacroEditControlPane::OnKeyEvent` writes state `1` for semicolon/text-entry mode and writes state `2` or `3` based on the active source tab when an alphabetic key is selected.
- [UID:00045D][0x00541b30-0x00541e29.IntegrateMacroDialogConstructor](by-memory/0x00541b30-0x00541e29.IntegrateMacroDialogConstructor.md) performs the first-page binding during dialog construction: it creates ten `IntegrateMacroEditControlPane` controls and passes row bases for `g_pConfig->m_macroHotkeys[0..9]` (`g_pConfig + 0x28f2ec + row * 0x108`). [UID:00045L][0x005421f0-0x00542265.IntegrateMacroDialogRefreshMacroEditFields](by-memory/0x005421f0-0x00542265.IntegrateMacroDialogRefreshMacroEditFields.md) later rebinds the same visible row controls to `(currentPage * 10 + row)` for page changes.

## 2026-05-31 IDA Recheck

- `sub_48EBC0` starts by resetting the user-profile slice and then initializes exactly 30 macro rows. The loop starts its state pointer at `this + 0x28f2f0`, advances by `66` dwords (`0x108` bytes), writes the slot ordinal at row `+0x00`, writes default state `2` at row `+0x04`, and stores a one-character wide key plus terminator at row `+0x08`.
- `sub_4F95B0` calls `sub_48EBC0` before overlaying `.usr` data. Its macro loop reads a count, uses a state pointer at `g_pConfig + 0x28f2f0`, maps wide chars `I`, `S`, and `T` to states `3`, `2`, and `1`, reads the payload into `state + 4` / row `+0x08`, and advances by `66` dwords per row. Unknown type chars leave the previous default state in place.
- `sub_50ABA0` writes exactly 30 rows. Its switch maps state `1` to `T`, state `2` to `S`, and state `3` to `I`, then writes the payload from `g_pConfig + 0x28f2f4 + index * 0x108`.
- `sub_5421F0` refreshes ten edit controls per page and passes row base `g_pConfig + 0x28f2ec + row * 0x108` into `sub_57FF60`; `sub_57FF60` stores that row pointer and displays row `+0x08` text when state `1` is active.
- `sub_580320` writes row `+0x08` and row `+0x0a` for a single selected key, then stores state `2` for active `GeneralPurposePanel` child index `3` or state `3` for child index `2`. The semicolon/text-entry path stores state `1`.
- `sub_5805E0` syncs the text edit into row `+0x08` when the row state is `1`.
- `sub_5A3AE0` dispatches runtime hotkeys from the same table: state `1` sends a converted text macro packet, state `2` calls `sub_5A4530`, and state `3` calls `sub_5A3E30`. Those dispatch helper names remain below final confidence.

## 2026-06-11 Gate Recheck

Live IDA MCP reconfirmed the method boundaries used by this page: `0x0048ebc0` size `0x30f`, `0x004f95b0` size `0x778`, `0x0050aba0` size `0x4d8`, `0x005421f0` size `0x75`, `0x0057ff60` size `0x3c`, `0x00580320` size `0x13d`, `0x005805e0` size `0x5e`, `0x005a3ae0` size `0x259`, `0x005a3e30` size `0x1c3`, and `0x005a4530` size `0x3d8`.

The focused decompilation pass confirms the row is a direct child of [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md):

- `RegistryConfig::InitializeUserDataDefaults` writes slot ordinals at row `+0x00`, default state `2` at row `+0x04`, and one wide key plus terminator at row `+0x08`; rows `0..25` default to `a..z`, while rows `26..29` default to `A..D`.
- `IntegrateMacroDialog::RefreshMacroEditFields` binds ten rows per page by passing `g_pConfig + 0x28f2ec + (page * 10 + row) * 0x108` into `IntegrateMacroEditControlPane::SetMacroData`; current IDA callers show `SetMacroData` is reached from that refresh method.
- `SetMacroData` stores the row pointer and displays row `+0x08` only when row `+0x04` is text state `1`.
- `IntegrateMacroEditControlPane::OnKeyEvent` writes semicolon/text-entry mode as state `1`; alphabetic bindings write the key at `+0x08`, terminate at `+0x0a`, and write state `2` for active panel index `3` or state `3` for active panel index `2`.
- `SyncEditControl` copies up to 64 units from the embedded editor back into row `+0x08` only when state `1` is active.
- `UserPane::ExecuteHotkeyAction` consumes the same table from the state view at `g_pConfig + 0x28f2f0 + adjustedIndex * 0x108`, sends opcode `14` for state `1`, routes state `2` through `UserPane::UseCommandSlot` at `0x005a4530`, and routes state `3` through `UserPane::UseInventorySlot` at `0x005a3e30`.

## UID0003UB Runtime Consumer Synchronization

[UID:0003UB][0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction](by-memory/0x005a3ae0-0x005a3d39.UserPaneExecuteHotkeyAction.md) is the behavior-complete runtime consumer of this table. Its sole merged key-handler caller supplies a page-relative digit and one of the page bases `0`, `10`, or `20`; the method rotates the digit within a decade and selects one of all 30 rows at `g_pConfig + 0x28f2ec + index * 0x108` without adding an independent bounds guard.

- State `Text` converts the row's wide `text` to ACP, writes packet bytes `0x0e`, subtype `0`, and a narrowed one-byte text length with the value-first PacketBuffer writers, copies exactly `textLength` bytes to `packet + 3` through `MemoryMan::MemmoveWrapper`, and asks `Socket::QueueAndSendPacket` to send exactly `textLength + 3` bytes. Helper spare zeros and the local trailing NUL are not part of the transmitted length.
- State `Spell` accepts alphabetic bindings, maps `a..z` and `A..Z` to the same zero-based value, adds one, and calls `UserPane::UseCommandSlot`. State `Item` duplicates that mapping and calls `UserPane::UseInventorySlot`. A non-ASCII code unit that passes the locale-sensitive alphabetic test but misses both ASCII ranges retains the machine's `0xff` intermediate before the one-based call.
- The inherited Config runtime storage and exact row layout are proven, but the current Config declaration does not expose a binary-layout-correct source member for this table. UID0003UB therefore retains a blank formal/no-body emitter instead of inventing a nested profile member, RegistryConfig cast, direct undeclared Config member, raw-offset accessor, or placeholder-heavy full layout. This declaration limitation does not change this type's existing score, owner, emitter, position, or formal declaration.

## Assignment And Score Rationale

Canonical owner remains [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md), the direct layout parent for the nested 30-row table. The emitted declaration routes directly to [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) at position `0` because [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) is a non-standalone layout-slice page and this exact row type is safe to declare independently.

Completion is `88` because the page records row layout, defaulting, `.usr` load/save mapping, UI binding, edit-control mutation/sync, runtime dispatch, verified offset conversions, direct parent routing, direct file emitter route, and first-draft formal struct C++. Confidence is `90` because current IDA decompilation and caller evidence corroborate the row contract across all known producer and consumer groups, and other emitted source already uses `MacroHotkeyRecord::Text`, `MacroHotkeyRecord::Spell`, and `MacroHotkeyRecord::Item`. It remains below final only because exact original type/member spellings and paired runtime dispatch-helper names are still provisional.

## Cross-References

- [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md)
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md)
- [UID:00006L][IntegrateMacroDialog](by-class/IntegrateMacroDialog.md)
- [UID:00006M][IntegrateMacroEditControlPane](by-class/IntegrateMacroEditControlPane.md)
- [UID:0001KM][0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md)

## Changes

- 2026-06-30 B007 RegistryConfig empty-emitter implementation callback:
  - Changed from `85/89` to `88/90`; canonical owner remains [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md); emitter changed from `0001VR` to [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md) with position `0`.
  - Populated formal first-draft `struct MacroHotkeyRecord` with enum states `Text = 1`, `Spell = 2`, `Item = 3`, `unsigned short ordinal`, `unsigned short reserved`, `State state`, and `wchar_t text[0x80]`.
  - The route change is intentional: [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) remains a comment-only layout slice, while this exact nested row type can safely appear in `RegistryConfig.cpp` before methods use `MacroHotkeyRecord::Spell`.
- 2026-06-28 B002 UID00045D implementation callback: no score change. Added the constructor-side row-binding proof for [UID:00045D][0x00541b30-0x00541e29.IntegrateMacroDialogConstructor](by-memory/0x00541b30-0x00541e29.IntegrateMacroDialogConstructor.md): first-page controls bind to `m_macroHotkeys[0..9]` with row stride `0x108`, while refresh handles current-page rebinding.
- Completion/confidence metadata: existed before as `0/0`; changed to `82/88`. Summary: the row layout, defaulting, `.usr` load/save mapping, macro dialog editing, and runtime dispatch consumers are now documented with direct IDA MCP evidence. Evidence: `sub_48EBC0`, `sub_4F95B0`, `sub_50ABA0`, `sub_5421F0`, `sub_57FF60`, `sub_580320`, `sub_5805E0`, and `sub_5A3AE0`.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: the table is NexusTK-owned profile/runtime source data that must be represented in a rebuilt client. Evidence: IDA-confirmed storage in `RegistryConfig`, direct file serialization in profile storage, UI editing, and runtime hotkey dispatch. Parent UID and C++ reconstruction remain blank because final source placement, helper names, and surrounding profile structure are not at the `95+` final-source gate.
- 2026-06-11 A004 Batch 146 strict-gate update:
  - Before: `82/88`, `AUTOGEN_PARENT_UID` blank.
  - After: `85/89`, `AUTOGEN_PARENT_UID:0001VR`.
  - Summary/evidence: live IDA MCP reconfirmed macro/profile function boundaries and caller paths, then decompilation tied the row base, state field, payload field, default values, UI row binding, text/key mutation, sync path, and runtime dispatch to the [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) layout. Numeric offset conversions from decimal decompiler output were verified with `int_convert.py`. B007 later superseded this blank-emitter state with the current first-draft formal struct declaration.
- 2026-07-14 B005 SaveUserSettings synchronization: score, owner/emitter, position, and formal declaration remain unchanged at `88/90`. Added exact count/type/length/text writer behavior, preserved the invalid-state type-omission hazard, and confirmed `.text` as the synchronized formal member rather than historical `.payload` spelling.
- 2026-07-15 B005 UID0003UB callback synchronization: score, owner/emitter, position, and formal declaration remain unchanged at `88/90`. Corrected the runtime owner to `UserPane`, resolved state-2/state-3 consumers as `UseCommandSlot`/`UseInventorySlot`, added the exact three-page normalization and Text/Spell/Item runtime behavior, and preserved the Config declaration blocker as the reason UID0003UB emits no source body.

## 2026-07-15 UID0003UP Natural-Alignment Callback

- The exact managed declaration removes only the explicit `reserved` word. On x86/MSVC, compiler-natural two-byte alignment before the four-byte `State` enum preserves `ordinal=+0`, `state=+4`, `text=+8`, and `sizeof(MacroHotkeyRecord)==0x108`.
- Owner UID0001VR, emitter UID0000N4, position 0, score `88/90`, state values, thirty-row behavior, default keys, profile serialization, malformed-state behavior, UI/runtime consumers, and all unrelated history remain unchanged.
- The former explicit reserved-word declaration is historical layout scaffolding, not plausible authored source. Natural alignment is the accepted current source shape; no packed pragma or handwritten padding is added.
