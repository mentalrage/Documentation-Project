*** UID:0001RB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Forced Inform Message Resources

## Status

- Confidence: strong for observed resource names and layout constants.
- Owner source: [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- Owner class: [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)

## Resource Family

| Resource | Role |
| --- | --- |
| `DLGSTAFF.EPF` | Newer forced-message dialog background, `318x456`. |
| `DLGSTAFF.PAL` | Palette for the EPF forced-message dialog. |
| `DLGSTAFF.EPD` | Older forced-message dialog background, `267x367`. |
| `NPAL8.PAL` | Palette for the EPD forced-message dialog. |

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

## Source Ownership Notes

Do not merge this with [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md). `STAFF.EPF` / `STAFFS` is the staff credits screen; `DLGSTAFF.EPF` / `DLGSTAFF.EPD` is a mandatory accept/decline message dialog.

## IDA MCP Evidence

- `0x0062d9a0` decodes as UTF-16 `DLGSTAFF.PAL`; xref `0x00587c85` lands in `0x00587bb0-0x00588073`.
- `0x0062d9bc` decodes as UTF-16 `DLGSTAFF.EPF`; xrefs `0x00587c92` and `0x00587e1b` land in `0x00587bb0-0x00588073`.
- `0x0062d9d8` decodes as UTF-16 `DLGSTAFF.EPD`; xrefs `0x00587f04` and `0x00587fe5` land in `0x00587bb0-0x00588073`.
- `0x0061484c` decodes as UTF-16 `NPAL8.PAL`; it is a shared legacy dialog palette with many xrefs, including several dialog helper ranges.

## Cross-References

- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md)
- [UID:0001J7][0x00587bb0-0x005881ed.ForcedInformMessageDialogCore](by-memory/0x00587bb0-0x005881ed.ForcedInformMessageDialogCore.md)
- [UID:0001RM][staff-dialog-resources](by-resource/staff-dialog-resources.md)
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md)

## Changes

- Before: page was scored `0/0` despite having concrete resource names and layout notes.
- Changed to: `COMPLETION:70`, `CONFIDENCE:88`, with explicit IDA MCP address/xref evidence.
- Evidence: IDA MCP direct UTF-16 decode and xrefs for `DLGSTAFF.PAL`, `DLGSTAFF.EPF`, `DLGSTAFF.EPD`, and `NPAL8.PAL`.
