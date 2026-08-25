*** UID:0001RA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Exchange Dialog Resources

## Status

- Resource family: player exchange/trade dialog UI
- Owner module: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Confidence: very strong from IDA MCP byte-backed resource string decoding, xrefs, constructor analysis, and current DAT payload provenance; source declaration-table ownership remains open.

## Resource Set

| Resource | Observed owner/use | Rebuild handling |
| --- | --- | --- |
| `DLGEXC1.EPF` | Main player exchange dialog layout/background resource loaded by [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). | Resource-derived payload; source should keep the wide-string name and loader call. |
| `DLGEXC1.PAL` | Palette passed when creating the exchange dialog background image. | Resource-derived palette payload paired with `DLGEXC1.EPF`. |

## Dialog Resource Role Matrix

| Runtime use | Resource input | Source-owned behavior | Resource boundary |
| --- | --- | --- | --- |
| Fixed exchange dialog background | `DLGEXC1.EPF` | `ExchangeDialog` constructor creates the fixed `451x371` window, places the lists/buttons/labels/money controls, and loads the dialog resource by name. | The EPF bytes remain packaged resource art/layout data; do not embed decoded image bytes into reconstructed source. |
| Exchange dialog palette | `DLGEXC1.PAL` | Constructor passes the palette name with the background image creation path. | Palette contents remain resource payload paired with the EPF. |
| Offered-item list widgets | none confirmed on this page | `ExchangeItemListPane` draws item rows and text inside the exchange window. | Item glyphs and picker chrome belong to item/image libraries or item dialog resources, not to `DLGEXC1.*`. |
| Cancel/ready alerts | none confirmed on this page | `ExchangeAlertPane` builds text/button modal alerts dynamically for cancel and ready/confirm states. | No fixed exchange alert EPF/PAL is documented here. |

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data` and checked the read-only client tree for loose duplicates. The exchange dialog resource pair is present in the current packaged client as `bint1.dat` entries.

| Resource | Package evidence | Payload evidence |
| --- | --- | --- |
| `DLGEXC1.EPF` | `bint1.dat`, entry index `20`, offset `1,838,194`, size `167,560`; no loose duplicate found in the read-only tree. | EPF header begins with little-endian u16s `(1, 449, 369)`, matching one fixed dialog-background frame for the `451x371` window chrome route. |
| `DLGEXC1.PAL` | `bint1.dat`, entry index `21`, offset `2,005,754`, size `1,056`; no loose duplicate found in the read-only tree. | Palette payload begins with `DLPalette`, matching the paired palette path passed by the constructor. |

## Owner And Boundary Notes

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) owns the fixed trade-window background resource use along with the dialog controls, offered-item list panes, money edit control, and confirmation/cancel alert flow.
- The exchange alert pane itself uses text/button controls and dynamic sizing in current documentation; this page does not currently have evidence for a separate fixed EPF/PAL alert asset.
- Item-picker resources such as `MIXITEM.*`, `1.*`, and `2.*` appear in the broader exchange/item `.rdata` neighborhood but belong with [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) unless later evidence proves the original project grouped item pickers into the exchange source. IDA's interior labels at `0x0061a380`/`0x0061a398` read like `XITEM.*`, but the byte-backed string heads are `MIXITEM.PAL` at `0x0061a37c` and `MIXITEM.EPF` at `0x0061a394`.
- Treat the two `DLGEXC1` string constants as source-declared UI resource names. The actual image/palette payloads are resource-derived and should come from the rebuilt resource packaging, not from hard-coded binary data.

## Rebuild Packaging Boundary

For source reconstruction, keep `DLGEXC1.EPF` and `DLGEXC1.PAL` as the exchange dialog background pair loaded by `ExchangeDialog.cpp`. The source should preserve the filename constants, background creation/load calls, fixed window size, child-control ids, money edit behavior, packet handlers, and alert creation, while resource packaging supplies the EPF/PAL payloads.

Do not use this page to pull in neighboring `MIXITEM.*`, `1.*`, or `2.*` resources. Those strings are adjacent in read-only data because exchange invokes item picker dialogs, but current ownership docs keep picker chrome under [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md). Treat the stale interior `XITEM.*` labels as IDA string-head artifacts until a future IDA cleanup pass can safely retype the UTF-16 data.

## Evidence Notes

- `ExchangeDialog::ExchangeDialog` creates a `451x371` background image with `DLGEXC1.EPF` and `DLGEXC1.PAL`, then loads the same dialog resource through `LoadDialogResource`.
- The layout places action buttons at the bottom, player labels near the top, item-list scroll panes in the middle, and money controls at y=295.
- `ExchangeAlertPane` uses text/button controls and dynamic sizing rather than a fixed EPF resource in current generated output.
- The stale `DL_20` / `DL_20.PAL` names should not be used for this page unless a separate future pass finds another exchange-related resource path that actually references them.

## IDA MCP Evidence

- 2026-06-12 C001 Batch C001-015 IDA MCP recheck: `get_bytes 0x0061a2f0 size 0x40` proves `DLGEXC1.PAL` starts at `0x0061a304`, immediately after the corrected `ExchangeMoneyEditControlPane` tertiary table; `xrefs_to 0x0061a304` reports the `0x004ac9d2` constructor reference.
- `0x0061a304` decodes as UTF-16 `DLGEXC1.PAL`; xref `0x004ac9d2` lands in `0x004ac8a0-0x004ad0aa`.
- `0x0061a31c` decodes as UTF-16 `DLGEXC1.EPF`; xrefs `0x004ac9e2` and `0x004acf8a` land in `0x004ac8a0-0x004ad0aa`.
- The same C001 byte/xref pass proves the neighboring item/mix picker literals are `MIXITEM.PAL` at `0x0061a37c` with xref `0x004af625`, and `MIXITEM.EPF` at `0x0061a394` with xrefs `0x004af632` and `0x004af809`.
- No IDA evidence in this pass supported the previous `DL_20` / `DL_20.PAL` resource names for this page.
- 2026-06-14 A003 IDA MCP refresh on database `a001_goal2_class_batch`: raw `get_bytes` over `0x0061a304-0x0061a34c` confirms the contiguous UTF-16 sequence `DLGEXC1.PAL` at `0x0061a304`, `DLGEXC1.EPF` at `0x0061a31c`, `%s(%s)` at `0x0061a334`, and the next `DLGE...` string head at `0x0061a344` outside this page's two-resource set.
- The same refresh reports `xrefs_to` counts of one for `0x0061a304`, two for `0x0061a31c`, and one for `0x0061a334`; all land in `sub_4AC8A0`. `analyze_function 0x004ac8a0` reports `sub_4AC8A0` size `0x80a`, callers `sub_507C90` and `sub_513A20`, and decompile markers for `aDl_1`/`off_61A304` at the background creation path.

## Score Rationale

- Completion is `88` because the page now documents the two confirmed resources as a dialog background/palette pair, separates source-owned controls and packet/alert behavior from resource payloads, records the corrected `0x0061a304` string boundary, confirms the adjacent `%s(%s)`/next-string boundary, explicitly excludes neighboring item-picker resources, and ties both payload files to exact current `bint1.dat` package entries with EPF/PAL header evidence.
- Confidence is `94` because current IDA `get_bytes`, `xrefs_to`, constructor analysis, and DAT payload inspection strongly support the resource names, xref counts, constructor ownership, package location, and resource-payload type; declaration-table/source ownership is still unresolved.

## Open Questions

- Determine whether the original source declared the resource names inline in `ExchangeDialog.cpp` or through a shared dialog-resource table/macro.
- Revisit item-picker resource ownership only after the `ItemDialogs` resource family has its own page or a broader exchange/item resource split is audited.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)
- [UID:00025A][0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData](by-memory/0x00619d28-0x0061a3c4.ExchangeItemReadOnlyData.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)

## Changes

- Before: resource rows named `DL_20` and `DL_20.PAL`.
- Changed to: `DLGEXC1.EPF` and `DLGEXC1.PAL`; score set to `70/88`.
- Evidence: IDA MCP direct UTF-16 decode and xrefs at `0x0061a304` and `0x0061a31c`.
- 2026-06-06: Raised completion from `70` to `76`, added owner/boundary notes, separated source-declared resource-string handling from resource-derived payloads, and recorded open questions for DAT packaging and possible shared declaration/table ownership.
  - Before: the page named the two confirmed resources but did not distinguish exchange-owned dialog background resources from neighboring item-picker resources or alert text/button controls.
  - After: the page documents that `DLGEXC1.*` belongs to the exchange dialog background path while neighboring item-picker strings stay with item-picker resource review unless later evidence proves otherwise.
- 2026-06-07 role/boundary pass:
  - What existed before: the page identified the confirmed background resources and owner boundaries, but lacked an explicit runtime role matrix, packaging boundary, and score rationale.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, with a dialog resource role matrix, rebuild packaging boundary, current-session IDA availability caveat, and stronger item-picker/alert exclusions.
  - Summary/evidence: existing exchange file/class/memory/resource docs support the `DLGEXC1.EPF`/`.PAL` constructor path, fixed exchange-window controls, dynamic alert behavior, and separate `ItemDialogs` ownership for adjacent item-picker resources.
- 2026-06-12 C001 Batch C001-015:
  - Raised `78/88 -> 80/90`.
  - Summary/evidence: live IDA MCP `get_bytes`/`get_string`/`xrefs_to` confirmed `DLGEXC1.PAL` starts at `0x0061a304`, not at the interior `1.PAL` label, and corrected the neighboring item/mix picker strings from stale interior `XITEM.*` labels to byte-backed `MIXITEM.PAL`/`MIXITEM.EPF` heads.
- 2026-06-14 A003 score refresh:
  - Raised `80/90 -> 85/92`.
  - Summary/evidence: live IDA MCP on `a001_goal2_class_batch` reverified raw bytes, xref counts, the `%s(%s)` adjacent format string, the `0x0061a344` next-string boundary, and `sub_4AC8A0` constructor markers. Remaining work is DAT/source-declaration provenance, not the dialog resource identity.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:92`, with dialog resource identity proven but DAT payload provenance still open.
  - After: raised to `COMPLETION:88`, `CONFIDENCE:94`, with current `bint1.dat` entries for `DLGEXC1.EPF` and `DLGEXC1.PAL`, EPF one-frame `449x369` header evidence, `DLPalette` payload evidence, and no loose duplicate in the read-only tree.
