// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KM
// Source by-file doc: by-file/LegendPane.md
// UID:000074 | by-class/LegendPane.md | Completion:91 | Confidence:93
class Event;

class LegendPane : public TextEditPane
{
public:
    LegendPane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};

// UID:0001HB | by-memory/0x0056c400-0x0056c493.LegendPane.md | Completion:88 | Confidence:91
LegendPane::LegendPane()
    : TextEditPane(g_useEpfAssets ? 175 : 145,
                   g_useEpfAssets ? 229 : 180,
                   g_useEpfAssets ? 160 : 145,
                   g_useEpfAssets ? 229 : 180,
                   128,
                   0,
                   false,
                   true,
                   6,
                   static_cast<unsigned short>(IsLegacyAssetMode()),
                   true,
                   0)
{
    m_verticalScrollBarOffset = 63;
}

// UID:00023W | by-memory/0x0056c4a0-0x0056c4b5.LegendPaneInputFalseOverrides.md | Completion:92 | Confidence:94
bool LegendPane::HandleKeyOrTextEvent(Event *event)
{
    return false;
}

bool LegendPane::OnMouseEvent(Event *event)
{
    return false;
}

// UID:00038P | by-type\by-vtable\LegendPaneVtables.md | Completion:90 | Confidence:94 | Empty Emitter Marker

// UID:0002V0 | by-memory\0x00624384-0x00624438.LegendPaneVtableData.md | Completion:90 | Confidence:94 | Empty Emitter Marker
