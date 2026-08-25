*** UID:0000A4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000ME | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000ME | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// PanelPane method implementations are emitted by exact by-memory children.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Pane.h"

class PanelPane : public Pane
{
public:
    PanelPane();
    virtual ~PanelPane();
    virtual void OnActivate(const unsigned char *packetData) = 0;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PanelPane

## Status

- Confidence: very strong for direct `PanelPane : Pane` inheritance, no-new-field `0xf8` layout, behavior, all three vtable facets, RTTI, adjustor thunks, derived-pane caller fan-in, destructor routing, and UI-core ownership; historical physical source colocation remains inferential.
- Likely source file: [UID:0000ME][PanelPane](by-file/PanelPane.md)
- Main address doc: [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)
- Type docs: [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- Current recovered file label: `class_PanelPane.cpp` (non-authoritative generated naming only).
- IDA MCP rechecked: 2026-06-16.

## Functionality

`PanelPane` is a base panel container class that directly derives only from `Pane`. Pane already supplies the `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler` subobject chain; PanelPane does not repeat those classes as direct source bases. Its RTTI facet offsets are `+0xa0` and `+0xa4`, and both Pane and PanelPane have size `0xf8`, proving PanelPane adds no fields. It changes the virtual contract by introducing one pure activation hook.

[UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md) carries the source-ready constructor `PanelPane::PanelPane() : Pane(1) {}` and empty ordinary destructor `PanelPane::~PanelPane()`. Compiler lowering installs/restores the three vptrs, synthesizes scalar deleting and facet-adjustor wrappers, and emits RTTI/vtable data. Those artifacts remain declaration/ABI evidence rather than handwritten class-page implementations.

PanelPane introduces primary slot `+0x48` as the pure activation contract best declared `virtual void OnActivate(const unsigned char *packetData)`. Pane's inherited primary contract ends at `+0x44 OnPaint`; PanelPane extends it by one cell. Eight concrete panel families override this slot; some consume packet data and others ignore it while rebuilding or requesting state. This pointer contract supersedes the historical `bool showChild` interpretation, while behavior names such as `RebuildMessagePanes`, `RequestGroupList`, and `InitializeCollectionData` remain useful derived-method aliases. Inherited primary slot `+0x0c` remains `UpdateRenderRegion(const RectBounds *)`.

## RTTI Hierarchy And Layout

- [UID:0002OG][0x00621a6c-0x00621af8.PanelPaneVtableData](by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md) contains three PanelPane complete-object locators at `0x0064daf4`, `0x0064db08`, and `0x0064db1c`, all using type descriptor `0x00676e5c` (`.?AVPanelPane@@`) and hierarchy descriptor `0x006496bc`.
- The hierarchy descriptor has attribute `1`, six bases, and base array `0x006496cc`. Exact order is `PanelPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`.
- PMD `mdisp` values are `0` for the primary chain, `0xa0` for EventHandler, and `0xa4` for TimerHandler; all use `pdisp -1`, `vdisp 0`. This is direct `PanelPane : public Pane`, with both handler facets inherited through Pane.
- Current opaque IDA UDTs and the deleting-destructor guard both use `0xf8`; no PanelPane-specific field offset exists. The primary vtable adds `OnActivate` after Pane's endpoint, so the class changes behavior without changing object size.
- The current formal H declaration derives `PanelPane` directly from the complete emitted `Pane` declaration, declares the constructor, virtual destructor, pure `OnActivate(const unsigned char *packetData)` slot, and preserves `[[CHILDREN]]` for exact method children. No speculative fields or direct secondary bases are introduced.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x00545090-0x005450c2` | Source-ready in UID0001EC as `PanelPane::PanelPane() : Pane(1) {}`; compiler then installs panel vtables; IDA size `0x32` (50 bytes; Verified with int_convert.py). |
| destructor | `0x005450d0-0x005450ef` | Source-ready in UID0001EC as an empty `PanelPane::~PanelPane()`; compiler resets vtables and tail-jumps to base pane teardown; IDA size `0x1f` (31 bytes; Verified with int_convert.py); generated owner label is polluted. |
| adjustor thunks | `0x005450ef-0x00545105` | Two `0x0b`-byte IDA-confirmed thunks (11 bytes each; Verified with int_convert.py) forwarding to `0x00545110`. |
| scalar deleting destructor | `0x00545110-0x00545165` | Deleting destructor wrapper; IDA size `0x55` (85 bytes; Verified with int_convert.py), vtable data xref at `0x00621a70`. |

The exact inherited facets are not source methods owned by PanelPane, but they define its ABI: the primary view preserves Pane/base virtuals through `+0x44 OnPaint`; the secondary view carries EventHandler's pointer/key/IME/packet/system/type19/order/coordinate/acceptance contract; the tertiary view carries `Pane::OnTimer(int,int,int)`. Only primary `+0x48` is introduced by PanelPane.

## Derived-Use Evidence

UID0000KA whole-file closure adds two previously omitted concrete implementations to the derived activation evidence. Legacy `InventoryPane` primary slot `0x0061c7a0` targets `0x004ea280`, and `InventoryPane2` primary slot `0x0061c8b8` targets `0x004ee6d0`; both implement `void OnActivate(const unsigned char *)`, ignore the packet, and invalidate inherited embedded-pane bounds. The former `InventoryPane2::RefreshEmbeddedPane` spelling is superseded derived-method history, not a second slot or helper. This does not change PanelPane ownership, declaration, layout, or score.

IDA MCP xref checks on `0x00545090` now show sixteen direct constructor xrefs: thirteen modeled-function callers from inventory panes, options, self-look, group panes, collection, spell inventory, new system-message pane, and user-look/profile panes, plus three raw/no-function constructor bodies for `InventoryPane2` (`0x004ee65a`), `CollectionPane2` (`0x0056fd7a`), and `SpellInventoryPane2` (`0x0057ea6a`). That broad fan-in makes `PanelPane` a reusable UI-core base rather than a source file owned by any one feature module.

The scalar deleting destructor has no direct code callers; xrefs are vtable/thunk driven. `0x005450ef` and `0x005450fa` have vtable data xrefs at `0x00621ac0` and `0x00621af0` respectively.

IDA `list_globals` confirms the three `PanelPane` vtable bases at `0x00621a70`, `0x00621ac0`, and `0x00621af0`, with RTTI objects at `0x0064daf4`, `0x0064db08`, and `0x0064db1c`. The tertiary table is short: only `0x005450fa` and inherited slot `0x00544e90` belong to `PanelPane`; the next dword at `0x00621af8` begins neighboring `EditablePaperPane` RTTI metadata.

[UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md) now records the stronger 2026-06-01 IDA recheck: exact vtable-data dwords, constructor/destructor stores to all three views, `Pane` teardown in the non-deleting and scalar deleting destructor paths, and the neighboring RTTI boundary. [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md) records the two secondary/tertiary adjustor thunks as compiler-generated ABI glue, resolving the generated missing-code caveat for source ownership.

The 2026-07-13 B004 UID00015Y callback extends that type evidence with the exact eight-entry `+0x48` derived matrix and the `+0x0c` contract. It does not alter constructor/destructor ownership, object layout, raw vtable data, or compiler-generated wrapper/thunk dispositions.

## PanelPane-Introduced Activation Contract

- Pane's exact primary vtable spans 18 cells from `+0x00` through `+0x44 OnPaint`. Its next physical dword is secondary RTTI metadata, proving that Pane does not own `OnActivate`.
- PanelPane's primary vtable preserves those inherited 18 cells and adds one new `+0x48 -> __purecall` cell. That cell is the binary source cause for a pure virtual declaration on PanelPane itself.
- The strongest source-facing declaration remains `virtual void OnActivate(const unsigned char *packetData)`. The eight concrete implementations recorded by [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md) resolve the pointer argument and reject the historical `bool showChild` alternative.
- PhotoPane supplies independent negative evidence: it derives through Pane but not PanelPane, and its exact primary table ends at `+0x44 PhotoPane::OnPaint` with no activation slot.
- Historical correction: earlier documentation correctly recovered activation behavior and signature but described the cell as inherited from Pane. The behavioral evidence and derived aliases remain valid; source ownership is corrected to PanelPane.

## 2026-06-11 Live IDA Refresh

- `lookup_funcs` reconfirms constructor `0x00545090`, destructor `0x005450d0`, secondary/tertiary adjustor thunks `0x005450ef` and `0x005450fa`, scalar deleting destructor `0x00545110`, base teardown `0x00544580`, and successor `EditablePaperPane` constructor `0x00545170`.
- Constructor callers remain the same broad thirteen-site set: inventory, new inventory, option, self-look, group/group2/new-group, collection, self-look2, spell inventory, new spell inventory, new system-message, and user-look paths.
- Non-deleting destructor callers are broader cleanup paths across derived panel families; scalar deleting destructor has no ordinary direct callers and is reached through `0x005450ef`, `0x005450fa`, and the primary vtable slot.
- Disassembly confirms the object layout views: primary vptr at `+0x00`, secondary vptr at `+0xa0`, and tertiary vptr at `+0xa4`; `0xa0 = 160` and `0xa4 = 164` (Verified with int_convert.py).
- The scalar deleting destructor calls `Pane` teardown at `0x00544580`, then branches on delete flags for normal `operator delete` or vector-delete guard handling with size `0xf8 = 248` (Verified with int_convert.py).

## 2026-06-16 Live IDA Refresh

- `lookup_funcs` reconfirms constructor `0x00545090`, destructor `0x005450d0`, adjustor thunks `0x005450ef` and `0x005450fa`, scalar deleting destructor `0x00545110`, `Pane` constructor/teardown `0x00544460`/`0x00544580`, and successor `EditablePaperPane` constructor `0x00545170`.
- `xrefs_to 0x00545090` reports sixteen constructor xrefs. The three previously uncounted raw sites are already owned elsewhere: [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md), and [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md).
- `xrefs_to` reconfirms complete vtable-store triads for `0x00621a70`, `0x00621ac0`, and `0x00621af0`; `xrefs_to 0x00545110` remains limited to the two adjustor thunks plus the primary vtable slot.
- Raw-byte checks reconfirm `0x00545086-0x00545090` and `0x00545165-0x00545170` as `0xcc` alignment. The original standalone `PanelPane.cpp` versus adjacent `Pane.cpp` source grouping and inherited slot names remain class-level score caps, but they no longer block UID0001EC from emitting the constructor/destructor first draft.

## Score Rationale

| Metric | Score | Rationale |
| --- | ---: | --- |
| Completion | `90` | Exact constructor/destructor/thunk ranges, sixteen constructor xrefs, full 35-dword vtable map, six-base RTTI hierarchy, direct inheritance, no-new-field layout, inherited facet contracts, pure activation extension, compiler/source partition, and file route are documented. |
| Confidence | `93` | Exact memory/type children, live IDA, PMDs, store triads, Pane endpoint, and derived activation behavior agree. Confidence remains below final-source audit only because stripped original lexical/access spelling, a complete Pane header, and historical standalone-versus-colocated file layout are unavailable. |

## Data Caveats

- Historical disabled output marked `0x005450ef` as missing code even though IDA models it as a real thunk. That stale generated state is retained as history, not current evidence.
- Historical generated output used a `TextButtonExControlPane`-named base teardown. Exact disassembly proves Pane teardown, so the old owner label is superseded rather than a current blocker.

## Autogen Handling

Attach this class to [UID:0000ME][PanelPane](by-file/PanelPane.md). Both class and parent satisfy the current attachment gate, and the parent file has valid `NexusTK/ui/core/` placement. The formal CPP routing comment is followed by the explicit `[[CHILDREN]]` insertion point so UID0001EC's exact constructor/destructor and UID0002OG/UID0001YD's compiler-generated covered-by dispositions surface without duplicating method bodies or emitting literal vtable/RTTI data. Historical generated commands `000000019092` and `000000019152` retained only the routing comment because the insertion point was absent; that suppression was an emitter-composition defect, not an intended covered-by policy. Keep H blank until a coordinated pass emits a complete Pane base declaration; UID0001EC remains the exact lifecycle-method emitter.

## Cross References

- [UID:0000ME][PanelPane](by-file/PanelPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)
- [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)
- [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md)
- [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md)
- [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md)

## Changes

- 2026-07-29 B002 UID0002OG post-callback emitter-composition repair:
  - Added `[[CHILDREN]]` immediately after the existing class CPP routing comment. Historical generated commands `000000019092` and `000000019152` emitted only UID0000A4's routing comment because the nonblank class fragment lacked an explicit child insertion point; the generator therefore suppressed UID0001EC's constructor/destructor and UID0002OG/UID0001YD's covered-by comments.
  - Preserved all metadata, the existing routing comment, blank H, and every child formal. The expected CPP route now emits UID0001EC first, followed by UID0002OG and UID0001YD in stable blank-position first-seen path order. Literal vtable/RTTI/COL data remains intentionally compiler-generated and un-emitted.

- 2026-07-29 B002 UID0002OG accepted implementation callback:
  - Raised `86/88 -> 90/93`; retained canonical owner/emitter UID0000ME and reconstructable state.
  - Added the exact class-level CPP routing comment and kept H blank because no compile-ready Pane header exists; no partial class sample was inserted.
  - Incorporated the six-base RTTI/PMD proof, direct `PanelPane : Pane` source inheritance, inherited EventHandler/TimerHandler facets, no-new-field `0xf8` layout, full inherited ABI boundary, and PanelPane-introduced pure activation contract.
  - Historicalized broad claims that inherited slot identities/source grouping were unresolved and that generated missing-code/`TextButtonExControlPane` labels were current blockers. Exact physical original colocation remains a bounded historical uncertainty, not an ownership or emission blocker.

- 2026-07-26 Agent-B001 UID0003OU source-quality callback:
  - Preserved `86/88`, owner/emitter UID0000ME, constructor/destructor/thunk/layout/fan-in evidence, exact eight-derived activation matrix, and blank partial class formal.
  - Corrected `+0x48 OnActivate(const unsigned char *)` from an inherited Pane slot to a pure virtual introduced by PanelPane after Pane's `+0x44` endpoint.
  - Retained all valid signature and behavior research, added PhotoPane negative corroboration, and recorded the former ownership statement as historical rather than deleting it.

- 2026-07-13 B004 UID00015Y accepted callback: scores remain `86/88`; recorded inherited `UpdateRenderRegion(const RectBounds *)` and pure/common `OnActivate(const unsigned char *)` contracts plus the derived pointer-argument behavior, while preserving constructor/destructor evidence, compiler-generated vtables/wrappers/thunks, and the intentionally blank partial class formal block.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and left `AUTOGEN_PARENT_UID` blank.
  - Before: reconstruction autogen classification was blank even though the page documents a reusable NexusTK UI-core base class with constructor, destructor, adjustor thunks, scalar deleting destructor, vtable data, and broad derived-pane fan-in.
  - After: classified as reconstructable source but intentionally unassigned.
  - Evidence: live IDA MCP `lookup_funcs` confirms `0x00545090`, `0x005450d0`, `0x005450ef`, `0x005450fa`, and `0x00545110` as modeled `PanelPane` function/thunk starts; existing [UID:0000ME][PanelPane](by-file/PanelPane.md) evidence places the module under `NexusTK/ui/core/`. Parent attachment is deferred because this class has `CONFIDENCE:78` and the parent file has `CONFIDENCE:78`, below the 80/80 attach gate.

- Before: the `PanelPane` scalar deleting destructor and memory page ended at `0x00545164`.
- Changed to: both end at `0x00545165`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00545164` is the final operand byte of the destructor's `retn 4`.
- Before: completion/confidence metadata were `0/0` despite method map, derived-use evidence, vtables, RTTI, and generated-data caveats.
- Changed to: `COMPLETION:80` and `CONFIDENCE:78`.
- Evidence: constructor, destructor, adjustor thunks, scalar deleting destructor, broad derived-class fan-in, vtable data xrefs, and owner-label pollution are documented; confidence stays medium-high because destructor base-owner naming remains generated/polluted.
- 2026-06-06: Raised confidence to `84` and attached `AUTOGEN_PARENT_UID:0000ME`.
  - Evidence: [UID:0000ME][PanelPane](by-file/PanelPane.md) is now `84/84` with `NexusTK/ui/core/` placement; [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md) records exact vtable data, constructor/destructor stores, `Pane` teardown, and table boundary evidence; [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md) classifies the missing generated body as compiler-generated adjustor glue. The formal C++ block was still blank under the old final-source gate at that time; UID0001EC now emits the method bodies from the target page.
- 2026-06-11 A006 parent-gate refresh:
  - Before: `80/84`, attached under the older gate but below the current strict child-side completion/confidence threshold.
  - After: `85/86`, still attached to [UID:0000ME][PanelPane](by-file/PanelPane.md), which was refreshed to `85/86`.
  - Summary/evidence: live IDA MCP reconfirmed all function starts and sizes, thirteen constructor callers, broad derived cleanup callers for the non-deleting destructor, vtable/thunk-only scalar destructor dispatch, three object vptr offsets, complete vtable-store xrefs, direct `Pane` teardown, delete-flag behavior, vector-delete guard size, and the `EditablePaperPane` successor boundary. The class page still lacked formal C++ then because inherited virtual names and original file split were not final-audit quality; that history no longer blocks UID0001EC target emission.
- 2026-06-16 A002 source-quality refresh:
  - Before: `85/86`.
  - After: `86/88`.
  - Summary/evidence: live IDA MCP reconfirmed function/thunk boundaries, table-store triads, thunk/vtable-only scalar destructor dispatch, `Pane` constructor/teardown edges, and alignment bytes, and resolved the stale constructor-caller count by documenting sixteen total xrefs: thirteen modeled callers plus raw `InventoryPane2`, `CollectionPane2`, and `SpellInventoryPane2` constructor bodies. Owner/emitter remain [UID:0000ME][PanelPane](by-file/PanelPane.md); the class page still lacked formal declaration C++ pending inherited slot names and source grouping, while the 2026-07-06 callback now supplies target-level method bodies.
- 2026-07-06 B002 support sync:
  - Metadata and this class page's formal C++ remain unchanged.
  - Summary/evidence: accepted UID0001EC callback now emits `PanelPane::PanelPane() : Pane(1) {}` and empty `PanelPane::~PanelPane()` from the target memory page. Vptr stores, the existing [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md), scalar deleting wrapper, and vtable data remain compiler output/declaration evidence rather than handwritten class-page source.

## 2026-07-31 B002 Complete Fieldless Source Declaration

- `PanelPane` is an exact fieldless `Pane` subclass of size `0xf8`; it adds no storage beyond `Pane`.
- Its new source contract is one pure OnActivate(const unsigned char *packetData) primary virtual at +0x48, plus inherited Pane/EventHandler/TimerHandler facets and exact children.
- The formal H now expresses constructor, virtual destructor, pure activation slot, and child route. This enables derived NewGroupPane source without inventing fields or direct secondary bases.
- Score rises to 93/95; former blank-H/incomplete-base wording is retained only as historical pre-callback state.
