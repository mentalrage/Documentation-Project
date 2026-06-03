*** UID:0000NQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SimpleListPane

## Status

- Confidence: medium-high for standalone source-file identity; strong for class behavior and `ListPane` inheritance.
- Proposed module: `ui/controls/SimpleListPane.cpp`
- Alternative compact placement: [UID:0000KT][ListPane](by-file/ListPane.md)
- Current recovered source: `source-3/simroot_v2/class_SimpleListPane.cpp`
- Key ranges: [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md), [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md), [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md)

## File Role

`SimpleListPane` is a small `ListPane`-derived adapter for fixed, bounds-driven item lists. It constructs the shared list base with fixed row/column parameters and uses caller-supplied bounds to derive list width and height.

This class should stay in reusable UI controls, not in item, clan, board, mail, or menu feature modules. It is lower-level than feature-specific list panes, but narrower than the full [UID:0000KT][ListPane](by-file/ListPane.md) base.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `SimpleListPane::SimpleListPane` | `0x005739a0-0x005739f6` | Raw constructor-shaped code; derives size from a rectangle and delegates to `ListPane::ListPane(4, 10, width, height, 1, 1, 1)`. |
| non-scalar destructor and entry helpers | `0x00573a00-0x00573c38` | [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) aggregates the destructor and raw copied wide-string entry helper bodies. |
| copied-text helper children | `0x00573a00-0x00573c38` | [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md), [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md), [UID:0002LG][0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText](by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md), [UID:0002LH][0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText](by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md), and [UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) document the exact child ranges. |
| secondary destructor thunks | `0x00573c38`, `0x00573c43` | Compiler-generated adjustor thunks for secondary base subobjects at offsets `0xa0` and `0xa4`; track for vtable layout but ignore as handwritten source. |
| `SimpleListPane::~SimpleListPane` | `0x00573c50-0x00573d15` | Resets vtables, frees heap-backed list-entry buffers, calls the `ListPane` base destructor, then runs scalar/sized delete handling. |

## Ownership Decision

Keep `SimpleListPane` as a reusable control source or a small companion to `ListPane.cpp`.

- `SimpleListPane` depends directly on `ListPane` and the list storage cleanup path.
- It has no current direct constructor callers in IDA, so feature ownership cannot be inferred from caller fanout.
- Its destructor is virtual/destructor infrastructure reached through vtables rather than ordinary calls.
- Active generated output labels the base destructor call as `ClientItemMenuItemList::~ClientItemMenuItemList()`, but the called function is the shared `ListPane` destructor family. Treat the client-item-menu name as owner pollution.

## Evidence Notes

- IDA MCP reports `0x005739a0` as `Not a function`, but cached prewave code and Wave3 metadata both identify the raw constructor range.
- IDA MCP confirms `0x00573c38` and `0x00573c43` as 0xb-byte thunks and `0x00573c50` as a 0xc5-byte destructor.
- The constructor sets the primary vtable and two secondary vtables after constructing the `ListPane` base.
- The destructor reads the item list state, loops the list count, obtains each entry slot through the shared selected-entry/list helper, frees non-null heap buffers, nulls the slot, then destroys the base.
- 2026-05-31 IDA MCP raw-disassembly pass splits `0x00573a00-0x00573c38` into five exact child pages and confirms the copied-text append, insert, remove, and replace helper boundaries.
- The scalar deleting destructor uses sized-delete size `0x14c`, matching a thin `ListPane`-derived object with no confirmed local fields beyond inherited list control storage.
- 2026-05-26 recheck: current `simroot_v2/class_SimpleListPane.cpp` still emits only the destructor, with the base cleanup labeled as `ClientItemMenuItemList`; IDA still decompiles the two preceding functions as `this - 0xa0` and `this - 0xa4` adjustors into `0x00573c50`.
- The adjustor thunk pair is recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). The main destructor remains reconstructable project code.

## Cross-References

- [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md)
- [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md)
- [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md)
- [UID:0002LE][0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers](by-memory/0x00573a00-0x00573a98.SimpleListPaneDestroyEntryBuffers.md)
- [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md)
- [UID:0002LG][0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText](by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md)
- [UID:0002LH][0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText](by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md)
- [UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md)
- [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md)
- [UID:0001W3][SimpleListPaneLayout](by-type/by-struct/SimpleListPaneLayout.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: `SimpleListPane` file-level docs skipped the `0x00573a00-0x00573c38` helper span between constructor and scalar deleting destructor.
- Changed to: the missing non-scalar destructor and entry helper span is now represented by [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md).
- Evidence: 2026-05-28 IDA MCP disassembly shows `0x00573a00` frees list-entry buffers and calls base cleanup, while raw helpers at `0x00573aa0`, `0x00573b10`, and `0x00573b70` allocate/copy/free wide-string entry buffers.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document covers role, proposed contents, destructor/helper span, ownership decision, IDA evidence, generated-owner pollution, layout refs, and cross-references; confidence is capped by standalone-vs-ListPane source placement and raw constructor modeling.
- 2026-05-31: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/controls/`, changed completion/confidence from `84/78` to `86/82`, and added exact child helper references.
  - Before: The validator-managed projected path was blank and the copied-text helper island was represented mostly through the aggregate page.
  - After: The file stages as `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp`, matching the proposed source tree, and the proposed contents link the exact child helper pages.
  - Evidence: `by-project-structure/proposed-source-tree.md` already places `SimpleListPane.cpp` under controls; IDA MCP confirms the child helper boundaries and the `ListPane`-derived object size/vtables.
- 2026-06-03: Corrected copied-text helper links for the append/insert children.
  - Before: the file page linked old short ranges `0x00573aa0-0x00573b05` and `0x00573b10-0x00573b6a`.
  - After: the file page links `0x00573aa0-0x00573b08` and `0x00573b10-0x00573b6d`, matching the full return-instruction boundaries.
  - Evidence: IDA MCP raw disassembly shows `retn 4` bytes at `0x00573b05-0x00573b08` and `retn 8` bytes at `0x00573b6a-0x00573b6d`.
