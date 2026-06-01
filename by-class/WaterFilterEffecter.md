*** UID:0000FZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WaterFilterEffecter

## Status

- Confidence: strong for role and ownership.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_WaterFilterEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`WaterFilterEffecter` is a [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) subclass for animated water/caustic filtering. It loads the `CAUST.PAL` palette data, advances a 32-frame palette index on a 60 ms cadence, and renders the current caustic frame into the filter pane.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055b5d0-0x0055b698` | `UpdateCausticEffect` | IDA confirms the 60 ms tick gate, 32-frame wrap, frame-table lookup, and render call using the `CAUST.PAL` key; see [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md). |
| `0x0055b6a0-0x0055b77d` | constructor | Builds the filter base, installs water vtables, loads palette buffer/timestamps, configures alpha, and attaches pane state. |
| `0x0055b780-0x0055b80e` | destructor | Resets water/filter/screen vtables and tears down pane state. |
| `0x0055c0c0-0x0055c17d` | scalar deleting destructor | Calls destructor and conditionally deletes storage. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0000MA][Palette](by-file/Palette.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the water/caustic effect responsibility, tick/update frame behavior, constructor/destructor/deleting-destructor map, palette/resource ownership, vtable-family link, and exact update-helper memory reference.
