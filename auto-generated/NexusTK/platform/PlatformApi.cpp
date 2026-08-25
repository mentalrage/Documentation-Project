// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000ML
// Source by-file doc: by-file/PlatformApi.md
// UID:0000FE | by-class/UniAPIInit.md | Completion:93 | Confidence:95
class UniAPIInit
{
public:
    UniAPIInit();
    virtual ~UniAPIInit();

// UID:0004N6 | by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md | Completion:92 | Confidence:93
UniAPIInit::UniAPIInit()
{
    OSVERSIONINFOA versionInfo;

    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    GetVersionExA(&versionInfo);

    g_pfnReadUtf16CodeUnitFromFile = ReadUtf16CodeUnitFromFile;

    if (versionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT) {
        g_pfnFindWindowW = FindWindowW;
        g_pfnOpenFileMappingW = OpenFileMappingW;
        g_pfnCreateMutexW = CreateMutexW;
        g_pfnCreateDialogParamW = CreateDialogParamW;
        g_pfnLoadLibraryW = LoadLibraryW;
        g_pfnCreateFileW = CreateFileW;
        g_pfnCreateProcessW = CreateProcessW;
        g_pfnCreateEventW = CreateEventW;
        g_pfnRegisterClassW = RegisterClassW;
        g_pfnCreateWindowExW = CreateWindowExW;
        g_pfnCreateFileMappingW = CreateFileMappingW;
        g_pfnCreateSemaphoreW = CreateSemaphoreW;
        g_pfnDefWindowProcW = DefWindowProcW;
        g_pfnRegisterClipboardFormatW = RegisterClipboardFormatW;
        g_pfnCharUpperBuffW = CharUpperBuffW;
        g_pfnCreateDirectoryW = CreateDirectoryW;
        g_pfnDeleteFileW = DeleteFileW;
        g_pfnDispatchMessageW = DispatchMessageW;
        g_pfnFindFirstFileW = FindFirstFileW;
        g_pfnFormatMessageW = FormatMessageW;
        g_pfnGetCurrentDirectoryW = GetCurrentDirectoryW;
        g_pfnGetModuleFileNameW = GetModuleFileNameW;
        g_pfnGetModuleHandleW = GetModuleHandleW;
        g_pfnGetWindowsDirectoryW = GetWindowsDirectoryW;
        g_pfnGlobalGetAtomNameW = GlobalGetAtomNameW;
        g_pfnLoadCursorW = LoadCursorW;
        g_pfnLoadIconW = LoadIconW;
        g_pfnPeekMessage = PeekMessageW;
        g_pfnPostMessageW = PostMessageW;
        g_pfnRegCreateKeyExW = RegCreateKeyExW;
        g_pfnRegDeleteKeyW = RegDeleteKeyW;
        g_pfnRegEnumValueW = RegEnumValueW;
        g_pfnRegQueryInfoKeyW = RegQueryInfoKeyW;
        g_pfnRegQueryValueExW = RegQueryValueExW;
        g_pfnRegSetValueExW = RegSetValueExW;
        g_pfnSetCurrentDirectoryW = SetCurrentDirectoryW;
        g_pfnWideOpenFile = _wfopen;
        g_pfnWideStat = _wstat64i32;
        g_pfnGetFileVersionInfoSizeW = GetFileVersionInfoSizeW;
        g_pfnGetFileVersionInfoW = GetFileVersionInfoW;
        g_pfnVerQueryValueW = VerQueryValueW;
        g_pfnImmGetCompositionStringW = ImmGetCompositionStringW;
        g_pfnImmGetCandidateListW = ImmGetCandidateListW;
        g_pfnSendMessageW = SendMessageW;
        g_pfnGetLocaleInfoW = GetLocaleInfoW;
        g_pfnSetFileAttributesW = SetFileAttributesW;
    }
}

// UID:0004N7 | by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md | Completion:93 | Confidence:96
UniAPIInit::~UniAPIInit()
{
}
};


// UID:0002AS | by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md | Completion:90 | Confidence:90
FILE *(__cdecl *g_pfnWideOpenFile)(const wchar_t *path, const wchar_t *mode);
int (__cdecl *g_pfnWideStat)(const wchar_t *path, struct _stat64i32 *buffer);
wchar_t (__cdecl *g_pfnReadUtf16CodeUnitFromFile)(FILE *stream);
HWND (WINAPI *g_pfnFindWindowW)(LPCWSTR className, LPCWSTR windowName);
HANDLE (WINAPI *g_pfnOpenFileMappingW)(DWORD desiredAccess, BOOL inheritHandle, LPCWSTR name);
HANDLE (WINAPI *g_pfnCreateMutexW)(LPSECURITY_ATTRIBUTES attributes, BOOL initialOwner, LPCWSTR name);
HWND (WINAPI *g_pfnCreateDialogParamW)(HINSTANCE instance, LPCWSTR templateName, HWND parent, DLGPROC dialogProc, LPARAM initParam);
HMODULE (WINAPI *g_pfnLoadLibraryW)(LPCWSTR fileName);
HANDLE (WINAPI *g_pfnCreateFileW)(LPCWSTR fileName, DWORD desiredAccess, DWORD shareMode, LPSECURITY_ATTRIBUTES securityAttributes, DWORD creationDisposition, DWORD flagsAndAttributes, HANDLE templateFile);
BOOL (WINAPI *g_pfnCreateProcessW)(LPCWSTR applicationName, LPWSTR commandLine, LPSECURITY_ATTRIBUTES processAttributes, LPSECURITY_ATTRIBUTES threadAttributes, BOOL inheritHandles, DWORD creationFlags, LPVOID environment, LPCWSTR currentDirectory, LPSTARTUPINFOW startupInfo, LPPROCESS_INFORMATION processInformation);
HANDLE (WINAPI *g_pfnCreateEventW)(LPSECURITY_ATTRIBUTES attributes, BOOL manualReset, BOOL initialState, LPCWSTR name);
ATOM (WINAPI *g_pfnRegisterClassW)(const WNDCLASSW *windowClass);
HWND (WINAPI *g_pfnCreateWindowExW)(DWORD exStyle, LPCWSTR className, LPCWSTR windowName, DWORD style, int x, int y, int width, int height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID param);
HANDLE (WINAPI *g_pfnCreateFileMappingW)(HANDLE file, LPSECURITY_ATTRIBUTES attributes, DWORD protect, DWORD maximumSizeHigh, DWORD maximumSizeLow, LPCWSTR name);
HANDLE (WINAPI *g_pfnCreateSemaphoreW)(LPSECURITY_ATTRIBUTES attributes, LONG initialCount, LONG maximumCount, LPCWSTR name);
LRESULT (WINAPI *g_pfnDefWindowProcW)(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
UINT (WINAPI *g_pfnRegisterClipboardFormatW)(LPCWSTR format);
DWORD (WINAPI *g_pfnCharUpperBuffW)(LPWSTR text, DWORD length);
BOOL (WINAPI *g_pfnCreateDirectoryW)(LPCWSTR pathName, LPSECURITY_ATTRIBUTES securityAttributes);
BOOL (WINAPI *g_pfnDeleteFileW)(LPCWSTR fileName);
LRESULT (WINAPI *g_pfnDispatchMessageW)(const MSG *message);
HANDLE (WINAPI *g_pfnFindFirstFileW)(LPCWSTR fileName, LPWIN32_FIND_DATAW findFileData);
DWORD (WINAPI *g_pfnFormatMessageW)(DWORD flags, LPCVOID source, DWORD messageId, DWORD languageId, LPWSTR buffer, DWORD size, va_list *arguments);
DWORD (WINAPI *g_pfnGetCurrentDirectoryW)(DWORD bufferLength, LPWSTR buffer);
DWORD (WINAPI *g_pfnGetModuleFileNameW)(HMODULE module, LPWSTR fileName, DWORD size);
HMODULE (WINAPI *g_pfnGetModuleHandleW)(LPCWSTR moduleName);
UINT (WINAPI *g_pfnGetWindowsDirectoryW)(LPWSTR buffer, UINT size);
UINT (WINAPI *g_pfnGlobalGetAtomNameW)(ATOM atom, LPWSTR buffer, int size);
HCURSOR (WINAPI *g_pfnLoadCursorW)(HINSTANCE instance, LPCWSTR cursorName);
HICON (WINAPI *g_pfnLoadIconW)(HINSTANCE instance, LPCWSTR iconName);
BOOL (WINAPI *g_pfnPeekMessage)(LPMSG message, HWND hwnd, UINT filterMin, UINT filterMax, UINT removeMsg);
BOOL (WINAPI *g_pfnPostMessageW)(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
LONG (WINAPI *g_pfnRegCreateKeyExW)(HKEY key, LPCWSTR subKey, DWORD reserved, LPWSTR className, DWORD options, REGSAM samDesired, LPSECURITY_ATTRIBUTES securityAttributes, PHKEY resultKey, LPDWORD disposition);
LONG (WINAPI *g_pfnRegDeleteKeyW)(HKEY key, LPCWSTR subKey);
LONG (WINAPI *g_pfnRegEnumValueW)(HKEY key, DWORD index, LPWSTR valueName, LPDWORD valueNameLength, LPDWORD reserved, LPDWORD type, LPBYTE data, LPDWORD dataLength);
LONG (WINAPI *g_pfnRegQueryInfoKeyW)(HKEY key, LPWSTR className, LPDWORD classLength, LPDWORD reserved, LPDWORD subKeyCount, LPDWORD maxSubKeyLength, LPDWORD maxClassLength, LPDWORD valueCount, LPDWORD maxValueNameLength, LPDWORD maxValueLength, LPDWORD securityDescriptorLength, PFILETIME lastWriteTime);
LONG (WINAPI *g_pfnRegQueryValueExW)(HKEY key, LPCWSTR valueName, LPDWORD reserved, LPDWORD type, LPBYTE data, LPDWORD dataLength);
LONG (WINAPI *g_pfnRegSetValueExW)(HKEY key, LPCWSTR valueName, DWORD reserved, DWORD type, const BYTE *data, DWORD dataLength);
BOOL (WINAPI *g_pfnSetCurrentDirectoryW)(LPCWSTR pathName);
DWORD (WINAPI *g_pfnGetFileVersionInfoSizeW)(LPCWSTR fileName, LPDWORD handle);
BOOL (WINAPI *g_pfnGetFileVersionInfoW)(LPCWSTR fileName, DWORD handle, DWORD length, LPVOID data);
BOOL (WINAPI *g_pfnVerQueryValueW)(LPCVOID block, LPCWSTR subBlock, LPVOID *buffer, PUINT length);
LONG (WINAPI *g_pfnImmGetCompositionStringW)(HIMC context, DWORD index, LPVOID buffer, DWORD bufferSize);
DWORD (WINAPI *g_pfnImmGetCandidateListW)(HIMC context, DWORD index, LPCANDIDATELIST candidateList, DWORD bufferSize);

// UID:0002A6 | by-memory/0x0069bec8-0x0069bed0.WideApiDispatchTailPointers.md | Completion:91 | Confidence:93
int (WINAPI *g_pfnGetLocaleInfoW)(LCID locale, LCTYPE localeType, LPWSTR data, int dataCount);
BOOL (WINAPI *g_pfnSetFileAttributesW)(LPCWSTR fileName, DWORD fileAttributes);

// UID:00022V | by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md | Completion:88 | Confidence:89
static void MapiSendMailHelper(const wchar_t *recipient,
                               const wchar_t *subject,
                               const wchar_t *noteText,
                               const wchar_t *attachmentPath)
{
    HMODULE mapiLibrary = LoadLibraryA("MAPI32.DLL");
    if (mapiLibrary == NULL)
        return;

    LPMAPISENDMAIL sendMail =
        (LPMAPISENDMAIL)GetProcAddress(mapiLibrary, "MAPISendMail");
    if (sendMail == NULL)
        return;

    char *recipientAddress = AllocAnsiFromWideDefaultCodepage(recipient);
    char *recipientName = AllocAnsiFromWideDefaultCodepage(recipient);
    char *ansiSubject = AllocAnsiFromWideDefaultCodepage(subject);
    char *ansiNoteText = AllocAnsiFromWideDefaultCodepage(noteText);
    char *ansiAttachmentPath = NULL;

    if (attachmentPath != NULL)
        ansiAttachmentPath = AllocAnsiFromWideDefaultCodepage(attachmentPath);

    MapiRecipDesc recipientDesc = {0};
    recipientDesc.ulRecipClass = MAPI_TO;
    recipientDesc.lpszName = recipientName;
    recipientDesc.lpszAddress = recipientAddress;

    MapiFileDesc fileDesc = {0};
    if (attachmentPath != NULL) {
        fileDesc.nPosition = (ULONG)-1;
        fileDesc.lpszPathName = ansiAttachmentPath;
    }

    MapiMessage message = {0};
    message.lpszSubject = ansiSubject;
    message.lpszNoteText = ansiNoteText;
    message.flFlags = MAPI_RECEIPT_REQUESTED;
    message.nRecipCount = 1;
    message.lpRecips = &recipientDesc;
    if (attachmentPath != NULL) {
        message.nFileCount = 1;
        message.lpFiles = &fileDesc;
    }

    sendMail(0, 0, &message, 0, 0);

    if (ansiAttachmentPath != NULL)
        FreeAllocatedAnsiString(ansiAttachmentPath);
    FreeAllocatedAnsiString(ansiNoteText);
    FreeAllocatedAnsiString(ansiSubject);
    FreeAllocatedAnsiString(recipientName);
    FreeAllocatedAnsiString(recipientAddress);
    FreeLibrary(mapiLibrary);
}

// UID:000249 | by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md | Completion:88 | Confidence:91
static char *AllocAnsiFromWideDefaultCodepage(const wchar_t *text)
{
    if (text == NULL)
        return NULL;

    int wideLength = (int)wcslen(text);
    int byteLength = WideCharToMultiByte(CP_ACP, 0, text, wideLength, NULL, 0, NULL, NULL);
    char *result = (char *)operator new(byteLength + 1);

    WideCharToMultiByte(CP_ACP, 0, text, wideLength, result, byteLength, NULL, NULL);
    result[byteLength] = '\0';
    return result;
}

static void FreeAllocatedAnsiString(char *text)
{
    if (text != NULL)
        free(text);
}

static wchar_t *AllocWideFromAnsiDefaultCodepage(const char *text)
{
    if (text == NULL)
        return NULL;

    int byteLength = (int)strlen(text);
    int wideLength = MultiByteToWideChar(CP_ACP, 0, text, byteLength, NULL, 0);
    wchar_t *result = (wchar_t *)operator new((wideLength + 1) * sizeof(wchar_t));

    MultiByteToWideChar(CP_ACP, 0, text, byteLength, result, wideLength);
    result[wideLength] = L'\0';
    return result;
}

static void FreeAllocatedWideString(wchar_t *text)
{
    if (text != NULL)
        free(text);
}

static wchar_t ReadUtf16CodeUnitFromFile(FILE *stream)
{
    wchar_t ch;

    if (feof(stream))
        return (wchar_t)0xffff;

    fread(&ch, sizeof(wchar_t), 1, stream);
    return ch;
}

// UID:0003OT | by-memory/0x0061d0f0-0x0061d118.MapiLookupStrings.md | Completion:86 | Confidence:91
// MAPI lookup string literals are emitted inline by MapiSendMailHelper.

// UID:00028B | by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md | Completion:91 | Confidence:94
static UniAPIInit s_uniAPIInit;

// UID:0001Q1 | by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md | Completion:91 | Confidence:93
LRESULT (WINAPI *g_pfnSendMessageW)(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

// UID:0000TQ | by-global\WideApiDispatchTable.md | Completion:92 | Confidence:91 | Empty Emitter Marker
