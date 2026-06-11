*** UID:0000T6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Main UI Layer Slots

## Status

- Confidence: strong for lifecycle, storage set, split backing ranges, ignored-alias cleanup, and broad UI-layer role; medium-high for final per-slot role names and whether the source modeled them as globals or fields of a graph/context object.
- Symbol kind: global pointer set.
- Proposed owner: [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) / UI layer infrastructure.
- Key backing storage: `dword_69B364` at `0x0069b364`, formerly tracked under stale alias [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md).
- Rebuild handling: source-declared layer/context pointer storage. Preserve exact addresses as binary-layout evidence; reconstruct source declarations under the main UI graph owner only after final names and object-vs-global modeling are proven.

## Summary

The main UI bootstrap allocates a small set of eight-byte layer/context objects, stores them in adjacent globals, uses them as pane initialization arguments, and releases them during UI shutdown. These are not runtime screen-effecter-owned globals.

The six active slots are split across three exact backing pages because the surrounding `.data` block contains unrelated singleton pointers and a reviewed unused gap:

| Backing page | Active main UI layer slots covered |
| --- | --- |
| [UID:00029M][0x0069b364-0x0069b370.MainUiLayerSlotsHead](by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md) | `0x0069b364`, `0x0069b368`, and `0x0069b36c`, the head triplet after three feature singleton storage pages. |
| [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md) | `0x0069b374`, the browser/alert/layout-facing shared context slot. |
| [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md) | `0x0069b378` and `0x0069b37c`, the tail pair before the active-dialog counter. |

[UID:00029N][0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370](by-memory/0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370.md) is a separate initialized `0xffffffff` dword with no direct data xrefs; do not count it as a seventh layer slot.

## Observed Slots

| Storage | Startup write | Startup init | Shutdown release/clear | Notes |
| --- | --- | --- | --- | --- |
| `dword_69B364` / `0x0069b364` | `0x004f6268` | `0x004f6340` | `0x004f64ff`, `0x004f6594` | Broad UI layer/context slot; stale alias [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md). |
| `dword_69B368` / `0x0069b368` | `0x004f6239` | `0x004f6331` | `0x004f6510`, `0x004f65ae` | Used by root/background/status pane setup paths. |
| `dword_69B36C` / `0x0069b36c` | `0x004f6297` | `0x004f634f` | `0x004f64ee`, `0x004f657a` | Used by main UI graph setup; final role name open. |
| `dword_69B374` / `0x0069b374` | `0x004f62c6` | `0x004f635e` | `0x004f64dd`, `0x004f65c8` | Used by main UI graph setup; final role name open. |
| `dword_69B378` / `0x0069b378` | `0x004f62f5` | `0x004f636d` | `0x004f64cc`, `0x004f6560` | Used by main UI graph setup; final role name open. |
| `dword_69B37C` / `0x0069b37c` | `0x004f632c` | `0x004f637c` | `0x004f6521`, `0x004f6546` | Used by main UI graph setup; final role name open. |

## InitializeMainUiGraph Handoff

[UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) and [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) currently record the most specific pane-setup handoff counts for the first two layer/context slots: `dword_69B364` is pushed at 12 pane-setup sites and `dword_69B368` at 10 pane-setup sites. The remaining four slots are still proven as members of the same startup/shutdown-managed family through their adjacent allocation/registration sequence, direct data-ref counts, and consumer evidence on the backing memory pages, but their final per-slot semantic names remain open.

## Alias Cleanup

- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) is a stale generated alias over `0x0069b364`; one effecter consumer does not make the storage render/effects-owned.
- [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md) is a generated browser-facing alias over `0x0069b374`; browser code consumes the layout context but does not own the slot.
- The real reconstructable family is this six-slot MainUiGraph/MainUiLayerSlots set. Keep generated consumer-biased aliases in the ignored ledger and keep reconstruction under the final main UI graph owner.

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
- IDA xrefs to `0x0069b364` are broad and include `InitializeMainUiGraph`, root/UI panes, chat/browser/status/user panes, and effecter pane setup. [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) is one consumer, not the owner.
- Exact backing pages refreshed through 2026-06-06 document all initial bytes as `0xffffffff`, the 35/60/101/13/14/11 direct-ref split, startup writes/initialization passes, shutdown detach/release/zero paths, and clean neighboring boundaries around the unused `0x0069b370` dword and the `0x0069b380` active-dialog counter.
- [UID:0002H7][0x004f5fb0-0x004f6490.ApplicationStartup](by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md) and [UID:0002H8][0x004f6490-0x004f66a5.ApplicationShutdown](by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md) now both cross-reference the exact layer-slot pages, which confirms the startup/shutdown mirror and keeps this overview aligned with the app lifecycle methods.

## Reconstruction Guidance

Recover these as main UI graph layer/context globals or as fields of a recovered UI graph object if later layout evidence proves they were members. Do not create a `ScreenEffecterList` class or attach `dword_69B364` to `render/Effects.cpp`.

Do not emit final C++ yet. The family is clearly source-declared and reconstructable, but the original names for the six slots and the final declaration shape are still below the final-code gate.

## Cross-References

- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)
- [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md)
- [UID:0002H7][0x004f5fb0-0x004f6490.ApplicationStartup](by-memory/0x004f5fb0-0x004f6490.ApplicationStartup.md)
- [UID:0002H8][0x004f6490-0x004f66a5.ApplicationShutdown](by-memory/0x004f6490-0x004f66a5.ApplicationShutdown.md)
- [UID:00029M][0x0069b364-0x0069b370.MainUiLayerSlotsHead](by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md)
- [UID:00029N][0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370](by-memory/0x0069b370-0x0069b374.UnreferencedInitializedDword_69B370.md)
- [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md)
- [UID:00029O][0x0069b378-0x0069b380.MainUiLayerSlotsTail](by-memory/0x0069b378-0x0069b380.MainUiLayerSlotsTail.md)
- [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0000IZ][Effects](by-file/Effects.md)

## Changes

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
