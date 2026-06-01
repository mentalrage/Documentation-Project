*** UID:000091 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewHistoryDialogPane

## Status

- Confidence: strong for class behavior, medium for live entry-point reachability.
- Likely source file: [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- Core address range: [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- Support ranges: [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear.md), [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md), [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md)
- Current recovered source: `source-3/simroot_v2/class_NewHistoryDialogPane.cpp`

## Class Purpose

`NewHistoryDialogPane` is a full-screen pre-login history/credits dialog. It creates a blank [UID:00003T][DialogPane](by-class/DialogPane.md), writes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md), displays a `HISTORYN.EPF` background using `HISTORYN.PAL`, and embeds [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md) over the `MADEBY` text resource.

The dialog closes on Enter, Escape, Space, mouse down, or mouse up. The embedded `ScrolledTextControlPaneForMadeBy` timer also closes `g_pNewHistoryDialog` when the credits text reaches the end.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| Constructor | `0x00500410-0x005005b3` | Builds a full-screen dialog, background image, `MADEBY` scrolled text control, and shows it over `g_pMainMenuPane`. |
| `OnKeyInput` | `0x005005c0-0x00500604` | Closes on Enter, Escape, or Space. |
| `OnMouseInput` | `0x00500610-0x00500632` | Closes on mouse down/up. |
| Singleton clear helper | [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear.md) | Real `0xb` constructor EH cleanup helper that clears `g_pNewHistoryDialog`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md), and currently omitted from active generated output. |
| Adjustor thunks | [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md) | Two real destructor adjustor thunks documented in [UID:0000VN][-ignored](by-memory/-ignored.md). Disabled output emits `0x005024f8` but marks `0x00502503` as missing code. |
| Scalar deleting destructor | [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md) | Clears singleton, chains to `DialogPane` cleanup, and optionally deletes. |

## Resource Notes

- Background/layout resource: `HISTORYN.EPF`.
- Palette: `HISTORYN.PAL`.
- Text resource: `MADEBY`.
- Background/control rectangle: `(0, 0)-(1024, 768)`.
- Scrolled text rectangle: `(614, 156)-(950, 556)`.
- Parent/show target: `g_pMainMenuPane`.

See [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md) for the resource-centered view.

## Evidence Notes

- IDA MCP confirms real function starts at `0x00500410`, `0x005005c0`, `0x00500610`, `0x005023e0`, `0x005024f8`, `0x00502503`, and `0x00502920`.
- IDA MCP reports no direct callers for `0x00500410` in the current database. Treat this as an unresolved reachability question, not proof the class is unused.
- IDA MCP `xrefs_to 0x0069b49c` shows constructor writes, `ScrolledTextControlPaneForMadeBy::OnTimerEvent` close behavior, singleton clear helper `0x005023e0`, and destructor clear.
- IDA MCP `xrefs_to 0x005024f8` and `xrefs_to 0x00502503` show secondary vtable data refs at `0x0061db54` and `0x0061db84`, proving both destructor thunks are real.
- 2026-05-26 recheck: `0x005023e0` and `0x005024f8-0x0050250e` are compiler-generated cleanup/thunk spans, now listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Constructor callees include `DialogPane` construction/show helpers, `EPFImageControlPane`, `ScrolledTextControlPaneForMadeBy`, control insertion, focus mode, and dialog-resource loading.

## Source Layout Decision

Place this in `login/NewHistoryDialogPane.cpp` next to [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md), and [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md). Keep [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md) in the reusable text-control module; this class only composes it for the `HISTORYN`/`MADEBY` screen.

## Cross-References

- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented the constructor, event handlers, singleton helpers, destructor family, resources, and source-layout decision.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: IDA-backed function starts, singleton xrefs, vtable thunk notes, resource names, and UI behavior are recorded; confidence remains below strong because direct constructor reachability is still unresolved.
