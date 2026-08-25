*** UID:0004W1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007S | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapRefreshDimmer Vtables

## Status

- Disposition: non-emitting source-declared/generated-binary ABI authority.
- Source owner: [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md).
- Physical backing: [UID:0002SR][0x0061e854-0x0061e8dc.MapRefreshDimmerVtableData](by-memory/0x0061e854-0x0061e8dc.MapRefreshDimmerVtableData.md).
- Source route: private MapRefreshDimmer class in [UID:0000L3][MapPane](by-file/MapPane.md).
- No handwritten table, RTTI object, adjustor, or deleting wrapper is emitted from this page.

## Exact Physical Views

| View | COL-inclusive range | Object offset | Slots | Constructor stores |
| --- | --- | ---: | ---: | --- |
| complete object | `0x0061e854-0x0061e8a0` | `0` | 18 | `0x00506fcf`, `0x0051496e` |
| EventHandler facet | `0x0061e8a0-0x0061e8d0` | `+0xa0` | 11 | `0x00506fd5`, `0x00514974` |
| TimerHandler facet | `0x0061e8d0-0x0061e8dc` | `+0xa4` | 2 | `0x00506fdf`, `0x0051497e` |

## Primary Slot Map

| Slot | Target | Source role |
| ---: | --- | --- |
| 0 | `0x00514e20` | compiler scalar deleting destructor for implicit derived destructor |
| 1 | `0x004f4b10` | inherited `LObject::GetRuntimeClass` |
| 2 | `0x0041b6c0` | inherited `LObject::OnChangeMessage` default |
| 3 | `0x004b8e20` | inherited `GrafPort::UpdateRenderRegion` |
| 4 | `0x0041d680` | inherited `Pane::DrawOnTarget` no-op |
| 5 | `0x00544730` | inherited `Pane::Show` |
| 6 | `0x00544750` | inherited `Pane::Hide` |
| 7 | `0x005447a0` | inherited `Pane::GetParentPane` |
| 8 | `0x00544800` | inherited `Pane::InvalidateRect` |
| 9 | `0x00544a20` | inherited `Pane::GetDescription` |
| 10 | `0x00544b80` | inherited `Pane::GetScreenBounds` |
| 11 | `0x00544bd0` | inherited `Pane::SetBounds` |
| 12 | `0x00544c70` | inherited `Pane::AddToLayer` |
| 13 | `0x00544cb0` | inherited `Pane::InsertInLayer` |
| 14 | `0x00544ce0` | inherited `Pane::RemoveFromLayer` |
| 15 | `0x00544d30` | inherited `Pane::SetPaneOrder` |
| 16 | `0x00544d70` | inherited `Pane::UnregisterEventHandler` |
| 17 | `0x00559dd0` | inherited `ScreenDimmer::OnPaint` |

## EventHandler Facet Slot Map

| Slot | Target | Source role |
| ---: | --- | --- |
| 0 | `0x00514d34` | compiler deleting-destructor adjustor from `+0xa0` |
| 1 | `0x004b0ba0` | inherited/folded true pointer-mouse handler |
| 2 | `0x004b0ba0` | inherited/folded true key-text handler |
| 3 | `0x00544dd0` | inherited Pane IME default |
| 4 | `0x005149a0` | [UID:0004VZ][0x005149a0-0x005149e2.MapRefreshDimmerHandlePacketEvent](by-memory/0x005149a0-0x005149e2.MapRefreshDimmerHandlePacketEvent.md) |
| 5 | `0x00544df0` | inherited Pane system/control default |
| 6 | `0x00544e00` | inherited Pane type-19 default |
| 7 | `0x004a89f0` | inherited `EventHandler::ForwardHandlerOrder` |
| 8 | `0x00544e10` | inherited `EventHandler::GetLocalEventPair` |
| 9 | `0x00544e30` | inherited `EventHandler::GetScreenEventPair` |
| 10 | `0x00544e70` | inherited `EventHandler::ShouldAcceptEvent` |

## TimerHandler Facet Slot Map

| Slot | Target | Source role |
| ---: | --- | --- |
| 0 | `0x00514d3f` | compiler deleting-destructor adjustor from `+0xa4` |
| 1 | `0x005149f0` | [UID:0004W0][0x005149f0-0x00514a0d.MapRefreshDimmerOnTimer](by-memory/0x005149f0-0x00514a0d.MapRefreshDimmerOnTimer.md) |

## RTTI And Inheritance

- Complete object locator addresses are `0x0064b3fc`, `0x0064b4fc`, and `0x0064b510` with offsets `0`, `0xa0`, and `0xa4`.
- Type descriptor is `0x00677824`, decorated class identity `.?AVMapRefreshDimmer@@`; hierarchy descriptor is `0x0064b410`.
- Eight hierarchy entries are MapRefreshDimmer, ScreenDimmer, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<ScreenDimmer>`.
- The only direct source base is ScreenDimmer. EventHandler and TimerHandler are inherited Pane facets; `Singleton<ScreenDimmer>` is inherited through ScreenDimmer.

## Source Regeneration Route

- [UID:0004VY][0x00514920-0x0051499b.MapRefreshDimmerConstructor](by-memory/0x00514920-0x0051499b.MapRefreshDimmerConstructor.md) proves all three vptr stores and the no-extra-field layout.
- UID0004VZ and UID0004W0 supply the only class-specific virtual overrides.
- ScreenDimmer supplies the inherited primary `OnPaint` and folded/default EventHandler behavior.
- The implicit virtual derived destructor generates UID0003M5/UID0003M6 compiler glue and all three deleting-destructor slots.

## Boundaries And Negative Evidence

- Exact backing SHA256 is `9C9A227E6455A26423A69BD4AF863D181462CA101455E3E091C0CCB70475BAFC` over 136 bytes.
- [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md) ends exactly at the first COL.
- [UID:0002SS][0x0061e8dc-0x0061e8fc.DialogCreatorVtableData](by-memory/0x0061e8dc-0x0061e8fc.DialogCreatorVtableData.md) starts exactly after the timer slot.
- COL dwords have no ordinary xrefs; constructor stores are the direct liveness evidence.
- No source evidence supports raw vtable arrays, explicit vptr fields, explicit EventHandler/TimerHandler bases, or extra class data.

## Historical And Rejected Alternatives

- Historical docs treated all three tables as reconstructable emitter content. Current source/ABI policy and exact class closure supersede that metadata.
- A standalone MapRefreshDimmer.cpp route is rejected by zero out-of-line constructor callers and complete MapPane-side construction/completion inlining.
- Shared `0x004b0ba0` entries are inherited compiler-folded behavior documented by UID000342, not two authored MapRefreshDimmer methods.
