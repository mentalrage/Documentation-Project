*** UID:000026 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanBankPane

## Status

- Confidence: strong for local methods; medium for whether the slide-close helper is shared dialog infrastructure.
- Likely source file: [UID:0000I9][ClanBank](by-file/ClanBank.md)
- Current recovered file: `source-3/simroot_v2/class_ClanBankPane.cpp`

## Class Purpose

`ClanBankPane` is the main clan bank dialog. It selects item-bank or gold-bank mode from the server action type, creates the `cl` dialog resource, embeds a `ClanBankItemListPane`, tracks quantity input, sends close/submit packets, and clears the singleton `g_pClanBankPane` during destruction.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanBankPane` | `0x0048b1c0-0x0048b5f3` | Constructs the dialog, installs vtables, selects bank mode, creates buttons, quantity edit, item list, scroll wrapper, and count label. |
| vtable-reset helper | `0x0048b600-0x0048b629` | Real IDA function with no Wave3 owner; resets `ClanBankPane` vtables and clears the bank singleton before base teardown. |
| `OnDialogAction` | `0x0048b630-0x0048b7dc` | Sends close packet subtype `11`; on submit sends item/gold bank packet subtype `13` or `12` with slot and quantity, then closes. |
| raw packet helpers | [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) | Two function-shaped opcode `0x36` packet helpers without IDA function objects or inbound xrefs. |
| destructor/thunks | `0x0048c2bd`, `0x0048c2c8`, `0x0048c410-0x0048c46e` | Vtable thunks and scalar deleting destructor. |
| `AnimateDialogClose` | `0x0049ed60-0x0049ee41` | Sliding close animation currently owned by `ClanBankPane`, but likely shared with dialog pane behavior. |

## Evidence Notes

- IDA confirms real starts at `0x0048b1c0`, `0x0048b600`, `0x0048b630`, `0x0048c410`, and `0x0049ed60`.
- 2026-05-27 boundary pass corrected `OnDialogAction` to end at `0x0048b7dc`, then documented raw packet helpers at [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md).
- `g_pClanBankPane`, `g_pBackPane`, `g_pDisplayContext`, and `g_pNetConnection` tie the class to live UI/dialog and packet send state.
- The packet opcode `0x36` path in `OnDialogAction` is distinct from the `0x4b` item deposit/withdraw dialogs but still clan-bank feature owned.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md)
- [UID:00012V][0x0049ec80-0x0049ee41.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee41.ClanDialogSlideAnimation.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:000025][ClanBankItemListPane](by-class/ClanBankItemListPane.md)

## Changes

- 2026-05-27: Corrected constructor and `OnDialogAction` exclusive ends to `0x0048b5f3` and `0x0048b7dc`, then added raw packet helpers [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md). Evidence: IDA MCP reports `sub_48B1C0` at `0x0048b1c0-0x0048b5f3`, `sub_48B630` at `0x0048b630-0x0048b7dc`, and helper-shaped opcode `0x36` packet bodies at `0x0048b7e0` and `0x0048b870`.
- What existed before: the page documented local methods, packet helpers, singleton/global ties, and boundary corrections, but metadata remained `0/0`.
- What it was changed to: scores were set to `76/80`.
- Summary and evidence: dialog construction, action packet behavior, raw helper span, destructor, and clan-bank state ownership are covered; shared slide-close ownership and exact widget/layout fields remain open.
