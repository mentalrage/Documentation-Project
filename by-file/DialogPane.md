*** UID:0000IT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# DialogPane
## UID0000LU Shared Gate Synchronization - 2026-08-15

DialogPane now receives the sole `signed char g_activeDialogCount;` definition and matching extern declaration from UID0000PQ. Constructor increment, destructor decrement, loader-zero initialization, one-byte UID0001PH storage boundary, and positive-only action blocking remain the exact shared-lifetime contract; NewSpell is only a consumer.

## 2026-08-14 B003 ChangePassword Dependency Incorporation

- UID00003T remains the class/formal owner through this file. Its CPP now includes `DialogPane.h` before children; its guarded H includes complete EPFTileContext and Pane and forwards ControlPane, Event, Layer, and List.
- This is support-only for UID0000I3: ChangePasswordDialogPane derives from DialogPane and uses child management, hover/focus/pending state, background/mode, create/show/slide/close operations. No password-dialog body or singleton is moved here. File metadata remains unchanged.

## Status

- Confidence: very strong for source module, class responsibility, exact base-dialog aggregate, shared lifetime state, vtable data, control-helper child routing, generic List-backed control storage, exact background setup/draw children, resource/package contract, derived override exclusions, and complete declaration-level class source.
- Proposed module: `NexusTK/ui/core/DialogPane.cpp`, with complete class declaration in companion `NexusTK/ui/core/DialogPane.h`.
- Current recovered source: `source-3/simroot_v2/class_DialogPane.cpp`
- Main method cluster: `0x0049d8a0-0x0049feae`; Browser/WebBoard input/window reposition overrides in `0x0046ad80-0x0046e9f5` are derived consumers, not DialogPane-owned methods.
- Type docs: [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md), [UID:0003JB][DialogPaneVtables](by-type/by-vtable/DialogPaneVtables.md), split from [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)

## File Role

`DialogPane` is the base class for modal and modeless dialogs. It extends `Pane`, stores a title, dialog config ID, saved mode/title-drag state, focused/pending/active/pressed/selected control IDs, the generic `List *m_controlManager` containing four-byte `ControlPane *` elements, drag clamp state, one embedded `EPFTileContext m_backgroundTileContext`, trailing background width/state, and a Boolean custom-background flag. It owns common dialog creation/show/hide/destroy/paint behavior, config-backed dialog positioning, base pointer/key/IME dispatch, exact background setup/drawing, List-backed add/remove/find/count wrappers, exact focused-control activation [UID:0003KO][0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw](by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md), exact hover-control transition method [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md), and slide animation helpers.

Many feature dialogs should remain separate feature files, but their common lifetime, control tracking, and layout behavior belong here.

## Add Control Source Route

[UID:0003KH][0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd](by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md) is the exact out-of-line `DialogPane::AddControl(ControlPane *)` body in `DialogPane.cpp`; [UID:00003T][DialogPane](by-class/DialogPane.md) supplies its protected declaration from `DialogPane.h`. The method occupies exact range `[0x0049dc10,0x0049dc93)`, between eleven and thirteen bytes of alignment padding, and must not absorb either padding span.

The body lazily constructs `new List(sizeof(ControlPane *), 20)` when `m_controlManager` at `+0x1fc` is null, then calls accepted `List::Append(1, &control)`. The generic List owns copied four-byte pointer slots/backing storage; DialogPane retains ownership of the pointed-to controls and later drains, destroys, and clears them. The allocator wrapper, constructor-failure cleanup funclet, security cookie, and raw vslot call are compiler lowering of ordinary source and are not handwritten file contents.

Complete live reachability contains exactly 800 direct code xrefs grouped into 88 modeled dialog construction/layout functions plus one unmodeled call site, with zero data or indirect/function-pointer routes. This broad usage makes AddControl shared DialogPane infrastructure rather than feature-dialog, List, ControlPane, or free-helper source. No call supplies a category byte or second explicit argument; no separate AddControl function/name exists. The historical category-bearing overload and source-distinct `DialogControlManager` theories are therefore rejected while retained as superseded research history.

## Focused Activation Source Route

[UID:0003KO][0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw](by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md) is the exact out-of-line `DialogPane::ActivateFocusedControl()` body in `DialogPane.cpp`; UID00003T supplies its one protected declaration in `DialogPane.h`. Within the control-helper child order, the body follows UID0003KN `SetSelectionVisualState` and its nine-byte padding, then precedes twelve-byte padding and separate UID0003KP `ActivatePendingControl`. The exact interval is `[0x0049de70,0x0049df14)`, 164 bytes and 47 instructions; neither padding span nor either sibling belongs to the body.

Source gates focused id `-1` and disabled controls, pulses state `11`, performs two synchronous `RenderPresentation()` calls around `Sleep(0x85)`, conditionally restores a previous selected child to state `10`, clears selected id/state, and finishes through DialogPane primary slot `+0x48` as `OnControlCommand(m_focusedControlId, 11)`. The earlier control-side `+0x48` call is the separate `ControlPane::SetVisualState(10)` reset. The exact source lives only on UID0003KO; this file page records placement/inventory and does not duplicate the body.

Nine live 11-byte virtual consumers load a non-owning dialog owner and tail-forward to UID0003KO: `TextMenuItemList`, `ServerItemMenuItemList`, `ClientItemMenuItemList`, `ServerSpellMenuItemList`, `ClientSpellMenuItemList`, `ArgumentedMenuMenuItemList`, two menu-question item-list variants, and `ServerSelectMenuItemList` `OnItemActivated`. Their owner offsets are `+0x154`, `+0x158`, or `+0x14c`, and each wrapper is reached by its own vtable cell. These consumers remain in their TextMenu/menu source families; they establish liveness but do not move the body out of `DialogPane.cpp`.

IDA currently names the body entry `loc_49DE70` and attaches it as a shared tail to modeled wrapper owner `TextMenuItemList__OnItemActivated` at `0x00519840`. Exact DialogPane fields, terminal receiver flow, class declaration, padding, and nine owner-loading wrappers override that presentation defect for source ownership. No handwritten vtable/thunk, duplicate header declaration, function/chunk repair, new source file, or aggregate body is part of this source route.

## Generic Control Refresh Route

- `DialogPane` helper `0x0049fe20` resolves control selector `1` and dispatches primary virtual slot `+0x4c` when the control exists. The dynamic control class owns the slot behavior; the wrapper is shared DialogPane infrastructure rather than an AddItemDialog method.
- The helper has ten direct callers. AddItemDialog construction reaches it synchronously through `OnCreate`, after selectors `1` and `3` and the AddItemDialog vtables have been installed; the resulting AddItemDialog-family dispatch reaches [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md).
- AddItemDialog, AddEmployeeDialog, and AddMixingItemDialog primary vtables route slot `+0x4c` to UID0004BP. AddItemWithCountDialog instead routes that slot to its separate override at `0x004af480`.
- UID0004BP then uses the protected `GetChild<T>` contract for selectors `1` and `3`; this does not make the generic wrapper or control lookup helper part of ItemDialogs source.
- Historical direct-call searches correctly found no constructor instruction calling UID0004BP. That negative is narrower than the completed synchronous route through `OnCreate -> 0x0049fe20 -> virtual +0x4c` and does not imply deferred initialization.

[UID:0003KI][0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer](by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md) is source-ready under this file route. Its protected `RemoveControl(ControlPane *control)` source composes public `FindControlIndex(control)` with guarded indexed `RemoveControl(controlIndex)`; optimized binary expansion reproduces the generic List first-match scan and `RemoveAt(index,1)`. Ten MiniMap teardown call sites remove inherited entries before destroying and clearing their saved pointers, proving non-owning DialogPane registration without moving the method into MiniMap source.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `DialogPane` | `0x0049d8a0-0x0049feae` | Base dialog constructor, create/show/hide/destroy/paint, pointer/key/IME input, background/border drawing, control focus/selection, and config-backed positioning. |
| [UID:00003T][DialogPane](by-class/DialogPane.md) declaration | class shell | Complete `DialogPane.h` declaration with exactly one `AddControl(ControlPane *)` declaration and one `[[CHILDREN]]`; class CPP stays blank and exact method bodies stay on by-memory children. |
| [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) | `0x0049dae0-0x0049dfc4` | Non-emitting inventory for exact class-owned control helpers over generic `List(sizeof(ControlPane *), 20)`. Exact children [UID:0003KD][0x0049dae0-0x0049db14.DialogPaneStoreClampRect](by-memory/0x0049dae0-0x0049db14.DialogPaneStoreClampRect.md)-[UID:0003KP][0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl](by-memory/0x0049df20-0x0049dfc4.DialogPaneActivatePendingControl.md) plus [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md) are source-authored `DialogPane` methods. UID0003KH emits exact protected one-pointer AddControl; [UID:0003KI][0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer](by-memory/0x0049dca0-0x0049dcf8.DialogPaneRemoveControlByPointer.md) emits protected pointer removal through factorized lookup/index removal; UID00012T emits indexed removal; UID0003KK emits `GetControlCount() const`; UID0003KO emits exact focused activation with nine live virtual forwarders. DialogCategorySwitch remains separate state behavior and is not an AddControl category overload. |
| [UID:0003KH][0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd](by-memory/0x0049dc10-0x0049dc93.DialogPaneEnsureControlManagerAndAdd.md) | `0x0049dc10-0x0049dc93` | Exact one-pointer source body in `DialogPane.cpp`: lazy generic List construction, one pointer-slot Append, DialogPane-owned control lifetime, 800 direct callers, and ordinary-new compiler lowering. |
| [UID:0003KO][0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw](by-memory/0x0049de70-0x0049df14.DialogPaneActivateFocusedControlRaw.md) | `0x0049de70-0x0049df14` | Exact `ActivateFocusedControl()` source body in `DialogPane.cpp`, ordered after UID0003KN and before UID0003KP: focused-id/enable gates, state-11 pulse, two renders, `Sleep(0x85)`, neutral state-10 reset, terminal DialogPane `OnControlCommand`, nine live `OnItemActivated` forwarders, and bounded shared-tail IDA caveat. |
| [UID:0003KG][0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource](by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md) | `0x0049db60-0x0049dc05` | Exact `SetBackgroundResource(const wchar_t *, short)` body: resolve one layout entry, release the embedded context, copy row stride/bounds/mask count, allocate and copy owned encoded-mask bytes through MemoryMan. |
| [UID:0004SW][0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground](by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md) | `0x0049f1d0-0x0049f2d4` | Exact primary `+0x50` body: current DLGFRAME.EPF/PAL01 frame-8 tiled background, legacy DLGFRAME.EPD/NPAL8 background, or custom encoded-mask fill callback. |
| [UID:0004SX][0x0049f2e0-0x0049f912.DialogPaneDrawBorder](by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md) | `0x0049f2e0-0x0049f912` | Exact primary `+0x54` body: 14/16-pixel frame modes, all eight edge/corner indices, do-while tiling, palette split, and custom-background suppression. |
| [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md) | resource authority | Exact DLGFRAME EPF/EPD frame-role and package matrix, PAL01/NPAL8 pairing, all DialogPane direct xrefs, sixteen-function PAL01 consumer inventory, Browser fallback, and source-literal/pooling boundary. |
| vtable family | [UID:0003JB][DialogPaneVtables](by-type/by-vtable/DialogPaneVtables.md), [UID:0003AW][0x00618a60-0x00618afc.DialogPaneVtableData](by-memory/0x00618a60-0x00618afc.DialogPaneVtableData.md) | Primary dialog view plus secondary/tertiary handler views at object offsets `+0xa0` and `+0xa4`. |
| adjustor thunk helpers | `0x0048c27b-0x0048c291` | Compiler-generated secondary/tertiary destructor thunks; reused by derived dialog vtables. |
| [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md) | `0x0049eac0-0x0049f081` | Shared `DialogPane` slide-open/close/shrink/expand animation helpers. The exact child now emits the six method bodies after repairing the stale final-instruction end; [UID:00012V][0x0049ec80-0x0049ee42.ClanDialogSlideAnimation](by-memory/0x0049ec80-0x0049ee42.ClanDialogSlideAnimation.md) is only a historical caller alias. |
| [UID:0004RI][0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl](by-memory/0x0049fc00-0x0049fc4c.DialogPaneSetHoverControl.md) | `0x0049fc00-0x0049fc4c` | Exact `DialogPane::SetHoverControl(int)` source body: deactivate old child, activate new child, then store `m_activeControlId`; primary slot `+0x58`, eight MacroDialogs callsites, and 208 total refs prove the shared base route. |
| `DialogPane::DispatchInputToControl` | `0x0049fda0-0x0049fe12` | Distinct Event-coordinate translation/dispatch/restoration body historically misassigned to `0x0049fc00`; remains declared by UID00003T and source-owned here. |
| inherited input/paint virtuals | `0x0049e240`, `0x0049e6e0`, `0x0049ea60`, `0x0049f090`, UID0004SW, UID0004SX | Base dialog pointer/control dispatch, key/focus/selection handling, IME handling, OnPaint, exact DrawBackground, and exact DrawBorder. |
| derived override consumers | [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md), [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md), [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md), [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md) | BrowserDialog/WebBoardDialog/WebBoardDialogOld reposition and key/request overrides call or consume the inherited DialogPane input surface but are owned by their derived classes. |

## Evidence Notes

- IDA MCP reports 84 direct constructor call sites, matching a common dialog base.
- IDA MCP `list_globals` confirms three `DialogPane` vtable bases at `0x00618a64`, `0x00618ac4`, and `0x00618af4`; `disasm` confirms `0x0048c27b` and `0x0048c286` as 11-byte destructor adjustor thunks.
- 2026-06-12 A004 live IDA MCP split [UID:0003JB][DialogPaneVtables](by-type/by-vtable/DialogPaneVtables.md) as the source-local type owner and repaired [UID:0003AW][0x00618a60-0x00618afc.DialogPaneVtableData](by-memory/0x00618a60-0x00618afc.DialogPaneVtableData.md) to the `0x00618afc` exclusive boundary before `AlertPane` RTTI.
- IDA layout review on 2026-05-26 confirms inherited dialog fields at `+0x0f8`, `+0x1f8`, `+0x1fc`, `+0x200`, `+0x204`, mouse/control state from `+0x208` through `+0x238`, `+0x23c`, and the custom background/tile state through `+0x268`.
- UID0003KG/UID0004SW/UID0004SX close the background type/source blocker: `+0x23c..+0x263` is one EPFTileContext, `+0x264` is trailing background width/state, `+0x268` is Boolean custom-background state, and `+0x269..+0x26b` is natural tail padding. The old overlapping DialogBackgroundState source placeholder is superseded.
- [UID:0003AX][0x00618ce0-0x00618d2c.DialogFrameResourceStrings](by-memory/0x00618ce0-0x00618d2c.DialogFrameResourceStrings.md) and UID0004SY prove source expressions are inline wide literals pooled into three non-emitting physical children; no raw storage, interior suffix alias, or separate constants file belongs in this module.
- IDA MCP on 2026-05-25 reports 47 direct callers to `0x0049eac0` and 69 direct callers to `0x0049eb90`, confirming the slide helpers are shared dialog infrastructure rather than ranking/clan feature methods.
- UID0003JB/UID0002NB resolve the complete source contract: primary OnCreate/OnDestroy/OnShow/OnHide/OnPaint/OnControlCommand/UpdateActionButton/DrawBackground/DrawBorder/SetHoverControl, secondary pointer/key/IME overrides plus inherited false packet/default EventHandler methods, and inherited true TimerHandler OnTimer.
- DialogInSession inherits this surface directly. The exact class declarations, not handwritten vtable/RTTI arrays or adjustor wrappers, regenerate its 23/11/2 views.
- 2026-06-28 B008 MCP session `supervisor_20260628_resume` repaired the slide-animation child [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md): `lookup_funcs` confirms modeled helpers at `0x0049eac0`, `0x0049eb90`, `0x0049ec80`, and `0x0049ed60`, raw `SlideShrink`/`SlideExpand` starts `0x0049ee50`/`0x0049ef60` are not modeled functions and have zero incoming xrefs, `0x0049f07e` starts the `c2 04 00` `retn 4`, `0x0049f081` has zero xrefs and is the correct exclusive end, and `0x0049f090` is the next modeled function.
- IDA MCP on 2026-06-02 confirms the base constructor at `0x0049d8a0` increments [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md), and the destructor at `0x0049d9f0` decrements it. Other UI/input paths only compare the byte, so the storage owner belongs with common dialog lifetime state.
- 2026-06-16 A001 live IDA MCP recheck in session `b001_mappane_0001AW_20260616` reconfirmed `0x0049d8a0` size `0x148`, cleanup/destructor body `0x0049d9f0` size `0xdb`, control helpers `0x0049dae0` size `0x34` and `0x0049df20` size `0xa4`, slide helpers `0x0049eac0` size `0xcd` and `0x0049eb90` size `0xe2`, input/window handlers `0x0046ad80` size `0x128` and `0x0046e930` size `0xc5`, and adjustor thunks `0x0048c27b`/`0x0048c286` size `0xb`.
- The same 2026-06-16 xref pass found 84 refs to the base constructor, 48 refs to `0x0049eac0`, 74 refs to `0x0049eb90`, constructor/destructor-only refs to vtable bases `0x00618a64`, `0x00618ac4`, and `0x00618af4`, and 13 refs to [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md). Derived WebBoardDialog handlers `0x0046d3b0` and `0x0046d4b0` still each have one vtable-data ref at `0x00613654`/`0x00613658`, supporting the existing derived-owner split.
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) calls the `0x0049d9f0` cleanup body before scalar-delete flag handling. The local IDA `boost::exception` label is polluted; source semantics are common `DialogPane` cleanup shared by default dialog destructors, while the scalar deleting wrapper itself remains compiler glue.
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) is scored `92/94` and documents the full contiguous base-dialog method island: exact end boundary, 34 modeled starts, constructor/destructor, lifecycle/control helpers, exact UID0003KG/UID0004SW/UID0004SX/UID0004RI routes, distinct `DispatchInputToControl`, slide animation children, layout offsets, vtable data, resources, and active-dialog counter ownership.
- [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md) is scored `88/91` and confirms this file as the storage owner through the constructor increment, destructor decrement, exact 13-reference set, one-byte range boundary, and consumer-only reads in inventory/spell/take-off code.
- [UID:00003T][DialogPane](by-class/DialogPane.md) emits the complete declaration in `DialogPane.h`, not in the `.cpp` channel. That is the correct source mechanism for class layout and vtables; exact by-memory pages carry method bodies, including UID0003KH `AddControl(ControlPane *)`, [UID:0003KK][0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw](by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md), and UID0003KO `ActivateFocusedControl()`.
- B001 2026-06-24 resolves exact child [UID:0003KK][0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw](by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md) as code-emitting `DialogPane::GetControlCount() const` under this file route. MCP session `80de0a67` confirmed no IDA function at `0x0049dd70`, exact unique 15-byte body and padding, no incoming xref/address-literal route, and null-zero/direct-`+0x0c` behavior. B004 UID00012T supersedes only the old placeholder type: `m_controlManager` is exact `List *`, and `GetCount()` is the accepted inline source accessor.
- B004 UID00012T confirms rejected source-owner alternatives: BrowserDialog/WebBoardDialog/WebBoardDialogOld and FittingRoom/HeadSelect are callers or derived consumers; generic List is the delegated container dependency; `Pane` is the base dependency. DialogPane owns the pointer/index removal wrappers and emits UID00012T here. The old category-switch, refresh-flag, custom-manager, feature-owner, no-owner, inline-only, and compiler-artifact interpretations are rejected.
- Generated `NexusTK/ui/core/DialogPane.cpp` is the accepted route for the UID00003T declaration and exact class-owned children. UID0003KG, UID0003KO, UID0004SW, UID0004SX, and UID0004RI supply one source definition each; UID00012R and UID00012S remain blank to prevent duplicate aggregate source, while physical strings and compiler vtables/RTTI/adjustor/scalar-wrapper data remain unhandwritten. UID0003KO's generated definition must appear once after UID0003KN and before UID0003KP; `DialogPane.h` must retain exactly one declaration from UID00003T.
- Wave3 metadata has useful high-level structure notes, but the active generated file has low automated quality because cross-file class references were not resolved during grading. That issue is logged in [Wave3 noticed problems](../wave3_noticed_problems.md).

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | The page documents the `.h`/`.cpp` source split, common dialog role, complete declaration route, exact UID0003KH AddControl and UID0003KO focused-activation body routes, vtable/layout anchors, broad constructor and 800-call AddControl fan-in, nine focused-activation forwarding consumers, control-helper split ownership, exact background/hover children, resource contract, coordinate dispatch, animations, derived exclusions, active-dialog state, and generated route. |
| Confidence | 95 | Exact memory aggregate/class/layout, UID0003KH typed ABI/boundaries/all-caller inventory, UID0003KO bytes/receiver flow/vtable routes/sibling, generic List construction/Append/destruction contracts, exact child bodies/slots/callers, resource/package evidence, and constructor/slide/global xrefs support this direct source owner. The cap preserves stripped lexical and unrelated helper uncertainty, not AddControl or ActivateFocusedControl behavior, ownership, or placement. |

## Cross-References

- [UID:00003T][DialogPane](by-class/DialogPane.md)
- [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md)
- [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:0003KG][0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource](by-memory/0x0049db60-0x0049dc05.DialogPaneSetBackgroundResource.md)
- [UID:0004SW][0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground](by-memory/0x0049f1d0-0x0049f2d4.DialogPaneDrawBackground.md)
- [UID:0004SX][0x0049f2e0-0x0049f912.DialogPaneDrawBorder](by-memory/0x0049f2e0-0x0049f912.DialogPaneDrawBorder.md)
- [UID:0004SY][dialog-frame-resources](by-resource/dialog-frame-resources.md)
- [UID:0003JB][DialogPaneVtables](by-type/by-vtable/DialogPaneVtables.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:00000W][BlackHole](by-class/BlackHole.md)
- [UID:0000A3][PaneChildRegistry](by-class/PaneChildRegistry.md)
- [UID:0000KL][Layer](by-file/Layer.md)

## Changes

- 2026-08-23 B005 UID0003KO accepted support callback:
  - Preserved `93/95`, `NexusTK/ui/core/`, `CANONICAL_OWNER:FILE`, complete header/source split, and all unrelated module inventory/history.
  - Added UID0003KO's exact `DialogPane.cpp` position after UID0003KN and before UID0003KP, its nonduplicated source-body disposition, exact focused activation semantics, shared-tail caveat, and all nine live item-list forwarding consumers.
  - Preserved UID0000ET/TextMenu source ownership for the wrappers and UID00003T's single `DialogPane.h` declaration; no body was copied onto this by-file page.

- 2026-07-28 B004 UID0003KH accepted implementation callback:
  - Raised `92/94 -> 93/95`, preserved `NexusTK/ui/core/` and `CANONICAL_OWNER:FILE`, and recorded the exact companion `DialogPane.h` declaration plus `DialogPane.cpp` child-body route.
  - Incorporated exact one-pointer AddControl ABI/body, padding boundaries, `List(sizeof(ControlPane *), 20)`, `Append(1, &control)`, slot/control lifetime split, 800 direct callers with no data/indirect route, compiler-lowering boundary, and historical rejection of category/custom-manager ownership.
  - Preserved all unrelated class, aggregate, vtable, resource, input, animation, and derived-owner detail.

- 2026-07-16 B003 UID0003AX accepted implementation:
  - Raised `90/92 -> 92/94`, retaining FILE ownership and `NexusTK/ui/core/`.
  - Added exact UID0003KG/UID0004SW/UID0004SX source children, UID0004SY resource authority, three pooled literal children, Browser fallback, package provenance, and no-raw-storage policy.
  - Synchronized the complete UID00003T one-context class layout and preserved the full unrelated control/List/lifecycle/animation/SetHoverControl/derived-consumer/compiler history.

- 2026-07-16 B004 UID0002NB accepted support synchronization:
  - Preserved `90/92`, FILE ownership, `NexusTK/ui/core/`, complete List/control/lifecycle/animation/derived-consumer union, and every unrelated score/source fact.
  - Synchronized the complete UID00003T declaration with OnPaint, HandleImeEvent, DrawBackground, and DrawBorder; recorded the exact inherited DialogInSession vtable route and compiler-generation boundary.
  - No score, route, or unrelated content inflation was applied.
- 2026-07-15 B003 UID00049G implementation callback: raised `88/88` to `90/92`; retained FILE ownership and `NexusTK/ui/core/` route; linked exact UID0004RI, corrected coordinate dispatch to `0x0049fda0`, synchronized UID00012R `90/93` and UID00003T `91/94`, and documented one-source-body/no-raw-vtable generation while preserving every unrelated base-dialog, List, animation, lifetime, and derived-consumer fact.

- 2026-07-13 B005 UID0004BP support synchronization:
  - Preserved `88/88`, the accepted formal class route, and all unrelated DialogPane evidence.
  - Added the exact shared `0x0049fe20` selector-1 virtual-refresh contract, ten-caller inventory, synchronous AddItemDialog `OnCreate` route, derived inheritance/override distinction, and historicalized the narrower direct-call negative.

- 2026-07-12 B003 UID0003KI support implementation:
  - Kept `88/88`, projected `NexusTK/ui/core/` route, and all broader DialogPane file evidence unchanged.
  - Added renamed source-ready pointer removal, exact UID0003KJ/UID00012T factorization, first-match/non-owning behavior, and ten MiniMap remove/destroy/clear consumer sequences without moving ownership.

- 2026-07-12 B004 UID00012T support implementation:
  - Score/path/owner state remain `88/88`, `NexusTK/ui/core/`, and `CANONICAL_OWNER:FILE`.
  - Recorded exact generic `List(4, 20)` control storage, four-byte `ControlPane *` elements, List-backed add/remove/find/count wrappers, UID00012T formal emission through this source route, all four caller families, and superseded category/custom-manager/return alternatives.
  - Preserved the non-emitting UID00012S aggregate, all unrelated DialogPane contents, derived override exclusions, slide methods, lifetime global ownership, and compiler-generated thunk policy.

- 2026-06-16 A001 Goal 2 file-confidence refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:85`.
  - After: `COMPLETION:87`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the constructor/destructor/control/slide/input/thunk starts and sizes, 84 constructor refs, 48/74 slide-helper refs, constructor/destructor-only refs to the three `DialogPane` vtable bases, 13 refs to the active-dialog byte, and the derived WebBoardDialog vtable-only refs for `0x0046d3b0`/`0x0046d4b0`. The remaining blocker is source quality rather than ownership: field names after `+0x208` and several helper names are still provisional in [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md), so final C++ stays blank.
- 2026-06-19 B011 source-quality pass:
  - Changed score from `87/86` to `88/88`.
  - Summary/evidence: [UID:00003T][DialogPane](by-class/DialogPane.md) now emits declaration-only C++; exact by-memory pages keep method bodies. The file page now records the non-emitting [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) split over class-owned exact helpers, DialogPane-owned [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md), Browser/WebBoard derived override exclusions, compiler thunk/vtable-data exclusion, and remaining caveats for control-manager/background/visual-state helper names and the signed/bias declaration of [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md).
- 2026-05-27: The input/window reposition override row previously listed `0x0046d3b0` as part of the unresolved DialogPane-derived override group. Changed it to link to the `WebBoardDialog` virtual-companion memory page because IDA vtable slot `0x00613654` points to `0x0046d3b0` in the `WebBoardDialog` vtable family, and the body repositions the embedded browser child window.
- 2026-05-27: The input/window reposition override row also previously kept `0x0046d4b0` in the unresolved DialogPane-derived override group. Changed it to link to the `WebBoardDialog` input/request helper page because IDA vtable slot `0x00613658` points to `0x0046d4b0` in the same `WebBoardDialog` vtable family.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:78`.
  - Summary/evidence: base dialog role, proposed contents, vtable/layout anchors, broad constructor fan-in, slide animation ownership, derived override corrections, and generated-output quality caveat are documented; confidence is capped by active-source quality and remaining derived override review.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/core/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `DialogPane.cpp` under `ui/core`, and the 2026-05-31 IDA MCP recheck confirms this is common dialog infrastructure rather than a feature-dialog source.
- 2026-06-02 active-dialog counter ownership:
  - Changed confidence from `78` to `80`.
  - Evidence: IDA MCP shows `DialogPane` construction increments the global active-dialog byte and destruction decrements it; all other reviewed refs are consumers that gate immediate UI/input commands.
- 2026-06-10 A001 strict-gate confidence refresh:
  - Changed confidence from `80` to `85`.
  - Evidence: [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md) now records the exact base-dialog aggregate at `86/88`, and [UID:0001PH][0x0069b380-0x0069b381.g_activeDialogCount](by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md) records the exact dialog lifetime byte at `88/91`. Together with the layout and vtable links, this clears the direct parent side of the strict `85/85` gate for DialogPane-owned child globals while keeping final C++ blank below the final-code threshold.
- 2026-06-12 Agent-A001 Goal 2:
  - Kept score `86/85`.
  - Updated the main method cluster endpoint to `0x0049feae` and recorded [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md) as a non-emitting exact-child inventory for class-owned control-manager helpers.
- 2026-06-22 B014 ClanDestructorBand support sync:
  - Corrected the visible DialogPane adjustor thunk range to `0x0048c27b-0x0048c291`; the backing file path still contains the historical `0x0048c290` end until shared registry/coverage paths are renamed.
  - Evidence: [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md) and [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md). Scores and owner/emitter are unchanged.
- 2026-06-24 B001 accepted implementation:
  - Score unchanged at `88/88`.
  - Summary/evidence: recorded that [UID:0003KK][0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw](by-memory/0x0049dd70-0x0049dd7f.DialogPaneGetControlCountRaw.md) now emits the formal `DialogPane::GetControlCount() const` method body through [UID:00003T][DialogPane](by-class/DialogPane.md) into this file route, while this source root and the non-emitting helper inventory remain otherwise unchanged.
- 2026-06-28 B008 DialogPane slide-animation implementation:
  - Score unchanged at `88/88`.
  - Summary/evidence: synchronized the accepted [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md) range repair and method-body insertion. The file route remains `NexusTK/ui/core/DialogPane.cpp`; Ranking and Clan labels stay rejected as generated/caller-provenance pollution, while the exact child now emits the six `DialogPane` slide methods.

## 2026-07-23 B004 Accepted UID0002E6 Reconciliation (0000IT)

- Accepted source: B004 UID0002E6 report, Gate 1 SHA F8FE25AA9AD6922244A4C7EC84D390D41DE9782819D15DCD6D192A58C1D7EF26.
- NexusTK/ui/core/DialogPane.h is now the explicit compile-visible companion of the existing complete UID00003T declaration. NexusTK/ui/core/DialogPane.cpp ownership and the 92/94 evidence remain unchanged.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2E6-079 | 000050 | The complete dialog formal uses `../ui/core/DialogPane.h`, `../map/ObjectStatusBlob.h`, and same-directory `CashShopRequest.h`; UID0000IT/UID0000M6 are explicit callback destinations for the first two companion-header paths, while UID0000I0 already documents the third. Current autogen is not misrepresented as having materialized them. | Strong | Current by-file/class source roots, exact complete class declaration owners, and UID0000I0 Proposed Placement. | UID000050 formal/dependency prose; UID0000IT/UID0000M6/UID0000I0 source-package support. | incorporate | implemented |
| C2E6-083 | 0000IT | `NexusTK/ui/core/DialogPane.h` is the exact companion-header destination for complete declaration UID00003T; UID0000IT currently records only the `.cpp` module and must add the header route for derived consumers such as FittingRoom. | Strong | UID0000IT source root, complete UID00003T formal, and FittingRoom inheritance dependency. | UID0000IT proposed-header/source-placement prose and manual by-file row. | incorporate | implemented |
