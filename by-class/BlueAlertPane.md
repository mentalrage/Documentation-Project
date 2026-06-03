*** UID:00000Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BlueAlertPane

## Status

- Assigned source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md). Live construction reachability is still unresolved, but the class-level source ownership is strong enough for no-code parent attachment.
- Address ranges: [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md), with shared destructor [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) and adjustor thunks [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md).
- Vtables: [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md) at `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70`; exact vtable bytes are split as [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md).
- Layout docs: [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- Current recovered file: `source-3/simroot_v2/class_BlueAlertPane.cpp`
- Confidence: medium.

## Class Purpose

`BlueAlertPane` is a blue-framed alert/dialog variant. It has dynamic alert construction similar to `AlertPane`, custom selected-list frame painting, and custom `BDFRAME.EPF` background/border drawing.

## Class Shape

- Base family: [UID:00000B][AlertPane](by-class/AlertPane.md)-family dialog with three vtable views and shared alert deleting-destructor support.
- Layout state: stores caller layout reference at `+0x26c` and follows [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- Render role: draws blue framed alert/list content from `BDFRAME.EPF` using EPF frame lookup/render callbacks.
- Source placement: attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md), with live construction path still unresolved.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScalarDeletingDestructor` | [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md) | Shared `AlertPane`-family deleting destructor, reused by multiple alert/dialog derived vtables. |
| `AdjustorThunk` | [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks into the shared deleting destructor. |
| `BlueAlertPane` | `0x005008c0-0x00500c24` | IDA shows dynamic text measurement, static text creation, optional button creation, dialog show, slide animation, and layout-reference storage. |
| `HandleActionButton` | `0x00500c30-0x00500c70` | Handles action ids `1` and `2`, dispatches primary/secondary callback slots, and closes the dialog. |
| `DrawSelectedItemFrame` | `0x00500c70-0x00500d6e` | Repaints the pane, fetches the selected list item bounds, and draws a multi-line highlight frame with active/inactive colors. |
| `DrawContent` | `0x00500d70-0x00500e19` | Draws alternate content or fills the body with `BDFRAME.EPF` frame `8` through `g_pEPFLib` frame lookup plus shared render callbacks. |
| `DrawBorderFrame` | `0x00500e20-0x0050114d` | Tiles `BDFRAME.EPF` frames `0` through `7` as corners and edges; generated `g_uiTileRenderer` calls are an alias artifact over `g_pEPFLib` and `dword_69B3E8`. |

## Evidence Notes

- IDA confirms the `0x005008c0` constructor body does not match the current generated prose that claims `DIALOG2.DLG`, parent dimensions, and a single OK button.
- 2026-05-26 IDA MCP vtable pass confirms `BlueAlertPane` primary/secondary/tertiary vtables at `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70`, installed by constructor stores at `0x00500920`, `0x00500926`, and `0x00500930`.
- 2026-05-31 IDA MCP vtable-data recheck confirms [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) as the exact vtable-data child range. `0x0061dd78` is `UserHairSelectControlPane` RTTI and `0x0061dd7c` is the next class vtable start, so the `BlueAlertPane` table does not extend past `0x0061dd78`.
- 2026-05-26 IDA layout pass confirms the same three-view vptr offsets as `AlertPane` and confirms the constructor stores the caller layout reference at `+0x26c`; see [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- 2026-05-26 current-state IDA MCP recheck shows no direct callers or code xrefs for `0x005008c0`, `0x00500c30`, `0x00500c70`, `0x00500d70`, or `0x00500e20`; the four virtual handlers are referenced through the primary vtable only, and the three vtable bases are only stored by the constructor. Treat live construction paths as unresolved.
- `DrawContent` and `DrawBorderFrame` are concrete resource evidence for [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md).
- IDA MCP decompile/disassembly of `0x00500d70` and `0x00500e20` shows `dword_67A744` / [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) frame resolution and render callbacks, not a real `g_uiTileRenderer` singleton.
- 2026-05-26 IDA MCP xrefs show the `0x0048c550` deleting destructor and `0x0048c315`/`0x0048c320` thunks are shared by `AlertPane`, `BlueAlertPane`, `CopyWindow`, `QuitDialog`, and `ClanLeaveConfirmDialog` vtables. Do not treat that island as BlueAlert-only code.

## Data Caveats

- Current generated destructor text still names `TransferReplyAlert` teardown. Treat that as base-owner pollution.
- The generated constructor should be re-emitted or rewritten from IDA before source migration.
- The generated `g_uiTileRenderer` global-data record is now listed in [UID:0000PF][-ignored](by-global/-ignored.md) as a stale alias. Do not make it a source singleton without a later render/global pass proving backing storage.

## Reconstruction Notes

- Attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md) as an assigned/no-code class. The parent file has a valid `NexusTK/ui/dialogs/` reconstruction path and already groups the shared `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane` family from IDA-backed evidence.
- Do not emit class C++ yet. The current generated constructor body is contradicted by IDA evidence, and the final source declaration still needs a constructor rewrite, exact field names, and a live-reachability explanation.
- 2026-06-03 local IDA MCP retry failed at the JSON-RPC transport with `The underlying connection was closed: The connection was closed unexpectedly.` No new live IDA facts were added from that failed query.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md)
- [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md)
- [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)

## Changes

- What existed before: the page contained IDA-based corrections for generated constructor/render aliases and live-reachability caveats; it referenced the vtables only through the type page.
- What it was changed to: the class is marked reconstructable, scores were raised conservatively to `68/80`, and the exact vtable-data child range [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) was added.
- Summary and evidence: vtables, layout stores, render methods, and vtable-data boundaries are now well supported by IDA MCP evidence. Confidence remains below final-source level because current generated constructor prose is wrong and no direct live construction xrefs were found.
- 2026-06-03 parent assignment:
  - What existed before: the class was reconstructable but unassigned even though its likely source file was already documented as [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
  - Changed to: `COMPLETION:72`, `CONFIDENCE:82`, and `AUTOGEN_PARENT_UID:0000HE`, with C++ still blank.
  - Summary/evidence: the AlertPanes page has a valid projected path and IDA-backed shared alert-family grouping. The attachment is limited to source ownership; generated constructor text and live construction reachability remain open.
