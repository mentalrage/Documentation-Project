** TARGET-REPORT-UID:00044X **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00044X ScrollNewGroupPaneConstructor Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: refresh [UID:00044X] `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md` with current MCP evidence, exact byte/padding proof, xref/callee facts, caller argument proof, and score rationale.
- Final disposition: keep the current direct owner/emitter [UID:0000CL] `ScrollNewGroupPane`, source route through [UID:0000JS] `Group` / `NexusTK/social/Group.cpp`, reconstructable `TRUE`, emitter position `40`, and the existing formal first-draft constructor C++.
- Callback status: supervisor Gate 1 accepted this report; the implementation callback applied the target-only refresh and left support docs unchanged because they already carried the accepted facts at same-or-greater detail.
- Confidence: high for range, owner/emitter route, behavior, and current C++ behavior; medium-high for exact original parameter spelling/type and final whole-class declaration polish.

## Supporting Research

This is a new UID00044X-specific report for a target that the generated research tracker still lists with direct reports `0`. The earlier B005 report created the UID00044X child as part of the parent [UID:0001GP] split, so it is valid implementation history, but it is not a UID00044X-targeted executed report. This pass supplies current live MCP evidence from session `b001-0001I5` rather than relying only on B005 session `80de0a67`.

Historical lifecycle note: this assignment previously paused because MCP was reachable but `idb_list` returned zero active sessions. The supervisor later reported the active `b001-0001I5` session, and this resumed pass collected live MCP evidence before writing the report.

Initial report-only generated state checked read-only before callback:

- `auto-generated/NexusTK/social/Group.cpp` header: `validator-command-id: 000000007586`, `validator-refreshed-at: 2026-07-06T13:33:39-04:00`; it emits UID00044X as `86/89` with the same constructor C++ currently present in the target page.
- `auto-generated/-ag-research-tracker.md` header: `validator-command-id: 000000007623`, `validator-refreshed-at: 2026-07-06T18:21:27-04:00`; UID00044X remains `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- `auto-generated/-ag-coverage-report-by-memory.md` header: `validator-command-id: 000000007623`, `validator-refreshed-at: 2026-07-06T18:21:27-04:00`; UID00044X remains an emitting reconstructable `86% : strong` row updated from the original B005 child creation.

Implementation callback generated state checked read-only:

- Scoped validator command `000000007628` refreshed `auto-generated/NexusTK/social/Group.cpp` at `2026-07-06T18:46:14-04:00`; UID00044X emitted as `88/90` with the unchanged constructor C++. A final read-only freshness check later saw the generated header at newer `validator-command-id: 000000007639`, `validator-refreshed-at: 2026-07-06T18:48:51-04:00`, still emitting UID00044X as `88/90`.
- Generated tracker/coverage files remain validator-owned and were not manually edited by B006.

## Target

- Target UID: `00044X`.
- Target path: `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md`.
- Initial source queue/report row: `auto-generated/-ag-research-tracker.md` by-memory not-covered reconstructable row, `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- Current supervisor classification: implementation callback complete; stop at `READY_FOR_SUPERVISOR_EXECUTE` and do not run `execute_report`.
- Current scores and parent state after callback: target `88/90`; direct class owner [UID:0000CL] `ScrollNewGroupPane` is `85/86`; source-file route [UID:0000JS] `Group` is `90/86`; parent split index [UID:0001GP] is non-emitting `88/90`.

## Current Target State

- Post-callback metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:40`.
- Current owner/emitter/reconstructable state: correct. The constructor is a direct `ScrollNewGroupPane` class method, and the class routes through the Group source file.
- Current C++/emitter state: populated formal first-draft C++ constructs `ScrollNewGroupPane::ScrollNewGroupPane(bool horizontal) : Pane(true)` and initializes the documented scroll-tail fields; callback left the block unchanged.
- Current open questions, blockers, placeholder names, stale assumptions, or contradictory claims: the page now carries both historical B005 MCP session `80de0a67` and current B006 MCP session `b001-0001I5` proof. Exact original parameter spelling/type is not recovered: current IDA sees a `char` argument stored at `+0xfc`, while the source-facing constructor uses `bool horizontal`. The current caller passes literal `0`, so behavior is safe; only original spelling/type certainty is capped.
- Related target/support docs checked: target page, [UID:0000CL] `ScrollNewGroupPane`, [UID:0000JS] `Group`, [UID:0001GP] `ScrollNewGroupPaneCore`, [UID:0002OS] `ScrollNewGroupPaneVtableData`, [UID:0001YR] `ScrollNewGroupPaneVtables`, generated `Group.cpp`, generated tracker, generated memory coverage, and related executed B reports.
- Current artifact/lifecycle status: implementation callback complete in the active B006 report path. No report execution, archive movement, manual report move, generated edit, coverage edit, validator-state edit, supervisor-ledger edit, or unauthorized by-* edit occurred.

## Executive Recommendation

Keep UID00044X attached to [UID:0000CL] `ScrollNewGroupPane` and emitted through [UID:0000CL] at position `40`. The implementation callback updated the target doc from `86/89` to `88/90` because current MCP proves the exact range, one direct `NewGroupPane` caller, constructor field writes, vtable installs, exact padding, and a unique constructor signature. Do not rename, split, reassign, or alter the formal C++ body.

The remaining cap is source-shape certainty, not behavior. IDA does not prove the original constructor parameter name or whether the original source declared it as `bool`, `char`, or a small orientation enum. The caller passes `0`, and sibling geometry uses nonzero as horizontal, so the current `bool horizontal` source-facing spelling remains acceptable.

## Supervisor Active Recheck

- Triggering instruction: supervisor resumed Agent-B006 report-only research for UID00044X after restoring MCP session `b001-0001I5`, then accepted Gate 1 and sent an implementation callback. Report lifecycle commands remain prohibited for B006.
- Split repair requirement: no split repair is required. B005 already split [UID:0001GP] and UID00044X is the exact constructor child.
- Source-bearing child state: UID00044X is a reconstructable emitting child with formal first-draft C++; the callback applied the current evidence/score refresh on that exact target page.

## Inference Research Guidance Check

The current by-structure rules separate direct ownership from emission routing. UID00044X's narrowest semantic owner is the class [UID:0000CL] because the function installs `ScrollNewGroupPane` vtables and initializes class fields. [UID:0000JS] is the source-file route, not the direct owner. [UID:000090] `NewGroupPane` constructs and stores the scrollbar object, but that caller relationship is use/containment evidence rather than method ownership.

IDA facts are separated from inference here:

- IDA facts: function start/size, exact disassembly, xrefs, callees, bytes, vtable data refs, direct caller, and caller argument.
- Documentation evidence: support docs already map fields, class/source route, vtable bases, and parent split.
- Inference: source-facing names such as `ScrollNewGroupPane`, `Pane(true)`, `horizontal`, `m_scrollSkinIndex`, `m_scrollStyleByte`, `m_thumbDragOffset`, and `InitPointPair`.

No current Wave2/Wave3 evidence was used as authority. Existing stale simroot/generated ownership pollution under `TextEditPane` remains rejected by the class/caller/vtable route.

## Heuristic / Inference Reanalysis And Validation

- Constructor identity: validated. `lookup_funcs` reports `sub_560900` at `0x00560900`, size `0xa1` / 161 bytes (Verified with int_convert.py). `xrefs_to 0x00560900` reports one code xref from `0x0056caae` inside `sub_56CA20`, the `NewGroupPane` constructor.
- Parameter role: best source-facing interpretation remains `bool horizontal`. MCP decompile shows `char a2` stored at `this + 252` (`+0xfc`), and caller disassembly/decompile shows `push 0` / `sub_560900(v2, 0)` at `0x0056caae`. Sibling support docs define `+0xfc m_orientation`, zero vertical and nonzero horizontal. A stronger original type claim is unsafe, but the current bool spelling preserves behavior for the proven caller.
- Base constructor/source shape: `sub_544460((char *)this, 1)` and disassembly `push 1; call sub_544460` support `: Pane(true)`. This is inferred source shape, not recovered original symbol proof.
- Vtable installs: MCP confirms writes to `0x00623f1c`, `0x00623f68`, and `0x00623f98` at `0x00560951`, `0x00560957`, and `0x00560961`, matching the class/vtable support docs.
- Field initialization: MCP confirms `+0xf8` dword `0x10000`, which initializes `m_scrollSkinIndex = 0`, `m_scrollStyleByte = 1`, and `m_thumbDragActive = false`; `+0xfe` dword zero initializes `m_scrollPosition` and `m_scrollRange`; `+0x102` word `0xff01` initializes `m_scrollEnabled = 1` and `m_highlightPart = 0xff`; `+0x104` byte `0xff` initializes `m_activePart`; and `sub_4B7C30(this + 0x108, 0, 0)` initializes the point pair.
- Boundary/padding: `get_bytes` confirms four `0xcc` bytes at `0x005608fc-0x00560900` and fifteen `0xcc` bytes at `0x005609a1-0x005609b0` (0x0f / 15 bytes, Verified with int_convert.py). The successor bytes at `0x005609b0` begin the raw skin-index setter body.
- Generated-output state: initial generated `Group.cpp` emitted the correct body at old `86/89` metadata; scoped validator command `000000007628` refreshed it to `88/90` after callback, and the final read-only check saw newer generated header `000000007639` still emitting UID00044X as `88/90`.
- Rejected alternatives:
  - Direct [UID:0000JS] `Group` ownership rejected because by-structure requires the narrowest true owner; this is a class constructor.
  - Direct [UID:000090] `NewGroupPane` ownership rejected because it allocates and stores a `ScrollNewGroupPane`, but the callee installs `ScrollNewGroupPane` vtables and initializes `ScrollNewGroupPane` fields.
  - Generic scrollbar ownership rejected because generic scrollbars are pattern evidence only; target-local vtables, fields, and caller route are `ScrollNewGroupPane`.
  - No-owner/non-emitting rejected because range, caller, vtable, field writes, and generated route are all strong.
  - C++ rewrite rejected because current formal body is behaviorally aligned with live MCP; only evidence/prose/score need refresh.

## Evidence Standards Used

- IDA MCP functions used: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `xref_query`, `callees`, `decompile`, `analyze_function`, `disasm`, `get_bytes`, `insn_query`, and `make_signature_for_range`.
- Local project tools used: `tools/int_convert.py` after reading `tools/int_convert_readme.md`.
- Evidence types used: live IDB health, function boundaries, raw bytes, instruction listing, Hex-Rays decompile, xrefs, vtable data refs, caller decompile/disassembly, callee list, generated artifacts, current by-* docs, and executed report history.
- Evidence ladder: current live MCP facts first; current by-* docs and generated artifacts second; old executed reports only as leads and historical implementation context; source-shape inference last.
- Confidence limiter: MCP cannot recover original source spelling or declarations, so final parameter type/name and whole-class header shape remain below final-audit certainty.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list`: active session `b001-0001I5`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `15332`.
  - `server_health`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
  - `lookup_funcs`: `0x00560900` is `sub_560900`, size `0xa1`; `0x005608fc`, `0x005609a1`, `0x005609b0`, and `0x005609e0` are not functions; positive controls `0x00560a10`, `0x00560b00`, `0x00560cf0`, `0x00560d00`, `0x00560d40`, and `0x00561420` are modeled functions.
  - `xrefs_to`: `0x00560900` has one code xref from `0x0056caae`; vtable bases `0x00623f1c`, `0x00623f68`, and `0x00623f98` have constructor data xrefs at `0x00560951`, `0x00560957`, and `0x00560961`.
  - `xref_query`: vtable bases also point to their table entries and have constructor data refs back to `sub_560900`.
  - `callees`: `0x00560900` calls `0x00544460` and `0x004b7c30`.
  - `decompile` / `analyze_function` / `disasm`: confirm base call, orientation byte store, field writes, vtable stores, point initializer call, and `retn 4`.
  - `get_bytes`: confirms predecessor and successor padding and the successor raw-setter start.
  - `insn_query`: exact `0x00560900-0x005609a1` range has 42 instructions, not truncated; `0x005609a1-0x005609b0` is an `align 10h` region.
  - `make_signature_for_range`: `format='ida'` and `format='mask'` both reported unique signatures for `0x00560900-0x005609a1`.
  - Caller evidence: bounded disassembly/decompile of `0x0056ca20` confirms allocation size `272`, call `sub_560900(v2, 0)` at `0x0056caae`, storage at `this[64]`, and `Show` call at `0x0056cac3`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target, `ScrollNewGroupPane.md`, `Group.md`, `ScrollNewGroupPaneCore.md`, `ScrollNewGroupPaneVtableData.md`, `ScrollNewGroupPaneVtables.md`, generated `Group.cpp`, generated tracker, generated memory coverage, executed B005 `0001GP`, B010 `00044Y`, B012 `00044Z`, B002 `0000JS`, and sibling ScrollNewGroupPane reports found by search.
- Search terms used: `TARGET-REPORT-UID:00044X`, `00044X`, `0x00560900`, `005609a1`, `ScrollNewGroupPaneConstructor`, `ScrollNewGroupPane::ScrollNewGroupPane`, `m_scrollSkinIndex`, `m_scrollStyleByte`, `ScrollNewGroupPane`, `NewGroupPane`, and `Group.cpp`.
- Negative checks performed: no direct UID00044X-specific executed report found; no function at post-target padding `0x005609a1`; no owner evidence stronger than class owner; no need for a new split or C++ rewrite found.
- Failed, unavailable, or intentionally skipped checks and why: one `func_profile` attempt with `queries=0x00560900` returned a broad first page rather than the target profile, so it was not used. One `make_signature_for_range` attempt with unsupported `format='hex'` failed with a format error; it was retried with supported `ida` and `mask` formats successfully. The earlier paused MCP state is historical only; current `server_health` after the failed signature-format call remained `ok`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00044X-01 | UID00044X remains exact modeled constructor range `0x00560900-0x005609a1`, `sub_560900`, size `0xa1` / 161 bytes. | High | MCP `lookup_funcs`, `decompile`, `insn_query`, `int_convert.py` | Target `Address Range And Boundary` / `Evidence` | incorporate | applied |
| C-00044X-02 | Predecessor `0x005608fc-0x00560900` is four `0xcc` bytes; successor `0x005609a1-0x005609b0` is fifteen `0xcc` bytes / `align 10h`. | High | MCP `get_bytes`, `insn_query`, `int_convert.py` | Target `Address Range And Boundary` | incorporate | applied |
| C-00044X-03 | Direct owner/emitter remain [UID:0000CL] `ScrollNewGroupPane`; source route remains [UID:0000JS] `Group` / `NexusTK/social/Group.cpp`. | High | Vtable installs, field offsets, support docs, generated `Group.cpp` | Target `Status`; support already present | incorporate | applied |
| C-00044X-04 | Direct caller is `NewGroupPane::NewGroupPane` at `0x0056caae`, which allocates 272 bytes, calls constructor with literal `0`, stores result at `this[64]`, and calls `Show`. | High | MCP caller disasm/decompile | Target `Evidence` / `Behavior` | incorporate | applied |
| C-00044X-05 | Three `ScrollNewGroupPane` vtable views are installed at `0x00560951`, `0x00560957`, and `0x00560961`. | High | MCP `decompile`, `disasm`, `xrefs_to`, support vtable docs | Target `Behavior` / `Evidence`; support already present | incorporate | applied |
| C-00044X-06 | Field writes support existing formal constructor C++ without behavior change. | High | MCP decompile/disasm: `+0xfc`, `+0xfe`, `+0xf8`, `+0x102`, `+0x104`, `+0x108` writes | Target `Behavior`; formal C++ block | incorporate | applied |
| C-00044X-07 | Current formal C++ should remain unchanged. | Medium-high | Binary facts match block; unresolved original parameter spelling only | Target formal C++ / Reconstruction Notes | already-present | already-present |
| C-00044X-08 | Score should move to `88/90`, not higher. | Medium-high | Current MCP proof, unique signature, remaining original-name/type uncertainty | Target metadata / Score rationale | incorporate | applied |
| C-00044X-09 | Support docs require no mandatory edit for this pass. | High | `ScrollNewGroupPane`, `Group`, core, vtable docs already record owner/source/field/vtable facts | Support docs | already-present | already-present |
| C-00044X-10 | Generated artifacts are read-only evidence and should refresh through scoped target validation after callback, not manual edits. | High | Workflow rules, current generated headers, target metadata recommendation | Report checklist / Validator Results | not-applicable | excluded-with-reason |

Callback ledger note: target `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md` now contains rows C-00044X-01 through C-00044X-08 at report-level detail. Support docs `by-class/ScrollNewGroupPane.md`, `by-file/Group.md`, `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`, `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md`, and `by-type/by-vtable/ScrollNewGroupPaneVtables.md` were checked and left unchanged because they already document the accepted owner/source/field/core/vtable facts at same-or-greater detail. Generated artifacts were not manually edited; scoped validation refreshed `auto-generated/NexusTK/social/Group.cpp`.

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation: live MCP reports a modeled function exactly at `0x00560900`, one direct caller from the `NewGroupPane` constructor, two constructor callees, three class-vtable installs, exact field writes for the formal C++ state, and byte-confirmed padding at both boundaries.
- Corroborating documentation/generated-report evidence: target/support docs already route UID00044X through [UID:0000CL] to [UID:0000JS] and generated `Group.cpp` emits the same constructor body.
- Strongest inference chain and why it is sufficient: constructor writes `ScrollNewGroupPane` vtables and class-local fields; its only direct caller allocates and stores a child scrollbar object under `NewGroupPane`; sibling class docs explain the field roles. This is enough to keep class ownership, source route, and first-draft C++.

## IDA MCP Facts

- Function/range facts: `sub_560900` starts at `0x00560900`, size `0xa1` / 161 bytes (Verified with int_convert.py). `0x005609a1` is not a function, and successor raw setter `0x005609b0` is not modeled as a function.
- Data/table/padding facts: bytes from `0x005608fc` begin `cc cc cc cc 55 8b ec...`; bytes from `0x005609a1` are fifteen `0xcc`; `0x005609b0` begins the raw setter bytes `55 8b ec 66 8b 45 08...`.
- Xref facts: `xrefs_to 0x00560900` has one code xref at `0x0056caae`; vtable bases have constructor data refs at `0x00560951`, `0x00560957`, and `0x00560961`.
- Vtable/global/type facts: decompile refs name `??_7ScrollNewGroupPane@@6B@`, `??_7ScrollNewGroupPane@@6B@_0`, and `??_7ScrollNewGroupPane@@6B@_1`; caller decompile names `??_7NewGroupPane@@6B@` for the owning pane constructor.
- Negative IDA facts: no modeled function starts at `0x005608fc`, `0x005609a1`, `0x005609b0`, or `0x005609e0`; no MCP fact proves the exact original constructor parameter spelling/type beyond a one-byte stored argument.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005608fc-0x00560900` | predecessor padding in [UID:0001GO] / boundary context | four `0xcc` bytes before constructor | false | none | n/a | keep as padding evidence |
| `0x00560900-0x005609a1` | [UID:00044X] `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md` | `ScrollNewGroupPane` constructor | true | [UID:0000CL] | current `86/89`, recommended `88/90` | target refresh recommended |
| `0x005609a1-0x005609b0` | padding in [UID:0001GP] | `align 10h`, fifteen `0xcc` bytes | false | none | n/a | keep as parent padding row |
| `0x005609b0-0x005609d7` | [UID:00044Y] `ScrollNewGroupPaneSkinIndexSetterRaw` | raw no-entry skin-index setter | true | [UID:0000CL] | `85/88` | unchanged sibling |
| `0x005609e0-0x00560a04` | [UID:00044Z] `ScrollNewGroupPaneStyleByteSetterRaw` | raw no-entry style-byte setter | true | [UID:0000CL] | `85/87` | unchanged sibling |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0056caae -> 0x00560900` | code xref/call from `sub_56CA20` | `NewGroupPane::NewGroupPane` constructs the scrollbar child. |
| `0x0056caaa` | `push 0` before constructor call | Constructor orientation argument is literal zero at the only direct caller. |
| `0x0056cabd` | caller stores constructor result in `this[64]` | `NewGroupPane` stores the child scrollbar pointer. |
| `0x0056cac3 -> 0x00560aa0` | immediate `Show` call | Caller enables/shows the constructed scrollbar. |
| `0x00560951 -> 0x00623f1c` | vtable data ref | Primary `ScrollNewGroupPane` view installed. |
| `0x00560957 -> 0x00623f68` | vtable data ref | Secondary `ScrollNewGroupPane` view installed. |
| `0x00560961 -> 0x00623f98` | vtable data ref | Tertiary `ScrollNewGroupPane` view installed. |
| `0x0056092b -> 0x00544460` | constructor callee | Pane base constructor/init call with argument `1`. |
| `0x00560985 -> 0x004b7c30` | constructor callee | Point pair initializer for `this + 0x108`. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: target page already documents owner/emitter route, parent split, vtable installs, field roles, and formal C++. `ScrollNewGroupPane.md` has the method row, field table, helper aliases, `NewGroupPane` caller path, and source route. `Group.md` has the `ScrollNewGroupPane` source route into `NexusTK/social/Group.cpp`. Vtable docs record the three constructor-installed bases.
- Existing docs that were stale, incomplete, or contradicted before callback: target evidence cited only B005 session `80de0a67`; it lacked the current `b001-0001I5` session, byte/signature/caller-argument details, and score rationale. Callback repaired the target page. No support-doc contradiction was found.
- Generated/coverage report state: generated `Group.cpp` refreshed after validation and final read-only check saw newer command `000000007639`, still emitting UID00044X at `88/90`; generated tracker and memory coverage are validator-owned and were not manually edited by B006.

## Ranked Ownership Analysis

### 1. [UID:0000CL] `ScrollNewGroupPane`

- Evidence for: constructor installs `ScrollNewGroupPane` vtables, writes class-local scroll fields, and is immediately used as a `NewGroupPane` scrollbar child. Support docs already map fields and vtables to this class.
- Evidence against: exact original class declaration is not fully audited, and some older generated/simroot leads polluted related helpers under `TextEditPane`.
- Decision: keep as direct owner and emitter. This is the narrowest true semantic owner and clears the current gate.

### 2. [UID:0000JS] `Group`

- Evidence for: source-file route owns the broader Group pane family and generated `NexusTK/social/Group.cpp` emits the constructor through the class route.
- Evidence against: by-structure says direct owner must be the narrowest semantic owner, not merely the source-file root. The constructor is a class method.
- Decision: keep only as source-file route through [UID:0000CL], not direct owner.

### 3. [UID:000090] `NewGroupPane`

- Evidence for: `NewGroupPane::NewGroupPane` allocates 272 bytes, calls this constructor with literal `0`, stores the result, and calls `Show`.
- Evidence against: caller containment does not make the callee a `NewGroupPane` method. The constructor installs `ScrollNewGroupPane` vtables and initializes `ScrollNewGroupPane` fields.
- Decision: reject as direct owner; use as caller/containment evidence.

### 4. Generic scrollbar / no-owner alternatives

- Evidence for: sibling generic scrollbar docs help field naming, especially skin/style byte patterns.
- Evidence against: target-local receiver, fields, vtables, and caller path are class-specific; no-owner/non-emitting would discard strong ownership and generated route evidence.
- Decision: reject.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable. No new source file or grouping is recommended.
- Likely full contents: source route stays with existing `NexusTK/social/Group.cpp` through `ScrollNewGroupPane`.
- Candidate related items that belong: existing ScrollNewGroupPane children already belong under the class route.
- Candidate related items rejected: none requiring a new route in this pass.
- Standalone, narrow, or broad source-file inference: narrow class-owned method inside existing Group source route.

## Source Placement

- Recommended source file/class/global/module placement: `ScrollNewGroupPane::ScrollNewGroupPane(bool horizontal)` under [UID:0000CL] `ScrollNewGroupPane`, emitted through [UID:0000JS] `Group` to `NexusTK/social/Group.cpp`.
- Why this placement fits source-tree and subsystem context: `NewGroupPane` constructs, stores, shows, and later uses this custom scrollbar in the Group UI family; `Group.md` already owns the feature file route.
- Rejected placements and why: direct `Group` ownership is too broad; direct `NewGroupPane` ownership confuses containment with method ownership; generic scrollbar ownership lacks target-local vtable/field evidence.
- Remaining placement uncertainty, if any: whole-class header/source split remains below final-audit certainty, but not enough to block target-level constructor source.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: target half-open range remains `0x00560900-0x005609a1`; size `0xa1` / 161 bytes (Verified with int_convert.py). Predecessor padding is four bytes; successor padding is `0x0f` / 15 bytes (Verified with int_convert.py).
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none. B005 already created exact core children.
- Padding/table/data/code distinctions: UID00044X contains one modeled function and associated EH code; `0x005609a1-0x005609b0` is alignment; `0x005609b0` starts sibling raw code.
- Parent/container impact: [UID:0001GP] remains a non-emitting split index. No parent reclassification is recommended.

## Negative Evidence Summary

- No UID00044X-specific executed report exists; B005 is parent/core implementation history, not direct report coverage.
- No function object begins at `0x005609a1`; bytes there are alignment, so the constructor range should not extend to `0x005609b0`.
- No direct owner candidate outranks [UID:0000CL]. `Group` is only file route, and `NewGroupPane` is the caller/container.
- No current evidence requires changing the formal C++ body. The remaining uncertainty is original source spelling/type, not behavior.
- No support doc was found that contradicts the target recommendation or needs mandatory repair.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments: keep `ScrollNewGroupPane::ScrollNewGroupPane(bool horizontal)`, `m_orientation`, `m_scrollSkinIndex`, `m_scrollStyleByte`, `m_thumbDragActive`, `m_scrollPosition`, `m_scrollRange`, `m_scrollEnabled`, `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, and `InitPointPair`.
- Evidence for each proposed name/type/comment: class support field table and live MCP writes to the matching offsets; caller passes literal `0`; sibling geometry supports nonzero horizontal and zero vertical; `sub_4B7C30` is already the project point-pair initializer alias.
- Items intentionally left unchanged and why: do not rename parameter to a raw `char` or `orientationByte` in formal C++ because current source-shape evidence and caller usage support a boolean-facing constructor parameter, while exact original spelling is not recoverable.
- Whether IDA DB edits are safe, unsafe, or not requested: no IDA DB rename/type/comment edits were requested or made in this callback.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, has a confirmed emitter route, clears the combined-score gate, and has exact current range/boundary/behavior evidence.
- Recommended code: keep the existing exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ScrollNewGroupPane::ScrollNewGroupPane(bool horizontal)
    : Pane(true)
{
    m_scrollSkinIndex = 0;
    m_scrollStyleByte = 1;
    m_thumbDragActive = false;
    m_orientation = horizontal ? 1 : 0;
    m_scrollPosition = 0;
    m_scrollRange = 0;
    m_scrollEnabled = true;
    m_highlightPart = kScrollNewGroupPartNone;
    m_activePart = kScrollNewGroupPartNone;
    InitPointPair(&m_thumbDragOffset, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: MCP decompile/disassembly maps each statement to constructor operations: base init argument `1`, orientation byte write at `+0xfc`, zero dword at `+0xfe`, packed dword `0x10000` at `+0xf8`, packed word `0xff01` at `+0x102`, active part `0xff` at `+0x104`, and point-pair init at `+0x108`.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: it is a normal class constructor with an initializer-list base call and member assignments, not decompiler-shaped pointer writes.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: all field names and `InitPointPair` are inferred from support docs and sibling usage, not original symbols.
- Naming/coding style convention used and evidence for consistency: `m_` class fields and `ScrollNewGroupPane` method names match current support docs and generated source output.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes applied or recommended: target-only doc refresh applied to UID00044X with current MCP session evidence, byte/signature/caller proof, and score rationale; metadata updated to `88/90`; formal C++ kept unchanged.
- Exact parent assignments applied or recommended: kept `CANONICAL_OWNER:0000CL`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:40`.
- Exact items left no-owner/non-emitting and why: none in this target. Adjacent padding remains non-source alignment in the parent split index.
- Exact future work, if any, outside this assignment scope: final whole-class declaration/header audit for `ScrollNewGroupPane` may later normalize `bool`/orientation spelling and `m_scrollSkinIndex` versus historical `m_scrollStyle` across sibling C++ blocks.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md`.
- Exact report facts incorporated: added current MCP session `b001-0001I5`, `server_health` OK, `lookup_funcs` size `0xa1` / 161 bytes, exact predecessor/successor padding, unique signature fact, direct caller/caller-argument proof, vtable xrefs, callees, and field-write mapping.
- Metadata/score/owner/emitter/reconstructable/C++ changes: changed score from `86/89` to `88/90`; kept owner/emitter/reconstructable/position/C++ unchanged.
- Historical/stale assumptions, rejected alternatives, and negative evidence preserved: preserved B005 session `80de0a67` as historical implementation evidence, but added current `b001-0001I5` as the live proof. Preserved rejected direct Group/NewGroupPane/generic scrollbar/no-owner alternatives and the unresolved exact original parameter spelling caveat.

## Recommended Support Doc Changes

- Support path: `by-class/ScrollNewGroupPane.md`.
- Exact report facts to incorporate: no required edit. Already records the UID00044X method row, field aliases, constructor/show caller path, vtable installs, and source route at same-or-greater support level.
- Metadata/link/score/coverage/source-placement changes: none.

- Support path: `by-file/Group.md`.
- Exact report facts to incorporate: no required edit. Already records the `ScrollNewGroupPane` source route through `NexusTK/social/Group.cpp`, exact core children including UID00044X, and the Group-pane file context.
- Metadata/link/score/coverage/source-placement changes: none.

- Support path: `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`.
- Exact report facts to incorporate: no required edit. Already treats UID00044X as exact constructor child and the parent as a non-emitting split index with padding rows.
- Metadata/link/score/coverage/source-placement changes: none.

- Support path: `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md` and `by-type/by-vtable/ScrollNewGroupPaneVtables.md`.
- Exact report facts to incorporate: no required edit. Already record the constructor stores for the three `ScrollNewGroupPane` vtable bases.
- Metadata/link/score/coverage/source-placement changes: none.

## Score And Metadata Recommendation

- Pre-callback score/metadata: `86/89`, owner/emitter [UID:0000CL], reconstructable `TRUE`, emitter position `40`, formal C++ populated.
- Post-callback score/metadata: `88/90`, same owner/emitter/reconstructable/position/C++.
- Score rationale and reason not higher/lower: raise completion because the target can now carry current UID-specific MCP evidence, exact bytes/padding, caller argument, and unique signature proof. Raise confidence modestly because live MCP confirms the old B005 facts and the current C++ behavior. Do not go higher because exact original parameter type/name, original helper names, and full class declaration/header shape remain inferred.
- Score-improvement attempt:
  - Current MCP freshness blocker: resolved by `b001-0001I5` evidence.
  - Range/padding blocker: resolved by `get_bytes` and `insn_query`.
  - Owner/emitter blocker: resolved in favor of existing class route by vtable installs and caller context.
  - C++ readiness blocker: resolved as already good; no body rewrite needed.
  - Original spelling/type blocker: evidence-backed unresolved; MCP cannot prove original source spelling, and caller only proves literal `0` at the one direct call.
- Metadata fields to change or leave unchanged: change only `COMPLETION` and `CONFIDENCE`; leave ownership, reconstructable, emitter route, position, item summary, and C++ block unchanged except for prose updates.

## Open Questions With Attempted Resolution

- Open questions found: exact original constructor parameter name/type; exact original helper/member spellings; whether support docs need a broader whole-class refresh; whether current generated output should be manually edited.
- Evidence checked for each: constructor decompile/disassembly, caller decompile/disassembly, class field table, sibling reports, generated `Group.cpp`, tracker/coverage rows, vtable docs, and by-structure rules.
- Best supported resolution or inference: keep `bool horizontal` as the source-facing parameter because the only caller passes `0`, `+0xfc` is a byte orientation field, and sibling geometry defines nonzero horizontal. Keep helper/member names as existing inferred support aliases. No support-doc edit is required.
- Questions remaining unresolved, exhaustive evidence proving why no defensible answer is safe now, score/C++ impact, and unavailable future evidence that would be required: original parameter spelling/type and original member/helper spellings remain unresolved because IDA has no original source symbols or declarations. This caps confidence at `90` but does not block current first-draft C++. Future evidence would need PDB/source artifacts, reliable original declaration metadata, or a whole-class final header audit that reconciles sibling C++ blocks.

## Follow-Up Actions

- Supervisor actions: verify callback incorporation claim-by-claim, then run the supervisor-owned report execution lifecycle only if Gate 2 passes.
- A-agent actions: none.
- B006 future research actions: none unless supervisor returns this report for callback repair.

## Confidence

- Recommendation confidence: high for target-only evidence/score refresh and unchanged owner/emitter/C++.
- Score confidence: medium-high for `88/90`; final-audit scores are not justified until original declaration/name uncertainty and whole-class header shape are resolved.
- Remaining uncertainty: exact original parameter type/name and exact original helper/member spellings.

## Validator Results

- Commands run during implementation callback:
  - `python .\tools\validator.py --mode file --file by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md --apply --queue-timeout 240`
- Results: exit code `0`; `command_id: 000000007628`; `command_timestamp: 2026-07-06T18:46:14-04:00`; scanned markdown files `1`; `ok: 1`; `completion_update: 1`; `confidence_update: 1`; `reference_index_add: 2`; `projected_stats_update: 1`; `stats_incremental_noop: 1`; `generated_refresh: deferred`; `generated_refresh_command_id: 000000007628`; `generated_refresh_timestamp: 2026-07-06T18:46:14-04:00`.
- Generated-output freshness: read-only header check after validation first showed `auto-generated/NexusTK/social/Group.cpp` refreshed to `validator-command-id: 000000007628`, `validator-refreshed-at: 2026-07-06T18:46:14-04:00`, with UID00044X emitted as `Completion:88 | Confidence:90`. A final read-only check saw a newer generated header, `validator-command-id: 000000007639`, `validator-refreshed-at: 2026-07-06T18:48:51-04:00`, `validator-refresh-source: foreground-generated-refresh`, still with UID00044X at `88/90`.
- Any unresolved validator warnings/errors: none target-specific. Validator reported `stats_incremental_noop` because UID00044X is not present in generated stats lists; generated `Group.cpp` is newer than the returned B006 scoped command metadata and still carries the accepted UID00044X score.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Not applicable. Generated tracker/coverage artifacts are validator-owned and must not be manually edited. No supervisor-owned manual coverage or tracker text is required for this implementation callback.

## Changed Files

- Modified by B006:
  - `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md`
  - `tools/leaser/Agents/Agent-B006/research/00044X-ScrollNewGroupPaneConstructor-source-quality.md`
- Checked and left unchanged as already-present support docs:
  - `by-class/ScrollNewGroupPane.md`
  - `by-file/Group.md`
  - `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`
  - `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md`
  - `by-type/by-vtable/ScrollNewGroupPaneVtables.md`
- Validator-owned side effects reported by scoped validation:
  - `auto-generated/NexusTK/social/Group.cpp` refreshed after the scoped validator and now has newer generated header `000000007639` / `2026-07-06T18:48:51-04:00`; UID00044X remains emitted as `88/90`.
  - Validator output reported completion/confidence metadata updates, two reference-index additions, and `project-level/-auto-completion-stats.md` projected stats update.
- Renamed: none.
- Report execution: not run. No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, generated edit, coverage edit, manual coverage edit, validator-state hand edit, supervisor-ledger edit, or unauthorized by-* edit was run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Callback received after Gate 1 pass for report SHA `2DEA36038D35F296ABB6BFD7ED2B28DEAF1F7AE42D54EFF91885D6753A05DE74`.
- [x] Target/support docs to update: target `by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md` updated; support docs `by-class/ScrollNewGroupPane.md`, `by-file/Group.md`, `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`, `by-memory/0x00623f18-0x00623fa0.ScrollNewGroupPaneVtableData.md`, and `by-type/by-vtable/ScrollNewGroupPaneVtables.md` checked and left unchanged as already-present.
- [x] Current target state and actual evidence checked recorded: target now records MCP session `b001-0001I5`, health, boundary, xref, callee, decompile/disasm, caller, bytes, padding, and signature facts.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows C-00044X-01 through C-00044X-10 updated to `applied`, `already-present`, or `excluded-with-reason`.
- [x] Metadata/score changes to apply: target `86/89` -> `88/90`; no owner/emitter/reconstructable/position change.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: current MCP freshness, range/padding, owner route, and C++ readiness resolved; exact original parameter/type spelling remains evidence-backed unresolved and caps score at `90`.
- [x] Owner/emitter/reconstructable changes to apply: none; explicitly preserved [UID:0000CL], `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, position `40`.
- [x] Split/rename/new-child changes to apply: none; exact child already exists and parent remains a non-emitting split index.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: kept `ScrollNewGroupPane -> Group.cpp`; no IDA DB edits; padding proof preserved.
- [x] First-draft C++ or no-code proof to apply: existing formal constructor C++ kept unchanged.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: current MCP session/provenance, exact function size, caller/callee/xref facts, vtable refs, field initialization map, byte/padding proof, unique signature proof, generated-state note, and rejected alternatives incorporated into target; support facts already present.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: B005 preserved as historical implementation evidence; stale generic/direct-file alternatives rejected; original parameter spelling/type uncertainty preserved as confidence cap.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: stale Wave3/simroot ownership pollution remains rejected in report; target page does not rely on it.
- [x] Open questions to close or document as evidence-backed unresolved: exact original parameter type/name and final class declaration/header shape remain unresolved with score impact; no "needs investigation" fallback.
- [x] Validators to run: scoped target validator run from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x00560900-0x005609a1.ScrollNewGroupPaneConstructor.md --apply --queue-timeout 240`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual generated/tracker edits. Generated `Group.cpp` caught up after validation and final read-only check showed newer header `000000007639` / `2026-07-06T18:48:51-04:00` with UID00044X still at `88/90`; no manual supervisor-owned coverage/tracker text needed.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: Gate 1 accepted; implementation callback received for UID00044X.
- [x] All accepted target/support doc details incorporated at report-level detail: target updated; support docs checked and left unchanged because they already carried accepted facts at same-or-greater detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C-00044X-01 through C-00044X-08 applied, C-00044X-09 already present, C-00044X-10 excluded with reason because generated artifacts are validator-owned.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target now `88/90`; owner/emitter/reconstructable/position unchanged; no split/rename/new child; formal C++ unchanged because binary facts already match.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: B005 historical session retained; direct Group, direct NewGroupPane, generic scrollbar, and no-owner alternatives rejected; original parameter spelling/type uncertainty preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: original parameter type/name, helper/member original spellings, and whole-class declaration/header remain unresolved confidence caps; no accepted item blocked.
- [x] Validators run and results recorded: scoped target validator returned command `000000007628`, timestamp `2026-07-06T18:46:14-04:00`, exit code `0`, `ok: 1`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: `auto-generated/NexusTK/social/Group.cpp` refreshed after validation and final read-only check showed newer header `000000007639` / `2026-07-06T18:48:51-04:00`; UID00044X remains emitted as `88/90`; no manual coverage/tracker text needed.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000007642","destination_path":"executed-b-agent-research/B006/00044X-ScrollNewGroupPaneConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00044X-ScrollNewGroupPaneConstructor-source-quality.md","timestamp":"2026-07-06T18:56:00-04:00","uid":"00044X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
