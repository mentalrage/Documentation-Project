*** UID:0000D8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleListPane

## Status

- Confidence: medium-high for reusable control ownership; final split from [UID:0000KT][ListPane](by-file/ListPane.md) remains a source-layout decision.
- Likely source file: [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md), or folded into [UID:0000KT][ListPane](by-file/ListPane.md) if final source layout favors compact control files.
- Current recovered file: `source-3/simroot_v2/class_SimpleListPane.cpp`

## Class Purpose

`SimpleListPane` is a thin `ListPane` subclass for basic list display. It provides a fixed list configuration from caller-supplied rectangle bounds and owns cleanup for heap-backed list-entry buffers stored in the underlying list.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleListPane` | `0x005739a0-0x005739f6` | Raw constructor-shaped code; computes width/height from rectangle fields and delegates to the `ListPane` base constructor. |
| `~SimpleListPane` body / entry helpers | [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) | Aggregate over the non-scalar destructor and copied wide-string append/insert/remove/replace helper bodies. |
| destroy copied-text buffers | [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md) | Restores vtables, frees each heap-backed copied-text buffer, and calls `ListPane` cleanup. |
| append copied text | [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md) | Raw helper that appends an allocated copy of a wide string. |
| insert copied text | [UID:0002LG][0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText](by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md) | Raw helper that inserts an allocated copy of a wide string at a supplied index. |
| remove copied text | [UID:0002LH][0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText](by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md) | Raw helper that frees the copied text then removes one list item. |
| replace copied text | [UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) | Raw helper that frees/removes an existing entry and reinserts a copied replacement. |
| destructor adjustor thunk | `0x00573c38` | Compiler-generated thunk; adjusts `this` by `-0xa0` before entering the main destructor. |
| destructor adjustor thunk | `0x00573c43` | Compiler-generated thunk; adjusts `this` by `-0xa4` before entering the main destructor. |
| `~SimpleListPane` | `0x00573c50-0x00573d15` | Resets vtables, frees entry buffers, destroys the base list pane, and handles scalar/sized delete flags. |

## Layout Notes

- The object uses the `ListPane` layout as its base and installs secondary vtable pointers at offsets matching the inherited list subobjects.
- The destructor reads the item-list state through the same storage area used by `ListPane` helpers; see [UID:0001W3][SimpleListPaneLayout](by-type/by-struct/SimpleListPaneLayout.md).
- IDA confirms no local `SimpleListPane` fields beyond inherited `ListPane` storage; scalar deleting destructor uses object size `0x14c`.

## Evidence Notes

- IDA MCP confirms the destructor and both thunks. It does not currently model the constructor at `0x005739a0` as a function, so the constructor remains raw-boundary evidence.
- Active Wave3 output only emits the destructor. The constructor and both thunks are in the disabled companion; this is tracked in [wave3_data_issues](../wave3_data_issues.md).
- The active destructor's `ClientItemMenuItemList` base-call name is not reliable ownership evidence. Behavior and address context match the shared `ListPane` destructor family.
- 2026-05-26 recheck: the active/disabled generated split is unchanged, and the thunk pair is now recorded as compiler-generated ignored memory in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-31 IDA pass split `0x00573a00-0x00573c38` into exact destructor and copied-text helper pages, and confirmed the vtable bases `0x00624c64`, `0x00624cec`, and `0x00624d1c`.

## Cross-References

- [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md)
- [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md)
- [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md)
- [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md)
- [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)
- [UID:0002LG][0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText](by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md)
- [UID:0002LH][0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText](by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md)
- [UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md)
- [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md)
- [UID:00007A][ListPane](by-class/ListPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `80`, confidence `74`.
- Evidence: the page documents the class role, likely ownership, constructor-shaped range, destructor/helper islands, thunk ranges, layout notes, Wave3 split, and ignored thunk tracking; confidence remains medium-high because the constructor is raw-boundary evidence and generated base-call names are polluted.
- Before: this page jumped from the raw constructor directly to the scalar deleting destructor/thunk range, leaving `0x00573a00-0x00573c38` undocumented.
- Changed to: the non-scalar destructor and entry helper island is now documented through [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md).
- Evidence: 2026-05-28 IDA MCP disassembly shows the vtable-restoring destructor at `0x00573a00`, followed by raw wide-string entry helpers at `0x00573aa0`, `0x00573b10`, and `0x00573b70`.
- 2026-05-31: Changed completion/confidence from `80/74` to `84/82`, marked the class reconstructable, and added the exact copied-text helper children.
  - Before: The class page referenced the aggregate helper island but did not list its child helper pages or the current layout/vtable evidence.
  - After: The class page links every current exact `SimpleListPane` child range and records object-size/vtable evidence, while leaving final C++ blank below the 95+ gate.
  - Evidence: IDA MCP raw-disassembly split of `0x00573a00-0x00573c38`, destructor decompilation, vtable xrefs, and updated layout page.
- 2026-06-03: Corrected copied-text helper links for the append/insert children.
  - Before: the class page linked the old short ranges `0x00573aa0-0x00573b05` and `0x00573b10-0x00573b6a`, which stopped at the starts of return instructions.
  - After: the class page links `0x00573aa0-0x00573b08` and `0x00573b10-0x00573b6d`.
  - Evidence: IDA MCP raw disassembly shows `retn 4` bytes at `0x00573b05-0x00573b08` and `retn 8` bytes at `0x00573b6a-0x00573b6d`.
