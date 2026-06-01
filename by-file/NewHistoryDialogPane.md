*** UID:0000LQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewHistoryDialogPane

## Status

- Confidence: strong for class contents, medium for exact original path and live reachability.
- Proposed source path: `login/NewHistoryDialogPane.cpp`
- Proposed header path: `login/NewHistoryDialogPane.h`
- Main class: [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- Core address range: [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- Support ranges: [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear.md), [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md), [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md), [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- Current generated file: `source-3/simroot_v2/class_NewHistoryDialogPane.cpp`

## File Role

This module should own the full-screen newer history/credits dialog shown over the pre-login main menu. It is a narrow `DialogPane` subclass that composes a `HISTORYN.EPF` background with a `ScrolledTextControlPaneForMadeBy` loaded from the `MADEBY` text resource.

The scrolling text implementation belongs in [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md). This file only chooses the resources, positions the controls, stores the active singleton, and closes on key or mouse input.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `NewHistoryDialogPane` | `0x00500410-0x00500632`, `0x005023e0`, `0x005024f8-0x0050250e`, `0x00502920-0x00502965` | Full-screen main-menu history/credits dialog and destructor support. |
| `g_pNewHistoryDialog` | [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) | Active singleton pointer used by constructor, clear helper, destructor, and `ScrolledTextControlPaneForMadeBy` end-of-scroll close behavior. |
| `ScrolledTextControlPaneForMadeBy` | `0x004ff400-0x004ff7cc`, `0x0050257c`, `0x00502c10` | Reusable credits-scrolling control consumed here, but owned by `ui/controls/ScrolledTextControlPane.cpp`. |

## Current Generated Split

| Current emitted owner | Address | Corrected source-layout decision |
| --- | --- | --- |
| `class_NewHistoryDialogPane.cpp` | `0x00500410`, `0x005005c0`, `0x00500610`, `0x00502920` | Keep in `login/NewHistoryDialogPane.cpp`. |
| omitted from active output | `0x005023e0` | Account for as compiler-generated constructor EH cleanup that clears `g_pNewHistoryDialog`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| disabled `class_NewHistoryDialogPane.cpp` | `0x005024f8`, `0x00502503` | Keep as compiler-generated destructor adjustor thunks in [UID:0000VN][-ignored](by-memory/-ignored.md); `0x00502503` is real despite missing generated code. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms `0x00500410` size `0x1a4`, `0x005005c0` size `0x45`, `0x00500610` size `0x22`, `0x005023e0` size `0xb`, `0x005024f8` size `0xb`, `0x00502503` size `0xb`, and `0x00502920` size `0x45`.
- Constructor callees include `DialogPane`, `EPFImageControlPane`, `ScrolledTextControlPaneForMadeBy`, focus-mode setup, dialog-resource loading, and dialog show helpers.
- IDA MCP `xrefs_to 0x0069b49c` confirms constructor writes, `ScrolledTextControlPaneForMadeBy::OnTimerEvent` close behavior, singleton clear helper `0x005023e0`, and destructor clear.
- IDA MCP `xrefs_to 0x005024f8` and `xrefs_to 0x00502503` show vtable data refs at `0x0061db54` and `0x0061db84`; both thunks call the scalar deleting destructor with `this - 0xa0` or `this - 0xa4`.
- 2026-05-26 recheck confirms `0x005023e0` is constructor-unwind cleanup glue and `0x005024f8-0x0050250e` are adjustor thunks; these tiny compiler-generated spans are documented but should not become handwritten source methods.
- IDA MCP reports no direct constructor caller in the current database. The source-layout decision is based on resource/parent-pane behavior and imported source naming rather than proven live menu action reachability.

## Migration Notes

- Proposed Wave3 source migration after review: set `class_NewHistoryDialogPane.cpp` simpath to `login/NewHistoryDialogPane.cpp`.
- Keep `0x005023e0` documented as a constructor EH singleton-clear helper in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Materialize or mark `0x00502503` as a real compiler-generated thunk instead of missing code.
- Keep the scrolled credits control in [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md), with this file referencing it as a child control.

## Cross-References

- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents file role, singleton, emitted-owner split, IDA function/xref evidence, migration notes, ignored thunk/EH handling, and cross-references; confidence is capped by live reachability and exact original path uncertainty.
