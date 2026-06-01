*** UID:0000EO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextEditPane

## Status

- Confidence: strong.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: `0x0058dce0-0x005917c8`, `0x00591d60-0x00594e11`, plus mixed scrollbar variants at `0x0055d960-0x00565488`
- Current recovered file: `source-3/simroot_v2/class_TextEditPane.cpp`

## Class Purpose

`TextEditPane` is the core styled text editor pane. It owns UTF-16 text storage, line and format tables, caret/selection state, IME focus, clipboard operations, scrollable viewport behavior, rich text drawing, and keyboard/mouse editing.

It inherits or embeds [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) behavior rather than being a simple `ControlPane`. The dialog-facing `ControlPane` wrapper is [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md).

## Observed State

Important recovered state:

```text
+0x000  primary vtable
+0x0a0  secondary vtable A
+0x0a4  secondary vtable B
+0x134  text/list storage pointer
+0x138  line-break or format/color table pointer
+0x13c  style/run table pointer
+0x140  format/style record table pointer
+0x144  selection/caret start word
+0x146  selection/caret end word
+0x15c  flags bitfield: active, read-only, selection visibility, blur-hide behavior
+0x167  mouse/drag mode
+0x16c  delete-forward line/index field
+0x16e  delete-backward format/index field
```

The generated source uses several alternate local struct names for the same backing storage. Treat the offsets above as stable, but the field names remain provisional.

The process-wide active editor pointer is [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md) at `0x0069be00`; generated `CopyWindow` output calls the same address `g_pCopyWindowTextEditPane`.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/destruction | `0x0058dce0-0x0058e227`, `0x0048c4d0-0x0048c50a` | Construct `ScrollablePane`, install vtables, create text/style lists, seed empty text, register active editor/IME focus, and release owned lists. |
| Text copy/access | [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md) | Copy a bounded UTF-16 prefix from editor text storage into a caller buffer and null-terminate it. |
| Serialization | `0x0058e490-0x0058e690` | Encode text/list/style table state through [UID:00004F][Encoder](by-class/Encoder.md) for a caller-owned save/export path. |
| Viewport and scroll queries | `0x0058e890-0x0058edc4` | Scroll to caret/line, report scroll range/position/page/content size, convert scroll units/deltas. |
| Layout and selection | `0x0058edd0-0x0058fb8a` | Resize, measure lines, locate cursor/format/word/line ranges, set selection, compute caret pixels, and recalc line breaks. |
| Text mutation and clipboard | `0x0058fc30-0x0059079b` | Insert/set text, copy to `TextEditScrap`, paste, select all, read text, and find next format handler. |
| Drawing and events | `0x00590810-0x0059116b` | Draw background/text/selection/caret, handle key events, idle, and mouse selection/drag/double-click behavior. |
| Invalidations and limits | `0x00591180-0x005917c8` | Enforce max length/lines, cleanup format records, update caret, and invalidate lines/selection/caret/text region. |
| Format runs/range editing | `0x00591d60-0x00593a10` | Build format arrays, apply/get range attributes, replace/delete ranges, manage style runs, and iterate text runs. |
| Input navigation and wrapping | `0x00594040-0x00594e11` | Character input, delete, cursor movement, wrapping, wrap position recalculation, and autoscroll during selection. |
| Scrollbar handler variants | `0x0055d960-0x00565488` excluding the corrected `0x00561420-0x00561d4d` group-scrollbar helper family | Hit-test, draw, track, and drag repeated scrollbar variants used by the editor and neighboring scrollbar classes. |

## Evidence Notes

- Wave3 class summary describes a rich text edit control with copy, paste, cut, multiline selection, caret cursor, scrollbar variants, double/triple-click selection, and text formatting.
- IDA MCP reports 26 direct references to the constructor and six references to `CopySelectionToScrap`.
- `TextEditPane::OnDraw` calls `IterateTextRuns` with [UID:0000UK][DrawTextRunCallback_00593DB0](by-item/DrawTextRunCallback_00593DB0.md).
- [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md) confirms text storage at `+0x134` can be copied out through a bounded UTF-16 accessor used by [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadTextForwarder.md).
- IDA data xrefs pass [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) into the same text-run/layout family; the current generated `0x00593b20` fitting-room owner marker is not an IDA function.
- `TextEditPane::OnDraw` and `InvalidateTextRegion` call [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md), currently emitted by `simroot_v2` as a BowGauge helper but proven shared by IDA callers.
- `TextEditPane::OnKeyEvent` handles clipboard hotkeys and constructs local `TextEditScrap` objects on copy/cut paths.
- `TextEditPane::OnMouseEvent` uses `g_selectionAnchor` and `AutoScrollSelectionToPoint` for drag selection.
- [UID:000039][CopyWindow](by-class/CopyWindow.md) consumes the active-editor global and calls `TextEditPane::SelectAll`, but it should stay as a neighboring dialog class rather than being absorbed into the editor implementation by default.

## Current Caveats

- Several generated helper names are polluted by unrelated feature owners. Verify helper addresses before using names such as `RankingEventListPane` or fitting-room helper labels as ownership evidence.
- Current generated output also owns `0x00561420`, `0x00561a40`, `0x00561b00`, and `0x00561bc0` under `TextEditPane`; IDA xrefs now tie those to [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md), so keep them out of TextEditPane source migrations.
- The destructor marker at `0x0058e140` is split across two generated source lines; this is tracked as a Wave3 codegen issue.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md)
- [UID:000039][CopyWindow](by-class/CopyWindow.md)
- [UID:0000EP][TextEditScrap](by-class/TextEditScrap.md)
- [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md)
- [UID:0001JM][0x0058dce0-0x005917c8.TextEditPaneCore](by-memory/0x0058dce0-0x005917c8.TextEditPaneCore.md)
- [UID:0001JP][0x00591d60-0x00593a10.TextEditPaneFormattingRuns](by-memory/0x00591d60-0x00593a10.TextEditPaneFormattingRuns.md)
- [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md)
- [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md)
- [UID:0001JS][0x00594040-0x00594e11.TextEditPaneInputNavigationAndWrap](by-memory/0x00594040-0x00594e11.TextEditPaneInputNavigationAndWrap.md)
- [UID:0001GJ][0x0055d960-0x00565488.TextEditPaneScrollbarVariants](by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md)
- [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `88`, confidence `82`.
- Evidence: the page documents core editor responsibility, stable offsets, active editor global, major method families, callbacks, rendering/helper links, clipboard/scrap behavior, source-owner caveats, and excluded `ScrollNewGroupPane` helper family; confidence remains capped by generated helper-name pollution and unresolved final field names.
