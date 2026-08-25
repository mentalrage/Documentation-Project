*** UID:0000QG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BulletinSession;

BulletinSession *g_pBulletinSession = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pBulletinSession

## Status

- Symbol kind: sole externally linked process-wide `BulletinSession *` definition
- Address: [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md)
- Observed aliases: `g_pBulletinSession`, `DAT_0067adc0`, `dword_67ADC0`
- Proposed owner module: [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- Emission: [UID:0000HX][BulletinSession](by-file/BulletinSession.md) position `0`, before class/method children.
- Header declaration: exactly one matching `extern BulletinSession *g_pBulletinSession;` in [UID:00001D][BulletinSession](by-class/BulletinSession.md).
- Physical backing: [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md) is false/non-emitting loader-zero storage; it cannot emit a duplicate object.
- Confidence: very strong.

## Role

`g_pBulletinSession` points to the active [UID:00001D][BulletinSession](by-class/BulletinSession.md), if one exists. UI commands and packet/input handlers read it to reuse or create the board/mail session. Direct `Singleton<BulletinSession>` construction/destruction publishes and clears it; authored BulletinSession constructor/destructor source does not duplicate those assignments.

## Lifetime Evidence

- RTTI proves direct `Singleton<BulletinSession>` inheritance with PMD `+0x100/-1/0`. Compiler-generated direct-base construction converts the empty-base view back to the complete object and publishes it; the odd constructor `this+0x100` adjustment/null fallback is lowering, not authored global code.
- Reverse direct-Singleton teardown clears the global during ordinary destruction. [UID:0003Q1][0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear](by-memory/0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear.md) constructor-unwind clear and [UID:0003Q4][0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor](by-memory/0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor.md) scalar-wrapper clear independently corroborate the same compiler-managed lifetime.
- Validator-issued [UID:0004US][0x005a50a0-0x005a5103.EnsureNormalBulletinSession](by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md) reads the global and performs `new BulletinSession(1, 0, false)` only when absent; Singleton construction publishes it.
- [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md) is a four-byte virtual `.data` tail slot beyond raw `.data` and is loader-zero-filled. The historical `0xffffffff` initializer arose from invalid raw-offset mapping into `.rsrc`; no consumer uses a `-1` sentinel.

## Consumer Pattern

IDA MCP xrefs on 2026-05-24 show consumers from:

- UI/panel input paths around `0x00507c90`, `0x00513bb0`, `0x00546610`, `0x005a5bd0`, and `0x005bd000`;
- lazy initializer [UID:0000HX][BulletinSession](by-file/BulletinSession.md);
- constructor/destructor/clear paths in the BulletinSession implementation.
- Fresh UID0001PA MCP reconfirmed exactly 11 xrefs, `more:false`: lifecycle writes/clears at `0x004711a2`, `0x004711a9`, `0x0047128a`, `0x0047e840`, and `0x0047eab0`; reads at `0x00508776`, `0x00513bd3`, `0x005466e8`, `0x005a50c3`, `0x005a60c8`, and `0x005bd0f4`. They occupy ten functions because the first two writes share the constructor.
- 2026-06-14 decompilation confirms constructor `sub_471150` (`0x11c` / 284 bytes, Verified with int_convert.py) publishes the singleton, installs the three `BulletinSession` vtable views, and may send initial board/mail packet setup through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- 2026-06-14 decompilation confirms cleanup helper `sub_471270` (`0x29` / 41 bytes, Verified with int_convert.py) restores `BulletinSession` vtables before clearing the singleton and falling into base cleanup, clear helper `sub_47E840` is `0xb` / 11 bytes (Verified with int_convert.py), and scalar deleting destructor `sub_47EA90` (`0x5f` / 95 bytes, Verified with int_convert.py) clears the singleton before conditional object deletion.
- Fresh decompilation confirms UID0004US `EnsureNormalBulletinSession` (`0x63` / 99 bytes) reads the singleton, allocates `0x104` / 260 bytes only when absent, and constructs `BulletinSession(1, 0, false)` with direct Singleton construction publishing the global.
- Six constructor call sites are exact: `0x005087b6` and `0x00513c07` use mode `0` packet replay; `0x00546718`, `0x005a50ef`, `0x005a60ff`, and `0x005bd120` use mode `1`, null packet, with false/true predefined-form selection as documented on their callers. No route passes or tests a `-1` sentinel.
- One-definition policy is exact: this page emits `BulletinSession *g_pBulletinSession = 0;`, UID00001D declares one extern, UID0001PA emits nothing, and no class-static or function-local duplicate is permitted.

## Autogen And Score Rationale

- Owner/emitter route remains [UID:0000HX][BulletinSession](by-file/BulletinSession.md), which surfaces to `auto-generated/NexusTK/ui/dialogs/BulletinSession.cpp` without a dead end.
- Completion `92` records the exact R1 definition, position 0, one extern, PE loader-zero backing, all xrefs/constructor routes, direct Singleton lifecycle, and duplicate-route exclusions.
- Confidence `94` follows mutually corroborating PE, RTTI/PMD, constructor/destructor/unwind/scalar, caller, and generated one-definition evidence. The cap preserves only original lexical/header factoring uncertainty, not type, linkage, owner, initializer, or lifetime.

## Cross-References

- [UID:0001PA][0x0067adc0-0x0067adc4.g_pBulletinSession](by-memory/0x0067adc0-0x0067adc4.g_pBulletinSession.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:00001D][BulletinSession](by-class/BulletinSession.md)
- [UID:0003Q1][0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear](by-memory/0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear.md)
- [UID:0003Q4][0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor](by-memory/0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)

## Changes

- 2026-07-21 B003 UID0001PA accepted implementation callback:
  - Raised `87/90 -> 92/94`, retained owner/emitter UID0000HX, set position `0`, and installed exact R1 as the sole external definition.
  - Added one matching class-header extern, loader-zero UID0001PA backing, all eleven refs/six constructors, direct Singleton PMD/EBO publication/clear, and generated one-definition/no-marker policy.
  - Historicalized explicit authored constructor/destructor writes, `EnsureBulletinSession_5A50A0`, `0xffffffff`, blank-formal, class-static, duplicate physical-emitter, and function-local alternatives while preserving their binary observations as compiler/source evidence.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address/memory page, observed aliases, singleton role, constructor/destructor/clear lifetime, lazy initializer, consumer families, and file/class refs.
- 2026-06-05: Marked reconstructable under [UID:0000HX][BulletinSession](by-file/BulletinSession.md). Evidence: live IDA MCP reports xrefs to `0x0067adc0` from the `BulletinSession` constructor/clear body, packet/dialog consumers, and `EnsureBulletinSession_5A50A0`; decompilation confirms `0x00471150` writes `dword_67ADC0`, `0x00471270` clears it, and `0x005a50a0` lazily constructs the session when the pointer is null.
- 2026-06-14 A003 goal2 score pass: raised `86/84` to `87/90`.
  - Evidence: live IDA MCP reconfirmed the 11-ref singleton map, constructor/cleanup/clear/scalar deleting destructor/lazy initializer bodies, allocation size, packet-send initialization, and non-dead-ended BulletinSession owner/emitter route.
  - Code-entry decision: no reconstruction C++ was added; the route and numeric gate are present, but final declaration, constructor parameter names, and consumer source names remain below source-quality evidence.
- 2026-06-16 supervisor execution of B001 MailDialogs split report: linked exact [UID:0003Q1][0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear](by-memory/0x0047e840-0x0047e84b.BulletinSessionConstructorUnwindSingletonClear.md) and [UID:0003Q4][0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor](by-memory/0x0047ea90-0x0047eaef.BulletinSessionScalarDeletingDestructor.md) pages now carrying the two `0x0067adc0` clear sites that had been documented only by address.
