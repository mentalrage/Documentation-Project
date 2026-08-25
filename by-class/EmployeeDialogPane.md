*** UID:00004C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:00004C] EmployeeDialogPane class route marker.
// Exact method, raw-island marker, vtable-data, and resource children carry EmployeeDialogPane.cpp output; broad class declaration C++ is deferred.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EmployeeDialogPane

## Status

- Confidence: strong for class role, source placement, exact child helper/vtable pages, IDA-confirmed method anchors, and current raw-helper no-route dispositions; medium-high for final full field names and class declaration shape.
- Likely source file: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Address range: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- Generated recovered-file lead (stale/source-check only): `source-3/simroot_v2/class_EmployeeDialogPane.cpp`; current by-* docs and MCP-backed evidence are the authority.
- Type docs: [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md), [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- Exact vtable data: [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md)
- Exact complete-object size: `0x850` / 2128 bytes. The final class field is `EmployeeRecord *m_employeeRecords` at `+0x84c`.
- Destructor source boundary: [UID:0003KR][0x004a22f0-0x004a23a8.EmployeeDialogPaneDestructor](by-memory/0x004a22f0-0x004a23a8.EmployeeDialogPaneDestructor.md) carries the sole ordinary destructor body; [UID:0003L4][0x004a4d40-0x004a4e27.EmployeeDialogPaneScalarDeletingDestructor](by-memory/0x004a4d40-0x004a4e27.EmployeeDialogPaneScalarDeletingDestructor.md) is false/non-emitting compiler support.

## Class Purpose

`EmployeeDialogPane` is the main employee shop/management dialog. It owns the employee record array, selected visible item slots, item tooltip/status drawing, employee command packets, and response packet handling for adding/removing/updating employee shop entries.

## Method Map

| Address | Method or helper | Role |
| --- | --- | --- |
| [UID:0003KQ][0x004a1d70-0x004a22ef.EmployeeDialogPaneConstructor](by-memory/0x004a1d70-0x004a22ef.EmployeeDialogPaneConstructor.md) | `EmployeeDialogPane` | Builds the `Employee` dialog, initializes visible slots, parses optional initial packet data, and sends the initial opcode `0x54` request. |
| [UID:0003KR][0x004a22f0-0x004a23a8.EmployeeDialogPaneDestructor](by-memory/0x004a22f0-0x004a23a8.EmployeeDialogPaneDestructor.md) | `~EmployeeDialogPane` ordinary destructor | Sole human destructor definition: frees nullable `m_employeeRecords`, sends exact seven-byte `{0x54,1,BE32(m_employeeDialogId),8}` close notification, and relies on automatic `DialogPane` teardown. |
| [UID:0003KT][0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper](by-memory/0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper.md) | inventory item helper | Opens quantity input for stack-like items or sends command `5` directly. |
| [UID:0003KU][0x004a2560-0x004a2a51.EmployeeDialogPaneOnPaint](by-memory/0x004a2560-0x004a2a51.EmployeeDialogPaneOnPaint.md) | `OnPaint` | Draws the seller background, employee name, gold/count/status text, item icons, and tooltip text. |
| [UID:0003KV][0x004a2a60-0x004a2c78.EmployeeDialogPaneOnMouseInput](by-memory/0x004a2a60-0x004a2c78.EmployeeDialogPaneOnMouseInput.md) | `OnMouseInput` | Hit-tests the 10 item icon rects and builds tooltip strings. |
| [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) | `SendCommand` | Sends opcode `0x54` employee subcommands for hire, quantity, transfer, remove, close, and fitting-room actions. B002 2026-06-28 now populates first-draft C++ on the exact child page through this class. |
| [UID:0003KX][0x004a2f60-0x004a322c.EmployeeDialogPanePacketDispatcher](by-memory/0x004a2f60-0x004a322c.EmployeeDialogPanePacketDispatcher.md) | packet dispatcher | Handles employee response packets. |
| [UID:0003KY][0x004a3240-0x004a33d8.EmployeeDialogPaneOnButtonAction](by-memory/0x004a3240-0x004a33d8.EmployeeDialogPaneOnButtonAction.md) | `OnButtonAction` | Opens quantity/property/add-item dialogs, fitting room, or closes the dialog. |
| [UID:0003KZ][0x004a33e0-0x004a34cb.EmployeeDialogPaneRebuildSelectionList](by-memory/0x004a33e0-0x004a34cb.EmployeeDialogPaneRebuildSelectionList.md) | `RebuildSelectionList` | Recomputes the 10 visible employee slots and scroll-button state. |
| [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) | `DeserializeEmployeeRecord` | File-local static/stdcall helper that parses one `EmployeeRecord`; used by class packet/load paths but not an `EmployeeDialogPane::` method. |
| [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md) | raw packet helpers | File-local raw island for record-field parsing and opcode `0x54` command writers. |
| [UID:0003L1][0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData](by-memory/0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData.md) | `LoadEmployeeData` | Parses the full employee list packet and allocates the record array. |
| [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md) | raw record mutation helpers | Updates/inserts/removes records; IDA currently does not define these bodies as functions. B006 2026-06-29 resolved the empty-emitter state with a formal no-body marker on the exact file-owned child, not class C++. |
| [UID:0003L3][0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields](by-memory/0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields.md) | `UpdateEmployeeFields` | Applies renamed/status/field updates to one existing record. |
| `0x004a4cc7-0x004a4cdc` | destructor adjustor thunks | Thin this-adjustor thunks into `0x004a4d40`. |
| [UID:0003L4][0x004a4d40-0x004a4e27.EmployeeDialogPaneScalarDeletingDestructor](by-memory/0x004a4d40-0x004a4e27.EmployeeDialogPaneScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-only false/non-emitting wrapper. It duplicates UID0003KR cleanup, then applies deleting flags, optional storage free, return-this ABI, and the guarded `0x850` path; no wrapper C++ or marker is emitted. |

## Evidence Notes

- Historical Wave3/generated lead notes identified a 2804-byte dialog. That size is superseded and retained only as stale history: two constructor allocation paths and the deleting-wrapper guard independently prove exact complete size `0x850` / 2128. The `0x41c` / 1052-byte `EmployeeRecord` stride and opcode `0x54` command family remain current.
- IDA MCP confirms all modeled method starts above. The adjacent raw starts in [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md) and [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md), including raw/projected `0x004a3be0`, still have no function objects; disassembly shows complete raw bodies, but B006/B005 current route checks resolve them as file-owned no-code helper evidence rather than class methods. UID0003L0 now carries a formal covered-by marker and UID0003L2 now carries a formal no-body marker instead of blank C++.
- Previously omitted helpers `0x004a2450` and `0x004a2f60` now have exact pages; both are employee-dialog-specific and remain below final C++ emission until final helper names are settled.
- `OnButtonAction` constructs [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md), [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md), and an `AddItemDialog` patched to [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) vtables.
- 2026-05-25 IDA MCP recheck confirms `0x004a3be0` is still not an IDA function but contains raw update-record code, and confirms `0x004a4ae0` is also raw constructor-shaped code with no IDA function object or xrefs.
- 2026-05-26 IDA MCP vtable pass confirms `EmployeeDialogPane` vtables at `0x00618f00`, `0x00618f60`, and `0x00618f90`; the secondary/tertiary destructor adjustor thunks at `0x004a4cc7` and `0x004a4cd2` are compiler-generated and now tracked as ignored memory.
- 2026-05-31 IDA MCP confirms the exact vtable data span at [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md), ending before `EmployeeItemPropertyDialogPane` RTTI at `0x00618f98`.
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) now records a strong `NexusTK/ui/dialogs/` source root for the full employee-shop module, including exact child pages for `DeserializeEmployeeRecord`, the employee item property dialog methods, quantity dialog methods, add-employee vtable data, employee read-only data, and employee resource notes.
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md) attaches the file-local helper family directly to `EmployeeDialogPane.cpp`; this supports class ownership for modeled helpers such as `0x004a2450` and `0x004a2f60` while documenting raw `0x004a3650-0x004a3a90` and `0x004a3be0-0x004a3e10` as file-owned no-code helper islands.
- [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md) records the runtime source-map anchor for the add-item branch inside `EmployeeDialogPane::OnButtonAction`, so the class page treats the unreferenced raw `0x004a4ae0` constructor-shaped bytes as retained no-code evidence rather than the primary construction path.
- 2026-06-07 A010 live IDA refresh reconfirmed `0x004a1d70` as a modeled constructor-sized function, with callers at `0x00508d53` and `0x005103d2`; `0x004a3240` remains the `OnButtonAction` island that opens quantity/property/add-item flows; `xrefs_to 0x004a34d0` still ties the exact parser to the packet/list/update paths at `0x004a2f60`, `0x004a3a90`, and raw `0x004a3c05`; and the three class vtable bases at `0x00618f00`, `0x00618f60`, and `0x00618f90` still have constructor/destructor store refs from `0x004a1dc1`/`0x004a231c`/`0x004a4d73` and adjacent offsets.
- 2026-06-12 A004 live IDA split recheck added exact children for the class constructor, non-deleting destructor, inventory helper, paint/mouse/send/dispatcher/action/rebuild/load/update methods, scalar deleting destructor, and adjacent raw helper islands. Raw islands [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md) and [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md) route to the file parent rather than this class because IDA still lacks function objects/direct xrefs for their starts.
- 2026-06-23 B001 source-quality sync for [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md) resolves the property-dialog command route into this class:
  - `EmployeeItemPropertyDialogPane::OnCommand` schedules through this dialog's TimerHandler view at owner `+0xa4`, not through a direct packet writer.
  - Parent primary offsets `+0x26c` and `+0x270` are accepted as `m_pendingPropertyPriceValue` and `m_pendingPropertyPriceState`. The target writes these before scheduling event/subcommand `2`; [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) reads them as TimerHandler-subobject offsets `this+456` and `this+460` and serializes them as command-2 dword payloads.
  - Event/subcommand `3`, reached from action id `0`, serializes opcode `0x54`, family byte `1`, subcommand `3`, and the selected employee item id only. The scheduled `record+0x40c` current price/display value is preserved in the schedule call for source/binary shape but is not emitted by case `3`.
  - The selected `EmployeeRecord*` is not stored in these parent pending fields; it remains on the property dialog at `this+0x280`.
- 2026-06-24 B006 MCP source-quality recheck closed the stale raw-helper blocker wording for this class. Raw packet-helper starts `0x004a3650`, `0x004a37a0`, `0x004a3830`, `0x004a38d0`, `0x004a3960`, `0x004a39d0`, and `0x004a3a30`; raw record-mutation starts `0x004a3be0` and `0x004a3ca0`; and raw constructor-shaped `0x004a4ae0` are still not functions, have zero direct xrefs, and have zero absolute VA/RVA pointer-byte routes. Their exact pages stay file-owned through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), with no class-method promotion. This is a resolved no-code/no-promotion disposition, not an open class-level C++ blocker.
- 2026-06-29 B006 current MCP session `967f0703` reconfirmed UID0003L2 no-function/no-xref/no-pointer-route evidence, the `0x004a3be0` and `0x004a3ca0` raw body boundaries, `0x41c` record stride, and `0x107` dword copy. UID0003L2 now uses a formal no-body marker through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md); class-method promotion, raw helper C++, and per-body child splits remain rejected.
- 2026-06-26 B001 source-quality recheck for [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) confirms the parser is a file-local helper used by this class's dispatcher/load/update support flow. MCP session/database `80de0a67` reconfirmed callers at `0x004a300d`, `0x004a3bb1`, and raw `0x004a3c05`; the helper now emits through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), while this class page remains support context for the record array and packet methods.
- 2026-06-28 B002 accepted implementation for [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) resolves the class-level empty-emitter issue for the command sender. Current MCP session `agent_b009_0002my_20260628` reconfirmed the function as `sub_4A2C80`, size `0x2dd`, with aligned start/end bytes, `retn 0Ch`, tertiary vtable slot `0x00618f94 -> 0x004a2c80`, no direct callers, PacketBuffer writer callees, Socket queue/send handoff, DialogPane close helpers, and TimerHandler scheduling calls. The child now emits `bool EmployeeDialogPane::SendCommand(int commandId, unsigned int argument0, unsigned int argument1)` as first-draft C++ through this class.
- `EmployeeDialogPane::SendCommand` field notes from B002: raw TimerHandler-subobject `this+0x6a4` maps to primary `m_commandPacketBuffer` at `+0x748`, raw `this+0x7a4` maps to `m_employeeDialogId` at `+0x848`, raw `this+0x1c8/+0x1cc` remain `m_pendingPropertyPriceValue`/`m_pendingPropertyPriceState` at primary `+0x26c/+0x270`, raw `this+0x37c` maps to the existing accepted `m_pendingQuantity` field at primary `+0x420`, raw `this+0x380/+0x384/+0x388` map to inferred `m_pendingQuantitySlot`, `m_pendingQuantityCount`, and `m_pendingQuantityFallbackSlot` at primary `+0x424/+0x428/+0x42c`. The `m_pendingQuantity` spelling is preserved for consistency with accepted [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md) C++ even though SendCommand case `5` proves it is used as a state/discriminator.
- 2026-06-29 B001 accepted implementation for [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md) records that the exact `EmployeeDialogPane` vtable/RTTI child is class-owned source-declared/generated-binary storage with a formal no-raw-vtable marker. Current MCP session `967f0703` reconfirmed non-function `.rdata` addresses, exact dwords/bytes including `0x00618f94 -> 0x004a2c80`, UID0003KW target size `0x2dd`, table-base stores, and next-class boundary `0x00618f98`.

## Destructor And Tail Layout

| Offset / fact | Current source-quality disposition |
| --- | --- |
| complete size `0x850` | Exact. Allocation paths `0x00508d2e -> 0x00508d53` and `0x005103b2 -> 0x005103d2` each request `0x850`; UID0003L4 independently uses `0x850` in its guarded deleting path. The historical 2804-byte lead is rejected. |
| `+0x748` | Accepted `m_commandPacketBuffer`; UID0003KR writes the seven-byte close notification here. |
| `+0x848` | Accepted `m_employeeDialogId`; serialized big-endian at packet offsets `+2..+5`. |
| `+0x84c` | `EmployeeRecord *m_employeeRecords`, the final four-byte class field. Load logic allocates `count * 0x41c`; both destructor forms free the nullable pointer and do not clear it afterward. |
| source destructor | UID0003KR is exact `[0x004a22f0,0x004a23a8)`, SHA256 `E7DD91C89E251B96E3E7025A5B439444C779FDC590C76AF8E2B2ACBDCC528836`, with zero inbound xrefs and no delete/guard tail. It emits `EmployeeDialogPane::~EmployeeDialogPane()`. |
| compiler wrapper | UID0003L4 is exact `[0x004a4d40,0x004a4e27)`, SHA256 `C1A6A5C685C3FE1DB9CF7EDDFBC2AFC8659D414B824922AF69B1EE8BC0E3324A`, reached only by primary vtable data and `0xa0`/`0xa4` adjustors. It is false/non-emitting. |

The eventual complete class declaration must contain a public virtual `~EmployeeDialogPane()` so the compiler regenerates primary/secondary/tertiary deleting slots and adjustors. Formal H remains blank in this callback because a loose declaration without the complete class shell would be invalid. Do not add a scalar-deleting-wrapper method, explicit base-destructor call, explicit vptr stores, deleting flags, guard path, object free, or return-this mechanics to human source.

## Ownership Synthesis

`EmployeeDialogPane` should remain the central class for the employee-shop feature. The class owns the employee record buffer, visible-slot state, seller/item drawing, opcode `0x54` command path, and packet-response update flow. The property, quantity, and add-employee item panes are feature-private companions rather than independent dialog subsystems; they reuse generic dialog/item-picker infrastructure but route through this owner object and employee command semantics.

Do not attach a partial class H yet. Exact size, tail fields, and destructor source/compiler separation are now resolved, but the complete class still needs final declaration shape and the remaining field/method declarations before a valid shell can be emitted. The required future declaration is a public virtual `~EmployeeDialogPane()`, with UID0003KR supplying its definition. The raw helper islands already have no-code/no-promotion dispositions and do not need to be solved again before this class can progress; [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md) records that disposition with a B005 formal covered-by marker, and [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md) records it with a B006 formal no-body marker, not class methods. Exact children can still emit when they meet the active code-entry gate; [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) now emits as a file-local helper through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) now emits as a class method through this page, and [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md) emits through [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md).

## Assignment Gate

`CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md). This class is `90/93`, the direct source-file parent is `91/92`, and the relationship is direct by-structure ownership: this class is the main type in the employee-shop source module, not a nested helper owned by another class page. UID0003L4 retains this class as semantic owner even though that compiler wrapper is false/non-emitting.

## Score Rationale

- Completion is `90` because purpose, method map, child dialogs, record layout, source placement, vtable data, exact parser/property/quantity/vtable children, raw-island dispositions, exact `0x850` complete size, tail-field map, ordinary destructor source, compiler-wrapper exclusion, and public virtual-destructor obligation are documented.
- Confidence is `93` because multiple live IDA-backed pages agree on class role, method anchors, source file, exact `0x41c` record stride, exact `0x850` allocation/guard size, vtable routes, destructor parity, packet bytes, child dialog relationships, and field offsets `+0x748/+0x848/+0x84c`.
- Both scores remain below final-audit range because several field/control names, the packet-byte-8 enum spelling, and the complete class declaration shape remain provisional. Formal H therefore stays blank until a complete valid shell can include the required public virtual destructor.
- Raw starts `0x004a3650`, `0x004a3be0`, and `0x004a4ae0` remain resolved no-code/no-promotion evidence, not open source-placement blockers. UID0003L4 likewise remains class-semantic compiler evidence, not a source method.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0003KQ][0x004a1d70-0x004a22ef.EmployeeDialogPaneConstructor](by-memory/0x004a1d70-0x004a22ef.EmployeeDialogPaneConstructor.md)
- [UID:0003KR][0x004a22f0-0x004a23a8.EmployeeDialogPaneDestructor](by-memory/0x004a22f0-0x004a23a8.EmployeeDialogPaneDestructor.md)
- [UID:0003KT][0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper](by-memory/0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper.md)
- [UID:0003KU][0x004a2560-0x004a2a51.EmployeeDialogPaneOnPaint](by-memory/0x004a2560-0x004a2a51.EmployeeDialogPaneOnPaint.md)
- [UID:0003KV][0x004a2a60-0x004a2c78.EmployeeDialogPaneOnMouseInput](by-memory/0x004a2a60-0x004a2c78.EmployeeDialogPaneOnMouseInput.md)
- [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md)
- [UID:0003KX][0x004a2f60-0x004a322c.EmployeeDialogPanePacketDispatcher](by-memory/0x004a2f60-0x004a322c.EmployeeDialogPanePacketDispatcher.md)
- [UID:0003KY][0x004a3240-0x004a33d8.EmployeeDialogPaneOnButtonAction](by-memory/0x004a3240-0x004a33d8.EmployeeDialogPaneOnButtonAction.md)
- [UID:0003KZ][0x004a33e0-0x004a34cb.EmployeeDialogPaneRebuildSelectionList](by-memory/0x004a33e0-0x004a34cb.EmployeeDialogPaneRebuildSelectionList.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)
- [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md)
- [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md)
- [UID:0003L1][0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData](by-memory/0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData.md)
- [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md)
- [UID:0003L3][0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields](by-memory/0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields.md)
- [UID:0003L4][0x004a4d40-0x004a4e27.EmployeeDialogPaneScalarDeletingDestructor](by-memory/0x004a4d40-0x004a4e27.EmployeeDialogPaneScalarDeletingDestructor.md)
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md)
- [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md)
- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md)
- [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md)
- [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md)

## Changes

- 2026-08-24 B002 UID0003L4 accepted implementation: raised `88/89` to `90/93`; recorded exact `0x850` class size, final `EmployeeRecord *m_employeeRecords` at `+0x84c`, packet/id tail fields, UID0003KR sole ordinary destructor body, UID0003L4 false/non-emitting wrapper policy, and the public virtual-destructor obligation for a future complete class shell. Formal H remains blank.
- 2026-06-29 B006 raw record mutation marker sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: recorded that [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md) now uses a formal no-body marker through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), backed by MCP session `967f0703` no-function/no-xref/no-pointer-route proof, two-body boundary evidence, `0x41c` stride, and `0x107` copy evidence. The class keeps no raw helper body and no class-method promotion.
- 2026-06-29 B005 raw packet helper marker sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: recorded that [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md) now uses a formal covered-by/no-code marker through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), backed by MCP session `967f0703` no-function/no-xref/no-pointer-route proof. The class keeps no raw helper body and no class-method promotion; sibling source-bearing coverage remains [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) and [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md).
- 2026-06-29 B001 vtable marker and stale-source cleanup:
  - Score unchanged at `88/89`.
  - Summary/evidence: historicalized active `simroot_v2` and Wave3 recovered-source wording as generated lead/background material; converted active `AUTOGEN_PARENT_UID` gate text to current `CANONICAL_OWNER` / `EMITTER_UIDS` terminology; and recorded that [UID:0002ME][0x00618efc-0x00618f98.EmployeeDialogPaneVtableData](by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md) now carries a formal comment-only no-raw-vtable marker through this class. Current MCP session `967f0703` reconfirmed the exact dwords/bytes, UID0003KW slot target size, non-function `.rdata` addresses, vtable-base stores, and `0x00618f98` next-class boundary.
  - Rejected alternatives: no class score change or whole-class C++ was made; the exact vtable child carries only the marker while this class remains below final declaration quality.
- 2026-06-28 B002 SendCommand empty-emitter implementation sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: recorded that [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) now emits first-draft C++ through this class. Current MCP session `agent_b009_0002my_20260628` reconfirmed exact target range `0x004a2c80-0x004a2f5d`, vtable slot `0x00618f94`, padding bytes, no direct callers, packet helper callees, TimerHandler scheduling, six employee command cases, and close-helper calls. Added class field notes for `m_commandPacketBuffer`, `m_employeeDialogId`, `m_pendingQuantitySlot`, `m_pendingQuantityCount`, and `m_pendingQuantityFallbackSlot`, while preserving existing `m_pendingPropertyPriceValue`, `m_pendingPropertyPriceState`, and accepted `m_pendingQuantity` naming.
  - Rejected alternatives: no class-level score change or whole-class C++ was made because the exact child now carries the method body and the broader class declaration/field set remains provisional.
- 2026-06-26 B001 DeserializeEmployeeRecord support sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: clarified that [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) is a file-local static/stdcall parser helper emitted through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), not an `EmployeeDialogPane::` method. MCP session/database `80de0a67` reconfirmed the dispatcher/full-list/raw-upsert callers and target first-draft C++ route; this class page keeps support context for the record array, class packet methods, and field/layout consumers.
- 2026-06-24 B006 raw-route source-quality sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: refreshed class evidence/ownership/score wording to distinguish resolved raw-island no-code dispositions from remaining whole-class declaration and field-name work. MCP session `80de0a67` reconfirmed no function objects, zero xrefs, and zero VA/RVA pointer-byte routes for the raw packet-helper starts, raw record-mutation starts `0x004a3be0`/`0x004a3ca0`, and raw constructor-shaped `0x004a4ae0`. The raw helper islands remain file-owned support pages through [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), with no class-method promotion; B005/B006 2026-06-29 later replaced UID0003L0/UID0003L2 blank states with formal no-code markers.
- 2026-06-23 B001 property-command support sync:
  - Score unchanged at `88/89`.
  - Summary/evidence: incorporated the accepted [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md) route into the class support notes. Parent `+0x26c/+0x270` are now documented as `m_pendingPropertyPriceValue`/`m_pendingPropertyPriceState` for command `2`, and [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) documents command cases `2` and `3`. The old selected-record-pointer interpretation for parent `+0x26c` is superseded.
- 2026-06-12 A004 Goal 2 exact method split:
  - Before: score `85/86`, and the method map still used raw address spans for the main methods, omitted helper caveats, and raw record mutation body.
  - After: score `88/89`; modeled class methods now link to exact child pages, and raw helper islands are explicitly file-owned no-code evidence rather than unsplit class-method rows.
  - Evidence: live IDA confirmed function sizes, vtable slots, callers/callees, raw island boundaries, opcode constants, and record stride; the direct file parent [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) is now `90/88`.
- 2026-06-07 A010 Batch086 class coverage toss-up:
  - Before: score `82/84`, `AUTOGEN_PARENT_UID` blank, and the direct file parent was just below the corrected confidence gate.
  - After: score `85/86`, `AUTOGEN_PARENT_UID:0000J0`.
  - Evidence: live IDA reconfirmed constructor callers, action/parser/helper anchors, quantity/property/add-item relationships, and vtable-store references; [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) was raised to `88/85`, so both child and direct parent meet the corrected 85/85 gate.
- 2026-06-07 A008 class/file sync:
  - Before: the class page was still scored `78/80` even though the file page and child pages had since gained exact parser/property/quantity/vtable/resource coverage and a stronger AddEmployee inline-construction anchor.
  - After: score raised to `82/84`, with an ownership synthesis tying the main dialog, file-local packet helpers, property/quantity child dialogs, and add-employee item variant back to the employee-shop class.
  - Evidence: existing IDA-backed pages [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md), [UID:0000TT][AddEmployeeItemDialogInlineConstruction_004A339F](by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md), exact employee child by-memory pages, vtable data, and [UID:0001R9][employee-dialog-resources](by-resource/employee-dialog-resources.md). No fresh live IDA claim was added in this pass.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/80`.
  - Summary/evidence: shop dialog role, method map, employee record stride, opcode family, historical omitted-helper caveats, child dialogs, vtable evidence, and adjustor-thunk handling are documented; raw/projected helper modeling is superseded by the B006 no-code/no-promotion disposition above, while current confidence remains limited by final field names and whole-class declaration shape.
- 2026-05-31 reconstructable flag and exact helper link:
  - Before: `RECONSTRUCTABLE:` was blank and `DeserializeEmployeeRecord` was only listed as an address span in the method map.
  - After: `RECONSTRUCTABLE:TRUE` and `DeserializeEmployeeRecord` links to its exact by-memory page.
  - Summary/evidence: live IDA MCP recheck confirms the parser at `0x004a34d0` is a real function, is called by employee-dialog packet/list paths, and writes the documented `EmployeeRecord` layout.
