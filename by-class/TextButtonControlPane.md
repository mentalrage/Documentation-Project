*** UID:0000EJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "TextButtonControlPane.h"
#include <wchar.h>
#include "../../util/MemoryMan.h"

TextButtonControlPane::TextButtonControlPane(const wchar_t *text,
                                             const RectBounds *bounds)
    : ButtonControlPane(*bounds)
{
    MemoryMan *memoryMan = GetMemoryMan();
    const size_t byteCount = (wcslen(text) + 1) * sizeof(wchar_t);

    m_text = static_cast<wchar_t *>(
        GetMemoryMan()->AllocateBufferMemory(byteCount));
    memoryMan->MemmoveWrapper(m_text, text, byteCount);
}

TextButtonControlPane::~TextButtonControlPane()
{
    if (m_text != 0) {
        m_text = static_cast<wchar_t *>(
            GetMemoryMan()->FreeBufferMemory(m_text));
    }
}

short TextButtonControlPane::GetText(wchar_t *destination,
                                     short maxCharacters)
{
    short copied = maxCharacters;
    const short textLength = static_cast<short>(wcslen(m_text));
    if (copied > textLength) {
        copied = textLength;
    }

    GetMemoryMan()->MemmoveWrapper(destination, m_text, copied);
    destination[copied] = L'\0';
    return copied;
}

void TextButtonControlPane::OnPaint()
{
    const unsigned int kNormalTopLeftColor = 192;
    const unsigned int kNormalBottomRightColor = 200;
    const unsigned int kPressedTopLeftColor = 200;
    const unsigned int kPressedBottomRightColor = 192;
    const unsigned int kButtonFillColor = 196;
    const unsigned int kEnabledTextColor = 128;
    const unsigned int kDisabledTextColor = 134;
    const unsigned char kPressedVisualState = 11;
    const int kLabelHalfHeight = 6;

    const bool pressed = (m_visualState == kPressedVisualState);
    const unsigned int topLeftColor =
        pressed ? kPressedTopLeftColor : kNormalTopLeftColor;
    const unsigned int bottomRightColor =
        pressed ? kPressedBottomRightColor : kNormalBottomRightColor;
    const unsigned int textColor =
        m_enabled ? kEnabledTextColor : kDisabledTextColor;

    RectBounds frame = m_visibleBounds;

    SetDrawColor(kButtonFillColor);
    FillRect(&frame);

    MoveTo(frame.left, frame.bottom - 1);
    SetDrawColor(topLeftColor);
    LineTo(frame.left, frame.top);
    LineTo(frame.right - 1, frame.top);
    SetDrawColor(bottomRightColor);
    LineTo(frame.right - 1, frame.bottom - 1);
    LineTo(frame.left, frame.bottom - 1);

    InsetRect(&frame, 1, 1);

    MoveTo(frame.left, frame.bottom - 1);
    SetDrawColor(topLeftColor);
    LineTo(frame.left, frame.top);
    LineTo(frame.right - 1, frame.top);
    SetDrawColor(bottomRightColor);
    LineTo(frame.right - 1, frame.bottom - 1);
    LineTo(frame.left, frame.bottom - 1);

    RectBounds textRect = m_visibleBounds;
    const int textCenterY = (textRect.top + textRect.bottom) / 2;
    textRect.top = textCenterY - kLabelHalfHeight;
    textRect.bottom = textCenterY + kLabelHalfHeight;

    if (pressed) {
        OffsetRect(&textRect, 1, 1);
    }

    SetTextColor(textColor);
    m_textDrawMode = 1;
    m_textAlign = 1;
    DrawTextInRect(m_text, static_cast<int>(wcslen(m_text)), &textRect);

    if (m_enabled && m_controlSelected) {
        SetDrawColor(1);
        m_drawMode = 0;
        DrawRectFrame(&m_visibleBounds);
    }

    if (m_enabled && m_controlActive) {
        SetDrawColor(128);
        m_drawMode = 0;
        DrawRectFrame(&m_visibleBounds);
    }
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CONTROLS_TEXTBUTTONCONTROLPANE_H
#define NEXUSTK_UI_CONTROLS_TEXTBUTTONCONTROLPANE_H

#include "ButtonControlPane.h"

class TextButtonControlPane : public ButtonControlPane
{
public:
    TextButtonControlPane(const wchar_t *text, const RectBounds *bounds);
    virtual ~TextButtonControlPane();

    virtual short GetText(wchar_t *destination, short maxCharacters);

protected:
    virtual void OnPaint();

    wchar_t *m_text;
};

typedef char TextButtonControlPaneSizeMustBe272[
    sizeof(TextButtonControlPane) == 0x110 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextButtonControlPane

## Status

- Confidence: very strong for class role, exact layout and virtual contract, active constructor use, destructor/vtable ownership, source/compiler split, and exclusion of stale generated helper rows.
- Likely source file: [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- Core memory: [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Historical recovered-file lead: `source-3/simroot_v2/class_TextButtonControlPane.cpp` is absent and superseded by the validator-routed formal CPP/H above.

## Class Purpose

`TextButtonControlPane` is a text-labeled button control. It owns a dynamically allocated wide-string text buffer, paints a beveled button, draws the centered label, and exposes faithful text retrieval. No source-supported text-resource setter belongs to this class.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TextButtonControlPane::TextButtonControlPane` | `[0x00495040,0x0049512f)` | Constructs `ButtonControlPane`, installs derived views, allocates `(wcslen+1)*2`, and copies the owned label. |
| `~TextButtonControlPane` | `[0x00495130,0x004951a3)` | Frees and clears the owned `+0x10c` text pointer; vptr restoration and base teardown are compiler lowering. |
| `GetText` | `[0x004951b0,0x00495218)` | Clamps a character count, passes it unchanged to byte-count Memmove, terminates at `destination[copied]`, and returns the count. |
| `OnPaint` | `[0x00495220,0x00495450)` | Draws fill, two bevel passes, centered label, pressed offset, then independent selected and active frames. |
| rejected `SetTextResource` candidate | `0x004964e0` | Not a modeled function, zero direct xrefs, and physically inside [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md). |
| `DrawTextInRect` dependency | `[0x004bad70,0x004baf92)` | Established GrafPort/shared-text source with broad fanout; called by `OnPaint`, not class-owned. |
| destructor adjustor thunks | [UID:0002YD][0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks](by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md) | Compiler-generated secondary/tertiary adjustor thunks into the scalar deleting destructor. |
| scalar deleting destructor | [UID:0002YE][0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md) | Compiler-generated scalar deleting wrapper now source-covered by this class emitter through a formal covered-by marker; do not hand-author the raw wrapper body. |

## Historical simroot_v2 Caveat

Historical 2026-05-25 recheck without running `wave3.py`: the then-present `simroot_v2/class_TextButtonControlPane.cpp` emitted `SetTextResource` at `0x004964e0`, while IDA reported that address as not a function and the RadioGroup source carried the neighboring paint loop. The current simroot path is absent. The old row is preserved only to explain its rejection; it is not current authority or an open class method.

## Assignment Gate

`CANONICAL_OWNER` and `EMITTER_UIDS` are set to [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md). The child and direct source-file parent both clear the `85/85` gate, and by-structure ownership is direct because this class is the principal class implemented by the narrower `TextButtonControlPane.cpp` file. The broader [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) remains a related button/choice-control family parent, not the direct parent for this class page.

## 2026-06-16 Evidence Refresh

Live IDA MCP was used to recheck the active-use, stale-helper, destructor-wrapper, and shared text-render blockers:

- `lookup_funcs` confirms the class method anchors: constructor `0x00495040` size `0xef`, destructor `0x00495130` size `0x73`, `GetText` `0x004951b0` size `0x68`, `OnPaint` `0x00495220` size `0x230`, adjustor thunks `0x0049b05b`/`0x0049b066` size `0x0b`, and scalar deleting destructor `0x0049b7a0` size `0xb4`.
- The stale generated `SetTextResource` row at `0x004964e0` remains `Not a function`, and `xrefs_to 0x004964e0` returns zero refs. This supports keeping that island under the radio-group option-helper documentation rather than promoting it here.
- `xrefs_to 0x00495040` returns ten constructor/setup callsites; `0x00495130` has two code refs; `GetText` and `OnPaint` are vtable/data referenced at `0x0060e038`, `0x00617ce0`, and `0x00617cc0`.
- Destructor support is exact: adjustor thunks are referenced from `0x00617ce8` and `0x00617d18`, scalar deleting destructor refs come from the two thunks and primary vtable cell `0x00617c7c`, and vtable writes to `0x00617c7c` occur in the constructor/destructor/deleting-destructor family at `0x004950bc`, `0x0049515b`, and `0x0049b7d2`.
- A paged `xrefs_to 0x004bad70` query returned the first 100 refs with `more:true`, including the `TextButtonControlPane::OnPaint` call at `0x004953e7`. That confirms `DrawTextInRect` is a dependency/shared text helper, not a direct class-owned method.
- `callees` confirms constructor/destructor/get-text use shared control/text-buffer helpers, while `OnPaint` calls GrafPort draw-state helpers and [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md).

These checks resolve the low-confidence class-routing questions for the direct text-button class. Remaining blockers are final field names, exact base/interface declaration shape, and the shared text-render source split, not ownership of the constructor/destructor/get-text/paint methods.

## 2026-07-03 B006 Scalar Wrapper Source-Coverage Sync

The [UID:0002YE][0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md) child is no longer an unresolved blank emitter. B006 MCP session `3a33af0b` reconfirmed `sub_49B7A0` as a `0xb4` byte modeled scalar deleting destructor wrapper with clean `0x0049b854-0x0049b860` `0xcc` padding, direct refs only from adjustor thunks `0x0049b061`/`0x0049b06c` and primary vtable cell `0x00617c7c`, and TextButton vtable stores at `0x0049b7d2`, `0x0049b7d8`, and `0x0049b7e2`.

The wrapper shares the ordinary destructor cleanup shape around `this+0x10c`, `sub_516030`, `sub_516170`, and base cleanup `sub_544580`, then adds compiler-only scalar-delete flag handling through `sub_4F4AC0` and the `0x110` guard/object-size path. UID0002YE is therefore represented as source-declared/generated-binary glue covered by this class page, not as a standalone source method or raw decompiler-shaped body. Remaining uncertainty is limited to final member/helper spelling and exact original declaration exposure; those cap confidence but do not change the class owner or marker-covered disposition.

## 2026-08-13 B006 Complete Layout And Source Contract

The accepted report artifact is SHA256 `252A1CEB3A98F1ED96A6A65DF6B76D74330C4A085840A5CB388804D6F16B93BD`. Its dated saved-IDB evidence snapshot is SHA256 `5CCAF2321601201E12AFE937EEC6511B9E92B7B54CEAD23F5464E1D3D2440C43`; that snapshot supports this documentation and does not assert current Gate 2B authority.

Layout is exact for source reconstruction: `ButtonControlPane` occupies `[+0x000,+0x10c)`, protected owned wide-text pointer `m_text` is at `+0x10c`, and complete size is `0x110`. Constructor allocation sizes, constructor/destructor/GetText/OnPaint field use, three-view vptr stores, and current FittingRoom-derived formal source independently converge on the same contract. Protected access is required because the derived paint implementation reads `m_text`.

| Method | Exact size/hash | Direct reachability | Faithful source behavior |
| --- | --- | --- | --- |
| constructor | `0xef`; `B77069621D6F69D5189CC6B3066A7CEFE4EEF7160CE82247097A2954394D1DFC` | Ten calls at `0x00424030`, `0x004a02de`, `0x004a034d`, `0x004b06f0`, `0x004b075f`, `0x00500afb`, `0x00500b6b`, `0x00545336`, `0x0054733b`, `0x0054890e` | Constructs the base from pointed-to bounds, obtains MemoryMan before sizing, obtains it again for allocation, allocates `(wcslen(text)+1)*sizeof(wchar_t)`, and uses the first manager for the copy. |
| ordinary destructor | `0x73`; `E00E4974D52F7C71BDF339BC3D182644DD50CA5B9B05ABE936132589326D8ED8` | Code refs `0x0042407a`, `0x004242b0` | Frees the non-null owned text and stores the null return. Explicit vptr/base teardown is omitted from human source. |
| `GetText` | `0x68`; `085A029DBA6AB39CD94F026D15CA1FA34AA2D2221C3D7D15A3C4FBF7AB874C72` | Vtable/data refs `0x0060e038`, `0x00617ce0` | Clamps to text length but deliberately forwards the character count unchanged to a byte-count copy, writes the wide terminator at the returned count, and returns that count. The mismatch is preserved. |
| `OnPaint` | `0x230`; `F0A470DA1DAC209B84349BBF4E9DE6E27BFE4B2C163F4D15EAA83F3424AB9DF4` | Generic primary cell `0x00617cc0` | Preserves fill, outer bevel, inset, inner bevel, centered 12-pixel label rect, pressed `(1,1)` offset, text state, selected frame, and active frame order. Selected and active tests remain independent. |

Exact authored boundaries are separated by all-CC fences `[0x0049503d,0x00495040)`, `[0x0049512f,0x00495130)`, `[0x004951a3,0x004951b0)`, and `[0x00495218,0x00495220)`. `OnPaint` ends exactly at the TextButtonEx constructor `0x00495450`.

Compiler/data split is complete. UID0002YD owns only the two 11-byte `this-0xa0`/`this-0xa4` deleting adjustors. UID0002YE owns only the exact `0xb4` complete-object scalar wrapper and its existing covered-by marker. The three-view vtable island `[0x00617c78,0x00617d20)`, 26/11/2 slots, COLs, BCD/CHD/BCA, type descriptor, hidden deletion flags, vptr writes, and CC alignment are compiler/linker output. No vtable array, RTTI object, adjusted entry, scalar wrapper, or alignment byte is handwritten.

The formal CPP block above contains all four authored definitions in address order and exactly one `[[CHILDREN]]` route so UID0002YE's marker remains attached without a raw wrapper body. The formal H block is the complete `ButtonControlPane`-derived declaration and compile-time `0x110` size invariant. No draft/example body is maintained in prose or any non-owning page.

At the Gate 1 snapshot the generated CPP was marker-only, 672 bytes, ten lines, SHA256 `E57CC0C12A2E04B6C873AE5731420E82326879AD736CEEB6D3F0082E019BC431`, and the required H was absent. The first ordinary-document callback populated only the owning formal channels and intentionally did not refresh generated output. Scoped validator command `000000023376` later completed generated closure at `2026-08-14T04:07:10-04:00` with exit `0`, `ok:1`: physical reread found the four authored definitions and expanded UID0002YE covered-by child marker in the 3,997-byte, 117-line CPP (SHA256 `783FD57EE868E147C20AC54097B696E4A989B52039A7CBE2198F99AC628A4827`), and the complete declaration plus `0x110` size invariant in the 964-byte, 30-line H (SHA256 `9ADD6C98CD6597E2B0144A2B9B5EB25C1119E9799D084FFD465D6B3FEDC7CDD4`). The H body exactly matches this formal channel; the CPP body matches the formal CPP after replacing `[[CHILDREN]]` with the expected two-line UID0002YE marker. Generated files remain validator-owned and were not edited directly.

Resolved blockers are historicalized rather than removed: the absent simroot and Wave3 labels are old leads; the rejected `SetTextResource` candidate is RadioGroup code; `DrawTextInRect` is a GrafPort dependency; the base, member, complete size, constructor pointer form, and protected access are now evidence-backed; and inclusive endpoint prose is superseded by exact half-open ranges. Remaining uncertainty is limited to unavailable original private spelling/header grouping and caps the score rather than source completeness.

## Cross-References

- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:000118][0x00494eb0-0x0049803a.ButtonChoiceControlCore](by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:00011E][0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers](by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md)
- [UID:0000UJ][DrawTextInRect_004BAD70](by-item/DrawTextInRect_004BAD70.md)
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)
- [UID:0002YD][0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks](by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md)
- [UID:0002YE][0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b7a0-0x0049b854.TextButtonControlPaneScalarDeletingDestructor.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [Wave3 noticed problems](../wave3_noticed_problems.md)

## Changes

- 2026-08-13 B006 UID0000OK whole-file implementation callback:
  - Before: `COMPLETION:86`, `CONFIDENCE:88`; formal CPP/H were blank, the page retained absent-simroot/current-helper caveats, and layout/source behavior remained prose-level and incomplete.
  - Changed to: `COMPLETION:94`, `CONFIDENCE:95`; owner `0000OK`, `RECONSTRUCTABLE:TRUE`, and emitter `0000OK` remain unchanged. The exact accepted four-body CPP and complete H are installed only in the formal channels, with full layout, hash, caller/xref, boundary, compiler/data, generated-defect, and historical-correction evidence.
  - Evidence: Gate 1 report SHA256 `252A1CEB3A98F1ED96A6A65DF6B76D74330C4A085840A5CB388804D6F16B93BD`. This ordinary callback does not claim generated refresh, manual coverage, IDA mutation, Gate 2, lifecycle, or execution.

- 2026-07-03 B006 implementation callback:
  - Metadata unchanged. Updated UID0002YE method/support wording to reflect the accepted formal covered-by marker disposition for the compiler-generated scalar deleting destructor wrapper.
  - Evidence: B006 report and target page record MCP session `3a33af0b`, exact `0x0049b7a0-0x0049b854` wrapper size/body/padding, vtable/thunk-only reachability, three TextButton vtable restores, `+0x10c` cleanup, ordinary destructor comparison at `0x00495130`, delete-helper/guard-size wrapper paths, and rejected raw-wrapper/no-owner/non-emitting alternatives.
- 2026-06-16 A002 Goal2 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`; owner and emitter remain [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md).
  - Evidence: live IDA MCP reconfirmed method sizes, ten constructor/setup refs, destructor/vtable refs, exact adjustor thunk and scalar deleting destructor support, stale `0x004964e0` non-function/no-xref status, and broad `DrawTextInRect` fanout with the `OnPaint` call as one dependency. Final C++ remains blank because field names, base declaration shape, and shared text-render source placement still need final-source review.
- 2026-06-07 A010 Batch096 class coverage toss-up:
  - Before: score `84/82`, `AUTOGEN_PARENT_UID` blank, with the likely direct file parent also below the corrected gate.
  - After: score `85/85`, `AUTOGEN_PARENT_UID:0000OK`.
  - Evidence: associated file work raised [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) to `85/85`; exact destructor support pages now cover the adjustor thunk pair and scalar deleting destructor/vtable cell; the class page keeps the stale `SetTextResource` radio-helper row and shared `DrawTextInRect` helper as exclusions rather than class-owned methods. Final C++ remains blank below the 95/95 code gate.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` while leaving `AUTOGEN_PARENT_UID` blank.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed function starts for the documented constructor, destructor, text copy, paint, and shared draw helper at `0x00495040`, `0x00495130`, `0x004951b0`, `0x00495220`, and `0x004bad70`; the generated `0x004964e0` caveat still reports `Not a function`. At that time, the likely parent [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) was below the corrected gate, so parent assignment was deferred. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `82`.
- Evidence: the page documents button role, constructor/destructor/get-text/paint ranges, shared draw helper, destructor/core memory links, and the `SetTextResource` generated-data caveat; confidence remains capped by provisional helper ownership around the radio-group island.
