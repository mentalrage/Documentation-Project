*** UID:0000DY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaffsDialogPane

## Status

- Confidence: strong for class behavior, medium for live reachability.
- Likely source file: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- Core address range: [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- Support ranges: [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonClear](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonClear.md), [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md), [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md)
- Source file: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)

## Class Purpose

`StaffsDialogPane` is a pre-login/main-menu credits or staff listing dialog. It builds a blank [UID:00003T][DialogPane](by-class/DialogPane.md), stores `g_pStaffsDialog`, displays a `STAFF.EPF` background using `NPAL8.PAL`, adds a close button, and embeds a [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md) loaded from either `STAFFS` or `STAFFS2`.

The `STAFFS2` variant is selected when event flag bit `0x02` is set. Current evidence ties the dialog to [UID:00007O][MainMenuPane](by-class/MainMenuPane.md) via `g_pMainMenuPane` parent/show state, but IDA MCP reports no direct constructor caller in the current database, so live entry-point reachability remains open.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| Constructor | `0x004ffaa0-0x004ffd1d` | Builds the dialog shell, background image, close button, scrolled staff text, centers it over the main menu, and slides open. |
| `OnDialogAction` | `0x004ffd20-0x004ffd3d` | If action/control id `1` is received, slides closed and closes the dialog. |
| Singleton clear helper | [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonClear](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonClear.md) | Real `0xb` constructor EH cleanup helper that clears `g_pStaffsDialog`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md), not modeled as handwritten source. |
| Adjustor thunks | [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md) | Two real `0xb` destructor adjustor thunks; documented in [UID:0000VN][-ignored](by-memory/-ignored.md), both live vtable targets. |
| Scalar deleting destructor | [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md) | Clears `g_pStaffsDialog`, chains to `DialogPane` cleanup, and conditionally deletes. |

## Resource Notes

- Background/layout resource: `STAFF.EPF`.
- Palette: `NPAL8.PAL`.
- Text resources: `STAFFS` and `STAFFS2`.
- Close button id: `14`.
- Text rectangle: approximately `(38, 62)-(230, 305)`.
- Dialog offset: based on `STAFF.EPF` dimensions, then offset to around x `630`, y `130` before showing over `g_pMainMenuPane`.

See [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md) for the resource-centered view.

## Evidence Notes

- 2026-06-06 live IDA MCP confirms real functions at `0x004ffaa0`, `0x004ffd20`, `0x00502410`, `0x00502592`, `0x0050259d`, and `0x00502cc0`.
- IDA MCP `callees 0x004ffaa0` includes `DialogPane` construction, `EPFImageControlPane`, `ImageButtonControlPane`, `ScrolledTextControlPane` constructor `0x004ff040`, resource frame lookup `0x004d0530`, and `DialogPane` show/slide helpers.
- IDA MCP `xrefs_to 0x0069b490` shows writes/clears from the constructor, the singleton clear helper, and the scalar deleting destructor.
- IDA MCP `xrefs_to 0x0050259d` shows a vtable data xref at `0x0061d9c4`, proving the second thunk is a live compiler-emitted vtable target.
- IDA MCP `xrefs_to 0x004ffd20` reports the action-handler vtable data ref at `0x0061d97c`, and `xrefs_to 0x00502cc0` reports the primary destructor vtable data ref at `0x0061d934` plus the two thunk code refs.
- 2026-05-26 recheck: `0x00502410` and `0x00502592-0x005025a8` are compiler-generated cleanup/thunk spans, now listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- IDA MCP reports no direct callers for the constructor, action handler, or scalar deleting destructor in the current database. Treat this as an open reachability issue rather than proof the dialog is dead.

## Source Layout Decision

Place this in `login/StaffsDialogPane.cpp` next to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md), and other pre-login support dialogs. It is not an in-game social/staff-management dialog; the resource names and parent pane point to a main-menu credit/staff screen.

## Cross-References

- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md)
- [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md)

## Changes

- 2026-06-06: Raised confidence to `84` and attached the class to [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md).
  - Reasoning: live IDA MCP confirms the method family, singleton lifetime, action/destructor vtable refs, destructor thunk code refs, and compiler-helper exclusions; no final reconstruction C++ was added because the class is below the 95/95 gate.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: initially set completion to `86`, confidence to `78`; later raised confidence to `84` after the live vtable/thunk/destructor recheck.
- Evidence: the page documents dialog purpose, source placement, constructor/action/destructor/support ranges, resources, singleton state, IDA xrefs, ignored cleanup/thunk spans, and reachability caveat; confidence remains capped because live constructor reachability is still open.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, action handler, singleton-clear helper, destructor thunks, and scalar deleting destructor at `0x004ffaa0`, `0x004ffd20`, `0x00502410`, `0x00502592`, `0x0050259d`, and `0x00502cc0`. The likely parent file meets 80/80, but class confidence is `78`, so the parent UID stays blank.
