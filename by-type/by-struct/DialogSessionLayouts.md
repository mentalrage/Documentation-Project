*** UID:0001U5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DialogSession Layouts

## Status

- Entity kind: non-emitting class layout authority for session dialog infrastructure.
- Covered classes: [UID:00003U][DialogSession](by-class/DialogSession.md) and [UID:00003S][DialogInSession](by-class/DialogInSession.md).
- Likely owner header/source: [UID:0000IU][DialogSession](by-file/DialogSession.md).
- Owner route: [UID:0000IU][DialogSession](by-file/DialogSession.md). This layout page is intentionally non-emitting because the two class pages carry the complete declarations.
- Confidence: very strong for direct bases, all listed offsets, vtable stores, helper function bounds, stack/tail field users, source types, alignment, and compiler-facet layout.

## DialogSession Layout

`DialogSession` is a [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)-derived session container. It has the common three-view pane vtable layout, then a small stack/list state block at the end of the base pane footprint.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | primary vptr, `0x00618d30` | Constructor stores at `0x004a0dc1`; destructor paths reinstall this table. |
| `+0x04-+0xf7` | inherited `Pane` state | Constructor calls `Pane` constructor with mode `4`; later applies full-screen bounds and attaches renderer state. |
| `+0xa0` | secondary/event vptr, `0x00618d7c` | Constructor stores at `0x004a0dc7`; secondary destructor thunk subtracts `0xa0`. |
| `+0xa4` | tertiary/event vptr, `0x00618dac` | Constructor stores at `0x004a0dd1`; tertiary destructor thunk subtracts `0xa4`. |
| `+0xf8` | protected `List *m_dialogList` | Constructor allocates a 20-byte list object initialized as `List(4, 16)` and stores it here; stack helpers read and clear it. Payload slots hold `DialogInSession *`; the original custom list template spelling is not proven. |
| `+0xfc` | protected `unsigned char m_activeDialogIndex` | Constructor initializes `0xff`; push/pop/activate/close helpers read, increment, decrement, and test it as a signed stack index. Current derived `BulletinSession` source directly accesses this inherited field, rejecting the historical private declaration. |

## DialogInSession Layout

`DialogInSession` is a [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)-derived base for dialogs stored inside a `DialogSession`. It uses the common dialog three-view vtable layout and adds a small session-specific tail. The exact source-facing constructor is `DialogInSession(DialogSession *session, unsigned short dialogConfigId, unsigned char dialogType)`: `dialogConfigId` is forwarded into `DialogPane::DialogPane(L"", dialogConfigId, 1)`, while `dialogType` and `session` are stored in the derived tail.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | primary vptr, `0x00618db8` | Constructor stores at `0x004a142d`; destructor paths reinstall this table. |
| `+0xa0` | secondary/event vptr, `0x00618e18` | Constructor stores at `0x004a1433`; secondary destructor thunk subtracts `0xa0`. |
| `+0xa4` | tertiary/event vptr, `0x00618e48` | Constructor stores at `0x004a143d`; tertiary destructor thunk subtracts `0xa4`. |
| `+0x0f8-+0x268` | inherited `DialogPane` state | Constructor calls `DialogPane::DialogPane(L"", dialogConfigId, 1)` before writing the session fields. |
| `+0x26c` | public `unsigned char m_dialogType` | Constructor stores the incoming `dialogType` byte. Current session-family source reads this field directly. |
| `+0x26d-+0x26f` | natural alignment | Three bytes align the following 32-bit pointer; no explicit source field is required. |
| `+0x270` | public `DialogSession *m_session` | Constructor stores the incoming session pointer. Derived dialog classes read this inherited field directly. |

The `DialogInSession` tail overlaps the same derived-tail zone used by several other `DialogPane` subclasses. Do not treat `+0x26c` or `+0x270` as base `DialogPane` fields.

## Inheritance And Compiler Facets

- DialogSession is directly `Pane`-derived. DialogInSession is directly `DialogPane`-derived.
- RTTI base arrays include EventHandler at `+0xa0` and TimerHandler at `+0xa4` through Pane inheritance. They are not extra direct source bases.
- UID0002NB contains exact primary/secondary/tertiary table views with counts 18/11/2 for DialogSession and 23/11/2 for DialogInSession.
- Scalar deleting wrappers and `this-0xa0`/`this-0xa4` adjustor thunks are compiler-generated from the ordinary virtual destructors and these offsets. Do not model them as layout fields or handwritten methods.

## IDA Evidence

Checked on 2026-05-26 and spot-rechecked on 2026-05-31:

- `DialogSession::DialogSession` at `0x004a0d80` calls `Pane` construction, installs vtables at `+0x00`, `+0xa0`, and `+0xa4`, allocates/initializes the tracked-dialog list at `+0xf8`, initializes active index byte `+0xfc` to `0xff`, applies full-screen bounds, and attaches renderer state.
- `CloseAllDialogs`, `PushDialog`, `PopCurrentDialog`, raw/prewave `ActivateNextDialog`, `FindPreviousDialog`, `GetDialogAtIndex`, and raw/prewave `FindDialogIndex` read `+0xf8` and `+0xfc` as the tracked-list pointer and active stack index.
- `DialogInSession::DialogInSession` at `0x004a1400` calls `DialogPane::DialogPane`, stores `dialogType` at `+0x26c`, stores session data at `+0x270`, and installs three `DialogInSession` vtables.
- `DialogInSession` destructor paths at `0x004a1450` and `0x004a14a0` reinstall the same three vtables before base `DialogPane` teardown.
- 2026-05-31 IDA MCP `lookup_funcs` reconfirms the function starts and sizes for `DialogSession` construction/destruction/stack helpers at `0x004a0d80`, `0x004a0e70`, `0x004a0f40`, `0x004a0fc0`, `0x004a10e0`, `0x004a1250`, `0x004a1360`, and `0x004a1390`.
- 2026-05-31 IDA MCP `lookup_funcs` reconfirms `DialogInSession` constructor/destructor starts at `0x004a1400`, `0x004a1450`, `0x004a14a0`, and `DialogSession` scalar deleting destructor at `0x004a1500`.
- 2026-05-31 IDA MCP decompilation of `0x004a0d80` shows tracked-list allocation into `+0xf8` and active index byte `+0xfc = 0xff`; decompilation of `0x004a1400` shows `DialogPane::DialogPane` base construction, `dialogType` at `+0x26c`, session data at `+0x270`, and `DialogInSession` vtable stores.
- `xrefs_to 0x00618d30` and `xrefs_to 0x00618db8` confirm constructor/destructor stores for the `DialogSession` and `DialogInSession` primary vtables. `xrefs_to 0x004a1400` confirms construction from multiple bulletin/session dialog constructors.
- 2026-06-14 live IDA MCP in session `a001_goal2_class_batch` reconfirmed the current function starts and sizes for the layout-driving bodies: `0x004a0d80` size `0xee`, `0x004a0e70` size `0xcc`, stack helpers at `0x004a0f40`/`0x004a0fc0`/`0x004a10e0`/`0x004a1250`/`0x004a1360`/`0x004a1390`, `DialogInSession` constructor/destructors at `0x004a1400`/`0x004a1450`/`0x004a14a0`, and `DialogSession` scalar deleting destructor at `0x004a1500`.
- 2026-06-14 live `xrefs_to` for all six table bases confirms the constructor/destructor store pattern: `DialogSession` bases `0x00618d30`, `0x00618d7c`, and `0x00618dac` are written by `0x004a0d80`, `0x004a0e70`, and `0x004a1500`; `DialogInSession` bases `0x00618db8`, `0x00618e18`, and `0x00618e48` are written by `0x004a1400`, `0x004a1450`, and `0x004a14a0`.
- 2026-06-14 live decompilation of `0x004a0d80` again shows base `Pane` construction with mode `4`, tracked-list allocation via `sub_4F3060(4, 16)` stored at `this + 0xf8`, active index byte `this + 0xfc = -1`, full-screen bounds setup, and renderer attachment. Live decompilation of `0x004a1400` again shows `DialogPane` base construction, `this[620]` (`+0x26c`) dialog type, dword index `156` (`+0x270`) session data, and all three vtable stores.
- 2026-06-17 B001 source-quality recheck names the DialogSession stack fields `m_dialogList` (`+0xf8`) and `m_activeDialogIndex` (`+0xfc`). Exact helper leaves should prefer `DialogInSession*` for tracked entries; active generated `RankingDialog*` spellings are caller/type pollution and should not drive final declarations.
- 2026-06-19 B014 BulletinDialog source-quality recheck confirms the board/article/mail constructor pattern: callers pass common `dialogPaneConfigId` value `2` to the `DialogPane` base path and pass distinct stored `dialogType` bytes separately. Do not treat the common `2` as the `+0x26c` dialog-type byte.
- 2026-06-20 B002 DialogSession source-quality recheck confirms the two previously missing helper pockets as additional field users: `0x004a11e0` updates `m_activeDialogIndex` while activating the next dialog, and `0x004a13b0` scans `m_dialogList` for a `DialogInSession *` and returns an index or `-1`. It also reinforces `List *` plus `DialogInSession *` payload as the best source-facing declaration direction.

## Score Rationale

- Completion is `91` because the page now records direct source bases, exact compiler-facet offsets, protected/public access, concrete field types, natural alignment, constructor widths, all six store sets, helper users, non-emitting source route, and compiler exclusions.
- Confidence is `94` because constructor/destructor stores, RTTI COL offsets, class consumers, exact vtable data, and current source declarations independently corroborate the layout. The remaining uncertainty is only the original custom List spelling.

## Reconstruction Notes

- Keep `DialogSession` and `DialogInSession` in one source module unless later historical source evidence proves a split.
- The four adjustor thunks at `0x004a146f`, `0x004a147a`, `0x004a1485`, and `0x004a1490` are ABI glue for these layouts, not handwritten methods.
- Active generated source uses feature names such as `RankingDialog` for generic session-dialog entries. Treat those as provisional; B001 2026-06-17 source-quality recheck favors `DialogInSession*` as the tracked-entry direction for the shared stack helpers.
- Keep this managed C++ block blank and `RECONSTRUCTABLE:FALSE`: complete declarations live on UID00003U/UID00003S, and duplicating layout source here would create a second class definition or Empty Emitter Marker.

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

- 2026-07-16 B004 UID0002NB accepted implementation callback:
  - Changed `85/90 -> 91/94`, `RECONSTRUCTABLE:TRUE -> FALSE`, and cleared emitter routing while retaining owner UID0000IU, blank position, and blank formal.
  - Added exact direct bases, inherited `+0xa0/+0xa4` facets, protected DialogSession fields, public DialogInSession fields, `unsigned short` config type, natural alignment, renamed UID0002NB route, and compiler-wrapper exclusions.
  - Preserved every constructor/destructor/helper/store/history fact and rejected generated RankingDialog typing and duplicate layout/class emission.
- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the session and in-session dialog constructors/destructors, tracked-list/index fields, session-dialog tail fields, and vtable stores. The page remains below `95+` because exact source-facing names for the stack/list helper methods and session tail fields are not final.
- 2026-06-06 parent attachment:
  - What existed before: the layout had strong IDA-backed offsets and was scored above `80/80`, but `AUTOGEN_PARENT_UID` was blank.
  - Changed to: attached to [UID:0000IU][DialogSession](by-file/DialogSession.md) without changing scores.
  - Summary/evidence: this page covers both `DialogSession` and `DialogInSession`, so file-level ownership is clearer than choosing one class; the file page is scored `84/80` and documents the same shared session-dialog infrastructure.
- 2026-06-14 A002 Goal2 score pass:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`, with stale parent score text and only older live-IDA evidence.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:90`, current owner/emitter wording, current parent/class scores, and live IDA function/xref/decompilation evidence.
  - Summary/evidence: IDA MCP session `a001_goal2_class_batch` reconfirmed the session stack fields at `+0xf8/+0xfc`, the in-session tail fields at `+0x26c/+0x270`, all six vtable store sets, and the current helper function bounds. Final C++ remains blank because final names and declarations are not source-quality.
- 2026-06-17 B001 DialogSession stack-index execution:
  - Score unchanged at `85/90`.
  - Clarified final field-name direction for `+0xf8/+0xfc` as `m_dialogList` and `m_activeDialogIndex`, and rejected feature-specific generated `RankingDialog*` typing for shared stack entries.
- 2026-06-19 B014 BulletinDialog constructor support sync:
  - Score unchanged.
  - Summary/evidence: clarified the `DialogInSession` constructor roles as `session`, `dialogPaneConfigId`, and `dialogType`, avoiding the stale reading that the shared board/article/mail constant `2` is the stored dialog-type byte.
- 2026-06-20 B002 Rule 26 incorporation:
  - Score unchanged.
  - Summary/evidence: added `ActivateNextDialog` and `FindDialogIndex` as additional `m_dialogList`/`m_activeDialogIndex` users and clarified that `m_dialogList` is best declared as `List *` with `DialogInSession *` payload slots, not a proven template list.
