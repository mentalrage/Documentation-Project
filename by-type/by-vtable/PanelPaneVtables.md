*** UID:0001YD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000A4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000A4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this vtable family is covered by [UID:0000A4][PanelPane](by-class/PanelPane.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PanelPane Vtables

## Status

- Disposition: vtable inventory for reconstructable UI-core panel base code.
- Covered source owner: [UID:0000ME][PanelPane](by-file/PanelPane.md)
- Covered class: [UID:0000A4][PanelPane](by-class/PanelPane.md)
- Exact vtable-data range: [UID:0002OG][0x00621a6c-0x00621af8.PanelPaneVtableData](by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md)
- Confidence: very strong for all 35 backing dwords, three COLs, six-base RTTI hierarchy, inherited facet offsets, complete slot identities, lifecycle stores, exact child range, compiler/source partition, and class ownership.
- Verification: IDA MCP `list_globals`, `xrefs_to`, `lookup_funcs`, `disasm`, `callers`, `callees`, and `py_eval` checks on 2026-05-26; IDA MCP `py_eval` recheck of exact vtable-data dwords, boundaries, data xrefs, and thunk/function extents on 2026-06-01.
- Autogen parent: [UID:0000A4][PanelPane](by-class/PanelPane.md). This page is `93/96`, and the accepted class update is `90/93`, so the strict child/direct-parent gate is satisfied.

## Table Bases

| Object offset | Vtable symbol | Address | First slot | Notes |
| --- | --- | --- | --- | --- |
| `+0x00` | `??_7PanelPane@@6B@` | `0x00621a70` | `0x00545110` | Primary `Pane` view; scalar deleting destructor followed by inherited pane virtuals. |
| `+0xa0` | `??_7PanelPane@@6B@_0` | `0x00621ac0` | `0x005450ef` | Secondary inherited EventHandler-facet view; destructor adjustor subtracts `0xa0`. |
| `+0xa4` | `??_7PanelPane@@6B@_1` | `0x00621af0` | `0x005450fa` | Tertiary inherited TimerHandler-facet view; destructor adjustor subtracts `0xa4`. |

## RTTI Hierarchy And Source Inheritance

- Primary, secondary, and tertiary complete-object locators are at `0x0064daf4`, `0x0064db08`, and `0x0064db1c`. Each is 20 bytes with signature `0`, `cdOffset 0`, type descriptor `0x00676e5c` (`.?AVPanelPane@@`), and class-hierarchy descriptor `0x006496bc`; their object offsets are `0`, `0xa0`, and `0xa4`.
- The hierarchy descriptor has multiple-inheritance attribute `1`, six bases, and base array `0x006496cc`. The descriptor order is `PanelPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`; all use `pdisp -1`/`vdisp 0`, with `mdisp 0` for the primary chain, `0xa0` for EventHandler, and `0xa4` for TimerHandler.
- This proves the source declaration directly derives only from Pane. EventHandler and TimerHandler are inherited Pane facets; they are not duplicate direct bases to add to PanelPane source.
- The scalar-delete guard size and current opaque UDT are both `0xf8`. Pane is also `0xf8`, so PanelPane adds no data fields and changes only the virtual contract.

## Slot Evidence

The exact physical map includes all three COL-pointer dwords and all 32 callable cells:

| Address | View/slot | Target | Source interpretation |
| --- | --- | --- | --- |
| `0x00621a6c` | primary COL | `0x0064daf4` | PanelPane complete-object locator, offset `0`. |
| `0x00621a70` | primary `+0x00` | `0x00545110` | Compiler scalar deleting destructor. |
| `0x00621a74` | primary `+0x04` | `0x004f4b10` | `LObject::GetRuntimeClass()`. |
| `0x00621a78` | primary `+0x08` | `0x0041b6c0` | `LObject::OnChangeMessage(LObject *, Message *)`. |
| `0x00621a7c` | primary `+0x0c` | `0x004b8e20` | `Pane::UpdateRenderRegion(const RectBounds *)`. |
| `0x00621a80` | primary `+0x10` | `0x0041d680` | no-op `Pane::DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)`. |
| `0x00621a84` | primary `+0x14` | `0x00544730` | `Pane::Show()`. |
| `0x00621a88` | primary `+0x18` | `0x00544750` | `Pane::Hide()`. |
| `0x00621a8c` | primary `+0x1c` | `0x005447a0` | `Pane::GetParentPane()`. |
| `0x00621a90` | primary `+0x20` | `0x00544800` | `Pane::InvalidateRect()` path. |
| `0x00621a94` | primary `+0x24` | `0x00544a20` | `Pane::GetDescription(int, wchar_t *)`. |
| `0x00621a98` | primary `+0x28` | `0x00544b80` | `Pane::GetScreenBounds()`. |
| `0x00621a9c` | primary `+0x2c` | `0x00544bd0` | `Pane::SetBounds()`. |
| `0x00621aa0` | primary `+0x30` | `0x00544c70` | `Pane::AddToLayer()`. |
| `0x00621aa4` | primary `+0x34` | `0x00544cb0` | `Pane::InsertInLayer()`. |
| `0x00621aa8` | primary `+0x38` | `0x00544ce0` | `Pane::RemoveFromLayer()`. |
| `0x00621aac` | primary `+0x3c` | `0x00544d30` | `Pane::SetPaneOrder()`. |
| `0x00621ab0` | primary `+0x40` | `0x00544d70` | `Pane::UnregisterEventHandler()`. |
| `0x00621ab4` | primary `+0x44` | `0x0041b6a0` | source `Pane::OnPaint()` empty body folded with the guard no-op; binary label is not the source identity. |
| `0x00621ab8` | primary `+0x48` | `0x005ca28c` | PanelPane-introduced pure `OnActivate(const unsigned char *packetData)`. |
| `0x00621abc` | secondary COL | `0x0064db08` | EventHandler-facet locator, offset `0xa0`. |
| `0x00621ac0` | secondary `+0x00` | `0x005450ef` | Compiler deleting-destructor adjustor, `this -= 0xa0`. |
| `0x00621ac4` | secondary `+0x04` | `0x00544db0` | `HandlePointerOrMouseEvent(Event *)`. |
| `0x00621ac8` | secondary `+0x08` | `0x00544dc0` | `HandleKeyOrTextEvent(Event *)`. |
| `0x00621acc` | secondary `+0x0c` | `0x00544dd0` | `HandleImeEvent(Event *)`. |
| `0x00621ad0` | secondary `+0x10` | `0x00544de0` | `HandlePacketEvent(Event *)`. |
| `0x00621ad4` | secondary `+0x14` | `0x00544df0` | `HandleSystemOrControlEvent(Event *)`. |
| `0x00621ad8` | secondary `+0x18` | `0x00544e00` | `HandleType19Event(Event *)`. |
| `0x00621adc` | secondary `+0x1c` | `0x004a89f0` | `ForwardHandlerOrder(EventHandler *, EventHandler *)`. |
| `0x00621ae0` | secondary `+0x20` | `0x00544e10` | `GetLocalEventPair(EventPointPair *)`. |
| `0x00621ae4` | secondary `+0x24` | `0x00544e30` | `GetScreenEventPair(EventPointPair *)`. |
| `0x00621ae8` | secondary `+0x28` | `0x00544e70` | `ShouldAcceptEvent() const`. |
| `0x00621aec` | tertiary COL | `0x0064db1c` | TimerHandler-facet locator, offset `0xa4`. |
| `0x00621af0` | tertiary `+0x00` | `0x005450fa` | Compiler deleting-destructor adjustor, `this -= 0xa4`. |
| `0x00621af4` | tertiary `+0x04` | `0x00544e90` | `Pane::OnTimer(int timerId, int arg0, int arg1)`. |

Do not read the tertiary table past slot `+0x04`. The next dword at `0x00621af8` is RTTI metadata for neighboring [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md), not a `PanelPane` virtual.

## Derived Activation Matrix

Primary slot `+0x48` is a PanelPane-introduced pointer-valued activation hook across the derived family. Pane's primary table ends at `+0x44`; the base `PanelPane` cell adds `__purecall`, and concrete PanelPane-derived tables provide the implementation:

| Derived pane | `+0x48` target | Supported behavior |
| --- | --- | --- |
| `InventoryPane` | `0x004ea280` | Ignores the packet argument and invalidates inherited embedded-pane bounds; primary cell `0x0061c7a0`. |
| `InventoryPane2` | `0x004ee6d0` | Same packet-ignored invalidation contract; primary cell `0x0061c8b8`. Former `RefreshEmbeddedPane` spelling is superseded. |
| `NewSystemMessagePane` | `0x00588800` | Ignores the packet argument and rebuilds message panes. |
| `NewOptionPane` | `0x00540240` | Activation/refresh override in the common slot. |
| `NewGroupPane` | `0x0056cb80` | Ignores the packet argument and requests the group list. |
| `NewInventoryPane` | `0x004eb550` | Activation/refresh override in the common slot. |
| `NewSpellInventoryPane` | `0x0057d080` | Activation/refresh override in the common slot. |
| `SelfLookPane` | `0x00565890` | Activation/refresh override in the common slot. |
| `UserLookPane` | `0x0059f610` | Activation/refresh override in the common slot. |
| `CollectionPane` | `0x0056ea30` | Consumes packet data to initialize collection state. |

The strongest source declaration is `virtual void OnActivate(const unsigned char *packetData)`. `OnActivate` is inferred rather than symbol-recovered, so behavior-specific names such as `RebuildMessagePanes`, `RequestGroupList`, and `InitializeCollectionData` remain useful aliases for individual bodies, not replacements for the shared slot contract. The derived pointer use and nullable call sites reject the historical `bool showChild` interpretation.

## Activation Provenance And Pane Boundary

- Pane's exact primary table has 18 callable cells and ends at `+0x44 OnPaint`. Its next dword at `0x00621a30` is the secondary EventHandler-facet complete-object-locator pointer, not a callable `+0x48` cell.
- PanelPane primary starts at `0x00621a70` and contains the same inherited Pane entries through `+0x44`, followed by the new `+0x48 -> __purecall` cell. This one-cell extension is the binary evidence that PanelPane declares the pure activation contract.
- The complete ten-entry derived matrix above supplies the strongest signature evidence: some implementations consume packet bytes while others ignore the pointer and request, rebuild, or invalidate state. The shared source signature is therefore retained, but its owner is PanelPane.
- [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md) independently confirms that a non-PanelPane Pane derivative has no activation slot: PhotoPane's primary table ends at `+0x44 PhotoPane::OnPaint` and is followed by a secondary COL pointer.
- Historical correction: the 2026-07-13 investigation correctly resolved the activation behavior/signature and derived implementation matrix. Its statement that `+0x48` was inherited from Pane is superseded; no valid derived evidence is discarded.

## Constructor and Destructor Stores

IDA `xrefs_to` reports all three vtable bases written from the constructor, non-deleting destructor, and scalar deleting destructor:

- Constructor `0x00545090`: writes primary at `0x005450a1`, secondary at `0x005450a9`, and tertiary at `0x005450b3`.
- Non-deleting destructor `0x005450d0`: writes primary at `0x005450d0`, secondary at `0x005450d6`, and tertiary at `0x005450e0`, then tail-jumps to `Pane` teardown at `0x00544580`.
- Scalar deleting destructor `0x00545110`: writes primary at `0x00545116`, secondary at `0x0054511c`, and tertiary at `0x00545126`, calls `Pane` teardown at `0x00544580`, then conditionally frees storage.

## 2026-06-11 Parent-Gate Refresh

Live IDA MCP reconfirmed the 2026-06-01 vtable inventory and added a current parent-gate check:

- `lookup_funcs` reports constructor `0x00545090` size `0x32`, destructor `0x005450d0` size `0x1f`, adjustor thunks `0x005450ef`/`0x005450fa` size `0x0b` each, scalar deleting destructor `0x00545110` size `0x55`, and successor `EditablePaperPane` constructor `0x00545170`.
- `xrefs_to` reports the complete vtable-store triads: `0x00621a70` from `0x005450a1`, `0x005450d0`, and `0x00545116`; `0x00621ac0` from `0x005450a9`, `0x005450d6`, and `0x0054511c`; `0x00621af0` from `0x005450b3`, `0x005450e0`, and `0x00545126`.
- `xrefs_to 0x00545110` reports only the two adjustor thunk jumps plus the primary vtable slot, supporting vtable-driven scalar destruction rather than ordinary source callers.
- `py_eval` reconfirms every dword from `0x00621a6c` through `0x00621af8`, including `0x00621a6c -> ??_R4PanelPane@@6B@`, `0x00621abc -> ??_R4PanelPane@@6B@_0`, `0x00621aec -> ??_R4PanelPane@@6B@_1`, and `0x00621af8 -> ??_R4EditablePaperPane@@6B@`.
- The object offsets remain `+0xa0` and `+0xa4`, equal to 160 and 164 respectively (Verified with int_convert.py).

## Historical Wave3 Data Issue

Historical Wave3 output marked `0x005450ef` as missing code and polluted the destructor base owner with `TextButtonExControlPane`. That workflow and its issue ledger are non-authoritative. Current IDA models both 11-byte adjustors, and current executable documentation proves the ordinary/scalar paths use Pane teardown. The old observation is retained only to explain why earlier generated output was rejected; it is not a current blocker or evidence source.

## Assignment Gate

This page now attaches to [UID:0000A4][PanelPane](by-class/PanelPane.md). The vtable family is a single-owner `PanelPane` type-layout record, not a mixed-owner aggregate: the exact child range starts at `PanelPane` RTTI `0x00621a6c`, all three table bases are stored only by `PanelPane` constructor/destructor paths, and the next dword `0x00621af8` is the `EditablePaperPane` RTTI boundary. The class parent and file parent now both clear the strict 85/85 gate.

Completion/confidence are `93/96`: all 35 backing dwords, three COLs, six-base hierarchy, exact Pane/EventHandler/TimerHandler source identities, lifecycle stores, compiler destructor glue, Pane/EditablePaperPane fences, and ten derived activation implementations are documented. Complete stripped original lexical/access spelling remains below final audit, but no raw identity, ownership, range, or source-disposition question remains.

## Cross References

- [UID:0002OG][0x00621a6c-0x00621af8.PanelPaneVtableData](by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md)
- [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)
- [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000ME][PanelPane](by-file/PanelPane.md)
- [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md)
- [UID:0003OU][0x00622030-0x006220b8.PhotoPaneVtableData](by-memory/0x00622030-0x006220b8.PhotoPaneVtableData.md)

## Changes

- 2026-07-29 B002 UID0002OG accepted implementation callback:
  - Raised `88/93 -> 93/96`; retained owner/emitter UID0000A4 and reconstructable state.
  - Added the exact covered-by CPP marker and kept H blank because this ABI page must not declare literal vtable arrays.
  - Incorporated all 35 backing dwords, three COL records, the shared six-base RTTI hierarchy, direct PanelPane-to-Pane inheritance, inherited EventHandler/TimerHandler facet PMDs, no-new-field `0xf8` layout, complete source-facing primary/secondary/tertiary contract, and exact external fences.
  - Historicalized the old Wave3 missing-code/owner-pollution paragraph. The facts that generated output once failed to model the thunk and misnamed teardown remain useful history; Wave3 itself is not current evidence or a current blocker.

- 2026-07-26 Agent-B001 UID0003OU source-quality callback:
  - Preserved `88/93`, owner/emitter UID0000A4, exact table/store/thunk/RTTI evidence, eight-derived activation matrix, inferred pointer signature, and blank formal blocks.
  - Clarified that inherited Pane slots end at `+0x44` and PanelPane itself introduces the pure `+0x48 OnActivate` cell.
  - Retained the earlier activation research as historical evidence while superseding only the stale Pane-ownership statement; PhotoPane's inherited 18-slot table provides independent negative corroboration.

- 2026-07-13 B004 UID00015Y accepted callback: raised `87/92 -> 88/93`; resolved inherited `+0x0c` as `UpdateRenderRegion`, documented the `+0x48` `__purecall` base cell and eight-entry derived activation matrix, established the common `OnActivate(const unsigned char *)` pointer contract, and preserved every raw table/RTTI/thunk/store fact and compiler-generated disposition.
- 2026-06-01:
  - What existed before: this vtable page had strong slot and constructor/destructor-store evidence, but the validator-tracked completion/confidence header remained `0/0` and there was no exact `by-memory` child for the `0x00621a6c-0x00621af8` RTTI/vtable-data island.
  - Changed to: scored the page as a strong but non-final vtable inventory, marked it reconstructable, and linked [UID:0002OG][0x00621a6c-0x00621af8.PanelPaneVtableData](by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md) as the exact address-range evidence page.
  - Summary/evidence: IDA MCP `py_eval` on 2026-06-01 read the RTTI/vtable dwords from `0x00621a6c` through `0x00621af8`, confirmed data xrefs from `PanelPane` constructor/destructor bodies to all three vtable bases, confirmed `0x005450ef` and `0x005450fa` as real 11-byte adjustor thunks, and confirmed `0x00621af8` starts neighboring `EditablePaperPane` RTTI.
- 2026-06-11 A006 parent-gate refresh:
  - Before: `84/90`, parent blank because the child completion and direct class parent were below the strict 85/85 gate.
  - After: `87/92`, `AUTOGEN_PARENT_UID:0000A4`.
  - Summary/evidence: live IDA MCP reconfirmed function sizes, table-store xrefs, vtable/thunk-only scalar destructor dispatch, exact dword inventory through the successor RTTI boundary, object offsets, and single-owner `PanelPane` class ownership. [UID:0000A4][PanelPane](by-class/PanelPane.md) and [UID:0000ME][PanelPane](by-file/PanelPane.md) were refreshed to clear the direct-parent gate.
