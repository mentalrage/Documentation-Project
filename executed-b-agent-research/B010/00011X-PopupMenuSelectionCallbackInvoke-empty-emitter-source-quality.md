** TARGET-REPORT-UID:00011X **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00011X PopupMenuSelectionCallbackInvoke Empty-Emitter Source-Quality Report

## Lifecycle Status

- Initial report-only research was completed with MCP session `279422f0` and submitted for supervisor validation.
- Supervisor accepted the report for implementation callback.
- Implementation callback is in progress in this report revision: target/support by-* docs have been edited under Agent-B010 leases, and scoped validators/generated-output inspection are recorded below after the validator batch completes.
- No fallback-only evidence is used; the accepted MCP-backed evidence remains session `279422f0`.

## Finalized Report / Current Recommendation

- Accepted disposition: repair [UID:00011X] from a stale empty-emitter target into a formal comment-only generated-template marker for the shared one-argument `PlainMemberFunctionObject` / `PlainMemberFunctionObjectT` invoke body at `0x0049af00-0x0049af11`.
- Final disposition: source-declared/generated-binary FunctionObjects invoke glue. Do not emit a handwritten wrapper body and do not leave the formal block blank while the target has a live emitter route.
- Required metadata action: change `CANONICAL_OWNER:0000AK -> 0000JO`, keep `RECONSTRUCTABLE:TRUE`, change `EMITTER_UIDS:0000AK -> 0000JO`, and raise target scores from `86/90` to `88/91`.
- Required formal C++ action: insert the exact comment-only marker below into the target `RECONSTRUCTION_CPP CODE` block.
- Confidence: high. MCP session `279422f0` proves exact range/bytes/body/xrefs, seven shared vtable slots, vtable names, and construction stores. Remaining uncertainty is only original header/template spelling and whether the linker folded multiple instantiations into this one body.

## Target

- Target UID: `00011X`.
- Target path: `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md`.
- Assignment id: `B010-report-00011X-PopupMenuSelectionCallbackInvoke-empty-emitter-20260629`.
- Report path: `tools/leaser/Agents/Agent-B010/research/00011X-PopupMenuSelectionCallbackInvoke-empty-emitter-source-quality.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` `Files With Empty Emitters`; generated `auto-generated/NexusTK/util/FunctionObjects.cpp` still lists [UID:00011X] as an `Empty Emitter Marker`.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000AK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AK`, blank formal C++.
- Current parent/support state: [UID:0000AK] `PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_` is `85/86` and routes to [UID:0000JO] `FunctionObjects`; [UID:0000JO] is `87/85`; [UID:0001WQ] `FunctionObjectTemplates` is `85/89`.

## Current Target State

The target page already records the correct function range, the adjusted member-function call through callback-object offsets `+0x08`, `+0x0c`, and `+0x10`, seven data/vtable refs, no ordinary direct callers, and rejection of stale `0x004d0050` as a standalone callback. The stale part is the final source-quality disposition:

- It treats [UID:0000AK] as the exclusive direct owner even though current MCP proves the same invoke body is reused by seven vtables across several concrete `PlainMemberFunctionObject` / `PlainMemberFunctionObjectT` instantiations.
- It keeps the formal C++ block blank even though the current by-structure gate permits formal C++ when the target is reconstructable, has a valid emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
- It uses old `90/90+` blocker language even though current FunctionObjects policy has accepted comment-only formal markers for proven invoke/object-size wrappers, while keeping scalar deleting destructor glue separate and blank.
- It repeats historical saved-label wording from a prior C001 pass. Current MCP session `279422f0` reports the function as `sub_49AF00`; the documentation name `PopupMenuSelectionCallbackInvoke` is still useful as an alias, but the current report should not present that label as live-session proof.

Related docs checked:

- `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md`
- `by-item/PopupMenuSelectionCallback_0049AF00.md`
- `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md`
- `by-file/FunctionObjects.md`
- `by-type/by-template/FunctionObjectTemplates.md`
- `by-file/PopupMenuControls.md`
- `by-class/PopupMenuControlPane.md`
- `by-class/MenuPane.md`
- `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`
- `by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md`
- `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`
- `auto-generated/NexusTK/util/FunctionObjects.cpp` read-only
- `auto-generated/-ag-research-tracker.md` read-only
- `by-memory/-coverage-report.md` read-only
- `by-structure.md`

## Historical Supervisor Active Recheck

The initial supervisor instruction was report-only research for [UID:00011X] with current MCP session `279422f0`; no target/support by-* docs could be edited until supervisor validation and an implementation callback. That phase is complete and supervisor accepted the implementation callback. No split repair was required because `lookup_funcs` and byte evidence prove a compact modeled function at `0x0049af00-0x0049af11`, followed immediately by a separate `0x0049af11` sibling thunk.

MCP was unavailable earlier in this assignment, and B010 paused as required. This report uses only the recovered session `279422f0` for current MCP-backed evidence and does not rely on the stale `b2ae72ec` or older C001/B001 session state as current proof.

## Inference Research Guidance Check

- IDA/MCP facts are treated as authoritative for address, range, bytes, xrefs, vtable names, and construction stores.
- Existing by-* docs are useful leads, but target ownership and final C++ disposition were rechecked against current by-structure rules and accepted FunctionObjects policy.
- Generated C++ is lead material only. It currently shows stale scores (`82/88`) for [UID:00011X] while the by-memory source page is `86/90`; the important generated-state fact is the still-present `Empty Emitter Marker`.
- Wave2/Wave3 references encountered in popup support docs were treated as historical search context only. No stale Wave2/Wave3 material was used as proof.

## Heuristic / Inference Reanalysis And Validation

### Shared Invoke Body Versus Popup-Only Ownership

The page name and short alias are popup-menu oriented, and the popup constructor proves a concrete `PlainMemberFunctionObject<void (__thiscall PopupMenuControlPane::*)(long), PopupMenuControlPane>` vtable at `0x006187e8`. However, current MCP proves the exact code body at `0x0049af00` is also installed in six other callback vtables:

- `0x0061ff70`: `PlainMemberFunctionObjectT<NewUserDialogPane2, String const&>` style vtable.
- `0x0062004c`: `PlainMemberFunctionObjectT<NewCreateUserDialogPane, String const&>` style vtable.
- `0x00620094`: `PlainMemberFunctionObjectT<CreateUserDialogPane, String const&>` style vtable.
- `0x00620184`: `PlainMemberFunctionObject<NexonclubRegistrationDialog, unsigned long>` style vtable.
- `0x00622cf4`: `PlainMemberFunctionObjectT<NexonclubProxyDialog, String const&>` style vtable.
- `0x0062dde8`: `PlainMemberFunctionObject<TerminalPane, unsigned long>` style vtable.

That pattern is stronger than a popup-only method. The best source-quality interpretation is a shared/folded one-argument FunctionObjects invoke body reused by multiple concrete callback-template instantiations. [UID:0000AK] remains a real concrete user of this body, but it should not be the canonical owner of the address range.

### Source-Facing Type Direction

The exact original template names and header basename remain inferred, but the source-facing direction is strong:

- Shared template family: `PlainMemberFunctionObject` / `PlainMemberFunctionObjectT` under [UID:0000JO] `FunctionObjects` and [UID:0001WQ] `FunctionObjectTemplates`.
- Popup concrete typedef direction:
  - `typedef void (__thiscall PopupMenuControlPane::*PopupMenuSelectionCallback)(long);`
  - `PlainMemberFunctionObject<PopupMenuSelectionCallback, PopupMenuControlPane>` or the existing project direction `PlainMemberFunctionObject<TMember, TObject, TArg>`.
- Generic object layout for this body:
  - `this + 0x08`: stored member-function/callback pointer.
  - `this + 0x0c`: stored this-adjustment or base adjustment field.
  - `this + 0x10`: stored target object pointer.
  - Runtime argument remains on the caller stack and is forwarded by the tail jump.

The body is not feature code and should not be represented as `PopupMenuControlPane::OnSelectionChanged`; that target method is `0x00498220` and remains class-owned by `PopupMenuControlPane`.

### Empty-Emitter Repair

The old blank-block rationale was appropriate before the current FunctionObjects policy existed. It is no longer the best disposition for [UID:00011X] because:

- [UID:00011X] is reconstructable and has a valid source route through [UID:0000JO].
- The current combined score is already above the code-entry threshold, and the report recommends `88/91`.
- Accepted sibling policy already lets proven invoke/object-size wrappers carry formal comment-only generated-binary markers, while scalar deleting destructors stay blank.
- A comment-only marker preserves source truth better than a handwritten wrapper body and avoids the generated empty-emitter marker.

### Rejected Alternatives

- Keep blank formal C++ with nonblank `EMITTER_UIDS`: rejected because it preserves the assigned empty-emitter defect even though the body/source route is proven.
- Emit a handwritten wrapper body: rejected because this is compiler-emitted template glue with one shared/folded machine body; a handwritten method body would be decompiler-shaped and duplicate source that should come from the FunctionObjects template declaration.
- Keep [UID:0000AK] as exclusive canonical owner: rejected because six non-popup vtables also point at the exact same address and current B001 precedent routes shared folded FunctionObjects glue through [UID:0000JO].
- Move ownership to `PopupMenuControls`, `NexonclubRegistrationDialog`, `TerminalPane`, or any other feature module: rejected because those are construction/consumer contexts, not owners of the reusable callback framework.
- `CANONICAL_OWNER:NONE` with multiple emitters: rejected because this is not a pooled string or source-authored constant with independent source-use contexts. It has one shared source-family route: FunctionObjects.
- Treat `0x004d0050` as a second callback/no-op body: rejected because `lookup_funcs 0x004d0050` maps to containing `sub_4CFFB0` size `0xbf`, and `xrefs_to 0x004d0050` reports only an internal code xref at `0x004d004e`. Raw pointer bytes exist at `0x00618804` and `0x00637bc4`, but they are not a modeled function start and do not belong inside [UID:00011X].
- Rename/split the by-memory file during this pass: not required. The stable UID/path can remain, with page text clarifying that `PopupMenuSelectionCallbackInvoke` is a historical/feature-facing alias for the shared one-argument invoke body.

## Evidence Standards Used

Evidence used: current IDA MCP session `279422f0`, exact `lookup_funcs`, `decompile`, `disasm`, `get_bytes`, `xrefs_to`, `find_bytes`, `make_signature_for_range`, `int_convert`, `entity_query`, `analyze_function`; support by-* docs; generated C++/tracker read-only state; and executed B reports searched by UID/address/name/source family.

The evidence is strong enough for owner/emitter repair and a formal marker because binary facts and project policy align: exact bytes/body, seven vtable refs, named concrete vtables, constructor stores, no ordinary callees, no ordinary code callers to the wrapper, and accepted FunctionObjects marker precedent.

## Evidence Checked

IDA MCP session `279422f0`:

- `idb_list`: one active adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `16380`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.
- `lookup_funcs`: `0x0049af00` -> `sub_49AF00` size `0x11`; `0x0049af11` -> `sub_49AF11` size `0x0b`; `0x004d0050` -> containing `sub_4CFFB0` size `0xbf`; `0x00498220` -> `sub_498220` size `0x4d`.
- `decompile 0x0049af00`: `(*(this + 8))(*(this + 12) + *(this + 16))`.
- `disasm 0x0049af00`: eight-instruction wrapper: `push ebp; mov ebp, esp; mov eax, ecx; mov ecx, [eax+10h]; add ecx, [eax+0Ch]; mov eax, [eax+8]; pop ebp; jmp eax`.
- `get_bytes 0x0049af00 size 17`: `55 8b ec 8b c1 8b 48 10 03 48 0c 8b 40 08 5d ff e0`.
- `get_bytes 0x0049af11 size 11`: `81 e9 a0 00 00 00 e9 b4 01 00 00`; this is the separate sibling thunk with `0xa0` / decimal `160` adjustment (Verified with MCP `int_convert`).
- `get_bytes 0x0049aefb size 5`: preceding bytes end with `cc cc`, proving padding immediately before the target.
- `get_bytes 0x0049af1c size 8`: begins the next sibling thunk (`81 e9 a4 ...`), proving [UID:00011X] should not absorb adjacent thunks.
- `xrefs_to 0x0049af00`: seven data refs only at `0x006187f4`, `0x0061ff7c`, `0x00620058`, `0x006200a0`, `0x00620190`, `0x00622d00`, and `0x0062ddf4`.
- `callees 0x0049af00`: none. The member-function call is an indirect tail jump, not an IDA direct callee.
- `find_bytes "00 AF 49 00"`: exactly the same seven raw pointer matches as the IDA data refs.
- `make_signature_for_range 0x0049af00-0x0049af11`: unique signature `55 8B EC 8B C1 8B 48 ? 03 48 ? 8B 40 ? 5D FF E0`.
- `int_convert`: `0x11` -> decimal `17`, `0x0b` -> decimal `11`, `0xa0` -> decimal `160`, `0x18` -> decimal `24`, `0x04` -> decimal `4` (Verified with MCP `int_convert`).
- `entity_query` around the seven vtable bases: vtables named for PopupMenuControlPane, NewUserDialogPane2, NewCreateUserDialogPane, CreateUserDialogPane, NexonclubRegistrationDialog, NexonclubProxyDialog, and TerminalPane.
- `xrefs_to` for vtable bases:
  - `0x006187e8` stored at `0x004980bc` in `sub_498040`.
  - `0x0061ff70` stored at `0x0052b6a1` in `sub_52B650`.
  - `0x0062004c` stored at `0x0052d151` in `sub_52D100`.
  - `0x00620094` stored at `0x0052e9c1` in `sub_52E970`.
  - `0x00620184` stored at `0x00530189` in `sub_530060`.
  - `0x00622cf4` stored at `0x0055388f` in `sub_553610`.
  - `0x0062dde8` stored at `0x0058b567` in `sub_58B470`.
- `analyze_function 0x00498040`: PopupMenu constructor allocates `24`, calls the callback base constructor, stores the `PlainMemberFunctionObject<void (__thiscall PopupMenuControlPane::*)(long), PopupMenuControlPane>` vtable at `0x004980bc`, stores target `sub_498220` at `+0x08`, stores zero adjustment at `+0x0c`, and stores the captured pane pointer at `+0x10`.
- `xrefs_to 0x00498220`: many normal code refs plus data store `0x004980c2` from the popup callback object construction site.

Existing reports searched:

- `rg` terms: `00011X`, `0049af00`, `PopupMenuSelectionCallbackInvoke`, `PopupMenuSelectionCallback_0049AF00`, `PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane`, `FunctionObjects comment-only`, `invoke-wrapper marker`, `empty-emitter`, `PlainMemberFunctionObject`.
- No direct executed B report for [UID:00011X] was found.
- Opened matching executed B reports:
  - `executed-b-agent-research/B001/000123-FunctionObjectCallbackScalarDeletingDestructor.md`: used as precedent that folded/shared callback-template support can route through [UID:0000JO] instead of one concrete feature class.
  - `executed-b-agent-research/B002/00012X-versatile-alert-pane-callbacks-source-quality.md`: used as evidence that `0x0049af00` is a shared FunctionObjects invoke helper used by non-popup callbacks and not a pane-local interface.

Negative checks:

- `lookup_funcs 0x004d0050` did not return a standalone function; it returns containing `sub_4CFFB0`.
- `xrefs_to 0x004d0050` found only an internal code xref at `0x004d004e`.
- Raw pointer search for `0x0049af11` found separate sibling-thunk refs, not [UID:00011X] refs.
- Current MCP does not show the prior C001 saved label for `0x0049af00`; it reports `sub_49AF00`.
- During the initial report-only pass, no leases, validators, generated edits, tool-state edits, IDA DB edits, or subagents were used. During the accepted implementation callback, short leases were taken only for the six edited by-* docs; generated files, tool state, IDA DB, executed archives, manual coverage, supervisor ledgers, and lock files were not manually edited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:00011X] is exactly `0x0049af00-0x0049af11`, size `0x11` / 17 bytes. | High | MCP `lookup_funcs`, `get_bytes`, `int_convert` session `279422f0`. | Target Covered Range / Score Rationale | applied | Target now records exact half-open range, size, bytes, and signature. |
| C02 | `0x0049af11` is a separate sibling thunk, size `0x0b` / 11, beginning with `this - 0xa0`; [UID:00011X] must remain half-open. | High | MCP `lookup_funcs`, `get_bytes`, `xrefs_to`, `int_convert`. | Target Covered Range / Rejected Alternatives | applied | Target records successor `0x0049af11` sibling bytes, size, `0xa0` / 160 adjustment, and non-merge decision. |
| C03 | Body reads callback pointer at `+0x08`, computes adjusted target from `+0x0c/+0x10`, then tail-jumps through the callback pointer. | High | MCP `decompile`, `disasm`, `get_bytes`. | Target Wrapper ABI; by-item Behavior; FunctionObjectTemplates | applied | Target includes disasm and offset table; support docs summarize offset policy. |
| C04 | The wrapper has seven data-only refs and no ordinary direct code callers/callees. | High | MCP `xrefs_to`, `callees`, `find_bytes`. | Target Shared Vtable Evidence; FunctionObjects; FunctionObjectTemplates | applied | Target and support docs record seven data/vtable refs and no direct callers/callees. |
| C05 | The seven refs are vtable invoke slots at `0x006187f4`, `0x0061ff7c`, `0x00620058`, `0x006200a0`, `0x00620190`, `0x00622d00`, and `0x0062ddf4`. | High | MCP `xrefs_to`, `get_bytes`, `find_bytes`. | Target Shared Vtable Evidence; FunctionObjects; FunctionObjectTemplates | applied | Seven-slot table added to target and policy docs. |
| C06 | Vtable bases name concrete callback types for PopupMenuControlPane, NewUser/CreateUser dialogs, Nexonclub registration/proxy dialogs, and TerminalPane. | High | MCP `entity_query` around vtable bases. | Target Shared Vtable Evidence; FunctionObjects; FunctionObjectTemplates | applied | Target and support docs list the concrete vtable names/contexts. |
| C07 | Each vtable base has a construction store, including popup store `0x004980bc` and six non-popup stores. | High | MCP `xrefs_to` vtable bases. | Target Shared Vtable Evidence; FunctionObjects; FunctionObjectTemplates | applied | Target and support docs list stores `0x004980bc`, `0x0052b6a1`, `0x0052d151`, `0x0052e9c1`, `0x00530189`, `0x0055388f`, and `0x0058b567`. |
| C08 | Popup constructor binds local vtable `0x006187e8`, target `0x00498220`, zero adjustment, and captured pane pointer in a 24-byte callback object. | High | MCP `analyze_function 0x00498040`; support docs. | Target Shared Vtable Evidence; by-class [UID:0000AK]; PopupMenuControls | applied | Target, class page, and PopupMenuControls preserve popup construction proof while making it consumer evidence. |
| C09 | `0x00498220` is the bound popup callback target, not this invoke body. | High | MCP `lookup_funcs`, `xrefs_to 0x00498220`, PopupMenuControlPane docs. | Target Source Ownership / Rejected Alternatives; support docs | applied | Target and support docs state `0x00498220` is popup target binding, not wrapper ownership. |
| C10 | Current MCP names `0x0049af00` as `sub_49AF00`; prior saved-label wording is historical, not current-session proof. | Medium-high | MCP `lookup_funcs` session `279422f0` versus existing docs. | Target Status / Changes; by-item Evidence | applied | Target/by-item historicalize `PopupMenuSelectionCallbackInvoke` as alias and record current `sub_49AF00` name. |
| C11 | Stale `0x004d0050` remains rejected as a target/sibling function: it is inside `sub_4CFFB0`, with only internal code xref. | High | MCP `lookup_funcs`, `xrefs_to`, bytes around `0x004d0048`. | Target Rejected Alternatives; FunctionObjects caveat; by-item Evidence | applied | Target/support docs preserve stale `0x004d0050` rejection. |
| C12 | Raw pointer bytes to `0x004d0050` exist at `0x00618804` and `0x00637bc4`, but they are not modeled function xrefs and do not make a standalone [UID:00011X] body. | Medium-high | MCP `find_bytes`, `xrefs_to 0x00618804/0x00637bc4`. | Target Rejected Alternatives | applied | Target records raw pointer nuance without turning `0x004d0050` into a body. |
| C13 | Existing [UID:0000AK] popup wrapper class is a valid concrete consumer but no longer the best canonical owner of the shared body. | High | Seven-vtable MCP evidence; B001 shared FunctionObjects precedent. | Target metadata; [UID:0000AK] support; PopupMenuControls | applied | Target metadata moved to UID0000JO; class/page wording now says popup is a consumer/user. |
| C14 | Best canonical owner/emitter for the exact address range is [UID:0000JO] `FunctionObjects`. | High | Shared/folded vtable evidence; by-structure owner/emitter rules; B001 precedent. | Target metadata; FunctionObjects support; by-item alias | applied | Target and by-item owner/emitter set to `0000JO`; FunctionObjects support policy added. |
| C15 | Target formal C++ should be a comment-only generated-template marker, not a handwritten body. | High | Current FunctionObjects policy, target body shape, accepted invoke/object-size marker precedents. | Target formal C++; FunctionObjects; FunctionObjectTemplates | applied | Target formal block contains exact accepted marker; support docs reject handwritten body. |
| C16 | Target scores should become `88/91`. | Medium-high | Current evidence resolves empty-emitter and ownership blockers while original header spelling remains inferred. | Target metadata / Score Rationale | applied | Target metadata changed to `COMPLETION:88`, `CONFIDENCE:91`. |
| C17 | [UID:0000V8] by-item alias should be updated as a feature-facing alias/support page and should not continue to imply the shared body is popup-exclusive. | Medium-high | Target and by-item duplicate range; seven-vtable evidence. | by-item support | applied | By-item rewritten as alias/support and given the accepted covered-by marker because it had its own blank formal emitter route. |
| C18 | Generated `FunctionObjects.cpp` previously showed [UID:00011X] as an `Empty Emitter Marker` with stale values; implementation had to validate with `--wait-generated` and inspect generated output read-only. | High | Read-only generated file inspection after validators. | Validator Results / Implementation checklist | applied | Validators `000000000832`, `000000000833`, and `000000000845` completed generated refresh. Read-only `rg` showed UID00011X at `FunctionObjects.cpp:58-61` with the formal marker, and `rg "00011X.*Empty Emitter Marker|Empty Emitter Marker.*00011X"` returned no matches. |
| C19 | Manual `by-memory/-coverage-report.md` row is stale (`82%` and popup-exclusive summary) and should be supervisor-owned if updated. | Medium-high | Read-only coverage row inspection; target score recommendation. | Exact Manual Supervisor-Owned Coverage Text | excluded-with-reason | Manual coverage report not edited; user/goal explicitly excluded manual `-coverage-report.md` files. |
| C20 | No split/rename/new child is required for the current callback body; preserve stable UID/path and clarify alias/source role in prose. | Medium-high | Exact range; broad references; no boundary defect. | Target Covered Range / Rejected Alternatives; support docs | applied | Stable UID/path preserved; prose clarifies alias/source role without split/rename/new child. |

## Positive Evidence Summary

- Current MCP proves the exact function bytes and semantics: a 17-byte adjusted member-function tail jump, no direct callees, and a unique signature.
- Current MCP proves seven data/vtable refs and seven raw pointer matches to `0x0049af00`.
- Current MCP names all seven vtable bases as FunctionObjects callback-template instantiations.
- Current MCP proves the popup construction route and six additional feature construction routes through vtable stores.
- Existing FunctionObjects docs already distinguish accepted invoke/object-size comment-only marker policy from scalar deleting destructor blank-formal-C++ policy.
- B001 executed report for [UID:000123] establishes a direct precedent for shared/folded callback-template support being routed through [UID:0000JO] rather than one concrete feature class.

## IDA MCP Facts

Function/range facts:

- `0x0049af00-0x0049af11`: real function, size `0x11` / 17 (Verified with MCP `int_convert`).
- `0x0049af11`: separate successor thunk, size `0x0b` / 11 (Verified with MCP `int_convert`).
- Preceding bytes at `0x0049aefb` end in `cc cc`; target bytes start at `0x0049af00`.
- Successor bytes at `0x0049af11` and `0x0049af1c` are separate adjustor thunks, not part of [UID:00011X].

Data/table/vtable facts:

| Vtable base | Invoke slot | Current MCP vtable name / context | Construction store |
| --- | --- | --- | --- |
| `0x006187e8` | `0x006187f4` | `PlainMemberFunctionObject<PopupMenuControlPane, long>` | `0x004980bc` in `sub_498040` |
| `0x0061ff70` | `0x0061ff7c` | `PlainMemberFunctionObjectT<NewUserDialogPane2, String const&>` | `0x0052b6a1` in `sub_52B650` |
| `0x0062004c` | `0x00620058` | `PlainMemberFunctionObjectT<NewCreateUserDialogPane, String const&>` | `0x0052d151` in `sub_52D100` |
| `0x00620094` | `0x006200a0` | `PlainMemberFunctionObjectT<CreateUserDialogPane, String const&>` | `0x0052e9c1` in `sub_52E970` |
| `0x00620184` | `0x00620190` | `PlainMemberFunctionObject<NexonclubRegistrationDialog, unsigned long>` | `0x00530189` in `sub_530060` |
| `0x00622cf4` | `0x00622d00` | `PlainMemberFunctionObjectT<NexonclubProxyDialog, String const&>` | `0x0055388f` in `sub_553610` |
| `0x0062dde8` | `0x0062ddf4` | `PlainMemberFunctionObject<TerminalPane, unsigned long>` | `0x0058b567` in `sub_58B470` |

Negative IDA facts:

- No direct callees from `0x0049af00`.
- No direct code xrefs to `0x0049af00`; all refs are data/vtable refs.
- `0x004d0050` is not a standalone function in current MCP.
- Current MCP does not confirm the prior saved label; it reports `sub_49AF00`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049af00-0x0049af11` | [UID:00011X] `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md` | Shared/folded one-argument `PlainMemberFunctionObject` invoke body | TRUE | recommend [UID:0000JO] | recommend `88/91` | repair empty emitter with formal marker |
| `0x0049af11-0x0049af1c` | no assigned target in this report | separate sibling adjustor thunk, `this - 0xa0` | out of scope | not changed | n/a | preserve as separate |
| `0x004d0050` | stale auxiliary/no-op lead | interior return path in `sub_4CFFB0`, not a standalone callback body | not [UID:00011X] | rejected | n/a | preserve as rejected stale lead |
| `0x00498220-0x0049826d` | PopupMenuControlPane callback target | popup selection change target bound by local callback object | TRUE | PopupMenuControlPane / PopupMenuControls | existing support | consumer evidence only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0049af00` | data refs from seven vtable slots, no code callers | shared virtual callback invoke body |
| `0x006187f4` | contains bytes `00 af 49 00` | PopupMenuControlPane concrete invoke slot |
| `0x0061ff7c` | contains bytes `00 af 49 00` | NewUserDialogPane2 string callback invoke slot |
| `0x00620058` | contains bytes `00 af 49 00` | NewCreateUserDialogPane string callback invoke slot |
| `0x006200a0` | contains bytes `00 af 49 00` | CreateUserDialogPane string callback invoke slot |
| `0x00620190` | contains bytes `00 af 49 00` | NexonclubRegistrationDialog unsigned-long callback invoke slot |
| `0x00622d00` | contains bytes `00 af 49 00` | NexonclubProxyDialog string callback invoke slot |
| `0x0062ddf4` | contains bytes `00 af 49 00` | TerminalPane unsigned-long callback invoke slot |
| `0x004980bc` | constructor store of `0x006187e8` | popup concrete callback object vtable store |
| `0x004980c2` | data store of `0x00498220` | popup concrete member target binding |
| `0x004d0050` | only IDA xref is internal code xref from `0x004d004e` | not a modeled callback function |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target and by-item docs already identify the adjusted member-function call and data/vtable-only reachability.
- [UID:0000JO] `FunctionObjects` documents accepted comment-only formal marker policy for proven invoke/object-size wrappers and separate blank-formal policy for scalar deleting destructors.
- [UID:0001WQ] `FunctionObjectTemplates` documents the shared template families and known instantiations.
- [UID:0000MN] `PopupMenuControls`, [UID:0000AN] `PopupMenuControlPane`, and [UID:00011F] `PopupMenuControlPaneCore` document the popup construction/consumer side.
- [UID:0003DF] `NexonclubProxyCallbackVtableData` and [UID:0003C7] `NexonclubRegistrationDialogReadOnlyData` independently document non-popup vtables that point to `0x0049af00`.
- Executed B001 and B002 reports already identify `0x0049af00` as shared FunctionObjects callback invoke support.

Existing docs that are stale or incomplete:

- Target and by-item pages still say final C++ remains blank because template spelling/source split are not at a previous `90/90+` gate. That is superseded by current by-structure and FunctionObjects marker policy.
- Target and by-item pages present the exact page as popup-focused without enough warning that the physical body is shared by seven concrete callback vtables.
- [UID:0000AK] page calls [UID:00011X] the exact source-bearing child of that class; it should instead say [UID:00011X] is the shared invoke body used by the class's vtable slot.
- Generated `FunctionObjects.cpp` is stale and still shows [UID:00011X] as `82/88` plus `Empty Emitter Marker`.
- `by-memory/-coverage-report.md` row is stale at `82%` and should be supervisor-owned if updated.

## Ranked Ownership Analysis

### 1. [UID:0000JO] FunctionObjects

- Evidence for:
  - Current MCP proves seven callback-template vtables across multiple feature modules use this exact body.
  - Current MCP proves shared ABI fields and no feature-specific logic.
  - [UID:0000JO] is the source root for the shared callback-template family.
  - B001 [UID:000123] accepted shared/folded FunctionObjects destructor routing through [UID:0000JO].
  - Existing FunctionObjects policy already accepts comment-only target markers for proven invoke wrappers.
- Evidence against:
  - The popup-specific vtable and constructor are the easiest concrete proof for the assigned page name.
  - [UID:0000JO] is a file/source-family page rather than a concrete class page.
- Decision:
  - Best canonical owner and emitter for the exact address range. Change target metadata to `CANONICAL_OWNER:0000JO` and `EMITTER_UIDS:0000JO`.

### 2. [UID:0000AK] PlainMemberFunctionObject PopupMenuControlPane

- Evidence for:
  - Vtable base `0x006187e8` is named for PopupMenuControlPane.
  - Popup constructor stores this vtable at `0x004980bc`, target `0x00498220` at `0x004980c2`, zero adjustment, and captured pane pointer.
  - Existing target/by-item docs and PopupMenuControls docs use this alias.
- Evidence against:
  - It accounts for only one of seven vtable slots pointing to the body.
  - It would misrepresent shared/folded template support as a popup-exclusive class method.
  - The actual popup behavior target is `0x00498220`, not `0x0049af00`.
- Decision:
  - Keep as concrete popup consumer/support doc. Do not keep as target canonical owner.

### 3. Feature modules and concrete dialog/pane classes

- Evidence for:
  - Each feature constructor stores one of the vtables and binds a target member.
  - Feature docs explain concrete runtime use.
- Evidence against:
  - The body contains no feature behavior and only uses the generic callback object layout.
  - Feature constructors are consumers/construction sites, not source owners of FunctionObjects template glue.
- Decision:
  - Reject as canonical owner/emitter. Preserve them as vtable/construction evidence.

### 4. [UID:0001WQ] FunctionObjectTemplates

- Evidence for:
  - It is the conceptual template-family doc and records known instantiations.
- Evidence against:
  - It is a by-type/template support page whose own canonical owner is [UID:0000JO].
  - The generated source route is already [UID:0000JO] `NexusTK/util/FunctionObjects.cpp`.
- Decision:
  - Use as support doc, not canonical owner/emitter.

### 5. No-owner / no-emitter

- Evidence for:
  - Exact original header basename and final template spelling remain inferred.
- Evidence against:
  - Current binary evidence and existing project policy identify a stable FunctionObjects route.
  - Leaving no owner or no emitter would preserve the assigned empty-emitter/source-quality defect.
- Decision:
  - Reject.

## Source Placement

Recommended source placement is [UID:0000JO] `FunctionObjects`, likely `NexusTK/util/FunctionObjects.h` for the real template declaration and `auto-generated/NexusTK/util/FunctionObjects.cpp` as the documentation-generated marker root. Concrete feature construction stays in feature modules:

- Popup construction/consumer: [UID:0000MN] `PopupMenuControls`, [UID:0000AN] `PopupMenuControlPane`, and [UID:0000AK] concrete vtable wrapper.
- NewUser/CreateUser dialog construction: feature docs for those dialog constructors, not in scope for edits here.
- Nexonclub construction: existing registration/proxy vtable docs.
- TerminalPane construction: TerminalPane/alert support, not in scope for edits here.

Rejected placements: popup-only class ownership, all feature modules, by-item alias ownership, or a new source file. No new file/grouping is needed.

## Range / Split / Padding / Reclassification Analysis

No split is required.

- Exact half-open range is `0x0049af00-0x0049af11`.
- Target bytes: `55 8b ec 8b c1 8b 48 10 03 48 0c 8b 40 08 5d ff e0`.
- Predecessor check shows `cc cc` immediately before the target.
- Successor `0x0049af11` is a separate `0x0b` / 11-byte thunk with `0xa0` / decimal `160` adjustment.
- The `0x0049af11` endpoint has its own four data refs and raw pointer matches; do not merge it into [UID:00011X].
- `0x004d0050` remains a rejected stale auxiliary lead and should not be split into this target.

No filename rename is required for implementation. Preserve stable path/UID and update title/prose to make the shared/folded source role explicit.

## Negative Evidence Summary

- Consumer construction stores do not make the feature classes owners of the shared invoke body.
- The popup target method `0x00498220` has normal code refs and a data store into the callback object; it is the bound member behavior, not the wrapper body.
- The absence of direct code callers for `0x0049af00` is not dead-code evidence. It is expected for vtable-dispatched callback glue.
- Raw pointer hits to `0x004d0050` do not override `lookup_funcs`; the address is not a modeled function start and has only an internal code xref.
- The current MCP function name `sub_49AF00` means prior saved-label wording should be historicalized, not used as current-session evidence.
- The exact original template declaration/header spelling is not proven; therefore a handwritten concrete C++ body is still rejected and scores stay below final-audit levels.

## First-Draft C++ Recommendation

Eligible for draft C++: yes, but only as a formal comment-only generated-template marker. Do not enter an executable wrapper body.

Recommended formal `RECONSTRUCTION_CPP CODE` block content for [UID:00011X]:

```cpp
// Compiler-emitted one-argument PlainMemberFunctionObject/PlainMemberFunctionObjectT invoke wrapper;
// generated from the shared FunctionObjects template declaration and folded across
// PopupMenuControlPane, NewUser/CreateUser dialog, Nexonclub, and TerminalPane callback vtables.
```

Reason it preserves exact original behavior: no handwritten logic is introduced. The comment records that executable bytes are generated from the shared template declaration and concrete construction sites.

Reason it matches plausible original source: mid-2000s Visual C++ template instantiations and linker folding can produce a single identical body for multiple callback object vtables. A source-level template declaration plus feature-specific construction is the realistic source shape; a standalone `sub_49AF00` method body is not.

Reason not to leave code blank: blank formal C++ with a live emitter route keeps [UID:00011X] in generated `FunctionObjects.cpp` as an unresolved `Empty Emitter Marker`. Current FunctionObjects policy allows formal comment-only markers for proven invoke/object-size wrappers.

Third-party import directive: not applicable.

## Final Recommendation

Target [UID:00011X]:

- Change `COMPLETION:86 -> 88`.
- Change `CONFIDENCE:90 -> 91`.
- Change `CANONICAL_OWNER:0000AK -> 0000JO`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Change `EMITTER_UIDS:0000AK -> 0000JO`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Insert the formal comment-only generated-template marker above.
- Preserve exact range/body/vtable/current-session evidence and stale `0x004d0050` rejection.
- Replace popup-exclusive wording with shared/folded one-argument FunctionObjects invoke wording while retaining `PopupMenuSelectionCallbackInvoke` as a historical/feature-facing alias.

No split, new child file, IDA rename, or IDA DB edit is recommended.

## Recommended Target Doc Changes

Target path: `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md`.

Incorporate:

- Current MCP session `279422f0` health/session facts.
- Current `lookup_funcs` facts for `0x0049af00`, `0x0049af11`, `0x004d0050`, and `0x00498220`.
- Exact bytes, unique signature, decompile/disasm body, no callees, seven data-only refs, and pointer-search proof.
- Vtable table with seven base/slot/name/construction-store rows.
- Popup constructor binding proof from `analyze_function 0x00498040`.
- Historicalize prior saved-label statement because current session reports `sub_49AF00`.
- Preserve stale `0x004d0050` rejection, including raw pointer nuance.
- Add score/metadata rationale for `88/91`, [UID:0000JO] owner/emitter, and comment-only marker.
- Rejected alternatives: blank formal block, handwritten wrapper body, popup-only owner, feature owner, no-owner/no-emitter, split/rename, and `0x004d0050` standalone function.

## Recommended Support Doc Changes

Support path: `by-file/FunctionObjects.md`.

- Update the [UID:0000AK]/[UID:00011X] proposed-contents row to say [UID:00011X] is the shared/folded one-argument invoke body used by the PopupMenuControlPane vtable and six other FunctionObjects vtables, not a popup-exclusive source child.
- Add B010 current MCP session `279422f0` proof to the accepted invoke-wrapper comment-only marker policy: exact `0x11` / 17-byte range, unique signature, seven data-only refs, seven vtable names, construction stores, no direct callees/callers, and `0x004d0050` rejection.
- Preserve scalar deleting destructor blank-formal policy as separate and unchanged.

Support path: `by-type/by-template/FunctionObjectTemplates.md`.

- Add [UID:00011X] to the target-level generated-template marker policy as the shared one-argument `PlainMemberFunctionObject` / `PlainMemberFunctionObjectT` invoke body.
- Record the source-facing layout: callback pointer `+0x08`, adjustment/base fields `+0x0c/+0x10`, runtime argument forwarded by the tail jump.
- Add the seven-vtable current MCP proof and keep exact original template/header spelling below final-audit confidence.

Support path: `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md`.

- Update wording so [UID:00011X] is a shared invoke body used by this class's vtable slot, not exclusively owned by this concrete popup class.
- Preserve popup-specific construction proof: vtable `0x006187e8`, invoke slot `0x006187f4`, store at `0x004980bc`, bound target `0x00498220`, zero adjustment, captured pane pointer.
- Do not raise class metadata solely from this report unless the supervisor chooses to repair the class's separate empty marker in a later assignment.

Support path: `by-item/PopupMenuSelectionCallback_0049AF00.md`.

- Update as a feature-facing alias/support page. It should say [UID:00011X] is the shared/folded FunctionObjects one-argument invoke body and [UID:0000AK]/PopupMenuControls are the popup construction/consumer route.
- If the supervisor wants to fix the by-item's separate generated empty marker in the same callback, use a covered-by formal comment rather than duplicating the full target marker:

```cpp
// Emitted marker for this shared invoke range is covered by [UID:00011X].
```

Support path: `by-file/PopupMenuControls.md`.

- Keep PopupMenuControls as the feature-side owner for constructing and consuming the popup callback.
- Add a short note that the `0x0049af00` body is shared FunctionObjects invoke glue; the popup-specific binding is the `0x004980bc` vtable store and `0x00498220` target store.

Support paths not recommended for edits in the first callback:

- `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`: already contains enough constructor/target context.
- `by-memory/0x006200a8-0x00620198.NexonclubRegistrationDialogReadOnlyData.md` and `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`: already document non-popup vtable refs; cite them as supporting evidence unless a contradiction is found during implementation.
- `by-memory/-coverage-report.md`: manual/supervisor-owned only; exact row supplied below.

## Score And Metadata Recommendation

Current target score/metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000AK`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000AK`
- Formal C++ blank

Recommended target score/metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000JO`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JO`
- Formal C++ comment-only generated-template marker

Score rationale:

- Raise completion because current B010 MCP resolves the empty-emitter disposition, shared/folded ownership, exact bytes/signature, all seven vtable slots, construction stores, sibling boundary, and stale `0x004d0050` caveat.
- Raise confidence because current MCP independently verifies the target-local and shared-source-route evidence. Confidence stays below final because exact original header/template spelling is inferred, current IDB does not preserve the prior saved label, and some non-popup consumer source docs are outside this target callback.
- Do not use `95+`; this is not final-audit source reconstruction.

Score-limiting blockers investigated:

- Original template/header spelling: checked FunctionObjects, FunctionObjectTemplates, by-item, by-class, and executed B reports. Resolved enough for a marker, not enough for final template declaration certainty.
- Popup-only owner: rejected by seven-vtable MCP proof.
- Blank formal block: rejected by current marker policy.
- Handwritten body: rejected by compiler-template glue evidence.
- `0x004d0050`: rejected as standalone function by current MCP.
- Generated output stale score: documented; implementation must refresh with validator and inspect generated output.

## Open Questions With Attempted Resolution

- Exact original header basename (`FunctionObjects.h` versus another callback utility header): unresolved but not blocking. Evidence checked: FunctionObjects, FunctionObjectTemplates, executed B reports, generated output. Impact: caps score; does not block comment-only marker.
- Exact final template spelling: unresolved but not blocking. Decorated vtable names prove the family and concrete type direction; the marker can avoid overcommitting to one final source spelling.
- Whether MSVC linker COMDAT folding is the precise mechanism: inferred, not original-proof. Evidence is seven concrete vtables pointing to one identical body. Impact: explains shared owner but does not require source code changes beyond the marker.
- Whether the current IDB should have the `PopupMenuSelectionCallbackInvoke` label: current MCP reports `sub_49AF00`; no IDA edits are allowed in this assignment. Impact: target docs should treat the label as documentation alias/historical C001 state, not current-session proof.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual `by-memory/-coverage-report.md` is outside B-agent write scope. If the supervisor chooses to update the stale [UID:00011X] row after accepting this report, replace the existing row with:

```text
    - [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) 0x0049af00-0x0049af11 | callback-template invoke | SharedPlainMemberFunctionObjectOneArgInvoke / PopupMenuSelectionCallbackInvoke : reconstructable : 88% : very strong : B010 MCP session `279422f0` proves an exact 17-byte shared/folded FunctionObjects one-argument invoke body: callback pointer at `+0x08`, adjusted target from `+0x0c/+0x10`, unique signature, no direct callees/callers, seven data-only vtable refs across PopupMenuControlPane, NewUser/CreateUser dialogs, Nexonclub registration/proxy dialogs, and TerminalPane, popup construction store `0x004980bc` plus target store `0x004980c2`, sibling `0x0049af11` kept separate, and stale `0x004d0050` rejected as a `sub_4CFFB0` interior address. Formal output should be a comment-only generated-template marker through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), not a handwritten wrapper body.
```

No exact manual text is needed for validator-owned `auto-generated/-ag-research-tracker.md`; it should refresh through validator/report execution after implementation.

## Follow-Up Actions

Supervisor actions:

- Initial validation is complete; supervisor accepted implementation callback.
- Supervisor-owned `execute_report` remains intentionally not run by B010.

A-agent actions:

- None required before callback acceptance.

B010 implementation callback actions:

- Short leases were taken only for the six edited by-* files.
- Target/support doc details were applied at report-level detail, including the by-item covered-by marker supported by the callback goal.
- Scoped validators and generated-output inspection are recorded below after the batch completes.
- Claim And Incorporation Ledger and checklist were updated with applied/excluded proof; generated proof is finalized after validator refresh.

## Confidence

- Recommendation confidence: high.
- Score confidence: `88/91` is defensible after target/support incorporation.
- Remaining uncertainty: original header/template spelling and final source declaration text for FunctionObjects. This uncertainty supports a comment-only marker and prevents a handwritten wrapper body.

## Validator Results

- Initial report-only phase: no validators were run because no target/support by-* docs were edited.
- Implementation callback phase validators:
  - `000000000832` at `2026-06-29T13:50:33-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md --apply --queue-timeout 240 --wait-generated`; exit code `0`, `ok: 1`, generated refresh completed.
  - `000000000833` at `2026-06-29T13:50:52-04:00`: `python .\tools\validator.py --mode file --file by-file\FunctionObjects.md --apply --queue-timeout 240 --wait-generated`; exit code `0`, `ok: 1`, generated refresh completed.
  - `000000000835` at `2026-06-29T13:51:10-04:00`: `python .\tools\validator.py --mode file --file by-type\by-template\FunctionObjectTemplates.md --apply --queue-timeout 240`; exit code `0`, `ok: 1`, generated refresh deferred.
  - `000000000841` at `2026-06-29T13:51:16-04:00`: `python .\tools\validator.py --mode file --file by-class\PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md --apply --queue-timeout 240`; exit code `0`, `ok: 1`, generated refresh deferred.
  - `000000000845` at `2026-06-29T13:51:24-04:00`: `python .\tools\validator.py --mode file --file by-item\PopupMenuSelectionCallback_0049AF00.md --apply --queue-timeout 240 --wait-generated`; exit code `0`, `ok: 1`, generated refresh completed.
  - `000000000851` at `2026-06-29T13:51:43-04:00`: `python .\tools\validator.py --mode file --file by-file\PopupMenuControls.md --apply --queue-timeout 240`; exit code `0`, `ok: 1`, generated refresh deferred.
- Validator caveats: scoped validators reported pre-existing missing-reference/missing-registry issues such as stale UID00011F, UID000123/UID0003LP, and unrelated menu helper UIDs. No UID00011X validator blocker remained.
- Generated refresh: `auto-generated/NexusTK/util/FunctionObjects.cpp` was inspected read-only after generated refresh. UID00011X now appears as the accepted marker at lines `58-61`; direct search for `00011X.*Empty Emitter Marker|Empty Emitter Marker.*00011X` returned no matches.
- Leases: Agent-B010 leased six by-* docs before editing. `unlease` after validation reported `Rejected[No active lease]` for all six, and `tools/leaser/Agents/current_leases.md` then showed `No active leases.`
- MCP availability: session `279422f0` was healthy for all current evidence calls used in this report.

## Changed Files

- Initial report-only phase created:
  - `tools/leaser/Agents/Agent-B010/research/00011X-PopupMenuSelectionCallbackInvoke-empty-emitter-source-quality.md`
- Implementation callback modified:
  - `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md`
  - `by-file/FunctionObjects.md`
  - `by-type/by-template/FunctionObjectTemplates.md`
  - `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md`
  - `by-item/PopupMenuSelectionCallback_0049AF00.md`
  - `by-file/PopupMenuControls.md`
  - `tools/leaser/Agents/Agent-B010/research/00011X-PopupMenuSelectionCallbackInvoke-empty-emitter-source-quality.md`
- Validator-owned generated refresh, not manually edited by B010:
  - `auto-generated/NexusTK/util/FunctionObjects.cpp`
- Renamed:
  - none.
- Report execution:
  - not run by B010. The supervisor owns any `execute_report` action after independent verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Completed; callback accepted.
- [x] Target doc update: `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md` metadata to `88/91`, `CANONICAL_OWNER:0000JO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JO`, formal comment-only generated-template marker, and current MCP session `279422f0` evidence.
- [x] Target doc update: record exact range `0x0049af00-0x0049af11`, bytes, unique signature, decompile/disasm behavior, no direct callees/callers, seven vtable refs, construction stores, sibling `0x0049af11` exclusion, and stale `0x004d0050` rejection.
- [x] Target doc update: replace stale blank-formal `90/90+` blocker rationale with accepted invoke-wrapper marker rationale.
- [x] Support doc update: `by-file/FunctionObjects.md` adds [UID:00011X] as the shared/folded one-argument invoke marker case and preserves scalar destructor blank-formal policy.
- [x] Support doc update: `by-type/by-template/FunctionObjectTemplates.md` adds [UID:00011X] to the accepted invoke-wrapper marker policy with field-offset and seven-vtable proof.
- [x] Support doc update: `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md` changes [UID:00011X] from exclusive child wording to shared invoke body used by this class's vtable slot, preserving popup construction proof.
- [x] Support doc update: `by-item/PopupMenuSelectionCallback_0049AF00.md` updates alias/prose to point to [UID:00011X] as shared body and adds the accepted covered-by formal marker because the doc structure supported it.
- [x] Support doc update: `by-file/PopupMenuControls.md` keeps feature-side construction/consumer ownership and notes the shared FunctionObjects invoke body.
- [x] Confirm no split/rename/new child is required; preserve stable UID/path and use prose/title alias for shared-source correction.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim, with generated proof pending validator refresh.
- [x] Score-limiting blockers researched to resolution: owner route, emitter route, first-draft C++ versus marker/no-code, exact range, vtable refs, stale `0x004d0050`, generated stale output, and prior saved-label wording.
- [x] Third-party import directive confirmed not applicable.
- [x] Historical/stale assumptions and rejected alternatives preserved: popup-only owner, blank formal block, handwritten wrapper body, feature owner, no-owner/no-emitter, standalone `0x004d0050`, current saved-label proof.
- [x] Validators to run after accepted implementation:
  - `python .\tools\validator.py --mode file --file by-memory\0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-file\FunctionObjects.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-type\by-template\FunctionObjectTemplates.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-class\PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-item\PopupMenuSelectionCallback_0049AF00.md --apply --queue-timeout 240 --wait-generated` if the by-item support marker/prose is accepted.
  - `python .\tools\validator.py --mode file --file by-file\PopupMenuControls.md --apply --queue-timeout 240` if PopupMenuControls support wording is changed.
- [x] Generated output check after validator refresh: inspected `auto-generated\NexusTK\util\FunctionObjects.cpp` read-only and proved [UID:00011X] no longer appears as an `Empty Emitter Marker`; generated refresh command IDs/timestamps recorded above.
- [x] Manual supervisor-owned `by-memory/-coverage-report.md` row supplied above if supervisor chooses to update manual coverage; excluded from B010 edits per callback scope.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim, including C18 generated no-empty-marker proof.
- [x] Metadata/score/owner/emitter/formal marker changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Validators run and results recorded with command IDs/timestamps.
- [x] Generated `FunctionObjects.cpp` checked for [UID:00011X] no-empty-marker proof.
- [x] Leases released or confirmed expired; current lease report showed no active leases.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00011X-PopupMenuSelectionCallbackInvoke-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/00011X-PopupMenuSelectionCallbackInvoke-empty-emitter-source-quality.md","timestamp":"2026-06-29T14:01:13","uid":"00011X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
