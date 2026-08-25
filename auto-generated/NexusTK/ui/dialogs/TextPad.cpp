// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OQ
// Source by-file doc: by-file/TextPad.md
// UID:0000EU | by-class/TextPad.md | Completion:94 | Confidence:93
#include "TextPad.h"

#include <wchar.h>
#include <windows.h>

#include "../../app/Application.h"
#include "../../platform/PlatformApi.h"
#include "../../render/Surface.h"
#include "../../util/MemoryMan.h"
#include "../MainUiGraph.h"
#include "../controls/TextEditControlPane.h"
#include "../controls/TextEditPane.h"
#include "../core/Event.h"
#include "../core/ScreenPane.h"

[[No Children Attached]]

// UID:0001JV | by-memory/0x00595900-0x00596242.TextPad.md | Completion:94 | Confidence:94
TextPad::TextPad()
    : DialogPane(L"", 0xffff, 0)
{
    RectBounds mainBounds = { 0, 0, g_screenWidth, g_screenHeight - 32 };
    TextEditControlPane *mainEdit = new TextEditControlPane(
        L"", false, 0x80, 0x8f, &mainBounds,
        false, true, true, false, 1.0f, false);
    AddControl(mainEdit);
    mainEdit->SetMaxLines(2000);
    mainEdit->SetMaxLength(30000);
    mainEdit->SetHandlesEnterKey(true);

    RectBounds commandBounds = {
        0, g_screenHeight - 32, g_screenWidth, g_screenHeight
    };
    TextEditControlPane *commandEdit = new TextEditControlPane(
        L"", false, 0x80, 0x8f, &commandBounds,
        false, false, true, false, 1.0f, false);
    AddControl(commandEdit);

    RectBounds frameBounds = { 0, 0, g_screenWidth, g_screenHeight };
    SetHoverControl(0);
    StoreClampRect(&frameBounds);
    OnCreate(&frameBounds, 0, 0, g_mainUiLayerSlots.rootPaneLayerContext);
    OnShow(0, g_pScreenPane);
}

bool TextPad::HandleKeyOrTextEvent(Event *event)
{
    if (g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers) == 13 &&
        m_activeControlId == 1 &&
        event->m_type == kEventKeyDown) {
        TextEditControlPane *commandEdit = GetChild<TextEditControlPane>(1);
        wchar_t commandLine[1024];
        commandEdit->ReadText(commandLine, 1023);
        SendText(commandLine);
        commandEdit->GetTextEditPane()->SetSelectionRange(0, 0x7fff);
        return true;
    }
    return DialogPane::HandleKeyOrTextEvent(event);
}

void TextPad::DrawBackground()
{
    SetDrawColor(0x80);
    SetDrawMode(0);
    g_pfnFillRect(this, &m_visibleBounds);
}

void TextPad::DrawBorder()
{
}

// UID:0001JW | by-memory/0x00595be0-0x00595f26.TextPadCommandHelper.md | Completion:93 | Confidence:94
void TextPad::SendText(const wchar_t *commandLine)
{
    if (wcsstr(commandLine, L"Open ") == commandLine) {
        Open(commandLine + 5);
    } else if (wcsstr(commandLine, L"Save ") == commandLine) {
        Save(commandLine + 5);
    } else if (wcsstr(commandLine, L"SetFont ") == commandLine) {
        int fontId;
        swscanf(commandLine + 8, L"%d", &fontId);
        SetFont(static_cast<unsigned short>(fontId));
    } else if (wcsstr(commandLine, L"SetColor ") == commandLine) {
        int color;
        swscanf(commandLine + 9, L"%d", &color);
        SetColor(static_cast<unsigned int>(color));
    }
}

// UID:000248 | by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md | Completion:93 | Confidence:93
void TextPad::Open(const wchar_t *path)
{
    MemoryMan *memoryMan = GetMemoryMan();
    TextEditScrap scrap;
    HANDLE file = g_pfnCreateFileW(path, GENERIC_READ, 0, 0,
        OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, 0);
    DWORD fileSize = GetFileSize(file, 0);
    char *fileBytes = static_cast<char *>(
        memoryMan->AllocateBufferMemory(fileSize + 1));
    DWORD bytesRead;
    ReadFile(file, fileBytes, fileSize, &bytesRead, 0);
    *reinterpret_cast<wchar_t *>(
        fileBytes + fileSize * sizeof(wchar_t)) = L'\0';
    CloseHandle(file);

    const wchar_t *text = reinterpret_cast<const wchar_t *>(fileBytes);
    unsigned int textChars = static_cast<unsigned int>(wcslen(text));
    scrap.SetText(text, static_cast<int>(textChars));
    if (textChars < fileSize) {
        int payloadSize = *reinterpret_cast<const int *>(
            fileBytes + textChars * sizeof(wchar_t) + sizeof(wchar_t));
        const void *payload = fileBytes + textChars + 5;
        scrap.SetPayload(payload, payloadSize);
    }

    TextEditPane *editor =
        GetChild<TextEditControlPane>(0)->GetTextEditPane();
    editor->SetSelectionRange(0, 0x7fff);
    editor->PasteFromClipboard(&scrap);
    editor->SetSelectionRange(0, 0);
    memoryMan->FreeBufferMemory(fileBytes);
}

void TextPad::Save(const wchar_t *path)
{
    MemoryMan *memoryMan = GetMemoryMan();
    TextEditScrap scrap;
    TextEditPane *editor =
        GetChild<TextEditControlPane>(0)->GetTextEditPane();

    short selectionStart;
    short selectionEnd;
    editor->GetCaretRange(&selectionStart, &selectionEnd);
    editor->SetSelectionRange(0, 0x7fff);
    editor->CopySelectionToScrap(&scrap);
    editor->SetSelectionRange(selectionStart, selectionEnd);

    wchar_t *textBuffer = 0;
    int textBytes = scrap.DuplicateText(&textBuffer);
    void *payloadBuffer = 0;
    int payloadBytes = scrap.DuplicatePayload(&payloadBuffer);
    HANDLE file = g_pfnCreateFileW(path, GENERIC_WRITE, 0, 0,
        CREATE_ALWAYS, FILE_FLAG_SEQUENTIAL_SCAN, 0);

    DWORD bytesWritten;
    if (textBytes > 0)
        WriteFile(file, textBuffer, textBytes, &bytesWritten, 0);
    unsigned char separator = 0;
    WriteFile(file, &separator, 1, &bytesWritten, 0);
    if (payloadBytes > 0) {
        WriteFile(file, &payloadBytes, 4, &bytesWritten, 0);
        WriteFile(file, payloadBuffer, payloadBytes, &bytesWritten, 0);
    }
    CloseHandle(file);

    if (textBuffer != 0)
        memoryMan->FreeBufferMemory(textBuffer);
    if (payloadBuffer != 0)
        memoryMan->FreeBufferMemory(payloadBuffer);
}

void TextPad::SetFont(unsigned short fontId)
{
    TextRunFormatData format;
    format.legacyAssetMode = fontId;
    GetChild<TextEditControlPane>(0)->GetTextEditPane()
        ->ApplySelectionFormat(1, &format);
}

void TextPad::SetColor(unsigned int color)
{
    TextRunFormatData format;
    format.textColor = color;
    GetChild<TextEditControlPane>(0)->GetTextEditPane()
        ->ApplySelectionFormat(2, &format);
}

// UID:0003DY | by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md | Completion:92 | Confidence:96
// TextPad RTTI and vtables are compiler-emitted from UID0000EU's class
// declaration and UID0001JV's virtual method definitions.

// UID:0003DZ | by-memory/0x0062e228-0x0062e268.TextPadCommandStrings.md | Completion:92 | Confidence:96
// TextPad command literals are emitted by UID0001JW's SendText definition.
