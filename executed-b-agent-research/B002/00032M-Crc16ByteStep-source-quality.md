** TARGET-REPORT-UID:00032M **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00032M Crc16ByteStep Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00032M] `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md` attached to [UID:00032J] `by-file/Crc16.md` with `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00032J`, and the existing formal `Crc16ByteStep` C++ block.
- Final disposition: supervisor Gate 1 passed for SHA256 `56F19D04DD56A63E9EFFA9FFE086ED07100765872E95BD924B4784303B288AA7`; the accepted target-only callback has been applied. Target score is now `88/91`, owner/emitter/source placement are unchanged, and support docs remain untouched by callback scope.
- Required action: supervisor Gate 2 review of the target page, this updated report ledger/checklist, and scoped validator result.
- Confidence: high for exact behavior, range, table dependency, and `Crc16` ownership; not final-audit because the original function name, source filename, and runtime reachability remain inferred.

## Supporting Research

- Lifecycle/status notes: this report remains an active B002 research artifact at `tools/leaser/Agents/Agent-B002/research/00032M-Crc16ByteStep-source-quality.md`. It passed supervisor Gate 1 at SHA256 `56F19D04DD56A63E9EFFA9FFE086ED07100765872E95BD924B4784303B288AA7`, then received a target-only implementation callback. It has not been executed or archived.
- Current assignment: UID `00032M`, target `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`, queue row `auto-generated/-ag-research-tracker.md` -> by-memory not-covered reconstructable.
- Required lead report opened: `executed-b-agent-research/B001/000225-ChecksumTableHelpers.md`.
- Current IDA MCP session used: `supervisor_recovery_20260705`, `NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, server status `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- MCP output discipline: used `initialize`, `tools/list`, `idb_list`, `server_health`, and narrow exact-address calls only. The current schema does not expose `py_eval`; no broad search, batch analysis, type scan, or unbounded disassembly was run.

## Target

- Target UID: `00032M`.
- Target path: `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md:1570`, `85/90`, combined `87.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: post-Gate-1 implementation callback complete; ready for supervisor Gate 2 review.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00032J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00032J`, formal C++ present.

## Current Target State

- Existing metadata: target range `0x0049bc50-0x0049bc70`, score `88/91`, owner [UID:00032J] `Crc16`, emitter [UID:00032J] `Crc16`, `Nested:0`, reconstructable source-authored helper body.
- Existing owner/emitter/reconstructable state: already attached to the narrow `NexusTK/util/Crc16.cpp` by-file owner created by B001-019, with generated output in `auto-generated/NexusTK/util/Crc16.cpp`.
- Existing C++/emitter state: the target has a formal `RECONSTRUCTION_CPP CODE` block for `static unsigned short Crc16ByteStep(unsigned char value, unsigned short checksum)`. Generated output refreshed at command id `000000006959` on `2026-07-05T10:43:05-04:00` and includes the target code.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: no functional contradiction found. The remaining blockers are exact original identifier/source filename proof and absent runtime caller/reachability evidence. The accepted callback replaced the stale "at least 85" score wording with the current `88/91` rationale and explicit not-`95+` cap.
- Related target/support docs checked: `by-file/Crc16.md`, parent aggregate `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md`, sibling byte-buffer page `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md`, word sibling pages `00032K` and `00032L`, table data page `00027A`, negative table candidate `00027N`, neighboring `Crasher` and critical-section pages, generated C++ output, generated coverage/tracker rows, and B001 aggregate report.
- Current artifact/lifecycle status: callback implementation and scoped validation are complete; this artifact is ready for supervisor Gate 2 review.

## Heuristic / Inference Reanalysis And Validation

- Helper role: current MCP disassembly at `0x0049bc50` shows a clean raw prologue/body/return sequence outside IDA function modeling. It loads the 16-bit checksum from `[ebp+0Ch]`, copies it to `ecx`, shifts `eax` left by eight, shifts `ecx` right by eight, xors `AX` with `word_66D680[ecx*2]`, zero-extends the byte input from `[ebp+8]`, xors that byte into `AX`, and returns. The best source-facing description remains a one-byte CRC16 step.
- Signature and argument order: `[ebp+8]` is zero-extended as a byte and `[ebp+0Ch]` is zero-extended as the 16-bit checksum. The existing `Crc16ByteStep(unsigned char value, unsigned short checksum)` order matches the observed stack layout and the sibling word-step convention.
- Table dependency: current xrefs to `0x0066d680` are exactly `0x0049bc5f` in this target and `0x0049bc92` in the byte-buffer helper. That supports keeping `kCrc16ByteTable` as the table source dependency for the byte helper pair.
- Range and padding: current `get_bytes` confirms nine `0xcc` bytes at `0x0049bc47-0x0049bc50`, then the exact `0x20` byte target body at `0x0049bc50-0x0049bc70`. The byte-buffer helper starts immediately at `0x0049bc70`.
- Decompiler status: current `decompile 0x0049bc50` fails because the raw start is not an IDA function. This supports documenting raw disassembly rather than treating the lack of Hex-Rays output as uncertainty about behavior.
- Entrypoint reachability: current `lookup_funcs` reports `0x0049bc50` and `0x0049bc70` are not functions; `xrefs_to 0x0049bc50` and `xrefs_to 0x0049bc70` both return zero xrefs. A capped `find_bytes` for the little-endian absolute pointer pattern `50 BC 49 00` found no matches. The older B001 raw direct-call/jump scan remains useful historical support, but the current pass did not repeat it because the live schema lacks `py_eval` and broad raw scanning would violate the MCP discipline.
- Source placement validation: the target remains better owned by `Crc16` than by MapPane, zlib, LodePNG, Crasher, or Monitor. The helper uses the `0x0066d680` CRC16 table pair, while MapPane's similar `0x0066db50` table has eight separate MapPane xrefs and no link to this entrypoint.
- Rejected alternatives: MapPane table ownership, third-party zlib/LodePNG ownership, Crasher adjacency, and Monitor/critical-section adjacency remain rejected. Parent-blank/no-emitter is also weaker because the child and parent clear the current gate and generated output already routes through `Crc16`.
- Unresolved issues: no original symbol/PDB/source path proves `Crc16ByteStep`, `Crc16`, or `kCrc16ByteTable` as exact original names. No direct caller proves live runtime reachability. Those limitations cap confidence below final-audit quality and argue against `95+` scoring.

## Evidence Standards Used

- Evidence types used: current IDA MCP `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `disasm`, `get_bytes`, `get_int`, `find_bytes`, and `decompile`; current by-* docs; generated tracker and coverage rows; generated C++ output; required B001 aggregate report; negative support-doc comparisons.
- Strength: the behavior, exact range, table reference, and non-function status are direct MCP facts from the current IDB. The source-facing names and file placement are inference backed by sibling helper structure, table exclusivity, and negative owner evidence.
- Limits: the current MCP schema does not expose `py_eval`, so the current pass did not perform an IDB-wide custom raw branch scan. That does not block this report because exact xrefs, function modeling, pointer-pattern search, and prior B001 raw-scan evidence all support the same non-reachable raw-helper conclusion.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list`: active session `supervisor_recovery_20260705`, not analyzing.
  - `server_health`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis and Hex-Rays ready.
  - `lookup_funcs` for `0x0049bc50`, `0x0049bc70`, `0x0049bcb0`, and `0x0066d680`: target and byte-buffer starts are not functions; next modeled function is `sub_49BCB0` at `0x0049bcb0`, size `0xe`; table address is not a function.
  - `xrefs_to` for `0x0049bc50`, `0x0049bc70`, and `0x0066d680`: zero entrypoint xrefs for both raw starts; table xrefs exactly `0x49bc5f` and `0x49bc92`.
  - `disasm 0x0049bc50 max_instructions 24`: target raw body plus beginning of byte-buffer successor; `0x0049bc5f` references `word_66D680`.
  - `get_bytes` for `0x0049bc47`, `0x0049bc50`, and `0x0049bca9`: confirms preceding padding, exact target bytes, and successor critical-section padding.
  - `find_bytes` for `50 BC 49 00`: zero absolute pointer-pattern matches to `0x0049bc50`.
  - `decompile 0x0049bc50`: failed at `0x49bc50`, expected because the raw start is not an IDA function.
  - `xrefs_to` for `0x0066d480`, `0x0066d680`, and `0x0066db50`: CRC16 word table xrefs are `0x49bbff` and `0x49bc2c`; byte table xrefs are `0x49bc5f` and `0x49bc92`; MapPane table xrefs are eight separate sites under `0x507c90`, `0x50c040`, and unmodeled raw sites.
  - `get_int` and `get_bytes` table sampling: `0x0066d680` begins with the same little-endian CRC/CCITT-style words as `0x0066d480`; last sampled words at `0x0066d870-0x0066d87e` match the documented tail.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target: `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`.
  - Support: `by-file/Crc16.md`, `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md`, `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md`, `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md`, `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`, `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md`.
  - Negative candidates: `by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md`, `by-memory/0x0049bae0-0x0049bbef.Crasher.md`, `by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md`.
  - Generated: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-file-coverage.md`, `auto-generated/NexusTK/util/Crc16.cpp`.
  - Old reports: required `executed-b-agent-research/B001/000225-ChecksumTableHelpers.md`.
  - Active reports search: `rg -l "00032M|0049bc50|Crc16ByteStep|word_66D680|ChecksumTableHelpers" tools/leaser/Agents -g "research/*.md" -g "research/**/*.md"` returned no active research reports.
  - Executed reports search: the same exact-target terms under `executed-b-agent-research` returned only `executed-b-agent-research/B001/000225-ChecksumTableHelpers.md`.
  - Broader docs search found only `by-file/Crc16.md` and coverage rows for exact target/source-family terms outside the already opened support docs.
- Negative checks performed:
  - No IDA function object at `0x0049bc50`.
  - No IDA entrypoint xrefs to `0x0049bc50`.
  - No little-endian absolute pointer-pattern hits to `0x0049bc50`.
  - No current active B report for the target.
  - MapPane table has distinct xrefs and should not absorb this helper.
  - Neighboring Crasher and CriticalSection pages have separate owner/behavior and only address adjacency.
- Failed, unavailable, or intentionally skipped checks and why:
  - `py_eval` is absent from the current schema, so no custom raw loaded-segment scan was run in this pass.
  - No broad `list_funcs`, full binary search, unbounded callgraph, or batch analysis was run because the assignment requires narrow MCP calls.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | `0x0049bc50-0x0049bc70` is a raw byte-step CRC16 helper body, not an IDA-modeled function. | High | Current `lookup_funcs`, `disasm`, `decompile` failure, target bytes. | Target `Status`, `IDA Evidence`, `Score Rationale` | incorporate | applied |
| C2 | The helper computes `(checksum << 8) ^ word_66D680[checksum >> 8] ^ value` and returns `AX`. | High | Current disassembly lines `0x0049bc53-0x0049bc6f`. | Target `Behavior`, `Draft C++ Notes`, C++ block rationale | incorporate | already-present |
| C3 | `[ebp+8]` is an unsigned byte value and `[ebp+0Ch]` is a 16-bit checksum accumulator. | High | `movzx ecx, byte ptr [ebp+8]`; `movzx eax, word ptr [ebp+0Ch]`. | Target `Behavior`, `Draft C++ Notes` | incorporate | already-present |
| C4 | `word_66D680` has exactly two current xrefs, this target at `0x0049bc5f` and byte-buffer helper at `0x0049bc92`. | High | Current `xrefs_to 0x0066d680 limit 20`. | Target `IDA Evidence`, `Ownership Notes` | incorporate | applied |
| C5 | The preceding `0x0049bc47-0x0049bc50` bytes are nine `0xcc` padding bytes; byte-buffer starts immediately at `0x0049bc70`. | High | Current `get_bytes 0x0049bc47 size 0x29`, `lookup_funcs 0x0049bc70`. | Target `Boundaries` | incorporate | applied |
| C6 | `Crc16` remains the best direct source owner and emitter; MapPane, zlib/LodePNG, Crasher, and Monitor remain rejected. | High for owner scope, medium-high for exact filename | Current table xrefs, support docs, B001 aggregate report, generated C++ output. | Target `Ownership Notes`, `Score Rationale`; support docs unchanged | incorporate | applied |
| C7 | The current formal C++ block is behavior-preserving and should remain unchanged. | High | Current disassembly, generated output, table owner docs. | Target formal `RECONSTRUCTION_CPP CODE` block | already-present | already-present |
| C8 | Target score can safely move from `85/90` to `88/91`, but not to `95+`. | Medium-high | Current MCP pass plus remaining name/reachability uncertainty. | Target metadata and `Score Rationale` | incorporate | applied |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - Current MCP disassembly exactly matches the existing documented instruction sequence.
  - Current MCP xrefs show only two references to `word_66D680`, both inside the byte helper pair.
  - Current bytes prove the target's start/end and predecessor padding.
  - Current generated C++ already emits the target through [UID:00032J] `Crc16`.
- Corroborating documentation/generated-report evidence:
  - `by-file/Crc16.md` already documents this as one of four narrow CRC16 helper children.
  - `auto-generated/-ag-coverage-report-by-memory.md` shows the target nested under the B001 split aggregate and emitting code.
  - `auto-generated/NexusTK/util/Crc16.cpp` contains the target block and table declarations/data.
- Strongest inference chain and why it is sufficient:
  - The target is one of two byte-oriented helpers that exclusively use the second CRC16 table object. The sibling helper, paired table docs, generated output, and absence of better owner evidence make `Crc16` the strongest source unit even without original symbol names.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs 0x0049bc50`: `fn:null`, error `Not a function`.
  - `lookup_funcs 0x0049bc70`: `fn:null`, error `Not a function`.
  - `lookup_funcs 0x0049bcb0`: function `sub_49BCB0`, size `0xe`.
  - `decompile 0x0049bc50`: `Decompilation failed at 0x49bc50`.
- Data/table/padding facts:
  - Target bytes at `0x0049bc50`: `55 8b ec 0f b7 45 0c 8b c8 c1 e0 08 c1 e9 08 66 33 04 4d 80 d6 66 00 0f b6 4d 08 66 33 c1 5d c3`.
  - Preceding bytes at `0x0049bc47-0x0049bc50`: nine `cc` bytes.
  - Table bytes at `0x0066d680` start `00 00 21 10 42 20 63 30 84 40 a5 50 c6 60 e7 70`, matching the documented CRC/CCITT-style opening.
  - Table tail sample at `0x0066d870` is `17 6e 36 7e 55 4e 74 5e 93 2e b2 3e d1 0e f0 1e`.
- Xref facts:
  - `xrefs_to 0x0049bc50`: zero xrefs.
  - `xrefs_to 0x0049bc70`: zero xrefs.
  - `xrefs_to 0x0066d680`: `0x49bc5f` and `0x49bc92`, both data xrefs, no containing function object.
  - `xrefs_to 0x0066db50`: eight MapPane-side data xrefs, separate from this Crc16 helper island.
- Vtable/global/type facts:
  - No vtable or global owner evidence points at this target. The meaningful dependency is file-scope table data under [UID:00027A].
- Negative IDA facts:
  - No function model, no decompile, no xrefs to target start, no absolute pointer-pattern hit for `0x0049bc50`, no stronger owner xref route.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049bbf0-0x0049bc0d` | [UID:00032K] `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md` | Word-step CRC16 helper using `word_66D480`. | TRUE | [UID:00032J] `Crc16` | `85/90` | Sibling support; unchanged. |
| `0x0049bc10-0x0049bc47` | [UID:00032L] `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md` | Word-buffer CRC16 helper using `word_66D480`. | TRUE | [UID:00032J] `Crc16` | `86/90` | Sibling support; unchanged. |
| `0x0049bc47-0x0049bc50` | ignored padding | Nine `0xcc` bytes before target. | FALSE | none | ignored | Boundary support. |
| `0x0049bc50-0x0049bc70` | [UID:00032M] target | Byte-step CRC16 helper using `word_66D680`. | TRUE | [UID:00032J] `Crc16` | current `85/90`, recommended `88/91` | Update target evidence and score. |
| `0x0049bc70-0x0049bca9` | [UID:00032N] `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md` | Byte-buffer CRC16 helper using `word_66D680`. | TRUE | [UID:00032J] `Crc16` | `86/90` | Direct byte-pair sibling; unchanged. |
| `0x0066d47c-0x0066d880` | [UID:00027A] `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md` | Two CRC16 lookup tables. | TRUE | [UID:00032J] `Crc16` | `88/92` | Table dependency; unchanged. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0049bc50` | no current xrefs | Target raw helper start is not directly reached in current IDA xref graph. |
| `0x0049bc5f` | data xref to `0x0066d680` | Target consumes `word_66D680`. |
| `0x0049bc70` | no current xrefs | Byte-buffer raw helper start is also unreferenced as an entrypoint. |
| `0x0049bc92` | data xref to `0x0066d680` | Byte-buffer sibling consumes the same byte table. |
| `0x0066d480` | refs `0x49bbff`, `0x49bc2c` | Word helper pair table. |
| `0x0066d680` | refs `0x49bc5f`, `0x49bc92` | Byte helper pair table. |
| `0x0066db50` | eight refs under MapPane-side code | Similar CRC table but separate MapPane owner; rejected for this target. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target page already records behavior, formal C++ code, exact disassembly, boundaries, owner, and table dependency.
  - `by-file/Crc16.md` records the narrow `NexusTK/util/` source owner and rejected owner candidates.
  - `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md` records the two 256-entry tables, exact helper xrefs, and `Crc16` attachment.
  - B001 report records the split and ownership repair that created this target as an exact child.
- Existing docs that are stale, incomplete, or contradicted:
  - Target score rationale says completion "should be at least 85" instead of reflecting the current post-C++, current-MCP evidence state.
  - Target page does not yet name the `supervisor_recovery_20260705` evidence pass, current pointer-pattern check, current MapPane table xref contrast, or explicit not-`95+` score cap.
  - No material contradiction was found in the existing behavior or owner docs.
- Generated/coverage report state:
  - `auto-generated/NexusTK/util/Crc16.cpp` currently contains the target C++ block.
  - `auto-generated/-ag-research-tracker.md` still shows reports `0` for UID `00032M`, which this report should address after supervisor execution.

## Ranked Ownership Analysis

### 1. [UID:00032J] `Crc16`

- Evidence for: accepted B001 source owner; exact target and byte-buffer sibling consume `word_66D680`; word siblings consume `word_66D480`; table page [UID:00027A] is attached to the same owner; generated output routes through `auto-generated/NexusTK/util/Crc16.cpp`; current MCP confirms no stronger entrypoint/caller owner.
- Evidence against: exact original source filename and helper names are not debug-proven; runtime call path is absent.
- Decision: accepted as the best direct source owner and emitter. The evidence against caps score, but does not justify parent blanking or reassignment.

### 2. Parent blank / no-emitter raw helper

- Evidence for: current MCP finds no entrypoint xrefs or callers, and IDA does not model the raw start as a function.
- Evidence against: the helper is clean source-shaped code, has a formal table dependency, has a sibling byte-buffer helper, and both table data plus by-file owner clear the current gate. Parent blanking would lose a strong source-unit relationship.
- Decision: rejected.

### 3. [UID:0000L3] `MapPane` and [UID:00027N] MapPane checksum table

- Evidence for: `0x0066db50` is a similar CRC/CCITT-style table.
- Evidence against: current MCP xrefs show `0x0066db50` has eight MapPane-side references, while this target references `0x0066d680`; there is no current xref/caller bridge from MapPane to `0x0049bc50`.
- Decision: rejected as a false owner for this target.

### 4. [UID:0000PC] `Zlib` / [UID:0000KW] `LodePNG`

- Evidence for: both contain checksum/CRC code elsewhere in the binary.
- Evidence against: their documented ranges are third-party CRC-32/Adler/PNG support, not this two-table 16-bit CRC/CCITT-style project helper pair.
- Decision: rejected.

### 5. Neighboring `Crasher` / `Monitor` and critical-section wrappers

- Evidence for: address adjacency around the `0x0049bbf0-0x0049bce8` neighborhood.
- Evidence against: `Crasher` ends before padding at `0x0049bbef-0x0049bbf0`; critical-section wrappers begin after `0x0049bca9-0x0049bcb0` padding. Neither shares table xrefs, globals, behavior, or source semantics with this helper.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new owner required. Keep existing [UID:00032J] `by-file/Crc16.md`, proposed path `NexusTK/util/`.
- Likely full contents: the four helper children [UID:00032K-00032N] and table data [UID:00027A], with the broad aggregate [UID:000225] remaining a non-emitting index.
- Candidate related items that belong: target UID `00032M`, byte-buffer UID `00032N`, word pair UIDs `00032K` and `00032L`, table data UID `00027A`.
- Candidate related items rejected: MapPane checksum table UID `00027N`, zlib/LodePNG checksum ranges, neighboring Crasher and Monitor/critical-section pages.
- Standalone, narrow, or broad source-file inference: narrow utility source file, not a broad checksum subsystem.

## Source Placement

- Recommended source file/class/global/module placement: keep `Crc16ByteStep` in [UID:00032J] `Crc16`, generated under `NexusTK/util/Crc16.cpp`.
- Why this placement fits source-tree and subsystem context: the helper is a file-local static utility paired with sibling CRC16 helpers and file-scope table data. No class receiver, vtable, feature file, or third-party source unit claims it more strongly.
- Rejected placements and why: MapPane, zlib, LodePNG, Crasher, and Monitor are rejected as above; table data alone is not a source parent.
- Remaining placement uncertainty, if any: exact original filename and whether the original developers used a broader checksum utility name are unresolved. Current `Crc16` remains the best source-facing descriptive file name.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target starts at `0x0049bc50` after nine `0xcc` bytes and ends at `0x0049bc70`, immediately before the byte-buffer helper. The target body is exactly 32 bytes and contains no `0xcc` padding.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new children or split repairs are needed. The B001 split remains correct.
- Padding/table/data/code distinctions: `0x0049bc47-0x0049bc50` is padding; `0x0049bc50-0x0049bc70` is source-authored code; `0x0066d680-0x0066d880` is source-declared/generated-binary table data under [UID:00027A].
- Parent/container impact: [UID:000225] remains a non-emitting aggregate/index. The target child continues to carry source emission.

## Negative Evidence Summary

- No current IDA function object exists at the target start.
- No current xrefs target `0x0049bc50` or `0x0049bc70`.
- No current absolute little-endian pointer-pattern hits target `0x0049bc50`.
- No current MapPane xrefs target this helper or its `word_66D680` table.
- Similar table bytes at `0x0066db50` are not ownership evidence because their xrefs are MapPane-side and separate.
- Neighboring pages are separated by padding and different source semantics.
- Original names remain inferred, so the report does not recommend `95+` scoring or final-audit language.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: keep `Crc16ByteStep`, `unsigned char value`, `unsigned short checksum`, `kCrc16ByteTable`, and source owner `Crc16`.
- Evidence for each proposed name/type/comment: byte input is proven by `movzx ecx, byte ptr [ebp+8]`; checksum is proven by `movzx eax, word ptr [ebp+0Ch]`; table role is proven by `word_66D680[ecx*2]`; helper family structure supports the `Crc16`/byte-step names.
- Items intentionally left unchanged and why: do not rename to a MapPane/checksum-packet helper; no xref route supports that. Do not claim original symbol proof.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. The implementation callback is documentation-only for the target by-memory page and does not authorize IDA DB edits.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is `RECONSTRUCTABLE:TRUE`, has emitter [UID:00032J], and its combined score clears the current C++ gate.
- Recommended code: keep the existing exact formal target C++ block. If the supervisor requests reapplication, use this exact insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static unsigned short Crc16ByteStep(unsigned char value, unsigned short checksum)
{
    const unsigned int tableIndex = checksum >> 8;
    return static_cast<unsigned short>((checksum << 8) ^ kCrc16ByteTable[tableIndex] ^ value);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable. This is NexusTK-owned source utility code, not a vetted static third-party source import.
- Reason it preserves exact original behavior: the code uses the high byte of `checksum` as table index, shifts the checksum left by eight, xors the `kCrc16ByteTable` entry, xors the unsigned byte input, and returns a 16-bit value, matching the target disassembly.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a small `static unsigned short` helper in a utility `.cpp` beside its table and buffer wrappers is more plausible than exposing unreferenced raw helpers as public API or decompiler-named global functions.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `Crc16ByteStep`, `value`, `checksum`, `tableIndex`, and `kCrc16ByteTable` replace raw stack labels and `word_66D680`.
- Naming/coding style convention used and evidence for consistency: same source-facing style as sibling `Crc16WordStep`, `Crc16WordBuffer`, and `Crc16ByteBuffer` in generated `Crc16.cpp`.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes applied or recommended: applied the accepted target-only callback to `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`: current MCP evidence pass, pointer-pattern negative check, MapPane-table contrast, B001 split preservation, explicit not-`95+` score cap, and target metadata `COMPLETION:88`, `CONFIDENCE:91`.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:00032J` and `EMITTER_UIDS:00032J`.
- Exact items left no-owner/non-emitting and why: none for this target. Parent aggregate [UID:000225] remains non-emitting by design and is outside the target edit scope.
- Exact future work, if any, outside this assignment scope: a future broader source-tree pass may decide whether `NexusTK/util/Crc16.cpp` should be listed in project-structure docs, but that is not required for this target and B002 did not edit project-structure files in this pass.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`.
- Exact report facts to incorporate:
  - Add a current MCP evidence note naming session `supervisor_recovery_20260705`, status `ok`, imagebase `0x400000`.
  - Add current `lookup_funcs`: `0x0049bc50` and `0x0049bc70` are not function starts; `0x0049bcb0` is `sub_49BCB0`, size `0xe`.
  - Add current `xrefs_to`: zero entrypoint xrefs to `0x0049bc50`; `word_66D680` has exactly `0x49bc5f` and `0x49bc92`.
  - Add current `find_bytes "50 BC 49 00"` result: zero absolute pointer-pattern matches to target start.
  - Add current decompile result: failed at `0x49bc50` because the raw start is not modeled.
  - Add boundary bytes: nine `0xcc` bytes at `0x0049bc47-0x0049bc50`, exact target bytes at `0x0049bc50-0x0049bc70`, and no padding before `0x0049bc70`.
  - Add negative ownership evidence: MapPane table `0x0066db50` has eight separate MapPane-side xrefs and is not evidence for moving this helper out of `Crc16`.
  - Add explicit not-higher score rationale: no original symbol/source path and no direct runtime caller keep this below final audit.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Change `COMPLETION:85` to `COMPLETION:88`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:91`.
  - Keep `CANONICAL_OWNER:00032J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00032J`, and current `RECONSTRUCTION_CPP CODE` unchanged.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve B001 split history and the no-direct-caller caveat.
  - Preserve rejection of MapPane/zlib/LodePNG/Crasher/Monitor ownership.
  - Replace "at least 85" score wording with current score rationale.

## Recommended Support Doc Changes

- Support path: `by-file/Crc16.md`.
  - Exact report facts to incorporate: none required. It already records the helper family, target link, table dependency, rejected candidates, generated output caveat, and score cap. Optional if supervisor wants current-evidence freshness: add one sentence that B002's 2026-07-05 MCP pass rechecked UID `00032M` without changing source placement.
  - Metadata/link/score/coverage/source-placement changes: no required change.
- Support path: `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md`.
  - Exact report facts to incorporate: none required. It already records `word_66D680` xrefs and table details.
  - Metadata/link/score/coverage/source-placement changes: no required change.
- Support path: `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md`.
  - Exact report facts to incorporate: none required. It already functions as a non-emitting aggregate index.
  - Metadata/link/score/coverage/source-placement changes: no required change.

## Score And Metadata Recommendation

- Current score/metadata: `85/90`, owner `00032J`, reconstructable `TRUE`, emitter `00032J`, formal C++ present.
- Recommended score/metadata: `88/91`, owner/emitter/reconstructable unchanged, formal C++ unchanged.
- Score rationale and reason not higher/lower:
  - Higher than current because current MCP independently rechecked function-model absence, decompile failure, exact disassembly, table xrefs, boundary bytes, table samples, generated output, and negative owner candidates.
  - Not `95+` because the original function/file/table names are inferred and no direct runtime caller/reachability route was found. Current schema limitations also prevented repeating B001's custom raw direct-call scan.
  - Not lower because behavior, range, table dependency, source owner, emitted C++ shape, and negative owner evidence are all current and specific.
- Score-improvement attempt:
  - Original-name blocker: checked by-function/by-file/by-class/by-global references, generated output, B001 report, and current IDA names; no debug/source symbol found. Resolved as "infer descriptive names, cap confidence."
  - Runtime reachability blocker: checked current `xrefs_to`, `lookup_funcs`, decompile status, and pointer-pattern search; no direct entrypoint route found. Resolved as "document retained/unreferenced raw helper, cap confidence."
  - Owner/source-placement blocker: checked Crc16 parent, table docs, MapPane table xrefs, zlib/LodePNG/Crasher/Monitor alternatives; resolved in favor of `Crc16`.
  - C++ readiness blocker: checked exact disassembly and generated C++; resolved by retaining existing formal block.
- Metadata fields to change or leave unchanged:
  - Change `COMPLETION` and `CONFIDENCE` only.
  - Leave `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`, `Nested`, and C++ block unchanged.

## Open Questions With Attempted Resolution

- Open question: are `Crc16ByteStep`, `Crc16`, and `kCrc16ByteTable` exact original names?
  - Evidence checked: current IDA names, by-* docs, by-function/by-file/by-class/by-global search, generated C++ output, B001 report.
  - Best supported resolution or inference: no exact names recovered; keep descriptive names because they reflect behavior and sibling structure.
  - Remaining impact: caps confidence below final-audit; no metadata reassignment needed.
- Open question: is there a runtime caller or feature owner?
  - Evidence checked: current `xrefs_to`, `lookup_funcs`, decompile failure, `find_bytes` absolute pointer-pattern search, B001 raw-scan lead, surrounding docs.
  - Best supported resolution or inference: no direct caller in current IDA; treat as retained/unreferenced raw utility helper under `Crc16`.
  - Remaining impact: caps confidence and prevents claiming feature-level ownership.
- Open question: should the similar MapPane table merge with this Crc16 table family?
  - Evidence checked: current `xrefs_to 0x0066db50`, MapPane table doc, Crc16 table docs.
  - Best supported resolution or inference: no. The tables are similar but have separate consumers and owners.
  - Remaining impact: none for target metadata.

## Follow-Up Actions

- Supervisor actions: Gate 2 review the updated target page, this report ledger/checklist, and validator result.
- A-agent actions: none required.
- B002 future research actions: none pending unless supervisor requests Gate 2 repair.

## Confidence

- Recommendation confidence: high for keeping owner/emitter/C++ and raising score modestly.
- Score confidence: medium-high for `88/91`; exact original names and absent caller route prevent final-audit scoring.
- Remaining uncertainty: original source spelling, source filename proof, and live runtime reachability.

## Validator Results

- Commands run: `python .\tools\validator.py --mode file --file by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md --apply --queue-timeout 240`
- Results: exit code `0`; `command_id: 000000006992`; `command_timestamp: 2026-07-05T11:23:29-04:00`; `ok: 1`; scanned markdown files `1`.
- Target updates reported: `completion_update 00032M ... 88`; `confidence_update 00032M ... 91`.
- Validator side effects reported: `reference_index_add 00027N ...`, `projected_stats_update ------ project-level/-auto-completion-stats.md updated projected path completion section`, `stats_incremental_noop 00032M ... file is not present in generated stats lists`, and `generated_refresh: deferred` with refresh command id `000000006992`. B002 did not manually edit generated files, coverage reports, validator state, support docs, or lifecycle/archive files.
- Any unresolved validator warnings/errors: none target-specific; validator returned `ok: 1`.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/00032M-Crc16ByteStep-source-quality.md`.
- Modified: `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`.
- Modified: `tools/leaser/Agents/Agent-B002/research/00032M-Crc16ByteStep-source-quality.md` for callback ledger/checklist/validator state.
- Renamed: none.
- Report execution: not run. B002 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, or any equivalent lifecycle command.

## Implementation Tracking Checklist

Callback implementation pass:
- [x] Supervisor validation required before implementation: Gate 1 passed at report SHA256 `56F19D04DD56A63E9EFFA9FFE086ED07100765872E95BD924B4784303B288AA7`.
- [x] Target/support docs to update: updated only `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`; support docs were excluded by callback scope and left untouched.
- [x] Current target state and actual evidence checked recorded: target now records current MCP session `supervisor_recovery_20260705`, server status `ok`, imagebase `0x400000`, `lookup_funcs`, `xrefs_to`, `find_bytes`, `decompile`, and boundary-byte facts.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C1-C8 now record `applied` or `already-present`.
- [x] Metadata/score changes applied: target `COMPLETION:85 -> 88`; `CONFIDENCE:90 -> 91`.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: target score rationale now documents original-name and runtime-reachability caps and explicit not-`95+` reasoning.
- [x] Owner/emitter/reconstructable changes applied or confirmed unchanged: target keeps `CANONICAL_OWNER:00032J`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00032J`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and existing C++ block unchanged.
- [x] Split/rename/new-child changes applied or confirmed not applicable: no split/rename/new child; target now preserves B001 split history and exact child status.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes applied or confirmed not applicable: target records exact padding/body boundary facts and states no IDA DB edits requested.
- [x] First-draft C++ or no-code proof applied or confirmed already present: existing formal `Crc16ByteStep` block was already present and left unchanged.
- [x] Third-party import directive applied or confirmed not applicable: not applicable; target is NexusTK-owned utility code.
- [x] Exact target/support doc facts incorporated at report-level detail: target incorporates current MCP facts, negative owner checks, generated-output state by implication through unchanged C++ block, and score-cap rationale.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: no-caller caveat, B001 split, and rejected MapPane/zlib/LodePNG/Crasher/Monitor alternatives preserved; stale "at least 85" wording replaced.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: no Wave2/Wave3 evidence used; no target edit needed.
- [x] Open questions closed or documented as evidence-backed unresolved: original names and runtime caller route remain unresolved with target score/C++ impact documented.
- [x] Validators run: scoped validator command above returned exit code `0`, `command_id 000000006992`, `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text applied: no manual coverage/tracker text. Validator reported `generated_refresh: deferred`; B002 made no manual generated edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000006995","destination_path":"executed-b-agent-research/B002/00032M-Crc16ByteStep-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00032M-Crc16ByteStep-source-quality.md","timestamp":"2026-07-05T11:27:45-04:00","uid":"00032M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
