*** UID:0000NJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScrollSpellInventoryPane

## Status

- Confidence: strong for spell-scrollbar behavior, inventory-module placement, and child layout/vtable anchors; medium for whether the original source kept a standalone file or folded this implementation into `NewSpellInventoryPane`.
- Proposed module: `ui/inventory/ScrollSpellInventoryPane.cpp`, or folded into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md).
- Current recovered source: `source-3/simroot_v2/class_ScrollSpellInventoryPane.cpp`
- Evidence basis: `simroot_v2` method anchors plus IDA MCP lookup/caller checks on 2026-05-24.

## File Role

`ScrollSpellInventoryPane.cpp` should own the spell-inventory private scrollbar if final migration preserves a separate file. It manages scroll range, current position, activation, drag/click state, repeat timers, painting, part rectangles, hover part updates, and reset-to-idle behavior for the newer spell inventory UI.

The source may also have been a private nested/helper implementation inside `NewSpellInventoryPane.cpp`: IDA currently observes the constructor `0x0055f450` called only from `NewSpellInventoryPane::NewSpellInventoryPane` at `0x0057d013`.

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x0055f450-0x0055f4f0` | constructor | Initializes orientation, owner callback state, and pane base. |
| `0x0055f560-0x0055f609` | range/position/activation helpers | Clamps scroll range and position, activates the control, and invalidates as needed. |
| `0x0055f650-0x0055f882` | mouse/repeat handlers | Handles drag/click interactions and repeat scroll scheduling. |
| `0x0055f890-0x0055ff6f` | paint | Draws `SLIDEBG.EPF`/`SCRBUTT.EPF` track sections and button state. |
| `0x00560290-0x0056058f` | part/hover helpers | Computes scrollbar part rectangles and invalidates changed hover regions. |
| `0x00560710-0x0056089d` | [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | Recomputes spell-scroll position from drag/click geometry and calls back into `NewSpellInventoryPane`. |
| `0x005608a0-0x005608fc` | [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Generated reset helper; IDA does not currently define this as a function start, but raw disassembly is method-shaped. |
| [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md) | offsets `+0xf8` through `+0x10f` | Packed scroll style, orientation, current/range words, enabled/hover/active state, and drag point. |
| [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md) | `0x00623e94`, `0x00623ee0`, `0x00623f10` | Three pane views for paint, mouse input, and repeat callbacks. |

## Boundary Notes

This is not the generic [UID:0000NF][ScrollBar](by-file/ScrollBar.md) module. It is a feature-specific companion used by [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) unless later evidence proves reuse outside spell inventory.

Generated source contains polluted helper labels from fitting-room/interface-effect/control code. Treat those as shared render/control helper names, not ownership evidence.

Current metadata reports `vtable_count: 0` even though IDA confirms three `ScrollSpellInventoryPane` vtable bases. Keep the generated inventory as data debt until generated metadata records these tables.

## Score Rationale

| Evidence | Relevance |
| --- | --- |
| [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) | Reviewed `82/82` module parent for the `ui/inventory/` spell-inventory family and candidate `ScrollSpellInventoryPane.cpp` split. |
| [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) | Class page records the constructor, range/position helpers, input/repeat/paint/part-rect behavior, layout/vtable anchors, and reset-helper caveat. |
| [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) | Confirms the executable aggregate, sole observed constructor caller in `NewSpellInventoryPane`, 0x110-byte object allocation, vtable stores, and raw helper gap. |
| [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Strong raw-byte evidence for reset-to-idle behavior, with modeled-function and caller-provenance caveats that keep confidence at 80. |

The confidence is raised only to `80` because file placement under `ui/inventory/` is well supported, but the standalone file versus private `NewSpellInventoryPane` fold remains unresolved and final C++ stays below the 95/95 gate.

## Cross-References

- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md)
- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md)
- [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md)
- [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md)
- [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document covers role, proposed contents, range map, helper functions, layout/vtable refs, feature-specific boundary rules, and generated-output caveats; confidence is capped by possible nesting under `NewSpellInventoryPane` and current Wave3 vtable metadata debt.
- 2026-06-01: Added projected path `NexusTK/ui/inventory/`.
  - Evidence: this page already proposes `ui/inventory/ScrollSpellInventoryPane.cpp` or a fold into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md), and current spell-inventory source placement uses the same folder.
- 2026-06-07: Raised confidence from `78` to `80`.
  - Before: The page had enough range, layout, vtable, path, and module evidence for high completion, but stayed just below the parent-attachment confidence gate.
  - Changed to: Added score rationale tying this file to [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md), [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md), and the exact aggregate/raw-helper by-memory pages, while preserving the standalone-vs-folded source caveat.
  - Evidence: the spell-inventory module page is already `82/82`, the executable aggregate and reset helper record IDA-backed object size, vtables, caller, and raw-helper evidence, and generated metadata debt is limited to vtable inventory rather than source ownership.
