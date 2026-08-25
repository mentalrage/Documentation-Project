*** UID:0000S9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SimpleHelpPane *g_pSimpleHelpPane = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern SimpleHelpPane *g_pSimpleHelpPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pSimpleHelpPane

## UID0000KA External Consumer Declaration - 2026-08-15

- `InventoryPane.cpp` is an external HelpPanes consumer, so the owner route now
  emits one externally linked `SimpleHelpPane *g_pSimpleHelpPane = NULL;`
  definition and the matching formal-H `extern` declaration.
- The prior file-local `static` definition is retained below as historical
  pre-callback source shape. Exact storage, lifetime behavior, UID0001PC
  covered-by status, owner/emitter metadata, and score are unchanged.

## Status

- Address: [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md)
- Symbol kind: process-wide singleton pointer.
- Likely owner file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Preferred source name: `g_pSimpleHelpPane`.
- Confidence: strong.

## Purpose

`g_pSimpleHelpPane` points to the active [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md), the older timed text tooltip popup. The formal source now emits one externally linked definition, the matching header declaration, and the existing `[[CHILDREN]]` insertion point. The former `static ... = nullptr` declaration was the historical pre-callback shape and could not serve external consumers. The exact storage child [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) must not emit a second definition; it records the binary storage and covered-by route. The constructor writes it, teardown clears it, and feature callers use it to avoid overlapping simple help popups.

## Evidence Notes

- 2026-06-14 live IDA MCP reports `0x0069ae00` as an exact four-byte `.data` singleton slot with current zero-filled IDB bytes and 23 data references. This supersedes older `0xff 0xff 0xff 0xff` initialization wording.
- 2026-06-16 live IDA MCP rechecked the same zero-filled storage window and 23 data references, then saved `SimpleHelpPane_Constructor`, `SimpleHelpPane_Destructor`, `SimpleHelpPane_ScalarDeletingDestructor`, and `CloseSimpleHelpPaneSingleton`. `ClearSimpleHelpPaneSingleton` was already present in the IDB.
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) contains the core lifetime sites: `SimpleHelpPane` construction stores the active pointer at `0x004c6ff1`, the same path clears it on null fallback at `0x004c6ff8`, ordinary teardown clears it at `0x004c72e8`, a compact unwind/support helper clears it at `0x004ce330`, and the scalar deleting destructor clears it at `0x004ce5bf`.
- [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md) includes a singleton close helper at `0x004a0d60` that reads this pointer and calls the first virtual slot with flag `1` when an active pane exists.
- Feature/UI callers read the pointer before opening or updating simple help popups, including `0x0049e5bd`, `0x004cef6c`, `0x004ead71`, `0x004eafca`, `0x004edad1`, `0x004edf2a`, `0x004ef368`, `0x004ef5b1`, `0x004fc7cc`, `0x00568d2e`, `0x00568d41`, `0x00568e03`, `0x00569892`, `0x00571d25`, `0x005a15e5`, `0x005b8a4b`, and `0x005bdff4`.
- The live xref set supports `g_pSimpleHelpPane` as the canonical singleton pointer; no separate storage was observed for the alias variants.

## Score Rationale

Completion is `87` because storage bytes, width, all 23 direct refs, constructor publish/guard clear, ordinary/helper/scalar-destructor clears, close-helper use, feature consumers, owner/emitter routing, and the emitted singleton declaration route are current and IDA labels are saved. Confidence is `90` for singleton identity and lifecycle; final declaration/header placement and the future HelpPanes versus narrower tooltip-source split remain open, but the source now emits the conservative file-local pointer declaration plus child insertion point.

## Cross-References

- [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md)

## Changes

- 2026-06-05: Marked reconstructable and attached to [UID:0000JU][HelpPanes](by-file/HelpPanes.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to the `SimpleHelpPane` constructor, teardown, close-helper, and feature callers within the HelpPanes tooltip module. No score change and no reconstruction C++ were added.
- What existed before: the page had correct address and role notes but still had unevaluated completion/confidence metadata and stale raw-label wording.
- What changed to: the page now uses the live IDA MCP xref set for storage shape, lifetime writes, close-helper reads, and feature callers. Completion/confidence were set to `78/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069ae00` as a four-byte `.data` singleton pointer with 23 xrefs, constructor assignment at `0x004c6ff1`, fallback clear at `0x004c6ff8`, destructor/cleanup clears at `0x004c72e8`, `0x004ce330`, and `0x004ce5bf`, and close-helper read at `0x004a0d60`.
- 2026-06-06: Raised completion from `78` to `84` and removed raw storage-label wording.
  - Reasoning: current live IDA MCP verifies exact initialized storage bytes, all 23 data references, constructor publish and fallback clear, ordinary destructor clear, unwind/support clear, scalar deleting destructor clear, the close helper, and broad feature consumers. The page remains below final-reconstruction quality because exact source spelling and neighboring helper ownership are still not final.
  - Summary and evidence: the 2026-06-06 pass treated `0x0069ae00` as an exact four-byte `.data` singleton slot and recorded xrefs covering publish `0x004c6ff1`, fallback clear `0x004c6ff8`, teardown clears `0x004c72e8`, `0x004ce330`, and `0x004ce5bf`, close-helper read `0x004a0d60`, and feature reads through `0x005bdff4`; the byte wording from that pass is superseded by the 2026-06-14 live IDB read above.
- 2026-06-14 A001 support sync:
  - Changed to: score `85/88`, current zero-filled IDB byte wording, and backing-storage score sync with [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md).
  - Summary/evidence: live IDA rechecked all 23 direct refs, constructor publish/fallback clear, ordinary destructor clear, compact helper clear, scalar deleting destructor clear, close-helper read, feature consumers, and the unchanged [UID:0000JU][HelpPanes](by-file/HelpPanes.md) emitter route. C++ remains blank because final declaration spelling and source split are still open.
- 2026-06-16 C001 Goal 2 safe IDA refresh:
  - Changed to: score `87/90`; owner/emitter retained [UID:0000JU][HelpPanes](by-file/HelpPanes.md).
  - Summary/evidence: live IDA rechecked the zero-filled storage window and 23 refs, saved constructor/destructor/scalar-deleting/close-helper labels, confirmed the existing clear-helper label, and investigated final declaration/header and tooltip-source split blockers. No type/prototype/member changes were made.
- 2026-06-30 B004 HelpPanes empty-emitter first batch:
  - Added formal singleton declaration `static SimpleHelpPane *g_pSimpleHelpPane = nullptr;` plus `[[CHILDREN]]`.
  - Preserved owner/emitter routing through [UID:0000JU][HelpPanes](by-file/HelpPanes.md) and recorded that exact storage child [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) is a covered/no-duplicate route, not a second definition.
