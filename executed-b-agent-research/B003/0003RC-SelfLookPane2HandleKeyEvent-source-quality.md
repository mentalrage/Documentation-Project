** TARGET-REPORT-UID:0003RC **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003RC SelfLookPane2HandleKeyOrTextEvent Source-Quality Report

## Finalized Report / Current Recommendation

- UID0003RC is one exact source-authored virtual method at `[0x00571c10,0x00571cb2)`, `0xa2` / 162 bytes, SHA256 `1CB7A6B49D3183AAFC55DF0F84CA0C247CAE7F444466ABA66B557FF93B3B6ADA`.
- The strongest current source identity is `bool SelfLookPane2::HandleKeyOrTextEvent(Event *event)`, not the historical `HandleKeyEvent(const PanelKeyEvent *)` title/declaration and not the unrelated UserLook `OnKeyEvent` spelling. The target occupies the accepted EventHandler secondary `+0x08` key/text slot.
- The validator-preserving UID0003RC rename is implemented at `by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md`; target score is `92/94`, with owner/emitter UID0000CV, `RECONSTRUCTABLE:TRUE`, blank optional position, `Nested:0`, exact range, and no split preserved.
- Destination R1 is implemented as complete human-written C++ that preserves translation before event-type filtering, the separate zero-modifier gates, PageUp before PageDown, every mode transition, every recognized no-call/consumed path, and every false path.
- The `this-0xa0` call adjustments and `[facet+0xcdc]` read are multiple-inheritance lowering. Source uses the complete `SelfLookPane2` object and its `m_viewMode` at complete offset `+0xd7c`.
- No implementation item remains. Original lexical names remain inferred and cap confidence, but current Event/EventHandler/EventMan/key/view conventions resolve every source type, field, helper, constant, signature, and behavior needed by R1.
- B003 completed the bounded ordinary-document implementation, serial scoped validators, and waited generated readback. B003 did not manually edit coverage/generated/tracker/audit/supervisor/validator-state files or IDA and ran no report execution, probe, count, move, archive, or lifecycle command. Subsequent report validation/execution/count/path/move/archive state is external supervisor/validator-owned and is neither asserted nor directed here.

## Supporting Research

### Documentation and generated evidence

- Historical pre-callback UID0003RC state was `85/89`, owner/emitter UID0000CV, reconstructable true, blank optional position/formal C++, `Nested:0`, the exact range, and only the bounded PageDown/UID0003RA caller contract. Current UID0003RC is renamed, `92/94`, and carries R1 plus exhaustive evidence while preserving the accepted metadata/range/nesting.
- UID0000CV `by-class/SelfLookPane2.md` now provides exact Pane-derived layout, `m_viewMode` at complete object `+0xd7c`, `ViewMode_Default/Spelled/Legend`, the three called view helpers, and exact `virtual bool HandleKeyOrTextEvent(Event *event);` R2 declaration.
- UID00004N `by-class/EventHandler.md` currently declares secondary slots in source order as `HandlePointerOrMouseEvent(Event *)`, `HandleKeyOrTextEvent(Event *)`, `HandleImeEvent(Event *)`, and later event families. That declaration, the exact vtable cell, and sibling implementations outweigh historical generic `HandleKeyEvent`/`OnKeyEvent` labels.
- UID00004L `by-class/Event.md` provides exact type/key/modifier fields at complete Event offsets `+0x04`, `+0x08`, and `+0x10a`, plus `kEventKeyDown = 8`.
- UID00004O/UID00014C identify `0x004a8b10` as the EventMan key translation adaptor. Its stale IDA `std::ctype<char>::do_narrow` label is not source authority.
- UID0003R8, UID0003R9, and UID0003RA are separate complete-object `SelfLookPane2` view methods. This target calls them; it neither owns their bodies nor duplicates their state changes.
- Evidence-time generated command `000000010815`, refreshed `2026-07-14T05:36:59-04:00`, contained the historical UID0003RC Empty Emitter Marker and stale declaration; that state is explicitly pre-callback evidence only. Current waited command `000000010866`, refreshed `2026-07-14T06:22:06-04:00`, emits the exact corrected class and target once, emits R3 once, contains no old target title/path or UID0003RC/UID00038M/UID00038N Empty Emitter Marker, and contains no raw vtable address/array.

### Historical-report search provenance and classification

Exact terms searched read-only were `0003RC`, `0x00571c10`, `00571c10`, `SelfLookPane2HandleKeyEvent`, `SelfLookPane2HandleKeyOrTextEvent`, `sub_571C10`, `HandleKeyEvent`, and `HandleKeyOrTextEvent`.

| Root searched | Exact outcome | Target-specific classification |
| --- | --- | --- |
| `source-3/project-documentation/executed-b-agent-research/**` | Direct address/title terms matched B001 UID0001HK and B003 UID0003RA. `0003RC` matched UID0003RA. Broader method terms also matched B005 UserLook, B001 EventHandler/Scrollable, B003 MainMenu/TextEdit, B011, and other pane reports. | No prior direct UID0003RC full-body report exists. B001 created the exact child and vtable route but left key names/body unresolved. B003 UID0003RA proved only one PageDown caller contract and explicitly left UID0003RC blank. The other reports are interface/helper/key-name comparators only. |
| `source-3/project-documentation/archived/**` | Zero matches for every exact term. | No archived direct-target research or competing conclusion. |
| `source-3/project-documentation/tools/leaser/Agents/Older-Research/**` | Zero matches for every exact term. | No older-research target evidence. |
| `source-3/project-documentation/tools/leaser/Agents/SpecialReports/**` | Zero matches for every exact term. | No special-report target evidence. |
| `source-3/project-documentation/tools/leaser/Agents/**` | Current B003 goal and audit/supervisor notes matched assignment terms; no active direct-target research report matched the proposed new title. | Current B003 goal is assignment authority. Audit/supervisor notes are workflow context, not binary or source evidence. No competing B001-B005 direct report was found. |

Relevant executed matches were opened and classified:

- B001 `0001HK-selflookpane2-source-split-audit.md`: exact interval, size, vtable cell `0x00624750`, internal helper calls, and child creation; generic `key handler` title and old `85/89` blocker are superseded by this direct pass.
- B003 `0003RA-SelfLookPane2ShowLegendView-source-quality.md`: exact unmodified PageDown mode-1 call to UID0003RA, PageDown mode-0 call to UID0003R9, PageUp complement, complete class layout, and preserved target blank state before this pass. It is bounded caller support, not target reconstruction.
- B003 `0003QZ-SelfLookPane2OnDraw-source-quality.md`: complete `0xd90` layout and view-mode/helper context. It does not resolve this key method.
- B011 `0000NL-SelfLookPane-empty-emitter-family-source-quality.md`: historical class skeleton with `HandleKeyEvent(const PanelKeyEvent *)`; it is earlier descriptive naming, not slot-specific authority.
- B005 `0003RO-UserLookPaneHandleKeyEvent-source-quality.md`: same Event offsets, EventMan call, translated `0x93/0x94` names, zero-modifier semantics, and translate-before-type order. UserLook's `OnKeyEvent`/`int` declaration is a separate accepted class-family surface and is not copied into SelfLookPane2.
- B008 `00014C-EventManAndEventFactoryHelpers-source-quality.md`: rejects CRT ownership for `0x004a8b10`, proves the ten-byte two-argument adaptor and 81 key-handler refs.
- B003 `00036Y-MainMenuPaneCore-source-quality.md`, B001 ScrollableControlPane work, and B003 TextEditControlPane work: current source-facing comparators for EventHandler secondary `+0x08` as `HandleKeyOrTextEvent(Event *)`.
- B001 `00014A-eventhandler-base-source-quality.md`: historical report used shorter generic slot names. Current implemented UID00004N declaration is newer and more specific, so that old lexical spelling is retained only as naming history.

## Target

- UID: `0003RC`
- Historical pre-callback path: `by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyEvent.md`
- Implemented UID-preserving path: `by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md`
- Exact interval: `[0x00571c10,0x00571cb2)`
- Exact size: `0xa2` / 162 bytes (Verified with `tools/int_convert.py`).
- Exact SHA256: `1CB7A6B49D3183AAFC55DF0F84CA0C247CAE7F444466ABA66B557FF93B3B6ADA`.
- Historical pre-callback metadata: `85/89`, `CANONICAL_OWNER:0000CV`, `EMITTER_UIDS:0000CV`, `RECONSTRUCTABLE:TRUE`, blank optional position, blank formal C++, `Nested:0`.
- Implemented metadata: `92/94`; every owner/emitter/reconstructable/position/nesting/range property is preserved and R1 is exact.
- Implemented source identity: `bool SelfLookPane2::HandleKeyOrTextEvent(Event *event)`.

## Current Target State

- The exact child/range/owner route, UID-preserving source name, R1 body, `92/94` score, and all supporting evidence are implemented and scoped-validated.
- Both transition halves are preserved in full: unmodified Page Up mode 2 -> Spelled, mode 1 -> Default, mode 0/other -> consumed no-call; unmodified Page Down mode 0 -> Spelled, mode 1 -> Legend, mode 2/other -> consumed no-call.
- SHA256/full bytes, both parent-only padding spans, ABI/facet explanation, translation-before-type ordering, every false/true path, exact secondary-vtable route, exhaustive negative evidence, and complete R1 are current target documentation.
- The command-`000000010815` target marker is historical pre-callback evidence. Waited command `000000010866` emits UID0003RC exactly once with no target marker or old title/path.
- All B003 implementation, validation, readback, ledger, and checklist items are complete; no B003 implementation item remains.

## Executive Recommendation

UID0003RC is implemented through the validator-preserving workflow as one `SelfLookPane2::HandleKeyOrTextEvent(Event *)` definition under owner/emitter UID0000CV and file route UID0000NL `NexusTK/ui/panels/SelfLookPane.cpp`. Exact target range, both parent-only alignment spans, EventHandler-facet lowering, helper order, and every consumed/no-call path are preserved. Only the bounded parent/class/file/view-link/vtable support listed below was synchronized; Event, EventHandler, EventMan, g_pEventMan, UID0003QZ, UID0003RD, Pane, and PanelPane remained verify-only because their detail was sufficient and non-contradictory.

## Supervisor Active Recheck

- The replaced B003 goal was reread and UID0003RC remained the sole assigned target.
- Fresh streamable MCP `idb_list` discovered one active adopted worker-backed NexusTK session, `2aa80220`, rather than relying on a stale session ID.
- `server_health` for `2aa80220` returned `status:ok`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and 2,067 cached strings at evidence-collection time.
- A valid bounded `get_bytes(database='2aa80220', addr='0x00571c10', size=16)` returned real target bytes beginning `55 8B EC 56 57 8B 7D 08 8B F1 8B 0D 54 A7 67 00`.
- Full target, boundary, disassembly, decompile, xref, callee, helper, vtable, and pointer-pattern checks were repeated against that live session after recovery. No fallback-only evidence is used.
- No IDA process was managed and no IDA mutation was requested. No subagent was spawned.

## Inference Research Guidance Check

- Direct binary facts are separated from source-facing inference. Range, bytes, hash, stack cleanup, AL truth result, vtable cell, event offsets, constants, comparisons, mode values, call targets, receiver adjustments, branch order, and padding are direct.
- `HandleKeyOrTextEvent`, `Event`, `m_type`, `m_payload.m_key.m_key`, `m_payload.m_key.m_modifiers`, `g_pEventMan`, `TranslateEventKey`, `kEventKeyDown`, `kPaneKeyPageUp`, `kPaneKeyPageDown`, `m_viewMode`, `ViewMode_*`, and view-helper names are current project source-facing identifiers. Original symbols do not prove their lexical spelling.
- Raw `this-0xa0`, `this[823]`, byte-array event indexing, stale CRT names, signed decimal key values, and decompiler labels do not appear in formal C++.
- Compiler prologue/epilogue/register saves, vtable arrays, RTTI, adjustor thunks, and adjacent alignment are excluded from source.
- R1 uses ordinary mid-2000s C++ constructs, explicit branches matching machine ordering, no modern-only syntax, and no reverse-engineering offset comments.

## Heuristic / Inference Reanalysis And Validation

| Question | Direct evidence and comparator check | Resolution |
| --- | --- | --- |
| Real source method or compiler body? | Modeled 162-byte function, coherent 58-instruction CFG, 14 basic blocks, cyclomatic complexity 7, source state dispatch, one virtual cell, four source callees, and four explicit `retn 4` exits. | Real source-authored virtual method; not thunk, wrapper, library body, padding, or no-code artifact. |
| Exact method name | Sole data route is secondary vtable base `0x00624748` cell `+0x08`; current EventHandler declaration calls this family `HandleKeyOrTextEvent(Event *)`. MainMenu/Scrollable/TextEdit use the same current spelling. | Rename from historical `HandleKeyEvent` to `HandleKeyOrTextEvent`. Reject `OnKeyEvent` as UserLook-local precedent and raw `sub_571C10`. |
| Parameter type | Reads exact Event offsets `+4/+8/+0x10a`; current Event is exact `0x110`. The method occupies the base `Event *` virtual slot. | Use non-const `Event *event` to match the accepted override. Reject `PanelKeyEvent`, raw byte pointer, and target-local structs. |
| Return type | Every exit writes `AL=1` or `AL=0`; callers dispatch through a bool EventHandler slot. No integer payload is formed. | `bool`, despite IDA's generic `char`. |
| Receiver shape | Entry ECX is the EventHandler facet at complete `SelfLookPane2+0xa0`; `[esi+0xcdc]` is complete `+0xd7c`; each view call uses `lea ecx,[esi-0xa0]`. | Source is an ordinary complete-object member accessing `m_viewMode`; raw adjustment is compiler multiple-inheritance lowering. |
| Translation helper | Target loads `g_pEventMan`, pushes modifiers then key so source argument order is key, modifiers, and calls ten-byte `0x004a8b10`. Helper returns first byte and ignores second in this build; 81 refs are key handlers. | Use `g_pEventMan->TranslateEventKey(key, modifiers)` and preserve the call plus both arguments. Reject CRT/locale ownership and local inline narrowing. |
| Translation order | The call at `0x571c2d` precedes event type compare at `0x571c32`. | R1 computes translated key before `m_type != kEventKeyDown`; do not factor the call inside the type branch. |
| Key values | Machine compares AL with bytes `0x93`, then `0x94`; signed decompile shows `-109/-108` only because IDA used `char`. Executed pane-key work names them PageUp/PageDown. | Use unsigned `kPaneKeyPageUp`/`kPaneKeyPageDown`; reject Win32 `VK_PRIOR/VK_NEXT` and signed semantic interpretations. |
| Modifier semantics | Each recognized key separately compares the entire byte at `Event+0x10a` with zero. No bit mask or selected flag is tested. | Require `m_modifiers == 0`; nonzero means false. Preserve separate branch-local gates. |
| PageUp transitions | Mode 2 branches to common ShowSpelled call; mode 1 calls ShowDefault; mode 0 or any other value skips calls. All recognized unmodified paths return true. | Exact matrix: Legend -> Spelled, Spelled -> Default, Default/other -> consumed no-call. |
| PageDown transitions | Mode 1 calls ShowLegend; mode 0 calls common ShowSpelled; mode 2 or any other nonzero value skips calls. All recognized unmodified paths return true. | Exact matrix: Default -> Spelled, Spelled -> Legend, Legend/other -> consumed no-call. |
| Helper result use | All three calls flow directly to explicit `AL=1`; no helper return is tested. | Helpers remain `void`; target itself returns handled true. |
| Base fallback | Unsupported type/key/modifier routes go directly to `AL=0`; no inherited handler call exists. | Return false, with no base fallback or second dispatch. |
| Split/factorization | One entry, one coherent two-key state machine, no interior xref/pointer, no source-independent suffix, and shared epilogues only. | No split, merge, or outlined helper. `Nested:0` remains exact. |
| Access | Base event-family virtuals and current SelfLookPane2 virtual section are public. Binary does not encode access. | Keep public override in R2; note exact lexical access is inferred but implementation-safe. |

Every source/C++ blocker has a best current resolution. Remaining original-symbol uncertainty is a confidence cap, not a reason to leave the target blank.

## Evidence Standards Used

- Mandatory healthy IDA MCP with fresh discovery, health, bounded byte probe, full bytes, function lookup, disassembly, decompile, analysis, xrefs, callees, and pointer-pattern searches.
- Exact half-open range, explicit byte count, SHA256, first/last instructions, predecessor/successor functions, and parent-only padding hashes.
- Instruction-ordered behavior and branch matrix rather than decompiler-only pseudocode.
- Current Event/EventHandler/EventMan/SelfLookPane2/vtable documentation and generated readback.
- Exhaustive historical report search across executed, archived, Older-Research, SpecialReports, and active Agent roots.
- Positive and negative reachability: code/data/immediate refs, VA/RVA byte patterns, strings, vtable cell, and internal split checks.
- Numeric conversions were checked with `tools/int_convert.py`: `0xa2=162`, `0x0b=11`, `0x0e=14`, `0xa0=160`, `0xcdc=3292`, `0xd7c=3452`, `0x10a=266`.

## Evidence Checked

### Mandatory MCP availability and recovery record

- Endpoint: `http://127.0.0.1:13337/mcp`, streamable JSON-RPC, read-only use.
- Fresh `idb_list` returned session `2aa80220` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, created `2026-07-14T05:43:09.926764`, active/adopted worker PID 21392 at evidence-collection time.
- `server_health` returned `status:ok`, uptime 523.644 seconds on the recorded pass, module `NexusTK.exe`, image base `0x400000`, analysis/Hex-Rays/strings ready, strings count 2,067.
- Valid bounded read returned target bytes. Full reads, lookup, disassembly, analysis, xrefs, helper disassembly, vtable bytes, and pointer searches then succeeded against the same database session.
- An initial local PowerShell wrapper used the wrong get-bytes field name and was rejected before a valid IDB read. `tools/list` supplied the exact `addr` schema, after which the required valid bounded IDB-backed call succeeded. This was a client-shape error, not evidence of an IDB outage.
- The earlier empty-session state is not used. No MCP/IDA process was started, stopped, restarted, killed, or otherwise managed by B003.

### Current documentation and support checked

- Target UID0003RC; parent UID0001HK; class UID0000CV; file UID0000NL.
- View helpers UID0003R8, UID0003R9, UID0003RA; neighboring UID0003RB OnPaint and UID0003RD pointer/mouse handler; UID0003QZ activation caller.
- UID00004L Event, UID00004N EventHandler, UID00004O EventMan, UID00014C mixed Event/EventMan helpers, UID00028L g_pEventMan, Pane/PanelPane, and source-local vtable pages UID00038M/UID00038N.
- Analogous UserLook, MainMenu, ScrollableControlPane, TextEditControlPane, FittingRoom, Parcel, and popup-menu key handlers for type/signature/helper/constant naming only.
- Evidence-time generated `SelfLookPane.cpp` and current manual by-memory/by-class/by-file/by-vtable coverage rows.
- Every historical root and exact term listed under Supporting Research.

### Failed, unavailable, or intentionally skipped checks

- No strings exist in the target; string lookup cannot improve source identity.
- No original PDB/symbol name exists for the target, helper lexical spelling, page-key enum spelling, or physical source filename. Current project-wide interface and behavior evidence supplies the strongest implementation-safe names.
- IDA mutation was never performed. Implementation validators were intentionally skipped during the historical report-only pass, then run only after the supervisor-authorized callback as recorded under Validator Results.

## Claim And Incorporation Ledger

| Claim ID | Atomic claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Mandatory MCP evidence was collected against healthy evidence-time IDB session `2aa80220`; all final bounded calls succeeded after fresh discovery. | very strong | idb_list, health, lookup, get_bytes | UID0003RC evidence/history and report provenance | incorporate | applied | UID0003RC carries the durable evidence-time health/request record; rename/target validator `000000010837` returned exit 0, `ok:1`. No IDA mutation occurred. |
| C02 | Target is exactly `[0x00571c10,0x00571cb2)`, `0xa2`/162 bytes, SHA256 `1CB7...B6ADA`. | very strong | full bytes, lookup, hash | UID0003RC range/evidence/Item Summary | incorporate | applied | Exact range, explicit size, hash, first/final bytes, instruction count, and R1 are in UID0003RC; `000000010837` exit 0/`ok:1`; generated target appears once under `000000010866`. |
| C03 | Predecessor `[0x00571c05,0x00571c10)` is 11 CC bytes and successor `[0x00571cb2,0x00571cc0)` is 14 CC bytes; both stay parent-only. | very strong | boundary reads, neighbor lookups | UID0003RC and UID0001HK | incorporate | applied | Both hashes/dispositions are in UID0003RC and UID0001HK; target `000000010837` and corrected parent `000000010865` each exit 0/`ok:1`; neither pad entered R1. |
| C04 | Binary ABI is one-argument `__thiscall`, `retn 4`, truth-valued AL, with EventHandler facet at complete `+0xa0`. | very strong | disassembly, vtable/class layout | UID0003RC ABI and UID0000CV method evidence | incorporate | applied | Target ABI/facet and class receiver-lowering sections are current; validators `000000010837` and `000000010841` exit 0/`ok:1`; R1/R2 generated once. |
| C05 | Sole target route is secondary vtable cell `0x00624750`, base `0x00624748 + 0x08`; no code caller exists. | very strong | xrefs/find/vtable bytes | UID0003RC, UID00038N, UID00038M | incorporate | applied | Exact route/negatives are in all three destinations; validators `000000010837`, `000000010862`, and `000000010864` exit 0/`ok:1`; generated contains no raw table/address. |
| C06 | Parameter is accepted `Event *`; fields are `m_type +4`, key `+8`, modifiers `+0x10a`, and type 8 is `kEventKeyDown`. | very strong | disassembly/current Event declaration | UID0003RC/R1/R2; Event verify-only | incorporate | applied | Exact offsets/type are in target/class and R1/R2; `000000010837` and `000000010841` exit 0/`ok:1`. UID00004L remained verify-only. |
| C07 | `g_pEventMan->TranslateEventKey(key,modifiers)` runs before type filtering; stale CRT name is rejected. | very strong | target/helper disassembly, 81 xrefs, support docs | UID0003RC/R1; EventMan support verify-only | incorporate | applied | Target ordered behavior/helper history and exact R1 are current; `000000010837` exit 0/`ok:1`; generated body preserves call-before-type order. EventMan pages remained verify-only. |
| C08 | Translated bytes `0x93/0x94` use shared `kPaneKeyPageUp`/`kPaneKeyPageDown`; signed decompiler values are not source semantics. | strong | target compares, executed comparators | UID0003RC/R1 | incorporate | applied | Target source-name/rejected-alternative evidence and R1 are exact; `000000010837` exit 0/`ok:1`; generated names occur in the single target body. |
| C09 | Unsupported type/key and nonzero-modifier recognized keys return false with no base fallback or state write. | very strong | exact branches/exits/callees | UID0003RC behavior/R1 | incorporate | applied | Target matrix/negative evidence and R1 preserve every false path; `000000010837` exit 0/`ok:1`; generated R1 occurs once. |
| C10 | Unmodified PageUp: mode2 -> ShowSpelled, mode1 -> ShowDefault, mode0/other -> no call; every branch returns true. | very strong | `0x571c38-0x571c67`, helper calls | UID0003RC, UID0003R8/R9 bounded caller prose, R1 | incorporate | applied | Target plus UID0003R8 `0x571c5b` and UID0003R9 common `0x571c9d` prose are exact; validators `000000010837`, `000000010849`, `000000010855` exit 0/`ok:1`. |
| C11 | Unmodified PageDown: mode1 -> ShowLegend, mode0 -> ShowSpelled, mode2/other nonzero -> no call; every branch returns true. | very strong | `0x571c68-0x571ca9`, helper calls | UID0003RC, UID0003R9/RA bounded caller prose, R1 | incorporate | applied | Target and UID0003R9/UID0003RA caller links are current; validators `000000010837`, `000000010855`, and `000000010860` exit 0/`ok:1`; R1 preserves both call/no-call paths. |
| C12 | Recognized unmodified PageUp/PageDown is consumed even when no helper runs; helper results are ignored. | very strong | explicit true epilogues/call flow | UID0003RC behavior/R1 | incorporate | applied | Target behavior/negative tables and R1 contain explicit handled returns after optional calls; `000000010837` exit 0/`ok:1`; generated exact body appears once. |
| C13 | `[facet+0xcdc]` is complete `m_viewMode +0xd7c`; each `lea ecx,[facet-0xa0]` is complete-object lowering for view calls. | very strong | disassembly/exact class layout | UID0003RC, UID0000CV, UID0001HK | incorporate | applied | Complete-object lowering is in target/class/parent; validators `000000010837`, `000000010841`, `000000010865` exit 0/`ok:1`; class layout remained exact. |
| C14 | Owner/emitter remain UID0000CV and source route UID0000NL; Event/EventMan/helpers are dependencies only. | very strong | receiver state, vtable, current hierarchy | target metadata, class/file support | already-present | already-present | UID0003RC metadata retained UID0000CV owner/emitter and UID0000CV retained UID0000NL owner/emitter; target/class/file validators `000000010837`, `000000010841`, `000000010844` confirm route. Dependencies were not edited. |
| C15 | Validator-preserving source/path identity is UID0003RC `SelfLookPane2HandleKeyOrTextEvent`; `HandleKeyEvent`, `OnKeyEvent`, and raw name are weaker/historical. | strong | exact slot/current EventHandler/sibling implementations | target rename, all current links, class declaration | incorporate | applied | `000000010837` recorded `path_update` for UID0003RC and four UID-link updates plus validator-owned coverage-link propagation; all nine ordinary destinations use the implemented path, and generated old-title/path count is zero. |
| C16 | Target remains one reconstructable child, blank position, `Nested:0`, with no split/merge/compiler/no-code disposition. | very strong | CFG, routes, coherent body | UID0003RC/UID0001HK | reject-invalid | excluded-with-reason | Split/merge/pad absorption/compiler/no-code alternatives are explicitly rejected in target/parent; metadata stayed true/blank/`Nested:0`; `000000010837` and `000000010865` exit 0/`ok:1`. |
| C17 | R1 is the exact complete formal target body and has replaced the historical target Empty Emitter Marker through authorized validation. | very strong | complete behavior/type closure | UID0003RC formal C++ | incorporate | applied | UID0003RC formal equals R1 byte-for-byte; `000000010837` registered block; waited `000000010866` emits exact R1 once and UID0003RC Empty Emitter Marker count is zero. |
| C18 | R2 updates only the target-specific class declaration while preserving the exact 0xd90 layout and class close before `[[CHILDREN]]`; R3 supplies compiler no-code proof for UID00038M. | strong | current class/vtable docs and generated structure | UID0000CV, UID00038M | incorporate | applied | R2/R3 equal report blocks byte-for-byte; `000000010841` and `000000010864` exit 0/`ok:1`; `000000010866` proves class closure before children and one R3 comment, no family/data marker or raw array. |
| C19 | Applied scores are target `92/94`, parent `90/93`, class `93/94`, file `91/93`, vtable family `90/94`; UID00038N remains `90/94`, and R8/R9/RA remain unchanged. | strong | closed blockers and bounded remaining lexical caps | named metadata/coverage rows | incorporate | applied | Target `000000010837`, parent `000000010865`, class `000000010841`, file `000000010844`, family `000000010864` confirm new scores; UID00038N `000000010862` and view validators preserve accepted scores. |
| C20 | Historical blank/name/blocker/generated-marker wording is labeled pre-direct-pass; the callback records legal final ledger states, per-file validators, generated freshness/uniqueness, changed files, lease releases, and checklist proof. | very strong | current-doc comparison/workflow | all changed docs and this report | historicalize | applied | Changed docs label stale state historically; this ledger/results/files/checklist record exact proof; waited `000000010866` is current generated evidence; B003 lease search is empty and lifecycle remains external. |

## Positive Evidence Summary

- Exact modeled boundary, complete bytes, hash, 58 instructions, 14 blocks, and four explicit callee-cleanup exits anchor one coherent function.
- The sole route is exact secondary-vtable cell `0x00624750`; it is not guessed from address adjacency.
- Current EventHandler declares the exact slot family and current Event supplies every raw field offset.
- EventMan helper body, global load, stack argument order, and 81 key-handler callers close the stale CRT/source-helper blocker.
- Project-wide executed handlers independently normalize `0x93/0x94` to PageUp/PageDown names.
- Exact class layout converts the EventHandler facet read and helper adjustments into ordinary source member access/calls.
- All mode values and callees are current source-ready names under the same class emitter.
- Every true/false path is explicit, including recognized no-transition boundary states.
- No source string, data structure, allocation, packet, mouse field, base fallback, or hidden side effect remains unexplained.

## IDA MCP Facts

### Function identity and exact bytes

- `lookup_funcs(0x00571c10)` -> `sub_571C10`, size `0xa2`; lookup at `0x00571cb1` resolves inside it and `0x00571cb2` is not a function.
- Full target first 16 bytes: `55 8B EC 56 57 8B 7D 08 8B F1 8B 0D 54 A7 67 00`.
- Full target final 16 bytes: `5F B0 01 5E 5D C2 04 00 5F 32 C0 5E 5D C2 04 00`; final instruction is `retn 4` at `0x00571caf-0x00571cb2`.
- SHA256 over exactly 162 bytes is `1CB7A6B49D3183AAFC55DF0F84CA0C247CAE7F444466ABA66B557FF93B3B6ADA`.
- `analyze_function` reports prototype `char __thiscall(_DWORD *this, _BYTE *)`, 162 bytes, 14 basic blocks, cyclomatic complexity 7, no strings, and callees `0x004a8b10`, `0x00570c00`, `0x00570c80`, `0x00570ef0`. Source correction is documented above.

### Exact ordered instruction/branch effects

| Address span | Machine effect | Source effect |
| --- | --- | --- |
| `0x571c10-0x571c1a` | Standard frame, save ESI/EDI, EDI=argument, ESI=entry ECX. | Compiler prologue; retain `event` and EventHandler facet. |
| `0x571c1a-0x571c32` | Load `dword_67A754`, load/push event `+0x10a`, load/push event `+8`, call `0x4a8b10`. | `key = g_pEventMan->TranslateEventKey(event key, event modifiers)` before filtering. |
| `0x571c32-0x571c38` | Compare event `+4` with `8`; mismatch -> false. | Require `kEventKeyDown`. |
| `0x571c38-0x571c45` | Compare AL `0x93`, then modifiers zero; mismatch key continues to PageDown, nonzero modifier -> false. | PageUp branch and its independent zero-modifier gate. |
| `0x571c45-0x571c55` | Read `[facet+0xcdc]`; mode 2 -> common Spelled call, mode 1 -> Default call, otherwise true epilogue. | PageUp Legend->Spelled, Spelled->Default, Default/other consumed no-call. |
| `0x571c55-0x571c68` | Complete-object adjustment, call `0x570c00`, set AL=1, `retn 4`. | `ShowDefaultView(); return true;`. |
| `0x571c68-0x571c75` | Compare AL `0x94`, then modifiers zero; mismatch/nonzero -> false. | PageDown and its independent zero-modifier gate. |
| `0x571c75-0x571c93` | Read mode; mode 1 adjusts/calls `0x570ef0`, sets true; other modes continue. | PageDown Spelled->Legend. |
| `0x571c93-0x571ca2` | Test mode; zero -> common complete-object call `0x570c80`; nonzero -> true epilogue. | PageDown Default->Spelled; Legend/other consumed no-call. PageUp mode2 shares the Spelled call. |
| `0x571ca2-0x571caa` | Set AL=1 and `retn 4`. | All recognized unmodified terminal paths return true. |
| `0x571caa-0x571cb2` | XOR AL, restore registers/frame, `retn 4`. | Unsupported type/key or nonzero modifier returns false. |

### Boundaries and padding

- UID0003RB OnPaint ends at `0x00571c05`; `[0x00571c05,0x00571c10)` is 11 bytes, all `CC`, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- Target starts exactly at `0x00571c10` and ends exactly at `0x00571cb2`.
- `[0x00571cb2,0x00571cc0)` is 14 bytes, all `CC`, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
- UID0003RD begins at `0x00571cc0`, `sub_571CC0`, size `0x43f`.
- Both alignment spans remain parent-only under UID0001HK. Neither changes target range, nesting, source body, or successor/predecessor ownership.

### Vtable and reachability

- `xrefs_to(0x00571c10)` returns exactly one data xref at `0x00624750`; no code xref.
- `find code_ref` count 0, `find data_ref` count 1 at `0x00624750`, and `find immediate` count 0.
- VA dword byte pattern `10 1C 57 00` occurs once at `0x00624750`; RVA dword pattern `10 1C 17 00` occurs zero times.
- Secondary RTTI locator is at `0x00624744`, table base `0x00624748`. Cells begin `0x005732b5` adjustor scalar destructor, `+0x04 -> 0x00571cc0` pointer/mouse handler, `+0x08 -> 0x00571c10` target, `+0x0c -> 0x00544dd0` inherited/default IME, `+0x10 -> 0x00572120` packet handler.
- The target has no ordinary caller, interior xref, duplicate pointer, immediate route, string, or RVA pointer. Virtual-only reachability is complete and expected.

### Helper and call graph

- `0x004a8b10` is ten bytes and five instructions: frame setup, `mov al,[arg_0]`, frame teardown, `retn 8`. It returns the first byte and ignores the second in this build.
- Target loads `g_pEventMan` into ECX before that call and passes exactly two arguments. The machine push order is modifiers, then key, yielding source argument order key, modifiers.
- Helper has 81 code xrefs from project keyboard handlers, including this target at `0x00571c2d`; current EventMan docs reject the stale IDA CRT name.
- Exact target callees are `0x00570c00` ShowDefaultView, `0x00570c80` ShowSpelledView, and `0x00570ef0` ShowLegendView, plus key translation. No packet, drawing, allocation, base-handler, or global-state setter call exists.

## Function / Child Inventory

| Exact range | UID/path | Role | Reconstructable | Owner/emitter | Recommended score/status |
| --- | --- | --- | --- | --- | --- |
| `0x00571c05-0x00571c10` | UID0001HK parent-only | 11-byte predecessor alignment after UID0003RB | false | UID0001HK | retain parent-only |
| `0x00571c10-0x00571cb2` | UID0003RC implemented `by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md` | EventHandler secondary `+0x08` key/text override | true | UID0000CV/UID0000CV | `92/94`, implemented |
| `0x00571cb2-0x00571cc0` | UID0001HK parent-only | 14-byte successor alignment before UID0003RD | false | UID0001HK | retain parent-only |

No child creation is proposed. The validator-preserving rename keeps UID0003RC and all relative nesting. Existing sibling helpers UID0003R8, UID0003R9, and UID0003RA remain independent children and emit their own bodies.

## Direct Xref / Caller Inventory

| Route | Exact evidence | Disposition |
| --- | --- | --- |
| Ordinary code callers | none | Expected for a vtable-only override. |
| Data/vtable caller | `0x00624750 -> 0x00571c10`, secondary base `0x00624748 + 0x08` | Sole live route; establishes EventHandler key/text override. |
| Immediate route | none | No hidden address literal. |
| VA pointer bytes | one at `0x00624750` | Same vtable cell, no duplicate. |
| RVA pointer bytes | none | No alternate registration table. |
| Strings | none | Naming comes from slot/interface/behavior, not text. |
| Callees | `0x004a8b10`, UID0003R8, UID0003R9, UID0003RA | Translation and three view transitions only. |

## Documentation Evidence And IDA Status

- IDA's function boundary and control flow are correct; its target name `sub_571C10`, generic `char` return, `_DWORD *` receiver, byte-array argument, and stale helper name are not source-quality types/names.
- Historical pre-callback UID0003RC contained valid partial PageDown evidence but was incomplete where it treated broader key/event naming as a formal-C++ blocker. Current UID0003RC preserves that evidence and adds the complete body/name/type/negative model.
- UID00004N/UID00004L/UID00004O detail closes the interface, record, and helper blockers at same-or-greater quality; these pages remained verify-only.
- UID0000CV's exact layout closes the complete-object field and view-mode blocker; its target declaration line and method inventory are now synchronized through exact R2.
- UID00038N proves the exact table group and now includes target-specific secondary `+0x08` evidence without changing its score or R4 compiler no-code formal.
- Generated command `000000010815` historically showed UID00038M as an Empty Emitter Marker despite its compiler-generated no-manual-array proof. Current command `000000010866` emits R3's comment-only no-code marker once, not a raw table, and the UID00038M Empty Emitter Marker count is zero.
- No current document contradicts the exact target behavior. Historical generic titles and blank-emitter statements remain source-quality history, not competing binary evidence.

## Ranked Ownership Analysis

1. **UID0000CV SelfLookPane2:** exact receiver fields, complete-object adjustments, class-local view helpers, vtable group, and source route. This is the direct canonical owner and emitter.
2. **UID0000NL SelfLookPane source file:** established translation-unit route for SelfLookPane2 class declaration and child definitions. It is the direct file owner, not the method emitter UID.
3. **UID00004N EventHandler:** supplies the inherited virtual interface and secondary facet only. It does not own the derived override body.
4. **UID00004O EventMan / UID00014C:** own or document key translation infrastructure only. The target reads their global/helper but mutates no EventMan state.
5. **UID0003R8/UID0003R9/UID0003RA:** called SelfLookPane2 methods. They own transition bodies, not dispatch ownership.
6. **Pane/PanelPane/Event/LegendPane/SpelledPane:** type/layout/dependency support only.

Rejected owners are UserLookPane, generic EventDispatcher, Event.cpp, LegendPane, SpelledPane, and CRT/`std::ctype`. None receives the target receiver, owns the secondary vtable cell, or contains the full dispatch behavior.

## Source Placement

- Keep source route [UID:0000NL] `NexusTK/ui/panels/SelfLookPane.cpp`.
- Emit the definition through UID0000CV after the complete SelfLookPane2 class declaration and alongside exact child definitions in address/source order.
- Keep Event/EventHandler/EventMan declarations in shared UI-core infrastructure; SelfLookPane.cpp consumes them through normal headers.
- Keep UID00038M/UID00038N as compiler-source-cause documentation. Do not emit manual RTTI/vtable arrays.
- Original physical filename is not embedded in symbols and remains an inference cap. The established class/file ownership is much stronger than any alternative source route.

## Range / Split / Padding / Reclassification Analysis

- Preserve target half-open range exactly `[0x00571c10,0x00571cb2)` and size `0xa2`.
- Preserve UID0003RB predecessor endpoint at `0x00571c05`; do not extend it through the 11-byte alignment.
- Preserve UID0003RD successor start at `0x00571cc0`; do not extend UID0003RC through the 14-byte alignment.
- Add both pad rows to UID0001HK as parent-only alignment. They are not source children and do not affect relative `Nested:0` for UID0003RC or its siblings.
- Apply a UID-preserving filename/title reclassification only: `SelfLookPane2HandleKeyEvent` -> `SelfLookPane2HandleKeyOrTextEvent`.
- No split, merge, duplicate emitter, helper extraction, compiler-only reclassification, or ownership move is valid.

## Negative Evidence Summary

- No direct code caller, interior xref, immediate route, RVA pointer, second VA pointer, string, or duplicate target body.
- No event mutation, target-local state write, heap action, packet read/write, mouse coordinate use, drawing, timer work, exception source operation, or global mutation.
- No base EventHandler fallback call and no inherited-handler chaining.
- No helper call for PageUp mode 0/other or PageDown mode 2/other nonzero, yet those recognized unmodified keys still return true.
- No recognized key is accepted when modifiers are nonzero; the full byte is compared with zero, not masked.
- No call result is tested or returned; all three view helpers remain `void` source methods.
- No Win32 `VK_PRIOR`/`VK_NEXT` values, CRT locale semantics, or signed key-domain meaning.
- No evidence for `PanelKeyEvent`, a const parameter, `int` source return, `OnKeyEvent` lexical ownership, or private static helper form.
- No target-owned vtable/RTTI array, adjustor method, or explicit `this-0xa0` source expression.
- No source split or padding absorption.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing/IDA function name: `SelfLookPane2__HandleKeyOrTextEvent` for `sub_571C10`.
- Proposed prototype annotation: `bool __thiscall SelfLookPane2::HandleKeyOrTextEvent(Event *event)` while documenting that binary ECX is the EventHandler secondary facet at complete `+0xa0`.
- Proposed argument name/type: `event`, `Event *`.
- Proposed local: `translatedKey`, `unsigned char`.
- Proposed comments: secondary vtable `0x00624750 = SelfLookPane2::HandleKeyOrTextEvent`; `[facet+0xcdc] = complete m_viewMode +0xd7c`; `lea [facet-0xa0]` restores complete receiver for view calls.
- Preserve helper address `0x004a8b10` as EventMan translation context; do not accept IDA's `std::ctype<char>::do_narrow` name as original source.
- No IDA DB edits are requested or permitted in this assignment. These are documentation recommendations only.

## First-Draft C++ Recommendation

Eligible: yes. R1 is the exact target insertion. R2 is the complete destination class declaration with only the target-specific interface correction. R3 resolves the source-local vtable-family no-code marker. R4 preserves the already-present exact vtable-memory no-code marker. R0 preserves the non-emitting parent.

### R0 - UID0001HK non-emitting parent, exact managed state

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R1 - UID0003RC target

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool SelfLookPane2::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char translatedKey =
        g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

    if (event->m_type != kEventKeyDown) {
        return false;
    }

    if (translatedKey == kPaneKeyPageUp) {
        if (event->m_payload.m_key.m_modifiers != 0) {
            return false;
        }

        if (m_viewMode == ViewMode_Legend) {
            ShowSpelledView();
        } else if (m_viewMode == ViewMode_Spelled) {
            ShowDefaultView();
        }

        return true;
    }

    if (translatedKey == kPaneKeyPageDown) {
        if (event->m_payload.m_key.m_modifiers != 0) {
            return false;
        }

        if (m_viewMode == ViewMode_Spelled) {
            ShowLegendView();
        } else if (m_viewMode == ViewMode_Default) {
            ShowSpelledView();
        }

        return true;
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R2 - UID0000CV complete class declaration

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfLookPane2 : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_Default = 0,
        ViewMode_Spelled = 1,
        ViewMode_Legend = 2
    };

    SelfLookPane2();
    virtual ~SelfLookPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual bool OnPaint();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleEvent(const PanelMouseEvent *event);
    virtual bool OnPacketEvent(const PanelPacketEvent *event);

    void ShowDefaultView();
    void ShowSpelledView();
    void ShowProfileView();
    void ShowLegendView();
    void DrawStatText();
    void GetButtonRect(int buttonId, RectBounds *bounds) const;
    unsigned short HitTestButton(int x, int y) const;

private:
    unsigned char *m_statDigitFrames;
    SpelledPane *m_spelledPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    LivingSpriteConfig m_spriteConfig;

    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;

    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_statusLineA[256];
    wchar_t m_statusLineB[128];
    wchar_t m_statusName[128];
    unsigned int m_displayValueA;
    unsigned int m_displayValueB;
    unsigned char m_activationState0;
    unsigned char m_activationState1;
    unsigned char m_activationState2;
    unsigned int m_activationValue;
    unsigned int m_lastToggleTick;
    unsigned int m_toggleRepeatDelay;
    unsigned char m_equipmentToggleState;
    unsigned char m_lookToggleState;
    unsigned char m_statsToggleState;
    wchar_t m_auxiliaryText[256];
    wchar_t m_spelledSourceText[256];
    int m_viewMode;
    int m_profileState;
    int m_reservedViewState;
    int m_buttonFrameA;
    int m_buttonFrameB;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R3 - UID00038M source-local vtable family no-code marker

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated SelfLookPane and SelfLookPane2 RTTI and vtable data; no manual source arrays.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R4 - UID00038N exact vtable-memory no-code marker, already present

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated SelfLookPane2 RTTI and vtable data; no manual source array.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

R1 preserves exact behavior because the translation call and every comparison/branch occur in machine order; each mode branch maps directly to the observed callee or consumed no-call path. R2 changes no layout field and keeps `[[CHILDREN]]` after the full class-closing `};`. R3/R4 emit no raw compiler data.

## Final Recommendation

C01-C20 and R0-R4 were accepted and implemented. The UID-preserving rename, target source body and score, exact class declaration correction, bounded parent/file/view-link/vtable synchronization, and vtable-family no-code marker are applied. Exact external manual coverage text remains retained below without B003 manual coverage edits. All unrelated SelfLookPane2 children, raw helper caveats, class layout, scores/routes not explicitly changed, and compiler/source exclusions are preserved.

## Recommended Target Doc Changes

For UID0003RC:

- Validator-preserving rename is complete at `by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md`; UID0003RC is retained.
- `COMPLETION:92`, `CONFIDENCE:94` are applied; owner/emitter UID0000CV, reconstructable true, blank optional position, `Nested:0`, and exact range are preserved.
- Historical blank formal C++ is replaced with R1 exactly.
- Exact Item Summary: `Exact EventHandler +0x08 SelfLookPane2 HandleKeyOrTextEvent override with EventMan translation before type filtering, unmodified PageUp/PageDown view transitions, consumed recognized boundary/no-call paths, bool AL/retn4 ABI, complete formal C++, and parent-only adjacent padding.`
- Exact range/size/hash/bytes, both parent-only pads, ABI/facet explanation, vtable route, instruction/transition matrix, helper contracts, positive/negative reachability, source name/type/access rationale, rejected alternatives, score rationale, and historicalized pre-direct-pass blocker/generated-marker wording are applied.
- Existing UID0003RA PageDown facts remain at full detail and the exact PageUp complement is added rather than replacing prior evidence with a summary.

## Recommended Support Doc Changes

The accepted bounded support changes below are implemented exactly.

| Destination | Exact bounded implemented change | Score/metadata disposition |
| --- | --- | --- |
| `by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md` UID0001HK | Changed inventory link/title to renamed UID0003RC; recorded target hash/source-ready role, both 11/14-byte parent-only pads, exact PageUp/PageDown matrix, facet lowering, and child-only emission. Preserved every sibling/raw/compiler/table fact. | `89/92 -> 90/93`; owner UID0000CV, non-emitting, blank formal, `Nested:0` unchanged. |
| `by-class/SelfLookPane2.md` UID0000CV | Applied R2 exactly; renamed method row; added secondary `+0x08`, Event fields/helper/key constants, transition matrix, bool/facet lowering, and target source-ready evidence. Preserved exact 0xd90 layout and all unrelated method/raw history. | `92/93 -> 93/94`; owner/emitter/file route, position, and all layout fields unchanged. |
| `by-file/SelfLookPane.md` UID0000NL | Added source-ready UID0003RC in SelfLookPane2 inventory/source order with exact signature, hash, route, event/helper/key/mode behavior, no-split and compiler exclusions; historicalized target Empty Emitter Marker. | `90/92 -> 91/93`; path/FILE ownership unchanged. |
| `by-memory/0x00570c00-0x00570c80.SelfLookPane2ShowDefaultView.md` UID0003R8 | Updated renamed target link and exact PageUp mode-1 caller at `0x571c5b`; preserved helper body blocker and all other callers. | Kept `86/89`, owner/emitter/formal/range/nesting. |
| `by-memory/0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView.md` UID0003R9 | Updated renamed target link; recorded PageUp mode2 and PageDown mode0 calls through common site `0x571c9d`; preserved other callers/body state. | Kept `86/89`, owner/emitter/formal/range/nesting. |
| `by-memory/0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView.md` UID0003RA | Updated renamed target link only where the path/title was referenced; retained exact PageDown mode1 call, all target body evidence, score/formal, and executed history. | Kept `91/94` and all metadata/formal. |
| `by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md` UID00038N | Added exact secondary cell `0x00624750`, base+8, target UID/path/signature, sole-route/receiver evidence, and no-manual-table source cause; preserved R4. | Kept `90/94`, owner/emitter UID00038M, blank position, `Nested:0`. |
| `by-type/by-vtable/SelfLookPaneFamilyVtables.md` UID00038M | Added exact SelfLookPane2 secondary key/text slot row and source declaration cause; inserted R3 so compiler no-code state no longer appears as an unresolved generated marker. Preserved both family ranges/stores and broad UID0001Y0 relationship. | `89/93 -> 90/94`; owner/emitter UID0000NL, source route, reconstructable state, position unchanged. |

Verify-only dependencies remained unchanged because no contradiction was found: UID00004L Event, UID00004N EventHandler, UID00004O EventMan, UID00014C, UID00028L, UID0003QZ, UID0003RD, Pane, PanelPane, and key tables/constants. Generated output was inspected read-only after the authorized waited refresh.

## Score And Metadata Recommendation

| Page | Historical pre-callback | Implemented | Rationale |
| --- | ---: | ---: | --- |
| UID0003RC target | `85/89` | `92/94` | Exact full body, signature, slot, bytes/hash, all branches, helper/type/name closure, formal C++, and negative routes; lexical symbols remain inferred. |
| UID0001HK parent | `89/92` | `90/93` | Child inventory gained a source-ready exact target and both missing parent-only pads; other children still cap aggregate completion. |
| UID0000CV class | `92/93` | `93/94` | One stale virtual declaration and method role become exact without changing the already exact layout; remaining raw/profile/name caveats cap it. |
| UID0000NL file | `90/92` | `91/93` | Adds one complete source method and exact event/vtable route; physical filename and broad raw helper names remain caps. |
| UID00038M vtable family | `89/93` | `90/94` | Exact secondary slot and explicit compiler no-code formal resolve a target-related table/marker gap; original inherited slot names remain partly inferred. |
| UID00038N vtable data | `90/94` | `90/94` unchanged | Exact target slot improves prose but existing range/store/compiler proof already supports the score ceiling. |
| UID0003R8/UID0003R9/UID0003RA | accepted current scores | unchanged | Only target link/caller prose changed; their independent body readiness determines their scores. |

Target owner/emitter/reconstructable/position/nesting remain internally coherent. No new UID, child, owner, source file, or route was required.

## Open Questions With Attempted Resolution

- **Exact original method spelling:** checked current EventHandler, vtable slot, MainMenu, ScrollableControlPane, TextEditControlPane, UserLook, Parcel, and historical EventHandler reports. Best current source-facing spelling is `HandleKeyOrTextEvent`; no PDB exists. This is a confidence cap, not a blocker.
- **Exact EventMan helper spelling:** checked ten-byte body, 81 callers, EventMan class/helper docs, and key-handler source. Use `TranslateEventKey`; `TranslateEventKeyByte` remains a documented lexical alternative. Behavior and call shape are closed.
- **Exact PageUp/PageDown enum spelling:** checked executed FittingRoom/inventory/UserLook/pane-key work and raw values. Use project-wide `kPaneKeyPageUp`/`kPaneKeyPageDown`; symbols are inferred but alternatives are weaker.
- **Modifier meaning:** checked full target and Event producer/layout. The target tests the entire modifier byte for zero and does not mask individual bits; call it `m_modifiers` per current Event.
- **Return type:** checked all exits and current base declaration. `bool` is exact; IDA `char` is ABI typing, not a competing source type.
- **Access control:** checked base and current class declarations. Keep the override public. Binary cannot prove lexical access, but this does not affect layout or behavior.
- **Physical source filename:** checked class/file/vtable routes and historical split reports. `NexusTK/ui/panels/SelfLookPane.cpp` is the established best route; lack of an embedded filename caps file confidence only.
- **Remaining unresolved implementation blockers:** none. Only original lexical-symbol uncertainty remains, and all affected names have evidence-backed best current choices.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The manual rows were read in `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md`. Validator command `000000010837` propagated the UID-preserving target link into the by-memory row as a validator-owned rename side effect, but the supervisor-owned scores/descriptions remain outside B003's manual edit scope. Exact external replacement text follows and is retained without B003 manual coverage edits.

### `by-memory/-coverage-report.md`

Replace the UID0001HK row in place:

```markdown
    - [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md) 0x0056fe80-0x005729c3 | non-emitting class-method split index | SelfLookPane2 : not_reconstructable : 90% : very-strong : Exact SelfLookPane2 constructor/destructor/OnActivate/view/paint/input/packet/stat/button/raw-helper inventory with complete 0xd90 layout, retained raw ShowProfileView, source-ready ShowLegendView and HandleKeyOrTextEvent children, all internal padding including 11-byte pre-key, 14-byte post-key, and 13-byte post-legend alignment, compiler exclusions, and exact child-only source emission through SelfLookPane2.
```

Replace the UID0003RC row in place under UID0001HK:

```markdown
        - [UID:0003RC][0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent](by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md) 0x00571c10-0x00571cb2 | virtual method | SelfLookPane2HandleKeyOrTextEvent : reconstructable : 92% : very-strong : Exact 162-byte/SHA256-anchored EventHandler +0x08 override with EventMan translation before type filtering, unmodified PageUp/PageDown Default/Spelled/Legend transitions, consumed recognized boundary/no-call paths, bool AL/retn4 ABI, complete formal C++, and parent-only adjacent padding.
```

Replace the UID00038N row in place under the SelfLookPane family vtable group:

```markdown
            - [UID:00038N][0x006246f4-0x00624780.SelfLookPane2VtableData](by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md) 0x006246f4-0x00624780 | vtable-data | SelfLookPane2VtableData : reconstructable : 90% : very-strong : Exact SelfLookPane2 RTTI/COL and primary/secondary/tertiary vtable-data interval with constructor/cleanup/scalar-destructor stores, primary +0x48 UID0003QZ OnActivate, secondary +0x08 UID0003RC HandleKeyOrTextEvent, CollectionPane2/LineIterator boundaries, compiler-generated no-manual-array disposition, and source-local UID00038M route.
```

### `by-class/-coverage-report.md`

Replace UID0000CV row:

```markdown
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md) : reconstructable : 93% : very-strong : Complete PanelPane-derived 0xd90 SelfLookPane2 declaration with exact natural layout, primary +0x48 OnActivate, EventHandler +0x08 HandleKeyOrTextEvent, source-ready ShowLegendView, resource/Spelled/Profile/Legend pointers, LivingSpriteConfig/equipment/status/toggle/text/view fields, exact method/raw-helper inventory, class closure before child definitions, and descriptive-name confidence caps.
```

### `by-file/-coverage-report.md`

Replace UID0000NL row:

```markdown
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) : reconstructable : 91% : very-strong : NexusTK/ui/panels/SelfLookPane.cpp source grouping with complete SelfLookPane/SelfLookPane2 split inventories, exact UID0003QZ OnActivate, UID0003RA ShowLegendView, and UID0003RC HandleKeyOrTextEvent source, retained raw UID0004NA ShowProfileView, packet/status/equipment/view behavior, class/vtable/compiler distinctions, helper/destructor islands, shared child-pane ownership, and original filename/name confidence caps.
```

### `by-type/by-vtable/-coverage-report.md`

Replace UID00038M row:

```markdown
- [UID:00038M][SelfLookPaneFamilyVtables](by-type/by-vtable/SelfLookPaneFamilyVtables.md) : reconstructable : 90% : very-strong : Source-local SelfLookPane/SelfLookPane2 vtable layout with exact table ranges/stores, SelfLookPane2 primary +0x48 UID0003QZ OnActivate and secondary +0x08 UID0003RC HandleKeyOrTextEvent cells, compiler-generated no-manual-array formal disposition, and unchanged SelfLookPane.cpp owner/emitter route.
```

No manual row exists for UID0003R8 or UID0003R9 in the current by-memory coverage inventory, and their scores/titles do not change. UID0003RA's current row does not contain the target path/title and remains accurate. No manual generated/tracker text is proposed.

## Follow-Up Actions

- The bounded implementation callback is complete; no B003 implementation item remains.
- Report validation/execution/count/path/move/archive state and any manual coverage application are external supervisor/validator-owned state and are neither asserted nor directed by this artifact.
- No separate A-agent or future B-agent research is required for UID0003RC. UID0003R8/UID0003R9 full-body work remains independent queue work and was not folded into this target callback.

## Confidence

- Binary boundary/behavior/ABI/vtable confidence: `99%`.
- Owner/emitter/source route confidence: `97%`.
- Source signature and current interface name confidence: `94%`.
- Exact original lexical names/header/physical filename confidence: `88%`.
- Recommended target metadata: completion `92`, confidence `94`.
- No behavior, type, helper, field, range, ownership, or formal-C++ blocker remains unresolved.

## Validator Results

- Historical report-only validation state: none, as required before Gate 1. Supervisor accepted exact report SHA `554741849529F50E519ACDBF491AFD3A2B499703E09F1F6C718F530C7D8AE016` for this callback.
- Pre-edit `validator.py --help` schema read was command `000000010836`; it did not apply, scan, queue, refresh, or mutate documentation.

| Command ID / timestamp | Scoped destination | Exit / ok | Exact result and side effects |
| --- | --- | --- | --- |
| `000000010837` / `2026-07-14T06:11:25-04:00` | renamed UID0003RC `by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md` | `0` / `ok:1` | Registered UID-preserving `path_update`, target `92/94`, blank-to-block formal, five source-path reference updates, four UID-link updates, and deferred generation. Validator-owned rename propagation updated the target link in `by-memory/-coverage-report.md`; B003 made no manual coverage edit. |
| `000000010838` / `2026-07-14T06:12:46-04:00` | UID0001HK parent initial application | `0` / `ok:1` | Applied `90/93` and exhaustive parent inventory/padding/behavior; generation deferred. Later exact Event-offset/key-value prose correction is independently covered by `000000010865`. |
| `000000010841` / `2026-07-14T06:14:00-04:00` | UID0000CV class | `0` / `ok:1` | Applied `93/94`, R2 registry hash, target reference, exact layout/method evidence; generation deferred. |
| `000000010844` / `2026-07-14T06:16:20-04:00` | UID0000NL file | `0` / `ok:1` | Applied `91/93`, target source inventory/reference/history; generation deferred. |
| `000000010849` / `2026-07-14T06:16:52-04:00` | UID0003R8 ShowDefaultView | `0` / `ok:1` | Registered the previously absent UID mapping/metadata, preserved `86/89`, and validated renamed link plus exact Page Up mode-1 caller; generation deferred. |
| `000000010855` / `2026-07-14T06:17:44-04:00` | UID0003R9 ShowSpelledView | `0` / `ok:1` | Validated renamed link, common `0x571c9d` Page Up mode-2/Page Down mode-0 callers, preserved `86/89`; generation deferred. |
| `000000010860` / `2026-07-14T06:18:11-04:00` | UID0003RA ShowLegendView | `0` / `ok:1` | Validated validator-propagated renamed target links and existing exact Page Down mode-1 caller; preserved `91/94`, R1-equivalent independent formal, route/range/history; generation deferred. |
| `000000010862` / `2026-07-14T06:19:08-04:00` | UID00038N vtable memory | `0` / `ok:1` | Validated exact secondary `+0x08` route/source cause and preserved `90/94` plus R4; generation deferred. |
| `000000010864` / `2026-07-14T06:20:55-04:00` | UID00038M vtable family | `0` / `ok:1` | Applied `90/94`, target reference, blank-to-block R3 registry state; generation deferred. |
| `000000010865` / `2026-07-14T06:21:34-04:00` | UID0001HK parent final correction | `0` / `ok:1` | Validated exact Event `+4/+8/+0x10a`, type `8`, keys `0x93/0x94`, all accepted parent detail, and unchanged `90/93`; generation deferred. |
| `000000010866` / `2026-07-14T06:22:06-04:00` | UID0000NL final `--wait-generated` | `0` / `ok:1` | Completed generated refresh; `autogen_registry_rebuild:1`, `generated_metadata_refresh:281`, and refreshed C++/generated metadata are validator-owned side effects. Header records command `000000010866`, timestamp `2026-07-14T06:22:06-04:00`, and `foreground-generated-refresh`. |

Generated `auto-generated/NexusTK/ui/panels/SelfLookPane.cpp` readback after `000000010866`:

- `class SelfLookPane2 : public PanelPane` count `1`; exact R2 declaration count `1`; class-closing `};` occurs before the first qualified SelfLookPane2 child definition and before UID0003RC.
- Exact R1 body is present once; UID0003RC header/path is present once; target definition count `1`; old `SelfLookPane2HandleKeyEvent` / `HandleKeyEvent(const PanelKeyEvent *)` count `0`.
- Existing emitted SelfLookPane2 definitions checked at this boundary occur once each: `OnActivate`, `ShowProfileView`, `ShowLegendView`, and `HandleKeyOrTextEvent`.
- Exact R3 comment is present once. UID0003RC, UID00038M, and UID00038N Empty Emitter Marker counts are each `0`; R4 remains exact in UID00038N and does not cause a duplicate generated table.
- Raw vtable addresses `0x006246f8`, `0x00624748`, `0x00624750`, `0x00624778` occur `0` times; manual vtable-array pattern count is `0`; no duplicate/wrong-range target emitter exists.
- R0-R4 destination blocks were compared against the accepted report before refresh: all five are byte-for-byte exact. Generated R1 and R3 occur exactly once; R2's complete class text before `[[CHILDREN]]` occurs exactly once.

## Changed Files

- UID-preserving rename: `by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyEvent.md` -> `by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md` (UID0003RC).
- Changed ordinary support: `by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md`, `by-class/SelfLookPane2.md`, `by-file/SelfLookPane.md`, `by-memory/0x00570c00-0x00570c80.SelfLookPane2ShowDefaultView.md`, `by-memory/0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView.md`, `by-memory/0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView.md`, `by-memory/0x006246f4-0x00624780.SelfLookPane2VtableData.md`, and `by-type/by-vtable/SelfLookPaneFamilyVtables.md`.
- Updated callback artifact: `tools/leaser/Agents/Agent-B003/research/0003RC-SelfLookPane2HandleKeyEvent-source-quality.md`.
- Validator-owned side effects only: UID0003RC path propagation changed its link in `by-memory/-coverage-report.md`; final waited generation refreshed `auto-generated/**` and generated metadata. B003 did not manually edit those files.
- Verify-only ordinary pages were unchanged: UID00004L, UID00004N, UID00004O, UID00014C, UID00028L, UID0003QZ, UID0003RD, Pane, PanelPane, and key constants/tables.
- No manual coverage description/score, tracker, audit, supervisor, validator-state, IDA, lifecycle, or archive file was manually edited. No report execution/probe/count/move/archive/lifecycle command was run.
- Every ordinary destination was leased only while rereading/editing/validating and released before the next lease. Final `tools/leaser/Agents/current_leases.md` search contains no B003 entry.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact pre-callback SHA `554741849529F50E519ACDBF491AFD3A2B499703E09F1F6C718F530C7D8AE016` before implementation.
- [x] Target/support destinations were exhaustively enumerated: UID0003RC renamed target; UID0001HK parent; UID0000CV class; UID0000NL file; UID0003R8, UID0003R9, UID0003RA link/caller support; UID00038N vtable memory; UID00038M vtable family.
- [x] Exact bytes/hash/range, ABI/facet, 58-instruction CFG, vtable route, helper, fields/constants, transition matrix, padding, generated/manual coverage, and historical roots were recorded.
- [x] C01-C20 were atomic with exact destinations before callback and now have legal final actions/states plus implementation proof.
- [x] Applied scores are target `92/94`, parent `90/93`, class `93/94`, file `91/93`, vtable family `90/94`; UID00038N and view helper scores remain unchanged.
- [x] Signature, bool return, Event type/fields, helper/global, key constants, modifier semantics, view modes, receiver adjustment, source name, access, route, and formal-body blockers were researched to resolution.
- [x] UID0000CV target owner/emitter and reconstructable true state were preserved; no unsupported owner/emitter change was made.
- [x] UID0003RC was validator-preserving renamed without new child/split; both padding spans remain parent-only.
- [x] R1 target, R2 complete class, and R3 vtable-family no-code marker are exact; R0/R4 are preserved byte-for-byte.
- [x] Generic HandleKeyEvent/PanelKeyEvent name, partial-body blocker, stale CRT helper name, signed-key decompile, pre-callback Empty Emitter Marker, and old split-report score are preserved as explicit history.
- [x] Rejected alternatives remain explicit: no UserLook/EventMan/CRT ownership, base fallback, state write, split, pad absorption, manual vtable array, const/raw event type, int return, or Win32 keys.
- [x] Exact supervisor-owned manual coverage text is retained for UID0001HK, UID0003RC, UID00038N, UID0000CV, UID0000NL, and UID00038M; B003 made no manual coverage edit.
- [x] Event, EventHandler, EventMan, g_pEventMan, UID0003QZ, UID0003RD, Pane/PanelPane, and key tables/constants were verified without contradiction and left unchanged; generated output was read-only.
- [x] One short ordinary-file lease was held at a time, each page was reread, edited/validated, and released before the next lease; no B003 lease remains.
- [x] Every changed/renamed ordinary page has scoped validator command/timestamp/exit/ok/side-effect proof above.
- [x] Final authorized waited refresh and exact `SelfLookPane.cpp` structure/uniqueness/no-empty-marker/no-raw-vtable checks are recorded.
- [x] Finalized/Current State, C01-C20, Validator Results, Changed Files, and this checklist reflect durable implementation-complete truth.
- [x] No generated/manual coverage/tracker/audit/supervisor/validator/lifecycle/IDA manual edit and no report execute/probe/count/move/archive/lifecycle command occurred.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation at exact Gate-1 SHA above.
- [x] UID0003RC validator-preserving rename completed and current ordinary links synchronized; validator-owned coverage link propagation is recorded separately.
- [x] R1 inserted exactly with target `92/94` and all metadata/range/nesting preserved.
- [x] UID0001HK parent score/padding/inventory/behavior/history changes applied at report-level detail, including corrected Event offsets/type/key values.
- [x] UID0000CV R2, score, method/vtable/ABI/behavior evidence applied with exact `0xd90` layout preserved and class closed before children.
- [x] UID0000NL source inventory/score/history/compiler distinction applied.
- [x] UID0003R8/UID0003R9/UID0003RA bounded link/caller updates applied with scores/formals/routes/ranges/history preserved.
- [x] UID00038N target slot evidence applied with R4 and `90/94` preserved.
- [x] UID00038M R3/slot evidence/`90/94` applied without manual arrays.
- [x] Verify-only dependencies were reread/checked and no contradiction required an edit.
- [x] Every changed ordinary page was scoped-validated under a short serial lease; command proof and releases are recorded.
- [x] Waited command `000000010866` proves exact R1/R2/R3 structure, uniqueness, freshness, no target/vtable-family/data Empty Emitter Marker, and no duplicate/wrong-range/manual table.
- [x] Exact external manual coverage rows remain retained without B003 manual coverage editing.
- [x] C01-C20 ledger rows use legal final states with exact destination/validator/generated proof.
- [x] Validator Results, Changed Files, Finalized/Current State, and checklist are current and archive-neutral.
- [x] No B003 lease remains and no forbidden manual edit, implementation scope expansion, IDA mutation, report execution, or lifecycle command occurred.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000010908","destination_path":"executed-b-agent-research/B003/0003RC-SelfLookPane2HandleKeyEvent-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003RC-SelfLookPane2HandleKeyEvent-source-quality.md","timestamp":"2026-07-14T06:46:31-04:00","uid":"0003RC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
