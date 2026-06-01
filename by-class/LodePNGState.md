*** UID:00007E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LodePNGState

## Status

- Confidence: strong for library identity; medium for complete field layout.
- Proposed owner: [UID:0000KW][LodePNG](by-file/LodePNG.md)
- Current Wave3 file: `source-3/simroot_v2/class_LodePNGState.cpp`
- Address docs: [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md), [UID:0000XI][0x00448520-0x00448557.LodePNGStateDestructors](by-memory/0x00448520-0x00448557.LodePNGStateDestructors.md), and [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md)
- Evidence basis: generated active/disabled Wave3 files, Wave3 metadata, read-only IDA MCP checks on 2026-05-24 and 2026-05-25, and local comparison against the obtained LodePNG `20160501` source archive. `wave3.py` was not executed for this pass.

## Class Role

`LodePNGState` is the codec state/settings object for the bundled LodePNG library. It is not a NexusTK gameplay, UI, archive, or render-surface class.

The currently observed use is encoder-side: `0x00443c80` constructs a stack state, initializes defaults through `0x004460f0`, overrides raw/PNG output color type and bit depth, calls the encoder at `0x004466b0`, and then frees state-owned blocks. This matches upstream LodePNG `lodepng_encode_memory` in the obtained `20160501` source.

## Layout Notes

| Offset | Evidence | Meaning |
| --- | --- | --- |
| `0x00` | Wave3 field and IDA decompile store `LodePNGState::vftable` | vtable pointer. |
| dword index `25` / `26` | `0x004460f0` initializes to color type `6` and bit depth `8`; `0x00443c80` overwrites from the caller's color type and bit-depth arguments | Raw color mode setting in the initialized state. |
| stack fields adjacent to the copied PNG info record | `0x00443c80` writes the same caller color type and bit depth into a second color-mode record before `0x004466b0` | PNG output color mode setting, matching upstream `state.info_png.color`. |

IDA does not currently expose a complete local struct named `LodePNGState`; the field offsets above are from decompiled stack-state writes.

## Methods

| Method | Range | Notes |
| --- | --- | --- |
| `~LodePNGState` | `0x00448520-0x00448527` | Trivial destructor that restores the `LodePNGState` vtable pointer. Wave3 keeps this in the disabled companion file. |
| `LodePNGState::ScalarDeletingDestructor` | `0x00448530-0x00448557` | Restores the vtable pointer and optionally calls operator delete when the low deletion flag bit is set. |

## Evidence

- IDA strings include `.?AULodePNGState@@` and `.?AVState@lodepng@@`, matching the third-party LodePNG state naming.
- IDA decompilation of `0x00443c80` writes `LodePNGState::vftable` into the stack object before initialization.
- IDA decompilation of `0x004460f0` initializes many state/settings dwords, including RGBA8 defaults.
- The obtained LodePNG `20160501` header defines `LodePNGState` with a virtual destructor when `LODEPNG_COMPILE_CPP` is enabled, which explains the vtable write and the trivial destructor entries in the binary.
- Wave3 active output emits only the scalar deleting destructor. The disabled companion emits the ordinary destructor.

## Ownership Decision

Keep `LodePNGState` inside the bundled [UID:0000KW][LodePNG](by-file/LodePNG.md) source candidate. Do not migrate it into `ImageWriters.cpp`, `ScreenshotCapture.cpp`, or DAT/resource code just because the current public caller writes screenshot PNGs.

## Cross-References

- [UID:0000KW][LodePNG](by-file/LodePNG.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md)
- [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md)
- [UID:0000XI][0x00448520-0x00448557.LodePNGStateDestructors](by-memory/0x00448520-0x00448557.LodePNGStateDestructors.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/80`. Summary: the embedded third-party LodePNG state object is well tied to upstream `20160501` source, encoder frontend behavior, init/destructor ranges, and ownership, but the complete field layout is still only partially recovered. Evidence: IDA strings/vtable writes, stack-state initialization writes, obtained upstream header/source comparison, and linked LodePNG memory pages.
