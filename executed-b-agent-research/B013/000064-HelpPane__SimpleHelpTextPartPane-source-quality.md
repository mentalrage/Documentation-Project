** TARGET-REPORT-UID:000064 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000064 HelpPane__SimpleHelpTextPartPane Source-Quality Report

Status: FINISHED

## Target

- UID: `000064`
- Class doc: `source-3/project-documentation/by-class/HelpPane__SimpleHelpTextPartPane.md`
- Primary aggregate: `source-3/project-documentation/by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md`
- Existing destructor child: `source-3/project-documentation/by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/000064-HelpPane__SimpleHelpTextPartPane-source-quality.md`

## Evidence Checked

- Assignment rules: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, and `Agent-B013/goal.md`.
- Target/support docs: `HelpPane__SimpleHelpTextPartPane`, `HelpPaneCore`, `HelpPane`, `HelpPanes`, `StaticTextControlPane2__SimpleHelpTextPartPane`, `SimpleHelpTextPartPaneCore`, `FontStyle`, `FontStyleLayout`, `FontStyleCore`, `Pane`, `PaneSetMode`, `GrafPort`, `GrafPortDrawStateAccessors`, `GrafPortTextRunHelpers`, `DrawTextInRect`, `SimpleHelpTextPartPaneTextEffects`, `SurfaceRenderCallbackTable`, `HelpTooltipDestructorThunks`, and the scalar deleting destructor child.
- Exported function facts for `0x004c65a0`, `0x004c6630`, `0x004c6880`, `0x004ce620`, `0x004c6960`, `0x004c6e50`, `0x00499f60`, and the StaticText opacity helper at `0x0049a2d0`.
- Local validator dry run: `python source-3/project-documentation/tools/validator.py --mode file --file source-3/project-documentation/by-class/HelpPane__SimpleHelpTextPartPane.md --uid-only`; result was ok for UID `000064`.
- IDA MCP endpoint probe at `http://127.0.0.1:13337/mcp`; not reachable, so current live IDA was unavailable.
- Local read-only PE route scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`.
- `tools/int_convert.py` conversions for sizes/offsets: constructor `0x82` = 130, `DrawText` `0x1e7` = 487, raw helper `0x5e` = 94, `DrawStyledTextSegment` `0xd3` = 211, scalar destructor wrapper `0x48` = 72, `+0xf8` = 248, `+0xfc` = 252, `+0x90` = 144, `+0x124` = 292, `+0x44` = 68, `+0x8c` = 140, colors `0x8f` = 143 and `0x80` = 128.

No by-* docs, coverage reports, or target/support pages were edited.

## Findings

### Method Boundaries And Child Coverage

The currently documented boundaries are still correct:

| Range | Best source-facing role | Child coverage decision |
| --- | --- | --- |
| `0x004c65a0-0x004c6622` | `HelpPane::SimpleHelpTextPartPane::SimpleHelpTextPartPane()` | Should become a method-level child if C++ is emitted. No direct caller was found in exported facts, but this is normal object-file retention and the body is a source constructor. |
| `0x004c6630-0x004c6817` | `HelpPane::SimpleHelpTextPartPane::DrawText()` | Should become a method-level child before emitting the body. It has vtable/data reachability and calls `DrawStyledTextSegment` twice. |
| `0x004c6817-0x004c6820` | padding | Keep as padding in the aggregate. |
| `0x004c6820-0x004c687e` | raw `ApplyStyleOpacityState` / `ApplyStyleStateFromFontStyle` candidate | Keep documented as a raw no-entry body, not a normal source-emitted method, unless a later live route is found. |
| `0x004c687e-0x004c6880` | padding | Keep as padding in the aggregate. |
| `0x004c6880-0x004c6953` | `HelpPane::SimpleHelpTextPartPane::DrawStyledTextSegment(...)` | Should become a method-level child with first-draft C++ after split. |
| `0x004ce620-0x004ce668` | scalar deleting destructor wrapper | Existing child [UID:0003Z0] is correct; do not emit wrapper C++. Source-facing method is the ordinary virtual destructor. |
| adjustor thunks near `0x004ce3a3/0x004ce3ae` | destructor thunks for secondary views | Compiler ABI thunks only; keep in the thunk aggregate, no source C++. |

The class doc currently has only the scalar destructor wrapper as a separate child. Constructor, `DrawText`, raw style-state helper, and `DrawStyledTextSegment` remain embedded in `HelpPaneCore`. That is the main C++ readiness blocker: method bodies should be emitted by method-level children, not by the class page.

### Raw Style-State Helper Route

The raw helper at `0x004c6820-0x004c687e` is exactly 94 bytes. Existing docs already record that IDA has no function object and that byte-by-byte xrefs are internal only. I rechecked the route in the read-only PE:

- Direct/conditional/short branch refs into `0x004c6820-0x004c687e`: `5` total, all internal, `0` external.
- Absolute VA dword refs to any address in the helper range: `0`.
- One unaligned full-image RVA-like byte pattern lands at `0x004c687a`, but it is inside `.text` and not an absolute data pointer; it does not provide a source route.
- Positive controls worked: absolute refs exist for `0x004c6630` and `0x004ce620`, matching vtable/destructor refs, while none exist for `0x004c6820`.

Conclusion: best descriptive name is `ApplyStyleOpacityState` or `ApplyStyleStateFromFontStyle`, but current evidence supports raw-retained/no formal C++ rather than a normal emitted private method. This is the exact no-code proof for that body: no modeled function object, no external branch/call entry, no absolute data pointer/table entry, and behavior duplicated inline in `HelpPane::HelpPane`.

### Field And Type Resolution

Best supported class shape:

```cpp
class HelpPane::SimpleHelpTextPartPane : public Pane {
public:
    SimpleHelpTextPartPane();
    virtual ~SimpleHelpTextPartPane();
    virtual void DrawText();

private:
    void DrawStyledTextSegment(const FontStyleRule& style,
                               int x,
                               int y,
                               const wchar_t *text,
                               int charCount);

    SimpleUString m_text;        // +0xf8
    FontStyle *m_fontStyle;      // +0xfc, nullable, points at the parent FontStyle block
};
```

Important offset decisions:

- Embedded text part `+0xf8`: owned `SimpleUString m_text`. Constructor calls `sub_582B20`; destructor calls `sub_582B70`; parent constructor assigns text through `sub_582D20`.
- Embedded text part `+0xfc`: best name `m_fontStyle` or `m_style`, not `m_styleRuns` / `m_styleArray`. `DrawText` calls `FontStyle::GetRule(index, &rule)` on this pointer, and the raw helper reads the `FontStyle` header byte and opacity float. It is a pointer to the full `FontStyle` object, not directly to the rule vector.
- Embedded text part `+0x90`: inherited `GrafPort::m_alpha` / opacity scalar. Constructor seeds `0.2f`; style-state code copies bounded text opacity from `FontStyle +0x08`.
- Embedded text part `+0x8c`: inherited `GrafPort::m_textAlign`. `DrawStyledTextSegment` copies per-rule `+0x0c` here before calling `GrafPort::DrawTextInRect`.
- Pane `+0x44`: inherited `RectBounds m_bounds`.
- Parent `HelpPane +0x124`: embedded `SimpleHelpTextPartPane` subobject.
- Parent `HelpPane +0x220`: same physical slot as embedded child `+0xfc`; set to `this +0xfc` in `HelpPane::HelpPane`, proving the child style pointer routes to the parent's `FontStyle` block.
- Parent `HelpPane +0xfc`: embedded `FontStyle` object copied from the optional caller style record.
- Parent `HelpPane +0x11c/+0x120`: fill/frame colors copied from `FontStyle +0x0c/+0x10` and used by `HelpPane::OnPaintFrame`.

Best supported `FontStyleRule` shape for this target:

```cpp
struct FontStyleRule {
    int textColor;          // +0x00, passed to GrafPort::SetTextColor / +0x7c
    int textBackColor;      // +0x04, passed to GrafPort::SetTextBackColor / +0x80
    unsigned char effect;   // +0x08 low byte: 0 normal, 1 outlined, 3 shadowed
    int textAlign;          // +0x0c, copied to GrafPort::m_textAlign / +0x8c
};
```

The root `FontStyle` scalar fields should remain conservative in shared layout docs, but this target strongly uses `+0x04` as parent/base opacity and `+0x08` as child/text opacity.

### Helper Names And Signatures

Recommended source-facing names/signatures:

- `sub_4C65A0`: `HelpPane::SimpleHelpTextPartPane::SimpleHelpTextPartPane()`.
- `sub_4C6630`: `void HelpPane::SimpleHelpTextPartPane::DrawText()`. `OnPaint` is a plausible virtual-family alternate, but the target and current docs consistently use `DrawText`, and the method is specifically the text-part draw routine.
- Raw `0x004c6820-0x004c687e`: descriptive `HelpPane::SimpleHelpTextPartPane::ApplyStyleOpacityState()` or `ApplyStyleStateFromFontStyle()`, but no emitted source until route proof exists.
- `sub_4C6880`: `void HelpPane::SimpleHelpTextPartPane::DrawStyledTextSegment(const FontStyleRule& style, int x, int y, const wchar_t *text, int charCount)`.
- `sub_4CE620`: scalar deleting destructor wrapper for `virtual HelpPane::SimpleHelpTextPartPane::~SimpleHelpTextPartPane()`. Keep wrapper C++ blank.
- `sub_584540`: `SimpleUString::c_str()` / text pointer accessor.
- `sub_582B20`: `SimpleUString::SimpleUString()`.
- `sub_582B70`: `SimpleUString::~SimpleUString()`.
- `sub_544460`: `Pane::Pane(unsigned char type)`.
- `sub_544580`: `Pane::~Pane()` / base teardown.
- `sub_5446B0`: `Pane::SetMode(unsigned char mode)`.
- `sub_499F60`: `FontStyle::GetRule(unsigned int index, FontStyleRule *outRule)` or `GetRuleAt`.
- `sub_4B9660`: `GrafPort::SetDrawColor(int color)`.
- `sub_4B9680`: `GrafPort::SetTextColor(int color)`.
- `sub_4B9690`: `GrafPort::SetTextBackColor(int color)`.
- `sub_4B9600`: `GrafPort::MoveTo(int x, int y)`.
- `sub_4BAAA0`: `GrafPort::GetLineHeight()`.
- `sub_4BAB70`: `GrafPort::DrawWideText(const wchar_t *text, int charCount)`.
- `sub_4BAD70`: `GrafPort::DrawTextInRect(const wchar_t *text, int length, const RectBounds *rect)`.
- `sub_4BAFA0`: `GrafPort::DrawOutlinedText(...)`.
- `sub_4BB080`: `GrafPort::DrawShadowedText(...)`.
- `dword_69B3FC`: render callback slot 7, descriptive `g_pfnFillOrInvalidateRect`; do not name it HelpPane-specific.

### Behavior To Carry Forward

- Constructor initializes the pane base with type `3`, installs three vtable views at `+0`, `+0xa0`, and `+0xa4`, constructs `m_text`, clears `m_fontStyle`, and seeds inherited `m_alpha` to `0.2f`.
- `HelpPane::HelpPane` constructs the embedded child at `this+0x124`, assigns the text into child `+0xf8`, sets child `+0xfc` to the parent `FontStyle` at `this+0xfc`, inserts the child with the Pane child-add virtual, and mirrors style/fade state into both parent and child.
- `DrawText` copies local bounds from `+0x44`, clears/fills through `SetDrawColor(0)` and `g_pfnFillOrInvalidateRect`, uses a default `FontStyleRule` equivalent to text color `0x8f`, back color `0x80`, effect `0`, align `0`, then scans `m_text.c_str()` by UTF-16 characters.
- `DrawText` treats CR, LF, and tab as segment/line separators. For each segment, if `m_fontStyle && m_fontStyle->enabled`, it asks `FontStyle::GetRule(lineIndex, &rule)` and calls `DrawStyledTextSegment`; otherwise it uses `MoveTo` plus `DrawWideText`.
- The raw style-state helper checks `m_fontStyle`, `m_fontStyle->enabled`, and `m_fontStyle +0x08`. Opacity `<= 0.0f` sets pane mode `1`; `0.0f < opacity <= 1.0f` sets pane mode `3` and copies the opacity into inherited `m_alpha`; opacity `> 1.0f`, null style, or disabled style falls through.
- `DrawStyledTextSegment` copies `rule.textAlign` into inherited `m_textAlign`, applies `rule.textColor` and `rule.textBackColor`, creates a 12-pixel-high rect from the provided x/y and available width, then dispatches effect `0` to `DrawTextInRect`, effect `1` to outlined text, and effect `3` to shadowed text.
- StaticText2 comparison: `StaticTextControlPane2__SimpleHelpTextPartPane` has similar style-state logic but different fields. Its opacity helper reads style at `+0x108` and layout fields at `+0xfc/+0x100/+0x104`; HelpPane's text part uses `+0xf8` for text and `+0xfc` for the `FontStyle *`. Do not merge the owners or layouts.
- Text effects comparison: outlined/shadowed helpers are GrafPort-owned shared render helpers, not HelpPane or StaticText private methods.

## C++ Recommendation

Do not populate class-level `RECONSTRUCTION_CPP` with method bodies. The class page can carry declaration/source-shape notes, but constructor/draw/helper bodies should be emitted through method-level by-memory children after a split. This preserves the supervisor class-vs-method emission policy and avoids placing several disjoint functions into one class doc snippet.

Recommended child/source policy:

- Create or split method children for constructor, `DrawText`, and `DrawStyledTextSegment` if implementation scope permits. These are source-authored methods and are C++ ready enough for first drafts.
- Keep the raw `0x004c6820-0x004c687e` body documented but blank/no-emission until a live call route is found. If a child is created for coverage, mark it as raw no-entry and include the no-code proof.
- Keep the scalar deleting destructor wrapper child blank; source C++ belongs to the ordinary destructor, not the wrapper.

First-draft method-level source shape:

```cpp
HelpPane::SimpleHelpTextPartPane::SimpleHelpTextPartPane()
    : Pane(3),
      m_text(),
      m_fontStyle(NULL)
{
    m_alpha = 0.2f;
}
```

```cpp
void HelpPane::SimpleHelpTextPartPane::ApplyStyleOpacityState()
{
    if (m_fontStyle == NULL || !m_fontStyle->enabled) {
        return;
    }

    const float opacity = m_fontStyle->textOpacity;
    if (opacity <= 0.0f) {
        SetMode(1);
        return;
    }

    if (opacity <= 1.0f) {
        SetMode(3);
        if (m_fontStyle->textOpacity <= 1.0f) {
            m_alpha = m_fontStyle->textOpacity;
        }
    }
}
```

The above helper is source-style accurate, but should not be emitted yet because there is no external entry/caller route.

```cpp
void HelpPane::SimpleHelpTextPartPane::DrawStyledTextSegment(
    const FontStyleRule& style,
    int x,
    int y,
    const wchar_t *text,
    int charCount)
{
    m_textAlign = style.textAlign;
    SetTextColor(style.textColor);
    SetTextBackColor(style.textBackColor);

    RectBounds rect;
    InitRectFromSize(&rect, x, y - 12, m_bounds.right - (2 * x) - m_bounds.left, 12);

    switch (style.effect) {
    case 0:
        DrawTextInRect(text, charCount, &rect);
        break;
    case 1:
        DrawOutlinedText(text, charCount, &rect);
        break;
    case 3:
        DrawShadowedText(text, charCount, &rect);
        break;
    default:
        break;
    }
}
```

```cpp
void HelpPane::SimpleHelpTextPartPane::DrawText()
{
    RectBounds bounds = m_bounds;
    SetDrawColor(0);
    g_pfnFillOrInvalidateRect(this, &bounds);

    FontStyleRule style = { 0x8f, 0x80, 0, 0 };
    const wchar_t *text = m_text.c_str();
    SetTextColor(0x8f);

    const int lineHeight = GetLineHeight();
    int y = lineHeight + 5;
    int segmentStart = 0;
    int lineIndex = 0;
    const int length = static_cast<int>(wcslen(text));

    for (int i = 0; i <= length; ++i) {
        const wchar_t ch = text[i];
        if (ch != L'\0' && ch != L'\r' && ch != L'\n' && ch != L'\t') {
            continue;
        }

        const int count = i - segmentStart;
        if (count > 0) {
            if (m_fontStyle != NULL && m_fontStyle->enabled) {
                m_fontStyle->GetRule(lineIndex, &style);
                DrawStyledTextSegment(style, 5, y, text + segmentStart, count);
            } else {
                MoveTo(5, y);
                DrawWideText(text + segmentStart, count);
            }
        }

        segmentStart = i + 1;
        y += GetLineHeight() + 1;
        ++lineIndex;
    }
}
```

This `DrawText` draft is intentionally source-style and may need small rect-origin tuning after a method-child decompile pass; it is ready as a first draft, not final audited source.

## Recommended Target Doc Changes

For `by-class/HelpPane__SimpleHelpTextPartPane.md`:

- Update metadata to `COMPLETION:87`, `CONFIDENCE:89`; keep `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU`, and blank class-level C++.
- Replace the status caveat with: final class/source shape is resolved enough for method-child C++ drafts; only exact historical spellings and the raw helper's no-entry status remain open.
- Rename the style pointer note from `m_styleRuns` / `m_styleArray` to `FontStyle *m_fontStyle` / `m_style`.
- Add that `+0x90` is inherited `GrafPort::m_alpha`, not a class-local field.
- Add that `+0x8c` is inherited `GrafPort::m_textAlign`, populated from per-rule `+0x0c`.
- Add the raw PE no-route evidence for `0x004c6820-0x004c687e`.
- Add the child-emission policy: constructor, `DrawText`, and `DrawStyledTextSegment` should emit through method-level children; raw style-state helper and scalar deleting destructor remain blank/no-emission.
- Add the rejected alternatives:
  - StaticText2 text part is not the owner and has different field offsets.
  - GrafPort text effects are dependencies, not HelpPane-owned methods.
  - `m_styleRuns` is too narrow because `+0xfc` points to a full `FontStyle`.
  - `OnPaint` remains a plausible virtual-family spelling, but current source-quality name should stay `DrawText` unless the Pane virtual naming pass standardizes otherwise.

## Recommended Support Updates

For `by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md`:

- Raise to `86/90` after incorporating this report.
- Add the PE route check: no external branch/call into `0x004c6820-0x004c687e` and no absolute data pointer to the helper range in read-only `NexusTK.exe`.
- Replace `style pointer/state` wording with `FontStyle *m_fontStyle` for the embedded child pointer at `+0xfc`.
- Document parent/child aliasing: `HelpPane +0x220` is embedded child `+0xfc`, set to `HelpPane +0xfc`.
- Document per-rule field consumption: rule `+0/+4/+8/+0xc` are text color, text back color, effect selector, and text alignment.
- Keep aggregate C++ blank and recommend child pages for method bodies.

For `by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md`:

- Keep score and blank C++.
- Replace `m_styleRuns` / `m_styleArray` direction with `m_fontStyle` or `m_style` for `+0xfc`.
- Make explicit that only `m_text` is destroyed by the wrapper; `m_fontStyle` is borrowed from the parent `HelpPane` and is not owned by the text part.

For `by-class/HelpPane.md`:

- Add that the embedded text part at `+0x124` has `m_text` at child `+0xf8` and borrowed `FontStyle *m_fontStyle` at child `+0xfc` / parent `+0x220`.
- Add that parent `FontStyle +0x04` controls parent opacity and `+0x08` controls child text opacity.

For `by-file/HelpPanes.md`:

- Add a source-shape note that `HelpPane::SimpleHelpTextPartPane` belongs in `NexusTK/ui/controls/HelpPanes.cpp`, with method bodies split to children rather than class-level snippets.

For `FontStyleLayout.md` / `FontStyleCore.md`:

- Optional support note only: this target strengthens the consumer-specific interpretation that per-rule `+0x0c` is copied into GrafPort text alignment, while root `+0x0c/+0x10` continue to feed HelpPane fill/frame colors.

## Score And Metadata Recommendation

Target class:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000JU
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JU
RECONSTRUCTION_CPP: keep blank
```

Rationale: source placement, class layout, method boundaries, field names, dependency names, and no-code proof for the raw helper are now strong. Completion remains below 90 because method children are not split/emitted and exact historical spellings for the private helper and virtual name are still inferred.

Support aggregate:

```text
HelpPaneCore: 86/90, owner/emitter unchanged at 0000JU, C++ blank.
```

Potential method-child scores if implementation creates them:

- Constructor child: `86/90`, owner/emitter `000064`, C++ ready.
- `DrawText` child: `86/89`, owner/emitter `000064`, first-draft C++ ready with minor rect-origin validation.
- Raw style-state helper child: `85/88`, owner `000064` as raw class-family code, but formal C++ blank/no-entry unless route proof appears.
- `DrawStyledTextSegment` child: `87/90`, owner/emitter `000064`, C++ ready.
- Existing scalar deleting destructor child: keep `86/91`, C++ blank.

## Coverage Text

Do not edit coverage reports in this B-agent report-only pass.

Exact replacement row for `by-class/-coverage-report.md` if the target score is accepted:

```text
- [UID:000064][HelpPane__SimpleHelpTextPartPane](by-class/HelpPane__SimpleHelpTextPartPane.md) : reconstructable : 87% : strong : B013 source-quality pass resolves HelpPanes ownership, embedded `HelpPane +0x124` child routing, constructor/DrawText/DrawStyledTextSegment boundaries, `SimpleUString m_text` at embedded `+0xf8`, borrowed `FontStyle *m_fontStyle` at embedded `+0xfc`, inherited GrafPort alpha/text-align fields at `+0x90/+0x8c`, FontStyleRule per-line rendering, raw no-external-route `ApplyStyleOpacityState` body at `0x004c6820-0x004c687e`, and scalar deleting destructor/no-C++ policy; method-level children are recommended before formal C++ emission.
```

Exact replacement row for `by-memory/-coverage-report.md` if `HelpPaneCore` support score is accepted:

```text
    - [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md) 0x004c65a0-0x004c6ea9 | method-cluster | HelpPaneCore : reconstructable : 86% : strong : B013 source-quality reanalysis preserves exact HelpPane/SimpleHelpTextPartPane method starts and raw-helper split, resolves `SimpleUString` text at embedded `+0xf8`, borrowed `FontStyle *m_fontStyle` at embedded `+0xfc`, inherited GrafPort alpha/text-align fields at `+0x90/+0x8c`, FontStyleRule text color/back color/effect/alignment consumption, constructor-side parent/child propagation from `HelpPane +0xfc/+0x220`, external-branch/data-pointer negative PE evidence for `0x004c6820-0x004c687e`, and method-child C++ routing; raw helper remains blank/no-entry pending a live call route.
```

No additional `by-memory/-coverage-report.md` rows should be inserted for proposed method children until actual child UIDs are assigned.

Project stats rows that will need regeneration after accepted score edits:

```text
| `000064` | 87 | 89 | 88.0 | `by-class/HelpPane__SimpleHelpTextPartPane.md` |
| `00016R` | 86 | 90 | 88.0 | `by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md` |
```

## Validation Commands After Implementation

From `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [000064-HelpPane__SimpleHelpTextPartPane-source-quality-removed.md](000064-HelpPane__SimpleHelpTextPartPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If method children are created, validate each new by-memory child file individually before running autogen.

## IDA Rename, Type, And Comment Recommendations

High confidence:

- Rename `sub_4C65A0` to `HelpPane::SimpleHelpTextPartPane::SimpleHelpTextPartPane`.
- Rename `sub_4C6630` to `HelpPane::SimpleHelpTextPartPane::DrawText`.
- Rename `sub_4C6880` to `HelpPane::SimpleHelpTextPartPane::DrawStyledTextSegment`.
- Rename `sub_4CE620` as scalar deleting destructor wrapper for `HelpPane::SimpleHelpTextPartPane::~SimpleHelpTextPartPane`.
- Type embedded child `+0xf8` as `SimpleUString m_text`.
- Type embedded child `+0xfc` as borrowed `FontStyle *m_fontStyle`.
- Type inherited `+0x90` as `m_alpha` / opacity and `+0x8c` as `m_textAlign`.
- Type `0x00499f60` as `FontStyle::GetRule(unsigned int index, FontStyleRule *outRule)`.

Medium-high confidence:

- Label raw `0x004c6820-0x004c687e` as `HelpPane::SimpleHelpTextPartPane::ApplyStyleOpacityState_raw_no_entry` or add a repeatable comment: "raw no external route; checks borrowed FontStyle, calls Pane::SetMode(1/3), copies text opacity to GrafPort alpha; do not emit until live route is found."
- Define `FontStyleRule` with `textColor`, `textBackColor`, `effect`, and `textAlign` fields for this consumer. Keep shared `FontStyleLayout` scalar names conservative until all consumers are audited.

Rejected rename/ownership alternatives:

- Do not name `+0xfc` as `m_styleRuns` or `m_styleArray`; it points to the full `FontStyle`.
- Do not move text effects to HelpPane; they are GrafPort-owned dependencies.
- Do not merge this class with StaticText2's similarly named text part; the offset layouts diverge.
- Do not emit scalar deleting destructor or adjustor thunk C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/000064-HelpPane__SimpleHelpTextPartPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"000064"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000064-HelpPane__SimpleHelpTextPartPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/000064-HelpPane__SimpleHelpTextPartPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000064"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
