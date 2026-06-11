*** UID:0000NA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ScreenDimmer

## Status

- Confidence: strong for `ScreenDimmer` class behavior and the shared overlay source family; medium for whether `ScreenFadeOut` was compiled from this exact source file or a neighboring `ScreenFadeOut.cpp`.
- Proposed module: `ui/core/ScreenDimmer.cpp`, with `ui/core/ScreenFadeOut.cpp` as a possible neighboring file if the original project kept fade transitions separate.
- Proposed headers: `ui/core/ScreenDimmer.h` and possibly `ui/core/ScreenFadeOut.h`.
- Current generated sources: `source-3/simroot_v2/class_ScreenDimmer.cpp`, `source-3/simroot_v2/class_ScreenFadeOut.cpp`, and `source-3/simroot_v2/recovered/CreateScreenDimmer_004A12B0.cpp`.
- Main address docs: [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md).

## File Role

This source family owns full-screen pane overlays used for modal dimming and transition fades. The classes are generic UI pane helpers, not map-specific effect classes and not the same runtime effecter family as [UID:0000IZ][Effects](by-file/Effects.md).

`ScreenDimmer` installs a modal pane over an existing back pane or parent pane and paints a palette-index based dim overlay. `ScreenFadeOut` is the adjacent pane-derived fade transition class with timer/fade fields. [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md) is a map-specific subclass/companion that adds timer-driven teardown, so it should stay near map transition code while depending on this generic overlay family.

## Proposed Contents

| Entity | Current source | Address evidence | Role |
| --- | --- | --- | --- |
| `ScreenDimmer` | `class_ScreenDimmer.cpp` | `0x00559b90-0x0055a173` sparse method island | Modal dim overlay pane and `g_pScreenDimmer` singleton owner. |
| `ScreenFadeOut` | `class_ScreenFadeOut.cpp` | `0x00559e50-0x0055a252` sparse method island | Pane overlay for fade-out transition timing and invalidation. |
| `CreateScreenDimmer_4A12B0` | `recovered/CreateScreenDimmer_004A12B0.cpp` | [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md) | Allocates 252 bytes and constructs a level-5 `ScreenDimmer` on the active UI host. |
| `g_pScreenDimmer` | generated global-data reference | `0x0069ae08` by metadata | Current singleton pointer cleared by dimmer teardown. |
| `ScreenDimmerSingletonClear` | not emitted in active class output | [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) | Tiny local helper that clears `g_pScreenDimmer`. |

## Ownership Reasoning

- `ScreenDimmer` and `ScreenFadeOut` are adjacent in memory immediately before the [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md). The boundary is now split as padding at `0x0055a252-0x0055a260` followed by ScreenEffecter tiny stubs at `0x0055a260`.
- The direct `ScreenDimmer` ownership is stronger than the broader fade/source-split question: the `ScreenDimmer` constructor, destructor, scalar deleting destructor, singleton clear helper, exact `.data` singleton storage, and factory wrapper all point back to this file page, while no caller-local dialog/menu or map-specific page owns the dimmer lifecycle.
- Both overlay classes inherit or embed `Pane` at offset `0` and install three vtable/interface pointers around offsets `0`, `0xa0`, and `0xa4`.
- Both operate on root/back pane globals and pane-list/modal-list services, not on asset-library state.
- `CreateScreenDimmer_4A12B0` is a one-off free helper whose only visible job is to allocate and construct `ScreenDimmer`; it should migrate with this source family rather than remain a generic recovered global.
- `MapRefreshDimmer` calls into `ScreenDimmer` behavior but adds map-specific timer ownership, so it should remain under `map/` unless later caller evidence proves a generic transition subsystem.

## Assignment-Gate Refresh

This file page now clears the corrected parent-side gate at `87/86` for direct `ScreenDimmer` children. The score increase is limited to the source-family root: it supports assigning [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md), [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md), and exact dimmer storage/helper children when those pages independently clear the child gate. It does not by itself prove that [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md) should be emitted into `ScreenDimmer.cpp`; the imported `ScreenFadeOut.cpp` hint remains an unresolved direct-parent question for that class.

Supporting evidence:

- [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) documents the exact `0x0069ae08-0x0069ae0c` singleton slot at `88/90` and attaches it to this source-file root.
- [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md) records the singleton lifecycle writes and clears through the constructor, destructor, scalar deleting destructor, and [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) clear helper.
- [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) and [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md) document the factory wrapper that allocates `0xfc` bytes and constructs a level-5 `ScreenDimmer`.
- [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md) records the overlay object sizes, vtable/interface offsets, dim-level field, fade fields, and vtable-table addresses with `88` confidence.
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md) covers the executable overlay island and keeps the aggregate unassigned only because its own completion is below `85`, not because the `ScreenDimmer` owner evidence is weak.

## Changes

- 2026-06-07: Batch 095 parent-gate refresh raised score from `86/80` to `87/86`.
  - Before: the page had enough `ScreenDimmer` behavior and source-family evidence for a plausible parent but remained below the corrected parent-side confidence gate.
  - After: the page distinguishes direct `ScreenDimmer` ownership from the unresolved `ScreenFadeOut.cpp` split, fixes the stale effecter boundary to `0x0055a260`, and clears the parent-side gate for direct `ScreenDimmer` children only.
  - Evidence: exact singleton storage [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md), singleton page [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md), factory page [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md), factory memory [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md), layout page [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md), and executable aggregate [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md) all agree on generic `ScreenDimmer` source ownership and reject `MapRefreshDimmer`, `Effects`, or caller-local ownership.

- 2026-06-05: Filled `PROPOSED_RECONSTRUCTION_PATH` with `NexusTK/ui/core/`.
  - Reason: `by-project-structure/proposed-source-tree.md` already places `ScreenDimmer.cpp` under UI core, and the linked IDA-backed ScreenDimmer/ScreenFadeOut and `CreateScreenDimmer_4A12B0` evidence supports this generic overlay source owner. This also makes the file root valid for child autogen attachment; completion/confidence scores were not changed.
- 2026-05-28: Updated the post-`ScreenFadeOut` boundary note.
  - Before: the next documented runtime effecter cluster began at `0x0055a2a0`.
  - After: IDA-backed coverage starts the effecter cluster at `0x0055a260`, with only `0x0055a252-0x0055a260` as padding after `ScreenFadeOut`.
  - Evidence: IDA MCP reports `0xcc` padding at `0x0055a252-0x0055a260` and real ScreenEffecter vtable/default code at `0x0055a260`, `0x0055a270`, `0x0055a280`, and `0x0055a290`.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers overlay/fade roles, proposed contents, singleton/factory ownership, IDA evidence, migration guidance, and cross-references; confidence remains capped by exact original file split between generic dimmer and fade transition code.
## Evidence Notes

- `class_ScreenDimmer.meta_wave3` imports from `ScreenDimmer.cpp`, reports a 252-byte layout, and records 14 constructor callers spanning map loading, dialogs, alerts, and reconnect flows.
- `class_ScreenFadeOut.meta_wave3` imports from `ScreenFadeOut.cpp`, reports a 268-byte layout, and records fade fields at `0xf8`, `0xfc`, `0x100`, `0x104`, and `0x108`.
- Live IDA MCP confirms the method island sizes, including one-byte `ScreenFadeOut::OnUpdate` at `0x0055a020`, the `0x0055a030` `g_pScreenDimmer` clear helper, and both adjustor thunks at `0x0055a051` and `0x0055a05c`.
- Live IDA MCP confirms `CreateScreenDimmer_4A12B0` at `0x004a12b0-0x004a1360` allocates `0xfc` bytes and calls the `ScreenDimmer` constructor with dim level `5`.
- 2026-05-26 recheck using current `simroot_v2` and IDA MCP only: the factory is still emitted as standalone `recovered/CreateScreenDimmer_004A12B0.cpp`; `class_ScreenDimmer.cpp` still omits the `0x0055a030` singleton clear helper; and `class_ScreenFadeOut.cpp` still omits the `0x0055a051`/`0x0055a05c` adjustor thunks.

## Migration Guidance

- Prefer `ui/core/ScreenDimmer.cpp` for `ScreenDimmer`, `g_pScreenDimmer`, and `CreateScreenDimmer_4A12B0`.
- Keep `ScreenFadeOut` either in the same small overlay module or in `ui/core/ScreenFadeOut.cpp`; do not merge it into `render/Effects.cpp` unless later source-name or caller evidence ties it to the effecter runtime module.
- Keep [UID:0000IZ][Effects](by-file/Effects.md) focused on `ScreenEffecter`, overlay/filter/pixel effecters, and map render effects beginning at `0x0055a260`.
- Preserve data caveats for the disabled `0x0055a051` thunk and the `0x0055a020` zero-length metadata range before any automatic migration.
- Treat `g_pScreenDimmer` and `dword_69AE08` as the same storage family until generated global-data ownership is normalized; do not create a duplicate global-data record for the alias.

## Cross-References

- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md)
- [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md)
- [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md)
- [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md)
- [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md)
- [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md)
- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
