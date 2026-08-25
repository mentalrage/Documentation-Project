** TARGET-REPORT-UID:00015Y **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID00015Y GeneralPurposePanel2 SwitchActiveChild Empty-Emitter Source-Quality Research

## Finalized Report / Current Recommendation

- The accepted callback reconstructed [UID:00015Y] as the source-authored public method `void GeneralPurposePanel2::SwitchActiveChild(int childIndex, const unsigned char *packetData)` in `NexusTK/ui/panels/GeneralPurposePanel.cpp`.
- The target is now `91/93`, raised from the evidence-time `86/90` snapshot. `CANONICAL_OWNER:00005R`, `EMITTER_UIDS:00005R`, `RECONSTRUCTABLE:TRUE`, blank emitter position, exact half-open range `0x004b89a0-0x004b8a7f`, and `Nested:0` are preserved.
- The exact accepted managed first-draft body is installed. It preserves the upper-bound-only index test, valid `-1` sentinel, old-child lookup before the active-index store, store before old-child collapse, optional new-child activation, exact rectangle and layer arguments, and unconditional FrameChrome refresh pair.
- [UID:00005R] `GeneralPurposePanel2` now uses `Pane *m_childPanes[1]` plus `int m_activeChildIndex` and the pointer-valued activation parameter. The constructor's concrete `NewSystemMessagePane` identity remains valid for `m_childPanes[0]`; it is not evidence for a singular source field.
- `0x00544ee0-0x00544f2e` is registered as exact child [UID:0004KU] `Pane::Collapse` under the non-emitting PaneCore index. Its body is `RemoveFromLayer()` followed by `UpdateRenderRegion` with an all-zero `RectBounds`.
- Inherited primary slot `+0x48` is synchronized as the best source contract `virtual void Pane::OnActivate(const unsigned char *packetData)`. Derived implementations either consume packet data or ignore it while refreshing/requesting state; the historical `bool showChild` interpretation is retained only as rejected history.
- Sibling [UID:00015X] now emits its accepted exact body with seven/four child limits, same-tab exceptions, layout branches, packet null behavior, and legacy InterfaceEfx call preserved.
- Broad [UID:00015V] is now a non-emitting split/index over exact source children and compiler support. Its source-unit ownership remains `0000JQ`, with `RECONSTRUCTABLE:FALSE` and blank emitter.
- Confidence remains below the high 90s because original symbols, exact `const` spelling, and exact original helper/method identifiers are inferred. Body behavior, ABI, owner, fields, call route, and source placement are directly supported.

## Supporting Research

- Before drafting, B004 searched agent goals, active research directories, and executed research for `UID00015Y`, `0x004b89a0`, `SwitchActiveChild`, `GeneralPurposePanel2`, `sub_4B89A0`, `0x00544ee0`, `sub_544EE0`, `+0x48`, and `OnActivate`. No retained B004 report for this assignment existed.
- Historical B003 `00015V-GeneralPurposePanel-source-quality.md`, B005 `00015X-GeneralPurposePanelSwitchActiveTab-source-quality.md`, B011 `00015W-GeneralPurposePanelChildAccessors-source-quality.md`, and B011 `0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` were used as leads, not as substitutes for current binary evidence.
- B005's prior no-code proof was valid for its evidence state: `0x00544ee0`, helper slot `+0x0c`, and child slot `+0x48` lacked source-quality names. This pass resolves all three through fresh helper decompilation, raw Pane/PanelPane vtable cells, and derived-slot behavior. The old blank-emitter disposition is therefore historical, not a current blocker.
- Live MCP evidence was collected on 2026-07-13 from database `328356ab`. A fresh `idb_list` listed that NexusTK worker, and `server_health(database=328356ab)` returned `ok` with auto-analysis, Hex-Rays, and strings ready when the evidence was collected. No indefinite availability assertion is made.
- The IDB identified `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, and imagebase `0x00400000`. B004 performed no MCP process-management or IDB write action.
- Historical pre-callback generated evidence from command `000000009304`, refreshed `2026-07-13T06:01:17-04:00`, showed UID00015X and UID00015Y Empty Emitter Markers and UID00015W inside an unclosed class. Final waited refresh `000000009370`, refreshed `2026-07-13T06:44:11-04:00`, supersedes that snapshot and proves the repaired emitted structure described under Validator Results.
- The read-only tracker row at evidence time showed UID00015Y at `86/90`, reconstructable, `Nested:0`, and no report link. Those are pre-report derived facts and must not be frozen as post-callback truth.
- Historical report-only boundary: before Gate 1, B004 edited no by-* document, acquired no lease, and ran no validator or lifecycle command. During the supervisor-authorized callback B004 edited only the listed ordinary by-* pages under short leases, ran scoped validators plus one waited refresh, and updated this report. B004 manually edited no generated output, coverage report, tracker, supervisor state, validator-owned state, IDA state, or lifecycle artifact, and ran no `execute_report`, move, or archive command.

## Target

- Target UID: `00015Y`.
- Target path: `by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md`.
- B004 artifact path at creation: `tools/leaser/Agents/Agent-B004/research/00015Y-GeneralPurposePanel2SwitchActiveChild-empty-emitter-source-quality.md`. Later validation, execution, count, path, move, and archive state is external supervisor/validator-owned state.
- Assignment classification: implemented reconstructable empty-emitter correction with exact body, source signature, field model, caller semantics, inherited API names, source placement, support synchronization, and score/metadata resolution complete.
- Evidence-time documented metadata: `86/90`, `CANONICAL_OWNER:00005R`, `EMITTER_UIDS:00005R`, `RECONSTRUCTABLE:TRUE`, blank position, blank formal C++, and `Nested:0`.
- Current callback metadata: `91/93` with owner, emitter, reconstructable state, position, range, and nesting preserved.

## Current Target State

- The target page records the corrected `0xdf` function size, exact exclusive end `0x004b8a7f`, one direct caller, one-child bound, old/new child flow, rectangle, and FrameChrome dependencies at report-level detail.
- Its Item Summary and score are current at `91/93`; the direct parents clear the gate, and source entry is blocked neither by score nor by body uncertainty.
- Class support uses `Pane *m_childPanes[1]` and `const unsigned char *packetData`; the concrete `NewSystemMessagePane` element-zero identity remains separately documented.
- Formal C++ contains the exact accepted managed method body and the waited generated output contains it exactly once with no target Empty Emitter Marker.
- No target split is required. The target is one modeled source method; the byte at `0x004b8a7f` is alignment and the next modeled helper starts at `0x004b8a80`.

## Executive Recommendation

- Emit the target method exactly once through [UID:00005R] after a closed class declaration and `[[CHILDREN]]` marker.
- Use `Pane *m_childPanes[1]` and `int m_activeChildIndex`, preserving `NewSystemMessagePane` as the concrete object stored in element zero.
- Use `const unsigned char *packetData` for the second argument. The pointer width regenerates the same two-dword `thiscall` ABI and `retn 8` while expressing the proven packet-data family.
- Introduce exact `Pane::Collapse` support before target emission and document `Pane::OnActivate` centrally before synchronizing derived behavior aliases.
- Keep broad aggregate, vtable bytes, padding, adjustor thunks, scalar deleting wrappers, and singleton storage non-emitting or source-declared/generated-binary as appropriate.

## Supervisor Active Recheck

- At research time B004 found no duplicate retained UID00015Y report or conflicting active assignment.
- The target, class/file/aggregate, sibling switch, caller, Pane/PanelPane support, derived `+0x48` implementations, globals, FrameChrome helpers, generated output, tracker snapshot, and matching archived reports were inspected.
- Database `328356ab` was healthy when all recorded live binary evidence was collected. The report does not claim that any MCP session remains available after evidence collection.
- Gate 1 callback authorization for exact SHA `512AD87DD930349682D9A13A08A54A24727374085B824351024D0BCA36759440` was received and C01-C32 were applied. Implementation and validators are complete; report execution, count, current path, move, and archive state remain external supervisor/validator-owned facts and are neither asserted nor directed here.

## Inference Research Guidance Check

- Direct facts, documentation facts, and source-shape inferences are separated.
- Direct facts include exact bytes/ranges, `retn 8`, stack-argument count, sole caller, field displacements, branch order, virtual offsets, vtable targets, derived slot bodies, and helper caller sets.
- Inferences include `SwitchActiveChild`, `packetData`, `Pane::Collapse`, `Pane::OnActivate`, member names, and `const`. Each is selected from project conventions and constrained by direct behavior.
- Decompiler placeholders (`sub_4B89A0`, `sub_544EE0`, `dword_67A740`, `dword_69B368`), raw slot dispatch, and generated-owner labels are not promoted into source C++.
- The recommendation preserves mid-2000s C++ shape: `NULL`, explicit local variables, ordinary pointers, no modern library abstractions, and no invented guard or ownership behavior.

## Heuristic / Inference Reanalysis And Validation

- **Boundary blocker resolved:** `lookup_funcs` and `analyze_function` identify `sub_4B89A0` at `0x004b89a0` with size `0xdf` and half-open end `0x004b8a7f`. Disassembly ends with `retn 8` at `0x004b8a7c`; `0x004b8a7f` is `0xcc` and `0x004b8a80` begins the next `0xb` helper.
- **Signature blocker resolved:** the binary is a `thiscall` receiver plus two four-byte stack arguments. The first is a signed child index. The second flows to inherited slot `+0x48`, whose derived family either reads packet bytes or ignores the pointer. Use `const unsigned char *packetData`, not `bool`, `int`, or `void *`.
- **Return blocker resolved:** the only caller ignores EAX, and control paths leave incidental unrelated values. The source method is `void`; IDA's integer guess is decompiler residue.
- **Index blocker resolved:** the binary tests only `childIndex >= 1`. Negative values are not rejected, and `-1` is deliberately handled as the no-active-child sentinel. Do not add `childIndex < -1` or `childIndex < 0` guards.
- **Access blocker resolved:** the sole direct call is from `UserPane::OnServerMessage` through the global singleton, so this is a public cross-class operation, not a private constructor helper.
- **Name blocker resolved:** `SwitchActiveChild` is stronger than `SwitchActiveTab` for the one-child SystemMessage panel shell. `SwitchActiveTab` remains the correct primary seven/four-child sibling name and a weaker target alternative.
- **Field blocker resolved:** both the switch and adjacent accessor use scaled `[this + index*4 + 4]` addressing. Use `Pane *m_childPanes[1]`. A singular `m_systemMessagePane` would require source pointer arithmetic unsupported by class conventions.
- **Concrete child identity preserved:** constructor evidence still proves `m_childPanes[0]` receives a `NewSystemMessagePane`. The interface field type and concrete allocation type are different facts.
- **Active field resolved:** `this+0x08` is read as a signed index, compared with `-1`, and overwritten with the requested index. `int m_activeChildIndex` remains the accepted name/type.
- **Totem cleanup resolved:** global `0x0069b35c` is [UID:0000SK] `g_pTotemFrame`; non-null state calls Pane `0x00544690`, accepted as `MarkForDeletion()`. This is a dependency, not target ownership.
- **Collapse helper resolved:** `0x00544ee0-0x00544f2e` has only the two panel switch callers. It calls primary `+0x38` (`RemoveFromLayer`), creates an all-zero 16-byte rectangle, and calls primary `+0x0c`.
- **Helper slot `+0x0c` resolved:** raw Pane/PanelPane primary vtables map the slot to `0x004b8e20`. Existing GrafPort/collection conventions and the zero-rectangle contract support `UpdateRenderRegion(const RectBounds *)`. `SetBounds` is rejected because Pane `SetBounds` is independently at `+0x2c`.
- **Helper name resolved:** `Collapse` best expresses detach plus zero render region. `Hide` is rejected because Pane `Hide` is a distinct `+0x18` virtual at `0x00544750`. `Deactivate` is weaker and collides semantically with the separate `+0x48` activation hook.
- **New-child slots resolved:** `+0x2c/+0x30/+0x3c` remain `SetBounds`, `AddToLayer`, and `SetPaneOrder`. Their arguments resolve through [UID:00028J] `g_pBackPane` and [UID:0000T6] `g_mainUiLayerSlots.rootPaneLayerContext`.
- **Activation slot `+0x48` resolved:** PanelPane's base entry is `__purecall`, while derived entries are live activation/open hooks. NewOption refreshes options, NewGroup requests the list, inventory panes refresh, NewSystem rebuilds message panes, and Collection/SelfLook/UserLook parse packet data.
- **Activation name resolved:** `OnActivate` is already the accepted source-facing NewOption name and best common virtual contract. Derived labels such as `RequestGroupList`, `InitializeCollectionData`, `OnReceiveCharacterData`, and `ParseLookPacket` remain behavior aliases, not distinct base slot signatures.
- **Activation type resolved:** Collection, SelfLook, and UserLook dereference the argument as packet data. NewOption, NewGroup, inventory panes, and NewSystem ignore it. This excludes `bool showChild` and supports a nullable byte pointer.
- **Caller-message blocker resolved:** `UserPane::OnServerMessage` checks one-time byte `this+0x3e1a`, calls the target with `childIndex=0` and `packetData=NULL`, sets the byte, then dispatches on `payload[0]` through a 128-case switch. The target call is one-time panel initialization before opcode dispatch, not one packet opcode body.
- **FrameChrome dependency resolved:** `0x004615b0` and `0x004615d0` remain `ReleaseDynamicAboveFrame()` and `RecreateDynamicAboveFrame()`. Both execute after the optional new-child branch, including the `-1` sentinel path.
- **Sibling blocker resolved:** UID00015X used the same unresolved helper and virtual. Its 35-call fan-in supplies non-null packet pointers at MapPane sites and proves the shared second parameter is pointer-compatible. Unlike UID00015Y, UID00015X collapses/unregisters the old child before storing the new active index; the sibling formal block preserves that order.
- **Aggregate blocker resolved:** UID00015V combines two classes, exact children, constructors/destructors, compiler wrappers, singleton helpers, and padding. It is a non-emitting split/index, not one reconstructable body.
- **Generated structure blocker resolved in recommendation:** both class declarations must close before `[[CHILDREN]]`. This keeps exact method definitions outside class bodies.
- **Score blocker resolved:** owner, range, body, ABI, caller, fields, dependencies, and placement are proven. Remaining original-spelling uncertainty supports `91/93` rather than `95+`.

## Evidence Standards Used

- IDA MCP: fresh `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `xrefs_to`/xref queries, `callees`, signatures, and raw vtable reads.
- Binary evidence: function extents, instruction ordering, stack cleanup, field displacements, virtual offsets, direct calls, singleton reads, caller packet flow, derived implementation bodies, and vtable cells.
- Documentation evidence: target, class/file/aggregate/sibling pages, PaneCore, Pane/PanelPane class/file/vtable docs, derived panel docs, globals, FrameChrome, RectBounds, caller, generated output, tracker, and archived reports.
- Inference evidence: source names, member names, pointer `const`, access declaration, and exact common virtual spelling.
- Negative evidence: no symbol/UDT/PDB source spelling, no bool consumer, no lower-bound test, no return consumer, no singular-field addressing, no target-owned collapse helper, and no monolithic aggregate body.

## Evidence Checked

- MCP health and database identity before binary analysis.
- Target function lookup, full decompile/disassembly, exact bytes, unique signature, predecessor neighborhood, successor helper, callers, callees, and xrefs.
- Sole caller `0x005a76c0-0x005a82bd` around `0x005a76f6-0x005a7727`, including event payload load, one-time flag, target arguments, and subsequent opcode switch.
- Collapse helper `0x00544ee0-0x00544f2e`, its complete caller set, virtual calls, zero local rectangle, and exact successor.
- Pane and PanelPane primary vtable cells at `0x006219e8` and `0x00621a70`, including `+0x0c`, `+0x38`, `+0x40`, and `+0x48`.
- Derived `+0x48` entries: NewSystemMessagePane `0x00588800`, NewOptionPane `0x00540240`, NewGroupPane `0x0056cb80`, NewInventoryPane `0x004eb550`, NewSpellInventoryPane `0x0057d080`, SelfLookPane `0x00565890`, UserLookPane `0x0059f610`, and CollectionPane `0x0056ea30`.
- UID00015X full body and representative MapPane calls at `0x00508040`, `0x00508679`, and `0x00508cb2`, which pass a pane index plus packet pointer.
- Current by-* metadata/formal blocks and read-only generated/tracker snapshots.
- Historical research phase made no by-* edit, lease, validator, generated refresh, report execution, lifecycle command, move, archive, or IDA write. The accepted callback later made only the bounded edits and validator-generated side effects recorded below; B004 still performed no report execution, lifecycle command, move, archive, manual generated edit, or IDA write.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Proposed action | Callback verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target exact half-open range is `0x004b89a0-0x004b8a7f`, size `0xdf`. | High | MCP lookup/analyze/bytes | UID00015Y metadata/boundary | preserve and refresh proof | Applied and scoped-validated by `000000009335`; range and size retained. |
| C02 | Final instruction is `retn 8` and `0x004b8a7f` is alignment before successor `0x004b8a80`. | High | disasm/bytes/lookup | UID00015Y boundary/padding | preserve exact source/padding split | Applied by `9335`; source/padding split and successor retained. |
| C03 | Source owner/emitter remains GeneralPurposePanel2 UID00005R through file UID0000JQ. | High | receiver layout, constructor, docs, generated route | UID00015Y/class/file | preserve metadata and route | Applied by `9335`, `9337`, and `9343`; waited output routes through UID0000JQ. |
| C04 | Source return type is `void`. | High | ignored EAX; path residue | UID00015Y formal/signature | replace IDA int guess | Exact `void` signature applied by `9335` and emitted once by `9370`. |
| C05 | First argument is signed `int childIndex` with upper-bound-only `>=1` rejection and valid `-1` sentinel. | High | target branches/field use | UID00015Y formal/behavior | preserve exact guard semantics | Exact guard/sentinel body applied by `9335`; generated body matches. |
| C06 | Second argument is nullable `const unsigned char *packetData`, not bool. | High | derived +0x48 family; sibling callers | target/class/file/vtables | replace stale showChild type | Applied across target/classes/file/vtables by `9335`, `9337`, `9343`, `9349`, `9351`, `9357`, and `9359`. |
| C07 | Best target name is `SwitchActiveChild`; `SwitchActiveTab` remains sibling-only. | Medium-high | one-child role/project naming | target/class/file | preserve name, explain inference | Names retained separately in target/sibling and generated exactly once each. |
| C08 | Method is public because UserPane calls it through the singleton. | High | sole external caller | class UID00005R | retain public declaration | Public declaration applied by `9337`; caller proof synchronized by `9362`. |
| C09 | Field model is `Pane *m_childPanes[1]` at +4 and `int m_activeChildIndex` at +8. | High | scaled accesses/accessor/sibling | class/target/file/aggregate | replace singular field model | Applied at report detail by `9335`, `9337`, `9343`, and `9345`; emitted class matches. |
| C10 | `m_childPanes[0]` concretely points to NewSystemMessagePane after construction. | High | constructor call/store | class/file/aggregate | preserve concrete identity separately | Preserved separately from interface-array typing by `9337`, `9343`, and `9345`. |
| C11 | `g_pTotemFrame->MarkForDeletion()` is an external Pane dependency. | High | global refs/call 0x544690 | target/sibling | preserve exact conditional call | Preserved in both exact bodies by `9335` and `9349`; dependency page unchanged. |
| C12 | `0x00544ee0-0x00544f2e` is source-authored Pane behavior with only UID15X/UID15Y callers. | High | analyze/callers/vtables | new PaneCollapse child/PaneCore | split exact child | Created first as UID0004KU by `9330`, then linked by `9353`, `9355`, `9356`, and `9357`. |
| C13 | Best helper name/body is `Pane::Collapse`: RemoveFromLayer then zero-region UpdateRenderRegion. | Medium-high | helper body and slot map | new child/Pane docs | insert exact managed body | Exact managed body applied by `9330`; `9370` emits it exactly once with no marker. |
| C14 | New PaneCollapse child uses owner/emitter UID0000A2, score `89/92`, blank position, and `Nested:0`. | High | source route and relative nesting sequence | new child metadata | create/register before links | Validator `9330` assigned UID0004KU and registered exact `89/92` metadata before any links. |
| C15 | Primary slot `+0x0c` is `UpdateRenderRegion`, not SetBounds. | High | vtable target 0x4b8e20; +0x2c distinct | Pane/PanelPane vtables | resolve stale slot caveat | Applied in PaneCore/Pane/PanelPane support by `9353`, `9355`, `9356`, `9357`, `9359`, `9360`, and `9361`. |
| C16 | Primary slot `+0x48` is best declared `OnActivate(const unsigned char *)`. | Medium-high | pure base slot and eight derived bodies | Pane/PanelPane vtables/class/file | document common contract | Applied centrally and to named derived owners by `9355`-`9368`; pure base and behavior aliases preserved. |
| C17 | NewSystem `0x588800` ignores its argument and rebuilds panes; `newMessageCount` is false. | High | live decompile | NewSystemMessagePane class | relabel as OnActivate; retain behavior alias | Applied content-only by `9364`; score/formal no-code proof preserved. |
| C18 | NewGroup `0x56cb80` is the +0x48 activation override; `0x56cc80` is layout/update-region behavior. | High | vtable ref and bodies | NewGroupPane class | correct swapped semantic labels | Applied content-only by `9366`; historical behavior aliases preserved. |
| C19 | Collection `0x56ea30` is the same OnActivate override and consumes packet data. | High | vtable ref/body | Collection class and UID0003Y3 | add common-contract name; retain behavior alias | Applied by `9367` and `9368`; class stays `89/90`, child is `88/91`, typed evidence preserved. |
| C20 | Target uses exact new-child sequence SetBounds/AddToLayer/SetPaneOrder/OnActivate. | High | target virtual calls/support | UID00015Y formal/behavior | insert exact calls | Exact sequence applied by `9335` and verified in waited generated body. |
| C21 | Layer arguments are `g_pBackPane` and `g_mainUiLayerSlots.rootPaneLayerContext`. | High | global docs/argument flow | target/sibling/file | replace raw globals | Applied to both bodies/file support by `9335`, `9343`, and `9349`; dependency pages unchanged. |
| C22 | Target rectangle is exactly `(832,376,1021,641)`. | High | immediate args/RectBounds call | target formal/behavior | preserve exact constants | Applied by `9335`; generated target body contains exact constants. |
| C23 | Target always calls ReleaseDynamicAboveFrame and RecreateDynamicAboveFrame after switching logic. | High | control flow/callees | target formal/FrameChrome dependency | preserve unconditional tail calls | Applied by `9335`; waited output preserves unconditional tail pair. |
| C24 | Sole caller performs one-time child-zero initialization before 128-case packet dispatch. | High | UserPane body around 0x5a771b | target/caller UID0003VB | add exact caller note | Applied to target and UID0003VB by `9335` and `9362`; no-whole-method proof preserved. |
| C25 | UID00015X's prior no-code proof is superseded because all three blockers are resolved. | High | helper/vtable/derived-family pass | UID00015X | insert exact managed body and historicalize proof | Applied by `9349`; exact sibling body emitted once by `9370`, old proof historicalized. |
| C26 | GeneralPurposePanel class must use pointer activation signature and close before `[[CHILDREN]]`. | High | sibling body/generated structure | class UID00005Q | replace exact class block | Applied by `9351`; `9370` structural regex count is one closed class before UID00015W/UID00015X. |
| C27 | GeneralPurposePanel2 class must close before `[[CHILDREN]]`. | High | generated insertion behavior | class UID00005R | replace exact class block | Applied by `9337`; `9370` structural regex count is one closed class before UID00015Y. |
| C28 | UID00015V is a non-emitting split/index, not a reconstructable blank body. | High | mixed range and exact children | aggregate UID00015V | set false/blank emitter; preserve owner/range | Applied by `9345`; UID00015V count in waited generated C++ is zero. |
| C29 | Target score should move `86/90 -> 91/93` with all routing metadata preserved. | High | complete body/ABI/route; inferred spellings | UID00015Y metadata | apply exact score | Applied by `9335`; waited output header reports `91/93`. |
| C30 | Support scores move only where target blocker resolution materially improves the page. | High | scoped documentation audit | listed support docs | apply score table below; no unrelated inflation | Applied exactly by scoped validators `9337`-`9368`; content-only pages retained scores and unchanged dependencies were not edited. |
| C31 | Generated verification must show one target and one sibling body, no target/sibling marker, and class methods outside closed classes. | High | accepted emission model/current defect | waited generated output | verify read-only after callback | Verified by waited `9370`: target/sibling UID and body counts `1/1`, marker counts `0/0`, class-closure regex counts `1/1`, aggregate/compiler-only counts `0`. |
| C32 | B004 report phase changes only this report and performs no validator/lifecycle action. | High | task boundary/file audit | report Changed Files/Validator Results | preserve boundary | Historical Gate 1 boundary preserved; callback used only bounded leases/validators, all leases released, and B004 ran no execute/lifecycle/move/archive command. |

## Positive Evidence Summary

- Exact method bounds, stack cleanup, caller count, field offsets, branch order, rectangle, helper calls, and frame refresh are live-IDB facts.
- The caller establishes public singleton use and one-time initialization semantics.
- The sibling establishes the shared pointer argument through real non-null payload call sites.
- Scaled child addressing in both switch/accessor families establishes an array model.
- Collapse helper behavior and ownership are exact; only its source spelling is inferred.
- Raw vtables resolve the old `+0x0c` ambiguity and establish a pure common `+0x48` contract.
- Eight derived `+0x48` bodies establish nullable packet-data semantics and activation behavior.
- Existing source routes already place both classes in `GeneralPurposePanel.cpp` and Pane support in `Pane.cpp`.

## IDA MCP Facts

| Subject | Live evidence collected on 2026-07-13 |
| --- | --- |
| Database | `328356ab` was listed and healthy at evidence time; NexusTK imagebase `0x400000`. |
| Target | `sub_4B89A0`, start `0x4b89a0`, size `0xdf`, end `0x4b8a7f`. |
| Target ABI | ECX receiver, two dword stack arguments, `retn 8`. |
| Target signature | Unique pattern `55 8B EC 83 EC 18 A1 ? ? ? ? 33 C5 89 45 ? 8B 45 ? 53 57`. |
| Target xrefs | One direct code xref at `0x5a771b`. |
| Target callees | `0x544690`, `0x544ee0`, `0x4b78d0`, `0x4615b0`, `0x4615d0`, security-cookie support, plus virtual dispatch. |
| Caller | `UserPane::OnServerMessage` at `0x5a76c0`, size `0xbfd`. |
| Collapse helper | `0x544ee0`, size `0x4e`, end `0x544f2e`; callers only `0x4b8650` and `0x4b89a0`. |
| Pane slot +0x0c | Primary vtable cell resolves to `0x4b8e20` / UpdateRenderRegion behavior. |
| Pane slots | `+0x2c SetBounds`, `+0x30 AddToLayer`, `+0x38 RemoveFromLayer`, `+0x3c SetPaneOrder`, `+0x40 UnregisterEventHandler`. |
| Activation slot | PanelPane primary `+0x48` is `__purecall`; eight derived tables replace it with live methods. |
| Successor | `0x4b8a80` is a separate `0xb` singleton-clear helper. |

## Function / Child Inventory

| Range/address | Source-quality identity | Disposition |
| --- | --- | --- |
| `0x004b83d0-0x004b8bd3` | GeneralPurposePanel source-unit aggregate UID00015V | Non-emitting split/index after callback. |
| `0x004b8650-0x004b8823` | `GeneralPurposePanel::SwitchActiveTab` UID00015X | Source method; exact body now supportable. Filename's final address remains inclusive `0x004b8822`. |
| `0x004b8950` modeled accessor neighborhood | GeneralPurposePanel2 child accessor | Preserve existing aggregate/class evidence; not part of target. |
| `0x004b89a0-0x004b8a7f` | `GeneralPurposePanel2::SwitchActiveChild` UID00015Y | Source method; emit exact target body. |
| `0x004b8a7f-0x004b8a80` | one `0xcc` byte | Compiler alignment; no source. |
| `0x004b8a80` | GeneralPurposePanel2 singleton clear helper | Separate source/compiler lifecycle support; not target. |
| `0x00544ee0-0x00544f2e` | `Pane::Collapse` | New exact source child under PaneCore. |
| `0x00544f2e-0x00544f44` | Pane adjustor thunks UID0001EB | Compiler-generated; preserve non-emitting. |

## Direct Xref / Caller Inventory

- Target code xrefs: exactly one, `0x005a771b` inside `UserPane::OnServerMessage`.
- `0x005a76f6` checks one-time state byte `[this+0x3e1a] == 0`.
- The event argument is `[ebp+8]` and its payload pointer is loaded from `event+0x0c` into EDI at `0x005a7706`.
- `0x005a7711-0x005a771b` loads `g_pGeneralPurposePanel2`, pushes `0` packet data, pushes child index `0`, and calls the target.
- `0x005a7720` sets the one-time byte to `1`.
- `0x005a7727` then reads `payload[0]` for the 128-case packet switch. This ordering excludes ownership by one opcode case.
- Collapse helper callers are exactly target `0x004b89ef` and sibling branches `0x004b86b9` and `0x004b8789`.
- Representative sibling MapPane calls at `0x00508040`, `0x00508679`, and `0x00508cb2` push EDI packet data plus indexes `1`, `0`, and `5`. These are direct negative evidence against `bool showChild`.

## Documentation Evidence And IDA Status

- UID00015Y already has correct owner/emitter/range/nesting but stale gate, bool, and blank-body wording.
- UID00005R already owns the target but has a singular child pointer, bool signature, and no safe post-class child marker.
- UID0000JQ has the accepted `NexusTK/ui/panels/` route but repeats stale singular/bool/helper caveats.
- UID00015V is a broad mixed aggregate still marked reconstructable/emitting despite intentionally blank C++.
- UID00015X has strong exact behavior and caller proof; its only three formal blockers are now resolved.
- PaneCore already indexes `0x00544ee0` but intentionally left its name and `+0x0c` unresolved.
- PaneVtables and PanelPaneVtables currently leave `+0x0c` and `+0x48` generic despite sufficient raw/derived evidence.
- UserPane caller UID0003VB documents the packet dispatcher but not the one-time GeneralPurposePanel2 initialization.
- NewSystemMessagePane incorrectly gives an unused argument the semantic name `newMessageCount`.
- NewGroupPane's behavior labels place `OnActivate` on the layout method instead of the common `+0x48` request method.
- CollectionPane/UID0003Y3 use a useful behavior name but do not state the common virtual contract.
- IDA session `328356ab` was healthy when this evidence was collected; no present-tense availability claim is made.

## Ranked Ownership Analysis

### 1. GeneralPurposePanel2 / GeneralPurposePanel.cpp

- Evidence for: receiver offsets match the class, constructor builds the one child, singleton caller uses the class, adjacent methods share the source unit, and current owner/emitter routing already agrees.
- Evidence against: none.
- Decision: retain UID00005R/UID0000JQ.

### 2. GeneralPurposePanel / GeneralPurposePanel.cpp

- Evidence for target ownership: shared algorithm and source unit.
- Evidence against: different receiver layout, child count, bounds, caller family, and class singleton.
- Decision: sibling support only; do not move UID00015Y.

### 3. UserPane

- Evidence for: sole direct caller.
- Evidence against: call uses `g_pGeneralPurposePanel2`; receiver and all state belong to GeneralPurposePanel2; caller immediately resumes packet dispatch.
- Decision: caller support only.

### 4. Pane / PanelPane

- Evidence for: owns Collapse and inherited virtual contracts consumed by the target.
- Evidence against target ownership: Pane receives old/new child calls but does not own the switching receiver or fields.
- Decision: dependency ownership only; split `Pane::Collapse` under Pane.

### 5. NewSystemMessagePane

- Evidence for: concrete object stored in child slot zero and `+0x48` override behavior.
- Evidence against target ownership: target receiver is the outer panel shell and works through Pane interface.
- Decision: derived child/dependency only.

### 6. FrameChrome

- Evidence for: owns the two tail refresh helpers.
- Evidence against target ownership: no target receiver/state ownership.
- Decision: dependency only.

## Source Placement

- Target and sibling: `NexusTK/ui/panels/GeneralPurposePanel.cpp` through [UID:0000JQ].
- Target class declaration: the corresponding GeneralPurposePanel header/class route represented by [UID:00005R]; exact physical header name is not proven and should not be invented in metadata.
- PaneCollapse: `NexusTK/ui/core/Pane.cpp` through [UID:0000MC].
- Common Pane/PanelPane virtual declarations: UI-core Pane/PanelPane header surface represented by class/vtable docs; do not create an ad hoc target-local wrapper.
- UserPane call-site note remains in UserPane documentation; no source move.
- NewSystem/NewGroup/Collection alias corrections remain in their established source routes.

## Range / Split / Padding / Reclassification Analysis

- UID00015Y remains one exact method page; do not split its internal basic blocks.
- Preserve half-open `0x004b89a0-0x004b8a7f`. Do not absorb `0x004b8a7f` alignment or `0x004b8a80` successor.
- Create exact child `by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md` under broad PaneCore. It starts and ends on exact function boundaries.
- New PaneCollapse `Nested:0` is proven from relative nesting semantics: PaneSetMode raises cumulative nesting with `Nested:4`; subsequent PaneGetDescription is `Nested:0` at that child level; PaneCollapse follows at the same level and therefore is `Nested:0`; existing PaneAdjustorThunks `Nested:-4` performs the lift.
- UID00015V should become `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS` and blank formal C++. Preserve `CANONICAL_OWNER:0000JQ`, exact range, `Nested:0`, inventory, historical evidence, source route, and child links.
- PaneCore remains `RECONSTRUCTABLE:FALSE` and blank-emitting. Exact Pane children carry source.
- Vtable data, adjustor thunks, scalar deleting wrappers, alignment, and singleton storage remain source-declared/generated-binary or ignored compiler output; no handwritten ABI body is recommended.

## Negative Evidence Summary

- No PDB, original source, UDT, or symbol proves the exact target/helper/virtual spelling.
- No caller consumes a target return value.
- No target instruction rejects negative indexes; adding a lower-bound guard would change behavior.
- No bool use exists for the second argument; packet-consuming derived methods and sibling packet call sites contradict bool.
- No singular child access exists in the switch/accessor family; scaled indexing contradicts `m_systemMessagePane` as the source field.
- No helper caller lies outside UID00015X/UID00015Y; helper ownership is Pane, not a feature caller.
- `Pane::Hide` is a distinct virtual and cannot name `0x00544ee0`.
- `Pane::SetBounds` is a distinct `+0x2c` slot and cannot name helper slot `+0x0c`.
- Derived `+0x48` methods do not share one behavior-specific name such as `RequestGroupList` or `InitializeCollectionData`; those are aliases under a common activation contract.
- No evidence supports target ownership by UserPane, NewSystemMessagePane, FrameChrome, SpellInputPanes, or generated polluted owners.
- No evidence supports monolithic C++ for UID00015V or PaneCore.

## IDA Rename / Type / Comment Recommendations

- No IDA database change is part of this report or proposed callback.
- If a separate supervisor-authorized IDA curation pass occurs, safe descriptive names are `GeneralPurposePanel2__SwitchActiveChild` for `0x004b89a0` and `Pane__Collapse` for `0x00544ee0`.
- A safe descriptive prototype is `void __thiscall GeneralPurposePanel2::SwitchActiveChild(int childIndex, const unsigned char *packetData)`.
- A safe helper prototype is `void __thiscall Pane::Collapse()`.
- Preserve comments that `-1` is the no-child sentinel, `+0x48` is the common activation hook, and exact source spellings remain inferred.
- Do not rename `0x00588800` to `RebuildMessagePanes(int newMessageCount)`; the argument is unused.

## First-Draft C++ Recommendation

### UID00015Y exact formal insertion

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void GeneralPurposePanel2::SwitchActiveChild(
    int childIndex,
    const unsigned char *packetData)
{
    if (childIndex >= 1)
        return;

    if (g_pTotemFrame != NULL)
        g_pTotemFrame->MarkForDeletion();

    Pane *oldChild = NULL;
    if (m_activeChildIndex != -1)
        oldChild = m_childPanes[m_activeChildIndex];

    m_activeChildIndex = childIndex;

    if (oldChild != NULL) {
        oldChild->Collapse();
        oldChild->UnregisterEventHandler();
    }

    if (m_activeChildIndex != -1) {
        Pane *newChild = m_childPanes[m_activeChildIndex];
        RectBounds bounds;
        bounds.SetLTRB(832, 376, 1021, 641);
        newChild->SetBounds(&bounds, 0);
        newChild->AddToLayer(
            &bounds,
            0,
            g_pBackPane,
            g_mainUiLayerSlots.rootPaneLayerContext);
        newChild->SetPaneOrder(0, g_pBackPane);
        newChild->OnActivate(packetData);
    }

    ReleaseDynamicAboveFrame();
    RecreateDynamicAboveFrame();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00005R exact class insertion

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel2 : public PanelPane
{
public:
    GeneralPurposePanel2();
    virtual ~GeneralPurposePanel2();

    Pane *GetChildPaneByIndex(int index);
    void SwitchActiveChild(
        int childIndex,
        const unsigned char *packetData);

private:
    Pane *m_childPanes[1];
    int m_activeChildIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### New PaneCollapse child exact formal insertion

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Pane::Collapse()
{
    RemoveFromLayer();

    RectBounds emptyBounds = { 0, 0, 0, 0 };
    UpdateRenderRegion(&emptyBounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### UID00015X exact formal insertion

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void GeneralPurposePanel::SwitchActiveTab(
    int tabIndex,
    const unsigned char *packetData)
{
    if (g_useEpfAssets == 1) {
        if (tabIndex >= 7)
            return;

        if (tabIndex == m_activeChildIndex &&
            tabIndex != 0 &&
            tabIndex != 1)
            return;

        if (g_pTotemFrame != NULL)
            g_pTotemFrame->MarkForDeletion();

        Pane *oldChild = NULL;
        if (m_activeChildIndex != -1)
            oldChild = m_childPanes[m_activeChildIndex];

        if (oldChild != NULL) {
            oldChild->Collapse();
            oldChild->UnregisterEventHandler();
        }

        m_activeChildIndex = tabIndex;

        Pane *newChild = NULL;
        if (tabIndex != -1)
            newChild = m_childPanes[tabIndex];

        RectBounds bounds;
        bounds.SetLTRB(832, 79, 1021, 367);
        newChild->SetBounds(&bounds, 0);
        newChild->AddToLayer(
            &bounds,
            0,
            g_pBackPane,
            g_mainUiLayerSlots.rootPaneLayerContext);
        newChild->SetPaneOrder(0, g_pBackPane);
        newChild->OnActivate(packetData);
        ReleaseDynamicAboveFrame();
        RecreateDynamicAboveFrame();
    } else {
        if (tabIndex >= 4)
            return;

        if (tabIndex == m_activeChildIndex &&
            tabIndex != 0 &&
            tabIndex != 1)
            return;

        if (g_pTotemFrame != NULL)
            g_pTotemFrame->MarkForDeletion();

        Pane *oldChild = NULL;
        if (m_activeChildIndex != -1)
            oldChild = m_childPanes[m_activeChildIndex];

        if (oldChild != NULL) {
            oldChild->Collapse();
            oldChild->UnregisterEventHandler();
        }

        m_activeChildIndex = tabIndex;

        Pane *newChild = NULL;
        if (tabIndex != -1)
            newChild = m_childPanes[tabIndex];

        RectBounds bounds;
        bounds.SetLTRB(434, 12, 626, 300);
        newChild->SetBounds(&bounds, 0);
        newChild->AddToLayer(
            &bounds,
            0,
            g_pBackPane,
            g_mainUiLayerSlots.rootPaneLayerContext);
        newChild->SetPaneOrder(0, g_pBackPane);
        if (packetData != NULL)
            newChild->OnActivate(packetData);
        g_pInterfaceEfxMgr->TriggerInterfaceEffect(m_activeChildIndex);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

The sibling block deliberately preserves the binary's lack of a safe `newChild` null guard after the `-1` path. Adding one would improve robustness but change exact behavior.

### UID00005Q exact class insertion

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel : public PanelPane
{
public:
    GeneralPurposePanel();
    virtual ~GeneralPurposePanel();

    Pane *GetChildPaneByIndex(int index);
    Pane *GetActiveChildPane();
    void DispatchActiveChildRefresh();
    void SwitchActiveTab(
        int tabIndex,
        const unsigned char *packetData);

private:
    Pane *m_childPanes[7];
    int m_activeChildIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No broad Pane, PanelPane, UID00015V, or PaneCore formal class/body block is recommended. Their exact children and declaration/vtable documentation carry the resolved contracts without inventing incomplete class shells.

## Final Recommendation

- Accept exact target emission and `91/93` metadata.
- Accept the one-child Pane-array class correction and pointer activation signature.
- Accept exact `Pane::Collapse` child creation before cross-references.
- Accept central `UpdateRenderRegion` and `OnActivate` contract synchronization.
- Accept UID00015X exact emission because its historical no-code proof has been fully discharged.
- Accept closed class declarations followed by `[[CHILDREN]]` to repair generated structure.
- Accept UID00015V non-emitting split/index reclassification.
- Preserve all negative evidence, historical aliases, compiler-generated dispositions, singleton identities, and source routes.

## Recommended Target Doc Changes

Callback result: every target item below was applied at full report detail and scoped-validated by command `000000009335`; final waited command `000000009370` emitted the target exactly once.

1. `by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md`:
   - Set `COMPLETION:91` and `CONFIDENCE:93`.
   - Preserve owner `00005R`, emitter `00005R`, reconstructable true, blank position, exact filename/range, and `Nested:0`.
   - Insert the exact managed target block above.
   - Replace stale Item Summary with: `Exact source-authored GeneralPurposePanel2::SwitchActiveChild body with 0xdf-byte boundary, retn-8 ABI, one-child upper-bound/-1 semantics, Pane child array and active index, TotemFrame deletion, Pane Collapse/unregister sequence, exact bounds/layer/activation calls, one-time UserPane caller, and FrameChrome refresh dependencies documented.`
   - Refresh Scope, Boundary, Behavior, Caller Evidence, signature/ABI, field model, dependency names, source placement, historical assumptions, rejected bool/singular/no-code alternatives, score rationale, and Changes at report-level detail.
   - Historicalize the old parent-gate, `bool showChild`, singular-field, unresolved-slot, and blank-emitter conclusions without deleting their provenance.

## Recommended Support Doc Changes

Callback result: every named support item below was applied under its own lease and scoped validator. New PaneCollapse received real UID `0004KU` before any cross-reference was added. The read-only unchanged-dependency list remained untouched.

1. `by-class/GeneralPurposePanel2.md` [UID:00005R]:
   - `85/90 -> 90/92`.
   - Preserve owner/emitter/reconstructable/position.
   - Apply the exact class block above; retain constructor, destructor, concrete NewSystemMessagePane, singleton, vtable, and history evidence.
2. `by-file/GeneralPurposePanel.md` [UID:0000JQ]:
   - `86/88 -> 89/91`; preserve `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"` and FILE ownership.
   - Synchronize pointer activation signatures, child array models, PaneCollapse/OnActivate dependencies, exact children, and post-class child emission. Preserve constructors, destructors, globals, vtables, compiler exclusions, and history.
3. `by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md` [UID:00015V]:
   - `86/91 -> 89/93`.
   - Set `RECONSTRUCTABLE:FALSE` and blank `EMITTER_UIDS`; preserve canonical owner `0000JQ`, blank position, exact range, `Nested:0`, and blank formal block.
   - Expand exact split inventory and historical evidence; state exact children emit and compiler material does not.
4. `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md` [UID:00015X]:
   - `88/93 -> 91/94`; preserve owner/emitter/reconstructable/position/range/nesting.
   - Apply the exact sibling block, replace stale no-code proof with resolved blocker history, and preserve every caller, branch, rectangle, dependency, padding, stale-owner rejection, and negative.
5. `by-class/GeneralPurposePanel.md` [UID:00005Q]:
   - `85/87 -> 89/91`.
   - Apply exact class block; preserve all existing methods/fields and only change the activation parameter plus post-class marker.
6. New `by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md`:
   - Create with validator-assigned UID before adding cross-references.
   - `89/92`, owner/emitter `0000A2`, reconstructable true, blank position, `Nested:0`, exact managed PaneCollapse body, exact range/callers/vtable proof, source route, inference caveat, alternatives, and history.
   - Item Summary: `Exact Pane::Collapse helper used only by GeneralPurposePanel switch methods; removes the pane from its layer, sends an all-zero RectBounds through UpdateRenderRegion, and has exact 0x00544ee0-0x00544f2e bounds, Pane ownership, callers, vtable contracts, source route, and rejected Hide/Deactivate aliases documented.`
7. `by-memory/0x00544460-0x00545086.PaneCore.md` [UID:0001EA]:
   - `88/90 -> 89/92`; remain non-emitting split/index.
   - Replace unresolved helper row with exact PaneCollapse child link and resolved `+0x0c` contract; preserve all other functions and compiler exclusions.
8. `by-class/Pane.md` [UID:0000A2] and `by-file/Pane.md` [UID:0000MC]:
   - Each `89/89 -> 90/91`.
   - Add PaneCollapse exact child and `OnActivate(const unsigned char *)`/UpdateRenderRegion contract prose. Keep class formal blocks blank; do not invent partial class declarations.
9. `by-type/by-vtable/PaneVtables.md` [UID:0003JA]:
   - `89/93 -> 90/94`.
   - Resolve `+0x0c` as UpdateRenderRegion and `+0x48` as pure/common OnActivate contract; preserve raw addresses and inference caveats.
10. `by-type/by-vtable/PanelPaneVtables.md` [UID:0001YD]:
    - `87/92 -> 88/93`.
    - Add derived `+0x48` matrix and common contract; retain `__purecall` base fact and all table/RTTI/thunk details.
11. `by-class/PanelPane.md` [UID:0000A4] and `by-file/PanelPane.md` [UID:0000ME]:
    - Content-only synchronization; scores stay `86/88`.
    - Record inherited common activation contract without adding a partial formal class shell.
12. `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` [UID:0003VB]:
    - Content-only synchronization; score stays `87/89`.
    - Add the exact one-time GeneralPurposePanel2 initialization sequence before opcode dispatch. Preserve its target-specific no-whole-method proof.
13. `by-class/NewSystemMessagePane.md` [UID:00009C]:
    - Content-only synchronization; score stays `85/86`.
    - Relabel `0x00588800` as the common `OnActivate(const unsigned char *packetData)` override with unused argument; retain `RebuildMessagePanes` as behavior alias and explicitly reject `newMessageCount`.
14. `by-class/NewGroupPane.md` [UID:000090]:
    - Content-only synchronization; score stays `85/86`.
    - Record `0x0056cb80` as the common OnActivate override whose behavior requests the group list; relabel `0x0056cc80` as UpdateRenderRegion/layout behavior. Preserve old names as historical behavior aliases.
15. `by-class/CollectionPane.md` [UID:00002X] and `by-memory/0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData.md` [UID:0003Y3]:
    - Class score stays `89/90`; exact child `87/90 -> 88/91`.
    - Record common OnActivate pointer contract while retaining InitializeCollectionData as the behavior alias and preserving all typed collection evidence.
16. Read-only unchanged dependencies after callback:
    - UID00015Q RectBounds, UID0000YI FrameChrome refresh, UID0000SK g_pTotemFrame, UID00028J g_pBackPane, UID0000T6 MainUiLayerSlots, UID0002VS GeneralPurposePanel2 storage, UID00018H InterfaceEfx, NewOption/NewInventory/NewSpellInventory/SelfLook/UserLook behavior pages, and compiler-support pages. They already support the required facts or serve only as evidence; do not inflate scores or formal C++.

## Score And Metadata Recommendation

| Page | Before | Applied current state | Metadata/disposition |
| --- | --- | --- | --- |
| UID00015Y target | `86/90` | `91/93` | owner/emitter 00005R, true, blank position, Nested0 preserved; exact body added |
| UID00005R class | `85/90` | `90/92` | owner/emitter preserved; typed array/pointer signature and marker |
| UID0000JQ file | `86/88` | `89/91` | path/FILE owner preserved |
| UID00015V aggregate | `86/91` | `89/93` | owner preserved; reconstructable false, emitter blank |
| UID00015X sibling | `88/93` | `91/94` | owner/emitter/range/nesting preserved; exact body added |
| UID00005Q class | `85/87` | `89/91` | owner/emitter preserved; pointer signature and marker |
| UID0004KU PaneCollapse | none | `89/92` | validator-assigned UID; owner/emitter 0000A2; true; blank position; Nested0 |
| UID0001EA PaneCore | `88/90` | `89/92` | remains false/non-emitting |
| UID0000A2 Pane class | `89/89` | `90/91` | routing preserved; formal remains blank |
| UID0000MC Pane file | `89/89` | `90/91` | path preserved |
| UID0003JA PaneVtables | `89/93` | `90/94` | routing preserved; prose/data contract only |
| UID0001YD PanelPaneVtables | `87/92` | `88/93` | routing preserved; prose/data contract only |
| UID0003Y3 Collection activation child | `87/90` | `88/91` | owner/emitter/range/nesting preserved; common contract note |
| Other named support | existing | unchanged | content-only where listed; no score/formal inflation |

## Open Questions With Attempted Resolution

| Question | Routes checked | Resolution |
| --- | --- | --- |
| Was the original method named SwitchActiveChild or SwitchActiveTab? | class/file conventions, one-child role, sibling naming, call sites | SwitchActiveChild is highest probability; exact spelling remains inferred. |
| Is the second argument bool? | sole caller, sibling callers, eight derived +0x48 bodies | No. Nullable packet-data pointer is strongly supported. |
| Is the child field singular? | target and accessor scaled addressing, sibling class layout, constructor | No. Pane pointer array of one, with concrete NewSystem child at element zero. |
| What is helper 0x544ee0? | full body, all callers, Pane slots, alternative Pane methods | Pane::Collapse is highest probability and body is exact. |
| What is helper slot +0x0c? | raw Pane/PanelPane vtables, target 0x4b8e20, distinct +0x2c SetBounds, collection conventions | UpdateRenderRegion. |
| What is slot +0x48? | pure base slot plus eight derived table/body checks | Common OnActivate(const unsigned char *) contract. |
| Should target add a lower-bound/null guard? | exact branches and -1 sentinel | No; that changes binary behavior. |
| Is UID15V source-bearing? | full mixed inventory and exact children | It is a source-unit index, but not a reconstructable emitting body. |
| Can any blocker be deferred? | all named helper, slot, caller, field, ABI, source-route checks | No in-scope blocker remains unresolved beyond explicitly scored original-spelling inference. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

N/A. Coverage and tracker rows are validator-generated and supervisor/validator-owned. This report supplies Item Summary text and metadata for ordinary docs only; no manual coverage/tracker edit is recommended.

## Follow-Up Actions

- Research, exact managed blocks, metadata changes, support synchronization, scoped validation, lease release, and waited generated verification are complete. No implementation item remains.
- B004 itself performed no `execute_report`, lifecycle probe, move, or archive command. Validation, report execution, count, current path, move, and archive state are external supervisor/validator-owned facts and are neither asserted nor directed by this artifact.
- The historical research-phase recommendations remain in this report as provenance; current callback truth is the applied C01-C32 ledger, validator table, changed-file inventory, generated proof, and checked callback checklist below.

## Confidence

- Target boundary/body/ABI/caller/field behavior: high.
- Owner/emitter/source placement: high.
- PaneCollapse behavior and ownership: high; exact original name medium-high.
- `+0x0c` UpdateRenderRegion contract: high.
- `+0x48` packet pointer contract: high; exact OnActivate spelling medium-high.
- Member names and pointer `const`: medium-high.
- Overall target recommendation: `91/93`.

## Validator Results

- All commands ran from `source-3/project-documentation` as `python .\tools\validator.py --mode file --file '<file>' --apply --queue-timeout 240`; only final command `000000009370` added `--wait-generated`.

| File / purpose | Command ID | Timestamp | Exit / ok | Result and validator-owned side effects |
| --- | --- | --- | --- | --- |
| New `by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md` | `000000009330` | `2026-07-13T06:30:34-04:00` | `0`; successful UID assignment (no literal `ok` counter printed) | Assigned real UID `0004KU`; registered path/owner/emitter/score/references; generated refresh deferred. |
| UID00015Y target | `000000009335` | `2026-07-13T06:31:50-04:00` | `0`; `ok:1` | Applied `91/93`, exact managed body, metadata and reference updates; generated deferred. |
| UID00005R GeneralPurposePanel2 class | `000000009337` | `2026-07-13T06:32:43-04:00` | `0`; `ok:1` | Applied exact closed class/array/pointer block; generated deferred. |
| UID0000JQ GeneralPurposePanel file | `000000009343` | `2026-07-13T06:34:10-04:00` | `0`; `ok:1` | Applied `89/91` route/detail sync; one pre-existing missing-ref warning for UID0003A2; generated deferred. |
| UID00015V aggregate | `000000009345` | `2026-07-13T06:34:52-04:00` | `0`; `ok:1` | Applied `89/93`, false/non-emitting split index; two pre-existing UID0003A2 missing-ref rows; generated deferred. |
| UID00015X sibling | `000000009349` | `2026-07-13T06:36:21-04:00` | `0`; `ok:1` | Applied `91/94` exact body and historicalized no-code proof; pre-existing UID0003UT missing-ref warning; generated deferred. |
| UID00005Q GeneralPurposePanel class | `000000009351` | `2026-07-13T06:36:52-04:00` | `0`; `ok:1` | Applied exact pointer signature and class-before-children block; pre-existing UID0003BC missing-ref warning; generated deferred. |
| UID0001EA PaneCore | `000000009353` | `2026-07-13T06:37:34-04:00` | `0`; `ok:1` | Applied `89/92`, UID0004KU index link, and slot contracts; remained non-emitting; generated deferred. |
| UID0000A2 Pane class | `000000009355` | `2026-07-13T06:38:49-04:00` | `0`; `ok:1` | Applied `90/91` child/contract prose, kept formal blank; generated deferred. |
| UID0000MC Pane file | `000000009356` | `2026-07-13T06:39:38-04:00` | `0`; `ok:1` | Applied `90/91` route/contract detail; two pre-existing UID0003CA missing-ref rows; generated deferred. |
| UID0003JA PaneVtables | `000000009357` | `2026-07-13T06:40:24-04:00` | `0`; `ok:1` | Applied `90/94`, raw `+0x0c/+0x48` resolution; two pre-existing UID0003CA warnings; generated deferred. |
| UID0001YD PanelPaneVtables | `000000009359` | `2026-07-13T06:40:58-04:00` | `0`; `ok:1` | Applied `88/93`, pure base and eight-entry derived matrix; generated deferred. |
| UID0000A4 PanelPane class | `000000009360` | `2026-07-13T06:41:20-04:00` | `0`; `ok:1` | Content-only inherited-contract sync; score/formal shell unchanged; generated deferred. |
| UID0000ME PanelPane file | `000000009361` | `2026-07-13T06:41:42-04:00` | `0`; `ok:1` | Content-only route/contract sync; score unchanged; generated deferred. |
| UID0003VB UserPane caller | `000000009362` | `2026-07-13T06:42:09-04:00` | `0`; `ok:1` | Added exact one-time call sequence; preserved no-whole-method proof; 25 pre-existing missing-ref rows (15 suppressed); generated deferred. |
| UID00009C NewSystemMessagePane | `000000009364` | `2026-07-13T06:42:33-04:00` | `0`; `ok:1` | Content-only OnActivate/behavior-alias correction; eight pre-existing UID0003GN missing-ref rows; score/formal unchanged; generated deferred. |
| UID000090 NewGroupPane | `000000009366` | `2026-07-13T06:42:56-04:00` | `0`; `ok:1` | Content-only `0x56cb80/0x56cc80` semantic correction; score/formal unchanged; generated deferred. |
| UID00002X CollectionPane | `000000009367` | `2026-07-13T06:43:18-04:00` | `0`; `ok:1` | Content-only common-contract sync; 23 pre-existing exact-child missing-ref rows; score/formal unchanged; generated deferred. |
| UID0003Y3 Collection activation child | `000000009368` | `2026-07-13T06:43:50-04:00` | `0`; `ok:1` | Applied `88/91`, Item Summary/common contract; validator normalized one header blank and refreshed registry/references; generated deferred. |
| Final UID00015Y waited refresh | `000000009370` | `2026-07-13T06:44:11-04:00` | `0`; `ok:1`; `18.2s` | `generated_refresh: completed`; rebuilt 4,611-node/3,759-edge autogen registry and refreshed 281 generated metadata artifacts. Broad unrelated warnings were reported but did not fail validation. |

- Read-only `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp` header records validator command `000000009370`. Counts: UID00015Y record/body `1/1`, UID00015X record/body `1/1`, target/sibling Empty Emitter Markers `0/0`, UID00015V records `0`, and UID0001EB/UID0001ED compiler-thunk records `0`.
- Structural regex checks each returned `1`: closed `GeneralPurposePanel` before UID00015W children, closed `GeneralPurposePanel2` before UID00015Y, UID00015X definition outside the first class, and UID00015Y definition outside the second class.
- Read-only `auto-generated/NexusTK/ui/core/Pane.cpp` counts are UID0004KU record/body `1/1` and UID0004KU Empty Emitter Marker `0`.
- Validator-owned side effects include `validator.ini`/autogen-registry, reference-index, projected-stat, coverage-metadata, and generated C++ refreshes. B004 did not manually edit those files. No scoped validator failed.

## Changed Files

| B004-authored file | Applied callback change | Scoped validator |
| --- | --- | --- |
| `by-memory/0x00544ee0-0x00544f2e.PaneCollapse.md` | Created first; real UID0004KU, `89/92`, exact body/evidence. | `9330` |
| `by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md` | Target `91/93`, exact body and full evidence. | `9335` |
| `by-class/GeneralPurposePanel2.md` | Exact typed array/pointer class block and class closure. | `9337` |
| `by-file/GeneralPurposePanel.md` | Route, signatures, source-unit and support synchronization. | `9343` |
| `by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md` | Detailed `89/93` non-emitting split/index. | `9345` |
| `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md` | Exact `91/94` sibling body and historicalized blocker proof. | `9349` |
| `by-class/GeneralPurposePanel.md` | Exact pointer signature and class-before-children block. | `9351` |
| `by-memory/0x00544460-0x00545086.PaneCore.md` | UID0004KU link and resolved contracts; remains non-emitting. | `9353` |
| `by-class/Pane.md` | `90/91`, exact child and common-contract prose; formal blank. | `9355` |
| `by-file/Pane.md` | `90/91`, PaneCollapse source route and contracts. | `9356` |
| `by-type/by-vtable/PaneVtables.md` | `90/94`, raw `+0x0c` and `+0x48` resolution. | `9357` |
| `by-type/by-vtable/PanelPaneVtables.md` | `88/93`, pure base and eight-entry derived matrix. | `9359` |
| `by-class/PanelPane.md` | Content-only inherited-contract sync; score/formal unchanged. | `9360` |
| `by-file/PanelPane.md` | Content-only inherited-contract/source-route sync. | `9361` |
| `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` | Exact one-time pre-dispatch call sequence; no-code proof retained. | `9362` |
| `by-class/NewSystemMessagePane.md` | Common OnActivate role, unused argument, behavior alias/rejection. | `9364` |
| `by-class/NewGroupPane.md` | Corrected activation versus update-region labels, aliases retained. | `9366` |
| `by-class/CollectionPane.md` | Common pointer contract, typed evidence and score preserved. | `9367` |
| `by-memory/0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData.md` | `88/91`, common contract/behavior alias, typed evidence preserved. | `9368` |
| `tools/leaser/Agents/Agent-B004/research/00015Y-GeneralPurposePanel2SwitchActiveChild-empty-emitter-source-quality.md` | Reconciled C01-C32, validator/generated proof, current state, changed files, and checklist. | Report artifact; no by-* validator. |

- Validator-owned files changed as automatic side effects only: registry/reference/projected-stat data and generated metadata/C++ refreshed by the listed validators, culminating in `9370`. No `-coverage-report.md`, tracker, supervisor, lifecycle, or IDA file was manually edited.
- The accepted unchanged-dependency list was not edited: UID00015Q, UID0000YI, UID0000SK, UID00028J, UID0000T6, UID0002VS, UID00018H, NewOption/NewInventory/NewSpellInventory/SelfLook/UserLook behavior pages, and compiler-support pages.

## Implementation Tracking Checklist

### Report-Only Gate 1 Phase

- [x] Read Agent-B004 `goal.md` and the complete project `ntk-b-agent-workflow` skill/reference/template instructions.
- [x] Confirmed B004 identity and `CHATGPT | 5.6 | xHigh` provenance.
- [x] Searched duplicate/current/historical reports and preserved valid historical evidence as leads.
- [x] Completed mandatory live MCP health, target, caller, helper, vtable, derived-family, sibling, and boundary evidence pass against database `328356ab`.
- [x] Re-read target and every named support category plus generated/tracker evidence read-only.
- [x] Resolved every named blocker and supplied exact managed C++ rather than a blank default.
- [x] Produced C01-C32 incorporation ledger, exact destination list, score/metadata table, negative/rejected alternatives, and callback verification criteria.
- [x] Edited no by-* file, acquired no lease, and ran no validator or lifecycle command.

### Supervisor-Accepted Implementation Callback Phase

- [x] Received explicit supervisor callback for exact Gate 1 SHA `512AD87DD930349682D9A13A08A54A24727374085B824351024D0BCA36759440` before any by-* edit. Ledger: C01-C32.
- [x] Created/registered PaneCollapse first under one immediate parent lease; validator `9330` assigned UID0004KU, then the lease was released before links. Ledger: C12-C15.
- [x] Updated UID00015Y under one immediate lease with exact `91/93` metadata/body/full evidence; validator `9335`, then release. Ledger: C01-C11, C20-C24, C29.
- [x] Updated UID00005R with the exact class block and preserved unrelated content; validator `9337`, then release. Ledger: C06-C10, C27.
- [x] Updated UID0000JQ with source route/support synchronization; validator `9343`, then release. Ledger: C03, C06-C10, C20-C23, C30.
- [x] Updated UID00015V as the detailed non-emitting split/index; validator `9345`, then release. Ledger: C28-C30.
- [x] Updated UID00015X with the exact body and historicalized no-code proof; validator `9349`, then release. Ledger: C06, C12-C16, C21, C25.
- [x] Updated UID00005Q with the exact pointer signature/post-class marker only; validator `9351`, then release. Ledger: C06, C26.
- [x] Updated UID0001EA PaneCore after UID0004KU existed; validator `9353`, then release. Ledger: C12-C15.
- [x] Updated Pane class/file one at a time, kept formal class C++ blank, validated by `9355`/`9356`, and released each. Ledger: C12-C16, C30.
- [x] Updated PaneVtables and PanelPaneVtables one at a time with raw-address/common-contract detail, validated by `9357`/`9359`, and released each. Ledger: C15-C16.
- [x] Updated PanelPane class/file one at a time with content-only inherited-contract notes, validated by `9360`/`9361`, and released each. Ledger: C16, C30.
- [x] Updated UID0003VB caller note without altering its no-whole-method proof; validator `9362`, then release. Ledger: C24.
- [x] Updated NewSystemMessagePane content-only, preserved unrelated evidence/score/formal proof; validator `9364`, then release. Ledger: C16-C17.
- [x] Updated NewGroupPane content-only, preserved unrelated evidence/score/formal proof; validator `9366`, then release. Ledger: C16, C18.
- [x] Updated CollectionPane class and UID0003Y3 one at a time, preserving typed collection work; validators `9367`/`9368`, then release. Ledger: C16, C19.
- [x] Confirmed the named unchanged dependencies were not edited. Ledger: C30.
- [x] Ran final authorized waited refresh `9370`; verified exact target/sibling/PaneCollapse counts, no target markers, no handwritten aggregate/compiler-only records, and child definitions outside closed classes. Ledger: C31.
- [x] Updated this same report at report-level detail with every claim outcome, validator ID/timestamp/exit/ok/side effect, changed files, generated proof, and archive-neutral state. Ledger: C01-C32.
- [x] Read B004's validator-owned `current_leases.md` after all releases; no B004 lease remains. Ledger: C32.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000009398","destination_path":"executed-b-agent-research/B004/00015Y-GeneralPurposePanel2SwitchActiveChild-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00015Y-GeneralPurposePanel2SwitchActiveChild-empty-emitter-source-quality.md","timestamp":"2026-07-13T07:03:59-04:00","uid":"00015Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
