*** UID:0001X3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000Y | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00000Y | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// BlueAlertPane vtable cluster generated from the BlueAlertPane class declaration and virtual overrides.
// The table evidence proves class layout and draw/action slots; it is not hand-authored source.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BlueAlertPane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md).
- Likely source file: [UID:0000HE][AlertPanes](by-file/AlertPanes.md), pending live constructor reachability.
- Exact vtable-data range: [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md).
- Confidence: strong for vtable bases, constructor stores, custom virtual slots, and the end boundary before `UserHairSelectControlPane`; medium for live construction/source reachability.
- Autogen status: attached to the `BlueAlertPane` class page; final C++ remains blank because the vtable bytes, RTTI metadata, and adjustor thunks are generated from the eventual class declaration and virtual overrides.

## Vtable Bases

| Class view | Base | Constructor store | Object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x0061dcd8` | `0x00500920` | `+0x00` | Installed after blank `DialogPane` construction inside `BlueAlertPane::BlueAlertPane`. |
| secondary | `0x0061dd40` | `0x00500926` | `+0xa0` | Secondary dialog/input view. |
| tertiary | `0x0061dd70` | `0x00500930` | `+0xa4` | Event/update-handler view. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x0061dcd8` | `+0x00` | `0x0048c550` | Shared `AlertPane`-family scalar deleting destructor. |
| primary `0x0061dcd8` | `+0x44` | `0x00500c70` | `BlueAlertPane::DrawSelectedItemFrame`. |
| primary `0x0061dcd8` | `+0x48` | `0x00500c30` | `BlueAlertPane::HandleActionButton`. |
| primary `0x0061dcd8` | `+0x4c` | `0x0041b6a0` | Guard/no-op slot, not a recovered custom handler. |
| primary `0x0061dcd8` | `+0x50` | `0x00500d70` | `BlueAlertPane::DrawContent`. |
| primary `0x0061dcd8` | `+0x54` | `0x00500e20` | `BlueAlertPane::DrawBorderFrame`. |
| primary `0x0061dcd8` | `+0x58` | `0x0049fc00` | Inherited dialog hover/update virtual. |
| primary `0x0061dcd8` | `+0x5c` | `0x0041b6a0` | Base no-op/guard callback slot. |
| primary `0x0061dcd8` | `+0x60` | `0x0041b6a0` | Base no-op/guard callback slot. |
| secondary `0x0061dd40` | `+0x00` | `0x0048c315` | Adjustor thunk into shared deleting destructor with `this - 0xa0`. |
| tertiary `0x0061dd70` | `+0x00` | `0x0048c320` | Adjustor thunk into shared deleting destructor with `this - 0xa4`. |
| tertiary `0x0061dd70` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

Do not read primary `+0x64` as a `BlueAlertPane` virtual: it is RTTI metadata for the secondary table at `0x0061dd40`. Likewise, secondary `+0x2c` is RTTI metadata for the tertiary table, and tertiary `+0x08` belongs to the following `UserHairSelectControlPane` RTTI region.

## IDA MCP Evidence

- `list_globals *BlueAlertPane*` reports vtables at `0x0061dcd8`, `0x0061dd40`, and `0x0061dd70`, plus RTTI records at `0x0064ac74`, `0x0064acd4`, and `0x0064ace8`.
- `xrefs_to` the three vtable bases reports constructor stores at `0x00500920`, `0x00500926`, and `0x00500930` inside `BlueAlertPane::BlueAlertPane` at `0x005008c0`.
- Disassembly of `0x005008c0` shows stores to `[ebx]`, `[ebx+0xa0]`, and `[ebx+0xa4]` immediately after `DialogPane` construction with a blank resource string.
- `lookup_funcs` confirms custom virtual targets at `0x00500c30`, `0x00500c70`, `0x00500d70`, and `0x00500e20`, plus the shared destructor at `0x0048c550` and adjustor thunks at `0x0048c315` and `0x0048c320`.
- `xrefs_to 0x005008c0` currently reports no direct constructor callers, so the class is structurally real but live construction is still unresolved.
- Current Wave3 metadata for `class_BlueAlertPane.meta_wave3` reports `vtable_count: 0`, so generated vtable inventory is incomplete even though the active source names virtual-install placeholders.
- 2026-05-31 IDA MCP `py_eval` dword scan confirms the exact vtable-data range [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md): `0x0061dcd4` is the preceding `BlueAlertPane` RTTI pointer, `0x0061dcd8` is the first primary slot, `0x0061dd78` is `UserHairSelectControlPane` RTTI, and `0x0061dd7c` is the next class vtable start.

## Reconstruction Notes

Model `BlueAlertPane` as a `DialogPane`-derived blue-frame alert variant with three vtable views at `+0x00`, `+0xa0`, and `+0xa4`. Keep `0x0048c315` and `0x0048c320` as compiler adjustor thunks, not source methods.

The primary table overrides dialog painting and action handling while retaining inherited dialog/input/event slots around them. The drawing methods use `BDFRAME.EPF` resource frames through the shared EPF/render path; the generated `g_uiTileRenderer` name is a data alias until a render-global pass proves backing storage.

## Parent Rationale

Attach this vtable cluster to [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) because the three tables are installed by `BlueAlertPane::BlueAlertPane`, the custom slots point to the class action and drawing methods, and the class page already records the same exact [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) range. The class itself is attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md), so this assignment gives generated type coverage the correct source-level owner while preserving the unresolved live-construction caveat.

## Cross-References

- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:00010W][0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor](by-memory/0x0048c550-0x0048c58b.AlertPaneSharedScalarDestructor.md)
- [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- [UID:0001R5][alert-dialog-resources](by-resource/alert-dialog-resources.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the vtable cluster was reconstructable but unassigned in generated type coverage, while the owning `BlueAlertPane` class was already attached to [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
  - What changed: attached the vtable cluster to [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md), raised completion to `84`, and added an explicit parent rationale.
  - Summary/evidence: constructor stores at `0x00500920`, `0x00500926`, and `0x00500930`, custom virtual slots for action/content/border drawing, and exact [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) tie the tables to the class; confidence stays below final-source level because direct construction reachability remains unresolved.
- 2026-06-30 B011 empty-emitter implementation:
  - Raised from `84/90` to `86/91`; owner/emitter remains [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md).
  - Added the formal vtable-cluster no-code marker and replaced stale final-threshold wording. Current evidence proves constructor stores, custom action/draw slots, no direct constructor refs, the exact [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md) child route, and no raw dword/source-array policy while preserving the unresolved live-construction caveat.

- What existed before: the vtable cluster page identified the three `BlueAlertPane` vtable bases and constructor stores, but it had unevaluated scores and no exact by-memory child range for the table bytes.
- What it was changed to: the page now points to [UID:0002M6][0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData](by-memory/0x0061dcd8-0x0061dd78.BlueAlertPaneVtableData.md), is marked reconstructable, and has completion/confidence scores reflecting the IDA-verified vtable data.
- Summary and evidence: 2026-05-31 IDA MCP `lookup_funcs` and read-only `py_eval` checks confirmed function starts, slot values, constructor xrefs, and the boundary before `UserHairSelectControlPane` RTTI/vtable data. Live constructor reachability remains open, so this is not a `95+` item.
