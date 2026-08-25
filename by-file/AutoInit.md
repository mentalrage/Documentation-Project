*** UID:0000HN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# AutoInit

## Status

- Confidence: very strong for OLE startup/shutdown behavior, static object/class/vtable ownership, compiler-generated boundaries, and Browser translation-unit placement.
- Current disposition: reviewed historical/index page with path `NONE`; it is not a standalone generated source root.
- Source destination: [UID:0000HV][Browser](by-file/Browser.md), current project module `NexusTK/browser/Browser.cpp`.
- Documentation basis: live IDA startup/shutdown evidence plus the by-class, by-global, by-memory, and by-type pages linked below.

## File Role

This page is the durable AutoInit family/index, not an `AutoInit.cpp` source emitter. The startup side is confirmed but non-emitting: [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) / [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md) calls `OleInitialize(NULL)` and registers [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md) through `atexit`. The ordinary destructor UID0000ZE carries authored `AutoInit::~AutoInit()` source; the scalar deleting destructor UID0000ZG is compiler ABI glue.

This looks like a static anonymous-namespace lifetime object rather than an allocation-heavy runtime class. The `0x0060c0f0` shutdown thunk writes the anonymous [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) into the static object slot [UID:000277][0x0066d42c-0x0066d430.AutoInitStaticObjectVptr](by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md) and tail-calls `OleUninitialize`.

The accepted source-level shape is a tiny Browser-TU lifetime guard: CPP-only anonymous class `AutoInit`, inline `OleInitialize(NULL)` constructor, virtual out-of-line destructor calling `OleUninitialize`, and `static AutoInit s_autoInit;`. The toolchain emits startup/cleanup glue, vtable, and scalar wrapper. Do not create a callable `InitializeOleSupport` body or standalone AutoInit module.

## Boundary Notes

OLE lifetime remains process-wide rather than Browser instance state. Source placement is nevertheless Browser's translation unit because AutoInit, BrowserThread, BrowserControlPaneOld, Browser, and `Singleton<BrowserThread>` RTTI/vtable identities share exact anonymous-namespace discriminator `?A0xbc51848c@`.

Do not look for a normal heap constructor call before placing this helper; the known initialization path is the startup initializer table entry at `0x0060d6a4`, not a `new AutoInit`. Source placement should use the IDA-backed memory/type docs rather than recovered-output shape alone, and the startup-table-only route is also why UID0000W8 is now non-emitting glue instead of a reconstructable standalone helper.

IDA MCP recheck on 2026-05-30 confirms the static initializer pointer table bytes at `0x0060d6a4`, `InitializeOleSupport` body at `0x00419ee0-0x00419ef4`, the shutdown thunk at `0x0060c0f0-0x0060c100`, and the static slot/vtable relationship through `off_66D42C` and `0x0061373c`.

2026-06-04 live IDA MCP recheck confirms `0x00419ee0` size `0x14`, `0x0046efe0` size `0x0c`, `0x00470300` size `0x2a`, and `0x0060c0f0` size `0x10`. Disassembly shows `InitializeOleSupport` calling `OleInitialize(0)` and `_atexit(0x0060c0f0)`, the ordinary destructor writing vtable `0x0061373c` then jumping to `OleUninitialize`, the scalar deleting destructor calling `OleUninitialize` and optional delete helper with size `4`, and the shutdown thunk writing `off_66D42C = 0x0061373c`.

Live IDA data inspection confirms startup table neighbors `0x0060d6a0 -> 0x00419ec0`, `0x0060d6a4 -> 0x00419ee0`, and `0x0060d6a8 -> 0x00419f00`; vtable neighborhood `0x00613738 -> 0x0064314c`, `0x0061373c -> 0x00470300`, `0x00613740 -> 0x0064325c`; and static slot [UID:000277][0x0066d42c-0x0066d430.AutoInitStaticObjectVptr](by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md) / `off_66D42C` at `0x0066d42c` currently containing `0x0061373c`.

2026-07-04 B013 implementation callback refreshed the source-shape decision for [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md). MCP session `6eab6bcb` reconfirmed the exact `0x00419ee0-0x00419ef4` function, `0x14` / 20 decimal byte size (Verified with `int_convert.py`), no ordinary callers, sole startup-table xref `0x0060d6a4`, body `OleInitialize(0); return atexit(sub_60C0F0);`, import addresses `0x0060d668` and `0x0060d650`, bytes around `0x00419ed0`, startup-table neighbors, shutdown thunk `0x0060c0f0`, static slot `0x0066d42c`, and vtable `0x0061373c`. Its then-current conclusion that this file remained source-policy owner is now historical and superseded by UID000277's translation-unit analysis.

## UID000277 Historical-Route Closure - 2026-07-26

- Exact RTTI names place AutoInit in the same anonymous namespace/translation unit as the Browser family. That evidence resolves the older standalone `NexusTK/platform/AutoInit.cpp`, `OleSupport.cpp`, and PlatformApi-fold hypotheses.
- UID00000Q emits the anonymous class through Browser; UID0000ZE emits the ordinary destructor through the class; UID000277 emits `static AutoInit s_autoInit;` through Browser.
- UID0001X0 vtable, UID0000ZG scalar wrapper, UID0000W8 startup helper, UID0000T3 name index, and UID0001O6 shutdown thunk remain linked here as compiler/generated evidence but do not emit source.
- Complete-object proof is exact: target storage is four bytes, initialized to one-slot vtable `0x0061373c`; RTTI has one self base/no inheritance; scalar delete size is `4`; startup and teardown use one object/vtable chain.
- Negative evidence rejects a standalone source root: no independent filename/symbol boundary, no separate API, no ordinary startup-helper caller, and no translation-unit discriminator distinct from Browser exists.
- Historical notes below are retained to show how the earlier platform/OLE hypothesis arose and why it was later corrected. They are not current placement instructions.
- Score `92/96` reflects a complete reviewed family/index and historical correction. Path `NONE` prevents an empty standalone generated source file while preserving all evidence.

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
- 2026-07-04 B013 UID0000W8 source-route sync:
  - Before: the file page treated the startup side as confirmed behavior but did not distinguish that the exact `0x00419ee0` by-memory helper should no longer emit as a standalone reconstructable body.
  - After: the file page records UID0000W8 as AutoInit source-policy evidence but non-emitting compiler/static-lifetime startup glue. The file path caveat remains `NexusTK/platform/AutoInit.cpp` versus a later [UID:0000ML][PlatformApi](by-file/PlatformApi.md) fold.
  - Evidence: B013 report `tools/leaser/Agents/Agent-B013/research/0000W8-InitializeOleSupport-source-quality.md` and MCP session `6eab6bcb` target/shutdown/static-slot/vtable checks.
- 2026-07-26 B004 UID000277 callback:
  - Before: `85/87`, path `NexusTK/platform/`, current standalone AutoInit versus PlatformApi uncertainty, and five downstream empty emitters.
  - After: `92/96`, path `NONE`, historical/index-only role, with source-bearing family members routed to Browser and generated artifacts non-emitting.
  - Evidence: exact Browser-family anonymous-namespace discriminator, complete RTTI/layout/lifetime analysis, and accepted formal class/destructor/static-object C++.
