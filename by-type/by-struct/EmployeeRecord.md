*** UID:0001UD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004C | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001UD] EmployeeRecord layout evidence marker.
// Exact parser and dialog method children consume this record layout; a standalone final struct declaration is deferred until field names and header placement are source-final.
// EmployeeDialogPane owns a heap array through its final pointer at +0x84c and releases it in the source destructor represented by UID0003KR.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EmployeeRecord

## Status

- Confidence: strong for fixed size, parser/list/update/display/property uses, and direct owner; medium-high for final source-facing field names.
- Current Wave3 entity kind: inferred struct/layout, not a standalone class.
- Direct owner class: [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- Likely owner header/source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Size: `0x41c` bytes (`1052`)
- Owner relationship: `EmployeeDialogPane` stores `EmployeeRecord *m_employeeRecords` at final complete-object offset `+0x84c`; both observed constructors allocate the containing object at exact size `0x850`.
- Array lifetime: full-load processing allocates `count * 0x41c` bytes, and UID0003KR's source destructor releases the non-null pointer with `free`. UID0003L4 repeats that release as part of the compiler-generated deleting-wrapper body before optional object deletion.

## Layout Hypothesis

| Offset | Size | Proposed field | Evidence |
| --- | --- | --- | --- |
| `0x000` | `4` | `employeeItemId` / `id` | Parsed by `DeserializeEmployeeRecord`; zero marks empty/default slots and command paths send this value back to the server. |
| `0x004` | `2` | `stateCode` / `recordType`; target-context `itemImageId` | Parsed from the packet word, used by insert/remove paths to distinguish reusable slots, and read with the icon flag during paint. In [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md), this same word is the item image id passed to `GetItemGlyphBounds` and `DrawItemImageIn43x43Slot`. |
| `0x006` | `1` | `iconVariant` / `parserFlag`; target-context `itemPaletteFlags` | Parsed from the packet byte and read by `OnPaint` with the `0x004` word for item rendering. In [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md), this byte is passed as the item renderer palette-flags argument. |
| `0x007` | `1` | `paddingOrUnused` | No current writer or reader observed; keeps the UTF-16 name buffer aligned at `0x008`. |
| `0x008` | `0x200` | `name[256]` | Multibyte packet name converted to UTF-16; used by paint, tooltip, and update paths. |
| `0x208` | `1` | `updateStatusByte` | `UpdateEmployeeFields` writes a packet byte here before copying the secondary text; relationship to `0x006` is still unresolved. |
| `0x209` | `1` | `paddingOrUnused` | No current writer or reader observed; preserves the secondary UTF-16 buffer start at `0x20a`. |
| `0x20a` | `0x202` | `extraText[257]` / `statusText` | Parser clears the first UTF-16 word; `UpdateEmployeeFields` copies a secondary packet string here. |
| `0x40c` | `4` | `displayValue` / `priceValue` | Displayed in tooltip/property text and sent through employee item commands. |
| `0x410` | `4` | `editableValue` / `levelValue` | Used by tooltip formatting and as the editable value seed in the property dialog. |
| `0x414` | `4` | `dataField3` / `serverDataField3` | Third server-provided trailing dword in parser/update paths. No current consumer proves a narrower gameplay role, so the descriptive name is accepted for [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) first-draft C++ but remains provisional for final struct declaration work. |
| `0x418` | `4` | `defaultId` / `fallbackItemId` | Used when `id == 0` in empty/default slot paths. |

## Evidence Notes

- 2026-06-11 live IDA MCP recheck of `0x004a34d0` confirms fixed writes to `0x000`, `0x004`, `0x006`, `0x008`, `0x20a`, `0x40c`, `0x410`, `0x414`, and `0x418`.
- `EmployeeDialogPane::LoadEmployeeData` stores the slot count, allocates `totalSlots * 1052` bytes at the class record-array field, initializes empty slots, and advances records with stride `0x41c`.
- The record-array field is the final dword of the complete `EmployeeDialogPane`: `this+0x84c` through the exclusive object end at `this+0x850`. Complete-object allocations at `0x00508d2e -> 0x00508d53` and `0x005103b2 -> 0x005103d2` independently pass `0x850` bytes.
- The employee packet dispatcher calls the parser, searches existing records by id, copies complete `0x41c` records into reusable slots, and clears removed slots by zeroing the id and writing state `1` at `0x004`.
- `UpdateEmployeeFields` searches the same record array by id, rewrites the id/state/name/trailing dwords, writes the additional byte at `0x208`, and copies the secondary string to `0x20a`.
- `OnPaint` and `OnMouseInput` index the array with `0x41c` stride and read the id, state/icon fields, name, display value, and editable/level value for icon rendering, tooltips, and visible-slot display.
- `EmployeeItemPropertyDialogPane::OnCommand` treats the selected pointer as an `EmployeeRecord`, sends the id in employee commands, uses `0x40c` for the alternate item command, and seeds/updates the editable value from `0x410`.
- B001 2026-06-23 target-context refinement for [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md): in the property dialog, `0x000` is the selected employee item id passed to events/subcommands `2` and `3`; `0x40c` is the current/display price value passed on the remove/clear schedule call for source/binary shape, although parent `SendCommand` case `3` serializes only the id; and `0x410` is the editable price value used both by the constructor to seed price edit control id `3` and by `OnCommand` as the confirm-path parse default.
- B004 2026-06-26 target-context refinement for [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md): in the property-dialog item icon path, `0x004` is the `itemImageId` word consumed by `GetItemGlyphBounds` and `DrawItemImageIn43x43Slot`, and `0x006` is the `itemPaletteFlags` byte consumed by the same item-image draw call. The broader record aliases remain because parser/list/update paths still use the offsets with wider employee/status meanings.
- B001 2026-06-26 target-context refinement for [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md): the parser now emits first-draft C++ and uses the accepted source-facing field set `employeeItemId`, `itemImageId`, `itemPaletteFlags`, `name`, `statusText`, `priceValue`, `editablePriceValue`, provisional `dataField3`, and `fallbackItemId`. MCP session/database `80de0a67` and the update path both confirm a third trailing dword write at `+0x414`; no current consumer gives it a narrower gameplay name, so `dataField3` / `serverDataField3` is the current descriptive disposition and does not block the exact parser C++.
- Raw `0x004a3be0` disassembly is still not an IDA function, but its body calls `DeserializeEmployeeRecord`, uses record count/array fields, and copies `0x107` dwords to cover the full `0x41c` record.
- 2026-06-16 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed modeled parser/load/update function sizes (`0x004a34d0` size `0x174`, `0x004a3a90` size `0x14f`, `0x004a3e10` size `0x247`), parser xrefs at `0x004a300d`, `0x004a3bb1`, and raw `0x004a3c05`, load callers at `0x004a1ff4` and `0x004a2fe0`, and update caller `0x004a313e`.
- The same session reconfirmed no xrefs to raw helper starts `0x004a3650`, `0x004a37a0`, `0x004a3830`, `0x004a38d0`, `0x004a3960`, `0x004a39d0`, `0x004a3a30`, `0x004a3be0`, or `0x004a3ca0`. Raw disassembly still shows `0x004a3be0` parsing into a stack `0x420` local record and scanning/copying records with `0x41c` stride, while raw `0x004a3ca0` removes a record, clears visible-slot state, rebuilds the list, and repaints before the `0x004a3e10` function boundary.
- B006 2026-06-29 current MCP session `967f0703` resolved the UID0003L2 empty-emitter disposition as a formal no-body marker through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md): `0x004a3be0` and `0x004a3ca0` remain not-functions with zero xrefs and zero VA/RVA pointer-byte routes, but their exact raw-island boundaries, `0x41c` stride, and `0x107` copy evidence are no longer open boundary-cleanup blockers for this struct page.
- Generated-output check: active `class_EmployeeDialogPane.cpp` uses a broad `EmployeeRecord` name with fields such as `id`, `type`, `subType`, `status`, `goldAmount`, and `level`, while `class_EmployeeItemPropertyDialogPane.cpp` locally redeclares a shorter `EmployeeItemRecord` with `spriteId`, `paletteId`, `priceValue`, and `editValue`. These overlays confirm the consumer roles but are inconsistent local generated types, so they cannot safely replace the conservative layout names here.
- Destructor-lifetime check: UID0003KR `[0x004a22f0,0x004a23a8)` tests the pointer at `+0x84c`, calls `free` only when non-null, then sends the close packet and invokes the base destructor. UID0003L4 `[0x004a4d40,0x004a4e27)` performs the same source-visible release/close/base sequence before compiler deleting-flag handling. Neither body writes zero back to `+0x84c`; no null-clear should be invented in source reconstruction.

## Open Questions

- The same offsets are used with shop-item and employee-status meanings depending on UI path. Final field names should wait for one more pass through item sprite render and property-edit usage.
- The relationship between parser byte `0x006`, update byte `0x208`, and the unobserved padding byte at `0x209` remains open.
- Raw/projected helpers `0x004a3650`, `0x004a3be0`, and `0x004a3ca0` no longer need boundary cleanup for UID0003L0/UID0003L2 empty-emitter disposition; they are exact retained raw islands with formal no-code markers. Original callable helper names and direct source-facing entries remain unproved.
- Generated local names such as `EmployeeItemRecord`, `spriteId`, `paletteId`, `priceValue`, and `editValue` are useful hints for consumer behavior, but the generated overlays disagree on record extent and field set, so they are not yet safe as final source declarations.
- For the property-dialog target only, `priceValue` and `editablePriceValue` are accepted target-context aliases for `0x40c` and `0x410`. The broad layout keeps `displayValue` / `priceValue` and `editableValue` / `levelValue` aliases because other employee/status paths still reuse the same trailing dwords with wider meanings.
- For the property-dialog paint target only, `itemImageId` and `itemPaletteFlags` are accepted target-context aliases for `0x004` and `0x006`. The broad layout keeps `stateCode` / `recordType` and `iconVariant` / `parserFlag` aliases until a whole-record field-name pass resolves all parser, list, update, and display consumers.
- For [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md), the `+0x414` uncertainty is now resolved far enough for first-draft parser code: use the descriptive `dataField3` / `serverDataField3` rather than raw offset names. This remains an open final-struct naming question only because no consumer has yet narrowed the field's gameplay meaning.
- The final member name remains provisional, but its type, offset, extent, allocation stride, and destructor ownership are no longer open. Model it as an `EmployeeRecord *` at `EmployeeDialogPane+0x84c`; do not add a separate owner object, array wrapper, or destructor null-store unsupported by the binary.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md). The child is now `88/92`, the direct class parent is `90/93`, and the source-file parent [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) is `91/92`, so the strict child/direct-parent `85/85` gate clears. The class is the direct semantic owner because it stores the `EmployeeRecord *` at `+0x84c`, allocates and maintains the array, parses packet records, updates/removes entries, renders visible slots, passes selected records into the property dialog, and releases the array in its destructor. [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) remains a non-owning consumer.

## Score Rationale

- Completion is `88` because the fixed `0x41c` size, field offsets, parser/list/update/display/property uses, raw-copy/remove bodies, owner class, exact `+0x84c` pointer relationship, `count * 0x41c` allocation, destructor release policy, source-file route, current parent scores, and generated-output overlay limitations are documented. Final field spelling and a standalone header declaration remain deferred.
- Confidence is `92` because multiple independent read/write paths agree on the record stride and offsets, two allocation sites agree on the containing `0x850` extent, and both ordinary and deleting destructor bodies read/free the same final pointer without clearing it. Final broad struct field names, `0x006` versus `0x208` semantics, and unproved original helper names still cap source-declaration confidence.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md)
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md)

## Changes

- 2026-08-24 B002 accepted EmployeeDialogPane destructor implementation callback: raised the page from `86/89` to `88/92`; tied the `0x41c` record array to `EmployeeDialogPane+0x84c`, recorded both `0x850` complete-object allocations and `count * 0x41c` array allocation, and documented non-null `free` in UID0003KR/UID0003L4 with no unsupported null-clear.

- 2026-06-29 B006 UID0003L2 marker support sync:
  - Score unchanged at `86/89`; struct C++ remains blank.
  - Summary/evidence: recorded that [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md) now has exact raw-island boundary/no-function/no-xref/no-pointer-route disposition and a formal no-body marker through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md). The struct page still keeps broad field-name questions open, but no longer treats `0x004a3be0`/`0x004a3ca0` boundary cleanup as a current blocker.
- 2026-06-26 B001 parser field-name support sync:
  - Score unchanged at `86/89`.
  - Summary/evidence: updated the `+0x414` row and evidence notes for accepted [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) C++ entry. MCP session/database `80de0a67` and current update-path evidence support `dataField3` / `serverDataField3` as the best descriptive source-facing name for the third server-provided trailing dword; no current consumer proves a narrower semantic role, so the field remains provisional for final struct declaration work but no longer blocks first-draft parser C++.
- 2026-06-26 B004 property-paint target-context sync:
  - Score unchanged at `86/89`.
  - Summary/evidence: added the accepted target-specific aliases for [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md): `0x004` as `itemImageId` for `GetItemGlyphBounds` and `DrawItemImageIn43x43Slot`, and `0x006` as `itemPaletteFlags` for the renderer palette-flags argument. The broader record score remains unchanged because parser, list, update, and employee/status consumers still require shared aliases rather than one final field spelling.

- 2026-06-23 B001 property-command target-context sync:
  - Score unchanged at `86/89`.
  - Summary/evidence: added the accepted target-specific aliases for [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md): `0x000` as selected employee item id, `0x40c` as current/display price value in the property dialog, and `0x410` as editable price value. The broader record score remains unchanged because generated overlays and non-property employee/status consumers still require shared aliases rather than one final field spelling.
- 2026-06-16 A002 Goal2 type-confidence refresh:
  - Before: `85/88`.
  - After: `86/89`; owner/emitter remain [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md), with final C++ still blank.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed parser/load/update sizes, caller sets, raw helper no-xref status, `0x41c` raw copy/remove behavior, and parent routing. Active generated EmployeeDialog/EmployeeItemProperty files were checked; they provide useful consumer-name hints but use inconsistent local overlays, so final record/member names remain unresolved.
- 2026-05-31 completion/reconstruction metadata:
  - What existed before: metadata remained unevaluated at `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite documented parser/layout evidence.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`; the exact `DeserializeEmployeeRecord` page was added to cross-references.
  - Summary/evidence: live IDA MCP decompilation of `0x004a34d0` confirms fixed writes to offsets `+0x000`, `+0x004`, `+0x006`, `+0x008`, `+0x20a`, `+0x40c`, `+0x410`, `+0x414`, and `+0x418`, while callers confirm the `0x41c` record stride.
- 2026-06-11 A001 strict-gate assignment:
  - What existed before: `AUTOGEN_PARENT_UID:` was blank, completion remained `78`, and the layout did not distinguish the parser byte at `0x006` from the update byte at `0x208`.
  - Changed to: `AUTOGEN_PARENT_UID:00004C`, `COMPLETION:85`, and `CONFIDENCE:88`; the layout now records the observed `0x208` byte, secondary text buffer, direct owner class, and remaining caveats.
  - Summary/evidence: live IDA MCP rechecked parser/list/update/paint/mouse/property paths, confirmed `EmployeeDialogPane` owns the record array and selected-record flow, verified `0x41c` stride and the raw `0x004a3be0` `0x107`-dword copy body, and confirmed child `85/88`, direct class parent `85/86`, and source file parent `88/85` clear the strict assignment gate.
