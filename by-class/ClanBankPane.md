*** UID:000026 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanBankPane

## Status

- Confidence: strong for constructor/action/vtable singleton behavior and ClanBank ownership; medium for exact original virtual names, final widget field names, and whether the slide-close helper is shared dialog infrastructure.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Documented source grouping: [UID:0000I9][ClanBank](by-file/ClanBank.md), with a possible `ClanItemDialogs.cpp` companion split.

## Class Purpose

`ClanBankPane` is the main clan bank dialog. It selects item-bank or gold-bank mode from the server action type, creates the `cl` dialog resource, embeds a `ClanBankItemListPane`, tracks quantity input, sends close/submit packets, and clears the singleton `g_pClanBankPane` during destruction.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanBankPane` | `0x0048b1c0-0x0048b5f3` | Constructs the dialog, installs vtables, selects bank mode from packet action `10` or `16`, creates buttons, quantity edit, item list, scroll wrapper, and count/gold label. |
| vtable-reset helper | `0x0048b600-0x0048b629` | Real IDA function with no direct xrefs; writes `ClanBankPane` vtables at object offsets `+0x0/+0xa0/+0xa4`, clears the bank singleton, then tail-calls base teardown. |
| `OnDialogAction` | `0x0048b630-0x0048b7dc` | Vtable-reached action handler; action `1` sends close packet subtype `11`, and action `2` submits selected bank item/amount with subtype `13` or `12`, then closes. |
| raw packet helpers | [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) | Two function-shaped opcode `0x36` packet helpers without IDA function objects or inbound xrefs. |
| destructor/thunks | `0x0048c2bd`, `0x0048c2c8`, `0x0048c410-0x0048c46e` | Vtable thunks and scalar deleting destructor. |
| `AnimateDialogClose` | `0x0049ed60-0x0049ee41` | Sliding close animation currently owned by `ClanBankPane`, but likely shared with dialog pane behavior. |

## Evidence Notes

- IDA confirms real starts at `0x0048b1c0`, `0x0048b600`, `0x0048b630`, `0x0048c410`, and `0x0049ed60`.
- 2026-05-27 boundary pass corrected `OnDialogAction` to end at `0x0048b7dc`, then documented raw packet helpers at [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md).
- `g_pClanBankPane`, `g_pBackPane`, `g_pDisplayContext`, and `g_pNetConnection` tie the class to live UI/dialog and packet send state.
- The packet opcode `0x36` path in `OnDialogAction` is distinct from the `0x4b` item deposit/withdraw dialogs but still clan-bank feature owned.
- 2026-06-05 live IDA MCP `lookup_funcs` reports modeled functions at `0x0048b1c0` size `0x433`, `0x0048b600` size `0x29`, and `0x0048b630` size `0x1ac`; `xrefs_to` reports constructor code xrefs at `0x00508739` and `0x00513b2f`, no direct vtable-reset xrefs, and the action handler vtable data xref at `0x006162c8`.
- Constructor decompilation writes the `g_pClanBankPane` singleton at `0x0067ade8`, installs three ClanBankPane vtables, stores mode at object offset `+0x26c`, returns early unless action is `10` or `16`, creates the `cl` dialog, button IDs `30` plus mode-specific `53` or `23`, quantity edit default `L"1"`, a child [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md), and a count/gold label before attaching to the back pane/display context.
- Action handler decompilation reads list control `4` and quantity edit control `3`; valid submit sends opcode `0x36`, subtype `13 - (mode != 0)`, selected slot byte, multi-count flag, and parsed amount as a length-`9` packet, then sends the length-`2` close packet `0x36, 11`.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md)
- [UID:00012V][0x0049ec80-0x0049ee41.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee41.ClanDialogSlideAnimation.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:000025][ClanBankItemListPane](by-class/ClanBankItemListPane.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)

## Changes

- 2026-05-27: Corrected constructor and `OnDialogAction` exclusive ends to `0x0048b5f3` and `0x0048b7dc`, then added raw packet helpers [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md). Evidence: IDA MCP reports the constructor at `0x0048b1c0-0x0048b5f3`, action handler at `0x0048b630-0x0048b7dc`, and helper-shaped opcode `0x36` packet bodies at `0x0048b7e0` and `0x0048b870`.
- What existed before: the page documented local methods, packet helpers, singleton/global ties, and boundary corrections, but metadata remained `0/0`.
- What it was changed to: scores were set to `76/80`.
- Summary and evidence: dialog construction, action packet behavior, raw helper span, destructor, and clan-bank state ownership are covered; shared slide-close ownership and exact widget/layout fields remain open.
- 2026-06-05: Initially marked reconstructable but left `AUTOGEN_PARENT_UID` blank because the class was still `76/80`, below the 80/80 parent-attachment gate, even though [UID:0000I9][ClanBank](by-file/ClanBank.md) was the likely owner. Live IDA MCP `lookup_funcs` confirmed exact starts at `0x0048b1c0`, `0x0048b600`, `0x0048b630`, `0x0048c2bd`, `0x0048c2c8`, `0x0048c410`, and `0x0049ed60`, while `0x0048b7e0` and `0x0048b870` remained non-function raw packet-helper bodies.
- 2026-06-05: Raised scores to `82/86` and attached parent [UID:0000I9][ClanBank](by-file/ClanBank.md) after live IDA MCP decompilation/caller/callee/xref review documented constructor mode selection, child list construction, singleton writes/clears, vtable-only action dispatch, opcode `0x36` close/submit packet bytes, and caller ties from the map packet/clan-bank routing paths. Final C++ remains blank under the 95/95 gate because original method names, widget member names, and shared slide-helper placement are still not final.
- 2026-06-05: Removed stale recovered-source/global/offset wording while preserving the `82/86` score.
