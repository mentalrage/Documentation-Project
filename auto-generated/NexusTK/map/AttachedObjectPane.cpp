// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HJ
// Source by-file doc: by-file/AttachedObjectPane.md
// UID:00000M | by-class/AttachedObjectPane.md | Completion:91 | Confidence:93
#include "../util/PoolAllocator.h"

// UID:0004QP | by-memory/0x005385c0-0x005385c7.AttachedObjectPaneGetLivingObjectPane.md | Completion:91 | Confidence:92
LivingObjectPane *AttachedObjectPane::GetLivingObjectPane() const
{
    return m_livingObjectPane;
}

// UID:0004QQ | by-memory/0x005385d0-0x005385e4.AttachedObjectPaneGetLivingObjectId.md | Completion:91 | Confidence:92
int AttachedObjectPane::GetLivingObjectId() const
{
    if (m_livingObjectPane == NULL)
        return 0;
    return m_livingObjectPane->GetObjectId();
}

// UID:0004QR | by-memory/0x005385f0-0x00538600.AttachedObjectPaneSetLivingObjectPane.md | Completion:91 | Confidence:92
void AttachedObjectPane::SetLivingObjectPane(LivingObjectPane *pane)
{
    m_livingObjectPane = pane;
}

// UID:000350 | by-memory/0x00620544-0x006205f8.AttachedObjectPaneVtableData.md | Completion:87 | Confidence:91
// Compiler-emitted RTTI/vtable data for AttachedObjectPane is regenerated from
// [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) AttachedObjectPane class declarations, virtual method definitions,
// destructor wrappers, and the [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) AttachedObjectPane.cpp source module.
// No raw vtable or RTTI dword tables are hand-authored for this .rdata range.

// UID:000067 | by-class/HitBarObjectPane.md | Completion:90 | Confidence:93
class HitBarObjectPane : public AttachedObjectPane
{
public:
    HitBarObjectPane(
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX,
        unsigned short primaryValue,
        unsigned short primaryMaximum,
        unsigned char style);
    HitBarObjectPane(
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX,
        unsigned short primaryValue,
        unsigned short primaryMaximum,
        unsigned short secondaryValue,
        unsigned short secondaryMaximum);
    virtual ~HitBarObjectPane();

    void SetValues(
        unsigned short primaryValue,
        unsigned short primaryMaximum,
        unsigned short secondaryValue,
        unsigned short secondaryMaximum);
    bool IsActive() const;

    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);
    virtual void UpdatePosition();

private:
    unsigned short m_primaryValue;       // 0x12c
    unsigned short m_primaryMaximum;     // 0x12e
    unsigned char m_style;               // 0x130
    bool m_active;                       // 0x131
    unsigned short m_secondaryValue;     // 0x132
    unsigned short m_secondaryMaximum;   // 0x134
};

typedef char HitBarObjectPaneSizeMustBe312[
    sizeof(HitBarObjectPane) == 0x138 ? 1 : -1];


// UID:000353 | by-memory/0x00620734-0x006207e8.HitBarObjectPaneVtableData.md | Completion:88 | Confidence:91
// Compiler-emitted RTTI/vtable data for HitBarObjectPane is regenerated from
// [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md) HitBarObjectPane class declarations, virtual method definitions,
// destructor wrappers, and the [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) AttachedObjectPane.cpp source module.
// No raw vtable or RTTI dword tables are hand-authored for this .rdata range.

// UID:0002YR | by-memory/0x00620bc0-0x00620bdc.DeadSignResourceString.md | Completion:86 | Confidence:91
// HitBarObjectPane source references L"DEADSIGN.EPF" from its dead-sign render path.
// No standalone raw .rdata string block is hand-authored for [UID:0002YR].

// UID:0002WP | by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md | Completion:88 | Confidence:93
static PoolAllocator g_hitBarObjectPanePool(0x138, 4);

// UID:00009P | by-class/ObjectInfoObjectPane.md | Completion:91 | Confidence:93
class ObjectInfoObjectPane : public AttachedObjectPane
{
public:
    ObjectInfoObjectPane(
        LivingObjectPane *owner,
        int mapY,
        int mapX,
        const wchar_t *primaryName,
        int textColor,
        unsigned char outlineColor,
        unsigned char fillColor);
    virtual ~ObjectInfoObjectPane();

    void SetPrimaryName(const wchar_t *name);
    void SetSelectedName(const wchar_t *name);
    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);
    virtual void SetSpriteAttribute(unsigned char value);
    virtual void UpdatePosition();

private:
    friend class MapPane;

    bool m_tracksSelectedName;               // +0x12c
    wchar_t m_primaryName[33];               // +0x12e
    wchar_t m_selectedName[33];              // +0x170
    int m_textColor;                         // +0x1b4
    unsigned char m_outlineColor;            // +0x1b8
    unsigned char m_fillColor;               // +0x1b9
    LivingObjectPane *m_nameOwner;           // +0x1bc
};

typedef char ObjectInfoObjectPaneSizeMustBe448[
    sizeof(ObjectInfoObjectPane) == 0x1c0 ? 1 : -1];


// UID:000355 | by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md | Completion:88 | Confidence:92
// Compiler-emitted RTTI/vtable data for ObjectInfoObjectPane is regenerated from
// [UID:00009P][ObjectInfoObjectPane](by-class/ObjectInfoObjectPane.md) ObjectInfoObjectPane class declarations, virtual method definitions,
// destructor wrappers, and the [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) AttachedObjectPane.cpp source module.
// No raw vtable or RTTI dword tables are hand-authored for this .rdata range.



// UID:000276 | by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md | Completion:90 | Confidence:94
static unsigned char s_balloonFrameMasks[6][4] = {
    { 0xC6, 0x28, 0x10, 0x10 },
    { 0x10, 0x10, 0x28, 0xC6 },
    { 0x30, 0x40, 0x80, 0x80 },
    { 0xC0, 0x20, 0x10, 0x10 },
    { 0x80, 0x80, 0x40, 0x30 },
    { 0x10, 0x10, 0x20, 0xC0 },
};

// UID:0002WU | by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md | Completion:88 | Confidence:93
static PoolAllocator g_balloonObjectPanePool(0x1e0, 0x10);

// UID:00003F | by-class/DamageNumberObjectPane.md | Completion:90 | Confidence:93
class DamageNumberObjectPane : public AttachedObjectPane
{
public:
    DamageNumberObjectPane(
        LivingObjectPane *livingObjectPane,
        int mapY,
        int mapX,
        int damageAmount,
        unsigned char style);
    virtual ~DamageNumberObjectPane();

    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);
    virtual void UpdatePosition();

private:
    unsigned char m_style;
    unsigned char m_animationFrame;
    int m_absoluteAmount;
    bool m_positive;
    char m_digitFrameOffset;
    char m_damageText[16];
};

typedef char DamageNumberObjectPaneSizeMustBe328[
    sizeof(DamageNumberObjectPane) == 0x148 ? 1 : -1];

// UID:0004SK | by-memory/0x00539230-0x0053935e.DamageNumberObjectPaneConstructor.md | Completion:91 | Confidence:93
DamageNumberObjectPane::DamageNumberObjectPane(
    LivingObjectPane *livingObjectPane,
    int mapY,
    int mapX,
    int damageAmount,
    unsigned char style)
    : AttachedObjectPane(
          kObjectPaneTypeDamageNumber,
          livingObjectPane,
          mapY,
          mapX),
      m_style(style),
      m_animationFrame(0),
      m_absoluteAmount(damageAmount),
      m_positive(damageAmount >= 0),
      m_digitFrameOffset(0)
{
    SetMode(3);
    m_alpha = 0;

    if (!m_positive)
        m_absoluteAmount = -damageAmount;

    sprintf_s(
        m_damageText,
        sizeof(m_damageText),
        "%d",
        m_absoluteAmount);

    if (m_style != 0)
    {
        if (!m_positive)
            m_digitFrameOffset += 10;
    }
    else
    {
        m_digitFrameOffset += 20;
        if (m_positive)
            m_digitFrameOffset += 10;
    }

    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this),
        0,
        20,
        0,
        0);
}


// UID:000354 | by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md | Completion:88 | Confidence:92
// Emitted code for this range is covered by [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md).

// UID:0002YS | by-memory/0x00620bdc-0x00620c10.DamageNumberResourceStrings.md | Completion:87 | Confidence:92
// DamageNumberObjectPane source references "%d", L"DMGNUM.EPF", and L"DMGNUM.PAL".
// No standalone raw .rdata string block is hand-authored for [UID:0002YS].


// UID:0002WQ | by-memory/0x0069b95c-0x0069b984.DamageNumberObjectPanePoolStaticStorage.md | Completion:88 | Confidence:93
static PoolAllocator g_damageNumberObjectPanePool(0x148, 8);

// UID:0001D8 | by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md | Completion:91 | Confidence:93
#include "AttachedObjectPane.h"

#include "LivingObjectPane.h"
#include "MapPane.h"

MapPoint *AttachedObjectPane::GetAttachedScreenPosition(MapPoint *outPoint) const
{
    ObjectPane *source = m_livingObjectPane != 0
        ? static_cast<ObjectPane *>(m_livingObjectPane)
        : const_cast<AttachedObjectPane *>(this);
    return g_activeMapPane->GetObjectScreenPoint(source, outPoint);
}

// UID:0003CC | by-memory/0x00620c10-0x00620c64.ObjectOverlayFrameIndexTables.md | Completion:86 | Confidence:91
// ObjectOverlayFrameIndexTables is documented as file-local attached-overlay constant data.
// Current IDA evidence has no direct xrefs or original declaration name for [UID:0003CC],
// so no standalone source table is emitted from this marker.

// UID:000384 | by-memory\0x0053d240-0x0053d2d7.HitBarObjectPaneScalarDeletingDestructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:000386 | by-memory\0x0053d620-0x0053d65b.ObjectInfoObjectPaneScalarDeletingDestructor.md | Completion:89 | Confidence:93 | Empty Emitter Marker

// UID:00000U | by-class\BalloonObjectPane.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0000YZ | by-memory\0x00467b30-0x0046904e.BalloonObjectPane.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:000381 | by-memory\0x0053d060-0x0053d0f7.DamageNumberObjectPaneScalarDeletingDestructor.md | Completion:89 | Confidence:93 | Empty Emitter Marker

// UID:0003CD | by-memory\0x00620c64-0x00620c68.DamageNumberAnimationStepConstant.md | Completion:85 | Confidence:91 | Empty Emitter Marker
