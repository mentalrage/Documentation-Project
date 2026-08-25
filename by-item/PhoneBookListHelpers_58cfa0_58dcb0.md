*** UID:0000V7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PhoneBookListHelpers 0x0058cfa0 / 0x0058dcb0

## Status

- Confidence: strong for phone-book selected-entry ownership and behavior, and very strong for the CRT/runtime classification of the formatted-write wrapper.
- Rebuild handling: mixed helper audit. [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) is source-authored `PhoneBookListPane` code and now emits through that exact memory page; [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is CRT/runtime formatted-output glue and should not be emitted as NexusTK product source.
- Related file/module: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Owner/emitter route: [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) routes to [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md); [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is ignored/runtime with no owner or emitter.
- Related memory ranges: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md), [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md), [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md), and [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)

## Helpers

| Address | Proposed name | Current issue | Evidence |
| --- | --- | --- | --- |
| `0x0058cfa0-0x0058cfdb` | `PhoneBookListPane::GetSelectedEntryData` | Resolved source-bearing `PhoneBookListPane` method; first-draft C++ now lives in [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md). | Live IDA shows one direct caller: `PhoneBookDialog::OnCommand` at `0x0058cd8c`. The body copies `PhoneBookContactEntry::name` and `PhoneBookContactEntry::phoneNumber` into caller buffers and returns the neutral `entryFlags` byte. |
| `0x0058dcb0-0x0058dcd3` | `CrtWideFilePrintfWrapper` / `MsvcWideFilePrintfWrapper` | Resolved as runtime/CRT glue, not a PhoneBook source helper. | Live IDA xrefs include `PhoneBookDialog::SavePhoneBook` at `0x0058ce94` and `0x0058cea6`, plus raw save-helper refs at `0x0058d0db` and `0x0058d0ed`. The helper builds a varargs list, calls `0x0041b9a0` for local stdio options, and forwards to `0x005d2208`. |

The broader B007 2026-06-19 source-quality pass also identified retained source-like helpers around this audit window: dialog wrappers at `0x0058c9c0`, `0x0058ca70`, and `0x0058cb30`; list setup/append helpers at `0x0058ced0` and `0x0058cf20`; and list replace/remove/save helpers at `0x0058cfe0`, `0x0058d080`, and `0x0058d090`. Those ranges remain documented on [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md) and the class pages; this item page stays focused on the exact [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) selected-entry helper and [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) CRT/runtime wrapper.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The page records both exact helper boundaries, the selected-entry caller, formatted-write modeled plus raw save-helper call sites, `PhoneBookContactEntry` layout, CRT forwarding, padding, and the split source/runtime interpretation. It remains a support audit page while exact target pages carry the actionable metadata/C++ decisions. |
| Confidence `90` | Confidence is strong because the 2026-06-14 live IDA refresh and B001 2026-06-17 source-quality pass agree on boundaries, decompiled field copies, varargs forwarding shape, direct xrefs, PhoneBookListPane owner route for [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md), and CRT/runtime route for [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md). |

## IDA MCP Evidence

Rechecked on 2026-05-31:

- `0x0058cfa0` is an IDA function `sub_58CFA0` with exclusive end `0x0058cfdc`; this matches the documented inclusive range `0x0058cfa0-0x0058cfdb`.
- `0x0058cfa0` has one direct code reference at `0x0058cd8c`. Its callees are `0x004f3dc0`, `_wcscpy_s`, and `_wcscpy_s`; decompilation copies two wide-string fields from the selected entry and returns the entry flag byte.
- `0x0058dcb0` is an IDA function `sub_58DCB0` with exclusive end `0x0058dcd3`; this aligns with the related memory page's `0x0058dcb0-0x0058dcd3` endpoint if that page is using exclusive-end notation. Confirm the exact inclusive/exclusive convention before any final-audit score.
- `0x0058dcb0` has code references at `0x0058ce94`, `0x0058cea6`, `0x0058d0db`, and `0x0058d0ed`. It calls `0x0041b9a0` and `0x005d2208`, consistent with a local varargs formatted-write adapter.

Rechecked on 2026-06-03:

- `lookup_funcs` reports `sub_58CFA0` size `0x3c`, so its half-open range is `0x0058cfa0-0x0058cfdc`; `0x0058cfdc` is not a function.
- `lookup_funcs` reports `sub_58DCB0` size `0x23`, so its half-open range is `0x0058dcb0-0x0058dcd3`; `0x0058dcd3` is not a function.
- `callers 0x0058cfa0` reports only `0x0058cd8c` inside `sub_58CCD0`; the call site passes two 64-wide-character output buffers and uses the selected-list object at `[eax+0x108]`.
- `callers 0x0058dcb0` reports the two modeled `SavePhoneBook` calls at `0x0058ce94` and `0x0058cea6`; IDA Python xrefs also show raw calls at `0x0058d0db` and `0x0058d0ed`, now identified as the raw no-function save helper at `0x0058d090-0x0058d10e`.
- Live decompile of `0x0058cfa0` calls the selected-entry accessor at `0x004f3dc0`, copies `v5 + 1` and `v5 + 65` through `_wcscpy_s`, and returns the leading flag byte.
- Live decompile of `0x0058dcb0` initializes a `va_list`, reads CRT stdio option storage through `0x0041b9a0`, and forwards the file/format/argument list to `0x005d2208`.
- IDA Python tail-byte inspection shows `0xcc` padding after both helpers' returns.

Rechecked on 2026-06-14:

- `lookup_funcs` reports `sub_58CFA0` size `0x3c` / 60 (Verified with int_convert.py) with half-open range `0x0058cfa0-0x0058cfdc`; `0x0058cfdc` is still not a function, and `get_bytes 0x0058cfdc size 4` returns four `0xcc` bytes.
- `lookup_funcs` reports `sub_58DCB0` size `0x23` / 35 (Verified with int_convert.py) with half-open range `0x0058dcb0-0x0058dcd3`; `0x0058dcd3` is still not a function, and `get_bytes 0x0058dcd3 size 13` returns `0xcc` padding (`13 == 0x0d`, Verified with int_convert.py).
- `analyze_component` reports `sub_58CFA0` as a `0x3c` / 60-byte (Verified with int_convert.py) one-block helper that calls `sub_4F3DC0` and `_wcscpy_s`, and `sub_58DCB0` as a `0x23` / 35-byte (Verified with int_convert.py) one-block helper that calls `sub_41B9A0` and `sub_5D2208`.
- `xrefs_to 0x0058cfa0` reports one direct caller at `0x0058cd8c` inside `sub_58CCD0`. `xrefs_to 0x0058dcb0` reports four code refs: two modeled `sub_58CE30` calls at `0x0058ce94` and `0x0058cea6`, plus raw refs at `0x0058d0db` and `0x0058d0ed`.
- Live decompile of `sub_58CFA0` still copies `v5 + 1` and `v5 + 65` through `_wcscpy_s` and returns the leading flag byte; the `+65` source confirms the second field begins after 64 wide characters (`64 == 0x40`, Verified with int_convert.py) plus the flag/pad lead-in.
- Live decompile of `sub_58DCB0` still initializes `va_list`, obtains CRT stdio option storage through `sub_41B9A0`, and forwards to `sub_5D2208`.

## Layout Evidence

Phone-book list entries have a compact flag plus two wide-string fields. The best source-facing type name is `PhoneBookContactEntry`:

```text
+0x000  entryFlags byte exposed through the helper return value
+0x002  name, wchar_t[64]
+0x082  phoneNumber, wchar_t[64]
```

`PhoneBookListPane::RenderEntry` reads the same `+0x02` and `+0x82` fields, truncates them with ellipses at approximately 60 and 120 pixels, and draws both columns.

## Ownership Decision

`0x0058cfa0` should not migrate as chat code or article-list code. It is direct [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md) source in the `PhoneBookDialog.cpp` source family.

`0x0058dcb0` should not be emitted as PhoneBook source. It is a static CRT/UCRT `fwprintf`-style wrapper around local stdio options and the common formatted-output backend; reconstructed callers should use normal CRT formatted file output.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md)
- [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md)
- [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while owner/emitter routing and C++ remain under review.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the helper boundaries, direct callsites, callees, and decompiled behavior. The score remains below final audit because final source naming, the `0x0058dcb0` endpoint convention, and owner placement still need a full audit.
- 2026-06-03: Raised from `70/85` to `82/88` and attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) using the older parent metadata then in effect.
  - Before: the page had correct high-level helper behavior but no parent assignment, stale generated/Wave provenance, and no current call-site/padding recheck.
  - After: live IDA MCP confirms both exact helper boundaries, selected-entry caller/body, formatted-write modeled and raw call sites, CRT forwarding behavior, and padding; [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) is a validated `NexusTK/login/` parent for both helpers.
  - Remaining gap: final reconstruction C++ stays blank because the selected-entry member name, formatted-write wrapper name, and handwritten source shape remain below source-quality evidence.
- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page had correct helper behavior and owner routing but still used stale parent metadata and old final-code gate wording.
  - After: the page records current owner/emitter terminology, a score rationale, refreshed IDA starts/endpoints, xref counts, decompiled copy/formatting behavior, padding bytes, and current source-quality blockers.
  - Evidence: IDA MCP `lookup_funcs`, `analyze_component`, `xrefs_to`, `get_bytes`, `decompile`, and `int_convert.py` checks.
- 2026-06-17 B001 source-quality execution:
  - Resolved [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) as `PhoneBookListPane::GetSelectedEntryData` with `PhoneBookContactEntry` row layout and direct [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md) owner/emitter.
  - Reclassified [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) as CRT/runtime formatted-output glue, corrected the raw xrefs to the raw save-helper span, and removed the local `WriteWideFormattedLine` source recommendation.
- 2026-06-21 B007 Rule 26 incorporation:
  - Added cross-reference to the surrounding retained dialog/list helpers from the broader [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md) pass while preserving this item's focused scope and unchanged score.
