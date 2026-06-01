*** UID:0000FE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UniAPIInit

## Summary

`UniAPIInit` initializes the client-wide Win32 API dispatch table for Unicode-aware operation. It detects whether the process is running on the NT platform family and installs wide-character API pointers when possible, otherwise keeping ANSI fallback behavior.

Current IDA evidence anchors the real dispatch-table initializer at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md). The generated body at `0x005995b0` is still useful for intent, but IDA does not mark `0x005995b0` as a function. Nearby platform string and stream-reader helpers are documented separately at [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md).

## Likely Original Placement

- Source: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Proposed path: `platform/PlatformApi.cpp`
- Confidence: medium

## Methods

- `0x0041a280-0x0041a4a8` real IDA initializer - sets conversion fallback, calls `GetVersionExA`, installs many `*W` API pointers on NT-family Windows, writes `_wfopen` to `dword_69BE14`, writes `_wstat64i32` to `dword_69BE18`, and registers the [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) with `atexit`.
- `0x0060c440-0x0060c44b` static cleanup wrapper - writes the `UniAPIInit` vtable pointer to `0x006702c4`; compiler/static-lifetime artifact, not a normal source method.
- `0x005995b0` Wave3-projected initializer/destructor body - generated source describes the same broad dispatch-table setup, but IDA does not currently define a function at this address.
- `0x00599a10-0x00599a34` scalar deleting destructor - resets vtable and optionally frees the object.

## Globals

This class owns or initializes many `g_pfn*` function pointers, including file, window, registry, dialog, message, locale, and IME APIs. Examples include `g_pfnCreateWindowEx`, `g_pfnDispatchMessage`, `g_pfnPeekMessage`, `g_pfnRegQueryValueEx`, `g_pfnSetWindowText`, and `g_pfnImmGetCompositionString`.

The concrete global-data cluster is documented as [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md). File consumers should treat `dword_69BE14` and `dword_69BE18` as entries in that table, not as `StdioFile` or `PathUtil` globals.

## Evidence

- Generated source uses `GetVersionExA` and compares `dwPlatformId` to `VER_PLATFORM_WIN32_NT`.
- IDA MCP confirms [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) is a real initializer that performs the table writes.
- IDA MCP confirms the scalar deleting destructor at `0x00599a10-0x00599a34`.
- IDA MCP reports no function containing `0x005995b0`; the previous function is [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), specifically the `0x00599570-0x005995a7` UTF-16 stream-reader helper, and the next function is `0x005997e0-0x005997e7`.
- 2026-05-26 IDA MCP recheck reconfirmed those boundaries and showed `0x0041a280` is referenced from startup initializer table data at `0x0060d71c`, while `0x005995b0` has no callers or xrefs.
- 2026-05-26 IDA MCP confirms `0x0060c440` has size `0x0b`, is registered by the `0x0041a280` initializer, and only writes `UniAPIInit::vftable` to `0x006702c4`.
- Current `simroot_v2/class_UniAPIInit.cpp` still emits the initializer body under `~UniAPIInit` at `0x005995b0`; keep this as generated provenance, not final source layout.

## Open Questions

- Review whether the body at `0x005995b0` should be a constructor or initializer rather than `~UniAPIInit`.
- Reconcile generated `0x005995b0` provenance with the real `0x0041a280` initializer.
- Type all `g_pfn*` globals and move their ownership into the platform API file.

## Cross-References

- File: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Globals: [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- Related classes: [UID:00000Q][AutoInit](by-class/AutoInit.md), [UID:00006J][InputMan](by-class/InputMan.md), [UID:00000D][Application](by-class/Application.md)
- Memory: [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md), [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md), [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md)

## Changes

- 2026-05-28 boundary/context correction:
  - What existed before: class documentation referenced `0x005995b0-0x00599a33` and treated the previous function only as an unnamed boundary fact.
  - Changed to: class documentation references `0x005995b0-0x00599a34` and links the previous platform string/stream helper island.
  - Summary/evidence: IDA MCP reports `sub_599A10` as `0x00599a10-0x00599a34` and identifies `0x00599440-0x005995a7` as real conversion/read helper code before the Wave3-projected `UniAPIInit` body.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the wide API dispatch-table initializer, global table ownership, scalar destructor/static cleanup evidence, boundary correction, and documented conflict between the real `0x0041a280` initializer and Wave3-projected `0x005995b0` body.
