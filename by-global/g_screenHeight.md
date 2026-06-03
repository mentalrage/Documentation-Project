*** UID:0000ST | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_screenHeight

## Status

- Symbol kind: process-wide display-height global.
- IDA address: `0x0066da98` (`word_66DA98`).
- Storage range: [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md).
- Proposed type: `std::uint16_t` or signed `short` promoted at use sites.
- Initial value in IDA data: `0x0300` / `768`.
- Confidence: strong for storage and display-height role; medium for final source-level variable name.
- Rebuild handling: source-declared global data. The rebuilt source should declare the display-height word or compatible typed global; exact address placement is linker output.
- Autogen status: reconstructable but intentionally unattached because final owner file and source-level type/name are still open.

## Score Rationale

| Field | Value | Reason |
| --- | ---: | --- |
| Completion | 78 | The page records exact storage, initial value, role, paired width global, neighboring byte/word boundaries, live xref count, representative use families, and source-declared rebuild handling. It is not higher because final owner file, exact declaration type, and original source-facing name remain open. |
| Confidence | 88 | The 2026-06-03 live IDA pass strongly supports the address, size, initial value, paired-display-height interpretation, and usage categories across application startup, config defaults, event/dialog layout, logo/media sizing, and screenshot paths. Confidence stays below final-audit level because IDA still labels the storage `word_66DA98` and no final source declaration is emitted. |
| Reconstructable | TRUE | This is source-declared rebuild data, parallel to [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), but C++ is withheld until the owner file and type naming are settled. |

## Role

`g_screenHeight` is the global screen/display height used by startup, pane positioning, and screen-size dependent UI/render paths. It is paired with [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) at `0x0066da94`.

The current documentation name is a source-level role label derived from the paired 1024x768 display-size use pattern. IDA still names the storage `word_66DA98`.

## Evidence

- `Application` startup and window creation paths read `word_66DA98` together with `word_66DA94`.
- Dialog and pane layout paths clamp lower edges against `word_66DA98`.
- Screen-pane construction passes the width/height pair into the screen backing setup path.
- Live IDA MCP recheck on 2026-06-03 found IDB `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`, storage name `word_66DA98`, initial word `0x0300` / `768`, and 96 xrefs to `0x0066da98`.
- Representative live xrefs include `Application__Constructor` at `0x004633b7`, application initialization at `0x0046440a`, `RegistryConfig::InitializeDefaults` at `0x0048efbb`, `LogoPane` construction at `0x004f4ca0`, event/dialog root rectangle setup at `0x004a8bb9`, screenshot capture at `0x00557c03`, and alert-pane centering at `0x004a0449`.
- The exact [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md) memory page records the two-byte data item, initial value `0x0300`, and boundaries against the separate movement/layout bytes before it and map-tile dimension globals after it.
- Related capture/output code such as [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md) consumes the same width/height pair for active screen dimensions.

## Neighboring Globals

The byte globals at `0x0066da96-0x0066da97` sit between the width and height words but are separate storage. The first byte is now tracked as [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), a movement interpolation/timer scale. The second byte, `0x0066da97`, is tracked as [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), the broad EPF/current-layout selector.

The nearby [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) pair begins at `0x0066da9c`, but it describes the `48x48` map-tile pixel span, not the process display height.

## Source Placement

Keep this global paired with [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) during reconstruction. The strongest current owners are application/display startup or a small display-layout globals module referenced by [UID:0000HG][Application](by-file/Application.md), [UID:0000NB][ScreenPane](by-file/ScreenPane.md), render setup, and UI layout code.

Do not attach or emit C++ yet. A later pass should decide whether the final declaration belongs in `Application.cpp`, a display/config globals source file, or a shared screen/layout header.

## Cross-References

- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)
- [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md)
- [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)

## Changes

- Before: this page described `byte_66DA96` as a separate unresolved byte between the width and height words.
- After: the byte is identified as [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), a movement interpolation/timer scale separate from `g_screenHeight`.
- Evidence: IDA MCP xrefs show `byte_66DA96` used in movement/vector division and timer-delay scaling, not display-height storage.
- 2026-06-02: Raised metadata from `55/80` to `70/84` and marked reconstructable.
  - Before: the page had exact storage and role evidence but no explicit rebuild handling, score rationale, or source-placement note.
  - After: it matches the paired [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) documentation style, records source-declared global handling, and keeps parent/C++ blank until final owner/type decisions are made.
  - Evidence: the exact memory page [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md) confirms storage/value/boundaries, and prior IDA MCP checks recorded 96 xrefs to the height word.
- 2026-06-03: Raised metadata from `70/84` to `78/88`.
  - Reason: live IDA MCP reconfirmed the exact `0x0066da98` two-byte storage, initial value `768`, 96-xref count, neighboring byte/word boundaries, and representative use families across application startup, initialization, registry defaults, event/dialog layout, logo sizing, alert centering, and screenshot capture.
  - Boundary: `AUTOGEN_PARENT_UID` and C++ remain blank because final owner file, original declaration spelling, and exact signedness/linkage are still below the `95/95` reconstruction threshold.
