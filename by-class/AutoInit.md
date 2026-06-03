*** UID:00000Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AutoInit

## Summary

`AutoInit` is a tiny anonymous/static OLE/COM lifetime helper. The normal startup side is represented by [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) at `0x00419ee0`, which calls `OleInitialize(0)` and registers the [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md) with `atexit`. Live IDA confirms both the ordinary non-deleting destructor at [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md) and the scalar deleting destructor at [UID:0000ZG][0x00470300-0x00470329.AutoInit](by-memory/0x00470300-0x00470329.AutoInit.md).

## Likely Original Placement

- Source: [UID:0000HN][AutoInit](by-file/AutoInit.md), with [UID:0000ML][PlatformApi](by-file/PlatformApi.md) as an adjacent platform/OLE bucket.
- Proposed path: `NexusTK/platform/AutoInit.cpp`, with possible later folding into `PlatformApi.cpp` if historical source grouping proves that.
- Confidence: strong for startup/shutdown behavior and class/vtable identity; medium for final standalone filename.

## Methods

- `0x00419ee0-0x00419ef4` `InitializeOleSupport` - global/static initializer that calls `OleInitialize(0)` and registers the `0x0060c0f0` shutdown thunk. Source-level constructor equivalent for the anonymous/static OLE lifetime object.
- `0x0046efe0-0x0046efec` ordinary non-deleting destructor - writes the one-slot vtable and tail-jumps to `OleUninitialize`; no direct entry xrefs observed in current IDA.
- `0x0060c0f0-0x0060c100` OLE shutdown thunk - writes the same anonymous `AutoInit` vtable pointer into the static object slot and tail-calls `OleUninitialize`.
- `0x00470300-0x0047032a` scalar deleting destructor - writes the vtable, calls `OleUninitialize`, and optionally deletes the object when the low deletion flag bit is set.
- `0x0061373c` [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) - one visible slot pointing to the scalar deleting destructor.

## Source Shape Hypothesis

The recoverable source shape is a file-local OLE lifetime guard: construction initializes OLE for the process, static shutdown uninitializes it through the `atexit` thunk, and the virtual destructor/scalar-deleting destructor are ABI-side teardown paths for the same helper. Final C++ remains blank because the exact standalone filename and source-facing class/object names are still provisional.

## Evidence

- 2026-06-04 live IDA MCP `lookup_funcs` confirms `0x00419ee0` size `0x14`, `0x0046efe0` size `0x0c`, `0x00470300` size `0x2a`, and `0x0060c0f0` size `0x10`.
- Live IDA decompilation/disassembly of `0x00419ee0` shows `push 0`, `call OleInitialize`, `push 0x0060c0f0`, and `call _atexit`.
- Live IDA data inspection confirms startup table dwords around this entry: `0x0060d6a0 -> 0x00419ec0`, `0x0060d6a4 -> 0x00419ee0`, and `0x0060d6a8 -> 0x00419f00`.
- Live IDA confirms the ordinary destructor at `0x0046efe0-0x0046efec`; the body stores the anonymous `AutoInit` vtable pointer and jumps to `OleUninitialize`.
- Live IDA confirms the scalar deleting destructor at `0x00470300-0x0047032a`; it writes the vtable, calls `OleUninitialize`, tests `(flags & 1)`, and calls the delete helper with size `4` when needed.
- Live IDA confirms the static shutdown thunk at `0x0060c0f0-0x0060c100`; it writes `off_66D42C = 0x0061373c` and jumps to `OleUninitialize`.
- IDA data inspection confirms the one-slot `AutoInit` vtable at `0x0061373c`, with RTTI at `0x00613738` and next adjacent RTTI/vtable data for `BrowserThread` at `0x00613740`.
- IDA MCP confirms `InitializeOleSupport` at `0x00419ee0-0x00419ef4`, with data xref from startup initializer table entry `0x0060d6a4`.
- IDA MCP confirms `InitializeOleSupport` registers shutdown thunk `0x0060c0f0` through `_atexit`; the thunk writes the anonymous `AutoInit` vtable pointer and calls `OleUninitialize`.
- 2026-05-30 IDA MCP byte/xref review confirms the startup initializer table entry at `0x0060d6a4`, the shutdown thunk pointer pushed at `0x00419ee8`, the static slot `off_66D42C`, and the vtable pointer `0x0061373c`.
- 2026-06-04 live IDA xrefs to `0x0061373c` land at `0x0046efe0`, `0x00470306`, `0x0060c0f0`, and the static slot `0x0066d42c`; the static slot currently contains `0x0061373c`.

## Open Questions

- Decide final filename: `AutoInit.cpp`, `OleSupport.cpp`, or folded into `PlatformApi.cpp`.
- Browser COM code calls COM/OLE APIs heavily, so a browser/OLE support file remains plausible, but current evidence is process-wide startup support.

## Cross-References

- File: [UID:0000HN][AutoInit](by-file/AutoInit.md)
- Related file candidate: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Related files: [UID:0000HV][Browser](by-file/Browser.md)
- Global: [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md)
- Vtable: [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md)
- Memory: [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md), [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md), [UID:0000ZG][0x00470300-0x00470329.AutoInit](by-memory/0x00470300-0x00470329.AutoInit.md), [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)

## Changes

- 2026-05-30: Added the source-level anonymous/static object reconstruction shape and raised grading from unevaluated.
  - Before: the page had correct startup/destructor facts but still used `COMPLETION:0` / `CONFIDENCE:0` and lacked a source-level class shape.
  - After: the page records `AutoInit` as an anonymous/static OLE lifetime object with constructor/destructor policy and IDA-confirmed initializer/shutdown evidence.
  - Evidence: IDA MCP confirms `0x00419ee0` calls `OleInitialize(0)`, pushes `0x0060c0f0`, calls `_atexit`, and links to the static vtable slot through `off_66D42C` / `0x0061373c`.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: the validator reconstructability field was blank despite IDA-confirmed NexusTK source semantics.
  - After: the class is explicitly marked reconstructable while autogen parent and C++ fields remain blank because final source-file ownership is still below the `95+` final-code gate.
  - Evidence: IDA MCP confirms the process-wide OLE initializer, ordinary destructor, scalar deleting destructor, one-slot vtable, and static object vptr relationship.
- 2026-06-04 live IDA MCP evidence and parent assignment:
  - Before: scores were `70/85`, autogen parent was blank, and the page still leaned on generated-source caveats.
  - After: scores set to `82/88`, attached to [UID:0000HN][AutoInit](by-file/AutoInit.md), and final C++ emission remains blank.
  - Summary/evidence: live IDA MCP confirmed exact function sizes, `OleInitialize(0)` and `_atexit(0x0060c0f0)`, startup table bytes at `0x0060d6a4`, ordinary/scalar/static teardown paths, the one-slot vtable at `0x0061373c`, and static object slot `off_66D42C`. Remaining uncertainty is final standalone filename/source-facing object name, not behavior.
