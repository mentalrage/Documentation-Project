*** UID:0000JV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# HierList

## Status

- Proposed module: `util/HierList.cpp`
- Confidence: strong for standalone class ownership, medium for exact folder.
- Current recovered source: `source-3/simroot_v2/class_HierList.cpp`

## File Role

`HierList.cpp` owns the tree-aware list container used by [UID:0000KL][Layer](by-file/Layer.md) to manage child pane hierarchy. It is not a UI pane class itself; it is reusable list infrastructure layered on [UID:0000KS][List](by-file/List.md).

## Proposed Contents

- [UID:000065][HierList](by-class/HierList.md)
- [UID:0001UQ][HierListNode](by-type/by-struct/HierListNode.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) aggregate and exact child range pages.
- wrapper helpers at `0x004ce7e0` and `0x004ce840`
- recursive node lookup helper at `0x004cec30`
- remove-node helper at `0x004ceb00`
- destructor bodies at `0x004ce760` and `0x004cedb0`

## Evidence

- Wave3 import provenance names `HierList.cpp`.
- IDA MCP confirms the constructor, insertion, removal, lookup, hierarchy-update, and destructor functions in the `0x004ce730-0x004cee52` cluster.
- `Layer::AddChildBefore` calls `HierList::InsertBefore`; `Layer::AddChildAfter` calls `HierList::InsertAfter`; `Layer::RemoveChild` calls the remove-node helper at `0x004ceb00`.
- IDA caller checks on 2026-05-25 show the recursive find helper at `0x004cec30` is shared by both insert paths, the remove helper, and its own recursive descent.
- `HierList` installs its own vtable at `0x0061b344` but shares base `List` virtual behavior where it does not need tree-specific repair.

## Migration Notes

Do not migrate directly from active `class_HierList.cpp` without adding the missing IDA-confirmed helper functions:

- `0x004ce760` non-deleting destructor body
- `0x004ce7e0` tail/default-sibling insert wrapper
- `0x004ce840` null-sibling insert wrapper
- `0x004ceb00` remove-node helper
- `0x004cec30` recursive find helper

The current generated destructor body also references a delete flag even though the emitted signature lacks that parameter; use the IDA body and scalar deleting wrapper shape before final C++ cleanup.

## Cross-References

- [UID:000065][HierList](by-class/HierList.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
- [UID:0000KS][List](by-file/List.md)
- [UID:0000KL][Layer](by-file/Layer.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:80`.
  - Summary/evidence: standalone tree-list role, `List`/`Layer` relationship, constructor/destructor/helper evidence, migration caveats, and type references are documented; completion is lower because detailed per-method mapping and source-form pseudocode remain light.

- 2026-05-31 exact range split and projected path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the file page listed only the broad aggregate plus three omitted helpers.
  - Changed to: path set to `NexusTK/util/`, scores raised to `82/85`, and migration notes now include the raw wrapper bodies.
  - Summary/evidence: proposed source tree already places `HierList.cpp` under `util/`; IDA MCP verified exact function/wrapper ranges and confirmed `Layer` consumes the container without making it a UI-owned file.
