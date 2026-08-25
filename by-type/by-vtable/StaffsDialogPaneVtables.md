*** UID:0004VK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000DY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaffsDialogPane Vtables

## Status

- Entity kind: semantic compiler-vtable and RTTI inventory for [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md).
- Exact physical backing: [UID:0004VJ][0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData](by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md), `[0x0061d930,0x0061d9cc)`, 156 bytes, SHA256 `E7A4B9BD17874390E125AB2A291521F5A64FB8DB3FF247836324DAD20CC8F86E`.
- Semantic owner: class UID0000DY; source route: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md).
- Disposition: source-declared and compiler-generated. This page is non-reconstructable, non-emitting, and has exact blank formal C++ because the human class declaration and ordinary methods regenerate the tables.

## Vtable Views

| Class view | Locator | Vtable base | Object offset | Constructor/lifecycle meaning |
| --- | --- | --- | ---: | --- |
| primary DialogPane view | `0x0061d930` | `0x0061d934` | `+0x00` | complete-object primary vptr |
| secondary EventHandler-related view | `0x0061d990` | `0x0061d994` | `+0xa0` | inherited secondary subobject |
| tertiary TimerHandler-related view | `0x0061d9c0` | `0x0061d9c4` | `+0xa4` | inherited tertiary subobject |

- The constructor installs all three bases. The scalar deleting wrapper restores/uses the primary view, while the two eleven-byte adjustors recover the complete object from secondary receivers.
- Object offsets `0xa0` and `0xa4` are inherited subobject layout, not StaffsDialogPane source data members.

## Proven Slots

| Cell | Target | Source/compiler interpretation |
| --- | --- | --- |
| `0x0061d934` primary `+0x00` | `0x00502cc0` | compiler scalar deleting destructor wrapper; implicit class destruction cause |
| `0x0061d97c` primary `+0x48` | `0x004ffd20` | source virtual `void StaffsDialogPane::OnControlCommand(int controlId, int notifyCode)` |
| `0x0061d994` secondary `+0x00` | `0x00502592` | compiler `this - 0xa0` destructor adjustor |
| `0x0061d9c4` tertiary `+0x00` | `0x0050259d` | compiler `this - 0xa4` destructor adjustor |
| `0x0061d9c8` tertiary terminal | `0x00544e90` | inherited/shared handler, not a new Staffs method |

- `OnControlCommand` is the established DialogPane virtual slot name and signature. Historical `OnDialogAction` is rejected as a generic reverse-engineering label.
- [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md) contains the two exact adjustors. UID0001A9 and UID0001AJ are compiler-generated Singleton-base/scalar-wrapper support, not authored methods.

## RTTI And Inheritance

- Exact RTTI cluster `[0x0064a7f0,0x0064a8cc)` has SHA256 `48E3DA5BFA1F1604A4C05013B550EC882D731A95D551B546B88D413EE0D5ADA7`.
- The eight-entry hierarchy is StaffsDialogPane, DialogPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<StaffsDialogPane>`.
- StaffsDialogPane directly derives from DialogPane and directly derives from `Singleton<StaffsDialogPane>`.
- Singleton PMD is `{0x26c,-1,0}`; attributes `0x40` prove a direct nonvirtual empty base at complete-object end.
- Complete object size is `0x26c`. The derived class has no authored data members and needs no explicit destructor declaration or body.

## Source Cause And Ownership

- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md) declares the direct bases, constructor, and protected `OnControlCommand` override.
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) provides the source constructor and virtual method body.
- `Singleton<StaffsDialogPane>` construction/destruction causes publication, adjusted-null fallback, constructor-EH clear, and scalar-wrapper clear around the implicit derived destructor.
- The compiler/linker, not a handwritten source table, emits the three vtables, RTTI hierarchy, scalar wrapper, adjustor entries, and vptr stores.
- MainMenuPane is only the show-parent/layer dependency. The mixed UID00025Q aggregate is only physical containment. Neither is the semantic owner.

## Boundaries And Physical Relationship

- Physical backing begins exactly where the ScrolledPictureControlPane vtable subrange ends at `0x0061d930` and ends before HistoryViewingPane at `0x0061d9cc`.
- [UID:0004VJ][0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData](by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md) carries `Nested:0` as a direct address-sorted child of UID00025Q while retaining canonical owner UID0000DY.
- This semantic page is not a by-memory child and therefore has no `Nested` metadata.

## No-Code Proof

- Handwriting pointer arrays, RTTI structures, vptr fields, adjusted wrappers, or scalar-delete/delete-flag code would duplicate compiler output.
- The exact source cause is represented on the class and method destinations. Blank emitter, blank position, and blank formal C++ are final dispositions rather than unresolved placeholders.
- Rejected alternatives: a standalone vtable source file, MainMenuPane ownership, broad-aggregate ownership, a manual callback table, or GM/staff gameplay data.

## Negative Evidence

- No separate source symbol or initializer for a vtable array is present.
- No additional StaffsDialogPane field, authored destructor action, fifth vtable view, or alternate action virtual is required.
- No direct constructor caller survives, but that reachability gap affects source confidence only; it does not make the proven class/vtable family compiler-only.

## Score Rationale

- Completion `92`: physical range/hash, all three views, proven slots, stores, RTTI hierarchy, direct bases, EBO, size, semantic/physical ownership split, source cause, and no-code disposition are complete.
- Confidence `96`: direct data/code xrefs, exact bytes, RTTI PMDs, and independent class/method evidence agree; only unavailable original linker symbol provenance remains.

## Cross-References

- [UID:0004VJ][0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData](by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md)
- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md)
- [UID:00025Q][0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData](by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md)

## Historical And Superseded Assumptions

- Broad Staffs/history range wording is retained as aggregate history only; the exact Staffs backing range is `[0x0061d930,0x0061d9cc)`.
- Historical source emitted `StaffsDialogPane::~StaffsDialogPane()` only to clear the singleton. Direct Singleton EBO and complete scalar-wrapper analysis prove that clear is implicit base teardown, so no unique authored destructor remains.
- Historical `OnDialogAction`, raw vtable-array, and manual singleton-publication source shapes are superseded by the class declaration and compiler/source split above.

## Changes

- 2026-07-21 B001 UID0001PT accepted callback: created the semantic StaffsDialogPane vtable inventory after physical UID0004VJ registration, with exact class ownership, slot/RTTI/EBO evidence, and blank compiler-data C++ disposition.
