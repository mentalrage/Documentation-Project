*** UID:0001WZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00000B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// AlertPane vtable cluster generated from the AlertPane class declaration and inherited DialogPane views.
// Raw vtable dwords and adjustor thunks are not hand-authored source.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AlertPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:00000B][AlertPane](by-class/AlertPane.md).
- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- Exact vtable data range: [UID:0002M5][0x00618b00-0x00618ba0.AlertPaneVtableData](by-memory/0x00618b00-0x00618ba0.AlertPaneVtableData.md).
- Confidence: strong for vtable bases, constructor stores, and destructor/callback slots.
- Autogen status: attached to the `AlertPane` class page. Final C++ remains blank here because the compiler should emit these vtables from the [UID:00000B][AlertPane](by-class/AlertPane.md) class declaration.

## Vtable Bases

| Class view | Base | Constructor store | Notes |
| --- | --- | --- | --- |
| primary | `0x00618b00` | `0x0049ff1e` | Installed at object offset `+0x00` after `DialogPane` construction. |
| secondary `+0xa0` | `0x00618b68` | `0x0049ff24` | Secondary dialog/input view installed at object offset `+0xa0`. |
| tertiary `+0xa4` | `0x00618b98` | `0x0049ff2e` | Event/update-handler view installed at object offset `+0xa4`. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00618b00` | `+0x00` | `0x0048c550` | Shared `AlertPane`-family scalar deleting destructor. |
| primary `0x00618b00` | `+0x30` | `0x0049dfd0` | Dialog create/show layout virtual inherited from `DialogPane`. |
| primary `0x00618b00` | `+0x44` | `0x0049f090` | Dialog focus drawing virtual inherited from `DialogPane`. |
| primary `0x00618b00` | `+0x48` | `0x004a0580` | `AlertPane::DismissDialog`, the button-id close/dispatch path. |
| primary `0x00618b00` | `+0x50` | `0x0049f1d0` | Dialog background drawing virtual inherited from `DialogPane`. |
| primary `0x00618b00` | `+0x54` | `0x0049f2e0` | Dialog border/tile drawing virtual inherited from `DialogPane`. |
| primary `0x00618b00` | `+0x58` | `0x0049fc00` | Dialog hover-control/update virtual inherited from `DialogPane`. |
| primary `0x00618b00` | `+0x5c` | `0x0041b6a0` | Base no-op `OnPrimaryButton` extension point; `DismissDialog(int buttonId, int unused)` calls this slot for button id `1` without pushing callback arguments. |
| primary `0x00618b00` | `+0x60` | `0x0041b6a0` | Base no-op `OnSecondaryButton` extension point; `DismissDialog(int buttonId, int unused)` calls this slot for button id `2` without pushing callback arguments. |
| secondary `0x00618b68` | `+0x00` | `0x0048c315` | Adjustor thunk into the shared deleting destructor with `this - 0xa0`. |
| tertiary `0x00618b98` | `+0x00` | `0x0048c320` | Adjustor thunk into the shared deleting destructor with `this - 0xa4`. |
| tertiary `0x00618b98` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x64` as an `AlertPane` virtual: it is RTTI metadata for the secondary table. Likewise, secondary `+0x2c` and tertiary `+0x08` are RTTI metadata for the next vtable/class region. The absolute address at secondary base `+0x34` is the same dword as tertiary `+0x04` because the tertiary table follows the secondary RTTI record.

## IDA MCP Evidence

- `list_globals *AlertPane*` reports the `AlertPane` vtables at `0x00618b00`, `0x00618b68`, and `0x00618b98`, plus derived alert-family tables for `VersatileAlertPane`, `ExchangeAlertPane`, `BlueAlertPane`, and `UrlAlertPane`.
- `xrefs_to` the three `AlertPane` vtable bases reports constructor stores at `0x0049ff1e`, `0x0049ff24`, and `0x0049ff2e` inside `AlertPane::AlertPane` at `0x0049feb0`.
- `lookup_funcs` confirms `0x0049feb0` as a `0x6c5`-byte constructor, `0x004a0580` as a `0x106`-byte `DismissDialog`, `0x0048c550` as the shared scalar deleting destructor, and `0x0048c315`/`0x0048c320` as 0xb-byte adjustor thunks.
- Disassembly of `0x0049feb0` shows `DialogPane` construction followed by stores of the three vtable bases before alert layout, text measurement, control creation, modal-list insertion, and slide-in animation.
- Current Wave3 metadata reports `vtable_count: 0`, so generated vtable inventory is incomplete even though the active source names `AlertPane_vtable`, `AlertPane_vtable2`, and `AlertPane_vtable3`.

## 2026-05-31 IDA Recheck

- `lookup_funcs` reconfirms `0x0049feb0-0x004a0575` as the constructor body, `0x004a0580-0x004a0686` as the dismiss/dispatch method, `0x0048c550-0x0048c58b` as the shared scalar deleting destructor, and `0x0048c315` / `0x0048c320` as 0xb-byte adjustor thunks.
- `py_eval` dword reads reconfirm `??_7AlertPane@@6B@` at `0x00618b00`, `??_7AlertPane@@6B@_0` at `0x00618b68`, and `??_7AlertPane@@6B@_1` at `0x00618b98`.
- `xrefs_to` the three vtable bases reports constructor stores at `0x0049ff1e`, `0x0049ff24`, and `0x0049ff2e`.
- The exact vtable-data child page [UID:0002M5][0x00618b00-0x00618ba0.AlertPaneVtableData](by-memory/0x00618b00-0x00618ba0.AlertPaneVtableData.md) now records the raw `.rdata` span and the `0x00618ba0` boundary before `VersatileAlertPane` RTTI.

## Reconstruction Notes

Model `AlertPane` as a `DialogPane`-derived shared alert base with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. Keep the adjustor thunks as compiler glue evidence rather than handwritten source methods.

The primary-button and secondary-button callback slots are intentional extension points. B002's 2026-06-17 source-quality pass names the base slots `OnPrimaryButton` and `OnSecondaryButton`. The base table contains no-op entries at both slots, while derived alert classes such as [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md), [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md), [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md), [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md), and [UID:0000IH][CopyWindow](by-file/CopyWindow.md) may override one or both slots depending on their feature behavior.

## Parent Rationale

Attach this vtable cluster to [UID:00000B][AlertPane](by-class/AlertPane.md) because the three tables are the base `AlertPane` virtual views installed by `AlertPane::AlertPane` and consumed by `AlertPane::DismissDialog`. The class page is already reconstructable, attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md), and records the same vtable bases, object offsets, shared destructor, and callback slots. The vtable page remains the narrow evidence home for slot order and `.rdata` boundaries.

## Cross-References

- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:0002M5][0x00618b00-0x00618ba0.AlertPaneVtableData](by-memory/0x00618b00-0x00618ba0.AlertPaneVtableData.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable cluster was reconstructable but unassigned in generated type coverage despite the owning class and file pages already clearing the attachment gate.
  - What changed: attached the vtable cluster to [UID:00000B][AlertPane](by-class/AlertPane.md), raised completion to `86`, and added an explicit parent rationale.
  - Summary/evidence: constructor stores at `0x0049ff1e`, `0x0049ff24`, and `0x0049ff2e`, exact [UID:0002M5][0x00618b00-0x00618ba0.AlertPaneVtableData](by-memory/0x00618b00-0x00618ba0.AlertPaneVtableData.md), and the class page's `82/90` score support the parent assignment; confidence stays below final-audit level because final callback names and source-quality declarations remain open.

- 2026-06-17 B002 source-quality execution:
  - Changed from: `86/90` to `88/92`.
  - Summary/evidence: B002 live IDA recheck confirmed the three-view vtable cluster, constructor stores, exact vtable-data child range, `DismissDialog` at primary slot `+0x48`, and no-argument `OnPrimaryButton` / `OnSecondaryButton` extension slots at `+0x5c` / `+0x60`. Final C++ stays blank because these dwords should be generated from the class declaration.
- 2026-06-30 B011 empty-emitter implementation:
  - Score and metadata unchanged at `88/92`, owner/emitter [UID:00000B][AlertPane](by-class/AlertPane.md).
  - Added the formal vtable-cluster no-code marker. It preserves vtable bases `0x00618b00`, `0x00618b68`, and `0x00618b98`, constructor stores, `DismissDialog` / primary-secondary callback slot mapping, adjustor thunks, and the no raw dword policy.

- What existed before: the page had strong vtable content and prior IDA evidence, but validator metadata was still unevaluated `0/0` and reconstructability was blank.
- What it was changed to: the page is marked `RECONSTRUCTABLE:TRUE`, scored `84/90`, and linked to the exact by-memory vtable-data child range.
- Summary/evidence: 2026-05-31 IDA MCP reconfirmed constructor stores, vtable bases, key function slot ranges, adjustor thunks, and the `0x00618ba0` boundary before the following `VersatileAlertPane` RTTI.
