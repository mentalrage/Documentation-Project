*** UID:0000RI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pMenuVarietyPane

## Status

- Address: `0x0069b4e8`
- Type kind: inferred singleton pointer.
- Likely owner: [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- Storage cluster: [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- Confidence: strong for address, owner, lifecycle writes/clears, and selector consumers; medium-high for standalone storage-page completeness.

## Role

`g_pMenuVarietyPane` points to the active in-game menu button pane. The constructor at `0x005bc610` installs the pointer, the cleanup body at `0x005bc660` and scalar deleting destructor at `0x005bfc80` clear it, and `MenuVarietySelectPane` action handlers use it to pulse or refresh the owning menu button.

## Evidence

- IDA xrefs to `0x0069b4e8` include `MenuVarietyPane::MenuVarietyPane` at `0x005bc610`, cleanup at `0x005bc660`, `MenuVarietySelectPane::HandleMenuMouseEvent` at `0x005bd000`, `MenuVarietySelectPane::NotifyAndMarkSessionForDeletion` at `0x005bd3a0`, and the `MenuVarietyPane` scalar deleting destructor at `0x005bfc80`.
- Active `simroot_v2/class_MenuVarietyPane.cpp` names the symbol `g_pMenuVarietyPane`.
- Current `source-3/simroot_v2/class_MenuVarietyPane.cpp.source_map.json` resolves `global-data:g_pMenuVarietyPane` to `0x0069b4e8-0x0069b4eb` with two mapped declaration/banner lines and no missing-memory-range count.
- `simroot_v2/class_MenuVarietySelectPane.cpp` reads `g_pMenuVarietyPane` in selector paths that call `Pulse()`, matching the owner/selector interaction documented in [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md).
- `simroot_v2/class_MapPane.cpp` checks and destroys `g_pMenuVarietyPane` during map/UI teardown; this is a lifetime consumer, not a source-owner claim.
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) documents the slot inside the dense UI singleton pointer run and separates it from adjacent `UserStatusPane2` and `OldUserStatusPane` globals.

## Cross-References

- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)
- [UID:0001NP][0x005bc610-0x005bfd98.MenuVarietyPanes](by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)

## Changes

- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0` with brief singleton/lifecycle notes.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:84`, storage-cluster reference, source-map range evidence, selector consumer evidence, and teardown-consumer note.
  - Summary/evidence: [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), [UID:0001NP][0x005bc610-0x005bfd98.MenuVarietyPanes](by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md), class docs for [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md) and [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md), plus current `simroot_v2` source-map evidence support the role. Completion is capped because this page still uses the aggregate UI singleton storage page rather than a dedicated exact by-memory page, and live IDA was unavailable for a fresh xref refresh.
