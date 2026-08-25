** TARGET-REPORT-UID:0001G6 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001G6] SurfacePresentation Split Ownership Report

## Final Recommendation

Keep [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](../../../../../by-memory/0x00557140-0x00559aef.SurfacePresentation.md) as a parent-blank, non-emitting mixed executable-neighborhood container:

- `RECONSTRUCTABLE:FALSE`
- `COMPLETION:88`
- `CONFIDENCE:90`
- no `AUTOGEN_PARENT_UID`

The split is now executable for supervisor coverage-report use. Every source-bearing child inside `0x00557140-0x00559aef` has an exact child page and a direct parent decision that clears the current `85/85` child/parent gate. The previous below-gate children are repaired:

- `00039U` `82/86 -> 86/88`, assigned to [UID:0000CB][ScreenPane](../../../../../by-class/ScreenPane.md).
- `0003A0` `84/86 -> 86/88`, assigned to [UID:0000CB][ScreenPane](../../../../../by-class/ScreenPane.md).
- `0003A2` `80/84 -> 85/86`, assigned to [UID:0000NB][ScreenPane](../../../../../by-file/ScreenPane.md).
- `0001G8` `76/82 -> 85/86`, assigned to [UID:0000ND][ScreenshotCapture](../../../../../by-file/ScreenshotCapture.md).
- `0001G9` `82/86 -> 86/88`, assigned to [UID:0000ND][ScreenshotCapture](../../../../../by-file/ScreenshotCapture.md).
- `ScreenshotCapture` file parent `88/80 -> 88/86`.

Do not assign the master `0001G6` row wholesale to Surface, ScreenPane, ScreenshotCapture, or DirectX. Surface, ScreenPane, and ScreenshotCapture each own exact children; no one source owner owns the full aggregate.

Do not edit `by-memory/-coverage-report.md` directly from B001. The supervisor should replace the stale `0001G6` block with the exact rows below.

## Exact by-memory/-coverage-report.md Replacement Rows

Replace the current `0001G6` master row and its nested stale child rows only. Keep the preceding row for `0x00557132-0x00557140` and the following row for `0x00559aef-0x00559af0` as-is.

```markdown
    - [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) 0x00557140-0x00559aef | mixed split inventory | SurfacePresentation : not_reconstructable : 88% : very-strong : B001-049 split execution converted this range to a parent-blank non-emitting mixed executable-neighborhood container. Exact children carry Surface, ScreenPane, and ScreenshotCapture ownership; live IDA MCP rechecked modeled/raw starts, found no uncovered non-`0xcc` bytes, repaired below-gate children, and corrected the `0x00559151-0x00559160` padding boundary.
        - [UID:00039P][0x00557140-0x00557377.SurfaceRenderPresentation](by-memory/0x00557140-0x00557377.SurfaceRenderPresentation.md) 0x00557140-0x00557377 | function | SurfaceRenderPresentation : reconstructable : 86% : strong : Assigned to [UID:0000OC][Surface](by-file/Surface.md); live IDA confirms modeled `sub_557140`, broad presentation callers, Surface callback/blit/traversal callees, screen-size/callback-table refs, and exact post-function padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00557377-0x00557380 | padding | SurfaceRenderPresentation to ScreenCursorHelpers alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:0001G7][0x00557380-0x00557467.ScreenCursorHelpers](by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md) 0x00557380-0x00557467 | screen/cursor helper island | ScreenCursorHelpers : reconstructable : 86% : very-strong : Assigned to [UID:0000NB][ScreenPane](by-file/ScreenPane.md) after child 86/90 and parent 86/85; IDA confirms seven helper boundaries, root-screen offsets, Win32 cursor calls, dimension accessors, and exact internal padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00557468-0x00557470 | padding | ScreenCursorHelpers to SurfaceFlipSurfaces alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039Q][0x00557470-0x0055769d.SurfaceFlipSurfaces](by-memory/0x00557470-0x0055769d.SurfaceFlipSurfaces.md) 0x00557470-0x0055769d | function | SurfaceFlipSurfaces : reconstructable : 85% : strong : Assigned to [UID:0000OC][Surface](by-file/Surface.md); IDA confirms DirectDraw flip/presentation helper, `g_pDirectX` dependency, Surface/minimap caller, DirectDraw vtable calls, and exception path.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055769d-0x005576a0 | padding | SurfaceFlipSurfaces to SurfaceDirectDrawRestoreMaintenance alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039R][0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance](by-memory/0x005576a0-0x00557810.SurfaceDirectDrawRestoreMaintenance.md) 0x005576a0-0x00557810 | function | SurfaceDirectDrawRestoreMaintenance : reconstructable : 85% : strong : Assigned to [UID:0000OC][Surface](by-file/Surface.md); IDA confirms DirectDraw restore/maintenance behavior, callers at `0x00466abb` and `0x004f5ed7`, DirectDraw vtable slots, and exception path.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00557810-0x00557820 | padding | SurfaceDirectDrawRestoreMaintenance to ScreenPanePresentationModeFlagSetters alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039S][0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters](by-memory/0x00557820-0x00557838.ScreenPanePresentationModeFlagSetters.md) 0x00557820-0x00557838 | tiny helper pair | ScreenPanePresentationModeFlagSetters : reconstructable : 85% : strong : Assigned to [UID:0000NB][ScreenPane](by-file/ScreenPane.md); IDA confirms root ScreenPane `+0x12c` presentation-mode setters and indirect callers through `dword_67A7CC`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00557838-0x00557840 | padding | ScreenPanePresentationModeFlagSetters to ScreenshotJpegCapturePath alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:0001G8][0x00557840-0x00557a95.ScreenshotJpegCapturePath](by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md) 0x00557840-0x00557a95 | raw screenshot helper | ScreenshotJpegCapturePath : reconstructable : 85% : strong : Assigned to [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md), now `88/86`; full raw-reference scan found no pointer/direct-call to the raw start, but IDA confirms complete JPG save/status/proof workflow and key raw calls to Surface update/flush/end, JPEG writer, status formatter, chat append, and proof packet.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00557a96-0x00557aa0 | padding | ScreenshotJpegCapturePath to ScreenshotCaptureAndProof alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md) 0x00557aa0-0x00558391 | screenshot capture/proof cluster | ScreenshotCaptureAndProof : reconstructable : 86% : strong : Assigned to [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md), now `88/86`; IDA confirms BMP/PNG hotkey callers, shared saved-file status path, three proof-packet callsites including raw JPG, and opcode `0x83` proof construction.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00558391-0x005583a0 | padding | ScreenshotCaptureAndProof to SurfaceDrawTilePresentation alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039T][0x005583a0-0x0055867a.SurfaceDrawTilePresentation](by-memory/0x005583a0-0x0055867a.SurfaceDrawTilePresentation.md) 0x005583a0-0x0055867a | function | SurfaceDrawTilePresentation : reconstructable : 85% : strong : Assigned to [UID:0000OC][Surface](by-file/Surface.md); IDA confirms Surface tile presentation behavior, shared state with `SurfaceRenderPresentation`, and traversal/blit/callback dependencies despite no direct callers.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055867a-0x00558680 | padding | SurfaceDrawTilePresentation to UnresolvedPresentationFlagSetter alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039U][0x00558680-0x00558688.UnresolvedPresentationFlagSetter](by-memory/0x00558680-0x00558688.UnresolvedPresentationFlagSetter.md) 0x00558680-0x00558688 | tiny helper | UnresolvedPresentationFlagSetter : reconstructable : 86% : strong : Assigned to [UID:0000CB][ScreenPane](by-class/ScreenPane.md); exact operand search shows all visible `+0x5b0` uses are ScreenPane constructor/init and presentation read/clear/set sites, while no caller/pointer to the tiny setter was recovered.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00558688-0x00558690 | padding | UnresolvedPresentationFlagSetter to SurfaceRenderCallbackInitializerRaw alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039V][0x00558690-0x0055883d.SurfaceRenderCallbackInitializerRaw](by-memory/0x00558690-0x0055883d.SurfaceRenderCallbackInitializerRaw.md) 0x00558690-0x0055883d | raw function | SurfaceRenderCallbackInitializerRaw : reconstructable : 85% : strong : Assigned to [UID:0000OC][Surface](by-file/Surface.md); IDA confirms raw setup of Surface render callbacks, Surface globals, tile draw/render helpers, and DirectDraw-surface dependencies.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055883d-0x00558840 | padding | SurfaceRenderCallbackInitializerRaw to SurfaceMinimapRenderInitializer alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039W][0x00558840-0x00558f63.SurfaceMinimapRenderInitializer](by-memory/0x00558840-0x00558f63.SurfaceMinimapRenderInitializer.md) 0x00558840-0x00558f63 | raw function | SurfaceMinimapRenderInitializer : reconstructable : 86% : strong : Assigned to [UID:0000OC][Surface](by-file/Surface.md); IDA confirms Surface/minimap render-buffer initialization, repeated DirectDraw-surface setup, minimap geometry refs, and Surface restore/flip calls.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00558f63-0x00558f70 | padding | SurfaceMinimapRenderInitializer to ScreenPaneCursorResourceLoader alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039X][0x00558f70-0x005590da.ScreenPaneCursorResourceLoader](by-memory/0x00558f70-0x005590da.ScreenPaneCursorResourceLoader.md) 0x00558f70-0x005590da | function | ScreenPaneCursorResourceLoader : reconstructable : 85% : strong : Assigned to [UID:0000NB][ScreenPane](by-file/ScreenPane.md); IDA confirms ScreenPane resource/cursor loading path, cursor helper dependencies, and ScreenPane-owned state writes.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005590da-0x005590e0 | padding | ScreenPaneCursorResourceLoader to ScreenPaneCallbackAndFlagHelpers alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039Y][0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers](by-memory/0x005590e0-0x0055916b.ScreenPaneCallbackAndFlagHelpers.md) 0x005590e0-0x0055916b | tiny helper cluster | ScreenPaneCallbackAndFlagHelpers : reconstructable : 85% : strong : Assigned to [UID:0000NB][ScreenPane](by-file/ScreenPane.md); IDA confirms root ScreenPane callback dispatch helpers, ScreenPane flags, the real `0x00559170` next-function boundary, and `0x00559151-0x00559160` padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055916b-0x00559170 | padding | ScreenPaneCallbackAndFlagHelpers to SurfaceRestoreLostSurfaces alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00039Z][0x00559170-0x005591fc.SurfaceRestoreLostSurfaces](by-memory/0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md) 0x00559170-0x005591fc | function | SurfaceRestoreLostSurfaces : reconstructable : 85% : strong : Assigned to [UID:0000OC][Surface](by-file/Surface.md); IDA confirms DirectDraw surface restore behavior and Surface/minimap render-initializer caller.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005591fc-0x00559200 | padding | SurfaceRestoreLostSurfaces to ScreenPanePresentationTransitionHelpers alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:0003A0][0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers](by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md) 0x00559200-0x00559359 | raw helper pair | ScreenPanePresentationTransitionHelpers : reconstructable : 86% : strong : Assigned to [UID:0000CB][ScreenPane](by-class/ScreenPane.md); decompilation matches the two ScreenPane transition branches, exact field search ties `+0x598/+0x5a4/+0x5a8/+0x5ac` to constructor/HandleMessage state, and no caller/pointer was recovered.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00559359-0x00559360 | padding | ScreenPanePresentationTransitionHelpers to ScreenPaneLayerIndexLookup alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:0003A1][0x00559360-0x005593a2.ScreenPaneLayerIndexLookup](by-memory/0x00559360-0x005593a2.ScreenPaneLayerIndexLookup.md) 0x00559360-0x005593a2 | function | ScreenPaneLayerIndexLookup : reconstructable : 85% : strong : Assigned to [UID:0000NB][ScreenPane](by-file/ScreenPane.md); IDA confirms callers from ScreenPane helpers at `0x00556ce0` and `0x00556d20`, layer indexing behavior, and exact padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005593a2-0x005593b0 | padding | ScreenPaneLayerIndexLookup to ScreenPanePaletteVisibleTilesRedrawRaw alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md) 0x005593b0-0x0055940c | raw helper | ScreenPanePaletteVisibleTilesRedrawRaw : reconstructable : 85% : strong : Assigned to [UID:0000NB][ScreenPane](by-file/ScreenPane.md); raw disassembly matches the `ScreenPane::HandleMessage` palette/active-pane/root-update repaint branch, with PaletteLib and MapPane as dependencies rather than direct owners.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055940c-0x00559410 | padding | ScreenPanePaletteVisibleTilesRedrawRaw to ScreenPanePresentationTraversal alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:0003A3][0x00559410-0x005595ca.ScreenPanePresentationTraversal](by-memory/0x00559410-0x005595ca.ScreenPanePresentationTraversal.md) 0x00559410-0x005595ca | function | ScreenPanePresentationTraversal : reconstructable : 86% : strong : Assigned to [UID:0000NB][ScreenPane](by-file/ScreenPane.md); live IDA confirms callers from ScreenPane message code, Surface presentation code, and transition helpers plus root callback/list traversal behavior.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005595ca-0x005595d0 | padding | ScreenPanePresentationTraversal to BlitSurfaceToDisplay alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:0003A4][0x005595d0-0x00559a0f.BlitSurfaceToDisplay](by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md) 0x005595d0-0x00559a0f | function | BlitSurfaceToDisplay : reconstructable : 85% : strong : Assigned to [UID:0000OC][Surface](by-file/Surface.md); IDA confirms DirectDraw blit/display copy path, Surface source-buffer dependencies, and Surface presentation callers.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00559a0f-0x00559a10 | padding | BlitSurfaceToDisplay to SurfaceDirectDrawCopyHelper alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment.
        - [UID:00023S][0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper](by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md) 0x00559a10-0x00559aef | function | SurfaceDirectDrawCopyHelper : reconstructable : 85% : very-strong : Assigned to [UID:0000OC][Surface](by-file/Surface.md); IDA confirms DirectDraw copy helper behavior, Surface blit caller, and DirectDraw lock/unlock/copy dependencies.
```

## Supporting Research

### Target

- Target UID: `0001G6`
- Target path: `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`
- Supervisor assignment: B001-049 `[UID:0001G6] SurfacePresentation`
- Current master state: parent-blank, `RECONSTRUCTABLE:FALSE`, `88/90`

### Function / Child Inventory

| UID | Range | Page | Direct parent | Score | Status |
|---|---:|---|---|---:|---|
| `00039P` | `0x00557140-0x00557377` | `SurfaceRenderPresentation` | `Surface` | `86/88` | assigned |
| `0001G7` | `0x00557380-0x00557467` | `ScreenCursorHelpers` | `ScreenPane` file | `86/90` | assigned |
| `00039Q` | `0x00557470-0x0055769d` | `SurfaceFlipSurfaces` | `Surface` | `85/88` | assigned |
| `00039R` | `0x005576a0-0x00557810` | `SurfaceDirectDrawRestoreMaintenance` | `Surface` | `85/87` | assigned |
| `00039S` | `0x00557820-0x00557838` | `ScreenPanePresentationModeFlagSetters` | `ScreenPane` file | `85/87` | assigned |
| `0001G8` | `0x00557840-0x00557a95` | `ScreenshotJpegCapturePath` | `ScreenshotCapture` file | `85/86` | repaired and assigned |
| `0001G9` | `0x00557aa0-0x00558391` | `ScreenshotCaptureAndProof` | `ScreenshotCapture` file | `86/88` | repaired and assigned |
| `00039T` | `0x005583a0-0x0055867a` | `SurfaceDrawTilePresentation` | `Surface` | `85/87` | assigned |
| `00039U` | `0x00558680-0x00558688` | `UnresolvedPresentationFlagSetter` | `ScreenPane` class | `86/88` | repaired and assigned |
| `00039V` | `0x00558690-0x0055883d` | `SurfaceRenderCallbackInitializerRaw` | `Surface` | `85/88` | assigned |
| `00039W` | `0x00558840-0x00558f63` | `SurfaceMinimapRenderInitializer` | `Surface` | `86/88` | assigned |
| `00039X` | `0x00558f70-0x005590da` | `ScreenPaneCursorResourceLoader` | `ScreenPane` file | `86/89` | assigned |
| `00039Y` | `0x005590e0-0x0055916b` | `ScreenPaneCallbackAndFlagHelpers` | `ScreenPane` file | `85/87` | assigned |
| `00039Z` | `0x00559170-0x005591fc` | `SurfaceRestoreLostSurfaces` | `Surface` | `85/87` | assigned |
| `0003A0` | `0x00559200-0x00559359` | `ScreenPanePresentationTransitionHelpers` | `ScreenPane` class | `86/88` | repaired and assigned |
| `0003A1` | `0x00559360-0x005593a2` | `ScreenPaneLayerIndexLookup` | `ScreenPane` file | `85/88` | assigned |
| `0003A2` | `0x005593b0-0x0055940c` | `ScreenPanePaletteVisibleTilesRedrawRaw` | `ScreenPane` file | `85/86` | repaired and assigned |
| `0003A3` | `0x00559410-0x005595ca` | `ScreenPanePresentationTraversal` | `ScreenPane` file | `85/86` | assigned |
| `0003A4` | `0x005595d0-0x00559a0f` | `BlitSurfaceToDisplay` | `Surface` | `87/89` | assigned |
| `00023S` | `0x00559a10-0x00559aef` | `SurfaceDirectDrawCopyHelper` | `Surface` | `85/89` | assigned |

### IDA MCP Facts

- IDA target: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- No uncovered non-`0xcc` bytes remain after applying the split inventory.
- Full-segment raw reference scan found zero direct xrefs, zero absolute pointers, and zero direct rel32 call/jump encodings to `0x00558680`, `0x00559200`, `0x005592b0`, `0x005593b0`, and `0x00557840`.
- Exact field search found every visible `+0x5b0` use: constructor init at `0x005569fd`, read/clear in `0x00557140` and `0x005583a0`, and the tiny setter at `0x00558680`.
- Exact transition-field search tied `+0x598/+0x5a4/+0x5a8/+0x5ac` to ScreenPane constructor, `ScreenPane::HandleMessage`, Surface presentation consumers, and transition helpers `0x00559200` / `0x005592b0`.
- Decompilation of `0x00559200` and `0x005592b0` matches the two ScreenPane transition branches from `HandleMessage`: state `2` with `+0x5ac = 0x18`, and state `3` with `+0x5ac = 0`.
- Raw `0x005593b0` loads `dword_67A7E0`, `dword_67A764`, and `dword_67A874`, calls PaletteLib state helpers, refreshes the active pane through `0x005051c0` and a virtual repaint, calls root update `0x004b8630`, and restores PaletteLib state. `ScreenPane::HandleMessage` uses the same global sequence.
- EventDispatcher `0x004a7130` loads `dword_67A7CC` / `g_pScreenPane` and calls BMP at `0x004a71b6` / `0x004a7250`, PNG at `0x004a71d1` / `0x004a7296`.
- Raw JPG `0x00557840` has key calls to `0x004b9820`, `0x0046bfd0`, `0x004efbc0`, `0x004b98c0`, `0x00559af0`, `0x0047f280`, and `0x00558240`.
- Proof helper `0x00558240` builds opcode `0x83`, uses MD5 stream helper `0x00515570`, XOR key `w-pu6a4Es*5pA@eg+tetayAp6us6EcrE`, 16 random pad bytes, and queues 49 bytes through `0x00574bb0`.

### Ownership Analysis

Surface remains the accepted owner for DirectDraw presentation, callback, restore, minimap, blit, and copy helpers. These children manipulate Surface/DirectDraw state directly and route through [UID:0000OC][Surface](../../../../../by-file/Surface.md), which clears `88/85`.

ScreenPane owns root UI traversal, cursor, callback, flag, palette/redraw, and transition helper children. Method-shaped children that operate on ScreenPane object fields attach to [UID:0000CB][ScreenPane](../../../../../by-class/ScreenPane.md), while file-local raw helpers without a `this` receiver attach to [UID:0000NB][ScreenPane](../../../../../by-file/ScreenPane.md).

ScreenshotCapture owns the save/status/proof workflow. The functions consume the root ScreenPane/render object as data state, but EventDispatcher owns the hotkeys and Surface/ImageWriters/LodePNG/MD5/PacketBuffer/CashShopRequest own dependencies. The screenshot workflow source module is now repaired to `88/86`, and its direct in-scope children clear the gate.

The master `0001G6` stays parent-blank because assigning the whole range would merge unrelated source modules.

### Related Screenshot Gate Cleanup

B001 also repaired two directly related `ScreenshotCapture` gate rows discovered during this target:

- [UID:0000CD][ScreenshotCapture](../../../../../by-class/ScreenshotCapture.md): `82/84 -> 85/86`.
- [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](../../../../../by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md): `84/90 -> 85/90`.

These are outside the `0001G6` replacement block, but they are direct `ScreenshotCapture` children and were repaired so the screenshot parent is executable as a gated owner.

### Validator Results

Applied validator commands were run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

- `python tools\validator.py --mode file --file by-memory\0x00558680-0x00558688.UnresolvedPresentationFlagSetter.md --apply --queue-timeout 120` -> `ok: 1`
- `python tools\validator.py --mode file --file by-memory\0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md --apply --queue-timeout 120` -> `ok: 1`
- `python tools\validator.py --mode file --file by-memory\0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md --apply --queue-timeout 120` -> `ok: 1`
- `python tools\validator.py --mode file --file by-memory\0x00557840-0x00557a95.ScreenshotJpegCapturePath.md --apply --queue-timeout 120` -> `ok: 1`
- `python tools\validator.py --mode file --file by-memory\0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md --apply --queue-timeout 120` -> `ok: 1`
- `python tools\validator.py --mode file --file by-file\ScreenshotCapture.md --apply --queue-timeout 120` -> `ok: 1`
- `python tools\validator.py --mode file --file by-memory\0x00557140-0x00559aef.SurfacePresentation.md --apply --queue-timeout 120` -> `ok: 1`
- `python tools\validator.py --mode file --file by-class\ScreenshotCapture.md --apply --queue-timeout 120` -> `ok: 1`
- `python tools\validator.py --mode file --file by-memory\0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md --apply --queue-timeout 120` -> `ok: 1`

Each run also printed the existing validator-generated no-op line `autogen_cpp_noop 0000J5 auto-generated/NexusTK/util/Error.cpp no assembled code for root`; this is not an error from the edited pages.

### Changed Files

- `by-memory/0x00558680-0x00558688.UnresolvedPresentationFlagSetter.md`
- `by-memory/0x00559200-0x00559359.ScreenPanePresentationTransitionHelpers.md`
- `by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md`
- `by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md`
- `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md`
- `by-file/ScreenshotCapture.md`
- `by-class/ScreenshotCapture.md`
- `by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md`
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`
- `tools/leaser/Agents/Agent-B001/research/0001G6-SurfacePresentation.md`

No direct edit was made to `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001G6-SurfacePresentation.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001G6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
