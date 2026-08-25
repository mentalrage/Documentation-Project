** TARGET-REPORT-UID:0004E5 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004E5 PrettyButtonControlPane State-Byte Virtual Forwarder Source-Quality Report

## Finalized Report / Current Recommendation

Current recommendation: promote [UID:0004E5] `by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md` from a reconstructable non-emitter to an emitting `PrettyButtonControlPane` method child through [UID:0000AR].

Final disposition: source-authored small setter/refresh method, not a compiler artifact and not a no-code exception. The best source-facing method is `PrettyButtonControlPane::SetSelected(bool selected)`: the target stores the selected/pressed-state byte at `this+0x118`, then invalidates the inherited pane bounds through virtual slot `+0x20` with a null rectangle argument.

Required action after supervisor Gate 1: update UID0004E5 to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000AR`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AR`, and insert the formal C++ block below. Synchronize concise support evidence into `by-class/PrettyButtonControlPane.md` and `by-file/PrettyButtonControlPane.md`. Parent/vtable/class2 docs need no required metadata change.

Confidence: high for behavior, owner, route, and source placement. Remaining uncertainty is limited to exact original member spelling (`m_selected` versus a similar selected/pressed name) and whether the original source used `InvalidateRect(NULL)` directly or a small inherited wrapper such as `Invalidate()`.

## Supporting Research

This is a report-only pass. No by-* docs, generated files, coverage reports, validator state, lifecycle state, archive files, or supervisor files were edited.

B014 used the project `ntk-b-agent-workflow` skill and followed the `by-structure.md` IDA MCP Output Discipline. MCP calls were narrow and exact-address/capped: active schema was checked, then exact `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `get_bytes`, `callees`, and small caller-slot checks were used.

Historical report search was performed before finalizing. The only directly relevant prior B-agent report found was executed B011 report `executed-b-agent-research/B011/0001F9-PrettyButtonControls-source-quality.md`; it created/split UID0004E5 and recommended owner/emitter UID0000AR at the parent inventory level, but left the child C++ blank pending this narrower source-quality pass. Accepted B004 report evidence for `NewUserDialogPane2` was also relevant because it already uses `GetShapeSelectControl(...)->SetSelected(...)` for the caller-family source shape that reaches this button-state forwarder.

## Target

- Target UID: `0004E5`.
- Target path: `by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md`.
- Report path: `tools/leaser/Agents/Agent-B014/research/0004E5-PrettyButtonControlPaneStateByteVirtualForwarder-source-quality.md`.
- Assignment: `B014-report-0004E5-PrettyButtonControlPaneStateByteVirtualForwarder-20260702`.
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Queue row at assignment: `84/88`, average `86.0`, reconstructable `true`, B reports `0`.

## Current Target State

UID0004E5 currently has `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, and blank formal C++. Its current text says B011 MCP found modeled function `0x0054b700` size `0x19`, with `mov [ecx+118h], al`, stack-argument clear, and a tail jump through `[eax+20h]`.

The current blocker says formal C++ and emitter route remain blank until the virtual slot name and field name are accepted. This report resolves that blocker far enough for first-draft source: slot `+0x20` is the inherited `Pane::InvalidateRect` path, the null argument is the whole-bounds fallback, and the field is the selected/pressed-frame byte used by `PrettyButtonControlPane::OnPaint`.

Current generated lead state: `auto-generated/-ag-memory-coverage.md` lists UID0004E5 as `non-emits` with owner `0000AR`; `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` currently contains only UID0004EM/UID0004EL comment-only scalar destructor markers plus class/vtable empty markers, not UID0004E5 emitted C++.

## Executive Recommendation

Emit UID0004E5 through [UID:0000AR][PrettyButtonControlPane]. Do not move it to the parent split page, `PrettyButtonControlPane.cpp` directly, CreateUser dialog classes, `Pane`, or `ButtonControlPane`.

Recommended source-facing method: `void PrettyButtonControlPane::SetSelected(bool selected)`.

Recommended field name for this target/support text: `m_selected` at `this+0x118`, with a caveat that the exact original spelling is inferred. Rejected names: raw `stateByte`, `m_enabled`, and `m_hovered`; `m_enabled` is already associated with `this+0x101`, while `this+0x119` is the hover/animation state checked before `this+0x118` in paint.

## Supervisor Active Recheck

The current supervisor/user instruction requires report-only research for UID0004E5, no by-* edits, no generated/project-level/coverage/tool/supervisor edits, no lifecycle/archive/execute-report command, no subagents, and narrow schema-current MCP calls. Those constraints were followed.

This item does not require a new split. It is already an exact modeled by-memory child from B011's UID0001F9 split. The remaining work is source-quality resolution: emitter route, method/field/slot naming, score, and support-doc synchronization.

## Inference Research Guidance Check

IDA/MCP facts used directly: function boundary, bytes, decompilation, disassembly, xrefs, caller snippets, vtable data refs, and inherited slot behavior. Documentation evidence used: current by-* target/support docs, B011 executed report, B004 executed NewUserDialogPane2 report, generated coverage/autogen leads, and sibling PrettyButton child pages. Inference used: the source-facing names `SetSelected` and `m_selected`.

No Wave2/Wave3 material was used as authority. Any generated/autogen material was treated as lead state only and checked against MCP or durable by-* docs.

## Heuristic / Inference Reanalysis And Validation

The old blocker "blank until virtual slot name and field name are accepted" is no longer strong enough to justify a non-emitter. Current MCP and accepted support reports resolve the slot as inherited `Pane::InvalidateRect`; the target passes a null rectangle, and accepted FolderTree/Browser evidence elsewhere in the docs models this family as `InvalidateRect(NULL)` or `InvalidateRect(0)`, not `Invalidate(false)`.

The state-byte field is no longer just a raw byte. MCP `analyze_function 0x0054b7c0` shows paint checks `this+0x119` first for the hover/animation frame, then `this+0x118` for the selected/pressed frame, then the normal frame. MCP caller snippets show create-user dialog selection helpers write selected option fields and call this target with `1` on the selected PrettyButton control. B004's accepted NewUserDialogPane2 source shape already names the source action `GetShapeSelectControl(8 + i)->SetSelected(i == slot)`.

`SetPressed` was considered but rejected as too narrow: callers use this for selected nation/totem/shape controls, not mouse-down-only behavior. `SetChecked` was considered but rejected because current project UI source/report language uses selected controls and selected slots rather than checkbox semantics. `SetSelected` is the best source-facing name.

`Invalidate()` was considered as a readable wrapper but rejected for the formal C++ because the binary dispatches slot `+0x20` with an explicit zero stack argument. Existing support docs identify slot `+0x20` as `Pane::InvalidateRect`, and accepted B011 FolderTree evidence explicitly rejects `Invalidate(false)` for this exact null-rectangle pattern.

## Evidence Standards Used

Evidence was considered sufficient because three independent routes agree: exact MCP behavior for UID0004E5, vtable/slot evidence for the inherited invalidation routine, and caller/source-family evidence from create-user dialog split reports. Confidence remains below final audit because exact original member spelling is inferred from behavior rather than recovered from symbols or source.

## Evidence Checked

- Read assignment `tools/leaser/Agents/Agent-B014/goal.md`.
- Read `ntk-b-agent-workflow/SKILL.md`, `references/b-agent-research-and-implementation-workflow.md`, `references/b-agent-report-template.md`, `references/score-blocker-audit-standard.md`, and `by-structure.md` IDA MCP Output Discipline.
- Read target UID0004E5.
- Read support docs: UID0001F9 parent, `by-class/PrettyButtonControlPane.md`, `by-file/PrettyButtonControlPane.md`, `by-class/PrettyButtonControlPane2.md`, UID0002UW/UID0002UX vtable pages, UID0004E3 constructor, UID0004E6 callback setter, UID0004E7 visual-state setter, UID0004E8 paint, and UID0004EC class2 counterpart.
- Searched current and executed B-agent materials for `0004E5`, `0x0054b700`, `0054b700`, `PrettyButtonControlPaneStateByteVirtualForwarder`, `PrettyButtonControls`, and class/source-family terms. Relevant report found: B011 UID0001F9. No separate prior UID0004E5 report was found.
- Checked generated leads: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- MCP session: `b011_0004EC_20260702`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` MCP id `102` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, imagebase `0x400000`.
- MCP id `103` `lookup_funcs`: `0x0054b700 -> sub_54B700 size 0x19`; `0x0054b719`, `0x0054b6fb`, and `0x0054b9e0` are not functions; `0x0054b720 -> sub_54B720 size 0x24`.
- MCP id `104` `analyze_function 0x0054b700`: prototype `int __thiscall(_BYTE *this, char)`, decompile writes `this[280] = a2`, then calls `(*this->vftable + 32)(this, 0)`; 42 code xrefs to the target and one internal from-edge.
- MCP id `222` `decompile 0x0054b700`: `this[280] = a2; return (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 32))(this, 0);`.
- MCP id `223` `disasm 0x0054b700`, cap 23: full 8-instruction function: prologue, load argument byte, store `[ecx+118h]`, load vtable, write stack arg zero, pop, and `jmp dword ptr [eax+20h]`; total instructions `8`.
- MCP id `107` `xrefs_to`: 42 code xrefs to `0x0054b700`; class1 vtable bases `0x006222d8`, `0x00622340`, and `0x00622370` each have three constructor/destructor store xrefs; `0x00622320` has no incoming xrefs because it is a vtable cell holding `0x0054b750`.
- MCP id `108` `xref_query`: target xrefs include `sub_52A540`, `sub_52B310`, `sub_52B3A0`, `sub_52B530`, `sub_52B5C0`, `sub_52C360`, `sub_52CEF0`, `sub_52CF80`, `sub_52D060`, `sub_52D0B0`, `sub_52E770`, `sub_52E850`, and `sub_52E8C0`; `0x00622320` has one data-from entry to `0x0054b750`.
- MCP id `109` `get_bytes`: UID0004E5 bytes are `55 8b ec 8a 45 08 88 81 18 01 00 00 8b 01 c7 45 08 00 00 00 00 5d ff 60 20`; leading/trailing local checks show `0xcc` padding before and after the function.
- MCP id `110` `callees 0x0054b700`: no direct static callees, consistent with the indirect tail jump.
- MCP ids `302`, `303`, and `304` caller snippets: direct calls at `0x0052ac23`, `0x0052add9`, and `0x0052c899` are preceded by `push 1` after storing selected option fields such as `m_selectedNation`/`m_selectedTotem` or equivalent selection data.
- MCP ids `332`-`335` `0x00544800`: `lookup_funcs` says size `0xac`; analysis/decompile show the inherited invalidation path, where nonzero argument uses that rect and zero argument falls back to `this+0x44`; xrefs include `0x006222f8`, the `PrettyButtonControlPane` primary vtable slot at offset `+0x20`.
- MCP ids `362`-`364`: `PrettyButtonControlPane::OnPaint` reads `this+0x119` first, then `this+0x118`, choosing frame fields at `+272`, `+276`, or `+268`; `PrettyButtonControlPane::SetVisualState` manages `this+0x119` and the hover/animation helper calls, distinguishing it from UID0004E5's selected-state byte.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004E5-01 | UID0004E5 is an exact modeled 25-byte function at `0x0054b700-0x0054b719`. | High | MCP `lookup_funcs` id `103`; `disasm` id `223`; bytes id `109`. | Target `Evidence` / `IDA MCP Facts` | incorporate | applied: target `Evidence` records modeled size, disasm, exact bytes, and padding; validator `000000004957` ok. |
| C-0004E5-02 | The body stores argument byte to `this+0x118` and tail-jumps through inherited vtable slot `+0x20` with a null rectangle argument. | High | MCP `analyze_function` id `104`; `decompile` id `222`; `disasm` id `223`. | Target `Evidence` / formal C++ notes | incorporate | applied: target `Evidence`, item summary, C++ block, and `Ownership And C++ Policy` record the store and inherited invalidation tail call; validator `000000004957` ok. |
| C-0004E5-03 | Vtable slot `+0x20` resolves to inherited `Pane::InvalidateRect`, with null argument fallback to `this+0x44` bounds. | High | MCP `analyze_function/decompile/disasm 0x00544800` ids `333`-`335`; existing Pane-slot reports. | Target C++ notes; class/file support evidence | incorporate | applied: target, class support, and file support document inherited `Pane::InvalidateRect(NULL)`; validators `000000004957`, `000000004981`, and `000000004985` ok. |
| C-0004E5-04 | `this+0x118` is the selected/pressed-frame byte, while `this+0x119` is hover/animation state. | Medium-high | MCP `OnPaint` ids `362`-`363`; `SetVisualState` id `364`; caller snippets ids `302`-`304`. | Target naming notes; class method table | incorporate | applied: target naming notes and class/file method inventory record `+0x118` as selected/pressed-frame byte and preserve the `+0x119` distinction; validators passed. |
| C-0004E5-05 | Best source-facing method name is `PrettyButtonControlPane::SetSelected(bool selected)`. | Medium-high | B004 accepted source shape uses `SetSelected`; current callers set selected option state and call target; paint consumes selected frame. | Target formal C++; class/file docs | incorporate | applied: formal target C++ inserted and class/file support rows now name `SetSelected(bool selected)`; validators passed. |
| C-0004E5-06 | UID0004E5 should emit through [UID:0000AR], not remain non-emitting. | High | B011 parent inventory already routed child owner/emitter UID0000AR; current method source name/slot/field blocker resolved. | Target metadata; generated route via class/file | incorporate | applied: target metadata now has `EMITTER_UIDS:0000AR`; class/file support record source-ready emission through UID0000AR. |
| C-0004E5-07 | `SetPressed`, `SetChecked`, raw `stateByte`, `m_enabled`, and `m_hovered` are weaker names. | Medium-high | Callers are selection helpers; `m_enabled` is `this+0x101`; `m_hovered`/animation byte is `this+0x119`. | Target negative evidence / support notes | incorporate | applied: target `Ownership And C++ Policy`, class evidence note, and file evidence note preserve rejected-name analysis. |
| C-0004E5-08 | Class2 counterpart UID0004EC remains comparison evidence only for this callback unless supervisor also assigns it. | Medium | UID0004EC is unmodeled raw counterpart at `this+0x11c`; current assignment target is class1 UID0004E5. | Optional support docs if touched | not-applicable | already-present/excluded-with-reason: B011 concurrently applied accepted UID0004EC class2 details to the file page; this callback did not edit UID0004EC target/class2 docs. |

## Positive Evidence Summary

The target is small, bounded, and source-shaped: one field write plus one invalidation dispatch. It is not a destructor, thunk, vtable data item, padding, or mixed aggregate. It is reached by many create-user selection paths and belongs to the `PrettyButtonControlPane` class whose constructor, paint, click, callback, and vtable docs already sit under [UID:0000AR]/[UID:0000MP].

The source-facing `SetSelected` name is supported by the caller family. Existing accepted NewUserDialogPane2 source C++ uses `GetShapeSelectControl(8 + i)->SetSelected(i == slot)`, and MCP caller snippets show `push 1` before calls to UID0004E5 after writing selected-option state. Paint reads the target byte to choose the selected/pressed frame.

## IDA MCP Facts

- Function/range: `0x0054b700`, `sub_54B700`, size `0x19`, total 8 instructions.
- Bytes: `55 8b ec 8a 45 08 88 81 18 01 00 00 8b 01 c7 45 08 00 00 00 00 5d ff 60 20`.
- Decompile: `this[280] = a2;` then indirect dispatch through `(*(_DWORD *)this + 32)` with argument `0`.
- Xrefs: 42 code xrefs to the target, mainly from create-user selection/setup helpers.
- Vtable: `0x006222f8` is class1 primary vtable slot `+0x20` and holds `0x00544800`.
- Slot target: `0x00544800` is inherited invalidation; null argument falls back to `this+0x44`.
- Negative IDA facts: no static callees from UID0004E5; class2 counterpart `0x0054b9e0` is not modeled as a function; padding before/after UID0004E5 is `0xcc`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0054b700-0x0054b719` | [UID:0004E5] `by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md` | `PrettyButtonControlPane::SetSelected(bool selected)` | TRUE | [UID:0000AR] | recommend `88/91` | emit through [UID:0000AR] |
| `0x0054b9e0-0x0054b9f9` | [UID:0004EC] `by-memory/0x0054b9e0-0x0054b9f9.PrettyButtonControlPane2StateByteVirtualForwarder.md` | class2 analogue | TRUE | [UID:0000AS] | unchanged | comparison only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0052ac23` | `sub_52A540` snippet: store selected field, `push 1`, call UID0004E5 | NewUserDialogPane2 setup/select path marks a PrettyButton selected. |
| `0x0052add9` | `sub_52A540` snippet: store selected field, `push 1`, call UID0004E5 | Second selected button in same constructor/setup family. |
| `0x0052c899` | `sub_52C360` snippet: random/selected option state, `push 1`, call UID0004E5 | NewCreateUserDialogPane retained variant uses the same control method. |
| `0x006222f8` | data xref to `0x00544800` from class1 primary vtable slot `+0x20` | UID0004E5's tail jump reaches inherited invalidation. |

## Documentation Evidence And IDA Status

Current target text is accurate but under-specific: it names the state-byte/slot facts, but keeps emitter/formal C++ blank. Current class/file support docs already route the child through PrettyButton ownership and source placement, but they still describe the target as a generic state-byte forwarder.

B011 UID0001F9 parent report is mostly already-present support. It split this child and said `0x0054b700-0x0054b719` owner/emitter UID0000AR in the recommended inventory. This report adds the missing target-level source-quality proof needed to actually populate the child emitter and formal C++.

Generated reports are lead evidence only. They currently show UID0004E5 as a reconstructable non-emitter, which is exactly the source-quality issue this report resolves.

## Ranked Ownership Analysis

### 1. [UID:0000AR] PrettyButtonControlPane

Evidence for: class1 constructor installs the class1 vtable set; vtable page UID0002UW records class1 slots; UID0004E5 writes a class1 field consumed by class1 paint; current target owner is already `0000AR`; B011 split inventory routes this child to UID0000AR.

Evidence against: exact original member names are inferred, not symbol-proven.

Decision: best direct owner and emitter.

### 2. [UID:0000MP] PrettyButtonControlPane.cpp

Evidence for: source file contains both PrettyButton classes and will be the generated source root through class emitters.

Evidence against: bypasses the narrower class owner. The target is a class method, not a file-local free helper.

Decision: keep as file/source placement support, not direct owner.

### 3. CreateUser dialog classes/files

Evidence for: many direct callers are create-user dialog setup/selection functions.

Evidence against: those are consumers. The method mutates PrettyButtonControlPane state, uses PrettyButtonControlPane layout/vtable, and is shared across dialog variants.

Decision: rejected as owner; useful caller/source-use evidence only.

### 4. Pane / ButtonControlPane

Evidence for: UID0004E5 dispatches inherited slot `+0x20`, and PrettyButton constructors call base `ButtonControlPane`.

Evidence against: base classes supply dependencies, not the selected-state field at `this+0x118` or the PrettyButton paint frame choice.

Decision: rejected as owner; `Pane::InvalidateRect` should be cited as inherited callee behavior.

## Source Placement

Recommended source placement: `NexusTK/ui/controls/PrettyButtonControlPane.cpp`, under the `PrettyButtonControlPane` class.

This fits the current by-file page, current class docs, vtable pages, B011 split, and generated source root. It also matches the UI controls subsystem: the method is reusable styled-button state, even when called by create-user dialog code.

Rejected placements: `login/NewUserDialogPane2.cpp` and `login/NewCreateUserDialogPane.cpp` are callers only; `Pane.cpp` / `ButtonControlPane.cpp` provide inherited/base behavior only.

## Range / Split / Padding / Reclassification Analysis

No new split is required. The exact child already covers `0x0054b700-0x0054b719`; MCP bytes show `0xcc` padding from `0x0054b6fb-0x0054b700` and `0x0054b719-0x0054b720`. `lookup_funcs` confirms the endpoint and neighboring callback setter function at `0x0054b720`.

Reclassification is metadata/emitter-only: keep reconstructable true and owner `0000AR`, add emitter `0000AR`, and add formal C++.

## Negative Evidence Summary

Do not leave the target blank merely because field names are not symbol-proven. The remaining uncertainty is ordinary inferred member spelling, not a behavior blocker. The body is short enough, source-shaped enough, and caller-supported enough for an emitting first draft.

Do not use decompiler-shaped source such as `this[280] = selected; return (*(fn)(...))(this, 0);`. The report must preserve the binary details as evidence but emit source-facing C++ through `m_selected` and inherited invalidation.

Do not model the invalidation call as `Invalidate(false)`. The argument is a null rectangle pointer to slot `+0x20`, not a boolean flag. `InvalidateRect(NULL)` is the clearest accepted source-facing spelling for this exact pattern.

## IDA Rename / Type / Comment Recommendations

No IDA database edit is requested.

Suggested documentation/source-facing names:

- `sub_54B700`: `PrettyButtonControlPane::SetSelected`.
- `this+0x118`: `m_selected`, with caveat "selected/pressed-frame byte".
- `0x00544800`: inherited `Pane::InvalidateRect`.

Rejected names:

- `SetStateByte`: too raw for source.
- `SetPressed`: too mouse-state-specific for selection callers.
- `SetChecked`: checkbox-specific and not used by surrounding create-user docs.
- `m_enabled`: conflicts with existing enabled byte evidence at `this+0x101`.
- `m_hovered`: conflicts with `this+0x119` hover/animation state.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Recommended exact formal `RECONSTRUCTION_CPP CODE` insertion for UID0004E5:

```cpp
void PrettyButtonControlPane::SetSelected(bool selected)
{
    m_selected = selected;
    InvalidateRect(NULL);
}
```

Reason it preserves exact original behavior: the compiler can lower the bool argument to the byte store at `this+0x118`; the final call maps to inherited vtable slot `+0x20` with a null rectangle argument, which `Pane::InvalidateRect` resolves to this pane's bounds.

Reason it matches plausible mid-2000s source: it is a simple member setter used by UI selection code, uses `bool`, uses `NULL` rather than modern `nullptr`, and avoids decompiler pointer syntax. The method name aligns with accepted `NewUserDialogPane2` source shape calling `SetSelected`.

Inferred names: `m_selected` and `InvalidateRect`. Both are evidence-backed but not original-symbol-proven; target/support docs should preserve that caveat.

## Final Recommendation

Update UID0004E5 metadata to `88/91`, keep `CANONICAL_OWNER:0000AR`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AR`, and insert `PrettyButtonControlPane::SetSelected(bool selected)` formal C++.

Support docs should preserve fresh MCP facts and rejected-name analysis without over-expanding the class/file pages. Class/file scores can remain unchanged unless the supervisor wants a small support-score bump for resolving one child emitter.

## Recommended Target Doc Changes

Target path: `by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md`.

Recommended changes:

- Metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AR`.
- Item summary: rename/describe as exact `PrettyButtonControlPane::SetSelected(bool selected)` child that writes selected byte `this+0x118` and invalidates through inherited `Pane::InvalidateRect(NULL)`.
- Evidence: add current MCP session `b011_0004EC_20260702`, health, lookup, decompile/analyze/disasm/bytes, xrefs, slot target, caller snippets, and OnPaint/SetVisualState field distinction.
- C++ policy: replace blank-emitter blocker with formal C++ and source-quality notes. Preserve caveat that `m_selected` is inferred, while raw vtable-tail syntax and raw `this[280]` source are rejected.

## Recommended Support Doc Changes

- `by-class/PrettyButtonControlPane.md`: update the method row from generic "State-byte forwarder" to `SetSelected` / selected-frame byte setter; add concise evidence that `this+0x118` selects the pressed/selected frame in `OnPaint`, slot `+0x20` is inherited `Pane::InvalidateRect(NULL)`, and callers in create-user selection paths use it. No required class score change.
- `by-file/PrettyButtonControlPane.md`: add a concise source-route note that UID0004E5 is ready to emit through `PrettyButtonControlPane` as `SetSelected(bool)`, supporting the existing `NexusTK/ui/controls/PrettyButtonControlPane.cpp` route. No required file score/path change.
- `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`: optional only. It already records UID0004E5 owner/emitter UID0000AR in B011 inventory and can be left unchanged unless the supervisor wants a short note that the child source method is now `SetSelected`.
- `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`: optional only. Existing slot evidence is sufficient; add `0x006222f8 -> 0x00544800 Pane::InvalidateRect` only if support detail is desired.
- `by-memory/0x0054b9e0-0x0054b9f9.PrettyButtonControlPane2StateByteVirtualForwarder.md` and `by-class/PrettyButtonControlPane2.md`: do not edit for this callback unless the supervisor explicitly wants counterpart synchronization; class2 remains comparison evidence.

## Score And Metadata Recommendation

Recommended UID0004E5 metadata:

- `COMPLETION:88` from current `84`.
- `CONFIDENCE:91` from current `88`.
- `CANONICAL_OWNER:0000AR` unchanged.
- `RECONSTRUCTABLE:TRUE` unchanged.
- `EMITTER_UIDS:0000AR` from blank.

Score rationale: completion rises because the prior source-quality blocker is resolved with current MCP slot/field/caller proof and formal C++; confidence rises because exact behavior and owner are strongly verified. Do not raise higher than `91` because the exact original field name and method spelling are inferred from behavior and caller source shape rather than recovered symbols.

Score-improvement attempt: investigated MCP exact function/bytes/decompile/disasm, caller xrefs, inherited slot target, paint consumption of the field, visual-state sibling distinction, class/file/vtable docs, B011 parent split, B004 caller-family source names, and generated non-emitter state. Result: enough evidence for emission, not enough for final-audit naming confidence.

## Open Questions With Attempted Resolution

- Exact original method spelling: best current answer is `SetSelected`. Evidence checked: B004 accepted source, caller snippets, paint frame choice, and surrounding selected-option names. Remaining risk: original could have used a near-synonym such as `SetPressed` or `SetChecked`; rejected as weaker for current source family.
- Exact field spelling: best current answer is `m_selected`. Evidence checked: paint `this+0x118` path, caller selection role, sibling `this+0x119` hover state, enabled byte distinction. Remaining risk: original could have used `m_pressed` or `m_bSelected`; keep caveat in docs.
- Exact invalidation wrapper: best current answer for formal C++ is `InvalidateRect(NULL)`. Evidence checked: slot target decompile and accepted Pane-slot reports. Remaining risk: original code might have used a zero-argument wrapper; formal source should prefer the proven inherited API spelling.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Do not manually edit validator-owned generated reports or coverage reports. Validator/autogen should update UID0004E5 from non-emits to emitted after a later accepted implementation callback and scoped validation.

## Follow-Up Actions

Supervisor Gate 1 should validate this report. If accepted, the implementation callback should edit only the target and required support docs, then run scoped validators for changed by-* files.

## Confidence

Recommendation confidence: high. Score confidence: high for `88/91`. Remaining uncertainty is naming exactness, not behavior, owner, range, or emitter route.

## Validator Results

Report-only pass commands: none.

Implementation callback validators:

- `python .\tools\validator.py --mode file --file by-memory\0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md --apply --queue-timeout 240`
  - command_id: `000000004957`
  - command_timestamp: `2026-07-03T01:53:36-04:00`
  - exit code: `0`
  - ok: `1`
  - generated_refresh: `deferred`
- `python .\tools\validator.py --mode file --file by-class\PrettyButtonControlPane.md --apply --queue-timeout 240`
  - command_id: `000000004981`
  - command_timestamp: `2026-07-03T02:02:06-04:00`
  - exit code: `0`
  - ok: `1`
  - generated_refresh: `deferred`
- `python .\tools\validator.py --mode file --file by-file\PrettyButtonControlPane.md --apply --queue-timeout 240`
  - command_id: `000000004985`
  - command_timestamp: `2026-07-03T02:07:19-04:00`
  - exit code: `0`
  - ok: `1`
  - generated_refresh: `deferred`

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B014/research/0004E5-PrettyButtonControlPaneStateByteVirtualForwarder-source-quality.md`

Modified during implementation callback:

- `by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md`
- `by-class/PrettyButtonControlPane.md`
- `by-file/PrettyButtonControlPane.md`
- `tools/leaser/Agents/Agent-B014/research/0004E5-PrettyButtonControlPaneStateByteVirtualForwarder-source-quality.md`

Report execution: not run. B014 did not run `execute_report`, any execute-report variant, registry lifecycle command, manual report move, or archive command.

## Implementation Tracking Checklist

Accepted report checklist disposition:

- [x] Supervisor validation required before implementation. Proof: accepted callback is recorded in `goal.md`, 2026-07-03.
- [x] Update target UID0004E5 metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000AR`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AR`. Proof: target metadata updated and validator `000000004957` confirmed completion/confidence/emitter updates.
- [x] Insert formal C++:
  `void PrettyButtonControlPane::SetSelected(bool selected) { m_selected = selected; InvalidateRect(NULL); }`
  Proof: target formal `RECONSTRUCTION_CPP CODE` block populated; validator `000000004957` ok.
- [x] Add target MCP evidence from session `b011_0004EC_20260702`: health id `102`, lookup id `103`, analyze id `104`, decompile id `222`, disasm id `223`, xrefs ids `107`/`108`, bytes id `109`, slot target ids `332`-`335`, caller snippets ids `302`-`304`, and OnPaint/SetVisualState ids `362`-`364`. Proof: target `Evidence` section now records each accepted evidence group.
- [x] Replace the stale blank-C++ blocker with source-quality caveats: `m_selected` and `SetSelected` are inferred; raw vtable-tail/decompiler syntax, `SetPressed`, `SetChecked`, `m_enabled`, and `m_hovered` are rejected for this target. Proof: target `Ownership And C++ Policy`, class support note, and file support note preserve caveats/rejections.
- [x] Update `by-class/PrettyButtonControlPane.md` with concise `SetSelected` method/field/slot/caller support evidence; no class score change required unless supervisor requests one. Proof: class method row, child row, evidence note, and change note updated; no class metadata score change by B014; validator `000000004981` ok.
- [x] Update `by-file/PrettyButtonControlPane.md` with concise source-route evidence that UID0004E5 now emits through `PrettyButtonControlPane` under `NexusTK/ui/controls/PrettyButtonControlPane.cpp`; no path change required. Proof: file split inventory, source-output paragraph, evidence note, score rationale, and change note updated; no file path/metadata change by B014; validator `000000004985` ok.
- [x] Treat UID0001F9 parent, UID0002UW vtable data, UID0004EC class2 counterpart, and `by-class/PrettyButtonControlPane2.md` as already-present/optional support unless current text lacks same-or-greater detail at callback time. Proof: parent/vtable/class2 files were not edited; B011 concurrently applied UID0004EC file-level details, and this callback excluded counterpart target/class2 edits as out of scope.
- [x] Run scoped file validators only after supervisor implementation callback for every changed by-* doc; at minimum validate UID0004E5 target with `python .\tools\validator.py --mode file --file by-memory\0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md --apply --queue-timeout 240`. Proof: validators `000000004957`, `000000004981`, and `000000004985` ran with exit code 0 and `ok: 1`.
- [x] Record validator command id, timestamp, exit code, ok/warnings, generated refresh state, changed files, leases used/released, and any unapplied accepted item in the implementation callback response. Proof: recorded in `Validator Results`, `Changed Files`, checklist, and final response; no unapplied accepted items remain.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: `goal.md` callback dated 2026-07-03 says Gate 1 passed and accepts UID0004E5 disposition.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target `by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md`, support `by-class/PrettyButtonControlPane.md`, and support `by-file/PrettyButtonControlPane.md` updated; optional parent/vtable/class2 support left already-present or out of scope.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: ledger rows above now use `applied`, `already-present`, or `excluded-with-reason` proof.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: target now has `COMPLETION:88`, `CONFIDENCE:91`, unchanged `CANONICAL_OWNER:0000AR`, unchanged `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AR`, and formal `PrettyButtonControlPane::SetSelected(bool selected)` C++.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/class/file docs now reject blank-C++ blocker, raw vtable-tail source, `SetPressed`, `SetChecked`, raw `stateByte`, `m_enabled`, and `m_hovered`; exact-name caveat retained.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: target C++ policy documents inferred `m_selected` spelling and inherited `InvalidateRect(NULL)` choice; class/file support retain remaining class-wide naming confidence caps.
- [x] Validators run and results recorded. Proof: target validator `000000004957` at `2026-07-03T01:53:36-04:00`, class validator `000000004981` at `2026-07-03T02:02:06-04:00`, file validator `000000004985` at `2026-07-03T02:07:19-04:00`; all exit code 0 with `ok: 1`.
- [x] Generated report refresh completed by validator or explicitly confirmed deferred. Proof: all three scoped validators reported `generated_refresh: deferred` with matching command ids/timestamps; generated files were not edited manually.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted item remains unapplied; optional UID0001F9/vtable/class2 docs were already-present or not applicable for this callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004994","destination_path":"executed-b-agent-research/B014/0004E5-PrettyButtonControlPaneStateByteVirtualForwarder-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0004E5-PrettyButtonControlPaneStateByteVirtualForwarder-source-quality.md","timestamp":"2026-07-03T02:26:03-04:00","uid":"0004E5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
