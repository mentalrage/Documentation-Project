*** UID:000091 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewHistoryDialogPane

## Status

- Confidence: strong for class behavior, vtable ownership, resources, singleton lifecycle, and support ranges; medium-high for live entry-point reachability.
- Likely source file: [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- Core address range: [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- Support ranges: [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear.md), [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md), [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md)
- Proposed module: `NexusTK/login/NewHistoryDialogPane.cpp`

## Class Purpose

`NewHistoryDialogPane` is a full-screen pre-login history/credits dialog. It creates a blank [UID:00003T][DialogPane](by-class/DialogPane.md), writes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md), displays a `HISTORYN.EPF` background using `HISTORYN.PAL`, and embeds [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md) over the `MADEBY` text resource.

The dialog closes on Enter, Escape, Space, mouse down, or mouse up. The embedded `ScrolledTextControlPaneForMadeBy` timer also closes `g_pNewHistoryDialog` when the credits text reaches the end.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| Constructor | `0x00500410-0x005005b4` | Builds a full-screen dialog, background image, `MADEBY` scrolled text control, and shows it over `g_pMainMenuPane`. |
| `OnKeyInput` | `0x005005c0-0x00500605` | Closes on Enter, Escape, or Space. |
| `OnMouseInput` | `0x00500610-0x00500632` | Closes on mouse down/up. |
| Singleton clear helper | [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear.md) | Real `0xb` constructor-unwind cleanup helper that clears `g_pNewHistoryDialog`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| Adjustor thunks | [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md) | Two real destructor adjustor thunks documented in [UID:0000VN][-ignored](by-memory/-ignored.md); both are vtable targets and jump to the scalar deleting destructor. |
| Scalar deleting destructor | [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md) | Clears singleton, chains to `DialogPane` cleanup, and optionally deletes. |

## Resource Notes

- Background/layout resource: `HISTORYN.EPF`.
- Palette: `HISTORYN.PAL`.
- Text resource: `MADEBY`.
- Background/control rectangle: `(0, 0)-(1024, 768)`.
- Scrolled text rectangle: `(614, 156)-(950, 556)`.
- Parent/show target: `g_pMainMenuPane`.

See [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md) for the resource-centered view.

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` confirms real function starts and sizes for the constructor (`0x00500410`, `0x1a4`), key handler (`0x005005c0`, `0x45`), mouse handler (`0x00500610`, `0x22`), singleton clear helper (`0x005023e0`, `0xb`), two destructor adjustor thunks (`0x005024f8` and `0x00502503`, each `0xb`), and scalar deleting destructor (`0x00502920`, `0x45`).
- Constructor disassembly writes `g_pNewHistoryDialog`, installs primary and two secondary `NewHistoryDialogPane` vtables, allocates the `HISTORYN.EPF` image pane and `MADEBY` scrolled text pane, loads the dialog resource, enables focus mode, and shows over the main-menu parent context.
- String/data checks confirm `HISTORYN.PAL`, `HISTORYN.EPF`, and the UTF-16LE `MADEBY` operand passed through `off_61E504`.
- `xrefs_to 0x0069b49c` shows constructor writes, `ScrolledTextControlPaneForMadeBy::OnTimerEvent` close behavior, singleton clear helper `0x005023e0`, and destructor clear.
- `xrefs_to 0x005024f8` and `xrefs_to 0x00502503` show secondary vtable data refs at `0x0061db54` and `0x0061db84`, proving both destructor thunks are real.
- IDA reports no direct callers for `0x00500410` in the current database. Treat this as an unresolved reachability question, not proof the class is unused.

## Source Layout Decision

Place this in `NexusTK/login/NewHistoryDialogPane.cpp` next to [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md), and [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md). Keep [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md) in the reusable text-control module; this class only composes it for the `HISTORYN`/`MADEBY` screen.

## Score Rationale

The score is raised from `78/76` to `82/84` because current IDA evidence now confirms function sizes, vtable slots, singleton lifecycle, resource operands, input-close logic, support thunk ownership, and parent file placement at `NexusTK/login/`. It remains below final reconstruction quality because direct constructor reachability and final helper/field names are still unresolved.

## Cross-References

- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented the constructor, event handlers, singleton helpers, destructor family, resources, and source-layout decision.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: IDA-backed function starts, singleton xrefs, vtable thunk notes, resource names, and UI behavior are recorded; confidence remains below strong because direct constructor reachability is still unresolved.
- 2026-06-04: Raised the class page from `78/76` to `82/84`, marked it reconstructable, and attached it to [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md).
  - Before: the page had class behavior and resource notes, but it still had no parent link and lacked the current live vtable/resource/byte-evidence refresh needed for stronger confidence.
  - After: the page records exact live function sizes, singleton and vtable xrefs, resource operands, input-close behavior, support thunk ownership, and the `NexusTK/login/` parent file.
  - Evidence: 2026-06-04 live IDA MCP `lookup_funcs`, `xrefs_to`, disassembly, vtable dword reads, string/data checks, and core byte checks recorded here and in [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md).
