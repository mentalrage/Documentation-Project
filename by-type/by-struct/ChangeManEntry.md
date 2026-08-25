*** UID:0001TV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00001K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00001K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct ChangeManEntry {
    LObject *owner;
    LObject *listener;
    bool allMessages;
    MessageType messageType;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChangeManEntry

## Status

- Kind: sorted-list record
- Owner class: [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- Parent attachment: attached to [UID:00001K][ChangeMan](by-class/ChangeMan.md), which now clears the strict route gate at `85/89` and emits through [UID:0000I2][ChangeMan](by-file/ChangeMan.md).
- Storage: `ChangeMan::m_changeList`
- Size: `0x10` bytes
- Confidence: strong for field offsets, concrete project types, boolean semantics, natural padding, and full-family use.
- Reconstructable: yes, as the source-level sorted-list record layout. The formal block uses the established `LObject` callback base, project `MessageType`, ordinary `bool`, and compiler-supplied x86 padding.

## Layout

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x00` | `LObject *owner` | Sort key and first field compared by the `0x0047ef20` comparator. Dispatch scans same-owner records. |
| `0x04` | `LObject *listener` | Dispatch calls the common primary-vtable `OnChangeMessage(owner, message)` slot. Unregister paths can remove by this pointer. |
| `0x08` | `bool allMessages` | One-byte load/store. Exact `true` means all messages for the owner; exact `false` requires `messageType`; invalid byte values other than 0/1 match neither explicit branch. |
| `0x09..0x0b` | natural padding | Unwritten by registration and required by ordinary x86 alignment of the following `MessageType`; not a source member. |
| `0x0c` | `MessageType messageType` | Compared against `Message::m_type` at message offset `+4` when `allMessages == false`. |

## Notes

`ChangeMan` stores these records in a [UID:0000DF][SortedList](by-class/SortedList.md) constructed with element size `0x10`, comparator `0x0047ef20`, and initial capacity `100`. The comparator only orders by `owner`, so entries with the same owner are contiguous and dispatch/unregister can scan forward from the first equal-owner index.

The exact [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md) show this layout being built on the stack before insert and later filtered by owner/listener/all-messages/message type.

## 2026-07-13 B003 UID0000ZW Type Resolution

- The record is exactly 16 bytes. UID0000ZW stores the two pointers, one byte, and one dword at `+0x00/+0x04/+0x08/+0x0c`; its three intervening bytes are not written. ChangeMan constructs the backing SortedList with element size `0x10`, so no field or tail is omitted.
- `owner` and `listener` are both `LObject *`. The dispatch path invokes primary vtable slot `+0x08` on `listener`, the base [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) occupies that slot, and confirmed derived overrides consume `(LObject *, Message *)`. There is no separate interface pointer adjustment or secondary vtable.
- `allMessages` is an ordinary source `bool`. Registration writes only its low byte; unregister and dispatch compare exact false/true states. Invalid non-boolean bytes remain negative evidence: they match neither explicit branch, but that compiler-level observation does not justify inventing a source enum.
- `MessageType` is the established 32-bit project message-tag type. It aligns naturally to `+0x0c`, giving three compiler-provided bytes at `+0x09..+0x0b`. An explicit `padding[3]` member would expose machine layout as source scaffolding and is rejected.
- Historical `ChangeListener`, `ChangeMessageScope`, `unsigned char scope`, and explicit-padding drafts below are retained only as superseded provenance from earlier passes. They are not current declarations or open blockers.

2026-05-31 IDA MCP recheck:

- Decompilation of `0x0047ed50` builds a stack record with `Src[0] = owner`, `Src[1] = listener`, byte `v8 = scope`, and `v9 = messageType`, then inserts it into `this[1]`.
- Decompilation of `0x0047ee20` lower-bounds by owner, iterates records while `record[0] == owner`, tests byte `record + 8`, compares dword `record + 12` with `Message + 4` when scope is `0`, and calls virtual slot `+0x08` on the listener pointer at `record + 4`.
- Raw IDA disassembly of comparator `0x0047ef20` compares only the first dword of each record, confirming `owner` is the sorted key.

Historical 2026-06-16 C001 live IDA refresh, superseded for source-facing names and types by the 2026-07-13 B003 synchronization above:

- `lookup_funcs` reported `0x0047ed50-0x0047ed80`, `0x0047ed80-0x0047ee18`, `0x0047ee20-0x0047ee95`, and `0x0047ef20-0x0047ef3f` with the documented sizes; `xrefs_to` still shows one Application wrapper caller for each register/unregister/dispatch method and one constructor data reference to the comparator.
- Decompilation again shows the register stack stores at offsets `+0x00/+0x04/+0x08/+0x0c`, filtered unregister wildcard behavior, dispatch callback through listener slot `+0x08`, and comparator ordering solely by `owner`.
- Safe IDA names were applied and saved for `ChangeMan_Register`, `ChangeMan_UnregisterFiltered`, `ChangeMan_DispatchMessage`, `CompareChangeEntries`, the surrounding ChangeMan lifecycle helpers, Application forwarding wrappers, and `g_pChangeMan`; at that historical stage no struct/member type was written because the listener interface and final `scope` enum spelling were still treated as provisional.

Historical 2026-06-16 B002 source-quality recheck, retained as pre-resolution evidence:

- The field layout stays unchanged, but the scope-byte semantics are now documented more tightly: exact `1` is the wildcard/all-messages path, exact `0` is the message-type-filtered path using [UID:000084][Message](by-class/Message.md) `m_type` at `+0x04`, and other nonzero scope values do not match either dispatch branch.
- At that historical stage, the descriptive enum candidates were `ChangeMessageScope_MatchType = 0` and `ChangeMessageScope_AllTypes = 1`. The complete 2026-07-13 family/caller proof supersedes those candidates with ordinary source `bool allMessages`; the old names are not current declarations.

## Historical 2026-06-19 B010 Implementation Source-Quality Sync

The accepted 2026-06-19 B010 ChangeMan implementation pass kept the formal struct C++ blank but made the first-draft declaration shape ready for use by method pages; B009 later promoted that shape into the formal block:

```cpp
enum ChangeMessageScope {
    ChangeMessageScope_MatchType = 0,
    ChangeMessageScope_AllTypes = 1
};

struct ChangeManEntry {
    void *owner;                 // +0x00
    ChangeListener *listener;    // +0x04
    unsigned char scope;         // +0x08
    unsigned char padding[3];    // +0x09
    unsigned int messageType;    // +0x0c
};
```

`ChangeMessageScope` and `ChangeListener` are descriptive source-facing names, not recovered original spellings. The size remains `0x10` / 16 bytes, and [UID:000101][0x0047ef20-0x0047ef3f.CompareChangeEntries](by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md) compares only `owner`.

## Historical 2026-07-01 B009 Empty-Emitter Implementation

B009's accepted empty-emitter report promoted the declaration shape above into the formal `RECONSTRUCTION_CPP CODE` block and raised the score to `88/91`. The explicit `padding[3]` keeps `messageType` at offset `+0x0c` and preserves the exact `0x10` / 16-byte record size. The scope field remains `unsigned char` because live dispatch/unregister evidence treats exact byte value `1` as all messages, exact byte value `0` as message-type match, and other nonzero values as nonmatching. The enum and listener names remain descriptive source-facing names, not recovered original spellings.

## Score Rationale

Completion is `92` because the complete 16-byte size, all four semantic fields, natural padding, owner-only sort key, boolean wildcard behavior, `MessageType` comparison, common LObject callback, stack construction, wrapper reachability, and parent route are documented and emitted in source-faithful form. Confidence is `94`; exact original private field spellings remain inferred, but no type, size, alignment, or behavior blocker remains.

## Open Questions

- Exact original private field spellings are not symbol-recovered; the selected names are the narrowest source-facing descriptions supported by all family users.
- Invalid values outside the C++ `bool` domain are documented as binary negative evidence and intentionally do not produce a source enum or validation branch.

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

- 2026-06-06: Completion/confidence changed from `78/88` to `82/90`, and `AUTOGEN_PARENT_UID` was set to [UID:00001K][ChangeMan](by-class/ChangeMan.md).
  - Before: field evidence was documented, but the metadata stayed below the parent-child attachment gate and the manual by-struct coverage row still showed a stale `50%`.
  - After: the page records the parent gate, score rationale, and coverage report sync.
  - Evidence: registration builds the stack record at `0x0047ed50`, dispatch reads offsets `+0x00/+0x04/+0x08/+0x0c` at `0x0047ee20`, and comparator `0x0047ef20` proves `owner` is the sorted key.
- 2026-06-16 C001: Completion changed from `82` to `85`.
  - Evidence: live IDA reconfirmed exact register/unregister/dispatch/comparator boundaries and xrefs, the four record offsets, same-owner scan behavior, wildcard filtering, listener callback slot, and owner-only comparator. The direct class parent now clears `85/85`, and safe IDA names were saved for the documented ChangeMan methods, wrappers, comparator, and singleton global.
- 2026-06-16 B002 source-quality recheck:
  - Scores unchanged.
  - Evidence: clarified exact `scope` behavior and documented best descriptive enum names while keeping final enum spelling provisional.
- 2026-06-19 B010 implementation sync:
  - Scores unchanged.
  - Evidence: synchronized accepted first-draft declaration shape, exact field offsets, 16-byte size, source-facing enum caveat, and owner-only comparator behavior used by the ChangeMan method pages.
- 2026-07-01 B009 empty-emitter implementation:
  - Changed score from `85/90` to `88/91`.
  - Evidence: populated formal `ChangeMessageScope` and `ChangeManEntry` declaration with explicit padding, preserving byte-scope semantics and the `0x10` / 16-byte record.
- 2026-07-13 B003 UID0000ZW implementation:
  - Changed score from `88/91` to `92/94` and replaced the superseded interface/enum/explicit-padding draft with `LObject *`, `bool allMessages`, `MessageType`, and natural padding.
  - Evidence: complete ChangeMan register/unregister/dispatch family, LObject primary-vtable slot `+0x08`, confirmed overrides, exact one-byte stores/tests, 16-byte list element size, and absence of any source-visible padding write.
