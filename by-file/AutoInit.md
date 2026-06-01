*** UID:0000HN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AutoInit

## Status

- Confidence: strong for OLE startup/shutdown behavior and destructor/vtable ownership; medium for standalone source file versus folding into [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
- Proposed module: `platform/AutoInit.cpp`, `platform/OleSupport.cpp`, or [UID:0000ML][PlatformApi](by-file/PlatformApi.md).
- Current recovered source: `source-3/simroot_v2/class_AutoInit.cpp`
- Related recovered global: `source-3/simroot_v2/recovered/InitializeOleSupport_00419EE0.cpp`

## File Role

`AutoInit.cpp` is a source candidate for a tiny application-wide OLE/COM lifetime helper. The startup side is now confirmed: [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) at `0x00419ee0` calls `OleInitialize(0)` and registers the [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md) through `atexit`. The ordinary destructor at [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md) resets the vtable and calls `OleUninitialize`; the scalar deleting destructor at [UID:0000ZG][0x00470300-0x00470329.AutoInit](by-memory/0x00470300-0x00470329.AutoInit.md) wraps the same teardown and optionally deletes the object.

This looks like a static anonymous-namespace lifetime object rather than an allocation-heavy runtime class. The `0x0060c0f0` shutdown thunk writes the anonymous [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) into the static object slot and tail-calls `OleUninitialize`.

The likely source-level shape is a tiny anonymous/static object:

```cpp
namespace {

class AutoInit {
public:
    AutoInit() { OleInitialize(nullptr); }
    ~AutoInit() { OleUninitialize(); }
};

AutoInit g_autoInit;

} // namespace
```

## Boundary Notes

Browser/OLE code remains the largest visible COM consumer, but current evidence is process-wide startup/shutdown support. Keep this in a platform/OLE support bucket unless historical source evidence proves it lived beside browser code.

Do not look for a normal heap constructor call before placing this helper; the known initialization path is the startup initializer table entry at `0x0060d6a4`, not a `new AutoInit`. Active `simroot_v2` still omits the ordinary destructor and vtable inventory, so source placement should use the IDA-backed memory/type docs rather than the generated one-method class file alone.

IDA MCP recheck on 2026-05-30 confirms the static initializer pointer table bytes at `0x0060d6a4`, `InitializeOleSupport` body at `0x00419ee0-0x00419ef4`, the shutdown thunk at `0x0060c0f0-0x0060c100`, and the static slot/vtable relationship through `off_66D42C` and `0x0061373c`.

## Cross-References

- [UID:00000Q][AutoInit](by-class/AutoInit.md)
- [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md)
- [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md)
- [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md)
- [UID:0000ZG][0x00470300-0x00470329.AutoInit](by-memory/0x00470300-0x00470329.AutoInit.md)
- [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)
- [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md)
- [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- [UID:0000HV][Browser](by-file/Browser.md)

## Changes

- 2026-05-30: Added the likely source-level static object shape and raised grading from unevaluated.
  - Before: the file page had correct OLE startup/shutdown notes but still used `COMPLETION:0` / `CONFIDENCE:0`.
  - After: the file page records a concrete `AutoInit` constructor/destructor reconstruction shape and the IDA-confirmed initializer-table/shutdown evidence.
  - Evidence: IDA MCP confirms the initializer-table pointer at `0x0060d6a4`, `OleInitialize`/`_atexit` body at `0x00419ee0`, shutdown thunk `0x0060c0f0`, and the `AutoInit` vtable/static slot link.
