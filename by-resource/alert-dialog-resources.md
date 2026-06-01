*** UID:0001R5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Alert Dialog Resources

## Status

- Scope: resources and strings used by shared alert pane classes.
- Confidence: medium.
- Evidence basis: IDA MCP direct UTF-16 decoding and xref checks; generated sources are only lead material.

## Resource Families

| Resource | Observed owner | Notes |
| --- | --- | --- |
| `BDFRAME.EPF` frames `0` through `8` | [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) | Frames `0`, `2`, `5`, and `7` act as corners; `1` and `6` act as horizontal edges; `3` and `4` act as vertical edges; frame `8` fills the content area. IDA shows lookup through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), not a proven alert-local renderer singleton. |
| [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md) at `0x00613a18` | [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md), [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md), many dialog callers | IDA decodes this as UTF-16 `OK` and reports 88 data xrefs. Current generated alias `g_addEmployeeAlertCallbacks` in `class_AddEmployeeItemDialog.cpp` is incorrect; it is a shared button label, not a callback table. |
| [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) | [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) | Korean UTF-16 string shown when more than one inventory item is selected for employee add flow. Keep feature ownership in [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md). |
| dynamic alert text | [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md), [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) | Shared alerts create text controls programmatically instead of using a fixed dialog layout resource. |

## Ownership Notes

- `AlertPane` normally builds controls at runtime from the supplied strings and layout reference. It should not be tied to a single DAT dialog layout solely because derived classes may use themed frames.
- `BlueAlertPane` is the concrete owner of the `BDFRAME.EPF` usage documented here.
- Generated `g_uiTileRenderer` calls in `class_BlueAlertPane.cpp` are a data alias artifact over resource lookup and render callback dispatch; do not model this resource as owned by a new renderer singleton without further evidence.
- `UrlAlertPane` owns the URL buffer and action behavior; it only consumes the shared primary-button string.
- `AddEmployeeItemDialog` owns the multi-selection warning behavior, but its `OK` label is the shared dialog string at `0x00613a18`.

## IDA MCP Evidence

- `BDFRAME.EPF` is a UTF-16 resource string at `0x0061e554`; IDA xrefs place it in `0x00500d70-0x00500e19` and `0x00500e20-0x0050114d`, matching the BlueAlertPane core range.
- `0x00613a18` decodes as UTF-16 `OK`; IDA reports many dialog xrefs, including `0x0046a910-0x0046aa34`, confirming it is a shared dialog label rather than an employee-specific callback table.
- `0x0061929c` decodes as UTF-16 `한번에 여러개를 추가할 수 없습니다.` and xrefs from `0x004a4b20-0x004a4cb1`, matching the AddEmployeeItemDialog warning path.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)

## Changes

- Before: page was scored `0/0` despite having several verified resource/string rows.
- Changed to: `COMPLETION:60`, `CONFIDENCE:80`, with explicit IDA MCP evidence for `BDFRAME.EPF`, shared `OK`, and the employee warning string.
- Evidence: IDA MCP UTF-16 decoding and xrefs from `0x0061e554`, `0x00613a18`, and `0x0061929c`.
