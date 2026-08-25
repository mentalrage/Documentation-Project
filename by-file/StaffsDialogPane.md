*** UID:0000O3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# StaffsDialogPane

## Status

- Confidence: very strong for the complete global/resource/class/method source union, compiler-support exclusions, and login/main-menu placement; absent constructor reachability remains a bounded confidence cap.
- Proposed source path: `login/StaffsDialogPane.cpp`
- Proposed header path: `login/StaffsDialogPane.h`
- Core address range: [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- Support ranges: [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonBaseDestructor.md), [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md), [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md), [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- Projected reconstruction path: `NexusTK/login/StaffsDialogPane.cpp`

## File Role

This module owns the pre-login staff/credits dialog shown over the main menu. It is a narrow `DialogPane` plus direct `Singleton<StaffsDialogPane>` subclass, not a reusable UI control module: it defines the active global and file-local `STAFF.EPF` pointer, creates the background, close button, and `ScrolledTextControlPane`, and reads `STAFFS` or `STAFFS2` text.

The source belongs with the main-menu/login support family because the constructor attaches through `g_mainUiLayerSlots.overlayPaneLayerContext` at `0x0069b36c` and shows through concrete `MainMenuPane *g_pMainMenuPane` at `0x0067aba4`; the content is a client/about/credits surface. Historical wording that collapsed both operands, used vague `g_mainUiLayer`, or called the show parent `g_pMainUiGraph` is superseded. It should not be grouped with GM/staff gameplay tools solely because of the word "staff".

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `StaffsDialogPane` | `0x004ffaa0-0x004ffd3d` plus compiler support at `0x00502410`, `0x00502592-0x005025a8`, `0x00502cc0-0x00502d05`, and `[0x0061d930,0x0061d9cc)` | Source constructor/OnControlCommand plus generated Singleton destructor, adjustors, scalar wrapper, vtables, and RTTI. |
| `g_pStaffsDialog` | [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md), physical [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md) | Sole external `StaffsDialogPane *g_pStaffsDialog = NULL;` definition; physical slot is non-emitting loader-zero evidence. |
| `StaffsDialogEpfResourcePointer` | [UID:0002ZI][StaffsDialogEpfResourcePointer](by-global/StaffsDialogEpfResourcePointer.md), [UID:00027M][0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer](by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md) | Source-declared pointer to the UTF-16 `STAFF.EPF` resource literal consumed only by the StaffsDialogPane constructor. |
| Staff resources | DAT/resource names | `STAFF.EPF`, `NPAL8.PAL`, `STAFFS`, and `STAFFS2`. |

## Source Boundary Split

| Evidence bucket | Address | Corrected source-layout decision |
| --- | --- | --- |
| constructor/virtual-method span | `0x004ffaa0`, `0x004ffd20` | Keep in `login/StaffsDialogPane.cpp`; [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) emits the exact constructor and `OnControlCommand` bodies. No authored global publish or explicit destructor body remains. |
| Singleton base destructor | `0x00502410` | Compiler-generated direct `Singleton<StaffsDialogPane>` base destruction used by constructor unwind; clears the global because the empty base is at `+0x26c`. It is documented, ignored, and non-emitting rather than a handwritten helper. |
| destructor thunk evidence | `0x00502592`, `0x0050259d` | Keep as compiler-generated destructor adjustor thunks in [UID:0000VN][-ignored](by-memory/-ignored.md); both thunks are live vtable targets. |
| scalar deleting wrapper | `0x00502cc0-0x00502d05` | Compiler-generated implicit destruction, DialogPane teardown, flags/guard/free behavior, and Singleton clear. No unique authored destructor statement exists. |
| vtables/RTTI | `[0x0061d930,0x0061d9cc)`, RTTI `[0x0064a7f0,0x0064a8cc)` | Exact physical UID0004VJ and semantic UID0004VK document generated three-view/RTTI data; the class declaration is the human source cause. |

## Evidence Notes

- 2026-06-06 live IDA MCP `lookup_funcs` confirms `0x004ffaa0` size `0x27d`, `0x004ffd20` size `0x1d`, `0x00502410` size `0xb`, `0x00502592` size `0xb`, `0x0050259d` size `0xb`, and `0x00502cc0` size `0x45`.
- Constructor callees include the `DialogPane` constructor, `EPFImageControlPane`, `ImageButtonControlPane`, [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md), frame-rectangle lookup, rectangle setup/offset helpers, and dialog show/slide helpers.
- `xrefs_to 0x0069b490` confirms the singleton is written in the constructor and cleared by `0x00502410` and the scalar deleting destructor.
- `xrefs_to 0x00502592` and `xrefs_to 0x0050259d` show the secondary vtable data refs at `0x0061d994` and `0x0061d9c4`; both thunks forward to the scalar deleting destructor after backing the secondary receiver up by `0xa0` or `0xa4`.
- `xrefs_to 0x004ffd20` shows the action-handler vtable data ref at `0x0061d97c`, and `xrefs_to 0x00502cc0` shows the primary destructor vtable data ref at `0x0061d934`.
- 2026-05-26 recheck confirms `0x00502410` is constructor-unwind cleanup glue and `0x00502592-0x005025a8` are adjustor thunks; these tiny compiler-generated spans are documented but should not become handwritten source methods.
- Some recovered naming still uses broad inherited helper labels such as `MiniMapDialog::LoadDialogResource`, `RankingDialog::SlideOpen`, and `ChattingColorPane::CloseDialog`. Treat those as base/helper label pollution, not evidence that this file belongs with mini-map, ranking, or chat-color sources.
- IDA MCP reports no direct constructor caller in the current database. The source-layout decision is based on resource/parent-pane behavior, not proven live menu action reachability.
- 2026-06-07 A010 Batch077 live IDA refresh reconfirmed the exact staff-resource pointer chain: `0x0066db44` contains `0x0061e484`, the target decodes as UTF-16 `STAFF.EPF`, the target literal is referenced only by that pointer slot, and the pointer has five constructor xrefs at `0x004ffb42`, `0x004ffb72`, `0x004ffb91`, `0x004ffba6`, and `0x004ffcb1` inside `sub_4FFAA0` (`0x004ffaa0`, size `0x27d`).
- 2026-06-16 A002 live IDA MCP refresh against session `b001_maildialogs_0000ZO_20260616` confirms the C001 source-quality names are present in the IDB: `StaffsDialogPane_Constructor` (`0x004ffaa0`, size `0x27d`), `StaffsDialogPane_OnDialogAction` (`0x004ffd20`, size `0x1d`), `StaffsDialogPane_ClearSingletonHelper` (`0x00502410`, size `0xb`), and `StaffsDialogPane_ScalarDeletingDestructor` (`0x00502cc0`, size `0x45`). The two destructor thunks remain real `0xb` functions at `0x00502592` and `0x0050259d`.
- The same refresh reconfirmed zero xrefs to the constructor start, one action-handler vtable xref at `0x0061d97c`, destructor thunk/vtable refs at `0x00502598`, `0x005025a3`, and `0x0061d934`, four `g_pStaffsDialog` lifecycle xrefs at `0x004ffaf6`, `0x004ffafd`, `0x00502410`, and `0x00502cc6`, five `STAFF.EPF` pointer xrefs through `0x0066db44`, and the direct `STAFFS2` / `STAFFS` literal refs at `0x004ffc4b` and `0x004ffc72`.
- Current decompilation shows compiler Singleton publication and three vptr stores around the source constructor body, which creates the `STAFF.EPF`/`NPAL8.PAL` background, centers close button id `14`, calls `EventMan::GetModifierState(unsigned char *)`, selects `STAFFS2` when bit `0x02` is set and `STAFFS` otherwise, attaches through `g_mainUiLayerSlots.overlayPaneLayerContext`, shows through `g_pMainMenuPane`, and starts slide-open. The DialogPane primary `+0x48` contract resolves `0x004ffd20` as `OnControlCommand`; only `controlId == 1` closes/slides and `notifyCode` is ignored.
- 2026-07-03 B014 MCP/local implementation recheck used active session `3a33af0b`; `server_health` was ok and the active IDB path was `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Current `lookup_funcs` reports raw labels for this active IDB rather than the older saved C001 names: `sub_4FFAA0` at `0x004ffaa0` size `0x27d`, `sub_4FFD20` at `0x004ffd20` size `0x1d`, and support functions at `0x00502410`, `0x00502592`, `0x0050259d`, and `0x00502cc0`. The raw-label state is current evidence-state, not a source-owner change.
- The same B014 pass reconfirmed zero constructor xrefs and zero constructor VA/RVA dword or exact rel32 route hits; the action pointer is the vtable data ref at `0x0061d97c`, `g_pStaffsDialog` has four lifecycle refs, `0x0066db44` has five constructor refs, and current singleton storage bytes are `00 00 00 00`.
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) is source-ready with formal constructor/OnControlCommand C++ through this file owner. Direct constructor route remains a confidence cap, not a final-C++ blank/no-route blocker.

## Source Order And One-Definition Union

| Position | UID | Source entity |
| ---: | --- | --- |
| `0` | [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md) | external `StaffsDialogPane *g_pStaffsDialog = NULL;` definition |
| `5` | [UID:0002ZI][StaffsDialogEpfResourcePointer](by-global/StaffsDialogEpfResourcePointer.md) | file-local `static const wchar_t *kStaffsDialogEpfName = L"STAFF.EPF";` |
| `10` | [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md) | complete fieldless DialogPane/Singleton class declaration |
| `20` | [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) | constructor and `OnControlCommand` definitions |

- Physical UID0001PT and UID00027M are non-emitting evidence; compiler UID0001A9/UID0001AE/UID0001AJ/UID0004VJ/UID0004VK are non-emitting generated support.
- This order produces exactly one global, one resource pointer, one class, one constructor, and one `OnControlCommand`, with no explicit destructor or duplicate compiler body.

## Score Rationale

- Completion `92`: full global/resource/class/method source order, exact file path, layout/inheritance, method behavior, compiler/data exclusions, one-definition routing, resource dependencies, and history are complete.
- Confidence `93`: binary, class, resource, and source-family evidence agree. The absent constructor entry route and inferred original lexical spellings remain the only bounded caps.

## Migration Notes

- Keep this page's projected reconstruction path at `NexusTK/login/` unless later original-source evidence proves a different login/main-menu support folder.
- Keep `0x00502410` documented as the compiler-generated `Singleton<StaffsDialogPane>` base-destructor instantiation used by constructor EH cleanup in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Keep `0x0050259d` as a real compiler-generated destructor adjustor thunk instead of treating it as a missing source method; current IDA already models it as a `0xb` function with the expected destructor jump.
- Keep the scrolled text implementation in [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md); this file only selects the staff text resource.
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) carries source-shaped `StaffsDialogPane::StaffsDialogPane()` and `StaffsDialogPane::OnControlCommand(int,int)` C++. Exact current names are `kStaffsDialogEpfName`, literal modifier bit `0x02`, `g_mainUiLayerSlots.overlayPaneLayerContext`, and `g_pMainMenuPane`.
- UID0001AJ remains a blank compiler scalar deleting wrapper. `DialogPane::~DialogPane()` at `0x0049d9f0`, Singleton clear, vptr/base cleanup, `0x004f4ac0` delete/free behavior, guard/no-free flags, and secondary thunks are compiler/base output; no source destructor body is emitted.

## Historical And Superseded Assumptions

- The 2026-06-19 explicit Staffs destructor and 2026-07-03 explicit constructor publish are preserved as superseded implementation history; direct Singleton EBO proves both assignments are compiler/base lowering.
- Historical `OnDialogAction`, `GetCurrentEventFlags`, named event constant, `g_mainUiLayer`, and `g_pMainUiGraph` source spellings are rejected by current base/helper/global contracts.
- Historical broad vtable/destructor ownership remains useful binary provenance but is superseded by exact UID0004VJ/UID0004VK physical/semantic compiler-data pages and implicit destruction.

## Cross-References

- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md)
- [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [UID:0004VJ][0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData](by-memory/0x0061d930-0x0061d9cc.StaffsDialogPaneVtableData.md)
- [UID:0004VK][StaffsDialogPaneVtables](by-type/by-vtable/StaffsDialogPaneVtables.md)

## Changes

- 2026-06-16 A002 file/item completion refresh:
  - Before: `85/86`.
  - Changed to: `86/88`.
  - Summary/evidence: live IDA MCP session `b001_maildialogs_0000ZO_20260616` reconfirmed the C001 IDA names, function sizes, action/destructor vtable refs, destructor thunk refs, singleton lifecycle, `STAFF.EPF` pointer route, `STAFFS2`/`STAFFS` text-resource selector refs, and constructor/action decompilation. The page stays below final-source confidence because direct constructor reachability is still zero-xref in IDA and should not be papered over by the resource evidence.
- Historical/superseded 2026-06-19 B005 destructor interpretation: [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneScalarDeletingDestructor.md) was treated as an `88/90` authored destructor body. The accepted direct-Singleton-base analysis now keeps the wrapper blank/non-emitting and omits any explicit Staffs destructor while preserving the correct `DialogPane::~DialogPane()` identification and compiler adjustor/delete mechanics.
- 2026-07-03 B014 UID00019Z implementation sync: recorded [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) as source-ready/applied with formal constructor/action C++ in this file owner; historical blank-C++/no-route wording is superseded by direct-route-as-confidence-cap. Current MCP session `3a33af0b` reports raw IDA labels, exact constructor/action sizes, no constructor xrefs/routes, action vtable ref `0x0061d97c`, four singleton refs, five `STAFF.EPF` pointer refs, and current `00 00 00 00` singleton bytes.

- 2026-06-07 A010 Batch077 parent-route repair:
  - What existed before: this page was `84/84`, below the corrected `85/85` parent gate needed by [UID:0002ZI][StaffsDialogEpfResourcePointer](by-global/StaffsDialogEpfResourcePointer.md).
  - Changed to: `85/86`.
  - Summary/evidence: live IDA reconfirmed the exact `STAFF.EPF` pointer value, UTF-16 target string, literal-only target xref, and five constructor xrefs inside the StaffsDialogPane constructor. This closes the staff-resource ownership gap enough for the exact global parent to route to `login/StaffsDialogPane.cpp`; confidence remains below final-source quality because ordinary constructor reachability is still absent in the current database.

- 2026-06-06: Raised confidence to `84` after a live IDA MCP cluster recheck confirmed all local function sizes, action/destructor vtable refs, thunk refs, singleton lifetime, and padding around the StaffsDialogPane ranges.
  - Reasoning: the login/main-menu source placement and class ownership are now strongly supported; confidence remains below final-source certainty because the current database still has no ordinary direct constructor caller.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/login/` to resolve the by-file generated-root coverage error.
  - Before: the validator path metadata was blank even though the document and proposed source tree both placed `StaffsDialogPane.cpp` in the login/main-menu support family.
  - After: set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/login/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `StaffsDialogPane.cpp` under `login/`, and live IDA xrefs show [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md) is written/cleared inside the staff dialog lifecycle block.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: initially set completion to `84` and confidence to `80`.
  - Evidence: document captures pre-login dialog role, proposed contents, source-boundary split, IDA function/xref evidence, resource dependencies, migration notes, compiler-thunk exclusions, and cross-references; confidence is capped by exact original path and unresolved reachability through current caller data.
- 2026-07-21 B001 UID0001PT accepted callback: raised to `92/93`, completed the ordered one-definition source union, corrected class/method/global/resource spellings, excluded all compiler-generated lifetime/vtable artifacts, and retained absent constructor reachability as a confidence cap.
