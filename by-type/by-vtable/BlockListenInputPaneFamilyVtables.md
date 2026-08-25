*** UID:0003HN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// BlockListenInputPaneFamilyVtables is a vtable-family index over [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md).
// Exact class methods and constructors emit through their child pages; the vtable bytes
// are compiler-generated from declarations and should not be duplicated here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BlockListen Input Pane Family Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `BlockListenInputPane`, `AddToBlockListenInputPane`, and `DeleteFromBlockListenInputPane` vtable views.
- Direct owner: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).
- Exact data page: [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md).
- Split from: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md), which remains a broad non-emitting mixed-owner index.

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- | --- |
| `BlockListenInputPane` | `0x0063064c-0x006306d4` | `0x0063064c` | `0x0063069c` | `0x006306cc` | Dispatcher/open/raw-constructor stores at `0x005a72af`, `0x005aa336`, and `0x005b68df`. |
| `AddToBlockListenInputPane` | `0x006306d8-0x00630760` | `0x006306d8` | `0x00630728` | `0x00630758` | Dispatch/raw-constructor stores at `0x005b6b0a` and `0x005b6c9f`. |
| `DeleteFromBlockListenInputPane` | `0x00630764-0x006307ec` | `0x00630764` | `0x006307b4` | `0x006307e4` | Dispatch/raw-constructor stores at `0x005b6bd5` and `0x005b711f`. |

## Boundary Evidence

- Exact span is `0x0063064c-0x006307ec`, or `0x1a0` / 416 bytes (Verified with int_convert.py).
- 2026-06-12 live IDA MCP `entity_query` lists nine decorated table names across the three block-list prompt classes.
- 2026-06-12 `get_bytes` reads shared input-pane slot bytes at `0x0063064c`.
- 2026-06-12 `get_bytes` at `0x006307ec` reads UTF-16 `Right cl`, confirming this page ends before the following right-click-look string data and does not include that literal as vtable slots.

## Assignment Gate

`AUTOGEN_PARENT_UID` is [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md). The child is `88/92`, and the direct file parent clears `90/91` after the B007 empty-emitter audit. A class parent would be too narrow because this page spans three block-list prompt classes. Formal reconstruction content is a no-code index marker because [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md) owns exact data evidence, and class/method children own source bodies.

## Score Rationale

Completion `88` and confidence `92` are supported by exact three-class vtable boundaries, decorated names, representative store refs, string-data successor evidence, the strict-gate file route, and the formal no-code index marker. Confidence remains below final-source quality because several raw constructor starts are still not IDA function objects.

## Cross-References

- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md)
- [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)

## Changes

- 2026-06-12 A004 Batch 313:
  - Created as the source-local block-list by-vtable child of [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md).
  - Evidence: live IDA MCP confirmed nine decorated table names, `0x1a0` / 416-byte exact span, representative stores for all three classes, and the UTF-16 `Right click look :ON` successor boundary at `0x006307ec`.
- 2026-07-01 B007 empty-emitter implementation callback: raised `87/91` to `88/92` and inserted the formal vtable-family index no-code marker. Exact data evidence remains on [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md), while constructors/methods emit through exact child pages; this page must not duplicate generated-binary vtable bytes as C++.
