// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NT
// Source by-file doc: by-file/SoftwareBlend16.md
// UID:00020C | by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md | Completion:88 | Confidence:91
void ByteSpanCopyRows(const unsigned char *source,
                      int sourceStride,
                      unsigned char *destination,
                      int destinationStride,
                      int width,
                      int rowCount);

// UID:00020D | by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md | Completion:88 | Confidence:91
void ByteSpanAddRows(const unsigned char *source,
                     int sourceStride,
                     unsigned char *destination,
                     int destinationStride,
                     int width,
                     int rowCount);

// UID:00020E | by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md | Completion:88 | Confidence:91
void ByteSpanSubtractRows(const unsigned char *source,
                          int sourceStride,
                          unsigned char *destination,
                          int destinationStride,
                          int width,
                          int rowCount);

// UID:0003ZP | by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md | Completion:93 | Confidence:95
void ConvertRgb565ToRgb555Pixels(unsigned short* pixels, int pixelCount);
