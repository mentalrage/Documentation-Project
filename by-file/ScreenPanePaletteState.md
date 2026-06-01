*** UID:0000NC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScreenPanePaletteState

## Status

- Confidence: strong for helper behavior at `0x00543d30` and `0x00543ee0`, strong for `PaletteLib`-resident ownership, medium for final class/facet naming.
- Proposed module: [UID:0000MA][Palette](by-file/Palette.md) / [UID:0000MB][PaletteLib](by-file/PaletteLib.md) as a palette-manager-resident screen-palette helper.
- Current recovered source: `source-3/simroot_v2/class_ScreenPanePaletteState_543D30.cpp`
- Main address ranges: `0x00543d30-0x00543d3c` and `0x00543ee0-0x00543f54`.

## File Role

`ScreenPanePaletteState_543D30` is a small screen/palette state helper recovered as a separate class by Wave3, but current IDA evidence shows it operates on the [UID:0000MB][PaletteLib](by-file/PaletteLib.md) singleton object. It stores a mode, owns a list of child palette-slot states, and owns two 25-entry palette banks that mirror the same 25-slot palette-family model used by `PaletteLib`.

`ScreenPane` triggers these methods during message handling, but it does not own the state. Confirmed callers pass `g_pPaletteLib` / `dword_67A7E0` as `this`, and `PaletteLib::PaletteLib` initializes the fields used by `SetMode` and `ResetSlots`.

Earlier docs included `0x00543f60` and `0x00543f80` as adjacent lower-only helpers for this class. IDA MCP recheck on 2026-05-25 shows those functions are called with `g_pPaletteLib` as `this`, so they are now documented as [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md).

## Ownership Hypothesis

The best current reconstruction is a helper/facet inside the palette/render subsystem:

```text
render/Palette.cpp or render/PaletteLib.cpp
  class PaletteLib
  PaletteLib screen-palette-state facet/base
  class ScreenPanePaletteSlotState or equivalent slot-state records
  ApplyPaletteEntryMovesToSlotState
  ApplyPaletteEntryMovesToCollection
```

The final source-facing names are still open: original code may have used a small base/facet class, private helper methods, or a nested state object inside `PaletteLib`. Do not migrate it into `ui/core/ScreenPane.cpp` without new ownership evidence.

## Cross-References

- [UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md)
- [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `80`.
  - Evidence: document captures helper behavior, PaletteLib ownership, wrong ScreenPane ownership correction, ownership hypothesis, and cross-references; confidence is limited by final class/facet naming.
