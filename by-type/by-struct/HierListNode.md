*** UID:0001UQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000065 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000065 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct HierListNode {
    HierListNode *parent;
    HierList *childList;
    unsigned char payload[1];
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HierListNode

## Layer Payload Synchronization - 2026-07-14

Layer uses the established HierListNode header exactly: `parent` at `+0x00`, `childList` at `+0x04`, and caller payload at `+0x08`. Its LayerNode payload is 48 bytes, yielding the constructor-observed 59-byte row allocation/stride after HierList overhead. Layer converts between header and payload by exactly eight bytes and uses `childList` for recursion.

The 48-byte payload fields are Pane pointer `+0x00`, paneFlags `+0x04`, padding through `+0x07`, current/previous RectBounds `+0x08/+0x18`, visible/traversal-block/dirty bytes `+0x28/+0x29/+0x2a`, padding `+0x2b`, and Region pointer `+0x2c`. This is a consumer payload, not a change to the generic HierListNode type or its accepted metadata/formal declaration.

## Status

- Entity kind: support struct
- Confidence: very strong for header fields and payload exposure, strong for treating the three extra stride bytes as trailing reserved/padding bytes.
- Proposed owner: [UID:000065][HierList](by-class/HierList.md), emitted through [UID:0000JV][HierList](by-file/HierList.md)
- Autogen parent: attached to [UID:000065][HierList](by-class/HierList.md); the class scores `86/90` and this node page scores `86/91`.
- Evidence basis: IDA MCP decompilation/disassembly of exact `HierList` methods, especially child-list construction, payload copy, `GetElementAt`, recursive lookup, and hierarchy repair.

## Layout

Each `HierList` row is a fixed-width list element with a hierarchy header followed by caller payload data:

```text
HierListNode
  +0x00  HierListNode* parent
  +0x04  HierList* childList
  +0x08  byte payload[payloadSize]
  ...    3 trailing reserved/padding bytes included in the list stride
```

`HierList::HierList` constructs the base list with `payloadSize + 11`, while insert paths copy `List.elementSize - 11` bytes of caller payload into `node + 0x08`. The first eight bytes are confirmed as hierarchy header. The last three bytes in the stride have no observed semantic load/store evidence and should be documented as trailing reserved/padding bytes, not named as flags.

Source-facing C++ that uses this support type should spell the confirmed fields as `HierListNode *parent`, `HierList *childList`, and `unsigned char payload[1]` or an equivalent flexible-payload representation. The 2026-06-25 B004 pass on [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) specifically reconfirmed `childList` at `+0x04`, payload compare start at `+0x08`, and no target-local semantic use for the trailing three stride bytes.

## Behavior

- Insert-before/insert-after populate `parentNode` and lazily allocate `childList`.
- `GetElementAt` returns `node + 0x08`, hiding the hierarchy header from callers.
- `UpdateHierarchy` rewrites child-list parent pointers after insert/remove/swap.
- Destructors and `RemoveNode` delete nested `childList` objects before removing the node.

## IDA Evidence

- [UID:0002I8][0x004ce730-0x004ce760.HierListConstructor](by-memory/0x004ce730-0x004ce760.HierListConstructor.md) adds `0x0b` to the caller element size before constructing the base list.
- [UID:0002IC][0x004ce860-0x004ce9ad.HierListInsertBefore](by-memory/0x004ce860-0x004ce9ad.HierListInsertBefore.md) and [UID:0002ID][0x004ce9b0-0x004ceafc.HierListInsertAfter](by-memory/0x004ce9b0-0x004ceafc.HierListInsertAfter.md) initialize node `+0x00` and `+0x04`, copy caller payload to `+0x08`, and lazily create child lists.
- [UID:0002IF][0x004ceb50-0x004ceb62.HierListGetElementAt](by-memory/0x004ceb50-0x004ceb62.HierListGetElementAt.md) returns the base node pointer plus `0x08`, proving the header is hidden from callers.
- [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md) calls base `List::GetElementAt` for the raw row pointer, compares caller payload bytes against `node+0x08`, and recurses through the child `HierList*` loaded from `node+0x04`.
- [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md) rewrites child-list owner pointers and child node parent pointers after structural edits.

## Cross-References

- [UID:000065][HierList](by-class/HierList.md)
- [UID:0000JV][HierList](by-file/HierList.md)
- [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)

## Changes

- 2026-07-01 B010 accepted empty-emitter family implementation:
  - Raised this struct to `COMPLETION:90`, `CONFIDENCE:92` and inserted formal source as `struct HierListNode { HierListNode *parent; HierList *childList; unsigned char payload[1]; };` routed through [UID:000065][HierList](by-class/HierList.md).
  - `payload[1]` is a flexible payload marker, not proof of a literal one-byte payload. The binary row stride is `payloadSize + 11`: 8 bytes of header, caller payload bytes, and three trailing reserved/padding bytes.
  - The trailing three bytes remain documented as stride padding/reserved bytes because current constructor, insertion, lookup, accessor, destructor, and hierarchy-update evidence shows no semantic reads or writes to them.

- 2026-06-25 B004 accepted source-quality implementation support update:
  - Added target-specific support for [UID:0002IK][0x004cec30-0x004ced0f.HierListFindNodeByData](by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md): `childList` at `+0x04`, payload compare start at `+0x08`, and no semantic evidence for trailing stride bytes.
  - Recorded source-facing field spellings used by the formal target C++: `parent`, `childList`, and `payload`, with a flexible payload spelling such as `unsigned char payload[1]`.

- 2026-06-17 B001 HierList source-quality support update:
  - Raised to `86/91` after B001 rechecked constructor, insert/remove/search/update, destructor, Layer caller, and node-stride evidence.
  - Standardized `+0x00` as parent node pointer, `+0x04` as child `HierList*`, `+0x08` as caller payload, and the remaining three stride bytes as trailing reserved/padding bytes because no observed method reads or writes them semantically.
  - B010's 2026-07-01 implementation supersedes this former deferral by inserting the formal flexible payload struct while preserving the trailing-byte padding/reserved interpretation.

- 2026-06-06: Attached the node layout to [UID:000065][HierList](by-class/HierList.md). Scores remain `84/90`; this pass only synced parent metadata now that the direct class owner is already above the 80/80 attachment gate.

### 2026-05-31 - Raised from unevaluated after IDA-backed HierList split

- What existed before: the page was scored `0/0` and only summarized the generated layout evidence.
- Changed to: `COMPLETION:84`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: exact IDA-verified HierList child pages now prove constructor stride, payload offset, child-list pointer ownership, recursive lookup, and hierarchy repair behavior. Scores remain below 95 because the final meaning of the extra three stride bytes and exact source-level field names are not yet fully audited.
