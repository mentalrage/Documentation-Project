*** UID:0000UE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DeserializePredefinedFormArticleEntries 0x00478650

## Status

- Confidence: strong; source-ready first-draft parser C++ now lives on [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md)
- Entity kind: global/file-local helper
- Likely source module: [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- Autogen parent: [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- Exact range: [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md)

## Behavior

`DeserializePredefinedFormArticleEntries_478650` parses a serialized predefined article form payload into `PredefinedFormArticleEntry` records used by `NewPredefinedFormArticleDialog`. B014's 2026-07-03 current MCP callback resolves this parser as source-ready at `90/92`; exact original declaration spellings remain inferred but no longer block the formal C++ block on the exact memory child.

Input/output model:

- `serialized`: source byte stream. `serialized[1]` is the first title length; parsing starts at offset `2`.
- `entries`: output array of `0x40c` byte entry records.
- `outVisibleRowCount`: receives the row count used to size the variable-height dialog.
- `outEntryCount`: receives the number of parsed entries.

Source-facing signature:

```text
static int DeserializePredefinedFormArticleEntries(const unsigned char *serializedForm, PredefinedFormArticleEntry *entries, unsigned short *outVisibleRowCount, unsigned short *outEntryCount)
```

Algorithm summary:

- Loops until the next title length byte is zero.
- Copies title bytes into a local ANSI buffer, converts to wide text with `MultiByteToWideChar`, stores title length and text.
- Reads `usesUserImagePane`, `textLineCount`, body length, body bytes, and `hasExtraRowAdvance`.
- Converts body bytes to wide text. The literal body value `empty` becomes an empty body with zero length.
- Updates visible-row count using the extra-row flag and the `textLineCount`-based height calculation for multiline body fields.
- Writes final entry count and visible row count to the caller outputs and returns the visible row count.

Entry layout used by the formal declaration:

| Offset | Source-facing field | Evidence/notes |
| --- | --- | --- |
| `+0x00` | `titleLength` | one-byte converted title length |
| `+0x02` | `title[256]` | wide title buffer; byte at `+0x01` is alignment padding |
| `+0x202` | `usesUserImagePane` | one-byte flag |
| `+0x203` | `textLineCount` | one-byte row-height input |
| `+0x204` | `bodyLength` | one-byte converted body length, zero for `empty` |
| `+0x206` | `body[256]` | wide body buffer; byte at `+0x205` is explicit reserved alignment |
| `+0x408` | `rowAdvanceMode` | dword consumed by submit; parser writes `0` or `1` |

The total stride is `0x40c`. The target C++ keeps explicit reserved fields for the alignment bytes, uses `g_emptyWideString` as the source-facing alias for raw `word_60DB20`, and preserves the skipped title delimiter byte after each title byte run.

## Xref Evidence

IDA MCP checked on 2026-05-24:

- Function boundary: `0x00478650-0x00478932`.
- Code xrefs are only from `NewPredefinedFormArticleDialog::NewPredefinedFormArticleDialog` at `0x00477848` and `0x00477d0c`.

This caller set strongly supports treating the helper as file-local to the predefined-form article dialog rather than a shared parser module.

Rechecked on 2026-06-14:

- Live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, `sub_478650` at `0x00478650` with size `0x2e3` / 739 bytes, and exactly two code xrefs from constructor body `sub_4777A0` at `0x00477848` and `0x00477d0c`.
- Disassembly still starts with a `0x324`-byte stack frame, security-cookie setup, source/output pointer setup, initial parsing from `serialized[1]` with the loop cursor starting at offset `2`, and calls into character conversion helpers before the payload field loop.

Rechecked on 2026-06-16:

- Live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed `sub_478650` at `0x00478650`, size `0x2e3`, half-open end `0x00478933`, and the same two constructor-only call sites at `0x00477848` and `0x00477d0c`.
- `analyze_function`/decompilation confirms a 15-block parser with the `0x40c` / 1036-byte entry stride, field writes at offsets `+0x00`, `+0x02`, `+0x202`, `+0x203`, `+0x204`, `+0x206`, and `+0x408`, the `L"empty"` body special case, final entry-count and visible-row-count stores, and callees/calls through `sub_516030`, `sub_516220`, `MultiByteToWideChar`, `_wcscpy_s`, and the security-cookie check.
- Boundary bytes around `0x00478640` reconfirm the parser starts after `0xcc` alignment following the paint method, so the old `0x00478932` wording was an inclusive/terminal-byte shorthand; the exact documented range is `0x00478650-0x00478933`.

Rechecked on 2026-07-03:

- B014 current MCP session `b010_00032w_20260703` reconfirmed `sub_478650` at `0x00478650`, size `0x2e3` / 739, terminal `retn 10h`, and no neighbor functions at `0x0047864c` or `0x00478933`; byte reads confirm `0xcc` padding before and after the exact function.
- `xrefs_to` command id 6 and `xref_query` command id 21 reported exactly two parser callers, `0x00477848` and `0x00477d0c`, both inside constructor `sub_4777A0`; no extra caller or shared utility route was found.
- `analyze_function`/`decompile` command ids 7/8 and paged disassembly command ids 9/10 confirm the input/output pointer signature, first title length from `serializedForm[1]`, cursor start at `2`, two `MultiByteToWideChar` conversions, `wcscmp` against `L"empty"`, the `word_60DB20` empty wide-string path, row-count arithmetic `16 * textLineCount / 21 + 1`, final out-count stores, and the field offsets listed above.
- `type_query` command id 19 and `search_structs` command id 20 found no named IDA `Predefined*` type or struct. The missing recovered type caps exact-spelling confidence but does not block the inferred `PredefinedFormArticleEntry` first-draft source declaration.

## Source-Quality Blockers Checked

- Ownership/reachability: `xrefs_to 0x00478650` still reports only the two constructor calls, so [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) remains the correct owner/emitter route.
- Range/split: the exact memory child [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md) now records the half-open range and padding evidence; no split or merge is justified.
- Formal C++ readiness: field offsets, call sites, out-pointer roles, row-count logic, and submit consumers are strong enough for source-shaped first-draft C++. The exact memory child now owns the formal parser C++ with inferred `PredefinedFormArticleEntry` names; narrow-copy helper original spellings and constructor-side dynamic-control member names remain confidence caps for broader class work.

## Cross-References

- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)
- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md)
- [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md)

## 2026-08-14 Covered-By And No-Code Disposition

This by-item page is a search/index alias for the same parser body at `[0x00478650,0x00478933)`. Exact source ownership, formal `static int __stdcall DeserializePredefinedFormArticleEntries(...)` CPP, caller/range evidence, and the class-H `PredefinedFormArticleEntry` declaration live on [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md) and [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md). Emitting from this alias would duplicate the same function and recreate an empty/duplicate generated marker. It is therefore intentionally `RECONSTRUCTABLE:FALSE`, non-emitting, and blank in both formal channels while retaining contextual owner [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md).

The accepted row layout uses seven source members at offsets `0`, `2`, `0x202`, `0x203`, `0x204`, `0x206`, and `0x408`; the gaps are natural compiler alignment, not explicit reserved source fields. Historical explicit-reserved-field and alias-emitter descriptions above are preserved as superseded evidence history.

## Changes

- 2026-08-14 B004 UID0000LT implementation callback: raised `90/92` to `92/94`, reclassified this duplicate search alias as non-reconstructable/non-emitting, kept both formal channels blank, and added the exact covered-by route to parser child [UID:0002UP][0x00478650-0x00478933.DeserializePredefinedFormArticleEntries](by-memory/0x00478650-0x00478933.DeserializePredefinedFormArticleEntries.md) plus H owner [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md).

- 2026-06-16 A002 Goal 2 parser evidence refresh:
  - Raised completion/confidence from `85/88` to `86/89`.
  - Summary/evidence: live IDA reconfirmed the exact `0x00478650-0x00478933` parser range, `0x2e3` size, two constructor-only xrefs, clean padding boundary, full decompiled field flow for the `0x40c` entry records, `L"empty"` handling, and final count stores. Owner/emitter remain [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md); final C++ remains blank because final struct/member/helper names are still not source-quality.
- 2026-07-03 B014 UID0002UP implementation callback:
  - Raised completion/confidence from `86/89` to `90/92`.
  - Summary/evidence: current MCP session `b010_00032w_20260703` reconfirmed range/size, two constructor-only xrefs, boundary padding, input/output pointer roles, `0x40c` entry stride, exact field offsets, `empty` handling through `word_60DB20`, visible-row arithmetic, no extra callers, and no named IDA `Predefined*` type. The exact memory child now emits the formal first-draft parser C++ and `PredefinedFormArticleEntry` declaration; owner/emitter remain [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md).
- 2026-06-14 A001 Goal 2 by-item score pass:
  - Raised completion from `84` to `85`; confidence remains `88`.
  - Summary/evidence: live IDA MCP reconfirmed the exact `0x00478650-0x00478932` function, `0x2e3` / 739-byte size, the two constructor-only caller sites, parser stack frame/setup, field-loop entry evidence, and unchanged [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md) owner/emitter route. Final C++ remains blank because final entry type names and exact string-conversion source shape remain unresolved.
- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md), and stale generated-source wording was removed.
  - Before: the predefined-form parser helper was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned file-local dialog source under the validated NewPredefinedFormArticleDialog file root; C++ remains blank because final entry type names and string conversion details are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_478650` at `0x00478650`, size `0x2e3`, with exactly two direct caller sites inside `sub_4777A0`, matching the documented constructor-only parser role.

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented predefined article payload parsing behavior, input/output model, algorithm summary, and xref evidence but remained unevaluated.
  - After: score reflects detailed parser behavior and strong file-local ownership for the predefined-form article dialog.
  - Evidence: IDA MCP confirms the exact function boundary and only two xrefs from `NewPredefinedFormArticleDialog::NewPredefinedFormArticleDialog`.
