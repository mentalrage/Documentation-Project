** TARGET-REPORT-UID:000012 **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000012 brdir::Notification Source-Quality Report

Status: FINISHED
Agent: B011
Assignment: B011-goal2-brdir-notification-source-quality-000012-20260619
Date: 2026-06-19

## Target

- Target UID: [UID:000012] `brdir__Notification`
- Primary doc: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\brdir__Notification.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000LG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LG`
- Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B011\research\000012-brdir-Notification-source-quality.md`

## Recommendation Summary

Keep [UID:000012] source-bearing and keep owner/emitter [UID:0000LG] `MiscWorkThread`.

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:0000LG
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LG
```

The class is a real source-facing payload type, not no-code glue: `brdir::Notification` is allocated by the browse-directory helper path and by the live `MiscWorkThread::ProcessWorkItem` `BDir` branch, then posted to the EventMan/application notification router. The binary destructor at `0x00528480-0x005284bb` is MSVC scalar-deleting destructor glue for a source-level empty virtual destructor; do not reconstruct delete-flags logic in C++.

The class page is now first-draft C++ ready, with one implementation coordination point: [UID:0001CJ] currently emits an aggregate `MiscWorkThreadAndNotifications` draft containing a `brdir::Notification` declaration. Implementing a formal class block in [UID:000012] should be paired with aggregate de-duplication or the generated source will contain duplicate class definitions. The aggregate draft should also drop the currently modeled constructor `m_path[0] = 0`; raw construction sites do not perform constructor-time zeroing.

## Evidence Checked

Project/workflow evidence:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B011/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and support docs:

- `by-class/brdir__Notification.md` [UID:000012]
- `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md` [UID:0001CJ]
- `by-file/MiscWorkThread.md` [UID:0000LG]
- `by-class/MiscWorkThread.md` [UID:00008I]
- `by-type/by-enum/MiscWorkThreadMessageId.md` [UID:0001SP]
- `by-class/LObject.md` [UID:00007D]
- `by-memory/0x0061fbac-0x0061fbdc.WorkThreadNotificationVtableData.md` [UID:0003C6]
- `by-memory/0x0061fb74-0x0061fc04.WorkThreadNotificationReadOnlyData.md` [UID:00025X]
- `by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md` [UID:0001CK]
- `by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md` [UID:0003MG]
- `by-global/g_pMiscWorkThread.md`
- `by-memory/0x0067ab50-0x0067ab53.g_pMiscWorkThread.md`
- `by-memory/0x0067a754-0x0067a758.g_pEventMan.md`
- `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`
- Sibling notification class docs: `by-class/httpget__Notification.md`, `by-class/ncauth__Notification.md`
- Auto-generated output markers: `auto-generated/NexusTK/app/MiscWorkThread.cpp`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-memory-coverage.md`
- Prior accepted related research lead: `tools/leaser/Agents/Agent-B001/research/executed/0001CJ-MiscWorkThreadAndNotifications-source-quality.md`

IDA MCP evidence:

- Attempted MCP tool discovery at `http://127.0.0.1:13337/mcp`.
- Result: unavailable, `Unable to connect to the remote server`.
- Replacement evidence source: direct raw PE/Capstone analysis of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, plus current IDA-backed project docs.

Raw binary context:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- SHA1: `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
- Image base: `0x00400000`
- Relevant sections:
  - `.text`: `0x00401000-0x0060c600`
  - `.rdata`: `0x0060d000-0x0066c200`
  - `.data`: `0x0066d000-0x0069ce24`

## Direct Raw Findings

### Browse Helper Copy, `0x00527eb0-0x00527fdf`

Boundary and liveness:

- Range bytes SHA1: `5ea58c40944b48b2e156971a011bbe102e2808f2`
- No direct rel32 call hits to `0x00527eb0`.
- No direct rel32 jump hits to `0x00527eb0`.
- No absolute dword VA hits to `0x00527eb0`.
- Best policy: retained source-shaped helper copy, not a blocker for the class. It appears to be a private/static browse helper retained by the linker even though the live branch duplicates the same behavior inside `ProcessWorkItem`.

Behavior:

- Calls `CoInitialize`.
- Calls `ShowCursor(TRUE)`.
- Reads `g_pApplication` at `0x0067ab1c` and calls `0x004651d0`, best current name `Application::GetWindowHandle` or equivalent.
- Builds a stack `BROWSEINFOA` with caller-provided title and `ulFlags = 1`, high-probability `BIF_RETURNONLYFSDIRS`.
- Calls `SHBrowseForFolderA`.
- Allocates `0x108` bytes through `0x004f4aa0`.
- Calls `LObject` constructor `0x004f4a80`.
- Stores `brdir::Notification` vtable pointer `0x0061fbb0` at `0x00527f7b`.
- On successful browse result, calls `SHGetPathFromIDListA(pidl, notification + 4)`.
- On canceled browse or failed conversion, writes `notification->m_path[0] = '\0'`.
- Posts the notification with channel/request id `0x42446972` at call `0x00527faf`.
- Calls `ShowCursor(FALSE)` and `CoUninitialize`.

The class construction evidence is strong, but this helper copy has no direct route. Its no-route status should be documented as retained helper liveness, not as evidence that the class is no-code.

### Live BDir Branch in `MiscWorkThread::ProcessWorkItem`, `0x00527fe0-0x005281a1`

Boundary:

- Range bytes SHA1: `2339eeafa3f0d62fc00be98b877b6fa0d897404d`
- Function-level vtable/data pointer at `0x0061fba0` keeps `0x00527fe0` as the worker virtual method.

Dispatch:

- Compares work item id to `0x42446972` and branches to browse-directory handling at `0x00528098`.
- Compares to `0x47654874` for HTTP get.
- Compares to `0x4e434175` for NCA auth/update.
- Default path calls the Thread base/fallback handler at `0x00596920`.

Live BDir branch behavior:

- Uses the queued title payload at `[ebp+0xc]`.
- Performs the same shell browse flow as helper `0x00527eb0`.
- Allocates `0x108`, calls `LObject` constructor `0x004f4a80`, stores vtable `0x0061fbb0` at `0x00528133`.
- Calls `SHGetPathFromIDListA` into `notification + 4` on success.
- Writes a leading NUL to `notification + 4` only on cancel/failure.
- Posts channel `0x42446972` via `0x004aa1d0` at `0x00528167`.
- Frees the queued title payload through `0x005d3547`.

This is the live source route that justifies keeping [UID:000012] reconstructable and owned by [UID:0000LG].

### Raw Request Wrapper, `0x005283b0-0x005283d5`

Boundary and liveness:

- Range bytes SHA1: `fd020f35799dc51b51bb8cc1dc014a0c40e1852c`
- No direct rel32 call hits to `0x005283b0`.
- No direct rel32 jump hits to `0x005283b0`.
- No absolute dword VA hits to `0x005283b0`.
- It is nevertheless source-shaped and belongs with `MiscWorkThread`, not with CashShop. The old CashShop label is already corrected by [UID:0001CK].

Disassembly shape:

```asm
005283b0  push ebp
005283b1  mov ebp, esp
005283b3  push esi
005283b4  push 0
005283b6  push dword ptr [ebp+8]
005283b9  mov esi, ecx
005283bb  call 0x005deb99
005283c0  add esp, 4
005283c3  mov ecx, esi
005283c5  push eax
005283c6  push 0x42446972
005283cb  call 0x00596960
005283d0  pop esi
005283d1  pop ebp
005283d2  ret 4
```

Best source-facing name:

```cpp
void MiscWorkThread::RequestBrowseDirectory(const char* title);
```

The wrapper duplicates the ANSI title string through `0x005deb99`, then queues a `0x42446972` work item through Thread async helper `0x00596960`. It appears retained/unreferenced in this build, but its behavior exactly matches the live `BDir` branch and should remain in the MiscWorkThread source island.

### Scalar Deleting Destructor, `0x00528480-0x005284bb`

Boundary:

- Range bytes SHA1: `53f1a0bdc1ee03b02111d317369f6e4e51216ec6`
- Vtable slot reference: `0x0061fbb0 -> 0x00528480`

Disassembly shape:

```asm
00528480  push ebp
00528481  mov ebp, esp
00528483  push esi
00528484  mov esi, ecx
00528486  call 0x004f4a90
0052848b  mov eax, dword ptr [ebp+8]
0052848e  test al, 1
00528490  je 0x005284b4
00528492  test al, 4
00528494  jne 0x005284a6
00528496  push esi
00528497  call 0x004f4ac0
005284a6  push 0x108
005284ab  push esi
005284ac  call 0x0041b6a0
005284b8  ret 4
```

Policy:

- Do not reconstruct the scalar deleting destructor body as handwritten C++.
- The source-level destructor should be an empty virtual destructor.
- `0x004f4a90` is the `LObject` destructor/base cleanup.
- `0x004f4ac0` is the ordinary object free path.
- `0x0041b6a0` is the guarded/sized delete path selected by scalar delete flags.
- There is no path buffer cleanup, no owned heap payload, and no source-authored destructor logic beyond permitting virtual destruction.

### Vtable and Read-Only Data

Raw vtable dwords:

```text
0x0061fbac -> 0x0064c488   brdir RTTI locator
0x0061fbb0 -> 0x00528480   brdir scalar deleting destructor
0x0061fbb4 -> 0x004f4b10   inherited LObject runtime-class accessor
0x0061fbb8 -> 0x0041b6c0   inherited LObject default no-op virtual
0x0061fbbc -> 0x0064c4d4   httpget RTTI locator
0x0061fbc0 -> 0x005284c0   httpget scalar deleting destructor
0x0061fbc4 -> 0x004f4b10   inherited LObject runtime-class accessor
0x0061fbc8 -> 0x0041b6c0   inherited LObject default no-op virtual
0x0061fbcc -> 0x0064c520   ncauth RTTI locator
0x0061fbd0 -> 0x00528520   ncauth scalar deleting destructor
0x0061fbd4 -> 0x004f4b10   inherited LObject runtime-class accessor
0x0061fbd8 -> 0x0041b6c0   inherited LObject default no-op virtual
```

Important support-doc correction:

- [UID:0003C6] currently describes these as "one-slot vtables." That wording is inaccurate for the emitted objects. Each notification vtable has a scalar deleting destructor slot plus inherited `LObject` runtime-class/no-op virtual slots after the RTTI locator.
- Keep `0x0061fbb0` as the `brdir::Notification` vtable start used by object vptr stores. `0x0061fbac` is the RTTI locator word preceding the vtable.

### FourCC / Message Id

Raw constant facts:

- `0x42446972` decimal: `1111779698`
- Little-endian bytes render as `riDB`; current docs correctly use source-facing FourCC display `BDir`.
- `0x42446972` appears in the browse helper post, `ProcessWorkItem` compare/post path, raw request wrapper queue call, and `MusicControlDialog` consumer.

Best source names:

- Request/work item id: `kMiscWorkBrowseDirectory` or `kWorkBrowseDirectory`.
- Posted notification id: `kBrowseDirectoryNotification`.
- If the project keeps one enum for both request and notification ids, retaining the existing `BDir` label is acceptable. If it splits worker requests and app notifications, use the same numeric value with separate source names.

### Layout

Best current class layout:

```text
brdir::Notification : LObject
+0x000 vptr
+0x004 char m_path[MAX_PATH]
sizeof = 0x108
```

Evidence:

- Allocation size is exactly `0x108`.
- LObject/vptr occupies `0x4`.
- `SHGetPathFromIDListA` destination is `this + 4`.
- `0x108 - 0x4 = 0x104`, matching Windows `MAX_PATH`.
- The object is ANSI, not wide-character: Shell APIs are `SHBrowseForFolderA` and `SHGetPathFromIDListA`, and the consumer treats the payload path as a byte string.

Constructor-zeroing correction:

- Raw construction sites call `LObject` constructor and store the brdir vtable.
- Neither construction site writes `m_path[0] = '\0'` before calling `SHGetPathFromIDListA`.
- Leading-NUL write happens only on cancel or failed path conversion.
- Therefore the aggregate draft in [UID:0001CJ] should not keep `Notification() { m_path[0] = 0; }` unless new evidence finds a separate inlined source initializer. The best source shape is no explicit constructor or an empty default constructor.

### Posting Path and Consumer

Producer:

- Both producer paths call `0x004aa1d0` with `ecx = [0x0067a754]`, not `[0x0067ab1c]`.
- `by-memory/0x0067a754-0x0067a758.g_pEventMan.md` identifies `0x0067a754` as `g_pEventMan`.
- Current aggregate wording that routes this through `g_pApplication->PostNotification` is therefore too specific and likely wrong for this call site.

Best helper name:

- `EventMan::PostNotification`, `EventMan::PostNotificationToHandlers`, or a similarly EventMan-owned notification router name.
- Keep a caveat if the exact method name is not yet proven, but do not continue calling the callee `Application::PostNotification` without noting the actual global register source.

Consumer:

- [UID:0003MG] `MusicControlDialogDirectoryPacketHandler` checks notification id `0x42446972`.
- The consumer reads the posted payload pointer and uses payload offset `+4` as the path.
- This independently confirms that `brdir::Notification` is an application notification payload, not only an internal worker request.

## Ownership and Source Placement Ranking

1. Keep `MiscWorkThread` / `NexusTK/app/MiscWorkThread.cpp` as canonical owner and emitter [UID:0000LG].
   - Strong evidence: worker request wrapper queues `BDir`, live `ProcessWorkItem` handles `BDir`, both shell browse producers allocate/post `brdir::Notification`, and the aggregate source island already emits the worker/notification family.
   - The current proposed source tree places [UID:0000LG] under `NexusTK/app/`, which remains the best grouping.

2. Browse-directory helper file.
   - Rejected as primary owner. The shell browse helper behavior is real, but the helper is in the MiscWorkThread source island and has no independent file/class evidence. The live route is inside `MiscWorkThread::ProcessWorkItem`.

3. `LObject`.
   - Rejected. `LObject` supplies base ctor/dtor and inherited vtable slots only. It does not own the browse payload fields or worker request routing.

4. No-owner/non-emitting.
   - Rejected. The class is allocated, vtable-stored, posted, and consumed by live routes. Only the scalar deleting destructor body is no-code glue.

5. Split child rows.
   - Not warranted for [UID:000012]. Existing [UID:0001CJ] covers the memory island, [UID:0003C6]/[UID:00025X] cover read-only data, and the class page is the correct source-quality surface.
   - A future exact by-memory child for `0x00528480` could be useful as a compiler-glue row, but it is not required to settle the class page.

## First-Draft C++ Recommendation

Recommended source-level class shape:

```cpp
namespace brdir {

class Notification : public LObject {
public:
    virtual ~Notification()
    {
    }

    char m_path[MAX_PATH];
};

} // namespace brdir
```

Notes for implementation:

- This is source-bearing C++, not a no-code proof.
- Do not include scalar-delete flags or direct calls to `0x004f4a90`, `0x004f4ac0`, or `0x0041b6a0` in formal C++.
- Prefer no explicit constructor. If the style requires one, make it empty. Do not initialize `m_path[0]` in the constructor unless new evidence appears.
- If formal C++ is added to [UID:000012], adjust [UID:0001CJ] so the generated file does not duplicate the class declaration. The best implementation is to move the `brdir::Notification` declaration to [UID:000012] and make [UID:0001CJ] use it.

Recommended source-level worker helpers for support docs:

```cpp
void MiscWorkThread::RequestBrowseDirectory(const char* title)
{
    DispatchRequest(kMiscWorkBrowseDirectory, DuplicateCString(title));
}

static void BrowseForDirectoryAndPost(const char* title)
{
    // source-shaped retained helper; no direct route found in this build
}
```

For the live branch inside `MiscWorkThread::ProcessWorkItem`, use the same browse/post helper logic and then free the queued title payload. The exact helper factoring in original source may have been duplicated/inlined, but the class shape and notification layout are not blocked by that uncertainty.

## Open Questions and Resolutions

### Exact source name for `0x004aa1d0`

Resolution: partially resolved with stronger direction.

Evidence checked:

- Raw call sites for browse posting load `ecx` from `0x0067a754`.
- `0x0067a754` support doc identifies the global as `g_pEventMan`.
- There are 12 rel32 calls to `0x004aa1d0`, including browse producer calls at `0x00527faf` and `0x00528167`.

Best direction:

- Use EventMan-owned naming, not Application-owned naming, for this callee in brdir support text.
- Recommended descriptive name: `EventMan::PostNotification`.
- Remaining uncertainty: exact original method name still needs the `0x004aa1d0` function page or type recovery if available.

Impact:

- This does not block [UID:000012] because it affects router naming, not class layout or ownership.

### Exact helper factoring between `0x00527eb0` and the `ProcessWorkItem` BDir branch

Resolution: high-probability source direction.

Evidence checked:

- `0x00527eb0` has no static start refs.
- The live `ProcessWorkItem` branch duplicates the helper behavior.
- Raw request wrapper queues work for the live branch, not the helper copy.

Best direction:

- Document `0x00527eb0` as retained `BrowseForDirectoryAndPost` or equivalent private helper.
- Document the `ProcessWorkItem` branch as the live source path.
- Do not treat helper no-route as a class no-code blocker.

### Constructor shape

Resolution: corrected.

Evidence checked:

- Both allocation paths: allocate `0x108`, call `LObject` ctor, store vtable, then perform shell path conversion or failure NUL.
- No constructor-time `m_path[0] = 0` write exists in either path.

Best direction:

- Source class should have no explicit constructor or an empty constructor.
- Remove/adjust aggregate [UID:0001CJ] draft constructor that zeroes the path.

### Destructor shape

Resolution: corrected.

Evidence checked:

- Vtable slot points to `0x00528480`.
- Body has scalar delete flags, base destructor call, optional free paths, and no payload cleanup.

Best direction:

- Source class gets `virtual ~Notification() {}`.
- The binary body remains documented as compiler-generated scalar deleting destructor glue.

### Vtable shape

Resolution: corrected.

Evidence checked:

- Raw dword dump of `0x0061fbac-0x0061fbdc`.
- `LObject` support doc for inherited runtime/no-op virtuals.

Best direction:

- [UID:0003C6] should replace "one-slot vtables" with a three-slot LObject-compatible vtable explanation for each notification class.

## Exact Recommended Doc Changes

### `by-class/brdir__Notification.md` [UID:000012]

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:0000LG
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LG
```

Recommended content updates:

- Replace stale below-95/no-C++ gate language with current 85/85 source-readiness analysis.
- State `brdir::Notification` is a source-facing `LObject` payload class in the `MiscWorkThread.cpp` source island.
- State layout: vptr `+0`, `char m_path[MAX_PATH]` at `+4`, `sizeof = 0x108`.
- State construction evidence:
  - `0x00527f7b` helper path vtable store.
  - `0x00528133` live `ProcessWorkItem` BDir branch vtable store.
  - no constructor-time path zeroing.
  - cancel/failure writes `m_path[0] = '\0'`.
- State `0x42446972` is source-facing `BDir`; use `kMiscWorkBrowseDirectory` / `kBrowseDirectoryNotification` as recommended names.
- State raw `0x005283b0-0x005283d5` is retained no-route `MiscWorkThread::RequestBrowseDirectory(const char*)`.
- State scalar deleting destructor `0x00528480-0x005284bb` is compiler-generated from an empty virtual destructor.
- State posting currently routes through `g_pEventMan` at `0x0067a754` into `0x004aa1d0`, so EventMan-owned naming is preferred over Application-owned naming.
- Add first-draft C++ block, coordinated with [UID:0001CJ] de-duplication.

### `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md` [UID:0001CJ]

Recommended support updates:

- Adjust the aggregate brdir class declaration to match the class-page source shape.
- Remove `Notification() { m_path[0] = 0; }` for `brdir::Notification` or mark it as not supported by current raw evidence.
- If [UID:000012] receives the formal class C++ block, remove/defer the duplicate class declaration in the aggregate generated C++ or convert the aggregate to use the class-page definition.
- Replace `g_pApplication->PostNotification` style wording for browse notification producers with an EventMan router note: raw callers load `ecx` from `g_pEventMan` (`0x0067a754`) before `0x004aa1d0`.
- Preserve the accepted B001 source island facts for HTTP/NCA and worker helper boundaries.

### `by-file/MiscWorkThread.md` [UID:0000LG]

Recommended support updates:

- Keep source path `NexusTK/app/MiscWorkThread.cpp`.
- Add/refresh a note that `brdir::Notification` is a local source-family notification payload class, not compiler-only glue.
- Note raw retained `RequestBrowseDirectory` at `0x005283b0` remains no-route but source-shaped.
- Update stale "final source path, wrapper/helper names, and notification-class nesting remain provisional" coverage language: source file grouping and brdir notification class shape are now high-confidence, though exact router method name remains a caveat.

### `by-class/MiscWorkThread.md` [UID:00008I]

Recommended support updates:

- Under request wrappers, state `RequestBrowseDirectory(const char*)` duplicates the title and queues `BDir` through Thread async helper `0x00596960`, but no direct static caller/reference was found.
- Under `ProcessWorkItem`, state the live `BDir` branch constructs and posts `brdir::Notification`.
- Use EventMan/router naming caveat for `0x004aa1d0`.

### `by-type/by-enum/MiscWorkThreadMessageId.md` [UID:0001SP]

Recommended support updates:

- Keep `0x42446972` displayed as `BDir`.
- Add that the same value appears in raw wrapper queueing, `ProcessWorkItem` dispatch, notification posting, and `MusicControlDialog` consumption.
- If introducing source names, prefer `kMiscWorkBrowseDirectory` for queued work and `kBrowseDirectoryNotification` for posted app notification, with shared numeric value.

### `by-memory/0x0061fbac-0x0061fbdc.WorkThreadNotificationVtableData.md` [UID:0003C6]

Recommended support updates:

- Replace "one-slot vtable" wording.
- Document brdir/httpget/ncauth vtables as LObject-compatible three-slot vtables after the RTTI locator:
  - scalar deleting destructor
  - inherited `LObject` runtime-class accessor `0x004f4b10`
  - inherited `LObject` no-op/default virtual `0x0041b6c0`
- Keep `0x0061fbb0` as the brdir vptr value and `0x0061fbac` as preceding RTTI locator.

### `by-memory/0x0061fb74-0x0061fc04.WorkThreadNotificationReadOnlyData.md` [UID:00025X]

Recommended support updates:

- Ensure brdir vtable refs remain listed at `0x00527f7b` and `0x00528133`.
- If this doc repeats "one-slot vtable" language, change to the corrected LObject-compatible slot layout.

### `by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md` [UID:0001CK]

Recommended support updates:

- Preserve the stale-CashShop rejection.
- Optionally strengthen `0x005283b0` wording: raw retained `MiscWorkThread::RequestBrowseDirectory(const char*)`, no direct call/jmp/VA/RVA refs found, queues `0x42446972` through `Thread::DispatchRequest`/`0x00596960`.

## Coverage Report Text

Do not edit `by-memory/-coverage-report.md` for this assignment.

No by-memory coverage replacement is required for the brdir class page itself; [UID:0001CJ] already carries the aggregate memory-island row. If implementation changes [UID:0001CJ] scoring, the supervisor should provide a separate memory coverage update.

Recommended exact replacement row for `by-class/-coverage-report.md`:

```text
- [UID:000012][brdir__Notification](by-class/brdir__Notification.md) : reconstructable : 87% : very strong : B011 2026-06-19 source-quality pass confirms `brdir::Notification` as a `MiscWorkThread.cpp` local `LObject` notification payload with vptr at `+0`, `char m_path[MAX_PATH]` at `+4`, allocation size `0x108`, construction stores at `0x00527f7b` and `0x00528133`, no constructor-time path zeroing, cancel/failed `SHGetPathFromIDListA` leading-NUL writes, `BDir`/`0x42446972` request and notification channel, live `ProcessWorkItem` BDir branch, retained no-route browse helper `0x00527eb0`, raw retained no-route `RequestBrowseDirectory` wrapper `0x005283b0`, vtable `0x0061fbb0` with scalar deleting destructor plus inherited `LObject` runtime/no-op slots, empty source destructor policy for scalar wrapper `0x00528480`, EventMan-style post helper path through `g_pEventMan`/`0x004aa1d0`, and first-draft class C++ readiness with duplicate-emission coordination against [UID:0001CJ].
```

Recommended exact replacement row for `by-file/-coverage-report.md` if [UID:0000LG] support text is refreshed:

```text
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) : reconstructable : 88% : strong : MiscWorkThread source module under `NexusTK/app/MiscWorkThread.cpp`; B001/B011 source-quality passes resolve source-facing names for `FetchHTTPContent`, `ProcessNCAUpdate`, `BrowseForDirectoryAndPost`, `ProcessWorkItem`, `RequestHTTPGet`, `RequestNCAUpdate`, raw retained `RequestBrowseDirectory`, and `PostNCAStatus`; direct raw PE evidence shows browse helper `0x00527eb0` and raw wrapper `0x005283b0` have no call/jmp/VA/RVA start refs while live HTTP/NCA wrappers have callers and `ProcessWorkItem` is vtable-routed; notification classes `brdir`/`httpget`/`ncauth` are local source-family payloads; request FourCCs/channels, notification layouts/lifetimes, PatchPane2/MusicControlDialog/NexonclubRegistration consumers, stale CashShop rejection, and first-draft aggregate C++ are documented.
```

## Validation Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

Minimum target/class coverage validation:

> Executable block R001 was removed from this report and preserved verbatim in [000012-brdir-Notification-source-quality-removed.md](000012-brdir-Notification-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If applying the recommended support-doc corrections:

> Executable block R002 was removed from this report and preserved verbatim in [000012-brdir-Notification-source-quality-removed.md](000012-brdir-Notification-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Autogen validation is required if the formal class C++ is moved from [UID:0001CJ] to [UID:000012], because generation order/de-duplication must be checked.

## IDA Rename / Type / Comment Recommendations

High confidence:

- `0x0061fbb0`: `brdir::Notification::vftable`
- `0x00528480`: `brdir::Notification::scalar_deleting_destructor` with comment "compiler-generated; source destructor is empty virtual destructor"
- `0x005283b0`: `MiscWorkThread::RequestBrowseDirectory` or `MiscWorkThread_RequestBrowseDirectory_retained`
- `0x00527eb0`: `BrowseForDirectoryAndPost` or `BrowseForDirectoryAndPost_retained_no_route`
- `brdir::Notification + 0x4`: `m_path`, type `char[MAX_PATH]`
- `0x42446972`: `BDir` / `kMiscWorkBrowseDirectory`

Medium confidence:

- `0x004aa1d0`: `EventMan::PostNotification` or equivalent EventMan notification-router name. Evidence supports EventMan ownership, but exact original method spelling is not proven.
- `0x004651d0`: application window-handle accessor used for `BROWSEINFOA::hwndOwner`.
- `0x00596960`: Thread async request dispatch helper; exact source name still should follow the Thread support docs if already named elsewhere.

Do not rename:

- Do not label `0x00528480` as the source-authored `brdir::Notification::~Notification()` body without a compiler-glue caveat. It is the scalar deleting wrapper.

## Remaining Issues and Impact

- Exact original name of `0x004aa1d0` remains unresolved. Impact is limited to helper naming in support docs. Raw evidence strongly supports EventMan/router ownership through `g_pEventMan`.
- Exact original helper factoring for shell browse code remains unresolved because `0x00527eb0` is retained no-route while the live branch duplicates behavior. Impact is low for [UID:000012]; both paths construct the same class with the same layout and posting semantics.
- Emission de-duplication must be handled carefully. [UID:0001CJ] currently emits a class declaration for `brdir::Notification`; adding the same declaration to [UID:000012] without aggregate adjustment will duplicate generated C++.

These issues do not block raising [UID:000012] to `87/91`, keeping owner/emitter [UID:0000LG], and adding first-draft source-level C++ for the class.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/000012-brdir-Notification-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"000012"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000012-brdir-Notification-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/000012-brdir-Notification-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000012"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
