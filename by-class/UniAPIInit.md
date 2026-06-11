*** UID:0000FE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ML | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UniAPIInit

## Summary

`UniAPIInit` initializes the client-wide Win32 API dispatch table for Unicode-aware operation. It detects whether the process is running on the NT platform family and installs wide-character API pointers when possible, otherwise keeping ANSI fallback behavior.

Current IDA-backed evidence anchors the real dispatch-table initializer at [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md). The generated body at `0x005995b0` is useful only as provenance for the table-write intent: IDA does not mark `0x005995b0` as a function, the exact static-object source shape remains unresolved, and the trustworthy executable coverage is split between the startup initializer, the `0x005997e0` vtable-reset helper, and the `0x00599a10` scalar deleting destructor. Nearby platform string and stream-reader helpers are documented separately at [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md).

## Likely Original Placement

- Source: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Proposed path: `platform/PlatformApi.cpp`
- Confidence: strong for platform ownership and memory anchors; medium for final source spelling/static-object shape

## Methods

- `0x0041a280-0x0041a4a8` real IDA initializer - sets conversion fallback, calls `GetVersionExA`, installs many `*W` API pointers on NT-family Windows, writes `_wfopen` to `dword_69BE14`, writes `_wstat64i32` to `dword_69BE18`, and registers the [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) with `atexit`.
- `0x005997e0-0x005997e7` vtable reset helper - exact raw IDA function that writes the `UniAPIInit` vtable pointer through `this`; no current xrefs.
- `0x0060c440-0x0060c44b` static cleanup wrapper - writes the `UniAPIInit` vtable pointer to `0x006702c4`; compiler/static-lifetime artifact registered by the real startup initializer, not a normal source method.
- `0x005995b0` Wave3-projected initializer/destructor body - generated source describes the same broad dispatch-table setup, but IDA does not currently define a function at this address.
- `0x00599a10-0x00599a34` scalar deleting destructor - resets vtable and optionally frees the object.

## Globals

This class owns or initializes many `g_pfn*` function pointers, including file, window, registry, dialog, message, locale, event, and IME APIs. Examples include `g_pfnCreateWindowEx`, `g_pfnDispatchMessage`, `g_pfnPeekMessage`, `g_pfnRegQueryValueEx`, `g_pfnSetWindowText`, `g_pfnCreateEventW`, `g_pfnSendMessageW`, and `g_pfnImmGetCompositionString`.

The concrete global-data cluster is documented as [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md). File consumers should treat `dword_69BE14` and `dword_69BE18` as entries in that table, not as `StdioFile` or `PathUtil` globals. The stale browser/transport name on [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) is also a consumer-biased alias; the documented slot is the `SendMessageW` dispatch entry.

## Evidence

- Generated source uses `GetVersionExA` and compares `dwPlatformId` to `VER_PLATFORM_WIN32_NT`.
- IDA MCP confirms [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) is a real initializer that performs the table writes.
- IDA MCP confirms the scalar deleting destructor at `0x00599a10-0x00599a34`.
- IDA MCP reports no function containing `0x005995b0`; the previous function is [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), specifically the `0x00599570-0x005995a7` UTF-16 stream-reader helper, and the next function is `0x005997e0-0x005997e7`.
- 2026-05-26 IDA MCP recheck reconfirmed those boundaries and showed `0x0041a280` is referenced from startup initializer table data at `0x0060d71c`, while `0x005995b0` has no callers or xrefs.
- 2026-05-26 IDA MCP confirms `0x0060c440` has size `0x0b`, is registered by the `0x0041a280` initializer, and only writes `UniAPIInit::vftable` to `0x006702c4`.
- Existing IDA-backed sibling pages now agree on the parent/source chain: [UID:0000ML][PlatformApi](by-file/PlatformApi.md) owns the source module, [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) owns the concrete pointer storage, [UID:00028B][0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot](by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md) owns the static object vptr slot, and [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) preserves the raw/generated-boundary caveat.
- Current `simroot_v2/class_UniAPIInit.cpp` still emits the initializer body under `~UniAPIInit` at `0x005995b0`; keep this as generated provenance, not final source layout.

## Open Questions

- Reconcile generated `0x005995b0` provenance with the real `0x0041a280` initializer and decide whether the raw spans should later become exact child pages or remain only a generated-boundary caveat.
- Decide the final C++ spelling for the static `UniAPIInit` object, vtable-reset helper, and dispatch table declaration style.
- Type all remaining `g_pfn*` globals with source-facing names; ownership is now attached to [UID:0000ML][PlatformApi](by-file/PlatformApi.md), but the final typedef/table style is still open.

## Cross-References

- File: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Globals: [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- Related classes: [UID:00000Q][AutoInit](by-class/AutoInit.md), [UID:00006J][InputMan](by-class/InputMan.md), [UID:00000D][Application](by-class/Application.md)
- Memory: [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md), [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md), [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md)

## Changes

- 2026-06-07 parent/confidence reconciliation:
  - What existed before: `AUTOGEN_PARENT_UID` was blank and the page stayed at `86/78`, even though the linked PlatformApi, WideApiDispatchTable, vtable-slot, and exact memory pages already carried a consistent IDA-backed ownership chain.
  - Changed to: raised the page to `88/82`, attached it to [UID:0000ML][PlatformApi](by-file/PlatformApi.md), expanded the summary/method/global sections with the vtable-reset helper, static vptr slot, `CreateEventW`/`SendMessageW` table slots, and clarified that `0x005995b0` remains raw/generated provenance rather than a source body.
  - Summary/evidence: existing IDA-backed pages document `0x0041a280` as the authoritative startup initializer, [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) as the concrete table, [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) as the generated-boundary caveat, [UID:00028B][0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot](by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md) as the static object slot, and [UID:0000ML][PlatformApi](by-file/PlatformApi.md) as the source root. This session could not reach IDA MCP, so no new live-disassembler claim was added. C++ remains blank below the 95/95 final-source gate.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE`; the later 2026-06-07 pass attached `AUTOGEN_PARENT_UID` to [UID:0000ML][PlatformApi](by-file/PlatformApi.md) after the class confidence reached the parent gate.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the real dispatch initializer at `0x0041a280`, static cleanup wrapper at `0x0060c440`, scalar deleting destructor at `0x00599a10`, and neighboring platform helper starts at `0x00599440`, `0x00599570`, and `0x005997e0`; `0x005995b0` still reports `Not a function`. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-28 boundary/context correction:
  - What existed before: class documentation referenced `0x005995b0-0x00599a33` and treated the previous function only as an unnamed boundary fact.
  - Changed to: class documentation references `0x005995b0-0x00599a34` and links the previous platform string/stream helper island.
  - Summary/evidence: IDA MCP reports `sub_599A10` as `0x00599a10-0x00599a34` and identifies `0x00599440-0x005995a7` as real conversion/read helper code before the Wave3-projected `UniAPIInit` body.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the wide API dispatch-table initializer, global table ownership, scalar destructor/static cleanup evidence, boundary correction, and documented conflict between the real `0x0041a280` initializer and Wave3-projected `0x005995b0` body.
