*** UID:0004VM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000091 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewHistoryDialogPane Vtables

## Status

- Entity kind: semantic compiler-vtable and RTTI inventory for [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md).
- Exact physical backing: [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md), `[0x0061daf0,0x0061db8c)`, 156 bytes, SHA256 `BA7C96EB88036F4D54AC50D72A74A0CA697655B45F4B8F1AAA13256C0EBF9D26`.
- Semantic owner: class UID000091; source route: [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md).
- Disposition: source-declared and compiler-generated. This page is non-reconstructable, non-emitting, and has exact blank formal C++ because the human class declaration and ordinary methods regenerate the tables.

## Vtable Views

| Class view | Locator | Vtable base | Object offset | Constructor/lifecycle meaning |
| --- | --- | --- | ---: | --- |
| primary DialogPane view | `0x0061daf0` | `0x0061daf4` | `+0x00` | complete-object primary vptr; slot zero targets scalar wrapper `0x00502920` |
| secondary EventHandler-related view | `0x0061db50` | `0x0061db54` | `+0xa0` | inherited secondary subobject; destructor adjustor `0x005024f8` plus pointer/key callbacks |
| tertiary TimerHandler-related view | `0x0061db80` | `0x0061db84` | `+0xa4` | inherited tertiary subobject; destructor adjustor `0x00502503` |

- The primary, secondary, and tertiary views contain exactly 23, 11, and 2 slots.
- The constructor installs all three bases. The scalar deleting wrapper uses the primary route, while two eleven-byte adjustors recover the complete object from secondary receivers.
- Object offsets `0xa0` and `0xa4` are inherited subobject layout, not NewHistoryDialogPane source data members.

## Proven Slots

| Cell | Target | Source/compiler interpretation |
| --- | --- | --- |
| `0x0061daf4` primary `+0x00` | `0x00502920` | compiler scalar deleting destructor wrapper; implicit class destruction cause |
| `0x0061db54` secondary `+0x00` | `0x005024f8` | compiler `this - 0xa0` destructor adjustor |
| `0x0061db58` secondary callback | `0x00500610` | source virtual `bool NewHistoryDialogPane::HandlePointerOrMouseEvent(Event *)` |
| `0x0061db5c` secondary callback | `0x005005c0` | source virtual `bool NewHistoryDialogPane::HandleKeyOrTextEvent(Event *)` |
| `0x0061db84` tertiary `+0x00` | `0x00502503` | compiler `this - 0xa4` destructor adjustor |

- The pointer/key slot identities are positive controls for the accepted mutable `Event *` signatures.
- Historical `OnMouseInput`, `OnKeyInput`, `Close`, and local event constants are superseded reverse-engineering labels, not additional table entries or methods.

## RTTI And Inheritance

- Complete-object locators are `0x0064aa80`, `0x0064ab34`, and `0x0064ab48` for the three views.
- The eight-entry hierarchy is NewHistoryDialogPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<NewHistoryDialogPane>`.
- NewHistoryDialogPane directly derives from DialogPane and directly derives from `Singleton<NewHistoryDialogPane>`.
- Singleton PMD `{0x26c,-1,0}` proves a direct nonvirtual empty base at complete-object end; complete object size remains `0x26c` with no authored derived member.
- EventHandler `+0xa0` and TimerHandler `+0xa4` are inherited through DialogPane, not repeated direct bases.

## Source Cause And Ownership

- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md) declares the two direct bases, constructor, and the two Event callbacks while intentionally omitting an explicit destructor.
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) provides the source constructor and callback bodies.
- `Singleton<NewHistoryDialogPane>` construction/destruction causes publication, adjusted-null fallback, constructor-EH clear, and scalar-wrapper clear around the implicit derived destructor.
- [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonBaseDestructor.md), [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md), and [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneScalarDeletingDestructor.md) are compiler support, not authored methods; D6/D8 receive accepted UID-preserving path corrections later in this callback.
- The compiler/linker, not a handwritten source table, emits all three vtables, RTTI, scalar wrapper, adjustors, and vptr stores.
- MainMenuPane is only the show parent, the scroller is only a runtime consumer, and UID00025Q is only physical containment. None is the semantic vtable owner.

## Boundaries And Physical Relationship

- Physical backing begins exactly at `0x0061daf0` after preceding history-dialog data and ends before [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md) at `0x0061db8c`.
- [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md) carries `Nested:0` as a direct address-sorted child of UID00025Q while retaining canonical owner UID000091.
- This semantic page is not a by-memory child and therefore has no `Nested` metadata.

## No-Code Proof

- Handwriting pointer arrays, RTTI structures, vptr fields, adjusted wrappers, or scalar-delete/delete-flag code would duplicate compiler output.
- The exact source cause is represented on the class and method destinations. Blank emitter, blank position, and blank formal C++ are final dispositions rather than unresolved placeholders.
- Rejected alternatives: standalone vtable source file, MainMenuPane ownership, scroller ownership, broad-aggregate ownership, manual callback table, explicit destructor, or explicit Singleton specialization in this translation unit.

## Negative Evidence

- No separate source symbol or initializer for a vtable array survives.
- No additional class member, authored destructor action, fourth vtable view, or alternate input callback is required.
- No constructor-start xref survives, but that bounded liveness gap affects source confidence only and does not make this proven class/vtable family hand-authored data.

## Score Rationale

- Completion `92`: physical range/hash, all three views, proven slots, stores, RTTI hierarchy, direct bases, EBO, size, semantic/physical ownership split, source cause, and no-code disposition are complete.
- Confidence `96`: direct data/code xrefs, exact bytes, RTTI PMDs, and independent class/method evidence agree; only unavailable original linker-symbol provenance remains.

## Cross-References

- [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md)
- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md)
- [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md)

## Historical And Superseded Assumptions

- Broad HistoryViewingPane/BackStoryDialogPane/NewHistoryDialogPane range wording remains aggregate history only; the exact NewHistory backing child is `[0x0061daf0,0x0061db8c)`.
- Historical source emitted `NewHistoryDialogPane::~NewHistoryDialogPane()` only to clear the singleton. Direct Singleton EBO and complete scalar-wrapper analysis prove that clear is implicit base teardown, so no unique authored destructor remains.
- Historical stale input names, raw vtable arrays, and manual singleton publication/clear source are superseded by the complete declaration and compiler/source split.

## Changes

- 2026-07-21 B004 UID0001PV accepted callback: created the semantic NewHistoryDialogPane vtable inventory after physical UID0004VL registration, with exact class ownership, slot/RTTI/EBO evidence, and blank compiler-data C++ disposition.
