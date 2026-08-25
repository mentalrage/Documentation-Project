*** UID:0000R0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel;

GeneralPurposePanel *g_pGeneralPurposePanel = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pGeneralPurposePanel

## Status

- Confidence: very strong for address, linkage, one-definition route, lifetime, and complete 87-reference inventory.
- Address: `0x0067a874`
- IDA name: `dword_67A874`
- Proposed owner file: [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)

## Symbol Role

`g_pGeneralPurposePanel` is the sole source-authored, externally linked typed pointer definition for the active seven-child in-game side-panel shell. Its source initializer is zero. [UID:00028X][0x0067a874-0x0067a878.g_pGeneralPurposePanel](by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md) is only the four-byte loader-zeroed physical slot and remains false/non-emitting, preventing duplicate definitions.

Compiler lowering of the direct `Singleton<GeneralPurposePanel>` base publishes and clears the pointer during construction, ordinary destruction, constructor unwind, and scalar deletion. Map, user, inventory, spell, item, dialog, input, screen, macro, status, and FrameChrome code read the externally visible pointer to fetch or switch side-panel children.

The field at object offset `+0x20` is the accepted source-facing `m_activeChildIndex` member. Decompilation presents it as `this[8]` because the object is treated as a dword array in raw output. FrameChrome consumes this field while constructing the dynamic right-edge `AboveFrame` piece: [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) builds `AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)`.

## Evidence

- [UID:0004UL][0x004b83d0-0x004b857e.GeneralPurposePanelConstructor](by-memory/0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md) publishes the null-adjusted complete object at `0x004b8412`/`0x004b8419` as direct-Singleton compiler lowering.
- [UID:0004UM][0x004b8580-0x004b85e3.GeneralPurposePanelDestructor](by-memory/0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md) clears it at `0x004b85c6` through implicit Singleton base destruction after seven authored child-deletion requests.
- [UID:00015Z][0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers](by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md) at `0x004b8a90` is the constructor-unwind Singleton base destructor, and [UID:0004UN][0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor](by-memory/0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor.md) contains the compiler scalar clear at `0x004b8b91`.
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) is called through this global from the map packet dispatcher and many input/menu paths.
- [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) are called through this global to fetch self-look, user-look, inventory, spell, group, collection, and option panes.
- [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md) reads this singleton at `0x005593f1` and calls [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) `GeneralPurposePanel::DispatchActiveChildRefresh()` at `0x005593fc` after refreshing the active map pane for a palette change.
- [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) reads `g_pGeneralPurposePanel->m_activeChildIndex` through raw `dword_67A874 + 0x20` at `0x0046140d` and `0x00461610`; this is a consumer of the panel state, not FrameChrome ownership of the singleton.
- MCP returned exactly 87 refs with `more:false`: five compiler/template lifetime writes and 82 reads. No consumer writes or defines a second pointer.
- The exact physical bytes are four loader-zeroed bytes with SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`; the historical `0xffffffff` interpretation is superseded because the target RVA lies in the PE `.data` virtual tail beyond raw payload.
- Decorated RTTI, CHD entries, Singleton PMD `{4,-1,0}`, 0x24-byte allocations, and the exact field layout prove direct `LObject` plus `Singleton<GeneralPurposePanel>` inheritance and EBO over `m_childPanes[0]`.

## Ownership Notes

Keep the one typed definition at position 0 in `NexusTK/ui/panels/GeneralPurposePanel.cpp`. [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md) supplies the single matching `extern` declaration after its complete class declaration. Caller names around shared side-panel helpers are not ownership evidence; 82 reads require external linkage but do not move the definition. A file-local static, function-local accessor, duplicate physical-page initializer, AutoInit object, or consumer-owned definition is rejected by the cross-translation-unit read inventory and exact lifetime island.

## Score Rationale

Completion/confidence are `92/94`: exact address/bytes, zero initializer, external linkage, one definition plus one declaration, all 87 refs, five compiler/template writes, 82 reads, direct Singleton hierarchy/EBO, exact lifecycle children, and source position are resolved. Original header filename and template spelling remain inferred caps below final certainty.

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)
- [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md)
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md)

## Changes

- 2026-07-20 B002 UID00028X accepted callback: raised `88/86 -> 92/94`, set source position 0, installed the sole typed zero definition, incorporated complete lifetime/ref/linkage/PE/RTTI/EBO/one-definition evidence, linked real constructor/destructor/scalar children, and historicalized the stale `0xffffffff`/manual-publication interpretation.
- 2026-07-20 B001 UID0001NM bounded support synchronization: current canonical singleton UID is `0000R0` (the accepted report's `0000RO` token was a coordination typo). The EPF status-payload path reads this singleton and calls `GetChildPaneByIndex(2)->OnActivate(NULL)` only when UserStatusPane's inventory-slot-count byte changes. This is exact consumer behavior; it preserves GeneralPurposePanel.cpp ownership, lifecycle, score, formal disposition, seven-child mapping, and unrelated callers.
- 2026-06-20 B003 AboveFrame source-quality implementation: added the accepted source-facing field inference for object offset `+0x20` / raw `this[8]` as `m_activeChildIndex`, and documented the FrameChrome dynamic `AboveFrame` consumer. Owner/emitter stay with [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md).
- 2026-06-21 B007 ScreenPane palette-helper support sync: added [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md) as a representative consumer that dispatches `GeneralPurposePanel::DispatchActiveChildRefresh()` after PaletteLib/active MapPane refresh. Owner/emitter unchanged.
- 2026-06-20 B006 Rule 26 reconciliation: score unchanged; reconfirmed that FrameChrome reads `m_activeChildIndex` only as input to `AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)`. This global remains owned by `GeneralPurposePanel`, not FrameChrome.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/86`. Summary/evidence: the page documents address, owner, singleton role, constructor/destructor/clear-helper evidence, broad reader behavior, child accessors, active-tab switching, ownership notes, and refs.
- 2026-06-05: Marked reconstructable under [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md). Evidence: live IDA MCP reports 87 xrefs to `0x0067a874`; decompilation confirms constructor `0x004b83d0`, destructor `0x004b8580`, clear helper `0x004b8a90`, and scalar deleting destructor `0x004b8b40` write/clear `dword_67A874` in the panel lifecycle.
