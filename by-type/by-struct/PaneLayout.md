*** UID:0001VH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000A2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000A2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Pane Layout

## UID000090 Exact Complete Pane Tail - 2026-07-31

- Complete bases end at `+0xa8`: `GrafPort +0x000/0xa0`, EventHandler facet `+0xa0/4`, TimerHandler facet `+0xa4/4`. Pane is exactly `0xf8` bytes and is a concrete class.
- Exact Pane-owned tail: `Layer *m_layer +0xa8`; `Point m_origin +0xac`; `bool m_visible +0xb4`; `unsigned char m_mode +0xb5`; natural alignment `+0xb6..+0xb7`; `Pane *m_redrawPeerPane +0xb8`; `unsigned int m_redrawState +0xbc`; `bool m_redrawPending +0xc0`; natural alignment `+0xc1..+0xc3`; `Region m_pendingMotionRegion +0xc4/0x14`; `bool m_inMotionPaint +0xd8`; natural alignment `+0xd9..+0xdb`; `Region m_motionRegion +0xdc/0x14`; `unsigned int m_inputRegistrationState +0xf0`; `bool m_pendingDelete +0xf4`; `bool m_hasPendingMotionRegion +0xf5`; `bool m_drawOnTarget +0xf6`; natural tail alignment `+0xf7`.
- `m_visibleBounds` is inherited from GrafPort at `+0x38`; the historical Pane-local `m_bounds` field is rejected because it shifts every proven Pane tail access and breaks the `0xf8` derived-class boundary.
- Names at `+0xb8/+0xbc/+0xc0` remain high-probability descriptive spellings, but pointer/word/byte width, behavior, and offsets are fixed by the complete Pane method family. This lexical uncertainty does not justify an incomplete declaration.

## Status

- Entity kind: class layout / UI base object state.
- Covered class: [UID:0000A2][Pane](by-class/Pane.md).
- Likely owner header/source: [UID:0000MC][Pane](by-file/Pane.md).
- Confidence: strong for listed offsets and derived boundary; medium for final names of several flags/region roles.
- Owner/emitter route: attached to [UID:0000A2][Pane](by-class/Pane.md), which emits through [UID:0000MC][Pane](by-file/Pane.md). The class/file route clears the strict gate; final C++ remains blank because several region/flag names and complete downstream use-site audits remain provisional.
- Verification basis: IDA MCP `lookup_funcs` and decompilation rechecked representative constructor, destructor, visibility, deletion, layer, and motion-region methods on 2026-05-31. Generated Wave3/simroot data is not used as authority for this score.

## Observed Layout

`Pane` is the common UI base over [UID:00005V][GrafPort](by-class/GrafPort.md). It keeps the primary `GrafPort`/pane view at object start, installs event/timer handler views at `+0xa0` and `+0xa4`, and adds layer, visibility, motion/clip, deletion, and focus state. Derived classes such as [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) and [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) begin their own fields at `+0xf8`.

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `+0x00` | primary `GrafPort`/`Pane` vptr, `0x006219e8` | `GrafPort` constructor writes the base table, then `Pane::Pane` installs the `Pane` primary vtable. |
| `+0x04` | inherited `GrafPort` active/current region state | `GrafPort` constructs a region here; motion helpers copy from or into this region. |
| `+0x18` | inherited `GrafPort` primary surface pointer | `GrafPort` constructor/destructor initialize and release this field. |
| `+0x1c` | inherited `GrafPort` tile/context state | `GrafPort` constructor initializes this context and destructor tears it down. |
| `+0x2c` | inherited `GrafPort` rectangle/state block | `GrafPort` initializes this rectangle; final role belongs to [UID:00005V][GrafPort](by-class/GrafPort.md). |
| `+0x44` | inherited `GrafPort::m_visibleBounds` | `Show`, `InvalidateRect`, and `SetBounds` use this 16-byte visible/local bounds rectangle. [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md) copies it to a caller output pointer and returns that pointer; direct BackPane and HitBarObjectPane receivers prove the accessor is inherited GrafPort state rather than a BackPane-only field. |
| `+0x54` | inherited `GrafPort` exposed/dirty region | `GrafPort` constructs a region here; GrafPort update/draw paths use it. |
| `+0x68` | inherited `GrafPort` point/draw-state area | `GrafPort` initializes a point here; draw-state fields continue through this block. |
| `+0xa0` | event-handler secondary vptr, `0x00621a34` | Constructor calls `EventHandler` constructor here, then stores the `Pane` secondary table. Dispatcher helpers pass `this + 0xa0`. |
| `+0xa4` | timer/event tertiary vptr, `0x00621a64` | Constructor calls timer handler constructor here, then stores the `Pane` tertiary table. |
| `+0xa8` | attached `Layer*` | Constructor initializes zero; add/insert/remove helpers read and write the cached layer pointer. |
| `+0xac/+0xb0` | `Point m_origin`: `m_origin.y` then `m_origin.x` | Constructor initializes `(0,0)`. `Point` is formally reconstructed as `int y; int x;`, and `InitPointPair(Point *, int y, int x)` stores top/Y at `+0xac` and left/X at `+0xb0`. Pane base `SetBounds`, ObjectPane UID0003XX, LoginDialog drag handling, IMEComposition release handling, MapPane coordinate layout, FittingRoom UID0002DG, and FlyingParcel owner-normalized accesses independently prove this order. |
| `+0xb4` | visible byte | Constructor initializes `1`; `Show` sets `1`, `Hide` sets `0`. |
| `+0xb5` | pane mode byte / `m_mode` | Constructor stores the incoming mode; `Show` skips redraw when mode is `4`; [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) updates it only on change and dispatches `Pane::InvalidateRect` through primary vtable slot `+0x20` with local bounds `+0x44`. Best enum direction is `PaneMode`/`PaneDrawMode`; final constant names remain provisional. |
| `+0xb8` | auxiliary peer/redraw pane pointer, high-probability `Pane*` | Constructor initializes zero; `Hide` checks this field and transfers bounds/redraw context when present. Rejected alternatives: attached layer (`+0xa8`), inline Region (`+0xc4/+0xdc`), and visibility/mode (`+0xb4/+0xb5`). Final source name remains descriptive, likely `m_peerPane` / `m_redrawPeerPane`. |
| `+0xc0` | auxiliary peer/redraw state byte | Constructor initializes zero near the `+0xb8` peer pointer. No documented consumer proves a final name; document as auxiliary state tied to the peer/redraw path rather than as an unknown compiler artifact. Rejected alternatives: delete marker (`+0xf4`), mode (`+0xb5`), and visible flag (`+0xb4`). |
| `+0xc4` | pending/alternate motion region | Constructor initializes and empties this region; motion helpers compare/copy/subtract it. |
| `+0xd8` | in-paint/motion-lock byte | `BeginMotionPaint` sets it to `1`; `EndMotionPaint` clears it. |
| `+0xdc` | pane clip/committed motion region | Constructor initializes and empties this region; `BeginMotionPaint` copies it into active region state. |
| `+0xf0` | input/focus registration state dword | Destructor paths test this against `1` before focus cleanup through the global manager. |
| `+0xf4` | dismissed/deferred-delete marker | Constructor initializes zero; `MarkForDeletion` sets it before queueing through the pane manager/deferred deletion path. |
| `+0xf5` | pending-motion selector flag, likely `m_hasPendingMotionRegion` | `GetCurrentMotionRegion` and `HasPendingMotion` choose current versus pending region behavior from this byte. This is a better source-facing direction than generic `pane flags`. |
| `+0xf6` | inherited direct-target paint-mode bool, preferred source name `m_drawOnTarget` | `Pane::Pane` clears it as part of the word store spanning `+0xf5/+0xf6`. Rain, Snow, and Swallow constructors are the only bounded byte-store matches and set it to `1`; `Layer_UpdateDirtyRegionsRecursive` at `0x004f16b2` is the only bounded byte-read/compare match and dispatches primary virtual `OnPaint` only when the byte is zero. This is distinct from visibility at `+0xb4`. |
| `+0xf8` | first derived-class field | `DialogPane` title starts here; `DialogSession` tracked-list pointer starts here. |

## IDA Evidence

Checked on 2026-05-26 and representative methods rechecked through IDA MCP on 2026-05-31:

- `Pane::Pane` at `0x00544460` calls `GrafPort::GrafPort`, constructs handler subobjects at `+0xa0` and `+0xa4`, installs the three `Pane` vtables, constructs regions at `+0xc4` and `+0xdc`, initializes layer/origin/visible/mode state, clears delete/input flags, and returns `this`.
- `Pane` non-deleting destructor at `0x00544580` and scalar deleting destructor at `0x00544f50` reinstall the three `Pane` vtables, clear active dispatcher/layer state through `+0xa0` and `+0xa8`, destroy the regions at `+0xdc` and `+0xc4`, tear down the handler subobjects, and call `GrafPort` teardown.
- `MarkForDeletion` at `0x00544690` reads/writes byte `+0xf4`.
- `Show` and `Hide` at `0x00544730` and `0x00544750` write visible byte `+0xb4`; `Show` also checks mode byte `+0xb5`.
- `PaneSetMode` at `0x005446b0-0x005446d4` compares and writes mode byte `+0xb5`, then calls `Pane::InvalidateRect` through primary vtable slot `+0x20`, `0x00621a08 -> 0x00544800`, with local bounds `this + 0x44` when the mode changed; this was resolved by B002 on 2026-06-17.
- `GetCurrentMotionRegion`, `HasPendingMotion`, `BeginMotionPaint`, and `EndMotionPaint` at `0x005446e0`, `0x00544a40`, `0x00544ae0`, and `0x00544b50` use `+0xc4`, `+0xd8`, `+0xdc`, and `+0xf5` for motion/dirty state.
- `AddToLayer`, `InsertInLayer`, and `RemoveFromLayer` at `0x00544c70`, `0x00544cb0`, and `0x00544ce0` read and write the cached layer pointer at `+0xa8`.
- `IsAttachedToLayer` / layer-membership test at `0x00544c50` reads the cached layer pointer at `+0xa8` and asks whether that layer contains the current pane.
- `GetScreenBounds` at `0x00544b80` obtains the pane's screen offset through the EventHandler view, copies inherited `GrafPort::m_visibleBounds`, and offsets the output into screen coordinates.
- Base `SetBounds` at `0x00544bd0` constructs a local `Point` from incoming top/Y and left/X, copies it into `m_origin` in the same Y/X order, localizes a stack rectangle by negative X/Y, and dispatches primary slot `+0x0c` / `UpdateRenderRegion`.
- [UID:0003XW][0x00537740-0x00537751.ObjectPaneSetBounds](by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md) is the ObjectPane `UpdateRenderRegion` override and assigns inherited `m_visibleBounds`; [UID:0003XX][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md) is the ObjectPane `SetBounds` override and directly updates `m_origin`/`m_visibleBounds` before object-data propagation.
- `SetPaneOrder` and `UnregisterEventHandler` at `0x00544d30` and `0x00544d70` pass `this + 0xa0` to `EventDispatcher`.
- 2026-06-14 live IDA MCP reconfirmed the current modeled sizes: constructor `0x00544460` size `0x118`, ordinary destructor `0x00544580` size `0x107`, mark-for-delete `0x00544690` size `0x1d`, mode setter `0x005446b0` size `0x24`, current-motion helper `0x005446e0` size `0x26`, show/hide `0x00544730/0x00544750` sizes `0x1a/0x4c`, pending-motion and paint-region helpers `0x00544a40/0x00544ae0/0x00544b50` sizes `0x9e/0x66/0x2d`, layer helpers `0x00544c50/0x00544c70/0x00544cb0/0x00544ce0` sizes `0x16/0x34/0x27/0x4a`, dispatcher helpers `0x00544d30/0x00544d70` sizes `0x3f/0x3e`, and scalar deleting destructor `0x00544f50` size `0x136`.
- Current constructor decompilation writes the three Pane vtables at `+0x00`, `+0xa0`, and `+0xa4`, constructs handler subobjects at `+0xa0/+0xa4`, constructs regions at `+0xc4/+0xdc`, clears delete/input flags, sets visible byte `+0xb4` to `1`, stores the incoming mode byte at `+0xb5`, clears the layer pointer at `+0xa8`, and zeros the derived-boundary-adjacent flags at `+0xf4/+0xf5/+0xf6`.
- Current destructor and scalar deleting destructor decompilation both reinstall the three vtables, test input/focus dword `+0xf0`, clear active event/layer state through `+0xa0/+0xa8`, destroy regions at `+0xdc/+0xc4`, tear down handler subobjects, and call `GrafPort` teardown.
- Current visibility/mode/deletion decompilation directly proves `+0xf4` as the deferred-delete byte, `+0xb5` as the mode byte that dispatches primary vtable slot `+0x20` with `this + 0x44`, and `+0xb4` as the visible byte toggled by `Show`/`Hide`.
- Current motion/region decompilation directly proves `+0xc4` as the pending/alternate motion region, `+0xd8` as the in-motion-paint byte, `+0xdc` as the committed clip/motion region, and `+0xf5` as the byte selecting current versus pending region behavior. Layer helper decompilation continues to prove `+0xa8` as the cached `Layer*`.
- UID0003PI cross-function closure proves `+0xf6` independently from neighboring motion state. The Pane constructor word-clear at `0x0054454f` establishes the zero default; `RainingLayerPane` at `0x005c144e`, `SnowingLayerPane` at `0x005c1c63`, and `SwallowLayerPane` at `0x005c2327` are the only bounded byte-store matches and set the byte to one.
- The unique bounded byte compare at `0x004f16b2` belongs to `Layer_UpdateDirtyRegionsRecursive`. Zero continues to primary vtable slot `+0x44`; nonzero bypasses that generic `OnPaint` dispatch. Rain primary vtable cell `0x00631264 -> 0x005c1460` proves the slot identity, while the concrete weather classes retain their separate direct-target rendering methods.
- Rejected `+0xf6` interpretations are now explicit: it is not visibility because `+0xb4` is toggled by `Show`/`Hide`; not padding/reserved because exact constructors write it and Layer reads it; not initialization/readiness because the only consumer gates painting; and not a Rain-added field because it lies inside the `0xf8`-byte Pane prefix.
- 2026-06-17 B001 source-quality reanalysis for [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md) provides an additional derived-object validation of offset `+0xa0`: the input-handler vtable entries receive the secondary EventHandler view and subtract `0xa0` before calling `LogoPlayerPane::AdvanceToNextSegment`.

## Reconstruction Notes

- Model `Pane` as a concrete base class of size `0xf8` before derived state starts. This matches `DialogPane +0xf8` title storage and `DialogSession +0xf8` session-stack storage.
- Keep `GrafPort` declaration details in [UID:0000JR][GrafPort](by-file/GrafPort.md). This page records the direct object offsets visible through pane behavior, not the full rendering-port declaration.
- Keep the `+0xa0` and `+0xa4` handler views as real embedded subobjects/interfaces. Their destructor adjustor thunks are compiler ABI glue and should not become handwritten methods.
- Current generated `class_Pane.cpp` still has source-quality issues such as synthetic overlays and `ConnStatusPane` names on generic pane state wrappers; use IDA layout evidence for final source declarations.
- Historical 2026-06-18 B002 PaneCore source-quality execution grouped `+0xf6` with motion/reserved directions because no consumer had then been documented. UID0003PI later resolved its exact writer/reader family and direct-target paint behavior; only the lexical spelling remains inferred. `m_drawOnTarget` is the preferred positive human name and `m_usesDirectTargetDrawing` is a descriptive alias, while negative implementation spelling such as `m_skipOnPaint` is rejected.
- 2026-07-15 B002 UID0003TC integration resolves `+0x44` as inherited `GrafPort::m_visibleBounds` and UID000161 as `GrafPort::GetBounds`. Historical `Pane::m_bounds`/`m_localBounds` and BackPane-specific accessor wording remain provenance only; the direct HitBar receiver, GrafPort field/island, and broad caller family reject them as current owner/member names. Score and broad blank formal remain unchanged because unrelated Pane flags/regions still cap the full layout declaration.
- 2026-07-16 B005 UID0003XX integration resolves the source-facing origin expression as `Point m_origin` with Y at `+0xac` and X at `+0xb0`. Historical FlyingParcel `m_origin.x` at owner `+0xac` and the swapped FittingRoom point/offset order are superseded. The correction adds no field, padding, accessor, or broad class formal and does not change the `85/88` layout score.

## Cross-References

- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md)
- [UID:0003JA][PaneVtables](by-type/by-vtable/PaneVtables.md) Pane vtable source-local type page
- [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md)
- [UID:0001EB][0x00544f2e-0x00544f44.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f44.PaneAdjustorThunks.md)
- [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md)
- [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:0001V9][ModelessDialogPaneLayout](by-type/by-struct/ModelessDialogPaneLayout.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Score Rationale

Completion remains `85` and confidence remains `88`. Constructor/destructor lifecycle, three vtable views, handler subobjects, visibility/mode/delete/layer fields, region fields, dispatcher helpers, derived boundary, and the exact `+0xf6` direct-target paint behavior are documented with current IDA evidence. The newly closed `+0xf6` role does not raise the broad layout score because unrelated peer/redraw and region source names plus the complete Pane declaration remain provisional.

## Changes

- 2026-07-24 Agent-B003 UID0003PI support sync:
  - Replaced the historical no-consumer/reserved interpretation of `+0xf6` with the exact Pane default, Rain/Snow/Swallow writer set, unique Layer reader, and zero/nonzero `OnPaint` dispatch behavior.
  - Selected inherited bool `m_drawOnTarget` as the preferred positive source name, preserved `m_usesDirectTargetDrawing` as a descriptive alias, rejected visibility/padding/readiness/negative-skip alternatives, and kept `85/88` because unrelated broad-layout names remain provisional.
- 2026-07-16 Agent-B005 UID0003XX accepted callback:
  - Preserved `85/88`, owner/emitter UID0000A2, reconstructable true, blank position/formal, complete inherited GrafPort/handler/layer/region/flag layout, and all unrelated history.
  - Refined `+0xac/+0xb0` to exact `Point m_origin.y/m_origin.x` order and added Pane/ObjectPane/LoginDialog/IMEComposition/MapPane/FittingRoom/FlyingParcel parity evidence.
  - Added bounded `GetScreenBounds`, base `SetBounds`, and `UpdateRenderRegion` source-boundary evidence while preserving `+0x44` as `GrafPort::m_visibleBounds`.
- 2026-06-17 B002 `PaneSetMode` support sync: updated `+0xb5` from a generic pane mode byte with unresolved callback side effect to `m_mode`/`PaneMode` direction with the resolved `Pane::InvalidateRect` dispatch through primary slot `+0x20`. No score change; final mode enum constant names remain provisional.
- Historical 2026-06-18 B003 `BackPane::GetBounds` support sync: correctly recorded the exact inherited-bounds copy at `+0x44`; its BackPane owner and `m_bounds`/`m_localBounds` spelling are superseded by the current GrafPort evidence. No score change.

- 2026-06-14 A002 score pass: raised from `82/86` to `85/88` after live IDA MCP reconfirmed the constructor/destructor sizes, vtable store triads, exact byte offsets for visible/mode/delete/motion flags, region copies at `+0xc4/+0xdc`, cached layer pointer at `+0xa8`, dispatcher helper offsets, and the source-local `PaneVtables` relationship. Reconstruction C++ remains blank because final flag/region names and downstream audits are not source-quality.
- 2026-06-17 B001 LogoPlayerPane input support sync: changed support wording without changing score. [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md) confirms the `+0xa0` EventHandler secondary-view adjustment in a derived `LogoPlayerPane` event override.
- 2026-06-06: Attached the base pane layout to [UID:0000A2][Pane](by-class/Pane.md). Scores remain `82/86`; this is a parent metadata sync for the already documented base layout.
- Before: validator metadata was unevaluated at completion `0`, confidence `0`, and reconstructable blank despite existing detailed offset documentation.
- Changed to: `RECONSTRUCTABLE:TRUE`, completion `82`, confidence `86`.
- Evidence: IDA MCP verified `Pane::Pane` at `0x00544460`, non-deleting destructor `0x00544580`, scalar deleting destructor `0x00544f50`, deletion marker `0x00544690`, visibility methods `0x00544730`/`0x00544750`, motion-region helpers `0x00544a40`/`0x00544ae0`/`0x00544b50`, and layer membership helpers `0x00544c70`/`0x00544cb0`/`0x00544ce0`. Scores stay below `95+` because final source names for several flags/regions and complete downstream use-site audits remain unresolved.
