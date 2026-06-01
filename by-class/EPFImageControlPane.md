*** UID:00004G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EPFImageControlPane

## Status

- Confidence: strong for observed behavior, medium for final member names.
- Likely source file: [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- Address range: [UID:00011J][0x004991f0-0x0049b24f.EPFImageControlPane](by-memory/0x004991f0-0x0049b24f.EPFImageControlPane.md)

## Class Purpose

`EPFImageControlPane` is a `ControlPane`-derived widget that renders one frame from a named EPF/EPD resource. It stores the resource name, frame index, flip state, and palette name, then draws through shared render callbacks.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| Constructor | `0x004991f0` | Initializes the base control, copies resource/palette names, stores frame index, and sets flip state. |
| Destructor | `0x004992b0` | Releases cached image data and chains to the pane base destructor. |
| `LoadAndRenderImage` | `0x00499310` | Prepares the pane draw surface through `dword_69B3FC`, loads one frame through `g_pEPFLib`, fetches a palette, blits to the pane surface through `dword_69B3E8`, and caches the result. |
| Scalar deleting destructor | `0x0049b1b0` | Destructor wrapper with optional `operator delete`. |

IDA MCP vtable evidence places small virtual adjustor functions at `0x0049af53-0x0049af5e` and `0x0049af5e-0x0049af69`; both forward to the scalar deleting destructor after base-pointer adjustment. The following in-band code at `0x004993b0-0x0049980d` installs `TargetOptionEditControlPane` vtables and is not part of this class.

## Dependencies

- `g_pEPFLib`: process-wide `ImageLib` singleton whose layout lookup methods are currently recovered as `ResourceLayoutTable`.
- `g_pPaletteLib`: palette lookup service.
- `g_pfnLockSurface`: generated alias for `dword_69B3FC` at `0x0069b3fc`; IDA shows `LoadAndRenderImage` passing `(this, this + 0x44)`, so the current one-argument generated signature is suspect.
- `g_pfnBlitSprite`: blits the selected EPF frame with the selected palette.

## Cross-References

- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: control role, constructor/destructor/render/destructor-wrapper methods, EPF/palette/render callback dependencies, and thunk caveat are documented; remaining uncertainty is final member names and generated callback signature cleanup.
