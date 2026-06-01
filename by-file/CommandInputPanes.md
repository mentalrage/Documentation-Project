*** UID:0000ID | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CommandInputPanes

## Status

- Confidence: medium for a shared command-input source module; strong for the individual class behaviors and IDA-confirmed vtable families listed here.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/CommandInputPanes.cpp`
- Possible split files: `ui/dialogs/SocialCommandInputPanes.cpp`, `ui/dialogs/SpellCommandInputPanes.cpp`, [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), and [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Evidence basis: Wave3 class inspection, generated `simroot_v2` sources, Wave3 method notes, and IDA MCP function-boundary/vtable checks on 2026-05-23 and 2026-05-26. Use [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md) as the current IDA-backed layout anchor.

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

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `EmotionInputPane` | `0x005b29c0-0x005b2f68`, helper `0x005b2f70-0x005b2fcb` | `class_EmotionInputPane.cpp` | Emotion command prompt; maps letter input to emotion indices, opens an emotion menu on help shortcut, and sends opcode `0x1d`. |
| `GroupInputPane` | `0x005b5440-0x005b5547` plus projected `0x005b5400` constructor | `class_GroupInputPane.cpp` | Line-input group command sender; sends opcode `0x2e` with converted text. |
| `PostInputPane` | `0x005b5630-0x005b5830` | `class_PostInputPane.cpp` | Single-letter post selection prompt; sends opcode `0x34`. |
| `SpellSpellInputPane` | [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md) | `class_SpellSpellInputPane.cpp` | Spell-selection prompt used by spell-on-spell flows; current stronger placement is [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md). |
| [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) | `0x005b67c0-0x005b68b0`, factory at `0x005aa140` | `class_SelfSaveInputPane.cpp` | Single-character self-save confirmation prompt that sends opcode `0x25` after `y`/`Y`; current constructor/factory modeling has IDA boundary caveats. |
| [UID:00000X][BlockListenInputPane](by-class/BlockListenInputPane.md), [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md), [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md) | `0x005b68c0-0x005b7553` | generated block-list input files | Block-list command prompts. Current stronger placement is [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), but they remain adjacent to this command-input neighborhood. |

## Boundary And Data Notes

- IDA confirms `EmotionInputPane` starts at `0x005b29c0` and `0x005b2a70`, but Wave3's current emitted `OnCharInput` code is only a helper struct. 2026-05-26 IDA decompilation confirms the missing body reads exactly one character, maps `a-p` through [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md), and builds a localized emotion menu on `?`. Track the emitted-body gap under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- IDA recheck on 2026-05-26 resolves adjacent helper `0x005b2f70-0x005b2fcb` as [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md), called only by `EmotionInputPane::OnCharInput`. Do not attach that range to `ChangeItemSlotInputPane`.
- IDA reports no function at `GroupInputPane::GroupInputPane` projected start `0x005b5400`; the previous IDA function is `0x005b52f0-0x005b538a`, and the next is `0x005b5440-0x005b5547`.
- `PostInputPane` and `SpellSpellInputPane` have clean IDA-aligned ranges. `SpellSpellInputPane` now cross-references [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) as the stronger spell-domain owner.
- [UID:0000NM][SelfSaveInputPane](by-file/SelfSaveInputPane.md) is source-structure relevant because it fills the gap immediately before the block-list input pane neighborhood. IDA currently misses its constructor start and the adjacent raw send helper, so use the memory docs before migration.
- 2026-05-25 IDA recheck confirms `SelfSaveInputPane` still has raw constructor/helper starts at `0x005b67c0` and `0x005b6870`, a real virtual handler at `0x005b6800`, and a discontiguous factory at `0x005aa140` with no direct callers.
- 2026-05-26 IDA recheck confirms the same SelfSave boundary state. Active `class_SelfSaveInputPane.cpp` still omits the raw send helper and factory/open helper.
- 2026-05-26 IDA vtable pass confirms three-view vtable groups for `EmotionInputPane`, `GroupInputPane`, `PostInputPane`, and `SelfSaveInputPane`, with adjacent spell/block-list prompt tables recorded in [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md). Current `simroot_v2` metadata for every checked class still reports `vtable_count: 0`.
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) extends the same command-input neighborhood after `SpellSpellInputPane`; IDA confirms the handlers and private find helper, but constructor starts are non-IDA projected starts.
- These classes sit between or near item-action input panes, but their gameplay ownership differs: emotion/social/spell command routing should not be merged into an item-only source file unless later evidence proves the original source was a broad command-input module.

## Migration Notes

Proposed dry-run sequence after reviewing the data issues:

```powershell
python source-3\wave3.py rename file class_PostInputPane.cpp CommandInputPanes.cpp --dry-run
python source-3\wave3.py set file-simpath CommandInputPanes.cpp ui/dialogs/CommandInputPanes.cpp --dry-run
python source-3\wave3.py attach class EmotionInputPane --file CommandInputPanes.cpp --dry-run
python source-3\wave3.py attach class GroupInputPane --file CommandInputPanes.cpp --dry-run
python source-3\wave3.py attach class PostInputPane --file CommandInputPanes.cpp --dry-run
python source-3\wave3.py attach class SpellSpellInputPane --file CommandInputPanes.cpp --dry-run
```

Do not run these migrations until `EmotionInputPane::OnCharInput` and the `GroupInputPane` constructor boundary are corrected or explicitly marked as projected.

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
- [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- [UID:0001MK][0x005b5630-0x005b5830.PostInputPane](by-memory/0x005b5630-0x005b5830.PostInputPane.md)
- [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md)
- [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: command-input family contents, likely split options, vtable anchors, IDA boundary caveats, omitted/generated-body issues, migration sequence, and cross-file dependencies are documented; confidence is capped by unresolved grouping between command, spell, item-action, block-list, and social prompt modules.
