*** UID:0001YW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpecializedButtonPane Vtables

## Status

- Confidence: very strong for exact vtable addresses, COL/CHD/PMD hierarchy, child boundaries, slot spans and targets, inherited facets, and vptr-store xrefs. These compiler tables are false/non-emitting evidence; human declarations emit through class H pages.
- Likely owner: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- Related file doc: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Exact vtable-data children: [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md), [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md), and [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md).

## GenderButtonControlPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x0061db90` | `+0x00 -> 0x00502700` scalar deleting destructor; `+0x44 -> 0x00500700` paint; `+0x48 -> 0x005006d0` state setter; `+0x68 -> 0x005024a0` secondary adjustor thunk. |
| secondary | `0x0061dbf8` | `+0x00 -> 0x005024a0` this-adjustor into scalar deleting destructor. |
| tertiary | `0x0061dc28` | `+0x00 -> 0x005024ab` this-adjustor into scalar deleting destructor. |

The exact compiler island is [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md), with primary/EventHandler/TimerHandler slot spans `25/11/2`. Its COLs point to one eight-base hierarchy: GenderButtonControlPane, ButtonControlPane, ControlPane, Pane, GrafPort, LObject, EventHandler, and TimerHandler. PMDs place the primary source object at `0`, inherited EventHandler at `+0xa0`, and inherited TimerHandler at `+0xa4`.

Source-bearing physical children are [UID:0004ZV][0x00500640-0x00500690.GenderButtonControlPaneConstructor](by-memory/0x00500640-0x00500690.GenderButtonControlPaneConstructor.md), [UID:0004ZW][0x00500690-0x00500697.GenderButtonControlPaneIsSelected](by-memory/0x00500690-0x00500697.GenderButtonControlPaneIsSelected.md), [UID:0004ZX][0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected](by-memory/0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected.md), [UID:0004ZY][0x005006d0-0x005006ff.GenderButtonControlPaneSetVisualState](by-memory/0x005006d0-0x005006ff.GenderButtonControlPaneSetVisualState.md), and [UID:0004ZZ][0x00500700-0x00500797.GenderButtonControlPaneOnPaint](by-memory/0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md). Compiler COL cells, table dwords, scalar deleting wrapper, and adjustors emit no handwritten source.

## DirectionButtonControlPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x0061dc34` | Exact 25-slot span `[0x0061dc34,0x0061dc98)`; `+0x00 -> 0x005026a0` scalar deleting destructor, `+0x44 -> 0x00500820` paint, `+0x48 -> 0x005007f0` state setter, and final slot `+0x60 -> 0x004242f0`. There is no primary `+0x68` slot. |
| secondary | `0x0061dc9c` | `+0x00 -> 0x0050248a` this-adjustor into scalar deleting destructor. |
| tertiary | `0x0061dccc` | `+0x00 -> 0x00502495` this-adjustor into scalar deleting destructor. |

The exact compiler island is [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md). Its three COL-adjacent views contain `25/11/2` slots: primary `[0x0061dc34,0x0061dc98)`, inherited EventHandler `[0x0061dc9c,0x0061dcc8)`, and inherited TimerHandler `[0x0061dccc,0x0061dcd4)`. The next dword at `0x0061dcd4` is the `BlueAlertPane` COL, so the historical primary `+0x68` presentation was outside the primary table and is superseded.

All three COLs share TypeDescriptor `0x00677564` and class-hierarchy descriptor `0x0064abfc`. The eight RTTI rows are `DirectionButtonControlPane`, `ButtonControlPane`, `ControlPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler`; PMDs place the complete object at `0`, inherited EventHandler at `+0xa0`, and inherited TimerHandler at `+0xa4`. Therefore the human declaration has one direct source base, `ButtonControlPane`; the two secondary views are inherited facets, not repeated direct bases.

| Primary slot / cell | Target | Source-facing role |
| --- | --- | --- |
| `0 / 0x0061dc34` | `0x005026a0` | compiler scalar-deleting wrapper |
| `1 / 0x0061dc38` | `0x004f4b10` | inherited `LObject::GetRuntimeClass` |
| `2 / 0x0061dc3c` | `0x0041b6c0` | inherited `LObject::OnChangeMessage` |
| `3 / 0x0061dc40` | `0x004b8e20` | inherited `Pane::UpdateRenderRegion` |
| `4 / 0x0061dc44` | `0x0041d680` | inherited `Pane::DrawOnTarget` |
| `5 / 0x0061dc48` | `0x00544730` | inherited `Pane::Show` |
| `6 / 0x0061dc4c` | `0x00544750` | inherited `Pane::Hide` |
| `7 / 0x0061dc50` | `0x005447a0` | inherited `Pane::GetParentPane` |
| `8 / 0x0061dc54` | `0x00544800` | inherited `Pane::InvalidateRect` |
| `9 / 0x0061dc58` | `0x00544a20` | inherited `Pane::GetDescription` |
| `10 / 0x0061dc5c` | `0x00544b80` | inherited `Pane::GetScreenBounds` |
| `11 / 0x0061dc60` | `0x00544bd0` | inherited `Pane::SetBounds` |
| `12 / 0x0061dc64` | `0x00544c70` | inherited `Pane::AddToLayer` |
| `13 / 0x0061dc68` | `0x00544cb0` | inherited `Pane::InsertInLayer` |
| `14 / 0x0061dc6c` | `0x00544ce0` | inherited `Pane::RemoveFromLayer` |
| `15 / 0x0061dc70` | `0x00544d30` | inherited `Pane::SetPaneOrder` |
| `16 / 0x0061dc74` | `0x00544d70` | inherited `Pane::UnregisterEventHandler` |
| `17 / 0x0061dc78` | `0x00500820` | `DirectionButtonControlPane::OnPaint` |
| `18 / 0x0061dc7c` | `0x005007f0` | `DirectionButtonControlPane::SetVisualState` |
| `19 / 0x0061dc80` | `0x00494bb0` | inherited `ControlPane::Enable` |
| `20 / 0x0061dc84` | `0x00494bd0` | inherited `ControlPane::Disable` |
| `21 / 0x0061dc88` | `0x00494c00` | inherited `ControlPane::SetIgnoreHitTesting` |
| `22 / 0x0061dc8c` | `0x00494c10` | inherited `ControlPane::Deactivate` |
| `23 / 0x0061dc90` | `0x00494c30` | inherited `ControlPane::Activate` |
| `24 / 0x0061dc94` | `0x004242f0` | shared control-family type-code virtual returning `11` |

| EventHandler slot / cell | Target | Source-facing role |
| --- | --- | --- |
| `0 / 0x0061dc9c` | `0x0050248a` | compiler `this -= 0xa0` deleting-wrapper adjustor |
| `1 / 0x0061dca0` | `0x00544db0` | inherited pointer/mouse default |
| `2 / 0x0061dca4` | `0x00494f70` | inherited `ButtonControlPane::HandleKeyOrTextEvent` |
| `3 / 0x0061dca8` | `0x0041d6b0` | inherited IME false/default |
| `4 / 0x0061dcac` | `0x00544de0` | inherited packet-event default |
| `5 / 0x0061dcb0` | `0x00544df0` | inherited system/control-event default |
| `6 / 0x0061dcb4` | `0x00544e00` | inherited type-19 default |
| `7 / 0x0061dcb8` | `0x004a89f0` | inherited `EventHandler::ForwardHandlerOrder` |
| `8 / 0x0061dcbc` | `0x00544e10` | inherited local-event pair |
| `9 / 0x0061dcc0` | `0x00544e30` | inherited screen-event pair |
| `10 / 0x0061dcc4` | `0x00544e70` | inherited acceptance predicate |

| TimerHandler slot / cell | Target | Source-facing role |
| --- | --- | --- |
| `0 / 0x0061dccc` | `0x00502495` | compiler `this -= 0xa4` deleting-wrapper adjustor |
| `1 / 0x0061dcd0` | `0x00544e90` | inherited `Pane::OnTimer` default |

Source-bearing physical children are [UID:00050G][0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor](by-memory/0x005007a0-0x005007e8.DirectionButtonControlPaneConstructor.md), [UID:00050H][0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState](by-memory/0x005007f0-0x0050081e.DirectionButtonControlPaneSetVisualState.md), and [UID:00050I][0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint](by-memory/0x00500820-0x005008b9.DirectionButtonControlPaneOnPaint.md). UID00003X emits one normal class declaration; COL cells, raw table dwords, scalar-deleting mechanics, and receiver adjustors remain compiler-only and non-emitting.

## CheckBoxTextControlPane

| Vtable | Address | Key slots |
| --- | --- | --- |
| primary | `0x0062e99c` | Exact 25-slot span `[0x0062e99c,0x0062ea00)`; `+0x00 -> 0x0059f050` scalar deleting destructor, `+0x44 -> 0x0059df50` paint, and terminal `+0x60 -> 0x004214c0` shared `HitTestPart(int,int)`. There is no primary `+0x68` slot. |
| secondary | `0x0062ea04` | `+0x00 -> 0x0059efeb` this-adjustor into scalar deleting destructor. |
| tertiary | `0x0062ea34` | `+0x00 -> 0x0059eff6` this-adjustor into scalar deleting destructor. |

The exact compiler island is [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md), SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`. Its 41 four-byte cells comprise three COL pointers and `25/11/2` table slots. The three COLs share `CheckBoxTextControlPane` RTTI and establish one direct `ControlPane` source base; inherited `EventHandler` and `TimerHandler` facets use PMD offsets `+0xa0` and `+0xa4`.

| Primary slot / cell | Target | Source-facing role |
| --- | --- | --- |
| `0 / 0x0062e99c` | `0x0059f050` | compiler scalar-deleting wrapper |
| `1 / 0x0062e9a0` | `0x004f4b10` | inherited `LObject::GetRuntimeClass` |
| `2 / 0x0062e9a4` | `0x0041b6c0` | inherited `LObject::OnChangeMessage` |
| `3 / 0x0062e9a8` | `0x004b8e20` | inherited `Pane::UpdateRenderRegion` |
| `4 / 0x0062e9ac` | `0x0041d680` | inherited `Pane::DrawOnTarget` |
| `5 / 0x0062e9b0` | `0x00544730` | inherited `Pane::Show` |
| `6 / 0x0062e9b4` | `0x00544750` | inherited `Pane::Hide` |
| `7 / 0x0062e9b8` | `0x005447a0` | inherited `Pane::GetParentPane` |
| `8 / 0x0062e9bc` | `0x00544800` | inherited `Pane::InvalidateRect` |
| `9 / 0x0062e9c0` | `0x00544a20` | inherited `Pane::GetDescription` |
| `10 / 0x0062e9c4` | `0x00544b80` | inherited `Pane::GetScreenBounds` |
| `11 / 0x0062e9c8` | `0x00544bd0` | inherited `Pane::SetBounds` |
| `12 / 0x0062e9cc` | `0x00544c70` | inherited `Pane::AddToLayer` |
| `13 / 0x0062e9d0` | `0x00544cb0` | inherited `Pane::InsertInLayer` |
| `14 / 0x0062e9d4` | `0x00544ce0` | inherited `Pane::RemoveFromLayer` |
| `15 / 0x0062e9d8` | `0x00544d30` | inherited `Pane::SetPaneOrder` |
| `16 / 0x0062e9dc` | `0x00544d70` | inherited `Pane::UnregisterEventHandler` |
| `17 / 0x0062e9e0` | `0x0059df50` | `CheckBoxTextControlPane::OnPaint` |
| `18 / 0x0062e9e4` | `0x00494b80` | inherited `ControlPane::SetVisualState` |
| `19 / 0x0062e9e8` | `0x00494bb0` | inherited `ControlPane::Enable` |
| `20 / 0x0062e9ec` | `0x00494bd0` | inherited `ControlPane::Disable` |
| `21 / 0x0062e9f0` | `0x00494c00` | inherited `ControlPane::SetIgnoreHitTesting` |
| `22 / 0x0062e9f4` | `0x00494c10` | inherited `ControlPane::Deactivate` |
| `23 / 0x0062e9f8` | `0x00494c30` | inherited `ControlPane::Activate` |
| `24 / 0x0062e9fc` | `0x004214c0` | shared folded `CheckBoxTextControlPane::HitTestPart(int,int)`, returns `22` |

| EventHandler slot / cell | Target | Source-facing role |
| --- | --- | --- |
| `0 / 0x0062ea04` | `0x0059efeb` | compiler `this -= 0xa0` deleting-wrapper adjustor |
| `1 / 0x0062ea08` | `0x00544db0` | inherited pointer/mouse default |
| `2 / 0x0062ea0c` | `0x0041d6b0` | inherited key/text false default |
| `3 / 0x0062ea10` | `0x0041d6b0` | inherited IME false default, same folded body |
| `4 / 0x0062ea14` | `0x00544de0` | inherited packet-event default |
| `5 / 0x0062ea18` | `0x00544df0` | inherited system/control-event default |
| `6 / 0x0062ea1c` | `0x00544e00` | inherited type-19 default |
| `7 / 0x0062ea20` | `0x004a89f0` | inherited `EventHandler::ForwardHandlerOrder` |
| `8 / 0x0062ea24` | `0x00544e10` | inherited local-event pair |
| `9 / 0x0062ea28` | `0x00544e30` | inherited screen-event pair |
| `10 / 0x0062ea2c` | `0x00544e70` | inherited acceptance predicate |

| TimerHandler slot / cell | Target | Source-facing role |
| --- | --- | --- |
| `0 / 0x0062ea34` | `0x0059eff6` | compiler `this -= 0xa4` deleting-wrapper adjustor |
| `1 / 0x0062ea38` | `0x00544e90` | inherited `Pane::OnTimer` default |

Primary head stores are `0x0059c789`, `0x0059c81f`, `0x0059defc`, `0x0059df30`, `0x0059e23f`, and `0x0059f056`; secondary stores are `0x0059c795`, `0x0059c82b`, `0x0059df02`, `0x0059df36`, `0x0059e24b`, and `0x0059f05c`; tertiary stores are `0x0059c79f`, `0x0059c835`, `0x0059df0c`, `0x0059df40`, `0x0059e255`, and `0x0059f066`. Source-bearing children are UID0003FE constructor, UID0003FF ordinary destructor, UID0003FG paint, UID0003FH setter, UID0003FI getter, and UID0002DZ HitTestPart. UID0003FJ scalar deletion plus the two adjustors are compiler-only.

## Evidence

- 2026-05-26 IDA MCP `py_eval` read the listed vtable dwords directly from the IDB.
- 2026-05-26 IDA MCP `xrefs_to` ties the primary vtables to inline constructor/setup writes in `NewUserMiscDialogPane` and `PartySearchEditPane`, plus scalar deleting destructor reset writes.
- 2026-05-26 IDA MCP `xrefs_to` confirms the adjustor thunk targets are vtable-only glue and code refs into the real scalar deleting destructors.
- 2026-06-01 IDA MCP `py_eval` confirms the exact `.rdata` child boundaries: `GenderButtonControlPane` occupies `0x0061db8c-0x0061dc30`, `DirectionButtonControlPane` occupies `0x0061dc30-0x0061dcd4`, and `CheckBoxTextControlPane` occupies `0x0062e998-0x0062ea3c`.
- 2026-06-11 A007 Batch161 confirms the exact executable consumers for the gender/direction destructor slots through new child pages [UID:00036W][0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor](by-memory/0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor.md) and [UID:00036X][0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor](by-memory/0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md). The direct file parent [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) is now `85/86`, so this type page can attach under the strict `85/85` gate.
- 2026-06-11 A005 Batch 174 live IDA MCP recheck reconfirmed the concrete RTTI locator dwords and primary/secondary/tertiary vtable heads:
  - `0x0061db8c -> ??_R4GenderButtonControlPane@@6B@`, primary `0x0061db90`, secondary `0x0061dbf8`, tertiary `0x0061dc28`; key targets include `0x00502700-0x00502755`, `0x005006d0-0x005006ff`, `0x00500700-0x00500797`, `0x005024a0-0x005024ab`, and `0x005024ab-0x005024b6`.
  - `0x0061dc30 -> ??_R4DirectionButtonControlPane@@6B@`, primary `0x0061dc34`, secondary `0x0061dc9c`, tertiary `0x0061dccc`; key targets include `0x005026a0-0x005026f5`, `0x005007f0-0x0050081e`, `0x00500820-0x005008b9`, `0x0050248a-0x00502495`, and `0x00502495-0x005024a0`.
  - `0x0062e998 -> ??_R4CheckBoxTextControlPane@@6B@`, primary `0x0062e99c`, secondary `0x0062ea04`, tertiary `0x0062ea34`; key targets include `0x0059f050-0x0059f0a5`, `0x0059df50-0x0059e0ac`, `0x0059efeb-0x0059eff6`, and `0x0059eff6-0x0059f001`.
  - Primary vptr-store refs still tie gender/direction tables to inline `NewUserMiscDialogPane` setup/reset sites and checkbox text tables to user-list/party-search setup plus destructor reset sites; this supports source-declared/generated-binary vtable reconstruction while leaving raw constructor starts provisional.
- 2026-06-20 B002 local PE recheck confirms the Gender vtable-store pattern without live MCP: `0x0061db90`, `0x0061dbf8`, and `0x0061dc28` each have four immediate-store sites from two `NewUserMiscDialogPane` inline setup blocks, the raw `0x00500640` constructor-shaped body, and the `0x00502700` destructor reset path. This reinforces generated-binary vtable handling and does not promote raw constructor bytes to a proven live source call route.
- 2026-06-20 B004 local PE recheck confirms the Direction vtable-store pattern without live MCP: `0x0061dc34`, `0x0061dc9c`, and `0x0061dccc` each have four immediate-store sites from two `NewUserMiscDialogPane` inline setup blocks, the raw `0x005007a0` constructor-shaped body, and the `0x005026a0` destructor reset path. The same scan found vtable-only refs for `0x005007f0` at `0x0061dc7c` and `0x00500820` at `0x0061dc78`, and destructor thunk branches at `0x00502490`/`0x0050249b`. This reinforces generated-binary vtable handling and does not promote raw constructor bytes or adjustor thunks to handwritten source.
- 2026-08-01 B005 read-only MCP reanalysis resolved the retained Gender constructor/getter/setter copies through exact live inlined consumers and completed the five-child source map. This changes no physical vtable facts; it closes the former raw-constructor caveat and confirms that one normal class declaration regenerates all three views.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | Exact table heads/boundaries, all three `25/11/2` spans, RTTI bases/PMDs, complete Direction and CheckBox slot maps, source children, store/reset xrefs, owner routes, and compiler-only no-emitter handling are complete. |
| Confidence | 96 | Direct bytes, RTTI, slot targets, and stores establish the compiler layouts. Human class source is independently routed through UID00005P, UID00003X, and UID000022; only stripped lexical slot names remain inferred. |

## Reconstruction Notes

The adjustor thunks are compiler-generated and are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). Final source models normal class inheritance and virtual overrides, not handwritten vtable arrays, COLs, scalar-deleting flags, or adjustor functions. This aggregate is therefore `RECONSTRUCTABLE:FALSE` with blank formal code and no emitter; [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md) carries the Gender declaration once.

## Cross-References

- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md)
- [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)
- [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md)
- [UID:00036W][0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor](by-memory/0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor.md)
- [UID:00036X][0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor](by-memory/0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md)
- [UID:0001KJ][0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap](by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md)
- [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md)
- [UID:0002OW][0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData](by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md)
- [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md)

## Changes

- 2026-08-17 B001 UID0002OX accepted implementation callback: retained `94/96` false/non-emitting metadata and replaced the stale CheckBox `+0x68` pseudo-slot/control-type wording with the exact 25/11/2 tables, RTTI/PMD inheritance, all 18 table-head stores, complete source-child map, and terminal shared `HitTestPart(int,int)`. UID0002OX, UID0003FJ, and adjustor data remain compiler output; UID000022 and exact method children carry human source.

- 2026-08-05 B004 UID0002OW accepted callback: corrected the Direction primary endpoint and rejected the stale `+0x68` pseudo-slot, added the complete `25/11/2` slot map, eight-base RTTI/PMDs, exact source children, and one-base/no-handwritten-table disposition while retaining `94/96` false/non-emitting metadata.
- 2026-08-01 B005 UID0002OV accepted callback: raised to `94/96`, changed the vtable aggregate to false/non-emitting, added the exact Gender slot spans, eight-base RTTI/PMDs and five physical source children, and resolved the retained-constructor caveat while preserving all Direction and CheckBox evidence.

- What existed before: this page documented the specialized button/control-pane vtable addresses but remained scored as unevaluated and did not link exact by-memory child ranges for the concrete vtable-data clusters.
- What it was changed to: the page now marks the vtable set reconstructable, raises scores to reflect IDA-verified vtable/range evidence below the final-audit threshold, and links the exact `GenderButtonControlPane`, `DirectionButtonControlPane`, and `CheckBoxTextControlPane` child pages.
- Summary and evidence: 2026-06-01 IDA MCP `py_eval` verified the slot dwords, constructor/store xrefs, and neighboring RTTI-adjacent boundaries for all three child ranges.
- 2026-06-11 A007 Batch 161: Raised completion from `84` to `85` and assigned parent [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) after the file parent cleared `85/85` and the exact gender/direction destructor child pages confirmed the vtable slot targets under current IDA evidence.
- 2026-06-11 A005 Batch 174: Raised from `85/90` to `86/91` after live IDA MCP reconfirmed all three RTTI locator dwords, primary/secondary/tertiary table heads, key slot target ranges, primary store/reset xrefs, and the existing direct file parent gate. Final inherited slot names and raw constructor declarations remain below final-source quality.
- 2026-06-20 B002 Rule 26 incorporation: added PE immediate-store confirmation for the three Gender vtable bases and preserved the rule that vtable data is regenerated from final source declarations, not hand-authored.
- 2026-06-20 B004 Rule 26 incorporation: added PE immediate-store confirmation for the three Direction vtable bases, vtable-only state/paint references, and destructor adjustor-thunk branch evidence while preserving the rule that vtable data and thunks are regenerated from final source declarations, not hand-authored.
