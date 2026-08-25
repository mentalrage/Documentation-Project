*** UID:00054I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000066 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HistoryViewingPane Vtables

## Status

- Entity kind: semantic vtable, RTTI, inheritance, and source-cause inventory for [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md).
- Exact physical backing: [UID:00054H][0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData](by-memory/0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData.md), `[0x0061d9cc,0x0061da54)`, 136 bytes and 34 four-byte cells.
- Semantic owner: UID000066; source root: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md).
- Disposition: reconstructable semantic documentation with no emitter and blank formal CPP/H. Human source declares the class and methods; the compiler emits all tables, COLs, RTTI, vptr stores, adjustors, and scalar-delete machinery.

## Complete View Inventory

| View | Locator | Vtable base | Object offset | Slots | Authored HistoryViewingPane slots |
| --- | --- | --- | ---: | ---: | --- |
| Pane/GrafPort primary | `0x0061d9cc -> 0x0064a8cc` | `0x0061d9d0` | `+0x00` | 18 | slot zero compiler wrapper; terminal `0x0061da14 -> 0x00500020` is `OnPaint` |
| EventHandler secondary | `0x0061da18 -> 0x0064a97c` | `0x0061da1c` | `+0xa0` | 11 | adjustor at slot zero; `0x0061da20 -> 0x004fffa0` mouse/pointer; `0x0061da24 -> 0x004fff10` key/text |
| TimerHandler tertiary | `0x0061da48 -> 0x0064a990` | `0x0061da4c` | `+0xa4` | 2 | adjustor at slot zero; `0x0061da50 -> 0x004fff90` `OnTimer` |

The physical page contains the complete 34-cell address/value/identity table. The inherited primary slots are LObject runtime/change handling followed by Pane render, hierarchy, invalidation, description, bounds, layer, ordering, and event-registration behavior. The inherited EventHandler tail contains its remaining dispatch/offset/acceptance slots. No additional History-authored virtual exists outside the four listed overrides.

## RTTI And Inheritance

- All three COLs use type descriptor `0x00677438` and hierarchy descriptor `0x0064a8e0`.
- Primary COL `0x0064a8cc` has offset `0`; secondary COL `0x0064a97c` has offset `0xa0`; tertiary COL `0x0064a990` has offset `0xa4`. Signatures and construction-displacement offsets are zero.
- CHD `0x0064a8e0` has attributes `1`, seven bases, and base array `0x0064a8f0` in this order: HistoryViewingPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, `Singleton<HistoryViewingPane>`.
- Source inheritance is `class HistoryViewingPane : public Pane, public Singleton<HistoryViewingPane>`. Pane supplies the embedded GrafPort/LObject/EventHandler/TimerHandler facets; Singleton is a direct nonvirtual empty base.
- Singleton PMD `{+0xf8,-1,0}` and the first derived field at `+0xf8` prove direct EBO. Complete class size is `0x108`.

## Source-Authored And Compiler-Generated Disposition

| Entity | Address | Disposition |
| --- | --- | --- |
| constructor | `0x004ffd80-0x004ffec9` | authored source; installs all three vptrs while constructing the complete class |
| key/text override | `0x004fff10-0x004fff84` | authored `HandleKeyOrTextEvent(Event *)` |
| timer override | `0x004fff90-0x004fff95` | authored `OnTimer(int,int,int)`, always true |
| pointer/mouse override | `0x004fffa0-0x0050001a` | authored `HandlePointerOrMouseEvent(Event *)` |
| paint override | `0x00500020-0x0050008b` | authored `OnPaint()` |
| cleanup island | `0x004ffed0-0x004fff0a` | compiler constructor unwind; no independent source function |
| singleton clear helper | `0x005023b0-0x005023bb` | compiler EH helper caused by Singleton destruction |
| adjustors | `0x005024b6-0x005024cc` | compiler `this - 0xa0` and `this - 0xa4` deleting-destructor thunks |
| scalar wrapper | `0x00502760-0x005027cc` | compiler wrapper caused by the implicit virtual destructor |

The class should not declare an explicit destructor body. `mystr::StringBase<wchar_t>`, `Singleton<HistoryViewingPane>`, and `Pane` implicit destruction regenerate the observed member/base order, singleton clear, table restoration, delete flags, and adjustor routes.

## Constructor, Cleanup, And Destructor Store Parity

| Vtable base | Constructor store | Cleanup-island store | Destructor-wrapper store |
| --- | --- | --- | --- |
| primary `0x0061d9d0` | `0x004ffdf1` | `0x004ffed9` | `0x0050276c` |
| EventHandler `0x0061da1c` | `0x004ffdf7` | `0x004ffedf` | `0x00502772` |
| TimerHandler `0x0061da4c` | `0x004ffe01` | `0x004ffee9` | `0x0050277c` |

This three-way parity proves one complete HistoryViewingPane object rather than adjacent unrelated tables. The primary scalar-wrapper slot and both secondary adjustor slots are live compiler destruction routes, not handwritten methods.

## Boundaries And Ownership

- Physical predecessor is StaffsDialogPane ending at `0x0061d9cc`; physical successor is BackStoryDialogPane beginning at `0x0061da54`.
- Support-only UID00025Q records broad mixed-section containment and the exact child link. It is not a source owner and receives no UID0000JW report coverage.
- MainMenuPane owns six construction sites and resource selection only. It does not own the HistoryViewingPane class, vtables, methods, singleton, or layout.
- Historical `class_ChattingColorPane.cpp` routing is rejected owner pollution. No RTTI, field, vtable, caller, or range evidence assigns this family to chat UI.

## No-Code Proof

- Raw vtable/COL/RTTI arrays would duplicate compiler output and expose reverse-engineering artifacts in otherwise human-written source.
- Source completeness comes from the UID000066 class declaration, UID0001A0/UID0001A1 authored methods, UID0000R3 singleton source, and implicit destruction.
- No emitter and blank formal CPP/H are final dispositions, not unresolved placeholders.

## Negative Evidence

- No fourth table view, extra class-owned virtual, independent vtable global, interior split xref, or handwritten RTTI initializer was found.
- No complete HistoryViewingPane IDA UDT exists; Gate 2B therefore preserves safe Pane/facet types rather than introducing a partial layout.
- Adjacency to StaffsDialogPane, BackStoryDialogPane, and NewHistoryDialogPane does not imply shared semantic ownership.

## Cross-References

- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:00054H][0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData](by-memory/0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData.md)
- [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0001A7][0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md)
- [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md)
- [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md)
- [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md)

## Changes

- 2026-08-16 Agent-B010 accepted UID0000JW callback: created the semantic HistoryViewingPane vtable/RTTI page from the complete three-view physical child and seven-base hierarchy. UID allocation is validator-owned; score `93/95`, owner UID000066, reconstructable semantic documentation, no emitter, and blank formal source are intentional.
