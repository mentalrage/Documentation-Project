*** UID:0001XU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// No raw vtable emission; ItemActionInputPane vtables are compiler-generated from the item-action pane class declarations and exact child methods under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Item Action Input Pane Vtable Family

## Status

- Entity kind: vtable family inventory.
- Covered module: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), with adjacent [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) and [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) boundary evidence.
- Confidence: strong for table bases, COL pointers, `+0x00`/`+0xa0`/`+0xa4` layout, key virtual targets, and store xrefs; medium for projected constructor starts that IDA does not materialize as functions and for final source-level virtual method names.
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, `lookup_funcs`, and disassembly checks on 2026-05-26; IDA MCP `py_eval` rechecks on 2026-05-31 and 2026-06-11; current `simroot_v2` metadata checks only as a data-issue lead.

## B004 2026-07-20 Wield Slot And Store Synchronization

- Wield's three-view table bases remain exactly `0x006304a8`, `0x006304f8`, and `0x00630528`; this page remains `86/89`, owned/emitted through [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), reconstructable only as a compiler-data cause record, and keeps its exact no-raw-vtable managed marker.
- Active source-facing virtual identities are [UID:0004U4][0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent](by-memory/0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent.md) at secondary slot dword `0x00630500` and [UID:0004U6][0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput](by-memory/0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput.md) at primary slot dword `0x006304f0`. Historical `OnCharInput` naming is superseded.
- Store triads distinguish three compiler-lowered construction routes without inventing handwritten vptr source: exact [UID:0004U2][0x005b62d0-0x005b6397.WieldInputPaneConstructor](by-memory/0x005b62d0-0x005b6397.WieldInputPaneConstructor.md) constructor stores at `0x005b6317/0x005b631d/0x005b6327`; UserPane inline construction stores at `0x005a6b5d/0x005a6b63/0x005a6b6d`; retained [UID:0004U0][0x005a9f00-0x005a9fd6.CreateWieldInputPane](by-memory/0x005a9f00-0x005a9fd6.CreateWieldInputPane.md) outlined factory stores at `0x005a9f5b/0x005a9f61/0x005a9f6b`.
- [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md) is one private nonvirtual member and therefore has no vtable slot. No raw vtable/COL/RTTI array, explicit vptr store, deleting wrapper, adjustor thunk, or helper slot is emitted as human source.

## Drop/Give Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md) | `0x0062fd8c` | `0x0062fddc` | `0x0062fe0c` | Constructor stores at `0x005b44f7`, `0x005b44fd`, and `0x005b4507`; `UserPane` command factory also stores these at `0x005a6452`, `0x005a6458`, and `0x005a6462`. |
| [UID:000044][DropInputPane](by-class/DropInputPane.md) | `0x0062fe18` | `0x0062fe68` | `0x0062fe98` | Constructor stores at `0x005b4827`, `0x005b482d`, and `0x005b4837`; `UserPane` command factory also stores these at `0x005a64ed`, `0x005a64f3`, and `0x005a64fd`. |
| [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md) | `0x0062fea4` | `0x0062fef4` | `0x0062ff24` | Gold branch stores at `0x005b4aaf`, `0x005b4ab5`, and `0x005b4abf`; raw constructor stores at `0x005b4b8f`, `0x005b4b97`, and `0x005b4ba1`; [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) now emits formal first-draft constructor C++ while no-function/no-route evidence remains an IDA anchor caveat; primary slot `+0x48` points to source-facing `DropGoldInputPane::OnSubmit()` at `0x005b4bb0`. |
| [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md) | `0x0062ff30` | `0x0062ff80` | `0x0062ffb0` | Constructor stores at `0x005b4d07`, `0x005b4d0d`, and `0x005b4d17`; `UserPane` command factory also stores these at `0x005a6588`, `0x005a658e`, and `0x005a6598`. |
| [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) | `0x0062ffbc` | `0x0063000c` | `0x0063003c` | Constructor stores at `0x005b4fb7`, `0x005b4fbd`, and `0x005b4fc7`; the tertiary table is named `off_63003C` in IDA, but xrefs and first slot match the same class layout. |
| [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) | `0x00630048` | `0x00630098` | `0x006300c8` | Gold branch stores at `0x005b51f8`, `0x005b51fe`, and `0x005b5208`; raw constructor stores at `0x005b52cf`, `0x005b52d7`, and `0x005b52e1`; primary slot `+0x48` / dword `0x00630090` points to source-facing current `OnSubmit` / descriptive `GiveGoldInputPane::OnSubmitGoldAmount` at `0x005b52f0`. |

## Equipment/Action Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md) | `0x0062f92c` | `0x0062f97c` | `0x0062f9ac` | Raw constructor stores at `0x005b26ff`, `0x005b2707`, and `0x005b2711`; command-factory stores at `0x005aa116`, `0x005aa11c`, and `0x005aa126`; primary `+0x48` points to `0x005b2830`, secondary `+0x08` points to `0x005b2720`. |
| [UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md) | `0x0062fa44` | `0x0062fa94` | `0x0062fac4` | Raw constructor stores at `0x005b2fef`, `0x005b2ff7`, and `0x005b3001`; command-factory stores at `0x005a9406`, `0x005a940c`, and `0x005a9416`; primary slot `+0x48` points to `0x005b3080`, secondary slot `+0x08` points to `0x005b3010`. |
| [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md) | `0x006301ec` | `0x0063023c` | `0x0063026c` | Constructor stores at `0x005b58d7`, `0x005b58dd`, and `0x005b58e7`; large command dispatcher stores at `0x005a68e4`, `0x005a68ea`, and `0x005a68f4`; command-factory stores at `0x005a9bcb`, `0x005a9bd1`, and `0x005a9bdb`; primary `+0x48` points to `0x005b59d0`, secondary `+0x08` points to `0x005b5960`. |
| [UID:0000EZ][ThrowReallyInputPane](by-class/ThrowReallyInputPane.md) | `0x00630278` | `0x006302c8` | `0x006302f8` | Raw constructor stores at `0x005b5b5d`, `0x005b5b63`, and `0x005b5b6d`; alternate construction stores appear in `UserPane` at `0x005a7b87`, `0x005a7b8d`, and `0x005a7b97`; helper `0x005aba80` stores at `0x005abae5`, `0x005abaeb`, and `0x005abaf5`; primary `+0x48` points to `0x005b5b80`. [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) now emits first-draft constructor C++ through the `ThrowReallyInputPane` route; no-function/no-route/no-pointer evidence remains an IDA/callgraph caveat, not a constructor C++ blocker. |
| [UID:0000FG][UseInputPane](by-class/UseInputPane.md) | `0x00630304` | `0x00630354` | `0x00630384` | Constructor stores at `0x005b5ce7`, `0x005b5ced`, and `0x005b5cf7`; large command dispatcher stores at `0x005a697f`, `0x005a6985`, and `0x005a698f`; command-factory stores at `0x005a9cab`, `0x005a9cb1`, and `0x005a9cbb`; primary `+0x48` points to `0x005b5de0`, secondary `+0x08` points to `0x005b5d70`. |
| [UID:000047][EatInputPane](by-class/EatInputPane.md) | `0x00630390` | `0x006303e0` | `0x00630410` | Constructor stores at `0x005b5f07`, `0x005b5f0d`, and `0x005b5f17`; large command dispatcher stores at `0x005a6a1a`, `0x005a6a20`, and `0x005a6a2a`; command-factory stores at `0x005a9d8b`, `0x005a9d91`, and `0x005a9d9b`; primary `+0x48` points to `0x005b6000`, secondary `+0x08` points to `0x005b5f90`. |
| [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md) | `0x006304a8` | `0x006304f8` | `0x00630528` | [UID:0004U2][0x005b62d0-0x005b6397.WieldInputPaneConstructor](by-memory/0x005b62d0-0x005b6397.WieldInputPaneConstructor.md) constructor stores at `0x005b6317`, `0x005b631d`, and `0x005b6327`; large UserPane inline construction stores at `0x005a6b5d`, `0x005a6b63`, and `0x005a6b6d`; retained [UID:0004U0][0x005a9f00-0x005a9fd6.CreateWieldInputPane](by-memory/0x005a9f00-0x005a9fd6.CreateWieldInputPane.md) outlined factory stores at `0x005a9f5b`, `0x005a9f61`, and `0x005a9f6b`; primary `+0x48` / `0x006304f0` points to [UID:0004U6][0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput](by-memory/0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput.md) `WieldInputPane::OnSubmitInput()` at `0x005b6410`, secondary `+0x08` / `0x00630500` points to [UID:0004U4][0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent](by-memory/0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent.md) `WieldInputPane::HandleKeyOrTextEvent(Event *)` at `0x005b63a0`; private [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md) `SendWieldPacket` is nonvirtual. |
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

2026-06-11 IDA MCP `py_eval` refreshed the same table set and additionally checked the complete-object-locator dword immediately before every primary, secondary, and tertiary table base. The refresh confirms:

- all fourteen primary table bases are still named for the expected item-action prompt class, with matching `??_R4...@@6B@` COL pointers at `base-4`;
- all ordinary direct-action prompts use primary first slot `0x005b7940`, secondary first slot `0x005b77c8`, and tertiary first slot `0x005b77d3`; the known `ThrowReallyInputPane` exception uses primary `0x005b7b80`, secondary `0x005b784c`, and tertiary `0x005b7857`;
- primary action slots at `+0x48` still resolve to the per-class submit/action handlers already listed in the tables, including `0x005b2830`, `0x005b3080`, `0x005b45f0`, `0x005b4920`, `0x005b4bb0`, `0x005b4e00`, `0x005b50b0`, `0x005b52f0`, `0x005b59d0`, `0x005b5b80`, `0x005b5de0`, `0x005b6000`, `0x005b6410`, and `0x005b66a0`;
- the latest data-xref set adds the same inline command-factory/dispatcher stores previously documented, such as `0x005a96eb`/`0x005a96f1`/`0x005a96fb` for `DropAllInputPane`, `0x005a97cb`/`0x005a97d1`/`0x005a97db` for `DropInputPane`, `0x005a998b`/`0x005a9991`/`0x005a999b` for `GiveInputPane`, and the constructor/raw-constructor store triads for all remaining direct item-action prompts.

## Direct Parent Gate

This vtable-family page is assigned upward to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md). The child is now `86/89`, and the file parent is `90/85`, so both clear the supervisor's strict `85/85` assignment gate. The direct parent is the source module that owns the declarations and constructors responsible for emitting these compiler-generated vtable records. The formal `RECONSTRUCTION_CPP CODE` block now emits only the accepted no-raw-vtable marker because the vtables should be regenerated from class declarations, and final virtual names/raw constructor boundary treatment still belong on the exact class/memory child pages rather than in this vtable inventory.

## Reconstruction Notes

[UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) is a non-emitting range inventory for the Throw/ThrowReally/Use/Eat executable island. It should not emit vtable-handler C++ or block class reconstruction; vtable-referenced handlers remain owned by their class pages and exact child pages.

The vtable inventory supports a compact `ui/dialogs/ItemActionInputPanes.cpp` source module for direct item command prompts, while keeping `ItemWhoInputPane` in the target-selection family and keeping `UserPane` as the command dispatcher. Raw/projected constructor starts such as [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md), [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md), [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md), [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md), and [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) should stay documented as constructor-shaped bytes but should not be used as IDA function-boundary or direct-call anchors until a route is found. For `TakeOffInputPane`, B007 accepts [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md) as formal first-draft `TakeOffInputPane::TakeOffInputPane()` source C++ because the exact raw bytes, `0x005aa0c0` inline factory mirror, prompt lookup, base construction, and vtable identity are source-ready; the no-function/no-route evidence remains an IDA anchor caveat rather than a no-code requirement. For `DropGoldInputPane`, B007 applies the same current raw-constructor policy to [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md): the exact child is formal first-draft constructor C++ ready through the `DropGoldInputPane` route, while no-function/no-start-xref/no-pointer/no-rel32 evidence remains an IDA/callgraph caveat and the live [UID:000044][DropInputPane](by-class/DropInputPane.md) inline construction mirror remains the supporting source-shape proof. For `GiveGoldInputPane`, B005 supersedes B015's no-code policy for [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md): the exact child is formal first-draft constructor C++ ready through the `GiveGoldInputPane` route, while no-function/no-start-xref/no-pointer evidence remains an IDA/callgraph caveat. Continue to use the live [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) inline construction mirror as supporting evidence and `0x00630090 -> 0x005b52f0` as the live submit-route anchor. For `ThrowReallyInputPane`, B006 applies the same retained raw-constructor policy to [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md): the exact child is formal first-draft `ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)` C++ ready through the `ThrowReallyInputPane` route, while no-function/no-start-xref/no-pointer evidence remains an IDA/callgraph caveat. The supporting source-shape proof is the exact 78-byte retained body, prompt id `0xa5`, `CharInputPane` base construction, three `ThrowReallyInputPane` vtable stores, inline construction mirrors at `0x005a7b70-0x005a7ba5` and `0x005abacd-0x005abb08`, and the inferred `m_itemSlot` byte at `this+0x108` consumed by confirmed-throw packet behavior. This vtable page itself now emits only the accepted comment-only no-raw-vtable marker because the tables are compiler-generated from class declarations.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md)
- [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md)
- [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md)
- [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md)
- [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md)
- [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md)
- [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md)
- [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md)
- [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block intentionally emits only the accepted no-raw-vtable marker. This is a compiler-output inventory, not a source target for raw vtable arrays.
- Route proof: this page records the fourteen item-action input pane class table triples, primary/secondary/tertiary bases, complete-object-locator pointers, constructor/factory/dispatcher store xrefs, shared destructor/adjustor thunks [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md), class pages, and exact method/helper pages. Source output is covered by declarations, constructors, virtual methods, and helpers under [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Rejected emission: raw vtable arrays in `ItemActionInputPanes.cpp` would be decompiler scaffolding rather than late-1999 through mid-2000s human-authored C++; the correct rebuild representation is compiler-generated data from class declarations and exact child methods.

## Changes

### 2026-05-31 - Scored IDA-verified item-action vtable family

- Before: validator metadata marked this page `COMPLETION:0`, `CONFIDENCE:0`, and left `RECONSTRUCTABLE` blank even though the page contained a broad vtable inventory.
- Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`. No parent attachment or C++ reconstruction code was added because raw constructor reachability, final virtual names, and original source declarations are not final-audit complete.
- Evidence: IDA MCP `py_eval` on 2026-05-31 confirmed every listed vtable base, primary/secondary/tertiary slot pattern, key action/input targets, shared adjustor/destructor thunks, and store xrefs for the item-action pane families.

### 2026-06-11 A007 Batch 154 parent-gate refresh

- Before: `COMPLETION:84`, `CONFIDENCE:88`, and no autogen parent; the direct file parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) already stood at `90/85`.
- Changed to: `COMPLETION:86`, `CONFIDENCE:89`, and `AUTOGEN_PARENT_UID:0000KC`. C++ remains blank.
- Evidence: live IDA MCP `py_eval` rechecked all fourteen primary/secondary/tertiary table triples, COL pointers, primary action slots, shared destructor/adjustor first slots, and constructor/factory/dispatcher store xrefs. The file parent owns the direct item-action prompt declarations that emit this vtable family and both sides now clear the strict `85/85` gate.

### 2026-06-13 A003 ThrowReallyInputPane raw-constructor range repair

- Before: UID `0001MM` references used `0x005b5b30-0x005b5b80`, including the two padding bytes before the `0x005b5b80` accept handler.
- Changed to: [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md), with `0x005b5b7e-0x005b5b80` recorded as alignment padding in the supervisor-owned by-memory ledger notes.
- Evidence: live IDA MCP byte audit on 2026-06-13 confirmed the raw constructor body ends at `retn 4` at `0x005b5b7e`, followed by two `0xcc` bytes before the modeled accept handler at `0x005b5b80`.

### 2026-06-20 B001 DropGold source-quality incorporation

- Score unchanged at `86/89`.
- Updated [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md) table wording so primary slot `+0x48` is source-facing `DropGoldInputPane::OnSubmit()` rather than the older descriptive `OnSubmitGoldAmount` wording.
- Added retained/no-route warning for [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md): use it as constructor evidence with the live inline mirror, not as an IDA function-boundary or direct-call anchor.

### 2026-06-22 B015 GiveGold source-quality incorporation

- Score unchanged at `86/89`.
- Updated [UID:00005T][GiveGoldInputPane](by-class/GiveGoldInputPane.md) table wording so primary slot `+0x48` / dword `0x00630090` points to current `OnSubmit` / descriptive `GiveGoldInputPane::OnSubmitGoldAmount` at `0x005b52f0`.
- Added retained/no-route warning for [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md): use it as constructor evidence with the live inline mirror in [UID:00005U][GiveInputPane](by-class/GiveInputPane.md), not as an IDA function-boundary or direct-call anchor.

### 2026-06-25 B007 TakeOff raw-constructor source-quality sync

- Score unchanged at `86/89`.
- Updated the reconstruction notes to state [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md) now has formal first-draft `TakeOffInputPane::TakeOffInputPane()` C++ while retaining no-function/no-route as an IDA anchor caveat.
- Evidence: current MCP session `80de0a67` and supplemental PE scan reconfirm exact `0x40` / 64-byte constructor body, `g_pLanguageMan->GetLocalizedString(0x22)`, `CharInputPane::CharInputPane(const wchar_t *)`, three TakeOff vtable stores, zero raw-start route hits, and the `0x005aa0c0` inline factory mirror.

### 2026-06-25 B005 GiveGold raw-constructor source-quality sync

- Score unchanged at `86/89`.
- Updated the reconstruction notes to state [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) now has formal first-draft `GiveGoldInputPane::GiveGoldInputPane()` C++ while retaining no-function/no-start-xref/no-pointer evidence as an IDA/callgraph caveat.
- Evidence: current MCP session `80de0a67` reconfirmed exact `0x40` / 64-byte constructor body, `g_pLanguageMan->GetLocalizedString(0x2b)`, `NumberInputPane::NumberInputPane(const wchar_t *)`, three GiveGold vtable stores `0x00630048`, `0x00630098`, and `0x006300c8`, zero raw-start route hits, the [UID:00005U][GiveInputPane](by-class/GiveInputPane.md) inline construction mirror, and `0x00630090 -> 0x005b52f0` as the live submit/action slot.

### 2026-06-25 B007 DropGold raw-constructor source-quality sync

- Score unchanged at `86/89`.
- Updated the DropGold table row and reconstruction notes to state [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md) now has formal first-draft `DropGoldInputPane::DropGoldInputPane()` C++ while retaining no-function/no-start-xref/no-pointer/no-rel32 evidence as an IDA/callgraph caveat.
- Evidence: current MCP session `80de0a67` reconfirmed exact `0x40` / 64-byte constructor body, `g_pLanguageMan->GetLocalizedString(7)`, `NumberInputPane::NumberInputPane(const wchar_t *)`, three DropGold vtable stores `0x0062fea4`, `0x0062fef4`, and `0x0062ff24`, zero raw-start route hits, STR.RES id `7` as the drop-gold amount prompt, and the [UID:000044][DropInputPane](by-class/DropInputPane.md) inline construction mirror.

### 2026-06-26 B006 ThrowReally raw-constructor source-quality sync

- Score unchanged at `86/89`.
- Updated the ThrowReallyInputPane table row and reconstruction notes to state [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) now has formal first-draft `ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)` C++ while retaining no-function/no-start-xref/no-pointer evidence as an IDA/callgraph caveat. This vtable-family page itself remains blank-C++ because vtables are compiler-generated from class declarations and are not the constructor emitter.
- Evidence: current MCP session `80de0a67` reconfirmed exact `0x4e` / 78-byte constructor body, prompt id `0xa5`, `g_pLanguageMan->GetLocalizedString`, `CharInputPane::CharInputPane`, three ThrowReallyInputPane vtable stores `0x00630278`, `0x006302c8`, and `0x006302f8`, zero raw-start function/xref/pointer route hits, construction mirrors in `sub_5A76C0` and `sub_5ABA80`, primary action slot route to `0x005b5b80`, and the stored `m_itemSlot` byte at `this+0x108` consumed by confirmed throw opcode `0x17`, mode `1`, length `3`.

### 2026-06-25 B010 Throw/Use/Eat aggregate source-quality sync

- Score unchanged at `86/89`.
- Added the [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) no-code routing note: the aggregate is a non-emitting range inventory, while vtable-referenced handlers remain class-owned.
- Evidence: current IDA MCP session `80de0a67` reconfirms the class method starts and vtable action slots for `ThrowInputPane`, `ThrowReallyInputPane`, `UseInputPane`, and `EatInputPane`; source decisions for those handlers belong on the class/exact child pages, not the aggregate range.
