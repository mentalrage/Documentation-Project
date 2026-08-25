*** UID:0001Y4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:13 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001Y4] MenuItem/StringMenuItem/SeparatorMenuItem vtable layout evidence.
// MSVC regenerates this vtable data from the class declarations and exact virtual method implementations.
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Menu Item Vtables

## Status

- Confidence: very strong for decorated identities, complete single-inheritance chains, exact slot order, abstractness, object-size implications, and compiler/source disposition; exact lost lexical spellings remain inferred.
- Current entity kind: vtable/layout evidence for [UID:00007V][MenuItem](by-class/MenuItem.md), [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md), and [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md).
- Current owner header/source: `NexusTK/ui/menu/PopupMenuControls.h/.cpp` through [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md). A historical `MenuItem.h/.cpp` split remains plausible but unproven.
- Assignment: attached to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), which is the narrowest current parent that owns the whole three-class vtable family and clears the strict `85/85` direct-parent gate.
- Evidence basis: decorated COL/vtable names, exact CHD/base arrays, live read-only IDA MCP bytes/types/xrefs/decompilation, wrapper sizes, constructor vptr stores, and exact method pages. Generated/simroot and stale Wave2/Wave3 material are leads or history only, not authority.

## Vtable Run

IDA resolves the three decorated vtable symbols in one compact `.rdata` run:

| Class | RTTI pointer | Vtable base | Slot range | Notes |
| --- | --- | --- | --- | --- |
| [UID:00007V][MenuItem](by-class/MenuItem.md) | `0x0061eb94` | `0x0061eb98` | `0x0061eb98-0x0061ebac` | Base entry type; most behavior slots are pure virtual. |
| [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) | `0x0061ebb0` | `0x0061ebb4` | `0x0061ebb4-0x0061ebc8` | Text item implementation. |
| [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md) | `0x0061ebcc` | `0x0061ebd0` | `0x0061ebd0-0x0061ebec` | Separator has two extra fixed-metric/style slots before following string data. |

The next dword after the separator slot run is UTF-16 resource/string data, not another vtable entry. The exact physical data child is [UID:00036I][0x0061eb94-0x0061ebf0.MenuItemVtableData](by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md).

## RTTI Hierarchy

| Class | COL / CHD | Exact base array | CHD / PMD result | Source hierarchy |
| --- | --- | --- | --- | --- |
| `MenuItem` | `0x0064b604` / `0x0064b618` | `MenuItem`, `LObject` | attrs `0`; both PMDs `0,-1,0` | `MenuItem : public LObject` |
| `StringMenuItem` | `0x0064b6d4` / `0x0064b6e8` | `StringMenuItem`, `MenuItem`, `LObject` | attrs `0`; all PMDs `0,-1,0` | `StringMenuItem : public MenuItem` |
| `SeparatorMenuItem` | `0x0064b724` / `0x0064b738` | `SeparatorMenuItem`, `MenuItem`, `LObject` | attrs `0`; all PMDs `0,-1,0` | `SeparatorMenuItem : public MenuItem` |

The complete descriptors reject multiple inheritance, virtual inheritance, sibling-only classes, and a secondary Separator facet.

## Slot Map

| Slot | MenuItem | StringMenuItem | SeparatorMenuItem | Role hypothesis |
| --- | --- | --- | --- | --- |
| `+0x00` | [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) | [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) | [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) | Compiler-generated scalar deleting destructor wrappers from ordinary virtual destructors. |
| `+0x04` | `0x004f4b10` | `0x004f4b10` | `0x004f4b10` | Inherited `LObject`/runtime virtual. |
| `+0x08` | `0x0041b6c0` | `0x0041b6c0` | `0x0041b6c0` | Shared no-op virtual. |
| `+0x0c` | `__purecall` | [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) | `__purecall` | `StringMenuItem::GetItemSize(GrafPort *port) const` candidate; returns height-first `MenuItemMetrics` through MSVC hidden-return/out-buffer ABI. |
| `+0x10` | `__purecall` | [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) | `__purecall` | Typed `errno_t GetText(wchar_t *destination, size_t sizeInWords) const` slot; physical String cell `0x0061ebc4 -> 0x005170d0`, concretely dispatched by PopupMenuControlPane OnDraw at `0x00498414`. |
| `+0x14` | `__purecall` | [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md) | [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) | Generic `DrawItem(GrafPort *port)` virtual; separator path keeps `DrawSeparator` only as a behavior-label filename. |
| `+0x18` | next RTTI | next RTTI | [UID:0002JC][0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions](by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md) | Separator fixed-dimensions slot. |
| `+0x1c` | not a slot | not a slot | [UID:0002JD][0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags](by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md) | Separator style/flags slot. |

B003 source-quality reanalysis keeps the slot map intact and resolves the source contract: `+0x04` is inherited `LObject::GetRuntimeClass`, `+0x08` is inherited `LObject::OnChangeMessage`, `StringMenuItem +0x0c/+0x10/+0x14` are `GetItemSize`, `GetText`, and `DrawItem`, and Separator `+0x14/+0x18/+0x1c` are `DrawItem`, `GetDefaultDimensions`, and `GetStyleFlags`. The Separator extension does not satisfy the two pure base slots; Separator is therefore abstract, while String is concrete. `MenuItemMetrics` is returned by value through the observed hidden-result pointer, and `MenuItemStyleFlags` is a two-byte UDT rather than a primitive AX return. B003's 2026-06-23 direct-copy implementation also confirms [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) is a nonvirtual sibling: the String table points to `0x00517090`, `0x005170d0`, and `0x005170f0`, never `0x00517070`.

Concrete consumer evidence closes the prior inferred-only use caveat. [UID:0004IU][0x00498270-0x004984bc.PopupMenuControlPaneOnDraw](by-memory/0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md) obtains a selected `MenuItem *`, pushes count `0x100`, addresses a 256-wide local, and calls `[edx+0x10]` at `0x00498414`. For a String object, the typed physical cell above resolves that call to UID0002J9. The caller ignores EAX and consumes the destination; this is status-independent use, not a `void` method contract or ownership transfer.

## Bounds-Method Vtable Exclusion

The exact base run beginning at `0x0061eb98` is, in order, `0x005172e0`, `0x004f4b10`, `0x0041b6c0`, `0x005ca28c`, `0x005ca28c`, and `0x005ca28c`; the following dword at `0x0061ebb0` is the decorated `StringMenuItem` RTTI complete-object-locator pointer rather than a seventh base slot. No cell is `0x00516fb0` or `0x00516fd0`.

This exact finite run proves that [UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemGetBounds](by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md) and [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBounds](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md) are not virtual methods. Their complete adjacent 17-byte bodies, inverse whole-`RectBounds` behavior, and exact `int3` fences support retained ordinary members. Exhaustive direct-xref, encoded-pointer, member-pointer, vtable, and rel32 scans are negative for both starts; those results cap surviving route confidence but do not change the no-slot proof or source-authored classification.

The getter's pointer-return ABI and the setter's const input belong in the `MenuItem` declaration and exact method pages. They must not be added as raw vtable cells or emitted in this compiler-data page. The byte-identical getter-shaped body at `0x00554ae0` belongs to a separately modeled Region/motion comparator and provides no alternate MenuItem slot.

## Constructor And Destructor Evidence

- `xrefs_to 0x0061eb98` reports writes from `MenuItem::MenuItem` at `0x00516f41`, the base-construction portions of `StringMenuItem` at `0x00517031` and `SeparatorMenuItem` at `0x005171f1`, plus base vtable resets in destructors at `0x005172e6` and `0x00517406`.
- 2026-06-20 B002 raw PE recheck for [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) found the little-endian `MenuItem` vtable VA `0x0061eb98` only in the base constructor store, derived constructor base-construction stores, and destructor reset stores. This keeps the constructor source model as ordinary `MenuItem::MenuItem()` while treating the vtable write itself as compiler output.
- `xrefs_to 0x0061ebb4` reports the `StringMenuItem` vtable write at `0x0051704e`.
- `xrefs_to 0x0061ebd0` reports the `SeparatorMenuItem` vtable write at `0x00517205`.
- IDA data xrefs place `StringMenuItem` virtual slots at `0x0061ebc0`, `0x0061ebc4`, and `0x0061ebc8`, and separator slots at `0x0061ebe4`, `0x0061ebe8`, and `0x0061ebec`.
- 2026-06-19 B015 raw PE recheck for [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) found the `SeparatorMenuItem` vtable immediate `0x0061ebd0` only in the constructor's final vptr store at `0x00517205`, while the separator vtable itself continues to route slot `+0x00` to the inherited [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) wrapper.
- 2026-06-11 read-only IDA MCP `py_eval` reconfirmed the dword sequence from the predecessor `MenuPane` adjusted-table dword at `0x0061eb90` through the menu-item child end at `0x0061ebf0`, including `0x0061eb94 -> ??_R4MenuItem@@6B@`, `0x0061ebb0 -> ??_R4StringMenuItem@@6B@`, `0x0061ebcc -> ??_R4SeparatorMenuItem@@6B@`, the three decorated vtable bases, all slot target function boundaries, and UTF-16 `MENUBACK.EPF` starting at `0x0061ebf0`.
- 2026-06-18 B003 raw PE recheck found little-endian target VA `0x005172e0` only at `.rdata:0x0061eb98` (`MenuItem` slot `+0x00`) and `.rdata:0x0061ebd0` (`SeparatorMenuItem` slot `+0x00`), with no target RVA/raw-offset hits and no `.text` rel32 callers. This strengthens the interpretation that [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) is vtable-owned deleting-destructor glue rather than an ordinary directly called helper.
- 2026-06-19 B009 raw PE recheck found little-endian target VA `0x00517400` only at `.rdata:0x0061ebb4` (`StringMenuItem` slot `+0x00`), with no target RVA/raw-offset hits and no `.text` rel32 callers. This strengthens the interpretation that [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) is vtable-owned deleting-destructor glue generated from ordinary/default `StringMenuItem` destructor semantics rather than an ordinary directly called helper.

## Destructor Wrapper Disposition

- The folded `0x005172e0-0x0051731e` wrapper appears only in MenuItem and Separator slot 0 and carries the `0x18` base delete size. The String-only `0x00517400-0x00517441` wrapper appears only in String slot 0 and carries the `0x118` delete size.
- `LObject` already supplies virtual destruction. `StringMenuItem` owns only inline trivial text storage, and `SeparatorMenuItem` adds no fields. The most faithful source shape is therefore implicit virtual derived destructors, not explicit empty declarations or handwritten deleting wrappers.
- The compiler regenerates both wrappers and all vtable/COL data from the H-channel class declarations and exact child method definitions. This page retains its compiler-generation marker plus `[[CHILDREN]]`; UID00036I is the attached semantic data child.
- UID0002JG is reviewed `RECONSTRUCTABLE:FALSE`, non-emitting support with blank CPP/H and no generated marker/body. Semantic owner UID0000E8 and physical cell `0x0061ebb4` remain unchanged; source regeneration comes from implicit virtual `StringMenuItem` destruction.

## IDA Type State

The accepted live prestate found project `MenuItem` at size `0x18` but with `lpVtbl` incorrectly typed as imported COM `MenuItemVtbl *`. That COM interface is 52 bytes with 13 slots and must remain unchanged. Collision-free project UDTs `NexusTKMenuItemVtable` and `NexusTKSeparatorMenuItemVtable` were absent; the proposed six/eight-slot types preserve the exact contracts above. These are supervisor Gate 2B actions. This page records the prestate but does not mutate IDA.

## Semantic Child Route

[UID:00036I][0x0061eb94-0x0061ebf0.MenuItemVtableData](by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md) is the exact physical compiler-data child of this semantic family. Its canonical owner/emitter is UID0001Y4, and this page continues to emit through UID0000MN at position 13. No raw vtable array, RTTI object, or scalar-wrapper body is authored.

## Assignment Gate

This page remains assigned directly to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), now `93/95` over a file parent recommended at `88/88`. It is the narrower semantic owner for the three-class physical child UID00036I. Routing the data to only one class is rejected because no one class owns all three tables; direct UID00025T or direct-file ownership would bypass the exact semantic family.

## Score Rationale

Completion is `93` because the page now has exact hierarchy descriptors, complete 6/6/8 slot contracts, direct abstractness conclusions, wrapper sizes/folding, source/compiler disposition, IDA type prestate, semantic child routing, and exact physical data linkage. Remaining work is independent callback/generated/IDA/lifecycle verification.

Confidence is `95` because decorated RTTI, CHD/base arrays, exact dwords, bounded bodies, xrefs, hidden-result ABIs, and wrapper sizes agree. Exact historical spellings and physical source filename remain inferred, preventing a perfect score.

## Data Caveats

Current `simroot_v2` metadata reports `vtable_count: 0` for `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem` even though IDA has decorated vtable symbols and constructor/destructor writes for all three classes.

## Cross-References

- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:00036I][0x0061eb94-0x0061ebf0.MenuItemVtableData](by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-08-11 B010 UID0002J9 vtable synchronization:
  - Preserved `93/95`, UID0000MN ownership/emission, position `13`, complete 6/6/8 slot order/types, RTTI, compiler marker, semantic child route, and all protected table data.
  - Added the exact typed String `GetText` cell and concrete `0x00498414` dispatch with 256-wide caller storage and ignored status.
  - Reconciled UID0002JG as false/non-emitting compiler support regenerated from implicit virtual derived destruction, with zero marker/body and no change to slot `0x0061ebb4`.
- 2026-08-01 B003 UID00036I ordinary implementation callback:
  - Raised `86/91 -> 93/95` while preserving owner/emitter UID0000MN, reconstructable true, position `13`, the compiler-generation marker, `[[CHILDREN]]`, and blank H.
  - Added complete CHD/base-array hierarchy, resolved 6/6/8 slot contract and Separator abstractness, wrapper size/folding and implicit-destructor policy, current IDA type collision/absence state, and the UID0001Y4 -> UID00036I semantic child route.
  - Preserved all prior vtable cells, constructor/destructor xrefs, bounds exclusion, historical evidence, and no-raw-vtable source policy.

- 2026-07-24 B005 accepted UID0002JJ support sync:
  - Score and metadata remain `86/91`, owner/emitter UID0000MN, reconstructable true, and position `13`.
  - Added the complete six-dword base run (`0x005172e0`, `0x004f4b10`, `0x0041b6c0`, and `0x005ca28c` three times), the following StringMenuItem COL boundary, and explicit no-slot proof for UID0002JJ/UID0002JK.
  - Synchronized the renamed bounds-method links and preserved decorated identities, compiler-generated vtable policy, all class slot maps, constructor/destructor xrefs, data boundaries, rejected ownership, and no-raw-vtable emission. No method body was added here.

- 2026-06-30 B008 empty-emitter implementation:
  - Score remains `86/91`; set `EMITTER_POSITION_OPTIONAL:13` and populated the formal block with a no-raw-vtable marker plus `[[CHILDREN]]`.
  - Evidence: B008 MCP `get_int` over the `0x0061eb94-0x0061ebec` run confirmed the MenuItem, StringMenuItem, and SeparatorMenuItem destructor and virtual slots, including purecall entries where the base remains abstract.
  - Source-quality decision: do not emit `.rdata` vtable bytes as source; MSVC should regenerate the vtable data from declaration shells and exact virtual method implementations.
- 2026-06-20 B002 [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) constructor support sync:
  - Score unchanged at `86/91`.
  - Evidence: recorded raw PE vtable-address search confirming `0x0061eb98` appears in the expected base constructor, derived base-construction, and destructor reset sites.
  - Source-quality decision: vtable stores remain compiler output; the constructor's emitted C++ should express `LObject`, bounds initialization, `m_enabled`, and `m_selected`.
- 2026-06-17 B003 source-quality incorporation:
  - Added draft source roles for `GetText`, `DrawItem`, `MenuItemMetrics`, `MenuItemStyleFlags`, and ordinary-destructor generation of scalar deleting wrappers.
  - Preserved the separator extra-slot caveat for a later live call-site audit.
- 2026-06-19 B015 SeparatorMenuItem constructor support sync:
  - Score unchanged at `86/91`.
  - Evidence: added raw PE evidence that `0x0061ebd0` is only used as the final vptr store in [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md), while slot `+0x00` remains inherited [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md).
- 2026-06-18 B003 [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) destructor-wrapper recheck:
  - Added raw PE pointer-route confirmation that `0x005172e0` appears only in the `MenuItem` and `SeparatorMenuItem` vtable slots, with no direct code caller or alternate RVA/raw-offset route. This supports keeping [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) owned by [UID:00007V][MenuItem](by-class/MenuItem.md), reused by `SeparatorMenuItem`, and formal-C++ blank as compiler-generated wrapper output.
- 2026-06-19 B009 [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) destructor-wrapper implementation:
  - Added raw PE pointer-route confirmation that `0x00517400` appears only in the `StringMenuItem` vtable slot at `0x0061ebb4`, with no direct code caller or alternate RVA/raw-offset route. This supports keeping [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) owned by [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) and formal-C++ blank as compiler-generated wrapper output.
- 2026-06-20 B004 [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) draw-slot implementation:
  - Score unchanged at `86/91`.
  - Evidence: recorded slot `+0x14` as the generic `DrawItem(GrafPort *port)` virtual for both `StringMenuItem` and `SeparatorMenuItem`; [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) keeps its behavior-label filename but emits first-draft `SeparatorMenuItem::DrawItem` C++.
- 2026-06-22 B013 [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) metric-slot implementation:
  - Score unchanged at `86/91`.
  - Evidence: recorded slot `+0x0c` as `StringMenuItem::GetItemSize(GrafPort *port) const`, with hidden-return `MenuItemMetrics`, accepted `GrafPort::GetTextWidth` dependency, inline `m_text[0x80]` scan, and height-first `[0]=14`, `[1]=textWidth+24` metrics. Final historical spelling remains inferred, but first-draft C++ now belongs on the exact method page.
- 2026-06-23 B003 [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) direct-copy support sync:
  - Score unchanged at `86/91`.
  - Evidence: recorded vtable-negative proof that [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) is not a slot entry. MCP session `b880584f` reads the `StringMenuItem` vtable as `0x0061ebc0 -> 0x00517090`, `0x0061ebc4 -> 0x005170d0`, and `0x0061ebc8 -> 0x005170f0`; no vtable cell points to `0x00517070`. [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) has eleven direct code xrefs and is now first-draft C++ ready as `StringMenuItem::CopyText(...)`, while [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) remains the vtable-backed `GetText` sibling at slot `+0x10`.
  - Rejected alternatives: naming [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) `GetText`, merging it with [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md), treating the stale `void CopyTextToWideBuffer` generated alias as final source, and routing the helper through base `MenuItem`, caller features, or no-owner/non-emitting status.
- Before: vtable slots were documented only as raw addresses and the page was ungraded.
- Changed to: reconstructable metadata is set, slot rows link to exact by-memory child pages, and the evidence basis explicitly treats generated data as a lead only.
- Evidence: IDA MCP vtable dword reads, xrefs to slot targets, and `lookup_funcs` confirmed the current slot targets and function extents.
- 2026-06-11 A004 assignment and split:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:88`, `AUTOGEN_PARENT_UID` blank, and no exact by-memory child for the `0x0061eb94-0x0061ebf0` physical vtable run.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:91`, `AUTOGEN_PARENT_UID:0000MN`, plus exact child [UID:00036I][0x0061eb94-0x0061ebf0.MenuItemVtableData](by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md).
  - Summary/evidence: 2026-06-11 read-only IDA MCP reconfirmed the COL pointers, decorated vtable bases, slot target boundaries, constructor/destructor vptr-store xrefs, `MenuPane` predecessor dword, and `MENUBACK.EPF` successor boundary; [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) clears the strict `85/85` parent gate and owns all three menu item classes.
