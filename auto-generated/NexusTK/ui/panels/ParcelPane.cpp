// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MF
// Source by-file doc: by-file/ParcelPane.md
// UID:0000A6 | by-class/ParcelPane.md | Completion:92 | Confidence:94
class FlyingParcelPane;
struct PaneKeyEvent;
struct PaneMouseEvent;

typedef unsigned char ParcelButtonState;

enum ParcelButtonStateValue
{
    kParcelButtonIdle = 0,
    kParcelButtonHover = 1,
    kParcelButtonPressed = 2,
    kParcelButtonAnimating = 3
};

class ParcelPane;
extern ParcelPane *g_pParcelPane;

class ParcelPane : public Pane,
                   public Singleton<ParcelPane>
{
public:
    ParcelPane();
    virtual ~ParcelPane();

    void SetParcelSlotData(unsigned char totalCount,
                           unsigned char leftCount,
                           unsigned char rightCount);

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool OnKeyDown(const PaneKeyEvent *event);
    virtual bool OnTimer(int timerId, int userData1, int userData2);
    virtual void OnPaint();
    virtual void AdvanceButtonAnimation(ParcelButtonState *state,
                                        signed char *frame,
                                        bool rightSide);
    virtual int ResolveButtonFrameIndex(const ParcelButtonState *state,
                                        unsigned char slotCount,
                                        bool rightSide) const;

private:
    friend class FlyingParcelPane;

    void FinishFlyingParcelAnimation(unsigned char totalCount,
                                     unsigned char leftCount,
                                     unsigned char rightCount)
    {
        SetParcelSlotData(totalCount, leftCount, rightCount);
        m_rightSlotActionEnabled = true;
        InvalidateRect(&m_bounds);
    }

    unsigned char m_totalParcelCount;
    unsigned char m_leftParcelCount;
    unsigned char m_rightParcelCount;
    bool m_rightSlotActionEnabled;
    ParcelButtonState m_leftButtonState;
    ParcelButtonState m_rightButtonState;
    signed char m_leftAnimationFrame;
    signed char m_rightAnimationFrame;
    RectBounds m_leftButtonRect;
    RectBounds m_rightButtonRect;
    bool m_leftSlotAcknowledged;
    bool m_rightSlotAcknowledged;
};

// UID:0002KB | by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md | Completion:92 | Confidence:94
ParcelPane::ParcelPane()
    : Pane(1),
      Singleton<ParcelPane>(),
      m_totalParcelCount(0),
      m_leftParcelCount(0),
      m_rightParcelCount(0),
      m_rightSlotActionEnabled(true),
      m_leftButtonState(kParcelButtonIdle),
      m_rightButtonState(kParcelButtonIdle),
      m_leftAnimationFrame(-3),
      m_rightAnimationFrame(0),
      m_leftSlotAcknowledged(false),
      m_rightSlotAcknowledged(false)
{
    SetRect(&m_leftButtonRect, 0, 0, 30, 25);
    SetRect(&m_rightButtonRect, 31, 0, 62, 25);

    SetParcelSlotData(0, 0, 0);
    SetPaneOrder(NULL, g_pBackPane);
    m_timerHandler.ScheduleTimer(0, 100, 0, 0);
}

// UID:0001EK | by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md | Completion:92 | Confidence:94
ParcelPane::~ParcelPane()
{
    RemoveFromLayer();
    UnregisterEventHandler();
}

// UID:0002KC | by-memory/0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md | Completion:92 | Confidence:94
void ParcelPane::SetParcelSlotData(unsigned char totalCount,
                                   unsigned char leftCount,
                                   unsigned char rightCount)
{
    RemoveFromLayer();

    m_totalParcelCount = totalCount;

    if (m_leftParcelCount != leftCount) {
        m_leftSlotAcknowledged = false;
    }
    m_leftParcelCount = leftCount;
    if (leftCount == 0) {
        m_leftButtonState = kParcelButtonIdle;
    }

    if (m_rightParcelCount != rightCount) {
        m_rightSlotAcknowledged = false;
    }
    m_rightParcelCount = rightCount;
    if (rightCount == 0) {
        m_rightButtonState = kParcelButtonIdle;
    }

    RectBounds paneRect;
    SetRect(&paneRect, 630, 726, 698, 751);
    if (!IsAttachedToLayer()) {
        AddToLayer(&paneRect, 0, g_pBackPane, g_mainUiLayerSlots[1]);
    }

    InvalidateRect(&m_bounds);
}

// UID:0002KD | by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md | Completion:91 | Confidence:93
bool ParcelPane::OnKeyDown(const PaneKeyEvent *event)
{
    if (event->eventKind == kPaneKeyDown)
        g_pEventMan->TranslateEventKey(event->payload[0], event->keyState);

    return false;
}

// UID:0002KE | by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md | Completion:92 | Confidence:93
bool ParcelPane::OnMouseEvent(const PaneMouseEvent& event)
{
    const int x = event.x;
    const int y = event.y;

    switch (event.type) {
    case kPaneMouseMove:
        if (!PointInRect(x, y, &m_bounds)) {
            if (m_leftButtonState != kParcelButtonAnimating)
                m_leftButtonState = kParcelButtonIdle;
            if (m_rightButtonState != kParcelButtonAnimating)
                m_rightButtonState = kParcelButtonIdle;
            return false;
        }

        if (PointInRect(x, y, &m_rightButtonRect)) {
            if (m_leftButtonState != kParcelButtonAnimating)
                m_leftButtonState = kParcelButtonIdle;
            if (m_rightButtonState != kParcelButtonPressed)
                m_rightButtonState = kParcelButtonHover;
        }

        if (PointInRect(x, y, &m_leftButtonRect)) {
            if (m_rightButtonState != kParcelButtonAnimating)
                m_rightButtonState = kParcelButtonIdle;
            if (m_leftButtonState != kParcelButtonPressed)
                m_leftButtonState = kParcelButtonHover;
        }
        return true;

    case kPaneMouseDown:
        if (!PointInRect(x, y, &m_bounds))
            return false;
        if (PointInRect(x, y, &m_rightButtonRect))
            m_rightButtonState = kParcelButtonPressed;
        if (PointInRect(x, y, &m_leftButtonRect))
            m_leftButtonState = kParcelButtonPressed;
        return true;

    case kPaneMouseUp:
        if (!PointInRect(x, y, &m_bounds))
            return false;

        m_leftButtonState = kParcelButtonIdle;
        m_rightButtonState = kParcelButtonIdle;

        if (PointInRect(x, y, &m_leftButtonRect)) {
            m_leftButtonState = kParcelButtonHover;
            if (m_leftParcelCount != 0) {
                unsigned char packet = 0x41;
                g_packetSender->QueueAndSendPacket(&packet, 1);
                m_leftSlotAcknowledged = true;
            }
        }

        if (PointInRect(x, y, &m_rightButtonRect)) {
            m_rightButtonState = kParcelButtonHover;
            if (m_rightSlotActionEnabled && g_pBulletinSession == NULL) {
                new BulletinSession(1, 0, true);
                m_rightSlotAcknowledged = true;
            }
        }
        return true;

    default:
        return false;
    }
}

// UID:0002KF | by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md | Completion:92 | Confidence:94
bool ParcelPane::OnTimer(int, int, int)
{
    if (m_leftParcelCount != 0 && !m_leftSlotAcknowledged)
        AdvanceButtonAnimation(&m_leftButtonState, &m_leftAnimationFrame, false);
    if (m_rightParcelCount != 0 && !m_rightSlotAcknowledged)
        AdvanceButtonAnimation(&m_rightButtonState, &m_rightAnimationFrame, true);

    InvalidateRect(&m_bounds);
    m_timerHandler.ScheduleTimer(0, 200, 0, 0);
    return true;
}

// UID:0002KG | by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md | Completion:92 | Confidence:93
void ParcelPane::OnPaint()
{
    EPFTileContext tileContext;

    SetDrawColor(0);
    SurfaceRenderCallbackTable::PreparePaneRegion(this, &m_bounds);

    int frameIndex = ResolveButtonFrameIndex(&m_leftButtonState,
                                             m_leftParcelCount,
                                             false);
    g_pEPFLib->LookupLayoutEntry(L"ALERTBTN.EPF", frameIndex, &tileContext);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &m_leftButtonRect,
                    1,
                    L"ALERTBTN.PAL",
                    0);

    frameIndex = ResolveButtonFrameIndex(&m_rightButtonState,
                                         m_rightParcelCount,
                                         true);
    g_pEPFLib->LookupLayoutEntry(L"ALERTBTN.EPF", frameIndex, &tileContext);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &m_rightButtonRect,
                    1,
                    L"ALERTBTN.PAL",
                    0);
}

// UID:0002KH | by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md | Completion:92 | Confidence:94
void ParcelPane::AdvanceButtonAnimation(ParcelButtonState *state,
                                        signed char *frame,
                                        bool rightSide)
{
    if (*state == kParcelButtonIdle) {
        if (*frame < 0) {
            ++*frame;
            return;
        }

        *state = kParcelButtonAnimating;
        *frame = rightSide ? 20 : 6;
        return;
    }

    if (*state == kParcelButtonAnimating) {
        ++*frame;
        if (rightSide) {
            if (*frame > 27) {
                *frame = 20;
                *state = kParcelButtonIdle;
            }
        } else {
            if (*frame > 13) {
                *frame = 6;
                *state = kParcelButtonIdle;
            }
        }
    }
}

// UID:0002KI | by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md | Completion:92 | Confidence:94
int ParcelPane::ResolveButtonFrameIndex(const ParcelButtonState *state,
                                        unsigned char slotCount,
                                        bool rightSide) const
{
    switch (*state) {
    case kParcelButtonIdle:
        if (slotCount != 0)
            return rightSide ? 17 : 3;
        return rightSide ? 14 : 0;

    case kParcelButtonHover:
        if (slotCount != 0)
            return rightSide ? 18 : 4;
        return rightSide ? 15 : 1;

    case kParcelButtonPressed:
        if (slotCount != 0)
            return rightSide ? 19 : 5;
        return rightSide ? 16 : 2;

    case kParcelButtonAnimating:
        return rightSide ? m_rightAnimationFrame : m_leftAnimationFrame;

    default:
        return 0;
    }
}

// UID:0000A5 | by-class/ParcelIconPane.md | Completion:92 | Confidence:93
#include "../core/BlackHole.h"

class ParcelIconPane;
class ParcelPane;
struct PaneEvent;

extern ParcelIconPane *g_pParcelIconPane;

class ParcelIconPane : public Pane,
                       public Singleton<ParcelIconPane>
{
public:
    ParcelIconPane();
    virtual ~ParcelIconPane();

protected:
    virtual bool OnParcelUpdate(const PaneEvent *event);

private:
    bool UpdateParcelCounts(const unsigned char *packet);

    unsigned char m_totalParcelCount;
    unsigned char m_leftParcelCount;
    unsigned char m_rightParcelCount;
    ParcelPane *m_parcelPane;
    int m_notificationState;
};

// UID:0001EG | by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md | Completion:92 | Confidence:94
ParcelIconPane::ParcelIconPane()
    : Pane(1),
      Singleton<ParcelIconPane>(),
      m_totalParcelCount(0),
      m_leftParcelCount(0),
      m_rightParcelCount(0),
      m_parcelPane(NULL)
{
    m_parcelPane = new ParcelPane;
}

// UID:0001EI | by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md | Completion:92 | Confidence:94
ParcelIconPane::~ParcelIconPane()
{
    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(m_parcelPane);
    UnregisterEventHandler();
}

// UID:00043J | by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md | Completion:92 | Confidence:93
bool ParcelIconPane::UpdateParcelCounts(const unsigned char *packet)
{
    unsigned char flags;
    unsigned short countOffset;
    unsigned char packedCount;
    unsigned char leftCount;
    unsigned char rightCount;
    unsigned char totalCount;
    unsigned char previousTotal;

    flags = packet[1];
    countOffset = (flags & 0x40) ? 31 : 2;
    if (flags & 0x20)
        countOffset += 8;
    if (flags & 0x10)
        countOffset += 9;
    if (flags & 0x08)
        countOffset += 5;

    packedCount = packet[countOffset];
    leftCount = packedCount & 0x0f;
    rightCount = packedCount >> 4;
    totalCount = leftCount + rightCount;

    previousTotal = m_totalParcelCount;
    m_totalParcelCount = totalCount;

    if (previousTotal > totalCount ||
        m_leftParcelCount < leftCount ||
        m_rightParcelCount < rightCount) {
        m_leftParcelCount = leftCount;
        m_rightParcelCount = rightCount;
        m_parcelPane->SetParcelSlotData(totalCount, leftCount, rightCount);
    }

    return false;
}

// UID:0001EJ | by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md | Completion:92 | Confidence:93
bool ParcelIconPane::OnParcelUpdate(const PaneEvent *event)
{
    if (event->packetData[0] == 8)
        return UpdateParcelCounts(event->packetData);

    return false;
}

// UID:000058 | by-class/FlyingParcelPane.md | Completion:92 | Confidence:93
class Layer;

class FlyingParcelPane : public Pane
{
public:
    FlyingParcelPane();
    virtual ~FlyingParcelPane();

    void StartAnimation(unsigned char parcelCountOrState,
                        unsigned char leftSlot,
                        unsigned char rightSlot,
                        bool isParcel);

protected:
    virtual bool AnimateStep(int timerId, int userData1, int userData2);
    virtual void DrawParcelOrLetter();

private:
    unsigned char m_animationFrame;
    unsigned char m_parcelCountOrState;
    unsigned char m_rightSlot;
    unsigned char m_leftSlot;
    bool m_isParcel;
    Layer *m_animationLayer;
};

// UID:0002KJ | by-memory/0x00546ac0-0x00546b74.FlyingParcelPaneConstructor.md | Completion:92 | Confidence:94
FlyingParcelPane::FlyingParcelPane()
    : Pane(1),
      m_animationFrame(0),
      m_parcelCountOrState(0),
      m_rightSlot(0),
      m_leftSlot(0),
      m_isParcel(false)
{
    m_animationLayer = new Layer;
}

// UID:0002R5 | by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md | Completion:92 | Confidence:94
FlyingParcelPane::~FlyingParcelPane()
{
    delete m_animationLayer;
}

// UID:0002R6 | by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md | Completion:92 | Confidence:93
void FlyingParcelPane::StartAnimation(unsigned char parcelCountOrState,
                                      unsigned char leftSlot,
                                      unsigned char rightSlot,
                                      bool isParcel)
{
    RectBounds animationRect;

    if (g_useEpfAssets == 1) {
        g_pSoundManager->PlaySample(200, 100);
        g_pScreenPane->SetLayerFrame(m_animationLayer, 0);

        m_leftSlot = leftSlot;
        m_rightSlot = rightSlot;
        m_parcelCountOrState = parcelCountOrState;
        m_isParcel = isParcel;
        m_animationFrame = 0;

        if (isParcel)
            SetRect(&animationRect, 630, 730, 659, 755);
        else
            SetRect(&animationRect, 667, 730, 698, 747);

        RemoveFromLayer();
        AddToLayer(&animationRect, 0, NULL, m_animationLayer);
        m_origin.y += 30;
        InvalidateRect(&m_bounds);
        m_timerHandler.ScheduleTimer(0, 100, 0, 0);
        return;
    }

    g_pScreenPane->SetLayerFrame(m_animationLayer, 0);

    m_leftSlot = leftSlot;
    m_rightSlot = rightSlot;
    m_parcelCountOrState = parcelCountOrState;
    m_isParcel = isParcel;
    m_animationFrame = 0;

    const int displaySlot = parcelCountOrState <= 4 ? parcelCountOrState : 4;
    SetRect(&animationRect,
            397 + displaySlot * 11,
            4,
            419 + displaySlot * 11,
            26);

    RemoveFromLayer();
    AddToLayer(&animationRect, 0, NULL, m_animationLayer);
    InvalidateRect(&m_bounds);
    m_timerHandler.ScheduleTimer(0, 10, 0, 0);
}

// UID:0002KK | by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md | Completion:92 | Confidence:93
bool FlyingParcelPane::AnimateStep(int, int, int)
{
    if (m_animationFrame < 30) {
        --m_origin.y;
        InvalidateRect(&m_bounds);
        ++m_animationFrame;
        m_timerHandler.ScheduleTimer(0, 10, 0, 0);
        return true;
    }

    RemoveFromLayer();
    g_pScreenPane->RemoveLayer(m_animationLayer);
    g_pParcelPane->FinishFlyingParcelAnimation(m_parcelCountOrState,
                                               m_leftSlot,
                                               m_rightSlot);
    return true;
}

// UID:0002KL | by-memory/0x00546df0-0x00546e6b.FlyingParcelPaneDrawParcelOrLetter.md | Completion:92 | Confidence:93
void FlyingParcelPane::DrawParcelOrLetter()
{
    EPFTileContext tileContext;

    const wchar_t *paletteName;
    if (m_isParcel) {
        g_pEPFLib->LookupLayoutEntry(L"ALERTBTN.EPF", 5, &tileContext);
        paletteName = L"ALERTBTN.PAL";
    } else {
        g_pEPFLib->LookupLayoutEntry(L"LETTER.EPF", 0, &tileContext);
        paletteName = L"LETTER.PAL";
    }

    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &m_bounds,
                    1,
                    paletteName,
                    0);
}

// UID:0000RX | by-global/g_pParcelIconPane.md | Completion:92 | Confidence:94
ParcelIconPane *g_pParcelIconPane = NULL;

// UID:0000RY | by-global/g_pParcelPane.md | Completion:92 | Confidence:94
ParcelPane *g_pParcelPane = NULL;
