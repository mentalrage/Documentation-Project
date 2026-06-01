*** UID:0001RR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Totem Frame Resources

## Status

- Confidence: strong for resource names and call site; medium for exact frame-index semantics.
- Related file: [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- Related class: [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- Evidence basis: IDA MCP decompile/string checks.

## Confirmed Resources

| Resource | String address | Used by | Notes |
| --- | --- | --- | --- |
| `TOTFRAME.EPD` | `0x0062e460` | `TotemFrame::OnPaint` | Totem/status frame image resource. |
| `NPAL7.PAL` | `0x006152ec` | `TotemFrame::OnPaint` | Palette passed to the tile-frame render helper. |

## Frame Index

`TotemFrame::OnPaint` calls [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) at `0x005bdc60` through [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) at `0x0069b4ec`. The returned value is passed as the `TOTFRAME.EPD` frame index. Exact frame-index meanings still need a focused status/totem UI pass.

## IDA MCP Evidence

- ASCII `TOTFRAME.EPD` was verified at `0x0062e460`, with an xref from `0x00598e05` inside `0x00598dd0-0x00598e3b`.
- UTF-16 `NPAL7.PAL` was verified at `0x006152ec`, with an xref from `0x00598e11` inside the same totem-frame paint helper.
- IDA decompilation of `0x00598dd0-0x00598e3b` calls `sub_5BDC60((char *)dword_69B4EC)`, passes the returned value as the `TOTFRAME.EPD` frame index, then renders with palette `NPAL7.PAL`.

## Cross-References

- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)

## Changes

- What existed before: the page was scored unevaluated and cited generated `simroot_v2` in the evidence basis.
- Changed to: scored `COMPLETION:70` / `CONFIDENCE:88`, removed generated-source evidence wording, and added direct IDA MCP evidence.
- Summary and evidence: `TOTFRAME.EPD` and `NPAL7.PAL` are directly tied to `0x00598dd0`; score remains below final because the status-to-frame mapping still needs a focused UI semantics pass.
