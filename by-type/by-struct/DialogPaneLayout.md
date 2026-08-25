*** UID:0001U4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DialogPane Layout

## Status

- Entity kind: class layout / inherited dialog state.
- Covered class: [UID:00003T][DialogPane](by-class/DialogPane.md) and derived modal/modeless dialog classes.
- Likely owner header/source: [UID:0000IT][DialogPane](by-file/DialogPane.md).
- Parent attachment: attached to [UID:00003T][DialogPane](by-class/DialogPane.md), which is scored `93/96`; this layout page is `92/95`, and source file [UID:0000IT][DialogPane](by-file/DialogPane.md) is `93/95`.
- Confidence: very strong for listed offsets, vtable-view offsets, generic List storage, exact EPFTileContext background region, trailing int/bool state, and method consumers; medium-high for final stripped lexical spellings and visual-state enum names.
- Current generated source hint: `source-3/simroot_v2/class_DialogPane.cpp`; use it only as a lead, with IDA/MCP controlling the offsets.

## Observed Layout

`DialogPane` is a [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)-derived object with three vtable views. IDA confirms the primary object at `+0x00`, a secondary view at `+0xa0`, and a tertiary view at `+0xa4`. Many derived dialogs use the base fields below directly, so these offsets should be treated as inherited state rather than feature-dialog-local storage.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | primary vptr, `DialogPane` table `0x00618a64` | Constructor and cleanup body store the primary vtable at object start. |
| `+0x04-+0xf7` | inherited `Pane` state | The constructor calls the `Pane` constructor before installing `DialogPane` vtables; see [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). |
| `+0xa0` | secondary/interface vptr, table `0x00618ac4` | Constructor stores this table; `OnShow` and `OnHide` pass `this + 0xa0` for modal registration/removal. |
| `+0xa4` | tertiary/interface vptr, table `0x00618af4` | Constructor stores this table; destructor adjustor thunk `0x0048c286` subtracts `0xa4`. |
| `+0x0f8` | dialog title, likely `wchar_t[0x80]` | Constructor and title setter pass `this + 0xf8` to `_wcscpy_s` with element count `0x80`. |
| `+0x1f8` | `uint16_t dialogConfigId` | Constructor stores the incoming config id; `OnCreate` checks it against `0xffff` and uses it for config lookup. |
| `+0x1fc` | `List *m_controlManager` | Live IDA reads this exact pointer member from `DialogPane` UDT ordinal `471`, exact object size `0x26c`. Constructor initializes it to zero; [UID:0003KH][0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd](by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md) allocates an exact `0x14`-byte generic List and reconstructs as `new List(sizeof(ControlPane *), 20)`, so the List holds copied four-byte `ControlPane *` slots rather than a source-distinct manager object. Accepted slots are `GetElementAt +0x10`, `Append +0x18`, and `RemoveAt +0x1c`; UID0003KH calls `Append(1, &control)`, and UID00012T removes one element by index. The List owns slot/backing storage, while DialogPane owns the pointed-to controls and destroys them during cleanup. [UID:0003KI][0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer](by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md) expands first-match lookup plus indexed removal, while source composes `FindControlIndex(control)` and guarded `RemoveControl(controlIndex)`. [UID:0003KK][0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw](by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md) returns zero on null and otherwise uses inline `List::GetCount()` for the direct `+0x0c` count load. `m_controlManager` remains the best supported inferred role spelling; custom-manager and category-bearing alternatives are rejected. |
| `+0x200` | `int m_focusedControlId` | Constructor initializes `0xffffffff`; keyboard and focus drawing paths read it. |
| `+0x204` | `int m_pendingControlId` | Constructor initializes `0xffffffff`; keyboard dispatch pushes it with `+0x200`, and [UID:0003KM][0x0049ddd0-0x0049ddf7.DialogPaneSetPendingControl](by-memory/0x0049ddd0-0x0049ddf7.DialogPaneSetPendingControl.md) / [UID:0003KP][0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl](by-memory/0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl.md) use it as the pending activation id. |
| `+0x208` | `unsigned char m_isTitleDragActive` | Constructor initializes zero; `ModelessDialogPane::HandlePointerOrMouseEvent` sets and clears it while dragging title/chrome hit type `10`. Browser/WebBoard input reports identify the adjusted secondary-view byte as this inherited title-drag state. |
| `+0x209` | `unsigned char m_savedPaneMode` | Constructor stores the incoming mode byte; modeless drag saves/restores pane input mode through this field. Exact original spelling could be `m_dialogMode` or `m_savedMode`, but `m_savedPaneMode` best fits current behavior. |
| `+0x20c` | `int m_dragOriginY` | Modeless mouse-down stores mouse Y here; drag move subtracts it while updating vertical pane position. |
| `+0x210` | `int m_dragOriginX` | Modeless mouse-down stores mouse X here; drag move subtracts it while updating horizontal pane position. |
| `+0x214` | `int m_activeControlId` | Constructor initializes `0xffffffff`; hover and input dispatch helpers read/write it. Older hover-only wording is incomplete because TextPad/input reports use the same field as the active/current control id. |
| `+0x218` | `unsigned char m_pressedControlActive` | Constructor initializes zero; modeless mouse-down/release toggles it. |
| `+0x21c` | `int m_pressedControlId` | Constructor initializes `0xffffffff`; modeless mouse paths store and dispatch through it. |
| `+0x220` | `unsigned char m_pressedHitType` | Modeless mouse-down stores hit type here and release checks it before activation; hit type `10` is title/chrome behavior in support docs. |
| `+0x224` | `int m_selectedControlId` | Constructor initializes `0xffffffff`; keyboard/control dispatch, selection helpers, and modeless release paths read/write it. |
| `+0x228` | `unsigned char m_selectionVisualState` | Input path and [UID:0003KN][0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState](by-memory/0x0049de00-0x0049de67.DialogPaneSetSelectionVisualState.md) update this byte; current evidence includes state values `0x0a` and `0x0b`, but final enum names remain open. |
| `+0x229` | `unsigned char m_clampDragToBounds` | Constructor initializes zero; [UID:0003KD][0x0049dae0-0x0049db14.DialogPaneStoreClampRect](by-memory/0x0049dae0-0x0049db14.DialogPaneStoreClampRect.md) sets it, [UID:0003KE][0x0049db20-0x0049db28.DialogPaneClearClampRectDirtyFlag](by-memory/0x0049db20-0x0049db28.DialogPaneClearClampRectDirtyFlag.md) clears it, and modeless drag checks it before clamping movement. |
| `+0x22c` | `int m_dragClampMinX` | `StoreClampRect` writes this first; modeless drag move compares horizontal origin against it. |
| `+0x230` | `int m_dragClampMinY` | `StoreClampRect` writes this second; modeless drag move compares vertical origin against it. |
| `+0x234` | `int m_dragClampMaxX` | `StoreClampRect` writes this third; modeless drag move compares the horizontal right edge against it. |
| `+0x238` | `int m_dragClampMaxY` | `StoreClampRect` writes this fourth; modeless drag move compares the vertical bottom edge against it. |
| `+0x23c..+0x263` | `EPFTileContext m_backgroundTileContext` | Exact 0x28-byte context. Constructor initializes it; cleanup releases it; [UID:0003KG][0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource](by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md) releases buffers, clears pixel data, copies row stride/bounds/encoded-mask count, allocates and copies owned mask bytes. UID0004SW/UID0004SX read the encoded-mask pointer and bounds. |
| `+0x264` | `int m_backgroundImageWidth` | Constructor initializes zero. Retained best descriptive spelling for trailing background-image width/state; it is outside the EPFTileContext and is not written by SetBackgroundResource. |
| `+0x268` | `bool m_hasCustomBackground` | Constructor initializes zero. Retained best descriptive spelling for trailing custom-background state; exact draw routing is primarily governed by the context's encoded-mask pointer. |
| `+0x269..+0x26b` | natural tail padding | Required to complete the 0x26c base size. It is compiler layout, not a raw source byte-array member. |

The base object is exactly `0x26c` bytes. The old overlapping `DialogBackgroundState` and separate `+0x240/+0x248/+0x24c/+0x25c/+0x260` source-member rows are superseded: those addresses are fields inside the one EPFTileContext. Do not treat `AlertPane` offset `+0x26c` as base DialogPane state; current IDA evidence puts `+0x26c` in derived tails.

## UID000312 Field-Order Closure

- Exact stores and comparisons in `0x004a0840-0x004a0c8e` establish Y at `+0x20c`, X at `+0x210`, and minX/minY/maxX/maxY at `+0x22c/+0x230/+0x234/+0x238`. These names are the current declaration contract across DialogPane and ModelessDialogPane.
- The prior X/Y and minY/minX/maxY/maxX order was a historical alias inferred from rectangle-style prose. It is retained in the dated B011/B015 history below but is superseded by operand-level evidence.
- `m_selectionVisualState` remains the broader canonical name for `+0x228`; modeless `m_selectedHitType` wording is a historical role alias, not separate storage.
- The corrected names remain source-facing inferences because original symbols are stripped. They are nevertheless higher probability than raw offsets or contradictory axis labels and are required for one coherent human-written header.

[UID:00003T][DialogPane](by-class/DialogPane.md) now has its complete class declaration in the H channel using the field names above and one `[[CHILDREN]]` marker. Exact helper-body C++ remains delegated to by-memory children, including UID0003KH AddControl, so this layout page keeps both formal channels blank and does not duplicate class or method source.

## IDA Evidence

Checked on 2026-05-26 and spot-rechecked on 2026-05-31:

- Live UID0003KH MCP readback on 2026-07-28 independently confirms `DialogPane` UDT ordinal `471`, exact size `0x26c`, and exact declaration `List *m_controlManager` at `+0x1fc`. `ControlPane` ordinal `443` is size `0x108`; named incomplete List ordinal `485` is safe for pointer declarations and remains source-defined by the List docs rather than synthesized here.
- The same recheck types UID0003KH as `void __thiscall(DialogPane *this, ControlPane *control)` and exhausts 800 direct code xrefs with zero data/indirect routes. No caller supplies a category argument, and exact name inventory finds no category-bearing AddControl function.

- `DialogPane::DialogPane` at `0x0049d8a0` calls the `Pane` constructor, initializes `EPFTileContext` at `+0x23c`, installs vtables at `+0x00`, `+0xa0`, and `+0xa4`, copies the title into `+0xf8`, then initializes the control/config/mode/background fields listed above.
- The cleanup body at `0x0049da10` reinstalls the same three vtables, tears down the control manager at `+0x1fc`, destroys the tile context at `+0x23c`, and then calls base `Pane` teardown.
- The title setter at `0x0049db30` copies to `+0xf8` and invalidates/repaints through a virtual slot.
- Exact UID0003KG at `0x0049db60` replaces the context at `+0x23c`: it releases owned buffers, clears pixel data, copies row stride/bounds/mask count, allocates a new encoded-mask buffer, and copies the mask bytes. Every affected address through `+0x260` is inside EPFTileContext.
- `OnCreate` at `0x0049dfd0` reads `+0x1f8` for dialog config lookup and uses `+0x1fc` for child-control setup.
- `OnShow` and `OnHide` at `0x0049e190` and `0x0049e210` pass `this + 0xa0` to modal/list registration helpers.
- Keyboard/control handling at `0x0049e6e0` uses `+0x1fc`, `+0x200`, `+0x204`, `+0x214`, `+0x224`, and `+0x228`.
- UID0003KI fresh session `supervisor_20260712` confirms that the direct `+0x1fc/+0x0c` scan and List vslots `+0x10/+0x1c` are optimized expansion evidence for accepted `FindControlIndex` and indexed `RemoveControl` helpers, not a reason to expose List internals in the pointer overload source. Ten MiniMap callers remove, then destroy, then clear saved pointers, confirming the List stores non-owning pointer values.
- `OnPaint` at `0x0049f090`, [UID:0004SW][0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground](by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md), and [UID:0004SX][0x0049f2e0-0x0049f912.DialogPaneDrawBorder](by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md) use the focus id, one tile context, inherited bounds, trailing state, exact DLGFRAME/PAL resource names, and custom encoded-mask behavior.
- `ModelessDialogPane::HandlePointerOrMouseEvent` at `0x004a0840` receives the secondary view as `this == object + 0xa0`; its secondary-relative accesses map back to base offsets `+0x208` through `+0x238`.
- Historical 2026-06-22 B015 aliases described `+0x20c/+0x210` as `m_dragStartX/Y` and `+0x22c..+0x238` as top/left/bottom/right. Exact UID000312 operands supersede them with Y/X and minX/minY/maxX/maxY. B015's `m_titleDragActive`, `m_hoverControlId`, selected-control reset, and clamp-enabled role observations remain useful, while `m_activeControlId` and `m_selectionVisualState` are the broader shared canonical names.
- 2026-05-31 IDA MCP `lookup_funcs` reconfirms key method starts and sizes including constructor `0x0049d8a0` size `0x148`, `OnCreate` `0x0049dfd0` size `0x1b9`, `OnShow` `0x0049e190` size `0x2e`, `OnHide` `0x0049e210` size `0x22`, control handling `0x0049e6e0` size `0x379`, slide helper `0x0049eac0` size `0xcd`, and final cluster function `sub_49FE20` ending at `0x0049feae`.
- 2026-05-31 IDA MCP decompilation of the constructor directly shows vtable stores at `+0x00/+0xa0/+0xa4`, title copy to `+0xf8`, config id at `+0x1f8`, control manager at `+0x1fc`, focus/control ids at `+0x200/+0x204/+0x214/+0x21c/+0x224`, state bytes at `+0x208/+0x209/+0x218/+0x229`, tile context at `+0x23c`, and custom background state through `+0x268`.
- `xrefs_to 0x00618a64` confirms the primary vtable is installed by constructor/destructor paths.
- 2026-06-16 A001 live IDA refresh reconfirmed constructor `0x0049d8a0` size `0x148`, cleanup/destructor body `0x0049d9f0` size `0xdb`, title setter `0x0049db30` size `0x2d`, raw count helper `0x0049dd70` still not a function, raw/polluted focused-control activation at `0x0049de70`, pending-control activation `0x0049df20` size `0xa4`, create/layout handler `0x0049dfd0` size `0x1b9`, keyboard/control handler `0x0049e6e0` size `0x379`, and repaint helper `0x0049fe20` size `0x8e`.
- The same pass reconfirmed 84 direct constructor xrefs to `0x0049d8a0`, 10 direct xrefs to `0x0049fe20`, and constructor/destructor-only vtable stores for bases `0x00618a64`, `0x00618ac4`, and `0x00618af4`. `tools/int_convert.py` verified the cited secondary/tertiary offsets `0xa0`/160 and `0xa4`/164, vtable-data range `0x9c`/156, tile context `0x23c`/572, and current base tail through `0x268`/616.
- A 2026-06-16 section-mapped PE scan found no VA/RVA/rel32 references to raw `0x0049dd70`, while raw `0x0049de70` has nine rel32 jump refs from dialog-derived helper thunks. B001's 2026-06-24 MCP refresh for [UID:0003KK][0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw](by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md) keeps the no-incoming-route fact as negative evidence, but no longer treats it as a source-facing name or C++ blocker: the raw 15-byte body is a complete `DialogPane::GetControlCount() const` leaf over the generic List field.
- 2026-06-24 B001 MCP session `80de0a67` rechecked the raw count helper: `lookup_funcs 0x0049dd70` returns `Not a function`; `get_bytes` shows target bytes `8B 81 FC 01 00 00 85 C0 75 01 C3 8B 40 0C C3` between `0xcc` padding at `0x0049dd6b-0x0049dd70` and `0x0049dd7f`; `xrefs_to`, `find_xref_signatures`, and VA/RVA byte-pattern checks found no incoming route. B004 UID00012T adds exact generic `List(4, 20)` construction/vtable proof and accepted inline `List::GetCount()` source wording for the direct `+0x0c` load.
- B004 UID00012T confirms this List stores four-byte `ControlPane *` values: `AddControl` calls `Append(1, &control)`, pointer/index removal wrappers call `RemoveAt(index, 1)`, public `FindControlIndex` compares dereferenced element slots, and DialogPane destruction drains the same pointers before deleting the List.

## Boundary Notes

- Browser/embedded-window input handlers in the `0x0046ad80-0x0046e9f4` area reference additional offsets such as `+0x11c`, `+0x120`, `+0x26c`, `+0x278`, and `+0x27c`. Those are derived/browser-pane fields or adjusted-this views, not confirmed base `DialogPane` fields.
- `AlertPane`, `BlueAlertPane`, `VersatileAlertPane`, and `UrlAlertPane` add derived tail fields beginning at `+0x26c` or later; see [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md).
- `DialogInSession` also uses derived tail fields at `+0x26c` and `+0x270`; see [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md).
- `ModelessDialogPane` does not currently need a separate derived tail for its mouse-event state; see [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md) for the secondary-view offset mapping.
- Generated names in `class_DialogPane.cpp` are useful hints, but IDA evidence should control final field ownership and names.
- Parent eligibility is current and strong: [UID:00003T][DialogPane](by-class/DialogPane.md) is `93/96` and [UID:0000IT][DialogPane](by-file/DialogPane.md) is `93/95`; exact vtable support [UID:0003JB][DialogPaneVtables](by-type/by-vtable/DialogPaneVtables.md) remains the compiler-layout authority. The remaining cap is stripped lexical naming and unrelated helper/enum spellings, not the `+0x1fc` type/lifetime contract or background layout.

## Cross-References

- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md)
- [UID:0003KG][0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource](by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md)
- [UID:0004SW][0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground](by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md)
- [UID:0004SX][0x0049f2e0-0x0049f912.DialogPaneDrawBorder](by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md)
- [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md)
- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-07-28 B004 UID0003KH accepted implementation callback:
  - Raised `91/93 -> 92/95`, preserving owner/emitter UID00003T, reconstructable true, blank position, blank CPP/H, every inherited offset, and all unrelated layout/history evidence.
  - Added live UDT ordinal `471`, exact size `0x26c`, exact `List *m_controlManager` readback at `+0x1fc`, UID0003KH prototype/all-800-caller evidence, `new List(sizeof(ControlPane *), 20)`, exact Append slot semantics, and List-slot versus DialogPane-control lifetime ownership.
  - Historicalized the custom-manager/category-bearing interpretation and recorded that the class declaration now belongs to the class H channel while exact child bodies remain on by-memory emitters.

- 2026-07-16 B003 UID0003AX accepted implementation:
  - Raised `86/90 -> 91/93`, retaining owner/emitter UID00003T, reconstructable true, blank position/formal, and all unrelated inherited/control/history rows.
  - Replaced overlapping background rows with exact `EPFTileContext m_backgroundTileContext` at `+0x23c..+0x263`, `int m_backgroundImageWidth` at `+0x264`, `bool m_hasCustomBackground` at `+0x268`, and natural tail padding at `+0x269..+0x26b`.
  - Added exact UID0003KG/UID0004SW/UID0004SX setup/draw consumers, source-resource links, and the no-raw-layout decision.

- 2026-07-12 B003 UID0003KI support implementation:
  - Kept `86/90`, owner/emitter UID00003T, reconstructable true, all offsets, and blank layout formal C++.
  - Updated the `+0x1fc` row with renamed UID0003KI, exact helper factorization, compiler-expanded List access, and ten-caller non-owning lifetime evidence.

- 2026-07-12 B004 UID00012T support implementation:
  - Kept `86/90`, owner/emitter UID00003T, reconstructable true, all offsets, and blank layout formal C++.
  - Replaced only the `+0x1fc` placeholder concrete type with exact `List *`, retained `m_controlManager` as an inferred role spelling, and recorded `List(4, 20)`, four-byte `ControlPane *`, `GetElementAt`/`Append`/`RemoveAt`, inline `GetCount`, and destructor-drain evidence.

- 2026-05-31 scoring and reconstructability:
  - What existed before: completion/confidence metadata was unevaluated at `0/0`, and `RECONSTRUCTABLE` was blank.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms the constructor, lifecycle/control methods, vtable stores, and major field offsets; the page remains below `95+` because several state bytes after `+0x208` still have provisional source-facing names and some derived-dialog ownership boundaries remain under review.
- 2026-06-06 parent attachment:
  - What existed before: the layout had strong IDA-backed offsets and was scored above `80/80`, but `AUTOGEN_PARENT_UID` was blank.
  - Changed to: attached to [UID:00003T][DialogPane](by-class/DialogPane.md) without changing scores.
  - Summary/evidence: the `DialogPane` class page is scored `82/84`, links this layout as its consolidated state map, and the layout page documents constructor, lifecycle, control handling, modeless secondary-view mapping, and vtable-store evidence.
- 2026-06-16 A001 Goal 2 type/layout refresh:
  - Before: `84/88`.
  - Changed to: `86/90`; owner/emitter remain [UID:00003T][DialogPane](by-class/DialogPane.md).
  - Evidence: live IDA reconfirmed key method starts/sizes, constructor field writes, 84 constructor callers, 10 repaint-helper callers, vtable-store xrefs for all three views, and raw helper reachability. The parent-gate issue from the assignment is no longer present in current docs: direct class parent [UID:00003T][DialogPane](by-class/DialogPane.md) is `85/86`, file parent [UID:0000IT][DialogPane](by-file/DialogPane.md) is `86/85`, and exact vtable support clears its own gate. Final C++ remains blank because source-facing names for fields after `+0x208` and several helper methods are still provisional.
- 2026-06-19 B011 source-quality sync:
  - Kept score `86/90`.
  - Replaced post-`+0x208` generated/hypothesis wording with the preferred source-facing names `m_pendingControlId`, `m_isTitleDragActive`, `m_savedPaneMode`, `m_activeControlId`, `m_pressedControlActive`, `m_pressedControlId`, `m_pressedHitType`, `m_selectedControlId`, `m_selectionVisualState`, `m_clampDragToBounds`, and explicit drag-clamp bounds.
  - Summary/evidence: B011 reconciled [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md), exact child helper pages, TextPad/input behavior, Browser/WebBoard secondary-view title-drag evidence, and the [UID:00003T][DialogPane](by-class/DialogPane.md) declaration route. Final original spellings for the control-manager/background/visual-state support types still cap confidence below final-audit levels.
- 2026-06-22 B014 support sync: corrected the visible DialogPane adjustor thunk support range to `0x0048c27b-0x0048c291`; backing file rename remains a supervisor/coverage task.
- 2026-06-22 B015 ModelessDialogPane support sync:
  - Score unchanged at `86/90`.
  - Summary/evidence: incorporated the modeless-handler field role aliases from [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md) / [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md), while preserving the wider `DialogPane` canonical field names from B011 where keyboard/control evidence uses the same slots more broadly.
- 2026-06-24 B001 accepted implementation:
  - Score unchanged at `86/90`.
  - Historical summary/evidence: updated the `m_controlManager` row and IDA evidence with [UID:0003KK][0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw](by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md) raw no-function unique 15-byte leaf, no incoming route, and formal `DialogPane::GetControlCount() const` child C++. Its provisional `DialogControlManager::m_count` wording is superseded by B004's generic List/accessor proof.
- 2026-06-28 B008 DialogPane slide-animation support sync:
  - Score unchanged at `86/90`.
  - Summary/evidence: updated the [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md) cross-reference to the repaired `0x0049eac0-0x0049f081` range; layout offsets and field names are unchanged.
