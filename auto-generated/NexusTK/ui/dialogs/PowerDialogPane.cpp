// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MO
// Source by-file doc: by-file/PowerDialogPane.md
// UID:0000S0 | by-global/g_pPowerDialog.md | Completion:92 | Confidence:94
PowerDialogPane *g_pPowerDialog = NULL;

// UID:0000AP | by-class/PowerDialogPane.md | Completion:92 | Confidence:94
class Event;
class PowerDialogPane;
extern PowerDialogPane *g_pPowerDialog;

class PowerDialogPane : public DialogPane
{
public:
    explicit PowerDialogPane(const unsigned char *packet);
    virtual ~PowerDialogPane();

    static PowerDialogPane *GetSingleton();

    virtual void OnControlCommand(int actionId, int actionParam);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    void ApplyPowerSlot(int slot);
    void RefreshPowerEntriesFromPacket(const unsigned char *packet);

    int m_encodedPowerValues[5];
    int m_powerGrid[5][5];
};

// UID:0000AQ | by-class/PowerListPane.md | Completion:92 | Confidence:94
class MouseEvent;
struct PowerEntryRecord;
struct RectBounds;

class PowerListPane : public ListPane
{
public:
    PowerListPane(int entrySize, int listWidth);
    virtual ~PowerListPane();

protected:
    virtual bool OnMouseEvent(MouseEvent *event);
    virtual void DrawListItem(int rowIndex,
                              const PowerEntryRecord *entry,
                              const RectBounds *rowBounds);

private:
    void FillColorRect(const RectBounds *bounds, int palettePage, int colorIndex);
};

// UID:0001F5 | by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md | Completion:89 | Confidence:90
namespace {

constexpr int kPowerDialogControlFocusId = 6;
constexpr int kPowerFirstListControlId = 7;
constexpr int kPowerListCount = 4;
constexpr int kPowerThresholdCount = 4;
constexpr int kPowerRowCount = 5;
constexpr int kPowerGridColumnCount = 5;
constexpr int kPowerFallbackRow = 4;
constexpr int kPowerEncodedBase = 52;
constexpr int kPowerEncodedScale = 8;
constexpr int kPowerEntryRecordSize = 528;
constexpr int kPowerListWidth = 100;
constexpr int kPowerTextColor = 143;

struct PowerButtonLayout {
    int left;
    int top;
    int right;
    int bottom;
    int imageId;
};

const PowerButtonLayout kPowerButtonLayout[] = {
    {47, 307, 110, 331, 43},
    {120, 307, 183, 331, 38},
    {193, 307, 256, 331, 39},
    {266, 307, 329, 331, 40},
    {339, 307, 402, 331, 41},
    {412, 307, 475, 331, 42},
    {485, 307, 548, 331, 30},
};

struct PowerEntryRecord {
    unsigned int entryId;
    unsigned char listColumn;
    unsigned int amount;
    wchar_t label[256];
    int displayColor;
};

int EncodePowerThreshold(int value)
{
    return value * kPowerEncodedScale + kPowerEncodedBase;
}

int DecodePowerThreshold(int encodedValue)
{
    return (encodedValue - kPowerEncodedBase) / kPowerEncodedScale;
}

PowerListPane *GetPowerListPane(PowerDialogPane *dialog, int controlId)
{
    ScrollableControlPane *scrollPane =
        static_cast<ScrollableControlPane *>(dialog->GetControl(controlId));
    return static_cast<PowerListPane *>(scrollPane->GetScrollablePane());
}

void AddPowerButton(PowerDialogPane *dialog, const PowerButtonLayout &layout)
{
    RectBounds bounds = MakeRect(layout.left,
                                 layout.top,
                                 layout.right,
                                 layout.bottom);
    dialog->AddControl(new ImageButtonControlPane(layout.imageId, bounds));
}

} // namespace

static int __cdecl ComparePowerEntries(const void *leftEntry,
                                       const void *rightEntry);

PowerDialogPane::PowerDialogPane(const unsigned char *packet)
    : DialogPane(L"Power", -1, 1)
{
    for (int i = 0; i < sizeof(kPowerButtonLayout) / sizeof(kPowerButtonLayout[0]); ++i) {
        AddPowerButton(this, kPowerButtonLayout[i]);
    }

    for (int left = 61; left < 501; left += 110) {
        PowerListPane *listPane =
            new PowerListPane(kPowerEntryRecordSize, kPowerListWidth);
        RectBounds listBounds = MakeRect(left, 99, left + 109, 219);
        AddControl(new ScrollableControlPane(listBounds, listPane, 0, 0, 0));
    }

    for (int i = 0; i < kPowerThresholdCount; ++i) {
        m_encodedPowerValues[i] =
            EncodePowerThreshold(g_pConfig->m_powerDialogThresholdDefaults[i]);
    }
    m_encodedPowerValues[kPowerFallbackRow] = kPowerEncodedBase;

    TextEditControlPane *lastThresholdEdit = NULL;
    for (int row = 0; row < kPowerRowCount; ++row) {
        wchar_t thresholdText[10];
        swprintf(thresholdText,
                 L"%d",
                 DecodePowerThreshold(m_encodedPowerValues[row]));

        const int top = 221 + row * 15;
        RectBounds editBounds = MakeRect(36, top, 61, top + 14);
        lastThresholdEdit =
            new TextEditControlPane(thresholdText,
                                    true,
                                    kPowerTextColor,
                                    0,
                                    &editBounds,
                                    false,
                                    false,
                                    false,
                                    false,
                                    1.0f,
                                    0);
        AddControl(lastThresholdEdit);
    }

    if (lastThresholdEdit != NULL)
        lastThresholdEdit->SetControlVisible(true);

    memset(m_powerGrid, 0, sizeof(m_powerGrid));

    unsigned int packetOffset = 4;
    const unsigned int entryCount = ReadUInt16BE(packet + 2);
    for (unsigned int i = 0; i < entryCount; ++i) {
        PowerEntryRecord record;
        memset(&record, 0, sizeof(record));

        record.entryId = ReadUInt32BE(packet + packetOffset);
        packetOffset += 4;

        record.listColumn = packet[packetOffset++];

        record.amount = ReadUInt32BE(packet + packetOffset);
        packetOffset += 4;

        const unsigned char thresholdValue = packet[packetOffset++];
        record.displayColor = EncodePowerThreshold(thresholdValue);

        const unsigned char labelLength = packet[packetOffset++];
        char labelText[256];
        memcpy(labelText, packet + packetOffset, labelLength);
        labelText[labelLength] = 0;
        packetOffset += labelLength;

        const int converted =
            MultiByteToWideChar(0,
                                0,
                                labelText,
                                labelLength,
                                record.label,
                                256);
        record.label[converted] = 0;

        PowerListPane *listPane =
            GetPowerListPane(this, record.listColumn + kPowerDialogControlFocusId);
        listPane->AddEntry(&record);

        int rowIndex = kPowerFallbackRow;
        for (int row = 0; row < kPowerRowCount; ++row) {
            if (thresholdValue == DecodePowerThreshold(m_encodedPowerValues[row])) {
                rowIndex = row;
                break;
            }
        }

        m_powerGrid[rowIndex][record.listColumn - 1] += record.amount;
    }

    for (int row = 0; row < kPowerRowCount; ++row) {
        m_powerGrid[row][4] = m_powerGrid[row][0]
                            + m_powerGrid[row][1]
                            + m_powerGrid[row][2]
                            + m_powerGrid[row][3];
    }

    for (int i = 0; i < kPowerListCount; ++i) {
        PowerListPane *listPane =
            GetPowerListPane(this, kPowerFirstListControlId + i);
        listPane->Sort(ComparePowerEntries);
    }

    SetHoverControl(kPowerDialogControlFocusId);
    SetFocusedControl(kPowerDialogControlFocusId);
    SetPendingControl(kPowerDialogControlFocusId);

    RectBounds dialogBounds = MakeRect(20, 20, 626, 391);
    SetMode(1);
    OnCreate(&dialogBounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();

    g_pPowerDialog = this;
}

// UID:0001F7 | by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md | Completion:90 | Confidence:93
PowerDialogPane::~PowerDialogPane()
{
    g_pPowerDialog = 0;
}

PowerDialogPane *PowerDialogPane::GetSingleton()
{
    return g_pPowerDialog;
}

// UID:0004AX | by-memory/0x0054a4c0-0x0054a69d.PowerDialogPaneOnControlCommand.md | Completion:92 | Confidence:94
void PowerDialogPane::OnControlCommand(int actionId, int actionParam)
{
    (void)actionParam;

    switch (actionId) {
    case 0: {
        unsigned char packet[256];
        int packetLength = 0;

        for (int i = 0; i < kPowerThresholdCount; ++i) {
            wchar_t thresholdText[10];
            TextEditControlPane *thresholdEdit =
                static_cast<TextEditControlPane *>(GetControl(11 + i));

            thresholdEdit->ReadText(thresholdText, 10);

            const short thresholdValue =
                static_cast<short>(_wtol(thresholdText));
            m_encodedPowerValues[i] = EncodePowerThreshold(thresholdValue);
            g_pConfig->m_powerDialogThresholdDefaults[i] = thresholdValue;
        }

        PacketBufferWriteUInt8(0x4c, packet + packetLength++);
        PacketBufferWriteUInt8(1, packet + packetLength++);
        PacketBufferWriteUInt8(kPowerThresholdCount, packet + packetLength++);

        for (int i = 0; i < kPowerThresholdCount; ++i) {
            PacketBufferWriteUInt8(
                DecodePowerThreshold(m_encodedPowerValues[i]),
                packet + packetLength++);
        }

        packet[packetLength] = 0;
        g_packetSender->QueueAndSendPacket(
            packet,
            static_cast<short>(packetLength));
        return;
    }

    case 1:
        ApplyPowerSlot(1);
        return;

    case 2:
        ApplyPowerSlot(2);
        return;

    case 3:
        ApplyPowerSlot(3);
        return;

    case 4:
        ApplyPowerSlot(4);
        return;

    case 5:
        ApplyPowerSlot(5);
        return;

    case 6:
        SlideCloseVertical();
        CloseDialog();
        return;

    default:
        return;
    }
}

// UID:0004AY | by-memory/0x0054a6c0-0x0054a6e6.PowerDialogPaneHandlePacketEvent.md | Completion:92 | Confidence:94
bool PowerDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] != 0x46)
        return false;

    RefreshPowerEntriesFromPacket(packet);
    return true;
}

// UID:0004AZ | by-memory/0x0054a6f0-0x0054a7e9.PowerDialogPaneOnPaint.md | Completion:90 | Confidence:91
void PowerDialogPane::OnPaint()
{
    EPFTileContext tileContext;
    tileContext.Init();

    g_pEPFLib->LookupLayoutEntry(L"POWER.EPF", 0, &tileContext);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &m_bounds,
                    1,
                    0,
                    0);

    SetTextColor(kPowerTextColor);
    m_textDrawMode = 1;

    for (int row = 0; row < kPowerRowCount; ++row) {
        const int y = 234 + row * 15;

        for (int column = 0; column < kPowerGridColumnCount; ++column) {
            wchar_t gridText[32];
            swprintf(gridText, L"%d", m_powerGrid[row][column]);

            MoveTo(62 + column * 110, y);
            DrawWideText(gridText, wcslen(gridText));
        }
    }
}

// UID:0004B0 | by-memory/0x0054a7f0-0x0054a954.PowerDialogPaneApplyPowerSlot.md | Completion:90 | Confidence:91
void PowerDialogPane::ApplyPowerSlot(int slot)
{
    PowerEntryRecord *selectedEntry = NULL;
    int selectedDisplayColor = 0;

    for (int i = 0; i < kPowerListCount; ++i) {
        PowerListPane *listPane =
            GetPowerListPane(this, kPowerFirstListControlId + i);
        const int selectedIndex = listPane->GetSelectedIndex();
        if (selectedIndex == -1)
            continue;

        selectedEntry =
            static_cast<PowerEntryRecord *>(listPane->GetItem(selectedIndex));
        selectedDisplayColor = m_encodedPowerValues[slot - 1];
        selectedEntry->displayColor = selectedDisplayColor;
        break;
    }

    if (selectedEntry == NULL)
        return;

    unsigned char packet[256];
    int packetLength = 0;

    PacketBufferWriteUInt8(0x4c, packet + packetLength++);
    PacketBufferWriteUInt8(2, packet + packetLength++);
    PacketBufferWriteUInt8(kPowerThresholdCount, packet + packetLength++);

    for (int i = 0; i < kPowerThresholdCount; ++i) {
        PacketBufferWriteUInt8(
            DecodePowerThreshold(m_encodedPowerValues[i]),
            packet + packetLength++);
    }

    PacketBufferWriteUInt32BE(selectedEntry->entryId, packet + packetLength);
    packetLength += 4;

    PacketBufferWriteUInt8(DecodePowerThreshold(selectedDisplayColor),
                           packet + packetLength++);

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(
        packet,
        static_cast<short>(packetLength));
}

// UID:0004B3 | by-memory/0x0054ab90-0x0054aebb.PowerDialogPaneRefreshPowerEntriesFromPacket.md | Completion:88 | Confidence:91
void PowerDialogPane::RefreshPowerEntriesFromPacket(const unsigned char *packet)
{
    for (int i = 0; i < kPowerListCount; ++i) {
        PowerListPane *listPane =
            GetPowerListPane(this, kPowerFirstListControlId + i);
        listPane->RemoveItems(0, listPane->GetItemCount());
    }

    memset(m_powerGrid, 0, sizeof(m_powerGrid));

    unsigned int packetOffset = 4;
    unsigned int entryCount = PacketBufferReadUInt16BE(packet + 2);
    while (entryCount-- != 0) {
        PowerEntryRecord record;

        record.entryId = PacketBufferReadUInt32BE(packet + packetOffset);
        packetOffset += 4;

        record.listColumn = packet[packetOffset++];

        record.amount = PacketBufferReadUInt32BE(packet + packetOffset);
        packetOffset += 4;

        const unsigned char thresholdValue = packet[packetOffset++];
        record.displayColor = EncodePowerThreshold(thresholdValue);

        const unsigned int labelLength = packet[packetOffset++];
        char labelText[256];
        memcpy(labelText, packet + packetOffset, labelLength);
        labelText[labelLength] = 0;
        packetOffset += labelLength;

        const int convertedLength =
            MultiByteToWideChar(0,
                                0,
                                labelText,
                                static_cast<int>(labelLength),
                                record.label,
                                256);
        record.label[convertedLength] = 0;

        PowerListPane *listPane =
            GetPowerListPane(this,
                             record.listColumn + kPowerDialogControlFocusId);
        listPane->AddEntry(&record);

        int rowIndex = kPowerFallbackRow;
        for (int row = 0; row < kPowerRowCount; ++row) {
            if (thresholdValue == DecodePowerThreshold(m_encodedPowerValues[row])) {
                rowIndex = row;
                break;
            }
        }

        m_powerGrid[rowIndex][record.listColumn - 1] += record.amount;
    }

    for (int row = 0; row < kPowerRowCount; ++row) {
        int total = 0;
        for (int column = 0; column < kPowerListCount; ++column)
            total += m_powerGrid[row][column];

        m_powerGrid[row][kPowerListCount] = total;
    }

    for (int i = 0; i < kPowerListCount; ++i) {
        PowerListPane *listPane =
            GetPowerListPane(this, kPowerFirstListControlId + i);
        listPane->Sort(ComparePowerEntries);
    }

    InvalidateRect(&m_bounds);
}

// UID:0004RQ | by-memory/0x0054aec0-0x0054af02.PowerListPaneConstructor.md | Completion:92 | Confidence:94
PowerListPane::PowerListPane(int entrySize, int listWidth)
    : ListPane(entrySize,
               listWidth,
               96,
               12,
               false,
               true,
               true)
{
}

// UID:0004B4 | by-memory/0x0054af10-0x0054af2f.PowerListPaneDestructorBody.md | Completion:92 | Confidence:94
PowerListPane::~PowerListPane()
{
}

// UID:0004B5 | by-memory/0x0054af30-0x0054afd5.PowerDialogPaneComparePowerEntries.md | Completion:89 | Confidence:91
static int __cdecl ComparePowerEntries(const void *leftEntry,
                                       const void *rightEntry)
{
    const PowerEntryRecord *left =
        static_cast<const PowerEntryRecord *>(leftEntry);
    const PowerEntryRecord *right =
        static_cast<const PowerEntryRecord *>(rightEntry);

    const int leftThreshold =
        (left->displayColor - kPowerEncodedBase) / kPowerEncodedScale;
    int leftBucket = left->displayColor == kPowerEncodedBase ? 1 : 2;
    for (int i = 0; i < kPowerThresholdCount; ++i) {
        if (g_pConfig->m_powerDialogThresholdDefaults[i] == leftThreshold) {
            leftBucket = i + 3;
            break;
        }
    }

    const int rightThreshold =
        (right->displayColor - kPowerEncodedBase) / kPowerEncodedScale;
    int rightBucket = right->displayColor == kPowerEncodedBase ? 1 : 2;
    for (int i = 0; i < kPowerThresholdCount; ++i) {
        if (g_pConfig->m_powerDialogThresholdDefaults[i] == rightThreshold) {
            rightBucket = i + 3;
            break;
        }
    }

    const int bucketDelta = leftBucket - rightBucket;
    if (bucketDelta != 0)
        return bucketDelta;

    return static_cast<int>(right->amount) - static_cast<int>(left->amount);
}

// UID:0004B6 | by-memory/0x0054b000-0x0054b210.PowerListPaneOnMouseEvent.md | Completion:90 | Confidence:91
bool PowerListPane::OnMouseEvent(MouseEvent *event)
{
    const int x = event->x;
    const int y = event->y;

    switch (event->type) {
    case MouseEvent::Move:
        if (!m_isDraggingSelection) {
            Invalidate(&m_bounds);
            return false;
        }
        {
            const int itemIndex = HitTestItem(x, y);
            if (itemIndex != -1) {
                SetSelectedItem(itemIndex, false);
                EnsureItemVisible(itemIndex);
            }
        }
        return true;

    case MouseEvent::LeftButtonDown:
        if (m_isDraggingSelection || !PointInRect(x, y, m_listHitRect)) {
            Invalidate(&m_bounds);
            return false;
        }
        {
            const int itemIndex = HitTestItem(x, y);
            if (itemIndex == -1) {
                Invalidate(&m_bounds);
                return false;
            }

            for (int i = 0; i < kPowerListCount; ++i) {
                PowerListPane *listPane =
                    GetPowerListPane(g_pPowerDialog,
                                     kPowerFirstListControlId + i);
                listPane->SetSelectedItem(-1, false);

                RectBounds bounds;
                listPane->GetBounds(&bounds);
                listPane->Invalidate(&bounds);
            }

            SetSelectedItem(itemIndex, false);
            m_isDraggingSelection = true;
            g_pEventMan->CaptureMouse();
        }
        return true;

    case MouseEvent::LeftButtonDoubleClick:
        if (!PointInRect(x, y, m_listHitRect)) {
            Invalidate(&m_bounds);
            return false;
        }
        {
            const int itemIndex = HitTestItem(x, y);
            if (itemIndex == -1) {
                Invalidate(&m_bounds);
                return false;
            }
            SetSelectedItem(itemIndex, false);
            OnSelectedItemDoubleClick();
        }
        return true;

    case MouseEvent::LeftButtonUp:
        if (!m_isDraggingSelection) {
            Invalidate(&m_bounds);
            return false;
        }
        if (PointInRect(x, y, m_listHitRect)) {
            const int itemIndex = HitTestItem(x, y);
            if (itemIndex != -1) {
                SetSelectedItem(itemIndex, false);
                EnsureItemVisible(itemIndex);
            }
        }
        m_isDraggingSelection = false;
        g_pEventMan->ReleaseMouse();
        return true;

    default:
        return false;
    }
}

// UID:0004B7 | by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md | Completion:88 | Confidence:91
void PowerListPane::DrawListItem(int rowIndex,
                                 const PowerEntryRecord *entry,
                                 const RectBounds *rowBounds)
{
    m_textDrawEnabled = true;

    if (IsItemSelected(rowIndex)) {
        SetDrawColor(143);
        DrawRectFrame(rowBounds);
    }

    const int displayColor = entry->displayColor;
    const int palettePage = (displayColor + 4) / 256;
    RectBounds swatchBounds = MakeRect(rowBounds->left + 5,
                                       rowBounds->top + 1,
                                       rowBounds->left + 15,
                                       rowBounds->bottom - 1);

    if (palettePage != 0) {
        FillColorRect(&swatchBounds, palettePage, displayColor % 256);
    } else {
        SetDrawColor(displayColor);
        FillRect(&swatchBounds);
    }

    SetTextColor(37);
    const wchar_t *label = entry->label;
    const int labelWidth = GetTextWidth(label);
    MoveTo(rowBounds->right - labelWidth,
           ((rowBounds->top + rowBounds->bottom) / 2) + 6);
    DrawWideText(label, wcslen(label));
}

// UID:0004B8 | by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md | Completion:89 | Confidence:90
void PowerListPane::FillColorRect(const RectBounds *bounds,
                                  int palettePage,
                                  int colorIndex)
{
    if (!m_drawEnabled) {
        return;
    }

    RectBounds clipBounds;
    GetClipRect(&clipBounds);

    RectBounds fillBounds = *bounds;
    IntersectRects(&clipBounds, &fillBounds, &fillBounds);
    if (IsRectEmptyOrInvalid(&fillBounds)) {
        return;
    }

    DLPalette *palette = g_pPaletteLib->GetSlotPalette(3, 0, palettePage);
    const unsigned short fillColor =
        static_cast<unsigned short>(palette->MapColor(colorIndex));

    (void)palette->MapColor(m_textBackColor);

    if (m_drawMode != 0) {
        if (m_drawMode != 1 || m_drawColor == 0) {
            return;
        }
    }

    const int width = fillBounds.right - fillBounds.left;
    int height = fillBounds.bottom - fillBounds.top;
    unsigned short *row = m_pixelBuffer
        + (fillBounds.left - m_originX)
        + (fillBounds.top - m_originY) * m_surfaceStride;

    while (height-- > 0) {
        for (int x = 0; x < width; ++x) {
            row[x] = fillColor;
        }
        row += m_surfaceStride;
    }
}

// UID:0003CG | by-memory/0x006221f0-0x006222b4.PowerListPaneVtableData.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:0000AQ][PowerListPane](by-class/PowerListPane.md).

// UID:0003CH | by-memory\0x006222b4-0x006222d4.PowerDialogResourceStrings.md | Completion:85 | Confidence:90 | Empty Emitter Marker
