*** UID:0000O0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SpellInputPanes

## Status

- Confidence: strong for grouping the spell argument prompt panes; medium for the final split between spell input, command input, and spell inventory sources.
- Proposed module folder: `ui/dialogs/`
- Candidate file: `ui/dialogs/SpellInputPanes.cpp`
- Alternative placement: split `SpellTargetInputPanes.cpp` for [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md) and keep [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md) in [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md).
- Current generated sources: `class_SpellStringInputPane.cpp`, `class_SpellFourArgsInputPane.cpp`, `class_SpellThreeArgsInputPane.cpp`, `class_SpellTwoArgsInputPane.cpp`, `class_SpellOneArgInputPane.cpp`, `class_SpellSlotInputPane.cpp`, `class_ChangeSpellSlotInputPane.cpp`, and `class_SpellSpellInputPane.cpp`.
- Primary memory docs: [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md), [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md), [UID:0001M8][0x005b3220-0x005b340e.ChangeSpellSlotInputPane](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md), and [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md).

## File Role

This module candidate covers spell command prompt panes that collect one or more user arguments, convert them into compact opcode `0x0f` spell-use packets, or route the selected spell/slot back into the spell panel.

The pane family shares:

- prompt text loaded from player spell records at a 328-byte stride;
- [UID:000077][LineInputPane](by-class/LineInputPane.md), [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md), [UID:00001P][CharInputPane](by-class/CharInputPane.md), or [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md) bases;
- panel close/reset behavior through the general-purpose spell panel child at index `3`;
- destructor adjustor thunks in the [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) island, excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md);
- packet construction helpers that serialize big-endian spell arguments before queueing to the session sender.

## Proposed Contents

| Entity | Address evidence | Current generated file | Role |
| --- | --- | --- | --- |
| [UID:0000DU][SpellStringInputPane](by-class/SpellStringInputPane.md) | [UID:00018Y][0x004f20a0-0x004f22f4.SpellPromptTextHelper](by-memory/0x004f20a0-0x004f22f4.SpellPromptTextHelper.md), [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md), destructor [UID:0001NH][0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor](by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md) | `class_SpellStringInputPane.cpp` | String-argument spell prompt; converts input text and sends opcode `0x0f`. |
| [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md) | [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md), destructor [UID:0001NE][0x005b7c20-0x005b7ce4.SpellFourArgsInputPaneScalarDeletingDestructor](by-memory/0x005b7c20-0x005b7ce4.SpellFourArgsInputPaneScalarDeletingDestructor.md) | `class_SpellFourArgsInputPane.cpp` | Numeric four-argument spell prompt; sends 10-byte payload. |
| [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md) | [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md), destructor [UID:0001NI][0x005b7f60-0x005b8024.SpellThreeArgsInputPaneScalarDeletingDestructor](by-memory/0x005b7f60-0x005b8024.SpellThreeArgsInputPaneScalarDeletingDestructor.md) | `class_SpellThreeArgsInputPane.cpp` | Numeric three-argument spell prompt; sends 8-byte payload. |
| [UID:0000DW][SpellTwoArgsInputPane](by-class/SpellTwoArgsInputPane.md) | [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md), destructor [UID:0001NJ][0x005b8030-0x005b80f4.SpellTwoArgsInputPaneScalarDeletingDestructor](by-memory/0x005b8030-0x005b80f4.SpellTwoArgsInputPaneScalarDeletingDestructor.md) | `class_SpellTwoArgsInputPane.cpp` | Numeric two-argument spell prompt; sends 6-byte payload. |
| [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md) | [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md), destructor [UID:0001NF][0x005b7cf0-0x005b7db4.SpellOneArgInputPaneScalarDeletingDestructor](by-memory/0x005b7cf0-0x005b7db4.SpellOneArgInputPaneScalarDeletingDestructor.md) | `class_SpellOneArgInputPane.cpp` | Numeric one-argument spell prompt; sends 4-byte payload. |
| [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md) | [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md), destructor [UID:0001NG][0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor](by-memory/0x005b7dc0-0x005b7e84.SpellSlotInputPaneScalarDeletingDestructor.md) | `class_SpellSlotInputPane.cpp` | Spell-slot letter prompt; sends selected spell slot as opcode `0x0f`. |
| [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md) | [UID:0001M7][0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor](by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md), [UID:0001M8][0x005b3220-0x005b340e.ChangeSpellSlotInputPane](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md) | `class_ChangeSpellSlotInputPane.cpp` | Comma-separated spell slot reorder prompt; sends slot-change packet. |
| [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md) | [UID:0001MO][0x005b6120-0x005b62c8.SpellSpellInputPane](by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md) | `class_SpellSpellInputPane.cpp` | Spell-to-spell selector prompt; selects another spell by letter. |
| [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md) | [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md) | `class_SpellWhoInputPane.cpp` | Spell target prompt; current stronger placement is [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md). |

## Boundary Notes

- IDA confirms the generated method starts for the string/numeric/slot prompt panes and all destructor adjustor thunks.
- `SpellStringInputPane::SetPromptText` at `0x004f20a0` is non-contiguous with the main spell input block but is strongly shared by spell input constructors, [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md), [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md), and [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md).
- `SpellOneArgInputPane` currently owns `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650` in generated output, but existing [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) docs and exact helper pages show those are panel child/tab helpers: [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) and [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md). Do not migrate them with spell argument panes.
- `SpellOneArgInputPane::__wtol` at [UID:0001O5][0x005cea43-0x005cea6d.CrtWtolWrapper](by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md) is a CRT `__wtol` wrapper in IDA, not project-owned spell input code.
- IDA does not have a function object at `0x005b3220`, but disassembly shows a complete `ChangeSpellSlotInputPane` constructor-shaped body ending at `0x005b325f`.
- 2026-05-27 IDA MCP recheck found no inbound xrefs or raw dword pointer hits to projected `ChangeSpellSlotInputPane` constructor start `0x005b3220`, but the byte body stores vtables `0x0062fad0`, `0x0062fb20`, and `0x0062fb50`. `SubmitSpellSlotChange` and `OnKeyInput` are real vtable-referenced functions at primary slots `+0x48` and `+0x58`.
- `ChangeSpellSlotInputPane` sends through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / `dword_67A7EC` and reads spell-slot state through the broad player-data pointer at `0x0067a748`. Generated `CashShopRequest*` and collection-specific names for those globals should remain typed-view/alias evidence only.
- Disabled generated output marks the second adjustor thunk for each spell argument pane as missing code, but IDA confirms the thunks at `0x005b7883`, `0x005b7899`, `0x005b78af`, `0x005b78c5`, `0x005b78db`, and `0x005b78f1`. The full reviewed island is documented at [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) and tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-26 IDA MCP recheck confirms the adjustor island as compiler-generated `this - 0xa0` / `this - 0xa4` destructor wrappers and confirms `0x005cea43` as `unknown_libname_24` / CRT `__wtol`.

## Placement Notes

The likely target source split is:

```text
ui/dialogs/SpellInputPanes.cpp
ui/dialogs/SpellInputPanes.h
ui/dialogs/TargetSelectionInputPanes.cpp
```

`SpellWhoInputPane` remains cross-referenced here because it is constructed by spell inventory cast paths, but its map-object traversal and saved-target helpers make [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) the stronger current owner.

`SpellSpellInputPane` can move from [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) into this module once the broader command-input pass accepts a spell-specific split.

## Cross-References

- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0000DU][SpellStringInputPane](by-class/SpellStringInputPane.md)
- [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md)
- [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md)
- [UID:0000DW][SpellTwoArgsInputPane](by-class/SpellTwoArgsInputPane.md)
- [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md)
- [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md)
- [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md)
- [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document covers spell prompt grouping, proposed contents for each pane, boundary notes, generated-owner exclusions, adjustor thunk handling, placement notes, vtable refs, and cross-references; confidence is capped by final split between spell input, target selection, command input, and spell inventory sources.
