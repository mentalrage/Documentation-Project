*** UID:0002W3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0002W3] by-global/g_pDeleteReplyAlert.md
class DeleteReplyAlert;

DeleteReplyAlert *g_pDeleteReplyAlert = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pDeleteReplyAlert

## Status

- Address: `0x0067adb8`
- Storage page: [UID:0002W4][0x0067adb8-0x0067adbc.g_pDeleteReplyAlert](by-memory/0x0067adb8-0x0067adbc.g_pDeleteReplyAlert.md)
- Type hypothesis: `DeleteReplyAlert *`
- Owner: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- Confidence: very strong for address, exact source definition, class owner, constructor/destructor/getter lifecycle, and one-definition emission; the final historical physical-file split remains inferred.

## Evidence

The slot stores the active [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) instance. 2026-06-16 live IDA MCP recheck reads the current board/mail singleton window as zero-filled virtual `.data`, confirms six refs to this slot, and saved the `g_pDeleteReplyAlert` data label. The later source-closure pass maps those roles to exact children: [UID:0004WC][0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor](by-memory/0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor.md) writes `this`, [UID:0004WD][0x0047e350-0x0047e379.DeleteReplyAlertDestructor](by-memory/0x0047e350-0x0047e379.DeleteReplyAlertDestructor.md) clears it, and [UID:0004WE][0x0047e380-0x0047e386.DeleteReplyAlertGetSingleton](by-memory/0x0047e380-0x0047e386.DeleteReplyAlertGetSingleton.md) returns it. Compiler-only [UID:0003Q6][0x0047eb30-0x0047eb8f.DeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb30-0x0047eb8f.DeleteReplyAlertScalarDeletingDestructor.md) repeats teardown as an ABI consequence rather than a second source writer.

[UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) identifies UID0004WE as the exact static singleton getter and documents the board/article reply-list delete behavior. Article-list response callers test the live pointer before constructing another reply-delete alert. [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md) records the original adjacent pair and the split rationale.

## Assignment Gate

This global is attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), raised by the callback to `90/92`. The relationship is direct because that file page owns the shared reply/delete alert wrapper bucket and the [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) class family. The formal definition above is current and exact; it emits once from this by-global page. Data page [UID:0002W4][0x0067adb8-0x0067adbc.g_pDeleteReplyAlert](by-memory/0x0067adb8-0x0067adbc.g_pDeleteReplyAlert.md), aggregate UID0002AI, and scalar UID0003Q6 remain non-emitting and must not duplicate it.

## Source-Quality Decision

`DeleteReplyAlert *g_pDeleteReplyAlert = 0;` matches the zero-filled storage and lifecycle exactly while using a realistic human source name rather than `dword_67ADB8`. Constructor publication, ordinary destruction, the static accessor, and article-list live checks all use this one object. Original physical placement between a shared alert source and a private board-dialog source is not symbol-proven, but that uncertainty does not justify blanking or duplicating the definition; the current canonical source root is BulletinReplyAlerts.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md)
- [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md)
- [UID:0004WC][0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor](by-memory/0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor.md)
- [UID:0004WD][0x0047e350-0x0047e379.DeleteReplyAlertDestructor](by-memory/0x0047e350-0x0047e379.DeleteReplyAlertDestructor.md)
- [UID:0004WE][0x0047e380-0x0047e386.DeleteReplyAlertGetSingleton](by-memory/0x0047e380-0x0047e386.DeleteReplyAlertGetSingleton.md)

## B006 2026-06-29 Implementation Callback

- Accepted C19: this global now emits the source-ready zero-initialized singleton definition. The duplicate byte storage page [UID:0002W4][0x0067adb8-0x0067adbc.g_pDeleteReplyAlert](by-memory/0x0067adb8-0x0067adbc.g_pDeleteReplyAlert.md) is non-emitting support and must not duplicate this definition.

## Changes

- 2026-07-22 B005 UID0003Q0 callback: retained `89/92` and the exact formal global; replaced stale blank-C++/source-blocker wording with exact constructor/destructor/getter users, article-list live checks, compiler-scalar exclusion, and the one-definition rule.
- 2026-06-07 A008 Batch 037 split:
  - Created as the canonical global page for the `0x0067adb8` board/article reply-delete alert singleton split from the mixed adjacent pair.
  - Summary/evidence: existing IDA-backed docs provide six refs, getter identity, class ownership, and shared alert-wrapper parent placement.
- 2026-06-16 C001 Goal 2 safe IDA refresh:
  - Changed to: score `87/90`; owner/emitter retained [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
  - Summary/evidence: live IDA confirmed zero-filled storage, the exact six refs, saved the global/getter/lifecycle/scalar-deleting labels, and rechecked the shared-alert source-split blocker against `BulletinReplyAlerts`, `DeleteReplyAlert`, and the adjacent mail singleton map.
