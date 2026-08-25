*** UID:0001RB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Forced Inform Message Resources

## Status

- Confidence: very strong for observed resource names, layout constants, EPF/EPD branch behavior, current-package provenance for the EPF and palette resources, and current constructor-local xrefs; legacy `DLGSTAFF.EPD` packaging remains open.
- Canonical owner source: [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- Owner class: [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)

## Resource Family

| Resource | Role | Rebuild handling |
| --- | --- | --- |
| `DLGSTAFF.EPF` | Newer forced-message dialog background, `318x456`. | Resource-derived payload; source should preserve the wide-string resource name and loader call. |
| `DLGSTAFF.PAL` | Palette for the EPF forced-message dialog. | Resource-derived palette paired with `DLGSTAFF.EPF`. |
| `DLGSTAFF.EPD` | Older forced-message dialog background, `267x367`. | Resource-derived legacy dialog payload. |
| `NPAL8.PAL` | Shared legacy palette for the EPD forced-message dialog. | Shared palette resource; forced-inform is a consumer, not sole owner. |

## Package Provenance

2026-06-14 and 2026-06-16 read-only package audits of `E:\2026\Resources\Read_Only\NexusTK\Data` parsed the documented DAT entry table format across the current 250 DAT archives and checked for loose matching files under `E:\2026\Resources`.

| Resource | Current package evidence |
| --- | --- |
| `DLGSTAFF.EPF` | Found as `DLGSTAFF.epf` in `bint1.dat`, entry index `69`, offset `7,423,504`, size `146,089`; no loose duplicate found. EPF header reports `1` frame of `317x455`, while source code constructs and draws a `(0,0)-(318,456)` extent. |
| `DLGSTAFF.PAL` | Found as `DLGSTAFF.pal` in `bint1.dat`, entry index `70`, offset `7,569,593`, size `1,056`; no loose duplicate found. Header begins with `DLPalette`. |
| `NPAL8.PAL` | Found in `bint2.dat`, entry index `50`, offset `9,161,935`, size `1,056`; no loose duplicate found. Header begins with `DLPalette`, and neighboring `NPAL1.PAL` through `NPAL7.PAL` entries confirm this is part of a shared palette family. |
| `DLGSTAFF.EPD` | Not found as a DAT entry or loose file in the audited current package. UTF-16 executable scans still find the literal in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe` at raw offset `2,278,360`, proving the code operand remains even though the current payload is absent. |

This proves the newer EPF branch payload and both observed palette dependencies in the current client distribution. It does not prove the legacy EPD background payload; keep that branch documented from IDA operands and layout evidence while treating its package provenance as distribution/version dependent.

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
[UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md)
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
- The EPF and EPD branches are both reconstructable UI behavior because they select different asset families and geometry. Current package evidence proves the EPF/palette assets, while the legacy `DLGSTAFF.EPD` payload still needs another distribution or loose-file source.
- Keep the three-level split in rebuilt documentation and packaging: source code owns the literal names and geometry, this resource page owns the resource-family evidence, and DAT/resource packaging owns the image/palette bytes.

## IDA MCP Evidence

- `0x0062d9a0` decodes as UTF-16 `DLGSTAFF.PAL`; xref `0x00587c85` lands in `0x00587bb0-0x00588073`.
- `0x0062d9bc` decodes as UTF-16 `DLGSTAFF.EPF`; xrefs `0x00587c92` and `0x00587e1b` land in `0x00587bb0-0x00588073`.
- `0x0062d9d8` decodes as UTF-16 `DLGSTAFF.EPD`; xrefs `0x00587f04` and `0x00587fe5` land in `0x00587bb0-0x00588073`.
- `0x0061484c` decodes as UTF-16 `NPAL8.PAL`; it is a shared legacy dialog palette with many xrefs, including several dialog helper ranges.
- 2026-06-14 IDA MCP refresh confirmed the core constructor at `0x00587bb0` (`sub_587BB0`, size `0x4c3`) plus non-deleting destructor `0x00588080`, button handler `0x00588110`, key handler `0x00588160`, and scalar deleting destructor `0x0058abf0`.
- The refreshed xref pass confirmed current constructor references for `DLGSTAFF.PAL` (`0x00587c85`), `DLGSTAFF.EPF` (`0x00587c92`, `0x00587e1b`), `DLGSTAFF.EPD` (`0x00587f04`, `0x00587fe5`), and the forced-inform `NPAL8.PAL` hit at `0x00587ef7` among 60 total shared-palette xrefs.
- Decompilation of `0x00587bb0` confirms the `byte_66DA97 == 1` EPF branch builds a centered `318x456` `DLGSTAFF.EPF` / `DLGSTAFF.PAL` dialog, text rect `(25,56)-(300,391)`, Accept rect `(86,419)-(149,443)`, and Decline rect `(163,419)-(226,443)`. The legacy branch builds the fixed `(363,100)-(630,467)` `DLGSTAFF.EPD` / `NPAL8.PAL` dialog with text rect `(39,70)-(230,306)`.
- 2026-06-14 continuation xref check reconfirmed all `DLGSTAFF.*` xrefs are constructor-local: one `DLGSTAFF.PAL` xref, two `DLGSTAFF.EPF` xrefs, and two `DLGSTAFF.EPD` xrefs, all inside `sub_587BB0`. This supports [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) as the direct semantic owner while preserving the shared-palette caveat for `NPAL8.PAL`.
- 2026-06-16 A002 refresh on IDA session `b001_mappane_0001AW_20260616` reconfirmed the same function surface: constructor `0x00587bb0` size `0x4c3`, non-deleting destructor `0x00588080` size `0x81`, button handler `0x00588110` size `0x4d`, key handler `0x00588160` size `0x8d`, and scalar deleting destructor `0x0058abf0` size `0xc2`.
- The same 2026-06-16 xref pass reconfirmed all `DLGSTAFF.*` references are constructor-local: `DLGSTAFF.PAL` at `0x00587c85`, `DLGSTAFF.EPF` at `0x00587c92`/`0x00587e1b`, and `DLGSTAFF.EPD` at `0x00587f04`/`0x00587fe5`. `NPAL8.PAL` still has 60 total xrefs and only one forced-inform constructor hit at `0x00587ef7`, preserving the shared-palette caveat.
- Filtered 2026-06-16 decompilation of `0x00587bb0` reconfirmed source-owned geometry: the EPF branch constructs `(0,0)-(318,456)`, text `(25,56)-(300,391)`, Accept `(86,419)-(149,443)`, Decline `(163,419)-(226,443)`, and centered screen placement; the legacy branch constructs `(0,0)-(267,367)`, text `(39,70)-(230,306)`, and fixed `(363,100)-(630,467)` placement.

## Open Questions

- Find a distribution or loose-resource source for the legacy `DLGSTAFF.EPD` payload; it is referenced by the binary but absent from the audited current package.
- Determine the runtime flag/config state that selects the EPF versus EPD path in source-level terms.
- Audit other `NPAL8.PAL` users before assigning a final shared-palette owner page.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page documents the forced-inform resource family, EPF/EPD geometry, source/resource split, shared `NPAL8.PAL` boundary, `.rdata` placement, SystemMessagePanes exclusion, direct canonical owner, refreshed constructor decompilation/xref counts for both resource branches, current package entries and header evidence for `DLGSTAFF.EPF`, `DLGSTAFF.PAL`, and `NPAL8.PAL`, and repeated negative package/loose evidence for `DLGSTAFF.EPD`. It remains capped because the legacy `DLGSTAFF.EPD` payload, full shared-palette ownership, and final source-level name for the EPF/EPD selector are still open. |
| Confidence | 93 | Current IDA xrefs, decompilation, DAT package parsing, executable raw-name scans, and package header checks confirm the `DLGSTAFF.*` literals, layout constants, EPF branch payload, palette payloads, branch behavior, source owner, and shared-palette caveat. Confidence is capped by the missing current-package `DLGSTAFF.EPD` entry and shared `NPAL8.PAL` ownership outside this consumer. |

## Cross-References

- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md)
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
  - After: the page ties the literals to [UID:00026M][0x0062d5f8-0x0062da10.SystemMessageReadOnlyData](by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md), preserves [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) as the source owner, and leaves final archive provenance open.
- 2026-06-14 A002 Goal2 by-resource score pass:
  - What existed before: `COMPLETION:82` / `CONFIDENCE:88` documented resources, layouts, and ownership boundaries but did not record a current constructor decompilation pass.
  - Changed to: `COMPLETION:85` / `CONFIDENCE:90` after refreshed IDA MCP confirmed function bounds, `DLGSTAFF.*` and `NPAL8.PAL` xrefs, EPF/EPD branch geometry, centered versus fixed placement, button rectangles, and the shared-palette fanout caveat.
  - Remaining below higher score: DAT/archive provenance, full `NPAL8.PAL` owner audit, and final source-level selector naming remain open.
- 2026-06-14 A002 Goal2 continuation:
  - What existed before: `CANONICAL_OWNER:NONE` even though [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) was already the documented source owner and clears the parent gate.
  - Changed to: `COMPLETION:86` / `CONFIDENCE:91` and `CANONICAL_OWNER:0000JJ` after direct xref-count refresh confirmed the `DLGSTAFF.*` resource references are constructor-local to the forced-inform dialog.
  - No emitter or proposed path fields apply to by-resource pages.
- 2026-06-14 A002 resource-payload provenance:
  - What existed before: `COMPLETION:86` / `CONFIDENCE:91` with DAT/archive provenance open for the whole resource family.
  - Changed to: `COMPLETION:87` / `CONFIDENCE:92`.
  - Evidence: current DAT table parsing found `DLGSTAFF.epf` and `DLGSTAFF.pal` in `bint1.dat` and shared `NPAL8.PAL` in `bint2.dat`; no `DLGSTAFF.EPD` DAT entry or loose file was found in the audited client tree, so the legacy branch remains a package blocker.
- 2026-06-16 A002 resource-provenance refresh:
  - Changed from `COMPLETION:87` / `CONFIDENCE:92` to `COMPLETION:88` / `CONFIDENCE:93`.
  - Added current IDA function/xref/decompilation refresh, current package header evidence for the EPF and palette payloads, all-`E:\2026\Resources` loose-file absence checks, and executable raw-offset evidence for the missing `DLGSTAFF.EPD` code operand.
  - Remaining blocker: no current DAT or loose payload has been found for the legacy `DLGSTAFF.EPD` branch, and `NPAL8.PAL` remains a shared palette with broad consumer fanout.
