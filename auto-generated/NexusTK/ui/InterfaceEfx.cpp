// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K9
// Source by-file doc: by-file/InterfaceEfx.md
// UID:00006O | by-class/InterfaceEfxMgr.md | Completion:92 | Confidence:94
class InterfaceEfxMgr : public Pane, public Singleton<InterfaceEfxMgr>
{
public:
    InterfaceEfxMgr();
    virtual ~InterfaceEfxMgr();

    void TriggerInterfaceEffect(int effectId);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    InterfaceEfx *m_characterEffect;
    InterfaceEfx *m_magicEffect;
    InterfaceEfx *m_itemEffect;
};

// UID:0004V0 | by-memory/0x004e9d00-0x004e9e78.InterfaceEfxMgrConstructor.md | Completion:92 | Confidence:94
InterfaceEfxMgr::InterfaceEfxMgr()
    : Pane(4)
{
    m_characterEffect = new InterfaceEfx(
        L"CHREFX.EPD",
        40,
        434,
        12,
        g_mainUiLayerSlots.rootPaneLayerContext,
        false,
        L"INTEFX.PAD");
    m_magicEffect = new InterfaceEfx(
        L"MAGEFX.EPD",
        40,
        434,
        12,
        g_mainUiLayerSlots.rootPaneLayerContext,
        false,
        L"INTEFX.PAD");
    m_itemEffect = new InterfaceEfx(
        L"ITEMEFX.EPD",
        40,
        434,
        12,
        g_mainUiLayerSlots.rootPaneLayerContext,
        false,
        L"INTEFX.PAD");

    ScheduleTimer(0, 0, 0, 0);
}

// UID:0004V1 | by-memory/0x004e9e80-0x004e9edf.InterfaceEfxMgrDestructor.md | Completion:92 | Confidence:94
InterfaceEfxMgr::~InterfaceEfxMgr()
{
    delete m_characterEffect;
    delete m_magicEffect;
    delete m_itemEffect;
}

// UID:00018H | by-memory/0x004e9ee0-0x004e9f2d.InterfaceEfxMgrTriggerInterfaceEffect.md | Completion:92 | Confidence:94
void InterfaceEfxMgr::TriggerInterfaceEffect(int effectId)
{
    if (!g_pConfig->shadowEnabled)
        return;

    switch (effectId) {
    case 0:
    case 1:
        m_characterEffect->Play();
        break;

    case 2:
        m_itemEffect->Play();
        break;

    case 3:
        m_magicEffect->Play();
        break;

    default:
        break;
    }
}

// UID:0004V2 | by-memory/0x004e9f40-0x004ea05e.InterfaceEfxMgrOnTimer.md | Completion:92 | Confidence:94
bool InterfaceEfxMgr::OnTimer(int, int, int)
{
    InterfaceEfx *leftEffect = new InterfaceEfx(
        L"FRMLEFX.EPD",
        40,
        0,
        0,
        g_mainUiLayerSlots.effectPaneLayerContext,
        true,
        L"INTEFX.PAD");
    InterfaceEfx *rightEffect = new InterfaceEfx(
        L"FRMREFX.EPD",
        40,
        446,
        1,
        g_mainUiLayerSlots.effectPaneLayerContext,
        true,
        L"INTEFX.PAD");

    if (g_pConfig->shadowEnabled) {
        leftEffect->Play();
        rightEffect->Play();
    }

    ScheduleTimer(0, rand() % 180000 + 120000, 0, 0);
    return true;
}

// UID:0000R8 | by-global/g_pInterfaceEfxMgr.md | Completion:92 | Confidence:94
InterfaceEfxMgr *g_pInterfaceEfxMgr = 0;

// UID:00006N | by-class\InterfaceEfx.md | Completion:85 | Confidence:88 | Empty Emitter Marker
