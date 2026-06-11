*** UID:0000AI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PixelEffecter

## Status

- Confidence: strong for role, medium for exact constructor boundary because IDA does not currently model `0x0055a2a0` as a function object.
- Proposed source: `render/Effects.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Documentation basis: IDA-backed raw constructor bytes, vtable-store evidence, the screen-effecter vtable family, and the shared [UID:0000IZ][Effects](by-file/Effects.md) source-module page.
- Recovered-output caveat: any one-class recovered output is only a lead; the current documentation treats `PixelEffecter` as part of the shared runtime effect hierarchy.

## Responsibility

`PixelEffecter` is a minimal runtime effect base under [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md). The documented raw constructor only installs the `PixelEffecter` vtable, which matches the behavior expected for the map/pixel displacement effect classes that do not need a pane-backed overlay or filter base.

Known subclasses in the current cluster include [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md), [UID:0000GC][XWaveEffecter](by-class/XWaveEffecter.md), [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md), and [UID:000070][LakeEffecter](by-class/LakeEffecter.md).

## Hierarchy And Branch Evidence

| Item | Evidence |
| --- | --- |
| Source module | [UID:0000IZ][Effects](by-file/Effects.md) groups `PixelEffecter` with the runtime `ScreenEffecter` hierarchy in `render/Effects.cpp`, before the overlay, filter, displacement, water, and lake branches. |
| Base class | [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) places `PixelEffecter` immediately after `ScreenEffecter` in the single-primary base/effecter table order. |
| Vtable | [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) lists `??_7PixelEffecter@@6B@` at `0x006235c4`, between the `ScreenEffecter` base vtable and the overlay branch tables. |
| Constructor store | [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) records raw bytes at `0x0055a2a0-0x0055a2b3` that store `0x006235c4` and return `this`; [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) keeps the non-function-object boundary caveat. |
| Branch role | The displacement subclasses (`EarthquakeEffecter`, `XWaveEffecter`, `YFlipEffecter`, `LakeEffecter`) keep a single-primary vtable shape, while overlay/filter subclasses replace or extend the base state with pane-like four-view shapes. That makes `PixelEffecter` the common effecter base layer, not a standalone effect implementation. |

## Rebuild Handling

- Source placement: attach to [UID:0000IZ][Effects](by-file/Effects.md), which already owns the screen-effect hierarchy and has IDA-backed vtable-family evidence.
- Reconstructability: true for the class declaration and minimal constructor behavior. The source-side constructor can be emitted as a small vtable-owning constructor, but no final C++ is recorded here because the current evidence is below the 95+ threshold and IDA still does not have a function object at `0x0055a2a0`.
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

## Reconstruction Notes

- Model `PixelEffecter` as the narrow pixel-effect branch below `ScreenEffecter`, not as an overlay/filter class with pane-owned state.
- The constructor has no documented member initialization beyond installing the class vtable view. Subclass pages carry the effect-specific state and runtime behavior.
- Keep source output minimal: declaration, inheritance, and constructor ownership are supported; additional methods or fields would be speculative from the current page evidence.
- Keep final C++ blank until the raw constructor is promoted or otherwise modeled with final-source-quality naming. This page now has enough evidence for source placement and class shape, but not enough for the 95/95 reconstruction gate.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The page now records the class's hierarchy position, vtable address, raw constructor boundary, Effects.cpp ownership, subclass branch role, blank-code gate, and related displacement subclass evidence. It remains below final-audit level because the only owned body is still raw/non-modeled and exact source-level field/method declarations are intentionally minimal. |
| Confidence | 86 | Existing IDA-backed pages agree on the vtable, constructor store, runtime-cluster placement, and subclass relationships. Confidence stays below 95 because current-session IDA MCP was unavailable for a fresh live byte/xref audit and `0x0055a2a0` is still not an IDA function object. |

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

## Changes

- Before: completion/confidence metadata were `0/0` despite base-effect role, subclass list, raw constructor evidence, and boundary caveat notes.
- Changed to: `COMPLETION:60` and `CONFIDENCE:68`.
- Evidence: the page documents the minimal vtable-store constructor, its raw disassembly boundary, known subclasses, and screen-effect cluster placement; score remains conservative because IDA does not model `0x0055a2a0` as a function object and there is little behavior beyond construction.
- 2026-06-02: Raised from `60/68` to `74/82`, marked reconstructable, and attached under [UID:0000IZ][Effects](by-file/Effects.md).
  - Before: the class stayed in the low-both queue even though the Effects file, vtable family, vtable-data page, and runtime cluster all agreed on ownership.
  - Evidence: `0x006235c4` vtable identity, constructor/base stores at `0x0055a2a9` and `0x0055a30b`, raw constructor range `0x0055a2a0-0x0055a2b3`, and the explicit IDA caveat that `0x0055a2a0` is not yet a function object.
- 2026-06-06 provenance cleanup:
  - Before: the status section still presented a direct recovered-source path as current evidence.
  - After: replaced it with the IDA-backed documentation basis and an explicit recovered-output caveat.
  - Evidence: ownership and behavior remain supported by the raw constructor range, vtable-store evidence, screen-effecter vtable family, runtime cluster, and Effects file page. Scores, parent, and blank C++ gate remain unchanged.
- 2026-06-07 A001 hierarchy/evidence refresh:
  - Before: scored `74/82` and documented the raw constructor and immediate vtable evidence, but did not summarize the class's hierarchy position or the supporting subclass branch evidence in one place.
  - After: scored `82/86`, added hierarchy/branch evidence, score rationale, stronger subclass cross-references, and explicit final-C++ gate rationale.
  - Evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md), [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), and the displacement subclass pages agree on the `Effects.cpp` owner, `0x006235c4` vtable, `0x0055a2a0-0x0055a2b3` raw constructor, and `PixelEffecter` base role. Current-session IDA MCP was unavailable after retries, so no new live byte audit is claimed.
