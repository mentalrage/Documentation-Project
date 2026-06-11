*** UID:0000SW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_useEpfAssets / byte_66DA97

## Status

- Confidence: strong for address, one-byte storage, initial value, and broad mode-selector role; exact original name and source-file owner remain unknown.
- Address: `0x0066da97`
- Exact memory: [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md).
- IDA name: `byte_66DA97`
- Generated aliases observed: `g_useEpfAssets`, `g_useHighResLayout`, `g_uiLayoutMode`, `g_attachmentModeFlag`
- Likely owner: startup/config or UI shell initialization, not any single pane.

## Purpose

This byte selects between the current EPF/high-layout UI asset path and the older legacy EPD/layout path. It is widely read by UI, render, dialog, and map-overlay code.

Use `g_useEpfAssets` as a readable documentation alias until the original symbol is recovered. Treat narrow generated aliases such as `g_attachmentModeFlag` as local misnamings when the same address is used outside that subsystem.

## Evidence Notes

- IDA reports the symbol name `byte_66DA97` at `0x0066da97`.
- IDA data inspection on 2026-05-26 reports a one-byte item initialized to `1`.
- IDA MCP `py_eval` on 2026-05-24, 2026-05-25, and 2026-05-26 found 366 xrefs to this byte.
- IDA MCP decompilation of [UID:0000O5][StartupWindow](by-file/StartupWindow.md) constructor `0x005807d0` shows `byte_66DA97 = 1`.
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) uses the byte as the main new/legacy layout selector.
- [UID:0000JX][HourPane](by-file/HourPane.md) uses `byte_66DA97 == 1` for `TIME.EPF`/`TIME.PAL`, and the else branch for `TIME.EPD`.
- [UID:0000HO][BackPane](by-file/BackPane.md) uses the byte to choose `FRAME.PAL` versus `NPAL5.PAL`.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)'s detach registry helper only clears the type-8 attachment slot in `byte_66DA97 == 1` mode.
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md) currently documents the constructor as forcing this mode byte to `1`.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0066da97` is a one-byte `.data` item named `byte_66DA97`, initialized to `1`, with 366 data xrefs. The only exact write found is `StartupWindow__Constructor` at `0x005807f3`, while sample reads compare the byte against `1` across early UI/resource/render paths.
- 2026-06-06 IDA MCP `py_eval` reconfirms the same one-byte item, initial value `1`, and 366 data xrefs. The local neighborhood bytes at `0x0066da90-0x0066daa2` are `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00`, keeping this byte distinct from `g_fpsDebugActive`, `g_screenWidth`, [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), and `g_screenHeight`.
- Representative 2026-06-06 xrefs include `0x004cf020` in HourPane resource selection, `0x004f7d40` and `0x004f8aaf` in `InitializeMainUiGraph`, `0x0053aee5` in attached-object detach cleanup, `0x00574de0` in the send-position helper, `0x005807f3` in `StartupWindow__Constructor`, `0x00598b50` in TimerPane digit drawing, `0x005ae3bf` and `0x005b7c5f` in spell-input cleanup, and `0x005c12ea` in weather-layer construction.
- 2026-06-07 A004 IDA MCP `py_eval` reconfirmed bytes `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00` at `0x0066da90-0x0066daa8`, `byte_66DA97` item size `1`, value `1`, `366` xrefs across `248` functions, predecessor boundary [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), and successor boundary [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md).
- The exact storage child [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md) is documented here as the direct one-byte storage evidence anchor after both child and parent reached the corrected `85/85` gate. The memory child leaves `AUTOGEN_PARENT_UID` blank because generated memory coverage currently rejects by-global parents as `autogen_parent_unknown`.

## Naming Rule

When a recovered source file emits a new global name for this address, normalize the documentation to this page and record the alias only as generated-source evidence.

Known misleading aliases:

| Alias | Problem |
| --- | --- |
| `g_useHighResLayout` | Common in current `simroot_v2`, but it narrows the byte to layout geometry and can mislead branch labels; the same address also selects EPF/EPD resources and render callbacks. |
| `g_attachmentModeFlag` | Observed again on 2026-05-25 in `class_AttachedObjectPaneHelper_53AEC0.cpp`; the byte has hundreds of non-attachment xrefs. |
| `g_uiLayoutMode` | Captures layout behavior but does not capture the repeated EPF/EPD asset selection branches. |

2026-05-26 recheck: `simroot_v2/class_AttachedObjectPaneHelper_53AEC0.cpp` still emits `g_attachmentModeFlag`, but IDA still reports broad cross-subsystem xrefs. Keep normalizing that alias to this page.

## Source Ownership

Keep `AUTOGEN_PARENT_UID` blank for now. `StartupWindow` is the observed initializer, but the read set spans startup, main UI graph selection, pane resource selection, attached-object cleanup, input/dialog state cleanup, packet-send side effects, and weather/map/layer construction. That spread supports a process-wide UI/render mode declaration, not a confidently owned file-local global.

## Score Rationale

Completion is raised to 86 because the page now documents exact storage, initial byte value, 366-ref count, 248-function spread, neighboring global boundaries, representative cross-subsystem consumers, alias normalization, exact memory-child relationship, and why the parent remains blank.
Confidence is raised to 90 because fresh IDA MCP confirms the one-byte storage, strict boundary, initialization value, and broad EPF/current-layout selector role already supported by linked UI/resource/render docs. It remains below final-source quality because the original source name, declaration owner, and emitted declaration are still unresolved.

## Cross-References

- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)
- [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)

## Changes

- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:84`, and `RECONSTRUCTABLE:TRUE`, with parent left blank.
  - Summary/evidence: IDA MCP reconfirms the one-byte storage, initial value, wide xref set, and StartupWindow write. Parent/source-file attachment remains open because the global is a broad UI asset-mode selector rather than clear ownership by a single pane or subsystem file.
- 2026-06-06 A008 alias/source-owner refresh:
  - What existed before: the page documented the broad role but did not record current representative xrefs or an explicit source-owner decision.
  - Changed to: `84/88`, added current IDA item/neighborhood/xref evidence, and kept parent blank.
  - Summary/evidence: live IDA MCP reconfirmed 366 xrefs and representative users across startup, UI graph, HourPane, attached-object, packet-send, TimerPane, spell-input, and weather/layer paths. The broad spread supports normalizing aliases to `g_useEpfAssets` while leaving original owner/name unresolved.
- 2026-06-07 A004 Batch 027:
  - Before: score `84/88`, just below the corrected assignment gate.
  - Changed to: score `86/90`, added fresh IDA MCP neighborhood/xref/function-spread evidence, and recorded [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md) as the exact assigned memory child.
  - Boundary: this by-global page remains unassigned upward because `StartupWindow` is only the observed writer and the read set is too broad for a source-file owner decision.
- 2026-06-07 A001 Batch070 coverage-error repair:
  - Kept score `86/90` and changed the memory-child wording from active autogen assignment to direct by-global evidence anchor.
  - Validation continued to report generated memory coverage error `autogen_parent_unknown` for `0001OH -> 0000SW`; matching neighboring one-byte global repairs, the exact memory child now leaves `AUTOGEN_PARENT_UID` blank until by-global parents are supported or a direct source-file owner is proven.
