*** UID:0000HN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/platform/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AutoInit

## Status

- Confidence: strong for OLE startup/shutdown behavior, static object slot, destructor/vtable ownership, and platform/OLE placement; medium for standalone source file versus folding into [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
- Proposed module: `NexusTK/platform/AutoInit.cpp`, with possible later folding into [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
- Documentation basis: live IDA startup/shutdown evidence plus the by-class, by-global, by-memory, and by-type pages linked below.

## File Role

`AutoInit.cpp` is a source candidate for a tiny application-wide OLE/COM lifetime helper. The startup side is now confirmed: [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) at `0x00419ee0` calls `OleInitialize(0)` and registers the [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md) through `atexit`. The ordinary destructor at [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md) resets the vtable and calls `OleUninitialize`; the scalar deleting destructor at [UID:0000ZG][0x00470300-0x0047032a.AutoInit](by-memory/0x00470300-0x0047032a.AutoInit.md) wraps the same teardown and optionally deletes the object.

This looks like a static anonymous-namespace lifetime object rather than an allocation-heavy runtime class. The `0x0060c0f0` shutdown thunk writes the anonymous [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) into the static object slot [UID:000277][0x0066d42c-0x0066d430.AutoInitStaticObjectVptr](by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md) and tail-calls `OleUninitialize`.

The likely source-level shape is a tiny file-local lifetime guard: process startup initializes OLE, the registered static shutdown thunk uninitializes OLE, and the virtual/scalar destructors are ABI-side teardown paths for the same helper. Final C++ remains blank until the standalone filename and source-facing object/class names are stronger.

## Boundary Notes

Browser/OLE code remains the largest visible COM consumer, but current evidence is process-wide startup/shutdown support. Keep this in a platform/OLE support bucket unless historical source evidence proves it lived beside browser code.

Do not look for a normal heap constructor call before placing this helper; the known initialization path is the startup initializer table entry at `0x0060d6a4`, not a `new AutoInit`. Source placement should use the IDA-backed memory/type docs rather than recovered-output shape alone.

IDA MCP recheck on 2026-05-30 confirms the static initializer pointer table bytes at `0x0060d6a4`, `InitializeOleSupport` body at `0x00419ee0-0x00419ef4`, the shutdown thunk at `0x0060c0f0-0x0060c100`, and the static slot/vtable relationship through `off_66D42C` and `0x0061373c`.

2026-06-04 live IDA MCP recheck confirms `0x00419ee0` size `0x14`, `0x0046efe0` size `0x0c`, `0x00470300` size `0x2a`, and `0x0060c0f0` size `0x10`. Disassembly shows `InitializeOleSupport` calling `OleInitialize(0)` and `_atexit(0x0060c0f0)`, the ordinary destructor writing vtable `0x0061373c` then jumping to `OleUninitialize`, the scalar deleting destructor calling `OleUninitialize` and optional delete helper with size `4`, and the shutdown thunk writing `off_66D42C = 0x0061373c`.

Live IDA data inspection confirms startup table neighbors `0x0060d6a0 -> 0x00419ec0`, `0x0060d6a4 -> 0x00419ee0`, and `0x0060d6a8 -> 0x00419f00`; vtable neighborhood `0x00613738 -> 0x0064314c`, `0x0061373c -> 0x00470300`, `0x00613740 -> 0x0064325c`; and static slot [UID:000277][0x0066d42c-0x0066d430.AutoInitStaticObjectVptr](by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md) / `off_66D42C` at `0x0066d42c` currently containing `0x0061373c`.

## Cross-References

- [UID:00000Q][AutoInit](by-class/AutoInit.md)
- [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md)
- [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md)
- [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md)
- [UID:0000ZG][0x00470300-0x0047032a.AutoInit](by-memory/0x00470300-0x0047032a.AutoInit.md)
- [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)
- [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md)
- [UID:000277][0x0066d42c-0x0066d430.AutoInitStaticObjectVptr](by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md)
- [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- [UID:0000HV][Browser](by-file/Browser.md)

## Changes

- 2026-05-30: Added the likely source-level static object shape and raised grading from unevaluated.
  - Before: the file page had correct OLE startup/shutdown notes but still used `COMPLETION:0` / `CONFIDENCE:0`.
  - After: the file page records a concrete `AutoInit` constructor/destructor reconstruction shape and the IDA-confirmed initializer-table/shutdown evidence.
  - Evidence: IDA MCP confirms the initializer-table pointer at `0x0060d6a4`, `OleInitialize`/`_atexit` body at `0x00419ee0`, shutdown thunk `0x0060c0f0`, and the `AutoInit` vtable/static slot link.
- 2026-06-04 live IDA MCP evidence, path, and score update:
  - Before: scores were `70/85` and `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: scores set to `82/86` and path set to `NexusTK/platform/`.
  - Summary/evidence: live IDA MCP confirmed exact initializer/destructor/shutdown-thunk sizes, startup table bytes, vtable/static-slot data, `OleInitialize(0)`, `_atexit(0x0060c0f0)`, `OleUninitialize` teardown, and optional scalar-deleting delete behavior. C++ remains blank because final standalone filename and source-facing class/object spelling are not at the 95+ bar.
- 2026-06-06: Added explicit cross-reference to the parent-attached static object vptr page.
  - Before: the file page described `off_66D42C` but did not link the dedicated by-memory child.
  - After: references to the static slot now point to [UID:000277][0x0066d42c-0x0066d430.AutoInitStaticObjectVptr](by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md), keeping the parent file inventory aligned with the child attachment.
- 2026-06-06 provenance cleanup:
  - Scores and projected path unchanged.
  - Summary/evidence: replaced recovered-source bullets with the current IDA/by-* evidence basis; the live initializer table, shutdown thunk, destructors, vtable/static slot, and platform/OLE placement evidence remain unchanged while the standalone file versus `PlatformApi` fold stays open.
- 2026-06-10 B001-024 in-range parent-gate repair:
  - Before: scores were `82/86`, which kept the in-range scalar deleting destructor [UID:0000ZG][0x00470300-0x0047032a.AutoInit](by-memory/0x00470300-0x0047032a.AutoInit.md) below the current 85/85 direct-parent assignment gate despite strong exact evidence.
  - After: scores set to `85/87`; proposed path remains `NexusTK/platform/`.
  - Summary/evidence: the file page now has enough IDA-backed coverage to clear the 85/85 gate for this narrow OLE lifetime helper: startup initializer `0x00419ee0`, ordinary destructor `0x0046efe0`, scalar deleting destructor `0x00470300`, shutdown thunk `0x0060c0f0`, static object slot `0x0066d42c`, one-slot vtable `0x0061373c`, and `OleInitialize`/`OleUninitialize` behavior are all documented and cross-linked. Confidence stays below 90 because the final historical source-file spelling versus folding into [UID:0000ML][PlatformApi](by-file/PlatformApi.md) is still provisional.
