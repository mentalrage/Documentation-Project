// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J8
// Source by-file doc: by-file/ExceptionHandler.md
// UID:00014F | by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md | Completion:90 | Confidence:94
static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo)
{
    KeySpeedMgr *keySpeedMgr = g_pKeySpeedMgr;
    ExceptionHandler *target = g_pCrashTarget;

    if (keySpeedMgr != 0) {
        keySpeedMgr->RestoreSystemKeyboardSettings();
    }

    if (target == 0 || target->ShouldSkipCrashReport()) {
        return EXCEPTION_CONTINUE_SEARCH;
    }

    target->GenerateExceptionReport(exceptionInfo);

    LPTOP_LEVEL_EXCEPTION_FILTER previousFilter = target->PreviousFilter();
    if (previousFilter != 0) {
        return previousFilter(exceptionInfo);
    }

    return EXCEPTION_CONTINUE_SEARCH;
}

// UID:00014G | by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md | Completion:94 | Confidence:96
void ExceptionHandler::GenerateExceptionReport(EXCEPTION_POINTERS *pExceptionInfo)
{
    wchar_t windowsDirectory[MAX_PATH];
    wchar_t reportPath[MAX_PATH];
    g_pfnGetWindowsDirectoryW(windowsDirectory, MAX_PATH);
    swprintf_s(reportPath, MAX_PATH, L"%s\\%s",
               windowsDirectory, L"BCrash.nfo");

    FILE *pReportFile = g_pfnWideOpenFile(reportPath, L"wt");
    if (pReportFile != NULL) {
        fprintf(pReportFile, "%d.%d.Eng.R\n",
                g_pApplication->GetVersionMajor(),
                GetExecutableVersionLowWord());
    }

    EXCEPTION_RECORD *pExceptionRecord = pExceptionInfo->ExceptionRecord;
    wchar_t faultingModule[MAX_PATH];
    DWORD sectionNumber;
    DWORD sectionOffset;
    GetLogicalAddress(pExceptionRecord->ExceptionAddress,
                      faultingModule,
                      MAX_PATH,
                      sectionNumber,
                      sectionOffset);

    CONTEXT *pContext = pExceptionInfo->ContextRecord;
    (void)GetExceptionString(pExceptionRecord->ExceptionCode);

    if (pReportFile != NULL) {
        char ansiText[1024];
        LPTSTR exceptionText =
            GetExceptionString(pExceptionRecord->ExceptionCode);
        WideCharToMultiByte(CP_ACP,
                            0,
                            exceptionText,
                            static_cast<int>(wcslen(exceptionText) + 1),
                            ansiText,
                            sizeof(ansiText),
                            NULL,
                            NULL);
        fprintf(pReportFile,
                "Exception code: %08X %s\n",
                pExceptionRecord->ExceptionCode,
                ansiText);

        WideCharToMultiByte(CP_ACP,
                            0,
                            faultingModule,
                            static_cast<int>(wcslen(faultingModule) + 1),
                            ansiText,
                            sizeof(ansiText),
                            NULL,
                            NULL);
        fprintf(pReportFile,
                "Fault address:  %08X %02X:%08X %s\n",
                pExceptionRecord->ExceptionAddress,
                sectionNumber,
                sectionOffset,
                ansiText);

        fprintf(pReportFile, "\nRegisters:\n");
        fprintf(pReportFile,
                "EAX:%08X\nEBX:%08X\nECX:%08X\nEDX:%08X\n"
                "ESI:%08X\nEDI:%08X\n",
                pContext->Eax,
                pContext->Ebx,
                pContext->Ecx,
                pContext->Edx,
                pContext->Esi,
                pContext->Edi);
        fprintf(pReportFile,
                "CS:EIP:%04X:%08X\n",
                pContext->SegCs,
                pContext->Eip);
        fprintf(pReportFile,
                "SS:ESP:%04X:%08X  EBP:%08X\n",
                pContext->SegSs,
                pContext->Esp,
                pContext->Ebp);
        fprintf(pReportFile,
                "DS:%04X  ES:%04X  FS:%04X  GS:%04X\n",
                pContext->SegDs,
                pContext->SegEs,
                pContext->SegFs,
                pContext->SegGs);
        fprintf(pReportFile,
                "Flags:%08X Time:%d Phase:%d 565:%d\n\n",
                pContext->EFlags,
                g_timerCurrentTickMirror - g_timerTickBaselineMirror,
                g_applicationPhaseState,
                g_surfaceUsesRgb565Pixels);
    }

    if (InitImagehlpFunctions()) {
        ImagehlpStackWalk(pContext, pReportFile);
        m_symCleanup(GetCurrentProcess());
    } else {
        IntelStackWalk(pContext, pReportFile);
    }

    fputs("-----------------------------------------------", pReportFile);
    if (pReportFile != NULL) {
        fflush(pReportFile);
        fclose(pReportFile);
    }
}

// UID:0004TS | by-memory/0x004ab510-0x004ab73b.ExceptionHandlerSendStoredCrashReportFile.md | Completion:92 | Confidence:93
void ExceptionHandler::SendStoredCrashReportFile()
{
    OSVERSIONINFOW versionInfo;
    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    GetVersionExW(&versionInfo);

    char versionText[64];
    if (versionInfo.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
    {
        const char *platformName = "Win95";
        if (versionInfo.dwMinorVersion == 10)
            platformName = "Win98";
        else if (versionInfo.dwMinorVersion == 90)
            platformName = "WinME";
        sprintf_s(versionText, sizeof(versionText),
                  "%s:%02d%02d : ", platformName,
                  versionInfo.dwMajorVersion, versionInfo.dwMinorVersion);
    }
    else if (versionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT)
    {
        const char *platformName =
            versionInfo.dwMajorVersion == 5 ? "WinXP" : "Win2K";
        sprintf_s(versionText, sizeof(versionText),
                  "%s:%02d%02d : ", platformName,
                  versionInfo.dwMajorVersion, versionInfo.dwMinorVersion);
    }
    else
    {
        sprintf_s(versionText, sizeof(versionText),
                  "Unknown:%02d%02d : ",
                  versionInfo.dwMajorVersion, versionInfo.dwMinorVersion);
    }

    wchar_t windowsDirectory[MAX_PATH];
    wchar_t reportPath[MAX_PATH];
    g_pfnGetWindowsDirectoryW(windowsDirectory, MAX_PATH);
    swprintf_s(reportPath, MAX_PATH, L"%s\\%s",
               windowsDirectory, L"BCrash.nfo");

    FILE *reportFile = g_pfnWideOpenFile(reportPath, L"rt");
    if (reportFile != NULL)
    {
        char reportText[4096];
        size_t reportLength = fread(
            reportText, 1, sizeof(reportText), reportFile);

        unsigned char packet[4192];
        size_t versionLength = strlen(versionText);
        unsigned short payloadLength = static_cast<unsigned short>(
            versionLength + reportLength);
        packet[0] = 0x42;
        packet[1] = 1;
        packet[2] = static_cast<unsigned char>(payloadLength >> 8);
        packet[3] = static_cast<unsigned char>(payloadLength);
        memcpy(packet + 4, versionText, versionLength);
        memcpy(packet + 4 + versionLength, reportText, reportLength);
        packet[payloadLength + 4] = 0;
        g_packetSender->QueueAndSendPacket(
            packet, static_cast<short>(payloadLength + 5));
        fclose(reportFile);
    }

    g_pfnDeleteFileW(reportPath);
}

// UID:00014E | by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md | Completion:88 | Confidence:92
void ExceptionHandler::SendCrashDiagnosticText(const char *text)
{
    GetMemoryMan();

    const unsigned int length = static_cast<unsigned int>(strlen(text));
    if (length == 0 || length > 0x0fff) {
        return;
    }

    unsigned char packet[0x1020];

    PacketBufferWriteUInt8(0x42, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(length), packet + 2);
    MemmoveWrapper(packet + 4, text, length);
    PacketBufferWriteUInt8(0, packet + length + 4);

    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(length + 5));
}

// UID:00014H | by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md | Completion:92 | Confidence:94
LPTSTR ExceptionHandler::GetExceptionString(DWORD dwCode)
{
#define EXCEPTION(name) \
    case EXCEPTION_##name: \
        return _T(#name);

    switch (dwCode) {
        EXCEPTION(ACCESS_VIOLATION)
        EXCEPTION(DATATYPE_MISALIGNMENT)
        EXCEPTION(BREAKPOINT)
        EXCEPTION(SINGLE_STEP)
        EXCEPTION(ARRAY_BOUNDS_EXCEEDED)
        EXCEPTION(FLT_DENORMAL_OPERAND)
        EXCEPTION(FLT_DIVIDE_BY_ZERO)
        EXCEPTION(FLT_INEXACT_RESULT)
        EXCEPTION(FLT_INVALID_OPERATION)
        EXCEPTION(FLT_OVERFLOW)
        EXCEPTION(FLT_STACK_CHECK)
        EXCEPTION(FLT_UNDERFLOW)
        EXCEPTION(INT_DIVIDE_BY_ZERO)
        EXCEPTION(INT_OVERFLOW)
        EXCEPTION(PRIV_INSTRUCTION)
        EXCEPTION(IN_PAGE_ERROR)
        EXCEPTION(ILLEGAL_INSTRUCTION)
        EXCEPTION(NONCONTINUABLE_EXCEPTION)
        EXCEPTION(STACK_OVERFLOW)
        EXCEPTION(INVALID_DISPOSITION)
        EXCEPTION(GUARD_PAGE)
        EXCEPTION(INVALID_HANDLE)
    }

#undef EXCEPTION

    static TCHAR szBuffer[512] = { 0 };

    FormatMessage(FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_FROM_HMODULE,
                  GetModuleHandle(_T("NTDLL.DLL")),
                  dwCode,
                  0,
                  szBuffer,
                  sizeof(szBuffer),
                  0);

    return szBuffer;
}

// UID:00014I | by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md | Completion:92 | Confidence:94
bool ExceptionHandler::GetLogicalAddress(PVOID address,
                                         PTSTR moduleName,
                                         DWORD moduleNameLength,
                                         DWORD &sectionNumber,
                                         DWORD &sectionOffset)
{
    MEMORY_BASIC_INFORMATION memoryInformation;
    if (VirtualQuery(address, &memoryInformation, sizeof(memoryInformation)) == 0) {
        return false;
    }

    const DWORD moduleBase = (DWORD)memoryInformation.AllocationBase;
    if (GetModuleFileName((HMODULE)moduleBase,
                          moduleName,
                          moduleNameLength) == 0) {
        return false;
    }

    PIMAGE_DOS_HEADER dosHeader = (PIMAGE_DOS_HEADER)moduleBase;
    PIMAGE_NT_HEADERS ntHeaders =
        (PIMAGE_NT_HEADERS)(moduleBase + dosHeader->e_lfanew);
    PIMAGE_SECTION_HEADER sectionHeader = IMAGE_FIRST_SECTION(ntHeaders);
    const DWORD relativeAddress = (DWORD)address - moduleBase;

    for (unsigned int index = 0;
         index < ntHeaders->FileHeader.NumberOfSections;
         ++index, ++sectionHeader) {
        const DWORD sectionStart = sectionHeader->VirtualAddress;
        const DWORD sectionEnd =
            sectionStart + std::max(sectionHeader->SizeOfRawData,
                                    sectionHeader->Misc.VirtualSize);

        if (relativeAddress >= sectionStart && relativeAddress <= sectionEnd) {
            sectionNumber = index + 1;
            sectionOffset = relativeAddress - sectionStart;
            return true;
        }
    }

    return false;
}

// UID:0004WT | by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md | Completion:94 | Confidence:94
BOOL ExceptionHandler::InitImagehlpFunctions()
{
    HMODULE imageHlp = g_pfnLoadLibraryW(L"IMAGEHLP.DLL");
    if (imageHlp == NULL) {
        return FALSE;
    }

    m_symInitialize =
        (SYMINITIALIZEPROC)GetProcAddress(imageHlp, "SymInitialize");
    if (m_symInitialize == NULL) {
        return FALSE;
    }

    m_symCleanup =
        (SYMCLEANUPPROC)GetProcAddress(imageHlp, "SymCleanup");
    if (m_symCleanup == NULL) {
        return FALSE;
    }

    m_stackWalk =
        (STACKWALKPROC)GetProcAddress(imageHlp, "StackWalk");
    if (m_stackWalk == NULL) {
        return FALSE;
    }

    m_symFunctionTableAccess =
        (SYMFUNCTIONTABLEACCESSPROC)GetProcAddress(
            imageHlp,
            "SymFunctionTableAccess");
    if (m_symFunctionTableAccess == NULL) {
        return FALSE;
    }

    m_symGetModuleBase =
        (SYMGETMODULEBASEPROC)GetProcAddress(imageHlp, "SymGetModuleBase");
    if (m_symGetModuleBase == NULL) {
        return FALSE;
    }

    m_symGetSymFromAddr =
        (SYMGETSYMFROMADDRPROC)GetProcAddress(imageHlp, "SymGetSymFromAddr");
    if (m_symGetSymFromAddr == NULL) {
        return FALSE;
    }

    DWORD (WINAPI *symSetOptions)(DWORD) =
        (DWORD (WINAPI *)(DWORD))GetProcAddress(imageHlp, "SymSetOptions");
    if (symSetOptions != NULL) {
        symSetOptions(7);
    }

    return m_symInitialize(GetCurrentProcess(), NULL, TRUE) != FALSE;
}

// UID:0004WU | by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md | Completion:94 | Confidence:94
void ExceptionHandler::IntelStackWalk(CONTEXT *pContext,
                                      FILE *pReportFile)
{
    wchar_t executablePath[MAX_PATH];
    if (pReportFile != NULL) {
        BuildExecutablePathForVersionInfo(executablePath, MAX_PATH);
        fprintf(pReportFile, "Call stack:\n");
        fprintf(pReportFile,
                "Address   Frame     Logical addr  Module\n");
    }

    DWORD instructionPointer = pContext->Eip;
    DWORD *pFrame = (DWORD *)pContext->Ebp;

    for (;;) {
        wchar_t moduleName[MAX_PATH];
        moduleName[0] = L'\0';
        DWORD sectionNumber = 0;
        DWORD sectionOffset = 0;
        GetLogicalAddress((PVOID)instructionPointer,
                          moduleName,
                          MAX_PATH,
                          sectionNumber,
                          sectionOffset);

        if (pReportFile != NULL) {
            fprintf(pReportFile,
                    "%08X  %08X  %04X:%08X %ws\n",
                    instructionPointer,
                    pFrame,
                    sectionNumber,
                    sectionOffset,
                    moduleName);

            if (_wcsicmp(moduleName, executablePath) == 0) {
                fprintf(pReportFile, "%08X\n", sectionOffset);
            }
        }

        instructionPointer = pFrame[1];
        DWORD *pPreviousFrame = pFrame;
        pFrame = (DWORD *)pFrame[0];

        if (((DWORD_PTR)pFrame & 3) != 0 ||
            pFrame <= pPreviousFrame ||
            IsBadWritePtr(pFrame, sizeof(DWORD) * 2)) {
            break;
        }
    }
}

// UID:00014J | by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md | Completion:94 | Confidence:94
void ExceptionHandler::ImagehlpStackWalk(CONTEXT *pContext,
                                         FILE *pReportFile)
{
    wchar_t executablePath[MAX_PATH];
    if (pReportFile != NULL) {
        BuildExecutablePathForVersionInfo(executablePath, MAX_PATH);
        fprintf(pReportFile, "Call stack\n");
        fprintf(pReportFile,
                "Address   Frame     Logical addr  Module\n");
    }

    STACKFRAME stackFrame;
    memset(&stackFrame, 0, sizeof(stackFrame));
    stackFrame.AddrPC.Offset = pContext->Eip;
    stackFrame.AddrPC.Mode = AddrModeFlat;
    stackFrame.AddrStack.Offset = pContext->Esp;
    stackFrame.AddrStack.Mode = AddrModeFlat;
    stackFrame.AddrFrame.Offset = pContext->Ebp;
    stackFrame.AddrFrame.Mode = AddrModeFlat;

    DWORD sectionNumber;

    while (m_stackWalk(IMAGE_FILE_MACHINE_I386,
                       GetCurrentProcess(),
                       GetCurrentThread(),
                       &stackFrame,
                       pContext,
                       NULL,
                       m_symFunctionTableAccess,
                       m_symGetModuleBase,
                       NULL)) {
        if (stackFrame.AddrFrame.Offset == 0) {
            break;
        }

        if (pReportFile != NULL) {
            fprintf(pReportFile,
                    "%08X  %08X  ",
                    stackFrame.AddrPC.Offset,
                    stackFrame.AddrFrame.Offset);
        }

        char symbolStorage[sizeof(IMAGEHLP_SYMBOL) + 512];
        PIMAGEHLP_SYMBOL pSymbol =
            (PIMAGEHLP_SYMBOL)symbolStorage;
        pSymbol->SizeOfStruct = sizeof(symbolStorage);
        pSymbol->MaxNameLength = 512;

        DWORD displacement = 0;
        if (m_symGetSymFromAddr(GetCurrentProcess(),
                                stackFrame.AddrPC.Offset,
                                &displacement,
                                pSymbol)) {
            if (pReportFile != NULL) {
                fprintf(pReportFile,
                        "%hs+%X\n",
                        pSymbol->Name,
                        displacement);
            }
        } else {
            wchar_t moduleName[MAX_PATH];
            moduleName[0] = L'\0';
            sectionNumber = 0;
            DWORD sectionOffset = 0;
            GetLogicalAddress((PVOID)stackFrame.AddrPC.Offset,
                              moduleName,
                              MAX_PATH,
                              sectionNumber,
                              sectionOffset);

            if (pReportFile != NULL) {
                fprintf(pReportFile,
                        "%04X:%08X %ws\n",
                        sectionNumber,
                        sectionOffset,
                        moduleName);
            }
        }

        if (pReportFile != NULL) {
            wchar_t moduleName[MAX_PATH];
            moduleName[0] = L'\0';
            DWORD sectionOffset = 0;
            GetLogicalAddress((PVOID)stackFrame.AddrPC.Offset,
                              moduleName,
                              MAX_PATH,
                              sectionNumber,
                              sectionOffset);
            if (_wcsicmp(moduleName, executablePath) == 0) {
                fprintf(pReportFile, "%08X\n", sectionOffset);
            }
        }
    }

    if (pReportFile != NULL) {
        fprintf(pReportFile, "\n");
    }
}

// UID:0000QN | by-global/g_pCrashTarget.md | Completion:92 | Confidence:94
ExceptionHandler *g_pCrashTarget = 0;

// UID:000297 | by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md | Completion:92 | Confidence:94
// Covered by UID0000QN g_pCrashTarget source definition.

// UID:00004P | by-class\ExceptionHandler.md | Completion:93 | Confidence:95 | Empty Emitter Marker

// UID:00014D | by-memory\0x004ab480-0x004ac89a.ExceptionHandler.md | Completion:90 | Confidence:94 | Empty Emitter Marker

// UID:000259 | by-memory\0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md | Completion:87 | Confidence:91 | Empty Emitter Marker
