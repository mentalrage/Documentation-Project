*** UID:0001RM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Staff Dialog Resources

## Status

- Confidence: strong for observed names, owner, text-resource switch, `STAFF.EPF` pointer route, current `NPAL8.PAL` package provenance, shared-palette caveat, and staff-specific blocker classification; staff-specific frame/text payload provenance remains open.
- Owner source: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- Owner class: [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)

## Resource Family

| Resource | Role | Rebuild handling |
| --- | --- | --- |
| `STAFF.EPF` | Staff dialog background/layout frame. | Resource-derived frame payload; source should preserve the wide-string name and frame bounds lookup. |
| `NPAL8.PAL` | Palette used by the background image control. | Shared palette resource; staff dialog is a consumer, not necessarily the owner. |
| `STAFFS` | Default scrolled text resource. | Resource-derived text payload selected by the constructor. |
| `STAFFS2` | Alternate scrolled text resource when modifier-state bit `0x02` is set. | Resource-derived alternate text payload selected from `EventMan::GetModifierState(unsigned char *)`. |

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data` and checked the read-only client tree for loose matching files. The shared palette is present in the current package; the staff-specific frame and text resources were not found as DAT entries or loose files in this audited distribution.

| Resource | Package evidence | Payload notes |
| --- | --- | --- |
| `NPAL8.PAL` | `bint2.dat`, entry index `50`, offset `9,161,935`, size `1,056` bytes. | Payload begins with the `DLPalette` header; this confirms the staff constructor's palette operand but keeps it shared across legacy dialog users. |
| `STAFF.EPF` | No matching DAT entry or loose file found in the audited current tree. | Keep the staff frame documented from IDA pointer-route evidence; actual payload provenance remains unresolved. |
| `STAFFS` | No matching DAT entry or loose file found in the audited current tree. | Keep as an IDA-referenced text resource selected by the constructor; payload/source archive remains unresolved. |
| `STAFFS2` | No matching DAT entry or loose file found in the audited current tree. | Keep as an IDA-referenced alternate text resource selected by modifier-state bit `0x02`; payload/source archive remains unresolved. |

## Blocker Classification

2026-06-14 A002 reran the package audit with corrected start-offset DAT parsing, case-insensitive exact-name checks, loose-file search across `E:\2026\Resources`, and a narrow raw-name scan over the read-only client files. `STAFF.EPF`, `STAFFS`, and `STAFFS2` remain absent from DAT entry names and loose resources.

The only exact missing-operand occurrences outside IDA are UTF-16 executable literals in `NexusTK.exe`, `NexusTK2.exe`, and `NexusTK_local.exe`: `STAFF.EPF` at raw offsets `2,215,556` and `2,278,338`, `STAFFS2` at `2,215,576`, and `STAFFS` at `2,215,592` (the `STAFFS2` prefix also naturally matches `STAFFS`). Current DAT substring hits are `DLGSTAFF.epf` / `DLGSTAFF.pal` in `bint1.dat`, but those are forced-inform dialog resources and should not be substituted for this page's staff credits frame/text payloads.

Treat the staff-specific blockers as code-referenced but payload-missing main-menu staff/credits operands in this audited distribution. `NPAL8.PAL` is the only current package payload proven for this page, and it remains shared legacy-dialog palette data.

## Runtime Role Matrix

| Runtime role | Resource inputs | Source behavior to preserve | Boundary notes |
| --- | --- | --- | --- |
| Staff dialog frame | `STAFF.EPF`, `NPAL8.PAL` | Constructor queries the frame bounds, builds the background image control, centers the close button from the frame width, and positions the dialog over the main menu. | `STAFF.EPF` is staff-dialog-specific; `NPAL8.PAL` is shared legacy-dialog palette data. |
| Default staff/credits text | `STAFFS` | Constructor selects this text resource when `EventMan::GetModifierState` returns a byte with bit `0x02` clear and embeds it in `ScrolledTextControlPane`. | Text contents remain DAT/resource payload, not reconstructed C++ string literals. |
| Alternate staff/credits text | `STAFFS2` | Constructor selects this text resource when modifier-state bit `0x02` is set. | The modifier-state branch is source behavior; the alternate text body is resource packaging. |
| Close control | image button id `14`, geometry derived from `STAFF.EPF` | `OnControlCommand(1, notifyCode)` slides closed and closes the dialog. | Button image id and frame-relative placement are source/layout behavior; button art is not owned by this page. |

## Code Evidence

- `StaffsDialogPane::StaffsDialogPane` at `0x004ffaa0` queries `STAFF.EPF` bounds twice, creates an `EPFImageControlPane` over the full frame, and loads the dialog resource.
- The close button rectangle is centered from the `STAFF.EPF` frame width and uses image button id `14`.
- The scrolled text rectangle is approximately `(38, 62)-(230, 305)` and constructs [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md) with scroll speed/value `50`.
- `EventMan::GetModifierState(unsigned char *)` supplies a byte whose literal bit `0x02` switches the text resource from `STAFFS` to `STAFFS2`.
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) now emits formal constructor/action C++ that uses source-facing `kStaffsDialogEpfName`, `L"NPAL8.PAL"`, and the `STAFFS2`/`STAFFS` branch. This source-readiness does not resolve the resource payload provenance blockers for `STAFF.EPF`, `STAFFS`, or `STAFFS2`.

## IDA MCP Evidence

- 2026-06-14 A003 IDA xref refresh confirms the `StaffsDialogPane` constructor at `0x004ffaa0` is `0x27d` bytes and references the staff resources documented here.
- UTF-16 `STAFF.EPF` was verified at `0x0061e484`; the literal has one data xref to pointer slot `0x0066db44`, and that pointer has five constructor xrefs at `0x004ffb42`, `0x004ffb72`, `0x004ffb91`, `0x004ffba6`, and `0x004ffcb1`.
- UTF-16 `STAFFS2` at `0x0061e498` is referenced from `0x004ffc4b` inside `0x004ffaa0-0x004ffd1d`.
- UTF-16 `STAFFS` at `0x0061e4a8` is referenced from `0x004ffc72` inside `0x004ffaa0-0x004ffd1d`.
- UTF-16 `NPAL8.PAL` at `0x0061484c` has sixty observed xrefs; the staff constructor consumer is `0x004ffb65` in `sub_4FFAA0`, supporting the shared legacy-dialog palette boundary.
- IDA decompilation of `0x004ffaa0-0x004ffd1d` shows the `StaffsDialogPane` constructor calling the current `EventMan::GetModifierState` API, selecting `STAFFS2` or `STAFFS` from literal modifier bit `0x02`, and creating the frame, close button, and scrolled text pane.
- `DLGSTAFF.EPF` is a separate ASCII resource literal at `0x0062d9bc` referenced by `0x00587bb0-0x00588073`, supporting the separation from forced-inform dialog resources.

## Source Ownership Notes

Keep these resources with the pre-login/main-menu source family. `DLGSTAFF.EPF` / `DLGSTAFF.PAL` appears in [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) and is a separate staff-themed dialog resource; do not merge it with `StaffsDialogPane` solely by resource-name prefix.

`STAFFS` and `STAFFS2` are content resources, not class names or separate source files. The source-level behavior to rebuild is the event-flag branch that chooses which resource to load into [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md). The actual text payload should remain DAT/resource packaging data.

## Scope Boundaries

- Keep `StaffsDialogPane` in the pre-login/main-menu family; the name "staff" describes a credits/about surface here, not in-game staff administration.
- Keep `DLGSTAFF.EPF` / `DLGSTAFF.PAL` with forced-inform resources. The shared word prefix is not ownership evidence.
- Treat `NPAL8.PAL` as a shared legacy-dialog palette until a dedicated shared-palette inventory assigns final ownership.
- Do not inline `STAFFS` or `STAFFS2` text contents into source reconstruction; only the selector and scrolled-text control setup belong in C++.
- Do not treat missing staff-specific payload files as a constructor C++ blocker. UID00019Z now owns the source-side resource-name selection; this resource page owns the unresolved package/payload provenance.

## Rebuild Notes

- Preserve the `STAFF.EPF`, `STAFFS`, and `STAFFS2` resource-name constants in the staff dialog source or a shared dialog-resource table.
- Let resource packaging supply the `STAFF.EPF` image, `NPAL8.PAL` palette, and `STAFFS`/`STAFFS2` text payloads. Current package parsing proves `NPAL8.PAL`; the staff-specific frame/text payloads still require another distribution, loose resource source, or deeper package-version evidence.
- Do not treat `NPAL8.PAL` as a staff-private palette until its other legacy-dialog users are audited.
- Keep the staff credits page separate from [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md), which owns the mandatory message dialog resources despite the `DLGSTAFF` prefix.

## Score Rationale

- Completion is `87` because the page separates frame/palette/text/close-control roles, records source-versus-resource ownership for each runtime path, gives explicit shared-palette and forced-inform exclusion boundaries, has refreshed IDA xrefs for the `STAFF.EPF` pointer route and `STAFFS`/`STAFFS2` switch, records current `NPAL8.PAL` package provenance, and now classifies the staff-specific frame/text operands as code-literal-only blockers in the audited package.
- Confidence is `92` because fresh IDA evidence supports the owner constructor, `STAFF.EPF` pointer indirection, `STAFFS`/`STAFFS2` switch, one staff-specific `NPAL8.PAL` reference, and current `NPAL8.PAL` package parsing while preserving the shared-palette caveat. The corrected archive/loose/raw scan strengthens the negative staff-specific payload provenance. Confidence remains below final because `STAFF.EPF`, `STAFFS`, `STAFFS2`, event-flag naming, and complete shared-palette ownership are still open.

## Open Questions

- Locate `STAFF.EPF`, `STAFFS`, and `STAFFS2` in another distribution, loose resource source, or undocumented package/version path; they were absent from the audited current DAT entries and loose files.
- Modifier input is closed for source reconstruction as `EventMan::GetModifierState(unsigned char *)` plus literal bit `0x02`; no stronger project enum token is evidenced, and none is required.
- Decide whether `NPAL8.PAL` should be promoted to a shared legacy dialog palette resource page after broader user review.

## Cross-References

- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:00027M][0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer](by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)
- [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md)

## Changes

- 2026-07-21 B001 UID0001PT callback: retained `87/92` and all package/payload provenance limits while synchronizing the closed code-side route. The constructor uses `kStaffsDialogEpfName`, calls `EventMan::GetModifierState(unsigned char *)`, tests literal bit `0x02`, and selects `STAFFS2`/`STAFFS`; close control id `1` routes through `OnControlCommand`. Historical `GetCurrentEventFlags`, invented event-bit enum, and `OnDialogAction` spellings are superseded source guesses, not current blockers.

- What existed before: the page had a strong summary but no score and no explicit current IDA evidence list.
- Changed to: scored `COMPLETION:70` / `CONFIDENCE:86` and added IDA MCP literal/xref/decompilation evidence.
- Summary and evidence: constructor xrefs confirm the staff dialog resource family and the `STAFFS`/`STAFFS2` switch; score remains below final because the resource file contents and all UI geometry details are not exhaustively documented.
- 2026-06-06: Raised scores from `70/86` to `76/88`, added source/payload rebuild boundaries, documented `STAFFS`/`STAFFS2` as DAT text resources selected by event flag state, and recorded shared `NPAL8.PAL` caveats.
  - Before: the page listed the observed resources and constructor evidence but did not distinguish content payloads from source-level selection logic.
  - After: the page explains what must be rebuilt in `StaffsDialogPane.cpp` versus what should remain in resource packaging, while preserving the forced-inform split.
- 2026-06-07 role/boundary pass:
  - What existed before: the page had resource rows and rebuild notes, but did not present frame/palette/text/close-control roles as a runtime matrix or explain the score cap.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, with a runtime role matrix, scope boundaries, current-session IDA availability caveat, and score rationale.
  - Summary/evidence: existing staff file/class/resource docs support the `STAFF.EPF` frame path, shared `NPAL8.PAL` caveat, `STAFFS`/`STAFFS2` event-flag text switch, close-button geometry, and forced-inform split.
- 2026-06-14 A003 score refresh:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:90`, after live IDA MCP reconfirmed the `STAFF.EPF` literal-to-pointer route, five pointer xrefs in `StaffsDialogPane::StaffsDialogPane`, direct `STAFFS2`/`STAFFS` constructor xrefs, and the `NPAL8.PAL` shared-palette xref count with one staff constructor hit.
  - Summary/evidence: the staff credits dialog remains separate from forced-inform `DLGSTAFF.*` resources; DAT provenance, event-flag naming, and final shared-palette ownership remain below-final blockers.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:90`, with IDA evidence but no current package audit.
  - After: raised to `COMPLETION:86`, `CONFIDENCE:91`, with current `bint2.dat` provenance for shared `NPAL8.PAL` and negative current-package/loose-file findings for `STAFF.EPF`, `STAFFS`, and `STAFFS2`.
  - Evidence: fixed-table DAT parsing under `E:\2026\Resources\Read_Only\NexusTK\Data` and loose-file search under the read-only client tree; only `DLGSTAFF.*` forced-inform resources matched the staff substring, reinforcing the separation from this page.
- 2026-06-14 A002 blocker provenance pass:
  - Before: `COMPLETION:86`, `CONFIDENCE:91`, with staff-specific resources absent from the first current-package audit.
  - After: raised to `COMPLETION:87`, `CONFIDENCE:92`, after corrected DAT start-offset parsing, case-insensitive exact-name checks, loose-resource search, and raw client scan confirmed `STAFF.EPF`, `STAFFS2`, and `STAFFS` are present only as UTF-16 executable literals in the packaged executables, not as current DAT or loose payloads; `DLGSTAFF.*` remains explicitly classified as the separate forced-inform family.
- 2026-07-03 B014 UID00019Z implementation sync: recorded that [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) now emits the constructor source behavior using `kStaffsDialogEpfName`, `L"NPAL8.PAL"`, and the `STAFFS2`/`STAFFS` branch. Staff-specific resource payload provenance remains this page's blocker, not a blocker for constructor/action C++.
