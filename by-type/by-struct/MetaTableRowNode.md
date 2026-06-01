*** UID:0001V7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MetaTableRowNode

## Status

- Kind: metadata row tree node.
- Owner: [UID:000089][MetaTable](by-class/MetaTable.md) inside [UID:0000LC][MetaMan](by-file/MetaMan.md)
- Confidence: strong for size and major fields; medium for final field names.
- Evidence basis: IDA MCP decompilation of [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md) on 2026-05-25. `wave3.py` was not executed for this pass.

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

- `0x00525850` allocates exactly `0x34` bytes for each node.
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

## Open Questions

- Exact naming and polarity of the red-black color byte.
- Whether the original source used `std::map<SimpleUString, vector<SimpleUString>>`, a local tree wrapper, or a custom container with STL-like layout.
- Whether row values should be named columns, fields, or aliases once the decoded metadata table schema is mapped.

## Cross-References

- [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md)
- [UID:0001CC][0x00524870-0x00524c54.MetaTableMaterializeRows](by-memory/0x00524870-0x00524c54.MetaTableMaterializeRows.md)
- [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)

## Changes

- Before: completion/confidence metadata was unevaluated at `0/0`; `RECONSTRUCTABLE` was blank.
- Changed to: completion `80`, confidence `87`, `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP rechecked the row allocator, initializer, vector-grow helper, row payload destructor, and lookup walk on 2026-05-31. The node size, link fields, key location, value-vector span, and sentinel byte are now directly documented. Scores remain below `95` because final field names, red/black polarity, and original container spelling are still not fully proven.
