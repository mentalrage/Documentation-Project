*** UID:0000QG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pBulletinSession

## Status

- Symbol kind: process-wide singleton pointer / global data
- Address: [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md)
- Observed aliases: `g_pBulletinSession`, `DAT_0067adc0`, `dword_67ADC0`
- Proposed owner module: [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- Confidence: strong.

## Role

`g_pBulletinSession` points to the active [UID:00001D][BulletinSession](by-class/BulletinSession.md), if one exists. UI commands and packet/input handlers read it to reuse or create the board/mail session, while the constructor and destructor maintain the storage.

## Lifetime Evidence

- `BulletinSession::BulletinSession` writes `g_pBulletinSession = this`.
- The clear helper at `0x00471270` and `BulletinSession::ScalarDeletingDestructor` clear the global.
- `EnsureBulletinSession_5A50A0` reads the global, allocates a new `BulletinSession` if absent, and leaves the constructor to publish it.

## Consumer Pattern

IDA MCP xrefs on 2026-05-24 show consumers from:

- UI/panel input paths around `0x00507c90`, `0x00513bb0`, `0x00546610`, `0x005a5bd0`, and `0x005bd000`;
- lazy initializer [UID:0000HX][BulletinSession](by-file/BulletinSession.md);
- constructor/destructor/clear paths in the BulletinSession implementation.

## Cross-References

- [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:00001D][BulletinSession](by-class/BulletinSession.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address/memory page, observed aliases, singleton role, constructor/destructor/clear lifetime, lazy initializer, consumer families, and file/class refs.
- 2026-06-05: Marked reconstructable under [UID:0000HX][BulletinSession](by-file/BulletinSession.md). Evidence: live IDA MCP reports xrefs to `0x0067adc0` from the `BulletinSession` constructor/clear body, packet/dialog consumers, and `EnsureBulletinSession_5A50A0`; decompilation confirms `0x00471150` writes `dword_67ADC0`, `0x00471270` clears it, and `0x005a50a0` lazily constructs the session when the pointer is null.
