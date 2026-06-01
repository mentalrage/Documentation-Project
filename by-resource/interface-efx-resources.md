*** UID:0001RE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Interface Effect Resources

## Status

- Confidence: strong for observed filenames and owning code; medium for exact DAT family/format details.
- Owner file hypothesis: [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- Evidence basis: IDA MCP UTF-16 string and xref checks; generated sources are only lead material.

## Resource Family

| Resource | Observed owner/use | Notes |
| --- | --- | --- |
| `CHREFX.EPD` | `InterfaceEfxMgr` constructor | Persistent character interface effect in old-layout manager. |
| `MAGEFX.EPD` | `InterfaceEfxMgr` constructor | Persistent magic interface effect in old-layout manager. |
| `ITEMEFX.EPD` | `InterfaceEfxMgr` constructor | Persistent item interface effect in old-layout manager. |
| `FRMLEFX.EPD` | `InterfaceEfxMgr::SpawnRandomFrameEffects` | Left-side periodic frame effect. |
| `FRMREFX.EPD` | `InterfaceEfxMgr::SpawnRandomFrameEffects` | Right-side periodic frame effect. |
| `INTEFX.PAD` | all manager-created `InterfaceEfx` instances | Palette/config resource passed into `InterfaceEfx` construction. |

## Behavior Notes

- `InterfaceEfx` stores a short effect filename and resolves it through the effect frame library during construction/playback.
- `InterfaceEfx::Play` asks the effect frame library for frame dimensions, sets the render/clip rectangle, resets the current tick, and schedules immediate update.
- `InterfaceEfxMgr::SpawnRandomFrameEffects` creates `FRMLEFX.EPD` and `FRMREFX.EPD`, plays them only when the client option flag at `g_clientStateBase + 0x28de5e` is nonzero, then schedules the next frame-effect cycle after a randomized 120000-299999 ms delay.

## IDA MCP Evidence

- `INTEFX.PAD` at `0x0061c6c0` xrefs from `0x004e9d00-0x004e9e78`, `0x004e9f40-0x004ea05e`, and `0x004ea130-0x004ea202`.
- `CHREFX.EPD`, `MAGEFX.EPD`, and `ITEMEFX.EPD` at `0x0061c6d8`, `0x0061c6f0`, and `0x0061c708` xref into the persistent interface-effect construction paths.
- `FRMLEFX.EPD` and `FRMREFX.EPD` at `0x0061c720` and `0x0061c738` xref from `0x004e9f40-0x004ea05e`, matching the randomized frame-effect spawn path.

## Cross-References

- [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md)
- [UID:00006N][InterfaceEfx](by-class/InterfaceEfx.md)
- [UID:00006O][InterfaceEfxMgr](by-class/InterfaceEfxMgr.md)
- [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md)

## Changes

- Before: page was scored `0/0` and cited generated source as evidence.
- Changed to: `COMPLETION:70`, `CONFIDENCE:85`, with IDA MCP resource string addresses and xrefs.
- Evidence: IDA MCP UTF-16 byte search and xrefs for `INTEFX.PAD`, `CHREFX.EPD`, `MAGEFX.EPD`, `ITEMEFX.EPD`, `FRMLEFX.EPD`, and `FRMREFX.EPD`.
