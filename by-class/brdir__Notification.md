*** UID:000012 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID:000012 | brdir::Notification source-level browse-directory payload.
// Emitted before UID:0001CJ so the MiscWorkThread aggregate can use this
// declaration without duplicating the class body.

#include <windows.h>

namespace brdir {

class Notification : public LObject {
public:
    virtual ~Notification()
    {
    }

    char m_path[MAX_PATH];
};

} // namespace brdir
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# brdir::Notification

## Status

- Confidence: very strong for object layout, construction sites, posting channel, EventMan router path, and destructor source policy; strong for [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) source-family placement.
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md) / `NexusTK/app/MiscWorkThread.cpp`.
- Current relevant ranges: browse helper `0x00527eb0-0x00527fdf`, BDir branch inside `0x00527fe0-0x005281a1`, request wrapper `0x005283b0-0x005283d5`, destructor `0x00528480-0x005284bb`, and vtable `0x0061fbb0`.
- Formal C++: source-facing class declaration is emitted here before the [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) aggregate to avoid duplicate `brdir::Notification` definitions.

## Responsibility

`brdir::Notification` is the browse-directory result object posted by [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md). The object is allocated as `0x108` bytes, constructs an [UID:00007D][LObject](by-class/LObject.md) base, installs the `brdir::Notification` vtable, and stores an ANSI `char m_path[MAX_PATH]` buffer at offset `+4`. It is a source-facing payload class in the `MiscWorkThread.cpp` local notification family, not compiler-only glue.

## Layout

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | vptr | `brdir::Notification` vtable at `0x0061fbb0`; `0x0061fbac` is the preceding RTTI locator. |
| `+0x04` | `char m_path[MAX_PATH]` | ANSI path buffer populated by `SHGetPathFromIDListA`; canceled selection or conversion failure stores a leading NUL byte. |

Allocation size is exactly `0x108`: `0x4` bytes for the [UID:00007D][LObject](by-class/LObject.md) vptr plus `0x104` bytes for Windows `MAX_PATH`. The shell path APIs are the ANSI variants (`SHBrowseForFolderA`, `SHGetPathFromIDListA`), and the [UID:0003MG][0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler](by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md) consumer treats payload offset `+4` as a byte string.

## Important Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x00527eb0-0x00527fdf` | retained browse-directory helper | Initializes COM, calls `ShowCursor(TRUE)`, builds `BROWSEINFOA` with `BIF_RETURNONLYFSDIRS`, shows `SHBrowseForFolderA`, constructs/posts a `brdir::Notification`, calls `ShowCursor(FALSE)`, and uninitializes COM. Raw PE scanning found no direct `call`/`jmp`/VA/RVA route to this start, so it is retained source-shaped helper code rather than the live public route. |
| `0x00527fe0-0x005281a1` | `MiscWorkThread::ProcessWorkItem` BDir case | Live worker route for message `0x42446972`; duplicates the helper browse flow, constructs/posts the same notification type, and frees the queued title payload after posting the result. |
| `0x005283b0-0x005283d5` | retained `MiscWorkThread::RequestBrowseDirectory(const char*)` wrapper | Raw/no-function wrapper that duplicates the caller title via `0x005deb99`, queues `0x42446972` through the [UID:0000EV][Thread](by-class/Thread.md) async helper `0x00596960`, and has no direct `call`/`jmp`/VA/RVA route in the scanned executable. |
| `0x00528480-0x005284bb` | scalar deleting destructor wrapper | Compiler-generated wrapper for a source-level empty virtual destructor; calls `LObject` cleanup at `0x004f4a90`, then optionally frees storage through `0x004f4ac0` or guarded/sized delete `0x0041b6a0` depending on delete flags. |

## Evidence

- 2026-06-04 live IDA MCP evidence from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`) confirms the browse helper at `0x00527eb0-0x00527fdf`, `ProcessWorkItem` at `0x00527fe0-0x005281a1`, and the destructor at `0x00528480-0x005284bb`.
- Both browse-directory construction paths allocate `0x108` bytes via `0x004f4aa0`, call the [UID:00007D][LObject](by-class/LObject.md) construction shell at `0x004f4a80`, install vtable `0x0061fbb0`, and call `SHGetPathFromIDListA` into object offset `+4`.
- Vtable xrefs are limited to the two construction stores at `0x00527f7b` and `0x00528133`; the vtable's first dword points to the scalar deleting destructor at `0x00528480`.
- Raw construction sites call the `LObject` constructor and then store vtable `0x0061fbb0`; neither construction path writes `m_path[0] = '\0'` before `SHGetPathFromIDListA`.
- Canceled folder selection or failed path conversion writes a NUL byte at offset `+4`; successful conversion writes the selected path directly into `m_path`.
- Notifications are posted with channel/message id `0x42446972` (`BDir`) through `0x004aa1d0`, now best documented as the EventMan/Event.cpp notification router (`EventMan::PostNotification` / `PostApplicationNotification`, exact spelling inferred). The helper forwards to the application window message callback with message `0x406`.
- The raw request wrapper at `0x005283b0-0x005283d5` duplicates the browse-title argument, pushes FourCC `0x42446972`, and calls the thread async dispatch helper at `0x00596960`; IDA still does not model this aligned block as a function.
- B011 raw PE reanalysis used `NexusTK.exe` SHA1 `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a` and found the retained browse helper body hash `5ea58c40944b48b2e156971a011bbe102e2808f2`, live BDir branch hash `2339eeafa3f0d62fc00be98b877b6fa0d897404d`, request-wrapper hash `fd020f35799dc51b51bb8cc1dc014a0c40e1852c`, and scalar-wrapper hash `53f1a0bdc1ee03b02111d317369f6e4e51216ec6`.
- The live BDir branch compares worker ids `0x42446972` (`BDir`), `0x47654874` (`GeHt`), and `0x4e434175` (`NCAu`), falling back to the [UID:0000EV][Thread](by-class/Thread.md) base handler for unknown ids. The class evidence does not rely on the retained helper being directly called.
- [UID:0003MG][0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler](by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md) independently confirms application-level consumption: it checks notification id `0x42446972`, reads the posted object pointer, and consumes the path at payload offset `+4`.
- [UID:0003C6][0x0061fbac-0x0061fbdc.WorkThreadNotificationVtableData](by-memory/0x0061fbac-0x0061fbdc.WorkThreadNotificationVtableData.md) records the corrected vtable shape: the object vptr value is `0x0061fbb0`, preceded by RTTI locator `0x0061fbac`, followed by scalar deleting destructor `0x00528480`, inherited `LObject` runtime-class accessor `0x004f4b10`, and inherited `LObject` no-op/default virtual `0x0041b6c0`.

## Source C++ Policy

Use a normal source declaration with an empty virtual destructor and no explicit constructor:

- Do not reconstruct scalar-delete flags, `0x004f4a90`, `0x004f4ac0`, or `0x0041b6a0` as handwritten destructor logic.
- Do not initialize `m_path[0]` in a constructor unless future raw evidence finds a separate inlined initializer. Current raw construction sites only write a leading NUL on cancel/failure.
- Keep this class emitted by [UID:000012] and keep [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md) from duplicating the class declaration.
- Preferred symbolic names are `kMiscWorkBrowseDirectory` for the queued worker request and `kBrowseDirectoryNotification` for the posted notification channel. They intentionally share numeric value `0x42446972`.

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md)

## Changes

- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the browse helper, BDir worker branch, and scalar deleting destructor starts at `0x00527eb0`, `0x00527fe0`, and `0x00528480`; IDA still reports raw request-wrapper offset `0x005283b0` as not a separate function, matching the existing raw-helper note. The class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the browse-directory notification role, object size/layout note, destructor method, worker allocation/path evidence, message id, and medium confidence on final source-file grouping.
- 2026-06-04 live IDA evidence update:
  - What existed before: `COMPLETION:76` and `CONFIDENCE:76`, with only generic worker allocation/path evidence and a generated-output file reference.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: live IDA confirms exact browse helper, `ProcessWorkItem` BDir branch, destructor range, vtable address and construction stores, `0x108` allocation, `+4` path buffer, fallback NUL write, posting path through `0x004aa1d0`, and raw request wrapper behavior. Final C++ remains blank because original helper names and source-file grouping are still below the reconstruction bar.
- 2026-06-21 Rule 26 incorporation of B008 EventMan/factory helper report:
  - Score unchanged at `84/88`.
  - Summary/evidence: standardized `0x004aa1d0` as the EventMan/Event.cpp notification router while preserving this class's MiscWorkThread payload ownership.
- 2026-06-21 Rule 26 incorporation of B011 brdir notification source-quality report:
  - Changed from: `COMPLETION:84`, `CONFIDENCE:88`, empty formal C++.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:91`, `EMITTER_POSITION_OPTIONAL:0`, with first-draft source-level class C++ emitted before the aggregate worker island.
  - Summary/evidence: B011 direct raw PE reanalysis confirmed the retained browse helper, live `ProcessWorkItem` BDir branch, raw retained request wrapper, scalar deleting destructor wrapper, exact `0x108` layout, ANSI `m_path[MAX_PATH]`, construction vptr stores at `0x00527f7b`/`0x00528133`, no constructor-time path zeroing, cancel/failure leading-NUL writes, EventMan router use through `g_pEventMan`/`0x004aa1d0`, MusicControlDialog consumption of payload `+4`, corrected three-slot `LObject`-compatible vtable shape, and empty source destructor policy.
