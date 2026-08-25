** TARGET-REPORT-UID:00032K **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00032K Crc16WordStep Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:00032K] `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md` as the exact leaf word-step helper under [UID:00032J] `Crc16`; keep its owner, emitter, reconstructable state, score, and formal C++ body unchanged.
- Final disposition: report-only pass complete; the only implementation-ready target edit I recommend is metadata cleanup plus a fresh evidence note.
- Required action: during a supervisor-approved implementation callback, change the target's `Nested` metadata from `4` to `0`, then add the 2026-07-05 MCP evidence refresh facts to the target page. Run the scoped target validator after that edit.
- Implementation callback status: Gate 1 accepted this report at SHA256 `2ED38E80CCB4929FF6C0A5273B4868940BB043283A9B928B5F8E541CD1DCEC0C`; the accepted target edit/evidence note was applied, and scoped validator command `000000006993` passed with `ok: 1`.
- Confidence: strong for range, behavior, table dependency, owner/emitter route, and C++ disposition; capped below final-audit quality because no direct runtime caller and no debug-proven original helper name are available.

## Supporting Research

- Lifecycle/status notes: this is an active B001 research artifact for [UID:00032K]. Gate 1 passed, the accepted implementation callback was applied, and the report is ready for supervisor Gate 2 review. It has not been executed, archived, or moved. No validator-owned lifecycle command was run.
- Current MCP session: JSON-RPC endpoint `http://127.0.0.1:13337/mcp`; `initialize` returned `ida-pro-mcp` protocol `2025-06-18`; `idb_list` returned active database `supervisor_recovery_20260705` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Required lead report opened: `executed-b-agent-research/B001/000225-ChecksumTableHelpers.md`. It split the old aggregate [UID:000225] into exact children [UID:00032K] through [UID:00032N], created [UID:00032J] `Crc16`, attached the exact helpers and [UID:00027A] table data to that owner, and rejected MapPane, zlib, LodePNG, Crasher, and Monitor candidates.
- Current support docs opened or checked: target page [UID:00032K], sibling [UID:00032L], [UID:00032M], [UID:00032N], aggregate [UID:000225], table data [UID:00027A], source owner [UID:00032J], generated `auto-generated/NexusTK/util/Crc16.cpp`, MapPane checksum table [UID:00027N], and relevant by-file candidate snippets for MapPane, Zlib, LodePNG, Crasher, and Monitor.
- Wave2/Wave3 handling: no current recommendation depends on Wave2/Wave3 output. Generated C++ and auto-generated coverage/tracker rows were used only as current output/state evidence and cross-checked against MCP and current by-* docs.

## Target

- Target UID: `00032K`.
- Target path: `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; assignment row shows `85/90`, combined `87.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: report-only B-agent source-quality research.
- Current scores and parent state: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:00032J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00032J`.

## Current Target State

- Existing metadata: [UID:00032K] covers `0x0049bbf0-0x0049bc0d`, records `COMPLETION:85`, `CONFIDENCE:90`, owner/emitter [UID:00032J] `Crc16`, `RECONSTRUCTABLE:TRUE`, and a nonblank formal `RECONSTRUCTION_CPP CODE` block.
- Existing owner/emitter/reconstructable state: correct. The target is a source-authored CRC16 helper and emits through `by-file/Crc16.md` into `auto-generated/NexusTK/util/Crc16.cpp`.
- Existing C++/emitter state: source-ready enough for current score/emitter gate. Generated `Crc16.cpp` header observed in this pass shows `validator-command-id: 000000006959`, `validator-refreshed-at: 2026-07-05T10:43:05-04:00`, source by-file UID `00032J`, and UID00032K emitted before sibling helper bodies.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: no direct caller/runtime route is known; the exact original helper/function/table names are inferred rather than debug-proven; target metadata says `Nested:4`, which is stale for this exact leaf page because sibling exact helpers [UID:00032L], [UID:00032M], and [UID:00032N] all record `Nested:0`.
- Related target/support docs checked: [UID:000225], [UID:00032J], [UID:00032L], [UID:00032M], [UID:00032N], [UID:00027A], [UID:00027N], generated `Crc16.cpp`, and relevant generated tracker/coverage rows.
- Current artifact/lifecycle status: this report is an active research report in B001's `research/` folder. It now records the accepted implementation callback result and is ready for supervisor Gate 2 review; it has not run report execution.

## Heuristic / Inference Reanalysis And Validation

- Raw-helper role: current MCP still reports no IDA function object at `0x0049bbf0`, but scoped instruction query over `0x0049bbef-0x0049bc10` shows a clean raw callable body: `push ebp`, frame setup, 16-bit accumulator load from `[ebp+0Ch]`, high-byte table index, table XOR from `word_66D480`, input-word XOR from `[ebp+8]`, `pop ebp`, and `retn` at `0x0049bc0c`. This validates the existing `Crc16WordStep` role.
- Range and padding: current bytes from `0x0049bbef` show the preceding `0xcc` padding byte, target body bytes, `retn`, three `0xcc` bytes at `0x0049bc0d-0x0049bc10`, and the next helper's first `push ebp` at `0x0049bc10`. No split or range correction is needed for UID00032K.
- Table dependency: current `xrefs_to` and `xref_query` show `word_66D480` at `0x0066d480` has exactly two data xrefs, `0x0049bbff` and sibling `0x0049bc2c`; UID00032K owns the first. Current table bytes begin `00 00 21 10 42 20 63 30 ...`, matching the existing CRC-CCITT-style table documentation.
- Reachability: current `xrefs_to 0x0049bbf0`, `xref_query 0x0049bbf0 direction=to`, `find code_ref 0x0049bbf0`, `find data_ref 0x0049bbf0`, and bounded `find_bytes f0 bb 49 00` all returned no matches. The helper should remain documented as retained/raw and unreferenced in the current IDB, not caller-owned feature code.
- Source-facing name: `Crc16WordStep` remains the best current descriptive name. It is inferred from behavior and source-family context, not original symbol proof. The name is still preferable to raw IDA labels because the function has a clear role and the `Crc16` source owner already exists.
- Owner/source placement: [UID:00032J] `Crc16` remains the best owner. Current support docs and MCP table xrefs show the helper belongs with the word-buffer, byte-step, byte-buffer, and two-table data family, not with MapPane's separate table or neighboring Crasher/Monitor ranges.
- C++ disposition: the current formal target C++ preserves the observed argument order: input word from `[ebp+8]`, checksum from `[ebp+0Ch]`, table index `checksum >> 8`, shifted checksum, table word, input-word XOR, and 16-bit return. I do not recommend changing the block in this report.
- Leaf metadata blocker: the target's `Nested:4` is not supported after the aggregate split. UID00032K is a leaf exact helper; the four-helper family belongs to aggregate [UID:000225], while sibling exact pages record `Nested:0`. This is the only target metadata cleanup recommended now.

## Evidence Standards Used

- Direct IDA/MCP facts: current server health and IDB session state; exact lookup results for nearby addresses; bounded instruction query; raw bytes for target/padding/table opening; xrefs to target start and table addresses; code/data ref searches; bounded pointer-byte search.
- Documentation evidence: current target/support by-* docs, generated memory/file coverage, generated `Crc16.cpp`, and the required prior B001 aggregate report.
- Negative evidence: no IDA function at the raw helper start, no xrefs or code/data refs to the entry point, no raw little-endian pointer constant hit for the entry, no MapPane table xrefs to this table, and no feature/third-party/neighborhood candidate with a stronger source route.
- Confidence limits: exact original filename and helper spelling remain inferred; no live caller path exists in the current IDB; completion/confidence should therefore remain below near-final `95+`.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `initialize`, `tools/list`, `idb_list`, and `server_health` for session/schema/current IDB state.
  - `lookup_funcs` for `0x0049bbef`, `0x0049bbf0`, `0x0049bc0c`, `0x0049bc0d`, `0x0049bc10`, and `0x0049bcb0`.
  - `insn_query` with `start=0x0049bbef`, `end=0x0049bc10`, `count=50`, `max_scan_insns=50`, `include_disasm=true`, and `allow_broad=false`.
  - `get_bytes` for `0x0049bbef` size `34`, `0x0049bc0d` size `3`, and `0x0066d480` size `32`.
  - `xrefs_to` for `0x0049bbf0`, `0x0049bc0d`, `0x0066d480`, `0x0066d680`, `0x0066db50`, and `0x0049bc10`.
  - `xref_query` for `0x0049bbf0` to-any and `0x0066d480` to-data with count `20`.
  - `find code_ref` and `find data_ref` for `0x0049bbf0`; `find code_ref` for sibling `0x0049bc10`.
  - `find_bytes` for little-endian pointer patterns `f0 bb 49 00` and `10 bc 49 00`, each with limit `20`.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`
  - `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md`
  - `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`
  - `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md`
  - `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md`
  - `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md`
  - `by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md`
  - `by-file/Crc16.md`, plus targeted candidate snippets in `by-file/MapPane.md`, `by-file/Zlib.md`, `by-file/LodePNG.md`, `by-file/Crasher.md`, and `by-file/Monitor.md`
  - `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-file-coverage.md`, and `auto-generated/NexusTK/util/Crc16.cpp`
  - Required prior lead report `executed-b-agent-research/B001/000225-ChecksumTableHelpers.md`
- Search terms used before finalizing:
  - `00032K`, `0x0049bbf0`, `Crc16WordStep`, `Crc16 Word Step`, `word_66D480`, `ChecksumTableHelpers`, `000225`, `Crc16`, `kCrc16WordTable`, `Checksum`, `0x0066d480`, and `0x0066db50`.
- Negative checks performed:
  - No active report for UID00032K was found under B-agent research folders.
  - No direct xrefs, code refs, data refs, or little-endian pointer bytes to `0x0049bbf0` were found by the bounded current MCP checks.
  - MapPane table `0x0066db50` has eight MapPane-heavy data xrefs, while `word_66D480` has only the Crc16 word-step/word-buffer refs.
- Failed, unavailable, or intentionally skipped checks and why:
  - `py_eval` is not present in the active `tools/list` schema, so it was not used.
  - Decompilation was not used for UID00032K because `lookup_funcs` proves the entry is not an IDA function object. Bounded instruction query and bytes are the correct exact-range evidence.
  - No broad unbounded listing/search/callgraph/type/batch-analysis calls were run.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID00032K is an exact leaf raw callable helper at `0x0049bbf0-0x0049bc0d`, not an aggregate with nested children. | Strong | Current MCP `insn_query` and sibling `Nested:0` checks; target had `Nested:4`. | Target metadata header. | incorporate | applied |
| C2 | The helper updates a 16-bit accumulator from a 16-bit input word using `(checksum >> 8)` as the `word_66D480` index. | Strong | Current instruction query and bytes; target disassembly already records the same flow. | Target `Behavior`, `IDA Evidence`, or new refresh note. | already-present | already-present |
| C3 | `0x0049bbf0` is not a modeled IDA function and has no current direct xrefs/code_refs/data_refs/pointer hits. | Strong | Current `lookup_funcs`, `xrefs_to`, `xref_query`, `find`, and `find_bytes` results. | Target `IDA Evidence` refresh note. | incorporate | applied |
| C4 | `word_66D480` at `0x0066d480` has exactly two data xrefs: `0x0049bbff` from UID00032K and `0x0049bc2c` from UID00032L. | Strong | Current `xrefs_to` and `xref_query` to `0x0066d480`. | Target `IDA Evidence` refresh note; support docs already present. | incorporate | applied |
| C5 | The current owner/emitter [UID:00032J] `Crc16` remains the best source placement. | Strong | Prior aggregate report, current by-file Crc16, exact helper/table docs, current MCP xrefs. | Target `Ownership Notes`; support docs already present. | already-present | already-present |
| C6 | MapPane's checksum table is separate: `0x0066db50` has eight MapPane-side xrefs and should not absorb UID00032K. | Strong | Current `xrefs_to 0x0066db50`; MapPane table doc [UID:00027N]. | Target negative evidence or support docs already present. | already-present | already-present |
| C7 | Zlib, LodePNG, Crasher, and Monitor remain rejected as direct owners for UID00032K. | Strong | Current support docs and aggregate report; target has no caller/state/algorithm bridge to those candidates. | Target `Ownership Notes`; support docs already present. | already-present | already-present |
| C8 | Formal C++ should remain the existing `Crc16WordStep` block; no body/source-route change is recommended in this report. | Strong | Current instructions and generated `Crc16.cpp` output. | Target `RECONSTRUCTION_CPP CODE` block. | already-present | already-present |
| C9 | Score should remain `85/90`; the safe current improvement is metadata/evidence freshness, not score inflation. | Medium-strong | Current evidence resolves target behavior but does not produce a caller path or original-name proof; by-memory 95+ gate remains far above current state. | Target score metadata and score rationale. | not-applicable | excluded-with-reason: no score change accepted or applied because caller/original-name blockers remain. |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - Current MCP shows `0x0049bbf0` is not a function object but disassembles as a clean raw helper with prologue/body/return.
  - Current bytes confirm the exact body is bounded by alignment padding before and after the helper.
  - Current xrefs prove UID00032K's table dependency is the `word_66D480` read at `0x0049bbff`.
  - Current generated C++ shows UID00032K emits through `auto-generated/NexusTK/util/Crc16.cpp` under by-file UID `00032J`.
- Corroborating documentation/generated-report evidence:
  - Target page already documents exact disassembly, behavior, no modeled function status, negative xrefs, owner [UID:00032J], and formal C++.
  - Aggregate [UID:000225] and executed B001 report document the exact split, padding, source-family owner, and rejected candidates.
  - Table page [UID:00027A] documents the two Crc16 lookup tables and their exact xrefs.
- Strongest inference chain and why it is sufficient:
  - The body, table xref, sibling word-buffer body, table page, and Crc16 source owner form a coherent utility source unit. No candidate feature owner has direct caller/data evidence. That supports keeping owner/emitter/C++ and only cleaning the stale leaf metadata.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs` reports `0x0049bbf0`, `0x0049bc0c`, and `0x0049bc0d` are not functions; `0x0049bc10` is also not a function; `0x0049bcb0` resolves to `sub_49BCB0` size `0xe`.
  - `insn_query 0x0049bbef-0x0049bc10` returns `align 10h` at `0x49bbef`, target instructions from `0x49bbf0` through `retn` at `0x49bc0c`, and `align 10h` at `0x49bc0d`.
- Data/table/padding facts:
  - `get_bytes 0x0049bbef size 34` returns `cc 55 8b ec ... 5d c3 cc cc cc 55`, proving one preceding padding byte, target bytes, `retn`, three following padding bytes, and next helper prologue.
  - `get_bytes 0x0049bc0d size 3` returns `cc cc cc`.
  - `get_bytes 0x0066d480 size 32` returns the table opening bytes for words `0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef`.
- Xref facts:
  - `xrefs_to 0x0049bbf0` reports no cross-references.
  - `xref_query 0x0049bbf0 direction=to` reports total `0`.
  - `xrefs_to 0x0066d480` reports `0x49bbff` and `0x49bc2c`.
  - `xrefs_to 0x0066d680` reports `0x49bc5f` and `0x49bc92`.
  - `xrefs_to 0x0066db50` reports eight MapPane-side refs: `0x508601`, `0x508616`, `0x50c094`, `0x50c0ad`, `0x50c0c3`, `0x50c10f`, `0x513941`, and `0x513956`.
- Vtable/global/type facts:
  - No vtable, class, or instance field evidence is involved. The helper is file-level utility code attached through a by-file source owner.
- Negative IDA facts:
  - Current `find code_ref 0x0049bbf0`, `find data_ref 0x0049bbf0`, and `find_bytes f0 bb 49 00` all returned zero matches.
  - Sibling `0x0049bc10` also had zero current xrefs/code refs/pointer-byte hits in this pass, supporting the retained raw helper-family interpretation.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049bbf0-0x0049bc0d` | [UID:00032K] `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md` | Word-step CRC16 helper | TRUE | [UID:00032J] `Crc16` | `85/90` | Target; leaf metadata cleanup recommended. |
| `0x0049bc10-0x0049bc47` | [UID:00032L] `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md` | Word-buffer CRC16 helper | TRUE | [UID:00032J] `Crc16` | `86/90` | Sibling; supports word-step naming/route. |
| `0x0049bc50-0x0049bc70` | [UID:00032M] `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md` | Byte-step CRC16 helper | TRUE | [UID:00032J] `Crc16` | `85/90` | Sibling; separate byte table. |
| `0x0049bc70-0x0049bca9` | [UID:00032N] `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md` | Byte-buffer CRC16 helper | TRUE | [UID:00032J] `Crc16` | `86/90` | Sibling; separate byte table. |
| `0x0049bbf0-0x0049bca9` | [UID:000225] `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md` | Non-emitting aggregate/index | FALSE | NONE | `88/91` | Container only; should not re-own UID00032K. |
| `0x0066d47c-0x0066d880` | [UID:00027A] `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md` | Backing Crc16 table data | TRUE | [UID:00032J] `Crc16` | `88/92` | Direct table dependency. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0049bbf0` | no xrefs, no code refs, no data refs, no `f0 bb 49 00` pointer-byte hits | Raw retained helper start; no current caller-owned route. |
| `0x0049bbff` | data xref from UID00032K to `0x0066d480` / `word_66D480` | Target's direct table read. |
| `0x0066d480` | data refs `0x0049bbff`, `0x0049bc2c` | Word-step and word-buffer table. |
| `0x0066d680` | data refs `0x0049bc5f`, `0x0049bc92` | Byte-step and byte-buffer table; sibling evidence. |
| `0x0066db50` | eight MapPane-side data refs | Separate MapPane checksum table; not UID00032K's owner. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target [UID:00032K] already records exact disassembly, behavior, owner [UID:00032J], formal C++ block, and negative entrypoint xref evidence.
  - [UID:00032J] `Crc16` records the narrow `NexusTK/util/` owner, helper/table contents, generated C++ emission state, and rejected owner boundaries.
  - [UID:000225] aggregate records the split into four exact children, internal padding, and non-emitting index role.
  - [UID:00027A] records the backing table bytes, xrefs, duplicate two-table shape, and Crc16 owner.
- Existing docs that are stale, incomplete, or contradicted:
  - The target header `Nested:4` is stale for an exact leaf helper. It appears to describe the old aggregate family, not UID00032K itself.
  - No contradiction was found in target owner/emitter/reconstructable/C++ state.
- Generated/coverage report state:
  - Research tracker row for UID00032K still shows reports `0`, which this report resolves once supervisor validates and executes it later.
  - Generated memory coverage and generated `Crc16.cpp` show UID00032K as coded/emitting through [UID:00032J].
  - Generated `Crc16.cpp` observed header: `validator-command-id: 000000006959`, `validator-refreshed-at: 2026-07-05T10:43:05-04:00`.

## Ranked Ownership Analysis

### 1. [UID:00032J] `Crc16`

- Evidence for: current target and support docs route the four exact helpers and table data through this owner; current MCP table xrefs show UID00032K and sibling UID00032L exclusively consume `word_66D480`; generated C++ emits UID00032K under the Crc16 by-file root.
- Evidence against: no direct caller path or original filename symbol proves the exact source filename.
- Decision: accepted. The remaining uncertainty affects exact original spelling and final-audit confidence, not the current direct owner/emitter recommendation.

### 2. Parent-blank raw helper / no owner

- Evidence for: no direct xrefs/callers to the raw entry point exist in current MCP.
- Evidence against: the helper has a coherent source family, table dependency, current by-file owner, and emitted generated output. Leaving it ownerless would discard a well-supported source-unit relationship.
- Decision: rejected. Use Crc16 as owner/emitter; keep the no-caller caveat documented.

### 3. [UID:000225] `ChecksumTableHelpers` aggregate

- Evidence for: it covers the broad address family containing UID00032K.
- Evidence against: current docs classify it as a non-emitting aggregate/index; exact child pages carry the source-authored helper bodies.
- Decision: rejected as direct owner/emitter. Keep it as cross-reference/container.

### 4. [UID:0000L3] `MapPane` and [UID:00027N] MapPane checksum table

- Evidence for: MapPane has a similar CRC-style table opening at `0x0066db50`.
- Evidence against: current MCP shows `0x0066db50` has eight MapPane-side refs, while UID00032K uses `word_66D480`; no caller/xref bridge connects MapPane to `0x0049bbf0`.
- Decision: rejected. MapPane's checksum table is a separate source-family route.

### 5. [UID:0000PC] `Zlib` / [UID:0000KW] `LodePNG`

- Evidence for: those source families include checksum concepts.
- Evidence against: current support docs place zlib/LodePNG checksum code in separate third-party/source families, and UID00032K is a 16-bit CRC-CCITT-style helper using project data at `0x0066d480`.
- Decision: rejected.

### 6. Neighboring [UID:0000II] `Crasher` / [UID:0000LI] `Monitor`

- Evidence for: address neighborhood around the old broad aggregate.
- Evidence against: current bytes show padding boundaries; current docs assign Crasher before `0x0049bbef` and critical-section/Monitor helpers after the checksum family. No shared state, table refs, or caller route exists.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new owner is needed. Use existing [UID:00032J] `by-file/Crc16.md` with projected path `NexusTK/util/`.
- Likely full contents: existing Crc16 source root contains UID00032K, UID00032L, UID00032M, UID00032N, and UID00027A.
- Candidate related items that belong: the four exact helper bodies and two-table data page.
- Candidate related items rejected: MapPane checksum table [UID:00027N], zlib/LodePNG checksum sources, Crasher, Monitor/critical-section helpers, and the non-emitting aggregate as source body.
- Standalone, narrow, or broad source-file inference: narrow utility file.

## Source Placement

- Recommended source file/class/global/module placement: keep UID00032K as a file-level static helper emitted through [UID:00032J] `Crc16`, projected to `NexusTK/util/Crc16.cpp`.
- Why this placement fits source-tree and subsystem context: the helper is not a class method, has no `this` pointer, touches only stack arguments and the Crc16 lookup table, and belongs with the paired word/byte helper family and static table declarations.
- Rejected placements and why: MapPane has its own table and caller refs; zlib/LodePNG are third-party checksum families; Crasher and Monitor are address-neighbor source families separated by padding and semantics.
- Remaining placement uncertainty, if any: exact original source file and helper names are inferred. This uncertainty does not justify moving the item out of Crc16 under current evidence.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: UID00032K should remain `0x0049bbf0-0x0049bc0d`. Current bytes show one preceding `0xcc` at `0x0049bbef-0x0049bbf0`, target body from `0x0049bbf0` through `retn` at `0x0049bc0c`, and `0x0049bc0d-0x0049bc10` as three `0xcc` bytes before the next helper.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no child creation, split, merge, or reclassification is recommended. The target is already an exact child.
- Padding/table/data/code distinctions: target range is source-authored code; adjacent `0xcc` bytes are alignment padding; table data belongs to [UID:00027A].
- Parent/container impact: [UID:000225] should remain the non-emitting aggregate/index. UID00032K should be leaf metadata `Nested:0`, not `Nested:4`.

## Negative Evidence Summary

- No IDA function object exists at `0x0049bbf0`; this blocks decompiler/function-prototype proof and supports raw-helper documentation.
- No xrefs, code refs, data refs, or little-endian pointer-byte hits to `0x0049bbf0` were found in the current MCP pass; no direct runtime caller can be claimed.
- Consumer/read xrefs to the table do not prove MapPane, zlib, LodePNG, Crasher, or Monitor ownership. The table xref set for `word_66D480` is confined to Crc16 word helpers, and MapPane's similar table has a distinct xref set.
- Exact original helper name, exact original source filename, and exact table symbol spelling are not proven. The current descriptive names remain inferred but source-facing.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: keep `Crc16WordStep(unsigned short value, unsigned short checksum)` and `kCrc16WordTable` as descriptive source-facing names in documentation/generated source.
- Evidence for each proposed name/type/comment: instruction order proves `[ebp+8]` is the input word, `[ebp+0Ch]` is the running checksum, and the return is the low 16-bit `AX` value after the table/input XOR.
- Items intentionally left unchanged and why: no IDA DB rename/type/comment changes are requested because the target is not a modeled function and original symbol proof is absent.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is `RECONSTRUCTABLE:TRUE`, emits through a valid by-file route [UID:00032J], has combined score `(85 + 90) / 2 = 87.5`, and already has a formal C++ block.
- Recommended code: keep the target's existing formal `RECONSTRUCTION_CPP CODE` insertion text exactly as follows:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern const unsigned short kCrc16WordTable[256];
extern const unsigned short kCrc16ByteTable[256];

static unsigned short Crc16WordStep(unsigned short value, unsigned short checksum)
{
    const unsigned int tableIndex = checksum >> 8;
    return static_cast<unsigned short>((checksum << 8) ^ kCrc16WordTable[tableIndex] ^ value);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable. This is NexusTK-owned source-authored utility code, not a staged third-party embed.
- Reason it preserves exact original behavior: the code uses the high byte of the incoming checksum as the 256-entry word-table index, shifts the checksum left eight bits, XORs the table word and input word, truncates to 16 bits, and returns the value in the source-level equivalent of `AX`.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a small `static unsigned short` file-local helper beside a static CRC table is a plausible utility-source shape for an unexported raw helper with no current external references.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `Crc16WordStep`, `value`, `checksum`, `tableIndex`, and `kCrc16WordTable` replace raw address/table labels.
- Naming/coding style convention used and evidence for consistency: matches existing `Crc16.cpp` generated sibling helpers and table names.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes recommended:
  - Change only the target metadata line `*** Nested:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***` to `*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`.
  - Add a 2026-07-05 B001 MCP refresh note to the target page recording current session `supervisor_recovery_20260705`, exact no-function/no-xref/no-pointer-hit evidence, current `word_66D480` xrefs, and the generated `Crc16.cpp` header observed at command `000000006959`.
  - Leave score `85/90`, `CANONICAL_OWNER:00032J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00032J`, and the formal C++ block unchanged.
- Exact parent assignments recommended: keep [UID:00032J] `Crc16`.
- Exact items left no-owner/non-emitting and why: none for the target. [UID:000225] remains the non-emitting aggregate by current docs and is outside the target edit.
- Exact future work, if any, outside this assignment scope: none required for UID00032K. A future broader Crc16 pass could revisit original naming only if new symbols or caller evidence appear.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`.
- Exact report facts to incorporate:
  - Current 2026-07-05 MCP session `supervisor_recovery_20260705` confirms `0x0049bbf0` remains not a function, has no xrefs/code_refs/data_refs/pointer-byte hits, and disassembles as the exact word-step helper.
  - Current bytes confirm `0x0049bc0d-0x0049bc10` is `cc cc cc` padding and the next helper starts at `0x0049bc10`.
  - Current `word_66D480` xrefs remain exactly `0x0049bbff` and `0x0049bc2c`.
  - Current generated `auto-generated/NexusTK/util/Crc16.cpp` has validator command `000000006959` and includes UID00032K's formal helper body.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Change `Nested` from `4` to `0`.
  - Keep `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:00032J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00032J`, and the existing formal C++ block.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve that no direct caller/runtime route is currently known.
  - Preserve rejected MapPane, zlib/LodePNG, Crasher, and Monitor candidates.
  - Preserve that exact original helper/source names are inferred.

Suggested target insertion under `## IDA Evidence` or a new `## 2026-07-05 B001 Standalone Refresh` subsection:

```markdown
- 2026-07-05 B001 standalone source-quality refresh: current IDA MCP session `supervisor_recovery_20260705` keeps `0x0049bbf0` outside the modeled function table, disassembles `0x0049bbf0-0x0049bc0d` as the same word-step helper, confirms `0x0049bc0d-0x0049bc10` as `cc cc cc` padding, reports no xrefs/code_refs/data_refs or little-endian pointer hits to `0x0049bbf0`, and reports `word_66D480` refs exactly at `0x0049bbff` and sibling `0x0049bc2c`. Generated `auto-generated/NexusTK/util/Crc16.cpp` was observed at validator command `000000006959`, refreshed `2026-07-05T10:43:05-04:00`, with UID00032K emitted through [UID:00032J] `Crc16`.
```

## Recommended Support Doc Changes

- Applicable support paths: [UID:00032J] `by-file/Crc16.md`, [UID:000225] aggregate, [UID:00027A] table data, generated coverage/tracker rows, and generated C++ were checked.
- Exact report facts to incorporate: no support-doc edit is required for this narrow target pass because the owner, split, table dependency, generated C++ route, and rejected candidates are already present at same-or-greater detail.
- Metadata/link/score/coverage/source-placement changes: none recommended outside the target page. Auto-generated tracker/coverage rows should be refreshed by the scoped target validator after target implementation; do not manually edit generated files.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:85`, `CONFIDENCE:90`, `Nested:4`, owner/emitter [UID:00032J], reconstructable true, nonblank formal C++.
- Recommended score/metadata: keep `COMPLETION:85`, keep `CONFIDENCE:90`, change `Nested:4` to `Nested:0`, and keep owner/emitter/reconstructable/C++ unchanged.
- Score rationale and reason not higher/lower:
  - Not lower: current MCP reconfirms exact bytes, behavior, table dependency, owner route, no-entrypoint-ref state, and generated emission.
  - Not higher: no direct runtime caller/source route or debug-proven original helper name was found; the page is useful and source-ready but not final-audit quality.
- Score-improvement attempt:
  - Function modeling blocker: checked `lookup_funcs`; still not a function, so no decompiler/prototype improvement is safe.
  - Caller/reachability blocker: checked xrefs, code refs, data refs, and pointer bytes to `0x0049bbf0`; no hits.
  - Source owner blocker: checked Crc16 docs, aggregate report, table xrefs, MapPane table xrefs, and third-party/neighborhood candidates; Crc16 remains best and already applied.
  - C++ blocker: checked formal block and generated C++; no body change is needed.
  - Metadata blocker: found stale `Nested:4`; recommend exact repair.
- Metadata fields to change or leave unchanged: change only `Nested`; all other target metadata should remain unchanged.

## Open Questions With Attempted Resolution

- Open question: original helper/source filename spelling.
  - Evidence checked: current by-file Crc16 docs, generated output, prior aggregate report, MCP xrefs and lookup. No debug/source symbol evidence appears.
  - Best supported resolution or inference: keep `Crc16WordStep` under `Crc16`.
  - Remaining impact: caps confidence below final-audit quality; does not block current owner/emitter/C++.
- Open question: direct runtime caller route.
  - Evidence checked: current `xrefs_to`, `xref_query`, `find code_ref`, `find data_ref`, and pointer-byte search for `0x0049bbf0`; also sibling `0x0049bc10` checks for family consistency.
  - Best supported resolution or inference: no current direct caller route; helper appears retained/raw.
  - Remaining impact: keep no-caller caveat and do not attach to a feature owner.
- Open question: why `Nested:4` remains on the target.
  - Evidence checked: target metadata, sibling exact helper metadata, aggregate split docs.
  - Best supported resolution or inference: stale metadata from the old four-helper aggregate context.
  - Remaining impact: implementation-ready metadata repair to `Nested:0`.

## Follow-Up Actions

- Supervisor actions: Gate 2 review this implementation callback result.
- A-agent actions: none.
- B001 future research actions: none for UID00032K unless new symbols/caller evidence appears.

## Confidence

- Recommendation confidence: strong.
- Score confidence: medium-strong; `85/90` remains conservative and defensible.
- Remaining uncertainty: exact original name and caller route remain unavailable after current evidence checks.

## Validator Results

- Commands run: `python .\tools\validator.py --mode file --file by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md --apply --queue-timeout 240` from `source-3/project-documentation`.
- Results: command `000000006993`, timestamp `2026-07-05T11:25:23-04:00`, exit code `0`, `ok: 1`.
- Validator apply notes: inserted UID links for [UID:00032L] and [UID:00032J] in the target page, updated projected stats, and reported `generated_refresh: deferred`.
- Any unresolved validator warnings/errors: none observed in this scoped run.

## Changed Files

- Created during report-only Gate 1 pass: `tools/leaser/Agents/Agent-B001/research/00032K-Crc16WordStep-source-quality.md`.
- Modified during implementation callback: `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`.
- Modified during implementation callback: `tools/leaser/Agents/Agent-B001/research/00032K-Crc16WordStep-source-quality.md`.
- Validator-owned apply side effect: `project-level/-auto-completion-stats.md` projected path completion section updated.
- Validator-owned command-state side effect: `tools/validator.ini` updated by the requested validator run.
- Renamed: none.
- Report execution: not run. B001 did not run `execute_report`, dry-run variants, registry lifecycle commands, manual report moves, or any equivalent report execution/archive command.

## Implementation Tracking Checklist

Initial report-only pass, Gate 2 status:
- [x] Supervisor validation required before implementation: applied; Gate 1 accepted report SHA256 `2ED38E80CCB4929FF6C0A5273B4868940BB043283A9B928B5F8E541CD1DCEC0C`.
- [x] Target/support docs to update: applied target-only update to `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`; support docs excluded-with-reason because they already contain the owner/split/table/candidate evidence at same-or-greater detail.
- [x] Current target state and actual evidence checked recorded: applied through the 2026-07-05 MCP refresh facts in the target page.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: applied; C1/C3/C4 are `applied`, C2/C5/C6/C7/C8 are `already-present`, and C9 is `excluded-with-reason`.
- [x] Metadata/score changes to apply: applied `Nested:4` to `Nested:0`; `85/90` already-present and kept unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: already-present in the report; caller route, function modeling, source owner, C++ body, and original naming were checked, and only `Nested` metadata repair was applied.
- [x] Owner/emitter/reconstructable changes to apply: excluded-with-reason because no owner/emitter/reconstructable change was accepted; [UID:00032J], `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00032J` remain unchanged.
- [x] Split/rename/new-child changes to apply: excluded-with-reason because the target is already an exact child and no split/rename/new-child change was accepted.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: already-present and preserved; no split/rename/IDA DB changes were accepted.
- [x] First-draft C++ or no-code proof to apply: already-present; the existing formal C++ block was kept unchanged.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: excluded-with-reason because this is NexusTK-owned utility code, not a third-party embed.
- [x] Exact target/support doc facts to incorporate at report-level detail: applied current MCP no-function/no-xref/bytes/table-xref/generated-output refresh note to the target page.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: already-present and preserved, including no direct caller, original-name inference, and rejected MapPane/zlib/LodePNG/Crasher/Monitor owners.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: excluded-with-reason because no active Wave2/Wave3 evidence was used.
- [x] Open questions to close or document as evidence-backed unresolved: already-present and preserved; original helper spelling and caller route remain evidence-backed unresolved.
- [x] Validators to run: applied; scoped validator command `000000006993` completed with exit code `0` and `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: excluded-with-reason for manual edits; validator reported `generated_refresh: deferred`, and no manual generated/tracker edit was made.

Implementation callback pass:
- [x] Supervisor Gate 1 accepted report SHA256 `2ED38E80CCB4929FF6C0A5273B4868940BB043283A9B928B5F8E541CD1DCEC0C`; scope limited to target page plus this report checklist/ledger.
- [x] Target lease acquired immediately before editing: `python leaser.py Agent-B001 lease E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0049bbf0-0x0049bc0d.Crc16WordStep.md` returned `Success`.
- [x] Target metadata applied: `Nested` changed from `4` to `0`.
- [x] Target score/owner/emitter/reconstructable metadata already present and kept unchanged: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:00032J`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00032J`.
- [x] Existing formal `RECONSTRUCTION_CPP CODE` block already present and kept unchanged.
- [x] 2026-07-05 MCP refresh facts applied to the target page at report-level detail, including session/status/imagebase, no modeled function, bounded helper disassembly, padding/next-helper bytes, negative entrypoint refs/pointers, exact `word_66D480` refs, and generated `Crc16.cpp` command/refreshed/emitter state.
- [x] No-direct-caller, original-name-inference, and rejected MapPane/zlib/LodePNG/Crasher/Monitor alternatives were already present and preserved.
- [x] Scoped validator run completed: command `000000006993`, timestamp `2026-07-05T11:25:23-04:00`, exit code `0`, `ok: 1`.
- [x] Target lease released immediately after the edit/validator batch: `python leaser.py Agent-B001 unlease E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0049bbf0-0x0049bc0d.Crc16WordStep.md` returned `Success`.
- [x] No support by-* docs, generated files, `-coverage-report.md` files, lifecycle/archive files, or report-execution commands were manually edited or run during this callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000007005","destination_path":"executed-b-agent-research/B001/00032K-Crc16WordStep-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00032K-Crc16WordStep-source-quality.md","timestamp":"2026-07-05T11:32:27-04:00","uid":"00032K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
