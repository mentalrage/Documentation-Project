*** UID:0000IC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CollectionPane

## Status

- Confidence: very strong for the main and alternate collection inventory panes, exact split/index routing, class-owned vtable/constructor/destructor anchors, and separation from `CollectionDialogPane.cpp`.
- Proposed module folder: `ui/panels/`
- Proposed source file: `ui/panels/CollectionPane.cpp`
- Companion file: [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- Evidence basis: existing source-layout docs plus IDA MCP boundary/decompilation checks through the 2026-06-12 Agent-A004 Batch 266 parent-gate audit.
- Source topology: UID00002X supplies the one file-root dependency preamble/child aggregator and complete `CollectionPane.h`; UID0003Y4/Y5/Y7/Y8/YA/YB/YC/YD/YE/YF emit complete method bodies, UID0003Y6 emits at position `70`, UID0003FA emits its covered-by marker at `75`, UID00038U emits one inert compiler-covered marker, and UID00002Y supplies the companion class declaration.

## Hypothesis

`CollectionPane.cpp` should own the in-game collection list panel shown inside the general purpose panel. It loads collection metadata, renders the five-row collection summary list, manages its `ScrollCollectionPane` child, opens the detailed collection dialog, and sends the request packet when a collection group is not loaded yet.

The detail dialog and its private controls are likely a companion source file rather than standalone one-class files. See [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md).

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md) | `0x0056e940-0x0056fe75` | split/index only | Non-emitting index over exact `CollectionPane` and `CollectionPane2` method children; not a single source body. |
| [UID:00002X][CollectionPane](by-class/CollectionPane.md) | exact children [UID:0003Y1][0x0056e940-0x0056e9e2.CollectionPaneConstructor](by-memory/0x0056e940-0x0056e9e2.CollectionPaneConstructor.md)-[UID:0003YF][0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot](by-memory/0x0056fbe0-0x0056fc73.CollectionPaneHitTestVisibleGroupSlot.md) plus [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md)/[UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md), vtable [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md), destructor [UID:00038Z][0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor](by-memory/0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor.md) | `class_CollectionPane.cpp` | Main five-row collection summary panel, metadata loader, scroll child owner, rectangle helpers, hit testing, input, packet-event false-return override, and collection-detail dispatch. |
| [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md) | exact children [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md)-[UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md) plus [UID:0003YG][0x0056fdd0-0x0056fe41.CollectionPane2OnPaint](by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md)-[UID:0003YI][0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0](by-memory/0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0.md), vtable evidence [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md), scalar-wrapper evidence [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md) | `CollectionPane.cpp` plus `CollectionPane.h` declaration | Lightweight alternate collection inventory frame renderer. The exact children emit constructor, empty destructor, `OnActivate`, `OnPaint`, and three EventHandler overrides; decorated vtables, adjustors, and scalar wrapper remain non-emitting compiler artifacts generated from the class declaration. |
| [UID:0003F1][0x00624a98-0x00624b30.CollectionPanePanelResourceStrings](by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md) | `[0x00624a98,0x00624b30)`, 152 bytes, SHA256 `09039478C0B4EDB0C3DF7B8D3C3EF15A73D7E7F66A7480D83C687BF4CB84FF19` | `CollectionPane.cpp` covered-by marker plus method-use literals | Eight compiler-pooled UTF-16 literals and two alignments with 14 refs across three CollectionPane methods and one CollectionPane2 method; no standalone source object or H declaration. |
| [UID:0003FA][0x00624c10-0x00624c20.CollectionPaneRectConstant](by-memory/0x00624c10-0x00624c20.CollectionPaneRectConstant.md) | `[0x00624c10,0x00624c20)`, 16 bytes, SHA256 `A9BC9BF25C41E884622F8CB1364E6835B7A59553F462E83CE6156E5721D9DB87` | `CollectionPane.cpp` position-75 covered-by marker plus OnPaint local aggregate | Exact `RectBounds rowBounds = { 6, 14, 161, 62 };` physical image with one xref at `0x0056ee7d`; no standalone object or H declaration. |
| [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) | `0x00561db0-0x0056325c` | `class_ScrollCollectionPane.cpp` | Generic EPF-backed scrollbar child. This is a dependency, not final collection ownership. |
| [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) | [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) alias/view | generated as `g_pCollectionData`, `g_pPlayerData`, and `g_collectionProgressTable` | Player-data block view used for collection group records. |

## Boundary Notes

- IDA MCP confirms real executable bodies from `0x0056e940` through `0x0056fe75`; the next function at `0x0056fe80` is `SelfLookPane2` and must not be merged into collection.
- IDA still does not mark `0x0056fd70` as a function, but raw IDA bytes show valid `CollectionPane2` constructor instructions from `0x0056fd70-0x0056fd9f`. Exact child [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md) now emits first-draft `CollectionPane2::CollectionPane2()` in this `CollectionPane.cpp` source family; the no-function/no-route evidence remains a confidence cap.
- The previous broad aggregate [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md) is now a non-emitting split/index; exact children cover the ordinary `CollectionPane` destructor body at `0x0056e9f0`, raw rectangle helpers at `0x0056fb60` and `0x0056fb80`, `CollectionPane2` render/stubs, and the existing helper/stub pages.
- Active generated output must preserve exact child responsibilities. [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md) supplies the formal class H declaration and CPP child insertion point; every source-bearing exact method child emits a body. UID00038U contributes only its compiler-covered marker because the complete class declaration and ordinary definitions regenerate its RTTI/COL/vtable group; adjustor and scalar-wrapper pages remain blank/non-emitting objects.
- UID00002X owns the complete main-class header and sole file-root CPP preamble, including direct `../core/Event.h` and `../../config/Config.h` dependencies. UID0003Y6's complete body uses the dependency-visible collection layout and metadata/render services, UID0003FA contributes only the position-75 no-object marker, and UID0003Y4/Y5/Y7/Y8/YA/YB/YC/YD/YE/YF contribute the ten completed lifecycle/layout/input/scroll/rectangle definitions. No named rectangle global/member/static is emitted.
- The sole cross-source access support is `friend class CollectionPane;` in the existing complete ScrollCollectionPane declaration. It permits only the evidenced `m_scrollPosition`/`m_scrollRange` reads and does not move ScrollCollectionPane source into this file.
- `0x0056fc80` is the key open/request helper: it checks `g_pUserPane` / `g_pCollectionData` typed view at `groupIndex * 0x2604 + 0x3ec8`, reads group volume/type at `+0x3ec9`, sends exact request bytes `0x27, 0, 1, groupVolumeId` with explicit length `4` and a local-only terminator when the group is not populated, or constructs `CollectionDialogPane(nullptr, groupVolumeId)` when data is ready and no dialog singleton is active. [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md) now emits first-draft `CollectionPane::OpenOrRequestGroupDetail(int groupIndex)` through [UID:00002X][CollectionPane](by-class/CollectionPane.md); packets must not send `groupIndex`, and the method does not belong to `CollectionDialogPane.cpp` or the broad aggregate.
- [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) now has first-draft source as `CollectionPane::HandlePacketEvent(Event *event)`, emitted through [UID:00002X][CollectionPane](by-class/CollectionPane.md) in this `CollectionPane.cpp` source family. It is the secondary `EventHandler` offset `+0x10` packet-event false-return override, not a standalone helper or `CollectionPane2` slot.
- [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md) now has first-draft source as `CollectionPane2::CollectionPane2()`, emitted through [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md) in this same `CollectionPane.cpp` source family. Current MCP maps the body as `PanelPane::PanelPane()` plus compiler-generated primary/secondary/tertiary `CollectionPane2` vptr stores at `+0`, `+0xa0`, and `+0xa4`. The raw-start no-function/no-xref/no-pointer/no-rel32 route evidence caps confidence but does not justify a blank exact-child constructor.
- [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md) emits an empty `CollectionPane2::~CollectionPane2()` through [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md) in this `CollectionPane.cpp` source family. MCP session `b001_000241_20260627` maps the exact body to compiler-generated vptr restores at `+0`, `+0xA0`, and `+0xA4`, followed by implicit `PanelPane` teardown. The zero direct ordinary-entry xrefs do not justify blank source; the sibling EventHandler names are now resolved, and scalar/delete flag logic remains isolated in non-emitting [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md).
- [UID:0001HI][0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk](by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md) emits `void CollectionPane2::OnActivate(const unsigned char *packetData)` through [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md) in this same `CollectionPane.cpp` family. Current PanelPane primary slot `+0x48` supplies the source contract; the body ignores packet data and calls inherited `Pane::InvalidateRect` at `+0x20` with `this+0x44` / `m_bounds`. Historical `InvalidateOwnBounds(int flags)` wording is superseded.
- [UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md) now has first-draft source as `CollectionPane2::HandlePacketEvent(Event *event)`, emitted through [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md) in this same `CollectionPane.cpp` source family. Current MCP maps `0x006246cc` as the `CollectionPane2 +0xa0` secondary `EventHandler` offset `+0x10`, the packet-event false-return slot.
- 2026-05-25 IDA MCP recheck reconfirmed `0x0056fd70` is still not a modeled function, while `0x0056f800`, `0x0056fc80`, `0x0056fda0`, `0x0056fdc0`, and `0x0056fe70` are modeled functions with exact pages.
- 2026-06-11 Agent-A001 live IDA MCP reconfirmed the file family boundary before `SelfLookPane2` at `0x0056fe80`, `CollectionPane` constructor caller `0x004b851f`, `CollectionPane2` raw constructor bytes at `0x0056fd70-0x0056fd9f`, and exact scalar deleting destructor function/data/thunk evidence for [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md) and [UID:00038Z][0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor](by-memory/0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor.md).
- 2026-06-12 Agent-A004 live IDA MCP reconfirmed the file-owned `CollectionPane` vtable child [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md): three COL/vtable views at `0x006245dc`, `0x0062462c`, and `0x0062465c`; constructor stores at `0x0056e97c`, `0x0056e982`, and `0x0056e98c`; destructor stores at `0x0057337c`, `0x00573382`, and `0x0057338c`; and successor boundary `0x00624668` for `CollectionPane2`.
- 2026-06-12 Agent-A004 Batch 266 live IDA MCP reconfirmed the file-owned `CollectionPane2` vtable child [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md): three COL/vtable views at `0x00624668`, `0x006246b8`, and `0x006246e8`; raw-constructor stores at `0x0056fd7f`, `0x0056fd87`, and `0x0056fd91`; destructor-body stores at `0x0056fda0`, `0x0056fda6`, and `0x0056fdb0`; scalar deleting destructor stores at `0x00573316`, `0x0057331c`, and `0x00573326`; and successor boundary `0x006246f4` for `SelfLookPane2`.
- 2026-06-17 B001 source-quality report confirmed the source placement remains `NexusTK/ui/panels/CollectionPane.cpp`, not `CollectionDialogPane.cpp`, and that `ScrollCollectionPane` remains a dependency rather than collection-private ownership. It also identified the aggregate memory page as a split/index and added exact child pages for all previously hidden raw bodies and vtable stubs.

## Read-Only Data Anchors

| Range | Owner | Notes |
| --- | --- | --- |
| [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md) | [UID:00002X][CollectionPane](by-class/CollectionPane.md) | Exact `CollectionPane` primary/secondary/tertiary vtable group, now routed to the class after Batch 262 direct-parent audit. |
| [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md) | semantic class [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md) | Exact primary/secondary/tertiary vtable and COL evidence. Non-reconstructable/non-emitting compiler data; human source is the class declaration and virtual method children. |

## CollectionPane2 Source And Header Topology

- Source root remains `NexusTK/ui/panels/CollectionPane.cpp`; a companion `CollectionPane.h` declaration is represented by the formal H channel on [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md).
- `CollectionPane2` is a no-new-fields `PanelPane` derivative of exact size `0xF8`, with `EventHandler` and `TimerHandler` facets at `+0xA0` and `+0xA4`.
- The explicit virtual destructor declaration and ordinary empty definition [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md) are the source cause of non-emitting scalar wrapper [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md), adjustors [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md), and vtable data [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md).
- Primary virtuals are `OnPaint` and `OnActivate`; secondary local overrides are `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, and `HandlePacketEvent`. All three EventHandler overrides return false.
- A separate scalar-wrapper source file, direct vtable C++ definitions, aggregate-wrapper emission, and placement in `Pane.cpp` or `CollectionDialogPane.cpp` are rejected because they do not match human source ownership.

## UID0003F1 Pooled Literal Topology

- Exact data child [UID:0003F1][0x00624a98-0x00624b30.CollectionPanePanelResourceStrings](by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md) is the 152-byte run SHA256 `09039478C0B4EDB0C3DF7B8D3C3EF15A73D7E7F66A7480D83C687BF4CB84FF19`. It partitions into eight terminated UTF-16 literals, `L"Collections"`, `L"GroupNames"`, `L"CLTINV.EPF"`, `L"CLTLIST.EPF"`, `L"CLTLIST.PAL"`, `L"\xC548\xB098\xC640"`, `L"%d %%"`, and `L"%d/%d"`, plus two two-byte zero alignments.
- All 14 refs are method-use expressions in this file: [UID:0003Y3][0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData](by-memory/0x0056ea30-0x0056ec44.CollectionPaneInitializeCollectionData.md) uses `Collections` twice and `GroupNames` twice; [UID:0003Y6][0x0056edc0-0x0056f655.CollectionPaneOnPaint](by-memory/0x0056edc0-0x0056f655.CollectionPaneOnPaint.md) uses `GroupNames`, all three CLT resource/palette names, the Korean fallback, and both formats; [UID:0003Y9][0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords](by-memory/0x0056f810-0x0056fa8a.CollectionPaneLoadCollectionGroupRecords.md) uses `Collections` twice; [UID:0003YG][0x0056fdd0-0x0056fe41.CollectionPane2OnPaint](by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md) shares `CLTINV.EPF` once. Counts by literal are exactly `4, 3, 2, 1, 1, 1, 1, 1`.
- Cross-class pooling is why file UID0000IC remains canonical owner/emitter. The source-facing route is repeated literals at those four methods plus UID0003F1's no-object covered-by marker in `NexusTK/ui/panels/CollectionPane.cpp`. There is no named array, table, global, member, package object, duplicate resource object, or target declaration in `CollectionPane.h`.
- Dated pre-callback generated baseline command `000000024278`, timestamp `2026-08-15T08:55:03-04:00`, produced `CollectionPane.cpp` SHA256 `8630E0BE4E4F96DF84D37CEB8B69B450B8CCEED152DB22E38C8DD49ECB74E134`, 3,417 bytes/89 lines, with UID0003F1 empty; the matching H was SHA256 `0057CB7FD98200F98460E4D359BC079113179DABC642B85107FDCABBC9BE8742`, 856 bytes/24 lines, with no target data declaration.

### 2026-07-29 IDA Analysis Reconciliation

Supervisor catalog entry `0349` applied and read back the corresponding analysis layer while preserving the file boundary and source topology above. The current IDA identities are `CollectionPane2__Destructor` at `0x0056FDA0`, `CollectionPane2__OnActivate` at `0x0056FDC0`, `CollectionPane2__OnPaint` at `0x0056FDD0`, `CollectionPane2__HandleKeyOrTextEvent` at `0x0056FE50`, `CollectionPane2__HandlePointerOrMouseEvent` at `0x0056FE60`, `CollectionPane2__HandlePacketEvent` at `0x0056FE70`, `CollectionPane2__ScalarDeletingDestructorAdjustorA0` at `0x00573247`, `CollectionPane2__ScalarDeletingDestructorAdjustorA4` at `0x00573252`, and `CollectionPane2__ScalarDeletingDestructor` at `0x00573310`. `PanelPane__Destructor` at `0x005450D0` is the applied base-teardown identity.

The read-back declarations preserve the source split: authored children use `void __thiscall CollectionPane2__Destructor(CollectionPane2 *this)`, `void __thiscall CollectionPane2__OnActivate(CollectionPane2 *this, const unsigned __int8 *packetData)`, `void __thiscall CollectionPane2__OnPaint(CollectionPane2 *this)`, and three physical `bool __thiscall(...EventHandler *this, void *event)` callback signatures. The scalar wrapper and its two facet adjustors use `CollectionPane2 *` returns plus `unsigned int deletingFlags` and remain compiler artifacts. Function-regular comments now record the empty destructor source cause, `OnActivate` bounds invalidation, paint resources/path, false-return callback roles, facet offsets, scalar deleting bits `1`/`4`, and `0xF8` object size; function-repeatable and entry comment channels remain blank, including removal of the two stale adjustor entry comments.

IDA now also contains analysis UDT `CollectionPane2`, size `0xF8`, with only `_base : PanelPane` at offset `0`. This reinforces the no-new-fields declaration but does not authorize hand-written vptrs, adjustors, scalar-wrapper code, or vtable globals. Decorated COL/vtable identities, exact ranges/bytes/xrefs/padding, dependency types, internal target comments, and unrelated entities were preserved. The saved IDB checkpoint is SHA256 `B46BEB1B347B569129E0B9F9BB53C51E4560EF6249081256D31EAC53A95F1A41`, size `143190134` bytes, last write `2026-07-29T02:03:25.4572488-04:00`.

## Current Score Rationale

- Completion `94`: source/header topology, complete CollectionPane and CollectionPane2 class routes, all fourteen source-bearing CollectionPane consumer/member bodies, dependency-closed OnPaint, both pooled-data covered-by routes, compiler-covered UID00038U handling, data anchors, and historical source-name corrections are incorporated. The waited owning-page readback is required to show `27/27/0` with no affected empty or comment-only placeholder.
- Confidence `94`: current vtable, destructor, size, method-slot, resource, rectangle-local provenance, dependency-header, bounded ten-body hashes, and source-family evidence agree. Exact original header filename and private spelling remain inferred but do not affect behavior or ownership.

## Data Layout

The collection feature uses a view over the large player-data block:

- group record stride: `0x2604`;
- per-entry record stride: `0x4c`;
- group active/loaded flag at record `+0x3ec8`;
- group type/volume at record `+0x3ec9`;
- total entry count at record `+0x3eca`;
- collected entry count at record `+0x3ecb`;
- global collection group count at `+0x1340c8`.

See [UID:0001TZ][CollectionPlayerDataLayout](by-type/by-struct/CollectionPlayerDataLayout.md).

## Migration Notes

Create the main file before attaching classes:

```powershell
python source-3\wave3.py create file CollectionPane.cpp --kind source --simpath ui/panels/CollectionPane.cpp --dry-run
python source-3\wave3.py attach class CollectionPane --to-file CollectionPane.cpp --dry-run
python source-3\wave3.py attach class CollectionPane2 --to-file CollectionPane.cpp --dry-run
```

Do not attach [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md) here unless a later scroll-control pass proves it was collection-private. Current evidence favors a generic `ui/core/ScrollCollectionPane.cpp` or a merge into `ScrollBar.cpp`.

## Cross-References

- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md)
- [UID:0000IB][CollectionDialogPane](by-file/CollectionDialogPane.md)
- [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md)
- [UID:0003Y1][0x0056e940-0x0056e9e2.CollectionPaneConstructor](by-memory/0x0056e940-0x0056e9e2.CollectionPaneConstructor.md)
- [UID:0003Y2][0x0056e9f0-0x0056ea25.CollectionPaneNonDeletingDestructor](by-memory/0x0056e9f0-0x0056ea25.CollectionPaneNonDeletingDestructor.md)
- [UID:0003YD][0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw](by-memory/0x0056fb60-0x0056fb7a.CollectionPaneSetInvalidGroupSlotRectRaw.md)
- [UID:0003YE][0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw](by-memory/0x0056fb80-0x0056fbd3.CollectionPaneGetVisibleGroupSlotRectRaw.md)
- [UID:0003YG][0x0056fdd0-0x0056fe41.CollectionPane2OnPaint](by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md)
- [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md)
- [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md)
- [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md)
- [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md)
- [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md)
- [UID:00038Z][0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor](by-memory/0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor.md)
- [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md)
- [UID:0001R8][collection-ui-resources](by-resource/collection-ui-resources.md)
- [UID:0003F1][0x00624a98-0x00624b30.CollectionPanePanelResourceStrings](by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md)
- [UID:0003FA][0x00624c10-0x00624c20.CollectionPaneRectConstant](by-memory/0x00624c10-0x00624c20.CollectionPaneRectConstant.md)

## Changes

- 2026-08-16 Agent-B008 UID0003FA completion callback: incorporated complete CPP bodies for UID0003Y4/Y5/Y7/Y8/YA/YB/YC/YD/YE/YF, direct Event/Config dependencies, the narrow ScrollCollectionPane friend route, and UID00038U's inert compiler-covered marker. The complete source contract is 27 total / 27 filled / 0 empty; current physical truth is taken from the callback's waited owning-page readback rather than any older fixed command.
- 2026-08-16 Agent-B008 UID0003FA accepted callback, historical pre-completion stage: raised `92/93 -> 94/94`, added the complete UID00002X source/header route, position-70 dependency-closed OnPaint body, position-75 UID0003FA local-aggregate marker, exact rectangle provenance, and unified class/file topology. That dated refresh registered ten previously absent signature-only children whose CPP channels still carried explicit no-body dispositions; its `27/26/1` result and empty UID00038U state are superseded by the completion callback above. Physical callback truth is taken from the latest supervisor-verified waited readback rather than pinned to a dated command.
- 2026-08-15 Agent-B002 UID0003F1 accepted callback: added the exact eight-literal/14-use cross-class pool, no-object CPP/H topology, target ownership, and dated generated baseline while preserving `92/93` and all existing class/method source routes.
- 2026-07-29 B003 UID00038Y implementation callback:
  - Raised from `90/90` to `92/93` and documented `CollectionPane.cpp` plus companion `CollectionPane.h` source topology.
  - Corrected the CollectionPane2 method route to `OnActivate`, resolved the two remaining EventHandler false-stub names, and recorded the complete no-new-fields class declaration route.
  - Reclassified UID00038Y, UID00023Y, and UID00038V as non-emitting compiler artifacts whose source cause remains in the class and ordinary method children. Earlier `InvalidateOwnBounds` and blank-class-header statements below are preserved as superseded history.

- 2026-06-12 Agent-A004 Batch 266: Raised from `88/87` to `89/88`.
  - Before: the file page named [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md) as a candidate-only sibling pending audit.
  - After: documented it as exact class-owned `CollectionPane2` read-only data, recorded the raw constructor's class-level route, and refreshed `CollectionPane2` constructor/destructor/vtable boundary evidence.
  - Evidence: live IDA MCP `py_eval` against NexusTK.exe md5 `4247e04e20b65d6414c7238aa8ff5515`; `tools/int_convert.py` verified the `0x8c`, `0x50`, `0x30`, `0x0c`, `0xa0`, `0xa4`, and `0x55` values used by the `CollectionPane2` route.
- 2026-06-17 B001 report execution: Raised from `89/88` to `90/90`.
  - Updated [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md) from a broad reconstructable range to a non-emitting split/index and linked the exact `CollectionPane`/`CollectionPane2` child pages.
  - Confirmed `CollectionPane.cpp` source placement, `CollectionDialogPane.cpp` separation, `ScrollCollectionPane` dependency status, and no aggregate C++ emission policy.
- 2026-06-25 B002 implementation callback:
  - Score unchanged at `90/90`.
  - Recorded that [UID:0001HE][0x0056f800-0x0056f805.CollectionPaneFalseStub](by-memory/0x0056f800-0x0056f805.CollectionPaneFalseStub.md) now emits first-draft `CollectionPane::HandlePacketEvent(Event *event)` C++ through the `CollectionPane` class route in this source file.
  - Evidence: current MCP dispatcher and secondary-vtable proof identifies `0x00624640 -> 0x0056f800` as `EventHandler` packet-event slot `+0x10` / event type `18`, with an always-false body.
- 2026-06-26 B002 implementation callback:
  - Score unchanged at `90/90`.
  - Recorded that [UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md) now emits first-draft `CollectionPane2::HandlePacketEvent(Event *event)` C++ through the `CollectionPane2` class route in this source file.
  - Evidence: MCP session `80de0a67` decoded `CollectionPane2 +0xa0` secondary slot `0x006246cc -> 0x0056fe70` as `EventHandler` offset `+0x10`; `EventDispatcher::CallHandler` routes packet events, exact type `18`, to that offset.
- 2026-06-26 B010 implementation callback:
  - Score unchanged at `90/90`.
  - Recorded that [UID:0001HI][0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk](by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md) now emits first-draft `CollectionPane2::InvalidateOwnBounds(int flags)` C++ through the `CollectionPane2` class route in this source file.
  - Evidence: MCP session `80de0a67` decoded `0x006246b4 -> 0x0056fdc0` as primary slot `+0x48`; inherited slot `0x0062468c -> 0x00544800` is `Pane::InvalidateRect`, and the body passes `this+0x44` / `m_bounds`. `Pane.cpp`, inventory ownership, and a new source file are rejected because they do not own this `CollectionPane2` primary vtable slot.
- 2026-06-26 B010 implementation callback for [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md):
  - Score unchanged at `90/90`.
  - Recorded that [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md) now emits first-draft `CollectionPane2::CollectionPane2()` C++ through the `CollectionPane2` class route in this source file.
  - Evidence: MCP session `80de0a67` confirmed the exact raw constructor bytes, `PanelPane::PanelPane()` base call, primary/secondary/tertiary `CollectionPane2` vptr stores, destructor/scalar-destructor lifecycle, and route-negative confidence cap. `PanelPane.cpp`, `SelfLookPane2`, vtable-data ownership, no-owner treatment, and a new source file are rejected for this `CollectionPane2` constructor child.
- 2026-06-27 B002 implementation callback:
  - Score unchanged at `90/90`.
  - Recorded that [UID:0001HF][0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail](by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md) now emits first-draft `CollectionPane::OpenOrRequestGroupDetail(int groupIndex)` C++ through the `CollectionPane` class route in this source file.
  - Evidence: accepted MCP session `80de0a67` tied the exact child to the input-handler caller at `0x0056f7a7`, the `g_pUserPane` collection group offsets `0x2604/+0x3ec8/+0x3ec9`, request bytes `0x27,0,1,groupVolumeId` length `4`, and the loaded branch constructor call `CollectionDialogPane(nullptr, groupVolumeId)`.
- 2026-06-27 B003 implementation callback:
  - Score unchanged at `90/90`.
  - Recorded that [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md) now emits first-draft empty `CollectionPane2::~CollectionPane2()` C++ through the `CollectionPane2` class route in this source file.
  - Evidence: MCP session `b001_000241_20260627` confirmed the exact `0x1f` / 31-byte ordinary destructor, unique bytes, `0xcc` successor alignment, zero direct ordinary-entry xrefs, three compiler-generated `CollectionPane2` vptr restores, tail jump to `PanelPane::~PanelPane()`, and scalar/delete wrapper separation in [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md). `CollectionPane.cpp` remains the source family; no separate `PanelPane`, `SelfLookPane2`, inventory, or vtable-data owner is introduced for this destructor.
- 2026-06-12 Agent-A004 Batch 262: Raised from `87/86` to `88/87`.
  - Before: the file parent cleared the strict gate but only carried destructor-oriented evidence for the `CollectionPane` class.
  - After: added the exact class-owned vtable child [UID:00038U][0x006245dc-0x00624668.CollectionPaneVtableData](by-memory/0x006245dc-0x00624668.CollectionPaneVtableData.md), documented the adjacent `CollectionPane2` sibling as a separate audit, and refreshed constructor/destructor vtable-store evidence.
  - Evidence: live IDA MCP `py_eval` against NexusTK.exe md5 `4247e04e20b65d6414c7238aa8ff5515`; `tools/int_convert.py` verified the `0x8c`, `0x50`, `0x30`, `0x0c`, `0xa0`, and `0xa4` values used by the child route.
- 2026-06-11 Agent-A001 Batch 186 continuation: Raised from `86/84` to `87/86`.
  - Before: file confidence sat below the strict parent gate even after the main/alternate collection pane route was documented.
  - After: linked the exact destructor children [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md) and [UID:00038Z][0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor](by-memory/0x00573370-0x005733d7.CollectionPaneScalarDeletingDestructor.md), refreshed live boundary/caller/destructor evidence, and accepted this file as the direct reconstruction parent for both collection pane classes.
  - Evidence: live IDA MCP `lookup_funcs`, `callers`, `xrefs_to`, `disasm`, and decompile/callee evidence from 2026-06-11.
- Before: file-level destructor ranges were listed only as start addresses.
- Changed to: `CollectionPane` and `CollectionPane2` now point to the exact IDA destructor endpoints and the new adjustor/destructor memory docs.
- Evidence: 2026-05-28 IDA MCP reports `sub_573310` as `0x00573310-0x00573365`, `sub_573370` as `0x00573370-0x005733d7`, and four collection adjustor thunks at `0x00573247-0x00573273`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: main collection pane role, companion dialog split, class/global/data-layout ownership, exact boundary notes, omitted helper functions, migration plan, and resource/data cross-references are documented; confidence remains below maximum because final split versus `CollectionDialogPane.cpp` is still provisional.
- 2026-06-01 path/scoring update:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:84`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/"`.
  - Evidence: existing proposed-source-tree placement, IDA MCP caller evidence from `GeneralPurposePanel` at `0x004b851f`, and the confirmed executable family ending before `SelfLookPane2` at `0x0056fe80`.
  - C++ reconstruction remains deferred because helper names, base/interface labels, and the `CollectionPane`/`CollectionPane2` source split are not final-source quality.
