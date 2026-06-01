*** UID:00000Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AutoInit

## Summary

`AutoInit` is a tiny OLE/COM lifetime helper. The normal startup side is represented by [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) at `0x00419ee0`, which calls `OleInitialize(0)` and registers the [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md) with `atexit`. IDA now confirms both the ordinary non-deleting destructor at [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md) and the scalar deleting destructor at [UID:0000ZG][0x00470300-0x00470329.AutoInit](by-memory/0x00470300-0x00470329.AutoInit.md).

## Likely Original Placement

- Source: [UID:0000HN][AutoInit](by-file/AutoInit.md), with [UID:0000ML][PlatformApi](by-file/PlatformApi.md) as an adjacent platform/OLE bucket
- Proposed path: `platform/AutoInit.cpp`, `platform/OleSupport.cpp`, or `platform/PlatformApi.cpp`
- Confidence: medium for source placement; strong for startup/shutdown behavior

## Methods

- `0x00419ee0` `InitializeOleSupport` - global/static initializer that calls `OleInitialize(0)` and registers the `0x0060c0f0` shutdown thunk. Source-level constructor equivalent for the anonymous/static OLE lifetime object.
- `0x0046efe0` ordinary non-deleting destructor - resets the vtable and tail-jumps to `OleUninitialize`; no direct entry xrefs observed in current IDA.
- `0x0060c0f0` OLE shutdown thunk - resets the anonymous `AutoInit` static vtable slot and tail-calls `OleUninitialize`.
- `0x00470300` scalar deleting destructor - calls `OleUninitialize` and optionally deletes the object.
- `0x0061373c` [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) - one visible slot pointing to the scalar deleting destructor.

## Reconstructed Shape

```cpp
namespace {

class AutoInit {
public:
    AutoInit()
    {
        OleInitialize(nullptr);
    }

    ~AutoInit()
    {
        OleUninitialize();
    }
};

AutoInit g_autoInit;

} // namespace
```

## Evidence

- Wave3 reports a one-method class.
- Generated source calls `OleUninitialize`.
- IDA MCP confirms the function at `0x00470300-0x0047032a`.
- IDA MCP confirms the ordinary destructor at `0x0046efe0-0x0046efeb`; the body stores the anonymous `AutoInit` vtable pointer and jumps to `OleUninitialize`.
- IDA data inspection confirms the one-slot `AutoInit` vtable at `0x0061373c`, with RTTI at `0x00613738` and next adjacent RTTI/vtable data for `BrowserThread` at `0x00613740`.
- IDA MCP confirms `InitializeOleSupport` at `0x00419ee0-0x00419ef4`, with data xref from startup initializer table entry `0x0060d6a4`.
- IDA MCP confirms `InitializeOleSupport` registers shutdown thunk `0x0060c0f0` through `_atexit`; the thunk writes the anonymous `AutoInit` vtable pointer and calls `OleUninitialize`.
- 2026-05-30 IDA MCP byte/xref review confirms the startup initializer table entry at `0x0060d6a4`, the shutdown thunk pointer pushed at `0x00419ee8`, the static slot `off_66D42C`, and the vtable pointer `0x0061373c`.
- Current `simroot_v2/class_AutoInit.cpp` still emits only the scalar deleting destructor and `class_AutoInit.meta_wave3` reports `vtable_count: 0`; treat those as Wave3 data gaps rather than class-ownership evidence.

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
