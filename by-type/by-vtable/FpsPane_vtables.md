*** UID:0001XN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FpsPane vtables

## Status

- Entity kind: vtable layout
- Primary vtable: `0x0061a620`
- Secondary pane view: `0x0061a66c`
- Timer/update view: `0x0061a69c`
- Exact vtable data: [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)
- Confidence: strong for key slots, medium for inherited slot names.
- Proposed owner: [UID:0000JK][FpsPane](by-file/FpsPane.md)
- Layout docs: [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)

## Key Slots

| Vtable | Slot/offset | Target | Notes |
| --- | --- | --- | --- |
| `0x0061a620` | `+0x00` | `0x004b6c50` | `FpsPane::ScalarDeletingDestructor`. |
| `0x0061a620` | `+0x0c` | `0x004b8e20` | Inherited/overridden pane bounds or paint-support method. |
| `0x0061a66c` | `+0x00` | `0x004b6c2b` | [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md). |
| `0x0061a69c` | `+0x00` | `0x004b6c36` | [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md). |
| `0x0061a69c` | `+0x04` | `0x004b68b0` | `FpsPane::UpdateStatistics` timer/update callback. |

The data after `0x0061a6a4` is the adjacent ASCII `FPSDATA-*` string area, so the third vtable view appears to contain only the destructor thunk and update callback before string data begins.

## Evidence

- IDA MCP `py_eval` decoded the dword slots at all three vtable bases on 2026-05-24.
- 2026-05-31 IDA MCP dword scan confirms exact vtable-data child [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md). `0x0061a61c` is the primary RTTI locator, and `0x0061a6a4` starts the adjacent `FPSDATA-*` string area.
- `FpsPane::FpsPane`, non-deleting destructor `0x004b6470`, and scalar deleting destructor `0x004b6c50` all write the three FpsPane vtable bases.
- 2026-05-25 IDA MCP xrefs confirm writes to the primary vtable at `0x004b643b`, `0x004b6470`, and `0x004b6c56`; secondary view at `0x004b6441`, `0x004b6476`, and `0x004b6c5c`; and timer/update view at `0x004b644b`, `0x004b6480`, and `0x004b6c66`.
- The two thunks at `0x004b6c2b` and `0x004b6c36` subtract owner offsets and forward to `0x004b6c50`.
- The `0x0061a69c` update callback is invoked with the `+0xa4` subobject pointer. Normalize `0x004b68b0` field offsets by adding `0xa4`; see [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md).
- 2026-05-26 IDA MCP reconfirmed the thunk pair as vtable-only compiler glue. They are documented in [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) and listed in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:00005F][FpsPane](by-class/FpsPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md)
- [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md)
- [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md)
- [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `84/88` and marked the page reconstructable. Evidence: IDA MCP rechecked `list_globals`, `lookup_funcs`, vtable xrefs, and an exact dword scan; exact child [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) now records the RTTI/vtable boundaries and slot values.
