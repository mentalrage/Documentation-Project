*** UID:0001UD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EmployeeRecord

## Status

- Confidence: strong for size and primary fields used by employee dialog code; medium for final field names.
- Current Wave3 entity kind: inferred struct/layout, not a standalone class.
- Likely owner header/source: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Size: `0x41c` bytes (`1052`)

## Layout Hypothesis

| Offset | Size | Proposed field | Evidence |
| --- | --- | --- | --- |
| `0x000` | `4` | `id` / `employeeItemId` | Parsed by `DeserializeEmployeeRecord`; zero marks empty or default slot. |
| `0x004` | `2` | `type` / `statusCode` | Parsed from packet word; used to distinguish empty reusable slots. |
| `0x006` | `1` | `flagByte` | Parsed from packet byte and preserved by update paths. |
| `0x008` | `0x200` | `name[256]` | Multibyte packet name converted to UTF-16; optional percent suffix appended. |
| `0x20a` | `0x202` | `extraText[257]` or reserved text | Cleared by current update code; exact semantic still unresolved. |
| `0x40c` | `4` | `goldAmount` / `priceValue` | Displayed in tooltip/property text and sent through employee item commands. |
| `0x410` | `4` | `level` / `editValue` | Displayed as bracketed level in tooltip, or used as editable value in property dialog. |
| `0x414` | `4` | `dataField3` | Third trailing dword in packet parser. |
| `0x418` | `4` | `defaultId` / `fallbackItemId` | Used when `id == 0` in empty/default slot paths. |

## Evidence Notes

- IDA MCP decompilation of `0x004a34d0` writes fields at `0x000`, `0x004`, `0x006`, `0x008`, `0x20a`, `0x40c`, `0x410`, `0x414`, and `0x418`.
- `EmployeeDialogPane::LoadEmployeeData` allocates `totalSlots * 1052` bytes and initializes record slots.
- `EmployeeDialogPane::RebuildSelectionList`, `OnMouseInput`, and `OnPaint` index records with stride `0x41c`.
- `EmployeeItemPropertyDialogPane` treats the same record pointer as item data with id, sprite/palette-like fields, name text, current price, and editable price.

## Open Questions

- The same offsets are used with shop-item and employee-status meanings depending on UI path. Final field names should wait for one more pass through item sprite render and property-edit usage.
- `extraText` at `0x20a` is currently cleared in the update helper; broader packet cases may reveal its real display purpose.

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md)
- [UID:0000UL][EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0](by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md)

## Changes

- 2026-05-31 completion/reconstruction metadata:
  - What existed before: metadata remained unevaluated at `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite documented parser/layout evidence.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`; the exact `DeserializeEmployeeRecord` page was added to cross-references.
  - Summary/evidence: live IDA MCP decompilation of `0x004a34d0` confirms fixed writes to offsets `+0x000`, `+0x004`, `+0x006`, `+0x008`, `+0x20a`, `+0x40c`, `+0x410`, `+0x414`, and `+0x418`, while callers confirm the `0x41c` record stride.
