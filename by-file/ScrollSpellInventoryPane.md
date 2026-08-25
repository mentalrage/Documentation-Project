*** UID:0000NJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScrollSpellInventoryPane

## UID0000O1 Exclusion Cross-Reference - 2026-08-22

[UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) now reconstructs only legacy `SpellInventoryPane` and `SpellInventoryPane2`. This accepted Scroll file remains a separate `NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp/.h` compilation unit with its existing class, exact children, formal source, scores, and ownership unchanged. Its constructor-only relationship with NewSpell establishes a private companion, not ownership by or merger into UID0000O1.

## UID0000NJ Whole-File Reconstruction Closure - 2026-08-16

`ScrollSpellInventoryPane.cpp` is the standalone source root for the complete authored island `[0x0055f450,0x005608fc)`: 5,292 bytes, SHA256 `cd32902d15a947bafd796b8db7505be5568d8a73e9b95a5ae82f7e9d6eba1c57`. The completed generic inventory-scroll island has the same length and nineteen-method/sixteen-padding topology; 5,130 of 5,292 bytes are identical. The 162 differing bytes occur in 77 relocation/data runs that select the spell owner, spell vtables, and spell-specific resources rather than another source owner.

The compilation unit has exactly nineteen class-owned methods in address and source order. Each method now emits from its exact bounded by-memory child through [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md); the broad [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) is an index/evidence page and emits no duplicate source.

| Position | UID and exact range | Source method | Binary/source evidence | Score |
| --- | --- | --- | --- | --- |
| 10 | [UID:000538][0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor](by-memory/0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor.md) | constructor | 161 bytes; SHA256 `40613436b6c5f0fe7f5b8e156fbf05de9ef8bcbd80e0fda85f03b5aaee3d09a1`; sole caller `0x0057d013`; three vtable stores | 93/95 |
| 20 | [UID:000539][0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw](by-memory/0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw.md) | `SetSizeIndex` | 39 bytes; SHA256 `48679840081c330a7852b3e68ce164e8e650e230fb07769968a9f84c4790758a`; exact sibling clone; zero entry xrefs | 89/91 |
| 30 | [UID:00053A][0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw](by-memory/0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw.md) | `SetScrollStyle` | 36 bytes; SHA256 `4ea6ca081e50c45c9d819c4df934434c95707a445f8f06cac86a1c8b5afad5c4`; exact sibling clone; zero entry xrefs | 89/91 |
| 40 | [UID:00053B][0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange](by-memory/0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange.md) | `SetMaxRange` | 91 bytes; SHA256 `c504a31bd1577b41537ae91425c5d2575483ed073207193c545b615792be1f23`; caller `0x0057d2b9` | 93/95 |
| 50 | [UID:00053C][0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition](by-memory/0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition.md) | `SetScrollPosition` | 39 bytes; SHA256 `c823be0b3a17b1411aac7d79c9052da8122a7e32f5b2a7c23fcbfb6c1aeee940`; four callers | 93/95 |
| 60 | [UID:00053D][0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate](by-memory/0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate.md) | `Activate` | 26 bytes; SHA256 `cc2001d3751e1f7d5535f9e6c63305f9cebda99fe58184945e9cfccab9451847`; caller `0x0057d028` | 90/92 |
| 70 | [UID:00053E][0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw](by-memory/0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw.md) | `Deactivate` | 26 bytes; SHA256 `c97d8f364beb37dcf10c6177a75485635a57c70d4e389ace3a7bbae35761f322`; exact sibling clone | 89/91 |
| 80 | [UID:00053F][0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw](by-memory/0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw.md) | `CanScroll` | 26 bytes; SHA256 `e5e73329a48d7f7236650f40361f4a4464b6b6d5777fde7a286d05ed94f5af19`; exact sibling clone | 92/94 |
| 90 | [UID:00053G][0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent](by-memory/0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent.md) | `HandlePointerOrMouseEvent` | 481 bytes; SHA256 `77b5a319bd719d1068101f3471b9d86458f00158936c6456488e324c044fd581`; EventHandler slot `0x00623ee4` | 90/92 |
| 100 | [UID:00053H][0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent](by-memory/0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent.md) | `HandleKeyOrTextEvent` | 5 bytes; SHA256 `cc0e3cb106eb0fdec984d44a563d98c3da80700bbb8d2be4e66ebd54a9919626`; EventHandler slot `0x00623ee8` | 93/95 |
| 110 | [UID:00053I][0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer](by-memory/0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer.md) | `OnTimer` | 51 bytes; SHA256 `85653f517fb94d695cc08eb66cfdb6714129374b64d0d7ac7a4f782a489e4e91`; TimerHandler slot `0x00623f14` | 93/95 |
| 120 | [UID:00053J][0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint](by-memory/0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md) | `OnPaint` | 1,760 bytes; SHA256 `57abec85e56067fb5ea52643ecaeeb3af504c904e1dd7c6859a8ca0ae8e71cdd`; primary slot `0x00623ed8` | 90/92 |
| 130 | [UID:00053K][0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart](by-memory/0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart.md) | `HitTestPart` | 797 bytes; SHA256 `17b1dfb9cb93b73473af0d43a3aeb044dbeb4497e9d14d6946d1d1cb76a22f4e`; two callers | 90/92 |
| 140 | [UID:00053L][0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect](by-memory/0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect.md) | `GetPartRect` | 647 bytes; SHA256 `177b3c96275f2428d35b58f81bbad6a624b92294b5f17be702c9989e64f964be`; thirteen callers | 90/92 |
| 150 | [UID:00053M][0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw](by-memory/0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw.md) | `SetHoverPart` | 112 bytes; SHA256 `6022e9b09a62d700988ba63a729a9657c81345fb13d7afabdc21803bfb95b668`; exact sibling clone | 91/93 |
| 160 | [UID:00053N][0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw](by-memory/0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw.md) | `BeginInteraction` | 191 bytes; SHA256 `f16fe1664be8fe9a1b6460a1a01998710460c89f8579a4e253a42e863f81cef5`; exact sibling clone | 91/93 |
| 170 | [UID:00053O][0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll](by-memory/0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll.md) | `UpdateDragScroll` | 192 bytes; SHA256 `76693d5645830bd3d04923b1524370af5c1998373fcf157929bdc9c23daf3fe2`; three callers; no explicit source arguments | 90/92 |
| 180 | [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | `UpdateFromDrag` | 397 bytes; SHA256 `09733ac52ea007586c04d5429f87094fa3f0d75481f0e801beabc55dda5320eb`; two callers | 91/93 |
| 190 | [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | `ResetScrollState` | 92 bytes; SHA256 `3d64e239e2e318d9f95a42ef76be91240a9ae8afbb1279629730d308ea6e6132`; exact sibling clone | 93/94 |

The sixteen `CC` alignment spans are `[55f4f1,55f500)` 15 bytes, `[55f527,55f530)` 9, `[55f554,55f560)` 12, `[55f5bb,55f5c0)` 5, `[55f5e7,55f5f0)` 9, `[55f60a,55f610)` 6, `[55f62a,55f630)` 6, `[55f64a,55f650)` 6, `[55f831,55f840)` 15, `[55f845,55f850)` 11, `[55f883,55f890)` 13, `[56028d,560290)` 3, `[560517,560520)` 9, `[56064f,560650)` 1, `[56089d,5608a0)` 3, and successor alignment `[5608fc,560900)` 4. No child absorbs padding or crosses successor `0x00560900`, which begins `ScrollNewGroupPane` construction.

The normal header is owned by UID0000CN and declares the exact `0x110` class, `ScrollSpellInventoryPart`, nineteen methods, private `NewSpellInventoryPane` friendship, and size guard. `NewSpellInventoryPane` remains the constructor consumer and callback parent, not the file owner. `kScrollPanePartExtentBySkin` remains owned by ScrollBar, while `SLIDEBG.EPF`, `SCRBUTT.EPF`, `SLIDEBG.PAL`, and `SCRBUTT.PAL` remain external render resources. No authored destructor, EH object, file-local global/string/table, import wrapper, third-party source, or post-`0x005608fc` body belongs to this unit. Shared deleting/adjustor wrappers, RTTI, vtables, and alignment bytes are compiler consequences rather than handwritten source.

Historical generated defects included seventeen absent method bodies, `m_bounds` in `UpdateFromDrag`, and a false two-argument `UpdateDragScroll` declaration. The accepted child split and complete class header replace those defects; generated output is validator-owned and must be physically reread after the owning-file refresh.

## UID0000LU Normal Header Contract - 2026-08-15

ScrollSpellInventoryPane remains a standalone `ui/inventory/ScrollSpellInventoryPane.cpp` companion. Its complete declaration is now in the normal sibling H channel, its CPP includes that header before established children, and NewSpell friendship is the exact private range/position callback route. Local reduced declarations and folding into NewSpell are rejected; all existing behavior, layout, vtables, source children, score, and path are preserved.

## Status

- Confidence: strong for spell-scrollbar behavior, inventory-module placement, class/layout/vtable ownership, exact update/reset children, and deterministic source order.
- Selected module: `NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp`. The former possible fold into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) remains documented as a historical rejected alternative rather than current placement.
- Current generated lead source observed by B002: `source-3/simroot_v2/ui/inventory/class_ScrollSpellInventoryPane.cpp`; active autogen destination `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp` was zero bytes before the reset child was populated.
- Evidence basis: existing documentation plus IDA MCP lookup/caller/xref/decompile/disassembly checks on 2026-05-24, 2026-06-11, and 2026-06-14.

## File Role

`ScrollSpellInventoryPane.cpp` owns the spell-inventory private scrollbar. It carries the [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) declaration and class-owned children for scroll range, current position, activation, drag/click state, repeat timers, painting, part rectangles, hover part updates, geometry-to-position conversion, and reset-to-idle behavior.

Historical alternative: the source may originally have been folded into `NewSpellInventoryPane.cpp` because IDA observes the constructor `0x0055f450` called only from `NewSpellInventoryPane::NewSpellInventoryPane` at `0x0057d013`. That constructor-only containment does not outweigh the dedicated class receiver, fields, three vtables, layout, contiguous implementation island, and established standalone file route, so the fold is rejected for current reconstruction.

## Proposed Contents

| Range | Current method family | Notes |
| --- | --- | --- |
| `0x0055f450-0x0055f4f0` | constructor | Initializes orientation, owner callback state, and pane base. |
| `0x0055f500-0x0055f553` | raw style/size setters | Source-shaped raw pockets that update `+0xf8` size/skin-table index and unresolved `+0xfa` scroll style/state byte, invalidating only on change. |
| `0x0055f560-0x0055f649` | range/position/activation/availability helpers | Clamps scroll range and position, activates the control, raw-clears enabled state, and tests whether scrolling is currently possible. |
| `0x0055f650-0x0055f882` | mouse/repeat handlers | Handles drag/click interactions, the secondary-view false-return virtual at `0x0055f840`, and repeat scroll scheduling. |
| `0x0055f890-0x0055ff6f` | paint | Draws `SLIDEBG.EPF`/`SCRBUTT.EPF` track sections and button state. |
| `0x0055ff70-0x00560516` | hit-test and part-rectangle helpers | Resolves pointer coordinates to scrollbar parts and computes scrollbar part rectangles from the tail layout fields. |
| `0x00560520-0x0056064e` | raw hover/active helpers | `SetHoverPart` invalidates changed hover regions; active/begin-interaction helper writes `m_activePart`, records the drag anchor, and schedules repeat/timer handling through the `+0xa4` view. |
| `0x00560650-0x0056070f` | input drag bridge | Dispatches active-part drag/click behavior and calls `UpdateFromDrag` from two internal sites. |
| `0x00560710-0x0056089d` | [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | Source-ready `UpdateFromDrag(int localY, int localX)` at position `180`; uses inherited `m_visibleBounds`, `+0x108/.y` and `+0x10c/.x`, preserves orientation-specific geometry formulas, and calls `NewSpellInventoryPane::OnScrollPositionChanged(unsigned char, short, short)` only on change. |
| `0x005608a0-0x005608fc` | [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Source-facing `ScrollSpellInventoryPane::ResetScrollState()`: source-shaped raw helper with no direct static route, no VA/RVA literal, no external branch into span, and no vtable slot; removes pending timers through the class `+0xa4` TimerHandler view, clears `m_activePart`, invalidates/clears old `m_hoverPart`, and is directly owned/emitted by class [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) with this file as source-file route. |
| [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md) | offsets `+0xf8` through `+0x10f` | Natural class tail declared once on UID0000CN, including Y/X `Point m_thumbDragOffset`; this nonreconstructable support page has no emitter and blank formals. |
| [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md) | `0x00623e94`, `0x00623ee0`, `0x00623f10` | Three inherited-pane views regenerated from UID0000CN virtual declarations; this nonreconstructable compiler-evidence page has no emitter and never emits literal arrays. |

## Source Emission Order

The class route uses deterministic positions under this source file:

| Position | UID | Source contribution |
| ---: | --- | --- |
| `10` | [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) | `Pane`-derived class declaration, natural `0x110` tail layout, accepted virtual/private declarations, size guard, and `[[CHILDREN]]`. |
| `10` | [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) | Covered-by aggregate comment; no duplicate broad body. |
| `20` | [UID:0001W1][ScrollSpellInventoryPaneLayout](by-type/by-struct/ScrollSpellInventoryPaneLayout.md) | Covered-by layout comment; fields remain on the class declaration. |
| `30` | [UID:0001YS][ScrollSpellInventoryPaneVtables](by-type/by-vtable/ScrollSpellInventoryPaneVtables.md) | Compiler-regenerated vtable comment; no literal arrays. |
| `80` | [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) | Exact source-bearing `UpdateFromDrag` body. |
| `90` | [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Existing exact `ResetScrollState` body. |

## Boundary Notes

This is not the generic [UID:0000NF][ScrollBar](by-file/ScrollBar.md) module. It is a feature-specific companion used by [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) unless later evidence proves reuse outside spell inventory.

Generated source contains polluted helper labels from fitting-room/interface-effect/control code. Treat those as shared render/control helper names, not ownership evidence.

Current metadata reports `vtable_count: 0` even though IDA confirms three `ScrollSpellInventoryPane` vtable bases. Keep the generated inventory as data debt until generated metadata records these tables.

## Score Rationale

| Evidence | Relevance |
| --- | --- |
| [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) | Reviewed module parent for the `ui/inventory/` spell-inventory family and candidate `ScrollSpellInventoryPane.cpp` split. |
| [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) | Class page records the constructor, range/position helpers, input/repeat/paint/part-rect behavior, layout/vtable anchors, and reset-helper caveat. |
| [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) | Confirms the executable aggregate, sole observed constructor caller in `NewSpellInventoryPane`, `0x110`-byte object allocation, vtable stores, exact padding, raw setter/disable/predicate/hover/active/reset pockets, and aggregate no-code policy. |
| [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) | Strong raw-byte evidence for reset-to-idle behavior, class owner/emitter route, first-draft child C++, and rejected static caller/table/vtable routes; modeled-function and caller-provenance caveats still cap final audit rather than the 85 gate. |

The file is `90/92` after complete ordinary closure: all nineteen exact method children, sixteen padding spans, standalone ownership, normal CPP/H assembly, corrected tail children, and non-emitting compiler/index pages are documented and generated. Remaining uncertainty is confined to unrecovered original private spellings and historical physical-file capitalization; the raw reset helper's no-direct-route evidence remains preserved without blocking its exact bounded source body.

## 2026-06-11 IDA Refresh

- `0x0057cf70` allocates `272` bytes, calls `0x0055f450(v2, 0)` at `0x0057d013`, stores the returned scrollbar at `this + 0x100`, and activates it through `0x0055f5f0`.
- `callers 0x0055f450` reports only the `NewSpellInventoryPane` constructor callsite, supporting this file as a feature-specific spell-inventory companion rather than a generic scrollbar module.
- `lookup_funcs` confirms modeled functions through `0x00560710-0x0056089d`; `0x005608a0` remains raw method-shaped reset code ending before `0x005608fc` and padding, with the next neighboring scroll-pane constructor at `0x00560900`.
- `xrefs_to` and vtable dword review confirm constructor stores to `0x00623e94`, `0x00623ee0`, and `0x00623f10`, with paint/mouse/repeat slots pointing back into this file's method family.

## 2026-06-14 IDA Refresh

- `lookup_funcs` reconfirms the full modeled method run: constructor `0x0055f450` size `0xa1`, setup helpers at `0x0055f560`, `0x0055f5c0`, `0x0055f5f0`, mouse/repeat helper `0x0055f650`, paint/control helpers through `0x00560290`, drag updater `0x00560710` size `0x18d`, raw reset helper `0x005608a0` still not a function, successor scroll-pane constructor `0x00560900` size `0xa1`, and `NewSpellInventoryPane` constructor `0x0057cf70` size `0xcf`.
- `xrefs_to` reconfirms `0x0055f450` has the single constructor call at `0x0057d013`, `0x00560710` is called from `0x005606ab` and `0x005606d4` inside the mouse/repeat path, and `0x005608a0` has no direct xrefs. Vtable base refs at `0x00623e94`, `0x00623ee0`, and `0x00623f10` still point back to constructor stores at `0x0055f4a1`, `0x0055f4a7`, and `0x0055f4b1`.
- Disassembly of `0x0057cf70` reconfirms `push 110h` before allocation, NewSpellInventoryPane vtable stores, `call sub_55F450` at `0x0057d013`, storage of the returned scrollbar at `this + 0x100`, and activation through `call sub_55F5F0`; `int_convert` verifies `0x110` as `272`.
- `callees` confirms the constructor only calls base pane/setup helpers, the paint and drag/update paths call shared UI/render helpers plus `0x00560290`/`0x00560710`, and `0x0057cf70` calls only `0x00545090`, `0x004f4aa0`, the ScrollSpell constructor, and activation. This keeps the file confidently feature-specific while preserving the standalone-vs-folded source caveat.

## 2026-06-18 B002 Reset Helper Route

[UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md) is rerouted from direct file ownership to direct class ownership [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md). This file remains the generated source route for that class. B002 confirmed the raw helper has exact boundary bytes, no direct caller, no VA/RVA literal, no external direct branch into the span, no pointer-table route, and no vtable slot, while its body and helper dependencies strongly support `ScrollSpellInventoryPane::ResetScrollState()` with `m_hoverPart`, `m_activePart`, the `+0xa4` TimerHandler view, `GetPartRect`, and Pane invalidation. The possible fold into [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) is retained as historical source-organization evidence but rejected for current reconstruction; it is not a direct method-ownership or source-route blocker.

## 2026-06-20 B002 Aggregate Route Refresh

[UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md) is still the file's broad executable island for the class, but it should not emit a monolithic `ScrollSpellInventoryPane.cpp` body. B002's local PE/listing pass confirmed the accepted `0x0055f450-0x005608fc` range, predecessor padding `0x0055f44f-0x0055f450`, internal padding around each modeled/raw method, successor padding `0x005608fc-0x00560900`, and the method-shaped raw setter/disable/predicate/hover/active/reset pockets. The aggregate stays directly owned by [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) with this file as the source route; exact method-body C++ should be added only after child pages are created for the source-bearing pockets or after existing exact children such as [UID:0001GN][0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag](by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md) clear a focused C++ pass.

Standalone placement is selected over direct ownership by [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md), because constructor-only use proves a private companion relationship but not ownership of the `ScrollSpellInventoryPane` fields, vtables, and helper bodies. The `NewSpellInventoryPane.cpp` fold remains a labeled rejected historical alternative.

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
- 2026-06-11 A005 parent-gate refresh:
  - Before: completion/confidence were `84/80`, which left the direct class parent chain below the strict 85/85 gate for layout assignment.
  - Changed to: completion `85`, confidence `85`; retained `NexusTK/ui/inventory/` as the proposed reconstruction path and kept the standalone-vs-folded source caveat.
  - Evidence: live IDA MCP reconfirmed the sole constructor caller in `NewSpellInventoryPane`, the `272`-byte allocation, method boundaries through the drag updater, raw reset-helper boundary before `0x00560900`, and the three spell-scrollbar vtable stores/slots.
- 2026-06-14 C001 Goal2 score refresh:
  - Before: score `85/85`.
  - Changed to: score `86/88`.
  - Summary/evidence: live IDA MCP reconfirmed the modeled method run, raw reset-helper non-function status, sole constructor callsite, vtable-base refs, `0x110` allocation and scrollbar storage in `NewSpellInventoryPane`, and callee separation between feature-specific scrollbar logic and shared render/control helpers. No owner/emitter routing changed; the private-file versus folded-source question and raw reset helper remain the blockers to a higher score.
- 2026-06-18 B002 support incorporation:
  - Updated the reset-helper proposed contents row, generated-source path note, and source-route section for [UID:0001GO][0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw](by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md).
  - Evidence: B002 resolved direct class ownership, field/helper names, no-route evidence, and first-draft child C++ while keeping this file as the route and preserving the standalone-versus-folded source caveat.
- 2026-06-20 B002 aggregate support incorporation:
  - Expanded Proposed Contents to include raw setter/disable/predicate pockets, the false-return input/event virtual, hit-test helper, raw hover/active helpers, and the input drag bridge.
  - Evidence: B002 confirmed exact local PE/listing boundaries, padding, no static route for representative raw starts with positive controls, direct class ownership for [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md), and aggregate no-code policy. This file remains the route, not the direct owner of class method bodies.
- 2026-07-22 B001 UID0001GN implementation callback:
  - Retained `86/88` and `NexusTK/ui/inventory/`, selected standalone `ScrollSpellInventoryPane.cpp`, and documented exact emission order: class/aggregate/layout/vtable support at `10/10/20/30`, `UpdateFromDrag` at `80`, and `ResetScrollState` at `90`.
  - Preserved the constructor-only NewSpell relationship and former fold hypothesis as historical/rejected evidence while resolving the current source route through [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) and this file.
