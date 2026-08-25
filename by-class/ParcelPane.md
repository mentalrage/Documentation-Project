*** UID:0000A6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FlyingParcelPane;
struct PaneKeyEvent;
struct PaneMouseEvent;

typedef unsigned char ParcelButtonState;

enum ParcelButtonStateValue
{
    kParcelButtonIdle = 0,
    kParcelButtonHover = 1,
    kParcelButtonPressed = 2,
    kParcelButtonAnimating = 3
};

class ParcelPane;
extern ParcelPane *g_pParcelPane;

class ParcelPane : public Pane,
                   public Singleton<ParcelPane>
{
public:
    ParcelPane();
    virtual ~ParcelPane();

    void SetParcelSlotData(unsigned char totalCount,
                           unsigned char leftCount,
                           unsigned char rightCount);

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool OnKeyDown(const PaneKeyEvent *event);
    virtual bool OnTimer(int timerId, int userData1, int userData2);
    virtual void OnPaint();
    virtual void AdvanceButtonAnimation(ParcelButtonState *state,
                                        signed char *frame,
                                        bool rightSide);
    virtual int ResolveButtonFrameIndex(const ParcelButtonState *state,
                                        unsigned char slotCount,
                                        bool rightSide) const;

private:
    friend class FlyingParcelPane;

    void FinishFlyingParcelAnimation(unsigned char totalCount,
                                     unsigned char leftCount,
                                     unsigned char rightCount)
    {
        SetParcelSlotData(totalCount, leftCount, rightCount);
        m_rightSlotActionEnabled = true;
        InvalidateRect(&m_bounds);
    }

    unsigned char m_totalParcelCount;
    unsigned char m_leftParcelCount;
    unsigned char m_rightParcelCount;
    bool m_rightSlotActionEnabled;
    ParcelButtonState m_leftButtonState;
    ParcelButtonState m_rightButtonState;
    signed char m_leftAnimationFrame;
    signed char m_rightAnimationFrame;
    RectBounds m_leftButtonRect;
    RectBounds m_rightButtonRect;
    bool m_leftSlotAcknowledged;
    bool m_rightSlotAcknowledged;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ParcelPane

## B001 UID0002ZO Accepted Callback - 2026-07-21

### Current Declaration And Layout

- The source declaration is complete and emitted at ParcelPane module position 10. It directly derives `Pane` and `Singleton<ParcelPane>`; RTTI PMD `+0xf8, pdisp=-1, vdisp=0`, attribute `0x40`, and the first field at `+0xf8` prove empty-base optimization.
- Exact size is `0x124`. Fields are total/left/right counts at `+0xf8/+0xf9/+0xfa`, right-action enable at `+0xfb`, left/right button states at `+0xfc/+0xfd`, signed animation frames at `+0xfe/+0xff`, button rectangles at `+0x100/+0x110`, and acknowledgement flags at `+0x120/+0x121`. Natural x86 layout supplies the terminal size; no explicit padding member is source-authored.
- `ParcelButtonState` is byte-sized and uses exact observed values idle/hover/pressed/animating `0/1/2/3`.

### Source And Compiler Boundary

- The source family consists of constructor, ordinary destructor, slot setter, key/mouse/timer/paint virtuals, animation helper, and frame resolver. The complete child order is positions 20/30/40/50/60/70/80/90/100.
- `Singleton<ParcelPane>` owns publication and clearing of [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md). Vptr writes, security-cookie code, constructor-unwind clear funclet, base teardown, adjustor thunks, RTTI/vtables, and scalar deleting wrapper are compiler output.
- FlyingParcelPane is a sibling Pane-derived class, so direct access to this class's private/derived state would be source-illegal. The private inline `FinishFlyingParcelAnimation` plus `friend class FlyingParcelPane` reproduces the observed inlined completion sequence without public fields, invented accessors, or ABI helpers.

### Behavior, Evidence, And History

- The declaration preserves exact slot reset, fixed bounds, attachment/order, mouse/key dispatch, 100/200 ms timer behavior, ALERTBTN frame mapping and resources, left packet `0x41`, right BulletinSession path, acknowledgement semantics, and Flying completion flow.
- Prior comment-only class emission, manual singleton assignment/clear, unresolved declaration/private-helper wording, explicit-padding alternatives, PatchPane caller contamination, and broad no-code conclusions are superseded. Historical records remain below as dated evidence.
- No second global definition, public field exposure, standalone Flying helper file, `nullptr`, decompiler labels, explicit vptr/base teardown, or compiler wrapper body is accepted. Complete layout, methods, ownership, and source legality justify `92/94`; unavailable original symbols cap the score below 95.

## Status

- Confidence: strong for parcel notification pane behavior, vtables, layout, singleton ownership, paint/timer/input method boundaries, slot-state enum, button-frame mapping, and source-file placement; medium-high for final timer wrapper spelling and whether helper classes were public or private original declarations.
- Likely source file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Current recovered file: `source-3/simroot_v2/class_ParcelPane.cpp`
- Memory range: [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md), now documented as a non-emitting mixed container/source-family index. Exact ParcelPane child pages carry ParcelPane source decisions.
- Vtable/type evidence: [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- Layout evidence: [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- Known generated-data pollution: ParcelPane metadata/global-data still references [UID:00005F][FpsPane](by-class/FpsPane.md) diagnostics code at `0x004b64a0` and the FPS globals.

## Class Purpose

`ParcelPane` is the small in-game parcel alert pane with two parcel/letter slots. It tracks total/left/right parcel counts, left/right button states, animation frames, slot acknowledgement flags, draws `ALERTBTN` resources, handles keyboard/mouse activation, and stores the active singleton in [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md).

Recommended source-facing button-state enum:

| Value | Name | Evidence |
| ---: | --- | --- |
| `0` | `kParcelButtonIdle` | Constructor and timer reset state to zero. |
| `1` | `kParcelButtonHover` | Mouse hover path writes state `1`. |
| `2` | `kParcelButtonPressed` | Mouse press path writes state `2`; therefore this is not the animation state. |
| `3` | `kParcelButtonAnimating` | Timer helper writes state `3` and frame resolver returns live animation frames. |

`ALERTBTN.EPF` frame map: left empty idle/hover/pressed `0/1/2`, left occupied idle/hover/pressed `3/4/5`, left animation `6..13`, right empty idle/hover/pressed `14/15/16`, right occupied idle/hover/pressed `17/18/19`, and right animation `20..27`.

## Layout Notes

`ParcelPane` starts from the common [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md). Its own state starts at `+0xf8` and the `ParcelIconPane` constructor allocates the child as `0x124` bytes, so generated fields past `+0x124` are not parcel-child state. See [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) for the slot bytes, button rectangles, animation counters, and secondary/tertiary callback offset normalization.

## Method Notes

| Range | Method | Notes |
| --- | --- | --- |
| `0x00546290-0x00546436` | `ParcelPane::ParcelPane` | First-draft C++ is now populated in [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md). It constructs `Pane(1)`, publishes `g_pParcelPane`, initializes accepted parcel count/state/frame/ack fields and button rects, performs `SetParcelSlotData(0,0,0)`, registers `SetPaneOrder(nullptr, g_pBackPane)`, and starts the initial 100 ms timer. Compiler vtable/security/EH output remains non-source. |
| `0x00546440-0x005464ac` | non-deleting destructor | Resets vtables, performs pane cleanup, clears `g_pParcelPane`, and destroys the base pane. Not emitted in active `class_ParcelPane.cpp`. |
| `0x005464b0-0x00546575` | `SetParcelSlotData` | First-draft C++ is now populated in [UID:0002KC][0x005464b0-0x00546575.ParcelPaneSetParcelSlotData](by-memory/0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md). It receives `(totalCount, leftCount, rightCount)`, detaches/repositions the pane, writes `m_totalParcelCount`, `m_leftParcelCount`, and `m_rightParcelCount`, clears changed-slot acknowledgement flags, idles empty-slot button states, reattaches at fixed alert bounds `(630,726,698,751)`, and invalidates `m_bounds`. |
| `0x005465e0-0x0054660a` | `OnKeyDown` | Source-ready [UID:0002KD][0x005465e0-0x0054660a.ParcelPaneOnKeyDown](by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md) at `90/92`: secondary key-down virtual at vtable slot `0x00621c98`; checks event type `8`, calls `g_pEventMan->TranslateEventKey(event->payload[0], event->keyState)`, ignores the returned byte, and always returns false/no-consume. |
| `0x00546610-0x00546807` | `OnMouseEvent` | Source-ready [UID:0002KE][0x00546610-0x00546807.ParcelPaneOnMouseEvent](by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md) at `91/91`: secondary mouse-event callback using `PointInRect`, `Socket::QueueAndSendPacket` through `g_packetSender`, the literal left action byte `0x41`, `g_pBulletinSession`, and `new BulletinSession(1, 0, true)` for right-slot action. |
| `0x00546810-0x00546887` | `OnTimer` / `ProcessSlotAnimations` | Tertiary timer callback; advances slot animation state through primary helper slot `+0x48`, invalidates the pane, and reschedules at 200 ms. |
| `0x00546890-0x0054696f` | `OnPaint` | Primary vtable slot `0x00621c80`; first-draft C++ is now populated in [UID:0002KG][0x00546890-0x0054696f.ParcelPaneOnPaint](by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md). It initializes an `EPFTileContext`, sets draw color `0`, prepares `m_bounds`, resolves accepted left/right count/state fields through `ResolveButtonFrameIndex`, loads `ALERTBTN.EPF`, and renders `m_leftButtonRect` / `m_rightButtonRect` with `ALERTBTN.PAL`. |
| `0x00546970-0x005469da` | `AdvanceButtonAnimation` / `UpdateAnimationCounter` | Protected primary virtual helper that advances state/frame pairs using idle/animating states, negative frame sentinels, and side-specific frame ranges. |
| `0x005469e0-0x00546aaa` | `ResolveButtonFrameIndex` / `GetFrameIndex` | Protected primary virtual helper that maps slot state/count/presence and side to `ALERTBTN` frame numbers. |
| `0x00546e80-0x00546e8b` | constructor/EH singleton-clear cleanup funclet | Non-emitting compiler cleanup target that clears `g_pParcelPane` from parcel-pane construction unwind metadata; source semantics belong to the constructor/destructor/global lifecycle. |
| `0x00546eb7-0x00546ecd` | destructor adjustor thunks | Secondary/tertiary vtable thunks forwarding to `0x00547000`. Compiler-generated; see [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md). |
| `0x00547000-0x005470ad` | MSVC scalar deleting destructor wrapper | Non-emitting compiler ABI glue for the source-declared `ParcelPane` destructor. Primary vtable slot `0x00621c3c` and adjustor thunks at `0x00546eb7` / `0x00546ec2` reach it; the body repeats ordinary cleanup, clears `g_pParcelPane`, tests the delete flag, optionally frees object storage, and stays blank-C++ through [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md). |

## Evidence Notes

- IDA MCP confirms all listed ParcelPane function starts. The separate `0x004b64a0` FPS range is now active under `class_FpsPane.cpp`; IDA still does not mark that address as a function.
- IDA MCP xrefs to `0x0069ba28` include constructor/destructor paths and `FlyingParcelPane::AnimateStep`, matching `g_pParcelPane`.
- `ParcelIconPane` constructor at `0x00545e40` allocates a `ParcelPane` child and initializes the same fields as the standalone constructor, so the pane family should be documented together.
- B007 reclassified [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md) as a non-emitting mixed container and created [UID:00043J][0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper](by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md) for the previously undocumented raw `ParcelIconPane` helper. That child calls `ParcelPane::SetParcelSlotData`, but it writes icon-pane fields and reads the icon-pane child pointer, so it is support evidence for the setter's caller/data flow, not a ParcelPane method or broad class C++ trigger.
- IDA MCP xrefs place the packet/update callback at `0x005461c0` in `ParcelIconPane`'s secondary vtable, not in the `ParcelPane` vtables. It still forwards to `ParcelPane::SetParcelSlotData` through the child pointer.
- IDA MCP vtable dump places `ParcelPane::OnMouseEvent` at secondary slot `+0x04`, `OnKeyDown` at secondary slot `+0x08`, and `ProcessSlotAnimations` at tertiary slot `+0x04`; the tertiary table ends before the `FlyingParcelPane` RTTI at `0x00621cc8`.
- [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) records the exact `ParcelPane` secondary vtable slot `0x00621c98 -> 0x005465e0`, and [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) records the `+0xa0` secondary callback offset normalization used by `OnKeyDown` and `OnMouseEvent`.
- IDA MCP confirms generated `0x00544c50` is the shared `Pane` layer-membership helper and generated `0x005051c0` draws visible tiles from a cached surface at `this + 0x428`; neither belongs to the 0x124-byte `ParcelPane` child.
- `FlyingParcelPane` is tightly coupled through `g_pParcelPane` and parcel delivery animation state.
- B006 reclassified [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) as non-emitting compiler/EH cleanup, not a handwritten `ParcelPane` helper. The exact body clears `dword_69BA28` / `g_pParcelPane`, has no callees or ordinary caller route, has constructor/unwind xrefs at `0x00605be2` / `Unwind@00605bd9` and `0x00605c38` / `Unwind@00605c2f`, and should be regenerated from the constructor/destructor/global lifecycle rather than emitted as class C++.
- 2026-06-26 B002 implementation sync for [UID:0002KE][0x00546610-0x00546807.ParcelPaneOnMouseEvent](by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md) records live MCP session `80de0a67`: `sub_546610` is exact range `0x00546610-0x00546807`, size `0x1f7` / 503 bytes, with only the secondary-vtable data xref `0x00621c94`; the callback uses secondary-this normalization by `+0xa0`, event type `0/1/3` move/press/release behavior, accepted `ParcelButtonState` values, `PointInRect` for owner/slot hit tests, `Socket::QueueAndSendPacket` through `g_packetSender` for left packet byte `0x41`, and `new BulletinSession(1, 0, true)` gated by `g_pBulletinSession` for the right slot. This resolves the OnMouseEvent-specific helper/action source-name blocker while keeping packet-byte and constructor-argument names intentionally literal.
- 2026-06-25 B001 implementation sync for [UID:0002KG][0x00546890-0x0054696f.ParcelPaneOnPaint](by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md) records live IDA MCP session `80de0a67`: `sub_546890` is exact range `0x00546890-0x0054696f`, size `0xdf` / 223 bytes, with no function at `0x0054696f`, one data xref from primary vtable slot `0x00621c80`, no direct code callers, target xrefs to `ALERTBTN.EPF` / `ALERTBTN.PAL`, helper callees through `EPFTileContext::Initialize`, `GrafPort::SetDrawColor`, `SurfaceRenderCallbackTable::PreparePaneRegion`, `g_pEPFLib->LookupLayoutEntry`, and `RenderTileFrame`, and no `ReleaseBuffers` call.
- 2026-06-25 B002 implementation sync for [UID:0002KC][0x005464b0-0x00546575.ParcelPaneSetParcelSlotData](by-memory/0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md) records live IDA MCP session `80de0a67`: `sub_5464B0` is exact range `0x005464b0-0x00546575`, size `0xc5` / 197 bytes, with exactly three code xrefs at `0x005461b0`, `0x00546274`, and `0x00546dcd`. The packet callback proves source arguments `(total,left,right)` from nibble decoding, and `FlyingParcelPane::AnimateStep` proves the completion call as `g_pParcelPane->SetParcelSlotData(m_parcelCountOrState, m_leftSlot, m_rightSlot)`. The body detaches through inherited `Pane::RemoveFromLayer`, writes count bytes `+0xf8/+0xf9/+0xfa`, clears acknowledgement flags `+0x120/+0x121` only on count changes, clears button-state bytes `+0xfc/+0xfd` to idle for empty slots, does not clear animation-frame bytes `+0xfe/+0xff`, builds fixed bounds `(630,726,698,751)`, conditionally attaches via inherited `Pane::AddToLayer` using `g_pBackPane` and MainUiLayerSlots slot `0x0069b368`, and invalidates inherited `m_bounds` through `Pane::InvalidateRect`.
- 2026-06-12 IDA MCP `analyze_component` over the main `ParcelPane` method cluster reconfirms the constructor/destructor/vtable shared globals at `0x00621c3c`, `0x00621c90`, and `0x00621cc0`, with the active method set from constructor through scalar deleting destructor still bounded inside the parcel notification family.
- 2026-06-17 B001 source-quality reanalysis resolves the timer/frame helper field and enum names: `+0xf8` is total parcel count, `+0xf9/+0xfa` are left/right parcel counts, `+0xfb` is the right-slot action enable flag, `+0xfc/+0xfd` are left/right `ParcelButtonState`, `+0xfe/+0xff` are left/right animation frames, `+0x100/+0x110` are button rectangles, and `+0x120/+0x121` are left/right slot acknowledgement flags. It also rejects stale PatchPane caller/source wording for [UID:0002KI][0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex](by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md).
- 2026-06-25 B002 implementation sync for [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md) records live IDA MCP session `80de0a67`: function inventory confirms exact half-open range `0x00546290-0x00546436`, size `0x1a6`, no function at `0x00546436`, six bytes of `0xcc` padding before the destructor at `0x00546440`, and no direct callers. Xrefs confirm the ParcelPane vtable views are stored from the icon-pane constructor, this constructor, destructor, and scalar deleting destructor, and `g_pParcelPane` has constructor publish/unwind-clear writes. The constructor body uses accepted fields (`m_totalParcelCount`, left/right counts, `m_rightSlotActionEnabled`, left/right button states, left/right animation frames, button rects, and slot acknowledgement flags), the inlined zero-slot `SetParcelSlotData(0,0,0)` reset, `SetPaneOrder(nullptr, g_pBackPane)`, and the initial `m_timerHandler.ScheduleTimer(0,100,0,0)` call.
- 2026-06-27 B011 implementation sync for [UID:0002KD][0x005465e0-0x0054660a.ParcelPaneOnKeyDown](by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md) records MCP session `398b87c1`: exact size `0x2a` / 42, exclusive end `0x0054660a`, vtable-only slot `0x00621c98`, EventMan producer offsets `+0x04` key-down type `8`, `+0x08` key byte, and `+0x10a` / 266 modifier/state byte, `dword_67A754` resolved to `g_pEventMan`, `0x004a8b10` resolved to `EventMan::TranslateEventKey`, ignored helper return, and always-false/no-consume behavior.
- 2026-06-28 B008 implementation sync for [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md) records the accepted no-code scalar-deleting-wrapper disposition: MCP session `supervisor_20260628_resume` confirms exact `sub_547000` size `0xad`, half-open end `0x005470ad`, `0xcc` padding before [UID:0000MH][PatchPane](by-file/PatchPane.md) at `0x005470b0`, primary vtable slot `0x00621c3c`, secondary/tertiary adjustor references at `0x00546ebd` and `0x00546ec8`, vtable restores at `0x0054702c/0x00547032/0x0054703c`, `g_pParcelPane` clear at `0x00547054`, and optional delete-flag storage free. Source-level destructor semantics remain with the ordinary destructor/class declaration path; the scalar wrapper has blank formal C++ and no emitter.

## Assignment Gate

`ParcelPane` now clears the strict direct-parent gate for exact child methods at `90/91`. The class page documents the executable method inventory, field layout, vtable slots, singleton ownership, source-file parent [UID:0000MF][ParcelPane](by-file/ParcelPane.md), slot-state enum, frame-map evidence, and populated constructor/source-shape evidence. Exact method children may remain attached to this class when their own pages also clear 85/85. `ParcelPane::ParcelPane`, `SetParcelSlotData`, `OnKeyDown`, `OnMouseEvent`, `OnPaint`, ordinary destructor [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md), timer callback [UID:0002KF][0x00546810-0x00546888.ParcelPaneProcessSlotAnimations](by-memory/0x00546810-0x00546888.ParcelPaneProcessSlotAnimations.md), animation helper [UID:0002KH][0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter](by-memory/0x00546970-0x005469db.ParcelPaneUpdateAnimationCounter.md), and frame resolver [UID:0002KI][0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex](by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md) now have first-draft formal C++ in their exact child pages. This class page itself carries only a comment-only support marker because it is the declaration/layout and method-inventory surface, not a duplicate method-body emitter.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | The complete destination declaration now records both direct bases, exact size and fields, all source methods, child order, private Flying integration, globals, resources, and source/compiler exclusions. No current source-shape blocker remains. |
| Confidence `94` | Live binary, RTTI/PMD, allocation size, vtable slots, every child body, caller/data flow, and exact layout agree. Only unavailable original symbols and exact private spellings prevent a 95+ score. |

## Open Questions

- Closed: stale FPS/global pollution is not ParcelPane state; exact fields are the accepted `+0xf8..+0x121` layout above.
- Closed: the broader class declaration and Flying cross-class access route are now supplied in the managed block. Residual original spelling uncertainty is a confidence cap, not a source/C++ blocker.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md)
- [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md)
- [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md)
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md)
- [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md)
- [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md)
- [UID:00005F][FpsPane](by-class/FpsPane.md)

## Changes

- 2026-06-28 B008 accepted ParcelPaneScalarDeletingDestructor no-code sync:
  - Updated the `0x00547000-0x005470ad` method row and evidence notes to classify [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md) as a non-emitting MSVC scalar deleting destructor wrapper, not class-authored source C++.
  - Evidence: accepted B008 report and MCP session `supervisor_20260628_resume` support exact bounds, vtable/thunk reachability, ordinary-destructor cleanup parity, `g_pParcelPane` clear, delete-flag/free behavior, and PatchPane boundary. Class metadata remains owned by [UID:0000MF][ParcelPane](by-file/ParcelPane.md); only the wrapper child clears its emitter and formal C++.
- 2026-06-26 B002 accepted ParcelPaneOnMouseEvent implementation sync:
  - Recorded that [UID:0002KE][0x00546610-0x00546807.ParcelPaneOnMouseEvent](by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md) now has first-draft formal C++ and is source-ready as `ParcelPane::OnMouseEvent(const PaneMouseEvent& event)` at `91/91`.
  - Evidence: accepted B002 source-quality report and MCP session `80de0a67` support the exact function boundary, secondary vtable slot `0x00621c94`, `+0xa0` secondary-this normalization, event type `0/1/3` behavior, `PointInRect`, left packet byte `0x41` through `g_packetSender->QueueAndSendPacket`, right `new BulletinSession(1, 0, true)` through `g_pBulletinSession`, and accepted acknowledgment field names. Class score remains `88/90` because broader timer/private-declaration caveats remain outside this target.
- 2026-06-26 B007 accepted ParcelNotificationPanes support sync:
  - Clarified that [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md) is a non-emitting mixed container/source-family index and that exact ParcelPane children carry source decisions.
  - Recorded [UID:00043J][0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper](by-memory/0x005460f0-0x005461c0.ParcelIconPaneParcelUpdateRawHelper.md) only as setter caller/data-flow support: it decodes direct payload counts and calls `ParcelPane::SetParcelSlotData` at `0x005461b0`, but its owner is [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), not this class.
  - Then-current C++ policy: broad class C++ stayed blank; exact ParcelPane constructor, setter, and paint children carried accepted formal C++ while timer/input/helper children kept their own blockers. B005 supersedes this by using a comment-only class support marker and populating the destructor, timer, animation-helper, and frame-resolver children.
- 2026-06-27 B011 accepted ParcelPaneOnKeyDown implementation sync:
  - Updated the `OnKeyDown` method row, evidence notes, assignment gate, score rationale, and open-question wording to reflect that [UID:0002KD][0x005465e0-0x0054660a.ParcelPaneOnKeyDown](by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md) now has first-draft formal C++ and source-ready key-event naming.
  - Evidence: accepted B011 source-quality report and MCP session `398b87c1` confirm exact range `0x005465e0-0x0054660a`, size `0x2a` / 42, vtable-only slot `0x00621c98`, EventMan key-down producer offsets `+0x04/+0x08/+0x10a`, `g_pEventMan`, `EventMan::TranslateEventKey`, ignored helper return, and always-false/no-consume behavior. Class score remains `88/90` because broader timer/private-declaration caveats remain outside this target.
- 2026-06-25 B002 accepted ParcelPaneSetParcelSlotData implementation sync:
  - Updated the `SetParcelSlotData` method row, evidence notes, assignment gate, score rationale, and open-question wording to reflect that [UID:0002KC][0x005464b0-0x00546575.ParcelPaneSetParcelSlotData](by-memory/0x005464b0-0x00546575.ParcelPaneSetParcelSlotData.md) now has first-draft formal C++ and exact half-open range `0x005464b0-0x00546575`.
  - Evidence: accepted B002 source-quality report and IDA MCP session `80de0a67` confirm function size `0xc5`, code xrefs at `0x005461b0`, `0x00546274`, and `0x00546dcd`, packet callback argument order `(total,left,right)`, FlyingParcelPane completion argument order `(m_parcelCountOrState,m_leftSlot,m_rightSlot)`, count writes at `+0xf8/+0xf9/+0xfa`, acknowledgement clears at `+0x120/+0x121`, empty-slot button-state idling at `+0xfc/+0xfd`, no animation-frame clear at `+0xfe/+0xff`, fixed alert bounds `(630,726,698,751)`, inherited Pane helper calls, `g_pBackPane`, and the MainUiLayerSlots `0x0069b368` dependency.
- 2026-06-25 B002 accepted ParcelPaneConstructor implementation sync:
  - Updated the constructor method row, evidence notes, assignment gate, score rationale, and open-question wording to reflect that [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md) now has first-draft formal `ParcelPane::ParcelPane()` C++.
  - Evidence: accepted B002 source-quality report and IDA MCP session `80de0a67` confirm exact range `0x00546290-0x00546436`, size `0x1a6`, no successor function at `0x00546436`, six-byte padding before the destructor, no direct callers, vtable-store xrefs from constructor/destructor paths, `g_pParcelPane` publish/unwind-clear writes, accepted field initializers, inlined `SetParcelSlotData(0,0,0)`, `SetPaneOrder(nullptr, g_pBackPane)`, and initial `m_timerHandler.ScheduleTimer(0,100,0,0)`. Vtable stores, security-cookie code, EH cleanup, and [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) remain compiler output rather than class source.
- 2026-06-25 B001 accepted ParcelPaneOnPaint implementation sync:
  - Updated the `OnPaint` method row, direct evidence note, assignment gate, score rationale, and open-question wording to reflect that [UID:0002KG][0x00546890-0x0054696f.ParcelPaneOnPaint](by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md) now has first-draft formal C++.
  - Evidence: accepted B001 source-quality report and IDA MCP session `80de0a67` confirm exact range `0x00546890-0x0054696f`, size `0xdf`, no successor function at `0x0054696f`, vtable slot `0x00621c80`, `ALERTBTN.EPF` / `ALERTBTN.PAL` xrefs, resolved helper/source names, accepted left/right field names, and no `ReleaseBuffers` call.
- 2026-06-18 B006 ParcelPane singleton cleanup support:
  - Replaced the stale `0x00546e80-0x00546e8a` clear-helper method row with the exact `0x00546e80-0x00546e8b` constructor/EH cleanup funclet classification.
  - Evidence: B006 source-quality review confirmed the one-store `g_pParcelPane` clear body, no ordinary source caller, two constructor/unwind xrefs, [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) same-shape sibling precedent, and normal lifecycle coverage through the constructor/destructor/scalar deleting destructor and global pages.
- 2026-05-31: Marked reconstructable and attached to [UID:0000MF][ParcelPane](by-file/ParcelPane.md); remaining core methods now have exact child by-memory pages.
  - Before: class documentation had detailed method/layout evidence but validator autogen metadata was blank.
  - After at that time: `RECONSTRUCTABLE:TRUE` with file parent set; C++ remained blank because input/event names, helper APIs, and final field names were below the then-current final-source threshold. Later child implementations and B005 supersede the blank state.
  - Evidence: IDA MCP function enumeration/decompilation confirmed constructor, slot update, input, timer, paint, animation, frame-index, singleton, and destructor boundaries in the parcel family range.
- Before: completion/confidence metadata were `0/0` despite detailed layout, method, vtable, global, pollution, and open-question notes.
- Changed to: `COMPLETION:84` and `CONFIDENCE:76`.
- Evidence: constructor/destructor, slot updates, mouse/key/timer/paint helpers, animation counters, frame mapping, scalar deleting destructor, singleton xrefs, parcel-icon ownership, and known stale FPS pollution are documented; confidence remains medium because helper ownership and full input semantics still need review.
- 2026-06-03 confidence update:
  - What existed before: `CONFIDENCE:76` and the `OnKeyDown` row only described the tiny generated body.
  - Changed to: `CONFIDENCE:80`, with the key-event row tied to exact vtable-data and layout evidence.
  - Evidence: [UID:0000MF][ParcelPane](by-file/ParcelPane.md) was a validated `NexusTK/ui/panels/` parent at 80 confidence, [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md) and [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) documented the `ParcelPane` secondary key-event slot, and [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md) documented the parcel callback subobject offsets. The blank C++ rationale is historical and superseded by later exact child implementations.
- 2026-06-12 A002 Goal2 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`; the class page did not clear the corrected 85/85 parent gate for the already attached paint child.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`; child routing to the class is now justified for [UID:0002KG][0x00546890-0x0054696f.ParcelPaneOnPaint](by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md) and other exact ParcelPane method pages that individually clear 85/85.
  - Evidence: live IDA MCP refreshed `ParcelPaneOnPaint` with exact boundary, primary vtable slot `0x00621c80`, resource xrefs, field offsets, helper boundaries, and one-byte successor padding; `analyze_component` over the main ParcelPane method cluster reconfirmed constructor/destructor/shared-vtable relationships for `0x00621c3c`, `0x00621c90`, and `0x00621cc0`. Remaining field/helper names keep the score below final-audit range.
- 2026-06-17 B001 source-quality support refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:86`; timer/frame helper pages still carried open slot-state, field-name, and PatchPane caller caveats.
  - After: `COMPLETION:88`, `CONFIDENCE:90`; added accepted `ParcelButtonState` names, `ALERTBTN` frame map, left/right count/state/frame/acknowledgement fields, timer callback role, protected helper names, and stale PatchPane caller rejection.
  - Evidence: B001 live IDA rechecked the timer callback, frame-advance helper, frame resolver, vtable slots `0x00621cc4/0x00621c84/0x00621c88`, count nibble flow through `ParcelIconPaneParcelUpdateCallback`, mouse state writes, and generated switch-table bytes after [UID:0002KI][0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex](by-memory/0x005469e0-0x00546aab.ParcelPaneGetButtonFrameIndex.md).
