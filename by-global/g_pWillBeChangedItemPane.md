*** UID:0000SS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WillBeChangedItemPane *g_pWillBeChangedItemPane = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pWillBeChangedItemPane

## Status

- Address: [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md)
- Symbol kind: process-wide singleton pointer.
- Owner file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md); the unsupported narrower `ui/controls/WillBeChangedPanes.cpp` alternative is rejected.
- Current generated names: `g_pWillBeChangedItemPane`, `dword_69B414`
- Confidence: very strong for exact storage, lifecycle, class role, external one-definition route, and owner family.
- Exact storage evidence: current MCP reads [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md) as a four-byte `.data` slot with bytes `00 00 00 00` / value `0`, five direct data xrefs, and separation from adjacent [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md). Older `ff ff ff ff` / `0xffffffff` wording is superseded.

## Purpose

`g_pWillBeChangedItemPane` points to the active [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md), the temporary item slot/change preview pane. This semantic page owns the sole externally linked C++03 definition `WillBeChangedItemPane *g_pWillBeChangedItemPane = NULL;` with the `[[CHILDREN]]` insertion point. Exact storage child [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md) is false/non-emitting and physically blank. The singleton remains distinct from adjacent MetaMan storage and stays with the HelpPanes tooltip/preview overlay family.

2026-05-28 IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) includes `ClearWillBeChangedItemPaneSingleton` at `0x004ce340`, which writes zero to this storage from constructor/destructor unwind cleanup.

Treat the `0x0069b410-0x0069b418` adjacency as physical storage locality, not as source-level grouping with `MetaMan`. The declaration belongs with the help/tooltip temporary preview pane source family. `HelpPanes.cpp` is the strongest current route; no build, object, source-path, or exclusive-rdata evidence supports a separate `WillBeChangedPanes.cpp`.

## Evidence Notes

- IDA MCP storage check reports a 4-byte `.data` item at `0x0069b414` with 5 data references.
- `simroot_v2/class_WillBeChangedItemPane.cpp` writes and clears this storage as `g_pWillBeChangedItemPane`.
- 2026-06-30 B004 current MCP recheck supersedes the older 2026-05-31 initializer wording: `get_bytes`/`get_int` read `0x0069b414` as `00 00 00 00` / `0`, not `ff ff ff ff` / `0xffffffff`. The five direct xrefs remain constructor set/cleanup at `0x004c7939` and `0x004c7940`, event/destructor clear at `0x004c7b9a`, helper clear at `0x004ce340`, and scalar-deleting destructor clear at `0x004ce690`.
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md) records the item preview constructor, non-deleting reset body, paint path, event and key dismissal handlers, sibling spell-preview pane, exact padding, and constructor caller `0x004ed40f`.
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) records the `WillBeChangedItemPane` adjustor thunks and scalar deleting destructor at `0x004ce670-0x004ce6cf`, including the singleton clear at `0x004ce690`.
- [UID:00025G][0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData](by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md) records the `WillBeChangedItemPane` vtables in the help/item-help read-only data span.

## Cross-References

- [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md)
- [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- [UID:00025G][0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData](by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md)
- [UID:0001PJ][0x0069b410-0x0069b414.g_pMetaMan](by-memory/0x0069b410-0x0069b414.g_pMetaMan.md)

## 2026-07-21 B003 One-Definition Closure

- Score is `92/94`; owner/emitter remain UID0000JU, reconstructable true, optional position blank.
- Initializer `NULL` matches the loader-zero-filled four-byte physical slot and the project's C++03-era source. File-local `static`, C++11 `nullptr`, a second by-memory declaration, raw `dword_69B414`, and explicit Singleton publish/clear statements are rejected.
- Five exact writes/clears and zero reads are preserved: constructor publish/fallback at `0x004c7939/0x004c7940`, ordinary-destructor clear at `0x004c7b9a`, EH cleanup clear at `0x004ce340`, and scalar-wrapper clear at `0x004ce690`.
- Direct `Singleton<WillBeChangedItemPane>` inheritance regenerates lifecycle stores. Authored source has one external definition here, an `extern` declaration after the complete class in UID0000G5, and no duplicate storage source.
- The exact ten-child method split [UID:0004V4][0x004c78e0-0x004c7b76.WillBeChangedItemPaneConstructor](by-memory/0x004c78e0-0x004c7b76.WillBeChangedItemPaneConstructor.md) through [UID:0004VD][0x004c8290-0x004c82cf.WillBeChangedSpellPaneHandleKeyOrTextEvent](by-memory/0x004c8290-0x004c82cf.WillBeChangedSpellPaneHandleKeyOrTextEvent.md) carries all item/spell preview behavior while this page supplies only the semantic global definition and child insertion point.

## Changes

- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and no autogen parent.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000JU][HelpPanes](by-file/HelpPanes.md), and ordered file-local position `70`.
  - Summary/evidence: IDA MCP confirms the exact singleton storage, initial value, constructor store, destructor/helper clears, and separation from adjacent `g_pMetaMan`; final C++ remains blank because the exact split between `HelpPanes.cpp` and a possible `WillBeChangedPanes.cpp` is still open.
- 2026-06-06: Raised `COMPLETION` from `74` to `86` and `CONFIDENCE` from `86` to `89`.
  - Added current exact storage evidence, preview-pane executable range support, destructor/thunk support, read-only vtable evidence, and a source-adjacency caveat separating this slot from `g_pMetaMan`.
  - Evidence: existing IDA-backed docs now account for the singleton slot in [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md), the item/spell preview code range in [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md), destructor behavior in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md), vtables in [UID:00025G][0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData](by-memory/0x0061aad0-0x0061b340.HelpItemHelpReadOnlyData.md), and source-family ownership in [UID:0000JU][HelpPanes](by-file/HelpPanes.md). The broader final source split and class-layout/member names remain below final-audit quality, but the 2026-06-30 B004 entry now emits the conservative singleton pointer declaration.
- 2026-06-30 B004 HelpPanes empty-emitter first batch:
  - Added formal singleton declaration `static WillBeChangedItemPane *g_pWillBeChangedItemPane = nullptr;` plus `[[CHILDREN]]`.
  - Corrected the current storage-byte wording to `00 00 00 00` / `0` from the accepted MCP-backed report, superseding older `ff ff ff ff` / `0xffffffff` wording.
  - Preserved owner/emitter routing through [UID:0000JU][HelpPanes](by-file/HelpPanes.md) and recorded that exact storage child [UID:0001PK][0x0069b414-0x0069b418.g_pWillBeChangedItemPane](by-memory/0x0069b414-0x0069b418.g_pWillBeChangedItemPane.md) is a covered/no-duplicate route, not a second definition. [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md), [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md), and [UID:0000G6][WillBeChangedSpellPane](by-class/WillBeChangedSpellPane.md) remain follow-up split/class work.
