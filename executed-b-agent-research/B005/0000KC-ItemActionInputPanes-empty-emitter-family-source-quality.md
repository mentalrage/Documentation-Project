** TARGET-REPORT-UID:0000KC **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
TARGET-REPORT-UID:0000KC

# 0000KC ItemActionInputPanes Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

Report-only research is complete for `[UID:0000KC]` `by-file/ItemActionInputPanes.md`.

Recommendation: keep the direct by-file ownership route under `ItemActionInputPanes`, clear the family empty markers with target-specific no-code/covered-by formal comments where the page is a class/container/range/vtable routing page, and add one concrete first-draft C++ body for the retained raw Wear packet sender `[UID:0002YP]`.

The implementation callback should not introduce broad class declarations or duplicate method bodies into class aggregate pages. The current binary evidence supports exact packet-helper source for `SendWearPacket`, but the class and aggregate empty markers are mostly ownership/routing pages whose bodies either already emit through child pages, are covered by exact split/index pages, or require exact method-page ownership rather than a whole-class page emission. Revision 1 below adds the stricter per-marker proof required by the supervisor rejection.

## Target

- Target UID: `0000KC`
- Target document: `source-3/project-documentation/by-file/ItemActionInputPanes.md`
- Generated file: `source-3/project-documentation/auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`
- Generated file status during this pass: current auto-generated file header shows validator command id `000000001491`, refreshed `2026-06-29T23:10:20-04:00`, source UID `0000KC`.
- Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/0000KC-ItemActionInputPanes-empty-emitter-family-source-quality.md`

## Current Target State

The current generated C++ for `ItemActionInputPanes.cpp` contains 33 total emitters: 14 filled and 19 marked empty. The filled emitters already cover several exact child bodies and retained helpers, including `ChangeItemSlotInputPane` constructor/input methods, gold input pane constructors, `TakeOffInputPane::TakeOffInputPane`, `ThrowReallyInputPane`, `SendWieldPacket`, `SendChangeItemSlotPacket`, `SendTakeOffPacket`, and `SendUseItemSlotPacket`.

The 19 remaining empty markers are not one uniform kind. They split into:

- class container pages with no standalone whole-class source body to emit;
- method/range aggregate pages that should not duplicate exact child bodies;
- one retained raw helper that has enough evidence for source-like packet send code;
- one vtable-family page whose data should be covered by class declarations and method pages rather than raw vtable array output.

## Generated Empty-Emitter Inventory

| UID | Current generated target | Generated lines | Disposition |
| --- | --- | ---: | --- |
| `00001J` | `by-class/ChangeItemSlotInputPane.md` | 85/88 | marker-only class routing container; child source is already routed by exact constructor/input/helper pages |
| `000042` | `by-class/DropAllInputPane.md` | 86/88 | marker-only class routing container; exact DropAll behavior is in the mixed drop/give aggregate evidence, not a whole-class page body |
| `000043` | `by-class/DropGoldInputPane.md` | 87/88 | marker-only class routing container; constructor source is exact child, submit/helper behavior remains aggregate evidence |
| `000044` | `by-class/DropInputPane.md` | 86/88 | marker-only class routing container; exact Drop behavior is in the mixed drop/give aggregate evidence |
| `000047` | `by-class/EatInputPane.md` | 86/88 | marker-only class routing container; exact Eat behavior is in the throw/use/eat aggregate evidence |
| `00005S` | `by-class/GiveAllInputPane.md` | 85/88 | marker-only class routing container; exact GiveAll behavior is in the mixed drop/give aggregate evidence |
| `00005T` | `by-class/GiveGoldInputPane.md` | 87/89 | marker-only class routing container; constructor source is exact child, submit/helper behavior remains aggregate evidence |
| `00005U` | `by-class/GiveInputPane.md` | 85/88 | marker-only class routing container; exact Give behavior is in the mixed drop/give aggregate evidence |
| `0000EC` | `by-class/TakeOffInputPane.md` | 88/86 | marker-only class routing container; constructor/helper/table/method evidence is split across exact pages and the range aggregate |
| `0001M1` | `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md` | 87/89 | marker-only method-range aggregate; do not emit a duplicate aggregate body |
| `0000EY` | `by-class/ThrowInputPane.md` | 86/90 | marker-only class routing container; exact Throw behavior is in the throw/use/eat aggregate evidence |
| `0000EZ` | `by-class/ThrowReallyInputPane.md` | 87/89 | marker-only class routing container; constructor and confirmed-send helper already emit from exact child pages |
| `0000FG` | `by-class/UseInputPane.md` | 86/88 | marker-only class routing container; use-item dispatch/helper evidence is already routed through adjacent exact pages |
| `0000G0` | `by-class/WearInputPane.md` | 87/91 | marker-only class routing container; Wear method cluster and packet helper are separate evidence pages |
| `0001MT` | `by-memory/0x005b6560-0x005b6760.WearInputPane.md` | 87/91 | marker-only method-range aggregate; concrete packet helper belongs to `0002YP` |
| `0002YP` | `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md` | 86/90 | source-bearing retained raw helper; add first-draft C++ packet send body |
| `0000G4` | `by-class/WieldInputPane.md` | 86/90 | marker-only class routing container; Wield method cluster and packet helper are separate evidence pages |
| `0001MR` | `by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md` | 86/90 | marker-only method-range aggregate; concrete packet helper already emits from `0001MS` |
| `0001XU` | `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` | 86/89 | marker-only vtable family; raw vtable data is compiler output from class/method declarations |

## Revision 1 Strict Per-Empty-Marker C++ / No-Code Proof

Supervisor rejection addressed in place. The first-draft `SendWearPacket` body remains valid after rechecking the current accepted sibling helper `[UID:0001MS]`: current `SendWieldPacket` formal C++ uses the same source-facing surfaces `PacketBufferWriteUInt8(value, out)` and `g_packetSender->QueueAndSendPacket(packet, 2)`. The Wear helper changes only opcode `0x12` to opcode `0x1e`.

For the remaining 18 empty markers, this report does not rely on a generic "container page" rationale. Each row below gives the exact target destination, formal action, and target-specific no-code/covered-by proof. The implementation callback should add the corresponding formal comment-only C++ block from the `First-Draft C++ Recommendation` section and preserve the proof in the target/support prose.

Declaration-container decision for by-class rows: do not emit narrow class declaration blocks in this callback. The current class pages document vtable identity and source ownership, while exact constructor/method/helper bodies are already routed through by-memory pages or split/index aggregate pages. A class declaration block would require stabilizing the shared input-pane inheritance header, destructor/adjustor thunk representation, virtual method names, and member fields across fourteen related panes before the declaration could be source-shaped. The safer implementation-ready action is a no-standalone-source formal comment plus exact child/range proof for each class page.

| UID | Destination | Formal action | Target-specific no-code / covered-by proof |
| --- | --- | --- | --- |
| `00001J` | `by-class/ChangeItemSlotInputPane.md` | comment-only no-code marker | Exact constructor source is `[UID:0001M5]` `0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor`; exact virtual key/submit source is `[UID:0001M6]` `0x005b3010-0x005b3196.ChangeItemSlotInputPane`; retained packet helper source is `[UID:00042U]` `0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender`. `[UID:0001XU]` records vtable slots `0x0062fa94 -> 0x005b3010` and `0x0062fa44 +0x48 -> 0x005b3080`. The class page has no additional source body to emit without duplicating exact children. |
| `000042` | `by-class/DropAllInputPane.md` | comment-only no-code marker | `[UID:0001MG]` covers exact DropAll ranges `0x005b44b0-0x005b4577` constructor, `0x005b4580-0x005b45ec` key handler, and `0x005b45f0-0x005b475c` confirm/slot submit. Exact all-items packet helper is `[UID:0003FK]` `0x005b4760-0x005b47dc.SendDropAllItemPacketRaw`. `[UID:0001XU]` records DropAll vtables `0x0062fd8c/0x0062fddc/0x0062fe0c`. The class page is an index over those exact ranges, not a standalone source body. |
| `000043` | `by-class/DropGoldInputPane.md` | comment-only no-code marker | Exact retained constructor source is `[UID:0001MH]` `0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor`; live submit method evidence is `0x005b4bb0-0x005b4c4a` inside `[UID:0001MG]`; retained packet helper is `[UID:0003FM]` `0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw`. `[UID:0001XU]` records `DropGoldInputPane::OnSubmit()` at primary slot `+0x48`. The class page should not duplicate the exact constructor child or create a whole declaration before the submit child is split. |
| `000044` | `by-class/DropInputPane.md` | comment-only no-code marker | `[UID:0001MG]` covers `0x005b47e0-0x005b48a7` constructor, `0x005b48b0-0x005b491c` key handler, and `0x005b4920-0x005b4ae4` submit/gold-routing handler. Exact single-drop helper is `[UID:0003FL]` `0x005b4af0-0x005b4b6c.SendDropItemPacketRaw`, and the gold branch constructs `[UID:000043]` / `[UID:0001MH]`. `[UID:0001XU]` records Drop vtable stores. The class page has no separate source body to emit. |
| `000047` | `by-class/EatInputPane.md` | comment-only no-code marker | `[UID:0001ML]` covers `0x005b5ec0-0x005b5f87` constructor, `0x005b5f90-0x005b5ffc` key handler, and `0x005b6000-0x005b60c0` confirm/submit path. `[UID:0001XU]` records Eat vtables `0x00630390/0x006303e0/0x00630410`, primary action slot `0x005b6000`, and secondary input slot `0x005b5f90`. Eat's opcode `0x1a` path must stay distinct from `[UID:0003NZ]` opcode `0x1c` retained Use helper. |
| `00005S` | `by-class/GiveAllInputPane.md` | comment-only no-code marker | `[UID:0001MG]` covers `0x005b4cc0-0x005b4d87` constructor, `0x005b4d90-0x005b4dfc` key handler, and `0x005b4e00-0x005b4eee` submit/confirmation handler. Exact all-items helper is `[UID:0003FN]` `0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw`. `[UID:0001XU]` records GiveAll vtables `0x0062ff30/0x0062ff80/0x0062ffb0`. The class page is covered by these exact range/helper records. |
| `00005T` | `by-class/GiveGoldInputPane.md` | comment-only no-code marker | Exact retained constructor source is `[UID:0001MI]` `0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor`; live submit evidence is `0x005b52f0-0x005b538a` inside `[UID:0001MG]`; adjacent retained no-route helper is `[UID:0003MW]` `0x005b5390-0x005b53f9.SendGiveGoldPacketRaw`, which stays no-code because the submit method emits equivalent packet logic inline. `[UID:0001XU]` records primary slot `0x00630090 -> 0x005b52f0`. |
| `00005U` | `by-class/GiveInputPane.md` | comment-only no-code marker | `[UID:0001MG]` covers `0x005b4f70-0x005b5037` constructor, `0x005b5040-0x005b50ac` key handler, and `0x005b50b0-0x005b5223` confirm/gold-routing handler. Exact single-give helper is `[UID:0003FO]` `0x005b5230-0x005b52ac.SendGiveItemPacketRaw`, and the gold branch constructs `[UID:00005T]` / `[UID:0001MI]`. `[UID:0001XU]` records Give vtable stores. |
| `0000EC` | `by-class/TakeOffInputPane.md` | comment-only no-code marker | Exact constructor source is `[UID:0001M0]`; exact shared file helper source is `[UID:0001M2]`; exact slot-key table declaration is `[UID:0001OF]` / `[UID:0000PX]`; exact method paths exist as `by-memory/0x005b2720-0x005b27b3.TakeOffInputPaneHandleTakeOffShortcut.md` and `by-memory/0x005b2830-0x005b296b.TakeOffInputPaneProcessUnequipCommand.md` despite validator-owned UID rewrite caveats. `[UID:0001M1]` remains the method/range index. The class page should not duplicate those exact children. |
| `0001M1` | `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md` | comment-only aggregate no-code marker | This range mixes exact shortcut method `0x005b2720-0x005b27b3`, padding `0x005b27b3-0x005b27c0`, shared helper `[UID:0001M2]` `0x005b27c0-0x005b2827`, padding `0x005b2827-0x005b2830`, exact submit/command method `0x005b2830-0x005b296b`, and padding `0x005b296b-0x005b2970`. Constructor `[UID:0001M0]`, helper `[UID:0001M2]`, and table `[UID:0001OF]` already emit separately. A parent aggregate body would duplicate the helper/table and flatten padding/split facts. |
| `0000EY` | `by-class/ThrowInputPane.md` | comment-only no-code marker | `[UID:0001ML]` covers Throw constructor `0x005b5890-0x005b5957`, key handler `0x005b5960-0x005b59cc`, and submit path `0x005b59d0-0x005b5aac`. Exact retained raw helper is `[UID:0003NX]` `0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw`. `[UID:0001XU]` records Throw vtable slots. The class page should not emit a whole-class declaration/body while exact method/helper ranges remain separately documented. |
| `0000EZ` | `by-class/ThrowReallyInputPane.md` | comment-only no-code marker | Exact constructor source is `[UID:0001MM]` `0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor`; accept handler evidence is `0x005b5b80-0x005b5c20` in `[UID:0001ML]`; exact confirmed-send helper source is `[UID:0003NY]` `0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw`; `[UID:0001XU]` records ThrowReally vtables and primary `+0x48 -> 0x005b5b80`. |
| `0000FG` | `by-class/UseInputPane.md` | comment-only no-code marker | `[UID:0001ML]` covers Use constructor `0x005b5ca0-0x005b5d67`, key handler `0x005b5d70-0x005b5ddc`, and submit/dispatch path `0x005b5de0-0x005b5e5c`; the live use path calls `[UID:0001KN]` `UseInventorySlotDispatch`; retained helper source is `[UID:0003NZ]` `SendUseItemSlotPacket(char itemSlot)`. `[UID:0001XU]` records Use vtable slots. The class page should not duplicate live dispatch or retained helper children. |
| `0000G0` | `by-class/WearInputPane.md` | comment-only no-code marker | `[UID:0001MT]` covers Wear constructor `0x005b6560-0x005b6627`, key handler `0x005b6630-0x005b669c`, and submit path `0x005b66a0-0x005b6760`; concrete retained helper source is `[UID:0002YP]`; `[UID:0001XU]` records Wear vtables `0x00630534/0x00630584/0x006305b4` and action/input slots. The class page is covered by the method cluster plus helper child, not by a standalone declaration block. |
| `0001MT` | `by-memory/0x005b6560-0x005b6760.WearInputPane.md` | comment-only aggregate no-code marker | This method cluster contains three modeled methods and internal padding: constructor `0x005b6560-0x005b6627`, padding `0x005b6627-0x005b6630`, key handler `0x005b6630-0x005b669c`, padding `0x005b669c-0x005b66a0`, and submit `0x005b66a0-0x005b6760`. The adjacent raw helper `[UID:0002YP]` is outside the half-open range and gets the concrete C++ body. Emitting aggregate C++ here would force unresolved shared event/text helper names and duplicate the exact helper split. |
| `0002YP` | `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md` | concrete first-draft C++ body | Source-bearing retained raw helper. MCP disassembly confirms opcode `0x1e`, selector byte from the stack argument, local terminator, send length `2`, `g_packetSender` dependency, no IDA function object, no start xrefs, and clean successor at `0x005b67c0`. Current `[UID:0001MS]` `SendWieldPacket` validates the source-facing helper names and packet-buffer shape. |
| `0000G4` | `by-class/WieldInputPane.md` | comment-only no-code marker | `[UID:0001MR]` covers Wield constructor `0x005b62d0-0x005b6397`, key handler `0x005b63a0-0x005b640c`, and submit path `0x005b6410-0x005b64fa`; exact packet helper source is `[UID:0001MS]`; `[UID:0001XU]` records Wield vtables `0x006304a8/0x006304f8/0x00630528` and action/input slots. No additional class-page source should emit. |
| `0001MR` | `by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md` | comment-only aggregate no-code marker | This method cluster contains constructor `0x005b62d0-0x005b6397`, padding `0x005b6397-0x005b63a0`, key handler `0x005b63a0-0x005b640c`, padding `0x005b640c-0x005b6410`, submit `0x005b6410-0x005b64fa`, and padding `0x005b64fa-0x005b6500`. Exact packet helper `[UID:0001MS]` already emits formal C++. First-drafting the three methods on this aggregate would require unresolved shared prompt setter, event field, text read, sound/panel helper, and `g_activeUserStatusPane +0x284` field names in one non-source aggregate destination, so the aggregate should remain no-code. |
| `0001XU` | `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` | comment-only vtable no-code marker | This page records compiler-generated vtable data for fourteen item-action input pane classes. Source output is covered by class declarations/method bodies that emit the constructors and virtual methods, not by raw array emission. The page names exact primary/secondary/tertiary table bases, COL pointers, constructor/factory/dispatcher store xrefs, shared destructor/adjustor thunks `[UID:0001N6]`, class pages, and method/helper pages. A raw vtable array in `ItemActionInputPanes.cpp` would be decompiler scaffolding rather than human source. |

Method-cluster no-code proof for `UID0001MR` and `UID0001MT`: current MCP decompilation, current aggregate docs, generated output, and vtable-family support docs were checked. The function boundaries and behaviors are known, but the destination pages are not exact source units: each page contains three methods plus alignment padding, while the source-bearing packet helper is already split to `[UID:0001MS]` or `[UID:0002YP]`. Emitting constructor/key/submit C++ from the aggregate would mix method bodies with padding ownership and would introduce still-unaccepted shared source surfaces for prompt assignment, event byte names, text-buffer access, sound/panel helpers, and the inventory-slot-count field. The implementation-ready repair for the current empty marker is therefore a formal no-code aggregate comment plus the exact boundary proof above; scores stay unchanged for the aggregate rows, and `UID0002YP` receives the only new concrete source body.

## MCP Evidence Status

IDA MCP was available and used during this report-only pass.

- Listener check: live on `127.0.0.1:13337`.
- MCP server: `ida-pro-mcp`, version `1.0.0`, protocol `2025-06-18`.
- Active database used for health/tool calls: `supervisor_resume_20260629`.
- `server_health` status: `ok`.
- IDB path reported by MCP: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input path reported by MCP: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Module: `NexusTK.exe`, imagebase `0x400000`.
- `auto_analysis_ready`: true.
- `hexrays_ready`: true.
- `strings_cache_ready`: true.
- `strings_cache_size`: 2067.
- Revision 1 recheck: JSON-RPC `initialize`, `tools/list`, and `tools/call server_health(database='supervisor_resume_20260629')` all succeeded; `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_size:2067` with uptime `6872.999` seconds.

One attempted `idb_meta` call failed because that MCP method is not in the active tool list. This is not a blocker because `server_health`, `lookup_funcs`, `decompile`, `disasm`, and `xrefs_to` were available and used.

## Evidence Checked

Read-only local evidence:

- `by-file/ItemActionInputPanes.md`
- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`
- `auto-generated/-ag-research-tracker.md`
- all 19 current empty-marker target/support docs listed in the inventory table
- relevant prior executed reports for the individual support leads, including DropGold, GiveGold, TakeOff, Wield packet helper, ChangeItemSlot raw helper, UseItemSlot raw helper, Throw/Use/Eat aggregate, ThrowConfirmed raw helper, and gold pane raw constructors
- Agent assignment history for `UID0001MT`; no direct completed report was found for that UID, so it is treated as assignment context only

Prior report search result:

- No direct registered report was found for `TARGET-REPORT-UID:0000KC`.
- Prior Surface/TargetSelection/ExchangeDialog Agent-B005 work is unrelated to this target and was not reused as target evidence.

## MCP Function And Range Facts

Representative function lookup for the ItemActionInputPanes family:

| Address | MCP result |
| --- | --- |
| `0x005b2fd0` | not a function |
| `0x005b3010` | `sub_5B3010`, size `0x6c` |
| `0x005b3080` | `sub_5B3080`, size `0x116` |
| `0x005b44b0` | `sub_5B44B0`, size `0xc7` |
| `0x005b4580` | `sub_5B4580`, size `0x6c` |
| `0x005b45f0` | `sub_5B45F0`, size `0x16c` |
| `0x005b47e0` | `sub_5B47E0`, size `0xc7` |
| `0x005b48b0` | `sub_5B48B0`, size `0x6c` |
| `0x005b4920` | `sub_5B4920`, size `0x1c4` |
| `0x005b4b70` | not a function |
| `0x005b4bb0` | `sub_5B4BB0`, size `0x9a` |
| `0x005b4cc0` | `sub_5B4CC0`, size `0xc7` |
| `0x005b4d90` | `sub_5B4D90`, size `0x6c` |
| `0x005b4e00` | `sub_5B4E00`, size `0xee` |
| `0x005b4f70` | `sub_5B4F70`, size `0xc7` |
| `0x005b5040` | `sub_5B5040`, size `0x6c` |
| `0x005b50b0` | `sub_5B50B0`, size `0x173` |
| `0x005b52b0` | not a function |
| `0x005b52f0` | `sub_5B52F0`, size `0x9a` |
| `0x005b2720` | `sub_5B2720`, size `0x93` |
| `0x005b27c0` | `sub_5B27C0`, size `0x67` |
| `0x005b2830` | `sub_5B2830`, size `0x13b` |
| `0x005b5890` | `sub_5B5890`, size `0xc7` |
| `0x005b5960` | `sub_5B5960`, size `0x6c` |
| `0x005b59d0` | `sub_5B59D0`, size `0xdc` |
| `0x005b5b30` | not a function |
| `0x005b5b80` | `sub_5B5B80`, size `0xa0` |
| `0x005b5c20` | not a function |
| `0x005b5ca0` | `sub_5B5CA0`, size `0xc7` |
| `0x005b5d70` | `sub_5B5D70`, size `0x6c` |
| `0x005b5de0` | `sub_5B5DE0`, size `0x7c` |
| `0x005b5e60` | not a function |
| `0x005b5ec0` | `sub_5B5EC0`, size `0xc7` |
| `0x005b5f90` | `sub_5B5F90`, size `0x6c` |
| `0x005b6000` | `sub_5B6000`, size `0xc0` |
| `0x005b62d0` | `sub_5B62D0`, size `0xc7` |
| `0x005b63a0` | `sub_5B63A0`, size `0x6c` |
| `0x005b6410` | `sub_5B6410`, size `0xea` |
| `0x005b6500` | `sub_5B6500`, size `0x60` |
| `0x005b6560` | `sub_5B6560`, size `0xc7` |
| `0x005b6630` | `sub_5B6630`, size `0x6c` |
| `0x005b66a0` | `sub_5B66A0`, size `0xc0` |
| `0x005b6760` | not a function |

Wield/Wear-specific MCP facts:

- `0x005b62d0` Wield constructor stores vtables `0x6304a8`, `0x6304f8`, `0x630528`, calls base setup, obtains local player text through `dword_67A748`, uses language string id `13`, formats a `wchar_t Buffer[128]`, and assigns the prompt through the existing input-pane text helper.
- `0x005b63a0` Wield key handler checks narrowed `?`, event byte `+266 == 4`, message byte `+4 == 8`, switches the panel through `unk_67A874` to `(2,0)`, plays sound `0x198` on `dword_67A7D0` at volume `100`, otherwise delegates to the base input handler.
- `0x005b6410` Wield submit requires one input character, maps `a-z` to `1..26`, maps `A-Z` to `27..52`, validates through the inventory/equipment object at `unk_69AE0C + 644`, and calls the Wield packet helper.
- `0x005b6500` Wield helper writes opcode `0x12`, selector byte, zero terminator, and sends packet length `2` through `dword_67A7EC`.
- `0x005b6560` Wear constructor stores vtables `0x630534`, `0x630584`, `0x6305b4`, calls base setup, obtains local player text through `dword_67A748`, uses language string id `33`, formats a `wchar_t Buffer[128]`, and assigns the prompt through the existing input-pane text helper.
- `0x005b6630` Wear key handler uses the same help shortcut shape as Wield.
- `0x005b66a0` Wear submit requires one input character, maps `a-z` to `1..26`, maps `A-Z` to `27..52`, validates through `unk_69AE0C + 644`, writes opcode `0x1e`, selector byte, zero terminator, and sends length `2`.
- `0x005b6760` is not an IDA function but disassembles as a retained packet helper. It writes opcode `0x1e`, writes selector byte from the stack argument, writes a zero terminator, calls the packet sender through `dword_67A7EC`, checks the stack cookie, and returns with `retn 4`. The next constructor starts at `0x005b67c0`.

Wield/Wear xref facts:

- No direct xrefs were found to Wield constructor `0x005b62d0`, Wear constructor `0x005b6560`, or raw Wear helper start `0x005b6760`.
- Wield vtable data references point to key handler `0x005b63a0` at `0x00630500` and submit handler `0x005b6410` at `0x006304f0`; constructor vtable stores occur at `0x005b6317`, `0x005b631d`, and `0x005b6327`.
- Wear vtable data references point to key handler `0x005b6630` at `0x0063058c` and submit handler `0x005b66a0` at `0x0063057c`; constructor vtable stores occur at `0x005b65a7`, `0x005b65ad`, and `0x005b65b7`.

## Heuristic And Source-Quality Reanalysis

### File Ownership

`ItemActionInputPanes` remains the correct by-file owner. The current generated file already groups the item action pane constructors, input handlers, and raw retained helpers under this source path. No evidence supports moving this family to `PacketBuffer`, `GameSocket`, the generic input pane base class, or a UI panel dispatcher owner.

### Class Container Pages

The by-class pages in this family are source ownership/routing containers. They do not currently carry enough synchronized class-declaration, inheritance, field-layout, and virtual-method naming evidence to emit full class declarations without risking invented source names or duplicated child method bodies. The project already has precedent for formal comment-only markers where a by-class or by-type page should not emit a standalone body because exact source belongs to child pages.

For this callback, class pages should receive explicit no-standalone marker comments, not whole class declarations. This is the current Rule 26/source-shape compliant path because it makes the generated output non-empty while preserving the correct source route and avoiding fake headers.

### Method/Range Aggregate Pages

`0x005b2720-0x005b296b.TakeOffInputPane`, `0x005b62d0-0x005b64fa.WieldInputPane`, and `0x005b6560-0x005b6760.WearInputPane` are aggregate/range pages containing multiple functions and padding boundaries. Emitting all method bodies from those aggregate pages would duplicate exact child helper pages and blur individual method ownership. They should receive marker-only formal C++ comments explaining their route.

This does not mean the contained methods lack binary evidence. It means the aggregate page is not the right emission unit for a body insertion during this by-file empty-emitter callback.

### Retained Raw Wear Packet Helper

`[UID:0002YP]` is the only current empty marker in the family that should receive a concrete code body in this pass. The helper mirrors the accepted Wield packet helper shape:

- local byte packet buffer;
- write opcode byte;
- write selector byte;
- zero terminate the next byte;
- queue/send length `2` through the retained packet sender;
- stack cleanup `retn 4` in the raw disassembly.

The recommended first-draft source keeps the source-facing signature as a plain static helper returning `int`, matching the already accepted Wield helper style. The observed ABI cleanup is documented in the page notes, but the formal source does not need an explicit calling convention unless the surrounding source style later requires it.

### Vtable Family

`ItemActionInputPaneVtableFamily` should not emit raw vtable arrays in source. The vtables are compiler output created by class declarations and virtual method definitions. The correct implementation action is a marker-only formal C++ comment that routes vtable evidence back to the item-action class/method family.

## Ranked Ownership / Source Route Candidates

1. `NexusTK::ui::dialogs::ItemActionInputPanes` by-file owner: accepted. It already owns the generated family and the child pages.
2. Individual by-class pages: accepted as routing containers only. They should not receive broad class declarations in this callback.
3. Individual by-memory child/helper pages: accepted for exact method/helper source where evidence supports it. `UID0002YP` qualifies now.
4. Vtable-family page: accepted only as compiler-output evidence, not as raw source data.
5. Packet sender or generic packet buffer owners: rejected as primary owner for these helpers because the opcodes and item-slot selection logic are item-action pane local source behavior.
6. Generic input pane base class or user pane owner: rejected for this family because constructors and submits set item-action-specific vtables, prompt ids, opcodes, and inventory/equipment selection rules.

## First-Draft C++ Recommendation

### Concrete Source Body For `UID0002YP`

Replace the empty `RECONSTRUCTION_CPP` block in `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md` with:

```cpp
static int SendWearPacket(unsigned char itemSlot)
{
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x1e, packet);
    PacketBufferWriteUInt8(itemSlot, packet + 1);
    packet[2] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 2);
}
```

Source-shape notes:

- No modern C++ constructs are introduced.
- `packet[128]` mirrors the retained helper pattern and accepted sibling Wield packet helper source shape.
- `PacketBufferWriteUInt8` and `g_packetSender->QueueAndSendPacket` are existing project source-facing surfaces already used by related accepted raw helper reports in this family.
- Revision 1 helper-name recheck: current `[UID:0001MS]` `SendWieldPacket` formal C++ uses `PacketBufferWriteUInt8(0x12, packet)`, `PacketBufferWriteUInt8(itemSlot, packet + 1)`, and `return g_packetSender->QueueAndSendPacket(packet, 2);`. `UID0002YP` should mirror that accepted source surface with opcode `0x1e`.
- The binary writes opcode `0x1e`, writes the selector argument to the second byte, writes a zero terminator at byte `2`, and sends length `2`.
- The raw disassembly shows `retn 4`; the source-facing helper remains `static int SendWearPacket(unsigned char itemSlot)` to match the sibling `SendWieldPacket` reconstruction. If the supervisor requires ABI spelling in this raw helper page, the only acceptable alternate header is `static int __stdcall SendWearPacket(unsigned char itemSlot)` with the same body.

### Marker-Only Formal C++ For Class Container Pages

These are exact insertion texts for the currently empty formal C++ blocks. They are comments by design.

`UID00001J`:

```cpp
// No standalone class-page emission for ChangeItemSlotInputPane; exact constructor, method, and retained-helper source is routed by [UID:0001M5], [UID:0001M6], and [UID:00042U].
```

`UID000042`:

```cpp
// No standalone class-page emission for DropAllInputPane; this page routes ownership for the exact DropAll method bodies documented in [UID:0001MG].
```

`UID000043`:

```cpp
// No standalone class-page emission for DropGoldInputPane; constructor source is [UID:0001MH] and submit/helper evidence is documented by [UID:0001MG].
```

`UID000044`:

```cpp
// No standalone class-page emission for DropInputPane; exact Drop method bodies and gold-branch evidence are documented in [UID:0001MG].
```

`UID000047`:

```cpp
// No standalone class-page emission for EatInputPane; exact Eat method bodies are documented in [UID:0001ML] and must stay separate from [UID:0003NZ].
```

`UID00005S`:

```cpp
// No standalone class-page emission for GiveAllInputPane; this page routes ownership for the exact GiveAll method bodies documented in [UID:0001MG].
```

`UID00005T`:

```cpp
// No standalone class-page emission for GiveGoldInputPane; constructor source is [UID:0001MI] and submit/helper evidence is documented by [UID:0001MG].
```

`UID00005U`:

```cpp
// No standalone class-page emission for GiveInputPane; exact Give method bodies and gold-branch evidence are documented in [UID:0001MG].
```

`UID0000EC`:

```cpp
// No standalone class-page emission for TakeOffInputPane; exact constructor, helper, table, and method evidence is routed by [UID:0001M0], [UID:0001M1], [UID:0001M2], and [UID:0001OF].
```

`UID0000EY`:

```cpp
// No standalone class-page emission for ThrowInputPane; exact Throw method bodies are documented in [UID:0001ML].
```

`UID0000EZ`:

```cpp
// No standalone class-page emission for ThrowReallyInputPane; constructor and confirmed-send helper source is routed by [UID:0001MM] and [UID:0003NY].
```

`UID0000FG`:

```cpp
// No standalone class-page emission for UseInputPane; live use dispatch remains [UID:0001KN] and adjacent helper source is [UID:0003NZ].
```

`UID0000G0`:

```cpp
// No standalone class-page emission for WearInputPane; method-cluster evidence is [UID:0001MT] and packet helper source is [UID:0002YP].
```

`UID0000G4`:

```cpp
// No standalone class-page emission for WieldInputPane; method-cluster evidence is [UID:0001MR] and packet helper source is [UID:0001MS].
```

### Marker-Only Formal C++ For Aggregate/Range Pages

`UID0001M1`:

```cpp
// No standalone aggregate emission; TakeOffInputPane source is split across [UID:0001M0], [UID:0001M2], [UID:0001OF], and the exact method boundaries recorded by this range.
```

`UID0001MR`:

```cpp
// No standalone aggregate emission; WieldInputPane helper source is emitted by [UID:0001MS], and this range records constructor, key-handler, and submit-handler boundaries.
```

`UID0001MT`:

```cpp
// No standalone aggregate emission; WearInputPane packet helper source is emitted by [UID:0002YP], and this range records constructor, key-handler, and submit-handler boundaries.
```

### Marker-Only Formal C++ For Vtable Family

`UID0001XU`:

```cpp
// No raw vtable emission; ItemActionInputPane vtables are compiler-generated from the item-action pane class declarations and exact child methods under [UID:0000KC].
```

## Score And Metadata Recommendation

Recommended score changes:

| UID | Recommendation |
| --- | --- |
| `0000KC` | keep `COMPLETION:90`, `CONFIDENCE:85`; by-file owner is correct, but many class/method names remain intentionally routed rather than body-emitting |
| `0002YP` | raise to `COMPLETION:88`, keep `CONFIDENCE:90`; first-draft C++ is now evidence-backed and mirrors sibling Wield helper, but no direct caller xref was found |
| class container UIDs | keep current scores; add marker-only C++ comments and route notes, not body code |
| `0001M1`, `0001MR`, `0001MT` | keep current scores; add aggregate marker-only C++ comments |
| `0001XU` | keep current score; add vtable marker-only C++ comment |

Metadata/action fields:

- Keep `PROPOSED_RECONSTRUCTION_PATH` under `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
- Keep `0000KC` as the generated source UID for the family.
- Keep owner/emitter routing unchanged for all target/support docs.
- Mark `UID0002YP` as reconstructable with the concrete first-draft code above.
- Mark marker-only pages as intentionally non-standalone emitters with exact routing comments, not as excluded or unrelated.

## Recommended Target And Support Doc Changes

Implementation callback should edit these docs only after short leases are acquired:

- `by-file/ItemActionInputPanes.md`: add a support note summarizing this direct family audit, the 19-marker disposition, and the `UID0002YP` concrete source body recommendation.
- `by-class/ChangeItemSlotInputPane.md`: add marker-only formal C++ and route note.
- `by-class/DropAllInputPane.md`: add marker-only formal C++ and route note.
- `by-class/DropGoldInputPane.md`: add marker-only formal C++ and route note.
- `by-class/DropInputPane.md`: add marker-only formal C++ and route note.
- `by-class/EatInputPane.md`: add marker-only formal C++ and route note.
- `by-class/GiveAllInputPane.md`: add marker-only formal C++ and route note.
- `by-class/GiveGoldInputPane.md`: add marker-only formal C++ and route note.
- `by-class/GiveInputPane.md`: add marker-only formal C++ and route note.
- `by-class/TakeOffInputPane.md`: add marker-only formal C++ and route note.
- `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`: add marker-only formal C++ and route note.
- `by-class/ThrowInputPane.md`: add marker-only formal C++ and route note.
- `by-class/ThrowReallyInputPane.md`: add marker-only formal C++ and route note.
- `by-class/UseInputPane.md`: add marker-only formal C++ and route note.
- `by-class/WearInputPane.md`: add marker-only formal C++ and route note.
- `by-memory/0x005b6560-0x005b6760.WearInputPane.md`: add marker-only formal C++ and route note.
- `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md`: add concrete first-draft C++ body and score update to `88/90`.
- `by-class/WieldInputPane.md`: add marker-only formal C++ and route note.
- `by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md`: add marker-only formal C++ and route note.
- `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`: add marker-only formal C++ and route note.

Do not edit generated files, coverage reports, validator state, IDA databases, executed archives, supervisor ledgers, or lock files.

## Validator Recommendation

No validators were run during report-only research.

Implementation callback should run scoped validation after the doc edits, including:

- scoped validators for each edited by-class/by-memory/by-type/by-file document;
- the reconstruction generator/validator path that refreshes `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`;
- an explicit freshness check on generated `ItemActionInputPanes.cpp`;
- an empty-marker check confirming the 19 listed markers are either resolved by the inserted formal C++ comments/body or intentionally accounted for by the validator output.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| `KC-R1-001` | `0000KC` currently has 19 generated empty markers. | High | Current generated `ItemActionInputPanes.cpp` header and marker list; tracker row lists 33 total emitters, 14 filled, 19 marked empty. | `by-file/ItemActionInputPanes.md` family audit note; this report `Generated Empty-Emitter Inventory`. | incorporate | applied |
| `KC-R1-002` | MCP is available and current for this revised report. | High | JSON-RPC `initialize`, `tools/list`, and `server_health(database='supervisor_resume_20260629')` succeeded; health returned `status:"ok"`, Hex-Rays ready, strings cache ready. | this report `MCP Evidence Status`; target audit note should cite MCP-backed evidence. | incorporate | applied |
| `KC-R1-003` | `UID0002YP` should mirror accepted `UID0001MS` helper names and packet source shape. | High | Current `[UID:0001MS]` formal C++ uses `PacketBufferWriteUInt8(value, out)` and `g_packetSender->QueueAndSendPacket(packet, 2)`; generated output confirms that body. | `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md` `RECONSTRUCTION_CPP` and source-quality notes. | incorporate | applied |
| `KC-R1-004` | `UID00001J` class page has no standalone source body to emit. | High | Exact source routes through `[UID:0001M5]`, `[UID:0001M6]`, and `[UID:00042U]`; vtable routes are recorded by `[UID:0001XU]`. | `by-class/ChangeItemSlotInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-005` | `UID000042` class page is covered by exact DropAll ranges and helper evidence. | High | `[UID:0001MG]` records DropAll constructor/key/submit ranges; `[UID:0003FK]` records all-items helper; `[UID:0001XU]` records vtables. | `by-class/DropAllInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-006` | `UID000043` class page is covered by constructor child, submit range, helper, and vtable evidence. | High | `[UID:0001MH]`, `[UID:0001MG]` `0x005b4bb0-0x005b4c4a`, `[UID:0003FM]`, and `[UID:0001XU]`. | `by-class/DropGoldInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-007` | `UID000044` class page is covered by exact Drop ranges and helper evidence. | High | `[UID:0001MG]` Drop constructor/key/submit ranges; `[UID:0003FL]`; DropGold construction branch through `[UID:0001MH]`; vtables in `[UID:0001XU]`. | `by-class/DropInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-008` | `UID000047` class page is covered by exact Eat ranges and vtable evidence. | High | `[UID:0001ML]` Eat constructor/key/submit ranges; `[UID:0001XU]` Eat vtable action/input slots; opcode `0x1a` distinction from `[UID:0003NZ]`. | `by-class/EatInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-009` | `UID00005S` class page is covered by exact GiveAll ranges and helper evidence. | High | `[UID:0001MG]` GiveAll constructor/key/submit ranges; `[UID:0003FN]`; vtables in `[UID:0001XU]`. | `by-class/GiveAllInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-010` | `UID00005T` class page is covered by exact constructor, submit, retained helper, and vtable evidence. | High | `[UID:0001MI]`, `[UID:0001MG]` `0x005b52f0-0x005b538a`, `[UID:0003MW]`, and `[UID:0001XU]` `0x00630090 -> 0x005b52f0`. | `by-class/GiveGoldInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-011` | `UID00005U` class page is covered by exact Give ranges and helper evidence. | High | `[UID:0001MG]` Give constructor/key/submit ranges; `[UID:0003FO]`; GiveGold branch through `[UID:0001MI]`; vtables in `[UID:0001XU]`. | `by-class/GiveInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-012` | `UID0000EC` class page is covered by TakeOff exact children and table/helper pages. | High | `[UID:0001M0]`, `[UID:0001M1]`, `[UID:0001M2]`, `[UID:0001OF]`, exact method paths `0x005b2720-0x005b27b3` and `0x005b2830-0x005b296b`, plus vtable evidence. | `by-class/TakeOffInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-013` | `UID0001M1` is an aggregate/index and must not emit duplicate source bodies. | High | Range mixes shortcut method, padding, shared helper `[UID:0001M2]`, submit method, and padding; constructor/table/helper already emit separately. | `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md` formal comment and aggregate no-code proof. | incorporate | applied |
| `KC-R1-014` | `UID0000EY` class page is covered by exact Throw ranges, raw helper, and vtable evidence. | High | `[UID:0001ML]`, `[UID:0003NX]`, and `[UID:0001XU]`. | `by-class/ThrowInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-015` | `UID0000EZ` class page is covered by exact ThrowReally constructor, accept range, confirmed-send helper, and vtable evidence. | High | `[UID:0001MM]`, `[UID:0001ML]` `0x005b5b80-0x005b5c20`, `[UID:0003NY]`, and `[UID:0001XU]`. | `by-class/ThrowReallyInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-016` | `UID0000FG` class page is covered by exact Use ranges, live dispatch child, retained helper, and vtable evidence. | High | `[UID:0001ML]`, `[UID:0001KN]`, `[UID:0003NZ]`, and `[UID:0001XU]`. | `by-class/UseInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-017` | `UID0000G0` class page is covered by Wear method cluster, raw helper child, and vtable evidence. | High | `[UID:0001MT]`, `[UID:0002YP]`, and `[UID:0001XU]`. | `by-class/WearInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-018` | `UID0001MT` is a method cluster and must not emit aggregate C++ in this callback. | Medium-high | Range contains constructor/key/submit methods and padding; raw helper `[UID:0002YP]` is outside the half-open range and gets concrete C++; method bodies require unresolved shared source-facing helper/field names. | `by-memory/0x005b6560-0x005b6760.WearInputPane.md` formal comment and aggregate no-code proof. | incorporate | applied |
| `KC-R1-019` | `UID0002YP` is source-bearing and should receive first-draft `SendWearPacket` C++. | High | MCP disassembly confirms opcode `0x1e`, selector byte, terminator, length-2 send, `retn 4`, no function object/start xrefs, and clean successor; `[UID:0001MS]` validates helper names. | `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md` formal C++ block and metadata. | incorporate | applied |
| `KC-R1-020` | `UID0000G4` class page is covered by Wield method cluster, helper child, and vtable evidence. | High | `[UID:0001MR]`, `[UID:0001MS]`, and `[UID:0001XU]`. | `by-class/WieldInputPane.md` formal comment and route note. | incorporate | applied |
| `KC-R1-021` | `UID0001MR` is a method cluster and must not emit aggregate C++ in this callback. | Medium-high | Range contains constructor/key/submit methods and padding; helper `[UID:0001MS]` already emits; method bodies require unresolved shared prompt/event/text/sound/panel/field source names. | `by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md` formal comment and aggregate no-code proof. | incorporate | applied |
| `KC-R1-022` | `UID0001XU` vtable page should not emit raw vtable arrays. | High | Vtables are compiler-generated from class declarations/methods; page records table bases, COL pointers, store xrefs, shared destructor/adjustor thunks, and class/method route evidence. | `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` formal comment and vtable no-code proof. | incorporate | applied |
| `KC-R1-023` | No direct prior report supersedes this direct `0000KC` report. | High | Search by `TARGET-REPORT-UID:0000KC`, target path, owner/name, address ranges, and family terms found support-lead reports only. | this report `Evidence Checked`; optional by-file audit provenance note. | incorporate | applied |
| `KC-R1-024` | Agent-B007 `UID0001MT` assignment context does not supersede this report. | High | Assignment notes exist, but no completed `0001MT` report file was found; Wear range was rechecked directly. | this report `Evidence Checked`; `by-memory/0x005b6560-0x005b6760.WearInputPane.md` implementation note if accepted. | incorporate | applied |
## Callback Application Proof

Implementation callback status: applied. The supervisor-accepted report details were incorporated into the target/support by-* documents under short leases. The first lease set expired during editing/validation; a fresh final lease set was acquired for the completed edit/validator batch and released with `python .\leaser.py B005 unlease`. A post-release lease report showed no active B005 leases; unrelated active B013 leases remained on SoftwareBlend16-related files only.

Ledger proof by claim group:

| Claim IDs | Applied destination proof |
| --- | --- |
| `KC-R1-001`, `KC-R1-002`, `KC-R1-023`, `KC-R1-024` | `by-file/ItemActionInputPanes.md` now contains `## B005 2026-06-30 Empty-Emitter Family Audit` with the direct `0000KC` generated baseline, MCP `supervisor_resume_20260629` evidence, prior-report audit, B007 non-supersession note, 19-row disposition, and `UID0002YP` source-ready exception. |
| `KC-R1-003`, `KC-R1-019` | `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md` now has `COMPLETION:88`, `CONFIDENCE:90`, the accepted `SendWearPacket(unsigned char itemSlot)` first-draft C++ body in the formal `RECONSTRUCTION_CPP CODE` block, and `## B005 2026-06-30 Source-Ready Helper Callback` with sibling `UID0001MS` helper-name proof and binary packet-flow proof. |
| `KC-R1-004` through `KC-R1-012`, `KC-R1-014` through `KC-R1-017`, and `KC-R1-020` | The 14 by-class pages now have the accepted formal no-standalone-source C++ comment in their `RECONSTRUCTION_CPP CODE` block plus `[[CHILDREN]]`, preserving exact child source routing in generated `ItemActionInputPanes.cpp`; each page also has `## B005 2026-06-30 Empty-Emitter Callback` with target-specific route proof. |
| `KC-R1-013`, `KC-R1-018`, `KC-R1-021` | The three method/range aggregate pages now have accepted formal aggregate no-code comments and B005 callback notes preserving constructor/key/submit/helper/padding split proof. |
| `KC-R1-022` | `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` now has the accepted formal no-raw-vtable comment and B005 callback note preserving compiler-generated vtable proof. |

Implementation detail: `[[CHILDREN]]` was intentionally retained/inserted on class pages with formal comment-only markers because the first generated refresh cleared empty markers but suppressed exact child emitters. The final validated shape emits the accepted no-standalone class comment and the exact children; class pages with no attached child source render `[[No Children Attached]]`, which is generated child-routing output, not an unresolved empty marker.

## Implementation Tracking Checklist

- [x] Supervisor validation was received; callback edits were limited to the accepted `0000KC` target/support by-* documents and this Agent-B005 report.
- [x] Short leases were used for `by-file/ItemActionInputPanes.md`, the 14 by-class docs, the four by-memory docs, and `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`; final B005 leases were released and confirmed absent.
- [x] `by-file/ItemActionInputPanes.md` was updated with the direct `0000KC` family audit note, current generated baseline, MCP revision recheck, 19-row disposition, and `UID0002YP` source-ready exception.
- [x] `by-class/ChangeItemSlotInputPane.md` has the exact `UID00001J` formal no-code comment, child routing, and route proof to `UID0001M5`, `UID0001M6`, `UID00042U`, and `UID0001XU`.
- [x] `by-class/DropAllInputPane.md` has the exact `UID000042` formal no-code comment, child routing, and route proof to `UID0001MG`, `UID0003FK`, and `UID0001XU`.
- [x] `by-class/DropGoldInputPane.md` has the exact `UID000043` formal no-code comment, child routing, and route proof to `UID0001MH`, `UID0001MG`, `UID0003FM`, and `UID0001XU`.
- [x] `by-class/DropInputPane.md` has the exact `UID000044` formal no-code comment, child routing, and route proof to `UID0001MG`, `UID0003FL`, `UID0001MH`, and `UID0001XU`.
- [x] `by-class/EatInputPane.md` has the exact `UID000047` formal no-code comment, child routing, route proof to `UID0001ML`/`UID0001XU`, and opcode distinction from `UID0003NZ`.
- [x] `by-class/GiveAllInputPane.md` has the exact `UID00005S` formal no-code comment, child routing, and route proof to `UID0001MG`, `UID0003FN`, and `UID0001XU`.
- [x] `by-class/GiveGoldInputPane.md` has the exact `UID00005T` formal no-code comment, child routing, and route proof to `UID0001MI`, `UID0001MG`, `UID0003MW`, and `UID0001XU`.
- [x] `by-class/GiveInputPane.md` has the exact `UID00005U` formal no-code comment, child routing, and route proof to `UID0001MG`, `UID0003FO`, `UID0001MI`, and `UID0001XU`.
- [x] `by-class/TakeOffInputPane.md` has the exact `UID0000EC` formal no-code comment, child routing, and route proof to `UID0001M0`, `UID0001M1`, `UID0001M2`, `UID0001OF`, and exact method paths `0x005b2720-0x005b27b3` / `0x005b2830-0x005b296b`.
- [x] `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md` has the exact `UID0001M1` formal no-code comment and function/padding/helper split proof.
- [x] `by-class/ThrowInputPane.md` has the exact `UID0000EY` formal no-code comment, child routing, and route proof to `UID0001ML`, `UID0003NX`, and `UID0001XU`.
- [x] `by-class/ThrowReallyInputPane.md` has the exact `UID0000EZ` formal no-code comment, child routing, and route proof to `UID0001MM`, `UID0001ML`, `UID0003NY`, and `UID0001XU`.
- [x] `by-class/UseInputPane.md` has the exact `UID0000FG` formal no-code comment, child routing, and route proof to `UID0001ML`, `UID0001KN`, `UID0003NZ`, and `UID0001XU`.
- [x] `by-class/WearInputPane.md` has the exact `UID0000G0` formal no-code comment, child routing, and route proof to `UID0001MT`, `UID0002YP`, and `UID0001XU`.
- [x] `by-memory/0x005b6560-0x005b6760.WearInputPane.md` has the exact `UID0001MT` formal no-code comment and constructor/key/submit/padding split proof plus the `UID0002YP` helper split.
- [x] `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md` has the exact first-draft `SendWearPacket` C++ body, helper-name revalidation proof, and score/metadata update to `COMPLETION:88`, `CONFIDENCE:90`.
- [x] `by-class/WieldInputPane.md` has the exact `UID0000G4` formal no-code comment, child routing, and route proof to `UID0001MR`, `UID0001MS`, and `UID0001XU`.
- [x] `by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md` has the exact `UID0001MR` formal no-code comment and constructor/key/submit/padding split proof plus the `UID0001MS` helper split.
- [x] `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` has the exact `UID0001XU` formal no-code comment and compiler-output proof naming table bases, COL pointers, store xrefs, shared thunks, class pages, and method/helper pages.
- [x] `0000KC` score/metadata and owner/emitter/path were kept unchanged; marker-only class/aggregate/vtable scores were kept unchanged.
- [x] This report's Claim And Incorporation Ledger was updated from `proposed` to `applied`; proof is recorded in the callback proof table above.

Scoped validator results from `source-3/project-documentation`:

| File | Command ID | Timestamp | Result |
| --- | --- | --- | --- |
| `by-file/ItemActionInputPanes.md` | `000000001752` | `2026-06-30T00:03:37-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:36` |
| `by-class/ChangeItemSlotInputPane.md` | `000000001753` | `2026-06-30T00:03:42-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:2`, `stats_row_update:3` |
| `by-class/DropAllInputPane.md` | `000000001754` | `2026-06-30T00:03:49-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:2` |
| `by-class/DropGoldInputPane.md` | `000000001755` | `2026-06-30T00:03:55-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:6` |
| `by-class/DropInputPane.md` | `000000001756` | `2026-06-30T00:04:01-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:2` |
| `by-class/EatInputPane.md` | `000000001757` | `2026-06-30T00:04:08-04:00` | exit `0`, ok `1`, generated refresh deferred |
| `by-class/GiveAllInputPane.md` | `000000001758` | `2026-06-30T00:04:14-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:7`, `stats_row_update:1` |
| `by-class/GiveGoldInputPane.md` | `000000001759` | `2026-06-30T00:04:21-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:8` |
| `by-class/GiveInputPane.md` | `000000001760` | `2026-06-30T00:04:27-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:7`, `stats_row_update:1` |
| `by-class/TakeOffInputPane.md` | `000000001761` | `2026-06-30T00:04:34-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:1`, `stats_row_update:1` |
| `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md` | `000000001762` | `2026-06-30T00:04:41-04:00` | exit `0`, ok `1`, generated refresh deferred |
| `by-class/ThrowInputPane.md` | `000000001763` | `2026-06-30T00:04:48-04:00` | exit `0`, ok `1`, generated refresh deferred, `missing_ref_uid:2` |
| `by-class/ThrowReallyInputPane.md` | `000000001765` | `2026-06-30T00:04:54-04:00` | exit `0`, ok `1`, generated refresh deferred |
| `by-class/UseInputPane.md` | `000000001766` | `2026-06-30T00:05:01-04:00` | exit `0`, ok `1`, generated refresh deferred |
| `by-class/WearInputPane.md` | `000000001767` | `2026-06-30T00:05:07-04:00` | exit `0`, ok `1`, generated refresh deferred |
| `by-memory/0x005b6560-0x005b6760.WearInputPane.md` | `000000001768` | `2026-06-30T00:05:13-04:00` | exit `0`, ok `1`, generated refresh deferred |
| `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md` | `000000001769` | `2026-06-30T00:05:19-04:00` | exit `0`, ok `1`, generated refresh deferred |
| `by-class/WieldInputPane.md` | `000000001770` | `2026-06-30T00:05:26-04:00` | exit `0`, ok `1`, generated refresh deferred |
| `by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md` | `000000001771` | `2026-06-30T00:05:32-04:00` | exit `0`, ok `1`, generated refresh deferred |
| `by-type/by-vtable/ItemActionInputPaneVtableFamily.md` | `000000001772` | `2026-06-30T00:05:41-04:00` | exit `0`, ok `1`, generated refresh deferred, `stats_row_update:1` |

Generated output inspection:

- [x] `python .\tools\validator.py --mode file --file by-file/ItemActionInputPanes.md --apply --queue-timeout 240 --wait-generated` completed as command id `000000001773`, timestamp `2026-06-30T00:05:54-04:00`, exit `0`, ok `1`, with `autogen_cpp_update:1`, `generated_refresh:completed`, and `generated_refresh_command_id:000000001773`.
- [x] `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` was inspected after generation. Its header still records `validator-command-id: 000000001772`, `validator-refreshed-at: 2026-06-30T00:05:41-04:00`, `validator-refresh-source: deferred-generated-refresh`, source UID `0000KC`; this is older than wait command `000000001773`, but command `000000001773` reported the generated refresh completed and the content reflects the accepted callback.
- [x] Generated `Empty Emitter Marker` count is `0`.
- [x] Generated output contains accepted comment/body emitters for `UID0001M1`, `UID0001MT`, `UID0002YP`, `UID0001MR`, `UID0001XU`, and all 14 class no-standalone markers; `UID0002YP` contains `static int SendWearPacket(unsigned char itemSlot)` and `PacketBufferWriteUInt8(0x1e, packet)`.
- [x] Final lease release completed successfully for the 20 edited by-* docs; post-release state had no active B005 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000KC-ItemActionInputPanes-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0000KC-ItemActionInputPanes-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T00:12:06","uid":"0000KC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
