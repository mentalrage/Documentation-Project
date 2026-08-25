*** UID:00004K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ErrorMessage class-level source is covered by [UID:0000J5][Error](by-file/Error.md) and exact message-copy child [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md); the raw constructor-shaped start at 0x004a63e0 has no current IDA function or xref route, so this class page emits no standalone declaration/body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ErrorMessage

## Status

- Confidence: strong for vtable/helper behavior; medium-high for the raw constructor boundary.
- Likely source module: [UID:0000J5][Error](by-file/Error.md)
- Current range: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- Vtable anchor: RTTI `0x006193b8`, vtable `0x006193bc`
- Evidence basis: live IDA MCP disassembly/decompilation checks through the 2026-06-23 B002 source-quality implementation on session `b880584f`, refreshed by B009's 2026-06-29 implementation on session `B006_0002F1_20260629`.

## Responsibility

`ErrorMessage` appears to be a small display/name wrapper in the error hierarchy. It supplies an error-name virtual and a destructor path.

The stronger current interpretation is that this is the inline-wide-message wrapper family member in [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md): vtable at `0x006193bc`, inline wide message storage at byte offset `+0x04`, copy slot [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md), scalar deleting destructor at `0x004a6920`, and shared name/descriptor slot `0x004a6a70`.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004a63e0` | `ErrorMessage` | Raw constructor-shaped bytes; IDA does not model a function at this address. |
| [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) | cleanup helper | IDA-confirmed helper that resets the base `Error` vtable and calls base cleanup. |
| [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) | `FormatErrorMessage` | Source-ready vtable `+0x0c` slot method: `int ErrorMessage::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` copies the stored wide message from byte offset `+0x04` and returns `wcscpy_s(destination, destinationChars, m_message)`. Original hierarchy-wide declaration spelling remains inferred. |
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
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` reconfirms `0x004a63e0` as `Not a function`, cleanup helper `sub_4A6400` size `0xb`, copy helper `sub_4A6410` size `0x19`, scalar deleting destructor `sub_4A6920` size `0x41`, and shared name helper `sub_4A6A70` size `0x6`.
- Current xrefs still show no references to raw constructor start `0x004a63e0`; the copy helper remains vtable-data referenced at `0x006193c8`, the destructor remains referenced at `0x006193bc`, and the raw constructor vtable store remains `0x004a63ef -> 0x006193bc`.
- `analyze_component` over the cleanup/copy/destructor/name helpers reports stable sizes and shared base `Error` vtable `0x00619344` accessed by `sub_4A6400` and `sub_4A6920`. `make_signature_for_range(0x004a63e0,0x004a6429)` returns a unique wildcarded signature for the raw constructor plus helper span.
- 2026-06-23 B002 MCP source-quality implementation on session `b880584f` reconfirmed the current IDB identity (`NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays ready), `lookup_funcs 0x004a6410 -> sub_4A6410 size 0x19`, and `lookup_funcs 0x004a6429 -> Not a function`. `get_bytes` for [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) returns `55 8b ec 8d 41 04 50 ff 75 0c ff 75 08 e8 35 72 12 00 83 c4 0c 5d c2 08 00`, and decompilation is the one-block `_wcscpy_s(destination, size, this + 2)` form; `this + 2` is byte offset `+0x04` because IDA typed `this` as `wchar_t *`.
- The same B002 pass decoded the `ErrorMessage` table bytes at `0x006193b8`: RTTI `0x00646d10`, destructor slot `0x006193bc -> 0x004a6920`, inherited runtime slot `0x006193c0 -> 0x004f4b10`, no-op slot `0x006193c4 -> 0x0041b6c0`, message-output slot `0x006193c8 -> 0x004a6410`, and name slot `0x006193cc -> 0x004a6a70`. `xrefs_to 0x004a6410` reports the single data ref `0x006193c8`; direct callers remain absent, which is expected for a vtable-only virtual body.
- B002 pointer-route checks keep the raw-constructor and vtable interpretation narrow: `find_bytes 10 64 4A 00` finds only `0x006193c8`, `find_bytes BC 93 61 00` finds the raw constructor store operand at `0x004a63f1`, and searches for raw constructor VA/RVA bytes (`E0 63 4A 00`, `E0 63 0A 00`) and slot-address bytes (`C8 93 61 00`) find no alternate route.
- The inline-message layout is stronger after the same pass: [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) uses `[ecx+4]`, and the `ErrorMessage` scalar deleting destructor `sub_4A6920` contains object-size immediate `204h`; subtracting the 4-byte vptr leaves `0x200` bytes, or `wchar_t[256]`. `m_message` remains a descriptive field name, not a recovered source symbol.
- B009's 2026-06-29 implementation on MCP session `B006_0002F1_20260629` supersedes the target-specific blank-C++ caveat for [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md). The current session reconfirmed `sub_4A6410 size 0x19`, the same bytes/decompile/disassembly, `_wcscpy_s` callee, vtable-only route at `0x006193c8`, raw constructor store at `0x004a63ef`, unique function-pointer bytes in the slot, no alternate raw-constructor or slot-address pointer route, and the `wchar_t[256]` layout. The exact child now emits `int ErrorMessage::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const { return wcscpy_s(destination, destinationChars, m_message); }`.
- Source-facing caveat: sibling `+0x0c` slots still decompile as `int` for status-code formatters and `errno_t` for stored-message copy helpers, so original declaration spelling remains inferred. That broader caveat no longer blocks formal C++ for this exact ErrorMessage body.
- 2026-06-27 B005 MCP session `80de0a67` reconfirmed the cleanup-island context around this class. [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) is modeled `sub_4A6400` size `0x0b`, has no direct xrefs/callers or VA/RVA pointer-route hits, writes the base `Error` vtable `0x00619344`, and tail-jumps to `sub_4F4A90` with bytes `c7 01 44 93 61 00 e9 85 e6 04 00`. The same session created sibling [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md), proving the duplicate FileError-adjacent island has the same source-family cleanup role. Both are represented by [UID:0000J5][Error](by-file/Error.md) destructor/unwind source and formal marker comments, not by ErrorMessage-specific product helper methods.

## Autogen Status

Attach this class to [UID:0000J5][Error](by-file/Error.md) as reconstructable hierarchy metadata, but keep the class page's own C++ block blank because the constructor start is still raw/projected and final class declaration/member spelling is not final C++ quality. The exact method page [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) now emits the source-ready `int ErrorMessage::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` body through `util/Error.cpp`; after validator refresh, generated `Error.cpp` should no longer list UID00013Z as an empty emitter marker.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The page records the class role, likely source owner, raw-constructor caveat, current MCP vtable slot map, inline `wchar_t[256]` message layout, source-ready exact [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) method body, cleanup/destructor helper behavior, constructor-store xref, component evidence, unique raw-constructor/helper signature, and class-level no-code autogen handling. Completion remains capped because the constructor is not an IDA-modeled function and final class declaration/member spelling is unresolved. |
| Confidence `88` | The ownership, vtable slots, copy offset, destructor size/layout evidence, helper ranges, and signature are live-IDA/MCP supported, including the B009 `B006_0002F1_20260629` recheck of [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md). Confidence is not higher because `0x004a63e0` remains a raw constructor-shaped start without an IDA function record or caller/xref proof, and the final original class/member/virtual names are not settled. |

## Cross-References

- [UID:0000J5][Error](by-file/Error.md)
- [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md)
- [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md)
- [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md)
- [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md)
- [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md)
- [UID:0001UE][ErrorObjectLayouts](by-type/by-struct/ErrorObjectLayouts.md)
- [UID:0002ND][0x00619340-0x00619448.ErrorHierarchyVtableData](by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md)

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
- 2026-06-15 A002 Goal 2 by-class refresh:
  - Changed to: scores `85/88`, with no owner/emitter changes.
  - Summary/evidence: live IDA reconfirmed the raw constructor remains non-modeled/no-xref, the cleanup/copy/destructor/name-helper sizes, copy/destructor vtable anchors, raw constructor vtable store, shared base-vtable restore evidence, component shape, and unique raw constructor plus helper signature. C++ remains blank because constructor reachability and final declaration/member names are not source-quality.
- 2026-06-23 B002 ErrorMessage copy-helper source-quality implementation:
  - Score unchanged at `85/88`.
  - Summary/evidence: accepted B002 report for [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) refreshed this class with MCP session `b880584f` evidence for the exact copy-helper bytes/decompile, single vtable data ref at `0x006193c8`, raw constructor vtable store at `0x004a63ef`, negative pointer/caller checks, `wchar_t[256]` inline-buffer support from `[ecx+4]` and destructor size `0x204`, and the hierarchy-wide `+0x0c` name/return caveat. Formal class C++ remains blank for source-shape standardization, not because [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) lacks a reconstructable body.
- 2026-06-27 B005 cleanup-island sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: B005 MCP session `80de0a67` confirms [UID:00013Y][0x004a6400-0x004a640b.ErrorBaseCleanupHelper](by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md) as a no-route base cleanup island adjacent to the raw ErrorMessage constructor/copy-helper region and adds [UID:00048A][0x004a6470-0x004a647b.FileErrorBaseCleanupHelper](by-memory/0x004a6470-0x004a647b.FileErrorBaseCleanupHelper.md) as the exact sibling island. Both write `0x00619344`, tail-jump to `sub_4F4A90`, and are represented by Error hierarchy destructor/unwind source rather than class-specific helper C++.
- 2026-06-29 B009 ErrorMessage copy-helper implementation:
  - Score unchanged at `85/88`; this is a targeted exact-method source update, not a broad class declaration pass.
  - Summary/evidence: accepted B009 report and MCP session `B006_0002F1_20260629` raise [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) to source-ready `int ErrorMessage::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const`, returning `wcscpy_s(destination, destinationChars, m_message)`. The raw constructor caveat, inferred `m_message` spelling, and class-page blank C++ remain; the old target-specific blank-C++ blocker no longer applies to UID00013Z.
