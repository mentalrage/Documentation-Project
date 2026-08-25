** TARGET-REPORT-UID:00023C **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00023C MidiSMFLoadAndStreamFillHelpers Ownership / Split Research


## Finalized Report / Current Recommendation

- Current implemented disposition: UID00023C is a `91/94` documentation-only, non-emitting index over two exact source functions, with owner UID0000LD, `RECONSTRUCTABLE:FALSE`, blank emitter/position/formal C++, and `Nested:0`. UID0002C6 and UID0002C7 are the only source-bearing children under the retained `MidiPlayer.cpp` route.
- Final source disposition: UID0002C6 is the private `MidiDocument::FillStreamBuffer` operation at `[0x005271b0,0x005273a0)`; UID0002C7 is the private `MidiDocument::Load` operation at `[0x005273a0,0x005277bb)`. The thirteen leading and five trailing `0xcc` bytes remain compiler alignment in UID0000VN and emit no source body.
- Completed correction: the two child bodies now remove unsupported writes/helpers/validation, preserve exact allocation and cleanup behavior, and use direct loader polarity. UID0002C5 was UID-preservingly renamed from `MidiParseSuccessWrapper` to `MidiDocumentLoadFailureWrapper`; `MidiDocument::LoadFailed` returns true for the loader failure value `1`. The private declarations and callback call site are synchronized without broad sibling rewrites.
- Confidence: very strong for ranges, bytes, calls, return polarity, layouts, state transitions, allocation/cleanup behavior, and parent non-emitting disposition; strong but not original-symbol proof for `MidiDocument`, `FillStreamBuffer`, `Load`, `LoadFailed`, field spellings, and the current `MidiPlayer.cpp` placement.

## Supporting Research

- Historical pre-callback target snapshot: `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md`, SHA256 `9377EE992FB15B1BAE5D115816D1D8D92EF97E31D2D7FC9AEA1B0505BB9D8DEB`, 19,306 bytes when inspected. Current post-callback SHA256 is `153D9F7878E503DD644D57BB39240FD5C0F9F14BA5A1CE38CD982A9C4C360804`.
- Historical pre-callback tracker snapshot: read-only `auto-generated/-ag-research-tracker.md`, SHA256 `FE0A54993978AA8F968234ED5FB00FFEB23F2A3FAAC5AC232C43E58084275DE8`, recorded UID00023C as `86/90`, reconstructable true, reports `0`. It is not asserted as current or permanent lifecycle/count truth and was not edited by B004.
- Historical pre-callback child snapshots were UID0002C6 SHA256 `74180B9EEAD07F90F74FBCC1F4649451E4C4892DC810C90B958A6A695195CEDF` and UID0002C7 SHA256 `B656ED9FF2394DCD7342ADE0532A33D538F57CAF16A2451D8CAAAD866F5B6DF6`. Current post-callback hashes are UID0002C6 `7CE78274E5A93CF90F4E7486B1AF994971C214ECD73ACD8EA801074D9AFA2D20` and UID0002C7 `4DAAD43118C12906A810140CC2DB54C7FEE4E852E8777939F189C42A7B3F0E80`.
- Historical generated snapshot: validator command `000000012197`, SHA256 `E095EB9805E954767EF364B347F6DAB1882CA9DC8DB2124EF5A300E0CA8CC6AF`, emitted both children plus the parent prose marker. B004's waited validator command `000000012277` refreshed read-only `auto-generated/NexusTK/audio/MidiPlayer.cpp` successfully; a later concurrent validator refresh produced current header command `000000012293` at `2026-07-14T21:27:33-04:00`, which is newer than B004's command. Current SHA256 is `D236479B8396D19337132D4B48C5EE5B1B7BB5BEED70D53EB2EFAB6C268EE3FB`, and the target assertions remain identical.
- Search terms used across every report root were `UID00023C`, `0x005271b0`, `0x005277bb`, `MidiSMFLoadAndStreamFillHelpers`, `MidiFillStreamBuffer`, `MidiLoadDocument`, `MidiDocument`, `MidiTrackState`, `MidiStreamWriteContext`, `UID0002C6`, `UID0002C7`, `UID0002B2`, `UID0002BY`, `UID0001CE`, `UID0001CG`, `UID0001CI`, `MidiPlayer`, `SMF`, `MThd`, and `MTrk`.
- Active roots `Agent-B001/research`, `Agent-B002/research`, and `Agent-B004/research` contained zero Markdown reports before this artifact; `Agent-B003/research` and `Agent-B005/research` each contained one unrelated report and no match. No active goal/report collision or matching lease was found outside B004's own assignment.
- `tools/leaser/Agents/Older-Research` contained three Markdown files and no matching report. `tools/leaser/Agents/SpecialReports` contained five Markdown files and no matching report. The actual project `archived` root contained zero Markdown reports and therefore no match.
- `executed-b-agent-research` contained the relevant historical reports. They were treated as leads and revalidated against current bytes/docs, not copied as current proof:
  - `B001/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md`, SHA256 `950E7F284AD2DCE066F508337AF448DD3B5EA3DF3F6391BD58E834D3D808D401`, introduced the descriptive names and current drafts, but explicitly left class-method versus file-static shape and exact source spellings unresolved.
  - `B003/0002B2-MidiSMFParserScratchGlobals-source-quality.md`, SHA256 `D30B25BBDE97B85D9A9CE64E9C16F23577FE5CE2887A6F2B9B15708C3F5D544B`, established five private scratch declarations and their confinement to UID0002C6.
  - `B012/0002BY-MidiTrackBufferPrimeReset-source-quality.md`, SHA256 `525F18DEAC26443ACFC14E477C8CC8006D11F6D2B4D1DC5F2894D2BF474CC2A8`, corrected replay so track priming occurs only for an already-recorded end state with replay permission.
  - `B003/0001CE-MidiStreamOpenAndPrimeBuffers-source-quality.md`, SHA256 `CB6E0212CEAE236285D4CC7FB99864D3F60C3A5CB4B05DB54260CC735987332E`, confirmed first-fill/reset argument order and that the stream-open caller treats UID0002C5 nonzero as failure.
  - `B004/0001CG-MidiStreamCallback-source-quality.md`, SHA256 `BEBA3786EB09FCA9C717CEE9C38F7F8F60D5BE46A467B110F04CFAB6BC60014B`, supplied the current callback body and second direct UID0002C6 call.
  - `B013/0000LD-MidiPlayer-empty-emitter-family-source-quality.md`, SHA256 `696466DC73BB3AEECA02DDA3EEDDECCC5CCD5C9C755C628C771E2BA5E89B6FD8`, retained `MidiPlayer.cpp` as the source route and recorded the declaration/output integration history.
  - The executed UID0002BS, UID0002BW, UID0002BZ, and UID0002C4 reports were opened to recheck exact-read polarity, VLQ shape, side-effect-only source open, and construction of the embedded `DATFile` member.
- Historical B001/B003/B012 source-quality findings remain useful, but their old source drafts do not supersede the current live decompilation. In particular, prior reports did not catch loader success polarity, direct header-read width, zero-track behavior, buffer-allocation flags/order, or UID0002C6's extra per-event clear and selected-tick reset write.

## Target

- Target UID: `00023C`.
- Target path: `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md`.
- Historical source queue/report row: the pre-callback tracker snapshot was a not-covered reconstructable row at `86/90`, average `88.0`, reports `0`; tracker/count/lifecycle truth after this callback is external supervisor/validator-owned.
- Callback state: supervisor Gate 1 accepted exact report SHA256 `7C6CB192D5D9ECCC2533969892EDC6B19D4B577D8C3795DA675E2A4F20725D21` at `2026-07-14T21:07:08-04:00`, and B004 completed the authorized ordinary-document callback without executing or moving this report.
- Current implemented parent state: `91/94`, owner `0000LD`, reconstructable false, blank emitter and optional position, `Nested:0`, and an empty managed block because exact children own every executable byte.

## Current Target State

- Current metadata: `COMPLETION:91`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:FALSE`, blank emitter and position, empty formal block, `Nested:0`.
- Current owner/emitter/reconstructable state: UID0000LD remains the documented source route, while the parent itself emits no declaration, body, marker, or storage. UID0002C6 and UID0002C7 own the two exact source bodies.
- Current C++/emitter state: generated `MidiPlayer.cpp` contains exactly one UID0002C6 `MidiDocument::FillStreamBuffer`, one UID0002C7 `MidiDocument::Load`, and one UID0002C5 `MidiDocument::LoadFailed`; it contains no UID00023C output and no target empty marker.
- Remaining uncertainty: original source spellings and historical filename are unavailable confidence caps only. File/class operation direction, layouts, scratch ownership, loader polarity, and exact child bodies are implemented.
- Related target/support docs checked: UID0002C6, UID0002C7, UID0002B1, UID0002B2, UID0002BS through UID0002C5, UID0002BU/0002BV/0002BY, UID0001CE/0001CG/0001CI, UID00023B, UID0000LD, UID00008A, UID0000T9, UID0000VN, all affected manual coverage files, and generated `MidiPlayer.cpp`.
- Current artifact/lifecycle boundary: implementation and scoped validation are complete. B004 performed ordinary edits under released short leases and ran the authorized validators/generated refresh, but performed no report execution, lifecycle probe, count, move, archive, manual coverage edit, or IDA mutation. Report validation/execution/archive/count state remains external supervisor/validator-owned.

## Executive Recommendation

- UID0000LD `MidiPlayer.cpp` remains the canonical owner/emitter route. `MidiDocument` is implemented as a private source type inside that translation unit, not as `MidiPlayer`, `DATFile`, or a new independently routed file.
- UID00023C is false/non-emitting with its exact child index and owner link retained; it emits no covered-by/prose marker.
- UID0002C6 and UID0002C7 remain true and routed to UID0000LD with corrected formal bodies and materially raised scores.
- UID0002C5 was renamed in place to `by-memory/0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md`; its UID/owner route are retained and the false `Succeeded` identity is replaced by `MidiDocument::LoadFailed`.
- UID0002B1's existing private declaration block carries the exact layouts, avoiding a duplicate by-type declaration owner.
- No in-scope blocker or implementation item remains. Original symbol and filename recovery would increase confidence but would not change the selected range, owner, source behavior, or no-duplication rule.

## Supervisor Active Recheck

- Historical assignment basis: the supervisor assigned a direct UID00023C report because the pre-callback queue snapshot showed zero reports and the parent remained a true/emitting aggregate with unresolved source-quality blockers.
- Current callback truth: the split, parent metadata/emission, child bodies, failure-wrapper rename, declarations, and support synchronization are complete and scoped-validated. Every source-bearing interval in `[0x005271b0,0x005277bb)` has one exact child body, and both padding intervals retain compiler-only proof.
- External boundary: fresh report review, execution, manual coverage application, counts, moves, and archive state are supervisor/validator-owned and are not asserted or directed by this artifact. No implementation item remains deferred.

## Inference Research Guidance Check

- `by-structure.md` requires exact child pages to own source bodies and requires a broad index with no independent source declaration to be false/non-emitting. That rule controls the parent disposition.
- Existing claims that `MidiFillStreamBuffer` and `MidiLoadDocument` were file-static helpers were treated as inference, not fact. Current `__thiscall` prototypes, explicit argument cleanup, and the real `MidiDocument` constructor make private operations on the internal object the strongest source model.
- Direct IDA facts are separated below from documentation evidence and source-shape inference. Names remain descriptive unless a binary/source artifact proves an original spelling.
- No Wave2/Wave3 source artifact was accepted as current evidence. Older report wording was historicalized when contradicted by current IDA or current generated output.

## Heuristic / Inference Reanalysis And Validation

The numbered resolutions below preserve the Gate 1 analysis verbatim in substance. References to a "current draft" identify the pre-callback source that was inspected; every stated resolution is now applied and independently represented in the terminal ledger/proof sections.

1. Parent reconstructability: the interval has two functions and no third body, declaration, table, or storage item. A true parent marker duplicates child ownership conceptually and pollutes output. Resolution: false/non-emitting index.
2. Function shape: IDA reports `int __thiscall(_DWORD *this, char, _DWORD *, int)` and `int __thiscall(char *this, unsigned int)`. The constructor at `0x00527080` initializes the same 0x48-byte object and its embedded `DATFile`. Resolution: model the two target bodies as private `MidiDocument` operations. This is source-shape inference backed by ABI consistency, not original-name proof.
3. UID0002C6 helper split: current C++ adds `MidiResetFillScratch` and `MidiSelectNextTrack` definitions with no exact child ranges. Resolution: fold their logic into the sole `FillStreamBuffer` body. The compiler may have inlined source fragments historically, but the exact by-memory child must not claim two extra address-owned functions.
4. UID0002C6 reset writes: current draft sets `g_midiSelectedTick = 0xffffffff` on reset. The executable reset path does not write `0x0069b87c`; it clears only state, pending event, selected track, and scan cursor. Resolution: remove the extra write.
5. UID0002C6 event clear: current draft zeroes `g_midiPendingEvent` before every `MidiReadEvent`. The executable only clears it on reset. Resolution: remove the per-event clear.
6. UID0002C6 payload cleanup: the executable gates `free(payload)` and decrement only on `allocatedPayloadCount != 0`; it does not separately test payload non-null. Resolution: preserve that exact count-gated behavior.
7. UID0002C6 replay: reset never primes. Only a pre-existing end bit plus `allowEndReplay` calls UID0002BY, clears fill state, and resumes. B012's correction is retained.
8. UID0002C6 result values: `0`, `-101`, `-102`, `-103`, and encoder sentinel `-104` are direct constants. Descriptive enum names remain accepted; they are not claimed original.
9. UID0002C7 return polarity: live code returns `0` after all tracks are prepared and `1` after cleanup on failure. Resolution: reverse the current draft's success/failure returns and rename UID0002C5's false success identity.
10. UID0002C7 wrapper: UID0002C5 returns `sub_5273A0(...) == 1`; the stream-open caller treats true as failure. Resolution: `LoadFailed`, not `LoadSucceeded`.
11. UID0002C7 document initialization: executable clears offsets `+0x30,+0x04,+0x08,+0x0c,+0x00,+0x10`; it does not clear `allocatedPayloadCount` at `+0x34`. Resolution: remove that extra clear.
12. Header tag read: the executable uses the raw source read path for the first four-byte tag and checks success plus exact count before `MThd`. Resolution: formal code uses `MidiReadRaw`, not `MidiReadExact`, for that first tag.
13. Header data read: after byte-swapping length, executable requires `length >= 6` and performs one exact read of `length` bytes beginning at the three-word header fields. It does not perform three two-byte reads and does not seek over extra bytes. Resolution: preserve the one-width trusted-header read, including its historical malformed-header overrun risk.
14. Endian conversion: `MThd`, `MTrk`, 32-bit lengths, and three 16-bit fields are direct. The current standalone swap helper definitions have no exact child ranges. Resolution: use explicit expressions inside `Load`.
15. Zero tracks: executable does not reject `trackCount == 0`; after table lock it returns success without entering the loop. Resolution: remove the current extra validation.
16. Track allocation: the table uses `GlobalAlloc(0x40, 40 * count)`; each 0x400 buffer uses `GlobalAlloc(0x42, 0x400)`. Resolution: use `GMEM_ZEROINIT` for the fixed table and `GHND` for movable zeroed buffers.
17. Allocation order: each track buffer is allocated/locked before reading the corresponding `MTrk` tag. Resolution: preserve that order.
18. Track source offsets: executable queries current source position before initial read and again after it. Resolution: do not replace the second query with arithmetic only.
19. Empty track: only `bufferedBytes == 0 && bytesRemaining == 0` sets `MIDI_TRACK_DONE`; otherwise the first VLQ is decoded. Resolution: preserve the OR condition.
20. Cleanup: all failure paths converge on source close plus table/buffer unlock/free and return `1`. `MidiReleaseDocument` has equivalent side effects and remains the accepted source-level cleanup expression; the executable inlines/duplicates it in this large body.
21. Layouts: `MidiTrackState` is exactly 0x28; `MidiEvent` is 0x10; the WinMM write context is exactly `MIDIHDR` 0x40 plus five dwords through 0x54; `MidiDocument` occupies 0x48 including embedded `DATFile` and final alignment. Current field spellings are descriptive, but offsets and widths are direct.
22. Scratch ownership: every direct reference to `0x0069b870-0x0069b88c` is in UID0002C6. Resolution: keep private file-static storage on UID0002B2; do not make it `MidiPlayer` or `MidiDocument` instance state.
23. Source placement: no recovered filename, source-path string, symbol, RTTI for the private type, or separate by-file route supports `MidiSMFDocument.cpp`. Adjacency and all callers remain in the MidiPlayer WinMM family. Resolution: use `MidiPlayer.cpp`; retain a historical split caveat only as negative evidence.
24. Rejected alternatives: parent true/prose marker, duplicate parent body, `MidiPlayer` instance methods, `DATFile` ownership, generic file-I/O ownership, `SoundManager`, a new source file without route evidence, three child functions per page, zero-track rejection, header-tail seeking, success-return `1`, and buffer flag `0x40` are rejected.

## Evidence Standards Used

- Primary evidence: current live IDA MCP health, exact function objects, Hex-Rays output, explicit stack cleanup, caller/callee/xref inventories, type catalog negatives, byte reads, exact SHA256 hashes, and pointer/immediate searches.
- Secondary evidence: current ordinary docs and generated output. They establish project routing and historical accepted names but are corrected where binary facts conflict.
- Historical leads: executed B-agent reports. Each relevant claim was rechecked against current IDA/current docs.
- Negative evidence: no third function in the interval, no pointer/immediate route to either function start, no interior alternate entry documented, no project MIDI/SMF private types in IDA, no stronger source filename, and no scratch consumer outside UID0002C6.
- The evidence ladder supports very strong behavior/range confidence. It cannot recover original private names or filename, so no `95+` recommendation is made.

## Evidence Checked

- IDA MCP session: streamable transport initialized successfully; `idb_list` returned active NexusTK database `2625e5c6`. `server_health` returned status `ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Bounded target lookup: `0x005271b0` is `sub_5271B0`, size `0x1f0`; `0x005273a0` is `sub_5273A0`, size `0x41b`; `0x005277bb` is not a function; successor `sub_5277C0` starts at `0x005277c0`.
- Exact bytes: target `[0x005271b0,0x005277bb)` is 1,547 bytes, SHA256 `78FDBEE84B88BF761C3359FB3DD8C70F86E12D0B7F8B8AB1FA98218156EB03CD`. UID0002C6 is SHA256 `D85755FA8EE8A623B05686784352D1B6952F47105AF282E3E1B6064070B2B39C`; UID0002C7 is SHA256 `522E18CD226DF604B3648458C4914AC0EC18C6CE70BD0F4E31B896542C237E6C`.
- Padding bytes: `[0x005271a3,0x005271b0)` is thirteen `0xcc` bytes, SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`; `[0x005277bb,0x005277c0)` is five `0xcc` bytes, SHA256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`.
- Instruction counts: disassembly reports 140 instructions for UID0002C6 and 335 for UID0002C7.
- Entry xrefs: UID0002C6 has exactly two code callers at `0x00525a51` and `0x00525d3a`; UID0002C7 has exactly one at `0x005270c6`.
- UID0002C6 callees: `0x00526da0`, `0x00526790`, `0x005269f0`, and `j___free_base`. UID0002C7 callees include `0x00526650`, `0x00527000`, `0x00526bb0`, `sub_49C540`, CreateFileW dispatch storage, Win32 file APIs, and global-memory APIs.
- Scratch xrefs: counts are 3 to `0x0069b870`, 3 to `0x0069b874`, 8 to `0x0069b878`, 2 to `0x0069b87c`, 4 to `0x0069b880`, and 2 to `0x0069b88c`; all are inside UID0002C6.
- Function prototypes rechecked across the family: modeled source helpers consistently use the document pointer in ECX; UID0002C6 ends with `retn 0Ch`, UID0002C7 with `retn 4`, and UID0002C5 with `retn 4`.
- Raw helper liveness: `0x00526ce0`, `0x00526f10`, `0x00526f60`, `0x00526fa0`, and `0x00527040` have zero entry xrefs; `0x00527000` has one call from UID0002C7. This supports retained/inlined source-helper treatment, not new child ownership inside UID00023C.
- Type search: only SDK `midihdr_tag` was found for Midi/MIDI terms; no private SMF, document, or track type survived in IDA. `midihdr_tag` is 64 bytes with the expected fields through `dwReserved[8]`.
- Byte searches found `MThd` only at `0x00527498` and `MTrk` only at `0x005275a7` in UID0002C7. Searches for little-endian absolute pointers to `0x005271b0`, `0x005273a0`, `0x005270c0`, and `0x005270e0` found none; normal relative calls account for the live routes.
- Ordinary docs and hashes checked include UID0002B1 `961B1D2ADD278685E31A89EC9DB11A6D8C108EF88D28ED6BFEBE6D1B2E089AA7`, UID0002B2 `5810C6B8512B3B04B36EE95ABFF16D602BD3DAF61710DED2FBCEC5B77F2C0EDE`, UID0002C5 `245F7497F585C48C7DC84223F6121C07469D4C7D5CB9FED4BA888CCB23C319C7`, UID0001CG `D20211AE77D026E034213F1801BC030DDA783F0AF009515C3E2A815E9BBCEE9D`, by-file MidiPlayer `1047131A1F5C252F036257F5209F8F6EFAFAA7F9118DC566B984E780A3020F36`, by-class MidiPlayer `EE7232D1833B18DBF13171EF94A3041D00EB56B5802CAF3B291B489D5461032B`, and by-global MidiPlayerWinMMState `683B98F125BAB3CAC8D90CD8D1E58EC5E583C45942ECED4BB276F66C85D4B54A`.
- Manual coverage inspected read-only: `by-memory/-coverage-report.md`, `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, `by-global/-coverage-report.md`, and `by-type/by-struct/-coverage-report.md`. Current by-memory rows are stale relative to both current docs and this recommendation.
- Failed/unavailable checks: no MCP-backed check failed after the healthy session was established. Original symbols/source files are unavailable in this stripped executable. No IDA mutation was attempted.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00023C exactly covers two functions and no independent parent source item. | Very strong | IDA entities, exact bytes, child boundaries | UID00023C range/status; validator `000000012234`, exit 0, ok 1 | incorporate | applied |
| C02 | UID00023C must be false/non-emitting with blank emitter, position, and C++. | Very strong | `by-structure.md`, exact split | UID00023C metadata/formal; validator `000000012234`; Destination 1 exact-match proof | incorporate | applied |
| C03 | UID00023C retains owner UID0000LD and `Nested:0` as an index. | Strong | source family, current nesting | UID00023C metadata; validator `000000012234` | incorporate | applied |
| C04 | UID0002C6 exactly covers `0x005271b0-0x005273a0`, 496 bytes. | Very strong | lookup/bytes/hash | UID0002C6; validator `000000012235`, exit 0, ok 1 | already-present | already-present |
| C05 | UID0002C6 is best modeled as private `MidiDocument::FillStreamBuffer`. | Strong | ECX receiver, retn 0Ch, constructor/type context | UID0002C6 formal/status and UID0002B1 declaration; validators `000000012235`/`000000012238`; generated command `000000012277` | incorporate | applied |
| C06 | UID0002C6 retains owner/emitter UID0000LD, true, blank position, `Nested:4`. | Very strong | exact parent/child graph | UID0002C6 metadata; validator `000000012235` | already-present | already-present |
| C07 | UID0002C6 reset does not write selected tick. | Very strong | decompile/data xrefs | UID0002C6 body/evidence and UID0002B2 support; validators `000000012235`/`000000012239` | incorporate | applied |
| C08 | UID0002C6 does not clear the pending event before each read. | Very strong | full decompile | UID0002C6 body/evidence; validator `000000012235` | incorporate | applied |
| C09 | UID0002C6 count-gated payload cleanup has no extra null test. | Very strong | full decompile | UID0002C6 body/evidence; validator `000000012235` | incorporate | applied |
| C10 | UID0002C6 primes only allowed replay after existing end state. | Very strong | current decompile and B012 recheck | UID0002C6 body/history retained and revalidated by `000000012235` | already-present | already-present |
| C11 | UID0002C6 track scan is 0x28 stride, active flag bit 0, minimum `+0x14` tick. | Very strong | decompile/layout cross-check | UID0002C6 and UID0002B1 evidence; validators `000000012235`/`000000012238` | incorporate | applied |
| C12 | UID0002C6 exact result/status behavior is retained. | Very strong | constants/branches | UID0002C6 body; validator `000000012235`; one generated definition under `000000012277` | incorporate | applied |
| C13 | UID0002C6 must emit one body, not two extra helper definitions. | Very strong | one function object/range | UID0002C6 Destination 2; validator `000000012235`; generated reset/select helper counts zero under `000000012277` | incorporate | applied |
| C14 | UID0002C7 exactly covers `0x005273a0-0x005277bb`, 1051 bytes. | Very strong | lookup/bytes/hash | UID0002C7; validators `000000012236` and post-rename `000000012259` | already-present | already-present |
| C15 | UID0002C7 is best modeled as private `MidiDocument::Load`. | Strong | ECX receiver, retn 4, object constructor | UID0002C7 formal/status and UID0002B1 declaration; validators `000000012236`/`000000012238`/`000000012259`; generated command `000000012277` | incorporate | applied |
| C16 | UID0002C7 returns `0` success and `1` failure. | Very strong | full decompile, UID0002C5/caller | UID0002C7 and UID0002C5 bodies; validators `000000012236`/`000000012237`/`000000012259` | incorporate | applied |
| C17 | UID0002C5 reports failure and must not retain `Succeeded` identity. | Very strong | exact `== 1`, caller test | UID0002C5 UID-preserving rename/formal; validator `000000012237` path update plus final generated old-identity count zero | incorporate | applied |
| C18 | Loader initialization does not clear payload count. | Very strong | exact field writes | UID0002C7 body/layout evidence; validators `000000012236`/`000000012259` | incorporate | applied |
| C19 | First `MThd` tag read is raw success-plus-count checked. | Very strong | direct adapter/ReadFile branch | UID0002C7 body; validators `000000012236`/`000000012259` | incorporate | applied |
| C20 | Header tail is one exact `headerLength` read after `length >= 6`. | Very strong | direct call width/stack target | UID0002C7 body/history; validators `000000012236`/`000000012259` | incorporate | applied |
| C21 | Loader does not reject zero tracks. | Very strong | branch/loop decompile | UID0002C7 body; validators `000000012236`/`000000012259` | incorporate | applied |
| C22 | Table allocation uses 0x40; per-track 0x400 buffer uses 0x42. | Very strong | immediate operands | UID0002C7 body/evidence; validators `000000012236`/`000000012259` | incorporate | applied |
| C23 | Per-track buffer allocation precedes `MTrk` validation. | Very strong | instruction order | UID0002C7 body; validators `000000012236`/`000000012259` | incorporate | applied |
| C24 | Track offsets are queried before and after initial read. | Very strong | source seek calls | UID0002C7 body/layout; validators `000000012236`/`000000012259` | incorporate | applied |
| C25 | Initial raw read is performed even for zero length. | Very strong | unconditional call | UID0002C7 body; validators `000000012236`/`000000012259` | incorporate | applied |
| C26 | Empty-track done condition is both buffered and remaining counts zero. | Very strong | exact condition | UID0002C7 body; validators `000000012236`/`000000012259` | incorporate | applied |
| C27 | Failure cleanup closes source and frees every allocated block before returning 1. | Very strong | converged cleanup | UID0002C7 and UID0001CI support; validators `000000012236`/`000000012243`/`000000012259` | incorporate | applied |
| C28 | UID0002C7 must emit one body; swap expressions remain inside it. | Very strong | one function object/no swap child | UID0002C7 Destination 3; validators `000000012236`/`000000012259`; generated swap-helper counts zero under `000000012277` | incorporate | applied |
| C29 | `MidiTrackState` is 0x28 with exact documented fields. | Very strong | loader/reader/prime/release offsets | UID0002B1 declarations/support; validator `000000012238` | incorporate | applied |
| C30 | `MidiEvent` is 0x10 with payload length/pointer at +8/+C. | Very strong | scratch/xrefs/reader/encoder | UID0002B2 formal retained and evidence expanded; validator `000000012239` | already-present | already-present |
| C31 | Write context is 0x54: MIDIHDR-compatible 0x40 plus five dwords. | Very strong | caller storage/helper offsets/SDK type | UID0002B1 Destination 5; validator `000000012238` | incorporate | applied |
| C32 | `MidiDocument` is 0x48 with exact fields through +0x40 and alignment tail. | Strong | constructor, all family accesses, global boundary | UID0002B1 Destination 5; validator `000000012238` | incorporate | applied |
| C33 | Scratch storage remains private static under UID0002B2, not object fields. | Very strong | xref confinement/storage address | UID0002B2/UID0000T9; validators `000000012239`/`000000012248` | already-present | already-present |
| C34 | Current source route remains `NexusTK/audio/MidiPlayer.cpp`. | Strong | adjacency/callers/current owner/no better file route | UID0000LD/UID00008A/UID0000T9; validators `000000012277`/`000000012247`/`000000012248` | incorporate | applied |
| C35 | A new `MidiSMFDocument.cpp` or duplicate by-type emitter is rejected. | Strong | no filename/symbol/route; duplicate declarations | Target/file/class/global rejected-alternative sections preserved; no page or emitter created | reject-invalid | excluded-with-reason |
| C36 | `DATFile`, `MidiPlayer` instance ownership, and `SoundManager` are rejected. | Very strong | embedded subobject, receiver identity, subsystem calls | Target/file/class/global ownership sections; validators `000000012247`/`000000012248`/`000000012277`; no owner changed | reject-invalid | excluded-with-reason |
| C37 | Callback must call the corrected document operation without changing callback behavior. | Strong | direct caller and current formal | UID0001CG Destination 6; validator `000000012240`; generated one `g_midiDocumentState.FillStreamBuffer` call under `000000012277` | incorporate | applied |
| C38 | Leading/trailing padding remains UID0000VN compiler-only and unchanged. | Very strong | exact all-CC hashes | Read-only `by-memory/-ignored.md` combined row at line 4128 retained exactly; no ordinary edit | already-present | already-present |
| C39 | Scores materially increase but stay below original-symbol/final-audit levels. | Strong | blocker closure and residual name uncertainty | Target/UID0002C6/UID0002C7/UID0002C5/UID0002B1/UID0002B2 validators `000000012234`-`000000012239` | incorporate | applied |
| C40 | Manual coverage rows are stale and require supervisor-owned replacements below. | Very strong | direct read-only row comparison | Exact text retained below; B004 performed no manual coverage edit; validator `000000012237` separately propagated the renamed UID link as an automatic side effect | incorporate | excluded-with-reason |

### Callback Destination And Artifact Proof

- Destination 1, UID00023C: current SHA256 `153D9F7878E503DD644D57BB39240FD5C0F9F14BA5A1CE38CD982A9C4C360804`; validator `000000012234`; current `91/94`, owner UID0000LD, false, blank emitter/position/formal C++, `Nested:0`; the parent retains the complete range/hash/caller/layout/history/negative evidence and emits nothing.
- Destination 2, UID0002C6: current SHA256 `7CE78274E5A93CF90F4E7486B1AF994971C214ECD73ACD8EA801074D9AFA2D20`; validator `000000012235`; current `92/94`; exact 496-byte range, two callers, four callees, scratch xrefs, replay rule, reset/per-event negative writes, count-gated payload cleanup, result values, and one-body disposition retained.
- Destination 3, UID0002C7: current SHA256 `4DAAD43118C12906A810140CC2DB54C7FEE4E852E8777939F189C42A7B3F0E80`; initial validator `000000012236` and post-rename/current-wording validator `000000012259`; current `93/94`; exact 1,051-byte range, single failure-wrapper caller, source split, raw first tag, full-width header read, zero-track success, allocation flags/order, two source-position queries, zero-length read, first-VLQ seed, converged cleanup, and one-body inline-swap disposition retained.
- Destination 4, UID0002C5: current SHA256 `04FF93AC49F0854834B80C16CC06B6482AED153217F39A5CBD6A7EF7A32B0D35`; validator-aware command `000000012237` moved the old path exactly once to `by-memory/0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md`, recorded `path_update`, eight reverse source-path updates, and nineteen UID-link updates. The old path is absent, the new path exists, UID0002C5 occurs once in its header, and generated old-name counts are zero.
- Destination 5, UID0002B1: current SHA256 `46B59A1B881C6865B2899E2DD22F254FF74C0086CBB00D4C8139DF22235C69B3`; validator `000000012238`; current `91/93`; all unrelated WinMM state/initializers remain while the exact private 0x48 document, 0x28 track, 0x54 write context, result enum, and method declarations are emitted at position 0.
- Destination 6, UID0001CG: current SHA256 `8586CFD0895DD828CB63D1FC473EC1D997C81137A31506852CF20C63B785D966`; validator `000000012240`; score and callback ABI/branches remain unchanged, and only the accepted `g_midiDocumentState.FillStreamBuffer` source contract changed.
- Mechanical exact-block comparison found six report-managed blocks and returned `True` for Destinations 1 through 6 against their current destination pages after all validators. No draft/example C++ was added outside the formal headers.
- UID0002B2 current SHA256 `35A2F232B90D43789CD0971D1038047775911591BBF4822218B845C54CDF9167`; validator `000000012239`; current `89/92`, with formal declarations/owner/position unchanged and current scratch/reset evidence added.
- Narrative/support proof: UID0001CE SHA256 `E4F1E7D3A9EC1772C31F7937AD2F9A0AB3EEBBE06A84EF6FB697D19808FEE763` (`000000012241`); UID0001CI SHA256 `E08F431192BB65EBD207FC060F58C964968459982748B1FF79AE450978C7DC38` (`000000012243`); UID00023B SHA256 `1CAAC43E3BE7B96E8CFE4A3058187FC885521AE77A132185E8D8AA8A3299B93D` (`000000012246`); by-class/MidiPlayer SHA256 `30AF72043A6AF27E03DF774DF0CB3CB3F987FD51BB58F81D8220326D0F22E3CD` (`000000012247`); by-global/MidiPlayerWinMMState SHA256 `65CCEE80B78233E95AD675225E8F51DA580C8151343CFB691E5DA12A21B2D476` (`000000012248`); validator-propagated UID0002C4 SHA256 `9CC93B2879E76DE8584DAB28C1C70117CD97ABDDA7C6A595CC8328ABF1508087` (`000000012251`); by-file/MidiPlayer SHA256 `41B2A4FB8CA687B84E53202A1F6C1865A488DE18B17FD0B4328B351C275782B8` (`000000012277`).
- UID0000VN verification remained read-only: `by-memory/-ignored.md` line 4128 still records `[0x005271a3,0x005271b0)` and `[0x005277bb,0x005277c0)` as compiler/linker `0xcc` alignment with the same adjacent owners. No padding edit or validator was needed.
- Lease closure proof: every ordinary page was leased immediately before its bounded reread/edit/validation and unleased immediately afterward. A final read-only target stale-token check was also released without an edit. `tools/leaser/Agents/current_leases.md`, written `2026-07-14T21:33:19-04:00`, contained zero `B004` rows after the callback.

## Positive Evidence Summary

- Exact function boundaries, hashes, instruction counts, callers, callees, status constants, allocation flags, and cleanup branches directly support the split and source behavior.
- The private object is real: constructor `0x00527080` initializes the same state and embedded `DATFile`; every modeled parser operation uses the state pointer in ECX.
- Current docs already establish a valid UID0000LD emitter route and exact child pages, so the repair does not invent ownership or require a new source root.
- Scratch xref confinement and exact padding hashes cleanly separate source storage, source code, parent index, and compiler alignment.
- The strongest inference chain is constructor/object layout plus repeated thiscall ABI plus adjacent private operations plus same-family callers. That is sufficient for a private `MidiDocument` source contract while keeping spellings explicitly descriptive.

## IDA MCP Facts

- Function/range facts: `sub_5271B0` is 0x1f0 bytes with 36 basic blocks and cyclomatic complexity 17; `sub_5273A0` is 0x41b bytes. There is no modeled function at `0x005277bb`.
- Data/table/padding facts: exact 0x28 track stride, 0x10 event scratch, 0x54 stream context, 0x48 document storage, thirteen leading CC bytes, five trailing CC bytes.
- Xref facts: two UID0002C6 callers, one UID0002C7 caller, one UID0002C5 caller, three UID0001CI callers, and scratch refs confined to UID0002C6.
- Vtable/global/type facts: no private MIDI type remains in IDA; SDK `MIDIHDR` is 0x40. The embedded `DATFile` path uses its virtual/interface calls, but the private document itself has no vtable evidence.
- Negative IDA facts: no pointer bytes to target starts, no third child, no source-name symbols, no separate swap functions, and no scratch consumer outside UID0002C6.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005271a3-0x005271b0` | UID0000VN `by-memory/-ignored.md` | 13-byte alignment | FALSE | none | 100/strong | unchanged compiler-only |
| `0x005271b0-0x005277bb` | UID00023C target | exact index over two children | FALSE | UID0000LD semantic owner | 91/94 | reclassify; no emitter/C++ |
| `0x005271b0-0x005273a0` | UID0002C6 | `MidiDocument::FillStreamBuffer` | TRUE | UID00023C | 92/94 | correct formal body; `Nested:4` |
| `0x005273a0-0x005277bb` | UID0002C7 | `MidiDocument::Load` | TRUE | UID00023C | 93/94 | correct formal body; `Nested:0` |
| `0x005277bb-0x005277c0` | UID0000VN `by-memory/-ignored.md` | 5-byte alignment | FALSE | none | 100/strong | unchanged compiler-only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005271b0` | callers `0x00525a51`, `0x00525d3a` | initial two-buffer fill and asynchronous callback refill |
| `0x005271b0` | callees `0x00526790`, `0x005269f0`, `0x00526da0`, free thunk | event read, WinMM write, replay prime, payload cleanup |
| `0x005273a0` | caller `0x005270c6` | one failure-predicate wrapper |
| `0x005273a0` | project callees `0x00526650`, `0x00527000`, `0x00526bb0`, `0x0049c540` | exact read, raw read, first VLQ, DAT readiness |
| `0x0069b870-0x0069b88c` | all direct refs in `0x005271b0-0x005273a0` | private persistent fill scratch, not object fields |
| `0x005270c0` | caller `0x0052599d`; callee `0x005273a0` | true means load failed, causing stream-open failure return |
| `0x005270e0` | callers `0x00525af2`, `0x00525d91`, `0x00526514` | shared document resource release outside loader's inline cleanup |

## Documentation Evidence And IDA Status

- Existing docs support exact ranges, UID routing, track/event field maps, scratch names, replay correction, and source-family ownership.
- Existing docs are stale or contradicted on the parent true/emitting marker, C6 extra helper/write behavior, C7 success polarity/header handling/allocation details, and C5 `SuccessWrapper` identity.
- Generated source reflects those same stale formal blocks. It is evidence of documentation state, not executable truth.
- Manual coverage is older still: target is shown at 84%, children at 78%, UID0002B1 at 85%, UID0002B2 at 82%, and callback at 82%.

## Ranked Ownership Analysis

### 1. UID0000LD `MidiPlayer.cpp` with private `MidiDocument` source type

- Evidence for: contiguous MidiPlayer WinMM family, all callers in stream open/callback/parser wrapper, existing valid emitter chain, private static state, embedded DAT adapter, no competing source path, and historical project routing.
- Evidence against: original filename and private type spelling are stripped.
- Decision: accepted owner/emitter route. The name is descriptive; behavior and routing are strong.

### 2. Separate private `MidiSMFDocument.cpp`

- Evidence for: cohesive parser object, constructor, methods, and source helpers could have lived in a narrow implementation file before linking adjacent to MidiPlayer code.
- Evidence against: no filename, path string, symbol, separate by-file page, source-tree entry, or stronger link-order boundary. Helpers directly coordinate MidiPlayer static state and callback buffers.
- Decision: rejected as current routing. Preserve only as historical source-layout possibility.

### 3. `DATFile`, `MidiPlayer` class, `SoundManager`, or generic file I/O

- Evidence for: `DATFile` is embedded; `MidiPlayer` owns the subsystem; `SoundManager` is adjacent conceptually to audio.
- Evidence against: `DATFile` is only one source adapter; the receiver is the private 0x48-byte document, not the 12-byte `MidiPlayer`; SoundManager uses a different audio stack; generic I/O does not own MIDI parsing and WinMM events.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable. No new file page is recommended.
- Likely full contents: existing `NexusTK/audio/MidiPlayer.cpp` already groups the private declarations, parser methods, callbacks, globals, and player controller.
- Candidate related items that belong: UID00023B children, UID0001CI, UID0002C4/C5, UID0002C6/C7, and WinMM state declarations remain under UID0000LD.
- Candidate related items rejected: `DATFile` implementation, SoundManager/Miles code, UI music controls.
- Standalone, narrow, or broad source-file inference: a narrow historical SMF source split is plausible but unproved and therefore not routed.

## Source Placement

- Recommended placement: private declarations and helper implementations in `NexusTK/audio/MidiPlayer.cpp`, with `MidiDocument` represented as a private source type and UID0000LD as emitter.
- This fits the source tree because the exact callers, globals, callback, stream headers, and player lifecycle are all in the same WinMM module.
- Rejected placements: a new MIDI document file, DATFile, MidiPlayer class methods, SoundManager, and generic file support.
- Remaining uncertainty: original filename and spellings. That uncertainty caps confidence but does not block current placement or C++.

## Range / Split / Padding / Reclassification Analysis

- Exact target interval length is 0x60b and equals 0x1f0 plus 0x41b exactly. No byte remains for a parent body.
- UID0002C6 starts with a standard prologue and ends `C2 0C 00`; UID0002C7 starts immediately at `0x005273a0` and ends `C2 04 00` at `0x005277bb`.
- Leading and trailing padding are outside the parent interval and already represented by UID0000VN.
- Parent impact: retain the index, child table, evidence, and owner link; change only source eligibility/emission metadata and remove managed prose C++.
- Child impact: no split/create/merge. Correct the two exact bodies and dependent declarations/call site.

## Negative Evidence Summary

- No third function, jump table, static storage, literal range, or source declaration exists inside UID00023C.
- No target-start pointer bytes or callback/data route exists; all live routes are direct relative calls to exact children.
- No current type catalog entry proves original `MidiDocument`, `MidiTrackState`, or helper spellings.
- No source artifact supports a separate file route.
- Consumer calls prove liveness but do not independently prove original names; names remain descriptive.
- Adjacent UID0001CI and UID00023B prove family continuity, not parent source emission.
- The embedded `DATFile` dependency does not transfer ownership of SMF parsing, track selection, WinMM output, or scratch state.

## IDA Rename / Type / Comment Recommendations

- Source-facing names: `MidiDocument::FillStreamBuffer`, `MidiDocument::Load`, `MidiDocument::LoadFailed`, `MidiTrackState`, `MidiEvent`, `MidiStreamWriteContext`, `MidiLoadResult`, and existing named fill results.
- UID0002C5 documentation path/title: rename in place from `MidiParseSuccessWrapper` to `MidiDocumentLoadFailureWrapper`; do not change UID.
- Parent target title/path: retain for stable aggregate indexing; change its entity description to non-emitting index.
- Raw IDA names: no IDA DB rename is requested. B004's research/callback scope forbids IDA mutation, and original symbol proof is absent.
- Type direction: retain exact layouts in UID0002B1/UID0002B2. Do not create a duplicate type emitter unless a future supervisor explicitly separates declarations and updates ordering.

## First-Draft C++ Recommendation

- Eligible for draft C++: UID0002C6, UID0002C7, UID0002C5, UID0002B1, and the dependent UID0001CG call site. UID00023C itself is ineligible because it is only an index.
- The six exact managed destination blocks follow. No body-only example exists elsewhere in this report.

### Destination 1 - UID00023C parent, exact blank managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - UID0002C6 `MidiStreamBufferFillHelper`, complete managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int MidiDocument::FillStreamBuffer(BOOL resetState, MidiStreamWriteContext* stream, BOOL allowEndReplay)
{
    stream->bytesWritten = 0;

    DWORD state;
    if (resetState) {
        state = 0;
        g_midiFillState = 0;
        ZeroMemory(&g_midiPendingEvent, sizeof(g_midiPendingEvent));
        g_midiSelectedTrack = NULL;
        g_midiTrackScanCursor = NULL;
    } else {
        state = g_midiFillState;
    }

    if ((state & MIDI_FILL_AT_END) != 0) {
        if (!allowEndReplay) {
            return MIDI_FILL_END_OF_STREAM;
        }

        MidiPrimeTracks(this);
        g_midiFillState = 0;
    } else if ((state & MIDI_FILL_PARSE_ERROR) != 0) {
        return MIDI_FILL_PREVIOUS_PARSE_FAILED;
    } else if ((state & MIDI_FILL_PENDING_EVENT) != 0) {
        g_midiFillState = state ^ MIDI_FILL_PENDING_EVENT;

        if (g_midiPendingEvent.status == MIDI_STATUS_META &&
            g_midiPendingEvent.data1 == MIDI_META_END_OF_TRACK) {
            if (allocatedPayloadCount != 0) {
                free(g_midiPendingEvent.payload);
                --allocatedPayloadCount;
            }
        } else if (MidiWriteStreamEvent(this, &g_midiPendingEvent, stream) == MIDI_FILL_OUTPUT_FULL) {
            g_midiFillState |= MIDI_FILL_PENDING_EVENT;
            return MIDI_FILL_OK;
        }
    }

    for (;;) {
        DWORD remaining = trackCount;
        MidiTrackState* cursor = tracks;
        MidiTrackState* selected = NULL;
        DWORD selectedTick = 0xFFFFFFFF;

        g_midiSelectedTrack = NULL;
        g_midiSelectedTick = 0xFFFFFFFF;
        g_midiTrackScanCursor = cursor;

        while (remaining != 0) {
            if ((cursor->flags & MIDI_TRACK_DONE) == 0 &&
                cursor->pendingTick < selectedTick) {
                selected = cursor;
                selectedTick = cursor->pendingTick;
            }
            ++cursor;
            --remaining;
        }

        g_midiTrackScanCursor = cursor;
        g_midiSelectedTick = selectedTick;
        g_midiSelectedTrack = selected;

        if (selected == NULL) {
            g_midiFillState |= MIDI_FILL_AT_END;
            return MIDI_FILL_OK;
        }

        if (MidiReadEvent(this, selected, &g_midiPendingEvent) != 0) {
            g_midiFillState |= MIDI_FILL_PARSE_ERROR;
            return MIDI_FILL_PARSE_FAILED;
        }

        if (g_midiPendingEvent.status == MIDI_STATUS_META &&
            g_midiPendingEvent.data1 == MIDI_META_END_OF_TRACK) {
            if (allocatedPayloadCount != 0) {
                free(g_midiPendingEvent.payload);
                --allocatedPayloadCount;
            }
        } else if (MidiWriteStreamEvent(this, &g_midiPendingEvent, stream) == MIDI_FILL_OUTPUT_FULL) {
            g_midiFillState |= MIDI_FILL_PENDING_EVENT;
            return MIDI_FILL_OK;
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID0002C7 `MidiSMFDocumentLoadHelper`, complete managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int MidiDocument::Load(const wchar_t* path)
{
    struct MidiHeaderFields {
        WORD format;
        WORD trackCount;
        WORD division;
    } header;

    DWORD tag;
    DWORD headerLength;
    DWORD bytesRead;
    DWORD i;
    HGLOBAL tableHandle;

    currentTick = 0;
    timeDivision = 0;
    format = 0;
    trackCount = 0;
    sourceSize = 0;
    tracks = NULL;

    MidiOpenSource(this, path);
    if (!MidiSourceIsReady(this)) {
        goto load_failed;
    }

    if (MidiReadRaw(this, &tag, sizeof(tag), &bytesRead) == 0 ||
        bytesRead != sizeof(tag) || tag != MIDI_TAG_MTHD) {
        goto load_failed;
    }

    if (MidiReadExact(this, &headerLength, sizeof(headerLength)) != 0) {
        goto load_failed;
    }

    headerLength = ((headerLength & 0x000000FF) << 24) |
                   ((headerLength & 0x0000FF00) << 8) |
                   ((headerLength & 0x00FF0000) >> 8) |
                   ((headerLength & 0xFF000000) >> 24);

    if (headerLength < sizeof(header) ||
        MidiReadExact(this, &header, headerLength) != 0) {
        goto load_failed;
    }

    format = (WORD)((header.format << 8) | (header.format >> 8));
    trackCount = (WORD)((header.trackCount << 8) | (header.trackCount >> 8));
    timeDivision = (WORD)((header.division << 8) | (header.division >> 8));

    tableHandle = GlobalAlloc(GMEM_ZEROINIT,
                              sizeof(MidiTrackState) * trackCount);
    tracks = (MidiTrackState*)GlobalLock(tableHandle);
    if (tracks == NULL) {
        goto load_failed;
    }

    for (i = 0; i < trackCount; ++i) {
        MidiTrackState* track = tracks + i;

        HGLOBAL bufferHandle = GlobalAlloc(GHND, MIDI_STREAM_BUFFER_BYTES);
        track->buffer = (BYTE*)GlobalLock(bufferHandle);
        if (track->buffer == NULL ||
            MidiReadExact(this, &tag, sizeof(tag)) != 0 ||
            tag != MIDI_TAG_MTRK ||
            MidiReadExact(this, &headerLength, sizeof(headerLength)) != 0) {
            goto load_failed;
        }

        headerLength = ((headerLength & 0x000000FF) << 24) |
                       ((headerLength & 0x0000FF00) << 8) |
                       ((headerLength & 0x00FF0000) >> 8) |
                       ((headerLength & 0xFF000000) >> 24);

        track->trackLength = headerLength;
        track->trackStartOffset = MidiSeekSource(this, 0, FILE_CURRENT);

        DWORD firstRead = track->trackLength;
        if (firstRead > MIDI_STREAM_BUFFER_BYTES) {
            firstRead = MIDI_STREAM_BUFFER_BYTES;
        }

        if (MidiReadRaw(this, track->buffer, firstRead, &bytesRead) == 0 ||
            bytesRead != firstRead) {
            goto load_failed;
        }

        track->bytesRemaining = track->trackLength - bytesRead;
        track->bufferedBytes = bytesRead;
        track->sourceOffset = MidiSeekSource(this, 0, FILE_CURRENT);
        track->cursor = track->buffer;
        track->flags = 0;
        track->runningStatus = 0;
        track->pendingTick = 0;

        if (track->bufferedBytes != 0 || track->bytesRemaining != 0) {
            if (MidiReadVariableLength(this, track, &track->pendingTick) != 0) {
                goto load_failed;
            }
        } else {
            track->flags = MIDI_TRACK_DONE;
        }

        MidiSeekSource(this,
                       (LONG)(track->trackStartOffset + track->trackLength),
                       FILE_BEGIN);
    }

    return MIDI_LOAD_OK;

load_failed:
    MidiReleaseDocument(this);
    return MIDI_LOAD_FAILED;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID0002C5 renamed `MidiDocumentLoadFailureWrapper`, complete managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
BOOL MidiDocument::LoadFailed(const wchar_t* path)
{
    return Load(path) == MIDI_LOAD_FAILED;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - UID0002B1 `MidiPlayerWinMMStateGlobals`, complete managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const unsigned int MIDI_RESET_SKIP_REOPEN = 0x00010000;
static const unsigned int MIDI_TRACK_PATH_CHARS = 260;
static const unsigned short MIDI_TRACK_NONE = (unsigned short)-1;
static const unsigned int MIDI_STREAM_BUFFER_BYTES = 0x400;

static const DWORD MIDI_STREAM_STATE_STOPPING = 100;
static const DWORD MIDI_STREAM_STATE_IDLE = 200;
static const DWORD MIDI_STREAM_STATE_FLUSHING = 300;

static const DWORD MIDI_TRACK_DONE = 0x00000001;
static const DWORD MIDI_TAG_MTHD = 0x6468544D;
static const DWORD MIDI_TAG_MTRK = 0x6B72544D;

static const BYTE MIDI_STATUS_CONTROL_CHANGE = 0xB0;
static const BYTE MIDI_STATUS_PROGRAM_CHANGE = 0xC0;
static const BYTE MIDI_STATUS_CHANNEL_PRESSURE = 0xD0;
static const BYTE MIDI_STATUS_SYSEX = 0xF0;
static const BYTE MIDI_STATUS_ESCAPE = 0xF7;
static const BYTE MIDI_STATUS_META = 0xFF;
static const BYTE MIDI_CONTROLLER_VOLUME = 7;
static const BYTE MIDI_META_END_OF_TRACK = 0x2F;
static const BYTE MIDI_META_TEMPO = 0x51;

enum MidiLoadResult {
    MIDI_LOAD_OK = 0,
    MIDI_LOAD_FAILED = 1
};

struct MidiTrackState {
    DWORD flags;
    DWORD trackLength;
    DWORD bufferedBytes;
    BYTE* buffer;
    BYTE* cursor;
    DWORD pendingTick;
    BYTE runningStatus;
    BYTE reservedStatus[3];
    DWORD trackStartOffset;
    DWORD sourceOffset;
    DWORD bytesRemaining;
};

struct MidiStreamWriteContext {
    LPSTR buffer;
    DWORD bufferLength;
    DWORD bytesRecorded;
    DWORD_PTR user;
    DWORD flags;
    MIDIHDR* next;
    DWORD_PTR reserved;
    DWORD offset;
    DWORD reservedWords[8];
    DWORD writeOffset;
    DWORD writeLimit;
    DWORD bytesWritten;
    DWORD lastEventTick;
    DWORD fullEventPending;
};

struct MidiStreamHeaderSlot {
    MIDIHDR header;
    DWORD writeOffset;
    DWORD writeLimit;
    DWORD bytesWritten;
    DWORD lastEventTick;
    DWORD fullEventPending;
};

struct MidiDocument {
    MidiDocument();

    int Load(const wchar_t* path);
    BOOL LoadFailed(const wchar_t* path);
    int FillStreamBuffer(BOOL resetState,
                         MidiStreamWriteContext* stream,
                         BOOL allowEndReplay);

    DWORD sourceSize;
    DWORD timeDivision;
    DWORD format;
    DWORD trackCount;
    MidiTrackState* tracks;
    DWORD datFileSource;
    DATFile datFile;
    HANDLE fileHandle;
    DWORD currentTick;
    DWORD allocatedPayloadCount;
    DWORD tempoTickCache;
    DWORD tempoScalePercent;
    DWORD tempoUSecPerQuarter;
};

static HMIDISTRM g_hMidiStream;
static UINT g_midiDeviceId;
static DWORD g_midiStreamState;
static DWORD g_midiRestartPending;
static BOOL g_midiAllowEndReplay;
static BOOL g_midiDocumentLoaded;
static BOOL g_midiStreamRunning;
static BOOL g_midiCallbackStreamOpen;
static BOOL g_midiHeadersPrepared;
static DWORD g_midiVolumeScale;
static MidiStreamHeaderSlot g_midiHeaders[2];
static DWORD g_midiChannelVolume[16];
static DWORD g_midiActiveHeaderIndex;
static DWORD g_midiPendingBufferCount;
static wchar_t g_midiCurrentPath[MIDI_TRACK_PATH_CHARS];
static HANDLE g_hMidiBufferEvent;
__declspec(align(8)) static MidiDocument g_midiDocumentState;
static DWORD g_midiEndOfStreamReached;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6 - UID0001CG `MidiStreamCallback`, complete managed block

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void CALLBACK MidiStreamCallback(HMIDIOUT hMidiOut,
                                        UINT message,
                                        DWORD_PTR instance,
                                        DWORD_PTR param1,
                                        DWORD_PTR param2)
{
    (void)hMidiOut;
    (void)instance;
    (void)param2;

    if (message == MOM_POSITIONCB) {
        MIDIHDR* header = (MIDIHDR*)param1;
        BYTE* eventBase = (BYTE*)header->lpData + header->dwBytesRecorded;
        DWORD event = *(DWORD*)(eventBase + 8);
        BYTE controller = (BYTE)((event >> 8) & 0xff);

        if ((event & 0xf0) == MIDI_STATUS_CONTROL_CHANGE &&
            controller != 0x27 &&
            controller == MIDI_CONTROLLER_VOLUME) {
            unsigned int channel = event & 0x0f;
            unsigned int volume = (event >> 16) & 0x7f;

            g_midiChannelVolume[channel] = volume;
            if (g_midiStreamRunning != 0) {
                DWORD scaled = (g_midiVolumeScale * g_midiChannelVolume[channel]) / 1000;
                DWORD outgoing = MIDI_STATUS_CONTROL_CHANGE |
                                 channel |
                                 (MIDI_CONTROLLER_VOLUME << 8) |
                                 (scaled << 16);
                midiOutShortMsg((HMIDIOUT)g_hMidiStream, outgoing);
            }
        }
        return;
    }

    if (message != MOM_DONE) {
        return;
    }

    if (g_midiStreamState == MIDI_STREAM_STATE_IDLE) {
        return;
    }

    ++g_midiPendingBufferCount;

    if (g_midiStreamState == MIDI_STREAM_STATE_FLUSHING) {
        if (g_midiPendingBufferCount >= 2) {
            g_midiStreamState = MIDI_STREAM_STATE_IDLE;
            MidiPlayer_ResetStream(0);
            SetEvent(g_hMidiBufferEvent);
        }
        return;
    }

    if (g_midiStreamState == MIDI_STREAM_STATE_STOPPING) {
        if (g_midiPendingBufferCount >= 2) {
            g_midiStreamState = MIDI_STREAM_STATE_IDLE;
            SetEvent(g_hMidiBufferEvent);
        }
        return;
    }

    if (g_midiStreamRunning == 0 || g_midiPendingBufferCount == 0) {
        return;
    }

    MIDIHDR* header = &g_midiHeaders[g_midiActiveHeaderIndex].header;
    MidiStreamWriteContext* stream = (MidiStreamWriteContext*)header;
    stream->writeOffset = 0;
    stream->writeLimit = MIDI_STREAM_BUFFER_BYTES;
    stream->bytesWritten = 0;
    stream->lastEventTick = 0;
    stream->fullEventPending = 0;

    int fillResult = g_midiDocumentState.FillStreamBuffer(FALSE,
                                                          stream,
                                                          g_midiAllowEndReplay);
    if (fillResult != MIDI_FILL_OK) {
        if (fillResult == MIDI_FILL_END_OF_STREAM) {
            g_midiEndOfStreamReached = 1;
            g_midiStreamState = MIDI_STREAM_STATE_FLUSHING;
            return;
        }

        MidiDocumentRelease(&g_midiDocumentState);
        return;
    }

    header->dwBytesRecorded = stream->bytesWritten;
    if (midiStreamOut(g_hMidiStream, header, sizeof(MIDIHDR)) != MMSYSERR_NOERROR) {
        MidiDocumentRelease(&g_midiDocumentState);
        return;
    }

    g_midiActiveHeaderIndex = (g_midiActiveHeaderIndex + 1) % 2;
    --g_midiPendingBufferCount;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Behavior preservation: the target bodies preserve every observed branch, status, read width, allocation flag/order, field write, source-position query, cleanup route, and return value identified above.
- Mid-2000s source shape: explicit Win32 types, `GlobalAlloc`/`GlobalLock`, simple private structs, goto-based cleanup, local byte swapping, and a private implementation type are consistent with the existing module and compiler era.
- Inferred names are explicitly descriptive. No raw `sub_`, `unk_`, `dword_`, or offset expression is introduced into emitted source.
- Third-party import directive: not applicable. This is project-owned executable logic, not a vetted static source embed.
- Exact no-code proof for UID00023C: its byte interval is exhausted by UID0002C6 plus UID0002C7, and it owns no separate declaration/storage/body. Only the parent managed block remains blank.

## Final Recommendation

- C01-C40 are incorporated at report-level detail with terminal ledger states and destination/validator proof.
- UID00023C is `91/94`, false, with no emitter/position/C++, owner UID0000LD, and `Nested:0`.
- UID0002C6 is `92/94`, true, owner/emitter UID0000LD, blank position, `Nested:4`, with Destination 2 exact.
- UID0002C7 is `93/94`, true, owner/emitter UID0000LD, blank position, `Nested:0`, with Destination 3 exact.
- UID0002C5 retains its UID at `0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md`, is `90/93`, and matches Destination 4. The old path and old generated identity are absent.
- UID0002B1 is `91/93` with Destination 5, owner/emitter UID0000T9, and position 0 retained. UID0002B2 is `89/92` with storage/formal C++/owner/position retained and no duplicate declarations.
- UID0001CG matches Destination 6 without score or unrelated callback changes. UID0000VN padding remains unchanged and verify-only; unrelated parser children retain their bodies/scores except validator-managed reverse-link propagation.
- No implementation item remains. Original symbol recovery is outside the available artifact set and remains only a confidence cap. Report review/execution/manual coverage/count/move/archive state is external supervisor/validator-owned.

## Recommended Target Doc Changes

- Applied target path: `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md`.
- Metadata and Destination 1 match the accepted recommendation exactly under validator `000000012234`.
- The page now uses non-emitting index wording while retaining the complete child inventory, bytes/hashes, callers/callees, layouts, source route, historical reports, rejected alternatives, and exact padding facts.
- The old true/prose-marker treatment is explicitly historical/rejected, and all child correctness/source-contract conclusions are present without evidence compression.

## Recommended Support Doc Changes

- `by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md` now matches Destination 2 at `92/94` with C04-C13 and complete replay/caller/callee/hash history.
- `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md` now matches Destination 3 at `93/94` with C14-C28, adapter/Win32 split, cleanup, negatives, and historical draft corrections.
- UID0002C5 was moved once through validator-aware UID preservation to `by-memory/0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md`, matches Destination 4 at `90/93`, and has current ordinary reverse links.
- `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md` matches Destination 5 at `91/93`; exact layouts/method declarations were added without removing unrelated WinMM state.
- `by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md` retains formal declarations/owner/position and is `89/92` with current xref/reset evidence.
- `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md` matches Destination 6 with score, callback ABI, branches, and unrelated content preserved.
- UID0001CE, UID0001CI, and UID00023B received only accepted narrative/link corrections; formal blocks and scores remain preserved.
- by-file/MidiPlayer, by-class/MidiPlayer, and by-global/MidiPlayerWinMMState contain the accepted parent/method/polarity/layout/ownership synchronization with their scores/formal dispositions unchanged.
- `by-memory/-ignored.md` was verified read-only; the two padding spans remain exact. Existing UID0002BU/0002BV/0002BY/0002BS/0002BT/0002BW/0002BX/0002BZ/0002C0/0002C1/0002C2/0002C3 bodies and scores remain unchanged; UID0002C4 changed only by validator-managed reverse-link propagation and was revalidated.

## Score And Metadata Recommendation

- Historical target transition: `86/90`, owner/emitter UID0000LD, true, prose marker, `Nested:0` -> current `91/94`, owner UID0000LD, false, blank emitter/position/formal block, `Nested:0`.
- UID0002C6 is currently `92/94` from `88/91`, with owner/emitter/true/blank position/`Nested:4` retained.
- UID0002C7 is currently `93/94` from `88/91`, with owner/emitter/true/blank position/`Nested:0` retained.
- UID0002C5 is currently `90/93` from `88/90` after UID-preserving rename, with owner/emitter/true/blank position/`Nested:0` retained.
- UID0002B1 is currently `91/93` from `89/92`, with owner/emitter UID0000T9, true, position 0, and nesting retained.
- UID0002B2 is currently `89/92` from `86/90`, with owner/emitter UID0000T9, true, position 0, nesting, and formal block retained.
- UID0001CG and file/class/global support scores remain unchanged.
- Completion rises because parent disposition, source operation declarations, exact layouts, child body errors, wrapper semantics, and manual coverage plan are resolved. Confidence stays below 95 because original private spellings and filename are not recovered.
- Score-improvement attempt: every named blocker was checked through live functions/bytes/xrefs/types, current docs/generated output, manual coverage, and old reports. Only original-name/file provenance lacks available evidence; it no longer blocks behavior, source placement, metadata, or C++.

## Open Questions With Attempted Resolution

- Original class/function/field spellings: IDA names, strings, types, reports, and local source searches were checked. No original symbols survive. Resolution: use the existing descriptive vocabulary and explicitly cap confidence.
- Member versus file-static declarations: repeated ECX receiver use, explicit argument cleanup, and constructor/object layout make private operations the strongest source form. Internal optimizer conventions are a runner-up, but they do not explain the object-oriented constructor and entire consistent family as well.
- Separate source file: all report roots, source-tree docs, current by-file docs, symbols, and adjacency were checked. No route supports creation. Resolution: keep MidiPlayer.cpp.
- Header length greater than six: executable performs the full-width read into six bytes of named header fields. Resolution: preserve the trusted-input behavior instead of introducing a seek or safe clamp that would differ from the binary.
- Zero-track files: executable success is direct. Resolution: preserve it even though a stricter parser might reject it.
- Dedicated by-type page: current UID0002B1 already owns/emits these declarations at position 0. Resolution applied: no duplicate page was created, and the exact layouts are documented there.
- No investigable blocker remains unresolved. Unavailable original source/debug symbols are confidence-only evidence, not future implementation work.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual rows inspected: by-memory rows for UID0001CG, UID0002C5, UID00023C, UID0002C6, UID0002C7, UID0002B1, UID0002B2, and UID0000VN padding; by-file UID0000LD; by-class UID00008A; by-global UID0000T9; by-type/by-struct no matching private MIDI row.
- The following exact text is for supervisor application only. B004 must not edit manual coverage.

File: `by-memory/-coverage-report.md`.

Replace the current UID0001CG row with:

```text
    - [UID:0001CG][0x00525be0-0x00525dbb.MidiStreamCallback](by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md) 0x00525be0-0x00525dbb | WinMM callback | MidiStreamCallback : reconstructable : 88% : strong : WinMM callback installed by MidiPlayer stream-open paths; exact callback ABI, MOM_DONE/MOM_POSITIONCB branches, header refill, volume-controller callback, reset/release behavior, and corrected private MidiDocument::FillStreamBuffer call are documented without changing unrelated callback semantics.
```

Replace the current UID0002C5 row with:

```text
        - [UID:0002C5][0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper](by-memory/0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md) 0x005270c0-0x005270d5 | function | MidiDocumentLoadFailureWrapper : reconstructable : 90% : very-strong : Exact 0x15-byte private document wrapper returns true only when MidiDocument::Load returns the directly evidenced failure value 1; sole stream-open caller treats true as failure. Historical MidiParseSuccessWrapper/MidiLoadDocumentSucceeded naming is rejected-stale.
```

Replace the UID00023C parent and its two child rows with:

```text
    - [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md) 0x005271b0-0x005277bb | aggregate/index | MidiSMFLoadAndStreamFillHelpers : ignored : 91% : very-strong : Non-emitting exact index exhausted by UID0002C6 and UID0002C7; retains MidiPlayer.cpp ownership, complete range/hash/caller/layout/history evidence, and no parent prose/body because exact children own both source functions.
        - [UID:0002C6][0x005271b0-0x005273a0.MidiStreamBufferFillHelper](by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md) 0x005271b0-0x005273a0 | function | MidiStreamBufferFillHelper : reconstructable : 92% : very-strong : Private MidiDocument::FillStreamBuffer operation with exact two callers, 0x1f0 bytes/hash, track-minimum scan, persistent scratch state, replay/error/output-full branches, count-gated payload cleanup, and corrected source C++ that removes unsupported helper bodies and extra reset/per-event writes.
        - [UID:0002C7][0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper](by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md) 0x005273a0-0x005277bb | function | MidiSMFDocumentLoadHelper : reconstructable : 93% : very-strong : Private MidiDocument::Load operation with exact one caller, 0x41b bytes/hash, MThd/MTrk/endian handling, 0x28 track records, 0x400 GHND buffers, source-position queries, initial VLQ seeding, full cleanup, and directly corrected 0-success/1-failure contract.
```

Replace the UID0002B1 and UID0002B2 rows with:

```text
    - [UID:0002B1][0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals](by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md) 0x0069b500-0x0069b870 | global-data cluster | MidiPlayerWinMMStateGlobals : reconstructable : 91% : very-strong : Source-declared MidiPlayer.cpp WinMM state plus exact private MidiDocument, 0x28 MidiTrackState, and 0x54 stream-write declarations; position-0 formal block records corrected Load/LoadFailed/FillStreamBuffer contracts while retaining all existing storage and initializers.
    - [UID:0002B2][0x0069b870-0x0069b890.MidiSMFParserScratchGlobals](by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md) 0x0069b870-0x0069b890 | global-data scratch | MidiSMFParserScratchGlobals : reconstructable : 89% : very-strong : Exact 0x20-byte private stream-fill scratch block; all direct refs are confined to UID0002C6, static zero storage is separated from runtime 0xffffffff selected-tick writes, and formal MidiEvent/fill-state declarations remain emitted before helper bodies.
```

The existing UID0000VN padding rows remain exact and require no replacement.

File: `by-file/-coverage-report.md`.

Replace UID0000LD row with:

```text
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) : reconstructable : 88% : strong : WinMM MIDI source module projected to NexusTK/audio/; current source-quality audit resolves UID00023C as a non-emitting index, corrects its private MidiDocument load/fill operations and failure wrapper, locks exact document/track/event/write-context layouts, preserves scratch/global ownership, and retains MidiPlayer.cpp over unproved private-SMF, DATFile, SoundManager, or class-owner routes.
```

File: `by-class/-coverage-report.md`.

Replace UID00008A row with:

```text
- [UID:00008A][MidiPlayer](by-class/MidiPlayer.md) : reconstructable : 87% : strong : WinMM MIDI playback controller class attached to MidiPlayer.cpp; private MidiDocument load/fill/parser operations and their 0x48 state object are module support rather than MidiPlayer instance methods, while the existing controller lifecycle/vtable/public playback surface remains unchanged.
```

File: `by-global/-coverage-report.md`.

Replace UID0000T9 row with:

```text
- [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md) : reconstructable : 87% : strong : Documentation owner for MidiPlayer WinMM headers, stream state, private MidiDocument storage, and SMF fill scratch; exact child pages emit declarations, UID0002C6 alone consumes the scratch block, and the corrected load/fill contracts preserve the existing MidiPlayer.cpp source route.
```

File: `by-type/by-struct/-coverage-report.md`.

- No insertion is recommended. The exact private declarations remain owned by UID0002B1; adding a second manual row without a new ordinary page would falsely imply duplicate declaration ownership.
- Reason B agent must not apply directly: manual coverage is supervisor-owned and validator-generated coverage does not replace these edits.

## Follow-Up Actions

- No target or support implementation item remains. Original source-symbol recovery could revise descriptive spellings only if stronger evidence appears; it is not a correctness or callback blocker.
- B004 performed no report execution, lifecycle probe, count, move, archive, manual coverage edit, generated-file edit, or IDA mutation. Report review, validation, execution, manual coverage application, counts, path, move, and archive state are external supervisor/validator-owned and are neither asserted nor directed by this artifact.
- The report remains a durable research/implementation-callback artifact regardless of external lifecycle placement. Validator history and external audit state, not current-path wording in this body, are authoritative for lifecycle status.

## Confidence

- Recommendation confidence: very strong for parent/child disposition and behavior; strong for private `MidiDocument` source form and current file route.
- Score confidence: strong. Scores reflect direct blocker closure without claiming original-source certainty.
- Remaining uncertainty: stripped original spellings and possible historical private source filename. Neither changes implementation behavior or present routing.

## Validator Results

- All scoped commands were run from `source-3/project-documentation` as `python .\tools\validator.py --mode file --file <final-relative-path> --apply --queue-timeout 240`; command `000000012277` additionally used `--wait-generated`. Every command exited `0` with `ok: 1`.
- `000000012234`, `2026-07-14T21:11:55-04:00`: UID00023C target; applied completion/confidence, true-to-false reconstructability, emitter clear, prose-block-to-blank conversion, autogen state, projected stats; generated refresh deferred.
- `000000012235`, `2026-07-14T21:13:09-04:00`: UID0002C6; applied `92/94`, formal hash/body and evidence, autogen state, projected stats; generated refresh deferred.
- `000000012236`, `2026-07-14T21:14:42-04:00`: UID0002C7 initial edit; applied `93/94`, formal hash/body and evidence, autogen state, projected stats; generated refresh deferred.
- `000000012237`, `2026-07-14T21:15:33-04:00`: final UID0002C5 path; validator-preserving path update from `MidiParseSuccessWrapper.md` to `MidiDocumentLoadFailureWrapper.md`, eight reverse source-path updates, nineteen UID-link updates, `90/93`, formal/autogen/projected-stats updates; generated refresh deferred. The validator also updated the UID0002C5 link in `by-memory/-coverage-report.md` and reported pre-existing missing-reference UIDs `0003MT`, `00039L`, and `0003T6`; B004 did not manually edit coverage or those unrelated references.
- `000000012238`, `2026-07-14T21:16:52-04:00`: UID0002B1; applied `91/93`, Destination 5 declaration hash, autogen/projected-stats updates; generated refresh deferred.
- `000000012239`, `2026-07-14T21:17:36-04:00`: UID0002B2; applied `89/92`, retained formal block, updated references/projected stats; generated refresh deferred.
- `000000012240`, `2026-07-14T21:18:22-04:00`: UID0001CG; applied Destination 6 only, formal hash/projected stats; generated refresh deferred.
- `000000012241`, `2026-07-14T21:18:57-04:00`: UID0001CE narrative support; score/formal unchanged, projected stats updated; generated refresh deferred.
- `000000012243`, `2026-07-14T21:19:23-04:00`: UID0001CI narrative support; score/formal unchanged, projected stats updated; generated refresh deferred.
- `000000012246`, `2026-07-14T21:21:12-04:00`: UID00023B aggregate terminology/link support; score/formal unchanged, projected stats updated; generated refresh deferred.
- `000000012247`, `2026-07-14T21:21:44-04:00`: by-class/MidiPlayer support; score/formal unchanged, two accepted reference-index additions, projected stats updated; pre-existing missing UID0003PF reported; generated refresh deferred.
- `000000012248`, `2026-07-14T21:22:28-04:00`: by-global/MidiPlayerWinMMState support; score/formal unchanged, three accepted reference-index additions, stats row/projected stats updated; generated refresh deferred.
- `000000012251`, `2026-07-14T21:22:42-04:00`: UID0002C4 verify-only after validator-managed rename propagation; score/body unchanged, projected stats updated; generated refresh deferred.
- `000000012259`, `2026-07-14T21:23:24-04:00`: UID0002C7 post-rename/current-contract revalidation; exit 0, ok 1, projected stats updated; generated refresh deferred.
- `000000012277`, `2026-07-14T21:25:37-04:00`: by-file/MidiPlayer scoped validator plus authorized waited refresh; exit 0, ok 1, `generated_refresh: completed`. Global refresh diagnostics were 14 fallback child inserts, 86 preferred-marker warnings, 176 no-code-emitter notices, one registry rebuild, and 281 generated metadata refreshes; these are project-wide validator output, not target failures or manual edits.
- Generated freshness/readback: B004's waited command was `000000012277`; the current generated header is command `000000012293`, refreshed `2026-07-14T21:27:33-04:00`, so it is newer than the B004 command rather than stale. Current `auto-generated/NexusTK/audio/MidiPlayer.cpp` SHA256 is `D236479B8396D19337132D4B48C5EE5B1B7BB5BEED70D53EB2EFAB6C268EE3FB`, size 44,896 bytes. It contains UID0002C5 once at definition line 1192, UID0002C6 once at line 1229, and UID0002C7 once at line 1316; method declarations occur at lines 91-93 before all three definitions. It contains one `g_midiDocumentState.FillStreamBuffer` callback call at line 290.
- Generated semantic assertions: `return Load(path) == MIDI_LOAD_FAILED;` occurs once at line 1194; `return MIDI_LOAD_OK;` occurs once at line 1423; `return MIDI_LOAD_FAILED;` occurs once at line 1427. The raw first-tag read occurs once at line 1342, table `GlobalAlloc(GMEM_ZEROINIT, ...)` once at line 1365, and track-buffer `GlobalAlloc(GHND, ...)` once at line 1375; an explicit `trackCount == 0` rejection count is zero, and the body performs the accepted full-width `MidiReadExact(this, &header, headerLength)`.
- Generated negative assertions: UID00023C count `0`; `UID:00023C.*Empty Emitter Marker` count `0`; `MidiParseSuccessWrapper`, `MidiLoadDocumentSucceeded`, `MidiResetFillScratch`, `MidiSelectNextTrack`, `MidiSwapWord`, and `MidiSwapDword` counts all `0`; no duplicate target child definition exists. The file-wide `Empty Emitter Marker` count is `1`, solely unchanged UID0001CE at line 1437, and is outside the target assertion.
- All six destination managed-block comparisons returned exact byte-normalized match `True`. No unresolved target validator error remains.

## Changed Files

- Updated report: `tools/leaser/Agents/Agent-B004/research/00023C-MidiSMFLoadAndStreamFillHelpers-source-quality.md`.
- Renamed once with UID preserved: `by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md` -> `by-memory/0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md`; old path absent, new path present, UID0002C5 unique.
- Modified ordinary target/formal pages: `by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md`, `by-memory/0x005271b0-0x005273a0.MidiStreamBufferFillHelper.md`, `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`, `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md`, `by-memory/0x0069b870-0x0069b890.MidiSMFParserScratchGlobals.md`, and `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`.
- Modified ordinary narrative/support pages: `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`, `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md`, `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`, `by-file/MidiPlayer.md`, `by-class/MidiPlayer.md`, and `by-global/MidiPlayerWinMMState.md`.
- Validator-managed reverse-link-only ordinary page: `by-memory/0x00527080-0x005270b5.MidiReaderConstructorInit.md`, revalidated by `000000012251` with score/body unchanged.
- Validator-managed restricted side effects: command `000000012237` propagated the UID0002C5 renamed link into `by-memory/-coverage-report.md`; ordinary validators updated projected stats/reference state; command `000000012277` refreshed generated artifacts/metadata. B004 manually edited none of those restricted files.
- Verify-only unchanged: `by-memory/-ignored.md` padding row and all explicitly excluded parser siblings/support pages.
- Report execution/lifecycle: not run by B004. No execute_report, lifecycle/probe/count/move/archive command was run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact pre-callback SHA256 `7C6CB192D5D9ECCC2533969892EDC6B19D4B577D8C3795DA675E2A4F20725D21` before implementation.
- [x] Re-read UID00023C immediately before edit; applied C01-C03 and Destination 1 at report-level detail.
- [x] Re-read UID0002C6; applied C04-C13, `92/94`, exact metadata, and Destination 2 without losing history/evidence.
- [x] Re-read UID0002C7; applied C14-C28, `93/94`, exact metadata, and Destination 3 without losing history/evidence; revalidated after rename propagation.
- [x] Leased UID0002C5 old path, performed one UID-preserving rename to `0x005270c0-0x005270d5.MidiDocumentLoadFailureWrapper.md`, applied C16-C17/Destination 4, validated final path, verified old path gone and UID unique, and released immediately.
- [x] Updated every ordinary reverse link from UID0002C5's old path/title while preserving unrelated content; validator side effects are recorded.
- [x] Re-read UID0002B1; applied C29/C31/C32 and Destination 5 at `91/93`, retaining all unrelated declarations/storage.
- [x] Re-read UID0002B2; applied C07/C30/C33 evidence at `89/92`, leaving formal block/owner/position intact.
- [x] Re-read UID0001CG; applied only Destination 6 and supporting source-contract text, preserving score and all callback behavior.
- [x] Re-read UID0001CE, UID0001CI, and UID00023B; applied only listed narrative/link corrections, preserving formal blocks/scores.
- [x] Re-read by-file/MidiPlayer, by-class/MidiPlayer, and by-global/MidiPlayerWinMMState; incorporated C34-C36 without unrelated score/formal inflation.
- [x] Verified UID0000VN leading/trailing padding row remains unchanged and made no edit.
- [x] Current target state and actual evidence checked are recorded.
- [x] Claim And Incorporation Ledger carries a legal action and terminal verification state plus destination proof for every C01-C40 claim.
- [x] Metadata/score changes were applied exactly as specified.
- [x] Score-limiting blockers were closed at report-level detail; original-name/file uncertainty remains only a confidence cap.
- [x] Owner/emitter/reconstructable changes were applied exactly; no duplicate source/file/type owner was created.
- [x] Parent/child/nesting/padding disposition was applied without creating or merging children.
- [x] Source-placement and rename/type recommendations were applied; no IDA mutation was performed.
- [x] All six exact managed destination blocks were applied only to their named formal headers and mechanically compared exact.
- [x] Third-party import directive was confirmed not applicable and no import marker was added.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, exact hashes, and binary/source distinction were preserved.
- [x] No open question remains as unspecified future investigation.
- [x] One short lease per changed ordinary page was acquired only immediately before edit and released after scoped validation.
- [x] One scoped file validator was run per changed ordinary page; command IDs, timestamps, exits, ok states, warnings, and side effects are recorded.
- [x] Final waited generated refresh completed and all positive/negative assertions were checked read-only.
- [x] Exact manual supervisor-owned coverage text remains present for external application; B004 made no manual coverage edit, and the validator-managed rename propagation is explicitly recorded.

Implementation callback pass:
- [x] Report was accepted by the supervisor for implementation at the exact Gate 1 SHA above.
- [x] All accepted target/support doc details were incorporated at report-level detail.
- [x] C01-C40 have legal callback actions/states with exact destination and validator proof.
- [x] Metadata/score/owner/emitter/reclassification/rename/C++ changes were applied or excluded with exact reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence were preserved.
- [x] Open questions were resolved or retained only with exhaustive evidence-backed confidence rationale.
- [x] Validators ran and exact results are recorded.
- [x] Generated refresh/readback completed and all positive/negative assertions are recorded.
- [x] Changed Files lists every ordinary page actually changed and validator-managed reverse-link/restricted-file side effects.
- [x] Every lease was released; current lease report contains zero B004 rows.
- [x] No manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/IDA file was manually changed.
- [x] No execute_report, lifecycle, probe, count, move, or archive command was run by B004.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000012391","destination_path":"executed-b-agent-research/B004/00023C-MidiSMFLoadAndStreamFillHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00023C-MidiSMFLoadAndStreamFillHelpers-source-quality.md","timestamp":"2026-07-14T22:13:34-04:00","uid":"00023C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
