*** UID:0001RA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Exchange Dialog Resources

## Status

- Resource family: player exchange/trade dialog UI
- Owner module: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Confidence: strong from IDA MCP resource string decoding and xrefs; physical DAT/source-asset provenance remains open.

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

## Owner And Boundary Notes

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md) owns the fixed trade-window background resource use along with the dialog controls, offered-item list panes, money edit control, and confirmation/cancel alert flow.
- The exchange alert pane itself uses text/button controls and dynamic sizing in current documentation; this page does not currently have evidence for a separate fixed EPF/PAL alert asset.
- Item-picker resources such as `XITEM.*`, `1.*`, and `2.*` appear in the broader exchange/item `.rdata` neighborhood but belong with [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) unless later evidence proves the original project grouped item pickers into the exchange source.
- Treat the two `DLGEXC1` string constants as source-declared UI resource names. The actual image/palette payloads are resource-derived and should come from the rebuilt resource packaging, not from hard-coded binary data.

## Rebuild Packaging Boundary

For source reconstruction, keep `DLGEXC1.EPF` and `DLGEXC1.PAL` as the exchange dialog background pair loaded by `ExchangeDialog.cpp`. The source should preserve the filename constants, background creation/load calls, fixed window size, child-control ids, money edit behavior, packet handlers, and alert creation, while resource packaging supplies the EPF/PAL payloads.

Do not use this page to pull in neighboring `XITEM.*`, `1.*`, or `2.*` resources. Those strings are adjacent in read-only data because exchange invokes item picker dialogs, but current ownership docs keep picker chrome under [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md).

## Evidence Notes

- `ExchangeDialog::ExchangeDialog` creates a `451x371` background image with `DLGEXC1.EPF` and `DLGEXC1.PAL`, then loads the same dialog resource through `LoadDialogResource`.
- The layout places action buttons at the bottom, player labels near the top, item-list scroll panes in the middle, and money controls at y=295.
- `ExchangeAlertPane` uses text/button controls and dynamic sizing rather than a fixed EPF resource in current generated output.
- The stale `DL_20` / `DL_20.PAL` names should not be used for this page unless a separate future pass finds another exchange-related resource path that actually references them.

## IDA MCP Evidence

- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass relies on the existing IDA-backed resource strings, owner docs, and memory docs rather than claiming a fresh xref pass.
- `0x0061a304` decodes as UTF-16 `DLGEXC1.PAL`; xref `0x004ac9d2` lands in `0x004ac8a0-0x004ad0aa`.
- `0x0061a31c` decodes as UTF-16 `DLGEXC1.EPF`; xrefs `0x004ac9e2` and `0x004acf8a` land in `0x004ac8a0-0x004ad0aa`.
- No IDA evidence in this pass supported the previous `DL_20` / `DL_20.PAL` resource names for this page.

## Score Rationale

- Completion is `78` because the page now documents the two confirmed resources as a dialog background/palette pair, separates source-owned controls and packet/alert behavior from resource payloads, and explicitly excludes neighboring item-picker resources.
- Confidence remains `88` because existing IDA string/xref evidence strongly supports the resource names and constructor ownership; DAT/archive provenance and declaration-table ownership are still unresolved.

## Open Questions

- Confirm the DAT/archive family that physically stores `DLGEXC1.EPF` and `DLGEXC1.PAL`.
- Determine whether the original source declared the resource names inline in `ExchangeDialog.cpp` or through a shared dialog-resource table/macro.
- Revisit item-picker resource ownership only after the `ItemDialogs` resource family has its own page or a broader exchange/item resource split is audited.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004R][ExchangeDialog](by-class/ExchangeDialog.md)
- [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)
- [UID:00025A][0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData](by-memory/0x00619d2c-0x0061a3c8.ExchangeItemReadOnlyData.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)

## Changes

- Before: resource rows named `DL_20` and `DL_20.PAL`.
- Changed to: `DLGEXC1.EPF` and `DLGEXC1.PAL`; score set to `70/88`.
- Evidence: IDA MCP direct UTF-16 decode and xrefs at `0x0061a304` and `0x0061a31c`.
- 2026-06-06: Raised completion from `70` to `76`, added owner/boundary notes, separated source-declared resource-string handling from resource-derived payloads, and recorded open questions for DAT packaging and possible shared declaration/table ownership.
  - Before: the page named the two confirmed resources but did not distinguish exchange-owned dialog background resources from neighboring item-picker resources or alert text/button controls.
  - After: the page documents that `DLGEXC1.*` belongs to the exchange dialog background path while `XITEM.*`/`1.*`/`2.*` stay with item-picker resource review unless later evidence proves otherwise.
- 2026-06-07 role/boundary pass:
  - What existed before: the page identified the confirmed background resources and owner boundaries, but lacked an explicit runtime role matrix, packaging boundary, and score rationale.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, with a dialog resource role matrix, rebuild packaging boundary, current-session IDA availability caveat, and stronger item-picker/alert exclusions.
  - Summary/evidence: existing exchange file/class/memory/resource docs support the `DLGEXC1.EPF`/`.PAL` constructor path, fixed exchange-window controls, dynamic alert behavior, and separate `ItemDialogs` ownership for adjacent item-picker resources.
