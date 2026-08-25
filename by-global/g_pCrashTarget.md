*** UID:0000QN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ExceptionHandler *g_pCrashTarget = 0;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern ExceptionHandler *g_pCrashTarget;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pCrashTarget

## Status

- Confidence: very strong for exact type, zero initialization, one source definition, ExceptionHandler ownership, lifecycle, and complete current xref inventory.
- Address range: [UID:000297][0x0067ab34-0x0067ab38.g_pCrashTarget](by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md)
- Likely source module: [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- Type hypothesis: `ExceptionHandler*`
- Evidence basis: IDA MCP xrefs and helper decompilation through 2026-06-10.

## Role

`g_pCrashTarget` stores the active [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) object used by [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md). The filter snapshots this pointer, restores keyboard settings through [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md) when live, optionally writes `BCrash.nfo`, and can chain to the previous unhandled-exception filter stored as `m_previousFilter`.

The [UID:00003A][Crasher](by-class/Crasher.md) diagnostic pane also uses this global. Its `OnTimer` source calls the public inline `g_pCrashTarget->SetSkipCrashReport(true)` before deliberately raising a null-pointer exception. That accessor compiles to the exact byte store `[g_pCrashTarget + 4] = 1`; [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) checks the same private `m_skipCrashReport` field and skips normal report generation and previous-filter chaining when it is set.

The offset `+4` byte is `m_skipCrashReport`. [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) owns the private field, sole global definition, and formal external declaration; [UID:0000II][Crasher](by-file/Crasher.md) is a cross-module consumer through the public inline setter. This preserves legal C++ access without changing the observed store.

## Known Accesses

| Address | Access | Notes |
| --- | --- | --- |
| `0x00464c5e` | cleanup path | `Application::CleanupResources` destroys the handler if present. |
| `0x004673a0` | destroy helper | [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) invokes the active handler deleting destructor; exact range [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md). B001-013 assigns that helper body to [UID:0000HG][Application](by-file/Application.md) fatal-load cleanup, while this global remains [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)-owned. |
| `0x0049bb60` | write through object | `Crasher::TriggerCrash` sets byte `[g_pCrashTarget + 4]`. |
| `0x004ab499` | write | `ExceptionHandler::ExceptionHandler` stores `this`. |
| `0x004ab830` | read | `TopLevelExceptionFilter` reads the active handler, checks `m_skipCrashReport`, writes the crash report when allowed, and chains through `m_previousFilter` when present. |
| `0x004ac879` | clear | `ExceptionHandler::ScalarDeletingDestructor` clears the global. |
| `0x005101e2` | read/use | UID0003TY loads the active handler into `ECX` before calling [UID:0004TS][0x004ab510-0x004ab73b.ExceptionHandlerSendStoredCrashReportFile](by-memory/0x004ab510-0x004ab73b.ExceptionHandlerSendStoredCrashReportFile.md). |

IDA MCP recheck on 2026-05-30 confirms the destroy helper has no direct callees because its deleting destructor call is indirect through the active handler vtable. Final C++ should be represented as `delete g_pCrashTarget;` at that helper site, not as a hand-written call to a scalar deleting destructor.

## 2026-06-07 Batch 034 IDA MCP Recheck

- IDB: `NexusTK.exe`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Historical Batch 034 tooling reported initialized dword `0xffffffff`; the current direct four-byte read is `00 00 00 00`. The old value is superseded evidence-time output, not the source initializer.
- The current xref inventory contains nine data references: cleanup path `0x00464c5e`, startup/failure cleanup `0x00466e70`, destroy helper `0x004673a0`, `Crasher::TriggerCrash` `0x0049bb60`, constructor write `0x004ab499`, raw destructor/reset body `0x004ab4ff`, `TopLevelExceptionFilter` read `0x004ab83a`, scalar deleting destructor clear `0x004ac879`, and startup/account dialog crash-report sender path `0x005101e2`.
- The direct source parent remains [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md), now `86/86` after the same Batch 034 refresh. The `Crasher` file remains a consumer/companion because it writes through the active object pointer but does not own the singleton lifecycle.
- Historical 2026-06-17 B001 Crasher reanalysis described the consumer as `Crasher::TriggerCrash` and the machine write as direct offset-`+4` field access. Current source reconstruction resolves that virtual method as `Crasher::OnTimer` and expresses the write through inline `SetSkipCrashReport(true)`; the inlined byte store remains exact, while `TopLevelExceptionFilter` reads `m_skipCrashReport` to skip normal report generation. Exact original symbol spelling remains final-audit evidence, not a blocker for human source reconstruction.
- The formal CPP continues to own the sole `ExceptionHandler *g_pCrashTarget = 0;` definition and `[[CHILDREN]]`; formal H now owns exactly one `extern ExceptionHandler *g_pCrashTarget;` declaration for cross-module consumers. Exact storage UID000297 remains covered-by only.

## Parent Gate

`AUTOGEN_PARENT_UID` remains assigned to [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md). The source gate is closed at `92/94`: the managed block emits the sole definition `ExceptionHandler *g_pCrashTarget = 0;`, while exact storage UID000297 is covered-by only and cannot duplicate it.

## Cross-References

- [UID:000297][0x0067ab34-0x0067ab38.g_pCrashTarget](by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md)
- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md)
- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md)
- [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md)
- [UID:00003A][Crasher](by-class/Crasher.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)

## Changes

- 2026-08-06 B005 UID000298 Crasher dependency synchronization:
  - Added exact formal H declaration `extern ExceptionHandler *g_pCrashTarget;` while preserving the sole zero CPP definition, scores, owner/emitter, and lifecycle.
  - Updated the Crasher consumer from historical illegal private-field syntax to `SetSkipCrashReport(true)`, which inlines to the same offset-`+4` byte write without transferring ownership.

- 2026-06-22 B015 class source-quality incorporation:
  - Score unchanged at `86/89`.
  - Added Crasher-side confirmation that `Crasher::TriggerCrash` consumes this global only by setting `ExceptionHandler::m_skipCrashReport`; owner/emitter remain [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md).
- 2026-06-17 B001 source-quality sync:
  - Score unchanged at `86/89`.
  - Added the inferred suppress/skip-report field direction at object offset `+4` and clarified that [UID:0000II][Crasher](by-file/Crasher.md) is a consumer, not the global owner. Later B005 source-quality work names the field `m_skipCrashReport`.
- 2026-06-20 B001/B015 TopLevelExceptionFilter child sync:
  - Score unchanged at `86/89`.
  - Updated the [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) linkage after the child reached first-draft C++ readiness: this global is read as `ExceptionHandler *g_pCrashTarget`, offset `+0x04` is consumed as `m_skipCrashReport`, and offset `+0x08` is consumed as `m_previousFilter`; [UID:0000II][Crasher](by-file/Crasher.md) remains a flag consumer, not the owner.
- 2026-06-10 B001-013 helper-owner clarification:
  - Score unchanged at `86/89`.
  - Clarified that [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md) deletes this global's active object but is now assigned to [UID:0000HG][Application](by-file/Application.md) as fatal-load cleanup glue.
  - Evidence: B001-013 IDA MCP confirmed this helper's 22 paired resource-failure callers, while the constructor/destructor/filter writes and reads that define the global's lifecycle remain in [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md).

- 2026-05-30: Raised completion/confidence from `0/0` to `82/88`. Previously the page described the global but had no score; it now links the concrete memory slot, records the 2026-05-30 destroy-helper recheck, and preserves the open xref-completeness caveat.
- 2026-06-05: Marked reconstructable under [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md). Evidence: live IDA MCP reports nine xrefs to `0x0067ab34`; decompilation confirms `0x004ab480` writes `dword_67AB34`, `TopLevelExceptionFilter` reads it at `0x004ab83a`, and the destroy helper at `0x004673a0` deletes the active handler through its vtable.
- 2026-06-07 Batch 034: raised `82/88 -> 86/89` and added current IDB hash, initialized dword, full xref inventory, and parent-gate note. The parent file [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) was refreshed to `86/86`, so this global's existing source-parent assignment is now justified under the corrected 85/85 gate.

## B001 UID0003TY Source Definition Synchronization - 2026-07-20

- Current metadata is `92/94`, canonical owner/emitter UID0000J8, reconstructable true, and blank position. The managed block defines exactly one `ExceptionHandler *g_pCrashTarget = 0;` in `NexusTK/platform/ExceptionHandler.cpp`.
- The exact storage bytes at `[0x0067ab34,0x0067ab38)` are four zeros. This direct read supersedes the stale historical `0xffffffff` interpretation and proves null static initialization.
- Constructor publication, raw ordinary-destructor clear, top-level-filter read, scalar-wrapper clear, Application cleanup, Crasher flag use, and destroy-helper use retain the established lifecycle. UID0003TY adds the live member-call route to UID0004TS at `0x005101e2`.
- UID000297 remains the storage documentation page and carries only the covered-by marker. It does not emit a second definition, separate integer object, import alias, or runtime initializer.
- The global remains owned by ExceptionHandler.cpp; Crasher, Application, MapPane, TopLevelExceptionFilter, and UID0004TS are consumers. No consumer ownership transfer, vtable/scalar-delete source, or `0xffffffff` initializer is introduced.
