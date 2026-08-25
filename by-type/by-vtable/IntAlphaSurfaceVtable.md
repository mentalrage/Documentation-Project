*** UID:0001XT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# IntAlphaSurface Vtable

## Accepted Current Compiler Disposition

- The exact RTTI-backed class identity is [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md), physically implemented in [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).
- Slots `+0x00` and `+0x04` resolve to the scalar-deleting destructor entry and `ReleaseOwnedPixels`; the following two dwords are null. The concrete class shell declares the virtual destructor and release helper in that exact order.
- This vtable is compiler-generated from those declarations. It therefore remains fully documented but is `RECONSTRUCTABLE:FALSE`, has no emitter, and keeps both formal source channels blank; manual vtable arrays, address literals, or scalar-delete wrappers are forbidden.
- The prior proposed `render/IntAlphaSurface.h` physical split is historical. The accepted one-file route is `AlphaMaskSurface.cpp/.h`, with `IntAlphaSurface` as the concrete source class.

## Status

- Confidence: very strong for slot values, vtable xrefs, function boundaries, RTTI-backed direct class ownership, compiler-generated disposition, and accepted physical source route.
- Concrete vtable address: `0x006112ec` (`off_6112EC`)
- Accepted owner header: `render/AlphaMaskSurface.h`, where the concrete `IntAlphaSurface` declaration generates this vtable; there is no separate current `IntAlphaSurface.h` route.
- Related layout: [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)

## Slot Map

| Offset | Target | Current interpretation |
| --- | --- | --- |
| `+0x00` | `0x00463270` | [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md); source body frees owned pixels, while object deletion is compiler scalar-delete wrapper behavior. |
| `+0x04` | `0x00462260` | [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md); frees owned pixels without deleting object storage. |
| `+0x08` | `0x00000000` | No recovered slot. |
| `+0x0c` | `0x00000000` | No recovered slot. |

## Evidence

- 2026-05-26 IDA MCP `py_eval` reads vtable dwords as `0x00463270`, `0x00462260`, `0x00000000`, and `0x00000000`.
- 2026-05-26 IDA MCP `xrefs_to 0x006112ec` reports data references from raw `0x0046212c`, `0x0046217b`, [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) store `0x00462237`, `0x00462415`, and `0x0046327a`, tying this vtable to the alpha-surface constructor/helper/destructor region.
- IDA MCP decompilation of `0x00462260` and `0x00463270` shows both helpers test the ownership flag at object offset `0x24` and free pixel storage at offset `0x14`.
- 2026-05-31 IDA MCP `py_eval` rechecked `0x006112e8-0x00611300`: `0x006112e8` is the `??_R4IntAlphaSurface@@6B@` locator, `0x006112ec -> 0x00463270`, `0x006112f0 -> 0x00462260`, `0x006112f4/0x006112f8` are zero, and following dwords transition into unrelated data rather than more confirmed virtual slots.
- 2026-06-08 B001 ownership follow-up rechecked the RTTI chain `0x006112e8 -> 0x00641e9c -> 0x006744ec`: the complete object locator is `??_R4IntAlphaSurface@@6B@`, the type descriptor is `??_R0?AVIntAlphaSurface@@@8`, and the class hierarchy descriptor is `??_R3IntAlphaSurface@@8`. This names `IntAlphaSurface` directly on the vtable metadata.
- 2026-05-31 IDA MCP `xrefs_to` rechecked the vtable and method targets: the vtable is written from raw/default-constructor bytes at `0x0046212c`, active constructor/helper/destructor stores at `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`; the method bodies have only vtable data references, consistent with virtual dispatch.
- 2026-05-31 IDA MCP `lookup_funcs` and `decompile` confirm `0x00463270-0x004632b1` is the scalar deleting destructor, `0x00462260-0x00462282` is the release slot body, and neighboring `0x004632c0` is a separate function reached through vtable `0x00612574`.
- 2026-06-08 Batch124 live IDA MCP recheck against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) reconfirmed the slot bytes and references: `0x006112ec -> 0x00463270`, `0x006112f0 -> 0x00462260`, and `0x006112f4/0x006112f8` remain zero. `xrefs_to 0x006112ec` still reports the raw no-function store at `0x0046212c`, active constructor/helper store `0x0046217b`, `sub_4623C0` stores at `0x00462237` and `0x00462415`, and destructor reset `0x0046327a`.
- The same 2026-06-08 recheck confirms `0x00462120` is still not an IDA function, while `0x00462170`, `0x00462260`, `0x004623c0`, `0x00463270`, and the excluded `0x004632c0` remain stable modeled functions with sizes `0xb7`, `0x22`, `0x154`, `0x41`, and `0x4b`. The virtual targets `0x00463270` and `0x00462260` still have only vtable-data references, not direct callers.
- 2026-06-28 B009 evidence at `0x00462415` records placement initialization of a caller-supplied `IntAlphaSurface` destination. Its then-current AlphaMaskSurface-helper ownership interpretation is superseded by the accepted [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) `IntAlphaSurface::InitSurfaceView` member route; the store remains valid construction/use-site evidence for this RTTI-backed vtable.
- 2026-07-03 B006 current MCP session `b010_00032w_20260703` reconfirmed the first vtable bytes at `0x006112e8` as locator pointer `9c 1e 64 00`, slot 0 pointer `70 32 46 00`, slot 1 pointer `60 22 46 00`, and two zero slots. `find_bytes` command id `24` found the destructor pointer only at `0x006112ec`, the release-helper pointer only at `0x006112f0`, and the separate `0x004632c0` pointer only at `0x00612574`. UID0000YP and UID0004FR are now source-ready class methods; [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) is alias/support.

## Naming Notes

`IntAlphaSurface` is the direct class/type owner because the RTTI locator, type descriptor, class hierarchy descriptor, and live virtual slots all name or route through that class. Constructor/view stores are construction/use sites. Physical source placement is resolved to `AlphaMaskSurface.cpp/.h` through [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), not a competing class identity or separate-file route.

## Assignment Gate

`CANONICAL_OWNER` is [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md), and this page is `95/95`. As compiler-generated evidence it is `RECONSTRUCTABLE:FALSE`, has no emitter, and keeps formal CPP/H blank. The vtable's RTTI proves direct type ownership; [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) is the accepted physical compilation unit rather than another type owner.

B001/supervisor decision: attach this vtable page to [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md), preserve it as non-emitting compiler evidence, and route the declaration that regenerates it through UID0000HF `AlphaMaskSurface.h`.

## Cross-References

- [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)

## Changes

- 2026-08-17 B005 UID0000HF Gate 2A reconciliation:
  - Replaced active `85/88`, `IntAlphaSurface.h`, and unresolved-colocation statements with the accepted `95/95`, owner UID00006K, compiler-generated/no-emitter/blank-source disposition, and physical UID0000HF route.
  - Retained all exact RTTI, slot, vptr-store, function-boundary, and pointer-uniqueness evidence; historical source-placement interpretations remain dated below.

- 2026-07-03 B006 Gate 1 implementation:
  - Score and owner/emitter metadata unchanged.
  - Summary/evidence: refreshed slot wording so slot `+0x00` points to source-ready destructor [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md) and slot `+0x04` points to source-ready release helper [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md). Current MCP session `b010_00032w_20260703` reconfirmed exact slot bytes, pointer-pattern uniqueness, vtable-store refs, and `0x004632c0` exclusion.
- 2026-06-28 B009 [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) construction/use-site clarification:
  - Score and owner/emitter metadata unchanged.
  - Summary/evidence: added that the `0x00462415` vtable store comes from an AlphaMaskSurface-owned helper with an explicit `IntAlphaSurface *` destination parameter, not from a direct `IntAlphaSurface` method body. RTTI still makes this vtable artifact class-owned by [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md).

### 2026-05-31 - Scored IDA-verified alpha-surface vtable

- Before: validator metadata still marked this page `COMPLETION:0`, `CONFIDENCE:0`, and left `RECONSTRUCTABLE` blank even though the page had IDA-backed slot and xref evidence.
- Changed to: `COMPLETION:82`, `CONFIDENCE:87`, and `RECONSTRUCTABLE:TRUE`. No parent attachment or C++ reconstruction code was added because the final source-level class split between `IntAlphaSurface` and `AlphaMaskSurface` remains open.
- Evidence: IDA MCP `py_eval`, `xrefs_to`, `lookup_funcs`, `list_globals`, and `decompile` checks on 2026-05-31 confirmed the locator/vtable dwords, vtable-store xrefs, destructor/release behavior, method bounds, and neighboring non-alpha-surface boundary.

### 2026-06-04 - Wording refresh from live IDA recheck

- Score unchanged at `82/87`.
- Updated naming wording from importer-derived name evidence to a placeholder-name caveat.
- Evidence: live IDA MCP reconfirmed the first four vtable dwords at `0x006112ec`, vtable stores from `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`, and vtable-only xrefs to `0x00463270` and `0x00462260`. The source-level class split remains unresolved, so no score change was made.

### 2026-06-08 - Batch124 strict ownership review

- Before: `82/87`, reconstructable, and unassigned because the owning class/source split was open.
- Changed to: `85/88`; parent metadata remained blank at that checkpoint.
- Evidence: live IDA MCP reconfirmed the exact four-slot vtable data, vtable-only virtual targets, stable function boundaries, raw `0x00462120` no-function status, active constructor/helper/view stores, destructor reset, and the neighboring `0x004632c0` exclusion. Completion reached the child gate, but no assignment was made at that point because the later B001 RTTI ownership pass had not yet been applied.

### 2026-06-08 - B001 RTTI ownership application

- Before: `85/88`, reconstructable, and unassigned after Batch124 because constructor/view stores in the `AlphaMaskSurface` neighborhood were treated as unresolved direct ownership.
- Changed to: `AUTOGEN_PARENT_UID:00006K` for [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md). Scores remain `85/88`.
- Evidence: B001 follow-up confirmed the RTTI chain `0x006112e8 -> 0x00641e9c -> 0x006744ec`, where the complete object locator is `??_R4IntAlphaSurface@@6B@` and the type descriptor is `??_R0?AVIntAlphaSurface@@@8`. The slot targets remain the documented `IntAlphaSurface` destructor/release pair, so constructor/view stores are construction-site evidence rather than stronger declaration ownership.
