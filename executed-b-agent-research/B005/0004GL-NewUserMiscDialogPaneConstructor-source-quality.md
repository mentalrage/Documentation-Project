** TARGET-REPORT-UID:0004GL **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004GL NewUserMiscDialogPaneConstructor Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: implemented. [UID:0004GL][by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md] is now a source-emitting `NewUserMiscDialogPane::NewUserMiscDialogPane()` child under [UID:00009F][by-class/NewUserMiscDialogPane.md].
- Final disposition: reconstructable, class-owned, source-authored constructor. Target now keeps `CANONICAL_OWNER:00009F`, keeps `RECONSTRUCTABLE:TRUE`, uses `EMITTER_UIDS:00009F`, and contains the formal first-draft constructor C++ supplied in this report.
- Required action status: applied for target/class/file/parent support docs. The accepted MCP session `eb7ce28b` evidence, exact range/size/caller/callee/vtable/global/resource facts, source-ready code, and negative owner evidence were incorporated at report-level detail. The class/file route now emits the child through `NexusTK/login/NewUserMiscDialogPane.cpp`.
- Confidence: implemented at `88/91`; capped below final-source quality because several child-control constructor spellings and two global/context names remain inferred/descriptive rather than original-symbol proof.

## Supporting Research

Historical initial research pass: B005 created this report as a report-only artifact and did not edit by-* files, generated files, coverage files, validator state, lifecycle state, archives, or supervisor ledgers during that pass.

Implementation callback pass: after Supervisor Gate 1 acceptance, B005 edited the target plus three direct support by-* docs, updated this report ledger/checklist, ran scoped validators, and released all leases. B005 did not edit generated files by hand, coverage reports, validator state by hand, lifecycle/archive files, or supervisor ledgers, and did not run `execute_report` or lifecycle/archive commands.

The active supervisor-restored IDA MCP session used for current evidence is `eb7ce28b`, attached to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Historical support pages still mention older sessions such as `3a33af0b`; those were treated as documentation history and rechecked where they affected this target.

Evidence sources used:

- Target: `by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md`.
- Direct owner/source docs: `by-class/NewUserMiscDialogPane.md`, `by-file/NewUserMiscDialogPane.md`, `by-file/CreateUserDialogs.md`.
- Parent/index docs: `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`, `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`.
- Direct singleton support: `by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md`.
- Child-control support: `by-class/GenderButtonControlPane.md`, `by-class/DirectionButtonControlPane.md`, `by-class/SelectBoxControlPane.md`, `by-memory/0x004fce80-0x004fd520.UserShapeSelectControlPaneCore.md`.
- Shared DialogPane helper naming support: `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`, `by-file/ForcedInformMessageDialog.md`, generated `auto-generated/NexusTK/login/BackStoryDialogPane.cpp`.
- Generated output state: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp`; after scoped validation it refreshes under validator command `000000005947` and contains UID0004GL constructor output.
- Executed matching report lead: `executed-b-agent-research/B013/0002Q7-NewUserMiscDialogPaneCoreAndPacketHelpers-source-quality.md`.
- Search terms used before old-report use: `0004GL`, `0x004fb630`, `0x004fbfcf`, `NewUserMiscDialogPaneConstructor`, `NewUserMiscDialogPane`, `DLGNEW02`, `GenderButtonControlPane`, `DirectionButtonControlPane`, `SelectBoxControlPane`, and `0002Q7`.

## Target

- Target UID: `0004GL`.
- Target path: `by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md`.
- Source queue/report row: assignment-time not-covered reconstructable by-memory row from `auto-generated/-ag-research-tracker.md`, score `84/90`, combined `87.0`, reconstructable `true`, reports `0`, agent blank.
- Current supervisor classification: implementation-callback artifact after Gate 1 acceptance, with B005 stopped before supervisor-owned execution.
- Current scores and parent state: target page now records `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, blank optional position, and formal constructor C++; direct class owner [UID:00009F] remains `85/88` under file owner [UID:0000LX] `NewUserMiscDialogPane`.

## Current Target State

- Current metadata: `UID:0004GL`, `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, blank optional position, `Nested:0`.
- Current owner/emitter/reconstructable state: the direct semantic owner is [UID:00009F][NewUserMiscDialogPane]. The target now emits through that class route and then through [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md).
- Current C++/emitter state: formal `RECONSTRUCTION_CPP CODE` now contains `NewUserMiscDialogPane::NewUserMiscDialogPane()` exactly from the accepted report.
- Current open questions/blockers: helper names and child-control constructor signatures are still inferred confidence caps; raw cleanup/destructor and packet-helper siblings remain separate child pages. None block UID0004GL constructor emission.
- Related target/support docs checked: target, class, file, parent split/index, broad mixed aggregate, singleton global, child controls, DialogPane helper pages, generated output, and matching executed B013 split report.
- Current artifact/lifecycle status: this artifact records B005's research plus implementation-callback application. B005 ran scoped file validators only, released leases, and did not run report execution/lifecycle/archive commands.

## Executive Recommendation

Assign UID0004GL as a source-emitting exact constructor child through [UID:00009F][NewUserMiscDialogPane]. Set target metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:00009F`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00009F`, leave optional position blank, and insert the formal constructor code below.

The broad UID0002Q7 parent must remain a non-emitting nested index, and UID00019U must remain a mixed non-emitting aggregate. The raw cleanup island at `0x004fbfd0`, command/packet/key/help handlers, raw sender islands, and reply handler are already exact sibling children and must not be folded into this constructor page.

The class/file support route should be synchronized so the class declaration can accept `[[CHILDREN]]` output and the file page records that the constructor emits through [UID:00009F] under the `NexusTK/login/NewUserMiscDialogPane.cpp` source route. `CreateUserDialogs` remains an umbrella/context page only.

## Supervisor Active Recheck

- Supervisor instruction: initial report-only research for UID0004GL passed Gate 1; current callback authorized applying accepted target/support details and scoped validators while stopping before supervisor-owned execution.
- Split status: no new split is required. B013 already split [UID:0002Q7] into exact child pages, including UID0004GL for `0x004fb630-0x004fbfcf` and exact sibling padding/raw/function/table children through UID0004GX.
- Source-bearing child status: UID0004GL is the assigned source-bearing constructor child. It now has current MCP evidence and a formal first-draft C++ recommendation. Sibling raw/no-route children stay outside this report's code body and are preserved as support evidence.

## Inference Research Guidance Check

The workflow requires using current binary facts and plausible mid-2000s source shape rather than copying decompiler labels or leaving eligible code blank solely because original symbols are missing. I separated:

- IDA facts: function size, calls, vtable writes, singleton writes, resource literals, xrefs, bytes, and padding from session `eb7ce28b`.
- Documentation evidence: existing class/file/parent pages, B013 split report, child-control field names, and shared DialogPane helper names.
- Inference: source-facing names such as `NewUserMiscDialogPane`, `g_pNewUserMiscDialogPane`, `GenderButtonControlPane`, `DirectionButtonControlPane`, `UserShapeSelectControlPane`, `Disable`, `dword_69B36C`, and `g_pMainUiGraph` are best-defensible project names, not original-PDB proof.

Existing assumptions corrected or limited:

- The broad parent no-C++ proof is valid for [UID:0002Q7] but no longer blocks the exact constructor child.
- The old generated empty class marker in `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` was historical pre-callback evidence of the blank child emitter route, not evidence that this constructor should stay blank. Post-callback generated output now contains UID0004GL constructor output.
- Inline setup for reusable controls is consumer evidence, not a reason to move ownership to `GenderButtonControlPane`, `DirectionButtonControlPane`, `SelectBoxControlPane`, or `UserShapeSelectControlPane`.
- No Wave2/Wave3 source was used as authority. Any older Wave references in support docs were treated as historical leads only.

## Heuristic / Inference Reanalysis And Validation

1. Constructor ownership: `lookup_funcs` under session `eb7ce28b` reports a modeled function at `0x004fb630` named `sub_4FB630`, size `0x99f`, ending before one byte of `0xcc` padding and a separate raw cleanup island. Decompile shows an ordinary constructor returning `this`, calling the DialogPane base constructor, installing the three class vtable views, publishing the singleton, building controls, and opening the pane. This validates `NewUserMiscDialogPane::NewUserMiscDialogPane()` as the source role.

2. Emitter route: target owner [UID:00009F] already clears the class gate at `85/88`, and file owner [UID:0000LX] is the established `NexusTK/login/NewUserMiscDialogPane.cpp` route. Historically, generated output showed only `g_pNewUserMiscDialogPane` and an empty class marker, proving the pre-callback coverage defect was missing child emission rather than absent source placement. After the callback validators, generated output contains UID0004GL constructor output.

3. Child-control construction: Gender and Direction class pages document exact inline setup values. For source shape, the constructor should create `GenderButtonControlPane` and `DirectionButtonControlPane` children rather than hand-writing vtable stores. The exact constructor signatures remain inferred because those reusable controls keep raw/no-route constructor caveats. That caps confidence but does not require decompiler-shaped code in this target.

4. Shape selector controls: `UserShapeSelectControlPane` has accepted constructor semantics and a formal source route. UID0004GL calls it four times with consecutive shape/head indices, `useMaleShapeBank=true`, and flag `1`, then selects the first slot. `sub_4E0DD0(dword_67A760)` is represented as the existing descriptive human-image/head-count getter; the name is inferred but the `rand() % (count - 3)` behavior is exact.

5. Select-box controls: `SelectBoxControlPane` has source-quality class declaration and method names. UID0004GL constructs six `SelectBoxControlPane` controls, uses `Pane::SetMode(1)` through the constructor path, and applies `SetSelected` only when the randomly chosen gender/style value requires a true selected state. The external group-clearing behavior lives in UID0004GO command handling, not in this constructor.

6. RNG order: the binary calls `rand()` for the shape window before seeding with `_time64(0)`/`srand`. It then calls `rand() % 2` and `rand() % 4` after seeding for gender/style groups. The first-draft C++ preserves that non-obvious order.

7. Tail helper names: current support pages name `sub_49FC00` as `DialogPane::SetHoverControl`, `sub_49DD80` as `SetFocusedControl`, `sub_49DDD0` as `SetPendingControl`, `sub_49DB60` as `SetBackgroundResource`, `sub_49DFD0` as `Create`/`OnCreate`, `sub_49E190` as `Show`/`OnShow`, `sub_49EAC0` as `SlideOpen`, and `sub_5446B0` as `Pane::SetMode`. These names allow human C++ without raw `sub_` labels.

8. Rejected no-code path: no ordinary pointer/immediate references to the constructor address were found, but `xrefs_to 0x004fb630` returns a real code caller at `0x004fa74e`. The pointer no-hit result is a confidence cap, not a hard no-route proof. The function is modeled, called, source-owned, and exact-bounded, so blank formal C++ is no longer the best source-quality disposition.

## Evidence Standards Used

Evidence used:

- IDA MCP `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, and `find_bytes`, all with exact addresses or narrow bounded ranges.
- Raw bytes around `0x004fb620`, `0x004fb630`, `0x004fb680`, `0x004fbfc0`, and `0x004fbfcf`.
- Direct code xrefs, vtable-store xrefs, singleton refs, resource literal refs, and negative address/pointer pattern checks.
- Current by-* documentation, direct child-control/source helper support docs, and current generated output.
- Executed B013 split report only after search-gating and only as a lead corroborated by current session `eb7ce28b`.

The evidence is strong enough for a first-draft constructor because the target is a modeled function with a single coherent caller, exact bounds, a class owner, direct vtable/singleton evidence, and source-quality helper names. Confidence remains below final audit because some source-facing child constructor declarations and global names are inferred.

## Evidence Checked

- IDA MCP checks performed under session `eb7ce28b`:
  - `idb_list`: active IDB session `eb7ce28b` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker, auto-analysis not running.
  - `server_health`: status `ok`, Hex-Rays ready, auto-analysis ready, module `NexusTK.exe`, imagebase `0x400000`.
  - `lookup_funcs`: `0x004fb630` is `sub_4FB630`, size `0x99f`; `0x004fb62a`, `0x004fbfcf`, and `0x004fbfd0` are not function starts; `0x004fc010` is the next modeled child function, size `0x56e`; `0x005029f0` is scalar deleting destructor, size `0x71`.
  - `decompile 0x004fb630`: confirms constructor body, base call, singleton publish, vtable stores, DLGNEW02 controls, randomization, child-control setup, DialogPane tail setup, and return `this`.
  - `xrefs_to`: `0x004fb630` has code xref `0x004fa74e`; vtables `0x0061d424/0x0061d484/0x0061d4b4` are written by constructor/raw cleanup/scalar destructor; singleton `0x0069b488` has constructor/raw cleanup/helper/destructor refs.
  - `callees 0x004fb630`: DialogPane/base/control helpers, allocator, `InitRectBounds`, EPF/image-button constructors, gender/direction inline base constructor, `sub_4E0DD0`, `_rand`, `UserShapeSelectControlPane` constructor, `_time64`, `_srand`, `SelectBoxControlPane` constructor, `Pane::SetMode`, DialogPane setup helpers, and security-cookie check.
  - `get_bytes`: six bytes of `0xcc` padding at `0x004fb62a-0x004fb62f`, function prologue at `0x004fb630`, constructor epilogue and one `0xcc` byte at `0x004fbfcf`, then raw cleanup island bytes at `0x004fbfd0`.
  - `find_bytes`: no matches for absolute VA bytes `30 B6 4F 00` or RVA-style `30 B6 0F 00`, so no broad pointer table route was found.
  - Caller decompile: `0x004fa5b0` reaches constructor at `0x004fa74e` after successful create-user reply path and object allocation; wrapper `0x004fa0f0` is vtable/data reached at `0x0061d35c`.
- Documentation/generation checks performed:
  - Historical pre-callback target page had blank formal C++ and blank emitter despite exact constructor evidence; implementation callback changed this to `EMITTER_UIDS:00009F` and formal constructor C++.
  - Historical pre-callback `by-class/NewUserMiscDialogPane.md` and `by-file/NewUserMiscDialogPane.md` described constructor role but did not yet provide an emission-ready route for this child; callback added the class `[[CHILDREN]]` route marker and file/source-route notes.
  - Historical pre-callback `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` header was from validator command `000000005897`, refreshed `2026-07-03T23:45:00-04:00`, and lacked UID0004GL output. Post-callback generated output header is command `000000005947`, refreshed `2026-07-04T00:32:50-04:00`, and contains UID0004GL constructor output.
  - B013 report confirms exact split child UIDs `0004GL` through `0004GX`, but did not resolve child formal C++ for UID0004GL.
- Failed/unavailable/skipped checks:
  - No IDA DB edits, renames, type changes, lifecycle commands, manual generated edits, or manual coverage edits were attempted by B005. Scoped validators were run only after the implementation callback.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004GL-001 | UID0004GL is an exact modeled constructor function at `0x004fb630-0x004fbfcf`, size `0x99f`. | High | MCP `lookup_funcs`, `get_bytes`, decompile, padding before/after. | Target status/evidence. | incorporate | applied: target evidence/status records session `eb7ce28b`, size `0x99f`, exact padding/end, raw cleanup boundary, successor `0x004fc010`; validator `000000005943` ok. |
| C-0004GL-002 | Direct owner remains [UID:00009F] `NewUserMiscDialogPane`; source route remains [UID:0000LX] `NewUserMiscDialogPane.cpp`. | High | Existing target owner, class/file docs, vtable stores, singleton lifecycle. | Target metadata; class/file docs. | incorporate | applied: target keeps `CANONICAL_OWNER:00009F`; class route marker and file route notes updated; validators `000000005943`, `000000005944`, and `000000005945` ok. |
| C-0004GL-003 | Target should emit through `EMITTER_UIDS:00009F`; blank emitter is the historical coverage defect. | High | Historical target blank emitter, class `85/88`, generated empty class marker, function/source readiness. | Target metadata; class support route. | incorporate | applied: target now has `EMITTER_UIDS:00009F`; generated output command `000000005947` contains UID0004GL constructor. |
| C-0004GL-004 | Formal first-draft C++ should be inserted as `NewUserMiscDialogPane::NewUserMiscDialogPane()` with exact RNG order and child-control construction behavior. | Medium-high | Decompile, callees, child-control docs, DialogPane helper names. | Target formal C++ block. | incorporate | applied: target formal block contains exact accepted constructor C++; validator `000000005943` ok and generated output includes the method. |
| C-0004GL-005 | Inline Gender/Direction setup is consumer-side child construction and must not transfer reusable-control ownership. | High | Gender/Direction class pages, vtable store refs, raw constructor caveats, inline value facts. | Target negative evidence; class/file support notes. | incorporate | applied: target ownership notes, class change note, and file change note preserve consumer-only child-control setup and rejected ownership transfer. |
| C-0004GL-006 | UID0002Q7 and UID00019U remain non-emitting container/index pages and must not receive aggregate constructor C++. | High | B013 split, parent metadata, exact child ranges. | Parent/support docs. | incorporate | applied/already-present: UID0002Q7 parent remains `RECONSTRUCTABLE:FALSE`, blank emitter/C++; parent row now says UID0004GL source-ready; UID00019U stayed unchanged because it already preserves mixed non-emitting aggregate state and does not directly mark UID0004GL no-code. |
| C-0004GL-007 | Raw cleanup island `0x004fbfd0-0x004fc00f` and packet raw senders are siblings outside this constructor, not tail code to paste into UID0004GL. | High | Lookup no-function start at `0x004fbfd0`, one-byte padding at `0x004fbfcf`, parent child inventory. | Target range/split evidence; parent row. | incorporate | applied: target evidence/ownership notes and UID0002Q7 row preserve raw cleanup and packet raw sender sibling boundaries; parent validator `000000005946` ok and wait-generated `000000005947` ok. |
| C-0004GL-008 | Pointer/immediate no-hits for `0x004fb630` are negative route evidence but do not block code because a direct code caller exists at `0x004fa74e`. | High | MCP `xrefs_to`, `find_bytes`, caller decompile. | Target negative evidence; score rationale. | incorporate | applied: target evidence/score rationale records no absolute-VA/RVA-style hits and direct caller `0x004fa74e`; source-ready disposition preserved. |
| C-0004GL-009 | Support docs should add or confirm a class-level `[[CHILDREN]]`/constructor route so generated output can place child method code instead of an empty class marker. | Medium-high | Historical generated empty marker, existing class blank C++. | `by-class/NewUserMiscDialogPane.md`. | incorporate | applied: class page formal block now has a `[[CHILDREN]]` route marker with UID0004GL route comments; validator `000000005944` ok; generated output command `000000005947` includes UID0004GL output and no UID00009F empty marker for this route. |
| C-0004GL-010 | `CreateUserDialogs`, `NewUserDialogPane2`, `CashShopRequest`, specialized controls, and broad aggregates are rejected as direct owners. | High | Source placement docs, dependency/caller direction, inline setup/callee use, class/file ownership evidence. | Ranked ownership, target/support negative evidence. | incorporate | applied: target/class/file/parent docs preserve rejected owner alternatives; singleton/control support docs were not edited because they already had same-or-greater detail and did not contradict accepted facts. |

## Positive Evidence Summary

- The binary function is an exact source-authored constructor: `sub_4FB630` has a standard constructor prologue/epilogue, object receiver, base constructor call, vtable writes, field/singleton initialization, child control construction, and returns `this`.
- The direct caller `0x004fa74e` in `sub_4FA5B0` allocates `620` bytes and calls `0x004fb630` during successful new-user reply handling, giving a real construction route.
- Class vtable writes at `0x004fb6ae`, `0x004fb6b4`, and `0x004fb6be` install `NewUserMiscDialogPane` primary/secondary/tertiary views. The same vtable family is referenced from the raw cleanup island and scalar deleting destructor, confirming class identity.
- Singleton writes to `0x0069b488` in the constructor match the executed singleton declaration [UID:0002XL] and class/file docs.
- `DLGNEW02.EPD` is referenced from this constructor and a sibling create-user variant; here it is part of `NewUserMiscDialogPane` setup, not a generic asset owner.
- Child-control docs resolve most source-facing names needed for human C++: `SelectBoxControlPane`, `UserShapeSelectControlPane`, `GenderButtonControlPane`, `DirectionButtonControlPane`, `SetSelected`, `SetMode`, `SetHoverControl`, `SetFocusedControl`, `SetPendingControl`, `SetBackgroundResource`, `Create`, `Show`, and `SlideOpen`.
- Historical pre-callback generated output lacked UID0004GL even after the split, which identified the blank emitter/formal C++ coverage gap. Post-callback generated output command `000000005947` contains UID0004GL constructor output.

## IDA MCP Facts

- Session: `eb7ce28b`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `server_health` status `ok`, Hex-Rays ready.
- Function/range:
  - `0x004fb630`: `sub_4FB630`, size `0x99f`, decompiled constructor returning `this`.
  - `0x004fb62a-0x004fb630`: six bytes of `0xcc` padding before the function.
  - `0x004fbfcf`: one byte of `0xcc` padding after constructor return.
  - `0x004fbfd0`: raw cleanup island start, not an IDA function, outside this page's end-exclusive range.
  - `0x004fc010`: successor modeled child `sub_4FC010`, size `0x56e`.
- Call/callee facts:
  - Direct code xref to `0x004fb630`: `0x004fa74e` inside `sub_4FA5B0`.
  - Caller chain: `0x004fa0f0` wrapper -> `0x004fa5b0` successful create-user reply branch -> allocate `620` bytes -> constructor call.
  - Callees include DialogPane base/setup helpers, allocator, `InitRectBounds`, EPF/image button/control constructors, `rand`, `_time64`, `srand`, `UserShapeSelectControlPane`, `SelectBoxControlPane`, and security-cookie check.
- Vtable/global facts:
  - Constructor writes `0x0061d424`, `0x0061d484`, `0x0061d4b4` into primary/secondary/tertiary views.
  - Vtable refs also appear in raw cleanup and scalar deleting destructor.
  - Singleton `0x0069b488` is written by constructor at `0x004fb687`/`0x004fb68e`, raw cleanup at `0x004fbfff`, support helper `0x00502400`, and scalar destructor `0x00502a22`.
- Resource/literal facts:
  - `DLGNEW02.EPD` at `0x0061e3a4` is referenced by the constructor at `0x004fb6ef` and `0x004fbf54`, and by `NewUserDialogPane2` construction at `0x0052a625`.
- Negative IDA facts:
  - `find_bytes` found no absolute-VA or RVA-style raw pointer hits for `0x004fb630`.
  - No evidence extends this constructor past `0x004fbfcf` into the raw cleanup island.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004fb630-0x004fbfcf` | [UID:0004GL][by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md] | Exact `NewUserMiscDialogPane` constructor | TRUE | [UID:00009F] | Current/applied `88/91`; historical pre-callback `84/90` | Source-ready child; emitter/formal C++ applied. |
| `0x004fbfcf-0x004fbfd0` | [UID:0004GM][by-memory/0x004fbfcf-0x004fbfd0.NewUserMiscDialogPaneConstructorPadding.md] | One-byte alignment padding | FALSE or ignored-style support | [UID:0002Q7] index | N/A | Keep separate; do not fold into constructor. |
| `0x004fbfd0-0x004fc00f` | [UID:0004GN][by-memory/0x004fbfd0-0x004fc00f.NewUserMiscDialogPaneRawCleanupIsland.md] | Raw cleanup/destructor-shaped island | TRUE documentation, no normal source route | [UID:0002Q7] index | N/A | Separate no-route child; not constructor tail. |
| `0x004fc010-0x004fc57e` | [UID:0004GO][by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md] | Command handler | TRUE | [UID:00009F] | Separate target | Not part of constructor. |
| `0x004fc5c0-0x004fc5e6` through `0x004fccee` | UID0004GP-UID0004GX children | Packet/key/help/reply/sender/table children | Mixed source/raw/data/padding | [UID:0002Q7] index / [UID:00009F] where source-ready | Separate targets | Preserve split boundaries. |
| `0x004fb630-0x004fccee` | [UID:0002Q7][by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md] | Nested index/container | FALSE | [UID:0000LX] | `88/91` | Keep non-emitting parent. |
| `0x004fb630-0x004fe782` | [UID:00019U][by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md] | Mixed broad aggregate/index | FALSE | NONE | `85/88` | Keep non-emitting aggregate. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004fa0f0` | Wrapper with data/vtable route at `0x0061d35c` | Dispatch wrapper reaches `sub_4FA5B0` when packet marker byte is `2`. |
| `0x004fa5b0` | Decompile contains success/failure create-user reply handling | On success, allocates `620` bytes and calls UID0004GL at `0x004fa74e`. |
| `0x004fa74e` | Direct code xref to `0x004fb630` | Strong constructor route; proves no-code route absence is false. |
| `0x004fb630` | Calls DialogPane base constructor | Establishes source role as class constructor, not free helper. |
| `0x004fb687` / `0x004fb68e` | Stores `0x0069b488` singleton | Publishes `g_pNewUserMiscDialogPane` with decompiler artifact guard for `this == -620`. |
| `0x004fb6ae/0x004fb6b4/0x004fb6be` | Vtable stores `0x0061d424/0x0061d484/0x0061d4b4` | Confirms class identity. |
| `0x004fb6ef` / `0x004fbf54` | DLGNEW02 literal refs | Background/resource setup. |
| `0x004fbfd0` | Not function start, raw island after one byte padding | Separate child boundary, not included in constructor formal code. |
| `0x005029f0` | Scalar deleting destructor, size `0x71` | Destructor family support, not constructor body. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target names `NewUserMiscDialogPane::NewUserMiscDialogPane`, owner [UID:00009F], source file [UID:0000LX], and exact child parent [UID:0002Q7].
  - Class/file docs describe the constructor's DLGNEW02 setup, singleton publish, vtables, child controls, randomization, and consumer-only inline setup for specialized controls.
  - B013 split report records exact child pages, parent non-emitting state, and current split boundaries.
  - SelectBox/UserShape/Gender/Direction support docs provide field names and ownership guardrails for child controls.
  - DialogPane helper support docs resolve tail helper names.
- Existing docs that were stale, incomplete, or contradicted before callback:
  - Historical pre-callback target C++ disposition said no formal code was inserted and left `EMITTER_UIDS` blank; callback applied `EMITTER_UIDS:00009F` and formal constructor C++.
  - Historical pre-callback class/file docs were strong on role but lacked an emission-ready child route; callback added the class `[[CHILDREN]]` route marker and file/source-route notes.
  - Older raw-helper/source-split uncertainty remains valid for siblings and parent but should not be copied forward as a constructor no-code reason.
- Generated/coverage report state:
  - Current generated `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` is validator-generated from command `000000005947`, refreshed `2026-07-04T00:32:50-04:00`, and contains UID0004GL constructor output. The older command `000000005897` empty-marker observation is historical pre-callback evidence only.

## Ranked Ownership Analysis

### 1. [UID:00009F] NewUserMiscDialogPane

- Evidence for: target metadata already names this class; constructor writes NewUserMiscDialogPane vtables; publishes `g_pNewUserMiscDialogPane`; builds class-specific DLGNEW02 UI; direct file route exists through [UID:0000LX]; caller constructs a 620-byte dialog object; parent split records exact child under this class family.
- Evidence against: full class declaration and several sibling methods remain incomplete; raw cleanup and packet sender siblings are unresolved. These affect broader class finality but not direct constructor ownership.
- Decision: best and accepted direct owner. Use [UID:00009F] as `CANONICAL_OWNER` and `EMITTER_UIDS`.

### 2. [UID:0000LX] NewUserMiscDialogPane file

- Evidence for: likely original source route under `NexusTK/login/`; contains singleton declaration; file doc already indexes the constructor; class owner emits through this file.
- Evidence against: file owner should not directly own a class method when the class page is viable and already named.
- Decision: keep as source file route only, not target canonical owner/emitter.

### 3. [UID:0000IK] CreateUserDialogs umbrella

- Evidence for: the UI belongs to create-user/login flow and shares `DLGNEW02.EPD` with `NewUserDialogPane2`.
- Evidence against: umbrella page is non-standalone context; direct class/file docs keep concrete NewUserMisc source route; constructor writes NewUserMisc vtables/singleton, not a generic create-user dialog family object.
- Decision: reject as direct owner; preserve as umbrella context only.

### 4. NewUserDialogPane2 / NewUserDialogPane source families

- Evidence for: `DLGNEW02.EPD` is also referenced by NewUserDialogPane2; caller chain is in the broader new-user packet flow.
- Evidence against: object vtables/singleton are NewUserMisc; NewUserDialogPane2 has its own class, singleton, constructor, and source file. Shared assets do not transfer constructor ownership.
- Decision: reject.

### 5. Specialized controls and shared helpers

- Evidence for: constructor inlines Gender/Direction setup and calls SelectBox/UserShape constructors.
- Evidence against: these are dependencies/child controls. Their vtables, fields, methods, and source files are documented elsewhere. Consumer construction does not own reusable-control methods.
- Decision: reject as owners; preserve as dependencies and naming support.

### 6. Broad by-memory parents [UID:0002Q7] and [UID:00019U]

- Evidence for: physical address ranges contain this function.
- Evidence against: UID0002Q7 is a non-emitting nested index and UID00019U is a mixed aggregate. Both exist to prevent aggregate emission across unrelated children.
- Decision: reject as emitters; keep unchanged.

## Source Placement

- Recommended source file/class/module placement: `NewUserMiscDialogPane::NewUserMiscDialogPane()` under [UID:00009F][by-class/NewUserMiscDialogPane.md], emitted through [UID:0000LX][by-file/NewUserMiscDialogPane.md] as `NexusTK/login/NewUserMiscDialogPane.cpp`.
- Why this placement fits source-tree and subsystem context: the object is a login/create-user UI dialog, shares the login source family with NewUserDialogPane2 and other account dialogs, uses the `g_pNewUserMiscDialogPane` singleton, and owns the NewUserMisc-specific vtables/handlers split by B013.
- Rejected placements:
  - `CreateUserDialogs`: umbrella/context only.
  - `NewUserDialogPane2`: shared resource, different class/singleton.
  - `CashShopRequest`: packet dependency, not UI owner.
  - `SpecializedButtonPanes` and `ButtonControlPane`: dependencies for child controls.
  - Mixed by-memory aggregates: split indexes, not source files.
- Remaining placement uncertainty: whether original source was physically `NewUserMiscDialogPane.cpp` or folded into a broader create-user implementation remains an original-file-name caveat. Current by-file route [UID:0000LX] is still the best project placement and clears the gate.

## Range / Split / Padding / Reclassification Analysis

- Exact boundary facts:
  - `0x004fb62a-0x004fb630`: six-byte `0xcc` padding before constructor start.
  - `0x004fb630-0x004fbfcf`: constructor body, IDA size `0x99f`.
  - `0x004fbfcf-0x004fbfd0`: one-byte `0xcc` constructor padding child [UID:0004GM].
  - `0x004fbfd0-0x004fc00f`: raw cleanup island [UID:0004GN], not modeled as a function and not part of constructor source.
  - `0x004fc010`: next modeled sibling `HandleCommand`.
- Children/subranges: all required children already exist through the B013 split workflow; this report does not request new child pages.
- Padding/table/data/code distinctions: constructor is source-authored code; the one-byte `0xcc` after it is padding; raw cleanup is a no-route sibling; help switch table later in UID0004GS is compiler data and out of scope for this constructor.
- Parent/container impact: keep UID0002Q7 and UID00019U non-emitting. Do not aggregate C++ into either parent.

## Negative Evidence Summary

- No broad pointer/immediate hits for `0x004fb630` were found with exact byte-pattern checks. This limits confidence about indirect construction routes but does not block source emission because a direct code caller exists at `0x004fa74e`.
- `0x004fbfd0` is not an IDA function and starts after a padding byte, so cleanup/destructor-shaped bytes must not be pasted into the constructor body.
- Inline writes to Gender/Direction vtables and fields are consumer-side construction evidence only. They do not prove those reusable controls belong to NewUserMiscDialogPane.
- `DLGNEW02.EPD` is shared with NewUserDialogPane2, so the resource literal alone is not ownership proof; ownership comes from vtables, singleton, and direct class docs.
- The `this == -620` decompiler branch around singleton publish is constructor/unwind artifact behavior from allocation adjustment, not human source logic to reproduce.
- `CreateUserDialogs` umbrella context, `CashShopRequest` packet path, and broad memory containers are weaker than the direct class route.
- The historical generated empty class marker was not evidence against code; it was generated output from the pre-callback blank child emitter/class route. Post-callback generated output includes UID0004GL.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were requested or performed by B005. Source-facing documentation names recommended for by-* docs:

- `sub_4FB630` -> `NewUserMiscDialogPane::NewUserMiscDialogPane()`.
- `unk_69B488` -> `g_pNewUserMiscDialogPane` in source-facing docs, preserving inferred/descriptive name caveat.
- `sub_49FC00` -> `DialogPane::SetHoverControl(int)`.
- `sub_49DD80` -> `DialogPane::SetFocusedControl(int)`.
- `sub_49DDD0` -> `DialogPane::SetPendingControl(int)`.
- `sub_49DB60` -> `DialogPane::SetBackgroundResource(...)`.
- `sub_49DFD0` -> `DialogPane::Create(...)` / existing project source surface.
- `sub_49E190` -> `DialogPane::Show(...)` / existing project source surface.
- `sub_49EAC0` -> `DialogPane::SlideOpen()`.
- `sub_5446B0` -> `Pane::SetMode(unsigned char)`.
- Child-control constructor spellings remain inferred support declarations; do not rename IDA or support pages solely from this report.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID0004GL is a modeled, called, exact-bounded, source-owned constructor with sufficient helper names and support docs.
- Recommended code: insert the following exact formal `RECONSTRUCTION_CPP CODE` block text into the target after supervisor callback.

```cpp
NewUserMiscDialogPane::NewUserMiscDialogPane()
    : DialogPane(L"", -1, true)
{
    RectBounds rect;

    g_pNewUserMiscDialogPane = this;

    InitRectBounds(&rect, 0, 0, 402, 373);
    AddControl(new EPFImageControlPane(L"DLGNEW02.EPD", 0, true, rect, NULL));

    InitRectBounds(&rect, 123, 307, 195, 323);
    AddControl(new ImageButtonControlPane(14, rect));

    InitRectBounds(&rect, 201, 307, 273, 323);
    AddControl(new ImageButtonControlPane(22, rect));

    InitRectBounds(&rect, 172, 49, 196, 72);
    AddControl(new GenderButtonControlPane(0, 2, true, rect));

    InitRectBounds(&rect, 200, 49, 224, 72);
    AddControl(new GenderButtonControlPane(1, 0, false, rect));

    const int shapeCount = g_pNewHumanImageLib->GetHeadCount();
    const int firstShapeIndex = rand() % (shapeCount - 3);

    InitRectBounds(&rect, 80, 78, 139, 154);
    UserShapeSelectControlPane *shapeButton =
        new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex), true, &rect, 1);
    AddControl(shapeButton);
    shapeButton->SetSelected(true);

    InitRectBounds(&rect, 139, 78, 198, 154);
    AddControl(new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex + 1),
                                              true,
                                              &rect,
                                              1));

    InitRectBounds(&rect, 198, 78, 257, 154);
    AddControl(new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex + 2),
                                              true,
                                              &rect,
                                              1));

    InitRectBounds(&rect, 257, 78, 316, 154);
    AddControl(new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex + 3),
                                              true,
                                              &rect,
                                              1));

    InitRectBounds(&rect, 56, 107, 72, 123);
    DirectionButtonControlPane *leftButton = new DirectionButtonControlPane(0, rect);
    AddControl(leftButton);
    if (firstShapeIndex == 0) {
        leftButton->Disable();
    }

    InitRectBounds(&rect, 325, 107, 341, 123);
    DirectionButtonControlPane *rightButton = new DirectionButtonControlPane(1, rect);
    AddControl(rightButton);
    if (firstShapeIndex == shapeCount - 4) {
        rightButton->Disable();
    }

    srand((unsigned)_time64(0));

    const int genderChoice = rand() % 2;

    InitRectBounds(&rect, 145, 180, 196, 231);
    SelectBoxControlPane *maleBox = new SelectBoxControlPane(&rect);
    AddControl(maleBox);
    maleBox->SetSelected(genderChoice == 0);

    InitRectBounds(&rect, 200, 180, 251, 231);
    SelectBoxControlPane *femaleBox = new SelectBoxControlPane(&rect);
    AddControl(femaleBox);
    femaleBox->SetSelected(genderChoice != 0);

    const int styleChoice = rand() % 4;

    InitRectBounds(&rect, 90, 235, 141, 286);
    SelectBoxControlPane *styleBox0 = new SelectBoxControlPane(&rect);
    AddControl(styleBox0);
    styleBox0->SetSelected(styleChoice == 0);

    InitRectBounds(&rect, 146, 235, 197, 286);
    SelectBoxControlPane *styleBox1 = new SelectBoxControlPane(&rect);
    AddControl(styleBox1);
    styleBox1->SetSelected(styleChoice == 1);

    InitRectBounds(&rect, 200, 235, 251, 286);
    SelectBoxControlPane *styleBox2 = new SelectBoxControlPane(&rect);
    AddControl(styleBox2);
    styleBox2->SetSelected(styleChoice == 2);

    InitRectBounds(&rect, 255, 235, 306, 286);
    SelectBoxControlPane *styleBox3 = new SelectBoxControlPane(&rect);
    AddControl(styleBox3);
    styleBox3->SetSelected(styleChoice == 3);

    SetHoverControl(5);
    SetFocusedControl(1);
    SetPendingControl(2);
    SetBackgroundResource(L"DLGNEW02.EPD", 0);
    SetMode(1);

    InitRectBounds(&rect, 238, 107, 640, 480);
    Create(rect, 0, 0, dword_69B36C);
    Show(false, g_pMainUiGraph);
    SlideOpen();
}
```

- Reason it preserves exact original behavior: the code preserves the base constructor arguments, singleton publish, background/buttons, exact rectangles, image IDs, control construction order, first-shape `rand()` before `srand`, `_time64` seeding before gender/style randomization, gender/style selection predicates, edge disabling for first/last shape window, focus/pending/hover control ids, background resource, mode, final create/show arguments, and slide-open call.
- Reason it matches plausible original source shape: it uses the same human source surfaces already present in generated login/dialog code (`RectBounds`, `InitRectBounds`, `AddControl`, `Load`/resource-style controls, `SetHoverControl`, `SetPendingControl`, `SetMode`, `Create`, `Show`, `SlideOpen`) instead of decompiler temporaries, vtable stores, raw allocators, or `sub_` labels.
- Inferred source-facing names/types used instead of IDA labels: `NewUserMiscDialogPane`, `g_pNewUserMiscDialogPane`, `g_pNewHumanImageLib`, `GetHeadCount`, `GenderButtonControlPane`, `DirectionButtonControlPane`, `Disable`, `dword_69B36C`, and `g_pMainUiGraph` are inferred/descriptive where original symbol proof is unavailable. Existing support docs already use or support most of these names; exact spelling remains a confidence cap.
- Naming/coding style convention: mid-2000s project style consistent with current generated dialog constructors, using `NULL`, `RectBounds`, `InitRectBounds`, `AddControl(new ...)`, direct control pointers for immediate state changes, and simple `rand()`/`srand()` calls.
- Reason code should remain blank, if applicable: not applicable. The previous blank-emitter state is superseded by current child-level evidence.
- Exact no-code proof, if not eligible: not applicable because the function is eligible.

## Final Recommendation

Implementation callback applied:

1. Updated `by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md` to `COMPLETION:88`, `CONFIDENCE:91`, kept `CANONICAL_OWNER:00009F`, kept `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00009F`, kept optional position blank, inserted the formal C++ block above, and incorporated current session `eb7ce28b` evidence and negative evidence.
2. Updated `by-class/NewUserMiscDialogPane.md` to record UID0004GL as source-ready, add a `[[CHILDREN]]` emission route marker, and preserve inferred child-control constructor/name caveats.
3. Updated `by-file/NewUserMiscDialogPane.md` to say UID0004GL emits through [UID:00009F] under the `NexusTK/login/NewUserMiscDialogPane.cpp` route while preserving `CreateUserDialogs` as umbrella context.
4. Updated `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` so the UID0004GL child row is source-ready while the parent remains non-emitting. The broad aggregate `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` was not edited because it already preserves mixed non-emitting state and does not directly mark UID0004GL no-code.
5. Ownership remains rejected for `CreateUserDialogs`, `NewUserDialogPane2`, `CashShopRequest`, specialized controls, SelectBox/UserShape controls, and broad memory aggregates.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md`.
- Implementation state: applied in target and validated by command `000000005943`.
- Exact report facts to incorporate:
  - MCP session `eb7ce28b` health/IDB evidence, function size `0x99f`, exact end before `0x004fbfcf` padding, successor raw cleanup island boundary, and successor `0x004fc010`.
  - Decompile/callee facts for base constructor, singleton publish, class vtables, DLGNEW02 controls, gender/direction inline setup, shape window randomization, select-box randomization, DialogPane tail setup, and return `this`.
  - Xref/caller facts: direct caller `0x004fa74e`, caller chain through `0x004fa0f0`/`0x004fa5b0`, vtable refs, singleton refs, resource refs.
  - Negative facts: no pointer/immediate hits for constructor address, raw cleanup outside range, consumer-only child-control setup, rejected owners.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:88`.
  - `CONFIDENCE:91`.
  - Keep `CANONICAL_OWNER:00009F`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Set `EMITTER_UIDS:00009F`.
  - Leave optional position blank.
  - Insert the formal C++ block from `First-Draft C++ Recommendation`.
- Historical/stale assumptions and negative evidence to preserve:
  - Historical B013 split used session `3a33af0b`; current callback should cite `eb7ce28b` for refreshed evidence.
  - Previous no-code/blank emitter was a child-level review blocker, now superseded.
  - Broad parent no-C++ proof remains valid for UID0002Q7, not for exact constructor UID0004GL.

## Recommended Support Doc Changes

- `by-class/NewUserMiscDialogPane.md`:
  - Implementation state: applied with route marker and UID0004GL source-ready notes; validator `000000005944` ok.
  - Incorporated UID0004GL method note as source-ready constructor emitting through the class.
  - Added a class formal C++ route marker with `[[CHILDREN]]`; did not invent a full final field layout beyond evidence.
  - Preserved inline Gender/Direction/SelectBox/UserShape consumer evidence, rejected ownership transfer, and raw cleanup/packet raw sender sibling boundaries.
- `by-file/NewUserMiscDialogPane.md`:
  - Implementation state: applied with UID0004GL class/file route notes; validator `000000005945` ok.
  - Constructor row/status now says UID0004GL emits through [UID:00009F] in `NexusTK/login/NewUserMiscDialogPane.cpp`.
  - Preserved [UID:0000IK] `CreateUserDialogs` as umbrella/context only and `NewUserDialogPane2` as a shared-resource neighbor.
- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`:
  - Implementation state: applied to UID0004GL row/detail while preserving parent non-emitting metadata; validators `000000005946` and wait-generated `000000005947` ok.
  - Parent remains `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++.
- `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`:
  - Implementation state: excluded with reason. Stale-check found no direct UID0004GL blank/no-code row requiring edit, and the page already preserves mixed aggregate non-emitting metadata.
- `by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md`:
  - Implementation state: already-present/excluded with reason. Current singleton declaration and lifecycle refs remain same-or-greater detail and did not contradict accepted facts.
- Gender/Direction/SelectBox/UserShape support docs:
  - Implementation state: already-present/excluded with reason. They already preserve consumer/dependency ownership and source-facing fields; no contradiction required edits.

## Score And Metadata Recommendation

- Historical pre-callback score/metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Current post-callback score/metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, blank optional position, formal C++ populated.
- Score rationale and reason not higher/lower:
  - Raise completion because the current pass closes the child-level formal C++ blocker, refreshes MCP evidence under `eb7ce28b`, resolves owner/emitter route, records exact boundaries, caller/callee/vtable/singleton/resource facts, and supplies implementation-ready support sync.
  - Raise confidence only one point because the binary facts are strong but helper/source names such as `GenderButtonControlPane` constructor arguments, `DirectionButtonControlPane::Disable`, `g_pNewHumanImageLib->GetHeadCount`, `dword_69B36C`, and `g_pMainUiGraph` remain inferred/descriptive rather than original-symbol proof.
  - Do not exceed low 90s until the class declaration route, child-control constructor support declarations, and sibling handler method source-quality reports are synchronized.
- Score-improvement attempts:
  - Checked direct MCP evidence for function size, boundaries, decompile, caller, callees, xrefs, and bytes.
  - Checked support docs for helper names and child-control field names.
  - Checked generated output to identify the current coverage defect.
  - Checked old B013 split report and direct parent docs to ensure no range/split blocker remains.
  - Checked negative pointer/immediate route; found no table route but direct caller resolves no-code concern.
- Metadata fields to leave unchanged: `UID`, target path, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `Nested:0`, optional emitter position blank.

## Open Questions With Attempted Resolution

- Exact original source filename: evidence favors [UID:0000LX] `NewUserMiscDialogPane.cpp`; it may have been folded under a broader create-user source file, but current source tree docs and direct class/file route make [UID:0000LX] the safest implementation path. Score impact: placement caveat only, not emitter blocker.
- Exact `GenderButtonControlPane` and `DirectionButtonControlPane` constructor signatures: support docs prove field values and class roles but keep raw constructor no-route caveats. The constructor code uses source-facing inferred constructors matching observed arguments and marks names as inferred. Score impact: confidence cap.
- Exact name for Direction edge no-arg vtable call: the binary calls a no-arg inherited/control method when the first/last shape window reaches an edge. Existing generated UI code uses `Disable()` for no-arg button disabling; this is the best descriptive source-facing name. Score impact: confidence cap.
- Exact `sub_4E0DD0(dword_67A760)` source spelling: support context points to a human image/head-count getter used for shape selector limits. `g_pNewHumanImageLib->GetHeadCount()` is descriptive and consistent with existing shape-selector docs, but exact original symbol is not proved. Score impact: confidence cap.
- Exact global names for `unk_69B36C` and `unk_67ABA4`: generated dialog constructors already use `dword_69B36C` and `g_pMainUiGraph` style for the same DialogPane create/show surface. The report preserves those as inferred/descriptive. Score impact: confidence cap.
- Whether to include raw cleanup/destructor logic in constructor C++: resolved no. Boundary bytes and exact child split prove the raw cleanup island is outside UID0004GL and must remain a sibling.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual supervisor-owned coverage or tracker edit is requested. The source by-* docs and scoped validators during implementation should update validator-owned/generated tracker and coverage state. Do not manually edit `auto-generated/-ag-research-tracker.md`, generated coverage reports, or any manual `-coverage-report.md` file.

## Follow-Up Actions

- Supervisor actions: perform supervisor-owned Gate 2 verification and, if accepted, supervisor-owned report execution. B005 did not and must not run execution/lifecycle commands.
- A-agent actions: none requested.
- B005 callback actions: completed and recorded in this report. No remaining B005 implementation blocker is known.

## Confidence

- Recommendation confidence: high for target owner/emitter/source-ready disposition; medium-high for exact source spellings inside the first-draft constructor.
- Score confidence: `88/91` is appropriate. Lower would under-credit current MCP and C++ readiness; higher would overstate unresolved constructor helper declarations and global names.
- Remaining uncertainty: original source names for some support constructors/helpers, final class declaration shape, and whether the original file was standalone or folded. None of these outweigh the direct modeled constructor/caller/class evidence.

## Validator Results

- Historical report-only pass: no validators were run before Gate 1.
- Implementation callback validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | command_id | command_timestamp | Exit | ok | Warnings/errors | Generated refresh |
| --- | --- | --- | --- | ---: | ---: | --- | --- |
| `by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md --apply --queue-timeout 240` | `000000005943` | `2026-07-04T00:32:00-04:00` | 0 | 1 | none target-specific | deferred |
| `by-class/NewUserMiscDialogPane.md` | `python .\tools\validator.py --mode file --file by-class/NewUserMiscDialogPane.md --apply --queue-timeout 240` | `000000005944` | `2026-07-04T00:32:08-04:00` | 0 | 1 | none target-specific | deferred |
| `by-file/NewUserMiscDialogPane.md` | `python .\tools\validator.py --mode file --file by-file/NewUserMiscDialogPane.md --apply --queue-timeout 240` | `000000005945` | `2026-07-04T00:32:20-04:00` | 0 | 1 | none target-specific | deferred |
| `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md --apply --queue-timeout 240` | `000000005946` | `2026-07-04T00:32:28-04:00` | 0 | 1 | none target-specific | deferred |
| `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md --apply --queue-timeout 240 --wait-generated` | `000000005947` | `2026-07-04T00:32:50-04:00` | 0 | 1 | global generated-refresh warnings only: unrelated `autogen_children_marker_missing`, `autogen_emitter_has_no_code`, and fallback-insert rows; no UID0004GL failure | completed |

- Generated freshness: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` header reports validator command `000000005947`, refreshed `2026-07-04T00:32:50-04:00`, `foreground-generated-refresh`; it contains UID0004GL constructor output and no longer shows the UID00009F empty-marker-only state for this route.
- Validator side effects from scoped commands: validator-owned generated metadata/projected stats/registry metadata refreshed, including `project-level/-auto-completion-stats.md`, `auto-generated/-ag-*-coverage.md`, generated C++ metadata, and autogen backups under `tools/validator_autogen_backup/20260704-003255`, `20260704-003258`, and `20260704-003300`. B005 did not edit generated files or validator state by hand.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B005/research/0004GL-NewUserMiscDialogPaneConstructor-source-quality.md` during the initial report-only pass.
- Modified by B005 in implementation callback:
  - `by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md`.
  - `by-class/NewUserMiscDialogPane.md`.
  - `by-file/NewUserMiscDialogPane.md`.
  - `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`.
  - `tools/leaser/Agents/Agent-B005/research/0004GL-NewUserMiscDialogPaneConstructor-source-quality.md`.
- Stale-checked but not edited:
  - `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` already preserves mixed aggregate non-emitting state and did not directly mark UID0004GL blank/no-code.
  - Singleton/control support docs already had same-or-greater relevant detail and did not contradict accepted facts.
- Renamed:
  - none.
- Leases used/released: leased exactly the four edited by-* files as B005 for the edit/validator batch, then released all four after validation. Final `current_leases.md` check reported no active leases.
- Generated/manual files: generated files and validator/projected stats refreshed only through scoped validator commands; no generated, coverage, lifecycle/archive, supervisor ledger, or validator-state file was manually edited.
- Report execution: not run. B005 did not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, registry commands, manual report moves, generated edits, or coverage edits.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor reported Gate 1 passed before callback.
- [x] Target/support docs to update listed. Proof: target, class, file, and parent support paths were listed; optional aggregate/control/singleton exclusions were recorded.
- [x] Current target state and actual evidence checked recorded. Proof: report records historical `84/90` blank-emitter state, current MCP session `eb7ce28b`, exact function/caller/callee/xref/byte/generated-output facts, and post-callback `88/91` state.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: C-0004GL-001 through C-0004GL-010 now have `applied`, `already-present`, or `excluded-with-reason` proof.
- [x] Metadata/score changes applied. Proof: target is `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009F`, blank optional position.
- [x] Score-limiting blockers researched to resolution. Proof: direct caller, pointer no-hit, helper names, child-control names, generated-output defect, range boundary, and source placement are resolved with confidence caps.
- [x] Owner/emitter/reconstructable changes applied. Proof: owner/reconstructable unchanged; emitter set to `00009F`.
- [x] Split/rename/new-child changes confirmed not applicable. Proof: no new split; B013 exact child split preserved; raw cleanup/padding/sibling handlers remain separate.
- [x] Source-placement/range/padding/reclassification/IDA rename-type-comment disposition recorded. Proof: source placement [UID:00009F] via [UID:0000LX], range/padding evidence incorporated, no IDA DB edits requested.
- [x] First-draft C++ applied. Proof: target formal block contains exact accepted `NewUserMiscDialogPane::NewUserMiscDialogPane()` code.
- [x] Third-party import directive not applicable. Proof: target is NexusTK-owned UI code.
- [x] Exact target/support doc facts incorporated at report-level detail. Proof: target/class/file/parent docs carry MCP session, function size, direct caller, callees, vtables, singleton, DLGNEW02 refs, child-control setup, RNG order, DialogPane tail helpers, generated-output repair, and rejected alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: blank/no-code state historicalized; parent no-C++ proof remains only for UID0002Q7; rejected owner alternatives and pointer no-hit/raw cleanup boundary preserved.
- [x] Wave2/Wave3 mentions or artifacts handled. Proof: older Wave-style support notes were treated as historical leads only; current by-* and MCP evidence controls the recommendation.
- [x] Open questions documented as evidence-backed confidence caps. Proof: child-control constructor spellings, `Disable`, head-count/global names, and original filename remain documented caps, not blockers.
- [x] Validators run for edited by-* docs. Proof: commands `000000005943` through `000000005947` recorded in `Validator Results`.
- [x] Generated refresh reported. Proof: generated `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` refreshed at command `000000005947` and contains UID0004GL output; no manual coverage/tracker text requested.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: supervisor callback authorized exact report artifact.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: edited target, class, file, and UID0002Q7 parent; aggregate/singleton/control supports marked already-present or excluded with reason.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: ledger rows C-0004GL-001 through C-0004GL-010 updated from `proposed`.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: target metadata/C++ applied; no split/rename required; UID00019U/support singleton/control docs excluded or already-present with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve raw cleanup sibling, no pointer/immediate hits, no aggregate C++, and rejected owner alternatives.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: remaining names are documented confidence caps only.
- [x] Validators run and results recorded. Proof: command IDs/timestamps/exits/ok counts are in `Validator Results`.
- [x] Generated report refresh completed by validator or generated freshness reported. Proof: wait-generated command `000000005947` completed and generated source header matches it.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no unapplied accepted target/class/file/parent item remains; optional aggregate/singleton/control support edits are excluded/already-present with concrete reasons.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000005989","destination_path":"executed-b-agent-research/B005/0004GL-NewUserMiscDialogPaneConstructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0004GL-NewUserMiscDialogPaneConstructor-source-quality.md","timestamp":"2026-07-04T00:53:41-04:00","uid":"0004GL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
