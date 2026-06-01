*** UID:00000S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BackPane

## Status

- Confidence: strong for core methods; medium for help-popup helper ownership; generated scattered helper ownership is tracked separately.
- Likely source file: [UID:0000HO][BackPane](by-file/BackPane.md)
- Core address range: [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- Current recovered file: `source-3/simroot_v2/class_BackPane.cpp`

## Class Purpose

`BackPane` is the root background pane for the in-game UI after login. It is constructed as the base/root pane for the main UI graph, loads a frame resource through the EPF/resource layout table, paints the background frame using the palette appropriate for the current asset mode, and provides a widely used bounds accessor for child UI and map/render helpers.

## Class Shape

- Base family: root `Pane` for the in-game UI graph after login.
- Singleton/state: owns `g_pBackPane`, cached bounds at `this + 0x44`, embedded tile context, and asset-mode-dependent frame palette selection.
- System dependencies: interacts with `ChangeMan`, cursor management, EPF frame loading, help-popup placement, and broad UI/map bounds consumers.
- Source placement: [UID:0000HO][BackPane](by-file/BackPane.md), with scattered helpers documented separately when generated ownership is wrong.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00467830-0x004678ee` | Constructs `Pane`, stores `g_pBackPane`, installs vtables, initializes tile context, copies screen dimensions, and loads the frame resource. |
| non-deleting destructor | `0x004678f0-0x0046795c` | Resets vtables, unregisters from [UID:00001K][ChangeMan](by-class/ChangeMan.md), clears `g_pBackPane`, and tears down `Pane`. |
| singleton clear thunk | `0x00467a50-0x00467a5b` | Clears `g_pBackPane`. |
| `OnActivate` | `0x004679c0-0x004679dd` | In legacy asset mode, resets the cursor through `CursorManager`; returns true. |
| `OnPaint` | `0x004679e0-0x00467a48` | Gets bounds and renders the frame using `FRAME.PAL` in EPF mode or `NPAL5.PAL` otherwise. |
| deleting destructor | `0x00467a80-0x00467b2d` | Same teardown as the non-deleting destructor plus optional `operator delete`. |
| adjustor thunks | `0x00467a5b-0x00467a71` | Multiple-inheritance/vtable thunks to the deleting destructor; compiler support only. |
| `GetBounds` | [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md) | Copies the cached layer bounds into the caller's `RECT`. |
| help packet helpers | [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md) | Decode packet text, convert to wide text, and place a simple help pane relative to current back-pane bounds. |

## Data Notes

- `g_pBackPane` is the live singleton pointer. It is written in the constructor and cleared by destructor paths.
- `g_pEPFLib` supplies `LoadFrame`.
- `g_screenWidth` and `g_screenHeight` are copied into the object at construction.
- `g_useEpfAssets` controls the `FRAME.PAL` versus `NPAL5.PAL` paint branch.
- [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md) is notified during teardown.

## Evidence Notes

- IDA MCP confirms real functions at all core method starts listed above.
- IDA xrefs show `BackPane::BackPane` is called from `InitializeMainUiGraph` at two EPF/legacy construction sites.
- `by-memory/-report.md` already lists `BackPane::OnPaint` and `BackPane::GetBounds` as integrated Wave2 methods.
- IDA MCP recheck on 2026-05-25 confirms `BackPane::GetBounds` copies the 16-byte cached rect from `this + 0x44` and is called broadly by UI/render helpers.
- IDA MCP recheck on 2026-05-25 confirms the three help packet helpers read current back-pane bounds, convert packet text through `MultiByteToWideChar`, close the active help popup, and allocate a replacement popup pane.
- Generated `simroot_v2` emits additional scattered `BackPane` methods. IDA MCP recheck rejects BackPane source ownership for [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md), [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md), and [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md): the first is called only from `ChattingModifyHeightPane::OnMouseEvent`, the second from target-selection panes, and the third is now reowned to `EffectObjectPane` after caller/object-layout review.
- The generated `0x005c2760` and `0x005c2840` rows are not BackPane: IDA has raw code bytes but no function objects/xrefs, and the field offsets/call to `0x005c2930` tie them to [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md).

## Cross-References

- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md)
- [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md)
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
