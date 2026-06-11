*** UID:0001X2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00000W | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BlackHole Vtable

## Status

- Entity kind: primary `BlackHole` vtable.
- Vtable base: `0x00613118`.
- RTTI pointer: `0x00613114 -> 0x0064254c` (`??_R4BlackHole@@6B@`).
- Confidence: strong for table base, slot boundary, and inherited `List` slot meanings.
- Owning class: [UID:00000W][BlackHole](by-class/BlackHole.md).
- Source owner: [UID:0000HR][BlackHole](by-file/BlackHole.md).
- Autogen status: attached to the `BlackHole` class page; final C++ remains blank under the `95/95` reconstruction gate.

## Slots

| Slot | Address | Current interpretation | Notes |
| --- | --- | --- | --- |
| `+0x00` | [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md) | `BlackHole::ScalarDeletingDestructor` | Clears `dword_67A74C`, tears down the list, and optionally frees `this`. |
| `+0x04` | `0x004f4b10` | inherited `LObject` runtime/type helper | Matches the same base slot used by `List`. |
| `+0x08` | `0x0041b6c0` | inherited/default no-op virtual | Shared default callback body. |
| `+0x0c` | `0x004f32a0` | `List::GetData` | Inherited fixed-width array access. |
| `+0x10` | `0x004f32b0` | `List::GetElementAt` | Used by `BlackHole::EnqueueIfMissing` and `ReleaseQueuedOwnedObjects`. |
| `+0x14` | `0x004f32e0` | `List::InsertAt` | Used for direct insertion by queue helpers. |
| `+0x18` | `0x004f33c0` | `List::Append` | Thin append wrapper around `InsertAt(count, ...)`. |
| `+0x1c` | `0x004f33e0` | `List::RemoveAt` | Inherited list mutation. |
| `+0x20` | `0x004f34a0` | `List::RemoveAll` | Used after draining queued objects. |
| `+0x24` | `0x004f34b0` | `List::SwapElements` | Inherited list utility. |

The table stops after `+0x24`. The next dword at `0x00613140` is non-function data (`unk_613140`), and the next visible RTTI/vtable pair belongs to `BrowserDialogOld` at `0x00613150` / `0x00613154`.

## Evidence

- 2026-05-31 IDA MCP `lookup_funcs` confirms `0x00613118`, `0x00613140`, and `0x00613154` are not functions; they are `.rdata` addresses.
- IDA MCP `xrefs_to 0x00613118` reports vptr stores from `BlackHole::BlackHole` at `0x004690d7` and `0x004690eb`, from the non-deleting destructor at `0x00469100`, and from the scalar deleting destructor at `0x00469246`.
- IDA MCP `xrefs_to 0x00469240` reports the vtable data reference at `0x00613118`.
- 2026-05-31 IDA MCP `xrefs_to 0x00613140` reports later browser code references at `0x004708ed` and `0x0047099d`, supporting that `0x00613140` is not a continued BlackHole slot.
- 2026-05-31 IDA MCP `xrefs_to 0x00613154` reports BrowserDialogOld vptr stores at `0x004692fe`, `0x00469455`, and `0x0047060c`, supporting the next visible RTTI/vtable pair boundary.
- IDA `.rdata` inspection on 2026-05-26 shows ten function-pointer slots from `0x00613118-0x0061313f`, then non-function data at `0x00613140`.
- 2026-05-31 IDA MCP `py_eval` confirms `0x00613114 -> ??_R4BlackHole@@6B@`, `0x00613118 -> sub_469240`, slot `+0x24` at `0x0061313c -> sub_4F34B0`, non-function `unk_613140` at `0x00613140`, and BrowserDialogOld `off_613154 -> sub_4705E0`.
- The inherited slot addresses match the documented [UID:000079][List](by-class/List.md) virtual surface at `0x0061ce2c`.
- Current `source-3/simroot_v2/class_BlackHole.meta_wave3` still reports `vtable_count: 0` and `vtables: []`, so this page is the reconstruction anchor until generated vtable inventory is fixed.

## Parent Rationale

Attach this vtable type to [UID:00000W][BlackHole](by-class/BlackHole.md) rather than directly to the file root because it is the primary virtual surface for the `BlackHole` class. The parent class is already reconstructable, attached to [UID:0000HR][BlackHole](by-file/BlackHole.md), and documents the same `0x00613118` vtable, six method ranges, singleton state, and inherited `List` surface. The type page remains the narrow home for slot ordering and `.rdata` boundary evidence, while the class page owns the source-level declaration.

## Cross-References

- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000HR][BlackHole](by-file/BlackHole.md)
- [UID:0001TT][BlackHoleLayout](by-type/by-struct/BlackHoleLayout.md)
- [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md)
- [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md)
- [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- [UID:000079][List](by-class/List.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable page was reconstructable but unassigned in generated type coverage despite linking to the `BlackHole` class and file pages.
  - What changed: attached the vtable to [UID:00000W][BlackHole](by-class/BlackHole.md), raised completion to `86`, and added an explicit parent rationale.
  - Summary/evidence: the class and file pages both document the same `0x00613118` primary vtable, IDA-confirmed constructor/destructor vptr stores, and inherited `List` slots; the class is above the 80% attachment threshold and remains the correct source-level owner.

- What existed before: the page had strong vtable slot notes but remained scored as unevaluated and reconstructability was not marked.
- What it was changed to: the page is now marked reconstructable and scored `84/90`; evidence notes include refreshed 2026-05-31 IDA MCP boundary/xref checks for the BlackHole table and adjacent data.
- Summary/evidence: IDA MCP confirms the ten-slot table at `0x00613118-0x0061313f`, the vtable slot xref to `BlackHole` scalar deleting destructor, constructor/destructor vptr stores, non-function data at `0x00613140`, and the next BrowserDialogOld vtable boundary at `0x00613154`.
