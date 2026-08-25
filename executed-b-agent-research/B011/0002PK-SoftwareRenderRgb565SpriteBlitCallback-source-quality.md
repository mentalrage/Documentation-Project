** TARGET-REPORT-UID:0002PK **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0002PK SoftwareRenderRgb565SpriteBlitCallback Source-Quality Report


## Finalized Report / Current Recommendation

- Implementation callback result: accepted target-only changes were applied to [UID:0002PK] `by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md`; current target metadata is `88/90`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`.
- Final disposition: source-authored Surface software-render RGB565 slot-2 callback implementation selected through `dword_69B3E8` / `g_pfnBlitSprite`; exact function range and output route are strong, but the body is still not source-safe for formal C++.
- Applied action: target prose/current-state wording was repaired, the current MCP recheck was added, target-specific slot typedef/options evidence was added, top-level and option-local switch boundaries were recorded, rejected owner/helper alternatives were preserved, and stale "current generated owner" / "corrected-gate parent blocker" wording was historicalized.
- Confidence: high for range, owner/emitter, callback route, xrefs, callee set, local switch data, and no-code proof; intentionally below final audit because mode enum names, concrete `SurfaceSpriteBlitOptions` layout, and source-shaped branch decomposition remain unresolved.

## Supporting Research

- Historical assignment source: `Agent-B011/goal.md` selected [UID:0002PK] from the reconstructable not-covered by-memory queue with pre-callback tracker state `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- Historical generated state at initial B011 report time: `auto-generated/NexusTK/render/Surface.cpp` header then reported validator command `000000007434`, refreshed `2026-07-05T22:34:34-04:00`; UID0002PK emitted only an empty marker as `Completion:86 | Confidence:89`.
- B011 callback-time generated state: scoped validator command `000000007462` refreshed `auto-generated/NexusTK/render/Surface.cpp` at `2026-07-05T23:25:59-04:00`; UID0002PK emitted only an empty marker as `Completion:88 | Confidence:90`. Later supervisor execution may refresh generated headers again.
- B011 callback-time tracker/coverage state before supervisor execution: `auto-generated/-ag-research-tracker.md` listed UID0002PK as `88/90`, combined `89.0`, reconstructable `true`, reports `0`; `auto-generated/-ag-coverage-report-by-memory.md` listed `emits_code:false`, reconstructable, `88%`, `very-strong`, and the refreshed item summary without the stale parent-blocker phrase. After supervisor execution, validator-owned tracker rows, executed archive path, and lifecycle history/footer are authoritative.
- Existing aggregate/support reports were treated as leads only. The current report's proof uses current target/support docs plus live IDA MCP session `supervisor_recovery_20260705`.
- Old report search terms used: `0002PK`, `004c0f80`, `SoftwareRenderRgb565SpriteBlitCallback`, `sub_4C0F80`, `dword_69B3E8`, `SurfaceSpriteBlitProc`, `SurfaceSpriteBlitOptions`, `0x1c`, and related UIDs `00016L`, `0002PH`, `0002TI`, `000167`, `00041R`, `00041U`, `00004I`.
- Relevant old-report leads opened: B001 `00016L-SoftwareRenderRgb565Callbacks.md`; B012 `0002PH-SoftwareRenderCompatSpriteBlitCallback-source-quality.md`; B012 `0002TI-SoftwareRenderRgb565BitmaskBlitCallback-source-quality.md`; B003 `000167-SurfaceSpriteBlitHelper-source-quality.md`; B003 `00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md`; B005 `00041U-ItemObjImageLibDrawItemImageScaled-by-memory-source-quality.md`; B004 `00004I-EPFTileContext-class-source-quality.md`.
- The old reports are useful leads for aggregate ownership, compat peer comparison, slot-2 typedef repair, item-options no-code proof, EPFTileContext encoded-mask field names, and source-ready UID0002TI contrast. They are not substituted for current MCP evidence.
- During the B011 implementation callback, B011 manually edited only the target by-memory page and this B011 report. Validator command `000000007462` performed validator-owned generated/metadata refreshes; B011 did not manually edit support docs, generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers.

## Target

- Target UID: `0002PK`.
- Target path: `by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md`.
- Source queue/report row at B011 callback validation time: `auto-generated/-ag-research-tracker.md` showed the by-memory row at `88/90`, combined `89.0`, reports `0` before supervisor-owned `execute_report`; after execution, validator-owned tracker/history state supersedes this pre-execution observation.
- B011 callback classification at repair time: B-agent implementation callback complete and handed off for the then-pending supervisor Gate 2 step; this is a B-agent history note, not a description of the archived artifact's later validator-owned state.
- Current scores and parent state: target is `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.

## Current Target State

- Current metadata after callback: UID0002PK scores `88/90`; `CANONICAL_OWNER` and `EMITTER_UIDS` both route to [UID:0000OC] `Surface`; reconstructable is true; formal C++ remains blank.
- Existing owner/emitter/reconstructable state: Surface ownership is current and supported. The target is an exact source-bearing callback child, not the broad non-emitting RGB565 aggregate.
- Existing C++/emitter state: generated `Surface.cpp` contains only an empty emitter marker for UID0002PK. The formal `RECONSTRUCTION_CPP CODE` block is blank and should remain blank.
- Stale assumptions repaired: the target no longer presents "Current generated owner: caller-biased RankingEventListPane" or "corrected-gate parent blocker" as current truth. RankingEventListPane is preserved only as historical generated/caller-biased pollution, and current output route is Surface empty marker through `EMITTER_UIDS:0000OC`.
- Existing accurate evidence to preserve: exact `0x004c0f80-0x004c3123` range, `sub_4C0F80` size `0x21a3` / 8611 bytes (Verified with MCP `int_convert`), no direct callers, two target-address data refs, 114 `dword_69B3E8` slot refs, 308 blocks, 2109 instructions, callee set, destination state offsets, option-pointer reads, RGB565 helper relationships, and `0x004c3123-0x004c3190` local switch data.
- Related docs checked: `by-file/Surface.md`, `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`, `by-global/SurfaceRenderCallbackTable.md`, `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`, `by-memory/0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md`, EPFTileContext class/file docs, UID00041R/UID00041U item-image docs, UID00016M/UID00016N RGB565 helper docs, and `by-file/SoftwareBlend16.md`.
- Artifact/lifecycle note: before supervisor execution, the editable B011 copy is in `tools/leaser/Agents/Agent-B011/research/` for Gate 2 verification / execution decision. After supervisor execution, the validator-owned executed archive path, `REPORT-VALIDATION-STATUS` / `VALIDATOR-REPORT-HISTORY` footer when present, and generated tracker history are authoritative; this section is B011 callback history only.

## Executive Recommendation

- Best owner/source route: keep UID0002PK with [UID:0000OC] `Surface` / `NexusTK/render/Surface.cpp`. It is an installed Surface render callback target, not a feature-pane method and not a pure SoftwareBlend16 helper.
- Split/container disposition: no split or range change. The modeled function is exact; the following `0x004c3123-0x004c3190` bytes are local switch data that should be regenerated from source control flow, not split into a child page or copied as standalone data.
- Score/metadata: applied `COMPLETION:88`, `CONFIDENCE:90`; owner, emitter, reconstructable, and blank emitter position remain unchanged.
- C++ disposition: no formal C++ yet. The code-entry gate is numerically met, but the body is not source-safe because the callback is an 8611-byte, 2109-instruction, 308-block dispatcher with nested mode/option switches, partially initialized options records, local switch data, decompiler register artifacts, and unresolved source-mode taxonomy.

## Supervisor Active Recheck

- B011 callback instruction history: implement the Gate 1-passed report target-only, run the scoped target validator, update the report ledger/checklist, release leases, do not run `execute_report` or lifecycle/archive commands, and stop at `READY_FOR_SUPERVISOR_EXECUTE`. This records B011's pre-execution callback boundary, not the later supervisor archive state.
- Assigned item did not require split repair before final report: IDA MCP reconfirmed `0x004c0f80` is a modeled function start, `0x004c3123` is not a function, and the next modeled function starts at `0x004c3190`.
- Every source-bearing child in scope already exists: UID0002PK is the exact child for slot `dword_69B3E8`; UID00016L remains a non-emitting aggregate; related callees UID00016M/UID00016N are separate SoftwareBlend16 helpers.

## Inference Research Guidance Check

- `by-structure.md` was applied as follows: `CANONICAL_OWNER` records semantic ownership, `EMITTER_UIDS` records generated output route, and the C++ gate is a minimum eligibility rule rather than permission to add weak code.
- Existing docs treated as uncertain and rechecked: old RankingEventListPane generated ownership, old scalar final-argument/flags wording, concrete `SurfaceSpriteBlitOptions` layout assumptions, local table vs padding boundary, and the broad aggregate page's non-emitting role.
- Direct IDA fact: exact ranges, function sizes, caller/callee/xref counts, stack frame arguments, option reads, switch-table bytes, helper calls, and global/constant refs.
- Documentation evidence: current support docs establish `SurfaceSpriteBlitProc`, opaque `SurfaceSpriteBlitOptions`, EPFTileContext encoded-mask names, Surface source route, and SoftwareBlend16 helper ownership.
- Inference: source-facing `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` is a descriptive name/direction, not an original-symbol proof; `SurfaceSpriteBlitOptions` remains an opaque forward-declared record because callers do not uniformly initialize all fields that RGB565 reads.
- Wave2/Wave3/generated output: generated output was used only as lead/current-state evidence. Wave2/Wave3-style generated names and caller-biased output labels were not treated as authority.

## Heuristic / Inference Reanalysis And Validation

- Owner/emitter route: current MCP shows no ordinary callers to `0x004c0f80`, only two target-address data refs at `0x0055882e` and `0x00558eb0`, plus 114 slot refs to `0x0069b3e8`. This validates Surface callback-table ownership and rejects RankingEventListPane or other feature-pane owners as callsite/generated pollution.
- Source placement: `Surface.cpp` is a provisional but current direct source route for installed callback targets. The exact helper math callees belong to SoftwareBlend16, but UID0002PK itself consumes destination state, source descriptors, palette fallback, clipping, mode dispatch, encoded masks, and option records; it is not a stateless math helper.
- Callback typedef/signature: support docs now resolve the safe source-facing slot-2 direction as `int` returning `SurfaceSpriteBlitProc`, destination draw receiver in `ecx`, six stack arguments, and nullable opaque `const SurfaceSpriteBlitOptions *options`. Current MCP stack frame for UID0002PK confirms `arg_0`, `arg_4`, `arg_8`, one-byte `arg_C`, `arg_10`, and `arg_14`, plus the saved `ecx` destination receiver.
- Destination/source-context fields: current MCP rechecks preserve `ecx` as destination, reads draw-enabled byte `+0x71`, destination buffer/pitch/origin state through `+0x20`, `+0x28`, `+0x2c`, and `+0x30`, and reads source descriptor `+0x20` as encoded mask byte count. EPFTileContext support docs name `+0x20/+0x24` as `encodedMaskByteCount` and `encodedMaskBytes`.
- Mode/options record: top-level `arg_C` is a six-case byte switch at `0x004c11b3-0x004c11c6`. Case 1 enters an option-pointer path that null-checks `arg_14`, reads selector byte `+0`, uses an eight-case option switch at `0x004c130f-0x004c1320`, and reads option bytes/dwords at `+0x08`, `+0x0c`, and `+0x1c`.
- Concrete options layout remains unsafe: UID00041R writes kind `3`, alpha `+0x04`, and palette/tint `+0x08` but leaves `+0x1c` unwritten; UID00041U kind `6` similarly initializes only `+0` and conditionally `+8`. Current UID0002PK MCP reads `+0x1c` at `0x004c138a`, `0x004c189d`, and `0x004c1eee`, so a zero-initialized or fully declared struct would change or overstate behavior.
- Branch/switch-table boundaries: `0x004c3123-0x004c3190` begins with `0x90` followed by little-endian local code target dwords such as `0x004c11cd`, `0x004c12d5`, `0x004c2a6f`, `0x004c2b7e`, and `0x004c3110`. It is `0x6d` / 109 bytes (Verified with MCP `int_convert`) and must remain local switch data.
- RGB565 helper relationships: current MCP finds calls to `_memmove` at `0x004c1219` and `0x004c2713`, UID00016M `BlendRgb565Pixel` at nine sites, UID00016N `BlendRgb565Pair` at `0x004c2d0b`, plus `0x00460370` and `0x00460500`. These are callee/helper dependencies, not owner routes.
- Source-ready peer contrast: UID0002TI's accepted first-draft body proves that some Surface RGB565 callbacks can emit when their branch space is bounded and source-shaped. UID0002PK is not comparable yet: it is much larger, has nested option/switch paths, and reads caller-uninitialized options fields.
- Rejected alternatives: RankingEventListPane and other feature panes are consumer/generated pollution; SurfaceRenderCallbackTable owns storage and typedef context, not this implementation body; SoftwareBlend16 owns called math helpers, not the callback implementation; UID00016L is a non-emitting inventory; concrete options struct/initialized source C++ is behavior-unsafe now; splitting the `0x004c3123` table would misclassify compiler-generated switch data.
- Remaining unresolved issue: exact original mode enum names, concrete options initialization policy, and source-shaped decomposition of all branch families remain unresolved after current MCP/support checks. This limits C++ and caps score, but it no longer blocks improving the target prose, current generated-state wording, typedef direction, and option-record no-code proof.

## Evidence Standards Used

- Live IDA MCP was required and used as primary evidence for binary facts: server health, function lookup, function profile, stack frame, xrefs, callees, basic blocks, disassembly slices, rendered listing searches, raw bytes, and integer conversion.
- Current by-* docs were used as support evidence only when consistent with live MCP: Surface owner/source route, SurfaceRenderCallbackTable typedef/storage state, EPFTileContext field names, ItemObjImageLib option callers, and SoftwareBlend16 helper ownership.
- Generated files were used only for current-state evidence: `Surface.cpp` marker, research tracker row, and by-memory generated coverage row.
- Old B reports were searched and opened as leads only; current MCP/support docs decide the recommendation.
- Negative evidence had to be explicit: no direct callers, only data target refs, broad slot fanout, no ordinary helper ownership route, no safe concrete options struct, and no function at `0x004c3123`.
- Evidence is strong enough for ownership, range, score improvement, and no-code proof. It is not strong enough for formal C++ because the remaining unresolved issues affect behavior-preserving source shape.

## Evidence Checked

- IDA MCP session: `supervisor_recovery_20260705`, `server_health` status `ok`, module `NexusTK.exe`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis and Hex-Rays ready.
- IDA MCP function checks: `lookup_funcs` for `0x004c0f80`, `0x004c3123`, `0x004c3190`, `0x004bc090`, `0x004c3ea0`, `0x004c6050`, and `0x004c60d0`; `func_profile` for UID0002PK; `basic_blocks`; `stack_frame`; `export_funcs`; `callees`; `xrefs_to`; bounded `disasm`; bounded `search_text`; `get_bytes`; `int_convert`.
- IDA MCP current facts checked: `sub_4C0F80` at `0x004c0f80`, size `0x21a3`; `0x004c3123` not a function; next modeled `sub_4C3190` at `0x004c3190`; 2109 instructions; 308 blocks; no direct callers; 12 unique callees; decompiler prototype `char __userpurge@<al>(int@<ecx>, __m64@<mm3>, _DWORD *, __m64 *, __int128 *, char, _BYTE *, char *)`.
- Xref checks: `xrefs_to 0x004c0f80` returned exactly two data refs, `0x0055882e` and `0x00558eb0` in `sub_558840`; `xrefs_to 0x0069b3e8` returned `xref_count:114`, `more:false`, including refs at `0x004b9957`, `0x004b99a6`, `0x004b9a4a`, `0x004ba2ca`, `0x004ba403`, `0x004ba7b6`, `0x004d1b31`, and many UI/render functions.
- Branch/option checks: top-level `arg_C` switch at `0x004c11b3-0x004c11c6`; `arg_14` reads at `0x004c12ec`, `0x004c12f6`, `0x004c1352`, `0x004c1380`, and `0x004c23bf`; option `+0x1c` reads at `0x004c138a`, `0x004c189d`, `0x004c1eee`; `+0x08` reads at `0x004c1355`, `0x004c188b`, `0x004c1edc`; `+0x0c` reads at `0x004c23c2` and `0x004c2429`.
- Helper/global checks: `dword_67A7E0` refs at `0x004c0fd0`, `0x004c1334`, `0x004c1885`, `0x004c1ed6`; `dword_6104CC` refs at `0x004c1664`, `0x004c19b4`, `0x004c2a83`, `0x004c2b92`; `dword_6104B0` refs at `0x004c166c`, `0x004c19c2`, `0x004c2a8b`, `0x004c2ba3`.
- Helper call checks: UID00016M `sub_4C6050` at nine call sites; UID00016N `sub_4C60D0` at `0x004c2d0b`; `sub_460370` at `0x004c2a54`; `sub_460500` at `0x004c2ad4`; `_memmove` at `0x004c1219` and `0x004c2713`.
- Bytes checked: `get_bytes 0x004c3123 size 109` returned `0x90` then local target dwords; `int_convert` verified `0x21a3 = 8611` and `0x6d = 109`.
- by-* docs checked: target UID0002PK; Surface file; RGB565 aggregate UID00016L; SurfaceRenderCallbackTable global/memory pages; SurfaceSpriteBlitHelper UID000167; compat peer UID0002PH; ItemObjImageLib UID00041R/UID00041U callers; EPFTileContext class/file; UID00016M/UID00016N; SoftwareBlend16 file.
- Generated state checked: `auto-generated/NexusTK/render/Surface.cpp`; `auto-generated/-ag-research-tracker.md`; `auto-generated/-ag-coverage-report-by-memory.md`. A read-only attempt to inspect nonexistent `auto-generated/-ag-coverage-report-by-file.md` failed with path-not-found and had no side effects.
- Negative checks performed: no function at `0x004c3123`; no direct callers; target refs are data refs only; slot xrefs are broad consumers, not owner proof for feature panes; concrete options struct unsafe; generated RankingEventListPane output is not current owner proof.
- Failed/unavailable/skipped checks: no IDA edits, type edits, renames, or binary patches were attempted. During the initial report-only pass no validators were run; during the implementation callback B011 ran the scoped target validator recorded under `## Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002PK-001 | UID0002PK should remain `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank emitter position. | High | MCP xrefs/callers; Surface docs; callback-table support | Target metadata / Status / Reconstruction Notes | already-present | already-present: target metadata still has Surface owner/emitter, reconstructable true, and blank emitter position after callback. |
| C-0002PK-002 | Raise target score from historical `86/89` to current `88/90`. | Medium-high | Current MCP recheck plus resolved typedef/current-state/stale wording blockers | Target metadata / Score Rationale | applied | applied: target metadata and score rationale now show `COMPLETION:88` and `CONFIDENCE:90`; validator `000000007462` confirmed updates. |
| C-0002PK-003 | Formal C++ must remain blank despite numerical eligibility. | High | 2109 instructions, 308 blocks, nested switches, unsafe options layout, decompiler prototype | Target `RECONSTRUCTION_CPP` / Reconstruction Notes | applied | applied: target formal C++ block remains blank and Reconstruction Notes now contain the target-specific no-code proof. |
| C-0002PK-004 | Current generated route is Surface empty emitter marker, not current RankingEventListPane ownership. | High | `Surface.cpp` marker; target metadata | Target Status / generated route wording | applied | applied: target Status now frames RankingEventListPane as historical caller-biased pollution and validator `000000007462` refreshed `Surface.cpp` marker to `88/90`. |
| C-0002PK-005 | The item-summary phrase "corrected-gate parent blocker" is stale. | High | Current target owner/emitter set to `0000OC`; Surface clears parent route | Target Item Summary / generated coverage after validator refresh | applied | applied: target Item Summary replaced the stale phrase; generated by-memory coverage refreshed from the new summary at `88%`. |
| C-0002PK-006 | `sub_4C0F80` exact range is `0x004c0f80-0x004c3123`, size `0x21a3` / 8611 bytes. | High | MCP `lookup_funcs`, `func_profile`, `int_convert` | Target IDA MCP Evidence / Address Range | applied | applied: target B011 MCP evidence records range, size, and 8611-byte conversion. |
| C-0002PK-007 | `0x004c3123` is not a function and `0x004c3190` is next modeled function. | High | MCP `lookup_funcs` | Target Address Range / Local Switch Data | applied | applied: target B011 MCP evidence and range notes record non-function end and next modeled function. |
| C-0002PK-008 | `0x004c3123-0x004c3190` is local switch data, not padding or a child source object. | High | MCP `get_bytes`; local target dwords; `int_convert` | Target Local Switch Data / Range notes | applied | applied: Local Switch Data now records `0x6d` / 109 bytes, target dwords, and no split/padding classification. |
| C-0002PK-009 | There are no direct code callers to `0x004c0f80`; runtime dispatch is through `dword_69B3E8`. | High | MCP `func_profile` caller_count 0; `xrefs_to` data refs only | Target IDA MCP Evidence / Ownership Notes | applied | applied: target evidence and Ownership Notes record no direct callers and slot dispatch route. |
| C-0002PK-010 | Target-address refs are exactly `0x0055882e` and `0x00558eb0` in setup/`sub_558840`. | High | MCP `xrefs_to 0x004c0f80` | Target IDA MCP Evidence | applied | applied: target B011 MCP evidence records both setup data refs. |
| C-0002PK-011 | Slot `0x0069b3e8` has 114 refs and broad render/UI consumers. | High | MCP `xrefs_to 0x0069b3e8`; support docs | Target IDA MCP Evidence / Direct Xrefs | applied | applied: target B011 MCP evidence records 114 refs and representative broad consumers. |
| C-0002PK-012 | Source-facing slot-2 typedef direction is `SurfaceSpriteBlitProc` / `g_pfnBlitSprite`, int return, receiver in `ecx`, six stack args, opaque nullable options pointer. | Medium-high | SurfaceRenderCallbackTable docs; target stack frame; UID00041R/UID00041U | Target Touched State / Slot Typedef And Option Record Evidence | applied | applied: target Branch Role Map, Touched State, and Slot Typedef sections record the ABI direction. |
| C-0002PK-013 | The concrete `SurfaceSpriteBlitOptions` layout/init policy is unsafe. | High | UID00041R/UID00041U writes; MCP `+0x1c` reads | Target no-code proof / Option Record Evidence | applied | applied: target Slot Typedef and Reconstruction Notes preserve the unsafe concrete options proof. |
| C-0002PK-014 | Top-level `arg_C` mode switch is six cases at `0x004c11b3-0x004c11c6`. | High | MCP bounded disassembly | Target Branch Role Map / Option evidence | applied | applied: target Branch Role Map records the six-case `arg_C` switch. |
| C-0002PK-015 | Option pointer path reads selector `+0`, bytes `+8/+0x1c`, and dwords `+0x0c`. | High | MCP `search_text` and disassembly around `0x004c12ec-0x004c1320` | Target Touched State And Option Record Evidence | applied | applied: target B011 MCP evidence, Touched State, and Slot Typedef sections record selector, field reads, and option switch. |
| C-0002PK-016 | EPFTileContext source-context fields `+0x20/+0x24` are encoded mask byte count/bytes. | High | EPFTileContext docs; target `+0x20` read; B004 lead | Target EPFTileContext Encoded-Mask Role / Touched State | already-present | already-present with refresh: target already had EPFTileContext encoded-mask role and now Touched State also records `+0x20/+0x24`. |
| C-0002PK-017 | UID00016M and UID00016N are RGB565 helper callees owned by SoftwareBlend16, not owners of UID0002PK. | High | MCP helper calls; SoftwareBlend16 docs | Target RGB565 helper relationship / Ownership Notes | applied | applied: target evidence and Ownership Notes preserve SoftwareBlend16 as helper/callee context only. |
| C-0002PK-018 | RankingEventListPane, feature panes, SurfaceRenderCallbackTable storage page, UID00016L aggregate, and SoftwareBlend16 helper file are rejected as direct owner routes. | High | Xref/callee/support docs and by-structure ownership rules | Target Ownership Notes / Negative Evidence | applied | applied: target Ownership Notes now list each rejected owner/source route with reason. |
| C-0002PK-019 | No support docs require immediate edits because current support docs already contain slot-2 typedef, options caveats, Surface route, EPFTileContext fields, and helper ownership. | Medium-high | Support doc checks listed in Evidence Checked and callback support grep | Recommended Support Doc Changes | already-present | already-present: support docs were inspected and left unedited because they do not directly contradict the accepted report at same detail. |
| C-0002PK-020 | Target validator after accepted implementation should use scoped file mode with `--wait-generated`; support validators only if support docs are actually edited. | High | Workflow rules and generated Surface.cpp dependency | Implementation Tracking Checklist / Validator Results | applied | applied: target validator ran as command `000000007462`, exit code `0`, `ok:1`, generated refresh completed; no support validators were required. |

## Positive Evidence Summary

- Direct facts supporting recommendation: live MCP confirms exact function range, no direct callers, two setup target refs, 114 slot refs, Surface callback dispatch route, expected callee families, current stack arguments, local switch table, and option field reads.
- Corroborating documentation/generated evidence: Surface proposed contents includes UID0002PK as exact Surface-owned callback child; callback table docs define slot 2 as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`; generated Surface.cpp already routes UID0002PK through Surface as an empty emitter marker.
- Strongest inference chain: initializer refs install `0x004c0f80` into Surface slot `dword_69B3E8`; all runtime refs go through the slot; broad consumers span render/UI/image paths; target body consumes destination draw state and EPFTileContext source data; therefore Surface render callback implementation is the best direct owner while SoftwareBlend16 remains only callee/helper ownership.

## IDA MCP Facts

- Function/range facts: `sub_4C0F80` at `0x004c0f80`, size `0x21a3` / 8611 bytes; 2109 instructions; 308 basic blocks; `0x004c3123` not a function; next modeled `sub_4C3190` at `0x004c3190`.
- Data/table/padding facts: `0x004c3123-0x004c3190` is `0x6d` / 109 bytes and begins `90 cd 11 4c 00 d5 12 4c 00 ...`; local target dwords point back into `sub_4C0F80`.
- Xref facts: `xrefs_to 0x004c0f80` returned two data refs (`0x0055882e`, `0x00558eb0`); `xrefs_to 0x0069b3e8` returned 114 refs with `more:false`.
- Calee facts: `sub_516030`, `sub_543D40`, `sub_543D20`, `sub_4B96C0`, `sub_4B7CC0`, `sub_4B7EB0`, `_memmove`, security-cookie glue, `sub_4C6050`, `sub_460370`, `sub_460500`, and `sub_4C60D0`.
- Stack/prototype facts: stack frame has `arg_0`, `arg_4`, `arg_8`, byte `arg_C`, `arg_10`, and `arg_14`; export/decompiler prototype remains `char __userpurge@<al>(int@<ecx>, __m64@<mm3>, _DWORD *, __m64 *, __int128 *, char, _BYTE *, char *)`, which is not source-grade.
- Option facts: `arg_14` null check and reads at `0x004c12ec`, `0x004c12f6`, `0x004c1352`, `0x004c1380`, `0x004c23bf`; `+0x1c` reads at `0x004c138a`, `0x004c189d`, `0x004c1eee`.
- Negative IDA facts: no direct callers; no function at `0x004c3123`; no evidence that local switch data is a standalone source object; no source-grade final signature from Hex-Rays.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004c0f80-0x004c3123` | UID0002PK target | RGB565 slot-2 sprite/tile/frame blit callback | TRUE | Surface UID0000OC | current `88/90` after callback | exact child, blank C++ |
| `0x004c3123-0x004c3190` | no UID; local table | compiler-generated local switch data for UID0002PK | not separate | contained by UID0002PK control flow | n/a | do not split |
| `0x004bc090-0x004bd3e8` | UID0002PH | compat/RGB555 slot-2 peer | TRUE | Surface UID0000OC | `86/89` | blank C++ peer/no-code precedent |
| `0x004c3ea0-0x004c4364` | UID0002TI | RGB565 bitmask slot-6 peer | TRUE | Surface UID0000OC | source-ready peer | positive contrast only |
| `0x004c0770-0x004c5fde` | UID00016L | RGB565 callback aggregate inventory | FALSE | non-emitting inventory | `90/92` | no aggregate C++ |
| `0x004c6050-0x004c60c7` | UID00016M | `BlendRgb565Pixel` callee | TRUE | SoftwareBlend16 UID0000NT | `90/92` | helper owner, not UID0002PK owner |
| `0x004c60d0-0x004c6151` | UID00016N | `BlendRgb565Pair` callee | TRUE | SoftwareBlend16 UID0000NT | `90/92` | helper owner, not UID0002PK owner |
| `0x0069b3e0-0x0069b410` | UID0001PI | callback-table storage | TRUE | SurfaceRenderCallbackTable UID0000TN | `89/88` | storage/typedef support, not implementation owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0055882e` | data xref to `0x004c0f80` | raw setup-neighborhood target ref for RGB565 slot 2 |
| `0x00558eb0` | data xref to `0x004c0f80` in `sub_558840` | Surface initializer installs RGB565 slot-2 target |
| `0x0069b3e8` | 114 slot refs | broad runtime dispatch through slot, not direct function callers |
| `0x004b9957`, `0x004b99a6`, `0x004b9a4a` | slot refs in draw-sprite/render-frame/forwarder wrappers | direct render wrappers consume slot 2 |
| `0x004ba2ca`, `0x004ba403` | slot refs in UID000167 | `GrafPort::BlitSurface` null-options caller |
| `0x004ba7b6` | slot ref in UID00016A | tiled background consumer |
| `0x004d1b31` | slot ref in MapTileImageLib path | map/tile consumer |
| `0x004c1219`, `0x004c2713` | `_memmove` calls | straight row/span copy paths |
| `0x004c17e5`, `0x004c1e24`, `0x004c1e30`, `0x004c2537`, `0x004c2934`, `0x004c2b25`, `0x004c2d4d`, `0x004c3024`, `0x004c30ca` | UID00016M calls | single-pixel RGB565 blend helper use |
| `0x004c2d0b` | UID00016N call | packed-pair RGB565 blend helper use |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: target page already records range, xrefs, callee set, branch map, touched state, local switch data, and Surface ownership. Support docs now record slot-2 typedef and opaque options pointer, EPFTileContext encoded-mask fields, UID00041R/UID00041U options proof, and SoftwareBlend16 helper ownership.
- Historical docs that were stale/incomplete before callback: target current generated-owner wording said RankingEventListPane as current truth; item summary/generated row said "corrected-gate parent blocker" as current truth; target lacked the July 2026 slot-2 options/typedef repair and current 2026-07-05 MCP session evidence.
- B011 callback-time generated/coverage report state: generated `Surface.cpp` had an empty UID0002PK marker at `88/90` under validator command `000000007462`; tracker row reported `88/90`, combined `89.0`, reports `0` before supervisor execution; by-memory generated coverage said `emits_code:false`, reconstructable, `88%`, `very-strong`, and mirrored the refreshed item summary. Later supervisor execution may update generated headers, tracker counts, and lifecycle history.
- IDA status: current MCP is live and schema-current. No IDA DB edits are requested.

## Ranked Ownership Analysis

### 1. Surface / `NexusTK/render/Surface.cpp`

- Evidence for: initializer data refs install `0x004c0f80` as the RGB565 target for Surface slot `dword_69B3E8`; broad runtime users dispatch through the slot; Surface docs list UID0002PK among exact Surface-owned callback children; generated output already routes UID0002PK into `Surface.cpp` as an empty marker.
- Evidence against: `Surface.cpp` remains a provisional shared render bucket, not a proven original source filename, and exact public callback implementation name is not recovered.
- Decision: accepted current owner/emitter route. The provisional source-file caveat caps score but does not justify moving the exact callback.

### 2. SurfaceRenderCallbackTable / callback-table storage pages

- Evidence for: `dword_69B3E8` storage and slot typedef context are central to dispatch and current signature recovery.
- Evidence against: the storage/global pages own the table declaration and support typedef context, not the 8611-byte implementation installed into the slot.
- Decision: support context only; do not set as direct owner for UID0002PK.

### 3. SoftwareBlend16

- Evidence for: UID0002PK calls RGB565 helper math owned by SoftwareBlend16, including UID00016M and UID00016N.
- Evidence against: UID0002PK is not a stateless math helper; it is an installed callback target with destination/source/palette/options/clip state and broad slot dispatch. SoftwareBlend16 docs explicitly limit direct ownership to helpers called by the callback bodies.
- Decision: rejected as direct owner; preserve as callee/helper context.

### 4. RankingEventListPane or other feature panes

- Evidence for: older generated output and some consumers are feature-pane-heavy.
- Evidence against: current MCP finds no direct code callers to the function, only setup data refs; slot fanout spans many render/UI/image callers; target body has no RankingEventListPane-specific state.
- Decision: rejected as caller-biased/generated pollution.

### 5. UID00016L RGB565 aggregate

- Evidence for: aggregate contains the exact callback family and records split/slot context.
- Evidence against: aggregate is `RECONSTRUCTABLE:FALSE` and non-emitting; exact children carry source ownership.
- Decision: use as inventory/support only; do not emit or assign UID0002PK through the aggregate.

## Source Placement

- Recommended source file/class/global/module placement: keep UID0002PK routed through [UID:0000OC] `Surface` / `NexusTK/render/Surface.cpp` as a software render callback implementation.
- Why this placement fits source-tree and subsystem context: slot setup, callback dispatch, SurfaceRenderCallbackTable storage, and current exact RGB565 callback family rows all live in the shared render/surface backend. The function operates below feature panes and above low-level RGB565 helper math.
- Rejected placements and why: RankingEventListPane/feature panes are consumers; SurfaceRenderCallbackTable is storage; SoftwareBlend16 owns callees only; UID00016L is an inventory; a new `SoftwareRenderCallbacks.cpp` could become plausible in a future source-tree cleanup but is not proven better than current Surface route.
- Remaining placement uncertainty: exact original filename and exact implementation symbol spelling remain inferred. This uncertainty caps score but not current owner/emitter metadata.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: function range is `0x004c0f80-0x004c3123`; `0x004c3123` is not a function start; next modeled function begins at `0x004c3190`.
- Children/subranges: no new children should be created. UID0002PK is already the exact source-bearing child for this slot target.
- Padding/table/data/code distinction: `0x004c3123-0x004c3190` is local compiler-generated switch data beginning with `0x90` and local target dwords. It is not padding and not a standalone reconstructable table page.
- Parent/container impact: UID00016L remains a non-emitting callback-family inventory; UID0002PK remains the exact child and should carry target details.

## Negative Evidence Summary

- No direct code callers to `0x004c0f80`; this rejects ordinary method/caller ownership.
- Target-address refs are data refs from setup only; this supports callback-table installation rather than direct call reachability.
- Broad slot refs to `0x0069b3e8` are consumers; they prove shared dispatch fanout but not any single feature-pane owner.
- `0x004c3123` is not a function start; splitting the local switch table would be a range error.
- Generated RankingEventListPane names are not source-quality owner proof.
- `SurfaceSpriteBlitOptions` cannot yet be a concrete zero-initialized source struct because UID0002PK reads option bytes that UID00041R/UID00041U do not always initialize.
- UID0002TI source readiness does not generalize to UID0002PK because UID0002PK is far larger and has a different options/branch complexity profile.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: target docs should use `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` for slot 2 and `const SurfaceSpriteBlitOptions *options` as an opaque nullable final argument. `BlitRgb565SpriteCallback` is a plausible future implementation-name direction, but this report does not recommend an IDA rename or formal C++ symbol yet.
- Evidence for names/types: current support docs, UID000167 formal typedef, UID00041R/UID00041U nonzero options callers, and MCP target stack/option reads.
- Items intentionally left unchanged: IDA function name `sub_4C0F80` and decompiler prototype should not be treated as final source. No IDA rename/type/comment edits are requested during this report.
- Whether IDA DB edits are safe: not requested. This report is documentation-only.

## First-Draft C++ Recommendation

- Eligible for draft C++: numerically yes under the current gate (`88/90`, reconstructable true, nonblank emitter route), but eligibility is only a minimum condition.
- Recommended code: leave the formal target C++ block blank. Do not insert a sample/body-only reconstruction.
- Reason it preserves exact original behavior: blank formal C++ avoids emitting a decompiler-shaped, partially inferred 2109-instruction dispatcher that would likely misrepresent uninitialized option bytes and mode-specific behavior.
- Reason it matches plausible original source shape: the target still needs a source-shaped decomposition before any final body can look like mid-2000s developer C++; current evidence supports names and comments, not a safe full body.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: use `SurfaceSpriteBlitProc`, `g_pfnBlitSprite`, `EPFTileContext *sourceContext`, `RectBounds` source/destination rectangles, `mode`, palette pointer, and opaque `SurfaceSpriteBlitOptions *options` in prose only.
- Naming/coding style convention used and evidence: Surface/GrafPort support docs use simple C++ callback typedefs and descriptive render helper names; `SurfaceSpriteBlitProc` is already current support wording.
- Reason code should remain blank: body scale, nested switches, unresolved mode enum, unsafe concrete options struct, local switch table, and decompiler-shaped prototype.
- Exact no-code proof: UID0002PK has 2109 instructions, 308 blocks, six-case `arg_C` switch, option-selector switch, multiple row/blend/transform paths, local switch table at `0x004c3123`, and `arg_14` option reads including `+0x1c` at `0x004c138a`, `0x004c189d`, and `0x004c1eee`. UID00041R/UID00041U prove non-null callers that do not initialize all fields the RGB565 target reads. Any formal C++ now would require either raw byte/decompiler scaffolding or behavior-changing zero initialization.

## Final Recommendation

- Exact changes recommended: update UID0002PK target doc prose at report-level detail, raise score to `88/90`, preserve Surface owner/emitter/reconstructable metadata, keep formal C++ blank, and add the current no-code proof.
- Exact parent assignments recommended: no parent/owner/emitter change; keep Surface UID0000OC.
- Exact items left no-owner/non-emitting and why: none for UID0002PK. The target is reconstructable and routed through Surface but emits no body because formal C++ is unsafe now.
- Exact future work outside this assignment scope: a broader Surface callback signature/source-decomposition pass should recover global mode enum names, concrete options initialization policy, final implementation name, and source-shaped branch layout for UID0002PK and its compat peer.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md`.
- Metadata/score/owner/emitter/reconstructable/C++ changes: applied `COMPLETION:88`, `CONFIDENCE:90`; preserved `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`.
- Item Summary: applied replacement summary covering `dword_69B3E8`, `SurfaceSpriteBlitProc` / `g_pfnBlitSprite`, B011 MCP range/size, no direct callers, two setup data refs, 114 slot refs, 308 blocks / 2109 instructions, helper/global refs, option reads, local switch data, Surface route, and blank-C++ proof.
- Status: applied historicalization of "Current generated owner: caller-biased RankingEventListPane" as legacy generated-output pollution and stated current route as `Surface.cpp` empty emitter marker through UID0000OC.
- IDA MCP Evidence: applied the B011 2026-07-05 session facts from `supervisor_recovery_20260705`, including health, function range, size, block/instruction counts, exact xrefs, callee list, stack arguments, decompiler prototype, option reads, helper/global refs, and local switch bytes.
- Touched State / Option Record Evidence: applied destination receiver in `ecx`, stack arguments (`arg_0`, `arg_4`, `arg_8`, `arg_C`, `arg_10`, `arg_14`), source context/EPFTileContext names, option selector and field reads, and the `+0x1c` no-code blocker.
- Branch Role Map: applied top-level six-case `arg_C` switch at `0x004c11b3-0x004c11c6`, option-selector eight-case switch at `0x004c130f-0x004c1320`, and secondary option-local control flow around `0x004c13a0`.
- Local Switch Data: kept `0x004c3123-0x004c3190` as local switch data with `0x6d` / 109-byte conversion proof and local target dwords.
- RGB565 helper relationships: recorded current helper/callee set, call counts, and addresses for UID00016M/UID00016N, `0x00460370`, `0x00460500`, and `_memmove`.
- Reconstruction Notes / C++ readiness: replaced generic wording with the exact no-code proof; noted that slot typedef direction is partially resolved but full formal C++ remains unsafe.
- Ownership Notes / Negative Evidence: preserved rejected alternatives at report-level detail: RankingEventListPane/feature panes, SurfaceRenderCallbackTable storage, SoftwareBlend16 helper ownership, UID00016L aggregate, concrete options struct, splitting the switch table, and transferring UID0002TI source readiness.
- Score Rationale: justified current `88/90`; reason not higher cites unresolved mode enum, concrete options struct/init policy, full branch decomposition, exact original symbol/source-file uncertainty, and blank C++.

## Recommended Support Doc Changes

- `by-file/Surface.md`: no edit made. It already lists UID0002PK as an exact Surface-owned callback child and records the RGB565 callback family route; callback recheck found no same-detail contradiction requiring support-doc modification.
- `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`: no required edit. It already treats UID0002PK as an exact Surface-owned child and keeps the aggregate non-emitting.
- `by-global/SurfaceRenderCallbackTable.md` and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`: no required edit. They already record slot 2 as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, int return, destination receiver in `ecx`, six stack args, nullable opaque `SurfaceSpriteBlitOptions`, and UID0002PK `+0x1c` reads.
- `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`: no required edit. It already carries the repaired formal typedef and null-options callsites.
- UID00041R/UID00041U docs: no required edit. They already contain the relevant partial-options initialization/no-code evidence.
- EPFTileContext and SoftwareBlend16 support docs: no required edit. They already contain encoded-mask field names and helper-owner routes.
- Metadata/link/score/coverage/source-placement changes: none recommended for support docs in this report.

## Score And Metadata Recommendation

- Historical pre-callback score/metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank emitter position, blank C++.
- Post-callback score/metadata applied by B011: `COMPLETION:88`, `CONFIDENCE:90`; all other metadata unchanged.
- Score rationale and reason not higher/lower: completion should rise because current MCP revalidates exact binary facts and this report resolves stale current-generated-owner wording, stale parent-blocker wording, source-facing slot-2 typedef direction, option-pointer evidence, and target-specific no-code proof. It should not rise above 88 because a large amount of branch/source decomposition remains unwritten and C++ stays blank. Confidence should rise to 90 because current MCP and support docs align tightly; it should not rise higher because concrete options layout, original mode enum names, final implementation name, and final source decomposition remain inferred or unresolved.
- Score-improvement attempt: callback typedef was rechecked through SurfaceRenderCallbackTable, UID000167, and current stack frame; resolved to opaque `SurfaceSpriteBlitProc` direction. Destination/source-context fields were rechecked through MCP and EPFTileContext; resolved enough for prose. Mode/options records were rechecked through MCP and UID00041R/UID00041U; resolved to opaque options and exact no-code blocker. Branch/switch boundaries were rechecked through MCP; resolved as local switch data. Owner/emitter route was rechecked through xrefs/generated Surface.cpp; current route remains Surface. First-draft C++ was considered and rejected with exact no-code proof.
- Metadata fields to leave unchanged: `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`, and formal C++ block.

## Open Questions With Attempted Resolution

- Open question: final callback typedef/signature. Evidence checked: support docs, UID000167 formal typedef, UID00041R/UID00041U callers, target stack frame/prototype. Resolution: safe source-facing direction is `SurfaceSpriteBlitProc` with opaque options; exact implementation function symbol and final header declaration style remain unresolved and cap score/C++.
- Open question: destination/source-context fields. Evidence checked: target MCP disassembly, EPFTileContext docs, GrafPort helper docs. Resolution: destination receiver and EPFTileContext source context are strong enough for target prose; exact project-wide receiver base type remains `void *destination` in shared typedef until a common render-owner base is proven.
- Open question: mode/options record names. Evidence checked: top-level and option switch disassembly, UID00041R/UID00041U writes, support docs. Resolution: use opaque `SurfaceSpriteBlitOptions` and descriptive field roles (`kind`, `alpha`, `palette/tint`, `secondaryShift`) in prose; do not emit concrete struct or formal body.
- Open question: branch/switch boundaries. Evidence checked: `lookup_funcs`, `get_bytes`, disassembly, int conversion. Resolution: target range exact; post-function table local; no split needed.
- Open question: first-draft C++ eligibility. Evidence checked: by-structure code-entry rule, current score/emitter, MCP scale/option evidence. Resolution: numerically eligible but behavior/source-shape unsafe; blank formal C++ remains required.
- Remaining unresolved questions: exact original mode enum names, concrete options layout/init policy, full source-shaped branch names, and exact original callback implementation spelling. Future evidence required: a family-wide slot-2 source-decomposition pass that reconciles all non-null option callers and both compat/RGB565 installed targets without changing uninitialized-byte behavior.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable for direct manual coverage/tracker edits. The source by-memory target was edited and validated; generated coverage and tracker rows refreshed through scoped validator command `000000007462`.

## Follow-Up Actions

- Supervisor actions: perform Gate 2 claim-by-claim verification against the changed target, updated checklist/ledger, and validator output; execute the report only if verification passes.
- B011 callback actions: completed target lease/edit/validator/release cycle and updated this report checklist/ledger.
- Future research actions: broader Surface slot-2 pass for final options struct/init policy, mode enum names, and source-shaped UID0002PK/UID0002PH decomposition.

## Confidence

- Recommendation confidence: high for target-doc update and score bump; high for keeping Surface owner/emitter and blank C++.
- Score confidence: medium-high for `88/90`. The proof supports a modest increase but not near-final scores.
- Remaining uncertainty: exact original source filename/symbol spelling, full mode enum taxonomy, concrete `SurfaceSpriteBlitOptions` source declaration, and branch-level reconstruction.

## Validator Results

- Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md --apply --queue-timeout 240 --wait-generated`.
- Prior scoped validator pass before the final dispatch-context note: command id `000000007461`; command timestamp `2026-07-05T23:24:40-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`; generated Surface marker was refreshed to `88/90`.
- Final validator command id: `000000007462`; command timestamp: `2026-07-05T23:25:59-04:00`; exit code: `0`; `ok: 1`; `generated_refresh: completed`; `generated_refresh_command_id: 000000007462`; `generated_refresh_timestamp: 2026-07-05T23:25:59-04:00`.
- Validator-confirmed target updates: `completion_update 0002PK ... 88` and `confidence_update 0002PK ... 90`.
- Generated refresh state observed by B011: `auto-generated/NexusTK/render/Surface.cpp` header reported `validator-command-id: 000000007462`, `validator-refreshed-at: 2026-07-05T23:25:59-04:00`, and UID0002PK marker `Completion:88 | Confidence:90 | Empty Emitter Marker` after the final scoped validator. Later supervisor-owned lifecycle execution may refresh this header again.
- Other validator-owned side effects observed: `autogen_registry_rebuild`, `projected_stats_update`, generated metadata refreshes, `memory_auto_coverage_update`, and generated backup creation. These were validator-owned refreshes, not manual B011 edits.
- Support validators: not run because no support docs were edited.
- Unresolved target validator errors: none. Known unrelated warnings/noise remained `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` rows outside UID0002PK.

## Changed Files

- Manual by-* edit: `by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md`.
- Manual report edit: `tools/leaser/Agents/Agent-B011/research/0002PK-SoftwareRenderRgb565SpriteBlitCallback-source-quality.md`.
- Support docs edited: none.
- Validator-owned generated/state refreshes observed from command `000000007462`: `auto-generated/NexusTK/render/Surface.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, generated metadata reports, projected stats, and `validator.ini` registry rebuild.
- Renamed: none.
- Leases: B011 leased the target by-memory file for the immediate edit/validator batch, released it, then took a second short target lease for one dispatch-context note and released it after the final validator. B011's post-callback lease check showed no active B011 lease.
- Report execution/lifecycle boundary: during the B011 callback and this report-text repair, B011 did not run `execute_report`, execute dry-runs/probes, lifecycle/archive commands, manual report moves, broad validators, or registry lifecycle commands. This does not describe the eventual supervisor execution state; after supervisor execution, validator-owned executed archive/history/footer state is authoritative.

## Implementation Tracking Checklist

Initial report-only pass, now historical:
- [x] Supervisor validation required before implementation. State: completed by supervisor before this callback.
- [x] Target/support docs to update: target `by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md`; no required support-doc edits unless a direct contradiction appeared. State: target-only scope kept; no support contradiction found.
- [x] Current target state and actual evidence checked recorded. State: report records historical `86/89` and B011 post-callback `88/90`.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. State: rows C-0002PK-001 through C-0002PK-020 now show `applied` or `already-present`.
- [x] Metadata/score changes applied: target set to `COMPLETION:88`, `CONFIDENCE:90`; owner/emitter/reconstructable/emitter-position/C++ unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair, or evidence-backed no-improvement proof. State: typedef direction, owner route, branch/switch boundary, and no-code proof incorporated.
- [x] Owner/emitter/reconstructable changes to apply: none. State: existing Surface owner/emitter/reconstructable true verified.
- [x] Split/rename/new-child changes to apply: none. State: `0x004c3123-0x004c3190` preserved as local switch data, not padding/new child.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable. State: source placement remains Surface; no IDA edits requested or made.
- [x] First-draft C++ or no-code proof applied. State: formal C++ remains blank with exact no-code proof covering 2109 instructions, 308 blocks, nested switches, option `+0x1c` reads, and UID00041R/UID00041U partial initialization.
- [x] Third-party import directive to apply or confirm not applicable. State: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail. State: current MCP facts, generated state, typedef/options, destination/source fields, helper calls, local switch data, rejected alternatives, and score rationale are in the target.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. State: RankingEventListPane historical pollution, stale gate wording, rejected storage/helper/aggregate owners, no direct callers, no concrete options struct, and no split at `0x004c3123` are recorded.
- [x] Wave2/Wave3/generated caller-biased artifacts rejected as authority. State: generated/caller-biased output retained only as historical/current-output evidence.
- [x] Open questions documented with evidence-backed unresolved rationale. State: original mode enum, concrete options policy, exact implementation symbol, and full branch decomposition remain unresolved with score/C++ impact.
- [x] Validators run after accepted callback. State: command `000000007462`, timestamp `2026-07-05T23:25:59-04:00`, exit `0`, `ok:1`, generated refresh completed.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text. State: generated Surface.cpp, by-memory coverage, and research tracker refreshed by validator; no manual generated/coverage/tracker edits.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. State: user supplied Gate 1 pass and target-only callback.
- [x] All accepted target/support doc details incorporated at report-level detail. State: target details incorporated; support docs inspected and already sufficient.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. State: all rows resolved as `applied` or `already-present`; no `blocked` rows.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. State: score applied, metadata preserved, no split/rename, formal C++ blank by no-code proof.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. State: applied to target Ownership Notes, Reconstruction Notes, Item Summary, and Status.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. State: unresolved mode/options/source-decomposition questions remain documented as score/C++ caps.
- [x] Validators run and results recorded. State: command `000000007462` recorded above.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. State: generated refresh completed; no manual supervisor-owned coverage/tracker text needed.
- [x] Remaining unapplied accepted items listed with exact blocker. State: none; every accepted item is applied or already present with reason.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000007474","destination_path":"executed-b-agent-research/B011/0002PK-SoftwareRenderRgb565SpriteBlitCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0002PK-SoftwareRenderRgb565SpriteBlitCallback-source-quality.md","timestamp":"2026-07-05T23:59:19-04:00","uid":"0002PK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
