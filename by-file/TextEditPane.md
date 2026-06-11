*** UID:0000ON | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# TextEditPane

## Status

- Confidence: strong for `TextEditPane`, `TextEditScrap`, `TextEditObject`, `EPFTextEditObject`, `TextRunMeasureCallback`, and `DrawTextRunCallback` belonging to one text-edit implementation module; `TextFilter` is now treated as a neighboring separate file rather than a confidence limiter for this module.
- Proposed module: `ui/controls/TextEditPane.cpp`
- Proposed header: `ui/controls/TextEditPane.h`
- Current recovered sources: `source-3/simroot_v2/class_TextEditPane.cpp`, `class_TextEditScrap.cpp`, `class_TextEditObject.cpp`, `class_EPFTextEditObject.cpp`, and `recovered/DrawTextRunCallback_00593DB0.cpp`
- Main address clusters: `0x0058dce0-0x005917c9`, `0x00591d60-0x00594e11`, [UID:0002XX][0x00594e60-0x00595760.TextEditSupportObjects](by-memory/0x00594e60-0x00595760.TextEditSupportObjects.md), and mixed scrollbar handler families at `0x0055d960-0x00565488`

## File Role

This module owns the rich text editing pane used by dialogs and input controls. It combines scrollable pane behavior, styled UTF-16 text storage, caret and selection state, clipboard scrap handling, text-run layout, drawing, keyboard/mouse editing, and optional EPF-backed inline text objects.

`TextEditPane` should stay separate from [UID:0000NF][ScrollBar](by-file/ScrollBar.md). It contains many scrollbar tracking handlers, but those are editor-specific consumers of the generic `ScrollPane` geometry and scroll-widget APIs.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `TextEditPane` | `0x0058dce0-0x00594e11` plus scrollbar families | Rich text editor pane: construction, text lists, style runs, wrapping, draw, key/mouse input, caret, selection, scrolling, and editing commands. |
| [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md) | `0x0058e380-0x0058e3d7` | Bounded UTF-16 text copy helper used by [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) and other input/text callers. |
| `TextRunMeasureCallback` | `0x00593c20-0x00593ce4` | File-local/free callback used by text-run iteration/layout to accumulate remaining row width. |
| `DrawTextRunCallback` | `0x00593db0-0x00593ef5` | File-local/free callback passed to `TextEditPane::IterateTextRuns` by draw and invalidation paths. |
| [UID:0002XX][0x00594e60-0x00595760.TextEditSupportObjects](by-memory/0x00594e60-0x00595760.TextEditSupportObjects.md) | `0x00594e60-0x00595760` | Exact child split for `TextEditObject`, `TextEditScrap`, `EPFTextEditObject`, and the trailing alignment before `TextFilter`. |
| `TextEditObject` | `0x00594e60-0x005956ad` in small ranges | Base object for inline/edit payloads, derived from `LObject`. |
| `TextEditScrap` | `0x00594f30-0x00595759` in small ranges | Clipboard scrap buffer storing copied UTF-16 text and optional style payload. |
| `EPFTextEditObject` | `0x005954c0-0x0059566d` | Inline text edit object that loads `SYMBOLS.EPF` or `SYMBOLS.EPD` frames. |
| Text-edit free helpers | `0x005917d0`, `0x00594b50` | Clipboard publication and word-boundary/navigation helpers used by `TextEditPane`. |
| `EncodeTextEditState` | `0x0058e490-0x0058e690` | Serializes text-edit table buffers through [UID:00004F][Encoder](by-class/Encoder.md). |
| [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md) | `0x0069be00` | Active editor pointer used by editor commands and [UID:0000IH][CopyWindow](by-file/CopyWindow.md). |

## Ownership Decision

Keep the support classes and file-local callbacks in this module for now. The address order is tightly clustered after the main editor methods, and their behavior is text-editor internal rather than general UI infrastructure. `TextEditScrap` is constructed directly in `TextEditPane` copy/cut/paste paths, `TextEditObject` and `EPFTextEditObject` support styled/embedded text payloads, and `TextRunMeasureCallback` / `DrawTextRunCallback` are only meaningful as callback bodies for `TextEditPane::IterateTextRuns`.

Keep [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) as a neighboring adapter file. It is a `ControlPane` wrapper with broad dialog constructor fan-in and control type `5`; it allocates and owns a `TextEditPane`, but it is not the editor implementation itself.

Keep [UID:0000OO][TextFilter](by-file/TextFilter.md) as a separate file. It sits immediately after the text-edit support objects, but its singleton startup and chat/mail sanitization behavior make it broader than one editor pane. The split boundary is now documented by [UID:0002XX][0x00594e60-0x00595760.TextEditSupportObjects](by-memory/0x00594e60-0x00595760.TextEditSupportObjects.md) and [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md).

Keep [UID:0000IH][CopyWindow](by-file/CopyWindow.md) as a neighboring dialog source. It consumes the active editor pointer and calls `TextEditPane::SelectAll`, but it is an `AlertPane` subclass with its own vtable and current Wave2 source-file evidence for `CopyWindow.cpp`.

## Evidence Notes

- `TextEditPane::TextEditPane` constructs a `ScrollablePane`, installs three text-edit vtables, stores `g_pActiveTextEditPane` unless style flags suppress it, creates four `List` tables, seeds empty text, configures scrollbars, and installs IME focus through `g_pIMEPane`.
- [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md) is the same address that generated `class_CopyWindow.cpp` currently calls `g_pCopyWindowTextEditPane`.
- 2026-05-26 `simroot_v2` recheck: this file now owns the canonical `TextEditPane* g_pActiveTextEditPane` declaration, but `class_CopyWindow.cpp` still has the narrow alias and should be normalized during source migration.
- Earlier generated metadata reports broad text-edit class ranges, but IDA must remain the source of truth for ownership and boundaries.
- IDA MCP reports 26 direct references to the `TextEditPane` constructor at `0x0058dce0`.
- `TextEditPane` uses internal lists at offsets `0x134`, `0x138`, `0x13c`, and `0x140` for text, line break, style/run, and format records.
- [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md) confirms the `+0x134` text storage pointer is used for bounded copy-out and null termination.
- `TextEditPane::OnDraw` and `TextEditPane::InvalidateSelection` both pass `DrawTextRunCallback` into `IterateTextRuns`.
- IDA data xrefs pass `0x00593c20` as another text-run callback from TextEditPane layout/formatting code; current IDA has no function or xrefs at the generated `0x00593b20` marker.
- `TextEditPane::OnDraw` and `TextEditPane::InvalidateTextRegion` call [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md), a shared GrafPort/surface helper currently emitted under BowGaugeObjectPane.
- `TextEditScrap` owns the stack/local clipboard object path used by copy, cut, paste, and selection publication.
- `EPFTextEditObject` checks `g_useEPFFormat` and loads symbol frames from `SYMBOLS.EPF` or `SYMBOLS.EPD` through `g_pEPFResourceManager`.
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md) is the only confirmed direct consumer of the [UID:00004F][Encoder](by-class/Encoder.md) write family. IDA xrefs reach it through a raw UI-control thunk at `0x00498c4a`, so final wrapper ownership remains open, but the serialized offsets belong to text-edit state.

## Current Caveats

- `class_TextEditPane.cpp` contains generated helper-name pollution from unrelated feature classes such as `RankingEventListPane` and fitting-room text helpers. Treat those names as provisional unless the underlying address is verified.
- `simroot_v2/class_FittingRoomDownloadControlPane.cpp` emits projected text helper markers at `0x00593b20` and `0x00593f00`, but IDA currently reports both as not functions with no xrefs. The real nearby text-edit callback start is `0x00593c20`.
- `class_TextEditPane.cpp` has a split `NTK_ScopedInstall(~TextEditPane` marker across two lines at the destructor, which is a Wave3 codegen issue tracked in [Wave3 Noticed Problems](../wave3_noticed_problems.md).
- The exact original split between `TextEditPane.cpp`, `TextEditObject.cpp`, and `TextEditScrap.cpp` is not proven. Current evidence favors one implementation module because the classes are tightly coupled and contiguous.

## Cross-References

- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0000EN][TextEditObject](by-class/TextEditObject.md)
- [UID:00004H][EPFTextEditObject](by-class/EPFTextEditObject.md)
- [UID:0000EP][TextEditScrap](by-class/TextEditScrap.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:0000OO][TextFilter](by-file/TextFilter.md)
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md)
- [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md)
- [UID:0001JM][0x0058dce0-0x005917c9.TextEditPaneCore](by-memory/0x0058dce0-0x005917c9.TextEditPaneCore.md)
- [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md)
- [UID:0001JP][0x00591d60-0x00593a10.TextEditPaneFormattingRuns](by-memory/0x00591d60-0x00593a10.TextEditPaneFormattingRuns.md)
- [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md)
- [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md)
- [UID:0001JS][0x00594040-0x00594e11.TextEditPaneInputNavigationAndWrap](by-memory/0x00594040-0x00594e11.TextEditPaneInputNavigationAndWrap.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)
- [UID:0001GJ][0x0055d960-0x00565488.TextEditPaneScrollbarVariants](by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md)
- [UID:0000UK][DrawTextRunCallback_00593DB0](by-item/DrawTextRunCallback_00593DB0.md)
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md)
- [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)

## Changes

- 2026-06-07 A004 Batch 046 range sync:
  - Updated [UID:0001JM][0x0058dce0-0x005917c9.TextEditPaneCore](by-memory/0x0058dce0-0x005917c9.TextEditPaneCore.md) to the corrected half-open endpoint `0x0058dce0-0x005917c9` after IDA MCP confirmed the final `sub_591740` body spans through byte `0x005917c8` and the next function starts at `0x005917d0`.
  - Score unchanged at `88/85`; this edit only syncs a child memory-range filename and endpoint.

- 2026-06-07 A005 Batch 047 parent-gate refresh:
  - Before: `88/80`, with confidence capped by the unresolved `TextFilter` adjacency question.
  - After: `88/85`; the file now treats `TextFilter` as a separate neighboring source and owns the exact [UID:0002XX][0x00594e60-0x00595760.TextEditSupportObjects](by-memory/0x00594e60-0x00595760.TextEditSupportObjects.md) child split.
  - Evidence: live IDA confirms the support-object destructor ends at `0x00595759`, `TextFilter` starts at `0x00595760`, and the support-object cluster remains tied to the editor's inline-object and scrap behavior.
  - Assignment effect: enables [UID:0002XX][0x00594e60-0x00595760.TextEditSupportObjects](by-memory/0x00594e60-0x00595760.TextEditSupportObjects.md) assignment under the corrected child-and-parent `85/85` gate.

- 2026-06-01: Set projected reconstruction path to `NexusTK/ui/controls/` and updated the scrollbar aggregate endpoint.
  - Evidence: this page already proposes `ui/controls/TextEditPane.cpp`; IDA MCP recheck of [UID:0001GJ][0x0055d960-0x00565488.TextEditPaneScrollbarVariants](by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md) shows the enclosing scrollbar corridor ends at `0x00565488`.
  - Scope: path assignment only; reconstructed C++ remains gated by exact child-page confidence and final source-quality names.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document captures rich editor role, support classes/callbacks, ownership decisions, global active-editor pointer, IDA/Wave3 evidence, serialization and scrollbar relationships, caveats, and cross-references; confidence is capped by exact original split among `TextEditPane`, support objects, and `TextFilter`.
