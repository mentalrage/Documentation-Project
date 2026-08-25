// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NZ
// Source by-file doc: by-file/SpelledPane.md
// UID:000078 | by-class/LineIterator.md | Completion:92 | Confidence:94
#include "../../util/StringBase.h"

class LineIterator
{
public:
    LineIterator(const wchar_t *text, unsigned int length)
        : m_text(text),
          m_length(length),
          m_offset(0)
    {
    }

    virtual ~LineIterator()
    {
    }

    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &
    ReadNextLine(
        mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &line);

private:
    const wchar_t *m_text;
    unsigned int m_length;
    unsigned int m_offset;
};

// UID:000190 | by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md | Completion:89 | Confidence:92
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &
LineIterator::ReadNextLine(
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > &line)
{
    const wchar_t *const first = m_text + m_offset;

    while (m_offset < m_length) {
        const wchar_t ch = m_text[m_offset++];
        if (ch == L'\n') {
            break;
        }
    }

    line.InitializeWideFromRange(first, m_text + m_offset);
    return line;
}

// UID:0001HL | by-memory/0x00573240-0x00573247.LineIteratorDestructor.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:000078][LineIterator](by-class/LineIterator.md).

// UID:00038W | by-memory/0x00624780-0x00624788.LineIteratorVtableData.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:000078][LineIterator](by-class/LineIterator.md).

// UID:0000DK | by-class/SpelledPane.md | Completion:94 | Confidence:94
#include "SpelledPane.h"
#include <stddef.h>
#include <wchar.h>
#include "../../localization/LanguageMan.h"

extern bool g_useEpfAssets;
bool IsLegacyAssetMode();

// UID:0004YO | by-memory/0x0056bb20-0x0056bbdb.SpelledPaneConstructor.md | Completion:94 | Confidence:95
SpelledPane::SpelledPane()
    : TextEditPane(g_useEpfAssets ? 169 : 145,
                   g_useEpfAssets ? 83 : 108,
                   g_useEpfAssets ? 155 : 145,
                   g_useEpfAssets ? 83 : 108,
                   128, 0, false, true, 6,
                   IsLegacyAssetMode(), true, false),
      m_entries()
{
}

// UID:0004YP | by-memory/0x0056bbe0-0x0056bc6f.SpelledPaneConstructorWithDimensions.md | Completion:92 | Confidence:94
SpelledPane::SpelledPane(int viewportWidth,
                         int viewportHeight,
                         int textAreaWidth,
                         int textAreaHeight)
    : TextEditPane(viewportWidth, viewportHeight,
                   textAreaWidth, textAreaHeight,
                   128, 0, false, true, 6,
                   IsLegacyAssetMode(), true, false),
      m_entries()
{
}

// UID:0004YQ | by-memory/0x0056bc70-0x0056bc9d.SpelledPaneDeleteLine.md | Completion:92 | Confidence:94
void SpelledPane::DeleteLine(short lineIndex)
{
    short start;
    short end;
    GetLineTextRange(lineIndex, &start, &end);
    DeleteTextRangeAndClampSelection(start, end);
}

// UID:0004YR | by-memory/0x0056bca0-0x0056be17.SpelledPaneAddOrUpdateEntry.md | Completion:94 | Confidence:95
void SpelledPane::AddOrUpdateEntry(const wchar_t *text, int value, int group)
{
    const WideString entryText(text);

    for (std::vector<SpelledPaneEntry>::iterator it = m_entries.begin();
         it != m_entries.end(); ++it) {
        if (it->text.CompareWideLiteral(entryText.c_str()) == 0 &&
            it->group == group) {
            it->value = value;
            return;
        }
    }

    SpelledPaneEntry entry;
    entry.text = entryText;
    entry.value = value;
    entry.group = group;
    m_entries.push_back(entry);

    const short oldPosition = GetScrollPosition(0);
    RebuildDisplayText();
    ApplyScrollPosition(0, GetScrollPosition(0), oldPosition);
}

// UID:0004YS | by-memory/0x0056be20-0x0056bea0.SpelledPaneRemoveEntry.md | Completion:94 | Confidence:95
void SpelledPane::RemoveEntry(const wchar_t *text, int group)
{
    const WideString entryText(text);

    for (std::vector<SpelledPaneEntry>::iterator it = m_entries.begin();
         it != m_entries.end(); ++it) {
        if (it->text.CompareWideLiteral(entryText.c_str()) == 0 &&
            it->group == group) {
            m_entries.erase(it);
            RebuildDisplayText();
            ApplyScrollPosition(0, GetScrollPosition(0), 0);
            return;
        }
    }
}

// UID:0004YT | by-memory/0x0056bea0-0x0056c0d8.SpelledPaneRebuildDisplayText.md | Completion:94 | Confidence:95
void SpelledPane::RebuildDisplayText()
{
    WideString displayText;
    bool hasSecondGroup = false;

    for (std::vector<SpelledPaneEntry>::const_iterator it = m_entries.begin();
         it != m_entries.end(); ++it) {
        if (it->group == 1) {
            hasSecondGroup = true;
            break;
        }
    }

    for (int group = 0; group != 2; ++group) {
        if (group == 1 && hasSecondGroup)
            displayText.AppendWideLiteral(L"------------------------\n", 25);

        for (std::vector<SpelledPaneEntry>::const_iterator it = m_entries.begin();
             it != m_entries.end(); ++it) {
            if (it->group != group || it->value == 0)
                continue;

            WideString line;
            if (it->value > 0)
                line.FormatWide(g_pLanguageMan->GetLocalizedString(222),
                                it->text.c_str(), it->value);
            else
                line.FormatWide(L"%s", it->text.c_str());
            displayText.AppendWideLiteral(line.c_str(), line.length());
            displayText.AppendWideLiteral(L"\n", 1);
        }
    }

    ClearText();
    InsertTextRange(displayText.c_str(),
                    static_cast<short>(displayText.length()), NULL, 0);
    InvalidateRect(NULL);
}

// UID:000284 | by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md | Completion:92 | Confidence:93
// The function-local static delimiter array is declared and emitted by
// SpelledPane::ParseAndLoadEntries; no duplicate data object is emitted here.

// UID:0004N5 | by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md | Completion:92 | Confidence:94
void SpelledPane::ParseAndLoadEntries(const wchar_t *text, int length)
{
    static wchar_t delimiters[] = L" \t";

    m_entries.clear();

    LineIterator lines(text, length);
    WideString line;
    lines.ReadNextLine(line);

    while (!line.empty()) {
        const int delimiter =
            line.FindLastOf(delimiters, 0xffffffffU,
                            static_cast<unsigned int>(wcslen(delimiters)));
        if (delimiter != -1) {
            const int textLength =
                line.FindLastNotOf(delimiters,
                                   static_cast<unsigned int>(delimiter),
                                   static_cast<unsigned int>(wcslen(delimiters))) + 1;

            SpelledPaneEntry entry;
            WideString entryText;
            line.SubstringWide(entryText, 0,
                               static_cast<unsigned int>(textLength));
            entry.text = entryText;

            WideString valueText;
            line.SubstringWide(valueText,
                               static_cast<unsigned int>(delimiter + 1),
                               0xffffffffU);
            entry.value = static_cast<int>(valueText.ToLong());

            // The original body leaves entry.group indeterminate.
            m_entries.push_back(entry);
        }

        WideString nextLine;
        lines.ReadNextLine(nextLine);
        line = nextLine;
    }

    RebuildDisplayText();
}

// UID:0004YU | by-memory/0x0056c2e0-0x0056c2e5.SpelledPaneHandleKeyOrTextEvent.md | Completion:94 | Confidence:95
bool SpelledPane::HandleKeyOrTextEvent(Event *event)
{
    (void)event;
    return false;
}

// UID:0004YV | by-memory/0x0056c2f0-0x0056c2f5.SpelledPaneOnMouseEvent.md | Completion:94 | Confidence:95
bool SpelledPane::OnMouseEvent(Event *event)
{
    (void)event;
    return false;
}

// UID:0004YW | by-memory/0x0056c300-0x0056c3f1.SpelledPaneOnFrameUpdate.md | Completion:94 | Confidence:95
void SpelledPane::OnFrameUpdate(const FrameUpdateContext *context)
{
    (void)context;

    for (std::vector<SpelledPaneEntry>::iterator it = m_entries.end();
         it != m_entries.begin();) {
        --it;
        if (it->value > 0)
            --it->value;
        if (it->value == 0)
            it = m_entries.erase(it);
    }

    const short oldPosition = GetScrollPosition(0);
    RebuildDisplayText();
    ApplyScrollPosition(0, GetScrollPosition(0), oldPosition);
    ScheduleFrameCallback(50);
}
