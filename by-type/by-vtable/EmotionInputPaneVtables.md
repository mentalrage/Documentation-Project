*** UID:0003HI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// EmotionInputPaneVtables is the source-local index for UID0002N4.
// Regenerate the tables through EmotionInputPane; do not duplicate fixed
// vtable, RTTI, scalar-destructor, or adjustor-thunk bytes here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EmotionInputPane Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `EmotionInputPane` primary, secondary, and tertiary vtable views.
- Direct owner: [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md).
- Source context: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md).
- Exact data page: [UID:0002N4][0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData](by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md).
- Split from: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md), which remains a broad non-emitting mixed-owner index.

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- | --- |
| `EmotionInputPane` | [UID:0002N4][0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData](by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md) | `0x0062f9b8-0x0062fa04`, 19 slots | `0x0062fa08-0x0062fa34`, 11 slots, object `+0xa0` | `0x0062fa38-0x0062fa40`, two slots, object `+0xa4` | Constructor stores at `0x005b2a03`, `0x005b2a09`, and `0x005b2a13`; the source virtual slot is `0x0062fa00 -> 0x005b2a70` (`EmotionInputPane::OnAccept`). |

## Complete Source-Local Cell Inventory

The exact source-local family is 34 consecutive four-byte data items with no padding. The two locator cells are part of the family: `0x0062fa04 -> 0x00652c34` introduces the `EventHandler` view and `0x0062fa34 -> 0x00652c48` introduces the `TimerHandler` view. The primary complete-object locator at `0x0062f9b4 -> 0x00652bd0` is immediately before this page and is excluded; `0x0062fa40 -> 0x00652c5c` begins `ChangeItemSlotInputPane` and is excluded.

| Cell | View offset | Current target | Evidence-backed role |
| --- | --- | --- | --- |
| `0x0062f9b8` | primary `+0x00` | `0x005b7940` | shared scalar deleting-destructor wrapper |
| `0x0062f9bc` | primary `+0x04` | `0x004f4b10` | inherited/shared primary virtual slot |
| `0x0062f9c0` | primary `+0x08` | `0x0041b6c0` | inherited/shared primary virtual slot |
| `0x0062f9c4` | primary `+0x0c` | `0x004f2320` | inherited/shared primary virtual slot |
| `0x0062f9c8` | primary `+0x10` | `0x0041d680` | inherited/shared primary virtual slot |
| `0x0062f9cc` | primary `+0x14` | `0x00544730` | inherited/shared primary virtual slot |
| `0x0062f9d0` | primary `+0x18` | `0x00544750` | inherited/shared primary virtual slot |
| `0x0062f9d4` | primary `+0x1c` | `0x005447a0` | inherited/shared primary virtual slot |
| `0x0062f9d8` | primary `+0x20` | `0x00544800` | inherited/shared primary virtual slot |
| `0x0062f9dc` | primary `+0x24` | `0x00544a20` | inherited/shared primary virtual slot |
| `0x0062f9e0` | primary `+0x28` | `0x00544b80` | inherited/shared primary virtual slot |
| `0x0062f9e4` | primary `+0x2c` | `0x00544bd0` | inherited/shared primary virtual slot |
| `0x0062f9e8` | primary `+0x30` | `0x004f2430` | inherited/shared primary virtual slot |
| `0x0062f9ec` | primary `+0x34` | `0x00544cb0` | inherited/shared primary virtual slot |
| `0x0062f9f0` | primary `+0x38` | `0x004f24c0` | inherited/shared primary virtual slot |
| `0x0062f9f4` | primary `+0x3c` | `0x00544d30` | inherited/shared primary virtual slot |
| `0x0062f9f8` | primary `+0x40` | `0x00544d70` | inherited/shared primary virtual slot |
| `0x0062f9fc` | primary `+0x44` | `0x004f2790` | inherited/shared primary virtual slot |
| `0x0062fa00` | primary `+0x48` | `0x005b2a70` | `EmotionInputPane::OnAccept` override |
| `0x0062fa04` | internal locator | `0x00652c34` | `EventHandler` secondary-view complete-object locator; not padding |
| `0x0062fa08` | EventHandler `+0x00` | `0x005b77c8` | shared `-0xa0` scalar-delete adjustor |
| `0x0062fa0c` | EventHandler `+0x04` | `0x004f24f0` | inherited/shared EventHandler virtual slot |
| `0x0062fa10` | EventHandler `+0x08` | `0x004f2920` | inherited/shared EventHandler virtual slot |
| `0x0062fa14` | EventHandler `+0x0c` | `0x004f2580` | inherited/shared EventHandler virtual slot |
| `0x0062fa18` | EventHandler `+0x10` | `0x004f2760` | inherited/shared EventHandler virtual slot |
| `0x0062fa1c` | EventHandler `+0x14` | `0x00544df0` | inherited/shared EventHandler virtual slot |
| `0x0062fa20` | EventHandler `+0x18` | `0x00544e00` | inherited/shared EventHandler virtual slot |
| `0x0062fa24` | EventHandler `+0x1c` | `0x004a89f0` | inherited/shared EventHandler virtual slot |
| `0x0062fa28` | EventHandler `+0x20` | `0x00544e10` | inherited/shared EventHandler virtual slot |
| `0x0062fa2c` | EventHandler `+0x24` | `0x00544e30` | inherited/shared EventHandler virtual slot |
| `0x0062fa30` | EventHandler `+0x28` | `0x00544e70` | inherited/shared EventHandler virtual slot |
| `0x0062fa34` | internal locator | `0x00652c48` | `TimerHandler` tertiary-view complete-object locator; not padding |
| `0x0062fa38` | TimerHandler `+0x00` | `0x005b77d3` | shared `-0xa4` scalar-delete adjustor |
| `0x0062fa3c` | TimerHandler `+0x04` | `0x00544e90` | inherited/shared TimerHandler virtual slot |

## RTTI And Object Layout

| RTTI item | Type | PMD `mdisp/pdisp/vdisp` | Source meaning |
| --- | --- | --- | --- |
| type descriptor `0x00679f54` | `EmotionInputPane` | n/a | decorated dynamic type identity |
| CHD `0x00652be4` / base array `0x00652bf4` | `EmotionInputPane` hierarchy | n/a | attributes `1`; eight BCD entries |
| BCD `0x00652c18` | `EmotionInputPane` | `0 / -1 / 0` | complete object; seven contained bases; attributes `0x40` |
| BCD `0x00649afc` | `CharInputPane` | `0 / -1 / 0` | direct source base; six contained bases |
| BCD `0x006499ec` | `LineInputPane` | `0 / -1 / 0` | primary ancestor; five contained bases |
| BCD `0x00640540` | `Pane` | `0 / -1 / 0` | primary ancestor; four contained bases |
| BCD `0x00640584` | `GrafPort` | `0 / -1 / 0` | primary ancestor; one contained base |
| BCD `0x00640348` | `LObject` | `0 / -1 / 0` | primary root ancestor |
| BCD `0x006405bc` | `EventHandler` | `0xa0 / -1 / 0` | secondary non-virtual base view at object offset `+0xa0` |
| BCD `0x0064060c` | `TimerHandler` | `0xa4 / -1 / 0` | tertiary non-virtual base view at object offset `+0xa4` |

The PMDs, constructor stores, and observed allocation size `0x108` agree. The inherited layout already reaches the two handler subobjects, so no Emotion-specific persistent field is supported.

## Current Source And Compiler Disposition

- The constructor installs the primary, `EventHandler`, and `TimerHandler` views at `0x005b2a03`, `0x005b2a09`, and `0x005b2a13`.
- Function `0x005b2a70` has no code caller and exactly one binary route through primary slot `+0x48`; alignment with the current `CharInputPane::OnAccept` declaration resolves the override as `EmotionInputPane::OnAccept`.
- `0x005b7940` is shared by 23 prompt-class primary tables plus two adjustor code references, while `0x005b77c8` and `0x005b77d3` each have 23 table references. They are shared compiler/linker artifacts, not Emotion-specific methods.
- Regenerate this family from the `EmotionInputPane` class declaration and virtual method set. Do not write fixed vtable arrays, RTTI records, complete-object locators, scalar deleting-destructor wrappers, or adjustor thunks in source.
- Keep the page as a source-local index for UID0002N4; do not split or duplicate the exact data page. The H channel remains blank because the class declaration belongs to UID00004B.

## Boundary Evidence

- Exact span is `0x0062f9b8-0x0062fa40`, or `0x88` / 136 bytes (Verified with int_convert.py).
- 2026-06-12 live IDA MCP `entity_query` lists `??_7EmotionInputPane@@6B@`, `??_7EmotionInputPane@@6B@_0`, and `??_7EmotionInputPane@@6B@_1` at the three table bases.
- 2026-06-12 `get_bytes` reads `40 79 5b 00 10 4b 4f 00` at the primary base, matching shared scalar-deleting destructor and inherited slot dwords.
- 2026-06-12 `get_bytes` at `0x0062fa40` reads the next `ChangeItemSlotInputPane` RTTI/slot bytes, confirming this page ends before the following prompt class.
- 2026-06-21 B009 PE/Capstone reanalysis confirms whole-image absolute dword scan finds exactly one pointer to [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) at `0x0062fa00`. No direct rel32 callers were found for `0x005b2a70`, which supports the vtable-only virtual route recorded here.
- The constructor stores remain the class-specific three-view ABI: `0x005b2a03 -> [this+0] = 0x0062f9b8`, `0x005b2a09 -> [this+0xa0] = 0x0062fa08`, and `0x005b2a13 -> [this+0xa4] = 0x0062fa38`.

## Assignment Gate

`AUTOGEN_PARENT_UID` is [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md). This source-local child is `90/94`, the direct class parent is `91/93`, and the class routes to the `89/91` [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) source root. The broad [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md) remains `88/92`, parent-blank, non-reconstructable, and non-emitting because it spans several unrelated feature owners.

## Score Rationale

Completion `90` and confidence `94` are supported by the exact 136-byte hash/range, complete 34-cell inventory, all three views, both internal locators, complete RTTI/PMD hierarchy, constructor stores, canonical `OnAccept` slot, shared-wrapper evidence, class declaration route, and compiler-generated marker. Scores remain below 95 because original private symbol spellings and the exact historical translation-unit split are unavailable; no unresolved issue blocks source-ready output.

## Historical Assumptions

- The 2026-06-12/2026-06-21 key-slot-only evidence remains valid dated research, but the current page now records the complete three-view table and RTTI hierarchy.
- Dated references that treated `0x005b2a70` only as an unnamed input handler or `OnCharInput` are superseded by the current `EmotionInputPane::OnAccept` identity. The earlier names are retained as investigation history rather than deleted.
- The former blank formal CPP channel is superseded by the accepted source-local-index marker. The marker does not hand-author ABI data; it directs regeneration through the class declaration.

## Cross-References

- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0002N4][0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData](by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md)

## Changes

- 2026-06-12 A004 Batch 313:
  - Created as the source-local `EmotionInputPane` by-vtable child of [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md).
  - Evidence: live IDA MCP confirmed the three decorated table bases, `0x88` / 136-byte exact span, constructor store at `0x005b2a03`, and successor boundary at `0x0062fa40`.
- 2026-06-21 Rule 26 B009 incorporation:
  - Scores remain `87/92`.
  - Added PE/Capstone route evidence that `0x005b2a70` is reached only through slot `0x0062fa00`, plus the constructor stores for all three vtable bases.
- 2026-08-02 B007 UID0002N4 implementation callback:
  - Before: `87/92`, blank position/formal block, key-slot-only evidence, and unresolved source-facing handler identity.
  - After: `90/94`, position `30`, exact source-local-index marker, complete 34-cell and RTTI/PMD inventories, all three constructor stores, canonical `OnAccept`, and explicit compiler-generated/no-duplicate-source disposition.
