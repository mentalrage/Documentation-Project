*** UID:0001V8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapVersionNode

## Status

- Entity kind: support struct
- Confidence: strong for observed fields, medium for final name/header visibility.
- Proposed owner: [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- Proposed header/module: [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md), likely `map/MiniMapVersionManager.h`
- Evidence basis: IDA MCP decompilation/disassembly of [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md), [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md), [UID:0000XR][0x004570e0-0x004570ff.CreateListNodeWithPayload](by-memory/0x004570e0-0x004570ff.CreateListNodeWithPayload.md), and [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md). `simroot_v2` may be used only as a lead.

## Layout Hypothesis

```cpp
struct MiniMapVersionNode {
    MiniMapVersionNode* next; // +0x00
    MiniMapVersionNode* prev; // +0x04
    int hashKey;              // +0x08, map id / hash-list key
    wchar_t* versionText;     // +0x0c, 33 wchar_t buffer
};
```

The struct is a typed payload overlay on [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md). `UpdateHashList` creates nodes from slash-delimited `key,value` entries, allocates `0x42` bytes for the wide value string, copies up to 33 `wchar_t` characters, packages `{ key, versionText }`, and inserts the node through `DATIndexVector::InsertNode`.

## IDA Verification Notes

- [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md) parses slash-delimited entries, splits each token at the comma, parses the left-side key, allocates a 66-byte wide buffer for new right-side text, and passes two payload dwords `{ key, versionText }` to [UID:0000XR][0x004570e0-0x004570ff.CreateListNodeWithPayload](by-memory/0x004570e0-0x004570ff.CreateListNodeWithPayload.md).
- `0x004570e0` creates a linked-list node and stores `payload[0]` at node offset `+0x08` and `payload[1]` at node offset `+0x0c`.
- Existing-node update in `0x00456a90` writes the new text through `node[3]`, proving offset `+0x0c` is the `wchar_t*` value buffer.
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) calls [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) on the manager's embedded index at `this + 0x48`, compares against the list sentinel at `this + 0x4c`, and returns `*(node + 0x0c)` when found.

## Consumers

- `MiniMapVersionManager::UpdateHashList` creates or updates nodes.
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) returns `versionText` for renderer version checks.
- `MiniMapVersionManager::~MiniMapVersionManager` frees each node's `versionText` before destroying list/index state.

## Open Questions

- Whether `hashKey` should be named `mapId`, `hashKey`, or `miniMapId`.
- Whether `versionText` is a hash string, a version token, or an S3/cache path component. The two renderer callers compare it against the 33-wide-character `.mnm` header field, so `versionText` is the safest current name.

## Cross-References

- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md)

## Changes

- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank; evidence basis still mentioned generated `simroot_v2` directly.
- Changed to: completion `76`, confidence `88`, `RECONSTRUCTABLE:TRUE`; evidence basis now records current IDA MCP checks and treats generated output only as a lead.
- Summary/evidence: IDA MCP verification of `0x00456a90`, `0x004570b0`, `0x004570e0`, and `0x00457580` proves the node payload slots, map-key lookup, update path, and version-text pointer behavior. Scores remain below `95` because final semantic names and the original class/header declaration are not exhaustively audited.
