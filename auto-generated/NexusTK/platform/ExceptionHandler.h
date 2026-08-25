// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J8
// Source by-file doc: by-file/ExceptionHandler.md
// UID:00004P | by-class/ExceptionHandler.md | Completion:93 | Confidence:95
typedef BOOL (WINAPI *SYMINITIALIZEPROC)(HANDLE, PCSTR, BOOL);
typedef BOOL (WINAPI *SYMCLEANUPPROC)(HANDLE);
typedef BOOL (WINAPI *STACKWALKPROC)(
    DWORD,
    HANDLE,
    HANDLE,
    LPSTACKFRAME,
    PVOID,
    PREAD_PROCESS_MEMORY_ROUTINE,
    PFUNCTION_TABLE_ACCESS_ROUTINE,
    PGET_MODULE_BASE_ROUTINE,
    PTRANSLATE_ADDRESS_ROUTINE);
typedef PVOID (WINAPI *SYMFUNCTIONTABLEACCESSPROC)(HANDLE, DWORD);
typedef DWORD (WINAPI *SYMGETMODULEBASEPROC)(HANDLE, DWORD);
typedef BOOL (WINAPI *SYMGETSYMFROMADDRPROC)(
    HANDLE,
    DWORD,
    PDWORD,
    PIMAGEHLP_SYMBOL);

class ExceptionHandler
{
public:
    ExceptionHandler();
    virtual ~ExceptionHandler();

    void SetReportText(const wchar_t *text);
    void SendStoredCrashReportFile();
    void SendCrashDiagnosticText(const char *text);
    void GenerateExceptionReport(EXCEPTION_POINTERS *pExceptionInfo);
    BOOL InitImagehlpFunctions();
    void IntelStackWalk(CONTEXT *pContext, FILE *pReportFile);
    void ImagehlpStackWalk(CONTEXT *pContext, FILE *pReportFile);

    void SetSkipCrashReport(bool skipCrashReport)
    {
        m_skipCrashReport = skipCrashReport;
    }

    bool ShouldSkipCrashReport() const
    {
        return m_skipCrashReport;
    }

    LPTOP_LEVEL_EXCEPTION_FILTER PreviousFilter() const
    {
        return m_previousFilter;
    }

private:
    static LPTSTR GetExceptionString(DWORD dwCode);
    static bool GetLogicalAddress(
        PVOID address,
        PTSTR moduleName,
        DWORD moduleNameLength,
        DWORD &sectionNumber,
        DWORD &sectionOffset);

    bool m_skipCrashReport;
    LPTOP_LEVEL_EXCEPTION_FILTER m_previousFilter;
    DWORD m_reserved0C;
    SYMINITIALIZEPROC m_symInitialize;
    SYMCLEANUPPROC m_symCleanup;
    STACKWALKPROC m_stackWalk;
    SYMFUNCTIONTABLEACCESSPROC m_symFunctionTableAccess;
    SYMGETMODULEBASEPROC m_symGetModuleBase;
    SYMGETSYMFROMADDRPROC m_symGetSymFromAddr;
    wchar_t m_reportText[0x400];
};

typedef char ExceptionHandlerSizeMustBe0x828[
    sizeof(ExceptionHandler) == 0x828 ? 1 : -1];

[[No Children Attached]]

// UID:0000QN | by-global/g_pCrashTarget.md | Completion:92 | Confidence:94
extern ExceptionHandler *g_pCrashTarget;
