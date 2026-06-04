*** UID:0000J2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# EPFImageControlPane

## Status

- Confidence: strong for class behavior, vtable identity, render dependencies, and UI-control placement; medium-high for final member/callback names.
- Proposed module: `ui/controls/EPFImageControlPane.cpp`
- Main address range: `0x004991f0-0x0049b24f`
- Evidence basis: live IDA MCP/disassembly checks for constructor/destructor/render/destructor-wrapper bounds, vtables, caller fanout, resource strings, surface callbacks, and neighboring-class exclusion.

## File Role

`EPFImageControlPane` is a UI control for displaying a single EPF/EPD frame with a palette. It should live with UI controls, not with the EPF registry itself.

The likely original file contained:

- `EPFImageControlPane`
- references to `g_pEPFLib`
- references to `g_pPaletteLib`
- draw-surface/blit function pointer declarations used by the control

The class consumes the [UID:0000K2][ImageLib](by-file/ImageLib.md) / [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) singleton through `g_pEPFLib`, then uses palette and blit services to draw the decoded frame into the pane surface. The surface-prep callback is tracked as [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3FC` rather than owned by this control.

## Behavior

- Constructor chains to `ControlPane`, stores a 16-wchar EPF file name, stores the frame index, applies a flip flag, and defaults the palette name to `BARAM.PAL` when no palette is supplied.
- Destructor releases the cached image and chains to the parent pane destructor.
- `LoadAndRenderImage` prepares the pane draw surface through `dword_69B3FC`, asks `g_pEPFLib` for the selected frame, fetches a palette from `g_pPaletteLib`, blits the image when pixel data is present, and encodes the rendered result into the control's cache. Live IDA shows the prepare call shape as `dword_69B3FC(this, this + 0x44)`.

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms local class functions at `0x004991f0-0x004992a8`, `0x004992b0-0x0049930e`, `0x00499310-0x004993a5`, adjustors at `0x0049af53-0x0049af69`, and scalar deleting destructor `0x0049b1b0-0x0049b24f`.
- The constructor has 66 unique caller functions, matching a reusable UI image-control widget rather than a one-off dialog helper.
- Constructor, destructor, and scalar deleting destructor install the three `EPFImageControlPane` vtables at `0x00618248`, `0x006182b0`, and `0x006182e0`; render slot `0x0061828c` points to `0x00499310`.
- Constructor writes the frame index at `this + 0x128`, flip/control state at `this + 0xff`, the resource name at `this + 0x108`, and default palette `BARAM.PAL` at `this + 0x12a` when no palette argument is supplied.
- `LoadAndRenderImage` uses `dword_67A744` (`g_pEPFLib`), `dword_67A7E0` (palette service), callback slot `dword_69B3FC`, blit callback `dword_69B3E8`, and resource lookup helper `0x004d02f0`.
- The adjacent `0x004993b0` constructor installs `TargetOptionEditControlPane` vtables at `0x00618330`, `0x0061834c`, and later TargetOption vtable cells, so the following control code is excluded from this file's class-local method set.

## Ownership Decision

Keep this as a consumer in `ui/controls/EPFImageControlPane.cpp`. It is useful evidence for the registry API, but it should not own `ResourceLayoutTable`, `ResourceLayoutEntry`, palette classes, or generic blit helpers.

## Cross-References

- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md)
- [UID:00011J][0x004991f0-0x0049b24f.EPFImageControlPane](by-memory/0x004991f0-0x0049b24f.EPFImageControlPane.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:78`.
  - Summary/evidence: UI control role, constructor/load-render behavior, `g_pEPFLib`/palette/surface callback dependencies, and non-ownership decisions are documented; completion is lower than larger pages because detailed vtable/layout and caller coverage are still sparse.
- 2026-06-04: Raised from `78/78` to `84/84` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/controls/`.
  - Before: the page had a correct proposed module but a blank validator path, stale recovered-source wording, sparse caller/vtable evidence, and no fresh executable identity.
  - After: live IDA evidence records exact local bounds, 66-constructor-caller fanout, vtable stores/slots, default palette, render dependencies, callback shape, and adjacent `TargetOptionEditControlPane` exclusion.
  - Reasoning: `NexusTK/ui/controls/` matches the control role and the existing proposed module. Confidence remains below final-code level because member names and callback typedefs still need source-quality review.
