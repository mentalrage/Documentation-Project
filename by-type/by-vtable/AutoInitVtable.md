*** UID:0001X0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AutoInit Vtable

## Scope

- Entity kind: vtable
- Vtable address: `0x0061373c`
- RTTI pointer: `0x00613738 -> 0x0064314c`
- Current IDA name: `??_7AutoInit@?A0xbc51848c@@6B@`
- Likely owner: [UID:00000Q][AutoInit](by-class/AutoInit.md)
- Likely source module: [UID:0000HN][AutoInit](by-file/AutoInit.md) / [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Current Wave3 issue: `class_AutoInit.meta_wave3` reports `vtable_count: 0`
- Rebuild handling: `source-declared/generated-binary`; represent this through the `AutoInit` class declaration/static object, not by hand-porting the `.rdata` bytes.
- Confidence: confirmed

## Layout

| Address | Slot | Target | Notes |
| --- | --- | --- | --- |
| `0x00613738` | RTTI | `0x0064314c` | IDA names this `AutoInit` RTTI data. |
| `0x0061373c` | `0` | `0x00470300` | [UID:0000ZG][0x00470300-0x00470329.AutoInit](by-memory/0x00470300-0x00470329.AutoInit.md). |
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

- Treat this as an anonymous-namespace one-slot helper vtable. The class is likely a tiny RAII OLE initializer with only virtual destruction visible in the binary.
- The vtable does not prove browser-instance ownership by itself. It is physically adjacent to browser/OLE vtables, but startup evidence still shows the process-wide OLE initialization path.
- Regenerated Wave3 metadata should eventually record this vtable instead of leaving `AutoInit` with `vtable_count: 0`.

## Cross-References

- Class: [UID:00000Q][AutoInit](by-class/AutoInit.md)
- File: [UID:0000HN][AutoInit](by-file/AutoInit.md), [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Memory: [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md), [UID:0000ZG][0x00470300-0x00470329.AutoInit](by-memory/0x00470300-0x00470329.AutoInit.md), [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md), [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md)

## Changes

- 2026-05-31: Reclassified the page from unevaluated metadata to a reconstructable source-declared/generated-binary vtable type page and raised scores from `0/0` to `84/90`.
  - Before: the page had strong content but validator metadata still said `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - After: the page records `RECONSTRUCTABLE:TRUE`, direct IDA evidence for the one-slot layout, complete current xref set, adjacent table boundary, and source-level rebuild handling.
  - Evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `search data_ref`, `disasm`, and `py_eval` byte review on 2026-05-31 confirm `0x0061373c -> 0x00470300`, references from `0x0046efe0`, `0x00470306`, `0x0060c0f0`, and `0x0066d42c`, and the adjacent `BrowserThread` RTTI/vtable boundary at `0x00613740/0x00613744`.
