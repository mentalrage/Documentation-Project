*** UID:0000ID | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CommandInputPanes

## Status

- Confidence: medium-high for a shared command-input source module; strong for the individual class behaviors and IDA-confirmed vtable families listed here.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/CommandInputPanes.cpp`
- Possible split files: `ui/dialogs/SocialCommandInputPanes.cpp`, `ui/dialogs/SpellCommandInputPanes.cpp`, [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), and [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Evidence basis: IDA MCP function-boundary, vtable, xref, and raw-byte checks recorded in the linked memory/type pages, plus the current project-documentation source/module map. Use [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md) as the current layout anchor.

## Hypothesis

The direct command input panes around `0x005b29c0-0x005b7553` may have been developed as one command-prompt family built on [UID:00001P][CharInputPane](by-class/CharInputPane.md) and [UID:000077][LineInputPane](by-class/LineInputPane.md). Item actions have enough density to justify [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), while the adjacent emotion, group, post, spell-selection, and block-list prompts may be either a neighboring `CommandInputPanes.cpp` file or small feature-owned files.

Likely feature split:

```text
ui/dialogs/ItemActionInputPanes.cpp
ui/dialogs/CommandInputPanes.cpp
social/BlockListenInputPanes.cpp
```

Possible more granular split:

```text
ui/dialogs/EmotionInputPane.cpp
ui/dialogs/SocialCommandInputPanes.cpp
ui/dialogs/SpellCommandInputPanes.cpp
```

## Proposed Contents

| Entity | Current range | Primary evidence | Role |
| --- | --- | --- | --- |
| [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md) | [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md), helper [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md) | IDA-confirmed constructor/handler/helper and vtable data | Emotion command prompt; maps letter input to emotion indices, opens an emotion menu on help shortcut, and sends opcode `0x1d`. |
| [UID:00005W][GroupInputPane](by-class/GroupInputPane.md) | Raw constructor [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md) plus submit method [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md) | IDA-confirmed raw constructor bytes, submit method, packet layout, and vtables | Line-input group command sender; sends opcode `0x2e` with converted text. |
| [UID:0000AO][PostInputPane](by-class/PostInputPane.md) | [UID:0001MK][0x005b5630-0x005b5830.PostInputPane](by-memory/0x005b5630-0x005b5830.PostInputPane.md), true documented range `0x005b5630-0x005b5890` | IDA-confirmed constructor/key/confirm methods, raw opcode `0x34` helper, packet sender path, and vtables | Single-letter post selection prompt; sends opcode `0x34`. |
| [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md) | [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md) | IDA-confirmed spell prompt methods and vtables | Spell-selection prompt used by spell-on-spell flows; current stronger placement is [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md). |
| [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) | [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md), factory at `0x005aa140` | IDA-confirmed handler/raw-helper/factory caveats and vtables | Single-character self-save confirmation prompt that sends opcode `0x25` after `y`/`Y`; constructor/factory starts still carry boundary caveats. |
| [UID:00000X][BlockListenInputPane](by-class/BlockListenInputPane.md), [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md), [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md) | [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md) plus adjacent helper/destructor pages | IDA-confirmed block-list handlers, private find helper, and vtable cluster | Block-list command prompts. Current stronger placement is [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), but they remain adjacent to this command-input neighborhood. |

## Boundary And Data Notes

- IDA confirms `EmotionInputPane` starts at `0x005b29c0` and `0x005b2a70`. 2026-05-26 IDA decompilation confirms the input handler reads exactly one character, maps `a-p` through [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md), and builds a localized emotion menu on `?`.
- IDA recheck on 2026-05-26 resolves adjacent helper `0x005b2f70-0x005b2fcb` as [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md), called only by `EmotionInputPane::OnCharInput`. Do not attach that range to `ChangeItemSlotInputPane`.
- 2026-06-02 IDA MCP refresh confirms `EmotionInputPane` constructor callers at `0x005a6138`, `0x005a9390`, and the `?` help/menu reopen path at `0x005b2f38`; `OnCharInput` is a vtable-reached body from slot `0x0062fa00`; `SendEmotionPacket` is called only from `0x005b2aef`, `0x005b2b15`, and `0x005b2f52`.
- The same refresh confirms `0x005b2f68-0x005b2f70` and `0x005b2fcb-0x005b2fd0` are pure `0xcc` alignment spans between the Emotion command cluster, its helper, and the following `ChangeItemSlotInputPane` raw-constructor neighborhood.
- 2026-06-02 IDA MCP refresh resolves `GroupInputPane::GroupInputPane` as raw constructor-shaped bytes at `0x005b5400-0x005b5440`: IDA still reports no function at the start, but disassembly shows prompt id `0x2f`, line-input base construction, and vtable stores to `0x006300d4`, `0x00630124`, and `0x00630154`. The following submit method remains the modeled function `0x005b5440-0x005b5547`.
- `PostInputPane` has clean modeled method ranges plus the raw `0x005b5830-0x005b5890` opcode `0x34` helper. The raw helper has no direct xref to its start, but byte/disassembly review shows it is non-padding Post-owned packet-send code and ends exactly before the item-action `ThrowInputPane` constructor at `0x005b5890`.
- `SpellSpellInputPane` has clean IDA-aligned modeled ranges and now cross-references [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) as the stronger spell-domain owner.
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) is source-structure relevant because it fills the gap immediately before the block-list input pane neighborhood. IDA currently misses its constructor start and the adjacent raw send helper, so use the memory docs before source-placement decisions.
- 2026-05-25 IDA recheck confirms `SelfSaveInputPane` still has raw constructor/helper starts at `0x005b67c0` and `0x005b6870`, a real virtual handler at `0x005b6800`, and a discontiguous factory at `0x005aa140` with no direct callers.
- 2026-05-26 IDA recheck confirms the same SelfSave boundary state; the raw send helper and factory/open helper remain boundary-sensitive and should be checked from the memory docs.
- 2026-05-26 and 2026-06-05 IDA vtable passes confirm three-view vtable groups for `EmotionInputPane`, `GroupInputPane`, `PostInputPane`, and `SelfSaveInputPane`, with adjacent spell/block-list prompt tables recorded in [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md).
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) extends the same command-input neighborhood after `SpellSpellInputPane`; IDA confirms the handlers and private find helper, but constructor starts are non-IDA projected starts.
- These classes sit between or near item-action input panes, but their gameplay ownership differs: emotion/social/spell command routing should not be merged into an item-only source file unless later evidence proves the original source was a broad command-input module.

## Batch 023 Vtable Parent Evidence

Live IDA MCP on 2026-06-07 rechecked `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) for the exact [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md) child:

- `GroupInputPane` still owns the three views at `0x006300d4`, `0x00630124`, and `0x00630154`, with submit slot `0x0063011c -> 0x005b5440`.
- `PostInputPane` still owns the three views at `0x00630160`, `0x006301b0`, and `0x006301e0`, with confirm slot `0x006301a8 -> 0x005b5770` and key slot `0x006301b8 -> 0x005b5700`.
- Store xrefs remain the dispatcher/open-helper/raw-constructor set for `GroupInputPane` and the dispatcher/open-helper/modeled-constructor set for `PostInputPane`.
- The shared range is correctly source-owned by this file root because it spans two command-input prompt classes that are both documented as `CommandInputPanes` contents; no single class page directly owns the whole combined vtable-data child.

This by-file page now meets the corrected `85/85` parent gate for assigning [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md) here. The vtable bytes remain `source-declared/generated-binary`, so the child should stay C++-empty.

## Source Placement Notes

Keep `CommandInputPanes.cpp` as the current `ui/dialogs/` source-root candidate for the emotion/group/post command prompts and as an address-neighborhood cross-reference for spell, self-save, and block-list prompts. Attach only pages whose parent/source-file evidence meets the 80/80 gate. The currently attached PostInputPane class and memory page satisfy that gate; final C++ remains intentionally blank on the attached pages because the relevant functions are below the 95/95 reconstruction-code bar.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md)
- [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md)
- [UID:00005W][GroupInputPane](by-class/GroupInputPane.md)
- [UID:0000AO][PostInputPane](by-class/PostInputPane.md)
- [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)
- [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md)
- [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md)
- [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- [UID:0001MK][0x005b5630-0x005b5830.PostInputPane](by-memory/0x005b5630-0x005b5830.PostInputPane.md)
- [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md)
- [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md)
- [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: command-input family contents, likely split options, vtable anchors, IDA boundary caveats, source-placement notes, and cross-file dependencies are documented; confidence is capped by unresolved grouping between command, spell, item-action, block-list, and social prompt modules.
- 2026-06-02 Emotion attachment refresh:
  - Changed to: `CONFIDENCE:82` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Why: Emotion constructor, virtual input handler, helper, vtable data, caller map, helper-only ownership, and padding boundaries are now IDA-confirmed; confidence remains below `95` because broader command/spell/social split still has unresolved source-file boundaries.
- 2026-06-05 PostInputPane refresh:
  - Changed to: `COMPLETION:84` and `CONFIDENCE:84`.
  - Why: [UID:0001MK][0x005b5630-0x005b5830.PostInputPane](by-memory/0x005b5630-0x005b5830.PostInputPane.md) now records the true Post-owned island through `0x005b5890`, including the raw opcode `0x34` helper at `0x005b5830-0x005b5890`, updated vtable slots/stores, packet sender dependencies, and the exclusive boundary before item-action `ThrowInputPane`.
- 2026-06-07 A003 Batch 023 parent gate:
  - Before: `84/84`, below the corrected direct-parent gate for the combined Group/Post vtable-data child.
  - After: `86/86`, with current hash-backed vtable slot, xref, and boundary evidence for [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md).
  - Summary/evidence: this file page already documents group/post command-input contents, method ranges, packet behavior, source split caveats, and cross-file boundaries; the Batch 023 IDA recheck closes the direct parent gate for the combined vtable child while keeping final-source C++ blocked by wider command/spell/social split questions.
