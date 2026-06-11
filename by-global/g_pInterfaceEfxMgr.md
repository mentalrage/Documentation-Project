*** UID:0000R8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pInterfaceEfxMgr

## Status

- Confidence: strong for singleton role; medium for final canonical name.
- Address: `0x0069b360`
- Exact storage: [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md)
- IDA name: `dword_69B360`
- Proposed name: `g_pInterfaceEfxMgr`
- Owner class: [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)

## Summary

`dword_69B360` stores the active [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md). The manager is created by [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md) only in the older layout branch, and it owns persistent interface effects for character, magic, and item UI animations.

This slot is the final feature singleton before the MainUiLayerSlots head triplet at `0x0069b364`. Keep `g_pInterfaceEfxMgr` with `InterfaceEfx`/`InterfaceEfxMgr` ownership rather than merging it into the generic layer-slot family.

## Evidence

- IDA xrefs show writes from `InterfaceEfxMgr` constructor `0x004e9d00`.
- IDA xrefs show clears from [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) and scalar deleting destructor `0x004ea090`.
- Additional reads include [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), which calls the manager trigger method at `0x004e9ee0`.
- Live IDA MCP decompilation confirms singleton writes in the constructor and clears in the helper/destructor paths; `0x004e9ee0` remains the IDA-confirmed trigger helper.
- Batch 039 live IDA MCP recheck on 2026-06-07 confirmed the exact four-byte storage page [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md): initial dword `0xffffffff`, seven direct refs, constructor writes at `0x004e9d4b`/`0x004e9d52`, clear/destructor paths at `0x004ea060` and `0x004ea0e2`, and the boundary before [UID:00029M][0x0069b364-0x0069b370.MainUiLayerSlotsHead](by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md).

## Open Questions

- Final canonical name is likely `g_pInterfaceEfxMgr`, but keep `dword_69B360` searchable until aliases and IDA labels converge.
- Final source split remains open: this global can live in `InterfaceEfx.cpp` with the manager class or in a separate `InterfaceEfxMgr.cpp` if later project-structure evidence favors a manager split.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)
- [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md)
- [UID:0001RE][interface-efx-resources](by-resource/interface-efx-resources.md)
- [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `84/82`.
  - Before: The page had basic singleton lifecycle notes but was unscored and did not link the exact storage aggregate.
  - After: The page records the exact `0x0069b360-0x0069b364` storage context, owner split caveat, and manager helper caveats.
  - Evidence: [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md) documents the slot and xrefs; IDA xrefs tie the slot to the `InterfaceEfxMgr` constructor, trigger helper consumers, clear helper, destructor, and main UI shutdown.
- 2026-06-05: Marked reconstructable under [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md). Evidence: live IDA MCP reports seven xrefs to `0x0069b360`; decompilation confirms constructor `0x004e9d00`, clear helper `0x004ea060`, and scalar deleting destructor `0x004ea090` write/clear `dword_69B360`.
- 2026-06-06: Synced [UID:00018I][0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks](by-memory/0x004ea060-0x004ea081.InterfaceEfxMgrSingletonAndThunks.md) after live IDA corrected the third adjustor endpoint from `0x004ea080` to `0x004ea081`; singleton ownership and score were unchanged.
- 2026-06-07: Raised to `85/86` during Batch 039 parent-gate follow-up after splitting exact storage [UID:0002VQ][0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage](by-memory/0x0069b360-0x0069b364.g_pInterfaceEfxMgrStorage.md). The parent now satisfies the corrected `85/85` gate for the storage child.
