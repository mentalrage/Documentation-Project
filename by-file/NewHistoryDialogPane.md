*** UID:0000LQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewHistoryDialogPane

## Status

- Confidence: strong for class contents, source-family placement, singleton/resource ownership, and support ranges; medium-high for direct constructor reachability.
- Proposed module folder: `login/`
- Proposed source file: `login/NewHistoryDialogPane.cpp`
- Proposed header file: `login/NewHistoryDialogPane.h`
- Main class: [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- Core address range: [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- Support ranges: [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear.md), [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md), [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md), [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- Evidence basis: 2026-06-04 live IDA MCP function, xref, vtable, disassembly, string/data, and byte checks.

## File Role

This module should own the full-screen newer history/credits dialog shown over the pre-login main menu. It is a narrow `DialogPane` subclass that composes a `HISTORYN.EPF` background with a `ScrolledTextControlPaneForMadeBy` loaded from the `MADEBY` text resource.

The scrolling text implementation belongs in [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md). This file only chooses the resources, positions the controls, stores the active singleton, and closes on key or mouse input.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `NewHistoryDialogPane` | `0x00500410-0x00500632`, `0x005023e0`, `0x005024f8-0x0050250e`, `0x00502920-0x00502965` | Full-screen main-menu history/credits dialog and destructor support. |
| `g_pNewHistoryDialog` | [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) | Active singleton pointer used by constructor, clear helper, destructor, and `ScrolledTextControlPaneForMadeBy` end-of-scroll close behavior. |
| `ScrolledTextControlPaneForMadeBy` | `0x004ff400-0x004ff7cc`, `0x0050257c`, `0x00502c10` | Reusable credits-scrolling control consumed here, but owned by `ui/controls/ScrolledTextControlPane.cpp`. |

## Source Ownership Split

| Source-level owner | Address | Handling |
| --- | --- | --- |
| `NewHistoryDialogPane` | `0x00500410`, `0x005005c0`, `0x00500610`, `0x00502920` | Keep as the class constructor, input handlers, and scalar deleting destructor in `login/NewHistoryDialogPane.cpp`. |
| constructor unwind cleanup | `0x005023e0` | Keep documented as compiler/unwind singleton-clear glue in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| destructor adjustor thunks | `0x005024f8`, `0x00502503` | Keep documented as compiler adjustor thunks in [UID:0000VN][-ignored](by-memory/-ignored.md); both are real vtable targets. |

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` confirms `0x00500410` size `0x1a4`, `0x005005c0` size `0x45`, `0x00500610` size `0x22`, `0x005023e0` size `0xb`, `0x005024f8` size `0xb`, `0x00502503` size `0xb`, and `0x00502920` size `0x45`.
- Constructor disassembly writes [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md), installs the three `NewHistoryDialogPane` vtable pointers at `0x0061daf4`, `0x0061db54`, and `0x0061db84`, allocates the image/text children, loads `HISTORYN.EPF`, sets focus mode, creates the full-screen dialog, and shows it with the main-menu parent context.
- String/data checks confirm `HISTORYN.PAL` at `0x0061e4cc`, `HISTORYN.EPF` at `0x0061e4e8`, and the UTF-16LE `MADEBY` resource operand through `off_61E504`.
- `xrefs_to 0x0069b49c` confirms constructor writes, the made-by scrolled-text timer close read at `0x004ff6eb`, singleton clear helper `0x005023e0`, and destructor clear at `0x00502926`.
- `xrefs_to 0x005024f8` and `xrefs_to 0x00502503` show vtable data refs at `0x0061db54` and `0x0061db84`; the thunks jump to `0x00502920` with `this - 0xa0` and `this - 0xa4`.
- Byte checks in [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) split the internal method alignment into `0x005005b4-0x005005c0` and `0x00500605-0x00500610`.
- IDA reports no direct constructor caller in the current database. The source-layout decision is based on live resource/singleton/parent-pane behavior and the established login/main-menu folder in [by-project-structure/proposed-source-tree.md](../by-project-structure/proposed-source-tree.md).

## Reconstruction Notes

- Keep `0x005023e0` documented as a constructor-unwind singleton-clear helper in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Keep `0x005024f8` and `0x00502503` documented as real compiler adjustor thunks rather than handwritten source methods.
- Keep the scrolled credits control in [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md), with this file referencing it as a child control.
- Do not emit final C++ for this module yet: direct constructor reachability and final helper/field names remain below the project bar.

## Score Rationale

The score is raised from `84/78` to `86/84` because the page now has a concrete `NexusTK/login/` projected folder, current live IDA evidence for all class/support functions, vtable ownership, singleton lifecycle, resource operands, and internal padding ownership. It remains below final reconstruction quality because direct constructor reachability is still absent and several helper/field names are provisional.

## Cross-References

- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md)
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents file role, singleton, emitted-owner split, IDA function/xref evidence, migration notes, ignored thunk/EH handling, and cross-references; confidence is capped by live reachability and exact original path uncertainty.
- 2026-06-04: Raised the file page from `84/78` to `86/84` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/login/`.
  - Before: the validator-managed projected path was blank, and the page relied on stale migration/output wording instead of a current source-ownership split.
  - After: the page records the login folder, source/support ownership, exact live function sizes, vtable/singleton/resource evidence, internal padding ownership, and retained direct-constructor reachability caveat.
  - Evidence: 2026-06-04 live IDA MCP `lookup_funcs`, `xrefs_to`, disassembly, vtable dword reads, string/data checks, and `get_bytes` checks recorded here and in [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md).
