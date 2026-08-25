** TARGET-REPORT-UID:0003TC **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003TC MapPaneApplyHitBarObjectPane Ownership / Split Research


## Finalized Report / Current Recommendation

- Applied callback result: [UID:0003TC] is retained as the exact source-authored `MapPane` method child for `[0x0050e690,0x0050e805)`, with canonical owner/emitter [UID:00007Q][MapPane](by-class/MapPane.md), `RECONSTRUCTABLE:TRUE`, `Nested:0`, applied score `92/93`, deliberately blank `EMITTER_POSITION_OPTIONAL` for the established address-first MapPane child order, and Destination 1's complete formal body.
- Final disposition: the function is not dead code, compiler-only lowering, or a HitBarObjectPane method. It is a retained out-of-line MapPane helper whose complete policy is independently present inline inside [UID:0003TB] `MapPane::ProcessMapEvent`. The absence of an inbound route to the retained out-of-line copy caps liveness/name confidence but does not justify blank C++.
- Applied implementation: Destinations 1-14 and the complete current-reference synchronization bundle are present in the current ordinary pages. The emitted source preserves both percentage branches, unsigned-short truncation, absent divisor guards, percentage-before-null order, exact active/stale/create paths, pooled `new`/`delete` source shape, owner-slot synchronization, ObjectList remove/add order, shared `UpdatePosition` virtual dispatch, inherited GrafPort bounds copy, and final invalidation.
- Applied support correction: UID000161 is no longer accepted as `BackPane::GetBounds`. The UID-preserving page/path/name/owner/emitter correction now documents the common inherited `GrafPort::GetBounds` member over accepted GrafPort `m_visibleBounds` at `+0x44`; former BackPane assignment remains explicitly historical.
- Confidence: very high for binary behavior, range, owner, ABI parameter widths/order, fields, lifecycle, virtual slots, and source placement; high rather than final for exact stripped private method spelling and the retained out-of-line method's original inbound use.

## Supporting Research

- This is the first target-specific B report for UID0003TC. The tracker direct-report count is `0`; the executed UID0001AW continuation report created the child but did not resolve its blank C++, names, fields, liveness, or inherited bounds-helper ownership.
- Initial evidence collection used NexusTK IDA MCP database `2198f811` on 2026-07-15. That evidence-time worker later disappeared, and B002 paused report finalization after a fresh transport connection returned an empty `idb_list` and `Session not found: 2198f811` for both `server_health` and bounded `get_bytes`. These are historical incident facts, not present availability claims.
- After supervisor recovery, B002 established a new transport session and reran `idb_list` rather than substituting a session identifier into old prose. The fresh call returned exactly one active/adopted worker session, database `01f84d61`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `18448`, `is_analyzing:false`.
- Fresh `server_health(database=01f84d61)` returned `status:ok`, module `NexusTK.exe`, image base `0x00400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and cache size `2067`. A later health call after the full helper pass remained `status:ok` with the same module/path/readiness values.
- All MCP-dependent report facts were independently rerun on `01f84d61`: target/adjacent lookups, full target and padding bytes, target analysis/decompilation/CFG/callees/xrefs/constants/prototype, predecessor inline-twin decompilation, HitBar constructor/accessor/position helpers, vtable cells, ObjectList/pool/owner helpers, and `0x004b8e00` bytes/decompilation/xrefs. No conclusion below relies solely on dead database `2198f811` or stale database `46dda60b`.
- A read-only PE pass used the same binary named by server health, `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Evidence-time generated snapshots at validator command `000000012699`, refresh `2026-07-15T01:54:32-04:00`, showed UID0003TC as one MapPane empty-emitter marker, UID000161 as one BackPane definition, no HitBar class declaration, and no `UpdateHitBarBounds` token. These are read-only pre-callback observations, not present/future generated-state assertions.
- Active B001-B005 exact-target search found no competing UID0003TC report. At the recovery recheck, B001/B003/B004/B005 were in report-only/current-state repair modes; B005's UID00037V work references GrafPort support but does not own UID0003TC. `tools/leaser/lease.json` contained only a supervisor lease on B004's `goal.md` and no ordinary target/support lease.

### Current and historical report-root search

Exact terms searched together were `UID0003TC`, `0003TC`, `0x0050e690`, `0x50e690`, `MapPaneApplyHitBarObjectPane`, `ApplyHitBarObjectPane`, `HitBarObjectPane`, `UID0001AW`, `UID0003Z4`, `UID0000HJ`, `UID0001DF`, `0x004b8e00`, `BackPaneGetBounds`, and `GrafPortGetBounds`.

- Central executed root searched: `source-3/project-documentation/executed-b-agent-research`. Direct target terms matched only B001 `0001AW-mappane-packet-source-split-audit.md`, B001 `0001AW-mappane-packet-source-split-continuation-batch2.md`, B001 continuation batches 3/4, B001 `0001DF-attached-object-detach-registry-source-shape.md`, B001 `0003Z4-LivingObjectPaneLinkedObjectSetupHelpers-source-quality.md`, and B009 `0000HJ-AttachedObjectPane-empty-emitter-family-source-quality.md`. Family-term searches additionally found the expected current MapPane, ObjectList, GrafPort, BackPane, and attached-overlay reports listed under Evidence Checked.
- Legacy executed root searched: `source-3/project-documentation/archived/b-agent-reports-20260623`, including its `Agent-B001` through `Agent-B015/research/executed` subtrees. No direct or family-term match for the exact search set was returned.
- Archived loose root searched: `source-3/project-documentation/archived/duplicate-loose-b-agent-reports`. No direct or family-term match was returned.
- Active roots searched independently: `tools/leaser/Agents/Agent-B001/research`, `Agent-B002/research`, `Agent-B003/research`, `Agent-B004/research`, and `Agent-B005/research`. No direct UID/address/name target report matched. Broad `HitBarObjectPane`/GrafPort terms appeared only as support in active B001 UID0003U6, B004 UID0003U7, and B005 UID00037V work; none owns or proposes edits to UID0003TC.
- The former B003 UID000161 report is central executed at `executed-b-agent-research/B003/000161-BackPaneGetBounds-source-quality.md`. It is useful historical evidence for bytes, ABI, and 103 callers, but its BackPane ownership inference is superseded because it rejected a common base owner from documentation/caller style and did not account for the direct HitBarObjectPane receiver at `0x0050e7d7`.

## Target

- Target UID: `0003TC`.
- Target path: `by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` line observed at evidence time as `86/88`, reconstructable `true`, direct report count `0`; this is an evidence-time snapshot rather than a current tracker assertion.
- Supervisor classification at research time: report-only source-quality research, first exact target report. Supervisor Gate 1 accepted exact report SHA `21496FF8274FA2841A642DA069D604D71F716DCD8C671863525FDD81576A28DD` at `2026-07-15T02:54:00-04:00`, after which the bounded callback was applied.
- Applied scores and parent state: target `92/93`; owner/emitter [UID:00007Q] MapPane; file source root [UID:0000L3] MapPane; broad parent [UID:0001AW] remains a `86`-completion non-emitting packet-handler split index.
- Exact target range: `[0x0050e690,0x0050e805)`, `0x175` / 373 bytes.

## Current Target State

- Evidence-time / pre-callback metadata was `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++, blank Item Summary, `Nested:0`.
- Applied target metadata is `COMPLETION:92`, `CONFIDENCE:93`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, complete Destination 1 formal C++, complete Item Summary, and `Nested:0`.
- Applied owner/emitter/reconstructable state retains MapPane semantic ownership and emission. Final waited validator command `000000012755` emits exactly one UID0003TC definition in MapPane.cpp and zero UID0003TC Empty Emitter Markers.
- Evidence-time open questions/blockers were no inbound xref, descriptive method name, raw target-object pointer, `+0x1dc` field, active/update/remove/register/bounds helper names, pool/new/delete source shape, return type, source order, and compiler-vs-source disposition. The applied target page now records every resolution and preserves no-caller status only as a confidence cap.
- Superseded assumptions remain historical: `0x004b8e00` as BackPane-owned; `UpdateHitBarBounds` as the accepted final virtual spelling; complexity/no caller as grounds for blank C++; IDA's incidental `unsigned int` return as a likely source return.
- Target/support readback covered all fourteen destinations, verify-only MapPoint/LivingObjectPane/ObjectList/pool/vtable pages, all current ordinary references that used the stale BackPane accessor spelling, generated MapPane/AttachedObjectPane/GrafPort/BackPane output, and all affected manual coverage roots. Current ordinary links no longer use the old UID000161 path; manual coverage and historical reports remain supervisor-owned/read-only.
- B002 callback state: all accepted ordinary edits, scoped validators, final waited generated verification, report reconciliation, and lease releases are complete. Current/future report path, count, execution, movement, archive, registry, and manual-coverage application are external supervisor/validator-owned and are not asserted.

## Executive Recommendation

- Keep UID0003TC as one exact method. No split is needed: all 373 bytes are one coherent thiscall with two percentage diamonds, one target-null branch, active/stale/create branches, one compiler EH state around pooled construction, and a shared epilogue.
- Use `void MapPane::ApplyHitBarObjectPane(...)` as the highest-probability source shape. IDA's unsigned return is residue: different exits retain unrelated percentage/callee results, no caller consumes a result, and the inline twin in UID0003TB is modeled `void`.
- Use `LivingObjectPane *objectPane` and two `unsigned int` current/maximum pairs. The direct `+0x1dc` access is accepted `HitBarObjectPane *m_hitBarObjectPane`; MapPane friendship already authorizes access.
- Use `HitBarObjectPane::SetValues`, `IsActive`, and shared virtual `UpdatePosition`. The final no-argument AttachedObjectPane slot is pure in the base and overridden by HitBar, DamageNumber, and ObjectInfo position/bounds methods.
- Correct UID000161 to `GrafPort::GetBounds`: the exact body copies accepted `GrafPort::m_visibleBounds` at `+0x44`; it is called on both BackPane and HitBar-derived receivers. BackPane consumes the inherited method and must not redeclare it.
- Preserve pool mechanics as compiler/inlined allocation lowering of ordinary source `new`/`delete`. UID0002WP remains the sole file-local pool definition and is already stronger at `88/93`.
- Do not add by-file reconstruction metadata. File pages receive source placement/history prose only.

## Supervisor Active Recheck

- The supervisor assigned UID0003TC after the previous UID00031G lifecycle completed. After the first evidence worker disappeared, the supervisor restored MCP on database `01f84d61` and required a new evidence pass; the report now records the rerun results rather than relabeling old-session observations.
- The assigned item did not require a range split. It required a source-quality and integration repair before the exact method could emit.
- Every source-bearing item in scope has an implementation-ready destination: UID0003TC body; UID000067 class declaration; UID00000M shared virtual declaration; UID000161 UID-preserving correction/body; UID00000S declaration cleanup; and prose/history synchronization across MapPane, AttachedObjectPane, GrafPort, BackPane, PaneLayout, ObjectOverlayPanes, and DamageNumberObjectPane.
- Verify-only dependencies already at same-or-greater detail remain unchanged unless callback reread proves concrete drift.

## Inference Research Guidance Check

- `by-structure.md` separates semantic ownership from emission. UID0003TC remains semantically owned and emitted by MapPane; HitBarObjectPane is the constructed object owner, not the method owner.
- `EMITTER_POSITION_OPTIONAL` was rechecked. A numeric target position would sort UID0003TC ahead of all no-position MapPane children. Blank position is therefore the deliberate stable choice; first-seen address-path order already places UID0003TB, UID0003TC, and UID0003TD correctly.
- Direct IDA facts, documentation evidence, and inference are separated below. Stripped source names are presented as highest-probability descriptive names, not original-symbol proof.
- Existing documentation assumptions treated as uncertain were caller-biased BackPane ownership, the `UpdateHitBarBounds` lexical alias, IDA return type, no-caller liveness, and raw pooled-allocation source shape.
- Wave2/Wave3 references were found in older BackPane/Pane documentation and old reports. They were ignored as stale authority; only live MCP, current by-* docs, current binary bytes, and non-Wave current report evidence are used.

## Heuristic / Inference Reanalysis And Validation

### Function identity and liveness

- Direct fact: IDA models one function `sub_50E690`, size `0x175`, with 19 basic blocks, cyclomatic complexity 5, 146 instructions, no strings, no inbound xrefs, and ten direct named callee starts plus virtual calls.
- Direct negative fact: IDA `xrefs_to`/callers are empty. A read-only `.text` scan found zero `E8`/`E9` rel32 transfers to `0x0050e690`, zero little-endian absolute VA hits, zero target-RVA hits, and one unique 16-byte prologue at raw offset `0x10da90`.
- Resolution: the predecessor UID0003TB contains the same full percentage/update/stale-delete/create/register/position/bounds/invalidate sequence inline and is explicitly `void`. The out-of-line body is a retained source-authored helper copy, plausibly emitted for a private member defined out of line while the visible call site was inlined. No-caller status caps liveness confidence but does not make coherent source code compiler-only.
- Rejected: dead/garbage function. It has an ordinary thiscall frame, exact five-argument `ret 0x14`, coherent class fields/callees, a unique body, valid EH lowering, and an independently inlined twin.
- Rejected: compiler-generated outline. The source policy, parameter ABI, object-lifecycle operations, and named class calls are developer logic; only EH/cookie/new/delete mechanics are compiler lowering.

### ABI, return type, and parameters

- Direct fact: `ECX` is MapPane; `ret 0x14` proves five explicit 32-bit stack arguments.
- Direct fact: argument 1 is dereferenced as a LivingObjectPane/ObjectPane-derived receiver and its `+0x1dc` typed HitBar field. Arguments 2-5 are unsigned arithmetic inputs.
- Resolution: source return is `void`. Null exit leaves secondary-percentage residue, active exit leaves `SetValues` residue, and create exit leaves invalidation residue. No stable semantic return exists. UID0003TB's inline twin is explicitly `void`.
- Resolution: neutral names `primaryValue`, `primaryMaximum`, `secondaryValue`, `secondaryMaximum` preserve exact behavior without overclaiming HP/MP semantics. Hit bars can represent primary/secondary values; health/mana spellings are plausible but not binary-proven.

### Exact percentage arithmetic

- For each pair, if current value is below `10000000` (`0x989680`), source computes `current * 100 / maximum`.
- Otherwise source computes `current / (maximum / 100)` to avoid overflowing the multiplication.
- `0x51EB851F` and shift 5 are compiler strength reduction for division by 100; they are not source constants.
- The result is truncated to 16 bits before use. There is no clamp to `0..100`, no saturating conversion, no maximum-zero guard, and no guard for `maximum / 100 == 0` in the large-current branch.
- Both percentages are computed before checking `objectPane` for null. Destination 1 preserves this observable fault/order behavior.

### Object, fields, and helper identities

- `objectPane` is `LivingObjectPane *`: UID0003XP returns its `MapPoint`, UID0004QM stores its HitBar pointer, and UID0003Z4 proves `HitBarObjectPane *m_hitBarObjectPane` at complete-object `+0x1dc`.
- `MapPoint` UID0004R0 is exactly two ints, `row` then `column`. UID0003XP returns `m_mapY` into row and `m_mapX` into column. The constructor receives row then column, matching the accepted `mapY`, `mapX` constructor order.
- MapPane `+0x424` is accepted `ObjectList *m_objectList`.
- `0x00531c10` and `0x005314a0` are accepted `ObjectList::RemoveObjectPane` and `AddObjectPane`; no invented local list helper is needed.
- `0x0053ae70` is exact `LivingObjectPane::SetHitBarObjectPane`; it is one pointer store with no delete/equality logic.

### Active, stale, and create paths

- Existing non-null HitBar path calls `IsActive`; only value `1` takes the update return. Destination 1 retains an explicit equality to true.
- Active path calls `SetValues(primaryPercent,100,secondaryPercent,100)` and returns. `SetValues` stores four unsigned shorts only when the active byte is set and invalidates with a null rectangle. Its source return is void; decompiler EAX is residue.
- Stale path first removes the old HitBar from MapPane's ObjectList and then source-deletes it. The deleting destructor/pool return and AttachedObjectPane owner-unregister behavior are generated from `delete`; no manual pool free, owner clear, scalar-delete flag, or vptr work belongs in UID0003TC.
- Create path uses ordinary `new HitBarObjectPane(...)`. Machine calls to `PoolAllocator::Allocate`, the conditional constructor call, EH state, and constructor-failure pool free are compiler/inlined class-allocation lowering. There is no source-visible null guard after `new`.
- Creation order is exact: construct; store owner slot through `SetHitBarObjectPane`; register in `m_objectList`; virtual `UpdatePosition`; inherited `GetBounds`; virtual `InvalidateRect`.

### HitBar layout and common virtual

- AttachedObjectPane base size is `0x12c`.
- HitBar fields are unsigned shorts at `+0x12c/+0x12e`, style byte at `+0x130`, active bool at `+0x131`, unsigned shorts at `+0x132/+0x134`, and two implicit tail bytes to exact size `0x138`.
- Style constructor initializes primary pair, style, and inactive state. Dual constructor initializes both pairs and writes word `0x0101` over style/active, proving style 1 plus active true.
- AttachedObjectPane primary vtable cells at `0x006205b4`/`0x006205b8` are `0x00538600` then `0x005ca28c` (`__purecall`). HitBar corresponding cells at `0x006207a4`/`0x006207a8` are `0x00538600` then `0x00538ec0`; DamageNumber uses `0x00539400`; ObjectInfo uses `0x00539700`.
- The final no-argument slot therefore has one shared source contract. `UpdatePosition` is strongest because ObjectInfo already uses that name and every override recalculates owner-relative screen bounds before calling `SetBounds`.
- `UpdateHitBarBounds` and `ComputeDisplayBounds` remain useful historical/descriptive aliases for HitBar and DamageNumber bodies, but they are superseded as accepted source-facing override spellings.

### Bounds accessor ownership correction

- `0x004b8e00` is an exact 17-byte thiscall leaf that copies 16 bytes from receiver `+0x44` to one caller output and returns that output pointer.
- Current GrafPort docs identify `+0x44..+0x50` as `RectBounds m_visibleBounds`; `0x004b8e00` lies inside the GrafPort method island, not the BackPane constructor/paint island.
- UID0003TC directly calls the helper with a `HitBarObjectPane *`. HitBar derives through AttachedObjectPane -> ObjectPane -> Pane -> GrafPort and is not a BackPane.
- BackPane and HitBar share GrafPort ancestry. The 103-call broad UI/map/render fan-in is therefore evidence for a common inherited GrafPort accessor, not a root BackPane convenience member.
- Rejected: retain BackPane owner and add a separate HitBar declaration. One body/address and broad unrelated receivers do not support two source declarations; duplicate declarations would be source-invalid.
- Rejected: Pane owner. Pane is also common ancestry, but the field is accepted GrafPort state, the function lies in the GrafPort island, and non-Pane GrafPort consumers are present in the 103-call family.
- Rejected: free helper. The receiver is in `ECX` and `ret 4` cleans one explicit output argument, which is ordinary member-function ABI.

### Source placement and compiler exclusions

- UID0003TC belongs in `NexusTK/map/MapPane.cpp` as a private MapPane method definition; its declaration belongs in the complete MapPane header union.
- HitBarObjectPane and AttachedObjectPane declarations belong to the AttachedObjectPane header/source family. The complete class blocks provide source-safe field/virtual contracts and stable order before class-owned children.
- UID000161 belongs in `NexusTK/render/GrafPort.cpp`; the corresponding inherited member declaration belongs in the complete GrafPort header union. The broad GrafPort class formal remains blank rather than emitting a lossy partial class shell; Destination 4 is the exact definition owner.
- Compiler-only exclusions: SEH registration, cookie setup/check, EH state variable, constructor-failure pool free, scalar deleting destructor call shape, vptr writes, RTTI/vtables, magic division constants, and raw PoolAllocator calls.

## Evidence Standards Used

- Highest tier: live IDA MCP modeled boundaries, bytes, decompilation, disassembly-derived vtable cells, xrefs/callers/callees, CFG, constants, and class receiver/field behavior.
- Corroborating hard evidence: exact PE hash/section mapping, target-range SHA256, direct rel32/absolute/RVA/prefix scans, current formal by-* declarations, and exact generated readback.
- Documentation evidence: current by-memory/by-class/by-file/by-type pages and current executed reports, used as leads and revalidated against binary behavior.
- Inference: stripped private method/local names, primary/secondary semantics, `UpdatePosition` shared spelling, and original source header organization. Each inference is constrained by ABI, field offsets, sibling naming, and era-appropriate C++.
- Negative evidence is not treated as ownership proof by itself. Zero callers cap liveness; broad callers do not prove BackPane ownership; address adjacency does not override receiver/class state.
- Confidence is held below final because no original symbol or source header survives for the private method and because no inbound route to the retained out-of-line copy was recovered.

## Evidence Checked

### IDA MCP/manual-disassembly/raw-byte checks performed

- Fresh `idb_list`, `server_health`, `lookup_funcs`, bounded `get_bytes`, `analyze_batch`, `analyze_function`, `decompile`, `basic_blocks`, `callees`, `xrefs_to`, and `find_bytes` calls against recovered database `01f84d61`.
- Target start/end/successor lookups; complete 373-byte target read; target first/last bytes; predecessor/successor padding; target CFG/prototype/constants/callees/strings/xrefs; unique prologue and target-pointer byte searches.
- Fresh decompiles for `0x0050e4c0`, `0x0050e690`, `0x00538d50`, `0x00538dc0`, `0x00538e60`, `0x00538eb0`, `0x00538ec0`, `0x00539400`, `0x00539700`, `0x005374d0`, `0x0053ae70`, and `0x004b8e00`; fresh compact analysis for ObjectList add/remove, the pool allocator, attached-position support, and owner-bounds support.
- Vtable-cell bytes at `0x006205b4`, `0x006207a4`, `0x00620858`, and `0x0062090c`, proving the common final AttachedObjectPane virtual slot.
- Current executable PE SHA, `.text` RVA/raw mapping, target exact-range SHA, rel32/pointer/RVA negative scans, and unique first-16-byte prefix.

### by-* docs, support docs, old reports, generated reports, and trackers checked

- Target UID0003TC; parent UID0001AW; siblings UID0003TB/UID0003TD; MapPane class/file.
- HitBar UID000067; mixed aggregate UID0001DB; vtable UID000353; pool UID0002WP; resource UID0002YR; AttachedObjectPane UID00000M/class/file/core/vtable; DamageNumber and ObjectInfo sibling classes/vtables.
- LivingObjectPane UID00007B; getter UID0003XP; setter UID0004QM; unregister/cleanup UID0001DF/UID0004QH; MapPoint UID0004R0.
- ObjectList class and exact add/remove dispatch children UID0002C9/UID0002CA.
- UID000161, BackPane class/file/paint/help callers, GrafPort class/file/core, PaneLayout, RectBoundsLayout, and all ordinary current references containing the stale BackPane accessor spelling.
- Tracker exact row, generated MapPane/AttachedObjectPane/GrafPort/BackPane files, and manual `by-memory`, `by-class`, `by-file`, and `by-type` coverage roots.
- Central executed reports opened/classified: B001 UID0001AW audit and continuation batches 2-4; B001 UID0001DF; B001 UID0003Z4; B009 UID0000HJ; B010 UID0001D8; B003 UID000161; B002 UID0002BB; B005 UID00037X; other family matches were searched but opened only when they contained target/helper evidence.

### Negative checks performed

- No inbound IDA xref/caller to UID0003TC start; no raw rel32 call/jump; no absolute VA/RVA pointer encoding; no string; no vtable/table entry to the target.
- No split boundary inside the target; exact padding before and after; no overlap with predecessor/successor.
- No source evidence for health/mana-specific parameter names, return value, divisor checks, clamp, new failure branch, owner nulling before stale delete, manual pool API, or duplicate bounds helper.
- No active B001-B005 exact target report and no evidence-time lease.
- No direct target/family search result in legacy executed or duplicate-loose archived roots.

### Failed, unavailable, or intentionally skipped checks and why

- During report-only evidence collection, no IDA mutation, rename, type application, or comment write was attempted; the evidence pass was read-only. The later callback also did not mutate IDA.
- During report-only evidence collection, no implementation validator or generator refresh was run. The accepted callback later ran only the scoped ordinary validators and final authorized waited target refresh recorded below; no report lifecycle command, registry/count/probe, move, archive, or execute command was run in either phase.
- Original symbols/source/PDB are unavailable; lexical confidence is therefore inferred, not claimed as original proof.
- A broad `.text` `insn_query` for direct `call 0x0050e690` exceeded the tool's 60-second internal limit, including two narrower half-range retries. The worker remained healthy, and this incomplete route is not used as evidence. Fresh all-database `xrefs_to` returned zero, fresh `find_bytes` returned one unique 16-byte target prologue and zero absolute-VA/RVA encodings, and the exact read-only PE scan returned zero `E8`/`E9` rel32 destinations to the target; together those completed bounded routes establish the same negative result without a fallback-only conclusion.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0003TC is exactly `[0x0050e690,0x0050e805)`, 373 bytes, target SHA256 `1E1A016D5EB8642081823AE3A1D378F3DCBD7291519FECA4D3B8A73B17941C0B`. | Very high | MCP lookup/bytes; PE hash | Destination 1 target Range/IDA evidence | incorporate | applied |
| C02 | Three preceding and eleven following bytes are `cc`; predecessor and successor begin/end exactly as documented. | Very high | MCP bounded bytes/lookups | Destination 1; UID0001AW support | incorporate | applied |
| C03 | One source method accounts for all blocks; no internal split is justified. | Very high | 19-block CFG, unified EH/epilogue | Destination 1 Range/CFG | incorporate | applied |
| C04 | Source signature is void MapPane member plus LivingObjectPane pointer and four unsigned 32-bit values. | High | ret 0x14, field/callee use, residue exits, void twin | Destination 1 formal/body; MapPane support | reject-stale | applied |
| C05 | No inbound route exists in IDA/raw PE, but the retained out-of-line source method remains valid. | High | xrefs and byte scans; unique coherent body | Destination 1 liveness/negative evidence | reject-invalid | applied |
| C06 | UID0003TB contains the full logic inline and establishes source-authored/void disposition. | Very high | fresh decompile 0x0050e4c0 | Destination 1; UID0003TB verify-only support | incorporate | applied |
| C07 | Primary percentage uses exact threshold/overflow-avoidance branches and ushort truncation. | Very high | target decompile/constants/disassembly | Destination 1 formal/behavior | incorporate | applied |
| C08 | Secondary percentage independently uses the same exact branches and truncation. | Very high | target decompile/constants/disassembly | Destination 1 formal/behavior | incorporate | applied |
| C09 | No divisor guards/clamp exist; both percentages precede object null check. | Very high | CFG and instruction order | Destination 1 formal/negative evidence | incorporate | applied |
| C10 | `+0x1dc` is typed `HitBarObjectPane *m_hitBarObjectPane`; MapPane friendship permits direct read. | Very high | UID0003Z4, UID0004QM, callers | Destination 1; LivingObjectPane verify-only | already-present | already-present |
| C11 | Existing active HitBar calls SetValues with both maxima fixed at 100 and returns. | Very high | calls 0x538eb0/0x538e60 | Destinations 1, 2, 7 | incorporate | applied |
| C12 | Existing inactive HitBar is removed from ObjectList then source-deleted before replacement. | Very high | instruction/callee order | Destination 1; MapPane/Attached support | incorporate | applied |
| C13 | Creation is ordinary pooled-class `new`; allocation/EH/free mechanics are compiler lowering. | Very high | pool xrefs, constructor, unwind, scalar destructor | Destinations 1, 2, 8 | reject-invalid | applied |
| C14 | Constructor args are owner, map row, map column, primary percent/100, secondary percent/100. | Very high | UID0003XP/MapPoint and ctor decompile | Destinations 1, 2 | incorporate | applied |
| C15 | Create order is setter, ObjectList add, UpdatePosition, GetBounds, InvalidateRect. | Very high | exact call/virtual sequence | Destination 1 formal/behavior | incorporate | applied |
| C16 | UID0003TC remains owned/emitted by UID00007Q with blank position and Nested 0. | Very high | receiver/source family/generator ordering | Destinations 1, 6, 9 | already-present | already-present |
| C17 | HitBar exact size is 0x138 with six explicit fields and two implicit tail bytes. | Very high | constructors/accessors/pool size | Destination 2; Destinations 7-8 | incorporate | applied |
| C18 | HitBar class needs two constructors, destructor, SetValues, IsActive, three overrides, size guard, and child insertion point. | High | vtables/functions/layout | Destination 2 formal block | incorporate | applied |
| C19 | AttachedObjectPane's final pure no-arg virtual is best named UpdatePosition. | High | four aligned vtable cells and sibling bodies | Destination 3 formal; Destinations 7-8 | incorporate | applied |
| C20 | UpdateHitBarBounds/ComputeDisplayBounds are superseded descriptive aliases, not concurrent accepted names. | High | shared vtable contract | Destinations 2, 7, 8, 14 | historicalize | applied |
| C21 | UID000161 is GrafPort::GetBounds over m_visibleBounds, not BackPane::GetBounds. | Very high | HitBar receiver, GrafPort field/island, ABI, 103 callers | Destination 4 formal; Destinations 10-14 | reject-stale | applied |
| C22 | UID000161 is UID-preserving renamed/rerouted to GrafPort and raised to 92/94. | Very high | exact body/owner correction | Destination 4 metadata/path | incorporate | applied |
| C23 | BackPane consumes inherited GetBounds and must remove its duplicate member declaration while preserving all other class content. | Very high | common ancestry and direct callers | Destination 5 formal; Destinations 12-13 | reject-invalid | applied |
| C24 | GrafPort class/file need the exact inherited accessor contract and source placement, while broad class formal remains blank to avoid a lossy partial shell. | High | current GrafPort layout/source policy | Destinations 10-11 | incorporate | applied |
| C25 | PaneLayout +0x44 is inherited GrafPort m_visibleBounds and UID000161 is its accessor, not a BackPane-specific consumer. | Very high | current field evidence and receiver set | Destination 14 PaneLayout | reject-stale | applied |
| C26 | All current ordinary references to the old UID000161 path/name require collision-safe UID-preserving link/prose synchronization; historical reports remain historical. | Very high | 21-file exact search | Destination 14 synchronization bundle | incorporate | applied |
| C27 | Pool UID0002WP, vtable UID000353, MapPoint, LivingObjectPane setter/layout, and ObjectList add/remove are same-or-greater verify-only dependencies. | Very high | current formal docs and current readback | Recommended Support Doc Changes / Verify-only dependencies | already-present | already-present |
| C28 | Applied scores are target 92/93, HitBar 90/93, AttachedObjectPane 90/93, and UID000161 92/94; other destination scores remain as listed. | High | blocker closure and bounded lexical caps | Score/metadata; Destinations 1-14 | incorporate | applied |
| C29 | Exact manual by-memory/by-class/by-file/by-type rows are absent or stale and require supervisor-owned text below. | Very high | direct read-only row comparison | Exact Manual Supervisor-Owned Coverage Or Tracker Text | incorporate | excluded-with-reason |
| C30 | Callback verification requires one scoped validator per changed ordinary page, one final waited target refresh, exact generated counts/routes/order, no duplicate target or stale BackPane definition, and no handwritten ABI/pool/vtable glue. | Very high | workflow and expected emitter routes | Validator plan/checklist | incorporate | applied |

Callback destination proof for C01-C30: C01-C09 and C11-C15 are present in Destination 1 and target SHA `81E90B6D1C510C857C31B8F9AD212A3E06E6075F8AD8958EF882B3CD32A61494`; C10, C16, and C27 survived readback unchanged as same-or-greater dependencies; C17-C20 are present in HitBar/Attached class and file destinations; C21-C26 are present in UID000161, GrafPort, BackPane, PaneLayout, and every listed current ordinary reference; C28 is present in all scored destination metadata; C29 is deliberately excluded because manual coverage remains supervisor-owned and the exact handoff text below was preserved without editing coverage; C30 is proved by scoped commands `000000012712` through `000000012754` as listed under Validator Results plus final waited command `000000012755` and its generated readback.

## Positive Evidence Summary

- Exact modeled function and padding boundaries; exact target SHA and unique prefix.
- Coherent MapPane receiver, ObjectList field, LivingObjectPane field, MapPoint, HitBar methods, pool, constructor, setter, and virtual call chain.
- Complete inlined twin in UID0003TB proves retained source logic and void disposition.
- Exact HitBar fields/size are triangulated by constructors, accessors, render helpers, pool size, and vtable.
- Shared vtable slot proves `UpdatePosition`; sibling ObjectInfo already supplies the strongest source-facing spelling.
- HitBar receiver at `0x0050e7d7` decisively invalidates BackPane ownership of UID000161; GrafPort field/island and 103 callers positively support the corrected common base.
- Current support docs already provide source-ready MapPoint, LivingObjectPane setter/layout, ObjectList add/remove, pool declaration, and vtable covered marker.

## IDA MCP Facts

- Recovery pass: every fact in this section was reproduced on recovered database `01f84d61`; the former `2198f811` session is historical incident context only.

- Function/range facts: `lookup_funcs(0x0050e690)` -> `sub_50E690`, size `0x175`; `0x0050e805` not a function; `0x0050e810` -> `sub_50E810`, size `0x38`.
- Target first 16 bytes: `55 8B EC 6A FF 68 6E 29 60 00 64 A1 00 00 00 00`.
- Target last 16 bytes: `8B 4D F0 33 CD E8 30 8F 0B 00 8B E5 5D C2 14 00`.
- Data/table/padding facts: `[0x0050e68d,0x0050e690)` is three `cc`; `[0x0050e805,0x0050e810)` is eleven `cc`.
- CFG facts: 19 blocks, complexity 5, 146 instructions; two percentage diamonds, null branch, active/stale/create branches, EH metadata, one epilogue.
- Prototype lead: IDA displays `unsigned int __thiscall(_DWORD **this,_DWORD *,unsigned int,unsigned int,unsigned int,unsigned int)`; report corrects only source types/return based on data flow.
- Direct callees: `0x005374d0`, `0x00538eb0`, `0x00538e60`, `0x00531c10`, `0x00538dc0`, `0x0053ae70`, `0x005314a0`, `0x004b8e00`, `0x004b1400`, and cookie support; virtual scalar-delete/UpdatePosition/InvalidateRect are additionally present.
- Constants: `10000000`, `100`, `0x51EB851F`, shift 5, active value 1, pool address `0x0069b934`, EH sentinel values, and `ret 0x14`.
- Xref facts: zero inbound target xrefs/callers; UID0003TB inline twin calls the same HitBar constructor/SetValues/IsActive/setter/add/remove/bounds chain.
- Vtable facts: final AttachedObjectPane slot is pure at base cell `0x006205b8`, HitBar `0x00538ec0`, DamageNumber `0x00539400`, ObjectInfo `0x00539700`.
- Global/type facts: pool `0x0069b934`, HitBar size `0x138`, LivingObjectPane HitBar pointer `+0x1dc`, MapPane ObjectList pointer `+0x424`, GrafPort visible bounds `+0x44`.
- Negative IDA facts: no target strings, no inbound direct/data refs, no target pointer route, no internal split, no separate active/new failure behavior.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0050e4c0-0x0050e68d` | UID0003TB MapPaneProcessMapEvent | Caller-context method with inline twin | TRUE | UID00007Q | `86/89` | verify-only; body/name outside this target |
| `0x0050e68d-0x0050e690` | UID0000VN ignored | alignment | FALSE | none | `100` | exact three `cc` |
| `0x0050e690-0x0050e805` | UID0003TC target | retained MapPane method | TRUE | UID00007Q | `92/93` | Destination 1 applied |
| `0x0050e805-0x0050e810` | UID0000VN ignored | alignment | FALSE | none | `100` | exact eleven `cc` |
| `0x0050e810-0x0050e848` | UID0003TD | linked-overlay activation sibling | TRUE | UID00007Q | `86/90` | verify-only |
| `0x00538d50-0x00538dbb` | UID0001DB inventory / UID000067 class | style HitBar constructor | TRUE through class | UID000067 | class `90/93` | Destination 2 applied declaration/support |
| `0x00538dc0-0x00538e3a` | same | dual HitBar constructor | TRUE through class | UID000067 | same | Destination 2 declaration/support |
| `0x00538e40-0x00538e5f` | same | constructor unwind | compiler-only | UID000067 | n/a | no handwritten body |
| `0x00538e60-0x00538ea3` | same | SetValues | TRUE through class | UID000067 | same | Destination 2 declaration/support |
| `0x00538eb0-0x00538eb7` | same | IsActive | TRUE through class | UID000067 | same | Destination 2 declaration/support |
| `0x00538ec0-0x00538f81` | same | UpdatePosition override | TRUE through class | UID000067 | same | corrected name |
| `0x00538f90-0x00539021` | same | ClearOutputRects override | TRUE through class | UID000067 | same | historical GetBarRectOffsets alias |
| `0x00539030-0x0053922b` | same | RenderFrame override | TRUE through class | UID000067 | same | historical RenderHitBar alias |
| `0x004b8e00-0x004b8e11` | UID000161 GrafPortGetBounds | inherited bounds accessor | TRUE | UID00005V | `92/94` | Destination 4 UID-preserving correction applied |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| UID0003TC start | zero IDA callers/xrefs; zero raw rel32/VA/RVA routes | retained out-of-line method, liveness cap |
| `0x0050e4c0` | inline twin | proves complete source policy and void use |
| `0x0050e728` | `LivingObjectPane::GetMapPosition` | row/column constructor inputs |
| `0x0050e72d` | direct `objectPane+0x1dc` | accepted HitBar pointer |
| `0x0050e74b` | `HitBarObjectPane::IsActive` | equality-to-1 active gate |
| `0x0050e75c` | `HitBarObjectPane::SetValues` | active update and return |
| `0x0050e76b` | `ObjectList::RemoveObjectPane` | stale removal before delete |
| `0x0050e776` | scalar deleting destructor dispatch | source `delete` lowering |
| `0x0050e77d` | pool allocate | source `new` lowering |
| `0x0050e7a6` | dual HitBar constructor | exact owner/map/value args |
| `0x0050e7b6` | `SetHitBarObjectPane` | owner-slot store |
| `0x0050e7c5` | `ObjectList::AddObjectPane` | MapPane registration |
| `0x0050e7ce` | vtable `+0x70` -> `0x00538ec0` | shared UpdatePosition override |
| `0x0050e7d7` | direct `0x004b8e00` on HitBar receiver | decisive GrafPort GetBounds evidence |
| `0x0050e7e4` | vtable `+0x20` | ObjectPane::InvalidateRect |
| `0x00538dc0` | exactly calls from UID0003TB and UID0003TC | dual constructor is specific to these paths |
| `0x00538e60` | exactly calls from UID0003TB and UID0003TC | exact SetValues pair |
| `0x00538eb0` | calls from UID0003TB, UID0003TC, UID0003TD | active predicate family |
| `0x004b8e00` | 103 direct callers | common inherited GrafPort bounds accessor |

## Documentation Evidence And IDA Status

- Current UID0003Z4/LivingObjectPane docs already resolve `m_hitBarObjectPane`, setter type, MapPane friendship, exact cleanup, and unregister semantics. They are current and verify-only.
- Current UID0002BB/ObjectList docs resolve AddObjectPane/RemoveObjectPane signatures and type dispatch. They are current and verify-only.
- Evidence-time UID0000HJ support resolved HitBar pool/vtable/resource handling but left the class declaration blank. Applied HitBar/Attached destinations close the field/helper/class blocker without altering already-accepted pool/vtable bodies.
- Evidence-time UID0001AW/UID0003TC docs established range/owner/basic behavior but used blank-C++/no-caller deferral. UID0003TC now has complete formal source and evidence; UID0001AW remains a non-emitting split index.
- Evidence-time UID000161/BackPane/PaneLayout docs and executed B003 report assigned semantic ownership to BackPane. Their byte/ABI/caller facts remain valid historical evidence; current ordinary UID000161/GrafPort/BackPane/PaneLayout pages apply the GrafPort owner/name/path/class correction.
- Current GrafPort docs call `+0x44..+0x50` `m_visibleBounds`, and current UID000161 emits its exact accessor through GrafPort. This is same-or-greater field evidence for the corrected accessor.
- Evidence-time generated MapPane had one UID0003TC Empty Emitter Marker, BackPane had one UID000161 definition, and GrafPort had none. Final waited command `000000012755` now produces one UID0003TC definition with zero target empty markers, one UID000161 GrafPort definition, and zero UID000161 BackPane definitions.

## Ranked Ownership Analysis

### 1. UID00007Q MapPane for UID0003TC

- Evidence for: thiscall receiver; direct `m_objectList` use; MapPane packet/event address island; MapPane friendship into LivingObjectPane; inline twin in MapPane::ProcessMapEvent; registration/invalidation policy.
- Evidence against: no inbound route to retained out-of-line copy; private original name stripped.
- Decision: retain canonical owner/emitter. Negative liveness affects confidence, not semantic ownership or emission.

### 2. UID000067 HitBarObjectPane

- Evidence for: constructed object; methods, pool, vtable, fields, and render policy are HitBar-owned.
- Evidence against: target `this` is MapPane and target chooses when to update/remove/create/register the overlay.
- Decision: support/dependency owner only, not UID0003TC owner.

### 3. UID00000M AttachedObjectPane / UID0000HJ source family

- Evidence for: supplies owner link, common virtual, unregister lifecycle, and HitBar source module.
- Evidence against: does not own MapPane policy or ObjectList registration decision.
- Decision: support class/file; receives shared virtual and class declaration synchronization only.

### 4. UID00005V GrafPort for UID000161

- Evidence for: exact `m_visibleBounds` field, code-island location, thiscall ABI, common ancestry of BackPane and HitBar, and broad receiver/caller family.
- Evidence against: original member symbol is stripped and the broad GrafPort formal class remains intentionally blank.
- Decision: accepted UID000161 canonical owner/emitter and source module; stronger than BackPane/Pane/free-helper alternatives.

### Proposed new file/grouping, if applicable

- No new file or grouping is needed.
- UID0003TC stays in existing MapPane.cpp; HitBar/Attached declarations stay in AttachedObjectPane source family; UID000161 moves to existing GrafPort.cpp.
- No candidate related item is orphaned. Pool/vtable/resource children remain with HitBar; BackPane keeps its own constructor/paint/help methods and consumes inherited bounds access.

## Source Placement

- UID0003TC: private MapPane declaration in the complete MapPane header union and exact definition in `NexusTK/map/MapPane.cpp` through UID00007Q/UID0000L3.
- UID000067 and UID00000M: class declarations in the AttachedObjectPane header/source family, ordered AttachedObjectPane position 10 then HitBarObjectPane position 20. Class-owned children remain under `[[CHILDREN]]` insertion points.
- UID000161: inherited GrafPort declaration in the complete GrafPort header union and exact definition in `NexusTK/render/GrafPort.cpp` through UID00005V/UID0000JR.
- BackPane: no own GetBounds declaration or definition; OnPaint/help paths use the inherited GrafPort member.
- Rejected source placements: HitBar-owned UID0003TC; AttachedObjectPane-owned UID0003TC; BackPane-owned UID000161; Pane-owned UID000161; free helper; duplicated folded member definitions.
- Remaining placement uncertainty: exact header filenames are not proven. Existing project routes are strong enough for class/file ownership and emitter selection.

## Range / Split / Padding / Reclassification Analysis

- Exact target boundaries are unchanged; no child split or merge.
- Predecessor UID0003TB ends at `0x0050e68d`; three `cc` bytes separate it from target.
- Target ends at `0x0050e805`; eleven `cc` bytes separate it from UID0003TD.
- Target SEH/cookie instructions are part of compiler lowering inside the method range and are not separate source children.
- UID000161 range remains exact while its source-facing path/title/owner/emitter are UID-preserving corrected.
- UID0001DB remains a non-emitting mixed physical inventory; its HitBar rows/names/layout are synchronized, but no monolithic body or owner is introduced.
- `Nested:0` remains correct for target and UID000161. Target blank position is intentional address-order behavior; Attached/HitBar class positions 10/20 establish declaration order before no-position source children.

## Negative Evidence Summary

- No target caller, pointer, string, table, RTTI, or vtable entry was recovered.
- No stable return value exists; IDA's return type is rejected.
- No source-level safety checks exist for zero maxima, percentage range, object state, ObjectList pointer, allocation result, or null HitBar after allocation.
- No evidence supports health/mana-specific argument names.
- No evidence supports manually calling PoolAllocator, pool free, scalar destructor, vptr stores, owner clear, or EH cleanup in source.
- Broad calls to UID000161 do not prove BackPane ownership. The decisive typed HitBar receiver disproves it.
- Address adjacency to BackPane call sites, old docs, and an executed report are not stronger than common-base receiver/field evidence.
- `UpdateHitBarBounds`, `GetBarRectOffsets`, `RenderHitBar`, and `ComputeDisplayBounds` are useful descriptive labels but cannot override common base virtual signatures when source declarations are reconstructed.

## IDA Rename / Type / Comment Recommendations

- IDA DB edits are not requested and are outside report-only scope.
- Source-facing target name: `MapPane::ApplyHitBarObjectPane`; high descriptive confidence, not original-symbol proof.
- Source-facing parameters: LivingObjectPane target plus primary/secondary unsigned value/maximum pairs.
- Source-facing HitBar names: `SetValues`, `IsActive`, `UpdatePosition`, inherited `GetBounds`, and `InvalidateRect`.
- Source-facing field names: `m_hitBarObjectPane`, `m_objectList`, HitBar primary/secondary values/maxima, `m_style`, `m_active`, and GrafPort `m_visibleBounds`.
- UID000161 source-facing rename: `GrafPortGetBounds` page/title and `GrafPort::GetBounds` definition.
- Historical aliases retained explicitly: `UpdateHitBarBounds`, `GetBarRectOffsets`, `RenderHitBar`, `ComputeDisplayBounds`, and `BackPaneGetBounds`.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Five exact managed destination blocks follow. They are the only C++ draft/example text in this report.

### Destination 1 - UID0003TC target exact block

Destination path: `by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md`.

```cpp
*** UID:0003TC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MapPane::ApplyHitBarObjectPane(
    LivingObjectPane *objectPane,
    unsigned int primaryValue,
    unsigned int primaryMaximum,
    unsigned int secondaryValue,
    unsigned int secondaryMaximum)
{
    unsigned short primaryPercent;
    if (primaryValue < 10000000)
        primaryPercent = static_cast<unsigned short>(
            primaryValue * 100 / primaryMaximum);
    else
        primaryPercent = static_cast<unsigned short>(
            primaryValue / (primaryMaximum / 100));

    unsigned short secondaryPercent;
    if (secondaryValue < 10000000)
        secondaryPercent = static_cast<unsigned short>(
            secondaryValue * 100 / secondaryMaximum);
    else
        secondaryPercent = static_cast<unsigned short>(
            secondaryValue / (secondaryMaximum / 100));

    if (!objectPane)
        return;

    MapPoint mapPosition;
    objectPane->GetMapPosition(&mapPosition);

    HitBarObjectPane *hitBarObjectPane = objectPane->m_hitBarObjectPane;
    if (hitBarObjectPane)
    {
        if (hitBarObjectPane->IsActive() == true)
        {
            hitBarObjectPane->SetValues(
                primaryPercent,
                100,
                secondaryPercent,
                100);
            return;
        }

        m_objectList->RemoveObjectPane(hitBarObjectPane);
        delete hitBarObjectPane;
    }

    hitBarObjectPane = new HitBarObjectPane(
        objectPane,
        mapPosition.row,
        mapPosition.column,
        primaryPercent,
        100,
        secondaryPercent,
        100);
    objectPane->SetHitBarObjectPane(hitBarObjectPane);
    m_objectList->AddObjectPane(hitBarObjectPane);
    hitBarObjectPane->UpdatePosition();

    RectBounds bounds;
    hitBarObjectPane->GetBounds(&bounds);
    hitBarObjectPane->InvalidateRect(&bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact retained MapPane helper that computes two overflow-avoiding unsigned-short percentages, updates an active attached HitBarObjectPane or removes/deletes/recreates/registers/positions/invalidates it, with a complete source body and no recovered inbound route to the out-of-line copy. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 2 - UID000067 complete HitBarObjectPane class block

Destination path: `by-class/HitBarObjectPane.md`.

```cpp
*** UID:000067 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class HitBarObjectPane : public AttachedObjectPane
{
public:
    HitBarObjectPane(
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX,
        unsigned short primaryValue,
        unsigned short primaryMaximum,
        unsigned char style);
    HitBarObjectPane(
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX,
        unsigned short primaryValue,
        unsigned short primaryMaximum,
        unsigned short secondaryValue,
        unsigned short secondaryMaximum);
    virtual ~HitBarObjectPane();

    void SetValues(
        unsigned short primaryValue,
        unsigned short primaryMaximum,
        unsigned short secondaryValue,
        unsigned short secondaryMaximum);
    bool IsActive() const;

    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);
    virtual void UpdatePosition();

private:
    unsigned short m_primaryValue;       // 0x12c
    unsigned short m_primaryMaximum;     // 0x12e
    unsigned char m_style;               // 0x130
    bool m_active;                       // 0x131
    unsigned short m_secondaryValue;     // 0x132
    unsigned short m_secondaryMaximum;   // 0x134
};

typedef char HitBarObjectPaneSizeMustBe312[
    sizeof(HitBarObjectPane) == 0x138 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID00000M complete AttachedObjectPane block

Destination path: `by-class/AttachedObjectPane.md`.

```cpp
*** UID:00000M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class LivingObjectPane;

class AttachedObjectPane : public ObjectPane
{
public:
    AttachedObjectPane(
        unsigned char objectType,
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX);
    virtual ~AttachedObjectPane();

    LivingObjectPane *GetLivingObjectPane() const;
    int GetLivingObjectId() const;
    void SetLivingObjectPane(LivingObjectPane *pane);

    virtual void SetSpriteAttribute(unsigned char value);
    virtual void UpdatePosition() = 0;

private:
    LivingObjectPane *m_livingObjectPane; // 0x128
};

typedef char AttachedObjectPaneSizeMustBe300[
    sizeof(AttachedObjectPane) == 0x12c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - UID000161 UID-preserving GrafPort correction

Destination path after accepted rename: `by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md`.

```cpp
*** UID:000161 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RectBounds *GrafPort::GetBounds(RectBounds *outBounds) const
{
    *outBounds = m_visibleBounds;
    return outBounds;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact inherited GrafPort bounds accessor that copies m_visibleBounds at +0x44 to a caller RectBounds and returns the output pointer; broad direct-call fan-in and a HitBarObjectPane receiver reject the historical BackPane owner. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 5 - UID00000S BackPane class block without duplicate GetBounds

Destination path: `by-class/BackPane.md`.

```cpp
*** UID:00000S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BackPane : public Pane
{
public:
    explicit BackPane(const wchar_t *frameResourceName);
    virtual ~BackPane();

    virtual bool OnActivate(int activateCode);
    virtual void OnPaint();

    void ShowHelpFromPacket(const unsigned char *packet);
    void ShowHelpFromPacketV2(const unsigned char *packet);
    void ShowHelpFromPacketV3(const unsigned char *packet);

private:
    EPFTileContext m_frameTileContext;
    int m_frameWidth;
    int m_frameHeight;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason Destination 1 preserves exact behavior: every arithmetic branch, truncation, fault ordering, object branch, call order, and absent check matches the binary and inline twin. Source-level `new`/`delete` regenerate pool/EH/scalar mechanics through the existing class support.
- Reason the class blocks are source-safe: exact base sizes, fields, common virtual slot, override surface, size guards, and child insertion points are reconciled; no raw vtable/pool ABI is handwritten.
- Reason the code matches plausible original era source: ordinary private member methods, raw pointers, simple conditionals, output parameters, class-specific object lifetime, and explicit integer arithmetic fit the surrounding Visual C++ source shape.
- Naming convention: established project `m_` members, PascalCase methods/classes, lower-camel locals/parameters, and exact current type names.
- No code remains blank for the target or the two direct class blockers. Broad MapPane/GrafPort class pages remain blank because replacing their full established unions with target-only class shells would lose unrelated methods/layout; exact child definitions remain the valid emitters.

## Final Recommendation

- Destination 1 is applied exactly and only the target score was raised as specified.
- Destinations 2-3 are applied exactly, resolving HitBar fields/methods and the common AttachedObjectPane virtual while preserving pool/vtable/resource children unchanged.
- UID000161 was UID-preserving renamed/rerouted with Destination 4 and every current ordinary link was propagated; B003 byte/ABI/caller research remains historical and is superseded only on owner/name/path.
- Destination 5 is applied exactly, so BackPane inherits rather than duplicates the GrafPort member.
- MapPane class/file, AttachedObjectPane file/aggregate, DamageNumber terminology, GrafPort class/file, BackPane file/callers, PaneLayout, and the complete current-reference bundle are synchronized at report-level detail.
- UID0001AW remains non-emitting and verify-only; no second target child, HitBar method child, pool child, vtable child, or duplicate report was created.
- No report lifecycle, manual coverage edit, IDA mutation, or generated-file manual edit belongs to B002.

## Recommended Target Doc Changes

- Applied target path: `by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md`.
- Metadata, Item Summary, and formal block exactly match Destination 1; owner/emitter/reconstructable/range/Nested and historical B001/UID0003Z4 provenance are preserved.
- Current target evidence includes exact target SHA/bytes, 19-block CFG/complexity/instruction count, direct callees/virtual calls, no-string/no-route evidence, raw scan, inlined twin, complete arithmetic, branch/lifecycle/call order, ABI/return decision, source placement, compiler exclusions, rejected alternatives, score rationale, and confidence cap.
- Stale blank-C++/future-investigation wording is retained only as labeled evidence-time history; current wording is source-ready and callback-complete.

## Recommended Support Doc Changes

### Destination 2 - `by-class/HitBarObjectPane.md`

- Applied exact class block, `90/93`, position 20, complete layout/size/implicit tail, constructor modes, SetValues/IsActive, UpdatePosition/ClearOutputRects/RenderFrame overrides, target caller pair, pool/lifetime behavior, compiler exclusions, and historical aliases.

### Destination 3 - `by-class/AttachedObjectPane.md`

- Applied exact full block, `90/93`, position 10, and common pure `UpdatePosition` slot proof. Accessors, `+0x128`, size, unrelated position-helper caveats, and child insertion point are preserved.

### Destination 4 - UID000161 by-memory page

- Applied UID-preserving rename from `BackPaneGetBounds` to `GrafPortGetBounds`; owner/emitter are rerouted `00000S -> 00005V`; score is `92/94`; exact body, range/bytes/padding/103-call/no-pointer evidence, and historical B003 provenance are present at `by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md`. The old ordinary path is absent.

### Destination 5 - `by-class/BackPane.md`

- Applied Destination 5 managed class block; own GetBounds inventory/ownership claims are removed, constructor/destructor/activate/paint/help fields/methods and score are retained, and current OnPaint/help callers use the inherited GrafPort accessor.

### Destination 6 - `by-class/MapPane.md`

- Retained `89/89` and blank broad formal; added target method inventory, exact body/fields/lifecycle/source ordering, blank-position rationale, compiler exclusions, route-negative retained-method explanation, and declaration/header requirement matching Destination 1.

### Destination 7 - `by-file/MapPane.md`

- Retained `89/85`; added `MapPane.cpp` target source placement, complete behavior, dependencies, source order between UID0003TB/UID0003TD, and no duplicate body/by-file metadata.

### Destination 8 - `by-file/AttachedObjectPane.md`

- Retained `86/86`; added complete HitBar class/layout/helper/virtual/pool route and historical alias corrections, class positions 10/20, and compiler exclusions.

### Destination 9 - `by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md`

- Retained `86/91`, NONE/FALSE/blank; renamed HitBar rows to SetValues/IsActive/UpdatePosition/ClearOutputRects/RenderFrame, added exact fields/size/common slot, and kept the physical mixed-owner/no-monolithic-C++ disposition.

### Destination 10 - `by-class/DamageNumberObjectPane.md`

- Retained `86/90` and blank formal; identified `0x00539400` as its shared `UpdatePosition` override while preserving `ComputeDisplayBounds` as a historical descriptive alias and all unrelated field/render blockers.

### Destination 11 - `by-class/GrafPort.md`

- Retained `88/90` and blank broad formal; added UID000161 as the exact inherited `GetBounds` definition over `m_visibleBounds`, exact member declaration/header contract matching Destination 4, HitBar/BackPane receiver proof, BackPane/Pane/free-helper rejection, and historical correction.

### Destination 12 - `by-file/GrafPort.md`

- Retained `89/88`; added UID000161 to GrafPort.cpp inventory/source placement without adding by-file reconstruction metadata.

### Destination 13 - `by-file/BackPane.md`

- Retained `89/91`; removed UID000161 as a BackPane-owned definition, recorded inherited use in paint/help methods, and preserved all true BackPane family content and B003 historical classification.

### Destination 14 - PaneLayout and current-reference synchronization bundle

- `by-type/by-struct/PaneLayout.md` retains `85/88`; `+0x44` now names inherited GrafPort `m_visibleBounds` and UID000161 GrafPort accessor, with BackPane-specific phrasing historicalized.
- The following current ordinary references were reread, synchronized, scoped-validated, and released under short individual callback leases: `by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md`, `0x004806d0-0x00480739.BackPaneViewportRectHelper.md`, `0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md`, `0x00495aa0-0x00495be3.TextButtonExControlPaneLabelBoundsRawHelpers.md`, `0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md`, `0x004b0490-0x004b086b.ExchangeAlertPaneCore.md`, `0x004b67b0-0x004b68ab.FpsPaneOnPaint.md`, `0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md`, `0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md`, `0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md`, `0x00504110-0x00504521.MapPaneInitialize.md`, `0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md`, `0x005380b0-0x005387a3.AttachedObjectPane.md`, `0x005c2230-0x005c299f.SwallowLayerPaneCore.md`, and `by-file/SwallowLayerPane.md`.
- Each listed ordinary page kept its score/owner/body unless its current statement explicitly assigned UID000161 to BackPane; only links/current source-facing owner/name prose changed. `by-memory/-report.old.md`, manual coverage, executed reports, and archived reports remain historical/read-only and were not callback edit destinations.

### Verify-only dependencies

- UID0003TB/UID0003TD; UID0004R0 MapPoint; UID0003XP GetMapPosition; UID00007B LivingObjectPane; UID0004QM setter; UID0004QH cleanup; UID0001DF unregister; UID00009Q ObjectList; UID0002C9 AddObjectPane; UID0002CA RemoveObjectPane; UID0002WP pool; UID000353 vtable; UID0002YR resource; RectBoundsLayout; ObjectPane class.
- Callback reread found no concrete contradiction in these pages. They remain unchanged at same-or-greater detail rather than being rewritten for stylistic consistency.

## Score And Metadata Recommendation

- UID0003TC evidence-time/applied: `86/88 -> 92/93`, same owner/emitter UID00007Q, true, blank position, Nested 0, complete formal C++ and Item Summary.
- UID000067 evidence-time/applied: `85/89 -> 90/93`, same owner/emitter UID0000HJ, true, position `20`, complete class block.
- UID00000M evidence-time/applied: `88/91 -> 90/93`, same owner/emitter UID0000HJ, true, position `10`, complete block with final pure virtual.
- UID000161 evidence-time/applied: `87/91 -> 92/94`, owner/emitter `00000S -> 00005V`, true, blank position, Nested 0, UID-preserving path/name correction and complete formal body.
- UID00000S remains `88/91`; UID00005V remains `88/90`; UID0001DB remains `86/91` NONE/FALSE; UID00003F remains `86/90`; file roots and MapPane class retain current scores.
- Reason not higher: original private target spelling/header and inbound retained-copy route are absent; HitBar original field/method lexical spellings and some unrelated render details remain inferred; broad class/file pages retain unrelated blockers.
- Score-improvement attempt: every current target blocker was checked. Caller liveness was exhausted through IDA and raw PE; return/type/name/field/helper/pool/virtual/bounds/source-order/compiler distinctions were resolved; broad class no-loss constraints were handled with exact child definitions rather than partial shells.

## Open Questions With Attempted Resolution

- Original target name: searched IDA names/strings/xrefs, source-family docs, current/archived reports, and siblings. No symbol survives. `ApplyHitBarObjectPane` is the strongest descriptive private-member spelling and caps confidence only.
- Inbound retained-copy route: exhausted IDA caller/xref, rel32 E8/E9, absolute VA, RVA, table/vtable, and prefix scans. None exists. Inline twin proves source liveness; no caller is left as an evidence-backed lexical/liveness cap, not a C++ blocker.
- Return type: resolved to void from incompatible exit residues, no consumers, and void twin.
- Parameter semantics: exact unsigned widths/order resolved; primary/secondary names chosen because health/mana-specific semantics are not proven.
- `+0x1dc`: resolved to typed HitBar pointer from UID0003Z4/setter/unregister/callers.
- Virtual `0x00538ec0`: resolved to shared `UpdatePosition` from aligned pure/derived vtable slots and ObjectInfo naming.
- `0x004b8e00` owner: resolved to GrafPort from typed HitBar receiver, common inheritance, exact field, island, and broad callers.
- Pool behavior: resolved as ordinary `new`/`delete` source with class-local pool lowering; no handwritten allocator mechanics.
- Emitter order: target blank position is intentionally correct; Attached/HitBar class positions 10/20 resolve declaration order.
- No investigable target blocker remains. Remaining uncertainties affect only lexical/source-header confidence, not behavior, formal body, ownership, or implementation readiness.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Read-only comparison inspected `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/-coverage-report.md`.
- Manual coverage is supervisor-owned. B002 must not apply any row below; validator-generated coverage does not satisfy these replacements/additions.

### `by-memory/-coverage-report.md`

Placement: insert the following four rows immediately after the UID0001AW parent row and before the current UID0001AX row; if supervisor first restores missing earlier address-order children, retain exact address order.

```text
        - [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) 0x0050e690-0x0050e805 | class method | MapPaneApplyHitBarObjectPane : reconstructable : 92% : very-strong : Exact retained MapPane helper with complete source body; computes two overflow-avoiding unsigned-short percentages before the target null check, updates an active HitBarObjectPane, or removes/deletes/recreates/registers/positions/invalidates it through typed LivingObjectPane, ObjectList, HitBar, MapPoint, pool, inherited GrafPort bounds, and ObjectPane invalidation routes. Owner/emitter [UID:00007Q] MapPane; no recovered inbound route to the unique out-of-line copy caps confidence without making it compiler-only.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050e805-0x0050e810 | padding | MapPaneApplyHitBarObjectPane to MapPaneActivateLinkedObjectById alignment : ignored : 100% : strong : Eleven exact 0xcc bytes after UID0003TC end-exclusive 0x0050e805 and before UID0003TD begins at 0x0050e810.
        - [UID:0003TD][0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md) 0x0050e810-0x0050e848 | class method | MapPaneActivateLinkedObjectById : reconstructable : 86% : strong : Exact retained MapPane object-id lookup helper with three direct callers; reads the typed HitBarObjectPane slot at LivingObjectPane +0x1dc, requires active value 1, and dispatches the linked-overlay activation/removal callback. Owner/emitter [UID:00007Q] MapPane; unchanged verify-only sibling of UID0003TC.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0050e848-0x0050e850 | padding | MapPaneActivateLinkedObjectById to next MapPane helper alignment : ignored : 100% : strong : Eight exact 0xcc bytes after UID0003TD end-exclusive 0x0050e848 and before the next modeled MapPane helper begins at 0x0050e850.
```

Placement: replace existing UID000161 line 1507 with:

```text
    - [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md) 0x004b8e00-0x004b8e11 | method/accessor | GrafPortGetBounds : reconstructable : 92% : very-strong : Exact 17-byte inherited GrafPort::GetBounds leaf copying m_visibleBounds at +0x44 to a caller RectBounds and returning the output pointer; no callees, exact padding, 103 direct calls, and no pointer/table route. Direct use on HitBarObjectPane plus broad BackPane/UI/map/render receivers rejects the historical BackPane owner; owner/emitter [UID:00005V] GrafPort with complete formal body.
```

Placement: replace existing UID0001DB line 2490 with:

```text
    - [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md) 0x00538bc0-0x00539bb2 | mixed-class-cluster | ObjectOverlayPanes : not_reconstructable : 86% : very-strong : Non-emitting mixed BowGauge/attached-overlay physical inventory with 27 modeled starts and exact padding. HitBar rows resolve dual/style constructors, SetValues, IsActive, shared UpdatePosition, ClearOutputRects, RenderFrame, exact 0x138 layout, pool/vtable/resource support, MapPane callers, and compiler-only unwind/deleting/vtable mechanics; per-class children own source.
```

### `by-class/-coverage-report.md`

Replace the existing rows for UID00000M, UID00000S, UID00003F, UID00005V, UID000067, and UID00007Q with:

```text
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) : reconstructable : 90% : very-strong : Complete source-legal 0x12c ObjectPane-derived declaration with constructor/destructor, typed LivingObjectPane owner accessors and +0x128 field, SetSpriteAttribute, the binary-proven final pure virtual UpdatePosition contract, size guard, child insertion point, stable position 10, and retained unrelated attached-position caveats.
- [UID:00000S][BackPane](by-class/BackPane.md) : reconstructable : 88% : very-strong : Root backdrop class with exact constructor/destructor/activation/paint/help surface and frame fields; BackPane paint/help code consumes inherited GrafPort::GetBounds, while historical BackPane ownership of UID000161 is rejected and removed from the formal declaration.
- [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md) : reconstructable : 86% : very-strong : Attached combat-number overlay with exact constructor/animation/UpdatePosition/packed-copy/render/destructor anchors, pool/vtable/resource support, and compiler exclusions; historical ComputeDisplayBounds is retained as a descriptive alias for the shared final AttachedObjectPane UpdatePosition override.
- [UID:00005V][GrafPort](by-class/GrafPort.md) : reconstructable : 88% : very-strong : Core graphics-port class with exact surface/clip/draw/text children and inherited UID000161 GrafPort::GetBounds over m_visibleBounds at +0x44; direct HitBarObjectPane and broad BackPane/UI/map/render receivers reject the historical BackPane owner while the broad class formal remains blank to avoid a lossy partial shell.
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) : reconstructable : 90% : very-strong : Complete source-legal 0x138 AttachedObjectPane-derived declaration with two constructors, SetValues, IsActive, UpdatePosition/ClearOutputRects/RenderFrame overrides, exact primary/style/active/secondary fields and implicit tail padding, size guard, stable position 20, pool/vtable/resource children, MapPane lifecycle callers, and compiler ABI exclusions.
- [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 89% : very-strong : Live game-world pane class with child-only source emission; UID0003TC now supplies complete ApplyHitBarObjectPane source with exact percentage, typed owner-slot, ObjectList, pooled lifecycle, shared UpdatePosition, inherited GrafPort bounds, invalidation, route-negative retained-method, and compiler-exclusion evidence while the broad class formal remains blank.
```

### `by-file/-coverage-report.md`

Replace the existing rows for UID0000HJ, UID0000HO, UID0000JR, and UID0000L3 with:

```text
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) : reconstructable : 86% : strong : NexusTK/map AttachedObjectPane.cpp source root with complete AttachedObjectPane and HitBarObjectPane declarations, exact common UpdatePosition slot, typed owner accessors, HitBar 0x138 layout/method/lifecycle evidence, derived overlay families, pool/vtable/resource support, and compiler ABI exclusions; stale UpdateHitBarBounds/ComputeDisplayBounds names remain historical aliases only.
- [UID:0000HO][BackPane](by-file/BackPane.md) : reconstructable : 89% : very-strong : Root game backdrop source root with BackPane/BackGroundPane lifecycles, singleton/vtable/resource/help methods, and inherited GrafPort::GetBounds consumption; historical UID000161 BackPane ownership is superseded without changing true BackPane paint/help behavior.
- [UID:0000JR][GrafPort](by-file/GrafPort.md) : reconstructable : 89% : strong : Render source family for GrafPort surface, clipping, drawing, glyph, wrapped-text, rect text-effect methods, and UID000161 GrafPort::GetBounds over m_visibleBounds; exact HitBar/BackPane/common-receiver evidence fixes the inherited source route without by-file reconstruction metadata.
- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 89% : very-strong : Major NexusTK/map/MapPane.cpp source root with complete UID0003TC ApplyHitBarObjectPane source in address order between UID0003TB and UID0003TD, preserving exact percentage arithmetic, LivingObjectPane/HitBar/ObjectList lifecycle, pooled new/delete lowering, position/bounds/invalidation order, absent inbound route, and compiler exclusions alongside existing MapPane families.
```

### `by-type/-coverage-report.md`

Placement: add alphabetically after `ModelessDialogPaneVtables` and before `ScheduledTimerEvent`:

```text
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) : reconstructable : 85% : very-strong : Pane/GrafPort inherited layout through the +0xf8 derived boundary; +0x44 is GrafPort m_visibleBounds and UID000161 GrafPort::GetBounds copies it for BackPane, ObjectPane-derived overlays, and broad UI/map/render consumers. Historical BackPane-specific accessor ownership is superseded while all handler/layer/region/visibility/motion/deletion field evidence remains intact.
```

- Tracker text: no manual tracker edit is proposed. The validator-owned research tracker changes only after supervisor report execution, which B002 must not run or predict as current state.

## Follow-Up Actions

- B002 implementation, scoped validators, waited generated verification, report reconciliation, and lease releases are complete.
- Supervisor may independently verify every C01-C30 claim, managed-block equality, UID-preserving UID000161 route, support no-loss, validators, generated output, leases, and manual coverage text. Independent Gate 2, coverage application, report execution, current/future path, movement, archive, registry, and lifecycle state remain external supervisor/validator-owned and are not asserted.
- A-agent actions: none. No IDA mutation is requested.
- B002 remaining callback items: zero. No additional ordinary or restricted edit is requested by this report.

## Confidence

- Recommendation confidence: `93/100` for target source disposition/body/ownership; `94/100` for UID000161 owner correction; `93/100` for class virtual/layout integration.
- Score confidence: high. Target behavior/source blockers are closed; lexical/liveness caps justify stopping below final.
- Remaining uncertainty: exact original private method and parameter spellings, exact original header filenames, and the original inbound reason for retaining the out-of-line copy. None changes behavior or blocks formal source.

## Validator Results

- Every scoped ordinary-page validation exited `0` with `ok:1`. Exact command/timestamp sequence (`America/New_York`) was: `000000012712` `02:57:20`, `000000012714` `02:58:22`, `000000012715` `02:58:54`, `000000012716` `03:02:31`, `000000012717` `03:03:44`, `000000012718` `03:04:30`, `000000012719` `03:05:11`, `000000012720` `03:05:48`, `000000012721` `03:06:29`, `000000012722` `03:07:13`, `000000012723` `03:07:55`, `000000012724` `03:08:22`, `000000012725` `03:09:48`, `000000012726` `03:10:16`, `000000012727` `03:11:09`, `000000012728` `03:11:36`, `000000012729` `03:12:07`, `000000012730` `03:12:44`, `000000012731` `03:13:25`, `000000012732` `03:13:48`, `000000012733` `03:14:16`, `000000012734` `03:14:46`, `000000012735` `03:16:01`, `000000012736` `03:17:08`, `000000012737` `03:18:08`, `000000012739` `03:18:36`, `000000012741` `03:19:09`, `000000012742` `03:19:37`, `000000012744` `03:20:05`, `000000012746` `03:20:28`, `000000012748` `03:21:01`, `000000012750` `03:21:29`, and `000000012754` `03:23:25`, all on `2026-07-15T...-04:00`.
- Command-to-destination proof: `12712`/`12742` target; `12714`/`12754` HitBar; `12715` Attached class; `12716` UID-preserving rename registration and `12750` renamed page validation; `12717`/`12748` BackPane class; `12718` MapPane class; `12719` MapPane file; `12720` Attached file; `12721` ObjectOverlayPanes; `12722` DamageNumber; `12723` GrafPort class; `12724` GrafPort file; `12725` BackPane file; `12726` PaneLayout; `12727` SwallowLayerPane file; `12728` BackPane activate/paint; `12729` viewport helper; `12730` chatting line count; `12731` TextButton bounds helpers; `12732`/`12733` ExchangeAlert constructor/core; `12734` FpsPane paint; `12735`/`12736`/`12737` help packet V1/V2/V3; `12739` MapPaneInitialize; `12741` generated BackPane hit test ordinary doc; `12744` AttachedObjectPane aggregate; `12746` SwallowLayerPaneCore.
- Scoped side effects were validator-owned projected-stat/reference-index/auto-generated-registry maintenance. Command `12731` also inserted its tool-owned missing metadata/UID mapping `0003NC`. UID-only command `12716` correctly skipped generated refresh. Warnings were pre-existing unrelated `missing_ref_uid` or unrelated empty/no-code marker warnings (including UID0003TD, UID0003YQ, UID0003XE, and FPS support); no target-specific error remained.
- Final authorized command: `python .\tools\validator.py --mode file --file 'by-memory\0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md' --apply --wait-generated --queue-timeout 240`, command `000000012755`, timestamp `2026-07-15T03:23:41-04:00`, exit `0`, `ok:1`, generated refresh completed under the same command. Validator-owned side effects were the expected auto-generated registry, projected metadata/reference refresh, and memory auto-coverage refresh; it also removed orphan generated `SwallowLayerPane.cpp` because its current source route emits no file. No generated file was manually edited.
- B002 final-authorized-refresh snapshot hashes/header command `000000012755`: `MapPane.cpp` `DAB6115B13E2D6E9E086C2F1AD6E8AEDA9C29CFD55F4E8AA2DAD89ED961DE814`; `AttachedObjectPane.cpp` `498451EB14C6591144168213CDB2871112B37A6C26CF77B0402ECC31A9C83851`; `GrafPort.cpp` `BC5CF3AB19562FD4D8C272ED4E2A360D913EAE39DE5AD76DE4542DB7CF6AFF7C`; `BackPane.cpp` `C1DEDA5FE2B57E6FB7BEB1257ED476D4A442AC09C544A92D8FE5592614C6116B`.
- Later concurrent validator-owned generated refreshes changed only the generated snapshot after B002's authorized command. The final report-time read-only headers show command `000000012773`, refreshed `2026-07-15T03:35:46-04:00`; snapshot hashes are MapPane.cpp `CC5DCAB9D33729818D0748F92F6C36DA3714BD767943BF5B2820D0A10927DDBA`, AttachedObjectPane.cpp `7A31106CBCAF1D315DE871FD3B5760298B55C0D6BF8D86DF16EE47FF33B801FD`, GrafPort.cpp `F8D8E91C7EBDDE46D1C78CED50A9EF69CD54E67D5459EDC5DD9722CE624958FC`, and BackPane.cpp `D3378254609412DEF168D297DB4249139519AA6ECC294C04675A1CD5EB9DE847`. B002 did not invoke those later commands or edit generated output; these values are explicitly time-scoped rather than assertions that unrelated future validator refreshes cannot change generated hashes.
- Generated exact-count/order proof is unchanged in both snapshots: MapPane has one UID0003TC header, one definition, and zero target empty markers. AttachedObjectPane has one AttachedObjectPane class before one HitBarObjectPane class, one exact HitBar pool definition, one SetValues, one IsActive, two UpdatePosition declarations (base pure plus HitBar override), one ClearOutputRects, one RenderFrame, zero raw vtable arrays, zero scalar-deleting source, and zero naked wrappers. GrafPort has one UID000161 header/definition and zero target empty markers. BackPane has zero UID000161 headers/definitions and four inherited `GetBounds(&bounds)` calls. No accepted current ordinary page retains the old UID000161 path or `UpdateHitBarBounds` as a concurrent accepted name.

## Changed Files

- Same report updated: `tools/leaser/Agents/Agent-B002/research/0003TC-MapPaneApplyHitBarObjectPane-source-quality.md`; exact final SHA256 and metrics are supplied with the supervisor submission because embedding a file's own final digest would mutate that digest.
- UID-preserving ordinary rename: `by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md` -> `by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md`; old path absent; UID remains `000161`.
- Modified ordinary destination hashes: target `81E90B6D1C510C857C31B8F9AD212A3E06E6075F8AD8958EF882B3CD32A61494`; HitBar class `9774CD9755E2763519052353BE414B8E2C041AADA71431CFD46F7703A5D090D4`; Attached class `B7919691F32313F4752544583DD5F54F38691057EE8023F6D6C3BCD0FF929C00`; UID000161 `D4DEF83C41E63B001615AA67B47F196B189562D7AAB03D6F977BE445022C7217`; BackPane class `CFFE0E700122A0B39575CAB2E46567EE03FA17ABE917311789E6A25716185D4C`; MapPane class `2E5BC3C5F475DABDC5DAAD17A893A89BC370872D927D3019D7EDB3D065656652`; MapPane file `CFAEAC7A19BD52EA05C7BDE8CBB38B0CE59E28F0AB344043FAB9774A7BD24908`; Attached file `2F217358FD8C1E1BD49195B56F46025E6DA479DB350678BE164C1BAD9B5C0DDC`; ObjectOverlayPanes `2D3B856A1126594A9EF6EF40CCAB0A9C1DF2FC469B7E180FEC928E9033287EFA`; DamageNumber `FDF23E1D9D362AAF3AAD4EDCFAA154A7C4142BD2BF46344EB6D364D46637B723`; GrafPort class `F1AD63407DAD2CCE4891E755A9F6271F259D3BEB40E9780A74A250A52B16053C`; GrafPort file `F1BC7F4AB313CA6CD07C66D75210C619BA9E382D4AF19ADE422EBE6DDD4F7E56`; BackPane file `49D7B56136FD145FB02D29696E6E0E6F4AAF5391DFC1DEC7CDA043FEC4723EF6`; PaneLayout `7D3F8FD2C1E7EF07E647A17E07927990C3A79CE13D59390250E5E87FABB2F248`.
- Modified current-reference hashes: BackPaneActivate `5F897A56D6E11AA07108154585069FC5536E99ADB44020CF00E2140AD727D673`; BackPaneViewport `888452C55C60AAB1EC7C1EC7B63A781CE07939954677C16078F4C1B66EF3973B`; ChattingLineCount `853741C492A03FABD01D3F9D370CD68CF0D0B81DE3BB8A4E82D19CAE1850AD8B`; TextButton bounds `4AA27D5BC31E9BE6AA76F6E29A6DA104EE74D5FFCCA092AF36BDF352776C6D83`; Exchange constructor `DA8ED83A13D055945527C776ABCCBDEDEC380A197C37543F95EB7283101C19E9`; Exchange core `0CD5F355CD6273E90598DC023D683D581D974699636A0B82A7ED0A64DFFAC9AA`; FpsPane paint `15E348DD2C1BCECF7EF02FE635797E9A51A48A268C3E89F4693A4F84E90DFADA`; help V1 `ACB5B46E0142232F2FE699A7B09F6E29ED4253D5925EC1B2DDE430591871B6A2`; help V2 `808AF9ED7627C927679DA8CC05B91089250671D06EE0B8D048A8C382A69883E8`; help V3 `2896F23B593625569F6FEB6E90E62F032B43F8C538C1705720A5019E7FCB8EA9`; MapPaneInitialize `04C2E2988DE34A6DDA6112A2877169C2E92DDC43911AB3A1438D2EFF17D3587D`; generated-hit-test ordinary doc `ED6F4A109361E7005DE6876C30EE41B6EB615B6A9E8DD7BDD40998FDC088657E`; Attached aggregate `8DBCE9885BDDEF76AB9EA731EAE40C0EFDD3D9C942DC0F1E212AB01E53315704`; Swallow core `65F2E08A2AAED08FC1ACCBF619CA84EDAC31D891822C8F7523916E1D334BBD21`; Swallow file `4E2783F02602A2178AB6F08F25BC23B72921F21B3468EE925A5DFBDD1C746F0B`.
- Restricted/manual coverage/generated/tracker/audit/supervisor/validator-state/lifecycle/IDA files manually edited by B002: zero. Generated files above were read-only validator output.
- Lease proof: one short B002 lease was acquired only for the ordinary page immediately being edited and released after that page's scoped validator. Terminal `tools/leaser/Agents/Agent-B002/current_leases.md` readback contains its generated header/table and `No active leases.` with no active B002 row; zero B002 leases remain.
- Report execution: not run. No report lifecycle/probe/count/move/archive command was run.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 validation passed before implementation; accepted SHA and timestamp are recorded above.
- [x] Confirm ledger IDs are exactly C01-C30, every Action is one of `incorporate`, `already-present`, `historicalize`, `reject-stale`, `reject-invalid`, `not-applicable`, and the initial report-only Verification states were exactly `proposed`; terminal states now use only the authorized callback vocabulary.
- [x] Apply Destination 1 target metadata, Item Summary, evidence, history, and exact managed body.
- [x] Apply Destination 2 complete HitBarObjectPane block, `90/93`, position 20, layout/virtual/lifecycle evidence.
- [x] Apply Destination 3 complete AttachedObjectPane block, `90/93`, position 10, shared pure UpdatePosition proof.
- [x] UID-preserving rename/reroute UID000161 and apply Destination 4 exactly.
- [x] Apply Destination 5 BackPane block without a duplicate GetBounds declaration.
- [x] Update MapPane class/file at report-level detail while retaining blank broad class formal and no by-file metadata.
- [x] Update AttachedObjectPane file, ObjectOverlayPanes, and DamageNumber terminology without compressing unrelated evidence.
- [x] Update GrafPort class/file, BackPane file, PaneLayout, and all listed current ordinary stale references under individual leases.
- [x] Preserve UID0003TB/UID0003TD, MapPoint, LivingObjectPane, setter/cleanup/unregister, ObjectList, pool/vtable/resource, RectBounds, and ObjectPane same-or-greater dependencies unless concrete drift is documented.
- [x] Preserve exact bytes/hash/range/CFG/xrefs/callees/negative evidence and historical B001/B003/B009 provenance.
- [x] Preserve exact arithmetic, fault order, active/stale/create order, owner synchronization, pool lowering, virtual order, and absent checks.
- [x] Preserve source/compiler distinctions and do not handwrite pool, EH, cookie, scalar-delete, vptr, RTTI, or vtable mechanics.
- [x] Confirm target owner/emitter/true/blank position/Nested 0 and class positions 10/20.
- [x] Confirm no duplicate report/child/helper/class body is created.
- [x] Confirm first-draft C++ appears only in the five exact managed destination blocks.
- [x] Confirm third-party import directive is not applicable; no third-party source is involved.
- [x] Confirm Wave2/Wave3 material is historical/stale and not used as authority.
- [x] Supply exact supervisor-owned manual coverage rows without editing coverage.
- [x] Keep all implementation callback boxes unchecked until the explicit supervisor callback; they were checked only after callback readback.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] Re-read every destination and verify-only dependency immediately before any edit.
- [x] Re-read active B001-B005 goals/reports and `lease.json`; wait/rebase if any listed ordinary page is leased or changed.
- [x] Lease only one ordinary file immediately before editing it.
- [x] Incorporate all accepted report detail without removing same-or-greater unrelated content.
- [x] Run one scoped validator for that changed page and record command ID, timestamp, exit, ok count, warnings, and side effects.
- [x] Release that file lease immediately after scoped validation before acquiring another.
- [x] Complete UID000161 UID-preserving rename/path propagation and verify every current ordinary stale reference; do not edit historical/coverage/generated files.
- [x] Update C01-C30 to legal terminal callback states with destination proof outside the state cell.
- [x] Run one final authorized waited target validation only after all ordinary pages pass and all leases are released.
- [x] Verify exact generated MapPane/AttachedObjectPane/GrafPort/BackPane counts, order, source route, absence of target empty marker, absence of duplicate BackPane definition, and absence of handwritten ABI/pool/vtable glue.
- [x] Record every changed file and final SHA in the supervisor submission, all validator proof, generated command/header/hash/readback, and zero remaining leases in this same report.
- [x] Fully check both checklist phases only after every accepted claim is applied or explicitly excluded with reason.
- [x] Do not run/probe execute_report, report lifecycle/count/registry commands, move/archive the report, mutate IDA, or manually edit generated/manual coverage/tracker/audit/supervisor/validator-state files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000012823","destination_path":"executed-b-agent-research/B002/0003TC-MapPaneApplyHitBarObjectPane-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0003TC-MapPaneApplyHitBarObjectPane-source-quality.md","timestamp":"2026-07-15T04:07:28-04:00","uid":"0003TC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
