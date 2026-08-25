*** UID:0000J8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/platform/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ExceptionHandler

## Status

- Confidence: very strong for the complete class/global source route, exact Generate/Init/Intel/ImageHlp helper family, callback typedefs, Windows-directory report behavior, retained/inlined disposition, exact stored-report member, and platform placement; original Nexus symbols/source and rebuilt-binary comparison remain the final cap.
- Proposed module: `platform/ExceptionHandler.cpp`
- Historical recovered-output filename: `class_ExceptionHandler.cpp` (non-authoritative context, not the current source route; ignore Wave2/Wave3 workflow labels)
- Main class: [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md)
- Main address docs: [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- Evidence basis: IDA MCP lookup/xref/decompilation checks through 2026-06-07 plus linked by-memory, by-class, and by-global documentation.

## Responsibility

`ExceptionHandler` installs a process top-level exception filter, records crash-related state, writes `BCrash.nfo`, and restores the previous filter when destroyed. It is platform/process infrastructure rather than UI, render, or gameplay code.

## Likely Contents

- `ExceptionHandler` constructor at `0x004ab480`.
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), with one zero CPP definition and one formal `extern ExceptionHandler *g_pCrashTarget;` H declaration for companion consumers.
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) callback at `0x004ab830`, now first-draft C++ ready as `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)`.
- [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) nonvirtual `ExceptionHandler::SendCrashDiagnosticText(const char *)` packet helper at `0x004ab740`; caller `0x00466e80` passes [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) in `ECX` before the call even though the callee body does not dereference fields.
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md), source-ready `void ExceptionHandler::GenerateExceptionReport(EXCEPTION_POINTERS *)` at `94/96`; it writes Windows-directory `BCrash.nfo` and preserves exact Nexus failure behavior.
- [UID:00014H][0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString](by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md), source-ready private static `LPTSTR ExceptionHandler::GetExceptionString(DWORD)`; [UID:00014I][0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress](by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md), source-ready private static `bool ExceptionHandler::GetLogicalAddress(PVOID, PTSTR, DWORD, DWORD &, DWORD &)`; [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md), source-ready retained `InitImagehlpFunctions`; [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md), source-ready retained `IntelStackWalk`; and [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md), source-ready `ImagehlpStackWalk`. The three stack/ImageHlp children are each `94/94` with complete formals.
- scalar deleting destructor at `0x004ac860`.
- companion [UID:0000II][Crasher](by-file/Crasher.md) remains a separate source file and depends on the external `g_pCrashTarget` declaration plus the inline `ExceptionHandler::SetSkipCrashReport(bool)` source surface.
- object byte at offset `+4`, `m_skipCrashReport`, written through the public inline setter by `Crasher::OnTimer` and read by `TopLevelExceptionFilter`.

Related but not direct file-owned after B001-013: [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) / [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md). That helper deletes the active handler object, but IDA MCP shows it is called only as paired Application/resource fatal-load cleanup, so the helper body is assigned to [UID:0000HG][Application](by-file/Application.md).

## Evidence

- Historical recovered/generated output established that the constructor sets `g_pCrashTarget`, installs the class vptr, calls `SetUnhandledExceptionFilter`, stores the previous filter, and clears crash-state fields; current source reconstruction must express those source semantics without handwritten vtable/RTTI data.
- IDA MCP confirms `0x004ab480-0x004ab4ed`, `0x004ab740-0x004ab804`, `0x004ab830-0x004ab86f`, `0x004ab870-0x004abd10`, `0x004abd10-0x004abe4a`, `0x004abfa0-0x004ac035`, `0x004ac040-0x004ac0ed`, `0x004ac230-0x004ac4cb`, and `0x004ac860-0x004ac89a` as modeled functions. Exact raw code `[0x004ac0f0,0x004ac221)` contains 89 instructions and terminal `ret 8` but lacks a current IDA function record; it is nevertheless source-ready as `IntelStackWalk`.
- IDA caller evidence shows construction from the app startup region at `0x004639d0`.
- `GenerateExceptionReport` builds `BCrash.nfo` under the Windows directory through `GetWindowsDirectoryW`, records version/exception/fault/register/timer/phase/RGB565 state, dynamically resolves `IMAGEHLP.DLL`, calls `ImagehlpStackWalk` on success and `IntelStackWalk` on failure, and preserves the original unconditional separator write even when file open failed.
- 2026-06-07 Batch 034 IDA MCP refresh on `NexusTK.exe` SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632` rechecked [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) and [UID:000297][0x0067ab34-0x0067ab38.g_pCrashTarget](by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md). IDA reports nine data xrefs to `0x0067ab34`: application cleanup `0x00464c5e`, startup/failure cleanup `0x00466e70`, destroy helper `0x004673a0`, `Crasher::TriggerCrash` `0x0049bb60`, constructor write `0x004ab499`, raw destructor/reset body `0x004ab4ff`, `TopLevelExceptionFilter` read `0x004ab83a`, scalar deleting destructor clear `0x004ac879`, and startup/account dialog crash-report sender path `0x005101e2`.
- The same recheck supports this file as the direct source parent for the global singleton declaration: all writes/clears outside `Crasher` occur in the exception-handler constructor/destructor/filter lifecycle, while `Crasher` is a consumer that sets the suppress-report flag through the active object pointer.
- 2026-06-10 B001-013 IDA MCP source-owner audit for [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md): the helper reads `dword_67AB34` and calls the active object's deleting destructor, but its 22 direct callers are the same fatal image/resource load exits that first call [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md). No caller comes from the `0x004ab480-0x004ac89a` ExceptionHandler method cluster; normal `g_pCrashTarget` writes/clears remain in the constructor/destructor/filter lifecycle here.
- Current Crasher integration keeps [UID:0000II][Crasher](by-file/Crasher.md) separate. `ExceptionHandler.cpp` owns [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), its external declaration, private `m_skipCrashReport`, and inline `SetSkipCrashReport(bool)`; Crasher consumes those legal public/header surfaces before the intentional diagnostic crash.

## Placement Notes

Place under `platform/` for now because the implementation is Windows exception-filter and crash-report glue. If later caller/string evidence shows it is tied to the startup application shell, `app/ExceptionHandler.cpp` is also plausible.

## 2026-06-18 B005 Source-Placement Conclusions

- Closed: keep this family in `platform/ExceptionHandler.cpp`. A separate `CrashDiagnostics.cpp` is not justified by current evidence because the helpers are tied to `ExceptionHandler` fields, `g_pCrashTarget`, `BCrash.nfo`, and the ExceptionHandler diagnostics `.rdata` island.
- Closed: [UID:000259][0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md) is source-owned by this file. The class declaration regenerates the `ExceptionHandler` COL/vtable, while the crash-report, exception-code, stack/logical-address, and ImageHlp resolver literals should remain in executable consumer helpers rather than a hand-authored `.rdata` blob.
- Closed: [UID:0000II][Crasher](by-file/Crasher.md) remains a separate companion source file and consumes `g_pCrashTarget` plus `SetSkipCrashReport(true)`. Direct private-field access is historical decompiler/source-draft syntax, not final C++.
- Closed: [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md) `DestroyExceptionHandler` is Application fatal-load cleanup, not direct ExceptionHandler implementation ownership.
- Closed for draft source: use descriptive names `m_skipCrashReport`, `m_previousFilter`, `m_symInitialize`, `m_symCleanup`, `m_stackWalk`, `m_symFunctionTableAccess`, `m_symGetModuleBase`, `m_symGetSymFromAddr`, and `m_reportText[0x400]` for the class layout.
- Target-family source-quality closure: exact identities `GenerateExceptionReport`, `InitImagehlpFunctions`, `IntelStackWalk`, and `ImagehlpStackWalk`, all three helper splits/formals, six legacy callback typedefs, Windows-directory behavior, and zero-xref retained/inlined disposition are resolved. Unrelated raw ranges at `0x004ab810`, `0x004ac4d0`, and `0x004ac650`, exact unrelated private spellings, and rebuilt-binary comparison remain independent file-level caps.

## Open Questions

- Exact original spellings remain open for helpers such as `SendStoredCrashReportFile` and for the exact original member spelling of `ExceptionHandler::SendCrashDiagnosticText`. The former `GetExceptionCodeText` and `GetLogicalAddress` questions are closed: exact `MSJEXHND` source/header lineage proves private static `LPTSTR ExceptionHandler::GetExceptionString(DWORD dwCode)` and private static `bool ExceptionHandler::GetLogicalAddress(PVOID, PTSTR, DWORD, DWORD &, DWORD &)`.
- Closed for the assigned report family: exact children [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md), [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md), and [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md) own complete formals. Independent exact child/formal questions remain only for unrelated raw starts `0x004ab810`, `0x004ac4d0`, and `0x004ac650`.
- Keep [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) separate even though `TopLevelExceptionFilter` restores keyboard settings during crash cleanup.

## 2026-06-20 TopLevelExceptionFilter Source Readiness

[UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) remains in this `platform/ExceptionHandler.cpp` file route through [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) and [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md). The callback body is source-authored and now belongs on the exact child page, not in the aggregate page.

B001/B015 evidence keeps the source owner here and rejects direct `Crasher.cpp`, `KeySpeedMgr.cpp`, Application, ImageHlp, packet, Error, CRT, and generic runtime owners. `Crasher.cpp` consumes the public inline `g_pCrashTarget->SetSkipCrashReport(true)` source surface, whose inlining produces the exact `[g_pCrashTarget + 4] = 1` machine write without illegal private-field access; `KeySpeedMgr.cpp` owns `RestoreSystemKeyboardSettings`; Application constructs or cleanup-deletes the object; downstream diagnostics helpers remain ExceptionHandler-family code. The child page records the raw PE/disassembly proof for the constructor callback pointer, `g_pKeySpeedMgr` restore call, `g_pCrashTarget` snapshot, `m_skipCrashReport` skip branch, report-writer call, and `m_previousFilter` tailcall.

## 2026-06-20 CrashDiagnosticTextSender Source Readiness

[UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) routes to this `platform/ExceptionHandler.cpp` file through [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) as a nonvirtual member helper. First-draft source should use `void ExceptionHandler::SendCrashDiagnosticText(const char *text)`: the helper has one explicit stack argument and does not read fields, but B013 rechecked the caller at `0x00466e80` and found the source-call pattern `ECX = g_pCrashTarget`, `push formattedText`, `call 0x004ab740`, followed by the one-shot diagnostic latch write at `0x0067ab6c`. That caller-side member-call evidence supersedes the older file-static interpretation.

The helper packetizes already-formatted ANSI diagnostic text as `{0x42, 0x01, length16be, payload, 0}` and sends `length + 5` bytes through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / Socket-owned [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Accepted payload length is `1..0xFFF`; overlong strings are dropped, not truncated. PacketBuffer scalar writers leave an out-of-band scratch zero, so a `0x1005` local buffer covers the maximum `0x1004` counted send plus the spare zero. This evidence rejects Application, Socket, PacketBuffer, CashShopRequest, runtime, and a new `CrashDiagnostics.cpp` file as direct owners.

## 2026-07-14 B003 GetExceptionString Source State

- UID00014H belongs in this existing `NexusTK/platform/ExceptionHandler.cpp` route as `LPTSTR ExceptionHandler::GetExceptionString(DWORD dwCode)`. Exact Microsoft `MSJEXHND` source and header prove the class, private access, static storage class, spelling, return type, and parameter type; no new translation unit is warranted.
- The accepted body preserves the source's 22 `EXCEPTION(name)` cases and `NTDLL.DLL` `FormatMessage` fallback with shared `static TCHAR szBuffer[512]`. This is source-authored project code with a reusable lineage, not a CRT/compiler helper or imported implementation.
- The switch/data island `0x004abe4a-0x004abf9c` and alignment `0x004abf9c-0x004abfa0` remain parent-only binary evidence. They must not become source arrays or separate file inventory entries; the compiler regenerates them from the switch.
- `GetExceptionCodeText` and file-static ownership are historical draft conclusions superseded by the direct lineage. The static-member ABI accounts for no `this`/`ECX`, while two writer calls and the private declaration keep ownership inside the class/file family.
- This synchronization preserves this page's `87/88` score, `NexusTK/platform/` route, all unrelated ExceptionHandler contents, raw-helper liveness questions, compiler boundaries, and the separate ownership of Application cleanup and `Crasher`.

## 2026-07-16 B003 GetLogicalAddress Source State

- UID00014I is source-ready in this existing `NexusTK/platform/ExceptionHandler.cpp` route as private static `bool ExceptionHandler::GetLogicalAddress(PVOID address, PTSTR moduleName, DWORD moduleNameLength, DWORD &sectionNumber, DWORD &sectionOffset)`.
- Exact source lineage, five-stack-argument static ABI, `ret 0x14`, `AL` Boolean return, and six same-family calls close the method spelling, ownership, signature, and placement questions. No separate `PeUtil.cpp`, `CrashDiagnostics.cpp`, PlatformApi helper file, Application, Crasher, ImageHlp, Error, runtime, or import source route is justified.
- The source body uses generic `GetModuleFileName` in keeping with the TCHAR-era source, while the project PlatformApi layer supplies the proven `GetModuleFileNameW` dispatch slot at `0x0069be74`. This is a source adaptation, not helper ownership transfer.
- The method walks mapped PE sections after `VirtualQuery`, uses inclusive `max(SizeOfRawData, Misc.VirtualSize)` containment, and writes one-based section number plus section-relative offset only on success. Four modeled and two raw parent-contained callers ignore the Boolean result and rely on their own initialization.
- The old file-static, pointer-output, four-caller, unresolved-slot, and `BOOL` descriptions are historical findings superseded by exact current evidence. Parent switch/data and padding remain compiler-regenerated/non-emitting; no raw PE table source is added.
- This bounded synchronization preserves `87/88`, the `NexusTK/platform/` route, all unrelated contents and ownership boundaries, and independent raw-helper/full-class score caps.

## Cross-References

- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md)
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md)
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md)
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md)
- [UID:00014H][0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString](by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md)
- [UID:00014I][0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress](by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md)
- [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md)
- [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md)
- [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md)
- [UID:000259][0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md)
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md)
- [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md)
- [UID:0000II][Crasher](by-file/Crasher.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-06 B005 UID000298 Crasher dependency synchronization:
  - Recorded the source-owned external `g_pCrashTarget` declaration and inline `SetSkipCrashReport(bool)` class surface consumed by `Crasher.cpp`.
  - Preserved all unrelated ExceptionHandler diagnostics behavior, layout, helpers, compiler exclusions, scores, and Application cleanup boundary.

- 2026-07-16 B003 GetLogicalAddress implementation support sync:
  - Preserved `87/88`, `NexusTK/platform/`, all unrelated file inventory, ownership boundaries, and broader score caps.
  - Closed UID00014I spelling, private-static ownership, signature, W-dispatch adaptation, six-call inventory, and source placement; rejected separate PE/diagnostics and dependency-owned placements.
- 2026-07-14 B003 GetExceptionString implementation support sync:
  - Preserved `87/88`, `NexusTK/platform/`, all unrelated file inventory, and broader score caps.
  - Added source-ready private static `LPTSTR ExceptionHandler::GetExceptionString(DWORD)` to likely contents and closed that method's name/type/access/source-placement question from exact `MSJEXHND` lineage.
  - Historicalized `GetExceptionCodeText`/file-static ownership and retained the switch island and padding as compiler-regenerated, parent-only non-emitting evidence.

- 2026-06-18 B005 source-quality incorporation:
  - Changed to: `COMPLETION:87`, `CONFIDENCE:88`.
  - Evidence: closed the standalone diagnostics-file question, fixed the offset `+4` field name to `m_skipCrashReport`, documented the explicit Application construction route and Application-owned cleanup wrapper boundary, tied [UID:000259][0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData](by-memory/0x006196bc-0x00619d28.ExceptionHandlerDiagnosticsReadOnlyData.md) to this source file without raw `.rdata` emission, and recorded the remaining score caps as exact helper spellings/raw-helper liveness/child C++ bodies.
- 2026-06-20 B001/B015 TopLevelExceptionFilter child sync:
  - Score unchanged at `87/88`.
  - Marked [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) as first-draft C++ ready on the exact child page and preserved `platform/ExceptionHandler.cpp` as source root while rejecting `Crasher`, `KeySpeedMgr`, Application, runtime, ImageHlp, packet, and Error ownership alternatives.
- 2026-06-20 B005 CrashDiagnosticTextSender child sync:
  - Score unchanged at `87/88`.
  - Historical note: the B005 pass marked [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) as first-draft C++ ready on its exact child page using direct file-static ownership because the callee body has no field access.
  - Evidence: B005 source-quality report, PacketBuffer scalar writer docs, Socket queue/send docs, `g_packetSender` docs, and the cached `0x004ab740` function export agree on behavior and dependencies.
- 2026-06-22 B013 CrashDiagnosticTextSender member-call correction:
  - Score unchanged at `87/88`.
  - Corrected [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) to route through [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) while remaining emitted from this source file. B013's local PE/Capstone and caller-shape recheck proves `ECX = g_pCrashTarget` at caller `0x00466e80`, making the class-member interpretation stronger than the older file-static one.
- 2026-06-17 B001 Crasher source-quality sync:
  - Score unchanged at `86/86`.
  - Preserved [UID:0000II][Crasher](by-file/Crasher.md) as a separate companion file and clarified that this file owns `g_pCrashTarget` plus the object flag at offset `+4`; later B005 source-quality work names it `m_skipCrashReport` for draft source.
- 2026-06-10 B001-013 DestroyExceptionHandler ownership repair:
  - Score unchanged at `86/86`.
  - Removed [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) from direct likely contents and documented it as related Application fatal-load cleanup instead.
  - Evidence: B001-013 IDA MCP confirmed the helper deletes `g_pCrashTarget` but has 22 paired resource-failure call sites, no ExceptionHandler-cluster callers, and normal `g_pCrashTarget` lifecycle writes/clears in this module. This file remains the class/global owner, not the cleanup-wrapper source owner.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: process exception-filter role, likely contents, crash globals, report/filter/helper functions, IDA evidence, placement notes, Crasher/KeySpeed/Error boundaries, and open helper naming questions are documented; confidence is strong with final folder and Crasher colocation still medium.
- 2026-06-07 Batch 034 crash-target parent refresh:
  - Before: `84/82`, and the evidence basis still mentioned generated recovered output.
  - Changed to: `86/86`, with current IDA-backed `g_pCrashTarget` xref inventory and source-parent rationale.
  - Summary/evidence: live IDA MCP reconfirms the singleton pointer's constructor/destructor/filter lifecycle in this module and separates the `Crasher` diagnostic consumer from the `ExceptionHandler` global owner. Helper naming and final Crasher colocation remain below final-audit quality, so scores stay well under 95.

## B001 UID0003TY Complete Source-Family Synchronization - 2026-07-20

- `NexusTK/platform/ExceptionHandler.cpp` now has a complete declaration route through [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md), source global [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), and exact source-bearing child [UID:0004TS][0x004ab510-0x004ab73b.ExceptionHandlerSendStoredCrashReportFile](by-memory/0x004ab510-0x004ab73b.ExceptionHandlerSendStoredCrashReportFile.md).
- Address/source order remains constructor, raw ordinary destructor/reset, `SendStoredCrashReportFile`, [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md), raw wide-text setter, file-static top-level filter, report writer, exception-string/logical-address/ImageHlp/stack helpers, and compiler scalar wrapper. Exact bodies remain on their respective child pages.
- UID0004TS is a nonvirtual member because UID0003TY loads `g_pCrashTarget` into `ECX` before its sole call. It obtains OS version text, reads up to 4096 bytes from `BCrash.nfo`, emits opcode `0x42` subtype 1 with BE16 length, closes an opened file, and always deletes the path.
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) is defined once as `ExceptionHandler *g_pCrashTarget = 0;`; exact storage [UID:000297][0x0067ab34-0x0067ab38.g_pCrashTarget](by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md) is covered-by only. Constructor/destructor/filter/Application/Crasher consumers remain documented without duplicating storage.
- The class uses natural 32-bit alignment after `m_skipCrashReport`, retains real unresolved `m_reserved0C`, all IMAGEHLP pointers and report text, and exact size `0x828`. No explicit source padding field is emitted.
- Current file score becomes `90/92`; projected path `NexusTK/platform/`, canonical owner FILE, every existing helper/global/consumer relation, retained raw body, and historical section are preserved.
- Vptr/RTTI/EH/cookie/scalar-delete/base-teardown, aggregate duplication, file-static duplication of UID0004TS, a second global definition, and UI/gameplay ownership are explicitly excluded from handwritten source.

## 2026-07-24 B001 GenerateExceptionReport Family Source Closure

- `NexusTK/platform/ExceptionHandler.cpp` now has a single exact child route for `GenerateExceptionReport`, `InitImagehlpFunctions`, `IntelStackWalk`, and `ImagehlpStackWalk`. UID00014D remains blank/child-only, and UID00004P contributes declarations plus `[[CHILDREN]]`; no body is emitted twice.
- The retained Init and Intel definitions have zero start xrefs because `GenerateExceptionReport` contains compiler-inlined semantic copies. Their exact children UID0004WT and UID0004WU preserve the out-of-line source bodies and exclude three-byte and fifteen-byte alignment respectively. UID00014J excludes its five-byte tail pad.
- The six callback fields retain exact offsets `+0x10..+0x24` and now use `SYMINITIALIZEPROC`, `SYMCLEANUPPROC`, `STACKWALKPROC`, `SYMFUNCTIONTABLEACCESSPROC`, `SYMGETMODULEBASEPROC`, and `SYMGETSYMFROMADDRPROC`. Dynamic lookup and the absence of failure-path `FreeLibrary` are Nexus behavior.
- Windows-directory `BCrash.nfo`, duplicate `GetExceptionString`, ignored `GetLogicalAddress` result, null-stream separator write, timer/phase/RGB565 output, and ImageHlp-or-x86-fallback behavior remain documented on UID00014G rather than flattened into this file index.
- Historical `WriteCrashReport`, `InitializeImageHlp`, `WriteImageHlpStackWalk`, current/client-directory output, raw `void *` callbacks, and unresolved target-helper liveness remain only in dated provenance. The current file score is `92/94`; unrelated raw helper work and unavailable original source/rebuild comparison prevent a higher file-wide score.
