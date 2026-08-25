** TARGET-REPORT-UID:0001L4 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001L4 ItemWhoInputPane Source-Quality Reanalysis

Report-only assignment for [UID:0001L4] `by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md`.

Created by Agent-B013 on 2026-06-19. No `by-*` documentation files and no `by-memory/-coverage-report.md` were edited for this report.

## Final Recommendation

[UID:0001L4] should be converted from a reconstructable emitting aggregate to a non-emitting split index/container:

```md
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The parent page should keep a blank formal C++ block and add an explicit no-code proof. The exact child/support pages should carry source-bearing first-draft C++ where eligible:

- [UID:0002S1] `0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md`: source method `ItemWhoInputPane::ItemWhoInputPane(unsigned char itemSlot)`.
- [UID:0001L5] `0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md`: source method `ItemWhoInputPane::~ItemWhoInputPane()`.
- [UID:0002S2] `0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md`: source method `ItemWhoInputPane::OnKeyEvent(...)`.
- [UID:0002S3] `0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md`: source method `ItemWhoInputPane::OnMouseEvent(...)`.
- [UID:0001L6] `0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md`: source method `ItemWhoInputPane::OnObjectListMessage(...)`.
- [UID:0001L7] `0x005af390-0x005af3af.ClearItemWhoTarget.md`: file-local helper `ClearItemWhoTarget()` / `ClearSavedItemWhoTarget()`.

The parent range is not one source function. It contains at least four separate modeled source functions plus padding and the key-handler switch-support span:

- constructor `0x005aec60-0x005aed3d`;
- padding `0x005aed3d-0x005aed40`;
- non-deleting destructor `0x005aed40-0x005aedcb`;
- padding `0x005aedcb-0x005aedd0`;
- key handler `0x005aedd0-0x005aefaf`;
- key-handler switch/jump-table support and alignment `0x005aefaf-0x005af050`;
- mouse handler `0x005af050-0x005af2e7`.

The object-list virtual, clear helper, raw navigation helper island, packet helpers, and scalar-deleting destructor/thunks are related support pages, not evidence that the parent should emit. They should remain documented on exact pages or support aggregates.

## Scope And Inputs Checked

Primary target:

- [UID:0001L4] `by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md`.

Direct child/support pages considered:

- [UID:0002S1] `by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md`.
- [UID:0001L5] `by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md`.
- [UID:0002S2] `by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md`.
- [UID:0002S3] `by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md`.
- [UID:0001L6] `by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md`.
- [UID:0001L7] `by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md`.
- [UID:0002S5] `by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md`.
- [UID:0001L9] `by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md`.
- [UID:0001LA] `by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md`.
- [UID:0002S4] `by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md`.

Source-placement and support pages considered:

- [UID:00006X] `by-class/ItemWhoInputPane.md`.
- [UID:00006Y] `by-class/ItemWhoInputPaneState.md`.
- [UID:0000OH] `by-file/TargetSelectionInputPanes.md`.
- [UID:0000KC] `by-file/ItemActionInputPanes.md`.
- [UID:00007Q] `by-class/MapPane.md` and MapPane helper pages.
- [UID:0002AB] `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`.
- [UID:0001OW] active MapPane singleton documentation for `dword_67A764`.
- `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`.
- `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`.
- `by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md`.
- `by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md`.
- `by-memory/-coverage-report.md` only as a read-only source for exact supervisor-owned replacement text.

## Current Target Defect

The current [UID:0001L4] page says it is a grouping index, but the metadata still advertises:

```md
COMPLETION:85
CONFIDENCE:87
CANONICAL_OWNER:00006X
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006X
```

That is internally inconsistent. The page is an index over several exact bodies and support ranges. It must not be treated as an emitter, because any C++ inserted at the parent would have no one-to-one source function boundary and would duplicate child source.

The target's current range stops at `0x005af2e7`. Related documentation extends to the object-list virtual at `0x005af2f0`, clear helper at `0x005af390`, raw helper island at `0x005af3b0`, packet helpers at `0x005af4f0` and `0x005af580`, and non-contiguous scalar destructor/thunks at `0x005b780a` / `0x005b7a20`. Those related pages are valid support for the index, but they are not inside the formal parent address range and should not be folded into parent C++.

## Boundary Reanalysis

| Range | Recommended treatment | Evidence and source-quality decision |
| --- | --- | --- |
| `0x005aec60-0x005aed3d` | exact child source method | Constructor page [UID:0002S1]. It builds the `Which target?` prompt through `LineInputPane`, installs ItemWho vtables, stores the selected inventory slot/action byte at full object `+0x108`, initializes the saved item target global, and highlights the starting target. |
| `0x005aed3d-0x005aed40` | ignored alignment | Three `0xcc` bytes after constructor `ret`, before destructor prologue. Not source code. |
| `0x005aed40-0x005aedcb` | exact child source method | Non-deleting destructor page [UID:0001L5]. It restores vtables, optionally copies ItemWho saved target state into the SpellWho slot according to a config byte, clears the ItemWho input-mode state through the state object, and runs LineInputPane/base cleanup. |
| `0x005aedcb-0x005aedd0` | ignored alignment | Five `0xcc` bytes before key handler. Not source code. |
| `0x005aedd0-0x005aefaf` | exact child source method | Key handler page [UID:0002S2]. Vtable-only reachability through slot `0x0062f2f4`. It handles Enter, Escape, self-target, previous/next navigation, highlight transitions, and dispatch through `SendObjectActionPacket`. |
| `0x005aefaf-0x005af050` | key-handler switch support and alignment | Raw bytes and disassembly identify compiler switch/jump-table support for the key handler, not a function start and not independent source C++. Keep ignored/switch-table coverage. |
| `0x005af050-0x005af2e7` | exact child source method | Mouse handler page [UID:0002S3]. Vtable-only reachability through slot `0x0062f2f0`. It converts event coordinates to map coordinates, hit-tests/selects targets, gates immediate click behavior through config, sends the item action packet, and closes the pane. |
| `0x005af2e7-0x005af2f0` | ignored alignment | Nine `0xcc` bytes before the object-list virtual. Not source code. |
| `0x005af2f0-0x005af383` | exact support source method | Object-list virtual page [UID:0001L6]. This is immediately adjacent but outside the formal parent range. It should carry its own source method and be cross-linked by parent. |
| `0x005af383-0x005af390` | ignored alignment | Thirteen `0xcc` bytes before the clear helper. Not source code. |
| `0x005af390-0x005af3af` | exact support helper | File-local helper page [UID:0001L7]. Called by ItemWho key and mouse handlers. It resolves `s_itemWhoTargetId` and clears target highlight. |
| `0x005af3b0-0x005af4ef` | raw source-authored helper island, not parent code | [UID:0002S5]. It contains executable helper bodies that repeat previous/next/self retarget logic, but current xrefs do not prove exact source call surface. Document descriptive helper names and keep formal C++ blank until reachability is proven. |
| `0x005af4f0-0x005af57b` | file-local packet helper | [UID:0001L9] `SendTargetedActionPacket`. Same source file/module, not ItemWho parent body. |
| `0x005af580-0x005af5ea` | file-local packet helper | [UID:0001LA] `SendObjectActionPacket`. Used by ItemWho key/mouse confirm paths and the inventory launcher. |
| `0x005b780a-0x005b7820` | compiler adjustor thunks | Non-contiguous vtable thunks into ItemWho scalar deleting destructor; ignored/thunk coverage is appropriate. |
| `0x005b7a20-0x005b7aec` | compiler scalar deleting destructor wrapper plus destructor semantics | [UID:0002S4]. It should document compiler-generated delete dispatch and duplicate destructor semantics. Source C++ belongs on the ordinary destructor page, not the aggregate parent. |

## Caller And Reachability Reanalysis

Constructor reachability is real despite the lack of ordinary static call xrefs:

- The constructor has retained code at `0x005aec60`, a prompt literal route through `off_630AF0` / `Which target?`, and vtable stores for the ItemWho object facets.
- The item-use launcher at [UID:0001KN] `0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md` constructs equivalent ItemWho state inline when an inventory item requires a target. That inline construction explains why the out-of-line constructor can have no direct static caller while still being source-authored and retained.
- The constructor and launcher both write the selected item/action byte into the same full-object field `+0x108`, both use the saved target globals, and both activate the ItemWho input-mode state.

Virtual methods are vtable-reachable:

- Mouse handler [UID:0002S3] is installed at the ItemWho vtable slot `0x0062f2f0`.
- Key handler [UID:0002S2] is installed at `0x0062f2f4`.
- Object-list virtual [UID:0001L6] is installed at `0x0062f2fc`.
- The primary scalar deleting destructor route references `0x005b7a20` at `0x0062f29c`.
- Adjustor thunks for non-primary subobjects point into the scalar destructor at `0x005b780a` and `0x005b7815`.

Helper reachability:

- `ClearItemWhoTarget` at `0x005af390` has direct calls from the key Enter path, key Escape path, and mouse send paths.
- `SendObjectActionPacket` at `0x005af580` has direct calls from the ItemWho key confirm path, the ItemWho mouse send/confirm paths, and inventory dispatch paths. This confirms the helper is the ItemWho use-on-target packet helper.
- `SendTargetedActionPacket` at `0x005af4f0` belongs to the same target-selection source module but is not the ItemWho confirm helper. It sends the larger opcode `0x0f` packet and is shared by other target-selection flows.
- The raw helper island at `0x005af3b0-0x005af4ef` has strong semantic evidence but weak direct reachability. It should stay as a raw-helper support page until xrefs/call-surface are resolved.

## Owner And Source Placement

Best-supported source placement is [UID:0000OH] `TargetSelectionInputPanes.cpp`.

Reasons:

- ItemWho's constructor, key handler, mouse handler, object-list virtual, clear helper, and packet helpers mirror the SpellWho / SelectObject / TargetObject target-selection pane family.
- The shared saved-target global cluster at `0x0069bf20-0x0069bf34` is target-selection state, not item-action command state.
- ItemActionInputPanes launches item command prompts and direct item input panes, but ItemWho is the reusable target-selection prompt for use-on-target behavior.
- UseInventorySlotDispatch is a LivingObjectPane/inventory dispatcher that chooses whether to send immediately or open ItemWho. It is not the source owner for ItemWho's virtual methods.

Recommended ownership split:

- Class/method owner for child methods: [UID:00006X] `ItemWhoInputPane`.
- Source file/emitter route: [UID:0000OH] `TargetSelectionInputPanes.cpp`.
- File-local helper owner for `ClearItemWhoTarget`, packet helpers, and raw helper island: [UID:0000OH].
- Parent aggregate [UID:0001L4]: canonical owner [UID:00006X] is acceptable for browsing, but it should have no emitter because it is a split index.

Rejected alternatives:

- `ItemActionInputPanes.cpp` as owner: rejected. It explains the inventory launcher relationship but not vtable handlers, target-selection saved globals, object-list virtual, highlight helpers, or neighboring target-selection packet helpers.
- `LivingObjectPane` as owner: rejected. The dispatcher allocates/constructs or initializes the pane but does not own ItemWho's virtual behavior.
- Parent as direct emitter: rejected because it would merge multiple function bodies, padding, and compiler switch support into a fake source function.

## Best-Supported Names

### Methods And Helpers

| Address / UID | Recommended source-facing name | Confidence | Notes |
| --- | --- | --- | --- |
| `0x005aec60` / [UID:0002S1] | `ItemWhoInputPane::ItemWhoInputPane(unsigned char itemSlot)` | strong | The byte stored at full object `+0x108` is the selected inventory slot/action byte passed to `SendObjectActionPacket`; `itemSlot` is the best source-facing name, with `action` only acceptable in packet-helper context. |
| `0x005aed40` / [UID:0001L5] | `ItemWhoInputPane::~ItemWhoInputPane()` | strong | Non-deleting source destructor. It should carry source destructor C++, not scalar delete wrapper logic. |
| `0x005aedd0` / [UID:0002S2] | `ItemWhoInputPane::OnKeyEvent(...)` | strong | Existing `HandleKeyInput` is descriptive but less consistent with virtual input naming used around the pane family. |
| `0x005af050` / [UID:0002S3] | `ItemWhoInputPane::OnMouseEvent(...)` | strong | Existing `HandleMouseInput` is acceptable as an alias; `OnMouseEvent` better fits vtable event-handler style. |
| `0x005af2f0` / [UID:0001L6] | `ItemWhoInputPane::OnObjectListMessage(...)` | medium-high | Exact original virtual spelling is not proven. Avoid vague `ObjectListVirtual` in C++; use descriptive message/payload name and preserve caveat. |
| `0x005af390` / [UID:0001L7] | `ClearItemWhoTarget()` or `ClearSavedItemWhoTarget()` | strong | It is a file-local helper with no receiver, not an ItemWho member. |
| `0x005af3b0` | `SelectPreviousItemWhoTarget(...)` / `StepItemWhoTargetPrevious(...)` | medium | Raw helper with previous/up traversal logic. Exact original name and call surface unresolved. Do not emit formal C++ yet. |
| `0x005af430` | `SelectNextItemWhoTarget(...)` / `StepItemWhoTargetNext(...)` | medium | Raw helper with next/down traversal logic. Exact original name and call surface unresolved. |
| `0x005af4b0` | `SelectLocalPlayerItemWhoTarget()` | medium | Raw helper that retargets to local player. Exact original name and call surface unresolved. |
| `0x005af580` / [UID:0001LA] | `SendObjectActionPacket(unsigned char itemSlot, unsigned int targetObjectId)` | strong | Opcode `0x1c`, length 6. This is the ItemWho confirm packet helper. |
| `0x005af4f0` / [UID:0001L9] | `SendTargetedActionPacket(...)` | strong | Opcode `0x0f`, length 10. Same file but not the ordinary ItemWho confirm helper. |

### Globals And Fields

| Existing name / address | Recommended name | Confidence | Evidence and caveat |
| --- | --- | --- | --- |
| `dword_69BF24` | `s_itemWhoTargetId` / `s_itemWhoSavedTargetId` | strong | Written/read by ItemWho constructor, destructor, key, mouse, object-list, clear helper, raw helper island, scalar destructor, and inventory launcher. Project-level alias `g_savedItemWhoTargetObjectId` is behaviorally correct; module-scope `s_itemWhoTargetId` is the better source style for `TargetSelectionInputPanes.cpp`. Reject generated `g_selectedTargetId` because the cluster has separate SpellWho/ItemWho/SelectObject/TargetObject slots. |
| `dword_69BF20` | `s_spellWhoTargetId` / `s_spellWhoSavedTargetId` | strong | Neighbor saved target used by SpellWho; ItemWho destructor copies into it when the target-sharing/save-target config byte is active. |
| `dword_67A764` | `g_activeMapPane` | strong | Used for object lookup, traversal, and hit-test helper calls. |
| `dword_67A748` | local-player `LivingObjectPane` / established `g_pCollectionData` local object | medium-high | Used as fallback target and for clearing pending target field `+0x210`. Existing docs call the global `g_pCollectionData`; first-draft C++ can use a local-player accessor with caveat if class layout is not finalized. |
| `dword_67A7C8 + 0x28de5a` | `g_pConfig->doubleClick` / target click policy | strong | Mouse handler gates immediate send-vs-select behavior. This should not be confused with the destructor/constructor target-save option byte. |
| `dword_67A7C8 + 0x28de6c` | `g_pConfig->saveTargetOnClose` / `shareSpellItemTargetOnClose` | medium-high | Constructor/destructor move saved target ids between SpellWho and ItemWho slots when set. Exact original field name is not proven; document semantic name and rejected alternatives. |
| full object `+0x108` | `m_itemSlot` | strong | Constructor/launcher store the selected item byte; key/mouse confirmation passes it to `SendObjectActionPacket`. Packet helper can call the same byte `action` only at packet serialization level. |
| key event `+4` | `event->kind` / `event->message` | medium-high | Key handler requires value `8` for handled paths. Exact event struct name remains open. |
| key event `+8` | `event->key` | strong | Narrowed through `std::ctype<char>::do_narrow` and compared with Enter/Escape/navigation constants. |
| key event `+0x10a` | `event->modifierFlags` | medium-high | Low bits consume input; bit `0x04` selects alternate previous/next traversal helper. Exact flag enum names remain open. |
| mouse event `+4` | `event->subtype` | strong | Subtype `1` is selection/hit-test, subtype `2` is confirmation/click. |
| mouse event `+8/+0xc` | `event->x`, `event->y` | strong | Used with pane and map origins to compute map-space hit-test coordinates. |
| state object `+0xfa` | `ItemWhoInputPaneState::m_active` / target input-mode flag | strong | Set by launcher/constructor path and cleared by destructor/scalar destructor through `0x0057d0a0`; this is not part of `TargetSelectionModeFlags` globals. |

### Callees

| Address / current helper | Recommended role name | Confidence |
| --- | --- | --- |
| `0x004f1c00` | `LineInputPane::LineInputPane(...)` | strong |
| `0x004f20a0` | `LineInputPane::SetPromptText(...)` | strong |
| `0x004f2010` | `LineInputPane` cleanup/destructor helper | medium-high |
| `0x004f25a0` | `LineInputPane::OnKeyEvent(...)` / close-forwarding path | medium-high |
| `0x00506970` | `MapPane::FindObjectPaneById(...)` | strong |
| `0x00506ae0` | `MapPane::FindPreviousSelectableObject(...)` | strong |
| `0x00506b30` | `MapPane::FindNextSelectableObject(...)` | strong |
| `0x00506b80` | `MapPane::FindPreviousSelectableObjectAlternate(...)` | medium-high |
| `0x00506bd0` | `MapPane::FindNextSelectableObjectAlternate(...)` | medium-high |
| `0x00506ce0` | `MapPane::HitTestObjectAtPoint(...)` | strong |
| `0x0053b1b0` | `LivingObjectPane::SetTargetHighlight(bool)` | strong |
| `0x004b8e00` | pane/map `GetBoundsRect(...)` | medium-high |
| `0x004b7e80` | `PointInRect(...)` | strong |
| `0x00469180` | `BlackHole::QueuePaneForDeferredDeletion(...)` / deferred pane removal | medium-high |
| `0x004b85f0` | `GeneralPurposePanel::GetChildPaneByIndex(...)` | medium-high |
| `0x0057d0a0` | `ItemWhoInputPaneState::SetInputModeFlag(bool)` | strong |
| `0x005754c0` | payload/object-id decode helper | medium | Use descriptive `ReadObjectIdFromPayload` until the codec helper has a final source name. |
| `0x004f4ac0` | operator delete wrapper | medium-high |

## Heuristic / Inference Reanalysis And Validation

This section applies the B-agent Rule 26 standard and the `inference_research.md` guidance: adjacency alone is weak evidence; xrefs, dataflow, vtable slots, constructor/destructor pairing, shared literal/global usage, and negative evidence drive the decision.

| Issue | Evidence checked | Best-supported conclusion | Rejected or remaining alternatives |
| --- | --- | --- | --- |
| Should [UID:0001L4] emit C++? | Target page itself calls the file an index; exact child starts exist inside and adjacent to the range; raw bytes identify padding and switch support; child pages already own method bodies. | No. Parent is a non-emitting split index with blank formal C++. | Reject reconstructable/emitter parent. A single parent function would merge constructor, destructor, key, mouse, padding, and switch support. |
| Is `0x005aefaf-0x005af050` code, padding, or data? | Current target, IDA notes, and raw-byte review identify it as key-handler switch/jump-table support and alignment between key and mouse handlers. | Keep as ignored switch-table/support bytes attached to the key handler region, not a child method and not source C++. | Reject treating it as a raw helper or independent function because no source start/prologue exists and it belongs to the key switch lowering. |
| Does object-list virtual belong to the target page? | It starts at `0x005af2f0`, outside the formal target range after nine `0xcc` bytes, but its vtable slot and saved target global are ItemWho-specific. | It is a related exact child/support page of ItemWho and should be cross-linked, but it should emit from its own page. | Reject folding it into parent C++ or ignoring it as unrelated adjacency. |
| Does `ClearItemWhoTarget` belong as a class method? | Function has no receiver use; it reads global `dword_69BF24`, resolves through active MapPane, clears highlight, and is called by key/mouse paths. | File-local helper in `TargetSelectionInputPanes.cpp`, owned by [UID:0000OH]. | Reject `ItemWhoInputPane::ClearTarget` as a method unless future evidence finds a hidden receiver; current code is receiver-free. |
| Is `dword_69BF24` an arbitrary selected target id? | Xrefs span constructor/destructor/key/mouse/object-list/clear/raw/scalar and inventory launcher; `0x0069bf20` is neighboring SpellWho saved target. | Name it `s_itemWhoTargetId` or `s_itemWhoSavedTargetId`; project alias `g_savedItemWhoTargetObjectId` is acceptable. | Reject `g_selectedTargetId`, because it collapses several adjacent saved-target slots and loses ItemWho specificity. |
| Is `this+0x108` an action code or item slot? | Constructor and UseInventorySlotDispatch store the incoming selected inventory slot/action byte; key/mouse send it through opcode `0x1c`. | Name the ItemWho field `m_itemSlot`; packet helper argument can be `action`/`itemAction` at serialization level. | Reject generic `m_action` on the class because launcher evidence proves selected item slot context. |
| Are target-selection input-mode flags global? | `TargetSelectionModeFlags` globals cover select/target-object flows; ItemWho active state uses helper `0x0057d0a0` on an ItemWhoInputPaneState child object at offset `+0xfa`. | Document ItemWho state as `ItemWhoInputPaneState::SetInputModeFlag(bool)` / active flag. | Reject forcing ItemWho into `TargetSelectionModeFlags` global cluster. |
| Does ItemWho belong in `ItemActionInputPanes.cpp`? | ItemWho is launched by inventory item use, but virtual behavior, saved-target globals, object-list virtual, highlight management, and packet helpers live with SpellWho/SelectObject/TargetObject target-selection code. | Source route is `TargetSelectionInputPanes.cpp`; ItemActionInputPanes should cross-reference launcher relationship only. | Reject ItemActionInputPanes ownership. |
| What are `0x00506b80` and `0x00506bd0`? | Key handler and raw helper island select these helpers when key event modifier bit `0x04` is set; unmodified paths call previous/next selectable object helpers. | Use descriptive names `FindPreviousSelectableObjectAlternate` and `FindNextSelectableObjectAlternate`, with original enum/name caveat. | Do not leave as `sub_506B80`/`sub_506BD0`; exact original "alternate" meaning remains unresolved and should be documented. |
| What is config byte `+0x28de6c`? | Constructor/destructor use it to select/copy between SpellWho and ItemWho saved target slots; mouse double-click policy uses a different byte `+0x28de5a`. | Use semantic name `saveTargetOnClose` or `shareSpellItemTargetOnClose`; document original field name unresolved. | Reject conflating it with `doubleClick`. |
| Should raw helper island emit C++ now? | It contains executable retargeting helper bodies and uses ItemWho globals/helpers, but no direct xrefs to starts are established. | Keep page as source-authored raw helper support with descriptive names and no formal C++ until call-surface/reachability is proven. | Reject deleting/ignoring it as padding. Reject source-emitting exact helpers until entry semantics are validated. |
| Should scalar deleting destructor page carry source destructor C++? | It repeats destructor cleanup and implements compiler-generated delete flags/size path; ordinary destructor page exists. | Source C++ belongs on [UID:0001L5]. Scalar deleting destructor page should document wrapper semantics and usually stay blank or low-level-only per project policy. | Reject parent emission and avoid duplicating full destructor source twice. |

## Open Questions Closed Or Narrowed

Closed:

- Parent emit-vs-index policy: closed as non-emitting split index.
- Source placement: closed as `TargetSelectionInputPanes.cpp`, not `ItemActionInputPanes.cpp`.
- `dword_69BF24`: closed as ItemWho saved target id, best source name `s_itemWhoTargetId` / `s_itemWhoSavedTargetId`.
- Item/action byte field: closed as `m_itemSlot` in the class and `itemSlot` or `action` in packet helper scope.
- Highlight helper role: closed as `LivingObjectPane::SetTargetHighlight(bool)`.
- Packet helper roles: closed as opcode `0x1c` `SendObjectActionPacket` for ItemWho confirm and opcode `0x0f` `SendTargetedActionPacket` for other targeted action flows.
- Input-mode flag location: closed as `ItemWhoInputPaneState` field, not the global target-selection mode flags.
- Constructor no-direct-xref concern: closed as retained out-of-line constructor plus inline construction in inventory dispatch; no-direct-caller caveat remains documentation, not a blocker.

Remaining caveats that should be documented, not treated as blockers for child method C++:

- Exact original source spelling of event structs, key constants, and mouse subtype enum remains unresolved. Use descriptive names in first drafts.
- Exact original source field name for config byte `+0x28de6c` remains unresolved. Use semantic `saveTargetOnClose` / `shareSpellItemTargetOnClose` and note not `doubleClick`.
- Exact source names and call surface for raw helper island `0x005af3b0-0x005af4ef` remain unresolved. This blocks formal C++ only on [UID:0002S5].
- Exact original spelling for object-list virtual remains unresolved. `OnObjectListMessage` is a good descriptive name; preserve caveat.
- Exact "alternate" traversal semantics for `0x00506b80`/`0x00506bd0` remain inferred from modifier bit `0x04`; use descriptive alternate traversal names and avoid stronger claims.

## Parent No-Code Proof

[UID:0001L4] is ineligible for formal C++ even after score improvement because:

1. Its formal address range contains multiple separate source functions.
2. It includes compiler alignment bytes at `0x005aed3d-0x005aed40` and `0x005aedcb-0x005aedd0`.
3. It includes key-handler switch/jump-table support bytes at `0x005aefaf-0x005af050`.
4. Related ItemWho methods and helpers continue outside the parent range, so a parent-level C++ block would either omit required support or incorrectly absorb out-of-range code.
5. Exact child pages already represent the source bodies at the correct granularity.

Recommended parent text:

```md
## Formal C++ Status

No parent-level C++ is emitted for this page. [UID:0001L4] is a split index over multiple exact ItemWhoInputPane source functions and compiler support bytes, not a single source routine. Source-bearing drafts belong on the exact child method/helper pages. The parent's `RECONSTRUCTION_CPP` block intentionally remains blank.
```

## First-Draft C++ Recommendations

These drafts use high-confidence descriptive names and should be placed only on exact child pages after support docs are updated. They intentionally avoid parent emission.

### [UID:0002S1] Constructor Draft

```cpp
ItemWhoInputPane::ItemWhoInputPane(unsigned char itemSlot)
    : LineInputPane(nullptr),
      m_itemSlot(itemSlot)
{
    SetPromptText(kWhichTargetPrompt);

    unsigned int targetId = s_itemWhoTargetId;
    if (g_pConfig->saveTargetOnClose)
        targetId = s_spellWhoTargetId;

    s_itemWhoTargetId = targetId;

    LivingObjectPane *target = g_pUserPane->GetLocalPlayerObject();
    LivingObjectPane *candidate = g_activeMapPane->FindObjectPaneById(targetId);
    if (candidate != nullptr &&
        candidate->ObjectType() == kLivingObjectType &&
        !candidate->IsTargetingDisabled()) {
        target = candidate;
    }

    target->SetTargetHighlight(true);
    s_itemWhoTargetId = target->ObjectId();
}
```

Notes:

- `g_pUserPane->GetLocalPlayerObject()` is a source-facing accessor name for the documented local-player object at `dword_67A748` / established `g_pCollectionData` route; if implementation keeps the existing global naming convention, `g_pCollectionData` should be preserved with this local-player role documented.
- `saveTargetOnClose` is the descriptive name for config byte `+0x28de6c`; original field spelling remains open.
- Constructor page should retain the no-direct-caller caveat and inline-construction relationship to `UseInventorySlotDispatch`.

### [UID:0001L5] Destructor Draft

```cpp
ItemWhoInputPane::~ItemWhoInputPane()
{
    if (g_pConfig->saveTargetOnClose)
        s_spellWhoTargetId = s_itemWhoTargetId;

    ItemWhoInputPaneState *state =
        static_cast<ItemWhoInputPaneState *>(g_pGeneralPurposePanel->GetChildPaneByIndex(3));
    if (state != nullptr)
        state->SetInputModeFlag(false);
}
```

Notes:

- Base cleanup is implicit in source C++ even though the binary calls the LineInputPane cleanup helper.
- Scalar deleting destructor delete-flag logic should not be copied into this source destructor draft.

### [UID:0002S2] Key Handler Draft

```cpp
bool ItemWhoInputPane::OnKeyEvent(const KeyEvent &event)
{
    const unsigned char key = NarrowKey(event.key);

    if ((event.modifierFlags & 0x03) != 0)
        return true;

    if (event.kind != kKeyPressed)
        return false;

    LivingObjectPane *current = g_activeMapPane->FindObjectPaneById(s_itemWhoTargetId);

    if (key == kEnter) {
        if (current != nullptr) {
            ClearItemWhoTarget();
            SendObjectActionPacket(m_itemSlot, current->ObjectId());
        }
        return LineInputPane::OnKeyEvent(event);
    }

    if (key == kEscape) {
        if (current != nullptr)
            ClearItemWhoTarget();
        return LineInputPane::OnKeyEvent(event);
    }

    if (key == kSelfTarget) {
        LivingObjectPane *self = g_pUserPane->GetLocalPlayerObject();
        if (current != self) {
            if (current != nullptr)
                current->SetTargetHighlight(false);
            self->SetTargetHighlight(true);
            s_itemWhoTargetId = self->ObjectId();
        }
        return true;
    }

    LivingObjectPane *next = nullptr;
    const bool alternateTraversal = (event.modifierFlags & 0x04) != 0;

    if (IsPreviousTargetKey(key)) {
        if (current != nullptr) {
            next = alternateTraversal
                ? g_activeMapPane->FindPreviousSelectableObjectAlternate(current)
                : g_activeMapPane->FindPreviousSelectableObject(current);
        } else {
            next = g_pUserPane->GetLocalPlayerObject();
        }
    } else if (IsNextTargetKey(key)) {
        if (current != nullptr) {
            next = alternateTraversal
                ? g_activeMapPane->FindNextSelectableObjectAlternate(current)
                : g_activeMapPane->FindNextSelectableObject(current);
        } else {
            next = g_pUserPane->GetLocalPlayerObject();
        }
    } else {
        return false;
    }

    if (next == current)
        return true;

    if (current != nullptr)
        current->SetTargetHighlight(false);

    if (next != nullptr) {
        next->SetTargetHighlight(true);
        s_itemWhoTargetId = next->ObjectId();
    } else {
        s_itemWhoTargetId = 0;
    }

    return true;
}
```

Notes:

- The binary compares Enter `13`, Escape `27`, self target signed `-111`, and previous/next key groups `104`, `107`, `-128`, `-127`, `106`, `108`, `-126`, `-125`.
- The `0x04` modifier bit selects the alternate traversal helpers at `0x00506b80` and `0x00506bd0`.

### [UID:0002S3] Mouse Handler Draft

```cpp
bool ItemWhoInputPane::OnMouseEvent(const MouseEvent &event)
{
    if (event.subtype != kMouseMoveSelect && event.subtype != kMouseConfirm)
        return false;

    Point mapPoint = ToMapPoint(event.x, event.y);
    Rect mapRect = g_activeMapPane->GetBoundsRect();
    LivingObjectPane *current = g_activeMapPane->FindObjectPaneById(s_itemWhoTargetId);

    if (event.subtype == kMouseConfirm) {
        if (current == nullptr || !PointInRect(mapRect, mapPoint))
            return false;

        current->SetTargetHighlight(false);
        g_pUserPane->ClearPendingTargetObject();
        SendObjectActionPacket(m_itemSlot, current->ObjectId());
        BlackHole::QueuePaneForDeferredDeletion(this);
        return true;
    }

    LivingObjectPane *hit = g_activeMapPane->HitTestObjectAtPoint(mapPoint.x, mapPoint.y);

    if (hit != nullptr && hit != current) {
        if (current != nullptr)
            current->SetTargetHighlight(false);
        hit->SetTargetHighlight(true);
        s_itemWhoTargetId = hit->ObjectId();

        if (g_pConfig->doubleClick)
            return true;

        ClearItemWhoTarget();
        g_pUserPane->ClearPendingTargetObject();
        SendObjectActionPacket(m_itemSlot, hit->ObjectId());
        BlackHole::QueuePaneForDeferredDeletion(this);
        return true;
    }

    if (!PointInRect(mapRect, mapPoint))
        return false;

    if (g_pConfig->doubleClick || current == nullptr)
        return true;

    ClearItemWhoTarget();
    g_pUserPane->ClearPendingTargetObject();
    SendObjectActionPacket(m_itemSlot, current->ObjectId());
    BlackHole::QueuePaneForDeferredDeletion(this);
    return true;
}
```

Notes:

- `ToMapPoint` abstracts the binary's event coordinate plus pane-origin minus active-map-origin calculation.
- `g_pConfig->doubleClick` maps to config byte `+0x28de5a`, not the save-target byte used by constructor/destructor.
- The subtype names are descriptive; exact enum spelling remains open.

### [UID:0001L6] Object-List Virtual Draft

```cpp
bool ItemWhoInputPane::OnObjectListMessage(const ObjectListMessage &message)
{
    const unsigned char *payload = message.payload;
    if (payload == nullptr || payload[0] != '_')
        return false;

    const unsigned int count = NarrowCount(payload[1]);
    bool containsCurrentTarget = false;

    for (unsigned int i = 0; i < count; ++i) {
        const unsigned int objectId = ReadObjectIdFromPayload(payload + 2 + i * 4);
        if (objectId == s_itemWhoTargetId) {
            containsCurrentTarget = true;
            break;
        }
    }

    if (!containsCurrentTarget)
        return false;

    LivingObjectPane *oldTarget = g_activeMapPane->FindObjectPaneById(s_itemWhoTargetId);
    LivingObjectPane *self = g_pUserPane->GetLocalPlayerObject();

    s_itemWhoTargetId = self->ObjectId();

    if (oldTarget != nullptr)
        oldTarget->SetTargetHighlight(false);

    self->SetTargetHighlight(true);
    return false;
}
```

Notes:

- The return value appears non-consuming in the current child notes. Do not force a consumed return unless the vtable contract is proven.
- `ReadObjectIdFromPayload` names `0x005754c0` descriptively until the codec helper has a final source name.

### [UID:0001L7] Clear Helper Draft

```cpp
static void ClearItemWhoTarget()
{
    LivingObjectPane *target = g_activeMapPane->FindObjectPaneById(s_itemWhoTargetId);
    if (target != nullptr)
        target->SetTargetHighlight(false);
}
```

### [UID:0002S5] Raw Helper Island C++ Decision

No formal C++ should be emitted for [UID:0002S5] yet. The page should document descriptive helper roles:

- previous/up target step helper at `0x005af3b0-0x005af430`;
- next/down target step helper at `0x005af430-0x005af4af`;
- local-player/self-target helper at `0x005af4b0-0x005af4ef`.

But the current evidence has no direct xrefs to the helper starts and no final source call surface. Formal C++ would likely duplicate key-handler logic or invent helper names without enough support.

### [UID:0002S4] Scalar Deleting Destructor C++ Decision

Do not put ordinary source destructor C++ on the scalar deleting destructor wrapper unless project policy requires low-level compiler-wrapper C++. The source destructor body belongs on [UID:0001L5]. [UID:0002S4] should document:

- compiler-generated adjustor/thunk routes;
- duplicate destructor cleanup;
- scalar-delete flag handling;
- operator delete call/size path.

## Support Implementation Checklist

When this report is accepted, apply the following under normal lease and validator rules. Do not edit `by-memory/-coverage-report.md`; use the coverage text in this report/notes for supervisor-owned application.

1. Update [UID:0001L4] parent page:
   - set `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`;
   - keep `CANONICAL_OWNER:00006X`;
   - blank `EMITTER_UIDS`;
   - keep formal C++ blank;
   - add explicit `[[CHILDREN]]` links to [UID:0002S1], [UID:0001L5], [UID:0002S2], [UID:0002S3], and related support [UID:0001L6], [UID:0001L7], [UID:0002S5], [UID:0002S4];
   - add the parent no-code proof and boundary table.
2. Update [UID:0002S1] constructor page:
   - use `ItemWhoInputPane::ItemWhoInputPane(unsigned char itemSlot)`;
   - document prompt `Which target?`, line-input base, vtable stores, saved target initialization, fallback local player, highlight, and no-direct-caller/inline-construction evidence;
   - add first-draft constructor C++.
3. Update [UID:0001L5] destructor page:
   - use `ItemWhoInputPane::~ItemWhoInputPane()`;
   - document target-save config byte, copy between ItemWho and SpellWho saved target slots, `ItemWhoInputPaneState::SetInputModeFlag(false)`, and base cleanup;
   - add first-draft destructor C++.
4. Update [UID:0002S2] key handler page:
   - rename source method to `ItemWhoInputPane::OnKeyEvent`;
   - preserve vtable slot `0x0062f2f4`;
   - document key constants, modifier bits, Enter/Escape behavior, self-target behavior, previous/next traversal helpers, highlight update, packet send, and line-input forwarding;
   - add first-draft key-handler C++.
5. Update [UID:0002S3] mouse handler page:
   - rename source method to `ItemWhoInputPane::OnMouseEvent`;
   - preserve vtable slot `0x0062f2f0`;
   - document subtype `1` selection/hit-test, subtype `2` confirm/click, coordinate conversion, map rect test, config double-click gate, pending-target clear, packet send, and deferred pane deletion;
   - add first-draft mouse-handler C++.
6. Update [UID:0001L6] object-list virtual page:
   - use descriptive method `ItemWhoInputPane::OnObjectListMessage`;
   - preserve vtable slot `0x0062f2fc`;
   - document underscore-prefixed payload, count byte, 4-byte id decoding through `0x005754c0`, saved-target comparison, fallback to local player, and non-consuming return caveat;
   - add first-draft object-list C++.
7. Update [UID:0001L7] clear helper page:
   - source name `ClearItemWhoTarget` / `ClearSavedItemWhoTarget`;
   - owner/emitter route [UID:0000OH];
   - add first-draft helper C++.
8. Update [UID:0002S5] raw helper island page:
   - document previous/next/self helper role names;
   - keep exact no-C++ proof for now because direct xrefs/call-surface are unresolved.
9. Update [UID:0002S4] scalar deleting destructor page:
   - document compiler wrapper policy and point source destructor C++ to [UID:0001L5];
   - preserve vtable/thunk evidence and delete-flag behavior.
10. Update [UID:00006X] `by-class/ItemWhoInputPane.md`:
    - method map names and vtable slots;
    - saved-target global name;
    - `m_itemSlot` field;
    - target highlight/helper names;
    - child-emission policy that parent index does not emit.
11. Update [UID:0000OH] `by-file/TargetSelectionInputPanes.md`:
    - source placement for ItemWho methods, clear helper, raw helper island, and packet helpers;
    - relationship to SpellWho/SelectObject/TargetObject target-selection module;
    - exact child C++ ownership.
12. Update [UID:0000KC] `by-file/ItemActionInputPanes.md`:
    - keep ItemWho as a target-selection pane launched from item action dispatch, not owned by ItemActionInputPanes.
13. Update `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`:
    - document inline construction/no-direct-caller explanation;
    - document selected item slot byte passed into ItemWho and `SendObjectActionPacket`.
14. Update [UID:0002AB] `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`:
    - record source-facing names `s_spellWhoTargetId`, `s_itemWhoTargetId`, select-object and target-object saved ids;
    - mention accepted alias `g_savedItemWhoTargetObjectId` for `dword_69BF24` if supervisor wants project-wide global naming.
15. Update `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md` and [UID:00006Y] state docs:
    - clarify that ItemWho active state uses `ItemWhoInputPaneState::SetInputModeFlag(+0xfa)`, not this global flag cluster.
16. Update MapPane helper docs:
    - confirm `FindObjectPaneById`, previous/next traversal, alternate previous/next traversal, and hit-test helper names;
    - preserve caveat for exact original names of alternate traversal helpers.
17. Update `by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md`:
    - add exact ItemWho primary/secondary/tertiary vtable slice;
    - include slots `0x0062f2f0`, `0x0062f2f4`, `0x0062f2fc`, destructor slot `0x0062f29c`, and adjustor thunks `0x005b780a`/`0x005b7815`.
18. Update `by-memory/-ignored.md` only if supervisor-owned ignored rows need text refinements:
    - keep `0x005aed3d-0x005aed40`, `0x005aedcb-0x005aedd0`, `0x005aefaf-0x005af050`, `0x005af2e7-0x005af2f0`, `0x005af383-0x005af390`, `0x005b780a-0x005b7820`, and `0x005b7aec-0x005b7af0` documented as padding/switch/thunk rows.
19. Run scoped validators for every edited target/support page.

Recommended scoped validators after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0001L4-ItemWhoInputPane-source-quality-removed.md](0001L4-ItemWhoInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Exact Supervisor-Owned Coverage Replacement Text

Do not edit `by-memory/-coverage-report.md` from B013. Replace the existing [UID:0001L4] row and its immediate child/ignored rows through the object-list padding region with this block:

```md
    - [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md) 0x005aec60-0x005af2e7 | non-emitting split index | ItemWhoInputPane : ignored/non-emitting : 88% : very strong : B013 source-quality reanalysis resolves the old aggregate as a non-emitting `ItemWhoInputPane` split index under `TargetSelectionInputPanes.cpp`: exact child [UID:0002S1][0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor](by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md) is the source constructor, [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md) is the non-deleting source destructor, [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md) is the key handler, and [UID:0002S3][0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput](by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md) is the mouse handler; internal `0xcc` alignment and key-switch support bytes mean parent C++ must remain blank, while adjacent [UID:0001L6] object-list virtual, [UID:0001L7] clear helper, [UID:0002S5] raw helper island, and [UID:0002S4] scalar deleting destructor remain exact support pages.
        - [UID:0002S1][0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor](by-memory/0x005aec60-0x005aed3d.ItemWhoInputPaneConstructor.md) 0x005aec60-0x005aed3d | constructor | ItemWhoInputPane::ItemWhoInputPane : reconstructable : 88% : strong : Source constructor for `ItemWhoInputPane`; calls `LineInputPane`, sets the `Which target?` prompt, installs ItemWho vtables, stores the selected item slot/action byte at full-object `+0x108`, initializes `s_itemWhoTargetId` from ItemWho/SpellWho saved-target state under the target-save config byte, validates or falls back to the local player object, highlights the selected target, and has no ordinary direct caller because inventory dispatch also contains an inline construction path.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005aed3d-0x005aed40 | padding | ItemWhoInputPane constructor/destructor padding : ignored : 100% : strong : Three `0xcc` bytes between the constructor return and the non-deleting destructor prologue; not source C++.
        - [UID:0001L5][0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor](by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md) 0x005aed40-0x005aedcb | destructor | ItemWhoInputPane::~ItemWhoInputPane : reconstructable : 88% : strong : Source non-deleting destructor for `ItemWhoInputPane`; restores class vtables, copies `s_itemWhoTargetId` into the SpellWho saved-target slot when the target-save config byte is set, clears the ItemWho input-mode state through `ItemWhoInputPaneState::SetInputModeFlag(false)` on GeneralPurposePanel child index 3, and runs LineInputPane/base cleanup.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005aedcb-0x005aedd0 | padding | ItemWhoInputPane destructor/key padding : ignored : 100% : strong : Five `0xcc` bytes between the non-deleting destructor and key-handler prologue; not source C++.
        - [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md) 0x005aedd0-0x005aefaf | virtual method | ItemWhoInputPane::OnKeyEvent : reconstructable : 88% : strong : Vtable-routed key handler at slot `0x0062f2f4`; consumes modifier-reserved keys, handles Enter/Escape through `ClearItemWhoTarget`, `SendObjectActionPacket`, and LineInputPane forwarding, handles self-target, previous/up and next/down target navigation through `MapPane` lookup/traversal helpers including alternate traversal on modifier bit `0x04`, updates `s_itemWhoTargetId`, and toggles `LivingObjectPane::SetTargetHighlight`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005aefaf-0x005af050 | switch-table | ItemWhoInputPane key-handler switch support : ignored : 100% : strong : Compiler switch/jump-table support and alignment bytes after the key handler; not an independent source function.
        - [UID:0002S3][0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput](by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md) 0x005af050-0x005af2e7 | virtual method | ItemWhoInputPane::OnMouseEvent : reconstructable : 88% : strong : Vtable-routed mouse handler at slot `0x0062f2f0`; handles subtype `1` target hit-test/selection and subtype `2` confirmation, converts pane/event coordinates into active-map coordinates, uses `MapPane::HitTestObjectAtPoint`, gates immediate send behavior through the config double-click/target-click byte, clears pending local-player target state, sends opcode `0x1c` through `SendObjectActionPacket(m_itemSlot, targetId)`, and queues the pane for deferred deletion.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005af2e7-0x005af2f0 | padding | ItemWhoInputPane mouse/object-list padding : ignored : 100% : strong : Nine `0xcc` bytes after the mouse handler and before the adjacent object-list virtual; not source C++.
        - [UID:0001L6][0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual](by-memory/0x005af2f0-0x005af383.ItemWhoInputPaneObjectListVirtual.md) 0x005af2f0-0x005af383 | virtual method | ItemWhoInputPane::OnObjectListMessage : reconstructable : 88% : strong : Adjacent ItemWho object-list virtual at slot `0x0062f2fc`; parses underscore-prefixed object-list payloads, decodes 4-byte object ids through the payload codec helper, compares entries to `s_itemWhoTargetId`, and when the saved target appears in the payload resets target selection/highlight to the local player object while returning through the non-consuming virtual path.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005af383-0x005af390 | padding | ItemWhoInputPane object-list/clear-helper padding : ignored : 100% : strong : Thirteen `0xcc` bytes between the object-list virtual and the file-local clear helper; not source C++.
```

Also replace/refine these related support rows when supervisor applies coverage updates:

```md
        - [UID:0001L7][0x005af390-0x005af3af.ClearItemWhoTarget](by-memory/0x005af390-0x005af3af.ClearItemWhoTarget.md) 0x005af390-0x005af3af | file helper | ClearItemWhoTarget : reconstructable : 88% : strong : File-local `TargetSelectionInputPanes.cpp` helper with no receiver; resolves `s_itemWhoTargetId` through `MapPane::FindObjectPaneById` and clears `LivingObjectPane::SetTargetHighlight(false)`, with callers from ItemWho key Enter/Escape and mouse send paths.
        - [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) 0x005af3b0-0x005af4ef | raw-helper island | ItemWho target navigation helpers : reconstructable/no-formal-cpp : 85% : strong : Source-authored raw helper island for previous/up, next/down, and local-player ItemWho retargeting; uses `s_itemWhoTargetId`, active MapPane traversal helpers, fallback local player, and highlight transitions, but direct xrefs to helper starts and exact original helper names remain unresolved, so formal C++ should stay blank pending reachability proof.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005b780a-0x005b7820 | thunk | ItemWhoInputPane destructor adjustor thunks : ignored : 100% : strong : Two compiler-generated ItemWho adjustor thunks into the scalar deleting destructor, `sub ecx,0xa0; jmp 0x005b7a20` and `sub ecx,0xa4; jmp 0x005b7a20`, referenced by ItemWho non-primary vtable facets; not source C++.
    - [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md) 0x005b7a20-0x005b7aec | scalar deleting destructor | ItemWhoInputPane scalar deleting destructor : reconstructable/no-source-cpp : 88% : strong : Compiler scalar deleting destructor wrapper for `ItemWhoInputPane`; repeats destructor cleanup, target-save/state-clear behavior, and vtable restoration, then handles delete flags and operator delete/size path. Source destructor C++ belongs on [UID:0001L5], while this page documents wrapper semantics and vtable/thunk reachability.
```

## Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R002 was removed from this report and preserved verbatim in [0001L4-ItemWhoInputPane-source-quality-removed.md](0001L4-ItemWhoInputPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`.
- Target `ok` count: `1`.
- Key output: `ok 0001L4 by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md UID header exists`.
- Dry-run global/generated-output notices were present, including `autogen_emitter_has_no_code` and generated report no-ops; none were target failures.

## Report-Only File Changes

Created report:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B013\research\0001L4-ItemWhoInputPane-source-quality.md
```

Required notes update:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B013\notes.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0001L4-ItemWhoInputPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001L4"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001L4-ItemWhoInputPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0001L4-ItemWhoInputPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001L4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
