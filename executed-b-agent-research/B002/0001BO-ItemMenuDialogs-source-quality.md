** TARGET-REPORT-UID:0001BO **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Source-Quality Report: [UID:0001BO] ItemMenuDialogs

Target: `source-3/project-documentation/by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0001BO-ItemMenuDialogs-source-quality.md`  
Report scope: B-agent source-quality / heuristic research only. No target/support by-* docs, generated files, prior reports, or `by-memory/-coverage-report.md` were edited.

## Final Recommendation

Treat [UID:0001BO] as a reviewed non-emitting split/index over the server/client item-menu executable family, not as one monolithic source-emitting C++ body.

The correct source unit remains [UID:0000KF] `ItemMenuDialogs` / `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`. Do not fold the range back into broader [UID:0000KE] `ItemDialogs`; `ItemDialogs` is useful context, but the item-menu vtables, factory subtype routes, row-list classes, opcode `0x39` reply helpers, and resource strings are tight enough to keep `ItemMenuDialogs.cpp` as the direct source file.

Recommended target metadata after the implementation callback creates or confirms the exact child pages:

```yaml
COMPLETION: 88
CONFIDENCE: 89
CANONICAL_OWNER: 0000KF
RECONSTRUCTABLE: FALSE
EMITTER_UIDS:
```

Final split direction:

- Create a source-bearing child for `ServerItemMenuDialog` methods at `0x0051a520-0x0051ae8d`, owned by [UID:0000CZ] `ServerItemMenuDialog`, emitted through [UID:0000KF] `ItemMenuDialogs`.
- Keep existing child [UID:0001BP] `ServerItemMenuItemList`, but correct its row layout and emitted C++. The current `actionId` first-field interpretation is wrong for the server row.
- Create a source-bearing child for `ClientItemMenuDialog` methods at `0x0051b880-0x0051c46d`, owned by [UID:00002P] `ClientItemMenuDialog`, emitted through [UID:0000KF] `ItemMenuDialogs`.
- Keep adjacent sibling [UID:0001BQ] `ClientItemMenuItemList` in the same file family and raise it to first-draft C++ readiness after applying the row-layout corrections below.

Do not emit formal C++ directly from [UID:0001BO]. It contains an already-source-bearing nested child (`0001BP`) and stops immediately before another required source-bearing sibling (`0001BQ`). A direct aggregate body would either duplicate child output or omit part of the real source file.

## Evidence Checked

Process and active guidance:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and direct support docs:

- [UID:0001BO] `by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md`
- [UID:0001BP] `by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md`
- [UID:0001BQ] `by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md`
- [UID:0000KF] `by-file/ItemMenuDialogs.md`
- [UID:0000KE] `by-file/ItemDialogs.md`
- [UID:0000CZ] `by-class/ServerItemMenuDialog.md`
- [UID:0000D0] `by-class/ServerItemMenuItemList.md`
- [UID:00002P] `by-class/ClientItemMenuDialog.md`
- [UID:00002Q] `by-class/ClientItemMenuItemList.md`
- [UID:00031Z] `by-type/by-vtable/ItemMenuDialogVtables.md`
- [UID:00025U] `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`
- [UID:000238] `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`
- [UID:0001C2] `by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md`
- Shared destructor/thunk pages near `0x00520abb-0x00520e2b`

Dependency docs checked for ownership boundaries:

- [UID:0000KT] `by-file/ListPane.md`
- [UID:0000M3] `by-file/ObjectImageControlPane.md`
- [UID:0001BU] `by-memory/0x00520540-0x00520816.ObjectImageControlPane.md`
- [UID:0000Q5] `by-global/g_packetSender.md`
- [UID:0000R9] `by-global/g_pItemHelpPane.md`
- [UID:0000NS] `by-file/Socket.md`
- [UID:0000JU] `by-file/HelpPanes.md`

Generated and coverage state checked:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/dialogs/ItemMenuDialogs.cpp`
- `by-memory/-coverage-report.md` rows for `0001BO`, `0001BP`, and `0001BQ`
- Prior B002 report `research/executed/0001BP-ServerItemMenuItemList-source-quality.md`

Raw binary evidence:

- PE scanned locally: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5 from local scan: `4247e04e20b65d6414c7238aa8ff5515`
- `.text` section: `0x00401000-0x0060c600`
- Boundary padding bytes confirmed around `0x0051a520`, `0x0051ae90`, `0x0051b880`, `0x0051c470`, and `0x0051ca40`.
- Fresh IDA MCP was not available for this pass (`http://127.0.0.1:13337/mcp` did not accept the tool-list connection), so no IDA labels/types were changed. This report uses existing IDA-backed docs plus a local PE byte/disassembly recheck.

Numeric conversions verified with `tools/int_convert.py`:

- `0x278` = 632 bytes, dialog allocation size.
- `0x408` = 1032 bytes, server row stride.
- `0x206` = 518 bytes, client row stride.
- `0x15c` = 348 bytes, row-list object allocation size.
- `0xe4` = 228 and `0x18` = 24, client list dimension arguments.
- `0x208` = 520, server row description offset.
- `0x39` = 57, reply opcode.
- `0x10` = 16, common list x-origin argument.

## Inventory And Split Boundaries

The target range is real project code, but it is not one source-level body.

| Range | Source-facing entity | Split decision |
| --- | --- | --- |
| `0x0051a520-0x0051ac8e` | `ServerItemMenuDialog::InitializeFromPacket` or constructor initializer | New exact child should carry source C++. |
| `0x0051acb0-0x0051ae42` | `ServerItemMenuDialog::OnDialogAction` | Same server-dialog child. |
| `0x0051ae50-0x0051ae8d` | `ServerItemMenuDialog::UpdateActionAvailability` | Same server-dialog child. |
| `0x0051ae8d-0x0051ae90` | alignment padding | No source. |
| `0x0051ae90-0x0051b87a` | [UID:0001BP] `ServerItemMenuItemList` | Existing source-bearing child; needs row-layout correction. |
| `0x0051b87a-0x0051b880` | alignment padding | No source. |
| `0x0051b880-0x0051c309` | `ClientItemMenuDialog::ClientItemMenuDialog` | New exact child should carry source C++. |
| `0x0051c310-0x0051c421` | `ClientItemMenuDialog::HandleMenuCommand` | Same client-dialog child. |
| `0x0051c430-0x0051c46d` | `ClientItemMenuDialog::UpdateActionButtonState` | Same client-dialog child. |
| `0x0051c46d-0x0051c470` | alignment padding | No source. |
| `0x0051c470-0x0051ca3c` | [UID:0001BQ] `ClientItemMenuItemList` | Adjacent sibling, outside `0001BO`, but same source file family and required for first-draft C++ completeness. |

The aggregate's current span deliberately skips the client row-list sibling. That is the main proof against aggregate C++ emission: the physical range is a historical inventory slice, not an exact file or exact class.

## Source Placement And Ownership

Recommended routing:

- Source file owner: [UID:0000KF] `ItemMenuDialogs`, path `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`.
- Direct class owners for future method children:
  - [UID:0000CZ] `ServerItemMenuDialog`
  - [UID:0000D0] `ServerItemMenuItemList`
  - [UID:00002P] `ClientItemMenuDialog`
  - [UID:00002Q] `ClientItemMenuItemList`
- Vtable ownership: [UID:00031Z] `ItemMenuDialogVtables` for item-menu-specific vtable evidence; [UID:00025U] remains the broader mixed `.rdata` aggregate. The current target text should prefer the dedicated item-menu vtable page when naming the direct vtable-family anchor.
- Factory ownership stays with [UID:000238] `MenuDialogFactoryHelpers`; factory subtype routing is evidence for item-menu ownership, not a reason to move factory code into `ItemMenuDialogs.cpp`.
- `ListPane`, `ObjectImageControlPane`, `g_packetSender`, and `g_pItemHelpPane` remain external dependencies. Do not move those helpers/globals into item-menu docs or generated C++.

Rejected alternatives:

- Fold into `ItemDialogs.cpp`: rejected. The item-menu classes have dedicated source-file, vtable, factory subtype, and row-list evidence. `ItemDialogs` is broader item UI context, not the narrow direct owner.
- Emit C++ from `0001BO`: rejected. The range contains a nested source-bearing child and excludes the adjacent client list sibling, so aggregate emission would be structurally wrong.
- Assign raw `ListPane` helper ownership to item-menu classes: rejected. Shared helpers such as `0x004f3a50`, `0x004f3c50`, `0x004f3dc0`, and `0x004f3e20` remain `ListPane`/shared-control code.

## Factory, Vtable, And Dependency Evidence

Factory subtype routes:

- Subtype `4` constructs `ServerItemMenuDialog` from factory callers at `0x0051762b` and `0x00517a5d`, with dialog allocation size `0x278` (632) and payload at `packet + 2`.
- Subtype `5` constructs `ClientItemMenuDialog` from factory callers at `0x00517677` and `0x00517ae7`, also with allocation size `0x278` (632) and payload at `packet + 2`.

Vtable evidence:

- `ServerItemMenuDialog`: primary/adjusted tables at `0x0061eea8`, `0x0061ef08`, and `0x0061ef38`; action/update slots point to `0x0051acb0` and `0x0051ae50`.
- `ServerItemMenuItemList`: tables at `0x0061ef44`, `0x0061efcc`, and `0x0061effc`; destructor/selection/activation/draw slots route to the server list range and scalar destructor glue at `0x00520ce0`.
- `ClientItemMenuDialog`: tables at `0x0061f008`, `0x0061f068`, and `0x0061f098`; action/update slots point to `0x0051c310` and `0x0051c430`.
- `ClientItemMenuItemList`: tables at `0x0061f0a4`, `0x0061f12c`, and `0x0061f15c`; constructor refs come only from `ClientItemMenuDialog` at `0x0051ba35` and `0x0051bf64`.

Resource/control dependencies:

- `DLGMERC3.EPF` at `0x0061f904` is used by the server item menu and argumented item menu family.
- `DLGMERC1.EPF` / `DLGMERC1.EPD` are the current/legacy client item-menu resource family according to the read-only-data string audit. Use source names such as `DLGMERC1_EPF` and `DLGMERC1_EPD` only when writing source-style constants; do not invent palette globals.
- `ObjectImageControlPane` construction routes through `0x00520540`; keep it owned by [UID:0000M3].
- `g_packetSender` at `0x0067a7ec` owns the packet send singleton; item-menu methods only consume it.
- `g_pItemHelpPane` at `0x0069ae04` owns the active item-help pane singleton used by server list destructor/event paths.

## Row Record Layout Corrections

The most important source-quality correction from this pass is the server row layout. The older B002 `0001BP` report and current generated C++ place `actionId` at server row offset `+0x000`. Fresh raw-disassembly evidence rejects that.

Server row append at `0x0051af40` writes:

- `word [row + 0x000]` from first argument.
- `byte [row + 0x002]` from second argument.
- `dword [row + 0x004]` from third argument.
- `wchar_t name[256]` at `row + 0x008`.
- `wchar_t description[256]` at `row + 0x208`.

Server row draw at `0x0051b3e0` reads:

- `word [row + 0x000]` as item id.
- `byte [row + 0x002]` as item style.
- `dword [row + 0x004]` as value, formatted with the `%10u` literal.
- `row + 0x008` as display name.
- Selection/help paths use `row + 0x208` as description text.

Correct server row source shape:

```cpp
struct ServerItemMenuEntry
{
    unsigned short itemId;       // +0x000
    unsigned char itemStyle;     // +0x002
    unsigned char reserved;      // +0x003, copied padding/unused in observed code
    unsigned int value;          // +0x004
    wchar_t name[256];           // +0x008
    wchar_t description[256];    // +0x208
};                               // sizeof == 0x408
```

The server list does not need a row `actionId`. Server action dispatch serializes selected row text, not a row action byte.

Client row append at `0x0051c4e0` writes:

- `byte [row + 0x000]` from action id argument.
- `word [row + 0x002]` from item id argument.
- `byte [row + 0x004]` from item style argument.
- `wchar_t name[256]` at `row + 0x006`.

Client row draw at `0x0051c6c0` reads:

- `byte [row + 0x000]` as action id for packet dispatch.
- `word [row + 0x002]` as item id.
- `byte [row + 0x004]` as item style.
- `row + 0x006` as display name.

Correct client row source shape:

```cpp
struct ClientItemMenuEntry
{
    unsigned char actionId;      // +0x000
    unsigned char reserved;      // +0x001, copied padding/unused in observed code
    unsigned short itemId;       // +0x002
    unsigned char itemStyle;     // +0x004
    unsigned char reserved2;     // +0x005, copied padding/unused in observed code
    wchar_t name[256];           // +0x006
};                               // sizeof == 0x206
```

Use `reserved` names for padding until a packet field or source name proves a semantic byte. Do not promote those bytes to flags in first-draft C++.

## Source-Facing Names And Signatures

Recommended class/field names:

- `ServerItemMenuDialog`
- `ServerItemMenuItemList`
- `ServerItemMenuEntry`
- `ClientItemMenuDialog`
- `ClientItemMenuItemList`
- `ClientItemMenuEntry`
- list fields: `m_packetSubtype` (`+0x14c`), `m_menuObjectId` (`+0x150`), `m_menuOptionId` (`+0x154`), `m_owner` (`+0x158`)
- global dependency names: `g_packetSender`, `g_pItemHelpPane`, `g_useEpfAssets`

Recommended method/helper names:

- `ServerItemMenuDialog::InitializeFromPacket` or `ServerItemMenuDialog::ServerItemMenuDialog` if the implementation callback proves the constructor signature from the factory wrapper.
- `ServerItemMenuDialog::OnDialogAction(int actionId)`
- `ServerItemMenuDialog::UpdateActionAvailability()`
- `ServerItemMenuItemList::ServerItemMenuItemList(unsigned char packetSubtype, unsigned int menuObjectId, unsigned short menuOptionId, ServerItemMenuDialog* owner)`
- `ServerItemMenuItemList::AppendItem(unsigned short itemId, unsigned char itemStyle, unsigned int value, const wchar_t* name, const wchar_t* description)`
- `ServerItemMenuItemList::SendSelectedItemName()`
- `ServerItemMenuItemList::SendItemName(const wchar_t* name)`
- `ServerItemMenuItemList::OnSelectionChanged()`
- `ServerItemMenuItemList::NotifyOwnerItemActivated()`
- `ServerItemMenuItemList::UpdateItemHelpFromMouse(...)`
- `ServerItemMenuItemList::DrawItem(...)`
- `ClientItemMenuDialog::ClientItemMenuDialog(...)`
- `ClientItemMenuDialog::HandleMenuCommand(int actionId)`
- `ClientItemMenuDialog::UpdateActionButtonState()`
- `ClientItemMenuItemList::ClientItemMenuItemList(unsigned char packetSubtype, unsigned int menuObjectId, unsigned short menuOptionId, ClientItemMenuDialog* owner)`
- `ClientItemMenuItemList::AppendAction(unsigned char actionId, unsigned short itemId, unsigned char itemStyle, const wchar_t* name)`
- `ClientItemMenuItemList::SendSelectedAction()`
- `ClientItemMenuItemList::SendAction(unsigned char actionId)`
- `ClientItemMenuItemList::NotifyOwnerItemActivated()`
- `ClientItemMenuItemList::DrawItem(...)`

Do not preserve raw names such as `sub_0051af40`, `sub_0051afd0`, `sub_0051c4e0`, or `sub_0051c550` in final source-facing docs except as historical address evidence.

## Packet And Action Semantics

Both server and client item-menu families send opcode `0x39` (decimal 57), but their payload semantics differ:

- Server selected/caller-supplied paths serialize `m_packetSubtype`, `m_menuObjectId`, `m_menuOptionId`, and a multibyte string converted from the selected/caller-supplied wide text. The selected row string comes from `ServerItemMenuEntry::name`.
- Client selected/explicit paths serialize `m_packetSubtype`, `m_menuObjectId`, `m_menuOptionId`, selected/explicit `ClientItemMenuEntry::actionId`, and a trailing null byte; observed payload length is 9 bytes before the send helper.

Dialog action/update behavior:

- Dialog action `1` submits the selected row/action and closes the dialog.
- Dialog action `2` forwards to the shared menu-dialog action/string helper at `0x00517ec0`.
- Dialog action `3` closes the dialog.
- `UpdateActionAvailability` / `UpdateActionButtonState` fetch control id `1` for the action button and control id `6` for the row-list host, call the `ListPane` selection-count helper (`0x004f3e20`), then dispatch enable/disable through control virtual slots `+0x4c` or `+0x50`.
- Server selection changes update owner text control id `7` with `ServerItemMenuEntry::description`, or the empty wide string at `0x0060db20` when no row is selected.

Button/control notes:

- The dialog constructors create three button controls with raw skin/control ids `0x0e`, `0x10`, and `0x0f`. Keep these as construction constants until the button class docs provide exact command enum names.
- The source-facing command ids observed in action handlers are `1`, `2`, and `3`; do not conflate these with the raw button construction constants.

## Compiler-Generated And Raw-Helper Handling

Compiler-generated/no-source items:

- Vtables in `0x0061eea8-0x0061f15c` are compiler output. Source declarations/classes regenerate them; do not copy vtable bytes into C++.
- Scalar deleting/destructor thunks around `0x00520abb-0x00520e2b` are compiler glue. Ordinary list destructor behavior belongs with `ServerItemMenuItemList` / `ClientItemMenuItemList`; deleting wrappers should remain no-code or comment-only ABI markers.
- Padding gaps `0x0051ae8d-0x0051ae90`, `0x0051b87a-0x0051b880`, and `0x0051c46d-0x0051c470` are alignment only.

Raw-helper conclusions:

- The server out-of-line list constructor at `0x0051ae90` has no direct rel32 caller because `ServerItemMenuDialog` inline-constructs the list. It still represents source-authored constructor logic and should remain in the `ServerItemMenuItemList` child, not be ignored.
- Server raw helpers `0x0051af40`, `0x0051afd0`, and `0x0051b190` are source-authored list helpers. They should receive source-facing helper names as above, not remain passive `sub_` blockers.
- Client raw helpers `0x0051c4e0`, `0x0051c550`, and `0x0051c610` are source-authored list helpers. They should receive source-facing helper names as above, not remain passive `sub_` blockers.
- Shared `ListPane` helpers are dependencies, not item-menu-owned helpers.

## First-Draft C++ Readiness

[UID:0001BO] itself should not emit C++. The exact no-code proof is:

1. The target crosses multiple classes.
2. It contains existing source-bearing child [UID:0001BP].
3. It ends before adjacent source-bearing sibling [UID:0001BQ].
4. Direct C++ would duplicate [UID:0001BP] and still omit the client list needed for a complete `ItemMenuDialogs.cpp`.
5. Vtables/destructor wrappers are compiler-generated and should be regenerated from class declarations, not handwritten in the aggregate.

Recommended target formal C++ after split:

```cpp
// Non-emitting split index for ItemMenuDialogs executable methods; exact child pages carry source C++.
```

Use that comment only if the validator/generated pipeline needs a non-empty marker for a reviewed non-emitting page. Otherwise keep target C++ blank with `RECONSTRUCTABLE:FALSE`.

First-draft source fragments for child/support docs:

```cpp
struct ServerItemMenuEntry
{
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned char reserved;
    unsigned int value;
    wchar_t name[256];
    wchar_t description[256];
};

struct ClientItemMenuEntry
{
    unsigned char actionId;
    unsigned char reserved;
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned char reserved2;
    wchar_t name[256];
};
```

```cpp
void ServerItemMenuItemList::AppendItem(unsigned short itemId,
                                        unsigned char itemStyle,
                                        unsigned int value,
                                        const wchar_t* name,
                                        const wchar_t* description);

bool ServerItemMenuItemList::SendSelectedItemName();
bool ServerItemMenuItemList::SendItemName(const wchar_t* name);
```

```cpp
void ClientItemMenuItemList::AppendAction(unsigned char actionId,
                                          unsigned short itemId,
                                          unsigned char itemStyle,
                                          const wchar_t* name);

bool ClientItemMenuItemList::SendSelectedAction();
bool ClientItemMenuItemList::SendAction(unsigned char actionId);
```

Dialog method children are also first-draft ready once split pages exist. Their C++ should be source-style reconstruction, not raw decompiler output:

- Server constructor/initializer parses object-image descriptor from `packet + 6`, converts title/action strings, inline-constructs `ServerItemMenuItemList`, appends server entries with item id/style/value/name/description, builds `DLGMERC3.EPF` controls, and initializes list/action state.
- Server action handler switches on action `1/2/3`, submits selected row name through opcode `0x39`, forwards shared action `2`, and closes on action `1` or `3`.
- Client constructor parses object-image descriptor and local client action rows, looks up client item data through the collection-data helper, appends `ClientItemMenuEntry` rows, and builds current/legacy `DLGMERC1` layout controls.
- Client action handler switches on action `1/2/3`, submits selected `actionId` through opcode `0x39`, forwards shared action `2`, and closes on action `1` or `3`.

## Recommended Exact Doc Changes

Target [UID:0001BO]:

- Change disposition from reconstructable aggregate to non-emitting split/index after exact children are created.
- Update score to `88/89`.
- Change `RECONSTRUCTABLE` to `FALSE` and blank `EMITTER_UIDS`.
- Update vtable anchor to include/prefer [UID:00031Z] `ItemMenuDialogVtables`.
- Replace remaining "source split open" wording with the concrete split listed above.
- Add the row-layout correction summary so future implementers do not use the older server `actionId` layout.
- Keep [UID:0000KF] as source-file family context.

[UID:0001BP] `ServerItemMenuItemList`:

- Replace the current `ServerItemMenuEntry` field order with `itemId`, `itemStyle`, reserved padding, `value`, `name`, `description`.
- Remove server row `actionId`.
- Change `AppendItem` signature to accept `unsigned short itemId, unsigned char itemStyle, unsigned int value, const wchar_t* name, const wchar_t* description`.
- Update draw/packet narrative: server selected action sends row name/string, not row action byte.
- Keep score at `88/89` or use `89/90` only if the implementation callback also source-checks the help-pane mouse handler.

[UID:0001BQ] `ClientItemMenuItemList`:

- Raise to at least `88/89` after adding the client row layout and first-draft C++.
- Add row struct with `actionId` at `+0x000`, `itemId` at `+0x002`, `itemStyle` at `+0x004`, and `name[256]` at `+0x006`.
- Name helpers `AppendAction`, `SendSelectedAction`, and `SendAction`.
- Exclude shared destructor thunks and shared `ListPane` helpers from ownership.

Class/file support pages:

- [UID:0000CZ] and [UID:00002P]: update class notes to say method C++ is ready through exact child method pages, not the broad aggregate.
- [UID:0000D0] and [UID:00002Q]: update row layout and helper names to match this report.
- [UID:0000KF] `ItemMenuDialogs`: update contents to list the two dialog method children plus server/client list pages; keep `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`.
- [UID:0000KE] `ItemDialogs`: leave as broader context only.
- [UID:000238] `MenuDialogFactoryHelpers`: optionally add a cross-reference note that subtype `4` and subtype `5` route into `ItemMenuDialogs`, but do not change ownership.
- [UID:00025U] read-only-data aggregate: no ownership change; optional cross-reference to dedicated [UID:00031Z] item-menu vtables if missing.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` in this report-only task. If the supervisor accepts the split/index recommendation, replace the existing `0001BO`, `0001BP`, and `0001BQ` rows with the following text.

```text
    - [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) 0x0051a520-0x0051c46d | split-index | ItemMenuDialogs executable split index : ignored/non-emitting : 88% : very-strong : B002 2026-06-19 source-quality pass reclassifies the aggregate as a non-emitting split index over ServerItemMenuDialog methods, existing ServerItemMenuItemList child [UID:0001BP], ClientItemMenuDialog methods, and the adjacent ClientItemMenuItemList sibling [UID:0001BQ]. Raw PE recheck verifies factory subtype 4/5 routes, vtable families, opcode `0x39` server-string/client-action semantics, control ids 1/6/7, object-image/ListPane/packet/help-pane dependencies, padding boundaries, and exact row-layout corrections; source C++ should be emitted by exact child pages under [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), not by this aggregate.
    - [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) 0x0051ae90-0x0051b87a | class-method/raw-helper cluster | ServerItemMenuItemList : reconstructable : 88% : strong : Server item-menu private ListPane row class under ItemMenuDialogs; B002 2026-06-19 aggregate source-quality pass corrects the `0x408` row layout to `itemId` at `+0x000`, `itemStyle` at `+0x002`, `value` at `+0x004`, `name[256]` at `+0x008`, and `description[256]` at `+0x208` after raw append/draw recheck, rejects the older server-row `actionId` first-field interpretation, keeps context fields `+0x14c/+0x150/+0x154/+0x158`, opcode `0x39` selected/explicit string packet helpers, owner description control id `7` update, activation thunk, help-pane singleton dependency, current/legacy row draw paths, and first-draft C++ readiness; raw helper starts remain non-IDA-functions/no-direct-xref caveat.
    - [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) 0x0051c470-0x0051ca3c | class-method/raw-helper cluster | ClientItemMenuItemList : reconstructable : 88% : strong : B002 2026-06-19 source-quality pass raw-disassembled constructor/raw append/packet helpers/draw, proves the `0x206` row layout with `actionId` at `+0x000`, `itemId` at `+0x002`, `itemStyle` at `+0x004`, and `name[256]` at `+0x006`, resolves opcode `0x39` selected/explicit action packet helpers, context fields `+0x14c/+0x150/+0x154/+0x158`, activation thunk to owner item-state logic, current/legacy draw paths, factory/caller coupling from ClientItemMenuDialog, shared destructor glue exclusion, and first-draft C++ readiness; raw helper starts remain non-IDA-functions/no-direct-xref caveat.
```

If new child method pages are created for `ServerItemMenuDialog` and `ClientItemMenuDialog`, add new coverage rows with validator-assigned UIDs immediately before/around the existing `0001BP` / `0001BQ` rows. UIDs are not knowable until validator creation, so exact UID-bearing rows cannot be supplied in this report.

## Validator / Autogen Needs

After an implementation callback, run file-mode validator on each edited or newly created by-* file, then run autogen once. Suggested command order:

> Executable block R001 was removed from this report and preserved verbatim in [0001BO-ItemMenuDialogs-source-quality-removed.md](0001BO-ItemMenuDialogs-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation callback creates new child pages, run `--mode file --file <new-page>` for each new page before validating the aggregate and class pages.

## Remaining Open Questions

These are not blockers for the split/index decision or first-draft child C++:

- Exact original source spelling for constructor parameter names remains unknown. Use `packetSubtype`, `menuObjectId`, `menuOptionId`, and `owner` because they match packet serialization and list ownership.
- Exact original spelling of row helper names remains unknown. Use the source-facing names recommended above instead of raw `sub_` names.
- The server row padding byte at `+0x003` and client padding bytes at `+0x001/+0x005` are copied as part of the row stride but have no proven semantic reads. Keep them as reserved padding.
- Client current/legacy resource constants should use `DLGMERC1.EPF` / `DLGMERC1.EPD` only where the read-only-data string page supports them. Avoid inventing palette/helper globals.
- Server item-help mouse handler details are enough for ownership and first-draft structure, but should be rechecked if the supervisor asks for high-90s C++ polish.

## Implementation Readiness

Ready for implementation callback as a split/index repair plus support-doc C++ updates.

Do not emit aggregate C++ for [UID:0001BO]. The implementation-ready work is:

1. Create exact dialog method children, or at minimum convert `0001BO` to a non-emitting split index only after those children exist.
2. Correct [UID:0001BP] server row layout and generated C++.
3. Fill [UID:0001BQ] client row-list first-draft C++.
4. Update class/file support docs to route the family through [UID:0000KF] `ItemMenuDialogs`.
5. Apply the coverage rows above manually only after the docs are updated and validator/autogen has run.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001BO-ItemMenuDialogs-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001BO"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001BO-ItemMenuDialogs-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001BO-ItemMenuDialogs-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001BO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
