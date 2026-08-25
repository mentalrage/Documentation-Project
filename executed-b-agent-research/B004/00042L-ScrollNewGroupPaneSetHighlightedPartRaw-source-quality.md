** TARGET-REPORT-UID:00042L **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00042L ScrollNewGroupPane SetHighlightedPart Raw Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:00042L] as the exact class-owned, reconstructable, code-emitting child for `ScrollNewGroupPane::SetHighlightedPart(ScrollNewGroupPart part)` over `[0x005619d0,0x00561a40)`. The accepted ordinary callback has physically applied `92/94` while retaining `CANONICAL_OWNER:0000CL`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:70`, and the `ScrollNewGroupPane -> Group` source route.
- Source classification: a retained out-of-line source method whose statically visible callers were optimized into specialized inline copies. It is not compiler-generated glue, dead data, a covered-by-only duplicate, or part of the successor body.
- Formal source disposition: retain the current behavior-preserving human C++ body in the target formal CPP channel and retain a blank target H channel because declarations are owned by [UID:0000CL]. Do not emit raw IDA labels. The current body already expresses the exact no-op, old/new invalidation, sentinel, and byte-store behavior.
- Score result: the target is now `92/94`, raised from historical pre-callback `87/89`. The raw start's lack of an incoming static route no longer remains an unresolved blocker: direct xref, VA, RVA, raw-file-offset, and function-pointer routes are absent, while eight homologous bodies and the constant-propagated inline lowering in `ScrollNewGroupPane::HandleMouseEvent` positively resolve why the out-of-line copy survives without a callsite.
- IDA disposition: supervisor catalog entry0369 applied, verified, and durably saved IDA-42L-001 through IDA-42L-010 and protected IDA-42L-011 at historical target checkpoint `A4A6BC82...AC02C4`; catalog0368 `64704F...E54642` is its byte-identical prestate/backup. The shared save later advanced through unrelated work to dated checkpoints `87D34CCD...500F2`, `83C20CE9...C294A9E`, and `D65C96CE...98F2D11`. The supervisor-supplied saved-IDB checkpoint for this bounded reread was `2CCA289F...70D7E851`; readback at that checkpoint confirms the exact four-byte enum, target function/name/type/comment/frame, GetPartRect name/type/comment/arguments, catalog0366 ordinal955 size-`0x110` class UDT, active mouse-handler/vtable dependency, bytes, and xrefs remained unchanged. Shared-IDB identity after that timestamp is authoritative only from the physical IDB and active-session metadata, not this report.
- Confidence: very strong for bytes, bounds, ABI, behavior, owner, source route, field width, enum values, helper route, retained-source classification, and formal CPP; strong for the inferred original member/enum lexemes. Exact original method and enum spelling is not present in symbols, but the selected names are the dominant high-probability family-consistent source names and are not left as raw labels.

## Supporting Research

- Live MCP database: `1da2b2ae`, worker PID `11900`, `is_analyzing:false`, `auto_analysis_ready:false`, Hex-Rays ready, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Bounded valid IDB-backed calls succeeded, so the health flag is context rather than an availability failure.
- Saved-IDB checkpoint used for accepted report research: SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, `143191140` bytes, last write `2026-07-29T15:00:32.0998001-04:00`; catalog0366 `EEF0C80D...A7997B`, catalog0367 `222DEBAD...99D043`, and catalog0368 `64704F81...E54642` are all historical checkpoints. Catalog0368 is also the byte-identical prestate backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B004-UID00042L-20260729_181833.i64`. Supervisor catalog entry0369 is the historical durable target-application checkpoint: SHA256 `A4A6BC82D18D9BA7E1B0FDFCD87CED2B9FD4551E9AFEF3CE0175237B6DAC02C4`, `143191991` bytes, saved `2026-07-30T06:48:02.4013060-04:00`, with applied/verified IDA-42L-001..010, protected/verified IDA-42L-011, exact bytes/xrefs/comments/frames, and `idb_save ok:true`. Later shared-save checkpoints include SHA256 `87D34CCD103CC97F107DBABF1CA089FCE223F1650D5376A0DCB48C0E46F500F2`, `143192020` bytes, saved `2026-07-30T07:11:07.1602926-04:00`; SHA256 `83C20CE9E13A19CA3C5501998110D490FA3D2D2EA5FE774AE1F880403C294A9E`, `143193954` bytes, saved `2026-07-30T07:36:29.3601106-04:00`; SHA256 `D65C96CEE79AB084596B633491F2A6AF57AC18B1CB966F86D6DD9088988F2D11`, `143193979` bytes, saved `2026-07-30T09:10:51.2682267-04:00`; and supervisor-supplied SHA256 `2CCA289FBF2BA0D2CEEF5F870AF560AD3BA6025109FB47A4D66E154F70D7E851`, `143192020` bytes, saved `2026-07-30T09:23:53.4855352-04:00`. Bounded MCP readback in active session `1da2b2ae` at the `2CCA...` checkpoint proved the catalog0369 target/dependency/protected state survived unchanged. Every global IDB hash here is timestamped evidence only; physical IDB/session metadata governs any later shared-state advance.
- Target document checkpoint at research start: SHA256 `27C451D6F7BF786C9CA75A8AD5D6B7E16AC086B1807F8593A2E0FB5D887B41F8`, `5774` bytes, 88 lines. Accepted ordinary implementation command `000000019764` produced the dated callback checkpoint `BDB57D2B...A3CC`; post-IDA ordinary reconciliation plus scoped validator command `000000019807` now reads SHA256 `499BAB9A78F4AB49AA22297197F645B440F140772AFA6ADF2D2AF387F4FA0A24`, `13165` bytes, 108 lines.
- Raw target bytes: exact 112-byte body SHA256 `87DB25794833D0D69688ED035EE9DC9668533C2CB1A4899EA09F20B77B471FB2` from PE raw offset `0x160dd0`.
- Direct predecessor bytes `[0x005619c7,0x005619d0)` are nine `0xcc` bytes. The successor begins with its own prologue at `0x00561a40`; the target's `retn 4` instruction is exactly `c2 04 00` at `[0x00561a3d,0x00561a40)`.
- Historical lead only: executed B008 report `executed-b-agent-research/B008/0001GS-ScrollNewGroupPaneRawAndInteractionHelpers-source-quality.md`, SHA256 `5D40DD53AE2B57D9E61F939A1C86B3B2FDF944D2FE3D68B1F9D63314EE664D07`. Its range/owner/behavior evidence remains valid, but this report independently rechecks liveness, clone family, source classification, types, formal source, current IDA state, scores, and manual coverage.
- Duplicate screening found no other active or executed report directly targeting UID00042L. Dated pre-lifecycle tracker checkpoint command `000000019805`, refreshed `2026-07-29T17:48:40-04:00`, records direct/additional/total report coverage `0/0/0`; the B008 aggregate report is support history, not a declared direct or additional UID00042L report. Later report-lifecycle changes may legitimately change those counts, so current tracker truth is authoritative only from the generated tracker itself.
- Dated pre-callback generated source checkpoints are validator command `000000019752`, refreshed `2026-07-29T15:33:08-04:00`, `auto-generated/NexusTK/social/Group.cpp` SHA256 `98B45D049D957A54E484C567D40712160DB0CDF076D7ECA5BF50AE15EDF5E409`, `27435` bytes/796 lines, and command `000000019759`, refreshed `2026-07-29T16:10:35-04:00`, SHA256 `D3E40E945FF401793947DE8DD0B3FA2B1615AF7BF902899A57416B0294568747`, `27435` bytes/796 lines. Dated supervisor semantic checkpoints command `000000019802`, refreshed `2026-07-29T17:43:08-04:00`, SHA256 `4E3DC6003DA28E39656616442D1D878F0F0BFCD9A90BABA4BD6CA8D6DF0EE2F6`, command `000000019812`, refreshed `2026-07-30T07:02:21-04:00`, SHA256 `3CE3BE6270C72A578636BEE7CF9B317EE9CCB53D607109B987B37B3D2A0E9E1D`, `27422` bytes/796 lines, and command `000000019887`, refreshed `2026-07-30T08:15:21-04:00`, SHA256 `6136FF9F09141369B2A12A6831E1DE98BB62151F956BC2A61E0F816750DC2336`, `27458` bytes/798 lines, established and preserved the accepted one-copy `92/94` body, absent `Group.h`, and UID0003CQ shared-scrollbar route. Current supervisor-owned global foreground refresh command `000000019890`, refreshed `2026-07-30T08:36:15-04:00`, reads `auto-generated/NexusTK/social/Group.cpp` SHA256 `44D14FCE613155FF6478621D345189E43499A0D58E1E1A905AD95C53E80BBDAC`, `27458` bytes/798 lines; it still emits UID00042L exactly once at `92/94` with the accepted body, includes `../ui/core/ScrollBar.h`, consumes `kScrollPanePartExtentBySkin` through the shared table route, and has no sibling `Group.h`.
- Dated pre-callback research tracker checkpoints are validator command `000000019753`, refreshed `2026-07-29T15:36:17-04:00`, SHA256 `A3A148C58B0D491183F43A80EF85685833079CB8D3698EA9B0C6715AC7E3DAF3`, `1677702` bytes/6632 lines; command19761; and command19779. Dated pre-lifecycle checkpoint command `000000019805`, refreshed `2026-07-29T17:48:40-04:00`, SHA256 `2FEFCCCE84D7AC363CBECEC1818CA5D9A4BBA2FEEE8412EC26F3F700D4B58454`, records the zero-report `92/94` row. Command `000000019812`, refreshed `2026-07-30T07:02:21-04:00`, tracker SHA256 `6AEA2B8B172B368AD2525B5403E9609BAEE9F585E183F6FAACB7F08DC9EB68B0`, interim command `000000019886`, refreshed `2026-07-30T08:07:46-04:00`, SHA256 `6F2D84C509E969A6A3B18B43352773A3947CC00C2F11F029119C2E69A2DE3100`, command `000000019887`, refreshed `2026-07-30T08:15:21-04:00`, tracker SHA256 `10ABDA6320862624215BD3AD0432AA74A1CE4511BF46318E07573509C1B5921A`, and command `000000019890`, refreshed `2026-07-30T08:36:15-04:00`, tracker SHA256 `C7C933E131C9FBEB3DA853ECA80716F679A8674306EBAB3015E9B88E78CB78B8`, `1678309` bytes/6633 lines, are historical. Latest observed bounded tracker refresh command `000000019891`, refreshed `2026-07-30T08:55:28-04:00`, tracker SHA256 `C7EB6279021B1F0F3C202F923358787C08CFA1C89F30F1A39CC53942601A5CC5`, `1678440` bytes/6633 lines, recorded UID00042L under `by-memory -> Not-Covered Files - Reconstructable` at `92/94`, combined `93.0`, reconstructable true, direct/additional/total `0/0/0`. That timestamped row is a durable checkpoint, not a permanent lifecycle/count assertion; after later report execution or tracker refresh, current truth is authoritative only from the physical generated tracker and its validator metadata. This tracker-only advance does not supersede command19890's generated CPP/H reconstruction checkpoint.

## Target

- Primary declared target: [UID:00042L] `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md`.
- Additional target UIDs: none.
- Required support destinations: [UID:0000CL] `by-class/ScrollNewGroupPane.md`; [UID:0000JS] `by-file/Group.md`; [UID:0001GS] `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`; [UID:0001GR] `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md`; [UID:000453] `by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md`; and boundary-only [UID:00042M] `by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md`.
- Queue source: `auto-generated/-ag-research-tracker.md`, `by-memory -> Not-Covered Files - Reconstructable`; the target was `87/89`, combined `88.0`, with zero report coverage.
- Historical creation mode was report-only source-quality research with no external mutation. The accepted ordinary callback and this post-IDA reconciliation changed only mapped ordinary by-* documents and this same report, using scoped validators; manual coverage and report lifecycle remain supervisor-owned and untouched by B004. IDA mutations/save were performed only by the supervisor and are recorded as catalog entry0369; B004 performed no IDA mutation or save.

## Current Target State

- Physical callback metadata is `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, and position `70`.
- The target retains the exact formal CPP definition for `ScrollNewGroupPane::SetHighlightedPart(ScrollNewGroupPart part)` and a blank formal H channel. Physical readback confirms neither formal channel drifted.
- Current prose records the exact range/body hash/instruction count/fences, historical no-function and current no-xref/pointer/interior-route negatives, eight-body clone family, active constant-thumb/constant-none lowerings, ABI/enum/field distinctions, helper/callback route, stale TextEditPane rejection, catalog0369's durable IDA result, and the target-specific no-drift readback at dated shared-save checkpoint `2CCA289F...70D7E851`; `D65C96CE...98F2D11`, `83C20CE9...C294A9E`, and `87D34CCD...500F2` are earlier checkpoints, while later shared-IDB truth remains external moving state.
- Manual coverage remained untouched by B004 and supervisor-owned. The supervisor subsequently applied and verified all five exact payloads through commands19894-19896 and confirmed both support no-ops: post-apply by-memory coverage is SHA256 `BECB2B9939F549434F86D7EA21AA86A7F7E8E25765371CFF083C6A91D1E6F44E`, `2097338` bytes/4747 lines; by-class coverage is SHA256 `EDC00B8A9E9EF17F045A09EBB9223AA941625B004050D671FF51609747A31E34`, `271998` bytes/625 lines; and by-file coverage is SHA256 `226B990E2D50956D9BE1A475C44333B7B2A03CD6C5CB4342D23AEE102815B35B`, `162777` bytes/317 lines. Currentness after those dated checkpoints remains authoritative only from the physical coverage files. Dated supervisor-owned command19890 confirmed generated semantic closure with one accepted UID00042L body at `92/94`, the required `../ui/core/ScrollBar.h` dependency and shared-table consumption, and no `Group.h`; latest observed bounded tracker-only command19891 recorded the zero-report tracker row at `92/94` at its timestamp. Physical tracker metadata remains authoritative after any later lifecycle/refresh change. Command19802/19805/19812/19886/19887 and command19890's tracker identity remain dated tracker checkpoints.
- Bounded readback at dated checkpoint `2CCA289F...70D7E851` confirmed catalog0369's exact target function `[0x005619d0,0x00561a40)` as `ScrollNewGroupPane__SetHighlightedPart`, size `0x70`, prototype `void __thiscall(ScrollNewGroupPane *this, ScrollNewGroupPart part)`, blank AR/AP/FR channels, and the accepted FP literal. Incoming target xrefs were zero; target body SHA256 remained `87DB25794833D0D69688ED035EE9DC9668533C2CB1A4899EA09F20B77B471FB2`; predecessor padding and the separate successor were exact.
- Durable target frame is exactly `rect +0x8/0x10 struct RectBounds`, saved registers `+0x1c/4`, return address `+0x20/4`, and `part +0x24/4 ScrollNewGroupPart`. The report-predicted `var_4 +0x18/4` did not materialize and is intentionally absent rather than invented.
- Catalog0369 creates one ordinal956 four-byte `ScrollNewGroupPart` enum with all six exact values and preserves catalog0366's ordinal955 size-`0x110`, 13-member `ScrollNewGroupPane` UDT unchanged. The exact class member remains `unsigned __int16 m_scrollSkinIndex +0xf8`; `Pane`, `Point`, and `RectBounds` are unchanged.
- The same bounded `2CCA289F...70D7E851` readback preserved catalog0369's `[0x00561740,0x005619c7)` `ScrollNewGroupPane__GetPartRect`, exact class/enum/output prototype and FP comment, physical arguments `part +0x2c/4 ScrollNewGroupPart` and `outRect +0x30/4 RectBounds *`, unchanged nonargument locals/interior comments, helper body SHA256 `70D64415...2F17`, and all thirteen incoming code xrefs. Protected `sub_560B00` remained size `0x1e1` with its historical prototype/frame/four blank comments, exact body SHA `1681036A...4F57`, sole vtable data xref, and cell bytes `00 0B 56 00`.
- Historical command19752/19759 generated topology and command19802/19812/19887 semantic checkpoints are retained as dated evidence. Dated supervisor-owned command19890 confirmed that `Group.cpp` emitted UID00042L once at `92/94` with the accepted body, incorporated UID0003CQ's `../ui/core/ScrollBar.h` dependency and shared-table use, and had no sibling `Group.h`. This report does not invent a partial class declaration.

## Executive Recommendation

1. Treat the raw body as retained source, not as unreachable garbage. The compiler emitted the general out-of-line member while constant-propagating the only visible active uses into `HandleMouseEvent`.
2. Keep the exact child and route. Do not fold it into `HandleMouseEvent`, `GetPartRect`, UID0001GS, TextEditPane, or UID00042M.
3. Preserve the current formal CPP body and blank target H channel. The method's explicit 4-byte enum argument and one-byte state field are both required.
4. Ordinary callback physically applied UID00042L `92/94` and UID0000CL `88/90`; all other support scores were retained as listed.
5. Preserve catalog0369's applied atomic IDA result. It removes the target function-table gap and helper decompiler labels while preserving bytes, xrefs, fences, vtables, unrelated types, sibling functions, and protected handler state.
6. Preserve the exact supervisor-applied manual coverage insert/replacements and the two verified no-op dispositions supplied below; B004 did not edit those files.

## Supervisor Active Recheck

- Recheck target/report hashes before Gate 1 because project artifacts are concurrently refreshed.
- B004's pre-action bounded reconciliation verified all eleven IDA rows against historical prestate `64704F...E54642`. Supervisor catalog entry0369 then applied, verified, and saved the accepted actions at historical target checkpoint `A4A6BC82...AC02C4`. B004 found no target-specific drift through later checkpoints `87D34CCD...500F2`, `83C20CE9...C294A9E`, and `D65C96CE...98F2D11`; the bounded target, GetPartRect, types, comments, frames, bytes, padding, xrefs, and protected handler/vtable readback was repeated at dated checkpoint `2CCA289F...70D7E851`, and the target state was exact. Fresh Gate 1/final Gate 2 must bind any current-state conclusion to a fresh physical IDB readback rather than treating this dated hash as permanent.
- Gate 1 must validate the retained-source classification, complete formal CPP/blank-H disposition, score basis, 88-row atomic ledger, 11-row IDA handoff, and exact manual coverage operations.
- Historical supervisor Gate 2A verified every ordinary target/support detail after callback and the serial scoped validator evidence from commands19807-19812, including each deferred generated-refresh result.
- Gate 2B mutation/save was supervisor-owned and is historicalized as catalog entry0369; B004 did not mutate or save IDA.
- This callback reconciles the same report and affected ordinary docs to literal saved readback. Supervisor Gate 2A and manual-coverage application/verification are completed historical facts; fresh supervisor Gate 1/final Gate 2, generated-semantic recheck, and lifecycle decisions remain supervisor-owned. Report execution/archive state is authoritative only from the artifact's actual path plus validator-owned status/history metadata.

## Inference Research Guidance Check

- The analysis follows the current B-agent inference standard and ignores Wave2/Wave3 staging terminology as stale process language.
- Binary fact and inference are separated. Exact bytes, ranges, instructions, xrefs, types, RTTI, comments, frames, helper calls, and clone matches are direct evidence. Method/enum/member lexemes are source-facing inferences ranked against the full family.
- No raw label is accepted as final source. `sub_561740`, absent raw-start function state, `_BYTE`, and stack `arg_0`/`var_14` spellings are translated into the highest-probability class/member/enum source model.
- The no-xref result was investigated through multiple independent routes and then explained through positive compiler-lowering evidence. It is not deferred as “needs investigation.”
- Final source prioritizes exact execution first and human mid-2000s C++ source shape second; family-consistent naming is used where original symbols are unavailable.

## Heuristic / Inference Reanalysis And Validation

- `ScrollNewGroupPane` is not inferred: MSVC RTTI names exist at `0x0064fa10`, `0x0064fa24`, `0x0064fa34`, `0x0064fa50`, `0x0064fa6c`, `0x0064fa80`, and type descriptor `0x00678fc0`. Constructor vtable stores bind the class at `0x00623f1c`, `0x00623f68`, and `0x00623f98`.
- `SetHighlightedPart` is the strongest method name. The identical family shape is already named `ScrollPane__SetHighlightedPart`, `RankingEventScrollPane_SetHighlightedPart`, and `ScrollCollectionPane__SetHighlightedPart`; the target's state is explicitly highlight rather than active/pressed or volume hover.
- `ScrollNewGroupPart` is the strongest enum name. The class-specific family uses `RankingScrollPart`, `ScrollCollectionPart`, `ScrollVolumePart`, and `ScrollPanePart`; this class's docs and child formals already consistently use `ScrollNewGroupPart`.
- `m_highlightPart` is exact role-level naming: paint/input/reset paths distinguish `+0x103` highlight from `+0x104` active/pressed state. The target only changes `+0x103`.
- The state field is a signed one-byte storage member, not a 4-byte enum member. Adjacent state begins at `+0x104`, loads/stores use byte operations, and `0xff` represents `-1`. The explicit parameter remains a 4-byte C++ enum on the stack, proven by `retn 4` and modeled homolog frames.
- `kScrollNewGroupPartNone = -1` and values `0..4` are exact behavioral values. `HitTestPart` enumerates the five geometries, `GetPartRect` switches on those five values, and constructor/reset paths store `0xff` for no part.
- `GetPartRect` is exact family terminology and the current best source name for `0x00561740`; thirteen current code xrefs include both target callsites.
- The inherited slot `+0x20` is `InvalidateRect(RectBounds *)`, established by pane-family docs and both modeled homolog decompilations.

## Evidence Standards Used

- Exactness: byte ranges and state transitions must agree between PE bytes, raw instruction decoding, modeled homologs, current docs, and generated formal source.
- Liveness: direct xrefs alone are insufficient; VA/RVA/raw-offset pointers, branch operands, vtables, callback tables, inline copies, homologs, and compiler retention patterns are all evaluated.
- Source classification: a method-shaped prologue/epilogue is not enough. Class-local fields, helper calls, family clones, active inlining, fences, and semantic role must converge.
- Type safety: recommend only types with exact sizes/offsets and protect existing `Pane`, `Point`, and `RectBounds` layouts.
- Naming: prefer exact RTTI/symbol evidence, then repeated family conventions and role evidence. Never retain `sub_`, `loc_`, `arg_`, or anonymous byte-field names in formal source.
- Score discipline: raw/no-route evidence can cap confidence but cannot excuse incomplete investigation. Score rises only because the blocker is positively resolved.

## Evidence Checked

- Live MCP: `idb_list`, `server_health`, `lookup_funcs`, `inspect_items`, `get_comments`, `get_bytes`, `insn_query`, `xrefs_to`, `xref_query`, `find_bytes`, `entity_query`, `type_query`, `type_inspect`, `analyze_function`, `decompile`, `stack_frame`, and `make_signature_for_range` against database `1da2b2ae`.
- Pre-action reconciliation against physical `64704F...E54642` used bounded `idb_list`, `server_health`, `type_query`, `type_inspect`, `lookup_funcs`, `inspect_items`, `get_comments`, `xref_query`, `get_bytes`, and `stack_frame` calls. Supervisor catalog entry0369 then applied/read back IDA-42L-001..010, protected row011, and durably saved historical target checkpoint `A4A6BC82...AC02C4`. The same bounded read-only families were repeated at dated shared-save checkpoint `2CCA289F...70D7E851`; exact target/helper names, types, frames, comments, bytes and xrefs, ordinal956 enum/ordinal955 class UDT, and protected handler/vtable state all matched catalog0369. The intervening `87D34CCD...500F2`, `83C20CE9...C294A9E`, and `D65C96CE...98F2D11` checkpoints are earlier history. B004's role remains documentation reconciliation only.
- Target raw bytes and 46 decoded instructions over `[0x005619d0,0x00561a40)`; predecessor/successor bytes; target PE raw offset `0x160dd0`; target body SHA256.
- Liveness checks: incoming code/data xrefs; exact VA bytes `d0 19 56 00`; RVA bytes `d0 19 16 00`; raw-offset bytes `d0 0d 16 00`; proposed-name collision searches; and all internal branch destinations.
- Clone search: wildcarded 112-byte signature across `.text`; eight matches at `0x0041e780`, `0x0045a990`, `0x0055dea0`, `0x00560520`, `0x005619d0`, `0x00562e80`, `0x00564330`, and `0x00565170`.
- Active lowering: full assembly/decompile of `sub_560B00` `[0x00560b00,0x00560ce1)`, especially `0x00560bfd-0x00560c3a` and mouse-up clearing at `0x00560b5f-0x00560b87`.
- Types at the accepted report checkpoint were `ScrollNewGroupPane` absent and `ScrollNewGroupPart` absent. Catalog0366 later supplied exact ordinal955 size-`0x110` `ScrollNewGroupPane`; catalog0369 creates exact ordinal956 four-byte `ScrollNewGroupPart`. `Pane` size `0xf8`, `Point` size `8` with `y,x`, and `RectBounds` size `0x10` remain unchanged.
- Five ordinary destinations remain byte-identical to the post-B004 reconciliation inventory. The two shared destinations advanced additively under B002's later UID0003CQ shared-scrollbar callback: current [UID:0000CL] `by-class/ScrollNewGroupPane.md` is SHA256 `7A3C36C8EF4CA79A071E7E4F6F51D8AE1AF2FF10469C7626CB88C5BA59727161`, `48078` bytes/234 lines, and current [UID:0000JS] `by-file/Group.md` is SHA256 `E2816C4DFFFFB57B2C662A577F7B6AFE7ABA774A2C93510A474D4CE8CCE5464B`, `41827` bytes/215 lines. Historical post-B004 reconciliation identities `481CF657...9129` and `28E0731E...2D1B` remain dated checkpoints only. Physical readback confirms UID0003CQ added the shared scrollbar table/field alias and `ScrollBar.h` dependency while retaining every UID00042L SetHighlightedPart/catalog0369/inline-lowering/source-route/score/history claim without removal or contradiction. Manual coverage anchors were re-read at the dated repair checkpoints recorded below; dated command19802 generated semantics and command19805 pre-lifecycle tracker semantics are also recorded. These supervisor-owned artifacts may move, so final-use truth comes from fresh physical readback rather than treating any checkpoint hash as permanent.
- Historical reports: B008 UID0001GS and B002 Group-family reports. Their valid evidence is retained; their absence of the current clone/inline/IDA handoff is corrected here.
- Failed/unavailable checks: none required for the recommendation. A broad operand scan returned no positive direct target route, consistent with exact xref/pointer results; no fallback-only conclusion is used.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 00042L | Exact range is `[0x005619d0,0x00561a40)`. | very strong | Raw instructions and fences | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Address Range And Boundary` | incorporate | applied |
| C02 | 00042L | Exact 112-byte body SHA is `87DB2579...71FB2`. | very strong | PE/MCP bytes | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Evidence` | incorporate | applied |
| C03 | 00042L | `[0x005619c7,0x005619d0)` is nine-byte `0xcc` predecessor padding. | very strong | MCP bytes/items | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Address Range And Boundary` | incorporate | applied |
| C04 | 00042L | `retn 4` occupies `[0x00561a3d,0x00561a40)` and is inside the child. | very strong | Raw decode | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Address Range And Boundary` | incorporate | applied |
| C05 | 00042M | Successor starts independently at `0x00561a40`. | very strong | Item/prologue and support doc | `by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md` / `## Address Range And Boundary` | already-present | already-present |
| C06 | 00042L | Historical IDA prestate had code items but no function object; catalog0369 now has the exact durable target function. | very strong | historical lookup/items plus catalog0369 function readback | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Evidence` | historicalize | applied |
| C07 | 00042L | Incoming start code/data xrefs are zero. | very strong | xrefs_to/xref_query | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Evidence` | incorporate | applied |
| C08 | 00042L | VA, RVA, and raw-offset pointer encodings have zero matches. | very strong | find_bytes | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Evidence` | incorporate | applied |
| C09 | 00042L | All interior branch-target xrefs originate inside the same body. | very strong | xrefs_to internal labels | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Evidence` | incorporate | applied |
| C10 | 00042L | The wildcarded method shape occurs exactly eight times. | very strong | signature/find_bytes | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Evidence` | incorporate | applied |
| C11 | 00042L | Four clone starts are current modeled source functions; zero-xref modeled clones disprove no-xref-as-glue. | very strong | lookup/items/xrefs | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Reconstruction Notes` | incorporate | applied |
| C12 | 00042L | HandleMouseEvent contains the constant-part inline lowering for thumb highlight. | very strong | 0x560bfd-0x560c3a | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Evidence` | incorporate | applied |
| C13 | 000453 | HandleMouseEvent contains the constant-part inline lowering for thumb highlight. | very strong | 0x560bfd-0x560c3a | `by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md` / `## Evidence` | incorporate | applied |
| C14 | 00042L | Mouse-up contains the constant-none clearing specialization. | strong | 0x560b5f-0x560b87 | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Evidence` | incorporate | applied |
| C15 | 000453 | Mouse-up contains the constant-none clearing specialization. | strong | 0x560b5f-0x560b87 | `by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md` / `## Evidence` | incorporate | applied |
| C16 | 00042L | Classification is retained source method, not compiler-generated glue or dead data. | very strong | C01-C15 convergence | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Status` | incorporate | applied |
| C17 | 00042L | ABI is `void __thiscall(..., ScrollNewGroupPart part)`. | very strong | ECX receiver, stack arg, retn4, homologs | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Reconstruction Notes` | incorporate | applied |
| C18 | 00042L | Equal old/new values return without invalidation or store. | very strong | cmp/jz | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Behavior` | incorporate | applied |
| C19 | 00042L | Old non-none part rectangle is resolved and invalidated first. | very strong | 0x5619f1-0x561a09 | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Behavior` | incorporate | applied |
| C20 | 00042L | New non-none part rectangle is resolved and invalidated second. | very strong | 0x561a0c-0x561a25 | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Behavior` | incorporate | applied |
| C21 | 00042L | New state is stored once at `+0x103`. | very strong | 0x561a28 | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Behavior` | incorporate | applied |
| C22 | 00042L | `m_highlightPart` is signed one-byte storage. | very strong | byte ops, adjacency, sentinel | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Touched State And Calls` | incorporate | applied |
| C23 | 0000CL | `m_highlightPart` is signed one-byte storage. | very strong | byte ops, adjacency, sentinel | `by-class/ScrollNewGroupPane.md` / `## Scrollbar Part And Field Alias Notes` | incorporate | applied |
| C24 | 00042L | `ScrollNewGroupPart` parameter is a four-byte enum. | very strong | retn4 and homolog frames | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Reconstruction Notes` | incorporate | applied |
| C25 | 0000CL | `ScrollNewGroupPart` parameter is a four-byte enum. | very strong | retn4 and homolog frames | `by-class/ScrollNewGroupPane.md` / `## Scrollbar Part And Field Alias Notes` | incorporate | applied |
| C26 | 00042L | Enum values are none=-1 and five parts 0..4. | very strong | HitTest/GetPartRect/constructor | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Reconstruction Notes` | incorporate | applied |
| C27 | 0000CL | Enum values are none=-1 and five parts 0..4. | very strong | HitTest/GetPartRect/constructor | `by-class/ScrollNewGroupPane.md` / `## Scrollbar Part And Field Alias Notes` | incorporate | applied |
| C28 | 00042L | `SetHighlightedPart` is the best source method name. | strong | three named exact homologs and role | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Reconstruction Notes` | incorporate | applied |
| C29 | 0000CL | `SetHighlightedPart` is the best source method name. | strong | three named exact homologs and role | `by-class/ScrollNewGroupPane.md` / `## Method Notes` | incorporate | applied |
| C30 | 0001GR | `GetPartRect` at 0x561740 is the exact rectangle helper. | very strong | thirteen xrefs and decompile | `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md` / `## Behavior` | incorporate | already-present |
| C31 | 00042L | Vtable slot +0x20 is inherited `InvalidateRect`. | very strong | homolog decompiles and pane docs | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Touched State And Calls` | incorporate | applied |
| C32 | 00042L | Return contract is void with no result state. | very strong | epilogue and homologs | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Reconstruction Notes` | incorporate | applied |
| C33 | 00042L | Canonical owner remains UID0000CL. | very strong | class/file/order evidence | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / header `CANONICAL_OWNER` field | already-present | already-present |
| C34 | 00042L | Emitter remains UID0000CL. | very strong | class/file/order evidence | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / header `EMITTER_UIDS` field | already-present | already-present |
| C35 | 00042L | Emitter position remains 70. | very strong | class/file/order evidence | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / header `EMITTER_POSITION_OPTIONAL` field | already-present | already-present |
| C36 | 00042L | Existing exact child range remains unsplit. | very strong | complete body/fences | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Address Range And Boundary` | already-present | already-present |
| C37 | 00042L | Current formal CPP body is exact and should be retained. | very strong | instruction-to-source comparison | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `RECONSTRUCTION_CPP CODE` | already-present | already-present |
| C38 | 00042L | Target formal H remains blank by child topology. | strong | class-owned declaration route | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `RECONSTRUCTION_H CODE` | already-present | already-present |
| C39 | 00042L | Item Summary should gain retained-source/inline-lowering proof without metadata repetition. | strong | generated reporting rules | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / header `Item Summary` field | incorporate | applied |
| C40 | 00042L | Raise target score to 92/94. | strong | blocker closure and exact formals | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / header `COMPLETION` and `CONFIDENCE` fields | incorporate | applied |
| C41 | 0001GS | Parent remains a non-emitting non-reconstructable split index. | very strong | exact children own bodies | `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md` / `## Status` | already-present | already-present |
| C42 | 0001GS | Parent should record UID00042L's retained-source and inline-lowering resolution. | very strong | exact child and active lowering | `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md` / `## Reconstruction Notes` | incorporate | applied |
| C43 | 0001GS | Parent score remains 88/90. | very strong | split-index scope | `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md` / header `COMPLETION` and `CONFIDENCE` fields | already-present | already-present |
| C44 | 0000CL | Class support should record exact clone and inline-lowering proof. | strong | signature family and active lowering | `by-class/ScrollNewGroupPane.md` / `## Evidence Notes` | incorporate | applied |
| C45 | 0000CL | Class support should record exact 0x110 UDT, enum, and field-width proof. | strong | RTTI, constructor, types | `by-class/ScrollNewGroupPane.md` / `## Scrollbar Part And Field Alias Notes` | incorporate | applied |
| C46 | 0000CL | Raise class support score to 88/90. | strong | target and class-family closure | `by-class/ScrollNewGroupPane.md` / header `COMPLETION` and `CONFIDENCE` fields | incorporate | applied |
| C47 | 0000CL | Class owner and emitter remain UID0000JS. | very strong | established file route | `by-class/ScrollNewGroupPane.md` / header `CANONICAL_OWNER` and `EMITTER_UIDS` fields | already-present | already-present |
| C48 | 0000JS | Group remains the source file root. | strong | class ownership and generated route | `by-file/Group.md` / `## Proposed Contents` | already-present | already-present |
| C49 | 0000JS | Group should record UID00042L as a retained ScrollNewGroupPane source method. | strong | class ownership and generated route | `by-file/Group.md` / `## Proposed Contents` | incorporate | applied |
| C50 | 0000JS | Group score remains 90/86. | strong | bounded target scope | `by-file/Group.md` / header `COMPLETION` and `CONFIDENCE` fields | already-present | already-present |
| C51 | 0001GR | PartRect support should record target callsites `0x005619fc` and `0x00561a18`. | very strong | current xrefs | `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md` / `## Caller And Support Evidence` | incorporate | applied |
| C52 | 0001GR | PartRect support records catalog0369's exact applied name/type/comment/frame state and thirteen incoming code xrefs. | very strong | catalog0369 durable type/comment/frame/xref readback | `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md` / `## IDA MCP Evidence` | incorporate | applied |
| C53 | 000453 | HandleMouseEvent support should record its source-level lowering relationship to UID00042L. | very strong | live assembly/decompile | `by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md` / `## Evidence` | incorporate | applied |
| C54 | 00042M | BeginPartInteraction remains boundary-only support. | very strong | successor prologue/docs | `by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md` / `## Status` | already-present | already-present |
| C55 | 00042M | BeginPartInteraction score and route remain unchanged at 88/90 through UID0000CL. | very strong | successor metadata/docs | `by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md` / header metadata fields | already-present | already-present |
| C56 | 00042M | BeginPartInteraction formal CPP remains unchanged. | very strong | inspected formal source | `by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md` / `RECONSTRUCTION_CPP CODE` | already-present | already-present |
| C57 | 00042M | BeginPartInteraction formal H remains unchanged. | very strong | inspected formal source | `by-memory/0x00561a40-0x00561b00.ScrollNewGroupPaneBeginPartInteractionRaw.md` / `RECONSTRUCTION_H CODE` | already-present | already-present |
| C58 | 00042L | Historical B008 evidence remains valid but its unresolved liveness wording is superseded. | strong | executed report/current MCP | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Changes` | historicalize | applied |
| C59 | 0001GS | Historical B008 evidence remains valid but its unresolved liveness wording is superseded. | strong | executed report/current MCP | `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md` / `## Changes` | historicalize | applied |
| C60 | 00042L | Generated TextEditPane ownership is stale pollution for this target. | very strong | RTTI/class-local state/Group owner | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Reconstruction Notes` | reject-stale | applied |
| C61 | 0001GS | Generated TextEditPane ownership is stale pollution for the parent range. | very strong | RTTI/class-local state/Group owner | `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md` / `## Rejected Ownership And Source Routes` | reject-stale | already-present |
| C62 | 0000CL | Generated TextEditPane ownership is stale pollution for the class route. | very strong | RTTI/class-local state/Group owner | `by-class/ScrollNewGroupPane.md` / `## Evidence Notes` | reject-stale | applied |
| C63 | 0000JS | Generated TextEditPane ownership is stale pollution for the Group source route. | very strong | RTTI/class-local state/Group owner | `by-file/Group.md` / `## Boundary And Data Notes` | reject-stale | applied |
| C64 | 00042L | Exact four-byte ordinal956 `ScrollNewGroupPart` enum is durably present with all six accepted members/values. | very strong | catalog0369 applied/verified/save readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-001` | incorporate | applied |
| C65 | 00042L | Catalog0366's exact ordinal955 size-0x110 `ScrollNewGroupPane` UDT was verified/protected without duplicate or coercion. | very strong | catalog0369 protected readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-002` | already-present | already-present |
| C66 | 00042L | Exact function `[0x5619d0,0x561a40)` is durably defined. | very strong | catalog0369 complete range/body/fence readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-003` | incorporate | applied |
| C67 | 00042L | Target function is durably named `ScrollNewGroupPane__SetHighlightedPart`. | very strong | catalog0369 unique-name readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-004` | incorporate | applied |
| C68 | 00042L | Exact target function prototype is durably applied. | very strong | catalog0369 ABI/type readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-005` | incorporate | applied |
| C69 | 00042L | Target frame is durably normalized to complete `RectBounds rect`; predicted `var_4 +0x18` is absent. | very strong | catalog0369 physical frame readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-006` | incorporate | applied |
| C70 | 00042L | Exact target function-repeatable comment is durably applied with other channels blank. | very strong | catalog0369 comment readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-007` | incorporate | applied |
| C71 | 0001GR | Helper is durably named `ScrollNewGroupPane__GetPartRect`. | very strong | catalog0369 exact name/range readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-008` | incorporate | applied |
| C72 | 0001GR | Exact GetPartRect prototype and physical `part`/`outRect` frame arguments are durably applied with thirteen incoming code xrefs preserved. | very strong | catalog0369 ABI/frame/xref readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-009` | incorporate | applied |
| C73 | 0001GR | Exact GetPartRect function-repeatable comment is durably applied with other channels blank. | very strong | catalog0369 comment readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-010` | incorporate | applied |
| C74 | 000453 | HandleMouseEvent bytes/range/frame/comments/vtable route were protected and verified unchanged. | very strong | catalog0369 protected function/vtable readback | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## IDA Rename / Type / Comment Recommendations` / `IDA-42L-011` | already-present | already-present |
| C75 | 00042L | The absent target manual by-memory coverage row was inserted after UID0001GS and before UID0001GT. | very strong | supervisor command19894 post-apply row/address-order readback | `by-memory/-coverage-report.md` / `## Covered Items` / UID00042L row | incorporate | applied |
| C76 | 0001GS | The stale parent manual coverage row was replaced with the exact no-loss split-index payload. | very strong | supervisor command19894 post-apply row readback | `by-memory/-coverage-report.md` / `## Covered Items` / UID0001GS row | incorporate | applied |
| C77 | 0001GR | The stale part-rect manual coverage row was replaced with the exact thirteen-caller payload. | very strong | supervisor command19894 post-apply row readback | `by-memory/-coverage-report.md` / `## Covered Items` / UID0001GR row | incorporate | applied |
| C78 | 0000CL | The stale class manual coverage row was replaced with the no-loss merged row preserving UID0003CQ/UID000450/UID000451 detail and adding UID00042L. | strong | supervisor command19895 post-apply row readback | `by-class/-coverage-report.md` / `## Covered Items To Replicate` / UID0000CL row | incorporate | applied |
| C79 | 0000JS | The stale file manual coverage row was replaced with the no-loss merged 90% row preserving range/position clone and vtable/destructor detail while adding UID00042L and shared-scrollbar routing. | strong | supervisor command19896 post-apply row readback | `by-file/-coverage-report.md` / `## Covered Items To Replicate` / UID0000JS row | incorporate | applied |
| C80 | 000453 | Post-apply verification confirms no direct manual row is required; score/path remain unchanged and no row was invented. | strong | supervisor command19894 post-apply no-op readback | `by-memory/-coverage-report.md` / `## Covered Items` / UID000453 no-op disposition | not-applicable | excluded-with-reason |
| C81 | 00042M | Post-apply verification confirms boundary-only inspection does not justify a direct manual row. | strong | supervisor command19894 post-apply no-op readback | `by-memory/-coverage-report.md` / `## Covered Items` / UID00042M no-op disposition | not-applicable | excluded-with-reason |
| C82 | 00042L | Dated supervisor-owned command19890 confirmed generated semantic closure: Group.cpp emitted UID00042L exactly once at 92/94 with the accepted body and incorporated the ScrollBar header/shared-table route; commands19752/19759/19802/19812/19887 are historical. | very strong | exact dated command19890 generated identity, include, shared-table uses, and emitter block; coverage commands19894-19896 do not alter this generated disposition | `auto-generated/NexusTK/social/Group.cpp` / UID0000CL include plus UID00042L emitter block | already-present | already-present |
| C83 | 00042L | Dated command19890 generated topology had no `auto-generated/NexusTK/social/Group.h`; command19802/19812/19887 are earlier dated closure checkpoints. | very strong | exact dated command19890 generated topology | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## Supporting Research` | already-present | already-present |
| C84 | 00042L | Latest observed bounded command19891 tracker checkpoint recorded UID00042L under Not-Covered Files - Reconstructable at 92/94 with direct/additional/total 0/0/0; command19753/19761/19779/19805/19812/19886/19887/19890 tracker identities are historical, and physical validator metadata governs later lifecycle/count truth. | very strong | exact timestamped command19891 tracker identity and row | `auto-generated/-ag-research-tracker.md` / `## by-memory` / `### Not-Covered Files - Reconstructable` / UID00042L row | already-present | already-present |
| C85 | 00042L | Open questions close to deterministic directions. | strong | full evidence matrix | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## Open Questions With Attempted Resolution` | incorporate | already-present |
| C86 | 00042L | Unproven original lexical spellings remain the only score cap. | strong | full evidence matrix | `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md` / `## Status` | incorporate | applied |
| C87 | 00042L | Third-party import is not applicable to this project-owned RTTI class method. | very strong | project-owned RTTI class | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## Inference Research Guidance Check` | not-applicable | excluded-with-reason |
| C88 | 00042L | Wave2/Wave3 staging is rejected as stale for this report. | very strong | current workflow rule | `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md` / `## Inference Research Guidance Check` | reject-stale | already-present |

## Positive Evidence Summary

- The target decodes into one complete cookie-protected member body with a conventional prologue, one 16-byte local rectangle, one explicit stack argument, and `retn 4`.
- Every state/call operation has a direct source-level role: read old highlight, compare new part, resolve/invalidate old, resolve/invalidate new, store one-byte new highlight.
- The wildcarded code shape appears eight times in the executable. Modeled homologs prove the same high-level source method and ABI; raw homologs occupy the same aligned position in class-local scrollbar families.
- `HandleMouseEvent` contains a constant-propagated copy of the transition for `part == 2`, eliminating the runtime `part != none` branch and storing `2`; mouse-up similarly specializes clearing to none.
- RTTI proves the class identity. Constructor and sibling types prove the exact 0x110 tail layout. Hit-test/geometry paths prove enum values and member roles.
- The selected C++ has no decompiler artifacts and reproduces all observable behavior.

## IDA MCP Facts

- Historical catalog0368/6470 physical identity was independently recomputed, and live session `1da2b2ae` remained healthy during pre-action bounded queries. Supervisor catalog0369 then applied/read back the accepted actions and saved historical target checkpoint `A4A6BC82...AC02C4`. Target-specific readback in that session at dated shared-save checkpoint `2CCA289F...70D7E851` matched the exact applied state; `D65C96CE...98F2D11`, `83C20CE9...C294A9E`, and `87D34CCD...500F2` are earlier checkpoints. The report does not assert that any global hash remains current after its timestamp.
- Historical `lookup_funcs 0x005619d0` returned `Not a function`. Catalog0369 current readback is exact `ScrollNewGroupPane__SetHighlightedPart`, `[0x005619d0,0x00561a40)`, size0x70, with the separate successor `0x00561a40` still not a function.
- Catalog0369 target comments are AR absent, AP absent, FR absent, and the exact accepted FP literal; its physical frame is `rect +0x8/0x10 struct RectBounds`, saved +0x1c, return +0x20, and `part +0x24/4 ScrollNewGroupPart`, with no predicted `var_4` member.
- `xrefs_to 0x005619d0`: zero incoming xrefs. Internal branch labels have only in-range predecessors.
- `find_bytes`: no `0x005619d0` VA, RVA, or raw-file-offset pointer encodings; wildcard signature has eight matches.
- Historical helper prestate was `sub_561740` with low-byte part argument and four blank comment channels. Catalog0369 current readback is `ScrollNewGroupPane__GetPartRect`, size0x287, exact typed class/enum/output prototype, physical `part +0x2c/4` and `outRect +0x30/4`, exact accepted FP, AR/AP/FR absent, and thirteen incoming code xrefs including target callsites `0x005619fc` and `0x00561a18`.
- `lookup_funcs 0x00560b00`: `sub_560B00`, size `0x1e1`, current prototype `char __thiscall(int this, int)`, one data xref from secondary vtable slot `0x00623f6c`, all four comment channels absent.
- At accepted-report checkpoint `412DA7E8...519CD`, both target types were absent. Catalog0366 created exact ordinal955 `ScrollNewGroupPane`; catalog0369 created ordinal956 `ScrollNewGroupPart` and preserved `Pane`, `Point`, `RectBounds`, and all protected types unchanged.
- Catalog0369 readback confirms the applied function/type names are unique and collision-free.

## Function / Child Inventory

| Range | Current IDA state | Source role | Disposition |
| --- | --- | --- | --- |
| `[0x00561740,0x005619c7)` | `ScrollNewGroupPane__GetPartRect`, modeled 0x287-byte function | `ScrollNewGroupPane::GetPartRect` | Catalog0369-applied support identity/type/comment; thirteen xrefs preserved. |
| `[0x005619c7,0x005619d0)` | nine-byte data item of `0xcc` | alignment | Outside target; preserve. |
| `[0x005619d0,0x00561a40)` | `ScrollNewGroupPane__SetHighlightedPart`, modeled 0x70-byte function | `ScrollNewGroupPane::SetHighlightedPart` | Primary target; catalog0369-applied identity/type/comment/frame and retained formal emitter. |
| `[0x00561a40,0x00561b00)` | decoded code, no function object | `ScrollNewGroupPane::BeginPartInteraction` | Distinct successor UID00042M; preserve. |
| `[0x00561b00,0x00561bc0)` | `sub_561B00`, modeled function | `UpdateActiveInteraction` | Distinct later child. |

Eight same-shape set-highlight/hover bodies:

| Address | Family role | Current function state | Incoming start xrefs |
| --- | --- | --- | --- |
| `0x0041e780` | FittingRoom `SetHotPart` | raw/no function | 0 |
| `0x0045a990` | RankingEvent `SetHighlightedPart` | modeled/named/typed | 0 |
| `0x0055dea0` | generic ScrollPane `SetHighlightedPart` | modeled/named/typed | 1 |
| `0x00560520` | ScrollSpellInventory `SetHoverPart` | raw/no function | 0 |
| `0x005619d0` | ScrollNewGroup `SetHighlightedPart` | modeled/named/typed by catalog0369 | 0 |
| `0x00562e80` | ScrollCollection `SetHighlightedPart` | modeled/named/typed | 0 |
| `0x00564330` | ScrollInventory highlight setter | raw/no function | 0 |
| `0x00565170` | ScrollVolume `SetHoverPart` | modeled/named/typed | 0 |

## Direct Xref / Caller Inventory

- No direct caller, vtable cell, function pointer, data pointer, VA pointer, RVA pointer, or raw-offset pointer targets `0x005619d0`.
- No external branch enters an interior target label. The start's outgoing fall-through xref to `0x005619d1` and all other label xrefs are internal control flow.
- The positive liveness route is optimized source use, not a static entrypoint: `sub_560B00` at `0x00560bfd-0x00560c3a` performs the same transition with constant `part = 2`. It invalidates the prior non-none part, invalidates thumb part 2, and stores 2 at `+0x103`.
- Mouse-up at `0x00560b5f-0x00560b87` specializes the none transition by invalidating the old non-none part and storing `0xff`.
- `GetPartRect` has thirteen callers. The two target calls are exact and demonstrate the target remains integrated with the class-local geometry helper even though no caller targets the target start.
- Zero static entry routes therefore describe compiler lowering/retention, not absence of source semantics.

## Documentation Evidence And IDA Status

- UID00042L records catalog0369's exact applied target identity/type/comment/physical frame while retaining the clone/inlining/source evidence, exact formal CPP, blank H, and score/route.
- UID0001GS remains a non-emitting split index, historicalizes its earlier target raw/no-function state, and records UID00042L as the catalog0369-modeled retained child; supervisor command19894 applied and verified the exact manual-coverage replacement preserved below.
- UID0000CL remains `88/90` and records catalog0369's ordinal956 enum, applied target/helper identities, frames/comments, protected ordinal955 UDT/handler state, clone/lowering evidence, and stale TextEditPane rejection while retaining its Group route and blank full-class H.
- UID0001GR retains exact geometry/formal CPP and records catalog0369's applied GetPartRect name/type/comment/typed arguments, helper body hash, and thirteen incoming code xrefs.
- UID000453 identifies its `part=2` and none sequences as compiler specializations of UID00042L and records catalog0369's protected no-change handler/vtable readback while preserving sole ownership of its secondary-facet/event ABI.
- Dated supervisor command19802 first emitted the target once at `92/94`; command19812 later preserved that target body but predates UID0003CQ's generated header-route closure, and command19887 is the dated checkpoint that first recorded the completed shared route. Dated supervisor-owned command19890 emitted the target once at `92/94`, included `../ui/core/ScrollBar.h`, consumed the shared table, and had no `Group.h`. The old command19759 `87/89` marker and TextEditPane grouping are historical and must not become the canonical route.

## Ranked Ownership Analysis

1. [UID:0000CL] `ScrollNewGroupPane` - very strong. Exact RTTI class name, constructor-installed three-facet vtables, `this+0x103` class-tail field, local `GetPartRect`, active inlining, and neighboring class method order all agree.
2. [UID:0000JS] `Group` file - strong. `NewGroupPane` constructs/uses this scrollbar, the class docs route there, and generated output already follows that source root.
3. Shared ScrollPane/ScrollBar source file - rejected for ownership. It is valuable homolog evidence but does not own the class-specific body or its Group/NewGroup relations.
4. TextEditPane - rejected stale generated ownership. It does not explain the RTTI class, constructor, fields, vtables, owner callbacks, or class-local method order.
5. Compiler/runtime owner or no owner - rejected. The body is a normal stateful member method, not ABI glue or a runtime helper.

No owner/emitter route change is warranted.

## Source Placement

- Canonical source route remains [UID:00042L] -> [UID:0000CL] `ScrollNewGroupPane` -> [UID:0000JS] `Group` -> `NexusTK/social/Group.cpp` in current reconstruction topology.
- In likely original source shape, the definition belongs with the private `ScrollNewGroupPane` method family near `GetPartRect` and interaction helpers. The executable address order supports that placement.
- Do not create a standalone `ScrollNewGroupPaneSetHighlightedPartRaw.cpp`, a shared generic ScrollPane implementation, or a TextEditPane method.
- Target formal H remains blank. The eventual complete class declaration belongs in UID0000CL's H channel, not as a fragment in a child by-memory page. This report does not claim the broader whole-class H audit is complete.

## Range / Split / Padding / Reclassification Analysis

- Keep the target exact range and file. No split, merge, covered-by conversion, or range extension is needed.
- The predecessor is padding and remains outside. The successor begins at the exact target end.
- `0x00561a3e-0x00561a40` must never be reclassified as padding; those bytes are the immediate operand of the `retn 4` instruction headed at `0x00561a3d`.
- Reclassify only semantic status: “raw/manual method with unexplained no-xref caveat” becomes “retained out-of-line source method with active specialized inline lowerings and no static entry route.”
- UID0001GS remains a non-emitting split index; the exact child retains formal emission.

## Negative Evidence Summary

- No incoming direct code/data xref to the target start.
- No VA, RVA, or raw-file-offset pointer encoding.
- No proposed function/type name collision.
- No vtable entry at the target start.
- No original symbol for `SetHighlightedPart`, `ScrollNewGroupPart`, `m_highlightPart`, or the enum constants.
- No evidence that the target belongs to TextEditPane, a compiler helper, or a shared generic source body.
- No evidence for a wider/narrower target range, a fall-through from the predecessor, an external interior entry, or a merge with UID00042M.
- These negatives cap lexical confidence but do not block source reconstruction because exact homolog and inline-lowering evidence supplies the missing source explanation.

## IDA Rename / Type / Comment Recommendations

All mutations/save below were supervisor-owned and are durably recorded by catalog entry0369; B004 made no IDA mutation or save. Each row preserves its historical prestate and records the exact applied/protected readback. Comment channels are literal: address regular (AR), address repeatable (AP), function regular (FR), and function repeatable (FP). `absent` means that exact channel is empty.

| Action ID | Exact entity/range | Literal current prestate | Canonical classification | Exact action and evidence | Protected constraints | Literal expected readback |
| --- | --- | --- | --- | --- | --- | --- |
| IDA-42L-001 | type catalog enum `ScrollNewGroupPart` | Historical catalog0368 prestate: type/name/declaration/size/ordinal/members absent; type comment channels not applicable. Catalog0369 current state: one ordinal956 four-byte enum with `kScrollNewGroupPartNone=-1`, `Leading=0`, `PageBeforeThumb=1`, `Thumb=2`, `PageAfterThumb=3`, `Trailing=4`; no collision. | already present | No further mutation. Preserve catalog0369's exact enum created from HitTest/GetPartRect/constructor and homolog ABI evidence. | Do not alter sibling enums or `ScrollPanePart`; do not reduce width or duplicate ordinal956. | Exactly one unchanged ordinal956 four-byte enum with all six literal members/values. |
| IDA-42L-002 | type catalog UDT `ScrollNewGroupPane` | Historical 412D prestate absent; catalog0366 onward current state: ordinal955, size `0x110`, 13 members: `Pane _paneBase +0x00`; `unsigned __int16 m_scrollSkinIndex +0xf8`; `unsigned __int8 m_scrollStyleByte +0xfa`; `bool m_thumbDragActive +0xfb`; `unsigned __int8 m_orientation +0xfc`; `unsigned __int8 _alignmentFD +0xfd`; `__int16 m_scrollPosition +0xfe`; `__int16 m_scrollRange +0x100`; `bool m_scrollEnabled +0x102`; `signed __int8 m_highlightPart +0x103`; `signed __int8 m_activePart +0x104`; `unsigned __int8 _alignment105[3] +0x105`; `Point m_thumbDragOffset +0x108`; type comment channels not applicable. | already present | Catalog0369 verified/protected the exact catalog0366 UDT; no creation or replacement occurred. | Preserve `Pane`, `Point`, `RectBounds`, all members/offsets/widths, ordinal955, size0x110, and no secondary-facet fields. | Exactly one unchanged ordinal955 UDT with all 13 members and no duplicate/collision. |
| IDA-42L-003 | function `[0x005619d0,0x00561a40)` | Historical 6470 prestate: decoded code, no function, start name/type absent, AR/AP absent, FR/FP not applicable, zero incoming xrefs. Catalog0369 current state: one function, size0x70, 46 instructions/seven blocks, unchanged body SHA `87DB2579...71FB2`, zero incoming start xrefs; AR/AP/FR absent and FP as row007. | already present | No further mutation. Preserve the exact function defined by catalog0369. | Preserve every byte, both fences, helper calls, labels, security-cookie call, separate successor, and no overlap. | One unchanged function exactly `[0x005619d0,0x00561a40)`, 112 bytes. |
| IDA-42L-004 | function `[0x005619d0,0x00561a40)` | Historical 6470 prestate had no function/name and proposed-name lookup failed. Catalog0369 current name is exactly `ScrollNewGroupPane__SetHighlightedPart`; AR/AP/FR absent; FP is row007. | already present | No further mutation. Preserve the exact unique family-consistent name applied by catalog0369. | Do not rename homologs or create a second function. | Exact unique name remains at `0x005619d0`; no collision. |
| IDA-42L-005 | function `[0x005619d0,0x00561a40)` | Historical 6470 prestate had no function/type. Catalog0369 current declaration is `void __thiscall(ScrollNewGroupPane *this, ScrollNewGroupPart part)`; AR/AP/FR absent; FP is row007; frame is row006. | already present | No further mutation. Preserve exact class receiver, one four-byte enum argument, void return, and `retn 4`. | Preserve bytes/calls/xrefs/frame bounds, enum width4, class size0x110, and one explicit argument. | Exact current prototype and physical frame from row006 remain unchanged. |
| IDA-42L-006 | target frame at `[0x005619d0,0x00561a40)` | Historical prestate had no frame; the report predicted `var_14` plus `var_4`. Catalog0369 physical current frame is exactly `rect +0x8/0x10 struct RectBounds`, `__saved_registers +0x1c/0x4`, `__return_address +0x20/0x4`, `part +0x24/0x4 ScrollNewGroupPart`; no `var_4 +0x18/0x4` exists. | already present | No further mutation. Preserve the complete RectBounds local produced after safe deletion of fragmented automatic members. | Preserve exact offsets/sizes and do not invent the predicted absent `var_4` or resize the stack. | Exact four-entry physical frame remains; `rect` is one complete 16-byte `struct RectBounds`. |
| IDA-42L-007 | function `[0x005619d0,0x00561a40)` | Historical prestate AR/AP absent and FR/FP not applicable. Catalog0369 current channels: AR absent; AP absent; FR absent; FP exactly `Retained ScrollNewGroupPane::SetHighlightedPart method. If the highlighted part changes, invalidates the old and new non-none part rectangles through GetPartRect and inherited InvalidateRect, then stores m_highlightPart at +0x103; active mouse handling contains constant-part inline lowerings while this out-of-line copy has no static entry route.` | already present | No further mutation. Preserve the exact applied FP literal. | Keep AR/AP/FR absent; preserve function/type/frame/bytes/xrefs. | Exact FP remains present and all companion channels remain absent. |
| IDA-42L-008 | function `[0x00561740,0x005619c7)` | Historical 6470 name `sub_561740`; catalog0369 current name `ScrollNewGroupPane__GetPartRect`, size0x287, 243 instructions/39 blocks, helper body SHA `70D64415...2F17`, thirteen incoming code xrefs; AR/AP/FR absent; FP is row010. | already present | No further mutation. Preserve exact unique helper name applied by catalog0369. | Preserve range, bytes, thirteen xrefs, callees, frame offsets, and interior regular comments. | Exact current helper name/range/hash/xrefs remain unchanged. |
| IDA-42L-009 | function `[0x00561740,0x005619c7)` | Historical prototype `void __thiscall(int this, char, RectBounds *bounds)` with byte `arg_0`. Catalog0369 current prototype is `void __thiscall ScrollNewGroupPane__GetPartRect(ScrollNewGroupPane *this, ScrollNewGroupPart part, RectBounds *outRect)`; frame `var_20 +0x4/0x10`, `position +0x14/0x8`, `offset +0x1c/0x8`, saved +0x24/4, return +0x28/4, `part +0x2c/0x4 ScrollNewGroupPart`, `outRect +0x30/0x4 RectBounds *`; AR/AP/FR absent; FP is row010. | already present | No further mutation. Preserve exact typed ABI and physical argument normalization. | Preserve range/calls/thirteen xrefs/nonargument locals/interior comments; enum remains four-byte despite low-byte reads. | Exact current prototype/frame and thirteen incoming code xrefs remain unchanged. |
| IDA-42L-010 | function `[0x00561740,0x005619c7)` | Historical FP absent. Catalog0369 current channels: AR absent; AP absent; FR absent; FP exactly `ScrollNewGroupPane::GetPartRect resolves the leading edge, page-before-thumb, thumb, page-after-thumb, or trailing edge rectangle for one ScrollNewGroupPart; it uses orientation, range, position, enabled state, and the shared extent table.` | already present | No further mutation. Preserve the exact applied FP literal. | Preserve other blank channels, interior comments, bytes/range/thirteen xrefs/type/frame. | Exact FP remains present; AR/AP/FR remain absent. |
| IDA-42L-011 | protected function `[0x00560b00,0x00560ce1)` and vtable cell `0x00623f6c` | Catalog0369 protected current state: `sub_560B00`, size0x1e1, prototype `char __thiscall(int this, int)`; full prior frame unchanged; AR/AP/FR/FP absent; body SHA `1681036A...4F57`; exactly one data xref from `[0x00623f6c,0x00623f70)`; cell bytes `00 0b 56 00`. | no change recommended | Continue using this as protected inline-lowering evidence only; catalog0369 applied no partial handler mutation. | Preserve function bytes/range/type/name/comments/frame/interior comments, vtable bytes, and sole vtable xref. | Exact protected state remains unchanged and still shows `part=2` and none specializations. |

## First-Draft C++ Recommendation

Target formal CPP should remain exactly:

```cpp
void ScrollNewGroupPane::SetHighlightedPart(ScrollNewGroupPart part)
{
    RectBounds rect;
    const ScrollNewGroupPart oldPart =
        static_cast<ScrollNewGroupPart>(m_highlightPart);

    if (oldPart == part)
        return;

    if (oldPart != kScrollNewGroupPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kScrollNewGroupPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_highlightPart = static_cast<signed char>(part);
}
```

Target formal H remains exactly blank. Do not put a declaration fragment in this child H channel. The source declaration is semantically `void SetHighlightedPart(ScrollNewGroupPart part);`, but the complete class declaration belongs to UID0000CL's eventual full H audit.

Why this source shape is accepted:

- It is human-written member code, not a transliteration of `al`, `bl`, `esi`, `var_14`, or vtable syntax.
- It preserves the exact early return and invalidation order.
- It represents enum semantics while retaining the byte field through explicit casts.
- It produces the same observable state and callback order as the binary.
- It is consistent with the mid-2000s class-family source shape already used by sibling reconstructed scrollbars.

## Final Recommendation

- Target identity, range, owner/emitter, reconstructable state, emitter position, formal CPP, and blank H were retained exactly.
- UID00042L is physically `92/94` with the complete current ordinary evidence in this report.
- Support class UID0000CL is physically `88/90`; UID0001GS remains `88/90`, UID0001GR `89/91`, UID000453 `89/90`, UID00042M `88/90`, and Group `90/86`.
- Supervisor catalog entry0369 applied/verified IDA-42L-001 and IDA-42L-003..010, verified/protected already-present IDA-42L-002 and no-change IDA-42L-011, and durably saved historical target checkpoint `A4A6BC82...AC02C4`. Bounded read-only verification at dated shared-save checkpoint `2CCA289F...70D7E851` found no target/dependency/protected-state drift; `D65C96CE...98F2D11`, `83C20CE9...C294A9E`, and `87D34CCD...500F2` remain earlier checkpoints. Fresh Gate 1/final Gate 2 must verify this report and all reconciled ordinary pages against then-current physical state.
- Supervisor commands19894-19896 applied and verified all five exact manual coverage insert/replacements after Gate 2A, and command19894 verified the two support no-op dispositions.
- Do not defer raw-start liveness, names, types, enum values, field width, source classification, source route, or formal source. They are resolved here.
- Remaining uncertainty is lexical only: no original debug symbol proves the exact method/enum/member spelling. That uncertainty justifies the below-95 score but not raw names or blank CPP.

## Recommended Target Doc Changes

For `by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md`, all accepted ordinary items below are physically applied and validator-backed:

- Metadata changed from `87/89` to `92/94`; all route fields and position 70 were retained.
- Replace Item Summary with: `Retained ScrollNewGroupPane highlighted-part transition with exact old/new rectangle invalidation, inline-lowering proof, and class-local enum/field ABI.`
- Preserve the exact formal CPP and blank H.
- Expand Status with retained out-of-line source classification and resolved no-static-route explanation.
- Add exact 112-byte hash, 46-instruction map, predecessor/successor fences, raw offset, `retn 4` ABI, no-pointer-route results, internal-only branch entries, and eight-clone inventory.
- Add specialized inline-copy evidence from UID000453 and distinguish it from static caller evidence.
- Add exact enum/member width analysis, RTTI-backed class identity, helper/callback types, no-return contract, and name ranking.
- Reconcile historical IDA prestate to catalog0369's exact applied enum/function/name/type/comment/frame state, generated/manual coverage currentness, rejected TextEditPane/compiler-glue/covered-by alternatives, and complete history preserving B008 assumptions.

## Recommended Support Doc Changes

- [UID:0001GS] parent split index remains `88/90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, with blank emitter/formals; it now records UID00042L's retained-source/inline-lowering classification and correct child emission.
- [UID:0000CL] class is `88/90` with 0000JS ownership/emission and class CPP/H topology retained; exact clone/lowering, size-0x110 UDT, enum/field-width, source-route, and stale-ownership evidence is applied while preserving the broader full-class H audit cap.
- [UID:0000JS] Group remains `90/86` and now records the retained `SetHighlightedPart` method and Group source route without a separate file or duplicate body.
- [UID:0001GR] PartRect remains `89/91` and records callsites `0x005619fc`/`0x00561a18`, all thirteen incoming code xrefs, and catalog0369's applied GetPartRect name/type/comment/argument readback.
- [UID:000453] HandleMouseEvent remains `89/90`, records constant-thumb `[0x00560bfd,0x00560c3a)` and constant-none `[0x00560b5f,0x00560b87)` lowerings, and records catalog0369's protected no-change handler/vtable readback while preserving its separately owned secondary-facet/event ABI.
- [UID:00042M] successor was inspected and is byte-identical at `88/90`; its exact boundary, route, CPP, and blank H remain unchanged.
- Preserve valid B008 history and label its unresolved no-xref wording as historical before this reanalysis, not delete it.

## Score And Metadata Recommendation

| UID | Historical pre-callback | Applied/current | Route disposition | Reason |
| --- | --- | --- | --- | --- |
| 00042L | 87/89 | 92/94 | retain 0000CL/0000CL/70, reconstructable | Exact liveness/classification, clone/inline proof, types, IDA handoff, and formal source now resolved. |
| 0000CL | 85/86 | 88/90 | retain owner/emitter 0000JS | Target adds exact RTTI/type/layout/family evidence; broader class H remains a cap. |
| 0001GS | 88/90 | 88/90 retained | no owner/emitter, non-reconstructable | Split index remains correct; one child is improved, not all siblings re-audited. |
| 0001GR | 89/91 | 89/91 retained | 0000CL/0000CL/60 | Current geometry already strong; target adds callers/IDA plan but not a full geometry re-audit. |
| 000453 | 89/90 | 89/90 retained | 0000CL/0000CL/46 | Inline relation is new support detail, not a complete event-ABI re-audit. |
| 00042M | 88/90 | 88/90 retained | 0000CL/0000CL/71 | Boundary-only support inspection. |
| 0000JS | 90/86 | 90/86 retained | file root | Target confirms one class-local method but does not re-audit the full file. |

The target does not reach 95/95 because original lexical spellings and the complete class H/source-declaration audit remain unproven. No behavioral, ownership, range, liveness, type-width, enum-value, or formal-body blocker remains.

## Open Questions With Attempted Resolution

1. Is the raw body live source despite zero xrefs? Resolved: yes, as retained out-of-line source. Eight family clones and two specialized sequences in the active handler explain compiler lowering; pointer and branch routes were exhaustively negative.
2. Is it compiler-generated or dead historical code? Resolved: no. It is a normal class-state transition with family method clones, exact helper calls, class-tail members, and active inlined semantics.
3. What is the method name? Resolved to `SetHighlightedPart`, the repeated family name matching this field role. Exact original spelling is unavailable but no stronger alternative exists.
4. What is the part type? Resolved to 4-byte enum `ScrollNewGroupPart` with values `-1,0..4`; the storage field is separately signed 8-bit.
5. What is `this+0x103`? Resolved to `m_highlightPart`, not active/pressed or hover-only state.
6. What are the helper and callback? Resolved to `GetPartRect` and inherited `InvalidateRect` with exact signatures/slot.
7. Should C++ be blank because there is no raw callsite? Resolved: no. The complete retained body emits once; inlining does not erase the out-of-line source definition.
8. Should the target H contain a declaration? Resolved: no, because the child formal H is not the complete class declaration channel. Exact target H remains blank; UID0000CL owns the eventual complete declaration.
9. Should IDA remain unchanged because the start was raw? Resolved: no. Catalog0369 safely applied the exact enum/function/name/type/comment repair, normalized the target frame to one complete RectBounds without inventing the predicted absent `var_4`, typed the helper arguments, preserved all thirteen helper xrefs, and protected catalog0366's class UDT plus UID000453.
10. Does the target need a split/merge or new owner? Resolved: no.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The manual files were re-inspected read-only after supervisor command19890 and B008 M01-M05; B004 did not edit them. The pre-apply identities and anchors were: `by-memory/-coverage-report.md` SHA256 `1E8ADE03DAC904CEF6A396BE9E389DD01737CCC74EE2A1EFB324B695E0EFCF42`, `2096375` bytes/4746 lines, with UID0001GR/UID0001GS at lines 3227/3228, UID0001GT at line 3229, UID00042L absent, and UID000453/UID00042M absent; `by-class/-coverage-report.md` SHA256 `B1166F5ED1A35CF9793E110459F3E61C076DD6590EAA6CB5DA50461F1EA62CE2`, `271791` bytes/625 lines, with UID0000CL at line477; and `by-file/-coverage-report.md` SHA256 `33826E899598F6E4D84D92A69551CF4BE6D222A9C0CBA5DB791E3836252B2E04`, `162528` bytes/317 lines, with UID0000JS at line109. Supervisor commands19894-19896 then applied and verified all five exact no-loss payloads below and confirmed the two support no-ops. Dated post-apply identities are: by-memory SHA256 `BECB2B9939F549434F86D7EA21AA86A7F7E8E25765371CFF083C6A91D1E6F44E`, `2097338` bytes/4747 lines; by-class SHA256 `EDC00B8A9E9EF17F045A09EBB9223AA941625B004050D671FF51609747A31E34`, `271998` bytes/625 lines; and by-file SHA256 `226B990E2D50956D9BE1A475C44333B7B2A03CD6C5CB4342D23AEE102815B35B`, `162777` bytes/317 lines. Command19887 manual identities `35B4FAE3...44FC3`, `E401089D...E3163`, and `5E04B7C1...C91DC`, earlier by-memory checkpoint `4376E670...E39EE`, and interim audit snapshot `FD7EF245...5FAA6` are historical. The literal blocks remain below as applied payload history; current truth after those timestamps is authoritative from the physical coverage files.

1. `by-memory/-coverage-report.md`: insert the following immediately after current UID0001GS and before UID0001GT:

```markdown
        - [UID:00042L][0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw](by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md) 0x005619d0-0x00561a40 | retained source method | ScrollNewGroupPaneSetHighlightedPartRaw : reconstructable : 92% : very-strong : Exact 0x70-byte class-owned SetHighlightedPart body with old/new non-none rectangle invalidation, signed-byte highlight storage, four-byte part enum ABI, eight-body homolog family, constant-part inline lowerings in HandleMouseEvent, exhaustive no-static-route proof, formal C++, and atomic IDA handoff.
```

2. Replace the current UID0001GS row exactly with:

```markdown
    - [UID:0001GS][0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers](by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md) 0x005619d0-0x00561db0 | split index | ScrollNewGroupPaneRawAndInteractionHelpers : not reconstructable : 88% : very-strong : Non-emitting split index over exact class-owned interaction children and ScrollNewGroupPane interaction callers; preserves mixed raw/modeled boundaries, highlighted/active/drag/timer state bytes, rectangle invalidation calls, scroll-position callback, retained-source/no-route evidence, and exact padding before ScrollCollectionPane without duplicating child C++.
```

3. Replace the current UID0001GR row exactly with:

```markdown
    - [UID:0001GR][0x00561740-0x005619c7.ScrollNewGroupPanePartRect](by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md) 0x00561740-0x005619c7 | helper method | ScrollNewGroupPanePartRect : reconstructable : 89% : very-strong : Exact 0x287-byte five-part rectangle resolver with thirteen incoming callsites spanning mouse, paint, and raw-interaction paths including both SetHighlightedPart callsites, rectangle-helper callees, constants, orientation/range/position/enabled geometry, shared extent table, exact padding before raw helpers, class owner/emitter, formal C++, and source-quality IDA name/type/comment handoff.
```

4. Replace the current UID0000CL row in `by-class/-coverage-report.md` with this no-loss merged row, preserving every current UID0003CQ/UID000450/UID000451 and class-family fact while adding UID00042L:

```markdown
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md) : reconstructable : 88% : very-strong : Group-owned custom scrollbar with exact constructor/setter/input/timer/paint/geometry/interaction children, three vtable views, applied exact 0x110/13-member receiver UDT, resolved raw interaction setter family and scroll-tail fields, UID000450 signed range contract/name/prototype/comment, UID000451 byte-identical typed position-setter contract and inherited m_visibleBounds correction, retained UID00042L SetHighlightedPart clone/inline-lowering proof and catalog0369 enum/function/helper/frame/comment handoff, NewGroupPane caller route, shared kScrollPanePartExtentBySkin table/field alias and ScrollBar.h dependency, and source-ready child C++; full class-header final audit remains separate.
```

5. Replace the current UID0000JS row in `by-file/-coverage-report.md` with this no-loss merged row, preserving every current range/position-clone, vtable/destructor, UID0003CQ shared-scrollbar, and module fact while adding UID00042L:

```markdown
- [UID:0000JS][Group](by-file/Group.md) : reconstructable : 90% : very-strong : Group/social pane source root covering GroupListPane raw construction and exact false input overrides, GroupPane/GroupPane2/NewGroupPane and ScrollNewGroupPane exact children, packet/layout/render/input behavior, exact range/position setter clone evidence, vtable/destructor support, GroupMemberMarkers relationships, retained source-ready UID00042L SetHighlightedPart with clone/inline-lowering and catalog0369 proof, and UID0003CQ's shared ScrollBar.h dependency and external kScrollPanePartExtentBySkin consumption under NexusTK/social/Group.cpp.
```

6. Supervisor command19894 post-apply readback verified that UID000453 and UID00042M still require no direct manual by-memory rows. Their score/path/reconstructable states remain unchanged, so no support rows were invented. Generated tracker/coverage files remain validator-owned.

## Follow-Up Actions

1. Historical Gate 1 accepted report SHA256 `4E3AF2058F669359703CCAB210B1BE91250D094B40DE0C36F77543B0991C28B5` for ordinary callback.
2. B004 completed the accepted same-report ordinary callback for target and listed support docs, then serially ran the updated goal's exact scoped validator command for each changed page; commands19807-19812 all returned deferred generated refresh.
3. B004 first reconciled this report against EEF0, catalog0367 `222DEBAD...D043`, and catalog0368 `64704F...E54642`, now dated historical/prestate checkpoints. Supervisor catalog0369 then applied, verified, and durably saved the accepted IDA actions at historical target checkpoint `A4A6BC82...AC02C4`; this callback reconciled the same report and all six actually affected ordinary docs to that exact readback. Later shared-save checkpoints `87D34CCD...500F2`, `83C20CE9...C294A9E`, `D65C96CE...98F2D11`, and `2CCA289F...70D7E851` were checked read-only at their respective times and all preserved the same target/dependency/protected state; no checkpoint is asserted as permanent current truth.
4. Commands19807-19812 serially validated the six reconciled ordinary docs. Dated supervisor-owned global foreground refresh command19890 confirmed one accepted UID00042L body at `92/94`, the ScrollBar header/shared-table route, and no `Group.h`; latest observed bounded tracker-only command19891 recorded the zero-report reconstructable row at its timestamp. Physical tracker metadata governs later lifecycle/count truth. Command19802/19805/19812/19886/19887 and command19890's tracker identity remain dated tracker checkpoints.
5. Historical supervisor Gate 2A completed claim/hash/validator verification. Commands19894-19896 then applied and verified all five manual coverage payloads, and command19894 confirmed the two support no-ops, producing the dated post-apply identities recorded above.
6. Fresh Gate 1/final Gate 2 rechecks this reconciled artifact, catalog0369, and then-current physical hashes without converting dated checkpoints into permanent current-state claims.
7. Final generated/tracker semantic verification remains distinct from the completed manual-coverage work. Report execution/archive and agent-assignment truth are authoritative only from the artifact's actual path, validator-owned status/history metadata, and current supervisor assignment state; historical commands19897 and19898 are recorded only in the validator-owned report-history footer and do not assert current lifecycle status.

## Confidence

- Very strong: exact range, bytes, fences, instruction semantics, ABI, helper calls, field offset/width, sentinel, enum values, owner, source route, clone family, inline lowering, and formal CPP behavior.
- Strong: selected original-style member/enum/field/helper lexemes, retained out-of-line source classification, class UDT member names, and Group.cpp placement.
- Medium-high only: exact original spelling and whether the historical developer declared this helper private/protected. Those lexical/access uncertainties do not alter emitted behavior, routing, or selected source names.
- Overall recommendation confidence: `94`.

## Validator Results

- Historical report-only research issued no validator or lifecycle command. Authoritative retained Codex session output and original tool-call records recover the exact accepted-callback set as commands19764, 19766, 19771, 19772, 19774, 19775, and 19776 below; the intervening command IDs belonged to concurrent project work and are not attributed to B004. Every listed command ran from `source-3/project-documentation`.

| command_id | Exact command | command_timestamp | exit / ok | Exact warnings, errors, and material output | Generated-refresh state |
| --- | --- | --- | --- | --- | --- |
| `000000019764` | `python .\tools\validator.py --mode file --file 'by-memory/0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md' --apply --queue-timeout 240 --no-generated-refresh` | `2026-07-29T16:23:12-04:00` | `0 / 1` | No warning or error. `completion_update:1` to 92, `confidence_update:1` to 94, `reference_index_add:1` for UID000453, `stats_incremental_noop:1`. | `skipped`; command/timestamp echoed exactly; `disabled by --no-generated-refresh`. |
| `000000019766` | `python .\tools\validator.py --mode file --file 'by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md' --apply --queue-timeout 240 --no-generated-refresh` | `2026-07-29T16:23:53-04:00` | `0 / 1` | No warning or error. `reference_index_add:1` for UID000453; `stats_incremental_noop:1`. | `skipped`; command/timestamp echoed exactly; `disabled by --no-generated-refresh`. |
| `000000019771` | `python .\tools\validator.py --mode file --file 'by-class/ScrollNewGroupPane.md' --apply --queue-timeout 240 --no-generated-refresh` | `2026-07-29T16:26:15-04:00` | `0 / 1` | No validator error; output exposed `reference_index_remove:1` for UID0002OS after score-paragraph tightening plus class score updates to 88/90. B004 restored the pre-existing UID0002OS vtable-data reference before lease release and reran the same file as command19772. | `skipped`; command/timestamp echoed exactly; `disabled by --no-generated-refresh`. |
| `000000019772` | `python .\tools\validator.py --mode file --file 'by-class/ScrollNewGroupPane.md' --apply --queue-timeout 240 --no-generated-refresh` | `2026-07-29T16:26:30-04:00` | `0 / 1` | No warning or error. `reference_index_add:1` restored UID0002OS; `stats_incremental_noop:1`. | `skipped`; command/timestamp echoed exactly; `disabled by --no-generated-refresh`. |
| `000000019774` | `python .\tools\validator.py --mode file --file 'by-file/Group.md' --apply --queue-timeout 240 --no-generated-refresh` | `2026-07-29T16:27:40-04:00` | `0 / 1` | `missing_ref_uid:1`: exact pre-existing warning `0003XA by-file/Group.md UID reference is not present in validator.ini`; UID00042L `reference_index_add:1` succeeded; no target-specific error. | `skipped`; command/timestamp echoed exactly; `disabled by --no-generated-refresh`. |
| `000000019775` | `python .\tools\validator.py --mode file --file 'by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md' --apply --queue-timeout 240 --no-generated-refresh` | `2026-07-29T16:28:20-04:00` | `0 / 1` | No warning or error. UID00042L `reference_index_add:1`; `stats_incremental_noop:1`. | `skipped`; command/timestamp echoed exactly; `disabled by --no-generated-refresh`. |
| `000000019776` | `python .\tools\validator.py --mode file --file 'by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md' --apply --queue-timeout 240 --no-generated-refresh` | `2026-07-29T16:28:51-04:00` | `0 / 1` | No warning or error. UID00042L `reference_index_add:1`; `stats_incremental_noop:1`. | `skipped`; command/timestamp echoed exactly; `disabled by --no-generated-refresh`. |

- Post-IDA reconciliation used the exact command set below. Each scoped command returned exit `0`, `ok:1`, and `generated_refresh: deferred`; each validator-owned generated-refresh result later completed with exit `0` and empty `stderr`.

| command_id | Exact command | command_timestamp | exit / ok | Exact warnings/errors | Deferred generated-refresh result |
| --- | --- | --- | --- | --- | --- |
| `000000019807` | `python .\tools\validator.py --mode file --file 'by-memory\0x005619d0-0x00561a40.ScrollNewGroupPaneSetHighlightedPartRaw.md' --apply --queue-timeout 240` | `2026-07-30T07:00:35-04:00` | `0 / 1` | No scoped warning or error; `stats_incremental_noop:1`. | `zz-generated-refresh-000000019807-f59fd15b5e68.result.json`: exit0/stderr empty; diagnostics fallback11, marker-missing72, emitter-no-code100, header-noop1; Group.cpp/tracker/memory coverage refreshed. |
| `000000019808` | `python .\tools\validator.py --mode file --file 'by-memory\0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md' --apply --queue-timeout 240` | `2026-07-30T07:00:42-04:00` | `0 / 1` | No scoped warning or error; `stats_incremental_noop:1`. | `zz-generated-refresh-000000019808-8b4cfc73eeb7.result.json`: exit0/stderr empty; diagnostics fallback11, marker-missing72, emitter-no-code100, header-noop1; four generated metadata targets refreshed. |
| `000000019809` | `python .\tools\validator.py --mode file --file 'by-memory\0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md' --apply --queue-timeout 240` | `2026-07-30T07:00:56-04:00` | `0 / 1` | No scoped warning or error; `stats_incremental_noop:1`. | `zz-generated-refresh-000000019809-c950373a1951.result.json`: exit0/stderr empty; diagnostics fallback11, marker-missing72, emitter-no-code100; three generated metadata targets refreshed. |
| `000000019810` | `python .\tools\validator.py --mode file --file "by-memory\0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md" --apply --queue-timeout 240` | `2026-07-30T07:02:03-04:00` | `0 / 1` | No scoped warning or error; `stats_incremental_noop:1`. | `zz-generated-refresh-000000019810-9c240fc40450.result.json`: exit0/stderr empty; diagnostics fallback11, marker-missing72, emitter-no-code100, header-noop1; four generated metadata targets refreshed. |
| `000000019811` | `python .\tools\validator.py --mode file --file "by-class\ScrollNewGroupPane.md" --apply --queue-timeout 240` | `2026-07-30T07:02:11-04:00` | `0 / 1` | No scoped warning or error; `stats_incremental_noop:1`. | `zz-generated-refresh-000000019811-bcece53d16fe.result.json`: exit0/stderr empty; diagnostics fallback11, marker-missing72, emitter-no-code100, header-noop1; three generated metadata targets refreshed. |
| `000000019812` | `python .\tools\validator.py --mode file --file "by-file\Group.md" --apply --queue-timeout 240` | `2026-07-30T07:02:21-04:00` | `0 / 1` | `missing_ref_uid:1`: exact pre-existing warning `0003XA by-file/Group.md UID reference is not present in validator.ini`; no UID00042L error. | `zz-generated-refresh-000000019812-fc4d32ea0a67.result.json`: exit0/stderr empty; diagnostics fallback11, marker-missing72, emitter-no-code100, header-noop1; Group.cpp/tracker/file coverage refreshed. |

- Supervisor-owned post-apply manual-coverage validation completed as follows. These are supervisor-supplied command/result facts; exact command timestamps remain authoritative from validator-owned command history rather than being invented in this report.

| command_id | Validated manual file | exit / ok | Exact material result | Dated post-apply identity |
| --- | --- | --- | --- | --- |
| `000000019894` | `by-memory/-coverage-report.md` | `0 / 1` | Applied and verified UID00042L insertion plus UID0001GS/UID0001GR replacements; verified UID000453/UID00042M no-ops. Two unrelated pre-existing missing-UID warnings remained; no UID00042L-family coverage error. | `BECB2B9939F549434F86D7EA21AA86A7F7E8E25765371CFF083C6A91D1E6F44E`, 2097338 bytes/4747 lines. |
| `000000019895` | `by-class/-coverage-report.md` | `0 / 1` | Applied and verified the exact no-loss UID0000CL merged replacement; no target-specific failure. | `EDC00B8A9E9EF17F045A09EBB9223AA941625B004050D671FF51609747A31E34`, 271998 bytes/625 lines. |
| `000000019896` | `by-file/-coverage-report.md` | `0 / 1` | Applied and verified the exact no-loss UID0000JS merged replacement; no target-specific failure. | `226B990E2D50956D9BE1A475C44333B7B2A03CD6C5CB4342D23AEE102815B35B`, 162777 bytes/317 lines. |

- Current execution/archive truth is authoritative only from the report's actual path and validator-owned status/history metadata; this report does not assert a lifecycle result.
- Generated/tracker observations are read-only checkpoints, not validation claims.
- Catalog0369 saved historical target checkpoint SHA256 `A4A6BC82D18D9BA7E1B0FDFCD87CED2B9FD4551E9AFEF3CE0175237B6DAC02C4`, `143191991` bytes, at `2026-07-30T06:48:02.4013060-04:00`; catalog0368/6470 is its byte-identical prestate backup and 222D, EEF0, and 412D remain dated history. Later shared-save checkpoints were SHA256 `87D34CCD103CC97F107DBABF1CA089FCE223F1650D5376A0DCB48C0E46F500F2`, `143192020` bytes, saved `2026-07-30T07:11:07.1602926-04:00`; SHA256 `83C20CE9E13A19CA3C5501998110D490FA3D2D2EA5FE774AE1F880403C294A9E`, `143193954` bytes, saved `2026-07-30T07:36:29.3601106-04:00`; SHA256 `D65C96CEE79AB084596B633491F2A6AF57AC18B1CB966F86D6DD9088988F2D11`, `143193979` bytes, saved `2026-07-30T09:10:51.2682267-04:00`; and supervisor-supplied SHA256 `2CCA289FBF2BA0D2CEEF5F870AF560AD3BA6025109FB47A4D66E154F70D7E851`, `143192020` bytes, saved `2026-07-30T09:23:53.4855352-04:00`. Bounded target-specific readback at `2CCA...` found no semantic drift from catalog0369. These hashes are dated evidence; final currentness is determined from physical IDB/session state at the supervisor gate.
- Commands19752/19759/19802/19812/19887 Group.cpp and commands19753/19761/19779/19805/19812/19886/19887/19890 tracker are dated historical checkpoints. Dated supervisor-owned global foreground command19890 produced Group.cpp SHA256 `44D14FCE613155FF6478621D345189E43499A0D58E1E1A905AD95C53E80BBDAC`, 27458 bytes/798 lines, with `../ui/core/ScrollBar.h`, shared-table consumption, one accepted UID00042L body at `92/94`, and no Group.h. Latest observed bounded deferred command19891 tracker checkpoint is `C7EB6279021B1F0F3C202F923358787C08CFA1C89F30F1A39CC53942601A5CC5`, 1678440 bytes/6633 lines, and recorded not-covered `92/94`, combined `93.0`, reconstructable true, direct/additional/total `0/0/0`; physical generated/tracker metadata controls any later change, and the tracker-only command19891 checkpoint did not alter the dated command19890 generated CPP/H content.

## Changed Files

- Agent-owned report artifact updated in place: `tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md`.
- Physical ordinary destination identities after the B004 post-IDA reconciliation, with later shared-document provenance made explicit:
  - UID00042L `499BAB9A78F4AB49AA22297197F645B440F140772AFA6ADF2D2AF387F4FA0A24`, 13165 bytes, 108 lines.
  - UID0001GS `CE05F09BB9846ABFC7F95AEE7068B7A2F3F4C5059C9E0A9756155FB1EBF2746C`, 16984 bytes, 132 lines.
  - UID0001GR `316EE3649076D543D505C1C7EAF8723DC67CD07A528CF6D20C2D3D7B19F2AF13`, 26497 bytes, 369 lines.
  - UID000453 `E461FD0F9B88A1C66774D43D08682CDB0FD25EAF6B3C4E8EFA509CD3BFEBDD7F`, 12946 bytes, 161 lines.
  - UID0000CL current physical identity is `7A3C36C8EF4CA79A071E7E4F6F51D8AE1AF2FF10469C7626CB88C5BA59727161`, 48078 bytes, 234 lines. Historical post-B004 reconciliation identity `481CF657AF1100191831C27DCD0A1B01380F86DADB152726453C5C51E0CE9129`, 46553 bytes/220 lines, remains a dated command19811 checkpoint. B002 UID0003CQ later added the shared scrollbar table/field alias and ScrollBar declaration dependency without removing or contradicting any UID00042L class claim.
  - UID0000JS current physical identity is `E2816C4DFFFFB57B2C662A577F7B6AFE7ABA774A2C93510A474D4CE8CCE5464B`, 41827 bytes, 215 lines. Historical post-B004 reconciliation identity `28E0731EE24792B85E2809B3F8140A2E9FDB0B56365E009FD77398C5BE422D1B`, 40139 bytes/205 lines, remains a dated command19812 checkpoint. B002 UID0003CQ later recorded the shared ScrollBar header route without removing or contradicting UID00042L placement, catalog0369, inline-lowering, or no-duplicate-body evidence.
  - UID00042M remained byte-identical and read-only at `7F135A74F451579BDAD14E4F3EF69FFB0DC930906FAE49FA0C16F237319A8032`, 7067 bytes, 102 lines.
- No manual coverage report, generated file, tracker/audit/catalog/supervisor file, goal/notes file, or IDA database was edited by B004. The supervisor later applied the manual files through commands19894-19896; B004 only reconciled this report to their supplied results. The earlier seven-path lease batch had expired by cleanup; `leaser.py Agent-B004 unlease` returned `No active leases`, and immediate readback found no B004 row in `current_leases.md`. Each subsequent report-only correction/currentness pass used its own immediate single-report lease; every lease and unlease command returned `Success`, and no lease was held between passes.
- Catalog0369 IDA reconciliation changed the six listed ordinary docs and this report; UID00042M remained read-only. B004 only documented the supervisor-saved IDA state and did not mutate or save IDA. B002's later UID0003CQ ordinary callback additively changed shared UID0000CL and UID0000JS to the current identities above; exact readback confirms all B004/UID00042L claims and content remain present and uncontradicted. This repair changes only this report after read-only verification that dated shared-save checkpoint `2CCA289F...70D7E851` preserved the historical `A4A6BC82...AC02C4` target poststate; `D65C96CE...98F2D11`, `83C20CE9...C294A9E`, and `87D34CCD...500F2` are earlier checkpoints. Later shared-IDB currentness is intentionally not asserted.
- Moving-artifact checkpoints recorded by this report are supervisor-owned command19890 Group.cpp `44D14FCE613155FF6478621D345189E43499A0D58E1E1A905AD95C53E80BBDAC`, latest observed bounded command19891 tracker `C7EB6279021B1F0F3C202F923358787C08CFA1C89F30F1A39CC53942601A5CC5`, and post-apply manual coverage from command19894 by-memory `BECB2B9939F549434F86D7EA21AA86A7F7E8E25765371CFF083C6A91D1E6F44E`, command19895 by-class `EDC00B8A9E9EF17F045A09EBB9223AA941625B004050D671FF51609747A31E34`, and command19896 by-file `226B990E2D50956D9BE1A475C44333B7B2A03CD6C5CB4342D23AEE102815B35B`. Command19802/19805/19812/19886/19887, command19890's tracker identity, pre-apply manual identities `1E8ADE03...EFCF42`, `B1166F5E...62CE2`, `33826E89...2B2E04`, and earlier identities `35B4FAE3...44FC3`, `E401089D...E3163`, `5E04B7C1...C91DC`, `4376E670...E39EE`, and `FD7EF245...5FAA6` remain dated history. Physical generated/tracker/coverage metadata governs later changes. No generated, tracker, or manual coverage file was edited by B004.

## Implementation Tracking Checklist

Initial report-only research and planning:

- [x] Current target metadata, formal CPP/H, Item Summary, range, boundaries, and existing blocker language were read exactly.
- [x] Live MCP database `1da2b2ae` was healthy and every required target query completed; the bounded pre-action pass verified all eight clone bodies, target/padding/xref state, all eleven IDA rows, and protected dependencies against catalog0368/6470 without mutation/save. Catalog0369 `A4A6BC82...AC02C4` is the historical supervisor-applied target checkpoint; bounded reread at dated shared-save checkpoint `2CCA289F...70D7E851` confirmed all eleven target/dependency/protected states remained exact. Catalog0367/222D, EEF0, `D65C96CE...98F2D11`, `87D34CCD...500F2`, and `83C20CE9...C294A9E` are earlier checkpoints; this checklist does not freeze global currentness.
- [x] Raw 112-byte body, 46 instructions, body SHA, PE raw offset, predecessor padding, successor prologue, and return immediate were verified.
- [x] Start/interior xrefs, VA/RVA/raw-offset pointers, proposed-name collisions, and vtable/static routes were investigated.
- [x] All eight method-shape clones were found and classified.
- [x] Active constant-thumb and constant-none inline lowerings were verified in UID000453.
- [x] Source classification was resolved to retained out-of-line source; compiler glue/dead data/covered-by-only alternatives were rejected.
- [x] RTTI class identity, exact field width, enum ABI/values, sentinel, helper, callback, and return contract were resolved.
- [x] Owner/emitter/source placement/range/split dispositions were resolved.
- [x] Exact target formal CPP and blank-H dispositions were verified.
- [x] Score-limiting blockers were actively researched; only bounded lexical uncertainty remains.
- [x] Target/support docs were reconciled to catalog0369 and rehashed after scoped commands19807-19812. Exact command strings/timestamps/results for accepted callback commands19764/19766/19771/19772/19774/19775/19776 were recovered from authoritative retained session tool-call/output records; commands19807-19812 were recovered from those records plus their six validator-owned generated-refresh result JSONs. Shared UID0000CL/UID0000JS identities were re-read after the additive UID0003CQ callback, and every UID00042L claim remained present and uncontradicted. Dated supervisor-owned command19890 generated semantics and bounded command19891 tracker semantics were inspected read-only. Supervisor commands19894-19896 subsequently applied and verified all five exact manual coverage payloads and the two no-op dispositions; their post-apply identities are recorded above. Physical generated/tracker/coverage metadata controls later truth.
- [x] All 88 ledger claims are atomic, use allowed action/state vocabulary, and name one exact destination document path plus one literal section.
- [x] All 11 IDA rows preserve literal catalog0368/6470 historical prestate and contain catalog0369's exact durable current state, one canonical classification, exact no-further-mutation/protection disposition, constraints, and expected readback.
- [x] Exact manual supervisor-owned coverage payloads and placements were prepared; no coverage file was edited.
- [x] Third-party import is not applicable; Wave2/Wave3 staging references were ignored as stale.
- [x] Open questions were closed to deterministic directions rather than deferred.

Future callback and supervisor-owned lifecycle:

- [x] Historical supervisor Gate 1 accepted exact SHA `4E3AF2058F669359703CCAB210B1BE91250D094B40DE0C36F77543B0991C28B5` for ordinary callback; this changed callback artifact requires fresh review.
- [x] B004 callback updated UID00042L at full report detail and physically applied `92/94`, retained route, exact Item Summary, and unchanged formal CPP/blank H.
- [x] B004 callback updated UID0001GS, UID0000CL, UID0000JS, UID0001GR, and UID000453 exactly as listed; UID00042M was physically inspected and retained byte-identical. Later UID0003CQ shared-scrollbar additions advanced UID0000CL to `7A3C36C8...27161` and UID0000JS to `E2816C4D...464B` additively; no UID00042L content or claim was removed or contradicted.
- [x] B004 completed the ordinary edit/validator work with exact accepted-callback commands19764, 19766, 19771, 19772, 19774, 19775, and 19776, then exact post-IDA commands19807-19812. The earlier batch leases had expired by cleanup; `leaser.py Agent-B004 unlease` reported no active leases, and current-leases readback showed no B004 row. Each of the six subsequent report correction/currentness passes used one immediate single-report lease and released it before further work.
- [x] Historical supervisor Gate 2A independently verified every ordinary claim/hash/validator result before manual coverage application.
- [x] Historical supervisor Gate 2B catalog0369 applied IDA-42L-001 enum type.
- [x] Historical supervisor Gate 2B catalog0369 verified/protected catalog0366's already-present IDA-42L-002 class UDT with no duplicate mutation.
- [x] Historical supervisor Gate 2B catalog0369 applied IDA-42L-003 target function creation.
- [x] Historical supervisor Gate 2B catalog0369 applied IDA-42L-004 target rename.
- [x] Historical supervisor Gate 2B catalog0369 applied IDA-42L-005 target prototype.
- [x] Historical supervisor Gate 2B catalog0369 applied IDA-42L-006 target frame-local normalization without inventing `var_4`.
- [x] Historical supervisor Gate 2B catalog0369 applied IDA-42L-007 target FP comment.
- [x] Historical supervisor Gate 2B catalog0369 applied IDA-42L-008 GetPartRect rename.
- [x] Historical supervisor Gate 2B catalog0369 applied IDA-42L-009 GetPartRect prototype and physical argument normalization while preserving thirteen xrefs.
- [x] Historical supervisor Gate 2B catalog0369 applied IDA-42L-010 GetPartRect FP comment.
- [x] Historical supervisor Gate 2B catalog0369 verified IDA-42L-011 protected HandleMouseEvent state unchanged, saved, cataloged, and supplied exact durable readback.
- [x] B004 reconciled the same report and all six affected ordinary docs to exact catalog0369 saved IDA state without touching IDA.
- [x] Supervisor commands19894-19896 applied and verified the five exact manual coverage operations; command19894 confirmed the UID000453 and UID00042M support no-ops.
- [x] Dated supervisor-owned command19890 confirmed generated semantic closure: UID00042L emitted once in Group.cpp at `92/94` with the accepted body, no duplicate/raw-label source, the required ScrollBar header/shared-table route, and no Group.h. Latest observed bounded command19891 recorded the zero-report reconstructable tracker row at its timestamp; physical generated/tracker metadata controls later lifecycle/count truth, and command19802/19805/19812/19886/19887 plus command19890's tracker identity remain dated checkpoints.
- [x] Report execution/archive state is deliberately not asserted by this report; it is supervisor-owned and authoritative only from the artifact's actual path plus validator-owned status/history metadata.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000019897","destination_path":"executed-b-agent-research/B004/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md","timestamp":"2026-07-30T09:42:20-04:00","uid":"00042L"} -->
<!-- {"agent":"B004","command_id":"000000019898","destination_path":"tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B004/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md","timestamp":"2026-07-30T09:43:07-04:00","uid":"00042L"} -->
<!-- {"agent":"B004","command_id":"000000019911","destination_path":"executed-b-agent-research/B004/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00042L-ScrollNewGroupPaneSetHighlightedPartRaw-source-quality.md","timestamp":"2026-07-30T10:16:59-04:00","uid":"00042L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
