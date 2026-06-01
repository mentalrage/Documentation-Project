*** UID:0000ST | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:55 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Role

`g_screenHeight` is the global screen/display height used by startup, pane positioning, and screen-size dependent UI/render paths. It is paired with [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) at `0x0066da94`.

The current best source name comes from Wave2-era metadata and IDA use patterns. IDA still names the storage `word_66DA98`.

## Evidence

- `Application` startup and window creation paths read `word_66DA98` together with `word_66DA94`.
- Dialog and pane layout paths clamp lower edges against `word_66DA98`.
- Screen-pane construction passes the width/height pair into the screen backing setup path.
- IDA MCP recheck on 2026-05-26 found 96 xrefs to `0x0066da98`.

## Neighboring Globals

The byte globals at `0x0066da96-0x0066da97` sit between the width and height words but are separate storage. The first byte is now tracked as [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), a movement interpolation/timer scale. The second byte, `0x0066da97`, is tracked as [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), the broad EPF/current-layout selector.

The nearby [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) pair begins at `0x0066da9c`, but it describes the `48x48` map-tile pixel span, not the process display height.

## Cross-References

- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)
- [UID:0001OI][0x0066da98-0x0066da9a.g_screenHeight](by-memory/0x0066da98-0x0066da9a.g_screenHeight.md)
- [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- Before: this page described `byte_66DA96` as a separate unresolved byte between the width and height words.
- After: the byte is identified as [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), a movement interpolation/timer scale separate from `g_screenHeight`.
- Evidence: IDA MCP xrefs show `byte_66DA96` used in movement/vector division and timer-delay scaling, not display-height storage.
