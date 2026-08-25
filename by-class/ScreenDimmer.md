*** UID:0000C8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ScreenDimmer.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "Pane.h"
#include "../../util/Singleton.h"

class ScreenDimmer : public Pane, public Singleton<ScreenDimmer>
{
public:
    ScreenDimmer(unsigned char dimLevel, Pane *parentPane);
    virtual ~ScreenDimmer();

    virtual void OnPaint();

private:
    unsigned char m_dimLevel;
};

extern ScreenDimmer *g_pScreenDimmer;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScreenDimmer

## UID00029O Status-Layer Dependency - 2026-07-21

The constructor's EPF initial attach, optional parent reattach, and legacy attach all consume independent `g_pStatusPaneLayer`. All class inheritance/facets, modal registration, root/parent bounds order, pane-order behavior, resource branch, peer `ScreenFadeOut` inventory, destructor/vtable detail, and existing formal declarations remain unchanged. The old aggregate tail spelling is superseded history.

## Status

- Confidence: very strong for behavior, direct bases, layout, virtual surface, singleton lifecycle, and direct source split; exact original lexical names and header organization remain inferred.
- Likely source file: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- Address range: [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- Reconstruction route: [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) -> `NexusTK/ui/core/ScreenDimmer.cpp`, source position `10`.
- Direct source bases: `Pane` and `Singleton<ScreenDimmer>`.

## Class Purpose

`ScreenDimmer` is a modal overlay that directly derives from `Pane` and empty `Singleton<ScreenDimmer>`. It darkens the active screen using a fixed dim-level to palette-index mapping and is used by dialog, loading, alert, reconnect, and map-transition paths that need the rest of the UI visually dimmed behind a modal operation.

The class owns the process singleton pointer [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md). Direct Singleton-base construction publishes the complete object implicitly; the source constructor does not assign the global by hand. Construction attaches/registers the overlay pane and passes `this` to the modal list, with the inherited `EventHandler` conversion producing the binary `+0xa0` adjustment. Destruction removes the modal-list entry, detaches/unregisters from the pane hierarchy, requests a repaint on the reconnect or main back pane, and lets the Singleton base clear the pointer through ordinary/scalar/unwind compiler paths.

## Layout Notes

| Offset | Field | Evidence |
| --- | --- | --- |
| `0x000` | primary `Pane`/`ScreenDimmer` vtable | IDA MCP confirms constructor/destructor paths install the primary `ScreenDimmer` table at object base. |
| `0x000-0x0f7` | inherited `Pane`, including GrafPort/LOBject and interface storage | RTTI places GrafPort, LObject, EventHandler, and TimerHandler under Pane; the first derived source field is at `+0xf8`. |
| `0x0a0` | inherited `EventHandler` facet | Constructor modal registration passes `this + 160`; the adjustor thunk subtracts `0xa0`. This is inherited through Pane, not a direct ScreenDimmer field or base. |
| `0x0a4` | inherited `TimerHandler` facet | The related adjustor thunk subtracts `0xa4`; RTTI places TimerHandler under Pane rather than as a direct ScreenDimmer base. |
| `0x0f8` | direct empty `Singleton<ScreenDimmer>` base and byte `m_dimLevel` | The Singleton BCD at `0x0064b4ac` has `mdisp=0xf8`, `pdisp=-1`, `vdisp=0`, attributes `0x40`; MSVC EBO overlaps it with the one-byte source field. |
| `0x0f9-0x0fb` | 3 bytes natural tail padding | No project-owned field writes occur here; the complete allocation ends at `0xfc`. No explicit padding member belongs in source. |

Dim-level palette mapping in `OnPaint`: `0=143`, `1=142`, `2=140`, `3=132`, `4=130`, `5=128`, `6=12`, `7=11`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ScreenDimmer(unsigned char dimLevel, Pane *parentPane)` | `0x00559b90-0x00559ce6` | Constructs the overlay with `Pane(2)`, chooses the exact EPF/current versus legacy attachment path, registers pane state, and adds the inherited EventHandler view to the modal list. |
| `~ScreenDimmer` | `0x00559cf0-0x00559dc4` | Non-deleting destructor; removes modal entry, detaches pane, repaints back pane, clears singleton. |
| `OnPaint` | `0x00559dd0-0x00559e2d` | Applies dim-level palette index, clears dirty flag, and calls the process paint callback. |
| `ScreenDimmerSingletonClear` / constructor unwind clear target | [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) | Non-emitting constructor EH cleanup/funclet target that clears `g_pScreenDimmer`; not a source method because the body ignores `ecx`, has no member access, no vtable slot, no callees, no ordinary callers, and only the cleanup xref at `0x006074a1`. |
| `ScalarDeletingDestructor_vtable2_adjustor` | `0x0055a03b-0x0055a046` | Adjusts `this` from offset `0xa0` back to object base and forwards to scalar deleting destructor. |
| `ScalarDeletingDestructor_vtable3_adjustor` | `0x0055a046-0x0055a051` | Adjusts `this` from offset `0xa4` back to object base and forwards to scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x0055a070-0x0055a173` | Performs destructor body and conditionally frees heap storage. |

## Source Contract And Compiler Boundaries

- Live RTTI hierarchy data lists ScreenDimmer, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<ScreenDimmer>`. Source direct bases are only Pane and Singleton; the other facets arrive through Pane.
- The complete source declaration is owned here and closed before `[[CHILDREN]]`. UID0003H8 is non-emitting layout support so it cannot duplicate this class.
- Source surface is the constructor, virtual ordinary destructor, and virtual `OnPaint`; deleting-destructor wrappers and `+0xa0`/`+0xa4` adjustors are compiler-generated ABI support.
- Source declares one private `unsigned char m_dimLevel` and one typed `extern ScreenDimmer *g_pScreenDimmer`. The global definition belongs to UID0000S5.
- Explicit vptr stores, RTTI arrays, receiver adjustments, EBO padding/union members, singleton publish/clear calls, EH/FuncInfo, security cookies, deleting-destructor mechanics, and return-this lowering are intentionally absent from human C++.
- Rejected alternatives are a Pane-only base list, direct EventHandler/TimerHandler bases, raw offset fields, a handwritten `g_pScreenDimmer = this`, a duplicate clear helper, and a combined ScreenDimmer/ScreenFadeOut source owner.

## Related Helpers

[UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) allocates `0xfc` / 252 bytes (Verified with int_convert.py) and constructs a level-5 `ScreenDimmer` on the active UI host. Live IDA confirms its factory body at [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md). [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md) is the map-transition companion that builds on this dimmer behavior with timer-driven teardown.

B008's ForcedInformMessageDialog constructor incorporation accepts `SetDimmed(bool enabled)` as the source-facing singleton notification used around forced-inform modal setup. The exact final implementation still belongs with the ScreenDimmer/Pane overlay support pages; this class note only records the accepted call-site spelling needed by exact dialog constructor C++.

Historical 2026-05-26 recheck: generated output at that time left [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) as a recovered global and omitted `ScreenDimmerSingletonClear` from `class_ScreenDimmer.cpp`. B004 later resolved UID0001GB as non-reconstructable constructor cleanup support, so that omission remains expected after emitter clearing. MCP session `43ccf853`, when that later evidence was collected, resolved the range as `sub_55A030` at `0x0055a030-0x0055a03b`, decompiled it to `unk_69AE08 = 0`, and showed the only incoming code xref as the constructor cleanup jump at `0x006074a1`.

## Assignment Decision

Assigned directly to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md). The constructor, ordinary destructor, paint method, typed singleton, exact storage, factory, RTTI, and layout converge on this class/file route. [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) remains non-emitting constructor-unwind support, and [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) remains the factory wrapper. The former 95/95 blank-C++ gate is historical and superseded; the complete class is now implementation-ready at `92/94` while unrecovered lexical/header details cap it below `95`.

## Open Questions

- Source split resolved: `ScreenFadeOut` is a peer `NexusTK/ui/core/ScreenFadeOut.cpp` class/file, not contents of this class or file root.
- Global placement resolved: `g_pScreenDimmer` is declared by this class block and defined by UID0000S5 in `ScreenDimmer.cpp`; UID00029D is only exact linker-storage evidence.
- Interface roles resolved structurally: primary Pane view, inherited EventHandler facet at `+0xa0`, and inherited TimerHandler facet at `+0xa4`. Exact original lexical vtable labels are compiler symbols and not source blockers.

## Cross-References

- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0000CA][ScreenFadeOut](by-class/ScreenFadeOut.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md)
- [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md)
- [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md)
- [UID:0003H8][ScreenDimmerLayout](by-type/by-struct/ScreenDimmerLayout.md)
- [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md)
- [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md)

## 2026-08-11 UID0001CU Formal-Route Incorporation

- Metadata remains `92/94`; owner/emitter remain [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md), reconstructable remains true, position remains `10`, and `Nested:0` remains exact.
- The complete ScreenDimmer declaration and `g_pScreenDimmer` extern moved into the formal H channel. The formal CPP now includes `ScreenDimmer.h` and emits children.
- Direct Pane plus Singleton inheritance, constructor/destructor, paint override, dim-level field, and singleton pointer are preserved. UID0001CU only consumes the singleton during accepted-notification cleanup; it does not own dimmer implementation.

## Changes

- 2026-07-14 B004 UID000392 source-quality callback:
  - Raised `87/86` to `92/94`, retained owner/emitter UID0000NA, set source position `10`, and installed the complete closed class block before `[[CHILDREN]]`.
  - Added direct `Pane, Singleton<ScreenDimmer>` bases, inherited EventHandler/TimerHandler facets, exact `0xfc` layout, Singleton EBO and one-byte field overlap at `+0xf8`, constructor signature, typed singleton extern, implicit singleton lifecycle, source route, and compiler exclusions.
  - Preserved the existing destructor/paint/helper/factory and B008 `SetDimmed` support notes while superseding the historical blank-C++ and unresolved ScreenFadeOut/global-placement conclusions.

- 2026-07-07 B004 UID0001GB source-quality implementation:
  - Reclassified [UID:0001GB][0x0055a030-0x0055a03b.ScreenDimmerSingletonClear](by-memory/0x0055a030-0x0055a03b.ScreenDimmerSingletonClear.md) from a tiny helper/source-method note to non-emitting constructor EH cleanup/funclet support.
  - Evidence from MCP session `43ccf853` is the unique 11-byte global clear, sole cleanup jump at `0x006074a1`, ignored `ecx`, no member access, no callees, no ordinary callers, and no raw pointer/vtable route.

- 2026-06-07: Batch 095 raised score from `86/82` to `87/86` and assigned the class to [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md).
  - Before: The page documented the constructor/destructor/paint behavior and layout but remained below the corrected confidence gate, mainly because the direct file parent was also below confidence gate.
  - After: The page records direct parent ownership through singleton lifecycle, exact storage, factory, UID0001GB cleanup support, and the refreshed `ScreenDimmer` source-file page; `AUTOGEN_PARENT_UID` is set to `0000NA`.
  - Evidence: [UID:00029D][0x0069ae08-0x0069ae0c.g_pScreenDimmer](by-memory/0x0069ae08-0x0069ae0c.g_pScreenDimmer.md) documents the exact singleton slot at `88/90`, [UID:0000S5][g_pScreenDimmer](by-global/g_pScreenDimmer.md) records lifecycle writes/clears, [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) and [UID:000133][0x004a12b0-0x004a1360.CreateScreenDimmerFactory](by-memory/0x004a12b0-0x004a1360.CreateScreenDimmerFactory.md) prove the factory construction path, [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md) supports layout/vtable offsets, and [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) now clears the parent-side gate at `87/86`.

- 2026-06-12 A004 Batch303 layout split:
  - Score unchanged at `87/86`; added [UID:0003H8][ScreenDimmerLayout](by-type/by-struct/ScreenDimmerLayout.md) as the exact class-local layout child split from mixed [UID:0001VY][ScreenOverlayPaneLayouts](by-type/by-struct/ScreenOverlayPaneLayouts.md).
  - Evidence: A004 live IDA MCP reconfirmed constructor writes at object base, `+0xa0`, `+0xa4`, and `+0xf8`, vtable restore refs from constructor/destructor/deleting destructor, and the `0xfc` / 252-byte size.

- 2026-05-30: Changed completion/confidence from `0/0` to `86/82`.
  - Before: The page was unevaluated despite detailed constructor/destructor/paint coverage, singleton handling, layout offsets, palette mapping, and helper/factory evidence.
  - After: Scored as high completion and strong confidence with remaining uncertainty around final source split and secondary/tertiary interface names.
  - Evidence: Existing layout notes, method notes, related helper notes, IDA recheck notes, singleton/global references, and overlay layout cross-references support the score.
- 2026-05-31: Marked reconstructable, corrected the `m_dimLevel` field width to byte-sized, and replaced generated `Pane`-size wording with IDA-backed inherited-storage wording.
  - Before: `m_dimLevel` was described without an explicit size, inherited storage relied on generated metadata, and the class was not flagged in validator metadata as reconstructable.
  - After: The layout records `m_dimLevel` as a byte at `0x0f8` with unresolved/padding bytes through `0x0fb`; inherited storage is bounded by the first confirmed derived write; `RECONSTRUCTABLE` is set to `TRUE`.
  - Evidence: IDA MCP decompilation of `0x00559b90` stores `a2` with `*(_BYTE *)(this + 248)`, and `0x00559dd0` reads `*(_BYTE *)(this + 248)` for the dim-level switch.
- 2026-06-28 B008 ForcedInformMessageDialog support sync:
  - Score unchanged at `87/86`.
  - Added the accepted `SetDimmed(bool enabled)` source-facing call-site alias used by the exact ForcedInformMessageDialog constructor child; no ownership, emitter, or formal-C++ metadata changed.
