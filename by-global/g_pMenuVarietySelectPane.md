*** UID:0000RJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMenuVarietySelectPane

## Status

- Address: `0x0069bf78`
- Type kind: inferred singleton pointer.
- Final source type: `MenuVarietySelectPane* g_pMenuVarietySelectPane`.
- Likely owner: [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- Exact storage page: [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md)
- Confidence: strong for identity, owner, and lifecycle; medium-high for final initialization syntax.

## Role

`g_pMenuVarietySelectPane` points to the currently open selector spawned by [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md). The menu button checks this pointer to decide whether to draw the open-frame artwork, refresh the existing selector, or allocate a new [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md).

## Lifecycle

- `MenuVarietySelectPane::MenuVarietySelectPane` at `0x005bc970` assigns `this` to the global.
- `MenuVarietySelectPane::~MenuVarietySelectPane` at `0x005bcf80` clears the global to null after unregistering/removing the pane and destroying the menu label vector.
- The clear helper at `0x005bfbd0-0x005bfbdb` also clears this exact slot during the shared UI-pane destructor/thunk tail.
- The image dword is documented as initialized to `0xffffffff`; treat the exact final C++ initializer as unresolved until IDA/data-section context is rechecked live.

## Consumers

- `MenuVarietyPane::HandleClick` at `0x005bc690` checks the pointer. A live selector is refreshed; otherwise a new selector is allocated and stored on the owner pane.
- `MenuVarietyPane::DrawMenuArtwork` at `0x005bc800` checks the pointer to choose the menu artwork load/display mode.
- Selector action handling uses the sibling [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md) to pulse the menu button before marking the session for deletion.

## Evidence

- IDA xrefs to `0x0069bf78` include the menu button click handler at `0x005bc690`, menu artwork draw at `0x005bc800`, `MenuVarietySelectPane::MenuVarietySelectPane` at `0x005bc970`, destructor at `0x005bcf80`, singleton clear helper at `0x005bfbd0`, and scalar deleting destructor at `0x005bfce0`.
- Active `simroot_v2/class_MenuVarietyPane.cpp` checks `g_pMenuVarietySelectPane` in `HandleClick` and `DrawMenuArtwork`.
- Active `simroot_v2/class_MenuVarietySelectPane.cpp` writes `g_pMenuVarietySelectPane = this` in the constructor and `g_pMenuVarietySelectPane = nullptr` in the destructor.
- The source maps for both active files contain `global-data:g_pMenuVarietySelectPane` entries; the global-data declarations still lack direct memory ranges, so the exact storage page remains the stronger address evidence.
- The former unresolved `dword_69bf78` clear helper at `0x005bfbd0` is therefore a `MenuVarietySelectPane` singleton clear helper, not a `UserStatusPane` singleton.
- IDA MCP was unavailable during the 2026-05-30 score pass, so this update uses prior IDA-recorded xrefs plus exact by-memory evidence rather than a fresh live xref query.

## Cross-References

- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)
- [UID:0001NP][0x005bc610-0x005bfd98.MenuVarietyPanes](by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md)

## Changes

- Completion/confidence score update:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`, with only the basic role and xref summary documented.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:84`, with explicit storage page, lifecycle, consumers, source-map support, and unresolved initializer caveat.
  - Summary/evidence: exact storage is covered by [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md); constructor/destructor and click/draw consumers are documented in the menu-variety memory/class/file pages and active simroot files; confidence is capped because live IDA MCP was unavailable for a fresh xref check and the observed `0xffffffff` image initializer still needs final-source interpretation.
