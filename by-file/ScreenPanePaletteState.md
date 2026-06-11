*** UID:0000NC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScreenPanePaletteState

## Status

- Confidence: strong for helper behavior at `0x00543d30` and `0x00543ee0`, `PaletteLib`-resident ownership, caller contexts, and bank-table offsets; medium only for final source-facing facet naming.
- Proposed module: [UID:0000MA][Palette](by-file/Palette.md) / [UID:0000MB][PaletteLib](by-file/PaletteLib.md) as a palette-manager-resident screen-palette helper.
- Current recovered source: `source-3/simroot_v2/class_ScreenPanePaletteState_543D30.cpp`
- Main address ranges: `0x00543d30-0x00543d3c` and `0x00543ee0-0x00543f54`.
- Standalone disposition: `PROPOSED_RECONSTRUCTION_PATH:"NONE"` because the recovered class name is a focused documentation view over `PaletteLib` fields, not a proven original source root.

## File Role

`ScreenPanePaletteState_543D30` is a small screen/palette state helper recovered as a separate class by Wave3, but current IDA evidence shows it operates on the [UID:0000MB][PaletteLib](by-file/PaletteLib.md) singleton object. It stores a mode, owns a list of child palette-slot states, and owns two 25-entry palette banks that mirror the same 25-slot palette-family model used by `PaletteLib`.

`ScreenPane` triggers these methods during message handling, but it does not own the state. Confirmed callers pass `g_pPaletteLib` / `dword_67A7E0` as `this`, and `PaletteLib::PaletteLib` initializes the fields used by `SetMode` and `ResetSlots`.

[UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md) and [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md) document the observed layout: mode at `+0x04`, the child slot list at `+0x08`, and two 25-entry banks at `+0x690` and `+0x6f4`. `ResetSlots` chooses the bank from a `g_pConfig + 0x28de5e` byte, walks the slot list, applies [UID:0001E5][0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState](by-memory/0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState.md), then calls the collection helper at `0x005435b0` for each of 25 bank entries.

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
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:0001E5][0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState](by-memory/0x00542fa0-0x00543020.ApplyPaletteEntryMovesToSlotState.md)
- [UID:0001E7][0x00543450-0x00543665.PaletteListAndEntryMoveHelpers](by-memory/0x00543450-0x00543665.PaletteListAndEntryMoveHelpers.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- 2026-06-05: Marked the projected reconstruction path as `NONE`.
  - Before: the blank path made this PaletteLib-resident helper/facet appear as a missing generated source root.
  - After: the page is explicit non-standalone documentation; palette state stays folded into [UID:0000MA][Palette](by-file/Palette.md) / [UID:0000MB][PaletteLib](by-file/PaletteLib.md) until a separate source split is proven.
  - Evidence: live IDA MCP `lookup_funcs` confirms the helper starts at `0x00543d30` (`0xd` bytes) and `0x00543ee0` (`0x75` bytes), and `callers` for `0x00543d30` remain inside `sub_556D50`, matching the current PaletteLib helper/facet interpretation.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `82` and confidence to `80`.
  - Evidence: document captures helper behavior, PaletteLib ownership, wrong ScreenPane ownership correction, ownership hypothesis, and cross-references; confidence is limited by final class/facet naming.
- 2026-06-07 A010 PaletteLib-facet synchronization:
  - What existed before: the page was scored `82/80` and carried the `NONE` path, but did not yet summarize the exact class/memory layout, `g_pPaletteLib` caller contexts, config-selected 25-entry banks, or child/collection helper calls already documented in the class and memory pages.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, stronger `NONE` disposition wording, explicit layout/loop/helper evidence, and added `g_pPaletteLib` plus helper-memory cross-references.
  - Evidence: synchronized existing [UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md), [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md), [UID:0000MB][PaletteLib](by-file/PaletteLib.md), and [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md) notes without adding new live IDA facts.
