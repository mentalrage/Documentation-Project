*** UID:00004K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ErrorMessage

## Status

- Confidence: strong for vtable/helper behavior; medium-high for the raw constructor boundary.
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x006193b8`, vtable `0x006193bc`
- Evidence basis: live IDA MCP disassembly/decompilation checks on 2026-06-05.

## Responsibility

`ErrorMessage` appears to be a small display/name wrapper in the error hierarchy. It supplies an error-name virtual and a destructor path.

The stronger current interpretation is that this is the inline-wide-message wrapper family member in [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md): vtable at `0x006193bc`, inline wide message storage at byte offset `+0x04`, copy slot [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md), scalar deleting destructor at `0x004a6920`, and shared name/descriptor slot `0x004a6a70`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a63e0` | `ErrorMessage` | Raw constructor-shaped bytes; IDA does not model a function at this address. |
| [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) | cleanup helper | IDA-confirmed helper that resets the base `Error` vtable and calls base cleanup. |
| [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) | copy helper | IDA-confirmed vtable slot helper that copies the stored wide message from `this + 4`. |
| `0x004a6920` | `ScalarDeletingDestructor` | Resets to base error vtable and tears down `LObject`. |
| `0x004a6a70` | `GetErrorName` | Returns the base display name string. |

## Ownership Notes

Do not use the projected constructor as a rename anchor. The destructor/name helper still belongs in the shared error module.

- Live IDA reports no function record at `0x004a63e0`, no xrefs to that raw start, and no little-endian pointer-byte matches for `e0 63 4a 00`.
- Direct disassembly covers `0x004a63e0-0x004a63fc`: the raw constructor calls shared base setup `sub_4F4A80` at `0x004a63ea`, installs `??_7ErrorMessage@@6B@` at `0x004a63ef`, returns with `retn`, and is followed by `0xcc` padding through `0x004a6400`.
- Live IDA reports `sub_4A6400` as a real `0x0b`-byte helper at `0x004a6400-0x004a640b`; decompilation writes the base `Error` vtable and calls `sub_4F4A90`. IDA reports no direct xrefs to this helper.
- Live IDA reports `sub_4A6410` as a real `0x19`-byte helper at `0x004a6410-0x004a6429`, referenced from vtable slot `0x006193c8`. Decompilation copies with `wcscpy_s(destination, size, this + 2)`, which is byte offset `+0x04` because IDA types `this` as `wchar_t *`.
- Live IDA reports `sub_4A6920` as a real `0x41`-byte scalar deleting destructor at `0x004a6920-0x004a6961`, referenced from vtable slot `0x006193bc`; it writes the base `Error` vtable, calls `sub_4F4A90`, and conditionally frees the object via `sub_4F4AC0` based on the deleting flags.
- Live vtable data confirms RTTI at `0x006193b8`, destructor slot `0x006193bc -> sub_4A6920`, shared base slot `0x006193c0 -> sub_4F4B10`, no-op slot `0x006193c4 -> nullsub_18`, copy slot `0x006193c8 -> sub_4A6410`, and name/descriptor slot `0x006193cc -> sub_4A6A70`.
- The constructor vtable-store xref is `0x004a63ef -> 0x006193bc`; `sub_4A6A70` returns `L"Error"` and is shared by the error-family descriptor slots.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable hierarchy metadata, but leave C++ blank. The class belongs in `util/Error.cpp`, yet the constructor start is still raw/projected and the final class declaration/member spelling is not final C++ quality.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `82` | The page records the class role, likely source owner, raw-constructor caveat, vtable slot map, inline-message layout, live copy/cleanup/destructor helper behavior, constructor-store xref, and no-code autogen handling. Completion remains capped because the constructor is not an IDA-modeled function and final declaration details are unresolved. |
| Confidence `86` | The ownership, vtable slots, copy offset, destructor behavior, and helper ranges are now live-IDA supported. Confidence is not higher because `0x004a63e0` remains a raw constructor-shaped start without an IDA function record or caller/xref proof, and the final original class/member names are not settled. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0002ND][0x00619344-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619344-0x00619448.ErrorHierarchyVtableData.md)

## Changes

- 2026-06-05:
  - Before: scored `72/82`, with stale external-source wording and only a high-level raw-constructor/helper summary.
  - After: scored `82/86`, removed stale source references, and kept reconstruction C++ blank.
  - Why: live IDA evidence now records the raw constructor bytes, lack of constructor function/xrefs/pointer matches, real cleanup/copy/destructor helper ranges, copy-from-`+0x04` behavior, destructor deleting-flag behavior, exact vtable slots, `0x004a63ef` constructor vtable-store xref, and shared `L"Error"` descriptor helper. The score remains below final-source quality because the constructor is still not an IDA-modeled function and original class/member naming remains unresolved.
- 2026-06-02:
  - Before: scored `64/70`, reconstructability and parent blank.
  - After: scored `72/82`, marked reconstructable, and attached to [UID:0000J5][Error](by-file/Error.md) with C++ blank.
  - Why: the shared Error file, vtable, layout, and exact vtable-data pages now provide strong evidence for `util/Error.cpp` ownership and inline-message behavior, while the constructor remains a raw projected start.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/70`.
  - Summary/evidence: display-message wrapper role, projected constructor caveat, cleanup/copy helpers, destructor/name helper, and missing helper evidence are documented; confidence remains limited because the constructor is still not an IDA-modeled function.
