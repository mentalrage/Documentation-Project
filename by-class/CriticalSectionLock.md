*** UID:00003C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00051U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00051U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class CriticalSectionLock
{
public:
    explicit CriticalSectionLock(CriticalSection *criticalSection);
    ~CriticalSectionLock();

private:
    CriticalSection *m_criticalSection;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CriticalSectionLock

## Summary

`CriticalSectionLock` is the four-byte non-owning RAII guard paired with [UID:00051V][CriticalSection](by-class/CriticalSection.md). It stores a `CriticalSection *`, enters it during construction, and leaves it during destruction. Application owns the concrete static instance used by the two observed guard scopes; this reusable class owns no synchronization storage itself.

## Likely Original Placement

- Source: [UID:00051U][CriticalSection](by-file/CriticalSection.md)
- Path: `util/CriticalSection.cpp` and `util/CriticalSection.h`
- Confidence: very strong for the separate module and pointer ABI; exact original private spelling remains inferred.

## Methods

- [UID:00051X][0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor](by-memory/0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor.md).
- [UID:000522][0x0049bd10-0x0049bd19.CriticalSectionLockDestructor](by-memory/0x0049bd10-0x0049bd19.CriticalSectionLockDestructor.md).
- Related low-level API wrappers: [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md).
- Formal declaration: one private `CriticalSection *m_criticalSection` field plus constructor/destructor declarations. Exact method definitions live on the two children; [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md) is a non-emitting index.

## Evidence

- IDA confirms the two-function range exactly.
- Constructor callers include `Application::RunMessageLoop`-area code at `0x00464db7` and message-handler exchange code at `0x00465666`.
- Generated source behavior is direct Win32 RAII: `EnterCriticalSection` and `LeaveCriticalSection`.
- 2026-06-16 A001 live IDA refresh reconfirmed `sub_49BCF0` size `0x19`, `sub_49BD10` size `0x9`, decompilation as pointer store plus `EnterCriticalSection` and stored-pointer `LeaveCriticalSection`, constructor refs at `0x00464db7`/`0x00465666`, destructor refs at `0x00464dc5`/`0x00465677`, and the adjacent wrapper/padding boundaries.
- Historical pre-split evidence, 2026-07-05: B003's then-current MCP callback resolved the adjacent [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md) as a source-ready `CriticalSection` constructor/destructor/enter/leave method family at `88/91` and described it as Monitor-routed. The 2026-08-15 UID0000LI split supersedes that placement: [UID:00051U][CriticalSection](by-file/CriticalSection.md) now owns the separate `NexusTK/util/CriticalSection.cpp/.h` route for UID000226 and `CriticalSectionLock`. The shared storage-shape evidence remains valid, while Application remains only the owner/consumer of the concrete static object.
- Application is a consumer: `RunMessageLoop` and `ExchangeMSGHandler` construct local `CriticalSectionLock` guards around `s_messageHandlerCriticalSection` at `0x0067a9a4`. Application owns that static storage and active-handler state; this class owns only the reusable guard declaration.
- Negative support evidence remains important: UID00012A calls imported `EnterCriticalSection` / `LeaveCriticalSection` directly and does not route through UID000226's unreferenced `CriticalSection::Enter` / `CriticalSection::Leave` helper bodies.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | The page records the exact four-byte layout, method pair, caller pairs, Application consumer/static relation, direct CriticalSection owner, complete H declaration, exact CPP child routes, and no ownership/null-check additions. |
| Confidence | 95 | Behavior, bounds, pointer ABI, call sites, and source neighborhood are direct. Only original private spelling and pointer-versus-reference source style remain inferred. |

## Open Questions

- The source split is resolved as `CriticalSection.cpp/.h` by the contiguous low-address method family and direct type relationship; historical Monitor placement is superseded.
- `PlatformApi.cpp` and Application ownership are rejected: the class is a reusable synchronization guard, while Application only owns and consumes one static instance.
- Pointer-versus-reference source spelling is not symbol-proven. The accepted `CriticalSection *` form exactly preserves the four-byte ABI and observed address-passing call shape without retaining raw Win32 typedefs in the human declaration.

## Cross-References

- File: [UID:00051U][CriticalSection](by-file/CriticalSection.md)
- Direct class: [UID:00051V][CriticalSection](by-class/CriticalSection.md)
- Critical-section API wrappers: [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md)
- Memory: [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md)
- Exact methods: [UID:00051X][0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor](by-memory/0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor.md), [UID:000522][0x0049bd10-0x0049bd19.CriticalSectionLockDestructor](by-memory/0x0049bd10-0x0049bd19.CriticalSectionLockDestructor.md)
- Related consumer: [UID:0000HG][Application](by-file/Application.md)

## Changes

- 2026-08-15 B004 UID0000LI callback:
  - Reparented this exact four-byte non-owning RAII guard to [UID:00051U][CriticalSection](by-file/CriticalSection.md), replaced raw `LPCRITICAL_SECTION` declaration source with the typed `CriticalSection *` wrapper relationship, and moved definitions to exact children [UID:00051X][0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor](by-memory/0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor.md) / [UID:000522][0x0049bd10-0x0049bd19.CriticalSectionLockDestructor](by-memory/0x0049bd10-0x0049bd19.CriticalSectionLockDestructor.md).
  - Raised to `94/95`; preserved caller pairs, no ownership/null-check behavior, and the historical Monitor placement as superseded provenance.

- 2026-07-05 B004 UID00012A implementation callback:
  - Changed `85/88 -> 88/91`, kept owner/emitter/reconstructable metadata routed through [UID:0000LI][Monitor](by-file/Monitor.md), and inserted the formal one-field `CriticalSectionLock` declaration.
  - Recorded source-ready status, Application consumer context, UID000226 source-ready sibling support, and the remaining exact header/source split as a confidence cap rather than a C++ blocker.
- 2026-07-05 B003 UID000226 implementation callback:
  - Added the relationship to the then source-ready `CriticalSection` wrapper method family and historically described `CriticalSectionLock` as Monitor-routed over caller-owned critical-section storage. The 2026-08-15 UID0000LI split supersedes that route with current [UID:00051U][CriticalSection](by-file/CriticalSection.md) ownership of the separate `CriticalSection.cpp/.h` module; the evidence still does not support moving UID000226 to Application.
  - No score change.
- 2026-06-16 A001 file-completion support refresh:
  - Before: scored `84/86`.
  - After: scored `85/88`.
  - Evidence: live IDA reconfirmed constructor/destructor sizes, decompilation, caller pairs, and the adjacent critical-section wrapper/padding boundaries. Owner/emitter stay with [UID:0000LI][Monitor](by-file/Monitor.md); the method-pair memory page routes through this class.
- Before: this class page only listed the RAII constructor/destructor methods.
- Changed to: cross-reference the adjacent critical-section API wrapper family.
- Summary/evidence: IDA MCP/raw disassembly shows the Win32 critical-section wrapper helpers immediately before the RAII lock method pair.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `84/86`.
  - Summary/evidence: the item is small and the constructor/destructor behavior, bounds, callers, API wrappers, and placement uncertainty are already documented; remaining uncertainty is mostly whether the original implementation lived in a header or a nearby monitor/platform source.
