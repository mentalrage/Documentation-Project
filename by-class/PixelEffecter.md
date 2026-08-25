*** UID:0000AI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PixelEffecter : public ScreenEffecter
{
public:
    PixelEffecter();

    bool IsPixelEffecter() const override { return true; }
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PixelEffecter

## Status

- Confidence: strong for role, hierarchy, and source placement; medium-high for exact constructor representation because IDA does not currently model `0x0055a2a0` as a function object.
- Proposed source: `render/Effects.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Documentation basis: IDA-backed raw constructor bytes, vtable-store evidence, the screen-effecter vtable family, and the shared [UID:0000IZ][Effects](by-file/Effects.md) source-module page.
- Recovered-output caveat: any one-class recovered output is only a lead; the current documentation treats `PixelEffecter` as part of the shared runtime effect hierarchy.

## Responsibility

`PixelEffecter` is a minimal runtime effect base under [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md). The documented raw constructor only installs the `PixelEffecter` vtable, which matches the behavior expected for the map/pixel displacement effect classes that do not need a pane-backed overlay or filter base.

Known subclasses in the current cluster include [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md), [UID:0000GC][XWaveEffecter](by-class/XWaveEffecter.md), [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md), and [UID:000070][LakeEffecter](by-class/LakeEffecter.md).

[UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) confirms the pixel-displacement branch shape: it keeps the single-primary `PixelEffecter` vptr layout, adds only a 20-byte shake state record after the vptr, and implements map-image displacement through random X/Y offset sampling plus `GrafPort::BlitSurface` rather than a pane-backed overlay/filter subobject.

## Hierarchy And Branch Evidence

| Item | Evidence |
| --- | --- |
| Source module | [UID:0000IZ][Effects](by-file/Effects.md) groups `PixelEffecter` with the runtime `ScreenEffecter` hierarchy in `render/Effects.cpp`, before the overlay, filter, displacement, water, and lake branches. |
| Base class | [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) places `PixelEffecter` immediately after `ScreenEffecter` in the single-primary base/effecter table order. |
| Vtable | [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) lists `??_7PixelEffecter@@6B@` at `0x006235c4`, between the `ScreenEffecter` base vtable and the overlay branch tables. B001's 2026-06-18 reanalysis treats the first slot's `0x0055c1b0` target as inferred `IsPixelEffecter()` / `UsesPrimaryEffectPass()` true for this branch, but keeps the folded physical body [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) no-owner/non-emitting because it is shared with system-message and runtime uses. |
| Constructor store | [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) records raw bytes at `0x0055a2a0-0x0055a2b3` that store `0x006235c4` and return `this`; [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) keeps the non-function-object boundary caveat. |
| Branch role | The displacement subclasses (`EarthquakeEffecter`, `XWaveEffecter`, `YFlipEffecter`, `LakeEffecter`) keep a single-primary vtable shape, while overlay/filter subclasses replace or extend the base state with pane-like four-view shapes. That makes `PixelEffecter` the common effecter base layer, not a standalone effect implementation. |

## Rebuild Handling

- Source placement: attach to [UID:0000IZ][Effects](by-file/Effects.md), which already owns the screen-effect hierarchy and has IDA-backed vtable-family evidence.
- Reconstructability: true for the class declaration and minimal constructor behavior. No final C++ is recorded here for a target-specific no-code reason: IDA still does not have a function object at `0x0055a2a0`, no direct raw-start reachability is proven, and final source spelling for the constructor remains below source-quality evidence. This is not an old `95/95` threshold rule.
- Boundary rule: keep the constructor range documented as raw constructor-shaped code until the function object is created in IDA. Do not promote `0x0055a2a0` to an IDA-modeled function in notes or generated comments without that follow-up evidence.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a2a0-0x0055a2b3` | constructor | Raw IDA disassembly confirms a normal prologue, `PixelEffecter` vtable store at `0x0055a2a9`, return, and alignment before the next helper. IDA still lacks a function object for the start; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). |

## IDA Evidence

- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) records the `PixelEffecter` vtable at `0x006235c4`.
- The same vtable-family page records constructor/base stores at `0x0055a2a9` and `0x0055a30b`, tying the raw constructor bytes and derived overlay construction path to this class.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) records `0x0055a2a0-0x0055a2b3` as `PixelEffecter` constructor-shaped bytes that store `0x006235c4`, then return; it also notes that `lookup_funcs 0x0055a2a0` still reports `Not a function`.
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) records `0x006235c4` as `??_7PixelEffecter@@6B@`.
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md), [UID:0000GC][XWaveEffecter](by-class/XWaveEffecter.md), [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md), and [UID:000070][LakeEffecter](by-class/LakeEffecter.md) all document their `PixelEffecter` inheritance and runtime behavior under the same Effects module, reinforcing this class as the shared base for map/pixel displacement effects.
- 2026-06-16 live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed `lookup_funcs 0x0055a2a0` reports `Not a function`, while neighboring/base functions remain modeled at `0x0055a260` size `0x9`, `0x0055a290` size `0x7`, `0x0055a2c0` size `0x7`, `0x0055bfd0` size `0x24`, and `0x0055c1d0` size `0x2f`.
- 2026-06-16 live IDA MCP `trace_data_flow backward 0x006235c4` reconfirmed the raw constructor store at `0x0055a2a9` and the derived/base store in `OverlayEffecter` construction at `0x0055a30b`; `trace_data_flow backward 0x0055a2a0` found no raw-start xrefs.
- 2026-06-16 live IDA MCP `make_signature_for_range 0x0055a2a0-0x0055a2b3` produced a unique exact byte signature for the `0x13` / 19-byte constructor body (Verified with `int_convert.py`). A local PE scan found zero absolute-VA hits, zero RVA hits, and zero direct `E8`/`E9` branch hits to `0x0055a2a0`.

## Reconstruction Notes

- Model `PixelEffecter` as the narrow pixel-effect branch below `ScreenEffecter`, not as an overlay/filter class with pane-owned state.
- The constructor has no documented member initialization beyond installing the class vtable view. Subclass pages carry the effect-specific state and runtime behavior.
- Keep source output minimal: declaration, inheritance, and constructor ownership are supported; additional methods or fields would be speculative from the current page evidence.
- Keep formal C++ declaration-only. This page now has enough evidence for source placement, inheritance, constructor ownership, and the `IsPixelEffecter()` true direction, but its only owned executable body remains a raw/non-modeled constructor with no direct raw-start route; do not emit an isolated constructor body from this page.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page records the class's hierarchy position, vtable address, raw constructor boundary, Effects.cpp ownership, subclass branch role, current live byte/xref evidence, declaration-only source policy, and related displacement subclass evidence. It remains below final-audit level because the only owned body is still raw/non-modeled and exact source-level field/method declarations are intentionally minimal. |
| Confidence | 88 | Current IDA-backed pages and the 2026-06-16 live pass agree on the vtable, constructor store, runtime-cluster placement, no raw-start xrefs, PE no-hit scan, and subclass relationships. Confidence stays below final-audit quality because `0x0055a2a0` is still not an IDA function object and original constructor/source spelling remains unproven. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md)
- [UID:0000GC][XWaveEffecter](by-class/XWaveEffecter.md)
- [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md)
- [UID:000070][LakeEffecter](by-class/LakeEffecter.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal C++ now emits a declaration-only `PixelEffecter : public ScreenEffecter` block with the source-facing `IsPixelEffecter()` true direction. Current MCP still treats `0x0055a2a0-0x0055a2b3` as raw constructor bytes rather than an IDA function, with no direct raw-start xrefs or pointer route. The constructor-shaped bytes store vtable `0x006235c4`, return `this`, and are reinforced by derived/base store evidence at `0x0055a30b`; that is enough for class declaration output but not for a standalone constructor body.

## Changes

- 2026-06-19 B007 EarthquakeEffecter support sync:
  - Score unchanged.
  - Evidence: refreshed the subclass note to record Earthquake as a single-primary `PixelEffecter` displacement subclass with 20-byte shake state and GrafPort blit behavior, not a pane-backed overlay/filter class.
- 2026-06-18 B001 folded-boolean slot sync:
  - Score unchanged at `85/88`.
  - Evidence: the first `PixelEffecter` vtable predicate remains best described as inferred `IsPixelEffecter()` / `UsesPrimaryEffectPass()` true, but the physical true stub at [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) stays no-owner/non-emitting because it is folded with SystemMessagePanes and runtime table uses.
- 2026-06-25 B003 OverlayEffecter support-gate check:
  - Score unchanged.
  - Evidence: checked inherited-base consistency while implementing [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md). `OverlayEffecter : public PixelEffecter, public Pane` is consistent with `PixelEffecter` as the common effecter base layer and with the derived/base store at `0x0055a30b`. Rewrote stale `95/95` empty-output wording as a target-specific no-code proof for the raw `0x0055a2a0` constructor; no metadata or source-route change.
- 2026-06-16 A001 low-confidence class refresh:
  - Before: `82/86`; the page explicitly noted that the previous hierarchy refresh lacked a current-session live IDA audit.
  - After: `85/88`; formal output was withheld because the only owned body was still a raw constructor with no direct reachability proof. B006 2026-06-30 now emits the declaration while keeping the constructor body withheld.
  - Evidence: live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed `0x0055a2a0` is not an IDA function, the constructor-range bytes are unique, `0x006235c4` receives refs from raw store `0x0055a2a9` and derived/base store `0x0055a30b`, neighboring ScreenEffecter functions remain modeled, and local PE scanning found zero absolute-VA, RVA, or direct `E8`/`E9` branch hits to the raw constructor start.

- Before: completion/confidence metadata were `0/0` despite base-effect role, subclass list, raw constructor evidence, and boundary caveat notes.
- Changed to: `COMPLETION:60` and `CONFIDENCE:68`.
- Evidence: the page documents the minimal vtable-store constructor, its raw disassembly boundary, known subclasses, and screen-effect cluster placement; score remains conservative because IDA does not model `0x0055a2a0` as a function object and there is little behavior beyond construction.
- 2026-06-02: Raised from `60/68` to `74/82`, marked reconstructable, and attached under [UID:0000IZ][Effects](by-file/Effects.md).
  - Before: the class stayed in the low-both queue even though the Effects file, vtable family, vtable-data page, and runtime cluster all agreed on ownership.
  - Evidence: `0x006235c4` vtable identity, constructor/base stores at `0x0055a2a9` and `0x0055a30b`, raw constructor range `0x0055a2a0-0x0055a2b3`, and the explicit IDA caveat that `0x0055a2a0` is not yet a function object.
- 2026-06-06 provenance cleanup:
  - Before: the status section still presented a direct recovered-source path as current evidence.
  - After: replaced it with the IDA-backed documentation basis and an explicit recovered-output caveat.
  - Evidence: ownership and behavior remain supported by the raw constructor range, vtable-store evidence, screen-effecter vtable family, runtime cluster, and Effects file page. Scores and parent remain unchanged; B006 2026-06-30 replaces the former empty marker with declaration-only output.
- 2026-06-07 A001 hierarchy/evidence refresh:
  - Before: scored `74/82` and documented the raw constructor and immediate vtable evidence, but did not summarize the class's hierarchy position or the supporting subclass branch evidence in one place.
  - After: scored `82/86`, added hierarchy/branch evidence, score rationale, stronger subclass cross-references, and explicit final-C++ gate rationale.
  - Evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md), [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), and the displacement subclass pages agree on the `Effects.cpp` owner, `0x006235c4` vtable, `0x0055a2a0-0x0055a2b3` raw constructor, and `PixelEffecter` base role. Current-session IDA MCP was unavailable after retries, so no new live byte audit is claimed.
