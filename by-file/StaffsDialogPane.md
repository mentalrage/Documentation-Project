*** UID:0000O3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StaffsDialogPane

## Status

- Confidence: strong for class contents, staff-resource ownership, and login/main-menu placement; medium for exact original path and current constructor reachability.
- Proposed source path: `login/StaffsDialogPane.cpp`
- Proposed header path: `login/StaffsDialogPane.h`
- Core address range: [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- Support ranges: [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonClear](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonClear.md), [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md), [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md), [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- Projected reconstruction path: `NexusTK/login/StaffsDialogPane.cpp`

## File Role

This module should own the pre-login staff/credits dialog shown over the main menu. It is a narrow `DialogPane` subclass, not a reusable UI control module: it creates a `STAFF.EPF` background, a single close button, and a `ScrolledTextControlPane` that reads `STAFFS` or `STAFFS2` text.

The source belongs with the main-menu/login support family because the constructor shows the dialog against `g_pMainMenuPane` and the content is a client/about/credits surface. It should not be grouped with GM/staff gameplay tools solely because of the word "staff".

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `StaffsDialogPane` | `0x004ffaa0-0x004ffd3d`, `0x00502410`, `0x00502592-0x005025a8`, `0x00502cc0-0x00502d05` | Main-menu staff credits dialog, close action, singleton clear/destructor support. |
| `g_pStaffsDialog` | [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md) | Active singleton pointer for the dialog. |
| `StaffsDialogEpfResourcePointer` | [UID:0002ZI][StaffsDialogEpfResourcePointer](by-global/StaffsDialogEpfResourcePointer.md), [UID:00027M][0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer](by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md) | Source-declared pointer to the UTF-16 `STAFF.EPF` resource literal consumed only by the StaffsDialogPane constructor. |
| Staff resources | DAT/resource names | `STAFF.EPF`, `NPAL8.PAL`, `STAFFS`, and `STAFFS2`. |

## Source Boundary Split

| Evidence bucket | Address | Corrected source-layout decision |
| --- | --- | --- |
| constructor/action/destructor spans | `0x004ffaa0`, `0x004ffd20`, `0x00502cc0` | Keep in `login/StaffsDialogPane.cpp`. |
| constructor cleanup helper | `0x00502410` | Account for as compiler-generated constructor EH cleanup that clears `g_pStaffsDialog`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| destructor thunk evidence | `0x00502592`, `0x0050259d` | Keep as compiler-generated destructor adjustor thunks in [UID:0000VN][-ignored](by-memory/-ignored.md); both thunks are live vtable targets. |

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

## Migration Notes

- Keep this page's projected reconstruction path at `NexusTK/login/` unless later original-source evidence proves a different login/main-menu support folder.
- Keep `0x00502410` documented as a constructor EH singleton-clear helper in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Materialize or mark `0x0050259d` as a real compiler-generated thunk instead of missing code.
- Keep the scrolled text implementation in [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md); this file only selects the staff text resource.

## Cross-References

- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md)
- [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)

## Changes

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
