*** UID:00006X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/BlackHole.h"

// No standalone ItemWhoInputPane class-level source body; exact method and helper children emit this class.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ItemWhoInputPane

## Status

- Confidence: strong for target-selection behavior, saved-target state, exact child method ownership, first-draft child C++ placement, and non-emitting parent-index policy; medium-high for final original helper/event/config spellings.
- Likely source file: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), with item-action cross-references through [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md), destructor [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md), object-list virtual [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md)
- Current recovered file: `source-3/simroot_v2/class_ItemWhoInputPane.cpp`

## Class Purpose

`ItemWhoInputPane` is a target-selection input pane used by the use-on-target flow. It accepts a typed target name or mouse-selected map object, tracks the current selected target, and sends a use-item-on-object packet for the stored inventory slot and target object.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| [UID:0002S1][0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor](by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md) | `0x005aec60-0x005aed3d` | Source constructor `ItemWhoInputPane::ItemWhoInputPane(unsigned char itemSlot)`; builds the line-input prompt using [UID:0003J5][0x00630af0-0x00630b10.ItemWhoTargetPromptString](by-memory/0x00630af0-0x00630b10.ItemWhoTargetPromptString.md), stores `m_itemSlot` at full-object `+0x108`, initializes `s_itemWhoTargetId`, validates/falls back to the local-player object, and highlights the initial target. |
| [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md) | `0x005aed40-0x005aedcb` | Source destructor `ItemWhoInputPane::~ItemWhoInputPane()`; restores vtables, copies ItemWho saved target state into the SpellWho slot under the target-save config byte, clears `ItemWhoInputPaneState::SetInputModeFlag(false)`, and calls base cleanup. |
| [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md) | `0x005aedd0-0x005aefaf` | Source key handler `ItemWhoInputPane::OnKeyEvent`, vtable slot `0x0062f2f4`; handles Enter/Escape, self-target selection, previous/next target navigation including modifier-bit `0x04` alternate traversal, highlight updates, and use-on-target dispatch through `m_itemSlot`. |
| [UID:0002S3][0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput](by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md) | `0x005af050-0x005af2e7` | Source mouse handler `ItemWhoInputPane::OnMouseEvent`, vtable slot `0x0062f2f0`; handles subtype `1` hit-test/selection and subtype `2` confirmation, map-coordinate conversion, target-click/double-click policy, pending-target clear, packet send, and deferred pane deletion. |
| [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md) | `0x005af2f0-0x005af383` | Source object-list virtual `ItemWhoInputPane::OnObjectListMessage`, vtable slot `0x0062f2fc`; scans underscore-prefixed object-list payloads and retargets to the local player when the saved ItemWho target appears in the payload. |
| [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md) | `0x005af390-0x005af3af` | File-local `ClearItemWhoTarget()` helper in `TargetSelectionInputPanes.cpp`; no receiver, resolves `s_itemWhoTargetId`, and clears the target highlight. |
| [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) | `0x005af3b0-0x005af4ef` | Raw source-authored helper island for previous/up, next/down, and local-player ItemWho retargeting. B002 current MCP route checks found no direct xrefs/code refs/data refs/immediates/VA/RVA pointer hits to the helper starts, so the page emits only a formal covered-by marker to [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md), whose active key-handler C++ already contains the equivalent inline behavior. |
| [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md) | `0x005b7a20-0x005b7aec` | Non-emitting compiler scalar deleting destructor wrapper / rebuild-recognition page. Current B008 MCP evidence confirms vtable restores, duplicated source destructor cleanup, scalar delete/free/guard behavior, adjustor thunk/vtable refs, and no ordinary source caller route; source destructor C++ remains on [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md). |

## Field And State Names

| Binary item | Source-facing name | Confidence | Notes |
| --- | --- | --- | --- |
| full object `+0x108` | `m_itemSlot` | strong | Stored by the constructor and inline inventory launcher; key/mouse confirmation sends it through `SendObjectActionPacket`. |
| `dword_69BF24` | `s_itemWhoTargetId` / `s_itemWhoSavedTargetId` | strong | File-scope saved ItemWho target id. Existing project alias `g_savedItemWhoTargetObjectId` remains behaviorally correct but is less source-local. |
| `dword_69BF20` | `s_spellWhoTargetId` / `s_spellWhoSavedTargetId` | strong | Neighbor SpellWho saved target id copied to/from ItemWho under the target-save config byte. |
| `dword_67A7C8+0x28de6c` | `saveTargetOnClose` / `shareSpellItemTargetOnClose` | medium-high | Constructor/destructor target-sharing byte; not the mouse double-click option. |
| `dword_67A7C8+0x28de5a` | `doubleClick` / target-click policy | strong | Mouse handler immediate send-vs-select gate. |

## Emission Policy

[UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md) is a non-emitting split index. Do not put aggregate C++ on the parent page. Source C++ belongs to exact method/helper pages: constructor, non-deleting destructor, key handler, mouse handler, object-list virtual, and file-local `ClearItemWhoTarget`. The raw navigation helper island remains a reconstructable support page with a formal covered-by marker to the key handler, not callable helper-body C++; [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md) is a non-emitting compiler scalar-delete wrapper with blank formal C++ and no covered-by marker.

## Evidence Notes

- Existing generated source shows calls to map hit-test/lookup helpers, target-id globals, and item/action packet dispatch; use it only as context, not authority.
- IDA MCP confirms the constructor, key handler, mouse handler, thunks at `0x005b780a`/`0x005b7815`, object-list virtual, clear helper, and scalar deleting destructor.
- IDA recheck on 2026-05-26 confirms `0x005aed40` as the non-deleting destructor and `0x005af2f0` as a vtable-dispatched object-list helper. Wave3 active output still lacks stable owners for those two functions.
- The 2026-05-24 target-selection pass identifies `0x005af390` as the saved-item-target clear helper.
- The 2026-06-02 IDA MCP refresh verifies exact function sizes, vtable/data refs, `dword_69BF24` refs across constructor/destructor/key/mouse/object-list/clear/scalar-dtor code, callee maps, and padding/switch-table bytes. This raises source placement to the [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) attachment threshold.
- The 2026-06-05 split child pages document exact constructor/key/mouse/scalar-destructor body evidence at `86/90`, including vtable slots, saved-target globals `dword_69BF20`/`dword_69BF24`, local-player fallback [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748`, map-object lookup/traversal helpers, highlight toggles, and item/action dispatch through [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md).
- [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) now records the unmodeled raw navigation island between [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md) and [UID:0001L9][0x005af4f0-0x005af57b.SendTargetedActionPacket](by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md), so the class inventory no longer treats target navigation as only a key/mouse inline behavior.
- 2026-06-29 B008 UID0002S4 implementation callback keeps the class score unchanged while recording [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md) as non-emitting compiler scalar-delete support. MCP session `279422f0` confirms exact range `0x005b7a20-0x005b7aec`, size `0xcc` (`204` decimal, Verified with `int_convert.py`), four-byte padding, vtable restores, saved-target/state-clear/base-cleanup parity with the source destructor, scalar-delete free/guard branch, adjustor thunk/vtable refs, and no ordinary source caller route. Destructor source C++ stays on [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md).
- 2026-06-27 B002 accepted callback confirms [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) is still directly owned by this class but has no direct helper-start route. Its formal C++ is the covered-by marker to [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md), not separate callable helper bodies.
- 2026-06-12 A002 Batch 335 live IDA MCP reconfirmed the class-owned prompt literal split [UID:0003J5][0x00630af0-0x00630b10.ItemWhoTargetPromptString](by-memory/0x00630af0-0x00630b10.ItemWhoTargetPromptString.md). `xrefs_to 0x00630af0` reports the out-of-line constructor xref at `0x005aecb4` and an inline construction sequence in [UID:0001KN][0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot](by-memory/0x005a3e30-0x005a3ff3.UserPaneUseInventorySlot.md) at `0x005a3f55`; both decompiles set the prompt with `sub_4F20A0(&off_630AF0)`, install `ItemWhoInputPane` vtables, and store the item/action byte at `+0x108` / 264 (Verified with int_convert.py).
- 2026-06-22 B013 source-quality reanalysis upgrades the class inventory from behavior-only to source-draft placement: child pages now carry first-draft C++ for `ItemWhoInputPane::ItemWhoInputPane(unsigned char itemSlot)`, `~ItemWhoInputPane`, `OnKeyEvent`, `OnMouseEvent`, `OnObjectListMessage`, and file-local `ClearItemWhoTarget()`. The broad [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md) parent is now explicitly non-emitting.

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
- [UID:0003J5][0x00630af0-0x00630b10.ItemWhoTargetPromptString](by-memory/0x00630af0-0x00630b10.ItemWhoTargetPromptString.md)

## Changes

- 2026-06-29 B005 UID0000OH direct empty-emitter callback:
  - Score unchanged at `88/90`.
  - Summary/evidence: inserted the accepted formal no-standalone class marker with `[[CHILDREN]]` so child method/helper bodies still emit through this class. This page remains the direct class owner under [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md); exact ItemWho source bodies continue to emit from constructor/destructor/key/mouse/object-list/clear/raw-helper child pages, and no separate class-level source body is required.
- 2026-06-29 B008 UID0002S4 scalar-wrapper implementation callback:
  - Score unchanged at `88/90`.
  - Evidence: updated the UID0002S4 row and emission policy to classify [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md) as non-emitting compiler scalar-delete support owned by ItemWhoInputPane for review/rebuild recognition only. Preserved [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md) as the source destructor C++ home and preserved scalar-wrapper separation for vtable restores, base cleanup, delete flags, free/guard behavior, and adjustor thunk reachability.
- 2026-06-27 B002 accepted `0002S5` raw-helper callback:
  - Score unchanged at `88/90`.
  - Evidence: updated the raw-helper method row and emission policy to match the current MCP-backed no-route proof and the target page's formal covered-by marker to [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md). This preserves [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md) ownership without inventing standalone helper calls.
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
- 2026-06-12 A002 Batch 335 prompt-literal routing:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`; the class was just below the strict child/parent routing gate for the exact `Which target?` prompt literal.
  - After: `COMPLETION:85`, `CONFIDENCE:87`; added the exact prompt-string child and live IDA inline/out-of-line constructor evidence.
  - Evidence: live IDA confirmed `0x00630af0` has exactly two xrefs, both constructing `ItemWhoInputPane` prompt state, so [UID:0003J5][0x00630af0-0x00630b10.ItemWhoTargetPromptString](by-memory/0x00630af0-0x00630b10.ItemWhoTargetPromptString.md) can attach directly to this class.
- 2026-06-22 B013 Rule 26 source-quality incorporation:
  - Before: `85/87`, with exact child evidence but no class-level source-draft policy.
  - After: `88/90`, with source-facing method/field/global names, vtable-slot mapping, first-draft child C++ placement, and explicit parent-index no-emission policy.
  - Evidence: B013 reanalysis of the ItemWho cluster, saved-target globals, inventory inline-construction path, MapPane traversal/hit-test helpers, state helper, vtables, and scalar deleting wrapper.
