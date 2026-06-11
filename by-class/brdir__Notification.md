*** UID:000012 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# brdir::Notification

## Status

- Confidence: strong for object layout, construction sites, posting channel, and destructor behavior; medium for final source-file grouping.
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Current relevant ranges: browse helper `0x00527eb0-0x00527fdf`, BDir branch inside `0x00527fe0-0x005281a1`, request wrapper `0x005283b0-0x005283d5`, destructor `0x00528480-0x005284bb`, and vtable `0x0061fbb0`.

## Responsibility

`brdir::Notification` is the browse-directory result object posted by [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md). The object is allocated as `0x108` bytes, constructs an [UID:00007D][LObject](by-class/LObject.md) base, installs the `brdir::Notification` vtable, and stores an ANSI path buffer at offset `+4`.

## Layout

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | vtable | `brdir::Notification` vtable at `0x0061fbb0`; first slot points to `0x00528480`. |
| `+0x04` | path | ANSI path buffer populated by `SHGetPathFromIDListA`; canceled selection or conversion failure stores a leading NUL byte. |

## Important Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x00527eb0-0x00527fdf` | browse-directory helper | Initializes COM, shows `SHBrowseForFolderA`, constructs/posts a `brdir::Notification`, then restores cursor and uninitializes COM. |
| `0x00527fe0-0x005281a1` | `MiscWorkThread::ProcessWorkItem` BDir case | Inline browse-directory processing for message `0x42446972`; frees the request title payload after posting the result. |
| `0x00528480-0x005284bb` | `ScalarDeletingDestructor` | Calls `LObject` cleanup at `0x004f4a90` and optionally frees `this` through `0x004f4ac0` when scalar-delete flags request it. |

## Evidence

- 2026-06-04 live IDA MCP evidence from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`) confirms the browse helper at `0x00527eb0-0x00527fdf`, `ProcessWorkItem` at `0x00527fe0-0x005281a1`, and the destructor at `0x00528480-0x005284bb`.
- Both browse-directory construction paths allocate `0x108` bytes via `0x004f4aa0`, call the [UID:00007D][LObject](by-class/LObject.md) construction shell at `0x004f4a80`, install vtable `0x0061fbb0`, and call `SHGetPathFromIDListA` into object offset `+4`.
- Vtable xrefs are limited to the two construction stores at `0x00527f7b` and `0x00528133`; the vtable's first dword points to the scalar deleting destructor at `0x00528480`.
- Canceled folder selection or failed path conversion writes a NUL byte at offset `+4`.
- Notifications are posted with channel/message id `0x42446972` (`BDir`) through `0x004aa1d0`, which forwards to the application window message callback with message `0x406`.
- The raw request wrapper at `0x005283b0-0x005283d5` duplicates the browse-title argument, pushes FourCC `0x42446972`, and calls the thread async dispatch helper at `0x00596960`; IDA still does not model this aligned block as a function.

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
