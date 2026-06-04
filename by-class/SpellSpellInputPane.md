*** UID:0000DT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellSpellInputPane

## Status

- Confidence: strong for behavior, vtable identity, and current `SpellInputPanes` placement; medium for final source-level method names.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Vtable data: [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md)
- Reconstruction handling: attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md); C++ remains blank until field names, base declarations, and source names reach the final-source bar.

## Class Purpose

`SpellSpellInputPane` is a spell-selection prompt used when a spell command needs another spell as the argument. It formats a prompt with the current spell name, handles help shortcut input, and converts a letter to a spell index.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SpellSpellInputPane` | [UID:0001MN][0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor](by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md) | Constructs prompt using current spell name and installs vtables. |
| `OnKeyInput` | [UID:0001MP][0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput](by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput.md) | Handles spell help-panel shortcut. |
| `OnAccept` | [UID:0001MQ][0x005b6260-0x005b62c8.SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md) | Converts letter to spell index and calls spell selection. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms the three method functions: constructor `0x005b6120-0x005b61e7`, key handler `0x005b61f0-0x005b625c`, and accept handler `0x005b6260-0x005b62c8`.
- Live IDA confirms the constructor stores the three `SpellSpellInputPane` vtable bases at `0x0063041c`, `0x0063046c`, and `0x0063049c` into offsets `+0x00`, `+0xa0`, and `+0xa4`.
- Live IDA reports the same vtable stores from command/spell factory paths `0x005a5bd0-0x005a7422` and `0x005a9e10-0x005a9ef3`, plus the constructor stores at `0x005b6167`, `0x005b616d`, and `0x005b6177`.
- Live vtable cells tie primary accept slot `0x00630464` to `0x005b6260`, secondary key slot `0x00630474` to `0x005b61f0`, and secondary/tertiary deleting slots to shared adjustor thunks `0x005b77c8` / `0x005b77d3`.
- Live key handler evidence confirms spell help-panel behavior: `do_narrow`, tab switch helper `0x004b8650`, sound/helper call `0x0057a5c0`, and fallback through base key handler `0x004f2920`.
- Live accept-handler evidence confirms spell selection behavior: input decode helpers `0x004f2310` / `0x004f2300`, player/spell data read through `dword_67A748`, range checks, and final selection call `0x005a4530`.
- Live boundary checks confirm padding at `0x005b61e7-0x005b61f0`, `0x005b625c-0x005b6260`, and `0x005b62c8-0x005b62d0` before the next function.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The class now records exact method pages, live function ranges, vtable slots/stores, factory/context refs, key and accept behavior, padding boundaries, parent file placement, and reconstruction gating. |
| Confidence | 86 | Confidence rises because live IDA ties all three methods and all three vtable views to `SpellSpellInputPane`, and the behavior is spell-domain-specific enough to attach to `SpellInputPanes`; final names and declarations remain below the 95/95 bar. |
| Reconstructable | true | The class is NexusTK-owned source behavior, but final C++ remains blank until base declarations, field names, and method names are final-quality. |

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `80`, confidence `76`.
- Evidence: the page documents spell-selection prompt behavior, constructor/key/accept memory docs, vtable family, IDA-confirmed vtable views, and spell-domain placement rationale; confidence remains capped by final spell-input versus command-input source placement.
- 2026-06-04: Completion/confidence changed from `80/76` to `86/86`, `RECONSTRUCTABLE:TRUE` was set, and the class was attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md). Evidence: live IDA MCP confirmed all method boundaries, constructor/vtable stores, vtable slots for accept/key/thunks, factory-path vtable stores, key/accept callee behavior, and exact padding around the method cluster. C++ remains blank because the page is below the final reconstruction bar.
