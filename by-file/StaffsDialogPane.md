*** UID:0000O3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StaffsDialogPane

## Status

- Confidence: strong for class contents, medium for exact original path.
- Proposed source path: `login/StaffsDialogPane.cpp`
- Proposed header path: `login/StaffsDialogPane.h`
- Core address range: [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- Support ranges: [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonClear](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonClear.md), [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md), [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md), [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- Current generated file: `source-3/simroot_v2/class_StaffsDialogPane.cpp`

## File Role

This module should own the pre-login staff/credits dialog shown over the main menu. It is a narrow `DialogPane` subclass, not a reusable UI control module: it creates a `STAFF.EPF` background, a single close button, and a `ScrolledTextControlPane` that reads `STAFFS` or `STAFFS2` text.

The source belongs with the main-menu/login support family because the constructor shows the dialog against `g_pMainMenuPane` and the content is a client/about/credits surface. It should not be grouped with GM/staff gameplay tools solely because of the word "staff".

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `StaffsDialogPane` | `0x004ffaa0-0x004ffd3d`, `0x00502410`, `0x00502592-0x005025a8`, `0x00502cc0-0x00502d05` | Main-menu staff credits dialog, close action, singleton clear/destructor support. |
| `g_pStaffsDialog` | [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md) | Active singleton pointer for the dialog. |
| Staff resources | DAT/resource names | `STAFF.EPF`, `NPAL8.PAL`, `STAFFS`, and `STAFFS2`. |

## Current Generated Split

| Current emitted owner | Address | Corrected source-layout decision |
| --- | --- | --- |
| `class_StaffsDialogPane.cpp` | `0x004ffaa0`, `0x004ffd20`, `0x00502cc0` | Keep in `login/StaffsDialogPane.cpp`. |
| omitted from active output | `0x00502410` | Account for as compiler-generated constructor EH cleanup that clears `g_pStaffsDialog`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| disabled `class_StaffsDialogPane.cpp` | `0x00502592`, `0x0050259d` | Keep as compiler-generated destructor adjustor thunks in [UID:0000VN][-ignored](by-memory/-ignored.md); `0x0050259d` is real despite missing generated code. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms `0x004ffaa0` size `0x27d`, `0x004ffd20` size `0x1d`, `0x00502410` size `0xb`, `0x00502592` size `0xb`, `0x0050259d` size `0xb`, and `0x00502cc0` size `0x45`.
- Constructor callees include the `DialogPane` constructor, `EPFImageControlPane`, `ImageButtonControlPane`, [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md), frame-rectangle lookup, rectangle setup/offset helpers, and dialog show/slide helpers.
- `xrefs_to 0x0069b490` confirms the singleton is written in the constructor and cleared by `0x00502410` and the scalar deleting destructor.
- `xrefs_to 0x00502592` and `xrefs_to 0x0050259d` show the secondary vtable data refs at `0x0061d994` and `0x0061d9c4`; both thunks call the scalar deleting destructor with `this - 0xa0` or `this - 0xa4`.
- 2026-05-26 recheck confirms `0x00502410` is constructor-unwind cleanup glue and `0x00502592-0x005025a8` are adjustor thunks; these tiny compiler-generated spans are documented but should not become handwritten source methods.
- Current generated code still uses broad inherited helper labels such as `MiniMapDialog::LoadDialogResource`, `RankingDialog::SlideOpen`, and `ChattingColorPane::CloseDialog`. Treat those as base/helper label pollution, not evidence that this file belongs with mini-map, ranking, or chat-color sources.
- IDA MCP reports no direct constructor caller in the current database. The source-layout decision is based on resource/parent-pane behavior, not proven live menu action reachability.

## Migration Notes

- Proposed Wave3 source migration after review: set `class_StaffsDialogPane.cpp` simpath to `login/StaffsDialogPane.cpp`.
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
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document captures pre-login dialog role, proposed contents, generated split, IDA function/xref evidence, resource dependencies, migration notes, compiler-thunk exclusions, and cross-references; confidence is capped by exact original path and unresolved reachability through current caller data.
