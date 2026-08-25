*** UID:0003HM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SelfSaveInputPaneVtables is the source-local index for UID0002N8.
// Regenerate the tables through SelfSaveInputPane; do not duplicate fixed
// vtable, RTTI, scalar-destructor, or adjustor-thunk bytes here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SelfSaveInputPane Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `SelfSaveInputPane` primary, secondary, and tertiary vtable views.
- Direct owner: [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md).
- Source context: [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md), with [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) still a grouping candidate.
- Exact data page: [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md).
- Split from: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md), which remains a broad non-emitting mixed-owner index.
- Related method island: [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md). B007's 2026-06-19 helper recheck corrected the retained raw send helper to [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md), but no vtable slot changes. B005's 2026-06-21 constructor pass makes [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) source-ready; the constructor vptr stores remain compiler output from the class declaration.

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- | --- |
| `SelfSaveInputPane` | [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) | `0x006305c0` | `0x00630610` | `0x00630640` | Factory/raw-constructor stores at `0x005aa196` and `0x005b67df`; confirmation slot remains documented in the exact data page. |

## Boundary Evidence

- Exact span is `0x006305c0-0x00630648`, or `0x88` / 136 bytes (Verified with int_convert.py).
- 2026-06-12 live IDA MCP `entity_query` lists the three decorated `SelfSaveInputPane` table names at the listed bases.
- 2026-06-12 `get_bytes` reads shared input-pane slot bytes at `0x006305c0`.
- 2026-06-12 `get_bytes` at `0x00630648` reads the next `BlockListenInputPane` RTTI/slot bytes, confirming this page ends before the social block-list prompt group.
- B007 2026-06-19 route scanning used the active handler as a positive control: the vtable pointer to `0x005b6800` was found at `0x00630608`, while no rel32 or pointer route was found for the retained helper [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md). The vtable family therefore continues to document the active confirmation handler route, not the retained helper.
- B005 2026-06-21 constructor scanning found no branch/pointer route to raw constructor start `0x005b67c0`, but the paired factory and constructor stores still prove the same three table bases. This preserves the raw-start confidence caveat while allowing constructor C++ to omit vptr stores and rely on the class declaration.

## 2026-07-13 B002 Complete View And Source-Disposition Recheck

The exact [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) target is `0x88` / 136 bytes with SHA256 `8D10C1E386E81C36935A768719766D9F351FFA2CA8DC7834200E475975D318D4`. Evidence was collected through supervisor-designated IDB `supervisor_nexustk_20260713`; its fresh `idb_list` and `server_health ok` result are evidence-time observations only.

The target contains exactly three vtable views and two internal complete-object-locator cells:

| View/cell | Exact range/address | Object offset | Complete target inventory |
| --- | --- | --- | --- |
| primary `??_7SelfSaveInputPane@@6B@` | `0x006305c0-0x0063060c` | `+0x00` | 19 targets: `0x005b7940`, `0x004f4b10`, `0x0041b6c0`, `0x004f2320`, `0x0041d680`, `0x00544730`, `0x00544750`, `0x005447a0`, `0x00544800`, `0x00544a20`, `0x00544b80`, `0x00544bd0`, `0x004f2430`, `0x00544cb0`, `0x004f24c0`, `0x00544d30`, `0x00544d70`, `0x004f2790`, `0x005b6800` |
| secondary COL | `0x0063060c -> 0x00653880` | `+0xa0` | RTTI locator, not padding |
| secondary `??_7SelfSaveInputPane@@6B@_0` | `0x00630610-0x0063063c` | `+0xa0` | 11 targets: `0x005b77c8`, `0x004f24f0`, `0x004f2920`, `0x004f2580`, `0x004f2760`, `0x00544df0`, `0x00544e00`, `0x004a89f0`, `0x00544e10`, `0x00544e30`, `0x00544e70` |
| tertiary COL | `0x0063063c -> 0x00653894` | `+0xa4` | RTTI locator, not padding |
| tertiary `??_7SelfSaveInputPane@@6B@_1` | `0x00630640-0x00630648` | `+0xa4` | adjustor `0x005b77d3`, inherited/default timer callback `0x00544e90` |

The primary slot roles are the shared scalar deleting wrapper, inherited LObject/LineInputPane/Pane interface through offset `+0x44`, and class-specific active confirmation method `0x00630608 -> 0x005b6800` at `+0x48`. The secondary view is the EventHandler interface: destructor adjustor, pointer/mouse, key/text, IME/active-child, packet/text-edit, two default event paths, forward-order, two event-pair outputs, and event-accept predicate. The tertiary view is TimerHandler. Exact per-slot roles and modeled sizes remain on UID0002N8 and are not replaced by raw function labels here.

The primary COL at `0x006305bc -> 0x0065381c` is outside the exact child, after the WearInputPane tertiary table at `0x006305b4`. The successor `0x00630648 -> 0x006538a8` is the BlockListen COL, followed by its table at `0x0063064c`. No target byte is padding or a source-authored constant.

All COLs share SelfSave type descriptor `0x0067a240` and CHD `0x00653830`; their offsets are `0`, `0xa0`, and `0xa4`. The eight-base RTTI order proves `SelfSaveInputPane -> CharInputPane -> LineInputPane -> Pane`, the GrafPort/LObject primary chain, EventHandler at `+0xa0`, and TimerHandler at `+0xa4`. Factory allocation remains `0x108`; no SelfSave-specific data field or reserve is justified.

Factory stores at `0x005aa196/0x005aa19c/0x005aa1a6` and raw constructor stores at `0x005b67df/0x005b67e7/0x005b67f1` install all three views. The active confirm handler is vtable-routed; private nonvirtual send helper `0x005b6870` correctly has no slot and has no ordinary route. Human source calls it once from the active method, while release output inlines its exact send core. Constructor/helper/factory route absence remains a confidence cap, not a no-source decision.

Shared scalar wrapper `0x005b7940` and adjustors `0x005b77c8/0x005b77d3` are compiler ABI. The wrapper's high table fanout, deletion-flag behavior, LineInputPane cleanup, and adjustor tails do not justify an explicit SelfSave destructor, thunk body, vtable array, or RTTI record.

Keep this page as the one-to-one source-local type index over UID0002N8 and direct child of [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md). Broad [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md) and [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md) stay `NONE/FALSE/blank` mixed-owner indexes. Do not split the exact range or move only this page to CommandInputPanes. Any future file consolidation must move the complete SelfSave class/source unit.

## Assignment Gate

`AUTOGEN_PARENT_UID` remains [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md). This source-local child remains `90/94`, and the direct class parent is `91/93`. The class parent remains the exact semantic source owner regardless of the bounded historical file-grouping uncertainty between [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) and a future coordinated [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) consolidation.

## 2026-07-13 B004 Private Helper Source-Disposition Synchronization

The accepted UID0003O7 change does not alter any vtable bytes, ranges, slots, RTTI, stores, owner/emitter metadata, score, position, or formal marker. Private nonvirtual `SelfSaveInputPane::SendSelfSavePacket` has no table entry by design. Primary slot `+0x48` remains `0x00630608 -> 0x005b6800` for `OnConfirmInput`; its release body is the compiler-inlined realization of one human source helper call. No explicit destructor, adjustor, table array, locator, RTTI record, or helper slot is added.

All historical negative evidence remains useful: UID0003O7 has no ordinary route or vtable entry, constructor/factory starts remain route-negative, and original file grouping is stripped. These facts cap confidence but do not support file-static, class-static, virtual, compiler-only, no-code, or duplicate handwritten packet-source alternatives.

## Score Rationale

Completion `90` records the exact target hash, all 32 slot targets across three views, both internal locator cells, all COL/object offsets, eight-base hierarchy, paired stores, active handler, predecessor/successor boundaries, compiler-wrapper disposition, no-padding/no-split result, source owner, and exact formal marker. It remains below final because several inherited slot spellings and original file grouping are not recoverable.

Confidence `94` reflects agreement among bytes, decorated bases, RTTI, function lookup, xrefs, class/base layouts, constructor/factory stores, and active method behavior. It remains below `95` because original symbols are stripped and the raw constructor/helper/factory route and historical file grouping remain bounded uncertainties.

## Cross-References

- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md)
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md)
- [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md)
- [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md)
- [UID:0003O6][0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput](by-memory/0x005b6800-0x005b686c.SelfSaveInputPaneConfirmInput.md)
- [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md)

## Changes

- 2026-06-12 A004 Batch 313:
  - Created as the source-local `SelfSaveInputPane` by-vtable child of [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md).
  - Evidence: live IDA MCP confirmed the three decorated table bases, `0x88` / 136-byte exact span, representative stores at `0x005aa196` and `0x005b67df`, and the `BlockListenInputPane` successor boundary.
- 2026-06-19 Agent-B007 implementation: Added the corrected method-island/helper cross-references and recorded that the [UID:0003O7][0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw](by-memory/0x005b6870-0x005b68b1.SelfSaveInputPaneSendSelfSavePacketRaw.md) range correction does not add or change any vtable slot; scores and ownership stay unchanged.
- 2026-06-21 Rule 26 B005 incorporation: Added the source-ready constructor relationship and clarified that constructor vptr stores are evidence for the generated vtables, not handwritten table source; scores and ownership stay unchanged.
- 2026-07-13 Agent-B002 UID0002N8 callback: raised `86/91 -> 90/94`, set position `50`, installed the exact source-local-index marker, added the complete three-view/locator/RTTI/store/compiler-wrapper disposition, preserved broad indexes as non-emitting, and rejected raw ABI duplication or a partial file move.
- 2026-07-13 Agent-B004 UID0003O7 support sync: scores and formal marker unchanged; recorded expected private-nonvirtual slot absence and the source-call/release-inlining relation while preserving the complete compiler-generated vtable/RTTI disposition.
