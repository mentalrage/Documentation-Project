*** UID:0000EO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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

[[CHILDREN]]

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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TextEditPane

## Historical / Superseded UID0001HA Integration Receipt - 2026-07-29

- [UID:0004YQ][0x0056bc70-0x0056bc9d.SpelledPaneDeleteLine](by-memory/0x0056bc70-0x0056bc9d.SpelledPaneDeleteLine.md) calls the TextEditPane helpers at `0x0058f150` and `0x0058e2b0` after clamping its signed line index. Their observed ABI is one line-index lookup producing exact start/end shorts, followed by text deletion plus selection/caret clamping over that range.
- The complete managed class declaration now exposes these inherited operations as protected `GetLineTextRange(short, short *, short *) const` and `DeleteTextRangeAndClampSelection(short, short)`. Those spellings are descriptive source reconstruction grounded in method behavior and the derived-class call site; raw helper addresses/names do not enter formal source.
- This bounded support addition changes no TextEditPane score, ownership, field layout, unrelated declarations, child bodies, callback records, or compiler-artifact policy. It closes only the declaration dependency required by SpelledPane's exact formal `DeleteLine` body.

## Historical / Superseded UID0003N0 Integration Receipt - 2026-07-20

- [UID:0003N0][0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane](by-memory/0x00591400-0x005917c9.TextEditPaneCoreAfterTextBoxPane.md) is now a `92/94` non-emitting split index for six exact private TextEditPane methods and five internal compiler-alignment gaps. It retains owner UID0000EO, `Nested:8`, its exact envelope, and a blank managed block; it cannot emit one aggregate body without duplicating its children.
- Validator-issued children [UID:0004TC][0x00591400-0x005914c4.TextEditPaneRefreshTextRange](by-memory/0x00591400-0x005914c4.TextEditPaneRefreshTextRange.md), [UID:0004TD][0x005914d0-0x0059151c.TextEditPaneGetCaretBounds](by-memory/0x005914d0-0x0059151c.TextEditPaneGetCaretBounds.md), [UID:0004TE][0x00591640-0x005916b5.TextEditPaneDrawTextRange](by-memory/0x00591640-0x005916b5.TextEditPaneDrawTextRange.md), and [UID:0004TF][0x005916c0-0x0059173e.TextEditPaneDrawCaret](by-memory/0x005916c0-0x0059173e.TextEditPaneDrawCaret.md) join preserved children [UID:0004T1][0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles](by-memory/0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles.md) and [UID:00030D][0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion](by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md) in exact address order.
- The complete managed class union adds private declarations for `GetLineIndexForTextOffset`, `ScrollCaretIntoView`, `GetCaretBounds`, `DrawTextRange`, and `DrawCaret` around the already accepted `RefreshTextRange` declaration. It preserves every B001/B003/B004/B005 constructor, destructor, serialization, callback, record, field, access, and support declaration and still closes the class before `[[CHILDREN]]`.
- `RefreshTextRange` resolves text offsets to line indexes, rebuilds and optionally measures the affected line range, then invalidates and scrolls the active caret unless exact editor flag literals suppress those stages. The two support identities remain private TextEditPane methods at `0x0058f0d0` and `0x0058e890`; their source spellings are high-confidence inference grounded in complete behavior and caller use.
- `GetCaretBounds`, `DrawTextRange`, and `DrawCaret` are retained source methods despite zero direct start xrefs. Their complete ordinary method forms and byte-equivalent optimizer-inlined logic in [UID:00030C][0x00590810-0x005909e3.TextEditPaneOnDraw](by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md) close liveness without inventing compiler pseudo-source.
- Score remains `93/94`: this callback closes the assigned source island and declaration surface, while unrelated TextEditPane input/navigation/formatting raw debt and unrecoverable private lexical spellings still cap the broader class.

## Historical / Superseded UID0001JN Integration Receipt - 2026-07-19

- [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md) is now the exact class-owned source body `unsigned char *TextEditPane::EncodeState(unsigned short *outSize) const` at `92/94`. UID0000EO remains its owner/emitter, while [UID:0000ON][TextEditPane](by-file/TextEditPane.md) remains the translation-unit route.
- The existing declaration was already source-correct and remains byte-for-byte in the complete managed class block. UID0001JN adds no alternate free-helper prototype, raw IDA signature, buffer-object type, new access section, or class layout field.
- Source ABI is one const `TextEditPane` receiver, one explicit `unsigned short *outSize`, an allocator-owned `unsigned char *` return, and x86 `retn 4`. The raw TextEditControlPane wrapper loads `m_textEditPane` and tail-forwards; it does not change member ownership or visibility.
- The method serializes the existing exact fields in declaration order: `m_textStorage`, `m_lineTable`, `m_formatTable`, and `m_formatRuns`, whose element types remain `wchar_t`, `TextEditLineRecord`, `TextEditFormatRecord`, and `TextEditFormatRun` at 2/16/16/4 bytes. It calls only existing List, Encoder, and MemoryMan APIs.
- `TextEditFormatRecord::referenceCount` remains signed `short` for UID0004T0's strictly-positive deletion test. UID0001JN copies complete 16-byte records without interpreting this field, so the accepted B003 destructor/private-helper/signed-record declaration union is preserved without modification.
- Exact source-visible stream behavior is raw low-word text bytes, zero delimiter, big-endian integer `0x6b6f6e67` (`kong`), and three big-endian short byte lengths followed by 16/16/4-byte table payloads. Sixteen-bit multiplication wrap and signed-short widening are deliberate as-shipped behavior.
- The source uses a 32768-byte automatic buffer with Encoder capacity 32766, ignores the `Finalize` boolean, uses the full 32-bit finalized count for MemoryMan allocation/copy, and truncates only the public output size. It preserves two `GetMemoryMan()` evaluations and returns caller-owned raw storage.
- No null/empty/output/capacity/overflow/finalize/allocation guards, checked arithmetic, text-size multiplication, `size_t` hardening, explicit alloca/cookie/SEH cleanup, raw vtable call, or decoder body is added. The paired decoder remains a separate lower method outside UID0001JN.
- The full current class union remains unchanged: `virtual ~TextEditPane()`, private `ReleaseFormatObjects()`, signed format records, exact callbacks/friends/methods/fields, compiler-vtable source cause, and class-closing `};` before `[[CHILDREN]]`. Score remains `93/94`; this child closes its own source body without claiming the unrelated raw helper islands are complete.

## Historical / Superseded UID0002ZZ And UID0004T0 Integration Receipt - 2026-07-19

- The complete declaration now directly supports [UID:0002ZZ][0x0058e140-0x0058e228.TextEditPaneDestructor](by-memory/0x0058e140-0x0058e228.TextEditPaneDestructor.md) and private [UID:0004T0][0x005912b0-0x005912fe.TextEditPaneReleaseFormatObjects](by-memory/0x005912b0-0x005912fe.TextEditPaneReleaseFormatObjects.md). `virtual ~TextEditPane()` remains the ordinary source declaration; `void ReleaseFormatObjects()` is private because all three callers are TextEditPane methods and the body directly consumes private table state.
- R3 preserves the complete accepted constructor, method surface, callbacks, friends, access sections, fields, and source order. The class-closing `};` remains before `[[CHILDREN]]`, so destructor/helper and all existing exact method definitions emit at namespace scope.
- The only semantic record-type correction remains `TextEditFormatRecord::referenceCount` from unsigned to signed `short`. UID0004T0's exact branch deletes an embedded object only when this field is strictly positive. The formerly explicit `reserved02`/`reserved0e` declarations are compiler-natural alignment, not source members: ordinary x86 alignment still places 12-byte `TextRunFormatData` at record `+4` and preserves exact 16-byte line/format records.
- Exact owned List declaration order remains `m_textStorage`, `m_lineTable`, `m_formatTable`, and `m_formatRuns` at complete-object offsets `+0x134/+0x138/+0x13c/+0x140`. Their constructor element sizes remain 2/16/16/4 bytes. Historical reversed `m_styleRuns/m_formatRecords` names remain superseded.
- Destructor source clears `g_pActiveTextEditPane` only when equal to this, calls `ReleaseFormatObjects`, guarded-deletes/nulls the four Lists in field order, and calls `g_pIMEPane->SetFocusPane(this, false)` only when the global exists. Current active-editor and IME support remain dependencies rather than class ownership transfers.
- UID0004T0 is reusable: destructor, DecodeState, and SetText call it before container destruction or state repopulation. It preserves format records and List count, does not touch `m_formatRuns`, and releases only positively referenced embedded `TextEditObject` payloads before zeroing each count.
- Explicit TextEditPane vptr writes at primary and `+0xa0/+0xa4` facets, scalar deleting wrapper flags, destructor thunk, derived/unwind routes, `ScrollablePane::~ScrollablePane()` call, SEH/cookie state, funclets, operator delete, and raw vtable/RTTI arrays remain compiler output. They are intentionally absent from this human declaration and exact method bodies.
- [UID:0003DV][0x0062df90-0x0062e044.TextEditPaneVtableData](by-memory/0x0062df90-0x0062e044.TextEditPaneVtableData.md) remains compiler-generated evidence. This virtual declaration and exact child methods regenerate its ordinary/deleting/adjustor slots; no handwritten table is needed.
- Source ownership remains [UID:0000ON][TextEditPane](by-file/TextEditPane.md) / `NexusTK/ui/controls/TextEditPane.cpp`. TextEditControlPane, TextBoxPane, SpelledPane, IMEPane, List, and CopyWindow remain wrappers, derived classes, dependencies, or consumers.
- Completion rises `92 -> 93` because the ordinary destructor, private helper, signed record contract, four-field lifecycle, globals, source/compiler boundary, and source-legal access are now closed. Confidence remains `94`: exact behavior/types/routes are very strong, while the original private-helper lexical spelling is inferred and unrelated raw helper islands remain.

## Historical / Superseded UID0002ZY Integration Receipt - 2026-07-19

- The class now exposes the exact twelve-argument constructor declaration used by [UID:0002ZY][0x0058dce0-0x0058e132.TextEditPaneConstructor](by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md): dimensions 1-4, colors 5-6, horizontal/vertical scrollbar booleans 7-8, editor flags 9, legacy mode 10, default-alignment 11, and thousands-separator 12.
- Exact storage types are `List(sizeof(wchar_t),128)` at `+0x134`, 16-byte `TextEditLineRecord` at `+0x138`, 16-byte `TextEditFormatRecord` at `+0x13c`, and 4-byte `TextEditFormatRun` at `+0x140`. `TextRunFormatData` is the naturally aligned 12-byte legacy-mode/text-color/object payload embedded at format-record `+4`; the alignment after the initial short is compiler supplied.
- The historical `m_styleRuns` at `+0x13c` and `m_formatRecords` at `+0x140` pairing is reversed. Current source-facing names are `m_formatTable` and `m_formatRuns`, proved independently by 16-byte versus 4-byte indexing and the signed `-1` run sentinel.
- `TextRunMeasureCallback` and `DrawTextRunCallback` remain namespace-scope static `__cdecl` iterator callbacks. Exact prototypes precede the class and exact friends preserve direct access to private TextEditPane state without widening fields, inventing raw-offset helpers, or changing the address-taken callback ABI.
- Constructor defaults are 30000 characters and 30000 lines. The TextEditControlPane wrapper later applies 1024/1; those wrapper postcalls are not base-constructor defaults. Parameter 11 is alignment policy rather than read-only state, and parameter 12 gates numeric thousands grouping rather than a generic input mode.
- Vtable stores, cookie/SEH setup, EH state changes, unwind funclets, incomplete-new cleanup, explicit List destruction, and base teardown remain compiler output. The class closes before `[[CHILDREN]]`, so all child definitions remain namespace scope.

## Historical / Superseded UID00030F Integration Receipt - 2026-07-20

- The complete managed declaration now incorporates source-ready UID00030F `bool OnKeyEvent(Event *)`, UID0004TZ `bool OnKeyUp(Event *)`, UID0004U3 `HandleNavigationKey`, UID0004U5 `DeleteSelectionOrBackspace`, UID0004U7 `GetNavigationCaretIndex`, UID0004U8 `MeasureTextRunWrapSegment`, and UID0004UA `AutoScrollSelectionToPoint(int y,int x)` without dropping any executed constructor/destructor/serialization/draw/range-helper declaration.
- Public `CopySelectionToScrap`, `PasteFromClipboard`, and `InsertTextRange` provide the compile-visible TextEditScrap and shared insertion surfaces. `InsertTextRange` has 38 callers across TextEditPane and unrelated pane classes, so it cannot be private or protected. Private `DeleteTextRange`, text-offset/format-run/word/line selection helpers, and file-local UID0004U9 `FindWordBoundary` close the remaining calls emitted by the accepted bodies.
- The four List pointers and signed format records remain in exact source order. Compiler-natural alignment, not explicit `reserved02`/`reserved0e` members, preserves 16-byte line/format records and the 12-byte TextRunFormatData payload.
- Tail fields are declaration-complete through `+0x173`. The proven click/selection bytes are `m_selectionReversed`, `m_currentFormatValid`, `m_selectionVisible`, `m_scrollRangeDirty`, `m_lastClickTime`, `m_lastClickTextOffset`, `m_lastClickHitPart`, and `m_repeatClickCount`. Physically occupied `+0x168` is inference-capped `unsigned char m_unusedClickState`; it is not padding and no surviving access proves a stronger original spelling. `+0x16b` is compiler-natural alignment and has no source member.
- Composition state is two bools at `+0x170/+0x171`: `m_replacePreviousCompositionText` and `m_replacedCompositionText`. Historical `m_inputState` coalescing is superseded by branch-local target evidence.
- Primary virtual slots `+0x64/+0x68/+0x6c` are bool OnKeyEvent/OnKeyUp/OnMouseEvent. Raw vtable arrays, deleting/adjustor wrappers, RTTI, EH/cookie mechanics, padding, and raw offsets remain compiler artifacts rather than declarations.
- Score remains `93/94`. This callback closes the target-required class surface while retaining confidence caps for exact original private lexical spellings, especially the dormant `+0x168` byte and unrelated residual UID0001JS helpers.

## Status

- UID0000OJ Gate 2A routing repair: this page owns the translation-unit CPP preamble/statics followed by exactly one CPP `[[CHILDREN]]` marker, together with the shared header preamble/types and complete `TextEditPane` declaration. All 141 TextEditPane/file-local body keys are owned only by 50 sorted child nodes: 28 one-body exact pages, 19 range-limited split pages, UID0002RU's two-body node, and UID0003FC/UID0003FD. UID000565 and UID000566 close the two former file-root exceptions, and no function definition remains copied in this class CPP channel. The independent pre-class H child marker inserts authoritative UID0000EN `TextEditObject` and UID0000EP `TextEditScrap` declarations in explicit order; fieldless UID0000EI `TextBoxPane` and UID00004H `EPFTextEditObject` are ordered file-root H siblings after this page, with UID00004H supplying the final include-guard close.
- UID0001JM, UID0001JP, and UID0001JS are now `RECONSTRUCTABLE:FALSE`, have blank emitter/position/formal channels, and retain complete covered-by manifests. Their 109 former aggregate bodies are owned once by UID00056B-UID00056T; no broad aggregate snippet remains available to cross separately owned exact pages.
- Dated waited refresh command `000000027091` assembled 144 unique numeric CPP keys in strict ascending order and preserved the complete 574-line H declaration surface. This is a mutable generated receipt; the ordinary one-owner and ordering contract remains authoritative across later refreshes.
- Confidence: very strong for core editor ownership, exact constructor ABI/behavior, four table layouts, all draw/key/mouse/invalidation and modeled/raw children, active-editor and clipboard-format globals, support-object boundaries, TextEditPane source-file routing, return-by-value hidden-result wide StringBase ABI, text-area and caret query contracts, source-legal callback friendship, and complete selected-unit formal closure. Only unrecoverable original private lexical spelling prevents a perfect score.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: `0x0058dce0-0x005917c9`, `0x00591d60-0x00594e60`, plus mixed scrollbar variants at `0x0055d960-0x005654ec`
- Historical generated lead: `source-3/simroot_v2/class_TextEditPane.cpp`; stale simroot/Wave material is retained only as history and is not current source authority.

## Class Purpose

`TextEditPane` is the core styled text editor pane. It owns UTF-16 text storage, line and format tables, caret/selection state, IME focus, clipboard operations, scrollable viewport behavior, rich text drawing, keyboard/mouse editing, text-run measurement/drawing callbacks, and the tightly coupled `TextEditObject` / `TextEditScrap` / `EPFTextEditObject` support-object family.

It inherits or embeds [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) behavior rather than being a simple `ControlPane`. The dialog-facing `ControlPane` wrapper is [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md).

## Observed State

Important recovered state. Field names are the current source-facing recommendations; offsets are stable, while table and callback names remain below final-audit proof where noted.

```text
+0x000  primary vtable
+0x0a0  secondary vtable A
+0x0a4  secondary vtable B
+0x08c  m_textAlignment, inferred text alignment/mode byte; draw callback values 1/2 align center/right and value 3 trims final whitespace
+0x120  m_textAreaLeft, inferred text-area left bound used by text-run layout/draw
+0x124  m_textAreaTop, inferred text-area top bound used by draw rect Y coordinates
+0x128  m_textAreaRight, inferred text-area right bound used by text-run layout/draw
+0x134  m_textStorage, UTF-16 text/list storage; high confidence
+0x138  m_lineTable / m_lineBreakTable, inferred line/wrap table with 16-byte records; medium-high confidence
+0x13c  m_formatTable, exact 16-byte TextEditFormatRecord table with signed short referenceCount, compiler-natural alignment, plus TextRunFormatData
+0x140  m_formatRuns, exact 4-byte TextEditFormatRun table with unsigned start and signed format index
+0x144  m_selectionStart, selection/caret endpoint; high confidence
+0x146  m_selectionEnd, paired selection/caret endpoint; high confidence
+0x148  saved selection / mouse-expansion anchor start; medium confidence
+0x14a  saved selection / mouse-expansion anchor end; medium confidence
+0x158  m_selectionReversed; active Shift endpoint selector
+0x159  m_currentFormatValid
+0x15a  m_selectionVisible; drag-autoscroll gate
+0x15b  m_scrollRangeDirty
+0x15c  m_editorFlags, active/editable/read-only/selection/autoscroll style flags; high confidence for bitfield role
+0x160  m_lastClickTime
+0x164  m_lastClickTextOffset
+0x166  m_lastClickHitPart
+0x167  m_repeatClickCount
+0x168  m_unusedClickState; occupied code-dead byte, original spelling/type intent inference-capped
+0x169  m_dirty / m_needsRefresh; medium-high confidence
+0x16a  m_maskedText / password-mask display byte; high confidence
+0x16b  compiler-natural alignment; no source member
+0x16c  m_maxLength; high confidence from direct setter and constructor value 1024
+0x16e  m_maxLines; high confidence from direct setter and constructor value 1
+0x170  m_replacePreviousCompositionText
+0x171  m_replacedCompositionText
+0x172  m_useDefaultAlignment, constructor policy byte; false immediately selects alignment mode 2
+0x173  m_useThousandsSeparator, numeric grouping byte read by the bounded formatting path
```

Historical generated source used several alternate local struct names for the same backing storage. The accepted constructor/callback pass resolves `+0x138/+0x13c/+0x140` to the exact record sizes and roles above, while [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) and [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) carry the exact callback bodies and shared generic-context ABI. Table layout, callback access, and all raw-helper dispositions are closed; only unrecoverable original private lexical spelling remains a confidence cap.

[UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) uses `+0x120/+0x124/+0x128` as text-area bounds, `+0x8c` as alignment/mode, `+0x15c` editor flags, and inherited GrafPort draw/text color state. The field names are inferred source-facing names, not original-proof spellings.

The process-wide active editor pointer is [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md) at `0x0069be00`; current generated [UID:000039][CopyWindow](by-class/CopyWindow.md) source consumes that canonical pointer. The older `g_pCopyWindowTextEditPane` spelling is an explicitly superseded historical generated consumer alias for the same address, not a current symbol or separate global.

## Source Placement And Rejected Owners

Keep this class owned and emitted through [UID:0000ON][TextEditPane](by-file/TextEditPane.md) / `NexusTK/ui/controls/TextEditPane.cpp`. The class owns class methods and vtable data, while file-local callbacks, raw adapters, support objects, string literals, and module statics stay in the same implementation module.

The `0x00593c20-0x0059403b` source corridor is ordered as file-local cdecl `TextRunMeasureCallback`, private `TextEditPane::MeasureTextRunSegment` at exact `[0x00593cf0,0x00593dad)`, file-local cdecl `DrawTextRunCallback`, then private raw `DrawTextRunSegment`. UID0003FC is a compiler-retained source member with no shipped route, not a cdecl callback thunk; its zero xrefs do not alter this direct class/file placement. All four paths inherit width and visible-count methods from GrafPort, whose member definition remains in `NexusTK/render/GrafPort.cpp`.

Rejected owner alternatives:

- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md) is a reusable `ControlPane` adapter. It allocates/forwards to an embedded editor at wrapper offset `+0x10c`, but does not own the editor implementation.
- `TextBoxPane` is a derived or adjacent control with its own constructor/vtable island; it does not own base editor logic.
- `TextFilter` starts after the support-object cluster and owns separate singleton/sanitizer behavior.
- [UID:000039][CopyWindow](by-class/CopyWindow.md) consumes `g_pActiveTextEditPane`, calls `TextEditPane::CopyAllToClipboard()`, and then clears the canonical pointer without a null guard; it is not the global or editor owner. The older `SelectAll` shorthand is explicitly superseded because it does not describe the accepted clipboard-publication behavior.
- [UID:00004F][Encoder](by-class/Encoder.md) / [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) are serializer dependencies, not TextEditPane state owners.
- `GrafPort`, `SurfaceRenderCallbackTable`, `ScrollBar`, `ScrollVolumePane`, and `ScrollNewGroupPane` are renderer/scroll dependencies or adjacent owners. Current docs reject generated TextEditPane ownership for `0x00561420`, `0x00561a40`, `0x00561b00`, and `0x00561bc0` because they route to [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md).
- Stale FittingRoom / RankingEvent generated labels around `0x00593b20`, `0x00593d00`, and `0x00593f00` cut through or neighbor TextEditPane callback bodies and should not be used as ownership evidence.

## C++ Declaration Policy

This class is declaration-ready. The formal CPP block contains the translation-unit preamble/statics and then one `[[CHILDREN]]` marker, so all 141 function bodies emit from their exact by-memory owners in source order. The independent H block places its one child marker before the `TextEditPane` declaration, so the authoritative TextEditObject/TextEditScrap support declarations precede the class while all TextEditPane declarations remain owned here. The declaration intentionally omits raw offsets and inference/provisional audit comments. The complete offset map, stable roles, inferred spellings, provisional states, confidence caps, and alignment caveats remain in `Observed State` and the surrounding evidence prose above. `ReleaseFormatObjects` is declared private for issued UID0004T0, and signed `TextEditFormatRecord::referenceCount` preserves its exact positive-count branch without changing record size. TextEditControlPane constructor call sites and `IsLegacyAssetMode()` resolve constructor argument ten as `legacyAssetMode`, not `fontId`. Direct lower setters and the wrapper constructor's `1024/1` values resolve `+0x16c/+0x16e` as `m_maxLength/m_maxLines`. Lower `0x0058e3e0` constructs a pointer-backed `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` in the caller-provided hidden result and returns that result in EAX; this is source-facing return-by-value, not an explicit output-reference API. Provisional `WideString` and the unrelated SSO-7 `SimpleUString` class remain rejected.

UID0003FC requires no class-channel duplication: formal H already contains exactly one 12-byte `TextRunMeasureState` (`availableWidth +0`, `remainingWidth +4`, conservative reset-only `scratch +8`) and exactly one private seven-argument `MeasureTextRunSegment` declaration. UID0003FC therefore emits only its member definition and keeps its own H blank. The inherited `AdjustVisibleCountForTrailingWhitespace` declaration belongs once to GrafPort, while `friend class TextEditPane` belongs on TextEditObject so private member bodies may read protected `m_payload1` without public fields or raw offsets.

Preserve the current single-emitter support-class route. UID0000EN `TextEditObject`, UID0000EP `TextEditScrap`, and UID00004H `EPFTextEditObject` each supply one authoritative H definition through their existing ordered child/file-root channels; this callback repair authorizes no copied aggregate definition or UID0000EO removal.

`InsertTextRange` is deliberately public. The current IDA identity and typed contract are `TextEditPane__InsertTextRange` at `0x0058fc30`, `int __thiscall(TextEditPane *this, const wchar_t *text, short length, const unsigned short *formatPayload, TextEditObject *textObject)`. Its 38 checked callers include unrelated pane classes as well as TextEditPane internals, which rules out private/protected access without invented friends or wrappers. The target [UID:000414][0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText](by-memory/0x005b34d0-0x005b356c.SayInputPaneConstructorWithInitialText.md) passes the initial text, `wcslen` narrowed to the observed signed-short length, and null format/object pointers. The older `int formatFlags` fourth-parameter declaration is superseded by the pointer-typed object contract.

The made-by scrolled-text constructor [UID:0004MA][0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor](by-memory/0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md) requires five compile-visible declaration details that remain explicit without changing ownership: `TextEditScrap` is forward-declared; `PasteFromClipboard`, `GetLineCount`, `SetViewportBounds`, and `SetTextAreaBounds` are public; and the existing virtual `OnDraw` declaration is public because the unrelated `ScrolledTextControlPaneForMadeBy` source calls it directly. UID0003R9 independently proves the paired public `GetTextAreaBounds(RectBounds *) const` declaration at lower `0x0058f080`. Exact lower behavior is supported at `0x005904a0`, `0x0058f1a0`, `0x0058f4b0`, `0x0058f080`, `0x0058f490`, and [UID:00030C][0x00590810-0x005909e3.TextEditPaneOnDraw](by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md). Original helper spellings remain inferred, but their ABI and consumed behavior are resolved.

The IME anchor-refresh source route adds two compile-visible const query declarations without moving ownership. Lower `0x0058f050` writes the signed-short selection/caret endpoints at `+0x144/+0x146` to two caller pointers and returns with two explicit arguments; source-facing `GetCaretRange(short *, short *) const` is behaviorally exact. Lower `0x0058f740` consumes a signed-short caret index and writes a project `Point { int y; int x; }`; source-facing `GetCaretLocalPoint(Point *, short) const` is behaviorally exact. [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md) calls both on the final focused TextEditPane, and [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) contains the optimizer-inline expansion of that source-level private IMEPane call. Exact original helper spellings remain descriptive and confidence-capped; raw `sub_` names, a direct object cast from List element storage, and a duplicate IMEPanes definition are rejected.

## TextEditControlPane Wrapper Dependencies

- [UID:0004K3][0x00498bd0-0x00498bef.TextEditControlPaneLimitSetters](by-memory/0x00498bd0-0x00498bef.TextEditControlPaneLimitSetters.md) forwards to `SetMaxLength`/`SetMaxLines`; lower `0x0058ee50/0x0058ee70` write `+0x16c/+0x16e` and recompute layout.
- [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadText](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md) forwards to [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md), with exact signed-short return/capacity and 70 wrapper sites across 41 functions.
- [UID:0004K5][0x00498c20-0x00498c38.TextEditControlPaneGetInputText](by-memory/0x00498c20-0x00498c38.TextEditControlPaneGetInputText.md) forwards return-by-value `GetText()` through the same hidden-result ABI. The compiler supplies the result pointer; it is not a source parameter or returned reference.
- [UID:0004K6][0x00498c40-0x00498c5f.TextEditControlPaneStateSerialization](by-memory/0x00498c40-0x00498c5f.TextEditControlPaneStateSerialization.md) exposes retained raw `EncodeState`/`DecodeState` wrappers over [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md) and raw lower decode `0x0058e6a0-0x0058e880`.
- Mask/state, empty/select/set, and layer/event wrapper children require the declaration methods shown above. These dependencies do not move editor implementation into TextEditControlPane.cpp.

## UID0003R9 Hidden-Result And Text-Area Consumer Evidence

- Lower `0x0058e3e0-0x0058e482` receives only the implicit hidden StringBase result pointer after `this`, initializes the previously unconstructed one-pointer object, copies/detaches exact UTF-16 storage, finalizes it, returns the hidden result in EAX, and uses `ret 4`. It does not receive a preconstructed caller reference in source.
- UID0003R9 passes an unconstructed stack slot, marks its lifetime only after the call, uses the returned StringBase for trim/c_str/length, and destroys it at scope exit. Wrapper UID0004K5 forwards the same hidden result; its external caller at `0x00529790` likewise passes an unconstructed local and later destroys it. These independent lifecycles require `StringBase GetText() const` and `StringBase GetInputText() const` source declarations.
- The exact one-pointer `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` type remains compiler-proven. The correction changes only source calling shape; it does not replace the type with `WideString` or SSO-7 `SimpleUString`, move ownership, or add manual ABI code.
- UID0003R9 is the sole checked caller of lower `0x0058f080`: it passes a 16-byte `RectBounds`, copies the current text-area bounds, offsets y by negative `top` with x zero, and writes them through existing `0x0058f490`. The declaration `void GetTextAreaBounds(RectBounds *bounds) const` is behaviorally exact; its lexical spelling is descriptive and confidence-capped.
- At that bounded callback epoch, unrelated table/private names, raw callback records, aggregate splits, file-local access, and generated helper-name pollution were still open. The complete UID0000OJ selected-unit pass later closed those source and access dispositions; this sentence is retained only as superseded history for the ABI correction.

File-local callbacks in `TextEditPane.cpp` use the exact friend declarations already present in the formal class, preserving direct access to `m_maskedText`, `m_textAreaLeft`, `m_textAreaTop`, `m_textAreaRight`, and `m_textAlignment` without widened fields or raw offsets. [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) and [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) carry those exact bodies; this class page remains declaration-only for those callbacks and does not duplicate either child definition.

## Method Families

| Family | Addresses | Role |
| --- | --- | --- |
| Construction/destruction | `0x0058dce0-0x0058e227`, `0x0048c4d0-0x0048c50b` | Construct `ScrollablePane`, install vtables, create text/style lists, seed empty text, register active editor/IME focus, and release owned lists. The `0x0048c4d0` wrapper is shared compact/TextEdit/ListPane scalar-deleting destructor support, not an exclusive TextEditPane source body. |
| Text copy/access | [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md) | Copy a bounded UTF-16 prefix from editor text storage into a caller buffer and null-terminate it. |
| Serialization | `0x0058e490-0x0058e691` | Encode text/list/style table state through [UID:00004F][Encoder](by-class/Encoder.md) for a caller-owned save/export path. |
| Viewport and scroll queries | `0x0058e890-0x0058edc4` | Scroll to caret/line; report inherited range/overflow/page/content metrics; convert units; and implement canonical `GetScrollDelta` at `0x0058ed80`, scaling vertical old-minus-new by line height and horizontal old-minus-new directly. |
| Layout and selection | `0x0058edd0-0x0058fb8a` | Resize, measure lines, locate cursor/format/word/line ranges, set selection, expose signed-short caret endpoints at `0x0058f050`, map a caret index to a local Point at `0x0058f740`, compute caret pixels, and recalc line breaks. |
| Text mutation and clipboard | `0x0058fc30-0x0059079b` | Insert/set text, copy to `TextEditScrap`, paste, select all, read text, and find next format handler. |
| Drawing and events | [UID:00030C][0x00590810-0x005909e3.TextEditPaneOnDraw](by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md), [UID:00030F][0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent](by-memory/0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent.md), [UID:00030E][0x00590de0-0x00591180.TextEditPaneOnMouseEvent](by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md) | Draw background/text/selection/caret, handle key events, and mouse selection/drag/double-click behavior. |
| Invalidations and limits | `0x00591180-0x0059173f`, [UID:00030D][0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion](by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md) | Enforce max length/lines, cleanup format records, update caret, and invalidate lines/selection/caret/text region. |
| Format runs/range editing | `0x00591d60-0x00593c20`, callbacks at `0x00593c20-0x0059403b` | Build format arrays, apply/get range attributes, replace/delete ranges, manage style runs, iterate text runs, address-taken measure/hit adapters, and raw measure-helper variants. |
| Input navigation, wrapping, and text-run helpers | `0x00594040-0x00594e60` | Non-emitting organizational aggregate whose modeled children, raw helpers, lower renderer, dispatcher tables, padding, and pre-support boundary all have exact formal or non-source dispositions. The aggregate stays blank to prevent duplication, not because source debt remains. |
| Scrollbar handler variants | `0x0055d960-0x005654ec` excluding the corrected `0x00561420-0x00561d4d` group-scrollbar helper family | Mixed hit-test, draw, track, drag, and raw reset scrollbar variants used by the editor and neighboring scrollbar classes; the range is a non-emitting corridor map, not a direct TextEditPane source-owned block. |

Current source-facing helper names:

| Address / item | Recommended name | Confidence / policy |
| --- | --- | --- |
| `0x0058dce0-0x0058e132` | `TextEditPane::TextEditPane(...)` | High role confidence; constructor parameter names remain provisional. |
| `0x0058e140-0x0058e228` | `TextEditPane::~TextEditPane()` | High confidence; method-body C++ is closer to readiness than constructor once table member names are accepted. |
| `0x0058e380-0x0058e3d7` | `TextEditPane::CopyWideText(wchar_t *outText, short maxChars) const` | High behavior confidence, medium exact spelling. |
| `0x0058e3e0-0x0058e482` | `TextEditPane::GetText() const` returning `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` by value | Exact one-pointer wide StringBase type and hidden-result return ABI are compiler/lifecycle-proven; method spelling remains descriptive. |
| `0x0058e490-0x0058e691` | `unsigned char *TextEditPane::EncodeState(unsigned short *outSize) const` | Very high: exact member ABI, retained wrapper, four class fields/types, stream, allocator/output contract, and complete child source are resolved; historical free-helper ambiguity is superseded. |
| `0x00590810` | `TextEditPane::OnDraw()` | High. |
| `0x005909f0` | `bool TextEditPane::OnKeyEvent(Event *event)` | Very high: exact bool ABI, Event union, complete source body, seven vtable routes, and recursive helper closure. |
| `0x00590dd0` | `bool TextEditPane::OnKeyUp(Event *event)` | Very high: exact five-byte unconditional-false source virtual with nine vtable routes. |
| `0x00590de0` | `bool TextEditPane::OnMouseEvent(Event *event)` | High role and return confidence; the Event spelling remains source-family inferred. |
| `0x00591740` | `TextEditPane::InvalidateTextRegion(short start, short end)` | High behavior confidence, medium exact spelling. |
| `0x0058fc30` | `TextEditPane::InsertTextRange(const wchar_t *text, short length, const unsigned short *formatPayload, TextEditObject *textObject)` | Very high ABI and access confidence: the current typed helper has 38 callers spanning unrelated pane classes, and UID000414 supplies a direct typed consumer with both optional pointers null. |
| `0x00593500` | `TextEditPane::IterateTextRuns(...)` | High role confidence; proves the eight-argument ABI used by [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) and [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md). Route-negative compiler-retained member counterparts have complete formal dispositions. |
| `0x0058fef0` | formatting object insertion / apply-format helper | Medium-high behavior confidence; B012 TextPad sync confirms command bit `1` reads payload `WORD +0`, bit `2` reads `DWORD +4`, and bit `4` reads `DWORD +8`. |
| `0x00593c20` | `TextRunMeasureCallback` | File-local callback, not a class method; target-level first-draft ready with `TextRunMeasureState` (`+0/+4/+8`), optional `TextRunFormatData::object` at `+0x08`, final line-record writes at `+0x08/+0x0c`, and inferred segment flags. |
| `0x00593db0` | `DrawTextRunCallback` | File-local callback, not a class method; first-draft ready on [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) with `TextRunDrawState`, `TextRunDrawLineRecord`, text-area bounds, alignment mode, optional inline-object dispatch, final whitespace trim, and lower renderer forwarding. |
| `0x00593cf0` | `TextEditPane::MeasureTextRunSegment` | Compiler-retained private member at exact `[0x00593cf0,0x00593dad)`, 189 bytes/72 instructions, with `ECX` plus seven stack arguments and `retn 0x1c`. It has zero start/immediate/pointer routes but complete formal C++; it resets/subtracts/finalizes `TextRunMeasureState`, reads object width, calls inherited final visible-count adjustment, measures plain/masked text, and returns false. `TextRunMeasureCallbackThiscallRaw` remains only the stable page label. |
| `0x00593f00` | `TextEditPane::DrawTextRunSegment` raw member | Separately documented route-negative private member with complete formal C++ and inherited visible-count call at `0x00594019`; it corroborates the member ABI but is not an additional UID0003FC report target. `DrawTextRunCallbackThiscallRaw` remains the stable page label. |
| `0x00594040` | `void TextEditPane::HandleNavigationKey(Event *event)` | Very high: exact Shift/collapse/dispatcher behavior and two callers. |
| `0x00594120` | `void TextEditPane::DeleteSelectionOrBackspace()` | Very high: exact read-only, selected-range, previous-unit, collapse, and refresh behavior. |
| `0x00594190` | `DeleteForward` / `DeleteNextCharacter` | Medium-high behavior confidence. |
| `0x005941f0` | `short TextEditPane::GetNavigationCaretIndex(Event *, short) const` | High; owns both local switch tables and complete character/word/visual/page/line/document movement matrix. |
| `0x00594660` | clamp text index raw helper | High behavior confidence; raw no-function helper with source signature unresolved. |
| `0x00594680` | normalize selection pair raw helper | High behavior confidence; raw no-function helper with source signature unresolved. |
| `0x005946b0` | `TextEditPane::DrawTextRunSegment` | Strong behavior confidence from [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) and raw draw variant refs; exact original spelling remains inferred. |
| `0x005948a0` | `TextEditPane::MeasureTextRunWrapSegment(...) const` | High: exact seven-argument ABI, primed current/next StringIter, cumulative widths, overflow midpoint, and terminal-inclusive success count. |
| `0x005949c0` | measure masked-or-plain text width raw helper | Medium-high behavior confidence; checks `m_maskedText`, uses `L"*"` at `0x0062e168`, and calls text-width helper code. |
| `0x00594a30` | wrap segment raw helper | Medium-high behavior confidence; scans UTF-16 CR/LF and trims trailing space/control chars before writing an output index. |
| `0x00594b50` | file-local `FindWordBoundary` | Very high: exact five-argument `__stdcall`, four-separator policy, and five callers; distinct from the member wrapper. |
| `0x00594cb0` | `bool TextEditPane::AutoScrollSelectionToPoint(int y, int x)` | Very high: exact coordinate order, field gates, clamps, axis/unit conversions, and two mouse callers. |
| `0x00594e20` | raw pre-support draw/callback-state helper | Medium; exact signature unresolved. |

## Module Statics And Literals

- `0x0069bdfc` is best documented as `s_styledUnicodeClipboardFormat` or `g_textEditStyledUnicodeClipboardFormat`, a module-scope cached custom clipboard format id initialized from image value `0xffffffff`, registered from the constructor using `L"Nexon.StyledUnicodeText"`, and consumed by key/paste helpers.
- `0x0069be00` remains `g_pActiveTextEditPane`; `g_pCopyWindowTextEditPane` is a historical/generated consumer alias only.
- `0x0069be04` is best documented as `s_mouseSelectionAnchor` / `g_textEditMouseSelectionAnchor`, a module-scope scratch word used by `OnMouseEvent` for selection expansion.
- `0x0062e138-0x0062e168` is the file-owned `L"Nexon.StyledUnicodeText"` literal; `0x0062e168-0x0062e16c` is the file-owned wildcard/masked-text `L"*"` literal.

## Raw Callback And Support Boundaries

- `0x00593b20-0x00593c1c` is real raw TextEditPane wildcard/password-mask measure helper code, not FittingRoom and not padding.
- `0x00593c1c-0x00593c20`, `0x00593ce5-0x00593cf0`, `0x00593dad-0x00593db0`, `0x00593ef6-0x00593f00`, and `0x0059403b-0x00594040` are alignment before or between exact callback children.
- UID0003FC occupies only half-open `[0x00593cf0,0x00593dad)`: eleven `0xcc` bytes at `[0x00593ce5,0x00593cf0)` and three at `[0x00593dad,0x00593db0)` remain separate alignment. No split, merge, alternate owner, or new UID is needed.
- `0x00594618-0x00594658` is two adjacent cursor/navigation switch tables for `0x005941f0`: `0x00594618-0x00594628` is a 4-entry table referenced from `0x00594226`, `0x00594628-0x00594658` is a 12-entry action table referenced from `0x0059427f`, and `0x00594658` begins padding.
- `0x00594e12-0x00594e20` is alignment, `0x00594e20-0x00594e5f` is real raw TextEditPane helper code, and `0x00594e5f-0x00594e60` is the one-byte pad before support objects.
- [UID:0002XX][0x00594e60-0x00595760.TextEditSupportObjects](by-memory/0x00594e60-0x00595760.TextEditSupportObjects.md) must remain a non-emitting audit map because it crosses [UID:0002RV][0x00595390-0x005954b3.TextBoxPaneConstructor](by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md). [UID:0003M7][0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane](by-memory/0x00594e60-0x00595389.TextEditSupportObjectsBeforeTextBoxPane.md) is also now a non-emitting split-audit container; exact pre-TextBoxPane support-object code belongs to [UID:00040S][0x00594e60-0x00594f23.TextEditObjectCoreMethods](by-memory/0x00594e60-0x00594f23.TextEditObjectCoreMethods.md) and [UID:00040T][0x00594f30-0x00595389.TextEditScrapClipboardCore](by-memory/0x00594f30-0x00595389.TextEditScrapClipboardCore.md). Post-TextBoxPane support-object code remains in [UID:0003M8][0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane](by-memory/0x005954c0-0x00595760.TextEditSupportObjectsAfterTextBoxPane.md).

## Evidence Notes

- Wave3 class summary describes a rich text edit control with copy, paste, cut, multiline selection, caret cursor, scrollbar variants, double/triple-click selection, and text formatting.
- IDA MCP reports 26 direct references to the constructor and six references to `CopySelectionToScrap`.
- `TextEditPane::OnDraw` calls `IterateTextRuns` with [UID:0000UK][DrawTextRunCallback_00593DB0](by-item/DrawTextRunCallback_00593DB0.md).
- 2026-06-07 A004 Batch 068 split exact child docs for [UID:00030C][0x00590810-0x005909e3.TextEditPaneOnDraw](by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md), [UID:00030F][0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent](by-memory/0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent.md), [UID:00030E][0x00590de0-0x00591180.TextEditPaneOnMouseEvent](by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md), and [UID:00030D][0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion](by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md), confirming boundaries, virtual handler shape, key/mouse selection behavior, render/invalidation callees, and the mouse switch-table tail.
- [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md) confirms text storage at `+0x134` can be copied out through a bounded UTF-16 accessor used by [UID:0002OA][0x00498c10-0x00498c1f.TextEditControlPaneReadText](by-memory/0x00498c10-0x00498c1f.TextEditControlPaneReadText.md).
- UID00011H split evidence resolves wrapper-facing editor dependencies without disturbing unrelated editor families: lower `0x0058ee50/0x0058ee70` write max length/max lines at `+0x16c/+0x16e`; TextEditControlPane passes `IsLegacyAssetMode()` as constructor argument ten; and callback RTTI at `0x0061fcec` plus four caller-local one-pointer lifecycles prove `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>` for `GetText` output. Historical delete-index, `fontId`, `WideString`, and SSO-7 substitutions are rejected.
- IDA data xrefs pass [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) into the same text-run/layout family. B001's 2026-06-16 live IDA/raw PE audit confirms `0x00593b20` has no function or direct start xref but is real raw TextEditPane wildcard/password-mask measure helper code, not fitting-room code.
- 2026-06-25 B007 implementation of [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) resolves that callback's local signature and state blocker without changing class ownership: live MCP session `80de0a67` confirmed `sub_593C20` size `0xc5`, four address-taking data refs, no code refs, callees `0x004baad0`/`0x004ba9a0`, `TextEditPane::IterateTextRuns` callback call shape, four setup sites initializing available width from `this+0x128 - this+0x120`, `m_maskedText` wildcard path, and stale generated `76/84` output.
- 2026-06-26 B006 implementation of [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) resolves the draw callback's local signature/state blocker without changing class ownership: live MCP session `80de0a67` confirmed `sub_593DB0` size `0x146` / 326 bytes (Verified with `int_convert.py`), exactly two address-taking data refs, no raw-neighbor start refs for [UID:0003FD][0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw](by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md), `TextEditPane::IterateTextRuns` callback call shape, `TextRunDrawState` offsets `+0x00/+0x10/+0x20`, `TextRunDrawLineRecord` top/remainingWidth/bottom fields, `TextRunFormatData` text-color/object payload, text-area fields `+0x120/+0x124/+0x128`, alignment mode `+0x8c`, and lower renderer `0x005946b0`.
- 2026-08-22 B003 UID0003FC source-quality evidence closes the raw measurement member: exact `[0x00593cf0,0x00593dad)`, SHA256 `7D11CC7DD7E195A284EAFFDF7DEAACADF05A891E81844EAD0154A04A1D1E1009`, 72 instructions, no current IDA function/name/type/comment, zero start/immediate/pointer routes, `ECX` TextEditPane receiver, seven stack arguments, and `retn 0x1c`. Its object/plain/masked/reset/subtract/clamp/store/false-return body is complete; the prior formal omitted only the inherited final non-object helper call at `0x00593d38`.
- The shared helper route is now source-closed. Calls at `0x00593c72`, `0x00593d38`, `0x00593ed4`, and `0x00594019` all establish a TextEditPane/GrafPort receiver in `ECX`, proving non-static `GrafPort::AdjustVisibleCountForTrailingWhitespace(const wchar_t *, short)` with unsigned-short return. The helper remains receiver-independent internally and preserves its shipped count-versus-last-index comparison.
- Current generated TextEditPane H before this callback contained one TextEditObject, one TextEditScrap, one EPFTextEditObject, one `TextRunMeasureState`, and one target declaration. Only TextEditObject class friendship was absent; no aggregate definition removal or duplicate-class repair is supported.
- 2026-06-12 A003 live IDA MCP rechecked the stale `0x00593d00-0x00593e6b` FittingRoom projection and split the real TextEditPane callback bodies: [UID:0003FC][0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw](by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md) and [UID:0003FD][0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw](by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md). The requested stale slice begins inside the raw measurement variant and ends inside the cdecl draw callback, so it is not a valid ownership/range split.
- Historical B001/B005 evidence established that [UID:0001JS][0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers](by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md) includes cursor dispatch, two adjacent switch tables referenced from `0x00594226` and `0x0059427f`, lower renderer `0x005946b0`, raw helpers at `0x00594190`, `0x00594660`, `0x00594680`, `0x005949c0`, `0x00594a30`, and `0x00594e20`, and the support-object boundary at `0x00594e60`. The old blank/split-required source-debt conclusion is superseded: the aggregate remains blank only as an index, and the complete current inventory supplies exact formal or non-source dispositions for every constituent.
- `TextEditPane::OnDraw` and `InvalidateTextRegion` call [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md), now best routed as `GrafPort::CompositePixels`, a shared GrafPort pixel-effect method. The direct call sites at `0x00590960` and `0x005917a3` apply it to active selection and dirty text-range rectangles; BowGaugeObjectPane remains the other direct consumer at `0x00538ce5`.
- `TextEditPane::OnKeyEvent` handles clipboard hotkeys and constructs local `TextEditScrap` objects on copy/cut paths.
- 2026-06-25 B012 TextPad support sync documents `sub_58FEF0` as the editor-side formatting application helper used by `TextPad::SetFont`/`SetColor`: command bit `1` consumes payload `WORD +0`, bit `2` consumes payload `DWORD +4`, and bit `4` consumes payload `DWORD +8`. The TextPad helper child owns its inferred local 12-byte stack payload; this class page records the TextEditPane ABI so future method-body work keeps `SetColor` at offset `+4`.
- `TextEditPane::OnMouseEvent` uses the module-scope [UID:000303][0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch](by-memory/0x0069be04-0x0069be06.TextEditMouseSelectionAnchorScratch.md) word and `AutoScrollSelectionToPoint` for drag selection.
- 2026-07-16 B001 UID00023W support synchronization resolved the mouse return contract. The later UID00030F callback independently resolved `OnKeyEvent` and adjacent `OnKeyUp` as bool virtuals while preserving the accepted bool `OnMouseEvent(Event *)` union.
- [UID:000039][CopyWindow](by-class/CopyWindow.md) consumes `g_pActiveTextEditPane`, calls `TextEditPane::CopyAllToClipboard()`, and clears the canonical pointer, but it remains a neighboring dialog class rather than being absorbed into the editor implementation. Historical `TextEditPane::SelectAll` consumer wording is superseded by the accepted callback behavior.
- B014 2026-06-22 destructor-band recheck corrects the shared scalar-deleting destructor support range to `0x0048c4d0-0x0048c50b` and rejects the prior ClanBank/item-dialog route. Current evidence keeps TextEditPane as the strongest documented consumer/source-family clue, but vtable fanout means the wrapper should be treated as shared compact/TextEdit/ListPane ABI support until a dedicated owner/name pass resolves it.

## Historical / Superseded 2026-07-13 B005 GetScrollDelta Receipt

- `0x0058ed80-0x0058edc5` is the TextEditPane override of ScrollablePane primary slot `+0x5c`, table word `0x0062dff0`.
- Source ABI is `Point *GetScrollDelta(Point *outDelta, char axis, short oldPosition, short newPosition)`. Project `Point` is y/x. Vertical axis `0` writes line-height-scaled old-minus-new to y and zero x; horizontal axis `1` writes unscaled old-minus-new to x and zero y.
- The evidence-time audit covered base and all six direct ScrollablePane constructor families. The surviving ListPane inventory supplies canonical `GetScrollDelta`; historical `ConvertScrollDelta` and role-only "convert delta" wording are superseded.
- The method's vtable/data references are normal virtual liveness. No new declaration/body is added to the already accepted TextEditPane formal class block because the broader declaration has its own resolved/current surface and exact method-body promotion is outside UID0002ES.
- Scores, metadata, formal block, editor fields, raw callbacks, method-child blockers, excluded ScrollNewGroupPane range, and `TextEditPane.cpp` route remain unchanged.
- [UID:0004JD][0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta](by-memory/0x0047f6b0-0x0047f6e5.ChattingPaneGetScrollDelta.md) supplies the exact sibling ABI and naming proof.

## Historical / Superseded 2026-07-13 UID0003RK Receipt

- [UID:0003RK][0x0059f610-0x005a0626.UserLookPaneParseLookPacket](by-memory/0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md) is an exact external consumer of three existing rich-text operations. It clears MoreInfoPane, ProfilePane, and LegendPane editor state; applies selection formatting with the observed one-byte mask/data payload; and inserts 12-by-12 [UID:00004H][EPFTextEditObject](by-class/EPFTextEditObject.md) instances into LegendPane.
- The accepted class declaration therefore adds only `class TextEditObject;`, `ClearText()`, `ApplySelectionFormat(unsigned char, const void *)`, and `InsertEmbeddedObject(TextEditObject *, int, int)`. All preexisting declaration lines, score `90/91`, UID0000ON owner/emitter route, fields, callbacks, split-required aggregates, and method-body ownership are preserved.
- Target behavior supplies exact caller contracts, not ownership transfer: UserLookPane.cpp consumes these APIs, while implementations and support objects remain in TextEditPane.cpp. No raw offset, duplicate body, new child UID, or third-party source import is introduced.

## UID00030C OnDraw And Geometry Helper Integration - 2026-07-19

- [UID:00030C][0x00590810-0x005909e3.TextEditPaneOnDraw](by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md) now emits the exact source-authored `virtual void TextEditPane::OnDraw()` body through this class. The unique 467-byte method has 19 basic blocks, cyclomatic complexity 7, 168 instructions, nine primary-vtable slot-`+0x6c` routes, and no ordinary direct-call requirement.
- `TextRunDrawState` is now a complete declaration before `TextEditPane`, not a forward declaration. Its exact source layout is two `RectBounds` records followed by `bool applyRunTextColor`; OnDraw zero-initializes it before the existing cdecl `DrawTextRunCallback` iterator route.
- `EPFTextEditObject` intentionally has no explicit destructor declaration in the complete H. Fresh canonical IDA on 2026-08-18 proves `0x00595630` is the sole EPF vtable destructor slot and combines implicit derived teardown with scalar-delete handling; the virtual `TextEditObject` base makes the implicit C++03 derived destructor virtual without an out-of-line source definition.
- Private [UID:0004T1][0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles](by-memory/0x00591520-0x00591639.TextEditPaneBuildTextRangeRectangles.md) owns endpoint normalization and same-line/first/middle/final rectangle construction into caller-owned `List(sizeof(RectBounds),16)` storage. Its source return is void; residual EAX from the final Append is compiler residue.
- Private [UID:0004T2][0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY](by-memory/0x00592bb0-0x00592c20.TextEditPaneGetLineIndexForY.md) returns a signed-short line index from a binary search over current and next 16-byte line-record tops. OnDraw uses `clip.bottom - m_textAreaTop - 1` and `clip.top - m_textAreaTop` as its two exact queries.
- Draw-shared flags are `kTextEditBlackBackground` (`0x02`), `kTextEditReadOnly` (`0x04`), `kTextEditUseCurrentTextColor` (`0x40`), and `kTextEditInteractive` (`0x80`). The historical `NoImeFocus` label covered only one consequence of flag `0x04`; OnKey mutation and OnDraw caret suppression prove read-only semantics.
- OnDraw uses inherited `m_drawMode`, `m_drawColor`, `m_bounds`, `m_textColor`, `m_textBackColor`, and exact Surface slot-7 `g_pfnFillRect`. It preserves the background branch's color restore and the terminal caret branch's intentional no-restore asymmetry.
- Signed-short `m_selectionStart`/`m_selectionEnd`, project `Point {y,x}`, automatic `List` lifetime, inherited `CompositePixels`, caret left/right/bottom geometry, and compiler-only cookie/EH cleanup are exact source contracts. No resource, palette, target-local pixel buffer, external rectangle allocation, or explicit ABI cleanup belongs in the class source.
- The complete declaration preserves the finalized B001 serialization union (`EncodeState`, 2/16/16/4 tables and output-size contract), finalized B003 ordinary destructor/private `ReleaseFormatObjects`/signed `referenceCount`/compiler-vtable boundary, existing IME and consumer declarations, and every unrelated field and child at same-or-greater detail.

## Current Caveats

- Historical generated helper labels from unrelated feature owners, including RankingEvent and fitting-room projections, are non-authoritative and have been superseded by exact address ownership.
- The mixed scrollbar addresses `0x00561420`, `0x00561a40`, `0x00561b00`, and `0x00561bc0` remain excluded through [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md); that external corridor does not reduce TextEditPane source closure.
- Historical empty-emitter output for the destructor and helper is superseded by the current complete selected-unit formal and waited generated readback.
- Every inventoried TextEditPane source-authored body is supplied or exactly routed, including modeled children, raw helpers, callback counterparts, lower renderers, navigation/wrap helpers, and pre-support code. Broad aggregate pages remain non-emitting indexes solely to prevent duplicate bodies; no active split-required work or future UID creation is needed for `94/94`.
- The exact current split pages are UID00056B-UID00056G under UID0001JM, UID00056H-UID00056O under UID0001JP, and UID00056P-UID00056T under UID0001JS; the parent covered-by lists are the canonical range-to-page manifests.

## Score Rationale

| Metric | Value | Rationale |
| --- | ---: | --- |
| Completion | `94` | The complete declaration, canonical route, all 165 source-authored bodies, five compiler products, constructor/destructor/private helpers, records, Lists, wrapper APIs, callbacks, globals, and no-code boundaries are formally closed in deterministic order. |
| Confidence | `94` | Exact bodies, callers, ABI lifetimes, List/record layouts, IME/active-editor routes, vtables, fields, callbacks, and waited generated assembly agree on the complete class surface. Only unrecoverable original private lexical spelling prevents a perfect score. |

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EM][TextEditControlPane](by-class/TextEditControlPane.md)
- [UID:000039][CopyWindow](by-class/CopyWindow.md)
- [UID:0000EP][TextEditScrap](by-class/TextEditScrap.md)
- [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md)
- [UID:0001JM][0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane](by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md)
- [UID:0002ZZ][0x0058e140-0x0058e228.TextEditPaneDestructor](by-memory/0x0058e140-0x0058e228.TextEditPaneDestructor.md)
- [UID:0004T0][0x005912b0-0x005912fe.TextEditPaneReleaseFormatObjects](by-memory/0x005912b0-0x005912fe.TextEditPaneReleaseFormatObjects.md)
- [UID:0003DV][0x0062df90-0x0062e044.TextEditPaneVtableData](by-memory/0x0062df90-0x0062e044.TextEditPaneVtableData.md)
- [UID:00030C][0x00590810-0x005909e3.TextEditPaneOnDraw](by-memory/0x00590810-0x005909e3.TextEditPaneOnDraw.md)
- [UID:00030F][0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent](by-memory/0x005909f0-0x00590dc5.TextEditPaneOnKeyEvent.md)
- [UID:00030E][0x00590de0-0x00591180.TextEditPaneOnMouseEvent](by-memory/0x00590de0-0x00591180.TextEditPaneOnMouseEvent.md)
- [UID:00030D][0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion](by-memory/0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md)
- [UID:000565][0x00591c70-0x00591ca1.TextEditPaneIsPasteUnavailable](by-memory/0x00591c70-0x00591ca1.TextEditPaneIsPasteUnavailable.md)
- [UID:000566][0x00591cb0-0x00591d52.TextEditPaneDuplicateTextRange](by-memory/0x00591cb0-0x00591d52.TextEditPaneDuplicateTextRange.md)
- [UID:0001JP][0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters](by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md)
- [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md)
- [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md)
- [UID:0003FC][0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw](by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md)
- [UID:0003FD][0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw](by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md)
- [UID:0001JS][0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers](by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md)
- [UID:0001GJ][0x0055d960-0x005654ec.TextEditPaneScrollbarVariants](by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md)
- [UID:0002O9][0x0058e380-0x0058e3d7.TextEditPaneCopyWideText](by-memory/0x0058e380-0x0058e3d7.TextEditPaneCopyWideText.md)
- [UID:0000CL][ScrollNewGroupPane](by-class/ScrollNewGroupPane.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md)

## Changes

- 2026-08-22 B003 UID0003FC support implementation: preserved `94/94`, owner/emitter/source route, exact `TextRunMeasureState`, one private target declaration, and the one-each TextEditObject/TextEditScrap/EPFTextEditObject H route; reclassified UID0003FC as a complete private member, synchronized the existing aggregate CPP copies of UID0001JQ/UID0003FC/UID0001JR to their exact accepted helper/member formals, recorded exact range/ABI/behavior/helper/source-order evidence, closed inherited GrafPort linkage plus TextEditObject friendship, and historicalized stale blank/raw-callback wording without altering unrelated source.
- 2026-08-22 Agent-B009 UID0000OJ Gate 2A repair: removed copied TextEditObject, TextEditScrap, TextBoxPane, and EPFTextEditObject class bodies from this formal H. Moved the one H child marker before TextEditPane so the two support declarations come from their authoritative class pages before the base editor, and delegated the final guard close to the last ordered file-root H sibling.

- 2026-08-22 Agent-B009 UID0000OJ eleven-claim callback: restored active `94/94` class closure, converted lower-score integration blocks to explicit superseded receipts, and removed active split/raw-helper debt assertions now closed by the complete selected-unit formal inventory. Ownership, formal source, and ordinary implementation remain otherwise unchanged.
- 2026-08-22 Agent-B009 UID0000OJ duplicate-body Gate 2A repair, initial class-only stage: removed exactly 113 class-channel copies whose byte-identical canonical bodies already resided on six exact child pages (69 core, two invalidation, 33 formatting, one measure adapter, one draw adapter, and seven navigation). That intermediate stage temporarily retained 28 class CPP bodies because two exact pages did not yet exist; the supervisor-authorized routing expansion below supersedes only that temporary ownership state.
- 2026-08-22 Agent-B009 UID0000OJ authorized routing expansion: removed the remaining 28 class CPP copies, created exact child owners UID000565/UID000566 for `CPP@00591C70`/`CPP@00591CB0`, and placed one CPP child marker immediately after the preserved preamble/statics. All 141 function bodies now emit from 34 exact by-memory pages; the complete H declaration surface and its independent marker/order remain unchanged.

### Historical / Superseded Change Log (Pre-94/94)

- 2026-07-29 B008 UID000414 accepted ordinary implementation callback:
  - Preserved `93/94`, owner/emitter UID0000ON, reconstructable state, the complete class declaration, every unrelated child/method/field, and `[[CHILDREN]]` placement.
  - Corrected `InsertTextRange` from a private helper with an untyped integer fourth parameter to the public exact contract `int InsertTextRange(const wchar_t *, short, const unsigned short *, TextEditObject *)`.
  - Evidence: current IDA names the helper `TextEditPane__InsertTextRange` at `0x0058fc30`; its 38 callers span TextEditPane and unrelated pane classes, and UID000414 passes initial text, observed signed-short length, null formatting, and null object pointers. The cross-class fanout rejects private/protected access and the typed pointer rejects historical `int formatFlags`.

- 2026-07-19 B004 UID00030C accepted callback:
  - Preserved `93/94`, owner/emitter UID0000ON, reconstructable true, blank position, class closure, and the complete finalized B001/B003 serialization/destructor/private-helper/signed-record/IME union.
  - Replaced only the incomplete draw-state/helper portion of the managed declaration: `TextRunDrawState` is complete before OnDraw, and private UID0004T1 `BuildTextRangeRectangles` plus UID0004T2 `GetLineIndexForY` declarations are present exactly once.
  - Added exact OnDraw virtual-route, draw-state, flag, line-search, automatic List, selection/caret, Surface slot-7, compiler-boundary, negative-evidence, and source-placement facts without pruning unrelated current content.

- 2026-07-19 B003 UID0002ZZ accepted callback:
  - Raised `92/94 -> 93/94`, retained UID0000ON owner/emitter, reconstructable true, blank optional position, complete class route, and class closure before `[[CHILDREN]]`.
  - Applied exact R3 by changing only `TextEditFormatRecord::referenceCount` to signed `short` and adding private `ReleaseFormatObjects()` to the complete current declaration.
  - Added UID0002ZZ/UID0004T0 destructor-helper behavior, three-caller/access proof, exact four-List lifecycle, IME/active-editor routes, compiler exclusions, vtable source cause, rejected alternatives, historical correction, and score rationale while preserving every unrelated declaration, field, callback, child, and prior history item.

- 2026-07-19 B001 UID0002ZY accepted callback: raised `91/93 -> 92/94`; installed the exact twelve-argument constructor declaration, four shared record types, generic callback ABI, corrected `m_formatTable`/`m_formatRuns`, source-facing alignment/thousands bytes, private helper declarations, and exact file-local callback friends. Preserved every unrelated method, child, source route, prior support union, and class closure before `[[CHILDREN]]`; historical thirteen-argument, `isReadOnly`/`inputMode`, reversed-table, 24-byte line-record, and unresolved-access conclusions are superseded only where the accepted evidence closes them.

- 2026-07-16 B001 UID00023W accepted implementation callback: changed only the managed declaration's `OnMouseEvent(Event *)` return from `int` to `bool`, added the AL/primary-slot/dispatcher rationale, and preserved the score, owner/emitter, full layout, `OnKeyEvent`, and every unrelated declaration.
- 2026-07-15 B002 UID00031G accepted callback support sync:
  - Score and metadata remain `91/93`, owner/emitter UID0000ON, reconstructable true, and blank position.
  - Added only the `Point` forward declaration and const public `GetCaretRange(short *, short *)` / `GetCaretLocalPoint(Point *, short)` declarations required by exact lower helpers and the IMEPanes consumer route.
  - Preserved the complete prior class union, every unrelated declaration/field/callback/split/history item, and the broad score caps. No helper body or ownership moved into IMEPanes.
- 2026-07-14 Agent-B003 UID0003R9 callback: changed `90/91 -> 91/93`; preserved owner/emitter UID0000ON, reconstructable state, blank position, all unrelated declarations/fields/callbacks/splits/history, and the complete class-closing `};` before `[[CHILDREN]]`. Applied exact R2 by replacing only the stale explicit output-reference `GetText` declaration with return-by-value hidden-result `GetText() const` and adding target-proven `GetTextAreaBounds(RectBounds *) const`. Added lower `0x0058e3e0`, UID0003R9, UID0004K5, and external caller lifecycle proof; exact `0x0058f080/0x0058f490` text-area copy/set evidence; WideString/SSO rejection; lexical/access/file caps; and unchanged broad-editor blockers.

- 2026-07-13 B005 UID0003RK accepted callback support sync:
  - Score, metadata, route, all prior declaration lines, and editor evidence remain unchanged at `90/91`, owner/emitter UID0000ON.
  - Added only the `TextEditObject` forward declaration and public `ClearText`, `ApplySelectionFormat`, and `InsertEmbeddedObject` declarations required by the exact UserLookPane OnActivate callsites.
  - Preserved all unrelated editor methods, fields, callback/split blockers, source boundaries, generated-name rejections, and historical evidence.
- 2026-07-13 B002 made-by scrolled-text compile-support synchronization:
  - Score and ownership unchanged at `90/91`, owner/emitter UID0000ON.
  - Added public declarations for `PasteFromClipboard(TextEditScrap *)`, `GetLineCount() const`, `SetViewportBounds(const RectBounds *)`, and `SetTextAreaBounds(const RectBounds *)`; added the `TextEditScrap` forward declaration; and moved the existing `OnDraw` declaration from protected to public exactly once.
  - Evidence: accepted UID00019X report C11-C13/C29 and exact constructor child UID0004MA consume these interfaces; lower helper behavior/ABI and OnDraw ownership were already documented here. No unrelated method, field, score, or child ownership changed.

- 2026-07-13 B003 UID00011H generated-structure correction:
  - Moved `[[CHILDREN]]` after the complete `TextEditPane` class-closing `};`, keeping declarations inside the class and all child contributors at namespace scope.
  - Removed raw offset and inferred/provisional audit comments from formal C++ only. The complete `+0x134-0x173` field map, stable versus inferred names, provisional state dispositions, record sizes, and confidence caps remain in `Observed State`, declaration policy, helper tables, and history prose.

- 2026-07-13 B003 UID00011H implementation support sync:
  - Changed `89/88 -> 90/91`; owner/emitter/reconstructable state and unrelated child/callback inventory remain unchanged.
  - Replaced the formal declaration with the accepted exact block: constructor argument ten `legacyAssetMode`; signed-short `CopyWideText`; exact pointer-backed wide StringBase `GetText`; text length, decode, insert, mask/edit-state, mode, and wrapper dependency declarations; `m_maxLength +0x16c`; `m_maxLines +0x16e`; and separate provisional `+0x172` state.
  - Evidence: UID00011H live lower-setter/constructor/type/caller pass, registered wrapper children UID0004K3/UID0002OA/UID0004K5/UID0004K6, and compiler RTTI/caller-local StringBase lifecycles. No unrelated TextEditPane source family, score route, callback, aggregate, or support-object disposition was removed.

- 2026-07-07 B005 UID0001JS implementation callback support sync:
  - Score unchanged at `89/88`; class formal C++ remains declaration-only and no aggregate method body was added.
  - Updated method-family, helper-name, raw-boundary, evidence, and caveat sections for [UID:0001JS][0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers](by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md): target now records `88/90`, two adjacent local switch tables, live raw helpers, inferred `TextEditPane::DrawTextRunSegment`, and split-required/no aggregate C++ policy.
  - Evidence: B005 report `tools/leaser/Agents/Agent-B005/research/0001JS-TextEditPaneInputNavigationWrapAndTextRunHelpers-source-quality.md` and MCP session `supervisor-nexustk-20260707` confirmed the exact range, raw helper liveness, switch table refs from `0x00594226` and `0x0059427f`, and `0x00594e60` support-object boundary. No child pages or UIDs were created.

- 2026-06-25 B007 TextRunMeasureCallback implementation support sync:
  - Score unchanged at `89/88`.
  - Updated the method/helper table and class caveats to reflect that [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) is file-local first-draft ready with `TextRunMeasureState`, while draw/raw callback records remain unresolved for their own bodies.
  - Evidence: B007 MCP session `80de0a67` confirmed the callback's exact `0xc5` body, four address-taking data refs, no direct code refs, iterator ABI, state offsets `+0/+4/+8`, optional embedded-object pointer at `TextRunFormatData+0x08`, line-record writes at `+0x08/+0x0c`, and masked-text wildcard route through `m_maskedText`. Added strict-private friend/access policy notes for file-local callback bodies.

- 2026-06-25 B012 TextPad format-payload support sync:
  - Score unchanged at `89/88`.
  - Added the `sub_58FEF0` payload ABI needed by [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md): command bit `1` reads payload `WORD +0`, bit `2` reads `DWORD +4`, and bit `4` reads `DWORD +8`. TextPad owns the local payload construction; TextEditPane owns the format application helper.

- 2026-06-26 B006 DrawTextRunCallback implementation support sync:
  - Score unchanged at `89/88`.
  - Updated the method/helper table, observed field map, declaration policy, and caveats to reflect that [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) is file-local first-draft ready with `TextRunDrawState`, `TextRunDrawLineRecord`, text-area/alignment fields, optional inline-object dispatch, final whitespace trim, and lower renderer forwarding. Class formal C++ remains declaration-only; method-body C++ stays on the exact child page.
  - Evidence: B006 MCP session `80de0a67` confirmed the `0x146` target body, two address-taking refs, no route to the raw draw variant, iterator ABI, state offsets `+0x00/+0x10/+0x20`, and `TextRunFormatData+0x04/+0x08` payload roles.

- 2026-06-16 B001 TextEditPane source-quality audit:
  - Score unchanged at `88/85`.
  - Updated the main TextEditPane formatting/input cluster from `0x00591d60-0x00594e11` to `0x00591d60-0x00594e60`, refreshed [UID:0001JP][0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters](by-memory/0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md) and [UID:0001JS][0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers](by-memory/0x00594040-0x00594e60.TextEditPaneInputNavigationWrapAndTextRunHelpers.md) link text, and recorded that `0x00593b20` and `0x00594e20-0x00594e5f` are real raw TextEditPane code rather than fitting-room/support-object ownership.
  - Evidence: B001 live IDA MCP and raw PE audit confirmed exact function/raw/data/padding spans, rejected stale generated labels, preserved TextEditPane file ownership, and kept final C++ blocked only by unresolved source-quality field/type/helper names.
- 2026-06-18 B003 CompositePixels support sync:
  - Score unchanged at `88/85`.
  - Replaced stale BowGauge-emitted/shared-surface wording for [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) with the accepted `GrafPort::CompositePixels` route.
  - Evidence: B003 raw PE/Capstone recheck found TextEditPane direct callers at `0x00590960` in `OnDraw` and `0x005917a3` in `InvalidateTextRegion`; the function uses GrafPort draw state, embedded surface-context fields, and palette mapping, so TextEditPane is a consumer for selection/dirty-rectangle effects rather than the source owner.

- 2026-06-20 B005 Rule 26 source-quality incorporation:
  - Before: `88/85`, blank formal C++, and caveats still framed around unresolved field/helper names.
  - Changed to: `89/88`, declaration-only class C++ with `[[CHILDREN]]`, stronger field map, source-placement and generated-name rejection sections, module-static naming, raw callback/support-object boundary policy, and child C++ readiness notes.
  - Evidence: B005 local PE/report reanalysis matched existing child/source docs for constructor/destructor/copy/serialization/draw/key/mouse/callback/global routes, resolved high-probability source names for `m_textStorage`, `m_lineTable`, `m_styleRuns`, `m_formatRecords`, selection/flag/masked-text fields, `g_pActiveTextEditPane`, `s_styledUnicodeClipboardFormat`, and `s_mouseSelectionAnchor`, and kept method-body C++ on exact child pages until signatures and callback-state layouts are final.

- 2026-06-22 B014 ClanDestructorBand support sync:
  - Corrected the shared scalar-deleting destructor support range from `0x0048c4d0-0x0048c50a` to `0x0048c4d0-0x0048c50b`.
  - Evidence: direct PE/vtable fanout reanalysis rejects the stale ClanBank/item-dialog route and keeps this as shared compact/TextEdit/ListPane wrapper support pending a dedicated source-quality owner pass. Scores and owner/emitter are unchanged.

- 2026-06-07 A004 Batch 068 parent-gate refresh:
  - Before: `88/82`; confidence was below the corrected direct-parent gate for exact TextEditPane method children.
  - After: `88/85`.
  - Evidence: live IDA MCP split exact child pages for draw, key event, mouse event plus local switch table, and final text-region invalidation; these combine with existing constructor/destructor/copy/serialization/formatting/input-navigation evidence and the already refreshed [UID:0000ON][TextEditPane](by-file/TextEditPane.md) source-file parent at `88/85`.
  - Remaining cap: final field names, generated helper-name pollution, and several still-unsplit core helper slices prevent higher confidence/completion.

- 2026-06-12 A003 stale fitting-room slice repair:
  - Before: the class page only rejected the generated `0x00593b20` fitting-room marker and did not account for the raw no-function callback variants at `0x00593cf0` and `0x00593f00`.
  - After: added the two raw TextEditPane callback children and recorded why the requested `0x00593d00-0x00593e6b` FittingRoom slice is invalid.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, disassembly, and byte checks on `0x00593ce5-0x00594040`.

- 2026-06-07 A004 Batch 046 range sync:
  - Updated [UID:0001JM][0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane](by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md) to the corrected half-open endpoint `0x0058dce0-0x005917c9` after IDA MCP confirmed `sub_591740` covers the prior endpoint byte and the next function begins at `0x005917d0`.
  - Score unchanged at `88/82`; final field names and generated helper-name pollution still cap confidence.

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed representative editor method starts across construction/destruction, text access, serialization, viewport, layout, mutation, drawing/events, invalidation, and input navigation at `0x0058dce0`, `0x0058e140`, `0x0058e380`, `0x0058e490`, `0x0058e890`, `0x0058edd0`, `0x0058fc30`, `0x00590810`, `0x00591180`, and `0x00594040`; `0x00591d60` remains a raw non-function formatting-run island inside the documented range. This page and parent [UID:0000ON][TextEditPane](by-file/TextEditPane.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `88`, confidence `82`.
- Evidence: the page documents core editor responsibility, stable offsets, active editor global, major method families, callbacks, rendering/helper links, clipboard/scrap behavior, source-owner caveats, and excluded `ScrollNewGroupPane` helper family; confidence remains capped by generated helper-name pollution and unresolved final field names.
- 2026-07-13 B005 UID0002ES support synchronization: preserved `89/88`, metadata, complete formal class declaration, and all editor evidence/blockers; resolved `0x0058ed80` / primary `+0x5c` to canonical `GetScrollDelta` with Point y/x and old-before-new, including line-height-scaled vertical and unscaled horizontal behavior, while retaining `ConvertScrollDelta` only as superseded history.

## 2026-07-29 SpelledPane Gate 2B Consumer Reconciliation

- Supervisor Gate 2B applied the following exact SpelledPane consumers of TextEditPane behavior:
  - A01 `[0x0056bb20,0x0056bbdb)` `SpelledPane__Constructor`, `SpelledPane *__thiscall(SpelledPane *this)`: default constructor selecting EPF/legacy dimensions and initializing the TextEditPane base.
  - A02 `[0x0056bbe0,0x0056bc6f)` `SpelledPane__ConstructorWithDimensions`, `SpelledPane *__thiscall(SpelledPane *this, int viewportWidth, int viewportHeight, int textAreaWidth, int textAreaHeight)`: dimensioned constructor forwarding caller dimensions and fixed text-pane flags.
  - A03 `[0x0056bc70,0x0056bc9d)` `SpelledPane__DeleteLine`, `void __thiscall(SpelledPane *this, short lineIndex)`: clamps a signed line index and resolves the exact text range through TextEditPane helpers before deletion.
  - A06 `[0x0056bea0,0x0056c0d8)` `SpelledPane__RebuildDisplayText`, `void __thiscall(SpelledPane *this)`: rebuilds grouped display text, inserts the group-one separator, omits zero-valued rows, and invalidates the pane.
- Exact applied regular comments remain on the SpelledPane functions; no TextEditPane helper was renamed or retyped. Existing helper targets including `0x0058f150` and `0x0058e2b0`, their bytes, caller edges, and class declarations are unchanged.
- A02 and A03 were modeled at `[0x0056bbe0,0x0056bc6f)` and `[0x0056bc70,0x0056bc9d)`. Their typed disassembly/analysis arguments are exact, while Hex-Rays still fails at dependency calls `0x0056bc15` and `0x0056bc84`. This is a bounded decompiler lifting limitation, not evidence against the methods, their TextEditPane interactions, or the recovered source.
- Preserved SpelledPane hashes are A01 `321465B15E9654093572074551FF493C68B0102C5D7C7D3087418F63735A8FE0`, A02 `E3E4C79E6F5F16D21C7BE146F023286731D8E2654BD4C0F264F91353C3320897`, A03 `96A4495DEE8819B53938A24233794BA33946EED9AE454631AE7EB53C11898EAD`, and A06 `BFECC11B3496B95C45768061A575DEB622EC45F575B6FAB9BFB9B1AC8100ACE1`.
- Authoritative saved IDB: session `1da2b2ae`, SHA256 `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, 143,190,636 bytes, `2026-07-29T13:59:50.138-04:00`; prestate backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B001-UID0001HA-20260729-135636.i64`; catalog entry `0361`. Agent-B001 made no IDA mutation.

## 2026-07-29 SpelledPane Shared IDB Currentness Recheck

- `0E0AF938...AB481` is historical and current authoritative session `1da2b2ae` is `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, saved `2026-07-29T14:12:44.7229687-04:00`; `03F102...DBE5DA` and earlier are historical prestates.
- Read-only recheck preserved TextEditPane size `0x174`, A01/A02/A03/A06 consumer types and body hashes, and protected helpers `sub_58F150`/`sub_58E2B0` with exact existing prototypes/comments. A02/A03 typed analysis remains exact despite the same bounded Hex-Rays call failures. Agent-B001 did not mutate/save IDA.
- Currentness supersession: `3C8F3178...5B69` is historical. Current authoritative session `1da2b2ae` is `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, last write `2026-07-29T14:22:15.9735862-04:00`; TextEditPane/dependency evidence again matched.
- Dated currentness supersession at that checkpoint: `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B` and every earlier identity became history when session `1da2b2ae` was saved as SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, last write `2026-07-29T14:42:53.5091352-04:00`. That bounded UID0001HA readback found zero drift across exact names, ranges, prototypes, four comment channels, body hashes, xref counts, padding, callback slots, literals, helper identities, and relevant type state. A02/A03 retained exact typed analysis with the same bounded Hex-Rays failures at `0x0056bc15` and `0x0056bc84`. Agent-B001 did not mutate or save IDA.

## 2026-07-30 UID000414 InsertTextRange Protected Readback

- Supervisor Gate 2B for UID000414 intentionally left `TextEditPane__InsertTextRange` unchanged at `[0x0058fc30,0x0058fe93)`. Current prototype remains `int __thiscall(TextEditPane *this, const wchar_t *text, __int16 length, const unsigned __int16 *formatPayload, TextEditObject *textObject)` with 38 inbound xrefs.
- Address-regular, address-repeatable, and function-repeatable comments remain blank. Function-regular comment remains exactly `Source member InsertTextRange. Source-facing name is inferred; wchar_t text and signed-short length are supported by all observed callers.` The physical source arguments remain typed `text`, `length`, `formatPayload`, and `textObject`.
- UID000414 Gate-2B checkpoint `87D34CCD103CC97F107DBABF1CA089FCE223F1650D5376A0DCB48C0E46F500F2`, 143,192,020 bytes, saved `2026-07-30T07:11:07.1602926-04:00`, is dated history. Current authoritative saved IDB is session `1da2b2ae`, SHA256 `83C20CE9E13A19CA3C5501998110D490FA3D2D2EA5FE774AE1F880403C294A9E`, 143,193,954 bytes, saved `2026-07-30T07:36:29.3601106-04:00`. The bounded no-change readback preserves helper bytes, range, type, comment, and 38 caller edges; the UID000414 target still consumes it through typed `const wchar_t *initialText` and signed-short length.

## UID0000OJ Whole-File Incorporation - 2026-08-16

The class owner now carries only the translation-unit CPP preamble/statics, one CPP child insertion point, and the complete H contract. Exactly 141 function bodies reside only on 34 canonical exact by-memory pages, including UID000565 and UID000566 for the former file-root raw bodies, so every ordinary source key has one formal owner and one emitted definition; support classes remain separately owned.

The accepted claim/evidence/destination rows incorporated for this owner are preserved verbatim:

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination | Action | Gate-1 state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0000OJ-028 | 0000EO | Add both helper declarations inside TextEditPane private declarations. | very-strong | Member field access and call topology. | UID0000EO formal H | incorporate | proposed |
| C0000OJ-031 | 0000EO | Add exact pre-class and post-class H child ordering for support classes, TextBoxPane, and EPFTextEditObject. | very-strong | Required same-header source placement and complete-base ordering. | UID0000EO formal H | incorporate | proposed |
| C0000OJ-048 | 0000EO | Incorporate complete TextBox class/layout/vtable relationship. | original-proof | Type/vtable/RTTI/caller evidence. | UID0000EO body/formal H | incorporate | proposed |
| C0000OJ-443 | 0000EO | Preserve enum `TextNavigationAction` with exact values: 0..11 character/right/up/down/word/page/line/document actions. | very-strong | Current formal/generated source and control-flow tables agree. | UID0000EO formal H/UID0000ON CPP | already-present | proposed |
| C0000OJ-444 | 0000EO | Preserve enum `TextRunSegmentFlags` with exact values: 0x01 next and 0x02 previous. | very-strong | Current formal/generated source and control-flow tables agree. | UID0000EO formal H/UID0000ON CPP | already-present | proposed |
| C0000OJ-445 | 0000EO | Preserve enum `TextEditPaneTextAlignment` with exact values: 0 left, 1 center, 2 right, 3 trim-final-whitespace. | very-strong | Current formal/generated source and control-flow tables agree. | UID0000EO formal H/UID0000ON CPP | already-present | proposed |
| C0000OJ-460 | 0000EO | Preserve TextEditPane layout `0x174` and exact 30-member state. | original-proof | Live named UDT and complete offset table. | UID0000EO formal H/layout | already-present | proposed |
| C0000OJ-465 | 0000EO | Preserve TextEditLineRecord: 16 bytes: startIndex@0, top@4, remainingWidth@8, wrapState@c. | very-strong | Current formal H plus live field/callback use. | UID0000EO formal H/type inventory | already-present | proposed |
| C0000OJ-466 | 0000EO | Preserve TextRunFormatData: 12 bytes: legacyAssetMode@0, textColor@4, object@8. | very-strong | Current formal H plus live field/callback use. | UID0000EO formal H/type inventory | already-present | proposed |
| C0000OJ-467 | 0000EO | Preserve TextEditFormatRecord: 16 bytes: signed referenceCount@0, format@4. | very-strong | Current formal H plus live field/callback use. | UID0000EO formal H/type inventory | already-present | proposed |
| C0000OJ-468 | 0000EO | Preserve TextEditFormatRun: 4 bytes: startIndex@0, formatIndex@2. | very-strong | Current formal H plus live field/callback use. | UID0000EO formal H/type inventory | already-present | proposed |
| C0000OJ-469 | 0000EO | Preserve TextEditRange: 4 bytes: start@0, end@2. | very-strong | Current formal H plus live field/callback use. | UID0000EO formal H/type inventory | already-present | proposed |
| C0000OJ-470 | 0000EO | Preserve TextRunMeasureState: 12 bytes: availableWidth@0, remainingWidth@4, scratch@8. | very-strong | Current formal H plus live field/callback use. | UID0000EO formal H/type inventory | already-present | proposed |
| C0000OJ-471 | 0000EO | Preserve TextRunDrawState: 36 bytes: lineRect@0, clippedLineRect@10, applyRunTextColor@20. | very-strong | Current formal H plus live field/callback use. | UID0000EO formal H/type inventory | already-present | proposed |
| C0000OJ-472 | 0000EO | Preserve TextRunIteratorCallback: cdecl callback over line/format/text/offset/count/flags/context/pane. | very-strong | Current formal H plus live field/callback use. | UID0000EO formal H/type inventory | already-present | proposed |
| C0000OJ-493 | 0000EO | Record dated generated H snapshot `1B3E88A61A9710DE87305B0B9BA50F8F49AF5018A2E61C7EC4031D30DC98414C`, 10,210 bytes/262 lines. | very-strong | Physical read at 2026-08-16T11:00:12.2363292Z; mutable validator output. | Validator Results/generated evidence | historicalize | proposed |
| C0000OJ-508 | 0000EO | Include `../../util/LObject.h` before support classes in TextEditPane.h. | original-proof | TextEditObject and TextEditScrap derive from LObject. | UID0000EO formal H include order | incorporate | proposed |
| C0000OJ-509 | 0000EO | Include `../../render/EPFTileContext.h` before EPFTextEditObject in TextEditPane.h. | original-proof | EPFTextEditObject contains EPFTileContext by value. | UID0000EO formal H include order | incorporate | proposed |
