*** UID:0003HF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Clan Bank Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `ClanItemDialog`, item deposit/withdraw dialogs, clan bank pane, and clan bank item-list pane.
- Direct owner: [UID:0000I9][ClanBank](by-file/ClanBank.md).
- Exact data page: [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md).
- Split from: [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md), which remains a broad non-emitting modal-plus-bank index.

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- | --- |
| `ClanItemDialog` | `0x00615fd8-0x00616078` | `0x00615fdc` | `0x00616040` | `0x00616070` | Raw constructor/reset/destructor stores at `0x0048a0d8`, `0x0048a100`, `0x0048a690`, `0x0048acf0`, and `0x0048c476`. |
| `ClanDepItemDialog` | `0x00616078-0x00616118` | `0x0061607c` | `0x006160e0` | `0x00616110` | Constructor stores at `0x0048a21a`, `0x0048a220`, and `0x0048a22a`. |
| `ClanWidItemDialog` | `0x00616118-0x006161b8` | `0x0061611c` | `0x00616180` | `0x006161b0` | Constructor stores at `0x0048a86a`, `0x0048a870`, and `0x0048a87a`. |
| `ClanItemListPane` | `0x006161b8-0x0061627c` | `0x006161bc` | `0x00616244` | `0x00616274` | Constructor stores at `0x0048aedb`, `0x0048aee1`, and `0x0048aeeb`. |
| `ClanBankPane` | `0x0061627c-0x00616318` | `0x00616280` | `0x006162e0` | `0x00616310` | Constructor/reset/destructor stores at `0x0048b239`, `0x0048b600`, and `0x0048c416`. |
| `ClanBankItemListPane` | `0x00616318-0x006163dc` | `0x0061631c` | `0x006163a4` | `0x006163d4` | Constructor store at `0x0048b92b` plus companion secondary/tertiary stores. |

## Boundary Evidence

- The exact span is `0x00615fd8-0x006163dc`, or `0x404` / 1028 bytes (Verified with int_convert.py).
- Live IDA MCP on 2026-06-12 lists 18 decorated bank/item-dialog vtable names in the range, from `??_7ClanItemDialog@@6B@` at `0x00615fdc` through `??_7ClanBankItemListPane@@6B@_1` at `0x006163d4`.
- Live bytes at `0x00615fd8` are `64 52 64 00 70 c4 48 00`, matching the `ClanItemDialog` complete-object-locator pointer followed by the first primary slot.
- Live bytes at `0x006163d4` are `b2 c2 48 00 90 4e 54 00`, the final `ClanBankItemListPane` tertiary entries.
- Live bytes at `0x006163dc` decode as UTF-16 `CLAN1.EP`, confirming the successor is the clan resource string block rather than another vtable record.

## Assignment Gate

`AUTOGEN_PARENT_UID` is [UID:0000I9][ClanBank](by-file/ClanBank.md). This page covers the clan-bank/item-dialog vtable family, and the direct file owner clears `86/85`. The broad [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md) must remain parent-blank because it also includes the modal-dialog vtables owned by the Clan source area.

## Score Rationale

Completion `87` and confidence `92` are supported by exact `.rdata` boundaries, decorated vtable names, bank/item class inventory, resource-string successor bytes, live store/xref checks for representative classes, and the strict-gate route to the current ClanBank source owner. The score remains below final-source quality because virtual slot names and the final split between `ClanBank.cpp` and possible item-dialog helper files are not settled.

## Cross-References

- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md)
- [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md)
- [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md)
- [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md)
- [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md)

## Changes

- 2026-06-12 A004 Batch 308:
  - Created as the source-local clan-bank by-vtable child of [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md).
  - Evidence: live IDA MCP confirmed the `0x00615fd8-0x006163dc` span, 18 decorated bank/item vtable names, boundary bytes, representative stores at `0x0048a0d8`, `0x0048b239`, and `0x0048b92b`, and the UTF-16 `CLAN1.EPF` successor boundary at `0x006163dc`.
