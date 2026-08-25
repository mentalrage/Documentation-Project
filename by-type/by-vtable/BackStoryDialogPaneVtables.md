*** UID:0004WB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BackStoryDialogPane Vtables

## Status

- Entity kind: semantic compiler-vtable and RTTI inventory for [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md).
- Exact physical backing: [UID:0004WA][0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData](by-memory/0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData.md), `[0x0061da54,0x0061daf0)`, 156 bytes, SHA256 `612C02F9BECCB97561B968979DAA3F8D743982053D8FBE8A7EBEA5CB37422771`.
- Semantic owner: class UID00000T; source route: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) / `NexusTK/login/BackStoryDialogPane.cpp`.
- Disposition: source-declared and compiler-generated. This semantic page is non-reconstructable, non-emitting, and has exact blank formal C++ because the human class declaration and ordinary methods regenerate the tables.

## Vtable Views

| Class view | Locator | Vtable base | Object offset | Slot count | Constructor/lifecycle meaning |
| --- | --- | --- | ---: | ---: | --- |
| primary `DialogPane` view | `0x0061da54` | `0x0061da58` | `+0x00` | 23 | complete-object primary vptr |
| secondary inherited view | `0x0061dab4` | `0x0061dab8` | `+0xa0` | 11 | inherited secondary subobject |
| tertiary inherited view | `0x0061dae4` | `0x0061dae8` | `+0xa4` | 2 | inherited tertiary subobject |

- The constructor installs all three bases. The primary view reaches the scalar deleting wrapper directly, while the secondary/tertiary views recover the complete object through `-0xa0` and `-0xa4` adjustors.
- Object offsets `0xa0` and `0xa4` are inherited `DialogPane`-family layout, not BackStory source members.

## Proven Slots

| Cell | Target | Source/compiler interpretation |
| --- | --- | --- |
| `0x0061da58`, primary slot 0 | `0x00502600` / [UID:0004W9][0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor](by-memory/0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor.md) | compiler scalar deleting wrapper caused by implicit virtual destruction |
| `0x0061daa0`, primary `+0x48` | `0x005003f0` / [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) | source virtual `void BackStoryDialogPane::OnControlCommand(int controlIndex, int notifyCode)` |
| `0x0061dab8`, secondary slot 0 | `0x0050245e` / [UID:0004W8][0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks](by-memory/0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks.md) | compiler `this - 0xa0` destructor adjustor |
| `0x0061dae8`, tertiary slot 0 | `0x00502469` / UID0004W8 | compiler `this - 0xa4` destructor adjustor |

- `OnControlCommand` is the established `DialogPane` virtual slot name/signature. Historical `HandleButtonClick` is rejected as a generic reverse-engineering label rather than a second virtual.
- The primary/adjusted destruction cells represent one implicit source destructor contract, not three authored destructor bodies.

## RTTI And Inheritance

- The class RTTI cluster is rooted around `0x0064a9a4`; the BackStory type descriptor is at `0x0067748c`, and `Singleton<BackStoryDialogPane>` is at `0x006774b0`.
- The eight-entry hierarchy is `BackStoryDialogPane`, `DialogPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`, and `Singleton<BackStoryDialogPane>`.
- BackStoryDialogPane directly derives from `DialogPane` and directly derives from `Singleton<BackStoryDialogPane>`.
- Singleton PMD `{0x26c,-1,0}` and attributes `0x40` prove a direct nonvirtual empty base at complete-object end.
- Complete object size is `0x26c`. The derived class has no recovered authored data members and needs no explicit destructor declaration or body.

## Source Cause And Ownership

- [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md) declares both direct bases, the constructor, and protected `OnControlCommand` override.
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) provides the source constructor and command-handler bodies.
- [UID:0003HH][0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor](by-memory/0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor.md), UID0004W8, and UID0004W9 are compiler/template artifacts caused by construction unwind, multiple vtable views, direct Singleton teardown, and deleting-destructor ABI.
- The compiler/linker, not a handwritten source table, emits the three vtables, RTTI hierarchy, scalar wrapper, adjustor entries, and vptr stores.
- MainMenuPane is only a show/cleanup dependency; HistoryViewingPane is the current active replacement path; UID00025Q is only physical containment. None is the semantic owner.

## Boundaries And Physical Relationship

- Exact physical backing begins where HistoryViewingPane vtable/RTTI data ends at `0x0061da54` and ends where [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md) begins at `0x0061daf0`.
- UID0004WA carries `Nested:0` as a direct address-sorted child of [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md) while retaining class canonical ownership.
- This semantic by-vtable page is not a by-memory child and therefore has no `Nested` metadata.

## No-Code Proof

- Handwriting pointer arrays, RTTI records, vptr fields, adjusted wrappers, scalar-delete flags, or address constants would duplicate compiler output.
- The exact source cause is represented on the class, semantic global, and core-method destinations. Blank emitter, blank position, and blank formal C++ are final dispositions rather than unresolved placeholders.

## Negative Evidence And Rejected Alternatives

- No separate source symbol or initializer for a vtable array is present.
- No additional BackStoryDialogPane field, authored destructor action, fourth vtable view, or alternate action virtual is required.
- No current constructor launcher survives, but that reachability gap affects historical lifecycle confidence only; it does not make the proven class/vtable family compiler-only or ownerless.
- Rejected source shapes include a standalone vtable source file, MainMenuPane ownership, HistoryViewing ownership, broad-aggregate ownership, a manual callback table, and emitted compiler wrappers.

## Score Rationale

- Completion `92`: physical range/hash, all three views and slot counts, proven source/compiler cells, constructor stores, RTTI hierarchy, direct bases, EBO, size, semantic/physical ownership split, boundaries, and no-code disposition are complete.
- Confidence `96`: direct table bytes/cells, code/data xrefs, constructor stores, RTTI PMDs, and independent class/method/compiler evidence agree; only unavailable original linker symbol provenance remains.

## Cross-References

- [UID:0004WA][0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData](by-memory/0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData.md)
- [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md)
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0004W8][0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks](by-memory/0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks.md)
- [UID:0004W9][0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor](by-memory/0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor.md)
- [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md)
- [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md)

## Historical And Superseded Assumptions

- Broad history/BackStory range wording is retained as aggregate history only; exact BackStory backing is `[0x0061da54,0x0061daf0)`.
- Historical source reconstruction emitted explicit singleton publication/clear and generic `HandleButtonClick` naming. Direct Singleton EBO and current DialogPane slot analysis supersede both source shapes.
- Generic raw-vtable and manual-destructor interpretations are superseded by the class declaration plus compiler/source-effect split above.

## Changes

- 2026-07-22 B002 UID00029F accepted callback: created the semantic BackStoryDialogPane vtable inventory without a guessed UID after real physical/compiler child mappings existed, with exact class ownership, slot/RTTI/EBO evidence, and blank compiler-data C++ disposition.
