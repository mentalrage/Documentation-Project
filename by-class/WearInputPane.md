*** UID:0000G0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No standalone class-page emission for WearInputPane; method-cluster evidence is [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md) and packet helper source is [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md).
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WearInputPane

## B003 2026-07-20 Event Contract Synchronization

- The compact `0x005b6630` help override is `bool HandleKeyOrTextEvent(Event *event)`: translate key/modifiers, require translated `?`, exact Shift `0x04`, and key-down, switch tab `2` with `NULL`, play effect `0x198` at 100, return true, otherwise use the existing CharInputPane base handler.
- Wear construction, typed slot validation, packet behavior, children, vtable/compiler evidence, scores, route, formal block, and history remain unchanged. Stale `OnKeyInput`/`InputEvent`/`NarrowInputKey`/`false` wording is superseded only.

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md), plus adjacent exact helper [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md).

## Class Purpose

`WearInputPane` is the equipment-wear prompt. It accepts one inventory slot letter, validates the slot against the local inventory count, and sends the wear packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WearInputPane` | `0x005b6560-0x005b6627` | Constructs the prompt with player name and installs vtables. |
| `OnKeyEvent` | `0x005b6630-0x005b669c` | Handles help-panel shortcut and delegates normal input. |
| `OnSubmitInput` | `0x005b66a0-0x005b6760` | Converts slot letter and sends wear opcode `0x1e`. |
| `SendWearPacket` | [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md) | Raw adjacent helper that writes opcode `0x1e` and a caller-supplied selector byte; no current direct xref to the start. |

## Evidence Notes

- IDA MCP confirms all three function starts.
- IDA MCP recheck on 2026-05-26 resolves neighboring real function `0x005b6500-0x005b6560` as [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)'s packet helper. `WearInputPane` starts at `0x005b6560`.
- IDA MCP recheck on 2026-05-27 confirms the constructor uses prompt id `0x21`, calls `CharInputPane::CharInputPane`, gets the local player name from [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, formats the prompt, and installs vtables `0x00630534`, `0x00630584`, and `0x006305b4`.
- IDA decompilation of `0x005b66a0` confirms slot conversion: lowercase `a-z` becomes `1-26`, uppercase `A-Z` becomes `27-52`, and the accepted value must be between `1` and byte offset `+0x284` from [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md).
- The submit path sends opcode `0x1e`, selector byte, and length `2` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). Use the IDA-confirmed slot formulas above for reconstruction.
- IDA MCP recheck on 2026-06-05 against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirms starts and sizes for `0x005b6560` (`0xc7`), `0x005b6630` (`0x6c`), and `0x005b66a0` (`0xc0`), with `0xcc` padding between modeled methods.
- Current IDA decompilation confirms opcode `0x1e` directly in `OnSubmitInput`: after one-character input and slot bounds validation, it writes opcode `0x1e`, appends the selector byte, writes a zero after the selector, and sends length `2`.
- Linear disassembly of [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md) confirms an adjacent raw helper with the same opcode `0x1e`/selector-byte/two-byte-send shape, `retn 4`, no current direct xref to the start, and a clean boundary before [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md).

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md)
- [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md)
- [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:00028L][0x0067a754-0x0067a758.g_pEventMan](by-memory/0x0067a754-0x0067a758.g_pEventMan.md)
- [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md)
- [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so the Wear method cluster and adjacent helper child assemble under this route. Wear method source is documented by the method cluster and the adjacent helper child.
- Route proof: [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md) covers Wear constructor `0x005b6560-0x005b6627`, key handler `0x005b6630-0x005b669c`, and submit path `0x005b66a0-0x005b6760`. Concrete retained helper source is [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records Wear vtables `0x00630534`, `0x00630584`, and `0x006305b4` with action/input slots.
- Rejected emission: the class page is covered by the method cluster plus helper child, not by a standalone declaration block in this callback.

## Changes

- 2026-06-07 A008 alias cleanup:
  - Before: constructor evidence used bare `dword_67A748` wording for the local-player name source.
  - Changed to: canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording while preserving `dword_67A748` as the historical IDA alias.
  - Evidence: the global page records `0x0067a748` as a broad player/client-state pointer, including item-command prompt views.
- 2026-06-07 A006 Batch 048 split-recheck:
  - Changed completion/confidence from `86/90` to `87/91` after [UID:0002YP][0x005b6760-0x005b67c0.SendWearPacket](by-memory/0x005b6760-0x005b67c0.SendWearPacket.md) was created as an exact child and attached to this class.
  - Evidence: the child page records the raw helper boundary, opcode `0x1e`, selector-byte argument, packet-send length `2`, no direct xrefs to the raw start, and clean separation from [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md).
- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the constructor, key handler, and submit/send path starts at `0x005b6560`, `0x005b6630`, and `0x005b66a0`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-06-05 stale evidence cleanup and helper refresh:
  - What existed before: status/evidence still referenced a stale output path and non-IDA opcode evidence for `0x1e`.
  - Changed to: removed stale output provenance from the class page and replaced opcode/helper support with current IDA MCP decompilation and boundary evidence.
  - Summary/evidence: current IDA MCP confirms opcode `0x1e` in the modeled submit path, confirms the raw adjacent helper at `0x005b6760-0x005b67c0`, confirms no direct xref to the helper start, and confirms [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md) starts cleanly at `0x005b67c0`.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:90`.
  - Summary/evidence: scored from the constructor/key/submit method map, IDA-confirmed prompt id, vtables, slot conversion bounds, opcode `0x1e` send path, and item-action input grouping.
