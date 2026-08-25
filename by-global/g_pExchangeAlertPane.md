*** UID:0000QV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static ExchangeAlertPane *g_pExchangeAlertPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pExchangeAlertPane

## Status

- Address: `0x0069b330` (`dword_69B330` in IDA)
- Symbol kind: process-wide singleton pointer
- Likely owner file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Confidence: strong.

## Purpose

`g_pExchangeAlertPane` guards the active exchange alert dialog. `ExchangeAlertPane` stores itself during construction, clears the pointer during destruction, and exchange packet handlers close the active alert before creating a replacement.

## Evidence

- IDA xrefs to `0x0069b330` include `ExchangeAlertPane` constructor storage at `0x004b04ff`/`0x004b0506`, destructor cleanup at `0x004b09d6`, singleton-clear helper `0x004b0860`, and close-active helper `0x004b0b20`.
- Exchange packet helpers reference the pointer at `0x004ad611`, `0x004ad739`, `0x004addd3`, and `0x004adf51` before showing cancel/ready alert messages.
- Adjacent globals are separate: `dword_69B328` is the item picker singleton and `dword_69B32C` is the mix dialog singleton.
- 2026-06-14 A003 live IDA MCP refresh reconfirmed exactly nine refs to `0x0069b330`: four packet-handler reads/close checks, constructor publish/fallback clear at `0x004b04ff`/`0x004b0506`, clear helper at `0x004b0860`, scalar deleting destructor clear at `0x004b09d6`, and close-active helper read at `0x004b0b20`.
- 2026-06-14 decompilation confirms `ExchangeAlertPane` constructor `sub_4B0490` is `0x389` / 905 bytes (Verified with int_convert.py), publishes/fallback-clears the singleton, installs the three `ExchangeAlertPane` vtable views, and builds the alert UI from exchange message inputs.
- 2026-06-14 decompilation confirms clear helper `sub_4B0860` is `0xb` / 11 bytes (Verified with int_convert.py), scalar deleting destructor `sub_4B09D0` is `0x45` / 69 bytes (Verified with int_convert.py), and close-active helper `sub_4B0B20` is `0x11` / 17 bytes (Verified with int_convert.py) and dispatches the active pane's virtual close/delete path when the singleton is non-null.
- 2026-06-14 packet-handler refresh confirms `sub_4AD320` is `0x493` / 1171 bytes, `sub_4ADD40` is `0x11f` / 287 bytes, and `sub_4ADE60` is `0x14c` / 332 bytes (Verified with int_convert.py); these packet handlers read/close the active exchange alert before constructing replacement cancel/ready alert panes.
- 2026-06-30 B011 current MCP refresh confirms exact storage [UID:0002VZ][0x0069b330-0x0069b334.g_pExchangeAlertPane](by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md) currently contains bytes `00 00 00 00`, so the source definition is a null-initialized file-local singleton pointer, not an explicit `0xffffffff` initializer.

## Autogen And Score Rationale

- Owner/emitter route remains [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md), which surfaces to `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` without a dead end.
- Completion is raised to `88` because the page now records the exact xref set, constructor/destructor/clear/close-helper boundaries, packet-handler consumer windows, adjacent-singleton distinction, current zero-initialized storage bytes, and formal source declaration.
- Confidence is raised to `92` because current IDA xrefs, decompilation, storage bytes, and owner/emitter route support the singleton identity and ExchangeDialog owner. It remains below final audit because final alert-message parameter names and packet-handler source names are not fully reconstructed.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, owner, singleton purpose, constructor/destructor/clear/close helper xrefs, packet-handler uses, adjacent singleton distinction, and class/file/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). Evidence: live IDA MCP reports nine xrefs to `0x0069b330`, including exchange packet handlers at `0x004ad611`, `0x004ad739`, `0x004addd3`, and `0x004adf51`, plus constructor/destructor/clear/close helpers at `0x004b0490`, `0x004b0860`, `0x004b09d0`, and `0x004b0b20`.
- 2026-06-14 A003 goal2 score pass: raised `86/84` to `87/90`.
  - Evidence: live IDA MCP reconfirmed the nine-ref singleton map, constructor/clear/deleting-destructor/close-helper decompilation, packet-handler consumer windows, adjacent singleton separation, and non-dead-ended ExchangeDialog owner/emitter route.
  - Code-entry decision: no reconstruction C++ was added; the route and numeric gate are present, but final declaration and alert parameter/source names remain below source-quality evidence.
- 2026-06-30 B011 accepted ExchangeDialog empty-emitter implementation:
  - Before: this page had blank formal C++ despite owning the source-level singleton.
  - After: score is `88/92`, and the formal block emits `static ExchangeAlertPane *g_pExchangeAlertPane = NULL;`.
  - Evidence: current MCP confirms the nine-ref singleton map and current storage bytes `00 00 00 00`; [UID:0002VZ][0x0069b330-0x0069b334.g_pExchangeAlertPane](by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md) now records that exact storage is covered by this source global definition.
