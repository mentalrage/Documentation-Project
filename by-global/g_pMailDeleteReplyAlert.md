*** UID:0002W5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMailDeleteReplyAlert

## Status

- Address: `0x0067adbc`
- Storage page: [UID:0002W6][0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert](by-memory/0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert.md)
- Type hypothesis: `MailDeleteReplyAlert *`
- Owner: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), with [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) retained as an alternate private-placement candidate.
- Confidence: strong for address, class owner, and lifecycle; medium-high for final source split.

## Evidence

The slot stores the active [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) instance. Existing IDA-backed docs report ten refs to `dword_67ADBC` across mail-list and mail-alert code around `0x0047a3b0`, `0x0047a760`, `0x0047c9f0`, `0x0047cb40`, `0x0047e6f0`, `0x0047e720`, and `0x0047eb30`.

Exact child pages tie the lifecycle to this slot: [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md) records the constructor write, [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md) records the clear/getter pair, and [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md) records the scalar-destructor clear.

## Assignment Gate

This global is attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), which is `85/86`. The relationship is direct for the current shared alert-wrapper source bucket; assigning the exact mixed pair to `MailDialogs` would overclaim the board/article slot, but this split global can be moved later if stronger source evidence proves mail-private placement. C++ stays blank below the final-source threshold.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md)
- [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md)
- [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md)
- [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md)
- [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md)

## Changes

- 2026-06-07 A008 Batch 037 split:
  - Created as the canonical global page for the `0x0067adbc` mail reply-delete alert singleton split from the mixed adjacent pair.
  - Summary/evidence: existing IDA-backed docs provide ten refs, exact constructor/destructor/getter/scalar-destructor child evidence, class ownership, and shared alert-wrapper parent placement.
