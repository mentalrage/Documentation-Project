*** UID:00002G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanItemListPane

## Status

- Confidence: strong for constructor, vtable, row parsing, draw, and destructor evidence; medium for final field names and shared text-helper ownership.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)

## Class Purpose

`ClanItemListPane` is the compact item list used by clan item deposit/withdraw dialogs. It decodes item slot records from packet data, stores active slots, adds rows for active items, and draws each row with icon-aware selection and truncated wide text.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanItemListPane` | `0x0048ae70-0x0048b08c` | Initializes list storage, parses packet item count/slot/item-id/name records, converts names to wide text, and adds active rows. |
| raw selected-entry helper | `0x0048b090-0x0048b09e` | Unmodeled helper-shaped island; reads the selected row state, calls the list entry accessor, and returns a byte from the selected entry. |
| `DrawListItem` | `0x0048b0a0-0x0048b1b1` | Draws selected/unselected item row, gets item glyph bounds, truncates display name, and draws wide text. |
| destructor/thunks | `0x0048c2ff`, `0x0048c30a`, `0x0048c510-0x0048c54b` | Vtable thunks and scalar deleting destructor. |
| shared text-fit helper | `0x004ba820-0x004ba8a2` | Shared GrafPort/text dependency that truncates a row label and appends an ellipsis suffix. |
| shared count-fit helper | `0x004ba8b0-0x004ba991` | Shared GrafPort/text dependency that counts visible wide characters fitting a measured width. |

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms modeled function ranges `0x0048ae70-0x0048b08c`, `0x0048b0a0-0x0048b1b1`, adjustor thunks `0x0048c2ff-0x0048c30a` and `0x0048c30a-0x0048c315`, scalar deleting destructor `0x0048c510-0x0048c54b`, and text helpers `0x004ba820-0x004ba8a2` / `0x004ba8b0-0x004ba991`.
- The constructor has one direct caller: `0x0048ab68` inside [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md). That caller creates the clan withdraw item list; the deposit item dialog uses [UID:00008W][MyItemListPane](by-class/MyItemListPane.md) instead.
- Constructor vtable stores are `0x0048aedb -> 0x006161bc`, `0x0048aee1 -> 0x00616244`, and `0x0048aeeb -> 0x00616274`. Primary vtable slot 32 (`0x0061623c`) points to `DrawListItem`; secondary and tertiary destructor slots point to `0x0048c2ff` and `0x0048c30a`.
- Constructor calls include list-pane initialization `0x004f3a50`, packet/string reads through `0x00516030`, `0x00575470`, `0x00575480`, `0x00516220`, `MultiByteToWideChar`, `_wcscpy_s`, and row insertion through `0x004f3c50`.
- The raw island at `0x0048b090-0x0048b09e` has no IDA function, no direct xrefs, and no loaded dword references to its start; it reads `this + 0x134`, calls `0x004f3dc0`, returns the first byte of that row payload, and is kept as non-final class evidence.
- `DrawListItem` calls row-selection and text-state helpers, the surface callback at `dword_69B3FC`, item glyph bounds at `0x004df460`, text truncation at `0x004ba820`, text cursor movement at `0x004b9600`, and wide-text drawing at `0x004bab70`; it also uses the ellipsis literal at `0x0061066c`.
- The text-fit pair remains shared support, not class-owned code. Live caller counts are 21 callers for `0x004ba820` and 4 callers for `0x004ba8b0`, and [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) already attaches it to GrafPort/text layout review.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md)

## Changes

- 2026-05-27: Corrected `DrawListItem` from `0x0048b0a0-0x0048b1b0` to exclusive end `0x0048b1b1`. Evidence: IDA MCP reports `sub_48B0A0` at `0x0048b0a0-0x0048b1b1`, with `retn 0Ch` occupying bytes `0x0048b1ae-0x0048b1b0`.
- Earlier baseline: the page documented item-list parsing/drawing and text-fitting helper caveats, but metadata remained unevaluated.
- Earlier scoring pass: scores were set to `72/80` because constructor/parser, draw method, destructor/thunks, and text-fitting helpers were covered; final helper ownership, entry layout, and font/global naming remained incomplete.
- 2026-06-04: Raised from `72/80` to `82/86`, marked reconstructable, and attached to [UID:0000I9][ClanBank](by-file/ClanBank.md).
  - Before: page had behavior notes but no reconstructable/parent metadata, stale recovered-file provenance, and treated the shared text-fit pair as local methods.
  - After: live IDA evidence records executable identity, exact modeled ranges, raw helper-shaped island status, constructor caller, three vtable stores, draw/destructor vtable slots, constructor parser calls, draw-time item/text helper calls, and shared text-helper caller fanout.
  - Reasoning: this is enough for reconstructable class-level documentation and parent attachment because the [UID:0000I9][ClanBank](by-file/ClanBank.md) parent is already `86/80` with a valid `NexusTK/social/` path. Completion remains below final-code range because field names, raw helper reachability, and shared text helper ownership are not final.
