** TARGET-REPORT-UID:0004A5 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0004A5 SpellMacroEditControlPane HandlePointerOrMouseEvent Ownership / Split Research

## Finalized Report / Current Recommendation

- Implemented target: validator-preserving rename UID0004A5 from `SpellMacroEditControlPaneIsSelectable` to `SpellMacroEditControlPaneHandlePointerOrMouseEvent`, exact range `[0x0057f9a0,0x0057f9a5)`, owner/emitter UID0000DQ, `RECONSTRUCTABLE:TRUE`, blank optional position, relative `Nested:0`, score `91/94`, and exact formal block R1.
- Final disposition: source-authored `bool SpellMacroEditControlPane::HandlePointerOrMouseEvent(Event *)` override that unconditionally returns true. It is the `EventHandler` secondary-vtable `+0x04` method, not a no-argument const selectability query.
- Callback disposition: C01-C20 and R1-R10 are incorporated, all seven UID-preserving renames and bounded support changes are complete, every changed ordinary destination passed its scoped validator, and final waited command `000000011805` generated and verified current `MacroDialogs.cpp`. No B003 implementation item remains.
- Confidence: very strong for range, bytes, return value, stack argument, vtable slot, receiver subobject, owner, and source file; strong for the project-canonical descriptive method spelling and source access spelling.

## Supporting Research

The direct evidence pass used the exact search terms `UID0004A5`, `0004A5`, `0x0057f9a0`, `0057f9a0`, `SpellMacroEditControlPaneIsSelectable`, `SpellMacroEditControlPane::IsSelectable`, `SpellMacroEditControlPane`, `IsSelectable`, and `MacroEditControlPane` against all current historical-report roots:

- `source-3/project-documentation/executed-b-agent-research/**`: two relevant reports were opened and classified.
- `source-3/project-documentation/archived/**`: no direct or support report match.
- `source-3/project-documentation/tools/leaser/Agents/Older-Research/**`: no match.
- `source-3/project-documentation/tools/leaser/Agents/SpecialReports/**`: no match.
- `source-3/project-documentation/tools/leaser/Agents/Agent-*/research/**`: no competing direct-target report. The current B003 goal is assignment metadata, not research evidence.

Relevant executed reports:

- B001 `0001IK-MacroEditControlPanes-empty-emitter-source-quality.md`: historical split/child-creation report. It correctly established the exact target range, five-byte body, Spell class/file route, and vtable reachability, but its CPP-4/CPP-5 source factorization named the adjacent methods `OnKeyEvent(const KeyEvent &)` and `IsSelectable() const`. Fresh ABI and inherited-slot evidence rejects those names and signatures.
- B003 `0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality.md`: historical table-layout support. Its exact cells `0x0062d250 -> 0x0057f9a0` and `0x0062d254 -> 0x0057f930` remain valid. Its semantic labels `IsSelectable` and `OnKeyEvent` are superseded because it did not compare the cells with the accepted `EventHandler` interface and dispatcher call convention.

Current documentation and generated state were read independently rather than copied from those reports. The current target, UID0004A4, UID0000DQ, UID0001IK, UID0003DB, UID0001Y1, UID0000KY, `EventHandler`, `Event`, `Pane`, and `ControlPane` pages were checked. The same-slot New and Integrate method pages were also checked because they expose the same inherited-interface contradiction.

Historical report-only state: before the accepted callback, this was B003's research artifact at the agent-local path and no ordinary page had been edited or validated. Current callback state: B003 edited the bounded ordinary destinations below under serial leases, ran one scoped validator per destination, and released every lease. B003 manually changed no generated/manual-coverage/tracker/audit/supervisor/validator/lifecycle state, mutated no IDA state, and invoked no report execution/probe/count/move/archive/lifecycle command. External report validation/execution/count/path/move/archive state is neither asserted nor directed by this artifact.

## Target

- Target UID: UID0004A5.
- Historical pre-callback target path: `by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneIsSelectable.md`.
- Implemented target path: `by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent.md`.
- Source queue/report evidence-time row at line 1610: `auto-generated/-ag-research-tracker.md` recorded `86/90`, reconstructable true, zero direct reports, and the stale `IsSelectable` path when checked.
- Historical supervisor classification: independent direct-target report-only research with mandatory live MCP and no ordinary implementation before accepted Gate 1.
- Implemented scores and parent state: target `91/94`, owner/emitter UID0000DQ, true, blank position, `Nested:0`; parent UID0001IK is `91/93`, UID0000KY owner, false, blank emitter/position/formal, `Nested:-4`.

## Current Target State

- Implemented metadata: UID0004A5, exact half-open range `0x0057f9a0-0x0057f9a5`, `91/94`, owner/emitter UID0000DQ, reconstructable true, blank optional position, `Nested:0`.
- Implemented formal C++ is exact R1, `bool SpellMacroEditControlPane::HandlePointerOrMouseEvent(Event *) { return true; }`.
- Implemented Item Summary identifies the unconditional EventHandler pointer/mouse override reached through Spell secondary vtable cell `0x0062d250`.
- Implemented evidence records size `0x5`, exact bytes/hash, stack cleanup, sole xref, secondary offset, dispatcher semantics, predecessor/successor padding, owner/source placement, and rejected signatures.
- Historical contradiction resolved: bytes `b0 01 c2 04 00` return true and pop one four-byte argument, which rejects the former zero-argument const interpretation.
- Historical contradiction resolved: Spell secondary cell `0x0062d250`, exactly `+0x04` after the destructor slot, is the accepted `EventHandler::HandlePointerOrMouseEvent(Event *)` slot.
- Historical adjacent-method contradiction resolved: cell `0x0062d254` is `EventHandler +0x08`; UID0004A4 is now `HandleKeyOrTextEvent(Event *)` with exact key-up/text-input/self-invalidation behavior.
- Evidence-time generated `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp` header was validator command `000000011699`, refreshed `2026-07-14T14:55:23-04:00`, SHA256 `04A32A0FFEC77838841353DBFBD1677B90FC8A16C7A05F7C21E37823AA763A45`. It contained one stale UID0004A5 `IsSelectable` definition, one stale UID0004A4 `OnKeyEvent` definition, no canonical Spell handler names, and an UID0000DQ Empty Emitter Marker because the class formal was blank.
- Current generated state: `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp` is validator-owned output from final waited command `000000011805`, refreshed `2026-07-14T16:14:42-04:00`, SHA256 `514ADBEBD680E3D89C1170821CB7F778F17FA053AAB526236758E9F6F518C0EA`. It contains R1/R3/R4 and R5-R9 once each, closes UID0000DQ before namespace-scope definitions, has no stale renamed definition, no UID0004A5/UID0000DQ/UID0001Y1 Empty Emitter Marker, and no handwritten compiler tables.
- Related support verified: UID0004A2, UID0004A4, UID0004AE, UID0004AF, UID0004AM, UID0004AN, UID0004AO, UID0000DQ, UID000095, UID00006M, UID0001IK, UID0003DB, UID0001Y1, UID0000KY, UID00004L, UID00004N, UID0000A2, UID000038, UID0003JA, and UID0002PB.
- Current artifact/lifecycle boundary: callback implementation and ordinary validation are complete with no lease remaining. B003 itself performed no execute/probe/count/move/archive/lifecycle command; external lifecycle state is not asserted or directed here.

## Executive Recommendation

- Direct semantic owner/emitter UID0000DQ `SpellMacroEditControlPane` and source-file route UID0000KY `MacroDialogs` are retained.
- UID0004A5 is renamed to source-facing inherited override `SpellMacroEditControlPaneHandlePointerOrMouseEvent`; the five-byte range is neither split nor moved.
- Exact R1 is installed. The unnamed `Event *` formal is intentional because the function reads neither receiver nor event.
- Complete class declaration R2 is installed on UID0000DQ. It uses `ControlPane` inheritance, public constructor/getter, protected inherited overrides, private `unsigned short m_spellKey`, exact `0x10c` natural layout, class closure before `[[CHILDREN]]`, and no raw vptr/padding members.
- UID0004A2 R3 and UID0004A4 R4 make the class declaration and emitted definitions ABI/source coherent. `m_controlFlags = 1` is inherited state; it does not prove a selectability virtual.
- Same-slot bounded parity corrections R5-R9 are applied to New/Integrate pages. They do not change target ownership and remove directly disproved method names from active shared-vtable support.
- R10 is installed on UID0001Y1 as a compiler-generated-vtable coverage marker. Raw vtable/RTTI arrays remain excluded.
- `Event`, `EventHandler`, `Pane`, `ControlPane`, target-independent methods, destructor glue, thunks, and scalar deleting wrappers remain verify-only except for validator-managed link synchronization caused by the seven renames.

## Supervisor Active Recheck

- Trigger: supervisor assigned UID0004A5 from the reconstructable/not-covered tracker and required fresh direct MCP research rather than repetition of the B001 family report.
- Split-first result: no new split is required. The target is one exact modeled five-byte function between independent padding spans.
- Associated blockers: target signature/name, adjacent Spell key override, class formal/layout, constructor parameter/state write, New parity, Integrate secondary-slot names, vtable labels, generated class marker, scores, and manual coverage text are all resolved; accepted ordinary changes are implemented and exact supervisor-owned coverage text is retained below.
- No source-bearing item in the accepted bounded recommendation is left with a generic future-investigation statement. Remaining original-spelling uncertainty is explicitly inference-capped and does not block formal C++.

## Inference Research Guidance Check

- `by-structure.md` and the workflow require exact vtable position, caller convention, complete-object/subobject adjustment, source/ABI separation, parent gating, relative nesting preservation, and formal-block-only C++. Those rules overturn the attractive but unsupported old `IsSelectable` name.
- IDA fact: target bytes, `ret 4`, exact vtable cell, COL offset `+0xa0`, dispatcher indirect call, no direct code caller, and padding.
- Documentation evidence: accepted `EventHandler` declaration, `Event` layout, `Pane::InvalidateRect`, `ControlPane` field band, MacroDialogs parent route, and existing split inventories.
- Inference: exact original lexical spelling is unavailable, but `HandlePointerOrMouseEvent(Event *)` is the project-canonical descriptive contract fixed by UID00004N and used by current high-quality Pane-derived reconstructions.
- Existing generated names and old report names were treated as hypotheses. `IsSelectable`, `OnKeyEvent`, `KeyEvent`, `RequestParentRefresh`, `SetSelectable`, and `ForwardFocusEvent` were not preserved merely because generated output used them.
- Wave2/Wave3/simroot mentions in support docs and historical reports were treated only as stale provenance leads. No Wave2/Wave3 artifact was used as current authority.

## Heuristic / Inference Reanalysis And Validation

### Target name, signature, and constness

- Best source identity: `bool SpellMacroEditControlPane::HandlePointerOrMouseEvent(Event *)`.
- Evidence: one popped stack argument; secondary `EventHandler` slot `+0x04`; EventDispatcher passes the `Event *` to that slot; same class key handler occupies the following `+0x08` slot; no receiver/event reads.
- `IsSelectable() const` is rejected-invalid. It has no parameter and cannot generate `ret 4`; no `ControlPane`/`EventHandler` vtable slot at this position has that contract.
- Static/free helper is rejected-invalid. The sole inbound reference is a class vtable cell, and RTTI/constructor stores identify the receiver subobject.
- `const` is rejected. This inherited event method is not a const-qualified virtual in UID00004N. The lack of receiver reads is an optimizer/unused-argument fact, not a constness proof.

### Return type and behavior

- `bool` is the source type. The body writes `AL=1` and returns through a bool-valued EventHandler dispatch slot.
- The method consumes every pointer/mouse-family event by returning true. It does not inspect type, coordinates, modifiers, or control state.
- A compiler nullsub/no-code classification is rejected. The class has a distinct class-local override cell where base `ControlPane` uses its inherited default-false handler; the source declaration must cause this out-of-line vtable target.

### Adjacent key/text override

- UID0004A4 is `HandleKeyOrTextEvent(Event *)`, not `OnKeyEvent(const KeyEvent &)`. Its `ret 4` ABI, `0x0062d254` slot, and EventHandler `+0x08` contract are exact.
- Event type `8` is key-down. Event type `10` is text input and returns true. Event type `9` key-up returns false; the current formal reverses this fact.
- Key normalization uses the accepted source-facing `NarrowInputKey(event->m_payload.m_key.m_key, event->m_payload.m_key.m_modifiers)` expression around the observed `std::ctype<char>::do_narrow` lowering.
- Only ASCII A-Z/a-z updates `m_spellKey`; successful update calls complete-object primary slot `+0x20`, proven as `Pane::InvalidateRect`, with `NULL`. `RequestParentRefresh` is rejected-invalid.

### Class layout and access

| Offset | Source model | Evidence/disposition |
| --- | --- | --- |
| `+0x000..+0x107` | inherited `ControlPane` | Constructor directly calls UID0002PB; ControlPane size and private-field start at `+0x108` are current support facts. |
| `+0x0a0` | inherited `EventHandler` secondary view | Constructor stores Spell secondary vtable; COL offset is `0xa0`; target/key calls receive this view. |
| `+0x0a4` | inherited tertiary view | Constructor stores third Spell vtable; COL offset is `0xa4`. |
| `+0x0ff` | inherited `m_controlFlags` | Constructor stores byte `1`; current ControlPane layout rejects a Spell-private field or selectability virtual. |
| `+0x108..+0x109` | `unsigned short m_spellKey` | Getter, constructor, key handler, paint path, and save caller all agree. |
| `+0x10a..+0x10b` | natural tail/alignment padding | No source member is required; class allocation is decimal 268 / `0x10c`. |

- Constructor/getter are public because SpellMacroDialog constructs rows and calls the getter.
- Paint and EventHandler overrides are protected in the first draft because no external direct call requires public access; access does not affect layout/ABI.
- `m_spellKey` is private. No direct external field access was found.
- An explicit destructor declaration/body is omitted. The empty implicit derived destructor is sufficient source cause for compiler-retained complete-object/destructor wrapper/thunk artifacts already classified no-code.

### Constructor source shape

- UID0004A2 receives a word and a non-null pointer to a caller-local 16-byte rectangle, forwards that pointer to `ControlPane(8, bounds)`, stores the word, installs compiler vptrs, and writes inherited `m_controlFlags=1`.
- Best source signature is a `const RectBounds &` at the derived boundary, forwarded as `&bounds` to the nullable base constructor. It matches the one-pointer ABI and the two caller sites that build a local rectangle then pass its address.
- A raw pointer derived signature remains possible, but the const-reference spelling is more consistent with current `Rect(...)` temporary call-site drafts. This bounded lexical choice caps confidence rather than blocking source.
- `SetSelectable(true)` is rejected-stale: no such documented base method or binary call exists; exact current ControlPane support names `+0xff` as `m_controlFlags`, and other reconstructed derived constructors directly assign it.

### Shared family parity

- UID0004AF has identical bytes/hash/ABI and occupies New secondary `+0x04`; it now carries R5 and the same semantic rename.
- UID0004AE occupies New secondary `+0x08` and now carries R6. It handles key-down, text input, ASCII validation, active child 2/3 state, key/mode stores, and self invalidation.
- UID0004AN/UID0004AM/UID0004AO occupy Integrate secondary `+0x04/+0x08/+0x0c`; they are respectively pointer/mouse, key/text, and IME overrides. R7-R9 preserve their forwarding/state behavior while correcting type/name/dispatch source shape.
- These sibling corrections are bounded consequences of the same exact interface comparison. New/Integrate class declarations and unrelated methods remain outside direct formal reconstruction here.

### Rejected alternatives

- Direct `ControlPane`, `EventHandler`, vtable-data, parent aggregate, New sibling, or `MacroDialogs` file ownership is rejected in favor of narrower class UID0000DQ ownership and UID0000KY file emission.
- Moving the target to a generic input helper file is rejected; the vtable, constructor, RTTI, and neighboring class methods are class-local.
- Emitting adjusted `this`, vptr stores, RTTI arrays, scalar-delete flags, base-destructor calls, raw addresses, raw offsets, `__thiscall`, `__stdcall`, or decompiler labels is rejected as compiler/decompiler output.
- Splitting the five bytes, absorbing adjacent padding, merging with UID0004A4, or treating vtable reachability as dead code is rejected.

## Evidence Standards Used

- Mandatory live IDA MCP: fresh `idb_list`, `server_health`, bounded bytes, decompile, disassembly, function profiles, xrefs, dispatcher body, constructor/caller body, COL/vtable bytes, and sibling parity.
- Strong binary evidence: exact instructions/stack cleanup, table position, indirect dispatcher call, constructor base/vptr/field stores, object allocation size, and caller-local rectangle address.
- Documentation evidence: current accepted Event/EventHandler/Pane/ControlPane contracts and current MacroDialogs split/class/file/vtable routes.
- Negative evidence: no direct code callers, no callee, no reads of event/receiver, no documented `SetSelectable`, no slot-compatible selectability method, no extra target bytes, and no original symbol proving the stale name.
- Evidence ladder: direct binary facts control behavior/ABI/range; accepted interface/layout docs provide source types; inference is limited to lexical/access/header choices and is explicitly capped.
- Tool status did not limit the recommendation. The evidence-time database was healthy with auto-analysis, Hex-Rays, and strings ready.

## Evidence Checked

- MCP session discovery: `idb_list` returned one active NexusTK IDB database `6b2e78f3` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- MCP health at evidence collection: `server_health` status `ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready with 2067 entries.
- Bounded target calls: `get_bytes`, `decompile`, `disasm`, `func_profile`, and `xref_query` for `0x0057f9a0`; bounded sibling and support calls for `0x0057f930`, `0x0057fd00`, `0x0057fc80`, `0x0057f760`, `0x004a77d0`, `0x00544db0`, `0x0041d6b0`, `0x00580320`, `0x00580460`, and `0x00580490`.
- Data checks: Spell/New/Integrate secondary tables, ControlPane secondary table, Spell RTTI COLs, constructor call-site allocation, and exact padding windows.
- Executable identity: `NexusTK.exe`, size 2,679,296, MD5 `4247E04E20B65D6414C7238AA8FF5515`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Current docs checked: target, associated method pages, class/parent/file/vtable pages, Event/EventHandler, Pane/PaneVtables, ControlPane/constructor, manual coverage files, generated MacroDialogs.cpp, generated research tracker, supervisor assignment record, and both matching executed reports.
- Exact historical roots and outcomes are recorded under Supporting Research.
- Historical report-only boundary: no IDA mutation, validator, generated/manual-coverage edit, ordinary lease/edit, or lifecycle/execute probe occurred before Gate 1. During the accepted callback, B003 used only serial ordinary leases and scoped validators recorded below; IDA and restricted/lifecycle files remained untouched.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Evidence-time MCP database `6b2e78f3` was healthy and bounded target calls succeeded. | Very strong | Fresh idb_list/health/get_bytes/decompile/disasm/profile/xrefs | Target Evidence; support change logs | incorporate | applied | UID0004A5, UID0004A2, UID0004A4, UID0000DQ, UID0003DB, UID0001Y1, and UID0000KY retain the evidence-time session/request facts as durable captured evidence; their scoped validators passed. |
| C02 | UID0004A5 is exact `[0x0057f9a0,0x0057f9a5)`, size 5, bytes `b0 01 c2 04 00`, target SHA256 `f4c6d7ae520f88aecb3ea65952e885437fa4a6ce4b5c3439a161d1c5d8e42863`. | Very strong | Bytes/profile/hash | UID0004A5 Range/Evidence | incorporate | applied | Renamed UID0004A5 records the exact range, size, bytes, hash, two-instruction CFG, and body; validator `000000011761` passed. |
| C03 | Eight predecessor `0xcc` bytes and eleven successor `0xcc` bytes remain parent-only padding; no split/merge. | Very strong | `0x0057f990` byte window and modeled neighbors | UID0004A5; UID0001IK padding | incorporate | applied | UID0004A5 and UID0001IK explicitly preserve `0x0057f998-0x0057f9a0` and `0x0057f9a5-0x0057f9b0` as parent-only padding; validators `000000011761` and `000000011793` passed. |
| C04 | Sole target xref is `0x0062d250`; EventHandler secondary `+0x04` and dispatcher prove one `Event *` parameter. | Very strong | Vtable bytes, COL `+0xa0`, EventDispatcher indirect call | UID0004A5; UID0003DB; UID0001Y1 | incorporate | applied | Exact cell, COL, interface slot, dispatcher, and one-parameter ABI are present in all three destinations; validators `000000011761`, `000000011797`, and `000000011798` passed. |
| C05 | Rename UID0004A5 to `SpellMacroEditControlPaneHandlePointerOrMouseEvent`; apply R1 and `91/94`; preserve owner/emitter/true/blank position/Nested 0. | Very strong | C02-C04 and accepted interface | UID0004A5 path/metadata/formal | incorporate | applied | Validator-aware rename retained UID/range and installed exact metadata, Item Summary, evidence, history, and R1; validator `000000011761` passed and generated command `000000011805` emits R1 once with no target marker. |
| C06 | `IsSelectable() const`, static/free, nullsub/no-code, and compiler-wrapper alternatives are invalid. | Very strong | `ret 4`, vtable route, distinct base cell, dispatcher | UID0004A5 negative/history | reject-invalid | excluded-with-reason | UID0004A5 retains each rejected alternative with the exact ABI/slot/dispatcher reason; generated command `000000011805` contains zero stale Spell `IsSelectable` definitions. |
| C07 | Spell layout is inherited `0x108` plus word `m_spellKey` and natural tail padding, total `0x10c`; inherited EventHandler view is `+0xa0`. | Very strong | Allocation 268, constructor/getter/key accesses, COLs | UID0000DQ layout/evidence | incorporate | applied | UID0000DQ records inherited extent, `m_spellKey`, natural tail, total allocation, `+0xa0` EventHandler view, access model, and negative raw-layout evidence; validator `000000011769` passed. |
| C08 | UID0000DQ receives complete R2, `91/93`, class close before `[[CHILDREN]]`, no explicit padding/vptr/destructor glue. | Strong | C07, method inventory, source-access analysis | UID0000DQ formal/status/score | incorporate | applied | Exact R2 and score are present; validator `000000011769` changed the registry from blank to block. Generated command `000000011805` closes `};` before all qualified Spell child definitions and has no UID0000DQ marker. |
| C09 | UID0004A2 receives R3 and `90/93`; const-reference rectangle forwards by address; `m_controlFlags=1` supersedes undocumented `SetSelectable`. | Strong | Constructor/caller disassembly, ControlPane layout, search negatives | UID0004A2 formal/evidence; UID0000DQ | incorporate | applied | UID0004A2 contains exact R3, caller/layout/control-state/history evidence, and score; validator `000000011767` passed. Generated command `000000011805` emits R3 once. |
| C10 | Rename UID0004A4 to `SpellMacroEditControlPaneHandleKeyOrTextEvent`, apply R4 and `92/94`; type 10 true, type 9 false, self invalidation. | Very strong | Exact body, cell `0x0062d254`, Event/EventHandler/Pane | UID0004A4 path/formal/evidence | incorporate | applied | Validator-aware rename installed R4 and full Event/type/ASCII/invalidation/history evidence; validator `000000011764` passed and generated command `000000011805` emits R4 once with no stale Spell `OnKeyEvent`. |
| C11 | Rename UID0004AF and UID0004AE to New pointer/key EventHandler names and apply R5/R6 with exact parity behavior. | Very strong | Identical target bytes, New table, full key body | UID0004AF; UID0004AE; UID000095 | incorporate | applied | UID0004AF/UID0004AE renames and R5/R6 passed validators `000000011770`/`000000011772`; bounded UID000095 synchronization passed `000000011780`. Generated command `000000011805` emits both canonical definitions once. |
| C12 | Rename UID0004AN/AM/AO to Integrate pointer/key/IME EventHandler names and apply R7-R9. | Very strong | Integrate table and bounded bodies | UID0004AN; UID0004AM; UID0004AO; UID00006M | incorporate | applied | UID0004AN/AM/AO renames and exact R7/R8/R9 passed `000000011774`, `000000011776`, and `000000011778`; bounded UID00006M sync passed `000000011782`. Byte-exact R8 repair validator `000000011804` passed, and generated command `000000011805` emits all three once. |
| C13 | UID0001IK remains non-emitting, owner UID0000KY, blank emitter/position/formal, Nested -4; update exact renamed inventory/padding/history and `91/93`. | Very strong | Current parent plus C03-C12 | UID0001IK | incorporate | applied | Parent metadata/route/nesting remain exact; renamed inventory, target padding, source/compiler distinctions, and history are current; validator `000000011793` passed. |
| C14 | UID0003DB retains comment-only compiler marker/route and gains canonical secondary-slot names, class coverage, negatives, `90/94`. | Very strong | Exact table bytes/COLs/constructor stores | UID0003DB | incorporate | applied | UID0003DB retains all nine views/COLs/xrefs/thunks/boundaries and exact compiler exclusion while adding canonical slots/class cause; validator `000000011797` passed and generated marker appears once. |
| C15 | UID0001Y1 retains owner/emitter UID0000KY/true/blank position, gains R10 compiler marker and exact slot names, `89/93`. | Strong | Shared family table evidence | UID0001Y1 | incorporate | applied | Exact R10, score, route, canonical slot inventory, and no-raw-array proof are present; validator `000000011798` passed with the documented project stats warning/side effect. Generated R10 appears once with no UID0001Y1 marker. |
| C16 | UID0000KY remains `90/88` and same route; update Spell/New/Integrate inventory, exact generated expectations, historical names, and source/compiler split. | Strong | File family/current generated output | UID0000KY | incorporate | applied | UID0000KY preserves score/path/route and concurrent content while adding exact inventory, historical labels, source/compiler boundary, and generated assertions; final waited validator `000000011805` passed. |
| C17 | UID00004L/04N, UID0000A2, UID000038, UID0003JA, and UID0002PB are verify-only and already support the accepted model. | Very strong | Current formal/layout/slot docs and live parity | Verify-only support readback | already-present | already-present | Readback found no contradiction; these ordinary pages were not leased, edited, or scoped-validated by B003. |
| C18 | Preserve UID0001IL/1IM/1IN/4AV/4AW and unrelated methods as no-code/compiler or unrelated; no raw vtable/RTTI/destructor ABI source. | Very strong | Current accepted docs and no contradictory target evidence | Parent/class/file/vtable history | already-present | already-present | Verify-only pages remain unchanged. Generated command `000000011805` has 61 unique UID emission comments, no duplicate UID definitions, and no handwritten vtable/RTTI/cookie/EH constructs. |
| C19 | Manual coverage rows are stale/absent and require the exact external replacement/addition text below; B003 must not edit them. | Very strong | Read-only comparison of four manual coverage files | Supervisor-owned coverage | incorporate | excluded-with-reason | Exact supervisor-owned replacement/addition text remains below. B003 did not edit any `-coverage-report.md`; application and lifecycle are external. |
| C20 | Callback must use serial short leases, scoped validators per changed/renamed ordinary page, final waited MacroDialogs refresh, exact generated assertions, ledger/checklist reconciliation, and no B003 lifecycle action. | Very strong | Workflow and evidence-time generated defects | Validator Results/Changed Files/checklist | incorporate | applied | Seventeen scoped commands across fifteen ordinary destinations passed, including UID0004AM repair `000000011804` and final waited command `000000011805`; all leases are released, report sections/checklist are reconciled, and B003 ran no lifecycle command. |

## Positive Evidence Summary

- Target bytes encode unconditional true plus one four-byte callee-cleaned argument.
- The only target reference is Spell secondary vtable cell `0x0062d250`.
- Spell secondary COL offset is `0xa0`; constructor stores the table at object `+0xa0`.
- EventDispatcher sends pointer/mouse events to handler slot `+0x04` with the `Event *` argument.
- UID00004N fixes the accepted source-facing declaration order as pointer/mouse at `+0x04`, key/text at `+0x08`, and IME at `+0x0c` after the virtual destructor.
- Base ControlPane uses inherited false behavior in the corresponding slot, while Spell and New provide distinct class-local constant-true targets. That is positive explicit-override evidence.
- Target lies between exact padding and has no overlap/table/body ambiguity.
- Constructor, RTTI, class methods, and source-family docs all converge on UID0000DQ / UID0000KY.

## IDA MCP Facts

- Evidence-time database: `6b2e78f3`; health `ok`; analysis, Hex-Rays, and strings ready.
- Target function: `sub_57F9A0`, exact size `0x5`, two instructions, one block, no callers/callees/strings, prototype presentation `char __stdcall(int)` caused by unused receiver, constants 1 and 4.
- Target bytes: `b0 01 c2 04 00`; SHA256 `f4c6d7ae520f88aecb3ea65952e885437fa4a6ce4b5c3439a161d1c5d8e42863`.
- Exact xref: data-only `0x0062d250 -> 0x0057f9a0`; no direct code xref.
- Spell secondary table begins `0x0062d24c`: destructor adjustor `0x00580671`, target `0x0057f9a0`, key/text `0x0057f930`, then inherited defaults.
- ControlPane secondary table `0x00617af8` has destructor adjustor, inherited false pointer/mouse at `0x00544db0`, inherited false key/text at `0x0041d6b0`, then inherited defaults.
- `0x00544db0` tail-jumps to the EventHandler default-false body; `0x0041d6b0` is `xor al,al; retn 4`.
- EventDispatcher `0x004a77d0` classifies pointer/mouse then calls handler vtable `+0x04` with the Event pointer; key/text calls `+0x08`; IME calls `+0x0c`.
- UID0004A4 `0x0057f930-0x0057f998`: size `0x68`, 41 instructions, eight blocks, one Event pointer argument, direct ctype call, type 8/type 10 branches, ASCII tests, `m_spellKey` store, complete-object `+0x20` invalidation, `ret 4`.
- Spell constructor `0x0057f760-0x0057f7a9`: size `0x49`, calls ControlPane, stores word `+0x108`, vtables at `+0/+0xa0/+0xa4`, byte 1 at `+0xff`, returns `ret 8`.
- SpellMacroDialog caller allocates decimal 268 / `0x10c` and calls the constructor at `0x0053eac5` and `0x0053ec1d` with a local rectangle address.
- Spell COL offsets: primary 0, secondary `0xa0`, tertiary `0xa4`.
- New target `0x0057fd00` is byte-identical and referenced only by `0x0062d2f4`; New key method is at `0x0062d2f8`.
- Integrate cells `0x0062d398/0x0062d39c/0x0062d3a0` target `0x00580460/0x00580320/0x00580490`, exactly pointer/key/IME interface positions.
- Padding: `0x0057f998-0x0057f9a0` eight `0xcc`; `0x0057f9a5-0x0057f9b0` eleven `0xcc`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0057f760-0x0057f7a9` | UID0004A2 `SpellMacroEditControlPaneConstructor` | Source constructor/layout cause | true | UID0000DQ | `87/90 -> 90/93` | implemented R3 |
| `0x0057f7d0-0x0057f927` | UID0004A3 `SpellMacroEditControlPaneOnPaint` | Primary paint override | true | UID0000DQ | `88/91` | verify-only |
| `0x0057f930-0x0057f998` | UID0004A4 `SpellMacroEditControlPaneHandleKeyOrTextEvent` | EventHandler `+0x08` override | true | UID0000DQ | `88/91 -> 92/94` | implemented UID-preserving rename/R4 |
| `0x0057f998-0x0057f9a0` | parent-only | eight-byte alignment | false | UID0001IK | n/a | preserve padding |
| `0x0057f9a0-0x0057f9a5` | UID0004A5 `SpellMacroEditControlPaneHandlePointerOrMouseEvent` | EventHandler `+0x04` override | true | UID0000DQ | `86/90 -> 91/94` | implemented UID-preserving rename/R1 |
| `0x0057f9a5-0x0057f9b0` | parent-only | eleven-byte alignment | false | UID0001IK | n/a | preserve padding |
| `0x0057fc80-0x0057fcff` | UID0004AE `NewMacroEditControlPaneHandleKeyOrTextEvent` | New EventHandler `+0x08` parity | true | UID000095 | `88/91 -> 90/93` | implemented bounded rename/R6 |
| `0x0057fd00-0x0057fd05` | UID0004AF `NewMacroEditControlPaneHandlePointerOrMouseEvent` | New EventHandler `+0x04` parity | true | UID000095 | `86/90 -> 91/94` | implemented bounded rename/R5 |
| `0x00580320-0x0058045d` | UID0004AM `IntegrateMacroEditControlPaneHandleKeyOrTextEvent` | Integrate EventHandler `+0x08` | true | UID00006M | `88/91 -> 90/93` | implemented bounded rename/R8 |
| `0x00580460-0x00580484` | UID0004AN `IntegrateMacroEditControlPaneHandlePointerOrMouseEvent` | Integrate EventHandler `+0x04` | true | UID00006M | `86/90 -> 89/93` | implemented bounded rename/R7 |
| `0x00580490-0x005804b4` | UID0004AO `IntegrateMacroEditControlPaneHandleImeEvent` | Integrate EventHandler `+0x0c` | true | UID00006M | `86/90 -> 89/93` | implemented bounded rename/R9 |
| `0x0062d1e0-0x0062d3cc` | UID0003DB `MacroEditControlPaneVtableData` | Compiler-generated tables/RTTI | true/covered-by | UID0000KY | `88/93 -> 90/94` | implemented slot/class sync; marker retained |

UID0001IK remains the non-emitting split parent at relative `Nested:-4`; the seven renamed method children remain `Nested:0`. No new child UID or relative nesting increment is required.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062d250` | data xref to target `0x0057f9a0` | Sole target reachability; Spell EventHandler `+0x04`. |
| `0x0062d254` | data xref to `0x0057f930` | Spell EventHandler `+0x08` key/text override. |
| `0x004a781c-0x004a7820` | EventDispatcher pushes Event pointer, calls vtable `+0x04` | Exact pointer/mouse call convention. |
| `0x004a783f-0x004a7843` | EventDispatcher pushes Event pointer, calls vtable `+0x08` | Exact key/text call convention. |
| `0x0053eac5`, `0x0053ec1d` | SpellMacroDialog calls constructor | Two row-layout branches; both pass local rectangle address. |
| `0x0053ed27` | SpellMacroDialog confirm calls getter | Public `m_spellKey` accessor use. |
| `0x0062d2f4`, `0x0062d2f8` | New target/key data xrefs | Same inherited slot parity. |
| `0x0062d398`, `0x0062d39c`, `0x0062d3a0` | Integrate pointer/key/IME data xrefs | Exact three EventHandler override positions. |
| target direct callers | none | Vtable-only dispatch is live; absence of direct calls is not dead-code proof. |

## Documentation Evidence And IDA Status

- UID00004N currently emits the complete `EventHandler` interface in exact slot order. UID00004L emits the `Event` record and type values 0-22, including pointer payload and key payload at the offsets used here.
- UID0000A2 and UID0003JA identify Pane primary `+0x20` as `InvalidateRect`; that directly rejects the current `RequestParentRefresh` source claim.
- UID000038 and UID0002PB identify `ControlPane` size/private-field boundary, inherited state band, `m_controlFlags` at `+0xff`, and nullable base bounds pointer.
- Historical pre-callback UID0001IK had correct broad split/range/padding ownership but stale method names and a broad final-class-polish blocker. Current UID0001IK has the canonical inventory, target padding, source/compiler split, and `91/93` while preserving the non-emitting route.
- Historical pre-callback UID0003DB/UID0001Y1 had exact table addresses but stale semantic labels, and UID0001Y1 was blank despite reconstructable/emitting metadata. Current pages carry canonical secondary-slot names, complete UID0000DQ source cause, compiler-only markers, and `90/94` plus `89/93`; generated command `000000011805` has neither related Empty Emitter Marker.
- Historical pre-callback UID0000KY had the correct source route but stale inventory links/names and generated expectations. Current UID0000KY preserves `90/88` and the route while recording implemented inventory, historical labels, source/compiler boundary, and exact generated assertions.
- Manual coverage is stale: parent UID0001IK says reconstructable 80 despite current false/90; Spell class says 84 despite current 86; file says 88 despite current 90; exact child/vtable-data rows are absent; New/Integrate class descriptions retain stale selectability/generic helper text.
- Evidence-time generated command `000000011699` is explicitly historical pre-callback state. Final waited command `000000011805`, timestamp `2026-07-14T16:14:42-04:00`, generated SHA256 `514ADBEBD680E3D89C1170821CB7F778F17FA053AAB526236758E9F6F518C0EA`, verifies the implemented source/class/marker state described under Validator Results.

## Ranked Ownership Analysis

### 1. UID0000DQ SpellMacroEditControlPane

- Evidence for: class-specific vtable cell, constructor vptr stores, RTTI, adjacent class methods, `m_spellKey` state, scalar-wrapper/thunk support, and direct MacroDialogs class route.
- Evidence against: none material. Exact original header split is unknown but does not affect semantic ownership.
- Decision: retain as direct owner/emitter.

### 2. UID0000KY MacroDialogs

- Evidence for: owns the Spell/New/Integrate dialog/control source family and generated path `NexusTK/ui/dialogs/MacroDialogs.cpp`.
- Evidence against: file-level owner is broader than the class; direct target ownership should not bypass UID0000DQ.
- Decision: retain as indirect file emitter through UID0000DQ.

### 3. UID00004N EventHandler / UID000038 ControlPane

- Evidence for: define inherited interface, subobject position, and base defaults.
- Evidence against: target vtable is Spell-specific; base tables point elsewhere and constructors/RTTI identify the derived class.
- Decision: support-only, not owner/emitter.

### 4. UID0001IK / UID0003DB / UID0001Y1

- Evidence for: physical range and vtable inventory context.
- Evidence against: parent is non-emitting mixed split inventory; table pages describe compiler output rather than method semantic ownership.
- Decision: support/index pages only.

### 5. New/Integrate siblings, no-owner, or generic helper

- Evidence for: same inherited contract and useful parity.
- Evidence against: separate classes/ranges/vtables; no target-local constructor or state ownership.
- Decision: reject as target owner. Apply only bounded contradiction repairs.

### Proposed new file/grouping, if applicable

- Not applicable. Existing UID0000KY `NexusTK/ui/dialogs/MacroDialogs.cpp` route is correct.
- No new by-file, by-class, by-memory child, or type page is required.

## Source Placement

- Recommended placement: member declaration in UID0000DQ `SpellMacroEditControlPane`; definition emitted through UID0000KY at `NexusTK/ui/dialogs/MacroDialogs.cpp`.
- The class sits with SpellMacroDialog/NewMacroDialog/IntegrateMacroDialog and their row controls, uses the shared macro row state/assets, and is instantiated only from SpellMacroDialog setup.
- Generic EventDispatcher/EventHandler/ControlPane files are rejected because they define infrastructure/base behavior, not this class-local true override.
- A separate `SpellMacroEditControlPane.cpp` is a weaker historical simroot artifact. Current accepted source-family grouping and contiguous dialog/control islands favor MacroDialogs.
- Exact header factoring is not symbol-proven. The class declaration may have lived in a MacroDialogs header or the source file; this does not alter current UID0000KY generation.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x0057f9a0,0x0057f9a5)`, five bytes, no overlap.
- Predecessor UID0004A4 ends at `0x0057f998`; `0x0057f998-0x0057f9a0` is eight-byte alignment.
- Successor UID0004A6 begins at `0x0057f9b0`; `0x0057f9a5-0x0057f9b0` is eleven-byte alignment.
- The target remains one source method. Do not merge with the preceding key/text method or following New getter.
- Reclassification is semantic/title/signature only: stale selectability query to explicit EventHandler override. `RECONSTRUCTABLE:TRUE` remains correct.
- Parent UID0001IK remains false/non-emitting with blank emitter/formal and `Nested:-4`. Children remain relative `Nested:0`; the existing getter's separate relative nesting metadata is not changed by this report.
- Vtable tables and RTTI remain compiler-generated source coverage, never handwritten arrays.

## Negative Evidence Summary

- No direct code caller exists; only the vtable cell reaches the target.
- No target instruction reads `this`, Event fields, coordinates, flags, or globals.
- No documented or called `SetSelectable` helper exists in the current base/source support. The current generated use comes only from the stale B001 draft.
- No accepted `ControlPane` secondary slot at `+0x04` is a selectability query; it is the EventHandler pointer/mouse family.
- No zero-argument ABI can account for `ret 4`.
- No const qualification follows from an unused receiver.
- No target bytes are padding, table data, thunk adjustment, destructor glue, scalar-delete logic, or security/EH scaffolding.
- No source evidence supports raw vptr stores, raw offset members, a synthetic padding array, a fake KeyEvent hierarchy, or a parent-refresh callback.
- New/Integrate parity supports the interface but does not transfer target ownership.

## IDA Rename / Type / Comment Recommendations

- Source-facing/IDA function direction: `SpellMacroEditControlPane__HandlePointerOrMouseEvent` for `0x0057f9a0`, returning bool with one `Event *` argument and an EventHandler-secondary receiver at complete-object offset `+0xa0`.
- Adjacent direction: `SpellMacroEditControlPane__HandleKeyOrTextEvent` for `0x0057f930`.
- Same-slot directions: New pointer/key and Integrate pointer/key/IME names used in R5-R9.
- Vtable comments: Spell secondary `+0x04/+0x08`, New secondary `+0x04/+0x08`, Integrate secondary `+0x04/+0x08/+0x0c` should use the accepted EventHandler family names.
- Preserve address/range/function boundaries and all compiler thunk/destructor names. Do not rename padding.
- No IDA DB edit is requested or authorized. These are documentation/source-facing recommendations only; supervisor controls any separate IDA mutation process.

## First-Draft C++ Recommendation

Eligible: UID0004A5 and the bounded source-bearing support pages whose current formal signatures/bodies contradict the same inherited interface. Every C++ recommendation appears only in the literal managed destination shape below.

R1 - UID0004A5 implemented renamed target:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SpellMacroEditControlPane::HandlePointerOrMouseEvent(Event *)
{
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R2 - UID0000DQ class declaration:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct RectBounds;

class SpellMacroEditControlPane : public ControlPane
{
public:
    SpellMacroEditControlPane(unsigned short spellKey, const RectBounds &bounds);

    unsigned short GetSpellKey() const;

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    unsigned short m_spellKey;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R3 - UID0004A2 constructor:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SpellMacroEditControlPane::SpellMacroEditControlPane(
    unsigned short spellKey,
    const RectBounds &bounds)
    : ControlPane(8, &bounds),
      m_spellKey(spellKey)
{
    m_controlFlags = 1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R4 - UID0004A4 implemented renamed key/text override:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SpellMacroEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
    {
        const unsigned char key = NarrowInputKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

        if ((key >= 'a' && key <= 'z') ||
            (key >= 'A' && key <= 'Z'))
        {
            m_spellKey = key;
            InvalidateRect(NULL);
            return true;
        }
    }
    else if (event->m_type == kEventTextInput)
    {
        return true;
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R5 - UID0004AF implemented renamed New pointer/mouse override:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewMacroEditControlPane::HandlePointerOrMouseEvent(Event *)
{
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R6 - UID0004AE implemented renamed New key/text override:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool NewMacroEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
    {
        const int activeChild = g_pGeneralPurposePanel->GetActiveChildIndex();
        if (activeChild == 2 || activeChild == 3)
        {
            const unsigned char key = NarrowInputKey(
                event->m_payload.m_key.m_key,
                event->m_payload.m_key.m_modifiers);

            if ((key < 'a' || key > 'z') &&
                (key < 'A' || key > 'Z'))
                return false;

            m_key = key;
            m_mode = activeChild == 3;
            InvalidateRect(NULL);
        }

        return true;
    }

    return event->m_type == kEventTextInput;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R7 - UID0004AN implemented renamed Integrate pointer/mouse override:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool IntegrateMacroEditControlPane::HandlePointerOrMouseEvent(Event *event)
{
    if (m_editActive)
        return m_textEdit->HandlePointerOrMouseEvent(event);

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R8 - UID0004AM implemented renamed Integrate key/text override:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool IntegrateMacroEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    if (m_editActive && !m_pendingTextEditForward)
        return m_textEdit->HandleKeyOrTextEvent(event);

    if (m_pendingTextEditForward)
        m_pendingTextEditForward = false;

    if (event->m_type != kEventKeyDown)
        return event->m_type == kEventTextInput;

    const unsigned char key = NarrowInputKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (key == ';')
    {
        m_pendingTextEditForward = true;
        m_macroData->state = MacroHotkeyRecord::Text;
        EnterTextEditMode();
        InvalidateRect(NULL);
        return true;
    }

    const int activeChild = g_pGeneralPurposePanel->GetActiveChildIndex();
    if (activeChild == 2 || activeChild == 3)
    {
        if ((key < 'a' || key > 'z') &&
            (key < 'A' || key > 'Z'))
            return false;

        m_textEdit->ClearText();
        m_macroData->key = key;
        m_macroData->terminator = 0;
        m_macroData->state = activeChild == 3
            ? MacroHotkeyRecord::Spell
            : MacroHotkeyRecord::Item;
        InvalidateRect(NULL);
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R9 - UID0004AO implemented renamed Integrate IME override:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool IntegrateMacroEditControlPane::HandleImeEvent(Event *event)
{
    if (m_editActive)
        return m_textEdit->HandleImeEvent(event);

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R10 - UID0001Y1 compiler-vtable coverage marker:

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated MSVC RTTI and vtable data for the MacroDialogs class family;
// do not emit handwritten vtable or RTTI arrays.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R1 preserves the exact body. R2 provides the declaration source cause for vtable generation and places `[[CHILDREN]]` after the complete class closing `};`. R3-R9 remove ABI-incompatible source drafts without introducing adjusted receivers, raw offsets, vptr stores, compiler wrappers, or decompiler artifacts. R10 removes the type-page Empty Emitter Marker with a source-coverage statement rather than raw data.

## Final Recommendation

- The seven UID-preserving renames and R1/R3-R9 are applied exactly.
- Class R2 and vtable-family R10 are applied exactly.
- Retain UID0004A5 direct owner/emitter UID0000DQ, true, blank position, Nested 0, exact range.
- Retain UID0001IK as false/non-emitting parent with exact padding and relative nesting.
- Retain UID0000KY as file root and all compiler glue/thunks/wrappers as no-code/covered-by.
- Exact support links and historical labels are synchronized throughout the bounded MacroDialogs family without changing unrelated behavior.
- No new source file, class, child UID, split, import directive, raw table source, or IDA mutation is recommended.
- No B003 report lifecycle action is recommended or performed; lifecycle state remains external supervisor/validator-owned.

## Recommended Target Doc Changes

- Implemented validator-preserving path is `by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent.md`, retaining UID0004A5 and exact range.
- Implemented metadata is `COMPLETION:91`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000DQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000DQ`, blank position, `Nested:0`.
- Exact R1 and unconditional EventHandler pointer/mouse title/Item Summary/status are installed.
- Exact bytes, target hash, two-instruction/one-block body, `ret 4`, sole vtable xref, dispatcher route, secondary `+0xa0` receiver, predecessor/successor padding, owner/source placement, positive/negative evidence, rejected alternatives, and score rationale are incorporated.
- `IsSelectable` remains only explicitly historical/superseded provenance from B001 and pre-callback generated output.

## Recommended Support Doc Changes

These accepted changes are implemented:

- UID0004A4: validator-preserving rename to `by-memory/0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent.md`, `92/94`, exact R4, and full key behavior/type-10/type-9/invalidation evidence.
- UID0004A2: `90/93`, exact R3, exact `0x10c` allocation/caller/RectBounds-reference/inherited-control-flag evidence, with `SetSelectable` historicalized.
- UID0000DQ: `91/93`, exact R2, exact layout/access/method/vtable/caller/compiler-exclusion evidence, current renamed links, and no class Empty Emitter blocker.
- UID0001IK: `91/93`, retained owner UID0000KY, false state, blank emitter/position/formal, Nested -4, complete current inventory, exact padding, canonical event names, historical corrections, and no-code distinctions.
- UID0004AE/UID0004AF: validator-preserving New `HandleKeyOrTextEvent`/`HandlePointerOrMouseEvent` renames, `90/93` and `91/94`, exact R6/R5, and preserved New-specific state behavior.
- UID000095: scores/route/formal remain `85/87`/UID0000KY/blank; renamed links and exact EventHandler slot prose are synchronized without claiming the broader New class declaration is complete.
- UID0004AM/UID0004AN/UID0004AO: validator-preserving Integrate `HandleKeyOrTextEvent`, `HandlePointerOrMouseEvent`, and `HandleImeEvent` renames; `90/93`, `89/93`, `89/93`; exact R8/R7/R9; full state/forwarding behavior and unrelated helpers preserved.
- UID00006M: scores/route/formal remain `87/88`/UID0000KY/blank; only the three renamed links and exact interface roles are synchronized.
- UID0003DB: `90/94`, retained owner/emitter UID0000KY and comment marker, canonical secondary labels, target/class-generation proof, and preserved table ranges/COLs/xrefs/thunks/compiler exclusions.
- UID0001Y1: `89/93`, retained owner/emitter UID0000KY, true state, blank position, exact R10, and synchronized Spell/New/Integrate secondary slots without raw arrays.
- UID0000KY: retained `90/88` and path/route with current inventories, source/compiler distinctions, generated assertions, and historical stale names.
- All current ordinary links to the seven renamed pages were validator-managed. UID00004L, UID00004N, UID0000A2, UID000038, UID0003JA, UID0002PB, UID0001IL, UID0001IM, UID0001IN, UID0004AV, UID0004AW, and unrelated methods were reread verify-only; no contradiction required broader edits.

## Score And Metadata Recommendation

| Destination | Pre-callback | Implemented | Rationale / cap |
| --- | --- | --- | --- |
| UID0004A5 target | `86/90` | `91/94` | Exact body/range/hash/ABI/vtable/dispatcher/name/owner/C++; original lexical spelling remains inferred. |
| UID0004A4 Spell key | `88/91` | `92/94` | Full body and inherited contract resolved; helper lexical spelling remains descriptive. |
| UID0004A2 constructor | `87/90` | `90/93` | Exact layout/callers/state/source body; reference-vs-pointer original spelling remains inferred. |
| UID0000DQ class | `86/88` | `91/93` | Complete source declaration/layout/method cause; exact header/access spellings remain inferred. |
| UID0001IK parent | `90/91` | `91/93` | Exact current inventory/names/padding/compiler split; broad unrelated class polish prevents higher completion. |
| UID0004AF New target | `86/90` | `91/94` | Byte-identical exact inherited override. |
| UID0004AE New key | `88/91` | `90/93` | Exact body/slot/source signature; New field lexical names remain inferred. |
| UID0004AN/AM/AO | `86/90`, `88/91`, `86/90` | `89/93`, `90/93`, `89/93` | Exact slots/forwarding/event types; broader Integrate class/helper source audit remains open. |
| UID0003DB vtable data | `88/93` | `90/94` | Exact canonical slots/class source cause; data remains compiler-generated. |
| UID0001Y1 vtable family | `86/90` | `89/93` | Exact slot correction plus nonblank coverage marker; broad dialog tables retain lexical caps. |
| UID0000KY file | `90/88` | unchanged | Target correction does not resolve whether every dialog generation shared one original TU. |
| UID000095 / UID00006M | `85/87` / `87/88` | unchanged | Bounded link/slot corrections do not complete their broader class declarations. |

Score-improvement attempt:

- Signature/name blocker removed through exact `ret 4`, vtable, dispatcher, and inherited interface checks.
- Caller/reachability blocker removed through sole table xref plus dispatcher indirect route.
- Const/static/compiler-authorship blocker removed through interface/table comparison and distinct base target.
- Layout blocker removed through allocation size, constructor, COL, getter/key/paint, and ControlPane layout.
- Constructor type/state blocker removed through caller-local rectangle and base field evidence.
- Class formal blocker removed with R2 and natural layout.
- Generated marker blocker is removed by implemented R2/R10 and verified by final waited command `000000011805`.
- Original lexical/header/access spellings cannot be symbol-proven. They cap confidence/completion but do not justify blank C++ or stale decompiler names.

## Open Questions With Attempted Resolution

- Exact original method spelling: no PDB/source symbol exists. Checked vtable order, dispatcher, accepted EventHandler contract, sibling classes, current high-quality pane methods, generated output, and historical reports. Resolution: use project-canonical `HandlePointerOrMouseEvent`/`HandleKeyOrTextEvent`/`HandleImeEvent`; mark spelling inferred, not blocked.
- Derived constructor rectangle pointer versus const reference: binary ABI is one pointer; callers always pass a local rectangle address; base accepts nullable pointer. Resolution: derived const reference plus base `&bounds` best matches current human call sites. This is an inference cap only.
- `NarrowInputKey` exact implementation spelling: binary calls `std::ctype<char>::do_narrow`; current project uses `NarrowInputKey` as the source-facing expression across accepted handlers. Resolution: use it without inventing a new recovered binary helper.
- `m_controlFlags` exact original name: current ControlPane support uses this neutral descriptive name and multiple reconstructed constructors write it directly. Resolution: use it; do not revive unsupported `SetSelectable`.
- Access labels: no direct calls require public event methods; public constructor/getter, protected overrides, private field are safest conventional access. Access does not affect ABI. No blocker remains.
- Source TU: all direct evidence and current project grouping favor MacroDialogs. Exact header factoring remains unknown but does not affect the file emitter route.
- No unresolved question requires blank target/class C++, no-owner state, score freeze, split, or no-code reroute.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Read-only comparison covered `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md`. The rows remain supervisor-owned manual state. B003 did not edit them; the following is the exact replacement/addition text corresponding to the implemented ordinary pages.

`by-memory/-coverage-report.md`: replace the current UID0001IK row and insert the changed children immediately beneath it in address order:

```text
    - [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md) 0x0057f750-0x005807c5 | split index | MacroEditControlPanes : not_reconstructable : 91% : very-strong : Non-emitting MacroDialogs split inventory for Spell/New/Integrate row controls; exact source children own behavior, UID0004A5/UID0004A4 and same-slot family methods use canonical EventHandler signatures, parent-only padding remains excluded, and complete-object destructor glue, vtable thunks, scalar deleting wrappers, RTTI, and raw tables remain compiler/no-code coverage.
        - [UID:0004A2][0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor](by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md) 0x0057f760-0x0057f7a9 | constructor | SpellMacroEditControlPaneConstructor : reconstructable : 90% : very strong : Exact 0x49-byte constructor, two SpellMacroDialog call sites, 0x10c allocation, ControlPane base call, +0x108 spell key, inherited +0xff control flags, three compiler vptr stores, and source-ready const-RectBounds-reference R3.
        - [UID:0004A4][0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent.md) 0x0057f930-0x0057f998 | method | SpellMacroEditControlPaneHandleKeyOrTextEvent : reconstructable : 92% : very strong : Exact EventHandler +0x08 override with Event pointer ABI, type-8 key-down/type-10 text handling, ASCII normalization, +0x108 key store, self InvalidateRect(NULL), false key-up/nonletter behavior, and complete R4.
        - [UID:0004A5][0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent.md) 0x0057f9a0-0x0057f9a5 | method | SpellMacroEditControlPaneHandlePointerOrMouseEvent : reconstructable : 91% : very strong : Exact five-byte b0 01 c2 04 00 EventHandler +0x04 override, sole 0x0062d250 vtable xref, one Event pointer argument, unconditional true behavior, exact surrounding padding, UID0000DQ ownership, and complete R1.
        - [UID:0004AE][0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent.md) 0x0057fc80-0x0057fcff | method | NewMacroEditControlPaneHandleKeyOrTextEvent : reconstructable : 90% : very strong : Exact New EventHandler +0x08 override with active-child 2/3 gating, ASCII key/mode stores, text-input handling, self invalidation, and complete R6.
        - [UID:0004AF][0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent.md) 0x0057fd00-0x0057fd05 | method | NewMacroEditControlPaneHandlePointerOrMouseEvent : reconstructable : 91% : very strong : Byte-identical New EventHandler +0x04 unconditional-true override at vtable cell 0x0062d2f4; complete R5 supersedes stale IsSelectable naming.
        - [UID:0004AM][0x00580320-0x0058045d.IntegrateMacroEditControlPaneHandleKeyOrTextEvent](by-memory/0x00580320-0x0058045d.IntegrateMacroEditControlPaneHandleKeyOrTextEvent.md) 0x00580320-0x0058045d | method | IntegrateMacroEditControlPaneHandleKeyOrTextEvent : reconstructable : 90% : very strong : Exact Integrate EventHandler +0x08 override, text-edit forwarding/state transitions, semicolon text mode, ASCII item/spell assignment, type-10 handling, self invalidation, and complete R8.
        - [UID:0004AN][0x00580460-0x00580484.IntegrateMacroEditControlPaneHandlePointerOrMouseEvent](by-memory/0x00580460-0x00580484.IntegrateMacroEditControlPaneHandlePointerOrMouseEvent.md) 0x00580460-0x00580484 | method | IntegrateMacroEditControlPaneHandlePointerOrMouseEvent : reconstructable : 89% : very strong : Exact EventHandler +0x04 override forwarding Event pointers to the embedded text edit only while edit mode is active and otherwise returning true; complete R7.
        - [UID:0004AO][0x00580490-0x005804b4.IntegrateMacroEditControlPaneHandleImeEvent](by-memory/0x00580490-0x005804b4.IntegrateMacroEditControlPaneHandleImeEvent.md) 0x00580490-0x005804b4 | method | IntegrateMacroEditControlPaneHandleImeEvent : reconstructable : 89% : very strong : Exact EventHandler +0x0c IME override forwarding to the embedded text edit only while edit mode is active and otherwise returning true; complete R9 supersedes stale focus-event naming.
```

Under current UID00026J `SpellInventoryMacroReadOnlyData` row, add:

```text
        - [UID:0003DB][0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData](by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md) 0x0062d1e0-0x0062d3cc | vtable-data | MacroEditControlPaneVtableData : reconstructable : 90% : very strong : Exact Spell/New/Integrate MacroEditControlPane MSVC RTTI/vtable island with nine views, COL/store/thunk evidence, canonical EventHandler secondary slots, Ctrl+%d successor boundary, UID0000KY source route, and comment-only compiler coverage with no raw arrays.
```

`by-class/-coverage-report.md`: replace UID0000DQ, UID000095, and UID00006M rows:

```text
- [UID:0000DQ][SpellMacroEditControlPane](by-class/SpellMacroEditControlPane.md) : reconstructable : 91% : very strong : Complete 0x10c ControlPane-derived spell macro row class with exact +0x108 word field, natural tail padding, constructor/getter/paint/EventHandler overrides, implicit destructor/compiler-glue split, complete managed declaration, vtable views, caller routes, and MacroDialogs ownership.
- [UID:000095][NewMacroEditControlPane](by-class/NewMacroEditControlPane.md) : reconstructable : 85% : strong : Macro row control attached to MacroDialogs; state offsets, getters/setters, paint, canonical HandlePointerOrMouseEvent/HandleKeyOrTextEvent overrides, compiler teardown/scalar/thunk support, and vtable views documented; broader final class declaration remains separate debt.
- [UID:00006M][IntegrateMacroEditControlPane](by-class/IntegrateMacroEditControlPane.md) : reconstructable : 87% : strong : Integrated macro row control attached to MacroDialogs with text-edit state, paint/sync/lifecycle methods, canonical pointer/key/IME EventHandler overrides, compiler thunk/scalar support, and preserved broader class/helper source-form caveats.
```

`by-file/-coverage-report.md`: replace UID0000KY row:

```text
- [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md) : reconstructable : 90% : strong : Macro dialog/edit-control source family with exact split inventories, canonical EventHandler override names, complete SpellMacroEditControlPane declaration/0x10c layout, registry macro records, vtable/compiler-artifact coverage, historical stale-name corrections, and unchanged generation-grouping caveat.
```

`by-type/by-vtable/-coverage-report.md`: replace UID0001Y1 row:

```text
- [UID:0001Y1][MacroDialogFamilyVtables](by-type/by-vtable/MacroDialogFamilyVtables.md) : reconstructable : 89% : very strong : MacroDialogs-owned MSVC vtable family with exact dialog/edit-control table bases, COL/store/thunk evidence, canonical Spell/New/Integrate EventHandler secondary slot identities, comment-only compiler coverage marker, and no handwritten vtable/RTTI arrays.
```

The generated research tracker and generated C++ remain validator-owned. Final waited validator command `000000011805` refreshed generated metadata and `MacroDialogs.cpp` from the implemented ordinary pages; B003 made no manual generated edit. Manual coverage application and all report lifecycle state remain external.

## Follow-Up Actions

- Implementation and ordinary scoped validation are complete; no B003 implementation item remains.
- Report validation/execution/count/path/move/archive state and manual coverage application are external supervisor/validator-owned. This artifact neither asserts nor directs those lifecycle results.
- No A-agent action, new split, additional source target, or further B003 callback action is recorded by this artifact.

## Confidence

- Recommendation confidence: very strong (`94`) for target range/behavior/ABI/slot/owner/source route; strong for descriptive lexical/access/type spellings.
- Score confidence: strong. The target is above source-ready threshold because every behavioral and routing blocker is closed; the score remains below 95 because original names/source/header are unavailable.
- Remaining uncertainty: only original lexical spellings, derived bounds reference-versus-pointer spelling, and exact header/access style. None affects exact behavior, range, layout, owner/emitter, or the ability to emit first-draft source.

## Validator Results

All commands were run from `source-3/project-documentation` with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; commands `000000011801` and final `000000011805` additionally used `--wait-generated`. All seventeen commands exited `0` with `ok: 1`.

| Command ID | Timestamp | Scoped ordinary destination | Result / side effects |
| --- | --- | --- | --- |
| `000000011761` | `2026-07-14T15:48:57-04:00` | renamed UID0004A5 target | exit 0, ok 1; UID-preserving path/score/formal update, eight link updates, generated refresh deferred. |
| `000000011764` | `2026-07-14T15:49:51-04:00` | renamed UID0004A4 Spell key/text | exit 0, ok 1; UID-preserving path/score/formal update, eight link updates, generated refresh deferred. |
| `000000011767` | `2026-07-14T15:50:33-04:00` | UID0004A2 constructor | exit 0, ok 1; score/formal/evidence accepted, generated refresh deferred. |
| `000000011769` | `2026-07-14T15:51:50-04:00` | UID0000DQ Spell class | exit 0, ok 1; registry formal changed blank to block, generated refresh deferred. |
| `000000011770` | `2026-07-14T15:52:33-04:00` | renamed UID0004AF New pointer/mouse | exit 0, ok 1; UID-preserving path/score/formal update, eight link updates, generated refresh deferred. |
| `000000011772` | `2026-07-14T15:53:23-04:00` | renamed UID0004AE New key/text | exit 0, ok 1; UID-preserving path/score/formal update, eight link updates, generated refresh deferred. |
| `000000011774` | `2026-07-14T15:54:07-04:00` | renamed UID0004AN Integrate pointer/mouse | exit 0, ok 1; UID-preserving path/score/formal update, seven link updates, generated refresh deferred. |
| `000000011776` | `2026-07-14T15:55:06-04:00` | renamed UID0004AM Integrate key/text | exit 0, ok 1; UID-preserving path/score/formal update, eight link updates, generated refresh deferred. |
| `000000011778` | `2026-07-14T15:55:49-04:00` | renamed UID0004AO Integrate IME | exit 0, ok 1; UID-preserving path/score/formal update, seven link updates, generated refresh deferred. |
| `000000011780` | `2026-07-14T15:56:44-04:00` | UID000095 New class | exit 0, ok 1; bounded prose/link sync accepted; validator-owned projected-stats/reference side effects only. |
| `000000011782` | `2026-07-14T15:57:38-04:00` | UID00006M Integrate class | exit 0, ok 1; bounded prose/link sync accepted; generated refresh deferred. |
| `000000011793` | `2026-07-14T15:59:31-04:00` | UID0001IK split parent | exit 0, ok 1; metadata/inventory/padding/history accepted; generated refresh deferred. |
| `000000011797` | `2026-07-14T16:01:00-04:00` | UID0003DB vtable data | exit 0, ok 1; canonical slots/class cause/compiler marker accepted; generated refresh deferred. |
| `000000011798` | `2026-07-14T16:01:47-04:00` | UID0001Y1 vtable family | exit 0, ok 1; registry formal changed blank to block; validator emitted the project-level rescore recommendation/statistics side effect, with no scoped validation failure. |
| `000000011801` | `2026-07-14T16:05:39-04:00` | UID0000KY MacroDialogs file | exit 0, ok 1; bounded file sync accepted; reference index/projected stats/registry/generated metadata refreshed; initial waited generated refresh completed. |
| `000000011804` | `2026-07-14T16:14:33-04:00` | UID0004AM R8 byte-exact repair | exit 0, ok 1; inserted the one report-required blank line, registry formal hash changed `6b119c...` -> `2dd3d2...`, projected stats updated, generated refresh deferred; lease released immediately. |
| `000000011805` | `2026-07-14T16:14:42-04:00` | final UID0000KY MacroDialogs verification | exit 0, ok 1; final reference/projected-stats/registry/generated metadata refresh completed and current generated output was waited. |

Generated readback: `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`, header command `000000011805`, refreshed `2026-07-14T16:14:42-04:00`, SHA256 `514ADBEBD680E3D89C1170821CB7F778F17FA053AAB526236758E9F6F518C0EA`. A direct managed-body comparison reports R1-R10 all byte-for-byte equal between this report and their destination pages. UID0000DQ closes with `};` before UID0004A1-UID0004A5 definitions. R1, R3, R4, R5, R6, R7, R8, and R9 each occur exactly once; canonical New/Integrate definitions each occur once; stale Spell/New/Integrate renamed definitions occur zero times. UID0004A5, UID0000DQ, and UID0001Y1 have zero Empty Emitter Markers. All 61 `// UID:` emission comments are unique, and searches found zero handwritten `__declspec(naked)`, `__asm`, complete-object-locator/type-info arrays, security-cookie/EH handler constructs, or vtable arrays. Existing unrelated generated methods remain represented once by unique UID emission rows. The six remaining Empty Emitter Markers belong to unchanged broader class pages UID00006L/00006M/00007I/000094/000095/0000DP and are outside the accepted formal scope; none is the target, complete Spell class, or vtable-family destination.

Warnings/errors: no scoped command failed. Global validator diagnostics and generated-metadata/statistics/registry updates were validator-owned side effects, not manual B003 edits.

## Changed Files

- Report updated in place: `tools/leaser/Agents/Agent-B003/research/0004A5-SpellMacroEditControlPaneIsSelectable-source-quality.md`.
- Validator-preserving rename: `by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneIsSelectable.md` -> `by-memory/0x0057f9a0-0x0057f9a5.SpellMacroEditControlPaneHandlePointerOrMouseEvent.md` (UID0004A5).
- Validator-preserving rename: `by-memory/0x0057f930-0x0057f998.SpellMacroEditControlPaneOnKeyEvent.md` -> `by-memory/0x0057f930-0x0057f998.SpellMacroEditControlPaneHandleKeyOrTextEvent.md` (UID0004A4).
- Validator-preserving rename: `by-memory/0x0057fd00-0x0057fd05.NewMacroEditControlPaneIsSelectable.md` -> `by-memory/0x0057fd00-0x0057fd05.NewMacroEditControlPaneHandlePointerOrMouseEvent.md` (UID0004AF).
- Validator-preserving rename: `by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneOnKeyEvent.md` -> `by-memory/0x0057fc80-0x0057fcff.NewMacroEditControlPaneHandleKeyOrTextEvent.md` (UID0004AE).
- Validator-preserving rename: `by-memory/0x00580460-0x00580484.IntegrateMacroEditControlPaneForwardMouseEvent.md` -> `by-memory/0x00580460-0x00580484.IntegrateMacroEditControlPaneHandlePointerOrMouseEvent.md` (UID0004AN).
- Validator-preserving rename: `by-memory/0x00580320-0x0058045d.IntegrateMacroEditControlPaneOnKeyEvent.md` -> `by-memory/0x00580320-0x0058045d.IntegrateMacroEditControlPaneHandleKeyOrTextEvent.md` (UID0004AM).
- Validator-preserving rename: `by-memory/0x00580490-0x005804b4.IntegrateMacroEditControlPaneForwardFocusEvent.md` -> `by-memory/0x00580490-0x005804b4.IntegrateMacroEditControlPaneHandleImeEvent.md` (UID0004AO).
- Modified ordinary pages: `by-memory/0x0057f760-0x0057f7a9.SpellMacroEditControlPaneConstructor.md`, `by-class/SpellMacroEditControlPane.md`, `by-class/NewMacroEditControlPane.md`, `by-class/IntegrateMacroEditControlPane.md`, `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`, `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md`, `by-type/by-vtable/MacroDialogFamilyVtables.md`, and `by-file/MacroDialogs.md`.
- Final self-review repaired UID0004AM only by restoring the single report-required blank line in R8; validator `000000011804` passed before final waited command `000000011805`. No behavior, metadata, score, route, evidence, or non-formal prose changed in that repair.
- Validator-managed rename link propagation updated current ordinary links, including the existing UID0004AI support page, under the corresponding rename commands; no stale exact old path remains in ordinary `by-*` docs.
- Verify-only and unchanged: `by-class/Event.md` (UID00004L), `by-class/EventHandler.md` (UID00004N), Pane/ControlPane and constructor/vtable support UID0000A2/000038/0003JA/0002PB, compiler/no-code UID0001IL/0001IM/0001IN/0004AV/0004AW, and unrelated MacroDialogs methods.
- Restricted files: B003 manually edited no `-coverage-report.md`, auto-generated/generated C++, tracker, audit, supervisor, validator registry/state/queue/lock, goal, lifecycle, or archive file. Validator-owned generated/statistics/index/registry side effects are recorded above.
- IDA remained read-only. B003 ran no report execute/probe/count/move/archive/lifecycle command.
- Leases were acquired one ordinary destination at a time, released immediately after its validator, and `Agents/current_leases.md` currently reports no active lease.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation; exact report SHA `C3241378DCE6C8F50661172AA8FFC03A9298F2CCCEFE5F15265BF81EDF079BED` was accepted.
- [x] Validator-preserving rename UID0004A5 and apply exact target metadata, Item Summary, evidence, history, score, and R1 (`000000011761`).
- [x] Apply UID0000DQ exact `0x10c` layout/access/method evidence, `91/93`, and R2 with class closed before `[[CHILDREN]]` (`000000011769`; generated `000000011805`).
- [x] Apply UID0004A2 constructor correction/score/evidence/R3; remove stale `SetSelectable` source assertion without deleting historical provenance (`000000011767`).
- [x] Validator-preserving rename UID0004A4 and apply exact Event/type/ASCII/invalidation behavior, `92/94`, and R4 (`000000011764`).
- [x] Validator-preserving rename UID0004AF/UID0004AE and apply R5/R6 plus bounded New class/support synchronization (`000000011770`, `000000011772`, `000000011780`).
- [x] Validator-preserving rename UID0004AN/UID0004AM/UID0004AO and apply R7/R8/R9 plus bounded Integrate class/support synchronization (`000000011774`, `000000011776`, `000000011778`, `000000011782`); byte-exact R8 repair passed `000000011804`.
- [x] Update UID0001IK exact inventory, padding, non-emitting route, relative nesting, history, score, and all renamed links (`000000011793`).
- [x] Update UID0003DB exact slot names/class source cause/score while retaining compiler-only marker and all raw table facts (`000000011797`).
- [x] Update UID0001Y1 exact slot names/score and apply R10 without raw arrays (`000000011798`).
- [x] Update UID0000KY bounded source inventory/generated assertions/history while preserving unchanged score/path and unrelated concurrent content (`000000011801`; final revalidation `000000011805`).
- [x] Verify-only UID00004L, UID00004N, UID0000A2, UID000038, UID0003JA, UID0002PB, UID0001IL, UID0001IM, UID0001IN, UID0004AV, UID0004AW, and unrelated MacroDialogs methods; no concrete contradiction found.
- [x] Preserve exact range/hash/bytes/xrefs/COLs/callers/layout/padding/source/compiler distinctions/negative evidence/rejected alternatives/score caps at report-level detail.
- [x] Retain exact supervisor-owned manual coverage text while making no B003 manual coverage edit; C19 records the exclusion reason.
- [x] Update C01-C20 ledger rows to legal final action/state values with exact destination/validator/generated proof.
- [x] Lease one ordinary file immediately before editing, reread after acquisition, scoped-validate, and release before the next lease; final lease report is empty.
- [x] Run one scoped validator for every changed/renamed ordinary destination and record command ID, timestamp, exit, ok count, warnings, and side effects; all seventeen commands from `000000011761` through `000000011805` are itemized above.
- [x] Run final authorized `--wait-generated` refresh through UID0000KY and record command/header freshness/SHA (`000000011805`, `2026-07-14T16:14:42-04:00`, `514ADBEBD680E3D89C1170821CB7F778F17FA053AAB526236758E9F6F518C0EA`).
- [x] Verify generated MacroDialogs.cpp has UID0000DQ class closed before child definitions; R1/R3/R4 exactly once; one canonical target definition; zero stale Spell `IsSelectable`/`OnKeyEvent`; zero UID0004A5/UID0000DQ/UID0001Y1 Empty Emitter Markers; canonical New/Integrate R5-R9 once; no duplicate/wrong-range body; no handwritten vtable/RTTI/destructor ABI code; unrelated methods represented once by unique UID rows.
- [x] Confirm third-party import directive is not applicable; this is project C++ source, not a static third-party embed.
- [x] Confirm no manual generated/manual-coverage/tracker/audit/supervisor/validator-state/lifecycle/IDA edit and no B003 execute/probe/count/move/archive command.

Implementation callback pass:

- [x] Exact report accepted by supervisor for implementation.
- [x] All accepted C01-C20 and R1-R10 details incorporated at report-level depth.
- [x] All accepted metadata/score/owner/emitter/rename/formal changes applied or explicitly excluded with concrete reason.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, padding, compiler distinctions, and verify-only boundaries preserved.
- [x] Every changed/renamed ordinary destination validator passed and results are recorded.
- [x] Final waited generated refresh/readback `000000011805` passed all exact structure/name/count/marker/no-raw-array assertions, and direct comparison confirms R1-R10 destination bodies are byte-for-byte equal to this report.
- [x] Exact manual supervisor-owned coverage text retained/reconciled without B003 editing coverage.
- [x] C01-C20 final states, Validator Results, Changed Files, current state, and checklist reconciled to durable callback truth.
- [x] No B003 lease or unapplied accepted implementation item remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000011858","destination_path":"executed-b-agent-research/B003/0004A5-SpellMacroEditControlPaneIsSelectable-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004A5-SpellMacroEditControlPaneIsSelectable-source-quality.md","timestamp":"2026-07-14T16:43:06-04:00","uid":"0004A5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
