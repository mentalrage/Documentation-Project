** TARGET-REPORT-UID:00016R **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00016R HelpPaneCore Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](../../../../../by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) into exact method/helper child pages, add explicit internal padding rows, then reclassify `00016R` as a reviewed non-emitting HelpPanes migration index.
- Do not put aggregate C++ on `00016R`. The current active code gate is not the blocker: `84/90` averages `87` and the emitter route reaches [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md). The blocker is source shape. The target spans two classes, seven method/helper bodies, raw no-entry helper code, and multiple alignment gaps; exact children should carry final source ownership.
- Do not reclassify the parent alone unless exact child pages are created in the same implementation callback. Until children exist, the parent is the only documentation row covering these source bodies. After children exist, the parent should become `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
- No IDA database edits are recommended.

Recommended parent metadata after split:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

`CANONICAL_OWNER:0000JU` remains correct for the parent because the aggregate mixes [UID:000063] `HelpPane` and [UID:000064] `HelpPane__SimpleHelpTextPartPane` bodies. Exact children should use the direct class owners.

## Target And Current State

- Target UID: `00016R`
- Target path: `source-3/project-documentation/by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00016R-HelpPaneCore-source-quality.md`
- Current target state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU`, blank formal C++.
- Current generated route: `auto-generated/-ag-memory-coverage.md` lists [UID:00016R] as `emits` through `0000JU` to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`.
- Current generated output state: `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` contains only an empty emitter marker for [UID:00016R], so no C++ would be removed by making the parent non-emitting after child pages exist.

B001 did not edit target by-* docs, support by-* docs, generated reports/source, IDA DB, or `by-memory/-coverage-report.md`.

## Current-Session Evidence Status

- Live IDA MCP was attempted on 2026-06-19 at the project-guidance endpoint `http://127.0.0.1:13337/mcp`; the endpoint was unavailable: `Unable to connect to the remote server`.
- This report relies on current by-* documentation with prior live IDA evidence, cached/exported prewave function facts, generated coverage/output state, local read-only PE byte checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, and source-layout docs.
- A mistaken older-port MCP probe was not used as evidence.

## Recommended Exact Child Pages

Create exact child pages in address order:

| Range | Recommended page name | Direct owner/emitter | Recommended disposition |
| --- | --- | --- | --- |
| `0x004c65a0-0x004c6622` | `HelpPaneSimpleHelpTextPartPaneConstructor` | [UID:000064] `HelpPane__SimpleHelpTextPartPane` | `RECONSTRUCTABLE:TRUE`, blank C++ pending final class layout. |
| `0x004c6630-0x004c6817` | `HelpPaneSimpleHelpTextPartPaneDrawText` | [UID:000064] `HelpPane__SimpleHelpTextPartPane` | `RECONSTRUCTABLE:TRUE`, blank C++ pending final draw/virtual name and field names. |
| `0x004c6820-0x004c687e` | `HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw` | [UID:000064] `HelpPane__SimpleHelpTextPartPane` | `RECONSTRUCTABLE:TRUE`, blank C++; raw no-IDA-function/no-external-xref helper. |
| `0x004c6880-0x004c6953` | `HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment` | [UID:000064] `HelpPane__SimpleHelpTextPartPane` | `RECONSTRUCTABLE:TRUE`, blank C++ pending final `TextStyleInfo`/GrafPort field names. |
| `0x004c6960-0x004c6dac` | `HelpPaneConstructor` | [UID:000063] `HelpPane` | `RECONSTRUCTABLE:TRUE`, blank C++ pending final `HelpStyle`/field names. |
| `0x004c6db0-0x004c6e49` | `HelpPaneDestructor` | [UID:000063] `HelpPane` | `RECONSTRUCTABLE:TRUE`, blank C++ pending ordinary destructor/class-layout pass. |
| `0x004c6e50-0x004c6ea9` | `HelpPaneOnPaintFrame` | [UID:000063] `HelpPane` | `RECONSTRUCTABLE:TRUE`, blank C++ pending final paint color/global helper names. |

The class page [UID:000064] is currently `84/88`, while [UID:000063] is `85/89`. Exact child creation should also raise [UID:000064] at least to `85/88` by recording the exact child pages, the raw helper child, and the padding split. Existing child [UID:0003Z0] already routes through [UID:000064], so this route is consistent with current generated state, but the support score should be cleaned up during implementation.

## Required Padding / Ignored Rows

Local PE byte checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirm these internal gaps are all `0xcc` alignment:

| Range | Bytes |
| --- | --- |
| `0x004c6622-0x004c6630` | 14 bytes `cc` |
| `0x004c6817-0x004c6820` | 9 bytes `cc` |
| `0x004c687e-0x004c6880` | 2 bytes `cc` |
| `0x004c6953-0x004c6960` | 13 bytes `cc` |
| `0x004c6dac-0x004c6db0` | 4 bytes `cc` |
| `0x004c6e49-0x004c6e50` | 7 bytes `cc` |

The already-recorded successor gap `0x004c6ea9-0x004c6eb0` is also seven bytes of `cc`, but it is outside the target's half-open range and is already represented around [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](../../../../../by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md).

## Heuristic / Inference Reanalysis And Validation

### 1. Source-Facing Method Inventory

Best current source-facing names and signatures:

| Range | Reject raw/generated name | Best current source direction | Evidence |
| --- | --- | --- | --- |
| `0x004c65a0-0x004c6622` | `sub_4C65A0`, `ctor_0x4c65a0` | `HelpPane::SimpleHelpTextPartPane::SimpleHelpTextPartPane()` | Constructor function size `0x82`; vtable triplet for `SimpleHelpTextPartPane<HelpPane>`; constructs pane base, `SimpleUString` text member, style pointer, and opacity default. |
| `0x004c6630-0x004c6817` | `virt_meth_0x4c6630` | `void HelpPane::SimpleHelpTextPartPane::DrawText()`; possible virtual paint override name should be rechecked, but do not retain `virt_meth`. | Existing class/target docs name it `DrawText`; simroot lead names it `DrawText`; behavior walks CR/LF/tab-delimited text and calls the styled segment helper. |
| `0x004c6820-0x004c687e` | `FUN_004c6820` | `void HelpPane::SimpleHelpTextPartPane::UpdateStyleState()` / `ApplyStyleOpacityState()`; final name unresolved. | Ghidra/prewave cache models a 94-byte helper with no callers; IDA-backed docs record no IDA function object and no external xrefs. Behavior checks style pointer and opacity, then calls `Pane::SetMode`. |
| `0x004c6880-0x004c6953` | `sub_4C6880`, `meth_0x4c6880` | `void HelpPane::SimpleHelpTextPartPane::DrawStyledTextSegment(const HelpTextStyleRun *style, int xMargin, int yPos, const wchar_t *text, short length)` | Cached signature has five explicit args after `this`; target and simroot agree it draws normal/outlined/shadowed styled text. |
| `0x004c6960-0x004c6dac` | `sub_4C6960`, `ctor_0x4c6960` | `HelpPane::HelpPane(const wchar_t *text, Pane *parentPane, int x, int y, int hAlign, int vAlign, const HelpStyle *styleConfig)` | Cached/prewave signature has text, parent/owner pane, two coordinates, two alignment args, and style pointer; simroot lead matches this shape. |
| `0x004c6db0-0x004c6e49` | `sub_4C6DB0`, `dtor_0x4c6db0` | `HelpPane::~HelpPane()` | Ghidra cache names `~HelpPane`; destructor resets vtables and frees string/style/vector state. |
| `0x004c6e50-0x004c6ea9` | `virt_meth_0x4c6e50` | `void HelpPane::OnPaintFrame()` | Class/target docs name it `OnPaintFrame`; vtable slots at `0x0061aba0` and `0x0061acb0` reach it; body fills frame then draws border/frame color. |

The raw helper at `0x004c6820` should not be folded into `DrawText` or `DrawStyledTextSegment`. It has its own prologue/body shape in cached Ghidra output, separate `0xcc` boundaries in prior IDA evidence and local PE bytes, and a distinct style/mode update role.

### 2. HelpPane Owner / Emitter Routing

Validated current route:

- [UID:0000JU] `HelpPanes` is `90/86`, projected to `NexusTK/ui/controls/`, and generated as `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`.
- [UID:000063] `HelpPane` is `85/89`, reconstructable, and routes through [UID:0000JU].
- [UID:000064] `HelpPane__SimpleHelpTextPartPane` is `84/88`, reconstructable, and routes through [UID:0000JU].
- `auto-generated/-ag-class-coverage.md` lists both classes as emitting through [UID:0000JU].
- `auto-generated/-ag-memory-coverage.md` currently lists `00016R` as emitting through [UID:0000JU] to `HelpPanes.cpp`, but the generated file contains only an empty marker for `00016R`.
- [UID:00025G] `HelpItemHelpReadOnlyData` ties the `SimpleHelpTextPartPane<HelpPane>` and `HelpPane` vtable triplets to this executable cluster and the broader HelpPanes source family.

Rejected routes:

- A standalone `class_HelpPane.cpp` / `class_HelpPane__SimpleHelpTextPartPane.cpp` original source split is only Wave3/simroot output. The by-file and proposed-source-tree docs place the real source family under `ui/controls/HelpPanes.cpp`.
- A StaticTextControlPane route is wrong. [UID:000064] is explicitly distinct from [UID:0000E5] `StaticTextControlPane2__SimpleHelpTextPartPane`, even though both consume shared GrafPort text-effect helpers.
- A GrafPort route is wrong for this target. GrafPort owns shared text helpers [UID:00016D] and [UID:00016E]; this target is the HelpPane consumer and class method cluster.

### 3. Text / Style / Control Fields

Best field/type directions for implementation:

| Offset / state | Source-facing direction | Evidence and caveat |
| --- | --- | --- |
| `HelpPane +0xfc` | `m_styleData`, `m_styleConfig`, or embedded `HelpStyle` / `FontStyle`-compatible block | Constructor copies enabled byte, opacity/floats, colors, and vector triplet; [UID:00005C] `FontStyle` compatibility is documented. Final type name remains open. |
| `HelpPane +0x100` | base opacity/fade float | [UID:00022N] and constructor/fade logic compare it against `0.0f` and `1.0f`. |
| `HelpPane +0x108/+0x10c` | source color fields copied into paint colors | [UID:00022N] copies these into `+0x11c/+0x120`. |
| `HelpPane +0x11c/+0x120` | frame/fill or foreground/background paint color fields | `OnPaintFrame` consumes both; current docs disagree on exact order, so avoid final `m_foreColor`/`m_backColor` claims until paint helper semantics are locked. |
| `HelpPane +0x124` | `m_textPart` / `m_simpleTextPart` | Constructor builds embedded `HelpPane::SimpleHelpTextPartPane`; [UID:00016W]/[UID:0003Z0] validate the related destructor/vtable model. |
| `HelpPane +0x220` | child style pointer / style-run pointer for embedded text part | Constructor stores pointer used by child opacity logic. |
| text part `+0xf8` | `m_text` of type `SimpleUString` | Constructor constructs it, draw path reads it, [UID:0003Z0] destroys it. |
| text part `+0xfc` | `m_styleRuns` / `m_styleArray` | `DrawText` and raw helper test style data and style enabled byte. |
| text part `+0x90` | opacity / line-spacing/fade value | Constructor initializes it, raw helper writes accepted opacity. The simroot `m_lineSpacing` name is not strong enough for final source because fade helper writes opacity here. |
| `Pane +0xb5` | pane mode byte | [UID:0002V7] resolves `Pane::SetMode(unsigned char)` and invalidation side effect. |
| modes `1` and `3` | pane draw/blend/fade states | Current evidence supports state values, not enum names. Do not use feature-local names yet. |

Avoid generated receiver pollution such as `FittingRoomDownloadControlPane`, `FittingRoomListPane`, `RankingEventListPane`, `TextButtonExControlPane::~Pane`, or `DAT_0067a7cc` in final names. They are decompiler/type-owner artifacts for shared pane/GrafPort helpers.

### 4. Shared Helper Names

Use already-resolved shared helper names where available:

- [UID:0002V7] `Pane::SetMode(unsigned char mode)` for `0x005446b0`.
- [UID:00016D] `GrafPort::DrawTextInRect(const wchar_t *text, int length, const RectBounds *rect)` for `0x004bad70-0x004baf92`.
- [UID:00016E] `GrafPort::DrawOutlinedText` and `GrafPort::DrawShadowedText` for `0x004bafa0` and `0x004bb080`.
- [UID:00016C] `GrafPortTextRunHelpers` for width/draw helpers around `0x004ba9a0`, `0x004baaa0`, and `0x004bab70`.
- Rectangle helpers around `0x004b7c30`, `0x004b7c70`, `0x004b7e10`, and `0x004b8e00` should be described by operation until final source names are proven.
- `dword_69B3FC` should be described as the render/fill callback from the surface/render callback table, not left as a raw dword in source-facing text.

### 5. Caller / Reachability Evidence

Current evidence checked:

- `0x004c6880` is called twice from `0x004c6630` at `0x004c6743` and `0x004c67d1`.
- `0x004c6820` has no IDA-modeled function object and no external xrefs in the prior all-byte IDA scan; cached Ghidra/prewave has it as `FUN_004c6820` with no callers. Keep it as raw source-relevant helper evidence, not final C++.
- `0x004c6960` has two documented callers: SimpleHelpPane2 construction/factory paths at `0x004c74ff` and `0x004c7715`.
- `0x004c6db0` is reached from cleanup/destructor paths at `0x004c7604`, `0x004ce3f6`, `0x004ce52a`, and EH cleanup records in the two factories; cached prewave lists 4-5 caller refs depending on tool.
- `0x004c6e50` is vtable/data-reached through HelpPane vtable slots at `0x0061aba0` and `0x0061acb0`.
- [UID:00025G] vtable evidence confirms `SimpleHelpTextPartPane<HelpPane>` vtables at `0x0061aad4`, `0x0061ab20`, `0x0061ab50` and HelpPane vtables at `0x0061ab5c`, `0x0061aba8`, `0x0061abd8`.

### 6. Compiler-Generated / Raw Name Policy

Source-quality replacements:

- `sub_4C65A0` -> constructor.
- `virt_meth_0x4c6630` -> `DrawText` or possible paint/draw override; final virtual slot name still open.
- `FUN_004c6820` -> raw style-state/update helper; no final name yet.
- `meth_0x4c6880` / `sub_4C6880` -> `DrawStyledTextSegment`.
- `sub_4C6960` -> `HelpPane::HelpPane`.
- `sub_4C6DB0` -> `HelpPane::~HelpPane`.
- `virt_meth_0x4c6e50` -> `HelpPane::OnPaintFrame`.
- `TextButtonExControlPane::~Pane`, `FittingRoom*`, `RankingEventListPane`, and similar labels in generated output are type-pollution artifacts and should not survive final source.
- Scalar deleting destructor wrappers and `this -= 0xa0/0xa4` adjustor thunks are handled by [UID:00016W] / exact children and should not be hand-authored here.

## Exact Aggregate No-Code Proof

`00016R` should keep formal C++ blank after reclassification because:

1. It is not one source-level function or class. It spans `HelpPane::SimpleHelpTextPartPane` constructor/draw/helper bodies and `HelpPane` constructor/destructor/paint bodies.
2. It contains confirmed internal `0xcc` alignment gaps that should not be represented as source code.
3. It contains raw no-IDA-function/no-external-xref helper body `0x004c6820-0x004c687e`, whose source name and liveness are unresolved.
4. The current generated output already contains only an empty marker for `00016R`; there is no useful aggregate source to preserve.
5. Under `by-structure.md`, a mixed owner/method-cluster index should be `RECONSTRUCTABLE:FALSE` once exact source-bearing children carry the real method ownership.

This is not a stale `95/95` gate issue. The numeric route currently passes the active combined-score gate, but final C++ on the aggregate would violate the by-memory rule limiting code to the page's own source object and would create a non-original source blob.

## Recommended Exact Target Doc Changes

After exact children and padding rows exist, update the target:

- Change status/disposition from `reconstructable NexusTK project code` / `class method cluster` to `reviewed non-emitting HelpPanes split index`.
- Replace the covered-ranges table with a split map that includes every method/helper child and every padding gap:
  - `0x004c65a0-0x004c6622` child method.
  - `0x004c6622-0x004c6630` padding.
  - `0x004c6630-0x004c6817` child method.
  - `0x004c6817-0x004c6820` padding.
  - `0x004c6820-0x004c687e` raw helper child.
  - `0x004c687e-0x004c6880` padding.
  - `0x004c6880-0x004c6953` child method.
  - `0x004c6953-0x004c6960` padding.
  - `0x004c6960-0x004c6dac` child method.
  - `0x004c6dac-0x004c6db0` padding.
  - `0x004c6db0-0x004c6e49` child method.
  - `0x004c6e49-0x004c6e50` padding.
  - `0x004c6e50-0x004c6ea9` child method.
- Keep the source-family owner [UID:0000JU].
- Blank `EMITTER_UIDS`.
- Keep formal C++ blank.
- Add an evidence note that local PE bytes independently confirm the internal `0xcc` gaps listed above.
- Replace reconstruction notes that imply only raw-helper naming blocks C++ with the stronger aggregate no-code proof above.

Recommended support-doc sync:

- [UID:0000JU] `HelpPanes`: replace the single `HelpPaneCore` proposed-content row with exact children under `HelpPane__SimpleHelpTextPartPane` and `HelpPane`, mirroring the accepted [UID:00016V] / [UID:00016W] split style.
- [UID:000063] `HelpPane`: add exact child references for constructor/destructor/paint and note that `HelpPaneCore` is now a non-emitting index.
- [UID:000064] `HelpPane__SimpleHelpTextPartPane`: add exact child references for constructor, draw text, raw update helper, styled segment helper, and raise support completion to at least `85` after the split/padding evidence is incorporated.
- [UID:00022N] `HelpPaneFadeStateUpdate`: keep as adjacent raw helper; cross-link the exact `0x004c6820` child as the embedded text-part counterpart.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` in this B-agent pass. After child pages exist and their UIDs are assigned, replace the current parent row with:

```text
    - [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) 0x004c65a0-0x004c6ea9 | split index | HelpPaneCore : not_reconstructable : 88% : strong : B001 2026-06-19 source-quality split review reclassifies this mixed HelpPane and embedded SimpleHelpTextPartPane method/helper island as a non-emitting HelpPanes migration index; exact child pages should carry the text-part constructor, draw text, raw style-state helper, styled segment draw helper, HelpPane constructor, destructor, and OnPaintFrame source ownership, while internal 0xcc padding rows cover the alignment gaps, so no aggregate final C++ should emit from this range.
```

Recommended ignored coverage rows for the internal padding, after the split:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004c6622-0x004c6630 | padding | HelpPane text-part constructor to DrawText alignment : ignored : 100% : strong : Local PE byte check and function-boundary evidence confirm fourteen `0xcc` alignment bytes between `0x004c65a0-0x004c6622` and `0x004c6630-0x004c6817`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004c6817-0x004c6820 | padding | HelpPane text-part DrawText to raw style-state helper alignment : ignored : 100% : strong : Prior IDA evidence and local PE byte check confirm nine `0xcc` alignment bytes before the raw `0x004c6820-0x004c687e` helper.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004c687e-0x004c6880 | padding | HelpPane text-part raw style-state helper to DrawStyledTextSegment alignment : ignored : 100% : strong : Prior IDA evidence and local PE byte check confirm two `0xcc` alignment bytes before `0x004c6880-0x004c6953`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004c6953-0x004c6960 | padding | HelpPane text-part DrawStyledTextSegment to HelpPane constructor alignment : ignored : 100% : strong : Local PE byte check and function-boundary evidence confirm thirteen `0xcc` alignment bytes between `0x004c6880-0x004c6953` and `0x004c6960-0x004c6dac`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004c6dac-0x004c6db0 | padding | HelpPane constructor to destructor alignment : ignored : 100% : strong : Local PE byte check and function-boundary evidence confirm four `0xcc` alignment bytes between `0x004c6960-0x004c6dac` and `0x004c6db0-0x004c6e49`.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004c6e49-0x004c6e50 | padding | HelpPane destructor to OnPaintFrame alignment : ignored : 100% : strong : Local PE byte check and function-boundary evidence confirm seven `0xcc` alignment bytes between `0x004c6db0-0x004c6e49` and `0x004c6e50-0x004c6ea9`.
```

Child coverage rows cannot be exact until validator assigns UIDs. Suggested row subjects, in address order:

```text
    - [UID:TBD][0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor](by-memory/0x004c65a0-0x004c6622.HelpPaneSimpleHelpTextPartPaneConstructor.md) 0x004c65a0-0x004c6622 | method | HelpPaneSimpleHelpTextPartPaneConstructor : reconstructable : 86% : strong : ...
    - [UID:TBD][0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneDrawText](by-memory/0x004c6630-0x004c6817.HelpPaneSimpleHelpTextPartPaneDrawText.md) 0x004c6630-0x004c6817 | method | HelpPaneSimpleHelpTextPartPaneDrawText : reconstructable : 86% : strong : ...
    - [UID:TBD][0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw](by-memory/0x004c6820-0x004c687e.HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw.md) 0x004c6820-0x004c687e | raw helper | HelpPaneSimpleHelpTextPartPaneUpdateStyleStateRaw : reconstructable : 85% : strong : ...
    - [UID:TBD][0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment](by-memory/0x004c6880-0x004c6953.HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment.md) 0x004c6880-0x004c6953 | method | HelpPaneSimpleHelpTextPartPaneDrawStyledTextSegment : reconstructable : 86% : strong : ...
    - [UID:TBD][0x004c6960-0x004c6dac.HelpPaneConstructor](by-memory/0x004c6960-0x004c6dac.HelpPaneConstructor.md) 0x004c6960-0x004c6dac | method | HelpPaneConstructor : reconstructable : 86% : strong : ...
    - [UID:TBD][0x004c6db0-0x004c6e49.HelpPaneDestructor](by-memory/0x004c6db0-0x004c6e49.HelpPaneDestructor.md) 0x004c6db0-0x004c6e49 | method | HelpPaneDestructor : reconstructable : 86% : strong : ...
    - [UID:TBD][0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame](by-memory/0x004c6e50-0x004c6ea9.HelpPaneOnPaintFrame.md) 0x004c6e50-0x004c6ea9 | method | HelpPaneOnPaintFrame : reconstructable : 86% : strong : ...
```

## Validator Needs For Implementation Callback

No validator was run in this B-agent report-only pass.

Implementation callback should use this order:

1. Create exact child pages and padding/ignored rows.
2. Validate each new child page so real UIDs are assigned.
3. Update [UID:00016R], [UID:000063], [UID:000064], [UID:0000JU], [UID:00022N], `by-memory/-ignored.md`, and supervisor-owned `by-memory/-coverage-report.md`.
4. Run scoped file validation on every touched doc.
5. Run autogen/rescore and `memory_ranges.py report` after the coverage/ignored split is complete.

## Open Questions

- Whether `0x004c6630` was originally named `DrawText`, `OnPaint`, or another class-local paint/draw override. Current docs and simroot lead favor `DrawText`, but vtable-slot source naming is not final.
- Final source name and liveness story for raw `0x004c6820-0x004c687e`. Best descriptive direction is `UpdateStyleState` / `ApplyStyleOpacityState`, but no external entry is proven.
- Final `HelpStyle` / `FontStyle` type name and exact field names for style records, colors, opacity, and style-run vector.
- Exact paint color order at `HelpPane +0x11c/+0x120`.
- Whether a future source-layout pass should split `HelpPanes.cpp` further. Current evidence supports keeping the generic HelpPane/text-part cluster in [UID:0000JU] `HelpPanes`.

## Changed Files

- Created this report only: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/00016R-HelpPaneCore-source-quality.md`.

Preserved existing B001 reports `0002NQ-ClanStringListPaneDrawItem-source-quality.md` and `00013I-EncoderWriteBytes-source-quality.md`; neither was overwritten or moved.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00016R-HelpPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"00016R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
