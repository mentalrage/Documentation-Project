*** UID:0000FO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MouseEvent;
class UserListRecord;

class UserListPane : public ListPane
{
public:
    UserListPane(int recordSize,
                 int pageSize,
                 UserListPane **siblingPanes,
                 int siblingPaneCount);
    virtual ~UserListPane();

    void SortRecords(ListCompareFunction compare);
    int GetRecordCount() const;
    UserListRecord *GetRecordAt(int index)
    {
        return static_cast<UserListRecord *>(GetItem(index));
    }
    int GetSelectedIndex() const
    {
        return m_selectedIndex;
    }
    UserListRecord *GetSelectedRecord()
    {
        return m_selectedIndex >= 0 ? GetRecordAt(m_selectedIndex) : 0;
    }
    void AddEntry(const UserListRecord *record);
    void SyncSourceText(const UserListRecord *sourceRecord);

    virtual void DrawUserEntry(int itemIndex,
                               const UserListRecord *record,
                               const RectBounds *bounds);
    virtual void OnItemSelected(int itemIndex);
    virtual void OnItemActivated();
    virtual bool OnDoubleClick(const MouseEvent &event);

private:
    EPFTileContext m_statusIconFrames[4];
    EPFTileContext m_badgeIconFrames[16];
    EPFTileContext m_huntersListIconFrame;
    UserListPane **m_siblingPanes;
    int m_siblingPaneCount;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserListPane

## Status

- Confidence: strong for class purpose and local ownership.
- Likely source file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Address range: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- Current recovered file: `source-3/simroot_v2/class_UserListPane.cpp`

## Class Purpose

`UserListPane` is the repeated list widget used by `UserListDialogPane` for user rows. It derives from/list-wraps `ListPane`, draws user entries, tracks selection, handles the inherited item-activation virtual by opening direct-message input for the selected user, and dispatches the distinct double-click source/message actions.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0059e710-0x0059e899` | Exact source-ready four-argument constructor: calls the ListPane base, explicitly initializes the 4/16/1 frame contexts, selects STAR/ICON EPF versus EPD resources, loads EPF-only SYMBOLS frame 223 into the hunters-list context, then stores the five-pane sibling route. |
| destructor | `0x0059e8a0-0x0059e943` | Source-ready ordinary destructor explicitly releases four status, sixteen badge, and one hunters-list frame contexts in forward storage order; base/vptr/EH/delete mechanics remain compiler output. |
| `DrawUserEntry` | `0x0059ea90-0x0059ed18` | Source-ready three-argument virtual draws hunters/status/bucket-badge frames, selected fill, display/selected/friend colors, and right-aligned packed-row name text. |
| `OnItemSelected` | `0x0059ed20-0x0059ed5e` | Selection callback, then forwards to base list selection. |
| `OnItemActivated` | `0x0059ed60-0x0059ee0c` | Primary-vtable `+0x7c` activation override. After ListPane has established a valid hit/selection, it fetches `GetRecordAt(m_selectedIndex)`, queues the user-list dialog for deferred deletion, and opens the modern or legacy direct-message pane from the row name. |
| `OnDoubleClick` | `0x0059ee10-0x0059efd0` | Handles double-click row actions, calls `AddUserListSourceMessage` when cached source text is available, or sends outbound source-text request opcode `0x85`. |
| `SyncSourceText` | `0x0059e9f0-0x0059ea8f` | Member scan using case-sensitive `wcscmp`; marks and copies source text into every matching row. |
| adjustor thunks | `0x0059f02d-0x0059f043` | Destructor adjustors for list-pane subobjects. |
| scalar deleting destructor | `0x0059f190-0x0059f25b` | Deleting destructor wrapper around list-pane teardown. |

## Exact Child Pages

B002 split implementation added exact child pages for `UserListPane` executable coverage:

- [UID:00047H][0x0059e710-0x0059e899.UserListPaneConstructor](by-memory/0x0059e710-0x0059e899.UserListPaneConstructor.md) is source-ready at `92/94` and emits the exact constructor through UID0000OZ. Its former blank-body frame/resource blocker is superseded by this complete layout plus the exact EPFTileContext and copy-wrapper contracts.
- [UID:00047I][0x0059e8a0-0x0059e943.UserListPaneDestructor](by-memory/0x0059e8a0-0x0059e943.UserListPaneDestructor.md) is source-ready at `92/94`: exact bytes/CFG and scalar-vtable liveness prove one ordinary destructor whose handwritten body performs forward 4/16/1 `ReleaseBuffers` calls. Automatic ListPane teardown, vptr restores, EH/cookie, adjustors, scalar flags, and optional delete remain compiler-generated.
- [UID:00047O][0x0059ea90-0x0059ed18.UserListPaneDrawUserEntry](by-memory/0x0059ea90-0x0059ed18.UserListPaneDrawUserEntry.md) is source-ready at `92/94`: physical `retn 0x0c` proves item-index, packed-record, and bounds arguments; the body preserves all icon predicates/indexes/geometry, selected fill, friend-name color, and right-aligned text behavior.
- [UID:00047P][0x0059ed20-0x0059ed5e.UserListPaneOnItemSelected](by-memory/0x0059ed20-0x0059ed5e.UserListPaneOnItemSelected.md), [UID:00047Q][0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane](by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md) (`OnItemActivated`), and [UID:00047R][0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick](by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md) carry exact formal C++ through [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md).
- [UID:00047N][0x0059e9f0-0x0059ea8f.UserListPaneSyncSourceText](by-memory/0x0059e9f0-0x0059ea8f.UserListPaneSyncSourceText.md) is the source-authored member `SyncSourceText(const UserListRecord *)`, not a free helper. Target-call ECX proves the member receiver, and the body uses case-sensitive `wcscmp`, not `_wcsicmp`.
- [UID:00047L][0x0059e9b0-0x0059e9cf.UserListPaneSortByStatusNoRouteWrapper](by-memory/0x0059e9b0-0x0059e9cf.UserListPaneSortByStatusNoRouteWrapper.md) and [UID:00047M][0x0059e9d0-0x0059e9ef.UserListPaneSortByNameNoRouteWrapper](by-memory/0x0059e9d0-0x0059e9ef.UserListPaneSortByNameNoRouteWrapper.md) are no-owner raw wrappers, not public class APIs, because current xref/code/data/immediate/pointer-route evidence to their starts is negative. B006's UID00047M refresh kept the no-rename child path but documented the exact name-sort body at `0x0059e9d0-0x0059e9e1`: it loads the internal list at `this+0x130`, pushes `CompareUserListRecordsByName`, calls `List::Sort`, returns, then aligns to `0x0059e9f0`.
- [UID:00047T][0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks](by-memory/0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks.md) and [UID:00047W][0x0059f190-0x0059f25b.UserListPaneScalarDeletingDestructor](by-memory/0x0059f190-0x0059f25b.UserListPaneScalarDeletingDestructor.md) are compiler-generated artifacts with blank formal C++.

## Evidence Notes

- The constructor at `0x0059e710` calls `ListPane(recordSize,pageSize,108,12,0,1,1)`, begins derived storage at exact base boundary `+0x14c`, explicitly initializes four 40-byte status contexts, sixteen 40-byte badge contexts, and one 40-byte hunters-list context, then stores sibling pointer/count at `+0x494/+0x498`; complete size is `0x49c`.
- UID000470 calls it at `0x0059c00a` and `0x0059cb6b`, allocating `0x49c` and passing `sizeof(UserListRecord)`, page size 100, the five-pane array, and count 5. This complete declaration removes the old allocation/layout blocker while retaining each executable method on its exact child page.
- All 21 contexts receive `Initialize` before resources. With `g_useEpfAssets == 1`, the constructor loads STAR EPF frames 0..3, ICON EPF frames 0..15, and `SYMBOLS.EPF` frame 223 into `m_huntersListIconFrame`; otherwise it loads only STAR/ICON EPD banks. The signed-short loop values, unconditional `g_pEPFLib` calls, and post-branch sibling stores preserve exact binary order.
- `DrawUserEntry` independently maps status id `+0x0c` to `m_statusIconFrames`, badge/bucket ids around `+0x03/+0x01` to `m_badgeIconFrames`, and `huntersListFlag` at `+0x20e` to `m_huntersListIconFrame`. The historical `m_selectionFrame` spelling is rejected because no selection predicate controls that context.
- Constructor vptr writes, SEH/cookie setup, partial-construction cleanup, returned-`this`, and the neighboring scalar wrapper are compiler lowering and remain absent from the human class/method source.

## Destructor, Draw, And Vtable Closure

- The destructor's exact 163 bytes (`67CF6D994E2303D173D49D2A9428D341CD92EFAF4751EB90971EA95B2F1215BF`) contain 54 instructions, seven blocks, and complexity two. Explicit lifecycle follows declaration/storage order: status bank, badge bank, hunters frame. Primary-vtable scalar wrapper reachability proves liveness despite zero ordinary callers.
- `DrawUserEntry` exact 648 bytes (`84C846F8D3218CEA450A252849AC41B354E82DE2F408C5E3585A96263B5E2ECC`) contain 237 instructions, sixteen blocks, and complexity nine. Hunters id equality, status/badge 1..4 gates, row-centered left 0/12/24 destinations, typed blit/fill calls, selection color 128, twenty profile-string comparisons with friend color 9, and right-aligned counted text are all directly accounted for.
- The exact packed row contract is `bucketIndex +0x01`, `badgeIconId +0x03`, `displayColor +0x04`, `statusIconId +0x0c`, `name[256] +0x0e`, `huntersListFlag +0x20e`, source fields, and `careerVariant +0x410`. No raw overlay or duplicate Config field is required.
- [UID:0003E8][0x0062eadc-0x0062eb9c.UserListPaneVtableData](by-memory/0x0062eadc-0x0062eb9c.UserListPaneVtableData.md) is false compiler data, not a source emitter. Exact address points are primary `0x0062eadc` (33 slots), secondary `0x0062eb64` (11 slots, COL complete offset `+0xa0`), and tertiary `0x0062eb94` (two slots, COL complete offset `+0xa4`). Constructor, ordinary destructor, and scalar wrapper each reference all three views. This complete declaration plus virtual bodies regenerates the tables; no RTTI/COL/vtable arrays or adjustor source is handwritten.
- Historical blank-destructor/blank-draw and `0x0062eb44/0x0062eb74` table-start assumptions are superseded by the direct audits. They remain useful correction history, not current blockers.

## UID000478 Selected-Record Access

- UID000478 reads inherited `ListPane::m_selectedIndex` at exact complete-pane offset `+0x134`, rejects negative values, then calls indexed record accessor `0x004f3dc0` with that same index. Existing ListPane evidence identifies `0x004f3dc0` as caller-supplied indexed item/record access, not a globally selected-only helper.
- Inline `GetSelectedIndex() const` lowers to the observed field load. Inline `GetSelectedRecord()` lowers to the same nonnegative test followed by `GetRecordAt(m_selectedIndex)`; UID000478's explicit index gate permits optimization to exactly one visible check and one indexed fetch.
- Returned storage is the packed `UserListRecord` row. UID000478 consumes only UTF-16 `name[256]` at `+0x00e`; it does not reinterpret row bytes, change ownership, or add selection state.
- These accessors add no data members and preserve the exact `0x14c` ListPane base boundary, `0x49c` complete size, four/sixteen/one frame arrays, sibling fields, vtable surface, children, owner/emitter UID0000OZ, and `92/93`.
- Exact original accessor spellings remain inferred and cap confidence; `GetSelectedEntry` as the name of `0x004f3dc0`, a new out-of-line selected helper body, raw `this+0x134` access, and promotion of no-route UID00047L/UID00047M wrappers are rejected.

## UID00047Q Item-Activation Closure

- [UID:00047Q][0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane](by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md) is the no-argument `ListPane` primary-vtable `+0x7c` activation override, not a class-specific public helper. Base dispatch at `0x004f4190` invokes `+0x78` selection and then `+0x7c` only after a successful double-click hit; the PhoneBook derived class uses the same slot for its own selected-item action.
- The exact target body reads `m_selectedIndex` at complete-pane offset `+0x134`, calls inherited explicit-index `GetItem`, and dereferences the packed `UserListRecord::name[256]` field at `+0x00e` without a null branch. The formal inline `GetRecordAt(int)` wrapper expresses that inherited call while preserving the binary's direct indexed access.
- `GetSelectedRecord()` remains part of the class for callers that require a guarded selected-row convenience. UID00047Q intentionally does not use it because ListPane has already established selection validity and the machine contains no target null test.
- The method unconditionally invokes `g_pUserListDialogPane->CloseDialog()`. Deferred deletion plus the modern and legacy constructors' immediate copies into `m_recipientName[128]` preserve the observed close-before-construction order safely.
- `g_useEpfAssets` selects `NewSayToUserMessageInputPane(record->name)` when true and `SayToUserMessageInputPane(record->name)` otherwise. The two `0x208` allocations, constructor unwind cleanup tails, vptr writes, cookie, and frame-handler logic are compiler lowering represented by the ordinary `new` expressions.
- Historical terminology: `OpenSayToUserMessageInputPane` described this override's derived behavior but is not the current shared virtual name. The old guarded draft and free `ClosePane` expression are rejected because they add control flow or an API not present in the binary.

- Wave3 reports class grade `96.1`, with current source emitted separately as `class_UserListPane.cpp`.
- IDA MCP confirms `UserListDialogPane` constructor calls `UserListPane` at `0x0059c00a` and `0x0059cb6b`.
- The class should migrate with `UserListDialogPane.cpp` rather than a generic list-control file because its draw and double-click behavior are specific to social user records.
- Exact vtable child [UID:0003E8][0x0062eadc-0x0062eb9c.UserListPaneVtableData](by-memory/0x0062eadc-0x0062eb9c.UserListPaneVtableData.md) records the `UserListPane` `.rdata` table area, constructor/destructor store xrefs, backing method starts, and boundary before the user-list string tail.
- 2026-06-18 B001 source-quality support note: `UserListPane` rows are packed `0x414` `UserListRecord` entries owned by [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md). Important row fields used by this class are UTF-16 `name[256]` at `+0x00e`, `huntersListFlag` / `partySearchListed` at `+0x20e`, `hasSourceText` at `+0x20f`, UTF-16 `sourceText[256]` at `+0x210`, `displayColor` at `+0x004`, `statusIconId` at `+0x00c`, and icon/badge fields around `+0x003`. The old hidden-user interpretation is rejected for row `+0x20e`; it is the hunters-list/party-search marker used by [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md). `OnDoubleClick` should be described as cached source display versus opcode `0x85` source request, not only generic source-message display.
- UID000477/UID00047N member-ABI evidence closes the source helper surface: `HandlePacketEvent` maps bucket zero to pane four and nonzero `n` to `n-1`, calls `pane->SyncSourceText(record)`, and `SyncSourceText` updates every case-sensitive matching row. UID00047R's cached path calls the dialog member through `g_pUserListDialogPane`; no global Sync/Add helper declarations belong to this class source.

## Cross-References

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md)

## Changes

- 2026-08-13 B001 UID00047Q accepted implementation callback:
  - Preserved `93/94`, owner/emitter UID0000OZ, inheritance, complete `0x49c` layout, all unrelated methods/fields/children, target H blank, and `[[CHILDREN]]` placement.
  - Replaced only the out-of-line `GetRecordAt(int)` declaration with its exact typed inline `GetItem(index)` wrapper and the historical behavior-specific declaration with `virtual void OnItemActivated();`.
  - Added exact primary-slot/base-dispatch, no-guard, packed-name, deferred-close, constructor-copy, asset-mode, compiler-lowering, and historical-name evidence while retaining `GetSelectedRecord()` unchanged for its other guarded callers.

- 2026-07-20 B005 UID00047H expanded implementation callback:
  - Raised only `92/93 -> 93/94`, preserving owner/emitter UID0000OZ, inheritance, complete `0x49c` layout, all fields/accessors/methods/children, source route, class closure, and `[[CHILDREN]]` placement.
  - Applied the revised complete declaration by adding only `const UserListRecord *record` to the current `DrawUserEntry` signature; constructor and accepted hunters-frame spelling remain unchanged.
  - Added exact source-ready destructor/draw evidence, forward 4/16/1 lifecycle, three-icon/selection/friend/text behavior, packed row/support contracts, and exact false compiler-vtable source cause without handwritten compiler data.
  - Historicalized the earlier independent blank-body/table-start dispositions while preserving all constructor, UID000478, UID000477, B001/B003/B004/B005/B006, no-route, and compiler history.

- 2026-07-20 B005 UID00047H accepted implementation callback:
  - Preserved `92/93`, owner/emitter UID0000OZ, complete inheritance/method/field/child union, inline selected-record access, B003/B004/B005/B006 history, no-route wrappers, and compiler exclusions.
  - Applied exact Destination 2 by changing only formal field `m_selectionFrame` to `m_huntersListIconFrame`; all other formal bytes, class closure, and `[[CHILDREN]]` placement remain the accepted current class surface.
  - Added exact constructor callers/arguments, base call, 4/16/1 initialization and layout, EPF/EPD STAR/ICON branches, EPF-only SYMBOLS frame 223, signed-short frame indices, unconditional resource route, post-resource sibling stores, draw-consumer corroboration, compiler separation, lexical cap, and stale selection/layout/no-code history.
  - Split child dispositions accurately for that bounded callback: UID00047H was source-ready while UID00047I and UID00047O remained independent direct audits. The later expanded callback above supersedes only those interim blank-body dispositions.
- 2026-07-20 B005 UID000478 serialized implementation callback, Phase 1:
  - Preserved `92/93`, owner/emitter UID0000OZ, blank position, complete `0x49c` declaration, constructor/destructor/method/field/child union, B003/PartySearch content, no-route wrappers, compiler exclusions, and history.
  - Applied exact Destination 4 by adding inline `GetSelectedIndex() const` and changing `GetSelectedRecord()` to the evidence-backed inline nonnegative-indexed accessor; recorded UID000478 field/call lowering, packed-name consumer, no-layout-change proof, lexical cap, and rejected alternatives.
- 2026-07-19 B003 UID000477 accepted implementation callback:
  - Raised `91/92 -> 92/93` and installed exact R5 by adding only `SyncSourceText(const UserListRecord *)` to the complete current class declaration.
  - Added UID00047N member/case-sensitive evidence and UID00047R dialog-member call correction while preserving exact `0x49c` layout, all current methods/fields, child dispositions, no-route wrappers, compiler artifacts, and UID0000OZ route.

- 2026-07-14 B004 UID000470 support implementation:
  - Raised `85/87 -> 91/92`, preserved owner/emitter UID0000OZ and all existing exact-child ownership, and inserted the accepted complete `UserListPane` declaration closed before `[[CHILDREN]]`.
  - Added exact `0x14c` base boundary, 4/16/1 `EPFTileContext` arrays, sibling pane pointer/count at `+0x494/+0x498`, and complete size `0x49c`, as proved by constructor `0x0059e710` and UID000470 call sites.
  - Added only the class surface required by current exact children and the constructor: typed record access/add, sort/count, draw/selection/message/double-click methods. UID00047L/UID00047M remain no-owner/non-emitting wrappers rather than public methods; compiler adjustor/deleting-destructor children remain blank.

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, destructor, row draw, selection callback, message-input opener, double-click handler, adjustor thunks, and scalar deleting destructor at `0x0059e710`, `0x0059e8a0`, `0x0059ea90`, `0x0059ed20`, `0x0059ed60`, `0x0059ee10`, `0x0059f02d`, `0x0059f038`, and `0x0059f190`; this page and parent [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:86`.
  - Summary/evidence: scored from the repeated-list purpose, constructor/destructor/draw/selection/message/double-click method map, constructor call evidence, and local ownership with `UserListDialogPane`.
- 2026-06-11 A002 Batch227 strict-gate repair: Raised from `84/86` to `85/87` after splitting exact child [UID:0003E8][0x0062eadc-0x0062eb9c.UserListPaneVtableData](by-memory/0x0062eadc-0x0062eb9c.UserListPaneVtableData.md). Live IDA MCP reconfirmed the vtable base, store/reset xrefs, constructor/destructor function boundaries, and the `Users Dialog Pane` string successor boundary.
- 2026-06-18 B001 support incorporation: Added the `UserListRecord` row-layout details used by `UserListPane`, corrected `AddUserListSourceMessage` naming, documented cached source-text state and opcode `0x85` source request behavior, and linked the row `+0x20e` hunters-list marker to [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md). Score remains `85/87` because this was support incorporation, not a full class-C++ pass for `UserListPane`.
- 2026-06-26 B002 split implementation support sync: Added exact child links for constructor/destructor/draw/selection/direct-message/double-click/no-route wrappers/adjustor/scalar-deleting-destructor coverage after [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) was split. No-route wrappers remain blank-emitter no-owner children rather than class APIs.
- 2026-07-03 B006 UID00047M support sync: live MCP session `2ec9c08f` confirmed the name-sort wrapper's exact bytes, code body `0x0059e9d0-0x0059e9e1`, alignment to `0x0059e9f0`, `this+0x130` list load, `CompareUserListRecordsByName`, `List::Sort`, unique signature, and negative start/interior/end route checks. This class page should continue to treat UID00047M as no-owner/non-emitting wrapper evidence, not as a public `UserListPane` member.
