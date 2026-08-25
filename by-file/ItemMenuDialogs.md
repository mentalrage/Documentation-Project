*** UID:0000KF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ItemMenuDialogs

## Status

- Confidence: strong for the accepted distinct server/client item-menu module, child parent routing, factory reachability, raw-start liveness, exact split children, corrected row layouts, and complete CPP/H placement.
- Accepted source module: `ui/dialogs/ItemMenuDialogs.cpp` with required sibling `ui/dialogs/ItemMenuDialogs.h`.
- Superseded placement hypothesis (historical): folding these four classes into `ui/dialogs/ItemDialogs.cpp` was rejected because the closed item-menu binary island, adjacent RTTI/vtables, four factory routes, and immediate `SpellMenuDialogs` successor support a distinct companion module.
- Superseded generated leads (historical): the old `class_ServerItemMenuDialog.cpp`, `class_ServerItemMenuItemList.cpp`, `class_ClientItemMenuDialog.cpp`, and `class_ClientItemMenuItemList.cpp` outputs were fragmented evidence only; the accepted route replaces them with the ordered `ItemMenuDialogs.cpp` definitions and `ItemMenuDialogs.h` declarations documented below.
- Evidence basis: `source-3/simroot_v2` generated files plus IDA MCP checks on 2026-05-24, 2026-05-26, the 2026-06-07 A001 Batch081 parent-gate refresh, the 2026-06-16 A001 file-confidence refresh, the B002 2026-06-19/20 Rule 26 aggregate source-quality report, and B013's 2026-06-21 `ClientItemMenuDialog` source-quality pass.
- Vtable/layout anchor: [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md), with broader mixed-family context in [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).

## Hypothesis

The original source likely kept the server and client item context-menu dialogs together with their private list-pane row classes. The dialogs own the packet parsing, object preview, buttons, description text, and scrollable list container. The item-list classes own row records, selection text updates, activation forwarding, and row drawing.

The list classes should stay adjacent to the item-menu dialogs, but shared `ListPane`, image-control, object-preview, network-packet writer, and `MerchantDialogPane` base helpers should not be migrated into this file.

IDA confirms item menu dialog/list vtables at `0x0061eea8-0x0061f15c`. Historical fragmented class-generated metadata reported `vtable_count: 0`; that snapshot is superseded and is not current authority. UID00031Z now preserves the exact compiler-evidence inventory, while the four current `94/94` class pages provide the human declarations that regenerate those artifacts.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `ServerItemMenuDialog` | [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md) | `ItemMenuDialogs.cpp` | Parses server-provided item menu packet data, creates `DLGMERC3.EPF` dialog controls, and dispatches selected server menu row names through opcode `0x39`. |
| `ServerItemMenuItemList` | [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md), compiler destructor glue [UID:0001BZ][0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks](by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md) and [UID:0001C2][0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor](by-memory/0x00520ce0-0x00520d47.ServerItemMenuItemListScalarDeletingDestructor.md) | `ItemMenuDialogs.cpp` | Server-provided item row list; stores corrected `ServerItemMenuEntry` records, updates description slot `7`, sends selected/caller-supplied row names, draws item/value rows, and owns the ordinary `~ServerItemMenuItemList()` source body. The compiler regenerates the adjustors/scalar wrapper. |
| `ClientItemMenuDialog` | [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md) | `ItemMenuDialogs.cpp` | Builds client-side item action menus from local inventory state and sends selected action packets. |
| `ClientItemMenuItemList` | [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md), shared destructor glue at `0x00520ad1`, `0x00520adc`, `0x00520c20` | `ItemMenuDialogs.cpp` | Client-side item row list; stores corrected `ClientItemMenuEntry` records, appends local item-action rows, sends selected/explicit action ids, forwards activation, and draws icon/name rows. |

## IDA MCP Evidence

- `ServerItemMenuDialog` methods are IDA functions at `0x0051a520`, `0x0051acb0`, and `0x0051ae50`.
- `ServerItemMenuItemList` has raw constructor/destructor/helper code at `0x0051ae90`, `0x0051af00`, `0x0051af40`, `0x0051afd0`, and `0x0051b190` that IDA does not currently model as function starts. IDA does model the vtable virtuals at `0x0051b100`, `0x0051b2b0`, `0x0051b2c0`, and `0x0051b3e0`.
- `ClientItemMenuDialog` methods are IDA functions at `0x0051b880`, `0x0051c310`, and `0x0051c430`.
- `ClientItemMenuItemList` has IDA functions at `0x0051c470`, `0x0051c6b0`, and `0x0051c6c0`, plus raw helper code at `0x0051c4e0`, `0x0051c550`, and `0x0051c610`.
- IDA xrefs show `ClientItemMenuDialog` calls `ClientItemMenuItemList` construction at `0x0051ba35` and `0x0051bf64`.
- IDA xrefs do not show direct calls to the out-of-line `ServerItemMenuItemList` constructor at `0x0051ae90`; the server dialog contains inline-equivalent vtable writes at `0x0051a6ff`, `0x0051a705`, and `0x0051a70f`.
- 2026-06-07 A001 Batch081 live IDA recheck reconfirmed `ClientItemMenuDialog` functions at `0x0051b880` size `0xa8a`, `0x0051c310` size `0x112`, and `0x0051c430` size `0x3d`; the constructor is called by menu factory helpers at `0x00517677` and `0x00517ae7`.
- 2026-06-07 A001 Batch081 `xrefs_to` reconfirmed the `ClientItemMenuDialog` constructor stores primary, secondary, and tertiary vtable bases `0x0061f008`, `0x0061f068`, and `0x0061f098` at `0x0051b8e9`, `0x0051b8ef`, and `0x0051b8f9`, while virtual dispatch rows point `0x0061f050` to `0x0051c310` and `0x0061f054` to `0x0051c430`.
- 2026-06-07 A001 Batch081 `callers/xrefs_to 0x0051c470` reconfirmed `ClientItemMenuItemList` is constructed only from `ClientItemMenuDialog` at `0x0051ba35` and `0x0051bf64`, supporting this file as the direct source owner for both client item-menu classes.
- 2026-06-16 A001 live IDA MCP reconfirmed the modeled function inventory: `0x0051a520` size `0x76e`, `0x0051acb0` size `0x192`, `0x0051ae50` size `0x3d`, `0x0051b880` size `0xa8a`, `0x0051c310` size `0x112`, `0x0051c430` size `0x3d`, and `0x0051c470` size `0x6c`; `0x0051ae90` still is not an IDA function.
- The same A001 refresh reconfirmed two factory xrefs to `ServerItemMenuDialog` (`0x0051762b`, `0x00517a5d`), two factory xrefs to `ClientItemMenuDialog` (`0x00517677`, `0x00517ae7`), and only the two client-dialog construction xrefs to `ClientItemMenuItemList` (`0x0051ba35`, `0x0051bf64`).
- A read-only PE reachability scan of `NexusTK.exe` found no direct call/branch, absolute VA dword, or RVA dword reference to the raw `ServerItemMenuItemList` start `0x0051ae90`, while IDA vtable refs still show inline server-list construction in `ServerItemMenuDialog` and modeled client-list construction in `ClientItemMenuDialog`.

## Ownership Notes

- `MerchantDialogPane` stays in [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md). Its [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) is referenced by item menu dialog vtables, but it is not item-menu-specific and is not the `ClientItemMenuDialog` command id `2` helper.
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) is the shared creator/dispatcher that can allocate the item-menu dialogs for packet subtypes `4` / `kServerItemMenu` and `5` / `kClientItemMenu`; keep ownership with the broader merchant/menu dialog family. The factory now emits formal first-draft C++ through [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), initializes `RectBounds` through `InitRectBounds`, and calls `ServerItemMenuDialog(const RectBounds& bounds, const unsigned char *payload, unsigned char menuMode)` or `ClientItemMenuDialog(const RectBounds& bounds, const unsigned char *payload, unsigned char menuMode)` as subtype targets rather than moving the dispatcher into this file.
- `ObjectImageControlPane`, `ImageButtonControlPane`, `StaticTextControlPane`, `ScrollableControlPane`, and `ListPane` are dependencies created by the dialogs, not file contents here.
- Historical / superseded class-generated `ServerItemMenuItemList` output included article/mail paging helpers and generic list-count helpers. IDA caller fanout proved those were not private item-menu list code, and the accepted UID0001BP formal source replaced that polluted snapshot; it is not a current migration blocker.
- B002 2026-06-18 reanalysis keeps `ServerItemMenuItemList` under this `ItemMenuDialogs` source family but warns against importing historical generated `class_ServerItemMenuItemList.cpp` wholesale. That output mixes true item-menu list virtuals with article/mail pagination helpers and shared `ListPane` helpers, omits raw item-menu helper bodies, and corrupts the event/help body. Source-facing reconstruction should use the [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) row layout and `g_pItemHelpPane` correction instead.
- Shared default dialog destructor note: `ServerItemMenuDialog` primary vtable `0x0061eea8` and `ClientItemMenuDialog` primary vtable `0x0061f008` use [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md); their secondary/tertiary slots route through [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md). This is compiler-generated deleting-destructor glue for the `DialogPane`-derived dialog objects; source reconstruction should declare/default the item-menu dialog destructors and rely on [UID:0000IT][DialogPane](by-file/DialogPane.md) for ordinary cleanup, not hand-port the wrapper.
- Historical / superseded class-generated `ClientItemMenuItemList` output treated `0x004f3b60` and `0x00520c20` as class destructors. IDA vtable/xref evidence instead establishes `0x004f3b60` as source-owned `ListPane::~ListPane()` cleanup and [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) as shared compiler-generated ABI glue also used by spell menu item-list vtables. For `ClientItemMenuItemList`, current source responsibility is an ordinary implicit/empty class destructor plus inherited `ListPane` cleanup; the old wrapper attribution is not imported into `ItemMenuDialogs.cpp`.

## ServerItemMenuItemList Destructor Source Responsibility

- Human-authored source in this file is the ordinary `ServerItemMenuItemList::~ServerItemMenuItemList()` body from UID0001BP exact `[0x0051af00,0x0051af35)`. The accepted source expresses the null-safe active-help cleanup as direct `delete g_pItemHelpPane;` followed by normal inherited `ListPane` teardown; no invented close helper or deleting-wrapper source is emitted.
- The ordinary body's exact SHA256 is `33D2282C2082BD8A9C26F862709936EC0BFD90FEB0ECBDF2A2EF53F5CD67039A`, with four predecessor and eleven successor `0xcc` bytes. Its first 47 semantic bytes match UID0001C2 after that wrapper's frame setup.
- Primary vtable `0x0061ef44` enters UID0001C2 directly. Secondary `0x0061efcc` and tertiary `0x0061effc` enter UID0001BZ adjustors that subtract `0xa0` and `0xa4` before tail-jumping to UID0001C2.
- UID0001C2's unsigned delete flags, optional MemoryMan-backed free, guarded `0x15c` complete-object path, returned `this`, manual vptr stores, and UID0001BZ's adjusted-`this` bodies are MSVC-generated ABI mechanics. Do not write any of them as methods or local helpers in `ItemMenuDialogs.cpp`.
- UID0001C2 remains class-owned reconstructable traceability evidence under UID0000D0, but its formal block is exactly a covered-by comment to UID0001BP. UID0001BZ remains false/no-owner/non-emitting. This preserves one plausible human source destructor while allowing the compiler to reproduce all three vtable entry routes.
- `ListPane`, `ItemHelpPane`, and MemoryMan remain dependencies, not source owners for the class destructor. No compiler-glue source file or new grouping is warranted.

## Rule 26 Source-Quality Notes

B002's 2026-06-19/20 report is incorporated as a split repair: [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) is a non-emitting index, [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md) and [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md) carry the server/client dialog method C++, and [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md) / [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md) carry the private row-list C++. This avoids duplicate emission from the aggregate and includes the adjacent client list sibling that starts after the `0x0051c46d-0x0051c470` padding.

- 2026-06-27 B015 rejected-report amendment support sync for [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md): keep this child emitted through `NexusTK/ui/dialogs/ItemMenuDialogs.cpp`, but treat [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md) as the canonical semantic owner. The formal C++ replacement preserves item-menu file routing while removing raw-helper overclaims: no `AppendAction` null-name fallback, no boolean selected/explicit send return, no selected upper-bound/null-entry guard, and no sent terminator byte beyond the explicit `QueueAndSendPacket(..., 9)` length.

Row layouts now used by this file:

| Row type | Size | Layout |
| --- | ---: | --- |
| `ServerItemMenuEntry` | `0x408` | `itemId` at `+0x000`, `itemStyle` at `+0x002`, reserved byte at `+0x003`, `value` at `+0x004`, `name[256]` at `+0x008`, `description[256]` at `+0x208`; no row `actionId`. |
| `ClientItemMenuEntry` | `0x206` | `actionId` at `+0x000`, reserved byte at `+0x001`, `itemId` at `+0x002`, `itemStyle` at `+0x004`, reserved byte at `+0x005`, `name[256]` at `+0x006`. |

Both families send opcode `0x39`, but their payload semantics differ. Server selected/explicit helpers send `m_packetSubtype`, `m_menuObjectId`, `m_menuOptionId`, and a selected/caller-supplied name string converted from wide text. Client selected/explicit helpers send the same context fields and a selected/caller-supplied `actionId`; B013 narrows the dialog-selected client action packet to length `9` and supersedes older trailing-null wording. Dialog command ids `1`, `2`, and `3` are separate from raw button construction constants `0x0e`, `0x10`, and `0x0f`.

B013's command split is retained with current identities: `ClientItemMenuDialog::OnControlCommand(1)` sends the selected action byte through opcode `0x39`, `OnControlCommand(2)` calls [UID:0004H8][0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket](by-memory/0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket.md) `MerchantDialogPane::SendMenuRequestPacket()` for the six-byte opcode `0x43` request, and `OnControlCommand(3)` closes. Broad [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md) remains an evidence/index range, while `0x00517d80` remains inherited action-string vtable glue. The client constructor parses subtype/object id/object-status/text/menu-option/action-entry payload data, resolves action entries through [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md), reads `active`, `itemId`, `iconStyle`, and `displayName` from the returned `LocalInventorySlotRecord`, and selects current `DLGMERC1.EPF`/`PAL01.PAL` or legacy `DLGMERC1.EPD`/`NPAL8.PAL` layout branches.

Dependency exclusions remain explicit: `Socket::QueueAndSendPacket`, `g_packetSender`, packet scalar readers/writers, `ObjectStatusBlob::ParseTaggedStatus`, `ListPane`, image/button/static-text/list-host controls, `MerchantDialogPane::SendMenuRequestPacket`, and `UserPane::GetInventorySlotAddress` are consumed by this file but owned by their existing support modules.

`ClientItemMenuDialog` consumes local inventory slots through [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md). The item-dialog source owner remains `ItemMenuDialogs.cpp`; the accessor and `LocalInventorySlotRecord` table are owned by class [UID:0000FQ][UserPane](by-class/UserPane.md) through file [UID:0000P1][UserPane](by-file/UserPane.md). Do not fold that table into item-menu row ownership. Historical LivingObjectPane ownership wording is superseded because the complete UserPane declaration and UID0003U9 formal source establish the local-player member route.

## 2026-08-22 UID0000KF Whole-File Completion

The accepted whole-file reconstruction resolves the old standalone-versus-folded uncertainty in favor of a distinct first-party `NexusTK/ui/dialogs/ItemMenuDialogs.cpp` with required sibling `ItemMenuDialogs.h`. The closed binary island, adjacent RTTI/vtables, two server and two client factory routes, private list construction, and exact `SpellMenuDialogs` successor outweigh the older domain-only argument for folding this code into `ItemDialogs.cpp`. This is reconstructed NexusTK source, not a vetted static-source import; no `third_party_embeds/...` directive applies.

### Complete authored inventory

| Range | Source entity | Route | Exact evidence |
| --- | --- | --- | --- |
| `[0x0051a520,0x0051ac8e)` | `ServerItemMenuDialog` constructor/parser/control build | UID00040D -> this file | SHA256 `2B5F553C39546294DB0A30F4C775A1E2E2D86504115738A1303A663ECC690E04`; callers `0x0051762b`, `0x00517a5d`. |
| `[0x0051acb0,0x0051ae42)` | server control command | UID00040D -> this file | SHA256 `3439930A2490A40FECDE544976683DB91EC8B5F04F2ECB4C6B130B1183D36925`; vtable cell `0x0061eef0`. |
| `[0x0051ae50,0x0051ae8d)` | server action-button update | UID00040D -> this file | SHA256 `3C428D79A18771C8F7E856EE19492B2BB9AAC1DD88BC8195330A4529DA6033A6`; vtable cell `0x0061eef4`. |
| `[0x0051ae90,0x0051aefc)` | retained server-list constructor | UID0001BP -> this file | SHA256 `DE9946C8F93E6F812302019EBFB13BF36C2E5C26EA022E47A501647272E0BBEA`; raw one-byte code head, zero direct start xrefs, inline-equivalent construction in the server dialog. |
| `[0x0051af00,0x0051af35)` | ordinary server-list destructor | UID0001BP -> this file | SHA256 `33D2282C2082BD8A9C26F862709936EC0BFD90FEB0ECBDF2A2EF53F5CD67039A`; source counterpart to UID0001C2 compiler wrapper. |
| `[0x0051af40,0x0051afbf)` | server `AppendItem` | UID0001BP -> this file | SHA256 `4ACA80BD90DBDB58C90C53A209ED8327B7D19CBCE0627CAC51ECBE7F317A4817`; raw retained body with two direct `_wcscpy_s` calls. |
| `[0x0051afd0,0x0051b0f8)` | server selected-name send | UID0001BP -> this file | SHA256 `59C25060299BF161CDBE3C2140CED8066D3F8365F34E7146A1791B9D72CC1FB3`; raw retained opcode `0x39` string sender. |
| `[0x0051b100,0x0051b18d)` | server selection override | UID0001BP -> this file | SHA256 `990C4DC58BFB23DD5DD2242251F26442A4E6A1A5D769245E29DA85A92794EDA1`; vtable cell `0x0061efbc`. |
| `[0x0051b190,0x0051b2a8)` | server explicit-name send | UID0001BP -> this file | SHA256 `5EC0351EE0C1E4296FFC5D1B7552BB5DC971346BB532FE6524BDC4EEDB9F12F8`; raw retained opcode `0x39` string sender. |
| `[0x0051b2b0,0x0051b2bb)` | server activation override | UID0001BP -> this file | SHA256 `18D2EAD01F66617879C1DE7CE0107A5886CC70C30C2425A9100AF7BF832661B5`; vtable cell `0x0061efc0`. |
| `[0x0051b2c0,0x0051b3e0)` | server mouse/help override | UID0001BP -> this file | SHA256 `E5213F9C16C6AEBC635BE2ACBB02A26146A4E56B3F0F39DB9078D8F743F494D9`; vtable cell `0x0061efa4`. |
| `[0x0051b3e0,0x0051b87a)` | server row draw override | UID0001BP -> this file | SHA256 `A58CE9420B288F8549FCE473327480DC38365215A4122C15BE7CA0CF456F8946`; vtable cell `0x0061efc4`. |
| `[0x0051b880,0x0051c30a)` | `ClientItemMenuDialog` constructor/parser/control build | UID00040E -> this file | SHA256 `549E0B6FA43C1D9A9E8B5C097CF523300E26AFB69A5FFE85CF89D089A94EBB7A`; callers `0x00517677`, `0x00517ae7`. |
| `[0x0051c310,0x0051c422)` | client control command | UID00040E -> this file | SHA256 `70C7D032FB71DC2512848A57C0CF7A382887771228F4FFFF9D560ACEAA32522D`; vtable cell `0x0061f050`. |
| `[0x0051c430,0x0051c46d)` | client action-button update | UID00040E -> this file | SHA256 `A430BF37374DDEC908E66E75E8958A0FFAE3CD1EAF600BF86F95DB6109F9A2BD`; vtable cell `0x0061f054`. |
| `[0x0051c470,0x0051c4dc)` | client-list constructor | UID0001BQ -> this file | SHA256 `C00DFF9C66B68B5FE6BEA454F683E0E4A358815AF8207D99639185A1334B0AA1`; calls at `0x0051ba35`, `0x0051bf64`. |
| `[0x0051c4e0,0x0051c548)` | client `AppendAction` | UID0001BQ -> this file | SHA256 `1CE275A806BBAAB2145189BE5D1DB844C70C15B27C102C723DB32094E8A06F82`; raw retained body. |
| `[0x0051c550,0x0051c603)` | client selected-action send | UID0001BQ -> this file | SHA256 `8B9BD3F8135D07B992061C58FAA1E79E4D2B614A1707BAFAFEC4D8E200AA6879`; fixed nine-byte send. |
| `[0x0051c610,0x0051c6ac)` | client explicit-action send | UID0001BQ -> this file | SHA256 `A7C1D460112F263F18667C28CA7AB7CDBB9236911226954A7887C5E064524F59`; fixed nine-byte send. |
| `[0x0051c6b0,0x0051c6bb)` | client activation override | UID0001BQ -> this file | SHA256 `5D47939801B9C4A7171F805D4AF67ED1EBE071E1F1A3A76B0EA06CD7BA8798EE`; vtable cell `0x0061f120`. |
| `[0x0051c6c0,0x0051ca3c)` | client row draw override | UID0001BQ -> this file | SHA256 `1F3D57650A37F69CF97049FCEC132F50B73F691E82BB7A00F9B496F41A050759`; vtable cell `0x0061f124`. |

The exact non-emitting alignment spans are `[0x0051ae8d,0x0051ae90)`, `[0x0051aefc,0x0051af00)`, `[0x0051b87a,0x0051b880)`, `[0x0051c30a,0x0051c310)`, `[0x0051c46d,0x0051c470)`, and `[0x0051ca3c,0x0051ca40)`. The authored family is `[0x0051a520,0x0051ca3c)`; `0x0051ca40` is the independent `SpellMenuDialogs` successor. The seven raw starts remain retained source bodies but are not to be defined as new IDA functions merely to improve naming.

### Declarations, layouts, and source order

- `ServerItemMenuEntry` is exactly `0x408`: `itemId +0`, `itemStyle +2`, reserved `+3`, `value +4`, `name[256] +8`, `description[256] +0x208`.
- `ClientItemMenuEntry` is exactly `0x206`: `actionId +0`, reserved `+1`, `itemId +2`, `itemStyle +4`, reserved `+5`, `name[256] +6`.
- Four H declarations are owned by UID0000CZ, UID0000D0, UID00002P, and UID00002Q at positions `5/20/30/40` in server-dialog/server-list/client-dialog/client-list order. UID0000CZ has one metadata position, `5`, governing both its CPP include preamble and H declaration; no separate H position `10` exists. Four definition children are UID00040D, UID0001BP, UID00040E, and UID0001BQ at CPP positions `10/20/30/40` in the same order, after the UID0000CZ position-`5` preamble.
- UID0001BO is a `94/95` false/non-emitting split index with blank source. UID00031Z is `94/96`, owner `NONE`, false/non-emitting compiler evidence with blank source. UID0001BZ, UID0001BW, UID0001C0, and UID0001C1 remain compiler-only; UID0001C2 retains only its covered-by comment to the ordinary UID0001BP destructor.

### Exact behavior and dependency closure

- Server command `1` sends a selected row name through opcode `0x39`, command `2` calls inherited `MerchantDialogPane::SendMenuRequestPacket()`, and command `3` closes. Client command `1` sends the selected action in a fixed nine-byte opcode `0x39` packet, command `2` uses the same inherited six-byte opcode `0x43` request, and command `3` closes.
- The server constructor uses `DLGMERC3.EPF`, button constants `14/16/15`, exact rectangles, object preview, description text, scroll host, hover control `6`, focus `1`, pending `3`, clamp bounds, and background resource. The client constructor preserves both `DLGMERC1.EPF`/`PA` and `DLGMERC1.EPD`/`NP` branches with their separate rectangles before the same hover/focus/pending/clamp sequence.
- Packet scalar reads/writes are owned by UID0000M8; `Socket::QueueAndSendPacket(const void *, short)` and `g_packetSender` by UID0000NS. Shared request state and code belong to UID000083/UID0004H8, with `m_menuDialogType +0x26c`, `m_menuObjectId +0x270`, and an exact six-byte send.
- `ScrollableControlPane(const RectBounds *, ScrollablePane *, int, int, int)` is class UID0000CE through file UID0000NE; UID00011G is only its non-emitting core index. `ObjectImageControlPane(const ObjectStatusBlob *, const RectBounds *)` is class UID00009O through file UID0000M3, with UID0001BU as its method child.
- Help uses the UID0000JU H/CPP route for class UID00006U and global UID0000R9. Drawing uses UID0000OC/UID0000TN `g_pfnFillRect`, existing GrafPort text APIs, and UID0000KH/UID00006W item-image APIs. No packet, layout, drawing, help, event, or image wrapper is invented locally.
- **File-owned data-island exclusion:** `ItemMenuDialogs.cpp` owns no global or static data island. The observed resource strings and layout/palette literals, compiler-emitted vtables and COL records, singleton pointers such as `g_pItemHelpPane` and `g_pItemObjImageLib`, render callback/global `g_pfnFillRect`, packet sender/global `g_packetSender`, and all other dependency data remain owned by their existing resource, compiler, support-file, or global routes. This module consumes those external symbols and literals but does not define, initialize, duplicate, or re-home them.

Rejected source forms remain explicit: no fold into generic `ItemDialogs`, no ownership transfer to `MerchantDialogPane`, `SpellMenuDialogs`, `ListPane`, factories, packet helpers, inventory lookup, or item-image modules; no raw vtable arrays or deleting-wrapper bodies; no decompiler interfaces such as `DrawContext`, `MenuEvent`, packet-view classes, null fallbacks, zero-initialized rows, synthetic owner-notify wrappers, or extra bounds/return guards that change binary behavior.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `94` | All 21 authored bodies, four declarations, two row layouts, six alignment spans, factory/vtable routes, packet/UI behavior, compiler-only exclusions, dependency owners, formal CPP/H destinations, and generated completion defects now have exact ordinary-documentation and source-channel dispositions. |
| Confidence | `94` | Live bounded IDA evidence, exact body hashes, class/vtable topology, factory and private-list reachability, current base/list declarations, and the hard SpellMenu successor agree on this narrow module. The score remains below final because original filename/private lexical spelling, compile/link parity, runtime equivalence, and byte-level parity are not yet proven. |

## Cross-References

- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:0000D0][ServerItemMenuItemList](by-class/ServerItemMenuItemList.md)
- [UID:00002P][ClientItemMenuDialog](by-class/ClientItemMenuDialog.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)
- [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md)
- [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md)
- [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md)
- [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0000L9][MerchantDialogPane](by-file/MerchantDialogPane.md)
- [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md)
- [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md)
- [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md)
- [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md)

## Changes

- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added the `ClientItemMenuDialog` dependency on `LocalInventorySlotRecord` lookup and kept server menu action rows separate.

### Historical/Superseded Checkpoints: 2026-05-30 Through 2026-06-20

The score transitions and evidence below remain useful chronology, but their possible `ItemDialogs.cpp` fold, fragmented generated-output reliance, and unresolved physical-source/final-name blocker conclusions are superseded. The 2026-08-22 whole-file closure established exactly 21 authored definitions and four declarations, a distinct first-party `ItemMenuDialogs.cpp` plus required `ItemMenuDialogs.h`, definition routes UID00040D/UID0001BP/UID00040E/UID0001BQ, and declaration owners UID0000CZ/UID0000D0/UID00002P/UID00002Q. The older `0/0`, `86/80`, `86/85`, `87/86`, and `88/89` values are historical intermediate scores, not current state; their still-valid function, caller, vtable, destructor, row-layout, and packet evidence remains supporting evidence for the accepted 94/94 route.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: server/client item menu dialog and list roles, vtable/layout anchor, raw helper caveats, creator/merchant base boundaries, and cross-references are documented; confidence is capped by possible folding into `ItemDialogs.cpp` and generated list-pane pollution.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/` so reviewed item-menu child pages can attach without autogen path errors.
- 2026-06-07 A001 Batch081 parent-gate refresh:
  - What existed before: `86/80`, with strong item-menu grouping but confidence capped by the standalone-versus-folded source-file question.
  - Changed to: `86/85`.
  - Summary/evidence: added live IDA confirmation for the client item-menu method ranges, factory callers, vtable stores, virtual rows, and exclusive coupling to `ClientItemMenuItemList`. The page now satisfies the strict direct-parent `85/85` gate for item-menu child classes while preserving the note that final physical source may fold into `ItemDialogs.cpp`.
- 2026-06-16 A001 file-confidence refresh:
  - What existed before: `86/85`, with good parent routing but the raw server-list constructor and current source-quality blocker evidence not refreshed on the file root.
  - Changed to: `87/86`.
  - Summary/evidence: live IDA MCP reconfirmed modeled server/client dialog functions, factory callers, client-list construction xrefs, vtable refs, and `0x0051ae90` as a raw non-function start; a read-only PE scan found no direct call/branch or VA/RVA pointer references to `0x0051ae90`. The remaining blocker is original physical source split (`ItemMenuDialogs.cpp` versus folded `ItemDialogs.cpp`) and final field/helper names.
- 2026-06-20 B001 Rule 26 source-quality sync: score unchanged. Clarified `ClientItemMenuItemList` destructor responsibility and rejected importing shared scalar deleting destructor wrapper [UID:0001C1][0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor](by-memory/0x00520c20-0x00520c5b.SharedListPaneScalarDeletingDestructor.md) as item-menu handwritten source.
- 2026-06-20 B002 Rule 26 split incorporation: raised to `88/89`; listed exact child method pages [UID:00040D][0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods](by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md) and [UID:00040E][0x0051b880-0x0051c46d.ClientItemMenuDialogMethods](by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md); kept [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md) as a non-emitting split index; incorporated corrected server/client row layouts, opcode `0x39` string-versus-action semantics, command-id versus button-constant separation, dedicated [UID:00031Z][ItemMenuDialogVtables](by-type/by-vtable/ItemMenuDialogVtables.md) vtable anchoring, and first-draft C++ routing through the exact memory children.

### Later Support History

- 2026-06-21 B013 `ClientItemMenuDialog` source-quality incorporation (historical/superseded in part): the pass correctly rejected `0x00517d80`, recorded client payload/layout branches and narrowed opcode `0x39` to a length-`9` action packet, but its `TextMenuDialog::SendMenuRequestPacket` attribution for `0x00517ec0` was later replaced by exact UID0004H8 `MerchantDialogPane::SendMenuRequestPacket` ownership after seven-caller and shared-layout evidence closed the route.
- 2026-06-28 B010 [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) support sync: score unchanged. Recorded subtype `4/5` factory creation through the `TextMenuDialogs.cpp` dispatcher, normalized constructor bounds wording to `RectBounds`, and preserved item-menu ownership only for the concrete item dialog/list classes.
- 2026-07-23 B001 UID0001C2 support synchronization: score/path unchanged at `88/89` and `NexusTK/ui/dialogs/`. Added exact UID0001BP ordinary-destructor ownership, hash/padding/parity, primary/secondary/tertiary route inventory, UID0001C2 formal covered-by behavior, and an explicit no-duplicate rule for scalar flags, operator-delete, guarded-size, vptr, and adjustor ABI lowering.
