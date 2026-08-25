*** UID:0000FN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/BlackHole.h"

template <class T> class Singleton;
class DialogPane;
class Event;
class List;
class PartySearchEditPane;
class UserListDialogPane;
class UserListPane;
class WideString;

extern UserListDialogPane *g_pUserListDialogPane;
void GetLocalPlayerNameString(WideString &outName);

#pragma pack(push, 1)
struct UserListRecord
{
    unsigned char careerId;
    unsigned char bucketIndex;
    unsigned char reserved2;
    unsigned char badgeIconId;
    unsigned char displayColor;
    unsigned char reserved5[3];
    long arrivalSortKey;
    unsigned char statusIconId;
    unsigned char reservedD;
    wchar_t name[256];
    unsigned char huntersListFlag;
    unsigned char hasSourceText;
    wchar_t sourceText[256];
    unsigned char careerVariant;
    unsigned char reserved411[3];
};
#pragma pack(pop)

int __cdecl CompareUserListRecordsByStatus(const UserListRecord *left,
                                           const UserListRecord *right);
int __cdecl CompareUserListRecordsByName(const UserListRecord *left,
                                         const UserListRecord *right);

class UserListDialogPane : public Singleton<UserListDialogPane>, public DialogPane
{
public:
    enum UserListMessage
    {
        kUserListHuntersListStateUpdate = 0x83,
        kUserListSourceTextUpdate = 0x84
    };

    enum UserListControlIndex
    {
        kHuntersListParticipationControl = 0x14
    };

    explicit UserListDialogPane(const unsigned char *packet);
    virtual ~UserListDialogPane();

    void SortListsByStatus();
    void SortListsByName();
    void RefreshCategoryView(char step);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);

    void AddUserListSourceMessage(const UserListRecord *record);

private:
    friend class PartySearchEditPane;
    short m_selectedNationId;
    short m_categoryPage;
    short m_selectedCareerVariant;
    UserListPane *m_bucketPanes[5];
    List *m_allUserRecords;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserListDialogPane

## Status

- Confidence: very strong for class purpose, source-file parentage, method boundaries, local child-class ownership, packed record layout, packet-field roles, helper names, the hunters-list-only flag semantics, and the complete signed-char category-refresh source; exact original private spellings remain the bounded cap.
- Likely source file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Address range: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- Read-only data: [UID:00026U][0x0062e8fc-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md)
- Parent gate: attached to [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md); both pages now meet the strict `85/85` attachment threshold.

## Class Purpose

`UserListDialogPane` is the main users dialog. It builds high-resolution or low-resolution dialog layouts, parses the initial user-list packet into fixed-size user records, distributes users into five visible list panes, sorts by status/rank or by name, filters by category/career and hunters-list status, handles selected-user/source-text packet updates, and dispatches UI commands.

## Class Shape

- Source family: social user-list feature source under [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md), not generic dialog/list infrastructure.
- Owned local collaborators: [UID:0000FO][UserListPane](by-class/UserListPane.md) repeated list panes, [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) command-20 subdialog, and the local `AddUserListSourceMessage` helper at `0x0059de60`.
- Bounded cross-class access: `PartySearchEditPane` alone is a friend so its submit method can scan private `m_allUserRecords` for the local packed row. This does not expose the list publicly, change the `0x28c` layout, or add UserPane friendship.
- Reused controls: consumes `CheckBoxTextControlPane`, list, radio, scroll, text-edit, and dialog-pane controls, but those reusable controls keep their own source families.
- Runtime state: active dialog singleton at [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), hunters-list-only flag at [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md) / [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md), active category-nation initialization through [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md), and separate legacy constructor context through [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md).

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0059bc90-0x0059d198` | Constructs high/low-res dialog controls, creates five `UserListPane` children, parses user rows, populates buckets, and initializes labels/counts. |
| `SortListsByStatus` | `0x0059d1f0-0x0059d24f` | Sorts all five category list panes through comparator `0x0059e950`, which compares record `+0x00c` status/rank first and `+0x008` arrival sort key as the tie-breaker. |
| `SortListsByName` | `0x0059d250-0x0059d2af` | Sorts all five category list panes through comparator `0x0059e990`, which compares wide user names at record `+0x00e`. |
| `RefreshCategoryView` | `0x0059d2b0-0x0059d5fe` | Source-ready `void RefreshCategoryView(char step)`: clamps six pages, resolves the active nation/GameServerConfig category entry, clears and rebuilds five buckets with hunters/career filtering, independently sorts by status or name, updates duplicate-read pane counts and signed-short total, preserves exact EPF/legacy label behavior, and invalidates the dialog. |
| `HandlePacketEvent(Event *)` | `0x0059d620-0x0059d8f5` | EventHandler secondary slot `+0x10`; exact 0x83 hunters-state and 0x84 source-text packet handling, always returns false. |
| `HandleKeyOrTextEvent(Event *)` | `0x0059d900-0x0059da82` | Source-ready EventHandler secondary slot `+0x08`: translates the key before testing it, handles only unmodified key-down Page Up/Page Down with signed category steps and `true`, forwards failed page-key gates immediately to `DialogPane`, scans all five bucket panes for Ctrl+C selected-name publication with last selected pane winning, returns `false` for recognized Ctrl+C, and base-forwards every other event. |
| `AddUserListSourceMessage` | `0x0059de60-0x0059decf` | Nonstatic member proved by both ECX-seeded callers and `retn 4`; formats the cached source line. |
| `OnControlCommand` | `0x0059da90-0x0059dbe3` | Handles close, sort-mode change, category step, party-search dialog open, and hunters-list-only toggle. |
| PartySearch local class | `0x0059e0d0-0x0059e707` | Zero-member `DialogPane` derivative with complete constructor, empty `OnPaint`, and two-argument `OnControlCommand`; it uses the friendship only for `m_allUserRecords` during local-row mirror/send. |
| adjustor thunks | `0x0059f017-0x0059f02d` | User-list dialog destructor adjustors. |
| scalar deleting destructor | `0x0059f110-0x0059f181` | Destroys owned scroll/list state, tears down base dialog, clears singleton, and optionally deletes. |

## Exact Child Pages

B002 split implementation moved exact executable coverage out of the broad parent [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) and into child pages:

- [UID:000470][0x0059bc90-0x0059d198.UserListDialogPaneConstructor](by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md) carries the complete constructor body through [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md). [UID:000475][0x0059d2b0-0x0059d5fe.UserListDialogPaneRefreshCategoryView](by-memory/0x0059d2b0-0x0059d5fe.UserListDialogPaneRefreshCategoryView.md) emits the complete signed-char category-refresh body. [UID:000477][0x0059d620-0x0059d8f5.UserListDialogPaneHandlePacketEvent](by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandlePacketEvent.md) emits exact R1; [UID:000478][0x0059d900-0x0059da82.UserListDialogPaneHandleKeyOrTextEvent](by-memory/0x0059d900-0x0059da82.UserListDialogPaneHandleKeyOrTextEvent.md) now emits the complete mutable-Event key/text body with exact page-navigation, selected-name clipboard, return, and base-forwarding behavior.
- [UID:000473][0x0059d1f0-0x0059d24f.UserListDialogPaneSortListsByStatus](by-memory/0x0059d1f0-0x0059d24f.UserListDialogPaneSortListsByStatus.md), [UID:000474][0x0059d250-0x0059d2af.UserListDialogPaneSortListsByName](by-memory/0x0059d250-0x0059d2af.UserListDialogPaneSortListsByName.md), and [UID:000479][0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand](by-memory/0x0059da90-0x0059dbe3.UserListDialogPaneOnControlCommand.md) carry exact formal C++ through [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md).
- [UID:000471][0x0059d198-0x0059d1e0.UserListDialogPaneConstructorCleanupTail](by-memory/0x0059d198-0x0059d1e0.UserListDialogPaneConstructorCleanupTail.md), [UID:000472][0x0059d1e0-0x0059d1e3.UserListDialogPaneNullsub61](by-memory/0x0059d1e0-0x0059d1e3.UserListDialogPaneNullsub61.md), [UID:000476][0x0059d5fe-0x0059d620.UserListDialogPaneRefreshCategorySwitchTable](by-memory/0x0059d5fe-0x0059d620.UserListDialogPaneRefreshCategorySwitchTable.md), [UID:00047A][0x0059dbe3-0x0059dc20.UserListDialogPaneOnControlCommandSwitchTable](by-memory/0x0059dbe3-0x0059dc20.UserListDialogPaneOnControlCommandSwitchTable.md), [UID:00047T][0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks](by-memory/0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks.md), and [UID:00047V][0x0059f110-0x0059f181.UserListDialogPaneScalarDeletingDestructor](by-memory/0x0059f110-0x0059f181.UserListDialogPaneScalarDeletingDestructor.md) are compiler/no-op/table artifacts with blank formal C++.
- [UID:00047B][0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw](by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md) remains a no-owner raw helper: the route checks to its start were negative, so it is not promoted to a `UserListDialogPane` public API. B004's current MCP pass confirms it is `__thiscall`-shaped on `UserListDialogPane *this` and scans `this+0x288`, but its local-player state comes from canonical `g_pUserPane+0x3cb1/+0x3cb2`; no IDA function object, start xref, pointer-pattern route, or generated emitter exists for the helper.

## Related Local Classes

- [UID:0000FO][UserListPane](by-class/UserListPane.md) implements the repeated list control used by this dialog.
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md) is opened by `OnControlCommand(20)`.
- [UID:00047C][0x0059de60-0x0059decf.UserListDialogPaneAddUserListSourceMessage](by-memory/0x0059de60-0x0059decf.UserListDialogPaneAddUserListSourceMessage.md) is a dialog member called by packet and double-click/source display paths, not a free helper.

## EventHandler And Member-ABI Corrections

- Secondary vtable `0x0062e960` places `HandleKeyOrTextEvent(Event *)` at `+0x08` and `HandlePacketEvent(Event *)` at `+0x10` (`0x0062e970`). The old `OnKeyEvent(KeyEvent *)` and `HandleUserListPacket(PacketEventContext *)` declarations are historical descriptive aliases, not current source interfaces.
- UID000478 receives an adjusted EventHandler receiver at complete-object `+0xa0`, returns bool in AL, and ends with `retn 4`; human source remains the ordinary complete-object virtual and does not spell the compiler's `this-0xa0` adjustment, EH scaffolding, cookie checks, or vtable machinery.
- The key is translated through `EventMan::TranslateEventKey(event)` before any gate. Internal page-key bytes `0x93` and `0x94` are accepted only for key-down type `8` with zero modifiers; Page Up calls `RefreshCategoryView(-1)`, Page Down calls `RefreshCategoryView(+1)`, and both return `true`. A failed page-key type/modifier gate immediately forwards to `DialogPane::HandleKeyOrTextEvent(event)`.
- Ctrl+C tests translated `'c'` plus control bit `0x02`, has no Event-type gate, permits additional modifier bits, and scans all five `m_bucketPanes` without breaking. Each selected pane uses its nonnegative selected index and indexed record accessor, copies packed `UserListRecord::name` through a cleared `TextEditScrap`, and invokes the TextEditPane clipboard publisher. Multiple selected panes therefore publish repeatedly and the last selected pane wins; recognized Ctrl+C always returns `false` and never base-forwards.
- The source-facing helper dependencies are `UserListPane::GetSelectedIndex`, inline `UserListPane::GetSelectedRecord`, `TextEditScrap::Clear`, `TextEditScrap::SetText`, and standalone [UID:0004T8][0x005917d0-0x00591a1c.PutScrapToClipboard](by-memory/0x005917d0-0x00591a1c.PutScrapToClipboard.md). The registered publisher and its exact `void PutScrapToClipboard(TextEditScrap *scrap)` prototype belong to the TextEditPane source family; that free-helper dependency does not alter this class declaration or its `0x28c` layout.
- UID000477 receives an adjusted EventHandler receiver at complete-object `+0xa0`; its adjusted `+0x1e8` master list is complete-object `+0x288`. The exact class remains `0x28c` with Singleton EBO and natural member layout.
- UID00047C is declared as a member even though its optimized body does not read `this`: both known callers load a dialog receiver into ECX and the body returns with `retn 4`. UID00047N belongs to `UserListPane`, so no free Sync/Add declarations remain here.
- The two inferred protocol enum labels and child-control label are source-facing descriptive names. Their widths, values `0x83`, `0x84`, and `0x14`, branch roles, and access are binary-exact; original private spellings remain the confidence cap.
- [UID:0003E6][0x0062e8fc-0x0062e998.UserListDialogPaneVtableData](by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md) is compiler-generated/non-emitting. This class inheritance and virtual surface are its source cause; no raw vtable, RTTI, COL, adjustor, EH, or cookie code is handwritten.

## PartySearchEditPane Access And Protocol Union

- User-list control `0x14` is the sole construction route for the zero-data-member PartySearch dialog. Its constructor uses current public UserPane accessors for the hunters-list flag and 256-wide source text; `g_pUserListDialogPane` is caller/active-list context rather than storage owner for those settings.
- PartySearch submit control `1` reads child controls, closes, validates and sanitizes text, persists typed UserPane state, and then uses this class's private `m_allUserRecords` only when the active singleton exists. The accepted friendship is the minimal compile-legal expression of that direct private access.
- The scan compares packed `UserListRecord::name` against the local player and preserves the binary's no-null-guard invariant after the scan. It updates `huntersListFlag`, clears `hasSourceText`, and copies `sourceText[256]` only when the row differs from UserPane state.
- Outbound opcode `0x84` is a value-first PacketBuffer byte write followed by the hunters-list flag. Only flag value `1` adds a narrowed one-byte MBCS length and that many text bytes; Socket sends size 2 or `encodedLength+3`. No NUL is protocol payload.
- PartySearch control `2` toggles and invalidates its reusable checkbox. The observed direct byte access is compatible with the accepted inline/control API and does not transfer ownership of generic `CheckBoxTextControlPane` source.
- Current method identities are `PartySearchEditPane::OnPaint()` at primary slot `+0x44` and `PartySearchEditPane::OnControlCommand(int,int)` at `+0x48`. Historical `OnDestroyChildControls` and `OnAction` labels are superseded source names retained only by physical UID slugs/history.
- The complete current class/record declaration, Event signatures, B003 packet handling, five bucket panes, all fields, exact `0x28c` size, and `[[CHILDREN]]` placement are preserved. Only `friend class PartySearchEditPane;` was added to the formal block.

## Data Notes

- `g_pUserListDialogPane` is the active dialog singleton. The `extern UserListDialogPane *g_pUserListDialogPane;` declaration in this class formal pairs with the sole zero-initialized module definition emitted by [UID:0003EI][g_pUserListDialogPane](by-global/g_pUserListDialogPane.md) through [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md); the exact storage child [UID:0002WD][0x0069b4e0-0x0069b4e4.g_pUserListDialogPane](by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md) remains false/non-emitting and does not supply a second declaration or definition.
- The direct `Singleton<UserListDialogPane>` base at complete-object `+0x26c` implicitly publishes and clears that pointer during construction/destruction. Constructor/EH/scalar-wrapper stores are compiler lowering of that base lifecycle and must not be duplicated as handwritten assignments, guards, or cleanup code.
- This class's inheritance and complete virtual declarations are the human source cause for [UID:0003E6][0x0062e8fc-0x0062e998.UserListDialogPaneVtableData](by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md) and the `UserListPane` declarations are the source cause for [UID:0003E8][0x0062eadc-0x0062eb9c.UserListPaneVtableData](by-memory/0x0062eadc-0x0062eb9c.UserListPaneVtableData.md). Complete-object locators, address-point arrays, adjustors, vptr stores, EH cleanup, scalar-delete flags, and RTTI remain compiler-generated rather than class-body source.
- `g_bShowHuntersListOnly` is the inferred source-facing module-scope boolean for [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md). When set, constructor and refresh paths include only records whose `UserListRecord::huntersListFlag` at `+0x20e` is nonzero. The old `g_bShowHiddenUsers` / `ShowHiddenFlag` wording is a stale historical assumption, not current source naming.
- `m_selectedNationId` is retained as the stable union field name, but `RefreshCategoryView` stores a `GameServerConfig::NationEntry` index in it. The method then loads the entry's `nationId` separately for `careerId`/`careerVariant` matching.
- `RefreshCategoryView` uses `g_activeUserStatusPane->GetNationId()` for page 0. The old-status-pane global remains relevant only to separate legacy constructor context and is not substituted into the refresh body.
- `g_userListDialogHighResLayout` and `g_userListDialogLowResLayout` are resource-layout dependencies.
- User rows are staged as packed `0x414` / `1044` byte `UserListRecord` entries. The record size is passed to list construction/allocation paths, used for the master-list capacity, and matches all observed offsets through `+0x413`.
- Resource strings tied to this source family include `Users Dialog Pane`, `USERLIST.PAL`, `USERLIST.EPF`, `USERLIST.PAD`, `USERLIST.EPD`, `%s > %s`, `Put me on the hunters list`, `STAR.EPF`, `ICON.EPF`, `STAR.EPD`, and `ICON.EPD`.
- [UID:00026U][0x0062e8fc-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md) records matching `UserListDialogPane`, `PartySearchEditPane`, and `UserListPane` vtable/resource data while keeping the interleaved reusable `CheckBoxTextControlPane` child separate.
- [UID:0003E6][0x0062e8fc-0x0062e998.UserListDialogPaneVtableData](by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md) records the exact `UserListDialogPane` vtable lead-in before the reusable checkbox-control child, with live vtable-base xrefs from constructor/destructor paths and an exclusive end at the `CheckBoxTextControlPane` RTTI word.

## B001 Source-Quality Reanalysis

B001's 2026-06-18 source-quality report resolved the prior open record, packet, flag, helper, and sort-name questions to high-probability source-facing names. Exact original identifier spellings remain unproven by the binary, but the following descriptive names are now supported strongly enough for first-draft class C++.

### Constructor Packet Fields

| Packet offset | Recommended name | Evidence |
| --- | --- | --- |
| `payload[0]` | opcode / message selector | Opcode `0x36` dispatch and server packet label table entry `kServerUserList` at `0x00626a9c`. |
| `payload+1` | `totalUserCount` / `serverTotalUserCount` | Big-endian word read before the entry loop and used to compute displayed/filtered totals. |
| `payload+3` | `userListEntryCount` | Big-endian word that bounds the `0x414` row-record parse loop. |
| `payload+5` | `initialSortMode` / `userListModeByte` | Seeds the dialog sort/view mode control state; no stronger protocol name is proven. |
| `payload+6` | first encoded user-list record | Start of the repeated record parser. |

The constructor allocates five `UserListPane` children of size `0x49c` through `0x0059e710`, passing row size `0x414`, visible count `0x64`, and bucket/list kind value `5`. The five pointers are stored at `this+0x274`, `this+0x278`, `this+0x27c`, `this+0x280`, and `this+0x284`; the master record list is at `this+0x288`. Dialog fields `this+0x26c`, `this+0x26e`, and `this+0x270` track selected category/career id, category page/cycle index, and selected local-player career variant/special-filter value.

### Packed `UserListRecord`

| Offset | Size | Recommended name | Evidence |
| --- | ---: | --- | --- |
| `+0x000` | 1 | `careerId` / `categoryId` | High nibble of encoded byte 0; compared against selected category/career in constructor and refresh. |
| `+0x001` | 1 | `bucketIndex` / `statusBucket` | Low bits of encoded byte 0; selects one of five `UserListPane` bucket panes. |
| `+0x002` | 1 | `reserved2` | Constructor zeroes it; no stable semantic reads were found, so do not name it `hiddenFlag`. |
| `+0x003` | 1 | `badgeIconId` / `secondaryIconId` | Low bits of encoded byte 1; `UserListPane` drawing uses values `1..4` to choose a 16-icon badge. |
| `+0x004` | 1 | `displayColor` / `rowColor` | Encoded packet byte 3; draw path uses it for row background/foreground behavior and local-player match overwrites it with `0x80`. |
| `+0x005..+0x007` | 3 | padding/reserved | No stable semantic reads found. |
| `+0x008` | 4 | `arrivalSortKey` / `sequenceSortKey` | Set to `100000 - ordinal`; status comparator uses it as tie-breaker. |
| `+0x00c` | 1 | `statusIconId` / `rankIconId` | High nibble of encoded byte 1; draw path renders star/status icon for values `1..4`; comparator prioritizes this byte. |
| `+0x00d` | 1 | padding/reserved | Alignment before wide name. |
| `+0x00e` | `0x200` | `name[256]` UTF-16 | Length-prefixed MBCS name is converted into this buffer; list matching and double-click/source requests compare this field. |
| `+0x20e` | 1 | `huntersListFlag` / `partySearchListed` | Encoded from low bits of packet byte 2; the global filter skips zero rows when set; opcode `0x83` and `PartySearchEditPane` confirm hunters-list semantics. |
| `+0x20f` | 1 | `hasSourceText` | Cleared after name conversion; opcode `0x84` sets it and stores source text; double-click checks it before posting cached source text. |
| `+0x210` | `0x200` | `sourceText[256]` UTF-16 | Opcode `0x84` copies a converted source string here; `AddUserListSourceMessage` formats this text with the row name. |
| `+0x410` | 1 | `careerVariant` / `specialFilterValue` | High nibble of encoded byte 2; selected-category case `10` compares it against `this+0x270`. |
| `+0x411..+0x413` | 3 | padding/reserved | No stable semantic reads found. |

Rejected record alternatives: `+0x20e` is not `hidden` or `showHidden`; setting the global byte makes the dialog show only rows with this flag set. `+0x20f` is not a second unrelated flag because it is set only with source-string population. `+0x00e` is not ANSI; the parser converts MBCS to UTF-16 and later helpers use wide-string operations. `+0x210` is not the target name; `%s > %s` formatting uses `+0x00e` for the name and `+0x210` for source text.

### Packet Updates And Local Helpers

- `HandleUserListPacket` opcode `0x83` synchronizes the local hunters-list/party-search listed flag: it writes `g_pUserPane + 0x3cb1` / historical `g_pPlayerData+0x3cb1`, updates control id `20`, mirrors the value into the matching row at `+0x20e`, and refreshes the category view.
- `HandleUserListPacket` opcode `0x84` updates a row source string: it reads a target name, source-text length/string, sets row `+0x20f`, writes `sourceText` at `+0x210`, syncs the visible bucket through `0x0059e9f0`, and posts a formatted source message through `0x0059de60`.
- Outbound opcode `0x85` is the source-text request sent by `UserListPane::OnDoubleClick` when the selected row has `huntersListFlag != 0` but no cached source text.
- `0x0059de60` is `AddUserListSourceMessage`, a user-list-specific helper that formats `"%s > %s"` from `name` and `sourceText`; it is not a generic chat helper.
- `0x0059e9f0-0x0059ea8f` is `SyncUserListSourceTextIntoBucket`, a local helper that copies source-text state into the visible bucket row.

### Sort Names, No-Route Chunks, And Ownership

- Existing sort names were swapped. `0x0059e950` is `CompareUserListRecordsByStatus`/rank because it compares record `+0x00c` and then `+0x008`; `0x0059e990` is `CompareUserListRecordsByName` because it compares wide strings at `+0x00e`.
- `0x0059d1f0` is therefore `SortListsByStatus`; `0x0059d250` is `SortListsByName`.
- `0x0059e9b0` and `0x0059e9d0` are no-route retained local sort wrappers over the internal `UserListPane` list at `this+0x130`; do not expose them as public methods without a new route.
- Non-modeled chunks are no longer generic unknowns: `0x0059d198-0x0059d1e0` is padding plus non-deleting destructor/constructor-unwind cleanup at `0x0059d1a0`; `0x0059d5fe-0x0059d620` is refresh switch-table/padding; `0x0059dbe3-0x0059dc20` is `OnControlCommand` switch-table data/padding; `0x0059dc20-0x0059de4a` is a no-route local send helper that uses the `UserListDialogPane *this` receiver plus `g_pUserPane+0x3cb1/+0x3cb2`, mirrors local-player hunters-list/source-text state into row `+0x20e/+0x20f/+0x210`, and builds outbound opcode `0x84`.
- Source placement remains `NexusTK/social/UserListDialogPane.cpp`; no split to `UserPane`, `MapPane`, `LivingObjectPane`, `UserStatusPane`, or generic controls is supported. `UserPane`/`MapPane` are dispatch callers, [UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md) is retained duplicate/no-live-route helper evidence, and `CheckBoxTextControlPane` keeps its reusable-control ownership.

## Evidence Notes

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) places this class in `NexusTK/social/` and records the social user-list source family, exact constructor callers, user-list pane construction, party-search command ownership, and read-only data island.
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) records the executable aggregate, modeled function boundaries, non-padding tail/table chunks, checkbox-control interleaves, caller/callee refs, and autogen attachment to the file parent.
- IDA MCP confirms the constructor and virtuals as real functions, with the constructor called from packet/UI paths at `0x005087f4`, `0x00513c6c`, `0x005a7ccb`, and `0x005abc54`.
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) identifies `0x0069b4e0` as the active `UserListDialogPane` singleton slot, written by the constructor and tested by UI/map paths.
- [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md) documents the hunters-list-only filter flag reads in the constructor and refresh path plus the toggle in `OnControlCommand`.
- Existing generated/recovered source names remain search leads only. Current ownership and scoring are based on UID-backed IDA/project documentation, not generated source quality.

## Score Rationale

- Completion is `93` because the class purpose, complete method map, local child classes, Singleton/hunters-list state, exact active-nation dependency, read-only data, exact vtable lead-in child, source-file parent, packed `0x414` record layout, constructor packet fields, source-message/source-text helpers, corrected sort/comparator names, non-modeled chunk taxonomy, and complete source-ready category-refresh method are documented.
- Confidence is `94` because the file parent, memory aggregate, exact vtable child, global/flag pages, raw packet-label evidence, resource strings, constructor/caller graph, current helper contracts, and exact UID000475 bytes/CFG/callers all agree on class shape and ownership. Exact original private identifiers and header packaging remain bounded lexical uncertainty.
- Formal C++ contains the complete current class and `UserListRecord` declarations, closes `UserListDialogPane` before `[[CHILDREN]]`, and declares `void RefreshCategoryView(char step)`. Method bodies remain on exact child pages under [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md).

## Cross-References

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0000FO][UserListPane](by-class/UserListPane.md)
- [UID:0000A7][PartySearchEditPane](by-class/PartySearchEditPane.md)
- [UID:00026U][0x0062e8fc-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md)
- [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md)

## Changes

- 2026-07-20 B005 UID00047H expanded callback:
  - Preserved `94/95`, owner/emitter UID0000OZ, the complete formal block byte-for-byte, exact Singleton/DialogPane inheritance, packed `UserListRecord`, methods, fields, children, `0x28c` layout, and every unrelated UserListDialogPane, PartySearch, Event, packet, clipboard, compiler, and historical fact.
  - Added only the declaration/definition contract: the existing class-level extern pairs with the sole UID0003EI module definition, while UID0002WD remains the false/non-emitting physical storage description.
  - Recorded that direct `Singleton<UserListDialogPane>` construction/destruction implicitly publishes and clears the pointer and that class/virtual source regenerates UserListDialogPane/UserListPane vtables. Explicit singleton stores, vptr writes, RTTI/COL arrays, adjustors, scalar-delete mechanics, EH cleanup, or a second global definition remain rejected compiler duplication.
- 2026-07-19 B005 UID000478 accepted implementation callback, Phase 1:
  - Preserved `94/95`, owner/emitter UID0000OZ, the complete class formal byte-for-byte, exact `0x28c` layout, packed record, five bucket pointers, every B003/B004/PartySearch declaration and behavior, compiler exclusions, source route, and historical evidence.
  - Reclassified UID000478 from blank child to source-ready emitting `HandleKeyOrTextEvent(Event *)` and recorded the exact secondary-slot ABI, translation-before-gates order, unmodified key-down Page Up/Page Down behavior, branch-local base forwarding, all-five-pane Ctrl+C selected-name publication, last-selected-pane-wins behavior, false Ctrl+C result, helper dependencies, and source/compiler boundary.
  - At this evidence-time checkpoint, clipboard-helper creation and shared TextEditPane/TextEditScrap documentation remained deliberately deferred to the supervisor-released Phase 2 lane; no shared destination or class formal was changed in Phase 1.
- 2026-07-20 B005 UID000478 serialized implementation callback, Phase 2:
  - Linked registered external helper UID0004T8 and its exact TextEditPane-owned prototype/behavior while preserving `94/95`, owner/emitter UID0000OZ, the complete class formal byte-for-byte, the exact `0x28c` layout, and all unrelated B003/B004 declarations and evidence.
- 2026-07-19 B005 UID00047D accepted implementation callback:
  - Preserved `94/95`, owner/emitter UID0000OZ, every B003/B004 declaration, packed record field, Event signature, enum, method, field, child, compiler exclusion, and exact `0x28c` layout.
  - Added only `friend class PartySearchEditPane;` before the existing private fields and documented its bounded use for active local-record scan/mirror during the complete PartySearch submit flow.
  - Added the exact current PartySearch constructor/OnPaint/OnControlCommand identities, typed UserPane state route, packed-row update, opcode `0x84` payload/send, no-null-guard invariant, reusable-control ownership, and superseded-name history without changing unrelated class content.
- 2026-07-19 B003 UID000477 accepted implementation callback:
  - Raised `93/94 -> 94/95` and installed exact complete R2 with the class closed before `[[CHILDREN]]`.
  - Corrected packet/key handlers to EventHandler `HandlePacketEvent(Event *)` / `HandleKeyOrTextEvent(Event *)`, declared the proved dialog member `AddUserListSourceMessage`, and removed stale PacketEventContext/KeyEvent/free-helper source shape.
  - Added exact enums, global/local-name declarations, adjusted-facet ABI, vtable source cause, helper ownership, packed `0x414` row evidence, and preserved the exact `0x28c` Singleton-EBO layout, every unrelated method/field/child/history fact, and UID0000OZ route.

- 2026-07-16 B004 UID000475 implementation callback:
  - Raised `92/93 -> 93/94`, preserved owner/emitter UID0000OZ, reconstructable state, complete Singleton/DialogPane class union, packed `UserListRecord`, helper declarations, fields, children, compiler exclusions, and history.
  - Applied the accepted complete class formal with only the source signature correction `RefreshCategoryView(int step) -> RefreshCategoryView(char step)`; the class remains closed before `[[CHILDREN]]`.
  - Documented `m_selectedNationId` as a nation-entry index in the refresh path, the separate selected `nationId` load, the active UserStatusPane dependency, six-page mapping, five-pane rebuild, exact filters/sorts/counts/labels, and UID000475 source emission without pruning unrelated class content.

- 2026-07-14 B004 UID000470 implementation callback:
  - Raised `88/88 -> 92/93`, preserved owner/emitter UID0000OZ and reconstructable state, and replaced the incomplete one-base declaration with the accepted complete class block closed before `[[CHILDREN]]`.
  - Added direct `Singleton<UserListDialogPane>` before `DialogPane`, matching RTTI PMD `+0x26c`, constructor order, and empty-base overlap; no manual singleton-pointer member or assignment was introduced.
  - Corrected the tail to `m_selectedNationId`, `m_categoryPage`, branch-conditionally initialized `m_selectedCareerVariant`, five `UserListPane *`, and exact `List *m_allUserRecords`, yielding the observed `0x28c` complete size.
  - Corrected `OnControlCommand(int controlIndex, int notifyCode)`, removed invented private rebuild helpers and static comparator ownership, and retained the four local free-helper declarations used by exact source children.
  - Preserved the packed `0x414` record, EPF/EPD packet differences, branch-specific uninitialized fields, all existing exact children, historical B001/B002 evidence, raw-helper exclusions, resource/global dependencies, and unrelated content.

- 2026-06-22 Rule 26 support sync from B001 [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md):
  - Updated the opcode `0x83` local-player flag dependency to source-facing `g_pUserPane + 0x3cb1`; `g_pPlayerData` remains a historical typed-view alias.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` while leaving `AUTOGEN_PARENT_UID` blank.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, sort/filter/packet/key/control methods, adjustor thunks, and scalar deleting destructor at `0x0059bc90`, `0x0059d1f0`, `0x0059d250`, `0x0059d2b0`, `0x0059d620`, `0x0059d900`, `0x0059da90`, `0x0059f017`, `0x0059f022`, and `0x0059f110`; likely parent [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) passes 80/80, but this class page is `84/78`, so the child-side parent gate does not pass. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:78`.
  - Summary/evidence: scored from the users-dialog responsibility, constructor, sort/filter/packet/key/control method map, related local classes, data notes, constructor callers, and explicit generated-source quality caveat.
- 2026-06-07 A004 parent-gate cleanup:
  - What existed before: the page remained `84/78`, had no parent UID, and still framed confidence around generated-source quality despite stronger UID-backed file, memory, read-only-data, global, and child-class documentation.
  - Changed to: `CONFIDENCE:84`, `AUTOGEN_PARENT_UID:0000OZ`, class-shape notes, data-state references, score rationale, and source-facing evidence based on existing IDA-backed docs.
  - Summary/evidence: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md), [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md), [UID:00026U][0x0062e8fc-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md), [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md), and [UID:0002A7][0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag](by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md) now support the class/file attachment. The flag page was then using the stale show-hidden name; C++ remained blank because final record/packet fields and helper names were below the reconstruction threshold at that time.
- 2026-06-11 A002 Batch227 strict-gate repair: Raised completion/confidence from `84/84` to `85/85` after splitting exact child [UID:0003E6][0x0062e8fc-0x0062e998.UserListDialogPaneVtableData](by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md) and live IDA MCP reconfirmed the vtable base, constructor/destructor xrefs, backing destructor thunk, and boundary before `CheckBoxTextControlPane`.
- 2026-06-18 B001 Rule 26 source-quality incorporation:
  - What existed before: the page was `85/85`, used stale `g_bShowHiddenUsers` wording, had swapped sort names, left `1044`-byte records and packet/helper names open, and had blank formal C++.
  - Changed to: `88/88`, first-draft class/record C++, corrected `g_bShowHuntersListOnly` semantics, corrected `SortListsByStatus`/`SortListsByName` mapping, full `UserListRecord` field layout, packet-field notes, opcode `0x83`/`0x84`/`0x85` handling, helper names, non-modeled chunk taxonomy, rejected alternatives, and current ownership/source-placement rationale.
  - Summary/evidence: B001 compared current docs, accepted [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md)/[UID:0003US][0x005abb20-0x005abc6f.UserPaneHandleUserListPacket](by-memory/0x005abb20-0x005abc6f.UserPaneHandleUserListPacket.md) packet-route reports, raw packet label table `kServerUserList` at `0x00626a9c`, raw disassembly for `0x0059bc90-0x0059f25b`, resource strings, comparator behavior, and constructor/list/helper call evidence. Exact original identifier spellings remain inferred but no longer block class-level draft C++.
- 2026-06-26 B002 split implementation support sync:
  - Added real child UID links for constructor/sort/refresh/packet/key/control/artifact coverage after [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) was converted to a non-emitting split index. Class-level C++ remains declaration-only; exact method/helper C++ belongs on the child pages.
