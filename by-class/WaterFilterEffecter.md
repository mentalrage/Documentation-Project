*** UID:0000FZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WaterFilterEffecter : public FilterEffecter
{
public:
    WaterFilterEffecter();
    virtual ~WaterFilterEffecter();

    virtual void OnPaint();

private:
    float m_causticDrawAlpha;
    ArchiveMetadataTable *m_causticFrameTable;
    void *m_causticPalette;
    unsigned int m_lastCausticTick;
    unsigned short m_causticFrameIndex;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WaterFilterEffecter

## Status

- Confidence: very strong for role, ownership, vtable shape, constructor/update/destructor ranges, CAUST resource fields, and caustic paint/update behavior.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_WaterFilterEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`WaterFilterEffecter` is a [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) subclass for animated water/caustic filtering. It loads `CAUST.EPF` frame metadata and `CAUST.PAL` palette data, advances a 32-frame caustic frame index on a 60 ms timer cadence, and renders the current caustic tile over the filter pane through GrafPort tiled-background drawing.

The class uses the same four-view filter-effecter object shape as other pane-backed filter classes: primary view at `+0x00`, inherited Pane/GrafPort view at `+0x04`, and additional adjusted inherited Pane-side views at `+0xa4` and `+0xa8`. The update body at [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md) is installed in the adjusted `+0x04` Pane/GrafPort view slot `+0x44`.

B013's FilterEffecter source-quality pass resolves the base declaration as `FilterEffecter : public ScreenEffecter, public Pane`. Water-specific fields begin after the inherited Pane/GrafPort portion; complete `+0xf9` remains inherited Pane flag state used before concrete layer registration, not a WaterFilterEffecter-owned active field.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b5d0-0x0055b698` | `OnPaint` / caustic update paint body | [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md) is the `+0x04` Pane/GrafPort view slot `+0x44` override (`0x00623cb4 -> 0x0055b5d0`). It gates on `g_pTimerMgr->m_currentTick`, advances the 32-frame caustic index, projects the `CAUST.EPF` frame through `LoadFrameDrawRecord`, temporarily sets GrafPort draw mode/alpha, and draws with `L"CAUST.PAL"`. |
| `0x0055b6a0-0x0055b77d` | constructor | Builds the filter base, installs WaterFilterEffecter vtable views, loads `CAUST.EPF` metadata at complete `+0x10c` / view `+0x108`, preloads `CAUST.PAL` at complete `+0x110` / view `+0x10c`, seeds `m_lastCausticTick` at complete `+0x114` / view `+0x110`, zeroes `m_causticFrameIndex` at complete `+0x118` / view `+0x114`, initializes inherited alpha, writes inherited Pane flag state at complete `+0xf9`, and attaches pane state through the Main UI layer/context slot. |
| `0x0055b780-0x0055b80e` | destructor | Resets water/filter/screen vtables and tears down pane/filter state. |
| `0x0055c0c0-0x0055c17d` | scalar deleting destructor | Calls the ordinary destructor and conditionally deletes storage. |

## Field Notes

The caustic paint body receives the adjusted Pane/GrafPort view. Add four bytes for complete-object offsets.

Complete `+0x94` equals this adjusted view's `+0x90` alpha field. Complete `+0xf9` equals inherited Pane flag state at Pane-relative `+0xf5`; avoid Water-owned field wording for that byte.

| View offset | Source-facing direction | Evidence |
| --- | --- | --- |
| `+0x70` | `m_drawMode` / `m_blitMode` | Temporarily set to `2` before [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md), then restored to `0`. This is GrafPort render mode, not Pane `m_mode` at `+0xb5`. |
| `+0x90` | `m_alpha` / current draw alpha | Constructor seeds the current alpha; update saves/restores it around the caustic draw. |
| `+0xbc` | `m_causticDrawAlpha` | High-probability descriptive name. The update copies it into `+0x90`; no local setter has been proven. |
| `+0x108` | `m_causticFrameTable` | Constructor stores `CAUST.EPF` metadata here; update passes it to `LoadFrameDrawRecord`. |
| `+0x10c` | `m_causticPalette` | Constructor stores the `CAUST.PAL` preload/lookup result here. |
| `+0x110` | `m_lastCausticTick` | Constructor seeds `currentTick - 61`; update compares against `+60` and stores current tick. |
| `+0x114` | `m_causticFrameIndex` | 16-bit field zeroed in constructor, incremented and wrapped at `32` in update. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md)
- [UID:0003EH][0x00623d18-0x00623d58.ScreenEffecterResourceStringsAndConstants](by-memory/0x00623d18-0x00623d58.ScreenEffecterResourceStringsAndConstants.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal C++ now emits the `WaterFilterEffecter : public FilterEffecter` declaration with caustic alpha, frame-table, palette, tick, and frame-index state. The accepted declaration preserves the current caustic path: the `+0x04` Pane/GrafPort paint slot at `0x00623cb4 -> 0x0055b5d0` advances the 32-frame caustic index, calls `LoadFrameDrawRecord`, uses `CAUST.EPF`/`CAUST.PAL`, and renders through `GrafPort::DrawTiledBackground`. Exact method bodies remain with exact children; the class page now provides the source-facing declaration rather than an empty marker.

## Changes

- 2026-06-19 B013 FilterEffecter support incorporation:
  - Score unchanged at `86/90`.
  - Summary/evidence: updated inherited-view wording to match the accepted FilterEffecter class shape. WaterFilterEffecter's adjusted `+0x04` view remains the caustic paint route, complete `+0x94` maps to view `+0x90` alpha, and complete `+0xf9` is inherited Pane flag state rather than a Water-owned active field. Layer registration continues to use the Main UI layer/context slot.
- 2026-06-17 B002 WaterFilterEffecter source-quality execution:
  - Before: `84/88`, with the caustic body documented as a generic update helper and unresolved final field/source names.
  - After: `86/90`, with the `+0x04` Pane/GrafPort view slot, CAUST resource fields, timer/frame fields, draw-mode/alpha fields, and `OnPaint` source-facing direction documented.
  - Summary/evidence: B002 reanalysis confirmed `0x00623cb4 -> 0x0055b5d0`, the constructor-to-update field mapping for `CAUST.EPF`, `CAUST.PAL`, last tick, and frame index, the stale `DrawPictureObjectPane` rejection, and accepted first-draft C++ on the exact child page.
- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the update helper, constructor, destructor, and scalar deleting destructor starts at `0x0055b5d0`, `0x0055b6a0`, `0x0055b780`, and `0x0055c0c0`; the class and parent both pass the 80/80 parent gate. No class-level reconstruction C++ was emitted because final class declarations belong to the aggregate/file reconstruction.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the water/caustic effect responsibility, tick/update frame behavior, constructor/destructor/deleting-destructor map, palette/resource ownership, vtable-family link, and exact update-helper memory reference.
