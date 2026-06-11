*** UID:0000CN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScrollSpellInventoryPane

## Status

- Confidence: strong for scrollbar behavior, constructor ownership, layout/vtable anchors, and the `NewSpellInventoryPane` caller; medium for final standalone-vs-folded source split and one reset-helper boundary.
- Likely source file: [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md), with a possible final fold into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md). `ScrollSpellInventoryPane` is the current by-file parent because it records the matching `ui/inventory/` projected path, dedicated spell-scrollbar file hypothesis, and 80+ parent confidence.
- Address range: [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- Layout: [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md)
- Vtables: [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- Read-only-data evidence: [UID:00026D][0x00623d58-0x00624184.ScrollPaneReadOnlyData](by-memory/0x00623d58-0x00624184.ScrollPaneReadOnlyData.md)
- Final C++: intentionally blank because the standalone-vs-folded source split and raw reset-helper provenance remain below the final-source gate.

## Class Purpose

`ScrollSpellInventoryPane` is the EPF-backed scrollbar pane used by spell inventory UI. It manages scroll range, position, activation, drag/click state, repeat timers, painting, part rectangles, hover part updates, and reset-to-idle behavior.

## Lifecycle Summary

`ScrollSpellInventoryPane` is a private spell-inventory scrollbar companion. The constructor is observed from [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md), and the surrounding `SpellInventoryPane` file docs keep it under `NexusTK/ui/inventory/` rather than generic control or text-edit ownership.

| Phase | Evidence | Notes |
| --- | --- | --- |
| Construction/setup | `0x0055f450-0x0055f4f1`, `0x0055f5f0-0x0055f609` | Builds the `0x110`-byte pane tail, installs the three vtable views, records orientation/state fields, and activates the spell scrollbar from the new-spell inventory path. |
| Range/position | `0x0055f560-0x0055f5e6` | Clamps maximum range/current position and invalidates only on state changes. |
| Input/repeat | `0x0055f650-0x0055f882`, [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | Handles drag/click/repeat behavior, converts drag geometry into scroll positions, and notifies the owning spell-inventory pane. |
| Paint/layout | `0x0055f890-0x0055ff6f`, `0x00560290-0x00560516` | Draws the EPF-backed track/button assets and computes part rectangles from the layout fields. |
| Hover/reset | `0x00560520-0x0056058f`, [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Updates hover state and clears capture/highlight state; final source naming is capped because IDA still treats the reset body as raw code rather than a modeled function. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScrollSpellInventoryPane` | `0x0055f450-0x0055f4f1` | Constructs scrollbar pane with orientation and initial state. |
| `SetMaxRange` | `0x0055f560-0x0055f5ba` | Clamps max range and current position. |
| `SetScrollPosition` | `0x0055f5c0-0x0055f5e6` | Updates scroll position and invalidates. |
| `Activate` | `0x0055f5f0-0x0055f609` | Shows the scrollbar and triggers initial paint. |
| `HandleMouseEvent` | `0x0055f650-0x0055f830` | Handles mouse drag and click interactions. |
| `OnScrollRepeat` | `0x0055f850-0x0055f882` | Auto-repeats scroll action while a button is held. |
| `OnPaint` | `0x0055f890-0x0055ff6f` | Paints track sections and scroll button. |
| `GetPartRect` | `0x00560290-0x00560516` | Calculates rectangles for scrollbar parts. |
| `SetHoverPart` | `0x00560520-0x0056058f` | Updates hover part and invalidates affected regions. |
| `UpdateFromDrag` candidate | [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | Recomputes the scroll position from drag/click geometry and notifies the owning spell inventory pane. |
| `ResetScrollState` candidate | [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Raw method-shaped reset helper; IDA does not currently define a function at this start. |

## Evidence Notes

- IDA MCP confirms constructor, paint, and part-rect function boundaries.
- IDA MCP caller check on 2026-05-24 shows the constructor `0x0055f450` is only directly called from `NewSpellInventoryPane::NewSpellInventoryPane` at `0x0057d013`.
- IDA MCP lookup confirms the activation helper `0x0055f5f0` as a real `0x1a`-byte function.
- IDA reports no function at `0x005608a0`; previous modeled function is `0x00560710-0x0056089d`, and raw disassembly shows method-shaped reset code through `0x005608fc` before the next function at `0x00560900`. Treat the reset-helper function-table mismatch as data debt.
- IDA-backed allocation and constructor evidence records the same `0x110` scrollbar tail field pattern as the item-inventory scrollbar; see [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md).
- 2026-05-26 IDA MCP confirms vtable bases `0x00623e94`, `0x00623ee0`, and `0x00623f10`, with paint, mouse, and repeat slots mapped in [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md).
- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) now gives the file-level container a reviewed `84/80` score and the same projected `NexusTK/ui/inventory/` path used by the surrounding [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) module.
- The raw reset helper and aggregate/update child pages remain useful evidence, but this class page does not attach or rescore by-memory children. [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) and [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) are still below 80 completion, and [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) keeps a function-table/caller-provenance caveat.

## Parent And Score Rationale

| Item | Score | Relevance |
| --- | ---: | --- |
| [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) | `84/80` | Current parent: documents the dedicated spell-scrollbar file hypothesis, projected path, method family, layout/vtable refs, and possible fold into `NewSpellInventoryPane`. |
| [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) | `82/82` | Confirms the broader `ui/inventory/` ownership and the spell-inventory/new-spell split that hosts this scrollbar. |
| [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) | `72/82` | Confirms the executable range, constructor caller, vtable stores, field offsets, and raw-helper caveat, but remains below the by-memory attachment completion threshold. |
| [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | `84/86` | Strong evidence for the reset behavior and exact raw span; keeps final C++ and higher class confidence capped because no modeled function start or caller provenance exists. |
| [UID:00026D][0x00623d58-0x00624184.ScrollPaneReadOnlyData](by-memory/0x00623d58-0x00624184.ScrollPaneReadOnlyData.md) | `82/86` | Places the `ScrollSpellInventoryPane` RTTI/vtable band between neighboring scroll-pane families, matching the three vtable bases documented by the vtable page. |

The class confidence is raised only to `82`, not higher, because the local behavior, file parent, vtables, layout, and read-only-data band are well supported, but the original standalone-vs-folded source split and raw reset-helper identity are still not final-source quality.

## Cross-References

- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md)
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md)
- [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)
- [UID:00026D][0x00623d58-0x00624184.ScrollPaneReadOnlyData](by-memory/0x00623d58-0x00624184.ScrollPaneReadOnlyData.md)
- [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `80/78`.
  - Before: The page was unevaluated despite documenting the spell-inventory scrollbar methods, caller, layout, vtables, and reset-helper mismatch.
  - After: Scored as high completion with medium-high confidence because scrollbar behavior is strong, while one raw reset-helper boundary and source placement remain unresolved.
  - Evidence: Existing method notes, IDA caller/evidence notes, layout/vtable references, and NewSpellInventoryPane relationship support the score.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE`.
  - Before: The class page documented project-owned behavior but had no validator reconstructable flag.
  - Changed to: The page is flagged as rebuild-owned while `AUTOGEN_PARENT_UID` and C++ remain blank.
  - Evidence: IDA MCP confirms `NewSpellInventoryPane::NewSpellInventoryPane` allocates a 0x110-byte pane, calls the `0x0055f450` constructor, and owns the spell-inventory scrollbar; final source-file placement and source-quality C++ are not at the 95+ gate.
- 2026-06-07: Raised confidence from `78` to `80` and attached the class to [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md).
  - Before: The class had 80 completion but stayed below the attachment confidence gate, and the matching file page also sat at 78 confidence.
  - Changed to: `AUTOGEN_PARENT_UID` is now `0000NJ`, with added parent/score rationale explaining the file attachment, raw reset-helper caveat, and why by-memory children and final C++ are not changed here.
  - Evidence: [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) records the dedicated `ui/inventory/` spell-scrollbar source hypothesis, [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) corroborates module placement, [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) records caller/layout/vtable evidence, and [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) preserves the reset-helper provenance cap.
- 2026-06-07 A001 class evidence refresh:
  - Changed to: `COMPLETION:82` and `CONFIDENCE:82`.
  - Summary/evidence: added a lifecycle summary spanning construction, range/position updates, input/repeat handling, paint/part-rect layout, and hover/reset cleanup; linked the shared scroll-pane read-only-data band for the spell-scrollbar vtables; removed stale recovered-file wording; kept the parent attachment and blank final C++ because the raw reset helper and standalone-vs-folded source split still cap final-source confidence.
