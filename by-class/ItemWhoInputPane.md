*** UID:00006X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemWhoInputPane

## Status

- Confidence: strong for target-selection behavior, saved-target state, and exact child method ownership; medium-high for final source-level helper names and the broader file split.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), with item-action cross-references through [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md), destructor [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md), object-list virtual [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md)
- Current recovered file: `source-3/simroot_v2/class_ItemWhoInputPane.cpp`

## Class Purpose

`ItemWhoInputPane` is a target-selection input pane used by the use-on-target flow. It accepts a typed target name or mouse-selected map object, tracks the current selected target, and sends a use-spell-or-item packet for the stored slot/target.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0002S1][0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor](by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md) | `0x005aec60-0x005aed3d` | Builds the line-input prompt, stores the item/action byte at object offset `+0x108`, initializes saved target state from the item-target globals, validates the selected map object, and highlights the initial target. |
| Non-deleting destructor | `0x005aed40-0x005aedcb` | Restores vtables, reconciles saved target state, clears item target input-mode state, and calls base cleanup. |
| [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md) | `0x005aedd0-0x005aefaf` | Handles Enter/Escape, self-target selection, previous/next target navigation, highlight updates, and use-on-target dispatch through the stored item/action byte. |
| [UID:0002S3][0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput](by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md) | `0x005af050-0x005af2e7` | Handles map-coordinate mouse hover/selection, saved-target highlight changes, optional immediate send/close behavior, and use-on-target dispatch. |
| Object-list virtual | `0x005af2f0-0x005af383` | Handles underscore-prefixed object-list payloads for saved item target state. |
| [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) | `0x005af3b0-0x005af4ef` | Raw source-authored helper island for previous/next/local-player target navigation; IDA does not model the starts as functions. |
| [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md) | `0x005b7a20-0x005b7aec` | Scalar deleting destructor that restores vtables, reconciles saved item-target globals, clears the active item-target state flag, and handles delete flags. |

## Evidence Notes

- Existing generated source shows calls to map hit-test/lookup helpers, target-id globals, and item/action packet dispatch; use it only as context, not authority.
- IDA MCP confirms the constructor, key handler, mouse handler, thunks at `0x005b780a`/`0x005b7815`, object-list virtual, clear helper, and scalar deleting destructor.
- IDA recheck on 2026-05-26 confirms `0x005aed40` as the non-deleting destructor and `0x005af2f0` as a vtable-dispatched object-list helper. Wave3 active output still lacks stable owners for those two functions.
- The 2026-05-24 target-selection pass identifies `0x005af390` as the saved-item-target clear helper.
- The 2026-06-02 IDA MCP refresh verifies exact function sizes, vtable/data refs, `dword_69BF24` refs across constructor/destructor/key/mouse/object-list/clear/scalar-dtor code, callee maps, and padding/switch-table bytes. This raises source placement to the [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) attachment threshold.
- The 2026-06-05 split child pages document exact constructor/key/mouse/scalar-destructor body evidence at `86/90`, including vtable slots, saved-target globals `dword_69BF20`/`dword_69BF24`, local-player fallback [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748`, map-object lookup/traversal helpers, highlight toggles, and item/action dispatch through [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md).
- [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) now records the unmodeled raw navigation island between [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md) and [UID:0001L9][0x005af4f0-0x005af57b.SendTargetedActionPacket](by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md), so the class inventory no longer treats target navigation as only a key/mouse inline behavior.

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md)
- [UID:0002S1][0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor](by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md)
- [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md)
- [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md)
- [UID:0002S3][0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput](by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md)
- [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md)
- [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md)
- [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md)
- [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md)
- [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)
- [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md)
- [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Changes

- 2026-06-07 A005 resolved-name cleanup:
  - Before: local-player fallback evidence used only historical `dword_67A748`.
  - After: the page records canonical `g_pCollectionData` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A748` to `g_pCollectionData`; existing split-child evidence already ties the reference to local-player fallback and item target dispatch.
- Completion/confidence score update: existed before as `0/0`; changed to `80/80`. Summary: target-selection input role, constructor/destructor/key/mouse/object-list/scalar-destructor methods, target-state helper relationship, packet dispatch, and Wave3 owner gaps are documented; confidence remains limited by final source-file placement between target-selection and item-action modules. Evidence: `ItemWhoInputPane`, `ItemWhoInputPaneDestructor`, `ItemWhoInputPaneObjectListVirtual`, `TargetSelectionInputPanes`, `ItemActionInputPanes`, and related target-input classes.
- 2026-06-02 source attachment update:
  - Before: reconstructable/autogen metadata was blank and the likely source file was left split between target-selection and item-action modules.
  - After: marked reconstructable and attached to [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), while retaining [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) as a cross-reference.
  - Evidence: IDA MCP confirms the same target-selection map/highlight/object-list/global-state patterns as `SpellWhoInputPane`, with item-action behavior isolated to the packet dispatch arguments.
- 2026-06-07 A009 exact-child inventory sync:
  - Before: the class method table still used broad address-only rows for constructor/key/mouse/scalar-destructor behavior and did not list the raw target-navigation helper island, even though exact child pages already contained stronger body-level evidence.
  - After: raised scores to `84/86`, linked the exact constructor/key/mouse/scalar-destructor child pages, added [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) to the inventory, and refreshed evidence notes around saved-target globals, local-player fallback, highlight toggles, and item/action dispatch. Final C++ remains blank.
  - Evidence: [UID:0002S1][0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor](by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md), [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md), [UID:0002S3][0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput](by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md), [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md), and [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) already record the exact IDA-backed body evidence.
