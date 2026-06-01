*** UID:0002CF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_movementSubstepScale

## Status

- Symbol kind: process-wide movement interpolation scale byte.
- IDA address: `0x0066da96` (`byte_66DA96`).
- Storage range: [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md).
- Proposed type: `std::uint8_t` or `unsigned char`.
- Initial value in IDA data: `1`.
- Confidence: strong for movement/interpolation role; medium for final source-level variable name.

## Role

`g_movementSubstepScale` controls the fine-grained movement and animation substep scale used by map-object, attached-object, and local-player movement paths. With the initial value `1`, a tile-direction vector is divided into four substeps. The same value is used to divide timer delays so higher values would create more substeps at shorter intervals rather than simply slowing movement.

The name is descriptive, not recovered original source evidence. Keep the IDA alias `byte_66DA96` in notes until startup/config writes are fully reviewed.

## Evidence

- IDA data inspection reports a one-byte item at `0x0066da96` with initial value `1` and 23 xrefs.
- Map and attached-object position helpers divide direction vectors by `4 * byte_66DA96`, including `MapPane` object-position helpers at `0x005055e0`, `0x00506980`, and `0x0050b080`, attached-object helpers at `0x00538600`, `0x005386c0`, `0x0053c700`, and `0x0053c810`, and `LivingObjectPane::UpdateScreenPosition` at `0x005a88d0`.
- Local-player movement timer setup divides frame delays by `byte_66DA96` at `0x005a36f0`, `0x005a3770`, and `0x005ab410`.
- `UserPane::OnAnimationStep` at `0x005a83b0` uses `4 * byte_66DA96` as the movement subframe modulus and also divides movement timer delays by the same byte.

## Ownership Notes

This global is a shared movement/rendering configuration value rather than part of the screen width/height pair. It sits between `g_screenWidth` and `g_useEpfAssets` in `.data`, but xrefs tie it to movement interpolation, attached-object placement, and player animation timing.

Likely source ownership is a low-level map/movement configuration module or an application startup/config unit that initializes global movement constants. Keep exact source-file placement open until the writer or configuration parser is recovered.

## Cross-References

- [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md)
- [UID:0001OG][0x0066da94-0x0066da96.g_screenWidth](by-memory/0x0066da94-0x0066da96.g_screenWidth.md)
- [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
