*** UID:0000SW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_useEpfAssets / byte_66DA97

## Status

- Confidence: strong for address and broad mode-selector role; exact original name unknown.
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

## Naming Rule

When a recovered source file emits a new global name for this address, normalize the documentation to this page and record the alias only as generated-source evidence.

Known misleading aliases:

| Alias | Problem |
| --- | --- |
| `g_useHighResLayout` | Common in current `simroot_v2`, but it narrows the byte to layout geometry and can mislead branch labels; the same address also selects EPF/EPD resources and render callbacks. |
| `g_attachmentModeFlag` | Observed again on 2026-05-25 in `class_AttachedObjectPaneHelper_53AEC0.cpp`; the byte has hundreds of non-attachment xrefs. |
| `g_uiLayoutMode` | Captures layout behavior but does not capture the repeated EPF/EPD asset selection branches. |

2026-05-26 recheck: `simroot_v2/class_AttachedObjectPaneHelper_53AEC0.cpp` still emits `g_attachmentModeFlag`, but IDA still reports broad cross-subsystem xrefs. Keep normalizing that alias to this page.

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
