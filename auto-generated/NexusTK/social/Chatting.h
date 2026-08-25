// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I5
// Source by-file doc: by-file/Chatting.md
// UID:00002Z | by-class/ColorStringChattingMessage.md | Completion:90 | Confidence:93
class GrafPort;
struct RectBounds;

class ChattingMessage : public LObject
{
public:
    virtual ChattingMessage *Clone() = 0;
    virtual int MeasureLines(GrafPort *grafPort, int width) = 0;
    virtual void Draw(GrafPort *grafPort, RectBounds *bounds) = 0;
};

class ColorStringChattingMessage : public ChattingMessage
{
public:
    ColorStringChattingMessage(const wchar_t *text,
                               int foregroundColor,
                               int backgroundColor,
                               unsigned char textStyleFlag,
                               int customForegroundRgb,
                               int customBackgroundRgb);
    virtual ~ColorStringChattingMessage();
    virtual ChattingMessage *Clone();
    virtual int MeasureLines(GrafPort *grafPort, int width);
    virtual void Draw(GrafPort *grafPort, RectBounds *bounds);

private:
    wchar_t *m_text;
    int m_foregroundColor;
    int m_backgroundColor;
    unsigned char m_textStyleFlag;
    int m_customForegroundRgb;
    int m_customBackgroundRgb;
};
