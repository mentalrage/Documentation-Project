*** UID:0001U5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DialogSession Layouts

## Status

- Entity kind: class layout notes for session dialog infrastructure.
- Covered classes: [UID:00003U][DialogSession](by-class/DialogSession.md) and [UID:00003S][DialogInSession](by-class/DialogInSession.md).
- Likely owner header/source: [UID:0000IU][DialogSession](by-file/DialogSession.md).
- Parent attachment: attached to [UID:0000IU][DialogSession](by-file/DialogSession.md), which is scored `84/80`; this multi-class layout page is scored `82/88`, so both sides clear the `80/80` child attachment gate.
- Confidence: strong for listed offsets; medium for final source-facing names.

## DialogSession Layout

`DialogSession` is a [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)-derived session container. It has the common three-view pane vtable layout, then a small stack/list state block at the end of the base pane footprint.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | primary vptr, `0x00618d30` | Constructor stores at `0x004a0dc1`; destructor paths reinstall this table. |
| `+0x04-+0xf7` | inherited `Pane` state | Constructor calls `Pane` constructor with mode `4`; later applies full-screen bounds and attaches renderer state. |
| `+0xa0` | secondary/event vptr, `0x00618d7c` | Constructor stores at `0x004a0dc7`; secondary destructor thunk subtracts `0xa0`. |
| `+0xa4` | tertiary/event vptr, `0x00618dac` | Constructor stores at `0x004a0dd1`; tertiary destructor thunk subtracts `0xa4`. |
| `+0xf8` | tracked dialog list pointer | Constructor allocates a 20-byte list object initialized as `List(4, 16)` and stores it here; stack helpers read and clear it. |
| `+0xfc` | active dialog index byte | Constructor initializes `0xff`; push/pop/close helpers read, increment, decrement, and test it as a signed stack index. |

## DialogInSession Layout

`DialogInSession` is a [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)-derived base for dialogs stored inside a `DialogSession`. It uses the common dialog three-view vtable layout and adds a small session-specific tail.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | primary vptr, `0x00618db8` | Constructor stores at `0x004a142d`; destructor paths reinstall this table. |
| `+0xa0` | secondary/event vptr, `0x00618e18` | Constructor stores at `0x004a1433`; secondary destructor thunk subtracts `0xa0`. |
| `+0xa4` | tertiary/event vptr, `0x00618e48` | Constructor stores at `0x004a143d`; tertiary destructor thunk subtracts `0xa4`. |
| `+0x0f8-+0x268` | inherited `DialogPane` state | Constructor calls `DialogPane::DialogPane(L"", dialogId, 1)` before writing the session fields. |
| `+0x26c` | dialog type byte | Constructor stores the incoming `dialogType` byte at `this[620]`. |
| `+0x270` | session data pointer/value | Constructor stores the incoming `sessionData` value at dword index `156`. |

The `DialogInSession` tail overlaps the same derived-tail zone used by several other `DialogPane` subclasses. Do not treat `+0x26c` or `+0x270` as base `DialogPane` fields.

## IDA Evidence

Checked on 2026-05-26 and spot-rechecked on 2026-05-31:

- `DialogSession::DialogSession` at `0x004a0d80` calls `Pane` construction, installs vtables at `+0x00`, `+0xa0`, and `+0xa4`, allocates/initializes the tracked-dialog list at `+0xf8`, initializes active index byte `+0xfc` to `0xff`, applies full-screen bounds, and attaches renderer state.
- `CloseAllDialogs`, `PushDialog`, `PopCurrentDialog`, `FindPreviousDialog`, and `GetDialogAtIndex` read `+0xf8` and `+0xfc` as the tracked-list pointer and active stack index.
- `DialogInSession::DialogInSession` at `0x004a1400` calls `DialogPane::DialogPane`, stores `dialogType` at `+0x26c`, stores session data at `+0x270`, and installs three `DialogInSession` vtables.
- `DialogInSession` destructor paths at `0x004a1450` and `0x004a14a0` reinstall the same three vtables before base `DialogPane` teardown.
- 2026-05-31 IDA MCP `lookup_funcs` reconfirms the function starts and sizes for `DialogSession` construction/destruction/stack helpers at `0x004a0d80`, `0x004a0e70`, `0x004a0f40`, `0x004a0fc0`, `0x004a10e0`, `0x004a1250`, `0x004a1360`, and `0x004a1390`.
- 2026-05-31 IDA MCP `lookup_funcs` reconfirms `DialogInSession` constructor/destructor starts at `0x004a1400`, `0x004a1450`, `0x004a14a0`, and `DialogSession` scalar deleting destructor at `0x004a1500`.
- 2026-05-31 IDA MCP decompilation of `0x004a0d80` shows tracked-list allocation into `+0xf8` and active index byte `+0xfc = 0xff`; decompilation of `0x004a1400` shows `DialogPane::DialogPane` base construction, `dialogType` at `+0x26c`, session data at `+0x270`, and `DialogInSession` vtable stores.
- `xrefs_to 0x00618d30` and `xrefs_to 0x00618db8` confirm constructor/destructor stores for the `DialogSession` and `DialogInSession` primary vtables. `xrefs_to 0x004a1400` confirms construction from multiple bulletin/session dialog constructors.

## Reconstruction Notes

- Keep `DialogSession` and `DialogInSession` in one source module unless later historical source evidence proves a split.
- The four adjustor thunks at `0x004a146f`, `0x004a147a`, `0x004a1485`, and `0x004a1490` are ABI glue for these layouts, not handwritten methods.
- Active generated source uses feature names such as `RankingDialog` for generic session-dialog entries. Treat those as provisional until caller/type review settles the final base type.

## Cross-References

- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:00003U][DialogSession](by-class/DialogSession.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md)
- [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the session and in-session dialog constructors/destructors, tracked-list/index fields, session-dialog tail fields, and vtable stores. The page remains below `95+` because exact source-facing names for the stack/list helper methods and session tail fields are not final.
- 2026-06-06 parent attachment:
  - What existed before: the layout had strong IDA-backed offsets and was scored above `80/80`, but `AUTOGEN_PARENT_UID` was blank.
  - Changed to: attached to [UID:0000IU][DialogSession](by-file/DialogSession.md) without changing scores.
  - Summary/evidence: this page covers both `DialogSession` and `DialogInSession`, so file-level ownership is clearer than choosing one class; the file page is scored `84/80` and documents the same shared session-dialog infrastructure.
