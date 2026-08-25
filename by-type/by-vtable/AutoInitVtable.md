*** UID:0001X0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AutoInit Vtable

## Scope

- Entity kind: vtable
- Vtable address: `0x0061373c`
- RTTI pointer: `0x00613738 -> 0x0064314c`
- Current IDA name: `??_7AutoInit@?A0xbc51848c@@6B@`
- Owner: [UID:00000Q][AutoInit](by-class/AutoInit.md)
- Source module: [UID:0000HV][Browser](by-file/Browser.md), proven by the shared anonymous-namespace discriminator
- Rebuild handling: compiler-generated/non-emitting. The exact virtual destructor declaration in UID00000Q causes this table; do not hand-port `.rdata` bytes.
- Formal CPP/H: blank by design.
- Confidence: near-final for layout, RTTI, ownership, placement, and no-code disposition

## Layout

| Address | Slot | Target | Notes |
| --- | --- | --- | --- |
| `0x00613738` | RTTI | `0x0064314c` | IDA names this `AutoInit` RTTI data. |
| `0x0061373c` | `0` | `0x00470300` | [UID:0000ZG][0x00470300-0x0047032a.AutoInit](by-memory/0x00470300-0x0047032a.AutoInit.md). |
| `0x00613740` | next RTTI | `0x0064325c` | Start of adjacent `BrowserThread` RTTI/vtable family, not an `AutoInit` slot. |

## Evidence

- IDA data inspection names `0x0061373c` as `??_7AutoInit@?A0xbc51848c@@6B@`.
- The single vtable slot points to `0x00470300`, the IDA-confirmed scalar deleting destructor.
- 2026-05-31 IDA MCP `lookup_funcs` confirms `0x00470300` (`sub_470300`, size `0x2a`), `0x0046efe0` (`sub_46EFE0`, size `0xc`), `0x00419ee0` (`sub_419EE0`, size `0x14`), and `0x0060c0f0` (`sub_60C0F0`, size `0x10`); `0x00613738`, `0x0061373c`, and `0x00613740` are data, not functions.
- 2026-05-31 IDA MCP `py_eval` byte review of `0x00613738-0x00613758` reports dwords `0x0064314c`, `0x00470300`, `0x0064325c`, `0x004706f0`, `0x004f4b10`, `0x0041b6c0`, `0x00596540`, and `0x005965c0`; the named vtable symbol is only at `0x0061373c`, and the next named vtable begins at `0x00613744`.
- 2026-05-31 IDA MCP `xrefs_to` / `search data_ref` reports the complete current reference set to `0x0061373c`: `0x0046efe0`, `0x00470306`, `0x0060c0f0`, and `0x0066d42c`.
- 2026-05-31 IDA MCP disassembly confirms the ordinary destructor, scalar deleting destructor, and static shutdown thunk all write or install the same anonymous `AutoInit` vtable pointer before calling or tail-jumping to `OleUninitialize`.
- Xrefs to the vtable land at:
  - `0x0046efe0`, the [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md);
  - `0x00470306`, the scalar deleting destructor vtable store;
  - `0x0060c0f0`, the [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md);
  - `0x0066d42c`, the static object slot.
- Adjacent data at `0x00613744` is `BrowserThread` vtable data, which bounds `AutoInit` to one visible slot in the current IDA model.

## Reconstruction Notes

- Treat this as an anonymous-namespace one-slot helper vtable generated from the source declaration `virtual ~AutoInit();`.
- The vtable does not make AutoInit Browser instance state. Exact RTTI names establish Browser translation-unit placement while startup evidence establishes process-wide OLE lifetime behavior.
- Keep the exact mangled vtable/RTTI identities in IDA; they are original compiler evidence and should not be replaced by a hand-authored source global.

## Parent Rationale

Attach this vtable evidence to [UID:00000Q][AutoInit](by-class/AutoInit.md), now emitted through [UID:0000HV][Browser](by-file/Browser.md). The class, authored ordinary destructor, and static object declaration carry the source. This page records the exact compiler artifact and is intentionally nonreconstructable/non-emitting.

## UID000277 RTTI And No-Code Closure - 2026-07-26

- `0x00613738` points to complete-object locator `0x0064314c`; the COL points to type descriptor `0x00674b84` and class hierarchy `0x00643160`. Type text `.?AVAutoInit@?A0xbc51848c@@` proves the original class name.
- The hierarchy contains one self base with PMD `0,-1,0`, attributes `0x40`, no inherited base, and no secondary vptr. The sole vtable slot at `0x0061373c` points to generated scalar deleting destructor `0x00470300`.
- Exact vtable refs are ordinary destructor `0x0046efe0`, scalar-wrapper store `0x00470306`, static shutdown `0x0060c0f0`, and static object `0x0066d42c`. Adjacent BrowserThread RTTI begins at `0x00613740`, so no second AutoInit slot exists.
- AutoInit, BrowserThread, BrowserControlPaneOld, Browser, and `Singleton<BrowserThread>` carry the same `?A0xbc51848c@` discriminator. That resolves the old standalone AutoInit/PlatformApi placement caveat in favor of Browser's translation unit.
- No source UDT currently exists in IDA, but the class page's CPP-only `AutoInit` declaration provides the source shape. This page must remain blank CPP/H so generated vtable bytes and scalar wrapper are not duplicated.
- Negative evidence: no second slot, extra base, data member, alternate vtable pointer occurrence, or external header consumer was found. Ignore stale Wave2/Wave3 metadata rather than using its `vtable_count` as current evidence.
- Score `94/97` reflects complete generated-artifact coverage and high-confidence no-emitter routing; it stays below perfect because original build metadata/file names are stripped.

## Cross-References

- Class: [UID:00000Q][AutoInit](by-class/AutoInit.md)
- File: [UID:0000HN][AutoInit](by-file/AutoInit.md), [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Memory: [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md), [UID:0000ZG][0x00470300-0x0047032a.AutoInit](by-memory/0x00470300-0x0047032a.AutoInit.md), [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md), [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md)

## Changes

- 2026-05-31: Reclassified the page from unevaluated metadata to a reconstructable source-declared/generated-binary vtable type page and raised scores from `0/0` to `84/90`.
  - Before: the page had strong content but validator metadata still said `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - After: the page records `RECONSTRUCTABLE:TRUE`, direct IDA evidence for the one-slot layout, complete current xref set, adjacent table boundary, and source-level rebuild handling.
  - Evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `search data_ref`, `disasm`, and `py_eval` byte review on 2026-05-31 confirm `0x0061373c -> 0x00470300`, references from `0x0046efe0`, `0x00470306`, `0x0060c0f0`, and `0x0066d42c`, and the adjacent `BrowserThread` RTTI/vtable boundary at `0x00613740/0x00613744`.
- 2026-06-07 parent attachment update:
  - Before: the page was reconstructable and IDA-verified, but unassigned in autogen type coverage.
  - After: completion is now `86` and `AUTOGEN_PARENT_UID:00000Q`; confidence stays `90`, and C++ remains blank.
  - Evidence: [UID:00000Q][AutoInit](by-class/AutoInit.md) and [UID:0000HN][AutoInit](by-file/AutoInit.md) already document the same vtable/static-slot relationship, OLE initializer/shutdown chain, scalar deleting destructor slot, and final standalone-vs-PlatformApi placement caveat.
- 2026-07-26 B004 UID000277 callback:
  - Before: `86/90`, reconstructable/emitting through UID00000Q but blank C++, with stale source-placement and Wave3 caveats.
  - After: `94/97`, owner UID00000Q, nonreconstructable/non-emitting, blank CPP/H, and exact Browser-TU RTTI/no-code proof.
  - Historical correction: the prior empty-emitter route is superseded; the virtual destructor declaration generates this table, so emitting a raw vtable would be duplicate ABI source.
