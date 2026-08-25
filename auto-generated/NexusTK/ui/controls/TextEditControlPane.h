// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OM
// Source by-file doc: by-file/TextEditControlPane.md
// UID:0000EM | by-class/TextEditControlPane.md | Completion:92 | Confidence:94
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
