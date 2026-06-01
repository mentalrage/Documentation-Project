*** UID:0001XU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Item Action Input Pane Vtable Family

## Status

- Entity kind: vtable family inventory.
- Covered module: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), with adjacent [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) and [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) boundary evidence.
- Confidence: strong for table bases, `+0x00`/`+0xa0`/`+0xa4` layout, key virtual targets, and store xrefs; medium for projected constructor starts that IDA does not materialize as functions and for final source-level virtual method names.
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, `lookup_funcs`, and disassembly checks on 2026-05-26; IDA MCP `py_eval` recheck on 2026-05-31; current `simroot_v2` metadata checks only as a data-issue lead.

## Drop/Give Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md) | `0x0062fd8c` | `0x0062fddc` | `0x0062fe0c` | Constructor stores at `0x005b44f7`, `0x005b44fd`, and `0x005b4507`; `UserPane` command factory also stores these at `0x005a6452`, `0x005a6458`, and `0x005a6462`. |
| [UID:000044][DropInputPane](by-class/DropInputPane.md) | `0x0062fe18` | `0x0062fe68` | `0x0062fe98` | Constructor stores at `0x005b4827`, `0x005b482d`, and `0x005b4837`; `UserPane` command factory also stores these at `0x005a64ed`, `0x005a64f3`, and `0x005a64fd`. |
| [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md) | `0x0062fea4` | `0x0062fef4` | `0x0062ff24` | Gold branch stores at `0x005b4aaf`, `0x005b4ab5`, and `0x005b4abf`; raw constructor stores at `0x005b4b8f`, `0x005b4b97`, and `0x005b4ba1`; primary slot `+0x48` points to `0x005b4bb0`. |
| [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md) | `0x0062ff30` | `0x0062ff80` | `0x0062ffb0` | Constructor stores at `0x005b4d07`, `0x005b4d0d`, and `0x005b4d17`; `UserPane` command factory also stores these at `0x005a6588`, `0x005a658e`, and `0x005a6598`. |
| [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) | `0x0062ffbc` | `0x0063000c` | `0x0063003c` | Constructor stores at `0x005b4fb7`, `0x005b4fbd`, and `0x005b4fc7`; the tertiary table is named `off_63003C` in IDA, but xrefs and first slot match the same class layout. |
| [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) | `0x00630048` | `0x00630098` | `0x006300c8` | Gold branch stores at `0x005b51f8`, `0x005b51fe`, and `0x005b5208`; raw constructor stores at `0x005b52cf`, `0x005b52d7`, and `0x005b52e1`; primary slot `+0x48` points to `0x005b52f0`. |

## Equipment/Action Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md) | `0x0062f92c` | `0x0062f97c` | `0x0062f9ac` | Raw constructor stores at `0x005b26ff`, `0x005b2707`, and `0x005b2711`; command-factory stores at `0x005aa116`, `0x005aa11c`, and `0x005aa126`; primary `+0x48` points to `0x005b2830`, secondary `+0x08` points to `0x005b2720`. |
| [UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md) | `0x0062fa44` | `0x0062fa94` | `0x0062fac4` | Raw constructor stores at `0x005b2fef`, `0x005b2ff7`, and `0x005b3001`; command-factory stores at `0x005a9406`, `0x005a940c`, and `0x005a9416`; primary slot `+0x48` points to `0x005b3080`, secondary slot `+0x08` points to `0x005b3010`. |
| [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md) | `0x006301ec` | `0x0063023c` | `0x0063026c` | Constructor stores at `0x005b58d7`, `0x005b58dd`, and `0x005b58e7`; large command dispatcher stores at `0x005a68e4`, `0x005a68ea`, and `0x005a68f4`; command-factory stores at `0x005a9bcb`, `0x005a9bd1`, and `0x005a9bdb`; primary `+0x48` points to `0x005b59d0`, secondary `+0x08` points to `0x005b5960`. |
| [UID:0000EZ][ThrowReallyInputPane](by-class/ThrowReallyInputPane.md) | `0x00630278` | `0x006302c8` | `0x006302f8` | Raw constructor stores at `0x005b5b5d`, `0x005b5b63`, and `0x005b5b6d`; alternate construction stores appear in `UserPane` at `0x005a7b87`, `0x005a7b8d`, and `0x005a7b97`; helper `0x005aba80` stores at `0x005abae5`, `0x005abaeb`, and `0x005abaf5`; primary `+0x48` points to `0x005b5b80`. |
| [UID:0000FG][UseInputPane](by-class/UseInputPane.md) | `0x00630304` | `0x00630354` | `0x00630384` | Constructor stores at `0x005b5ce7`, `0x005b5ced`, and `0x005b5cf7`; large command dispatcher stores at `0x005a697f`, `0x005a6985`, and `0x005a698f`; command-factory stores at `0x005a9cab`, `0x005a9cb1`, and `0x005a9cbb`; primary `+0x48` points to `0x005b5de0`, secondary `+0x08` points to `0x005b5d70`. |
| [UID:000047][EatInputPane](by-class/EatInputPane.md) | `0x00630390` | `0x006303e0` | `0x00630410` | Constructor stores at `0x005b5f07`, `0x005b5f0d`, and `0x005b5f17`; large command dispatcher stores at `0x005a6a1a`, `0x005a6a20`, and `0x005a6a2a`; command-factory stores at `0x005a9d8b`, `0x005a9d91`, and `0x005a9d9b`; primary `+0x48` points to `0x005b6000`, secondary `+0x08` points to `0x005b5f90`. |
| [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md) | `0x006304a8` | `0x006304f8` | `0x00630528` | Constructor stores at `0x005b6317`, `0x005b631d`, and `0x005b6327`; large command dispatcher stores at `0x005a6b5d`, `0x005a6b63`, and `0x005a6b6d`; command-factory stores at `0x005a9f5b`, `0x005a9f61`, and `0x005a9f6b`; primary `+0x48` points to `0x005b6410`, secondary `+0x08` points to `0x005b63a0`. |
| [UID:0000G0][WearInputPane](by-class/WearInputPane.md) | `0x00630534` | `0x00630584` | `0x006305b4` | Constructor stores at `0x005b65a7`, `0x005b65ad`, and `0x005b65b7`; large command dispatcher stores at `0x005a6c03`, `0x005a6c09`, and `0x005a6c13`; command-factory stores at `0x005aa03b`, `0x005aa041`, and `0x005aa04b`; primary `+0x48` points to `0x005b66a0`, secondary `+0x08` points to `0x005b6630`. |

## Shared Slot Notes

- These command-prompt panes use the same three-view pane layout as other `LineInputPane`/`CharInputPane` derivatives: primary vfptr at `+0x00`, secondary view at `+0xa0`, and tertiary view at `+0xa4`.
- The primary slot for this family usually points at scalar deleting destructor `0x005b7940`, while the secondary and tertiary first slots point at [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md) `0x005b77c8` and `0x005b77d3`.
- Those two thunks are shared across item, command, spell, and target-input pane vtables. They should be represented by inheritance/destructor layout, not source-level methods on `TakeOffInputPane` or any one item prompt class.
- `0x005a5bd0` is a large `UserPane` command/key dispatcher that constructs many of these prompt panes in response to typed commands. Its vtable stores are strong caller evidence for the family, but final source placement should keep the dispatcher with [UID:0000P1][UserPane](by-file/UserPane.md), not with `ItemActionInputPanes.cpp`.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for each checked direct item-action input pane even though IDA confirms the bases listed above:

`DropAllInputPane`, `DropInputPane`, `DropGoldInputPane`, `GiveAllInputPane`, `GiveInputPane`, `GiveGoldInputPane`, `TakeOffInputPane`, `ChangeItemSlotInputPane`, `ThrowInputPane`, `ThrowReallyInputPane`, `UseInputPane`, `EatInputPane`, `WieldInputPane`, and `WearInputPane`.

Use this page as the vtable/layout anchor until generated metadata records those tables.

## Current IDA Recheck

2026-05-31 IDA MCP `py_eval` walked every listed primary, secondary, and tertiary vtable base using IDA names, dword reads, function containment, and data xrefs. The pass confirmed:

- all fourteen class table triples resolve to the expected MSVC vtable names except the known `GiveInputPane` tertiary table, which IDA still names `off_63003C` while its first slot and xrefs match the same layout;
- primary first slots point to the shared scalar deleting destructor family (`0x005b7940` for most item-action panes, `0x005b7b80` for `ThrowReallyInputPane`) and primary `+0x48` action slots point to the documented per-class submit/action handlers;
- secondary first slots point to the shared `this-0xa0` adjustor thunk family, and secondary `+0x08` slots point to the per-class input/key handlers or inherited numeric/character filters;
- tertiary first slots point to the shared `this-0xa4` adjustor thunk family, with `+0x04 -> 0x00544e90` default/update slot;
- each table has constructor, command-factory, dispatcher, or raw constructor-shaped store xrefs matching the ownership notes in the tables above.

## Reconstruction Notes

The vtable inventory supports a compact `ui/dialogs/ItemActionInputPanes.cpp` source module for direct item command prompts, while keeping `ItemWhoInputPane` in the target-selection family and keeping `UserPane` as the command dispatcher. Raw/projected constructor starts such as [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md), [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md), [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md), [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md), and [UID:0001MM][0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md) should stay documented as constructor-shaped bytes but should not be used as IDA function-boundary anchors until reconciled.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md)
- [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0001MM][0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md)
- [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md)
- [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md)
- [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md)
- [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md)
- [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md)
- [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md)
- [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

### 2026-05-31 - Scored IDA-verified item-action vtable family

- Before: validator metadata marked this page `COMPLETION:0`, `CONFIDENCE:0`, and left `RECONSTRUCTABLE` blank even though the page contained a broad vtable inventory.
- Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`. No parent attachment or C++ reconstruction code was added because raw constructor reachability, final virtual names, and original source declarations are not final-audit complete.
- Evidence: IDA MCP `py_eval` on 2026-05-31 confirmed every listed vtable base, primary/secondary/tertiary slot pattern, key action/input targets, shared adjustor/destructor thunks, and store xrefs for the item-action pane families.
