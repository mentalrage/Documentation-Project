*** UID:0000NC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScreenPanePaletteState

## Status

- Confidence: very strong that the recovered file/class spelling is historical only; exact PaletteLib method behavior, ownership, callers, layout, and focused source placement are closed.
- Source route: no standalone module. [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md) emits both bodies through [UID:0000MB][PaletteLib](by-file/PaletteLib.md), `NexusTK/render/PaletteLib.cpp`.
- Historical recovered source lead only: `source-3/simroot_v2/class_ScreenPanePaletteState_543D30.cpp`; it is not current source authority or an emitted file.
- Main address ranges: `0x00543d30-0x00543d3c` and `0x00543ee0-0x00543f54`.
- Standalone disposition: `PROPOSED_RECONSTRUCTION_PATH:"NONE"` because the recovered class name is a focused documentation view over `PaletteLib` fields, not a proven original source root.

## File Role

`ScreenPanePaletteState_543D30` is a historical Wave3 recovery alias, not a source file/class/helper. Current IDA evidence shows the two bodies are ordinary methods on the [UID:0000A1][PaletteLib](by-class/PaletteLib.md) singleton object. PaletteLib stores a mode, loaded-palette list, and two 25-entry banks as part of its exact `0x25c8` layout.

`ScreenPane` triggers `PaletteLib::SetScreenPaletteMode` and `PaletteLib::ResetScreenPaletteSlots` during message handling, but it does not own the state. All six confirmed callers pass `g_pPaletteLib` / `dword_67A7E0` as `this`, and `PaletteLib::PaletteLib` initializes the fields used by both methods.

[UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md) and [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md) document the observed layout: mode at `+0x04`, the child slot list at `+0x08`, and two 25-entry banks at `+0x690` and `+0x6f4`. `ResetSlots` chooses the bank from a `g_pConfig + 0x28de5e` byte, walks the slot list, calls [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) on the `DLPalette *` reached from each list entry at `+0x04`, then calls the collection helper at `0x005435b0` for each of 25 bank entries.

Earlier docs included `0x00543f60` and `0x00543f80` as adjacent lower-only helpers for this class. IDA MCP recheck on 2026-05-25 shows those functions are called with `g_pPaletteLib` as `this`, so they are now documented as [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md).

## Ownership Hypothesis

The resolved source route is:

```text
  NexusTK/render/PaletteLib.h
    class PaletteLib
    struct PaletteLibLoadedEntry
  NexusTK/render/PaletteLib.cpp
    PaletteLib::SetScreenPaletteMode
    PaletteLib::ResetScreenPaletteSlots
  NexusTK/render/Palette.cpp umbrella support
    DLPalette::ApplyPaletteEntryMoves
    ApplyPaletteEntryMovesToCollection
```

No independent facet/base/nested-state declaration or `ScreenPanePaletteState.cpp` is emitted. Original private field spellings remain a confidence cap, but they do not reopen source ownership. Do not migrate these bodies into `ui/core/ScreenPane.cpp`, broad Palette output, or a recovered standalone file.

## B001 UID00028T Historical File-Alias Closure - 2026-07-20

- `0x00543d30-0x00543d3d` is exact `PaletteLib::SetScreenPaletteMode`, SHA256 `DE8F7DA299F04A4488AFC2EB5581093BE8A8C778C1BFA0A2FF76D4F1B6FCEC1E`, with four callers.
- `0x00543ee0-0x00543f55` is exact `PaletteLib::ResetScreenPaletteSlots`, SHA256 `729B504AE82D630888B527FC3766A9377785C1D6DA5F34248AD9D2A6CDD711FA`, with two callers and padding `[0x00543f55,0x00543f60)` before filter helpers.
- Receiver identity, exact class layout, loaded-record width/fields, `g_pConfig->m_shadowEnabled`, source/runtime banks at `+0x690/+0x6f4`, reverse no-guard traversal, and 25-list loop reject independent file/class ownership.
- This page remains `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`. It is documentation/provenance only; focused UID0000MB owns both definitions and broad UID0000MA retains shared DLPalette/free-helper support.
- Historical one-file-versus-facet uncertainty, recovered class source, broad Palette emitter, and ScreenPane ownership are superseded with concrete rejection reasons. The old spelling remains only as a search alias.

## Cross-References

- [UID:0000CC][ScreenPanePaletteState_543D30](by-class/ScreenPanePaletteState_543D30.md)
- [UID:0001E8][0x00543d30-0x00543f54.ScreenPanePaletteState](by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md)
- [UID:0001E7][0x00543450-0x00543665.PaletteListAndEntryMoveHelpers](by-memory/0x00543450-0x00543665.PaletteListAndEntryMoveHelpers.md)
- [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- 2026-07-20 B001 UID00028T callback: raised documentation quality to `90/94`; preserved path NONE/owner NONE; converted current-facing one-file/facet uncertainty into a definitive historical alias, synchronized exact PaletteLib method names/hashes/callers/layout/source route, and prohibited standalone/duplicate emission without removing earlier evidence.
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
- 2026-06-25 B014 reset-callee sync:
  - Score unchanged.
  - Replaced the old `ApplyPaletteEntryMovesToSlotState` wording with [UID:0001E5][0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves](by-memory/0x00542fa0-0x00543020.DLPaletteApplyPaletteEntryMoves.md) as the `DLPalette` method reached through each list entry's `+0x04` pointer.
  - Evidence: accepted B014 report traces the `ResetSlots` caller data flow and ties the callee's `+0x04/+0x08/+0x2c` fields to adjacent DLPalette loader/copy/raw-RGBA methods.
