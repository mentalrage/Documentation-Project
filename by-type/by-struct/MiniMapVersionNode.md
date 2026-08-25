*** UID:0001V8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MiniMapVersionManager.h"

struct MiniMapVersionNode
{
    MiniMapVersionNode *next;
    MiniMapVersionNode *prev;
    int mapId;
    wchar_t *expectedVersionString;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MiniMapVersionNode

## Status

- Entity kind: support struct
- Confidence: very strong for exact 16-byte layout, field roles, payload lifetime, lookup behavior, semantic owner, and file-scope placement; high for inferred source spellings.
- Direct owner: [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- Proposed header/module: [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md), likely `map/MiniMapVersionManager.h`
- Evidence basis: IDA MCP decompilation/disassembly of [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md), [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md), [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md), and [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md). `simroot_v2` may be used only as a lead.
- Ownership/emission split: semantic owner remains [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), while direct emitter [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md) places this file-scope declaration at position `5`, before the class at position `10`.

## Layout Hypothesis

```cpp
struct MiniMapVersionNode
{
    MiniMapVersionNode *next;          // +0x00
    MiniMapVersionNode *prev;          // +0x04
    int mapId;                         // +0x08, renderer map id / hash-list key
    wchar_t *expectedVersionString;    // +0x0c, points to a 33-wchar_t buffer
};
```

The struct is a typed payload overlay on [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md). `UpdateHashList` creates nodes from slash-delimited `mapId,value` entries, allocates `0x42` bytes for the wide value string, copies up to 33 `wchar_t` characters, packages `{ mapId, expectedVersionString }`, and inserts the node through `DATIndexVector::InsertNode`.

`0x42` is 66 decimal bytes and `0x21` is 33 decimal wide-character slots (Verified with `int_convert.py`). The copy bound therefore matches the renderer-side `.mnm` header/version field size used by the lookup consumers.

## Size, Scope, And Emitter Decision

- The structure is exactly four 32-bit words and therefore `0x10` bytes on the target x86 ABI: `next` at `+0x00`, `prev` at `+0x04`, `mapId` at `+0x08`, and `expectedVersionString` at `+0x0c`.
- `expectedVersionString` is a pointer. Its separately allocated payload is `0x42` bytes (`33 * sizeof(wchar_t)`); that payload is not inline structure storage.
- Current method usage is unqualified and the type has an independent project page. The highest-probability source shape is a file-scope support struct in `MiniMapVersionManager.h`, not a nested class declaration.
- Direct emission through UID0000LF is an ordering decision, not a semantic ownership change. UID00008H remains canonical owner because the manager exclusively creates, indexes, looks up, updates, and destroys these nodes.
- Emitting through the class would place the independent declaration inside `class MiniMapVersionManager` when children expand, changing type qualification and source shape. Position `5` followed by class position `10` avoids that invalid nesting and duplicates neither type nor storage.

## IDA Verification Notes

- [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md) parses slash-delimited entries, splits each token at the comma, parses the left-side map id, allocates a 66-byte wide buffer for new right-side expected-version text, and passes two payload dwords `{ mapId, expectedVersionString }` to [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md).
- `0x004570e0` creates a linked-list node and stores `payload[0]` at node offset `+0x08` and `payload[1]` at node offset `+0x0c`.
- Existing-node update in `0x00456a90` writes the new text through `node[3]`, proving offset `+0x0c` is the `wchar_t*` value buffer.
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) calls [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) on the manager's embedded index at `this + 0x48`, compares against the list sentinel at `this + 0x4c`, and returns `expectedVersionString` at `node + 0x0c` when found.
- 2026-06-11 live IDA MCP recheck confirmed the same key instructions: existing-node update pushes `21h` and `dword ptr [esi+0Ch]` into `_wcscpy_s`; the new-node path pushes `42h`, copies with `21h`, stores the parsed key and allocated text pointer in adjacent stack payload dwords, calls `0x004570e0`, increments manager `+0x50`, and inserts through the embedded index at `+0x48`.
- 2026-06-11 live IDA MCP recheck also confirmed `MiniMapVersionManager::~MiniMapVersionManager` frees `dword ptr [esi+0Ch]` before freeing the list node, closing the payload lifetime for `expectedVersionString`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | Exact field offsets/size, payload source and allocation size, update path, lookup return, destructor cleanup, DATIndexVector overlay relationship, semantic owner, file-scope source shape, direct file emitter, source order, formal declaration, and duplicate/nesting rejection are documented. |
| Confidence | 93 | Direct creation, copy, insertion, lookup, return, and cleanup instructions prove the four-word layout and lifetime. The type/field spellings and exact historical header filename remain high-probability source inferences, keeping the page below 95. |

## Consumers

- `MiniMapVersionManager::UpdateHashList` creates or updates nodes.
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) returns `expectedVersionString` for renderer version checks.
- `MiniMapVersionManager::~MiniMapVersionManager` frees each node's `expectedVersionString` before destroying list/index state.

## Open Questions

- Original symbols do not survive for the type or fields. `MiniMapVersionNode`, `mapId`, and `expectedVersionString` are the highest-probability human names from current manager/renderer conventions and behavior; they are not PDB-authenticated spellings.
- Exact historical header filename remains inferred. Current reconstruction uses focused `NexusTK/map/MiniMapVersionManager.h`; no unresolved question blocks the accepted file-scope declaration or emitter route.

## Historical Assumptions Superseded

- Earlier revisions left formal C++ blank because exact header declaration style and shared container API spelling were provisional. Those uncertainties do not affect the exact four-word support declaration and are now bounded by below-95 confidence.
- Earlier emitter UID00008H represented semantic class ownership but would become source nesting once the class emits children. The semantic ownership evidence is preserved; only the emitter route changes to UID0000LF to retain the proven file-scope shape.

## Cross-References

- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0001U1][DATIndexVectorNode](by-type/by-struct/DATIndexVectorNode.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md)

## Changes

- 2026-08-17 B007 UID0000PA include-order closure:
  - Prepended `#include "MiniMapVersionManager.h"` to the position-`5` CPP payload, then preserved the exact source-local `0x10` node declaration unchanged.
  - The node intentionally remains outside the public manager header because no external declaration or consumer needs it. Position `5` places the provider include and file-local support type before the manager's position-`10` method children without nesting the node inside the class.

- 2026-07-23 B002 UID0001OZ accepted implementation callback raised the page from `85/90` to `90/93`, retained canonical owner UID00008H, changed emitter to focused file UID0000LF, set source position `5`, installed the exact 16-byte file-scope struct, documented payload allocation versus inline size, and historicalized the former blank-C++/class-emitter assumptions.

- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank; evidence basis still mentioned generated `simroot_v2` directly.
- Changed to: completion `76`, confidence `88`, `RECONSTRUCTABLE:TRUE`; evidence basis now records current IDA MCP checks and treats generated output only as a lead.
- Summary/evidence: IDA MCP verification of `0x00456a90`, `0x004570b0`, `0x004570e0`, and `0x00457580` proves the node payload slots, map-key lookup, update path, and version-text pointer behavior. Scores remain below `95` because final semantic names and the original class/header declaration are not exhaustively audited.
- 2026-06-11 Agent-A005 Batch 152:
  - Before: `COMPLETION:76`, `CONFIDENCE:88`, and no autogen parent because the page had payload evidence but still lacked written owner, lifetime, and parent-gate detail.
  - After: `COMPLETION:85`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:00008H`.
  - Summary/evidence: live IDA MCP rechecked existing-node copy through `+0x0c`, new-node allocation/copy/payload packaging, `StdListBuyNodeWithPayload8` writes to `+0x08/+0x0c`, lookup return from `node+0x0c`, destructor free of `node+0x0c`, and shared `DATIndexVectorFindNodeByKey` caller spread. `int_convert.py` verified `0x21 == 33` and `0x42 == 66`. Final C++ remains blank below the 95/95 gate.
- 2026-06-17 B002 source-quality execution:
  - Score unchanged at `85/90`.
  - Renamed the preferred descriptive fields from `hashKey`/`versionText` to `mapId`/`expectedVersionString` after B002 rechecked renderer callers: the key comes from `MiniMapRenderer +0x25c`, and the returned value is compared against the 33-wide-character `.mnm` header/version field.
