*** UID:0000E4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "FontStyle.h"

class Layer;
struct RectBounds;

class StaticTextControlPane2 : public ControlPane
{
public:
    class SimpleHelpTextPartPane : public Pane
    {
    public:
        SimpleHelpTextPartPane();
        virtual ~SimpleHelpTextPartPane() {}
        virtual void OnPaint();

    private:
        friend class StaticTextControlPane2;

        void DrawTextLine(const FontStyleRule& style,
                          int x,
                          int y,
                          const wchar_t *text,
                          short charCount);

        SimpleUString m_text;
        int m_horizontalPadding;
        int m_verticalPadding;
        int m_lineSpacing;
        FontStyle *m_fontStyle;
    };

    StaticTextControlPane2(const wchar_t *text,
                           int x,
                           int y,
                           int horizontalAlignment,
                           int verticalAlignment,
                           const FontStyle *fontStyle,
                           int horizontalPadding,
                           int verticalPadding,
                           int lineSpacing);
    virtual ~StaticTextControlPane2();

    void SetCenterPosition(int centerX, int centerY);

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual void Show();
    virtual void Hide();
    virtual void OnPaint();
    virtual unsigned char GetControlType(int, int);

private:
    void ApplyStyleState();

    wchar_t m_textBuffer[40];
    unsigned int m_fillColor;
    unsigned int m_frameColor;
    FontStyle m_fontStyle;
    int m_horizontalPadding;
    int m_verticalPadding;
    int m_lineSpacing;
    int m_textWidth;
    int m_textHeight;
    int m_horizontalAlignment;
    int m_verticalAlignment;
    SimpleHelpTextPartPane m_textPart;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# StaticTextControlPane2

## Status

- Confidence: strong.
- Likely source file: [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- File emission position: `20`, after older StaticTextControlPane at `10` and before B005-owned nested route at `30`.
- Main source ranges: exact children of [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md); vtable data [UID:0004L6][0x00618600-0x006186a4.StaticTextControlPane2VtableData](by-memory/0x00618600-0x006186a4.StaticTextControlPane2VtableData.md).
- Reconstruction: complete declaration plus namespace-scope `[[CHILDREN]]`; compiler ABI is marker-covered and never handwritten.

## Class Purpose

`StaticTextControlPane2` is a `0x2a8`-byte ControlPane-derived static/help text control. It measures CR/LF/tab-delimited text, computes padded dimensions, aligns and clamps bounds to screen coordinates, paints style-derived fill/frame colors, manages parent and child opacity/mode state, and owns an embedded [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md) by value. The complete nested type is declared once here; B005 owns its separate method-route page and children.

The outer declaration closes before `[[CHILDREN]]`, so exact outer method definitions expand at namespace scope. The frozen B005 report SHA `321CD4518BDB36ACF55A6B9AAF3DE2E434E56AF7462FC6F1C242B318CB7D1811` contains a byte-identical copy of this managed block for collision detection and treats UID0000E4 as B002-owned/verify-only.

## Object Layout

| Offset / size | Source member or base | Evidence/disposition |
| --- | --- | --- |
| `+0x000`, `0x108` | `ControlPane` base | Constructor route is `ControlPane(8,NULL)`; three Pane/EventHandler views produce the vtables/adjustors. |
| `+0x108..+0x157`, `0x50` | `wchar_t m_textBuffer[40]` | One contiguous natural field ending at next proven color. Observed `wcscpy_s` logical capacity remains 32. No independent `+0x148` record/reserve exists. |
| `+0x158`, `+0x15c` | fill/frame colors | Set from FontStyle foreground/background; consumed by OnPaint. |
| `+0x160`, `0x20` | `FontStyle m_fontStyle` | Optional deep-copy assignment; owns rule vector. |
| `+0x180..+0x198` | padding, spacing, text dimensions, horizontal/vertical alignment | Seven signed integer fields used by constructor/center helper/child setup. |
| `+0x19c`, `0x10c` | `SimpleHelpTextPartPane m_textPart` | Complete by-value nested child; friend access preserves direct constructor/style stores without inventing raw setter calls. |

Eight constructor callers allocate exactly `0x2a8`. No target method/caller/lifecycle/address-taking route establishes a boundary at `+0x148`; RectBounds, FontStyleRule, anonymous integers, opaque record, and explicit reserve interpretations are superseded.

## FontStyle Header Dependency

This declaration requires the complete [UID:00005C][FontStyle](by-class/FontStyle.md) definition before first use. It owns `FontStyle m_fontStyle` by value, accepts `const FontStyle *`, stores `FontStyle *` in the nested text part, and accepts `const FontStyleRule&`; a forward declaration is insufficient for the by-value member. The formal CPP therefore includes `FontStyle.h` before the class declaration.

The dependency does not transfer ownership: StaticTextControlPane2 remains a consumer. FontStyle constructor/GetRule/Configure source stays in UID0000JI/UID00011T, while implicit vector destruction/growth remains compiler output. This class keeps its existing deep-copy, enabled/opacity/color accessor behavior unchanged.

## Method Families

| Range | Function | Role |
| --- | --- | --- |
| [UID:0004KS][0x0049a410-0x0049a8ac.StaticTextControlPane2Constructor](by-memory/0x0049a410-0x0049a8ac.StaticTextControlPane2Constructor.md) | position 10 | Base type 8/null bounds; optional FontStyle deep copy; independent CR/LF/tab measurement; padding, alignment, screen clamp, 32-limit checked copy, child setup, and style call. |
| [UID:0004KT][0x0049a8b0-0x0049a949.StaticTextControlPane2Destructor](by-memory/0x0049a8b0-0x0049a949.StaticTextControlPane2Destructor.md) | position 20 | Empty source body; members/bases regenerate child/StringBase/vector/Pane cleanup. |
| [UID:0004KV][0x0049a950-0x0049aa71.StaticTextControlPane2SetCenterPosition](by-memory/0x0049a950-0x0049aa71.StaticTextControlPane2SetCenterPosition.md) | position 30 | Rebuilds aligned/clamped rectangle around display-space center and applies it to parent and child. |
| [UID:0004KW][0x0049aa80-0x0049aaba.StaticTextControlPane2AddToLayer](by-memory/0x0049aa80-0x0049aaba.StaticTextControlPane2AddToLayer.md) | position 40 | Base uses caller layer; child uses global overlay context. |
| [UID:0004KX][0x0049aac0-0x0049aada.StaticTextControlPane2RemoveFromLayer](by-memory/0x0049aac0-0x0049aada.StaticTextControlPane2RemoveFromLayer.md) | position 50 | Child then base. |
| [UID:0004KY][0x0049aae0-0x0049aaf8.StaticTextControlPane2Show](by-memory/0x0049aae0-0x0049aaf8.StaticTextControlPane2Show.md) / [UID:0004KZ][0x0049ab00-0x0049ab18.StaticTextControlPane2Hide](by-memory/0x0049ab00-0x0049ab18.StaticTextControlPane2Hide.md) | positions 60/70 | Base then child for both visibility transitions. |
| [UID:0004L0][0x0049ab20-0x0049ab79.StaticTextControlPane2OnPaint](by-memory/0x0049ab20-0x0049ab79.StaticTextControlPane2OnPaint.md) | position 80 | Fill current bounds with foreground color; frame with background color. |
| [UID:0004L1][0x0049ab80-0x0049ac59.StaticTextControlPane2ApplyStyleState](by-memory/0x0049ab80-0x0049ac59.StaticTextControlPane2ApplyStyleState.md) | position 90 | Retained private helper with exact enabled/opacity/mode/color and child branches. |
| [UID:0004L2][0x0049b019-0x0049b02f.StaticTextControlPane2AdjustorThunks](by-memory/0x0049b019-0x0049b02f.StaticTextControlPane2AdjustorThunks.md) | no source | `this -= 0xa0/0xa4` compiler glue, false/NONE/blank. |
| [UID:0004L3][0x0049b5f0-0x0049b6bc.StaticTextControlPane2ScalarDeletingDestructor](by-memory/0x0049b5f0-0x0049b6bc.StaticTextControlPane2ScalarDeletingDestructor.md) | position 100 marker | Source-declared/generated-binary, covered by virtual destructor. |
| [UID:0004L4][0x0049b910-0x0049b915.StaticTextControlPane2GetControlType](by-memory/0x0049b910-0x0049b915.StaticTextControlPane2GetControlType.md) | position 110 | Non-const unsigned-byte virtual with two ints; returns 24. |
| [UID:0004L5][StaticTextControlPane2Vtables](by-type/by-vtable/StaticTextControlPane2Vtables.md) / [UID:0004L6][0x00618600-0x006186a4.StaticTextControlPane2VtableData](by-memory/0x00618600-0x006186a4.StaticTextControlPane2VtableData.md) | positions 120/130 markers | Three views/RTTI are compiler-generated from declaration and virtuals. |

## Evidence Notes

- Eight constructor callers from MiniMap and NewMail agree on allocation/signature and include literals `NPC`, `Portal`, `X : `, `Y : `, and `Keep a copy `.
- Independent CR/LF/tab segmentation, exact width/height formulas, horizontal `0/1/other`, vertical `3/4/other`, and screen clamping are preserved in source.
- Parent style disabled returns. Parent opacity `>=1` selects mode 1; `[0,1)` selects mode 3 and alpha; negative skips mode/alpha but continues colors/child. Child opacity `<=0` selects mode 1; `(0,1]` selects mode 3 and alpha; above 1 does nothing.
- The ordinary destructor and scalar wrapper share object cleanup but differ by delete flags/operator-delete path; vptr/free/guard logic stays compiler-generated.
- The terminal primary slot is exactly `mov al,18h; retn 8`. ControlPane and seven sibling implementations prove `unsigned char GetControlType(int,int)`; historical no-argument and `GetControlTypeId` wording is superseded.
- FontStyle vector growth, shared EH cleanup, copy assignment, Popup callback, and all Slider/TextEdit/TargetOption/TextButton/Rectangle/Scrollable sibling rows remain outside class source despite physical adjacency in UID00011V.
- Exact local/inter-function `0xcc` spans are documented on UID00011V and `by-memory/-ignored.md`; no unexplained target byte remains.

## Cross-References

- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0000E5][StaticTextControlPane2__SimpleHelpTextPartPane](by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md)
- [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md)
- [UID:0004L5][StaticTextControlPane2Vtables](by-type/by-vtable/StaticTextControlPane2Vtables.md)
- [UID:0004L6][0x00618600-0x006186a4.StaticTextControlPane2VtableData](by-memory/0x00618600-0x006186a4.StaticTextControlPane2VtableData.md)

## Changes

- 2026-08-17 B006 accepted UID0000JI dependency callback:
  - Added `#include "FontStyle.h"` before the complete StaticTextControlPane2 declaration because the class owns FontStyle by value and uses FontStyleRule by reference.
  - Preserved all existing StaticTextControlPane2 behavior, layout, ownership, method children, metadata, and source order; this is a dependency repair only.

- 2026-07-13 B002 accepted UID00011V callback:
  - Raised `88/90 -> 92/93`, set file position 20, inserted the complete accepted outer/nested declaration, and placed `[[CHILDREN]]` after the outer `};` for namespace-scope method definitions.
  - Resolved the layout to one `wchar_t[40]` field with exact 32-character checked-copy limit, added every source/compiler child UID and position, and corrected destructor/center/style endpoints and `GetControlType(int,int)` ABI.
  - Preserved B005-exclusive UID0000E5/UID00011U ownership and frozen report SHA `321CD451...`; this page contains the shared declaration once and was not synchronized by editing B005-owned pages.
- 2026-06-05: A004 raised the class to `88/90`, removed stale recovered-file provenance, added live raw helper/destructor coverage at `0x0049a8b0`, `0x0049a950`, and `0x0049ab80`, and documented the sibling rows inside the broad historical range.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents extended static/help text behavior, constructor/forwarding/paint/destructor/type-id ranges, embedded part-pane ownership, caller evidence, and local-buffer caveat; remaining completion gap is source-ready C++ detail.
- Before: the class index listed the method cluster and fixed type-id helper as ending at `0x0049b914`.
- Changed to: `0x0049b915`.
- Summary/evidence: IDA MCP reports the type-id helper at `0x0049b910` as size `0x5`, so the `retn 8` helper spans `0x0049b910-0x0049b915`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, layer/show/hide forwarding, paint, scalar deleting destructor, and type-id helper at `0x0049a410`, `0x0049aa80`, `0x0049ab20`, `0x0049b5f0`, and `0x0049b910`; both class (`86/88`) and parent file (`86/80`) meet the 80/80 gate.
