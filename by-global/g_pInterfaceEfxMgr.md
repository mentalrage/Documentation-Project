*** UID:0000R8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pInterfaceEfxMgr

## Status

- Confidence: strong for singleton role; medium for final canonical name.
- Address: `0x0069b360`
- Exact storage: [UID:00029M][0x0069b358-0x0069b370.UiSingletonAndMainUiLayerGlobals](by-memory/0x0069b358-0x0069b370.UiSingletonAndMainUiLayerGlobals.md)
- IDA name: `dword_69B360`
- Proposed name: `g_pInterfaceEfxMgr`
- Current generated declaration: `InterfaceEfxMgr* g_pInterfaceEfxMgr` in `source-3/simroot_v2/class_InterfaceEfxMgr.cpp`
- Owner class: [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)

## Summary

`dword_69B360` stores the active [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md). The manager is created by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) only in the older layout branch, and it owns persistent interface effects for character, magic, and item UI animations.

This slot is one member of the UI singleton/layer block at `0x0069b358-0x0069b370`. The first three slots are feature singletons and the following three are main UI layer/context slots, so keep `g_pInterfaceEfxMgr` with `InterfaceEfx`/`InterfaceEfxMgr` ownership rather than merging it into the generic layer-slot family.

## Evidence

- IDA xrefs show writes from `InterfaceEfxMgr` constructor `0x004e9d00`.
- IDA xrefs show clears from [UID:00018I][0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks.md) and scalar deleting destructor `0x004ea090`.
- Additional reads include [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), which calls the manager trigger method at `0x004e9ee0`.
- Current `class_InterfaceEfxMgr.cpp.source_map.json` maps generated `global-data:g_pInterfaceEfxMgr` to storage `0x0069b360-0x0069b364` and reports the active generated declaration in `class_InterfaceEfxMgr.cpp`.
- Current active `class_InterfaceEfxMgr.cpp` emits singleton writes in the constructor and scalar deleting destructor, while still omitting the IDA-confirmed trigger helper at `0x004e9ee0` and singleton-clear helper at `0x004ea060`.

## Open Questions

- Final canonical name is likely `g_pInterfaceEfxMgr`, but keep `dword_69B360` searchable until generated aliases and IDA labels converge.
- Final source split remains open: this global can live in `InterfaceEfx.cpp` with the manager class or in a separate `InterfaceEfxMgr.cpp` if later project-structure evidence favors a manager split.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- [UID:00029M][0x0069b358-0x0069b370.UiSingletonAndMainUiLayerGlobals](by-memory/0x0069b358-0x0069b370.UiSingletonAndMainUiLayerGlobals.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:00018I][0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea080.InterfaceEfxMgrSingletonAndThunks.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `84/82`.
  - Before: The page had basic singleton lifecycle notes but was unscored and did not link the exact storage aggregate or current generated declaration/source-map evidence.
  - After: The page records the exact `0x0069b360-0x0069b364` storage context, generated declaration, current source-map evidence, owner split caveat, and remaining generated-output omissions.
  - Evidence: [UID:00029M][0x0069b358-0x0069b370.UiSingletonAndMainUiLayerGlobals](by-memory/0x0069b358-0x0069b370.UiSingletonAndMainUiLayerGlobals.md) documents the slot and xrefs; current `class_InterfaceEfxMgr.cpp` declares `InterfaceEfxMgr* g_pInterfaceEfxMgr`, and its source map maps `global-data:g_pInterfaceEfxMgr` to the same storage range.
