** TARGET-REPORT-UID:000106 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 000106 ChattingVarietySelectPane Hit Test Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: preserve the callback-applied [UID:000106] `92/94`, `CANONICAL_OWNER:00001Z`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00001Z` state and the destination-ready `ChattingVarietySelectPane::HitTest(int mouseY, int mouseX)` C++ now emitted exactly once.
- Final disposition: this is a private, non-static `ChattingVarietySelectPane` member in `NexusTK/social/Chatting.cpp`. It tests exactly six selector rows, returns a signed row `0..5`, and returns `-1` on a miss.
- Current lifecycle action: the accepted ordinary-document callback, post-callback Gate 1, independent supervisor Gate 2A, and supervisor Gate 2B are complete. This same-report reconciliation now awaits a fresh exact-artifact Gate 1 continuity review; the supervisor then owns report execution/archive and the manual coverage edits in that order.
- Confidence: very strong for binary behavior, bounds, caller ABI, class/source ownership, coordinate order, return type, source form, and first-draft C++; strong for inferred original private-helper spelling.
- Current lifecycle: post-Gate-2B same-report reconciliation awaiting fresh exact-artifact Gate 1. B003 changed and scoped-validated only the seven accepted ordinary destinations during the historical callback; validator-owned generated output refreshed as a consequence. Supervisor Gate 2B then applied and saved C106-31 through C106-33. B003 did not mutate IDA, edit coverage/generated/tracker/audit/goal/lifecycle state directly, or run any report lifecycle command.

## Supporting Research

- Historical accepted Gate 1 baselines were target SHA-256 `AAC4406A5D1D97E2F7ED718BA88A43422E46143D47687A36111B357B41ED6035`, sibling SHA-256 `9D9C2B06824EA91CAD079A3195B98EEF0B6244D7A028CEC9CB4CA77BC1870579`, class SHA-256 `580BC0ECD5F6AA6D204EDACDC4DD86A152ED73B0C282EBE1566CA057B1EC6A27`, and file SHA-256 `CF306B19B102987A3B6198B880F22E27E4E5559EE202BDBDFE371D09E1B48523`. They are pre-callback checkpoints, not current identities.
- Current target: `by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md`, SHA-256 `BE6B665DD1CD12FE6B01A33472981A1177903C77CDF5AF34AD710B93F7C4A600`, 13,004 bytes/121 lines.
- Current sibling: `by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md`, SHA-256 `8D6EDD2C86895392DEDC4BB96A098E087717E542B140C36B4B9FFB0045943EC9`, 6,146 bytes/81 lines.
- Current class/source/aggregate supports are respectively SHA-256 `495FCAC8E58E1F43E52040469697D56E1333657AD6119AA0BA4E58842706EBA4` (22,707 bytes/148 lines), `8EFC83D392B2C2E2359F768E67CF66DECD3A68A3FDB273138C8183D13A3A8321` (154,798 bytes/499 lines), and `CE3620A2F959AEDFE3D4B1C36422409569674A055FBE704B27EDB8493C76F785` (104,799 bytes/441 lines). The source route remains `NexusTK/social/`.
- Current direct research-tracker row is line 3113 with `92/94`, average `93.0`, reconstructable true, and zero direct/additional report coverage pending supervisor execution. The pre-callback line-1710 `86/91` row is historical.
- Healthy live IDA MCP session: database `supervisor_current_20260724_9f6e`, worker PID 17444, analysis idle, Hex-Rays available.
- Historical saved-IDB checkpoints are `E2128EF4804CEB23ED4619C27A7C1B7808D050E08571B25BB3C8E40646448931` (143,186,421 bytes, `2026-07-24T21:40:00.1407193-04:00`) and `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C` (143,186,002 bytes, `2026-07-24T22:09:37.3164487-04:00`). Both were superseded by unrelated supervisor saves and are not current Gate 2B prestates.
- Authoritative stable Gate 2B rebase checkpoint before and after the complete itemized read-only pass: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, 143,186,450 bytes, last write `2026-07-24T22:54:09.6318603-04:00`, SHA-256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`. Every UID000106 action, local, type, protected dependency, padding, successor, collision, boundary, xref, and operand-comment row was reread against this revision; no target-specific prestate or disposition drifted from the historical `9DF` pass.
- Supervisor Gate 2B audit/catalog authority: `tools/leaser/Agents/b-report-validation-audit.md` entry `B003 UID000106 Independent Gate 2B - 2026-07-25T05:12:18-04:00` and `tools/leaser/Agents/ida-recommendation-implementation-catalog.md` entry `0311`, both `APPLIED_VERIFIED`.
- Gate 2B protected prestate backup: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-pending-gate2b-20260725_050130.bak`, SHA-256 `F812F1170EAAA4FC047EE006C61475D4671B28AC2AF8C8EAF4A5EB573756DFA8`, 143,186,450 bytes.
- Gate 2B saved checkpoint: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA-256 `3B7FC953A07344D07F33CD8C244853E0CD8DBFF8AB80C4DE2839D14A9800B63C`, 143,186,450 bytes, last write `2026-07-25T05:12:18.1184370-04:00`; `idb_save` returned `ok:true`, and post-save health plus all four primary lookups succeeded in session `f6f2c166`.

## Target

- Target UID: `000106`.
- Additional target UIDs: none. Related pages are support destinations, not additional report targets.
- Declared-target inventory: [UID:000106] exact modeled code range `[0x00481ad0,0x00481b5b)` for the selector popup's private six-row hit test.
- Target path: `by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md`.
- Source queue/report baseline: historical `auto-generated/-ag-research-tracker.md` line 1710 at `86/91`, average `88.5`. Current validator-owned row is line 3113 at `92/94`, average `93.0`, reconstructable true, with report coverage still zero until supervisor execution.
- Current supervisor classification: reconstructable by-memory target whose former Empty Emitter Marker was corrected by the accepted ordinary callback; source output and supervisor Gate 2B are current, leaving only fresh report continuity review, supervisor execution/archive, and post-execution coverage closure.
- Current scores and parent state: target `92/94`; owner/emitter [UID:00001Z] `ChattingVarietySelectPane` remains `92/94`; source file [UID:0000I5] `Chatting` remains `89/93`.

## Current Target State

- Current metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:00001Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Z`, blank emitter position, exact populated CPP formal, and empty H formal.
- Current C++/emitter state: physical generated `auto-generated/NexusTK/social/Chatting.cpp` is validator command `000000017510`, refreshed `2026-07-25T04:52:56-04:00`, SHA-256 `D1D01D808ACF89F7401B925F0D4907BBCBCA2223C2766D4C50624A261DC113E5`, 66,449 bytes/1,989 lines. UID000106 occurs exactly once with one `ChattingVarietySelectPane::HitTest` definition; there are zero UID000106 Empty Emitter Markers and no duplicate target output. Historical callback checkpoint command `17449`/SHA `651379C4...2DDA` established the same invariants before later unrelated generation.
- Current support declaration: [UID:00001Z] remains the sole complete class declaration and declares private `signed char HitTest(int mouseY, int mouseX);`; the child H formal remains empty and produces no separate declaration/header output.
- Historical blocker, coordinate, and score text is now explicitly superseded in the target. Current [UID:00015S]/[UID:0001VP] resolve `RectBounds` and `PointInRect(y,x,bounds)`, UID0002FM emits exact `GetItemRect`, live callers prove Y then X, and the current score rationale supports `92/94`.
- Current manual coverage rows remain supervisor-owned and stale at 82 percent: UID0002FJ line 819, UID0002FL line 823, UID0002FM line 829, and UID000106 line 831.
- Current artifact/lifecycle status: ordinary callback, post-callback Gate 1, independent supervisor Gate 2A, and supervisor Gate 2B are complete. Fresh exact-artifact Gate 1 continuity for this reconciled report, execution/archive, and post-execution manual coverage remain pending.
- Current IDA handoff status: `APPLIED_VERIFIED` for C106-31 through C106-33 under audit entry `B003 UID000106 Independent Gate 2B` and catalog entry `0311`; saved revision is `3B7FC953A07344D07F33CD8C244853E0CD8DBFF8AB80C4DE2839D14A9800B63C`.

## Executive Recommendation

- Assign no new owner and perform no split. Keep the exact code range under [UID:00001Z] and emit it through [UID:0000I5] in `NexusTK/social/Chatting.cpp`.
- Use source-facing member signature `signed char ChattingVarietySelectPane::HitTest(int mouseY, int mouseX)`.
- Use a signed-byte loop variable `itemIndex`, exact six-row limit, `RectBounds itemRect`, the existing private `GetItemRect`, and canonical `PointInRect(mouseY, mouseX, &itemRect)`.
- Promote target to `92/94`; promote [UID:0002FM] to `92/94` because its private-member ABI, sole caller, exact bytes, source name, types, geometry, and draft body are now all cross-validated.
- Correct support documentation that calls the event payload `x,y`: the observed project order is `mouseY` at event payload `+0x00` / event `+0x08`, then `mouseX` at payload `+0x04` / event `+0x0c`.
- No unresolved dependency blocks target C++.

## Supervisor Active Recheck

- The accepted report-only artifact passed supervisor Gate 1 at SHA-256 `D48ED99440053CF31BB64C43F4D90199C4751F5285431019669AF16997660A39`; the authorized ordinary callback then applied the accepted scope only.
- Split repair is not required: predecessor [UID:0002FM] ends at `0x00481acd`, three `0xcc` bytes align the target at `0x00481ad0`, the target ends at `0x00481b5b`, and five `0xcc` bytes align unrelated [UID:0002FP] at `0x00481b60`.
- Every source-bearing dependency needed by the body was checked: class declaration, `GetItemRect`, OnMouseEvent call sites, OnPaint sibling call, `RectBounds`, `InitRectBounds`, `PointInRect`, source file, aggregate, generated output, tracker, manual coverage, and historical report.
- Current post-callback controls: post-callback Gate 1, independent Gate 2A claim/destination/validator verification, and supervisor-owned Gate 2B IDA application have passed. Supervisor must now revalidate this exact reconciled report at fresh Gate 1 before execution/archive; manual coverage follows execution.

## Inference Research Guidance Check

- IDA fact, documentation evidence, and inference are separated throughout this report.
- IDA fact proves exact bytes, bounds, control flow, return encoding, caller register/stack setup, callees, padding, and current database names/types/comments.
- Documentation evidence proves the project-wide `y,x` geometry convention, `RectBounds` source declaration, canonical helper names, class declaration, and `social/Chatting.cpp` route.
- Inference supplies only the most plausible original private-helper spelling and local variable spelling. Those names follow the already accepted sibling `ChattingVarietyPane::HitTest` and class declaration.
- Historical assumptions treated as uncertain and rechecked: file-local/static ownership, `x,y` argument order, lack of a source-ready rectangle type, lack of a source-ready sibling helper, and the claim that blank C++ must wait for a later phase.
- Wave2/Wave3 references were found in old target/file text. They were ignored as stale workflow artifacts and are not evidence for any conclusion.

## Heuristic / Inference Reanalysis And Validation

### Member Ownership And Calling Convention

- Current IDA infers `char __stdcall(int,int)` because the body does not read `ECX`. That inference is incomplete, not source truth.
- Both exclusive call sites load the selector base into `ECX` before calling: release uses `lea edi,[esi-0xa0]` then `mov ecx,edi`; hover does the same. Both push two explicit coordinates and the callee returns with `retn 8`.
- A non-static `__thiscall` member that does not use `this` has exactly this machine shape under 32-bit MSVC. File-local/static alternatives cannot explain the deliberate selector receiver load at both calls.
- Best inference: private non-static member. Rejected: free/file-local helper and static method.

### Parameter Order And Types

- At release, caller pushes `[event+0x0c]`, then `[event+0x08]`; due right-to-left argument order the first formal receives event `+0x08`, the second event `+0x0c`.
- The callee passes first formal then second formal to `PointInRect`; the live helper tests first as row/Y and second as column/X.
- Current `Point` UDT is `{ int y; int x; }`; current RectBounds docs explicitly reject x/y formal order.
- Best source-facing signature: `(int mouseY, int mouseX)`. Rejected: `(int x, int y)`, `(Point)`, and pointer-to-event signatures.

### Return Type And Miss Sentinel

- BL starts at zero, increments as an 8-bit value, returns through AL on hit, and miss executes `or al,0xff`.
- Both callers compare/use AL directly; hover compares `0xff` and stores it in `m_hotRow`.
- `signed char` is the minimal human source type that preserves `0..5` and `-1`. Plain `char` is implementation-signedness dependent; `int` obscures the byte state and return register evidence.

### Loop, Geometry, And Inlining

- Rows are exactly `0..5`; the loop stops when incremented `itemIndex >= 6`.
- Per-row rectangle is `(left=0, top=row*16+6, right=67, bottom=row*16+22)`.
- The branch testing `itemIndex == -1` is unreachable from this loop but exactly matches sibling `GetItemRect(-1)` behavior. Its presence proves the compiler inlined `GetItemRect` rather than proving a different handwritten rectangle algorithm.
- Most plausible original source calls `GetItemRect(itemIndex,&itemRect)`. Writing the expanded geometry directly would reproduce runtime but would be less faithful to the sibling source helper and retained unreachable branch.
- `PointInRect` is half-open: `left <= x < right` and `top <= y < bottom`.

### Compiler Output Versus Authored Source

- `/GS` security-cookie prologue/epilogues, register temporaries, decompiler `v3..v7`, duplicated return epilogues, and inlined `GetItemRect` instructions are compiler output.
- They must not appear as reverse-engineered scaffolding in the source body.
- The authored source is a compact loop, stack `RectBounds`, private helper call, point test, signed row return, and final `-1`.

### Source Name And Placement

- The accepted class declaration already names the method `HitTest`; the compact sibling uses the same source-facing name and pattern.
- `HitTestRow`, `FindRowAtPoint`, and `HitTestChatVarietyRow` are plausible descriptive alternatives but conflict with accepted project/class naming.
- `social/Chatting.cpp` is supported by class/file ownership, address clustering, caller location, and current generated route. No separate selector source file is evidenced.

### Score-Blocker Audit

- Blocker: raw `sub_481AD0` name. Resolved through class declaration, sibling naming, callers, and behavior.
- Blocker: stdcall versus member. Resolved through identical ECX receiver setup at both exclusive callers.
- Blocker: x/y versus y/x. Resolved through call order, helper semantics, Point UDT, and RectBounds docs.
- Blocker: final rectangle/helper declarations. Resolved by current RectBounds/RectGeometry pages and live IDA types.
- Blocker: sibling helper readiness. Resolved by exact UID0002FM body, sole caller ABI, and 77-byte body hash.
- Blocker: H placement. Resolved because UID00001Z already owns the private declaration; target H remains intentionally empty.
- Blocker: no exact original symbol spelling. This does not justify raw names or blank C++; `HitTest` is the highest-probability human name and is already accepted project-wide. It only keeps the score below final-grade 95/95.

## Evidence Standards Used

- Primary binary evidence: live IDA MCP `idb_list`, `server_health`, `analyze_function`, `disasm`, `xrefs_to`, `callees`, `inspect_items`, `get_comments`, `get_bytes`, `type_inspect`, and collision/name queries.
- Primary documentation evidence: current target, class/file/aggregate pages, OnMouseEvent, OnPaint, GetItemRect, RectBoundsLayout, RectGeometryHelpers, current generated C++, tracker, and manual coverage.
- Historical reports were treated only as hypotheses. Their previous x/y and blank-C++ conclusions were independently rejected by newer live/documented evidence.
- Negative evidence: no other target callers, no target name collision, no need for a range split, no target data/string/global dependency, no standalone H declaration, and no valid reason to preserve an Empty Emitter Marker.
- Evidence is strong enough for `92/94` because all behavior/source-placement/code-entry questions are closed. Lack of original symbols prevents a higher final-audit score.

## Evidence Checked

- IDA MCP/manual checks: target and sibling decompilation/assembly, caller windows at `0x00481234..0x0048125b` and `0x00481422..0x00481444`, OnPaint sibling window at `0x004815ed..0x00481612`, target/sibling bytes, padding bytes, exact xrefs/callees, comments, types, and current IDB hash stability.
- by-* docs: UID000106, UID0002FM, UID0002FJ, UID0002FL, UID00001Z, UID0000I5, UID000104, UID0001VP, and UID00015S.
- Generated/tracker/manual: `NexusTK/social/Chatting.cpp`, `-ag-research-tracker.md`, and relevant rows in by-memory/by-class/by-file manual coverage reports.
- Historical: B003 selector-family report and B001 compact-hit-test report; both were used only after live revalidation.
- Negative checks: proposed target/sibling/caller names have no existing function collision; predecessor/successor bounds are disjoint; compact `(0,0,62,24)` helper family is not this selector target.
- Unavailable/skipped: original PDB/source symbols do not exist in current evidence. B003 did not mutate IDA; the callback ran only the seven required serial scoped ordinary-document validators.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C106-01 | 000106 | Exact code range is `[0x00481ad0,0x00481b5b)`, 139 bytes. | Certain | Live IDA function size/bounds and bytes | UID000106 Status/IDA Evidence | Replace stale range summary with exact current fact | APPLIED_VERIFIED in target SHA `BE6B665D...A600` |
| C106-02 | 000106 | Target bytes SHA-256 are `AFD9F146918CF5A289F5FD0D7724FD34C16B02E619F638196DDDCD53D1BE6E6B`. | Certain | MCP `get_bytes` and local SHA-256 | UID000106 Binary Identity | Add exact hash/first-last bytes | APPLIED_VERIFIED in target SHA `BE6B665D...A600` |
| C106-03 | 000106 | Pre-padding `[0x00481acd,0x00481ad0)` is three `0xcc` bytes. | Certain | MCP bytes/item head | UID000106 Boundaries | Preserve outside target | APPLIED_VERIFIED; exact predecessor/padding retained |
| C106-04 | 000106 | Post-padding `[0x00481b5b,0x00481b60)` is five `0xcc` bytes. | Certain | MCP bytes/item head | UID000106 Boundaries | Preserve outside target | APPLIED_VERIFIED; exact successor/padding retained |
| C106-05 | 000106 | Exactly two callers exist at `0x0048124d` and `0x00481430`. | Certain | Live xrefs | UID000106 Caller Inventory | Add exact callers | APPLIED_VERIFIED in target and UID0002FJ |
| C106-06 | 000106 | Both callers load selector receiver into ECX. | Certain | Live disassembly | UID000106 ABI Evidence | Classify as non-static member | APPLIED_VERIFIED in target and support docs |
| C106-07 | 000106 | First explicit argument is mouse Y; second is mouse X. | Very strong | Caller pushes plus PointInRect/Point/RectBounds semantics | UID000106 Signature | Correct historical x/y wording | APPLIED_VERIFIED in target, UID0002FJ, class, file, and aggregate |
| C106-08 | 000106 | Return is signed char row `0..5` or `-1`. | Certain | BL/AL dataflow and callers | UID000106 Behavior/Signature | Use signed char | APPLIED_VERIFIED in target/formal/generated body |
| C106-09 | 000106 | Loop tests exactly rows 0 through 5. | Certain | Assembly/decompile | UID000106 Behavior | Add exact loop semantics | APPLIED_VERIFIED in target/formal/generated body |
| C106-10 | 000106 | Geometry is `(0,row*16+6,67,row*16+22)`. | Certain | Assembly and sibling | UID000106 Behavior | Add exact geometry | APPLIED_VERIFIED in target and support closure |
| C106-11 | 000106 | Containment is half-open. | Certain | PointInRect body/docs | UID000106 Behavior | Add edge semantics | APPLIED_VERIFIED in target and support closure |
| C106-12 | 000106 | Retained row `-1` branch is inlined GetItemRect evidence. | Very strong | Instruction-identical geometry/branch | UID000106 Source Shape | Historicalize direct-handwritten assumption | APPLIED_VERIFIED; rejected history preserved |
| C106-13 | 000106 | `/GS`, register temporaries, and duplicated epilogues are compiler output. | Certain | Assembly | UID000106 Compiler Boundary | Exclude from C++ | APPLIED_VERIFIED; absent from exact formal/generated body |
| C106-14 | 000106 | Best human source name is `HitTest`. | Very strong | Existing class declaration and compact sibling | UID000106 Naming | Replace raw/helper alternatives | APPLIED_VERIFIED in target/class/generated body |
| C106-15 | 000106 | Canonical owner remains UID00001Z. | Certain | Receiver/class/caller/route | UID000106 Metadata | Preserve | APPLIED_VERIFIED; owner unchanged |
| C106-16 | 000106 | Emitter remains UID00001Z through UID0000I5. | Certain | Class/file generated route | UID000106 Metadata | Preserve | APPLIED_VERIFIED; emitter/route unchanged |
| C106-17 | 000106 | Source placement is `NexusTK/social/Chatting.cpp`. | Very strong | File route/address cluster/generated source | UID000106 Source Placement | Record exact path | APPLIED_VERIFIED in target/file/generated path |
| C106-18 | 000106 | No split/merge/reclassification is required. | Certain | Exact padding and neighboring heads | UID000106 Range Analysis | Preserve exact range | APPLIED_VERIFIED; no new UID/range/owner |
| C106-19 | 000106 | Recommended score is `92/94`; metadata route otherwise unchanged. | Very strong | Closed blocker audit | UID000106 Managed Header/Score | Apply score | APPLIED_VERIFIED by validator command `17441` |
| C106-20 | 000106 | Target CPP should emit exact private member body. | Very strong | Runtime/source-shape proof | UID000106 CPP formal | Install managed block | APPLIED_VERIFIED; one generated body at lines 584-597 |
| C106-21 | 000106 | Target H remains empty because UID00001Z already declares it. | Certain | Current class formal | UID000106 H formal | Preserve empty block | APPLIED_VERIFIED; no UID000106 H/sibling output |
| C106-22 | 000106 | Empty generated marker is a documentation omission, not no-code proof. | Certain | Eligible route plus blank CPP | Generated Chatting.cpp expectation | Remove via callback/validator | APPLIED_VERIFIED; zero target Empty Emitter Markers |
| C106-23 | 0002FM | GetItemRect is a private member and should be `92/94`. | Very strong | ECX caller, exact body/hash, class declaration | UID0002FM Status/Score | Update evidence/type/score | APPLIED_VERIFIED in SHA `8D6EDD2C...EC9`, command `17442` |
| C106-24 | 0002FJ | OnMouseEvent support must record Y/X call ABI and target result use. | Certain | Two live call windows | UID0002FJ Behavior/IDA Evidence | Correct stale coordinate prose; score unchanged | APPLIED_VERIFIED in SHA `318D586F...55F0`, command `17443` |
| C106-25 | 0002FL | OnPaint support must record private GetItemRect call ABI. | Certain | Live `0x481605` call window | UID0002FL IDA Evidence | Add support detail; score unchanged | APPLIED_VERIFIED in SHA `D0D8CC6C...1AB9`, command `17444` |
| C106-26 | 00001Z | Class method row should name exact signature/body readiness. | Certain | Current class formal and live target | UID00001Z Method Notes | Enrich row; score/formal unchanged | APPLIED_VERIFIED in SHA `495FCAC8...EBA4`, command `17445` |
| C106-27 | 0000I5 | File should record exact target source closure. | Very strong | Current source route | UID0000I5 Changes/Inventory | Add evidence; score unchanged | APPLIED_VERIFIED in SHA `8EFC83D3...8321`, command `17447` |
| C106-28 | 000104 | Aggregate should index target as source-ready child without duplicate emission. | Very strong | Child/aggregate route | UID000104 Child Inventory | Add evidence; score unchanged | APPLIED_VERIFIED in SHA `CE3620A2...F785`, command `17449` |
| C106-29 | 0001VP | RectBounds layout/Y-X convention is already exact. | Certain | Current docs/live UDT | UID0001VP | Verified no change | VERIFIED_NO_CHANGE at SHA `F91373E2...C496`, 12,842 bytes/98 lines |
| C106-30 | 00015S | PointInRect source formal uses RectBounds and Y/X. | Certain | Current formal/body/live UDT | UID00015S | Verified doc no change; IDA type correction applied by supervisor | APPLIED_VERIFIED: doc SHA `52A86FFD...EDBF`, 29,460 bytes/296 lines; IDA now uses `(int y, int x, const RectBounds *bounds)` at saved SHA `3B7FC953...B63C` |
| C106-31 | 000106 | Target IDA function/local should receive source-quality name/type/comment. | Very strong | Exact prestate/collision/readback plan | Report IDA handoff | Supervisor Gate 2B apply | APPLIED_VERIFIED at catalog entry `0311`: `ChattingVarietySelectPane__HitTest`, signed-byte member Y/X type, exact regular function comment, local `signed char itemIndex`, two xrefs preserved, saved SHA `3B7FC953...B63C`; B003 made no IDA mutation |
| C106-32 | 000106 | Sibling/caller IDA functions should receive matching names/types/comments. | Very strong | Exact ABI and class formal | Report IDA handoff | Supervisor Gate 2B apply | APPLIED_VERIFIED at catalog entry `0311`: `ChattingVarietySelectPane__GetItemRect`, `ChattingVarietySelectPane__HandlePointerOrMouseEvent`, and retained `PointInRect` received exact accepted types/regular function comments; xrefs preserved |
| C106-33 | 000106 | Current internal operand comments and neighboring entities must be preserved. | Certain | Live comment/item readback | Report protected inventory | Supervisor Gate 2B verify | APPLIED_VERIFIED at catalog entry `0311`: protected UDTs, `InitRectBounds`, padding, successor, bytes, xrefs, and all 20 operand comments preserved; permitted type propagation displays target `column`/`row` labels as `x`/`y` |
| C106-34 | 000106 | Manual coverage rows for UID000106/2FM/2FJ/2FL are stale. | Certain | Current row readback | by-memory/-coverage-report.md | Supervisor post-execution replacement | PENDING_SUPERVISOR_POST_EXECUTION; exact rows re-read at 819/823/829/831 |

## Positive Evidence Summary

- Exact modeled function, complete bytes, two exclusive callers, exact callees, and exact padding make the binary scope certain.
- Both callers deliberately load the selector receiver into ECX, proving private class membership even though the optimized body does not read `this`.
- Canonical Point/RectBounds declarations and helper behavior close parameter order and rectangle type.
- Existing class declaration closes the method name, signature, and H placement.
- Existing GetItemRect body plus the target's retained `row == -1` path identifies the source-level helper call despite optimization inlining.
- Historical pre-callback generated output exposed the sole documentation defect as a blank target CPP formal. Historical callback command `17449` first proved the correction; current command `17510` independently preserves exactly one UID000106 occurrence/body, one `ChattingVarietySelectPane::HitTest` definition, zero target Empty Emitter Markers, and no duplicate target output.

## IDA MCP Facts

- Historical read-only rebase used MCP session `supervisor_current_20260724_9f6e` (worker PID 17444) and saved-IDB SHA-256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`. Supervisor Gate 2B later completed in healthy session `f6f2c166`, and `idb_save` produced SHA-256 `3B7FC953A07344D07F33CD8C244853E0CD8DBFF8AB80C4DE2839D14A9800B63C`.
- Function: `ChattingVarietySelectPane__HitTest`, `[0x481ad0,0x481b5b)`, size `0x8b`, current prototype `signed __int8 __thiscall(ChattingVarietySelectPane *this, int mouseY, int mouseX)`, eight basic blocks, cyclomatic complexity three; surviving local is `signed __int8 itemIndex`.
- Target hash: `AFD9F146918CF5A289F5FD0D7724FD34C16B02E619F638196DDDCD53D1BE6E6B`.
- Callees: `InitRectBounds` at `0x4b7c50`, `PointInRect` at `0x4b7e80`, and compiler security-cookie helper.
- Xrefs: only `0x48124d` and `0x481430`, both in `ChattingVarietySelectPane__HandlePointerOrMouseEvent`.
- Return: AL receives BL on hit; AL receives `0xff` on miss; callee returns with `retn 8`.
- Sibling: `ChattingVarietySelectPane__GetItemRect`, `[0x481a80,0x481acd)`, 77 bytes, hash `BC85785B59C28F4DD1E0676D70F9054472EE01668833D34AD33299C34A922061`, current member/out-`RectBounds` type, sole caller `0x481605`.
- Types: `RectBounds` is 16 bytes with four int fields `left/top/right/bottom`; `Point` is 8 bytes with `y/x`; `Event` is 272 bytes; `ChattingVarietySelectPane` is currently an opaque named type, not a broad UDT.
- Gate 2B readback: `ChattingVarietySelectPane__HandlePointerOrMouseEvent` is the exact `Event *` member dispatcher; `PointInRect` retains its name with `bool __cdecl PointInRect(int y, int x, const RectBounds *bounds)`. All four accepted literals are regular function comments; every entry regular/repeatable and function-repeatable channel is empty.
- Negative facts: no target strings/globals/data tables, no name collision, no additional target caller, and no overlap with adjacent functions.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004811c0-0x00481461` | UID0002FJ OnMouseEvent | exclusive caller/dispatcher | true | UID00001Z | 86/91 | callback ABI/result-use correction applied and validated |
| `0x00481490-0x004816ce` | UID0002FL OnPaint | sibling consumer of GetItemRect | true | UID00001Z | 86/91 | callback member-call detail applied and validated |
| `0x00481a80-0x00481acd` | UID0002FM GetItemRect | private rectangle helper | true | UID00001Z | 92/94 | source-ready support applied and validated |
| `0x00481acd-0x00481ad0` | no UID | alignment padding | false | none | n/a | preserve |
| `0x00481ad0-0x00481b5b` | UID000106 target | private six-row hit test | true | UID00001Z | 92/94 | exact C++ emitted once and validated |
| `0x00481b5b-0x00481b60` | no UID | alignment padding | false | none | n/a | preserve |
| `0x00481b60...` | UID0002FP | unrelated ChattingHandlePane helper | true | ChattingHandlePane | current | protected boundary |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x48124d` | release/commit call from `sub_4811C0` | ECX selector; stack event Y then X; result dispatches row action |
| `0x481430` | hover call from `sub_4811C0` | ECX selector; stack event Y then X; AL stored to `m_hotRow` and compared with `0xff` |
| `0x481b11` | call `InitRectBounds` | constructs row bounds in left/top/right/bottom order |
| `0x481b1e` | call `PointInRect` | half-open Y/X point containment |
| `0x481605` | OnPaint call to `sub_481A80` | ECX selector; signed hot row and local RectBounds output |
| `0x614f84` | sole data xref to caller `sub_4811C0` | selector virtual method ownership |

## Documentation Evidence And IDA Status

- Supporting docs already exact: UID00001Z class declaration, UID0001VP RectBounds layout/Y-X rule, UID00015S source-facing RectGeometry helpers, UID0000I5 source route.
- Ordinary callback closure: UID000106 now has exact C++, hash, source ABI, and blocker resolution; UID0002FM is documented as the private member with current ABI/hash; UID0002FJ has corrected Y/X event order and result use; UID0002FL has the exact sibling member-call setup. Their accepted hashes and scoped validator results remain recorded below.
- Current IDA is `APPLIED_VERIFIED`: target, sibling, and caller have accepted member names/types/comments; `PointInRect` has the exact `RectBounds` Y/X contract and no stale `MapRect` cast remains in target decompilation.
- Current command `17510` generated source declares the class helper and emits GetItemRect followed by exactly one UID000106 HitTest body; the former target Empty Emitter Marker is historical and no duplicate target output exists.

## Ranked Ownership Analysis

### 1. Private ChattingVarietySelectPane member

- Evidence for: two exclusive class-method callers, ECX receiver at both calls, accepted private declaration, selector row geometry/state, source adjacency, and direct owner/emitter route.
- Evidence against: optimized body does not read `this`, causing IDA to infer stdcall.
- Decision: accepted. The caller ABI outweighs decompiler inference.

### 2. Static ChattingVarietySelectPane helper

- Evidence for: body uses no receiver data.
- Evidence against: both callers still load ECX with the selector, and the accepted class declares a non-static private method.
- Decision: rejected as less faithful to the call sites and source closure.

### 3. File-local/free hit-test helper

- Evidence for: machine body could execute without `this`.
- Evidence against: explicit ECX setup, class-private sibling pattern, accepted class declaration, and exclusive class callers.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Not applicable. Keep the body in existing `NexusTK/social/Chatting.cpp` source order immediately after `GetItemRect`.

## Source Placement

- Recommended placement: private `ChattingVarietySelectPane` definition in [UID:0000I5] `NexusTK/social/Chatting.cpp`.
- Source order: after [UID:0002FM] `GetItemRect`, matching binary order and existing generated class declaration.
- Rejected placement: `ChattingVarietyPane` owns only compact `(0,0,62,24)` helpers; `ChattingHandlePane` begins after padding at `0x481b60`; generic RectBounds owns only shared geometry primitives.
- Remaining uncertainty: exact original file split cannot be symbol-proven, but no evidence supports a different file and this does not block source-quality draft C++.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x00481ad0,0x00481b5b)` with no embedded padding/data.
- Predecessor [UID:0002FM] ends at `0x00481acd`; separate three-byte `0xcc` item `[0x00481acd,0x00481ad0)` has SHA-256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`.
- Separate five-byte `0xcc` item `[0x00481b5b,0x00481b60)` has SHA-256 `992CF51486F901AA1AA7D1F63E18C150C9156166E08E0B9E59CC3FAF98177329`.
- Successor `0x481b60` is already named `ChattingHandlePane__IsRenderStateCurrent` and must not be merged.
- No split, merge, child creation, range extension, or reclassification is warranted.

## Negative Evidence Summary

- No additional caller or callback route exists outside selector OnMouseEvent.
- No target vtable slot exists because this is a private helper called by the virtual dispatcher.
- No use of target `this` exists after optimization, but this does not prove static/free ownership because callers still supply ECX.
- No evidence supports compact-pane geometry, ColorPane ownership, HandlePane ownership, generic RectBounds ownership, or BulletinSession ownership.
- No evidence supports X/Y formal order; all current high-quality project geometry evidence says Y/X.
- No original symbol proves `HitTest`, but accepted class/sibling naming makes raw `sub_481AD0` or artificial address-derived names worse and impermissible in final source.
- No no-code condition exists: target is reconstructable, class-owned, emitter-routed, above gate, and expressible without placeholder names.

## IDA Rename / Type / Comment Recommendations

Historical stable handoff prestate was saved-IDB SHA-256 `7509EC8477DC19D5028386F3DE945F319988B275B704DE7AF7A4C0CD10E3B331`, 143,186,450 bytes, last write `2026-07-24T22:54:09.6318603-04:00`. The `E2128EF4804CEB23ED4619C27A7C1B7808D050E08571B25BB3C8E40646448931` and `9DF44486A6C1DC34A55BDE2EB8E517916E0B073D46712BC7C1B9B1D3ECB9EB4C` observations are also historical. B003 performed read-only queries only. Supervisor Gate 2B matched the semantic prestate row by row, protected backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-pending-gate2b-20260725_050130.bak` at SHA-256 `F812F1170EAAA4FC047EE006C61475D4671B28AC2AF8C8EAF4A5EB573756DFA8`/143,186,450 bytes, applied C106-31 through C106-33, and saved `3B7FC953A07344D07F33CD8C244853E0CD8DBFF8AB80C4DE2839D14A9800B63C`/143,186,450 bytes at `2026-07-25T05:12:18.1184370-04:00`. Audit entry `B003 UID000106 Independent Gate 2B` and catalog entry `0311` are authoritative.

### Accepted Gate 2B rows and historical prestates

| Entity | Literal current pre-state | Current comments | Proposed supervisor action | Collision/boundary constraints | Exact expected readback |
| --- | --- | --- | --- | --- | --- |
| Function `[0x481ad0,0x481b5b)` | Name `sub_481AD0`; type `char __stdcall(int, int)`; size `0x8b`; two xrefs `0x48124d`,`0x481430` | Entry regular absent; entry repeatable absent; function regular absent; function repeatable absent | Rename `ChattingVarietySelectPane__HitTest`; apply `signed char __thiscall ChattingVarietySelectPane__HitTest(ChattingVarietySelectPane *this, int mouseY, int mouseX)`; function comment `Private ChattingVarietySelectPane six-row hit test. Tests rows 0..5 using GetItemRect geometry and half-open PointInRect(mouseY, mouseX), returning the signed row index or -1.` | Proposed name has no collision; preserve exact range, both xrefs, internal comments, pre/post padding, and successor | New name/type/comment exact; size/xrefs/bytes unchanged; decompile shows member-style Y/X arguments and signed row result |
| Target Hex-Rays local in `0x481ad0` | Current name `v2`; type `char`; register BL; stable across current decompile | Local comment channel not applicable | Rename to `itemIndex`; set type `signed char` if local type application is accepted | Do not rename compiler temporaries `v3..v7`; do not manufacture a persistent source field | Decompile uses `signed char itemIndex`, loop `0..5`, return `itemIndex/-1` |
| Function `[0x481a80,0x481acd)` | Name `sub_481A80`; type `void __stdcall(int, struct RectBounds *bounds)`; size `0x4d`; sole xref `0x481605` | Entry regular absent; entry repeatable absent; function regular absent; function repeatable absent | Rename `ChattingVarietySelectPane__GetItemRect`; apply `void __thiscall ChattingVarietySelectPane__GetItemRect(ChattingVarietySelectPane *this, int row, RectBounds *outRect)`; function comment `Private ChattingVarietySelectPane row-rectangle helper. Writes (-1,-1,-1,-1) for row -1; otherwise writes (0,row*16+6,67,row*16+22).` | Name has no collision; preserve exact range, sole caller, operand comments, and following padding | Exact name/type/comment; size/xref/bytes unchanged; decompile shows member helper and outRect |
| Function `[0x4811c0,0x481461)` | Name `sub_4811C0`; type `bool __thiscall(_BYTE *this, _DWORD *Block)`; size `0x2a1`; sole data xref `0x614f84` | Entry regular absent; entry repeatable absent; function regular absent; function repeatable absent | Rename `ChattingVarietySelectPane__HandlePointerOrMouseEvent`; apply `bool __thiscall ChattingVarietySelectPane__HandlePointerOrMouseEvent(ChattingVarietySelectPane *this, Event *event)`; function comment `ChattingVarietySelectPane pointer-event dispatcher. Hit-tests hover and release points, commits Talk/Shout/Whisper/Group/Clan rows, and opens ChattingColorPane for row 5.` | Name has no collision; preserve vtable xref/range/all behavior; do not infer unresolved row-command helper names here | Exact name/type/comment; vtable xref and bytes unchanged; calls resolve to typed HitTest |
| Function `[0x4b7e80,0x4b7ea7)` | Name `PointInRect`; type `bool __cdecl(int row, int column, const MapRect *bounds)`; size `0x27`; 270 code xrefs | Entry regular absent; entry repeatable absent; function regular `Half-open row/column containment test for MapRect bounds.`; function repeatable absent | Keep name; apply `bool __cdecl PointInRect(int y, int x, const RectBounds *bounds)`; replace function comment with `Half-open containment test: bounds->left <= x < bounds->right and bounds->top <= y < bounds->bottom.` | Broad shared action: preserve all 270 xrefs and body; require existing 16-byte RectBounds; do not create/overwrite MapRect or Point | Exact corrected type/comment; all xrefs/body unchanged; target decompile loses stale MapRect cast |

### Exact protected/no-change dependencies

| Entity | Literal current pre-state | Current comments | Disposition and expected readback |
| --- | --- | --- | --- |
| `RectBounds` UDT | 16 bytes: `left` int +0, `top` int +4, `right` int +8, `bottom` int +0xc | UDT comment not exposed by current read-only query | `ALREADY_PRESENT/NO_CHANGE`; exact four fields remain |
| `Point` UDT | 8 bytes: `y` int +0, `x` int +4 | UDT comment not exposed | `ALREADY_PRESENT/NO_CHANGE`; preserve Y/X order |
| `Event` UDT | 272 bytes: `vftable` +0, `m_type:EventType` +4, `m_payload:EventPayload` +8 size264 | UDT comment not exposed | `ALREADY_PRESENT/NO_CHANGE`; no broad event mutation from this target |
| `ChattingVarietySelectPane` type | Named opaque declaration; no UDT; unknown size | Type comment not exposed | `NO_CHANGE`; do not create a partial broad UDT during this gate |
| Function `0x4b7c50` | Name `InitRectBounds`; type `void __cdecl(RectBounds *bounds,int left,int top,int right,int bottom)`; size `0x1f`; exactly 1,731 inbound xrefs | Entry regular absent; entry repeatable absent; function regular `Initializes RectBounds fields in left, top, right, bottom order.`; function repeatable absent | `ALREADY_PRESENT/NO_CHANGE`; preserve name/type/comment/body/all 1,731 xrefs |
| Padding `[0x481acd,0x481ad0)` | One 3-byte data item, bytes `cc cc cc`, no name/type | Regular absent; repeatable absent | `NO_CHANGE`; preserve separate item and boundaries |
| Padding `[0x481b5b,0x481b60)` | One 5-byte data item, bytes `cc cc cc cc cc`, no name/type | Regular absent; repeatable absent | `NO_CHANGE`; preserve separate item and boundaries |
| Successor `[0x481b60,0x481bb9)` | Name `ChattingHandlePane__IsRenderStateCurrent`; type `bool __thiscall(const ChattingHandlePane *this,const ChattingHandleRenderState *state)`; size `0x59`; zero inbound entry xrefs | Entry regular absent; entry repeatable absent; function regular `Retained private ChattingHandlePane::IsRenderStateCurrent helper. Compares the valid-first six-field 24-byte render state; zero inbound entry xrefs remain optimization evidence.` followed by `IDA analysis type names the two natural-alignment byte spans only to reproduce the exact 24-byte MSVC layout; they are compiler padding, not source fields.`; function repeatable absent | `NO_CHANGE`; preserve unrelated function, exact two-paragraph function comment, zero-xref state, and start/end boundaries |

### Existing target operand comments to preserve exactly

| Address | Current regular | Current repeatable | Expected readback |
| --- | --- | --- | --- |
| `0x481b09` | `bottom` | absent | unchanged |
| `0x481b0a` | `right` | absent | unchanged |
| `0x481b0b` | `top` | absent | unchanged |
| `0x481b0c` | `left` | absent | unchanged |
| `0x481b10` | `bounds` | absent | unchanged |
| `0x481b19` | `bounds` | absent | unchanged |
| `0x481b1a` | `column` | absent | unchanged unless type propagation displays `x`; do not overwrite manually |
| `0x481b1b` | `row` | absent | unchanged unless type propagation displays `y`; do not overwrite manually |
| `0x481b39` | `StackCookie` | absent | unchanged |
| `0x481b4d` | `StackCookie` | absent | unchanged |

### Existing GetItemRect operand comments to preserve exactly

| Address | Current regular | Current repeatable | Expected readback |
| --- | --- | --- | --- |
| `0x481a9c` | `bottom` | absent | unchanged |
| `0x481a9d` | `right` | absent | unchanged |
| `0x481a9e` | `top` | absent | unchanged |
| `0x481a9f` | `left` | absent | unchanged |
| `0x481aa0` | `bounds` | absent | unchanged |
| `0x481ab7` | `bottom` | absent | unchanged |
| `0x481ab8` | `right` | absent | unchanged |
| `0x481abb` | `top` | absent | unchanged |
| `0x481abc` | `left` | absent | unchanged |
| `0x481abd` | `bounds` | absent | unchanged |

### Supervisor Gate 2B applied/readback state

- Gate state: `APPLIED_VERIFIED` for C106-31 through C106-33 under audit entry `B003 UID000106 Independent Gate 2B - 2026-07-25T05:12:18-04:00` and catalog entry `0311`.
- Target: `0x00481ad0` is `ChattingVarietySelectPane__HitTest` with `signed __int8 __thiscall(ChattingVarietySelectPane *this, int mouseY, int mouseX)`; size remains `0x8b`, xrefs remain exactly `0x48124d` and `0x481430`, and local `v2` is now `signed __int8 itemIndex`.
- Sibling: `0x00481a80` is `ChattingVarietySelectPane__GetItemRect` with the accepted `ChattingVarietySelectPane *this`, signed row, and `RectBounds *outRect` member/out-rectangle type; size remains `0x4d` and sole xref remains `0x481605`.
- Caller: `0x004811c0` is `ChattingVarietySelectPane__HandlePointerOrMouseEvent` with `ChattingVarietySelectPane *this` and `Event *event`; size remains `0x2a1` and its sole vtable data xref remains `0x614f84`.
- Shared helper: `PointInRect` retains its name and now has `bool __cdecl PointInRect(int y, int x, const RectBounds *bounds)`; size remains `0x27` and all 270 xrefs remain.
- Exact regular function comments are: target `Private ChattingVarietySelectPane six-row hit test. Tests rows 0..5 using GetItemRect geometry and half-open PointInRect(mouseY, mouseX), returning the signed row index or -1.`; sibling `Private ChattingVarietySelectPane row-rectangle helper. Writes (-1,-1,-1,-1) for row -1; otherwise writes (0,row*16+6,67,row*16+22).`; caller `ChattingVarietySelectPane pointer-event dispatcher. Hit-tests hover and release points, commits Talk/Shout/Whisper/Group/Clan rows, and opens ChattingColorPane for row 5.`; helper `Half-open containment test: bounds->left <= x < bounds->right and bounds->top <= y < bounds->bottom.`
- Comment channels: those four literals exist only as regular function comments. Entry regular, entry repeatable, and function-repeatable channels are empty for all four. A transient legacy-tool channel mismatch was cleared before final save.
- Protected UDT/type readback is unchanged: `RectBounds` is 16 bytes with `left/top/right/bottom`; `Point` is 8 bytes in Y/X order; `Event` is 272 bytes with its three-member layout; `ChattingVarietySelectPane` remains opaque.
- Protected function/item readback is unchanged: `InitRectBounds` retains its exact type, regular function comment, body, and 1,731 xrefs; padding remains separate three-byte and five-byte `0xcc` data items; successor `ChattingHandlePane__IsRenderStateCurrent` retains its exact name/type/two-paragraph regular function comment, `0x59` range, and zero xrefs.
- All twenty protected operand comments remain. Target comments read back as `bottom`, `right`, `top`, `left`, `bounds`, `bounds`, `x`, `y`, `StackCookie`, `StackCookie` at the ten listed addresses; GetItemRect comments read back as `bottom`, `right`, `top`, `left`, `bounds`, `bottom`, `right`, `top`, `left`, `bounds`. The only permitted display change was type propagation from target labels `column`/`row` to `x`/`y`; no operand comment was manually overwritten.
- Decompiler readback uses `signed __int8 itemIndex`, member-style Y/X formals, `PointInRect(mouseY, mouseX, &bounds)`, exactly six rows, and signed `itemIndex`/`-1` return without a stale `MapRect` cast.
- Save/readback: `idb_save` returned `ok:true`; saved IDB SHA-256 is `3B7FC953A07344D07F33CD8C244853E0CD8DBFF8AB80C4DE2839D14A9800B63C`, 143,186,450 bytes, last write `2026-07-25T05:12:18.1184370-04:00`. Post-save `server_health` and all four primary lookups succeeded in session `f6f2c166`.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Exact behavior, ownership, source types, source route, declaration, and dependencies are closed.
- CPP destination: [UID:000106].

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
signed char ChattingVarietySelectPane::HitTest(int mouseY, int mouseX)
{
    for (signed char itemIndex = 0; itemIndex < 6; ++itemIndex)
    {
        RectBounds itemRect;
        GetItemRect(itemIndex, &itemRect);

        if (PointInRect(mouseY, mouseX, &itemRect))
            return itemIndex;
    }

    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- H destination: [UID:000106]. The class-level UID00001Z formal already declares this exact private method, so the child header block must remain empty rather than duplicate the declaration.

*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

- Runtime equivalence: six ordered rows, same rectangle helper semantics, same half-open point test, first-hit return, signed-byte result, and `-1` miss.
- Source-shape fidelity: an ordinary loop calling the adjacent private GetItemRect helper best explains the retained inlined `row == -1` branch. Security-cookie and register artifacts are excluded.
- Naming/style: matches current project class declarations and compact sibling `HitTest` style; no IDA/decompiler placeholders appear.
- Third-party import: not applicable; this is first-party NexusTK UI code.

## Final Recommendation

- C106-01 through C106-30 are implemented or verified no-change at report-level detail. The exact UID000106 body is installed, target H remains empty, and UID00001Z remains the sole class declaration/owner/emitter route through `social/Chatting.cpp`.
- UID0002FM is now `92/94`; other support metadata remained unchanged while exact ABI, result, source-order, inlining, and aggregate-index evidence was incorporated.
- Current command `17510` generated output has exactly one UID000106 occurrence/body, one `ChattingVarietySelectPane::HitTest` definition, zero UID000106 Empty Emitter Markers, and no duplicate target output.
- Independent supervisor Gate 2A passed for the callback destination hashes, historical commands `17441` through `17449`, ledger states, and then-current generated invariants. Fresh Gate 1 preflight established physical generated continuity at command `17510`; supervisor Gate 2B remains `APPLIED_VERIFIED` for C106-31 through C106-33 at saved-IDB SHA `3B7FC953...B63C`.
- Fresh exact-artifact Gate 1 continuity for this reconciled report remains required before supervisor execution/archive; exact C106-34 manual coverage replacements follow execution.
- No target-specific research question remains unresolved. Future full final-audit symbol spelling work is outside this score pass and does not block draft C++.

## Recommended Target Doc Changes

- APPLIED_VERIFIED: target path `by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md` is `92/94` with preserved owner/reconstructable/emitter/position, exact CPP, and empty H formals.
- APPLIED_VERIFIED: stale Item Summary was replaced with current behavior/source-readiness text.
- APPLIED_VERIFIED: exact hash/range/padding, callers/call-site ABI, Y/X arguments, signed return, loop/geometry/half-open semantics, inlined GetItemRect proof, compiler boundary, source placement, score rationale, and IDA handoff provenance are present.
- APPLIED_VERIFIED: historical `82/90` and `86/91`, blank-C++, x/y, file-local/static, and Wave3 assumptions remain only as explicit superseded history.
- APPLIED_VERIFIED: supervisor Gate 2B applied and read back the exact IDA handoff under catalog entry `0311`; no target ordinary-document or IDA work remains pending.

## Recommended Support Doc Changes

- APPLIED_VERIFIED: `by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md` is `92/94`, preserves CPP/H/route, and records exact 77-byte hash, sole OnPaint caller ABI, private-member signature, inlining relation, and IDA prestate.
- APPLIED_VERIFIED: `by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md` keeps metadata/formals and records `mouseY` at `+8`, `mouseX` at `+0xc`, receiver/stack setup, and result use at both calls.
- APPLIED_VERIFIED: `by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md` keeps metadata/formals and records exact `0x481605` member-call ABI.
- APPLIED_VERIFIED: `by-class/ChattingVarietySelectPane.md` keeps `92/94`/formal and records exact signatures, source-ready status, return/geometry, compiler boundary, and child-emission ownership.
- APPLIED_VERIFIED: `by-file/Chatting.md` keeps `89/93` and records target/GetItemRect closure, Y/X/signed-result behavior, source order, and compiler inlining.
- APPLIED_VERIFIED: `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md` keeps `88/93` and its nonduplicative aggregate formal while indexing source-ready children and exact caller ABI.
- VERIFIED_NO_CHANGE: `by-type/by-struct/RectBoundsLayout.md` and `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` still match accepted hashes and exact Y/X, layout, half-open, and source-form evidence.

## Score And Metadata Recommendation

- Historical assignment baseline: `86/91`, owner `00001Z`, true, emitter `00001Z`, blank CPP/H.
- Current callback-applied target: `92/94`, same owner/reconstructable/emitter/position, populated CPP, empty H.
- Reason not lower: exact code/hash, exclusive callers, member ABI, source types, loop/geometry/return, source route, declaration, dependency body, and generated defect are all proven.
- Reason not higher: original private-helper/local spelling is inferred rather than symbol-proven, and the wider OnMouseEvent body still has unrelated helper-name blockers. Under the 95 barrier, `92/94` accurately distinguishes source-ready draft from final original-source certainty.
- UID0002FM: callback-applied `86/92 -> 92/94`, route unchanged, existing CPP/H preserved.
- Other support scores/routes unchanged.
- Every prior score blocker was actively investigated and closed; none is deferred to later C++ work.

## Open Questions With Attempted Resolution

- Was it static/free because `this` is unused? No. Both exclusive callers load selector ECX; accepted as non-static private member.
- Are coordinates X/Y? No. Caller order, helper semantics, Point UDT, and RectBounds docs prove Y/X.
- Is return `char`, `signed char`, or int? Signed char best preserves AL/BL and `-1`; accepted.
- Was geometry handwritten in target? Most likely no. The unreachable `row == -1` branch and exact sibling body prove GetItemRect inlining; source calls helper.
- Is the body blocked by Rect/MapRect naming? No. Canonical source type is RectBounds; supervisor Gate 2B applied the exact correction and target decompilation no longer contains the stale MapRect cast.
- Does target need H code? No. UID00001Z already owns the exact private declaration.
- Could original spelling differ from HitTest? Possibly, but current class/sibling naming makes HitTest the highest-probability human spelling. This affects only final-grade certainty, not draft eligibility.
- Questions remaining unresolved: none that affect behavior, ownership, source placement, score gate, or C++ entry.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected current by-memory manual rows: UID000106 line 831, UID0002FM line 829, UID0002FJ line 819, UID0002FL line 823. All four are stale at 82 percent.
- Inspected class UID00001Z row line 96, file UID0000I5 row line 49, and aggregate UID000104 row line 747. Their current scores/routes remain valid and require no replacement from this report.
- Supervisor must apply these exact replacements only after execution/archive:

```markdown
        - [UID:0002FJ][0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent](by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md) 0x004811c0-0x00481461 | class method | ChattingVarietySelectPane::HandlePointerOrMouseEvent : reconstructable : 86% : strong : Exact vtable-owned selector pointer dispatcher; release and hover calls load the selector receiver into ECX, pass event mouseY then mouseX to UID000106, consume signed row 0..5/-1, maintain press/hot-row state, commit Talk/Shout/Whisper/Group/Clan actions, and open ChattingColorPane for Color. Broader command-helper naming still keeps formal method C++ blank.
        - [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md) 0x00481490-0x004816ce | class method | ChattingVarietySelectPane::OnPaint : reconstructable : 86% : strong : IDA-verified selector label/highlight paint method; call 0x00481605 passes selector ECX, sign-extended m_hotRow, and a local RectBounds output to private UID0002FM GetItemRect before drawing the active frame.
        - [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) 0x00481a80-0x00481acd | private member | ChattingVarietySelectPane::GetItemRect : reconstructable : 92% : very-strong : Exact 77-byte body, SHA-256 BC85785B59C28F4DD1E0676D70F9054472EE01668833D34AD33299C34A922061, sole OnPaint caller with selector ECX, signed row and RectBounds output, invalid (-1,-1,-1,-1) case, normal (0,row*16+6,67,row*16+22) geometry, and source-ready child C++ reused/inlined by UID000106.
        - [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md) 0x00481ad0-0x00481b5b | private member | ChattingVarietySelectPane::HitTest : reconstructable : 92% : very-strong : Exact 139-byte body, SHA-256 AFD9F146918CF5A289F5FD0D7724FD34C16B02E619F638196DDDCD53D1BE6E6B, two exclusive selector OnMouseEvent callers with ECX receiver and mouseY/mouseX arguments, six rows, inlined GetItemRect geometry, half-open PointInRect, signed 0..5/-1 return, exact padding boundaries, and destination-ready C++ through ChattingVarietySelectPane/Chatting.cpp.
```

- B003 must not edit `by-memory/-coverage-report.md`; it is a high-collision supervisor-owned file.
- The validator-owned research tracker must not be manually edited. Report execution/validator refresh will update direct coverage.

## Follow-Up Actions

- Supervisor fresh Gate 1: verify this exact post-Gate-2B reconciled report, 34 ledger rows, two formals, current lifecycle wording, destination hashes, validator results, generated readback, and catalog entry `0311`/saved SHA `3B7FC953...B63C` continuity.
- B003 ordinary callback: complete. Seven destinations were edited, serially validated, read back, and released; UID0001VP/UID00015S were verified no-change.
- Supervisor Gate 2A: complete and independently verified claim by claim.
- Supervisor Gate 2B: `APPLIED_VERIFIED` for C106-31 through C106-33; backup `F812F117...56DFA8`, catalog entry `0311`, and saved checkpoint `3B7FC953...B63C` record the exact operation/readback.
- Supervisor only: execute/archive after fresh exact-artifact Gate 1 continuity check; then apply manual coverage replacements.
- No future B-agent research is required unless Gate 1 finds a concrete contradiction or current IDB drift changes an actionable prestate.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: very strong for `92/94` and below-95 cap.
- Remaining uncertainty: original symbol/local spellings and exact historical source file split are not symbol-proven. Plausible human names and the current source route are nevertheless strongly constrained and no reverse-engineered placeholder is warranted.

## Validator Results

- All callback validators were run serially from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; every command exited `0` with `ok: 1` and deferred generated refresh.
- `17441` at `2026-07-24T22:29:31-04:00`: UID000106 target, exit `0`, `ok: 1`.
- `17442` at `2026-07-24T22:30:28-04:00`: UID0002FM, exit `0`, `ok: 1`.
- `17443` at `2026-07-24T22:31:41-04:00`: UID0002FJ, exit `0`, `ok: 1`.
- `17444` at `2026-07-24T22:32:26-04:00`: UID0002FL, exit `0`, `ok: 1`.
- `17445` at `2026-07-24T22:34:27-04:00`: UID00001Z, exit `0`, `ok: 1`.
- `17447` at `2026-07-24T22:35:32-04:00`: UID0000I5, exit `0`, `ok: 1`.
- `17449` at `2026-07-24T22:36:51-04:00`: UID000104, exit `0`, `ok: 1`; this is the historical callback validator checkpoint.
- Historical generated readback after command `17449`: `auto-generated/NexusTK/social/Chatting.cpp`, refreshed `2026-07-24T22:36:51-04:00`, SHA-256 `651379C4768C967F8AAD45BE9110C0725874A0ED0896A444FBFE18F71D8F2DDA`, 66,447 bytes/1,989 lines. UID0002FM body was lines 572-582; exactly one UID000106 entry/body was lines 584-597; there were zero UID000106 Empty Emitter Markers and no duplicate target body/declaration or H/HPP output.
- Current physical generated readback from fresh supervisor Gate 1 preflight: command `17510`, refreshed `2026-07-25T04:52:56-04:00`, SHA-256 `D1D01D808ACF89F7401B925F0D4907BBCBCA2223C2766D4C50624A261DC113E5`, 66,449 bytes/1,989 lines. Semantic invariants remain exactly one UID000106 occurrence/body, one `ChattingVarietySelectPane::HitTest` definition, zero UID000106 Empty Emitter Markers, and no duplicate target output.
- Unresolved validator warnings/errors: none.
- This same-report continuity repair ran no validator and changed no ordinary/generated artifact. Commands `17441` through `17449` remain the historical callback record; command `17510` is the current physical generated identity supplied by fresh supervisor Gate 1 preflight.

## Changed Files

- Reconciled report: `tools/leaser/Agents/Agent-B003/research/000106-ChattingVarietySelectPaneHitTest-empty-emitter-source-quality.md`.
- Modified ordinary destination: UID000106 SHA `BE6B665DD1CD12FE6B01A33472981A1177903C77CDF5AF34AD710B93F7C4A600`, 13,004 bytes/121 lines.
- Modified ordinary destination: UID0002FM SHA `8D6EDD2C86895392DEDC4BB96A098E087717E542B140C36B4B9FFB0045943EC9`, 6,146 bytes/81 lines.
- Modified ordinary destination: UID0002FJ SHA `318D586FE455F06BA3247841F91BD8F6B7FE7E583D06E2A85B7C74C6B82955F0`, 12,660 bytes/114 lines.
- Modified ordinary destination: UID0002FL SHA `D0D8CC6CBA6D2B8B28FE7248418C99A3C7C26C228D3B8DD07D69DE8FF84F1AB9`, 6,180 bytes/96 lines.
- Modified ordinary destination: UID00001Z SHA `495FCAC8E58E1F43E52040469697D56E1333657AD6119AA0BA4E58842706EBA4`, 22,707 bytes/148 lines.
- Modified ordinary destination: UID0000I5 SHA `8EFC83D392B2C2E2359F768E67CF66DECD3A68A3FDB273138C8183D13A3A8321`, 154,798 bytes/499 lines.
- Modified ordinary destination: UID000104 SHA `CE3620A2F959AEDFE3D4B1C36422409569674A055FBE704B27EDB8493C76F785`, 104,799 bytes/441 lines.
- Verified no-change: UID0001VP SHA `F91373E23033563A2164F77C929437089976BA88F234A4A49AF4D3FF300DC496`; UID00015S SHA `52A86FFDE507C1D9664B19410E83351DC50D072A5935E4CD3D7C4CEB517EEDBF`.
- Lease readback: each of the seven ordinary destinations was leased only for its immediate edit/validation and successfully released before the next destination.
- Validator-owned side effects: projected completion stats and deferred generated output refreshed through the historical scoped commands; B003 did not manually edit them.
- Renamed: none.
- Report execution: not run. B003 did not run, probe, dry-run, or invoke any report lifecycle/registry command.
- IDA: B003 remained read-only. Supervisor Gate 2B applied C106-31 through C106-33 and saved SHA `3B7FC953A07344D07F33CD8C244853E0CD8DBFF8AB80C4DE2839D14A9800B63C`; audit/catalog records are `APPLIED_VERIFIED`.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Accepted report-only artifact passed supervisor Gate 1 before implementation.
- [x] Update UID000106 at full report-level detail with `92/94`, exact CPP, and empty H.
- [x] Additional target UIDs: none; support pages remain ordinary evidence destinations, not declared report targets.
- [x] Verify exact current target state, hashes, command `17510` generated marker/body invariants, tracker, and manual rows; historical IDA handoff was rebased against stable saved revision `7509` before supervisor application.
- [x] Apply/verify C106-01 through C106-30 at their exact ordinary destinations; C106-31 through C106-33 are supervisor `APPLIED_VERIFIED`, while C106-34 remains supervisor-owned post-execution coverage.
- [x] Apply target `86/91 -> 92/94` and UID0002FM `86/92 -> 92/94`; leave all other support scores unchanged.
- [x] Preserve UID00001Z owner, reconstructable true, UID00001Z emitter, blank position, and existing class/file route.
- [x] Confirm no split/rename/new child; preserve three-byte/five-byte padding and unrelated successor.
- [x] Supervisor Gate 2B applied/verified every actionable/protected IDA row, saved SHA `3B7FC953...B63C`, and recorded audit/catalog entry `0311`; B003 made no IDA mutation.
- [x] Install exact target CPP block and preserve exact empty target H block; preserve class-owned declaration.
- [x] Third-party import directive is not applicable.
- [x] Incorporate all target/support facts without summary loss or pruning.
- [x] Preserve historical stale assumptions and explain why x/y, file-local/static, blank-C++, and threshold blockers were superseded.
- [x] Wave2/Wave3 artifacts encountered remain ignored as stale.
- [x] Open questions remain closed; no implementation-time contradiction was found.
- [x] Run serial scoped validators for every changed ordinary by-* doc during callback only.
- [x] Verify generated CPP/H invariants.
- [ ] Supervisor applies exact manual coverage replacements only after execution/archive.

Implementation callback pass:
- [x] Supervisor-owned IDA changes are `APPLIED_VERIFIED`; they were not applied by B003.
- [x] Report accepted by supervisor for implementation at exact SHA `D48ED99...0A39`.
- [x] All accepted target/support details incorporated at report-level detail.
- [x] UID000106 independently verified against ledger, destination, and generated output.
- [x] Ledger verification states updated from proposed to exact applied/read-back or supervisor-pending states.
- [x] Metadata/score/CPP/H changes applied with no external blocker.
- [x] Historical assumptions, rejected alternatives, positive/negative evidence, and source-shape rationale preserved.
- [x] Open questions rechecked against implementation-time evidence.
- [x] Scoped validators run serially and exact results/command IDs recorded.
- [x] Generated Chatting.cpp historical callback checkpoint `17449` and current physical checkpoint `17510` are both recorded; current UID000106 occurrence/body/definition/empty-marker/duplicate invariants are exact.
- [x] Supervisor Gate 2A and Gate 2B C106-31..33 are complete; remaining supervisor-owned items are fresh exact-artifact Gate 1 continuity, execution/archive, and post-execution C106-34 coverage.
- [x] Independent supervisor Gate 2A verification passed claim by claim before Gate 2B.
- [ ] Supervisor fresh exact-artifact Gate 1 continuity for this reconciled report remains pending.
- [ ] Supervisor execution/archive remains pending after that fresh Gate 1; post-execution C106-34 coverage remains pending.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000017511","destination_path":"executed-b-agent-research/B003/000106-ChattingVarietySelectPaneHitTest-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/000106-ChattingVarietySelectPaneHitTest-empty-emitter-source-quality.md","timestamp":"2026-07-25T22:25:05-04:00","uid":"000106"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
