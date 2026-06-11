*** UID:0000UG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DestroyExceptionHandler 0x004673a0

## Status

- Confidence: strong for behavior, high for Application cleanup ownership, medium-high for original helper spelling.
- Address: `0x004673a0`
- Exact memory range: [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md)
- Selected source family: [UID:0000HG][Application](by-file/Application.md) fatal resource-load cleanup.
- Related object owner: [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) owns the class and [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) singleton that this helper deletes.
- Parent attachment: canonical reconstruction is now carried by [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md), which attaches to [UID:0000HG][Application](by-file/Application.md). This by-item page remains a name/index note and intentionally does not duplicate the autogen parent.
- Evidence basis: IDA MCP lookup/decompile/caller/callee checks through 2026-06-10.

## Behavior

`0x004673a0` checks [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md). If an active [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) exists, the helper calls vtable slot 0 with delete flag `1`, effectively destroying the active exception handler object.

Final C++ should be expressed as `delete g_pCrashTarget;`; the explicit vtable call is compiler output for deleting a polymorphic object. The helper does not write null back to the global.

## Evidence

- IDA MCP `lookup_funcs` reports a 17-byte helper at `0x004673a0-0x004673b1`.
- IDA decompilation shows a single `g_pCrashTarget` null check followed by `(**vtable)(g_pCrashTarget, 1)`.
- IDA MCP `callees 0x004673a0` reports no direct callees because the destructor call is indirect through the vtable.
- IDA callers are concentrated in resource/image load failure paths, including callers around `0x004d1860`, `0x004d2720`, `0x004dcf60`, `0x004ddf60`, and `0x004e1800`.
- The same caller sites immediately call [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md), making this pair fatal-load cleanup glue rather than normal subsystem teardown.
- This helper is separate from [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md), which also touches [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) during normal teardown.
- B001-013 IDA MCP recheck confirms all 22 direct caller sites pair this helper immediately after [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) in fatal image/resource load exits. The normal `g_pCrashTarget` constructor/destructor/filter lifecycle lives in [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md); this helper is external Application/startup cleanup policy.

## Ownership Notes

Treat this item as a name/index note for the exact [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md). The helper destroys an ExceptionHandler object, so concrete class/global ownership stays with `platform/ExceptionHandler.cpp`; the repeated paired fatal-load callers make [UID:0000HG][Application](by-file/Application.md) the best direct source owner for the helper body.

Do not treat this as evidence that image-library modules own the exception handler. They only call the helper while unwinding after failed asset loads.

## Cross-References

- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:000297][0x0067ab34-0x0067ab38.g_pCrashTarget](by-memory/0x0067ab34-0x0067ab38.g_pCrashTarget.md)
- [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md)
- [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md)
- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)

## Changes

- 2026-06-10 B001-013 ownership sync:
  - What existed before: the item page still described final source ownership as deferred between ExceptionHandler object ownership and Application/resource failure cleanup.
  - Changed to: selected Application fatal-load cleanup as the source family and clarified that the canonical by-memory page carries the autogen parent while this by-item remains an index note.
  - Evidence: B001-013 IDA MCP confirmed the exact deleting wrapper, all 22 paired fatal resource-load callers, normal ExceptionHandler singleton lifetime writes/clears in the ExceptionHandler cluster, and Application/startup neighboring helper context.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`; parent attachment remains blank.
  - Before: the tiny exception-handler deletion helper was documented but unclassified in autogen coverage.
  - After: it is marked as source-authored cleanup behavior that must be reproduced, but not attached because the final source owner is still unresolved between `ExceptionHandler.cpp` object ownership and application/resource-failure glue.
  - Evidence: live IDA MCP confirms `sub_4673A0` at `0x004673a0`, size `0x11`, no direct callees, and the same paired image/resource failure caller pattern as [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md).

- 2026-05-30: Raised completion/confidence from `0/0` to `84/88`. Previously the page had the right helper identity but no score; it now carries the current IDA MCP no-direct-callee result, concrete global memory cross-reference, final C++ `delete g_pCrashTarget` form, and unchanged source-owner caveat.
