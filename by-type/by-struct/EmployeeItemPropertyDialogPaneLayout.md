*** UID:0001UB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00004D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00004D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001UB] EmployeeItemPropertyDialogPane layout evidence marker.
// Derived tail fields support exact property-dialog method children; no standalone layout/body C++ is emitted here.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EmployeeItemPropertyDialogPane Layout

## Status

- Entity kind: derived dialog layout.
- Covered class: [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md).
- Likely owner source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md).
- Size: `0x284` bytes on the live allocation path.
- Confidence: very strong for feature-specific tail fields, vtable offsets, inherited control-manager use, command-handler field routing, exact `0x284` extent, and compiler-only destructor-wrapper corroboration; strong for the inferred implicit-destructor source shape.
- Owner/emitter route: attached under [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) as the derived dialog layout. The class and [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) file parent clear the strict route gate. The layout page itself remains blank C++, but accepted children [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md) and [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md) now have first-draft C++ using these field names.

## Layout Hypothesis

`EmployeeItemPropertyDialogPane` is a `DialogPane`-derived item price/property editor. The inherited dialog base occupies the first `0x26c` bytes. The derived tail stores the owning employee dialog, the icon rectangle used by `OnPaint`, and the selected employee record pointer.

| Offset | Size | Observed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | 4 | primary vtable | Constructor stores `0x00618f9c` at `0x004a4230`. |
| `+0xa0` | 4 | secondary dialog/input vtable view | Constructor stores `0x00618ffc` at `0x004a4236`. |
| `+0xa4` | 4 | tertiary event/update vtable view | Constructor stores `0x0061902c` at `0x004a4240`. |
| `+0x1fc` | 4 | inherited `DialogControlManager *m_controlManager` | [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) names inherited `DialogPane + 0x1fc` as `m_controlManager`; `OnCommand` reads this field, dispatches vtable slot `+0x10` with control id `3`, and reads price text from the returned `TextEditControlPane`. |
| `+0x26c` | 4 | `EmployeeDialogPane* m_owner` / `parentDialog` | Constructor stores argument `a3` at `0x004a420f`; `OnCommand` reads it before staging parent pending property price payload fields and scheduling employee command events. |
| `+0x270` | 16 | `RECT m_itemIconRect` | Constructor writes `20, 21, 68, 69` through `SetRect`; accepted `OnPaint()` C++ copies this rectangle, preserves left/top, and sets right/bottom to left/top plus `44` for the fixed item-image slot. The command handler does not touch this adjacent derived-tail field. |
| `+0x280` | 4 | `EmployeeRecord* m_itemRecord` | Constructor stores argument `a2` at `0x004a421a`; accepted `OnPaint()` C++ reads target-context `itemImageId` and `itemPaletteFlags` from this record, while `OnCommand` reads item id, price, and editable price. |
| `+0x284` | - | object end | `EmployeeDialogPane::OnButtonAction` allocates `644` bytes before calling the constructor. |

## Method Offset Evidence

- `EmployeeDialogPane::OnButtonAction` at `0x004a32ff` allocates `644` bytes (`0x284`) and calls the constructor at `0x004a3319`.
- Constructor `0x004a41c0` calls `DialogPane::DialogPane("Property", 20, 1)`, then stores the parent pointer at dword index `155` (`+0x26c`) and the item pointer at dword index `160` (`+0x280`).
- Constructor `0x004a43d7` writes the item icon rectangle at dword index `156` (`+0x270`) using `SetRect(20, 21, 68, 69)`.
- `OnPaint` at `0x004a4570` reads `this + 0x270` and `this + 0x280`, loads `SELLITEM.EPF`/`SELLITEM.PAL`, calls `GetItemGlyphBounds` for selected-record word `+0x004`, expands `m_itemIconRect` to a 44-by-44 destination, and calls the item-object image renderer using target-context `itemImageId` (`record + 0x004`) and `itemPaletteFlags` (`record + 0x006`).
- `OnCommand` at `0x004a4660` reads `this + 0x26c`, `this + 0x1fc`, and `this + 0x280`. Confirm action id `1` reads price edit control id `3`, seeds/parses the price from `record + 0x410`, writes the edited price to parent `+0x26c`, sets parent `+0x270` to `1`, and schedules employee event/subcommand `2`; remove action id `0` schedules event/subcommand `3` with record id and current `record + 0x40c`; close action id `2` closes only.
- Parent `+0x26c/+0x270` are not layout fields of this dialog. B001 2026-06-23 resolves them as [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md) pending property price payload fields, consumed by [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) case `2` through the TimerHandler-subobject offsets `this+456/+460`.
- 2026-06-14 live IDA MCP rechecked the exact local family: `EmployeeDialogPane::OnButtonAction` at `0x004a3240` is size `0x198`, allocates `644` bytes (`0x284`) at `0x004a32ff`, and calls `0x004a41c0` at `0x004a3319`; the property constructor is size `0x3ab`, writes `this[155]`/`this[160]` for `+0x26c/+0x280`, installs the three vtables, writes the `+0x270` rectangle, and creates the dialog controls; `OnPaint` is size `0xe9` and is primary vtable slot data xref `0x00618fe0`; `OnCommand` is size `0x10e` and is primary slot `0x00618fe4`, reading the control collection at `+0x1fc`, parent at `+0x26c`, and record at `+0x280`.
- [UID:0003L5][0x004a4e30-0x004a4e6b.EmployeeItemPropertyDialogPaneScalarDeletingDestructor](by-memory/0x004a4e30-0x004a4e6b.EmployeeItemPropertyDialogPaneScalarDeletingDestructor.md) independently embeds guarded size `0x284` after ordinary `DialogPane_destructor` teardown. The same size appears in the allocation before constructor call `0x004a3319` and at this layout's exact end, providing three-way object-extent corroboration.
- The wrapper has no property-specific cleanup and no ordinary caller. Its only routes are primary vtable `0x00618f9c` plus the `this -= 0xa0` and `this -= 0xa4` adjustor thunks from secondary/tertiary table views, matching the offsets in this layout.

## Vtable Notes

Primary vtable `0x00618f9c` includes:

- `+0x00 -> 0x004a4e30` scalar deleting destructor.
- `+0x44 -> 0x004a4570` paint handler. B004 2026-06-26 resolves this as [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md), now owner/emitter [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) with first-draft C++.
- `+0x48 -> 0x004a4660` command/action handler.

Secondary vtable `0x00618ffc` and tertiary vtable `0x0061902c` are installed at `+0xa0` and `+0xa4`. Their destructor slots point to compiler-generated adjustor thunks `0x004a4cdd` and `0x004a4ce8`; keep those as ABI glue, not source methods.

The secondary thunk is exact bytes `81 e9 a0 00 00 00 e9 48 01 00 00`, SHA256 `B22DEFACEC74C40B73CE02F91CFE2515BCFD638DCAF8F359B94E32E998FE954A`; the tertiary thunk is exact bytes `81 e9 a4 00 00 00 e9 3d 01 00 00`, SHA256 `D1DF58142A94587D821DCF92882BFC356003483C5E29FF451EB8CC96A8F12DA9`. Their deltas are direct ABI evidence for the table-view offsets, not extra layout fields or handwritten helper functions.

## Reconstruction Notes

Model the source type as a feature-private property dialog with a typed `EmployeeDialogPane*` owner, `RECT m_itemIconRect`, and `EmployeeRecord* m_itemRecord`. Do not copy the generated local `DialogLayout` and `PaneState` overlay structs into final source; they are decompiler scaffolding for the derived tail fields.

The scalar deleting destructor's inherited target is resolved as ordinary `DialogPane_destructor` at `0x0049d9f0`; earlier `TransferReplyAlert::~DialogPane` and `boost::exception::~exception` labels are superseded type/decompiler pollution. UID0003L5 uses bit `1` as the release gate, bit `4` for the guarded-size no-free path, optional project delete, and exact size `0x284`, but remains compiler-generated and contributes no formal CPP/H.

The highest-probability original class source omitted an explicit destructor because the wrapper performs no derived-field cleanup beyond inherited teardown. The compiler generated the implicit virtual derived destructor, scalar deleting wrapper, and adjusted entries from the class/inheritance shape. An explicitly empty/defaulted destructor is a lower-probability binary-equivalent historical alternative and is not inserted merely to imitate compiler output.

## Parent Rationale

Attach this layout declaration to [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md). The offsets describe that dialog's derived tail and vtable views, the owner class clears the `80/80` attachment gate and is already attached to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), and the broader file page owns the employee-dialog feature family without changing this layout's single-class identity.

## Score Rationale

Completion is raised to `88` because the page now documents the object extent, exact allocation/caller, constructor field writes, vtable stores, paint and command consumers, owner/emitter route, inherited `m_controlManager`, price edit control id `3`, exact wrapper-size corroboration, and compiler/source destructor disposition. Confidence is raised to `93` because allocation, layout endpoint, wrapper guard constant, inherited `DialogPane` teardown, primary/secondary/tertiary routes, and exact adjustor hashes agree. It remains below final-audit range because some constructor helper/control factory spellings and the implicit-versus-explicit-empty historical source choice are not directly observable.

## Cross-References

- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md)
- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md)
- [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md)
- [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)
- [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md)
- [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md)

## Changes

- 2026-08-24 B005 UID0003L5 source-quality callback: raised `86/91 -> 88/93`; replaced stale base-destructor uncertainty with resolved `DialogPane_destructor`, exact `0x284` allocation/layout/wrapper corroboration, deleting-flag behavior, exact adjustor deltas/hashes, and highest-probability implicit-destructor inference while preserving the class owner/emitter marker route.
- 2026-06-26 B004 source-quality sync for [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md):
  - Score unchanged at `86/91`.
  - Summary/evidence: added the accepted OnPaint support details: `m_itemIconRect` at `+0x270` feeds the first-draft C++ copy/44-pixel expansion, `m_itemRecord` at `+0x280` feeds `itemImageId`/`itemPaletteFlags`, and primary vtable slot `+0x44` / `0x00618fe0 -> 0x004a4570` now routes to direct owner/emitter [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md). The layout remains a declaration/support page with blank C++.

- 2026-06-23 B001 source-quality sync for [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md):
  - Before: `85/90`, with `+0x1fc` described generically as an inherited control collection and C++ still blocked by inherited/control/source field names.
  - After: `86/91`; `+0x1fc` uses inherited `DialogPane::m_controlManager`, `+0x26c` records `m_owner`/`parentDialog`, `+0x270` records `m_itemIconRect`, and `+0x280` records `m_itemRecord`.
  - Summary/evidence: B001 current MCP session `80de0a67` and [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) resolve the command-handler control path through `m_controlManager`, price edit control id `3`, `TextEditControlPane::ReadText`, and parent pending property price fields. [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md) now carries first-draft C++; this layout page remains a declaration/support page with blank C++.
- 2026-06-14 A002 Goal 2 score refresh:
  - What existed before: `80/88`, with strong offset evidence but completion still capped at the old attachment threshold.
  - Changed to: `85/90`.
  - Summary/evidence: live IDA MCP reconfirmed `0x004a3240` allocation/caller evidence, constructor `0x004a41c0` size `0x3ab`, paint `0x004a4570` size `0xe9`, command `0x004a4660` size `0x10e`, the `0x284` allocation, vtable stores, `+0x26c/+0x270/+0x280` tail fields, and command use of `+0x1fc`. At that time unresolved inherited/control/source names kept the layout's formal source minimal; UID0003L5 now independently resolves the inherited destructor target while remaining compiler-only and non-emitting.
- 2026-06-07 parent attachment update:
  - What existed before: the layout page had strong constructor/paint/command and field-offset evidence, but no autogen parent.
  - Changed to: `COMPLETION:80` and `AUTOGEN_PARENT_UID:00004D`, with an explicit class-parent rationale.
  - Summary/evidence: [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) owns the `+0x26c/+0x270/+0x280` derived tail, clears the attachment gate, and links the same exact method and vtable-data pages. The then-provisional destructor-base label is now superseded by exact `DialogPane_destructor` evidence; the layout retains its existing marker/children route rather than emitting a duplicate standalone body.
- 2026-05-31 completion/reconstruction metadata:
  - What existed before: metadata remained unevaluated at `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite detailed layout notes.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`; exact constructor/paint/command memory pages were added to cross-references.
  - Summary/evidence: live IDA MCP recheck confirms the constructor size/caller, vtable stores, parent pointer at `+0x26c`, icon rectangle at `+0x270`, item record pointer at `+0x280`, paint use of those fields, and command use of parent/record/control state.
