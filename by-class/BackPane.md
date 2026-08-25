*** UID:00000S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "BackPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_BACKPANE_H
#define NEXUSTK_MAP_BACKPANE_H

#include "../ui/core/Pane.h"
#include "../render/EPFTileContext.h"

class BackPane : public Pane
{
public:
    explicit BackPane(const wchar_t *frameResourceName);
    virtual ~BackPane();

    virtual bool OnActivate(int activateCode);
    virtual void OnPaint();

    void ShowHelpFromPacket(const unsigned char *packet);
    void ShowHelpFromPacketV2(const unsigned char *packet);
    void ShowHelpFromPacketV3(const unsigned char *packet);

private:
    EPFTileContext m_frameTileContext;
    int m_frameWidth;
    int m_frameHeight;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BackPane
## UID0000LU Owner Header Placement - 2026-08-15

The complete BackPane declaration now lives in `map/BackPane.h`, with the CPP including that header before existing method children. The full Pane-derived class and EPFTileContext storage are preserved; no reduced NewSpell-only declaration was created.

## Status

- Confidence: high for core lifecycle/paint methods, source-file parentage, singleton storage, and first-draft declaration; medium-high for final help-popup dispatch reachability.
- Source parent: [UID:0000HO][BackPane](by-file/BackPane.md)
- Core address range: [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md), now split into exact BackPane children.
- Historical generated source lead: `source-3/simroot_v2/class_BackPane.cpp`; use only as search context, not source authority.

## Class Purpose

`BackPane` is the root background pane for the in-game UI after login. It is constructed as the base/root pane for the main UI graph, loads a frame resource through the EPF/resource layout table, and paints the background frame using the palette appropriate for the current asset mode. Its paint/help paths consume the inherited `GrafPort::GetBounds` accessor; BackPane does not declare or define a duplicate accessor.

## Class Shape

- Base family: root `Pane` for the in-game UI graph after login.
- Singleton/state: owns `g_pBackPane`, exposes inherited [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) local bounds at `this + 0x44`, embeds the tile context, and selects the asset-mode-dependent frame palette.
- System dependencies: interacts with `ChangeMan`, cursor management, EPF frame loading, help-popup placement, and broad UI/map bounds consumers.
- Source placement: [UID:0000HO][BackPane](by-file/BackPane.md), with scattered helpers documented separately when generated ownership is wrong.
- First-draft class declaration is populated in the formal `RECONSTRUCTION_CPP CODE` block. It preserves already-present [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md) constructor/destructor C++ and the accepted [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) and help-helper method surface. [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md) now supplies the inherited `GrafPort::GetBounds` definition through GrafPort instead of this class.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `BackPane::BackPane(const wchar_t *frameResourceName)` | [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md) `0x00467830-0x004678ee` | Constructs `Pane(0)`, publishes `g_pBackPane` with the adjusted-member guard clear path, installs BackPane vtables, initializes `m_frameTileContext`, copies `g_screenWidth`/`g_screenHeight` into `m_frameWidth`/`m_frameHeight`, and loads the selected frame resource. B005 source-quality pass now marks this exact child first-draft C++ ready. |
| `BackPane::~BackPane()` ordinary/non-deleting destructor | [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md) `0x004678f0-0x0046795c` | Resets vtables, unregisters from [UID:00001K][ChangeMan](by-class/ChangeMan.md), clears `g_pBackPane`, and tears down `Pane`; the scalar deleting destructor in [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) duplicates this body plus optional free. B005 now records first-draft source for the ordinary destructor in [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md). |
| singleton clear thunk | [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) `0x00467a50-0x00467a5b` | Clears `g_pBackPane`. |
| `OnActivate` | [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) `0x004679c0-0x004679dd` | In legacy asset mode, resets the cursor through `CursorManager`; returns true. |
| `OnPaint` | [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) `0x004679e0-0x00467a48` | Gets bounds and renders the frame using `FRAME.PAL` in EPF mode or `NPAL5.PAL` otherwise; now first-draft C++ ready with `g_useEpfAssets` and resource-literal branch preserved. |
| deleting destructor | [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) `0x00467a80-0x00467b2d` | Same teardown as the non-deleting destructor plus optional `operator delete`. |
| adjustor thunks | [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) `0x00467a5b-0x00467a71` | Multiple-inheritance/vtable thunks to the deleting destructor; compiler support only. |
| inherited `GrafPort::GetBounds(RectBounds *outBounds) const` | [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md) | Copies inherited `GrafPort::m_visibleBounds` at `this+0x44` into `outBounds` and returns `outBounds`. BackPane paint/help code consumes this inherited method; a direct HitBarObjectPane receiver rejects the historical BackPane-owned declaration. |
| help packet helpers | [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md) | Decode packet text, convert to wide text, close/replace the active simple help pane, and place the popup relative to current back-pane bounds. Zero direct xrefs remain a dispatch caveat, not a first-draft C++ blocker. |

## Data Notes

- `g_pBackPane` is the live singleton pointer. It is published by `BackPane::BackPane` at `0x00467878`, guard-cleared at `0x0046787f`, and cleared by destructor paths at `0x0046793d`, `0x00467a50`, and `0x00467ad4`.
- `m_frameTileContext` is the inferred embedded `EPFTileContext` at `this + 0xf8`; construction initializes it before the resource lookup.
- `g_pEPFLib` supplies the resource-layout lookup used by the constructor for the selected frame filename.
- `g_screenWidth` and `g_screenHeight` are copied into inferred construction cache fields `m_frameWidth` / `this + 0x120` and `m_frameHeight` / `this + 0x124`.
- `g_useEpfAssets` controls the `FRAME.PAL` versus `NPAL5.PAL` paint branch.
- [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md) is notified during teardown.

## Evidence Notes

- IDA MCP confirms real functions at all core method starts listed above.
- IDA xrefs show `BackPane::BackPane` is called from `InitializeMainUiGraph` at two EPF/legacy construction sites.
- Historical `by-memory/-report.md`/Wave-era output listed `BackPane::OnPaint` and `BackPane::GetBounds` together. `OnPaint` remains BackPane-owned; the accessor label is superseded by current `GrafPort::GetBounds` ownership and is not authority for present source shape.
- Historical 2026-05-25 evidence correctly established the 16-byte copy from `this + 0x44` and broad UI/render calls, but its BackPane-specific owner label is superseded; current evidence identifies `GrafPort::m_visibleBounds` and inherited `GrafPort::GetBounds`.
- IDA MCP recheck on 2026-05-25 confirms the three help packet helpers read current back-pane bounds, convert packet text through `MultiByteToWideChar`, close the active help popup, and allocate a replacement popup pane.
- Live IDA recheck on 2026-06-06 confirms `sub_467830` has size `0xbe`, stores `g_pBackPane`, installs three `BackPane` vtables, initializes the tile context, copies screen dimensions, and loads the frame resource through the EPF/library path.
- Live IDA recheck on 2026-06-06 confirms `sub_4678f0`, `sub_467a50`, and `sub_467a80` all clear `g_pBackPane`; destructor variants reset BackPane vtables, unregister through [UID:00001K][ChangeMan](by-class/ChangeMan.md), tear down the base `Pane`, and the scalar deleting form conditionally frees the allocation.
- Live IDA recheck on 2026-06-06 confirms `OnActivate` only resets cursor state in legacy asset mode, `OnPaint` calls inherited [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md) and selects the EPF versus legacy palette resource, and the adjacent [UID:00000R][BackGroundPane](by-class/BackGroundPane.md) constructor uses its own singleton/vtable family rather than sharing this class.
- Live IDA recheck on 2026-06-08 split the old mixed aggregate into exact BackPane children: `0x00467830-0x0046795c` for constructor/non-deleting destructor and `0x004679c0-0x00467b2d` for activate/paint/clear/deleting-destructor methods. The intervening `0x00467960-0x004679bf` function remains the separate [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md) Application helper.
- B005 live MCP-backed source-quality implementation on 2026-06-23 uses session `80de0a67` and PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632` to raise [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md) to `88/91` and add first-draft constructor/destructor C++. It verifies `sub_467830` size `0xbe`, `sub_4678F0` size `0x6c`, exact `0xcc` padding before, between, and after the functions, two `InitializeMainUiGraph` constructor callers at `0x004f7d7d`/`0x004f8573` with `FRAME.EPF`/`FRAME.EPD`, BackPane vtable anchors `0x00612fc8`/`0x00613014`/`0x00613044`, `g_pEPFLib` lookup at `0x004678d4`, screen-dimension copies, `ChangeMan::UnregisterObject` teardown, and [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md) successor separation. This supersedes the old `95/95` blank-C++ gate only for [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md); broader class caveats still apply to other BackPane-family helpers and declarations.
- Generated `simroot_v2` emits additional scattered `BackPane` methods. IDA MCP recheck rejects BackPane source ownership for [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md), [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md), and [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md): the first is called only from `ChattingModifyHeightPane::OnMouseEvent`, the second from target-selection panes, and the third is now reowned to `EffectObjectPane` after caller/object-layout review.
- The generated `0x005c2760` and `0x005c2840` rows are not BackPane: IDA has raw code bytes but no function objects/xrefs, and the field offsets/call to `0x005c2930` tie them to [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md).
- B009 live MCP session `supervisor_resume_20260629` confirms [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) first-draft readiness: `OnActivate` `0x004679c0` size `0x1d` returns true and calls the `g_pScreenPane`/cursor reset helper only when `g_useEpfAssets != 1`; `OnPaint` `0x004679e0` size `0x68` calls `GetBounds`, then draws with `FRAME.PAL` at `0x0061304c` in EPF mode and shared `NPAL5.PAL` at `0x00610fd0` in legacy mode; `0x00467a50` is exact `g_pBackPane = NULL`; scalar deleting destructor `0x00467a80` size `0xad` duplicates the ordinary destructor body and conditionally frees storage.
- B009 current MCP decompiles confirm [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), and [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md) first-draft readiness. V1/V2 use `ReadPacketWord(packet+1) & 0x3fff`, V3 uses byte `packet[2]`, all read length from `packet+3`, guard `1..1023`, convert `packet+5` with `MultiByteToWideChar`, null-terminate, call `GetBounds`, close `g_pSimpleHelpPane`, allocate `252` bytes, construct `SimpleHelpPane`, and pass timeout `10000`. `xrefs_to` remains zero for all three helper starts, so dispatch reachability caps final confidence but no longer blocks formal source.

## Cross-References

- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md)
- [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md)
- [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md)
- [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md)
- [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md)
- [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md)
- [UID:0001R7][backpane-background-resources](by-resource/backpane-background-resources.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00000R][BackGroundPane](by-class/BackGroundPane.md)
- [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)

## Changes

- What existed before: the page contained strong core method evidence and rejected several generated helper ownership mistakes but had unevaluated scores.
- What it was changed to: scores were set to `76/82`, and class-shape notes were added for root pane role, singleton/cached bounds state, dependencies, and source placement.
- Summary and evidence: constructor/destructor/paint/get-bounds behavior is strong through IDA and by-memory references; confidence is held below the simpler panes because generated scattered helpers still require ownership discipline.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor, destructor, activate, paint, and deleting-destructor starts at `0x00467830`, `0x004678f0`, `0x004679c0`, `0x004679e0`, and `0x00467a80`, and `callers` shows construction from the main UI initialization path. Parent attachment remained blank at that time because this class and [UID:0000HO][BackPane](by-file/BackPane.md) did not both clear the 80+ completion attachment gate.
- 2026-06-06: Raised to `82/86` and attached `AUTOGEN_PARENT_UID:0000HO` after live IDA decompilation reconfirmed the BackPane singleton lifecycle, vtable family, ChangeMan unregister, paint resource branch, `GetBounds` call, and the adjacent BackGroundPane singleton split. Final C++ remains blank because the class declarations, member names, and helper ownership are not yet at the 95/95 reconstruction-code gate.
- 2026-06-08 A006 Batch105 split:
  - Before: score `82/86`, and the core memory link pointed only at the mixed BackPane/BackGroundPane/Application aggregate.
  - Changed to: score `85/88`; method rows now point at exact BackPane child pages split around the Application shutdown-message helper.
  - Summary/evidence: live IDA MCP reconfirmed the constructor/non-deleting-destructor boundaries, activate/paint/clear/deleting-destructor boundaries, two `InitializeMainUiGraph` constructor callers, `g_pBackPane` lifecycle refs, and the next `BalloonObjectPane` boundary. The direct file parent [UID:0000HO][BackPane](by-file/BackPane.md) is `86/88`, so this class clears the corrected parent gate for exact BackPane memory children.
- Historical 2026-06-18 B003 BackPaneGetBounds source-quality execution:
  - B003 established UID000161 as a 17-byte direct-call leaf that copies the 16-byte rectangle at `+0x44`, returns the output pointer, has 103 direct rel32 callers, no hidden pointer/vtable route, and source-ready behavior. Its `BackPane::GetBounds` and `Pane::m_bounds`/`m_localBounds` owner/member spellings are retained only as superseded history.
- 2026-07-15 B002 UID0003TC integration:
  - UID000161 was UID-preserving renamed to [0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md), rerouted to owner/emitter [UID:00005V][GrafPort](by-class/GrafPort.md), and resolved as `GrafPort::GetBounds` over `m_visibleBounds` at `+0x44`.
  - The direct HitBarObjectPane receiver, shared GrafPort ancestry, GrafPort function island, and broad unrelated caller families reject a BackPane-specific declaration. The managed BackPane declaration therefore omits `GetBounds`; existing paint/help behavior remains unchanged through inheritance.
- 2026-06-23 B005 BackPane construction/destruction source-quality execution:
  - [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md) now carries first-draft `BackPane::BackPane(const wchar_t *frameResourceName)` and `BackPane::~BackPane()` C++ at `88/91`.
  - The old target-specific `95/95` blank-C++ language is superseded by current MCP evidence: session `80de0a67`, exact boundaries and padding, two root-UI callers with `FRAME.EPF`/`FRAME.EPD`, `g_pBackPane` publish/clear lifecycle, embedded `EPFTileContext`, display-dimension cache fields, `g_pEPFLib` lookup, and `ChangeMan` unregister.
- 2026-07-01 B009 empty-emitter implementation:
  - Raised from `85/88` to `88/91`.
  - Inserted first-draft class declaration in the formal C++ block and preserved [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md); UID000161's then-BackPane assignment is historical and is now inherited from GrafPort.
  - Updated [UID:00030N][0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor](by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md) and help-helper method evidence as first-draft ready while preserving the help-helper zero-xref dispatch caveat and generated-owner pollution exclusions.
