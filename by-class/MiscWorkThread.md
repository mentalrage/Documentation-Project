*** UID:00008I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiscWorkThread

## Status

- Confidence: strong for class ownership, medium for original module placement.
- Current generated file: `source-3/simroot_v2/class_MiscWorkThread.cpp`
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Base class: [UID:0000EV][Thread](by-class/Thread.md)
- Current relevant range: `0x005277c0-0x005285dd`
- Evidence basis: `simroot_v2` generated source plus IDA MCP lookup/decompile/xref checks on 2026-05-24.

## Responsibility

`MiscWorkThread` is a singleton background worker for miscellaneous application tasks. It receives [UID:0000EV][Thread](by-class/Thread.md) queue messages, owns each request payload, performs the requested shell or WinInet operation, and posts a typed notification object back to the main application notification path.

## Key Data

- Singleton global: [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) at [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md).
- Vtable: `??_7MiscWorkThread@@6B@` at `0x0061fb74`.
- RTTI references include `MiscWorkThread` and `Singleton<MiscWorkThread>`.
- Object size in current construction path: `0x68` bytes.
- Worker base construction: `Thread::Thread(this, 100)`.

## Important Methods

| Address | Proposed name | Notes |
| --- | --- | --- |
| `0x00527fe0` | `ProcessWorkItem` | Handles browse-directory, HTTP get, NCA update, and falls back to `Thread::OnMessage`. |
| `0x005281b0` | `MiscWorkThread` | Constructs the [UID:0000EV][Thread](by-class/Thread.md) base, stores singleton, installs vtable, starts worker. |
| `0x00528230` | `~MiscWorkThread` | Stops worker, clears singleton, destroys base thread object. |
| `0x00528290` | `RequestHTTPGet` candidate | Allocates one `SimpleUString` payload and dispatches message `0x47654874`. |
| `0x00528310` | `RequestNCAUpdate` candidate | Allocates two adjacent `SimpleUString` payloads and dispatches message `0x4e434175`. |
| `0x005283b0` | `RequestBrowseDirectory` candidate | Raw aligned code start, duplicates an ANSI title/path and dispatches message `0x42446972`. |
| `0x005283e0` | `ClearSingleton` candidate | Clears `g_pMiscWorkThread`. |
| `0x005283f0` | `ScalarDeletingDestructor` | Stops worker, clears singleton, destroys base, optionally frees `this`. |

## Worker Messages

See [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md).

| Value | FourCC | Request payload | Posted notification |
| --- | --- | --- | --- |
| `0x42446972` | `BDir` | Heap ANSI title string | [UID:000012][brdir__Notification](by-class/brdir__Notification.md) |
| `0x47654874` | `GeHt` | One heap `SimpleUString` URL | [UID:000069][httpget__Notification](by-class/httpget__Notification.md) |
| `0x4e434175` | `NCAu` | Two adjacent heap `SimpleUString` values | [UID:00008X][ncauth__Notification](by-class/ncauth__Notification.md) |

## Ownership Notes

- `0x00528290`, `0x00528310`, and raw `0x005283b0` are not [UID:00001H][CashShopRequest](by-class/CashShopRequest.md) methods. They dispatch through `this` as a [UID:0000EV][Thread](by-class/Thread.md)-derived `MiscWorkThread`, and known callers obtain the object from [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md).
- The worker owns request payload cleanup. The main thread owns notification consumption after `PostNotification`.
- The base queue helpers at `0x00596960` and nearby belong to [UID:0000EV][Thread](by-class/Thread.md), not this class.
- 2026-06-01 IDA MCP confirms the class method starts and owner evidence: `ProcessWorkItem` at `0x00527fe0` size `0x1c1`, constructor at `0x005281b0` size `0x75`, destructor at `0x00528230` size `0x51`, request wrappers at `0x00528290` and `0x00528310`, raw browse-directory request wrapper bytes at `0x005283b0`, singleton clear helper at `0x005283e0`, and scalar deleting destructor at `0x005283f0`.
- Current xrefs to `0x0061fb74` show the `MiscWorkThread` vtable installed by constructor/destructor/scalar-delete paths, and xrefs to `0x0067ab50` show singleton writes plus application/feature consumers.

## Cross-References

- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md)
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- [UID:0000EV][Thread](by-class/Thread.md)
- [UID:00000D][Application](by-class/Application.md)
- [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md)

## Changes

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) because this class is 84/82 and the parent file is 86/84. Live IDA MCP on `NexusTK.exe` confirmed worker, constructor, destructor, request-wrapper, singleton-clear, and scalar-deleting starts at `0x00527fe0`, `0x005281b0`, `0x00528230`, `0x00528290`, `0x00528310`, `0x005283e0`, and `0x005283f0`; `0x005283b0` remains raw aligned code rather than an IDA function start and is not used as attachment proof.
- Before: the current relevant range was listed as `0x005277c0-0x005285dc`.
- Changed to: the range is `0x005277c0-0x005285dd`.
- Summary/evidence: 2026-05-28 IDA MCP shows the `PostNCAStatus` helper's final `retn` byte is at `0x005285dc`; the next padding starts at `0x005285dd`.
- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: the singleton worker thread has detailed responsibility, singleton/vtable/RTTI data, method map, worker-message IDs, notification classes, ownership caveats, and IDA evidence, but final original module placement and some request helper names remain medium confidence. Evidence: linked `MiscWorkThreadAndNotifications` range, `g_pMiscWorkThread`, `MiscWorkThreadMessageId`, Thread base construction, IDA lookup/decompile/xref checks, and payload cleanup/notification ownership notes.
- 2026-06-01: changed grading from `82/78` to `84/82`. Evidence: fresh IDA MCP lookup/caller/xref checks confirm constructor/application ownership, vtable and singleton lifecycle, request-wrapper consumers, and `Thread` queue dispatch. Confidence remains below very high because final request helper names and notification class source layout are still open.
