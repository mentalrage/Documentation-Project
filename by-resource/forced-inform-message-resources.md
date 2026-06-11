*** UID:0001RB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Forced Inform Message Resources

## Status

- Confidence: strong for observed resource names and layout constants; DAT/source-asset packaging remains open.
- Owner source: [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- Owner class: [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)

## Resource Family

| Resource | Role | Rebuild handling |
| --- | --- | --- |
| `DLGSTAFF.EPF` | Newer forced-message dialog background, `318x456`. | Resource-derived payload; source should preserve the wide-string resource name and loader call. |
| `DLGSTAFF.PAL` | Palette for the EPF forced-message dialog. | Resource-derived palette paired with `DLGSTAFF.EPF`. |
| `DLGSTAFF.EPD` | Older forced-message dialog background, `267x367`. | Resource-derived legacy dialog payload. |
| `NPAL8.PAL` | Shared legacy palette for the EPD forced-message dialog. | Shared palette resource; forced-inform is a consumer, not sole owner. |

## Layout Notes

- EPF mode:
  - background rect `(0,0)-(318,456)`;
  - message text rect `(25,56)-(300,391)`;
  - Accept button rect `(86,419)-(149,443)`;
  - Decline button rect `(163,419)-(226,443)`;
  - dialog centered from `g_screenWidth` / `g_screenHeight`.
- EPD mode:
  - background rect `(0,0)-(267,367)`;
  - message text rect `(39,70)-(230,306)`;
  - dialog fixed around `(363,100)-(630,467)`.

## Binary Placement

The resource literals live in the shared system-message/forced-inform `.rdata`
neighborhood rather than in a separate resource-only island.
[UID:00026M][0x0062d5fc-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5fc-0x0062da10.SystemMessageReadOnlyData.md)
records the forced-inform vtable block at `0x0062d718-0x0062d7b4` and the
trailing resource filename block at `0x0062d978-0x0062da10`, including
`DLGSTAFF.*`. That placement is useful binary evidence, but it does not make
the resources part of the `SystemMessagePanes` source module.

## Source Ownership Notes

Do not merge this with [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md). `STAFF.EPF` / `STAFFS` is the staff credits screen; `DLGSTAFF.EPF` / `DLGSTAFF.EPD` is a mandatory accept/decline message dialog.

The `DLGSTAFF` prefix is resource naming only. [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) owns the modal accept/decline dialog, singleton, and login-teardown behavior, while [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md) owns the main-menu staff/credits screen. `NPAL8.PAL` is shared between old-style dialog surfaces and staff UI consumers, so it should not be duplicated as a forced-inform-private asset in rebuild packaging.

[UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) is a neighboring
social/chat UI source family. It explicitly excludes the forced-inform dialog
despite address adjacency, because the forced-inform constructor/destructors,
singleton, accept/decline behavior, and login-dialog restoration path belong to
the pre-login modal notice workflow.

## Rebuild Notes

- Treat the resource names and fixed layout constants as source-level UI data for `login/ForcedInformMessageDialog.cpp`.
- Treat the EPF/EPD/PAL bytes as resource-derived payloads that should be supplied by rebuilt DAT/resource packaging.
- Keep the supplied message body out of this resource page: the class displays caller/server-supplied text, not a fixed DAT string like the staff credits screen.
- The EPF and EPD branches are both reconstructable UI behavior because they select different asset families and geometry, but final asset provenance still needs DAT/archive review.
- Keep the three-level split in rebuilt documentation and packaging: source code owns the literal names and geometry, this resource page owns the resource-family evidence, and DAT/resource packaging owns the image/palette bytes.

## IDA MCP Evidence

- `0x0062d9a0` decodes as UTF-16 `DLGSTAFF.PAL`; xref `0x00587c85` lands in `0x00587bb0-0x00588073`.
- `0x0062d9bc` decodes as UTF-16 `DLGSTAFF.EPF`; xrefs `0x00587c92` and `0x00587e1b` land in `0x00587bb0-0x00588073`.
- `0x0062d9d8` decodes as UTF-16 `DLGSTAFF.EPD`; xrefs `0x00587f04` and `0x00587fe5` land in `0x00587bb0-0x00588073`.
- `0x0061484c` decodes as UTF-16 `NPAL8.PAL`; it is a shared legacy dialog palette with many xrefs, including several dialog helper ranges.

## Open Questions

- Confirm which DAT/archive families contain `DLGSTAFF.EPF`, `DLGSTAFF.EPD`, `DLGSTAFF.PAL`, and the shared `NPAL8.PAL`.
- Determine the runtime flag/config state that selects the EPF versus EPD path in source-level terms.
- Audit other `NPAL8.PAL` users before assigning a final shared-palette owner page.

## Cross-References

- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- [UID:00026M][0x0062d5fc-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5fc-0x0062da10.SystemMessageReadOnlyData.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- Before: page was scored `0/0` despite having concrete resource names and layout notes.
- Changed to: `COMPLETION:70`, `CONFIDENCE:88`, with explicit IDA MCP address/xref evidence.
- Evidence: IDA MCP direct UTF-16 decode and xrefs for `DLGSTAFF.PAL`, `DLGSTAFF.EPF`, `DLGSTAFF.EPD`, and `NPAL8.PAL`.
- 2026-06-06: Raised completion from `70` to `76`, added rebuild notes, separated resource-derived payloads from source-level string/layout data, documented `NPAL8.PAL` as shared rather than forced-inform-private, and recorded open DAT packaging and EPF/EPD selection questions.
  - Before: the page listed resources and layout constants but did not spell out source/payload boundaries or shared-palette ownership.
  - After: the page documents the forced-inform-specific `DLGSTAFF.*` resources separately from staff credits resources and shared legacy palette use.
- 2026-06-06: Raised completion from `76` to `82` by adding the `.rdata` placement, neighboring `SystemMessagePanes` exclusion, and a stricter source/resource-packaging split.
  - Before: the page documented forced-inform resources and layouts but did not link the `0x0062d978-0x0062da10` filename block or explain why that shared read-only island does not change source ownership.
  - After: the page ties the literals to [UID:00026M][0x0062d5fc-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5fc-0x0062da10.SystemMessageReadOnlyData.md), preserves [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) as the source owner, and leaves final archive provenance open.
