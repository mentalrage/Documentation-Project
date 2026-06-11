*** UID:0000QN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCrashTarget

## Status

- Confidence: strong for storage and primary owner; medium-high for complete xref coverage.
- Address range: [UID:000297][0x0067ab34-0x0067ab38.g_pCrashTarget](by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md)
- Likely source module: [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- Type hypothesis: `ExceptionHandler*`
- Evidence basis: IDA MCP xrefs and helper decompilation through 2026-06-10.

## Role

`g_pCrashTarget` stores the active [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) object used by `TopLevelExceptionFilter`. The filter reads this pointer, restores keyboard settings, optionally writes `BCrash.nfo`, and can chain to the previous unhandled-exception filter.

The [UID:00003A][Crasher](by-class/Crasher.md) diagnostic pane also uses this global. Its crash-trigger path sets byte `[g_pCrashTarget + 4]` before deliberately raising a null-pointer exception; `TopLevelExceptionFilter` checks the same byte and skips normal report generation when it is set.

## Known Accesses

| Address | Access | Notes |
| --- | --- | --- |
| `0x00464c5e` | cleanup path | `Application::CleanupResources` destroys the handler if present. |
| `0x004673a0` | destroy helper | [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) invokes the active handler deleting destructor; exact range [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md). B001-013 assigns that helper body to [UID:0000HG][Application](by-file/Application.md) fatal-load cleanup, while this global remains [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)-owned. |
| `0x0049bb60` | write through object | `Crasher::TriggerCrash` sets byte `[g_pCrashTarget + 4]`. |
| `0x004ab499` | write | `ExceptionHandler::ExceptionHandler` stores `this`. |
| `0x004ab830` | read | `TopLevelExceptionFilter` reads the active handler. |
| `0x004ac879` | clear | `ExceptionHandler::ScalarDeletingDestructor` clears the global. |
| `0x005101e2` | read/use | Startup/account dialog path touches the active crash target; exact semantics remain open. |

IDA MCP recheck on 2026-05-30 confirms the destroy helper has no direct callees because its deleting destructor call is indirect through the active handler vtable. Final C++ should be represented as `delete g_pCrashTarget;` at that helper site, not as a hand-written call to a scalar deleting destructor.

## 2026-06-07 Batch 034 IDA MCP Recheck

- IDB: `NexusTK.exe`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- IDA still names the storage `dword_67AB34` and reads the initialized dword as `0xffffffff`, matching a writable singleton slot that is set during runtime rather than a static object address.
- The current xref inventory contains nine data references: cleanup path `0x00464c5e`, startup/failure cleanup `0x00466e70`, destroy helper `0x004673a0`, `Crasher::TriggerCrash` `0x0049bb60`, constructor write `0x004ab499`, raw destructor/reset body `0x004ab4ff`, `TopLevelExceptionFilter` read `0x004ab83a`, scalar deleting destructor clear `0x004ac879`, and startup/account dialog crash-report sender path `0x005101e2`.
- The direct source parent remains [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md), now `86/86` after the same Batch 034 refresh. The `Crasher` file remains a consumer/companion because it writes through the active object pointer but does not own the singleton lifecycle.

## Parent Gate

`AUTOGEN_PARENT_UID` remains assigned to [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md). The corrected gate is now met for this associated parent chain: this global page is `86/89`, and the direct file parent is `86/86`. C++ remains blank because the exact final declaration belongs with the source file once the surrounding exception-handler declarations are ready for final reconstruction.

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

- 2026-06-10 B001-013 helper-owner clarification:
  - Score unchanged at `86/89`.
  - Clarified that [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md) deletes this global's active object but is now assigned to [UID:0000HG][Application](by-file/Application.md) as fatal-load cleanup glue.
  - Evidence: B001-013 IDA MCP confirmed this helper's 22 paired resource-failure callers, while the constructor/destructor/filter writes and reads that define the global's lifecycle remain in [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md).

- 2026-05-30: Raised completion/confidence from `0/0` to `82/88`. Previously the page described the global but had no score; it now links the concrete memory slot, records the 2026-05-30 destroy-helper recheck, and preserves the open xref-completeness caveat.
- 2026-06-05: Marked reconstructable under [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md). Evidence: live IDA MCP reports nine xrefs to `0x0067ab34`; decompilation confirms `0x004ab480` writes `dword_67AB34`, `TopLevelExceptionFilter` reads it at `0x004ab83a`, and the destroy helper at `0x004673a0` deletes the active handler through its vtable.
- 2026-06-07 Batch 034: raised `82/88 -> 86/89` and added current IDB hash, initialized dword, full xref inventory, and parent-gate note. The parent file [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) was refreshed to `86/86`, so this global's existing source-parent assignment is now justified under the corrected 85/85 gate.
