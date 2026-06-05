*** UID:0001XT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IntAlphaSurface Vtable

## Status

- Confidence: strong for slot values, medium for final owning class name.
- Concrete vtable address: `0x006112ec` (`off_6112EC`)
- Likely owner header: `render/AlphaMaskSurface.h` or `render/IntAlphaSurface.h`
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
- 2026-05-31 IDA MCP `xrefs_to` rechecked the vtable and method targets: the vtable is written from raw/default-constructor bytes at `0x0046212c`, active constructor/helper/destructor stores at `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`; the method bodies have only vtable data references, consistent with virtual dispatch.
- 2026-05-31 IDA MCP `lookup_funcs` and `decompile` confirm `0x00463270-0x004632b1` is the scalar deleting destructor, `0x00462260-0x00462282` is the release slot body, and neighboring `0x004632c0` is a separate function reached through vtable `0x00612574`.

## Naming Notes

The current placeholder class name `IntAlphaSurface` is useful for the destructor/vtable anchor, but the same vtable is written by `AlphaMaskSurface` constructor/helper code. Treat this as an alpha-surface family vtable until constructor recovery resolves whether the original source had a separate `IntAlphaSurface` class or a shared/base surface type.

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
