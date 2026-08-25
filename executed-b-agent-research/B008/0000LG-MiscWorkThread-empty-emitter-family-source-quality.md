** TARGET-REPORT-UID:0000LG **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000LG MiscWorkThread Empty-Emitter Family Source-Quality Report

## Assignment And Mode

- Assignment: `B008-report-0000LG-MiscWorkThread-empty-emitter-family-20260701`
- Mode: report-only research; no target/support by-* docs were edited.
- Target: [UID:0000LG] `by-file/MiscWorkThread.md`
- Generated lead: `auto-generated/NexusTK/app/MiscWorkThread.cpp`
- Required output: this report, with implementation-ready formal C++ or formal no-code/no-duplicate disposition for the current empty emitters.

## Current Generated Baseline

Generated `auto-generated/NexusTK/app/MiscWorkThread.cpp` was current at:

- `validator-command-id: 000000003842`
- `validator-refreshed-at: 2026-07-01T15:24:09-04:00`
- Tracker row: `12` total emitters, `2` filled, `10` empty, `16.7%` filled.
- Filled emitters: [UID:000012] `by-class/brdir__Notification.md`; [UID:0001CJ] `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`.
- Empty markers now audited: [UID:00008I], [UID:0001SP], [UID:000069], [UID:0001SN], [UID:00008X], [UID:0001SQ], [UID:0000RQ], [UID:0001P8], [UID:00027S], [UID:00029T].

The generated file currently emits `brdir::Notification` from [UID:000012] and the worker/helper body from [UID:0001CJ]. It still duplicates source declarations inside [UID:0001CJ] for `MiscWorkThreadMessageId`, `httpget::Notification`, `HttpGetNotificationState`, `ncauth::Notification`, and `NcauthNotificationState`; those declarations are the main source-quality repair for this family.

## Evidence Used

### Existing Documentation

- `by-file/MiscWorkThread.md`
- `by-class/MiscWorkThread.md`
- `by-type/by-enum/MiscWorkThreadMessageId.md`
- `by-class/httpget__Notification.md`
- `by-type/by-enum/HttpGetNotificationState.md`
- `by-class/ncauth__Notification.md`
- `by-type/by-enum/NcauthNotificationState.md`
- `by-global/g_pMiscWorkThread.md`
- `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md`
- `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md`
- `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`
- `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`
- `by-class/brdir__Notification.md`
- `auto-generated/-ag-research-tracker.md`, `-ag-class-coverage.md`, `-ag-type-coverage.md`, `-ag-global-coverage.md`, `-ag-memory-coverage.md`

### Existing Report Search

Search terms used: `TARGET-REPORT-UID:0000LG`, `MiscWorkThread-empty-emitter-family`, `MiscWorkThread`, `0001CJ`, `00027S`, `00029T`, `000012`, `000069`, `00008X`, `0001SP`, `0001SN`, `0001SQ`, `brdir`, `httpget`, `ncauth`.

No exact prior family report for [UID:0000LG] / `MiscWorkThread-empty-emitter-family` was found. Matching support reports opened and used as evidence:

- `executed-b-agent-research/B001/0001CJ-MiscWorkThreadAndNotifications-source-quality.md`
- `executed-b-agent-research/B011/000012-brdir-Notification-source-quality.md`
- `executed-b-agent-research/B001/00029T-MainMenuTextUrlStaticString.md`
- `executed-b-agent-research/B002/00029T-MainMenuTextUrlStaticString-memory-range-report.md`
- `executed-b-agent-research/B002/00027S-NcauthConfirmUserUrlObfuscated-advanced-scan.md`

### Live IDA MCP Evidence

MCP endpoint was live. Session `supervisor_resume_20260629` reported:

- `status: ok`
- module `NexusTK.exe`
- IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- imagebase `0x400000`
- `auto_analysis_ready: true`, `hexrays_ready: true`

Live checks performed:

- `lookup_funcs`: confirmed modeled starts and sizes for `0x005277c0` (`0x3e6`), `0x00527bb0` (`0x2f4`), `0x00527eb0` (`0x12f`), `0x00527fe0` (`0x1c1`), `0x005281b0` (`0x75`), `0x00528230` (`0x51`), `0x00528290` (`0x74`), `0x00528310` (`0x96`), `0x005283e0` (`0xb`), `0x005283f0` (`0x8f`), `0x00528480` (`0x3b`), `0x005284c0` (`0x5a`), `0x00528520` (`0x38`), `0x00528560` (`0x7d`); `0x005283b0` remains `Not a function`.
- `xrefs_to`: `0x0067ab50` has 8 refs; `0x0066de30` has 2 refs, both in `0x00527bb0`; `0x0069b3d0` has 6 refs; `0x005283b0` has 0 refs; vtables `0x0061fb74`, `0x0061fbb0`, `0x0061fbc0`, `0x0061fbd0` have the expected construction/destructor refs.
- `get_bytes`: `0x0067ab50` is `00 00 00 00`; `0x0069b3d0` is `00 00 00 00`; `0x0066de30` is the exact 60-byte encoded URL sequence `97 8b 8b 8f c5 d0 d0 92 9e 96 93 d1 91 9a 87 90 91 9c 93 8a 9d d1 9c 90 92 d0 9c 93 8a 9d 9e 9b 92 96 91 d0 9c 90 91 99 96 8d 92 8a 8c 9a 8d c0 b6 bb c2 da 8c d9 af a8 c2 da 8c ff`.
- `find_bytes`: no VA/RVA pointer hits for `0x005283b0` (`b0 83 52 00`, `b0 83 12 00`); three little-endian `0x0066de30` hits inside the NCA decode path; six little-endian `0x0069b3d0` hits matching the documented static string refs.
- `callees`: `0x00527fe0` calls `0x005277c0`, `0x00527bb0`, shell browse APIs, EventMan router `0x004aa1d0`, and base thread fallback `0x00596920`; request wrappers `0x00528290` and `0x00528310` call thread dispatch helper `0x00596960`; `0x00528560` constructs/posts only NCA notifications.
- `decompile 0x00527fe0`: confirmed switch cases `1111779698`, `1197820020`, and `1313030517`, posting `brdir::Notification`, calling HTTP/NCA helpers, cleaning request payloads, and falling back to the thread base.
- `decompile 0x005277c0`: confirmed HTTP state postings `0`, `1`, `2`, `3`, `4`, `httpget::Notification` vtable `0x0061fbc0`, channel `0x68747470`, WinInet reads, and state-owned payload setup.
- `decompile 0x00527bb0`: confirmed override URL check at `0x0069b3d0`, bitwise-not fallback decode from `0x0066de30`, WinInet open/read, NCA state postings `0..5`, inline state `4` notification on `InternetOpenA` failure, and helper `0x00528560`.

## Source-Placement And Ownership Reanalysis

The best source route remains [UID:0000LG] `NexusTK/app/MiscWorkThread.cpp`. Positive evidence:

- `Application` constructs/destructs the `MiscWorkThread` singleton through `g_pMiscWorkThread`.
- `ProcessWorkItem` dispatches worker requests for browse directory, HTTP get, and NCA update.
- HTTP, NCA, and browse helpers all post local notification payloads through the same EventMan notification route.
- `g_pMiscWorkThread`, `MiscWorkThreadMessageId`, `httpget::Notification`, `ncauth::Notification`, NCA override storage, and fallback URL storage all point back to the same worker source family.
- The current generated output already routes the family to `auto-generated/NexusTK/app/MiscWorkThread.cpp`.

Rejected owners:

| Candidate | Rejection |
| --- | --- |
| `CashShopRequest.cpp` / [UID:00001H] | The request wrappers are reached through `g_pMiscWorkThread` and `Thread` queue helper `0x00596960`, not a cash-shop object. |
| `PatchPane.cpp` | PatchPane produces/consumes HTTP work but does not own worker internals or notification class declarations. |
| `NexonclubRegistrationDialog.cpp` | Registration queues NCA work and consumes `ncauth::Notification`; the worker owns URL construction, WinInet open/read, parse, and posting. |
| `MainMenuPane.cpp` / `MapPane.cpp` | These are packet writers for the override string. They do not semantically own the NCA worker URL storage. |
| New `auth/Ncauth.cpp` or `network/MiscWorkThread.cpp` | Plausible abstract source grouping, but weaker than the existing app worker family that also handles shell browse-directory UI and application notification routing. |

## Heuristic And Source-Quality Reanalysis

The older blank-C++ blockers are now source-quality debt rather than true blockers:

- The active code gate is not a 95/95 final-source gate. The relevant pages are reconstructable, routed to a valid emitter, and clear the B-agent source-quality threshold.
- The enum names are descriptive and not recovered originals, but the values, producers, consumers, and payload/state semantics are strong enough for first-draft formal C++.
- The data names are descriptive and not recovered originals, but [UID:0001CJ] already references `g_ncauthConfirmUserUrlOverride` and `g_ncauthConfirmUserUrlObfuscated`; the data pages should own those source declarations instead of remaining empty markers.
- [UID:0001CJ] should keep method/helper bodies, not source declarations that belong to dedicated class/type/global/data pages. Moving declarations out of [UID:0001CJ] requires de-duplication in that aggregate.
- [UID:0001P8] is an exact storage child of [UID:0000RQ]; it should emit a formal no-duplicate storage comment, not a second pointer definition.

## Recommended First Callback Scope

Recommended implementation should edit the ten empty marker docs plus [UID:0001CJ] and [UID:0000LG] support prose:

- Fill class/type/global/data declaration pages with formal C++ where source-bearing.
- Fill [UID:0001P8] with formal no-duplicate storage proof.
- Update [UID:0001CJ] to remove duplicate declarations now emitted by child/support pages while preserving worker/helper bodies.
- Update [UID:0000LG] with the generated-output audit baseline and source-declaration ownership split.
- Do not edit [UID:000012] except as already-present support; it already emits `brdir::Notification`.
- Do not edit manual `-coverage-report.md`, generated reports, generated C++, validator/tool state, queues, archives, supervisor ledgers, or IDA DB.

## Empty Marker Dispositions

### [UID:00008I] `by-class/MiscWorkThread.md`

Disposition: source-bearing declaration emitter.

Recommended metadata:

- `COMPLETION:90`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000LG`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LG`
- Set `EMITTER_POSITION_OPTIONAL:1` after [UID:000012] or another early declaration position accepted by validator ordering.

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// UID:00008I | MiscWorkThread source-level worker class declaration.
// Method bodies are emitted by UID:0001CJ; this page owns the class surface.

[[CHILDREN]]

class MiscWorkThread : public Thread {
public:
    MiscWorkThread();
    virtual ~MiscWorkThread();

    virtual void ProcessWorkItem(int messageId, void* payload, int aux);

    void RequestHTTPGet(const wchar_t* url);
    void RequestNCAUpdate(const wchar_t* account, const wchar_t* password);
    void RequestBrowseDirectory(const char* title);
};
```

Rationale: `[[CHILDREN]]` lets [UID:0001SP] emit the request enum before the class declaration while avoiding duplicate method bodies. The class owns the source surface; [UID:0001CJ] owns method/helper implementations.

### [UID:0001SP] `by-type/by-enum/MiscWorkThreadMessageId.md`

Disposition: source-bearing enum emitter under [UID:00008I].

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:00008I`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00008I`

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
enum MiscWorkThreadMessageId {
    kMiscWorkBrowseDirectory = 0x42446972, // BDir
    kMiscWorkGetHttp = 0x47654874,         // GeHt
    kMiscWorkNcaUpdate = 0x4e434175        // NCAu request
};
```

Rationale: live `ProcessWorkItem` switch and request wrappers prove all three values. Original symbol spelling remains inferred, but this is no longer a reason to leave an empty marker.

### [UID:000069] `by-class/httpget__Notification.md`

Disposition: source-bearing class declaration emitter.

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:89`
- Keep `CANONICAL_OWNER:0000LG`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LG`
- Set `EMITTER_POSITION_OPTIONAL:2` or another pre-[UID:0001CJ] declaration position.

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// UID:000069 | httpget::Notification source-level payload declaration.

namespace httpget {

[[CHILDREN]]

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
```

Rationale: the class uses `[[CHILDREN]]` inside `namespace httpget` so [UID:0001SN] emits `NotificationState` before the class. The destructor is source-facing payload ownership; do not emit scalar-delete flags or raw helper calls.

### [UID:0001SN] `by-type/by-enum/HttpGetNotificationState.md`

Disposition: source-bearing enum emitter under [UID:000069].

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:000069`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:000069`

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
enum NotificationState {
    Started = 0,
    DataChunk = 1,
    Completed = 2,
    ReadOrOpenUrlFailed = 3,
    InternetOpenFailed = 4
};
```

Rationale: `FetchHTTPContent` posts all five values on channel `0x68747470`; `httpget::Notification` destructor releases payload for states `1` and `4`.

### [UID:00008X] `by-class/ncauth__Notification.md`

Disposition: source-bearing class declaration emitter.

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- Keep `CANONICAL_OWNER:0000LG`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LG`
- Set `EMITTER_POSITION_OPTIONAL:3` or another pre-[UID:0001CJ] declaration position.

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// UID:00008X | ncauth::Notification source-level payload declaration.

namespace ncauth {

[[CHILDREN]]

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
```

Rationale: the class uses `[[CHILDREN]]` inside `namespace ncauth` so [UID:0001SQ] emits the enum before the class. The source destructor is empty; compiler scalar-deleting wrapper logic stays out of formal C++.

### [UID:0001SQ] `by-type/by-enum/NcauthNotificationState.md`

Disposition: source-bearing enum emitter under [UID:00008X].

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:93`
- Keep `CANONICAL_OWNER:00008X`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00008X`

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
enum NotificationState {
    Accepted = 0,
    IdRejected = 1,
    PasswordRejected = 2,
    RejectedOther = 3,
    OpenFailed = 4,
    ReadFailed = 5
};
```

Rationale: `ProcessNCAUpdate`, `PostNCAStatus`, and the registration consumer prove the six values. Exact original value names remain behavioral, but the state semantics are strong enough for first-draft formal C++.

### [UID:0000RQ] `by-global/g_pMiscWorkThread.md`

Disposition: source-bearing global definition emitter.

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000LG`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LG`
- Set a pre-[UID:0001CJ] position after the class declaration, for example `EMITTER_POSITION_OPTIONAL:4`.

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// UID:0000RQ | MiscWorkThread singleton pointer.

MiscWorkThread* g_pMiscWorkThread = 0;

[[CHILDREN]]
```

Rationale: live bytes are zero, xrefs confirm constructor/destructor/helper/consumer lifecycle, and [UID:0001P8] should remain a storage child rather than duplicate this definition.

### [UID:0001P8] `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md`

Disposition: formal no-duplicate storage comment under [UID:0000RQ].

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000RQ`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000RQ`
- Update stale item summary text from `0xffffffff` to current zeroed bytes `00 00 00 00`.

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// UID:0001P8 | Exact storage for g_pMiscWorkThread at 0x0067ab50.
// The source definition is emitted by UID:0000RQ; do not duplicate the
// singleton pointer definition from this storage child.
```

Rationale: this clears the empty marker while preserving single-definition source ownership.

### [UID:00027S] `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md`

Disposition: source-bearing static data emitter.

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000LG`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LG`
- Set a pre-[UID:0001CJ] position, for example `EMITTER_POSITION_OPTIONAL:5`.

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// UID:00027S | Bitwise-not encoded NCA confirm-user fallback URL.
// Decodes to:
// http://mail.nexonclub.com/clubadmin/confirmuser?ID=%s&PW=%s

extern const unsigned char g_ncauthConfirmUserUrlObfuscated[] = {
    0x97, 0x8b, 0x8b, 0x8f, 0xc5, 0xd0, 0xd0, 0x92,
    0x9e, 0x96, 0x93, 0xd1, 0x91, 0x9a, 0x87, 0x90,
    0x91, 0x9c, 0x93, 0x8a, 0x9d, 0xd1, 0x9c, 0x90,
    0x92, 0xd0, 0x9c, 0x93, 0x8a, 0x9d, 0x9e, 0x9b,
    0x92, 0x96, 0x91, 0xd0, 0x9c, 0x90, 0x91, 0x99,
    0x96, 0x8d, 0x92, 0x8a, 0x8c, 0x9a, 0x8d, 0xc0,
    0xb6, 0xbb, 0xc2, 0xda, 0x8c, 0xd9, 0xaf, 0xa8,
    0xc2, 0xda, 0x8c, 0xff
};
```

Rationale: the current aggregate already depends on an external declaration for this symbol. Emitting the encoded bytes preserves the observed runtime decode behavior and avoids choosing a plain-literal rewrite prematurely.

### [UID:00029T] `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`

Disposition: source-bearing static object declaration emitter.

Recommended metadata:

- `COMPLETION:90`
- `CONFIDENCE:93`
- Keep `CANONICAL_OWNER:0000LG`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000LG`
- Set a pre-[UID:0001CJ] position, for example `EMITTER_POSITION_OPTIONAL:6`.

Formal `RECONSTRUCTION_CPP CODE` insertion:

```cpp
// UID:00029T | NCA confirm-user URL override string storage.

SimpleUString g_ncauthConfirmUserUrlOverride;
```

Rationale: live IDA confirms zero image bytes, startup construction, cleanup, two packet writers, and sole semantic reader in `ProcessNCAUpdate`. The source-visible symbol is descriptive but already used by [UID:0001CJ]'s formal draft.

## Required Support Edit: [UID:0001CJ]

[UID:0001CJ] should remain the worker/helper body emitter and keep its current metadata unless implementation changes require a small score bump. It should be edited to avoid duplicate declarations once the dedicated pages above emit them.

Recommended [UID:0001CJ] formal C++ de-duplication:

- Remove the `enum MiscWorkThreadMessageId` block from [UID:0001CJ]; [UID:0001SP] should emit it.
- Remove the `namespace httpget` enum/class declaration block from [UID:0001CJ]; [UID:000069] and [UID:0001SN] should emit it.
- Remove the `namespace ncauth` enum/class declaration block from [UID:0001CJ]; [UID:00008X] and [UID:0001SQ] should emit it.
- Keep `enum MiscWorkThreadNotificationId` in [UID:0001CJ] for now because no dedicated non-empty marker owns it in this assignment.
- Keep worker/helper bodies and request wrappers in [UID:0001CJ].
- Keep or replace `extern` declarations only if validator/generation ordering requires them. If dedicated pages emit before [UID:0001CJ], the externs for `g_pMiscWorkThread`, `g_ncauthConfirmUserUrlOverride`, and `g_ncauthConfirmUserUrlObfuscated` are optional but harmless as declarations. Do not create duplicate definitions.

Replacement comment block recommended in [UID:0001CJ] where the moved declarations formerly lived:

```cpp
// UID:0001SP emits MiscWorkThreadMessageId before this worker aggregate.
// UID:000069/UID:0001SN emit httpget::Notification and its state enum.
// UID:00008X/UID:0001SQ emit ncauth::Notification and its state enum.
// Keep this aggregate focused on worker/helper bodies and request wrappers.
```

## File-Level Support Edit: [UID:0000LG]

Recommended [UID:0000LG] support prose:

- Add the generated audit baseline from this report: `MiscWorkThread.cpp` validator command `000000003842`, refreshed `2026-07-01T15:24:09-04:00`, pre-callback state `12` total emitters, `2` filled, `10` empty, `16.7%` filled.
- State the declaration/body split:
  - [UID:000012], [UID:00008I], [UID:0001SP], [UID:000069], [UID:0001SN], [UID:00008X], [UID:0001SQ], [UID:0000RQ], [UID:00027S], and [UID:00029T] own source declarations/data.
  - [UID:0001CJ] owns worker/helper method bodies and request wrappers.
  - [UID:0001P8] is a storage child comment only.
- Preserve rejected owner policy for `CashShopRequest`, `PatchPane`, `NexonclubRegistrationDialog`, `MainMenuPane`, `MapPane`, and speculative standalone auth/network files.

## Negative Evidence And Non-Actions

- No exact `TARGET-REPORT-UID:0000LG` family report was found; this is the first current family report.
- No split is needed for [UID:00027S]; it is exactly the 60-byte encoded URL including encoded terminator.
- No split is needed for [UID:00029T]; it is a single four-byte static string handle.
- No second pointer definition should be emitted from [UID:0001P8].
- No child page should emit scalar deleting destructor flags, security-cookie checks, raw helper calls, or fake local APIs.
- [UID:000012] is already implemented and should be treated as already-present, not edited for this callback unless validator ordering forces a comment-only sync.
- Manual `-coverage-report.md` files, generated reports, generated C++, validator/tool state, queues, archives, supervisor ledgers, and IDA DB remain supervisor/tool-owned and should not be edited by B008.

## Score And Metadata Recommendations

| UID | Path | Current | Recommended | Owner/emitter disposition |
| --- | --- | ---: | ---: | --- |
| 0000LG | `by-file/MiscWorkThread.md` | 88/88 | 89/90 optional | File route stays `NexusTK/app/`; add audit/prose only if supervisor accepts. |
| 00008I | `by-class/MiscWorkThread.md` | 88/89 | 90/91 | Source class declaration; owner/emitter unchanged. |
| 0001SP | `by-type/by-enum/MiscWorkThreadMessageId.md` | 86/90 | 88/91 | Source enum; owner/emitter unchanged. |
| 000069 | `by-class/httpget__Notification.md` | 85/86 | 88/89 | Source notification declaration; owner/emitter unchanged. |
| 0001SN | `by-type/by-enum/HttpGetNotificationState.md` | 86/89 | 88/90 | Source enum; owner/emitter unchanged. |
| 00008X | `by-class/ncauth__Notification.md` | 86/88 | 88/90 | Source notification declaration; owner/emitter unchanged. |
| 0001SQ | `by-type/by-enum/NcauthNotificationState.md` | 86/92 | 88/93 | Source enum; owner/emitter unchanged. |
| 0000RQ | `by-global/g_pMiscWorkThread.md` | 85/89 | 87/91 | Source global pointer definition; owner/emitter unchanged. |
| 0001P8 | `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md` | 86/90 | 87/91 | No-duplicate storage comment; owner/emitter unchanged. |
| 00027S | `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md` | 85/90 | 88/91 | Source encoded data definition; owner/emitter unchanged. |
| 00029T | `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md` | 88/92 | 90/93 | Source static string object declaration; owner/emitter unchanged. |
| 0001CJ | `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md` | 87/90 | 87/90 or 88/91 optional | Keep body emitter; remove duplicate declarations after child pages emit. |

## Implementation Callback Results

Changed by-* docs:

- `by-file/MiscWorkThread.md`
- `by-class/MiscWorkThread.md`
- `by-type/by-enum/MiscWorkThreadMessageId.md`
- `by-class/httpget__Notification.md`
- `by-type/by-enum/HttpGetNotificationState.md`
- `by-class/ncauth__Notification.md`
- `by-type/by-enum/NcauthNotificationState.md`
- `by-global/g_pMiscWorkThread.md`
- `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md`
- `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md`
- `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`
- `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`

Report/log files updated in B008 folder:

- `tools/leaser/Agents/Agent-B008/research/0000LG-MiscWorkThread-empty-emitter-family-source-quality.md`
- `tools/leaser/Agents/Agent-B008/validation-logs/0000LG-implementation/*.log`
- `tools/leaser/Agents/Agent-B008/validation-logs/0000LG-implementation/summary.json`

Leases:

- Initial edit lease acquired as `B008` for the 12 by-* docs at `2026-07-01T19:33:00Z`, expiring `2026-07-01T19:38:00Z`. The edit batch was completed under that lease; the lease expired just as validation began. Cleanup reported `Rejected[No active lease]` for each file, confirming no active B008 lease remained.
- Validation-proof lease reacquired as `B008` for the same 12 docs before the proof validator rerun. Released immediately after the proof batch; `leaser.py B008 unlease ...` reported `Success` for all 12 files. `current_leases.md` has no `B008` entries.

Validator results:

| File | Command | Timestamp | Exit | ok | Generated refresh | Log |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-file/MiscWorkThread.md` | `000000003922` | `2026-07-01T15:42:23-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-file_MiscWorkThread.md.log` |
| `by-class/MiscWorkThread.md` | `000000003923` | `2026-07-01T15:42:35-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-class_MiscWorkThread.md.log` |
| `by-type/by-enum/MiscWorkThreadMessageId.md` | `000000003924` | `2026-07-01T15:42:45-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-type_by-enum_MiscWorkThreadMessageId.md.log` |
| `by-class/httpget__Notification.md` | `000000003925` | `2026-07-01T15:42:57-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-class_httpget__Notification.md.log` |
| `by-type/by-enum/HttpGetNotificationState.md` | `000000003927` | `2026-07-01T15:43:07-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-type_by-enum_HttpGetNotificationState.md.log` |
| `by-class/ncauth__Notification.md` | `000000003928` | `2026-07-01T15:43:18-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-class_ncauth__Notification.md.log` |
| `by-type/by-enum/NcauthNotificationState.md` | `000000003930` | `2026-07-01T15:43:31-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-type_by-enum_NcauthNotificationState.md.log` |
| `by-global/g_pMiscWorkThread.md` | `000000003931` | `2026-07-01T15:43:50-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-global_g_pMiscWorkThread.md.log` |
| `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md` | `000000003933` | `2026-07-01T15:44:00-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-memory_0x0067ab50-0x0067ab54.g_pMiscWorkThread.md.log` |
| `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md` | `000000003935` | `2026-07-01T15:44:19-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-memory_0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md.log` |
| `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md` | `000000003937` | `2026-07-01T15:44:39-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-memory_0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md.log` |
| `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md` | `000000003939` | `2026-07-01T15:44:58-04:00` | 0 | 1 | completed | `validation-logs/0000LG-implementation/by-memory_0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md.log` |

Non-fatal validator diagnostics were project-wide/generated-state diagnostics, not target blockers: repeated `autogen_children_marker_missing`, `autogen_children_fallback_insert`, `autogen_emitter_has_no_code`, generated metadata/report refresh notices, projected stats updates, and stats row removals/rescore recommendations for rows that left low-score lists. No scoped validator failed.

Generated output verification:

- Final inspected generated file: `auto-generated/NexusTK/app/MiscWorkThread.cpp`
- Header: `validator-command-id: 000000003948`, `validator-refreshed-at: 2026-07-01T15:46:09-04:00`, `validator-refresh-source: foreground-generated-refresh`
- Freshness: generated header is newer than the last scoped validator command `000000003939` / `2026-07-01T15:44:58-04:00`.
- Empty marker count: `0`
- Current count checks: `enum MiscWorkThreadMessageId` = `1`; `class MiscWorkThread` = `1`; `MiscWorkThread* g_pMiscWorkThread = 0;` = `1`; `g_ncauthConfirmUserUrlObfuscated[] =` = `1`; `SimpleUString g_ncauthConfirmUserUrlOverride;` appears once as the definition and once as the aggregate's later `extern` declaration.
- [UID:0001CJ] still emits worker/helper bodies and request wrappers; moved declarations now emit before it through dedicated pages.

## Claim And Incorporation Ledger

| Claim / item | Target path | Action | Verification state | Proof |
| --- | --- | --- | --- | --- |
| Generated baseline is fresh and has `12` total, `2` filled, `10` empty, `16.7%` filled. | `by-file/MiscWorkThread.md` | incorporate | applied | Added `## 2026-07-01 Generated Output Audit And Declaration Split` with command `000000003842`, refreshed `2026-07-01T15:24:09-04:00`, and `12/2/10/16.7%`; validated by command `000000003922`. |
| Source route is `NexusTK/app/MiscWorkThread.cpp`; rejected owners remain CashShop/PatchPane/Registration/MainMenu/MapPane/new auth file. | `by-file/MiscWorkThread.md` | incorporate | applied | Same section preserves the source route, declaration/body split, and rejected-owner policy; metadata updated to `89/90`; validator `000000003922` exit `0`, `ok:1`. |
| `MiscWorkThread` class declaration is source-bearing; method bodies belong to [UID:0001CJ]. | `by-class/MiscWorkThread.md` | incorporate | applied | Header updated to `90/91`, `EMITTER_POSITION_OPTIONAL:1`; formal class declaration with `[[CHILDREN]]` inserted; prose states [UID:0001CJ] remains method/helper body island; validator `000000003923` exit `0`, `ok:1`. |
| `MiscWorkThreadMessageId` enum is source-bearing and no longer blocked by original spelling. | `by-type/by-enum/MiscWorkThreadMessageId.md` | incorporate | applied | Header updated to `88/91`; formal enum inserted with exact values `0x42446972`, `0x47654874`, `0x4e434175`; prose records first-draft source disposition; validator `000000003924` exit `0`, `ok:1`. |
| `httpget::Notification` class declaration is source-bearing. | `by-class/httpget__Notification.md` | incorporate | applied | Header updated to `88/89`, `EMITTER_POSITION_OPTIONAL:2`; formal namespace/class C++ inserted with `[[CHILDREN]]`, constructor, destructor, fields; validator `000000003925` exit `0`, `ok:1`. |
| `HttpGetNotificationState` enum is source-bearing. | `by-type/by-enum/HttpGetNotificationState.md` | incorporate | applied | Header updated to `88/90`; formal five-value enum inserted; current status no longer says code must stay blank; validator `000000003927` exit `0`, `ok:1`. |
| `ncauth::Notification` class declaration is source-bearing. | `by-class/ncauth__Notification.md` | incorporate | applied | Header updated to `88/90`, `EMITTER_POSITION_OPTIONAL:3`; formal namespace/class C++ inserted with `[[CHILDREN]]`, constructor, empty destructor, field; validator `000000003928` exit `0`, `ok:1`. |
| `NcauthNotificationState` enum is source-bearing. | `by-type/by-enum/NcauthNotificationState.md` | incorporate | applied | Header updated to `88/93`; formal six-value enum inserted; current status records source-ready first draft; validator `000000003930` exit `0`, `ok:1`. |
| `g_pMiscWorkThread` is a source global definition. | `by-global/g_pMiscWorkThread.md` | incorporate | applied | Header updated to `87/91`, `EMITTER_POSITION_OPTIONAL:4`; formal `MiscWorkThread* g_pMiscWorkThread = 0;` plus `[[CHILDREN]]` inserted; validator `000000003931` exit `0`, `ok:1`. |
| Exact singleton storage child must not duplicate the pointer definition. | `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md` | incorporate | applied | Header updated to `87/91`; item summary/prose corrected to current `00 00 00 00`; formal no-duplicate storage comment inserted; validator `000000003933` exit `0`, `ok:1`. |
| NCA fallback URL bytes are source-bearing encoded data. | `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md` | incorporate | applied | Header updated to `88/91`, `EMITTER_POSITION_OPTIONAL:5`; exact 60-byte `extern const unsigned char g_ncauthConfirmUserUrlObfuscated[] = { ... };` inserted; validator `000000003935` exit `0`, `ok:1`. |
| NCA override string handle is a source static object declaration. | `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md` | incorporate | applied | Header updated to `90/93`, `EMITTER_POSITION_OPTIONAL:6`; formal `SimpleUString g_ncauthConfirmUserUrlOverride;` inserted; stale B002 no-code wording superseded; validator `000000003937` exit `0`, `ok:1`. |
| [UID:0001CJ] remains the worker/helper body emitter but should stop duplicating declarations moved to source pages. | `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md` | incorporate | applied | Removed duplicate `MiscWorkThreadMessageId`, `httpget::Notification`/state, and `ncauth::Notification`/state declarations; inserted routing comments; preserved worker/helper bodies, request wrappers, EventMan router wording, and notification ID enum; validator `000000003939` exit `0`, `ok:1`. |
| [UID:000012] `brdir::Notification` already emits source class declaration. | `by-class/brdir__Notification.md` | already-present | already-present | No edit made. Generated `MiscWorkThread.cpp` still emits [UID:000012] before [UID:0001CJ], with current header [UID:000012] `87/91`; no validator ordering issue appeared. |
| Manual coverage files and generated/tool/supervisor files are not B008 implementation targets. | `*-coverage-report.md`, `auto-generated/**`, validator/tool state, queues, archives, supervisor ledgers | not-applicable | excluded-with-reason | No manual edits were made to generated C++, generated reports, coverage reports, project-level generated reports, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB. Validator-owned generated files refreshed through scoped validators only. |

## Implementation Tracking Checklist

- [x] Edit `by-file/MiscWorkThread.md`: added generated-output audit baseline for `auto-generated/NexusTK/app/MiscWorkThread.cpp` command `000000003842`, refreshed `2026-07-01T15:24:09-04:00`, `12/2/10/16.7%`; added source declaration/body split; preserved rejected-owner policy; score updated to `89/90`. Proof: validator `000000003922`, exit `0`, `ok:1`.
- [x] Edit `by-class/MiscWorkThread.md`: set metadata to `COMPLETION:90`, `CONFIDENCE:91`, `EMITTER_POSITION_OPTIONAL:1`; added formal class declaration C++ with `[[CHILDREN]]`; stated method bodies remain [UID:0001CJ]-owned. Proof: validator `000000003923`, exit `0`, `ok:1`.
- [x] Edit `by-type/by-enum/MiscWorkThreadMessageId.md`: set metadata to `88/91`; added formal enum C++ for `kMiscWorkBrowseDirectory`, `kMiscWorkGetHttp`, `kMiscWorkNcaUpdate`; added prose that original spelling is inferred but no longer blocks first-draft source. Proof: validator `000000003924`, exit `0`, `ok:1`.
- [x] Edit `by-class/httpget__Notification.md`: set metadata to `88/89`, `EMITTER_POSITION_OPTIONAL:2`; added formal namespace/class C++ with `[[CHILDREN]]`; preserved state-owned payload destructor evidence and scalar-delete exclusion. Proof: validator `000000003925`, exit `0`, `ok:1`.
- [x] Edit `by-type/by-enum/HttpGetNotificationState.md`: set metadata to `88/90`; added formal `NotificationState` enum C++ with five exact values; updated current status/prose to source-ready first draft. Proof: validator `000000003927`, exit `0`, `ok:1`.
- [x] Edit `by-class/ncauth__Notification.md`: set metadata to `88/90`, `EMITTER_POSITION_OPTIONAL:3`; added formal namespace/class C++ with `[[CHILDREN]]`; preserved consumer/posting evidence and empty source destructor policy. Proof: validator `000000003928`, exit `0`, `ok:1`.
- [x] Edit `by-type/by-enum/NcauthNotificationState.md`: set metadata to `88/93`; added formal `NotificationState` enum C++ with six exact values; updated current status/prose to source-ready first draft. Proof: validator `000000003930`, exit `0`, `ok:1`.
- [x] Edit `by-global/g_pMiscWorkThread.md`: set metadata to `87/91`, `EMITTER_POSITION_OPTIONAL:4`; added formal `MiscWorkThread* g_pMiscWorkThread = 0;` plus `[[CHILDREN]]`; added zero-byte/xref proof and no-duplicate child route. Proof: validator `000000003931`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md`: set metadata to `87/91`; replaced stale item summary `0xffffffff` with current `00 00 00 00`; added formal no-duplicate storage comment; did not emit a second pointer definition. Proof: validator `000000003933`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md`: set metadata to `88/91`, `EMITTER_POSITION_OPTIONAL:5`; added exact formal encoded byte array for `g_ncauthConfirmUserUrlObfuscated`; preserved decoded URL and encoded-vs-plain rationale. Proof: validator `000000003935`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`: set metadata to `90/93`, `EMITTER_POSITION_OPTIONAL:6`; added formal `SimpleUString g_ncauthConfirmUserUrlOverride;`; preserved filename stability and semantic override-string naming. Proof: validator `000000003937`, exit `0`, `ok:1`.
- [x] Edit `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`: removed duplicate `MiscWorkThreadMessageId`, `httpget::Notification`, `HttpGetNotificationState`, `ncauth::Notification`, and `NcauthNotificationState` declaration blocks; inserted source-declaration routing comments; preserved worker/helper method bodies, request wrappers, EventMan router wording, and notification ID enum. Proof: validator `000000003939`, exit `0`, `ok:1`.
- [x] Confirm `by-class/brdir__Notification.md` remains already-present and does not need modification. Proof: generated output still emits [UID:000012] before [UID:0001CJ]; no validator ordering issue appeared.
- [x] Run validators with `--wait-generated` for every edited by-* doc. Proof: validator commands `000000003922`, `000000003923`, `000000003924`, `000000003925`, `000000003927`, `000000003928`, `000000003930`, `000000003931`, `000000003933`, `000000003935`, `000000003937`, and `000000003939`; all exit `0`, `ok:1`, generated refresh completed.
- [x] Inspect `auto-generated/NexusTK/app/MiscWorkThread.cpp`. Proof: final generated header command `000000003948`, refreshed `2026-07-01T15:46:09-04:00`, newer than last scoped validator; no empty markers remain for [UID:00008I], [UID:0001SP], [UID:000069], [UID:0001SN], [UID:00008X], [UID:0001SQ], [UID:0000RQ], [UID:0001P8], [UID:00027S], or [UID:00029T]; [UID:0001CJ] still emits worker/helper bodies; no duplicate enum/class/global/data definitions remain.
- [x] Do not edit generated reports, generated `auto-generated/NexusTK/**` C++, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB. Proof: only listed by-* docs, this B008 report, and B008 validation logs were manually edited/created; generated files changed only through validator refresh.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000LG-MiscWorkThread-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000LG-MiscWorkThread-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T15:54:25","uid":"0000LG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
