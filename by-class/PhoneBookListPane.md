*** UID:0000AE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PhoneBookListPane

## Status

- Confidence: very strong for ownership, selected-entry behavior, contact row layout, vtable placement, embedded owner back-pointer, and parent source placement; medium-high for final render helper names and adjusted-base hierarchy names.
- Likely source file: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- Address range: [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- Generated recovery hint: `class_PhoneBookListPane.cpp`; use only as a provenance/search hint because the generated body still has owner-polluted casts and incomplete render output.
- Parent attachment: attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), which is `87/86` with `NexusTK/login/` placement under the older attachment gate. The strict Batch 290 route for [UID:0003DR][0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData](by-memory/0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData.md) uses this class as the actual direct parent and does not require assigning the vtable directly to the file page.
- Reconstruction status: [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) now carries first-draft C++ for `PhoneBookListPane::GetSelectedEntryData`. Class-level C++ remains blank until `RenderEntry`, inherited-base declarations, and shared `ListPane` API names are coordinated.

## Class Purpose

`PhoneBookListPane` displays terminal phone-book contacts and forwards selected-entry activation back to the owning `PhoneBookDialog`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Initialize` / setup helper | `0x0058ced0-0x0058cf1d` | Retained no-direct-xref setup helper that initializes list-base geometry, writes `m_ownerDialog` at `+0x14c`, and installs the three `PhoneBookListPane` vtables. |
| `AppendEntry` / `AddEntry` | `0x0058cf20-0x0058cf9a` | Retained no-direct-xref list-side row builder and insert helper for `PhoneBookContactEntry` data. |
| `GetSelectedEntryData` | [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) | Copies selected `PhoneBookContactEntry` name/number fields from the list entry and returns the neutral `entryFlags` byte. |
| `ReplaceSelectedEntryData` | `0x0058cfe0-0x0058d075` | Retained no-direct-xref helper that replaces the selected row from flag/name/number arguments; corrected half-open endpoint includes the `ret 0x0c` byte at `0x0058d074`. |
| `RemoveSelectedEntry` | `0x0058d080-0x0058d08e` | Retained no-direct-xref wrapper around the shared list remove helper for the current selected row. |
| `SaveEntriesToPhoneCfg` | `0x0058d090-0x0058d10e` | Retained no-direct-xref list save helper that opens `PHONE.CFG`, iterates entries, and calls the CRT/runtime formatted-output wrapper twice per row. |
| `DialSelectedEntry` | `0x0058d110-0x0058d11b` | Forwards activation/dial request to the owner [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md); existing inclusive filename convention ends at `0x0058d11a`. |
| `RenderEntry` | `0x0058d120-0x0058d263` | Draws the selected highlight and two contact columns from the entry name/number fields; existing inclusive filename convention ends at `0x0058d262`. |

## Evidence Notes

- Current `simroot_v2/class_PhoneBookListPane.cpp` emits [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) at `0x0058cfa0`, but `PhoneBookDialog::OnCommand` still calls the same helper through a polluted `ChattingColorListPane` cast. B001's 2026-06-17 source-quality pass rejects that generated cast as owner pollution; the method is direct `PhoneBookListPane` logic.
- `RenderEntry` is still only a packed struct declaration in the emitted file.
- IDA decompilation of `RenderEntry` confirms the row payload fields at `+0x02` and `+0x82`, ellipsis truncation, palette setup, selected-row highlight, and two-column text drawing.
- The list pane should migrate with `PhoneBookDialog`, not with generic chat or article list code.
- [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md) now records the complete phone-book block as reconstructable `84/84`, attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), with rows for `PhoneBookListPane::DialSelectedEntry` at `0x0058d110-0x0058d11a` and `PhoneBookListPane::RenderEntry` at `0x0058d120-0x0058d262`.
- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) has a valid `NexusTK/login/` projected path and treats `PhoneBookListPane` as part of `login/PhoneBookDialog.cpp`, alongside `PhoneBookDialog`, `PhoneEntryDialog`, and `DialDialog`.
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md) places the `PhoneBookListPane` vtable family in the terminal/phone read-only-data block, between `PhoneBookDialog` and `PhoneEntryDialog`.
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md) records a focused helper audit: the selected-entry helper has one direct caller in `PhoneBookDialog::OnCommand`, copies the `+0x02` and `+0x82` wide-string fields, and returns the leading entry flag byte.
- 2026-06-12 A003 live IDA MCP `entity_query` over the vtable span reconfirmed the three named `PhoneBookListPane` table heads at `0x0062dbe4`, `0x0062dc6c`, and `0x0062dc9c`, followed immediately by the `PhoneEntryDialog` vtable head at `0x0062dca8`.
- 2026-06-12 `xrefs_to` reported constructor stores to the three list-pane vtable heads at `0x0058c443`, `0x0058c449`, and `0x0058c453`, plus setup-helper stores at `0x0058cefe`, `0x0058cf04`, and `0x0058cf0e`.
- 2026-06-12 constructor disassembly shows the embedded list pane is allocated as `0x150` / 336 bytes, initialized with geometry arguments, assigned primary/adjusted vptrs at offsets `+0`, `+0xa0`, and `+0xa4`, and linked back to the owning `PhoneBookDialog` via `mov [esi+14Ch], edi`; values verified with `int_convert.py`.
- 2026-06-12 slot-target checks tie [UID:0003DR][0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData](by-memory/0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData.md) to this class: `0x0062dc60 -> 0x0058d110` forwards through `[this+0x14c]` to `PhoneBookDialog::DialSelectedEntry`, and `0x0062dc64 -> 0x0058d120` renders the `+0x02` contact name and `+0x82` number fields with column truncation and selected-row highlighting.
- 2026-06-17 B001 source-quality pass resolves the selected-entry helper and row-layout open questions: [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) is now owned/emitted by this class as `PhoneBookListPane::GetSelectedEntryData`; the best row type is `PhoneBookContactEntry { unsigned char entryFlags; wchar_t name[64]; wchar_t phoneNumber[64]; }`; `entryFlags` is deliberately neutral because all checked producers write zero and no checked consumer decodes nonzero bits.
- B007's 2026-06-19 source-quality pass adds retained no-direct-xref helpers before and after [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md): setup `0x0058ced0-0x0058cf1d`, append `0x0058cf20-0x0058cf9a`, replace `0x0058cfe0-0x0058d075`, remove `0x0058d080-0x0058d08e`, and save `0x0058d090-0x0058d10e`. These are source-like list-pane helpers, not padding or compiler glue. Exact padding is `0x0058cf1d-0x0058cf20`, `0x0058cf9a-0x0058cfa0`, `0x0058cfdc-0x0058cfe0`, `0x0058d075-0x0058d080`, `0x0058d08e-0x0058d090`, `0x0058d10e-0x0058d110`, `0x0058d11b-0x0058d120`, and `0x0058d263-0x0058d270`.
- Direct-rel32 evidence supports the split: `0x0058ced0`, `0x0058cf20`, `0x0058cfe0`, `0x0058d080`, and `0x0058d090` have no direct refs to their starts; `0x0058cfa0` has the edit-path caller at `0x0058cd8c`; `0x0058d110` is referenced through the vtable slot at `0x0062dc60`; and `0x0058d120` is referenced through the render slot at `0x0062dc64`.

## Touched State And Dependencies

| State or dependency | Use |
| --- | --- |
| `PhoneBookContactEntry::entryFlags` byte at `+0x000` | Returned by `GetSelectedEntryData`; neutral name chosen because every checked producer writes zero and no checked consumer decodes nonzero bits. |
| `PhoneBookContactEntry::name` at `+0x002` | Copied by the selected-entry helper, drawn by `RenderEntry`, loaded/saved through `PHONE.CFG`, and updated by `PhoneEntryDialog`. |
| `PhoneBookContactEntry::phoneNumber` at `+0x082` | Copied by the selected-entry helper, drawn by `RenderEntry`, saved through `PHONE.CFG`, and used by dial flow. |
| Owner dialog back-pointer at list offset `+0x14c` | Written during constructor/setup and read by `DialSelectedEntry`; forwards activation to [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md). Offset `0x14c` is 332 bytes. Verified with `int_convert.py`. |
| Selected row index at shared list offset `+0x134` | Used by selected-entry/replace/remove paths through shared list helpers; accepted as a descriptive role pending final `ListPane` layout names. |
| Shared list helper `0x004f3bd0` | Descriptive role `ListPane::GetItemCount` / `GetEntryCount`; used by save/button-state style logic. |
| Shared list helper `0x004f3dc0` | Descriptive role `ListPane::GetItemAt` / `GetEntryAt`; used by selected-entry and save/render row access. |
| [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md) | Owner dialog calls selected-entry helper and receives activation/dial forwarding. |
| [UID:0000AF][PhoneEntryDialog](by-class/PhoneEntryDialog.md) | Inserts or updates rows displayed by this list pane. |
| [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md) | Places this class's vtables in the terminal phone-book data island. |

## First-Draft Readiness

Attach this class to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) as reconstructable terminal phone-book metadata. Method-level first-draft C++ is available for [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) and is also ready in outline for `AppendEntry`, `ReplaceSelectedEntryData`, `RemoveSelectedEntry`, `SaveEntriesToPhoneCfg`, and `DialSelectedEntry` once exact child pages are created or accepted. `RenderEntry` is behavior-ready with selected highlight, two-column name/number drawing, and ellipsis truncation, but should remain below final audit until palette/text helper names and inherited base declarations are coordinated.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `87` | The page records class role, exact selected-entry/dial/render ranges, retained setup/append/replace/remove/save helpers, corrected raw-helper endpoints/padding, parent source module, `PhoneBookContactEntry` row layout, render/selected-entry behavior, generated owner-pollution rejection, exact vtable child [UID:0003DR][0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData](by-memory/0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData.md), constructor/setup vptr stores, owner back-pointer evidence, touched state, and method-level C++ readiness for [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md). Completion remains capped by incomplete final `RenderEntry` C++ and unresolved shared inherited-base/list API declarations. |
| Confidence `89` | Phone-book ownership is strongly supported by live IDA vtable-head/xref evidence, constructor/setup disassembly, activation/render slot targets, selected-entry helper caller/body evidence, direct/no-direct caller scans, terminal/phone read-only vtable placement, and the related PhoneBookDialog/PhoneEntryDialog/DialDialog flow. B001's 2026-06-17 pass closes the selected-entry owner/field-name questions, and B007's 2026-06-19 pass resolves the retained helper inventory; confidence is not higher because final adjusted-base hierarchy names and render helper shape still need a dedicated source-quality pass. |

## Resolved Source-Quality Decisions

- `PhoneBookListPane::GetSelectedEntryData` is the accepted source-facing direction for [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md).
- The row type is `PhoneBookContactEntry` with `entryFlags`, `name`, and `phoneNumber` fields.
- `ChattingColorListPane` and `ArticleListPane` names in generated output are owner-pollution artifacts around shared list helpers, not phone-book owners.
- [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is CRT/runtime formatted-output glue; PhoneBook source should use normal formatted file output at callers.

## Remaining Follow-Up

- Reconstruct `RenderEntry` after its palette/text helpers, truncation behavior, inherited-base declarations, and row-field names are coordinated for final-source C++.
- Decide in a later raw-helper split pass whether retained helpers `0x0058ced0-0x0058cf1d`, `0x0058cf20-0x0058cf9a`, `0x0058cfe0-0x0058d075`, `0x0058d080-0x0058d08e`, and `0x0058d090-0x0058d10e` should become exact by-memory pages or remain inventory inside [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md).

## Cross-References

- [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md)
- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000AF][PhoneEntryDialog](by-class/PhoneEntryDialog.md)
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md)
- [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md)
- [UID:0003DR][0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData](by-memory/0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData.md)
- [UID:00026N][0x0062da10-0x0062df94.TerminalPhoneReadOnlyData](by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md)

## Changes

- 2026-06-02:
  - Before: scored `68/72`, reconstructability and parent blank.
  - After: scored `76/84`, marked reconstructable, and attached to [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) with C++ blank.
  - Why: exact phone-book aggregate, selected-entry helper, terminal/phone vtable data, and the high-confidence parent file now prove login phone-book ownership while incomplete generated bodies still block source emission.
- 2026-06-07:
  - Before: scored `76/84` and already attached to the phone-book source parent, but exact list method ranges, touched row fields, vtable helper audit evidence, and final open questions were scattered across linked pages.
  - After: scored `82/86`, kept parent attachment, added exact `DialSelectedEntry`/`RenderEntry` ranges, touched-state table, stronger score rationale, and explicit source-quality blockers.
  - Why: existing IDA-backed docs now prove selected-entry helper boundaries/body/caller, row field offsets `+0x000`, `+0x002`, and `+0x082`, terminal-phone vtable placement, parent file placement, and the add/edit/dial flow through PhoneEntryDialog and PhoneBookDialog. Class-level C++ remained blank pending source-quality helper and field names.
- 2026-06-12 A003 Batch 290:
  - Before: scored `82/86`; the class was above the older 80/80 attachment threshold but below the strict 85 completion gate needed to route the exact vtable child.
  - After: scored `85/88`; retained parent [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md) and left final C++ blank.
  - Why: live IDA MCP reconfirmed the exact vtable child [UID:0003DR][0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData](by-memory/0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData.md), constructor and setup-helper vptr stores, owner back-pointer at `+0x14c`, activation/render slot targets, selected-entry data layout, and `PhoneEntryDialog` successor boundary. Remaining uncertainty is source-quality naming, not class ownership.
- 2026-06-12 A004 Batch 291:
  - Updated [UID:0003DR][0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData](by-memory/0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData.md) links after the memory child range was repaired from `0x0062dbe4-0x0062dca8` to `0x0062dbe4-0x0062dca4`; no score change.
- 2026-06-17 B001 source-quality execution:
  - Resolved selected-entry source ownership, row type, row field names, generated list-pane owner pollution, and raw helper inventory. [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) now emits through this class with first-draft C++; [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is documented as CRT/runtime glue rather than a PhoneBook-owned method.
- 2026-06-21 B007 Rule 26 incorporation:
  - Raised `85/88 -> 87/89`, added the retained setup/append/replace/remove/save helper inventory, corrected the `ReplaceSelectedEntryData` endpoint to half-open `0x0058d075`, recorded the exact padding gaps, accepted descriptive shared-list helper roles, and documented first-draft readiness for list helper child pages while keeping class-level C++ blank.
- Earlier update:
  - Before: completion/confidence metadata were `0/0` despite selected-entry helper, activation, render behavior, and generated owner-pollution notes.
  - Changed to: `COMPLETION:68` and `CONFIDENCE:72`.
  - Evidence: selected contact copying, dial forwarding, render-entry behavior, row payload fields, and placement with `PhoneBookDialog` are documented; completion/confidence remain moderate because emitted `RenderEntry` is incomplete and helper owner pollution still needs cleanup.
