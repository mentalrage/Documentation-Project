*** UID:0001XA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Command Input Pane Vtable Family

## Status

- Entity kind: non-emitting mixed-owner vtable family inventory.
- Covered modules: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), with adjacent [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) and [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) boundary evidence.
- Confidence: strong for table bases, exact child ranges, owner split, and `+0x00`/`+0xa0`/`+0xa4` layout; medium for projected constructor starts that IDA does not materialize as functions.
- Evidence basis: IDA MCP `entity_query`, `trace_data_flow`, byte reads, and offset conversion checks through 2026-06-12. Wave3-generated metadata is treated as provisional only.
- Rebuild handling: this aggregate is not reconstructable/emitting because it crosses multiple direct owners. The split source-local vtable pages below are reconstructable documentation for compiler-emitted vtable artifacts generated from the owning class/source declarations.

## Exact Vtable Data Pages

| Exact page | Covered classes | Notes |
| --- | --- | --- |
| [UID:0002N4][0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData](by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md) | `EmotionInputPane` | Three-view table now assigned to the direct class parent after [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md) reached `85/86`; ends before `ChangeItemSlotInputPane` RTTI. |
| [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md) | `ChangeSpellSlotInputPane` | Spell-domain prompt table preserved here as adjacent boundary evidence. |
| [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md) | `GroupInputPane`, `PostInputPane` | `92/94`; exact 69-cell contiguous cluster with all six views, five in-range locator cells, complete COL/RTTI graphs, construction stores, and compiler-marker disposition. |
| [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md) | `SpellSpellInputPane` | Spell-domain prompt table preserved here as adjacent boundary evidence. |
| [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) | `SelfSaveInputPane` | Self-save table ending before block-list prompt RTTI. |
| [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md) | `BlockListenInputPane`, `AddToBlockListenInputPane`, `DeleteFromBlockListenInputPane` | Block-list prompt table cluster ending before following wide/string data. |

## Source-Local Split Pages

| Split page | Direct parent | Parent gate | Backing data |
| --- | --- | ---: | --- |
| [UID:0003HI][EmotionInputPaneVtables](by-type/by-vtable/EmotionInputPaneVtables.md) | [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md) | `85/86` | [UID:0002N4][0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData](by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md) |
| [UID:0003HJ][ChangeSpellSlotInputPaneVtables](by-type/by-vtable/ChangeSpellSlotInputPaneVtables.md) | [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md) | `86/86` | [UID:0002N5][0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData](by-memory/0x0062fad0-0x0062fb58.ChangeSpellSlotInputPaneVtableData.md) |
| [UID:0003HK][GroupPostInputPaneVtables](by-type/by-vtable/GroupPostInputPaneVtables.md) | [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) | type `91/94`; parent `91/93` | [UID:0002N6][0x006300d4-0x006301e8.GroupPostInputPaneVtableData](by-memory/0x006300d4-0x006301e8.GroupPostInputPaneVtableData.md) |
| [UID:0003HL][SpellSpellInputPaneVtables](by-type/by-vtable/SpellSpellInputPaneVtables.md) | [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md) | `86/86` | [UID:0002N7][0x0063041c-0x006304a4.SpellSpellInputPaneVtableData](by-memory/0x0063041c-0x006304a4.SpellSpellInputPaneVtableData.md) |
| [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md) | [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) | `85/86` | [UID:0002N8][0x006305c0-0x00630648.SelfSaveInputPaneVtableData](by-memory/0x006305c0-0x00630648.SelfSaveInputPaneVtableData.md) |
| [UID:0003HN][BlockListenInputPaneFamilyVtables](by-type/by-vtable/BlockListenInputPaneFamilyVtables.md) | [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) | `85/89` | [UID:0002N9][0x0063064c-0x006307ec.BlockListenInputPaneVtableData](by-memory/0x0063064c-0x006307ec.BlockListenInputPaneVtableData.md) |

## Core Command Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md) | `0x0062f9b8` | `0x0062fa08` | `0x0062fa38` | Constructor stores at `0x005b2a03`, `0x005b2a09`, and `0x005b2a13`. |
| [UID:00005W][GroupInputPane](by-class/GroupInputPane.md) | `0x006300d4` | `0x00630124` | `0x00630154` | Command dispatcher stores at `0x005a66c4`, `0x005a66cc`, and `0x005a66d6`; open helper stores at `0x005a9a66`, `0x005a9a6c`, and `0x005a9a76`; raw/projected constructor bytes store at `0x005b541f`, `0x005b5427`, and `0x005b5431`. |
| [UID:0000AO][PostInputPane](by-class/PostInputPane.md) | `0x00630160` | `0x006301b0` | `0x006301e0` | Command dispatcher stores at `0x005a6718`, `0x005a671e`, and `0x005a6728`; open helper stores at `0x005a9aeb`, `0x005a9af1`, and `0x005a9afb`; constructor stores at `0x005b5677`, `0x005b567d`, and `0x005b5687`. |
| [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) | `0x006305c0` | `0x00630610` | `0x00630640` | Factory/open helper stores at `0x005aa196`, `0x005aa19c`, and `0x005aa1a6`; raw/projected constructor bytes store at `0x005b67df`, `0x005b67e7`, and `0x005b67f1`. |

## 2026-08-14 Group/Post Six-View Closure

- Group views are primary `0x6300d4`, EventHandler `0x630124`, and TimerHandler `0x630154`. Their COLs are `0x653334/0x653394/0x6533a8`, PMD offsets `0/+0xa0/+0xa4`, type descriptor `0x67a128`, CHD `0x653348`, and seven bases: Group, LineInputPane, Pane, GrafPort, LObject, EventHandler, TimerHandler.
- Post views are primary `0x630160`, EventHandler `0x6301b0`, and TimerHandler `0x6301e0`. Their COLs are `0x6533bc/0x653420/0x653434`, PMD offsets `0/+0xa0/+0xa4`, type descriptor `0x67a148`, CHD `0x6533d0`, and eight bases: Post, CharInputPane, LineInputPane, Pane, GrafPort, LObject, EventHandler, TimerHandler.
- Both classes are `0x108` bytes with no supported derived fields. Group's class-specific slot is primary `0x63011c -> 0x5b5440`; Post's are primary `0x6301a8 -> 0x5b5770` and EventHandler `0x6301b8 -> 0x5b5700`.
- Every Group head has dispatcher/open/raw-constructor stores; every Post head has dispatcher/open/modeled-constructor stores. Shared wrapper/adjustors `0x5b7940/0x5b77c8/0x5b77d3` remain compiler output and do not imply explicit class destructors.
- The exact page stays combined because the in-range Post primary locator at `0x63015c` would be orphaned or special-cased by a class split. Its predecessor Group primary locator at `0x6300d0` and successor Throw primary locator at `0x6301e8` remain excluded.
- Source route is [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md): Group class/children at direct position `50` and relative `10/20`, Post class/child at direct `60` and relative `10`, exact data marker `70`, source-local type marker `80`. Group/Post declarations emit through H; child definitions and explanatory markers emit through CPP.
- Raw ABI arrays, fixed RTTI structures, shared deleting wrappers, and adjustor thunks are not handwritten source. UID0001XA remains `88/92`, `RECONSTRUCTABLE:FALSE`, owner/emitter blank, because this family still spans independent CommandInputPanes, SpellInputPanes, SelfSave, and BlockListen owners.
- Historical uncertainty about a standalone Group/Post file remains recorded but is outweighed by the complete current module route. The Group raw constructor's lack of a direct start route is now fully investigated and source-ready rather than an unresolved boundary blocker.

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
- 2026-06-11 IDA MCP rechecked the remaining unassigned Emotion child: `0x0062f9b8`, `0x0062fa08`, and `0x0062fa38` are still the three `EmotionInputPane` vtable bases; constructor stores remain `0x005b2a03`, `0x005b2a09`, and `0x005b2a13`; the primary handler slot at `0x0062fa00` still points to `0x005b2a70`; and `0x0062fa40` remains the next `ChangeItemSlotInputPane` RTTI locator.
- 2026-06-12 A004 IDA MCP recheck confirms all split bases are still named in the IDB: Emotion `0x0062f9b8/0x0062fa08/0x0062fa38`, ChangeSpellSlot `0x0062fad0/0x0062fb20/0x0062fb50`, Group/Post `0x006300d4/0x00630124/0x00630154/0x00630160/0x006301b0/0x006301e0`, SpellSpell `0x0063041c/0x0063046c/0x0063049c`, SelfSave `0x006305c0/0x00630610/0x00630640`, and BlockListen/Add/Delete `0x0063064c/0x0063069c/0x006306cc/0x006306d8/0x00630728/0x00630758/0x00630764/0x006307b4/0x006307e4`.
- The same 2026-06-12 byte pass confirms the exclusive boundaries: Emotion ends before `ChangeItemSlotInputPane` RTTI at `0x0062fa40`, ChangeSpellSlot ends before `SayInputPane` RTTI at `0x0062fb58`, Group/Post ends before `ThrowInputPane` RTTI at `0x006301e8`, SpellSpell ends before `WieldInputPane` RTTI at `0x006304a4`, SelfSave ends before `BlockListenInputPane` RTTI at `0x00630648`, and BlockListen/Add/Delete ends before the UTF-16 `"Right cl..."` string data at `0x006307ec`.
- `trace_data_flow backward` on 2026-06-12 reconfirms representative vptr stores from constructors/dispatchers/open helpers for every split, including Emotion `0x005b2a03`, ChangeSpellSlot `0x005a61d7/0x005a9486/0x005b323f`, Group `0x005a66c4/0x005a9a66/0x005b541f`, Post `0x005a6718/0x005a9aeb/0x005b5677`, SpellSpell `0x005a6ac2/0x005a9e78/0x005b6167`, SelfSave `0x005aa196/0x005b67df`, BlockListen `0x005a72af/0x005aa336/0x005b68df`, AddToBlockListen `0x005b6b0a/0x005b6c9f`, and DeleteFromBlockListen `0x005b6bd5/0x005b711f`.

## Ownership Split Decision

This page is a reviewed mixed-owner vtable inventory, so `AUTOGEN_PARENT_UID` intentionally stays blank and `RECONSTRUCTABLE` is now `FALSE`. The aggregate has no single direct source owner and should not emit code. The exact by-memory data pages remain the binary backing ranges, while the source-local split pages carry reconstructable ownership and routing:

| Split page | Direct parent decision |
| --- | --- |
| [UID:0003HI][EmotionInputPaneVtables](by-type/by-vtable/EmotionInputPaneVtables.md) | Assigned to [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md). |
| [UID:0003HJ][ChangeSpellSlotInputPaneVtables](by-type/by-vtable/ChangeSpellSlotInputPaneVtables.md) | Assigned to [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md). |
| [UID:0003HK][GroupPostInputPaneVtables](by-type/by-vtable/GroupPostInputPaneVtables.md) | Assigned to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) because it spans two command-input classes. |
| [UID:0003HL][SpellSpellInputPaneVtables](by-type/by-vtable/SpellSpellInputPaneVtables.md) | Assigned to [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md). |
| [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md) | Assigned to [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md). |
| [UID:0003HN][BlockListenInputPaneFamilyVtables](by-type/by-vtable/BlockListenInputPaneFamilyVtables.md) | Assigned to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md) because it spans three block-list prompt classes. |

The aggregate still captures the shared three-view ABI pattern and adjacent ownership boundaries needed by the rebuilt declarations. It should not emit code or route to a single parent because no one class or source file owns every table in this inventory.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for each checked command/social input pane even though IDA confirms the bases listed above:

`EmotionInputPane`, `GroupInputPane`, `PostInputPane`, `SelfSaveInputPane`, `SpellSpellInputPane`, `ChangeSpellSlotInputPane`, `BlockListenInputPane`, `AddToBlockListenInputPane`, and `DeleteFromBlockListenInputPane`.

Use this page as the vtable/layout anchor until generated metadata records those tables.

## Reconstruction Notes

The vtable inventory strengthens the binary-level grouping of the command-input neighborhood from `EmotionInputPane` through `SelfSaveInputPane`, while preserving feature-owned splits for spell and block-list prompt code. `SpellSpellInputPane` should remain under spell-input review, and the block-list trio should remain under the social block-list module unless later source-level evidence shows the original developers kept all typed command prompts in one `CommandInputPanes.cpp` file.

Raw/projected constructor starts such as `0x005b67c0`, `0x005b68c0`, `0x005b6c80`, and `0x005b7100` should stay documented with their own evidence before use as IDA function-boundary anchors. Group `0x005b5400` is now reconciled separately: its exact 64-byte body, predecessor/successor boundaries, two live inline mirrors, no-route controls, formal constructor source, and deterministic supervisor-owned function handoff are documented by UID0002SB.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0003HI][EmotionInputPaneVtables](by-type/by-vtable/EmotionInputPaneVtables.md)
- [UID:0003HJ][ChangeSpellSlotInputPaneVtables](by-type/by-vtable/ChangeSpellSlotInputPaneVtables.md)
- [UID:0003HK][GroupPostInputPaneVtables](by-type/by-vtable/GroupPostInputPaneVtables.md)
- [UID:0003HL][SpellSpellInputPaneVtables](by-type/by-vtable/SpellSpellInputPaneVtables.md)
- [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md)
- [UID:0003HN][BlockListenInputPaneFamilyVtables](by-type/by-vtable/BlockListenInputPaneFamilyVtables.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md)
- [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md)
- [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- [UID:0001MK][0x005b5630-0x005b5890.PostInputPane](by-memory/0x005b5630-0x005b5890.PostInputPane.md)
- [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md)
- [UID:0001M8][0x005b3220-0x005b340e.ChangeSpellSlotInputPane](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md)
- [UID:0001MU][0x005b67c0-0x005b68b1.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b1.SelfSaveInputPane.md)
- [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-08-14 Agent-B010 UID0002N6 callback: kept `88/92`, owner/emitter blank, and non-emitting mixed-family status; updated the Group/Post exact child to `92/94`, source-local type to `91/94`, parent to `91/93`, and added complete six-view COL/RTTI/layout/slot/store/source-order/compiler-disposition closure plus the reconciled Group raw-constructor exception.
- 2026-05-31 exact vtable-data split:
  - What existed before: the page had `COMPLETION:0`, `CONFIDENCE:0`, blank reconstructable metadata, and depended on the broad [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md) aggregate for `.rdata` coverage.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, and six exact by-memory vtable-data child pages for the command/spell-adjacent/self-save/block-list prompt tables.
  - Summary/evidence: 2026-05-31 IDA MCP `xrefs_to`, `lookup_funcs`, and `py_eval` verify the table bases, vtable labels, store xrefs, representative slot values, and exact boundary dwords; final score remains below `95+` because source-file grouping and raw constructor boundaries are not fully resolved.
- 2026-06-11 A003 mixed-owner review:
  - What existed before: the page was `82/88` and parent-blank, but it did not explicitly close the ownership split or the remaining unassigned Emotion exact child.
  - Changed to: `86/90`, kept `AUTOGEN_PARENT_UID` blank, recorded the exact child parent decisions, and tied [UID:0002N4][0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData](by-memory/0x0062f9b8-0x0062fa40.EmotionInputPaneVtableData.md) to [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md) after the class parent cleared `85/85`.
  - Summary/evidence: live IDA reconfirmed the Emotion table bases, handler slot, constructor stores, next-class boundary, method/helper xrefs, and IDB hash; existing exact children already document the spell, group/post, self-save, and block-list routes, so the aggregate remains an intentionally unassigned mixed-owner layout anchor.
- 2026-06-12 A004 Batch 313 split repair:
  - What existed before: the aggregate was still marked `RECONSTRUCTABLE:TRUE` even though it was explicitly parent-blank mixed ownership, and the source-local vtable documentation existed only as exact by-memory data pages.
  - Changed to: `88/92`, `RECONSTRUCTABLE:FALSE`, kept the aggregate parent blank, and created reconstructable source-local split pages [UID:0003HI][EmotionInputPaneVtables](by-type/by-vtable/EmotionInputPaneVtables.md), [UID:0003HJ][ChangeSpellSlotInputPaneVtables](by-type/by-vtable/ChangeSpellSlotInputPaneVtables.md), [UID:0003HK][GroupPostInputPaneVtables](by-type/by-vtable/GroupPostInputPaneVtables.md), [UID:0003HL][SpellSpellInputPaneVtables](by-type/by-vtable/SpellSpellInputPaneVtables.md), [UID:0003HM][SelfSaveInputPaneVtables](by-type/by-vtable/SelfSaveInputPaneVtables.md), and [UID:0003HN][BlockListenInputPaneFamilyVtables](by-type/by-vtable/BlockListenInputPaneFamilyVtables.md).
  - Summary/evidence: live IDA confirms every split vtable base, representative vptr stores, exact successor boundaries, and shared offset constants `0xa0`/`0xa4`; the direct parents already clear the strict gate, so routing belongs on the split pages rather than this broad inventory.
