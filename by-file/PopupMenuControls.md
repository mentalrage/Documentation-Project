*** UID:0000MN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PopupMenuControls

## Status

- Confidence: strong for reusable popup-menu control/menu-item ownership, current header/source contract, semantic vtable routing, and closure of the sole UID00036I empty emitter; exact historical physical splitting remains inferred.
- Proposed module folder: `ui/menu/`
- Candidate files: `ui/menu/PopupMenuControls.h` and `ui/menu/PopupMenuControls.cpp`.
- Generated source root: `auto-generated/NexusTK/ui/menu/PopupMenuControls.h/.cpp`, assembled through support/class/child emitters. Historical `class_*.cpp` names remain search context only.
- Evidence basis: existing by-* documentation and targeted IDA MCP boundary checks, including the 2026-06-07 menu aggregate/type evidence refresh. Generated source names are retained only as search context.

## Hypothesis

The current accepted reconstruction groups the reusable popup-menu control code as a small UI/menu framework source file. `PopupMenuControlPane` constructs and owns a separately allocated `MenuPane`; `MenuPane` owns the typed member-function callback and every `MenuItem`. `StringMenuItem` and `SeparatorMenuItem` are concrete entries used by popup and context-menu flows. Possible historical physical splitting remains a confidence cap, not a blocker or alternate current route.

Likely structure:

```text
ui/menu/PopupMenuControls.cpp
```

Possible split:

```text
ui/menu/MenuPane.cpp
ui/menu/MenuItem.cpp
ui/controls/PopupMenuControlPane.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `PopupMenuControlPane` | eleven exact children UID0004IM-UID0004IW inside `0x00498040-0x00498599`, plus non-contiguous UID0002Y9/UID0002YA/UID0003LM | class emitter UID0000AN | `ControlPane`-derived selector with exact tail layout, typed callback, owned MenuPane, accessors/selection notifications, `POPUPMNU.EPF` draw, mouse/key Show paths, authored destructor UID0004IN, and type-id virtual; UID0002Y9/UID0002YA are documented compiler support with no authored output. |
| [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md) / [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) | `0x0049af00-0x0049af11` | shared FunctionObjects generated-template invoke body | Popup construction/consumer route for the shared folded callback invoke body used by `MenuPane` selection. |
| `MenuPane` | `0x00516290-0x005173fe` | `class_MenuPane.cpp` | Popup menu pane with entry list, layout building, hit-testing, pointer/keyboard navigation, and selection dispatch. |
| `MenuItem` | `0x00516f00-0x0051731e` | `class_MenuItem.cpp` | Base menu item with exact `RectBounds *GetBounds(RectBounds *outBounds) const` / `void SetBounds(const RectBounds *bounds)` pair, enabled/selected state, abstract draw/metric/text contract, and compiler-generated deleting-destructor lowering. |
| `StringMenuItem` | `0x00516ff0-0x00517441` | `class_StringMenuItem.cpp` | Text menu item with object-owned inline `wchar_t m_text[128]`; exact authored methods construct, directly copy, measure, virtually export, and draw the label. UID0002J9 `GetText` is concretely consumed by PopupMenuControlPane OnDraw; UID0002JG is compiler-only/non-emitting deleting support regenerated from implicit virtual destruction. |
| `SeparatorMenuItem` | `0x005171b0-0x005172be` | `class_SeparatorMenuItem.cpp` | Non-interactive separator item with fixed dimensions/style flags and `DrawItem(GrafPort *port)` separator-line drawing. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `PopupMenuControlPane`: `0x00498040-0x0049812b`, `0x00498270-0x004984bc`, `0x004984c0-0x0049851a`, `0x00498520-0x00498599`, `0x0049af95-0x0049afa0`, `0x0049afa0-0x0049afab`, `0x0049b3b0-0x0049b417`, and `0x0049b8e0-0x0049b8e5`.
- Callback helper alias: [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md) at `0x0049af00-0x0049af11`; exact shared invoke target: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md).
- `MenuPane`: `0x00516290-0x00516345`, `0x00516350-0x005163fa`, `0x005164e0-0x005164f7`, `0x00516790-0x0051693e`, `0x00516940-0x00516a62`, `0x00516a70-0x00516ba8`, `0x005172be-0x005172c9`, `0x005172c9-0x005172d4`, and `0x00517320-0x005173fe`.
- `MenuItem`/`StringMenuItem`/`SeparatorMenuItem`: `0x00516f00-0x00517441` as listed in the memory page.

IDA caller evidence ties `PopupMenuControlPane::OnDraw` to `MenuPane::GetItemByIndex`, and older Wave2 notes record that `0x005164e0` was restored under `MenuPane` after reviewing `PopupMenuControlPane` and `RadioGroupControlPane` callers.

## Ownership Notes

- Keep this separate from item-specific menu dialogs such as `ServerItemMenuDialog` and from packet-driven message/menu-question dialogs.
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md) begins immediately after the menu item destructor padding, but it is a merchant/dialog factory island rather than reusable popup-menu item code.
- `RightButtonMenuPane`, `VoteMenuPane`, and `MenuVarietyPane` use similar drawing idioms and SUBWIN/MENUVAR resources, but they are gameplay/menu entry points and should be documented as neighboring feature panes, not as proof that every menu-named class belongs in this core file.
- The complex template callback class name caused a Wave3 lookup timeout; use [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md) as the short alias and use the generated source file plus IDA boundary for evidence. B010 UID00011X current MCP proof now narrows the exact body as a shared/folded one-argument FunctionObjects invoke wrapper: [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) is owned/emitted by [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md), while this file owns the popup-menu construction/consumer side. The popup constructor still stores vtable `0x006187e8` at `0x004980bc`, target `0x00498220`, zero adjustment, and the captured pane pointer in the 24-byte callback object; six non-popup callback-template vtables also point at the same invoke body.
- Historical generated output omitted PopupMenuControlPane bodies behind a false no-children marker. UID00011F is now a non-emitting split index and exact UID0004IM-UID0004IW bodies emit through class UID0000AN. MenuPane's separate unresolved class/body work remains support scope and does not justify duplicating popup methods.
- 2026-05-26 IDA MCP resolved the concrete menu-item vtables at `0x0061eb98`, `0x0061ebb4`, and `0x0061ebd0`; see [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md). Current generated metadata reports `vtable_count: 0` for the three menu item classes.
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md) records the shared bounds/state layout and the `StringMenuItem` inline `wchar_t[0x80]` label buffer at offset `+0x18`.
- 2026-06-17 B003 source-quality incorporation records current best names for the menu item source model: `MenuItem +0x14` is `m_enabled`, `MenuItem +0x15` is `m_selected`/highlighted draw state, `StringMenuItem +0x18` is inline `wchar_t m_text[0x80]`, separator size returns are height-first `MenuItemMetrics`, separator style returns use a 16-bit `MenuItemStyleFlags` wrapper, and scalar deleting-destructor ranges are compiler-generated wrappers regenerated from ordinary virtual destructors.
- 2026-06-07 supporting-page refresh on [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md) strengthened this file parent: the menu aggregate now records the current IDB hash, exact recognized function inventory, endpoint padding before [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md), constructor/open-helper caller evidence from [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md), internal navigation caller relationships, relayout behavior at `0x00516400`, and the raw `0x00516ba8-0x00516dd0` jump-table/helper caveat.
- 2026-06-11 Batch166 split the former raw `MenuPane` tail in [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md) into [UID:000376][0x00516ba8-0x00516c40.MenuPaneKeyDispatchTables](by-memory/0x00516ba8-0x00516c40.MenuPaneKeyDispatchTables.md), [UID:000377][0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw](by-memory/0x00516c40-0x00516c9a.MenuPaneFindPreviousEnabledItemRaw.md), [UID:000378][0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw](by-memory/0x00516ca0-0x00516cf3.MenuPaneFindNextEnabledItemRaw.md), and [UID:000379][0x00516d00-0x00516dc2.MenuPaneRecomputeItemBoundsRaw](by-memory/0x00516d00-0x00516dc2.MenuPaneRecomputeItemBoundsRaw.md). The split removes the prior raw-helper caveat enough for `0001BK` to attach here, while preserving the note that a later original-source review may split `MenuPane` into a narrower file.
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md) and [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md) independently tie `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem` to the same compact menu-item source family. `by-project-structure/proposed-source-tree.md` also names `PopupMenuControls.cpp` as the likely owner for `PopupMenuControlPane`, `MenuPane`, `MenuItem`, `StringMenuItem`, `SeparatorMenuItem`, and the popup selection callback helper.

## UID0002JH MenuItem State-Family Incorporation

The current source-facing nonvirtual state API is [UID:0002J4][0x00516f70-0x00516f74.MenuItemIsEnabled](by-memory/0x00516f70-0x00516f74.MenuItemIsEnabled.md), [UID:0002JH][0x00516f80-0x00516f8d.MenuItemSetEnabled](by-memory/0x00516f80-0x00516f8d.MenuItemSetEnabled.md), [UID:0002J5][0x00516f90-0x00516f94.MenuItemIsSelected](by-memory/0x00516f90-0x00516f94.MenuItemIsSelected.md), and [UID:0002JI][0x00516fa0-0x00516fad.MenuItemSetSelected](by-memory/0x00516fa0-0x00516fad.MenuItemSetSelected.md). The two getters are exact modeled four-byte direct bool returns; the setters are exact 13-byte raw/unmodeled retained out-of-line bool assignments. All four emit through class UID00007V, not directly through the file page.

Fresh 2026-07-15 MCP session `64c11373` confirms bool `m_enabled` at `+0x14` from constructor defaults, disabled separator construction, and six pointer/keyboard/navigation consumers. It confirms bool `m_selected` at `+0x15` from the five-routed old/new selection updater and `StringMenuItem::DrawItem` highlighted branch. Exact vtable reads prove the state API is nonvirtual. Zero surviving direct start xrefs, pointers, bounded address operands, whole-file VA/RVA/raw-offset patterns, and executable rel32 routes cap liveness/original-name confidence but do not negate complete source bodies or justify compiler/no-code treatment.

Generic state flags, raw byte/word fields, bitfields, visibility/active/style interpretations, MenuPane ownership, direct file ownership, compiler glue, inline-only, and no-code alternatives are rejected. The exact `0x18` `MenuItem` layout is `RectBounds` at `+0x04..+0x13`, bools at `+0x14/+0x15`, and natural tail padding at `+0x16..+0x17`; String storage begins at `+0x18`. The consolidated `PopupMenuControls.cpp` route remains current because no binary/source artifact proves a physical `MenuItem.cpp` split.

The class formals for `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem` now close each complete declaration before `[[CHILDREN]]`. This preserves declarations inside the class and routes every qualified child definition to namespace scope. Historical validator command `000000012947` emitted all state bodies and no empty marker but placed children before class closure; that pre-callback structural state is superseded by the current ordinary formals and the callback's waited generated verification.

## UID0002JJ MenuItem Bounds-Pair Incorporation

[UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemGetBounds](by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md) and [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBounds](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md) are the exact retained nonvirtual bounds API over `MenuItem::m_bounds` at `+0x04`. Both are 17-byte, seven-instruction, independently fenced whole-`RectBounds` copy methods. The getter's output pointer remains in `eax`, resolving the source signature as `RectBounds *GetBounds(RectBounds *outBounds) const`; the setter only reads its input and remains `void SetBounds(const RectBounds *bounds)`.

The exact target hashes are `EA9AEECC35E759BF98B38B96CC4E91ED0B2D7916497F84EC4F663FDF693AB315` and `C21224F940494FD4BBCB8BBC163A8652492375B88E6A936AFAC51678977F7076`. Exhaustive route checks found no direct xref, encoded VA/RVA/raw offset, immediate, member pointer, vtable entry, or rel32 route to either start. Those negatives remain liveness/original-name confidence caps, not a compiler/no-code disposition: paired exact bodies, constructor/relayout/draw field evidence, and no wrapper/table traits support authored methods.

The complete `MenuItem` vtable contains destructor, inherited/no-op, and three purecall slots only; neither bounds method is virtual. The getter's byte-identical body at `0x00554ae0` belongs to a separately modeled Region/motion comparator with ten xrefs from nine callers and does not own or cover UID0002JJ. `GetBounds`/`SetBounds` is preferred over `CopyBounds` and `GetRect`/`SetRect`; reference-return and no-argument value-return alternatives conflict with the explicit stack-pointer ABI.

Method declarations belong to [UID:00007V][MenuItem](by-class/MenuItem.md), exact bodies to the two by-memory pages, and compiler vtable data remains blank source output. This file stays the `NexusTK/ui/menu/PopupMenuControls.cpp` source root. The possible historical `MenuItem.cpp` physical split remains an explicit confidence cap, but there is no evidence strong enough to reroute or duplicate the pair.

## UID00011F PopupMenuControlPane Incorporation

The accepted B005 MCP pass during database session `bf5519ae` resolves the complete compact popup method run and its support:

- [UID:0004IM][0x00498040-0x0049812b.PopupMenuControlPaneConstructor](by-memory/0x00498040-0x0049812b.PopupMenuControlPaneConstructor.md) constructor takes `DialogPane *` plus `const RectBounds *`, not historical `menuType`/`parentBlock`; ten callers agree. It calls `ControlPane(3, bounds)`, binds a 24-byte `PlainMemberFunctionObject` to `SetSelectedIndex(long)`, owns MenuPane at `+0x108`, initializes selected index `+0x10c` to `-1`, stores parent dialog `+0x110`, and establishes complete size `0x114`.
- [UID:0004IN][0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw](by-memory/0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw.md) is the 53-byte authored ordinary destructor, current CB62 name/type `PopupMenuControlPane_destructor` / `void __thiscall(PopupMenuControlPane *this)`, exact SHA256 `2DA7AA820932B95231CED18AA16EF9CD1DAF71E4C249A6D81490BBCA50D41F0A`. It deletes `m_menuPane`; MenuPane deletes its items/list/callback. Its no-incoming-xref state remains a retained-body confidence cap, not a reason to replace source with ABI output.
- [UID:0002YA][0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor](by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md) is exact semantic class evidence but `RECONSTRUCTABLE:FALSE` and non-emitting: the 103-byte compiler wrapper restores all three vptr views, performs ordinary/base cleanup, and dispatches hidden flags among no free, normal operator delete, and a `0x114` size/one-byte-no-op path. [UID:0002Y9][0x0049af95-0x0049afab.PopupMenuControlPaneAdjustorThunks](by-memory/0x0049af95-0x0049afab.PopupMenuControlPaneAdjustorThunks.md) is likewise FALSE/non-emitting and contains only exact `this-0xa0`/`this-0xa4` tail adjustors.
- Generated source must therefore contain the class declaration and exactly one authored UID0004IN destructor body, with zero UID0002YA marker/body and zero UID0002Y9 marker/body. The former UID0002YA comment-only output was a historical empty-marker workaround and is superseded; compiler ABI support is regenerated from the class/destructor source.
- [UID:0004IO][0x00498170-0x0049817f.PopupMenuControlPaneAppendItem](by-memory/0x00498170-0x0049817f.PopupMenuControlPaneAppendItem.md)/[UID:0004IP][0x00498180-0x0049818f.PopupMenuControlPaneGetItem](by-memory/0x00498180-0x0049818f.PopupMenuControlPaneGetItem.md)/[UID:0004IQ][0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount](by-memory/0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount.md)/[UID:0004IR][0x004981a0-0x004981a7.PopupMenuControlPaneGetSelectedIndex](by-memory/0x004981a0-0x004981a7.PopupMenuControlPaneGetSelectedIndex.md) provide `AppendItem`, `GetItem`, `GetItemCount`, and `GetSelectedIndex`, with direct caller counts 54/11/12/17. [UID:0004IT][0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex](by-memory/0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md) `SetSelectedIndex(long)` has sixteen code callers plus callback binding, rejects `-1`/no-change, invalidates bounds, and sends parent code 10.
- [UID:0004IS][0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw](by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md) is a retained private source method now modeled by current IDA as `PopupMenuControlPane_SelectItemAndNotifyParent`, exact size `0x6f`. Its 111 bytes, 49 instructions, seven coherent blocks, SHA256 `6DC833EECFD6DDF74E589850D46D0ADA9D992DAD5588742A3C67CC219C3255C7`, and exact `0xcc` fences prove the body. It source-level calls `SetSelectedIndex(long)`, matching the optimized inline code-10 path, then independently sends literal code 12 through the parent cached before the setter call. Zero incoming code/data xrefs, VA/RVA pointer hits, vtable/data slots, and callback routes remain a liveness/name cap; historical raw/unmodeled state is discovery provenance. `SelectItemAndNotifyParent` is behavior-descriptive, while close/commit/accept/dismiss names remain rejected because FolderSelect consumes only code 10 and the other checked parent handlers do not prove code-12 semantics.
- [UID:0004IU][0x00498270-0x004984bc.PopupMenuControlPaneOnDraw](by-memory/0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md) is primary-vtable draw using exact `POPUPMNU.EPF` frames 0/1/2, `NPAL8.PAL`, selected text, and disabled/active frame states. [UID:0004IV][0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent](by-memory/0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent.md) event-kind-3 mouse hit and [UID:0004IW][0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown](by-memory/0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown.md) key-kind-8/translated-`0x83`/state-zero path both call `MenuPane::Show(m_parentDialog, screenX + width - 1, screenY, m_selectedIndex)`.
- [UID:0003LM][0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId](by-memory/0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId.md) emits `GetControlType()` returning 12. UID00011X remains the folded shared FunctionObjects invoke wrapper and is not emitted in this file as a concrete body.

Primary/secondary/tertiary popup vtables are `0x00617fb8`, `0x00618020`, and `0x00618050`. Raw methods have unique complete signatures and exact `0xcc` fences; absent direct routes cap liveness/name confidence but do not support padding, compiler glue, or no-owner classification. Every byte in UID00011F is now child code or alignment, and successor `ScrollableControlPane` begins at `0x004985a0` after seven `0xcc` bytes.

UID0004IS's formal definition remains on its exact by-memory child and is emitted through class UID0000AN. Its private declaration is now physically owned by UID0000AN's formal H channel. The class CPP channel contains only `[[CHILDREN]]`, so the generated module carries the declaration in `PopupMenuControls.h` and exactly one qualified definition in `PopupMenuControls.cpp` rather than embedding a class declaration in the source file.

## UID0002J9 StringMenuItem GetText Closure

[UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) remains an exact authored virtual method owned/emitted by [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) through this file root. Its half-open range is `[0x005170d0,0x005170e9)`, followed by seven `0xcc` bytes. Current ABI is `errno_t __thiscall(const StringMenuItem *this, wchar_t *destination, rsize_t sizeInWords)`; source remains `errno_t StringMenuItem::GetText(wchar_t *destination, size_t sizeInWords) const` and directly returns `wcscpy_s(destination, sizeInWords, m_text)`. The target's formal CPP is already exact, its H stays blank, and the declaration remains in the owning class H channel.

The method copies object-owned inline `m_text[128]` at `+0x18` into caller-owned storage and preserves CRT success `0`, `EINVAL` / `22`, and `ERANGE` / `34` behavior, including clearing a valid destination on source-invalid/range failure. Physical String vtable cell `0x0061ebc4` is slot `+0x10` and points to UID0002J9. [UID:0004IU][0x00498270-0x004984bc.PopupMenuControlPaneOnDraw](by-memory/0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md) obtains a selected `MenuItem *`, pushes `0x100` at `0x00498404`, addresses a 256-wide local, and calls `[edx+0x10]` at `0x00498414`; it ignores EAX and draws the destination. This is concrete consumer evidence, not ownership transfer.

[UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) remains a separate direct nonvirtual helper with eleven callers and no vtable cell. Historical `void CopyTextToWideBuffer`, decompiler `const wchar_t *` receiver, generic file ownership, consumer-unknown, heap/borrowed/string-object storage, and forced `StringMenuItem.cpp` split assumptions are superseded but retained as search provenance. The consolidated `PopupMenuControls.h/.cpp` route remains the best coherent route because no stronger physical-file evidence exists.

Support-only [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) is now `93/95`, semantic owner `0000E8`, `RECONSTRUCTABLE:FALSE`, blank emitter/position, blank CPP/H, and `Nested:0`. Its exact vtable-only wrapper resets the base vptr, performs base cleanup and hidden deleting-flag dispatch, uses delete size `0x118`, and needs no inline-text cleanup. Implicit virtual derived destruction regenerates it; the former comment-only proof marker is historical and must not survive in generated source.

## Source Placement Decision

Keep `NexusTK/ui/menu/PopupMenuControls.cpp` as the current source root. PopupMenuControlPane vtables/fields/public callers, authored ordinary destructor, and compiler deleting routes establish class ownership; MenuPane is an owned dependency; feature dialogs are consumers; FunctionObjects owns shared callback-template code; DialogPane/ControlPane/EventMan/renderer pages own infrastructure. Direct file emission bypassing the class, MenuPane ownership of popup bodies, caller-feature ownership, a new raw-island file, handwritten UID0002Y9/UID0002YA bodies, and a forced `PopupMenuControlPane.cpp` split are rejected. Exact original physical source splitting remains unresolved but has no emitter or C++ impact under the accepted route.

## Source Placement And Routing

- Current authored module root is `NexusTK/ui/menu/PopupMenuControls.h/.cpp` under UID0000MN.
- Shared support declarations emit from [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md) into the H channel. Complete `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem` declarations emit from class UIDs 00007V/0000E8/0000CY into H.
- Exact method definitions remain owned by their by-memory pages and emit through the respective class CPP `[[CHILDREN]]` hooks.
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md) is the semantic owner of [UID:00036I][0x0061eb94-0x0061ebf0.MenuItemVtableData](by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md). The route is UID00036I -> UID0001Y4 -> UID0000MN, so compiler data is accounted for without a raw file-level table.
- Feature dialogs remain consumers, FunctionObjects retains shared callback-template ownership, and the broad UID00025T memory page remains physical containment only.

## Header And Source Contract

- `PopupMenuControls.h` contains support includes/forward declarations, `MenuItemMetrics`, `MenuItemStyleFlags`, and the four complete `MenuItem`, `StringMenuItem`, `SeparatorMenuItem`, and `PopupMenuControlPane` declarations exactly once.
- `PopupMenuControls.cpp` includes `PopupMenuControls.h` once before qualified child definitions. Class CPP channels contain only `[[CHILDREN]]`; declarations no longer appear in CPP.
- Compiler COL/RTTI/vtable data and scalar deleting wrappers are regenerated from class declarations, virtual ordering, and authored method bodies. Neither the header nor source contains fixed-address tables, decorated compiler objects, or deleting-wrapper functions.
- UID00036I emits the exact no-code compiler-regeneration marker through UID0001Y4. This closes the sole remaining empty emitter for the current file without inventing source code for `.rdata`.
- UID0002J9 contributes exactly one `StringMenuItem::GetText` definition in `PopupMenuControls.cpp`; UID0000E8 contributes exactly one matching virtual declaration in `PopupMenuControls.h`. UID0002JG contributes zero marker and zero body in both files because it is false/non-emitting compiler support.

## Historical Source Split

A historical `MenuItem.h/.cpp`, `MenuPane.cpp`, or `PopupMenuControlPane.cpp` physical split remains plausible because compiler output does not encode original filenames. No current PDB, source archive, include trace, or uniquely grouped artifact discriminates among those spellings. The consolidated `PopupMenuControls.h/.cpp` route is therefore the best current coherent reconstruction and is not blocked by that uncertainty. The caveat caps perfect source-placement confidence but does not justify duplicate output, raw-island files, or a speculative split.

## Assignment Gate Notes

This file is now `88/88`, enough to serve as the direct source root for popup/menu classes and semantic support pages that clear the child gate. UID0000AN remains `90/92` with complete declaration and exact children. The score increase reflects the explicit H/CPP contract, UID0001Y4 -> UID00036I semantic route, resolved class declarations, and closure of the sole empty emitter. Confidence remains below final-audit level because an original source archive could still refine the physical split.

B003's 2026-06-17 popup-menu controls report keeps this file as the source root while routing method-level children through their concrete classes when those classes clear the gate. `StringMenuItem` methods emit through [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md), separator methods emit through [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md), and base menu item methods emit through [UID:00007V][MenuItem](by-class/MenuItem.md), with this file still owning the reconstructed `NexusTK/ui/menu/PopupMenuControls.cpp` grouping.

B015 [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) recheck keeps `SeparatorMenuItem` constructor ownership on [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md) and source-file routing through this `PopupMenuControls.cpp` root. The constructor is now first-draft C++ ready; the possible later `MenuItem.cpp`/`MenuPane.cpp` split remains a source-layout caveat, not a blocker for the current route.

B002 [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) recheck keeps the base constructor routed through [UID:00007V][MenuItem](by-class/MenuItem.md) with this `PopupMenuControls.cpp` file root. The constructor is now first-draft C++ ready as `MenuItem::MenuItem() : LObject()` followed by `InitRectBounds(&m_bounds, 0, 0, 0, 0)`, `m_enabled=true`, and `m_selected=false`; the binary `word [this+0x14]=1` is a compiler-coalesced adjacent-byte store, not a source `m_stateWord` assignment. The adjacent `0x00516ef0-0x00516eff` `MenuPane` thunk remains separate support coverage and is not part of the constructor route.

B004 [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) recheck keeps separator draw ownership routed through [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md) with this `PopupMenuControls.cpp` file root. The method is now first-draft C++ ready as `void SeparatorMenuItem::DrawItem(GrafPort *port)`, clears active draw/blit mode, sets draw color `0x80`, builds a horizontally inset centered `RectBounds`, and dispatches Surface slot 7 as a fill/invalidate callback. The page name `DrawSeparator` remains a behavior label, not a separate virtual contract.

B012 [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) recheck keeps string-item constructor ownership routed through [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) with this `PopupMenuControls.cpp` file root. The constructor is now first-draft C++ ready as `StringMenuItem::StringMenuItem(const wchar_t *text) : MenuItem() { wcscpy_s(m_text, _countof(m_text), text); }`; the expanded base-construction/vtable/EH/security-cookie sequence is compiler lowering, while the 54 direct construction xrefs through FolderSelectDialog, MusicControlDialog, TerminalSetupPane, and UserInfoDialogPane remain consumer evidence rather than alternate owners.

B013 [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) recheck keeps string-item metric ownership routed through [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) with this `PopupMenuControls.cpp` file root. The method is now first-draft C++ ready as `MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const`; the binary's hidden result pointer is MSVC value-return lowering, while `GrafPort::GetTextWidth`, inline `m_text[0x80]`, height-first `MenuItemMetrics`, and the `24` total-horizontal-padding interpretation are documented on the target and layout pages.

B003 [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) recheck keeps the direct string-item copy helper routed through [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) with this `PopupMenuControls.cpp` file root. The method is now first-draft C++ ready as `errno_t StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const`. MCP session `b880584f` confirms the exact 25-byte body, SHA256 prefix `a858cb8bb45508d2`, seven-byte `0xcc` successor padding, `_wcscpy_s` callee, `retn 8`, eleven direct FolderSelect/Music/Terminal/UserInfo code xrefs, and the accepted `m_text[0x80]` field at byte offset `+0x18`. This does not force a narrower `MenuItem.cpp` or class-specific `StringMenuItem.cpp` split: current evidence supports [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md) as method owner/emitter and this file as the source-root grouping. `CopyTextToWideBuffer` is retained only as a historical/generated alias, while `GetText` remains the vtable sibling [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) at slot `+0x10` / `0x0061ebc4`.

## Cross-References

- [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md)
- [UID:00007W][MenuPane](by-class/MenuPane.md)
- [UID:0000V8][PopupMenuSelectionCallback_0049AF00](by-item/PopupMenuSelectionCallback_0049AF00.md)
- [UID:0000AK][PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_](by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00007V][MenuItem](by-class/MenuItem.md)
- [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md)
- [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md)
- [UID:0001Y4][MenuItemVtables](by-type/by-vtable/MenuItemVtables.md)
- [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md)
- [UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemGetBounds](by-memory/0x00516fb0-0x00516fc1.MenuItemGetBounds.md)
- [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBounds](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBounds.md)
- [UID:00011F][0x00498040-0x00498599.PopupMenuControlPaneCore](by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md)
- [UID:0003LM][0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId](by-memory/0x0049b8e0-0x0049b8e5.PopupMenuControlPaneTypeId.md)
- [UID:0004IM][0x00498040-0x0049812b.PopupMenuControlPaneConstructor](by-memory/0x00498040-0x0049812b.PopupMenuControlPaneConstructor.md)
- [UID:0004IN][0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw](by-memory/0x00498130-0x00498165.PopupMenuControlPaneDestructorRaw.md)
- [UID:0004IO][0x00498170-0x0049817f.PopupMenuControlPaneAppendItem](by-memory/0x00498170-0x0049817f.PopupMenuControlPaneAppendItem.md)
- [UID:0004IP][0x00498180-0x0049818f.PopupMenuControlPaneGetItem](by-memory/0x00498180-0x0049818f.PopupMenuControlPaneGetItem.md)
- [UID:0004IQ][0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount](by-memory/0x00498190-0x0049819b.PopupMenuControlPaneGetItemCount.md)
- [UID:0004IR][0x004981a0-0x004981a7.PopupMenuControlPaneGetSelectedIndex](by-memory/0x004981a0-0x004981a7.PopupMenuControlPaneGetSelectedIndex.md)
- [UID:0004IS][0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw](by-memory/0x004981b0-0x0049821f.PopupMenuControlPaneSelectItemAndNotifyParentRaw.md)
- [UID:0004IT][0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex](by-memory/0x00498220-0x0049826d.PopupMenuControlPaneSetSelectedIndex.md)
- [UID:0004IU][0x00498270-0x004984bc.PopupMenuControlPaneOnDraw](by-memory/0x00498270-0x004984bc.PopupMenuControlPaneOnDraw.md)
- [UID:0004IV][0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent](by-memory/0x004984c0-0x0049851a.PopupMenuControlPaneOnMouseEvent.md)
- [UID:0004IW][0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown](by-memory/0x00498520-0x00498599.PopupMenuControlPaneOnKeyDown.md)
- [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md)
- [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)

## Changes

- 2026-08-11 B010 UID0002J9 source-root synchronization:
  - Preserved `88/88`, `CANONICAL_OWNER:FILE`, `NexusTK/ui/menu/`, every existing popup/MenuPane/menu-item/callback route, complete H/CPP contract, UID00036I compiler-data policy, and historical source-split caveat.
  - Added the exact UID0002J9 behavior/ABI/CRT/lifetime/vtable/consumer closure and retained UID0002J7 as the distinct direct helper.
  - Reconciled UID0002JG as `93/95`, false/non-emitting compiler support with blank CPP/H and implicit virtual derived destruction. Required generated state is one GetText definition/declaration and zero UID0002JG marker/body; the former proof-comment workaround is historical only.
- 2026-08-10 B002 accepted UID0004IS source-root synchronization:
  - Preserved `88/88`, `CANONICAL_OWNER:FILE`, `NexusTK/ui/menu/`, every existing popup/MenuPane/menu-item/callback route, and the bounded historical source-split caveat.
  - Replaced stale UID0004IS raw/no-function wording with the current exact modeled/no-route state, source-level setter/code-10 parity, independent literal code-12 behavior, exhaustive route negatives, and historical raw discovery provenance.
  - Reconciled the physical header/source contract: UID0000AN now emits the complete PopupMenuControlPane declaration through H, its CPP contains only `[[CHILDREN]]`, and UID0004IS remains the sole owner of its qualified definition.

- 2026-08-01 B003 UID00036I ordinary implementation callback:
  - Raised `86/85 -> 88/88` while preserving `CANONICAL_OWNER:FILE`, `NexusTK/ui/menu/`, all popup/MenuPane/menu-item/callback routes, and every historical changes entry.
  - Established `PopupMenuControls.h/.cpp` as the current coherent module pair, with support/class declarations in H, one CPP include, exact method bodies through class children, and no raw RTTI/vtable/deleting-wrapper output.
  - Added the UID00036I -> UID0001Y4 -> UID0000MN semantic route and documented closure of the file's sole empty emitter through the exact compiler-regeneration marker.
  - Retained possible historical `MenuItem.cpp`, `MenuPane.cpp`, and `PopupMenuControlPane.cpp` splits as a bounded confidence caveat rather than an implementation blocker.

- 2026-07-24 B005 UID0002YA-family accepted source-root synchronization:
  - Preserved score/path/file ownership at `86/85`, `NexusTK/ui/menu/`, all existing popup/MenuPane/menu-item/callback evidence, and the possible physical source-split confidence cap.
  - Recorded UID0004IN as the sole authored popup destructor with current exact identity, UID0002Y9 as two compiler adjustors, and UID0002YA as the compiler complete-object deleting wrapper including the hidden bit-1/bit-4 no-op distinction.
  - Historicalized the former UID0002YA comment-only empty-marker workaround and established the required generated state: one UID0004IN body and no UID0002Y9/UID0002YA source marker or body.

- 2026-07-24 B005 accepted UID0002JJ source-root synchronization:
  - Score/path/FILE ownership remain unchanged at `86/85` and `NexusTK/ui/menu/`.
  - Incorporated the UID-preserving `MenuItemGetBounds`/`MenuItemSetBounds` routes, exact paired signatures, whole-object bounds behavior, hashes/fences, exhaustive no-route evidence, nonvirtual vtable exclusion, field producer/consumer evidence, comparator separation, naming/ABI rejections, and source-placement decision.
  - Preserved the consolidated source root and all popup/MenuPane/callback/state/StringMenuItem/SeparatorMenuItem/compiler/history facts; no method body was duplicated in this file router, and the possible physical `MenuItem.cpp` split remains a confidence cap rather than a current route.

- 2026-07-15 B003 accepted UID0002JH source-root synchronization:
  - Score/path/FILE ownership remain unchanged at `86/85` and `NexusTK/ui/menu/`.
  - Added the four validator-renamed enabled/selected method routes, exact bool/layout/constructor/consumer/selection-update/vtable/no-route evidence, retained-source and rejected-alternative decisions, and historicalized command-12947 class-closure defect.
  - Recorded the corrected MenuItem/StringMenuItem/SeparatorMenuItem class-close-before-children route while preserving every existing popup/MenuPane/callback/FunctionObjects/menu-item/compiler/history/source-split fact.

- 2026-07-12 B005 UID00011F source-root synchronization:
  - Score, `FILE` ownership, and `NexusTK/ui/menu/` path remain unchanged at `86/85`.
  - Replaced the stale omitted-popup/no-children state with the exact UID0004IM-UID0004IW child route through class UID0000AN, complete constructor/layout/callback/lifetime/accessor/notification/draw/input/type behavior, raw liveness negatives, successor padding, and explicit UID00011X/UID0002Y9/UID0002YA non-duplication.
  - Preserved the consolidated PopupMenuControls source route and historical possible physical splits as a confidence cap; rejected direct file emission, MenuPane/caller ownership, and a raw-island file.

- 2026-06-30 B008 empty-emitter family implementation:
  - Score and metadata unchanged at `86/85`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`.
  - Implemented the accepted 17-marker family repair without moving the source root: [UID:0001V5][MenuItemLayouts](by-type/by-struct/MenuItemLayouts.md) now emits `MenuItemMetrics` and `MenuItemStyleFlags`; [UID:00007V][MenuItem](by-class/MenuItem.md), [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md), and [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md) now emit declaration shells with `[[CHILDREN]]`; the tiny `MenuItem` enabled/selected/bounds helpers now emit exact first-draft methods; and compiler scalar deleting destructors, aggregates, and vtable evidence now emit explicit no-standalone-source markers rather than raw wrapper/vtable code.
  - Source-placement decision: keep `PopupMenuControls.cpp` as the current generated source root. The possible later original-source split into `MenuPane.cpp`, `MenuItem.cpp`, or `PopupMenuControlPane.cpp` remains the confidence cap at `85`, but no current empty marker requires moving this family away from [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md).
- 2026-06-29 B010 UID00011X implementation callback:
  - Score unchanged at `86/85`.
  - Clarified that [UID:00011X][0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke](by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md) is shared/folded FunctionObjects invoke glue, not popup-exclusive source.
  - Preserved this file's ownership of popup construction/consumer behavior: the popup construction route stores callback vtable `0x006187e8`, bound target `0x00498220`, zero adjustment, and the captured pane pointer, while [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) owns the reusable callback-template body.
- 2026-06-20 B002 MenuItem constructor source-quality implementation:
  - Score unchanged at `86/85`.
  - Evidence: [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md) now has first-draft constructor C++, exact raw-body evidence, no direct constructor-start caller/pointer hits, and source-quality resolution of `m_enabled`/`m_selected`.
  - Routing decision: keep source output under this reusable popup-menu file family through [UID:00007V][MenuItem](by-class/MenuItem.md); do not create a new `MenuItem.cpp` split from this evidence alone.
- 2026-06-20 B004 SeparatorMenuItem draw source-quality implementation:
  - Score unchanged at `86/85`.
  - Evidence: recorded that [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) now emits first-draft `SeparatorMenuItem::DrawItem(GrafPort *port)` through the concrete class route, with this file remaining the source-root grouping.
- 2026-06-21 B012 StringMenuItem constructor source-quality implementation:
  - Score unchanged at `86/85`.
  - Evidence: recorded that [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md) now emits first-draft `StringMenuItem::StringMenuItem(const wchar_t *text)` through the concrete class route, with this file remaining the source-root grouping.
- 2026-06-22 B013 StringMenuItem metric source-quality implementation:
  - Score unchanged at `86/85`.
  - Evidence: recorded that [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) now emits first-draft `StringMenuItem::GetItemSize(GrafPort *port) const` through the concrete class route, with this file remaining the source-root grouping.
- 2026-06-23 B003 StringMenuItem direct copy-text implementation:
  - Score unchanged at `86/85`.
  - Evidence: recorded that [UID:0002J7][0x00517070-0x00517089.StringMenuItemCopyText](by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md) now emits first-draft `StringMenuItem::CopyText(wchar_t *destination, size_t sizeInWords) const` through [UID:0000E8][StringMenuItem](by-class/StringMenuItem.md), with this file remaining the `PopupMenuControls.cpp` source-root grouping.
  - Source-placement decision: this implementation rejects a forced source split, direct file ownership/emission for the method, caller-feature ownership, base `MenuItem` ownership, and merge with [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md). `CopyTextToWideBuffer` is preserved only as a historical alias because current MCP evidence proves an `errno_t` body.
- 2026-06-12 C001 barrier repair:
  - Score unchanged at `86/85`; updated `PopupMenuControlPane` proposed contents from a sparse `0x00498040-0x0049b8e5` range to compact core plus exact non-contiguous child pages.
  - Evidence: IDA MCP confirms `0x00498599-0x004985a0` padding before `ScrollableControlPane`, popup type-id helper `0x0049b8e0-0x0049b8e5`, and unrelated intervening control/destructor ownership.
- 2026-06-19 B015 SeparatorMenuItem constructor source-quality implementation:
  - Score unchanged at `86/85`.
  - Evidence: recorded that [UID:0002JB][0x005171b0-0x0051721d.SeparatorMenuItemConstructor](by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md) remains routed through [UID:0000CY][SeparatorMenuItem](by-class/SeparatorMenuItem.md) and this file root, with first-draft constructor C++ ready and no current source-file split blocker.
- 2026-06-11 A002 Batch166:
  - No score change; this page remains `86/85`.
  - Summary/evidence: recorded the exact `MenuPane` raw-helper split that let [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md) clear the strict child-plus-parent gate and attach to this source-file parent.
- 2026-06-07 A010 Batch096 parent-gate update:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:80`, below the corrected 85/85 parent gate for menu-item class coverage toss-ups.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:85`.
  - Summary/evidence: associated pages now document the 2026-06-07 `MenuPaneAndItems` live IDA refresh, exact menu-item child method pages, compact menu-item vtable run, shared layout offsets, `PopupMenuControlPane` constructor/open-helper caller links, endpoint padding before the menu-dialog factory island, and proposed-source-tree ownership for the reusable popup-menu source. Confidence stays at the gate rather than higher because the possible `MenuPane.cpp`/`MenuItem.cpp` split remains a real source-layout caveat.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents the popup menu framework hypothesis, proposed contents, IDA boundary evidence, ownership notes, vtable/layout refs, generated callback caveat, and cross-references; confidence remains capped by exact split between control, menu pane, and menu item sources.
- 2026-06-02 projected path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and confidence stayed at `78`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"` and `CONFIDENCE:80`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` names `PopupMenuControls.cpp` under `ui/menu/`, and this file already records IDA-backed popup-control, menu-pane, menu-item, vtable, layout, and callback evidence. Confidence remains capped at 80 because a later source-layout pass may split `MenuPane.cpp`, `MenuItem.cpp`, or `PopupMenuControlPane.cpp` from the consolidated file.
