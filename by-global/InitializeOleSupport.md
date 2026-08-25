*** UID:0000T3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# InitializeOleSupport

## Status

- Confidence: very strong for behavior, initializer-table role, non-emitting startup-glue disposition, AutoInit class ownership, and Browser translation-unit placement.
- Symbol kind: documentation/descriptive name for compiler/static-lifetime startup initializer glue
- Address: `0x00419ee0`
- Paired shutdown thunk: [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)
- Source-policy owner: [UID:00000Q][AutoInit](by-class/AutoInit.md), emitted through [UID:0000HV][Browser](by-file/Browser.md).
- Historical generated artifact: `source-3/simroot_v2/recovered/InitializeOleSupport_00419EE0.cpp`; do not treat it as current source authority.
- Startup table entry: `0x0060d6a4 -> 0x00419ee0`
- Reconstruction status: name-centric index for non-emitting startup glue attached to the `AutoInit` OLE lifetime policy. Keep final C++ blank; the exact `0x00419ee0` helper is compiler/static-lifetime startup machinery reached only through the initializer table, not a source-callable body.

## Role

`InitializeOleSupport` initializes OLE for the process and registers the matching static shutdown thunk with `atexit`. It is part of process startup support, not a browser-window instance method. The name is retained as a useful documentation/global index, but current MCP evidence and the matching by-memory page classify the exact helper as non-reconstructable startup glue rather than a standalone source emitter.

Low-level binary equivalent, retained as behavior evidence only:

```cpp
int InitializeOleSupport()
{
    OleInitialize(NULL);
    return atexit(RunOleShutdownThunk);
}
```

Do not emit that body as final source for this global. The actual registered thunk at `0x0060c0f0` stores the anonymous `AutoInit` vtable pointer into the static object slot and tail-calls `OleUninitialize`. The same destructor policy is visible in the ordinary `AutoInit` destructor at `0x0046efe0` and scalar deleting destructor at `0x00470300`.

At source level this is reconstructed as an anonymous/static OLE lifetime object whose constructor calls `OleInitialize(NULL)` and whose destructor calls `OleUninitialize()`. The `atexit` thunk is compiler/static-lifetime glue for that policy.

## Evidence

- IDA MCP confirms `0x00419ee0-0x00419ef4` as a compact function that calls `OleInitialize` and `_atexit`.
- IDA MCP confirms data xref `0x0060d6a4 -> 0x00419ee0`, placing the function in the startup initializer pointer table.
- IDA MCP confirms `0x00419ee8 -> 0x0060c0f0`, registering the paired shutdown thunk.
- IDA MCP confirms `0x0060c0f0-0x0060c100` writes `off_66D42C` to the one-slot [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) at `0x0061373c` and tail-jumps to `OleUninitialize`.
- `simroot_v2` recovers this as `InitializeOleSupport` with notes matching the Wave2 report.
- 2026-05-30 IDA MCP byte/xref check confirms the exact body bytes, the initializer-table pointer at `0x0060d6a4`, the shutdown-thunk registration at `0x00419ee8`, and the static slot/vtable link through `off_66D42C` and `0x0061373c`.
- 2026-06-14 live IDA MCP `analyze_function 0x00419ee0` reports `sub_419EE0`, prototype `int()`, size `0x14` / 20 decimal bytes (Verified with int_convert.py), one basic block, no ordinary callers, data xref from startup table entry `0x0060d6a4`, and callees `OleInitialize` and `_atexit`. The same result decompiles to `OleInitialize(0); return atexit(sub_60C0F0);` and disassembles as `push 0`, `call ds:OleInitialize`, `push offset sub_60C0F0`, `call _atexit`, `pop ecx`, `retn`.
- 2026-07-04 Agent-B013 MCP session `6eab6bcb` reconfirms the exact `0x00419ee0-0x00419ef4` function, `0x00419ef4` not a function start, no ordinary callers, one startup-table data xref from `0x0060d6a4`, raw helper bytes `6a 00 ff 15 68 d6 60 00 68 f0 c0 60 00 e8 b1 dc 1a 00 59 c3`, startup table neighbors `0x0060d6a0 -> 0x00419ec0`, `0x0060d6a4 -> 0x00419ee0`, `0x0060d6a8 -> 0x00419f00`, import endpoints `0x0060d668`/`0x0060d650`, paired shutdown thunk `0x0060c0f0`, static object slot `0x0066d42c`, and vtable `0x0061373c`. This resolved the global as a name-centric/non-emitting index for AutoInit startup glue, not an emitting helper.

## Ownership And Placement Resolution

- Canonical owner is [UID:00000Q][AutoInit](by-class/AutoInit.md); this index has no emitter because the exact helper is compiler startup machinery.
- Source placement is [UID:0000HV][Browser](by-file/Browser.md), proven by AutoInit's exact anonymous-namespace discriminator shared with Browser-family RTTI. Browser's COM use alone would not have been sufficient.
- Process-wide startup OLE support is runtime behavior, not Browser instance state. Translation-unit placement and runtime ownership are distinct.
- Do not treat `AutoInit` as missing constructor evidence anymore; this global plus the `atexit` thunk provide the static lifetime evidence.

## Parent Attachment Guidance

Use UID00000Q as the source-policy owner. The matching by-memory page, one-slot vtable, static object, ordinary destructor, scalar wrapper, and shutdown thunk form one class/lifetime chain. UID0000HN remains a historical family index with path `NONE`; standalone AutoInit and PlatformApi folding are rejected. This global remains nonreconstructable with blank emitter/CPP/H because preserving a useful documentation name does not require a source definition.

## UID000277 Name-Index Closure - 2026-07-26

- `InitializeOleSupport` is a descriptive documentation/index name for raw `sub_419EE0`; no original project symbol proves a callable global by that name.
- Exact live body/range: `0x00419ee0-0x00419ef4`, size `0x14`/20, one block, no ordinary callers, sole data xref from startup table `0x0060d6a4`, calls `OleInitialize(NULL)` and `atexit(0x0060c0f0)`.
- The shutdown thunk restores UID000277's AutoInit vptr and calls `OleUninitialize`; the ordinary destructor supplies the authored source body and the scalar destructor is generated ABI glue.
- Shared namespace discriminator `?A0xbc51848c@` resolves Browser-TU placement. The exact class/object source is carried by UID00000Q and UID000277, so this global/index stays blank CPP/H.
- Negative evidence: no ordinary caller, exported declaration, independent source API, alternate owner, or reason to emit this low-level helper exists.
- Score `92/96` records complete index/behavior/route/no-code coverage. Literal original object/file spelling is unavailable but has an accepted best source reconstruction elsewhere.

## Score Rationale

- Completion is `92` because body, size, startup-table xref, shutdown pairing, class owner, Browser placement, related destructor/vtable/static-object chain, historical name role, and final no-emitter decision are closed.
- Confidence is `96` because live IDA and linked source pages agree on exact behavior and lowering. The only unavailable data is literal stripped source spelling, which no longer blocks the accepted class/object source.

## Cross-References

- Memory: [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md), [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md), [UID:0000ZG][0x00470300-0x0047032a.AutoInit](by-memory/0x00470300-0x0047032a.AutoInit.md), [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md)
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
- 2026-06-07 A007 parent attachment:
  - Before: `AUTOGEN_PARENT_UID` was blank, while the matching by-memory page and class page were already attached to [UID:0000HN][AutoInit](by-file/AutoInit.md).
  - After: set `AUTOGEN_PARENT_UID:0000HN`, added explicit autogen-parent/reconstruction status bullets, and recorded parent attachment guidance.
  - Evidence: [UID:0000HN][AutoInit](by-file/AutoInit.md), [UID:00000Q][AutoInit](by-class/AutoInit.md), [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md), [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md), and [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) all document the same process-wide OLE lifetime helper. No score or final C++ change was made because final file folding and source-facing object spelling remain open.
- 2026-06-14 A003 live MCP refresh:
  - Before: score `80/90`; the page had correct OLE lifetime evidence but lacked the current session's compact body/caller/callee/size confirmation and explicit score rationale.
  - After: score `84/91`; added current `analyze_function` evidence, verified size conversion, and documented why C++ remains blank despite the emitter route and average score now clearing the minimum code-entry gate.
  - Evidence: live IDA MCP session `a001_goal2_class_batch` reported `sub_419EE0` size `0x14` / 20 decimal bytes (Verified with int_convert.py), one basic block, data xref from `0x0060d6a4`, callees `OleInitialize` and `_atexit`, no ordinary callers, and the exact `OleInitialize(0)` / `atexit(sub_60C0F0)` body.
- 2026-07-04 B013 UID0000W8 source-route sync:
  - Before: the global page remained reconstructable with `EMITTER_UIDS:0000HN` and described the low-level helper body as a likely reconstructed shape.
  - After: set `COMPLETION:86`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and retained blank C++. The page now keeps `InitializeOleSupport` as a documentation/name-centric index for AutoInit startup policy while rejecting standalone source emission for the exact helper.
  - Evidence: B013 report `tools/leaser/Agents/Agent-B013/research/0000W8-InitializeOleSupport-source-quality.md`; MCP session `6eab6bcb` confirmed exact range, no ordinary callers, sole startup-table xref, raw bytes, import endpoints, startup table neighbors, paired shutdown thunk, static object slot, and vtable chain.
- 2026-07-26 B004 UID000277 callback:
  - Before: `86/92`, owner UID0000HN, non-emitting index with current AutoInit/PlatformApi placement uncertainty.
  - After: `92/96`, owner UID00000Q, nonreconstructable/non-emitting, Browser-TU placement, and exact inline-constructor/static-object destination.
  - Historical correction: the old standalone helper example and file-fold question remain behavioral history, not formal source or a current blocker.
