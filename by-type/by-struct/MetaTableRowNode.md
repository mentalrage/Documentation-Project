*** UID:0001V7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000089 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000089 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MetaTableRowNode
{
    MetaTableRowNode *left;
    MetaTableRowNode *parent;
    MetaTableRowNode *right;
    unsigned char colorOrRedBlackFlag;
    unsigned char isSentinelOrNil;
    unsigned short paddingOrFlags;
    SimpleUString key;
    SimpleUString *valuesBegin;
    SimpleUString *valuesEnd;
    SimpleUString *valuesCapacity;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MetaTableRowNode

## Status

- Kind: metadata row tree node.
- Owner: [UID:000089][MetaTable](by-class/MetaTable.md) inside [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for size, major fields, and the field names used by [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md); medium for red/black color polarity and broader original container spelling.
- Owner/emitter route: attached to [UID:000089][MetaTable](by-class/MetaTable.md), which clears the strict route gate and emits through [UID:0000LC][MetaMan](by-file/MetaMan.md).
- Evidence basis: IDA MCP decompilation of [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md) on 2026-05-25, live helper-endpoint and sentinel-allocation audit on 2026-06-03, and live row-node layout refresh on 2026-06-14. `wave3.py` was not executed for this pass.

## Purpose

`MetaTableRowNode` stores one decoded metadata row. The row key is a `SimpleUString`, and the row values are stored as a vector of `SimpleUString` elements. B014's accepted materializer pass documents the node as the compiler node value for a `std::map<SimpleUString, std::vector<SimpleUString>>`-style `MetaTable::m_rows` abstraction.

Rows are inserted into a red-black tree owned by `MetaTable`, allowing `MetaMan::FindEntry` and `MetaMan::LoadStatValues` to look up rows by table name plus row key.

## Observed Layout

```text
MetaTableRowNode                         // size 0x34
  +0x00  MetaTableRowNode* left
  +0x04  MetaTableRowNode* parent
  +0x08  MetaTableRowNode* right
  +0x0c  uint8 colorOrRedBlackFlag        // exact polarity pending
  +0x0d  uint8 isSentinelOrNil
  +0x0e  uint16 paddingOrFlags
  +0x10  SimpleUString key                // 0x18 bytes
  +0x28  SimpleUString* valuesBegin
  +0x2c  SimpleUString* valuesEnd
  +0x30  SimpleUString* valuesCapacity
```

## Formal Struct Declaration

The 2026-07-02 Agent-B007 UID0000LC implementation callback promotes this layout into the formal reconstruction block as the first-draft `MetaTableRowNode` declaration. This declaration is source-ready because [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md) already emits helper C++ using `left`, `parent`, `right`, `isSentinelOrNil`, and `key`, while [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md) now uses `valuesBegin` and `valuesEnd` for direct lookup output.

The field names are accepted inferred source-facing names. `colorOrRedBlackFlag` and `paddingOrFlags` intentionally keep final color polarity and old MSVC container spelling open below final-audit level, while the sentinel byte at `+0x0d`, 24-byte `SimpleUString` key at `+0x10`, and values vector triplet at `+0x28/+0x2c/+0x30` are current evidence-backed layout facts.

## Evidence

- `0x00525830` allocates exactly `0x34` bytes for the row-tree header/sentinel node, initializes the first three pointers back to itself, and writes word `0x0101` at `+0x0c`.
- `0x00525850` allocates exactly `0x34` bytes for each normal row node.
- `0x00524d10` initializes the first three dwords from the tree sentinel, clears the flags at `+0x0c`, copies the row key into `+0x10`, and clears the three value-vector pointers at `+0x28`, `+0x2c`, and `+0x30`.
- `0x00524db0` grows the value vector using 24-byte elements, matching the local `SimpleUString` size.
- `0x00525610` destroys the value vector at `+0x28` and then frees/reset the row key string at `+0x10`.
- `0x00524fc0`, `0x00525120`, and `0x00525370` use `+0x0c` / `+0x0d` as the normal red-black tree color/sentinel bytes.

2026-05-31 IDA MCP recheck:

- `0x00525850` allocates `0x34` bytes and initializes the first three dwords from the tree sentinel, confirming node size and link fields.
- `0x00524d10` calls the allocator, clears the flag word at `+0x0c`, copies the row key into `+0x10`, and clears the value-vector pointers at `+0x28`, `+0x2c`, and `+0x30`.
- `0x00524db0` grows/inserts the value vector with a 24-byte stride, matching `SimpleUString` values.
- `0x00525610` destroys the value vector beginning at `+0x28`, frees/resets the key string at `+0x10`, and restores the empty-string state.
- `0x005245c0` walks the tree using the byte at `+0x0d` as the sentinel/nil flag and compares keys at `+0x10`.

2026-06-03 IDA MCP recheck:

- `MetaTable::MetaTable` calls `sub_525830` at `0x00524656` to allocate the tree header/sentinel before clearing payload fields.
- `sub_525830` writes self-links to `+0x00`, `+0x04`, and `+0x08` and sets the flag word at `+0x0c` to `0x0101`; normal node allocation remains at `sub_525850`.
- `sub_5258B0` ends at `0x005258f1`, so the recursive cleanup helper includes the final `retn 4` instruction and the following `0x005258f1-0x00525900` bytes are padding.

2026-06-14 IDA MCP recheck:

- `lookup_funcs` reconfirmed the local row-node helpers: sentinel allocator `0x00525830` size `0x19`, normal allocator `0x00525850` size `0x1d`, initializer `0x00524d10` size `0x91`, value-vector grow/insert helper `0x00524db0` size `0x20e`, row cleanup `0x00525610` size `0x5a`, and lookup helper `0x005245c0` size `0x6a`.
- `analyze_function 0x00525830` decompiles to `operator new(0x34)`, self-links at the first three dwords, and `*((_WORD *)result + 6) = 257`, matching the `+0x0c/+0x0d` flag bytes for the header sentinel.
- `analyze_function 0x00525850` decompiles to `operator new(0x34)` and copies the sentinel pointer into the first three dwords for a normal node allocation.
- `analyze_function 0x00524d10` calls the normal allocator, clears the flag word at `+0x0c`, copies the row key through `sub_525580(*a3)` into `+0x10`, and clears the values vector pointers at `+0x28`, `+0x2c`, and `+0x30`.
- `analyze_function 0x00524db0` uses 24-byte element math for the values vector, and `analyze_function 0x005245c0` walks the tree through the `+0x0d` sentinel byte while comparing keys at node offset `+0x10`.

2026-06-25 B007 lookup-helper sync:

- [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md) now uses the accepted source-facing field names `left`, `parent`, `right`, `isSentinelOrNil`, and `key` in formal first-draft C++.
- The lookup helper confirms the same-type header/sentinel model: the helper starts from `MetaTableRowNode *rowTreeHeader`, reads the root from `rowTreeHeader->parent`, walks `left` and `right`, stops on `isSentinelOrNil`, and compares `key` through `SimpleUStringLessThan`.
- This resolves the lookup-helper field-name blocker for [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md). It does not close the broader red/black color polarity or exact original `std::map`/local-tree/custom-container spelling questions for the whole row-tree helper island.

2026-06-27 B014 materializer implementation:

- [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) appends values through the source-facing `m_rows[rowKey].push_back(valueText)` abstraction.
- The helper-island evidence for that append is the `valuesBegin`, `valuesEnd`, and `valuesCapacity` triplet at `+0x28/+0x2c/+0x30`, with `0x00524db0` using a 24-byte `SimpleUString` stride for vector append/grow.
- The node is therefore documented as the compiler/node value backing the row-map abstraction. Exact red-black color polarity remains a below-95 uncertainty and is not needed for the materializer's first-draft C++.

## Score Rationale

Completion is raised to `88` because the node size, sentinel/normal allocation split, link fields, flag bytes, `SimpleUString` key placement, values vector triplet, value stride, cleanup path, lookup walk, strict owner/emitter route, and formal struct output are all documented with current IDA evidence. Confidence is raised to `90` because the structural evidence is repeatable across allocator, initializer, grow, cleanup, lookup helpers, and the emitted helper dependencies; it remains below final-source confidence because red/black polarity, final STL-vs-local-container spelling, and source-facing row/value names are still open.

## Open Questions

- Exact naming and polarity of the red-black color byte remains open for the broader helper island.
- Exact original spelling of the `std::map<SimpleUString, std::vector<SimpleUString>>`-style row-map member or any local wrapper remains open for final-audit source spelling; for [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md), `m_rows[rowKey].push_back(valueText)` is the accepted source-facing abstraction.
- Whether row values should be named columns, fields, or aliases remains open until the decoded metadata table schema is mapped.
- The lookup-helper field names used by [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md) are no longer open for first-draft C++; they are accepted inferred source-facing names for that exact helper.

## Cross-References

- [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md)
- [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md)
- [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)

## Changes

- 2026-07-02 Agent-B007 UID0000LC implementation callback:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`.
  - Summary/evidence: inserted the formal first-draft `MetaTableRowNode` struct declaration from the accepted empty-emitter family report, preserving `0x34` allocation size, link fields, sentinel flag byte, 24-byte `SimpleUString` key placement, value vector triplet, helper cleanup evidence, emitted [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md) dependency, and the caveat that red/black color polarity and exact original row-container spelling remain final-audit questions.
- 2026-06-14 A002 Goal 2 score refresh:
  - What existed before: `80/87`, with the row-node layout documented but no current strict-gate score rationale.
  - Changed to: `85/89`.
  - Summary/evidence: live IDA MCP reconfirmed helper sizes, `0x34` sentinel and normal node allocations, self-links, `0x0101` sentinel flag word, initializer key copy at `+0x10`, values vector clears at `+0x28/+0x2c/+0x30`, 24-byte values vector stride, cleanup helper callers, lookup helper callers, and tree walk through the `+0x0d` sentinel byte. C++ remained blank at that time because broad final container spelling, red/black polarity, and row-value naming were still provisional.
- 2026-06-25 Agent-B007 lookup-helper sync:
  - Score unchanged.
  - Summary/evidence: recorded that [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md) now uses the accepted inferred field names `left`, `parent`, `right`, `isSentinelOrNil`, and `key` in formal first-draft C++. This closes the target-specific field-name blocker while preserving broader red/black polarity and original row-container spelling as final-audit questions.
- 2026-06-27 Agent-B014 materializer implementation:
  - Score unchanged.
  - Summary/evidence: incorporated the accepted [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md) source-quality pass by documenting this node as the compiler node value for the `m_rows` row-map abstraction and preserving value-vector append evidence through `valuesBegin`, `valuesEnd`, `valuesCapacity`, and the 24-byte `SimpleUString` stride. Exact color polarity remains below-final-audit uncertainty.
- 2026-06-06: Attached the row-node layout to [UID:000089][MetaTable](by-class/MetaTable.md). Scores remain `80/87`; this parent metadata sync follows the documented MetaTable tree ownership and existing 80/80 class gate.
- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank.
- Changed to: completion `80`, confidence `87`, `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP rechecked the row allocator, initializer, vector-grow helper, row payload destructor, and lookup walk on 2026-05-31. The node size, link fields, key location, value-vector span, and sentinel byte are now directly documented. Scores remain below `95` because final field names, red/black polarity, and original container spelling are still not fully proven.
- 2026-06-03: added the separate `0x00525830-0x00525849` tree-header/sentinel allocator and corrected the cleanup-helper endpoint evidence from the live IDA helper-island audit. Scores were not raised in this pass; this page is already above the current low-score threshold and still needs final field names/red-black polarity.
