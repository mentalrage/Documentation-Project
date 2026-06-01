*** UID:0001RM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Staff Dialog Resources

## Status

- Confidence: strong for observed names and owner.
- Owner source: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md)
- Owner class: [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md)

## Resource Family

| Resource | Role |
| --- | --- |
| `STAFF.EPF` | Staff dialog background/layout frame. |
| `NPAL8.PAL` | Palette used by the background image control. |
| `STAFFS` | Default scrolled text resource. |
| `STAFFS2` | Alternate scrolled text resource when event flag bit `0x02` is set. |

## Code Evidence

- `StaffsDialogPane::StaffsDialogPane` at `0x004ffaa0` queries `STAFF.EPF` bounds twice, creates an `EPFImageControlPane` over the full frame, and loads the dialog resource.
- The close button rectangle is centered from the `STAFF.EPF` frame width and uses image button id `14`.
- The scrolled text rectangle is approximately `(38, 62)-(230, 305)` and constructs [UID:0000CI][ScrolledTextControlPane](by-class/ScrolledTextControlPane.md) with scroll speed/value `50`.
- Event flag bit `0x02` switches the text resource from `STAFFS` to `STAFFS2`.

## IDA MCP Evidence

- UTF-16 `STAFF.EPF` was verified at `0x0061e484`; it is referenced through the global pointer/data slot at `0x0066db44`.
- UTF-16 `STAFFS2` at `0x0061e498` is referenced from `0x004ffc4b` inside `0x004ffaa0-0x004ffd1d`.
- UTF-16 `STAFFS` at `0x0061e4a8` is referenced from `0x004ffc72` inside `0x004ffaa0-0x004ffd1d`.
- IDA decompilation of `0x004ffaa0-0x004ffd1d` shows the `StaffsDialogPane` constructor selecting `STAFFS2` or `STAFFS` based on the event flag bit and creating the frame, close button, and scrolled text pane.
- `DLGSTAFF.EPF` is a separate ASCII resource literal at `0x0062d9bc` referenced by `0x00587bb0-0x00588073`, supporting the separation from forced-inform dialog resources.

## Source Ownership Notes

Keep these resources with the pre-login/main-menu source family. `DLGSTAFF.EPF` / `DLGSTAFF.PAL` appears in [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) and is a separate staff-themed dialog resource; do not merge it with `StaffsDialogPane` solely by resource-name prefix.

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
