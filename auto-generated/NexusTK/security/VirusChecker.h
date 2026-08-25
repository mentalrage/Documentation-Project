// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P5
// Source by-file doc: by-file/VirusChecker.md
// UID:0000FW | by-class/VirusChecker.md | Completion:91 | Confidence:93
#ifndef NEXUSTK_SECURITY_VIRUSCHECKER_H
#define NEXUSTK_SECURITY_VIRUSCHECKER_H

#include <set>
#include <string.h>
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class VirusChecker : public Singleton<VirusChecker>
{
public:
    VirusChecker();
    virtual ~VirusChecker();

    bool LoadV3Scanner();
    void ScanLoadedProcessModules();

private:
    typedef mystr::StringBase<char, mystr::mychar_traits<char> > ModulePathString;

    struct ModulePathLess
    {
        bool operator()(const ModulePathString& left,
                        const ModulePathString& right) const
        {
            return strcmp(left.c_str(), right.c_str()) < 0;
        }
    };

    typedef std::set<ModulePathString, ModulePathLess> ModulePathSet;

    static int __stdcall V3ModuleEnumCallback(
        unsigned long processId,
        unsigned long moduleId,
        const char *modulePath,
        void *context);
    static int __stdcall V3ProcessEnumCallback(
        unsigned long processId,
        unsigned long unused1,
        unsigned long unused2,
        unsigned long unused3,
        void *context);

    void InsertModulePath(const char *path);

    ModulePathSet m_modulePaths;
};

extern VirusChecker *g_pVirusChecker;

#endif
