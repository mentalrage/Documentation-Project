*** UID:0000K6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# InputMan

## Proposed Original Placement

- Proposed source path: `input/InputMan.cpp`
- Proposed header path: `input/InputMan.h`
- Projected reconstruction path: `NexusTK/input/InputMan.cpp`
- Confidence: strong

## Source Ownership Notes

This page is the sole source root for `NexusTK/input/InputMan.cpp` and sibling `InputMan.h`. No split or new child page is required: UID00018E remains the exhaustive method/helper aggregate, UID00006J owns the class declaration/child route, and UID00050J owns the singleton definition plus specializations.

## Responsibilities

`InputMan` is the process-wide Win32 input and IME manager. It owns the custom IME context, tracks UI input targets, bridges the main window procedure into text/composition/candidate events, and notifies the application when the tracked input-target set becomes empty or non-empty.

This should not be merged into `Application.cpp`: `Application` constructs and destroys it, but the implementation is large, IME-specific, and has its own state and helper routines.

Keep this separate from [UID:0000K5][IMEPanes](by-file/IMEPanes.md). `InputMan` produces and routes Win32/IMM input events, while `IMEPanes.cpp` owns the root IME pane singleton, composition/candidate/status popup panes, and focus-pane list. Also keep [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) separate: it owns Windows keyboard repeat settings, not input message routing.

## Likely File Contents

- `class InputMan : public LObject, public Singleton<InputMan>` with exact x86 size `0x20`, complete shared Singleton dependency, seven fields, virtual destructor, full public API, and CPP-only child routing.
- Small IME helper logic currently embedded in the recovered `HandleWindowMessage` method view, such as candidate-list construction, composition string extraction, `GCS_CURSORPOS` composition cursor-position query at `0x004e94d0`, and candidate text conversion. The candidate-list notification branch builds a visible candidate deque from IMM `CANDIDATELIST` page-start/page-size data, computes selected row as `dwSelection - pageStart`, and calls the Event factory at `0x004a9e50`; the current `CandidateStringQueue` helper calls in this method are standard-library [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) support, not evidence for an `InputMan`-owned queue class.
- Input-manager globals:
  - [UID:00050J][g_pInputMan](by-global/g_pInputMan.md), the semantic owner and sole `InputMan *g_pInputMan = 0;` definition followed by explicit `Singleton<InputMan>` constructor/destructor specializations; [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) is non-emitting physical backing evidence.
- PlatformApi wide-dispatch imports used by this file: `g_pfnDefWindowProcW` at `0x0069be50`, `g_pfnPostMessageW` at `0x0069be90`, `g_pfnImmGetCompositionStringW` at `0x0069bebc`, `g_pfnImmGetCandidateListW` at `0x0069bec0`, and `g_pfnGetLocaleInfoW` at `0x0069bec8`. These slots are initialized by [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) and should not be moved into `InputMan.cpp`.
- Receiver-bearing EventMan methods for character, IME open/composition, candidate-list, and candidate-close dispatch. The bodies remain [UID:0000J6][Event](by-file/Event.md)-owned; `InputMan.cpp` includes `../ui/core/Event.h` and calls through `g_pEventMan` rather than declaring historical free factories.

## Evidence

- IDA MCP confirms the modeled method/helper starts and sizes in the main executable island:
  - `0x004e8af0-0x004e8c11` constructor
  - `0x004e8c20-0x004e8ca1` ordinary destructor
  - `0x004e8cb0-0x004e8cb5` five-argument member fallback handler
  - `0x004e8cc0-0x004e8ce1` raw/no-route keyboard-layout language helper
  - `0x004e8cf0-0x004e8dcb` `TrackInputTarget`
  - `0x004e8de0-0x004e9319` `HandleWindowMessage`
  - `0x004e9430-0x004e9434` `GetInputMode`
  - `0x004e9440-0x004e9485` `SetInputMode`
  - `0x004e9490-0x004e9561` composition finalizer, free cursor-position helper, and composition copier
  - `0x004e9570-0x004e964a` current-context getter/release helper plus ten retained IMM/PlatformApi wrappers
  - `0x004e9650-0x004e965b` compiler-retained constructor-unwind action for `Singleton<InputMan>::~Singleton()`, no handwritten body
  - `0x004e9660-0x004e970d` compiler scalar deleting destructor, source-covered by the virtual destructor
- IDA MCP shows the constructor is called from `Application::Initialize` at `0x00464572`.
- IDA MCP shows `HandleWindowMessage` is called from the main application window-message path at `0x00465fad`.
- Recovered constructor evidence shows use of `ImmGetDefaultIMEWnd`, `ImmCreateContext`, `ImmAssociateContext`, `ImmGetContext`, `ImmSetOpenStatus`, `ImmReleaseContext`, and `ImmGetProperty`.
- `TrackInputTarget` sends message `0x401` through `g_pfnPostMessageW` when active input-target state crosses empty/non-empty; its source signature is `void` and its exact List operations are `RemoveAll`, `Append(1, &targetId)`, and `RemoveAt(index, 1)`.
- Historical 2026-06-07 A006 documentation for [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) called `dword_67AB44` initialized to `0xffffffff` while correctly inventorying 18 direct xrefs. Current PE mapping and bounded IDB bytes disprove the initializer interpretation: the slot lies beyond `.data` raw extent and is loader-zero-filled as `00 00 00 00`. The xrefs remain valid: Application/message consumers at `0x00464bff`, `0x00464d94`, `0x00465f84`, and `0x004661c7`; IME consumer `0x004e7600`; InputMan publication/clear writes at `0x004e8b33`, `0x004e8b3a`, `0x004e8c81`, `0x004e9650`, and `0x004e96c8`; and UI/input consumers at `0x004f6796`, `0x004f8ae4`, `0x005445cc`, `0x00544ebb`, `0x00544ecd`, `0x00544fa3`, `0x00590f65`, and `0x005a25e0`.
- The same singleton pass confirms `0x0067ab44-0x0067ab48` is bounded by the `g_pDATFileMgr` slot at `0x0067ab40` and a separate non-InputMan singleton slot at `0x0067ab48`.
- 2026-06-17 B001 reanalysis for [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) confirms `InputMan::HandleWindowMessage` owns the producer side of Event type `15`: the candidate-list branch handles IMM candidate-list notifications, defaults zero page size to `9`, appends visible-page strings through `0x004e9710`, and calls `0x004a9e50` with candidate deque pointer plus selected row.

## Migration Notes

- Keep this under the top-level `input/` folder shown in the proposed source tree unless later original-source evidence proves the project nested input under `app/`.
- Keep the IME candidate-string container name provisional. IDA now supports a `std::deque<std::wstring>`-style implementation, so reconstruct the source as ordinary wide-string/deque operations and do not add a handwritten queue implementation to `InputMan.cpp`.
- Keep the receiver-bearing EventMan method bodies at `0x004a9a40-0x004a9f00` in [UID:0000J6][Event](by-file/Event.md); `InputMan.cpp` consumes their declarations from `Event.h`.
- Keep pane-side helpers in [UID:0000K5][IMEPanes](by-file/IMEPanes.md), including `g_pIMEPane`, `IMEPane::SetFocusPane`, composition/candidate popup methods, and the candidate-string container member.
- `InputMan` depends on `Application` for the window handle, but the direction should remain app -> input rather than merging input into app.

## UID000090 Header And List Dependency Contract - 2026-07-31

- `NexusTK/input/InputMan.h` is the declaration owner for the complete `InputMan` class, its accepted `0x20` layout, public message/IME API, `g_pInputMan`, and the compile-time size guard. The header may forward-declare `List` because the field is pointer-only.
- `NexusTK/input/InputMan.cpp` owns the executable bodies in [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md). It includes `InputMan.h` and complete `../util/List.h` because the constructor, destructor, and `TrackInputTarget` allocate, release, inspect, append to, and remove from the list. A forward declaration is not sufficient at those member-call sites.
- [UID:000079][List](by-class/List.md) and [UID:0000KS][List](by-file/List.md) remain the declaration/body owners for the generic container. InputMan consumes that utility type and does not acquire its methods, layout, allocation helpers, or source file.
- [UID:0004ZK][Singleton](by-file/Singleton.md) and [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md) own the complete storage-free primary template. `InputMan.h` includes `../util/Singleton.h`; the consuming `InputMan.cpp` owns only its two explicit class-specific specializations.
- The Windows/IMM declarations and local message/candidate helpers remain implementation details in `InputMan.cpp`. Event factories remain Event-owned, PlatformApi slots remain PlatformApi-owned, and pane-side IME display state remains IMEPanes-owned.
- This supersedes the former blank `InputMan.h`/PCH-only route. It does not change any target range, executable behavior, owner/emitter metadata, or the documented uncertainty around a few original source spellings.

## State And Dispatch Inventory

| Area | Current evidence | File-level decision |
| --- | --- | --- |
| Executable island | [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) records 26 starts: 24 source-authored constructor/destructor/member/helper/wrapper bodies and compiler-only Singleton unwind/scalar destruction, plus four switch/value tables and all exact gaps. | Treat its formal CPP as the canonical complete body. Emit no source for tables, gaps, `0x004e9650`, or `0x004e9660`. |
| Class layout | [UID:00006J][InputMan](by-class/InputMan.md) documents direct `LObject` PMD 0 and empty `Singleton<InputMan>` PMD +4 bases, the vptr, seven fields through `+0x1c`, and total size `0x20`. | Emit the guarded dual-base H, shared Singleton include, complete API, free helper declarations, and no H child marker. |
| Singleton | [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) owns the definition and exact explicit constructor/destructor specializations; [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) is loader-zero non-emitting backing. | Emit the definition/specializations before UID00006J children; omit all manual derived assignments and any handwritten unwind helper. |
| RTTI/vtable | [UID:0003BR][0x0061c5a0-0x0061c5b0.InputManVtableData](by-memory/0x0061c5a0-0x0061c5b0.InputManVtableData.md) records COL `0x00649444`, CHD `0x00649458`, three base descriptors, Singleton descriptor `0x00676dac`, and three slots. | Class-owned compiler data, `RECONSTRUCTABLE:FALSE`, non-emitting; regenerate from the dual-base declaration and virtual destructor. |
| Windows/IMM dispatch table | [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) and adjacent dispatch-slot docs identify `ImmGetCompositionStringW`, `ImmGetCandidateListW`, `SendMessageW`, and related wide API pointers used by this file. | Keep as platform/API dispatch state initialized by `PlatformApi`/UniAPI support; type the consumers in `InputMan` instead of moving the table here. |
| Event methods | InputMan calls receiver-bearing EventMan bodies in the `0x004a97e0-0x004a9f00` family. | Keep bodies in [UID:0000J6][Event](by-file/Event.md); consume the complete EventMan declaration while translating Win32/IME messages. |
| Pane-side IME state | `g_pIMEPane`, composition/candidate pane methods, focus-list state, and candidate-string member ownership are documented under [UID:0000K5][IMEPanes](by-file/IMEPanes.md). | Keep `InputMan` as the Win32/IMM producer/router and `IMEPanes.cpp` as the UI consumer/display side. |

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `94` | The file page reconciles all 26 starts, 24 human bodies, four tables, every exact gap, dual-base H, definition/specializations/source order, full RTTI/vtable and backing/no-code dispositions, dependencies, candidate defects, and zero owned strings/resources. |
| Confidence | `95` | Current IDA, preserved executable RTTI bytes, class/aggregate/global/template pages, caller/xref inventories, and formal generated routes agree. It remains below 100 because several original spellings and defect intent cannot be recovered without source/PDB evidence. |

## g_pInputMan Source Definition And Lifetime Route - 2026-08-06

- [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) resolves the former missing-global parent gap and owns the externally linked source definition. Its canonical owner and emitter are this [UID:0000K6] file page, so the definition is routed into `NexusTK/input/InputMan.cpp`.
- [UID:00006J][InputMan](by-class/InputMan.md) remains the complete `InputMan.h` declaration owner and emits exactly one `extern InputMan *g_pInputMan;`. The global page H channel stays blank; [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) CPP/H channels also stay blank. This preserves a one-definition/one-declaration source split.
- The exact backing slot `[0x0067ab44,0x0067ab48)` begins `00 00 00 00` because its `.data` virtual offset `0x0000db44` lies beyond raw size `0x0000d800`. The accepted source definition `InputMan *g_pInputMan = 0;` reproduces that null startup state in plausible C++03-era source.
- Five compiler-lowered writes define lifetime from the two explicit specializations: constructor publish `0x004e8b33`, constructor-unwind clear `0x004e8b3a`, ordinary reverse-base clear `0x004e8c81`, EH-only action `0x004e9650`, and scalar-path clear `0x004e96c8`.
- Thirteen consumers span Application (`0x00464bff`, `0x00464d94`, `0x00465f84`, `0x004661c7`), IME composition (`0x004e7600`), MainMenu (`0x004f6796`, `0x004f8ae4`), Pane (`0x005445cc`, `0x00544ebb`, `0x00544ecd`, `0x00544fa3`), TextEditPane (`0x00590f65`), and UserPane (`0x005a25e0`). These remain dependency/consumer modules, not source owners.
- The direct InputMan file route is supported by the constructor/destructor writer cluster and existing class/header contract. Application owns construction/cleanup call sites, Event owns event factories, IMEPanes owns pane display state, PlatformApi owns wide API dispatch storage, and List owns the generic container implementation.
- File completion/confidence are `94/95`: source/body/header/routing/hierarchy and candidate ownership questions are closed; exact original spellings remain the only material cap.

## UID0000K6 Exhaustive Whole-File Closure - 2026-08-24

- Complete executable inventory: 26 starts in `[0x004e8af0,0x004e970d)`, split into 24 source-authored bodies and compiler-only `0x004e9650` Singleton unwind plus `0x004e9660` scalar deleting destruction. The source set includes constructor/destructor, fallback handler, keyboard-language helper, target tracker, state-byte accessor, full WndProc bridge, mode getter/setter, two cross-file helpers, composition copier, current-context getter/releaser, and ten retained IMM/PlatformApi wrappers.
- Compiler products inside the aggregate are four tables at `0x004e931c-0x004e9334`, `0x004e9334-0x004e93f3`, `0x004e93f4-0x004e9408`, and `0x004e9408-0x004e9424`, plus exact alignment/gaps at `8c11-8c20`, `8ca1-8cb0`, `8cb5-8cc0`, `8ce1-8cf0`, `8dcb-8dd0`, `8dd4-8de0`, `9319-931c`, `93f3-93f4`, `9424-9430`, `9434-9440`, `9485-9490`, `94c4-94d0`, `950e-9510`, `9561-9570`, `9582-9590`, `95ab-95b0`, `95b9-95c0`, `95c5-95d0`, `95d9-95e0`, `95e9-95f0`, `95f9-9600`, `9609-9610`, `9619-9620`, `9629-9630`, `963a-9640`, `964a-9650`, `965b-9660`, and `970d-9710`. None emits source.
- Complete hierarchy: COL `0x00649444`; CHD `0x00649458`, attributes `1`, base count `3`; InputMan and LObject PMD `0`; `Singleton<InputMan>` PMD `+4`; Singleton type descriptor `0x00676dac`; preserved executable token at raw offset `0x2749B8`. UID0003BR is compiler-only and the dual-base H regenerates it.
- Source order is one UID00050J global definition, its two explicit Singleton specializations, then UID00006J `[[CHILDREN]]` and all 24 UID00018E bodies. `InputMan.cpp` includes `InputMan.h`, Event, List, MemoryMan, deque, string, and cstring dependencies; `InputMan.h` includes LObject, Singleton, Windows, and IMM declarations.
- Candidate behavior is intentionally faithful: MemoryMan owns the temporary CANDIDATELIST buffer; packed-DBCS and normal UTF-16 paths stay distinct; the special branch can use uninitialized `pageStart`; no checked receiver/dispatcher/destructor path frees the dispatched candidate deque. The source preserves these original defects.
- Negative inventory is closed at zero file-owned strings and zero file-owned resources. Adjacent UID00018F/UID0001WO is standard-library `std::deque<std::wstring>::push_back` support, not InputMan product code. No split, new source root, third-party import, or ownership move is justified.

## Parent-Gate Note

[UID:00050J][g_pInputMan](by-global/g_pInputMan.md) now exists as the narrow semantic owner and clears the attachment/source-entry gate at `94/96`. [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) attaches to that global as non-emitting physical evidence, while the global emits through this `94/95` file root. The former direct-file attachment was a temporary workaround for a missing path and is superseded, not silently deleted from history.

## Cross-References

- Class: [UID:00006J][InputMan](by-class/InputMan.md)
- Global: [UID:00050J][g_pInputMan](by-global/g_pInputMan.md)
- Neighboring files: [UID:0000K5][IMEPanes](by-file/IMEPanes.md), [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), [UID:0000HG][Application](by-file/Application.md), [UID:0000J6][Event](by-file/Event.md), [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Memory: [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md)
- Data: [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md), [UID:00025K][0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData](by-memory/0x0061c5a0-0x0061c7a4.InterfaceEfxReadOnlyData.md), [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md)
- Type support: [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)

## Changes

- 2026-08-24 B008 UID0000K6 accepted implementation callback: changed `88/90 -> 94/95`; retained `NexusTK/input/` and sole-file ownership; replaced stale sampled inventory with the complete 26-start/24-body model, four tables and all gaps; added dual LObject/Singleton H, shared Singleton dependency, global specialization source order, full RTTI hierarchy, compiler-only unwind/scalar/vtable/backing dispositions, complete dependency/event receiver model, generated completion expectations, candidate defect preservation, and zero string/resource inventory.

- 2026-08-06 B002 UID000299 accepted callback: retained `88/90` and `NexusTK/input/`; added [UID:00050J][g_pInputMan](by-global/g_pInputMan.md) as the semantic global definition owner and [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) as non-emitting physical evidence; documented the exact CPP definition/class-H declaration split, loader-zero-filled startup state, all five writes and thirteen consumers, and retained the old `0xffffffff` plus direct-file-parent claims as disproved/superseded history.
- 2026-07-31 B002 UID000090 dependency callback: committed `InputMan.h` as complete declaration owner, `InputMan.cpp` as aggregate-body owner, and `../util/List.h` as the required complete implementation dependency; rejected blank-H, forward-only member-call, and PCH-only routes without moving List/Event/PlatformApi/IMEPanes ownership.

- 2026-06-05: Assigned projected reconstruction path `NexusTK/input/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree place `InputMan.cpp` under `input/`.
  - After: set the validator path to `NexusTK/input/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `InputMan.cpp` under `input`, and live IDA MCP lookup on 2026-06-05 confirms the constructor anchor at `0x004e8af0` as a real function of size `0x121`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Summary/evidence: input/IME manager responsibilities, Win32/IMM bridge, method starts, application/message callers, IME pane boundary, event factory routing, and candidate-string template caveat are documented; completion is lower because globals and per-message branches still need fuller detailed documentation.
- 2026-06-06 A005 memory-range refresh:
  - Before: the file page still mentioned a generated recovered container, listed only the older six-method inventory, and linked the stale `0x004e8af0-0x004e970c` aggregate path.
  - After: replaced the generated-container note with IDA-backed ownership guidance, expanded the method/helper list, and linked the corrected [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) aggregate.
  - Evidence: IDA MCP on 2026-06-06 confirmed the ordinary destructor, helper group, singleton clear helper, and scalar deleting destructor end at `0x004e970d`; completion/confidence remain `80/84` because event helper names and global callback types are still open.
- 2026-06-07 file-level inventory pass:
  - Before: the file page had the corrected method list but did not summarize state/global/read-only/API-dispatch ownership at the parent level.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`, with state/dispatch inventory and score-rationale sections.
  - Evidence: existing class, memory, global, and read-only pages now cover the exact executable island, `InputMan` field roles, `g_pInputMan`, `InputMan` vtable/read-only boundary, Windows/IMM dispatch pointer table relationship, event-factory exclusion, and IME-pane boundary. Scores stay below final-source quality because `HandleWindowMessage` helper names, callback/API pointer types, and several field names remain unresolved.
- 2026-06-07 A006 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`, below the stricter Batch 035 direct-parent gate for the `g_pInputMan` singleton storage child.
  - After: `COMPLETION:86`, `CONFIDENCE:89`.
  - Evidence: live IDA MCP rechecked the initialized singleton storage, all 18 direct xrefs, InputMan lifecycle writes/clears, UI/Application/input users, and adjacent-slot boundaries. A missing `by-global/g_pInputMan.md` parent could not be leased/created, so this file page is documented as the direct source owner used for assignment.
- 2026-06-17 B003 support update:
  - Changed support wording without changing score.
  - Evidence: [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) validates `0x004e94d0` as the `GCS_CURSORPOS` / `GetCompositionCursorPosition` helper used to measure the composition caret x position; stale composition-length wording should not be reused for this helper.
- 2026-06-17 B001 support update:
  - Changed support wording without changing score.
  - Evidence: [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) validates the candidate-list notification producer path and Event type `15` dispatch payload from `InputMan` to the IME candidate pane.
- 2026-06-18 B001 InputMan source-quality reanalysis:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`.
  - Summary/evidence: [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md) reanalysis resolves Event helper names, PlatformApi dispatch slot names/signatures, raw no-route helper roles for `0x004e8cc0` and `0x004e8dd0`, source-facing field names, `TrackInputTarget` list semantics, IME message/event payload structures, and formal C++ readiness. `InputMan.cpp` should remain under `NexusTK/input/`; Event factories stay in [UID:0000J6][Event](by-file/Event.md), pane-side IME UI stays in [UID:0000K5][IMEPanes](by-file/IMEPanes.md), and API dispatch storage stays in [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
- 2026-06-21 Rule 26 incorporation of B008 EventMan/factory helper report:
  - Score unchanged at `88/90`.
  - Summary/evidence: B008's [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) report confirms the Event-side helper names/signatures called by `InputMan::HandleWindowMessage`, especially `DispatchCompositionTextEvent` at `0x004a9ae0` and `DispatchCandidateListEvent` at `0x004a9e50`; InputMan remains the Win32/IMM producer/router, not the owner of those Event factory bodies.
