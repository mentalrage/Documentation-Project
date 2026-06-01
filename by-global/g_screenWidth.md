*** UID:0000SU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_screenWidth

## Status

- Symbol kind: process-wide display-width global.
- IDA address: `0x0066da94` (`word_66DA94`).
- Storage range: [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md).
- Proposed type: `std::uint16_t` or signed `short` promoted at use sites.
- Initial value in IDA data: `0x0400` / `1024`.
- Confidence: strong for storage and display-width role; medium for final source-level variable name.

## Role

`g_screenWidth` is the global screen/display width used by startup, pane positioning, and render-surface sizing paths. It is paired with [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) at `0x0066da98`.

The current best source name comes from Wave2-era metadata and IDA use patterns. IDA still names the storage `word_66DA94`.

## Evidence

- `Application` startup and window creation paths read `word_66DA94` together with `word_66DA98`.
- Dialog and pane layout paths clamp right edges against `word_66DA94`.
- [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md) reads `word_66DA94` during its DirectDraw surface-packing decision.
- IDA MCP recheck on 2026-05-26 found 98 xrefs to `0x0066da94`.
- 2026-05-31 IDA MCP recheck confirms storage name `word_66DA94`, initial word value `0x0400` / `1024`, dword pair value `0x01010400` with adjacent screen/display globals, and 98 xrefs. Sampled users include `Application__Constructor`, application/window setup helpers, dialog/pane layout code, and render/GrafPort-related paths.

## Wave3 Data Note

Current generated metadata may expose a synthetic `g_maxSurfacePitch` reference around `GrafPort::UpdateRenderRegion`. IDA disassembly shows that operand is actually `word_66DA94`, this screen-width global, not a separate surface-pitch cap. Do not migrate `g_maxSurfacePitch` as a real source symbol without new evidence.

## Cross-References

- [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md)
- [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- What existed before: completion/confidence were `0/0` and reconstructable state was blank.
- What it was changed to: completion `70`, confidence `84`, and `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank.
- Summary/evidence: the 2026-05-31 IDA MCP recheck reconfirmed the exact storage, initial value, and broad screen-width xref set. The global is source-declared rebuild data, but final owner file and source-level type/name are still open, so it is intentionally not attached to a parent or emitted as C++ yet.
