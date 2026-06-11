*** UID:0001XT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00006K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IntAlphaSurface Vtable

## Status

- Confidence: strong for slot values, vtable xrefs, function boundaries, and RTTI-backed direct class ownership; medium for final physical source-file colocation.
- Concrete vtable address: `0x006112ec` (`off_6112EC`)
- Likely owner header: `render/IntAlphaSurface.h`, with physical source colocation beside `AlphaMaskSurface` still possible.
- Related layout: [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)

## Slot Map

| Offset | Target | Current interpretation |
| --- | --- | --- |
| `+0x00` | `0x00463270` | `IntAlphaSurface::ScalarDeletingDestructor` provisional; frees owned pixels and optionally deletes object storage. |
| `+0x04` | `0x00462260` | `ReleaseOwnedPixels` provisional; frees owned pixels without deleting object storage. |
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

## Naming Notes

`IntAlphaSurface` is now the direct class/type owner for this vtable because the RTTI locator, type descriptor, class hierarchy descriptor, and live virtual slots all name or route through the `IntAlphaSurface` class. The same vtable is still written by `AlphaMaskSurface` constructor/helper code, so physical source-file colocation remains open, but those stores are construction/use sites rather than stronger ownership evidence than the vtable's own RTTI.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md). This page clears the child score gate at `85/88`, the class parent clears `85/89`, and the vtable's own RTTI is stronger direct ownership evidence than constructor/view stores in the neighboring `AlphaMaskSurface` region. [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md) and [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) remain plausible physical source-file colocation candidates, but they are not the direct type owner for this RTTI-backed vtable artifact.

B001/supervisor decision: attach this vtable page to [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md). Keep the file-level caveat that the original source may have colocated the declaration with `AlphaMaskSurface`, but do not leave the type page unassigned when the RTTI names `IntAlphaSurface`.

## Cross-References

- [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)

## Changes

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
