*** UID:000014 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# browser::Notification

## Summary

`browser::Notification` is the browser-specific notification payload type used by `PostBrowserNotification`. It carries browser notification data on the `'Bros'` notification channel and destroys its owned string/base-object state through compiler-generated destructor glue from the class declaration.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong

## Methods

| Range | Method/helper | Notes |
| --- | --- | --- |
| [UID:00033D][0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor](by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-generated wrapper; releases the string object at `+0x08`, destroys the [UID:00007D][LObject](by-class/LObject.md) base, and optionally frees `this` based on scalar-delete flags. Formal output is a no-hand-authored-wrapper marker, not a handwritten source body. |
| [UID:00033L][0x00470f20-0x00470fb9.PostBrowserNotification](by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md) | `PostBrowserNotification` | Source-ready first-draft helper; allocates the 12-byte payload, stores the value/state at `+0x04`, optionally copies a wide string into `+0x08`, and posts channel `0x42726f73` (`Bros`) through the inferred `PostApplicationNotification` route. |

## Layout

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | vtable | `browser::Notification` vtable at `0x006131f0`; first slot points to `0x00470740`. |
| `+0x04` | value/state | Set to `0` in the inline `Browser::Invoke` completion path; set from the first `PostBrowserNotification` argument in the helper path. |
| `+0x08` | string payload | Constructed by `0x00582b20`, optionally assigned from a wide string by `0x00582d20`, and released by the destructor through `0x00582b70`. |

## Evidence

- 2026-06-04 live IDA MCP evidence from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`) confirms `sub_470740` at `0x00470740-0x00470782` and `sub_470F20` at `0x00470f20-0x00470fb9`.
- `PostBrowserNotification` allocates 12 bytes via `0x004f4aa0`, calls the [UID:00007D][LObject](by-class/LObject.md) construction shell at `0x004f4a80`, installs vtable `0x006131f0`, constructs the string payload at `+0x08`, stores the first argument at `+0x04`, optionally assigns the string argument, and posts tag `1114795891` / `0x42726f73` (`Bros`) through the EventMan/Event.cpp notification router at `0x004aa1d0` (`EventMan::PostNotification` / `PostApplicationNotification`, exact spelling inferred).
- `Browser::Invoke` also constructs this payload inline for event case `104`: it allocates 12 bytes, installs the same vtable at `0x0046fa16`, constructs the `+0x08` string object, stores `0` at `+0x04`, and posts the same `Bros` channel.
- The `browser::Notification` vtable at `0x006131f0` has data refs only from the inline `Browser::Invoke` construction site `0x0046fa16` and `PostBrowserNotification` construction site `0x00470f6c`; its first slot is the destructor at `0x00470740`.
- The destructor calls `0x00582b70` on `this+0x08`, calls [UID:00007D][LObject](by-class/LObject.md) cleanup at `0x004f4a90`, and only calls `0x004f4ac0` when scalar-delete flags request object deletion.
- 2026-07-02 B011 MCP recheck resolves [UID:00033D][0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor](by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md) as compiler-generated scalar deleting destructor glue rather than a source-authored method body: the body has only string payload cleanup at `+0x08`, `LObject` base cleanup, scalar-delete flag tests, and optional object free for the 12-byte allocation. Source reconstruction should declare the class/base/member layout and let the compiler regenerate the wrapper.
- 2026-07-03 B011 UID00033L MCP recheck on session `b010_00032w_20260703` resolves [UID:00033L][0x00470f20-0x00470fb9.PostBrowserNotification](by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md) as source-ready first-draft helper code: `lookup_funcs` reports `sub_470F20` size `0x99`, `xrefs_to` finds only callers `0x0046f15d` and `0x0046fa81`, decompile/disassembly confirm 12-byte allocation, `LObject` construction, vtable `0x006131f0`, `+0x04` state store, nullable text copy into `+0x08`, and the `Bros` post through `0x004aa1d0`. `find_bytes` finds `Bros` only at inline Browser producer `0x0046fa34`, helper producer `0x00470fa0`, and ScreenPane consumer `0x00556f9a`.
- B001-024 exact children [UID:00033D][0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor](by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md) and [UID:00033L][0x00470f20-0x00470fb9.PostBrowserNotification](by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md) document the destructor and posting helper at `85/88` and `85/89`.

## Open Questions

- Final enum/value names for the `+0x04` field.
- Whether the inline `Browser::Invoke` state `0` and helper state `1` names matched explicit source constants or were simple boolean/status values.
- The unresolved `+0x04` names do not block [UID:00033D][0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor](by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md)'s no-code wrapper disposition because the destructor does not read or branch on that field.
- The unresolved `+0x04` enum/member spelling also no longer blocks [UID:00033L][0x00470f20-0x00470fb9.PostBrowserNotification](by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md)'s first-draft helper C++: state `0` is the inline Browser visible/download-complete notification path, state `1` is the helper current-url/new-window/shutdown notification path, and exact original names remain a score cap rather than a behavior blocker.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:000013][Browser](by-class/Browser.md)
- Memory: [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md), [UID:00033D][0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor](by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md), [UID:00033L][0x00470f20-0x00470fb9.PostBrowserNotification](by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md), [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- 2026-07-03 B011 UID00033L implementation callback:
  - Score unchanged at `85/88`.
  - Summary/evidence: synchronized the accepted [UID:00033L][0x00470f20-0x00470fb9.PostBrowserNotification](by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md) source-ready helper status. Current MCP session `b010_00032w_20260703` confirms the exact `0x00470f20-0x00470fb9` helper range, two callers from BrowserThread and Browser::Invoke, 12-byte `browser::Notification` allocation, vtable `0x006131f0`, state at `+0x04`, nullable wide text copy into `+0x08`, and `Bros` post through `0x004aa1d0`. Final enum/member/router spellings remain inferred and keep the class below final-audit scoring, but they no longer block UID00033L formal helper C++.
- 2026-07-02 B011 UID00033D implementation callback:
  - Score unchanged at `85/88`.
  - Summary/evidence: synchronized the accepted [UID:00033D][0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor](by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md) disposition. The scalar deleting destructor is compiler-generated wrapper glue for this class; live MCP confirms string payload cleanup at `+0x08`, [UID:00007D][LObject](by-class/LObject.md) base cleanup, scalar-delete optional object free, 12-byte object size, vtable slot `0x006131f0`, and producer refs from `PostBrowserNotification` plus inline Browser invoke case `104`. Formal output belongs on the exact child as a no-hand-authored-wrapper marker, while final `+0x04` state/value naming remains an unresolved class/helper question.
- 2026-06-10 B001-024 parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:88`, with destructor/posting ranges documented but no exact child pages.
  - Changed to: `COMPLETION:85`, linked exact children [UID:00033D][0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor](by-memory/0x00470740-0x00470782.BrowserNotificationScalarDeletingDestructor.md) and [UID:00033L][0x00470f20-0x00470fb9.PostBrowserNotification](by-memory/0x00470f20-0x00470fb9.PostBrowserNotification.md).
  - Summary/evidence: live IDA MCP confirms destructor `0x00470740-0x00470782`, helper `0x00470f20-0x00470fb9`, vtable `0x006131f0`, allocation size `12`, string payload at `+0x08`, value/state at `+0x04`, and `Bros` notification posting. This clears the strict `85/85` parent gate for assigning both children.
- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000HV][Browser](by-file/Browser.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the scalar deleting destructor and posting helper starts at `0x00470740` and `0x00470f20`; the class and parent both pass the historical 80/80 parent gate and now clear the strict 85/85 gate through the later B001-024 repair. No reconstruction C++ is emitted from this class page because the exact payload enum/value names and final class-level declaration remain unresolved; the destructor wrapper is now covered by a comment-only exact by-memory marker, while posting helper C++ remains separate follow-up.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:72` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the browser notification purpose, deleting destructor, `PostBrowserNotification` channel evidence, and browser memory/vtable references; completion remains moderate because payload fields and exact notification enum names are still open.
- 2026-06-04 live IDA evidence update:
  - What existed before: `COMPLETION:72` and `CONFIDENCE:78`, with stale generator-derived method evidence and open payload fields.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: live IDA confirms the exact destructor and posting-helper ranges, 12-byte object size, `LObject` construction/cleanup, vtable address and refs, `+0x04` value/state field, `+0x08` string payload lifecycle, inline `Browser::Invoke` construction site, and `Bros` posting path. Final C++ remains blank because the source enum/value names are still unproven.
- 2026-06-21 Rule 26 incorporation of B008 EventMan/factory helper report:
  - Score unchanged at `85/88`.
  - Summary/evidence: standardized the raw `0x004aa1d0` posting path as the EventMan/Event.cpp notification router, with exact method spelling still inferred.
