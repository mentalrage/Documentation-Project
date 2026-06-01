*** UID:0000QN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Evidence basis: IDA MCP xrefs, helper decompilation, and `simroot_v2` generated source through 2026-05-30.

## Role

`g_pCrashTarget` stores the active [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) object used by `TopLevelExceptionFilter`. The filter reads this pointer, restores keyboard settings, optionally writes `BCrash.nfo`, and can chain to the previous unhandled-exception filter.

The [UID:00003A][Crasher](by-class/Crasher.md) diagnostic pane also uses this global. Its crash-trigger path sets byte `[g_pCrashTarget + 4]` before deliberately raising a null-pointer exception; `TopLevelExceptionFilter` checks the same byte and skips normal report generation when it is set.

## Known Accesses

| Address | Access | Notes |
| --- | --- | --- |
| `0x00464c5e` | cleanup path | `Application::CleanupResources` destroys the handler if present. |
| `0x004673a0` | destroy helper | [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) invokes the active handler deleting destructor; exact range [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md). |
| `0x0049bb60` | write through object | `Crasher::TriggerCrash` sets byte `[g_pCrashTarget + 4]`. |
| `0x004ab499` | write | `ExceptionHandler::ExceptionHandler` stores `this`. |
| `0x004ab830` | read | `TopLevelExceptionFilter` reads the active handler. |
| `0x004ac879` | clear | `ExceptionHandler::ScalarDeletingDestructor` clears the global. |
| `0x005101e2` | read/use | Startup/account dialog path touches the active crash target; exact semantics remain open. |

IDA MCP recheck on 2026-05-30 confirms the destroy helper has no direct callees because its deleting destructor call is indirect through the active handler vtable. Final C++ should be represented as `delete g_pCrashTarget;` at that helper site, not as a hand-written call to a generated scalar deleting destructor.

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

- 2026-05-30: Raised completion/confidence from `0/0` to `82/88`. Previously the page described the global but had no score; it now links the concrete memory slot, records the 2026-05-30 destroy-helper recheck, and preserves the open xref-completeness caveat.
