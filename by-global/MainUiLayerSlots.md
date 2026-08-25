*** UID:0000T6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MainUiGraph.h"

MainUiLayerSlots g_mainUiLayerSlots = { NULL, NULL, NULL };
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_MAINUIGRAPH_H
#define NEXUSTK_UI_MAINUIGRAPH_H

class Layer;

struct MainUiLayerSlots
{
    Layer *effectPaneLayerContext;
    Layer *rootPaneLayerContext;
    Layer *overlayPaneLayerContext;
};

extern MainUiLayerSlots g_mainUiLayerSlots;

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Main UI Layer Slots

## 2026-08-14 B003 Formal Graph Closure

- The head triplet now has one exact guarded H declaration and one source-era zero-initialized CPP definition. Field order is effect, root, overlay; ChangePasswordDialogPane consumes `overlayPaneLayerContext` during OnCreate.
- Independent layout/status/IME globals and the no-reference gap remain outside this struct and unchanged. UID0000T6 advances from `86/90` to `90/92` with UID0000L1 as the sole emitter.

## Layer Client Synchronization - 2026-07-14

Runtime startup constructs six eight-byte [UID:000073][Layer](by-class/Layer.md) objects through [UID:0004NR][0x004f0480-0x004f0597.LayerConstructor](by-memory/0x004f0480-0x004f0597.LayerConstructor.md), then registers them with ScreenPane. Source declaration shape is not one six-field object: UID0000T6 retains only the contiguous head triplet at `0x0069b364/368/36c`; independent [UID:0004VE][g_pLayoutPaneLayer](by-global/g_pLayoutPaneLayer.md), [UID:0004VF][g_pStatusPaneLayer](by-global/g_pStatusPaneLayer.md), and [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md) occupy `0x0069b374/378/37c` after a no-reference gap. Runtime call/store order remains root `0x004f6227 -> 0x0069b368`, effect `0x004f6256 -> 0x0069b364`, overlay `0x004f6285 -> 0x0069b36c`, layout `0x004f62b4 -> 0x0069b374`, status `0x004f62e3 -> 0x0069b378`, and IME `0x004f6312 -> 0x0069b37c`; registrations follow at `0x004f6331/6340/634f/635e/636d/637c`.

UID0000T6 owns only the provisional head declarations and does not own Layer source. Its score, owner/emitter route, and blank formal remain unchanged. The independent tail globals have complete semantic pages and sole definitions in MainUiGraph.cpp.

## Status

- Confidence: strong for the head-triplet lifecycle, storage, consumers, and boundaries; the final head declaration shape remains provisional. Layout/status/IME global-vs-field shape is resolved independently and is no longer a cap on this page.
- Symbol kind: provisional head-triplet global support family.
- Proposed owner: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) / UI layer infrastructure.
- Key backing storage: `dword_69B364` at `0x0069b364`, formerly tracked under stale alias [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md).
- Rebuild handling: source-declared head-triplet support with blank formal until its own names/object shape clear the code gate. Do not absorb the independent layout/status/IME definitions.

## Summary

The main UI bootstrap allocates six eight-byte Layer objects, stores their pointers in source-declared globals, uses those pointers as pane initialization arguments, and releases them during UI shutdown. The first three pointers form this provisional head family. The last three are independently declared `g_pLayoutPaneLayer`, `g_pStatusPaneLayer`, and `g_pIMEPaneLayer`; they are not fields of a single six-member aggregate and are not runtime screen-effecter-owned globals.

The six runtime pointers span three exact backing pages because the surrounding `.data` block includes an unreferenced zero-fill gap. The accepted source-facing names are `rootPaneLayerContext`, `effectPaneLayerContext`, and `overlayPaneLayerContext` for the provisional head triplet, followed by the independent globals `g_pLayoutPaneLayer`, `g_pStatusPaneLayer`, and `g_pIMEPaneLayer`. The final declaration shape and exact original spelling of only the head triplet remain this family's audit cap.

| Backing page | Active main UI layer slots covered |
| --- | --- |
| [UID:00029M][0x0069b364-0x0069b370.MainUiLayerSlotsHead](by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md) | `0x0069b364`, `0x0069b368`, and `0x0069b36c`, the head triplet after three feature singleton storage pages. |
| [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md) | Physical backing for independent [UID:0004VE][g_pLayoutPaneLayer](by-global/g_pLayoutPaneLayer.md), outside this head family. |
| [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md) | Split parent for physical [UID:0004VH][0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage](by-memory/0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage.md) and [UID:0004VI][0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage](by-memory/0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage.md), outside this head family. |

[UID:00029N][0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370](by-memory/0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370.md) is a separate loader-zero dword with no direct data xrefs or source body; do not count it as a seventh layer slot or bridge the head and independent globals into one aggregate.

## Observed Slots

| Storage | Startup write | Startup init | Shutdown release/clear | Notes |
| --- | --- | --- | --- | --- |
| `dword_69B364` / `0x0069b364` | `0x004f6268` | `0x004f6340` | `0x004f64ff`, `0x004f6594` | Inferred `effectPaneLayerContext`; stale alias [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md). Concrete effecter Pane registration paths, including SolidColor and Water filters, consume this slot but do not own it. |
| `dword_69B368` / `0x0069b368` | `0x004f6239` | `0x004f6331` | `0x004f6510`, `0x004f65ae` | Inferred `rootPaneLayerContext`; this is the first slot constructed/registered in [UID:0002H7][0x004f5fb0-0x004f6490.BaramAppStartup](by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md), before the lower-address effect slot. |
| `dword_69B36C` / `0x0069b36c` | `0x004f6297` | `0x004f634f` | `0x004f64ee`, `0x004f657a` | Inferred `overlayPaneLayerContext`; this name is already supported by LogoPane overlay consumer evidence. |
| `dword_69B374` / `0x0069b374` | `0x004f62c6` | `0x004f635e` | `0x004f64dd`, `0x004f65c8` | Independent [UID:0004VE][g_pLayoutPaneLayer](by-global/g_pLayoutPaneLayer.md); browser/alert/layout users are consumers. |
| `dword_69B378` / `0x0069b378` | `0x004f62f5` | `0x004f636d` | `0x004f64cc`, `0x004f6560` | Independent [UID:0004VF][g_pStatusPaneLayer](by-global/g_pStatusPaneLayer.md). |
| `dword_69B37C` / `0x0069b37c` | `0x004f632c` | `0x004f637c` | `0x004f6521`, `0x004f6546` | Independent [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md); FpsPane is one incidental consumer and does not own or rename it. |

## InitializeMainUiGraph Handoff

[UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) and [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) record the most specific pane-setup handoff counts for the first two head pointers: `dword_69B364` is pushed at 12 pane-setup sites and `dword_69B368` at 10. The accepted startup order is head `rootPaneLayerContext`, `effectPaneLayerContext`, and `overlayPaneLayerContext`, followed by independent `g_pLayoutPaneLayer`, `g_pStatusPaneLayer`, and `g_pIMEPaneLayer`; exact stores and registration calls remain `0x004f6239/6331`, `0x004f6268/6340`, `0x004f6297/634f`, `0x004f62c6/635e`, `0x004f62f5/636d`, and `0x004f632c/637c`.

## Alias Cleanup

- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) is a stale generated alias over `0x0069b364`; one effecter consumer does not make the storage render/effects-owned.
- [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md) is a generated browser-facing alias over `0x0069b374`; current source ownership is independent `g_pLayoutPaneLayer`, and browser code is only a consumer.
- Runtime has six Layer pointers, but source declaration ownership is a provisional head triplet plus three independent globals. Keep consumer-biased aliases in the ignored ledger and definitions under MainUiGraph.cpp.

## Evidence

- `0x004f5fb0` allocates and constructs the slot objects, then stores them into the adjacent globals.
- `0x004f6490` releases the same slots and clears each pointer.
- Live IDA MCP on 2026-06-04 confirms startup `sub_4F5FB0` as `0x004f5fb0-0x004f6490`, shutdown `sub_4F6490` as `0x004f6490-0x004f66a5`, and `InitializeMainUiGraph` as `sub_4F7D10` with size `0xe1b`.
- IDA MCP recheck on 2026-06-05 confirmed the same startup/shutdown boundaries, `_WinMain@16` lifecycle callers, and xrefs from the six slot globals back into `sub_4F5FB0` and `sub_4F6490`.
- `sub_4F5FB0` and `sub_4F6490` each have one live caller from `_WinMain@16` (`0x004f5e78` and `0x004f5e8e`), while `InitializeMainUiGraph` has one live caller at `0x004fac9b` in the login-success path.
- IDA decompilation of `sub_4F5FB0` shows six repeated `sub_4F4AA0(8)` allocation paths, each followed by `sub_4F0480`, storage into one of the `0x0069b36x/0x0069b37x` globals, and registration via `sub_556CE0(slot, 0)`.
- IDA decompilation of `sub_4F6490` shows the reverse lifecycle: each slot is passed through `sub_556D20` when `dword_67A7CC` is live, then vtable-released and cleared to zero.
- IDA xref counts remain broad and UI-oriented: `dword_69B368` has 60 refs across 36 functions, `dword_69B364` has 35 refs across 19 functions, `dword_69B36C` has 101 refs across 92 functions, `dword_69B374` has 13 refs across 8 functions, `dword_69B378` has 14 refs across 9 functions, and `dword_69B37C` has 11 refs across 6 functions.
- IDA reports no name and no xrefs for `0x0069b370`, supporting the six-slot model rather than an undocumented seventh slot between `dword_69B36C` and `dword_69B374`.
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) passes these globals into pane initialization virtual calls across both new and old UI layout branches.
- IDA xrefs to `0x0069b364` are broad and include `InitializeMainUiGraph`, root/UI panes, chat/browser/status/user panes, and effecter pane setup. [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) and [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) are concrete filter consumers, not owners.
- B013's 2026-06-19 [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) pass confirms the base `FilterEffecter : public ScreenEffecter, public Pane` constructor initializes inherited Pane geometry but does not attach to this slot. The slot is used by concrete subclasses after vtable replacement and effect-specific initialization, reinforcing the Main UI layer/context-slot model.
- Current PE inspection resolves the six pointers and `0x0069b370` as loader-zero storage. Older reports that described file-backed `0xffffffff` initializers are superseded historical assumptions. The 35/60/101/13/14/11 direct-ref split, startup writes/registration, shutdown detach/release/zero paths, and clean neighboring boundaries remain valid.
- [UID:0002H7][0x004f5fb0-0x004f6490.BaramAppStartup](by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md) and [UID:0002H8][0x004f6490-0x004f66a5.BaramAppShutdown](by-memory/0x004f6490-0x004f66a5.BaramAppShutdown.md) now both cross-reference the exact layer-slot pages, which confirms the startup/shutdown mirror and keeps this overview aligned with the app lifecycle methods.
- [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) consumes `0x0069b36c` at `0x004f5221` by pushing it into the retained `LogoPane::AttachStaticLogoSurface()` helper's attach virtual. This supports the accepted inferred role `g_mainUiLayerSlots.overlayPaneLayerContext`; exact original declaration spelling remains open because the same storage has broad UI-layer consumers.
- [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) consumes independent `g_pIMEPaneLayer` when showing the FPS overlay rectangle. This incidental reuse does not transfer ownership to FpsPane and does not justify a consumer-biased alias.

## Reconstruction Guidance

Keep this page blank-formal for the provisional head triplet only. Use the accepted head names in callers to avoid raw labels, but do not emit a final head aggregate until its original declaration shape clears the code gate. Emit the separately proven layout/status/IME globals through their own by-global pages and MainUiGraph.cpp; do not create a `ScreenEffecterList` class or attach `dword_69B364` to render/Effects.cpp.

## Cross-References

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0002H7][0x004f5fb0-0x004f6490.BaramAppStartup](by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md)
- [UID:0002H8][0x004f6490-0x004f66a5.BaramAppShutdown](by-memory/0x004f6490-0x004f66a5.BaramAppShutdown.md)
- [UID:00029M][0x0069b364-0x0069b370.MainUiLayerSlotsHead](by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md)
- [UID:00029N][0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370](by-memory/0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370.md)
- [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md)
- [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md)
- [UID:0004VE][g_pLayoutPaneLayer](by-global/g_pLayoutPaneLayer.md)
- [UID:0004VF][g_pStatusPaneLayer](by-global/g_pStatusPaneLayer.md)
- [UID:0004VG][g_pIMEPaneLayer](by-global/g_pIMEPaneLayer.md)
- [UID:0004VH][0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage](by-memory/0x0069b378-0x0069b37c.g_pStatusPaneLayerStorage.md)
- [UID:0004VI][0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage](by-memory/0x0069b37c-0x0069b380.g_pIMEPaneLayerStorage.md)
- [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0000IZ][Effects](by-file/Effects.md)

## Changes

- 2026-06-26 B007 ApplicationStartup slot-name sync:
  - Score unchanged at `86/90`; broad MainUiLayerSlots C++ remains blank.
  - Added accepted inferred source-facing field names used by [UID:0002H7][0x004f5fb0-0x004f6490.BaramAppStartup](by-memory/0x004f5fb0-0x004f6490.BaramAppStartup.md): `rootPaneLayerContext` (`0x0069b368`), `effectPaneLayerContext` (`0x0069b364`), `overlayPaneLayerContext` (`0x0069b36c`), `layoutPaneLayerContext` (`0x0069b374`), `statusPaneLayerContext` (`0x0069b378`), and `fpsOverlayLayerContext` (`0x0069b37c`).
  - Summary/evidence: B007 MCP session `80de0a67` reconfirmed six `0x08` / 8-byte Layer-style allocations (Verified with tools/int_convert.py), constructor `0x004f0480`, stores at `0x004f6239`, `0x004f6268`, `0x004f6297`, `0x004f62c6`, `0x004f62f5`, `0x004f632c`, and `ScreenPane::SetLayerFrame(slot, 0)` registrations at `0x004f6331`, `0x004f6340`, `0x004f634f`, `0x004f635e`, `0x004f636d`, `0x004f637c`. Exact original declarations remain a support cap.
- 2026-06-19 B013 FilterEffecter support incorporation:
  - Score unchanged at `86/90`.
  - Summary/evidence: reinforced `dword_69B364` as a Main UI layer/context slot consumed by concrete effecter Pane registration paths, not an Effects-owned list. The accepted FilterEffecter model keeps base construction separate from SolidColor/Water registration, preserving the stale-alias rejection for [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md).
- 2026-06-17 B003 FpsPane consumer sync:
  - Score unchanged.
  - Added the FpsPane `UpdateFpsLogSession` consumer for `dword_69B37C` and documented that FpsPane may use a descriptive dependency name while final slot naming remains a MainUiLayerSlots task.

- 2026-05-30: Grading changed from `0/0` to `72/82`.
  - Before: page documented the UI layer/context slot set, startup/shutdown writes, stale alias, and reconstruction guidance but remained unevaluated.
  - After: score reflects strong lifecycle/ownership evidence while preserving lower completion for unresolved final role names and object-vs-global modeling.
  - Evidence: startup `0x004f5fb0`, shutdown `0x004f6490`, `InitializeMainUiGraph`, and xrefs around `0x0069b364` tie the slots to UI graph setup rather than screen-effect ownership.

- 2026-06-04 live IDA refresh:
  - Before: the page had the correct ownership direction but lacked exact live function ranges, caller roots, per-slot xref counts, and the `0x0069b370` no-ref check.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:88`.
  - Summary/evidence: live IDA MCP confirmed startup/shutdown/initializer boundaries, `_WinMain@16` lifecycle callers, login-success initializer caller, six repeated 8-byte slot allocations and `sub_556CE0` registrations, mirrored `sub_556D20` release/clear logic, broad UI-oriented xref counts for all six slots, and no xrefs for `0x0069b370`. The score stays below reconstruction-ready because the original per-slot semantic names and object-vs-global modeling are still not proven.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md).
  - Reason: live IDA MCP recheck confirms this source-declared global slot set is constructed and destroyed by main UI lifecycle helpers and consumed by the main UI graph, not by a render/effecter owner.
- 2026-06-06: Raised completion/confidence from `82/88` to `86/90`.
  - Reason: integrated exact backing-page evidence for the first three slots, middle shared layout slot, tail pair, and ignored `0x0069b370` gap; documented stale alias handling for `g_pScreenEffecterList` and `g_pBrowserOverlayLayer`; linked startup/shutdown lifecycle pages; and added explicit rebuild guidance for source-declared storage with final C++ still blank.
  - Remaining cap: final per-slot semantic names and whether the original source declared these as globals or as fields behind a recovered graph/context object remain unresolved.
- 2026-06-17 B002 LogoPane consumer sync:
  - What changed: added the [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) consumer note for `0x0069b36c`.
  - Summary/evidence: B002 verified `0x004f5221` pushes the slot into the retained `LogoPane` attach helper. Score unchanged because this is another consumer confirmation, not final per-slot naming proof.
