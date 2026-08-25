*** UID:0001X9 | DO NOT MODIFY OR REMOVE!!! ***
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

# Clan Dialog Vtable Family

## Status

- Disposition: non-emitting mixed-owner vtable-family index for NexusTK Clan modal-dialog and clan-bank dialog/pane code.
- Autogen parent: intentionally blank. The page itself clears `88/92`, but it is now `RECONSTRUCTABLE:FALSE` because the source-local vtable pages route separately: [UID:0003HE][ClanModalDialogVtables](by-type/by-vtable/ClanModalDialogVtables.md) to [UID:0000I8][Clan](by-file/Clan.md), and [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md) to [UID:0000I9][ClanBank](by-file/ClanBank.md). Assigning this aggregate to either file would bypass the direct-owner rule and misplace the other half.
- Modal source owner: [UID:0000I8][Clan](by-file/Clan.md). [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) is a non-standalone, non-emitting family/index and historical split record, not another source-owner candidate.
- Bank/source-owner candidate: [UID:0000I9][ClanBank](by-file/ClanBank.md).
- Confidence: very strong for table bases, RTTI presence, vtable store/xref evidence, the two exact child vtable-data ranges, and the modal-versus-bank source-local split; medium-high for final unresolved virtual-slot lexical names and exact historical object-file boundaries.
- Verification: IDA MCP `list_globals` and vtable xref checks on 2026-05-26, IDA MCP `py_eval` vtable/xref recheck on 2026-05-31, exact child-page refreshes on 2026-06-07, A002 live IDA MCP `py_eval` boundary/xref spot-checks on 2026-06-11, and A004 live IDA MCP entity/byte/xref checks on 2026-06-12 for the full `0x006158f4-0x006163dc` modal and clan-bank vtable block.

## Assignment Decision

This page remains unassigned because it is a review aggregate, not a single direct source declaration owner. The exact type-level ownership has now been split into:

- [UID:0003HE][ClanModalDialogVtables](by-type/by-vtable/ClanModalDialogVtables.md), covering the modal-dialog group from `ClanNameInputDialog` through `ClanLeaveConfirmDialog` and assigned to [UID:0000I8][Clan](by-file/Clan.md).
- [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md), covering the clan-bank/item-dialog group from `ClanItemDialog` through `ClanBankItemListPane` and assigned to [UID:0000I9][ClanBank](by-file/ClanBank.md).

The exact binary data remains split in [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md) and [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md). The modal half points toward the clan modal-dialog source area, while the bank half points toward `ClanBank`. Keeping this aggregate's `AUTOGEN_PARENT_UID` blank is still correct because exact children now carry the narrower assignments.

## Source-Local Split Pages

| Source-local page | Exact data page | Direct parent | Parent gate |
| --- | --- | --- | --- |
| [UID:0003HE][ClanModalDialogVtables](by-type/by-vtable/ClanModalDialogVtables.md) | [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md) | [UID:0000I8][Clan](by-file/Clan.md) | Child `87/92`, direct parent `90/85`; route clears. |
| [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md) | [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md) | [UID:0000I9][ClanBank](by-file/ClanBank.md) | Child `87/92`, direct parent `86/85`; route clears. |

## Score Rationale

- Completion is `88` because this page now records the mixed-owner assignment decision, links the two exact source-local by-vtable children, links the two exact child vtable-data ranges, preserves the per-class vtable inventory, and documents why the aggregate itself must not be assigned.
- Confidence is `92` because the exact by-vtable children are now `87/92`, both direct file parents clear the strict gate, and the 2026-06-12 live IDA MCP recheck reconfirmed the modal/bank range sizes, boundary bytes, 51 decorated vtable labels, and representative store xrefs. Modal source placement is resolved to `Clan.cpp` and bank placement to `ClanBank.cpp`; confidence remains below final-source quality because many virtual-slot names and exact historical object-file boundaries are inferred.
- `RECONSTRUCTABLE` is now `FALSE` for this aggregate. The source-declared vtable requirements are reconstructable on [UID:0003HE][ClanModalDialogVtables](by-type/by-vtable/ClanModalDialogVtables.md) and [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md); this page is only the broad index over two direct source owners.

## Name And Money Dialog Tables

These classes are `ClanNameInputDialog` shells or derived one-action variants. The three vtable bases follow the same primary/secondary/tertiary pane shape seen in other dialog families.

| Class | Primary vtable | Secondary vtable | Tertiary vtable | Store / xref evidence |
| --- | --- | --- | --- | --- |
| `ClanNameInputDialog` | `0x006158f8` | `0x0061595c` | `0x0061598c` | stores at `0x00488b9e`, `0x00488ba4`, `0x00488bae` |
| `ClanDepMoneyInputDialog` | `0x00615998` | `0x006159fc` | `0x00615a2c` | xrefs at `0x00485120`, `0x00487de4`, `0x00488fb2` and companions |
| `ClanWidMoneyInputDialog` | `0x00615a38` | `0x00615a9c` | `0x00615acc` | B010 current xrefs at `0x00485398`/`0x0048539e`/`0x004853a8`, `0x004884d4`/`0x004884da`/`0x004884e4`, and raw stores `0x00489082`/`0x0048908a`/`0x00489094` |
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

### DLGCLAN2 Dispatch Contract

An exhaustive 24-entry comparison of the `ClanAttrInputDialog` primary table at `0x00615d58`, the `ClanEnlistInputDialog` primary table at `0x00615df8`, and the `ClanChangeInputDialog` primary table at `0x00615e98` shows that all entries are identical through offset `+0x58`. Their inherited `+0x48` cells `0x00615da0`, `0x00615e40`, and `0x00615ee0` all contain UID0004HI address `0x00489df0`, proving the shared source declaration `OnControlCommand(int controlIndex, int notifyCode)` rather than historical descriptive `OnDialogAction`.

Only primary offset `+0x5c` differs. Base cell `0x00615db4` points to `__purecall`; Enlist cell `0x00615e54` points to UID0002O3 `0x00489fc0`; Change cell `0x00615ef4` points to UID0002O5 `0x0048a030`. The source-facing contract is therefore inferred pure virtual `int OnSubmit()`, overridden by both derived classes. `OnSubmitEnlistment` and method-level `SubmitClanChange` are superseded descriptive aliases; `SubmitClanChangeHelper` remains the separate unchanged packet helper. These vtable entries are compiler-generated binary support, not handwritten table definitions or standalone method-body emitters.

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
- [UID:0003HE][ClanModalDialogVtables](by-type/by-vtable/ClanModalDialogVtables.md) and [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md) split the source-local type-level ownership. [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md) and [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md) split the exact `.rdata` vtable subranges from the broad clan read-only-data aggregate.
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md) records the current recovered storage offsets: inherited control host at `+0x1fc`, `ClanAttrInputDialog` submitted strings at `+0x26c/+0x46c/+0x66c`, and submitted 16-bit value at `+0x86c`.
- Many derived constructor starts in current generated output are projected records, not IDA function starts. Use vtable stores/xrefs and confirmed submitter functions as class identity evidence until constructor boundaries are cleaned up.
- 2026-05-27 IDA MCP recheck found no inbound xrefs or raw dword pointer hits to the projected derived constructor starts, but did confirm constructor-shaped bytes that call the base dialog constructors and store the listed vtable bases. [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) documents the first focused raw constructor body. This supports class identity while keeping live constructor reachability unresolved.
- 2026-05-27 follow-up documented [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md) for the first bank/item-dialog raw constructor body. It has the same no-IDA-function caveat as the projected Clan modal dialog constructors, but its vtable stores match the `ClanItemDialog` reset helper at [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md).
- `ClanLeaveConfirmDialog` shares `AlertPane` destructor paths and adjustor thunks. The source should model this through ordinary C++ inheritance, not by reconstructing compiler-generated thunk functions as handwritten Clan code.

## 2026-06-11 IDA Recheck

- IDB identity: `NexusTK.exe`, base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- The modal-dialog child range `0x006158f4-0x00615fd8` is `0x6e4` bytes. Live bytes rechecked as `68 4c 64 00 50 c3 48 00` at the start, `20 c3 48 00 90 4e 54 00` at the end, and `64 52 64 00 70 c4 48 00` at `0x00615fd8`, matching the handoff to `ClanItemDialog`.
- The clan-bank child range `0x00615fd8-0x006163dc` is `0x404` bytes. Live bytes rechecked as `64 52 64 00 70 c4 48 00` at the start, `b2 c2 48 00 90 4e 54 00` at the end, and `43 00 4c 00 41 00 4e 00` at `0x006163dc`, confirming the next owner begins with UTF-16 `CLAN1.EPF` resource text rather than another vtable.
- IDA names reconfirm the primary vtable labels from `??_7ClanNameInputDialog@@6B@` at `0x006158f8` through `??_7ClanLeaveConfirmDialog@@6B@` at `0x00615f38`, then from `??_7ClanItemDialog@@6B@` at `0x00615fdc` through `??_7ClanBankItemListPane@@6B@` at `0x0061631c`.
- Representative xrefs still match constructor/reset stores: `ClanNameInputDialog` primary at `0x006158f8` is stored from `0x00488b9e`; `ClanAttrInputDialog` primary at `0x00615d58` from `0x00489660`; `ClanItemDialog` primary at `0x00615fdc` from `0x0048a0d8`, `0x0048a100`, `0x0048a690`, `0x0048acf0`, and `0x0048c476`; `ClanBankPane` primary at `0x00616280` from `0x0048b239`, `0x0048b600`, and `0x0048c416`; and `ClanBankItemListPane` primary at `0x0061631c` from `0x0048b92b`.

## 2026-06-12 A004 IDA Recheck

- IDB session: `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- `entity_query` over `0x006158f4-0x006163dc` returned 51 decorated vtable names: 33 names in the modal-dialog half through `ClanLeaveConfirmDialog`, and 18 names in the bank/item-dialog half through `ClanBankItemListPane`.
- `int_convert.py` verified the modal span `0x6e4` / 1764 bytes, bank span `0x404` / 1028 bytes, combined span `0xae8` / 2792 bytes, and common subobject offsets `0xa0` / 160 bytes and `0xa4` / 164 bytes.
- `get_bytes` reconfirmed the modal start bytes `68 4c 64 00 50 c3 48 00`, modal end bytes `20 c3 48 00 90 4e 54 00`, bank start bytes `64 52 64 00 70 c4 48 00`, bank end bytes `b2 c2 48 00 90 4e 54 00`, and UTF-16 `CLAN1.EPF` successor bytes at `0x006163dc`.
- `trace_data_flow` reconfirmed representative store refs: `ClanNameInputDialog` primary from `0x00488b9e`, `ClanAttrInputDialog` primary from `0x00489660`, `ClanItemDialog` primary from `0x0048a0d8`/`0x0048a100`/`0x0048a690`/`0x0048acf0`/`0x0048c476`, `ClanBankPane` primary from `0x0048b239`/`0x0048b600`/`0x0048c416`, and `ClanBankItemListPane` primary from `0x0048b92b`.

## Wave3 Data Issue

Generated class metadata has previously reported `vtable_count: 0` for the checked Clan modal and clan-bank dialog classes even though IDA exposes complete vtable and RTTI records for each class listed above. This page does not rely on that generated metadata for ownership or scoring; the mismatch is tracked in [wave3 data issues](../../wave3_data_issues.md).

## Reconstruction Notes

- These tables support grouping the name, money, attribute, enlist/change, and leave-confirm dialog classes together under [UID:0000I8][Clan](by-file/Clan.md). UID0000IA documents that family and the rejected focused-split hypothesis but owns no emitted source.
- The bank and item-dialog classes should remain with [UID:0000I9][ClanBank](by-file/ClanBank.md) unless later source-layout evidence proves the original source kept the entire Clan feature in one large file.
- The true thunk strip at `0x0048c27b-0x0048c341` is layout evidence for these classes and `ClanStatusPane`, but those tiny adjustor stubs should be ignored for source reconstruction in favor of normal destructors/inheritance. The preceding `0x0048c260-0x0048c26b` and `0x0048c270-0x0048c27b` bodies are singleton-clear cleanup helpers for `g_pClanBankPane` and `g_pClanStatusPane`, not thunks.
- Do not set an aggregate parent on this page merely because a candidate file now clears `85/85`. The page crosses the modal/bank source split; exact child pages or final source-layout evidence must carry any narrower assignment later.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:0003HE][ClanModalDialogVtables](by-type/by-vtable/ClanModalDialogVtables.md)
- [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00024Z][0x00615570-0x006164f0.ClanReadOnlyData](by-memory/0x00615570-0x006164f0.ClanReadOnlyData.md)
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

- 2026-07-13 B004 UID0004HI contract implementation: added the exact DLGCLAN2 24-entry primary-table result, common `+0x48` `OnControlCommand` cells, base `+0x5c` `__purecall`, and Enlist/Change `OnSubmit` cells. Preserved `88/92`, aggregate non-emitting/mixed-owner status, compiler-generated vtable disposition, every modal/bank table, source-local child split, and unrelated evidence.

- 2026-07-05 B010 UID0002NT support sync:
  - Synchronized `ClanWidMoneyInputDialog` vtable evidence with MCP session `supervisor_recovery_20260705`: primary `0x00615a38`, secondary `0x00615a9c`, and tertiary `0x00615acc` xrefs remain the two active inline construction triads plus raw constructor stores in [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md).
  - No aggregate ownership/emitter change: [UID:0000I8][Clan](by-file/Clan.md) remains the active modal source route and this mixed vtable family remains non-emitting support.
- 2026-06-12 A004 Batch 308 source-local type split:
  - Before: `COMPLETION/CONFIDENCE` was `85/90`, `RECONSTRUCTABLE:TRUE`, and the aggregate had no by-vtable children, so generated type coverage still reported it as reconstructable but unassigned.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, parent blank, with source-local children [UID:0003HE][ClanModalDialogVtables](by-type/by-vtable/ClanModalDialogVtables.md) -> [UID:0000I8][Clan](by-file/Clan.md) and [UID:0003HF][ClanBankVtables](by-type/by-vtable/ClanBankVtables.md) -> [UID:0000I9][ClanBank](by-file/ClanBank.md).
  - Evidence: live IDA MCP `entity_query`, `get_bytes`, `trace_data_flow`, and `int_convert.py` reconfirmed 51 decorated vtable names, the exact `0x6e4` modal and `0x404` bank spans, representative constructor/reset/destructor store refs, the `ClanItemDialog` handoff at `0x00615fd8`, and the UTF-16 `CLAN1.EPF` successor at `0x006163dc`. The aggregate remains parentless because no single direct parent owns both source-local vtable groups.
- 2026-06-11 A002 Batch 211 child-routing refresh:
  - Scores remain `85/90`, and this mixed aggregate remains parent-blank.
  - Summary/evidence: [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md) now routes to [UID:0000I8][Clan](by-file/Clan.md) and [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md) now routes to [UID:0000I9][ClanBank](by-file/ClanBank.md) after both child and direct parent pages clear `85/85`. The aggregate stays unassigned because it intentionally spans the modal and bank source-owner groups.
- 2026-06-11 A002 mixed-owner aggregate pass for assigned target `0001X9`.
  - Before: `COMPLETION/CONFIDENCE` was `78/88`, the page listed the vtable family but did not explicitly encode the corrected parent-gate decision after the exact modal and bank child pages were raised.
  - After: raised to `85/90` and kept `AUTOGEN_PARENT_UID` blank.
  - Summary/evidence: [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md) is `85/90`, [UID:0002MO][0x00615fd8-0x006163dc.ClanBankVtableData](by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md) is `86/90`, and live IDA MCP reconfirmed the modal/bank range sizes, boundary bytes, primary labels, and representative store xrefs. The aggregate remains unassigned because the modal side belongs to the Clan/ClanDialogs source area while the bank side belongs to ClanBank, so one direct parent would be a mixed-owner shortcut.
- 2026-05-27: Added `ClanItemDialog` vtables to this family after the `0x0048a0c0-0x0048a0fb` raw constructor pass. Evidence: IDA MCP reports `ClanItemDialog` vtable stores at `0x0048a0d8`, `0x0048a0e0`, `0x0048a0ea`, and matching reset-helper stores at `0x0048a100`, `0x0048a106`, `0x0048a110`.
- 2026-05-31: Expanded the bank/item vtable inventory from `ClanItemDialog` only to the full IDA-verified contiguous clan-bank block through `ClanBankItemListPane`, and linked exact child by-memory vtable ranges. Evidence: IDA MCP `py_eval` reports named vtable bases and xrefs from `0x00615fdc` through `0x006163d4`, followed by resource-string data at `0x006163dc`.
- 2026-06-22 B014 Rule 26 support sync: corrected the destructor-band wording from `0x0048c260-0x0048c341` as a thunk strip to `0x0048c27b-0x0048c341`, with `0x0048c260` and `0x0048c270` recorded as singleton-clear cleanup helpers. Score and reconstructability are unchanged.
