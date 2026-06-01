*** UID:0000P9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# WebBoardDialog

## Status

- Confidence: strong for active/old web-board behavior; medium for final source-file placement.
- Proposed module: `ui/dialogs/WebBoardDialog.cpp`, with browser dependencies from [UID:0000HV][Browser](by-file/Browser.md).
- Current recovered sources: `source-3/simroot_v2/class_WebBoardDialog.cpp`; stale old-variant helpers currently emitted in `source-3/simroot_v2/class_RankingDialog.cpp`.

## File Role

`WebBoardDialog.cpp` is a split candidate for the browser-backed in-game board dialog family. The active `WebBoardDialog` derives from the browser pane/dialog family, creates an embedded `BrowserControlPane`, and routes packet-driven or direct URL startup into board response/browser loading. The older `WebBoardDialogOld` variant uses the same browser control path but wraps it in fixed `WEBBOARD.EPD` / `WEBBOARD.PAD` art.

## Proposed Contents

| Entity | Current range | Current generated file | Role |
| --- | --- | --- | --- |
| [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md) | `0x0046d050-0x0046e25b`, with destructor companions at `0x0046d330`, `0x00470790`, and small thunks | `class_WebBoardDialog.cpp` plus un-emitted IDA-only methods | Active browser-backed board dialog, singleton `0x0067ab9c`, mode-dependent layout, direct URL loading, packet opcode `0x73` response handling, URL escaping, and vtable-backed render/layout helpers. |
| [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) | `0x0046e260-0x0046efda`, with destructor companions at `0x0046e8c0`, `0x004707f0`, and small thunks | currently mis-emitted through `class_RankingDialog.cpp` plus un-emitted raw helpers at `0x0046e260`, `0x0046e4c0`, `0x0046ea30`, and `0x0046ee80` | Legacy fixed-art web board dialog using `WEBBOARD.EPD`/`WEBBOARD.PAD`, singleton `0x0067aba0`, browser control, opcode `0x73`, timer `0x572`, unxrefed browser-control teardown and initial request helpers, raw mode/control rectangle helper, raw old URL escape helper, destructor, and old browser-control close/reposition callbacks. |

## Evidence Notes

- IDA MCP on 2026-05-24 confirms `0x0046d050` size `0x2d4`, `0x0046d480` size `0x23`, and `0x0046d580` size `0x4e3`.
- IDA MCP confirms `0x0046e2a0` size `0x216`, `0x0046e640` size `0x27e`, `0x0046ea00` size `0x23`, and `0x0046eaa0` size `0x3da`.
- IDA MCP on 2026-05-27 confirms [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md): active vtable slots at `0x00613620`, `0x0061362c`, and `0x00613630`, raw active URL escape helper at `0x0046da70`, and raw old teardown-like helper at `0x0046e260`.
- IDA MCP on 2026-05-27 confirms [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md), a raw old-mode rectangle helper with embedded switch tables before the old constructor.
- IDA MCP on 2026-05-27 confirms [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md), a destructor plus old-dialog vtable callbacks at `0x006136d4` and `0x00613704` for browser-control shutdown/reposition behavior.
- IDA MCP on 2026-05-27 confirms [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md), a raw old-dialog request helper that sends opcode `0x73`/zero payload and starts timer `0x572`.
- IDA MCP on 2026-05-27 confirms [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md), a raw old-dialog URL escape helper using the old `0x0067acb0+` escape table state.
- `simroot_v2/class_WebBoardDialog.cpp` currently emits only the active constructor and globals, so it is incomplete for source migration.
- `simroot_v2/class_RankingDialog.cpp` currently emits `WebBoardDialogOld_Constructor` and `HandleWebBoardResponse` under `RankingDialog`; this is generated owner pollution, not original ranking source ownership.

## Boundary Notes

Behavior is board-specific, while implementation dependencies are browser-specific. Keep this as `ui/dialogs/WebBoardDialog.cpp` unless later import provenance proves a browser-folder source. The browser module should own generic `BrowserPane` / `BrowserControlPane` infrastructure; this file should own the board-specific packet, singleton, resource, and layout code. Do not migrate the old-variant helpers into [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) just because the generated file currently places them there.

## Cross-References

- [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md)
- [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md)
- [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md)
- [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md)
- [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md)
- [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md)
- [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md)
- [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md)
- [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md)
- [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md)
- [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md)
- [UID:0000SQ][g_pWebBoardDialog](by-global/g_pWebBoardDialog.md)
- [UID:0000SR][g_pWebBoardDialogOld](by-global/g_pWebBoardDialogOld.md)
- [UID:0001RT][webboard-dialog-resources](by-resource/webboard-dialog-resources.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)

## Changes

- 2026-05-27: The proposed contents table previously ended active `WebBoardDialog` at `0x0046da63` and started `WebBoardDialogOld` at `0x0046e2a0`. Updated the active row to include the documented `0x0046da70-0x0046e25b` URL escape/render helper cluster, and updated the old row to include the raw `0x0046e260-0x0046e294` teardown-like helper. IDA MCP confirms active WebBoardDialog vtable slots at `0x00613620`, `0x0061362c`, and `0x00613630`, plus raw helper bytes at `0x0046da70` and `0x0046e260`; the exact evidence is recorded in [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md).
- 2026-05-27: The `WebBoardDialogOld` row previously omitted the raw `0x0046e4c0-0x0046e63c` mode/control rectangle helper. Added it to the old helper coverage after IDA MCP showed a complete raw helper with switch tables between the old layout refresh helper and old constructor. Evidence is recorded in [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md).
- 2026-05-27: The `WebBoardDialogOld` row previously left `0x0046e8be-0x0046ea00` as an unknown coverage gap. Added destructor and old-dialog close/reposition callback coverage for `0x0046e8c0-0x0046e9f5`, with surrounding bytes classified as padding. Evidence is recorded in [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md).
- 2026-05-27: The `WebBoardDialogOld` row previously left `0x0046ea23-0x0046eaa0` as an unknown coverage gap. Added the raw `0x0046ea30-0x0046ea99` initial request/timer helper and classified the surrounding bytes as padding. Evidence is recorded in [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md).
- 2026-05-27: The `WebBoardDialogOld` row previously ended at the response parser and left `0x0046ee7a-0x0046efe0` unknown. Added the raw `0x0046ee80-0x0046efda` old URL escape helper and classified the surrounding bytes as padding. Evidence is recorded in [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md).
- 2026-05-30: Grading changed from unevaluated `0/0` to `80/84`.
  - Before: page had the active/old web-board source-family inventory but no completion/confidence score.
  - After: score reflects the broad IDA-backed method coverage, corrected active/old helper inventory, singleton/global links, and clear source ownership away from generated RankingDialog pollution.
  - Evidence: linked by-memory pages cover the active constructor, virtual companions, packet/request helpers, response handler, URL escape/render helpers, old constructor, old response handler, and raw old helper gaps; current `simroot_v2/ui/dialogs/WebBoardDialog.cpp` remains incomplete/generated, so completion stays below higher-confidence source-family pages.
- 2026-05-31: Projected reconstruction path changed from blank to `NexusTK/ui/dialogs/`.
  - Before: validator reported the by-file root as missing `PROPOSED_RECONSTRUCTION_PATH`.
  - After: the page stages as `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ui/dialogs/WebBoardDialog.cpp`, and this page's boundary notes keep the board-specific browser-backed dialog implementation under `ui/dialogs/`.
