*** UID:0000KC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ItemActionInputPanes

## Status

- Confidence: strong for grouping the direct item command input panes, including Batch 085 live IDA confirmation of the DropAll/Drop/Eat class boundaries, vtables, factory/dispatcher xrefs, prompt ids, slot conversion, packet bytes, and confirmation/gold branches. Confidence remains capped by raw helper splits and final source-level helper names.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/ItemActionInputPanes.cpp`
- Possible split files: `ui/dialogs/ItemActionInputPanes.cpp`, `ui/dialogs/TargetSelectionInputPanes.cpp`
- Evidence basis: IDA MCP function-boundary/vtable checks on 2026-05-23, 2026-05-26, and 2026-06-07 plus existing by-memory/by-class/by-global documentation. Use [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) as the current IDA-backed layout anchor.

## Hypothesis

The original client likely kept direct slash-command/item-action prompt panes in one small dialog/input source module rather than scattering each one into a separate file. These panes are thin [UID:00001P][CharInputPane](by-class/CharInputPane.md), [UID:00009L][NumberInputPane](by-class/NumberInputPane.md), [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md), or [UID:000077][LineInputPane](by-class/LineInputPane.md) derivatives that all translate a short typed selection into a server packet or target-selection flow.

Likely compact source layout:

```text
ui/dialogs/ItemActionInputPanes.cpp
ui/dialogs/ItemActionInputPanes.h
```

Possible split if target-use code proves broader than item use:

```text
ui/dialogs/ItemActionInputPanes.cpp
ui/dialogs/ItemTargetInputPane.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `DropAllInputPane` | `0x005b44b0-0x005b475c` | `class_DropAllInputPane.cpp` | Single-letter inventory slot drop-all prompt; sends drop packet or opens confirmation. |
| `DropInputPane` | `0x005b47e0-0x005b4ae4` | `class_DropInputPane.cpp` | Slot drop prompt; routes gold input to `DropGoldInputPane`. |
| `DropGoldInputPane` | raw constructor `0x005b4b70-0x005b4bb0`, submit `0x005b4bb0-0x005b4c4a` | `class_DropGoldInputPane.cpp` | Numeric gold-drop prompt; sends opcode `0x24`. |
| `GiveAllInputPane` | `0x005b4cc0-0x005b4eee` | `class_GiveAllInputPane.cpp` | Single-letter give-all prompt with confirmation callback. |
| `GiveInputPane` | `0x005b4f70-0x005b5223` | `class_GiveInputPane.cpp` | Slot give prompt; routes gold input to `GiveGoldInputPane`. |
| `GiveGoldInputPane` | raw constructor `0x005b52b0-0x005b52f0`, submit `0x005b52f0-0x005b538a` | `class_GiveGoldInputPane.cpp` | Numeric gold-give prompt; sends opcode `0x2a`. |
| `TakeOffInputPane` | destructor `0x004f2010-0x004f2092`, raw constructor `0x005b26e0-0x005b2720`, methods `0x005b2720-0x005b296b`, helper `0x005b27c0-0x005b2827`, scalar destructor `0x005b7940-0x005b797b` | `class_TakeOffInputPane.cpp` | Equipment removal prompt; supports event shortcut opcode `0x2d`, typed `A` all-equipment removal, and opcode `0x1f` slot removal. |
| `ChangeItemSlotInputPane` | raw constructor `0x005b2fd0-0x005b3010`, methods `0x005b3010-0x005b3196` | `class_ChangeItemSlotInputPane.cpp` | Comma-separated source/destination slot prompt; sends opcode `0x30` subcommand `0`. |
| `ThrowInputPane` | `0x005b5890-0x005b5aac` | `class_ThrowInputPane.cpp` | Slot throw prompt; sends opcode `0x17`. |
| `ThrowReallyInputPane` | raw constructor `0x005b5b30-0x005b5b80`, accept handler `0x005b5b80-0x005b5c20` | `class_ThrowReallyInputPane.cpp` | Confirmation prompt for throwing/discarding an item. |
| `UseInputPane` | `0x005b5ca0-0x005b5e5c` | `class_UseInputPane.cpp` | Item-use prompt that resolves one slot letter and dispatches the use flow. |
| `EatInputPane` | `0x005b5ec0-0x005b60c0` | `class_EatInputPane.cpp` | Item-eat prompt; sends opcode `0x1a`. |
| `WieldInputPane` | `0x005b62d0-0x005b64fa`, helper `0x005b6500-0x005b6560` | `class_WieldInputPane.cpp` | Weapon wield prompt; sends opcode `0x12`. |
| `WearInputPane` | `0x005b6560-0x005b6760` | `class_WearInputPane.cpp` | Equipment wear prompt; sends opcode `0x1e`. |
| `ItemWhoInputPane` | `0x005aec60-0x005af3af`, `0x005b780a-0x005b7820`, `0x005b7a20-0x005b7aec` | `class_ItemWhoInputPane.cpp` | Target-name/object selection pane used by item or spell use-on-target flow; see [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). |
| `ItemWhoInputPaneState` | `0x0057d0a0-0x0057d0af` | `class_ItemWhoInputPaneState.cpp` | Small state helper shared by `ItemWhoInputPane` and sibling spell-input panes; see [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md). |

## Boundary Notes

- IDA confirms the main action method starts listed above, but it does not recognize Wave3 projected constructor starts at `0x005b4b70`, `0x005b52b0`, `0x005b26e0`, `0x005b5b30`, or `0x005b2fd0`.
- IDA confirms three-view vtable groups for the direct item-action prompts, with primary vfptr at `+0x00`, secondary at `+0xa0`, and tertiary at `+0xa4`; see [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md).
- 2026-05-27 IDA raw-disassembly follow-up confirms `0x005b2fd0-0x005b3010` is constructor-shaped `ChangeItemSlotInputPane` code even though IDA does not model it as a function. It uses localized prompt id `0x2e`, calls `CharArgsInputPane::CharArgsInputPane`, and installs vtables `0x0062fa44`, `0x0062fa94`, and `0x0062fac4`.
- IDA decompiles the command factory at `0x005a93b0` as an inline allocation/construction path for the same class: allocate `0x108` bytes, load string id `46`, call `0x004f2a60`, then store the same three vtables. There are still no direct xrefs to the raw constructor start.
- 2026-05-27 IDA raw-disassembly follow-up also confirms [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) and [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) raw constructors. Both are `NumberInputPane` derivatives; the direct `DropInputPane`/`GiveInputPane` submit handlers inline equivalent allocation/construction branches for the gold prompt.
- 2026-06-02 IDA MCP refresh of [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) confirms the modeled function map and shows several non-empty raw helper bodies inside prior gap spans. These remain item-action input-pane evidence but should be split into exact children before any final C++ reconstruction.
- 2026-06-07 A004 Batch 085 live IDA MCP recheck confirms [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md), [UID:000044][DropInputPane](by-class/DropInputPane.md), and [UID:000047][EatInputPane](by-class/EatInputPane.md) as direct item-action prompt classes in this module. The recheck confirmed exact constructor/key/submit function ranges, three-view vtable stores and xrefs from constructors plus the command factory/dispatcher, localized prompt ids `8`, `6`, and `12`, the shared help-key path, slot-letter conversion, inventory-limit checks against [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`, Drop/DropAll opcode `0x08` packet modes, Eat opcode `0x1a`, the DropGold shortcut branch, and the confirmation branches.
- 2026-05-27 IDA raw-disassembly follow-up confirms [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md) as constructor-shaped bytes. It uses prompt id `0x22`, calls `CharInputPane::CharInputPane`, and installs vtables `0x0062f92c`, `0x0062f97c`, and `0x0062f9ac`.
- IDA confirms [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) as a real helper that sends opcode `0x1f` plus a selector byte through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). It is called by both `TakeOffInputPane` and `SelfLookPane`, so final helper source placement remains open.
- IDA confirms [UID:0000PX][g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md) at `0x00630bd8` as the fixed 23-entry table used by `TakeOffInputPane::ProcessUnequipCommand`: `wash#nlr####fm#c###[]12`.
- 2026-06-02 IDA MCP refresh confirms the TakeOff typed all-equipment branch compares the read wchar to `0x0041` (`A`), not `*`. The opcode `0x2d` shortcut is a separate event-handler path at `0x005b2720`, while opcode `0x1f` is used by the `A` selector loop and table-matched single-slot removals.
- The same refresh confirms TakeOff internal alignment padding at `0x005b27b3-0x005b27c0`, `0x005b2827-0x005b2830`, and `0x005b296b-0x005b2970`; keep these in [UID:0000VN][-ignored](by-memory/-ignored.md), not as source functions.
- 2026-05-27 IDA raw-disassembly follow-up confirms [UID:0001MM][0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md) as constructor-shaped bytes. It uses prompt id `0xa5`, calls `CharInputPane::CharInputPane`, installs vtables `0x00630278`, `0x006302c8`, and `0x006302f8`, and stores the confirmed item slot byte at `+0x108`.
- 2026-06-02 IDA MCP refresh of [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) confirms the Throw/Use/Eat modeled function map, pure padding spans, and non-empty raw helper bodies around [UID:0001MM][0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md). Keep those helper bodies in the item-action module, but split them into exact children before final C++ reconstruction.
- The small functions at `0x005b77c8` and `0x005b77d3` are shared input-pane destructor adjustor thunks, not handwritten `TakeOffInputPane` logic. They are documented and ignored in [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md).
- 2026-05-27 IDA decompilation confirms [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md) and [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md) are clean IDA-modeled constructors/methods, not raw constructor cases. Wield uses prompt id `0x0d`, Wear uses prompt id `0x21`, both derive from `CharInputPane`, both format prompts with the local player name from [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, and both validate typed slot letters against `dword_69AE0C + 0x284`.
- 2026-05-27 IDA decompilation confirms [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md), [UID:0000FG][UseInputPane](by-class/UseInputPane.md), and [UID:000047][EatInputPane](by-class/EatInputPane.md) follow the same constructor/key-handler pattern. Throw uses prompt id `0x23`, Use uses `0x09`, and Eat uses `0x0c`; all three validate slot letters against `dword_69AE0C + 0x284`. Throw sends opcode `0x17` mode `0` after checking [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748` byte `+0x3ec0`, Use dispatches through [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md), and Eat sends opcode `0x1a`.
- The broader `0x005b29c0-0x005b6760` neighborhood also contains `EmotionInputPane`, `GroupInputPane`, `PostInputPane`, and `SpellSpellInputPane`; see [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md). That supports an original "command input panes" source neighborhood, but those classes should not be claimed as item-action ownership without their own pass.
- IDA recheck on 2026-05-26 resolves `0x005b6500-0x005b6560` as [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md), called only from `WieldInputPane::OnSubmitInput`. It should attach to the wield side of the item-action module, not to `WearInputPane`.
- `ItemWhoInputPane` is earlier in memory than the direct item command cluster and interacts with `MapPane`, `LivingObjectPane`, selected target state, and auto-use configuration. The 2026-05-24 target-selection pass now documents a likely split module in [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md).

## Migration Notes

Proposed dry-run sequence after class docs are reviewed:

```powershell
python source-3\wave3.py rename file class_DropInputPane.cpp ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py set file-simpath ItemActionInputPanes.cpp ui/dialogs/ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class DropAllInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class DropInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class DropGoldInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class GiveAllInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class GiveInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class GiveGoldInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class TakeOffInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class ChangeItemSlotInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class ThrowInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class ThrowReallyInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class UseInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class EatInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class WieldInputPane --file ItemActionInputPanes.cpp --dry-run
python source-3\wave3.py attach class WearInputPane --file ItemActionInputPanes.cpp --dry-run
```

Do not run these migrations until the non-IDA constructor starts and uncovered neighboring functions are reviewed.

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)
- [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md)
- [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)
- [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md)
- [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000PX][g_equipmentSlotKeys](by-global/g_equipmentSlotKeys.md)
- [UID:0000PQ][g_activeDialogCount](by-global/g_activeDialogCount.md)
- [UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md)
- [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md)
- [UID:0000EZ][ThrowReallyInputPane](by-class/ThrowReallyInputPane.md)
- [UID:0001MM][0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:0001KN][0x005a3e30-0x005a3ff3.UseInventorySlotDispatch](by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md)
- [UID:000047][EatInputPane](by-class/EatInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)
- [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md)
- [UID:00006Y][ItemWhoInputPaneState](by-class/ItemWhoInputPaneState.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md)
- [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md)
- [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md)
- [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md)
- [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md)
- [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md)
- [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md)
- [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md)
- [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md)

## Changes

- 2026-06-07 A004 Batch 085 parent-gate refresh:
  - Before: `90/80`; confidence was below the strict direct-parent gate for [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md), [UID:000044][DropInputPane](by-class/DropInputPane.md), and [UID:000047][EatInputPane](by-class/EatInputPane.md).
  - After: `90/85`.
  - Evidence: live IDA MCP against `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the modeled DropAll/Drop/Eat ranges, vtable triples, command factory/dispatcher xrefs, prompt ids, help-key path, slot conversion, packet opcodes, DropGold branch, and confirmation branches.
  - Remaining cap: raw helper bodies, non-IDA constructor starts, and final source-level helper names still need exact child docs before final C++ reconstruction.
- 2026-06-07 A008 alias cleanup:
  - Before: Wield/Wear/Throw/Use/Eat evidence used bare `dword_67A748` wording for local-player/client-state reads.
  - Changed to: canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording while preserving `dword_67A748` as the historical IDA alias.
  - Evidence: the `g_pCollectionData` global page documents `0x0067a748` as a broad player/client-state pointer with item, spell, gold, and collection typed views.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:90` and `CONFIDENCE:80`.
  - Summary/evidence: direct item command input panes, raw constructor cases, packet helper ownership, slot tables, vtable family, migration sequence, and extensive memory/class refs are documented; confidence is capped by `ItemWhoInputPane` split and non-IDA raw constructor starts.
- 2026-06-02 metadata/evidence refresh:
  - Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/`.
  - Corrected TakeOff all-equipment wording from older `*` source-lead text to IDA-confirmed typed `A` behavior.
