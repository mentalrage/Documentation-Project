*** UID:00038P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000074 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000074 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LegendPane Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `LegendPane` three-view vtable layout.
- Disposition: reconstructable type/layout documentation parented to the `LegendPane` class.
- Source candidate: [UID:0000KM][LegendPane](by-file/LegendPane.md).
- Created from B001-048 split research of [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md).

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Evidence |
| --- | --- | --- | --- | --- | --- |
| `LegendPane` | [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md) | `0x00624388` | `0x00624400` | `0x00624430` | Constructor stores at `0x0056c466`, `0x0056c46e`, `0x0056c478`; primary `+0x60` is bool `OnMouseEvent`, secondary `+0x08` is bool `HandleKeyOrTextEvent`, and first slots retain inherited/compiler destructor adjustors. |

## Exact Input Slot Map

| View / offset | Cell | Target | Source cause |
| --- | --- | --- | --- |
| primary `+0x60` | `0x006243e8` | `0x0056c4b0` | `bool LegendPane::OnMouseEvent(Event *)` |
| primary `+0x64` | `0x006243ec` | `0x005909f0` | inherited TextEditPane key handler |
| secondary `+0x04` | `0x00624404` | `0x0055ef50` | inherited ScrollablePane pointer/mouse dispatcher |
| secondary `+0x08` | `0x00624408` | `0x0056c4a0` | `bool LegendPane::HandleKeyOrTextEvent(Event *)` |

## Boundary Evidence

- The exact table span is `0x00624384-0x00624438`, ending before the GroupPane vtable family.
- `LegendPane` is constructed by self-look and user-look flows, so consumer/caller context does not make either caller the direct owner of the class layout.
- This page is split out from [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md), which remains a non-emitting cross-source index.
- 2026-06-16 A001 live IDA/PE refresh reconfirmed constructor store xrefs from `0x0056c466`, `0x0056c46e`, and `0x0056c478`, false-stub slot refs at `0x00624408 -> 0x0056c4a0` and `0x006243e8 -> 0x0056c4b0`, and the `0x00624438` GroupPane boundary through the exact child data page.
- 2026-07-16 B001 live MCP session `64c11373` resolves the two source identities and their inherited neighbors. Separate function objects and sole table references prove distinct source overrides, while the complete UID000074 declaration regenerates all three views without hand-written vtable/RTTI arrays.

## Assignment Gate

`CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:000074][LegendPane](by-class/LegendPane.md). This page covers a single class vtable layout, so the class is the narrowest semantic parent at `91/93`; its file parent [UID:0000KM][LegendPane](by-file/LegendPane.md) is `90/92`. Exact child UID0002V0 routes here without using the broad cross-source UID0001Y0 index.

## Score Rationale

Completion `90` and confidence `94` are supported by exact RTTI/vtable boundaries, constructor stores, complete input slot identities, inherited neighboring cells, distinct-contract proof, GroupPane successor boundary, and regeneration from the complete LegendPane declaration. Only original lexical spelling and physical header/file factoring remain capped.

## Cross-References

- [UID:0000KM][LegendPane](by-file/LegendPane.md)
- [UID:000074][LegendPane](by-class/LegendPane.md)
- [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md)

## Changes

- 2026-07-16 B001 UID00023W accepted implementation callback:
  - Raised `88/91 -> 90/94`.
  - Added the complete primary/secondary input slot map, inherited neighboring cells, exact source method causes, and compiler-generated regeneration disposition.
  - Preserved UID000074 owner/emitter and broad UID0001Y0 containment exclusion.
- 2026-06-16 A001 file-completion support refresh:
  - Changed `87/91 -> 88/91`.
  - Evidence: live IDA/PE reconfirmed constructor store refs, false-stub vtable slot refs, and the exact GroupPane successor boundary; [UID:000074][LegendPane](by-class/LegendPane.md) and [UID:0000KM][LegendPane](by-file/LegendPane.md) both have refreshed scores.
  - Scope: owner/emitter stay [UID:000074][LegendPane](by-class/LegendPane.md); final C++ remains blank because source-level virtual names are not final.
- 2026-06-11 Agent-A001 Batch 232:
  - Before: `86/91`, parent blank pending LegendPane class/file repair.
  - Changed to: `87/91`, parent [UID:000074][LegendPane](by-class/LegendPane.md).
  - Evidence: [UID:000074][LegendPane](by-class/LegendPane.md) is now `85/88` and its file parent is `85/86`; live IDA rechecked the three table bases and constructor store refs while routing [UID:0002V0][0x00624384-0x00624438.LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md) through this type page.
- 2026-06-11 supervisor implementation of B001-048: created source-local LegendPane vtable page instead of using the broad multi-owner LookPane vtable family as a parent.
