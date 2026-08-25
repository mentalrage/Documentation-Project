// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000ON
// Source by-file doc: by-file/TextEditPane.md
// UID:0000EO | by-class/TextEditPane.md | Completion:94 | Confidence:94
#ifndef NEXUSTK_UI_CONTROLS_TEXTEDITPANE_H
#define NEXUSTK_UI_CONTROLS_TEXTEDITPANE_H

#include "../../util/LObject.h"
#include "../../render/EPFTileContext.h"
#include "../core/ScrollBar.h"

class Event;
class FontImageLib;
class List;
class StringIter;
class TextEditObject;
class TextEditPane;
class TextEditScrap;
struct Point;
struct TextRunMeasureState;
extern FontImageLib *g_pFontImageLib;
namespace mystr {
template <class CharT> struct mychar_traits;
template <class CharT, class Traits> class StringBase;
}

struct TextEditLineRecord
{
    unsigned short startIndex;
    int top;
    int remainingWidth;
    unsigned short wrapState;
};

struct TextRunFormatData
{
    unsigned short legacyAssetMode;
    unsigned int textColor;
    TextEditObject *object;
};

struct TextEditFormatRecord
{
    short referenceCount;
    TextRunFormatData format;
};

struct TextEditFormatRun
{
    unsigned short startIndex;
    short formatIndex;
};

struct TextEditRange
{
    short start;
    short end;
};

static void __stdcall FindWordBoundary(const wchar_t *text,
                                       short textLength,
                                       short caretIndex,
                                       bool forward,
                                       TextEditRange *range);

struct TextRunMeasureState
{
    int availableWidth;
    int remainingWidth;
    int scratch;
};

struct TextRunDrawState
{
    RectBounds lineRect;
    RectBounds clippedLineRect;
    bool applyRunTextColor;
};

struct TextEditFormatSpan
{
    short start;
    short end;
    TextRunFormatData format;
};

struct TextRunHitState
{
    int consumedWidth;
    int remainingWidth;
    short textOffset;
    signed char hitPart;
};

struct TextRunOffsetState
{
    Point point;
    short targetOffset;
    bool targetIsLineEnd;
};

typedef bool (__cdecl *TextRunIteratorCallback)(TextEditLineRecord *line,
                                                const TextRunFormatData *format,
                                                const wchar_t *text,
                                                int textOffset,
                                                unsigned short charCount,
                                                unsigned short segmentFlags,
                                                void *context,
                                                TextEditPane *pane);

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane);

static bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                        const TextRunFormatData *format,
                                        const wchar_t *text,
                                        int textOffset,
                                        unsigned short charCount,
                                        unsigned short segmentFlags,
                                        void *context,
                                        TextEditPane *pane);

bool __cdecl TextRunHitTestCallback(TextEditLineRecord *line,
                                    const TextRunFormatData *format,
                                    const wchar_t *text,
                                    int textOffset,
                                    unsigned short charCount,
                                    unsigned short segmentFlags,
                                    void *context,
                                    TextEditPane *pane);

bool __cdecl TextRunOffsetMeasureCallback(TextEditLineRecord *line,
                                          const TextRunFormatData *format,
                                          const wchar_t *text,
                                          int textOffset,
                                          unsigned short charCount,
                                          unsigned short segmentFlags,
                                          void *context,
                                          TextEditPane *pane);

short ClampNavigationIndex(short value, short minimum, short maximum);
void NormalizeTextRange(short *start, short *end);
bool IsTextOffsetInRange(short textOffset, short unused,
                         short rangeStart, short rangeEnd);
int MeasureWrappedTextHeight(const wchar_t *text, int viewportWidth);

// UID:0000EN | by-class/TextEditObject.md | Completion:94 | Confidence:94
class Event;
class TextEditPane;
struct TextEditLineRecord;
struct TextRunFormatData;

static bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                           const TextRunFormatData *format,
                                           const wchar_t *text,
                                           int textOffset,
                                           unsigned short charCount,
                                           unsigned short segmentFlags,
                                           void *context,
                                           TextEditPane *pane);

class TextEditObject : public LObject
{
public:
    TextEditObject(void *ownerHandle);
    virtual ~TextEditObject();

    int GetObjectType() const;
    void GetPayloadPair(int *outPair) const;
    void *GetOwnerHandle() const;
    void SetPayloadPair(int first, int second);

    virtual void OnUpdate();
    virtual void OnMouseEvent(Event *event,
                              bool repeatedClick,
                              unsigned int messageTime);

protected:
    friend class TextEditPane;
    friend bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                               const TextRunFormatData *format,
                                               const wchar_t *text,
                                               int textOffset,
                                               unsigned short charCount,
                                               unsigned short segmentFlags,
                                               void *context,
                                               TextEditPane *pane);

    int m_objectType;
    void *m_ownerHandle;
    int m_payload0;
    int m_payload1;
};

typedef char TextEditObjectSizeMustBe14[
    (sizeof(TextEditObject) == 0x14) ? 1 : -1];

// UID:0000EP | by-class/TextEditScrap.md | Completion:94 | Confidence:94
class TextEditScrap;
void PutScrapToClipboard(TextEditScrap *scrap);
void GetScrapFromClipboard(TextEditScrap *scrap);

class TextEditScrap : public LObject
{
public:
    TextEditScrap();
    virtual ~TextEditScrap();

    void Clear();
    bool IsEmpty() const;
    void SetText(const wchar_t *text, int length);
    void SetPayload(const void *payload, int size);
    int DuplicateText(wchar_t **outText) const;
    int DuplicatePayload(void **outPayload) const;
    int BuildClipboardBlock(void **outBlock) const;
    void SetFromClipboardBlock(const void *data, int dataSize);

private:
    friend void GetScrapFromClipboard(TextEditScrap *scrap);

    int m_textLength;
    wchar_t *m_text;
    int m_payloadSize;
    void *m_payload;
};

typedef char TextEditScrapSizeMustBe14[
    (sizeof(TextEditScrap) == 0x14) ? 1 : -1];

// UID:0000Q7 | by-global/g_pActiveTextEditPane.md | Completion:92 | Confidence:93
extern TextEditPane *g_pActiveTextEditPane;

class TextEditPane : public ScrollablePane
{
public:
    TextEditPane(int viewportWidth,
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
                 bool useThousandsSeparator);
    virtual ~TextEditPane();

    short CopyWideText(wchar_t *outText, short capacity) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > GetText() const;
    short GetTextLength() const;
    void GetCaretRange(short *start, short *end) const;
    void GetCaretLocalPoint(Point *point, short caretIndex) const;
    unsigned char *EncodeState(unsigned short *outSize) const;
    void DecodeState(const unsigned char *data, unsigned short size);

    void InsertText(const wchar_t *text, int flags);
    int InsertTextRange(const wchar_t *text,
                        short length,
                        const unsigned short *formatPayload,
                        TextEditObject *textObject);
    void SetText(const wchar_t *text);
    void ClearText();
    void SetSelectionRange(short start, short end);
    void SelectAll();
    void ApplySelectionFormat(unsigned char formatMask, const void *formatData);
    void InsertEmbeddedObject(TextEditObject *object, int width, int height);
    void SetMaxLength(short maxLength);
    void SetMaxLines(short maxLines);
    void EnableMaskedText()
    {
        if (!m_maskedText) {
            m_maskedText = true;
            SetFocusRegistration(true);
        }
    }
    void SetEditActiveState(bool editActive, bool selectAll);
    bool IsEmpty() const;
    void ScrollToTop();
    bool IsMaskedText() const;
    bool IsDirty() const;
    void SetDirty(bool dirty);
    bool IsSelectionVisible() const
    {
        return m_selectionVisible;
    }

    void DeleteSelection();
    void ApplySerializedFormatToSelection(const unsigned short *payload);
    void CutSelectionToScrap(TextEditScrap *scrap);
    void CopyAllToClipboard();
    const wchar_t *GetTextBuffer() const;
    wchar_t GetCharacterAt(short textOffset) const;
    short MeasureTextRange(short start, short end);
    Point GetCaretLocalPoint(short caretIndex) const;
    RectBounds GetViewportBounds() const;
    short GetTextOffsetAtPoint(int y, int x) const;
    bool IsPasteUnavailable() const;
    bool SetEditorFlag(short flagIndex, short state);

    void CopySelectionToScrap(TextEditScrap *scrap);
    void PasteFromClipboard(TextEditScrap *scrap);
    short GetLineCount() const;
    void SetViewportBounds(const RectBounds *bounds);
    void GetTextAreaBounds(RectBounds *bounds) const;
    void SetTextAreaBounds(const RectBounds *bounds);
    virtual void OnDraw();

protected:
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnKeyUp(Event *event);
    virtual bool OnMouseEvent(Event *event);

    virtual short GetScrollRange(char axis);
    virtual short GetOverflowCount(char axis);
    virtual short GetPageSize(char axis);
    virtual short GetScrollOffset(char axis, short units);
    virtual Point *GetContentSize(Point *outSize);
    virtual Point *GetScrollDelta(Point *outDelta, char axis,
                                  short oldPosition, short newPosition);
    virtual void UpdateRenderRegion(const RectBounds *bounds);

    void SetTextColor(unsigned int color);
    void OnSelectionChanged();
    void DispatchNavigationKey(unsigned char key);

    void InvalidateTextRegion(short start, short end);
    void DeleteSelectionOrBackspace();
    void FindWordBoundary(short index, short *wordStart, short *wordEnd) const;
    bool AutoScrollSelectionToPoint(int y, int x);
    void GetLineTextRange(short lineIndex, short *start, short *end) const;
    void DeleteTextRangeAndClampSelection(short start, short end);

private:
    friend bool __cdecl TextRunMeasureCallback(TextEditLineRecord *line,
                                               const TextRunFormatData *format,
                                               const wchar_t *text,
                                               int textOffset,
                                               unsigned short charCount,
                                               unsigned short segmentFlags,
                                               void *context,
                                               TextEditPane *pane);
    friend bool __cdecl DrawTextRunCallback(TextEditLineRecord *line,
                                            const TextRunFormatData *format,
                                            const wchar_t *text,
                                            int textOffset,
                                            unsigned short charCount,
                                            unsigned short segmentFlags,
                                            void *context,
                                            TextEditPane *pane);
    friend bool __cdecl TextRunHitTestCallback(
        TextEditLineRecord *, const TextRunFormatData *, const wchar_t *, int,
        unsigned short, unsigned short, void *, TextEditPane *);
    friend bool __cdecl TextRunOffsetMeasureCallback(
        TextEditLineRecord *, const TextRunFormatData *, const wchar_t *, int,
        unsigned short, unsigned short, void *, TextEditPane *);

    void SetActiveLineIndex(int lineIndex);
    void ReleaseFormatObjects();
    void DeleteTextRange(short start, short end);
    void HandleNavigationKey(Event *event);
    short GetNavigationCaretIndex(Event *event, short caretIndex) const;
    short MeasureTextRunWrapSegment(const wchar_t *text,
                                    short textLength,
                                    int textOffset,
                                    int *remainingWidth,
                                    signed char *hitPart,
                                    unsigned short segmentFlags,
                                    int xOffset) const;
    void RebuildLineTable(short *firstLine, short *lastLine);
    void IterateTextRuns(short firstLine,
                         short lastLine,
                         TextRunIteratorCallback callback,
                         void *context);
    short GetLineIndexForTextOffset(short textOffset) const;
    short GetFormatRunIndexForTextOffset(short textOffset) const;
    short GetTextOffsetAtPoint(int y,
                               int x,
                               signed char *hitPart) const;
    void GetWordSelectionRange(short textOffset,
                               signed char hitPart,
                               short *rangeStart,
                               short *rangeEnd) const;
    void GetLineSelectionRange(short textOffset,
                               signed char hitPart,
                               short *rangeStart,
                               short *rangeEnd) const;
    bool ScrollCaretIntoView(short caretIndex);
    void RefreshTextRange(short start, short end);
    void GetCaretBounds(short caretIndex, RectBounds *bounds) const;
    void DrawTextRange(short firstLine, short lastLine);
    void DrawCaret();
    void ApplyFormatRange(short start,
                          short end,
                          unsigned char formatMask,
                          const TextRunFormatData *format);
    void LoadCurrentFormat();
    void BuildTextRangeRectangles(short start, short end, List *rectangles) const;
    short GetLineIndexForY(int y) const;
    void GetFormatRunBounds(short runIndex, short *start, short *end) const;
    short GetLastFormatRunIndex() const;
    unsigned char GetRepeatClickCount() const;
    bool GetCommonSelectionFormat(unsigned short *mask,
                                  TextRunFormatData *format);
    void GetFormatSpanAtOffset(short textOffset,
                               TextEditFormatSpan *span) const;
    void GetVisualLineSelectionRange(short textOffset, int mode,
                                     short *rangeStart,
                                     short *rangeEnd) const;
    void RebuildAllLines();
    void ScrollSelectionIntoView();
    void ShowSelection();
    void HideSelection();
    void EnforceMaxLength();
    void EnforceMaxLines();
    int DuplicateTextRange(short start, short end, wchar_t **outText) const;
    int BuildSerializedFormatRuns(short start, short end,
                                  void **outPayload) const;
    void CopyFormatFields(TextRunFormatData *target,
                          const TextRunFormatData *source,
                          unsigned short mask);
    void GetRangeFormat(short start, short end, unsigned short *mask,
                        TextRunFormatData *format) const;
    void GetFormatSpanForRun(short runIndex,
                             TextEditFormatSpan *span) const;
    void FindOrCreateFormatRecord(const TextRunFormatData &format,
                                  short *formatIndex);
    bool IsBoundaryFormatRun(short runIndex) const;
    bool IsLeadingFormatRun(unsigned char flags) const;
    void InsertFormatRun(short runIndex, short textOffset,
                         short formatIndex);
    void SetFormatRunRecord(short runIndex, short formatIndex,
                            bool preserveOldObject);
    void RemoveFormatRun(short runIndex);
    void ApplySerializedFormatRuns(short start, short end,
                                   const unsigned short *payload);
    void SetEmbeddedObjectAt(short textOffset, TextEditObject *object);
    void DeleteFormatRange(short start, short end);
    void MeasureLineRange(short firstLine, short lastLine);
    void InsertLineRecord(short lineIndex,
                          const TextEditLineRecord &line);
    void RemoveLineRecord(short lineIndex);
    void DeleteLineRecordsForRange(short start, short end);
    short MeasureLineBreak(short textOffset);
    void InsertTextStorage(short textOffset, const wchar_t *text,
                           short length);
    void ShiftLineOffsets(short firstLine, short delta);
    void ShiftFormatRunOffsets(short firstRun, short delta);
    void OffsetLinePositions(short firstLine, int delta);
    int GetLineAlignmentOffset(const TextEditLineRecord *line) const;
    void DeleteForwardCharacter();
    short MeasureNavigationRun(const wchar_t *text, short count,
                               short unused0, short unused1,
                               short limit, short unused2);
    short ComputeWrapBreak(const wchar_t *text, short count,
                           short start, short end,
                           int *remainingWidth,
                           short *breakOffset);
    bool HitTestRunSegment(TextEditLineRecord *line,
                           const TextRunFormatData *format,
                           const wchar_t *text, int textOffset,
                           unsigned short charCount,
                           unsigned short segmentFlags,
                           TextRunHitState *state);
    bool MeasureRunToOffset(TextEditLineRecord *line,
                            const TextRunFormatData *format,
                            const wchar_t *text, int textOffset,
                            unsigned short charCount,
                            unsigned short segmentFlags,
                            TextRunOffsetState *state);
    bool MeasureTextRunSegment(TextEditLineRecord *line,
                               const TextRunFormatData *format,
                               const wchar_t *text, int textOffset,
                               unsigned short charCount,
                               unsigned short segmentFlags,
                               TextRunMeasureState *state);
    bool DrawTextRunSegment(TextEditLineRecord *line,
                            const TextRunFormatData *format,
                            const wchar_t *text, int textOffset,
                            unsigned short charCount,
                            unsigned short segmentFlags,
                            TextRunDrawState *state);
    void DrawTextCharacters(const wchar_t *text, short length,
                            int textOffset, int segmentFlags);
    void FillTextBackground(const RectBounds *bounds);
    void InvalidateCaret();
    void InvalidateSelectionRange(short start, short end);
    TextEditObject *GetSelectedEmbeddedObject() const;
    TextEditObject *FindNextEmbeddedObject(short *textOffset) const;

    int m_activeLineIndex;
    List *m_textStorage;
    List *m_lineTable;
    List *m_formatTable;
    List *m_formatRuns;
    short m_selectionStart;
    short m_selectionEnd;
    short m_savedSelectionStart;
    short m_savedSelectionEnd;
    TextRunFormatData m_currentFormat;
    bool m_selectionReversed;
    bool m_currentFormatValid;
    bool m_selectionVisible;
    bool m_scrollRangeDirty;
    unsigned int m_editorFlags;
    unsigned int m_lastClickTime;
    short m_lastClickTextOffset;
    signed char m_lastClickHitPart;
    unsigned char m_repeatClickCount;
    unsigned char m_unusedClickState;
    bool m_dirty;
    bool m_maskedText;
    short m_maxLength;
    short m_maxLines;
    bool m_replacePreviousCompositionText;
    bool m_replacedCompositionText;
    bool m_useDefaultAlignment;
    bool m_useThousandsSeparator;
};

// UID:0000EI | by-class/TextBoxPane.md | Completion:94 | Confidence:94
class TextBoxPane : public TextEditPane
{
public:
    TextBoxPane(int viewportWidth,
                int viewportHeight,
                bool blackBackground,
                int textColor,
                int textBackColor,
                const wchar_t *initialText);

protected:
    virtual bool OnKeyEvent(Event *)
    {
        return false;
    }

    virtual bool OnMouseEvent(Event *)
    {
        return false;
    }
};

typedef char TextBoxPaneSizeMustBe174[
    (sizeof(TextBoxPane) == 0x174) ? 1 : -1];

// UID:00004H | by-class/EPFTextEditObject.md | Completion:94 | Confidence:94
class TextEditPane;

class EPFTextEditObject : public TextEditObject
{
public:
    EPFTextEditObject(TextEditPane *owner, unsigned char symbolIndex);

    virtual void OnUpdate();

private:
    EPFTileContext m_frame;
};

typedef char EPFTextEditObjectSizeMustBe3C[
    (sizeof(EPFTextEditObject) == 0x3c) ? 1 : -1];

#endif
