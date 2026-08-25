** TARGET-REPORT-UID:0003A5 **
** TARGET-REPORT-ADDITIONAL-UIDS:0004YF,0004YI,0004YJ,0004YL,0004YM,0004YN **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003A5 ScrollPaneInputGeometryHelpers Source-Quality Report

## Finalized Report / Current Recommendation

[UID:0003A5] is a source-authored seven-method `ScrollPane` input/geometry family, not one source function. The six formerly unsplit helpers are now resolved to branch-level behavior, source-facing names, signatures, field use, caller relationships, source placement, and destination-ready first-draft C++. The existing exact [UID:0001GK] `GetScrollPartRect` page supplies the seventh method. All part-bearing declarations, definitions, fields, and applied IDA types now share one signed one-byte `ScrollPanePart` contract.

The accepted ordinary documentation shape is now applied and scoped-valid:

- [UID:0003A5] is a reviewed non-emitting split index at `93/94`, owner `0000CM`, reconstructable false, with blank emitter and formal CPP/H;
- six exact reconstructable by-memory children now exist for `HitTestPart`, `SetHighlightedPart`, `BeginPartPress`, `ProcessActivePart`, `UpdatePositionFromCursor`, and `ResetScrollState`;
- all six new children and existing [UID:0001GK] route directly through [UID:0000CM] `ScrollPane`, then [UID:0000NF] `ScrollBar`;
- every exact child contains its accepted implementation body, and [UID:0000CM] contains the bounded source-ready formal H declaration for the accepted emitted `ScrollPane` members;
- [UID:0000VN] now classifies every inter-function `0xcc` run and the `0x0055e1ed-0x0055e210` compiler-generated `ProcessActivePart` switch-table tail plus alignment;
- [UID:000433] now uses the accepted Y-first helper ABI in both EPF and classic paths.

No helper or ABI-contract blocker is deferred. Exact original spellings are unavailable in the stripped binary, so the names below are the highest-probability human source names selected from behavior, accepted project vocabulary, and two independent sibling scrollbar families.

## Supporting Research

The initial research phase was report-only. After supervisor Gate 1 accepted exact SHA256 `0EF25C93292AA70A8514AC7EFA8EADC67FAEFD8AD57C35489F4F66AF07329214`, B005 performed the authorized same-report implementation callback. B005 created and updated only accepted ordinary by-* destinations under short-lived leases and ran serial scoped validators with `--no-generated-refresh`. The supervisor separately applied and independently verified IDA-F1 through IDA-F7 and IDA-T1/T2 under catalog entry `0359`; B005 did not mutate or save IDA and only reconciled that saved poststate into ordinary documentation and this report. B005 did not edit coverage/generated/supervisor/audit/catalog/lifecycle/goal/notes files or run/probe any report-lifecycle command.

Evidence was reconciled from:

- the current target, class, file, containing corridor, exact child, input, timer, draw, constants, and scroll-owner documentation;
- current generated `NexusTK/ui/core/ScrollBar.cpp` topology;
- current manual coverage state and ignored-range state;
- matching executed B-agent reports for [UID:0001GK], [UID:0001GH], [UID:000433], [UID:000435], [UID:0001GI], [UID:0001GL], [UID:00042W], and [UID:0000NF];
- the accepted `FittingRoomScrollPane` and `RankingEventScrollPane` sibling families;
- a fresh read-only IDA MCP pass over all seven functions, direct xrefs, decompilations, function boundaries, stack frames, UDTs, comments, bytes, and the switch-table tail.

Historical assumptions are retained here where useful, but superseded claims are labeled rather than reused as current facts.

## Target

- Target UID: `0003A5`.
- Additional target UIDs: `0004YF,0004YI,0004YJ,0004YL,0004YM,0004YN`, declared in exact report order after serial scoped validators assigned all six identities.
- Target path: `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md`.
- Report path: `tools/leaser/Agents/Agent-B005/research/0003A5-ScrollPaneInputGeometryHelpers-source-quality.md`.
- Historical source-queue checkpoint: `auto-generated/-ag-research-tracker.md` validator command `000000018895`, refreshed `2026-07-29T07:49:11-04:00`, SHA256 `21171036DD059D779DA0597D55C1075F93AF5AED9917E17063C1BE3485BD2274`, 1,669,011 bytes, 6,603 lines, physical last write `2026-07-29T07:49:15.4305610-04:00`. Its exact preimplementation UID0003A5 row was line 1672 and reported `87/89`, average `88.0`, reconstructable `true`, and zero direct/additional report counts:

```text
| [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) | 87/89 | 88.0 | true | 0 | 0 | 0 |  |  | `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` |  |  |
```

- Current generated and tracker authority is unified at validator command `000000019483`, refreshed `2026-07-29T14:30:34-04:00` from `foreground-generated-refresh`. The exact current identities and topology are recorded below. Commands through `000000019259` remain dated history only. Any later artifact-specific validator header plus exact physical hash/size/line readback supersedes only the corresponding checkpoint.
- Range: `[0x0055d960,0x0055e65c)`.
- Current ordinary metadata after callback: `93/94`, owner [UID:0000CM], reconstructable false, blank emitter/position, `Nested:8`, blank formal CPP/H, and a complete seven-child split index.
- Implemented outcome: all six unsplit helper blockers are exact registered child pages; [UID:0001GK] is directly rerouted; accepted class/file/caller/timer/corridor/ignored documentation is reconciled and scoped-valid.

## Current Target State

The target now identifies seven modeled functions and generic `ScrollPane` ownership through exact child links. Its former provisional-name and unresolved branch/signature statements are preserved only as history and superseded by the applied split.

The target no longer treats the family as a reconstructable aggregate emitter. It is a non-emitting index over seven independent C++ member functions, five ordinary alignment gaps, one compiler-generated switch-table tail, and the outside-target successor fence.

Existing [UID:0001GK] and all six new pages are now peer class children under [UID:0000CM].

The bounded manual-coverage preflight against the current ordinary pages and exact live manual rows found `20` applicable supervisor-owned row changes: `15` insertions and `5` replacements. The prior `17` staged changes remain valid. Three additional replacements are now staged atomically for stale [UID:0001GH] (`76%`/reconstructable manual row versus current `88/90` non-reconstructable split index), [UID:0001GI] (`78%` manual row versus current `88/90` reconstructable draw method), and callback-touched [UID:0001GJ] (`82%`, reconstructable, displayed through `0x00565488` versus current `89/91`, non-reconstructable, exact range through `0x005654ec`). [UID:0000NF] remains one exact no-op. The existing UID0001GH, `0x0055c643-0x0055c650`, UID0001GJ, and UID0001GL row locations remain valid placement anchors after their applicable replacements.

The separate generated research queue command `000000018895` records the preimplementation target at `87/89`, reconstructable true, with zero direct/additional report counts and is retained only as dated history. Commands through `000000019259` and their exact tracker identities are earlier dated postimplementation checkpoints. The current tracker is command `000000019483`, refreshed `2026-07-29T14:30:34-04:00` from `foreground-generated-refresh`, SHA256 `A2C97D53EA038671299109D5455954FD909A2DFF0E6BCB9673E8CABD2518DC65`, 1,676,576 bytes/6,632 lines, physical last write `2026-07-29T14:30:53.2980054-04:00`; its UID0003A5 row at line 5544 remains `93/94`, average `93.5`, reconstructable `false`, with zero direct/additional report counts. This matches current ordinary metadata. It is a physical queue checkpoint, not report lifecycle authority; report execution/archive state remains authoritative only from the current path and validator-owned status/history metadata.

Generated read-only evidence was inspected again during this exact-artifact currentness audit. B005 did not run the validator or generate any artifact. The research tracker and generated source remain independent artifacts with independent command provenance:

- the earlier checkpoint was `auto-generated/NexusTK/ui/core/ScrollBar.cpp` SHA256 `A39011C58C95984A90975323EC016C906B1CCE703C3C6FE85A8BE699B089764B`, 21,405 bytes, 621 lines, last write `2026-07-29T04:09:45.7726993-04:00`;
- validator command `18812` at `2026-07-29T04:41:43-04:00`, side effect `foreground-generated-refresh`, produced the historical report-time `ScrollBar.cpp` SHA256 `E62179E53912E86DB5B857822A078EF7F714EB11710CA090894D55DE5CF216E8`, 21,405 bytes/621 lines, last write `2026-07-29T04:42:02.0394828-04:00`, while `ScrollBar.h` was then absent;
- commands through `000000019259` and their exact CPP/H identities are retained only as earlier dated generated checkpoints;
- current validator command `000000019483`, refreshed `2026-07-29T14:30:34-04:00` from `foreground-generated-refresh`, produced `auto-generated/NexusTK/ui/core/ScrollBar.cpp` SHA256 `F3A446D6B85768A8F74FD0456D1D0F864609D55F648241099A6398BC53A856F5`, 25,913 bytes/806 lines, physical last write `2026-07-29T14:30:47.5362523-04:00`, and `auto-generated/NexusTK/ui/core/ScrollBar.h` SHA256 `3D2057DC66587D9802C14B862789666A9462622EFDC33BF33D5B630435F67CFC`, 1,866 bytes/53 lines, physical last write `2026-07-29T14:30:47.5696882-04:00`;
- the current CPP contains exactly one definition each for UID0004YF, UID0001GK, UID0004YI, UID0004YJ, UID0004YL, UID0004YM, and UID0004YN; UID0003A5 has no aggregate definition or empty-emitter marker;
- the current H contains UID0000CM's one-byte `ScrollPanePart` typedef/constants, one `ScrollPane` declaration, all seven method declarations, and the accepted member layout. Definitions therefore remain child-owned while declarations remain class-owned;
- lifecycle-time currentness must still re-read validator headers and physical identities if any artifact advances after supervisor coverage/IDA work.

## Executive Recommendation

The accepted split-index conversion and six exact child creations are implemented. The source-facing reconstruction now uses:

| Address | Recommended source method |
| --- | --- |
| `0x0055d960` | `ScrollPanePart ScrollPane::HitTestPart(int localY, int localX)` |
| `0x0055d9e0` | `void ScrollPane::GetScrollPartRect(ScrollPanePart part, RectBounds *outRect)` |
| `0x0055dea0` | `void ScrollPane::SetHighlightedPart(ScrollPanePart part)` |
| `0x0055df10` | `void ScrollPane::BeginPartPress(ScrollPanePart part, int localY, int localX)` |
| `0x0055dfd0` | `void ScrollPane::ProcessActivePart()` |
| `0x0055e210` | `void ScrollPane::UpdatePositionFromCursor(int localY, int localX)` |
| `0x0055e600` | `void ScrollPane::ResetScrollState()` |

The one-byte `ScrollPanePart` source typedef and typed constants, the bounded source-ready `ScrollPane` declaration for accepted emitted members, and the seven method declarations belong in [UID:0000CM]'s formal H block. Exact implementations belong only in exact by-memory child CPP blocks. Unrelated class APIs are not declared by inference in this bounded pass.

## Supervisor Active Recheck

The supervisor completed Gate 2B for all seven function actions and both analysis-type actions, independently verified the result, saved it, and recorded catalog entry `0359` as `APPLIED_VERIFIED_RECONCILIATION_REQUIRED_FOR_SAVED_STATE`. B005 then reconciled every affected ordinary destination and revalidated each changed file serially with `--no-generated-refresh`.

The remaining supervisor review should:

1. Audit this exact post-reconciliation report artifact and verify the 14 ordinary destinations against the exact current hashes and command IDs below.
2. Confirm the six canonical child identities remain UID0004YF, UID0004YI, UID0004YJ, UID0004YL, UID0004YM, and UID0004YN with no provisional identity token.
3. Recheck the 20 staged manual coverage operations and UID0000NF no-op against the current coverage identities before applying supervisor-owned coverage edits.
4. Perform the authoritative final generated/tracker readback after any coverage validation; current command `000000019483` is a dated physical checkpoint.
5. Reconcile catalog entry `0359` from its current saved-state reconciliation state only after claim-by-claim ordinary/report verification. Report execution/archive remains supervisor-only and authoritative only from the artifact path plus validator-owned lifecycle metadata.

The original live read-only MCP research checkpoint used by B005 was healthy and responsive and is retained as dated provenance:

- endpoint `http://127.0.0.1:13337/mcp`;
- MCP session `7ef422d7-2eee-41f5-ad6f-a80e5b46870a`;
- database session `5a570ede`;
- IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`;
- worker PID `7608`, active true, analyzing false;
- server health `ok`, Hex-Rays ready, strings cache ready;
- no mutation calls were made.
- a later read-only exact-artifact repair pass on the same database session independently queried all seven proposed names, all seven current functions/frames/locals, and `Pane`/`ScrollPane`/`ScrollPanePart`/`ScrollPanePartValue`; those historical literal results are preserved below.

The final pre-mutation report-only currentness preflight used active database `1da2b2ae`; its collision-free raw names, absent types, frames, and literal prestates remain dated historical evidence below. Supervisor Gate 2B first saved the verified UID0003A5 state as SHA256 `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`, 143,190,452 bytes, at `2026-07-29T12:53:48.4762005-04:00`, from protected backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B005-UID0003A5-20260729-124819.i64`, SHA256 `E9600F6C16B46FE1F5A7FEE463EF7890E415905CE465F8F6C55954FF5AA91611`, 143,190,173 bytes. Shared saves `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, and `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1` are historical.

After unrelated supervisor saves, B005 performed a bounded read-only no-drift check against session `1da2b2ae` and current authoritative IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`. `server_health` returned `status:"ok"`, Hex-Rays ready, strings cache ready, and `auto_analysis_ready:false`; every bounded query succeeded. All seven applied names, exact prototypes, sizes, function-repeatable comments, blank other three comment channels, normalized frames, caller xrefs, complete `ScrollPanePart`/13-member `ScrollPane` types, dependency layouts, adjacent functions, and all 15 protected body/fence/NOP/table/padding hashes remained exact. B005 made no IDA mutation or save. The preceding `905D1AB1...` and earlier readbacks remain dated historical evidence only.

## Inference Research Guidance Check

The project goal is behavior-exact runtime reconstruction expressed as plausible mid-2000s human C++, not decompiler-shaped output. This report therefore distinguishes three levels:

- direct binary facts: ranges, calls, fields, branches, arithmetic, timer values, part values, and data-table placement;
- accepted cross-family source inference: method names and declaration style shared by `FittingRoomScrollPane` and `RankingEventScrollPane`;
- selected project convention: Y-first coordinate parameters, `m_highlightPart`, `m_activePart`, and the `ScrollPanePart` name; this repair models that name as a one-byte signed typedef rather than a four-byte C++ enum because the stored state and current function ABI are byte-sized.

No `sub_`, `dword_`, raw offset, or IDA temporary name is retained in recommended source. The selected names are descriptive, internally consistent with current project documentation, and more probable than leaving reverse-engineering labels.

References to obsolete Wave2/Wave3 workflow language were ignored; current skill and current evidence rules control this report.

## Heuristic / Inference Reanalysis And Validation

The six previous blockers were each actively resolved:

1. `sub_55D960`: exact loop over part IDs `0..4`, `GetScrollPartRect` calls, Y-first `PointInRect`, and `-1` miss sentinel resolve `HitTestPart`.
2. `sub_55DEA0`: exact old/new rectangle invalidation and `+0x103` store resolve `SetHighlightedPart`. `RankingEventScrollPane` independently uses this vocabulary, making it preferable to the FittingRoom-only `SetHotPart` spelling.
3. `sub_55DF10`: thumb-only highlight/drag-offset setup, active-part store, immediate processing, and 200-tick timer resolve `BeginPartPress` and Y-first parameter order.
4. `sub_55DFD0`: cursor localization, thumb drag dispatch, EPF/classic paths, active-part repeat behavior, page-size calls, clamping, and scroll-owner callback resolve `ProcessActivePart`.
5. `sub_55E210`: leading/trailing/thumb geometry, drag-offset arithmetic, EPF/classic vertical distinction, signed division, clamping, and owner callback resolve `UpdatePositionFromCursor`.
6. `sub_55E600`: timer removal, active-state clear, old-highlight invalidation, and highlight clear resolve `ResetScrollState`.

The source names are not claimed as recovered symbols. They are best-probability reconstructions supported by binary behavior and sibling source vocabulary. That uncertainty caps scores below 95 but does not justify leaving any helper unsplit or unnamed.

## Evidence Standards Used

- Current live IDA MCP facts outrank old reports and generated summaries.
- Current by-* documentation outranks generated output when stale generated text disagrees.
- Executed reports are leads until reconciled with current docs or live MCP.
- A claimed method signature must match call-site cleanup, receiver adjustment, argument use, and sibling ABI.
- A source name must describe the full body and fit accepted project vocabulary.
- Compiler artifacts are separated from source-authored methods even when physically adjacent.
- Scores above the 85/85 threshold require implementation-ready behavior and routing, while scores below 95 acknowledge remaining final-audit uncertainty.
- Missing original symbols are not a reason to preserve IDA names; realistic human names are inferred from context.

## Evidence Checked

### Positive checks

- Read current [UID:0003A5] `ScrollPaneInputGeometryHelpers`, [UID:0001GK] `ScrollPaneGetScrollPartRect`, [UID:0000CM] `ScrollPane`, [UID:0000NF] `ScrollBar`, [UID:0001GJ] `TextEditPaneScrollbarVariants`, [UID:000433] `ScrollPaneHandleMouseEvent`, [UID:000435] `ScrollPaneOnScrollTimer`, [UID:0001GI] `ScrollPaneOnDraw`, [UID:0001GL] `ScrollablePaneCore`, [UID:0003CQ] `ScrollPaneScrollbarConstantData`, and the relevant TimerHandler, EventHandler, Pane, and shared input/event documentation.
- Read the historical generated source-queue artifact command `000000018895` as preimplementation evidence and retained commands through `000000019259` only as dated checkpoints; then re-read current tracker command `000000019483`, refresh `2026-07-29T14:30:34-04:00` from `foreground-generated-refresh`, tracker SHA256 `A2C97D53EA038671299109D5455954FD909A2DFF0E6BCB9673E8CABD2518DC65`, 1,676,576 bytes/6,632 lines, with UID0003A5 still current `93/94`, average `93.5`, non-reconstructable, and zero direct/additional report counts. Generated CPP/H were independently re-read at the same current command `000000019483` identities.
- Read and compared the full sibling helper families: `FittingRoomScrollPaneHitTestPart`, `FittingRoomScrollPaneGetPartRect`, `FittingRoomScrollPaneSetHotPartRaw`, `FittingRoomScrollPaneBeginPartPressRaw`, `FittingRoomScrollPaneProcessActivePart`, `FittingRoomScrollPaneUpdateThumbDragScroll`, `FittingRoomScrollPaneResetScrollStateRaw`, `RankingEventScrollPaneHitTestPart`, `RankingEventScrollPaneSetHighlightedPartRaw`, `RankingEventScrollPaneBeginPartInteractionRaw`, `RankingEventScrollPaneUpdateActiveInteractionRaw`, `RankingEventScrollPaneDragToPosition`, and `RankingEventScrollPaneRawResetState`.
- Searched executed-report history by `0003A5`, `55d960`, `55e65c`, `ScrollPane`, `GetScrollPartRect`, and the six unsplit helper starts. Reconciled the matching B009 `0001GK-ScrollPaneGetScrollPartRect-empty-emitter-source-quality.md`, B004 `0001GH-ScrollPaneInputCore-source-quality.md`, B007 `0000NF-ScrollBar-empty-emitter-family-source-quality.md`, B012 `000435-ScrollPaneOnScrollTimer-source-quality.md`, B010 `0001GI-ScrollPaneOnDraw-source-quality.md`, B001 `0001GL-scrollablepane-core-source-split-audit.md`, and B004 `00042W-ScrollPaneRangeSetterRaw-empty-emitter-source-quality.md` as leads rather than authority.
- Used live read-only IDA MCP database `5a570ede` for the original bounded function lookup/profile, decompilation, disassembly, direct-xref, callee, byte, frame, all-four-comment-channel, exact type-name, and UDT research pass. The final pre-mutation pass against active database `1da2b2ae` read all seven raw function/range/size/prototype prestates, seven collision names, frames/locals, four comment channels, absent type names, and protected dependencies; it corrected F2's historical display to an unnamed `char` slot in `void __thiscall(int this, char, struct RectBounds *bounds)`.
- After supervisor Gate 2B, bounded read-only currentness checks against database `1da2b2ae` and current authoritative IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD` re-read all nine applied actions and protected dependencies. `server_health` returned `status:"ok"`; every required bounded query succeeded; all seven source-facing names/types/comments, normalized frames, exact caller counts, `ScrollPanePart`, and `ScrollPane` remained applied. Adjacent `sub_55C650` size `0x1307` and `sub_55E660` size `0x11e`, all 15 protected function/fence/NOP/table/padding hashes, and unrelated dependencies remained unchanged. No IDA drift, mutation, or save occurred during B005's check.
- Confirmed exact existing analysis types: `Pane` size `0xf8` with `_paneBase` `unsigned __int8[248]`, `Point` size `0x8` with `y/x` at `+0x0/+0x4`, `RectBounds` size `0x10` with `left/top/right/bottom` at `+0x0/+0x4/+0x8/+0xc`, and `ScrollablePane` size `0x10c`.
- Confirmed the generic methods use one `ScrollPane` tail layout through `+0x10f`, the Y-first event ABI, one direct class owner [UID:0000CM], and one source-file route through [UID:0000NF].

### Negative checks

- Historical pre-mutation exact type-name queries found no `ScrollPanePart`, `ScrollPanePartValue`, or `ScrollPane`; that absence established collision safety. Current post-Gate2B readback instead confirms the accepted one-byte `ScrollPanePart` typedef and exact `ScrollPane` UDT exist, while `ScrollPanePartValue` remains absent and no conflicting enum/type was introduced.
- Direct-xref and pointer checks found no independent owner for the jump table and no evidence that alignment bytes or the switch tail are handwritten source globals.
- Caller/receiver and sibling-family comparison found no support for TextEditPane, ScrollWidget, ScrollablePane, EventHandler, TimerHandler, or the constants page as the direct owner of any of the seven methods.
- Event offsets, `Point` layout, and both sibling families found no X-first ABI. The current X-first calls in UID000433 are stale documentation, not competing evidence.
- Bounded function lookup found no additional function start in `[0x0055d9d6,0x0055d9e0)`, `[0x0055de99,0x0055dea0)`, `[0x0055dfcf,0x0055dfd0)`, `[0x0055e1ed,0x0055e210)`, or `[0x0055e5f6,0x0055e600)`.
- Full decompilation found no denominator-zero guard in `UpdatePositionFromCursor`; adding one would change binary behavior.
- No original symbols, PDB names, or source paths were recovered. This is negative symbol evidence only; it does not justify preserving `sub_` names.

### Failed, unavailable, and intentionally skipped checks

- One initial broad `func_profile` batch used a non-bounded query shape and was discarded; all affected claims were rechecked with exact-address lookup/decompile/xref/comment/type requests. No conclusion relies on the discarded response.
- Original identifier spellings are unavailable in the stripped binary. Each applied source-facing name is therefore a documented best-probability human source name supported by behavior, call sites, field use, and two sibling families.
- No required MCP check failed after bounded retry. MCP health remained usable even though `auto_analysis_ready:false` can be reported independently of successful live IDB-backed queries.
- During initial research, IDA mutation, ordinary-document edits, B005-generated refresh, scoped validation, coverage editing, and report lifecycle execution were intentionally skipped. During the authorized callback, ordinary edits and serial scoped validations were completed. The supervisor separately completed IDA mutation/save/verification and cataloged it as entry `0359`; B005 performed only read-only poststate checks and ordinary/report reconciliation. Manual coverage edits, generated refresh/currentness closure, audit/catalog/lifecycle work, and execution/archive actions remain supervisor-owned, while current execution/archive state is authoritative only from the artifact's actual path plus validator-owned status/history metadata. Third-party import is not applicable to this project-authored ScrollPane method family.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | ---: | --- | --- | --- | --- |
| A5-001 | `0003A5` | The aggregate is a seven-method family plus compiler/alignment bytes, not one source function; convert it to the documented split index. | `99` | exact modeled ranges, bytes, xrefs, decompilation; command `000000018943` | target current state, range analysis, item summary, UID0001GJ corridor | incorporate | applied |
| A5-002 | `0003A5` | The split index is non-reconstructable/non-emitting at `93/94`, owner `0000CM`; clear its emitter and aggregate C++. | `96` | exact child partition, direct class route, and command `000000018943` | target metadata/formals/score | incorporate | applied |
| A5-003 | [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md) | `[0x55d960,0x55d9d6)` is `ScrollPane::HitTestPart(int localY,int localX)`; the exact `92/94` child was created and scoped validation assigned UID0004YF. | `94` | loop, geometry calls, Y-first point test, callers, siblings; validator command `000000018911` | UID0004YF formal CPP/evidence/metadata | incorporate | applied |
| A5-004 | `0001GK` | `[0x55d9e0,0x55de99)` is direct class-owned `GetScrollPartRect`, not nested under the aggregate; reroute owner/emitter to `0000CM` and set `92/94`. | `97` | existing exact body plus seven-helper caller family; command `000000018945` | UID0001GK metadata/evidence | incorporate | applied |
| A5-005 | [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md) | `[0x55dea0,0x55df10)` is `ScrollPane::SetHighlightedPart(ScrollPanePart)`; the exact `92/94` child was created and scoped validation assigned UID0004YI. | `94` | old/new invalidation, `+0x103` store, siblings; validator command `000000018914` | UID0004YI formal CPP/evidence/metadata | incorporate | applied |
| A5-006 | [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md) | `[0x55df10,0x55dfcf)` is Y-first `BeginPartPress`; the exact `92/94` child was created and scoped validation assigned UID0004YJ. | `95` | stack order, thumb offsets, immediate dispatch, timer 0/200, callers; validator command `000000018915` | UID0004YJ formal CPP/evidence/metadata | incorporate | applied |
| A5-007 | [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md) | `[0x55dfd0,0x55e1ed)` is `ProcessActivePart`; the exact `93/94` child was created and scoped validation assigned UID0004YL. | `96` | full branch/switch reconstruction, cursor localization, callers; validator command `000000018917` | UID0004YL formal CPP/evidence/metadata | incorporate | applied |
| A5-008 | [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md) | `[0x55e210,0x55e5f6)` is Y-first `UpdatePositionFromCursor`; the exact `93/94` child was created and scoped validation assigned UID0004YM. | `96` | exact EPF/classic formulas, clamp/divide/callback behavior; validator command `000000018921` | UID0004YM formal CPP/evidence/metadata | incorporate | applied |
| A5-009 | [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) | `[0x55e600,0x55e65c)` is `ResetScrollState`; the exact `92/94` child was created and scoped validation assigned UID0004YN. | `95` | timer removal, active/highlight stores, invalidation, callers; validator command `000000018932` | UID0004YN formal CPP/evidence/metadata | incorporate | applied |
| A5-010 | `000433` | Formal helper calls use Y-first argument order and metadata is `91/93`. | `98` | event offsets, Point layout, both sibling families; command `000000018964` | UID000433 formal CPP/evidence/manual row | incorporate | applied |
| A5-011 | `000435` | Timer callback dispatches the resolved `ProcessActivePart` and remains direct class-owned at `88/90`. | `97` | direct call at `0x55c628`, timer-id gate, existing body; command `000000018970` | UID000435 current evidence/manual row | incorporate | applied |
| A5-012 | `0000CM` | The bounded source-ready one-byte `ScrollPanePart` typedef/constants and class declaration expose accepted emitted members without a four-byte enum ABI; retain `87/88`. | `90` | exact byte fields, byte return/parameters, x86 stack-slot behavior, tail layout, seven-member family, and command `000000018960` | UID0000CM formal H/evidence/manual row | incorporate | applied |
| A5-013 | `0000NF` | Existing file ownership remains correct; reconcile only stale helper wording and preserve the newer current `91/90` score. | `93` | class/file routes, current file coverage, and command `000000018974` | UID0000NF evidence | incorporate | applied |
| A5-014 | `0000VN` | Six compiler-only ranges are represented exactly in `by-memory/-ignored.md`; the supervisor coverage payload remains pending: `[0x55d9d6,0x55d9e0)`, `[0x55de99,0x55dea0)`, `[0x55dfcf,0x55dfd0)`, `[0x55e1ed,0x55e210)`, `[0x55e5f6,0x55e600)`, and `[0x55e65c,0x55e660)`. | `99` | exact bytes, method boundaries, successor boundary, internal jump-table xref, and command `000000018983` | UID0003A5, [UID:0000VN] ordinary doc, exact supervisor coverage block | incorporate | applied |
| IDA-F1 | [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md) | Supervisor Gate 2B applied and verified the exact `ScrollPane__HitTestPart` name, prototype, function-repeatable comment, and normalized argument frame at `0x55d960`; B005 reconciled the live state into the exact child and aggregate/class support docs. | `94` | catalog `0359`; first save `08D31F...`; current `412DA7E8...` readback; exact body/fence hashes and four xrefs | UID0004YF IDA Analysis State; UID0003A5/UID0000CM support state; report applied-state tables | incorporate | applied |
| IDA-F2 | `0001GK` | Supervisor Gate 2B replaced the dated `void __thiscall(int this, char, struct RectBounds *bounds)` prestate with exact current `void __thiscall(ScrollPane *this, ScrollPanePart part, RectBounds *outRect)`, the applied name/comment, and normalized `part`/`bounds` frame. | `97` | catalog `0359`; current `412DA7E8...` function/type/frame/comment/xref readback; exact body/fence hashes | UID0001GK IDA Analysis State; aggregate/class support state; report applied-state tables | incorporate | applied |
| IDA-F3 | [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md) | Supervisor Gate 2B applied and verified `ScrollPane__SetHighlightedPart`, its exact typed prototype/comment, and one-byte `part` frame; B005 reconciled all ordinary current-state wording. | `94` | catalog `0359`; current `412DA7E8...` readback; exact body hash and single caller | UID0004YI IDA Analysis State; aggregate/class support state; report applied-state tables | incorporate | applied |
| IDA-F4 | [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md) | Supervisor Gate 2B applied and verified `ScrollPane__BeginPartPress`, exact typed Y-first prototype/comment, and normalized `part/localY/localX` frame. | `95` | catalog `0359`; current `412DA7E8...` readback; exact body/fence hashes and two callers | UID0004YJ IDA Analysis State; aggregate/class support state; report applied-state tables | incorporate | applied |
| IDA-F5 | [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md) | Supervisor Gate 2B applied and verified `ScrollPane__ProcessActivePart`, exact typed prototype/comment, and preserved compiler switch tail; timer/corridor references now use the applied name. | `96` | catalog `0359`; current `412DA7E8...` readback; body/NOP/table/padding hashes and two callers | UID0004YL IDA Analysis State; UID000435/UID0001GJ support state; report applied-state tables | incorporate | applied |
| IDA-F6 | [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md) | Supervisor Gate 2B applied and verified `ScrollPane__UpdatePositionFromCursor`, exact typed Y-first prototype/comment, and normalized `localY/localX` frame. | `96` | catalog `0359`; current `412DA7E8...` readback; exact body/fence hashes and two callers | UID0004YM IDA Analysis State; aggregate/class support state; report applied-state tables | incorporate | applied |
| IDA-F7 | [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) | Supervisor Gate 2B applied and verified `ScrollPane__ResetScrollState`, exact void prototype/comment, preserved frame, and successor fence. | `95` | catalog `0359`; current `412DA7E8...` readback; exact body/successor-fence hashes and two callers | UID0004YN IDA Analysis State; aggregate/class support state; report applied-state tables | incorporate | applied |
| IDA-T1 | `0000CM` | Supervisor Gate 2B created and verified one-byte typedef `ScrollPanePart` targeting signed-byte storage without a conflicting default-width enum; all part-bearing prototypes and both UDT fields use it. | `96` | catalog `0359`; current type size `1`; seven prototypes; normalized byte arguments; no `ScrollPanePartValue` | UID0000CM/children IDA Analysis State; report applied type table | incorporate | applied |
| IDA-T2 | `0000CM` | Supervisor Gate 2B created and verified exact-size `ScrollPane` analysis UDT: size `0x110`, 13 members, `Pane Pane_base` at `+0x0`, exact tail fields, and analysis pads at `+0xfd`/`+0x105`. | `96` | catalog `0359`; current `412DA7E8...` type readback; preserved Pane/Point/RectBounds/ScrollablePane dependencies | UID0000CM/aggregate/children IDA Analysis State; report applied type table | incorporate | applied |
| COV-1 | `0003A5`, `0004YF`, `0004YI`, `0004YJ`, `0004YL`, `0004YM`, and `0004YN` | Apply the literal existing-UID by-memory/class rows and the exact UID0000VN successor-fence row; all six complete child rows below carry their validator-assigned UID/link prefixes. | `99` | current by-memory coverage SHA `BB5E391E0198251142EC7BA4907D524E9ABCC80A5A2DFB0EBA53CE3F93802E20`: all 15 staged insert rows remain absent; stale UID0001GK remains at line 3199; UID0001GL remains the exact line-3200 successor anchor | supervisor coverage gate | incorporate | proposed |
| COV-GH | `0001GH` | Replace the stale manual by-memory row (`76%`, reconstructable mixed cluster) with the exact current `88%`, non-reconstructable, non-emitting ScrollPane/ScrollWidget split-index row while preserving its top-level location before nested UID000433/UID000435 and the `0x0055c643-0x0055c650` fence. | `100` | current ordinary UID0001GH metadata `88/90`, `RECONSTRUCTABLE:FALSE`, blank emitter/formals, `Nested:11`, exact Item Summary and split/no-code proof versus current manual line 3194 in SHA `BB5E391E0198251142EC7BA4907D524E9ABCC80A5A2DFB0EBA53CE3F93802E20` | exact supervisor-owned by-memory replacement row below | incorporate | proposed |
| COV-GI | `0001GI` | Replace the stale manual by-memory `78%` ScrollPaneOnDraw row with the exact current `88%` reconstructable method row immediately after the existing `0x0055c643-0x0055c650` fence and before `0x0055d957-0x0055d960`. | `100` | current ordinary UID0001GI metadata `88/90`, direct `0000CM` owner/emitter, exact formal CPP, Item Summary, vtable/resource/branch evidence and score rationale versus current manual line 3196 in SHA `BB5E391E0198251142EC7BA4907D524E9ABCC80A5A2DFB0EBA53CE3F93802E20` | exact supervisor-owned by-memory replacement row below | incorporate | proposed |
| COV-GJ | `0001GJ` | Replace the callback-touched stale manual by-memory row (`82%`, reconstructable, displayed end `0x00565488`) with the exact current `89%`, non-reconstructable, non-emitting mixed-owner corridor row through `0x005654ec`; retain its top-level location before UID0003A5 and the nested generic ScrollPane sequence. | `100` | current ordinary UID0001GJ metadata `89/91`, `RECONSTRUCTABLE:FALSE`, blank owner/emitter/formals, exact endpoint, Item Summary, 84-function/owner-split evidence and callback change record versus current manual line 3198 in SHA `BB5E391E0198251142EC7BA4907D524E9ABCC80A5A2DFB0EBA53CE3F93802E20` | exact supervisor-owned by-memory replacement row below | incorporate | proposed |
| GEN-1 | `0000NF` | Preserve commands through `000000019259` as history. Record current command `000000019483` and exact `ScrollBar.cpp`/`ScrollBar.h` identities, seven child-owned definitions, class-owned declarations/layout, and absence of a UID0003A5 aggregate definition/empty marker. Require a later readback only if generated artifacts advance before lifecycle closure. | `100` | command `000000019483` headers; CPP `F3A446D6...`; H `3D2057DC...`; exact definition/declaration topology | Current Target State; Validator Results; Changed Files; checklist | incorporate | applied |
| QUEUE-1 | `0003A5` | Preserve commands through `000000019259` as dated history; record current tracker command `000000019483`, exact physical identity, and UID0003A5 `93/94`, average `93.5`, reconstructable-false row. Require a later readback only if the tracker artifact advances. | `100` | command `000000019483` tracker header, SHA `A2C97D53...`, and exact UID0003A5 line-5544 row | Target; Current Target State; Evidence Checked; Validator Results; Changed Files; checklist | incorporate | applied |

## Positive Evidence Summary

- All seven function starts are modeled with stable half-open ranges and ordinary source-shaped bodies.
- Every unsplit helper has direct callers within the generic `ScrollPane` input/timer family.
- `GetScrollPartRect` is called by every geometry/state helper and by `OnDraw`, binding the family to one class layout.
- The accepted `ScrollPane` field table accounts for all accessed tail offsets through object size `0x110`.
- `FittingRoomScrollPane` independently reproduces the same seven-role helper sequence and Y-first ABI.
- `RankingEventScrollPane` independently supports `HitTestPart`, `SetHighlightedPart`, begin/update/drag/reset roles and the `m_highlightPart` vocabulary.
- UID000433 and UID000435 independently establish the input and timer entry points into the family.
- UID0001GL establishes the parent `ScrollablePane` page-size and apply-position contracts used by classic interaction and thumb dragging.
- Exact bytes separate ordinary methods from alignment and identify the `ProcessActivePart` switch jump table.
- There is no evidence for a TextEditPane, ScrollWidget, constants-data, or no-owner route.

## IDA MCP Facts

Applied/current function inventory:

| Range | Current IDA name | Size | Current decompiler prototype | Blocks / complexity |
| --- | --- | ---: | --- | ---: |
| `[0x0055d960,0x0055d9d6)` | `ScrollPane__HitTestPart` | `0x76` | `ScrollPanePart __thiscall(ScrollPane *this,int localY,int localX)` | `5 / 2` |
| `[0x0055d9e0,0x0055de99)` | `ScrollPane__GetScrollPartRect` | `0x4b9` | `void __thiscall(ScrollPane *this,ScrollPanePart part,RectBounds *outRect)` | `68 / 17` |
| `[0x0055dea0,0x0055df10)` | `ScrollPane__SetHighlightedPart` | `0x70` | `void __thiscall(ScrollPane *this,ScrollPanePart part)` | `7 / 4` |
| `[0x0055df10,0x0055dfcf)` | `ScrollPane__BeginPartPress` | `0xbf` | `void __thiscall(ScrollPane *this,ScrollPanePart part,int localY,int localX)` | `7 / 4` |
| `[0x0055dfd0,0x0055e1ed)` | `ScrollPane__ProcessActivePart` | `0x21d` | `void __thiscall(ScrollPane *this)` | `26 / 15` |
| `[0x0055e210,0x0055e5f6)` | `ScrollPane__UpdatePositionFromCursor` | `0x3e6` | `void __thiscall(ScrollPane *this,int localY,int localX)` | `48 / 26` |
| `[0x0055e600,0x0055e65c)` | `ScrollPane__ResetScrollState` | `0x5c` | `void __thiscall(ScrollPane *this)` | `3 / 2` |

Current comment disposition for each function is exact: address regular `""`, address repeatable `""`, and function regular `""`; the function-repeatable channel contains the exact accepted role comment listed in the applied-state table below. Historical pre-mutation comment channels were all blank.

Current IDA type state:

- `ScrollPanePart` exists as exact `typedef signed __int8 ScrollPanePart`, size `0x1`; `ScrollPanePartValue` remains absent and no conflicting default-width enum exists;
- `ScrollPane` exists as exact size `0x110`, 13-member analysis UDT with `Pane Pane_base` and the accepted tail members/pads;
- `Pane` remains exact size `0xf8` with one analysis member `_paneBase` at `+0x0`, type `unsigned __int8[248]`;
- `Point` exists at size `0x8` with `y` at `+0x0` and `x` at `+0x4`;
- `RectBounds` exists at size `0x10` with `left/top/right/bottom` at `+0x0/+0x4/+0x8/+0xc`;
- `ScrollablePane` exists at size `0x10c`, supporting the parent relationship but not replacing the missing `ScrollPane` type.

Key stack-frame observations:

- `0x0055d960` has one `RectBounds` local and two coordinate arguments currently labeled generically;
- `0x0055df10` consumes part, local Y, and local X and stores Y offset before X offset;
- `0x0055dfd0` and `0x0055e210` use `Point` locals for cursor/origin and position arithmetic;
- no stack-local mutation is required to establish the method contracts.

The coherent ABI decision is one-byte signed `ScrollPanePart` everywhere it is stored, returned, or passed. The current IDA prototypes infer `char` for the part-bearing functions, `stack_frame` reports the part-bearing argument itself as one byte where IDA has preserved that granularity, and the class fields at `+0x103/+0x104` are signed bytes. Disassembly confirms `HitTestPart` returns the selected byte in `al` (or sets `al` to `0xff`) and uses `retn 8`; every `GetScrollPartRect` exit uses `retn 8`; `SetHighlightedPart` uses `retn 4`; and `BeginPartPress` uses `retn 0Ch`. On 32-bit x86 `__thiscall`, each by-value argument still occupies a four-byte stack slot, so a `signed char` typedef preserves those cleanup amounts and stack positions while making the callee's low-byte access, AL return, signed `-1` sentinel, member fields, declarations, and definitions agree. A default four-byte C++ enum would not express that accepted analysis ABI; a C++11 fixed-underlying enum would be historically inappropriate for this mid-2000s source target.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x0055d960,0x0055e65c)` aggregate | [UID:0003A5] `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` | seven-method split index | `FALSE` | [UID:0000CM] | `93/94` | retain range as non-emitting index; no aggregate C++ |
| `[0x0055d960,0x0055d9d6)` | [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md) | Y-first five-part hit test | `TRUE` | [UID:0000CM] | `92/94` | created and validated by command `000000018911`; stable UID reconciled in report and staged coverage payload |
| `[0x0055d9d6,0x0055d9e0)` | [UID:0000VN] `by-memory/-ignored.md` | ten-byte `0xcc` alignment | ignored | [UID:0003A5] split index | `100/strong` | preserve as compiler alignment |
| `[0x0055d9e0,0x0055de99)` | [UID:0001GK] `by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md` | five-part geometry method | `TRUE` | [UID:0000CM] | `92/94` | retain exact child, direct class route, formal CPP |
| `[0x0055de99,0x0055dea0)` | [UID:0000VN] `by-memory/-ignored.md` | seven-byte `0xcc` alignment | ignored | [UID:0003A5] split index | `100/strong` | preserve as compiler alignment |
| `[0x0055dea0,0x0055df10)` | [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md) | highlighted-part transition | `TRUE` | [UID:0000CM] | `92/94` | created and validated by command `000000018914`; stable UID reconciled in report and staged coverage payload |
| `[0x0055df10,0x0055dfcf)` | [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md) | Y-first press initializer | `TRUE` | [UID:0000CM] | `92/94` | created and validated by command `000000018915`; stable UID reconciled in report and staged coverage payload |
| `[0x0055dfcf,0x0055dfd0)` | [UID:0000VN] `by-memory/-ignored.md` | one-byte `0xcc` alignment | ignored | [UID:0003A5] split index | `100/strong` | preserve as compiler alignment |
| `[0x0055dfd0,0x0055e1ed)` | [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md) | active-part dispatcher | `TRUE` | [UID:0000CM] | `93/94` | created and validated by command `000000018917`; stable UID reconciled in report and staged coverage payload |
| `[0x0055e1ed,0x0055e1f0)` | [UID:0000VN] `by-memory/-ignored.md` | three-byte NOP alignment | ignored | [UID:0004YL] | `100/strong` | preserve compiler tail; stable parent UID0004YL reconciled; not source code |
| `[0x0055e1f0,0x0055e204)` | [UID:0000VN] `by-memory/-ignored.md` | five-entry internal switch jump table | ignored | [UID:0004YL] | `100/very-strong` | compiler output of UID0004YL ProcessActivePart switch; no source global |
| `[0x0055e204,0x0055e210)` | [UID:0000VN] `by-memory/-ignored.md` | twelve-byte `0xcc` alignment | ignored | [UID:0004YL] | `100/strong` | preserve compiler tail; stable parent UID0004YL reconciled |
| `[0x0055e210,0x0055e5f6)` | [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md) | Y-first thumb drag-to-position method | `TRUE` | [UID:0000CM] | `93/94` | created and validated by command `000000018921`; stable UID reconciled in report and staged coverage payload |
| `[0x0055e5f6,0x0055e600)` | [UID:0000VN] `by-memory/-ignored.md` | ten-byte `0xcc` alignment | ignored | [UID:0003A5] split index | `100/strong` | preserve as compiler alignment |
| `[0x0055e600,0x0055e65c)` | [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) | interaction reset method | `TRUE` | [UID:0000CM] | `92/94` | created and validated by command `000000018932`; stable UID reconciled in report and staged coverage payload |
| `[0x0055e65c,0x0055e660)` | [UID:0000VN] `by-memory/-ignored.md` | four-byte `0xcc` successor fence outside UID0003A5 | ignored | following [UID:0001GL] corridor | `100/strong` | ordinary ignored entry applied; supervisor coverage row remains staged after ResetScrollState and before UID0001GL |

The six registered and validated child references are:

- [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md);
- [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md);
- [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md);
- [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md);
- [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md);
- [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md).

No UID was guessed. Implementation processed each child deterministically in report order: create the exact path, run its literal scoped validator command, read the validator-assigned first-line UID, and reconcile every report/manual-staging identity to that UID. Commands `000000018911`, `000000018914`, `000000018915`, `000000018917`, `000000018921`, and `000000018932` assigned UID0004YF, UID0004YI, UID0004YJ, UID0004YL, UID0004YM, and UID0004YN respectively. The additional-target provenance, Target inventory, ledger, Function / Child Inventory, checklist, and staged manual coverage rows now use those stable identities. The pre-Gate-2 self-audit confirms that every child identity is a literal assigned UID/path and that no provisional child-identity token remains.

## Direct Xref / Caller Inventory

| Callee | Direct call sites | Resolved caller role |
| --- | --- | --- |
| `0x0055d960` | `0x55c4c5`, `0x55c5b9`, `0x55e040`, `0x55e0ef` | UID000433 mouse handler and `ProcessActivePart` |
| `0x0055d9e0` | `0x55ce8f`, `0x55cf4c`, `0x55d664`, `0x55d77f`, `0x55d989`, `0x55decc`, `0x55dee8`, `0x55df41`, `0x55df59`, `0x55df78`, `0x55e06f`, `0x55e1c7`, `0x55e242`, `0x55e413`, `0x55e636` | OnDraw plus every geometry/state helper |
| `0x0055dea0` | `0x55e10a` | `ProcessActivePart` classic highlighted-part update |
| `0x0055df10` | `0x55c4e9`, `0x55c5d3` | UID000433 mouse-down paths |
| `0x0055dfd0` | `0x55c628`, `0x55dfa2` | UID000435 timer callback and `BeginPartPress` |
| `0x0055e210` | `0x55e055`, `0x55e0db` | `ProcessActivePart` thumb/EPF update paths |
| `0x0055e600` | `0x55c459`, `0x55c56d` | UID000433 reset paths |

The jump-table base at `0x0055e1f0` has an internal xref from `0x0055e12d`; its five entries target blocks within `ProcessActivePart`. It is not an independent data owner and not a source-authored global table.

## Documentation Evidence And IDA Status

Current docs already establish:

- [UID:0000CM] class ownership and tail-field offsets;
- [UID:0000NF] source placement in `NexusTK/ui/core/ScrollBar`;
- [UID:000433] mouse entry, [UID:000435] timer entry, and [UID:0001GI] draw consumption;
- [UID:0001GK] exact rectangle formulas and part values;
- [UID:0001GL] `GetPageSize(axis)` and `ApplyScrollPosition(axis,old,new)` owner contracts;
- [UID:0003CQ] scrollbar extent data ownership;
- sibling scrollbar family method sequence and source vocabulary.

At the historical report-only checkpoint, all seven functions still used `sub_` names and inaccurate inferred prototypes, while `ScrollPane` and `ScrollPanePart` were absent. Supervisor Gate 2B catalog entry `0359` later applied and independently verified all F1-F7/T1-T2 actions. Current live readback from session `1da2b2ae` against authoritative saved IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD` confirms the seven source-facing names/prototypes/comments, normalized frames, one-byte `ScrollPanePart`, exact `0x110` `ScrollPane` UDT, and all protected byte ranges remain applied with no target drift.

## Ranked Ownership Analysis

1. [UID:0000CM] `ScrollPane` - selected direct owner/emitter for all seven exact methods. Every method reads the same tail fields and is reached from ScrollPane draw/input/timer code.
2. [UID:0000NF] `ScrollBar` - selected source-file ancestor only. It groups the generic scrollbar classes but is too broad for direct method ownership.
3. [UID:0003A5] current aggregate - retained only as a non-emitting documentation split index. It should no longer own or emit exact children.
4. [UID:0001GJ] mixed scrollbar corridor - containing address map only; rejected as semantic owner because it crosses multiple classes and source families.
5. [UID:0000CF] `ScrollablePane` - dependency/parent consumer for page-size and apply-position calls; rejected as method owner because the bodies read `ScrollPane` fields.
6. [UID:0000EO] `TextEditPane` - rejected. It is a downstream consumer in the broad corridor, not the generic helper owner.
7. [UID:0000CP] `ScrollWidget` - rejected. It is adjacent but uses a different class layout and method family.
8. no-owner/non-emitting source - rejected for exact methods because all six have normal source bodies and proven class routes.

## Source Placement

Place the declarations and definitions in the existing generic scrollbar source family:

- header/declarations: `NexusTK/ui/core/ScrollBar.h`, emitted by [UID:0000CM]'s formal H block;
- implementations: `NexusTK/ui/core/ScrollBar.cpp`, emitted by the seven exact by-memory method pages through [UID:0000CM] and [UID:0000NF];
- split index: UID0003A5, documentation only, no emitted source body;
- compiler switch table: generated by the compiler from `ProcessActivePart`'s source switch, no handwritten C++ data declaration.

This placement matches the existing file owner and class family. It does not move methods into TextEditPane, a synthetic helper file, or a reverse-engineering-only source unit.

## Range / Split / Padding / Reclassification Analysis

The target range should remain as a documentation index because it is a useful contiguous family boundary. Its emitted role should change.

- Preserve target half-open range `[0x0055d960,0x0055e65c)`.
- Split all six formerly unsplit functions into exact method pages.
- Keep existing UID0001GK as the exact seventh method page.
- Reclassify UID0003A5 as `RECONSTRUCTABLE:FALSE` because it is an overlap/index, not a separate source construct.
- Clear aggregate owner-emitter child routing; exact pages route to the class.
- Keep target `Nested:8` as the existing family/index indentation.
- Set each new exact child `Nested:0`, matching the accepted UID0001GH split-index pattern.
- Change UID0001GK `Nested:-8` to `Nested:0`; its current negative delta is stale once all peers are represented.
- Keep following UID0001GL at its existing `Nested:0` unless validator readback proves a required relative-depth correction.

Compiler/alignment exclusions are exact:

- `0x0055d9d6-0x0055d9e0`: alignment;
- `0x0055de99-0x0055dea0`: alignment;
- `0x0055dfcf-0x0055dfd0`: alignment;
- `0x0055e1ed-0x0055e210`: compiler switch-table tail and alignment, not plain padding;
- `0x0055e5f6-0x0055e600`: alignment;
- `0x0055e65c-0x0055e660`: successor fence outside the target.

## Negative Evidence Summary

- No original symbols recover exact method or field spellings.
- No evidence supports preserving any `sub_55...` name in source.
- No evidence supports one aggregate handwritten function for the complete range.
- No evidence supports treating the jump table as a source global.
- No evidence supports an X-first coordinate ABI; accepted event layout and sibling methods prove Y-first.
- No evidence supports TextEditPane, ScrollWidget, ScrollablePane, TimerHandler, EventHandler, or the constants page as direct owner.
- No evidence supports explicit source padding members in the natural `ScrollPane` declaration; alignment follows ordinary MSVC layout.
- No denominator-zero branch exists in `UpdatePositionFromCursor`; adding one would change observed behavior.
- No final-audit score of 95 or higher is justified until the reconstructed project compiles and behavior/ABI readback is compared end to end.

## IDA Rename / Type / Comment Recommendations

These were supervisor-only Gate 2 actions. The supervisor applied and independently verified every accepted F1-F7/T1-T2 action under catalog entry `0359`; B005 did not mutate or save IDA. The tables retain literal pre-mutation evidence as dated history and record the exact applied/current readback.

### Applied function actions and current readback

Quoted empty strings are literal comment-channel values, not omitted checks. Current authoritative identity is database session `1da2b2ae`, IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`.

| Entity | Historical literal prestate | Supervisor-applied action | Exact current readback | Frame/xref/protected-state readback |
| --- | --- | --- | --- | --- |
| IDA-F1 `[0x0055d960,0x0055d9d6)` | `sub_55D960`; `char __thiscall(void *this, int, int)`; all four comment channels `""` | renamed; exact type and function-repeatable comment applied | `ScrollPane__HitTestPart`; `ScrollPanePart __thiscall(ScrollPane *this, int localY, int localX)`; function-repeatable comment exactly `ScrollPane part hit-test: scans part IDs 0..4, derives each rectangle through GetScrollPartRect, and returns the first containing part or -1; coordinates use the project Y-first ABI.`; address regular/repeatable and function regular `""` | frame storage unchanged, with physical `row +0x2c/0x4 int`, `column +0x30/0x4 int`; four xrefs `0x55c4c5,0x55c5b9,0x55e040,0x55e0ef`; body SHA `EE7D91AF331245B2D4CFEE4B8D9C3CC4B2F872449F25B54DC8CCE60533A22B19`; following fence SHA `22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045` |
| IDA-F2 `[0x0055d9e0,0x0055de99)` | `sub_55D9E0`; `void __thiscall(int this, char, struct RectBounds *bounds)` with unnamed second argument; all four comment channels `""` | renamed; exact receiver/argument/output type and function-repeatable comment applied | `ScrollPane__GetScrollPartRect`; `void __thiscall(ScrollPane *this, ScrollPanePart part, RectBounds *outRect)`; function-repeatable comment exactly `ScrollPane part geometry: writes first-button, page-before, thumb, page-after, or second-button bounds for EPF/classic and horizontal/vertical modes.`; other channels `""` | former `arg_0 +0x40/0x1 _BYTE` is `part +0x40/0x1 ScrollPanePart`; physical `bounds +0x44/0x4 struct RectBounds *` is preserved; 15 exact xrefs listed in the child page; body SHA `82876E86E92C3AFB000F4CDF89FAE0F102904F1577AAF4DCF3736F1A7B6C31B1`; leading/trailing fence SHAs `22E52B...`/`F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D` |
| IDA-F3 `[0x0055dea0,0x0055df10)` | `sub_55DEA0`; `char __thiscall(_BYTE *this, char)`; all four comment channels `""` | renamed; exact void type and function-repeatable comment applied | `ScrollPane__SetHighlightedPart`; `void __thiscall(ScrollPane *this, ScrollPanePart part)`; function-repeatable comment exactly `ScrollPane highlight transition: invalidates the old and new valid part rectangles and stores m_highlightPart.`; other channels `""` | former `arg_0 +0x24/0x4 _DWORD` is `part +0x24/0x1 ScrollPanePart`; one xref `0x55e10a`; body SHA `34CB482142E7F76B46699FF8B441B8F1350846E6D1F3A0ED0C9BC828AD08B129` |
| IDA-F4 `[0x0055df10,0x0055dfcf)` | `sub_55DF10`; `void __thiscall(Point *this, char, int, int)`; all four comment channels `""` | renamed; receiver/arguments and function-repeatable comment applied | `ScrollPane__BeginPartPress`; `void __thiscall(ScrollPane *this, ScrollPanePart part, int localY, int localX)`; function-repeatable comment exactly `ScrollPane press initializer: records thumb drag offset when needed, stores m_activePart, processes the part immediately, and starts timer 0 with a 200-tick delay.`; other channels `""` | arguments now `part +0x34/0x1 ScrollPanePart`, `localY +0x38/0x4 int`, `localX +0x3c/0x4 int`; two xrefs `0x55c4e9,0x55c5d3`; body/fence SHAs `3A0B9FED469313B457A94C65A397192BE7B6F0D0871257BE5E518A75034B3434`/`1DD8312636F6A0BF3D21FA2855E63072507453E93A5CED4301B364E91C9D87D6` |
| IDA-F5 `[0x0055dfd0,0x0055e1ed)` | `sub_55DFD0`; `void __thiscall(int this)`; all four comment channels `""` | renamed; exact receiver type and function-repeatable comment applied | `ScrollPane__ProcessActivePart`; `void __thiscall(ScrollPane *this)`; function-repeatable comment exactly `ScrollPane active-part dispatcher: localizes the cursor, handles thumb/EPF interaction, repeats classic line/page actions, clamps position, updates the owner, and maintains highlighted state.`; other channels `""` | eight frame entries remain exact; two xrefs `0x55c628,0x55dfa2`; body/NOP/table/padding SHAs `79D14C825FF126200FA85603EAC1617D91EC185C8A1E0CC77E574669DA682EB4`/`019F07BFE6BD5747F9F3B65F5A095DB04A0418D5F11C6FEEC58EAFF709860B66`/`E64FE65BCDE53CCDD9103C2AD8F53BC401B719DB3975419D8FE9B4461DC09F14`/`A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902` |
| IDA-F6 `[0x0055e210,0x0055e5f6)` | `sub_55E210`; `void __thiscall(int this, int, int)`; all four comment channels `""` | renamed; exact receiver/arguments and function-repeatable comment applied | `ScrollPane__UpdatePositionFromCursor`; `void __thiscall(ScrollPane *this, int localY, int localX)`; function-repeatable comment exactly `ScrollPane thumb-position update: converts local cursor and drag offset to a clamped scroll position using part rectangles, then applies a changed position through the owning ScrollablePane.`; other channels `""` | former `arg_0`/`arg_4` are `localY +0x5c/0x4 int` and `localX +0x60/0x4 int`; two xrefs `0x55e055,0x55e0db`; body/fence SHAs `DDEB358FEF0878DECBD4829196C069AFD010CA2E86ADF31B89332041CA546FAE`/`22E52BBA61DA8AD6732BE550205A10B89A1BB3B0EA491BE07DE9294F0EB6F045` |
| IDA-F7 `[0x0055e600,0x0055e65c)` | `sub_55E600`; `char __thiscall(_BYTE *this)`; all four comment channels `""` | renamed; exact void receiver type and function-repeatable comment applied | `ScrollPane__ResetScrollState`; `void __thiscall(ScrollPane *this)`; function-repeatable comment exactly `ScrollPane interaction reset: removes pending timers, clears m_activePart, invalidates the old highlighted part, and clears m_highlightPart.`; other channels `""` | four frame entries remain exact; two xrefs `0x55c459,0x55c56d`; body/successor-fence SHAs `F51C51A3027C4CDA94899385BCA2592510999620A442B21A26308AA0D2199092`/`8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`; successor `sub_55E660` remains size `0x11e` |

### Historical proposed-name collision and function/frame/local prestates

The original 2026-07-29 follow-up used read-only `lookup_funcs` and `stack_frame` against database session `5a570ede`. The final pre-mutation pass repeated every lookup against active database `1da2b2ae`: each proposed function name returned `fn:null`, `error:"Not found"`; all ranges, names, sizes, frames/locals, and comment channels matched; and F2 required the literal unnamed-`char` display correction below. These rows are retained as dated pre-mutation evidence, not current function state.

| Action | Exact historical collision result | Literal historical function prestate | Literal historical `stack_frame` variable/local prestate |
| --- | --- | --- | --- |
| IDA-F1 | query `ScrollPane__HitTestPart` -> `fn:null`, `error:"Not found"` | `[0x0055d960,0x0055d9d6)`, `sub_55D960`, size `0x76`, `char __thiscall(void *this, int, int)`, all four comment channels `""` | `var_18`: offset `0xc`, size `0x4`, `_DWORD`; `bounds`: `0x10`, `0x10`, `MapRect`; `var_4`: `0x20`, `0x4`, `_DWORD`; `__saved_registers`: `0x24`, `0x4`, `_DWORD`; `__return_address`: `0x28`, `0x4`, `_UNKNOWN *`; `row`: `0x2c`, `0x4`, `int`; `column`: `0x30`, `0x4`, `int` |
| IDA-F2 | active database `1da2b2ae` query `ScrollPane__GetScrollPartRect` -> `fn:null`, `error:"Not found"` | `[0x0055d9e0,0x0055de99)`, `sub_55D9E0`, size `0x4b9`, `void __thiscall(int this, char, struct RectBounds *bounds)` with unnamed second argument, all four comment channels `""` | `var_2C`: offset `0xc`, size `0x10`, `_OWORD`; `position`: `0x1c`, `0x10`, `Point[2]`; `offset`: `0x2c`, `0x8`, `Point`; `var_4`: `0x34`, `0x4`, `_DWORD`; `__saved_registers`: `0x38`, `0x4`, `_DWORD`; `__return_address`: `0x3c`, `0x4`, `_UNKNOWN *`; `arg_0`: `0x40`, size `0x1`, `_BYTE`; `bounds`: `0x44`, size `0x4`, `struct RectBounds *` |
| IDA-F3 | query `ScrollPane__SetHighlightedPart` -> `fn:null`, `error:"Not found"` | `[0x0055dea0,0x0055df10)`, `sub_55DEA0`, size `0x70`, `char __thiscall(_BYTE *this, char)`, all four comment channels `""` | `var_14`: offset `0x8`, size `0x10`, `int[4]`; `var_4`: `0x18`, `0x4`, `_DWORD`; `__saved_registers`: `0x1c`, `0x4`, `_DWORD`; `__return_address`: `0x20`, `0x4`, `_UNKNOWN *`; `arg_0`: `0x24`, `0x4`, `_DWORD` |
| IDA-F4 | query `ScrollPane__BeginPartPress` -> `fn:null`, `error:"Not found"` | `[0x0055df10,0x0055dfcf)`, `sub_55DF10`, size `0xbf`, `void __thiscall(Point *this, char, int, int)`, all four comment channels `""` | `var_24`: offset `0x8`, size `0x4`, `_DWORD`; `var_20`: `0xc`, `0x4`, `_DWORD`; `var_14`: `0x18`, `0x10`, `int[4]`; `var_4`: `0x28`, `0x4`, `_DWORD`; `__saved_registers`: `0x2c`, `0x4`, `_DWORD`; `__return_address`: `0x30`, `0x4`, `_UNKNOWN *`; `arg_0`: `0x34`, `0x1`, `_BYTE`; `arg_4`: `0x38`, `0x4`, `_DWORD`; `arg_8`: `0x3c`, `0x4`, `_DWORD` |
| IDA-F5 | query `ScrollPane__ProcessActivePart` -> `fn:null`, `error:"Not found"` | `[0x0055dfd0,0x0055e1ed)`, `sub_55DFD0`, size `0x21d`, `void __thiscall(int this)`, all four comment channels `""` | `var_28`: offset `0x4`, size `0x4`, `_DWORD`; `var_24`: `0x8`, `0x1`, `_BYTE`; `offset`: `0x10`, `0x8`, `Point`; `var_14`: `0x18`, `0x1`, `_BYTE`; `position`: `0x20`, `0x8`, `Point`; `var_4`: `0x28`, `0x4`, `_DWORD`; `__saved_registers`: `0x2c`, `0x4`, `_DWORD`; `__return_address`: `0x30`, `0x4`, `_UNKNOWN *` |
| IDA-F6 | query `ScrollPane__UpdatePositionFromCursor` -> `fn:null`, `error:"Not found"` | `[0x0055e210,0x0055e5f6)`, `sub_55E210`, size `0x3e6`, `void __thiscall(int this, int, int)`, all four comment channels `""` | `offset`: offset `0xc`, size `0x8`, `Point`; `position`: `0x14`, `0x8`, `Point`; `oldPosition`: `0x1c`, `0x4`, `unsigned __int16[2]`; `var_34`: `0x20`, `0x4`, `_DWORD`; `var_30`: `0x24`, `0x4`, `_DWORD`; `var_2C`: `0x28`, `0x4`, `_DWORD`; `var_28`: `0x2c`, `0x4`, `_DWORD`; `var_24`: `0x30`, `0x10`, `_OWORD`; `var_14`: `0x40`, `0x10`, `_OWORD`; `var_4`: `0x50`, `0x4`, `_DWORD`; `__saved_registers`: `0x54`, `0x4`, `_DWORD`; `__return_address`: `0x58`, `0x4`, `_UNKNOWN *`; `arg_0`: `0x5c`, `0x4`, `_DWORD`; `arg_4`: `0x60`, `0x4`, `_DWORD` |
| IDA-F7 | query `ScrollPane__ResetScrollState` -> `fn:null`, `error:"Not found"` | `[0x0055e600,0x0055e65c)`, `sub_55E600`, size `0x5c`, `char __thiscall(_BYTE *this)`, all four comment channels `""` | `var_14`: offset `0x4`, size `0x10`, `int[4]`; `var_4`: `0x14`, `0x4`, `_DWORD`; `__saved_registers`: `0x18`, `0x4`, `_DWORD`; `__return_address`: `0x1c`, `0x4`, `_UNKNOWN *` |

### Applied type actions with literal historical prestates

| Entity | Literal historical prestate | Supervisor-applied action | Exact current readback | Protected dependencies |
| --- | --- | --- | --- | --- |
| `ScrollPanePart` | exact query absent; no enum/typedef/declaration/member list/value/comment/alias; `ScrollPanePartValue` also absent | declared `typedef signed __int8 ScrollPanePart;`; no default-width enum created | exact typedef `ScrollPanePart`, target `signed __int8`, size `0x1`; all part-bearing function types and both UDT fields resolve through it; `ScrollPanePartValue` remains absent | accepted source constants remain `-1,0,1,2,3,4`; no unrelated type changed |
| `ScrollPane` | exact query absent; `Pane` existed at size `0xf8` with `_paneBase`; `Point` size `0x8`; `ScrollablePane` separate at `0x10c` | declared the exact analysis UDT below after IDA-T1; did not alter dependencies | exact name `ScrollPane`, size `0x110`, 13 members; `Pane Pane_base` at `+0x0`; exact tail fields/pads through `+0x10f` | `Pane` size `0xf8`, `Point` size `0x8`, `RectBounds` size `0x10`, and `ScrollablePane` size `0x10c` remain exact |

Exact applied/current `ScrollPane` tail layout:

| Offset | Exact IDA member/type | Source disposition |
| ---: | --- | --- |
| `+0x000` | `Pane Pane_base` (size `0xf8`) | exact implementable analysis representation of the existing source base; live `Pane` is size `0xf8` with `_paneBase` byte array |
| `+0x0f8` | `unsigned __int16 m_scrollSkinIndex` | source member |
| `+0x0fa` | `unsigned __int8 m_scrollStyle` | source member; no callable helper is invented for the unrelated no-route raw setter |
| `+0x0fb` | `bool m_thumbDragActive` | source member |
| `+0x0fc` | `unsigned __int8 m_orientation` | source member |
| `+0x0fd` | `unsigned __int8 _analysisPadFD` | compiler layout only; omit from source |
| `+0x0fe` | `__int16 m_scrollPosition` | source member |
| `+0x100` | `__int16 m_scrollRange` | source member |
| `+0x102` | `bool m_enabled` | source member |
| `+0x103` | `ScrollPanePart m_highlightPart` | source member; typedef resolves to signed byte |
| `+0x104` | `ScrollPanePart m_activePart` | source member; typedef resolves to signed byte |
| `+0x105` | `unsigned __int8 _analysisPad105[3]` | compiler layout only; omit from source |
| `+0x108` | `Point m_thumbDragOffset` | source member; existing `Point` remains size `0x8`, `y/x` at `+0/+4` |

The exact applied IDA-T2 declaration is:

```cpp
struct ScrollPane
{
    Pane Pane_base;
    unsigned __int16 m_scrollSkinIndex;
    unsigned __int8 m_scrollStyle;
    bool m_thumbDragActive;
    unsigned __int8 m_orientation;
    unsigned __int8 _analysisPadFD;
    __int16 m_scrollPosition;
    __int16 m_scrollRange;
    bool m_enabled;
    ScrollPanePart m_highlightPart;
    ScrollPanePart m_activePart;
    unsigned __int8 _analysisPad105[3];
    Point m_thumbDragOffset;
};
```

This declaration is an analysis UDT, not the source declaration: `Pane Pane_base` is the exact IDA representation of source inheritance, and the two named pad members exist only to make offsets deterministic in IDA. The formal source H block below continues to use `class ScrollPane : public Pane` and natural compiler padding.

Supervisor Gate 2B captured the collision/function/type/frame/comment prestates, applied only the accepted actions, independently verified the poststate, and saved it under catalog entry `0359`. The protected pre-mutation backup is `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B005-UID0003A5-20260729-124819.i64`, SHA256 `E9600F6C16B46FE1F5A7FEE463EF7890E415905CE465F8F6C55954FF5AA91611`, 143,190,173 bytes. The first verified save was SHA256 `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`, 143,190,452 bytes, at `2026-07-29T12:53:48.4762005-04:00`; `03F102...`, `0E0AF9...`, `3C8F31...`, `296ED2...`, and `905D1A...` are later historical shared saves. Bounded read-only recheck against current authoritative SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD` found no target/dependency drift: jump-table data `[0x0055e1f0,0x0055e204)`, all six fences, adjacent methods, unrelated analysis state, exact callers/callees, frames, locals, and bytes remain protected.

## First-Draft C++ Recommendation

All first-draft/example C++ belongs in formal C++ or H blocks during implementation. The following is destination-ready source text, not pseudocode.

### UID0000CM formal H block

```cpp
struct PaneMouseEvent;

typedef signed char ScrollPanePart;

static const ScrollPanePart kScrollPanePartNone = -1;
static const ScrollPanePart kScrollPanePartFirstButton = 0;
static const ScrollPanePart kScrollPanePartPageBeforeThumb = 1;
static const ScrollPanePart kScrollPanePartThumb = 2;
static const ScrollPanePart kScrollPanePartPageAfterThumb = 3;
static const ScrollPanePart kScrollPanePartSecondButton = 4;

class ScrollPane : public Pane
{
public:
    explicit ScrollPane(bool horizontal);
    void SetSkinIndex(unsigned short skinIndex);
    bool IsScrollThumbVisible();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool CanScroll(int value);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnDraw();

private:
    ScrollPanePart HitTestPart(int localY, int localX);
    void GetScrollPartRect(ScrollPanePart part, RectBounds *outRect);
    void SetHighlightedPart(ScrollPanePart part);
    void BeginPartPress(ScrollPanePart part, int localY, int localX);
    void ProcessActivePart();
    void UpdatePositionFromCursor(int localY, int localX);
    void ResetScrollState();

    unsigned short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    ScrollPanePart m_highlightPart;
    ScrollPanePart m_activePart;
    Point m_thumbDragOffset;
};

[[CHILDREN]]
```

`ScrollPanePart` is intentionally a one-byte signed typedef with typed integral constants. This is valid mid-2000s C++, keeps the `-1` sentinel and values `0..4`, makes declarations/definitions/member fields and IDA types identical, preserves the observed byte return and low-byte parameter accesses, and avoids both a default four-byte enum and a historically inappropriate C++11 fixed-underlying enum. Ordinary 32-bit `__thiscall` still reserves four-byte stack slots for by-value arguments, so the stack cleanup and call-site layout are unchanged.

No handwritten source-level size-check typedef/assert is recommended. The exact `0x110` layout remains mandatory documentation and IDA analysis evidence, but no original-source or independent project evidence shows that the developers wrote such a compile-time assertion.

### ScrollPaneHitTestPart formal CPP block

```cpp
ScrollPanePart ScrollPane::HitTestPart(int localY, int localX)
{
    for (int value = kScrollPanePartFirstButton;
         value <= kScrollPanePartSecondButton;
         ++value) {
        RectBounds bounds;
        const ScrollPanePart part = static_cast<ScrollPanePart>(value);
        GetScrollPartRect(part, &bounds);
        if (PointInRect(localY, localX, &bounds)) {
            return part;
        }
    }

    return kScrollPanePartNone;
}
```

### ScrollPaneSetHighlightedPart formal CPP block

```cpp
void ScrollPane::SetHighlightedPart(ScrollPanePart part)
{
    if (part == m_highlightPart) {
        return;
    }

    RectBounds bounds;
    if (m_highlightPart != kScrollPanePartNone) {
        GetScrollPartRect(m_highlightPart, &bounds);
        InvalidateRect(&bounds);
    }
    if (part != kScrollPanePartNone) {
        GetScrollPartRect(part, &bounds);
        InvalidateRect(&bounds);
    }

    m_highlightPart = part;
}
```

### ScrollPaneBeginPartPress formal CPP block

```cpp
void ScrollPane::BeginPartPress(
    ScrollPanePart part,
    int localY,
    int localX)
{
    if (part == kScrollPanePartThumb) {
        RectBounds thumbBounds;
        SetHighlightedPart(kScrollPanePartThumb);
        GetScrollPartRect(kScrollPanePartThumb, &thumbBounds);
        m_thumbDragOffset.y = localY - thumbBounds.top;
        m_thumbDragOffset.x = localX - thumbBounds.left;
    }

    m_activePart = part;
    ProcessActivePart();
    ScheduleTimer(0, 200, 0, 0);
}
```

### ScrollPaneProcessActivePart formal CPP block

```cpp
void ScrollPane::ProcessActivePart()
{
    Point cursor;
    Point origin;
    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    const int localY = cursor.y - origin.y;
    const int localX = cursor.x - origin.x;

    if (m_activePart == kScrollPanePartThumb) {
        UpdatePositionFromCursor(localY, localX);
        return;
    }

    const ScrollPanePart part = HitTestPart(localY, localX);
    if (g_useEpfAssets) {
        if (part == m_activePart) {
            UpdatePositionFromCursor(localY, localX);
        }
        SetHighlightedPart(kScrollPanePartNone);
        return;
    }

    if (part != m_activePart) {
        SetHighlightedPart(kScrollPanePartNone);
        return;
    }

    SetHighlightedPart(part);

    ScrollablePane *owner = static_cast<ScrollablePane *>(GetParentPane());
    const short oldPosition = m_scrollPosition;
    int newPosition = oldPosition;
    switch (m_activePart) {
    case kScrollPanePartFirstButton:
        --newPosition;
        break;
    case kScrollPanePartPageBeforeThumb:
        newPosition -= owner->GetPageSize(m_orientation);
        break;
    case kScrollPanePartPageAfterThumb:
        newPosition += owner->GetPageSize(m_orientation);
        break;
    case kScrollPanePartSecondButton:
        ++newPosition;
        break;
    default:
        return;
    }

    if (newPosition < 0) {
        newPosition = 0;
    } else if (newPosition > m_scrollRange) {
        newPosition = m_scrollRange;
    }

    if (newPosition != oldPosition) {
        owner->ApplyScrollPosition(
            m_orientation,
            oldPosition,
            static_cast<short>(newPosition));
    }
}
```

### ScrollPaneUpdatePositionFromCursor formal CPP block

```cpp
void ScrollPane::UpdatePositionFromCursor(int localY, int localX)
{
    RectBounds firstButton;
    RectBounds secondButton;
    RectBounds thumb;
    GetScrollPartRect(kScrollPanePartFirstButton, &firstButton);
    GetScrollPartRect(kScrollPanePartSecondButton, &secondButton);
    GetScrollPartRect(kScrollPanePartThumb, &thumb);

    int thumbStart;
    int lowerBound;
    int upperBound;
    if (m_orientation != 0) {
        thumbStart = localX - m_thumbDragOffset.x;
        if (g_useEpfAssets) {
            ++thumbStart;
        }
        lowerBound = firstButton.right;
        upperBound = secondButton.left + thumb.left - thumb.right;
    } else {
        thumbStart = localY - m_thumbDragOffset.y;
        if (g_useEpfAssets) {
            ++thumbStart;
        }
        lowerBound = firstButton.bottom;
        upperBound = secondButton.top + thumb.top - thumb.bottom;
    }

    if (thumbStart < lowerBound) {
        thumbStart = lowerBound;
    } else if (thumbStart > upperBound) {
        thumbStart = upperBound;
    }

    int newPosition;
    if (m_orientation == 0 && g_useEpfAssets) {
        newPosition =
            ((m_scrollRange + 1) * (thumbStart - lowerBound)) /
            (upperBound - lowerBound);
        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    } else {
        newPosition =
            (m_scrollRange * (thumbStart - lowerBound)) /
            (upperBound - lowerBound);
    }

    const short oldPosition = m_scrollPosition;
    if (newPosition != oldPosition) {
        ScrollablePane *owner =
            static_cast<ScrollablePane *>(GetParentPane());
        owner->ApplyScrollPosition(
            m_orientation,
            oldPosition,
            static_cast<short>(newPosition));
    }
}
```

The lack of a zero-denominator guard is deliberate because no such branch exists in the binary. Signed integer division and truncation must be preserved.

### ScrollPaneResetScrollState formal CPP block

```cpp
void ScrollPane::ResetScrollState()
{
    RemovePendingTimers();
    m_activePart = kScrollPanePartNone;

    if (m_highlightPart != kScrollPanePartNone) {
        RectBounds bounds;
        GetScrollPartRect(m_highlightPart, &bounds);
        InvalidateRect(&bounds);
        m_highlightPart = kScrollPanePartNone;
    }
}
```

## Final Recommendation

The supervisor accepted historical pre-callback Gate 1 SHA256 `0EF25C93292AA70A8514AC7EFA8EADC67FAEFD8AD57C35489F4F66AF07329214`, B005 completed the authorized ordinary-document implementation callback, and supervisor Gate 2B applied/verified all F1-F7/T1-T2 actions under catalog entry `0359`. B005 reconciled that saved state into every affected ordinary destination and the same report, then serially revalidated all changed ordinary pages. All six formerly unsplit helper blockers are resolved and implemented; none is deferred. Because this post-Gate2B reconciliation changes the report artifact, the exact current artifact requires fresh Gate 1 and claim-by-claim Gate 2A review before supervisor-owned coverage/generated/catalog/lifecycle closure.

- [UID:0003A5] `[0x0055d960,0x0055e65c)` is now a `93/94`, owner-`0000CM`, non-reconstructable, non-emitting split index with blank formal CPP/H.
- Created [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md), validator-assigned UID0004YF, `92/94`, reconstructable, direct owner/emitter `0000CM`, `Nested:0`, destination-ready HitTestPart CPP, blank H.
- [UID:0001GK] is now the seventh directly class-owned method at `92/94`, owner/emitter `0000CM`, `Nested:0`, with preserved formal CPP/blank H.
- Created [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md), validator-assigned UID0004YI, `92/94`, reconstructable, direct owner/emitter `0000CM`, `Nested:0`, destination-ready SetHighlightedPart CPP, blank H.
- Created [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md), validator-assigned UID0004YJ, `92/94`, reconstructable, direct owner/emitter `0000CM`, `Nested:0`, destination-ready BeginPartPress CPP, blank H.
- Created [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md), validator-assigned UID0004YL, `93/94`, reconstructable, direct owner/emitter `0000CM`, `Nested:0`, destination-ready ProcessActivePart CPP, blank H.
- Created [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md), validator-assigned UID0004YM, `93/94`, reconstructable, direct owner/emitter `0000CM`, `Nested:0`, destination-ready UpdatePositionFromCursor CPP, blank H.
- Created [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md), validator-assigned UID0004YN, `92/94`, reconstructable, direct owner/emitter `0000CM`, `Nested:0`, destination-ready ResetScrollState CPP, blank H.
- All seven methods route through [UID:0000CM] `ScrollPane`, then through [UID:0000NF] `ScrollBar`; none routes through UID0003A5, TextEditPane, ScrollWidget, ScrollablePane, TimerHandler, EventHandler, or the constants page.
- UID0000CM formal H now contains the bounded source-ready one-byte `ScrollPanePart` typedef/typed constants and `ScrollPane` declaration without a handwritten size assertion; UID0000CM remains `87/88`, and UID0000NF preserves its newer current `91/90` score.
- [UID:000433] now uses Y-first calls at `91/93`; [UID:000435] now names the resolved [UID:0004YL] dependency while remaining `88/90`.
- [UID:0000VN] now preserves compiler exclusions exactly: `[0x55d9d6,0x55d9e0)`, `[0x55de99,0x55dea0)`, `[0x55dfcf,0x55dfd0)`, `[0x55e1ed,0x55e210)` including the internal switch table, `[0x55e5f6,0x55e600)`, and the outside-target fence `[0x55e65c,0x55e660)`. None belongs in handwritten C++.
- The manual supervisor-owned handoff now contains `20` exact applicable row changes: the preserved `17` rows plus evidence-backed replacements for UID0001GH, UID0001GI, and UID0001GJ. UID0000NF remains one exact no-op. No stale named anchor row is left without an atomic operation or disposition.

The seven method bodies are branch-complete first drafts for their formal CPP destinations under the now-coherent one-byte `ScrollPanePart` contract, and the bounded class declaration belongs in formal H. They are implementation-ready research artifacts, not a claim that final behavior equivalence has already been compiled and measured. Remaining uncertainty is exact historical spelling and final compile/ABI/behavior equivalence, not missing helper or type-contract investigation; those uncertainties cap scores below 95 but do not justify compiler labels, blank method emitters, or an aggregate source function.

## Recommended Target Doc Changes

Applied to [UID:0003A5]:

- changed `COMPLETION:87` to `93`;
- changed `CONFIDENCE:89` to `94`;
- keep `CANONICAL_OWNER:0000CM`;
- changed `RECONSTRUCTABLE:TRUE` to `FALSE`;
- cleared `EMITTER_UIDS`;
- keep blank position and `Nested:8`;
- removed the aggregate route comment and `[[CHILDREN]]` from formal CPP so CPP/H are blank;
- replaced the item summary with a complete seven-child split-index summary;
- replaced provisional helper descriptions with exact names/signatures/behavior;
- documented all function, alignment, NOP, jump-table, and successor boundaries;
- historicalized the prior branch-level/name/signature blockers as resolved by this B005 pass;
- added current MCP facts, exact callers, field/type evidence, sibling-family comparison, source placement, score rationale, and changes entry;
- retained the six reconciled validator-assigned child identities declared in `TARGET-REPORT-ADDITIONAL-UIDS`, with UID0001GK as the exact seventh child.

## Recommended Support Doc Changes

1. The six exact method pages identified by stable UIDs in `Function / Child Inventory` were created from the complete destination-ready payloads below with direct owner/emitter `0000CM`, reconstructable true, blank position, `Nested:0`, exact behavior/evidence/history, destination-ready CPP, and blank H. All six are declared as additional report UIDs before Gate 2.

### Complete destination-ready child-page payloads

The following six payloads were the complete ordinary-document instructions used during the authorized callback. The validator assigned each first-line UID during serial registration; every labeled evidence paragraph, formal CPP block, blank H disposition, score, route, and historical assumption was incorporated without supervisor synthesis.

#### [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md) destination payload

- **Exact metadata and Item Summary:**

```markdown
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Item Summary: Source-ready generic ScrollPane five-part hit-test method; scans part values 0 through 4 in order, obtains each part rectangle through GetScrollPartRect, applies the confirmed Y-first local coordinate contract to PointInRect, returns the first containing one-byte ScrollPanePart or kScrollPanePartNone, and preserves exact callers, range, ABI, ownership, source-placement, and alignment evidence. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- **Range and boundaries:** the handwritten body is exactly `[0x0055d960,0x0055d9d6)`, size `0x76`. Its next bytes `[0x0055d9d6,0x0055d9e0)` are ten `0xcc` alignment bytes owned by [UID:0000VN], not part of this method. The next modeled source method starts at `0x0055d9e0` as [UID:0001GK] `GetScrollPartRect`.
- **Behavior and data flow:** initialize the candidate part to `kScrollPanePartFirstButton`; for each signed one-byte part value `0..4`, call `GetScrollPartRect(part,&bounds)` and test `PointInRect(localY,localX,&bounds)`. Return the first matching part; after all five fail, return `kScrollPanePartNone` (`-1`/`0xff` in `AL`). The accepted source signature is `ScrollPanePart ScrollPane::HitTestPart(int localY, int localX)`; Y precedes X by contract.
- **Caller/callee/xref evidence:** direct code callers are `0x0055c4c5` and `0x0055c5b9` in [UID:000433] `ScrollPaneHandleMouseEvent`, plus `0x0055e040` and `0x0055e0ef` in applied [UID:0004YL] `ScrollPane__ProcessActivePart`. The body directly depends on [UID:0001GK] `ScrollPane__GetScrollPartRect` and the established point-in-rectangle helper. No data, vtable, or unrelated external owner route supersedes those four code xrefs.
- **Ownership, emitter, and source placement:** all callers pass the primary `ScrollPane` object, the geometry callee uses the same accepted `ScrollPane` tail fields, and both sibling scrollbar families expose the same role. Direct canonical owner and emitter are [UID:0000CM] `ScrollPane`; the containing aggregate [UID:0003A5] becomes a non-emitting split index. Place the definition in [UID:0000NF] `NexusTK/ui/core/ScrollBar.cpp` and the declaration in [UID:0000CM]'s formal H block.
- **Positive evidence:** exact modeled function/range, stable decompilation and disassembly, four direct callers, five-iteration loop, one-byte signed return sentinel, exact Y-first call order, sibling `FittingRoomScrollPane`/`RankingEventScrollPane` role agreement, and clean method/alignment fence all support the selected reconstruction.
- **Negative evidence:** no original symbol survives; no evidence supports an X-first contract, `ScrollWidget`/`TextEditPane` owner, separate source file, default-width four-byte enum return, aggregate emitter, or inclusion of the following `0xcc` bytes. Those alternatives are rejected rather than left open.
- **Score/confidence rationale:** `92/94` is justified because range, behavior, ABI, callers, owner, emitter, and source route are exact or strongly cross-confirmed. Completion stays below final-audit level because the historical identifier spelling and final compiled equivalence are inferred rather than symbol-proven.
- **Formal C++/H disposition:** copy verbatim the complete code block under the exact heading `### ScrollPaneHitTestPart formal CPP block` into this child's formal CPP header. Keep this child formal H header empty; the exact declaration and one-byte `ScrollPanePart` contract belong to [UID:0000CM]. Do not leave example C++ in prose only.
- **Historical/corrected assumptions:** historical raw name `sub_55D960`, an unresolved helper classification, an X-first parameter interpretation, and a wider enum ABI are superseded. Preserve them in a historical/corrected-assumptions section with the four-caller, AL-return, stack-cleanup, and sibling-family evidence that rejected them.

#### [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md) destination payload

- **Exact metadata and Item Summary:**

```markdown
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Item Summary: Source-ready generic ScrollPane highlighted-part transition method; avoids redundant work, invalidates the old and new valid part rectangles through GetScrollPartRect, stores the accepted one-byte m_highlightPart state, and preserves exact caller, range, ownership, source-placement, ABI, and sibling-naming evidence. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- **Range and boundaries:** the method is exactly `[0x0055dea0,0x0055df10)`, size `0x70`. It follows the seven-byte [UID:0000VN] alignment `[0x0055de99,0x0055dea0)` and ends exactly where `BeginPartPress` begins; there is no intervening padding or merged tail.
- **Behavior and data flow:** return immediately when the requested part equals `m_highlightPart`. If the old part is not `kScrollPanePartNone`, obtain its bounds with `GetScrollPartRect` and invalidate that rectangle. Store the new signed one-byte part at `+0x103`; if it is valid, obtain and invalidate the new rectangle. The accepted signature is `void ScrollPane::SetHighlightedPart(ScrollPanePart part)`.
- **Caller/callee/xref evidence:** the sole direct code caller is `0x0055e10a` in applied [UID:0004YL] `ScrollPane__ProcessActivePart`. The body calls [UID:0001GK] `ScrollPane__GetScrollPartRect` for old/new states and the accepted pane invalidation method for redraw. The one-caller result is coherent with a private state-transition helper; no data/vtable xref or alternate owner route was found.
- **Ownership, emitter, and source placement:** the `+0x103` field is the accepted `ScrollPane::m_highlightPart`, both callees operate on the same primary object, and RankingEvent/FittingRoom siblings provide the highlighted/hot-part role. Direct owner/emitter are [UID:0000CM]; source definition belongs in [UID:0000NF] `NexusTK/ui/core/ScrollBar.cpp`, declaration in UID0000CM H, never in aggregate UID0003A5 C++.
- **Positive evidence:** exact range/body, same-value early return, old/new rectangle invalidation, literal byte store, one direct process-helper caller, sibling role agreement, and immediate next-function boundary support the method contract and selected name.
- **Negative evidence:** no surviving original symbol distinguishes `SetHighlightedPart` from historical `SetHotPart`; project-local `m_highlightPart` vocabulary and behavior favor the selected spelling. No evidence supports a non-void return, wider part field, UI subclass owner, or combined Set/Begin method.
- **Score/confidence rationale:** `92/94` reflects exact state transition, field, caller, callees, ABI, route, and range, with only original lexical spelling/final compilation unproven.
- **Formal C++/H disposition:** copy verbatim the complete code block under `### ScrollPaneSetHighlightedPart formal CPP block` into this child's formal CPP header. Leave child H blank; UID0000CM owns the declaration and one-byte part type.
- **Historical/corrected assumptions:** preserve and mark corrected the raw `sub_55DEA0` name, stale `char` return, possible `SetHotPart` spelling, and unresolved-owner description. The body has no meaningful return and is class-owned; `SetHighlightedPart` is the accepted source-facing best inference.

#### [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md) destination payload

- **Exact metadata and Item Summary:**

```markdown
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Item Summary: Source-ready generic ScrollPane press-initialization method; records thumb drag offsets for thumb presses, stores the active one-byte ScrollPanePart, performs the first active-part action immediately, schedules timer zero with a 200 ms initial delay, and preserves the exact Y-first input ABI, callers, callees, range, ownership, and source route. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- **Range and boundaries:** the body is exactly `[0x0055df10,0x0055dfcf)`, size `0xbf`, immediately after `SetHighlightedPart`. The following single byte `[0x0055dfcf,0x0055dfd0)` is [UID:0000VN] `0xcc` alignment and must not enter this child.
- **Behavior and data flow:** for `kScrollPanePartThumb`, call `SetHighlightedPart`, obtain the thumb rectangle through `GetScrollPartRect`, and store Y/X drag offsets from the local cursor to rectangle top/left in `m_thumbDragOffset`. Store the requested signed one-byte part in `m_activePart` at `+0x104`, call `ProcessActivePart()` immediately, then call `ScheduleTimer(0,200,0,0)`. The accepted signature is `void ScrollPane::BeginPartPress(ScrollPanePart part, int localY, int localX)`.
- **Caller/callee/xref evidence:** direct code callers are `0x0055c4e9` and `0x0055c5d3` in [UID:000433] `ScrollPaneHandleMouseEvent`. Direct semantic callees are `SetHighlightedPart`, [UID:0001GK] `GetScrollPartRect`, `ProcessActivePart`, and inherited timer scheduling. Caller event-field order and `Point` layout establish Y before X.
- **Ownership, emitter, and source placement:** both calls recover/pass the primary `ScrollPane`; stores land in accepted `ScrollPane` tail members; timer and input facets are inherited through `Pane`. Direct owner/emitter are [UID:0000CM], definition in [UID:0000NF] `NexusTK/ui/core/ScrollBar.cpp`, declaration in UID0000CM H.
- **Positive evidence:** two direct mouse-down calls, exact thumb-only branch, exact rectangle-relative offset stores, active-part byte store, immediate dispatch, timer ID/delay constants, stack cleanup, and sibling begin-drag/repeat patterns all converge.
- **Negative evidence:** no evidence supports the decompiler's stale `Point *` receiver, X-first parameters, a return value, a separate timer-owner object, or inclusion of the following alignment byte. No additional callers/data references suggest a broader public helper.
- **Score/confidence rationale:** `92/94` is supported by exact range, constants, stores, callers, callee sequence, ABI, and class route. Historical symbol spelling and compiled-equivalence confirmation cap it below 95.
- **Formal C++/H disposition:** copy verbatim the complete block under `### ScrollPaneBeginPartPress formal CPP block` to the child formal CPP header. Leave child H blank; place the declaration in UID0000CM H.
- **Historical/corrected assumptions:** preserve the old `sub_55DF10`, `Point *this`, X-first, unresolved-helper, and potential timer-wrapper assumptions as corrected history. Primary-object caller recovery, field offsets, argument ordering, and exact call sequence supersede them.

#### [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md) destination payload

- **Exact metadata and Item Summary:**

```markdown
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Item Summary: Source-ready generic ScrollPane active-part dispatcher; localizes the cursor, handles thumb dragging through UpdatePositionFromCursor, enforces EPF/classic highlight rules, applies first-button/page-before/page-after/second-button position changes with exact clamping and owner callback behavior, and separates its compiler-generated switch tail from handwritten C++. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- **Range and boundaries:** handwritten code is exactly `[0x0055dfd0,0x0055e1ed)`, size `0x21d`. The separate compiler tail `[0x0055e1ed,0x0055e210)` consists of a three-byte NOP, the five-entry internal jump table `[0x0055e1f0,0x0055e204)`, and twelve `0xcc` bytes; it belongs in [UID:0000VN], not this child's formal C++ or range.
- **Behavior and data flow:** obtain cursor and screen origin, return for the `(-1000,-1000)` unavailable sentinel, and convert to local Y/X. If `m_activePart` is thumb, call `UpdatePositionFromCursor(localY,localX)` and return. Otherwise hit-test the local point; EPF mode highlights only the still-active part and clears a mismatch, while classic mode rejects a mismatch and clears highlight. Set the accepted highlight, recover the scroll owner, save the old position, and switch on active part: first button decrements, page-before subtracts page size, page-after adds page size, and second button increments. Clamp to `[0,m_scrollRange]`; call `ApplyScrollPosition(m_orientation,oldPosition,newPosition)` only when changed.
- **Caller/callee/xref evidence:** direct code callers are `0x0055c628` in [UID:000435] `ScrollPaneOnScrollTimer` and `0x0055dfa2` in `BeginPartPress`. Callees/dependencies include cursor-position and screen-offset helpers, `HitTestPart`, `SetHighlightedPart`, `UpdatePositionFromCursor`, parent/owner retrieval, page-size retrieval, and owner `ApplyScrollPosition`. The jump table xref targets internal switch blocks only.
- **Ownership, emitter, and source placement:** active/highlight/orientation/position/range fields all map to the accepted `ScrollPane` tail, callers use inherited input/timer facets of the same object, and owner callbacks match [UID:0001GL] contracts. Direct owner/emitter are [UID:0000CM]; definition belongs in [UID:0000NF] `NexusTK/ui/core/ScrollBar.cpp`, declaration in UID0000CM H.
- **Positive evidence:** complete branch reconstruction, two direct callers, exact cursor sentinel/localization, EPF/classic divergence, five-part switch, page/step arithmetic, clamp, changed-only callback, field map, and internal jump-table targets provide very strong behavioral proof.
- **Negative evidence:** no evidence supports treating the jump table as a source global, merging the compiler tail into handwritten range, a standalone free function, an unconditional callback, a missing clamp, or a different class owner. Original helper spelling is stripped but role is not unresolved.
- **Score/confidence rationale:** `93/94` reflects complete branch/switch/data-flow recovery and strong route/ABI evidence. The remaining one-point confidence cap is lexical/final compiled equivalence, not missing behavior.
- **Formal C++/H disposition:** copy verbatim the complete block under `### ScrollPaneProcessActivePart formal CPP block` into child formal CPP. Leave child H blank and place the declaration in UID0000CM H. Emit a source `switch`; never emit the jump-table bytes as manual data.
- **Historical/corrected assumptions:** retain the raw `sub_55DFD0`, unresolved aggregate/table, possible data-island, and generic timer-helper descriptions only as corrected history. Exact callers, fields, branch graph, and table xrefs establish a class method whose compiler tail is regenerated.

#### [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md) destination payload

- **Exact metadata and Item Summary:**

```markdown
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Item Summary: Source-ready generic ScrollPane thumb-drag position updater; derives horizontal or vertical track bounds from exact part geometry, applies saved drag offsets and EPF/classic arithmetic, clamps to the scroll range, calls the owner only on change, preserves the observed no-zero-denominator-guard behavior, and records exact Y-first caller, range, ownership, and source evidence. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- **Range and boundaries:** the method is exactly `[0x0055e210,0x0055e5f6)`, size `0x3e6`. It follows the complete `ProcessActivePart` compiler tail and ends before ten [UID:0000VN] `0xcc` bytes at `[0x0055e5f6,0x0055e600)`.
- **Behavior and data flow:** call `GetScrollPartRect` for the first button, second button, and thumb. For horizontal mode use `localX-m_thumbDragOffset.x`; for vertical use `localY-m_thumbDragOffset.y`; EPF mode applies the observed `+1` adjustment. Derive lower/upper track limits, clamp the dragged thumb coordinate, then calculate the new scroll position. EPF vertical uses `(m_scrollRange + 1) * (position-lower) / (upper-lower)` followed by range clamping; the other paths use `m_scrollRange * (position-lower) / (upper-lower)`. Preserve the observed absence of a denominator-zero guard. Call owner `ApplyScrollPosition` only when the result differs.
- **Caller/callee/xref evidence:** direct code callers are `0x0055e055` and `0x0055e0db`, both in `ProcessActivePart`. Callees/dependencies are [UID:0001GK] `GetScrollPartRect`, parent/owner retrieval, and `ApplyScrollPosition`; data dependencies are orientation, EPF mode, drag offset, position, and range fields. No unrelated external caller or data/vtable route was found.
- **Ownership, emitter, and source placement:** all geometry and state fields belong to accepted `ScrollPane`, both callers pass the same object, and owner callbacks match generic scroll contracts and sibling thumb-drag methods. Direct owner/emitter are [UID:0000CM]; definition belongs in [UID:0000NF] `NexusTK/ui/core/ScrollBar.cpp`, declaration in UID0000CM H.
- **Positive evidence:** exact large modeled body, two direct active-part callers, three geometry requests, orientation-specific coordinate selection, saved-offset use, EPF/classic formula differences, clamp, changed-only callback, and sibling drag behavior support the complete method.
- **Negative evidence:** no evidence supports adding a defensive zero-denominator guard, swapping X/Y arguments, collapsing EPF/classic formulas, using floating point, widening one-byte part state, or assigning the method to a derived pane. Such cleanups would alter observed behavior.
- **Score/confidence rationale:** `93/94` is warranted by branch-by-branch arithmetic and direct route proof; exact historical spelling and final compiler-equivalence remain the only material caps.
- **Formal C++/H disposition:** copy verbatim the complete block under `### ScrollPaneUpdatePositionFromCursor formal CPP block` into child formal CPP. Leave child H blank and put the declaration in UID0000CM H.
- **Historical/corrected assumptions:** preserve the former raw `sub_55E210`, unresolved formula, X-first possibility, and temptation to add a zero-denominator guard as corrected/rejected history. Exact arithmetic and caller order supersede them; the no-guard behavior is intentional reconstruction fidelity.

#### [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) destination payload

- **Exact metadata and Item Summary:**

```markdown
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Item Summary: Source-ready generic ScrollPane interaction reset method; removes pending timers, clears the active one-byte part, invalidates the highlighted part rectangle when present, clears highlighted state, and preserves exact mouse-handler callers, range/fences, ownership, source-placement, void ABI, and sibling reset evidence. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- **Range and boundaries:** the method is exactly `[0x0055e600,0x0055e65c)`, size `0x5c`, after ten [UID:0000VN] `0xcc` bytes. The four bytes `[0x0055e65c,0x0055e660)` are a separate outside-target successor fence before [UID:0001GL] and must remain ignored rather than expanding this method.
- **Behavior and data flow:** remove pending timers, store `kScrollPanePartNone` in `m_activePart`, and if `m_highlightPart` is valid, obtain its rectangle through `GetScrollPartRect`, invalidate it, then clear `m_highlightPart`. The accepted source signature is `void ScrollPane::ResetScrollState()`; no meaningful return value exists.
- **Caller/callee/xref evidence:** direct code callers are `0x0055c459` and `0x0055c56d` in [UID:000433] `ScrollPaneHandleMouseEvent`. Direct dependencies are inherited pending-timer removal, [UID:0001GK] `GetScrollPartRect`, and pane invalidation. No data/vtable or alternate-class caller route was found.
- **Ownership, emitter, and source placement:** the two state bytes are accepted `ScrollPane` members, mouse-reset callers recover the same primary object, and sibling scroll panes use the same cancel/clear/invalidate role. Direct owner/emitter are [UID:0000CM]; definition belongs in [UID:0000NF] `NexusTK/ui/core/ScrollBar.cpp`, declaration in UID0000CM H.
- **Positive evidence:** exact compact body, two direct reset-path callers, timer removal, literal active/highlight stores, conditional geometry invalidation, exact void behavior, sibling reset patterns, and two separate alignment fences provide strong proof.
- **Negative evidence:** no evidence supports the stale `char` return, a timer-only owner, preserving highlighted state, merging the four-byte successor fence, or assigning the helper to [UID:0001GL]. No original spelling survives, but the role is exact.
- **Score/confidence rationale:** `92/94` follows from exact range, body, state fields, callers, callees, owner, emitter, and source route. Original spelling and final compiled comparison prevent a 95+ final score.
- **Formal C++/H disposition:** copy verbatim the complete block under `### ScrollPaneResetScrollState formal CPP block` into child formal CPP. Leave child H blank and place the declaration in UID0000CM H.
- **Historical/corrected assumptions:** retain raw `sub_55E600`, stale `char` return, unresolved timer semantics, and possible successor-range ownership only in corrected history. The void body, two mouse callers, exact field stores, and separate four-byte fence supersede them.
2. Update UID0001GK:
   - owner/emitter `0003A5 -> 0000CM`;
   - `Nested:-8 -> 0`;
   - retain its exact formal CPP and blank H;
   - recommended score `92/94` after reconciling this complete family.
3. Update UID0000CM:
   - retain `87/88`; this bounded pass does not justify a whole-class score increase because the unrelated no-route `+0xfa` raw setter, complete virtual/destructor inventory, and final historical header/source split remain outside this target;
   - retain owner/emitter UID0000NF;
   - retain CPP child routing;
   - put the bounded source-ready one-byte part typedef/constants and class declaration above in the formal H block without inventing a callable API for the no-route raw setter;
   - replace provisional helper names/offset prose in the affected sections with the resolved one-byte part contract, seven methods, Y-first ABI, and exact tail-layout evidence while preserving unrelated class evidence;
   - do not add a source-level size-check typedef/assert; preserve size proof in prose and the exact supervisor IDA UDT instead.
4. Update UID000433:
   - change formal helper calls from X-first to Y-first: `PointInRect(event.y,event.x,...)`, `HitTestPart(event.y,event.x)`, and `BeginPartPress(part,event.y,event.x)`;
   - update evidence and score from `88/90` to recommended `91/93`.
5. Update UID000435 to state `ProcessActivePart` is resolved for first-draft source use rather than still pending helper-family finalization; keep current formal behavior and owner route.
6. Preserve UID0000NF's newer current `91/90`; update only stale generic ScrollPane helper-split/source-route wording. This bounded target does not claim the unrelated score increase and does not re-audit the whole file's remaining ScrollWidget/ScrollablePane/CScrollBarBackPane declarations or historical split.
7. Update UID0001GJ only as a containing-corridor map: record the complete generic ScrollPane split, but keep mixed/no-owner status.
8. Update UID0001GI/UID0001GL/UID0003CQ only where current prose still calls the six helpers unresolved; preserve their existing ownership and unrelated behavior.
9. Update `by-memory/-ignored.md` with the exact alignment and compiler-tail classifications without calling the switch table ordinary padding. Insert the following exact ordinary-doc disposition immediately after the existing `ScrollPaneInputCore internal alignment padding` entry and before the next higher-address ignored family entry:

```markdown
- `0x0055d9d6-0x0055d9e0`, `0x0055de99-0x0055dea0`, `0x0055dfcf-0x0055dfd0`, `0x0055e1ed-0x0055e210`, `0x0055e5f6-0x0055e600`, and `0x0055e65c-0x0055e660` - ScrollPane input/geometry helper alignment and ProcessActivePart compiler switch tail.
  - Why ignored: the first, second, third, fifth, and sixth spans are compiler/linker `0xcc` alignment; `[0x0055e1ed,0x0055e210)` is a three-byte NOP, the five-entry internal `ProcessActivePart` jump table at `[0x0055e1f0,0x0055e204)`, and twelve trailing `0xcc` bytes. None is handwritten source.
  - Evidence: the 2026-07-29 B005 live read-only IDA MCP function, byte, and xref audit confirmed every exact method end/start and byte sequence; `[0x0055e65c,0x0055e660)` is four `0xcc` bytes between `ScrollPane::ResetScrollState` and the first [UID:0001GL] `ScrollablePaneCore` method.
  - Replacement/procurement: no handwritten source replacement; emit the `ProcessActivePart` source switch and let the compiler/linker regenerate its jump table and all six alignment spans.
  - Owner docs: [UID:0003A5] `ScrollPaneInputGeometryHelpers`, [UID:0001GK] `ScrollPaneGetScrollPartRect`, [UID:0000CM] `ScrollPane`, [UID:0000NF] `ScrollBar`, and [UID:0001GL] `ScrollablePaneCore`.
```

10. Do not let any B agent edit a `-coverage-report.md`; supervisor applies the literal payload after implementation.

## Score And Metadata Recommendation

| Document | Completion | Confidence | Owner | Reconstructable | Emitter | Rationale |
| --- | ---: | ---: | --- | --- | --- | --- |
| UID0003A5 split index | `93` | `94` | `0000CM` | `FALSE` | blank | full family map, exact split, behavior, compiler-tail and source route; no standalone source construct |
| new HitTestPart | `92` | `94` | `0000CM` | `TRUE` | `0000CM` | exact loop/ABI/callers/body; original spelling inferred |
| new SetHighlightedPart | `92` | `94` | `0000CM` | `TRUE` | `0000CM` | exact invalidation/store behavior and sibling naming |
| new BeginPartPress | `92` | `94` | `0000CM` | `TRUE` | `0000CM` | exact thumb offset, active state, process call, timer |
| new ProcessActivePart | `93` | `94` | `0000CM` | `TRUE` | `0000CM` | exact branch/switch/cursor/page/clamp/update behavior |
| new UpdatePositionFromCursor | `93` | `94` | `0000CM` | `TRUE` | `0000CM` | exact geometry, arithmetic, EPF/classic divergence and callback |
| new ResetScrollState | `92` | `94` | `0000CM` | `TRUE` | `0000CM` | exact timer/state/invalidation body |
| UID0001GK GetScrollPartRect | `92` | `94` | `0000CM` | `TRUE` | `0000CM` | existing exact body plus fully resolved peer family |
| UID0000CM ScrollPane | `87` | `88` | `0000NF` | `TRUE` | `0000NF` | retain current score; bounded one-byte part typedef/constants and tail/helper declaration are internally coherent first-draft source, but unrelated whole-class audit and final compile/behavior proof remain incomplete |
| UID000433 mouse handler | `91` | `93` | `0000CM` | `TRUE` | `0000CM` | existing body with corrected Y-first helper calls |
| UID000435 timer callback | `88` | `90` | `0000CM` | `TRUE` | `0000CM` | exact existing timer body; reconcile only the now-resolved ProcessActivePart wording |
| UID0000NF ScrollBar file | `91` | `90` | existing | `TRUE` | existing | preserve newer current score; source route is confirmed but whole-file declarations and historical split are not re-audited by this bounded report |

No code-emitting target is recommended at 95 or above before compilation and behavior-equivalence audit.

## Open Questions With Attempted Resolution

No material helper or ABI-contract blocker remains open.

| Former open question | Investigation performed | Resolution |
| --- | --- | --- |
| exact role of `0x55d960` | decompile, callers, sibling hit tests, event ABI | `HitTestPart(int localY,int localX)` |
| exact role/name of `0x55dea0` | full data flow, field store, invalidation, RankingEvent/FittingRoom comparison | `SetHighlightedPart(ScrollPanePart)` |
| exact signature/order of `0x55df10` | stack args, Point layout, offset stores, caller event fields | `BeginPartPress(part,localY,localX)` |
| exact behavior of `0x55dfd0` | complete decompile/disasm, jump table, timer/input callers, owner contracts | `ProcessActivePart()` |
| exact formulas in `0x55e210` | branch-by-branch arithmetic, geometry children, EPF/classic comparison | `UpdatePositionFromCursor(localY,localX)` with exact formulas above |
| exact role of `0x55e600` | timer removal, stores, invalidation, callers, siblings | `ResetScrollState()` |
| `ScrollPanePart` storage/call ABI | current byte fields, byte-return disassembly, low-byte argument use, exact stack frames, x86 `__thiscall` stack cleanup, and mid-2000s language constraints | one-byte `typedef signed char ScrollPanePart` plus typed constants; the source and IDA declarations, definitions, parameters, returns, and fields now share one contract |
| source-level size assertion | searched accepted project/source-shape evidence; only reconstructed sibling drafts contained analogous assertions, with no direct original-source proof | omit the handwritten typedef/assert; retain exact `0x110` proof in documentation, natural source layout, and the implementable IDA UDT |
| original symbol spellings | bounded symbol/type/doc/report/sibling search | unrecoverable as symbols; best-probability human names selected, not a blocker |
| `0x55e1ed-0x55e210` classification | byte readback and xref to table | NOP + five-entry switch table + alignment, compiler-generated from `ProcessActivePart` |
| X/Y order | event offsets and two sibling scrollbar families | Y-first ABI; current UID000433 X-first calls must be corrected |
| class inheritance/layout | constructor/vtable/class docs and sibling declarations | `ScrollPane : public Pane`, natural size `0x110`; EventHandler/TimerHandler facets are inherited through Pane layout, not explicit duplicate source bases |

Residual uncertainty is exact historical spelling/style and final compiled equivalence. Project policy requires realistic inferred source names, so spelling is recorded as a score cap rather than deferred work; final compilation and behavior/ABI comparison remain required before any emitting page can justify a final-audit score of 95 or higher.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Current manual rows were inspected directly. UID000433, UID000435, UID0003A5, UID0004YF, UID0004YI, UID0004YJ, UID0004YL, UID0004YM, UID0004YN, and all six exact ignored ranges are absent. UID0001GK, UID0001GH, UID0001GI, UID0001GJ, and UID0000CM are stale. UID0000NF is already exact. The six new child pages now have validator-assigned identities, and their complete literal destination-ready rows below use those exact UID/link prefixes. The handoff therefore contains `20` applicable operations (`15` insertions plus `5` replacements) and one exact UID0000NF no-op; no row text is deferred to or synthesized by the supervisor.

The pre-B004, `2026-07-29T10:16`, `2026-07-29T10:42`, command-`000000019201`, and `4590B3...`/`91E531...`/`7ED5B1...` coverage checkpoints are retained only as dated history. The latest exact physical read-only audit found `by-memory/-coverage-report.md` SHA256 `BB5E391E0198251142EC7BA4907D524E9ABCC80A5A2DFB0EBA53CE3F93802E20`, 2,082,636 bytes/4,723 lines, last write `2026-07-29T12:29:46.3685-04:00`; `by-class/-coverage-report.md` SHA256 `EB1ADFEAD1D3702137748D16942EF1AA2A4A39637C24FB9EA1230172B2FA41C5`, 271,059 bytes/625 lines; and `by-file/-coverage-report.md` SHA256 `BDB85AA42D17E235E4C449A520DA2120D609247F0690ADC708B30121E995C83E`, 162,927 bytes/317 lines. Against these current files, all `20` staged operations remain applicable (`15` inserts plus replacements for UID0001GH line 3194, UID0001GI line 3196, UID0001GJ line 3198, UID0001GK line 3199, and UID0000CM by-class line 478); UID0000NF remains an exact byte-for-byte no-op at by-file line 241; UID0001GL remains the line-3200 successor anchor; and all staged child/ignored rows remain absent. The supervisor must re-read again before application if any coverage identity advances.

Replace the current top-level UID0001GH row in place with this exact row. Its current location remains the parent anchor for the two nested input children and precedes the existing `[0x0055c643,0x0055c650)` ignored row:

```markdown
    - [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) 0x0055c200-0x0055c643 | reviewed split index | ScrollPaneInputCore : non-reconstructable : 88% : very-strong : Non-emitting mixed ScrollPane/ScrollWidget input-core split index with eleven exact constructor, raw-setter, widget-state, predicate, EventHandler, default-virtual, and TimerHandler child pages; child-owned formal C++, source-file ancestor ScrollBar, exact class routes, no-code aggregate proof, raw-helper dispositions, and internal padding remain separated from aggregate emission.
```

The following existing-UID input-child rows are complete. After replacing UID0001GH, insert them immediately beneath it in address order, before the existing `[0x0055c643,0x0055c650)` ignored row and UID0001GI:

```markdown
        - [UID:000433][0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md) 0x0055c400-0x0055c5ff | EventHandler override | ScrollPaneHandleMouseEvent : reconstructable : 91% : very-strong : Exact EventHandler-adjusted ScrollPane mouse handler with primary-owner recovery, EPF/classic branches, capture/release, Y-first PaneMouseEvent coordinates, resolved HitTestPart/BeginPartPress/ResetScrollState calls, formal C++, and direct ScrollPane route.
        - [UID:000435][0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md) 0x0055c610-0x0055c643 | TimerHandler override | ScrollPaneOnScrollTimer : reconstructable : 88% : very-strong : Exact TimerHandler-adjusted ScrollPane repeat callback with vtable-only route, timer-id zero and active-part gates, resolved ProcessActivePart dispatch, ScheduleTimer(0,30,0,0), exact padding, formal C++, and direct ScrollPane ownership; helper spelling remains inferred only as a final lexical confidence cap.
```

Preserve the existing `[UID:0000VN] 0x0055c643-0x0055c650` ignored row exactly. Replace the following UID0001GI row in place with this exact current row, before the existing `[0x0055d957,0x0055d960)` ignored row:

```markdown
    - [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md) 0x0055c650-0x0055d957 | virtual method | ScrollPaneOnDraw : reconstructable : 88% : very-strong : Exact vtable-only ScrollPane::OnDraw with 0x1307-byte half-open range, EPF/classic rendering branches, SLIDEBG/SCRBUTT/SCRL001 resources, shared scrollbar constants, four GetScrollPartRect calls, IsScrollThumbVisible dependency, normalized render-helper roles, exact post-ret padding, direct ScrollPane owner/emitter, and source-ready formal C++.
```

Replace the following top-level UID0001GJ row in place with this exact current row. Its location remains immediately after `[0x0055d957,0x0055d960)` and immediately before UID0003A5 plus the finalized nested generic ScrollPane child sequence:

```markdown
    - [UID:0001GJ][0x0055d960-0x005654ec.TextEditPaneScrollbarVariants](by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md) 0x0055d960-0x005654ec | reviewed mixed corridor | TextEditPaneScrollbarVariants : non-reconstructable : 89% : very-strong : Non-emitting mixed-owner scrollbar corridor with 84 modeled functions through the complete ScrollVolumePane raw-reset island, stable owner-cluster boundaries, complete seven-method generic ScrollPane split, feature-scrollbar child maps, exact tail/raw-gap handling, and no single class or source-file owner for the full address span.
```

After replacing UID0001GJ, insert this exact existing-UID split-index row immediately beneath it and before the finalized child sequence/UID0001GL:

```markdown
    - [UID:0003A5][0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers](by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md) 0x0055d960-0x0055e65c | reviewed split index | ScrollPaneInputGeometryHelpers : non-reconstructable : 93% : very-strong : Non-emitting generic ScrollPane helper-family index with seven exact source methods, direct class/file routes, exact Y-first input ABI, complete caller/field/behavior ledger, five alignment regions, and the ProcessActivePart compiler switch-table tail separated from handwritten C++.
```

The following are the six complete literal new-child rows after validator registration. Preserve their range, role, title, status, score, confidence label, evidence description, and exact stable UID/link prefix during supervisor application.

```markdown
        - [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md) 0x0055d960-0x0055d9d6 | method | ScrollPaneHitTestPart : reconstructable : 92% : very-strong : Exact generic ScrollPane five-part hit test with Y-first local coordinates, GetScrollPartRect geometry, signed one-byte ScrollPanePart return, four direct mouse/process callers, clean alignment fence, direct ScrollPane owner/emitter, and source-ready formal C++.
        - [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md) 0x0055dea0-0x0055df10 | method | ScrollPaneSetHighlightedPart : reconstructable : 92% : very-strong : Exact generic ScrollPane highlighted-part transition with same-state early return, old/new rectangle invalidation, signed one-byte m_highlightPart store, sole ProcessActivePart caller, direct ScrollPane owner/emitter, and source-ready formal C++.
        - [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md) 0x0055df10-0x0055dfcf | method | ScrollPaneBeginPartPress : reconstructable : 92% : very-strong : Exact Y-first generic ScrollPane press initializer with thumb drag-offset capture, active-part store, immediate ProcessActivePart dispatch, ScheduleTimer(0,200,0,0), two direct mouse callers, direct ScrollPane owner/emitter, and source-ready formal C++.
        - [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md) 0x0055dfd0-0x0055e1ed | method | ScrollPaneProcessActivePart : reconstructable : 93% : very-strong : Exact generic ScrollPane active-part dispatcher with cursor localization, thumb drag path, EPF/classic highlight rules, step/page switch, range clamp, changed-only owner callback, two direct press/timer callers, and compiler switch tail excluded from handwritten C++.
        - [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md) 0x0055e210-0x0055e5f6 | method | ScrollPaneUpdatePositionFromCursor : reconstructable : 93% : very-strong : Exact Y-first generic ScrollPane thumb-drag updater with part geometry, saved drag offsets, horizontal/vertical EPF/classic formulas, observed no-zero-denominator-guard behavior, range clamp, changed-only owner callback, and two direct ProcessActivePart callers.
        - [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) 0x0055e600-0x0055e65c | method | ScrollPaneResetScrollState : reconstructable : 92% : very-strong : Exact generic ScrollPane interaction reset with pending-timer removal, active/highlight state clearing, conditional highlighted-rectangle invalidation, void ABI, two direct mouse-reset callers, direct ScrollPane owner/emitter, and successor fence excluded.
```

Exact placement is address ordered beneath UID0003A5: HitTestPart immediately before `[0x0055d9d6,0x0055d9e0)`; SetHighlightedPart immediately after `[0x0055de99,0x0055dea0)` and before BeginPartPress; BeginPartPress immediately before `[0x0055dfcf,0x0055dfd0)`; ProcessActivePart immediately before `[0x0055e1ed,0x0055e210)`; UpdatePositionFromCursor immediately before `[0x0055e5f6,0x0055e600)`; ResetScrollState immediately after that padding and before `[0x0055e65c,0x0055e660)`. The finalized identity table is:

| Final child | Registration state |
| --- | --- |
| [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md) | assigned UID/link prefix applied exactly; no further substitution required |
| [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md) | assigned UID/link prefix applied exactly; no further substitution required |
| [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md) | assigned UID/link prefix applied exactly; no further substitution required |
| [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md) | assigned UID/link prefix applied exactly; no further substitution required |
| [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md) | assigned UID/link prefix applied exactly; no further substitution required |
| [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) | assigned UID/link prefix applied exactly; no further substitution required |

This construction used no provisional UID. All staged rows now contain literal validator-owned UIDs before coverage application.

The following existing-UID rows are also exact. During the callback, interleave them with the six staged child rows in address order under UID0003A5: the first two rows follow HitTestPart; the next follows GetScrollPartRect; the third alignment row follows BeginPartPress; the compiler-tail row follows ProcessActivePart; the fifth alignment row follows UpdatePositionFromCursor; and the outside-target successor-fence row follows ResetScrollState immediately before UID0001GL.

```markdown
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055d9d6-0x0055d9e0 | alignment | ScrollPaneHitTestPartToGetScrollPartRectPadding : ignored : 100% : strong : Ten 0xcc alignment bytes between exact ScrollPane methods.
        - [UID:0001GK][0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md) 0x0055d9e0-0x0055de99 | method | ScrollPaneGetScrollPartRect : reconstructable : 92% : very-strong : Exact ScrollPane five-part geometry method for EPF/classic horizontal/vertical modes with resolved field layout, extent tables, formulas, direct class route, and source-ready formal C++.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055de99-0x0055dea0 | alignment | ScrollPaneGetScrollPartRectToSetHighlightedPartPadding : ignored : 100% : strong : Seven 0xcc alignment bytes between exact ScrollPane methods.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055dfcf-0x0055dfd0 | alignment | ScrollPaneBeginPartPressToProcessActivePartPadding : ignored : 100% : strong : One 0xcc alignment byte between exact ScrollPane methods.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055e1ed-0x0055e210 | compiler switch tail/alignment | ScrollPaneProcessActivePartCompilerTail : ignored : 100% : very-strong : Three-byte NOP, five-entry jump table at 0x0055e1f0-0x0055e204 targeting ProcessActivePart switch blocks, and twelve trailing 0xcc bytes; compiler output regenerated from the source switch, not handwritten data.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055e5f6-0x0055e600 | alignment | ScrollPaneUpdatePositionToResetStatePadding : ignored : 100% : strong : Ten 0xcc alignment bytes between exact ScrollPane methods.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055e65c-0x0055e660 | alignment | ScrollPaneInputGeometryHelpersToScrollablePaneCorePadding : ignored : 100% : strong : Four 0xcc compiler/linker alignment bytes after ScrollPane::ResetScrollState and before the first ScrollablePaneCore method; no handwritten source replacement.
```

Deterministic new-child UID and coverage reconciliation procedure:

| Canonical child reference | Completed registration action | Final post-validation reconciliation |
| --- | --- | --- |
| [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md) | created from the complete destination payload with `92/94`, owner/emitter `0000CM`, reconstructable true, `Nested:0`, exact formal CPP and blank H | command `000000018911` assigned UID0004YF; the report and staged coverage row now use the final link; supervisor places the row immediately before `[0x0055d9d6,0x0055d9e0)` |
| [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md) | created from the complete destination payload with `92/94`, owner/emitter `0000CM`, reconstructable true, `Nested:0`, exact formal CPP and blank H | command `000000018914` assigned UID0004YI; the report and staged coverage row now use the final link; supervisor places the row immediately after `[0x0055de99,0x0055dea0)` |
| [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md) | created from the complete destination payload with `92/94`, owner/emitter `0000CM`, reconstructable true, `Nested:0`, exact formal CPP and blank H | command `000000018915` assigned UID0004YJ; the report and staged coverage row now use the final link; supervisor places the row immediately before `[0x0055dfcf,0x0055dfd0)` |
| [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md) | created from the complete destination payload with `93/94`, owner/emitter `0000CM`, reconstructable true, `Nested:0`, exact formal CPP and blank H | command `000000018917` assigned UID0004YL; the report and staged coverage row now use the final link; supervisor places the row immediately before `[0x0055e1ed,0x0055e210)` |
| [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md) | created from the complete destination payload with `93/94`, owner/emitter `0000CM`, reconstructable true, `Nested:0`, exact formal CPP and blank H | command `000000018921` assigned UID0004YM; the report and staged coverage row now use the final link; supervisor places the row immediately before `[0x0055e5f6,0x0055e600)` |
| [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) | created from the complete destination payload with `92/94`, owner/emitter `0000CM`, reconstructable true, `Nested:0`, exact formal CPP and blank H | command `000000018932` assigned UID0004YN; the report and staged coverage row now use the final link; supervisor places the row after `[0x0055e5f6,0x0055e600)` and before the `[0x0055e65c,0x0055e660)` successor-fence row and UID0001GL |

The agent did not apply any staged row to the live coverage report. Each path exists, scoped validation succeeded, and every row now carries the literal assigned UID. `TARGET-REPORT-ADDITIONAL-UIDS`, Target/declared inventory, ledger, child inventory, checklist, and manual rows are reconciled before Gate 2. Exact-artifact verification confirms that all six child identities use literal assigned UID/path pairs and no provisional child-identity token remains. All six row bodies and placements are final; supervisor-owned coverage application remains pending.

Replace the current by-class row with:

```markdown
- [UID:0000CM][ScrollPane](by-class/ScrollPane.md) : reconstructable : 87% : strong : Generic Pane-derived ScrollPane source route with exact 0x110 tail layout, coherent one-byte ScrollPanePart typedef/typed constants and accepted constructor/state/draw/input/timer/geometry members, Y-first seven-method input/geometry split, direct method children, formal header C++, no unsupported source size assertion, and explicit exclusion of the no-route +0xfa raw setter from invented callable APIs; unrelated whole-class audit remains outside this bounded target.
```

The current by-file row is already score-consistent and needs no replacement. Preserve it exactly; only ordinary UID0000NF prose that still called this helper family unresolved was reconciled:

```markdown
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md) : reconstructable : 91% : very-strong : Generic ScrollPane/ScrollWidget/ScrollablePane source family with exact class/method/layout/constant/compiler routes; historical CScrollBarBackPane placement is rejected by its exclusive NewOptionPane volume-control ownership and rerouted to OptionPane.
```

No agent should edit these coverage files. The supervisor applies and validates the existing-UID rows and the later literal new-child rows only after child UID reconciliation and implementation verification are final.

## Follow-Up Actions

1. Historical Gate 1 accepted exact pre-callback SHA256 `0EF25C93292AA70A8514AC7EFA8EADC67FAEFD8AD57C35489F4F66AF07329214`; this additive post-Gate2B reconciliation creates a new artifact that requires fresh exact-artifact Gate 1 review.
2. B005 completed the ordinary implementation callback, all six child registrations, all accepted support edits, the initial 14 serial validators, and the final 11 serial post-Gate2B reconciliation validators with generated refresh disabled.
3. Supervisor Gate 2B is already complete: catalog `0359`, protected backup `E9600F...`, first verified save `08D31F...`, and no-drift live readback in current authoritative shared IDB `412DA7E8...` are recorded. Do not repeat mutation; verify the current applied state during final Gate 2 review.
4. Supervisor performs fresh Gate 1 on this exact report and Gate 2A claim-by-claim verification against the final ordinary hashes, validator commands, metadata, formal CPP/H, range/history text, and checklist below.
5. Supervisor rechecks and applies/validates all `20` staged manual by-memory/by-class coverage operations; B005 did not edit them. UID0000NF remains a verified no-op.
6. Current generated/tracker readback is complete for command `000000019483`; all earlier commands remain dated history. Supervisor performs an authoritative final readback after coverage validation or if either artifact advances.
7. Supervisor reconciles catalog entry `0359` from its saved-state reconciliation status only after exact report/ordinary/coverage/generated verification. Report execution/archive remains supervisor-only and authoritative from actual path plus validator-owned status/history metadata.

## Confidence

Overall report confidence is `94/100`.

Strongest facts are function boundaries, call graph, exact historical prestates, applied names/prototypes/comments, normalized current frames, protected bytes/xrefs, byte-backed `ScrollPanePart` storage/call contract, exact `ScrollPane` UDT, field offsets, part values, arithmetic, Y-first order, timer constants, compiler-tail classification, owner, and source file. Formal C++ and current IDA now use the same one-byte return/parameter/member contract and omit the unsupported source size assertion. The score cap reflects stripped original symbols and the need for final compiled ABI/behavior comparison, not unresolved helper, IDA, or ABI research.

No confidence reduction is taken for the six former blockers because each was investigated to a high-probability source conclusion. Leaving them as compiler labels would be lower-quality reconstruction than the evidence-backed names selected here.

## Validator Results

The initial research phase ran no validator. After exact Gate 1 acceptance, B005 ran the following serial scoped file validators from `source-3/project-documentation`. Every command used `--apply --queue-timeout 240 --no-generated-refresh`; every command exited `0` with `ok: 1`, and every result explicitly reported `generated_refresh: skipped` / `disabled by --no-generated-refresh`. B005 invoked no report-lifecycle command; execution/archive authority remains supervisor-owned and is not asserted from this prose.

| Command | Timestamp | Exact relative path | Result | Warnings and side effects |
| --- | --- | --- | --- | --- |
| `000000018911` | `2026-07-29T08:16:54-04:00` | `by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md` | exit `0`, `ok:1` | no warning; validator assigned first-line UID0004YF and updated registry/references/projected stats; generated skipped |
| `000000018914` | `2026-07-29T08:18:57-04:00` | `by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md` | exit `0`, `ok:1` | no warning; validator assigned first-line UID0004YI and updated registry/references/projected stats; generated skipped |
| `000000018915` | `2026-07-29T08:21:23-04:00` | `by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md` | exit `0`, `ok:1` | no warning; validator assigned first-line UID0004YJ and updated registry/references/projected stats; generated skipped |
| `000000018917` | `2026-07-29T08:23:17-04:00` | `by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md` | exit `0`, `ok:1` | no warning; validator assigned first-line UID0004YL and updated registry/references/projected stats; generated skipped |
| `000000018921` | `2026-07-29T08:25:19-04:00` | `by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md` | exit `0`, `ok:1` | no warning; validator assigned first-line UID0004YM and updated registry/references/projected stats; generated skipped |
| `000000018932` | `2026-07-29T08:27:07-04:00` | `by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md` | exit `0`, `ok:1` | no warning; validator assigned first-line UID0004YN and updated registry/references/projected stats; generated skipped |
| `000000018943` | `2026-07-29T08:31:52-04:00` | `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` | exit `0`, `ok:1` | no warning; registry changed reconstructable true to false, cleared emitter and aggregate CPP, reconciled exact child links, updated projected stats; generated skipped |
| `000000018945` | `2026-07-29T08:32:38-04:00` | `by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md` | exit `0`, `ok:1` | no warning; registry owner/emitter rerouted to UID0000CM, metadata/references/projected stats reconciled; generated skipped |
| `000000018960` | `2026-07-29T08:36:01-04:00` | `by-class/ScrollPane.md` | exit `0`, `ok:1` | no warning; formal H registry changed blank to block, seven child links and reference-index rows reconciled, projected stats updated; generated skipped |
| `000000018964` | `2026-07-29T08:37:11-04:00` | `by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` | exit `0`, `ok:1` | no warning; completion/confidence updated to `91/93`, formal CPP hash and four exact helper references reconciled, projected stats updated; generated skipped |
| `000000018970` | `2026-07-29T08:38:14-04:00` | `by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md` | exit `0`, `ok:1` | no warning; UID0004YJ/UID0004YL links and reference-index rows added, projected stats updated; generated skipped |
| `000000018974` | `2026-07-29T08:39:24-04:00` | `by-file/ScrollBar.md` | exit `0`, `ok:1` | no warning; all six new child links/reference-index rows reconciled while preserving current `91/90`, projected stats updated; generated skipped |
| `000000018982` | `2026-07-29T08:40:31-04:00` | `by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md` | exit `0`, `ok:1` | no warning; eight new class/ignored/child reference-index relationships and split links reconciled, projected stats updated; generated skipped |
| `000000018983` | `2026-07-29T08:41:21-04:00` | `by-memory/-ignored.md` | exit `0`, `ok:1` | nonfatal `missing_ref_uid:192` from pre-existing stale references in the large shared ignored map; new UID0001GK/UID0003A5 references indexed, projected stats updated; generated skipped |

After supervisor Gate 2B, B005 ran this final serial reconciliation set. Every command used the same `--apply --queue-timeout 240 --no-generated-refresh` form, exited `0` with `ok:1`, and reported generated refresh skipped. Commands for the three no-op destinations were not repeated.

| Command | Timestamp | Exact relative path | Result | Warnings and side effects |
| --- | --- | --- | --- | --- |
| `000000019440` | `2026-07-29T14:28:06-04:00` | `by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019441` | `2026-07-29T14:28:08-04:00` | `by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019442` | `2026-07-29T14:28:10-04:00` | `by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019444` | `2026-07-29T14:28:13-04:00` | `by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019446` | `2026-07-29T14:28:16-04:00` | `by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019447` | `2026-07-29T14:28:18-04:00` | `by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019448` | `2026-07-29T14:28:20-04:00` | `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019450` | `2026-07-29T14:28:23-04:00` | `by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019451` | `2026-07-29T14:28:25-04:00` | `by-class/ScrollPane.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019453` | `2026-07-29T14:28:27-04:00` | `by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |
| `000000019454` | `2026-07-29T14:28:30-04:00` | `by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md` | exit `0`, `ok:1` | no target warning; registry/references/projected stats reconciled; generated skipped |

The historical source-queue checkpoint is command `000000018895`, SHA256 `21171036DD059D779DA0597D55C1075F93AF5AED9917E17063C1BE3485BD2274`, with preimplementation UID0003A5 `87/89`. Commands through `000000019259` and their exact tracker identities remain dated postimplementation checkpoints. Current read-only tracker authority is command `000000019483`, refreshed `2026-07-29T14:30:34-04:00` from `foreground-generated-refresh`, SHA256 `A2C97D53EA038671299109D5455954FD909A2DFF0E6BCB9673E8CABD2518DC65`, 1,676,576 bytes/6,632 lines, physical last write `2026-07-29T14:30:53.2980054-04:00`; UID0003A5 at line 5544 remains `93/94`, average `93.5`, reconstructable `false`, with zero direct/additional report counts. B005 ran none of the generated/tracker refresh commands.

The earlier `ScrollBar.cpp`/`.h` identities remain dated history. Current command `000000019483`, refreshed `2026-07-29T14:30:34-04:00` from `foreground-generated-refresh`, produced `ScrollBar.cpp` SHA256 `F3A446D6B85768A8F74FD0456D1D0F864609D55F648241099A6398BC53A856F5`, 25,913 bytes/806 lines, and `ScrollBar.h` SHA256 `3D2057DC66587D9802C14B862789666A9462622EFDC33BF33D5B630435F67CFC`, 1,866 bytes/53 lines. Topology remains exact: one definition each for UID0004YF, UID0001GK, UID0004YI, UID0004YJ, UID0004YL, UID0004YM, and UID0004YN; one UID0000CM class declaration with all seven methods and accepted members; and no UID0003A5 aggregate definition or empty marker. A later header/readback supersedes this checkpoint if generated output advances.

The exact callback commands, in serial execution order, were:

> Executable block R001 was removed from this report and preserved verbatim in [0003A5-ScrollPaneInputGeometryHelpers-source-quality-removed.md](0003A5-ScrollPaneInputGeometryHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The conditional [UID:0001GI], [UID:0001GL], and [UID:0003CQ] pages were inspected read-only and did not contain stale claims that these seven helpers remained unresolved; no edits or unnecessary validators were made. The supervisor-owned `by-memory/-coverage-report.md` command below remains mandatory after inserting the exact [UID:0000VN] successor-fence row immediately after ResetScrollState and before [UID:0001GL].

The supervisor, not B005, must apply and then validate the two manual coverage files with these literal serial commands when their accepted payloads are complete and every new child UID is known:

> Executable block R002 was removed from this report and preserved verbatim in [0003A5-ScrollPaneInputGeometryHelpers-source-quality-removed.md](0003A5-ScrollPaneInputGeometryHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Manual coverage application remains supervisor-owned, and B005 did not edit any `-coverage-report.md`. Report execution/archive state is likewise supervisor-owned and authoritative only from this report's current path plus validator-owned status/history metadata; this report body makes no current executed/not-executed claim.

## Changed Files

Modified ordinary files and exact post-validator identities:

| Path | SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md` | `4BC381748D68CE70095DE7269F24F29798F80D1F03506B2AE15903957156FAD7` | 11,252 | 120 |
| `by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md` | `858336208B41A5F4132459FCA2268AF6C47C1F3468EE05BF162652C790A54B8C` | 9,453 | 119 |
| `by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md` | `20FE27E3E007DBEDB6B04FFA05D48AA176280D0FE34769D2402A1611CF08AEB4` | 9,973 | 123 |
| `by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md` | `EEE8D57546DF8F2194DB8D7968DF4B8350592B94C75F32FF4DDD4D525881AD29` | 11,947 | 173 |
| `by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md` | `E111193C3915E7AF105C055AB601344F9F987F5F8D7B01A89FFA2CB1E5069822` | 11,312 | 160 |
| `by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md` | `E9D79DF54AAF1FC60B49454F6AE7596CD50ABD961FEC59CE02413B98CFAA8D8F` | 9,284 | 114 |
| `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` | `2AA413E71EBA95D5748A15314AAC2D04B3484A33B05C4F8B80ACB5C0C2F62A24` | 21,969 | 133 |
| `by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md` | `33F4A4145CF4552A68BEEE9E4BCD87A68C41BD5AA433DBAA23071AE1257CD1F0` | 28,399 | 416 |
| `by-class/ScrollPane.md` | `B8D1BA333A9950E46DCEBF2A9BB728240D2B88086E7908EF036682D0143A5AC0` | 38,208 | 228 |
| `by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` | `0967E1B29C517425B7A00EC6AB400BD8BCFE2C6A1EA02B4581C47BAC6551858E` | 13,359 | 153 |
| `by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md` | `400CE33EA20C1DEF03D8ED8B6C4D8D5DD54CE0AAE5A06AA1B2DD78925D2C8B10` | 15,389 | 116 |
| `by-file/ScrollBar.md` | `F467456C8778B6FF17A47E411316C3A3D853824D7CF75A94A90D692C1457968A` | 46,082 | 231 |
| `by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md` | `76C6603379798EF180584F8DD7DC7814267EAC76CFFC1E17296F216132176717` | 39,474 | 225 |
| `by-memory/-ignored.md` | `CE93201D24BF65D43B2451593A95F622D346CD8EA91FA1C0E1FAC3056D625701` | 1,125,060 | 5,414 |

The post-Gate2B reconciliation changed the 11 ordinary destinations whose hashes differ from the historical callback table; `ScrollPaneHandleMouseEvent`, `ScrollBar`, and `by-memory/-ignored.md` remained verified no-ops with unchanged hashes. Current exact physical coverage identities are by-memory `BB5E391E0198251142EC7BA4907D524E9ABCC80A5A2DFB0EBA53CE3F93802E20`, by-class `EB1ADFEAD1D3702137748D16942EF1AA2A4A39637C24FB9EA1230172B2FA41C5`, and by-file `BDB85AA42D17E235E4C449A520DA2120D609247F0690ADC708B30121E995C83E`; all 20 operations remain applicable and UID0000NF remains an exact no-op. All 14 ordinary destination hashes and their metadata/formal/content dispositions were independently rechecked against current disk after final validators.

This same report was updated additively; its final post-save identity is returned to the supervisor because embedding its own SHA would change that SHA. No IDA database, coverage report, generated output, supervisor/audit/catalog file, tracker, goal, notes, archive, or lifecycle state was directly edited by B005. Scoped validators made their documented registry/reference/projected-stat side effects only.

Read-only current provenance inspected but not modified: tracker/generated command `000000019483`; tracker SHA `A2C97D53EA038671299109D5455954FD909A2DFF0E6BCB9673E8CABD2518DC65`; generated CPP SHA `F3A446D6B85768A8F74FD0456D1D0F864609D55F648241099A6398BC53A856F5`; generated H SHA `3D2057DC66587D9802C14B862789666A9462622EFDC33BF33D5B630435F67CFC`. Historical commands through `000000019259` remain separate dated artifacts. Current authoritative IDB is SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`; earlier `905D1A...`, `296ED2...`, `3C8F31...`, `0E0AF9...`, `03F102...`, and `08D31F...` identities are historical.

## Implementation Tracking Checklist

### Gate 1 report completeness

- [x] Read current B005 goal and current project-level B-agent skill/template.
- [x] Preserve the report-only boundary during research; ordinary edits occurred only after exact Gate 1 authorization under short-lived leases.
- [x] Reconcile current target/support docs, generated topology, current manual coverage grammar/placement, all six ignored/compiler-only ranges including `[0x0055e65c,0x0055e660)`, and matching executed-report leads.
- [x] Perform a current read-only MCP pass against active database `1da2b2ae` with `status:"ok"`; all required bounded queries succeeded, all seven collisions remained absent, all frames/comments/types/dependencies remained exact, and F2's current prototype was mechanically corrected to `void __thiscall(int this, char, struct RectBounds *bounds)`.
- [x] Record explicit positive, negative, failed/unavailable, and intentionally skipped checks under `Evidence Checked`.
- [x] Resolve all seven methods, including all six unsplit helpers, to exact range, callers, behavior, signature, source-facing name, owner, placement, score, status, and formal CPP destination.
- [x] Resolve Y-first coordinate order.
- [x] Resolve compiler switch-table tail and all alignment boundaries.
- [x] Prove exact historical absence of `ScrollPanePart`, `ScrollPanePartValue`, and `ScrollPane`; record the one-byte typedef and exact implementable `Pane Pane_base`/13-member UDT actions; reconcile the applied current typedef/UDT readback.
- [x] Query every proposed function name independently and record all seven exact `fn:null`, `error:"Not found"` collision results.
- [x] Record every function's literal current range/name/size/prototype, all four comment channels, and complete `stack_frame` variable/local prestate; reconcile IDA-F2's unnamed current `char` slot and `struct RectBounds *` rendering everywhere without changing the accepted source-facing action.
- [x] Reconcile source and IDA ABI to one-byte signed `ScrollPanePart` across return types, parameters, member fields, definitions, and calls while preserving four-byte x86 argument slots and byte return behavior.
- [x] Remove the unsupported handwritten source-size typedef/assert and keep exact `0x110` proof in documentation and IDA analysis only.
- [x] Provide a mandatory-schema Claim And Incorporation Ledger with separate rows for seven function actions and two type actions.
- [x] Provide a mandatory-schema Function / Child Inventory with UID/path, reconstructable state, direct parent, score, and status for every method and compiler range.
- [x] Provide exact target/support metadata, score, formal CPP/H, owner/emitter, split/range, ignored-range, coverage, IDA, validator, and lifecycle handoffs.
- [x] Resolve all in-scope open questions rather than deferring helper investigation.
- [x] Retain UID0000CM at `87/88` and preserve UID0000NF's newer current `91/90`; do not use this bounded helper pass to claim unrelated whole-class/file score increases.
- [x] Re-run the complete exact physical manual preflight against current by-memory SHA `BB5E391E0198251142EC7BA4907D524E9ABCC80A5A2DFB0EBA53CE3F93802E20`, by-class SHA `EB1ADFEAD1D3702137748D16942EF1AA2A4A39637C24FB9EA1230172B2FA41C5`, and by-file SHA `BDB85AA42D17E235E4C449A520DA2120D609247F0690ADC708B30121E995C83E`; confirm `20` literal applicable operations (`15` inserts/`5` replacements), exact current anchors, and one byte-identical UID0000NF no-op.
- [x] Stage a complete destination-ready ordinary-document payload for each of the six children, explicitly covering exact Item Summary, range/boundaries, behavior/data flow, callers/callees/xrefs, owner/emitter/source placement, positive/negative evidence, score/confidence, formal CPP/H, and historical/corrected assumptions.
- [x] Avoid guessed UIDs; register each child by canonical path, read each post-validation first-line UID, and reconcile every identity without provisional UID text.
- [x] Preserve commands through `000000019259` as dated queue provenance; record current tracker command `000000019483`, SHA `A2C97D53EA038671299109D5455954FD909A2DFF0E6BCB9673E8CABD2518DC65`, 1,676,576 bytes/6,632 lines, and exact UID0003A5 line-5544 `93/94`, non-reconstructable row.
- [x] Preserve all earlier CPP/H identities as history; record current command `000000019483` CPP SHA `F3A446D6B85768A8F74FD0456D1D0F864609D55F648241099A6398BC53A856F5` and H SHA `3D2057DC66587D9802C14B862789666A9462622EFDC33BF33D5B630435F67CFC`, exact seven-definition/class-declaration topology, and no UID0003A5 aggregate/empty marker.
- [x] Put all first-draft/example C++ in the formal H/CPP recommendation section, not prose-only pseudocode.
- [x] Record third-party import as explicitly not applicable.
- [x] Preserve historical/rejected alternatives and negative evidence; ignore stale Wave2/Wave3 material.
- [x] Include all 33 required literal report headings and exactly one current lifecycle marker.
- [x] Supervisor accepted exact Gate 1 SHA256 `0EF25C93292AA70A8514AC7EFA8EADC67FAEFD8AD57C35489F4F66AF07329214` and issued the same-report implementation callback.

### Agent-owned implementation callback

- [x] Supervisor recorded Gate 1 acceptance of exact SHA `0EF25C93292AA70A8514AC7EFA8EADC67FAEFD8AD57C35489F4F66AF07329214` and sent the authorized same-report implementation callback.
- [x] [UID:0003A5] is the exact `93/94`, owner-`0000CM`, non-reconstructable/non-emitting split index with blank CPP/H and complete seven-child/range/history/evidence text; command `000000018943` passed.
- [x] Created [UID:0004YF][0x0055d960-0x0055d9d6.ScrollPaneHitTestPart](by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md) from its complete destination payload; command `000000018911` assigned UID0004YF and validated `92/94`, owner/emitter `0000CM`, `Nested:0`, formal CPP, blank H, evidence/history sections, coverage-row prefix replacement, and applied ledger state.
- [x] [UID:0001GK] is validated at `92/94`, direct owner/emitter `0000CM`, `Nested:0`, preserved formal CPP, blank H, and corrected parent/range evidence; command `000000018945` passed.
- [x] Created [UID:0004YI][0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart](by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md) from its complete destination payload; command `000000018914` assigned UID0004YI and validated `92/94`, owner/emitter `0000CM`, `Nested:0`, formal CPP, blank H, evidence/history sections, coverage-row prefix replacement, and applied ledger state.
- [x] Created [UID:0004YJ][0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress](by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md) from its complete destination payload; command `000000018915` assigned UID0004YJ and validated `92/94`, owner/emitter `0000CM`, `Nested:0`, formal CPP, blank H, evidence/history sections, coverage-row prefix replacement, and applied ledger state.
- [x] Created [UID:0004YL][0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart](by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md) from its complete destination payload; command `000000018917` assigned UID0004YL and validated `93/94`, owner/emitter `0000CM`, `Nested:0`, formal CPP, blank H, evidence/history sections, coverage-row prefix replacement, and applied ledger state.
- [x] Created [UID:0004YM][0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor](by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md) from its complete destination payload; command `000000018921` assigned UID0004YM and validated `93/94`, owner/emitter `0000CM`, `Nested:0`, formal CPP, blank H, evidence/history sections, coverage-row prefix replacement, and applied ledger state.
- [x] Created [UID:0004YN][0x0055e600-0x0055e65c.ScrollPaneResetScrollState](by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md) from its complete destination payload; command `000000018932` assigned UID0004YN and validated `92/94`, owner/emitter `0000CM`, `Nested:0`, formal CPP, blank H, evidence/history sections, coverage-row prefix replacement, and applied ledger state.
- [x] [UID:0000CM] received only the bounded formal H one-byte `ScrollPanePart` typedef/typed constants and class declaration, with no source size assertion, while retaining `87/88`, owner/emitter `0000NF`, unrelated history, and no invented callable API for the no-route `+0xfa` setter; command `000000018960` passed.
- [x] [UID:000433] received exact Y-first formal helper calls/evidence and `91/93` metadata; command `000000018964` passed.
- [x] [UID:000435] received resolved [UID:0004YL] wording while retaining accepted timer behavior, owner/emitter route, and `88/90`; command `000000018970` passed.
- [x] [UID:0000NF] received only stale-helper/source-route reconciliation and preserved newer current `91/90`; command `000000018974` passed.
- [x] [UID:0001GJ] remains the `89/91` non-emitting mixed/no-owner corridor while recording the complete generic ScrollPane split; command `000000018982` passed.
- [x] [UID:0001GI], [UID:0001GL], and [UID:0003CQ] were inspected read-only; none described these seven helpers as pending/unresolved in a way requiring change, so their ownership and unrelated behavior remain unchanged.
- [x] [UID:0000VN] `by-memory/-ignored.md` received every exact alignment/NOP/switch-tail range, including `[0x0055e65c,0x0055e660)`, without treating the internal jump table as ordinary padding or handwritten source; command `000000018983` passed with only the shared file's pre-existing nonfatal missing-reference warnings.
- [x] After each new child validated, read its assigned first-line UID and reconcile every matching temporary/path reference in the ledger, inventory, checklist, and manual-coverage staging to that literal UID.
- [x] Added exact `TARGET-REPORT-ADDITIONAL-UIDS:0004YF,0004YI,0004YJ,0004YL,0004YM,0004YN` and reconciled Target/inventory/ledger/checklist/manual rows.
- [x] Verified the same report has zero provisional child-identity tokens and every child reference uses its literal assigned UID/path.
- [x] Reconciled every Claim And Incorporation Ledger row and every per-UID checklist row to actual state without dropping negative/historical evidence; only supervisor-owned manual coverage rows remain proposed.
- [x] Ran the initial 14 serial scoped validators and the final 11 serial post-Gate2B reconciliation validators with `--apply --queue-timeout 240 --no-generated-refresh`; every command/path/timestamp/exit/ok/warning/side effect is recorded above.
- [x] Preserved dated generated identities as history, recorded current command-`000000019483` generated identities/topology, and kept later artifact-specific readback conditional on physical advancement; ordinary docs prove exact formal definitions/declarations, non-emitting UID0003A5, and corrected Y-first caller source.
- [x] Released every short-lived ordinary-file lease immediately after validation; the report lease is released after this exact-artifact self-check.
- [x] Re-read exact current ordinary pages and manual rows for UID0001GH, UID0001GI, and UID0001GJ; proved all three current manual rows stale and staged one literal replacement operation plus one atomic ledger/checklist mapping for each without editing coverage.
- [x] Returned the same additive report with exact ordinary hashes, validation proof, updated ledger/checklist, `20` applicable manual operations, one no-op, and one fresh Gate 1 review marker.

### Supervisor-applied Gate 2B; remaining coverage, generated, catalog, and lifecycle

- [ ] Fresh Gate 1: audit this exact post-Gate2B reconciliation artifact, including all 20 atomic coverage operations and UID0000NF no-op.
- [ ] Verify every agent-owned change claim and every UID row against ordinary files, metadata, formals, hashes, validators, and generated readback (Gate 2A).
- [x] Supervisor captured all seven collision/function/frame/comment prestates and both absent-type prestates, protected dependencies/bytes/xrefs/fences/adjacent functions, and created backup SHA `E9600F...` before mutation.
- [x] Supervisor applied and verified IDA-F1 `ScrollPane__HitTestPart` exact name/type/function-repeatable comment; other comment channels remain blank and dependencies are preserved.
- [x] Supervisor applied and verified IDA-F2 `ScrollPane__GetScrollPartRect` exact name/void type/function-repeatable comment and normalized `part`/output presentation.
- [x] Supervisor applied and verified IDA-F3 `ScrollPane__SetHighlightedPart` exact name/void type/function-repeatable comment and one-byte part entry.
- [x] Supervisor applied and verified IDA-F4 `ScrollPane__BeginPartPress` exact receiver/name/type/function-repeatable comment and normalized part/Y/X entries.
- [x] Supervisor applied and verified IDA-F5 `ScrollPane__ProcessActivePart` exact name/type/function-repeatable comment while preserving the switch tail and fences.
- [x] Supervisor applied and verified IDA-F6 `ScrollPane__UpdatePositionFromCursor` exact name/type/function-repeatable comment and normalized Y/X entries.
- [x] Supervisor applied and verified IDA-F7 `ScrollPane__ResetScrollState` exact name/void type/function-repeatable comment and successor fence.
- [x] Supervisor applied and verified IDA-T1 exact `ScrollPanePart` target `signed __int8`, size `0x1`, all part-bearing types/fields, and no conflicting enum.
- [x] Supervisor applied and verified IDA-T2 exact `ScrollPane` UDT size `0x110`, 13 members, `Pane Pane_base`, exact tail fields/pads, and preserved dependencies.
- [x] Supervisor saved and cataloged Gate 2B as entry `0359`; first verified save `08D31F...` and bounded current authoritative `412DA7E8...` no-drift readback are recorded.
- [ ] COV-GH: replace UID0001GH in place with the exact `88%`, non-reconstructable split-index row, then retain it as parent anchor for UID000433/UID000435.
- [ ] COV-GI: replace UID0001GI in place with the exact `88%` reconstructable ScrollPaneOnDraw row between the existing adjacent ignored fences.
- [ ] COV-GJ: replace UID0001GJ in place with the exact `89%`, non-reconstructable mixed-corridor row ending at `0x005654ec`, then retain it as parent anchor for UID0003A5.
- [ ] Insert the literal UID000433 by-memory row immediately beneath replaced UID0001GH and before UID000435.
- [ ] Insert the literal UID000435 by-memory row immediately after UID000433 and before existing `[0x0055c643,0x0055c650)`.
- [ ] Insert the literal UID0003A5 by-memory split-index row immediately beneath replaced UID0001GJ and before its finalized nested ScrollPane sequence.
- [ ] Insert the literal UID0004YF by-memory child row immediately beneath UID0003A5 and before `[0x0055d9d6,0x0055d9e0)`.
- [ ] Insert the literal [UID:0000VN] `[0x0055d9d6,0x0055d9e0)` alignment row immediately after UID0004YF.
- [ ] Replace UID0001GK in place with the literal `92%` reconstructable direct ScrollPane method row immediately after `[0x0055d9d6,0x0055d9e0)`.
- [ ] Insert the literal [UID:0000VN] `[0x0055de99,0x0055dea0)` alignment row immediately after replaced UID0001GK.
- [ ] Insert the literal UID0004YI by-memory child row immediately after `[0x0055de99,0x0055dea0)` and before UID0004YJ.
- [ ] Insert the literal UID0004YJ by-memory child row immediately after UID0004YI and before `[0x0055dfcf,0x0055dfd0)`.
- [ ] Insert the literal [UID:0000VN] `[0x0055dfcf,0x0055dfd0)` alignment row immediately after UID0004YJ.
- [ ] Insert the literal UID0004YL by-memory child row immediately after `[0x0055dfcf,0x0055dfd0)` and before `[0x0055e1ed,0x0055e210)`.
- [ ] Insert the literal [UID:0000VN] `[0x0055e1ed,0x0055e210)` compiler switch-tail/alignment row immediately after UID0004YL.
- [ ] Insert the literal UID0004YM by-memory child row immediately after `[0x0055e1ed,0x0055e210)` and before `[0x0055e5f6,0x0055e600)`.
- [ ] Insert the literal [UID:0000VN] `[0x0055e5f6,0x0055e600)` alignment row immediately after UID0004YM.
- [ ] Insert the literal UID0004YN by-memory child row immediately after `[0x0055e5f6,0x0055e600)` and before `[0x0055e65c,0x0055e660)`.
- [ ] Insert the literal [UID:0000VN] `[0x0055e65c,0x0055e660)` successor-fence row immediately after UID0004YN and before UID0001GL.
- [ ] Replace the literal UID0000CM by-class coverage row in place at retained `87%` with the accepted bounded ScrollPane class description.
- [ ] Verify the literal UID0000NF by-file row remains byte-identical; perform no replacement.
- [ ] Validate every changed coverage report serially and perform authoritative final generated/current-state readback.
- [x] Record third-party import handling as `N/A`: no `third_party_embeds` directive is relevant to these project-authored ScrollPane methods.
- [x] Keep report execution/archive wording lifecycle-neutral: current truth is authoritative only from the report's current path plus validator-owned status/history metadata, and only the supervisor may perform the validator-controlled lifecycle.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"additional_uids":["0004YF","0004YI","0004YJ","0004YL","0004YM","0004YN"],"agent":"B005","command_id":"000000019753","destination_path":"executed-b-agent-research/B005/0003A5-ScrollPaneInputGeometryHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003A5-ScrollPaneInputGeometryHelpers-source-quality.md","timestamp":"2026-07-29T15:36:17-04:00","uid":"0003A5"} -->
<!-- {"additional_uids":["0004YF","0004YI","0004YJ","0004YL","0004YM","0004YN"],"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003A5-ScrollPaneInputGeometryHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0003A5-ScrollPaneInputGeometryHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003A5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
