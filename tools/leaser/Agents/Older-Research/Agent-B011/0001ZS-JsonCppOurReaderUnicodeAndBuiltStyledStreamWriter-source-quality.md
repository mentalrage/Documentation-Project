** TARGET-REPORT-UID:0001ZS **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

## Supervisor Disposition - Duplicate Historical Lead, Do Not Execute

2026-06-29 supervisor manual research-folder check: this loose B011 report is not active work and must not be executed or continued unless a future supervisor explicitly reopens it. The same target is already covered by the newer executed report `executed-b-agent-research/B001/0001ZS-JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter-source-quality.md`, and `auto-generated/-ag-research-tracker.md` lists [UID:0001ZS] at `89/91`, report count `1`, author `B001`, path `by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md`. The executed report already converted the parent into a non-emitting split index and materialized source-bearing JsonCpp children. Preserve this file only as historical lead material.

2026-07-02 B011 backlog review: disposition remains duplicate historical lead. Current target doc `by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md` already has the B001 implementation result: `COMPLETION:89`, `CONFIDENCE:91`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal C++, non-emitting JsonCpp split-index summary, and child links [UID:00048B] / [UID:00048C] for the source-bearing reader and writer import-directive pages. This loose B011 report is not report-only work awaiting validation, not callback-ready, and not already-implemented by B011; it is superseded by the executed B001 report and should not receive `execute_report`.

# B011 Source-Quality Report - [UID:0001ZS] JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter

## Assignment And Scope

- Assignment ID: `B011-report-0001ZS-jsoncpp-ourreader-builtstyledstreamwriter-source-quality-20260626`
- Repair assignment ID: `B011-repair-0001ZS-jsoncpp-ourreader-builtstyledstreamwriter-import-directives-20260627`
- Agent: `B011`
- Target: [UID:0001ZS] `by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md`
- Required report path: `tools/leaser/Agents/Agent-B011/research/0001ZS-JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter-source-quality.md`
- Mode: report-only research first; 2026-06-27 repair is report-only import-directive correction.
- Write scope observed: no target/support by-* docs, generated files, project-level files, validator/tool state, IDA DB, or `-coverage-report.md` files were edited. No leases were taken. No subagents were spawned.
- Required MCP session used: `80de0a67`.

## Current Recommendation

Convert [UID:0001ZS] from a reconstructable mixed reader/writer aggregate into a non-emitting JsonCpp source-file split index, then create two source-bearing children:

| Recommended page | Size | Source file | Disposition |
| --- | ---: | --- | --- |
| `by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md` | `0xb30` / `2864` bytes | `src/lib_json/json_reader.cpp` | Reconstructable static-embed child emitted through [UID:0000KI]. |
| `by-memory/0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers.md` | `0xdee` / `3566` bytes | `src/lib_json/json_writer.cpp` | Reconstructable static-embed child emitted through [UID:0000KI]. |

Parent [UID:0001ZS] after accepted implementation:

- `COMPLETION:89`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000KI`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- `EMITTER_POSITION_OPTIONAL:` blank
- parent formal C++ remains blank

New child scores should be `88/91`, with `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KI`, blank emitter position, blank multiline `RECONSTRUCTION_CPP CODE` BEGIN/END blocks, and exact formal inline import directives:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

```markdown
*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

This follows the same source-file split shape as the already-executed JsonCpp [UID:0000X6] precedent, but updates the implementation form to the current validator import-directive standard. Keeping the current [UID:0001ZS] as one emitting page would preserve the same source-quality defect: it crosses from `json_reader.cpp` into `json_writer.cpp` at `0x004353c0`.

## Current Target State

The target currently has:

- `COMPLETION:85`, `CONFIDENCE:88`
- `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KI`
- blank inline and multiline formal `RECONSTRUCTION_CPP CODE`
- a summary that correctly assigns the bytes to JsonCpp but treats vendored source as a reason for no formal imported output

The generated research tracker row is stale: `auto-generated/-ag-research-tracker.md` still lists [UID:0001ZS] at `80/85`, reconstructable `true`, and zero code characters. That is validator-owned generated output and was not edited; the source page itself is the current metadata source at `85/88`.

Current stale or incomplete pieces in the target page:

- It says `0x00434887-0x00434890` is `cc cc cc` padding. Live MCP bytes show nine `0xcc` bytes, not three.
- It lists only the tail `0x00436180-0x004361ae` as raw/no-function code. Live MCP also shows raw source bodies at `0x00434db0`, `0x00434e30`, `0x00434e50`, and `0x00435ed0`.
- It treats `0x004352f7-0x004353c0` as a gap/padding-style region. Live MCP shows reader-owned data: `jpt_4350AB` at `0x004352f8` and an indirect switch table at `0x00435340`, followed by only two alignment bytes before `0x004353c0`.
- It omits the writer `jpt_4355B0` table at `0x004358a0-0x004358c0`.
- It leaves formal C++ blank for source-bearing JsonCpp static-embed material. Current validator policy requires source-bearing JsonCpp children to use inline `RECONSTRUCTION_CPP CODE` import directives for vetted files under `source-3/third_party_embeds/...`, while mixed aggregate parents become non-emitting split indexes.

## MCP Evidence Checked

Live MCP was available and no fallback-only evidence was used.

- `initialize` succeeded against `http://127.0.0.1:13337/mcp`, server `ida-pro-mcp 1.0.0`, protocol `2025-06-18`.
- `idb_list` returned one active owned/adopted worker session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, `is_analyzing:false`.
- `server_health(database=80de0a67)` returned `status:ok`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready with `2067` strings.
- `survey_binary(detail_level=minimal,database=80de0a67)` returned PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, `.text` `0x00401000-0x0060d000`, `.rdata` `0x0060d670-0x0066d000`, `.data` `0x0066d000-0x0069d000`.
- `entity_query(functions, min_addr=0x00434880, max_addr=0x004361c0)` returned nineteen target modeled functions plus successor `sub_4361B0`.
- `lookup_funcs` confirmed all modeled starts and reported `Not a function` at exclusive ends, raw starts, tables, and padding addresses including `0x00436180` and `0x004361ae`.
- `get_bytes` checked all inter-function regions, tables, and tail padding.
- `insn_query` checked raw/no-function helper bodies and table regions.
- `xrefs_to`, `callees`, `entity_query(strings/names)`, and `analyze_function` checked reachability, vtable/data routes, literals, and representative decompiled behavior.

## Continuation Verification Addendum

The 2026-06-27 continuation pass rechecked the report's decisive evidence against live MCP without changing the recommendation.

- MCP remained responsive at `http://127.0.0.1:13337/mcp`: `initialize` returned `ida-pro-mcp 1.0.0` / protocol `2025-06-18`; `tools/list` included `server_health`, `entity_query`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `callees`, and related read-only inspection tools; `idb_list` still returned active session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, `is_analyzing:false`; `server_health(database=80de0a67)` returned `status:ok`, imagebase `0x400000`, Hex-Rays ready, strings cache ready with `2067` strings.
- Read-only listener/process status was present: `127.0.0.1:13337` had a listener owned by PID `13684`; visible MCP/IDA worker processes included `idalib-mcp.exe` / Python launcher wrappers on port `13337` and `ida_pro_mcp.idalib_server` worker PIDs on worker port `64549`. No process-control action was taken.
- `entity_query(functions, min_addr=0x00434880, max_addr=0x004361c0, database=80de0a67)` returned the same nineteen modeled target functions from `sub_434890` through `sub_436010`, plus successor `sub_4361B0` at `0x004361b0`.
- `lookup_funcs` reconfirmed no function at `0x00434887`, table boundary `0x004352f7`, raw tail `0x00436180`, or exclusive end `0x004361ae`; it reconfirmed functions at `0x00434890` (`sub_434890`), `0x004353c0` (`sub_4353C0`), and successor `0x004361b0` (`sub_4361B0`).
- `get_bytes(regions=...)` reconfirmed nine `0xcc` bytes at `0x00434887-0x00434890`; reader table bytes from `0x004352f7` ending with two `0xcc` bytes before `0x004353c0`; writer jump-table bytes at `0x004358a0-0x004358c0`; and nine `0xcc` bytes at `0x00436177-0x00436180`, raw `hasCommentForValue` bytes at `0x00436180-0x004361ae`, then two `0xcc` bytes at `0x004361ae-0x004361b0`.
- `xrefs_to` reconfirmed the reader table route `0x004350ab -> 0x004352f8`, writer table route `0x004355b0 -> 0x004358a0`, writer vtable route `0x0042eaf3/0x004353f0 -> 0x0060ef90`, and vtable-cell route `0x0060ef94 -> 0x004354b0`.
- `callees` reconfirmed the writer helper cluster around `0x004354b0`, `0x00435570`, `0x004358c0`, and `0x00435c40`, including internal calls to the local writer helpers and runtime/STL callees.
- `Get-FileHash` reconfirmed the staged and obtained-static-embed source hashes match for both `json_reader.cpp` (`89074ed5550883e9ea7d300ed24292bb3238a18f76103c1219adb4d08f8899d2`) and `json_writer.cpp` (`c197234a6b01d18355990168a0096baf25ad3af2381a38b39aab62c97a41e609`).
- `tools/int_convert.py` reconfirmed the documented size conversions: `0x191e` = `6430`, `0xb30` = `2864`, `0xdee` = `3566`, `0xc9` = `201`, and `0x2e` = `46`.

## Exact Range And Boundary Facts

Target half-open range: `0x00434890-0x004361ae`, total size `0x191e` / `6430` bytes (Verified with `int_convert.py`).

Start boundary:

- Predecessor [UID:0000X9] `sub_4345F0` ends at `0x00434887`.
- `get_bytes 0x00434887 size 9` returns nine `0xcc` bytes.
- `sub_434890` starts at `0x00434890`.
- The target page's current three-byte padding wording is stale.

Reader/writer source boundary:

- `sub_435040` ends at `0x004352f7`.
- `0x004352f7-0x004353c0` is not padding. MCP disassembly/data names show:
  - `0x004352f7`: alignment before the table
  - `0x004352f8`: `jpt_4350AB`, jump table for the `sub_435040` token switch
  - `0x00435340`: indirect switch table bytes
  - `0x004353be-0x004353c0`: two `0xcc` alignment bytes
- `sub_4353C0` starts the `BuiltStyledStreamWriter` writer source at `0x004353c0`.

End boundary:

- `sub_436010` ends at `0x00436177`.
- `0x00436177-0x00436180` is nine `0xcc` bytes.
- `0x00436180-0x004361ae` is raw/no-function `BuiltStyledStreamWriter::hasCommentForValue`.
- `0x004361ae-0x004361b0` is two `0xcc` bytes.
- `sub_4361B0` starts at `0x004361b0` in [UID:0001ZT], the MSVC/Dinkumware STL/iostream support island.

## Current MCP Inventory

Reader-side `json_reader.cpp` child candidate `0x00434890-0x004353c0`:

| Range | MCP label | Size | Source-facing role |
| --- | --- | ---: | --- |
| `0x00434890-0x004349e0` | `sub_434890` | `0x150` / 336 | `OurReader::decodeUnicodeCodePoint`; surrogate-pair handling. |
| `0x004349e0-0x00434b75` | `sub_4349E0` | `0x195` / 405 | `OurReader::decodeUnicodeEscapeSequence`; four hex digits and bad-hex diagnostics. |
| `0x00434b75-0x00434b80` | alignment | `0xb` / 11 | All `0xcc`. |
| `0x00434b80-0x00434c5d` | `sub_434B80` | `0xdd` / 221 | `OurReader::addError(...)`; appends `ErrorInfo`, returns false. |
| `0x00434c5d-0x00434c60` | alignment | `0x3` / 3 | All `0xcc`. |
| `0x00434c60-0x00434da3` | `sub_434C60` | `0x143` / 323 | `OurReader::recoverFromError(TokenType)`. |
| `0x00434da3-0x00434db0` | alignment | `0xd` / 13 | `align 10h`. |
| `0x00434db0-0x00434dd2` | raw code | `0x22` / 34 | `OurReader::addErrorAndRecover(...)`; calls `sub_434B80` then `sub_434C60`. |
| `0x00434dd2-0x00434de0` | alignment | `0xe` / 14 | `align 10h`. |
| `0x00434de0-0x00434e27` | `sub_434DE0` | `0x47` / 71 | `OurReader::currentValue()`. |
| `0x00434e27-0x00434e30` | alignment | `0x9` / 9 | `align 10h`. |
| `0x00434e30-0x00434e44` | raw code | `0x14` / 20 | `OurReader::getNextChar()`. |
| `0x00434e44-0x00434e50` | alignment | `0xc` / 12 | `align 10h`. |
| `0x00434e50-0x00434eab` | raw code | `0x5b` / 91 | `OurReader::getLocationLineAndColumn(Location,int&,int&)`. |
| `0x00434eab-0x00434eb0` | alignment | `0x5` / 5 | Alignment before string helper. |
| `0x00434eb0-0x00434f6a` | `sub_434EB0` | `0xba` / 186 | `OurReader::getLocationLineAndColumn(Location) const`; emits `Line %d, Column %d`. |
| `0x00434f6a-0x00434f70` | alignment | `0x6` / 6 | All `0xcc`. |
| `0x00434f70-0x0043503b` | `sub_434F70` | `0xcb` / 203 | `OurReader::addComment(...)` / comment-normalization and attachment path. |
| `0x0043503b-0x00435040` | alignment | `0x5` / 5 | All `0xcc`. |
| `0x00435040-0x004352f7` | `sub_435040` | `0x2b7` / 695 | `OurReader::skipCommentTokens(Token&)` path with compiled token-switch/readToken logic and `nfinity` literal. |
| `0x004352f7-0x004353c0` | table/data/alignment | `0xc9` / 201 | `jpt_4350AB` plus indirect token switch table for `sub_435040`, then two `0xcc` bytes. |

Writer-side `json_writer.cpp` child candidate `0x004353c0-0x004361ae`:

| Range | MCP label | Size | Source-facing role |
| --- | --- | ---: | --- |
| `0x004353c0-0x004354a1` | `sub_4353C0` | `0xe1` / 225 | `BuiltStyledStreamWriter::BuiltStyledStreamWriter(...)`. |
| `0x004354a1-0x004354b0` | alignment | `0xf` / 15 | All `0xcc`. |
| `0x004354b0-0x0043556a` | `sub_4354B0` | `0xba` / 186 | `BuiltStyledStreamWriter::write(Value const&, JSONCPP_OSTREAM*)`. |
| `0x0043556a-0x00435570` | alignment | `0x6` / 6 | All `0xcc`. |
| `0x00435570-0x004358a0` | `sub_435570` | `0x330` / 816 | `BuiltStyledStreamWriter::writeValue(Value const&)`; local switch. |
| `0x004358a0-0x004358c0` | table | `0x20` / 32 | `jpt_4355B0` for `sub_435570`. |
| `0x004358c0-0x00435c30` | `sub_4358C0` | `0x370` / 880 | `BuiltStyledStreamWriter::writeArrayValue(Value const&)`. |
| `0x00435c30-0x00435c40` | alignment | `0x10` / 16 | All `0xcc`. |
| `0x00435c40-0x00435da1` | `sub_435C40` | `0x161` / 353 | `BuiltStyledStreamWriter::isMultineArray(Value const&)`; upstream spelling preserved. |
| `0x00435da1-0x00435db0` | alignment | `0xf` / 15 | All `0xcc`. |
| `0x00435db0-0x00435e07` | `sub_435DB0` | `0x57` / 87 | `BuiltStyledStreamWriter::pushValue(JSONCPP_STRING const&)`. |
| `0x00435e07-0x00435e10` | alignment | `0x9` / 9 | All `0xcc`. |
| `0x00435e10-0x00435e3f` | `sub_435E10` | `0x2f` / 47 | `BuiltStyledStreamWriter::writeIndent()`. |
| `0x00435e3f-0x00435e40` | alignment | `0x1` / 1 | One `0xcc`. |
| `0x00435e40-0x00435ea4` | `sub_435E40` | `0x64` / 100 | `BuiltStyledStreamWriter::writeWithIndent(...)`. |
| `0x00435ea4-0x00435eb0` | alignment | `0xc` / 12 | All `0xcc`. |
| `0x00435eb0-0x00435ec9` | `sub_435EB0` | `0x19` / 25 | `BuiltStyledStreamWriter::indent()`. |
| `0x00435ec9-0x00435ed0` | alignment | `0x7` / 7 | `align 10h`. |
| `0x00435ed0-0x00435efb` | raw code | `0x2b` / 43 | `BuiltStyledStreamWriter::unindent()`. |
| `0x00435efb-0x00435f00` | alignment | `0x5` / 5 | Alignment before comment writer. |
| `0x00435f00-0x0043600c` | `sub_435F00` | `0x10c` / 268 | `BuiltStyledStreamWriter::writeCommentBeforeValue(Value const&)`. |
| `0x0043600c-0x00436010` | alignment | `0x4` / 4 | All `0xcc`. |
| `0x00436010-0x00436177` | `sub_436010` | `0x167` / 359 | `BuiltStyledStreamWriter::writeCommentAfterValueOnSameLine(Value const&)`. |
| `0x00436177-0x00436180` | alignment | `0x9` / 9 | All `0xcc`. |
| `0x00436180-0x004361ae` | raw code | `0x2e` / 46 | static `BuiltStyledStreamWriter::hasCommentForValue(Value const&)`. |

All numeric conversions above were checked with `tools/int_convert.py`.

## Xrefs, Callees, Tables, And Data Routes

Reader-side positive evidence:

- Unicode diagnostics:
  - String `additional six characters expected to parse unicode surrogate pair.` at `0x0060e580` has an xref from `0x00434904` inside `sub_434890`.
  - String `expecting another \u token to begin the second half of a unicode surrogate pair` at `0x0060e5c8` has an xref from `0x004349b5` inside `sub_434890`.
  - String `Bad unicode escape sequence in string: four digits expected.` at `0x0060e618` has an xref from `0x00434a28` inside `sub_4349E0`.
  - String `Bad unicode escape sequence in string: hexadecimal digit expected.` at `0x0060e658` has an xref from `0x00434ae2` inside `sub_4349E0`.
- `Line %d, Column %d` at `0x0060e69c` has an xref from `0x00434f16` inside `sub_434EB0`.
- `nfinity` at `0x0060e6fc` has an xref from `0x004351a6` inside `sub_435040`; `analyze_function 0x00435040` also reports token fragments `nfinity`, `alse`, `ull`, and `aN`.
- `xrefs_to 0x00435040` reports code xrefs from `0x00431e0c` in [UID:0000X7] `sub_431D50` and `0x00432f51` in [UID:0000X8] `sub_432F10`.
- `xrefs_to 0x004352f8` reports a data xref from `0x004350ab` in `sub_435040`, proving `jpt_4350AB` belongs to the reader/token-switch body.

Reader-side liveness caveat:

- `xrefs_to` reports no direct xrefs to several retained source starts (`0x00434890`, raw `0x00434db0`, raw `0x00434e30`, raw `0x00434e50`, and `0x00434f70`). The same zero-xref pattern exists in other accepted JsonCpp static-library slices. It is not product ownership evidence and does not justify dropping the source-backed bytes; it means the compiler emitted retained helpers or inlined call sites while IDA did not model all starts as functions.

Writer-side positive evidence:

- `get_bytes 0x0060ef90 size 16` returns first vtable cells `0x0043b280` and `0x004354b0`, followed by the `indentat...` writer setting string bytes.
- `xrefs_to 0x0060ef90` reports data xrefs from `0x0042eaf3` inside `sub_42E850` and from `0x004353f0` inside the constructor `sub_4353C0`.
- `xrefs_to 0x004354b0` reports a data xref from `0x0060ef94`, tying the virtual `BuiltStyledStreamWriter::write` slot to `sub_4354B0`.
- `xrefs_to 0x004358a0` reports a data xref from `0x004355b0` in `sub_435570`, proving `jpt_4355B0` belongs to `writeValue`.
- Writer helper call graph is internally coherent:
  - `sub_4354B0` calls `sub_435F00`, `sub_435570`, and `sub_436010`.
  - `sub_435570` recursively calls itself, calls `sub_4358C0`, `sub_435DB0`, `sub_435E40`, `sub_435EB0`, `sub_435F00`, and `sub_436010`.
  - `sub_4358C0` calls `sub_435C40`, `sub_435DB0`, `sub_435E40`, `sub_435F00`, `sub_435570`, and `sub_436010`.
  - `sub_435C40` calls `sub_435570`.

Writer-side liveness caveat:

- Raw `0x00435ed0` and raw `0x00436180` have no direct xrefs to their starts in the current IDB. The disassembly bytes still match source `unindent()` and static `hasCommentForValue()` exactly enough for a source-backed child. This is an IDB modeling/liveness detail, not evidence for a runtime/product owner.

## Source Comparison

The staged source files match the obtained third-party static embed:

- `source-3/third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp` SHA-256 `89074ed5550883e9ea7d300ed24292bb3238a18f76103c1219adb4d08f8899d2`
- `source-3/project-documentation/by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/src/lib_json/json_reader.cpp` SHA-256 `89074ed5550883e9ea7d300ed24292bb3238a18f76103c1219adb4d08f8899d2`
- `source-3/third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp` SHA-256 `c197234a6b01d18355990168a0096baf25ad3af2381a38b39aab62c97a41e609`
- `source-3/project-documentation/by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/src/lib_json/json_writer.cpp` SHA-256 `c197234a6b01d18355990168a0096baf25ad3af2381a38b39aab62c97a41e609`

Reader anchors checked:

- `json_reader.cpp:1700-1727` is `OurReader::decodeUnicodeCodePoint`.
- `json_reader.cpp:1729-1756` is `OurReader::decodeUnicodeEscapeSequence`.
- `json_reader.cpp:1758-1766` is `OurReader::addError`.
- `json_reader.cpp:1768-1779` is `OurReader::recoverFromError`.
- `json_reader.cpp:1781-1785` is `OurReader::addErrorAndRecover`.
- `json_reader.cpp:1788` is `OurReader::currentValue`.
- `json_reader.cpp:1790-1794` is `OurReader::getNextChar`.
- `json_reader.cpp:1796-1817` is `OurReader::getLocationLineAndColumn(Location,int&,int&)`.
- `json_reader.cpp:1819-1824` is `OurReader::getLocationLineAndColumn(Location) const`.
- `json_reader.cpp:1197-1204` is `OurReader::skipCommentTokens(Token&)`; `json_reader.cpp:1207-1349` is the underlying `OurReader::readToken(Token&)` token switch that the compiled `sub_435040` path reflects.
- `json_reader.cpp:1352` and following is `OurReader::addComment`.

Writer anchors checked:

- `json_writer.cpp:873-892` is `BuiltStyledStreamWriter::BuiltStyledStreamWriter(...)`.
- `json_writer.cpp:893-907` is `BuiltStyledStreamWriter::write(...)`.
- `json_writer.cpp:908-965` is `BuiltStyledStreamWriter::writeValue`.
- `json_writer.cpp:967-1012` is `BuiltStyledStreamWriter::writeArrayValue`.
- `json_writer.cpp:1014-1039` is `BuiltStyledStreamWriter::isMultineArray`.
- `json_writer.cpp:1041-1046` is `BuiltStyledStreamWriter::pushValue`.
- `json_writer.cpp:1048-1058` is `BuiltStyledStreamWriter::writeIndent`.
- `json_writer.cpp:1060-1064` is `BuiltStyledStreamWriter::writeWithIndent`.
- `json_writer.cpp:1066` is `BuiltStyledStreamWriter::indent`.
- `json_writer.cpp:1068-1071` is `BuiltStyledStreamWriter::unindent`.
- `json_writer.cpp:1073-1090` is `BuiltStyledStreamWriter::writeCommentBeforeValue`.
- `json_writer.cpp:1092-1101` is `BuiltStyledStreamWriter::writeCommentAfterValueOnSameLine`.
- `json_writer.cpp:1103-1108` is static `BuiltStyledStreamWriter::hasCommentForValue`.

This report does not claim an exact release tag. It preserves the file-level [UID:0000KI] conclusion that official JsonCpp commit `b299d3581f4dc670734f1fe1a34fce1282337802`, between tags `1.7.4` and `1.7.5`, is the best current source snapshot.

## Heuristic And Inference Reanalysis

### Source-File Boundary

The current target is a true source-file crossing:

- `0x00434890-0x004353c0` is `json_reader.cpp`.
- `0x004353c0-0x004361ae` is `json_writer.cpp`.

The correct split boundary is `0x004353c0`, not `0x004352f7`, because the reader-owned `jpt_4350AB` and indirect token table live after the last modeled reader function. Splitting at `0x004352f7` would orphan source-owned switch data. Splitting at `0x004361ae` or keeping the current aggregate preserves the mixed-source-file problem.

### Import Directive Versus Blank Formal C++

The current "vendored source means blank C++" disposition is stale for source-bearing JsonCpp children. The current validator-supported pattern is:

- source-bearing JsonCpp by-memory child: reconstructable true, emitted through [UID:0000KI], inline `RECONSTRUCTION_CPP CODE` import directive to the vetted staged source file under `third_party_embeds/...`, and a blank multiline BEGIN/END block;
- mixed source-file aggregate/index: reconstructable false, blank emitters, blank inline and multiline formal C++, detailed no-code proof.

[UID:0000X6] already executed the source-file split pattern for a `json_writer.cpp` / `json_reader.cpp` crossing. [UID:0001ZS] should follow the same split shape, but use current import directives rather than legacy marker comments.

### Raw Starts And No-Xref Helpers

The raw helper starts are not blockers after the current pass. They are now mapped with live disassembly and staged source:

- `0x00434db0-0x00434dd2`: `OurReader::addErrorAndRecover`
- `0x00434e30-0x00434e44`: `OurReader::getNextChar`
- `0x00434e50-0x00434eab`: `OurReader::getLocationLineAndColumn(Location,int&,int&)`
- `0x00435ed0-0x00435efb`: `BuiltStyledStreamWriter::unindent`
- `0x00436180-0x004361ae`: `BuiltStyledStreamWriter::hasCommentForValue`

No IDA DB edit is needed. The documentation should preserve that `lookup_funcs` currently reports these starts as `Not a function` while still assigning their source identities from source/disassembly.

### Product Ownership

No product module owner is supported. Product modules are JSON consumers; JsonCpp owns parser/writer internals. The writer factory route through `StreamWriterBuilder` and the `0x0060ef90` vtable still points at JsonCpp writer source, not NexusTK UI/download/cash-shop source. Runtime/STL calls are dependencies, not source ownership.

### Successor Runtime Island

[UID:0001ZT] begins at `0x004361b0` after the raw JsonCpp `hasCommentForValue` body and two bytes of padding. JsonCpp is a heavy consumer of [UID:0001ZT], but the successor remains MSVC/Dinkumware STL/iostream support. There is no merge or source-owner transfer at the tail.

## Ranked Alternatives

| Rank | Alternative | Decision | Reason |
| ---: | --- | --- | --- |
| 1 | Convert [UID:0001ZS] to a non-emitting split index and create reader/writer children at `0x004353c0` with inline third-party import directives | Recommended | Resolves the actual source-file crossing, preserves tables/raw helpers with the correct side, and uses the current validator import-directive standard for vetted JsonCpp source files. |
| 2 | Keep [UID:0001ZS] reconstructable and place two import directives in one formal inline value | Rejected | It would emit imported files, but it keeps a mixed `json_reader.cpp` / `json_writer.cpp` source item and duplicates the [UID:0000X6] source-file-crossing defect already repaired elsewhere. |
| 3 | Split every modeled/raw helper into per-function pages | Rejected for this callback | Technically possible but excessive. The current blocker is the source-file boundary plus blank imported output; two children solve it without scattering one vendored source file into many redundant import-directive pages. |
| 4 | Keep metadata and blank C++ unchanged because JsonCpp is vendored | Rejected | Vendored source explains why not to write decompiler C++, but source-bearing JsonCpp children should carry formal inline import directives. Blank C++ is the reason the row remains not-covered. |
| 5 | Reassign writer helpers to [UID:0001ZT] or MSVC/STL runtime support | Rejected | `BuiltStyledStreamWriter` bodies, vtable, strings, and source anchors are JsonCpp writer source. Runtime helpers are callees only. |
| 6 | Reassign reader/writer bytes to product modules | Rejected | No product ownership route; product code consumes JsonCpp APIs rather than owning parser/writer internals. |
| 7 | Set all of [UID:0001ZS] to `CANONICAL_OWNER:NONE` | Rejected | The parent can be non-emitting while retaining [UID:0000KI] as semantic owner; source-bearing children are JsonCpp-owned. |

## Score And Metadata Rationale

Parent [UID:0001ZS] should move from `85/88` to `89/91`:

- Completion rises because this pass resolves current range facts, raw/no-function helper starts, the stale padding statement, table ownership, exact source-file split, import-directive disposition, owner/emitter route, and support-doc implementation plan.
- Confidence rises because current MCP session `80de0a67`, source hashes, vtable/data xrefs, decompilation, and staged source anchors agree.
- Parent `RECONSTRUCTABLE` should become `FALSE` because it is not one source-level unit after the split. It is an overlapping source-file split index/audit container. Keeping [UID:0000KI] as owner is still useful context, but the parent should not emit code.

New children should use `88/91`:

- They have strong source-file identity, source hashes, live MCP function/table/raw inventory, and valid [UID:0000KI] owner/emitter routing.
- They stay below final confidence because exact compiler/link settings and full byte-for-byte object/source audit remain broader JsonCpp-file work, and some retained raw helpers have no direct IDB xrefs.

## Formal C++ / No-Code Disposition

Parent [UID:0001ZS] no-code proof after split:

- The parent is an overlapping split index that spans two different upstream JsonCpp source files.
- Emitting a parent inline directive or multiline formal block would either duplicate child imports or preserve a mixed source-file aggregate.
- The source-bearing bytes are represented by the two exact children.
- Therefore the parent should have `RECONSTRUCTABLE:FALSE`, blank emitters, blank inline `RECONSTRUCTION_CPP CODE:[[[...]]]`, and a blank multiline C++ block.

Reader child formal C++:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Writer child formal C++:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The import paths are relative to `E:\NTK\GhidraBridge\source-3`, use forward slashes, start with `third_party_embeds/`, and end in `.cpp`. When these inline import directives are used, the multiline `RECONSTRUCTION_CPP CODE` BEGIN/END blocks on the child pages must stay blank. No copied JsonCpp method bodies, marker comments, or decompiler-shaped helper implementations are recommended.

## Recommended Target And Support Doc Changes

Target parent [UID:0001ZS]:

- Change metadata to `COMPLETION:89`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000KI`, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, keep blank `EMITTER_POSITION_OPTIONAL`, and keep the formal C++ block blank.
- Replace the Item Summary with a concise non-emitting split-index summary naming the `0x004353c0` reader/writer boundary and the two source-bearing children.
- Replace the stale evidence with current session `80de0a67`, PE SHA-256, range size, exact function/raw/table inventory, padding and table facts, source hashes, xrefs/callees, source-file split, and rejected alternatives.
- Preserve old A003 facts as historical context where true, but mark the three-byte predecessor padding and "only one raw helper" inventory as superseded.

Create `by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md`:

- Metadata `88/91`, owner/emitter [UID:0000KI], reconstructable true, blank position.
- Inline `RECONSTRUCTION_CPP CODE` import directive exactly `*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`; keep the multiline BEGIN/END block blank.
- Include the reader-side modeled functions, raw helpers, `jpt_4350AB`, indirect token table, nine-byte predecessor padding, source anchors, xrefs/literal evidence, and no-product-owner rejection.

Create `by-memory/0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers.md`:

- Metadata `88/91`, owner/emitter [UID:0000KI], reconstructable true, blank position.
- Inline `RECONSTRUCTION_CPP CODE` import directive exactly `*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`; keep the multiline BEGIN/END block blank.
- Include the writer-side modeled functions, `jpt_4355B0`, raw `unindent`, raw `hasCommentForValue`, vtable cell `0x0060ef94 -> 0x004354b0`, source anchors, internal call graph, successor padding, and runtime/product-owner rejection.

Support docs:

- `by-file/JsonCpp.md`: update the [UID:0001ZS] statement to record the split-index parent, the two source-bearing children, exact `0x004353c0` boundary, current MCP `80de0a67`, the corrected raw/table inventory, and the import-directive policy. Source snapshot/path stay unchanged.
- `by-meta/client_libraries.md`: add a concise note that [UID:0001ZS] is split into reader/writer source-bearing import-directive children; no source snapshot/path change.
- `by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md`: update successor boundary to the new reader child and correct the nine-byte `0x00434887-0x00434890` padding.
- `by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md`: update the `0x00435040` callee reference to point to the new reader child rather than only "later helper family."
- `by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md`: update the `sub_435040` readToken caller reference to point to the new reader child if the implementation reviewer wants the current split reflected there.
- `by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md`: update the `0x00431e0c -> 0x00435040` / `sub_432E10` support reference to the new reader child.
- `by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md`: add or refresh the factory/vtable route to the new writer child for `BuiltStyledStreamWriter`.
- `by-memory/0x0060e2b0-0x0060f038.JsonCppReadOnlyData.md`: add `0x0060ef90/0x0060ef94` BuiltStyledStreamWriter vtable-cell evidence and link it to the new writer child.
- `by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md`: update predecessor references from [UID:0001ZS] as an emitting page to the new writer child ending at raw `hasCommentForValue`, while preserving [UID:0001ZT] as runtime/STL support.
- `by-project-structure/proposed-source-tree.md`: no required edit; the upstream multi-file `third_party/jsoncpp/` layout is already documented.
- Product caller docs: no edit unless any implementation-time check finds a direct stale ownership claim. This report found none.

No manual `-coverage-report.md` replacement text is supplied because the current workflow keeps coverage/generated reports validator/supervisor-owned and this assignment did not explicitly request manual coverage text.

## Expected Validators After Accepted Implementation

Run from `source-3/project-documentation` only for files actually changed/created:

Removed executable material: [0001ZS-JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter-source-quality-removed.md](0001ZS-JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter-source-quality-removed.md). The validator commands remain described by the surrounding prose and checklist; the companion is preservation-only and must not be executed.

Use optional validators only for optional support pages actually edited. Because the two child pages use third-party import directives, the implementation callback must also verify generated JsonCpp output freshness with `--wait-generated` on the child validator commands or an equivalent proof that the relevant generated file header is equal/newer than the returned validator command metadata. Do not edit generated reports, project-level generated files, validator/tool state, IDA DB, or any `-coverage-report.md`.

## Superseded Implementation Tracking Checklist - Do Not Execute

The checklist below is retained only as historical lead material from the original report-only pass. It must not be acted on under the current backlog-clearing instruction because the accepted/implemented lifecycle is already covered by executed report `executed-b-agent-research/B001/0001ZS-JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter-source-quality.md`. No B011 implementation callback is pending for this report unless a future supervisor explicitly reopens it.

- [ ] Target [UID:0001ZS] `by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md`: update metadata to `89/91`, keep `CANONICAL_OWNER:0000KI`, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, keep blank emitter position, and keep parent formal C++ blank.
- [ ] Target [UID:0001ZS]: replace Item Summary/status with non-emitting JsonCpp reader/writer source-file split-index wording and exact `0x004353c0` boundary.
- [ ] Target [UID:0001ZS]: incorporate current MCP session `80de0a67` evidence, including PE SHA-256, total size `0x191e` / 6430 bytes, nineteen modeled starts, raw helper starts, `jpt_4350AB`, `jpt_4355B0`, padding/table facts, xrefs/callees, vtable route, source hashes, and negative product/runtime-owner evidence.
- [ ] Target [UID:0001ZS]: mark stale earlier facts as superseded where needed: predecessor padding is nine bytes, not three; raw helper inventory includes more than the `0x00436180` tail helper; `0x004352f7-0x004353c0` is reader-owned table data/alignment, not pure padding.
- [ ] Create reader child `by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md` with metadata `88/91`, owner/emitter [UID:0000KI], reconstructable true, blank position, inline import directive `*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`, and blank multiline `RECONSTRUCTION_CPP CODE` BEGIN/END block.
- [ ] Create reader child content with modeled/raw/table inventory, source anchors, xrefs/literal evidence, boundary notes, rejected alternatives, and source-route rationale at report-level detail.
- [ ] Create writer child `by-memory/0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers.md` with metadata `88/91`, owner/emitter [UID:0000KI], reconstructable true, blank position, inline import directive `*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`, and blank multiline `RECONSTRUCTION_CPP CODE` BEGIN/END block.
- [ ] Create writer child content with modeled/raw/table inventory, vtable route, source anchors, internal call graph, boundary notes, rejected alternatives, and source-route rationale at report-level detail.
- [ ] Update `by-file/JsonCpp.md` with the [UID:0001ZS] split decision, two child pages, `0x004353c0` boundary, current MCP provenance, corrected raw/table inventory, and import-directive policy.
- [ ] Update `by-meta/client_libraries.md` with a concise JsonCpp import-directive split note if accepted by supervisor.
- [ ] Update [UID:0000X9] `by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md` successor/boundary references to the new reader child and nine-byte padding.
- [ ] Update [UID:0000X7] `by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md` so the `0x00435040` callee points to the new reader child.
- [ ] Update [UID:0001ZR] `by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md` if accepted implementation wants the `sub_435040` readToken caller reference to link to the new reader child.
- [ ] Update [UID:0000X8] `by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md` with the new reader child reference for the `0x00431e0c -> 0x00435040` / `sub_432E10` support edge.
- [ ] Update [UID:0000X3] `by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md` with the factory/vtable route to the new writer child.
- [ ] Update [UID:00024O] `by-memory/0x0060e2b0-0x0060f038.JsonCppReadOnlyData.md` with `0x0060ef90/0x0060ef94` BuiltStyledStreamWriter vtable-cell evidence and new writer-child link.
- [ ] Update [UID:0001ZT] `by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md` predecessor references to the new writer child while preserving the runtime/STL owner rejection.
- [ ] Do not edit `by-project-structure/proposed-source-tree.md` unless the supervisor callback explicitly adds it; current source tree route is already sufficient.
- [ ] Do not edit product caller docs unless implementation-time review finds a stale direct ownership claim.
- [ ] Do not edit any `-coverage-report.md`, generated reports, project-level generated files, validator/tool state, or IDA DB.
- [ ] Run scoped validators for every changed/created by-* doc and record command, `command_id`, `command_timestamp`, exit code, ok count, warnings, and generated-refresh side effects during implementation callback; use `--wait-generated` or equivalent generated-header freshness proof for any child page whose inline import directive affects generated JsonCpp output.
- [ ] After implementation callback only, update this checklist with checked boxes and proof for each accepted item.

## Report-Only Completion State

No implementation blockers remain for supervisor review. MCP was live and responsive; the report resolves the source-file split, raw-helper inventory, stale padding, table ownership, score movement, owner/emitter route, formal third-party import-directive disposition, and expected support-document updates. Implementation remains supervisor-gated.

## Backlog Clearing Status

- 2026-07-02 B011 backlog review preserved the original `AUTHOR-AGENT-SPECS` header exactly.
- Classification: duplicate historical lead, superseded by executed B001 report. Not callback-ready and not executable as a B011 report.
- Current by-memory target and child pages already reflect the executed B001 implementation; this B011 report should be used only as historical lead material if a future supervisor explicitly reopens it.
- No by-* docs, generated files, coverage reports, project-level files, validator/tool state, queues, locks, archives, or IDA DB were edited during this backlog review.
- No leases or validators were needed because only this report status text was clarified.
