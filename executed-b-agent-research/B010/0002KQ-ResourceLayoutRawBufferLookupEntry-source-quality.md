** TARGET-REPORT-UID:0002KQ **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# 0002KQ ResourceLayoutRawBufferLookupEntry Source-Quality Research

## Finalized Report / Current Recommendation

Current recommendation: update [UID:0002KQ] `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md` from `85/88` to `86/89`, preserve reconstructable/source-authored status, keep direct file-level owner [UID:0000N5] `ResourceLayoutTable`, and keep first-draft C++ blank.

This repair does not treat the next-row/mask-size issue as a reason for unchanged metadata. The current pass resolves two score blockers: owner route and destination field/type vocabulary are no longer provisional. It converts the remaining blocker into an implementation-ready no-code plan: document that UID0002KQ deliberately stays blank-C++ because the body allocates `24 * (entryCount + 1)` bytes, imports only the first raw record, and then computes `encodedMaskByteCount` from `entries[1].pixelData - entries[0].encodedMaskData` without the loop/sentinel write seen in the DAT-backed loader. That is faithful binary evidence, but not safe first-draft source until the raw packet format or caller contract proves the second row.

Report state: ready for supervisor Gate 1 validation.

## Target

- UID: `0002KQ`
- Target doc: `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md`
- Function: `sub_4D03A0`
- Address range: `0x004d03a0-0x004d04d0`
- Current direct owner: [UID:0000N5] `by-file/ResourceLayoutTable.md`
- Current generated output: `auto-generated/NexusTK/render/ResourceLayoutTable.cpp` contains only the empty emitter marker for this UID.

## Current Target State

Current target metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000N5`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N5`
- `RECONSTRUCTION_CPP CODE` blank

Current page summary already records the key source-quality facts: exact half-open boundary, one `UserLookPane::ParseLookPacket` caller, no pointer hits, `__stdcall` raw-buffer behavior, and rejection of class/caller/global ownership. That state remains accurate after this pass.

The target is currently a reconstructable source-authored helper with no emitted source body. The report recommends `86/89` because current support docs and live MCP now settle the owner/type-name blockers well enough to improve the page, while the next-row/mask-size issue still blocks formal C++.

## Evidence Checked

Local documentation and generated state checked:

- Target doc `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md`.
- Current tracker header in `auto-generated/-ag-research-tracker.md`: `validator-command-id: 000000004649`, `validator-refreshed-at: 2026-07-02T16:12:33-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- Current tracker row in `auto-generated/-ag-research-tracker.md`: UID0002KQ remains `85/88`, average `86.5`, reconstructable true, not covered by a B report yet.
- Supervisor prompt reports queue status command `000000004650` showed no queued or processing jobs before this resume.
- Memory coverage row in `auto-generated/-ag-coverage-report-by-memory.md`: `emits_code:false`, updated `2026-06-29 15:40:05`.
- Generated output file `auto-generated/NexusTK/render/ResourceLayoutTable.cpp`: empty emitter marker for `0002KQ`, plus empty marker for companion raw helper `0002KT`.
- Owner/support docs: `by-file/ResourceLayoutTable.md`, `by-class/ResourceLayoutTable.md`, `by-item/ResourceLayoutEntry.md`, `by-class/EPFTileContext.md`, and `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md`.
- Companion and adjacent ResourceLayout docs: `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md`, `by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md`, `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`, and `by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md`.
- Executed report `executed-b-agent-research/B001/000174-ResourceLayoutTable.md`.
- Executed report `executed-b-agent-research/B011/0000K2-ImageLib-empty-emitter-family-source-quality.md` for the ImageLib-vs-raw-helper exclusion.

Required existing-report search terms used:

- `0002KQ`
- `004d03a0`
- `004D03A0`
- `ResourceLayoutRawBufferLookupEntry`
- `sub_4D03A0`
- `ResourceLayoutRawBuffer`
- `ResourceLayoutTable`
- `next-row`
- `sentinel`
- `encodedMaskByteCount`
- `mask-size`
- `raw-buffer`

Relevant matches found:

- B001 executed report confirms final `0002KQ` state as `85/88`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000N5] `ResourceLayoutTable`, position `30`.
- B011 executed report explicitly excludes raw helpers `0002KQ` and `0002KT` from the ImageLib empty-emitter family and keeps them under file-level [UID:0000N5].
- Supervisor notes record B001-023 completion for `0002KQ` as a two-argument `__stdcall` raw-buffer helper with UserLook consumer context.
- Text/report search found no later executed report that resolves UID0002KQ's next-row/mask-size issue. Current target and `ResourceLayoutEntry` docs are still the authoritative pages for that blocker.

Live IDA MCP calls used, all narrow/exact-address:

- `idb_list`: active session `supervisor_resume_20260629`, input `NexusTK.exe.i64`.
- `server_health`: `auto_analysis_ready:true`, `hexrays_ready:true`, imagebase `0x400000`.
- `lookup_funcs` for `0x004d03a0`, `0x004d04d0`, `0x0059f610`, `0x005a0042`, `0x00516050`, `0x00516220`, and `0x004b7c50`.
- `analyze_function` for `0x004d03a0`, without full asm.
- `disasm` for `0x004d03a0`, `max_instructions=120`, `include_total=true`.
- `decompile` for caller `0x0059f610`, with addresses.
- `search_text` for `sub_4D03A0` and `dword_67A744` over `0x0059ff80-0x005a0060`.
- `trace_data_flow` backward from `0x004d03a0`, `max_depth=1`.
- `decompile` for support helpers `0x00516050` and `0x00516220`.
- Gate 1 repair MCP pass: `lookup_funcs` for `0x004d0120`, `0x004d02f0`, `0x004d03a0`, `0x004d05a0`, and `0x0059f610`; `decompile` for `0x004d0120`, `0x004d02f0`, and `0x004d05a0`; bounded `disasm` for `0x004d03a0`.

## Positive Evidence Summary

Live IDA reconfirmed the exact function boundary:

- `lookup_funcs` reports `sub_4D03A0` at `0x4d03a0`, size `0x130`.
- `lookup_funcs` reports the next function `sub_4D04D0` at `0x4d04d0`, size `0x52`.
- Bounded disassembly shows `push ebp` at `0x4d03a0` and `retn 8` at `0x4d04cd`; the function has 120 instructions.

Live IDA reconfirmed the calling convention and caller set:

- `analyze_function` prototype is `char *__stdcall(char *Src, int)`.
- The callee returns with `retn 8`, matching two stack arguments.
- `trace_data_flow` backward from the function start finds exactly one depth-1 code edge: `0x005a0042 -> 0x004d03a0`.
- `search_text` over the caller window finds `call sub_4D03A0` at `0x005a0042`.

Live IDA reconfirmed caller semantics:

- Caller `sub_59F610` is the `UserLookPane::ParseLookPacket` child context.
- In the non-JPF branch, the caller copies payload bytes into `this+2960` storage, rejects raw bytes `+6` or `+7` when nonzero, then calls this helper with raw buffer `v69` and output context `this+3484`.
- The adjacent JPF branch calls `sub_4D07B0` instead.
- `search_text` finds `mov ecx, dword_67A744` at `0x005a003c`, immediately before `call sub_4D03A0`, preserving the semantic `g_pEPFLib`/ResourceLayout relation in prose. This is not method ownership evidence because the callee overwrites/uses `ecx` for memory-helper context and returns with `retn 8`.

Live IDA reconfirmed helper behavior:

- The helper copies the first 8 raw header bytes and a dword table offset from the raw source buffer.
- It allocates `24 * (headerEntryCount + 1)` bytes.
- It reads one raw table row from `Src + tableOffset + 12`: `top`, `left`, `bottom`, `right`, plus two 32-bit payload/mask offsets.
- It calls `sub_4B7C50` to initialize normalized bounds as `left, top, right, bottom`.
- It rebases pixel and encoded-mask offsets by `Src + 12`.
- If an output context pointer is supplied, it writes `pixelData` at `+0x04`, `rowStridePixels` at `+0x0c`, bounds at `+0x10..+0x1c`, `encodedMaskByteCount` at `+0x20`, and `encodedMaskBytes` at `+0x24`.

Live IDA reconfirmed support helper meanings:

- `0x00516050` decompiles as `malloc(size)` with throw-on-failure behavior.
- `0x00516220` decompiles as a three-argument `memmove` wrapper.
- The allocator does not zero the `entryCount + 1` row array.

Support docs now provide source-quality destination names:

- `ResourceLayoutEntry` is emitted as a 24-byte `left/top/right/bottom/pixelData/encodedMaskData` row.
- `EPFTileContext` uses `pixelData`, `rowStridePixels`, `bounds`, `encodedMaskByteCount`, and `encodedMaskBytes`.
- `ResourceLayoutTable` file-level docs already preserve the no-`this` raw-helper route.

Additional Gate 1 repair evidence clarifies the next-row route:

- `LoadResourceIndex` (`0x004d0120`) performs the safe DAT-backed pattern: it loops over all `entryCount` rows, rebases every row's payload/mask offsets, then writes a zero-bounds sentinel row with both pointer fields set to `payloadBase + entryTableOffset`.
- `LookupLayoutEntry` (`0x004d02f0`) uses the same `nextEntry.pixelData - currentEntry.encodedMaskData` calculation, but it is safe there because `LoadResourceIndex` populated all rows plus the sentinel.
- Companion raw helper `ResourceLayoutRawRecordGetEntryRect` (`0x004d05a0`) does not help initialize UID0002KQ's temporary row array; it only copies an existing 16-byte rectangle prefix from a caller-provided record array.
- `GetEntryRect` (`0x004d0530`) likewise confirms normal record-array consumption but does not supply a raw-buffer sentinel for UID0002KQ.
- Therefore UID0002KQ's next-row read is not a struct-layout artifact: disassembly explicitly reads `[edx+28h]`, the second row's `pixelData`, after only `[edx+0..17h]` of the first row is initialized in this function.

## Negative Evidence Summary

No evidence supports class-method ownership:

- The function has no `this` receiver.
- It returns with `retn 8`, not a `thiscall` convention.
- The `g_pEPFLib` preload at the caller is not consumed as a `this` pointer in the callee.
- [UID:0000BY] `ResourceLayoutTable` class docs correctly exclude `0002KQ` from the class method inventory.

No evidence supports `UserLookPane` ownership:

- `UserLookPane::ParseLookPacket` is the only known caller, but the body parses ResourceLayout-format frame rows and fills an `EPFTileContext`-style output.
- The caller supplies a raw profile/look image payload; it does not define the shared ResourceLayout row format.

No evidence supports ImageLib ownership for this UID:

- [UID:0000K2] `ImageLib` owns the class-backed ResourceLayout method family through the singleton/facet route.
- B011's executed ImageLib report explicitly excludes `0002KQ` and `0002KT` from that emitted family.

No evidence closes the final C++ blocker:

- The helper allocates `entryCount + 1` rows but fills only the first row before output.
- It computes `encodedMaskByteCount` from row `+0x28`, equivalent to `entries[1].pixelData`, minus current row `encodedMaskData`.
- Because `0x00516050` is `malloc`, the second row is not guaranteed zero or initialized by the allocator.
- Existing docs do not prove that the raw packet always has one entry, that the allocated row memory is prefilled elsewhere, or that this is an intentional source-level undefined behavior.

Rejected next-row explanations:

- Not a class-backed sentinel import: `LoadResourceIndex` has a visible row loop and sentinel write; UID0002KQ has neither.
- Not a companion-helper route: UID0002KT only reads existing raw record arrays and has no call edge into UID0002KQ.
- Not a decompiler-only expression: UID0002KQ disassembly contains the direct `mov eax, [edx+28h]` then `sub eax, [edx+14h]` sequence.
- Not a proven one-entry safe shortcut: the caller validates raw bytes `+6/+7` but does not prove `entryCount == 1` or synthesize `entries[1]`.
- Not currently repairable by a split/child page: the body is already an exact `0x130` function, and the issue is inside the function's source shape rather than an overbroad range.

## Heuristic / Inference Reanalysis And Validation

The previous B001 ownership inference remains valid. The strongest source-family signal is not the lone caller, but the combination of ResourceLayout row layout, ResourceLayoutTable address neighborhood, `EPFTileContext` output mapping, and explicit no-`this` convention.

The `mov ecx, dword_67A744` caller instruction should be preserved as semantic context only: the UserLook non-JPF raw profile image branch lives near the ImageLib/ResourceLayout singleton, but the helper itself is still stack-argument `__stdcall` glue over a caller-provided raw buffer. Treating this as a method would overclaim both calling convention and object lifetime.

The next-row/mask-size issue should not be papered over with a polished loop or sentinel construction in first-draft C++. A loop would contradict the actual `0x004d03a0-0x004d04d0` body, and a zero-sentinel assumption would contradict the live `malloc` evidence.

Reasonable current routes attempted:

- Companion UID0002KT route: rejected because it consumes caller-owned raw record arrays and copies rectangles only; it does not initialize UID0002KQ's allocated second row.
- Class-backed `LoadResourceIndex`/`LookupLayoutEntry` route: confirms the next-row formula is semantically intentional for ResourceLayout rows, but also proves safe use depends on looped row import plus sentinel construction absent from UID0002KQ.
- Raw packet/caller route: UserLook non-JPF caller copies the payload, rejects raw bytes `+6/+7`, and calls UID0002KQ once. It does not prove the packet has one row, does not pass a table size, and does not write UID0002KQ's temporary allocation.
- Struct/decompiler artifact route: rejected because the direct displacement sequence uses first-row fields at `+0x00/+0x08/+0x10/+0x14` and second-row `pixelData` at `+0x28`, exactly matching the known 24-byte row shape.
- Split/source-route repair route: no child/range repair is available because the instructions between `0x004d03a0` and `0x004d04d0` are one coherent helper and no adjacent bytes participate in the missing sentinel logic.
- C++ repair route: unsafe to emit a source-natural loop/sentinel because it would add behavior not present in this function; unsafe to emit a polished `encodedMaskByteCount = 0` because it would change the observed next-row dependency; possible but not recommended to emit a bug-preserving helper that reads `entries[1]` without initialization.

Score impact: this pass can safely raise the page to `86/89` because owner route and field/type vocabulary are now settled and the blocker is narrowed to formal C++ only. It should not go to `90+` or receive C++ until a raw-packet/sentinel proof or an explicitly accepted faithful undefined-read source body exists.

## Ranked Ownership Analysis

1. [UID:0000N5] `by-file/ResourceLayoutTable.md`: strongest owner. The helper consumes the same 24-byte `ResourceLayoutEntry` record format, writes the same `EPFTileContext` fields as the ResourceLayout lookup path, sits in the ResourceLayout function neighborhood, and is explicitly a no-`this` file-level raw helper.
2. [UID:0000BY] `by-class/ResourceLayoutTable.md`: useful semantic context but not the direct owner. The class page owns class-backed methods and intentionally excludes no-`this` raw helpers.
3. [UID:0000K2] `by-file/ImageLib.md`: broader singleton/facet owner for class-backed ResourceLayout methods only. It should not absorb this raw helper after B011's empty-emitter family exclusion.
4. [UID:0001KK] `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md` / `UserLookPane.cpp`: caller/consumer only. It provides the non-JPF profile-image payload and receives the output context, but the parsing logic is shared ResourceLayout-family code.
5. [UID:0000QU] `g_pEPFLib`: global semantic anchor only. The caller preload is real, but the callee does not use it as a source object.

## Source Placement

Keep source placement under [UID:0000N5] `ResourceLayoutTable`, projected to `NexusTK/render/ResourceLayoutTable.cpp`.

The generated output should remain an empty emitter marker for `0002KQ` unless and until the next-row/mask-size question is resolved. If a later callback accepts source emission, the helper should be a file-local/static raw-buffer helper in the ResourceLayoutTable helper grouping, not a `ResourceLayoutTable::` member, not an `ImageLib::` member, and not a `UserLookPane::` method.

## Score And Metadata Recommendation

Recommended metadata:

- Change `COMPLETION` from `85` to `86`.
- Change `CONFIDENCE` from `88` to `89`.
- Keep `CANONICAL_OWNER:0000N5`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000N5`.
- Keep `RECONSTRUCTION_CPP CODE` blank.

Reason for the modest score raise: ownership, caller/callee, calling convention, ResourceLayoutTable file-level placement, and destination context field names are now settled against current support docs and live MCP. The target page's current confidence rationale still says output/context type names are provisional; that is stale after the `EPFTileContext` and `ResourceLayoutEntry` support updates.

Reason the score should remain below first-draft C++ tier: the raw-buffer next-row calculation is still behaviorally significant and unresolved. The report converts that blocker into a concrete no-code disposition rather than leaving it as open-ended future work.

Reason for no reclassification to non-reconstructable: the body is source-authored parsing logic, not compiler glue, thunking, padding, or linker output. The correct label is reconstructable but not first-draft C++ ready.

## First-Draft C++ Recommendation

Do not add first-draft C++ in the next implementation callback unless the supervisor explicitly accepts a byte-faithful body with the unresolved next-row calculation called out in comments.

No `RECONSTRUCTION_CPP CODE` insertion is recommended by this report.

No-code proof:

- A source-natural implementation would loop over raw rows or construct a sentinel row before computing `encodedMaskByteCount`.
- The live binary does neither inside this function.
- A byte-faithful implementation would have to allocate an array, initialize only `entries[0]`, then read `entries[1].pixelData` when filling `output->encodedMaskByteCount`.
- Because the allocation is `malloc`, that read is not safely initialized by the allocator.
- Emitting polished C++ now would either hide a real source-quality problem or encode undefined behavior as if it were settled source design.

Recommended future C++ acceptance condition:

- Find raw packet format proof that the helper is intentionally one-entry only and that the second-row value is initialized by another mechanism, or
- Prove a decompiler/typing artifact that actually copies a second row or sentinel into the allocated record array, or
- Supervisor explicitly accepts a faithful, caveated reconstruction with the unresolved second-row read preserved.

Exact impact: the formal `RECONSTRUCTION_CPP CODE` header and multiline block should remain empty during the next callback. The implementation should improve metadata/prose only.

## Recommended Target Doc Changes

For a later implementation callback, update only the target page if accepted:

- Change `COMPLETION` to `86` and `CONFIDENCE` to `89`.
- Preserve `CANONICAL_OWNER:0000N5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N5`, and blank C++.
- Add a source-quality note that B010 reconfirmed the owner route and recommends keeping C++ blank due to the `malloc` plus `entries[1].pixelData` mask-size blocker.
- Tighten the `Autogen Status` wording from "Caller expectations and final helper/source ownership need review first" to "ownership is settled; final C++ is blocked by the next-row mask-size/uninitialized row question."
- Update score rationale to remove stale "provisional output/context type names" wording and replace it with "score capped by inferred helper spelling and unresolved raw-buffer second-row/sentinel contract."
- Preserve the semantic `g_pEPFLib` caller relation in prose as context, not ownership.

## Recommended Support Doc Changes

No support doc edits are required for the recommended callback unless the supervisor wants an explicit support sync.

If a later callback is accepted, the support docs can stay unchanged unless the target doc update needs a cross-reference refresh. Current support docs already say:

- [UID:0000N5] `ResourceLayoutTable` owns no-`this` raw helpers directly.
- [UID:0000BY] `ResourceLayoutTable` class excludes raw helpers from class-method inventory.
- [UID:0000VB] `ResourceLayoutEntry` defines the 24-byte row and next-row mask-size pattern for class-backed lookup.
- [UID:00004I] `EPFTileContext` defines the destination field names.
- [UID:0001KK] `UserLookPaneAndProfilePanes` remains the caller/consumer context.
- [UID:0002KT] `ResourceLayoutRawRecordGetEntryRect` already documents companion raw-helper ownership but does not resolve UID0002KQ's second-row issue.

## Claim And Incorporation Ledger

| Claim | Confidence / Evidence | Destination doc / section | Action | Verification state |
| --- | --- | --- | --- | --- |
| UID0002KQ remains exact range `0x004d03a0-0x004d04d0`, IDA function `sub_4D03A0`, size `0x130`. | High: live `lookup_funcs` and bounded `disasm`; current target page and B001 report already align. | Target `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md` / `Status`, `Boundary Evidence`. | already-present | already-present |
| Helper is a two-argument `__stdcall` free/static helper, not a `thiscall` class method. | High: live prototype `char *__stdcall(char *Src, int)`, explicit `retn 8`, no `this` receiver. | Target / `Status`, `Supervisor Parent-Gate Audit`, `Behavior`. | already-present | already-present |
| The single confirmed caller is `UserLookPane::ParseLookPacket` non-JPF raw profile-image branch at `0x005a0042`. | High: live caller decompile, `search_text` hit at `0x005a0042`, `trace_data_flow` backward depth 1. | Target / `Caller Evidence`. | already-present | already-present |
| Caller preload `mov ecx, dword_67A744` is semantic `g_pEPFLib`/ResourceLayout context, not method ownership. | High: live `search_text` hit at `0x005a003c`; callee returns `retn 8` and uses stack args/memory-manager context. | Target / `Caller Evidence` and ownership prose. | incorporate | applied |
| Direct owner/emitter should remain file-level [UID:0000N5] `ResourceLayoutTable`, not [UID:0000BY] class, [UID:0000K2] ImageLib, UserLookPane, or `g_pEPFLib`. | High: B001/B011 executed reports, current support docs, ResourceLayout row semantics, no-`this` helper convention. | Target metadata and `Supervisor Parent-Gate Audit`; support docs only if supervisor wants a sync. | already-present | already-present |
| Current score rationale is stale where it cites provisional output/context type names as a confidence cap. | Medium-high: `ResourceLayoutEntry` and `EPFTileContext` support docs now emit or document source-quality field names. | Target / `Score Rationale`, `Open Questions`. | incorporate | applied |
| Metadata should move from `85/88` to `86/89` while preserving owner/reconstructable/emitter route and blank C++. | Medium-high: owner and field-name blockers are resolved; next-row issue remains C++-only blocker. | Target metadata header and `Score Rationale`; generated coverage/tracker refreshed by scoped validator after callback. | incorporate | applied |
| UID0002KQ should keep blank formal C++. | High: live body initializes only first row and reads second-row `pixelData`; allocator `0x00516050` is `malloc`; no loop/sentinel write in UID0002KQ. | Target `RECONSTRUCTION_CPP CODE` header/block and `Autogen Status`. | incorporate | applied |
| The next-row/mask-size blocker is not resolved by UID0002KT. | High: UID0002KT decompile copies rectangles from caller-provided arrays and does not initialize UID0002KQ's temporary allocation. | Target / `Open Questions` or new source-quality note; UID0002KT support doc already sufficient. | incorporate | applied |
| The next-row/mask-size expression is not a decompiler artifact. | High: UID0002KQ disasm uses `mov eax, [edx+28h]` then `sub eax, [edx+14h]`, matching `entries[1].pixelData - entries[0].encodedMaskData`. | Target / `Behavior`, `Open Questions`, or new `Source-Quality Recheck` note. | incorporate | applied |
| The class-backed safe route depends on `LoadResourceIndex` importing all rows and writing a sentinel; UID0002KQ lacks that loop/sentinel. | High: live decompile of `0x004d0120` and `0x004d02f0`; `ResourceLayoutEntry` docs. | Target / new source-quality note; support docs already present. | incorporate | applied |
| No support docs require mandatory edits for this callback. | Medium-high: current `ResourceLayoutTable`, `ResourceLayoutEntry`, `EPFTileContext`, UID0002KT, and UserLook docs already contain same-or-greater support facts. | Support docs listed in `Recommended Support Doc Changes`. | not-applicable | already-present |

## Implementation Tracking Checklist

- [x] Lease and edit target doc `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md` only after supervisor callback. Proof: B010 leased the target for this callback edit batch and released it after validation.
- [x] In the target metadata header, change `COMPLETION:85` to `COMPLETION:86`. Proof: scoped validator command `000000004657` reported `completion_update 0002KQ ... 86`.
- [x] In the target metadata header, change `CONFIDENCE:88` to `CONFIDENCE:89`. Proof: scoped validator command `000000004657` reported `confidence_update 0002KQ ... 89`.
- [x] Preserve target metadata `CANONICAL_OWNER:0000N5`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N5`; do not change owner/emitter route. Proof: callback edit changed scoring/prose only and kept the accepted owner/emitter/reconstructable route.
- [x] Leave target `RECONSTRUCTION_CPP CODE` one-line and multiline block blank; do not insert formal C++ in this callback. Proof: generated `ResourceLayoutTable.cpp` still shows UID0002KQ as an empty emitter marker.
- [x] Update target `Autogen Status` to say ownership is settled and final C++ is blocked specifically by the raw-buffer next-row/sentinel contract, not by owner review. Proof: target prose now names the raw-buffer next-row/sentinel contract as the final C++ blocker.
- [x] Update target `Score Rationale` to remove stale "provisional output/context type names" as a cap and replace it with current caps: inferred helper spelling and unresolved raw-buffer second-row/mask-size contract. Proof: target score rationale now cites inferred helper spelling plus unresolved raw-buffer second-row/sentinel contract.
- [x] Add target prose preserving `mov ecx, dword_67A744` / `g_pEPFLib` as semantic caller context only, not `thiscall` or owner evidence. Proof: target caller evidence now states the preload is semantic context only.
- [x] Add target source-quality evidence that `LoadResourceIndex`/`LookupLayoutEntry` prove the next-row mask-size pattern is valid only when rows plus sentinel are populated. Proof: target `Behavior` includes the B010 source-quality reanalysis note.
- [x] Add target source-quality evidence that UID0002KQ lacks the DAT-backed row loop/sentinel write and directly reads `entries[1].pixelData` from `[edx+28h]`. Proof: target note documents the missing loop/sentinel and `[edx+28h]` read.
- [x] Add target rejected-alternative prose: not UID0002KT route, not class method, not ImageLib method, not UserLook-owned parser, not decompiler artifact, not safe source-natural C++ yet. Proof: target rejected-alternatives paragraph includes each route.
- [x] Verify support doc `by-file/ResourceLayoutTable.md` already preserves file-level raw-helper ownership; edit only if supervisor callback asks for explicit sync. Proof: support docs were verification-only and no direct contradiction was found.
- [x] Verify support doc `by-class/ResourceLayoutTable.md` already excludes UID0002KQ from class-method inventory; edit only if callback asks for explicit sync. Proof: support docs were verification-only and no direct contradiction was found.
- [x] Verify support doc `by-item/ResourceLayoutEntry.md` already documents sentinel-dependent `encodedMaskByteCount`; edit only if callback asks for explicit sync. Proof: support docs were verification-only and no direct contradiction was found.
- [x] Verify support doc `by-class/EPFTileContext.md` already documents `encodedMaskByteCount` and `encodedMaskBytes`; edit only if callback asks for explicit sync. Proof: support docs were verification-only and no direct contradiction was found.
- [x] Verify companion doc `by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md` already documents companion raw-helper route; edit only if callback asks for explicit sync. Proof: support docs were verification-only and no direct contradiction was found.
- [x] Run scoped validator after callback edit: `python .\tools\validator.py --mode file --file by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md --apply --queue-timeout 240`. Proof: command `000000004657`, timestamp `2026-07-02T16:25:29-04:00`, exit code `0`, `ok: 1`.
- [x] Capture validator `command_id`, `command_timestamp`, exit code, and `ok` count in the callback response. Proof: recorded below in `Validator Results`.
- [x] Check generated refresh after validator: `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/NexusTK/render/ResourceLayoutTable.cpp` should reflect `86/89` and still show no emitted C++ body for UID0002KQ. Proof: generated freshness check found tracker/coverage command `000000004658` and generated C++ command `000000004657`; UID0002KQ shows `86/89`, `emits_code:false`, and an empty emitter marker.
- [x] Do not manually edit generated reports, generated C++, manual coverage reports, tracker files, validator state, archives, or supervisor ledgers. Proof: generated/projected changes were validator-managed side effects only.
- [x] Update this report's Claim And Incorporation Ledger during callback: mark incorporated target changes as `applied`, unchanged same-detail support facts as `already-present`, and any supervisor-excluded support edits as `excluded-with-reason`. Proof: ledger above is updated with applied/already-present states; no support-doc exclusions were needed.
- [x] Release any edit leases immediately after the callback edit/validator batch and report lease release state. Proof: `leaser.py B010 unlease ...` returned `Success`; current lease table shows no active leases.

## Validator Results

Scoped validator run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002KQ-ResourceLayoutRawBufferLookupEntry-source-quality-removed.md](0002KQ-ResourceLayoutRawBufferLookupEntry-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- `command_id`: `000000004657`
- `command_timestamp`: `2026-07-02T16:25:29-04:00`
- Exit code: `0`
- `ok`: `1`
- Target-specific updates: `completion_update 0002KQ ... 86`, `confidence_update 0002KQ ... 89`, and validator-managed UID link/index updates for referenced UIDs.
- Validator-managed side effects: projected stats update and deferred generated refresh. No manual generated/project-level edits were made.
- Generated freshness: `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` refreshed at command `000000004658`; `auto-generated/NexusTK/render/ResourceLayoutTable.cpp` refreshed at command `000000004657`. UID0002KQ reflects `86/89`, `emits_code:false`, and an empty emitter marker.

## Changed Files

- `by-memory/0x004d03a0-0x004d04d0.ResourceLayoutRawBufferLookupEntry.md`
- `tools/leaser/Agents/Agent-B010/research/0002KQ-ResourceLayoutRawBufferLookupEntry-source-quality.md`
- Validator-managed generated/projected outputs refreshed by scoped validation: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/NexusTK/render/ResourceLayoutTable.cpp`, and projected stats output noted by validator.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004684","destination_path":"executed-b-agent-research/B010/0002KQ-ResourceLayoutRawBufferLookupEntry-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002KQ-ResourceLayoutRawBufferLookupEntry-source-quality.md","timestamp":"2026-07-02T16:31:49-04:00","uid":"0002KQ"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002KQ-ResourceLayoutRawBufferLookupEntry-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0002KQ-ResourceLayoutRawBufferLookupEntry-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002KQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
