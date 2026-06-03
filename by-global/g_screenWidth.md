*** UID:0000SU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Rebuild handling: source-declared global data. The rebuilt source should declare the display-width word or compatible typed global; exact address placement is linker output.
- Autogen status: reconstructable but intentionally unattached because final owner file and source-level type/name are still open.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 78 | The page records exact storage, initial value, role, paired height global, neighboring byte/word boundaries, live xref count, representative use families, and source-declared rebuild handling. It is not higher because final owner file, exact declaration type, and original source-facing name remain open. |
| Confidence | 88 | The 2026-06-03 live IDA pass strongly supports the address, size, initial value, paired-display-width interpretation, and usage categories across application startup, config defaults, event/dialog layout, logo/media sizing, render packing, and screenshot paths. Confidence stays below final-audit level because IDA still labels the storage `word_66DA94` and no final source declaration is emitted. |
| Reconstructable | TRUE | This is source-declared rebuild data, parallel to [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md), but C++ is withheld until the owner file and type naming are settled. |

## Role

`g_screenWidth` is the global screen/display width used by startup, pane positioning, and render-surface sizing paths. It is paired with [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) at `0x0066da98`.

The current documentation name is a source-level role label derived from the paired 1024x768 display-size use pattern. IDA still names the storage `word_66DA94`.

## Evidence

- `Application` startup and window creation paths read `word_66DA94` together with `word_66DA98`.
- Dialog and pane layout paths clamp right edges against `word_66DA94`.
- [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md) reads `word_66DA94` during its DirectDraw surface-packing decision.
- Live IDA MCP recheck on 2026-06-03 found IDB `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`, storage name `word_66DA94`, initial word `0x0400` / `1024`, and 98 xrefs to `0x0066da94`.
- Representative live xrefs include `Application__Constructor` at `0x004633be`, application initialization at `0x00464421`, `RegistryConfig::InitializeDefaults` at `0x0048efae`, `LogoPane` construction at `0x004f4ca8`, event/dialog root rectangle setup at `0x004a8ba9`, screenshot capture at `0x00557bf7`, and alert-pane centering at `0x004a0458`.
- The adjacent bytes remain distinct globals: `byte_66DA96` starts at `0x0066da96`, `byte_66DA97` starts at `0x0066da97`, and [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md) begins at `0x0066da98`.

## Alias/Operand Note

Some generated docs may expose a synthetic `g_maxSurfacePitch` reference around `GrafPort::UpdateRenderRegion`. IDA disassembly shows that operand is actually `word_66DA94`, this screen-width global, not a separate surface-pitch cap. Do not migrate `g_maxSurfacePitch` as a real source symbol without new live evidence.

## Cross-References

- [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md)
- [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- What existed before: completion/confidence were `0/0` and reconstructable state was blank.
- What it was changed to: completion `70`, confidence `84`, and `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank.
- Summary/evidence: the 2026-05-31 IDA MCP recheck reconfirmed the exact storage, initial value, and broad screen-width xref set. The global is source-declared rebuild data, but final owner file and source-level type/name are still open, so it is intentionally not attached to a parent or emitted as C++ yet.
- 2026-06-03: Raised metadata from `70/84` to `78/88`.
  - Reason: live IDA MCP reconfirmed the exact `0x0066da94` two-byte storage, initial value `1024`, 98-xref count, neighboring byte/word boundaries, and representative use families across application startup, initialization, registry defaults, event/dialog layout, logo sizing, alert centering, and screenshot capture.
  - Boundary: `AUTOGEN_PARENT_UID` and C++ remain blank because final owner file, original declaration spelling, and exact signedness/linkage are still below the `95/95` reconstruction threshold.
