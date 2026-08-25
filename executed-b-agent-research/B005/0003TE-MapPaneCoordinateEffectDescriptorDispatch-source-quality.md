** TARGET-REPORT-UID:0003TE **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0003TE MapPaneCoordinateEffectDescriptorDispatch Source-Quality Research


## Finalized Report / Current Recommendation

- Completed implementation callback: [UID:0003TE] is now `92/94`; owner/emitter [UID:00007Q], `RECONSTRUCTABLE:TRUE`, blank position, exact range, and `Nested:0` are preserved, and Destination 1 replaces the former blank managed body.
- Source disposition: one source-authored private `MapPane::RequestCoordinateEffect` method in `NexusTK/map/MapPane.cpp`; no split, merge, raw-helper, duplicate-inline, compiler-only, new-file, or alternate-owner disposition is supported.
- Declaration closure: Destination 2 preserves the complete current MapPane declaration while replacing the incomplete `struct MapRect;` forward declaration with the evidence-backed `typedef RectBounds MapRect;` alias, adding the one private target declaration, and correcting the create helper's machine-proven row-before-column contract.
- Exact behavior: reject coordinates outside the clamped visible tile rectangle; copy one 52-byte `EffectInfo`; process secondary before primary; reverse-scan the matching ObjectList row bucket; match column, effect id, and looping state; reuse through UID0003TG or create through UID0003TF with null target, sequence `0`/`1`, and unchanged render-after flag.
- Callback state: C3TE-001 through C3TE-045 are terminal (`40 applied`, `3 already-present`, `2 excluded-with-reason`, `0 blocked`), all 41 checklist rows are checked with zero unchecked, and all four managed blocks retain byte-for-byte current destination parity. B005's historical callback changed and scoped-validated exactly 15 ordinary pages; final waited command `000000013397` verified MapPane.cpp, and bounded repair command `000000013429` corrected the sole stale UID0001AW signature prose to promoted `int`. B004 then completed the additive UID0003TG callback at exact terminal active-report SHA256 `0EA40ECC140798BCDE44A5AE4B47554C1F6BBE68585A983C545A9EEC9B8BBD88`, preserving the B005 target formals, row-before-column calls, and promoted-`int` signature while updating eight shared destinations. During this read-only rebase the supervisor externally executed that artifact as command `000000013491`; current archive `executed-b-agent-research/B004/0003TG-MapPaneApplyEffectObjectPaneTimerAction-source-quality.md` has lifecycle-footer SHA256 `621067D04483F9E36E227ABDBA87F7D65D4CA8E3CA673F10FB170C6361F14FA1`. Supervisor B003 coverage commands `13492-13496` subsequently advanced all four manual snapshots with unrelated LineIterator/SpelledPane rows, and supervisor B002 commands `13498-13500` advanced by-memory, by-class, and by-file with unrelated ScreenCursor/ScreenPane/Application rows. Supervisor Gate 1/Gate 2 then passed exact report SHA256 `CA69F3634F896061527FB1B20DAA2B037051F46E09A1B3E5742C2F7ED859CC11` and applied this report's exact ten-row no-loss manual handoff with commands `13503`, `13504`, `13506`, and `13507`, each exit `0`/`ok:1`. Direct current readback proves `10/10` exact row parity and all 18 placements current. A later unrelated external shared-lane update advanced MapPane class/file, UID0001AW, and generated MapPane.cpp to command `13515`; it preserves every UID0003TE/UID0003TF/UID000232/UID0003TG fact and only supersedes the unrelated HitBar helper declaration in the complete MapPane union. This report-only rebase changed no ordinary page. Every checklist item remains complete and all B005/B004 leases are released. Manual coverage, tracker, generated C++, audit, supervisor, IDA, and lifecycle state were not manually edited by B005.
- Remaining in-scope unresolved blocker count: `0`. Exact original lexical spellings remain unavailable and cap confidence, but the ranked names/types are sufficient for source-ready reconstruction.

## Supporting Research

- Authoritative workspace: `E:\NTK\GhidraBridge\source-3\project-documentation`. The legacy `E:\NTK\GhidraBridge\tools\leaser\Agents` tree was neither read nor written.
- Fresh IDA MCP discovery returned active/adopted NexusTK database session `64c11373`, worker PID `21508`, `is_analyzing:false`. Evidence-time `server_health` was `ok`, imagebase `0x400000`, with auto-analysis, Hex-Rays, and the 2067-entry strings cache ready.
- Exact old-report search terms: `0003TE`, `0x0050e850`, `MapPaneCoordinateEffectDescriptorDispatch`, `sub_50E850`, `RequestCoordinateEffect`, `RequestPositionEffect`, `RequestObjectEffect`, `GetSecondaryRowBucket`, and `EffectInfo`.
- Search roots checked read-only: central `executed-b-agent-research/**`; active `tools/leaser/Agents/Agent-B*/research/**`; legacy `archived/**`; `tools/leaser/Agents/Older-Research/**`; and `tools/leaser/Agents/SpecialReports/**`.
- Matching reports opened and classified:
  - `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-audit.md`: direct early split lead; stale provisional end/name and no final target body.
  - `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch2.md`: direct predecessor-padding and next-function proof; target itself remained unsplit at that stage.
  - `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch3.md`: direct target creation/range/owner/caller/callee provenance; final body and names intentionally deferred there.
  - `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch4.md`, `batch6.md`, `batch7.md`, and `batch8.md`: incidental-to-direct parent/caller inventory; useful for the packet-handler family and UID0003TO route, but their `compactFlag`, generic coordinate names, and blank-body status are superseded by current evidence.
  - `executed-b-agent-research/B003/00023H-LivingObjectPaneGetEntityId-source-quality.md`: incidental field/accessor correction; proves `EffectObjectPane::IsLooping` at `0x00538bb0` rather than the stale generic gate label.
  - `executed-b-agent-research/B007/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`: direct sibling naming lead; explicitly ranks `RequestCoordinateEffect` and `RequestPositionEffect` for UID0003TE.
  - `executed-b-agent-research/B008/000232-MapPaneObjectEffectDescriptorDispatch-source-quality.md`: direct sibling lead; its `ApplyObjectEffect` alternative is superseded by the accepted `RequestObjectEffect` family.
  - `executed-b-agent-research/B012/0001D2-MapPaneSpatialIndex-source-quality.md`: incidental but useful ObjectList primary/secondary row-bucket source contract.
  - `executed-b-agent-research/B002/0003TC-MapPaneApplyHitBarObjectPane-source-quality.md`, `B002/0001DA-EffectObjectPaneStartIdleTimer-source-quality.md`, `B004/0000L3-MapPane-empty-emitter-family-source-quality.md`, and terminal `executed-b-agent-research/B001/0003TF-MapPaneCreateEffectObjectPane-source-quality.md`: incidental support for MapPane ownership, List pointer-slot access, create/timer behavior, and current adjacent-source integration. The B001 artifact was executed by validator command `000000013371` at `2026-07-15T18:17:15-04:00`; its archived SHA256 is `EE9B4615A285E38B8BD47A043755C65CA455F94E848C399708653993FADADB46`.
- No dedicated prior `0003TE-...-source-quality.md` report exists in any searched root. The B001 split report is direct historical provenance, not a prior source-quality closure.
- Coordination state: B001's UID0003TF callback is terminal and centrally archived after validator command `000000013371`. During this completed callback B005 reread that exact archive and each current shared page after short lease acquisition, preserved the full B001/current union, and applied the exact Destinations 2-4 correction: all four callers and the constructor now use the machine-proven row-before-column contract.

## Target

- UID/path: [UID:0003TE] `by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md`.
- Queue evidence: `auto-generated/-ag-research-tracker.md` line 1566, Not-Covered Files - Reconstructable, `86/89`, combined `87.5`, zero reports, no assigned agent at selection time.
- Exact machine range: `[0x0050e850,0x0050ea30)`, 480 bytes (`0x1e0`).
- Current metadata: completion `92`, confidence `94`, owner/emitter `00007Q`, reconstructable true, blank position, complete Destination 1 formal body, `Nested:0`.
- Historical pre-callback metadata was `86/89` with the same owner/emitter/reconstructability/position/range/nesting and a blank formal body.
- Current target artifact after the additive B004 dependency synchronization: SHA256 `7372658F26E4D67026821535D4B9247A9FAD8C0C8DD40BE2B328255DFE620DD3`, 21,246 bytes, 235 physical lines. Historical B005 post-callback SHA256 was `85D081A4537E823E1060F69DCB78B44264945F579A3441650193`; historical accepted baseline SHA256 was `56B2F9848E1FDE34790B3D611A55AEEBB1170BCCA8AF25495C4051655B942D40`.

## Current Target State

- The target page now records the exact range, bytes/hash, CFG/ABI, one packet-handler caller, exact packet fields, clamped half-open gate, 52-byte EffectInfo copy, secondary-before-primary reverse row-bucket scans, match/reuse/create semantics, source route, score rationale, negative evidence, complete `MapPane::RequestCoordinateEffect` body, and B004's exact source-ready UID0003TG signed existing-pane action dependency.
- All former blockers are resolved in current documentation: Destination 1 supplies the body and argument names; Destination 2 supplies `typedef RectBounds MapRect` plus the private declaration; semantic helper names replace raw addresses; the four exact create callsites use row before column; and UID0001AW now states the same promoted `int mapColumn, int mapRow` target signature as the accepted ABI, target formal, and MapPane declaration.
- Current generated `MapPane.cpp` is external validator command `000000013515`, refreshed `2026-07-15T21:17:18-04:00`, SHA256 `0E2FC02FE45981F395CE3967FC06F20CCCDB050832AF55B2A412E16D0D5D4E5A`, 103,866 bytes, 3,043 lines. It has one complete UID00007Q class, one UID0003TE declaration/definition and no target marker, preserved UID000232/UID0003TF definitions and exact row-before-column calls/constructor, plus one source-ready UID0003TG declaration/definition and no UID0003TG marker. B005 waited command `13397`, B004 waited command `13477`, and external command `13487` remain historical proof; command `13515` is the current external generated checkpoint.
- Current class state remains `93/94`. Its complete managed declaration uses the accepted `typedef RectBounds MapRect;`, includes one private `RequestCoordinateEffect` declaration, preserves the full same-or-greater B001/B002/B004/current union and size guard, and carries the later unrelated source-ready `CreateHitBarObjectPane(... unsigned short ...)` declaration without changing any B005 target method.
- The B001 behavior, receiver, descriptor, timer, registration, and rendering union remains preserved; only the machine-disproved create-helper column/row labels and calls were corrected to row before column in Destinations 2-4 and synchronized support prose. The bounded UID0001AW repair changed only its stale target declaration from `short` parameters to the machine-proven promoted `int` signature. B004 subsequently added exact source-delete/no-op/cancel/all-signed-action/guard/query/compare/reschedule semantics and the inferred default-false `m_timerExtensionLocked` dependency without changing any B005 formal or call order.
- Current manual coverage includes the complete externally applied B004/B005 union. UID0003TG is `92%`, its successor-padding row is present, and the B004 UID0001D9/MapPane/EffectObjectPane facts remain preserved. Supervisor B003 and B002 additions remain intact. Supervisor commands `13503`, `13504`, `13506`, and `13507` applied all ten B005 target/order/consumer replacement or insertion rows exactly: UID0003TE is now `92%`, UID0003TO is present, and every fuller class/file/type union is current. B005 did not edit those restricted files; the exact 18-row matrix below records `10/10` applied rows plus eight verify-only/current dispositions.

## Executive Recommendation

- Use source name `MapPane::RequestCoordinateEffect`, parallel to accepted `RequestObjectEffect`. `Coordinate` is preferred over `Position` because both integer arguments are map column/row coordinates and the subsystem also has screen positions, viewport positions, and ObjectPane positions.
- Use exact arguments `int mapColumn`, `int mapRow`, `int effectDescriptorId`, `int timerAction`, and `bool renderAfterLivingObjects`. The caller's uint16/int16 reads are promoted to this five-dword thiscall stack contract; the final `retn 0x14` proves five stack arguments.
- Use `MapRect visibleBounds` through `typedef RectBounds MapRect`; preserve `PointInRect(mapRow, mapColumn, &visibleBounds)` y/x order and half-open bounds.
- Copy `EffectInfo` before both passes. Process `secondaryFrameCount/secondaryRangeStart/secondaryRangeEnd` first with `GetSecondaryRowBucket`, then the primary fields with `GetPrimaryRowBucket`.
- Reverse-scan List pointer slots. Do not add a null-element guard: the binary dereferences each returned slot and pane before comparison.
- Reuse only when the pane's column equals `mapColumn`, `m_effectId` equals `effectInfo.effectKeyOrId`, and `IsLooping()` is true. The binary does not compare row because row already selected the bucket.
- On no match or disabled reuse range, call the machine-accurate create contract with null target, `mapRow` before `mapColumn`, the by-value descriptor, timer action, sequence `0`/`1`, and render-after flag.
- Keep source route `NexusTK/map/MapPane.cpp`, owner/emitter UID00007Q, range, nesting, reconstructability, and blank explicit position unchanged.

## Supervisor Active Recheck

- Supervisor Gate 1 accepted exact pre-callback SHA256 `4A5AB19326227C85544722E7497E0C115AC5DC05277D0A147F4E57264BA9C4A7`. Independent Gate 2 later found one bounded UID0001AW contradiction; B005 corrected only that signature to promoted `int` under command `13429`. The subsequent shared-lane freshness gate waited for exact terminal B004 active-report SHA256 `0EA40ECC140798BCDE44A5AE4B47554C1F6BBE68585A983C545A9EEC9B8BBD88`, 50 checked/zero unchecked, with zero B004 leases, before this report-only rebase. Supervisor execution command `13491` then moved that same content to the central archive and appended only validator-owned lifecycle history; its current archive hash is `621067D0...4FA1`.
- Supervisor Gate 1/Gate 2 passed exact pre-coverage report SHA256 `CA69F3634F896061527FB1B20DAA2B037051F46E09A1B3E5742C2F7ED859CC11`. The supervisor then applied and validated the exact ten-row manual handoff with commands `13503`/`13504`/`13506`/`13507`, each exit `0`/`ok:1`; current readback is `10/10` exact.
- Split-first check is complete: exact modeled entry, return boundary, predecessor alignment, immediate successor function, one caller, one owner, and coherent CFG all support one retained method.
- Implementation readiness check is complete: target body, complete class declaration/MapRect alias, corrected UID0003TF create body, corrected UID000232 caller body, exact support prose, manual coverage handoff, validator plan, generated assertions, and concurrent rebase ordering are all destination-specific.
- Restricted-state check is complete: B005 used short one-file leases and authorized scoped validators, then released every lease. B005 did not manually edit coverage/generated/tracker/audit/supervisor/validator/lifecycle state, mutate IDA, run/probe `execute_report`, or move/archive the report.

## Inference Research Guidance Check

- Direct facts, current documentation, and inference are separated throughout this report.
- All generated `sub_*`, `a*`, `v*`, `_DWORD`, offset-index, and cookie/EH forms are rejected from final source.
- Human source uses existing project types and names: MapPane, MapRect/RectBounds, EffectInfo, ObjectList, List, MapPoint, EffectObjectPane, `GetPrimaryRowBucket`, `GetSecondaryRowBucket`, `GetMapPosition`, `IsLooping`, `ApplyEffectObjectPaneTimerAction`, and `CreateEffectObjectPane`.
- Exact original lexical spelling is stripped. Names are ranked by sibling source consistency, argument semantics, field lifecycle, and call relationships rather than asserted as recovered symbols.
- Mid-2000s source shape is ordinary explicit C++ with null constants, simple local structs/pointers, backward index loops, and no modern range algorithms, lambdas, smart pointers, `auto`, or ABI scaffolding.
- Wave2/Wave3 material was not used as evidence. Historical generic labels are retained only as superseded search provenance.

## Heuristic / Inference Reanalysis And Validation

### Source name

- `RequestCoordinateEffect` ranks first. It forms a precise pair with accepted `RequestObjectEffect`, covers reuse/create/cancel/timer/no-op outcomes better than `Apply*`, and distinguishes map coordinates from object/screen positions.
- `RequestPositionEffect` ranks second. B007 identified it as plausible, but `Position` is overloaded throughout MapPane and ObjectPane, while the caller supplies independent column and row packet fields.
- `ApplyCoordinateEffect`, `MapPaneCoordinateEffectDescriptorDispatch`, and `sub_50E850` are rejected as overly narrow, descriptive, or tool-generated.

### Types and declarations

- Five stack dwords plus `ECX` establish a nonstatic member taking five promoted source parameters. The caller's signed/unsigned 16-bit packet reads feed `int` parameters, while the descriptor-range predicate becomes a source `bool` final parameter.
- The local descriptor is exact `EffectInfo`, 52 bytes, copied by the accepted accessor. Its source fields consumed here are already declared.
- The row buckets are exact `List *` returned by ObjectList primary/secondary accessors. `GetElementAt` returns element storage, so the source must dereference `EffectObjectPane **` rather than cast the storage directly to an object.
- `MapPoint` is exact row at `+0` and column at `+4`; the target compares only `position.column` because row membership is established by the selected bucket.
- MapRect and RectBounds are not two proven source layouts. All current uses agree on the same 16-byte left/top/right/bottom half-open shape, and the target passes the clamped bounds object directly to RectBounds `PointInRect`. A typedef alias is more plausible and safer than duplicate structs or a cast.
- `CreateEffectObjectPane` receives target at frame `+0x08`, map row at `+0x0c`, and map column at `+0x10`. UID0003TE pushes its `mapRow` second-to-last and `mapColumn` third-to-last before null target; UID000232 pushes `MapPoint::column` first and `MapPoint::row` next so the callee sees row then column. The EffectObjectPane constructor then calls ObjectPane construction with its column argument followed by row, proving the source helper/constructor parameters are row then column even though the current B001 source block labels them oppositely.

### Control flow and exactness

- The visible-bounds gate occurs before descriptor lookup and all list/create/timer effects.
- A positive frame count enables each family. Negative range start or end skips reuse only; it does not suppress creation.
- Reverse scans begin at `GetCount() - 1` and stop at the first matching looping pane.
- Secondary work is complete before primary work begins. Each family can independently reuse or create.
- No null checks exist for `m_objectList`, bucket pointers, List slots, or EffectObjectPane elements; adding them would change malformed-state behavior.
- No row comparison is needed after row-bucket selection. Adding one would be redundant source and could alter behavior if list invariants are violated.

### Score blocker closure

- Boundary/split blocker: closed by modeled size, byte hash, predecessor padding, successor entry, and final `retn 0x14`.
- Caller/argument blocker: closed by UID0003TO decompile and exact packet offsets/promotions.
- Helper-name blocker: closed by current source-ready support pages and helper bodies.
- List/type blocker: closed by ObjectList/List formals and pointer-slot ABI.
- Field blocker: closed by EffectInfo, MapPoint, and EffectObjectPane current declarations.
- MapRect compile blocker: closed by the applied Destination 2 alias, which preserves layout and existing signatures.
- Source-name blocker: closed by ranked sibling-consistent `RequestCoordinateEffect`; exact spelling remains a confidence cap only.
- Source-placement blocker: closed by MapPane receiver, only caller, adjacent methods, class emitter, and existing file route.
- Adjacent create-helper coordinate-order blocker: closed by all four call-site push sequences, exact GetMapPosition layout, create-helper frame offsets, and EffectObjectPane-to-ObjectPane constructor forwarding; Destinations 2-4 correct the current source transposition.

## Evidence Standards Used

- Highest weight: current live IDA MCP lookups, bytes, decompilation, CFG, xrefs, exact caller/callee addresses, and established ABI cleanup.
- High weight: current managed C++ declarations and source-ready support docs whose behavior independently matches the target's machine use.
- Medium weight: current generated output as emitter/order/compile-surface evidence; it is not authority for unresolved names.
- Lead-only weight: old reports and historical docs, independently checked before use.
- Inference threshold: source-facing names/types require agreement among at least two of sibling terminology, call semantics, field lifecycle, class ownership, source route, and machine lowering.
- Negative evidence is used to reject alternatives, not to prove source absence by itself.

## Evidence Checked

- Read current target, MapPane class/file, parent UID0001AW, caller UID0003TO, sibling UID000232, creator UID0003TF, source-ready timer-action UID0003TG, clamped-bounds UID000420, ObjectList accessor UID0001D2, EffectInfo, EffectObjectPane, ObjectPane GetMapPosition UID0003XP, MapPoint, ObjectList, List, `g_pEffectObjImageLib`, ignored padding, current generated MapPane.cpp, tracker, all four manual coverage neighborhoods, exact terminal B004 active-report SHA256 `0EA40ECC...BBD88`, and its current command-`13491` archive/hash `621067D0...4FA1`.
- Fresh MCP calls against database `64c11373`: `idb_list`, `server_health`, batch `lookup_funcs`, `get_bytes`, `analyze_function(0x0050e850)`, `xrefs_to`, full bounded target/UID000232 disassembly, and bounded decompilation of `0x00511c90`, `0x00505290`, `0x004b7e80`, `0x00532550`, `0x005325b0`, `0x005374d0`, `0x00538bb0`, `0x0050e320`, `0x0050ea30`, `0x005387b0`, and `0x005388c0`.
- Exact target bytes: 480 bytes, first 16 `55 8b ec 83 ec 58 a1 24 2f 67 00 33 c5 89 45 fc`, last 16 `5f 5e 33 cd 5b e8 05 8d 0b 00 8b e5 5d c2 14 00`, SHA256 `A8B3951BA69C1AC4553004561FE2AF23ECFAAAB21C50824556DBBABFDD90C194`.
- Exact predecessor bytes `[0x0050e848,0x0050e850)` are eight `0xcc`; successor begins with a separate prologue at `0x0050ea30`.
- Report search roots/terms/matches are recorded under Supporting Research. No match was treated as proof without current corroboration.
- Historical report-only fact: no implementation validator was run before Gate 1, as required at that phase.
- Completed callback evidence: B005 reread the terminal B001 archive SHA256 `EE9B4615A285E38B8BD47A043755C65CA455F94E848C399708653993FADADB46`, reread each destination after its short lease, applied the accepted no-loss union, and ran scoped commands `000000013374`, `13375`, `13376`, `13378`, `13382`, `13384`, `13387`, and `13389` through `13397` as itemized under Validator Results. Every changed ordinary page returned exit `0`, `ok:1`; command `13397` completed the final waited generated refresh.
- Post-B004 ordinary and post-coverage manual read-only verification covered all 15 current destination hashes, all four report-to-destination formal blocks after no-loss rebasing of the unrelated current MapPane method declaration, current source-ready UID0003TG, verify-only `g_pEffectObjImageLib` and ObjectList/List, ignored padding, the four command-`13503`/`13504`/`13506`/`13507` manual snapshots, all 18 rows/placements, and current command-`13515` generated MapPane.cpp counts/order/scaffolding exclusions. A case-insensitive scan across all 15 accepted destinations found no current `RequestCoordinateEffect(short ...)`, `short mapColumn`, or `short mapRow` declaration. Exact manual handoff parity is `10/10`; this report-only readback ran no validator and changed no ordinary or restricted file.

## Claim And Incorporation Ledger

| ID | Claim | Evidence | Action | Destination | Verification state |
| --- | --- | --- | --- | --- | --- |
| C3TE-001 | Target is one modeled 480-byte function at `[0x0050e850,0x0050ea30)`. | lookup/bytes/analyze | incorporate | UID0003TE | applied |
| C3TE-002 | Full target byte SHA256 is `A8B395...C194`. | live get_bytes | incorporate | UID0003TE | applied |
| C3TE-003 | Eight-byte predecessor is alignment and successor starts separately at `0x0050ea30`. | bytes/lookups | already-present | UID0003TE/ignored | already-present |
| C3TE-004 | CFG has 26 blocks and complexity 17. | analyze_function | incorporate | UID0003TE | applied |
| C3TE-005 | ABI is thiscall with five promoted stack arguments and `retn 0x14`. | decompile/disasm | incorporate | UID0003TE | applied |
| C3TE-006 | Only direct caller is UID0003TO at `0x00511d51`. | xrefs/analyze | incorporate | UID0003TE/UID0003TO | applied |
| C3TE-007 | Caller packet fields are object id +1, descriptor +5, timer action +7, column +9, row +11. | caller decompile | incorporate | UID0003TO/UID0003TE | applied |
| C3TE-008 | Descriptor 160..162 alone sets render-after flag. | caller decompile | incorporate | UID0003TO/UID0003TE | applied |
| C3TE-009 | Object id zero selects coordinate target; nonzero resolved object selects RequestObjectEffect. | caller decompile | incorporate | UID0003TO | applied |
| C3TE-010 | GetClampedVisibleTileBounds and PointInRect gate all work. | target/helper decompile | incorporate | UID0003TE/UID000420 | applied |
| C3TE-011 | PointInRect source order is row/y then column/x and bounds are half-open. | helper decompile | incorporate | UID0003TE | applied |
| C3TE-012 | EffectInfo copy precedes both passes and uses g_pEffectObjImageLib. | target/xrefs | incorporate | UID0003TE/EffectInfo | applied |
| C3TE-013 | Descriptor is exact 52-byte current EffectInfo. | support/ABI | already-present | EffectInfo | already-present |
| C3TE-014 | Secondary frame count/ranges are consumed before primary fields. | target decompile | incorporate | UID0003TE/EffectInfo | applied |
| C3TE-015 | Positive count enables a pass; negative range disables reuse but not creation. | CFG/decompile | incorporate | UID0003TE | applied |
| C3TE-016 | Secondary uses GetSecondaryRowBucket; primary uses GetPrimaryRowBucket. | helper decompile/xrefs | incorporate | UID0003TE/UID0001D2 | applied |
| C3TE-017 | Row bucket is selected by mapRow through padded ObjectList bounds. | bucket helpers | incorporate | UID0003TE/UID0001D2 | applied |
| C3TE-018 | Each List is reverse-scanned from count minus one. | target decompile | incorporate | UID0003TE | applied |
| C3TE-019 | GetElementAt returns EffectObjectPane pointer storage requiring one dereference. | machine load/List formal | incorporate | UID0003TE | applied |
| C3TE-020 | Binary performs no null checks on list/slot/pane. | disassembly/decompile | incorporate | UID0003TE | applied |
| C3TE-021 | GetMapPosition returns row then column; target compares only column. | helper/MapPoint | incorporate | UID0003TE/UID0003XP/MapPoint | applied |
| C3TE-022 | Reuse requires m_effectId equal effectKeyOrId. | target/field docs | incorporate | UID0003TE/EffectObjectPane/EffectInfo | applied |
| C3TE-023 | Reuse additionally requires IsLooping true. | target/helper | incorporate | UID0003TE/EffectObjectPane | applied |
| C3TE-024 | First reverse-scan match is reused through ApplyEffectObjectPaneTimerAction. | CFG/xrefs | incorporate | UID0003TE | applied |
| C3TE-025 | Miss creates with null LivingObjectPane target. | call ABI/UID0003TF | incorporate | UID0003TE/by-file MapPane | applied |
| C3TE-026 | Secondary create uses sequence 0; primary create uses sequence 1. | callsites | incorporate | UID0003TE | applied |
| C3TE-027 | timerAction and renderAfterLivingObjects pass through unchanged. | caller/target/callee | incorporate | UID0003TE/UID0003TO | applied |
| C3TE-028 | Source name is RequestCoordinateEffect; RequestPositionEffect ranks second. | sibling semantics/history | incorporate | UID0003TE/class/file | applied |
| C3TE-029 | MapPane is sole canonical owner/emitter and MapPane.cpp is source route. | receiver/caller/adjacency/docs | already-present | UID0003TE/class/file | already-present |
| C3TE-030 | No split/merge/raw/duplicate/compiler-only reclassification is supported. | bytes/CFG/xrefs | reject-invalid | UID0003TE | excluded-with-reason |
| C3TE-031 | EffectObjectPane, EffectObjImageLib, ObjectList, List, TimerMgr are dependencies, not target owners. | dependency direction | reject-invalid | UID0003TE | excluded-with-reason |
| C3TE-032 | MapRect should be a RectBounds typedef alias, not an undefined separate struct or raw cast. | layout/use/search | incorporate | by-class/MapPane | applied |
| C3TE-033 | Complete MapPane formal must add one private RequestCoordinateEffect declaration. | compile route | incorporate | by-class/MapPane | applied |
| C3TE-034 | Parent UID0001AW remains blank/non-emitting; its target-row synchronization must use the promoted `int mapColumn, int mapRow` signature. | aggregate policy/ABI parity | incorporate | UID0001AW | applied |
| C3TE-035 | UID0003TO needs exact helper/argument names while retaining blank body/score. | caller evidence | incorporate | UID0003TO | applied |
| C3TE-036 | Clamped bounds, EffectInfo, EffectObjectPane, ObjectList accessors, GetMapPosition, and MapPoint need bounded consumer synchronization only. | current-doc comparison | incorporate | six support docs | applied |
| C3TE-037 | B005 target score should rise only to 92/94; B005 support scores/routes remain unchanged, without constraining later independent support-target callbacks. | blocker audit/lifecycle ordering | incorporate | UID0003TE/support | applied |
| C3TE-038 | Historical compactFlag/type2/type4/Apply/blank-body assumptions are superseded but retained as history. | old/current comparison | historicalize | target/support | applied |
| C3TE-039 | Supervisor commands `13503`/`13504`/`13506`/`13507` applied the exact ten-row no-loss target/support handoff across by-memory, by-class, by-file, and by-type/by-struct coverage. | current manual rows and hashes | incorporate | coverage handoff | applied |
| C3TE-040 | Generated result must have one declaration/definition, no UID0003TE empty marker, correct order, and no ABI/decompiler scaffolding. | emitter policy/current generated | incorporate | validator/generated verification | applied |
| C3TE-041 | Create helper frame/calls prove parameter order target, mapRow, mapColumn, EffectInfo, timer, sequence, render flag. | four callsites/callee frame | incorporate | UID0003TF/class/file | applied |
| C3TE-042 | EffectObjectPane constructor receives row then column and forwards column then row to ObjectPane construction. | constructor decompile | incorporate | UID0003TF/Effects support | applied |
| C3TE-043 | Historical B001 `mapColumn, mapRow` helper declaration/body wording was transposed and required narrow correction without losing accepted work. | machine/source comparison/current readback | reject-stale | UID0003TF/class/file/support | applied |
| C3TE-044 | UID000232 create calls must pass `position.row` then `position.column` to the corrected helper contract. | GetMapPosition/call pushes | incorporate | UID000232 | applied |
| C3TE-045 | Target create calls must pass `mapRow` then `mapColumn` while target's own caller-facing signature remains column then row. | target entry/calls | incorporate | UID0003TE | applied |

Ledger verification notes: all 45 rows are terminal: `40 applied`, `3 already-present`, `2 excluded-with-reason`, `0 blocked`. Claim-specific proof is anchored as follows; the exact current hashes are in Changed Files and every named command returned exit `0`, `ok:1`.

| Claims | Terminal destination proof |
| --- | --- |
| C3TE-001, 002, 004, 005, 011, 015, 018-020, 024, 026, 030, 031, 045 | UID0003TE current SHA `737265...0DD3`; B005 scoped `13374`/waited `13397`; additive B004 dependency sync `13473`; target formal/body and rejected alternatives remain intact. |
| C3TE-003 | Existing ignored row `[0x0050e848,0x0050e850)` remains eight `0xcc`; current `by-memory/-ignored.md` SHA `77F05C...FBB1` includes unrelated concurrent additions while all three B005 MapPane padding entries remain intact; no edit. |
| C3TE-006-009, 027, 035 | UID0003TO current SHA `B76BE9...85D7`; scoped `13384`; blank formal and `86/90` preserved. |
| C3TE-010, 011, 036 | UID000420 current SHA `5AD5E6...A28C`; scoped `13389`; exact formal/`88/90` preserved. |
| C3TE-012-015, 022, 036 | EffectInfo current SHA `B4E50F...F8DE`; scoped `13391`; complete `0x34` formal/`88/90` preserved. Verify-only `g_pEffectObjImageLib` remains SHA `F3EDE8...5316`. |
| C3TE-016, 017, 036 | UID0001D2 current SHA `FBA36D...6174`; scoped `13390`; exact xrefs `0x0050e8c0`/`0x0050e967` and row-bucket semantics added. |
| C3TE-021, 036 | UID0003XP current SHA `127D66...6044`, scoped `13393`; MapPoint current SHA `329517...91D1`, scoped `13394`; row/column formals preserved. |
| C3TE-022, 023, 036, 042 | EffectObjectPane current SHA `AB8BA1...3955`, B005 scoped `13392` plus B004 `13462`; UID0001D9 current SHA `F232D1...B9BA`, B005 `13396` plus B004 `13466`; class comment-only and aggregate blank formals remain preserved with additive `m_timerExtensionLocked` evidence. |
| C3TE-025, 028, 029, 032, 033, 037, 041, 043 | MapPane class current SHA `81E3DA...2652`, B005 scoped `13375` plus B004 `13455`; MapPane file current SHA `58EC08...9E47`, B005 `13382` plus B004 `13459`; complete Destination 2/source route and additive source-ready UID0003TG union remain verified after an unrelated external HitBar declaration/source-inventory update. |
| C3TE-034 | UID0001AW current SHA `EF0A51...4720`; original scoped `13387` plus bounded Gate 2 repair `13429`; the sole stale current `short` signature remains promoted `int`, while `86/90`, false, blank emitter/formal, the full child union, and later unrelated packet-support additions remain preserved. |
| C3TE-036 | Remaining bounded supports: EffectObjectPane `13392`, UID0003XP `13393`, MapPoint `13394`; all current hashes/formals are listed above and below. |
| C3TE-038 | Superseded `compactFlag`, type-number, transposed-order, GetEffectBounds, blank-target-body, generic-callback, positive-only, and raw-guard assumptions remain labeled historical across the complete B001/B004/B005 union. |
| C3TE-039 | Current post-application hashes: by-memory `B2E77EEA392073D08F0D8925954421629756E7378B12DFE46CFEB8BFAEBB9915`, by-class `54BCD2A27736A7E42095B7263E8C09AB1A37D7133D22C4DCF18443AF04F62665`, by-file `0574FDA2D15298AAB264F3C75115ED82056DE851619F28C00FC297F2B38E761E`, by-struct `269D77A8801F26AAA36F410C842B137973103FE81B55D0BA37C062AE2D16A1E5`; all 18 current row/placement checks preserve B003/B002/B004 facts and confirm the exact B005 handoff `10/10` applied. |
| C3TE-040 | Current external generated command/header `13515`; MapPane.cpp SHA `0E2FC0...4E5A`; B005 declaration/definition/order/scaffolding assertions and B004 UID0003TG source-body assertions all pass. Historical command `13487` remains the earlier complete-union checkpoint. |
| C3TE-041-043 | UID0003TF current SHA `192F03...DBE9`, B005 scoped `13376` plus B004 `13474`; Effects SHA `035840...6436`, B005 `13395`; UID0001D9 B005 `13396` plus B004 `13466`; full B001/B004/B005 union retains row-before-column and constructor-default evidence. |
| C3TE-044 | UID000232 current SHA `4102A5...5055`, B005 scoped `13378` plus B004 `13469`; two `position.row, position.column` calls, zero old-order calls, and exact source-ready UID0003TG dependency remain in generated/current docs. |

## Positive Evidence Summary

- Exact entry/range/return, stable full-byte hash, predecessor padding, and immediate successor prove a complete standalone function.
- One direct caller passes a coherent no-object coordinate effect payload and the sibling object route uses the accepted parallel member.
- Every helper is resolved to a current source-facing API; no raw helper label is required in formal C++.
- EffectInfo fields, MapPoint field order, ObjectList bucket roles, List pointer-slot ABI, EffectObjectPane id/looping fields, and create/timer helper contracts agree independently.
- Secondary-before-primary order and sequence 0/1 are repeated in the target, sibling, creator, constructor, and render semantics.
- Four create call sites, the create-helper frame, MapPoint layout, and EffectObjectPane constructor forwarding independently agree on row-before-column helper arguments and expose the current source transposition.
- MapPane receiver field `m_objectList`, adjacent MapPane methods, class emitter, and current file route all agree on ownership/source placement.
- RectBounds/MapRect shape and direct predicate use support a compile-legal semantic alias with no layout change.

## IDA MCP Facts

- Session `64c11373`; database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; health `ok`; imagebase `0x400000`; analysis/Hex-Rays/strings ready.
- Function lookups: target `sub_50E850` size `0x1e0`; caller `sub_511C90` size `0x11e`; clamped bounds `sub_505290` size `0x74`; point predicate `sub_4B7E80` size `0x27`; descriptor accessor `sub_4DE3E0` size `0x40`; primary/secondary row helpers `sub_532550`/`sub_5325B0`, each `0x5e`; GetMapPosition `sub_5374D0` size `0x1b`; IsLooping `sub_538BB0` size `0x7`; create `sub_50EA30` size `0x15a`; timer action `sub_50EB90` size `0x9e`.
- Target analysis: prototype `void __thiscall(_DWORD **this, int, int, int, int, char)`, 26 basic blocks, cyclomatic complexity 17, one caller, ten semantic callees plus security-cookie check.
- Xrefs: target has one at `0x00511d51`; create helper has four at `0x0050e3ed`, `0x0050e47e`, `0x0050e945`, `0x0050e9e3`; timer helper has four at `0x0050e494`, `0x0050e4a8`, `0x0050ea04`, `0x0050ea18`.
- Primary row helper has target call `0x0050e967`; secondary row helper has target call `0x0050e8c0`. `g_pEffectObjImageLib` has 12 total reads including target `0x0050e893`.
- Caller exact route: object id dword at packet +1, effect descriptor uint16 at +5, timer action int16 at +7, column uint16 at +9, row uint16 at +11, descriptor 134 flash branch, and render-after true only for descriptor 160..162.
- Create ABI: target call sites push render flag, sequence, timer, 52-byte EffectInfo, map column, map row, then target, producing callee frame target `+0x08`, row `+0x0c`, column `+0x10`. UID000232 does the same with MapPoint column/row loads. EffectObjectPane constructor parameters are target, row, column; it forwards column then row into ObjectPane construction.
- Constructor corroboration: `sub_5387B0(this, target, row, column, effectInfo, sequence, renderAfter)` calls `sub_5372D0(this, type, 0, column, row)`. Current ObjectPane source identifies its last two parameters as map X then map Y, independently fixing column then row at the base and therefore row then column at the effect constructor/create helper boundary.
- No MCP call failed or timed out during this bounded evidence pass. No IDA mutation call was issued.

## Function / Child Inventory

| Address/range | Source role | Disposition |
| --- | --- | --- |
| `0x0050e848-0x0050e850` | eight-byte MapPane alignment | existing ignored row; unchanged |
| `0x0050e850-0x0050ea30` | `MapPane::RequestCoordinateEffect` | target; retained source method; Destination 1 |
| `0x0050ea30-0x0050eb8a` | `MapPane::CreateEffectObjectPane` | separate UID0003TF dependency; terminal B001 callback baseline |
| `0x0050eb8a-0x0050eb90` | six-byte alignment | existing B001 manual handoff row; unchanged |
| `0x0050eb90-0x0050ec2e` | `MapPane::ApplyEffectObjectPaneTimerAction` | separate UID0003TG dependency; no target-owned body |

- UID0003TE has no internal source-child split. The two descriptor passes are branches of one member because they share parameters, descriptor local, visible-bounds gate, and return ABI.
- UID0001AW remains a non-emitting split index. This target emits only through UID00007Q and does not cause aggregate C++.

## Direct Xref / Caller Inventory

| Caller/callsite | Relationship | Exact target arguments |
| --- | --- | --- |
| UID0003TO `sub_511C90` at `0x00511d51` | only direct target call | map column, map row, signed descriptor id, signed timer action, render-after bool |
| MapPane packet dispatcher at `0x005082f6` | calls UID0003TO, not target directly | opcode `0x29` route |
| UID0003TQ at `0x00512c04` | reuses UID0003TO, not target directly | nested action visual route |

- There is no vtable slot, data pointer, import, export, or external class caller for the target.
- The absence of additional routes does not make the target dead: UID0003TO's direct call is real, modeled, and packet-reachable.
- UID0003TF and UID0003TG xref sets independently corroborate both target branches and their sibling RequestObjectEffect branches.

## Documentation Evidence And IDA Status

- Historical report-only state: the target was accurate at high level but stale about blank-body necessity and provisional naming. The completed B005 callback superseded that state with the source-ready Destination 1 body and exact `92/94` evidence.
- Historical pre-B005 state: UID0003TF was already behaviorally source-ready at `92/94` under B001, but its formal/source prose transposed the machine-proven row-before-column helper parameters. Applied Destination 3 corrected only that order while preserving null-target coordinate creation, sequence 0/1, by-value EffectInfo, timer sentinels, ObjectList insertion, timer events, bounds invalidation, and the later B004 constructor-default evidence for `m_timerExtensionLocked`.
- Historical pre-B005 state: UID000232's two create calls followed the same transposed declaration. Applied Destination 4 corrected only those calls to row before column; current UID000232 remains source-ready at `92/94` and now also records the later source-ready UID0003TG action-helper dependency.
- Historical B005 scope left UID0003TG blank at `86/90` because its direct body was outside UID0003TE. The later independent B004 callback superseded that state: current UID0003TG is source-ready at `92/94` with a complete ordinary definition preserving null return, source-level delete for `-1`, zero no-op, event-2 cancel for `-2`, all remaining signed actions, inferred `m_timerExtensionLocked`, typed TimerHandler due-tick query/compare/cancel/reschedule behavior, and the original unscaled-compare/`1000 * action` scheduling quirk.
- Current UID0001D2/ObjectList class formals declare `List *GetPrimaryRowBucket(int)` and `List *GetSecondaryRowBucket(int)` and identify their distinct row-list arrays.
- Current EffectInfo formal supplies all target-consumed fields and exact size. Unknown unrelated descriptor scalars remain lexical caps and do not enter target C++.
- Current EffectObjectPane documentation supplies `m_effectId`, `IsLooping`, and B004's inferred default-false `m_timerExtensionLocked` field-role evidence while preserving the comment-only broader declaration; current MapPoint supplies row/column without an invented x/y union.
- Current MapPane class remains complete at `93/94`. Applied Destination 2 is the no-loss declaration union with the MapRect alias, target declaration, and row-before-column create-helper contract; B004 subsequently added the source-ready UID0003TG declaration/behavior inventory without altering Destination 2 bytes or any B005 method signature.
- Historical generated commands `13366`, `13351`, B005 waited `13397`, B004 waited `13477`, and external complete-union `13487` are evidence-time checkpoints. Current external command/header `13515`, hash, metrics, and exact preserved B005/B004 assertions are recorded under Current Target State and Validator Results.
- Historical manual commands `13488-13490` applied the B004 rows. Supervisor B003 commands `13492-13496` then added unrelated LineIterator/SpelledPane coverage, and B002 commands `13498-13500` added unrelated ScreenCursor/ScreenPane/Application rows. Supervisor commands `13503`/`13504`/`13506`/`13507` subsequently applied this report's exact ten-row no-loss handoff. Current readback confirms all 18 B004/B005 rows/placements and `10/10` B005 literal-row parity.

## Ranked Ownership Analysis

### 1. MapPane / NexusTK/map/MapPane.cpp

- Strongly accepted. `ECX` is the same MapPane used by the caller; the function reads MapPane `m_objectList`, calls MapPane bounds/create/timer helpers, sits in the MapPane address family, and has only a MapPane packet-handler caller.
- Existing owner/emitter UID00007Q and file UID0000L3 are correct. No metadata route change is needed.

### 2. EffectObjectPane / Effects.cpp

- Rejected as target owner. EffectObjectPane instances are scanned, queried, reused, or constructed. Their fields/methods are dependencies, while the orchestration and ObjectList row selection are MapPane policy.

### 3. EffectObjImageLib / EffectObjImageLib.cpp

- Rejected as target owner. The library owns EffectInfo resource storage and the copy accessor only. It does not own map visibility, ObjectList buckets, coordinate policy, or timer/create orchestration.

### 4. ObjectList/List

- Rejected as target owner. These classes provide row selection and storage access. They do not own packet arguments, descriptor policy, or effect-pane creation/reuse decisions.

### 5. TimerMgr/TimerHandler or new helper file

- Rejected. Timer behavior is delegated through UID0003TG/UID0003TF, and no static/global/new-file call route exists. A separate file would fragment an established MapPane private method family.

## Source Placement

- Exact source route: `NexusTK/map/MapPane.cpp`, class emitter UID00007Q, source order after UID0003TD and its eight-byte alignment, before UID0003TF and UID0003TG.
- Declaration route: complete MapPane class block before `[[CHILDREN]]`; private declaration near the existing create/timer helpers.
- Definition route: exact UID0003TE child page. Parent UID0001AW remains comment-only to avoid duplicate emission.
- Shared type route: `MapRect` remains the semantic MapPane name but becomes a typedef alias to canonical `RectBounds`; no new type page/file or duplicate layout is justified.
- No third-party source import applies.

## Range / Split / Padding / Reclassification Analysis

- Start `0x0050e850` is a modeled function entry with standard prologue and the only incoming code xref.
- End `0x0050ea30` is exact and end-exclusive. The target ends with `retn 0x14`; the next byte begins UID0003TF's independent prologue.
- Predecessor `[0x0050e848,0x0050e850)` is eight `0xcc` bytes and remains ignored under UID0000VN.
- No interior entry, data island, switch table, EH table, padding seam, tail merge, alternate owner, or raw successor is present.
- The two late epilogues are ordinary branch-specific returns inside the same source function, not separate helpers.
- Keep exact target `Nested:0`. Parent cumulative nesting already accounts for the existing child and no new child page is created.

## Negative Evidence Summary

- No evidence supports EffectObjectPane, EffectObjImageLib, ObjectList, List, TimerMgr, or a new source file as owner.
- No evidence supports a compiler thunk, scalar wrapper, inline duplicate, dead raw helper, or aggregate-only/no-body disposition.
- No string or recovered symbol proves the original target spelling; therefore confidence is `94`, not `100`.
- No type evidence supports two distinct 16-byte MapRect/RectBounds layouts. Keeping an undefined `struct MapRect` or adding a duplicate struct is less source-complete than the alias.
- No null guard exists for List or pane elements; source hardening is rejected.
- No row equality test occurs after bucket selection; adding one is rejected.
- No deletion, list mutation, timer arithmetic, object registration, bounds invalidation, or descriptor ownership occurs directly in this target; those remain delegated.
- No call site supports the current create-helper `mapColumn, mapRow` source order. Treating the names as interchangeable would transpose EffectObjectPane placement and is rejected; all four sites plus constructor forwarding prove row then column.
- Historical `compactFlag`, type-2/type-4, `ApplyObjectEffect`, `ObjectPane *` creator target, `GetEffectBounds`, and generic `sub_*` labels are superseded.

## IDA Rename / Type / Comment Recommendations

- Rename `sub_50E850` to `MapPane::RequestCoordinateEffect` only if a later IDA-maintenance owner chooses to synchronize names. B005 does not mutate IDA.
- Apply source prototype conceptually as a MapPane thiscall member with five parameters: map column, map row, effect descriptor id, timer action, render-after flag.
- Name target locals `visibleBounds`, `effectInfo`, `effects`, `index`, `effectObject`, `position`, and `matchingEffect`.
- Keep helper names aligned to current documentation; do not rename stable support functions under this target.
- Add comments only for non-obvious secondary-before-primary order and range-gated reuse if needed. Do not copy address/offset narration into source.

## First-Draft C++ Recommendation

- Exactly four destination-specific managed blocks are applied. Destination 1 is the complete target definition. Destination 2 is the complete current MapPane declaration union with the MapRect alias, one private target declaration, corrected create-helper parameter order, and the later unrelated source-ready HitBar helper declaration preserved from the current shared union. Destination 3 preserves the complete current UID0003TF body while correcting only row/column parameter and constructor argument order. Destination 4 preserves the complete current UID000232 body while correcting only its two create calls.
- No C++ was added for parent UID0001AW, UID0003TO, or prose-only support destinations.
- Destination 1: `by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::RequestCoordinateEffect(
    int mapColumn,
    int mapRow,
    int effectDescriptorId,
    int timerAction,
    bool renderAfterLivingObjects)
{
    MapRect visibleBounds;
    GetClampedVisibleTileBounds(&visibleBounds);
    if (!PointInRect(mapRow, mapColumn, &visibleBounds))
        return;

    EffectInfo effectInfo;
    EffectObjImageLibGetEffectInfo(&effectInfo, effectDescriptorId);

    if (effectInfo.secondaryFrameCount > 0)
    {
        EffectObjectPane *matchingEffect = NULL;

        if (effectInfo.secondaryRangeStart >= 0 &&
            effectInfo.secondaryRangeEnd >= 0)
        {
            List *effects = m_objectList->GetSecondaryRowBucket(mapRow);
            for (int index = effects->GetCount() - 1; index >= 0; --index)
            {
                EffectObjectPane *effectObject =
                    *static_cast<EffectObjectPane **>(
                        effects->GetElementAt(index));
                MapPoint position;
                effectObject->GetMapPosition(&position);
                if (position.column == mapColumn &&
                    effectObject->m_effectId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping())
                {
                    matchingEffect = effectObject;
                    break;
                }
            }
        }

        if (matchingEffect != NULL)
        {
            ApplyEffectObjectPaneTimerAction(matchingEffect, timerAction);
        }
        else
        {
            CreateEffectObjectPane(
                NULL,
                mapRow,
                mapColumn,
                effectInfo,
                timerAction,
                0,
                renderAfterLivingObjects);
        }
    }

    if (effectInfo.primaryFrameCount > 0)
    {
        EffectObjectPane *matchingEffect = NULL;

        if (effectInfo.primaryRangeStart >= 0 &&
            effectInfo.primaryRangeEnd >= 0)
        {
            List *effects = m_objectList->GetPrimaryRowBucket(mapRow);
            for (int index = effects->GetCount() - 1; index >= 0; --index)
            {
                EffectObjectPane *effectObject =
                    *static_cast<EffectObjectPane **>(
                        effects->GetElementAt(index));
                MapPoint position;
                effectObject->GetMapPosition(&position);
                if (position.column == mapColumn &&
                    effectObject->m_effectId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping())
                {
                    matchingEffect = effectObject;
                    break;
                }
            }
        }

        if (matchingEffect != NULL)
        {
            ApplyEffectObjectPaneTimerAction(matchingEffect, timerAction);
        }
        else
        {
            CreateEffectObjectPane(
                NULL,
                mapRow,
                mapColumn,
                effectInfo,
                timerAction,
                1,
                renderAfterLivingObjects);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 2: `by-class/MapPane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Pane.h"
#include "GrafPort.h"
#include "Motion.h"

#include <vector>

class AlphaMaskSurface;
class Event;
class EffectObjectPane;
class Layer;
class LightingObjectPane;
class LivingObjectPane;
class LObject;
class Message;
class ObjectList;
class ObjectPane;
class ScreenEffecter;
struct EffectInfo;
struct ItemObjectImageEntry;
struct MapTileLayerIds
{
    unsigned int groundTileId;
    unsigned int objectNation;
    unsigned int flags;
};
struct MapPaneTileRecord;
struct MapPoint;
struct RectBounds;
typedef RectBounds MapRect;
struct ObjectStatusBlob;
struct Rect;

class MapPane : public Pane
{
public:
    MapPane(int visibleTileColumns, int visibleTileRows);
    virtual ~MapPane();

    virtual void AddToLayer(
        const RectBounds *bounds,
        int order,
        Pane *parentPane,
        Layer *layer);
    virtual void QueueMotionMessage(const Rect *rect);
    virtual void OnChangeMessage(LObject *sender, Message *message);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnNotifyMessage(const unsigned char *message);
    virtual bool OnTimerEvent(int timerId, int param1, int param2);
    virtual void OnPaint();

    bool HasScreenEffecters() const;
    ScreenEffecter *FindActivePixelEffecter();
    void ResetScreenEffecterListFields();
    void ConfigureScreenEffecterList(signed char effectMode);
    void ClearScreenEffecterList();
    void ExitToMenu(bool notifyServer);
    void LoadCompressedMapFile(unsigned short mapId, int unusedLoadOption);
    void SaveCompressedMapFile();
    void MapToScreenCoords(MapPoint *point) const;
    void ScreenToMapCoords(MapPoint *point) const;
    void RedrawVisibleTiles();
    bool ValidateMapAndViewportCoords(
        int mapColumn,
        int mapRow,
        int viewportColumn,
        int viewportRow) const;
    void GetClampedVisibleTileBounds(MapRect *outBounds) const;
    void GetVisibleTileBounds(MapRect *outBounds) const;
    MapPoint *GetVisibleTileSpan(MapPoint *outSpan) const;
    void GetExtendedVisibleTileBounds(MapRect *outBounds) const;
    int CheckMovementCollision(
        int mapColumn,
        int mapRow,
        unsigned char direction);
    bool AllowsMovementStatusTag() const;
    bool ApplyMovementSubstepScroll(unsigned char direction);
    unsigned short GetAdjacentVisibleTileBounds(
        unsigned char direction,
        MapRect *outBounds) const;
    void AfterLocalPlayerWarp();
    void ObjectCallbackNoOp(ObjectPane *objectPane);
    void ScrollViewportByDirection(unsigned char direction);
    void ReindexObjectPanePosition(
        ObjectPane *objectPane,
        int removeRow,
        int removeColumn,
        int addRow,
        int addColumn);
    void RecenterAndSendPosition(
        int targetX,
        int targetY,
        int viewportX,
        int viewportY,
        bool useActiveObjectViewport);
    void ClearQueuedMapStateRefresh();
    void ClearPendingActionPoll();
    ObjectPane *CreateOrUpdateObjectPane(
        int tileX,
        int tileY,
        int objectId,
        unsigned char action,
        const ObjectStatusBlob &status);
    void RemoveObjectPaneById(int objectId);
    void DetachObjectPane(ObjectPane *objectPane);
    bool HasObjectIntersectingRect(const Rect *rect) const;
    ObjectPane *FindObjectPaneById(int objectId);
    ObjectPane *FindPreviousSelectableObject(ObjectPane *current);
    ObjectPane *FindNextSelectableObject(ObjectPane *current);
    ObjectPane *FindPreviousItemTargetObject(ObjectPane *current);
    ObjectPane *FindNextItemTargetObject(ObjectPane *current);
    ObjectPane *FindPreviousLivingTarget(ObjectPane *current, int targetFilter);
    ObjectPane *FindNextLivingTarget(ObjectPane *current, int targetFilter);
    void RemoveObjectPaneIfPresent(ObjectPane *objectPane);
    void UpdateObjectPaneScreenBounds(ObjectPane *objectPane);
    void UpdateObjectPosition(ObjectPane *objectPane);
    LivingObjectPane *HitTestObjectAtPoint(int y, int x);
    unsigned short GetCurrentMapId() const;
    void RenderMapView();
    void ComputeDayNightBrightnessAndTint(
        unsigned char hour,
        float brightnessScale,
        float brightnessBias,
        float *outBrightness,
        float *outTintAmount) const;
    void SetDayNightFadeTarget(float targetBrightness, float tintAmount);
    void AttachObjectLighting(
        ObjectPane *anchorSource,
        int localOffsetX,
        int localOffsetY,
        int lightImageIndex);
    void RenderDayNightOverlay(const RectBounds *dirtyBounds);
    bool ShouldUseLivingObjectLightOverlay() const;
    bool ShouldOffsetElevatedLivingObjects() const;
    MapPoint *GetObjectScreenPoint(
        ObjectPane *objectPane,
        MapPoint *outPoint) const;
    void FlashMapColor(int drawColor);
    void FinishVisibleObjectRefresh();
    void InteractWithObject(LivingObjectPane *target);
    void CollectMovementTargetObjectIds(
        std::vector<unsigned int> &objectIds) const;
    void SortMovementTargetObjectIdsByDistance(
        std::vector<unsigned int> &objectIds) const;
    void ChangeMap(
        unsigned short mapId,
        short mapWidth,
        short mapHeight,
        unsigned char weatherMode,
        unsigned char transitionState,
        int loadOption);
    void AllocateTileBuffer();
    void RequestObjectEffect(
        unsigned int objectId,
        int effectDescriptorId,
        int timerAction,
        bool renderAfterLivingObjects);
    void RefreshGroupMemberHitBar(unsigned int memberId);
    void ApplyHitBarObjectPane(
        LivingObjectPane *objectPane,
        unsigned int primaryValue,
        unsigned int primaryMaximum,
        unsigned int secondaryValue,
        unsigned int secondaryMaximum);
    void RemoveGroupMemberHitBar(unsigned int memberId);
    bool HandleMapInfoTileRegionPacket(const unsigned char *packet);

private:
    void NotifyDeferredMotionChanged();
    void RefreshQueuedMapState();
    LivingObjectPane *FindObjectAtMapPoint(int y, int x);
    void DrawVisibleTiles();
    void DrawTileAt(int tileX, int tileY, bool refreshStaticObjects);
    unsigned short ComputeTileRectChecksum(const MapRect *bounds) const;
    unsigned int ComputeVisibleTileChecksum(const MapRect &bounds) const;
    MapTileLayerIds *GetLegacyAwareMapTileLayerIds(
        MapTileLayerIds *outTile,
        int mapColumn,
        int mapRow) const;
    unsigned char RemapMovementDirectionForMapScroll(unsigned char direction) const;
    void RefreshScrolledTileData(
        int objectColumn,
        int objectRow,
        int viewportColumn,
        int viewportRow,
        unsigned char direction);
    int SelectMovementPathStep();
    bool ShouldClearMovementTimerState() const;
    int BuildPathToPendingActionTarget(
        ObjectPane *target,
        const MapPoint &currentPosition);
    void ResolvePendingActionTarget(
        ObjectPane *target,
        const MapPoint &currentPosition);
    void SetMapState(int weatherType, unsigned char weatherMode);
    void RequestCoordinateEffect(
        int mapColumn,
        int mapRow,
        int effectDescriptorId,
        int timerAction,
        bool renderAfterLivingObjects);
    void ApplyEffectObjectPaneTimerAction(
        EffectObjectPane *effectObjectPane,
        int timerAction);
    void CreateEffectObjectPane(
        LivingObjectPane *target,
        int mapRow,
        int mapColumn,
        EffectInfo effectInfo,
        int timerAction,
        int sequenceIndex,
        bool renderAfterLivingObjects);
    void AttachObjectLighting(
        ObjectPane *anchorSource,
        const ItemObjectImageEntry *imageEntry,
        int localOffsetX,
        int localOffsetY);
    void CreateHitBarObjectPane(
        LivingObjectPane *objectPane,
        unsigned short currentValue,
        unsigned short maximumValue);
    void RefreshStaticObjectTileRegion(const MapRect &tileBounds);
    void ResetMapResourceStateForModeChange();
    void RefreshDeferredMapSurfacesForTileRegion();
    bool InvalidateShiftedMapArea(int deltaX, int deltaY);
    bool HandleObjectInfoPacket(const unsigned char *packet);
    bool HandleEffectMapStatePacket(const unsigned char *packet);
    bool HandleDrawObjectsPacket(const unsigned char *packet);
    bool HandleMovementSpeechBalloonPacket(const unsigned char *packet);
    bool HandleObjectMoveEffectPacket(const unsigned char *packet);
    bool HandleObjectWorldMapCreationPacket(const unsigned char *packet);
    bool HandleActionPacket(const unsigned char *packet);
    bool HandleFlyingObjectUpdatePacket(const unsigned char *packet);
    bool HandleAnimationSoundPacket(const unsigned char *packet);
    bool HandleObjectStatusPacket(const unsigned char *packet);

public:
    int m_screenEffecterCount;
    int m_screenEffecterCapacity;
    ScreenEffecter **m_screenEffecters;
    LivingObjectPane *m_highlightedObjectPane;
    bool m_selectedObjectActive;
    unsigned char m_selectedObjectPadding[3];
    LivingObjectPane *m_selectedObjectPane;
    int m_mapResourceMode;
    bool m_mapEffectEnabled;
    unsigned char m_mapEffectPadding[3];
    Motion m_deferredMotionRecords[32];
    int m_deferredMotionRecordCount;
    bool m_deferMotionMessages;
    bool m_queuedMapStateRefresh;
    bool m_pendingActionPoll;
    unsigned char m_deferredStatePadding;
    int m_pendingMovementState[6];
    float m_currentDayNightBrightness;
    float m_dayNightCurrentScale;
    float m_dayNightCurrentBias;
    float m_dayNightCurrentTint;
    float m_dayNightTintCurveScale;
    float m_dayNightTintCurveBase;
    float m_dayNightTintAmount;
    float m_newHumanProjectionDivisor;
    float m_newHumanProjectionShear;
    float m_dayNightTargetBrightness;
    AlphaMaskSurface *m_selectionOverlay;
    float m_dayNightBrightnessScale;
    float m_dayNightBrightnessBias;
    unsigned int m_pendingMapStateToken;
    bool m_waitingForLocalPlayerStatus;
    bool m_objectInteractionTimerActive;
    unsigned short m_mapId;
    short m_mapWidth;
    short m_mapHeight;
    MapPaneTileRecord *m_tileBuffer;
    int m_tileOriginX;
    int m_tileOriginY;
    int m_visibleTileColumns;
    int m_visibleTileRows;
    unsigned char m_mapTransitionState;
    unsigned char m_weatherMode;
    unsigned char m_movementGate;
    unsigned char m_dayNightHour;
    int m_weatherType;
    Pane *m_weatherLayerPane;
    LivingObjectPane *m_localPlayerObjectPane;
    Pane *m_auxiliaryPane;
    Layer *m_activeScreenLayer;
    ObjectList *m_objectList;
    GrafPort m_viewportGrafPort;
    int m_mapFlashColor;
    unsigned char m_mapRuntimeMode;
    bool m_visibleObjectRefreshPending;
    bool m_refreshWholeVisibleMap;
    unsigned char m_mapRefreshPadding;
    int m_mapDisplayOriginX;
    int m_mapDisplayOriginY;
    int m_mapDisplayScalePercent;
    wchar_t m_mapName[256];
    unsigned short m_mapNameLength;
    wchar_t m_mapResourceName[256];
    unsigned short m_mapResourceNameLength;
    unsigned char m_actionStatePrefix[8];
    bool m_pendingActionModeActive;
    unsigned char m_pendingActionModePadding[3];
    int m_pendingActionTileX;
    int m_pendingActionTileY;
    unsigned char m_pendingActionState[20];
    unsigned int m_pendingActionTargetObjectId;
    bool m_deferredPrimarySurfaceDirty;
    unsigned char m_deferredSurfacePadding;
    bool m_deferredSecondarySurfaceDirty;
    unsigned char m_finalPadding;
};

typedef char MapPaneSizeMustBe0x910[
    sizeof(MapPane) == 0x910 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 3: `by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::CreateEffectObjectPane(
    LivingObjectPane *target,
    int mapRow,
    int mapColumn,
    EffectInfo effectInfo,
    int timerAction,
    int sequenceIndex,
    bool renderAfterLivingObjects)
{
    if (timerAction == -1)
        return;

    int rangeStart = effectInfo.secondaryRangeStart;
    int rangeEnd = effectInfo.secondaryRangeEnd;
    if (sequenceIndex == 1)
    {
        rangeStart = effectInfo.primaryRangeStart;
        rangeEnd = effectInfo.primaryRangeEnd;
    }

    int timerDelay = timerAction;
    if (timerDelay > 0)
        timerDelay *= 1000;

    EffectObjectPane *effectObjectPane = new EffectObjectPane(
        target,
        mapRow,
        mapColumn,
        effectInfo,
        sequenceIndex,
        renderAfterLivingObjects);

    if (target != NULL)
    {
        if (sequenceIndex == 0)
            target->AddSecondaryEffectObjectPane(effectObjectPane);
        else if (sequenceIndex == 1)
            target->AddPrimaryEffectObjectPane(effectObjectPane);
    }

    m_objectList->AddObjectPane(effectObjectPane);
    effectObjectPane->StartIdleTimer();

    if (timerDelay != -2 &&
        rangeStart >= 0 &&
        rangeEnd >= 0)
    {
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(effectObjectPane),
            2,
            timerDelay,
            0,
            0);
    }

    if (target != NULL)
        effectObjectPane->UpdatePosition();

    RectBounds bounds;
    effectObjectPane->GetBounds(&bounds);
    effectObjectPane->InvalidateRect(&bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Destination 4: `by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::RequestObjectEffect(
    unsigned int objectId,
    int effectDescriptorId,
    int timerAction,
    bool renderAfterLivingObjects)
{
    EffectInfo effectInfo;
    EffectObjImageLibGetEffectInfo(&effectInfo, effectDescriptorId);

    ObjectPane *objectPane = m_objectList->FindByObjectId(objectId);
    if (objectPane == NULL)
        return;

    LivingObjectPane *target =
        static_cast<LivingObjectPane *>(objectPane);

    if (effectInfo.secondaryFrameCount > 0)
    {
        bool reused = false;

        if (effectInfo.secondaryRangeStart >= 0 &&
            effectInfo.secondaryRangeEnd >= 0)
        {
            const int count = target->m_secondaryEffectObjectPanes->GetCount();
            for (int index = count - 1; index >= 0; --index)
            {
                EffectObjectPane *effectObject =
                    *static_cast<EffectObjectPane **>(
                        target->m_secondaryEffectObjectPanes->GetElementAt(index));
                if (effectObject != NULL &&
                    effectObject->m_effectId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping())
                {
                    ApplyEffectObjectPaneTimerAction(effectObject, timerAction);
                    reused = true;
                    break;
                }
            }
        }

        if (!reused)
        {
            MapPoint position;
            target->GetMapPosition(&position);
            CreateEffectObjectPane(
                target,
                position.row,
                position.column,
                effectInfo,
                timerAction,
                0,
                renderAfterLivingObjects);
        }
    }

    if (effectInfo.primaryFrameCount > 0)
    {
        bool reused = false;

        if (effectInfo.primaryRangeStart >= 0 &&
            effectInfo.primaryRangeEnd >= 0)
        {
            const int count = target->m_primaryEffectObjectPanes->GetCount();
            for (int index = count - 1; index >= 0; --index)
            {
                EffectObjectPane *effectObject =
                    *static_cast<EffectObjectPane **>(
                        target->m_primaryEffectObjectPanes->GetElementAt(index));
                if (effectObject != NULL &&
                    effectObject->m_effectId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping())
                {
                    ApplyEffectObjectPaneTimerAction(effectObject, timerAction);
                    reused = true;
                    break;
                }
            }
        }

        if (!reused)
        {
            MapPoint position;
            target->GetMapPosition(&position);
            CreateEffectObjectPane(
                target,
                position.row,
                position.column,
                effectInfo,
                timerAction,
                1,
                renderAfterLivingObjects);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior preservation: the source keeps exact early return, descriptor copy timing, pass order, range gates, reverse iteration, unsafe slot/pane assumptions, match fields, reuse/create branch, null target, machine-proven row-before-column create contract, sequence indices, and flag forwarding.
- Source-quality rationale: the body mirrors accepted sibling style and uses only current semantic declarations. It contains no raw offset, decompiler temporary, IDA label, compiler cookie/EH/vptr mechanics, invented validation, or modern C++ construct.
- Formal block count: `4`; expected begin/end balance: `4/4`; third-party import: not applicable.

## Final Recommendation

- All four managed blocks and C3TE-001 through C3TE-045 support/history/manual/validation dispositions are applied or explicitly excluded with terminal proof.
- B005 raised only UID0003TE, to `92/94`; UID00007Q remains `93/94`, UID0000L3 remains `92/92`, and all B005 support scores/routes were preserved. The later independent B004 callback validly raised its own UID0003TG target from `86/90` to `92/94` while preserving all B005 formals and metadata.
- UID0001AW remains a non-emitting split index and UID0003TO remains blank-body `86/90`; their accepted target-facing names/evidence are synchronized without broader reclassification, and both now agree with the promoted `int mapColumn, int mapRow` target ABI.
- The complete terminal B001 UID0003TF callback content was reread and preserved while the narrowly machine-proven row/column correction was applied in Destinations 2-4 and supporting Effects pages. The complete terminal B004 UID0003TG union was then reread and preserved across the eight shared MapPane/Effect pages without changing any B005 formal.
- No in-scope implementation, research, or manual-coverage handoff item remains. Independent review, report execution, and archival are external lifecycle state, not pending B005 report work.

## Recommended Target Doc Changes

- Path: `by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md`.
- Applied `86/89` to `92/94`; owner/emitter 00007Q, true, blank position, exact UID/path/title/range, Item Summary intent, and `Nested:0` are preserved.
- Applied exact Item Summary: `Source-ready MapPane::RequestCoordinateEffect with clamped half-open coordinate validation, 52-byte EffectInfo copy, secondary-before-primary ObjectList row-bucket reverse scans, same-column/effect-id/looping reuse, null-target row-before-column creation, sequence 0/1, and renderAfterLivingObjects pass-through.`
- Destination 1 exactly replaces the former blank formal body.
- Provisional status/name/body-blocker language is historicalized; current text uses source-ready `MapPane::RequestCoordinateEffect` with exact signature/argument promotion evidence.
- Full bytes/hash, instruction/CFG/ABI, caller packet offsets, visible gate, EffectInfo copy, pass/range/bucket/List/MapPoint/match/reuse/create behavior, exact xrefs, source route, and score rationale are incorporated at report-level detail.
- Historical split provenance, B001/B003/B007/B008 corrections, rejected owners, compact/type-number/Apply/blank-body assumptions, and all positive/negative evidence are preserved.

## Recommended Support Doc Changes

| Support destination | Exact applied/verified change | Metadata disposition |
| --- | --- | --- |
| `by-class/MapPane.md` | Destination 2 applied after terminal B001/current reread; target inventory, alias rationale, behavior/source/order/history/negative evidence added. Terminal B004 then additively synchronized the source-ready ApplyEffectObjectPaneTimerAction declaration and exact signed event-2 action semantics. A later unrelated shared-lane update replaced only the historical HitBar declaration with current `CreateHitBarObjectPane(... unsigned short ...)`; the report block was rebased to the complete current union without changing B005 target declarations. | preserved `93/94`, full union, owner/emitter/position/size |
| `by-file/MapPane.md` | Source-ready target definition/order, exact no-target reuse/create behavior, MapRect alias dependency, generated assertions, and superseded blank-marker history added; B004 additively recorded the existing-pane delete/cancel/guarded TimerHandler replacement family. Later unrelated HitBar/group-member source-inventory additions are preserved. | preserved `92/92`, path/formal policy |
| UID0003TF `MapPaneCreateEffectObjectPane` | Destination 3 applied; complete accepted body/evidence preserved and only helper/constructor row-before-column order plus stale order prose corrected. B004 later added the constructor-default distinction for inferred `m_timerExtensionLocked`. | preserved `92/94`, owner/emitter/range/Nested |
| UID000232 `MapPaneObjectEffectDescriptorDispatch` | Destination 4 applied; complete accepted body/evidence preserved and only both create calls/order prose corrected. B004 later synchronized its four calls to the now source-ready signed action helper. | preserved `92/94`, owner/emitter/range/Nested |
| UID0003TG `MapPaneApplyEffectObjectPaneTimerAction` | Independent terminal B004 callback replaced the blank formal with a complete source-ready body and exhaustive null/`-1`/`0`/`-2`/remaining-signed action, TimerHandler, inferred lock-field, unit-quirk, source-placement, negative, and history evidence. | independently raised by B004 `86/90` to `92/94`; owner/emitter/range/Nested preserved |
| UID0003TO `MapPaneHandleObjectMoveEffectPacket` | Exact `RequestCoordinateEffect(mapColumn, mapRow, effectDescriptorId, timerAction, renderAfterLivingObjects)` spelling and descriptor 160..162 render meaning applied; descriptor 134 branch and blank body retained. | preserved `86/90`, owner/emitter/formal/Nested |
| UID0001AW `MapPanePacketHandlers` | UID0003TE child source status/name/behavior and UID0003TF order synchronized; bounded Gate 2 repair corrected the sole stale current target declaration to `RequestCoordinateEffect(int mapColumn, int mapRow, ...)`. The non-emitting aggregate and all other children remain preserved. | preserved `86/90`, false, blank emitter/formal, nesting |
| UID000420 clamped bounds | UID0003TE consumer and direct RectBounds/MapRect alias use added; exact body retained. | preserved `88/90` and formal |
| UID0001D2 ObjectList accessors | Target xrefs `0x0050e8c0`/`0x0050e967`, row-bucket consumer semantics, and source names added. | preserved `92/93` and formal |
| `by-type/by-struct/EffectInfo.md` | Coordinate target consumer, pass order, and match/create semantics added; exact 0x34 declaration and unrelated scalar caveats retained. | preserved `88/90`, owner/emitter/formal |
| `by-class/EffectObjectPane.md` | Coordinate reuse consumer for `m_effectId`, `IsLooping`, and null-target creation added; B004 later added inferred default-false `m_timerExtensionLocked +0x14e` beside the distinct `m_looping +0x14c` and `m_renderAfterLivingObjects +0x14d` fields. Broader declaration caveat remains preserved. | preserved `85/86`, formal/route |
| UID0003XP ObjectPaneGetMapPosition | Target reverse-scan consumer and column-only comparison after row-bucket selection added; stale blank-formal prose historicalized. | preserved `92/94` and formal |
| `by-type/by-struct/MapPoint.md` | UID0003TE row-bucket/returned-column consumer added; row/column layout and no x/y union preserved. | preserved `92/93` and formal |
| `by-file/Effects.md` and UID0001D9 EffectObjectPaneCore | Constructor call contract corrected only to target, row, column; all allocation/layout/timer/destructor evidence preserved. B004 additively synchronized UID0001D9's inferred lock-field constructor/read evidence and exact-child-only emission policy. | preserved scores/routes/formals |
| `g_pEffectObjImageLib`, ObjectList/List classes, ignored padding | Read-only verified at same-or-greater detail; no contradiction and no body/score/route edit. | unchanged |

- All shared MapPane/Effect support edits were performed after terminal B001/current destination rereads as additive unions; no concurrent content was compressed or overwritten.

## Score And Metadata Recommendation

- Historical pre-callback target: `86/89`, owner/emitter `00007Q`, reconstructable true, blank position/formal, `Nested:0`.
- Current target: `92/94`, same owner/emitter/reconstructable/position/Nested/range/path/title, with Destination 1 applied.
- Completion `92`: exact body, signature, arguments, fields, calls, range, bytes, CFG, xrefs, source placement, declaration route, generated plan, and history are all implementation-ready.
- Confidence `94`: machine behavior and project contracts are very strong; exact original source spelling `RequestCoordinateEffect` and the MapRect typedef spelling are inferred rather than symbol-recovered.
- Not higher: no PDB/source symbol, no local recovered MapRect UDT, and no direct lexical resource identifies the exact private method/type alias spellings.
- Not lower: both inferred spellings are constrained by accepted sibling APIs, exact ABI, direct call semantics, canonical layouts, and compile requirements; no behavioral or source-shape blocker remains.
- B005 support scores remained unchanged because target-consumer synchronization did not improve their independent unresolved class/type scope. B004's later independent source-quality callback raised only UID0003TG to `92/94`; that external accepted improvement does not alter the B005 target score rationale.
- UID0003TF and UID000232 stay `92/94`: the correction is exact and important but narrow, and their prior behavior/ownership/source-quality evidence remains valid.

## Open Questions With Attempted Resolution

- `RequestCoordinateEffect` versus `RequestPositionEffect`: searched old reports/current source family and compared sibling semantics. Resolution: Coordinate ranks first because arguments are explicit map column/row and Position is overloaded; no unresolved blocker.
- MapRect definition: searched current by-class/by-type/by-file/by-memory and generated NexusTK source. No definition exists; all uses match RectBounds layout and direct PointInRect compatibility. Resolution: typedef alias in complete class destination; no unresolved blocker.
- Null element behavior: checked disassembly and List ABI. Resolution: no null check; preserve unsafe invariant-dependent source.
- Row comparison: checked target code and bucket helper. Resolution: row is encoded by bucket selection; compare only column as binary does.
- Negative EffectInfo ranges: checked both CFG branches. Resolution: skip reuse, still create; no ambiguity.
- Timer/render flag meanings: checked caller, UID0003TF, UID0003TG, constructor/render docs. Resolution: `timerAction` and `renderAfterLivingObjects` are exact current names.
- Create-helper coordinate order: inspected all four call-site push sequences, GetMapPosition field order, callee frame offsets, EffectObjectPane constructor arguments, and its ObjectPane constructor forwarding. Resolution: helper/EffectObjectPane constructor source order is row then column; the historical B001 column/row labels were stale, and applied Destinations 2-4 plus current B004-preserved pages contain the exact correction.
- UID0003TG body readiness: B005's initial scope correctly treated the direct body as outside UID0003TE and did not raise the target score based on it. B004 later completed the independent body at `92/94`; current source-ready support strengthens generated closure but does not change UID0003TE's already accepted `92/94` score.
- Exact original lexical spellings remain unrecoverable, but ranked choices are implementation-ready confidence caps, not future investigations.
- Remaining unresolved in-scope items: `0`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only comparison was repeated after supervisor coverage commands `13503`/`13504`/`13506`/`13507`. Current hashes/metrics are: `by-memory/-coverage-report.md` `B2E77EEA392073D08F0D8925954421629756E7378B12DFE46CFEB8BFAEBB9915`, 1,716,683 bytes / 4,138 lines; `by-class/-coverage-report.md` `54BCD2A27736A7E42095B7263E8C09AB1A37D7133D22C4DCF18443AF04F62665`, 223,253 / 622; `by-file/-coverage-report.md` `0574FDA2D15298AAB264F3C75115ED82056DE851619F28C00FC297F2B38E761E`, 126,562 / 316; and `by-type/by-struct/-coverage-report.md` `269D77A8801F26AAA36F410C842B137973103FE81B55D0BA37C062AE2D16A1E5`, 57,098 / 137. All 18 current rows/placements below were reread from those exact files.
- Historicalized lifecycle fact: before B001 execution command `000000013371`, its report supplied a pending UID0003TE/UID0003TF/predecessor-padding/UID0003TG handoff. External B004 commands `13488-13490` later applied B004's exact UID0003TG, successor-padding, UID0001D9, UID000049, UID00007Q, and UID0000L3 rows. B003 commands `13492-13496` then added unrelated LineIterator/SpelledPane rows, and B002 commands `13498-13500` applied unrelated ScreenCursor/ScreenPane/Application rows. After exact report SHA `CA69F363...9CC11` passed Gate 1/Gate 2, supervisor commands `13503`/`13504`/`13506`/`13507` applied this report's ten literal replacement/insertion rows. Current parity is `10/10`; no B003, B002, or B004 fact was narrowed.
- Current-row matrix and exact disposition:

| Manual report/current row | Current applied state | Exact B005 disposition |
| --- | --- | --- |
| by-memory line 2276 UID000232 | exact B004/B005 RequestObjectEffect, source-ready UID0003TG, and row-before-column union | supervisor-applied exact handoff row; current |
| by-memory line 2278 UID0001AW | `86%` non-emitting packet split/container | verify-only; unchanged |
| by-memory line 2284 UID0003TE | `92%` exact source-ready coordinate-effect row | supervisor-applied exact handoff row; current |
| by-memory line 2285 UID0003TF | full row-before-column plus default-lock constructor union | supervisor-applied exact handoff row; current |
| by-memory line 2286 UID0000VN padding | applied six-byte `0xcc` alignment row | verify-only; unchanged |
| by-memory line 2287 UID0003TG | externally applied B004 `92%` source-ready action row | verify-only; exact accepted B004 row is current |
| by-memory line 2288 successor padding `[0x0050ec2e,0x0050ec30)` | externally applied exact two-byte ignored-padding row | verify-only; exact accepted B004 row is current |
| by-memory line 2292 UID0003TO | exact packet-method row present between UID0003TL line 2291 and UID0001AY line 2293 | supervisor-applied exact handoff row; current |
| by-memory line 2501 UID0001D2 | `92%` accessor summary | verify-only; unchanged |
| by-memory line 2511 UID0003XP | `92%` row/column accessor summary | verify-only; unchanged |
| by-memory line 2526 UID0001D9 | full B004/B005 constructor/descriptor/sequence split-index union | supervisor-applied exact handoff row; current |
| by-memory UID000420 | absent | verify-only absence; consumer-only prose does not require a new row |
| by-class line 302 UID00007Q | full B004/B005 target/alias/order/action-helper union | supervisor-applied exact handoff row; current |
| by-class line 178 UID000049 | full B004/B005 constructor/reuse/lock-field union | supervisor-applied exact handoff row; current |
| by-file line 156 UID0000L3 | full B004/B005 target/alias/order/action-helper source-root union | supervisor-applied exact handoff row; current |
| by-file line 80 UID0000IZ | full Effects constructor-order union | supervisor-applied exact handoff row; current |
| by-type/by-struct line 39 UID0001U8 | full EffectInfo coordinate-consumer union | supervisor-applied exact handoff row; current |
| by-type/by-struct line 72 UID0004R0 | `92%` MapPoint row/column union | verify-only; unchanged |

- Historical exact supervisor-applied UID0003TE line 2284 text, positioned after the existing `0x0050e848-0x0050e850` padding row and before UID0003TF:

        - [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) 0x0050e850-0x0050ea30 | private class method | MapPaneCoordinateEffectDescriptorDispatch : reconstructable : 92% : very strong : Exact source-ready `MapPane::RequestCoordinateEffect`; rejects coordinates outside clamped half-open visible bounds, copies a 52-byte EffectInfo, processes secondary before primary, reverse-scans the corresponding ObjectList row bucket, reuses the first same-column/same-effect-id looping EffectObjectPane through source-ready signed timer action, or creates a null-target pane with sequence 0/1 and unchanged renderAfterLivingObjects. Owner/emitter UID00007Q MapPane; one UID0003TO caller, exact 480-byte range, no split/compiler artifact, and complete formal body.

- Historical exact supervisor-applied UID0003TF line 2285 no-loss union; the following six-byte alignment line 2286 remains byte-for-byte unchanged:

        - [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md) 0x0050ea30-0x0050eb8a | class method | MapPaneCreateEffectObjectPane : reconstructable : 92% : very strong : Exact source-ready MapPane::CreateEffectObjectPane; takes LivingObjectPane target, map row then map column, and EffectInfo by value, preserves timerAction sentinels, creates through ordinary EffectObjectPane new/pool lowering, registers primary/secondary ownership and MapPane ObjectList state, starts event 1, conditionally schedules event 2, updates position, obtains bounds, and invalidates them. The exact target/row/column contract, constructor-default distinction for inferred `m_timerExtensionLocked`, and complete formal body preserve all current allocation, registration, timer, bounds, and invalidation evidence.

- Historical exact supervisor-applied UID000232 line 2276 corrected no-loss row:

    - [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) 0x0050e320-0x0050e4b6 | class method | MapPaneObjectEffectDescriptorDispatch : reconstructable : 92% : very strong : Source-ready MapPane::RequestObjectEffect with exact EffectInfo lookup, typed LivingObjectPane target, secondary-before-primary reuse/create flow, renderAfterLivingObjects pass-through, source-ready UID0003TG signed timer-action reuse, exact four-call relationship to UID0003TF, machine-accurate MapPoint row-before-column create calls, and complete formal body.

- Externally applied B004 UID0003TG row at current line 2287 and successor-padding row at line 2288 were verified byte-for-byte against the accepted B004 handoff. They are intentionally absent from the historical ten-row B005 text because they were already current and required no duplicate application.

- Historical exact supervisor-applied UID0003TO insertion, now current at line 2292 under UID0001AW after UID0003TL line 2291 and before UID0001AY line 2293:

        - [UID:0003TO][0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket](by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md) 0x00511c90-0x00511dae | packet method | MapPaneHandleObjectMoveEffectPacket : reconstructable : 86% : strong : Exact opcode-0x29 MapPane object-move/effect handler with object id, descriptor, signed timer action, column, and row fields; descriptor 134 performs the flash/sleep branch, descriptors 160..162 select renderAfterLivingObjects, object id zero calls RequestCoordinateEffect(column,row,...), and a resolved nonzero object calls RequestObjectEffect. Owner/emitter UID00007Q; blank formal retained pending the broader packet-handler source pass.

- Historical exact supervisor-applied UID0001D9 line 2526 no-loss aggregate row:

    - [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md) 0x005387b0-0x00538baa | method-cluster split index | EffectObjectPaneCore : not_reconstructable : 88% : very-strong : Non-emitting EffectObjectPane method-cluster index with exact constructor/destructor/timer/update/bounds/render/IsLooping inventory, child/padding/vtable/caller/callee evidence, target/row/column constructor flow, borrowed target and EffectInfo descriptor/sequence state, m_looping +0x14c, m_renderAfterLivingObjects +0x14d, inferred m_timerExtensionLocked +0x14e constructor-zero and bounded no-nonzero-writer evidence, generated state, and exact-child-only source emission policy.

- Historical exact supervisor-applied UID00007Q by-class line 302 full no-loss union:

- [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 93% : very strong : Complete source-era `class MapPane : public Pane` declaration emitter at position 0 with all 69 current MapPane method declarations, supported virtual/access surface, exact 0x910 field layout, complete-value and forward-declaration dependencies, compile-time size guard, child insertion after the class, exact UID00037W paint/day-night/lighting split, source-ready RequestObjectEffect/CreateEffectObjectPane/RequestCoordinateEffect integration with the machine-accurate row-before-column create-helper contract, and source-ready ApplyEffectObjectPaneTimerAction integration with typed EffectInfo/LivingObjectPane/EffectObjectPane, exact signed event-2 action semantics, and no handwritten compiler ABI lowering or Empty Emitter Marker. The MapRect source name is a layout-preserving typedef alias of canonical RectBounds, closing direct PointInRect compatibility without duplicate layout or raw casts.

- Historical exact supervisor-applied UID0000L3 by-file line 156 full no-loss union:

- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 92% : very strong : NexusTK/map/MapPane.cpp source root with complete UID00007Q class-before-children declaration route, Pane/GrafPort/Motion/vector and forward-declaration dependencies, singular canonical fields and MapPoint row/column contract, exact UID00037W eight-child source order, the previously documented seven MapPane member definitions plus exact source-ready RequestObjectEffect/CreateEffectObjectPane/RequestCoordinateEffect/ApplyEffectObjectPaneTimerAction definitions, one file-static ObjectStatusBlob light-equipment predicate, MapRect-as-RectBounds alias compatibility, coordinate-effect secondary-before-primary reuse/create behavior, exact row-before-column create-helper/EffectObjectPane-constructor contract, existing-pane source delete/cancel/guarded TimerHandler replacement behavior, and preserved prose-only by-file policy without reconstruction metadata.

- Historical exact supervisor-applied Effects by-file line 80 full union:

- [UID:0000IZ][Effects](by-file/Effects.md) : reconstructable : 90% : strong : Runtime effecter module with class inventory, vtable family, small-constructor caveats, EffectObjectPane relationship, asset-library separation, global alias correction, open split questions, endpoint/range changes, effect-id/looping evidence, +0x14d late/after-living render selector, MapPane ordinary-new creation dependency, exact target/row/column EffectObjectPane constructor order, primary/secondary LivingObjectPane ownership, and preserved compiler-allocation versus handwritten-source distinction.

- Historical exact supervisor-applied EffectObjectPane by-class line 178 full union:

- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) : reconstructable : 85% : strong : EffectObjectPane class support with exact +0x128 borrowed LivingObjectPane, selected EffectInfo sequence header, public m_effectId +0x148, m_looping +0x14c, m_renderAfterLivingObjects +0x14d, inferred default-false m_timerExtensionLocked +0x14e, target/row/column constructor flow, UpdatePosition virtual route, primary/secondary owner registration, timer events 1/2, pool lifecycle, RequestObjectEffect and RequestCoordinateEffect reuse/create consumers, source-ready existing-pane timer-action consumer, and the broader complete class declaration intentionally withheld pending independent constructor/layout closure.

- Historical exact supervisor-applied EffectInfo by-struct line 39 full union:

- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) : reconstructable : 88% : strong : Exact 0x34 EffectObjImageLib descriptor POD with two EffectFrameRecord sequences, accepted frame-count/range fields, by-value MapPane ABI, secondary-before-primary RequestObjectEffect/RequestCoordinateEffect consumers, UID0003TF range selection and constructor copy, owned-array cleanup, and preserved uncertainty only for nonconsumed original scalar/flag spellings.

- UID0001AW, UID000420, UID0001D2, UID0003XP, and MapPoint remain verify-only exactly as classified in the matrix. Their current rows, where present, do not assert the stale create-argument order and their score/path/title/reconstructability/split summaries remain true after bounded consumer synchronization. UID000420 remains absent because this callback does not create, rename, rescore, or reclassify it.
- Tracker is validator-owned and changes only through supervisor lifecycle; B005 did not edit `auto-generated/-ag-research-tracker.md`.
- B005 did not apply any text above because all `-coverage-report.md` files are manual supervisor-owned restricted state. Supervisor commands `13503`/`13504`/`13506`/`13507` applied the exact B005 target/order/consumer rows and fuller unions while preserving the B004 UID0003TG/successor-padding rows and unrelated B003/B002 additions. Current exact parity is `10/10`. The ten historical literal rows remain byte-for-byte unchanged from the no-loss handoff; joined in report order with LF separators, their SHA256 is `13C9B5BB8769C3E0C0456FAE76CC633B75AC81E02458AF161F5C518D5DDE7CDC`.

## Follow-Up Actions

- Supervisor-owned external state: independent review, report execution, and archival. Exact B005 manual no-loss coverage application is already complete at `10/10` under commands `13503`/`13504`/`13506`/`13507`; no manual handoff remains pending.
- A-agent actions: none.
- B005 callback work remaining: none. All accepted claims, destinations, scoped validators, waited generated verification, manual handoff, hash/formal checks, report reconciliation, and lease releases are complete.

## Confidence

- Range/bytes/CFG/ABI confidence: `99`.
- Behavior/caller/callee/field confidence: `97`.
- Owner/emitter/source-route confidence: `98`.
- First-draft source-shape confidence: `94`.
- Score recommendation confidence: `94`.
- Remaining uncertainty: exact original private method spelling and typedef spelling only; neither changes behavior or leaves an implementation blocker.

## Validator Results

- Historical report-only phase: no implementation validator was run before accepted Gate 1 SHA `4A5AB193...C4A7`.
- Completed callback command matrix; every row ran from `source-3/project-documentation`, returned exit `0`, `ok:1`, and was followed by immediate lease release:

| Command | Timestamp | Scoped ordinary page | Result / warnings / side effects |
| --- | --- | --- | --- |
| `000000013374` | `2026-07-15T18:44:32-04:00` | UID0003TE | target score/body/evidence accepted; projected stats/registry/ref updates; generated deferred |
| `000000013375` | `2026-07-15T18:46:55-04:00` | `by-class/MapPane.md` | Destination 2 accepted; 50 pre-existing `missing_ref_uid` warnings; registry/ref/stats; generated deferred |
| `000000013376` | `2026-07-15T18:48:05-04:00` | UID0003TF | Destination 3 accepted; registry/stats; generated deferred |
| `000000013378` | `2026-07-15T18:49:45-04:00` | UID000232 | Destination 4 accepted; registry/ref/stats; generated deferred |
| `000000013382` | `2026-07-15T18:52:08-04:00` | `by-file/MapPane.md` | source inventory accepted; 57 pre-existing `missing_ref_uid` warnings; stats; generated deferred |
| `000000013384` | `2026-07-15T18:52:57-04:00` | UID0003TO | caller synchronization accepted; refs/stats; generated deferred |
| `000000013387` | `2026-07-15T18:56:35-04:00` | UID0001AW | aggregate synchronization accepted; 40 pre-existing `missing_ref_uid` warnings; validator-owned UID-link normalization for unrelated UID0003TB/UID0003TD names; refs/stats; generated deferred |
| `000000013389` | `2026-07-15T18:57:23-04:00` | UID000420 | consumer/alias prose accepted; refs/stats; generated deferred |
| `000000013390` | `2026-07-15T18:58:13-04:00` | UID0001D2 | exact row-bucket xrefs accepted; refs/stats; generated deferred |
| `000000013391` | `2026-07-15T18:59:20-04:00` | EffectInfo | coordinate consumer accepted; refs/stats; generated deferred |
| `000000013392` | `2026-07-15T19:00:07-04:00` | EffectObjectPane | reuse/create consumer accepted; five pre-existing UID000382 warnings; refs/stats; generated deferred |
| `000000013393` | `2026-07-15T19:01:15-04:00` | UID0003XP | coordinate consumer accepted; one pre-existing UID0003Y0 warning; refs/stats; generated deferred |
| `000000013394` | `2026-07-15T19:01:56-04:00` | MapPoint | coordinate consumer accepted; refs/stats; generated deferred |
| `000000013395` | `2026-07-15T19:02:39-04:00` | `by-file/Effects.md` | constructor-order/consumer prose accepted; eight pre-existing UID0003HA-H/D warnings; refs/stats; generated deferred |
| `000000013396` | `2026-07-15T19:03:26-04:00` | UID0001D9 | constructor-order/consumer prose accepted; two pre-existing UID000382 warnings; refs/stats; generated deferred |
| `000000013397` | `2026-07-15T19:04:00-04:00` | UID0003TE `--wait-generated` | final target recheck accepted; generated refresh completed; global pre-existing autogen warnings were 14 fallback insertions, 85 missing-child markers, and 160 emitters without code; no target-specific failure |
| `000000013429` | `2026-07-15T19:32:56-04:00` | UID0001AW | bounded Gate 2 repair accepted; exit `0`, `ok:1`; corrected only the current target signature from `short` to promoted `int`; same 40 pre-existing `missing_ref_uid` warnings as command `13387`; projected-stat/reference updates were tool-owned and generated refresh was deferred |

- Subsequent B004 application-time evidence, all exit `0`/`ok:1` with immediate lease release: target `13454`; by-class MapPane `13455`; by-file MapPane `13459`; by-class EffectObjectPane `13462`; UID0001D9 `13466`; UID000232 `13469`; UID0003TE `13473`; UID0003TF `13474`; and final waited target refresh `13477`. These commands additively preserved all B005 formals, promoted-int ABI, and row-before-column calls while making UID0003TG source-ready.
- External supervisor manual-coverage commands `13488-13490`, completed before B004 execute command `13491`, applied B004's exact UID0003TG/successor-padding, UID0001D9, UID000049, UID00007Q, and UID0000L3 rows. Supervisor B003 commands `13492-13496` and B002 commands `13498-13500` later added unrelated coverage; all those snapshots are historical. After exact report SHA `CA69F363...9CC11` passed Gate 1/Gate 2, supervisor commands `13503` (by-memory), `13504` (by-class), `13506` (by-file), and `13507` (by-struct) each exited `0`/`ok:1` and applied this report's ten exact rows. Current hashes/metrics are by-memory `B2E77EEA...9915` / 1,716,683 bytes / 4,138 lines; by-class `54BCD2A2...2665` / 223,253 / 622; by-file `0574FDA2...761E` / 126,562 / 316; by-struct `269D77A8...A1E5` / 57,098 / 137. All 18 B004/B005 rows and placements are current, with exact B005 parity `10/10`. These were supervisor-owned external changes; B005 did not edit or validate coverage.
- Current external generated checkpoint is `auto-generated/NexusTK/map/MapPane.cpp` command/header `000000013515`, refreshed `2026-07-15T21:17:18-04:00`, SHA256 `0E2FC02FE45981F395CE3967FC06F20CCCDB050832AF55B2A412E16D0D5D4E5A`, 103,866 bytes, 3,043 lines. B005 waited command `13397`, B004 waited command `13477`, and external command `13487` are historical callback/complete-union baselines; later external command `13515` preserves both accepted unions plus unrelated current shared-lane additions.
- Generated B005 assertions pass: one `class MapPane`, one private target declaration, one UID0003TE definition, zero UID0003TE Empty Emitter Markers, one UID000232 definition, one UID0003TF definition, two null-target `mapRow,mapColumn` calls, two object-target `position.row,position.column` calls, one constructor `target,mapRow,mapColumn` call, zero old-order variants, secondary before primary, sequence `0/1`, and unchanged render-after forwarding.
- Generated B004 assertions also pass: one UID0003TG private declaration and one definition, zero UID0003TG Empty Emitter Markers, one source `delete effectObjectPane`, two event-2 `CancelTimer` calls, one due-tick query, one `ScheduleTimer` call, and one target `m_timerExtensionLocked` read; the broader EffectObjectPane declaration remains intentionally comment-only. The accepted regions contain zero raw `+0xa4`/`+0x14e`, vtable-slot, deleting-flag, scalar-destructor, pool-free, `_DWORD`, `sub_`, `security_cookie`, `__thiscall`, `undefined`, or `unk_` scaffolding.
- This post-coverage report rebase ran no validator and edited no ordinary or restricted file because current `10/10` manual parity creates no accepted C3TE contradiction. Validator side effects listed above were tool-owned projected-stat, reference-index, UID-link, registry, generated-report metadata, generated C++ refreshes, and supervisor-owned coverage updates; B005 did not manually edit any generated, coverage, tracker, audit, supervisor, validator-state, or lifecycle file.

## Changed Files

- Historical creation and completed callback artifact: `tools/leaser/Agents/Agent-B005/research/0003TE-MapPaneCoordinateEffectDescriptorDispatch-source-quality.md`.
- Historical B005 callback modified exactly 15 ordinary by-* files. This post-coverage applied-state rebase modified only this B005 report; it did not edit any ordinary, restricted, manual, generated, tracker, audit, supervisor, validator, archive, or lifecycle file.
- Accepted baselines and current complete shared-union destination artifacts:

| Path | Accepted baseline SHA256 | Current SHA256 | Bytes | Lines | Validator |
| --- | --- | --- | ---: | ---: | --- |
| target UID0003TE | `56B2F984...2D40` | `7372658F26E4D67026821535D4B9247A9FAD8C0C8DD40BE2B328255DFE620DD3` | 21246 | 235 | B005 `13374`, `13397`; B004 `13473` |
| `by-class/MapPane.md` | `14504E9E...0524` | `81E3DA7781AC2D7B8ED89FDFCED4EEC5F24322524EF8C0DC238F385C6A9B2652` | 156814 | 896 | B005 `13375`; B004 `13455`; later external shared union preserved |
| `by-file/MapPane.md` | `610C89E0...2A41` | `58EC08AF0CDF821DCDC4B9B10C975A849EFB2ACEE48E91858E61A81DE2CC9E47` | 157764 | 656 | B005 `13382`; B004 `13459`; later external shared union preserved |
| UID0003TF | `7E9815D6...4750` | `192F03AE10F29E670202789B5BC69EB9D58865D85A7B8413C2FBED37BBCADBE9` | 25114 | 227 | B005 `13376`; B004 `13474` |
| UID000232 | `6BEADB04...55BF` | `4102A5D9AB51BE8CAB00AD9A97CA59032FFF68D8458E2FEE71522C260D535055` | 29627 | 279 | B005 `13378`; B004 `13469` |
| UID0003TO | `83FB8262...9EA` | `B76BE9A077609E8305CA7865D4ED4FDBD920B47962BED8F09E3C39AAEF2F85D7` | 10435 | 99 | `13384` |
| UID0001AW | `751F12C4...8454` | `EF0A51650C70C6C7C75D6CD8ACA18282B0DEA7326AE8709EDBFB371311F14720` | 76302 | 313 | `13387`, `13429`; later external shared union preserved |
| UID000420 | `51605252...F857` | `5AD5E63BB5C5E8B638CDD5AB0EBE321DEF1DD831E5F8D463DDF092B6046EA28C` | 3920 | 58 | `13389` |
| UID0001D2 | `FF085BE2...92C` | `FBA36D2EEE0AAAF492AF54EED71CA4D025DD4388F67FFA9A5B9E927145E46174` | 18327 | 213 | `13390` |
| EffectInfo | `56EB4205...6D2` | `B4E50F88863C686C10274520CE0E37A81FA78FB4E97481762468A994BB92F8DE` | 19988 | 173 | `13391` |
| EffectObjectPane | `DE66AA9E...8C0` | `AB8BA198E1AFCE8ED52424AFFE58942D94F5666B4B93EB5D1D045F5DBBC73955` | 34722 | 208 | B005 `13392`; B004 `13462` |
| UID0003XP | `D1E711D5...501` | `127D6623538E41595C069CC72991DE0D0275D367035351242DDF217FEC066044` | 9587 | 81 | `13393` |
| MapPoint | `B9E2E954...FBD` | `329517FF6DD4337415A21239D7AC0C87CC3C5CD3EA40E6FCB716E659D15F91D1` | 5520 | 64 | `13394` |
| `by-file/Effects.md` | `884436DB...F4C` | `035840C905B530C432AC1E759FEF83D455EE61E8F7C18BD7E1AD6F40402D6436` | 59417 | 294 | `13395` |
| UID0001D9 EffectObjectPaneCore | `A2652D13...85E` | `F232D176781197ADFE9EE7CE5EB73517AA8E4C531060688615EF6C36B2CFB9BA` | 37490 | 209 | B005 `13396`; B004 `13466` |

- Formal parity: exactly four report blocks and four destination blocks, all byte-for-byte equal. UTF-8 extracted current block SHA256 values are Destination 1 `6E5D4DFF206F0C30EEBF058AE5BBEEB2D505F73982627ED7CBF11789875CF994`, Destination 2 `7DC24413189495C7F1F70552370985CFCA6766545696755220AD5B3A9F9E94B0`, Destination 3 `2B8CB197F30AAECFF0B0E638893F2C598EBB5385A3D21E38CE051E298F658266`, and Destination 4 `A550049375F4336DD31718BD6F484510735811CB59D70C6FF341085C81FF5B6A`. Historical accepted Destination 2 hash `F0B172E8...025E` differs only because the later shared union superseded the unrelated HitBar helper declaration; all B005 target content is unchanged.
- Current manual restricted artifacts after supervisor commands `13503`/`13504`/`13506`/`13507`: by-memory `B2E77EEA392073D08F0D8925954421629756E7378B12DFE46CFEB8BFAEBB9915` / 1,716,683 bytes / 4,138 lines; by-class `54BCD2A27736A7E42095B7263E8C09AB1A37D7133D22C4DCF18443AF04F62665` / 223,253 / 622; by-file `0574FDA2D15298AAB264F3C75115ED82056DE851619F28C00FC297F2B38E761E` / 126,562 / 316; by-struct `269D77A8801F26AAA36F410C842B137973103FE81B55D0BA37C062AE2D16A1E5` / 57,098 / 137. The 18-row matrix above records ten exact supervisor-applied B005 rows and eight verify-only/current dispositions while preserving B003/B002/B004 content.
- Current external dependency: UID0003TG SHA256 `EF898035364ECAF630D374FED4C553DD4F39866C3DBE665DF504A74CEBE21EFB`, 16,328 bytes, 172 lines, B004 scoped `13454`/waited `13477`. Exact B004 active terminal rebase boundary was report SHA256 `0EA40ECC...BBD88`; supervisor command `13491` subsequently produced current archive `executed-b-agent-research/B004/0003TG-MapPaneApplyEffectObjectPaneTimerAction-source-quality.md`, SHA256 `621067D0...4FA1`, by appending validator-owned lifecycle history.
- Verify-only current artifacts remained unchanged by B005: terminal B001 archive `EE9B4615...ADB46`; by-global `g_pEffectObjImageLib` `F3EDE861...5316`; its covered storage page `60EFC3E1...A859`; ObjectList class `C2752930...DE5C`; List class `1AD869D2...B1D`; and externally advanced `by-memory/-ignored.md` `77F05CB1C9050861D2342C387DE6E477F06941D82C99BBD492794C457865FBB1`, with exact padding entries `[0x0050e848,0x0050e850)`, `[0x0050eb8a,0x0050eb90)`, and `[0x0050ec2e,0x0050ec30)` intact.
- All ordinary leases, including the bounded UID0001AW repair lease, were released immediately after validation. Current B004 and B005 lease files contain zero B004/B005 rows. No report lease was required for this agent-local reconciliation. No accepted item is blocked; B005 ran no execute/probe/lifecycle/move/archive command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 validation completed before implementation.
- [x] Confirm exact report artifact/provenance/path and C3TE-001 through C3TE-045 acceptance.
- [x] Reread terminal B001 UID0003TF archive before B005 shared edits; after B004 cleared the lane, reread exact terminal B004 active artifact SHA `0EA40ECC...BBD88`, its current command-`13491` archive, and the complete post-B004 shared union.
- [x] Reread/rebase target and all shared destinations at same-or-greater detail before editing.
- [x] Raise only UID0003TE `86/89` to `92/94`; preserve all other scores/routes/metadata.
- [x] Apply Destination 1 exactly to UID0003TE.
- [x] Apply Destination 2 as a complete no-loss MapPane class replacement with alias/target declaration/create-order corrections only.
- [x] Apply Destination 3 to UID0003TF, preserving the full body and correcting only row-before-column parameter/constructor order.
- [x] Apply Destination 4 to UID000232, preserving the full body and correcting only both create-call argument orders.
- [x] Preserve target owner/emitter 00007Q, true, blank position, exact range, and Nested 0.
- [x] Incorporate exact bytes/hash/instruction/CFG/ABI/caller/callee/xref evidence.
- [x] Incorporate packet offsets/promotions, descriptor 134 exclusion, and 160..162 render-after meaning.
- [x] Incorporate visible-bounds/PointInRect order and half-open semantics.
- [x] Incorporate EffectInfo copy, exact pass order, frame/range gates, and negative-range create behavior.
- [x] Incorporate ObjectList row buckets, reverse List pointer-slot scan, and no-null-check behavior.
- [x] Incorporate MapPoint column comparison, effect-id match, IsLooping, first-match reuse, and create fallback.
- [x] Incorporate null target, sequence 0/1, timerAction, and renderAfterLivingObjects forwarding.
- [x] Incorporate all-four-callsite/create-frame/constructor proof for the row-before-column helper contract.
- [x] Apply bounded UID0003TO, UID0001AW, UID000420, UID0001D2, EffectInfo, EffectObjectPane, UID0003XP, and MapPoint synchronization; Gate 2 repair revalidated UID0001AW with the promoted `int mapColumn, int mapRow` target signature and no remaining current `short` declaration across all 15 destinations.
- [x] Preserve verify-only dependencies and all B001/B003/B004/B007/B008/current union content, including UID0003TG source body, lock-field evidence, TimerHandler semantics, and successor padding.
- [x] Preserve historical/superseded compact/type-number/Apply/ObjectPane/GetEffectBounds/blank-body assumptions with reasons.
- [x] Preserve rejected owners, no-split proof, negative evidence, lexical caps, and unsafe invariant behavior.
- [x] Confirm no third-party import applies and no parent/UID0003TO/support C++ is added.
- [x] Use one-file leases only immediately around each edit/scoped validation; release immediately.
- [x] Run one scoped validator per changed ordinary page and record command metadata/results/side effects.
- [x] Run one final authorized UID0003TE `--wait-generated` refresh and verify exact generated assertions; preserve B005 command `13397`, B004 command `13477`, and external command `13487` as historical proof, then rebase current readback to external command `13515` without running another validator.
- [x] Preserve the externally applied B004 manual rows and unrelated B003/B002 additions; confirm supervisor commands `13503`/`13504`/`13506`/`13507` applied this report's exact ten-row handoff and record the complete 18-row applied/verify matrix without editing coverage.
- [x] Reconcile ledger, validator results, changed files, generated proof, checklist, all 15 hashes, four formal blocks, manual hashes/rows, verify-only artifacts, and archive-neutral current-state wording in this same report.
- [x] Confirm all leases released and no restricted/prohibited action occurred.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted C3TE claims applied/already present/historicalized/excluded with claim-specific proof.
- [x] All accepted target/support details incorporated at report-level detail without loss.
- [x] All four managed destination blocks match accepted report bytes/content.
- [x] Metadata/score/owner/emitter/nesting/source-route changes applied exactly or excluded with reason.
- [x] Terminal B001 and B004 shared MapPane/Effect unions preserved after archive/current-page reread and additive report-only rebase.
- [x] Historical assumptions, rejected alternatives, negative evidence, and open-question resolutions preserved.
- [x] Scoped validators completed and lease releases recorded for every changed ordinary page, including bounded UID0001AW repair command `13429` and immediate lease release.
- [x] Historical final waited refreshes `13397`/`13477` completed; current external generated command `13515` preserves every B005/B004 MapPane assertion and later unrelated shared-lane additions.
- [x] Current manual rows reread under exact command-`13503`/`13504`/`13506`/`13507` four-file hashes; all 18 rows/placements are current and the exact ten-row handoff is supervisor-applied, byte-identical, no-loss, and `10/10` complete.
- [x] Remaining unapplied accepted item count confirmed as zero; no claim is blocked.
- [x] Report lifecycle/execute/move/archive left entirely to supervisor.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000013516","destination_path":"executed-b-agent-research/B005/0003TE-MapPaneCoordinateEffectDescriptorDispatch-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003TE-MapPaneCoordinateEffectDescriptorDispatch-source-quality.md","timestamp":"2026-07-15T21:30:39-04:00","uid":"0003TE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
