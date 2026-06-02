*** UID:0001R5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

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

## Evidence Matrix

| Resource evidence | Concrete support | Remaining limit |
| --- | --- | --- |
| Blue alert frame atlas | [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md) documents `DrawContent` and `DrawBorderFrame` use of `BDFRAME.EPF`, frame indexes `0` through `8`, [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), and broad render callbacks. | The DAT asset payload and original source asset names beyond `BDFRAME.EPF` are not fully reconstructed. |
| Shared OK label | [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md) confirms the inline UTF-16 `OK` string, range end, and broad dialog xrefs. | Final source should decide whether this was a literal, string table entry, or resource macro. |
| Employee warning string | [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) confirms the exact static text range and its AddEmployee caller. | Logical ownership belongs to employee-dialog resources; this page only records it because it is shown through the shared alert flow. |
| Alert ownership | [UID:0000HE][AlertPanes](by-file/AlertPanes.md), [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md), and [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) establish the consuming classes and layout/render context. | Feature-specific alert subclasses are intentionally not collapsed into this shared resource page without caller-specific evidence. |

## Ownership Notes

- `AlertPane` normally builds controls at runtime from the supplied strings and layout reference. It should not be tied to a single DAT dialog layout solely because derived classes may use themed frames.
- `BlueAlertPane` is the concrete owner of the `BDFRAME.EPF` usage documented here.
- Generated `g_uiTileRenderer` calls in `class_BlueAlertPane.cpp` are a data alias artifact over resource lookup and render callback dispatch; do not model this resource as owned by a new renderer singleton without further evidence.
- `UrlAlertPane` owns the URL buffer and action behavior; it only consumes the shared primary-button string.
- `AddEmployeeItemDialog` owns the multi-selection warning behavior, but its `OK` label is the shared dialog string at `0x00613a18`.

## Reconstruction Notes

- Treat this page as a resource/ownership index, not a generated C++ source unit. `by-resource` pages are excluded from reconstruction autogen; any source declarations should be documented on the consuming class, file, memory, or global page.
- Reconstruct `BDFRAME.EPF` usage through the `BlueAlertPane` rendering methods and the central EPF resource registry, not as a standalone alert-local singleton.
- Keep the shared `OK` label separate from employee-dialog behavior. The existing generated callback-table name is a data alias error.
- Keep the employee warning text cross-linked here for alert-flow visibility, but retain feature ownership in [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md).

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 72 | The page now ties each known alert resource/string to concrete memory, class/file owners, exact supporting pages, generated-alias caveats, and reconstruction boundaries. It is still below high completion because DAT packaging, full alert string inventory, and original resource macro/literal strategy remain incomplete. |
| Confidence | 84 | Exact strings, frame filename usage, owner classes, and render/global caveats are backed by existing IDA MCP evidence in the linked pages. Confidence is capped by missing DAT payload audit and unresolved final source representation for shared literals. |

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
- 2026-06-02 resource-boundary pass:
  - What existed before: the page identified the resource rows, but the coverage row was stale and the page did not explain completion/confidence limits.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:84`, with an evidence matrix, reconstruction notes, and score rationale.
  - Summary/evidence: linked AlertPanes, AlertPane, BlueAlertPaneCore, Dialog OK string, AddEmployee warning string, and `g_pEPFLib` docs are sufficient for a stronger resource index while preserving DAT/source-representation caveats.
