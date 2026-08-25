// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P2
// Source by-file doc: by-file/UserStatusPane.md
// UID:00009U | by-class/OldUserStatusPane.md | Completion:89 | Confidence:91
class OldUserStatusPane : public Pane
{
public:
    explicit OldUserStatusPane(const wchar_t *displayName);
    virtual ~OldUserStatusPane();

    unsigned char GetNationId() const;
    signed char GetSpiritId() const;
    void SetStatusIconId(unsigned char iconId);

    void InvalidateStatusFieldRect(int fieldId);
    void GetStatusFieldRect(int fieldId, RectBounds *bounds);
    void DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow);
    bool ApplyLegacyPositionPacket(const unsigned char *packet);
    bool ApplyLegacyMovementStep(const unsigned char *packet);
    bool ApplyLegacyMovementStepAlt(const unsigned char *packet);
    bool ApplyLegacyStatusPayload(const unsigned char *packet);

private:
    void *m_numberGlyphs;
    wchar_t m_displayName[16];
    unsigned short m_nationId;
    signed char m_spiritId;
    unsigned char m_statusIconId;
    unsigned char m_classId;
    unsigned char m_attributeLeft;
    unsigned char m_attributeCenter;
    unsigned char m_attributeRight;
    unsigned int m_statusRow8PartialValue;
    unsigned int m_statusRow8FullValue;
    unsigned int m_statusRow9PartialValue;
    unsigned int m_statusRow9FullValue;
    unsigned int m_statusRow10Value;
    unsigned int m_statusRow11Value;
    int m_positionX;
    int m_positionY;
    unsigned short m_legacyStatusTailWord0;
    unsigned short m_legacyStatusTailWord1;
};

// UID:0001NR | by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md | Completion:89 | Confidence:91
// UID:000495 | by-memory/0x005bf110-0x005bf14b.OldUserStatusPaneInvalidateStatusFieldRect.md | Completion:88 | Confidence:91
void OldUserStatusPane::InvalidateStatusFieldRect(int fieldId)
{
    RectBounds bounds;
    GetStatusFieldRect(fieldId, &bounds);
    InvalidateRect(&bounds);
}

// UID:000496 | by-memory/0x005bf150-0x005bf3b0.OldUserStatusPaneStatusFieldRectLookup.md | Completion:90 | Confidence:92
void OldUserStatusPane::GetStatusFieldRect(int fieldId, RectBounds *bounds)
{
    switch (fieldId)
    {
    case 0:
        InitRectBounds(bounds, 59, 3, 131, 15);
        break;
    case 1:
        InitRectBounds(bounds, 1, 49, 56, 94);
        break;
    case 2:
        InitRectBounds(bounds, 1, 2, 56, 47);
        break;
    case 3:
        InitRectBounds(bounds, 147, 0, 193, 17);
        break;
    case 4:
        InitRectBounds(bounds, 160, 3, 190, 15);
        break;
    case 5:
        InitRectBounds(bounds, 75, 17, 102, 29);
        break;
    case 6:
        InitRectBounds(bounds, 163, 17, 190, 29);
        break;
    case 7:
        InitRectBounds(bounds, 120, 17, 147, 29);
        break;
    case 8:
        InitRectBounds(bounds, 101, 30, 192, 42);
        break;
    case 9:
        InitRectBounds(bounds, 101, 43, 192, 55);
        break;
    case 10:
        InitRectBounds(bounds, 101, 56, 192, 68);
        break;
    case 11:
        InitRectBounds(bounds, 101, 69, 192, 81);
        break;
    case 12:
        InitRectBounds(bounds, 101, 82, 192, 94);
        break;
    default:
        InitRectBounds(bounds, 0, 0, 0, 0);
        break;
    }
}

// UID:000497 | by-memory/0x005bf3b0-0x005bf481.OldUserStatusPaneDrawNumberGlyphString.md | Completion:88 | Confidence:91
void OldUserStatusPane::DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow)
{
    RectBounds sourceBounds;
    InitRectBounds(&sourceBounds, 0, 0, 9, 11);

    for (const wchar_t *scan = text; *scan != L'\0'; ++scan, x += 9)
    {
        if (*scan == L' ' || *scan == L'/')
            continue;

        RectBounds destinationBounds;
        InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);

        const int glyphIndex = static_cast<int>(*scan) + (glyphRow * 10) - 47;
        RenderTileFrame(m_numberGlyphs, glyphIndex, &sourceBounds, &destinationBounds, true);
    }
}

// UID:000498 | by-memory/0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket.md | Completion:92 | Confidence:94
bool OldUserStatusPane::ApplyLegacyPositionPacket(const unsigned char *packet)
{
    const int x = ReadPacketInt16BE(packet + 1);
    const int y = ReadPacketInt16BE(packet + 3);

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(12);
    }

    return false;
}

// UID:000499 | by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md | Completion:89 | Confidence:91
bool OldUserStatusPane::ApplyLegacyMovementStep(const unsigned char *packet)
{
    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig))
    {
        if (direction >= 0)
            return false;

        direction &= 0x7f;
    }

    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);

    switch (direction)
    {
    case 0:
        --y;
        if (y < movementBounds.top)
            y = movementBounds.top;
        break;
    case 1:
        ++x;
        if (x >= movementBounds.right)
            x = movementBounds.right - 1;
        break;
    case 2:
        ++y;
        if (y >= movementBounds.bottom)
            y = movementBounds.bottom - 1;
        break;
    case 3:
        --x;
        if (x < movementBounds.left)
            x = movementBounds.left;
        break;
    default:
        break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(12);
    }

    return false;
}

// UID:00049A | by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md | Completion:89 | Confidence:91
bool OldUserStatusPane::ApplyLegacyMovementStepAlt(const unsigned char *packet)
{
    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig))
    {
        if (direction >= 0)
            return false;

        direction &= 0x7f;
    }

    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);

    switch (direction)
    {
    case 0:
        --y;
        if (y < movementBounds.top)
            y = movementBounds.top;
        break;
    case 1:
        ++x;
        if (x >= movementBounds.right)
            x = movementBounds.right - 1;
        break;
    case 2:
        ++y;
        if (y >= movementBounds.bottom)
            y = movementBounds.bottom - 1;
        break;
    case 3:
        --x;
        if (x < movementBounds.left)
            x = movementBounds.left;
        break;
    default:
        break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(12);
    }

    return false;
}

// UID:00049B | by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md | Completion:90 | Confidence:92
bool OldUserStatusPane::ApplyLegacyStatusPayload(const unsigned char *packet)
{
    const unsigned char flags = packet[1];
    unsigned char cursor = 2;

    if ((flags & 0x40) != 0)
    {
        const unsigned short nationId = PacketBufferReadUInt16BE(packet + 2);
        const signed char packetSpiritId = static_cast<signed char>(packet[4]);
        const unsigned char classId = packet[6];
        const unsigned int statusRow8FullValue = PacketBufferReadUInt32BE(packet + 7);
        const unsigned int statusRow9FullValue = PacketBufferReadUInt32BE(packet + 11);
        const unsigned char attributeLeft = packet[15];
        const unsigned char attributeRight = packet[16];
        const unsigned char attributeCenter = packet[19];

        m_legacyStatusTailWord0 = PacketBufferReadUInt16BE(packet + 26);
        m_legacyStatusTailWord1 = PacketBufferReadUInt16BE(packet + 28);
        cursor = 31;

        if (m_nationId != nationId)
        {
            m_nationId = nationId;
            InvalidateStatusFieldRect(1);
        }

        if (m_spiritId != packetSpiritId)
        {
            signed char spiritId = packetSpiritId;
            if (spiritId < -1)
                spiritId = -1;
            if (spiritId > 3)
                spiritId = 3;

            m_spiritId = spiritId;
            InvalidateStatusFieldRect(2);

            if (g_pTotemFrame != NULL)
                g_pTotemFrame->InvalidateFrame();
            else
                new TotemFrame();
        }

        if (m_classId != classId)
        {
            m_classId = classId;
            InvalidateStatusFieldRect(4);
        }

        if (m_statusRow8FullValue != statusRow8FullValue)
        {
            m_statusRow8FullValue = statusRow8FullValue;
            InvalidateStatusFieldRect(8);
        }
        if (m_statusRow9FullValue != statusRow9FullValue)
        {
            m_statusRow9FullValue = statusRow9FullValue;
            InvalidateStatusFieldRect(9);
        }

        if (m_attributeLeft != attributeLeft)
        {
            m_attributeLeft = attributeLeft;
            InvalidateStatusFieldRect(5);
        }
        if (m_attributeRight != attributeRight)
        {
            m_attributeRight = attributeRight;
            InvalidateStatusFieldRect(7);
        }
        if (m_attributeCenter != attributeCenter)
        {
            m_attributeCenter = attributeCenter;
            InvalidateStatusFieldRect(6);
        }
    }

    if ((flags & 0x20) != 0)
    {
        const unsigned int statusRow8PartialValue = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        const unsigned int statusRow9PartialValue = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;

        if (m_statusRow8PartialValue != statusRow8PartialValue)
        {
            m_statusRow8PartialValue = statusRow8PartialValue;
            InvalidateStatusFieldRect(8);
        }
        if (m_statusRow9PartialValue != statusRow9PartialValue)
        {
            m_statusRow9PartialValue = statusRow9PartialValue;
            InvalidateStatusFieldRect(9);
        }
    }

    if ((flags & 0x10) != 0)
    {
        const unsigned int statusRow10Value = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        const unsigned int statusRow11Value = PacketBufferReadUInt32BE(packet + cursor);

        if (m_statusRow10Value != statusRow10Value)
        {
            m_statusRow10Value = statusRow10Value;
            InvalidateStatusFieldRect(10);
        }
        if (m_statusRow11Value != statusRow11Value)
        {
            m_statusRow11Value = statusRow11Value;
            InvalidateStatusFieldRect(11);
        }
    }

    return false;
}

// UID:0002Z3 | by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md | Completion:87 | Confidence:92
// Emitted code for this OldUserStatusPane vtable-data range is covered by [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) OldUserStatusPane class declarations.

// UID:0000FS | by-class/UserStatusPane.md | Completion:92 | Confidence:94
class Event;
struct RectBounds;

class UserStatusPane : public Pane
{
public:
    explicit UserStatusPane(const wchar_t *displayName);
    virtual ~UserStatusPane();

    errno_t CopyNameLineA(wchar_t *destination, size_t capacity) const;
    errno_t CopyNameLineB(wchar_t *destination, size_t capacity) const;
    unsigned char GetPercentStatA() const;
    unsigned char GetPercentStatB() const;
    unsigned char GetPercentStatC() const;
    unsigned char GetNationId() const;
    signed char GetSpiritId() const;
    int GetSpiritIdValue() const;
    unsigned int GetDisplayValueA() const;
    unsigned int GetDisplayValueB() const;
    unsigned int GetDisplayValueC() const;
    void SetDisplayLineA(const wchar_t *text);
    void SetDisplayLineB(const wchar_t *text);
    void SetStatusIconId(unsigned char iconId);

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    void InvalidateStatusFieldRect(int fieldId);
    void GetStatusFieldRect(int fieldId, RectBounds *bounds) const;
    void DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow);
    bool ApplyLegacyPositionPacket(const unsigned char *packet);
    bool ApplyLegacyMovementStep(const unsigned char *packet);
    bool ApplyLegacyMovementStepAlt(const unsigned char *packet);
    bool ApplyStatusPayload(const unsigned char *packet);

    unsigned char *m_numberGlyphs;
    wchar_t m_nameLine[64];
    wchar_t m_displayLineA[64];
    wchar_t m_secondaryLine[64];
    unsigned short m_nationId;
    signed char m_spiritId;
    unsigned char m_statusIconId;
    unsigned char m_classId;
    unsigned char m_percentStatA;
    unsigned char m_percentStatB;
    unsigned char m_percentStatC;
    unsigned char m_inventorySlotCount;
    unsigned char m_padding285[3];
    unsigned int m_statusRow8PartialValue;
    unsigned int m_statusRow8FullValue;
    unsigned int m_statusRow9PartialValue;
    unsigned int m_statusRow9FullValue;
    unsigned int m_statusRow10Value;
    unsigned int m_statusRow11Value;
    int m_positionX;
    int m_positionY;
    unsigned short m_epfStatusTailWord0;
    unsigned short m_epfStatusTailWord1;
};

extern UserStatusPane *g_activeUserStatusPane;

// UID:0003A8 | by-memory/0x005b83b0-0x005b8526.UserStatusPaneConstructor.md | Completion:92 | Confidence:94
UserStatusPane::UserStatusPane(const wchar_t *displayName)
    : Pane(0),
      m_numberGlyphs(NULL)
{
    g_activeUserStatusPane = this;

    unsigned int fontSize = 0;
    m_numberGlyphs = static_cast<unsigned char *>(
        LoadDatFileBuffer(L"9X11FONT.BIN", 99, &fontSize));

    wcscpy_s(m_nameLine, 64, displayName);
    if (g_useEpfAssets)
    {
        m_displayLineA[0] = L'\0';
        m_secondaryLine[0] = L'\0';
    }

    m_nationId = 0xffff;
    m_spiritId = -1;
    m_statusIconId = 0xff;
    m_classId = 0;
    m_percentStatA = 0;
    m_percentStatB = 0;
    m_percentStatC = 0;
    m_inventorySlotCount = 52;
    m_statusRow8PartialValue = 0;
    m_statusRow8FullValue = 0;
    m_statusRow9PartialValue = 0;
    m_statusRow9FullValue = 0;
    m_statusRow10Value = 0;
    m_statusRow11Value = 0;
    m_positionX = 0;
    m_positionY = 0;
}

// UID:0003A9 | by-memory/0x005b8530-0x005b85ad.UserStatusPaneDestructor.md | Completion:92 | Confidence:94
UserStatusPane::~UserStatusPane()
{
    if (m_numberGlyphs != NULL)
        m_numberGlyphs = static_cast<unsigned char *>(
            GetMemoryMan()->FreeBufferMemory(m_numberGlyphs));

    g_activeUserStatusPane = NULL;
}

// UID:0001NN | by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md | Completion:92 | Confidence:94
errno_t UserStatusPane::CopyNameLineA(wchar_t *destination, size_t capacity) const
{
    return wcscpy_s(destination, capacity, m_nameLine);
}

errno_t UserStatusPane::CopyNameLineB(wchar_t *destination, size_t capacity) const
{
    return wcscpy_s(destination, capacity, m_secondaryLine);
}

unsigned char UserStatusPane::GetPercentStatA() const { return m_percentStatA; }
unsigned char UserStatusPane::GetPercentStatB() const { return m_percentStatB; }
unsigned char UserStatusPane::GetPercentStatC() const { return m_percentStatC; }
unsigned char UserStatusPane::GetNationId() const { return static_cast<unsigned char>(m_nationId); }
signed char UserStatusPane::GetSpiritId() const { return m_spiritId; }
unsigned int UserStatusPane::GetDisplayValueA() const { return m_statusRow8FullValue; }
unsigned int UserStatusPane::GetDisplayValueB() const { return m_statusRow9FullValue; }
unsigned int UserStatusPane::GetDisplayValueC() const { return m_statusRow10Value; }

void UserStatusPane::SetDisplayLineA(const wchar_t *text)
{
    wcscpy_s(m_displayLineA, 64, text);
    InvalidateRect(&m_bounds);
}

void UserStatusPane::SetDisplayLineB(const wchar_t *text)
{
    wcscpy_s(m_secondaryLine, 64, text);
    InvalidateRect(&m_bounds);
}

// UID:0004T3 | by-memory/0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue.md | Completion:90 | Confidence:92
int UserStatusPane::GetSpiritIdValue() const
{
    return m_spiritId;
}

// UID:0002LP | by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md | Completion:92 | Confidence:94
void UserStatusPane::SetStatusIconId(unsigned char iconId)
{
    m_statusIconId = iconId;
    InvalidateRect(&m_bounds);
}

// UID:0003AA | by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md | Completion:92 | Confidence:94
bool UserStatusPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = event->m_payload.m_packet.m_data;

    if (g_useEpfAssets)
    {
        if (packet[0] == 0x08)
            return ApplyStatusPayload(packet);
        return false;
    }

    switch (packet[0])
    {
    case 0x04:
        return ApplyLegacyPositionPacket(packet);
    case 0x08:
        return ApplyStatusPayload(packet);
    case 0x0b:
        return ApplyLegacyMovementStep(packet);
    case 0x26:
        return ApplyLegacyMovementStepAlt(packet);
    default:
        return false;
    }
}

// UID:0003AC | by-memory/0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:93
bool UserStatusPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type != kEventRightButtonDown)
        return false;

    if (g_pSimpleHelpPane != NULL)
        delete g_pSimpleHelpPane;

    const int mouseY = event->m_payload.m_pointer.m_y;
    const int mouseX = event->m_payload.m_pointer.m_x;
    RectBounds bounds;
    int stringId = -1;

    if (g_useEpfAssets)
    {
        InitRectBounds(&bounds, 20, 3, 96, 17);
        if (PointInRect(mouseY, mouseX, &bounds))
            stringId = 185;
        else
        {
            InitRectBounds(&bounds, 121, 4, 170, 17);
            if (PointInRect(mouseY, mouseX, &bounds))
                stringId = 186;
            else
            {
                InitRectBounds(&bounds, 0, 26, 102, 40);
                if (PointInRect(mouseY, mouseX, &bounds))
                    stringId = 188;
                else
                {
                    InitRectBounds(&bounds, 106, 26, 170, 40);
                    if (PointInRect(mouseY, mouseX, &bounds))
                        stringId = 187;
                }
            }
        }
    }
    else
    {
        InitRectBounds(&bounds, 59, 3, 131, 15);
        if (PointInRect(mouseY, mouseX, &bounds))
            stringId = 185;
        else
        {
            InitRectBounds(&bounds, 160, 3, 190, 15);
            if (PointInRect(mouseY, mouseX, &bounds))
                stringId = 186;
        }
    }

    if (stringId < 0)
        return false;

    new SimpleHelpPane(g_pLanguageMan->GetLocalizedString(stringId),
                       this, mouseX, mouseY, 5000);
    return true;
}

// UID:0003AE | by-memory/0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint.md | Completion:92 | Confidence:93
void UserStatusPane::OnPaint()
{
    RectBounds sourceBounds;
    RectBounds fieldBounds;
    wchar_t text[32];

    if (g_useEpfAssets)
    {
        EPFTileContext background;
        background.Initialize(L"USERSTAT.EPF", 0, L"ITEMINV.PAL");
        RenderTileFrame(&background, &m_bounds);

        GetStatusFieldRect(0, &fieldBounds);
        if (m_exposedRegion.IntersectsRect(&fieldBounds))
        {
            const int x = (fieldBounds.left + fieldBounds.right - GetTextWidth(m_nameLine)) / 2;
            SetTextBackColor(0);
            SetTextColor(0);
            MoveTo(x + 1, fieldBounds.top + 1);
            DrawWideText(m_nameLine);
            SetTextColor(0xffff);
            MoveTo(x, fieldBounds.top);
            DrawWideText(m_nameLine);
        }

        swprintf_s(text, 32, L"%u", static_cast<unsigned int>(m_classId));
        GetStatusFieldRect(4, &fieldBounds);
        if (m_exposedRegion.IntersectsRect(&fieldBounds))
            DrawNumberGlyphString(text, (fieldBounds.left + fieldBounds.right - 10 * wcslen(text)) / 2,
                                  fieldBounds.top, 1);

        GetStatusFieldRect(12, &fieldBounds);
        if (m_exposedRegion.IntersectsRect(&fieldBounds))
        {
            const int x = (fieldBounds.left + fieldBounds.right - GetTextWidth(m_displayLineA)) / 2;
            SetTextBackColor(0);
            SetTextColor(0);
            MoveTo(x + 1, fieldBounds.top + 1);
            DrawWideText(m_displayLineA);
            SetTextColor(0xffff);
            MoveTo(x, fieldBounds.top);
            DrawWideText(m_displayLineA);
        }

        GetStatusFieldRect(13, &fieldBounds);
        if (m_exposedRegion.IntersectsRect(&fieldBounds))
        {
            const int x = (fieldBounds.left + fieldBounds.right - GetTextWidth(m_secondaryLine)) / 2;
            SetTextBackColor(0);
            SetTextColor(0);
            MoveTo(x + 1, fieldBounds.top + 1);
            DrawWideText(m_secondaryLine);
            SetTextColor(0xffff);
            MoveTo(x, fieldBounds.top);
            DrawWideText(m_secondaryLine);
        }
        return;
    }

        EPFTileContext background;
    background.Initialize(L"USERSTAT.EPD", 0, L"NPAL7.PAL");
    RenderTileFrame(&background, &m_bounds);

    GetStatusFieldRect(0, &fieldBounds);
    if (m_exposedRegion.IntersectsRect(&fieldBounds))
    {
        const int x = (fieldBounds.left + fieldBounds.right - GetTextWidth(m_nameLine)) / 2;
        SetTextBackColor(0);
        SetTextColor(0);
        MoveTo(x + 1, fieldBounds.top + 1);
        DrawWideText(m_nameLine);
        SetTextColor(0xffff);
        MoveTo(x, fieldBounds.top);
        DrawWideText(m_nameLine);
    }

    if (m_nationId != 0xffff)
    {
        GetStatusFieldRect(1, &fieldBounds);
        EPFTileContext nation;
        if (nation.Initialize(L"NATION.EPD", m_nationId, L"NPAL7.PAL"))
            RenderTileFrame(&nation, &fieldBounds);
        else
        {
            const wchar_t *nationName = g_pLanguageMan->GetLocalizedString(m_nationId);
            MoveTo((fieldBounds.left + fieldBounds.right - GetTextWidth(nationName)) / 2,
                   fieldBounds.top);
            DrawWideText(nationName);
        }
    }

    if (m_spiritId != -1)
    {
        GetStatusFieldRect(2, &fieldBounds);
        EPFTileContext spirit;
        spirit.Initialize(L"TOTEM.EPD", m_spiritId, L"NPAL7.PAL");
        RenderTileFrame(&spirit, &fieldBounds);
    }

    if (m_statusIconId != 0xff)
    {
        GetStatusFieldRect(3, &fieldBounds);
        EPFTileContext statusIcon;
        statusIcon.Initialize(L"CLASS.EPD",
                              m_statusIconId == 0 ? 4 : m_statusIconId - 1,
                              L"NPAL5.PAL");
        RenderTileFrame(&statusIcon, &fieldBounds);
    }

    swprintf_s(text, 32, L"%3u", static_cast<unsigned int>(m_classId));
    GetStatusFieldRect(4, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 2);

    swprintf_s(text, 32, L"%3u", static_cast<unsigned int>(m_percentStatA));
    GetStatusFieldRect(5, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 1);
    swprintf_s(text, 32, L"%3u", static_cast<unsigned int>(m_percentStatC));
    GetStatusFieldRect(6, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 1);
    swprintf_s(text, 32, L"%3u", static_cast<unsigned int>(m_percentStatB));
    GetStatusFieldRect(7, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 1);

    InitRectBounds(&sourceBounds, 0, 0, 91, 12);
    GetStatusFieldRect(8, &fieldBounds);
    EPFTileContext row8Missing;
    row8Missing.Initialize(L"BAR.EPD", 2, L"NPAL7.PAL");
    RenderTileFrame(&row8Missing, &sourceBounds, &fieldBounds);
    if (m_statusRow8FullValue != 0)
    {
        RectBounds filled = fieldBounds;
        filled.right = filled.left + MulDiv(fieldBounds.right - fieldBounds.left,
                                             m_statusRow8PartialValue,
                                             m_statusRow8FullValue);
        EPFTileContext row8Fill;
        row8Fill.Initialize(L"BAR.EPD", 0, L"NPAL7.PAL");
        RenderTileFrame(&row8Fill, &sourceBounds, &filled);
    }
    swprintf_s(text, 32, L"%10u", m_statusRow8PartialValue);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 0);

    GetStatusFieldRect(9, &fieldBounds);
    EPFTileContext row9Missing;
    row9Missing.Initialize(L"BAR.EPD", 2, L"NPAL7.PAL");
    RenderTileFrame(&row9Missing, &sourceBounds, &fieldBounds);
    if (m_statusRow9FullValue != 0)
    {
        RectBounds filled = fieldBounds;
        filled.right = filled.left + MulDiv(fieldBounds.right - fieldBounds.left,
                                             m_statusRow9PartialValue,
                                             m_statusRow9FullValue);
        EPFTileContext row9Fill;
        row9Fill.Initialize(L"BAR.EPD", 1, L"NPAL7.PAL");
        RenderTileFrame(&row9Fill, &sourceBounds, &filled);
    }
    swprintf_s(text, 32, L"%10u", m_statusRow9PartialValue);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 0);

    swprintf_s(text, 32, L"%10u", m_statusRow10Value);
    GetStatusFieldRect(10, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 0);
    swprintf_s(text, 32, L"%10u", m_statusRow11Value);
    GetStatusFieldRect(11, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 2);
    swprintf_s(text, 32, L"%04u/%04u", m_positionX, m_positionY);
    GetStatusFieldRect(15, &fieldBounds);
    DrawNumberGlyphString(text, fieldBounds.left, fieldBounds.top, 2);
}

// UID:0004T4 | by-memory/0x005b9d70-0x005b9dab.UserStatusPaneInvalidateStatusFieldRect.md | Completion:91 | Confidence:93
void UserStatusPane::InvalidateStatusFieldRect(int fieldId)
{
    RectBounds bounds;
    GetStatusFieldRect(fieldId, &bounds);
    InvalidateRect(&bounds);
}

// UID:0003AD | by-memory/0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect.md | Completion:92 | Confidence:94
void UserStatusPane::GetStatusFieldRect(int fieldId, RectBounds *bounds) const
{
    if (g_useEpfAssets)
    {
        switch (fieldId)
        {
        case 0: InitRectBounds(bounds, 20, 3, 96, 17); break;
        case 4: InitRectBounds(bounds, 121, 4, 170, 17); break;
        case 12: InitRectBounds(bounds, 0, 26, 102, 40); break;
        case 13: InitRectBounds(bounds, 106, 26, 170, 40); break;
        default: break;
        }
        return;
    }

    switch (fieldId)
    {
    case 0: InitRectBounds(bounds, 59, 3, 131, 15); break;
    case 1: InitRectBounds(bounds, 1, 49, 56, 94); break;
    case 2: InitRectBounds(bounds, 1, 2, 56, 47); break;
    case 3: InitRectBounds(bounds, 147, 0, 193, 17); break;
    case 4: InitRectBounds(bounds, 160, 3, 190, 15); break;
    case 5: InitRectBounds(bounds, 75, 17, 102, 29); break;
    case 6: InitRectBounds(bounds, 163, 17, 190, 29); break;
    case 7: InitRectBounds(bounds, 120, 17, 147, 29); break;
    case 8: InitRectBounds(bounds, 101, 30, 192, 42); break;
    case 9: InitRectBounds(bounds, 101, 43, 192, 55); break;
    case 10: InitRectBounds(bounds, 101, 56, 192, 68); break;
    case 11: InitRectBounds(bounds, 101, 69, 192, 81); break;
    case 15: InitRectBounds(bounds, 101, 82, 192, 94); break;
    default: InitRectBounds(bounds, 0, 0, 0, 0); break;
    }
}

// UID:0003AF | by-memory/0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString.md | Completion:92 | Confidence:94
void UserStatusPane::DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow)
{
    RectBounds sourceBounds;
    InitRectBounds(&sourceBounds, 0, 0, 9, 11);

    for (const wchar_t *scan = text; *scan != L'\0'; ++scan, x += 9)
    {
        if (*scan == L' ' || *scan == L'/')
            continue;

        RectBounds destinationBounds;
        InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);
        const int glyphIndex = static_cast<int>(*scan) + glyphRow * 10 - 47;
        RenderTileFrame(m_numberGlyphs, glyphIndex,
                        &sourceBounds, &destinationBounds, true);
    }
}

// UID:0004T5 | by-memory/0x005ba100-0x005ba19c.UserStatusPaneApplyLegacyPositionPacket.md | Completion:91 | Confidence:92
bool UserStatusPane::ApplyLegacyPositionPacket(const unsigned char *packet)
{
    if (g_useEpfAssets)
        return false;

    const int x = ReadPacketInt16BE(packet + 1);
    const int y = ReadPacketInt16BE(packet + 3);
    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(15);
    }
    return false;
}

// UID:0004T6 | by-memory/0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md | Completion:91 | Confidence:92
bool UserStatusPane::ApplyLegacyMovementStep(const unsigned char *packet)
{
    if (g_useEpfAssets)
        return false;

    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig))
    {
        if (direction >= 0)
            return false;
        direction &= 0x7f;
    }
    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);
    switch (direction)
    {
    case 0: if (--y < movementBounds.top) y = movementBounds.top; break;
    case 1: if (++x >= movementBounds.right) x = movementBounds.right - 1; break;
    case 2: if (++y >= movementBounds.bottom) y = movementBounds.bottom - 1; break;
    case 3: if (--x < movementBounds.left) x = movementBounds.left; break;
    default: break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(15);
    }
    return false;
}

// UID:0004T7 | by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md | Completion:91 | Confidence:92
bool UserStatusPane::ApplyLegacyMovementStepAlt(const unsigned char *packet)
{
    if (g_useEpfAssets)
        return false;

    signed char direction = static_cast<signed char>(packet[1]);
    int x = ReadPacketInt16BE(packet + 2);
    int y = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (ShouldMaskLegacyMovementDirection(g_activeMapPane, g_pConfig))
    {
        if (direction >= 0)
            return false;
        direction &= 0x7f;
    }
    if (direction == 4)
        return false;

    RectBounds movementBounds;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);
    switch (direction)
    {
    case 0: if (--y < movementBounds.top) y = movementBounds.top; break;
    case 1: if (++x >= movementBounds.right) x = movementBounds.right - 1; break;
    case 2: if (++y >= movementBounds.bottom) y = movementBounds.bottom - 1; break;
    case 3: if (--x < movementBounds.left) x = movementBounds.left; break;
    default: break;
    }

    if (m_positionX != x || m_positionY != y)
    {
        m_positionX = x;
        m_positionY = y;
        InvalidateStatusFieldRect(15);
    }
    return false;
}

// UID:0003AB | by-memory/0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload.md | Completion:92 | Confidence:94
bool UserStatusPane::ApplyStatusPayload(const unsigned char *packet)
{
    if (g_useEpfAssets)
    {
        if ((packet[1] & 0x40) == 0)
            return false;

        m_nationId = PacketBufferReadUInt16BE(packet + 2);
        m_spiritId = static_cast<signed char>(packet[4]);

        if (m_classId != packet[6])
        {
            m_classId = packet[6];
            InvalidateStatusFieldRect(4);
        }
        m_statusRow8FullValue = PacketBufferReadUInt32BE(packet + 7);
        m_statusRow9FullValue = PacketBufferReadUInt32BE(packet + 11);

        if (m_percentStatA != packet[15])
        {
            m_percentStatA = packet[15];
            InvalidateStatusFieldRect(5);
        }
        if (m_percentStatB != packet[16])
        {
            m_percentStatB = packet[16];
            InvalidateStatusFieldRect(7);
        }
        if (m_percentStatC != packet[19])
        {
            m_percentStatC = packet[19];
            InvalidateStatusFieldRect(6);
        }

        m_epfStatusTailWord0 = PacketBufferReadUInt16BE(packet + 26);
        m_epfStatusTailWord1 = PacketBufferReadUInt16BE(packet + 28);
        if (m_inventorySlotCount != packet[30])
        {
            m_inventorySlotCount = packet[30];
            g_pGeneralPurposePanel->GetChildPaneByIndex(2)->OnActivate(NULL);
        }
        return false;
    }

    const unsigned char flags = packet[1];
    unsigned char cursor = 2;
    if ((flags & 0x40) != 0)
    {
        const unsigned short nationId = packet[2];
        signed char spiritId = static_cast<signed char>(packet[3]);
        const unsigned char classId = packet[5];
        const unsigned int row8Full = PacketBufferReadUInt32BE(packet + 6);
        const unsigned int row9Full = PacketBufferReadUInt32BE(packet + 10);

        if (m_nationId != nationId)
        {
            m_nationId = nationId;
            InvalidateStatusFieldRect(1);
        }
        if (spiritId < -1) spiritId = -1;
        if (spiritId > 3) spiritId = 3;
        if (m_spiritId != spiritId)
        {
            m_spiritId = spiritId;
            InvalidateStatusFieldRect(2);
            if (g_pTotemFrame != NULL)
                g_pTotemFrame->InvalidateFrame();
            else
                new TotemFrame();
        }
        if (m_classId != classId)
        {
            m_classId = classId;
            InvalidateStatusFieldRect(4);
        }
        if (m_statusRow8FullValue != row8Full)
        {
            m_statusRow8FullValue = row8Full;
            InvalidateStatusFieldRect(8);
        }
        if (m_statusRow9FullValue != row9Full)
        {
            m_statusRow9FullValue = row9Full;
            InvalidateStatusFieldRect(9);
        }

        if (m_percentStatA != packet[14])
        {
            m_percentStatA = packet[14];
            InvalidateStatusFieldRect(5);
        }
        if (m_percentStatB != packet[15])
        {
            m_percentStatB = packet[15];
            InvalidateStatusFieldRect(7);
        }
        if (m_percentStatC != packet[18])
        {
            m_percentStatC = packet[18];
            InvalidateStatusFieldRect(6);
        }
        cursor = 30;
    }

    if ((flags & 0x20) != 0)
    {
        const unsigned int row8Partial = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        const unsigned int row9Partial = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        if (m_statusRow8PartialValue != row8Partial)
        {
            m_statusRow8PartialValue = row8Partial;
            InvalidateStatusFieldRect(8);
        }
        if (m_statusRow9PartialValue != row9Partial)
        {
            m_statusRow9PartialValue = row9Partial;
            InvalidateStatusFieldRect(9);
        }
    }

    if ((flags & 0x10) != 0)
    {
        const unsigned int row10 = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        const unsigned int row11 = PacketBufferReadUInt32BE(packet + cursor);
        if (m_statusRow10Value != row10)
        {
            m_statusRow10Value = row10;
            InvalidateStatusFieldRect(10);
        }
        if (m_statusRow11Value != row11)
        {
            m_statusRow11Value = row11;
            InvalidateStatusFieldRect(11);
        }
    }
    return false;
}

// UID:0002YZ | by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md | Completion:86 | Confidence:91
// Emitted code for this UserStatusPane vtable-data range is covered by [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) UserStatusPane class declarations.

// UID:0000FT | by-class/UserStatusPane2.md | Completion:93 | Confidence:94
class Event;
struct RectBounds;

class UserStatusPane2 : public Pane
{
public:
    UserStatusPane2();
    virtual ~UserStatusPane2();

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    void InvalidateStatusFieldRect(int fieldId);
    void GetStatusFieldRect(int fieldId, RectBounds *bounds) const;
    void DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow);
    bool ApplyLegacyPositionPacket(const unsigned char *packet);
    bool ApplyLegacyMovementStep(const unsigned char *packet);
    bool ApplyLegacyMovementStepAlt(const unsigned char *packet);
    bool ApplyStatusPayload(const unsigned char *packet);

    unsigned char *m_numberGlyphs;
    int m_positionX;
    int m_positionY;
    unsigned int m_statusRow0PartialValue;
    unsigned int m_statusRow0FullValue;
    unsigned int m_statusRow1PartialValue;
    unsigned int m_statusRow1FullValue;
    unsigned int m_statusRow2Value;
    unsigned char m_statusRow2Percent;
    unsigned int m_statusRow3Value;
};

extern UserStatusPane2 *g_pUserStatusPane2;

// UID:0004TG | by-memory/0x005bab00-0x005babf7.UserStatusPane2Constructor.md | Completion:92 | Confidence:94
UserStatusPane2::UserStatusPane2()
    : Pane(1)
{
    g_pUserStatusPane2 = this;
    m_statusRow0PartialValue = 0;
    m_statusRow0FullValue = 0;
    m_statusRow1PartialValue = 0;
    m_statusRow1FullValue = 0;
    m_statusRow2Percent = 0;
    m_statusRow3Value = 0;
    m_statusRow2Value = 0;
    m_positionX = 0;
    m_positionY = 0;
    m_numberGlyphs = static_cast<unsigned char *>(
        g_pResourceMan->LoadResource(L"9X11FONT.BIN", 99));
}

// UID:0004TH | by-memory/0x005bac00-0x005bac7d.UserStatusPane2Destructor.md | Completion:92 | Confidence:94
UserStatusPane2::~UserStatusPane2()
{
    if (m_numberGlyphs != NULL)
        g_pMemoryMan->Free(m_numberGlyphs);
    g_pUserStatusPane2 = NULL;
}

// UID:0004TI | by-memory/0x005bac80-0x005baf64.UserStatusPane2HandlePacketEvent.md | Completion:92 | Confidence:94
bool UserStatusPane2::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = static_cast<const unsigned char *>(
        event->m_payload.m_packet.m_data);

    switch (packet[0])
    {
    case 0x04:
        return ApplyLegacyPositionPacket(packet);
    case 0x08:
        return ApplyStatusPayload(packet);
    case 0x0b:
        return ApplyLegacyMovementStep(packet);
    case 0x26:
        return ApplyLegacyMovementStepAlt(packet);
    default:
        return false;
    }
}

// UID:0004TJ | by-memory/0x005baf70-0x005baf75.UserStatusPane2HandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool UserStatusPane2::HandlePointerOrMouseEvent(Event *event)
{
    (void)event;
    return false;
}

// UID:0004TK | by-memory/0x005baf80-0x005bbe15.UserStatusPane2OnPaint.md | Completion:92 | Confidence:93
void UserStatusPane2::OnPaint()
{
    RectBounds fieldBounds;
    RectBounds fillBounds;
    wchar_t numberText[16];
    wchar_t groupText[4];

#define DRAW_STATUS_BAR(fieldId, currentValue, fullValue, middleFrame, leftFrame, rightFrame) \
    do { \
        GetStatusFieldRect(fieldId, &fieldBounds); \
        if ((fullValue) != 0) { \
            fillBounds = fieldBounds; \
            if ((currentValue) < (fullValue)) \
                fillBounds.left = fillBounds.right - \
                    MulDiv(fillBounds.right - fillBounds.left, currentValue, fullValue); \
            EPFTileContext middle; \
            EPFTileContext leftCap; \
            EPFTileContext rightCap; \
            middle.Initialize(L"BAR.EPF", middleFrame, L"BAR.PAL"); \
            leftCap.Initialize(L"BAR.EPF", leftFrame, L"BAR.PAL"); \
            rightCap.Initialize(L"BAR.EPF", rightFrame, L"BAR.PAL"); \
            RenderTileFrame(&middle, &fillBounds); \
            RectBounds capBounds = fillBounds; \
            capBounds.right = capBounds.left + 1; \
            RenderTileFrame(&leftCap, &capBounds); \
            capBounds.left = fillBounds.right - 1; \
            capBounds.right = fillBounds.right; \
            RenderTileFrame(&rightCap, &capBounds); \
        } \
    } while (0)

    DRAW_STATUS_BAR(4, m_statusRow0PartialValue, m_statusRow0FullValue, 0, 1, 2);
    DRAW_STATUS_BAR(5, m_statusRow1PartialValue, m_statusRow1FullValue, 3, 4, 5);

    GetStatusFieldRect(2, &fieldBounds);
    if (m_statusRow2Percent != 0)
    {
        fillBounds = fieldBounds;
        fillBounds.left = fillBounds.right -
            MulDiv(fillBounds.right - fillBounds.left, m_statusRow2Percent, 100);
        EPFTileContext middle;
        EPFTileContext leftCap;
        EPFTileContext rightCap;
        middle.Initialize(L"BAR.EPF", 6, L"BAR.PAL");
        leftCap.Initialize(L"BAR.EPF", 7, L"BAR.PAL");
        rightCap.Initialize(L"BAR.EPF", 8, L"BAR.PAL");
        RenderTileFrame(&middle, &fillBounds);
        RectBounds capBounds = fillBounds;
        capBounds.right = capBounds.left + 1;
        RenderTileFrame(&leftCap, &capBounds);
        capBounds.left = fillBounds.right - 1;
        capBounds.right = fillBounds.right;
        RenderTileFrame(&rightCap, &capBounds);
    }

#define DRAW_GROUPED_VALUE(value, fieldId, glyphRow) \
    do { \
        swprintf_s(numberText, 16, L"%10u", static_cast<unsigned int>(value)); \
        GetStatusFieldRect(fieldId, &fieldBounds); \
        if (m_exposedRegion.IntersectsRect(&fieldBounds)) { \
            int firstDigit = 0; \
            while (firstDigit < 9 && numberText[firstDigit] == L' ') ++firstDigit; \
            int x = fieldBounds.right - 27; \
            groupText[0] = numberText[7]; groupText[1] = numberText[8]; \
            groupText[2] = numberText[9]; groupText[3] = L'\0'; \
            DrawNumberGlyphString(groupText, x, fieldBounds.top, glyphRow); \
            if (firstDigit < 7) { \
                EPFTileContext comma; \
                comma.Initialize(L"COMMA.EPF", 0, L"COMMA.PAL"); \
                RectBounds commaBounds; \
                InitRectBounds(&commaBounds, x - 5, fieldBounds.top + 7, \
                               x, fieldBounds.top + 11); \
                RenderTileFrame(&comma, &commaBounds); \
                x -= 32; \
                groupText[0] = numberText[4]; groupText[1] = numberText[5]; \
                groupText[2] = numberText[6]; \
                DrawNumberGlyphString(groupText, x, fieldBounds.top, glyphRow); \
            } \
            if (firstDigit < 4) { \
                EPFTileContext comma; \
                comma.Initialize(L"COMMA.EPF", 0, L"COMMA.PAL"); \
                RectBounds commaBounds; \
                InitRectBounds(&commaBounds, x - 5, fieldBounds.top + 7, \
                               x, fieldBounds.top + 11); \
                RenderTileFrame(&comma, &commaBounds); \
                x -= 32; \
                groupText[0] = numberText[1]; groupText[1] = numberText[2]; \
                groupText[2] = numberText[3]; \
                DrawNumberGlyphString(groupText, x, fieldBounds.top, glyphRow); \
            } \
            if (numberText[0] != L' ') { \
                groupText[0] = numberText[0]; groupText[1] = L'\0'; \
                DrawNumberGlyphString(groupText, x - 9, fieldBounds.top, glyphRow); \
            } \
        } \
    } while (0)

    DRAW_GROUPED_VALUE(m_statusRow0PartialValue, 4, 2);
    DRAW_GROUPED_VALUE(m_statusRow1PartialValue, 5, 2);
    DRAW_GROUPED_VALUE(m_statusRow2Value, 2, 2);
    DRAW_GROUPED_VALUE(m_statusRow3Value, 3, 0);

    swprintf_s(numberText, 16, L"%03u", static_cast<unsigned int>(m_positionX));
    GetStatusFieldRect(7, &fieldBounds);
    if (m_exposedRegion.IntersectsRect(&fieldBounds))
        DrawNumberGlyphString(numberText, fieldBounds.left, fieldBounds.top, 1);

    swprintf_s(numberText, 16, L"%03u", static_cast<unsigned int>(m_positionY));
    GetStatusFieldRect(8, &fieldBounds);
    if (m_exposedRegion.IntersectsRect(&fieldBounds))
        DrawNumberGlyphString(numberText, fieldBounds.left, fieldBounds.top, 1);

#undef DRAW_GROUPED_VALUE
#undef DRAW_STATUS_BAR
}

// UID:0004TL | by-memory/0x005bbe20-0x005bbe5b.UserStatusPane2InvalidateStatusFieldRect.md | Completion:91 | Confidence:93
void UserStatusPane2::InvalidateStatusFieldRect(int fieldId)
{
    RectBounds bounds;
    GetStatusFieldRect(fieldId, &bounds);
    InvalidateRect(&bounds);
}

// UID:0004TM | by-memory/0x005bbe60-0x005bc008.UserStatusPane2GetStatusFieldRect.md | Completion:92 | Confidence:94
void UserStatusPane2::GetStatusFieldRect(int fieldId, RectBounds *bounds) const
{
    switch (fieldId)
    {
    case 0: InitRectBounds(bounds, 0, 0, 126, 16); break;
    case 1: InitRectBounds(bounds, 0, 19, 126, 35); break;
    case 2: InitRectBounds(bounds, 3, 57, 123, 73); break;
    case 3: InitRectBounds(bounds, 3, 38, 123, 54); break;
    case 4: InitRectBounds(bounds, 3, 0, 123, 16); break;
    case 5: InitRectBounds(bounds, 3, 19, 123, 35); break;
    case 6: InitRectBounds(bounds, 32, 79, 117, 92); break;
    case 7: InitRectBounds(bounds, 32, 79, 59, 92); break;
    case 8: InitRectBounds(bounds, 90, 79, 117, 92); break;
    default: InitRectBounds(bounds, 0, 0, 0, 0); break;
    }
}

// UID:0004TN | by-memory/0x005bc010-0x005bc0e1.UserStatusPane2DrawNumberGlyphString.md | Completion:92 | Confidence:94
void UserStatusPane2::DrawNumberGlyphString(
    const wchar_t *text, int x, int y, int glyphRow)
{
    RectBounds sourceBounds;
    InitRectBounds(&sourceBounds, 0, 0, 9, 11);

    for (const wchar_t *scan = text; *scan != L'\0'; ++scan, x += 9)
    {
        if (*scan == L' ' || *scan == L'/')
            continue;

        RectBounds destinationBounds;
        InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);
        const int glyphIndex = static_cast<int>(*scan) + glyphRow * 10 - 47;
        RenderTileFrame(m_numberGlyphs, glyphIndex,
                        &sourceBounds, &destinationBounds, true);
    }
}

// UID:0004TO | by-memory/0x005bc0f0-0x005bc177.UserStatusPane2ApplyLegacyPositionPacket.md | Completion:91 | Confidence:92
bool UserStatusPane2::ApplyLegacyPositionPacket(const unsigned char *packet)
{
    const int positionX = ReadPacketInt16BE(packet + 1);
    const int positionY = ReadPacketInt16BE(packet + 3);
    if (m_positionX != positionX || m_positionY != positionY)
    {
        m_positionX = positionX;
        m_positionY = positionY;
        InvalidateStatusFieldRect(6);
    }
    return false;
}

// UID:0004TP | by-memory/0x005bc180-0x005bc2cc.UserStatusPane2ApplyLegacyMovementStep.md | Completion:91 | Confidence:92
bool UserStatusPane2::ApplyLegacyMovementStep(const unsigned char *packet)
{
    signed char direction = static_cast<signed char>(packet[1]);
    int positionX = ReadPacketInt16BE(packet + 2);
    int positionY = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (g_activeMapPane->AllowsMovementStatusTag() &&
        g_pConfig->m_mapMovementStatusOption == 1)
    {
        if (direction >= 0)
            return false;
        direction = static_cast<signed char>(direction & 0x7f);
    }

    RectBounds movementBounds;
    if (direction == 4)
        return false;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);
    switch (direction)
    {
    case 0:
        if (--positionY < movementBounds.top) positionY = movementBounds.top;
        break;
    case 1:
        if (++positionX >= movementBounds.right) positionX = movementBounds.right - 1;
        break;
    case 2:
        if (++positionY >= movementBounds.bottom) positionY = movementBounds.bottom - 1;
        break;
    case 3:
        if (--positionX < movementBounds.left) positionX = movementBounds.left;
        break;
    default:
        break;
    }

    if (m_positionX != positionX || m_positionY != positionY)
    {
        m_positionX = positionX;
        m_positionY = positionY;
        InvalidateStatusFieldRect(6);
    }
    return false;
}

// UID:0004TQ | by-memory/0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt.md | Completion:91 | Confidence:92
bool UserStatusPane2::ApplyLegacyMovementStepAlt(const unsigned char *packet)
{
    signed char direction = static_cast<signed char>(packet[1]);
    int positionX = ReadPacketInt16BE(packet + 2);
    int positionY = ReadPacketInt16BE(packet + 4);
    (void)packet[10];

    if (g_activeMapPane->AllowsMovementStatusTag() &&
        g_pConfig->m_mapMovementStatusOption == 1)
    {
        if (direction >= 0)
            return false;
        direction = static_cast<signed char>(direction & 0x7f);
    }

    RectBounds movementBounds;
    if (direction == 4)
        return false;
    GetLegacyMovementBounds(g_activeMapPane, &movementBounds);
    switch (direction)
    {
    case 0:
        if (--positionY < movementBounds.top) positionY = movementBounds.top;
        break;
    case 1:
        if (++positionX >= movementBounds.right) positionX = movementBounds.right - 1;
        break;
    case 2:
        if (++positionY >= movementBounds.bottom) positionY = movementBounds.bottom - 1;
        break;
    case 3:
        if (--positionX < movementBounds.left) positionX = movementBounds.left;
        break;
    default:
        break;
    }

    if (m_positionX != positionX || m_positionY != positionY)
    {
        m_positionX = positionX;
        m_positionY = positionY;
        InvalidateStatusFieldRect(6);
    }
    return false;
}

// UID:0004TR | by-memory/0x005bc420-0x005bc60c.UserStatusPane2ApplyStatusPayload.md | Completion:92 | Confidence:94
bool UserStatusPane2::ApplyStatusPayload(const unsigned char *packet)
{
    const unsigned char flags = packet[1];
    unsigned int cursor = 2;

    if ((flags & 0x40) != 0)
    {
        const unsigned int row0Full = PacketBufferReadUInt32BE(packet + 7);
        const unsigned int row1Full = PacketBufferReadUInt32BE(packet + 11);
        cursor = 31;
        if (m_statusRow0FullValue != row0Full)
        {
            m_statusRow0FullValue = row0Full;
            InvalidateStatusFieldRect(0);
        }
        if (m_statusRow1FullValue != row1Full)
        {
            m_statusRow1FullValue = row1Full;
            InvalidateStatusFieldRect(1);
        }
    }

    if ((flags & 0x20) != 0)
    {
        const unsigned int row0Partial = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        const unsigned int row1Partial = PacketBufferReadUInt32BE(packet + cursor);
        cursor += 4;
        if (m_statusRow0PartialValue != row0Partial)
        {
            m_statusRow0PartialValue = row0Partial;
            InvalidateStatusFieldRect(0);
        }
        if (m_statusRow1PartialValue != row1Partial)
        {
            m_statusRow1PartialValue = row1Partial;
            InvalidateStatusFieldRect(1);
        }
    }

    if ((flags & 0x10) != 0)
    {
        const unsigned int row2Value = PacketBufferReadUInt32BE(packet + cursor);
        const unsigned int row3Value = PacketBufferReadUInt32BE(packet + cursor + 4);
        m_statusRow2Percent = packet[cursor + 8];
        if (m_statusRow2Value != row2Value)
        {
            m_statusRow2Value = row2Value;
            InvalidateStatusFieldRect(2);
        }
        if (m_statusRow3Value != row3Value)
        {
            m_statusRow3Value = row3Value;
            InvalidateStatusFieldRect(3);
        }
    }
    return false;
}

// UID:0002Z0 | by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md | Completion:91 | Confidence:94
// Covered by UserStatusPane2's virtual declarations and compiler-generated ABI data.

// UID:0000PS | by-global/g_activeUserStatusPane.md | Completion:92 | Confidence:94
UserStatusPane *g_activeUserStatusPane = NULL;

// UID:0000RV | by-global/g_pOldUserStatusPane.md | Completion:86 | Confidence:90
OldUserStatusPane *g_pOldUserStatusPane = NULL;

// UID:0000SN | by-global/g_pUserStatusPane2.md | Completion:86 | Confidence:89
UserStatusPane2 *g_pUserStatusPane2 = NULL;

// UID:0003JC | by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md | Completion:88 | Confidence:93
// Status HUD resource filenames and numeric format literals are emitted at their source-use sites
// in UserStatusPane, UserStatusPane2, and OldUserStatusPane paint/update bodies. Do not create
// standalone storage or a duplicate raw .rdata definition for this literal run.
