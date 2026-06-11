*** UID:0001XA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Command Input Pane Vtable Family

## Status

- Entity kind: vtable family inventory.
- Covered modules: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), with adjacent [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) and [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) boundary evidence.
- Confidence: strong for table bases and `+0x00`/`+0xa0`/`+0xa4` layout; medium for projected constructor starts that IDA does not materialize as functions.
- Evidence basis: IDA MCP `list_globals` and `xrefs_to` checks on 2026-05-26; current `simroot_v2` metadata checks. Wave3-generated metadata is treated as provisional only.
- Rebuild handling: `source-declared/generated-binary`; the class declarations and virtual methods must be reconstructed, while the vtable bytes are compiler-emitted from those declarations.

## Exact Vtable Data Pages

| Exact page | Covered classes | Notes |
| --- | --- | --- |
| [UID:0002N4][0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData](by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md) | `EmotionInputPane` | Three-view table ending before `ChangeItemSlotInputPane` RTTI. |
| [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md) | `ChangeSpellSlotInputPane` | Spell-domain prompt table preserved here as adjacent boundary evidence. |
| [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md) | `GroupInputPane`, `PostInputPane` | Contiguous command-input table cluster with IDA-confirmed store xrefs. |
| [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md) | `SpellSpellInputPane` | Spell-domain prompt table preserved here as adjacent boundary evidence. |
| [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) | `SelfSaveInputPane` | Self-save table ending before block-list prompt RTTI. |
| [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md) | `BlockListenInputPane`, `AddToBlockListenInputPane`, `DeleteFromBlockListenInputPane` | Block-list prompt table cluster ending before following wide/string data. |

## Core Command Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md) | `0x0062f9b8` | `0x0062fa08` | `0x0062fa38` | Constructor stores at `0x005b2a03`, `0x005b2a09`, and `0x005b2a13`. |
| [UID:00005W][GroupInputPane](by-class/GroupInputPane.md) | `0x006300d4` | `0x00630124` | `0x00630154` | Command dispatcher stores at `0x005a66c4`, `0x005a66cc`, and `0x005a66d6`; open helper stores at `0x005a9a66`, `0x005a9a6c`, and `0x005a9a76`; raw/projected constructor bytes store at `0x005b541f`, `0x005b5427`, and `0x005b5431`. |
| [UID:0000AO][PostInputPane](by-class/PostInputPane.md) | `0x00630160` | `0x006301b0` | `0x006301e0` | Command dispatcher stores at `0x005a6718`, `0x005a671e`, and `0x005a6728`; open helper stores at `0x005a9aeb`, `0x005a9af1`, and `0x005a9afb`; constructor stores at `0x005b5677`, `0x005b567d`, and `0x005b5687`. |
| [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) | `0x006305c0` | `0x00630610` | `0x00630640` | Factory/open helper stores at `0x005aa196`, `0x005aa19c`, and `0x005aa1a6`; raw/projected constructor bytes store at `0x005b67df`, `0x005b67e7`, and `0x005b67f1`. |

## Adjacent Domain Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md) | `0x0063041c` | `0x0063046c` | `0x0063049c` | Command dispatcher stores at `0x005a6ac2`, `0x005a6ac8`, and `0x005a6ad2`; spell open helper stores at `0x005a9e78`, `0x005a9e7e`, and `0x005a9e88`; constructor stores at `0x005b6167`, `0x005b616d`, and `0x005b6177`. Stronger source owner remains [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md). |
| [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md) | `0x0062fad0` | `0x0062fb20` | `0x0062fb50` | Raw/projected constructor bytes store at `0x005b323f`, `0x005b3247`, and `0x005b3251`; submit slot `+0x48 -> 0x005b32d0`; key slot `+0x58` / secondary `+0x08 -> 0x005b3260`. Stronger source owner remains [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md). |
| [UID:00000X][BlockListenInputPane](by-class/BlockListenInputPane.md) | `0x0063064c` | `0x0063069c` | `0x006306cc` | Command dispatcher stores at `0x005a72af`, `0x005a72b7`, and `0x005a72c1`; open helper stores at `0x005aa336`, `0x005aa33c`, and `0x005aa346`; raw/projected constructor bytes store at `0x005b68df`, `0x005b68e7`, and `0x005b68f1`. Stronger source owner remains [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md). |
| [UID:00000A][AddToBlockListenInputPane](by-class/AddToBlockListenInputPane.md) | `0x006306d8` | `0x00630728` | `0x00630758` | `BlockListenInputPane` command dispatcher stores at `0x005b6b0a`, `0x005b6b10`, and `0x005b6b1a`; raw/projected constructor bytes store at `0x005b6c9f`, `0x005b6ca7`, and `0x005b6cb1`. |
| [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md) | `0x00630764` | `0x006307b4` | `0x006307e4` | `BlockListenInputPane` command dispatcher stores at `0x005b6bd5`, `0x005b6bdb`, and `0x005b6be5`; raw/projected constructor bytes store at `0x005b711f`, `0x005b7127`, and `0x005b7131`. |

## Shared Slot Notes

- These command/social prompt panes use the same three-view pane layout as the direct item-action input panes: primary vfptr at `+0x00`, secondary view at `+0xa0`, and tertiary view at `+0xa4`.
- The primary slot for this neighborhood usually points at scalar deleting destructor `0x005b7940`, while the secondary and tertiary first slots point at [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md) `0x005b77c8` and `0x005b77d3`.
- `0x005a5bd0` is a large `UserPane` command/key dispatcher that constructs many prompt panes. Its vtable stores are strong allocation evidence, but the dispatcher itself should stay with [UID:0000P1][UserPane](by-file/UserPane.md).
- This page is a layout anchor only. It does not by itself prove every table listed here belongs in one original source file.
- 2026-05-31 IDA MCP recheck confirms the vtable base labels, constructor/factory/dispatcher store xrefs, and first slot values for the command, spell-adjacent, self-save, and block-list table groups. It also confirms several projected raw constructor stores are not IDA function starts, so those boundary caveats remain active.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for each checked command/social input pane even though IDA confirms the bases listed above:

`EmotionInputPane`, `GroupInputPane`, `PostInputPane`, `SelfSaveInputPane`, `SpellSpellInputPane`, `ChangeSpellSlotInputPane`, `BlockListenInputPane`, `AddToBlockListenInputPane`, and `DeleteFromBlockListenInputPane`.

Use this page as the vtable/layout anchor until generated metadata records those tables.

## Reconstruction Notes

The vtable inventory strengthens the binary-level grouping of the command-input neighborhood from `EmotionInputPane` through `SelfSaveInputPane`, while preserving feature-owned splits for spell and block-list prompt code. `SpellSpellInputPane` should remain under spell-input review, and the block-list trio should remain under the social block-list module unless later source-level evidence shows the original developers kept all typed command prompts in one `CommandInputPanes.cpp` file.

Raw/projected constructor starts such as `0x005b5400`, `0x005b67c0`, `0x005b68c0`, `0x005b6c80`, and `0x005b7100` should stay documented as constructor-shaped bytes but should not be used as IDA function-boundary anchors until reconciled.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md)
- [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)
- [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- [UID:0001MK][0x005b5630-0x005b5830.PostInputPane](by-memory/0x005b5630-0x005b5830.PostInputPane.md)
- [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- [UID:0001M8][0x005b3220-0x005b340e.ChangeSpellSlotInputPane](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md)
- [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md)
- [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-05-31 exact vtable-data split:
  - What existed before: the page had `COMPLETION:0`, `CONFIDENCE:0`, blank reconstructable metadata, and depended on the broad [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md) aggregate for `.rdata` coverage.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and six exact by-memory vtable-data child pages for the command/spell-adjacent/self-save/block-list prompt tables.
  - Summary/evidence: 2026-05-31 IDA MCP `xrefs_to`, `lookup_funcs`, and `py_eval` verify the table bases, vtable labels, store xrefs, representative slot values, and exact boundary dwords; final score remains below `95+` because source-file grouping and raw constructor boundaries are not fully resolved.
