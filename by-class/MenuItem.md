*** UID:00007V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MenuItem : public LObject
{
public:
    MenuItem();

    bool IsEnabled() const;
    void SetEnabled(bool enabled);
    bool IsSelected() const;
    void SetSelected(bool selected);

    RectBounds *GetBounds(RectBounds *outBounds) const;
    void SetBounds(const RectBounds *bounds);

    virtual MenuItemMetrics GetItemSize(GrafPort *port) const = 0;
    virtual errno_t GetText(wchar_t *destination, size_t sizeInWords) const = 0;
    virtual void DrawItem(GrafPort *port) = 0;

protected:
    RectBounds m_bounds;
    bool m_enabled;
    bool m_selected;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MenuItem

## Status

- Confidence: very strong for base class role, exact `0x18` layout, method ownership, bool semantics, nonvirtual/virtual split, vtable identity, and source-ready declaration; original lexical spellings and physical source-file split remain inferred.
- Likely source file: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- Autogen parent: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md). The complete formal declaration closes before `[[CHILDREN]]`, so all exact child definitions emit at namespace scope. The possible original `MenuItem.cpp` split remains a source-placement confidence cap, not an emitter blocker.
- Main address range: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- Vtables: [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- Layout docs: [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_MenuItem.cpp`

## Class Purpose

`MenuItem` is the base menu entry object. It initializes an empty bounds rectangle and enabled state, then provides the base deleting destructor for derived menu items.

The exact `0x18` base layout starts with the inherited/primary vptr at `+0x00`, a 16-byte bounds rectangle at `+0x04`, bool `m_enabled` at `+0x14`, bool `m_selected` at `+0x15`, and natural tail padding at `+0x16..+0x17`. `StringMenuItem` extends at `+0x18` with an inline label buffer, while `SeparatorMenuItem` adds no fields and changes behavior through vtable slots.

## Hierarchy And Virtual Contract

- RTTI proves `MenuItem : public LObject` through the two-entry `MenuItem`, `LObject` base array. The class-hierarchy descriptor has attributes `0`, and both base PMDs are `0,-1,0`, excluding multiple or virtual inheritance.
- The exact primary table has six slots: compiler scalar deleting destructor, inherited `GetRuntimeClass`, inherited `OnChangeMessage`, pure `GetItemSize`, pure `GetText`, and pure `DrawItem`.
- The three pure application slots make `MenuItem` abstract. `GetBounds` and `SetBounds` are ordinary nonvirtual members: neither exact address occurs in the finite table.
- The complete source-visible size is `0x18`, matching the field map below and the base scalar-wrapper delete-size constant.

## Layout And State

| Offset | Role | Evidence |
| --- | --- | --- |
| `+0x00` | primary vtable pointer | `MenuItem::MenuItem` writes `0x0061eb98`; the scalar deleting destructor resets the same base vtable before teardown; derived constructors first install the base table before writing their concrete tables. |
| `+0x04` | 16-byte bounds rectangle | The constructor zeroes this field through the shared rectangle helper; `MenuItem::GetBounds` copies `this+0x04` to a caller buffer and returns that pointer; `MenuItem::SetBounds` copies a caller rectangle back to `this+0x04`; `MenuPane` relayout writes this same 16-byte field for each item. |
| `+0x14` | enabled/interactable state byte inside a shared word; best current field name `m_enabled` | The base and string constructors initialize the word to `1`, the separator constructor initializes it to `0`, `MenuPane` previous/next-enabled scans compare byte `item+0x14`, and the accessor/setter pair reads/writes the same byte. B003 accepts `m_enabled`/`IsEnabled` as the high-probability source role; exact original spelling remains inferred. |
| `+0x15` | selected/highlighted draw-state byte inside the shared word; best current field name `m_selected` | The accessor/setter pair reads/writes `item+0x15`; `StringMenuItem` draw logic branches on `item+0x15` before choosing highlighted rendering. B003 accepts `m_selected`/`IsSelected` as the high-probability source role, with `highlighted draw state` retained as the semantic alias; exact original spelling remains inferred. |
| `+0x16..+0x17` | natural alignment/tail padding | The scalar deleting wrapper carries object-size immediate `0x18`, derived String storage begins at `+0x18`, and no source field or independent access exists in these two bytes. Keep them as compiler layout, not raw-layout members. |

`tools/int_convert.py` verified the decimal forms of the main sizes used by this pass: `0x04` is 4 bytes, `0x10` is 16 bytes, `0x11` is 17 bytes, `0x18` is 24 bytes, `0x5c` is 92 bytes, `0x67` is 103 bytes, `0x3e` is 62 bytes, `0x80` is 128 units, `0x100` is 256 bytes, and `0xb2` is 178 bytes.

## Method Map

| Memory page | Method | Role |
| --- | --- | --- |
| [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) | `MenuItem::MenuItem()` | Initializes `LObject`, vtable, bounds, `m_enabled=true`, and `m_selected=false`; B002 resolved the binary word store as adjacent byte initialization rather than a source `m_stateWord` assignment. |
| [UID:0002J4][0x00516f70-0x00516f74.MenuItemIsEnabled](by-memory/0x00516f70-0x00516f74.MenuItemIsEnabled.md) | `bool IsEnabled() const` | Exact four-byte nonvirtual direct bool getter for `m_enabled`. |
| [UID:0002JH][0x00516f80-0x00516f8d.MenuItemSetEnabled](by-memory/0x00516f80-0x00516f8d.MenuItemSetEnabled.md) | `void SetEnabled(bool enabled)` | Exact 13-byte retained out-of-line nonvirtual setter for `m_enabled`. |
| [UID:0002J5][0x00516f90-0x00516f94.MenuItemIsSelected](by-memory/0x00516f90-0x00516f94.MenuItemIsSelected.md) | `bool IsSelected() const` | Exact four-byte nonvirtual direct bool getter for `m_selected`. |
| [UID:0002JI][0x00516fa0-0x00516fad.MenuItemSetSelected](by-memory/0x00516fa0-0x00516fad.MenuItemSetSelected.md) | `void SetSelected(bool selected)` | Exact 13-byte retained out-of-line nonvirtual setter for `m_selected`. |
| [UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemGetBounds](by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md) | `RectBounds *GetBounds(RectBounds *outBounds) const` | Exact 17-byte retained nonvirtual getter; copies the complete `m_bounds` object to caller storage and returns that pointer in `eax`. |
| [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBounds](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md) | `void SetBounds(const RectBounds *bounds)` | Exact 17-byte retained nonvirtual setter; reads the complete caller rectangle and replaces `m_bounds`. |
| [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) | compiler-generated scalar deleting destructor wrapper | Base wrapper used by `MenuItem` and `SeparatorMenuItem` vtables; source should declare an ordinary virtual destructor and let MSVC regenerate this wrapper. |

## B003 Source-Quality Incorporation

B003 reviewed the state bytes as heuristic/source-quality issues rather than leaving compiler-style `stateFlag0`/`stateFlag1` names in place. The best current interpretation is:

| Field | Best current source role | Evidence | Rejected alternatives |
| --- | --- | --- | --- |
| `+0x14` | `m_enabled` / enabled-interactable state | Base and string constructors write state word `1`; separator constructor writes `0`; `MenuPane` previous/next scans test byte `+0x14`; accessor/setter siblings target the same byte. | generic `stateFlag0`, selected/highlighted state, style flags. |
| `+0x15` | `m_selected` / selected-highlighted draw state | Accessor/setter siblings target byte `+0x15`; constructors seed the high byte to zero; `StringMenuItem::DrawItem` branches on it before highlighted rendering. | generic `stateFlag1`, enabled/interactable state, style flags. |

Fresh 2026-07-15 MCP session `64c11373` extends that evidence. Six pointer/keyboard/navigation consumers at `0x005169af`, `0x00516a47`, `0x00516afe`, `0x00516b4b`, `0x00516c7e`, and `0x00516cde` test `m_enabled`. The selection updater at `0x00516e50`, reached through five code xrefs, clears old `m_selected` at `0x00516e95`, sets new `m_selected` at `0x00516ec2`, and invalidates both affected bounds; `StringMenuItem::DrawItem` then reads the bool at `0x00517109`. This closes the two field roles without requiring public fields or friendship: public methods plus protected storage are coherent source, and optimized direct offset operations do not change that access model.

All four state methods are nonvirtual. Exact vtable reads show no matching slots, while the base pure virtual metrics/text/draw contract remains unchanged. Their complete bodies, pair symmetry, consumers, and lack of wrapper/table traits preserve them as source-authored methods even though no surviving direct start xref/pointer/PE rel32 route exists. Direct file ownership, MenuPane ownership, compiler/no-code, bitfields, visibility, active-state, and style-flag interpretations remain rejected.

The scalar deleting destructor page remains formal-C++ blank by design. The source-level class representation should be an ordinary virtual destructor, not handwritten deleting-wrapper code.

## Bounds API Resolution

The two adjacent raw ranges at `0x00516fb0` and `0x00516fd0` are a complete retained nonvirtual getter/setter pair over `m_bounds`. Each is exactly `0x11` bytes, each copies all 16 bytes with `movups`, each is isolated by `int3` padding, and neither appears in the base vtable. Their lack of current encoded callers is preserved as exhaustive negative evidence, but it does not convert exact authored class methods into compiler-generated or no-code records.

The getter loads its explicit output argument into `eax`, stores the rectangle through it, and returns without changing `eax`. The class declaration therefore uses `RectBounds *GetBounds(RectBounds *outBounds) const`; the older `void GetBounds(RectBounds *bounds) const` declaration captured the store but discarded an observable ABI return. The setter only reads its pointer argument and remains `void SetBounds(const RectBounds *bounds)`.

`GetBounds`/`SetBounds` is the strongest source-facing pair. `CopyBounds` hides the accessor pairing, `GetRect`/`SetRect` conflicts with the established bounds terminology, a reference-return getter conflicts with the explicit hidden output pointer, and a no-argument value return conflicts with `retn 4`. A byte-identical getter-shaped body at `0x00554ae0` belongs to a separately modeled Region/motion comparator with ten xrefs from nine callers; it demonstrates a shared compiler idiom but does not own or cover UID0002JJ.

The paired pages preserve exact hashes, bytes, fences, PE coordinates, no-route scans, field producers/consumers, and rejected alternatives. They emit the method bodies; this class page emits only the declaration and keeps [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) as the current source root without inventing an unproven physical `MenuItem.cpp` split.

## Destructor Source Shape

[UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) is compiler-generated scalar deleting support for virtual destruction. It is referenced only from MenuItem and SeparatorMenuItem slot 0, uses size `0x18`, resets the base vptr, performs `LObject` cleanup, and conditionally calls delete. Because `LObject` already has a virtual destructor, an explicit `MenuItem` destructor declaration is not required to produce this ABI shape; the accepted H declaration omits it and relies on implicit virtual derived destruction. Handwriting the wrapper or a source-level flags parameter remains prohibited.

The prior explicit `virtual ~MenuItem()` draft is retained as a superseded source-shape assumption: it was plausible from slot 0 alone, but the wrapper fold, base virtual destructor, and lack of class-specific cleanup do not prove an authored declaration or definition.

B002's 2026-06-20 constructor pass makes [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) first-draft C++ ready. The raw `word ptr [this+0x14] = 1` write is compiler coalescing of adjacent `m_enabled` and `m_selected` bytes, so the source model is `m_enabled = true; m_selected = false;` after `LObject` construction and `InitRectBounds(&m_bounds, 0, 0, 0, 0)`. The pass rejected a separate `m_stateWord = 1` source assignment and kept the vtable write, SEH registration, security cookie, construction-unwind handler `0x00603199`, and local unwind-state stores as compiler-only output.

## Evidence Notes

- IDA MCP `lookup_funcs` confirms the modeled constructor, two state accessors, and scalar deleting destructor as exact function starts; IDA disassembly confirms four adjacent raw method-shaped helpers at `0x00516f80`, `0x00516fa0`, `0x00516fb0`, and `0x00516fd0`.
- 2026-05-26 IDA MCP resolves the decorated `MenuItem` vtable symbol to `0x0061eb98`; current `simroot_v2` metadata still reports `vtable_count: 0`.
- The base vtable has pure virtual behavior slots at `+0x0c`, `+0x10`, and `+0x14`, supporting `MenuItem` as an abstract/reusable entry type.
- 2026-06-13 live IDA MCP `lookup_funcs` reconfirmed the modeled base functions: constructor `0x00516f00` size `0x67` / 103 bytes (Verified with `int_convert.py`), state accessors at `0x00516f70` and `0x00516f90` size `0x04` / 4 bytes each (Verified with `int_convert.py`), scalar deleting destructor `0x005172e0` size `0x3e` / 62 bytes (Verified with `int_convert.py`), and successor `0x00517450` as the next `MenuDialogFactoryHelpers` function.
- The same live lookup confirms `0x00516f80`, `0x00516fa0`, `0x00516fb0`, and `0x00516fd0` are not IDA function starts, but `insn_query` over `0x00516f70-0x00516fe1` decodes them as isolated method-shaped setters/copy helpers separated by alignment. Their behavior exactly matches the layout page: `+0x14` byte set, `+0x15` byte set, 16-byte `movups` copy from bounds, and 16-byte `movups` copy into bounds.
- 2026-06-13 live IDA MCP `analyze_component` over the modeled base methods reported no internal call edges, shared vtable global `0x0061eb98`, constructor callees `sub_4F4A80` and `sub_4B7C50`, and destructor callees `sub_4F4A90`, `sub_4F4AC0`, and the guard-check helper.
- 2026-06-13 `xrefs_to` reconfirmed all five `MenuItem` base-vtable writes: base constructor `0x00516f41`, derived/base-construction writes `0x00517031` and `0x005171f1`, and destructor resets `0x005172e6` and `0x00517406`. `xrefs_to` for the raw state helper starts still reports no direct address references, matching their current raw-helper caveat.
- 2026-06-13 IDA MCP `analyze_function 0x00516400` and `insn_query 0x00516c40-0x00516cf3` confirm `MenuPane` consumers: relayout calls each item's metric virtual and writes a 16-byte bounds rectangle to `item+0x04`; previous/next-enabled scans test `byte ptr [item+0x14]`; `StringMenuItem` draw at `0x005170f0` tests `byte ptr [item+0x15]` before choosing highlighted rendering.

## Assignment Gate

This class is now `93/94`; its direct source-file parent [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) is recommended at `88/88`. Exact base-owned by-memory methods remain direct children. [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md) semantically owns/emits physical table child [UID:00036I][0x0061eb94-0x0061ebf0.MenuItemVtableData](by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md), while UID0000MN remains the source-file root.

## Ownership And Emission

- The formal H channel owns the complete class declaration; the formal CPP channel is only `[[CHILDREN]]`, so exact by-memory definitions emit at namespace scope.
- UID0000MN remains the current `PopupMenuControls.h/.cpp` source root. UID0001Y4 owns the shared three-class vtable semantics and routes UID00036I; this class does not emit raw table data.
- A historical `MenuItem.h/.cpp` split remains possible but lacks discriminating evidence. Direct file bypass, one-class ownership of the shared table, raw wrapper ownership, and no-slot bounds alternatives are rejected.

## Cross-References

- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)

## Changes

- 2026-08-01 B003 UID00036I ordinary implementation callback:
  - Raised `91/93 -> 93/94` while preserving owner/emitter UID0000MN, reconstructable true, position `10`, every method/field route, and all prior evidence/history.
  - Moved the complete class declaration to H, left CPP as `[[CHILDREN]]` only, removed the unsupported explicit destructor declaration, and documented implicit virtual derived destruction as the source cause of UID0002JF.
  - Added the exact RTTI two-base chain, six-slot abstract contract, `0x18` layout/no-slot bounds proof, and UID0001Y4 -> UID00036I semantic-data route.
  - Historicalized the explicit-destructor/raw-wrapper alternatives rather than deleting the earlier reasoning.

- 2026-07-24 B005 accepted UID0002JJ callback:
  - Raised `90/92 -> 91/93` while preserving owner/emitter UID0000MN, reconstructability, position `10`, class closure, and unrelated declarations/history.
  - Corrected `GetBounds` from the historical `void` draft to `RectBounds *GetBounds(RectBounds *outBounds) const`, preserved `SetBounds(const RectBounds *)`, and incorporated the exact paired-body, pointer-return, no-slot/nonvirtual, no-route, duplicate-separation, source-placement, and rejected-alternative evidence without duplicating either method body in this class router.

- 2026-07-15 B003 accepted UID0002JH callback:
  - Raised `88/90 -> 90/92`; preserved owner/emitter UID0000MN, reconstructable true, position `10`, all declarations/fields/routes, and unrelated historical evidence.
  - Applied exact R5 with the complete class-closing `};` before `[[CHILDREN]]`, keeping child definitions at namespace scope.
  - Incorporated the exact `0x18` layout including natural tail padding, public nonvirtual state API/protected bool fields, six enabled consumers, five-routed selection updater, highlighted draw use, no-vtable/no-route evidence, retained source disposition, rejected alternatives, source placement, and score cap.

- 2026-06-30 B008 empty-emitter implementation:
  - Raised from `86/88` to `88/90`, set `EMITTER_POSITION_OPTIONAL:10`, and populated the formal class declaration shell with `MenuItem`, virtual destructor, enabled/selected accessors, bounds accessors, abstract metric/text/draw virtuals, `m_bounds`, `m_enabled`, `m_selected`, and `[[CHILDREN]]`.
  - Evidence: the B008 MCP pass reconfirmed `0x00516f70`/`0x00516f80` as byte `+0x14` getter/setter, `0x00516f90`/`0x00516fa0` as byte `+0x15` selected getter/setter, `0x00516fb0`/`0x00516fd0` as exact 16-byte bounds copies at `+0x04`, and vtable slots for abstract `GetItemSize`, `GetText`, and `DrawItem`.
  - Source-quality decision: retain `m_enabled` and `m_selected` as inferred source-facing names with exact-spelling caveats, keep `RectBounds` as an existing geometry dependency, and keep this class routed through [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) without forcing a new `MenuItem.cpp` split.
- 2026-06-20 B002 [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) source-quality incorporation:
  - Score unchanged at `86/88`.
  - Evidence: exact constructor body `0x00516f00-0x00516f67`, `LObject::LObject` call at `0x004f4a80`, `MenuItem` vtable `0x0061eb98`, `InitRectBounds` call at `0x004b7c50`, no direct constructor-start caller/pointer hits, and derived constructor/destructor vtable-write family checks.
  - Source-quality decision: `word [this+0x14]=1` initializes `m_enabled=true` and `m_selected=false`; `m_stateWord=1` remains rejected as a source-level model.
- 2026-06-13 A003 Goal 2 refresh:
  - What existed before: `COMPLETION:76`, `CONFIDENCE:84`; the class was assigned to [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md), but several base method pages still used the file root as autogen parent because this class had been below the direct-parent gate.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; added live IDA evidence for modeled function extents, raw helper bytes/disassembly, vtable write xrefs, `MenuPane` state/bounds consumers, and `StringMenuItem` highlight-state consumption.
  - Evidence: active IDA MCP session `a003_goal2_rtti_type_descriptors` on `NexusTK.exe` reconfirmed the constructor/accessor/destructor extents, raw helper isolation, vtable data, and state/bounds consumers; [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md), [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md), and the exact child method pages provide the written audit trail. This older note predates B003's source-quality naming pass; current draft method C++ belongs on exact child pages while class-level source split remains under review.
- 2026-06-17 B003 source-quality incorporation:
  - Added high-probability source roles `m_enabled` for byte `+0x14` and `m_selected` for byte `+0x15`, with rejected alternatives and evidence preserved.
  - Recorded that [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) is compiler-generated wrapper output and should be represented in source as an ordinary virtual destructor.
- 2026-06-18 B003 destructor-wrapper recheck:
  - Preserved the class-level ordinary/default destructor policy for [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md).
  - Evidence: raw PE pointer search found target VA `0x005172e0` only at `.rdata:0x0061eb98` (`MenuItem` slot `+0x00`) and `.rdata:0x0061ebd0` (`SeparatorMenuItem` slot `+0x00`), with no target RVA/raw-offset hits and no `.text` rel32 callers. The wrapper object-size immediate is `0x18` / 24 bytes (Verified with `int_convert.py`), matching the recovered base `MenuItem` layout rather than `StringMenuItem`.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the abstract base menu entry role, layout, constructor/destructor, vtable, and derived-class relationships are documented, but the page remains concise and lacks full source-level method/body reconstruction. Evidence: linked menu-pane/items range, `MenuItemVtables`, `MenuItemLayouts`, IDA-confirmed starts, and pure virtual slot notes.
- Reconstructable metadata update: existed before as blank; changed to `TRUE`. Summary: IDA evidence confirms this is NexusTK menu infrastructure that must be represented in the rebuilt source; later B003 work moved first-draft source bodies to exact child method pages and kept class-level code focused on declarations/source-split policy.
- Method-map split update: existed before with only broad address rows for constructor/destructor; changed to UID links for exact by-memory child pages including state-byte accessors/setters and bounds-copy helpers. Evidence: IDA MCP `lookup_funcs`, disassembly, and byte review confirmed the modeled and raw helper bodies.
- 2026-06-02 parent update:
  - What existed before: `AUTOGEN_PARENT_UID` was blank.
  - Changed to: `AUTOGEN_PARENT_UID:0000MN`.
  - Evidence: [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) is now a valid `NexusTK/ui/menu/` file root at confidence 80, and this class page has confidence 84 with matching menu-item layout, vtable, constructor/destructor, accessor, setter, and derived-class evidence. This older note predates the current first-draft-C++ policy; current method bodies are expected on exact child pages when source-quality evidence supports them.
