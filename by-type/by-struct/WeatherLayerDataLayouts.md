*** UID:0001WJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WeatherLayerDataLayouts

## Status

- Confidence: strong for fields directly indexed by IDA-verified weather code; medium for final source type names and exact original declaration placement.
- Likely owner header: `map/WeatherLayerPane.h` or a private weather-layer `.cpp` header block.
- Autogen parent: attached to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md); the file scores `86/80` and this multi-layout page scores `80/88`, so both sides satisfy the 80/80 parent gate.
- Global storage notes: [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- Exact memory docs: [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md), and [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)

## Layout Hypotheses

```cpp
struct RainStreakCoord {
    short x;
    short y;
    short length;
};

struct RainSplashCoord {
    short x;
    short y;
};

struct SnowParticleEntry {
    int left;
    int top;
    int right;
    int bottom;
    signed char type;
    unsigned char pad[3];
};

struct SnowPatternDescriptor {
    int reserved0;
    const void* pattern;
    int reserved8;
    int frameCount;
    RECT sourceRect;
    int reserved20;
    int reserved24;
};
```

## Evidence Notes

- `RainingLayerPane::OnPaint` at `0x005c1460` indexes streak tables as three 16-bit values and splash tables as x/y 16-bit pairs.
- `RainingLayerPane::DrawRainOnTarget` at `0x005c1810` uses the same layouts against the alternate target/minimap coordinate tables.
- 2026-05-24 IDA refs for rain tables: main-view tables `0x00670528`, `0x006706d8`, and `0x00670730` are referenced from `0x005c1460`; target/minimap tables `0x006702c8`, `0x00670478`, and `0x006704d0` are referenced from `0x005c1810`.
- `SnowingLayerPane` methods advance snow particle entries by 20 bytes, with four integer rectangle fields followed by a one-byte type/pattern index.
- Snow descriptor initialization walks two records by `10` dwords each, matching a 40-byte descriptor with a pattern pointer, frame count, and source rect.
- 2026-05-24 IDA refs for snow tables: threshold/size/pattern data are at `0x00670785`, `0x00670788`, `0x0067078c`, `0x0067079c`, `0x006707ad`, `0x006707b0`, `0x006707b4`, and `0x006707c4`; descriptor/guard storage is at `0x0069bf98`, `0x0069bfe8`, `0x0069bff0`, and `0x0069c040`.
- 2026-05-25 IDA MCP byte-range review shows the snow pattern byte data ends at `0x006707d0`, where unrelated string data begins. The first threshold table uses `0x00670784` as the lower-bound sentinel while direct xrefs land at `0x00670785`.
- 2026-05-31 IDA MCP recheck:
  - `lookup_funcs` confirms modeled weather users at `0x005c1460`, `0x005c1810`, `0x005c1c80`, `0x005c1f50`, and `0x005c20e0`, while table/storage addresses are data, not functions.
  - `xrefs_to` confirms the six rain table starts are referenced only from the main-view and target/minimap rain drawing functions listed above.
  - `decompile` shows the rain streak index as `3 * (i + 24 * frame)` over 16-bit words and splash indices as `2 * (i + 7 * frame)`, matching `RainStreakCoord` and `RainSplashCoord`.
  - `decompile` shows snow particle entries advanced by 20 bytes, with four dword rectangle fields followed by the one-byte type/pattern index at offset `+16`.
  - `decompile` shows snow descriptor arrays initialized as two records advanced by 10 dwords each, matching 40-byte `SnowPatternDescriptor` records.
  - `get_bytes` confirms `0x00670784-0x006707d0` contains the threshold/size/pattern bytes and that `0x006707d0` immediately precedes unrelated `Bogus message code %d` string data.

## Open Questions

- Whether the rain table stride of 24 streak slots per frame represents padded data, unused entries, or a larger animation table where only 18 entries are drawn.
- Whether `SnowPatternDescriptor` is a shared render descriptor type also used outside snow effects.
- Final names for the active-map byte at `g_activeMapPane + 0x3f0`; weather code treats it as render suppression, while other input paths also test the same byte.

## Cross-References

- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md)
- [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md)
- [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)
- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md)
- [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)

## Changes

- 2026-06-06: Attached the weather data layouts to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md). Scores remain `80/88`; the file-level parent covers the rain/snow descriptor families and shared weather globals better than one pane class.
- 2026-05-31 IDA-verified scoring:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and useful but ungraded layout hypotheses.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `decompile`, and `get_bytes` verified the rain table strides, snow particle entry stride, snow descriptor stride, snow byte-table boundary, and table users. Scores remain below final-source level because original type names, header placement, and a few table naming/stride questions are still open.
