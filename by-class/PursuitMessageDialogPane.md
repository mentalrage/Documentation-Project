*** UID:0000BE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PursuitMessageDialogPane

## Status

- Confidence: strong for constructor bytes, vtable ownership, and source family; medium for final source-level naming of the shared response virtual.
- Likely source: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Autogen parent: blank under the strict 85/85 gate. The direct file parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) clears at `89/85`, but this child remains `80/82`.
- Reconstructed C++ remains blank until final-source confidence.
- Constructor memory: [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md)
- Vtables: [UID:0001YI][PursuitMessageDialogPaneVtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md)

## Responsibility

`PursuitMessageDialogPane` is a tiny [UID:0000IT][DialogPane](by-file/DialogPane.md)-derived base/companion class for the NPC message dialog family. The recovered constructor only initializes a blank dialog shell with mode `1` and installs three `PursuitMessageDialogPane` vtables.

This should be treated as part of [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), not as a strong standalone original source file. Generated `MessageDialogLarger` also embeds a `PursuitMessageDialogPane.DialogPane` base field, which supports message-dialog ownership.

## Method And Glue Map

| Range | Method/glue | Ownership note |
| --- | --- | --- |
| [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md) | raw constructor bytes | IDA does not define a function object, but disassembly confirms a constructor-shaped body that calls `DialogPane::DialogPane(L"", 1, 1)` and installs three class vtables. |
| [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md) | shared message-dialog object/response virtual | Vtable-referenced by this class and sibling message/menu dialogs; parses an action payload and sends an opcode `0x3a` response packet. Current generated output omits the body. |
| [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md) | shared adjustor thunks | Current generated disabled output assigns these to this class, but IDA vtable refs show broad reuse across multiple dialog classes; excluded through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) | shared default scalar deleting destructor | Calls shared base dialog teardown and optional delete. It is referenced by many vtables, is excluded through [UID:0000VN][-ignored](by-memory/-ignored.md), and should not be treated as uniquely owned by this class. |

## Unresolved

- No direct IDA callers were found for the raw constructor at `0x0054cab0`.
- 2026-05-25 IDA MCP recheck still reports `0x0054cab0` as `Not a function`, no direct xrefs to the raw constructor, and the next modeled function at `0x0054caf0`; `0x0054caf0` is now documented as shared message-dialog virtual behavior rather than part of the raw constructor.
- The exact semantic meaning of "Pursuit" in this class name remains open. Current evidence only supports a message-dialog base/variant role, not pursuit gameplay ownership.
- The shared destructor thunks and default scalar deleting destructor need neutral names during source migration.
- 2026-05-26 IDA MCP recheck confirms the constructor raw gap remains, while `0x00520aa5`, `0x00520ab0`, and `0x00520b70` remain broad shared compiler destructor glue tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-26 IDA MCP vtable pass confirms vtables `0x00622428`, `0x00622488`, and `0x006224b8`; current Wave3 metadata still reports `vtable_count: 0`.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md)
- [UID:0001YI][PursuitMessageDialogPaneVtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md)
- [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md)
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:000086][MessageDialogLarger](by-class/MessageDialogLarger.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `76/74`.
  - Before: The page was unevaluated despite documenting raw constructor bytes, shared message-dialog virtual behavior, vtables, and destructor-glue caveats.
  - After: Scored as moderate-high completion with medium-high confidence because the exact "Pursuit" semantic and raw-constructor function promotion remain unresolved.
  - Evidence: Existing method/glue map, unresolved notes, IDA recheck notes, and message-dialog cross-references explain both the known behavior and uncertainty.
- 2026-06-03 autogen attachment pass:
  - Before: the class remained unparented at `76/74` even though the parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) was at `88/80` and the constructor/vtable child pages carried strong IDA-backed evidence.
  - Changed to: completion/confidence `80/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000LA`.
  - Evidence: [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md) documents the exact raw constructor and vtable stores at `82/86`; [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) documents the exact three-view vtable data at `84/89`; [UID:0001YI][PursuitMessageDialogPaneVtables](by-type/by-vtable/PursuitMessageDialogPaneVtables.md) ties those views to this message-dialog base/companion. Scores stay below `95` because the raw constructor is still not an IDA function object and the shared response virtual's final source-level name is not settled.
- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000LA` attached this class to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), and status text still referenced generated recovered output.
  - After: `AUTOGEN_PARENT_UID:` is blank and status records the strict `85/85` gate; score remains `80/82`.
  - Summary/evidence: the direct parent is now `89/85`, but this child remains below the child side of the current gate. The source-owner link remains as evidence, backed by the raw constructor, three-view vtable data, shared response virtual, and destructor-glue caveats already documented in linked by-memory/by-type pages.
