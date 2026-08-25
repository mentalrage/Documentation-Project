*** UID:0001R5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Alert Dialog Resources

## Status

- Scope: resources and strings used by shared alert pane classes.
- Confidence: very strong for the known shared resources and owner boundaries; medium for complete DAT/string inventory because corrected package/raw scans still do not locate a `BDFRAME.EPF` payload.
- Evidence basis: IDA MCP direct UTF-16 decoding and xref checks; generated sources are only lead material.
- Canonical owner: [UID:0000HE][AlertPanes](by-file/AlertPanes.md), with feature-owned strings retained on their feature pages.

## Resource Families

| Resource | Observed owner | Notes |
| --- | --- | --- |
| `BDFRAME.EPF` frames `0` through `8` | [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) | Frames `0`, `2`, `5`, and `7` act as corners; `1` and `6` act as horizontal edges; `3` and `4` act as vertical edges; frame `8` fills the content area. IDA shows lookup through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), not a proven alert-local renderer singleton. |
| [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md) at `0x00613a18` | [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md), [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md), many dialog callers | IDA decodes this as UTF-16 `OK` and reports 88 data xrefs. Current generated alias `g_addEmployeeAlertCallbacks` in `class_AddEmployeeItemDialog.cpp` is incorrect; it is a shared button label, not a callback table. |
| [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) | [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) | Korean UTF-16 string shown when more than one inventory item is selected for employee add flow. Keep feature ownership in [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md). |
| dynamic alert text | [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md), [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) | Shared alerts create text controls programmatically instead of using a fixed dialog layout resource. |

## Package Provenance

2026-06-14 read-only package audit of `E:\2026\Resources\Read_Only\NexusTK\Data` parsed the documented DAT entry table format across the current DAT archives and checked for loose matching files under the client tree. No DAT entry or loose file named `BDFRAME.EPF` was found.

Corrected start-offset parsing and a broader raw scan found these nearby frame-like entries, none of which match the `BDFRAME.EPF` operand used by `BlueAlertPane`:

| Resource | Package evidence | Payload evidence |
| --- | --- | --- |
| `DLGFRAME.epf` | `bint1.dat`, entry index `24`, offset `2,132,439`, size `2,178`. | EPF header begins with u16s `(9, 14, 14)`, a small dialog-frame resource, not the blue alert frame atlas by name. |
| `frame.epf` | `bint1.dat`, entry index `78`, offset `7,716,660`, size `794,928`. | EPF header begins with u16s `(1, 1024, 768)`, the full-screen frame background resource, not `BDFRAME.EPF`. |
| `frame.pal` | `bint1.dat`, entry index `79`, offset `8,511,588`, size `1,056`. | Payload begins with `DLPalette`, paired with `frame.epf`. |
| `TOTFRAME.EPF` | `bint2.dat`, entry index `109`, offset `16,205,352`, size `224,716`. | EPF header begins with u16s `(4, 192, 288)`, a separate totem-frame resource. |

`BDFRAME.EPF` appears only as a UTF-16 executable literal at raw offset `2,215,764` in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`; raw `FRAME.EPF` hits at adjacent offsets are substring effects from `BDFRAME.EPF` or separate `FRAME.EPF` literals, not a package match. Keep `BDFRAME.EPF` documented from IDA resource-string and frame-index evidence, but treat actual payload packaging as unresolved for this distribution.

## Boundary Decisions

| Neighboring item | Decision | Evidence |
| --- | --- | --- |
| Browser alert text block `0x00613a20-0x00613ab0` | Exclude from this shared page except for its shared `OK` button dependency. | [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md) proves the `Dispose`, `Navigation Failed`, `Navigation Timeout`, and `Web Board Request Timeout` literals are direct `BrowserPane::OnCommand` strings with one browser xref each. |
| `0x00613a18-0x00613a1e` `OK` | Keep as shared dialog-button text. | [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md) confirms 88 UI xrefs, byte-level UTF-16 storage, and broad alert/dialog constructor use. |
| `BDFRAME.EPF` rendering | Keep resource ownership here, but model code ownership through `BlueAlertPane` and the EPF/render callback infrastructure. | [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md) records frame `0` through `8` selection; [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md) records the generated renderer name as an ignored alias over EPF lookup and surface callbacks. |
| Base `DLGFRAME.EPF` comparison | Keep as a non-owner comparison only. | [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md) is the separate central authority for DialogPane's nine-frame 14x14 `DLGFRAME.EPF`, `DLGFRAME.EPD`, PAL01/NPAL8 pairing, caller inventory, and source-pooling contract. Its exact package match does not resolve the missing `BDFRAME.EPF` payload or move alert ownership. |

## Source/Resource Contract

| Area | Source-owned behavior | Resource-owned data |
| --- | --- | --- |
| Blue alert frame | `BlueAlertPane` owns frame lookup timing, corner/edge/fill selection, stretch/tile placement, and render callback use. | `BDFRAME.EPF` owns the frame pixels for indexes `0` through `8`; the central EPF library owns asset loading/lookup. |
| Shared button label | Alert/dialog constructors own button creation, command IDs, default-action wiring, and layout around the primary button. | `0x00613a18-0x00613a1e` owns the shared UTF-16 `OK` text. The final source may represent it as a literal, resource-table entry, or named string macro, but not as an employee callback table. |
| Feature alert text | Callers such as `AddEmployeeItemDialog`, BrowserPane paths, or URL alert flows own the specific warning/failure text they pass into the shared alert shell. | This page only owns shared alert-shell assets and strings. Feature-owned text ranges remain documented on their by-memory or by-resource owner pages. |
| Dynamic text controls | `AlertPane`, `VersatileAlertPane`, and `UrlAlertPane` own runtime control creation, text placement, URL handling, and modal action behavior. | No fixed alert layout DAT is proven for these shared panes from the current evidence; the dynamic text payload is caller-supplied source data. |

## Evidence Matrix

| Resource evidence | Concrete support | Remaining limit |
| --- | --- | --- |
| Blue alert frame atlas | [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md) documents `DrawContent` and `DrawBorderFrame` use of `BDFRAME.EPF`, frame indexes `0` through `8`, [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), and broad render callbacks. | The current package audit did not find a `BDFRAME.EPF` DAT entry or loose file, so actual payload provenance remains unresolved. |
| Shared OK label | [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md) confirms the inline UTF-16 `OK` string, range end, and broad dialog xrefs. | Final source should decide whether this was a literal, string table entry, or resource macro. |
| Employee warning string | [UID:0001OE][0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText](by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md) confirms the exact static text range and its AddEmployee caller. | Logical ownership belongs to employee-dialog resources; this page only records it because it is shown through the shared alert flow. |
| Alert ownership | [UID:0000HE][AlertPanes](by-file/AlertPanes.md), [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md), and [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) establish the consuming classes and layout/render context. | Feature-specific alert subclasses are intentionally not collapsed into this shared resource page without caller-specific evidence. |

## Ownership Notes

- `AlertPane` normally builds controls at runtime from the supplied strings and layout reference. It should not be tied to a single DAT dialog layout solely because derived classes may use themed frames.
- `BlueAlertPane` is the concrete owner of the `BDFRAME.EPF` usage documented here.
- Generated `g_uiTileRenderer` calls in `class_BlueAlertPane.cpp` are a data alias artifact over resource lookup and render callback dispatch; do not model this resource as owned by a new renderer singleton without further evidence.
- `UrlAlertPane` owns the URL buffer and action behavior; it only consumes the shared primary-button string.
- `AddEmployeeItemDialog` owns the multi-selection warning behavior, but its `OK` label is the shared dialog string at `0x00613a18`.
- Browser/WebBoard failure text uses the alert constructor and the shared `OK` label, but those text literals remain browser-owned source data rather than generic alert resources.
- The shared `OK` string is intentionally cross-cutting: broad xrefs make it a common UI string dependency, not proof that every consuming dialog belongs in this alert-resource page.
- Keep `BDFRAME.EPF` distinct from generic EPF draw helpers. The resource page records the alert frame atlas and consuming panes; render surfaces, clipping, callbacks, and library lookup stay with global/render documentation.
- Keep this alert family distinct from [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md). The latter documents base DialogPane DLGFRAME assets and full PAL01 consumers; this page retains BDFRAME alert ownership, shared `OK` fanout, employee warning boundary, and the unresolved BDFRAME payload blocker.

## Reconstruction Notes

- Treat this page as a resource/ownership index, not a generated C++ source unit. `by-resource` pages are excluded from reconstruction autogen; any source declarations should be documented on the consuming class, file, memory, or global page.
- Reconstruct `BDFRAME.EPF` usage through the `BlueAlertPane` rendering methods and the central EPF resource registry, not as a standalone alert-local singleton.
- Keep the shared `OK` label separate from employee-dialog behavior. The existing generated callback-table name is a data alias error.
- Keep the employee warning text cross-linked here for alert-flow visibility, but retain feature ownership in [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md).

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page ties each known alert resource/string to concrete memory, class/file owners, exact supporting pages, generated-alias caveats, browser-string exclusions, reconstruction boundaries, source/resource contracts for `BDFRAME.EPF`, shared `OK`, caller-owned text, dynamic control creation, current parent-gate support for the shared OK literal, canonical AlertPanes owner routing, refreshed frame-drawing evidence, and corrected negative package/raw evidence for `BDFRAME.EPF` versus nearby frame resources. It remains below high completion because DAT packaging for the exact frame atlas, full alert string inventory, and original resource macro/literal strategy remain incomplete. |
| Confidence | 92 | Exact strings, frame filename usage, owner classes, browser-boundary evidence, render/global caveats, shared `OK` fanout, and current `BDFRAME.EPF` frame lookup/decompilation evidence are backed by IDA MCP. Corrected archive parsing and raw scans strengthen the negative `BDFRAME.EPF` package finding. Confidence is capped because the exact payload is still missing and the final source representation for shared literals remains unresolved. |

## IDA MCP Evidence

- `BDFRAME.EPF` is a UTF-16 resource string at `0x0061e554`; IDA xrefs place it in `0x00500d70-0x00500e19` and `0x00500e20-0x0050114d`, matching the BlueAlertPane core range.
- `0x00613a18` decodes as UTF-16 `OK`; IDA reports many dialog xrefs, including `0x0046a910-0x0046aa34`, confirming it is a shared dialog label rather than an employee-specific callback table.
- 2026-06-11 A005 live IDA MCP reconfirmed [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md) as `.rdata`, `0x6` / 6 bytes, `4f 00 4b 00 00 00`, with 88 xrefs. Representative refs include BrowserPane alert dispatch at `0x0046a910-0x0046aa34` and board/article dialog calls from `0x00471550-0x00471ff1`, preserving shared alert-resource ownership.
- `0x0061929c` decodes as UTF-16 `한번에 여러개를 추가할 수 없습니다.` and xrefs from `0x004a4b20-0x004a4cb1`, matching the AddEmployeeItemDialog warning path.
- 2026-06-14 IDA MCP refresh confirmed `BlueAlertPane` constructor `0x005008c0` (`sub_5008C0`, size `0x364`), content draw helper `0x00500d70` (`sub_500D70`, size `0xa9`), and border draw helper `0x00500e20` (`sub_500E20`, size `0x32d`).
- The refreshed xref pass reports nine `BDFRAME.EPF` references: one content fill reference at `0x00500ded` and eight border-frame references from `0x00500e91` through `0x00501119`. Decompilation confirms frame `8` fills the content area, while frames `0`, `2`, `5`, `7`, `1`, `6`, `3`, and `4` draw the corners and tiled edges through `g_pEPFLib` / historical `dword_67A744`.
- The same refresh reports 88 xrefs to the shared `OK` literal at `0x00613a18` and one xref to the AddEmployee warning string at `0x0061929c`, preserving the shared-label versus feature-owned text boundary.
- 2026-06-14 continuation xref check reconfirmed the first 12 shared `OK` xrefs span BrowserPane alert dispatch and board/article dialog calls, while the AddEmployee warning still has exactly one xref at `0x004a4bc1`. This preserves [UID:0000HE][AlertPanes](by-file/AlertPanes.md) as the shared-shell owner without absorbing BrowserPane or employee feature text.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md)
- [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)

## Changes

- 2026-07-16 B003 UID0003AX bounded support synchronization:
  - Scores `88/92`, owner UID0000HE, and every alert-specific fact remain unchanged.
  - Added an explicit non-owner link to UID0004SY for the separate DLGFRAME package comparison and central PAL01 inventory.
  - Preserved BDFRAME ownership, frame roles, missing-payload blocker, shared OK string, employee warning, Browser feature-string boundary, and source/resource contract.

- Before: page was scored `0/0` despite having several verified resource/string rows.
- Changed to: `COMPLETION:60`, `CONFIDENCE:80`, with explicit IDA MCP evidence for `BDFRAME.EPF`, shared `OK`, and the employee warning string.
- Evidence: IDA MCP UTF-16 decoding and xrefs from `0x0061e554`, `0x00613a18`, and `0x0061929c`.
- 2026-06-02 resource-boundary pass:
  - What existed before: the page identified the resource rows, but the coverage row was stale and the page did not explain completion/confidence limits.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:84`, with an evidence matrix, reconstruction notes, and score rationale.
  - Summary/evidence: linked AlertPanes, AlertPane, BlueAlertPaneCore, Dialog OK string, AddEmployee warning string, and `g_pEPFLib` docs are sufficient for a stronger resource index while preserving DAT/source-representation caveats.
- 2026-06-06: Raised to `COMPLETION:78`, `CONFIDENCE:86` after adding explicit boundary decisions for browser-owned alert text, shared `OK` ownership, and the `BDFRAME.EPF` render path.
  - Before: the page linked the key resources but did not state why adjacent browser alert strings and the generated `g_uiTileRenderer` alias stay outside the shared alert-resource model.
  - After: the page distinguishes shared alert resources from BrowserPane feature literals and keeps `BDFRAME.EPF` resource evidence separate from EPF/render callback implementation ownership.
- 2026-06-07 A002 source/resource contract pass:
  - Before: the page had owner and boundary notes, but did not spell out which behavior belongs to reconstructed source versus which data belongs to alert/shared resources.
  - After: raised to `COMPLETION:80` with a source/resource contract covering `BDFRAME.EPF`, the shared `OK` string, caller-owned feature text, dynamic text controls, and shared-string collision rules.
- 2026-06-11 A005 Batch 204 strict-gate support:
  - Before: `80/86`, enough for a resource index but below the current strict support target for the shared `OK` memory child.
  - After: `85/88`.
  - Evidence: live IDA MCP reconfirmed the `0x00613a18-0x00613a1e` UTF-16 `OK` bytes and 88 xrefs, while [UID:0000HE][AlertPanes](by-file/AlertPanes.md) already clears `85/88`. This page remains a by-resource support document, not an autogen parent.
- 2026-06-14 A002 Goal2 by-resource score pass:
  - What existed before: `COMPLETION:85` / `CONFIDENCE:88` documented the resource boundaries but did not record a current `BDFRAME.EPF` frame-drawing refresh.
  - Changed to: `COMPLETION:86` / `CONFIDENCE:90` after refreshed IDA MCP confirmed BlueAlertPane function bounds, nine `BDFRAME.EPF` xrefs, frame `8` content fill, border frame indices, 88 shared `OK` xrefs, and the AddEmployee warning's single feature-owned xref.
  - Remaining below higher score: DAT payload packaging, full alert string inventory, and final shared-literal source representation remain open.
- 2026-06-14 A002 Goal2 continuation:
  - What existed before: `CANONICAL_OWNER:NONE` even though the page's shared-shell content and [UID:0000HE][AlertPanes](by-file/AlertPanes.md) parent both clear the assignment gate.
  - Changed to: `COMPLETION:87` / `CONFIDENCE:91` and `CANONICAL_OWNER:0000HE` after direct xref refresh reconfirmed the shared `OK` fanout, the single AddEmployee warning xref, and the `BDFRAME.EPF` content/border draw split.
  - No emitter or proposed path fields apply to by-resource pages.
- 2026-06-14 A002 resource-payload provenance:
  - Scores remain `COMPLETION:87` / `CONFIDENCE:91`.
  - Evidence: current DAT table parsing and loose-file search did not find `BDFRAME.EPF` in the audited client tree. The closest package entries are `DLGFRAME.epf`, `frame.epf`, and `TOTFRAME.EPF`, which do not match the BlueAlertPane operand, so the frame-atlas payload remains the blocker for a further score raise.
- 2026-06-14 A002 package-provenance continuation:
  - Before: `COMPLETION:87`, `CONFIDENCE:91`, with negative package evidence but no corrected frame-neighbor details.
  - After: raised to `COMPLETION:88`, `CONFIDENCE:92`, after corrected DAT parsing recorded `DLGFRAME.epf`, `frame.epf`/`.pal`, and `TOTFRAME.EPF` payload headers while confirming `BDFRAME.EPF` is only a UTF-16 executable literal in the audited distribution, not a current DAT or loose payload.
