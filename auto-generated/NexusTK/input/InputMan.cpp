// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K6
// Source by-file doc: by-file/InputMan.md
// UID:00050J | by-global/g_pInputMan.md | Completion:94 | Confidence:96
#include "InputMan.h"

InputMan *g_pInputMan = 0;

template <>
Singleton<InputMan>::Singleton()
{
    g_pInputMan = static_cast<InputMan *>(this);
}

template <>
Singleton<InputMan>::~Singleton()
{
    g_pInputMan = 0;
}

// UID:00006J | by-class/InputMan.md | Completion:94 | Confidence:95
// UID:00018E | by-memory/0x004e8af0-0x004e970d.InputMan.md | Completion:95 | Confidence:96
#include "../ui/core/Event.h"
#include "../util/List.h"
#include "../util/MemoryMan.h"

#include <deque>
#include <string>
#include <cstring>

extern HWND GetApplicationWindow();

extern LRESULT (WINAPI *g_pfnDefWindowProcW)(HWND, UINT, WPARAM, LPARAM);
extern BOOL (WINAPI *g_pfnPostMessageW)(HWND, UINT, WPARAM, LPARAM);
extern LONG (WINAPI *g_pfnImmGetCompositionStringW)(HIMC, DWORD, LPVOID, DWORD);
extern DWORD (WINAPI *g_pfnImmGetCandidateListW)(HIMC, DWORD, LPCANDIDATELIST, DWORD);
extern int (WINAPI *g_pfnGetLocaleInfoW)(LCID, LCTYPE, LPWSTR, int);

static const UINT kInputManContextMessage = WM_USER + 1;
static const DWORD kDefaultCandidatePageSize = 9;

static int __stdcall CopyCompositionString(DWORD flag, wchar_t *buffer,
                                           int byteCapacity);
static BOOL __stdcall ReleaseCurrentImeContext(HIMC context);

InputMan::InputMan()
{
    HWND appWindow = GetApplicationWindow();
    m_defaultImeWindow = ImmGetDefaultIMEWnd(appWindow);
    m_ownedImeContext = ImmCreateContext();
    ImmAssociateContext(appWindow, m_ownedImeContext);

    HIMC context = ImmGetContext(GetApplicationWindow());
    ImmSetOpenStatus(context, FALSE);
    ImmReleaseContext(GetApplicationWindow(), context);

    m_imePropertyFlags = ImmGetProperty(GetKeyboardLayout(0), IGP_PROPERTY);
    m_imeStateWord = 0;
    m_inputMode = 2;
    m_inputTargetList = new List(sizeof(int), 100);
}

InputMan::~InputMan()
{
    if (m_restoreImeContext != 0) {
        ImmAssociateContext(GetApplicationWindow(), m_restoreImeContext);
    }
    if (m_ownedImeContext != 0) {
        ImmDestroyContext(m_ownedImeContext);
    }
    if (m_inputTargetList != 0) {
        m_inputTargetList->Release(1);
    }
}

bool InputMan::HandleDefaultWindowMessage(HWND, UINT, WPARAM, LPARAM,
                                          LRESULT *)
{
    return false;
}

static int __stdcall GetKeyboardLayoutLanguageName(LPWSTR buffer,
                                                    int cchBuffer)
{
    HKL layout = GetKeyboardLayout(0);
    return g_pfnGetLocaleInfoW(LOWORD(layout), LOCALE_SLANGUAGE,
                               buffer, cchBuffer);
}

void InputMan::TrackInputTarget(int targetId, bool active)
{
    HWND appWindow = GetApplicationWindow();
    if (targetId == 0) {
        g_pfnPostMessageW(appWindow, kInputManContextMessage,
                          active ? 1 : 0, 0);
        m_inputTargetList->RemoveAll();
        return;
    }

    int oldCount = m_inputTargetList->GetCount();
    int foundIndex = -1;
    int *targets = static_cast<int *>(m_inputTargetList->GetData());
    for (int i = 0; i < oldCount; ++i) {
        if (targets[i] == targetId) {
            foundIndex = i;
            break;
        }
    }

    if (active) {
        if (foundIndex < 0) {
            m_inputTargetList->Append(1, &targetId);
        }
    } else if (foundIndex >= 0) {
        m_inputTargetList->RemoveAt(foundIndex, 1);
    }

    int newCount = m_inputTargetList->GetCount();
    if (oldCount == 0 && newCount != 0) {
        g_pfnPostMessageW(appWindow, kInputManContextMessage, 1, 0);
    } else if (oldCount != 0 && newCount == 0) {
        g_pfnPostMessageW(appWindow, kInputManContextMessage, 0, 0);
    }
}

unsigned char InputMan::GetImeStateByte() const
{
    return static_cast<unsigned char>(m_imeStateWord >> 8);
}

bool InputMan::HandleWindowMessage(HWND window, UINT message, WPARAM wParam,
                                   LPARAM lParam, LRESULT *result)
{
    switch (message) {
    case WM_INPUTLANGCHANGE: {
        if (m_ownedImeContext != 0) {
            ImmDestroyContext(m_ownedImeContext);
        }
        m_ownedImeContext = ImmCreateContext();
        HWND appWindow = GetApplicationWindow();
        if (ImmGetContext(appWindow) != 0) {
            ImmAssociateContext(appWindow, m_ownedImeContext);
        }
        return false;
    }

    case WM_CHAR:
        if ((lParam & 0x20000000) == 0) {
            g_pEventMan->DispatchCharEvent(static_cast<wchar_t>(wParam),
                                           GetMessageTime());
        }
        *result = 0;
        return true;

    case WM_IME_STARTCOMPOSITION:
        g_pEventMan->DispatchCompositionStartEvent(GetMessageTime());
        *result = 0;
        return true;

    case WM_IME_ENDCOMPOSITION:
        g_pEventMan->DispatchCompositionEndEvent(GetMessageTime());
        return false;

    case WM_IME_COMPOSITION: {
        wchar_t text[128];
        if ((lParam & GCS_RESULTSTR) != 0) {
            CopyCompositionString(GCS_RESULTSTR, text, sizeof(text));
            g_pEventMan->DispatchCompositionResultEvent(text,
                                                        GetMessageTime());
        }
        if ((lParam & GCS_COMPSTR) != 0) {
            CopyCompositionString(GCS_COMPSTR, text, 128);
            g_pEventMan->DispatchCompositionTextEvent(text,
                                                      GetMessageTime());
        }
        return true;
    }

    case WM_IME_SETCONTEXT:
        if ((m_imePropertyFlags & 0x20000) == 0) {
            *result = g_pfnDefWindowProcW(window, message, wParam, 0);
            return true;
        }
        return false;

    case WM_IME_NOTIFY:
        switch (wParam) {
        case IMN_OPENSTATUSWINDOW:
            *result = 0;
            return true;

        case IMN_CHANGECANDIDATE:
        case IMN_OPENCANDIDATE: {
            std::deque<std::wstring> *visibleCandidates =
                new std::deque<std::wstring>;

            DWORD listIndex = 0;
            DWORD listBit = 1;
            while ((static_cast<DWORD>(lParam) & listBit) == 0 &&
                   listIndex < 32) {
                ++listIndex;
                listBit = (listBit << 1) | (listBit >> 31);
            }

            HWND appWindow = GetApplicationWindow();
            HIMC context = ImmGetContext(appWindow);
            DWORD byteCount = g_pfnImmGetCandidateListW(context, listIndex,
                                                        0, 0);
            CANDIDATELIST *candidateList =
                static_cast<CANDIDATELIST *>(
                    GetMemoryMan()->AllocateBufferMemory(byteCount));
            g_pfnImmGetCandidateListW(context, listIndex, candidateList,
                                      byteCount);
            ReleaseCurrentImeContext(context);

            DWORD pageStart;
            if ((candidateList->dwStyle & 2) != 0 &&
                candidateList->dwCount == 1) {
                const char *packed = reinterpret_cast<const char *>(
                    &candidateList->dwOffset[0]);
                char multibyte[3];
                if (static_cast<signed char>(packed[0]) < 0) {
                    multibyte[0] = packed[1];
                    multibyte[1] = packed[0];
                    multibyte[2] = 0;
                } else {
                    multibyte[0] = packed[0];
                    multibyte[1] = 0;
                }

                wchar_t wideText[256];
                int length = MultiByteToWideChar(
                    CP_ACP, 0, multibyte,
                    static_cast<int>(std::strlen(multibyte)),
                    wideText, 256);
                wideText[length] = 0;
                visibleCandidates->push_back(std::wstring(wideText));
            } else {
                DWORD pageSize = candidateList->dwPageSize;
                if (pageSize == 0) {
                    pageSize = kDefaultCandidatePageSize;
                }
                pageStart = candidateList->dwPageStart;
                if (pageStart == 0) {
                    pageStart = pageSize *
                        (candidateList->dwSelection / pageSize);
                }

                DWORD pageEnd = pageStart + pageSize - 1;
                if (pageEnd > candidateList->dwCount - 1) {
                    pageEnd = candidateList->dwCount - 1;
                }
                for (DWORD i = pageStart; i <= pageEnd; ++i) {
                    const wchar_t *candidate =
                        reinterpret_cast<const wchar_t *>(
                            reinterpret_cast<const unsigned char *>(
                                candidateList) + candidateList->dwOffset[i]);
                    visibleCandidates->push_back(std::wstring(candidate));
                }
            }

            g_pEventMan->DispatchCandidateListEvent(
                static_cast<int>(candidateList->dwSelection - pageStart),
                visibleCandidates, GetMessageTime());
            GetMemoryMan()->FreeBufferMemory(candidateList);
            *result = 0;
            return true;
        }

        case IMN_CLOSECANDIDATE:
            g_pEventMan->DispatchCandidateCloseEvent(GetMessageTime());
            return false;

        case IMN_SETOPENSTATUS: {
            HIMC context = ImmGetContext(GetApplicationWindow());
            BOOL isOpen = ImmGetOpenStatus(context);
            ReleaseCurrentImeContext(context);
            g_pEventMan->DispatchImeOpenStatusEvent(isOpen,
                                                    GetMessageTime());
            *result = 0;
            return true;
        }
        }
        return false;

    case WM_IME_CHAR:
        *result = 0;
        return true;

    case WM_IME_KEYDOWN:
        *result = 0;
        return false;

    case kInputManContextMessage:
        ImmAssociateContext(GetApplicationWindow(),
                            LOBYTE(wParam) == 1 ? m_ownedImeContext : 0);
        *result = 0;
        return true;
    }
    return false;
}

int InputMan::GetInputMode() const
{
    return m_inputMode;
}

BOOL InputMan::SetInputMode(int mode)
{
    m_inputMode = mode;
    if (mode == 2) {
        HWND appWindow = GetApplicationWindow();
        HIMC context = ImmGetContext(appWindow);
        ImmNotifyIME(context, NI_COMPOSITIONSTR, CPS_COMPLETE, 0);
        return ImmReleaseContext(appWindow, context);
    }
    return mode;
}

BOOL __stdcall CompleteImeComposition()
{
    HWND appWindow = GetApplicationWindow();
    HIMC context = ImmGetContext(appWindow);
    ImmNotifyIME(context, NI_COMPOSITIONSTR, CPS_COMPLETE, 0);
    return ImmReleaseContext(appWindow, context);
}

int __stdcall GetCompositionCursorPosition()
{
    HWND appWindow = GetApplicationWindow();
    HIMC context = ImmGetContext(appWindow);
    int position = g_pfnImmGetCompositionStringW(context, GCS_CURSORPOS,
                                                 0, 0) & 0xffff;
    ImmReleaseContext(appWindow, context);
    return position;
}

static int __stdcall CopyCompositionString(DWORD flag, wchar_t *buffer,
                                           int byteCapacity)
{
    HWND appWindow = GetApplicationWindow();
    HIMC context = ImmGetContext(appWindow);
    int byteCount = g_pfnImmGetCompositionStringW(
        context, flag, buffer, byteCapacity - sizeof(wchar_t));
    ImmReleaseContext(appWindow, context);
    *reinterpret_cast<wchar_t *>(
        reinterpret_cast<unsigned char *>(buffer) + byteCount) = 0;
    return byteCount;
}

static HIMC __stdcall GetCurrentImeContext()
{
    return ImmGetContext(GetApplicationWindow());
}

static BOOL __stdcall ReleaseCurrentImeContext(HIMC context)
{
    return ImmReleaseContext(GetApplicationWindow(), context);
}

static HWND __stdcall GetDefaultImeWindow(HWND window)
{
    return ImmGetDefaultIMEWnd(window);
}

static HIMC __stdcall CreateImeContext()
{
    return ImmCreateContext();
}

static HIMC __stdcall AssociateImeContext(HWND window, HIMC context)
{
    return ImmAssociateContext(window, context);
}

static BOOL __stdcall SetImeOpenStatus(HIMC context, BOOL isOpen)
{
    return ImmSetOpenStatus(context, isOpen);
}

static DWORD __stdcall GetImeProperty(HKL layout, DWORD index)
{
    return ImmGetProperty(layout, index);
}

static BOOL __stdcall DestroyImeContext(HIMC context)
{
    return ImmDestroyContext(context);
}

static BOOL __stdcall GetImeConversionStatus(HIMC context,
                                              LPDWORD conversion,
                                              LPDWORD sentence)
{
    return ImmGetConversionStatus(context, conversion, sentence);
}

static BOOL __stdcall GetImeOpenStatus(HIMC context)
{
    return ImmGetOpenStatus(context);
}

static DWORD __stdcall GetImeCandidateList(HIMC context, DWORD index,
                                            LPCANDIDATELIST list,
                                            DWORD byteCount)
{
    return g_pfnImmGetCandidateListW(context, index, list, byteCount);
}

static LONG __stdcall GetImeCompositionString(HIMC context, DWORD index,
                                               LPVOID buffer,
                                               DWORD byteCount)
{
    return g_pfnImmGetCompositionStringW(context, index, buffer,
                                         byteCount);
}
