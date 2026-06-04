*** UID:00004G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EPFImageControlPane

## Status

- Confidence: strong for observed behavior, vtable identity, caller fanout, render dependencies, and neighboring-range exclusion; medium-high for final member and callback names.
- Likely source file: [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- Address range: [UID:00011J][0x004991f0-0x0049b24f.EPFImageControlPane](by-memory/0x004991f0-0x0049b24f.EPFImageControlPane.md)
- Parent attachment: [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md) now has a valid `NexusTK/ui/controls/` path and live IDA-backed module evidence.

## Score Rationale

- Completion `84`: raised from `72` after the 2026-06-04 live IDA pass confirmed exact bounds, constructor caller fanout, three vtables, render slot, default palette, callback-table dependencies, and TargetOption exclusion.
- Confidence `86`: strong for class identity and behavior. It stays below final-code confidence because field names, callback typedefs, and final helper names remain provisional.

## Class Purpose

`EPFImageControlPane` is a `ControlPane`-derived widget that renders one frame from a named EPF/EPD resource. It stores the resource name, frame index, flip state, and palette name, then draws through shared render callbacks.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| Constructor | `0x004991f0-0x004992a8` | Initializes the base control, copies resource/palette names, stores frame index, and sets flip state. |
| Destructor | `0x004992b0-0x0049930e` | Releases cached image data and chains to the pane base destructor. |
| `LoadAndRenderImage` | `0x00499310-0x004993a5` | Prepares the pane draw surface through `dword_69B3FC`, loads one frame through `g_pEPFLib`, fetches a palette, blits to the pane surface through `dword_69B3E8`, and caches the result. |
| Adjustor thunks | `0x0049af53-0x0049af69` | Secondary/tertiary destructor adjustors referenced from EPF vtables. |
| Scalar deleting destructor | `0x0049b1b0-0x0049b24f` | Destructor wrapper with optional `operator delete`. |

## Evidence Notes

- Live IDA `py_eval` on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms exact local function bounds for the constructor, non-deleting destructor, render helper, adjustors, and scalar deleting destructor.
- The constructor has 66 unique caller functions across dialog/control construction paths, matching reusable control ownership.
- Constructor, destructor, and scalar deleting destructor write EPF vtables `0x00618248`, `0x006182b0`, and `0x006182e0`.
- Vtable slots place scalar deleting destructor at `0x00618248 -> 0x0049b1b0`, render helper at `0x0061828c -> 0x00499310`, and adjustors at `0x006182b0 -> 0x0049af53` / `0x006182e0 -> 0x0049af5e`.
- Constructor stores the EPF/EPD resource name at `this + 0x108`, frame index at `this + 0x128`, flip/control state at `this + 0xff`, and default palette `BARAM.PAL` at `this + 0x12a` when no palette is supplied.
- `LoadAndRenderImage` calls the surface/tile setup helpers `0x00457a60` and `0x004b9660`, callback slot `dword_69B3FC(this, this + 0x44)`, resource lookup `0x004d02f0` through `dword_67A744`, palette lookup `0x00543d70` through `dword_67A7E0`, blit callback `dword_69B3E8`, and cache finalizer `0x00457ab0`.
- The following in-band code at `0x004993b0+` installs `TargetOptionEditControlPane` vtables, so it remains excluded from this class.

## Dependencies

- `g_pEPFLib`: process-wide `ImageLib` singleton whose layout lookup methods are currently recovered as `ResourceLayoutTable`.
- `g_pPaletteLib`: palette lookup service.
- `dword_69B3FC`: shared surface-prep callback table slot at `0x0069b3fc`; IDA shows `LoadAndRenderImage` passing `(this, this + 0x44)`.
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
  - Summary/evidence: control role, constructor/destructor/render/destructor-wrapper methods, EPF/palette/render callback dependencies, and thunk caveat are documented; remaining uncertainty is final member names and callback signature cleanup.
- 2026-06-04: Raised from `72/80` to `84/86`, marked reconstructable, and attached to [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md).
  - Before: class metadata was unassigned, function ranges were start-only, parent path was blank, and vtable/caller evidence was sparse.
  - After: live IDA evidence records executable identity, exact bounds, 66-constructor-caller fanout, vtable stores/slots, render callback dependencies, default palette behavior, and TargetOption exclusion.
  - Reasoning: parent [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md) now has a valid `NexusTK/ui/controls/` path and strong module evidence. Final C++ remains blank because source-facing field names and callback typedefs remain below the 95/95 threshold.
