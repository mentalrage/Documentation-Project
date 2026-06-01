*** UID:0000JI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# FontStyle

## Status

- Confidence: strong for the recovered class behavior and layout; medium for exact original file placement.
- Proposed module: `ui/controls/FontStyle.cpp`, or a private support type folded into `ui/controls/StaticTextControlPane.cpp`.
- Proposed header: `ui/controls/FontStyle.h`, or declarations in the static/help text control header.
- Current recovered source: `source-3/simroot_v2/class_FontStyle.cpp`
- Exact code ranges: `0x004536e0-0x00453732`, `0x00499f10-0x00499fda`; compiler/vector support at `0x0049ac60-0x0049ad74`

## File Role

`FontStyle` is a small reusable text-style descriptor used by the static text and help-pane controls. The object is 0x20 bytes in the currently recovered layout: a short scalar style header followed by a `std::vector`-like triplet for 16-byte rule records.

The current best source-layout placement is a small UI control support file near [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md) and [UID:0000JU][HelpPanes](by-file/HelpPanes.md). It is consumed by minimap labels, the mail compose dialog's "Keep a copy" label, and `HelpPane` style-copy setup, but those caller features should not own the type.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| [UID:00005C][FontStyle](by-class/FontStyle.md) | `0x00499f10-0x00499fda`, cleanup at `0x004536e0-0x00453732` | Text-style descriptor with enabled/opacity/color-mode fields and rule-vector storage. |
| [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md) | data layout | 0x20-byte object layout plus 16-byte rule record layout. |
| `FontStyle::ClearRules` | [UID:0000XM][0x004536e0-0x00453732.FontStyleClearRules](by-memory/0x004536e0-0x00453732.FontStyleClearRules.md) | Releases rule-vector backing storage and zeros the begin/end/capacity triplet. |
| `FontStyle::FontStyle` | `0x00499f10-0x00499f51` | Initializes default enabled state, 0.2f opacity fields, scalar defaults, and empty vector pointers. |
| `FontStyle::Configure` | `0x00499f90-0x00499fda` | Appends one 16-byte rule record, using `0x0049ac60` as the vector growth slow path. |
| [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) | `0x0049ac60-0x0049ad74` | Compiler/template-style vector insert/growth helper; do not treat as a separate handwritten project method. |

## Evidence Notes

- IDA MCP confirms `0x004536e0`, `0x00499f10`, and `0x00499f90` as real functions with the same compact sizes reported by generated metadata.
- 2026-05-26 IDA MCP recheck confirms `0x0049ac60` has one direct caller, `0x00499fcf` inside `FontStyle::Configure`, and decompiles as allocator/memmove-backed growth for 16-byte vector entries.
- Constructor callers include [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md), [UID:000096][NewMailDialog](by-class/NewMailDialog.md), and [UID:000063][HelpPane](by-class/HelpPane.md).
- Configure callers include `MiniMapDialog` and `NewMailDialog` constructor paths and additional minimap-local style setup paths.
- `HelpPane::HelpPane` constructs an embedded style record at object offset `+0xfc`, then copies a caller-provided `FontStyle`-compatible record into it.
- `MiniMapDialog::MiniMapDialog` builds one local style object, configures it as `Configure(0x80, 6, 1, 0)`, and passes it to several `StaticTextControlPane2` labels.
- `NewMailDialog::NewMailDialog` uses a similar local style object for the "Keep a copy" static label in the EPF mail-skin path. The active generated source currently hides this behind `TextStyle labelStyle = BuildDialogTextStyle(...)`, but IDA shows raw calls to `0x00499f10` and `0x00499f90`.

## Ownership Decision

Keep this as reusable UI text-style support. It should not be owned by `MiniMapDialog`, `NewMailDialog`, or `HelpPane` even though those are the strongest current callers.

Final migration has two plausible shapes:

- `ui/controls/FontStyle.cpp` if the original project kept style descriptors as standalone support files.
- Static/private declarations in `ui/controls/StaticTextControlPane.cpp` or `ui/controls/HelpPanes.cpp` if later source-order/header evidence shows the type was local to text controls.

The separate file is safer for documentation because it has its own constructor, rule appender, cleanup helper, and cross-feature fanout.

## Current Caveats

- `class_FontStyle.cpp` repeats `FontStyleRule`, `FontStyleLayout`, and `GetFontStyleLayout` inside every emitted method body. Treat that as generated normalization noise, not original source style.
- IDA decompilation of `Configure` only proves the low byte at rule offset `+0x08` carries the selector argument. The generated source widens it to a full `uint32_t`, but the safer layout records the high three bytes as padding/unknown until rendering consumers are typed.
- The helper at `0x0049ac60` is a vector growth routine called only by `FontStyle::Configure` in current IDA caller output. Treat it as compiler/template support and keep it in the ignored memory ledger rather than as a hand-written `FontStyle` member.

## Cross-References

- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md)
- [UID:0000XM][0x004536e0-0x00453732.FontStyleClearRules](by-memory/0x004536e0-0x00453732.FontStyleClearRules.md)
- [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md)
- [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)

## Changes

- 2026-05-30: Scored the file page from 0/0 to 76/84 and linked the `FontStyle::ClearRules` row to its detailed by-memory page. Evidence: current IDA MCP recheck confirms `ClearRules` bounds/callers/callees, while existing docs already cover the constructor/configure functions, 0x20-byte layout, rule-vector growth helper, and cross-feature consumers.
