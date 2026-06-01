*** UID:0000UG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DestroyExceptionHandler 0x004673a0

## Status

- Confidence: strong for behavior, medium for final source owner.
- Address: `0x004673a0`
- Exact memory range: [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md)
- Likely source family: [UID:0000HG][Application](by-file/Application.md) or [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) cleanup glue.
- Evidence basis: IDA MCP lookup/decompile/caller/callee checks through 2026-05-30.

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

## Ownership Notes

Keep this as a standalone item until final source grouping is decided. It may be a private application/fatal-error helper that tears down the exception filter before showing fatal resource errors, or a small helper in `ExceptionHandler.cpp` consumed by resource loaders.

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

- 2026-05-30: Raised completion/confidence from `0/0` to `84/88`. Previously the page had the right helper identity but no score; it now carries the current IDA MCP no-direct-callee result, concrete global memory cross-reference, final C++ `delete g_pCrashTarget` form, and unchanged source-owner caveat.
