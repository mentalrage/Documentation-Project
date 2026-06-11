*** UID:0000C8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenDimmer

## Status

- Confidence: strong for behavior and layout; medium for final source split.
- Likely source file: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- Address range: [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- Current generated file: `source-3/simroot_v2/class_ScreenDimmer.cpp`
- Imported source hint: `ScreenDimmer.cpp`

## Class Purpose

`ScreenDimmer` is a modal `Pane`-derived overlay that darkens the active screen using a fixed dim-level to palette-index mapping. It is used by dialog, loading, alert, reconnect, and map-transition paths that need the rest of the UI visually dimmed behind a modal operation.

The class owns the process singleton pointer [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md). Construction sets the singleton, attaches/registers the overlay pane, and adds its secondary interface at offset `0xa0` to the modal list. Destruction removes the modal-list entry, detaches/unregisters from the pane hierarchy, requests a repaint on the reconnect or main back pane, clears the singleton, and destroys the `Pane` base.

## Layout Notes

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x000` | primary `Pane`/`ScreenDimmer` vtable | IDA MCP confirms constructor/destructor paths install the primary `ScreenDimmer` table at object base. |
| `0x000-0x0f7` | inherited `Pane` / interface storage | IDA confirms the first derived `ScreenDimmer` field write at `0x0f8`; exact inherited tail names are still unresolved. |
| `0x0a0` | secondary vtable/interface | Constructor installs a second vtable; modal-list registration passes `this + 160`; adjustor thunk at `0x0055a03b` subtracts `0xa0`. |
| `0x0a4` | tertiary vtable/interface | Constructor installs a third vtable; adjustor thunk at `0x0055a046` subtracts `0xa4`. |
| `0x0f8` | byte `m_dimLevel` | Constructor stores the input dim level as a byte; `OnPaint` reads that byte and maps values `0` through `7` to palette indices. |
| `0x0f9-0x0fb` | padding or unresolved tail bytes | No confirmed project field writes in the current IDA pass; allocation size is `0xfc` bytes. |

Dim-level palette mapping in `OnPaint`: `0=143`, `1=142`, `2=140`, `3=132`, `4=130`, `5=128`, `6=12`, `7=11`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScreenDimmer(uint8_t dimLevel, Pane* parent)` | `0x00559b90-0x00559ce6` | Constructs the overlay, chooses EPF versus legacy parent attachment path, registers pane state, and adds modal entry. |
| `~ScreenDimmer` | `0x00559cf0-0x00559dc4` | Non-deleting destructor; removes modal entry, detaches pane, repaints back pane, clears singleton. |
| `OnPaint` | `0x00559dd0-0x00559e2d` | Applies dim-level palette index, clears dirty flag, and calls the process paint callback. |
| `ScreenDimmerSingletonClear` | [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) | Tiny un-emitted helper that clears `g_pScreenDimmer`. |
| `ScalarDeletingDestructor_vtable2_adjustor` | `0x0055a03b-0x0055a046` | Adjusts `this` from offset `0xa0` back to object base and forwards to scalar deleting destructor. |
| `ScalarDeletingDestructor_vtable3_adjustor` | `0x0055a046-0x0055a051` | Adjusts `this` from offset `0xa4` back to object base and forwards to scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x0055a070-0x0055a173` | Performs destructor body and conditionally frees heap storage. |

## Related Helpers

[UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) allocates 252 bytes and constructs a level-5 `ScreenDimmer` on the active UI host. Live IDA confirms its factory body at [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md). [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md) is the map-transition companion that builds on this dimmer behavior with timer-driven teardown.

2026-05-26 recheck: current generated output still leaves [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) as a recovered global and still omits `ScreenDimmerSingletonClear` from `class_ScreenDimmer.cpp`. IDA MCP still resolves the clear helper as `0x0055a030-0x0055a03b` and decompiles it to a direct `dword_69AE08 = 0`.

## Assignment Decision

Assigned to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md). The child page now clears the corrected `85/85` gate at `87/86`, and the direct file parent clears the parent-side gate at `87/86`. The ownership relationship is direct for `ScreenDimmer`: the constructor publishes [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md), the destructor and deleting-destructor paths clear it, [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) is a local clear helper, [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) records the exact singleton storage, and [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) is a factory wrapper that allocates and constructs this class. Final C++ remains blank because interface names, inherited `Pane` tail names, and full final-source shape have not passed the `95/95` gate.

## Open Questions

- Whether the original project kept `ScreenFadeOut` in the same `ScreenDimmer.cpp` source file or in a neighboring `ScreenFadeOut.cpp`.
- Whether `g_pScreenDimmer` was declared in the dimmer source or a broader UI globals file.
- Final names for the three vtable/interface roles at offsets `0`, `0xa0`, and `0xa4`.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md)
- [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md)
- [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md)
- [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md)
- [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md)

## Changes

- 2026-06-07: Batch 095 raised score from `86/82` to `87/86` and assigned the class to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md).
  - Before: The page documented the constructor/destructor/paint behavior and layout but remained below the corrected confidence gate, mainly because the direct file parent was also below confidence gate.
  - After: The page records direct parent ownership through singleton lifecycle, exact storage, factory, clear helper, and the refreshed `ScreenDimmer` source-file page; `AUTOGEN_PARENT_UID` is set to `0000NA`.
  - Evidence: [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) documents the exact singleton slot at `88/90`, [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md) records lifecycle writes/clears, [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) and [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md) prove the factory construction path, [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md) supports layout/vtable offsets, and [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) now clears the parent-side gate at `87/86`.

- 2026-05-30: Changed completion/confidence from `0/0` to `86/82`.
  - Before: The page was unevaluated despite detailed constructor/destructor/paint coverage, singleton handling, layout offsets, palette mapping, and helper/factory evidence.
  - After: Scored as high completion and strong confidence with remaining uncertainty around final source split and secondary/tertiary interface names.
  - Evidence: Existing layout notes, method notes, related helper notes, IDA recheck notes, singleton/global references, and overlay layout cross-references support the score.
- 2026-05-31: Marked reconstructable, corrected the `m_dimLevel` field width to byte-sized, and replaced generated `Pane`-size wording with IDA-backed inherited-storage wording.
  - Before: `m_dimLevel` was described without an explicit size, inherited storage relied on generated metadata, and the class was not flagged in validator metadata as reconstructable.
  - After: The layout records `m_dimLevel` as a byte at `0x0f8` with unresolved/padding bytes through `0x0fb`; inherited storage is bounded by the first confirmed derived write; `RECONSTRUCTABLE` is set to `TRUE`.
  - Evidence: IDA MCP decompilation of `0x00559b90` stores `a2` with `*(_BYTE *)(this + 248)`, and `0x00559dd0` reads `*(_BYTE *)(this + 248)` for the dim-level switch.
