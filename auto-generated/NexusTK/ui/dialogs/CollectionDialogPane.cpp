// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IB
// Source by-file doc: by-file/CollectionDialogPane.md
// UID:00002U | by-class/CollectionBarControlPane.md | Completion:90 | Confidence:91
class CollectionBarControlPane : public ControlPane
{
public:
    CollectionBarControlPane(unsigned char groupIndex, const RectBounds *bounds);
    virtual ~CollectionBarControlPane();

protected:
    virtual void OnDraw();

private:
    void DrawProgressLabel(const wchar_t *text, int x, int y, unsigned char fontSet);

    signed char m_totalEntries;
    signed char m_collectedEntries;
    char *m_numericGlyphs;
};

// UID:0004JR | by-memory/0x0048dc30-0x0048dce0.CollectionBarControlPaneConstructor.md | Completion:90 | Confidence:92
CollectionBarControlPane::CollectionBarControlPane(unsigned char groupIndex,
                                                   const RectBounds *bounds)
    : ControlPane(8, bounds),
      m_totalEntries(0),
      m_collectedEntries(0),
      m_numericGlyphs(NULL)
{
    int glyphDataSize = 0;
    m_numericGlyphs =
        LoadDatFileBuffer(kCollectionNumericFontName, 99, &glyphDataSize);

    const CollectionGroupRecord &group =
        g_pUserPane->GetCollectionData().groups[groupIndex];
    m_totalEntries = static_cast<signed char>(group.totalEntries);
    m_collectedEntries = static_cast<signed char>(group.collectedEntries);
}

// UID:0004JT | by-memory/0x0048dce0-0x0048dd53.CollectionBarControlPaneDestructor.md | Completion:90 | Confidence:92
CollectionBarControlPane::~CollectionBarControlPane()
{
    if (m_numericGlyphs != NULL) {
        m_numericGlyphs = static_cast<char *>(
            GetMemoryMan()->FreeBufferMemory(m_numericGlyphs));
    }
}

// UID:0004JU | by-memory/0x0048dd60-0x0048dfec.CollectionBarControlPaneOnDraw.md | Completion:90 | Confidence:91
void CollectionBarControlPane::OnDraw()
{
    EPFTileContext leftFrame;
    EPFTileContext fillFrame;
    EPFTileContext rightFrame;
    g_pEPFLib->LoadFrame(kCollectionBarEpfName, 0, &leftFrame);
    g_pEPFLib->LoadFrame(kCollectionBarEpfName, 1, &fillFrame);
    g_pEPFLib->LoadFrame(kCollectionBarEpfName, 2, &rightFrame);

    RectBounds barBounds = m_bounds;
    barBounds.left += 3;
    barBounds.right -= 3;

    if (m_collectedEntries > 0) {
        int fillRight = barBounds.right;
        if (m_collectedEntries < m_totalEntries) {
            fillRight = barBounds.left +
                MulDiv(barBounds.right - barBounds.left,
                       m_collectedEntries, m_totalEntries);
        }

        RectBounds leftBounds = barBounds;
        leftBounds.left = barBounds.left - 3;
        leftBounds.right = barBounds.left;
        RenderTileFrame(&leftFrame, &leftFrame.m_bounds, &leftBounds, 1,
                        kCollectionBarPaletteName, NULL);

        RectBounds fillBounds = barBounds;
        fillBounds.right = fillRight;
        RenderTileFrame(&fillFrame, &fillFrame.m_bounds, &fillBounds, 0,
                        kCollectionBarPaletteName, NULL);

        RectBounds rightBounds = barBounds;
        rightBounds.left = fillRight;
        rightBounds.right = fillRight + 3;
        RenderTileFrame(&rightFrame, &rightFrame.m_bounds, &rightBounds, 1,
                        kCollectionBarPaletteName, NULL);
    }

    wchar_t progressText[128];
    swprintf_s(progressText, 128, kCollectionProgressTextFormat,
               m_collectedEntries, m_totalEntries,
               100 * m_collectedEntries / m_totalEntries);
    SetTextColor(128);

    const int x = (barBounds.right - barBounds.left -
                   6 * static_cast<int>(wcslen(progressText))) / 2;
    DrawProgressLabel(progressText, x, barBounds.top + 5, 2);
}

// UID:0004JV | by-memory/0x0048dff0-0x0048e133.CollectionBarControlPaneDrawProgressLabel.md | Completion:90 | Confidence:91
void CollectionBarControlPane::DrawProgressLabel(const wchar_t *text,
                                                 int x,
                                                 int y,
                                                 unsigned char fontSet)
{
    RectBounds sourceBounds;
    RectBounds destinationBounds;
    InitRectBounds(&sourceBounds, 0, 0, 9, 11);
    InitRectBounds(&destinationBounds, x, y, x + 9, y + 11);

    for (const wchar_t *cursor = text; *cursor != 0; ++cursor) {
        int symbolFrame = -1;
        switch (*cursor) {
        case L'/': symbolFrame = 0; break;
        case L'%': symbolFrame = 1; break;
        case L'(': symbolFrame = 2; break;
        case L')': symbolFrame = 3; break;
        }

        if (symbolFrame >= 0) {
            EPFTileContext symbol;
            g_pEPFLib->LoadFrame(kCollectionSymbolFontEpfName, symbolFrame, &symbol);
            RenderTileFrame(&symbol, &symbol.m_bounds, &destinationBounds, 1,
                            kCollectionSymbolFontPaletteName, NULL);
        } else if (*cursor != L' ') {
            const int glyphIndex = *cursor + 10 * fontSet - 47;
            RenderTileFrame(m_numericGlyphs, glyphIndex, &sourceBounds,
                            &destinationBounds, true);
        }

        destinationBounds.Offset(9, 0);
    }
}

// UID:0004JY | by-memory/0x0048e190-0x0048e244.CollectionBarControlPaneScalarDeletingDestructor.md | Completion:90 | Confidence:94
// Compiler-generated MSVC scalar deleting destructor for CollectionBarControlPane.
// Reconstruct virtual ~CollectionBarControlPane() and its ordinary destructor child.
// Let the compiler regenerate vtable deleting dispatch and secondary-base adjustors,
// Pane base destruction, deleting flags, return-this ABI behavior, and storage release.
// Do not hand-author this wrapper.

// UID:00002V | by-class/CollectionDialogPane.md | Completion:90 | Confidence:92
class CollectionDialogPane : public DialogPane
{
public:
    CollectionDialogPane(const unsigned char *packet, unsigned char groupVolumeId);
    virtual ~CollectionDialogPane();

    virtual void OnControlCommand(int controlIndex, int notifyCode);

protected:
    virtual void SetHoverControl(int controlId);

private:
    signed char FindCategoryIndex() const;
    void NextPage();
    void PreviousPage();

    unsigned char m_groupVolumeId;
    signed char m_stateByteCount;
    unsigned char m_reservedState;
    signed char m_currentPage;
};

// UID:0004JE | by-memory/0x0048c640-0x0048cf75.CollectionDialogPaneConstructor.md | Completion:90 | Confidence:92
CollectionDialogPane::CollectionDialogPane(const unsigned char *packet,
                                           unsigned char groupVolumeId)
    : DialogPane(kCollectionDialogPaneName, 17, 1),
      m_groupVolumeId(groupVolumeId),
      m_stateByteCount(0),
      m_reservedState(0),
      m_currentPage(0)
{
    g_pCollectionDialogPane = this;

    unsigned char stateBytes[32] = {};
    if (packet != NULL) {
        m_groupVolumeId = packet[3];
        m_stateByteCount = static_cast<signed char>(packet[4]);
        GetMemoryMan()->MemmoveWrapper(stateBytes, packet + 5, m_stateByteCount);
        stateBytes[m_stateByteCount] = 0;
    }

    CollectionPlayerDataView &collectionData = g_pUserPane->GetCollectionData();
    const signed char groupIndex = FindCategoryIndex();
    CollectionGroupRecord &group = collectionData.groups[groupIndex];

    if (packet != NULL) {
        for (int byteIndex = 0; byteIndex < m_stateByteCount; ++byteIndex) {
            for (int bitIndex = 0; bitIndex < 8; ++bitIndex) {
                CollectionEntryRecord &entry =
                    group.entries[byteIndex * 8 + bitIndex];
                entry.collectedFlag =
                    (stateBytes[byteIndex] & (1 << bitIndex)) != 0;
            }
        }
    }

    RectBounds controlBounds;
    InitRectBounds(&controlBounds, 0, 0, 668, 468);
    AddControl(new EPFImageControlPane(kCollectionDialogEpfName, 0, true,
                                       &controlBounds,
                                       kCollectionDialogPaletteName));

    InitRectBounds(&controlBounds, 229, 409, 292, 433);
    AddControl(new ImageButtonControlPane(18, &controlBounds));
    InitRectBounds(&controlBounds, 304, 409, 367, 433);
    AddControl(new ImageButtonControlPane(14, &controlBounds));
    InitRectBounds(&controlBounds, 379, 409, 442, 433);
    AddControl(new ImageButtonControlPane(19, &controlBounds));

    InitRectBounds(&controlBounds, 75, 42, 329, 93);
    AddControl(new EPFImageControlPane(kCollectionNameEpfName,
                                       m_groupVolumeId, true,
                                       &controlBounds,
                                       kCollectionNamePaletteName));

    InitRectBounds(&controlBounds, 393, 72, 593, 92);
    AddControl(new CollectionBarControlPane(groupIndex, &controlBounds));

    for (int slot = 0; slot < 6; ++slot) {
        signed char entryIndex = static_cast<signed char>(slot + 6 * m_currentPage);
        if (entryIndex >= group.totalEntries)
            entryIndex = -2;

        const int column = slot / 3;
        const int row = slot % 3;
        InitRectBounds(&controlBounds,
                       74 + 266 * column, 102 + 100 * row,
                       329 + 266 * column, 197 + 100 * row);
        AddControl(new CollectionEntryControlPane(
            groupIndex, entryIndex, &controlBounds));
    }

    SetFocusedControl(2);
    SetPendingControl(2);
    GetChild<ImageButtonControlPane>(1)->Disable();
    if (m_currentPage >= (group.totalEntries - 1) / 6)
        GetChild<ImageButtonControlPane>(3)->Disable();

    RectBounds dialogBounds;
    InitRectBounds(&dialogBounds,
                   (g_screenWidth - 668) / 2,
                   (g_screenHeight - 468) / 2,
                   (g_screenWidth - 668) / 2 + 668,
                   (g_screenHeight - 468) / 2 + 468);
    OnCreate(&dialogBounds, 0, NULL, g_pTopMostPane);
    OnShow(NULL, g_pScreenPane);
    SlideOpenVertical();

    const signed char loadedGroupIndex = packet != NULL
        ? groupIndex
        : static_cast<signed char>(m_groupVolumeId);
    collectionData.groups[loadedGroupIndex].loadedFlag = 1;
}

// UID:0004JG | by-memory/0x0048cfb0-0x0048d17e.CollectionDialogPaneOnControlCommand.md | Completion:91 | Confidence:92
void CollectionDialogPane::OnControlCommand(int controlIndex, int /*notifyCode*/)
{
    switch (controlIndex)
    {
    case 1:
        PreviousPage();
        break;
    case 2:
        SlideCloseVertical();
        CloseDialog();
        break;
    case 3:
        NextPage();
        break;
    }
}

// UID:0004JH | by-memory/0x0048d180-0x0048d183.CollectionDialogPaneSetHoverControlNoOp.md | Completion:90 | Confidence:93
void CollectionDialogPane::SetHoverControl(int /*controlId*/)
{
}

// UID:0004JI | by-memory/0x0048d190-0x0048d1ce.CollectionDialogPaneFindCategoryIndex.md | Completion:90 | Confidence:92
signed char CollectionDialogPane::FindCategoryIndex() const
{
    const CollectionPlayerDataView &collectionData =
        g_pUserPane->GetCollectionData();

    signed char groupIndex = 0;
    while (groupIndex < collectionData.groupCount) {
        if (collectionData.groups[groupIndex].groupType == m_groupVolumeId)
            break;
        ++groupIndex;
    }
    return groupIndex;
}

// UID:0004JJ | by-memory/0x0048d1d0-0x0048d2c7.CollectionDialogPaneNextPageRaw.md | Completion:90 | Confidence:91
void CollectionDialogPane::NextPage()
{
    const signed char groupIndex = FindCategoryIndex();
    const CollectionGroupRecord &group =
        g_pUserPane->GetCollectionData().groups[groupIndex];

    ++m_currentPage;
    const int lastPage = (group.totalEntries - 1) / 6;
    if (m_currentPage > lastPage)
        m_currentPage = static_cast<signed char>(lastPage);

    for (int slot = 0; slot < 6; ++slot)
        GetChild<CollectionEntryControlPane>(slot + 6)->NextPage();

    ImageButtonControlPane *previous = GetChild<ImageButtonControlPane>(1);
    ImageButtonControlPane *next = GetChild<ImageButtonControlPane>(3);
    previous->Enable();
    next->Enable();
    if (m_currentPage <= 0)
        previous->Disable();
    if (m_currentPage >= lastPage)
        next->Disable();
}

// UID:0004JK | by-memory/0x0048d2d0-0x0048d39f.CollectionDialogPanePreviousPageRaw.md | Completion:90 | Confidence:91
void CollectionDialogPane::PreviousPage()
{
    const signed char groupIndex = FindCategoryIndex();
    const CollectionGroupRecord &group =
        g_pUserPane->GetCollectionData().groups[groupIndex];

    --m_currentPage;
    if (m_currentPage < 0)
        m_currentPage = 0;

    for (int slot = 0; slot < 6; ++slot)
        GetChild<CollectionEntryControlPane>(slot + 6)->PreviousPage();

    ImageButtonControlPane *previous = GetChild<ImageButtonControlPane>(1);
    ImageButtonControlPane *next = GetChild<ImageButtonControlPane>(3);
    previous->Enable();
    next->Enable();
    if (m_currentPage <= 0)
        previous->Disable();
    if (m_currentPage >= (group.totalEntries - 1) / 6)
        next->Disable();
}

// UID:0004JZ | by-memory/0x0048e250-0x0048e2af.CollectionDialogPaneScalarDeletingDestructor.md | Completion:90 | Confidence:93
CollectionDialogPane::~CollectionDialogPane()
{
    g_pCollectionDialogPane = NULL;
}

// UID:00002W | by-class/CollectionEntryControlPane.md | Completion:90 | Confidence:92
class CollectionEntryControlPane : public ControlPane
{
public:
    CollectionEntryControlPane(unsigned char groupIndex, signed char entryIndex, const RectBounds *bounds);
    virtual ~CollectionEntryControlPane();

    void NextPage();
    void PreviousPage();

protected:
    virtual void OnDraw();

private:
    void DrawWrappedText(const wchar_t *text, int charCount, const RectBounds *bounds);

    unsigned char m_groupIndex;
    signed char m_entryIndex;
    wchar_t m_volumeEpfName[128];
    wchar_t m_volumePaletteName[128];
};

// UID:0004JL | by-memory/0x0048d3a0-0x0048d47b.CollectionEntryControlPaneConstructor.md | Completion:90 | Confidence:92
CollectionEntryControlPane::CollectionEntryControlPane(unsigned char groupIndex,
                                                       signed char entryIndex,
                                                       const RectBounds *bounds)
    : ControlPane(8, bounds),
      m_groupIndex(groupIndex),
      m_entryIndex(entryIndex)
{
    SetDrawEnabled(true);
    const CollectionGroupRecord &group =
        g_pUserPane->GetCollectionData().groups[groupIndex];
    swprintf_s(m_volumeEpfName, 128,
               kCollectionVolumeEpfFormat, group.groupType);
    swprintf_s(m_volumePaletteName, 128,
               kCollectionVolumePaletteFormat, group.groupType);
}

// UID:00010Y | by-memory/0x0048d480-0x0048d49f.CollectionEntryControlPaneDestructor.md | Completion:89 | Confidence:91
CollectionEntryControlPane::~CollectionEntryControlPane()
{
}

// UID:0004JM | by-memory/0x0048d4a0-0x0048d992.CollectionEntryControlPaneOnDraw.md | Completion:90 | Confidence:91
void CollectionEntryControlPane::OnDraw()
{
    EPFTileContext frame;
    wchar_t unknownText[128];
    wchar_t entryNumber[128];
    swprintf_s(unknownText, 128, L"%s", kCollectionUnknownEntryText);
    swprintf_s(entryNumber, 128, kCollectionEntryNumberFormat, m_entryIndex + 1);

    g_pEPFLib->LoadFrame(kCollectionEntryEpfName, 0, &frame);
    RenderTileFrame(&frame, &frame.m_bounds, &m_bounds, 0,
                    kCollectionEntryPaletteName, NULL);

    RectBounds iconBounds;
    InitRectBounds(&iconBounds, 0, 0, 95, 95);
    const CollectionGroupRecord &group =
        g_pUserPane->GetCollectionData().groups[m_groupIndex];

    if (m_entryIndex == -2 || m_entryIndex >= group.totalEntries) {
        g_pEPFLib->LoadFrame(kCollectionIconEpfName, 1, &frame);
        RenderTileFrame(&frame, &frame.m_bounds, &iconBounds, 0,
                        kCollectionIconPaletteName, NULL);
        return;
    }

    const CollectionEntryRecord &entry = group.entries[m_entryIndex];
    if (entry.collectedFlag == 0) {
        g_pEPFLib->LoadFrame(kCollectionIconEpfName, 0, &frame);
        RenderTileFrame(&frame, &frame.m_bounds, &iconBounds, 0,
                        kCollectionIconPaletteName, NULL);

        RectBounds textBounds = iconBounds;
        textBounds.top += 6;
        textBounds.bottom = textBounds.top + 12;
        textBounds.left += 102;
        textBounds.right = textBounds.left + 146;
        SetTextColor(143);
        DrawWrappedText(unknownText, (textBounds.right - textBounds.left) / 6 - 2,
                        &textBounds);

        RectBounds numberBounds = textBounds;
        numberBounds.left = textBounds.right - 13;
        DrawWrappedText(entryNumber, 2, &numberBounds);
        numberBounds.Offset(-1, 0);
        DrawWrappedText(entryNumber, 2, &numberBounds);

        textBounds.Offset(0, 23);
        DrawWrappedText(unknownText, (textBounds.right - (textBounds.left + 56)) / 12,
                        &textBounds);
        return;
    }

    g_pEPFLib->LoadFrame(m_volumeEpfName, m_entryIndex, &frame);
    RenderTileFrame(&frame, &frame.m_bounds, &iconBounds, 0,
                    m_volumePaletteName, NULL);

    RectBounds textBounds = iconBounds;
    textBounds.top += 6;
    textBounds.bottom = textBounds.top + 12;
    textBounds.left += 102;
    textBounds.right = textBounds.left + 146;
    SetTextColor(143);
    DrawWrappedText(entry.entryName.CStr(), entry.entryName.Length(), &textBounds);

    RectBounds numberBounds = textBounds;
    numberBounds.left = textBounds.right - 13;
    DrawWrappedText(entryNumber, 2, &numberBounds);
    numberBounds.Offset(-1, 0);
    DrawWrappedText(entryNumber, 2, &numberBounds);

    textBounds.Offset(0, 24);
    textBounds.left = textBounds.right - 6 * entry.shortName.Length() - 2;
    DrawWrappedText(entry.shortName.CStr(), entry.shortName.Length(), &textBounds);

    SetTextColor(128);
    iconBounds.Offset(0, 49);
    DrawWrappedText(entry.description.CStr(), entry.description.Length(), &iconBounds);
}

// UID:0004JO | by-memory/0x0048d9a0-0x0048d9b1.CollectionEntryControlPanePreviousPageRaw.md | Completion:89 | Confidence:91
void CollectionEntryControlPane::PreviousPage()
{
    m_entryIndex -= 6;
    InvalidateBounds();
}

// UID:0004JP | by-memory/0x0048d9c0-0x0048d9d1.CollectionEntryControlPaneNextPageRaw.md | Completion:89 | Confidence:91
void CollectionEntryControlPane::NextPage()
{
    m_entryIndex += 6;
    InvalidateBounds();
}

// UID:0004JQ | by-memory/0x0048d9e0-0x0048dc22.CollectionEntryControlPaneDrawWrappedText.md | Completion:90 | Confidence:92
void CollectionEntryControlPane::DrawWrappedText(const wchar_t *text,
                                                 int charCount,
                                                 const RectBounds *bounds)
{
    if (!m_drawEnabled)
        return;

    int savedPosition[2];
    GetDrawPosition(savedPosition);
    MoveTo(bounds->left, bounds->top);

    const int lineHeight = GetLineHeight();
    int consumed = 0;
    while (consumed < charCount && m_currentY <= bounds->bottom) {
        int lineLength = CountCharsFittingWidth(text + consumed,
                                               bounds->right - bounds->left);
        if (consumed + lineLength > charCount)
            lineLength = charCount - consumed;

        wchar_t line[128];
        GetMemoryMan()->MemmoveWrapper(
            line, text + consumed, lineLength * sizeof(wchar_t));
        line[lineLength] = 0;

        int sourceAdvance = lineLength;
        for (int index = 0; index + 1 < lineLength; ++index) {
            if (line[index] == L'\\' && line[index + 1] == L'n') {
                line[index] = 0;
                lineLength = index;
                sourceAdvance = index + 2;
                break;
            }
        }

        int drawX = bounds->left;
        if (m_textAlign == 1)
            drawX = (bounds->left + bounds->right) / 2 -
                    GetTextWidth(line, lineLength) / 2;
        else if (m_textAlign == 2)
            drawX = bounds->right - GetTextWidth(line, lineLength);

        MoveTo(drawX, m_currentY + lineHeight);
        DrawWideText(line, lineLength);

        consumed += sourceAdvance;
        if (consumed < charCount && text[consumed] == L' ')
            ++consumed;
    }

    MoveTo(savedPosition[1], savedPosition[0]);
}

// UID:0004K0 | by-memory/0x0048e2b0-0x0048e305.CollectionEntryControlPaneScalarDeletingDestructor.md | Completion:90 | Confidence:94
// Compiler-generated MSVC scalar deleting destructor for CollectionEntryControlPane.
// Reconstruct virtual ~CollectionEntryControlPane() and the empty ordinary destructor child.
// Let the compiler regenerate vtable deleting dispatch and secondary-base adjustors,
// Pane base destruction, deleting flags, return-this ABI behavior, and storage release.
// Do not hand-author this wrapper.

// UID:0000QL | by-global/g_pCollectionDialogPane.md | Completion:86 | Confidence:90
// Emitted declaration for this global storage is covered by [UID:0002B8][0x0069adf0-0x0069adf4.g_pCollectionDialogPane](by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md).

// UID:000250 | by-memory/0x006164f0-0x006168d0.CollectionReadOnlyData.md | Completion:90 | Confidence:93
namespace {

static const wchar_t kCollectionDialogPaneName[] = L"Collection Dialog Pane";
static const wchar_t kCollectionDialogPaletteName[] = L"DLGCLT.PAL";
static const wchar_t kCollectionDialogEpfName[] = L"DLGCLT.EPF";
static const wchar_t kCollectionNamePaletteName[] = L"CLTNAME.PAL";
static const wchar_t kCollectionNameEpfName[] = L"CLTNAME.EPF";
static const wchar_t kCollectionVolumeEpfFormat[] = L"CLTVOL%d.EPF";
static const wchar_t kCollectionVolumePaletteFormat[] = L"CLTVOL%d.PAL";
static const wchar_t kCollectionUnknownEntryText[] = L"\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F\uFF1F";
static const wchar_t kCollectionEntryNumberFormat[] = L"%2d";
static const wchar_t kCollectionEntryEpfName[] = L"CLTENTRY.EPF";
static const wchar_t kCollectionEntryPaletteName[] = L"CLTENTRY.PAL";
static const wchar_t kCollectionIconEpfName[] = L"CLTICON.EPF";
static const wchar_t kCollectionIconPaletteName[] = L"CLTICON.PAL";
static const wchar_t kCollectionNumericFontName[] = L"9X11FONT.BIN";
static const wchar_t kCollectionBarEpfName[] = L"CLTBAR.EPF";
static const wchar_t kCollectionBarPaletteName[] = L"CLTBAR.PAL";
static const wchar_t kCollectionProgressTextFormat[] = L"%d/%d (%d%%)";
static const wchar_t kCollectionSymbolFontEpfName[] = L"FONTSYMB.EPF";
static const wchar_t kCollectionSymbolFontPaletteName[] = L"FONTSYMB.PAL";

} // namespace

// UID:0002B8 | by-memory/0x0069adf0-0x0069adf4.g_pCollectionDialogPane.md | Completion:88 | Confidence:91
CollectionDialogPane *g_pCollectionDialogPane;
