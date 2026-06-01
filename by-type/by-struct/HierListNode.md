*** UID:0001UQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HierListNode

## Status

- Entity kind: support struct
- Confidence: strong for header fields and payload exposure, medium-high for the three extra stride bytes.
- Proposed owner: [UID:0000JV][HierList](by-file/HierList.md)
- Evidence basis: IDA MCP decompilation/disassembly of exact `HierList` methods, especially child-list construction, payload copy, `GetElementAt`, recursive lookup, and hierarchy repair.

## Layout

Each `HierList` row is a fixed-width list element with a hierarchy header followed by caller payload data:

```text
HierListNode
  +0x00  void* parentNode
  +0x04  HierList* childList
  +0x08  byte payload[payloadSize]
  ...    3 unresolved bytes included in the list stride
```

`HierList::HierList` constructs the base list with `elementSize + 11`, while insert paths copy `List.elementSize - 11` bytes of caller payload into `node + 0x08`. The first eight bytes are confirmed as hierarchy header. The last three bytes in the stride are not fully named yet; treat them as unresolved padding or flags until a caller proves their use.

## Behavior

- Insert-before/insert-after populate `parentNode` and lazily allocate `childList`.
- `GetElementAt` returns `node + 0x08`, hiding the hierarchy header from callers.
- `UpdateHierarchy` rewrites child-list parent pointers after insert/remove/swap.
- Destructors and `RemoveNode` delete nested `childList` objects before removing the node.

## IDA Evidence

- [UID:0002I8][0x004ce730-0x004ce760.HierListConstructor](by-memory/0x004ce730-0x004ce760.HierListConstructor.md) adds `0x0b` to the caller element size before constructing the base list.
- [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) and [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) initialize node `+0x00` and `+0x04`, copy caller payload to `+0x08`, and lazily create child lists.
- [UID:0002IF][0x004ceb50-0x004ceb62.HierListGetElementAt](by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md) returns the base node pointer plus `0x08`, proving the header is hidden from callers.
- [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md) rewrites child-list owner pointers and child node parent pointers after structural edits.

## Cross-References

- [UID:000065][HierList](by-class/HierList.md)
- [UID:0000JV][HierList](by-file/HierList.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)

## Changes

### 2026-05-31 - Raised from unevaluated after IDA-backed HierList split

- What existed before: the page was scored `0/0` and only summarized the generated layout evidence.
- Changed to: `COMPLETION:84`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: exact IDA-verified HierList child pages now prove constructor stride, payload offset, child-list pointer ownership, recursive lookup, and hierarchy repair behavior. Scores remain below 95 because the final meaning of the extra three stride bytes and exact source-level field names are not yet fully audited.
