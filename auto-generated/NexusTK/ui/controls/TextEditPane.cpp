// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000ON
// Source by-file doc: by-file/TextEditPane.md
// UID:0000EO | by-class/TextEditPane.md | Completion:94 | Confidence:94
// UID0000ON RECONSTRUCTION_CPP root preamble: first translation-unit line.
#include "TextEditPane.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"
#include "../../util/BinaryCodec.h"
#include "../../util/List.h"
#include "../../util/StringBase.h"
#include <cstring>

// Exact missing unit constant; all existing kTextEdit constants remain.
const unsigned int kTextEditAutoScrollSelection = 0x01;

// File-owned source definitions preserved by UID0000ON.
static unsigned int s_styledUnicodeClipboardFormat = 0;
static short s_mouseSelectionAnchor = 0;





// UID:0002ZY | by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md | Completion:92 | Confidence:94
// CPP@0058DCE0 | UID0000OJ accepted formal channel
namespace {
const int kTextEditScrollbarSize = 12;
const unsigned int kTextEditPreserveActiveEditor = 0x104;
const unsigned int kTextEditBlackBackground = 0x02;
const unsigned int kTextEditApplyInitialColor = 0x20;
const unsigned int kTextEditReadOnly = 0x04;
const unsigned int kTextEditUseCurrentTextColor = 0x40;
const unsigned int kTextEditInteractive = 0x80;
const unsigned int kTextEditInitialStateFlags = 0x81;
const unsigned char kTextEditColorFormatMask = 2;
const unsigned char kTextEditCompleteFormatMask = 3;
const short kTextEditDefaultLimit = 30000;
}

TextEditPane::TextEditPane(int viewportWidth,
                           int viewportHeight,
                           int textAreaWidth,
                           int textAreaHeight,
                           int textColor,
                           int textBackColor,
                           bool hasHorizontalScrollbar,
                           bool hasVerticalScrollbar,
                           unsigned int editorFlags,
                           unsigned short legacyAssetMode,
                           bool useDefaultAlignment,
                           bool useThousandsSeparator)
    : ScrollablePane(hasHorizontalScrollbar, hasVerticalScrollbar)
{
    m_useThousandsSeparator = useThousandsSeparator;
    if ((editorFlags & kTextEditPreserveActiveEditor) == 0)
        g_pActiveTextEditPane = this;

    m_activeLineIndex = -1;
    m_useDefaultAlignment = useDefaultAlignment;
    if (!m_useDefaultAlignment)
        m_textAlignment = 2;

    m_replacePreviousCompositionText = false;
    m_replacedCompositionText = false;
    SetLegacyAssetMode(legacyAssetMode);

    m_textStorage = new List(sizeof(wchar_t), 128);

    m_lineTable = new List(sizeof(TextEditLineRecord), 16);
    TextEditLineRecord initialLines[2] = { 0 };
    m_lineTable->Append(2, initialLines);

    m_formatTable = new List(sizeof(TextEditFormatRecord), 16);
    TextEditFormatRecord initialFormat = { 0 };
    initialFormat.referenceCount = 1;
    initialFormat.format.legacyAssetMode = legacyAssetMode;
    initialFormat.format.textColor = textColor;
    initialFormat.format.object = NULL;
    m_formatTable->Append(1, &initialFormat);

    m_formatRuns = new List(sizeof(TextEditFormatRun), 16);
    TextEditFormatRun initialRuns[2] = {
        { 0, 0 },
        { 1, -1 }
    };
    m_formatRuns->Append(2, initialRuns);

    m_selectionStart = 0;
    m_selectionEnd = 0;

    short firstLine = 0;
    short lastLine = 0x7fff;
    RebuildLineTable(&firstLine, &lastLine);

    if (m_textAlignment != 0) {
        TextRunMeasureState state = {
            m_textAreaRight - m_textAreaLeft,
            0,
            0
        };
        IterateTextRuns(firstLine,
                        lastLine,
                        TextRunMeasureCallback,
                        &state);
    }

    RectBounds textArea = { 0, 0, textAreaWidth, textAreaHeight };
    SetTextAreaBounds(&textArea);

    RectBounds viewport = {
        0,
        0,
        viewportWidth - (hasVerticalScrollbar ? kTextEditScrollbarSize : 0),
        viewportHeight - (hasHorizontalScrollbar ? kTextEditScrollbarSize : 0)
    };
    const RectBounds oldBounds = m_bounds;
    LayoutScrollbars(&viewport);
    if (oldBounds.left == m_bounds.left &&
        oldBounds.top == m_bounds.top &&
        oldBounds.right == m_bounds.right &&
        oldBounds.bottom != m_bounds.bottom) {
        OffsetRect(&textArea, 0, m_bounds.bottom - oldBounds.bottom);
        SetTextAreaBounds(&textArea);
    }

    RefreshTextRange(m_selectionStart, m_selectionEnd);
    m_editorFlags = editorFlags | kTextEditInitialStateFlags;

    TextRunFormatData colorFormat = { 0 };
    colorFormat.textColor = textColor;
    if ((editorFlags & kTextEditApplyInitialColor) != 0) {
        ApplyFormatRange(0,
                         static_cast<short>(m_textStorage->GetCount()),
                         kTextEditColorFormatMask,
                         &colorFormat);
        m_currentFormatValid = false;
        RefreshTextRange(0, static_cast<short>(m_textStorage->GetCount()));
    } else if (m_selectionStart == m_selectionEnd) {
        LoadCurrentFormat();
        m_currentFormat.textColor = textColor;
        if (m_textStorage->GetCount() == 0) {
            ApplyFormatRange(0,
                             0,
                             kTextEditCompleteFormatMask,
                             &m_currentFormat);
        }
    } else {
        m_dirty = true;
        ApplyFormatRange(m_selectionStart,
                         m_selectionEnd,
                         kTextEditColorFormatMask,
                         &colorFormat);
        RefreshTextRange(m_selectionStart, m_selectionEnd);
    }

    m_maskedText = false;
    SetTextColor(textColor);
    SetTextBackColor(textBackColor);
    m_maxLength = kTextEditDefaultLimit;
    m_maxLines = kTextEditDefaultLimit;

    if (s_styledUnicodeClipboardFormat == 0) {
        s_styledUnicodeClipboardFormat =
            RegisterClipboardFormatW(L"Nexon.StyledUnicodeText");
        if (s_styledUnicodeClipboardFormat == 0)
            throw new Win32Error;
    }

    if ((m_editorFlags & kTextEditReadOnly) == 0) {
        SetFocusRegistration(true);
        g_pIMEPane->SetFocusPane(this, true);
    }
}

// UID:0002ZZ | by-memory/0x0058e140-0x0058e228.TextEditPaneDestructor.md | Completion:92 | Confidence:94
// CPP@0058E140 | UID0000OJ accepted formal channel
TextEditPane::~TextEditPane()
{
    if (g_pActiveTextEditPane == this)
        g_pActiveTextEditPane = NULL;

    ReleaseFormatObjects();

    if (m_textStorage != NULL) {
        delete m_textStorage;
        m_textStorage = NULL;
    }
    if (m_lineTable != NULL) {
        delete m_lineTable;
        m_lineTable = NULL;
    }
    if (m_formatTable != NULL) {
        delete m_formatTable;
        m_formatTable = NULL;
    }
    if (m_formatRuns != NULL) {
        delete m_formatRuns;
        m_formatRuns = NULL;
    }

    if (g_pIMEPane != NULL)
        g_pIMEPane->SetFocusPane(this, false);
}

// UID:00056B | by-memory/0x0058e230-0x0058e37c.TextEditPaneEarlyCoreMutators.md | Completion:94 | Confidence:94
// CPP@0058E230 | UID0000OJ accepted formal channel
void TextEditPane::SetActiveLineIndex(int lineIndex)           // 0x58e230
{
    m_activeLineIndex = lineIndex;
}
// CPP@0058E260 | UID0000OJ accepted formal channel
// UID0001JM core-body closure. These small accessors are H-inline where noted;
// all other definitions emit through UID0001JM in ascending address order.
bool TextEditPane::IsMaskedText() const                         // 0x58e260
{
    return m_maskedText;
}
// CPP@0058E270 | UID0000OJ accepted formal channel
void TextEditPane::InsertText(const wchar_t *text, int)        // 0x58e270
{
    if (text != NULL)
        InsertTextRange(text, static_cast<short>(wcslen(text)), NULL, NULL);
}
// CPP@0058E2B0 | UID0000OJ accepted formal channel
void TextEditPane::DeleteTextRangeAndClampSelection(short start,
                                                     short end) // 0x58e2b0
{
    DeleteTextRange(start, end);
    const short length = GetTextLength();
    if (m_selectionStart < 0) m_selectionStart = 0;
    if (m_selectionStart > length) m_selectionStart = length;
    if (m_selectionEnd < 0) m_selectionEnd = 0;
    if (m_selectionEnd > length) m_selectionEnd = length;
}
// CPP@0058E320 | UID0000OJ accepted formal channel
void TextEditPane::ClearText()                                 // 0x58e320
{
    DeleteTextRangeAndClampSelection(0, 0x7fff);
}

// UID:0002O9 | by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md | Completion:88 | Confidence:91
// CPP@0058E380 | UID0000OJ accepted formal channel
short TextEditPane::CopyWideText(wchar_t *outText, short capacity) const
{
    if (capacity <= 0) {
        if (outText != NULL) {
            outText[0] = L'\0';
        }
        return 0;
    }

    short count = 0;
    const wchar_t *source = NULL;

    if (m_textStorage != NULL) {
        count = static_cast<short>(m_textStorage->GetCount());
        if (count > capacity) {
            count = capacity;
        }
        if (count > 0) {
            source = static_cast<const wchar_t *>(m_textStorage->GetData(0));
            MemoryMan::Copy(outText, source, static_cast<unsigned int>(count) * sizeof(wchar_t));
        }
    }

    outText[count] = L'\0';
    return count;
}

// UID:00056C | by-memory/0x0058e3e0-0x0058e482.TextEditPaneGetText.md | Completion:94 | Confidence:94
// CPP@0058E3E0 | UID0000OJ accepted formal channel
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
TextEditPane::GetText() const                                  // 0x58e3e0
{
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > result;
    const wchar_t *begin = GetTextBuffer();
    result.InitializeWideFromRange(begin, begin + GetTextLength());
    return result;
}

// UID:0001JN | by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md | Completion:92 | Confidence:94
// CPP@0058E490 | UID0000OJ accepted formal channel
unsigned char *TextEditPane::EncodeState(unsigned short *outSize) const
{
    MemoryMan *memoryMan = GetMemoryMan();
    Encoder encoder;
    unsigned char stateBuffer[32768];

    short textSize = static_cast<short>(
        static_cast<unsigned short>(m_textStorage->GetCount()));
    short lineTableSize = static_cast<short>(
        static_cast<unsigned short>(m_lineTable->GetCount()) *
        static_cast<unsigned short>(sizeof(TextEditLineRecord)));
    short formatTableSize = static_cast<short>(
        static_cast<unsigned short>(m_formatTable->GetCount()) *
        static_cast<unsigned short>(sizeof(TextEditFormatRecord)));
    short formatRunSize = static_cast<short>(
        static_cast<unsigned short>(m_formatRuns->GetCount()) *
        static_cast<unsigned short>(sizeof(TextEditFormatRun)));

    encoder.Initialize(stateBuffer, 32766);
    encoder.WriteBytes(m_textStorage->GetElementAt(0), textSize);
    encoder.WriteByte(0);
    encoder.WriteInt(0x6b6f6e67);

    encoder.WriteShort(lineTableSize);
    encoder.WriteBytes(m_lineTable->GetElementAt(0), lineTableSize);
    encoder.WriteShort(formatTableSize);
    encoder.WriteBytes(m_formatTable->GetElementAt(0), formatTableSize);
    encoder.WriteShort(formatRunSize);
    encoder.WriteBytes(m_formatRuns->GetElementAt(0), formatRunSize);

    unsigned int encodedSize;
    encoder.Finalize(&encodedSize);

    unsigned char *result = static_cast<unsigned char *>(
        GetMemoryMan()->AllocateBufferMemory(encodedSize));
    memoryMan->MemmoveWrapper(result, stateBuffer, encodedSize);
    *outSize = static_cast<unsigned short>(encodedSize);
    return result;
}

// UID:00056D | by-memory/0x0058e6a0-0x0058ee87.TextEditPaneCoreStateAndScrolling.md | Completion:94 | Confidence:94
// CPP@0058E6A0 | UID0000OJ accepted formal channel
void TextEditPane::DecodeState(const unsigned char *data,
                               unsigned short size)             // 0x58e6a0
{
    Decoder decoder;
    decoder.Initialize(data, size);

    m_textStorage->RemoveAll();
    for (;;) {
        const unsigned char value = decoder.ReadByte();
        if (value == 0)
            break;
        m_textStorage->Append(1, const_cast<unsigned char *>(&value));
    }
    if (decoder.ReadInt() != 0x6b6f6e67) {
        decoder.Finalize();
        ClearText();
        return;
    }

    const unsigned short lineBytes = decoder.ReadShort();
    m_lineTable->SetCount(lineBytes / sizeof(TextEditLineRecord));
    decoder.ReadBytes(m_lineTable->GetData(), lineBytes);
    const unsigned short formatBytes = decoder.ReadShort();
    m_formatTable->SetCount(formatBytes / sizeof(TextEditFormatRecord));
    decoder.ReadBytes(m_formatTable->GetData(), formatBytes);
    const unsigned short runBytes = decoder.ReadShort();
    m_formatRuns->SetCount(runBytes / sizeof(TextEditFormatRun));
    decoder.ReadBytes(m_formatRuns->GetData(), runBytes);
    decoder.Finalize();
    LoadCurrentFormat();
    RefreshTextRange(0, GetTextLength());
}
// CPP@0058E880 | UID0000OJ accepted formal channel
short TextEditPane::GetTextLength() const                       // 0x58e880/0x58efa0 source clone
{
    return static_cast<short>(m_textStorage->GetCount());
}
// CPP@0058E890 | UID0000OJ accepted formal channel
bool TextEditPane::ScrollCaretIntoView(short caretIndex)        // 0x58e890
{
    Point point;
    GetCaretLocalPoint(&point, caretIndex);
    bool changed = false;
    if (point.x < m_scrollContentRect.left) {
        const short oldPosition = GetScrollPosition(1);
        ApplyScrollPosition(1, oldPosition,
                            static_cast<unsigned short>(oldPosition -
                                (m_scrollContentRect.left - point.x)));
        changed = true;
    } else if (point.x >= m_scrollContentRect.right) {
        const short oldPosition = GetScrollPosition(1);
        ApplyScrollPosition(1, oldPosition,
                            static_cast<unsigned short>(oldPosition +
                                point.x - m_scrollContentRect.right + 1));
        changed = true;
    }
    const int lineHeight = GetLineHeight();
    if (point.y < m_scrollContentRect.top) {
        const short oldPosition = GetScrollPosition(0);
        ApplyScrollPosition(0, oldPosition,
                            static_cast<unsigned short>(oldPosition -
                                (m_scrollContentRect.top - point.y + lineHeight - 1)
                                / lineHeight));
        changed = true;
    } else if (point.y + lineHeight > m_scrollContentRect.bottom) {
        const short oldPosition = GetScrollPosition(0);
        ApplyScrollPosition(0, oldPosition,
                            static_cast<unsigned short>(oldPosition +
                                (point.y + lineHeight - m_scrollContentRect.bottom
                                 + lineHeight - 1) / lineHeight));
        changed = true;
    }
    return changed;
}
// CPP@0058EA30 | UID0000OJ accepted formal channel
Point TextEditPane::GetCaretLocalPoint(short caretIndex) const // 0x58ea30
{
    Point point;
    GetCaretLocalPoint(&point, caretIndex);
    return point;
}
// CPP@0058EA60 | UID0000OJ accepted formal channel
short TextEditPane::GetTextOffsetAtPoint(int y, int x) const    // 0x58ea60
{
    return GetTextOffsetAtPoint(y, x, NULL);
}
// CPP@0058EA80 | UID0000OJ accepted formal channel
void TextEditPane::SetEditActiveState(bool editActive,
                                      bool selectAll)            // 0x58ea80
{
    const bool wasInteractive = (m_editorFlags & kTextEditInteractive) != 0;
    if (editActive) {
        m_editorFlags &= ~kTextEditReadOnly;
        m_editorFlags |= kTextEditInteractive;
        SetFocusRegistration(true);
        if (selectAll)
            SetSelectionRange(0, GetTextLength());
        else
            ShowSelection();
    } else {
        m_editorFlags |= kTextEditReadOnly;
        m_editorFlags &= ~kTextEditInteractive;
        HideSelection();
        SetFocusRegistration(false);
    }
    if (wasInteractive != editActive)
        OnSelectionChanged();
}
// CPP@0058EB30 | UID0000OJ accepted formal channel
void TextEditPane::SetTextColor(unsigned int color)             // 0x58eb30
{
    GrafPort::SetTextColor(color);
}
// CPP@0058EB40 | UID0000OJ accepted formal channel
void TextEditPane::OnSelectionChanged()                         // 0x58eb40
{
}
// CPP@0058EB50 | UID0000OJ accepted formal channel
void TextEditPane::DispatchNavigationKey(unsigned char key)     // 0x58eb50
{
    Event event;
    event.m_type = 8;
    event.m_payload.m_key.m_key = key;
    HandleNavigationKey(&event);
}
// CPP@0058EBF0 | UID0000OJ accepted formal channel
short TextEditPane::GetScrollRange(char axis)                   // 0x58ebf0
{
    if (axis)
        return static_cast<short>((m_scrollContentRect.right - m_contentRect.right) > 0
            ? m_scrollContentRect.right - m_contentRect.right : 0);
    const int overflow = m_scrollContentRect.bottom - m_contentRect.bottom;
    return static_cast<short>(overflow > 0
        ? (overflow + GetLineHeight() - 1) / GetLineHeight() : 0);
}
// CPP@0058EC80 | UID0000OJ accepted formal channel
short TextEditPane::GetOverflowCount(char axis)                 // 0x58ec80
{
    if (axis)
        return static_cast<short>((m_contentRect.left - m_scrollContentRect.left) > 0
            ? m_contentRect.left - m_scrollContentRect.left : 0);
    const int overflow = m_contentRect.top - m_scrollContentRect.top;
    return static_cast<short>(overflow > 0
        ? (overflow + GetLineHeight() - 1) / GetLineHeight() : 0);
}
// CPP@0058ECE0 | UID0000OJ accepted formal channel
short TextEditPane::GetPageSize(char axis)                      // 0x58ece0
{
    return axis ? 1 : static_cast<short>(
        (m_contentRect.bottom - m_contentRect.top) / GetLineHeight() - 1);
}
// CPP@0058ED20 | UID0000OJ accepted formal channel
short TextEditPane::GetScrollOffset(char axis, short units)     // 0x58ed20
{
    return axis ? units : static_cast<short>(units * GetLineHeight());
}
// CPP@0058ED50 | UID0000OJ accepted formal channel
Point *TextEditPane::GetContentSize(Point *outSize)             // 0x58ed50
{
    outSize->x = m_scrollContentRect.right - m_scrollContentRect.left;
    outSize->y = m_scrollContentRect.bottom - m_scrollContentRect.top;
    return outSize;
}
// CPP@0058ED80 | UID0000OJ accepted formal channel
Point *TextEditPane::GetScrollDelta(Point *outDelta,
                                    char axis,
                                    short oldPosition,
                                    short newPosition)           // 0x58ed80
{
    const short delta = static_cast<short>(oldPosition - newPosition);
    outDelta->x = axis ? delta : 0;
    outDelta->y = axis ? 0 : delta * GetLineHeight();
    return outDelta;
}
// CPP@0058EDD0 | UID0000OJ accepted formal channel
void TextEditPane::UpdateRenderRegion(const RectBounds *bounds) // 0x58edd0
{
    const RectBounds oldBounds = m_bounds;
    ScrollablePane::UpdateRenderRegion(bounds);
    if (oldBounds.left == bounds->left && oldBounds.top == bounds->top &&
        oldBounds.right == bounds->right && oldBounds.bottom != bounds->bottom)
        OffsetRect(&m_scrollContentRect, 0, bounds->bottom - oldBounds.bottom);
    RefreshTextRange(m_selectionStart, m_selectionEnd);
}
// CPP@0058EE50 | UID0000OJ accepted formal channel
void TextEditPane::SetMaxLength(short maxLength)                // 0x58ee50
{
    m_maxLength = maxLength;
    EnforceMaxLength();
}
// CPP@0058EE70 | UID0000OJ accepted formal channel
void TextEditPane::SetMaxLines(short maxLines)                  // 0x58ee70
{
    m_maxLines = maxLines;
    EnforceMaxLines();
}

// UID:00056E | by-memory/0x0058ee90-0x0058ef57.MeasureWrappedTextHeight.md | Completion:94 | Confidence:94
// CPP@0058EE90 | UID0000OJ accepted formal channel
int MeasureWrappedTextHeight(const wchar_t *text,
                             int viewportWidth)                 // 0x58ee90
{
    TextEditPane *pane = new TextEditPane(viewportWidth,
                                          10,
                                          viewportWidth,
                                          10,
                                          128,
                                          0,
                                          false,
                                          false,
                                          kTextEditBlackBackground |
                                              kTextEditReadOnly,
                                          IsLegacyAssetMode(),
                                          true,
                                          false);
    pane->InsertTextRange(text, static_cast<short>(wcslen(text)), NULL, NULL);
    RectBounds bounds;
    pane->GetTextAreaBounds(&bounds);
    const int height = bounds.bottom - bounds.top;
    delete pane;
    return height;
}

// UID:00056F | by-memory/0x0058ef60-0x00590804.TextEditPaneTextAccessAndEditing.md | Completion:94 | Confidence:94
// CPP@0058EF60 | UID0000OJ accepted formal channel
const wchar_t *TextEditPane::GetTextBuffer() const              // 0x58ef60
{
    return m_textStorage->GetCount() == 0 ? L"" :
        static_cast<const wchar_t *>(m_textStorage->GetElementAt(0));
}
// CPP@0058EF70 | UID0000OJ accepted formal channel
wchar_t TextEditPane::GetCharacterAt(short textOffset) const    // 0x58ef70
{
    return textOffset >= 0 && textOffset < GetTextLength()
        ? *static_cast<const wchar_t *>(m_textStorage->GetElementAt(textOffset))
        : L'\0';
}
// CPP@0058EFB0 | UID0000OJ accepted formal channel
short TextEditPane::MeasureTextRange(short start, short end)    // 0x58efb0
{
    if (start < 0) start = 0;
    if (end > GetTextLength()) end = GetTextLength();
    return start < end ? GetTextWidth(GetTextBuffer() + start, end - start) : 0;
}
// CPP@0058F050 | UID0000OJ accepted formal channel
void TextEditPane::GetCaretRange(short *start, short *end) const // 0x58f050
{
    if (start != NULL) *start = m_selectionStart;
    if (end != NULL) *end = m_selectionEnd;
}
// CPP@0058F080 | UID0000OJ accepted formal channel
void TextEditPane::GetTextAreaBounds(RectBounds *bounds) const  // 0x58f080
{
    bounds->left = m_textAreaLeft;
    bounds->top = m_textAreaTop;
    bounds->right = m_textAreaRight;
    bounds->bottom = m_textAreaBottom;
}
// CPP@0058F0A0 | UID0000OJ accepted formal channel
RectBounds TextEditPane::GetViewportBounds() const             // 0x58f0a0
{
    return m_contentRect;
}
// CPP@0058F0D0 | UID0000OJ accepted formal channel
short TextEditPane::GetLineIndexForTextOffset(short textOffset) const // 0x58f0d0
{
    if (textOffset < 0) textOffset = 0;
    short result = 0;
    for (short index = 1; index < m_lineTable->GetCount(); ++index) {
        const TextEditLineRecord *line = static_cast<const TextEditLineRecord *>(
            m_lineTable->GetElementAt(index));
        if (line->startIndex > textOffset)
            break;
        result = index;
    }
    return result;
}
// CPP@0058F150 | UID0000OJ accepted formal channel
void TextEditPane::GetLineTextRange(short lineIndex,
                                    short *start,
                                    short *end) const            // 0x58f150
{
    if (lineIndex < 0) lineIndex = 0;
    if (lineIndex >= m_lineTable->GetCount() - 1)
        lineIndex = static_cast<short>(m_lineTable->GetCount() - 2);
    const TextEditLineRecord *line = static_cast<const TextEditLineRecord *>(
        m_lineTable->GetElementAt(lineIndex));
    const TextEditLineRecord *next = static_cast<const TextEditLineRecord *>(
        m_lineTable->GetElementAt(lineIndex + 1));
    if (start != NULL) *start = line->startIndex;
    if (end != NULL) *end = next->startIndex;
}
// CPP@0058F1A0 | UID0000OJ accepted formal channel
short TextEditPane::GetLineCount() const                        // 0x58f1a0
{
    return static_cast<short>(m_lineTable->GetCount() - 1);
}
// CPP@0058F1B0 | UID0000OJ accepted formal channel
short TextEditPane::GetFormatRunIndexForTextOffset(short textOffset) const // 0x58f1b0
{
    if (textOffset < 0) textOffset = 0;
    short result = 0;
    for (short index = 1; index < m_formatRuns->GetCount(); ++index) {
        const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
            m_formatRuns->GetElementAt(index));
        if (run->startIndex > textOffset)
            break;
        result = index;
    }
    return result;
}
// CPP@0058F230 | UID0000OJ accepted formal channel
void TextEditPane::GetFormatRunBounds(short runIndex,
                                      short *start,
                                      short *end) const          // 0x58f230
{
    if (runIndex < 0) runIndex = 0;
    if (runIndex >= m_formatRuns->GetCount())
        runIndex = static_cast<short>(m_formatRuns->GetCount() - 1);
    const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
        m_formatRuns->GetElementAt(runIndex));
    if (start != NULL) *start = run->startIndex;
    if (end != NULL) *end = run[1].startIndex;
}
// CPP@0058F280 | UID0000OJ accepted formal channel
short TextEditPane::GetLastFormatRunIndex() const               // 0x58f280
{
    return static_cast<short>(m_formatRuns->GetCount() - 1);
}
// CPP@0058F290 | UID0000OJ accepted formal channel
unsigned char TextEditPane::GetRepeatClickCount() const         // 0x58f290
{
    return m_repeatClickCount;
}
// CPP@0058F2A0 | UID0000OJ accepted formal channel
void TextEditPane::SetSelectionRange(short start, short end)    // 0x58f2a0
{
    const short length = GetTextLength();
    start = ClampNavigationIndex(start, 0, length);
    end = ClampNavigationIndex(end, 0, length);
    const short oldStart = m_selectionStart;
    const short oldEnd = m_selectionEnd;
    m_selectionReversed = start > end;
    NormalizeTextRange(&start, &end);
    m_selectionStart = start;
    m_selectionEnd = end;
    m_currentFormatValid = false;
    InvalidateSelectionRange(oldStart, oldEnd);
    InvalidateSelectionRange(start, end);
    ScrollCaretIntoView(m_selectionReversed ? start : end);
}
// CPP@0058F490 | UID0000OJ accepted formal channel
void TextEditPane::SetTextAreaBounds(const RectBounds *bounds)  // 0x58f490
{
    m_textAreaLeft = bounds->left;
    m_textAreaTop = bounds->top;
    m_textAreaRight = bounds->right;
    m_textAreaBottom = bounds->bottom;
}
// CPP@0058F4B0 | UID0000OJ accepted formal channel
void TextEditPane::SetViewportBounds(const RectBounds *bounds)  // 0x58f4b0
{
    m_contentRect = *bounds;
}
// CPP@0058F4D0 | UID0000OJ accepted formal channel
bool TextEditPane::GetCommonSelectionFormat(unsigned short *mask,
                                             TextRunFormatData *format) // 0x58f4d0
{
    const unsigned short requested = *mask & 3;
    unsigned short remaining = requested;
    if (m_selectionStart == m_selectionEnd) {
        LoadCurrentFormat();
        *format = m_currentFormat;
        *mask = remaining;
        return true;
    }
    short run = GetFormatRunIndexForTextOffset(m_selectionStart);
    const short last = GetFormatRunIndexForTextOffset(m_selectionEnd - 1);
    const TextEditFormatRun *firstRun = static_cast<const TextEditFormatRun *>(
        m_formatRuns->GetElementAt(run));
    *format = static_cast<const TextEditFormatRecord *>(
        m_formatTable->GetElementAt(firstRun->formatIndex))->format;
    for (++run; run <= last && remaining != 0; ++run) {
        const TextEditFormatRun *current = static_cast<const TextEditFormatRun *>(
            m_formatRuns->GetElementAt(run));
        const TextRunFormatData &value = static_cast<const TextEditFormatRecord *>(
            m_formatTable->GetElementAt(current->formatIndex))->format;
        if (value.legacyAssetMode != format->legacyAssetMode) remaining &= ~1;
        if (value.textColor != format->textColor) remaining &= ~2;
    }
    *mask = remaining;
    return remaining == requested;
}
// CPP@0058F630 | UID0000OJ accepted formal channel
void TextEditPane::GetFormatSpanAtOffset(short textOffset,
                                         TextEditFormatSpan *span) const // 0x58f630
{
    const short runIndex = GetFormatRunIndexForTextOffset(textOffset);
    const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
        m_formatRuns->GetElementAt(runIndex));
    span->start = run->startIndex;
    span->end = run[1].startIndex;
    span->format = static_cast<const TextEditFormatRecord *>(
        m_formatTable->GetElementAt(run->formatIndex))->format;
}
// CPP@0058F690 | UID0000OJ accepted formal channel
short TextEditPane::GetTextOffsetAtPoint(int y,
                                         int x,
                                         signed char *hitPart) const // 0x58f690
{
    if (hitPart != NULL) *hitPart = 0;
    if (y < m_textAreaTop)
        return 0;
    if (y >= m_textAreaBottom) {
        if (hitPart != NULL) *hitPart = -1;
        return GetTextLength();
    }
    const short lineIndex = GetLineIndexForY(y - m_textAreaTop);
    short start = 0;
    short end = 0;
    GetLineTextRange(lineIndex, &start, &end);
    TextRunHitState state;
    state.remainingWidth = x - m_textAreaLeft;
    state.textOffset = start;
    state.hitPart = 0;
    const_cast<TextEditPane *>(this)->IterateTextRuns(
        lineIndex, lineIndex, TextRunHitTestCallback, &state);
    if (hitPart != NULL) *hitPart = state.hitPart;
    return ClampNavigationIndex(state.textOffset, start, end);
}
// CPP@0058F740 | UID0000OJ accepted formal channel
void TextEditPane::GetCaretLocalPoint(Point *point,
                                       short caretIndex) const    // 0x58f740
{
    point->x = m_textAreaLeft;
    point->y = m_textAreaTop;

    const short firstLine = GetLineIndexForTextOffset(caretIndex);
    TextEditLineRecord *line = static_cast<TextEditLineRecord *>(
        m_lineTable->GetElementAt(firstLine));
    point->y += line->top;
    const int nextLineDelta = line[1].top - line->top;
    const short textLength = GetTextLength();
    bool caretAfterLineBreak = false;
    if (caretIndex == textLength) {
        const wchar_t previousCharacter = GetCharacterAt(
            static_cast<short>(caretIndex - 1));
        caretAfterLineBreak = previousCharacter == L'\r' ||
                              previousCharacter == L'\n';
    }

    if (caretAfterLineBreak) {
        point->y += nextLineDelta;
        const int emptyLineWidth = m_textAreaRight - m_textAreaLeft;
        if (m_textAlignment == 1)
            point->x += emptyLineWidth / 2;
        else if (m_textAlignment == 2)
            point->x += emptyLineWidth;
    } else {
        short boundedLine = firstLine;
        if (boundedLine < 0)
            boundedLine = 0;
        else if (boundedLine >= m_lineTable->GetCount() - 1)
            boundedLine = static_cast<short>(m_lineTable->GetCount() - 2);

        line = static_cast<TextEditLineRecord *>(
            m_lineTable->GetElementAt(boundedLine));
        const short lineStart = line->startIndex;
        short adjustedLineEnd = line[1].startIndex;
        bool excludeLineBreak = adjustedLineEnd < textLength;
        if (!excludeLineBreak) {
            const wchar_t lastLineCharacter = GetCharacterAt(
                static_cast<short>(adjustedLineEnd - 1));
            excludeLineBreak = lastLineCharacter == L'\r' ||
                               lastLineCharacter == L'\n';
        }
        if (excludeLineBreak)
            --adjustedLineEnd;

        if (caretIndex == lineStart) {
            point->x += GetLineAlignmentOffset(line);
        } else {
            TextRunOffsetState state;
            state.point.y = point->y;
            state.point.x = point->x;
            state.targetOffset = caretIndex;
            state.targetIsLineEnd = caretIndex == adjustedLineEnd;
            const_cast<TextEditPane *>(this)->IterateTextRuns(
                firstLine, firstLine, TextRunOffsetMeasureCallback, &state);
            point->y = state.point.y;
            point->x = state.point.x;
        }
    }

    if (point->x < m_textAreaLeft)
        point->x = m_textAreaLeft;
    else if (point->x > m_textAreaRight)
        point->x = m_textAreaRight;
    point->x += 2;
}
// CPP@0058F9A0 | UID0000OJ accepted formal channel
void TextEditPane::GetWordSelectionRange(short textOffset,
                                         signed char hitPart,
                                         short *rangeStart,
                                         short *rangeEnd) const // 0x58f9a0
{
    TextEditRange backward;
    TextEditRange forward;
    const short adjusted = static_cast<short>(textOffset + (hitPart > 0));
    ::FindWordBoundary(GetTextBuffer(), GetTextLength(), adjusted,
                       false, &backward);
    ::FindWordBoundary(GetTextBuffer(), GetTextLength(), adjusted,
                       true, &forward);
    *rangeStart = backward.start;
    *rangeEnd = forward.end;
}
// CPP@0058FA00 | UID0000OJ accepted formal channel
void TextEditPane::GetLineSelectionRange(short textOffset,
                                         signed char,
                                         short *rangeStart,
                                         short *rangeEnd) const // 0x58fa00
{
    GetLineTextRange(GetLineIndexForTextOffset(textOffset),
                     rangeStart, rangeEnd);
}
// CPP@0058FA50 | UID0000OJ accepted formal channel
void TextEditPane::GetVisualLineSelectionRange(short textOffset,
                                               int,
                                               short *rangeStart,
                                               short *rangeEnd) const     // 0x58fa50
{
    const wchar_t *text = GetTextBuffer();
    const short textLength = GetTextLength();
    short lineIndex = GetLineIndexForTextOffset(textOffset);
    const TextEditLineRecord *line = static_cast<const TextEditLineRecord *>(
        m_lineTable->GetElementAt(lineIndex));

    while (line->startIndex > 0) {
        const wchar_t previous = text[line->startIndex - 1];
        if (previous == L'\r' || previous == L'\n')
            break;
        --lineIndex;
        line = static_cast<const TextEditLineRecord *>(
            m_lineTable->GetElementAt(lineIndex));
    }
    if (rangeStart != NULL)
        *rangeStart = static_cast<short>(line->startIndex);

    const TextEditLineRecord *next = static_cast<const TextEditLineRecord *>(
        m_lineTable->GetElementAt(lineIndex + 1));
    while (next->startIndex < textLength) {
        const wchar_t previous = text[next->startIndex - 1];
        if (previous == L'\r' || previous == L'\n')
            break;
        ++lineIndex;
        next = static_cast<const TextEditLineRecord *>(
            m_lineTable->GetElementAt(lineIndex + 1));
    }
    if (rangeEnd != NULL)
        *rangeEnd = static_cast<short>(next->startIndex);
}
// CPP@0058FB20 | UID0000OJ accepted formal channel
void TextEditPane::RebuildAllLines()                            // 0x58fb20
{
    short firstLine = 0;
    short lastLine = 0x7fff;
    RebuildLineTable(&firstLine, &lastLine);
    if (m_textAlignment != 0) {
        TextRunMeasureState state = {
            m_textAreaRight - m_textAreaLeft,
            m_textAreaRight - m_textAreaLeft,
            0
        };
        IterateTextRuns(firstLine, lastLine, TextRunMeasureCallback, &state);
    }
}
// CPP@0058FB90 | UID0000OJ accepted formal channel
void TextEditPane::ScrollSelectionIntoView()                    // 0x58fb90
{
    ScrollCaretIntoView(m_selectionReversed
        ? m_selectionStart : m_selectionEnd);
}
// CPP@0058FBC0 | UID0000OJ accepted formal channel
void TextEditPane::ShowSelection()                              // 0x58fbc0
{
    if (!m_selectionVisible) {
        InvalidateSelectionRange(m_selectionStart, m_selectionEnd);
        m_selectionVisible = true;
    }
}
// CPP@0058FBF0 | UID0000OJ accepted formal channel
void TextEditPane::HideSelection()                              // 0x58fbf0
{
    if (m_selectionVisible) {
        InvalidateSelectionRange(m_selectionStart, m_selectionEnd);
        m_selectionVisible = false;
        InvalidateCaret();
    }
}
// CPP@0058FC30 | UID0000OJ accepted formal channel
int TextEditPane::InsertTextRange(const wchar_t *text,
                                  short length,
                                  const unsigned short *formatPayload,
                                  TextEditObject *textObject)    // 0x58fc30
{
    if (text == NULL || length <= 0 || (m_editorFlags & kTextEditReadOnly) != 0)
        return 0;
    if (m_selectionStart != m_selectionEnd)
        DeleteTextRange(m_selectionStart, m_selectionEnd);
    const short available = static_cast<short>(m_maxLength - GetTextLength());
    if (length > available) length = available;
    if (length <= 0) return 0;
    LoadCurrentFormat();
    InsertTextStorage(m_selectionStart, text, length);
    if (formatPayload != NULL)
        ApplySerializedFormatRuns(m_selectionStart,
            static_cast<short>(m_selectionStart + length), formatPayload);
    if (textObject != NULL) {
        TextRunFormatData objectFormat = m_currentFormat;
        objectFormat.object = textObject;
        ApplyFormatRange(m_selectionStart,
            static_cast<short>(m_selectionStart + 1), 4, &objectFormat);
    }
    m_selectionStart = static_cast<short>(m_selectionStart + length);
    m_selectionEnd = m_selectionStart;
    m_dirty = true;
    RebuildAllLines();
    RefreshTextRange(static_cast<short>(m_selectionStart - length),
                     m_selectionStart);
    return length;
}
// CPP@0058FEA0 | UID0000OJ accepted formal channel
void TextEditPane::DeleteSelection()                           // 0x58fea0
{
    if ((m_editorFlags & kTextEditReadOnly) != 0 ||
        m_selectionStart >= m_selectionEnd)
        return;

    const short start = m_selectionStart;
    const short end = m_selectionEnd;
    m_dirty = true;
    DeleteTextRange(start, end);
    m_selectionStart = start;
    m_selectionEnd = start;
    RefreshTextRange(start, end);
}
// CPP@0058FEF0 | UID0000OJ accepted formal channel
void TextEditPane::ApplySelectionFormat(unsigned char formatMask,
                                        const void *formatData) // 0x58fef0
{
    ApplyFormatRange(m_selectionStart, m_selectionEnd, formatMask,
                     static_cast<const TextRunFormatData *>(formatData));
}
// CPP@0058FFE0 | UID0000OJ accepted formal channel
void TextEditPane::ApplySerializedFormatToSelection(
    const unsigned short *payload)                             // 0x58ffe0
{
    if ((m_editorFlags & kTextEditReadOnly) != 0)
        return;

    ApplySerializedFormatRuns(m_selectionStart, m_selectionEnd, payload);
    RefreshTextRange(m_selectionStart, m_selectionEnd);
}
// CPP@00590030 | UID0000OJ accepted formal channel
void TextEditPane::SetText(const wchar_t *text)                // 0x590030
{
    m_dirty = false;
    ReleaseFormatObjects();

    const short length = static_cast<short>(wcslen(text));
    m_textStorage->RemoveAll();
    m_textStorage->Append(length, const_cast<wchar_t *>(text));

    m_formatRuns->SetCount(2);
    TextEditFormatRun *runs = static_cast<TextEditFormatRun *>(
        m_formatRuns->GetElementAt(0));
    runs[1].startIndex = static_cast<unsigned short>(length + 1);
    runs[1].formatIndex = -1;
    static_cast<TextEditFormatRecord *>(m_formatTable->GetElementAt(
        runs[0].formatIndex))->referenceCount = 1;

    m_lineTable->SetCount(2);
    TextEditLineRecord *lines = static_cast<TextEditLineRecord *>(
        m_lineTable->GetElementAt(0));
    std::memset(lines, 0, 2 * sizeof(TextEditLineRecord));
    lines[1].startIndex = static_cast<unsigned short>(length);

    m_selectionStart = 0;
    m_selectionEnd = 0;
    m_repeatClickCount = 0;
    m_unusedClickState = 0;
    RefreshTextRange(0, GetTextLength());
    EnforceMaxLength();
    EnforceMaxLines();
}
// CPP@00590130 | UID0000OJ accepted formal channel
bool TextEditPane::IsDirty() const                              // 0x590130
{
    return m_dirty;
}
// CPP@00590140 | UID0000OJ accepted formal channel
void TextEditPane::SetDirty(bool dirty)                         // 0x590140
{
    m_dirty = dirty;
}
// CPP@00590150 | UID0000OJ accepted formal channel
void TextEditPane::CutSelectionToScrap(TextEditScrap *scrap)   // 0x590150
{
    CopySelectionToScrap(scrap);
    if ((m_editorFlags & kTextEditReadOnly) != 0 ||
        m_selectionStart >= m_selectionEnd)
        return;

    const short start = m_selectionStart;
    const short end = m_selectionEnd;
    m_dirty = true;
    DeleteTextRange(start, end);
    m_selectionStart = start;
    m_selectionEnd = start;
    RefreshTextRange(start, end);
}
// CPP@005901B0 | UID0000OJ accepted formal channel
void TextEditPane::CopySelectionToScrap(TextEditScrap *scrap)  // 0x5901b0
{
    wchar_t *text = NULL;
    const int length = DuplicateTextRange(m_selectionStart,
                                          m_selectionEnd,
                                          &text);
    scrap->Clear();
    if (length > 0) {
        scrap->SetText(text, length);
        GetMemoryMan()->FreeBufferMemory(text);
    }
    if ((m_editorFlags & kTextEditApplyInitialColor) == 0) {
        void *payload = NULL;
        const int payloadSize = BuildSerializedFormatRuns(
            m_selectionStart, m_selectionEnd, &payload);
        if (payloadSize > 0) {
            scrap->SetPayload(payload, payloadSize);
            GetMemoryMan()->FreeBufferMemory(payload);
        }
    }
}
// CPP@005904A0 | UID0000OJ accepted formal channel
void TextEditPane::PasteFromClipboard(TextEditScrap *scrap)     // 0x5904a0
{
    wchar_t *text = NULL;
    const int length = scrap->DuplicateText(&text);
    void *payload = NULL;
    scrap->DuplicatePayload(&payload);
    if (text != NULL && length > 0)
        InsertTextRange(text, static_cast<short>(length),
                        static_cast<const unsigned short *>(payload), NULL);
    if (text != NULL) GetMemoryMan()->FreeBufferMemory(text);
    if (payload != NULL) GetMemoryMan()->FreeBufferMemory(payload);
}
// CPP@00590520 | UID0000OJ accepted formal channel
void TextEditPane::CopyAllToClipboard()                        // 0x590520
{
    SetSelectionRange(0, GetTextLength());
    TextEditScrap scrap;
    CopySelectionToScrap(&scrap);
    PutScrapToClipboard(&scrap);
}
// CPP@005905F0 | UID0000OJ accepted formal channel
void TextEditPane::InsertEmbeddedObject(TextEditObject *object,
                                        int width,
                                        int height)              // 0x5905f0
{
    if (object == NULL)
        return;
    object->SetPayloadPair(width, height);
    const wchar_t objectCharacter = 0xfffc;
    InsertTextRange(&objectCharacter, 1, NULL, object);
}
// CPP@005906A0 | UID0000OJ accepted formal channel
TextEditObject *TextEditPane::GetSelectedEmbeddedObject() const // 0x5906a0
{
    if (m_selectionEnd - m_selectionStart != 1)
        return NULL;
    const short runIndex = GetFormatRunIndexForTextOffset(m_selectionStart);
    const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
        m_formatRuns->GetElementAt(runIndex));
    const TextEditFormatRecord *record =
        static_cast<const TextEditFormatRecord *>(
            m_formatTable->GetElementAt(run->formatIndex));
    return record->format.object;
}
// CPP@00590710 | UID0000OJ accepted formal channel
TextEditObject *TextEditPane::FindNextEmbeddedObject(short *textOffset) const // 0x590710
{
    short runIndex = GetFormatRunIndexForTextOffset(*textOffset);
    for (; runIndex < m_formatRuns->GetCount() - 1; ++runIndex) {
        const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
            m_formatRuns->GetElementAt(runIndex));
        const TextEditFormatRecord *record =
            static_cast<const TextEditFormatRecord *>(
                m_formatTable->GetElementAt(run->formatIndex));
        if (record->format.object != NULL) {
            *textOffset = run->startIndex;
            return record->format.object;
        }
    }
    return NULL;
}
// CPP@005907A0 | UID0000OJ accepted formal channel
bool TextEditPane::SetEditorFlag(short flagIndex, short state)  // 0x5907a0
{
    const unsigned int mask = 1U << flagIndex;
    const bool wasSet = (m_editorFlags & mask) != 0;
    if (state == -2)
        state = wasSet ? 0 : 1;
    if (state == 0)
        m_editorFlags &= ~mask;
    else if (state == 1)
        m_editorFlags |= mask;
    return wasSet;
}

// UID:00030C | by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md | Completion:92 | Confidence:94
// CPP@00590810 | UID0000OJ accepted formal channel
void TextEditPane::OnDraw()
{
    const unsigned int oldDrawColor = m_drawColor;
    m_drawMode = 0;
    SetDrawColor((m_editorFlags & kTextEditBlackBackground) != 0
                     ? 0
                     : m_textBackColor);
    g_pfnFillRect(this, &m_bounds);
    SetDrawColor(oldDrawColor);

    RectBounds clipBounds;
    GetClipRect(&clipBounds);
    const short lastVisibleLine =
        GetLineIndexForY(clipBounds.bottom - m_textAreaTop - 1);
    const short firstVisibleLine =
        GetLineIndexForY(clipBounds.top - m_textAreaTop);
    DrawTextRange(firstVisibleLine, lastVisibleLine);

    if ((m_editorFlags & kTextEditInteractive) == 0)
        return;

    if (m_selectionStart < m_selectionEnd) {
        List selectionRects(sizeof(RectBounds), 16);
        BuildTextRangeRectangles(m_selectionStart,
                                 m_selectionEnd,
                                 &selectionRects);
        for (int index = 0; index < selectionRects.GetCount(); ++index) {
            CompositePixels(static_cast<const RectBounds *>(
                selectionRects.GetElementAt(index)));
        }
        return;
    }

    DrawCaret();
}

// UID:00030F | by-memory/0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent.md | Completion:92 | Confidence:94
// CPP@005909F0 | UID0000OJ accepted formal channel
bool TextEditPane::OnKeyEvent(Event *event)
{
    if (event->m_type == kEventTextInput)
    {
        if (event->m_payload.m_text.m_text[0] == L'\r'
            || (m_editorFlags & kTextEditReadOnly) != 0)
            return false;

        if (!m_maskedText)
        {
            if (m_replacePreviousCompositionText)
            {
                DeleteSelectionOrBackspace();
                m_replacedCompositionText = true;
            }

            InsertTextRange(event->m_payload.m_text.m_text,
                            event->m_payload.m_text.m_length,
                            0,
                            0);
            m_dirty = true;
        }
        return true;
    }

    if (event->m_type != kEventKeyDown)
        return false;

    unsigned char modifiers = event->m_payload.m_key.m_modifiers;
    unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key, modifiers);

    if ((modifiers & kEventModifierControl) != 0)
    {
        if (key == 'c')
        {
            if (m_selectionStart != m_selectionEnd)
            {
                TextEditScrap scrap;
                CopySelectionToScrap(&scrap);
                PutScrapToClipboard(&scrap);
            }
            return true;
        }

        if (key == 'v')
        {
            if ((s_styledUnicodeClipboardFormat != 0
                    && IsClipboardFormatAvailable(
                        s_styledUnicodeClipboardFormat) != 0)
                || IsClipboardFormatAvailable(CF_TEXT) != 0)
            {
                TextEditScrap scrap;
                GetScrapFromClipboard(&scrap);
                PasteFromClipboard(&scrap);
            }
            return true;
        }

        if (key == 'x')
        {
            if (m_selectionStart != m_selectionEnd)
            {
                TextEditScrap scrap;
                CopySelectionToScrap(&scrap);

                if ((m_editorFlags & kTextEditReadOnly) == 0)
                {
                    short start = m_selectionStart;
                    short end = m_selectionEnd;
                    m_dirty = true;
                    DeleteTextRange(start, end);
                    m_selectionStart = start;
                    m_selectionEnd = start;
                    RefreshTextRange(start, end);
                }

                PutScrapToClipboard(&scrap);
            }
            return true;
        }
    }

    switch (key)
    {
    case kPaneKeyLeft:
    case kPaneKeyUp:
    case kPaneKeyRight:
    case kPaneKeyDown:
        HandleNavigationKey(event);
        return true;
    }

    if (key == kPaneKeyDelete)
    {
        if ((modifiers & kEventModifierAlt) != 0)
            return false;

        if ((m_editorFlags & kTextEditReadOnly) == 0)
        {
            short start = m_selectionStart;
            short end = m_selectionEnd;
            if (start != end)
                DeleteTextRange(start, end);
            else if (start < GetTextLength())
                DeleteTextRange(start, start + 1);

            m_selectionStart = start;
            m_selectionEnd = start;
            RefreshTextRange(start, start);
        }

        m_dirty = true;
        return true;
    }

    if (key == '\b')
    {
        if ((modifiers & kEventModifierAlt) != 0)
            return false;

        DeleteSelectionOrBackspace();
        m_dirty = true;
        return true;
    }

    if (key == '\r')
    {
        if ((modifiers & kEventModifierAlt) != 0)
            return false;

        wchar_t text = L'\r';
        m_dirty = true;
        InsertTextRange(&text, 1, 0, 0);
        return true;
    }

    if (key >= 32 && key <= 126)
    {
        if ((m_editorFlags & kTextEditReadOnly) == 0 && m_maskedText)
        {
            event->m_payload.m_text.m_text[0] = key;
            InsertTextRange(event->m_payload.m_text.m_text, 1, 0, 0);
            m_dirty = true;
        }
        return true;
    }

    return false;
}

// UID:0004TZ | by-memory/0x00590dd0-0x00590dd5.TextEditPaneOnKeyUp.md | Completion:92 | Confidence:94
// CPP@00590DD0 | UID0000OJ accepted formal channel
bool TextEditPane::OnKeyUp(Event *event)
{
    (void)event;
    return false;
}

// UID:00030E | by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md | Completion:92 | Confidence:94
// CPP@00590DE0 | UID0000OJ accepted formal channel
extern bool g_useEpfAssets;
BOOL __stdcall CompleteImeComposition();

namespace {
const unsigned int kTextEditRepeatedClickMilliseconds = 500;
const signed char kTextHitAfterCharacter = 2;
}

bool TextEditPane::OnMouseEvent(Event *event)
{
    if ((m_editorFlags & kTextEditInteractive) == 0)
        return true;

    const int y = event->m_payload.m_pointer.m_y;
    const int x = event->m_payload.m_pointer.m_x;

    switch (event->m_type) {
    case kEventCursorMove:
    {
        if (!HasMouseCapture())
            return false;

        signed char hitPart;
        short textOffset = GetTextOffsetAtPoint(y, x, &hitPart);
        if (m_repeatClickCount != 0) {
            TextEditRange range;
            if (m_repeatClickCount <= 1) {
                ::FindWordBoundary(
                    static_cast<const wchar_t *>(m_textStorage->GetData(0)),
                    GetTextLength(),
                    textOffset,
                    hitPart != 0,
                    &range);
            } else {
                GetLineSelectionRange(textOffset,
                                      hitPart,
                                      &range.start,
                                      &range.end);
            }

            if (m_savedSelectionStart >= textOffset) {
                textOffset = range.start;
                s_mouseSelectionAnchor = m_savedSelectionEnd;
            } else {
                textOffset = range.end;
                s_mouseSelectionAnchor = m_savedSelectionStart;
            }
        } else if (hitPart == kTextHitAfterCharacter) {
            ++textOffset;
        }

        SetSelectionRange(s_mouseSelectionAnchor, textOffset);
        AutoScrollSelectionToPoint(y, x);
        return true;
    }

    case kEventLeftButtonDown:
    case kEventLeftButtonDoubleClick:
    {
        if (!PointInRect(y, x, &m_contentRect))
            return false;

        signed char hitPart;
        const short clickedOffset = GetTextOffsetAtPoint(y, x, &hitPart);
        const unsigned int messageTime =
            event->m_payload.m_pointer.m_messageTime;
        const bool repeatedClick =
            messageTime < m_lastClickTime + kTextEditRepeatedClickMilliseconds &&
            clickedOffset == m_lastClickTextOffset;

        m_lastClickTime = messageTime;
        m_lastClickTextOffset = clickedOffset;
        m_lastClickHitPart = hitPart;

        if (m_selectionEnd - m_selectionStart == 1) {
            const short runIndex =
                GetFormatRunIndexForTextOffset(m_selectionStart);
            TextEditFormatRun *run = static_cast<TextEditFormatRun *>(
                m_formatRuns->GetElementAt(runIndex));
            TextEditFormatRecord *record = static_cast<TextEditFormatRecord *>(
                m_formatTable->GetElementAt(run->formatIndex));
            TextEditObject *object = record->format.object;
            if (object != NULL &&
                m_selectionStart <= clickedOffset &&
                clickedOffset < m_selectionEnd) {
                object->OnMouseEvent(event, repeatedClick, m_lastClickTime);
            }
        }

        if ((event->m_payload.m_pointer.m_modifiers & kEventModifierShift) != 0) {
            s_mouseSelectionAnchor =
                m_selectionReversed ? m_selectionEnd : m_selectionStart;
        } else if (repeatedClick) {
            ++m_repeatClickCount;
            if (m_repeatClickCount <= 1) {
                GetWordSelectionRange(clickedOffset,
                                      m_lastClickHitPart,
                                      &m_savedSelectionStart,
                                      &m_savedSelectionEnd);
            } else {
                GetLineSelectionRange(clickedOffset,
                                      m_lastClickHitPart,
                                      &m_savedSelectionStart,
                                      &m_savedSelectionEnd);
            }
        } else {
            m_repeatClickCount = 0;
            s_mouseSelectionAnchor = clickedOffset;
        }

        CompleteImeComposition();
        if (event->m_type == kEventLeftButtonDown)
            CaptureMouse();

        signed char currentHitPart;
        short currentOffset = GetTextOffsetAtPoint(y, x, &currentHitPart);
        if (m_repeatClickCount != 0) {
            TextEditRange range;
            if (m_repeatClickCount <= 1) {
                ::FindWordBoundary(
                    static_cast<const wchar_t *>(m_textStorage->GetData(0)),
                    GetTextLength(),
                    currentOffset,
                    currentHitPart != 0,
                    &range);
            } else {
                GetLineSelectionRange(currentOffset,
                                      currentHitPart,
                                      &range.start,
                                      &range.end);
            }

            if (m_savedSelectionStart >= currentOffset) {
                currentOffset = range.start;
                s_mouseSelectionAnchor = m_savedSelectionEnd;
            } else {
                currentOffset = range.end;
                s_mouseSelectionAnchor = m_savedSelectionStart;
            }
        } else if (currentHitPart == kTextHitAfterCharacter) {
            ++currentOffset;
        }

        SetSelectionRange(s_mouseSelectionAnchor, currentOffset);
        AutoScrollSelectionToPoint(y, x);
        return true;
    }

    case kEventLeftButtonUp:
        if (HasMouseCapture())
            ReleaseMouseCapture();
        return g_useEpfAssets != 1;

    case kEventRightButtonDown:
        SetSelectionRange(0, 0);
        return true;

    default:
        return false;
    }
}

// UID:00056G | by-memory/0x00591180-0x005912ad.TextEditPaneLimitEnforcement.md | Completion:94 | Confidence:94
// CPP@00591180 | UID0000OJ accepted formal channel
void TextEditPane::EnforceMaxLength()                           // 0x591180
{
    if (GetTextLength() > m_maxLength) {
        const short oldLength = GetTextLength();
        DeleteTextRangeAndClampSelection(m_maxLength, 0x7fff);
        RefreshTextRange(m_maxLength, oldLength);
    }
}
// CPP@00591200 | UID0000OJ accepted formal channel
void TextEditPane::EnforceMaxLines()                            // 0x591200
{
    const short lineCount = GetLineCount();
    if (lineCount > m_maxLines) {
        short start = 0;
        short end = 0;
        GetLineTextRange(m_maxLines, &start, &end);
        const short oldLength = GetTextLength();
        DeleteTextRangeAndClampSelection(start, 0x7fff);
        RefreshTextRange(start, oldLength);
    }
}

// UID:0004T0 | by-memory/0x005912b0-0x005912fe.TextEditPaneReleaseFormatObjects.md | Completion:90 | Confidence:93
// CPP@005912B0 | UID0000OJ accepted formal channel
void TextEditPane::ReleaseFormatObjects()
{
    if (m_formatTable == NULL)
        return;

    for (int index = m_formatTable->GetCount() - 1; index >= 0; --index) {
        TextEditFormatRecord *record =
            static_cast<TextEditFormatRecord *>(m_formatTable->GetElementAt(index));

        if (record->referenceCount > 0 && record->format.object != NULL) {
            delete record->format.object;
            record->format.object = NULL;
        }

        record->referenceCount = 0;
    }
}

// UID:0002RU | by-memory/0x00591300-0x005913f9.TextEditPaneCaretAndSelectionInvalidationHelpers.md | Completion:94 | Confidence:94
// CPP@00591300 | UID0000ON accepted formal channel
// UID0002RU RECONSTRUCTION_CPP CODE -> UID0000EO children -> TextEditPane.cpp
void TextEditPane::InvalidateCaret()                           // 0x591300
{
    Point caretPoint;
    GetCaretLocalPoint(&caretPoint, m_selectionStart);

    RectBounds caretBounds;
    caretBounds.left = caretPoint.x;
    if (m_textAreaLeft < caretPoint.x)
        --caretBounds.left;
    caretBounds.top = caretPoint.y;
    caretBounds.right = caretPoint.x + 1;
    caretBounds.bottom = caretPoint.y + GetLineHeight();

    InvalidateRect(&caretBounds);
}

// CPP@00591370 | UID0000ON accepted formal channel
void TextEditPane::InvalidateSelectionRange(short start,
                                             short end)         // 0x591370
{
    List selectionBounds(sizeof(RectBounds), 16);
    BuildTextRangeRectangles(start, end, &selectionBounds);
    for (int index = 0; index < selectionBounds.GetCount(); ++index) {
        InvalidateRect(static_cast<RectBounds *>(
            selectionBounds.GetElementAt(index)));
    }
}

// UID:0004TC | by-memory/0x00591400-0x005914c4.TextEditPaneRefreshTextRange.md | Completion:92 | Confidence:94
// CPP@00591400 | UID0000OJ accepted formal channel
void TextEditPane::RefreshTextRange(short start, short end)
{
    if ((m_editorFlags & 0x08) != 0)
        return;

    short firstLine = GetLineIndexForTextOffset(start);
    short lastLine = GetLineIndexForTextOffset(end);
    RebuildLineTable(&firstLine, &lastLine);

    if (m_textAlignment != 0) {
        TextRunMeasureState state = {
            m_textAreaRight - m_textAreaLeft,
            0,
            0
        };
        IterateTextRuns(firstLine,
                        lastLine,
                        TextRunMeasureCallback,
                        &state);
    }

    if ((m_editorFlags & 0x10) == 0) {
        InvalidateRect(&m_contentRect);
        ScrollCaretIntoView(m_selectionReversed
                                ? m_selectionStart
                                : m_selectionEnd);
    }
}

// UID:0004TD | by-memory/0x005914d0-0x0059151c.TextEditPaneGetCaretBounds.md | Completion:91 | Confidence:93
// CPP@005914D0 | UID0000OJ accepted formal channel
void TextEditPane::GetCaretBounds(short caretIndex,
                                  RectBounds *bounds) const
{
    Point caretPoint;
    GetCaretLocalPoint(&caretPoint, caretIndex);

    bounds->left = caretPoint.x;
    if (m_textAreaLeft < caretPoint.x)
        --bounds->left;
    bounds->top = caretPoint.y;
    bounds->right = caretPoint.x + 1;
    bounds->bottom = caretPoint.y + GetLineHeight();
}

// UID:0004T1 | by-memory/0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles.md | Completion:92 | Confidence:94
// CPP@00591520 | UID0000OJ accepted formal channel
void TextEditPane::BuildTextRangeRectangles(short start,
                                            short end,
                                            List *rectangles) const
{
    if (end < start) {
        const short savedStart = start;
        start = end;
        end = savedStart;
    }

    Point startPoint;
    Point endPoint;
    GetCaretLocalPoint(&startPoint, start);
    GetCaretLocalPoint(&endPoint, end);

    RectBounds bounds;
    if (startPoint.y == endPoint.y) {
        bounds.left = startPoint.x;
        bounds.top = startPoint.y;
        bounds.right = endPoint.x;
        bounds.bottom = endPoint.y + GetLineHeight();
        rectangles->Append(1, &bounds);
        return;
    }

    bounds.left = startPoint.x;
    bounds.top = startPoint.y;
    bounds.right = m_textAreaRight;
    bounds.bottom = startPoint.y + GetLineHeight();
    rectangles->Append(1, &bounds);

    if (startPoint.y + GetLineHeight() < endPoint.y) {
        bounds.left = m_textAreaLeft;
        bounds.top = startPoint.y + GetLineHeight();
        bounds.right = m_textAreaRight;
        bounds.bottom = endPoint.y;
        rectangles->Append(1, &bounds);
    }

    bounds.left = m_textAreaLeft;
    bounds.top = endPoint.y;
    bounds.right = endPoint.x;
    bounds.bottom = endPoint.y + GetLineHeight();
    rectangles->Append(1, &bounds);
}

// UID:0004TE | by-memory/0x00591640-0x005916b5.TextEditPaneDrawTextRange.md | Completion:91 | Confidence:93
// CPP@00591640 | UID0000OJ accepted formal channel
void TextEditPane::DrawTextRange(short firstLine, short lastLine)
{
    RectBounds clipBounds;
    GetClipRect(&clipBounds);
    if (IsRectEmptyOrInvalid(&clipBounds))
        return;

    TextRunDrawState drawState = { 0 };
    drawState.applyRunTextColor =
        (m_editorFlags & kTextEditUseCurrentTextColor) == 0;
    IterateTextRuns(firstLine,
                    lastLine,
                    DrawTextRunCallback,
                    &drawState);
}

// UID:0004TF | by-memory/0x005916c0-0x0059173e.TextEditPaneDrawCaret.md | Completion:91 | Confidence:93
// CPP@005916C0 | UID0000OJ accepted formal channel
void TextEditPane::DrawCaret()
{
    if ((m_editorFlags & kTextEditReadOnly) != 0)
        return;

    RectBounds caretBounds;
    GetCaretBounds(m_selectionStart, &caretBounds);
    SetDrawColor(m_textColor);
    g_pfnFillRect(this, &caretBounds);
}

// UID:00030D | by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md | Completion:91 | Confidence:93
// CPP@00591740 | UID0000OJ accepted formal channel
void TextEditPane::InvalidateTextRegion(short start, short end)
{
    List invalidBounds(sizeof(RectBounds), 16);
    BuildTextRangeRectangles(start, end, &invalidBounds);
    for (int index = 0; index < invalidBounds.GetCount(); ++index) {
        CompositePixels(static_cast<const RectBounds *>(
            invalidBounds.GetElementAt(index)));
    }
}

// UID:0004T8 | by-memory/0x005917d0-0x00591a1c.PutScrapToClipboard.md | Completion:91 | Confidence:93
// CPP@005917D0 | UID0000OJ accepted formal channel
void PutScrapToClipboard(TextEditScrap *scrap)
{
    wchar_t *text = 0;
    int textLength = scrap->DuplicateText(&text);

    void *payload = 0;
    scrap->DuplicatePayload(&payload);

    if (text == 0)
        return;

    OpenClipboard(g_pApplication->GetMainWindowHandle());
    EmptyClipboard();

    int carriageReturnCount = 0;
    for (int index = 0; index < textLength; ++index)
    {
        if (text[index] == L'\r')
            ++carriageReturnCount;
    }

    wchar_t *normalizedText = text;
    int normalizedLength = textLength;
    if (carriageReturnCount != 0)
    {
        normalizedLength = textLength + carriageReturnCount;
        normalizedText = new wchar_t[normalizedLength + 1];

        int outputIndex = 0;
        for (int inputIndex = 0; inputIndex < textLength; ++inputIndex)
        {
            normalizedText[outputIndex++] = text[inputIndex];
            if (text[inputIndex] == L'\r')
                normalizedText[outputIndex++] = L'\n';
        }
        normalizedText[normalizedLength] = 0;
    }

    int encodedLength = WideCharToMultiByte(
        CP_ACP, 0, normalizedText, normalizedLength, 0, 0, 0, 0);
    HGLOBAL clipboardBlock = GlobalAlloc(GMEM_DDESHARE, encodedLength + 1);
    if (clipboardBlock == 0)
        throw new Win32Error;

    char *clipboardText = static_cast<char *>(GlobalLock(clipboardBlock));
    WideCharToMultiByte(
        CP_ACP, 0, normalizedText, normalizedLength,
        clipboardText, encodedLength, 0, 0);

    if (normalizedText != text)
        delete [] normalizedText;

    clipboardText[encodedLength] = 0;
    SetClipboardData(CF_TEXT, clipboardBlock);
    GlobalUnlock(clipboardBlock);

    GetMemoryMan()->FreeBufferMemory(text);
    if (payload != 0)
        GetMemoryMan()->FreeBufferMemory(payload);

    CloseClipboard();
}

// UID:0004U1 | by-memory/0x00591a20-0x00591c65.GetScrapFromClipboard.md | Completion:92 | Confidence:94
// CPP@00591A20 | UID0000OJ accepted formal channel
void GetScrapFromClipboard(TextEditScrap *scrap)
{
    wchar_t *text = 0;
    int textLength = 0;
    void *payload = 0;
    int payloadSize = 0;

    scrap->Clear();

    bool hasStyledText =
        IsClipboardFormatAvailable(s_styledUnicodeClipboardFormat) != 0;

    OpenClipboard(g_pApplication->GetMainWindowHandle());

    if (hasStyledText)
    {
        HGLOBAL clipboardBlock =
            GetClipboardData(s_styledUnicodeClipboardFormat);
        const unsigned char *clipboardData =
            static_cast<const unsigned char *>(GlobalLock(clipboardBlock));

        textLength = *reinterpret_cast<const int *>(clipboardData);
        clipboardData += sizeof(int);
        text = static_cast<wchar_t *>(
            GetMemoryMan()->AllocateBufferMemory(
                textLength * sizeof(wchar_t)));
        GetMemoryMan()->MemmoveWrapper(
            text, clipboardData, textLength * sizeof(wchar_t));
        clipboardData += textLength * sizeof(wchar_t);

        payloadSize = *reinterpret_cast<const int *>(clipboardData);
        clipboardData += sizeof(int);
        payload = GetMemoryMan()->AllocateBufferMemory(payloadSize);
        GetMemoryMan()->MemmoveWrapper(payload, clipboardData, payloadSize);

        GlobalUnlock(clipboardBlock);
    }
    else
    {
        HGLOBAL clipboardBlock = GetClipboardData(CF_TEXT);
        const char *clipboardText =
            static_cast<const char *>(GlobalLock(clipboardBlock));
        int clipboardLength = strlen(clipboardText);

        textLength = MultiByteToWideChar(
            CP_ACP, 0, clipboardText, clipboardLength, 0, 0);
        text = static_cast<wchar_t *>(
            GetMemoryMan()->AllocateBufferMemory(
                textLength * sizeof(wchar_t)));
        MultiByteToWideChar(
            CP_ACP, 0, clipboardText, clipboardLength, text, textLength);

        GlobalUnlock(clipboardBlock);
    }

    for (int index = 0; index < textLength; ++index)
    {
        if (text[index] == L'\n')
        {
            GetMemoryMan()->MoveBufferMemory(
                text + index,
                text + index + 1,
                (textLength - index) * sizeof(wchar_t));
            --textLength;
            --index;
        }
    }

    if (textLength > 0)
    {
        scrap->m_textLength = textLength;
        scrap->m_text = static_cast<wchar_t *>(
            GetMemoryMan()->AllocateBufferMemory(
                textLength * sizeof(wchar_t)));
        GetMemoryMan()->MemmoveWrapper(
            scrap->m_text, text, textLength * sizeof(wchar_t));
    }

    if (payload != 0 && payloadSize > 0)
    {
        scrap->m_payloadSize = payloadSize;
        scrap->m_payload =
            GetMemoryMan()->AllocateBufferMemory(payloadSize);
        GetMemoryMan()->MemmoveWrapper(
            scrap->m_payload, payload, payloadSize);
    }

    GetMemoryMan()->FreeBufferMemory(text);
    if (payload != 0)
        GetMemoryMan()->FreeBufferMemory(payload);

    CloseClipboard();
}

// UID:000565 | by-memory/0x00591c70-0x00591ca1.TextEditPaneIsPasteUnavailable.md | Completion:94 | Confidence:94
// CPP@00591C70 | UID0000OJ accepted formal channel
bool TextEditPane::IsPasteUnavailable() const
{
    if (s_styledUnicodeClipboardFormat != 0 &&
        IsClipboardFormatAvailable(s_styledUnicodeClipboardFormat) > 0)
        return false;
    return IsClipboardFormatAvailable(CF_TEXT) <= 0;
}

// UID:000566 | by-memory/0x00591cb0-0x00591d52.TextEditPaneDuplicateTextRange.md | Completion:94 | Confidence:94
// CPP@00591CB0 | UID0000OJ accepted formal channel
int TextEditPane::DuplicateTextRange(short start,
                                     short end,
                                     wchar_t **outText) const
{
    if (outText == NULL)
        return 0;
    if (start < 0) start = 0;
    if (end > GetTextLength()) end = GetTextLength();
    if (end <= start) {
        *outText = NULL;
        return 0;
    }
    const int count = end - start;
    *outText = static_cast<wchar_t *>(
        GetMemoryMan()->AllocateBufferMemory(count * sizeof(wchar_t)));
    GetMemoryMan()->MemmoveWrapper(*outText, GetTextBuffer() + start,
                                   count * sizeof(wchar_t));
    return count;
}

// UID:00056H | by-memory/0x00591d60-0x00592bab.TextEditPaneFormattingRunsBeforeLineLookup.md | Completion:94 | Confidence:94
// CPP@00591D60 | UID0000OJ accepted formal channel
int TextEditPane::BuildSerializedFormatRuns(short start,
                                             short end,
                                             void **outPayload) const // 0x591d60
{
    if (outPayload == NULL || end <= start) {
        if (outPayload != NULL) *outPayload = NULL;
        return 0;
    }
    const short first = GetFormatRunIndexForTextOffset(start);
    const short last = GetFormatRunIndexForTextOffset(end - 1);
    const unsigned short count = static_cast<unsigned short>(last - first + 1);
    const int words = 2 + count * 8;
    unsigned short *payload = static_cast<unsigned short *>(
        GetMemoryMan()->AllocateBufferMemory(words * sizeof(unsigned short)));
    payload[0] = count;
    payload[1] = 0;
    for (short runIndex = first; runIndex <= last; ++runIndex) {
        const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
            m_formatRuns->GetElementAt(runIndex));
        const TextEditFormatRecord *record =
            static_cast<const TextEditFormatRecord *>(
                m_formatTable->GetElementAt(run->formatIndex));
        unsigned short *entry = payload + 2 + (runIndex - first) * 8;
        const short relativeStart = static_cast<short>(run->startIndex - start);
        entry[0] = relativeStart < 0 ? 0 : relativeStart;
        entry[1] = 0;
        entry[2] = record->format.legacyAssetMode;
        entry[3] = 0;
        *reinterpret_cast<unsigned int *>(entry + 4) = record->format.textColor;
        *reinterpret_cast<TextEditObject **>(entry + 6) = relativeStart < 0
            ? NULL : record->format.object;
    }
    *outPayload = payload;
    return words * sizeof(unsigned short);
}
// CPP@00591EC0 | UID0000OJ accepted formal channel
void TextEditPane::LoadCurrentFormat()                          // 0x591ec0
{
    const short offset = m_selectionStart > 0 ? m_selectionStart - 1 : 0;
    const short runIndex = GetFormatRunIndexForTextOffset(offset);
    const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
        m_formatRuns->GetElementAt(runIndex));
    m_currentFormat = static_cast<const TextEditFormatRecord *>(
        m_formatTable->GetElementAt(run->formatIndex))->format;
    m_currentFormatValid = true;
}
// CPP@00591F20 | UID0000OJ accepted formal channel
void TextEditPane::CopyFormatFields(TextRunFormatData *target,
                                    const TextRunFormatData *source,
                                    unsigned short mask)         // 0x591f20
{
    if ((mask & 1) != 0) target->legacyAssetMode = source->legacyAssetMode;
    if ((mask & 2) != 0) target->textColor = source->textColor;
    if ((mask & 4) != 0) target->object = source->object;
}
// CPP@00591F60 | UID0000OJ accepted formal channel
void TextEditPane::GetRangeFormat(short start,
                                  short end,
                                  unsigned short *mask,
                                  TextRunFormatData *format) const // 0x591f60
{
    unsigned short remaining = *mask;
    short runIndex = GetFormatRunIndexForTextOffset(start);
    const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
        m_formatRuns->GetElementAt(runIndex));
    const TextEditFormatRecord *record =
        static_cast<const TextEditFormatRecord *>(
            m_formatTable->GetElementAt(run->formatIndex));
    CopyFormatFields(format, &record->format, remaining);
    while (remaining != 0 && run[1].startIndex < end) {
        run = static_cast<const TextEditFormatRun *>(
            m_formatRuns->GetElementAt(++runIndex));
        record = static_cast<const TextEditFormatRecord *>(
            m_formatTable->GetElementAt(run->formatIndex));
        if ((remaining & 1) != 0 &&
            record->format.legacyAssetMode != format->legacyAssetMode)
            remaining &= ~1;
        if ((remaining & 2) != 0 &&
            record->format.textColor != format->textColor)
            remaining &= ~2;
    }
    *mask = remaining;
}
// CPP@00592040 | UID0000OJ accepted formal channel
void TextEditPane::GetFormatSpanForRun(short runIndex,
                                       TextEditFormatSpan *span) const // 0x592040
{
    const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
        m_formatRuns->GetElementAt(runIndex));
    span->start = run->startIndex;
    span->end = run->endIndex;
    span->format = static_cast<const TextEditFormatRecord *>(
        m_formatTable->GetElementAt(run->formatIndex))->format;
}
// CPP@00592090 | UID0000OJ accepted formal channel
void TextEditPane::ApplySerializedFormatRuns(short start,
                                             short end,
                                             const unsigned short *payload) // 0x592090
{
    if (payload == NULL || payload[0] == 0)
        return;
    const unsigned short count = payload[0];
    const unsigned short *entry = payload + 2;
    for (unsigned short index = 0; index < count; ++index, entry += 8) {
        const short runStart = static_cast<short>(start + entry[0]);
        const short runEnd = index + 1 < count
            ? static_cast<short>(start + entry[8]) : end;
        TextRunFormatData format;
        format.legacyAssetMode = entry[2];
        format.textColor = *reinterpret_cast<const unsigned int *>(entry + 4);
        format.object = *reinterpret_cast<TextEditObject *const *>(entry + 6);
        ApplyFormatRange(runStart, runEnd, kTextEditCompleteFormatMask, &format);
    }
}
// CPP@00592440 | UID0000OJ accepted formal channel
void TextEditPane::SetEmbeddedObjectAt(short textOffset,
                                       TextEditObject *object)  // 0x592440
{
    TextRunFormatData format = { 0, 0, object };
    ApplyFormatRange(textOffset, static_cast<short>(textOffset + 1),
                     4, &format);
}
// CPP@00592470 | UID0000OJ accepted formal channel
void TextEditPane::ApplyFormatRange(short start,
                                    short end,
                                    unsigned char formatMask,
                                    const TextRunFormatData *format) // 0x592470
{
    if (format == NULL || end <= start)
        return;
    short firstRun = GetFormatRunIndexForTextOffset(start);
    short lastRun = GetFormatRunIndexForTextOffset(end - 1);
    for (short runIndex = firstRun; runIndex <= lastRun; ++runIndex) {
        TextEditFormatRun *run = static_cast<TextEditFormatRun *>(
            m_formatRuns->GetElementAt(runIndex));
        TextEditFormatRecord *oldRecord = static_cast<TextEditFormatRecord *>(
            m_formatTable->GetElementAt(run->formatIndex));
        TextRunFormatData merged = oldRecord->format;
        CopyFormatFields(&merged, format, formatMask);
        short newIndex;
        FindOrCreateFormatRecord(merged, &newIndex);
        if (newIndex != run->formatIndex) {
            if (oldRecord->referenceCount > 0) --oldRecord->referenceCount;
            ++static_cast<TextEditFormatRecord *>(
                m_formatTable->GetElementAt(newIndex))->referenceCount;
            run->formatIndex = newIndex;
        }
    }
    m_currentFormatValid = false;
    RefreshTextRange(start, end);
}
// CPP@005927E0 | UID0000OJ accepted formal channel
void TextEditPane::DeleteFormatRange(short start, short end)    // 0x5927e0
{
    short first = GetFormatRunIndexForTextOffset(start);
    short last = GetFormatRunIndexForTextOffset(end) - 1;
    while (last > first)
        RemoveFormatRun(last--);
    for (short index = static_cast<short>(first + 1);
         index < m_formatRuns->GetCount(); ++index) {
        TextEditFormatRun *run = static_cast<TextEditFormatRun *>(
            m_formatRuns->GetElementAt(index));
        run->startIndex = static_cast<unsigned short>(
            run->startIndex - (end - start));
    }
}
// CPP@005929A0 | UID0000OJ accepted formal channel
void TextEditPane::FindOrCreateFormatRecord(
    const TextRunFormatData &format, short *formatIndex)         // 0x5929a0
{
    short freeIndex = -1;
    for (short index = 0; index < m_formatTable->GetCount(); ++index) {
        TextEditFormatRecord *record = static_cast<TextEditFormatRecord *>(
            m_formatTable->GetElementAt(index));
        if (record->referenceCount == 0) {
            if (freeIndex < 0) freeIndex = index;
            continue;
        }
        if (record->format.legacyAssetMode == format.legacyAssetMode &&
            record->format.textColor == format.textColor &&
            record->format.object == format.object)
        {
            *formatIndex = index;
            return;
        }
    }
    TextEditFormatRecord record;
    record.referenceCount = 0;
    record.format = format;
    if (freeIndex < 0) {
        m_formatTable->Append(1, &record);
        freeIndex = static_cast<short>(m_formatTable->GetCount() - 1);
    } else {
        *static_cast<TextEditFormatRecord *>(
            m_formatTable->GetElementAt(freeIndex)) = record;
    }
    *formatIndex = freeIndex;
}
// CPP@00592A80 | UID0000OJ accepted formal channel
bool TextEditPane::IsBoundaryFormatRun(short runIndex) const    // 0x592a80
{
    return runIndex < 2;
}
// CPP@00592A90 | UID0000OJ accepted formal channel
bool TextEditPane::IsLeadingFormatRun(unsigned char flags) const // 0x592a90
{
    return (flags & 1) == 0;
}
// CPP@00592AA0 | UID0000OJ accepted formal channel
void TextEditPane::InsertFormatRun(short runIndex,
                                   short textOffset,
                                   short formatIndex)            // 0x592aa0
{
    TextEditFormatRun run;
    run.startIndex = textOffset;
    run.formatIndex = formatIndex;
    m_formatRuns->InsertAt(runIndex + 1, 1, &run);
    ++static_cast<TextEditFormatRecord *>(
        m_formatTable->GetElementAt(formatIndex))->referenceCount;
}
// CPP@00592AF0 | UID0000OJ accepted formal channel
void TextEditPane::SetFormatRunRecord(short runIndex,
                                      short formatIndex,
                                      bool preserveOldObject)   // 0x592af0
{
    TextEditFormatRun *run = static_cast<TextEditFormatRun *>(
        m_formatRuns->GetElementAt(runIndex));
    const short oldFormatIndex = run->formatIndex;
    run->formatIndex = formatIndex;
    TextEditFormatRecord *oldRecord = static_cast<TextEditFormatRecord *>(
        m_formatTable->GetElementAt(oldFormatIndex));
    TextEditFormatRecord *newRecord = static_cast<TextEditFormatRecord *>(
        m_formatTable->GetElementAt(formatIndex));
    ++newRecord->referenceCount;
    --oldRecord->referenceCount;
    if (!preserveOldObject && oldRecord->format.object != NULL &&
        oldRecord->format.object != newRecord->format.object) {
        delete oldRecord->format.object;
    }
}
// CPP@00592B60 | UID0000OJ accepted formal channel
void TextEditPane::RemoveFormatRun(short runIndex)              // 0x592b60
{
    TextEditFormatRun *run = static_cast<TextEditFormatRun *>(
        m_formatRuns->GetElementAt(runIndex));
    TextEditFormatRecord *record = static_cast<TextEditFormatRecord *>(
        m_formatTable->GetElementAt(run->formatIndex));
    if (record->referenceCount > 0)
        --record->referenceCount;
    if (record->referenceCount == 0 && record->format.object != NULL) {
        delete record->format.object;
        record->format.object = NULL;
    }
    m_formatRuns->RemoveAt(runIndex, 1);
}

// UID:0004T2 | by-memory/0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY.md | Completion:92 | Confidence:94
// CPP@00592BB0 | UID0000OJ accepted formal channel
short TextEditPane::GetLineIndexForY(int y) const
{
    short low = 0;
    short high = static_cast<short>(m_lineTable->GetCount() - 1);
    short lineIndex = 0;

    if (high <= 0)
        return 0;

    do {
        lineIndex = static_cast<short>((low + high) / 2);
        const TextEditLineRecord *line =
            static_cast<const TextEditLineRecord *>(
                m_lineTable->GetElementAt(lineIndex));
        if (line->top > y) {
            high = lineIndex;
        } else if (y < line[1].top) {
            return lineIndex;
        } else {
            low = static_cast<short>(lineIndex + 1);
        }
    } while (low < high);

    return lineIndex;
}

// UID:00056I | by-memory/0x00592c20-0x005934d2.TextEditPaneLineTableAndOffsets.md | Completion:94 | Confidence:94
// CPP@00592C20 | UID0000OJ accepted formal channel
void TextEditPane::RebuildLineTable(short *firstLine,
                                    short *lastLine)             // 0x592c20
{
    const short textLength = GetTextLength();
    m_lineTable->RemoveAll();
    TextEditLineRecord line;
    line.startIndex = 0;
    line.top = 0;
    line.remainingWidth = m_textAreaRight - m_textAreaLeft;
    line.wrapState = 0;
    m_lineTable->Append(1, &line);
    short offset = 0;
    while (offset < textLength && m_lineTable->GetCount() <= m_maxLines) {
        short next = MeasureLineBreak(offset);
        if (next <= offset) ++next;
        line.startIndex = next;
        line.top += GetLineHeight();
        line.remainingWidth = m_textAreaRight - m_textAreaLeft;
        line.wrapState = 0;
        m_lineTable->Append(1, &line);
        offset = next;
    }
    if (m_lineTable->GetCount() == 1) {
        line.startIndex = textLength;
        line.top = GetLineHeight();
        m_lineTable->Append(1, &line);
    }
    if (firstLine != NULL) *firstLine = 0;
    if (lastLine != NULL)
        *lastLine = static_cast<short>(m_lineTable->GetCount() - 2);
    m_scrollRangeDirty = true;
}
// CPP@00592EC0 | UID0000OJ accepted formal channel
void TextEditPane::MeasureLineRange(short firstLine,
                                    short lastLine)              // 0x592ec0
{
    TextRunMeasureState state = {
        m_textAreaRight - m_textAreaLeft,
        m_textAreaRight - m_textAreaLeft,
        0
    };
    IterateTextRuns(firstLine, lastLine, TextRunMeasureCallback, &state);
}
// CPP@00592F10 | UID0000OJ accepted formal channel
void TextEditPane::InsertLineRecord(short lineIndex,
                                    const TextEditLineRecord &line) // 0x592f10
{
    TextEditLineRecord copy = line;
    m_lineTable->InsertAt(lineIndex, 1, &copy);
}
// CPP@00592F30 | UID0000OJ accepted formal channel
void TextEditPane::RemoveLineRecord(short lineIndex)            // 0x592f30
{
    m_lineTable->RemoveAt(lineIndex, 1);
}
// CPP@00592F50 | UID0000OJ accepted formal channel
void TextEditPane::DeleteLineRecordsForRange(short start,
                                              short end)         // 0x592f50
{
    const short firstLine = static_cast<short>(
        GetLineIndexForTextOffset(start) + 1);
    const short lastLine = GetLineIndexForTextOffset(end);
    const short removeCount = static_cast<short>(lastLine - firstLine + 1);
    if (removeCount > 0)
        m_lineTable->RemoveAt(firstLine, removeCount);
    ShiftLineOffsets(firstLine, static_cast<short>(start - end));
}
// CPP@00592FB0 | UID0000OJ accepted formal channel
short TextEditPane::MeasureLineBreak(short textOffset)          // 0x592fb0
{
    const short length = GetTextLength();
    if (textOffset >= length)
        return length;
    int remainingWidth = m_textAreaRight - m_textAreaLeft;
    signed char hitPart = 0;
    const short count = MeasureTextRunWrapSegment(
        GetTextBuffer() + textOffset,
        static_cast<short>(length - textOffset),
        0, &remainingWidth, &hitPart, 0, 0);
    return static_cast<short>(textOffset + (count > 0 ? count : 1));
}
// CPP@005931E0 | UID0000OJ accepted formal channel
void TextEditPane::InsertTextStorage(short textOffset,
                                     const wchar_t *text,
                                     short length)               // 0x5931e0
{
    if (length <= 0)
        return;
    m_textStorage->InsertAt(textOffset, length,
                            const_cast<wchar_t *>(text));
    ShiftLineOffsets(static_cast<short>(
        GetLineIndexForTextOffset(textOffset) + 1), length);
    ShiftFormatRunOffsets(static_cast<short>(
        GetFormatRunIndexForTextOffset(textOffset - 1) + 1), length);
    ApplyFormatRange(textOffset, static_cast<short>(textOffset + length),
                     m_currentFormatValid ? 7 : 4, &m_currentFormat);
}
// CPP@00593280 | UID0000OJ accepted formal channel
void TextEditPane::DeleteTextRange(short start, short end)      // 0x593280
{
    start = ClampNavigationIndex(start, 0, GetTextLength());
    end = ClampNavigationIndex(end, 0, GetTextLength());
    NormalizeTextRange(&start, &end);
    if (end <= start)
        return;
    const short removed = static_cast<short>(end - start);
    DeleteFormatRange(start, end);
    m_textStorage->RemoveAt(start, removed);
    ShiftLineOffsets(static_cast<short>(
        GetLineIndexForTextOffset(start) + 1), -removed);
    ShiftFormatRunOffsets(static_cast<short>(
        GetFormatRunIndexForTextOffset(start) + 1), -removed);
    m_dirty = true;
    m_currentFormatValid = false;
    RebuildAllLines();
    RefreshTextRange(start, end);
}
// CPP@005933C0 | UID0000OJ accepted formal channel
void TextEditPane::OffsetLinePositions(short firstLine,
                                       int delta)                 // 0x5933c0
{
    for (short lineIndex = firstLine;
         lineIndex < m_lineTable->GetCount(); ++lineIndex) {
        TextEditLineRecord *line = static_cast<TextEditLineRecord *>(
            m_lineTable->GetElementAt(lineIndex));
        line->top += delta;
    }
}
// CPP@00593400 | UID0000OJ accepted formal channel
void TextEditPane::ShiftLineOffsets(short firstLine,
                                    short delta)                 // 0x593400
{
    for (short index = firstLine; index < m_lineTable->GetCount(); ++index)
        static_cast<TextEditLineRecord *>(
            m_lineTable->GetElementAt(index))->startIndex += delta;
}
// CPP@00593450 | UID0000OJ accepted formal channel
void TextEditPane::ShiftFormatRunOffsets(short firstRun,
                                         short delta)            // 0x593450
{
    for (short index = firstRun; index < m_formatRuns->GetCount(); ++index)
        static_cast<TextEditFormatRun *>(
            m_formatRuns->GetElementAt(index))->startIndex += delta;
}
// CPP@005934A0 | UID0000OJ accepted formal channel
int TextEditPane::GetLineAlignmentOffset(
    const TextEditLineRecord *line) const                        // 0x5934a0
{
    if (m_textAlignment == 1) return line->remainingWidth / 2;
    if (m_textAlignment == 2) return line->remainingWidth;
    return 0;
}

// UID:00056J | by-memory/0x005934e0-0x005934ff.IsTextOffsetInRange.md | Completion:94 | Confidence:94
// CPP@005934E0 | UID0000OJ accepted formal channel
bool IsTextOffsetInRange(short textOffset,
                         short,
                         short rangeStart,
                         short rangeEnd)                         // 0x5934e0
{
    return rangeStart <= textOffset && textOffset < rangeEnd;
}

// UID:00056K | by-memory/0x00593500-0x005936d9.TextEditPaneIterateTextRuns.md | Completion:94 | Confidence:94
// CPP@00593500 | UID0000OJ accepted formal channel
void TextEditPane::IterateTextRuns(short firstLine,
                                   short lastLine,
                                   TextRunIteratorCallback callback,
                                   void *context)                // 0x593500
{
    if (callback == NULL)
        return;
    firstLine = ClampNavigationIndex(firstLine, 0, GetLineCount());
    lastLine = ClampNavigationIndex(lastLine, firstLine, GetLineCount());
    for (short lineIndex = firstLine; lineIndex <= lastLine; ++lineIndex) {
        TextEditLineRecord *line = static_cast<TextEditLineRecord *>(
            m_lineTable->GetElementAt(lineIndex));
        const TextEditLineRecord *next = static_cast<const TextEditLineRecord *>(
            m_lineTable->GetElementAt(lineIndex + 1));
        short offset = line->startIndex;
        const short lineEnd = next->startIndex;
        while (offset < lineEnd) {
            const short runIndex = GetFormatRunIndexForTextOffset(offset);
            const TextEditFormatRun *run = static_cast<const TextEditFormatRun *>(
                m_formatRuns->GetElementAt(runIndex));
            const TextEditFormatRun *nextRun =
                static_cast<const TextEditFormatRun *>(
                    m_formatRuns->GetElementAt(runIndex + 1));
            const short segmentEnd = nextRun->startIndex < lineEnd
                ? nextRun->startIndex : lineEnd;
            const TextEditFormatRecord *record =
                static_cast<const TextEditFormatRecord *>(
                    m_formatTable->GetElementAt(run->formatIndex));
            unsigned short flags = 0;
            if (offset > line->startIndex) flags |= 2;
            if (segmentEnd < lineEnd) flags |= 1;
            if (callback(line, &record->format, GetTextBuffer() + offset,
                         offset, static_cast<unsigned short>(segmentEnd - offset),
                         flags, context, this))
                return;
            offset = segmentEnd;
        }
    }
}

// UID:00056L | by-memory/0x005936e0-0x00593875.TextRunHitTestCallback.md | Completion:94 | Confidence:94
// CPP@005936E0 | UID0000OJ accepted formal channel
bool __cdecl TextRunHitTestCallback(TextEditLineRecord *line,
                                    const TextRunFormatData *format,
                                    const wchar_t *text,
                                    int textOffset,
                                    unsigned short charCount,
                                    unsigned short segmentFlags,
                                    void *context,
                                    TextEditPane *pane)          // 0x5936e0
{
    return pane->HitTestRunSegment(
        line, format, text, textOffset, charCount, segmentFlags,
        static_cast<TextRunHitState *>(context));
}

// UID:00056M | by-memory/0x00593880-0x00593a11.TextEditPaneHitTestRunSegment.md | Completion:94 | Confidence:94
// CPP@00593880 | UID0000OJ accepted formal channel
bool TextEditPane::HitTestRunSegment(TextEditLineRecord *line,
                                     const TextRunFormatData *format,
                                     const wchar_t *text,
                                     int textOffset,
                                     unsigned short charCount,
                                     unsigned short segmentFlags,
                                     TextRunHitState *state)      // 0x593880
{
    if (segmentFlags <= 1)
        state->remainingWidth -= GetLineAlignmentOffset(line);
    const int previousWidth = state->remainingWidth;
    if (state->remainingWidth <= 0) {
        state->textOffset = static_cast<short>(textOffset);
        state->hitPart = -1;
        return true;
    }
    if (format->object != NULL) {
        const int width = format->object->m_payload1;
        if (state->remainingWidth < width) {
            state->textOffset = static_cast<short>(textOffset + 1);
            state->hitPart = state->remainingWidth < width / 2 ? -1 : 0;
            return true;
        }
        state->remainingWidth -= width;
        state->consumedWidth += previousWidth - state->remainingWidth;
        if (state->remainingWidth <= 0) {
            state->textOffset = static_cast<short>(textOffset + 1);
            state->hitPart = previousWidth < width / 4 ? -1 : 2;
            return true;
        }
        return false;
    }
    if ((segmentFlags & 1) == 0 && charCount != 0) {
        const wchar_t last = text[charCount - 1];
        if (last == L'\t' || last == L'\r' || last == L'\n' || last == L' ')
            --charCount;
    }
    signed char part = 0;
    const short count = MeasureTextRunWrapSegment(
        text, charCount, textOffset, &state->remainingWidth,
        &part, segmentFlags, state->consumedWidth);
    state->textOffset = static_cast<short>(
        textOffset + (count > 0 ? count - 1 : 0));
    state->hitPart = part;
    state->consumedWidth += previousWidth - state->remainingWidth;
    return state->remainingWidth <= 0;
}

// UID:00056N | by-memory/0x00593a20-0x00593b12.TextRunOffsetMeasureCallback.md | Completion:94 | Confidence:94
// CPP@00593A20 | UID0000OJ accepted formal channel
bool __cdecl TextRunOffsetMeasureCallback(TextEditLineRecord *line,
                                          const TextRunFormatData *format,
                                          const wchar_t *text,
                                          int textOffset,
                                          unsigned short charCount,
                                          unsigned short segmentFlags,
                                          void *context,
                                          TextEditPane *pane)    // 0x593a20
{
    return pane->MeasureRunToOffset(
        line, format, text, textOffset, charCount, segmentFlags,
        static_cast<TextRunOffsetState *>(context));
}

// UID:00056O | by-memory/0x00593b20-0x00593c1c.TextEditPaneMeasureRunToOffset.md | Completion:94 | Confidence:94
// CPP@00593B20 | UID0000OJ accepted formal channel
bool TextEditPane::MeasureRunToOffset(TextEditLineRecord *line,
                                      const TextRunFormatData *format,
                                      const wchar_t *text,
                                      int textOffset,
                                      unsigned short charCount,
                                      unsigned short segmentFlags,
                                      TextRunOffsetState *state) // 0x593b20
{
    const short relative = static_cast<short>(state->targetOffset - textOffset);
    const bool containsTarget = relative >= 0 && relative < charCount;
    if (segmentFlags <= 1)
        state->point.x += GetLineAlignmentOffset(line);
    if (format->object != NULL) {
        if (!containsTarget)
            state->point.x += format->object->m_payload1;
        return containsTarget;
    }
    const short measuredCount = relative < charCount ? relative : charCount;
    state->point.x += m_maskedText
        ? GetTextWidth(L"*", 1) * measuredCount
        : GetTextWidth(text, measuredCount);
    return containsTarget;
}

// UID:0001JQ | by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md | Completion:91 | Confidence:94
// CPP@00593C20 | UID0000OJ accepted formal channel
enum TextRunSegmentFlags
{
    kTextRunHasNextSegment = 0x01,
    kTextRunHasPreviousSegment = 0x02
};

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane)
{
    (void)textOffset;
    TextRunMeasureState *state =
        static_cast<TextRunMeasureState *>(context);

    int visibleCount = charCount;
    if (segmentFlags <= kTextRunHasNextSegment) {
        state->remainingWidth = state->availableWidth;
        state->scratch = 0;
    }

    int runWidth = 0;
    if (format->object != NULL) {
        runWidth = format->object->m_payload1;
    } else {
        if ((segmentFlags & kTextRunHasNextSegment) == 0) {
            visibleCount = pane->AdjustVisibleCountForTrailingWhitespace(
                text, static_cast<short>(visibleCount));
        }

        if (pane->m_maskedText)
            runWidth = visibleCount * pane->GetTextWidth(L"*", 1);
        else
            runWidth = pane->GetTextWidth(text, visibleCount);
    }

    state->remainingWidth -= runWidth;
    if ((segmentFlags & kTextRunHasNextSegment) == 0) {
        if (state->remainingWidth < 0)
            state->remainingWidth = 0;
        line->remainingWidth = state->remainingWidth;
        line->wrapState = 0;
    }

    return false;
}

// UID:0003FC | by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md | Completion:92 | Confidence:93
// CPP@00593CF0 | UID0003FC source-quality repair
bool TextEditPane::MeasureTextRunSegment(TextEditLineRecord *line,
                                         const TextRunFormatData *format,
                                         const wchar_t *text,
                                         int textOffset,
                                         unsigned short charCount,
                                         unsigned short segmentFlags,
                                         TextRunMeasureState *state)
{
    (void)textOffset;

    int visibleCount = charCount;
    if (segmentFlags <= kTextRunHasNextSegment) {
        state->remainingWidth = state->availableWidth;
        state->scratch = 0;
    }

    int runWidth = 0;
    if (format->object != NULL) {
        runWidth = format->object->m_payload1;
    } else {
        if ((segmentFlags & kTextRunHasNextSegment) == 0) {
            visibleCount = AdjustVisibleCountForTrailingWhitespace(
                text, static_cast<short>(visibleCount));
        }

        if (m_maskedText)
            runWidth = visibleCount * GetTextWidth(L"*", 1);
        else
            runWidth = GetTextWidth(text, visibleCount);
    }

    state->remainingWidth -= runWidth;
    if ((segmentFlags & kTextRunHasNextSegment) == 0) {
        if (state->remainingWidth < 0)
            state->remainingWidth = 0;
        line->remainingWidth = state->remainingWidth;
        line->wrapState = 0;
    }

    return false;
}

// UID:0001JR | by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md | Completion:92 | Confidence:94
// CPP@00593DB0 | UID0000OJ accepted formal channel
enum TextEditPaneTextAlignment
{
    kTextEditAlignLeft = 0,
    kTextEditAlignCenter = 1,
    kTextEditAlignRight = 2,
    kTextEditAlignTrimFinalWhitespace = 3
};

static bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                        const TextRunFormatData *format,
                                        const wchar_t *text,
                                        int textOffset,
                                        unsigned short charCount,
                                        unsigned short segmentFlags,
                                        void *context,
                                        TextEditPane *pane)
{
    (void)textOffset;
    TextRunDrawState *state = static_cast<TextRunDrawState *>(context);
    unsigned short visibleCount = charCount;

    if (segmentFlags <= kTextRunHasNextSegment) {
        state->lineRect.left = pane->m_textAreaLeft;
        state->lineRect.top = pane->m_textAreaTop + line->top;
        state->lineRect.right = pane->m_textAreaRight;
        state->lineRect.bottom = pane->m_textAreaTop + line[1].top;

        pane->GetClipRect(&state->clippedLineRect);
        IntersectRects(&state->clippedLineRect,
                       &state->lineRect,
                       &state->clippedLineRect);

        const unsigned int oldDrawColor = pane->m_drawColor;
        pane->m_drawMode = 0;
        pane->SetDrawColor((pane->m_editorFlags & kTextEditBlackBackground) == 0
                               ? pane->m_textBackColor
                               : 0);
        g_pfnFillRect(pane, &state->clippedLineRect);
        pane->SetDrawColor(oldDrawColor);

        int horizontalOffset = 0;
        if (pane->m_textAlignment == kTextEditAlignCenter)
            horizontalOffset = line->remainingWidth / 2;
        else if (pane->m_textAlignment == kTextEditAlignRight)
            horizontalOffset = line->remainingWidth;

        pane->MoveTo(state->lineRect.left + horizontalOffset,
                     state->lineRect.top + pane->GetLineHeight());
    }

    if (state->applyRunTextColor)
        pane->SetTextColor(format->textColor);

    if (format->object != NULL) {
        format->object->OnUpdate();
        return false;
    }

    if (pane->m_textAlignment == kTextEditAlignTrimFinalWhitespace &&
        (segmentFlags & kTextRunHasNextSegment) == 0) {
        visibleCount = pane->AdjustVisibleCountForTrailingWhitespace(
            text, static_cast<short>(visibleCount));
    }

    pane->DrawTextRunSegment(text, visibleCount, 0, segmentFlags);
    return false;
}

// UID:0003FD | by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md | Completion:85 | Confidence:88
// CPP@00593F00 | UID0000OJ accepted formal channel
bool TextEditPane::DrawTextRunSegment(TextEditLineRecord *line,
                                      const TextRunFormatData *format,
                                      const wchar_t *text,
                                      int,
                                      unsigned short charCount,
                                      unsigned short segmentFlags,
                                      TextRunDrawState *state)   // 0x593f00
{
    if (segmentFlags <= 1) {
        state->lineRect.left = m_textAreaLeft;
        state->lineRect.top = m_textAreaTop + line->top;
        state->lineRect.right = m_textAreaRight;
        state->lineRect.bottom = m_textAreaTop + line[1].top;
        GetClipRect(&state->clippedLineRect);
        IntersectRects(&state->clippedLineRect, &state->lineRect,
                       &state->clippedLineRect);
        FillTextBackground(&state->clippedLineRect);
        MoveTo(state->lineRect.left + GetLineAlignmentOffset(line),
               state->lineRect.top + GetLineHeight());
    }
    if (state->applyRunTextColor)
        SetTextColor(format->textColor);
    if (format->object != NULL)
        format->object->OnUpdate();
    else {
        short visibleCount = static_cast<short>(charCount);
        if (m_textAlignment == 3 && (segmentFlags & 1) == 0)
            visibleCount = AdjustVisibleCountForTrailingWhitespace(
                text, visibleCount);
        DrawTextCharacters(text, visibleCount, 0, segmentFlags);
    }
    return false;
}

// UID:0004U3 | by-memory/0x00594040-0x00594116.TextEditPaneHandleNavigationKey.md | Completion:92 | Confidence:94
// CPP@00594040 | UID0000OJ accepted formal channel
void TextEditPane::HandleNavigationKey(Event *event)
{
    unsigned char modifiers = event->m_payload.m_key.m_modifiers;
    unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key, modifiers);
    short start = m_selectionStart;
    short end = m_selectionEnd;

    if ((modifiers & kEventModifierShift) != 0)
    {
        short fixed = m_selectionReversed ? end : start;
        short moving = m_selectionReversed ? start : end;
        SetSelectionRange(fixed, GetNavigationCaretIndex(event, moving));
        return;
    }

    if (start != end)
    {
        short caret = (key == kPaneKeyLeft || key == kPaneKeyUp)
            ? start : end;
        SetSelectionRange(caret, caret);
        return;
    }

    short caret = GetNavigationCaretIndex(event, start);
    SetSelectionRange(caret, caret);
}

// UID:0004U5 | by-memory/0x00594120-0x00594190.TextEditPaneDeleteSelectionOrBackspace.md | Completion:92 | Confidence:94
// CPP@00594120 | UID0000OJ accepted formal channel
void TextEditPane::DeleteSelectionOrBackspace()
{
    if ((m_editorFlags & kTextEditReadOnly) != 0)
        return;

    short start = m_selectionStart;
    short end = m_selectionEnd;
    if (start != end)
    {
        DeleteTextRange(start, end);
        m_selectionStart = start;
        m_selectionEnd = start;
        RefreshTextRange(start, end);
        return;
    }

    if (start > 0)
    {
        DeleteTextRange(start - 1, start);
        --start;
        m_selectionStart = start;
        m_selectionEnd = start;
        RefreshTextRange(start, start + 1);
    }
}

// UID:00056P | by-memory/0x00594190-0x005941e3.TextEditPaneDeleteForwardCharacter.md | Completion:94 | Confidence:94
// CPP@00594190 | UID0000OJ accepted formal channel
// UID0001JS navigation/wrap source closure.
void TextEditPane::DeleteForwardCharacter()                     // 0x594190
{
    if ((m_editorFlags & kTextEditReadOnly) != 0)
        return;
    short start = m_selectionStart;
    short end = m_selectionEnd;
    if (start == end) {
        if (start == GetTextLength())
            return;
        end = static_cast<short>(start + 1);
    }
    DeleteTextRange(start, end);
    m_selectionStart = start;
    m_selectionEnd = start;
    RefreshTextRange(start, start);
}

// UID:0004U7 | by-memory/0x005941f0-0x00594658.TextEditPaneGetNavigationCaretIndex.md | Completion:91 | Confidence:93
// CPP@005941F0 | UID0000OJ accepted formal channel
enum TextNavigationAction
{
    kTextNavigationCharacterLeft = 0,
    kTextNavigationCharacterRight = 1,
    kTextNavigationVisualUp = 2,
    kTextNavigationVisualDown = 3,
    kTextNavigationWordLeft = 4,
    kTextNavigationWordRight = 5,
    kTextNavigationPageUp = 6,
    kTextNavigationPageDown = 7,
    kTextNavigationLineStart = 8,
    kTextNavigationLineEnd = 9,
    kTextNavigationDocumentStart = 10,
    kTextNavigationDocumentEnd = 11
};

short TextEditPane::GetNavigationCaretIndex(Event *event,
                                             short caretIndex) const
{
    unsigned char modifiers = event->m_payload.m_key.m_modifiers;
    unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key, modifiers);
    int action = key - kPaneKeyLeft;
    if ((modifiers & kEventModifierControl) != 0)
        action += 4;
    if ((modifiers & kEventModifierAlt) != 0)
        action += 8;

    short textLength = GetTextLength();
    if (action == kTextNavigationCharacterLeft)
        return caretIndex > 0 ? caretIndex - 1 : 0;
    if (action == kTextNavigationCharacterRight)
        return caretIndex < textLength ? caretIndex + 1 : textLength;

    if (action == kTextNavigationVisualUp
        || action == kTextNavigationVisualDown)
    {
        Point point;
        GetCaretLocalPoint(&point, caretIndex);
        point.y += action == kTextNavigationVisualUp
            ? -GetLineHeight() : GetLineHeight();
        signed char hitPart = 0;
        return GetTextOffsetAtPoint(point.y, point.x, &hitPart);
    }

    if (action == kTextNavigationWordLeft
        || action == kTextNavigationWordRight)
    {
        TextEditRange range;
        ::FindWordBoundary(
            static_cast<const wchar_t *>(m_textStorage->GetData(0)),
            textLength,
            caretIndex,
            action == kTextNavigationWordRight,
            &range);
        return action == kTextNavigationWordRight ? range.end : range.start;
    }

    if (action == kTextNavigationPageUp
        || action == kTextNavigationPageDown)
    {
        Point point;
        GetCaretLocalPoint(&point, caretIndex);
        int lineHeight = GetLineHeight();
        int targetY;

        if (action == kTextNavigationPageUp)
        {
            targetY = m_contentRect.top;
            signed char hitPart = 0;
            short result = GetTextOffsetAtPoint(targetY, point.x, &hitPart);
            if (point.y < m_contentRect.top)
                result = GetTextOffsetAtPoint(targetY + lineHeight,
                                              point.x, &hitPart);
            if (result != caretIndex)
                return result;

            int pageHeight = m_contentRect.bottom - m_contentRect.top
                - lineHeight;
            targetY = m_contentRect.top - pageHeight;
            result = GetTextOffsetAtPoint(targetY, point.x, &hitPart);
            if (point.y < targetY)
                result = GetTextOffsetAtPoint(targetY + lineHeight,
                                              point.x, &hitPart);
            return result;
        }

        targetY = m_contentRect.bottom;
        signed char hitPart = 0;
        short result = GetTextOffsetAtPoint(targetY, point.x, &hitPart);
        if (m_contentRect.bottom < point.y + lineHeight)
            result = GetTextOffsetAtPoint(targetY - lineHeight,
                                          point.x, &hitPart);
        if (result != caretIndex)
            return result;

        int pageHeight = m_contentRect.bottom - m_contentRect.top - lineHeight;
        targetY = m_contentRect.bottom + pageHeight;
        result = GetTextOffsetAtPoint(targetY, point.x, &hitPart);
        if (pageHeight + m_scrollContentRect.bottom < point.y + lineHeight)
            result = GetTextOffsetAtPoint(targetY - lineHeight,
                                          point.x, &hitPart);
        return result;
    }

    if (action == kTextNavigationLineStart
        || action == kTextNavigationLineEnd)
    {
        short lineIndex = GetLineIndexForTextOffset(caretIndex);
        TextEditLineRecord *line = static_cast<TextEditLineRecord *>(
            m_lineTable->GetElementAt(lineIndex));
        if (action == kTextNavigationLineStart)
            return line->startIndex;

        if (lineIndex + 1 >= GetLineCount())
            return textLength;
        TextEditLineRecord *nextLine = static_cast<TextEditLineRecord *>(
            m_lineTable->GetElementAt(lineIndex + 1));
        return nextLine->startIndex < textLength
            ? nextLine->startIndex - 1 : textLength;
    }

    if (action == kTextNavigationDocumentStart)
        return 0;
    if (action == kTextNavigationDocumentEnd)
        return textLength;
    return caretIndex;
}

// UID:00056Q | by-memory/0x00594660-0x005946a4.TextNavigationIndexHelpers.md | Completion:94 | Confidence:94
// CPP@00594660 | UID0000OJ accepted formal channel
short ClampNavigationIndex(short value, short minimum,
                           short maximum)                        // 0x594660
{
    if (value < minimum) return minimum;
    if (value > maximum) return maximum;
    return value;
}
// CPP@00594680 | UID0000OJ accepted formal channel
void NormalizeTextRange(short *start, short *end)               // 0x594680
{
    if (*start > *end) {
        const short swap = *start;
        *start = *end;
        *end = swap;
    }
}

// UID:00056R | by-memory/0x005946b0-0x0059489f.TextEditPaneDrawTextCharacters.md | Completion:94 | Confidence:94
// CPP@005946B0 | UID0000OJ accepted formal channel
void TextEditPane::DrawTextCharacters(const wchar_t *text,
                                      short length,
                                      int,
                                      int)                       // 0x5946b0
{
    if (m_maskedText) {
        for (short index = 0; index < length; ++index)
            DrawWideText(L"*", 1);
        return;
    }
    if (m_useThousandsSeparator) {
        wchar_t formatted[256];
        short output = 0;
        for (short index = 0; index < length && output < 255; ++index) {
            if (index != 0 && (length - index) % 3 == 0)
                formatted[output++] = L',';
            formatted[output++] = text[index];
        }
        formatted[output] = L'\0';
        DrawWideText(formatted, output);
        return;
    }
    DrawWideText(text, length);
}

// UID:0004U8 | by-memory/0x005948a0-0x005949be.TextEditPaneMeasureTextRunWrapSegment.md | Completion:91 | Confidence:93
// CPP@005948A0 | UID0000OJ accepted formal channel
short TextEditPane::MeasureTextRunWrapSegment(const wchar_t *text,
                                              short textLength,
                                              int textOffset,
                                              int *remainingWidth,
                                              signed char *hitPart,
                                              unsigned short segmentFlags,
                                              int xOffset) const
{
    (void)textOffset;
    (void)segmentFlags;
    (void)xOffset;

    StringIter iter(text, textLength);
    wchar_t current = iter.GetNextChar();
    wchar_t next = iter.GetNextChar();
    short accepted = 0;
    short previousTotalWidth = 0;

    if (current != 0)
    {
        short totalWidth = 0;
        for (;;)
        {
            short advance = 0;
            g_pFontImageLib->MeasureGlyphWidth(
                m_fontId, current, next, false, 0, 0, &advance, 0);
            totalWidth += advance;
            if (*remainingWidth < totalWidth)
            {
                *hitPart = (totalWidth + previousTotalWidth) / 2
                    < *remainingWidth ? 0 : -1;
                *remainingWidth = -1;
                return accepted;
            }

            ++accepted;
            current = next;
            next = iter.GetNextChar();
            previousTotalWidth = totalWidth;
            if (current == 0)
                break;
        }
    }

    *remainingWidth -= previousTotalWidth;
    *hitPart = 0;
    return accepted + 1;
}

// UID:00056S | by-memory/0x005949c0-0x00594b47.TextEditPaneMeasureNavigationAndWrapBreak.md | Completion:94 | Confidence:94
// CPP@005949C0 | UID0000OJ accepted formal channel
short TextEditPane::MeasureNavigationRun(const wchar_t *text,
                                         short count,
                                         short,
                                         short,
                                         short limit,
                                         short)                  // 0x5949c0
{
    const short measuredCount = count < limit ? count : limit;
    return m_maskedText
        ? static_cast<short>(GetTextWidth(L"*", 1) * measuredCount)
        : GetTextWidth(text, measuredCount);
}
// CPP@00594A30 | UID0000OJ accepted formal channel
short TextEditPane::ComputeWrapBreak(const wchar_t *text,
                                     short count,
                                     short start,
                                     short end,
                                     int *remainingWidth,
                                     short *breakOffset)         // 0x594a30
{
    if (count == 0) {
        *breakOffset = 0;
        return 2;
    }
    short scanEnd = end;
    short resultCode = 2;
    for (short index = start; index < end; ++index) {
        if (text[index] == L'\r' || text[index] == L'\n') {
            scanEnd = static_cast<short>(index + 1);
            resultCode = 0;
            break;
        }
    }
    signed char hitPart = 0;
    const short measured = MeasureTextRunWrapSegment(
        text + start, static_cast<short>(scanEnd - start), start,
        remainingWidth, &hitPart, 0, 0);
    short result = static_cast<short>(start + measured);
    if (*remainingWidth < 0) {
        short wordStart = result;
        while (wordStart > 0 && text[wordStart - 1] > L' ')
            --wordStart;
        if (wordStart == 0) {
            *breakOffset = result;
            return 1;
        }
        result = wordStart;
        while (result < scanEnd && text[result] <= L' ')
            ++result;
        resultCode = 0;
    }
    *breakOffset = result;
    return resultCode;
}

// UID:0004U9 | by-memory/0x00594b50-0x00594cb0.FindWordBoundary.md | Completion:92 | Confidence:94
// CPP@00594B50 | UID0000OJ accepted formal channel
static void __stdcall FindWordBoundary(const wchar_t *text,
                                       short textLength,
                                       short caretIndex,
                                       bool forward,
                                       TextEditRange *range)
{
    if (!forward)
    {
        if (caretIndex <= 0)
        {
            range->start = 0;
            range->end = 0;
            return;
        }

        short index = caretIndex - 1;
        bool separators = text[index] == L' ' || text[index] == L'\t'
            || text[index] == L'\r' || text[index] == L'\n';
        while (index > 0)
        {
            wchar_t previous = text[index - 1];
            bool previousIsSeparator = previous == L' '
                || previous == L'\t' || previous == L'\r'
                || previous == L'\n';
            if (previousIsSeparator != separators)
                break;
            --index;
        }
        range->start = index;
        range->end = caretIndex;
        return;
    }

    if (caretIndex >= textLength)
    {
        range->start = textLength;
        range->end = textLength;
        return;
    }

    short index = caretIndex;
    bool separators = text[index] == L' ' || text[index] == L'\t'
        || text[index] == L'\r' || text[index] == L'\n';
    while (index < textLength)
    {
        wchar_t current = text[index];
        bool currentIsSeparator = current == L' '
            || current == L'\t' || current == L'\r'
            || current == L'\n';
        if (currentIsSeparator != separators)
            break;
        ++index;
    }
    range->start = caretIndex;
    range->end = index;
}

// UID:0004UA | by-memory/0x00594cb0-0x00594e12.TextEditPaneAutoScrollSelectionToPoint.md | Completion:92 | Confidence:94
// CPP@00594CB0 | UID0000OJ accepted formal channel
bool TextEditPane::AutoScrollSelectionToPoint(int y, int x)
{
    if ((m_editorFlags & kTextEditAutoScrollSelection) == 0
        || !m_selectionVisible)
        return true;

    int horizontalDelta = 0;
    if (x < m_contentRect.left)
        horizontalDelta = x - m_contentRect.left;
    else if (x > m_contentRect.right)
        horizontalDelta = x - m_contentRect.right;

    int verticalDelta = 0;
    if (y < m_contentRect.top)
        verticalDelta = y - m_contentRect.top;
    else if (y > m_contentRect.bottom)
        verticalDelta = y - m_contentRect.bottom;

    if (horizontalDelta < -48)
        horizontalDelta = -48;
    else if (horizontalDelta > 48)
        horizontalDelta = 48;
    if (verticalDelta < -48)
        verticalDelta = -48;
    else if (verticalDelta > 48)
        verticalDelta = 48;

    if (horizontalDelta != 0)
    {
        int position = GetScrollPosition(1);
        ApplyScrollPosition(1, position, position - horizontalDelta);
    }

    if (verticalDelta != 0)
    {
        int lineHeight = GetLineHeight();
        int lineDelta = verticalDelta < 0
            ? 1 - (verticalDelta + 1) / lineHeight
            : -1 - (verticalDelta - 1) / lineHeight;
        int position = GetScrollPosition(0);
        ApplyScrollPosition(0, position, position + lineDelta);
    }

    return true;
}

// UID:00056T | by-memory/0x00594e20-0x00594e5f.TextEditPaneFillTextBackground.md | Completion:94 | Confidence:94
// CPP@00594E20 | UID0000OJ accepted formal channel
void TextEditPane::FillTextBackground(const RectBounds *bounds) // 0x594e20
{
    const unsigned int drawColor = m_drawColor;
    m_drawMode = 0;
    SetDrawColor((m_editorFlags & kTextEditBlackBackground) != 0
        ? 0 : m_textBackColor);
    g_pfnFillRect(this, bounds);
    SetDrawColor(drawColor);
}

// UID:0000Q7 | by-global/g_pActiveTextEditPane.md | Completion:92 | Confidence:93
TextEditPane *g_pActiveTextEditPane = NULL;

// UID:0000UM | by-item/EncodeTextEditState_0058E490.md | Completion:93 | Confidence:94
// Canonical source for this serialization item is owned by [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md).

// UID:0003DV | by-memory/0x0062df90-0x0062e044.TextEditPaneVtableData.md | Completion:86 | Confidence:91
// TextEditPane vtable and RTTI bytes are generated from the class declaration; do not hand-author raw arrays.

// UID:000301 | by-memory/0x0069bdfc-0x0069be00.TextEditStyledUnicodeClipboardFormat.md | Completion:88 | Confidence:91
static unsigned int s_styledUnicodeClipboardFormat = 0;

// UID:000303 | by-memory/0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch.md | Completion:87 | Confidence:91
static short s_mouseSelectionAnchor = 0;






// UID:00040S | by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md | Completion:89 | Confidence:92
TextEditObject::TextEditObject(void *ownerHandle)
    : LObject(),
      m_objectType(0),
      m_ownerHandle(ownerHandle),
      m_payload0(0),
      m_payload1(0)
{
}

TextEditObject::~TextEditObject()
{
}

int TextEditObject::GetObjectType() const
{
    return m_objectType;
}

void TextEditObject::GetPayloadPair(int *outPair) const
{
    outPair[0] = m_payload0;
    outPair[1] = m_payload1;
}

void *TextEditObject::GetOwnerHandle() const
{
    return m_ownerHandle;
}

void TextEditObject::SetPayloadPair(int first, int second)
{
    m_payload0 = first;
    m_payload1 = second;
}

void TextEditObject::OnUpdate()
{
}

void TextEditObject::OnMouseEvent(Event *, bool, unsigned int)
{
}

// UID:00040T | by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md | Completion:88 | Confidence:90
TextEditScrap::TextEditScrap()
    : LObject(),
      m_textLength(0),
      m_text(NULL),
      m_payloadSize(0),
      m_payload(NULL)
{
}

TextEditScrap::~TextEditScrap()
{
    Clear();
}

void TextEditScrap::Clear()
{
    if (m_text != NULL) {
        FreeBufferMemory(m_text);
        m_text = NULL;
        m_textLength = 0;
    }

    if (m_payload != NULL) {
        FreeBufferMemory(m_payload);
        m_payload = NULL;
        m_payloadSize = 0;
    }
}

bool TextEditScrap::IsEmpty() const
{
    return m_text == NULL && m_payload == NULL;
}

void TextEditScrap::SetText(const wchar_t* text, int length)
{
    if (m_text != NULL) {
        FreeBufferMemory(m_text);
        m_text = NULL;
        m_textLength = 0;
    }

    if (text == NULL || length <= 0) {
        return;
    }

    m_text = static_cast<wchar_t*>(AllocateBufferMemory(length * sizeof(wchar_t)));
    MemmoveWrapper(m_text, text, length * sizeof(wchar_t));
    m_textLength = length;
}

void TextEditScrap::SetPayload(const void* payload, int size)
{
    if (m_payload != NULL) {
        FreeBufferMemory(m_payload);
        m_payload = NULL;
        m_payloadSize = 0;
    }

    if (payload == NULL || size <= 0) {
        return;
    }

    m_payload = AllocateBufferMemory(size);
    MemmoveWrapper(m_payload, payload, size);
    m_payloadSize = size;
}

int TextEditScrap::DuplicateText(wchar_t** outText) const
{
    if (outText == NULL) {
        return 0;
    }

    if (m_text == NULL || m_textLength <= 0) {
        *outText = NULL;
        return 0;
    }

    const int byteCount = m_textLength * sizeof(wchar_t);
    wchar_t* copy = static_cast<wchar_t*>(AllocateBufferMemory(byteCount));
    MemmoveWrapper(copy, m_text, byteCount);
    *outText = copy;
    return m_textLength;
}

int TextEditScrap::DuplicatePayload(void** outPayload) const
{
    if (outPayload == NULL) {
        return 0;
    }

    if (m_payload == NULL || m_payloadSize <= 0) {
        *outPayload = NULL;
        return 0;
    }

    void* copy = AllocateBufferMemory(m_payloadSize);
    MemmoveWrapper(copy, m_payload, m_payloadSize);
    *outPayload = copy;
    return m_payloadSize;
}

int TextEditScrap::BuildClipboardBlock(void** outBlock) const
{
    if (outBlock == NULL) {
        return 0;
    }

    *outBlock = NULL;
    if (m_text == NULL || m_textLength <= 0) {
        return 0;
    }

    const int packedTextBytes = m_textLength;
    const int payloadTrailerBytes = (m_payload != NULL && m_payloadSize > 0)
        ? static_cast<int>(sizeof(int)) + m_payloadSize
        : 0;
    const int totalBytes = packedTextBytes + 1 + payloadTrailerBytes;

    char* block = static_cast<char*>(AllocateBufferMemory(totalBytes));
    MemmoveWrapper(block, m_text, packedTextBytes);
    block[packedTextBytes] = '\0';

    if (payloadTrailerBytes != 0) {
        MemmoveWrapper(block + packedTextBytes + 1, &m_payloadSize, sizeof(int));
        MemmoveWrapper(block + packedTextBytes + 1 + sizeof(int), m_payload, m_payloadSize);
    }

    *outBlock = block;
    return totalBytes;
}

void TextEditScrap::SetFromClipboardBlock(const void *dataValue, int dataSize)
{
    const char *data = static_cast<const char *>(dataValue);
    Clear();
    if (data == NULL || dataSize <= 0) {
        return;
    }

    int textBytes = 0;
    while (textBytes < dataSize && data[textBytes] != '\0') {
        ++textBytes;
    }

    if (textBytes > 0) {
        wchar_t wideText[0x8000];
        const int wideCount = MultiByteToWideChar(0, 0, data, textBytes, wideText, 0x8000);
        SetText(wideText, wideCount);
    }

    const int payloadSizeOffset = textBytes + 1;
    if (payloadSizeOffset + static_cast<int>(sizeof(int)) <= dataSize) {
        int payloadSize = 0;
        MemmoveWrapper(&payloadSize, data + payloadSizeOffset, sizeof(int));
        const int payloadOffset = payloadSizeOffset + static_cast<int>(sizeof(int));
        if (payloadSize > 0 && payloadOffset + payloadSize <= dataSize) {
            SetPayload(data + payloadOffset, payloadSize);
        }
    }
}

// UID:0002RV | by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md | Completion:94 | Confidence:94
// CPP@00595390 | UID0000ON accepted formal channel
// UID0002RV RECONSTRUCTION_CPP CODE -> UID0000ON TextEditPane.cpp
TextBoxPane::TextBoxPane(int viewportWidth,
                         int viewportHeight,
                         bool blackBackground,
                         int textColor,
                         int textBackColor,
                         const wchar_t *initialText)            // 0x595390
    : TextEditPane(viewportWidth,
                   viewportHeight,
                   viewportWidth,
                   viewportHeight,
                   textColor,
                   textBackColor,
                   false,
                   false,
                   blackBackground ? kTextEditBlackBackground : 0,
                   IsLegacyAssetMode(),
                   true,
                   false)
{
    if (initialText != NULL) {
        InsertTextRange(initialText,
                        static_cast<short>(wcslen(initialText)),
                        NULL,
                        NULL);
    }

    SetEditActiveState(false, false);
}

// UID:0003M8 | by-memory/0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane.md | Completion:86 | Confidence:88
// CPP@005954C0 | UID0000OJ accepted formal channel
// UID0003M8 / UID00004H source-bearing EPF definitions.
EPFTextEditObject::EPFTextEditObject(TextEditPane *owner,
                                     unsigned char symbolIndex) // 0x5954c0
    : TextEditObject(owner), m_frame()
{
    const wchar_t *resourceName = g_useEpfAssets
        ? L"SYMBOLS.EPF" : L"SYMBOLS.EPD";
    if (symbolIndex < g_pEPFLib->GetEntryCount(resourceName))
        g_pEPFLib->LookupLayoutEntry(resourceName, symbolIndex, &m_frame);
}

// CPP@005955A0 | UID0000OJ accepted formal channel
void EPFTextEditObject::OnUpdate()                              // 0x5955a0
{
    TextEditPane *owner = static_cast<TextEditPane *>(m_ownerHandle);
    int drawPosition[2];
    owner->GetDrawPosition(drawPosition);
    RectBounds destination;
    InitRectBounds(&destination,
                   drawPosition[1],
                   drawPosition[0] - 12,
                   drawPosition[1] + m_frame.bounds.right - m_frame.bounds.left,
                   drawPosition[0] + m_frame.bounds.bottom -
                       m_frame.bounds.top - 12);
    g_pfnBlitSprite(owner, &m_frame, &m_frame.bounds,
                    &destination, 1, NULL, NULL);
    owner->OffsetDrawPosition(m_payload1, 0);
}

// UID:0000UK | by-item/DrawTextRunCallback_00593DB0.md | Completion:91 | Confidence:91
// Emitted code for this callback item is covered by [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md).

// UID:0000EN | by-class\TextEditObject.md | Completion:94 | Confidence:94 | Empty Emitter Marker

// UID:0003GA | by-memory\0x0062e044-0x0062e05c.TextEditObjectVtableData.md | Completion:86 | Confidence:92 | Empty Emitter Marker

// UID:0000EP | by-class\TextEditScrap.md | Completion:94 | Confidence:94 | Empty Emitter Marker

// UID:0003GB | by-memory\0x0062e05c-0x0062e06c.TextEditScrapVtableData.md | Completion:86 | Confidence:92 | Empty Emitter Marker

// UID:0000EI | by-class\TextBoxPane.md | Completion:94 | Confidence:94 | Empty Emitter Marker

// UID:0003GC | by-memory\0x0062e06c-0x0062e120.TextBoxPaneVtableData.md | Completion:94 | Confidence:94 | Empty Emitter Marker

// UID:00004H | by-class\EPFTextEditObject.md | Completion:94 | Confidence:94 | Empty Emitter Marker

// UID:0003GG | by-memory\0x0062e120-0x0062e138.EPFTextEditObjectVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003GJ | by-memory\0x0062e16c-0x0062e184.EPFTextEditObjectSymbolsEpdString.md | Completion:86 | Confidence:92 | Empty Emitter Marker

// UID:0003GH | by-memory\0x0062e138-0x0062e168.TextEditStyledUnicodeClipboardFormatString.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0003GI | by-memory\0x0062e168-0x0062e16c.TextEditWildcardFormatString.md | Completion:85 | Confidence:90 | Empty Emitter Marker
