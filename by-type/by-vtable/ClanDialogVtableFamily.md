*** UID:0001X9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Clan Dialog Vtable Family

## Status

- Disposition: vtable family inventory for reconstructable NexusTK Clan dialog code.
- Covered source owner: [UID:0000I8][Clan](by-file/Clan.md), with [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) as a possible UI-dialog split.
- Confidence: strong for table bases, RTTI presence, and vtable store/xref evidence; medium for final original source-file split.
- Verification: IDA MCP `list_globals` and vtable xref checks on 2026-05-26, plus IDA MCP `py_eval` vtable/xref recheck on 2026-05-31 for the full `0x006158f8-0x006163d4` clan modal and clan-bank vtable block. Current `simroot_v2` class metadata is a hint only and reports `vtable_count: 0` for the checked classes.

## Name And Money Dialog Tables

These classes are `ClanNameInputDialog` shells or derived one-action variants. The three vtable bases follow the same primary/secondary/tertiary pane shape seen in other dialog families.

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Store / xref evidence |
| --- | --- | --- | --- | --- |
| `ClanNameInputDialog` | `0x006158f8` | `0x0061595c` | `0x0061598c` | stores at `0x00488b9e`, `0x00488ba4`, `0x00488bae` |
| `ClanDepMoneyInputDialog` | `0x00615998` | `0x006159fc` | `0x00615a2c` | xrefs at `0x00485120`, `0x00487de4`, `0x00488fb2` and companions |
| `ClanWidMoneyInputDialog` | `0x00615a38` | `0x00615a9c` | `0x00615acc` | xrefs at `0x00485398`, `0x004884d4`, `0x00489082` and companions |
| `ClanExpelNameInputDialog` | `0x00615ad8` | `0x00615b3c` | `0x00615b6c` | xrefs at `0x004851cb`, `0x004881e4`, `0x00489152` and companions |
| `ClanSummonNameInputDialog` | `0x00615b78` | `0x00615bdc` | `0x00615c0c` | xrefs at `0x0048522c`, `0x00488294`, `0x00489282` and companions |
| `ClanAppearNameInputDialog` | `0x00615c18` | `0x00615c7c` | `0x00615cac` | xrefs at `0x00485284`, `0x0048833c`, `0x004893b2` and companions |
| `ClanChangeNameInputDialog` | `0x00615cb8` | `0x00615d1c` | `0x00615d4c` | xrefs at `0x00485337`, `0x0048842e`, `0x004894e2` and companions |

## Attribute, Enlist, Change, And Leave Tables

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Store / xref evidence |
| --- | --- | --- | --- | --- |
| `ClanAttrInputDialog` | `0x00615d58` | `0x00615dbc` | `0x00615dec` | stores at `0x00489660`, `0x00489666`, `0x00489670` |
| `ClanEnlistInputDialog` | `0x00615df8` | `0x00615e5c` | `0x00615e8c` | xrefs at `0x00487f34`, `0x00489f92` and companions |
| `ClanChangeInputDialog` | `0x00615e98` | `0x00615efc` | `0x00615f2c` | xrefs at `0x004852ee`, `0x004883ed`, `0x0048a002` and companions |
| `ClanLeaveConfirmDialog` | `0x00615f38` | `0x00615fa0` | `0x00615fd0` | xrefs at `0x004850a7`, `0x00487d22`, `0x0048a07b` and companions |

## Bank And Item Dialog Tables

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Store / xref evidence |
| --- | --- | --- | --- | --- |
| `ClanItemDialog` | `0x00615fdc` | `0x00616040` | `0x00616070` | stores at `0x0048a0d8`, `0x0048a0e0`, `0x0048a0ea`; reset helper stores at `0x0048a100`, `0x0048a106`, `0x0048a110` |
| `ClanDepItemDialog` | `0x0061607c` | `0x006160e0` | `0x00616110` | stores at `0x0048a21a`, `0x0048a220`, `0x0048a22a` |
| `ClanWidItemDialog` | `0x0061611c` | `0x00616180` | `0x006161b0` | stores at `0x0048a86a`, `0x0048a870`, `0x0048a87a` |
| `ClanItemListPane` | `0x006161bc` | `0x00616244` | `0x00616274` | stores at `0x0048aedb`, `0x0048aee1`, `0x0048aeeb` |
| `ClanBankPane` | `0x00616280` | `0x006162e0` | `0x00616310` | stores at `0x0048b239`, `0x0048b600`, `0x0048c416` and companion subobject stores |
| `ClanBankItemListPane` | `0x0061631c` | `0x006163a4` | `0x006163d4` | stores at `0x0048b92b`, `0x0048b931`, `0x0048b93b` |

## Layout Notes

- IDA exposes three vtable views per class. The offsets align with the common dialog/pane inheritance pattern used elsewhere: primary object view plus secondary/tertiary views around the `+0xa0` and `+0xa4` subobjects.
- [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md) and [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md) split the exact `.rdata` vtable subranges from the broad clan read-only-data aggregate.
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md) records the current recovered storage offsets: inherited control host at `+0x1fc`, `ClanAttrInputDialog` submitted strings at `+0x26c/+0x46c/+0x66c`, and submitted 16-bit value at `+0x86c`.
- Many derived constructor starts in current generated output are projected records, not IDA function starts. Use vtable stores/xrefs and confirmed submitter functions as class identity evidence until constructor boundaries are cleaned up.
- 2026-05-27 IDA MCP recheck found no inbound xrefs or raw dword pointer hits to the projected derived constructor starts, but did confirm constructor-shaped bytes that call the base dialog constructors and store the listed vtable bases. [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) documents the first focused raw constructor body. This supports class identity while keeping live constructor reachability unresolved.
- 2026-05-27 follow-up documented [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md) for the first bank/item-dialog raw constructor body. It has the same no-IDA-function caveat as the projected Clan modal dialog constructors, but its vtable stores match the `ClanItemDialog` reset helper at [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md).
- `ClanLeaveConfirmDialog` shares `AlertPane` destructor paths and adjustor thunks. The source should model this through ordinary C++ inheritance, not by reconstructing compiler-generated thunk functions as handwritten Clan code.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for the checked Clan modal and clan-bank dialog classes even though IDA exposes complete vtable and RTTI records for each class listed above. This is tracked in [wave3 data issues](../../wave3_data_issues.md).

## Reconstruction Notes

- These tables support grouping the name, money, attribute, enlist/change, and leave-confirm dialog classes together under [UID:0000I8][Clan](by-file/Clan.md) or a focused [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) split.
- The bank and item-dialog classes should remain with [UID:0000I9][ClanBank](by-file/ClanBank.md) unless later source-layout evidence proves the original source kept the entire Clan feature in one large file.
- The thunk strip at `0x0048c260-0x0048c341` is layout evidence for these classes and `ClanStatusPane`, but those tiny adjustor stubs should be ignored for source reconstruction in favor of normal destructors/inheritance.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md)
- [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md)
- [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md)
- [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)

## Changes

- 2026-05-27: Added `ClanItemDialog` vtables to this family after the `0x0048a0c0-0x0048a0fb` raw constructor pass. Evidence: IDA MCP reports `ClanItemDialog` vtable stores at `0x0048a0d8`, `0x0048a0e0`, `0x0048a0ea`, and matching reset-helper stores at `0x0048a100`, `0x0048a106`, `0x0048a110`.
- 2026-05-31: Expanded the bank/item vtable inventory from `ClanItemDialog` only to the full IDA-verified contiguous clan-bank block through `ClanBankItemListPane`, and linked exact child by-memory vtable ranges. Evidence: IDA MCP `py_eval` reports named vtable bases and xrefs from `0x00615fdc` through `0x006163d4`, followed by resource-string data at `0x006163dc`.
