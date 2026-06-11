*** UID:00000B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AlertPane

## Status

- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- Address range: [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md), with shared destructor [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- Vtables: [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- Documentation basis: IDA-confirmed constructor/dismiss/destructor ranges, vtable/layout docs, and the [UID:0000HE][AlertPanes](by-file/AlertPanes.md) source-family page.
- Reconstruction parent: attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md) now that the file page has a valid `NexusTK/ui/dialogs/` source root and clears the parent-side `80/80` gate.
- Confidence: strong.

## Class Purpose

`AlertPane` is the shared modal alert dialog base used across the client. It builds a dynamic `DialogPane` from a message string, an anchor/layout reference, and optional primary/secondary button labels. It handles text measurement, wrapped-height calculation, static-text versus scrollable body selection, default-button setup, centering/clamping to screen bounds, modal-list insertion, and slide-in/slide-out animation.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AlertPane` | `0x0049feb0-0x004a0575` | Constructs a dynamic modal alert with optional buttons and text body. |
| `DismissDialog` | `0x004a0580-0x004a0686` | Handles primary/secondary button ids, animates out if visible, dispatches `OnPrimaryButton` or `OnSecondaryButton`, and dismisses the pane. |
| `ScalarDeletingDestructor` | [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) | Shared alert-family deleting destructor referenced by base and derived alert/dialog vtables. |

## Evidence Notes

- IDA MCP confirms both functions as real starts and shows broad constructor fan-in from many client subsystems.
- 2026-05-26 IDA `py_eval` recheck confirms `0x0049feb0-0x004a0575` constructor size `0x6c5`, `0x004a0580-0x004a0686` dismiss/dispatch size `0x106`, shared destructor `0x0048c550-0x0048c58b`, and adjustor thunks `0x0048c315-0x0048c32b`.
- The same recheck found 96 xrefs to the constructor, reinforcing `AlertPane` as shared UI infrastructure rather than feature-local code.
- 2026-05-26 IDA MCP confirms three `AlertPane` vtable bases at `0x00618b00`, `0x00618b68`, and `0x00618b98`, with constructor stores at `0x0049ff1e`, `0x0049ff24`, and `0x0049ff2e`.
- 2026-05-26 IDA layout pass confirms vptr offsets `+0x00`, `+0xa0`, and `+0xa4`, and confirms the constructor stores the caller layout reference at `+0x26c`; see [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- The constructor calls shared text measurement helpers, creates either `StaticTextControlPane` or a `TextEditPane` inside `ScrollableControlPane` for oversized dialogs, then calls dialog show/modal-list helpers.
- `DismissDialog` accepts only button ids `1` and `2`, matching primary and secondary alert button slots.
- `DismissDialog` dispatches through primary vtable slots `+0x5c` and `+0x60`; the base `AlertPane` table uses no-op/guard entries there, while derived alert classes override them as needed.
- 2026-05-26 IDA MCP xrefs show the shared scalar deleting destructor at `0x0048c550` referenced by `AlertPane`, `BlueAlertPane`, `CopyWindow`, `QuitDialog`, and `ClanLeaveConfirmDialog` vtables. Treat current `boost::exception` / `TransferReplyAlert` teardown labels as type-owner pollution.

## Open Questions

- The exact names of the primary/secondary virtual callbacks should be settled during source rewrite. Current docs use descriptive names rather than committing to final original names.
- Several derived alert wrappers have projected constructor starts in neighboring feature files. They should not be pulled into the base class without feature-specific caller review.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:0002M5][0x00618b00-0x00618ba0.AlertPaneVtableData](by-memory/0x00618b00-0x00618ba0.AlertPaneVtableData.md)
- [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md)
- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)

## Changes

- What existed before: the page contained strong constructor/dismiss/vtable/layout evidence but still had unevaluated `0/0` metadata.
- What it was changed to: scores were set to `82/90`; no ownership change was made.
- Summary and evidence: existing IDA MCP checks confirm function boundaries, broad constructor fan-in, vtable bases, layout offsets, and derived alert dispatch behavior. Remaining uncertainty is mostly final callback naming and derived wrapper boundaries.
- What existed before: the class was documented as reconstructable in prose but validator `RECONSTRUCTABLE` metadata was blank.
- What it was changed to: `RECONSTRUCTABLE` is set to `TRUE`; C++ remains blank because final callback names and derived wrapper boundaries are below the `95+` final-source gate.
- Summary/evidence: 2026-05-31 IDA MCP reconfirmed the class vtable bases, constructor vptr stores, and exact vtable-data child range.
- 2026-06-06 provenance cleanup: replaced the stale recovered-file path with the current IDA/by-* evidence basis. Scores and ownership metadata are unchanged.
- 2026-06-07 parent attachment:
  - Before: the class was reconstructable but parentless even though its likely source file was documented.
  - Changed to: `AUTOGEN_PARENT_UID:0000HE`; final class C++ remains blank.
  - Evidence: [UID:0000HE][AlertPanes](by-file/AlertPanes.md) is now `82/86` with valid `NexusTK/ui/dialogs/` placement and records the base alert family, exact vtable-data children, shared destructor, layout, and feature-specific exclusions. This class remains below the final C++ gate because callback names and source-quality class declaration details still need audit.
