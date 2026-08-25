** TARGET-REPORT-UID:0001LC **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0001LC SelectObjectWithKeyboardPaneDestructor Empty-Emitter Source-Quality Research

Status: FINISHED_IMPLEMENTATION

## Finalized Report / Current Recommendation

- Assignment: `B008-empty-emitter-report-0001LC-SelectObjectWithKeyboardPaneDestructor-20260629`.
- Current recommendation: promote [UID:0001LC] from a routed-but-empty destructor page to a source-ready first-draft `SelectObjectWithKeyboardPane::~SelectObjectWithKeyboardPane()` emitter.
- Final disposition: source-authored non-deleting destructor for [UID:0000CT][SelectObjectWithKeyboardPane](../../../../by-class/SelectObjectWithKeyboardPane.md), emitted through the existing class route to [UID:0000OH][TargetSelectionInputPanes](../../../../by-file/TargetSelectionInputPanes.md).
- Required action after supervisor acceptance: update the target by-memory page with current MCP proof from session `c9671f69`, replace stale `95/95` blank-C++ rationale, raise score to `88/91`, and insert the formal destructor C++ block below.
- Confidence: high for behavior, ownership, emitter route, bounds, padding, singleton source shape, scalar-wrapper separation, and C++ readiness. Confidence stays below final-audit because exact original spelling of the active singleton pointer is still provisional and broader target-selection static declaration/header cleanup remains outside this target.

## Target

- Target UID: `0001LC`
- Target path: `by-memory/0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`.
- Current generated empty marker: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, validator command `000000000674`, refreshed `2026-06-29T11:40:18-04:00`, line `889`.
- Current metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CT`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.

## Current Target State

The target page already has strong range and behavior evidence but keeps `RECONSTRUCTION_CPP CODE` blank because it still cites the old `95/95` final-code threshold. That threshold is stale under current `by-structure.md`: an agent may supply formal first-draft C++ when the target is `RECONSTRUCTABLE:TRUE`, has a nonblank emitter route to generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`, provided source-quality blockers are resolved or documented. UID0001LC currently averages `88`, routes through [UID:0000CT] to [UID:0000OH], and generated output proves the current empty marker is caused by the blank formal C++ block.

Current support state resolves the main source-facing names:

- [UID:0002A2] documents `0x0069bf60` / `dword_69BF60` as provisional `s_activeSelectObjectWithKeyboardPane`.
- [UID:0001LB] already emits constructor C++ using `s_activeSelectObjectWithKeyboardPane = this;`.
- [UID:00035Q] documents `0x004f2010` as the shared `LineInputPane` cleanup/base destructor body.
- [UID:0000CT] and [UID:0000OH] already route this class through `TargetSelectionInputPanes.cpp`.

The current target prose is otherwise structurally correct: exact `0x29` function range, two-byte predecessor padding, seven-byte successor padding, no direct xrefs to the non-deleting destructor entry, three `SelectObjectWithKeyboardPane` vtable restores, singleton clear, and tail jump to the base cleanup helper.

## Supervisor Active Recheck

The supervisor explicitly resumed this report-only assignment after MCP restart and verified current active MCP session `c9671f69` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `19076`. This report uses that session only and does not use stale session `d4d50b81`.

No split repair is required before the final report. UID0001LC is a single modeled function with exact half-open range `0x005af6e0-0x005af709`; adjacent bytes are padding and the next modeled function starts at `0x005af710`.

## Evidence Checked

IDA MCP current pass used endpoint `http://127.0.0.1:13337/mcp`, active session `c9671f69`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `idb_list` returned exactly that active worker session, and `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, module `NexusTK.exe`, and imagebase `0x400000`. No IDA DB writes, renames, comments, type changes, patching, saving, or process-management actions were made.

MCP calls and results used:

- `lookup_funcs` for `0x005af6e0`, `0x005af709`, `0x005af710`, `0x005b7bc0`, `0x004f2010`, and `0x005b7620`.
- `get_bytes` for `0x005af6de` size `2`, `0x005af6e0` size `41`, and `0x005af709` size `7`.
- `disasm 0x005af6e0` with `max_instructions=30` and `include_total=true`.
- `decompile 0x005af6e0` with `include_addresses=false`.
- `xrefs_to` for `0x005af6e0`, `0x0069bf60`, `0x005b7bc0`, `0x004f2010`, and vtable bases `0x0062f328`, `0x0062f378`, `0x0062f3a8`.
- `xref_query` for `0x005af6e0` and `0x005af709`, direction `to`, capped at `20`.
- `callees` for `0x005af6e0` and `0x005b7bc0`.
- `disasm` and `decompile` for scalar deleting sibling `0x005b7bc0`.
- `get_int` for vtable cells at `0x0062f328`, `0x0062f378`, `0x0062f37c`, `0x0062f380`, `0x0062f384`, `0x0062f3a8`, `0x0062f3ac`, and `0x0062f3b0`.
- MCP `int_convert` for `0x29`, `0x5f`, `0x108`, `0xa0`, `0xa4`, and vtable-cell decimal values. `0x29` is `41`, `0x5f` is `95`, `0x108` is `264`, `0xa0` is `160`, and `0xa4` is `164` (Verified with MCP `int_convert`).

Local docs checked:

- Target page [UID:0001LC].
- Allowed support pages [UID:0000CT], [UID:0000OH], [UID:0002A2].
- Comparison/support sibling [UID:0001ND].
- [UID:0001LB] constructor page for accepted singleton source shape.
- [UID:00035Q] `LineInputPaneCleanupBody` for base cleanup ownership.
- Generated output `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, read-only.
- `by-structure.md` current C++ gate and IDA MCP Output Discipline.
- `score-blocker-audit-standard.md`.

Old report search terms used as assigned: `0001LC`, `005af6e0`, `SelectObjectWithKeyboardPaneDestructor`, `SelectObjectWithKeyboardPane`, `TargetSelectionInputPanes`, `0000CT`, and `0001ND`.

Relevant old reports used as leads:

- `executed-b-agent-research/B005/0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality.md`: accepted singleton name `s_activeSelectObjectWithKeyboardPane`, current constructor gate precedent, and stale `95/95` handling.
- `executed-b-agent-research/B005/0001L8-TargetSelectionInputPanes-source-quality.md`: exact child/source-route context and aggregate non-emitting disposition.
- `executed-b-agent-research/B013/0001L4-ItemWhoInputPane-source-quality.md`: sibling destructor source-shape precedent that base cleanup is implicit in source C++ and scalar-delete logic must not be copied into the ordinary destructor.

No active unexecuted report already existed at the assigned B008 report path before this write.

## IDA MCP Facts

Function and boundary facts:

- `lookup_funcs 0x005af6e0` returns `sub_5AF6E0`, size `0x29`, ending at `0x005af709`.
- `lookup_funcs 0x005af709` returns `Not a function`.
- `lookup_funcs 0x005af710` returns sibling `sub_5AF710`, size `0x245`.
- `get_bytes 0x005af6de size 2` returns `0xcc 0xcc`.
- `get_bytes 0x005af6e0 size 41` returns the full five-instruction destructor body bytes.
- `get_bytes 0x005af709 size 7` returns seven `0xcc` bytes before the key handler.

Destructor instruction facts:

- `0x005af6e0`: `mov dword ptr [ecx], offset ??_7SelectObjectWithKeyboardPane@@6B@`, restoring vtable base `0x0062f328`.
- `0x005af6e6`: `mov dword ptr [ecx+0A0h], offset ??_7SelectObjectWithKeyboardPane@@6B@_0`, restoring the secondary view at offset `+0xa0` (`160` decimal, Verified with MCP `int_convert`).
- `0x005af6f0`: `mov dword ptr [ecx+0A4h], offset ??_7SelectObjectWithKeyboardPane@@6B@_1`, restoring the tertiary view at offset `+0xa4` (`164` decimal, Verified with MCP `int_convert`).
- `0x005af6fa`: `mov dword ptr unk_69BF60, 0`, clearing the active singleton.
- `0x005af704`: `jmp sub_4F2010`, a tail jump to shared base cleanup.
- `disasm` reports exactly five total instructions for the function.
- `decompile 0x005af6e0` renders the same sequence as vtable stores, `unk_69BF60 = 0`, and `sub_4F2010(this)`.

Xref and callee facts:

- `xrefs_to 0x005af6e0` returns no cross-references.
- `xref_query 0x005af6e0` and `xref_query 0x005af709` each return zero incoming xrefs.
- `xrefs_to 0x0069bf60` returns six refs: `0x005a5f3a`, constructor writes at `0x005af637` and `0x005af63e`, UID0001LC clear at `0x005af6fa`, helper clear at `0x005b7620`, and scalar deleting destructor clear at `0x005b7be0`.
- `xrefs_to 0x004f2010` returns 51 refs; UID0001LC is the code xref at `0x005af704`, matching a shared input-pane cleanup target.
- `callees 0x005af6e0` returns no call edges because the base cleanup is a tail jump, not a normal call.

Vtable facts:

- `xrefs_to 0x0062f328` returns constructor store `0x005af653`, UID0001LC restore `0x005af6e0`, and scalar restore `0x005b7bc6`.
- `xrefs_to 0x0062f378` returns constructor store `0x005af659`, UID0001LC restore `0x005af6e6`, and scalar restore `0x005b7bcc`.
- `xrefs_to 0x0062f3a8` returns constructor store `0x005af663`, UID0001LC restore `0x005af6f0`, and scalar restore `0x005b7bd6`.
- `get_int 0x0062f328 u32le` converts to `0x005b7bc0`, the scalar deleting destructor (Verified with MCP `int_convert`).
- Secondary table cells include `0x005afa10` and `0x005af710`, the mouse and key handlers (Verified with MCP `int_convert` from the `get_int` decimal values).
- Tertiary table starts with `0x005b786d`, the adjustor thunk (Verified with MCP `int_convert`).

Scalar sibling facts:

- `lookup_funcs 0x005b7bc0` returns `sub_5B7BC0`, size `0x5f` (`95` decimal, Verified with MCP `int_convert`).
- `disasm 0x005b7bc0` shows the same three vtable restores and singleton clear, then `call sub_4F2010`, scalar-delete flag tests, ordinary free through `sub_4F4AC0`, and guarded bit-4 size path with `push 108h` (`264` decimal, Verified with MCP `int_convert`).
- `xrefs_to 0x005b7bc0` returns two adjustor thunk jumps at `0x005b7868` and `0x005b7873`, plus primary vtable data ref `0x0062f328`.
- `callees 0x005b7bc0` returns `sub_4F2010`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`.

## Positive Evidence Summary

- UID0001LC is a normal modeled non-deleting destructor with exact bounds and padding.
- The destructor has one source-relevant action beyond compiler vtable/base chaining: clearing the active SelectObject singleton slot.
- The singleton slot has an accepted source-facing name, `s_activeSelectObjectWithKeyboardPane`, from [UID:0002A2] and the accepted [UID:0001LB] constructor implementation.
- The tail jump to `LineInputPaneCleanupBody` is destructor chaining/base cleanup, not a source statement to write manually.
- The scalar deleting sibling repeats the same cleanup and adds compiler delete-wrapper logic, proving UID0001LC should own ordinary destructor source while [UID:0001ND] remains separate wrapper evidence.
- The current score/emitter gate is satisfied and current generated output proves the only UID0001LC empty-emitter cause is blank formal C++.

## Negative Evidence Summary

- No direct static callers or xrefs target `0x005af6e0`; this is normal for a non-deleting destructor reached by compiler/vtable/destructor machinery and does not make the function non-source.
- The vtable writes are compiler destructor output and must not be written as source statements.
- `sub_4F2010(this)` is base destructor/cleanup chaining. Writing an explicit `LineInputPane::~LineInputPane()` call in source would be wrong for ordinary C++ destructor shape.
- Scalar-delete flag handling, object free, guarded-size delete, and adjustor-thunk jumps belong to [UID:0001ND] / thunk pages, not UID0001LC source C++.
- [UID:0000OH] owns the file route but is not the direct semantic owner of this class method.
- [UID:0002A2] owns the static data declaration route, not the method body. The destructor should reference the singleton variable but should not emit its declaration.

## Heuristic / Inference Reanalysis And Validation

- Old blocker: "final source spelling remains below the `95/95` final-code threshold." Rejected as stale. Current code gate is combined-score/emitter based. UID0001LC already clears it.
- Singleton pointer name: use provisional `s_activeSelectObjectWithKeyboardPane` for `dword_69BF60`. This is not symbol-proven, but it is the accepted source-facing name from constructor and singleton support docs. Rejected raw `dword_69BF60` / `unk_69BF60` in formal C++ because current project rules require replacing raw IDA globals when role evidence is strong.
- Destructor source shape: emit only the destructor method and singleton clear. This preserves behavior because C++ compiler output supplies vtable restores and base destructor chaining. Rejected explicit vtable stores and explicit base cleanup call as decompiler-shaped and behavior-risking source.
- Owner/source placement: keep direct owner [UID:0000CT] and route through [UID:0000OH]. Rejected direct file owner because the function is a class destructor; rejected `LineInputPane` because it is a base dependency only.
- Scalar sibling handling: [UID:0001ND] is comparison evidence only. Do not merge its delete-wrapper logic into UID0001LC and do not edit [UID:0001ND] during this callback unless the supervisor explicitly expands scope.
- Generated marker cause: verified current generated file still has UID0001LC as an empty marker under `TargetSelectionInputPanes.cpp`, not a missing owner/emitter/dead-end problem.

## Ranked Ownership Analysis

### 1. [UID:0000CT] SelectObjectWithKeyboardPane

- Evidence for: destructor restores three `SelectObjectWithKeyboardPane` vtable views, clears the SelectObject singleton slot, has scalar-wrapper parity with [UID:0001ND], and is surrounded by accepted class constructor/key/mouse/helper children.
- Evidence against: no direct caller xrefs, but that is expected destructor dispatch shape and is outweighed by vtable/singleton evidence.
- Decision: keep `CANONICAL_OWNER:0000CT` and `EMITTER_UIDS:0000CT`.

### 2. [UID:0000OH] TargetSelectionInputPanes

- Evidence for: this is the source file route for the target-selection pane family and owns the singleton slot declaration route.
- Evidence against: it is not the narrow semantic owner of a class destructor.
- Decision: keep as indirect generated source route through [UID:0000CT]; do not set direct owner/emitter to file UID.

### 3. [UID:000077] LineInputPane / [UID:00035Q] cleanup body

- Evidence for: UID0001LC tail-jumps to `0x004f2010`, the shared `LineInputPane` cleanup body.
- Evidence against: the vtables and singleton are `SelectObjectWithKeyboardPane`-specific; `LineInputPane` is inherited cleanup only.
- Decision: reject as owner; preserve as base dependency.

### 4. [UID:0002A2] singleton slots

- Evidence for: UID0001LC writes `0x0069bf60`.
- Evidence against: data declaration ownership is separate from the method body; the page already routes the static slot declaration through [UID:0000OH].
- Decision: use as support evidence, not method owner.

## Source Placement

Recommended source placement stays `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` via [UID:0000OH], with direct semantic ownership under [UID:0000CT]. This matches the accepted constructor, key handler, mouse handler, singleton slots, and target-selection module inventory. Do not route this destructor to `InputPanes.cpp`, `Pane.cpp`, `LineInputPane`, `MapPane`, `UserPane`, or a standalone destructor/glue source file.

## Range / Split / Padding / Reclassification Analysis

- Predecessor constructor [UID:0001LB] ends at `0x005af6de`.
- `0x005af6de-0x005af6e0`: two `0xcc` bytes, not source code.
- Target function: `0x005af6e0-0x005af709`, modeled `sub_5AF6E0`, size `0x29` (`41` decimal, Verified with MCP `int_convert`), exactly five instructions.
- `0x005af709-0x005af710`: seven `0xcc` bytes before [UID:0001LD].
- `0x005af710`: next function start, `sub_5AF710`.
- No split, merge, rename, or reclassification is required.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005af5f0-0x005af6de` | [UID:0001LB] constructor | source constructor | TRUE | [UID:0000CT] | `88/91` | already emits first-draft C++ |
| `0x005af6de-0x005af6e0` | none | padding | not source | n/a | n/a | two `0xcc` bytes |
| `0x005af6e0-0x005af709` | [UID:0001LC] target | source non-deleting destructor | TRUE | [UID:0000CT] | current `86/90`, recommend `88/91` | should emit first-draft C++ |
| `0x005af709-0x005af710` | none | padding | not source | n/a | n/a | seven `0xcc` bytes |
| `0x005af710-0x005af955` | [UID:0001LD] key handler | source virtual method | TRUE | [UID:0000CT] | populated | sibling starts after padding |
| `0x005b7bc0-0x005b7c1f` | [UID:0001ND] scalar deleting destructor | compiler delete wrapper with cleanup parity | TRUE but wrapper source separate | [UID:0000CT] | `86/90` | comparison only for this report |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005af6e0` | zero incoming xrefs | no direct static refs to ordinary destructor entry |
| `0x005af6fa -> 0x0069bf60` | data write | clears active SelectObject singleton |
| `0x005af704 -> 0x004f2010` | code xref tail jump | inherited `LineInputPane` cleanup/base destructor chaining |
| `0x005b7bc0` | refs from `0x005b7868`, `0x005b7873`, `0x0062f328` | scalar deleting wrapper reached by adjustor thunks/vtable |
| `0x0062f328/0x0062f378/0x0062f3a8` | constructor, destructor, scalar destructor refs | class vtable lifecycle constants |

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Reason: target is `RECONSTRUCTABLE:TRUE`, has nonblank emitter `0000CT`, routes to [UID:0000OH] `TargetSelectionInputPanes.cpp`, current average score is above `85`, current MCP evidence resolves exact behavior and boundaries, and the only source-level statement is a supported singleton clear.
- Third-party import directive: not applicable.

Exact formal target block after implementation:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SelectObjectWithKeyboardPane::~SelectObjectWithKeyboardPane()
{
    s_activeSelectObjectWithKeyboardPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why it preserves original behavior:

- `s_activeSelectObjectWithKeyboardPane = NULL;` corresponds to the absolute zero store at `0x005af6fa`.
- Vtable restores at `0x005af6e0`, `0x005af6e6`, and `0x005af6f0` are compiler destructor output, not handwritten source.
- The tail jump to `sub_4F2010` is implicit base destructor cleanup in ordinary C++ source.
- The scalar deleting wrapper's free paths remain outside UID0001LC, as required by ordinary MSVC destructor/source shape.

Why it matches plausible original mid-2000s source shape:

- It uses a normal out-of-line class destructor.
- It uses `NULL`, consistent with accepted nearby constructor C++.
- It uses the accepted module-scope static singleton name rather than an IDA raw global.
- It avoids decompiler artifacts, vtable labels, explicit base destructor calls, wrapper flags, and storage-free code.

## Recommended Target Doc Changes

Target path: `by-memory/0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md`

Recommended edits:

- Change metadata to `COMPLETION:88`, `CONFIDENCE:91`; keep `CANONICAL_OWNER:0000CT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CT`, and blank `EMITTER_POSITION_OPTIONAL`.
- Replace the formal C++ block with the exact destructor block above.
- Replace stale `95/95 final-code threshold` wording with current combined-score/emitter-gate reasoning.
- Add current MCP session `c9671f69` and server-health proof.
- Update evidence with current exact bounds, bytes, padding, zero incoming xrefs, five-instruction disassembly, decompile, singleton xrefs, vtable xrefs, `callees` tail-jump caveat, scalar wrapper parity, and `int_convert`-verified numeric values where decimals are stated.
- Change prose from raw `dword_69BF60` as the source expression to `s_activeSelectObjectWithKeyboardPane` / `dword_69BF60` where discussing source shape, while preserving the IDA/raw name as evidence.
- Preserve rejected alternatives: explicit vtable stores, explicit base cleanup call, scalar-delete flag/free logic, LineInputPane ownership, file UID as direct owner, and singleton-slot page as method owner.

## Recommended Support Doc Changes

Support path: `by-class/SelectObjectWithKeyboardPane.md`

- Update the destructor row from raw "Resets vtables, clears `dword_69BF60`, and calls the base cleanup helper" to report-level detail: ordinary source destructor, formal first-draft C++ if accepted, clears provisional `s_activeSelectObjectWithKeyboardPane`, vtable restores and base cleanup are compiler/base destructor effects, scalar delete wrapper remains separate.
- Add an evidence/change note for B008 current MCP session `c9671f69` verifying UID0001LC exact range, no direct xrefs, singleton clear, tail jump, and source-body decision.
- Score change not recommended for the class page; current `87/88` remains appropriate because broader class/header/static declaration work still limits class-level finality.

Support path: `by-file/TargetSelectionInputPanes.md`

- Update the SelectObject source-route/proposed-contents row to include UID0001LC as a first-draft source destructor that clears `s_activeSelectObjectWithKeyboardPane`; record that generated output currently has UID0001LC as an empty marker before implementation and should lose that marker after the target validator refresh.
- Preserve [UID:0000OH] as the indirect source-file route, not direct owner of the destructor.
- Score change not recommended for the file page.

Support path: `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md`

- Add B008 current evidence that MCP session `c9671f69` reconfirmed `xrefs_to 0x0069bf60`: constructor writes at `0x005af637` and `0x005af63e`, UID0001LC clear at `0x005af6fa`, helper clear at `0x005b7620`, scalar clear at `0x005b7be0`, and UserPane gate read at `0x005a5f3a`.
- Note that UID0001LC's accepted destructor source should use `s_activeSelectObjectWithKeyboardPane = NULL;`.
- Score change not recommended; exact original static variable spelling/declaration initializer still cap the data page.

Comparison path: `by-memory/0x005b7bc0-0x005b7c1f.SelectObjectWithKeyboardPaneScalarDeletingDestructor.md`

- No support edit recommended in this report. Use it as comparison evidence only. It is a separate empty-emitter target and includes compiler delete-wrapper logic that should not be merged into UID0001LC.

## Score And Metadata Recommendation

- Current: `86/90`, owner `0000CT`, reconstructable `TRUE`, emitter `0000CT`, blank C++.
- Recommended: `88/91`, owner unchanged, reconstructable unchanged, emitter unchanged, formal destructor C++ populated.
- Reason higher: current MCP revalidated every assigned evidence point, exact bytes/padding, no-direct-xref status, vtable lifecycle refs, singleton xref set, base cleanup tail jump, scalar sibling parity, current generated empty-marker cause, and source-shape separation of ordinary destructor versus wrapper/compiler output.
- Reason not higher: `s_activeSelectObjectWithKeyboardPane` is still a provisional source-facing name, target-selection static declarations are not finalized, and the exact original class header/source split remains broader class/file work.
- Metadata fields to leave unchanged: `CANONICAL_OWNER:0000CT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CT`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`.

Score-limiting blockers researched:

- Stale C++ gate: resolved. Current gate permits first-draft C++.
- Raw singleton name: resolved to implementation-ready provisional `s_activeSelectObjectWithKeyboardPane`; exact original spelling remains a confidence cap only.
- Base cleanup source shape: resolved. It is implicit C++ destructor chaining, supported by [UID:00035Q] and sibling destructor precedent.
- Scalar-wrapper overlap: resolved. [UID:0001ND] is comparison evidence, not code to paste into UID0001LC.
- Range/padding: resolved. Exact target range is single and needs no split.

## Open Questions With Attempted Resolution

- Exact original name for `dword_69BF60`: not recovered. Evidence routes checked: current MCP xrefs, singleton support page, constructor implementation, class/file docs, and old reports. Best implementation-ready name is `s_activeSelectObjectWithKeyboardPane`; this caps confidence only.
- Exact destructor declaration placement in original headers: not recovered. Evidence routes checked: class/file docs and generated output route. This does not block the target C++ body because the existing class route already emits other `SelectObjectWithKeyboardPane` methods through `TargetSelectionInputPanes.cpp`.
- Whether [UID:0001ND] should get its own no-code/marker update: outside this UID0001LC report scope. This report explicitly uses [UID:0001ND] only as comparison evidence.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0001LC is exact function `sub_5AF6E0`, range `0x005af6e0-0x005af709`, size `0x29` / 41 bytes, with two-byte predecessor padding and seven-byte successor padding. | High | MCP `lookup_funcs`, `get_bytes`, `int_convert`; target page. | Target Status / Range / Evidence | incorporated | applied: target page now records exact range/size/padding/current MCP evidence; validator `000000000678` `ok:1`. |
| C2 | The function is a five-instruction non-deleting destructor: three vtable restores, singleton clear, and tail jump to `sub_4F2010`. | High | MCP `disasm`, `decompile`. | Target Evidence / Behavior / Access table | incorporated | applied: target Evidence, Behavior, and Access table record five-instruction disassembly/decompile and tail-jump caveat; validator `000000000678` `ok:1`. |
| C3 | `xrefs_to` / `xref_query` find zero incoming refs to `0x005af6e0`; this is expected destructor dispatch behavior, not a no-source blocker. | High | MCP `xrefs_to 0x005af6e0`, `xref_query 0x005af6e0`. | Target Evidence / Negative Evidence | incorporated | applied: target Evidence and Negative Evidence preserve zero incoming xrefs and no-source rejection; validator `000000000678` `ok:1`. |
| C4 | `0x0069bf60` is the active SelectObject singleton slot; source-facing name should be provisional `s_activeSelectObjectWithKeyboardPane`. | Medium-high | MCP `xrefs_to 0x0069bf60`; [UID:0002A2]; accepted [UID:0001LB]. | Target C++ / singleton support / class-file notes | incorporated | applied: target C++, class, file, and singleton support page use provisional `s_activeSelectObjectWithKeyboardPane`; validators `000000000678`, `000000000679`, `000000000680`, and `000000000681` `ok:1`. |
| C5 | The source destructor body should be exactly `s_activeSelectObjectWithKeyboardPane = NULL;`. | Medium-high | MCP singleton clear at `0x005af6fa`; constructor source precedent. | Target formal `RECONSTRUCTION_CPP CODE` | incorporated | applied: target formal C++ emits the exact destructor block; generated file after validation contains `SelectObjectWithKeyboardPane::~SelectObjectWithKeyboardPane()` with the singleton clear and no UID0001LC empty marker. |
| C6 | Vtable restores are compiler output and must not be emitted as source statements. | High | MCP disasm and vtable xrefs; constructor/scalar parity. | Target Reconstruction / Negative Evidence / class row | incorporated | applied: target/class notes exclude explicit vtable stores from source and keep them as compiler-output evidence; validators `000000000678` and `000000000679` `ok:1`. |
| C7 | `sub_4F2010` is base cleanup reached by tail jump; source C++ should rely on implicit base destructor chaining, not an explicit call. | High | MCP xref at `0x005af704`; [UID:00035Q]; ItemWho destructor precedent. | Target C++ rationale / Evidence | incorporated | applied: target/class/file notes record base cleanup as compiler/base destructor effect and reject explicit source call; validators `000000000678`, `000000000679`, and `000000000680` `ok:1`. |
| C8 | [UID:0001ND] repeats cleanup then adds scalar-delete flag/free paths; that logic belongs to the wrapper, not UID0001LC. | High | MCP disasm/decompile `0x005b7bc0`; [UID:0001ND]. | Target scalar parity notes; no [UID:0001ND] edit | incorporated / excluded-with-reason for scalar edit | applied: target/class/file notes preserve scalar-wrapper separation; [UID:0001ND] inspected for contradiction only and left unedited because no direct contradiction was found. |
| C9 | Current generated `TargetSelectionInputPanes.cpp` had UID0001LC as an empty marker under [UID:0000OH] before implementation. | High | Read-only generated file header command `000000000674`, `rg` line `889`; post-validator read-only generated file. | Target Reconstruction / checklist / file support | incorporated | applied: target/file docs record former empty-marker cause and expected marker removal; final observed generated header is command `000000000689` at `2026-06-29T12:12:03-04:00`, with UID0001LC destructor at lines 259-264 and no UID0001LC empty marker. |
| C10 | Old `95/95 final-code threshold` rationale is stale under current `by-structure.md`; UID0001LC clears the current combined-score/emitter gate. | High | `by-structure.md`; current metadata average `88`; generated marker. | Target Reconstruction / Changes | historicalized | applied: target Reconstruction and Changes replace stale threshold rationale with current combined-score/emitter-gate reasoning; validator `000000000678` `ok:1`. |
| C11 | Best owner remains [UID:0000CT] and source route remains [UID:0000OH] `TargetSelectionInputPanes.cpp`. | High | vtables, singleton, class/file docs, generated route. | Target Ownership / class/file support | already-present plus incorporated current proof | applied: owner/emitter metadata remains [UID:0000CT], source-file route remains [UID:0000OH], and class/file support docs record indirect route; validators `000000000678`, `000000000679`, and `000000000680` `ok:1`. |
| C12 | No split, rename, child creation, IDA DB edit, or manual coverage/tracker edit is required for this report. | High | Exact range/padding/current docs/workflow scope. | Implementation checklist | not-applicable | satisfied: no split/rename/child/IDA DB/manual coverage/tracker edit was performed; only scoped by-* docs and this Agent-B008 report were edited, generated C++ was inspected read-only. |

## Validator Results

Implementation callback validators were run from `source-3/project-documentation` after scoped edits:

| Target | Command ID | Timestamp | Result | Generated state / notes |
| --- | --- | --- | --- | --- |
| `by-memory/0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md` | `000000000678` | `2026-06-29T12:08:16-04:00` | `ok: 1`, exit code `0` | `--wait-generated` completed; `generated_refresh: completed`. Reported non-fatal existing `missing_ref_uid 00035Q`. |
| `by-class/SelectObjectWithKeyboardPane.md` | `000000000679` | `2026-06-29T12:09:43-04:00` | `ok: 1`, exit code `0` | `generated_refresh: deferred`; reported non-fatal existing `missing_ref_uid 00035Q`. |
| `by-file/TargetSelectionInputPanes.md` | `000000000680` | `2026-06-29T12:09:43-04:00` | `ok: 1`, exit code `0` | `generated_refresh: deferred`; final generated file was later observed at header command `000000000689`. |
| `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md` | `000000000681` | `2026-06-29T12:09:43-04:00` | `ok: 1`, exit code `0` | `generated_refresh: deferred`. |

Generated C++ read-only inspection after validation:

- File: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- Header: `validator-command-id: 000000000689`, `validator-refreshed-at: 2026-06-29T12:12:03-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- `rg` proof: UID0001LC appears at line `259`, `SelectObjectWithKeyboardPane::~SelectObjectWithKeyboardPane()` at line `260`, and the body contains `s_activeSelectObjectWithKeyboardPane = NULL;`.
- UID0001LC is no longer an `Empty Emitter Marker`; unrelated markers for other UIDs remain.

## Changed Files

Created during original report-only pass:

- `tools/leaser/Agents/Agent-B008/research/0001LC-SelectObjectWithKeyboardPaneDestructor-empty-emitter-source-quality.md`

Modified during implementation callback:

- `by-memory/0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md`
- `by-class/SelectObjectWithKeyboardPane.md`
- `by-file/TargetSelectionInputPanes.md`
- `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md`
- `tools/leaser/Agents/Agent-B008/research/0001LC-SelectObjectWithKeyboardPaneDestructor-empty-emitter-source-quality.md`

Inspected read-only, not manually edited:

- `by-memory/0x005b7bc0-0x005b7c1f.SelectObjectWithKeyboardPaneScalarDeletingDestructor.md`

Validator-generated refresh, not manually edited:

- `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`

Leases:

- Leased immediately before by-* edits: `by-memory/0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md`, `by-class/SelectObjectWithKeyboardPane.md`, `by-file/TargetSelectionInputPanes.md`, and `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md`.
- Released after edit/validator batch with `python .\tools\leaser\leaser.py B008 unlease`; output: `B008: No active leases`.
- Current lease report after release contains no B008 rows. It shows other agents' active leases only, including later B009 leases on shared class/file docs; no further by-* edits were made after B008 release.

## Implementation Tracking Checklist

- [x] Supervisor validation required before implementation. Proof: supervisor accepted UID0001LC for implementation callback in this turn.
- [x] Target [UID:0001LC] `by-memory/0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md`: update metadata `86/90 -> 88/91`; keep owner `0000CT`, reconstructable `TRUE`, emitter `0000CT`, blank optional emitter position, and `Nested:0`. Proof: validator `000000000678` `ok:1`.
- [x] Target [UID:0001LC]: replace formal `RECONSTRUCTION_CPP CODE` with the exact destructor block from this report. Proof: validator `000000000678` `ok:1`; generated lines 259-264 emit the destructor.
- [x] Target [UID:0001LC]: replace stale `95/95` blank-C++ rationale with current combined-score/emitter-gate reasoning and generated empty-marker cause. Proof: target validator `000000000678` `ok:1`.
- [x] Target [UID:0001LC]: incorporate current MCP session `c9671f69`, server-health state, exact range, function size, bytes, padding, no incoming xrefs, five-instruction disassembly, decompile, singleton xrefs, vtable xrefs/cells, `callees` tail-jump caveat, scalar sibling parity, and `int_convert`-verified numeric conversions. Proof: target Evidence Notes and validator `000000000678` `ok:1`.
- [x] Target [UID:0001LC]: preserve rejected alternatives and negative evidence: raw IDA global in source, explicit vtable stores, explicit base cleanup call, scalar-delete/free logic, LineInputPane ownership, file UID as direct owner, singleton-slot page as method owner, and IDA DB edits. Proof: target Negative Evidence section and validator `000000000678` `ok:1`.
- [x] [UID:0000CT] `by-class/SelectObjectWithKeyboardPane.md`: update destructor row/evidence notes to use provisional `s_activeSelectObjectWithKeyboardPane = NULL`, first-draft destructor readiness, compiler/base cleanup caveat, and scalar-wrapper separation; leave class score unchanged unless supervisor expands scope. Proof: validator `000000000679` `ok:1`; score unchanged.
- [x] [UID:0000OH] `by-file/TargetSelectionInputPanes.md`: update SelectObject proposed-contents/source-route text to include UID0001LC as first-draft source destructor clearing `s_activeSelectObjectWithKeyboardPane`; preserve indirect file route and current/expected generated marker state; leave file score unchanged. Proof: validator `000000000680` `ok:1`; score unchanged.
- [x] [UID:0002A2] `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md`: add B008 current MCP xref evidence for `0x0069bf60` and note UID0001LC source destructor uses `s_activeSelectObjectWithKeyboardPane = NULL`; leave data-page score and blank declaration C++ unchanged. Proof: validator `000000000681` `ok:1`; score and blank C++ unchanged.
- [x] [UID:0001ND] `by-memory/0x005b7bc0-0x005b7c1f.SelectObjectWithKeyboardPaneScalarDeletingDestructor.md`: inspect during callback only for contradiction; no planned edit because this report uses it as comparison evidence and scalar-wrapper C++ remains separate. Proof: inspected read-only; no direct contradiction found, so no edit.
- [x] Claim And Incorporation Ledger: update every accepted claim from `proposed` to `applied`, `already-present`, or `excluded-with-reason` during implementation callback, with proof. Proof: ledger above updated after validators and generated inspection.
- [x] Run scoped validators from `source-3/project-documentation` after edits:
  - `python .\tools\validator.py --mode file --file by-memory\0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class\SelectObjectWithKeyboardPane.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\TargetSelectionInputPanes.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md --apply --queue-timeout 240`
- [x] Inspect generated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` read-only after the target validator with `--wait-generated`: UID0001LC should no longer be an `Empty Emitter Marker` and should contain `SelectObjectWithKeyboardPane::~SelectObjectWithKeyboardPane()` under [UID:0001LC]. Other unrelated empty markers may remain. Proof: final observed header command `000000000689`; UID0001LC at line 259, destructor at line 260, no UID0001LC empty marker.
- [x] Manual coverage/tracker action: none. Do not edit generated files, generated reports, manual `-coverage-report.md`, project-level generated files, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files. Supervisor/validator execution can refresh generated tracker state after verification. Proof: no manual edits to prohibited files; generated C++ read-only only.
- [x] Leases during implementation callback only: take short leases only for immediate target/support edits, release immediately after edit/validator batch, and record proof. Proof: four by-* files leased before edits; `python .\tools\leaser\leaser.py B008 unlease` returned `B008: No active leases`; current lease report has no B008 rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0001LC-SelectObjectWithKeyboardPaneDestructor-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0001LC-SelectObjectWithKeyboardPaneDestructor-empty-emitter-source-quality.md","timestamp":"2026-06-29T12:16:08","uid":"0001LC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
