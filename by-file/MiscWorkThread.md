*** UID:0000LG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MiscWorkThread

## Status

- Confidence: strong for class ownership, worker-message/reachability evidence, app-owned singleton routing, local notification payload classes, and `NexusTK/app/MiscWorkThread.cpp` placement; medium-high for exact original helper spellings.
- Proposed source pair: `app/MiscWorkThread.cpp` and `app/MiscWorkThread.h`
- Current generated source route: `auto-generated/NexusTK/app/MiscWorkThread.cpp`
- Main class: [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- Main address doc: [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- Singleton storage: [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- Evidence basis: `simroot_v2` generated files, IDA MCP lookup/decompile/xref checks, and B011 2026-06-19 raw PE reanalysis for the browse-directory notification path.

## Hypothesis

`MiscWorkThread.cpp` was an application-owned background-service module. It derives from the shared [UID:0000OR][Thread](by-file/Thread.md) worker base and multiplexes small asynchronous tasks that do not belong cleanly to one UI feature: WinInet HTTP fetches, NCA auth/update probes, and Shell browse-directory dialogs.

Keep it under `app/` for the current source-layout map because [UID:0000HG][Application](by-file/Application.md) constructs and destroys the singleton and because the worker serves patch, registration, and folder-selection consumers. Its network helpers depend on WinInet, but the module is not a transport/session class like [UID:0000NS][Socket](by-file/Socket.md) or [UID:0000JC][FileDownloader](by-file/FileDownloader.md).

## Likely Contents

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md)
- [UID:000012][brdir__Notification](by-class/brdir__Notification.md)
- [UID:000069][httpget__Notification](by-class/httpget__Notification.md)
- [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md)
- `FetchHTTPContent` helper at `0x005277c0`
- `ProcessNCAUpdate` helper at `0x00527bb0`
- NCA confirm-user URL storage: packet override [UID:00029T][0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString](by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md) and built-in obfuscated fallback [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md)
- browse-directory helper at `0x00527eb0`
- request submission wrappers at `0x00528290`, `0x00528310`, and raw start `0x005283b0`
- notification construction/post helpers, including `0x00528560` for NCA status notifications
- Compiler-generated primary RTTI/vtable support, including [UID:0004HM][0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer](by-memory/0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer.md), regenerated from the class declaration rather than a raw RTTI source file
- Reusable complete-base dependencies [UID:0000OR][Thread](by-file/Thread.md) / `Thread.h` and [UID:0004ZK][Singleton](by-file/Singleton.md) / [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md)

## 2026-07-01 Generated Output Audit And Declaration Split

B008 empty-emitter family implementation audited `auto-generated/NexusTK/app/MiscWorkThread.cpp` before the callback. The generated file header was `validator-command-id: 000000003842`, `validator-refreshed-at: 2026-07-01T15:24:09-04:00`, and the research tracker row reported `12` total emitters, `2` filled, `10` empty, and `16.7%` filled.

The intended source split is now explicit:

- [UID:000012][brdir__Notification](by-class/brdir__Notification.md) already emits the `brdir::Notification` source payload declaration.
- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) emits only `#include "MiscWorkThread.h"` plus `[[CHILDREN]]` in CPP; its guarded H includes complete `../util/Thread.h` and `../util/Singleton.h`, defines direct bases `Thread, Singleton<MiscWorkThread>`, owns the `extern g_pMiscWorkThread` declaration, and declares exact `OnMessage(int,int,int)` plus request methods.
- [UID:000069][httpget__Notification](by-class/httpget__Notification.md) and [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md) emit the HTTP notification class and state enum.
- [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md) and [UID:0001SQ][NcauthNotificationState](by-type/by-enum/NcauthNotificationState.md) emit the NCA notification class and state enum.
- [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) emits the sole pointer definition and both explicit `Singleton<MiscWorkThread>` lifetime specializations before `[[CHILDREN]]`; [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md) emits only an exact-storage/no-duplicate comment.
- [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md) emits the encoded fallback URL bytes, preserving runtime bitwise-not decode behavior.
- [UID:00029T][0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString](by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md) emits the `SimpleUString` NCA confirm-user URL override storage.
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) remains the worker/helper body island: `FetchHTTPContent`, `ProcessNCAUpdate`, retained private `BrowseForDirectoryAndPost`, exact `OnMessage`, ordinary constructor/destructor, request wrappers, `PostNCAStatus`, and the notification-channel enum. It does not duplicate dedicated declarations, class-specific Singleton specializations, the compiler EH action, or scalar-deleting wrappers.

Rejected owners remain unchanged: `CashShopRequest` is rejected because request wrappers dispatch through `g_pMiscWorkThread` and [UID:0000OR][Thread](by-file/Thread.md); `PatchPane` is a request producer/HTTP consumer only; `NexonclubRegistrationDialog` queues NCA work and consumes results but does not own URL construction or notification payloads; `MainMenuPane` and `MapPane` are packet writer contexts for the override string; speculative standalone auth/network files are weaker than the existing application worker family.

## Evidence

- `Application::Initialize` constructs a `0x68` byte `MiscWorkThread` object and calls `MiscWorkThread::MiscWorkThread` at `0x005281b0`.
- The constructor chains into `Thread(100)`, implicitly invokes the direct empty `Singleton<MiscWorkThread>` base specialization that publishes the complete object through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md), installs the `MiscWorkThread` vtable at `0x0061fb74`, and starts the worker.
- The ordinary destructor stops the worker in its body, then reverse base destruction invokes the Singleton specialization that clears the global before destroying [UID:0000OR][Thread](by-file/Thread.md). Scalar deletion and the 11-byte EH clear action are compiler output, not duplicate handwritten methods.
- `OnMessage` switches on [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md) values `0x42446972`, `0x47654874`, and `0x4e434175`; the matching base virtual slot and exact default call supersede historical `ProcessWorkItem` naming.
- HTTP and NCA helper bodies call WinInet APIs and post `httpget::Notification` / `ncauth::Notification` objects through the application notification channel.
- Browse-directory handling calls `CoInitialize`, `SHBrowseForFolderA`, `SHGetPathFromIDListA`, then posts a `brdir::Notification` object.
- B011 2026-06-19 raw PE reanalysis confirms `brdir::Notification` is a real local source-family payload class, not compiler-only glue: both the retained browse helper and live `OnMessage` BDir branch (then documented under the historical `ProcessWorkItem` alias) allocate `0x108` bytes, construct the [UID:00007D][LObject](by-class/LObject.md) base, store vtable `0x0061fbb0`, populate `char m_path[MAX_PATH]` at `+4`, and post channel `0x42446972`.
- The same B011 pass confirms raw `0x00527eb0` and raw `0x005283b0` have no direct `call`/`jmp`/VA/RVA start route in the scanned executable. Treat `0x00527eb0` as retained private/static `BrowseForDirectoryAndPost` helper code and `0x005283b0` as retained `MiscWorkThread::RequestBrowseDirectory(const char*)`, while the live worker route is `MiscWorkThread::OnMessage`; `ProcessWorkItem` is superseded historical terminology only.
- Notification posting in this source family uses the EventMan/Event.cpp router: both browse producer paths load `ecx` from [UID:00028L][0x0067a754-0x0067a758.g_pEventMan](by-memory/0x0067a754-0x0067a758.g_pEventMan.md) before calling `0x004aa1d0`.
- 2026-06-01 IDA MCP recheck confirms the source-family boundaries and owner evidence: `0x005277c0` size `0x3e6`, `0x00527bb0` size `0x2f4`, `0x00527eb0` size `0x12f`, `0x00527fe0` size `0x1c1`, `0x005281b0` size `0x75`, `0x00528230` size `0x51`, `0x00528290` size `0x74`, `0x00528310` size `0x96`, `0x005283e0` size `0xb`, `0x005283f0` size `0x8f`, `0x00528480` size `0x3b`, `0x005284c0` size `0x5a`, `0x00528520` size `0x38`, and `0x00528560` size `0x7d`.
- 2026-06-01 IDA MCP caller checks confirm `Application::Initialize` calls the constructor at `0x00464715`; the worker override then labeled `ProcessWorkItem` (now source-facing `MiscWorkThread::OnMessage`) calls the HTTP and NCA helpers; the request wrappers are called by patch/download and registration/NCA paths; and `PostNCAStatus` is called only from the NCA helper.
- 2026-06-01 IDA MCP xrefs confirm `g_pMiscWorkThread` lifecycle writes in constructor/destructor/clear/scalar-delete paths and consumers at application cleanup, registration/NCA, and patch download paths. Vtable refs confirm `MiscWorkThread`, `brdir::Notification`, `httpget::Notification`, and `ncauth::Notification` all belong to this source family.
- 2026-06-07 Batch 097 live IDA recheck against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed the function then labeled `ProcessWorkItem` at `0x00527fe0-0x005281a1`, now resolved as `MiscWorkThread::OnMessage`, plus the `0x47654874` (`GeHt`) dispatch to `FetchHTTPContent`, `FetchHTTPContent` at `0x005277c0-0x00527ba6`, the `httpget::Notification` destructor at `0x005284c0-0x0052851a`, the `0x68747470` notification channel, and state-specific payload ownership. This supports retaining [UID:000069][httpget__Notification](by-class/httpget__Notification.md) as a direct child under the strict parent gate.
- 2026-06-14 B002 NCA URL recheck confirmed that [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md) belongs to this file family: `ProcessNCAUpdate` first checks the override string [UID:00029T][0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString](by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md), then decodes the bitwise-not fallback URL at `0x0066de30`, formats account/password arguments, and calls `InternetOpenUrlA`. Registration code reaches the worker through `0x0053015f -> 0x00528310` but has no direct reference to the fallback storage.

## 2026-06-16 A001 File-Confidence Refresh

Live IDA MCP session `b001_mappane_0001AW_20260616` was used to recheck raw-helper reachability, singleton/vtable anchors, source placement, and final-name blockers:

- `lookup_funcs` reconfirmed the file-family method boundaries: HTTP helper `0x005277c0` size `0x3e6`, NCA helper `0x00527bb0` size `0x2f4`, browse helper `0x00527eb0` size `0x12f`, the `MiscWorkThread::OnMessage` override at `0x00527fe0` size `0x1c1` (historical IDA/doc alias `ProcessWorkItem`), constructor/destructor `0x005281b0`/`0x00528230`, request wrappers `0x00528290` size `0x74` and `0x00528310` size `0x96`, clear helper `0x005283e0`, scalar deleting destructor `0x005283f0`, and notification destruct/post helpers through `0x00528560`.
- `xrefs_to` reconfirmed active reachability for the modeled entries: constructor caller `0x00464715`, `MiscWorkThread::OnMessage` vtable/data ref `0x0061fba0`, HTTP request wrapper caller `0x005492aa`, NCA request wrapper caller `0x0053015f`, eight refs to `g_pMiscWorkThread` at `0x0067ab50`, and constructor/destructor/scalar vtable writes to `0x0061fb74`.
- The raw browse-directory request start remains a real blocker: `lookup_funcs 0x005283b0` still reports `Not a function`, `xrefs_to 0x005283b0` returns zero refs, and little-endian VA/RVA pointer byte searches for `b0 83 52 00` and `b0 83 12 00` return no matches. Raw bytes at `0x005283b0` still decode as a coherent wrapper that duplicates the title/path, pushes FourCC `0x42446972`, calls the `Thread` queue helper, and returns with `ret 4`.
- `find_regex` found RTTI strings for `MiscWorkThread` and `Singleton<MiscWorkThread>`, but no embedded `MiscWorkThread.cpp` filename string; `search_structs` found no local IDA UDT for the class. This keeps final notification-class spelling and wrapper names provisional.

These dated checks strengthened `app/MiscWorkThread.cpp` as the file root. Their raw lifecycle-name and no-local-UDT observations are retained as pre-catalog history; catalog0382 subsequently resolved the pointer-safe lifecycle naming/type/comment state without changing the raw-helper classifications or source route.

## 2026-07-31 Catalog0382 Saved IDA Reconciliation

Supervisor catalog entry `0382` applied and read back the UID0004HM IDA handoff in MCP database `f608d7c2`, then saved IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, at `2026-07-31T06:21:13.3464834-04:00`. The prestate backup `NexusTK.exe.pre-B004-UID0004HM-20260731_061621.i64` has SHA256 `5F2679A7C6BFF2CD3E91FE59BDCBD298C1A233EB7988D838C34C05508FC79A21`; it and all earlier raw-name snapshots are dated history.

- The hidden vftable[-1] cell at `0x0061fb70-0x0061fb74` remains unnamed/untyped bytes `e4 c3 64 00`, no direct xrefs, and unchanged fences. Its exact regular address comment identifies it as the pointer to `??_R4MiscWorkThread@@6B@` and explicitly rejects standalone source storage.
- Protected RTTI names, item types, ranges, bytes, xrefs, TypeDescriptors, base array, and vtable remain unchanged. Exact repeatable comments now state COL `{signature=0, offset=0, cdOffset=0, TypeDescriptor=0x00677d28, CHD=0x0064c3f8}`, CHD `{signature=0, attributes=1, four bases at 0x0064c408 in order MiscWorkThread, Thread, LObject, Singleton<MiscWorkThread>}`, and direct Singleton BCD `{TypeDescriptor=0x00677d48, contained bases=0, PMD={0x68,-1,0}, attributes=0x40, hierarchy=0x0064c454}`.
- IDA local type ordinal `964` is now a minimal incomplete pointer-usable `MiscWorkThread` with unknown size and zero members. The complete class layout remains source-owned by UID00008I and is not guessed into IDA.
- `[0x005281b0,0x00528225)` is now `MiscWorkThread_Constructor`, `MiscWorkThread *__thiscall(MiscWorkThread *this)`. Its exact function-repeatable comment records `Thread(100)`, Singleton publication at `+0x68`, primary-vtable installation, and worker start. Its physical frame remains `var_10 +0x8`, `var_C +0xc`, `var_4 +0x14`, saved registers `+0x18`, return `+0x1c`, and raw `arg_4 +0x24`.
- `[0x00528230,0x00528281)` is now `MiscWorkThread_Destructor`, `void __thiscall(MiscWorkThread *this)`. Its exact function-repeatable comment records primary-vtable restore, worker stop, Singleton clear, and Thread teardown. Its physical frame remains `var_C +0x8`, saved registers `+0x14`, return `+0x18`, and raw `arg_4 +0x20`.
- `[0x005283f0,0x0052847f)` is now `MiscWorkThread_ScalarDeletingDestructor`, `MiscWorkThread *__thiscall(MiscWorkThread *this, unsigned int flags)`. Its exact function-repeatable comment records ordinary destruction plus conditional project operator-delete. Nonargument frame entries remain `var_C +0x8`, `var_4 +0x10`, saved registers `+0x14`, and return `+0x18`; automatic prototype presentation is `flags +0x1c/4 unsigned int`.
- Decompiler recompilation succeeded with `MiscWorkThread *this` and `unsigned int flags`. The target/lifecycle byte hashes, calls, vtable/singleton refs, raw/no-route helper states, notification wrappers, EventMan dependency, and every protected boundary were read back unchanged. Thus catalog0382 improves the analysis database and ordinary documentation without changing the chosen human source split or introducing IDA-shaped source code.

## Source-Structure Decision

Use the focused `NexusTK/app/MiscWorkThread.cpp` plus companion `MiscWorkThread.h` source pair. CPP includes its sibling H, then carries the sole global and class-specific Singleton specialization definitions followed by child implementation bodies. Guarded H includes generated-complete `../util/Thread.h` and `../util/Singleton.h`, then owns the one complete class and external singleton declaration.

This is a legal complete-base route: [UID:0000EV][Thread](by-class/Thread.md) emits the guarded complete `Thread.h` declaration through [UID:0000OR][Thread](by-file/Thread.md), while [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md) emits the complete storage-free template through [UID:0004ZK][Singleton](by-file/Singleton.md). An incomplete base, a compact CPP-resident class, an implicit PCH definition, or a feature-local duplicate template is rejected.

Do not merge the worker into [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md): request-submission wrappers at `0x00528290`, `0x00528310`, and raw `0x005283b0` dispatch through `g_pMiscWorkThread` and [UID:0000OR][Thread](by-file/Thread.md), not through a cash-shop object.

Keep [UID:0000JC][FileDownloader](by-file/FileDownloader.md) separate. `MiscWorkThread` performs simple URL reads and notification posts; `FileDownloader` is a dedicated threaded downloader class with its own object lifetime and file-transfer behavior.

The complete source topology is:

- `MiscWorkThread.h`: complete direct `Thread, Singleton<MiscWorkThread>` class, exact `OnMessage(int,int,int)` override, request declarations, and the sole `extern MiscWorkThread* g_pMiscWorkThread`.
- `MiscWorkThread.cpp`: sibling-header include; one zero-initialized global; explicit class-specific Singleton constructor/destructor specializations; worker/message enum and child implementations.
- Source-authored helpers: `FetchHTTPContent`, `ProcessNCAUpdate`, retained private `BrowseForDirectoryAndPost`, and file-local `PostNCAStatus`.
- Source-authored request members: live `RequestHTTPGet`, live `RequestNCAUpdate`, and retained raw/no-route `RequestBrowseDirectory`.
- Compiler products: [UID:0004HM][0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer](by-memory/0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer.md), vtables/COL/CHD/BCD data, the `0x005283e0` constructor-unwind action, the class scalar-deleting wrapper, and the three notification scalar wrappers.
- Dependency-owned call: `EventMan::PostNotification` belongs to class UID00004O and the UID00014C/Event.cpp route. `DecodeNcauthConfirmUserUrl` remains optional human factoring of an inline decode loop, not a discrete binary helper.

Rejected source layouts include a separate RTTI `.cpp`, raw RTTI globals, a CPP-resident duplicate class, absent-header includes, incomplete base declarations, a local Singleton template, generic Singleton static storage, handwritten derived constructor/destructor publication statements, and handwritten scalar-deleting wrappers.

## Open Questions

- Exact original source-path and guard spelling remain unproven, but deterministic reconstruction stays at `NexusTK/app/MiscWorkThread.h/.cpp`; a flatter source pair remains only a historical possibility.
- Request-submission wrapper names are resolved at source-facing descriptive level as `RequestHTTPGet`, `RequestNCAUpdate`, and `RequestBrowseDirectory`.
- The standalone browse processing helper at `0x00527eb0` is not a live public API in the scanned executable. Treat it as a retained private/static helper copy whose behavior is duplicated or inlined in `MiscWorkThread::OnMessage`; the older `MiscWorkThread::ProcessWorkItem` spelling is superseded historical terminology.
- The notification classes are local source-family classes under namespaces `brdir`, `httpget`, and `ncauth`; [UID:000012][brdir__Notification](by-class/brdir__Notification.md) now carries its own first-draft declaration, while the aggregate [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) carries worker/helper behavior.

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md)
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md)
- [UID:0001SN][HttpGetNotificationState](by-type/by-enum/HttpGetNotificationState.md)
- [UID:0001SQ][NcauthNotificationState](by-type/by-enum/NcauthNotificationState.md)
- [UID:00029T][0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString](by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md)
- [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0004ZK][Singleton](by-file/Singleton.md)
- [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md)

## Changes

- 2026-06-07 A004 Batch 097 confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:84`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA rechecked the HTTP-get worker dispatch, producer helper, notification destructor, state enum ownership, and notification channel. Confidence is raised just enough to satisfy the strict direct-parent gate for [UID:000069][httpget__Notification](by-class/httpget__Notification.md); completion remains unchanged because request-wrapper names, exact source path, and notification-class layout spelling remain provisional.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page identifies the worker class, singleton, notification classes, request/message ids, helper families, IDA evidence, ownership decisions, and open questions; confidence remains medium-high because original placement and wrapper names are still provisional.
- 2026-06-01: changed grading from `84/78` to `86/84` and set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`. Evidence: current IDA MCP revalidated the executable boundaries, constructor/application ownership, singleton and vtable refs, request-wrapper consumers, notification helper callees, and proposed-source-tree placement. Confidence remains below near-final because wrapper/helper names and possible private notification-class source layout are still provisional.

- 2026-06-16 A001 Goal2 file-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Summary/evidence: current IDA MCP reconfirmed modeled helper/method boundaries, constructor/request-wrapper reachability, singleton and vtable refs, raw `0x005283b0` no-function/no-xref/no-pointer status, raw wrapper bytes, exact RTTI strings, no embedded source filename, and no local UDT. The remaining blockers are final source path spelling, wrapper/helper names, and notification-class nesting.
- 2026-06-18 B001 source-quality reanalysis:
  - Before: `COMPLETION:87`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:88`.
  - Summary/evidence: B001 resolved request-wrapper names at descriptive source level, classified raw `0x005283b0` as a retained/unreferenced `MiscWorkThread::RequestBrowseDirectory` request wrapper, classified `0x00527eb0` as a retained private/static browse-dialog helper copy, classified `0x00528560` as file-local `PostNCAStatus`, preserved `NexusTK/app/MiscWorkThread.cpp` as the best source route, and confirmed first-draft C++ can live in [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md).
- 2026-06-21 Rule 26 incorporation of B011 brdir notification source-quality report:
  - Score unchanged at `88/88`.
  - Summary/evidence: added the brdir-specific source-quality resolution: [UID:000012][brdir__Notification](by-class/brdir__Notification.md) is a source-bearing local payload class under this file, not no-code glue; browse helper `0x00527eb0` and request wrapper `0x005283b0` remain retained/no-route source-shaped code; the live `BDir` branch in what that dated pass called `ProcessWorkItem` (now `MiscWorkThread::OnMessage`) constructs/posts the same object; notification posting uses the EventMan router path through `g_pEventMan`/`0x004aa1d0`; and the class declaration now emits from [UID:000012][brdir__Notification](by-class/brdir__Notification.md) while [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) keeps worker/helper behavior.
- 2026-07-01 B008 empty-emitter family implementation:
  - Changed from `COMPLETION:88`, `CONFIDENCE:88`.
  - Changed to `COMPLETION:89`, `CONFIDENCE:90`.
  - Summary/evidence: B008 incorporated the generated-output audit baseline (`MiscWorkThread.cpp` command `000000003842`, refreshed `2026-07-01T15:24:09-04:00`, `12/2/10/16.7%`), documented the declaration/data/body split across the ten formerly empty emitters and [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md), preserved rejected-owner analysis, and tied source declarations/data to the dedicated pages to avoid broad duplicate method/class bodies in the aggregate.
- 2026-07-31 B004 UID0004HM implementation:
  - Changed score from `89/90` to `91/93`; path remains `NexusTK/app/`.
  - Replaced the compact CPP-only declaration topology with a legal `MiscWorkThread.h/.cpp` pair backed by real [UID:0000OR][Thread](by-file/Thread.md) and [UID:0004ZK][Singleton](by-file/Singleton.md) source roots.
  - Added direct Singleton inheritance, EBO/PMD lifetime lowering, sole-global and class-specific specialization placement, UID0004HM compiler-product ownership, exact `OnMessage` override naming, and itemized source-helper/request/compiler-wrapper/dependency ownership without pruning notification, NCA URL, raw-helper, consumer, or historical evidence.
  - Rejected raw RTTI source, CPP-resident duplicate class, incomplete/PCH-only bases, local duplicate template, generic static storage, handwritten singleton assignments, and scalar-wrapper source.
- 2026-07-31 supervisor catalog0382 saved-state reconciliation:
  - Applied and verified the exact RTTI comments, minimal incomplete IDA class type, and constructor/destructor/scalar-wrapper names, prototypes, frames, and function-repeatable comments listed above; saved IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`.
  - The older `sub_*`, no-local-UDT, and pre-save `5F2679...79A21` observations remain explicit superseded history. Source placement, helper classifications, formal CPP/H topology, and runtime behavior are unchanged.
