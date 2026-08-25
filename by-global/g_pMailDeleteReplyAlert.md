*** UID:0002W5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0002W5] by-global/g_pMailDeleteReplyAlert.md
class MailDeleteReplyAlert;

MailDeleteReplyAlert *g_pMailDeleteReplyAlert = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMailDeleteReplyAlert

## Status

- Address: `0x0067adbc`
- Storage page: [UID:0002W6][0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert](by-memory/0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert.md)
- Type hypothesis: `MailDeleteReplyAlert *`
- Owner: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), with [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) retained as an alternate private-placement candidate.
- Confidence: strong for address, class owner, and lifecycle; medium-high for final source split.

## Evidence

The slot stores the active [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) instance. Existing IDA-backed docs and B009 2026-06-19 PE/Capstone reanalysis report ten refs to `0x0067adbc` / `g_pMailDeleteReplyAlert` across mail-list, mail-dialog, and mail-alert code: `0x0047a483`, `0x0047a4e2`, `0x0047a811`, `0x0047a870`, `0x0047cb1a`, `0x0047cc50`, `0x0047e6e3`, `0x0047e70c`, `0x0047e721`, and `0x0047ebb2` in the local PE scan, aligning with the existing IDA xref neighborhoods `0x0047a3b0`, `0x0047a760`, `0x0047c9f0`, `0x0047cb40`, `0x0047e6f0`, `0x0047e720`, and `0x0047eb30`.

Exact child pages tie the lifecycle to this slot: [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md) records the constructor write, [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md) records the clear/getter pair, and [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md) records the scalar-destructor clear.

Current zero-filled `.data` evidence from [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md) supersedes older static-image wording. Treat the declaration as a source-level singleton pointer initialized to null, not as an intentional `0xffffffff` source initializer.

## Assignment Gate

This global is attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), currently `86/87`. The relationship is direct for the current shared alert-wrapper source bucket; assigning the exact mixed pair to `MailDialogs` would overclaim the board/article slot, but this split global can be moved later if stronger source evidence proves mail-private placement. C++ stays blank below the final-source threshold.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md)
- [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md)
- [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md)
- [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md)
- [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md)

## B006 2026-06-29 Implementation Callback

- Accepted C21: this global now emits the source-ready zero-initialized singleton definition. The duplicate byte storage page [UID:0002W6][0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert](by-memory/0x0067adbc-0x0067adc0.g_pMailDeleteReplyAlert.md) is non-emitting support and must not duplicate this definition.

## Changes

- 2026-06-21 supervisor-worker Rule 26 incorporation of B009 `00007J-MailDeleteReplyAlert-class-source-quality.md`: no score change. Added exact direct-ref list, current zero-filled `.data` note, and clarified that old `dword_67ADBC` / `0xffffffff` wording is superseded by the source-level `g_pMailDeleteReplyAlert` singleton declaration.
- 2026-06-07 A008 Batch 037 split:
  - Created as the canonical global page for the `0x0067adbc` mail reply-delete alert singleton split from the mixed adjacent pair.
  - Summary/evidence: existing IDA-backed docs provide ten refs, exact constructor/destructor/getter/scalar-destructor child evidence, class ownership, and shared alert-wrapper parent placement.
