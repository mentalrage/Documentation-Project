*** UID:0003HL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000DT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellSpellInputPane Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `SpellSpellInputPane` primary, secondary, and tertiary vtable views.
- Direct owner: [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md).
- Source context: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).
- Exact data page: [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md).
- Split from: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md), which remains a broad non-emitting mixed-owner index.

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- | --- |
| `SpellSpellInputPane` | [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md) | `0x0063041c` | `0x0063046c` | `0x0063049c` | Dispatcher/open/constructor stores at `0x005a6ac2`, `0x005a9e78`, and `0x005b6167`; accept/key slots remain documented in the exact data page. |

## Boundary Evidence

- Exact span is `0x0063041c-0x006304a4`, or `0x88` / 136 bytes (Verified with int_convert.py).
- 2026-06-12 live IDA MCP `entity_query` lists the three decorated `SpellSpellInputPane` table names at the listed bases.
- 2026-06-12 `get_bytes` reads shared input-pane slot bytes at `0x0063041c`.
- 2026-06-12 `get_bytes` at `0x006304a4` reads the next `WieldInputPane` RTTI/slot bytes, confirming this page ends before the following equipment prompt.
- 2026-06-19 B013 local PE recheck reconfirmed primary accept slot `0x00630464 -> 0x005b6260`, secondary key slot `0x00630474 -> 0x005b61f0`, tertiary adjustor slot `0x0063049c -> 0x005b77d3`, inherited slot `0x006304a0 -> 0x00544e90`, and successor locator `0x006304a4 -> 0x00653704`. It also found no non-vtable route to the key/accept starts, which supports keeping method C++ on exact children.

## Assignment Gate

The semantic `CANONICAL_OWNER` is [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md), but `EMITTER_UIDS` is intentionally blank. This source-local inventory is reconstructable documentation of compiler-generated table effects, not an independent source emitter; the complete class declaration and exact virtual children regenerate the tables without a blank-marker or handwritten `.rdata` body. The class routes to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).

## Score Rationale

Completion `87` and confidence `91` are supported by exact vtable boundaries, decorated names, live dispatcher/open/constructor store refs, and the strict-gate class route. Final slot names and source declaration wording remain below the final-source bar.

## Cross-References

- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md)

## Changes

### 2026-07-20 UID0001MP source-cause synchronization

- The source-local inventory now links the canonical `SpellSpellInputPane::HandleKeyOrTextEvent(Event *)` child UID0001MP at secondary key/text cell `0x00630474 -> 0x005b61f0` and retains UID0001MQ accept at primary cell `0x00630464 -> 0x005b6260`.
- Exact `[0x0063041c,0x006304a4)` primary/secondary/tertiary table views, decorated RTTI bases, constructor/dispatcher/open stores, adjusted complete-object offsets, inherited tertiary slot, and WieldInputPane successor boundary remain unchanged.
- The complete UID0000DT declaration plus exact children are the source cause. R6 remains intentionally blank: compiler/linker output regenerates RTTI, locators, vtables, and adjustors; no fixed dwords or raw arrays are human source.
- Scores become `90/94`; owner/emitter UID0000DT, reconstructable source-covered classification, blank position/formal, and `Nested:0` remain unchanged. Historical stale target title/signature is superseded without deleting table evidence.

- 2026-06-12 A004 Batch 313:
  - Created as the source-local `SpellSpellInputPane` by-vtable child of [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md).
  - Evidence: live IDA MCP confirmed the three decorated table bases, `0x88` / 136-byte exact span, representative stores at `0x005a6ac2`, `0x005a9e78`, and `0x005b6167`, and the `WieldInputPane` successor boundary.
- 2026-06-19 B013 source-quality support sync:
  - Score and ownership unchanged at `87/91`, owner/emitter [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md).
  - Summary/evidence: local PE route scan reconfirmed the accept/key slots, tertiary/inherited slots, successor locator, and vtable-only route to the exact child methods.
