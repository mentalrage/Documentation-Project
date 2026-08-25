** TARGET-REPORT-UID:00028L **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00028L g_pEventMan Source-Quality Report

## Finalized Report / Current Recommendation

Gate 1 passed at SHA256 `DBE938D100184045749B48E412E56E5226D03C91BA36CB2DC4457D0E6C9C20F9`; target-only implementation callback was applied on 2026-07-05.

Accepted implementation scope was target-only. The optional EventMan support consistency edits were explicitly excluded from this callback and remain future work unless separately assigned.

- Target: [UID:00028L] `by-memory/0x0067a754-0x0067a758.g_pEventMan.md`.
- Keep range `0x0067a754-0x0067a758`.
- Keep `CANONICAL_OWNER:0000J6`, `EMITTER_UIDS:0000J6`, `RECONSTRUCTABLE:TRUE`, and blank emitter position.
- `COMPLETION` is now `88`.
- `CONFIDENCE` is now `92`.
- The formal C++ block now contains the single source-level global definition:

```cpp
EventMan *g_pEventMan = NULL;
```

The source emission blocker is resolved because current live IDA MCP confirms the exact four-byte storage, zero initializer, 210 direct xrefs, all lifecycle writes/clears, clean neighbor boundaries, and consumer roles. Remaining uncertainty is limited to exact original spelling/linkage style and the broader `Event.cpp` versus possible future `EventMan.cpp` source split; neither blocks this first-draft definition.

## Supporting Research

This Gate 1 repair preserves the existing UID00028L research and makes the checked source set explicit before the target section.

| Source checked | Why it mattered |
| --- | --- |
| Current target doc `by-memory/0x0067a754-0x0067a758.g_pEventMan.md` | Established the pre-callback `85/90` target state, owner/emitter `0000J6`, reconstructable flag, exact range, blank C++ block, and already-recorded lifecycle/consumer facts; callback verification now records the post-callback `88/92` state below. |
| Current support docs `by-file/Event.md`, `by-class/EventMan.md`, EventMan helper pages, activation/deactivation pages, consumer pages, key-map table page, vtable page, and neighboring singleton pages | Confirmed the Event/Event.cpp source route, EventMan semantic class context, current helper names, consumer-only references, key-map constructor context, vtable linkage, and clean neighboring singleton boundaries. |
| Generated files and tracker rows: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/ui/core/Event.cpp` | Confirmed the pre-callback generated blocker: UID00028L was not-covered/reconstructable at `85/90`, routed through UID0000J6 to `Event.cpp`, and remained an empty emitter marker. Post-callback generated proof is recorded under `Current Target State` and `Validator Results`. |
| Executed B-agent reports B008 UID00014C/UID0002GK, B001 UID0002GJ/UID00027C, B006 UID0004B6, and B011 UID0002KD | Supplied accepted naming and incorporation precedent for EventMan lifecycle/helpers, activation/deactivation consumers, key translation tables, and downstream EventMan use without replacing current MCP verification. |
| Live IDA MCP session `supervisor_recovery_20260705` | Provided implementation-verifiable proof: bytes and global value at `0x0067a754`, 210 direct xrefs, lifecycle writes/clears, neighbor xref separation, helper decompilation, consumer references, and non-function data classification. |

## Target

- UID: `00028L`
- Target path: `by-memory/0x0067a754-0x0067a758.g_pEventMan.md`
- Assigned report path: `tools/leaser/Agents/Agent-B011/research/00028L-g_pEventMan-source-quality.md`
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Current tracker row after scoped validation: `88/92`, combined `90.0`, reconstructable `true`, reports `0`

## Current Target State

Current target metadata after the callback:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `92` |
| `CANONICAL_OWNER` | `0000J6` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000J6` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| `RECONSTRUCTION_CPP` | `EventMan *g_pEventMan = NULL;` |

Before callback, the target was `85/90` with a blank C++ block. The callback resolved that source-emission gap while keeping the address range, owner/emitter route, and reconstructable state unchanged.

Generated state checked read-only after validator command `000000007322`:

| File | Current fact |
| --- | --- |
| `auto-generated/-ag-research-tracker.md` | UID00028L row is `88/92`, combined `90.0`, reconstructable `true`, reports `0`; header `validator-command-id: 000000007322`, `validator-refreshed-at: 2026-07-05T18:54:51-04:00`. |
| `auto-generated/-ag-memory-coverage.md` | UID00028L is `coded`, owner/emitter `0000J6`, route `auto-generated/NexusTK/ui/core/Event.cpp`; header matches validator command `000000007322`. |
| `auto-generated/-ag-coverage-report-by-memory.md` | UID00028L now shows `emits_code:true`, `88%`, updated `2026-07-05 18:54:52`, with the target item summary; header matches validator command `000000007322`. |
| `auto-generated/NexusTK/ui/core/Event.cpp` | UID00028L now appears as `Completion:88 | Confidence:92` followed by `EventMan *g_pEventMan = NULL;`; it is no longer an Empty Emitter Marker. Header `validator-command-id: 000000007322`, `validator-refreshed-at: 2026-07-05T18:54:51-04:00`. |

## Heuristic / Inference Reanalysis And Validation

The current source-placement hypothesis is stable: `g_pEventMan` is a file-scope Event/EventMan singleton definition emitted through [UID:0000J6] `Event.cpp`, not a class-static member, not an adjacent data alias, and not a consumer-owned field.

The direct class meaning is `EventMan *`, but the source declaration is global storage. That is why the current target owner/emitter route through [UID:0000J6] remains better than moving the memory page to [UID:00004O] `EventMan`. [UID:00004O] owns methods and vtable/class behavior; [UID:0000J6] is the current containing source file and global-definition emitter.

No `by-global/g_pEventMan.md` exists. Unlike neighboring singleton pages that are covered by a separate by-global definition page, this exact by-memory page is the natural single source-definition site. Current generated consumers already use `extern EventMan *g_pEventMan` in modules such as `InputMan.cpp` and `MiscWorkThread.cpp`, which also argues against `static` linkage for the implementation draft.

## Evidence Standards Used

- Live IDA MCP was required and available.
- Current MCP database/session: `supervisor_recovery_20260705`.
- MCP health: `status: ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Evidence types used: `server_health`, `get_bytes`, `get_global_value`, `lookup_funcs`, `xrefs_to`, `insn_query`, `callees`, and `decompile`.
- Documentation evidence used only after live MCP confirmed the core storage/lifecycle facts.
- Executed B-agent reports were used as incorporated context and naming precedent, not as substitutes for the current MCP session.

## Evidence Checked

Current by-* docs checked:

| Path | Reason checked |
| --- | --- |
| `by-memory/0x0067a754-0x0067a758.g_pEventMan.md` | Target current state. |
| `by-file/Event.md` | Source family route and Event/EventMan ownership context. |
| `by-class/EventMan.md` | EventMan method inventory, lifecycle, vtable, and singleton context. |
| `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` | Constructor/destructor/helper island, `0x004a90d0`, `0x004aa1d0`, and retained-helper caveats. |
| `by-memory/0x004ab440-0x004ab476.EventManScalarDeletingDestructor.md` | Scalar deleting destructor clear path. |
| `by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md` | Activation caller of `0x004a90d0` through `g_pEventMan`. |
| `by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md` | Deactivation caller and `ResetInputState(false)` naming. |
| `by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md` | Raw cursor/anchor predicate consumer of `g_pEventMan`. |
| `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md` | Key-helper consumer and rejected `ctype`/raw-global wording. |
| `by-memory/0x0054b000-0x0054b210.PowerListPaneOnMouseEvent.md` | Capture/release consumer and rejected `g_pMetaMan` route. |
| `by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md` | Chat-status suppression consumers through EventMan. |
| `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md` | `extern EventMan* g_pEventMan` and `PostNotification` source-facing call precedent. |
| `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md` | EventMan constructor and source-family context. |
| `by-memory/0x006196b0-0x006196bc.EventManVtableData.md` | EventMan vtable/scalar-dtor/timer slot context. |
| `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md` | Predecessor singleton boundary. |
| `by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md` | Successor singleton boundary and duplicate-definition policy contrast. |

Executed reports checked:

| Report | Relevant conclusion used |
| --- | --- |
| `executed-b-agent-research/B008/00014C-EventManAndEventFactoryHelpers-source-quality.md` | EventMan helper island, `TranslateEventKey`, `PostNotification`, `ClearSingletonForUnwind`, split-first aggregate disposition. |
| `executed-b-agent-research/B008/0002GK-BaramAppOnDeactivate-empty-emitter-source-quality.md` | `EventMan::ResetInputState(bool applicationActive)` for deactivation `false`, activation sibling `true`, and UID00028L support update history. |
| `executed-b-agent-research/B001/0002GJ-BaramAppOnActivate-empty-emitter-source-quality.md` | Activation currently emits `ClearKeyboardState()` and preserves the older name; this creates a support-name consistency issue, not a target-blocking contradiction. |
| `executed-b-agent-research/B006/0004B6-PowerListPaneOnMouseEvent-by-memory-source-quality.md` | `dword_67A754` route is EventMan, not MetaMan; capture/release source-facing names remain inferred. |
| `executed-b-agent-research/B011/0002KD-ParcelPaneOnKeyDown-source-quality.md` | `dword_67A754` route is EventMan and `0x004a8b10` is `TranslateEventKey`, not CRT/locale. |
| `executed-b-agent-research/B001/00027C-EventManKeyTranslationTables.md` | EventMan constructor/table ownership and the Event.cpp versus possible EventMan.cpp caveat. |

Live MCP evidence checked:

| MCP check | Current result |
| --- | --- |
| `get_bytes 0x0067a750 size 12` | Twelve zero bytes spanning `g_pLanguageMan`, `g_pEventMan`, and `g_pItemObjImageLib`. |
| `get_bytes 0x0067a738 size 48` | Entire surrounding singleton window is zero-filled. |
| `get_global_value 0x0067a754` | `0x0`. |
| `xrefs_to 0x0067a754 limit 300` | `210` direct refs. |
| `xrefs_to 0x0067a750` | `192` refs to predecessor `g_pLanguageMan`. |
| `xrefs_to 0x0067a758` | `65` refs to successor `g_pItemObjImageLib`. |
| `lookup_funcs 0x0067a754` | Not a function. |
| `lookup_funcs 0x004a8b40` | `sub_4A8B40`, size `0x3d3`. |
| `lookup_funcs 0x004a8f20` | `sub_4A8F20`, size `0x15`. |
| `lookup_funcs 0x004ab3e0` | `sub_4AB3E0`, size `0xb`. |
| `lookup_funcs 0x004ab440` | `sub_4AB440`, size `0x36`. |
| `lookup_funcs 0x004a90d0` | `sub_4A90D0`, size `0x2d`. |
| `lookup_funcs 0x004aa1d0` | `sub_4AA1D0`, size `0x24`. |
| `lookup_funcs 0x00465f20` | `sub_465F20`, size `0x81c`, Main_WndProc-style input bridge. |
| `lookup_funcs 0x004669c0` | `sub_4669C0`, size `0xa9`, activation. |
| `lookup_funcs 0x00466a70` | `sub_466A70`, size `0xb3`, deactivation. |
| `lookup_funcs 0x004c7850` | Not a function; raw SimpleHelpPane2 predicate region still unmodeled. |
| `xrefs_to 0x004a90d0` | Two refs: `0x004669d9` and `0x00466acc`. |
| `xrefs_to 0x004aa1d0` | Twelve refs. |
| `xrefs_to 0x004ab440` | One data ref at `0x006196b4`. |
| `xrefs_to 0x004ab3e0` | One code/EH ref at `0x005fdbee` inside the constructor/unwind route. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-00028L-01 | UID00028L is exactly the four-byte `.data` singleton slot `0x0067a754-0x0067a758`. | High | MCP `get_bytes` shows zero bytes; `lookup_funcs 0x0067a754` is not a function; neighbors have distinct xrefs. | Target Scope/Storage. | incorporate | applied |
| C-00028L-02 | The slot initializes to zero/null and should be represented as a source-level null pointer definition. | High | MCP `get_global_value 0x0067a754 -> 0x0`; `get_bytes 0x0067a738 size 48` all zero. | Target formal C++ and Storage. | incorporate | applied |
| C-00028L-03 | The formal source definition should be `EventMan *g_pEventMan = NULL;`. | Medium-high | Target type/project name, generated consumers with `extern EventMan *g_pEventMan`, EventMan lifecycle writers, no by-global duplicate-definition page. | Target `RECONSTRUCTION_CPP` block. | incorporate | applied |
| C-00028L-04 | Do not mark the definition `static` in this draft. | Medium-high | Generated `InputMan.cpp` and `MiscWorkThread.cpp` use `extern EventMan *g_pEventMan`; many cross-module consumers use the global. | Target Reconstruction Notes / formal C++. | incorporate | applied |
| C-00028L-05 | Keep owner/emitter route through [UID:0000J6] Event/Event.cpp. | High | Current target metadata, Event file source family, generated path `auto-generated/NexusTK/ui/core/Event.cpp`, EventMan support docs. | Target metadata and Ownership. | already-present | already-present |
| C-00028L-06 | Do not transfer canonical ownership to EventMan class for this global storage page. | Medium-high | EventMan owns methods/class behavior; the singleton definition is file-scope Event.cpp storage. | Target Ownership / Negative Evidence. | reject-invalid | applied |
| C-00028L-07 | The slot has 210 direct xrefs in the active IDB. | High | Current MCP `xrefs_to 0x0067a754 limit 300` count is `210`. | Target Evidence Notes. | incorporate | applied |
| C-00028L-08 | Constructor `0x004a8b40` publishes the singleton and guard-clears it. | High | MCP `insn_query`: `0x004a8b89 mov dword_67A754, eax`; `0x004a8b90 mov dword_67A754, 0`; decompile shows publish/guard branch. | Target Lifetime / Evidence. | incorporate | applied |
| C-00028L-09 | Ordinary destructor `0x004a8f20` clears `g_pEventMan`. | High | MCP `insn_query`: `0x004a8f26 mov dword_67A754, 0`; decompile writes EventMan vtable and clears. | Target Lifetime / Evidence. | incorporate | applied |
| C-00028L-10 | EH/unwind helper `0x004ab3e0` clears `g_pEventMan` and should not emit standalone source C++. | High | MCP `lookup_funcs` size `0xb`; `insn_query`/decompile: `mov dword_67A754, 0`; B008 report records EH/unwind support. | Target Lifetime / Negative Evidence. | incorporate | applied |
| C-00028L-11 | Scalar deleting destructor `0x004ab440` clears `g_pEventMan` but does not own the global definition. | High | MCP `0x004ab44c mov dword_67A754, 0`; xref from vtable slot `0x006196b4`; UID0003LV docs. | Target Lifetime / Negative Evidence. | incorporate | applied |
| C-00028L-12 | Main_WndProc-style input bridge at `0x00465f20` is the largest single direct consumer with eleven loads. | High | MCP top xref grouping count `11`; `insn_query` refs `0x466011`, `0x4661fc`, `0x466254`, `0x4663d5`, `0x46642d`, `0x466449`, `0x46647c`, `0x46649e`, `0x466501`, `0x46665d`, `0x466671`. | Target Consumer Evidence. | incorporate | applied |
| C-00028L-13 | Activation/deactivation load `g_pEventMan` before calling `0x004a90d0`. | High | MCP `insn_query`: activation `0x004669cd mov ecx, dword_67A754`; deactivation `0x00466ac0 mov ecx, dword_67A754`; `xrefs_to 0x004a90d0` has `0x004669d9` and `0x00466acc`. | Target Consumer Evidence; support docs. | incorporate | applied |
| C-00028L-14 | `0x004a90d0` is best documented as `EventMan::ResetInputState(bool applicationActive)` for lifecycle callers, with `ClearKeyboardState` retained as a historical/behavior alias. | Medium-high | B008 UID0002GK accepted `ResetInputState(false)`; activation currently emits `ClearKeyboardState()`; MCP decompile clears `this+0x820`, `this+0x920`, `this+0x922`; bool arg is passed but not visibly consumed. | Target Reconstruction Notes; optional EventMan support consistency update. | incorporate | applied |
| C-00028L-15 | `0x004aa1d0` remains an EventMan/Event.cpp notification post helper, not Application-owned. | High | MCP `lookup_funcs` size `0x24`; `xrefs_to` count `12`; decompile calls `sub_4651D0(g_pApplication)` and posts message `0x406` through global PostMessageW pointer; B008 report. | Target Consumer/Helper Evidence. | incorporate | applied |
| C-00028L-16 | `0x004a8b10` and key-handler consumers reinforce EventMan ownership of the global route, not CRT/locale ownership. | High | B008 EventMan report; B011 UID0002KD report; ParcelPane target now emits `g_pEventMan->TranslateEventKey`. | Target Consumer Evidence / Negative Evidence. | incorporate | applied |
| C-00028L-17 | `PowerListPane` capture/release consumers use `g_pEventMan`, rejecting the stale `g_pMetaMan` route. | High | Executed B006 UID0004B6 report and target; current docs name `g_pEventMan->CaptureMouse()`/`ReleaseMouse()`. | Target Representative Consumers / Negative Evidence. | incorporate | applied |
| C-00028L-18 | Raw SimpleHelpPane2 predicate reads `dword_67A754` at `0x004c7866` to call `EventMan::GetCursorPosition`. | High | MCP `insn_query 0x004c7850-0x004c78db`; UID00022O formal C++. | Target Representative Consumers. | incorporate | already-present |
| C-00028L-19 | Screenshot/chat-status path and MiscWorkThread notifications are valid consumers, not owners. | Medium-high | UID0001G8 formal C++ uses suppression methods; UID0001CJ uses `extern EventMan* g_pEventMan` and `PostNotification`; lifecycle writes are elsewhere. | Target Representative Consumers / Negative Evidence. | incorporate | already-present |
| C-00028L-20 | Predecessor `0x0067a750-0x0067a754` is `g_pLanguageMan` with 192 refs; successor `0x0067a758-0x0067a75c` is `g_pItemObjImageLib` with 65 refs. | High | MCP `xrefs_to` counts; neighboring target docs. | Target Boundary Evidence. | incorporate | applied |
| C-00028L-21 | Do not widen, split, rename, or create a new child for UID00028L. | High | Exact one-dword singleton storage; distinct neighbor xrefs; no internal boundary. | Target Split/Range Decision. | already-present | already-present |
| C-00028L-22 | Do not create a separate by-global page during this callback; use UID00028L as the single definition site. | Medium-high | No existing `by-global/g_pEventMan.md`; generated route already assigns UID00028L to Event.cpp; duplicate-definition policy from neighboring pages. | Target Reconstruction Notes. | incorporate | applied |
| C-00028L-23 | Current generated output is stale and should no longer show UID00028L as an empty marker after callback validation. | High | `auto-generated/NexusTK/ui/core/Event.cpp` previously showed `Empty Emitter Marker` for UID00028L. | Validator/Generated proof after callback. | incorporate | applied |
| C-00028L-24 | Metadata should increase to `88/92`. | Medium-high | Source definition resolved, live MCP confirms storage/lifecycle/consumers; remaining original spelling/source split caveats cap below final audit. | Target metadata and score rationale. | incorporate | applied |
| C-00028L-25 | Support docs should not be edited by default except narrow method-name consistency if supervisor chooses. | Medium-high | Target already contains `ResetInputState` support note; `by-class/EventMan` and UID00014C still contain older `ClearKeyboardState` rows; no implementation blocker for UID00028L. | Recommended Support Doc Changes. | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Current MCP confirms `0x0067a754` is zero-initialized data, not code.
- The exact storage has `210` direct xrefs in the active IDB.
- Constructor, ordinary destructor, EH/unwind helper, and scalar deleting destructor all write the expected singleton value/clear.
- Main window input dispatch loads this global eleven times across focus, cursor, mouse, keyboard, IME, and message routes.
- Activation and deactivation both use the global before calling the same EventMan state reset helper.
- EventMan notification, key translation, cursor, capture/release, screenshot suppression, and MiscWorkThread notification support all agree on the `g_pEventMan` route.
- The predecessor and successor singleton slots have independent identities and xref counts.
- Generated output already routes UID00028L through `NexusTK/ui/core/Event.cpp`, so a target formal C++ definition will land in the expected source family.

## Negative Evidence Summary

- No evidence supports treating `0x0067a754` as part of the predecessor `g_pLanguageMan` or successor `g_pItemObjImageLib` slots.
- No evidence supports InputMan, EventDispatcher, Application, PowerDialogPane, ParcelPane, ScreenshotCapture, MiscWorkThread, or UI panes owning this storage; they are consumers.
- `g_pMetaMan` is rejected for `dword_67A754`; PowerListPane evidence confirms it is EventMan.
- CRT/locale `std::ctype<char>::do_narrow` is rejected for `0x004a8b10`; that helper is EventMan key translation.
- `0x004ab3e0` is not standalone handwritten source; it is EH/unwind singleton-clear support.
- `0x004ab440` is a scalar deleting destructor wrapper; it clears the singleton but does not own the global declaration.
- Creating a new by-global page or duplicate definition is not necessary for this pass.
- `static EventMan *g_pEventMan` is weaker than a non-static definition because generated consumers use `extern EventMan *g_pEventMan`.

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Evidence and rationale |
| ---: | --- | --- | --- |
| 1 | [UID:0000J6] Event / `NexusTK/ui/core/Event.cpp` | Accepted canonical owner and emitter route. | Keep `CANONICAL_OWNER:0000J6`, `EMITTER_UIDS:0000J6`, `RECONSTRUCTABLE:TRUE`, and source path `NexusTK/ui/core/Event.cpp`. Current metadata, generated memory coverage, and Event/EventMan lifecycle context all route this file-scope singleton definition through Event.cpp. |
| 2 | [UID:00004O] `EventMan` class | Accepted semantic class, rejected as storage owner. | The pointer type and pointed-to object are `EventMan *`, but UID00028L is global storage, not a class method body or class static-member proof. EventMan remains the class context for methods, vtable, constructor/destructor behavior, and helper analysis. |
| 3 | Consumer-only modules including Main_WndProc, activation/deactivation handlers, key/mouse pane handlers, screenshot, and work-thread notification pages | Rejected ownership; consumers only. | Current MCP and support docs show loads/calls through `g_pEventMan`, not definition ownership. These pages may include `extern EventMan *g_pEventMan` in generated source, but should not own or emit the singleton storage. |
| 4 | Neighboring singleton slots `0x0067a750` `g_pLanguageMan` and `0x0067a758` `g_pItemObjImageLib` | Rejected ownership and range widening. | MCP byte/xref checks show adjacent zero-initialized pointer slots with separate xref populations. UID00028L remains the four-byte range `0x0067a754-0x0067a758`; it should not merge into predecessor or successor singleton storage. |
| 5 | New `by-global/g_pEventMan.md` or duplicate global definition page | Not needed for this pass. | No by-global duplicate exists for this exact singleton. The by-memory page is already reconstructable, already routes to Event.cpp, and can directly carry the one-line source definition without adding another ownership surface. |
| 6 | EH clear helper `0x004ab3e0` and scalar deleting destructor route `0x004ab440` | Accepted as lifecycle evidence; rejected as owners. | These routes clear or delete the current EventMan instance and prove lifecycle participation, but neither owns the source-level global storage definition. They remain supporting evidence in the target. |

## Source Placement / Range / Data Classification Decision

- Range stays `0x0067a754-0x0067a758`.
- Entity kind remains global singleton pointer / source-authored project data.
- No split is needed.
- No range widening is allowed into `0x0067a750` or `0x0067a758`.
- Data classification remains ordinary null-initialized `.data` pointer storage.

## Source Naming And Type Decision

Accepted source-facing declaration:

```cpp
EventMan *g_pEventMan = NULL;
```

Reasons:

- `EventMan *` is directly supported by constructor/destructor/vtable/class docs.
- `g_pEventMan` is already the project source-facing name and is used by generated consumers.
- `NULL` matches the dominant current EventMan lifecycle style in accepted Application callback source (`g_pEventMan != NULL`). A later style-only pass could choose `0` or `nullptr`, but that is not a source-quality blocker for this target.
- No forward declaration is included in this target block; neighboring exact-storage singleton definitions also emit only the definition when the source family already supplies type context.

## First-Draft C++ Recommendation

Exact formal block to apply in the target if Gate 1 is accepted:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
EventMan *g_pEventMan = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is not a third-party import. It is a one-line project source definition for binary-backed singleton storage.

## Final Recommendation

Implement UID00028L as a target by-memory source definition page.

The callback should update the target metadata, item summary, evidence, score rationale, and formal C++ block. Support docs can remain untouched unless the supervisor wants the `0x004a90d0` naming tension resolved consistently in [UID:00004O] and [UID:00014C].

## Recommended Target Doc Changes

1. Set `COMPLETION:88`.
2. Set `CONFIDENCE:92`.
3. Keep `CANONICAL_OWNER:0000J6`.
4. Keep `RECONSTRUCTABLE:TRUE`.
5. Keep `EMITTER_UIDS:0000J6`.
6. Insert the exact formal C++ block above.
7. Replace the item summary with a source-emission-ready summary. Suggested text:

```text
EventMan singleton source definition/storage; current B011 MCP session `supervisor_recovery_20260705` confirms zero-filled four-byte slot `0x0067a754-0x0067a758`, 210 direct xrefs, constructor publish/guard clear, ordinary destructor/EH helper/scalar-deleting destructor clears, Main_WndProc input consumers, activation/deactivation reset calls, notification/UI/helper consumers, clean LanguageMan/ItemObjImageLib neighbor boundaries, and first-draft source definition `EventMan *g_pEventMan = NULL;` through [UID:0000J6][Event].
```

8. Update storage/evidence sections with current MCP details:
   - health/session `supervisor_recovery_20260705`;
   - `get_global_value 0x0067a754 -> 0x0`;
   - `get_bytes 0x0067a750 size 12` and `0x0067a738 size 48` zero-filled;
   - `xrefs_to 0x0067a754` count `210`;
   - constructor writes `0x004a8b89` and `0x004a8b90`;
   - clears at `0x004a8f26`, `0x004ab3e0`, `0x004ab44c`;
   - Main_WndProc loads listed in C-00028L-12;
   - app lifecycle loads at `0x004669cd` and `0x00466ac0`;
   - `0x004a90d0` xrefs `0x004669d9`, `0x00466acc`;
   - `0x004aa1d0` twelve refs and message `0x406` route;
   - neighbor xref counts `192` and `65`.
9. Add a reconstruction note that this page is the single current definition site because there is no `by-global/g_pEventMan.md`.
10. Preserve negative owner rationale rejecting adjacent singleton, consumer-owner, `g_pMetaMan`, CRT/locale, EH-helper-source, scalar-wrapper-owner, and duplicate-definition alternatives.

## Recommended Support Doc Changes

Support docs are not required for the target to emit, because the target already records the newer `ResetInputState(bool applicationActive)` support note and current consumers already use `g_pEventMan`.

Optional consistency edits if supervisor chooses support scope:

| Support doc | Recommendation |
| --- | --- |
| `by-class/EventMan.md` | Change the `0x004a90d0` row from only `ClearKeyboardState` to `ResetInputState(bool applicationActive)` / `ClearKeyboardState` alias, noting activation passes `true` and deactivation passes `false`, while the current body clears EventMan input/key state and does not visibly branch on the bool. |
| `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` | Historicalize the older `ClearKeyboardState`-only wording for `0x004a90d0`; preserve it as a behavior alias but add the accepted lifecycle source-facing name from UID0002GK. |
| `by-file/Event.md` | No required edit. It already routes Event/EventMan source through `NexusTK/ui/core/Event.cpp`. |
| `by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md`, `by-memory/0x0054b000-0x0054b210.PowerListPaneOnMouseEvent.md`, `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md`, `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md` | No edit required; they already contain same-or-greater consumer evidence for this report's purpose. |

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `88` | Formal global definition is now implementation-ready; current MCP updates storage, lifecycle, xref, consumer, generated-output, and boundary evidence. |
| `CONFIDENCE` | `90` | `92` | Direct live MCP evidence agrees with current docs and executed reports. Confidence remains below final audit because exact original declaration spelling/linkage and final `Event.cpp` versus possible `EventMan.cpp` source split remain inferred. |

No owner/emitter/reconstructable change is recommended.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Remaining status |
| --- | --- | --- |
| Exact original initializer style: `NULL`, `0`, or `nullptr`? | Existing accepted EventMan lifecycle source uses `g_pEventMan != NULL`; VC-era global docs frequently use `NULL` or `0`. Use `NULL` here for consistency with current EventMan consumers. | Resolved for first draft, not final-symbol proof. |
| Exact linkage: `static` or external? | Generated consumers use `extern EventMan *g_pEventMan`, so non-static is safer. | Resolved for first draft. |
| Exact original source file: `Event.cpp` or `EventMan.cpp`? | Current project route and generated output use `NexusTK/ui/core/Event.cpp`. | Keep Event.cpp; future split remains open. |
| `0x004a90d0` source name? | UID0002GK accepted `ResetInputState(bool applicationActive)` for lifecycle calls; UID0002GJ and older EventMan docs preserve `ClearKeyboardState`. | Use `ResetInputState` with `ClearKeyboardState` as alias/caveat in target/support. |
| Need a new by-global page? | No existing page; target is already the generated Event.cpp storage entry. | Do not create in callback. |

## Validator Results

Callback validator run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00028L-g_pEventMan-source-quality-removed.md](00028L-g_pEventMan-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

| Field | Result |
| --- | --- |
| Exit code | `0` |
| `command_id` | `000000007322` |
| `command_timestamp` | `2026-07-05T18:54:51-04:00` |
| `ok` | `1` |
| `generated_refresh` | `completed` |
| `generated_refresh_command_id` | `000000007322` |
| `generated_refresh_timestamp` | `2026-07-05T18:54:51-04:00` |

Target-specific validator updates:

- `completion_update 00028L ... 88`
- `confidence_update 00028L ... 92`
- `autogen_cpp_update 0000J6 auto-generated/NexusTK/ui/core/Event.cpp`
- `research_tracker_update` and `memory_auto_coverage_update` were validator-owned generated refreshes.

Read-only generated freshness inspection after validation:

- `auto-generated/NexusTK/ui/core/Event.cpp` header has `validator-command-id: 000000007322` and `validator-refreshed-at: 2026-07-05T18:54:51-04:00`.
- UID00028L generated source now appears as `// UID:00028L | by-memory/0x0067a754-0x0067a758.g_pEventMan.md | Completion:88 | Confidence:92` followed by `EventMan *g_pEventMan = NULL;`.
- UID00028L is no longer an Empty Emitter Marker. Later Event/EventMan neighboring entries still have their own unrelated empty markers.
- `auto-generated/-ag-coverage-report-by-memory.md` header matches command `000000007322`; UID00028L now shows `emits_code:true`, `88%`, updated `2026-07-05 18:54:52`.
- `auto-generated/-ag-memory-coverage.md` header matches command `000000007322`; UID00028L is now `coded` through `0000J6` to `auto-generated/NexusTK/ui/core/Event.cpp`.
- `auto-generated/-ag-research-tracker.md` header matches command `000000007322`; UID00028L now shows `88/92`, combined `90.0`.

Known non-target validator diagnostics remained unrelated to this callback: two `missing_ref_uid 0003LV` diagnostics in the target file and broad generated child-marker/emitter-no-code notices in other generated contexts. They did not block the scoped validator (`ok: 1`) or UID00028L generated emission.

## Changed Files

Manual edits made by B011:

- `tools/leaser/Agents/Agent-B011/research/00028L-g_pEventMan-source-quality.md`
- `by-memory/0x0067a754-0x0067a758.g_pEventMan.md`

Validator-owned refresh side effects reported by the scoped file validator:

- `auto-generated/NexusTK/ui/core/Event.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-research-tracker.md`
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini` registry metadata rebuild/update
- `tools/validator_autogen_backup/20260705-185455`, `tools/validator_autogen_backup/20260705-185459`, and `tools/validator_autogen_backup/20260705-185501`

No support by-* docs, supervisor ledgers, report lifecycle/archive files, or generated files were manually edited. No `execute_report`, dry-run execute, lifecycle, manual move, or archive command was run.

## Implementation Tracking Checklist

Callback status: target-only implementation applied. Optional support consistency edits were excluded by explicit supervisor scope.

| Status | Item | Callback instruction / proof expected |
| --- | --- | --- |
| [x] | Supervisor validation required before implementation | Gate 1 passed at report SHA256 `DBE938D100184045749B48E412E56E5226D03C91BA36CB2DC4457D0E6C9C20F9`; callback then authorized target-only implementation. |
| [x] | Lease target immediately before editing | Leased only `by-memory/0x0067a754-0x0067a758.g_pEventMan.md` as `B011`; unleased after validation; read-only lease report shows no active B011 lease. |
| [x] | Target doc to update | Applied metadata, item summary, formal C++, evidence, ownership/negative evidence, score rationale, reconstruction notes, and change log in UID00028L. |
| [x] | Support docs to update | Excluded with reason: supervisor instructed target-only scope and no optional EventMan support consistency edits in this callback. |
| [x] | Current target state/evidence checked recorded | Report now records post-callback `88/92`, formal C++, generated proof, and prior `85/90` blank-C++ state as historical callback context. |
| [x] | Claim-ledger update required | Ledger rows now use `applied`, `already-present`, or `excluded-with-reason`; no accepted item is marked `proposed`. |
| [x] | Metadata/score changes | Applied `COMPLETION:88`, `CONFIDENCE:92`; kept owner/emitter/reconstructable fields and blank emitter position. |
| [x] | Score-limiting blockers researched | Target score rationale preserves caps for exact original declaration spelling/linkage and `Event.cpp` versus possible future `EventMan.cpp` split. |
| [x] | Owner/emitter/reconstructable fields | Already present and preserved: `CANONICAL_OWNER:0000J6`, `EMITTER_UIDS:0000J6`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_POSITION_OPTIONAL`. |
| [x] | Split/rename/new-child decisions | Already present and preserved: no split, no rename, no new child, and no duplicate `by-global/g_pEventMan.md`. |
| [x] | Source-placement/range decisions | Applied/preserved range `0x0067a754-0x0067a758` and source route `NexusTK/ui/core/Event.cpp`. |
| [x] | IDA rename/type/comment decisions | Not applicable: callback required documentation-only changes and no IDA writes. |
| [x] | First-draft C++ block to apply | Applied exact formal code block content: `EventMan *g_pEventMan = NULL;`. |
| [x] | Third-party import directive | Not applicable: project singleton storage, not imported third-party source. |
| [x] | Exact target facts to incorporate | Applied storage bytes/value, 210 xrefs, lifecycle writes/clears, Main_WndProc refs, activation/deactivation refs, `0x004a90d0` refs, `0x004aa1d0` route, neighbor xref counts, and generated empty-marker resolution expectation. |
| [x] | Exact support facts to incorporate | Excluded with reason: no support docs edited under target-only callback; existing target retains the `ResetInputState(bool)` support note. |
| [x] | Historical/stale assumptions to preserve | Applied in target score/reconstruction/change-log notes: previous blank-C++ rationale is superseded, `ClearKeyboardState` remains historical/behavior alias context, and source split caveat remains open. |
| [x] | Negative evidence to preserve | Applied rejection of adjacent singleton ownership, consumer ownership, `g_pMetaMan`, CRT/locale, EH-helper source emission, scalar-wrapper ownership, duplicate by-global definition, and `static` declaration. |
| [x] | Wave2/Wave3 handling | Not applicable; no Wave2/Wave3 material or manual coverage edits used. |
| [x] | Open questions to close/document | Applied initializer/linkage/source-split caveats and helper-name limits in target score/reconstruction notes. |
| [x] | Validators to run | Required scoped validator ran with `--apply --queue-timeout 240 --wait-generated`; exit code `0`, `command_id 000000007322`, `ok: 1`, generated refresh completed. |
| [x] | Generated output disposition | Read-only inspection confirmed generated `Event.cpp` header matches command `000000007322`, UID00028L emits `EventMan *g_pEventMan = NULL;`, and memory coverage reports `emits_code:true`. |
| [x] | Manual coverage/tracker disposition | Not applicable: tracker/coverage updates were validator-owned only; no manual generated, coverage, tracker, or validator-state edits. |
| [x] | Implementation callback pass rows | Recorded lease used/released, validator command/result, generated freshness, changed files, and callback states in this report. |
| [x] | Remaining unapplied accepted items row | None blocked. The only non-applied report item is optional support consistency work, excluded by explicit target-only callback scope. |

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000007330","destination_path":"executed-b-agent-research/B011/00028L-g_pEventMan-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/00028L-g_pEventMan-source-quality.md","timestamp":"2026-07-05T19:01:56-04:00","uid":"00028L"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00028L-g_pEventMan-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00028L-g_pEventMan-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00028L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
