*** UID:000012 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# brdir::Notification

## Status

- Confidence: strong for notification role, medium for final source-file grouping.
- Current generated file: `source-3/simroot_v2/class_brdir__Notification.cpp`
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Current relevant range: `0x00527eb0-0x00528519`

## Responsibility

`brdir::Notification` is the browse-directory result object posted by [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md). The object is allocated as `0x108` bytes, constructs an [UID:00007D][LObject](by-class/LObject.md) base, installs the `brdir::Notification` vtable, and stores an ANSI path buffer at offset `+4`.

## Important Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00528480` | `ScalarDeletingDestructor` | Destroys the `LObject` base and optionally frees `this`. |

## Evidence

- Browse-directory worker paths allocate `0x108` bytes, write the notification vtable, and call `SHGetPathFromIDListA` into object offset `+4`.
- Canceled folder selection or failed path conversion writes a NUL byte at offset `+4`.
- Notifications are posted with channel/message id `0x42446972` (`BDir`).

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0001SP][MiscWorkThreadMessageId](by-type/by-enum/MiscWorkThreadMessageId.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:76` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the browse-directory notification role, object size/layout note, destructor method, worker allocation/path evidence, message id, and medium confidence on final source-file grouping.
