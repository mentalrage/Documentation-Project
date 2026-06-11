*** UID:0001V7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:000089 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MetaTableRowNode

## Status

- Kind: metadata row tree node.
- Owner: [UID:000089][MetaTable](by-class/MetaTable.md) inside [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for size and major fields; medium for final field names.
- Autogen parent: attached to [UID:000089][MetaTable](by-class/MetaTable.md); the class scores `84/80` and this node page scores `80/87`, so both sides satisfy the 80/80 parent gate.
- Evidence basis: IDA MCP decompilation of [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md) on 2026-05-25 plus live helper-endpoint and sentinel-allocation audit on 2026-06-03. `wave3.py` was not executed for this pass.

## Purpose

`MetaTableRowNode` stores one decoded metadata row. The row key is a `SimpleUString`, and the row values are stored as a vector of `SimpleUString` elements.

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

## Open Questions

- Exact naming and polarity of the red-black color byte.
- Whether the original source used `std::map<SimpleUString, vector<SimpleUString>>`, a local tree wrapper, or a custom container with STL-like layout.
- Whether row values should be named columns, fields, or aliases once the decoded metadata table schema is mapped.

## Cross-References

- [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md)
- [UID:0001CC][0x00524870-0x00524c55.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c55.MetaTableMaterializeRows.md)
- [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)

## Changes

- 2026-06-06: Attached the row-node layout to [UID:000089][MetaTable](by-class/MetaTable.md). Scores remain `80/87`; this parent metadata sync follows the documented MetaTable tree ownership and existing 80/80 class gate.
- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank.
- Changed to: completion `80`, confidence `87`, `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP rechecked the row allocator, initializer, vector-grow helper, row payload destructor, and lookup walk on 2026-05-31. The node size, link fields, key location, value-vector span, and sentinel byte are now directly documented. Scores remain below `95` because final field names, red/black polarity, and original container spelling are still not fully proven.
- 2026-06-03: added the separate `0x00525830-0x00525849` tree-header/sentinel allocator and corrected the cleanup-helper endpoint evidence from the live IDA helper-island audit. Scores were not raised in this pass; this page is already above the current low-score threshold and still needs final field names/red-black polarity.
