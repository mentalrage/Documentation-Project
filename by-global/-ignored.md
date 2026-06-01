*** UID:0000PF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Ignored Global Symbols

Use this file to list confirmed globals, thunks, callback slots, or data symbols that should not be reconstructed as NexusTK-owned state.

Add entries only after verifying the symbol is compiler/runtime support, third-party data, Windows import glue, a duplicate alias, or a stale generated record. Include address, name/alias, reason, evidence, and replacement owner.

## Ignored Entries

- `g_browserRuntime` - generated BrowserControlPane alias for [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) storage at `0x0067a7cc`.
  - Why ignored: IDA resolves the browser dispatch fallback to `dword_67A7CC`, the canonical root [UID:0000NB][ScreenPane](by-file/ScreenPane.md) singleton pointer, not a separate browser-owned global.
  - Evidence: [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md) and [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) record IDA `py_eval` evidence: `0x0067a7cc` is a 4-byte `.data` item with 145 xrefs, `BrowserControlPane::HandleBrowserDispatchEvent` at `0x0046c960-0x0046caf0` reads it, and no IDA name contains `browserRuntime`.
  - Replacement owner: [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) in [UID:0000NB][ScreenPane](by-file/ScreenPane.md); browser code should use a typed local view or accessor.
  - Data issue: [wave3 data issues](../wave3_data_issues.md).

- `g_pScreenEffecterList` - stale generated global-data alias for `dword_69B364` / `0x0069b364`.
  - Why ignored: live IDA shows the backing storage is a broadly used UI layer/context slot, not a screen-effecter-list object and not a `SolidColorFilterEffecter`-owned global.
  - Evidence: [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) records IDA MCP xrefs showing startup assignment at `0x004f6268`, layer registration at `0x004f6338`/`0x004f6340`, shutdown removal/release/clear at `0x004f64f3`/`0x004f64ff`/`0x004f6584`/`0x004f6594`, broad [UID:00019K][0x004f7d10-0x004f8b2a.InitializeMainUiGraph](by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md) pane setup use, and the `SolidColorFilterEffecter` consumer at `0x0055ae9a`.
  - Replacement owner: recover and name `dword_69B364` with the [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) under [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), alongside sibling layer slots `dword_69B368`, `dword_69B36C`, `dword_69B374`, `dword_69B378`, and `dword_69B37C`.
  - Data issue: [wave3 data issues](../wave3_data_issues.md).

- `g_uiTileRenderer` - generated global-data alias in `source-3/simroot_v2/class_BlueAlertPane.cpp`.
  - Why ignored: no confirmed backing global storage; current Wave3 output synthesizes an object-style renderer name from `BlueAlertPane` draw-call patterns.
  - Evidence: [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md) records IDA MCP decompile/disassembly evidence for `0x00500d70` and `0x00500e20`: the real code uses [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `dword_67A744`, `ResourceLayoutTable::LookupLayoutEntry` at `0x004d02f0`, and the shared [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) callbacks such as `dword_69B3E8` / `dword_69B3EC`. Current `class_BlueAlertPane.meta_wave3` also leaves `g_uiTileRenderer` without memory ranges and marks it incomplete.
  - Replacement owner: keep resource lookup with [UID:0000K2][ImageLib](by-file/ImageLib.md) / [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), and render dispatch with [UID:0000OC][Surface](by-file/Surface.md) / [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md). [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) is only a consumer selecting `BDFRAME.EPF` frame ids.
  - Data issue: [wave3 data issues](../wave3_data_issues.md).

- `g_pfnLockSurface` - generated alias for `dword_69B3FC` / [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) callback-table slot.
  - Why ignored: the storage is a slot in the shared surface render callback table, not a standalone EPFImageControlPane-owned global. Reconstructing a separate `g_pfnLockSurface` symbol would duplicate the table slot and preserve a generated callsite-biased name.
  - Evidence: 2026-05-31 IDA MCP `py_eval` reports `0x0069b3fc` as a 4-byte `.data` slot named `dword_69B3FC`, initialized to `0xffffffff`, with 206 data xrefs. The direct writes are the surface/render initializer choosing callback targets at `0x00558770`, `0x00558bc6`, and `0x00558ee2`. [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md) records the EPF call-shape caveat.
  - Replacement owner: [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) and [UID:0000OC][Surface](by-file/Surface.md).
