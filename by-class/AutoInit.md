*** UID:00000Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
class AutoInit
{
public:
    AutoInit()
    {
        OleInitialize(NULL);
    }

    virtual ~AutoInit();
};
}
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AutoInit

## Summary

`AutoInit` is a four-byte anonymous-namespace OLE/COM lifetime guard in the [UID:0000HV][Browser](by-file/Browser.md) translation unit. Its inline constructor calls `OleInitialize(NULL)`, its virtual out-of-line destructor calls `OleUninitialize`, and [UID:000277][0x0066d42c-0x0066d430.AutoInitStaticObjectVptr](by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md) causes MSVC to emit the observed startup-table entry, one-slot vtable, scalar deleting destructor, and `atexit` shutdown thunk. Those compiler artifacts remain documented but do not need hand-authored source bodies.

## Original Placement Resolution

- Source owner/emitter: [UID:0000HV][Browser](by-file/Browser.md), current project root `NexusTK/browser/Browser.cpp`.
- Exact placement evidence: AutoInit, BrowserThread, BrowserControlPaneOld, Browser, and `Singleton<BrowserThread>` RTTI/vtable names share MSVC anonymous-namespace discriminator `?A0xbc51848c@`, proving one translation unit.
- Header disposition: blank. The anonymous type is implementation-local and has no external source consumer.
- Historical correction: the old standalone `NexusTK/platform/AutoInit.cpp`, `OleSupport.cpp`, and [UID:0000ML][PlatformApi](by-file/PlatformApi.md) fold were behavior-based hypotheses. They are retained in history but superseded by exact translation-unit evidence.

## Methods

- `0x00419ee0-0x00419ef4` `InitializeOleSupport` - compiler/static-lifetime startup initializer helper that calls `OleInitialize(0)` and registers the `0x0060c0f0` shutdown thunk. It is source-policy evidence for construction/static lifetime of the anonymous OLE helper, but the exact helper is non-reconstructable and should not emit a standalone source-callable body.
- `0x0046efe0-0x0046efec` `AutoInit_NonDeletingDestructor` - writes the one-slot vtable and tail-jumps to `OleUninitialize`; no direct entry xrefs observed in current IDA.
- `0x0060c0f0-0x0060c100` `AutoInit_StaticShutdownThunk` - writes the same anonymous `AutoInit` vtable pointer into the static object slot and tail-calls `OleUninitialize`.
- `0x00470300-0x0047032a` `AutoInit_ScalarDeletingDestructor` - writes the vtable, calls `OleUninitialize`, and optionally deletes the object when the low deletion flag bit is set.
- `0x0061373c` [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) - one visible slot pointing to the scalar deleting destructor.

## Source Shape Hypothesis

The recoverable source shape is now formal: a CPP-only unnamed-namespace `AutoInit` with an inline `OleInitialize(NULL)` constructor and virtual out-of-line destructor, followed by `static AutoInit s_autoInit;` from UID000277. Construction initializes OLE for the process; compiler startup glue registers static shutdown; authored destruction uninitializes OLE. Do not add a low-level `InitializeOleSupport` method, explicit vtable, scalar deleting destructor, or shutdown-thunk body: those are compiler-lowered consequences of the class and instance source.

The class has no source-declared base or data member. Its complete size is four bytes because its only storage is the virtual-table pointer, RTTI has one self base, the vtable has one destructor slot, and the scalar deleting path passes size `4` to delete. The exact class name `AutoInit` is original-proof from RTTI; the object name `s_autoInit` is the strongest project-consistent inference after no original object symbol or IDA UDT survived.

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
- 2026-06-16 Agent-C001 IDA MCP `lookup_funcs` found raw names `sub_419EE0`, `sub_46EFE0`, `sub_470300`, and `sub_60C0F0`; a dry-run rename had zero conflicts, and post-rename lookup confirms `InitializeOleSupport`, `AutoInit_NonDeletingDestructor`, `AutoInit_ScalarDeletingDestructor`, and `AutoInit_StaticShutdownThunk`.
- 2026-06-16 `analyze_component` reconfirms `InitializeOleSupport` size `20`, callees `OleInitialize` and `_atexit`; scalar deleting destructor size `42`, callees `OleUninitialize` and delete helper; ordinary destructor size `12`; shutdown thunk size `16`; and shared vtable global `0x0061373c` accessed by the destructor/shutdown paths.
- 2026-06-16 `xrefs_to` reconfirms startup table `0x0060d6a4 -> 0x00419ee0`, vtable slot `0x0061373c -> 0x00470300`, atexit registration `0x00419ee8 -> 0x0060c0f0`, vtable pointer refs from `0x0046efe0`, `0x00470306`, `0x0060c0f0`, and `0x0066d42c`, plus the direct static slot xref from `0x0060c0f0` to `0x0066d42c`.
- 2026-07-04 Agent-B013 MCP session `6eab6bcb` reconfirmed the same source-policy chain and resolved UID0000W8's emitter status: `0x00419ee0` is a `0x14` / 20 decimal byte helper (Verified with `int_convert.py`) with no ordinary callers, one startup-table data xref from `0x0060d6a4`, body `OleInitialize(0); return atexit(sub_60C0F0);`, startup-table neighbor bytes around `0x0060d6a0`, import endpoints `0x0060d668`/`0x0060d650`, paired shutdown thunk `0x0060c0f0`, static slot `0x0066d42c`, and vtable `0x0061373c`. The class/source policy remains reconstructable, while the exact UID0000W8 helper is non-emitting startup glue.

## Source-Quality Closure And Negative Evidence

- Exact function/range evidence: startup `0x00419ee0-0x00419ef4` (`0x14` bytes), ordinary destructor `0x0046efe0-0x0046efec` (`0x0c` bytes), scalar wrapper `0x00470300-0x0047032a` (`0x2a` bytes), and shutdown thunk `0x0060c0f0-0x0060c100` (`0x10` bytes).
- Exact data evidence: object `0x0066d42c-0x0066d430` starts with vtable `0x0061373c`; RTTI COL `0x0064314c`, type descriptor `0x00674b84`, and CHD/BCD prove one self base and no wider layout.
- Exact xrefs: startup table `0x0060d6a4 -> 0x00419ee0`; startup body `0x00419ee8 -> 0x0060c0f0`; vtable refs from ordinary/scalar/shutdown/object paths; target slot written only by shutdown.
- No independent constructor function, ordinary caller to the startup helper, second vtable slot, additional base/data field, exported type/object consumer, or alternate target-pointer table was found.
- Browser's COM use is not itself ownership proof. The exact shared anonymous-namespace discriminator is the accepted source-placement proof; runtime OLE behavior remains process-wide.
- The literal original static-object identifier and filename were stripped. They no longer block source: `s_autoInit` is the final best inferred human spelling, and Browser is the established reconstruction root for the proven translation unit.

## Cross-References

- File: [UID:0000HN][AutoInit](by-file/AutoInit.md)
- Related file candidate: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Related files: [UID:0000HV][Browser](by-file/Browser.md)
- Global: [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md)
- Vtable: [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md)
- Memory: [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md), [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md), [UID:0000ZG][0x00470300-0x0047032a.AutoInit](by-memory/0x00470300-0x0047032a.AutoInit.md), [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)

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
- 2026-06-16 Agent-C001: Raised grading from `82/88` to `85/89` and applied safe IDA function renames for the initializer/destructor/shutdown paths.
  - Before: the page had strong OLE lifetime evidence but still referenced raw IDA function names and did not reflect the newer static-slot/vtable/global support evidence.
  - After: the page records current IDA names, refreshed startup/vtable/static-slot xrefs, and the explicit reason the static object slot and final C++ remain blocked.
  - Evidence: live IDA MCP `lookup_funcs`, `analyze_component`, `xrefs_to`, dry-run `rename`, verified post-rename lookup, and saved IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- 2026-07-04 B013 UID0000W8 source-route sync:
  - Before: the class page listed `InitializeOleSupport` as the startup-side equivalent for the source object but did not explicitly prevent a standalone helper emitter for UID0000W8.
  - After: the class page records UID0000W8 as non-emitting compiler/static-lifetime startup glue and keeps the source-level AutoInit lifetime policy as the reconstructable concept.
  - Evidence: B013 report `tools/leaser/Agents/Agent-B013/research/0000W8-InitializeOleSupport-source-quality.md` and MCP session `6eab6bcb`.
- 2026-07-26 B004 UID000277 source-quality callback:
  - Before: `85/89`, owner/emitter UID0000HN, blank formal CPP/H, and current placement/name questions blocked source emission.
  - After: `94/96`, owner/emitter UID0000HV, exact CPP-only anonymous class with inline `OleInitialize(NULL)` constructor and virtual destructor declaration, and blank H.
  - Evidence: current MCP RTTI/COL/CHD/BCD and xref analysis proves a four-byte one-vptr/no-base class, complete OLE lifetime lowering, and exact Browser-family anonymous-namespace discriminator `?A0xbc51848c@`.
  - Historical correction: standalone AutoInit/OleSupport/PlatformApi placement and a raw `off_66D42C` object name are preserved as superseded assumptions; Browser-TU placement and `s_autoInit` are now the accepted source reconstruction.
