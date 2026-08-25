*** UID:0001YI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PursuitMessageDialogPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md).
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md).
- Direct canonical owner/emitter: [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md), which routes to [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md).
- Exact vtable-data range: [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md).
- Confidence: very strong for vtable bases/stores/slots, seven-entry RTTI hierarchy, six derived classes, shared response ownership, and the source-declared/generated-binary boundary.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x00622428` | `0x0054cac8` | `+0x00` | Primary `DialogPane` view. |
| secondary | `0x00622488` | `0x0054cad0` | `+0xa0` | EventHandler view with the canonical packet-event override at slot `+0x10`. |
| tertiary | `0x006224b8` | `0x0054cada` | `+0xa4` | Event/update-handler view. |

The raw constructor at `0x0054cab0-0x0054cae9` is the only direct code xref to these three table bases in the current IDA database. IDA still does not model that constructor start as a function.

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x00622428` | `+0x00` | `0x00520b70` | Shared default scalar deleting destructor, not uniquely owned by this class. |
| primary `0x00622428` | `+0x44` | `0x0049f090` | Inherited dialog focus/selection drawing virtual. |
| primary `0x00622428` | `+0x48` | `0x0041b6c0` | Base no-op/default slot. |
| primary `0x00622428` | `+0x4c` | `0x0041b6a0` | Guard/no-op slot. |
| primary `0x00622428` | `+0x50` | `0x0049f1d0` | Inherited dialog content drawing virtual. |
| primary `0x00622428` | `+0x54` | `0x0049f2e0` | Inherited dialog border/background drawing virtual. |
| primary `0x00622428` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| secondary `0x00622488` | `+0x00` | `0x00520aa5` | Shared adjustor thunk into `0x00520b70` with `this - 0xa0`. |
| secondary `0x00622488` | `+0x10` | `0x0054caf0` | [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md), source `PursuitMessageDialogPane::HandlePacketEvent(Event*)`. |
| tertiary `0x006224b8` | `+0x00` | `0x00520ab0` | Shared adjustor thunk into `0x00520b70` with `this - 0xa4`. |
| tertiary `0x006224b8` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x5c` as a `PursuitMessageDialogPane` virtual: it is RTTI metadata for the secondary table. Secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` is RTTI for the following `MessageDialog` table cluster.

The secondary table follows canonical EventHandler order: adjusted destructor at `+0x00`; pointer/mouse, key/text, and IME families at `+0x04/+0x08/+0x0c`; `HandlePacketEvent` at `+0x10`; system/control and type-19 families at `+0x14/+0x18`; then forwarding, pair-output, and acceptance defaults through `+0x28`. The exact `0x00622498` cell fixes the source method; seven later table cells are inherited uses, not separate wrappers.

## IDA MCP Evidence

- `list_globals *PursuitMessageDialogPane*` reports vtables at `0x00622428`, `0x00622488`, and `0x006224b8`, plus RTTI records at `0x0064e360`, `0x0064e3c0`, and `0x0064e3d4`.
- IDA MCP `py_eval` on 2026-06-01 confirms the exact [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) child range: previous `PrimeNumberGenerator` data ends at `0x00622424`, primary/secondary/tertiary `PursuitMessageDialogPane` RTTI and vtable views occupy `0x00622424-0x006224c0`, and `0x006224c0` starts `MessageDialog` RTTI.
- Raw constructor disassembly at `0x0054cab0-0x0054cae9` calls `DialogPane::DialogPane(L"", 1, 1)`, then stores the three table bases at `0x0054cac8`, `0x0054cad0`, and `0x0054cada`.
- `xrefs_to` the three table bases reports only those constructor stores.
- `lookup_funcs` confirms `0x00520aa5`, `0x00520ab0`, `0x00520b70`, and `0x0054caf0` as modeled functions, while `0x0054cab0` remains `Not a function`.
- `xrefs_to 0x0054caf0` reports vtable data refs at `0x00622498`, `0x00622534`, `0x006225d0`, `0x0062266c`, `0x00622708`, `0x0062292c`, `0x006229c8`, and `0x00622cc8`, showing the handler is shared by the message/menu dialog family.
- Current `class_PursuitMessageDialogPane.meta_wave3` reports `vtable_count: 0` even though active source placeholders name `PursuitMessageDialogPane_vtable`, `PursuitMessageDialogPane_vtable2`, and `PursuitMessageDialogPane_vtable3`.
- 2026-06-16 C001 live IDA refresh on session `b001_maildialogs_0000ZO_20260616` reconfirmed the raw-constructor-only stores to the three vtable bases: `xrefs_to 0x00622428`, `0x00622488`, and `0x006224b8` returned only `0x0054cac8`, `0x0054cad0`, and `0x0054cada` respectively.
- The same refresh reconfirmed `0x0054cab0` is still not an IDA function, while `0x0054caf0` is a real `0x13f` function and its eight data refs remain the message/menu-dialog vtable slots listed above. The function was safely renamed in IDA from `sub_54CAF0` to `MessageDialogObjectResponseVirtual` and the IDB was saved.
- Decompilation after the rename still shows the documented opcode `0x3a` response path: Event packet discriminators `0x2f` and `0x30`, packet byte/dword/word helpers, `ObjectStatusBlob` parse at packet `+8`, signed-short trailer arithmetic, a 256-byte response local, and send through `g_packetSender`.
- Pursuit's class hierarchy descriptor at `0x0064e374` and base array at `0x0064e384` contain seven entries. TextDialog `0x0064e7d0/0x0064e7e0` and NexonclubProxyDialog `0x0064e85c/0x0064e86c` contain eight entries and use exact Pursuit base descriptor `0x0064e3a4` immediately after their own descriptor.
- Constructor and RTTI evidence establish six direct derived classes: `MessageDialog`, `MessageDialogLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, `TextDialog`, and `NexonclubProxyDialog`.
- The primary slot target `0x00520b70` has 17 primary vtable references. Bounded destructor review shows it calls source-owned `DialogPane::~DialogPane()` at `0x0049d9f0` directly and adds only scalar-delete flag/runtime handling.
- `PursuitMessageDialogPane` adds only POD packet fields, declares no explicit destructor, and relies on the implicitly declared virtual destructor produced from the base class virtual destructor contract. The primary wrapper, early adjustors, and proxy adjustor copies are generated ABI output rather than source definitions.

## Reconstruction Notes

Model `PursuitMessageDialogPane` as the direct `DialogPane`-derived message/text/proxy base with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. The class declaration, constructor, navigation methods, and `HandlePacketEvent(Event*)` are source-authored; exact table bytes, RTTI, implicit virtual destructor dispatch, shared scalar deleting wrapper, and adjustor thunks are compiler-generated. Formal blocks remain blank because UID0000BE H declares the class and UID0001FF CPP defines the packet method; do not handwrite a table, marker comment, or ABI destructor body here.

The former generic shared-response/`DialogObjectAction` wording is historical and superseded. Canonical Event/EventHandler evidence changes only the source-facing slot/type/name; exact table bases, stores, RTTI hierarchy, derived classes, wrapper disposition, xrefs, and score remain unchanged.

## Cross-References

- [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md)
- [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md)
- [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md)
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)

## Changes

- 2026-07-26 B002 accepted UID0001BM support correction:
  - Retained `90/94`, owner/emitter UID0000BE, reconstructable state, and changed the aggregate formal to truly blank non-emitting blocks.
  - Identified secondary `+0x10`, cell `0x00622498`, as `PursuitMessageDialogPane::HandlePacketEvent(Event*)`; added canonical EventHandler ordering and exact Event packet/body implications.
  - Preserved all RTTI/vtable/store/destructor/compiler-boundary evidence and historicalized only the superseded action-wrapper naming.

- 2026-07-16 Agent-B004 implementation callback:
  - Raised `86/90 -> 90/94`.
  - Changed direct owner/emitter from file UID0000LA to class UID0000BE.
  - Replaced the bounded marker with the exact accepted implicit-destructor/generated-wrapper disposition.
  - Added seven-entry Pursuit RTTI, six derived classes, 17-consumer wrapper evidence, source-owned DialogPane ordinary cleanup, and source/generated-binary separation.
- 2026-07-01 Agent-B010 implementation callback: added the accepted source-declared/generated-binary formal no-code marker. Metadata remains `86/90`; source emission belongs to the [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md) declaration and [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md), not this vtable inventory.
- 2026-06-01: Grading changed from validator-header `0/0` to `82/88`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the page had useful vtable notes, but no exact by-memory vtable-data child and no validator-visible score.
  - After: [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) records the exact primary/secondary/tertiary RTTI/vtable-data range while this page remains the type-level inventory.
  - Evidence: IDA MCP `py_eval` on 2026-06-01 verified the dword layout, neighboring `PrimeNumberGenerator`/`MessageDialog` boundaries, raw constructor vptr-store xrefs, shared response handler refs, and key slot function boundaries. Completion/confidence remain below `95` because the raw constructor has no IDA function object and final source-level shared virtual names are not audited to final-source confidence.
- 2026-06-03 autogen attachment pass:
  - Before: the vtable inventory was reconstructable at `82/88` but unparented.
  - Changed to: `AUTOGEN_PARENT_UID:0000LA`.
  - Evidence: the parent [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) is `88/80` and already owns the `PursuitMessageDialogPane` constructor, the exact [UID:0002OM][0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData](by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md) child, and the shared message-dialog response virtual.
- 2026-06-16 C001 assignment `C001-goal2-type-layout-ida-refresh-pursuit-item-light-20260616-11`:
  - Raised `82/88 -> 86/90`.
  - Summary/evidence: live IDA reconfirmed the three raw constructor store refs, no modeled function at `0x0054cab0`, the exact eight shared-response vtable refs, and the shared response decompilation. The exact vtable-data child is already `86/91` and the class/file owner route clears through [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md) and [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md). Superseded by the 2026-07-01 B010 callback, which emits a source-declared/generated-binary no-code marker while leaving raw-constructor reachability and final class/virtual naming below final-source confidence.
  - IDA DB change: `sub_54CAF0` -> `MessageDialogObjectResponseVirtual`; saved IDB.
