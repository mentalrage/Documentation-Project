*** UID:0000R7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IMEPane *g_pIMEPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pIMEPane

## Status

- Address: [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- Symbol kind: process-wide singleton pointer.
- Likely owner file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Dated 2026-08-12 IDA identity: `g_pIMEPane`, type `IMEPane *`, zero-valued storage, 17 exact xrefs.
- Historical aliases: `DAT_0069b458`, `dword_69B458`, and `unk_69B458`; retain these as provenance, not current source names.
- Confidence: strong.

## Purpose

`g_pIMEPane` points to the active [UID:00006H][IMEPane](by-class/IMEPane.md). It is used by the pane-side IME UI and text-entry controls to find the active focus-pane list, composition/candidate popup state, caret anchor position, and currently focused input control.

The root object also carries an active child/popup pane pointer at offset `+0xfc`. [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) reads `g_pIMEPane + 0xfc` when the candidate popup would exceed the screen bottom and uses the active child pane bounds as the alternate vertical anchor.

## Evidence Notes

- IDA MCP xrefs to `0x0069b458` include writes in `IMEPane::IMEPane` and clear helpers/destructors at `0x004e85b0` and `0x004e8720`.
- IDA MCP xrefs include IME popup methods `0x004e7470`, `0x004e7640`, `0x004e7930`, `0x004e7b70`, and `0x004e81b0`.
- 2026-06-17 B001 source-quality reanalysis of [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) confirms the `0x004e7930` use of `g_pIMEPane` is candidate-popup geometry state, specifically the active child/popup pane pointer at root offset `+0xfc`.
- IDA MCP xrefs include text-entry callers around `0x0058dce0`, `0x0058e140`, `0x0058ea80`, and `0x00595390`, matching text-edit/text-box focus registration.
- Historical 2026-05-26 IDA MCP storage evidence reported item head `0x0069b458`, size 4, segment `.data`, raw name `dword_69B458`, and 17 data references. The dated 2026-08-12 entity query supersedes only that active-name projection: it returns `g_pIMEPane`, while current inspect-items type projection is `IMEPane *` and storage remains zero.
- 2026-06-30 B008 current MCP `get_bytes`, `get_int`, and `get_global_value` on active session `supervisor_resume_20260629` report current bytes `00 00 00 00`, `u32le=0`, and global values `0x0` for `0x0069b458` / `dword_69B458` / `unk_69B458`. The correct source-level initializer is `IMEPane *g_pIMEPane = NULL;`; older `ff ff ff ff` / `0xffffffff` wording is historical/stale for the active IDB.
- The exact 17 dated-snapshot xrefs are `0x004e74b0`, `0x004e7689`, `0x004e77c2`, `0x004e77d3`, `0x004e7a83`, `0x004e7c46`, `0x004e7f68`, `0x004e7f6f`, `0x004e8079`, `0x004e8391`, `0x004e85b0`, `0x004e87a0`, `0x004f64ac`, `0x0058e0d0`, `0x0058e1ff`, `0x0058ead2`, and `0x0059545a`.

## Ownership Notes

- Keep this global with [UID:0000K5][IMEPanes](by-file/IMEPanes.md), not with [UID:0000K6][InputMan](by-file/InputMan.md). `InputMan` feeds IME events from Win32, but this singleton owns the pane-side state and child popup lifetimes.
- `DAT_0069b458`, `dword_69B458`, and `unk_69B458` are historical reverse-engineering aliases. Human source and current analysis-facing documentation use `g_pIMEPane`; the sole formal definition remains `IMEPane *g_pIMEPane = NULL;`.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:00006H][IMEPane](by-class/IMEPane.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Changes

- 2026-08-12 B006 UID00031K accepted implementation callback:
  - Preserved `90/90`, owner/emitter UID0000K5, reconstructable true, and the exact formal singleton definition.
  - Recorded the dated IDA identity `g_pIMEPane`, type `IMEPane *`, zero value, and exact 17-xref set. Historical `DAT_0069b458`/`dword_69B458`/`unk_69B458` observations remain retained but no longer describe current source or analysis identity.
- 2026-06-30 B008 implementation callback:
  - Before: score was `88/86` and formal C++ was blank.
  - Changed to: score `90/90` and formal global declaration `IMEPane *g_pIMEPane = NULL;`.
  - Summary/evidence: current MCP zero/null storage evidence, 17 xrefs, constructor publication/fallback clear, destructor/helper/scalar clears, and accepted B008 source route through [UID:0000K5][IMEPanes](by-file/IMEPanes.md).
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/86`. Summary/evidence: the page documents memory range, aliases, singleton purpose, IME/text-entry xrefs, storage check, ownership notes, alias normalization guidance, and class/file/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000K5][IMEPanes](by-file/IMEPanes.md). Evidence: live IDA MCP reports 17 xrefs to `0x0069b458`; decompilation confirms constructor `0x004e7f20`, clear helper `0x004e85b0`, and destructor path `0x004e8720` write/clear `dword_69B458`.
- 2026-06-17 B001 support update: added the active child/popup pane role at `g_pIMEPane+0xfc` from [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md).
