*** UID:0000FE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ML | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ML | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class UniAPIInit
{
public:
    UniAPIInit();
    virtual ~UniAPIInit();
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UniAPIInit

## Summary

`UniAPIInit` initializes the client-wide Win32 API dispatch table for Unicode-aware operation. It detects whether the process is running on the NT platform family and installs wide-character API pointers when possible, otherwise keeping ANSI fallback behavior.

Current evidence anchors the exact source constructor at [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md) and the exact empty out-of-line destructor at [UID:0004N7][0x005997e0-0x005997e7.UniAPIInitDestructor](by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md). The constructor has no linked route but is member-shaped and independently realized inline by the sole live startup wrapper [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), reached from startup table `0x0060d71c`. The source shape is a private PlatformApi helper class plus file-local `static UniAPIInit s_uniAPIInit`; mixed parent [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) and all startup/deleting/cleanup/compiler data remain non-emitting.

## Likely Original Placement

- Source: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Proposed path: `platform/PlatformApi.cpp`
- Confidence: very strong for platform ownership, class name, layout, virtual contract, exact constructor/destructor definitions, static-object source shape, and memory anchors; strong for public access and exact static variable spelling, which remain bounded inference.

## Source Shape Decision

The accepted source model is:

```cpp
static UniAPIInit s_uniAPIInit;
```

The exact `s_` prefix is descriptive, not symbol-proven, but the file-local static `UniAPIInit` object shape is now high probability and no longer an open ownership blocker. The vtable symbol `??_7UniAPIInit@@6B@`, the one-slot vtable child [UID:0003E5][0x0062e578-0x0062e580.UniAPIInitVtableData](by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md), the static object/vptr slot [UID:00028B][0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot](by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md), the static cleanup wrapper [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md), and the scalar deleting destructor value at `0x00599a10` all support a vptr-only static initializer object.

The class page emits only the declaration:

- `UniAPIInit::UniAPIInit()` is emitted by UID0004N6 with one unconditional reader assignment and the complete NT-only dispatch sequence. Its no-route retained body is corroborated by the live inlined startup copy.
- `virtual ~UniAPIInit()` is emitted by UID0004N7 as one empty out-of-line definition. C++11 `= default` is rejected for source-era fidelity; the retained seven-byte ordinary body is stronger than an inline-only form.
- Do not hand-write the vtable dword, vptr reset helper, scalar deleting destructor, or `atexit` cleanup wrapper as source code. Those are compiler/static-lifetime artifacts regenerated from the class/static object declaration.

## RTTI And Layout Contract

- Primary COL `0x00651a2c` is `??_R4UniAPIInit@@6B@` with exact fields `(0, 0, 0, 0x00679a10, 0x00651a40)`.
- Type descriptor `0x00679a10` contains `.?AVUniAPIInit@@`; the class name is symbol-proven.
- CHD `0x00651a40` has one base and points through base array `0x00651a50` to sole BCD `0x00651a58`. Its PMD is `(0,-1,0)`, with no inheritance, no secondary view, and no adjustor table.
- [UID:0003E5][0x0062e578-0x0062e580.UniAPIInitVtableData](by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md) is the complete COL-pointer-plus-one-slot-vtable unit. The sole slot is compiler scalar deleting destructor UID0004N9, proving the virtual destructor is the only virtual member.
- The scalar wrapper frees size four, static storage is one dword, and no field/base access exists. The class is vptr-only, four bytes, with no source data members.
- Public constructor/destructor access is highest probability because the file-scope object must construct/destruct and the established declaration uses public access; RTTI does not encode access, so this spelling remains explicitly inferred.

## Dispatch Initialization Evidence

Current raw PE validation and existing IDA-backed docs agree on the following source-relevant facts:

- `0x0041a280` is the authoritative live startup dynamic initializer / inlined constructor realization. It allocates `OSVERSIONINFOA` with only `dwOSVersionInfoSize = 0x94` seeded, ignores the `GetVersionExA` return, compares `dwPlatformId` against `2`, unconditionally writes `ReadUtf16CodeUnitFromFile` at `0x0069be1c`, installs NT `*W` dispatch entries, and registers [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) through `_atexit`.
- `0x0041a280` has no ordinary rel32 call/jump route but has the startup-table data reference at `0x0060d71c`, which is the expected route for dynamic initialization.
- `0x005995b0-0x005997dd` is exact constructor UID0004N6: it has `this`, vptr setup, exact assignments, return-this shape, and no route. The stale generated `~UniAPIInit` label is rejected.
- `0x005997e0-0x005997e7` is exact ordinary destructor UID0004N7: `mov dword ptr [ecx], 0x0062e57c; ret`, generated from one empty out-of-line source definition.
- `0x00599a10-0x00599a34` is scalar deleting destructor glue: it tests the delete flag, writes the vtable pointer, conditionally frees a 4-byte object, and returns `4`. Its vtable reference comes from `0x0062e57c`.
- `0x0060c440-0x0060c44b` is static cleanup glue: it writes `0x0062e57c` back to `0x006702c4` and returns. It is registered by the real initializer, not called as handwritten source.
- `0x006702c4-0x006702c8` is static object storage for the file-local `UniAPIInit` object vptr; it should not be modeled as a standalone raw pointer global in source C++.
- B014's exact split evidence is preserved, but its then-deferred source placement is now resolved: constructor/destructor source emits from UID0004N6/UID0004N7; duplicate UID0004N8, scalar UID0004N9, live wrapper UID0000WD, cleanup UID0001O9, target UID0003E5, and mixed parent UID0001KE remain blank/non-emitting.

The NT dispatch assignment sequence observed in [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) and rechecked from raw PE is:

| Slot | Installed target/source |
| --- | --- |
| `0x0069be1c` | `ReadUtf16CodeUnitFromFile` at `0x00599570`, unconditional after `GetVersionExA` |
| `0x0069be20` | `FindWindowW` |
| `0x0069be24` | `OpenFileMappingW` |
| `0x0069be28` | `CreateMutexW` |
| `0x0069be2c` | `CreateDialogParamW` |
| `0x0069be30` | `LoadLibraryW` |
| `0x0069be34` | `CreateFileW` |
| `0x0069be38` | `CreateProcessW` |
| `0x0069be3c` | `CreateEventW` |
| `0x0069be40` | `RegisterClassW` |
| `0x0069be44` | `CreateWindowExW` |
| `0x0069be48` | `CreateFileMappingW` |
| `0x0069be4c` | `CreateSemaphoreW` |
| `0x0069be50` | `DefWindowProcW` |
| `0x0069be54` | `RegisterClipboardFormatW` |
| `0x0069be58` | `CharUpperBuffW` |
| `0x0069be5c` | `CreateDirectoryW` |
| `0x0069be60` | `DeleteFileW` |
| `0x0069be64` | `DispatchMessageW` |
| `0x0069be68` | `FindFirstFileW` |
| `0x0069be6c` | `FormatMessageW` |
| `0x0069be70` | `GetCurrentDirectoryW` |
| `0x0069be74` | `GetModuleFileNameW` |
| `0x0069be78` | `GetModuleHandleW` |
| `0x0069be7c` | `GetWindowsDirectoryW` |
| `0x0069be80` | `GlobalGetAtomNameW` |
| `0x0069be84` | `LoadCursorW` |
| `0x0069be88` | `LoadIconW` |
| `0x0069be8c` | `PeekMessageW` |
| `0x0069be90` | `PostMessageW` |
| `0x0069be94` | `RegCreateKeyExW` |
| `0x0069be98` | `RegDeleteKeyW` |
| `0x0069be9c` | `RegEnumValueW` |
| `0x0069bea0` | `RegQueryInfoKeyW` |
| `0x0069bea4` | `RegQueryValueExW` |
| `0x0069bea8` | `RegSetValueExW` |
| `0x0069beac` | `SetCurrentDirectoryW` |
| `0x0069be14` | `_wfopen` wrapper/address `0x005d253a` |
| `0x0069be18` | `_wstat64i32` wrapper/address `0x005e25aa` |
| `0x0069beb0` | `GetFileVersionInfoSizeW` wrapper/address `0x005c5c8d` |
| `0x0069beb4` | `GetFileVersionInfoW` wrapper/address `0x005c5c93` |
| `0x0069beb8` | `VerQueryValueW` wrapper/address `0x005c5c99` |
| `0x0069bebc` | `ImmGetCompositionStringW` wrapper/address `0x005c5cc9` |
| `0x0069bec0` | `ImmGetCandidateListW` wrapper/address `0x005c5ce7` |
| `0x0069bec4` | `SendMessageW` |
| `0x0069bec8` | `GetLocaleInfoW` |
| `0x0069becc` | `SetFileAttributesW` |

## Rejected Alternatives

- Generated `~UniAPIInit` at `0x005995b0`: rejected. The body is constructor-shaped and has no current route; final source should not hand-port this stale projection.
- Raw vptr global at `0x006702c4`: rejected. Source should declare a static `UniAPIInit` object, not a `void *`, `DWORD`, or vtable pointer initialized by hand.
- Consumer ownership by `StdioFile`, `PathUtil`, `Browser`, `InputMan`, socket, or `Application`: rejected. Those modules consume specific dispatch entries or provide startup routing; they do not own the PlatformApi dispatch table or static initializer object.
- Forced runtime `struct WideApiDispatchTable g_table`: plausible as a documentation abstraction but weaker as final C++ because code uses direct absolute slot references, not `base + index * 4`, a table pointer, or a struct object at runtime. The stronger current style is grouped file-scope function-pointer globals documented under [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md).
- Handwritten `atexit` registration/source cleanup wrapper: rejected. The `atexit` call and `0x0060c440` wrapper are compiler/static-lifetime output from the file-local static object model.

## Methods

- [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md) - exact source constructor with complete dispatch behavior.
- [UID:0004N7][0x005997e0-0x005997e7.UniAPIInitDestructor](by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md) - exact empty out-of-line virtual destructor definition.
- `0x0041a280-0x0041a4a8` / UID0000WD - non-emitting live startup wrapper/inlined constructor plus `_atexit` registration.
- `0x0060c440-0x0060c44b` static cleanup wrapper - writes the `UniAPIInit` vtable pointer to `0x006702c4`; compiler/static-lifetime artifact registered by the real startup initializer, not a normal source method.
- [UID:0004N8][0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection](by-memory/0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection.md) - non-emitting retained duplicate projection.
- [UID:0004N9][0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor](by-memory/0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor.md) - compiler scalar deleting wrapper; resets vptr and conditionally frees the four-byte object.

## Globals

This class owns or initializes many `g_pfn*` function pointers, including file, window, registry, dialog, message, locale, event, and IME APIs. Examples include `g_pfnCreateWindowEx`, `g_pfnDispatchMessage`, `g_pfnPeekMessage`, `g_pfnRegQueryValueEx`, `g_pfnSetWindowText`, `g_pfnCreateEventW`, `g_pfnSendMessageW`, and `g_pfnImmGetCompositionString`.

The concrete global-data cluster is documented as [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md). File consumers should treat `dword_69BE14` and `dword_69BE18` as entries in that table, not as `StdioFile` or `PathUtil` globals. The stale browser/transport name on [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) is also a consumer-biased alias; the documented slot is the `SendMessageW` dispatch entry.

## Evidence

- Generated source uses `GetVersionExA` and compares `dwPlatformId` to `VER_PLATFORM_WIN32_NT`.
- IDA MCP confirms [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) is a real initializer that performs the table writes.
- IDA MCP confirms the scalar deleting destructor at `0x00599a10-0x00599a34`.
- IDA MCP reports no function containing `0x005995b0`; the previous function is [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), specifically the `0x00599570-0x005995a7` UTF-16 stream-reader helper, and the next function is `0x005997e0-0x005997e7`.
- 2026-05-26 IDA MCP recheck reconfirmed those boundaries and showed `0x0041a280` is referenced from startup initializer table data at `0x0060d71c`, while `0x005995b0` has no callers or xrefs.
- 2026-05-26 IDA MCP confirms `0x0060c440` has size `0x0b`, is registered by the `0x0041a280` initializer, and only writes `UniAPIInit::vftable` to `0x006702c4`.
- Existing IDA-backed sibling pages now agree on the parent/source chain: [UID:0000ML][PlatformApi](by-file/PlatformApi.md) owns the source module, [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) owns the concrete pointer storage, [UID:00028B][0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot](by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md) owns the static object vptr slot, and [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) preserves the raw/generated-boundary caveat.
- 2026-06-11 A002 live IDA MCP recheck confirms exact child [UID:0003E5][0x0062e578-0x0062e580.UniAPIInitVtableData](by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md): `0x0062e57c` is `??_7UniAPIInit@@6B@`, points to `0x00599a10`, has xrefs from `0x005995d7`, `0x005997e0`, `0x00599a1a`, `0x0060c440`, and static slot `0x006702c4`, and ends before the `UrlAlertPane` locator at `0x0062e580`.
- Historical `simroot_v2/class_UniAPIInit.cpp` emitted the initializer body under `~UniAPIInit` at `0x005995b0`; exact children supersede that stale layout and preserve it only as provenance.

## Open Questions

- Exact original static object spelling remains unresolved (`s_uniAPIInit`, `g_uniAPIInit`, or an unprefixed file-static name). This is a naming-polish issue, not an ownership or source-placement blocker.
- Dispatch factoring is resolved to the highest-probability direct member form `UniAPIInit::UniAPIInit()`: the retained exact body has `this`, vptr setup, return-this shape, and a live inlined counterpart. A separate helper is no longer needed.
- Exhaustive typedef names for every dispatch pointer remain descriptive. The source declaration style is now grouped PlatformApi file-scope function-pointer globals under [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md), not raw `dword_` names or consumer-local globals.
- The mixed UID0001KE span is fully split into exact children UID0004N6 through UID0004N9; no future child audit remains. Only original PDB formatting/static spelling remains unavailable and nonblocking.

## Cross-References

- File: [UID:0000ML][PlatformApi](by-file/PlatformApi.md)
- Globals: [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- Related classes: [UID:00000Q][AutoInit](by-class/AutoInit.md), [UID:00006J][InputMan](by-class/InputMan.md), [UID:00000D][Application](by-class/Application.md)
- Memory: [UID:0004N6][0x005995b0-0x005997dd.UniAPIInitConstructor](by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md), [UID:0004N7][0x005997e0-0x005997e7.UniAPIInitDestructor](by-memory/0x005997e0-0x005997e7.UniAPIInitDestructor.md), [UID:0004N8][0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection](by-memory/0x005997f0-0x00599a0b.RetainedWideApiDispatchInitProjection.md), [UID:0004N9][0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor](by-memory/0x00599a10-0x00599a34.UniAPIInitScalarDeletingDestructor.md), [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md), [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md), [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md)

## Changes

- 2026-07-14 B004 UID0003E5 callback: raised `90/88` to `93/95`; preserved owner/emitter UID0000ML, reconstructable true, and the exact class formal block; added complete COL/type/CHD/BCD hierarchy, vptr-only four-byte layout, public-access inference, exact constructor UID0004N6 and destructor UID0004N7 source routes, duplicate/scalar/compiler-support inventory, finalized direct-member source factoring, and historicalized stale generated destructor output.

- 2026-06-07 parent/confidence reconciliation:
  - What existed before: `AUTOGEN_PARENT_UID` was blank and the page stayed at `86/78`, even though the linked PlatformApi, WideApiDispatchTable, vtable-slot, and exact memory pages already carried a consistent IDA-backed ownership chain.
  - Changed to: raised the page to `88/82`, attached it to [UID:0000ML][PlatformApi](by-file/PlatformApi.md), expanded the summary/method/global sections with the vtable-reset helper, static vptr slot, `CreateEventW`/`SendMessageW` table slots, and clarified that `0x005995b0` remains raw/generated provenance rather than a source body.
  - Summary/evidence: existing IDA-backed pages document `0x0041a280` as the authoritative startup initializer, [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md) as the concrete table, [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) as the generated-boundary caveat, [UID:00028B][0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot](by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md) as the static object slot, and [UID:0000ML][PlatformApi](by-file/PlatformApi.md) as the source root. This session could not reach IDA MCP, so no new live-disassembler claim was added. C++ remains blank below the 95/95 final-source gate.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE`; the later 2026-06-07 pass attached `AUTOGEN_PARENT_UID` to [UID:0000ML][PlatformApi](by-file/PlatformApi.md) after the class confidence reached the parent gate.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the real dispatch initializer at `0x0041a280`, static cleanup wrapper at `0x0060c440`, scalar deleting destructor at `0x00599a10`, and neighboring platform helper starts at `0x00599440`, `0x00599570`, and `0x005997e0`; `0x005995b0` still reports `Not a function`. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-28 boundary/context correction:
  - What existed before: class documentation referenced `0x005995b0-0x00599a33` and treated the previous function only as an unnamed boundary fact.
  - Changed to: class documentation references `0x005995b0-0x00599a34` and links the previous platform string/stream helper island.
  - Summary/evidence: IDA MCP reports `sub_599A10` as `0x00599a10-0x00599a34` and identifies `0x00599440-0x005995a7` as real conversion/read helper code before the Wave3-projected `UniAPIInit` body.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the wide API dispatch-table initializer, global table ownership, scalar destructor/static cleanup evidence, boundary correction, and documented conflict between the real `0x0041a280` initializer and Wave3-projected `0x005995b0` body.
- 2026-06-11 A002 Batch227 vtable child gate: Raised confidence from `82` to `85` while keeping completion `88`. Live IDA MCP reconfirmed the exact `UniAPIInit` vtable dword, scalar destructor slot, static cleanup/static-slot xrefs, and `UrlAlertPane` successor boundary; new child [UID:0003E5][0x0062e578-0x0062e580.UniAPIInitVtableData](by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md) can therefore attach directly to this class under the strict `85/85` gate. Final source/static-object spelling remains below the C++ emission threshold.
- 2026-06-21 B007 Rule 26 incorporation:
  - What changed: raised [UID:0000FE] from `88/85` to `90/88`, added declaration-level first-draft C++, accepted the file-local static object model `static UniAPIInit s_uniAPIInit` as the strongest current source shape, and moved old open questions into resolved/deferred categories.
  - Summary/evidence: B007 current raw PE/xref reanalysis validates `0x0041a280` as the startup-table dynamic initializer with data xref `0x0060d71c`, confirms no current route to `0x005995b0`, identifies `0x005997e0` as a vptr-only reset helper, `0x00599a10-0x00599a34` as scalar deleting destructor glue, `0x0060c440-0x0060c44b` as static cleanup wrapper, `0x0062e57c` as the one-slot vtable, and `0x006702c4` as static object vptr storage. The class declaration is now source-ready; raw/generated [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md) remains no-code because hand-porting it would duplicate the real initializer and preserve a stale destructor projection.
- 2026-06-19 B014 UniAPIInit source-quality sync:
  - Score unchanged at `90/88`; the current B007-incorporated declaration is stronger than the report's older `89/87` recommendation.
  - Summary/evidence: B014 confirms the high-probability `class UniAPIInit { UniAPIInit(); virtual ~UniAPIInit(); };` plus file-local `static UniAPIInit s_uniAPIInit` model, with the constructor/initializer source behavior routed through [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) and compiler-generated/static-lifetime support routed through [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md), [UID:0003E5][0x0062e578-0x0062e580.UniAPIInitVtableData](by-memory/0x0062e578-0x0062e580.UniAPIInitVtableData.md), [UID:00028B][0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot](by-memory/0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md), and the scalar deleting destructor at `0x00599a10`.
