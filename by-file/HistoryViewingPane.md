*** UID:0000JW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# HistoryViewingPane

## Status

- Confidence: strong for class contents and main-menu reachability; medium for exact original path.
- Proposed source path: `login/HistoryViewingPane.cpp`
- Proposed header path: `login/HistoryViewingPane.h`
- Main class: [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- Core address range: [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- Support ranges: [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md), [UID:0001A7][0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md), [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md), [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md), [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md)
- Current generated file: `source-3/simroot_v2/class_HistoryViewingPane.cpp`

## File Role

This module should own the full-screen story/history frame viewer opened from the pre-login main menu. It is a `Pane` subclass that displays EPF/EPD frame sequences directly rather than a modal `DialogPane` with controls.

[UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) selects the resource and allocates the viewer; this file owns viewer lifetime, input handling, frame rendering, and its singleton pointer.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `HistoryViewingPane` | `0x004ffd40-0x0050008b`, `0x005023b0`, `0x005024b6-0x005024cc`, `0x00502760-0x005027cc` | Full-screen main-menu story/history frame viewer, including the private [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md). |
| `g_pHistoryViewingPane` | [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md) | Active singleton pointer used by constructor, cleanup helper, destructor, and main-menu singleton cleanup. |
| Resource selector callers | `0x004f7a10`, `0x004f90c0`, `0x004f9140` | Main-menu/menu-helper code that allocates a 264-byte viewer and passes `STORY.*` or `HISTORY.*`. Keep these with `MainMenuPane.cpp` unless later evidence proves file-local wrappers. |

## Current Generated Split

| Current emitted owner | Address | Corrected source-layout decision |
| --- | --- | --- |
| omitted/scattered helper | `0x004ffd40` | Keep as private `HistoryViewingPane` advance-page support called from `OnKeyDown`; it is not BulletinSession. |
| `class_HistoryViewingPane.cpp` | `0x004ffd80`, `0x004fff10`, `0x004fff90`, `0x004fffa0`, `0x00500020`, `0x005024b6`, `0x00502760` | Keep in `login/HistoryViewingPane.cpp`. |
| omitted from active output | `0x005023b0` | Account for as compiler-generated constructor EH cleanup that clears `g_pHistoryViewingPane`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| disabled `class_HistoryViewingPane.cpp` | `0x005024c1` | Keep as a compiler-generated destructor adjustor thunk in [UID:0000VN][-ignored](by-memory/-ignored.md); it is real despite missing generated code. |
| `class_ChattingColorPane.cpp` | `0x004fff10` | Owner pollution. The method body is `HistoryViewingPane::OnKeyDown`, not chat-color UI. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms the core functions and destructor support listed above.
- IDA MCP on 2026-05-26 confirms `0x004ffd40` as a real `0x39`-byte advance helper with the only caller at `0x004fff52` inside `HistoryViewingPane::OnKeyDown`.
- IDA MCP `callers 0x004ffd80` confirms six constructor call sites: four inside `MainMenuPane::ActivateMenuItem` and two menu helper wrappers.
- The two wrapper functions are [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md) and [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md). IDA confirms both are real functions, but direct caller/xref lookup currently returns none.
- The direct main-menu branch uses `STORY.EPF`/`STORY.EPD` for menu item `3` and `HISTORY.EPF`/`HISTORY.EPD` for menu item `4`.
- IDA MCP `xrefs_to 0x0069b494` confirms constructor writes, cleanup-helper/destructor clears, and main-menu cleanup reads.
- IDA MCP `xrefs_to 0x005024b6` and `xrefs_to 0x005024c1` show vtable data refs at `0x0061da1c` and `0x0061da4c`; both thunks call the scalar deleting destructor with `this - 0xa0` or `this - 0xa4`.
- 2026-05-26 recheck confirms `0x005023b0` is constructor-unwind cleanup glue and `0x005024b6-0x005024cc` are adjustor thunks; these tiny compiler-generated spans are documented but should not become handwritten source methods.

## Migration Notes

- Proposed Wave3 source migration after review: set `class_HistoryViewingPane.cpp` simpath to `login/HistoryViewingPane.cpp`.
- Keep `0x005023b0` documented as a constructor EH singleton-clear helper in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Materialize or mark `0x005024c1` as a real compiler-generated thunk instead of missing code.
- Reassign the stray `HistoryViewingPane::OnKeyDown` emission from `class_ChattingColorPane.cpp` back to this class/file.

## Cross-References

- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md)
- [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md)
- [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md)
- [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: main-menu story/history viewer role, singleton ownership, resource selector wrappers, generated split corrections, IDA evidence, migration notes, and resource/menu cross-references are documented; confidence is capped by exact login path and generated ownership caveats.
