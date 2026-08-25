*** UID:0001XH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001XH] no standalone employee-dialog vtable-family body.
// Vtable clusters are compiler-emitted ABI data; exact vtable-data children and class/method declarations own generated output.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EmployeeDialogPane Vtables

## Status

- Confidence: strong for vtable addresses and class-specific slots, medium for inherited slot names.
- Likely owner source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Owner/emitter status: `CANONICAL_OWNER:0000J0` and `EMITTER_UIDS:0000J0` attach this support page to the file-level [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) route because the vtable family spans four employee-dialog classes. Final C++ remains blank because this is compiler-emitted vtable-family support data, while exact class/method children may emit through their direct class owners.
- Memory evidence: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md), [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md), [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md), [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- Layout docs: [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md), [UID:0001TN][AddEmployeeItemDialogLayout](by-type/by-struct/AddEmployeeItemDialogLayout.md), [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md)
- EmployeeDialogPane destructor policy: source declares one public virtual destructor and UID0003KR supplies its sole body; UID0003L4, its two adjustor routes, and all three vtable slot encodings are compiler-generated ABI output.

## EmployeeDialogPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x00618f00` | `+0x00 -> 0x004a4d40`, direct UID0003L4 scalar deleting destructor route; exact wrapper SHA-256 `C1A6A5C685C3FE1DB9CF7EDDFBC2AFC8659D414B824922AF69B1EE8BC0E3324A`. |
| secondary | `0x00618f60` | `+0x00 -> 0x004a4cc7`, exact 11-byte `this-0xa0` thunk (SHA-256 `52E4503AD86D82E6EBF45101A83A4D81EA3E03D13739738AABF0240927158001`) into UID0003L4; `+0x04 -> 0x004a2a60` mouse/tooltip handler; `+0x10 -> 0x004a2f60` employee packet dispatcher. |
| tertiary | `0x00618f90` | `+0x00 -> 0x004a4cd2`, exact 11-byte `this-0xa4` thunk (SHA-256 `2464C693B14A05180DD5D45C4DBFC35CE1919DEAA0EE3EE2290B2C314581C76A`) into UID0003L4; `+0x04 -> 0x004a2c80` employee command sender. B002 2026-06-28 resolves `+0x04` as [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md), now owner/emitter [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md) with first-draft C++. |

Exact data range: [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md). That exact child is direct class-owned source-declared/generated-binary vtable/RTTI storage with a formal comment-only no-raw-vtable marker. UID0003KR is the source destructor carrier; UID0003L4 and both adjustor thunks remain compiler-only. [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) remains the source method carrier for the tertiary command slot.

## EmployeeItemPropertyDialogPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x00618f9c` | `+0x00 -> 0x004a4e30` scalar deleting destructor; `+0x44 -> 0x004a4570` paint handler; `+0x48 -> 0x004a4660` command/action handler. B004 2026-06-26 resolves `+0x44` as [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md), now owner/emitter [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) with first-draft C++. B001 2026-06-23 resolves `+0x48` as [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md), now owner/emitter [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) with first-draft C++. |
| secondary | `0x00618ffc` | `+0x00 -> 0x004a4cdd` this-adjustor thunk. |
| tertiary | `0x0061902c` | `+0x00 -> 0x004a4ce8` this-adjustor thunk; `+0x04 -> 0x00544e90` shared inherited/default slot with broad non-property-specific fan-in. |

Exact data range: [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md). B002 2026-06-29 resolves that exact child as direct class-owned source-declared/generated-binary vtable/RTTI storage with a formal comment-only no-raw-vtable marker; [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md), [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md), [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md), and [UID:0003L5][0x004a4e30-0x004a4e6b.EmployeeItemPropertyDialogPaneScalarDeletingDestructor](by-memory/0x004a4e30-0x004a4e6b.EmployeeItemPropertyDialogPaneScalarDeletingDestructor.md) remain the source method/destructor-wrapper carriers.

## EmployeeQuantityInputDialogPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x00619038` | `+0x00 -> 0x0047eaf0` shared dialog/alert scalar deleting destructor; `+0x48 -> 0x004a4a30` quantity confirm/cancel action handler. |
| secondary | `0x00619098` | `+0x00 -> 0x0047e8d9` this-adjustor thunk into `0x0047eaf0`. |
| tertiary | `0x006190c8` | `+0x00 -> 0x0047e8e4` this-adjustor thunk into `0x0047eaf0`; `+0x04 -> 0x00544e90` base/default event-update slot. |

Exact data range: [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md). B004 2026-06-29 resolves that exact child as direct class-owned source-declared/generated-binary vtable/RTTI storage with a formal comment-only no-raw-vtable marker; [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md) and [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) remain the source constructor/action carriers.

The quantity dialog uses the older shared [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md), not the employee-specific `0x004a4cb1-0x004a4cf3` thunk island. Keep this distinction when reconstructing destructors.

## AddEmployeeItemDialog

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x006190d4` | `+0x00 -> 0x004a4d00` scalar deleting destructor; `+0x48 -> 0x004a4b20` employee item action handler; `+0x4c -> 0x004aea40` inherited item-dialog action slot. |
| secondary | `0x00619134` | `+0x00 -> 0x004a4cb1` this-adjustor thunk. |
| tertiary | `0x00619164` | `+0x00 -> 0x004a4cbc` this-adjustor thunk. |

Do not read primary `+0x5c` or secondary `+0x2c` as normal virtual slots. They are RTTI metadata for the next table. The secondary table happens to begin at absolute address `0x00619134`, which is primary base `+0x60`.

Exact data range: [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md). B006 2026-06-28 resolves that exact child as direct class-owned source-declared/generated-binary vtable/RTTI storage with a formal comment-only no-raw-vtable marker; [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md) remains the source method/destructor carrier.

## Evidence

- 2026-05-26 IDA MCP `py_eval` read the listed vtable dwords directly from the IDB.
- 2026-05-31 IDA MCP `list_globals`, `lookup_funcs`, and dword scan confirmed exact `.rdata` child ranges: `0x00618efc-0x00618f98`, `0x00618f98-0x00619034`, `0x00619034-0x006190d0`, and `0x006190d0-0x0061916c`.
- `xrefs_to` ties `EmployeeDialogPane` vtables to constructor/destructor writes at `0x004a1d70`, `0x004a22f0`, and `0x004a4d40`.
- `xrefs_to` ties `EmployeeItemPropertyDialogPane` vtables to constructor writes at `0x004a41c0`.
- `xrefs_to` ties `EmployeeItemPropertyDialogPane::OnPaint` to primary slot `0x00618fe0` and `OnCommand` to primary slot `0x00618fe4`.
- B004 2026-06-26 current MCP session `80de0a67` reconfirmed `0x00618fe0 -> 0x004a4570`, `xrefs_to 0x004a4570` as a single data xref from this slot, and no direct refs to the slot address itself, supporting vtable-dispatch ownership rather than standalone data ownership for [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md).
- B001 2026-06-23 current MCP session `80de0a67` reconfirmed `0x00618fe4 -> 0x004a4660` and no direct refs to the slot address itself, supporting vtable-dispatch ownership rather than standalone data ownership for [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md).
- B002 2026-06-28 current MCP session `agent_b009_0002my_20260628` reconfirmed `0x00618f94` bytes as `0x80 0x2c 0x4a 0x0`, the slot target as `0x004a2c80`, and `lookup_funcs 0x004a2c80` as `sub_4A2C80`, size `0x2dd`. The slot target now emits first-draft `EmployeeDialogPane::SendCommand` C++ on [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md); this support page remains blank compiler-generated vtable-family evidence.
- B001 2026-06-29 current MCP session `967f0703` reconfirmed [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md) as non-function `.rdata` with exact dwords/bytes including `0x00618efc -> 0x006468bc`, `0x00618f00 -> 0x004a4d40`, `0x00618f5c -> 0x0064691c`, `0x00618f8c -> 0x00646930`, and `0x00618f94 -> 0x004a2c80`; `lookup_funcs 0x004a2c80` returned `sub_4A2C80` size `0x2dd`; and the next-class boundary remains `0x00618f98`. This supports the exact child marker disposition while keeping this family support page blank.
- Fresh UID0003L4 evidence resolves the EmployeeDialogPane destructor family without changing any sibling-class tables: the primary slot routes directly to the deleting wrapper; the secondary and tertiary slots route through exact `this-0xa0` and `this-0xa4` adjustors; all converge on wrapper `0x004a4d40`. UID0003KR's independent ordinary body has SHA-256 `E7DD91C89E251B96E3E7025A5B439444C779FDC590C76AF8E2B2ACBDCC528836`, while two constructor call sites allocate the complete class at `0x850` bytes through the final record pointer at `+0x84c`.
- B002 2026-06-29 current MCP session/database `967f0703` reconfirmed [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md) as non-function `.rdata` with property vtable globals at `0x00618f9c`, `0x00618ffc`, and `0x0061902c`, COL globals at `0x00646944`, `0x006469a4`, and `0x006469b8`, key dwords `0x00618f98 -> 0x00646944`, `0x00618f9c -> 0x004a4e30`, `0x00618fe0 -> 0x004a4570`, `0x00618fe4 -> 0x004a4660`, `0x00618ff8 -> 0x006469a4`, `0x00618ffc -> 0x004a4cdd`, `0x00619028 -> 0x006469b8`, `0x0061902c -> 0x004a4ce8`, `0x00619030 -> 0x00544e90`, and `0x00619034 -> 0x006469cc`; constructor stores at `0x004a4230`/`0x004a4236`/`0x004a4240`; zero direct xrefs to `0x00618f98`, `0x00618fe0`, `0x00618fe4`, and `0x00619034`; two `0xb`-byte adjustor thunks into `0x004a4e30`; and 312 inbound refs to shared/default slot `0x00544e90`. This supports the exact child marker disposition while keeping this family support page blank.
- `xrefs_to` ties `EmployeeQuantityInputDialogPane` vtables to constructor writes at `0x004a47cc`, `0x004a47d2`, and `0x004a47dc`; `OnAction` is vtable-referenced at `0x00619080`.
- B004 2026-06-29 current MCP session `967f0703` reconfirmed [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md) as non-function `.rdata` with quantity vtable bases at `0x00619038`, `0x00619098`, and `0x006190c8`, COL/RTTI dwords at `0x00619034`, `0x00619094`, and `0x006190c4`, key slots `0x00619038 -> 0x0047eaf0`, `0x00619080 -> 0x004a4a30`, `0x00619098 -> 0x0047e8d9`, `0x006190c8 -> 0x0047e8e4`, and `0x006190cc -> 0x00544e90`, constructor-store xrefs at `0x004a47cc`/`0x004a47d2`/`0x004a47dc`, action-slot data-only xref at `0x00619080`, no direct `OnAction` callers, and successor `0x006190d0 -> 0x00646a54`. This supports the exact child marker disposition while keeping this family support page blank.
- `xrefs_to` ties `AddEmployeeItemDialog` vtables to inline writes in `EmployeeDialogPane::OnButtonAction` at `0x004a3240` and to raw constructor-shaped bytes at `0x004a4ae0`.
- The live inline write sequence is documented as [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md): `0x004a33a4`, `0x004a33aa`, and `0x004a33b4` store the primary/secondary/tertiary vtable bases after the generic `AddItemDialog` constructor call.
- `xrefs_to` confirms `AddEmployeeItemDialog::OnButtonClick` at `0x004a4b20` is vtable-referenced at `0x0061911c` and has no direct code callers, matching virtual dispatch from the item picker.
- B006 2026-06-28 current MCP session `supervisor_20260628_resume` reconfirmed the AddEmployee exact data child: primary/secondary/tertiary bases `0x006190d4`, `0x00619134`, and `0x00619164`; COL globals `0x00646a54`, `0x00646b04`, and `0x00646b18`; key dwords `0x006190d4 -> 0x004a4d00`, `0x0061911c -> 0x004a4b20`, `0x00619120 -> 0x004aea40`, `0x00619134 -> 0x004a4cb1`, and `0x00619164 -> 0x004a4cbc`; live inline stores at `0x004a33a4`/`0x004a33aa`/`0x004a33b4`; raw no-function stores at `0x004a4afe`/`0x004a4b04`/`0x004a4b0e`; `lookup_funcs 0x004a4ae0` as `Not a function`; zero xrefs to raw `0x004a4ae0`; and successor `Employee` string boundary at `0x0061916c`.
- Current `class_AddEmployeeItemDialog.meta_wave3` reports `vtable_count: 0`, so generated vtable inventory is incomplete despite these IDA-confirmed vtable bases.

## Reconstruction Notes

The adjustor thunk slots are compiler-generated and are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). Reconstruct normal class inheritance and destructors in `EmployeeDialogPane.cpp`; do not emit these thunks as handwritten methods. For EmployeeDialogPane, place exactly one source body on UID0003KR and no source body on UID0003L4 or either adjustor thunk. A public virtual destructor declaration is the source-level cause of the compiler-emitted wrapper, vtable entries, and adjustors.

[UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md) follows the exact raw vtable/RTTI storage policy: keep the class-owned formal no-code marker and regenerate the bytes from `EmployeeDialogPane` declarations plus linked method children such as [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md), rather than adding handwritten vtable arrays.

[UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md) follows the same exact raw vtable/RTTI storage policy for `EmployeeItemPropertyDialogPane`: keep the class-owned formal no-code marker and regenerate the bytes from `EmployeeItemPropertyDialogPane` declarations plus [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md), [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md), [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md), and [UID:0003L5][0x004a4e30-0x004a4e6b.EmployeeItemPropertyDialogPaneScalarDeletingDestructor](by-memory/0x004a4e30-0x004a4e6b.EmployeeItemPropertyDialogPaneScalarDeletingDestructor.md), rather than adding handwritten vtable arrays or adjustor-thunk bodies.

[UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md) follows the same exact raw vtable/RTTI storage policy for `EmployeeQuantityInputDialogPane`: keep the class-owned formal no-code marker and regenerate the bytes from `EmployeeQuantityInputDialogPane` declarations plus [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md), [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md), and shared dialog destructor/adjustor declarations, rather than adding handwritten vtable arrays or thunk bodies.

[UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md) follows the same policy for exact raw vtable/RTTI storage: keep the class-owned formal no-code marker and regenerate the bytes from `AddEmployeeItemDialog` declarations plus [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md), rather than adding handwritten vtable arrays.

## Parent Rationale

Attach this vtable family support page to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), not to a single class. The page covers `EmployeeDialogPane`, `EmployeeItemPropertyDialogPane`, `EmployeeQuantityInputDialogPane`, and `AddEmployeeItemDialog`; the file page explicitly groups those four classes as one employee-shop source module and clears the current `85/85` owner/emitter gate. Exact vtable-data child pages still use their narrow direct class owners when those parents clear the gate, so this page remains a family-level support/index page rather than the direct owner for every child. File-scope support ownership also preserves the documented split from generic [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) while avoiding a misleading single-class parent for the whole family.

## Score Rationale

- Completion `92`: all four class table families retain exact child links and generated-binary policy, and the EmployeeDialogPane primary/secondary/tertiary destructor routes now have exact target/thunk identities plus an unambiguous source declaration/body disposition. It remains below final-audit completion because inherited slot names across the four-class family are not exhaustive.
- Confidence `95`: direct table dwords, function/thunk bounds, exact hashes, constructor/destructor table stores, two complete-object allocations, and source-visible ordinary destructor behavior mutually support the EmployeeDialogPane destructor policy. The score does not overclaim original declaration spelling beyond a public virtual destructor.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md)
- [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)
- [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md)
- [UID:0001UB][EmployeeItemPropertyDialogPaneLayout](by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md)
- [UID:0001TN][AddEmployeeItemDialogLayout](by-type/by-struct/AddEmployeeItemDialogLayout.md)
- [UID:0001UC][EmployeeQuantityInputDialogPaneLayout](by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md)
- [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md)
- [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md)
- [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-08-24 B002 accepted EmployeeDialogPane destructor implementation callback: raised the family page from `88/88` to `92/95`; recorded the exact direct and two adjusted UID0003L4 routes, target/thunk hashes, UID0003KR-only source placement, `0x850` complete size, public-virtual declaration policy, and unchanged compiler-generated vtable treatment. Property, quantity, and add-item table contracts remain unchanged.

- 2026-06-29 B004 EmployeeQuantityInputDialogPane vtable-data marker sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: synchronized the `EmployeeQuantityInputDialogPane` section, evidence, and reconstruction notes with [UID:0002MG][0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData](by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md)'s accepted formal no-raw-vtable marker disposition. Current MCP session `967f0703` reconfirmed exact quantity vtable/COL dwords, constructor-store xrefs, data-only action slot ref, no direct `OnAction` callers, shared destructor and adjustor thunk shape, inherited/default slot, and the `0x006190d0` successor boundary.

- 2026-06-29 B002 EmployeeItemPropertyDialogPane vtable-data marker sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: synchronized the `EmployeeItemPropertyDialogPane` section, evidence, and reconstruction notes with [UID:0002MF][0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData](by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md)'s accepted formal no-raw-vtable marker disposition. Current MCP session `967f0703` reconfirmed exact property vtable/COL dwords, constructor-store xrefs, data-only paint/command slot refs, zero direct slot-address refs, adjustor thunk shape, scalar deleting destructor wrapper caveat, shared/default slot fan-in, and the `0x00619034` successor boundary.

- 2026-06-29 B001 EmployeeDialogPane vtable-data marker sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: synchronized the `EmployeeDialogPane` section, evidence, and reconstruction notes with [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md)'s accepted formal no-raw-vtable marker disposition. Current MCP session `967f0703` reconfirmed exact dwords/bytes, non-function `.rdata` addresses, UID0003KW slot target size `0x2dd`, vtable-base stores, and the `0x00618f98` successor boundary.
  - Exclusion: the existing [Wave3 data issues](../../wave3_data_issues.md) cross-reference remains unchanged because it is a historical support link, not active stale recovered-source/simroot wording in this page.
- 2026-06-28 B002 SendCommand slot sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: updated the EmployeeDialogPane tertiary slot note to record that `0x00618f94 -> 0x004a2c80` now maps to [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md), owner/emitter [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md), with first-draft C++. B002 current MCP session `agent_b009_0002my_20260628` reconfirmed the slot bytes, target size `0x2dd`, padding boundaries, and vtable-only dispatch shape.
- 2026-06-28 B006 AddEmployee vtable-data marker sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: synchronized the `AddEmployeeItemDialog` section and reconstruction notes with [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md)'s accepted formal no-raw-vtable marker disposition. Current MCP session `supervisor_20260628_resume` reconfirmed exact AddEmployee vtable/COL addresses, key action/destructor slots, inline and raw store xrefs, zero raw-start reachability, and the `0x0061916c` successor boundary.
- 2026-06-26 B004 property-paint slot sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: updated the `EmployeeItemPropertyDialogPane` primary slot `+0x44` note to record that [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md) now emits through [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) with first-draft C++. B004 current MCP session `80de0a67` reconfirmed the slot dword `0x00618fe0 -> 0x004a4570` and vtable-only xref shape.

- 2026-06-23 B001 property-command slot sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: updated the `EmployeeItemPropertyDialogPane` primary slot `+0x48` note to record that [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md) now emits through [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) with first-draft C++. Also replaced stale broad final-gate wording with the current support-data disposition.
- 2026-06-07 parent attachment update:
  - What existed before: the page had strong four-class vtable evidence and exact by-memory children, but no autogen parent.
  - Changed to: `COMPLETION:88` with current `CANONICAL_OWNER:0000J0` and `EMITTER_UIDS:0000J0` routing, plus an explicit file-level parent rationale.
  - Summary/evidence: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) owns the employee-dialog family, links the same exact vtable children, and clears the attachment gate; final C++ remains blank because this is support data and inherited slot/source-split questions keep it below final-audit status.
- 2026-06-27 B007 terminology cleanup:
  - Before: status and parent-rationale prose still used legacy autogen/old-gate wording.
  - After: prose uses current `CANONICAL_OWNER` / `EMITTER_UIDS` terminology, states the current `85/85` gate, and clarifies that exact vtable-data children route through direct class owners when those class pages clear the gate.
  - Summary/evidence: B007's accepted UID `000256` implementation made no score or metadata change to this support page; it only synchronized stale ownership terminology and preserved the no-raw-vtable-C++ guidance.
- 2026-05-31 exact `.rdata` child split:
  - What existed before: metadata was unevaluated `0/0`, `RECONSTRUCTABLE` was blank, and the page listed vtable bases without exact by-memory child pages for the read-only data bytes.
  - Changed to: scored `86/88`, marked `RECONSTRUCTABLE:TRUE`, and linked four exact vtable-data child pages.
  - Summary/evidence: IDA MCP `list_globals`, `lookup_funcs`, and dword scan confirmed RTTI words, vtable bases, slot values, adjustor-thunk functions, and next-range boundaries for the employee dialog vtable family.
