*** UID:00008I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MiscWorkThread.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_APP_MISCWORKTHREAD_H
#define NEXUSTK_APP_MISCWORKTHREAD_H

#include "../util/Thread.h"
#include "../util/Singleton.h"

class MiscWorkThread;
extern MiscWorkThread* g_pMiscWorkThread;

class MiscWorkThread : public Thread,
                       public Singleton<MiscWorkThread>
{
public:
    MiscWorkThread();
    virtual ~MiscWorkThread();

    virtual void OnMessage(int messageId, int payloadValue, int aux);

    void RequestHTTPGet(const wchar_t* url);
    void RequestNCAUpdate(const wchar_t* account, const wchar_t* password);
    void RequestBrowseDirectory(const char* title);
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MiscWorkThread

## Status

- Confidence: strong for class ownership, worker messages, singleton/vtable evidence, request-wrapper reachability, and notification flow; medium-high for original module placement and final helper names.
- Current generated file: `source-3/simroot_v2/class_MiscWorkThread.cpp`
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Direct bases: [UID:0000EV][Thread](by-class/Thread.md) and reusable empty `Singleton<MiscWorkThread>`; `Thread` contributes inherited [UID:00007D][LObject](by-class/LObject.md).
- Current relevant range: `0x005277c0-0x005285dd`
- Evidence basis: `simroot_v2` generated source, IDA MCP lookup/decompile/xref checks, and B011 2026-06-19 raw PE reanalysis for the browse-directory notification path.

## Responsibility

`MiscWorkThread` is a singleton background worker for miscellaneous application tasks. It receives [UID:0000EV][Thread](by-class/Thread.md) queue messages, owns each request payload, performs the requested shell or WinInet operation, and posts a typed notification object back through the EventMan/application notification path.

## Key Data

- Singleton global: [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) at [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md).
- Vtable: `??_7MiscWorkThread@@6B@` at `0x0061fb74`.
- RTTI references include `MiscWorkThread` and `Singleton<MiscWorkThread>`.
- Object size in current construction path: `0x68` bytes.
- Worker base construction: `Thread::Thread(this, 100)`.
- Direct Singleton BCD PMD: `{0x68,-1,0}`. The empty base occupies the complete-object boundary without adding a source data member.

## Important Methods

| Address | Source-facing name | Notes |
| --- | --- | --- |
| `0x00527fe0` | `OnMessage` | Exact override of `Thread::OnMessage(int,int,int)`: handles browse-directory, HTTP get, NCA update, and falls back to the same base virtual. Historical `ProcessWorkItem` is a superseded descriptive alias. The live `BDir` case constructs/posts [UID:000012][brdir__Notification](by-class/brdir__Notification.md) and frees the queued ANSI title payload. |
| `0x005281b0` | `MiscWorkThread` | Current IDA name `MiscWorkThread_Constructor`; constructs `Thread(100)`, implicitly constructs the direct empty Singleton base whose class-specific specialization publishes the complete object, installs the vtable, and starts the worker. Publication is compiler/template lowering, not a handwritten derived-body assignment. |
| `0x00528230` | `~MiscWorkThread` | Current IDA name `MiscWorkThread_Destructor`; stops the worker in the derived body, then implicitly destroys the direct Singleton base whose specialization clears the external pointer before `Thread` teardown. |
| `0x00528290` | `RequestHTTPGet` | Allocates one `SimpleUString` payload and dispatches message `0x47654874`; live caller is the PatchPane2 download path. |
| `0x00528310` | `RequestNCAUpdate` | Allocates two adjacent `SimpleUString` payloads and dispatches message `0x4e434175`; live caller is the registration/NCA path. |
| `0x005283b0` | `RequestBrowseDirectory` | Raw aligned retained/unreferenced request wrapper; duplicates an ANSI title/path, dispatches message `0x42446972`, has no direct `call`/`jmp`/VA/RVA start reference in the scanned executable, and should not be treated as a live public API. |
| `0x005283e0` | constructor-unwind action | Compiler-retained 11-byte EH action generated from the explicit `Singleton<MiscWorkThread>` destructor specialization; it is not a second handwritten clear helper. |
| `0x005283f0` | scalar deleting destructor | Current IDA name `MiscWorkThread_ScalarDeletingDestructor`; compiler wrapper regenerated by the ordinary virtual destructor. It performs destruction and optional project operator-delete according to scalar-delete flags, but receives no standalone source body. |

## Catalog0382 Saved IDA Reconciliation

Supervisor catalog entry `0382` applied the accepted class/RTTI/lifecycle handoff in MCP database `f608d7c2`, verified it after save, and persisted IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, at `2026-07-31T06:21:13.3464834-04:00`. The byte-identical prestate backup `NexusTK.exe.pre-B004-UID0004HM-20260731_061621.i64` retains SHA256 `5F2679A7C6BFF2CD3E91FE59BDCBD298C1A233EB7988D838C34C05508FC79A21`; all earlier raw-name/type observations are preserved as dated prestate history.

- IDA local type ordinal `964` is the deliberately minimal incomplete `MiscWorkThread`: pointer-usable, unknown size, zero members, and no inferred physical layout. The complete human source declaration remains the guarded H block above; the incomplete IDA type exists only for evidence-backed function signatures.
- The primary vftable[-1] cell at `0x0061fb70` remains unnamed/untyped compiler storage with exact bytes `e4 c3 64 00`, no direct xrefs, unchanged boundaries, regular comment `MiscWorkThread primary vftable[-1] slot: pointer to ??_R4MiscWorkThread@@6B@, the MSVC complete-object locator for the complete object; compiler-generated from the class hierarchy, not standalone source storage.`, and absent repeatable address comment.
- The protected COL, CHD, and direct Singleton BCD retain their decorated names/types/bytes/xrefs. Their exact repeatable comments now record, respectively: `MiscWorkThread primary complete-object locator: signature=0, vftable offset=0, cdOffset=0, TypeDescriptor=0x00677d28, ClassHierarchyDescriptor=0x0064c3f8.`, `MiscWorkThread class hierarchy descriptor: signature=0, attributes=1, four bases at 0x0064c408 in order MiscWorkThread, Thread, LObject, Singleton<MiscWorkThread>.`, and `Direct empty Singleton<MiscWorkThread> base descriptor: TypeDescriptor=0x00677d48, contained bases=0, PMD={0x68,-1,0}, attributes=0x40, hierarchy=0x0064c454.`
- `[0x005281b0,0x00528225)` is `MiscWorkThread_Constructor` with exact IDA prototype `MiscWorkThread *__thiscall(MiscWorkThread *this)` and function-repeatable comment `MiscWorkThread constructor. Constructs Thread(100), runs the direct empty Singleton<MiscWorkThread> base publication lowering at +0x68, installs the primary vftable, and starts the worker.` Physical frame readback remains `var_10 +0x8`, `var_C +0xc`, `var_4 +0x14`, saved registers `+0x18`, return address `+0x1c`, and raw `arg_4 +0x24`.
- `[0x00528230,0x00528281)` is `MiscWorkThread_Destructor` with exact IDA prototype `void __thiscall(MiscWorkThread *this)` and function-repeatable comment `MiscWorkThread ordinary destructor. Restores the primary vftable, stops the worker, runs Singleton<MiscWorkThread> teardown lowering that clears g_pMiscWorkThread, then destroys Thread.` Physical frame readback remains `var_C +0x8`, saved registers `+0x14`, return address `+0x18`, and raw `arg_4 +0x20`.
- `[0x005283f0,0x0052847f)` is `MiscWorkThread_ScalarDeletingDestructor` with exact IDA prototype `MiscWorkThread *__thiscall(MiscWorkThread *this, unsigned int flags)` and function-repeatable comment `MiscWorkThread scalar deleting destructor. Performs ordinary destruction, then conditionally calls the project operator-delete wrapper according to scalar-delete flags.` Nonargument frame entries remain `var_C +0x8`, `var_4 +0x10`, saved registers `+0x14`, and return address `+0x18`; automatic prototype-driven presentation is `flags +0x1c/4 unsigned int`.
- Decompiler recompilation succeeded with `MiscWorkThread *this` and `unsigned int flags`. Target/lifecycle bytes, callers, vtable stores, singleton xrefs, helper-family names/types/comments, source behavior, and every protected RTTI/vtable boundary remained unchanged.

## Worker Messages

See [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md).

| Value | FourCC | Request payload | Posted notification |
| --- | --- | --- | --- |
| `0x42446972` | `BDir` | Heap ANSI title string | [UID:000012][brdir__Notification](by-class/brdir__Notification.md) |
| `0x47654874` | `GeHt` | One heap `SimpleUString` URL | [UID:000069][httpget__Notification](by-class/httpget__Notification.md) |
| `0x4e434175` | `NCAu` | Two adjacent heap `SimpleUString` values | [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md) |

## Ownership Notes

- `0x00528290`, `0x00528310`, and raw `0x005283b0` are not [UID:00001H][CashShopRequest](by-class/CashShopRequest.md) methods. They dispatch through `this` as a [UID:0000EV][Thread](by-class/Thread.md)-derived `MiscWorkThread`, and known callers obtain the object from [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md).
- RTTI proves four descriptors in order: `MiscWorkThread`, direct `Thread`, inherited `LObject`, and direct empty `Singleton<MiscWorkThread>`. The Singleton PMD `+0x68`, exact 0x68 allocation, constructor adjustment/publication order, and reverse destructor order reject member-field, generic-static, and unrelated-template interpretations.
- [UID:0004HM][0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer](by-memory/0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer.md) is the compiler-generated primary vftable[-1] COL pointer produced by this class declaration; it is not a separate handwritten RTTI source object.
- The worker owns request payload cleanup. The main thread owns notification consumption after `PostNotification`.
- Browse-directory notifications are posted through the EventMan/Event.cpp router at `0x004aa1d0` with `ecx` loaded from [UID:00028L][0x0067a754-0x0067a758.g_pEventMan](by-memory/0x0067a754-0x0067a758.g_pEventMan.md), not through an Application-owned method, although `g_pApplication` still supplies the owner window handle for `BROWSEINFOA`.
- The base queue helpers at `0x00596960` and nearby belong to [UID:0000EV][Thread](by-class/Thread.md), not this class.
- 2026-06-01 IDA MCP confirms the class method starts and owner evidence: `ProcessWorkItem` at `0x00527fe0` size `0x1c1`, constructor at `0x005281b0` size `0x75`, destructor at `0x00528230` size `0x51`, request wrappers at `0x00528290` and `0x00528310`, raw browse-directory request wrapper bytes at `0x005283b0`, singleton clear helper at `0x005283e0`, and scalar deleting destructor at `0x005283f0`.
- Current xrefs to `0x0061fb74` show the `MiscWorkThread` vtable installed by constructor/destructor/scalar-delete paths, and xrefs to `0x0067ab50` show singleton writes plus application/feature consumers.
- 2026-06-11 A005 Batch 174 live IDA MCP recheck reconfirmed the worker message surface used by [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md): `ProcessWorkItem` switches on `1111779698`, `1197820020`, and `1313030517`; `0x00528290` submits `1197820020` through `Thread` queue helper `0x00596960`; `0x00528310` submits `1313030517`; raw/no-function bytes at `0x005283b0` duplicate an ANSI title with `__strdup`, push `0x42446972`, and call `0x00596960`.
- 2026-06-19 B011 raw PE reanalysis strengthens the browse-directory branch: the live `BDir` case and retained helper both allocate `0x108`, call `LObject` construction, store `brdir::Notification` vtable `0x0061fbb0`, call `SHGetPathFromIDListA` into object `+4`, write `m_path[0] = 0` only on cancel/failure, and post `0x42446972`. The raw request wrapper at `0x005283b0` duplicates the title via `0x005deb99` and queues the same id through `0x00596960`.

## 2026-06-16 Evidence Refresh

Live IDA MCP was used to recheck active reachability, singleton/vtable ownership, raw-helper status, and final-name blockers:

- `lookup_funcs` confirms `FetchHTTPContent`-family helper `0x005277c0` size `0x3e6`, NCA helper `0x00527bb0` size `0x2f4`, browse helper `0x00527eb0` size `0x12f`, `ProcessWorkItem` `0x00527fe0` size `0x1c1`, constructor/destructor `0x005281b0`/`0x00528230`, modeled request wrappers `0x00528290`/`0x00528310`, clear helper `0x005283e0`, scalar deleting destructor `0x005283f0`, and notification helpers through `0x00528560`.
- `lookup_funcs 0x005283b0` still reports `Not a function`, and `xrefs_to 0x005283b0` reports zero refs. The raw browse-directory request bytes remain documented as a real wrapper body but are not safe to promote to a modeled class method.
- Active reachability is concrete for the modeled class entries: constructor has the application startup caller at `0x00464715`; `ProcessWorkItem` is vtable/data referenced at `0x0061fba0`; HTTP and NCA request wrappers have one caller each at `0x005492aa` and `0x0053015f`; scalar deleting destructor is the primary vtable slot at `0x0061fb74`.
- `xrefs_to 0x0067ab50` returns eight singleton refs, including application cleanup, constructor writes, destructor/clear/scalar-delete clears, and the HTTP/NCA request consumers. `xrefs_to 0x0061fb74` returns constructor/destructor/scalar-delete vtable writes at `0x00528208`, `0x00528255`, and `0x0052841c`.
- `callees` confirms `ProcessWorkItem` fanout to HTTP/NCA helpers, browse-dialog APIs (`CoInitialize`, `SHBrowseForFolderA`, `SHGetPathFromIDListA`, `CoUninitialize`), notification/application posting helpers, cleanup/free, and base `Thread` fallback; request wrappers allocate/copy strings and dispatch through `Thread` queue helper `0x00596960`.

These checks resolve the low-confidence reachability question for the modeled request producers and class lifetime. The current source-facing names are `OnMessage`, `RequestHTTPGet`, `RequestNCAUpdate`, and `RequestBrowseDirectory`; the exact Thread vtable slot and default call correct historical `ProcessWorkItem` wording. `0x005283b0` is retained/unreferenced request-wrapper code rather than `CashShopRequest` ownership. Remaining limitations are original textual spellings, exact historical path/guard spelling, and final build reproduction.

## Parent Gate

The class and file parent both clear the active parent/emitter gate. Current source-facing names are `OnMessage`, `RequestHTTPGet`, `RequestNCAUpdate`, and `RequestBrowseDirectory`; the raw `0x005283b0` helper is retained/unreferenced request-wrapper code, not `CashShopRequest` ownership. Formal implementation is supplied by [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md), with normal source constructors/destructors standing in for scalar deleting destructor and EH-unwind compiler output.

## Formal Source Declaration

The formal source is split into a normal sibling header and implementation stream. CPP contains only `#include "MiscWorkThread.h"` followed by `[[CHILDREN]]`. Guarded H includes the complete emitted `../util/Thread.h` and `../util/Singleton.h` dependencies, owns the one external singleton declaration, and defines `MiscWorkThread : public Thread, public Singleton<MiscWorkThread>` with the exact `OnMessage(int,int,int)` override and request surface. [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) remains the worker/helper body island.

The complete-base includes are required C++ rather than optional PCH assumptions: an incomplete `Thread` or `Singleton<T>` cannot be used as a base. The header rejects a local duplicate Singleton template, an incomplete-base forward declaration, a CPP-resident second class definition, and a second `g_pMiscWorkThread` declaration owner. The normalized guard `NEXUSTK_APP_MISCWORKTHREAD_H` follows the project path/stem convention; exact historical macro spelling remains inferred.

## Cross-References

- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md)
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- [UID:0004HM][0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer](by-memory/0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer.md)
- [UID:0004ZK][Singleton](by-file/Singleton.md)
- [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md)
- [UID:0000EV][Thread](by-class/Thread.md)
- [UID:00000D][Application](by-class/Application.md)
- [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md)

## Changes

- 2026-06-16 A002 Goal2 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:87`; owner and emitter remain [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
  - Evidence: live IDA MCP reconfirmed function boundaries, application constructor caller, vtable-backed `ProcessWorkItem`, request-wrapper callers, singleton/vtable refs, request-wrapper callees through the `Thread` queue helper, and raw browse-directory `0x005283b0` no-function/no-xref status. Final C++ remains blank because raw wrapper promotion, exact wrapper names, notification layout spelling, and source-path placement are not source-final.
- 2026-06-18 B001 source-quality reanalysis:
  - Before: `COMPLETION:86`, `CONFIDENCE:87`.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`; owner/emitter remain [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
  - Evidence: B001 resolved source-facing wrapper names, rechecked direct PE `call`/`jmp`/VA/RVA references, confirmed live `RequestHTTPGet` and `RequestNCAUpdate` callers, confirmed raw `0x005283b0` as retained/unreferenced `RequestBrowseDirectory`, preserved `0x00528560` as a file-local `PostNCAStatus` helper rather than a class member, and moved formal C++ responsibility to [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md).
- 2026-06-21 Rule 26 incorporation of B011 brdir notification source-quality report:
  - Score unchanged at `88/89`.
  - Evidence: documented the live BDir branch as the confirmed [UID:000012][brdir__Notification](by-class/brdir__Notification.md) producer, kept raw `0x00527eb0`/`0x005283b0` as retained no-route helper/wrapper code, corrected the post path to EventMan-owned router wording, and recorded the no-constructor-zeroing source policy for the browse payload.
- 2026-06-11 A005 Batch 174 enum parent-gate refresh:
  - Changed from: `COMPLETION:84`, `CONFIDENCE:82`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`.
  - Evidence: live IDA MCP rechecked the `ProcessWorkItem` switch, HTTP/NCA modeled request producers, raw browse-directory producer, `Thread` queue helper use, and fallback. This clears the direct-parent gate for [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md) while preserving final-source caveats.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) because this class is 84/82 and the parent file is 86/84. Live IDA MCP on `NexusTK.exe` confirmed worker, constructor, destructor, request-wrapper, singleton-clear, and scalar-deleting starts at `0x00527fe0`, `0x005281b0`, `0x00528230`, `0x00528290`, `0x00528310`, `0x005283e0`, and `0x005283f0`; `0x005283b0` remains raw aligned code rather than an IDA function start and is not used as attachment proof.
- Before: the current relevant range was listed as `0x005277c0-0x005285dc`.
- Changed to: the range is `0x005277c0-0x005285dd`.
- Summary/evidence: 2026-05-28 IDA MCP shows the `PostNCAStatus` helper's final `retn` byte is at `0x005285dc`; the next padding starts at `0x005285dd`.
- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: the singleton worker thread has detailed responsibility, singleton/vtable/RTTI data, method map, worker-message IDs, notification classes, ownership caveats, and IDA evidence, but final original module placement and some request helper names remain medium confidence. Evidence: linked `MiscWorkThreadAndNotifications` range, `g_pMiscWorkThread`, `MiscWorkThreadMessageId`, Thread base construction, IDA lookup/decompile/xref checks, and payload cleanup/notification ownership notes.
- 2026-06-01: changed grading from `82/78` to `84/82`. Evidence: fresh IDA MCP lookup/caller/xref checks confirm constructor/application ownership, vtable and singleton lifecycle, request-wrapper consumers, and `Thread` queue dispatch. Confidence remains below very high because final request helper names and notification class source layout are still open.
- 2026-07-01 B008 empty-emitter family implementation:
  - Changed from `COMPLETION:88`, `CONFIDENCE:89`, blank formal C++, and blank emitter position.
  - Changed to `COMPLETION:90`, `CONFIDENCE:91`, `EMITTER_POSITION_OPTIONAL:1`, and a formal source-level class declaration with `[[CHILDREN]]`.
  - Summary/evidence: B008 rechecked current generated `MiscWorkThread.cpp` command `000000003842`, live IDA MCP function boundaries, `g_pMiscWorkThread` xrefs, vtable refs, request-wrapper callees, and the existing B001/B011 source-quality reports. The class declaration is now source-bearing, while [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) remains the sole emitter for method/helper bodies to avoid duplicate broad class bodies.
- 2026-07-31 B004 UID0004HM implementation:
  - Changed score from `90/91` to `92/94`; owner/emitter remain [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
  - Replaced the compact CPP-resident class shell with a legal `MiscWorkThread.h`/`.cpp` split: self-include and child stream in CPP, complete guarded H with generated-complete Thread/Singleton includes, direct empty Singleton base, one extern declaration, exact `OnMessage` override, and request declarations.
  - Incorporated the complete RTTI hierarchy, Singleton PMD `+0x68`, exact 0x68 object size, class-specific publication/clear lowering, UID0004HM compiler-product ownership, corrected constructor/destructor/compiler-wrapper source shape, and rejection of incomplete-base, local-template, PCH-only, generic-static, and handwritten RTTI alternatives.
  - Historical correction: `ProcessWorkItem` remains useful as an older descriptive name, but the exact vtable/default-callee relationship proves the source override is `Thread::OnMessage(int,int,int)`.
- 2026-07-31 supervisor catalog0382 saved-state reconciliation:
  - Applied and verified the minimal pointer-safe IDA type, exact RTTI comments, and exact constructor/destructor/scalar-wrapper names, prototypes, frames, and function-repeatable comments documented above; persisted IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277` without changing bytes or source behavior.
  - Earlier raw-name and no-local-type observations remain as superseded history rather than current IDA state.
