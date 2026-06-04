*** UID:000014 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# browser::Notification

## Summary

`browser::Notification` is the browser-specific notification payload type used by `PostBrowserNotification`. It carries browser notification data on the `'Bros'` notification channel and destroys its owned string/base-object state in the deleting destructor.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong

## Methods

| Range | Method/helper | Notes |
| --- | --- | --- |
| `0x00470740-0x00470782` | scalar deleting destructor | Releases the string object at `+0x08`, destroys the [UID:00007D][LObject](by-class/LObject.md) base, and optionally frees `this` based on scalar-delete flags. |
| `0x00470f20-0x00470fb9` | `PostBrowserNotification` | Allocates the 12-byte payload, stores the value/state at `+0x04`, optionally copies a wide string into `+0x08`, and posts channel `0x42726f73` (`Bros`). |

## Layout

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | vtable | `browser::Notification` vtable at `0x006131f0`; first slot points to `0x00470740`. |
| `+0x04` | value/state | Set to `0` in the inline `Browser::Invoke` completion path; set from the first `PostBrowserNotification` argument in the helper path. |
| `+0x08` | string payload | Constructed by `0x00582b20`, optionally assigned from a wide string by `0x00582d20`, and released by the destructor through `0x00582b70`. |

## Evidence

- 2026-06-04 live IDA MCP evidence from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`) confirms `sub_470740` at `0x00470740-0x00470782` and `sub_470F20` at `0x00470f20-0x00470fb9`.
- `PostBrowserNotification` allocates 12 bytes via `0x004f4aa0`, calls the [UID:00007D][LObject](by-class/LObject.md) construction shell at `0x004f4a80`, installs vtable `0x006131f0`, constructs the string payload at `+0x08`, stores the first argument at `+0x04`, optionally assigns the string argument, and posts tag `1114795891` / `0x42726f73` (`Bros`) through `0x004aa1d0`.
- `Browser::Invoke` also constructs this payload inline for event case `104`: it allocates 12 bytes, installs the same vtable at `0x0046fa16`, constructs the `+0x08` string object, stores `0` at `+0x04`, and posts the same `Bros` channel.
- The `browser::Notification` vtable at `0x006131f0` has data refs only from the inline `Browser::Invoke` construction site `0x0046fa16` and `PostBrowserNotification` construction site `0x00470f6c`; its first slot is the destructor at `0x00470740`.
- The destructor calls `0x00582b70` on `this+0x08`, calls [UID:00007D][LObject](by-class/LObject.md) cleanup at `0x004f4a90`, and only calls `0x004f4ac0` when scalar-delete flags request object deletion.

## Open Questions

- Final enum/value names for the `+0x04` field.
- Whether the inline `Browser::Invoke` state `0` and helper state `1` names matched explicit source constants or were simple boolean/status values.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:000013][Browser](by-class/Browser.md)
- Memory: [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md), [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the browser notification purpose, deleting destructor, `PostBrowserNotification` channel evidence, and browser memory/vtable references; completion remains moderate because payload fields and exact notification enum names are still open.
- 2026-06-04 live IDA evidence update:
  - What existed before: `COMPLETION:72` and `CONFIDENCE:78`, with stale generator-derived method evidence and open payload fields.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: live IDA confirms the exact destructor and posting-helper ranges, 12-byte object size, `LObject` construction/cleanup, vtable address and refs, `+0x04` value/state field, `+0x08` string payload lifecycle, inline `Browser::Invoke` construction site, and `Bros` posting path. Final C++ remains blank because the source enum/value names are still unproven.
