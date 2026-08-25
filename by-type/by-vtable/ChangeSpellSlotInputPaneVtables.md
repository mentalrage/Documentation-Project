*** UID:0003HJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00001M | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00001M | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChangeSpellSlotInputPane Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `ChangeSpellSlotInputPane` primary, secondary, and tertiary vtable views.
- Direct owner: [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md).
- Source context: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).
- Exact data page: [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md).
- Split from: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md), which remains a broad non-emitting mixed-owner index.

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- | --- |
| `ChangeSpellSlotInputPane` | [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md) | `0x0062fad0` | `0x0062fb20` | `0x0062fb50` | Dispatcher/open/raw-constructor stores at `0x005a61d7`, `0x005a9486`, and `0x005b323f`; submit/key slots remain `0x005b32d0` and `0x005b3260`. |

2026-06-20 B002 source-quality incorporation confirms the method slots now route to source-ready exact child pages: primary slot `0x0062fb18 -> 0x005b32d0` emits `ChangeSpellSlotInputPane::SubmitSpellSlotChange`, and secondary slot `0x0062fb28 -> 0x005b3260` emits `ChangeSpellSlotInputPane::OnKeyInput`. The vtable pages themselves still keep formal C++ blank because these bytes are compiler-emitted table data generated from the class declaration, not handwritten source.

## Boundary Evidence

- Exact span is `0x0062fad0-0x0062fb58`, or `0x88` / 136 bytes (Verified with int_convert.py).
- 2026-06-12 live IDA MCP `entity_query` lists the three decorated `ChangeSpellSlotInputPane` table names at the listed bases.
- 2026-06-12 `get_bytes` reads shared input-pane slot bytes at `0x0062fad0`.
- 2026-06-12 `get_bytes` at `0x0062fb58` reads the next `SayInputPane` RTTI/slot bytes, confirming this page ends before the following prompt family.

## Assignment Gate

`AUTOGEN_PARENT_UID` is [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md). The child is `87/91`, and the direct class parent clears `86/86`; the class already routes to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).

## Score Rationale

Completion `87` and confidence `91` are supported by exact vtable boundaries, decorated names, dispatch/open/raw-constructor store refs, key slot evidence, and the strict-gate class route. Confidence remains below final-source quality because the projected constructor start is still not an IDA function object.

## Cross-References

- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md)

## Changes

- 2026-06-12 A004 Batch 313:
  - Created as the source-local `ChangeSpellSlotInputPane` by-vtable child of [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md).
  - Evidence: live IDA MCP confirmed the three decorated table bases, `0x88` / 136-byte exact span, representative stores at `0x005a61d7`, `0x005a9486`, and `0x005b323f`, and the `SayInputPane` successor boundary.
- 2026-06-20 B002 Rule 26 support sync: documented that the key and submit slots now point to exact child pages with first-draft method C++, while vtable data remains generated/no-formal-C++ support.
