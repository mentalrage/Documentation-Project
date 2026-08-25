// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OE
// Source by-file doc: by-file/SystemMessagePanes.md
// UID:0004SZ | by-class/SystemMessage.md | Completion:92 | Confidence:94
class GrafPort;
struct RectBounds;

class SystemMessage : public LObject
{
public:
    virtual bool IsHeaderMarker() const { return false; }
    virtual bool IsFooterMarker() const { return false; }
    virtual SystemMessage *Clone() = 0;
    virtual int GetLineCount(GrafPort *drawContext, short width);
    virtual void Draw(GrafPort * /*drawContext*/, RectBounds * /*bounds*/) {}
};

// UID:000246 | by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md | Completion:92 | Confidence:94
int SystemMessage::GetLineCount(GrafPort * /*drawContext*/, short /*width*/)
{
    return 1;
}

// UID:000061 | by-class/HeaderSystemMessage.md | Completion:92 | Confidence:94
class HeaderSystemMessage : public SystemMessage
{
public:
    virtual bool IsHeaderMarker() const { return true; }
    virtual SystemMessage *Clone() { return new HeaderSystemMessage; }
};

// UID:00005D | by-class/FooterSystemMessage.md | Completion:92 | Confidence:94
class FooterSystemMessage : public SystemMessage
{
public:
    virtual bool IsFooterMarker() const { return true; }
    virtual SystemMessage *Clone() { return new FooterSystemMessage; }
};

// UID:000030 | by-class/ColorStringSystemMessage.md | Completion:92 | Confidence:94
class ColorStringSystemMessage : public SystemMessage
{
public:
    ColorStringSystemMessage(const wchar_t *text, int color, int style);
    virtual ~ColorStringSystemMessage();

    virtual SystemMessage *Clone();
    virtual int GetLineCount(GrafPort *drawContext, short width);
    virtual void Draw(GrafPort *drawContext, RectBounds *bounds);

private:
    wchar_t *m_text;
    int m_color;
    int m_style;
};

[[No Children Attached]]

// UID:00009B | by-class/NewSystemMessageModifyHeightPane.md | Completion:85 | Confidence:87
// NewSystemMessageModifyHeightPane belongs to social/SystemMessagePanes.cpp, but
// class-level source is intentionally withheld here. Current evidence proves the
// constructor, drag/commit handler, paint path, singleton lifecycle, and destructor
// family, including exact vtable child [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md), +248/+256/+260 state, and
// 0x114-byte allocation size. A declaration shell would have to invent the base
// pane/event ABI and member layout, so this marker records disposition only.

// UID:00009C | by-class/NewSystemMessagePane.md | Completion:92 | Confidence:94
class Event;
class NewSystemMessageModifyHeightPane;
class SpelledPane;
class SystemMessagePane;

class NewSystemMessagePane : public PanelPane
{
public:
    NewSystemMessagePane();
    virtual ~NewSystemMessagePane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnActivate(const unsigned char *packet);
    virtual void OnPaint();

    void RefreshSpelledPane();
    void StopSpelledPaneRefresh();

private:
    SpelledPane *m_spelledPane;
    SystemMessagePane *m_systemMessagePane;
    NewSystemMessageModifyHeightPane *m_heightPane;
    wchar_t m_spelledText[256];
};

typedef char NewSystemMessagePaneSizeMustBe0x304[
    sizeof(NewSystemMessagePane) == 0x304 ? 1 : -1];


// UID:00009T | by-class/OldSystemMessagePane.md | Completion:85 | Confidence:88
// OldSystemMessagePane belongs to social/SystemMessagePanes.cpp, but the class
// declaration is intentionally withheld here. MCP confirms constructor ownership
// at 0x00588e30, caller 0x004f8861, singleton publication, vtable installs,
// resource/tile setup, message-entry seeding, exact vtable child [UID:0003DM][0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData](by-memory/0x0062d8c4-0x0062d974.OldSystemMessagePaneVtableData.md),
// and destructor cleanup. A declaration shell would have to invent the scrollable
// base ABI, adjusted-base layout, and ten tile-context member declarations.

// UID:0000EA | by-class/SystemMessagePane.md | Completion:86 | Confidence:87
// SystemMessagePane is the current scrollable system-message viewport in
// social/SystemMessagePanes.cpp. Constructor/destructor, append/prune helpers,
// packet handling, rendering, line metrics, and g_pChattingViewport lifecycle are
// documented, including exact vtable child [UID:0003DI][0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData](by-memory/0x0062d5f8-0x0062d6a8.SystemMessagePaneVtableData.md), +0x130 refresh behavior,
// +0x134 message list, and three vtable views. A declaration shell would have to
// invent inherited scroll/tile APIs, adjusted-base declarations, and member types.

// UID:0002WV | by-global/g_pChattingViewport.md | Completion:87 | Confidence:90
class SystemMessagePane;

SystemMessagePane *g_pChattingViewport = 0;

// UID:0000R2 | by-global/g_pHeightModifyPane.md | Completion:86 | Confidence:89
class NewSystemMessageModifyHeightPane;

NewSystemMessageModifyHeightPane *g_pHeightModifyPane = 0;

// UID:0000RU | by-global/g_pNewSystemMessagePane.md | Completion:85 | Confidence:90
class NewSystemMessagePane;

NewSystemMessagePane *g_pNewSystemMessagePane = 0;

// UID:0003ED | by-global/g_pOldSystemMessagePane.md | Completion:86 | Confidence:90
class OldSystemMessagePane;

OldSystemMessagePane *g_pOldSystemMessagePane = 0;

// UID:00016F | by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md | Completion:87 | Confidence:90
int GetSingleLineCount(void * /*context*/, const wchar_t * /*text*/, int /*length*/, int /*width*/)
{
    return 1;
}

// UID:0004R2 | by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md | Completion:89 | Confidence:92
void NewSystemMessagePane::RefreshSpelledPane()
{
    m_spelledPane->RefreshScrollState();
}

// UID:0004TU | by-memory/0x00588d70-0x00588d81.NewSystemMessagePaneStopSpelledPaneRefresh.md | Completion:92 | Confidence:94
void NewSystemMessagePane::StopSpelledPaneRefresh()
{
    m_spelledPane->RemoveFrame();
}

// UID:0004TV | by-memory/0x00588e00-0x00588e05.NewSystemMessagePaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool NewSystemMessagePane::HandleKeyOrTextEvent(Event *event)
{
    return false;
}

// UID:0004TW | by-memory/0x00588e10-0x00588e15.NewSystemMessagePaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool NewSystemMessagePane::HandlePointerOrMouseEvent(Event *event)
{
    return false;
}


// UID:0003GP | by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md | Completion:93 | Confidence:94
// The L"HELP.RES" bytes are emitted by the HasDATEntry and DATFile::Open use
// sites in SystemMessagePane::LoadHelpMessages and
// OldSystemMessagePane::LoadHelpMessages. Do not emit a duplicate standalone
// wide-character array for this pooled literal range.

// UID:0002AO | by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md | Completion:88 | Confidence:92
// The live singleton declarations in this storage cluster are emitted by
// [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md) g_pHeightModifyPane and [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md) g_pNewSystemMessagePane.
// The third dword at 0x0069bc14 is reviewed zero-initialized reserved storage
// with no current xrefs, so this aggregate emits only this disposition marker.

// UID:0002ZV | by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md | Completion:93 | Confidence:95
static const wchar_t *s_systemMessageHelpMessages[60] = { 0 };

// UID:0002ZW | by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md | Completion:93 | Confidence:95
static const wchar_t *s_oldSystemMessageHelpMessages[60] = { 0 };

// UID:0003GN | by-memory\0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003GO | by-memory\0x0062d974-0x0062d98c.SystemMessagePaneMsgbordEpdString.md | Completion:87 | Confidence:92 | Empty Emitter Marker
