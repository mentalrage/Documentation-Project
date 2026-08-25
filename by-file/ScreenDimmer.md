*** UID:0000NA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ScreenDimmer

## UID00029O Status-Layer Dependency - 2026-07-21

This source file retains the complete ScreenDimmer and related peer inventory. ScreenDimmer's three attachment expressions and ScreenFadeOut's bounded status-layer consumer use independent `g_pStatusPaneLayer`; MainUiGraph.cpp owns its sole definition. EPF/legacy branches, modal/event facets, resources, ScreenFadeOut behavior, teardown, scalar wrappers, and generated order remain unchanged.

## Status

- Confidence: very strong for direct `ScreenDimmer` class behavior, singleton/factory ownership, UI-core placement, source ordering, and the ScreenFadeOut peer split; exact original header organization and helper lexemes remain inferred.
- Proposed module: `NexusTK/ui/core/ScreenDimmer.cpp`, with verify-only UID00036Q `ScreenFadeOut` (`by-file/ScreenFadeOut.md`) as a neighboring peer source file.
- Proposed header: `ui/core/ScreenDimmer.h`.
- Current reconstruction root: `auto-generated/NexusTK/ui/core/ScreenDimmer.cpp`; legacy `simroot_v2` paths are historical source hints only.
- Main address docs: [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md).

## File Role

This source file owns the generic full-screen modal dimmer overlay, its direct `Pane, Singleton<ScreenDimmer>` declaration, source-authored methods, typed singleton definition, exact storage coverage marker, and factory/helper family. The dimmer is a generic UI pane helper, not a map-specific effect class and not the same runtime effecter family as [UID:0000IZ][Effects](by-file/Effects.md).

`ScreenDimmer` installs a modal pane over an existing back pane or parent pane and paints a palette-index based dim overlay. Verify-only UID00036Q `ScreenFadeOut` (`by-file/ScreenFadeOut.md`) is the adjacent pane-derived fade transition class with timer/fade fields; B001-044 split it to a peer `ui/core/ScreenFadeOut.cpp` file root because the `ScreenDimmer` singleton/factory ownership evidence does not touch the fade class. [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md) is a map-specific subclass/companion that adds timer-driven teardown, so it should stay near map transition code while depending on this generic dimmer behavior.

## Proposed Contents

| Entity | Current source | Address evidence | Role |
| --- | --- | --- | --- |
| `ScreenDimmer` | `class_ScreenDimmer.cpp` | `0x00559b90-0x0055a173` sparse method island | Modal dim overlay pane and `g_pScreenDimmer` singleton owner. |
| `CreateScreenDimmer` / recovered alias `CreateScreenDimmer_4A12B0` | `recovered/CreateScreenDimmer_004A12B0.cpp` | [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md) | Allocates `0xfc` / 252 bytes (Verified with int_convert.py) and constructs a level-5 `ScreenDimmer` on the active UI host. |
| `ReleaseScreenDimmer` / `DestroyScreenDimmer` | not emitted as an exact child yet | `0x004a1360-0x004a1371` inside the physical DialogSession island | Free helper over `g_pScreenDimmer`; ignores `this`, calls the dimmer deleting destructor when the global is present, and is paired with the active predicate across dialog/menu/session callers. |
| `IsScreenDimmerActive` / `HasScreenDimmer` | not emitted as an exact child yet | `0x004a1380-0x004a138b` inside the physical DialogSession island | Tiny project predicate over `g_pScreenDimmer`; B002 rejects the old `unknown_libname_11`/runtime-library label because raw bytes and 24 direct callers prove a source helper. |
| `g_pScreenDimmer` | generated global-data reference | `0x0069ae08` by metadata | Current singleton pointer cleared by dimmer teardown. |
| `ScreenDimmerSingletonClear` / constructor unwind clear target | non-emitting cleanup support; no generated source marker should be retained after emitter clearing | [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) | ScreenDimmer constructor EH cleanup/funclet target that clears `g_pScreenDimmer`; MCP session `43ccf853` proves the unique 11-byte `c7 05 08 ae 69 00 00 00 00 00 c3` body, one cleanup xref at `0x006074a1`, no callees, no ordinary callers, no raw pointer/vtable route, and non-reconstructable/non-emitting disposition. |

## Current Reconstruction Route And Order

| Position | UID | Source entity | Emission disposition |
| --- | --- | --- | --- |
| `10` | [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md) | Complete closed `class ScreenDimmer : public Pane, public Singleton<ScreenDimmer>` declaration with typed singleton extern and `[[CHILDREN]]`. | Emits once. |
| `40` (class-child scope) | [UID:000392][0x00559b90-0x00559ce6.ScreenDimmerConstructor](by-memory/0x00559b90-0x00559ce6.ScreenDimmerConstructor.md) | Source-authored `ScreenDimmer(unsigned char, Pane *)` with exact EPF/current and legacy branches. | Emits once at the class `[[CHILDREN]]` marker. |
| `20` | [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md) | `ScreenDimmer *g_pScreenDimmer = NULL;` | Sole external-linkage definition. |
| `30` | [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) | Exact zero-filled linker storage evidence. | Comment-only covered-storage marker; no duplicate definition. |

The metadata positions are scoped by emitter level, not flattened across the whole file. UID0000C8 emits first at file position `10`; UID000392 is then inserted at that class block's `[[CHILDREN]]` marker using class-child position `40`; file-level UID0000S5 and UID00029D follow at positions `20` and `30`. Final generated line order is therefore class declaration, constructor definition, singleton definition, storage marker.

- UID0003H8 remains exact non-emitting declaration/layout support owned by UID0000C8. UID0001GB and UID0003EF remain compiler-generated/non-emitting support; no empty marker or handwritten body is appropriate for either.
- The class route includes the virtual ordinary destructor and virtual `OnPaint` as existing siblings. Scalar deleting destructors, adjustor thunks, vtable arrays, RTTI, Singleton publish/clear lowering, SEH/FuncInfo, security cookies, receiver adjustments, and return-this mechanics remain compiler output.
- `g_useEpfAssets`, `g_pScreenPane`, `g_pStatusPaneLayer`, `g_pEventDispatcher`, and inherited Pane helpers are dependencies, not additional contents or owners of this file. The older aggregate spelling is superseded history.
- Generated output should contain one class declaration, one UID000392 constructor definition, one typed singleton definition, one exact storage marker, and no target/class/global/storage Empty Emitter Marker or duplicate compiler body.

## Ownership Reasoning

- `ScreenDimmer` and verify-only UID00036Q `ScreenFadeOut` (`by-file/ScreenFadeOut.md`) are adjacent in memory immediately before the [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md). The boundary is now split as padding at `0x0055a252-0x0055a260` followed by ScreenEffecter tiny stubs at `0x0055a260`.
- Direct `ScreenDimmer` ownership is limited to the dimmer lifecycle: the `ScreenDimmer` constructor, destructor, scalar deleting destructor, non-emitting singleton cleanup target, exact `.data` singleton storage, and factory wrapper all point back to this file page, while no caller-local dialog/menu or map-specific page owns the dimmer lifecycle.
- Both overlay classes inherit or embed `Pane` at offset `0` and install three vtable/interface pointers around offsets `0`, `0xa0`, and `0xa4`; after B001-044, treat that as shared UI-core adjacency, not proof that this file owns the fade class.
- Both operate on root/back pane globals and pane-list/modal-list services, not on asset-library state.
- `CreateScreenDimmer_4A12B0` is a one-off free helper whose only visible job is to allocate and construct `ScreenDimmer`; it should migrate with this source family rather than remain a generic recovered global.
- `0x004a1360` and `0x004a1380` are paired free helpers over `g_pScreenDimmer`, not `DialogSession` methods despite their physical placement near DialogSession stack code. B002's 2026-06-19 call scan found 24 direct calls to each helper, usually testing the predicate before releasing the current dimmer.
- `MapRefreshDimmer` calls into `ScreenDimmer` behavior but adds map-specific timer ownership, so it should remain under `map/` unless later caller evidence proves a generic transition subsystem.

## Assignment-Gate Refresh

This file page is `91/92` and directly owns the accepted ScreenDimmer class/global/source route. [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md), [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md), and [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) route here. It is not the direct parent for [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md); B001-044 assigns that class to verify-only peer UID00036Q `ScreenFadeOut` (`by-file/ScreenFadeOut.md`).

Supporting evidence:

- [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) documents the exact zero-filled `0x0069ae08-0x0069ae0c` singleton slot at `92/94`, 40 refs, source-declared/generated-binary handling, and a nonduplicating storage marker.
- [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md) records the singleton lifecycle writes and clears through the constructor, destructor, scalar deleting destructor, and [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) constructor EH cleanup/funclet clear target.
- [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) and [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md) document the factory wrapper that allocates `0xfc` bytes and constructs a level-5 `ScreenDimmer`.
- 2026-06-17 B002 source-quality audit recommends `ScreenDimmer *CreateScreenDimmer(void)` as the source-facing helper spelling while retaining `CreateScreenDimmer_4A12B0` as the recovered alias. The helper remains owned/emitted through this file; caller-specific Board/Mail/Dialog flows are consumers only.
- 2026-06-20 B002 DialogSession source-quality incorporation extends the same ownership decision to the successor helper pair: `0x004a1360` is best treated as `ReleaseScreenDimmer()` / `DestroyScreenDimmer()`, and `0x004a1380` as `IsScreenDimmerActive()` / `HasScreenDimmer()`. Both operate only on [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md), so they are ScreenDimmer/global support even though exact child pages have not been split yet.
- [UID:0003H8][ScreenDimmerLayout](by-type/by-struct/ScreenDimmerLayout.md) records the exact `0xfc` object size, inherited facets, direct Singleton EBO at `+0xf8`, overlapping dim-level byte, and non-emitting direct class ownership. [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md) remains the mixed cross-file layout index rather than sole `ScreenDimmer.cpp` evidence.
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md) covers the executable overlay island and remains parentless because it is a non-emitting mixed index spanning both `ScreenDimmer` and peer `ScreenFadeOut`; exact `ScreenDimmer` children still route through this file/class path.

## Changes

- 2026-07-14 B004 UID000392 source-quality callback:
  - Raised `87/86` to `91/92` while retaining `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/"` and `CANONICAL_OWNER:FILE`.
  - Added the complete class/global/storage/constructor route and positions `10/20/30/40`, direct Pane/Singleton class shape, implicit singleton lifecycle, exact generated expectations, and compiler-only exclusions.
  - Preserved the factory and DialogSession-island helper inventory, historical evidence, ScreenFadeOut peer split, MapRefreshDimmer/Effects rejection, and mixed aggregate disposition without inflating sibling scores or adding compiler bodies.

- 2026-07-07 B004 UID0001GB source-quality implementation: updated the `ScreenDimmerSingletonClear` route to non-emitting constructor EH cleanup/funclet support rather than a source-authored local helper. The canonical owner remains this ScreenDimmer file, but UID0001GB now has blank emitter state and should not leave an empty marker in generated `ScreenDimmer.cpp`.

- 2026-06-12 A004 Batch303 layout split:
  - Score unchanged at `87/86`; updated layout references to exact [UID:0003H8][ScreenDimmerLayout](by-type/by-struct/ScreenDimmerLayout.md) while preserving [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md) as a mixed non-emitting index.
  - Evidence: A004 live IDA MCP reconfirmed the `ScreenDimmer` constructor/destructor/deleting-destructor vtable stores and the `0xfc` / 252-byte object size.

- 2026-06-20 B002 DialogSession helper ownership sync:
  - Score unchanged.
  - Summary/evidence: added `ReleaseScreenDimmer`/`DestroyScreenDimmer` at `0x004a1360` and `IsScreenDimmerActive`/`HasScreenDimmer` at `0x004a1380` as ScreenDimmer/global helper candidates, based on raw bytes, 24 direct calls to each helper, and exclusive use of `g_pScreenDimmer`.

- 2026-06-12 Agent-C001 Batch C001-012:
  - Score unchanged at `87/86`; corrected the [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md) assignment-gate note after C001 reclassified that broad executable island as a non-emitting mixed index.
  - Evidence: C001 live IDA MCP reconfirmed the `ScreenDimmer` constructor xrefs and the `ScreenFadeOut` peer/successor split; the aggregate remains parentless because it spans two source roots, not because `ScreenDimmer` ownership is weak.

- 2026-06-11 B001-044: Narrowed this file page from the provisional generic dim/fade owner to direct `ScreenDimmer` ownership, with verify-only UID00036Q `ScreenFadeOut` (`by-file/ScreenFadeOut.md`) as the peer file root.
  - Before: the page listed `ScreenFadeOut` in proposed contents and left the source split open.
  - After: proposed contents now cover `ScreenDimmer`, `CreateScreenDimmer_4A12B0`, `g_pScreenDimmer`, and the non-emitting `ScreenDimmerSingletonClear` constructor cleanup target; [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md) is routed through verify-only UID00036Q `ScreenFadeOut` (`by-file/ScreenFadeOut.md`).
  - Evidence: B001-044 live IDA MCP confirmed the fade class has its own RTTI/COL/vtable family and class-local method set, while `ScreenDimmer` singleton/factory refs stay in the dimmer lifecycle and do not touch the fade class.

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

- `class_ScreenDimmer.meta_wave3` imports from `ScreenDimmer.cpp`, reports a `0xfc` / 252-byte layout (Verified with int_convert.py), and records 14 constructor callers spanning map loading, dialogs, alerts, and reconnect flows.
- `class_ScreenFadeOut.meta_wave3` imports from `ScreenFadeOut.cpp`, reports a `0x10c` / 268-byte layout (Verified with int_convert.py), and records fade fields at `0xf8`, `0xfc`, `0x100`, `0x104`, and `0x108`; B001-044 now treats that as historical supporting evidence for the verify-only peer UID00036Q `ScreenFadeOut` (`by-file/ScreenFadeOut.md`) file root rather than as contents of this file.
- Live IDA MCP confirms the method island sizes, including the one-byte `ScreenFadeOut::OnPaint()` at `0x0055a020`; its primary-vtable `+0x44` slot parity with Pane and ScreenDimmer supersedes the historical `ScreenFadeOut::OnUpdate` identity. The same evidence confirms the non-emitting `0x0055a030` ScreenDimmer constructor EH cleanup target that clears `g_pScreenDimmer` and both adjustor thunks at `0x0055a051` and `0x0055a05c`.
- Live IDA MCP confirms `CreateScreenDimmer_4A12B0` at `0x004a12b0-0x004a1360` allocates `0xfc` bytes and calls the `ScreenDimmer` constructor with dim level `5`.
- 2026-05-26 recheck using current `simroot_v2` and IDA MCP only: the factory is still emitted as standalone `recovered/CreateScreenDimmer_004A12B0.cpp`; `class_ScreenDimmer.cpp` still omits the `0x0055a030` singleton clear body; and `class_ScreenFadeOut.cpp` still omits the `0x0055a051`/`0x0055a05c` adjustor thunks. B004 later resolved UID0001GB as non-reconstructable constructor cleanup support, so the omission is expected after emitter clearing.

## Migration Guidance

- Prefer `ui/core/ScreenDimmer.cpp` for `ScreenDimmer`, `g_pScreenDimmer`, and `CreateScreenDimmer_4A12B0`.
- Keep verify-only UID00036Q `ScreenFadeOut` (`by-file/ScreenFadeOut.md`) in neighboring `ui/core/ScreenFadeOut.cpp`; do not merge it into this file or into `render/Effects.cpp` unless later source-name evidence contradicts the B001-044 split.
- Keep [UID:0000IZ][Effects](by-file/Effects.md) focused on `ScreenEffecter`, overlay/filter/pixel effecters, and map render effects beginning at `0x0055a260`.
- Preserve data caveats for the disabled `0x0055a051` thunk and the `0x0055a020` zero-length metadata range before any automatic migration.
- Treat `g_pScreenDimmer` and `dword_69AE08` as the same storage family until generated global-data ownership is normalized; do not create a duplicate global-data record for the alias.

## Cross-References

- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)
- [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md)
- UID00036Q verify-only `ScreenFadeOut` at `by-file/ScreenFadeOut.md`
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md)
- [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md)
- [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md)
- [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md)
- [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md)
- [UID:0003H8][ScreenDimmerLayout](by-type/by-struct/ScreenDimmerLayout.md)
- [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md)
- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
