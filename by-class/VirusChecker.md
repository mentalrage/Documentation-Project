*** UID:0000FW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <windows.h>
#include "VirusChecker.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# VirusChecker

## Status

- Confidence: very strong for recovered class identity, direct inheritance, object layout, class/file/source placement, vtable/global/container evidence, and first-draft class shape; normal runtime activation remains unproven but does not weaken the static source contract.
- Likely source file: [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- Main address range: [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)

## Class Purpose

`VirusChecker` is a small singleton wrapper around AhnLab/V3 scanning DLLs. It owns a tree of process/module paths, scans those paths with `AhnExCheckFile`, reports detections with the virus name from `AhnExGetVirusName`, and frees the V3 modules/function pointers during teardown.

Current RTTI proves the actual source shape is `class VirusChecker : public Singleton<VirusChecker>`. The class hierarchy contains only `VirusChecker` and the direct visible non-virtual Singleton specialization. The Singleton base PMD is `+0x04`, where empty-base optimization overlaps the first word of `m_modulePaths`; it is not an explicit data member.

The class is retained optional scanner code compiled into the client. The dated MCP session `e63ee655` found no direct xrefs or little-endian pointer patterns for the constructor `0x005c0460`, V3 load helper `0x005c05a0`, raw reset helper `0x005c0770`, scanner entry `0x005c07b0`, direct insert helper `0x005c0940`, or singleton clear helper `0x005c0eb0`, while expected local callback, vtable, and singleton references were present. The best-supported current inference is disabled/optional AhnLab integration, a distribution-specific activation route absent from this build, or an unresolved computed call; this caps confidence but does not make the class non-reconstructable. The earlier `86fb854e` cleanup is historical support only.

## Method And Helper Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| `VirusChecker::VirusChecker` | `0x005c0460-0x005c04df` | Constructs the implicit `Singleton<VirusChecker>` base, then initializes `m_modulePaths`. Binary lowering forms the base at `this+0x04`, adjusts back by `-0x04` to publish the complete object, installs vtable `0x006310e0`, initializes the set header/count at `+0x04/+0x08`, and allocates the sentinel through `0x005796d0`; the publication and vptr store are not handwritten body statements. |
| `VirusChecker::~VirusChecker` | `0x005c04e0-0x005c059c` | Authored behavior frees `s_hV3Pro32` and `s_hV3PCtrl` if nonzero, clears selected V3 function pointers, and destroys `m_modulePaths`. Vptr restoration and the final `g_pVirusChecker` clear are virtual-destructor and implicit Singleton-base lowering, not source statements to duplicate. |
| [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md) | `0x005c05a0-0x005c076d` | `VirusChecker::LoadV3Scanner` / `LoadV3ScannerDlls`: loads `V3PRO32E.DLL` and `V3PCTRL.DLL`, resolves `AhnExCheckFile`, `AhnExGetVirusName`, `V3PCtrl_EnumProcesses`, and `V3PCtrl_EnumModules`, reports localized MessageBoxW errors for missing DLL/export paths, and now emits formal first-draft method C++ on UID0001NV. |
| [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md) | `0x005c0770-0x005c07af` | Source-local raw `ResetV3ScannerState` / `FreeV3ScannerLibraries` helper; not an IDA function and no static caller was found. UID0001NV now emits formal first-draft source that frees both V3 module handles if present, then clears the enum-process, enum-module, and check-file pointers only. |
| [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md) | `0x005c07b0-0x005c0937` | `VirusChecker::ScanLoadedProcessModules`: formal first-draft source on UID0001NV enumerates process/module paths, checks each stored path with `AhnExCheckFile`, formats localized detection text id `221`, calls the Application error-text setter at `0x00465af0`, then calls `Application::RequestExit` at `0x00464e40`. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c0940-0x005c09ec` | `VirusChecker::InsertModulePath(const char *path)`: direct source-style insertion helper, no static caller found. Copies/normalizes an ANSI/module path string and inserts it into the set. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c09f0-0x005c0aa0` | `V3ModuleEnumCallback`: four-argument stdcall callback. Uses the module path at `[ebp+0x10]` and `VirusChecker *` context at `[ebp+0x14]`, inserts the path, and returns `1`. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c0aa0-0x005c0ac0` | `V3ProcessEnumCallback`: five-argument stdcall callback. Passes process argument `[ebp+8]`, module callback `0x005c09f0`, and context `[ebp+0x18]` to `s_pfnV3PCtrlEnumModules`, then returns `1`. |
| [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md) | `0x005c0ac0-0x005c0fe1` | Internal path-set allocation, insert/rebalance, lookup-or-insert, EH singleton clear, compiler scalar deleting destructor, and recursive node cleanup helpers. Express as source container behavior around `std::set<String>` / project string wrapper, not as public API or hand-portable STL internals. |
| compiler scalar deleting destructor | `0x005c0ec0-0x005c0f93` | Compiler artifact generated from `virtual VirusChecker::~VirusChecker`; repeats teardown, restores the vptr, clears Singleton storage through lowering, and conditionally frees the 12-byte object when delete flag bit 0 is set. Source declares only the virtual ordinary destructor. |

## Inheritance And Object Layout

- The dated MCP session `7be8cc9f` decodes Complete Object Locator `0x00653f08` and Class Hierarchy Descriptor `0x00653f1c` with exactly two base descriptors: `VirusChecker` and `Singleton<VirusChecker>`.
- `Singleton<VirusChecker>` descriptor `0x00653f54` has PMD `{mdisp=4,pdisp=-1,vdisp=0}` and attributes `0x40`. The absence of not-visible/private/protected/ambiguous/virtual flags supports direct public non-virtual inheritance.
- Complete object layout is 12 bytes: vptr at `+0x00`, empty Singleton base and `m_modulePaths` header overlap at `+0x04`, and `m_modulePaths` count at `+0x08`. The scalar deleting wrapper passes size `0x0c` to deallocation.
- Source must not add a Singleton pointer/member, explicit vptr field, RTTI structure, raw vtable array, scalar-deleting method, delete-flags parameter, or explicit singleton publication/clear statements.

## Data Notes

- [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md) is at [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md). This class block keeps the header/class-facing `extern VirusChecker *g_pVirusChecker;` declaration; the by-global page owns the source definition `VirusChecker *g_pVirusChecker;`.
- IDA confirms the one-slot [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md) uses object vptr `0x006310e0`; the only function slot is scalar deleting destructor `0x005c0ec0`. The mixed [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) page is retained only as a non-emitting security-vtable index.
- The observed object and path-tree fields are recorded in [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md). Object offset `+0x04` is both the direct empty Singleton base PMD and the path-set header/sentinel pointer through EBO; `+0x08` is the path-set node count. Avoid the disproved generated `m_state` wording and use the selected source reconstruction `ModulePathSet m_modulePaths`.
- Module/function pointer globals should use source-facing names from [UID:0002A5][0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals](by-memory/0x0069bf7c-0x0069bf94.VirusCheckerDynamicLibraryGlobals.md): `s_pfnV3PCtrlEnumProcesses`, `s_pfnV3PCtrlEnumModules`, `s_pfnAhnExCheckFile`, `s_pfnAhnExGetVirusName`, `s_hV3Pro32`, and `s_hV3PCtrl`.
- The dated MCP session `e63ee655` `get_bytes 0x0069bf7c size 28` shows the V3 dynamic globals and `g_pVirusChecker` storage are zero-filled static data; older `86fb854e` evidence remains historical support and older `0xffffffff` initial-value wording is stale unless a future live runtime pass proves a separate initializer.
- Current exported metadata still contains historical control-character name records such as `~VirusChecker\r` and old name-control grade reasons. Treat the metadata history rows as stale and prefer live IDA plus canonical documentation names for naming.
- 2026-06-04 live IDA recheck confirms the object layout, V3 DLL load/scan helpers, process/module callback chain, red-black-tree-style path set, singleton xrefs, one-slot vtable, and boundary before `WaitableTimer`.
- Dated MCP xrefs still show no direct callers for the constructor `0x005c0460`, loader `0x005c05a0`, scanner `0x005c07b0`, or direct insert helper `0x005c0940`; the scalar deleting destructor `0x005c0ec0` is vtable-only through `0x006310e0`, and the only external code xref to the local clear helper `0x005c0eb0` is a compiler EH cleanup thunk at `0x0060bc76`. The same dated snapshot's `find_bytes` likewise finds no pointer-pattern route to the constructor/destructor/load/reset/scan/insert/clear starts.
- File parent [UID:0000P5][VirusChecker](by-file/VirusChecker.md) is strong enough for class attachment and first-draft code under the active 85/85 source-readiness gate. This page emits the first-draft class/source-shape declaration with `[[CHILDREN]]`; UID0001NV now emits the V3 load/reset/scan method bodies, while remaining exact helper bodies stay on exact by-memory children and compiler vtable/scalar-deleting-destructor bytes remain compiler-emitted rather than handwritten source.
- 2026-06-29 B002 accepted implementation used dated MCP session `agent_b009_0002my_20260628` to confirm UID0001NV loader/scanner boundaries, raw reset helper liveness, V3 typedef/global/string evidence, LanguageMan ids `219`/`220`/`221`, `SetApplicationErrorText`, `Application::RequestExit`, and no direct activation route. The no-caller state remains a confidence cap, not a reason to keep the method bodies blank.
- 2026-06-07 A002 parent-gate follow-up rechecked the Batch 024 vtable evidence: the direct `VirusChecker` vtable fragment at `0x006310dc-0x006310e4` contains the class RTTI word and one scalar-deleting-destructor slot, with constructor/destructor/deleting-destructor refs to `0x006310e0`. Together with the existing constructor/destructor/scanner/tree-helper evidence, this justifies raising confidence to 85 while keeping the unresolved runtime-activation cap.
- 2026-07-23 B005 UID0002OT dated MCP session `7be8cc9f` supersedes earlier sessions for the class hierarchy and vtable relationship. It proves the direct visible non-virtual `Singleton<VirusChecker>` base at PMD `+0x04`, the two-entry hierarchy, one-slot vtable, three vptr stores, constructor base adjustment, 12-byte complete object, and compiler-generated scalar deleting wrapper.

## Cross-References

- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md)
- [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md)
- [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)
- [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md)
- [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md)
- [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)

## 2026-08-02 Header And Source Closure

- This class is the declaration owner for all source-facing VirusChecker members. `VirusChecker.h` carries the complete direct `Singleton<VirusChecker>` inheritance, public constructor/destructor/load/scan declarations, private StringBase/set aliases, both typed static callbacks, `InsertModulePath`, `m_modulePaths`, and the singleton extern. `VirusChecker.cpp` includes that header and receives only exact child definitions through `[[CHILDREN]]`.
- `ModulePathString` is the exact ANSI `mystr::StringBase<char, mystr::mychar_traits<char> >` specialization used by the binary. Path normalization consumes the shared header-visible inline `StringBase<char>::ToLower() const` specialization from `StringBase.h` or an included `.inl`; the inlined VirusChecker form is a consumer, not a definition owned by `VirusChecker.cpp` or `StringBase.cpp`. `ModulePathLess` is stateless and models the observed `strcmp(left.c_str(), right.c_str()) < 0` ordering. `ModulePathSet` is the source-level `std::set` whose compiler layout is the 8-byte storage at `+0x04/+0x08` and whose generated nodes are 0x14 bytes.
- Vendor enumeration exports are caller-cleaned cdecl pointers declared in the module-static child. Their callbacks are class-private static stdcall functions: the module callback cleans 16 bytes and consumes `modulePath` plus class context, while the process callback cleans 20 bytes and forwards process id, callback, and context to the module enumerator.
- Exact child ordering under the source root is module statics at position `10`, V3 load/reset/scan methods at `20`, and process-tree member/callback definitions at `30`. Vtable data, EH singleton clear, scalar deleting destructor, and Dinkumware node allocation/search/rebalance/destruction remain compiler-generated consequences and are not handwritten methods.
- Historical superseded source shape: the former CPP-resident class definition used forward declarations `template <class T> class Singleton;` and `class String;`, an incomplete `std::set<String>` alias, and omitted callback declarations. It was a useful first draft but could not produce the accepted sibling H/CPP closure. The formal channels now carry the complete header and include-only source shell instead.
- The absence of a recovered normal activation caller remains a runtime-confidence caveat. It does not change the exact RTTI hierarchy, 12-byte EBO object layout, method behavior, source ownership, or source-ready callback/container declarations.

All named MCP sessions in this page are dated evidence snapshots, not permanent current authority. Future IDA-dependent decisions require a fresh supervisor `idb_list`, health/canonical-disk identity, and target-prestate readback.

## Changes

- 2026-08-06 B003 UID0001NW placement callback: propagated the shared header-visible StringBase ToLower specialization into the class source model, retained VirusChecker as an inline consumer, and historicalized named MCP sessions without deleting dated evidence.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the singleton constructor/destructor, V3 load/scan helpers, process-tree helpers, global function/module pointers, vtable/layout evidence, and stale metadata caveats; confidence remains capped by medium live-activation evidence.
- 2026-05-31 reconstructable flag:
  - What existed before: blank `RECONSTRUCTABLE`.
  - Changed to: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms this class as NexusTK-owned wrapper/source code around dynamically loaded V3 scanner DLLs, with local singleton lifecycle and process-tree ownership.
- 2026-06-04 parent/confidence update:
  - Before: `CONFIDENCE:82` and blank `AUTOGEN_PARENT_UID`.
  - After: `CONFIDENCE:84` and `AUTOGEN_PARENT_UID:0000P5`.
  - Summary/evidence: live IDA rechecked the exact constructor/destructor/loader/scanner/callback/tree/destructor ranges, V3 DLL/export strings, singleton/vtable refs, no-direct-caller state, EH cleanup thunk, and padding boundary. Confidence remains capped by unresolved runtime activation; the later 2026-06-20 update superseded the old below-95 no-code policy with the current formal class block.
- 2026-06-07 A002 Batch 024 parent-gate follow-up:
  - Before: `COMPLETION:86`, `CONFIDENCE:84`, and parent `0000P5`.
  - After: `COMPLETION:86`, `CONFIDENCE:85`, and parent `0000P5` retained.
  - Summary/evidence: the file parent was raised to `86/85`, and the class now has enough direct constructor/destructor/vtable/process-tree evidence to clear the strict 85-confidence parent gate. Runtime activation remains unresolved, so confidence stays below 90 and final C++ remains withheld.
- 2026-06-12 A004 Batch 341 reference cleanup: added exact source-local [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md) as the concrete type-vtable page; [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) is now retained only as a non-emitting mixed security-vtable index.
- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`, and empty reconstruction C++ due stale below-95 wording.
  - After: `COMPLETION:88`, `CONFIDENCE:89`, owner/emitter [UID:0000P5][VirusChecker](by-file/VirusChecker.md) retained, and first-draft class/source-shape C++ populated.
  - Summary/evidence: superseded by the 2026-06-29 B004 MCP rework and the 2026-07-03 UID0001Q3 singleton refresh below; the old local PE/Capstone pass is retained only as historical lead material.
- 2026-06-29 B002 accepted implementation sync:
  - Score unchanged at `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: synchronized class notes after UID0001NV was raised to `91/91` and populated with formal first-draft C++ for `LoadV3Scanner`, raw `ResetV3ScannerState`, and `ScanLoadedProcessModules`; the class declaration shape remains unchanged and `[[CHILDREN]]` still carries exact by-memory method bodies.
- 2026-06-29 B004 dated MCP source-quality cleanup:
  - Score, owner/emitter, reconstructable state, and the existing formal class C++ block were preserved unchanged.
  - Summary/evidence: then-dated MCP session `86fb854e` reconfirmed the constructor/destructor/load/scan/process-tree/scalar-destructor island, one-slot vtable bytes `08 3f 65 00 c0 0e 5c 00`, V3 DLL/export strings, zero-filled dynamic globals and singleton slot, local singleton lifecycle refs, callback refs, and no direct constructor/load/scan/direct-insert activation route. The previous B004 local PE/Capstone wording is now historical only.
- 2026-07-03 B004 UID0001Q3 singleton implementation sync:
  - Score, owner/emitter, reconstructable state, and formal class C++ block were preserved unchanged.
  - Summary/evidence: dated MCP session `e63ee655` superseded `86fb854e` as the then-current singleton snapshot, reconfirming zero-filled V3 dynamic globals and `g_pVirusChecker` storage, exact five singleton lifecycle refs, vtable/scalar-deleting-destructor refs, no interior refs, separate successor `0x0069bf98` ref, and no activation xref or pointer-pattern route. The class-facing `extern VirusChecker *g_pVirusChecker;` remains here while [UID:0000SO][g_pVirusChecker](by-global/g_pVirusChecker.md) owns the source definition.
- 2026-07-23 B005 UID0002OT accepted support implementation:
  - Raised completion/confidence from `88/89` to `91/93`; preserved file owner/emitter [UID:0000P5][VirusChecker](by-file/VirusChecker.md) and reconstructable state.
  - Repaired the formal declaration to `VirusChecker : public Singleton<VirusChecker>`, added the template forward declaration, and documented direct-base RTTI, PMD `+0x04`, EBO overlap, 12-byte layout, and implicit Singleton/vtable/scalar-destructor lowering.
  - Historicalized the former base-less class shape and explicit-publication/clear interpretation as incomplete decompiler-facing models. The retained no-normal-activation evidence remains a runtime caveat rather than a class identity or source-shape blocker.
