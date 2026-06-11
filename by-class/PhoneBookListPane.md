*** UID:0000AE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PhoneBookListPane

## Status

- Confidence: strong for ownership, selected-entry behavior, render data layout, vtable placement, and parent source placement; medium-high for final list-base API names.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- Generated recovery hint: `class_PhoneBookListPane.cpp`; use only as a provenance/search hint because the generated body still has owner-polluted casts and incomplete render output.
- Parent attachment: attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), which is `86/80` with `NexusTK/login/` placement; this class has enough exact memory/helper/vtable evidence to satisfy the 80/80 parent gate.
- Reconstruction status: no final C++ emitted. The render routine, list-base API names, selected-entry method spelling, and contact-entry field names remain below the 95+ source gate.

## Class Purpose

`PhoneBookListPane` displays terminal phone-book contacts and forwards selected-entry activation back to the owning `PhoneBookDialog`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetSelectedEntryData` | [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) | Copies selected contact name/number from the list entry and returns the entry flag byte. |
| `DialSelectedEntry` | `0x0058d110-0x0058d11a` | Forwards activation/dial request to the owner [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md). |
| `RenderEntry` | `0x0058d120-0x0058d262` | Draws the selected highlight and two contact columns from the entry name/number fields. |

## Evidence Notes

- Current `simroot_v2/class_PhoneBookListPane.cpp` emits [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) at `0x0058cfa0`, but `PhoneBookDialog::OnCommand` still calls the same helper through a polluted `ChattingColorListPane` cast.
- `RenderEntry` is still only a packed struct declaration in the emitted file.
- IDA decompilation of `RenderEntry` confirms the row payload fields at `+0x02` and `+0x82`, ellipsis truncation, palette setup, selected-row highlight, and two-column text drawing.
- The list pane should migrate with `PhoneBookDialog`, not with generic chat or article list code.
- [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md) now records the complete phone-book block as reconstructable `84/84`, attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), with rows for `PhoneBookListPane::DialSelectedEntry` at `0x0058d110-0x0058d11a` and `PhoneBookListPane::RenderEntry` at `0x0058d120-0x0058d262`.
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) has a valid `NexusTK/login/` projected path and treats `PhoneBookListPane` as part of `login/PhoneBookDialog.cpp`, alongside `PhoneBookDialog`, `PhoneEntryDialog`, and `DialDialog`.
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md) places the `PhoneBookListPane` vtable family in the terminal/phone read-only-data block, between `PhoneBookDialog` and `PhoneEntryDialog`.
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md) records a focused helper audit: the selected-entry helper has one direct caller in `PhoneBookDialog::OnCommand`, copies the `+0x02` and `+0x82` wide-string fields, and returns the leading entry flag byte.

## Touched State And Dependencies

| State or dependency | Use |
| --- | --- |
| Phone-book row flag byte at `+0x000` | Returned by `GetSelectedEntryData`; meaning is still a source-name candidate. |
| Contact name at `+0x002` | Copied by the selected-entry helper and drawn by `RenderEntry`. |
| Contact phone number at `+0x082` | Copied by the selected-entry helper, drawn by `RenderEntry`, and used by dial flow. |
| [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md) | Owner dialog calls selected-entry helper and receives activation/dial forwarding. |
| [UID:0000AF][PhoneEntryDialog](by-class/PhoneEntryDialog.md) | Inserts or updates rows displayed by this list pane. |
| [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md) | Places this class's vtables in the terminal phone-book data island. |

## Autogen Status

Attach this class to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) as reconstructable terminal phone-book metadata. Leave C++ blank because `RenderEntry`, list-base APIs, selected-entry field names, and stale generated casts are not final-source quality.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `82` | The page records class role, exact selected-entry/dial/render ranges, parent source module, row-field layout, render/selected-entry behavior, generated owner pollution, vtable-block evidence, touched state, and no-code autogen handling. Completion remains capped by incomplete final render C++ and unresolved source-quality list-entry/list-base names. |
| Confidence `86` | Phone-book ownership is strongly supported by the high-confidence PhoneBookDialog file page, exact phone-book aggregate, selected-entry helper caller/body evidence, terminal/phone read-only vtable placement, and related PhoneEntryDialog/DialDialog flow. Confidence is not higher because final list-pane source names and render helper shape still need a dedicated source-quality pass. |

## Open Questions

- Resolve source-quality names for the row flag byte, contact-entry structure, selected-entry helper, and list-base accessors.
- Reconcile the generated `ChattingColorListPane` / `ArticleListPane` casts in nearby phone-book code with the final `PhoneBookListPane` inheritance or list-base API.
- Reconstruct `RenderEntry` only after its palette/text helpers, truncation behavior, and row-field names are ready for final-source C++.

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000AF][PhoneEntryDialog](by-class/PhoneEntryDialog.md)
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md)
- [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md)
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md)

## Changes

- 2026-06-02:
  - Before: scored `68/72`, reconstructability and parent blank.
  - After: scored `76/84`, marked reconstructable, and attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) with C++ blank.
  - Why: exact phone-book aggregate, selected-entry helper, terminal/phone vtable data, and the high-confidence parent file now prove login phone-book ownership while incomplete generated bodies still block source emission.
- 2026-06-07:
  - Before: scored `76/84` and already attached to the phone-book source parent, but exact list method ranges, touched row fields, vtable helper audit evidence, and final open questions were scattered across linked pages.
  - After: scored `82/86`, kept parent attachment, added exact `DialSelectedEntry`/`RenderEntry` ranges, touched-state table, stronger score rationale, and explicit source-quality blockers.
  - Why: existing IDA-backed docs now prove selected-entry helper boundaries/body/caller, row field offsets `+0x000`, `+0x002`, and `+0x082`, terminal-phone vtable placement, parent file placement, and the add/edit/dial flow through PhoneEntryDialog and PhoneBookDialog. Final C++ remains blank under the 95/95 gate.
- Earlier update:
  - Before: completion/confidence metadata were `0/0` despite selected-entry helper, activation, render behavior, and generated owner-pollution notes.
  - Changed to: `COMPLETION:68` and `CONFIDENCE:72`.
  - Evidence: selected contact copying, dial forwarding, render-entry behavior, row payload fields, and placement with `PhoneBookDialog` are documented; completion/confidence remain moderate because emitted `RenderEntry` is incomplete and helper owner pollution still needs cleanup.
