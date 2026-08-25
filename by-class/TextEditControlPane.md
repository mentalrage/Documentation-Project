*** UID:0000EM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class Layer;
class TextEditPane;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}
struct RectBounds;

class TextEditControlPane : public ControlPane
{
public:
    TextEditControlPane(const RectBounds *bounds,
                        bool drawBorder,
                        bool useThousandsSeparator);
    TextEditControlPane(const wchar_t *initialText,
                        bool useAlternateTextStyle,
                        int textColor,
                        int textBackColor,
                        const RectBounds *bounds,
                        bool hasHorizontalScrollbar,
                        bool hasVerticalScrollbar,
                        bool drawBorder,
                        bool allowMultipleLines,
                        float textWidthScale,
                        bool useThousandsSeparator);
    virtual ~TextEditControlPane();

    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText();
    void SetEditActiveState(bool editActive, bool selectAll);
    short ReadText(wchar_t *outText, short capacity) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > GetInputText() const;
    unsigned char *EncodeState(unsigned short *outSize) const;
    void DecodeState(const unsigned char *data, unsigned short size);
    bool IsEmpty() const;
    void SelectAll();
    void SetText(const wchar_t *text);
    TextEditPane *GetTextEditPane() const
    {
        return m_textEditPane;
    }

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);

private:
    bool m_useThousandsSeparator;
    bool m_drawBorder;
    TextEditPane *m_textEditPane;
    unsigned char m_cachedChildMode;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/ControlPane.h"

class Event;
class Layer;
class TextEditPane;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}
struct RectBounds;

class TextEditControlPane : public ControlPane
{
public:
    TextEditControlPane(const RectBounds *bounds,
                        bool drawBorder,
                        bool useThousandsSeparator);
    TextEditControlPane(const wchar_t *initialText,
                        bool useAlternateTextStyle,
                        int textColor,
                        int textBackColor,
                        const RectBounds *bounds,
                        bool hasHorizontalScrollbar,
                        bool hasVerticalScrollbar,
                        bool drawBorder,
                        bool allowMultipleLines,
                        float textWidthScale,
                        bool useThousandsSeparator);
    virtual ~TextEditControlPane();

    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText();
    void SetEditActiveState(bool editActive, bool selectAll);
    short ReadText(wchar_t *outText, short capacity) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > GetInputText() const;
    unsigned char *EncodeState(unsigned short *outSize) const;
    void DecodeState(const unsigned char *data, unsigned short size);
    bool IsEmpty() const;
    void SelectAll();
    void SetText(const wchar_t *text);
    TextEditPane *GetTextEditPane() const
    {
        return m_textEditPane;
    }

    virtual void AddToLayer(const RectBounds *bounds,
                            int order,
                            Pane *previousPane,
                            Layer *layer);
    virtual void RemoveFromLayer();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandleImeEvent(Event *event);

private:
    bool m_useThousandsSeparator;
    bool m_drawBorder;
    TextEditPane *m_textEditPane;
    unsigned char m_cachedChildMode;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextEditControlPane

## Status

- Disposition: reconstructable NexusTK class routed through [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md).
- Base: [UID:000038][ControlPane](by-class/ControlPane.md); embedded/owned editor: [UID:0000EO][TextEditPane](by-class/TextEditPane.md).
- Exact source inventory: twelve direct method-family children under the non-emitting [UID:00011H][0x004988d0-0x00498dd0.TextEditControlPaneCore](by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md), inherited shared helpers [UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md), and compiler scalar wrapper [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md).
- Exact method behavior, routes, and layout are source-ready. Original private spellings and historical header factoring remain unavailable and cap scores below 95.

## Class Purpose

`TextEditControlPane` is a type-5 `ControlPane` adapter that owns a `TextEditPane`. It constructs/configures the editor, exposes text and state APIs to dialogs, attaches and detaches the child with the wrapper, forwards three EventHandler subinterfaces, synchronizes inherited wrapper/editor state, paints the optional legacy border, and destroys the owned child.

## Exact Private Layout

| Offset | Field | Evidence/status |
| --- | --- | --- |
| `+0x108` | `bool m_useThousandsSeparator` | Written by both constructors and forwarded as the final TextEditPane constructor argument; the only downstream semantic use controls thousands grouping. |
| `+0x109` | `bool m_drawBorder` | Constructor input; controls child inset and shared border helper. |
| `+0x10a-0x10b` | compiler alignment | Not a source field. |
| `+0x10c` | `TextEditPane *m_textEditPane` | Private owned allocation used by all wrappers, lifecycle/event forwarding, and destructor; exact public inline `GetTextEditPane() const` exposes the pointer to dialog source without moving or duplicating storage. |
| `+0x110` | `unsigned char m_cachedChildMode` | Cached `Pane::m_mode` used by shared state helpers. |
| `+0x111-0x113` | tail padding | Object size `0x114`. |

Bytes `+0xff-0x104` remain inherited ControlPane state: `m_controlFlags`, `m_handlesEnterKey`, `m_enabled`, `m_controlActive`, `m_visualState`, and `m_ignoreHitTesting`. They are not private TextEditControlPane members. ProfileDialog configures the inherited Enter byte through `SetHandlesEnterKey(true)` and reaches this class's private editor through the public inline getter.

## Exact Source Children

| UID | Range | Methods/source role |
| --- | --- | --- |
| [UID:0004K1][0x004988d0-0x00498b8d.TextEditControlPaneConstructors](by-memory/0x004988d0-0x00498b8d.TextEditControlPaneConstructors.md) | `0x004988d0-0x00498b8d` | Short retained and full live constructors. |
| [UID:0004K2][0x00498b90-0x00498bcf.TextEditControlPaneOrdinaryDestructor](by-memory/0x00498b90-0x00498bcf.TextEditControlPaneOrdinaryDestructor.md) | `0x00498b90-0x00498bcf` | Ordinary source destructor. |
| [UID:0004K3][0x00498bd0-0x00498bef.TextEditControlPaneLimitSetters](by-memory/0x00498bd0-0x00498bef.TextEditControlPaneLimitSetters.md) | `0x00498bd0-0x00498bef` | `SetMaxLength`, `SetMaxLines`. |
| [UID:0004K4][0x00498bf0-0x00498c0f.TextEditControlPaneMaskAndEditState](by-memory/0x00498bf0-0x00498c0f.TextEditControlPaneMaskAndEditState.md) | `0x00498bf0-0x00498c0f` | `EnableMaskedText`, `SetEditActiveState`. |
| [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadText](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md) | `0x00498c10-0x00498c1f` | Bounded UTF-16 read; 70 sites/41 functions. |
| [UID:0004K5][0x00498c20-0x00498c38.TextEditControlPaneGetInputText](by-memory/0x00498c20-0x00498c38.TextEditControlPaneGetInputText.md) | `0x00498c20-0x00498c38` | By-value one-pointer wide StringBase return through the hidden-result ABI. |
| [UID:0004K6][0x00498c40-0x00498c5f.TextEditControlPaneStateSerialization](by-memory/0x00498c40-0x00498c5f.TextEditControlPaneStateSerialization.md) | `0x00498c40-0x00498c5f` | Retained raw encode/decode wrappers. |
| [UID:0004K7][0x00498c60-0x00498c72.TextEditControlPaneIsEmpty](by-memory/0x00498c60-0x00498c72.TextEditControlPaneIsEmpty.md) | `0x00498c60-0x00498c72` | Empty predicate. |
| [UID:0004K8][0x00498c80-0x00498c9d.TextEditControlPaneSelectAll](by-memory/0x00498c80-0x00498c9d.TextEditControlPaneSelectAll.md) | `0x00498c80-0x00498c9d` | Retained raw full-selection method. |
| [UID:0004K9][0x00498ca0-0x00498ce1.TextEditControlPaneSetText](by-memory/0x00498ca0-0x00498ce1.TextEditControlPaneSetText.md) | `0x00498ca0-0x00498ce1` | Null-preserving replacement. |
| [UID:0004KA][0x00498cf0-0x00498d66.TextEditControlPaneLayerLifecycle](by-memory/0x00498cf0-0x00498d66.TextEditControlPaneLayerLifecycle.md) | `0x00498cf0-0x00498d66` | `AddToLayer`, `RemoveFromLayer`. |
| [UID:0004KB][0x00498d70-0x00498dc8.TextEditControlPaneEventForwarders](by-memory/0x00498d70-0x00498dc8.TextEditControlPaneEventForwarders.md) | `0x00498d70-0x00498dc8` | Pointer/mouse, key/text, and IME overrides. |

## Constructor And Editor Semantics

- The short constructor is retained source with zero routes; it initializes only the base, `+0x108/+0x109`, vtable state, and inherited control flag. It does not invent child/cached-mode writes.
- The full constructor has 85 code sites across 34 functions. It uses 12-pixel scrollbar deductions, scaled content width, style bits `2/0x100`, `IsLegacyAssetMode()` as TextEditPane argument ten, limits `1024/1`, local/inset bounds, mode/edit state, optional nonempty text, wrapper mode, and cached child mode in exact order.
- TextEditPane `+0x16c/+0x16e` are max length/max lines. Historical delete-index labels and `fontId` argument-ten labeling are rejected.
- The final constructor byte and field at `+0x108` are `useThousandsSeparator` / `m_useThousandsSeparator`, not a generic input mode. Full construction forwards it as explicit TextEditPane argument twelve after the legacy-asset-mode byte; no other bounded behavior family consumes it.
- The direct TextEditPane constructor defaults maximum length and maximum lines to `30000/30000`; this wrapper then deliberately narrows its owned child to `1024/1`. The two stages are complementary source behavior, not contradictory constants.

## Text And Event Types

- `GetTextEditPane() const` is an exact inline source-safe accessor for private `m_textEditPane` at `+0x10c`. [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) uses it to perform the binary's guarded direct `TextEditPane::InsertTextRange` call. The inline form adds no standalone binary body, field, vtable slot, or ownership transfer.
- `SetText` is not a substitute for the constructor path: it has null-preserving replacement behavior, whereas ProfileDialog computes nonempty length and inserts the existing selected-profile text directly into the owned editor.
- `GetInputText` and TextEditPane `GetText` return exact `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` values through the Microsoft x86 hidden-result ABI. The wrapper forwards its hidden destination to lower `GetText`; lower initialization and caller-owned destruction prove return-by-value source syntax. Compiler RTTI at `0x0061fcec` and four caller-local one-pointer lifecycles reject provisional `WideString`, explicit output-reference source declarations, and separate SSO-7 `SimpleUString`.
- The final three source methods are EventHandler pointer/mouse, key/text, and IME overrides. They are not show/hide/focus. Compiler-generated adjusted-receiver arithmetic is omitted from source.
- Raw `EncodeState`, `DecodeState`, and `SelectAll`, plus the short constructor, have zero entry routes/pointer forms but complete coherent bodies; they are retained source, not padding or ABI glue.

## Destructor Source/Compiler Boundary

UID0004K2 emits the ordinary source destructor:

```cpp
TextEditControlPane::~TextEditControlPane()
{
    delete m_textEditPane;
    m_textEditPane = NULL;
}
```

UID000127 remains blank formal C++. Vptr stores, `Pane::~Pane()` chaining, scalar-delete flags, object-free/operator-delete path, CFG/vector-delete helper, and EventHandler/TimerHandler adjustor thunks are generated by the compiler from the virtual declaration and layout.

## Shared Inherited Helpers

[UID:0003LQ][0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers](by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md) remains a separate exact page. Historical consumer-vtable evidence alone was insufficient for ownership; later RTTI class-hierarchy arrays prove StaticTextControlPane and ExchangeMoneyEditControlPane derive through TextEditControlPane, so those five shared helper slots route once through this class. No standalone TextControl owner or multi-emitter duplication is introduced.

## Rejected Owners And Source Shapes

- TextEditPane owns lower editor implementation, not these wrapper methods. ControlPane/Pane provide base state. StaticText/ExchangeMoney inherit or override slots. Dialogs are consumers.
- Do not expose raw `sub_*`, decompiler `_DWORD` fields, vptr assignments, EH cleanup, scalar-delete ABI, receiver adjustments, implicit base teardown, or padding as source methods.
- Exact original spellings for style/color/private state and method visibility remain confidence caps only.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `92` | Exact declaration, child family, layout, final-byte semantics, ordinary/compiler destructor boundary, event corrections, raw retention, dependencies, and direct source route are complete. |
| Confidence | `94` | Bytes, vtables, constructor forwarding, single downstream field use, hidden-result/caller lifecycles, lower editor methods, RTTI/type metadata, and exact children establish behavior. Private lexical spellings/header factoring retain the final cap. |

## Changes

- 2026-08-02 B006 UID0004E0 Gate 2A C020 repair: preserved the accepted CPP declaration, score, route, exact `0x114` layout, twelve source children, private field order, and all prior evidence; added the complete legal class declaration to `RECONSTRUCTION_H CODE`, including the public inline `GetTextEditPane() const` over private `m_textEditPane +0x10c`. The header includes `../core/ControlPane.h` because a derived-class definition requires a complete base type; a standalone partial member fragment would not be valid C++ header source.

- 2026-08-01 B006 UID0004E0 support callback: preserved `92/94`, owner/emitter UID0000OM, reconstructable state, exact `0x114` layout, all twelve source children, private-field order, and unrelated history. Inserted exact public inline `TextEditPane *GetTextEditPane() const` immediately after `SetText`; retained private `m_textEditPane` at `+0x10c`; documented ProfileDialog's guarded `InsertTextRange` use and why `SetText` is not behaviorally interchangeable. Synchronized inherited `+0xff..+0x104` names with current ControlPane without changing TextEditControlPane storage.

- 2026-07-19 B001 UID0002ZY accepted implementation callback: changed `91/93 -> 92/94`; replaced stale `inputMode` with behavior-backed `useThousandsSeparator` in both constructors and the private field, refined color parameter names, preserved the complete B003 class/method/child union, and recorded the direct constructor `30000/30000` defaults versus wrapper `1024/1` limits without changing owner/emitter/reconstructable metadata or class closure.

- 2026-07-14 B003 UID0003R9 implementation support sync: replaced the stale explicit output-reference declaration with exact return-by-value `GetInputText()` source syntax, synchronized the hidden-result and caller-owned temporary evidence, and preserved the complete class layout, all unrelated declarations, twelve-child inventory, source/compiler distinctions, score, route, and class closure before `[[CHILDREN]]`.
- 2026-06-05/12 history: established the wrapper class, exact core boundary, separate shared-helper band, and broad dialog use.
- 2026-06-19/21 B008/B009 history: resolved inherited StaticText destructor slots and ordinary versus scalar-deleting destructor source policy.
- 2026-06-22 history: retained the superseded no-owner caution for UID0003LQ while accepting the RTTI-backed TextEditControlPane route; preserved source-facing setup aliases used by dialog reconstruction.
- 2026-07-13 B003 UID00011H callback: changed `86/90 -> 91/93`; replaced the provisional destructor-only block with the exact class declaration; registered and linked twelve exact direct source children; corrected private/inherited layout, event names, max-limit fields, legacy argument, StringBase type, raw retention, and compiler exclusions without changing owner/emitter/reconstructable state.
- 2026-07-13 B003 callback generated-structure correction: moved `[[CHILDREN]]` after the complete class-closing `};` so qualified child definitions emit at namespace scope, and removed raw offset comments from the formal declaration. Exact `+0x108/+0x109/+0x10c/+0x110` layout evidence remains in this page's documentation table.
