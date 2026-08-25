*** UID:0001UH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000051 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FittingEquipmentStateLayout

## Status

- Entity kind: embedded fitting-room state layout
- Working owner label: [UID:00004Z][FittingEquipmentState](by-class/FittingEquipmentState.md)
- Direct layout parent: [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)
- Likely source owner: [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) in [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Main evidence: IDA decompilation of `0x0041d5e0`, constructor initialization at `0x00422020`, and vector destruction at `0x00423870`.
- Confidence: strong for the selected-entry identity, documented offsets, element layout, and lifecycle evidence; source spelling is inferred consistently with the accepted fitting-room declaration.
- Reconstructable: true as a source-level embedded layout description. Its C++ body is intentionally blank because [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) emits the complete declaration and this support page must not duplicate it.

## Layout

The accepted source model identifies this storage as the selected-fitting-item vector inside the larger fitting-room item-state object:

| Offset | Type hypothesis | Evidence |
| --- | --- | --- |
| `+0x240` | `FittingRoomSelectionEntry* m_selectedFittingItems.begin` | Read as `this[144]`; constructor zeroes it at `0x004220d1`. |
| `+0x244` | `FittingRoomSelectionEntry* m_selectedFittingItems.end` | Read as `this[145]`; reset writes `end = begin`; constructor zeroes it at `0x004220db`. |
| `+0x248` | `FittingRoomSelectionEntry* m_selectedFittingItems.capacity` | Constructor zeroes `this[146]`; not used by `ResetEquipmentEntries`. |

The 2026-06-11 decompilation recheck reconfirmed these item-state offsets from the constructor as decimal `576` / `0x240`, decimal `580` / `0x244`, and decimal `584` / `0x248` (Verified with int_convert.py). The same constructor establishes nearby category storage at decimal `544` / `0x220`, cache-loaded byte at decimal `588` / `0x24c`, encode-key storage at decimal `592` / `0x250`, and decode-key storage at decimal `616` / `0x268` (Verified with int_convert.py), confirming this vector is one field group inside the larger [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) object.

`FittingRoomSelectionEntry` stride is `0xb4` bytes. The reset loop starts the nested `partTypes` vector triple at entry offset `+0xa8` and then advances the entry pointer by `0xb4`.

| Entry offset | Type hypothesis | Reset behavior |
| --- | --- | --- |
| `+0x000` | `FittingRoomCatalogCategory category` | Not touched by `ResetEquipmentEntries`. |
| `+0x004` | `wchar_t name[0x50]` | Not touched by `ResetEquipmentEntries`. |
| `+0x0a4` | signed `int catalogIndex` | Not touched by `ResetEquipmentEntries`; natural alignment occupies `+0x0a6-+0x0a7`. |
| `+0x0a8` | `int* partTypes.begin` | Freed if non-null, then zeroed. |
| `+0x0ac` | `int* partTypes.end` | Zeroed after nested-vector release. |
| `+0x0b0` | `int* partTypes.capacity` | Used for span/large-allocation validation, then zeroed. |

The reset helper reaches the end slot through decimal entry offset `176` / `0xb0` (Verified with int_convert.py), backs up two dwords for `+0xa8`, and advances by decimal `180` / `0xb4` bytes per entry (Verified with int_convert.py). The destructor vector helper at `0x00423870` repeats the same decimal `180` / `0xb4` entry stride (Verified with int_convert.py) before freeing the backing allocation.

## Ownership Notes

The historical `FittingEquipmentState` label remains useful for identifying the reset command route, but IDA caller and constructor evidence tie the storage to the larger fitting-room item-state record:

- `FittingRoomDialog::OnCommand` at `0x0041c404` calls `ResetEntries` with `this + 0x504`.
- `FittingRoomDialog` constructor calls the item-state constructor at `0x0041be6c` with the same `this + 0x504` pointer.
- The `0x00422020` constructor initializes strings, cache path, category storage, and the `+0x240/+0x244/+0x248` `m_selectedFittingItems` vector in one object.

Keep this as a layout/evidence page rather than a standalone class declaration. [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) owns the recovered source declaration and the single `m_selectedFittingItems` member.

## Lifecycle Evidence

- [UID:0002E7][0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor](by-memory/0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor.md) clears the selected-entry vector triple at item-state offsets `+0x240/+0x244/+0x248` during construction, after category lookup setup and before the encode/decode key strings.
- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md) is a non-destructive reset: it frees each active entry's trailing buffer triple at entry `+0xa8/+0xac/+0xb0`, zeroes that triple, and writes `end = begin` while preserving the vector allocation/capacity.
- [UID:0002EB][0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor](by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md) releases `m_selectedFittingItems` at item-state `+0x240` through [UID:0002UE][0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper](by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md), which passes `[begin,current)` to [UID:0002E0][0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease](by-memory/0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md) at `0x0042387e`; the range helper walks `0xb4`-byte `FittingRoomSelectionEntry` elements and calls [UID:0002DW][0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease](by-memory/0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease.md) for each nested `partTypes` vector at `+0xa8/+0xac/+0xb0`. UID0002UE then frees the outer backing allocation and clears the vector triple. Its covered-by marker routes emitted lifecycle source through UID0002EB and [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), avoiding a standalone compiler-container helper body.
- The reset helper and destructor helper therefore document two different lifecycle phases: command-time clearing of active entry contents versus object-destruction release of the vector allocation.

## 2026-06-11 Gate Recheck

Live IDA MCP reconfirmed the key functions and caller paths:

- `0x0041d5e0` remains `sub_41D5E0`, size `0x92`, with exactly one caller at `0x0041c404` inside `FittingRoomDialog::OnCommand`.
- `0x0041bdd0` remains the fitting-room dialog constructor, size `0x480`, and calls the item-state constructor at `0x0041be6c`.
- `0x00422020` remains the item-state constructor, size `0x30a`, with the single constructor caller above; its decompilation clears category lookup storage, then zeros `this[144]`, `this[145]`, and `this[146]` for the equipment vector before initializing the cache flag and CASH encode/decode strings.
- `0x00422330` remains the item-state destructor, size `0x13f`, called from the dialog scalar destructor at `0x0041d527`.
- `0x00423870` remains the vector destroy helper, size `0x73`, called from the item-state destructor at `0x0042240a`; it calls the entry range release helper, applies the same `0xb4` stride math, frees the vector backing allocation, and clears begin/end/capacity. It is `m_selectedFittingItems` lifecycle evidence covered by the item-state destructor/declaration rather than a standalone emitted helper body.

This supports assigning the layout page directly to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), not to the provisional [UID:00004Z][FittingEquipmentState](by-class/FittingEquipmentState.md) support view. The layout describes a field group inside the item-state object; the `FittingEquipmentState` name remains useful for the reset method label but is not a proven standalone original class.

## Boundary And Cleanup Caveats

- Do not merge `m_selectedFittingItems` with category-entry cleanup. [UID:0002EC][0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries](by-memory/0x00422470-0x0042259a.FittingRoomDialogItemStateResetCategoryEntries.md) walks category lookup storage at item-state `+0x220` and frees `0xc0`-byte category entries; this layout describes the separate selected-entry vector at `+0x240`.
- The entry stride `0xb4` is shared between the reset helper and the destructor vector helper. [UID:0002DW][0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease](by-memory/0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease.md) releases each selected entry's nested `partTypes` vector; it does not own or emit the outer item-state vector declaration.
- [UID:0002E0][0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease](by-memory/0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md) wraps the item-state `[begin,current)` selected-entry span. [UID:0002UE][0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper](by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md) owns outer-vector storage free/clear evidence and carries the covered-by marker through UID0002EB/UID000051; UID0002DW owns nested-vector cleanup evidence.
- The entry-local trailing buffer looks vector/string-like because both reset and destruction validate MSVC large-allocation headers before freeing. The current page should not name the buffer as item text, encoded bytes, or category parts until parser/render consumers are audited.

## 2026-06-16 Source-Quality Recheck

Live IDA MCP session `b001_0001KM_20260616` reconfirmed the source-quality blockers rather than resolving them into final field names:

- `lookup_funcs` still reports `0x0041d5e0` as `sub_41D5E0` size `0x92`, `0x00422020` as `sub_422020` size `0x30a`, `0x00422330` as `sub_422330` size `0x13f`, `0x00423870` as `sub_423870` size `0x73`, `0x00422470` as `sub_422470` size `0x12a`, and the dialog constructor `0x0041bdd0` size `0x480`.
- `analyze_batch` decompilation of `0x0041d5e0` again reads `this[144]` and `this[145]`, frees each entry-local block through `entry+0xa8`/`entry+0xac`/`entry+0xb0`, advances by decimal `180` / `0xb4`, and then writes `this[145] = this[144]`. That confirms the reset helper's owner-relative vector tail and entry stride.
- `analyze_batch` decompilation of `0x00422020` again zeros `this+0x240`, `this+0x244`, and `this+0x248`, then initializes the cache-loaded byte and the `CASHEncodeDecodeByChris` / `sirhCyBedoceDedocnEHSAC` strings. This keeps the vector inside [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md), not a standalone class.
- `type_query` and `search_structs` for `FittingRoomDialogItemState` and `FittingEquipmentState` returned no local NexusTK UDTs. IDA therefore does not currently preserve original field or nested-type names for this layout.
- The active `source-3/simroot_v2/class_FittingRoomDialogItemState.cpp` was checked as a lead. It reconstructs local `ItemStateView` overlays and a separate `FittingRoomCategoryEntry`/`itemParts` tail in category-loading code, but it does not provide a stable equipment-entry declaration at item-state `+0x240`. Because that generated source mixes local overlay structs and category-entry naming, it is not strong enough to rename this page's `EquipmentEntry` role type or its trailing buffer fields.

At the 2026-06-16 checkpoint, C++ remained blank because the item-state declaration and nested entry identity had not yet been closed. The accepted 2026-07-23 reconciliation supersedes that blocker with `FittingRoomSelectionEntry` and `m_selectedFittingItems`; this page remains blank only because UID000051 emits the complete declaration.

## Score Rationale

- Completion is `91` because the page records constructor initialization, command-time reset, destructor-time release, verified offset/stride conversions, the category-entry cleanup boundary, direct item-state ownership, the exact `FittingRoomSelectionEntry` layout, and the single `m_selectedFittingItems` source identity.
- Confidence is `92` because the `+0x240/+0x244/+0x248` vector triple, `0xb4` stride, semantic fields through `+0xa4`, and nested `partTypes` vector at `+0xa8/+0xac/+0xb0` are corroborated by constructor, input, paint, reset, and destruction paths. Lexical source spellings remain inferred, so the page does not claim symbol-level certainty.

## Cross-References

- [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md)
- [UID:00004Z][FittingEquipmentState](by-class/FittingEquipmentState.md)
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)

## Changes

- 2026-06-29 B012 [UID:0002UE][0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper](by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md) empty-emitter implementation callback:
  - Scores unchanged at `86/89`.
  - Summary/evidence: updated lifecycle support after B012 raised UID0002UE to `88/90` and inserted the formal covered-by marker. The layout continues to treat `EquipmentEntry` as an inferred role name while preserving UID0002UE as exact `+0x240/+0x244/+0x248` vector-storage free/clear evidence for `m_equipmentEntries`; emitted source for that cleanup range is covered by [UID:0002EB][0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor](by-memory/0x00422330-0x0042246f.FittingRoomDialogItemStateDestructor.md) and [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) field lifecycle.
- 2026-05-30: Scored the layout page from 0/0 to 74/84 after the method page was expanded with exact offset and raw-code evidence. Evidence: IDA MCP decompilation for `0x0041d5e0` confirms the `+0x240/+0x244/+0x248` vector fields, `0xb4` entry stride, and `+0xa8/+0xac/+0xb0` buffer triplet.
- 2026-06-03: Replaced older owner wording with a working-label statement. Live IDA MCP reconfirmed the same layout evidence: `sub_41D5E0` reads/writes the vector tail, `sub_41C310` calls it with dialog `this + 0x504`, and `sub_422020` initializes the vector fields at relative offsets `+0x240/+0x244/+0x248`.
- 2026-06-04: Marked `RECONSTRUCTABLE:TRUE` without changing scores.
  - Reasoning: existing live IDA evidence proves the embedded vector-tail and entry-buffer layout as real source-level data structure information; parent attachment remains blank because the complete fitting-room item-state declaration and final type name are still unresolved.
- 2026-06-07 A006 documentation pass:
  - Before: the page was `74/84` and focused on reset-method offsets.
  - After: raised to `80/86`.
  - Summary/evidence: added constructor initialization evidence, destructor vector-release evidence, the reset-versus-destruction lifecycle distinction, the boundary against category-entry cleanup at `+0x220`, and explicit naming caveats for the `0xb4` entry and trailing buffer.
- 2026-06-11 A004 Batch 146 strict-gate update:
  - Before: `80/86`, `AUTOGEN_PARENT_UID` blank.
  - After: `85/88`, `AUTOGEN_PARENT_UID:000051`.
  - Summary/evidence: live IDA MCP reconfirmed reset, constructor, destructor, and vector-destroy helper boundaries and caller paths. Decompilation ties the vector triple and `0xb4` stride to [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md); decimal offsets from the decompiler were rechecked with `int_convert.py`. C++ remained blank under the then-current final-source gate; the 2026-06-24 B004 support sync below now records the accepted compiler/container lifecycle no-code rationale for the [UID:0002DW][0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease](by-memory/0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease.md) tail-vector route.
- 2026-06-16 A002 source-quality pass:
  - Before: `85/88`.
  - After: `86/89`.
  - Summary/evidence: live IDA MCP session `b001_0001KM_20260616` reconfirmed the reset, item-state constructor/destructor, category-cleanup boundary, and vector-destroy helper starts/sizes; `analyze_batch` rechecked the `this[144..146]` vector triple and `0xb4` entry stride; `type_query`/`search_structs` found no preserved local `FittingRoomDialogItemState` or `FittingEquipmentState` UDT; generated `class_FittingRoomDialogItemState.cpp` was checked and found useful only as a lead because its local overlays do not safely name the equipment-entry tail.
- 2026-06-24 B004 support sync:
  - Scores unchanged at `86/89`.
  - Summary/evidence: added the accepted [UID:0002DW][0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease](by-memory/0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease.md) route to the destructor lifecycle: [UID:0002UE][0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper](by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md) calls [UID:0002E0][0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease](by-memory/0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md), which walks `0xb4` equipment entries and calls [UID:0002DW][0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease](by-memory/0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease.md) to release the entry-local tail buffer/vector at `+0xa8/+0xac/+0xb0`. The support note preserves the distinction between list-pane `partTypes` wording and the item-state `EquipmentEntry` role.
- 2026-06-24 B001 [UID:0002E0][0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease](by-memory/0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md) implementation callback:
  - Scores unchanged at `86/89`.
  - Summary/evidence: updated the renamed [UID:0002E0][0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease](by-memory/0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md) range wrapper route after B001 raised it to `88/90`; preserved equipment-entry tail-buffer wording distinct from list-pane `partTypes`, and clarified that [UID:0002E0][0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease](by-memory/0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md) walks `[begin,current)` while [UID:0002UE][0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper](by-memory/0x00423870-0x004238e3.FittingRoomEntryStringDestroyHelper.md) owns vector storage free/clear and [UID:0002DW][0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease](by-memory/0x00421380-0x004213e1.FittingRoomEntryTailVectorRelease.md) owns per-entry tail cleanup evidence.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0001UH)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- The opaque FittingRoomEquipmentEntry interpretation is superseded by the live-proved FittingRoomSelectionEntry route through UID000051: category +0, name[0x50] +4, signed catalogIndex +0xa4, natural alignment +0xa6, and vector<int> partTypes +0xa8. The single +0x240 item-state storage is m_selectedFittingItems.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-048 | 0001UH | The exact 0xb4 element is `FittingRoomSelectionEntry`: category +0, `wchar_t name[0x50]` +4, signed `catalogIndex` +0xa4, natural alignment, and `std::vector<int> partTypes` +0xa8. Prior `displayName`/`itemIndex` are weaker report spellings superseded by current emitters. | Certain for layout, strong for lexical names | Live UID0002DL/UID0002DN consumers plus existing selection-entry/vector docs. | UID000051 declaration, UID0002DL/UID0002DN, and UID0001UH support. | historicalize | implemented |
| C2E6-056 | 0002E6 | Manual rows for UID0002E5, UID0001UH, UID0004WJ, UID0004WL, and UID0004WI are terminalized with their validator-owned identities; all 43 exact manual coverage actions are now present and supervisor-validated by commands16953 through16957. B004 supplied the handoffs and did not edit coverage reports. | Certain | Current manual roots, allocated UID readback, supervisor coverage commands16953/16954/16955/16956/16957, and callback actor boundary. | Manual handoff/checklist. | incorporate | implemented-verified |
| C2E6-060 | 0001UH | `reservedState[0xa8]` and `vector<unsigned char> payload` are rejected; live selection insertion identifies every semantic field and a `vector<int>` payload. | Certain | UID000053 OnInputEvent construction and exact offsets/stride. | UID000051/UID0001UH history/formal. | reject-invalid | implemented |
| C2E6-068 | 0000WS | UID0000WS clears the same selected-entry vector; retain `ResetEquipmentEntries()` as the observed command-role method name but change its body/prose from `m_equipmentEntries.clear()` to `m_selectedFittingItems.clear()`. | Certain for storage/body, strong for method/member spelling | Live 0x0041d5e0 decompile, sole OnCommand caller, shared +0x240 vector and 0xb4 stride. | UID0000WS formal/prose; UID000051/UID00004Z/UID0001UH/UID0000JE support. | historicalize | implemented |
| C2E6-069 | 0002UE | UID0002UE remains covered-by/no-code vector-storage release evidence, but its covered source member is `m_selectedFittingItems`, not a second equipment-entry vector. | Certain | Live 0x00423870 decompile and item-state destructor call at 0x0042240a. | UID0002UE prose/formal comment; UID000051/UID0001UH/UID0000JE. | historicalize | implemented |
| C2E6-072 | 000051 | Constructor/destructor/layout/support pages that call the +0x240 vector `m_equipmentEntries` must preserve their binary facts but historicalize that lifecycle-only name in favor of `m_selectedFittingItems`. | Certain for identity, strong for spelling | Same dialog-relative/item-state-relative storage across 0x0041f100/0x0041f2b0/0x0041fcd0/0x0041d5e0/0x00422020/0x00422330/0x00423870. | UID0002E7, UID0002EB, UID0000WS, UID0002UE, UID000051, UID00004Z, UID0001UH, UID0000JE. | historicalize | implemented |
