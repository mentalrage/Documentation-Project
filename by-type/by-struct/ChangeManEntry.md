*** UID:0001TV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChangeManEntry

## Status

- Kind: sorted-list record
- Owner class: [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- Storage: `ChangeMan::m_changeList`
- Size: `0x10` bytes
- Confidence: strong for field offsets, medium for final field names.
- Reconstructable: yes, as source-level sorted-list record layout. Do not emit final C++ until the `ChangeMan` header and listener/message interface names are proven.

## Layout

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `owner` | Sort key and first field compared by the `0x0047ef20` comparator. Dispatch scans same-owner records. |
| `0x04` | `listener` | Dispatch calls virtual slot `+0x08` on this object with `(owner, message)`. Unregister paths can remove by this pointer. |
| `0x08` | `scope` | Byte-tested. `1` means all messages for the owner; `0` means only `messageType` matches dispatch. |
| `0x0c` | `messageType` | Compared against `Message::m_type` at message offset `+4` when `scope == 0`. |

## Notes

`ChangeMan` stores these records in a [UID:0000DF][SortedList](by-class/SortedList.md) constructed with element size `0x10`, comparator `0x0047ef20`, and initial capacity `100`. The comparator only orders by `owner`, so entries with the same owner are contiguous and dispatch can scan forward from the lower-bound index.

The exact [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md) show this layout being built on the stack before insert and later filtered by owner/listener/scope/message.

2026-05-31 IDA MCP recheck:

- Decompilation of `0x0047ed50` builds a stack record with `Src[0] = owner`, `Src[1] = listener`, byte `v8 = scope`, and `v9 = messageType`, then inserts it into `this[1]`.
- Decompilation of `0x0047ee20` lower-bounds by owner, iterates records while `record[0] == owner`, tests byte `record + 8`, compares dword `record + 12` with `Message + 4` when scope is `0`, and calls virtual slot `+0x08` on the listener pointer at `record + 4`.
- Raw IDA disassembly of comparator `0x0047ef20` compares only the first dword of each record, confirming `owner` is the sorted key.

## Open Questions

- Final field names depend on naming the listener interface and message type field in [UID:000084][Message](by-class/Message.md).
- Scope semantics are known from dispatch behavior but the original symbolic values are not yet proven.

## Cross-References

- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md)
- [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md)
- [UID:000084][Message](by-class/Message.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)

## Changes

- What existed before: the page described the record but remained scored unevaluated and did not state reconstruction status.
- What changed: the page is marked reconstructable and now includes live IDA MCP evidence for registration, dispatch, and comparator behavior.
- Summary/evidence: IDA MCP rechecked `0x0047ed50`, `0x0047ee20`, and raw comparator `0x0047ef20`.
