*** UID:0000T3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# InitializeOleSupport

## Status

- Confidence: confirmed behavior and initializer-table role; medium final source file name.
- Symbol kind: free startup initializer function
- Address: `0x00419ee0`
- Paired shutdown thunk: [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)
- Likely source module: [UID:0000HN][AutoInit](by-file/AutoInit.md) / [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Current generated source: `source-3/simroot_v2/recovered/InitializeOleSupport_00419EE0.cpp`
- Startup table entry: `0x0060d6a4 -> 0x00419ee0`

## Role

`InitializeOleSupport` initializes OLE for the process and registers the matching static shutdown thunk with `atexit`. It is part of process startup support, not a browser-window instance method.

Likely reconstructed shape:

```cpp
int InitializeOleSupport()
{
    OleInitialize(nullptr);
    return atexit(RunOleShutdownThunk);
}
```

The actual registered thunk at `0x0060c0f0` stores the anonymous `AutoInit` vtable pointer into the static object slot and tail-calls `OleUninitialize`. The same destructor policy is visible in the ordinary `AutoInit` destructor at `0x0046efe0` and scalar deleting destructor at `0x00470300`.

At source level this is best reconstructed as an anonymous/static OLE lifetime object whose constructor calls `OleInitialize(nullptr)` and whose destructor calls `OleUninitialize()`. The `atexit` thunk is compiler/static-lifetime glue for that policy.

## Evidence

- IDA MCP confirms `0x00419ee0-0x00419ef4` as a compact function that calls `OleInitialize` and `_atexit`.
- IDA MCP confirms data xref `0x0060d6a4 -> 0x00419ee0`, placing the function in the startup initializer pointer table.
- IDA MCP confirms `0x00419ee8 -> 0x0060c0f0`, registering the paired shutdown thunk.
- IDA MCP confirms `0x0060c0f0-0x0060c100` writes `off_66D42C` to the one-slot [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) at `0x0061373c` and tail-jumps to `OleUninitialize`.
- `simroot_v2` recovers this as `InitializeOleSupport` with notes matching the Wave2 report.
- 2026-05-30 IDA MCP byte/xref check confirms the exact body bytes, the initializer-table pointer at `0x0060d6a4`, the shutdown-thunk registration at `0x00419ee8`, and the static slot/vtable link through `off_66D42C` and `0x0061373c`.

## Ownership Notes

- Keep this with [UID:0000HN][AutoInit](by-file/AutoInit.md) and [UID:0000ML][PlatformApi](by-file/PlatformApi.md) for now.
- Do not attach it to [UID:0000HV][Browser](by-file/Browser.md) solely because browser code is the largest COM consumer. The evidence shows process-wide startup OLE support.
- Do not treat `AutoInit` as missing constructor evidence anymore; this global plus the `atexit` thunk provide the static lifetime evidence.

## Cross-References

- Memory: [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md), [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md), [UID:0000ZG][0x00470300-0x00470329.AutoInit](by-memory/0x00470300-0x00470329.AutoInit.md), [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)
- Vtable: [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md)
- File: [UID:0000HN][AutoInit](by-file/AutoInit.md), [UID:0000ML][PlatformApi](by-file/PlatformApi.md), [UID:0000HV][Browser](by-file/Browser.md)
- Class: [UID:00000Q][AutoInit](by-class/AutoInit.md)

## Changes

- 2026-05-28: Corrected the paired shutdown thunk evidence range from `0x0060c0f0-0x0060c0ff` to `0x0060c0f0-0x0060c100`. IDA MCP `py_eval` reports the function object for [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md) with exclusive end `0x0060c100`.
- 2026-05-30: Raised grading from unevaluated to high-confidence after rechecking body bytes and initializer links.
  - Before: the page documented the correct role but still had `COMPLETION:0` / `CONFIDENCE:0`.
  - After: the page records the startup-table pointer, static-object source interpretation, and IDA evidence tying `OleInitialize`, `_atexit`, `OleUninitialize`, `off_66D42C`, and the `AutoInit` vtable together.
  - Evidence: IDA MCP byte/xref/disassembly review of `0x00419ee0`, `0x0060c0f0`, `0x0060d6a4`, `0x0066d42c`, and `0x0061373c`.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: the validator reconstructability field was blank even though the global describes source-authored startup policy.
  - After: the global is explicitly reconstructable, with no autogen parent/code assignment until source placement reaches final-source confidence.
  - Evidence: IDA MCP confirms `0x00419ee0` calls `OleInitialize(0)` and registers the `0x0060c0f0` shutdown thunk that installs the `AutoInit` vtable and calls `OleUninitialize`.
