*** UID:0001RM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Staff Dialog Resources

## Status

- Confidence: strong for observed names, owner, and text-resource switch; exact DAT/source-asset provenance remains open.
- Owner source: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- Owner class: [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)

## Resource Family

| Resource | Role | Rebuild handling |
| --- | --- | --- |
| `STAFF.EPF` | Staff dialog background/layout frame. | Resource-derived frame payload; source should preserve the wide-string name and frame bounds lookup. |
| `NPAL8.PAL` | Palette used by the background image control. | Shared palette resource; staff dialog is a consumer, not necessarily the owner. |
| `STAFFS` | Default scrolled text resource. | Resource-derived text payload selected by the constructor. |
| `STAFFS2` | Alternate scrolled text resource when event flag bit `0x02` is set. | Resource-derived alternate text payload selected by event flag state. |

## Runtime Role Matrix

| Runtime role | Resource inputs | Source behavior to preserve | Boundary notes |
| --- | --- | --- | --- |
| Staff dialog frame | `STAFF.EPF`, `NPAL8.PAL` | Constructor queries the frame bounds, builds the background image control, centers the close button from the frame width, and positions the dialog over the main menu. | `STAFF.EPF` is staff-dialog-specific; `NPAL8.PAL` is shared legacy-dialog palette data. |
| Default staff/credits text | `STAFFS` | Constructor selects this text resource when event flag bit `0x02` is not set and embeds it in `ScrolledTextControlPane`. | Text contents remain DAT/resource payload, not reconstructed C++ string literals. |
| Alternate staff/credits text | `STAFFS2` | Constructor selects this text resource when event flag bit `0x02` is set. | The event-flag branch is source behavior; the alternate text body is resource packaging. |
| Close control | image button id `14`, geometry derived from `STAFF.EPF` | `OnDialogAction` closes/slides the dialog when the close action is received. | Button image id and frame-relative placement are source/layout behavior; button art is not owned by this page. |

## Code Evidence

- `StaffsDialogPane::StaffsDialogPane` at `0x004ffaa0` queries `STAFF.EPF` bounds twice, creates an `EPFImageControlPane` over the full frame, and loads the dialog resource.
- The close button rectangle is centered from the `STAFF.EPF` frame width and uses image button id `14`.
- The scrolled text rectangle is approximately `(38, 62)-(230, 305)` and constructs [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md) with scroll speed/value `50`.
- Event flag bit `0x02` switches the text resource from `STAFFS` to `STAFFS2`.

## IDA MCP Evidence

- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass uses existing IDA-backed staff dialog/resource docs and does not claim a fresh string/xref pass.
- UTF-16 `STAFF.EPF` was verified at `0x0061e484`; it is referenced through [UID:00027M][0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer](by-memory/0x0066db44-0x0066db48.StaffsDialogEpfResourcePointer.md).
- UTF-16 `STAFFS2` at `0x0061e498` is referenced from `0x004ffc4b` inside `0x004ffaa0-0x004ffd1d`.
- UTF-16 `STAFFS` at `0x0061e4a8` is referenced from `0x004ffc72` inside `0x004ffaa0-0x004ffd1d`.
- IDA decompilation of `0x004ffaa0-0x004ffd1d` shows the `StaffsDialogPane` constructor selecting `STAFFS2` or `STAFFS` based on the event flag bit and creating the frame, close button, and scrolled text pane.
- `DLGSTAFF.EPF` is a separate ASCII resource literal at `0x0062d9bc` referenced by `0x00587bb0-0x00588073`, supporting the separation from forced-inform dialog resources.

## Source Ownership Notes

Keep these resources with the pre-login/main-menu source family. `DLGSTAFF.EPF` / `DLGSTAFF.PAL` appears in [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) and is a separate staff-themed dialog resource; do not merge it with `StaffsDialogPane` solely by resource-name prefix.

`STAFFS` and `STAFFS2` are content resources, not class names or separate source files. The source-level behavior to rebuild is the event-flag branch that chooses which resource to load into [UID:0000NI][ScrolledTextControlPane](by-file/ScrolledTextControlPane.md). The actual text payload should remain DAT/resource packaging data.

## Scope Boundaries

- Keep `StaffsDialogPane` in the pre-login/main-menu family; the name "staff" describes a credits/about surface here, not in-game staff administration.
- Keep `DLGSTAFF.EPF` / `DLGSTAFF.PAL` with forced-inform resources. The shared word prefix is not ownership evidence.
- Treat `NPAL8.PAL` as a shared legacy-dialog palette until a dedicated shared-palette inventory assigns final ownership.
- Do not inline `STAFFS` or `STAFFS2` text contents into source reconstruction; only the selector and scrolled-text control setup belong in C++.

## Rebuild Notes

- Preserve the `STAFF.EPF`, `STAFFS`, and `STAFFS2` resource-name constants in the staff dialog source or a shared dialog-resource table.
- Let resource packaging supply the `STAFF.EPF` image, `NPAL8.PAL` palette, and `STAFFS`/`STAFFS2` text payloads.
- Do not treat `NPAL8.PAL` as a staff-private palette until its other legacy-dialog users are audited.
- Keep the staff credits page separate from [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md), which owns the mandatory message dialog resources despite the `DLGSTAFF` prefix.

## Score Rationale

- Completion is `78` because the page now separates frame/palette/text/close-control roles, records source-versus-resource ownership for each runtime path, and gives explicit shared-palette and forced-inform exclusion boundaries.
- Confidence remains `88` because existing IDA-backed filename/xref/decompile evidence supports the owner and text switch, but the archive/DAT provenance, event-flag name, and shared palette ownership are still open.

## Open Questions

- Confirm which archive/DAT stores `STAFF.EPF`, `STAFFS`, and `STAFFS2`.
- Identify the source-level name of the event flag whose bit `0x02` selects `STAFFS2`.
- Decide whether `NPAL8.PAL` should be promoted to a shared legacy dialog palette resource page after broader user review.

## Cross-References

- [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)
- [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)
- [UID:0001RB][forced-inform-message-resources](by-resource/forced-inform-message-resources.md)

## Changes

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
