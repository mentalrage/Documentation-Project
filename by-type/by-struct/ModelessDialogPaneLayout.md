*** UID:0001V9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008K | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ModelessDialogPane Layout

## Status

- Entity kind: class layout / secondary-view event-state notes.
- Covered class: [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md).
- Likely owner header/source: [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md).
- Confidence: strong for vtable offsets, secondary-view mapping, inherited field roles used by the mouse handler, and no-derived-tail decision; medium-high for exact original field spellings.
- Owner/emitter route: attached to [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md), which emits through [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md). The class now scores `89/88` and the file scores `89/85`, so the direct owner and emitted source root clear the corrected gate.

## Layout Summary

`ModelessDialogPane` uses the same three-view layout as [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) over [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). B015 reanalysis keeps the no-derived-tail decision: fields used by the modeless mouse handler from `+0x208` through `+0x238` are inherited `DialogPane` interaction state, not a `ModelessDialogPane` tail. Its class-specific behavior is concentrated in the constructor, `IsModal`, and the secondary-view mouse-event handler.

| Base object offset | Field/state | Evidence |
| --- | --- | --- |
| `+0x00` | primary vptr, `0x00618c48` | Constructor `0x004a0760` installs the primary table at `0x004a07bd`. |
| `+0xa0` | secondary event/input vptr, `0x00618ca8` | Constructor installs at `0x004a07c4` and registers `this + 0xa0` with the event dispatcher. |
| `+0xa4` | tertiary event/update vptr, `0x00618cd8` | Constructor installs at `0x004a07ca`; table is the common short tertiary view. |
| `+0x0f8-+0x268` | inherited `DialogPane` title/config/control/mouse/background state | See [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md). `HandlePointerOrMouseEvent` reuses inherited `DialogPane` state rather than owning a class-specific tail. |

## Secondary-View Offset Mapping

`ModelessDialogPane::HandlePointerOrMouseEvent` at `0x004a0840` receives `ecx == object + 0xa0`. In IDA disassembly the local `esi` is that secondary-view pointer, and the core `DialogPane` pointer is recovered with `esi - 0xa0`. Therefore generated offsets such as `context + 360` are secondary-relative and must be translated back to base-object offsets.

| IDA access | Base object offset | Field/state hypothesis | Evidence |
| --- | --- | --- | --- |
| `[esi+0x158]` | `+0x1f8` | `m_dialogConfigId` | Release path checks for `0xffff` before saving bounds/focus state. |
| `[esi+0x15c]` | `+0x1fc` | `m_controlManager` | Mouse-down/release paths use this pointer to look up control entries. |
| `[esi+0x168]` | `+0x208` | `m_titleDragActive` | Mouse-down on hit type `10` sets it to `1`; release clears it to `0`. |
| `[esi+0x169]` | `+0x209` | `m_savedPaneMode` | Mouse-down saves byte `[esi+0x15]`; release restores it through [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md). |
| `[esi+0x16c]` | `+0x20c` | `m_dragOriginY` | Mouse-down stores the current mouse Y; move subtracts it while updating vertical position. |
| `[esi+0x170]` | `+0x210` | `m_dragOriginX` | Mouse-down stores the current mouse X; move subtracts it while updating horizontal position. |
| `[esi+0x174]` | `+0x214` | `m_hoverControlId` / current active-control alias | Mouse-down compares the hit id against this field before invoking hover candidate callback; broader DialogPane docs keep `m_activeControlId` where key/control paths use it as active/current id. |
| `[esi+0x178]` | `+0x218` | `m_pressedControlActive` | Mouse-down sets it; release clears it before dispatching release behavior. |
| `[esi+0x17c]` | `+0x21c` | `m_pressedControlId` | Mouse-down stores the hit id; move/release compare and dispatch through it. |
| `[esi+0x180]` | `+0x220` | `m_pressedHitType` | Mouse-down stores the hit type; release checks it before activating. |
| `[esi+0x184]` | `+0x224` | `m_selectedControlId` | Release resets this field to `-1` after clearing previous control state. |
| `[esi+0x188]` | `+0x228` | `m_selectedHitType` / visual-state byte | Release resets this to hit type `10`; mouse code treats `10` as title/chrome or neutral state. |
| `[esi+0x189]` | `+0x229` | `m_dragClampEnabled` | Move path checks this before clamping to min/max bounds. |
| `[esi+0x18c]` | `+0x22c` | `m_dragClampMinX` | Horizontal drag movement clamps the origin against this minimum X value. |
| `[esi+0x190]` | `+0x230` | `m_dragClampMinY` | Vertical drag movement clamps the origin against this minimum Y value. |
| `[esi+0x194]` | `+0x234` | `m_dragClampMaxX` | Horizontal drag movement clamps the right edge against this maximum X value. |
| `[esi+0x198]` | `+0x238` | `m_dragClampMaxY` | Vertical drag movement clamps the bottom edge against this maximum Y value. |

The disassembly also reads `[esi-0x5c]`, `[esi-0x54]`, and `[esi-0x50]`, which translate to base `Pane`/`DialogPane` rectangle and extent state. Those are inherited fields, not `ModelessDialogPane`-specific members.

## IDA Evidence

Checked on 2026-05-26:

- Constructor `0x004a0760` calls `DialogPane::DialogPane(title, -1, 1)`, installs three `ModelessDialogPane` vtables, initializes default bounds `(100,100)-(200,200)`, initializes pane interaction, and registers the secondary view with the event dispatcher.
- `IsModal` at `0x004a0830` returns false and is referenced from secondary vtable `0x00618ca8 + 0x08`.
- `HandlePointerOrMouseEvent` at `0x004a0840` is referenced from secondary vtable `0x00618ca8 + 0x04`, computes `dialogCore = this - 0xa0`, and uses the translated offsets above for drag, hover, pressed-control, and clamp behavior.
- No direct constructor callers were found in this pass, but vtable references and executable method bodies make this a real reconstructable class.

Rechecked on 2026-05-31:

- IDA MCP `lookup_funcs` reports `0x004a0760` size `0xc7`, `0x004a0830` size `0x5`, and `0x004a0840` size `0x44e`.
- IDA MCP decompilation confirms the constructor calls `DialogPane::DialogPane(title, -1, 1)`, writes the primary/secondary/tertiary vtables, creates default bounds `(100,100)-(200,200)`, initializes pane interaction, and registers `this + 0xa0` through the event dispatcher.
- IDA MCP `xrefs_to` confirms constructor data writes to vtables `0x00618c48`, `0x00618ca8`, and `0x00618cd8`; it also confirms data references to `IsModal` at `0x00618cb0` and `HandlePointerOrMouseEvent` at `0x00618cac`.
- IDA MCP disassembly confirms `HandlePointerOrMouseEvent` stores `ecx` in `esi` as the secondary-view pointer and repeatedly uses `lea ..., [esi-0xa0]` for the base `DialogPane` object, so the `+0x168..+0x198` accesses are secondary-relative views of base-object fields.

Rechecked on 2026-06-14:

- Live IDA MCP `lookup_funcs` reconfirmed the exact local method starts and boundaries: constructor `0x004a0760` size `0xc7`, `IsModal` `0x004a0830` size `0x5`, and `HandlePointerOrMouseEvent` `0x004a0840` size `0x44e`; `199 == 0xc7`, `5 == 0x5`, and `1102 == 0x44e` were verified with `int_convert.py`.
- Live IDA MCP `lookup_funcs` reports `0x004a0827`, `0x004a0835`, `0x004a0c8e`, and `0x004a0c90` are not function starts, keeping the constructor/`IsModal`/handler split exact.
- Live IDA MCP `xrefs_to` reconfirmed the constructor writes to vtables `0x00618c48`, `0x00618ca8`, and `0x00618cd8`, plus the secondary-vtable entries `0x00618cac -> 0x004a0840` and `0x00618cb0 -> 0x004a0830`.
- Live IDA MCP decompilation of the constructor shows `this[40] = &ModelessDialogPane::vftable` and `this[41] = &ModelessDialogPane::vftable`, matching the `+0xa0` and `+0xa4` secondary/tertiary view vptr slots (`160 == 0xa0`, verified with `int_convert.py`).
- Live IDA MCP decompilation of `HandlePointerOrMouseEvent` shows the `this` parameter is the secondary-view pointer and uses negative offsets such as `this - 160` for the base `DialogPane` core; the handler's positive offsets `+360..+408` are therefore secondary-relative views of base-object state, not a separate derived tail.
- Live IDA MCP `get_bytes 0x004a0c8e size 34` shows the post-handler boundary is a two-byte `66 90` alignment followed by the jump table beginning at `0x004a0c90`, so the handler body still ends at `0x004a0c8e`.
- B015 raw PE recheck found no VA/RVA/raw-offset pointer hits and no `.text` rel32 branches to constructor `0x004a0760`; the constructor's three vtable immediates occur only as stores at `0x004a07bd`, `0x004a07c4`, and `0x004a07ca`. `IsModal` and `HandlePointerOrMouseEvent` are vtable-only by static refs at `0x00618cb0` and `0x00618cac`.
- B015 also confirms the modeless handler's EventMan type map: `0` cursor move, `1` left down, `2` left double-click, `3` left up, and `7` mouse wheel. Right-button types are part of the global event system but not this switch.

## Score Rationale

- Completion `93`: the page records the three-view layout, exact owner/emitter route, method boundaries, vtable refs, secondary-to-base translation, corrected Y/X and clamp-axis order, inherited-state rule, event map, negative constructor reachability, and successor boundaries.
- Confidence `95`: exact instruction operands, live IDA evidence, and raw PE evidence corroborate the translation and field ordering. Original lexical spellings are inferred, but no layout ambiguity remains.

## Reconstruction Notes

- Do not create a separate modeless tail for the generated `context + 360` through `context + 408` fields. Those are secondary-relative views of inherited `DialogPane +0x208` through `+0x238` state.
- `ModelessDialogPane` should still remain its own class/source file because it installs its own vtables and owns the modeless event handler.
- Final field names should be coordinated with [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) so modal/modeless/session dialogs use one inherited layout.
- B015's `m_hoverControlId`, `m_selectedHitType`, and drag-bound names are accepted as modeless-handler roles; where [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) uses broader canonical names such as `m_activeControlId` or `m_selectionVisualState`, treat them as aliases for the same inherited storage until a final header spelling pass resolves one shared name.

## UID000312 Exact Translation Reconciliation

- The complete-object translation is mechanical: every secondary-view operand is `0xa0` lower than its inherited `DialogPane` offset. No derived tail exists after `DialogPane`.
- Exact instruction operands supersede the older aliases: `+0x20c` is Y and `+0x210` is X; clamp order is minX, minY, maxX, maxY at `+0x22c/+0x230/+0x234/+0x238`.
- The secondary slot is the `EventHandler` override `HandlePointerOrMouseEvent(Event *)`, not an independent Modeless-only mouse interface.
- Earlier `m_dragStartX/m_dragStartY` and top/left/bottom/right labels remain visible in dated evidence/change history as superseded hypotheses, not current declaration guidance.
- Direct constructor reachability remains absent, while three constructor vtable stores and the `0x00618cac` handler slot provide positive class/layout evidence. The negative allocation evidence does not justify inventing fields or a derived tail.

## Cross-References

- [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md)
- [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md)
- [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md)
- [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md)
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-14: Raised completion/confidence from `82/88` to `85/90`.
  - Before: the layout had strong 2026-05 evidence but stale autogen-parent wording, older parent-score text, and no current method-boundary/jump-table recheck.
  - After: live IDA MCP reconfirms constructor/`IsModal`/handler sizes, non-function boundaries, vtable stores, secondary-vtable slots, constructor vptr writes at `+0xa0/+0xa4`, handler `this - 0xa0` base adjustment, and the `0x004a0c8e` alignment before the `0x004a0c90` jump table. Final C++ remains blank because the layout clears the minimum score/emitter gate but final inherited field names and source declarations are not source-quality yet.

- 2026-06-06: Attached the layout to [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md). Scores remain `82/88`; the update only syncs parent metadata for the already documented three-view dialog layout.
- Before: completion/confidence were `0/0`, and `RECONSTRUCTABLE` was blank despite the page containing IDA-backed layout research.
- Changed to: completion `82`, confidence `88`, and `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: 2026-05-31 IDA MCP rechecked function boundaries, constructor vtable stores, secondary vtable references for `IsModal` and `HandleMouseEvent`, and the `this + 0xa0` secondary-view offset translation. Scores remain below `95` because final inherited field names and live allocation sites are still not fully resolved.
- 2026-06-22 B015 source-quality incorporation:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter unchanged at [UID:00008K][ModelessDialogPane](by-class/ModelessDialogPane.md).
  - Summary/evidence: B015 validates the three-view layout against raw PE constructor stores, corrects stale `vtable_count:0` implications, maps secondary-view handler offsets to inherited `DialogPane` roles with high-probability names, documents the corrected mouse event type map, and keeps the no-derived-tail decision for `+0x208..+0x238`.
