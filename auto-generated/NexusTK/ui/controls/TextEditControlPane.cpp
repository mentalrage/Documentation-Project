// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OM
// Source by-file doc: by-file/TextEditControlPane.md
// UID:0000EM | by-class/TextEditControlPane.md | Completion:92 | Confidence:94
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

// UID:0004K1 | by-memory/0x004988d0-0x00498b8d.TextEditControlPaneConstructors.md | Completion:92 | Confidence:94
namespace {
const int kTextEditScrollBarSize = 12;
const int kTextEditBorderInset = 2;
const unsigned int kTextEditAlternateStyle = 2;
const unsigned int kTextEditSingleLineStyle = 0x100;
}

TextEditControlPane::TextEditControlPane(const RectBounds *bounds,
                                         bool drawBorder,
                                         bool useThousandsSeparator)
    : ControlPane(5, bounds),
      m_useThousandsSeparator(useThousandsSeparator),
      m_drawBorder(drawBorder)
{
    m_controlFlags = 1;
}

TextEditControlPane::TextEditControlPane(const wchar_t *initialText,
                                         bool useAlternateTextStyle,
                                         int textColor,
                                         int textBackColor,
                                         const RectBounds *bounds,
                                         bool hasHorizontalScrollbar,
                                         bool hasVerticalScrollbar,
                                         bool drawBorder,
                                         bool allowMultipleLines,
                                         float textWidthScale,
                                         bool useThousandsSeparator)
    : ControlPane(5, bounds),
      m_useThousandsSeparator(useThousandsSeparator),
      m_drawBorder(drawBorder)
{
    const int width = m_bounds.right - m_bounds.left -
                      (hasVerticalScrollbar ? kTextEditScrollBarSize : 0);
    const int height = m_bounds.bottom - m_bounds.top -
                       (hasHorizontalScrollbar ? kTextEditScrollBarSize : 0);
    const short contentWidth = static_cast<short>(width * textWidthScale);
    const unsigned int styleFlags =
        (useAlternateTextStyle ? kTextEditAlternateStyle : 0) |
        (allowMultipleLines ? 0 : kTextEditSingleLineStyle);

    m_textEditPane = new TextEditPane(width,
                                      height,
                                      contentWidth,
                                      height,
                                      textColor,
                                      textBackColor,
                                      hasHorizontalScrollbar,
                                      hasVerticalScrollbar,
                                      styleFlags,
                                      IsLegacyAssetMode(),
                                      true,
                                      useThousandsSeparator);

    RectBounds childBounds = *bounds;
    OffsetRect(&childBounds, -childBounds.left, -childBounds.top);
    if (m_drawBorder)
        InsetRect(&childBounds, kTextEditBorderInset, kTextEditBorderInset);

    m_textEditPane->SetMaxLength(1024);
    m_textEditPane->SetMaxLines(1);
    m_textEditPane->SetBounds(&childBounds, false);
    m_textEditPane->SetMode(1);
    m_textEditPane->SetEditActiveState(false, false);

    if (initialText != NULL && initialText[0] != L'\0')
        m_textEditPane->InsertText(initialText, 0);

    m_controlFlags = 1;
    SetMode(m_drawBorder ? 0 : 4);
    m_cachedChildMode = m_textEditPane->GetMode();
}

// UID:0004K2 | by-memory/0x00498b90-0x00498bcf.TextEditControlPaneOrdinaryDestructor.md | Completion:90 | Confidence:93
TextEditControlPane::~TextEditControlPane()
{
    delete m_textEditPane;
    m_textEditPane = NULL;
}

// UID:0004K3 | by-memory/0x00498bd0-0x00498bef.TextEditControlPaneLimitSetters.md | Completion:90 | Confidence:93
void TextEditControlPane::SetMaxLength(short maxLength)
{
    m_textEditPane->SetMaxLength(maxLength);
}

void TextEditControlPane::SetMaxLines(short maxLines)
{
    m_textEditPane->SetMaxLines(maxLines);
}

// UID:0004K4 | by-memory/0x00498bf0-0x00498c0f.TextEditControlPaneMaskAndEditState.md | Completion:90 | Confidence:92
void TextEditControlPane::EnableMaskedText()
{
    m_textEditPane->EnableMaskedText();
}

void TextEditControlPane::SetEditActiveState(bool editActive, bool selectAll)
{
    m_textEditPane->SetEditActiveState(editActive, selectAll);
}

// UID:0002OA | by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md | Completion:90 | Confidence:93
short TextEditControlPane::ReadText(wchar_t *outText, short capacity) const
{
    return m_textEditPane->CopyWideText(outText, capacity);
}

// UID:0004K5 | by-memory/0x00498c20-0x00498c38.TextEditControlPaneGetInputText.md | Completion:92 | Confidence:93
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
TextEditControlPane::GetInputText() const
{
    return m_textEditPane->GetText();
}

// UID:0004K6 | by-memory/0x00498c40-0x00498c5f.TextEditControlPaneStateSerialization.md | Completion:90 | Confidence:92
unsigned char *TextEditControlPane::EncodeState(unsigned short *outSize) const
{
    return m_textEditPane->EncodeState(outSize);
}

void TextEditControlPane::DecodeState(const unsigned char *data,
                                      unsigned short size)
{
    m_textEditPane->DecodeState(data, size);
}

// UID:0004K7 | by-memory/0x00498c60-0x00498c72.TextEditControlPaneIsEmpty.md | Completion:90 | Confidence:93
bool TextEditControlPane::IsEmpty() const
{
    return m_textEditPane->GetTextLength() == 0;
}

// UID:0004K8 | by-memory/0x00498c80-0x00498c9d.TextEditControlPaneSelectAll.md | Completion:90 | Confidence:92
void TextEditControlPane::SelectAll()
{
    const short textLength = m_textEditPane->GetTextLength();
    m_textEditPane->SetSelectionRange(0, textLength);
}

// UID:0004K9 | by-memory/0x00498ca0-0x00498ce1.TextEditControlPaneSetText.md | Completion:90 | Confidence:93
void TextEditControlPane::SetText(const wchar_t *text)
{
    if (text == NULL || m_textEditPane == NULL)
        return;

    const short textLength = m_textEditPane->GetTextLength();
    m_textEditPane->SetSelectionRange(0, textLength);
    m_textEditPane->InsertText(text, 0);
}

// UID:0004KA | by-memory/0x00498cf0-0x00498d66.TextEditControlPaneLayerLifecycle.md | Completion:90 | Confidence:93
void TextEditControlPane::AddToLayer(const RectBounds *bounds,
                                     int order,
                                     Pane *previousPane,
                                     Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);

    RectBounds childBounds;
    m_textEditPane->GetBounds(&childBounds);
    m_textEditPane->AddToLayer(&childBounds, 0, this, layer);
}

void TextEditControlPane::RemoveFromLayer()
{
    m_textEditPane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}

// UID:0004KB | by-memory/0x00498d70-0x00498dc8.TextEditControlPaneEventForwarders.md | Completion:90 | Confidence:93
bool TextEditControlPane::HandlePointerOrMouseEvent(Event *event)
{
    return m_textEditPane->HandlePointerOrMouseEvent(event);
}

bool TextEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    return m_textEditPane->HandleKeyOrTextEvent(event);
}

bool TextEditControlPane::HandleImeEvent(Event *event)
{
    return m_textEditPane->HandleImeEvent(event);
}

// UID:0003LQ | by-memory\0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:000127 | by-memory\0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker
