** TARGET-REPORT-UID:0001CJ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001CJ MiscWorkThreadAndNotifications Source-Quality Research

Assignment: `B001-goal2-misc-work-thread-notifications-source-quality-0001CJ-20260618`  
Agent: `Agent-B001`  
Primary target: [UID:0001CJ] `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`  
Required report path: `tools/leaser/Agents/Agent-B001/research/0001CJ-MiscWorkThreadAndNotifications-source-quality.md`

This is report-only research. No `by-*` docs, generated reports, generated source, IDA database, or `by-memory/-coverage-report.md` files were edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001CJ] as a reconstructable `MiscWorkThread.cpp` source island owned and emitted by [UID:0000LG] `MiscWorkThread`.
- Recommended target metadata: raise [UID:0001CJ] from `COMPLETION:84` / `CONFIDENCE:88` to `COMPLETION:87` / `CONFIDENCE:90`.
- Owner/emitter: keep `CANONICAL_OWNER:0000LG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LG`, and blank `EMITTER_POSITION_OPTIONAL`.
- Source placement: keep `NexusTK/app/MiscWorkThread.cpp`. A flatter `MiscWorkThread.cpp` or `network/MiscWorkThread.cpp` remains possible as an original-build spelling, but current source-tree routing under `app/` is the best reconstruction target because the module is application-owned, constructed by `Application`, and multiplexes folder browsing, HTTP fetch, and NCA auth/update work rather than being a pure network transport.
- Formal C++: populate the target's `RECONSTRUCTION_CPP CODE` block with the first-draft C++ below. This target clears the active code-entry gate, has a valid emitter route, and the remaining names are descriptive rather than blocking.
- Coverage: replace the stale [UID:0001CJ] `by-memory/-coverage-report.md` row with the row in `## Coverage Report Replacement Text`.

Resolved source-quality decisions:

- `0x005277c0`: source-facing name `FetchHTTPContent`, file-local worker helper taking a wide URL and posting `httpget::Notification` states.
- `0x00527bb0`: source-facing name `ProcessNCAUpdate`, file-local worker helper taking two `SimpleUString`/wide-string credential values and posting `ncauth::Notification` states.
- `0x00527eb0`: source-facing name `BrowseForDirectoryAndPost` or `PostBrowseDirectoryNotification`, a file-local browse-dialog helper. It has no static callers in the current executable and is best treated as a retained out-of-line/private helper copy whose body is duplicated or inlined in `ProcessWorkItem`, not a live public API.
- `0x00527fe0`: source-facing name `MiscWorkThread::ProcessWorkItem`. It is the `Thread` message-handler override for `BDir`, `GeHt`, and `NCAu` work items. If the final `Thread` interface later proves the original virtual name was `OnMessage`, keep `ProcessWorkItem` as the documentation alias and map it to that virtual.
- `0x00528290`: source-facing name `MiscWorkThread::RequestHTTPGet`.
- `0x00528310`: source-facing name `MiscWorkThread::RequestNCAUpdate`.
- `0x005283b0`: source-facing name `MiscWorkThread::RequestBrowseDirectory`. It is a source-shaped `thiscall` request wrapper that queues `0x42446972`, but direct PE scan finds no call, jump, VA pointer, or RVA pointer to the start. Treat it as retained/unreferenced helper code, not as an observed live public API.
- `0x00528560`: source-facing name `PostNCAStatus`, a file-local free helper in `MiscWorkThread.cpp`. It should not be modeled as a `MiscWorkThread` member because it has no `this`, and it should not be forced into `ncauth::Notification` as a static method because all evidence points to a local construction/post helper used only by `ProcessNCAUpdate`.

## Evidence Checked

Required guidance:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B001/goal.md`
- `project-documentation/by-structure.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`

Primary and support docs:

- [UID:0001CJ] `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`
- [UID:0000LG] `by-file/MiscWorkThread.md`
- [UID:00008I] `by-class/MiscWorkThread.md`
- [UID:0000EV] `by-class/Thread.md`
- [UID:0001JX] `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
- [UID:000012] `by-class/brdir__Notification.md`
- [UID:000069] `by-class/httpget__Notification.md`
- [UID:00008X] `by-class/ncauth__Notification.md`
- [UID:0001SP] `by-type/by-enum/MiscWorkThreadMessageId.md`
- [UID:0001SN] `by-type/by-enum/HttpGetNotificationState.md`
- [UID:0001SQ] `by-type/by-enum/NcauthNotificationState.md`
- [UID:0000RQ] `by-global/g_pMiscWorkThread.md`
- [UID:0001P8] `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md`
- [UID:0001CK] `by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md`
- [UID:0001CU] `by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md`
- [UID:0001EV] `by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md`
- [UID:0003MG] `by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md`
- [UID:00025X] `by-memory/0x0061fb74-0x0061fc04.WorkThreadNotificationReadOnlyData.md`
- [UID:0003C6] `by-memory/0x0061fbac-0x0061fbdc.WorkThreadNotificationVtableData.md`
- [UID:00027S] B002 executed report `00027S-NcauthConfirmUserUrlObfuscated-advanced-scan.md`
- [UID:0001EW]/[UID:0001EY]/[UID:0001EZ] B003 executed report `0001EW-0001EY-0001EZ-patchpane2-helper-source-quality.md`

Local exported function JSON:

- `0x005277c0`, `0x00527bb0`, `0x00527eb0`, `0x00527fe0`, `0x005281b0`, `0x00528230`, `0x00528290`, `0x00528310`, `0x005283b0`, `0x005283e0`, `0x005283f0`, `0x00528480`, `0x005284c0`, `0x00528520`, `0x00528560`, `0x00596960`, and `0x004aa1d0`.

Direct byte/PE evidence:

- Live IDA MCP was attempted with `tools/list` against `http://127.0.0.1:13337/mcp`, but the endpoint was unavailable (`Unable to connect to the remote server`).
- Because live MCP was unavailable, this pass used existing IDA/Ghidra exported data, prior live-ID-backed by-docs, and direct read-only PE scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- PE scan baseline: image base `0x00400000`; `.text` raw pointer `0x400`, raw size `0x20b600`; `.rdata` raw pointer `0x20ba00`, raw size `0x5f200`; `.data` raw pointer `0x26ac00`, raw size `0xd800`.
- Direct scan checked `E8 rel32` calls, `E9 rel32` jumps, little-endian VA constants, and little-endian RVA constants for every material target start.

Numeric conversion:

- `int_convert.py` was run for `0x42446972`, `0x47654874`, `0x4e434175`, `0x4e634175`, and `0x68747470`.
- Verified decimal values: `0x42446972 == 1111779698`, `0x47654874 == 1197820020`, `0x4e434175 == 1313030517`, `0x4e634175 == 1315127669`, and `0x68747470 == 1752462448`.

## Function And Source-Shape Inventory

| Address / range | Best source-facing name | Direct evidence | Source-shape decision |
| --- | --- | --- | --- |
| `0x005277c0-0x00527ba6` | `FetchHTTPContent` | One call from `0x00528074` inside `ProcessWorkItem`; WinInet `InternetOpenA("Baram")`, `InternetOpenUrlA`, `InternetReadFile`, channel `0x68747470`. | File-local worker helper in `MiscWorkThread.cpp`. |
| `0x00527bb0-0x00527ea4` | `ProcessNCAUpdate` | One call from `0x0052803f`; direct refs to NCA URL override/fallback data; calls `PostNCAStatus` at `0x00527e0d` and `0x00527e86`. | File-local worker helper in `MiscWorkThread.cpp`. |
| `0x00527eb0-0x00527fdf` | `BrowseForDirectoryAndPost` | No direct calls/jumps/pointers; `SHBrowseForFolderA`, `brdir::Notification`, channel `0x42446972`. | Retained private/static helper copy, not proven live public API. |
| `0x00527fe0-0x005281a1` | `MiscWorkThread::ProcessWorkItem` | Vtable/data VA pointer at `0x0061fba0`; dispatches `0x42446972`, `0x47654874`, `0x4e434175`; owns request-payload cleanup. | Main `Thread` message-handler override. |
| `0x005281b0-0x00528225` | `MiscWorkThread::MiscWorkThread` | Direct call from `Application::Initialize` at `0x00464715`; calls `Thread::Thread(this, 100)`, stores `g_pMiscWorkThread`, installs vtable, starts worker. | Normal constructor. |
| `0x00528230-0x00528281` | `MiscWorkThread::~MiscWorkThread` | Stops worker, clears singleton, destroys `Thread` base. | Normal destructor; scalar deleting wrapper is compiler output. |
| `0x00528290-0x00528304` | `MiscWorkThread::RequestHTTPGet` | Direct call from PatchPane2 download path `0x005492aa`; allocates one `SimpleUString`; queues `0x47654874`. | Live request wrapper method. |
| `0x00528310-0x005283a6` | `MiscWorkThread::RequestNCAUpdate` | Direct call from registration path `0x0053015f`; allocates two adjacent `SimpleUString` objects; queues `0x4e434175`. | Live request wrapper method. |
| `0x005283b0-0x005283d5` | `MiscWorkThread::RequestBrowseDirectory` | No direct calls/jumps/pointers; raw bytes call `strdup`, push `0x42446972`, call `Thread` queue helper `0x00596960`, `ret 4`. | Retained/unreferenced request wrapper method or private helper; source-authored but not proven live. |
| `0x005283e0-0x005283eb` | constructor-unwind singleton clear | Direct PE scan finds jump from `0x006042ef`; body only clears `g_pMiscWorkThread`. | Compiler/EH cleanup helper; source expressed by constructor/destructor lifetime. |
| `0x005283f0-0x0052847f` | `MiscWorkThread` scalar deleting destructor | Vtable pointer at `0x0061fb74`; stops worker, clears singleton, destroys base, optional delete. | Compiler deleting destructor generated from source destructor. |
| `0x00528480-0x005284bb` | `brdir::Notification::~Notification` | Vtable pointer at `0x0061fbb0`; calls `LObject` cleanup, optional delete. | Source virtual destructor. |
| `0x005284c0-0x0052851a` | `httpget::Notification::~Notification` | Vtable pointer at `0x0061fbc0`; deletes payload for states `1` and `4`, then base cleanup. | Source virtual destructor with state-owned payload release. |
| `0x00528520-0x00528558` | `ncauth::Notification::~Notification` | Vtable pointer at `0x0061fbd0`; base cleanup and optional delete. | Source virtual destructor. |
| `0x00528560-0x005285dd` | `PostNCAStatus` | Direct calls at `0x00527e0d` and `0x00527e86`; allocates 8-byte `ncauth::Notification`, writes state at `+4`, posts channel `0x4e634175`. | File-local free helper, not a class member. |
| `0x00596960` | `Thread::DispatchRequest` / async post helper | 22 direct calls; wrappers call it at `0x005282ed`, `0x0052838e`, raw `0x005283cb`; writes six-dword queue record and releases semaphore. | Dependency owned by [UID:0000EV]/[UID:0000OR], not MiscWorkThread. |
| `0x004aa1d0` | application notification post helper | 12 callers; worker notifications use it for `http`, `BDir`, and `NCAu`. | Shared application notification helper; dependency only. |

## Raw Helper And Reachability Reanalysis

Direct PE scan findings:

| Target | Direct call hit | Direct jump hit | VA pointer hit | RVA pointer hit | Decision |
| --- | --- | --- | --- | --- | --- |
| `0x00527eb0` | none | none | none | none | Out-of-line browse-dialog helper is not statically reached in the current executable. |
| `0x005283b0` | none | none | none | none | RequestBrowseDirectory wrapper is source-shaped but unreferenced. |
| `0x00528560` | `0x00527e0d`, `0x00527e86` | none | none | none | Live local helper called only by `ProcessNCAUpdate`. |
| `0x00528290` | `0x005492aa` | none | none | none | Live HTTP request wrapper called by PatchPane2. |
| `0x00528310` | `0x0053015f` | none | none | none | Live NCA request wrapper called by registration dialog. |
| `0x00527fe0` | none | none | `0x0061fba0` | none | Vtable/data-reached worker message handler. |

`0x005283b0` raw bytes:

```text
55 8b ec 56 6a 00 ff 75 08 8b f1 e8 d9 67 0b 00
83 c4 04 8b ce 50 68 72 69 44 42 e8 90 e5 06 00
5e 5d c2 04 00
```

This decodes as:

- `this` is preserved in `esi`.
- The stack argument is passed to the strdup-style helper at `0x005deb99`.
- The duplicated ANSI string is queued through `0x00596960(this, 0x42446972, duplicatedTitle, 0)`.
- The function returns with `ret 4`.

Decision for `0x005283b0`:

- It is not a live public helper by observed static references.
- It is not an unrelated duplicate range because the body is exactly paired with the live `RequestHTTPGet` and `RequestNCAUpdate` request wrappers and uses the same `Thread` async helper.
- It is not `CashShopRequest`; the generated `CashShopRequest *` type is false generated pollution, rejected by `g_pMiscWorkThread` callers and the `Thread` base queue helper.
- Best source-facing interpretation: `MiscWorkThread::RequestBrowseDirectory(const char* title)`, a source-authored request wrapper retained in the binary despite no known direct caller. Mark its live status as "unreferenced retained helper" rather than "dead unknown code".

Decision for `0x00527eb0`:

- It is a file-local browse-dialog/post helper with the same shell/notification logic as the `BDir` branch in `ProcessWorkItem`.
- The current executable has no static reference to the helper start.
- Best source-shape inference: a private helper such as `BrowseForDirectoryAndPost(const char* title)` was available in the source, and the message-handler branch either inlined/duplicated it or retained the out-of-line copy without using it. It should not be documented as a public worker API.

## Payload, Message, And Notification Type Resolution

Request messages:

| Value | Decimal | Display | Source-facing name | Producer | Payload ownership |
| --- | ---: | --- | --- | --- | --- |
| `0x42446972` | `1111779698` | `BDir` | `BrowseDirectory` | raw `0x005283b0` wrapper; queued item handled by `ProcessWorkItem` | Heap ANSI title from `_strdup`; `ProcessWorkItem` frees it after posting result. |
| `0x47654874` | `1197820020` | `GeHt` | `GetHttp` / `RequestHTTPGet` | live `0x00528290`, called by PatchPane2 | One heap `SimpleUString`; `ProcessWorkItem` destroys it and frees the block. |
| `0x4e434175` | `1313030517` | `NCAu` request | `NcaUpdate` / `RequestNCAUpdate` | live `0x00528310`, called by registration dialog | Two adjacent heap `SimpleUString` values; `ProcessWorkItem` destroys both and frees the block. |

Notification channels:

| Value | Decimal | Display | Producer | Consumer |
| --- | ---: | --- | --- | --- |
| `0x42446972` | `1111779698` | `BDir` | browse helper / `ProcessWorkItem` BDir branch | [UID:0003MG] `MusicControlDialogDirectoryPacketHandler` checks the tag and consumes path payload when present. |
| `0x68747470` | `1752462448` | `http` | `FetchHTTPContent` | [UID:0001EV] `PatchPane2MainLoop` filters `event + 0x08 == 0x68747470` and switches HTTP state payloads. |
| `0x4e634175` | `1315127669` | `NCAu` notification | `ProcessNCAUpdate` inline failure path and `PostNCAStatus` | [UID:0001CU] `NexonclubRegistrationDialog::OnNcauthNotification` consumes state at payload `+4`. |

Notification classes:

- `brdir::Notification`: `LObject`-derived 0x108-byte object; vtable at `0x0061fbb0`; `+0x04` is a `MAX_PATH` ANSI path buffer. No extra state field. Empty path means cancel or failed path conversion. Destructor just performs base cleanup and optional delete.
- `httpget::Notification`: 0x0c-byte object; vtable at `0x0061fbc0`; `+0x04` is `HttpGetNotificationState`; `+0x08` is a state-dependent payload. Destructor releases payload only for states `1` (`DataChunk`, `_AUTOBUF<unsigned char>*`) and `4` (`InternetOpenFailed`, error/helper object).
- `ncauth::Notification`: 8-byte object; vtable at `0x0061fbd0`; `+0x04` is `NcauthNotificationState`. No owned payload beyond the object.

HTTP state names:

- `0`: `Started`
- `1`: `DataChunk`
- `2`: `Completed`
- `3`: `ReadOrOpenUrlFailed`
- `4`: `InternetOpenFailed`

NCA state names:

- `0`: `Accepted`
- `1`: `IdRejected`
- `2`: `PasswordRejected`
- `3`: `RejectedOther`
- `4`: `OpenFailed`
- `5`: `ReadFailed`

The enum names remain descriptive/inferred rather than recovered original symbols, but the values, state producers, destructor ownership, and consumers are now strong enough for source-facing reconstruction.

## Heuristic / Inference Reanalysis And Validation

Issue: source placement for the aggregate.

- Evidence checked: `Application::Initialize` constructor caller, `g_pMiscWorkThread` lifecycle, `PatchPane2` and registration request consumers, NCA URL override/fallback ownership, proposed source tree, file/class docs, generated route.
- Accepted inference: `NexusTK/app/MiscWorkThread.cpp`.
- Rejected alternatives:
  - `network/MiscWorkThread.cpp`: rejected because the module also handles shell browse-directory UI and application notification routing, not just transport.
  - `CashShopRequest.cpp`: rejected because the wrappers are reached through `g_pMiscWorkThread` and `Thread::DispatchRequest`, not a cash-shop object.
  - `NexonclubRegistrationDialog.cpp`: rejected because registration queues NCA work and consumes results, while the worker builds the URL, opens WinInet, parses response, and posts notifications.
  - `PatchPane.cpp`: rejected as direct owner for HTTP worker internals; PatchPane2 is a request producer and HTTP notification consumer, not the worker owner.
- Remaining uncertainty: exact original project path spelling is not proven by embedded source-path metadata. Impact: no owner/emitter blocker; cap confidence below final-audit range.

Issue: final request wrapper names.

- Evidence checked: wrapper bodies, direct callers, message IDs, `Thread` helper, payload allocation/cleanup, stale `CashShopRequestAuthDirectory` correction page.
- Accepted names: `RequestHTTPGet`, `RequestNCAUpdate`, and `RequestBrowseDirectory`.
- Rejected alternatives:
  - `SendHashRequest`, `SendAuthRequest`, `SendDirectoryRequest`: rejected as stale generated/CashShop wording.
  - `ProcessHTTPGet` for the wrappers: rejected because they only allocate payloads and queue work; the actual processing bodies are `FetchHTTPContent` and `ProcessNCAUpdate`.
  - `Queue*` names: plausible, but `Request*` matches current docs and caller intent better.
- Remaining uncertainty: original symbol spelling could differ. Impact: descriptive names are adequate for first-draft C++ and score bump, but not for 95+ final audit.

Issue: `0x005283b0` raw browse request helper.

- Evidence checked: exported Ghidra record, missing IDA function name/size, zero callers, direct PE call/jump/VA/RVA search, raw bytes, `0x00596960` xrefs, BDir payload cleanup in `ProcessWorkItem`.
- Accepted inference: `MiscWorkThread::RequestBrowseDirectory(const char* title)`, an unreferenced retained request wrapper.
- Rejected alternatives:
  - Live public helper: rejected by no direct callers and no static pointers.
  - File-local free helper: weaker because the body uses `this` in ECX and calls the `Thread` queue helper as a member.
  - Duplicate raw garbage: rejected by coherent prologue/body/ret and exact pairing with request wrapper family.
- Impact: include in docs and first-draft C++ as an unreferenced helper, but do not use it as evidence for a live caller.

Issue: `0x00527eb0` standalone browse processing helper.

- Evidence checked: zero callers, no PE direct refs, full browse-dialog body, duplicated BDir branch in `ProcessWorkItem`, brdir notification construction refs.
- Accepted inference: retained private/static helper copy `BrowseForDirectoryAndPost` / `PostBrowseDirectoryNotification`.
- Rejected alternatives:
  - Live public API: rejected by no callers/pointers.
  - Main request wrapper: rejected because it performs the UI browse operation and posts a notification; the request wrapper is `0x005283b0`.
- Impact: source draft may call this helper from `ProcessWorkItem`, while documentation records the binary retained both an out-of-line body and inlined/duplicated branch behavior.

Issue: `0x00528560` post/status helper.

- Evidence checked: direct calls at `0x00527e0d` and `0x00527e86`, body allocates 8 bytes, constructs `LObject`, installs `ncauth::Notification` vtable, writes state at `+4`, posts `0x4e634175`, zero non-NCA callers.
- Accepted inference: file-local helper `PostNCAStatus(NcauthNotificationState state)` in `MiscWorkThread.cpp`.
- Rejected alternatives:
  - `MiscWorkThread` member: rejected because the signature is `cdecl` with no `this` and no worker state access.
  - `ncauth::Notification` static method: possible stylistically, but weaker because no class-specific static evidence exists and the helper is only used locally by `ProcessNCAUpdate`.
  - Generic notification helper: rejected because it constructs only `ncauth::Notification`.
- Impact: source draft should implement it as a file-local free helper.

Issue: notification class names and payload layouts.

- Evidence checked: vtable names/addresses, construction stores, destructor bodies, allocation sizes, producer states, consumer handlers, exact vtable data child.
- Accepted names/layouts: `brdir::Notification`, `httpget::Notification`, and `ncauth::Notification` with the fields described above.
- Rejected alternatives:
  - One shared generic notification class: rejected because three vtables, three destructor targets, and different layouts exist.
  - Separate source files per notification class: possible in source, but weaker than local declarations under `MiscWorkThread.cpp` because all construction/destruction/use evidence clusters in this file family.
- Impact: local namespace classes in `MiscWorkThread.cpp` are source-plausible and ready for first-draft C++.

Issue: notification consumers.

- Evidence checked: PatchPane2 main loop, MusicControlDialog directory handler, Nexonclub registration support, FourCC scans.
- Accepted consumers:
  - HTTP: PatchPane2 secondary work-event callback [UID:0001EV].
  - Browse directory: MusicControlDialog directory packet handler [UID:0003MG].
  - NCA auth: NexonclubRegistrationDialog notification handler [UID:0001CU].
- Extra `0x42446972` occurrence at `0x00529c89` belongs to MusicControlDialog's BDir consumer, not an extra MiscWorkThread producer.
- Impact: target open question on exact UI/notification handlers is resolved at source-facing level.

Issue: compiler-generated functions in this aggregate.

- Evidence checked: constructor unwind jump to `0x005283e0`, scalar deleting destructor vtable pointers, normal destructor bodies.
- Accepted source treatment: express these through the constructor/destructor and ordinary virtual destructors; do not hand-write scalar deleting destructors or EH clear helper as public source functions.
- Impact: formal C++ can be populated without emitting explicit compiler wrapper code.

## Open Questions Resolved Or Remaining

Resolved:

- Final request wrapper names: use `RequestHTTPGet`, `RequestNCAUpdate`, and `RequestBrowseDirectory` as high-probability descriptive names.
- `0x005283b0` role: unreferenced retained `MiscWorkThread` request wrapper, not live public API and not CashShopRequest.
- `0x00527eb0` role: uncalled private/static browse-dialog/post helper copy, not a live public API.
- `0x00528560` role: file-local `PostNCAStatus`, not a `MiscWorkThread` member and not required to be a `ncauth::Notification` static method.
- Notification classes: `brdir::Notification`, `httpget::Notification`, and `ncauth::Notification` are distinct local notification payload classes under the MiscWorkThread source family.
- Payload ownership: request payloads are owned by `ProcessWorkItem`; notification payload ownership is state-specific and class-owned after posting.
- UI/notification consumers: HTTP is PatchPane2, BDir is MusicControlDialog, NCA is NexonclubRegistrationDialog.
- Stale `CashShopRequest` ownership: rejected for this range; [UID:0001CK] remains a non-emitting correction page.

Remaining, with impact:

- Original symbol spellings are not proven by debug/source metadata. Impact: no owner/emitter or C++ draft blocker; keep confidence at `90`, not higher.
- Original source path could have been a flatter `MiscWorkThread.cpp`, but current reconstruction route `NexusTK/app/MiscWorkThread.cpp` is the best supported target. Impact: no routing blocker.
- Final `Thread` virtual name may be `OnMessage` rather than `ProcessWorkItem`. Impact: code draft uses `ProcessWorkItem` as the documentation name; if `Thread` later standardizes the virtual name, the method can be renamed without changing behavior.
- Live MCP was unavailable this session. Impact: confidence is capped below `92` despite strong prior IDA docs and direct PE scans.

## First-Draft C++ Recommendation

Recommendation: populate [UID:0001CJ]'s formal `RECONSTRUCTION_CPP CODE` block with this first draft after applying the metadata/support text. This is not a no-code case: the target is reconstructable, has a valid emitter route to `auto-generated/NexusTK/app/MiscWorkThread.cpp`, and `(87 + 90) / 2 > 85`.

The draft uses descriptive names where original symbols are not recovered. It intentionally models normal source-level constructors/destructors rather than compiler-generated scalar deleting destructors or constructor-unwind helpers.

```cpp
// UID:0001CJ | MiscWorkThread worker helpers and local notifications.

#include <windows.h>
#include <shlobj.h>
#include <wininet.h>
#include <stdio.h>

enum MiscWorkThreadMessageId {
    kMiscWorkBrowseDirectory = 0x42446972, // BDir
    kMiscWorkGetHttp = 0x47654874,         // GeHt
    kMiscWorkNcaUpdate = 0x4e434175        // NCAu request
};

enum MiscWorkThreadNotificationId {
    kBrowseDirectoryNotification = 0x42446972,
    kHttpGetNotification = 0x68747470,
    kNcauthNotification = 0x4e634175
};

namespace brdir {

class Notification : public LObject {
public:
    Notification()
    {
        m_path[0] = 0;
    }

    virtual ~Notification()
    {
    }

    char m_path[MAX_PATH];
};

} // namespace brdir

namespace httpget {

enum NotificationState {
    Started = 0,
    DataChunk = 1,
    Completed = 2,
    ReadOrOpenUrlFailed = 3,
    InternetOpenFailed = 4
};

class Notification : public LObject {
public:
    Notification(NotificationState state, LObject* payload = 0)
        : m_state(state), m_payload(payload)
    {
    }

    virtual ~Notification()
    {
        if ((m_state == DataChunk || m_state == InternetOpenFailed) && m_payload != 0) {
            delete m_payload;
        }
    }

    NotificationState m_state;
    LObject* m_payload;
};

} // namespace httpget

namespace ncauth {

enum NotificationState {
    Accepted = 0,
    IdRejected = 1,
    PasswordRejected = 2,
    RejectedOther = 3,
    OpenFailed = 4,
    ReadFailed = 5
};

class Notification : public LObject {
public:
    explicit Notification(NotificationState state)
        : m_state(state)
    {
    }

    virtual ~Notification()
    {
    }

    NotificationState m_state;
};

} // namespace ncauth

extern Application* g_pApplication;
extern MiscWorkThread* g_pMiscWorkThread;
extern SimpleUString g_ncauthConfirmUserUrlOverride; // UID:00029T
extern const unsigned char g_ncauthConfirmUserUrlObfuscated[]; // UID:00027S

static void PostNotification(unsigned int channel, LObject* notification)
{
    g_pApplication->PostNotification(channel, notification);
}

static void DecodeNcauthConfirmUserUrl(char* out, size_t outSize)
{
    size_t i = 0;
    while (i + 1 < outSize && g_ncauthConfirmUserUrlObfuscated[i] != 0) {
        out[i] = static_cast<char>(~g_ncauthConfirmUserUrlObfuscated[i]);
        ++i;
    }
    out[i] = 0;
}

static void BrowseForDirectoryAndPost(const char* title)
{
    BROWSEINFOA browseInfo;
    char displayName[MAX_PATH];

    CoInitialize(0);
    ShowCursor(TRUE);

    memset(&browseInfo, 0, sizeof(browseInfo));
    browseInfo.hwndOwner = g_pApplication->GetWindowHandle();
    browseInfo.pszDisplayName = displayName;
    browseInfo.lpszTitle = title;
    browseInfo.ulFlags = BIF_RETURNONLYFSDIRS;

    LPITEMIDLIST pidl = SHBrowseForFolderA(&browseInfo);

    brdir::Notification* notification = new brdir::Notification;
    if (pidl == 0 || !SHGetPathFromIDListA(pidl, notification->m_path)) {
        notification->m_path[0] = 0;
    }

    PostNotification(kBrowseDirectoryNotification, notification);

    ShowCursor(FALSE);
    CoUninitialize();
}

static void FetchHTTPContent(const wchar_t* url)
{
    HINTERNET session = InternetOpenA("Baram", 0, 0, 0, 0);
    if (session == 0) {
        PostNotification(kHttpGetNotification,
                         new httpget::Notification(httpget::InternetOpenFailed,
                                                   new InternetError));
        return;
    }

    SimpleString narrowUrl(url);
    HINTERNET request = InternetOpenUrlA(session, narrowUrl.c_str(), 0, 0, 0, 0);
    if (request == 0) {
        PostNotification(kHttpGetNotification,
                         new httpget::Notification(httpget::ReadOrOpenUrlFailed));
        InternetCloseHandle(session);
        return;
    }

    PostNotification(kHttpGetNotification,
                     new httpget::Notification(httpget::Started));

    BYTE buffer[0x400];
    DWORD bytesRead = 0;
    BOOL ok = InternetReadFile(request, buffer, sizeof(buffer), &bytesRead);
    while (ok && bytesRead != 0) {
        _AUTOBUF<unsigned char>* chunk = new _AUTOBUF<unsigned char>(bytesRead);
        memmove(chunk->data(), buffer, bytesRead);
        PostNotification(kHttpGetNotification,
                         new httpget::Notification(httpget::DataChunk, chunk));
        ok = InternetReadFile(request, buffer, sizeof(buffer), &bytesRead);
    }

    if (!ok) {
        PostNotification(kHttpGetNotification,
                         new httpget::Notification(httpget::ReadOrOpenUrlFailed));
    }

    PostNotification(kHttpGetNotification,
                     new httpget::Notification(httpget::Completed));

    InternetCloseHandle(request);
    InternetCloseHandle(session);
}

static void PostNCAStatus(ncauth::NotificationState state)
{
    PostNotification(kNcauthNotification, new ncauth::Notification(state));
}

static void ProcessNCAUpdate(const SimpleUString& account, const SimpleUString& password)
{
    HINTERNET session = InternetOpenA(0, 0, 0, 0, 0);
    if (session == 0) {
        PostNotification(kNcauthNotification,
                         new ncauth::Notification(ncauth::OpenFailed));
        return;
    }

    char url[0x100];
    if (!g_ncauthConfirmUserUrlOverride.empty()) {
        strcpy_s(url, sizeof(url), g_ncauthConfirmUserUrlOverride.c_str());
    } else {
        char format[0x80];
        SimpleString accountText(account);
        SimpleString passwordText(password);
        DecodeNcauthConfirmUserUrl(format, sizeof(format));
        sprintf_s(url, sizeof(url), format, accountText.c_str(), passwordText.c_str());
    }

    HINTERNET request = InternetOpenUrlA(session, url, Locale, 0, 0, 0);
    if (request == 0) {
        InternetCloseHandle(session);
        PostNCAStatus(ncauth::OpenFailed);
        return;
    }

    char response[0x80];
    DWORD bytesRead = 0;
    if (!InternetReadFile(request, response, sizeof(response), &bytesRead)) {
        PostNCAStatus(ncauth::ReadFailed);
        InternetCloseHandle(request);
        InternetCloseHandle(session);
        return;
    }

    if (response[0] == '1') {
        PostNCAStatus(ncauth::Accepted);
    } else if (response[2] == ' ' && response[3] == 'I' && response[4] == 'D') {
        PostNCAStatus(ncauth::IdRejected);
    } else if (response[2] == 'P' && response[3] == 'W') {
        PostNCAStatus(ncauth::PasswordRejected);
    } else {
        PostNCAStatus(ncauth::RejectedOther);
    }

    InternetCloseHandle(request);
    InternetCloseHandle(session);
}

MiscWorkThread::MiscWorkThread()
    : Thread(100)
{
    g_pMiscWorkThread = this;
    StartThread();
}

MiscWorkThread::~MiscWorkThread()
{
    StopThread();
    g_pMiscWorkThread = 0;
}

void MiscWorkThread::ProcessWorkItem(int messageId, void* payload, int aux)
{
    switch (messageId) {
    case kMiscWorkBrowseDirectory:
        BrowseForDirectoryAndPost(static_cast<const char*>(payload));
        free(payload);
        break;

    case kMiscWorkGetHttp:
        FetchHTTPContent(static_cast<SimpleUString*>(payload)->c_str());
        delete static_cast<SimpleUString*>(payload);
        break;

    case kMiscWorkNcaUpdate:
    {
        SimpleUString* strings = static_cast<SimpleUString*>(payload);
        ProcessNCAUpdate(strings[0], strings[1]);
        strings[1].~SimpleUString();
        strings[0].~SimpleUString();
        operator delete(strings);
        break;
    }

    default:
        Thread::ProcessWorkItem(messageId, payload, aux);
        break;
    }
}

void MiscWorkThread::RequestHTTPGet(const wchar_t* url)
{
    DispatchRequest(kMiscWorkGetHttp, new SimpleUString(url), 0);
}

void MiscWorkThread::RequestNCAUpdate(const wchar_t* account, const wchar_t* password)
{
    SimpleUString* strings =
        static_cast<SimpleUString*>(operator new(sizeof(SimpleUString) * 2));
    new (&strings[0]) SimpleUString(account);
    new (&strings[1]) SimpleUString(password);
    DispatchRequest(kMiscWorkNcaUpdate, strings, 0);
}

void MiscWorkThread::RequestBrowseDirectory(const char* title)
{
    DispatchRequest(kMiscWorkBrowseDirectory, _strdup(title), 0);
}
```

Supervisor application notes for the draft:

- `SimpleString`, `InternetError`, `_AUTOBUF<unsigned char>`, `Application::PostNotification`, `Application::GetWindowHandle`, and `Thread::DispatchRequest` should be mapped to the project's actual helper names if those names are already stronger in surrounding docs.
- `ProcessWorkItem` may later be renamed to the final `Thread` virtual name if the base class standardizes it.
- The source intentionally models `0x005283e0`, `0x005283f0`, and notification scalar deleting destructors through normal source constructors/destructors. Do not add explicit scalar deleting destructor code.
- If the supervisor is uncomfortable emitting the unreferenced `RequestBrowseDirectory`, keep that method in a comment with the reachability note. The stronger recommendation is to include it as retained source-authored helper code because the binary contains the coherent body.

## Exact Supervisor Changes Required

### Primary Target Header

Placement: header of `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`.

Recommended replacement:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Primary Target Reconstruction Notes

Placement: replace the current `## Reconstruction Notes` section in [UID:0001CJ].

Recommended replacement:

```md
## Reconstruction Notes

This aggregate is source-ready for a first-draft `MiscWorkThread.cpp` implementation. Use [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) as owner/emitter and keep source placement at `NexusTK/app/MiscWorkThread.cpp`.

Best source-facing names are:

- `FetchHTTPContent` for `0x005277c0`.
- `ProcessNCAUpdate` for `0x00527bb0`.
- `BrowseForDirectoryAndPost` / `PostBrowseDirectoryNotification` for the uncalled standalone helper at `0x00527eb0`.
- `MiscWorkThread::ProcessWorkItem` for the vtable-backed worker-message override at `0x00527fe0`.
- `MiscWorkThread::RequestHTTPGet` for `0x00528290`.
- `MiscWorkThread::RequestNCAUpdate` for `0x00528310`.
- `MiscWorkThread::RequestBrowseDirectory` for raw aligned helper `0x005283b0`.
- `PostNCAStatus` for `0x00528560`.

`0x005283b0` remains raw/no-function in IDA and has no direct `call`/`jmp`/VA/RVA reference in the scanned executable. It is still a coherent source-shaped `thiscall` request wrapper paired with the live HTTP/NCA wrappers, so document it as retained/unreferenced source-authored helper code rather than as a live public API.

`0x00528560` is a file-local free helper, not a `MiscWorkThread` member: it has no `this`, is called only from `ProcessNCAUpdate`, allocates an 8-byte `ncauth::Notification`, writes the state at `+4`, and posts channel `0x4e634175`.

Formal C++ can now be populated with a first draft. Use ordinary source constructors/destructors and notification classes; do not hand-write scalar deleting destructors or the constructor-unwind singleton clear helper.
```

### Primary Target Open Questions

Placement: replace the current `## Open Questions` section in [UID:0001CJ].

Recommended replacement:

```md
## Open Questions

Resolved for this target:

- Request wrapper names are resolved at source-facing descriptive level as `RequestHTTPGet`, `RequestNCAUpdate`, and `RequestBrowseDirectory`.
- The raw helper at `0x005283b0` is resolved as an unreferenced retained `MiscWorkThread` request wrapper, not as `CashShopRequest` code and not as a live public API.
- The standalone browse helper at `0x00527eb0` is resolved as a retained private/static browse-dialog notification helper copy with zero direct static references; the live worker behavior is the `BDir` branch inside `ProcessWorkItem`.
- `0x00528560` is resolved as file-local `PostNCAStatus`, called only by `ProcessNCAUpdate`.
- Notification consumers are resolved: `PatchPane2` consumes `http`, `MusicControlDialog` consumes `BDir`, and `NexonclubRegistrationDialog` consumes `NCAu`.

Remaining limitations:

- Original symbol spellings are inferred/descriptive rather than recovered from debug/source metadata.
- The exact original source path may have been a flatter `MiscWorkThread.cpp`, but current reconstruction should remain under `NexusTK/app/MiscWorkThread.cpp`.
- `ProcessWorkItem` may later be renamed if the `Thread` base virtual is standardized as `OnMessage`.
```

### Primary Target Change Log

Placement: append to [UID:0001CJ] `## Changes`.

Recommended addition:

```md
- 2026-06-18 B001 source-quality reanalysis:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`, owner/emitter [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md), formal C++ blank, with open questions around request names, raw `0x005283b0`, notification handlers, and `0x00528560`.
  - After recommendation: `COMPLETION:87`, `CONFIDENCE:90`, owner/emitter unchanged, formal C++ ready for first-draft population.
  - Summary/evidence: B001 rechecked support docs, exported decompilation, direct PE `call`/`jmp`/VA/RVA references, FourCC immediates, notification class layouts, request payload ownership, `Thread` queue helper `0x00596960`, PatchPane2/MusicControlDialog/NexonclubRegistration consumers, and NCA URL support docs. `0x005283b0` remains raw/no-xref retained request-wrapper code; `0x00528560` is a live file-local `PostNCAStatus` helper called twice from `ProcessNCAUpdate`.
```

### Support Docs

Placement: [UID:0000LG] `by-file/MiscWorkThread.md`, replace the current `## Open Questions` section.

Recommended replacement:

```md
## Open Questions

- Exact original source-path spelling remains unproven. Current reconstruction should stay at `NexusTK/app/MiscWorkThread.cpp`; a flatter `MiscWorkThread.cpp` remains only a historical-source possibility.
- Request-submission wrapper names are resolved at source-facing descriptive level as `RequestHTTPGet`, `RequestNCAUpdate`, and `RequestBrowseDirectory`.
- The standalone browse processing helper at `0x00527eb0` is not a live public API in the scanned executable. Treat it as a retained private/static helper copy whose behavior is duplicated or inlined in `MiscWorkThread::ProcessWorkItem`.
- The notification classes are local source-family classes under namespaces `brdir`, `httpget`, and `ncauth`; exact original declaration nesting remains inferred but no longer blocks first-draft C++.
```

Recommended metadata change if the above support text is applied:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement: [UID:00008I] `by-class/MiscWorkThread.md`, replace the final-source blocker text in `## Parent Gate`.

Recommended replacement paragraph:

```md
The class and file parent both clear the active parent/emitter gate. Current source-facing names are `ProcessWorkItem`, `RequestHTTPGet`, `RequestNCAUpdate`, and `RequestBrowseDirectory`; the raw `0x005283b0` helper is retained/unreferenced request-wrapper code, not `CashShopRequest` ownership. Formal implementation should be supplied by [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md), with normal source constructors/destructors standing in for scalar deleting destructor and EH-clear compiler output.
```

Recommended metadata change if the above support text is applied:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Placement: [UID:0001CK] `by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md`, replace the stale `SendDirectoryRequest` label in the covered-range row for `0x005283b0-0x005283d5`.

Recommended replacement row:

```md
| `0x005283b0-0x005283d5` | stale `SendDirectoryRequest` | Raw `MiscWorkThread::RequestBrowseDirectory` retained helper; duplicates an ANSI title/path, dispatches message `0x42446972`, returns with `retn 4`, and has no direct static caller or pointer reference in the scanned executable. |
```

No required support-doc score changes are recommended for the notification classes. Their current class docs already contain the relevant layout/state evidence at same or greater detail; optional wording can replace old `95/95`/old-gate references when those pages are next touched.

## Coverage Report Replacement Text

Placement: `by-memory/-coverage-report.md`, replace the existing [UID:0001CJ] row currently near the [UID:0001CK] ownership-correction row:

Current row begins:

```md
    - [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) 0x005277c0-0x005285dd | helper island | MiscWorkThreadAndNotifications : reconstructable : 84% : strong :
```

Recommended replacement:

```md
    - [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) 0x005277c0-0x005285dd | worker/helper island | MiscWorkThreadAndNotifications : reconstructable : 87% : strong : MiscWorkThread worker and notification source island with `FetchHTTPContent`, `ProcessNCAUpdate`, `ProcessWorkItem`, constructor/destructor/source lifetime helpers, request wrappers `RequestHTTPGet`/`RequestNCAUpdate`/raw retained `RequestBrowseDirectory`, local `PostNCAStatus`, direct PE reachability showing raw `0x005283b0` and browse helper `0x00527eb0` have no `call`/`jmp`/VA/RVA start references while `0x00528560` is called from `ProcessNCAUpdate`, Thread async dispatch helper `0x00596960`, request FourCCs `0x42446972`/`0x47654874`/`0x4e434175`, notification channels `0x42446972`/`0x68747470`/`0x4e634175`, `brdir`/`httpget`/`ncauth` notification layouts and state-owned payload lifetimes, PatchPane2/MusicControlDialog/NexonclubRegistration consumers, stale CashShop ownership rejection, source placement under `NexusTK/app/MiscWorkThread.cpp`, and first-draft C++ ready for supervisor population.
```

No generated report edits should be made manually. If the supervisor applies the target/support metadata changes and runs validator/autogen, generated `-ag-*` reports should refresh through the validator.

## Validator / Tool Results

- Live MCP check: failed, `Unable to connect to the remote server`.
- Direct PE scan: successful; results summarized above.
- `int_convert.py`: successful for the five FourCC/channel values after running each value individually.
- Documentation validator: not run, because this assignment created only the B001 research report and did not edit `by-*` documentation.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B001/research/0001CJ-MiscWorkThreadAndNotifications-source-quality.md`

Modified:

- None outside this report.

Not modified:

- `by-*` docs
- generated reports
- generated source
- IDA DB
- `by-memory/-coverage-report.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001CJ-MiscWorkThreadAndNotifications-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001CJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
