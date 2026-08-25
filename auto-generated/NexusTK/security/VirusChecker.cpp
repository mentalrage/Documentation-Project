// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P5
// Source by-file doc: by-file/VirusChecker.md
// UID:0000FW | by-class/VirusChecker.md | Completion:91 | Confidence:93
#include <windows.h>
#include "VirusChecker.h"

// UID:0002A5 | by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md | Completion:88 | Confidence:90
typedef int (__stdcall *V3ProcessEnumCallbackProc)(
    unsigned long processId, unsigned long unused1,
    unsigned long unused2, unsigned long unused3, void *context);
typedef int (__stdcall *V3ModuleEnumCallbackProc)(
    unsigned long processId, unsigned long moduleId,
    const char *modulePath, void *context);

typedef int (__cdecl *V3PCtrlEnumProcessesProc)(
    V3ProcessEnumCallbackProc callback, void *context);
typedef int (__cdecl *V3PCtrlEnumModulesProc)(
    unsigned long processId, V3ModuleEnumCallbackProc callback, void *context);
typedef int (__cdecl *AhnExCheckFileProc)(const char *path);
typedef const char *(__cdecl *AhnExGetVirusNameProc)(int index);

static V3PCtrlEnumProcessesProc s_pfnV3PCtrlEnumProcesses;
static V3PCtrlEnumModulesProc s_pfnV3PCtrlEnumModules;
static AhnExCheckFileProc s_pfnAhnExCheckFile;
static AhnExGetVirusNameProc s_pfnAhnExGetVirusName;
static HMODULE s_hV3Pro32;
static HMODULE s_hV3PCtrl;

// UID:0001NV | by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md | Completion:91 | Confidence:91
enum
{
    kVirusCheckerLoadLibraryErrorText = 219,
    kVirusCheckerGetProcAddressErrorText = 220,
    kVirusCheckerVirusDetectedText = 221
};

bool VirusChecker::LoadV3Scanner()
{
    s_hV3Pro32 = LoadLibraryA("V3PRO32E.DLL");
    if (s_hV3Pro32 == 0)
    {
        SimpleUString message(g_pLanguageMan->GetLocalizedString(kVirusCheckerLoadLibraryErrorText),
                              "V3PRO32E.DLL");
        MessageBoxW(0, message.c_str(), L"Error", 0);
        return false;
    }

    s_pfnAhnExCheckFile = (AhnExCheckFileProc)GetProcAddress(s_hV3Pro32, "AhnExCheckFile");
    s_pfnAhnExGetVirusName = (AhnExGetVirusNameProc)GetProcAddress(s_hV3Pro32, "AhnExGetVirusName");
    if (s_pfnAhnExCheckFile == 0 || s_pfnAhnExGetVirusName == 0)
    {
        SimpleUString message(g_pLanguageMan->GetLocalizedString(kVirusCheckerGetProcAddressErrorText),
                              "V3PRO32E.DLL");
        MessageBoxW(0, message.c_str(), L"Error", 0);
        return false;
    }

    s_hV3PCtrl = LoadLibraryA("V3PCTRL.DLL");
    if (s_hV3PCtrl == 0)
    {
        SimpleUString message(g_pLanguageMan->GetLocalizedString(kVirusCheckerLoadLibraryErrorText),
                              "V3PCTRL.DLL");
        MessageBoxW(0, message.c_str(), L"Error", 0);
        return false;
    }

    s_pfnV3PCtrlEnumProcesses = (V3PCtrlEnumProcessesProc)GetProcAddress(s_hV3PCtrl, "V3PCtrl_EnumProcesses");
    s_pfnV3PCtrlEnumModules = (V3PCtrlEnumModulesProc)GetProcAddress(s_hV3PCtrl, "V3PCtrl_EnumModules");
    if (s_pfnV3PCtrlEnumProcesses == 0 || s_pfnV3PCtrlEnumModules == 0)
    {
        SimpleUString message(g_pLanguageMan->GetLocalizedString(kVirusCheckerGetProcAddressErrorText),
                              "V3PCTRL.DLL");
        MessageBoxW(0, message.c_str(), L"Error", 0);
        return false;
    }

    return true;
}

static void ResetV3ScannerState()
{
    if (s_hV3Pro32 != 0)
        FreeLibrary(s_hV3Pro32);

    if (s_hV3PCtrl != 0)
        FreeLibrary(s_hV3PCtrl);

    s_pfnV3PCtrlEnumProcesses = 0;
    s_pfnV3PCtrlEnumModules = 0;
    s_pfnAhnExCheckFile = 0;
}

void VirusChecker::ScanLoadedProcessModules()
{
    s_pfnV3PCtrlEnumProcesses(V3ProcessEnumCallback, this);

    for (ModulePathSet::iterator iter = m_modulePaths.begin();
         iter != m_modulePaths.end();
         ++iter)
    {
        const char *path = iter->c_str();

        if (s_pfnAhnExCheckFile(path) == 0)
            continue;

        SimpleUString virusName(s_pfnAhnExGetVirusName(1));
        const mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > format =
            g_pLanguageMan->CopyLocalizedString(kVirusCheckerVirusDetectedText);

        SimpleUString modulePath(path);
        SimpleUString message(format.c_str(), modulePath.c_str(), virusName.c_str());

        SetApplicationErrorText(message.c_str());
        g_pApplication->RequestExit();
        return;
    }
}

// UID:0001NW | by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md | Completion:93 | Confidence:94
void VirusChecker::InsertModulePath(const char *path)
{
    m_modulePaths.insert(ModulePathString(path).ToLower());
}

int __stdcall VirusChecker::V3ModuleEnumCallback(
    unsigned long processId,
    unsigned long moduleId,
    const char *modulePath,
    void *context)
{
    VirusChecker *checker = static_cast<VirusChecker *>(context);
    checker->InsertModulePath(modulePath);
    return 1;
}

int __stdcall VirusChecker::V3ProcessEnumCallback(
    unsigned long processId,
    unsigned long unused1,
    unsigned long unused2,
    unsigned long unused3,
    void *context)
{
    s_pfnV3PCtrlEnumModules(processId, V3ModuleEnumCallback, context);
    return 1;
}


// UID:0002OT | by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md | Completion:93 | Confidence:96
// Compiler-emitted VirusChecker RTTI/vtable data.
// Source reconstruction is covered by the VirusChecker : public Singleton<VirusChecker> declaration and virtual destructor in [UID:0000FW][VirusChecker](by-class/VirusChecker.md), with the one-slot layout tracked by [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md); do not emit raw RTTI or vtable objects for this range.


// UID:0003JF | by-type/by-vtable/VirusCheckerVtable.md | Completion:91 | Confidence:95
// Compiler-emitted one-slot VirusChecker vtable/RTTI layout.
// Source reconstruction is covered by [UID:0000FW][VirusChecker](by-class/VirusChecker.md); no raw vtable array or scalar-deleting-destructor source method is emitted here.

// UID:0000SO | by-global/g_pVirusChecker.md | Completion:90 | Confidence:93
VirusChecker *g_pVirusChecker;

// UID:0001NU | by-memory\0x005c0460-0x005c0fe1.VirusChecker.md | Completion:90 | Confidence:92 | Empty Emitter Marker

// UID:0001WG | by-type\by-struct\VirusCheckerProcessTreeLayout.md | Completion:89 | Confidence:94 | Empty Emitter Marker

// UID:0002Z6 | by-memory\0x006310e4-0x00631184.VirusCheckerV3StringData.md | Completion:88 | Confidence:92 | Empty Emitter Marker
