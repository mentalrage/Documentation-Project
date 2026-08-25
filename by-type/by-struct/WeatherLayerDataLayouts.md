*** UID:0001WJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RainStreak and RainSplash emit with UID0001ON; the exact unsigned snow arrays emit with [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md); this support page does not duplicate either private CPP body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_WEATHERLAYERPANE_H
#define NEXUSTK_MAP_WEATHERLAYERPANE_H

#include "../render/EPFTileContext.h"
#include "../ui/core/Pane.h"

struct SnowParticleEntry
{
    RectBounds bounds;
    unsigned char type;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WeatherLayerDataLayouts

## Status

- Confidence: very strong for exact rain fields/types/dimensions, the exact unsigned snow threshold/size/pattern storage, the constructor-proven `SnowParticleEntry` layout, and the exact `SnowingLayerPane` extent; the separate descriptor's original spelling and wider sharing remain less certain.
- Current declaration placement: private rain implementation types stay beside UID0001ON's arrays in `map/WeatherLayerPane.cpp`; six private mutable snow arrays emit from UID0001OO in the same CPP without a public struct/header declaration; `SnowParticleEntry` remains source-ready in `WeatherLayerPane.h` before `SnowingLayerPane`. `SnowPatternDescriptor` remains a support hypothesis pending its own source closure.
- Owner/emitter route: attached to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), the weather-layer source-family root that now clears the strict route gate.
- Global storage notes: [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- Exact memory docs: [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md), and [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)

## Layout Hypotheses

Exact rain types are emitted only by [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md); this support page records their field contracts without duplicating C++ outside the formal header.

| Type | Size | Field layout | Status |
| --- | ---: | --- | --- |
| `RainStreak` | 6 bytes | `+0x00 short x`, `+0x02 short y`, `+0x04 short length` | Exact signed-short implementation type. |
| `RainSplash` | 4 bytes | `+0x00 short x`, `+0x02 short y` | Exact signed-short implementation type. |
| `SnowParticleEntry` | 20 bytes | `+0x00 RectBounds bounds`, `+0x10 unsigned char type`, `+0x11..+0x13 natural tail padding` | Source-ready constructor dependency. The descriptive private type/member spelling is inferred, while its exact layout, width, stride, count, and padding are binary-proven. |
| `SnowPatternDescriptor` | 40 bytes | `+0x00 state/flag`, `+0x04 pattern pointer`, `+0x08 reserved`, `+0x0c frame count`, `+0x10..+0x1f source rectangle`, `+0x20/+0x24 reserved` | Strong layout hypothesis; broader sharing and original name remain unresolved. |

## 2026-08-16 Combined Header Implementation

This page is the first formal H fragment under the canonical [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) root. Direct by-file roots are prose-only generator roots, so this position-0 type fragment carries the root's single include-guard opening and its two complete-type includes before declaring `SnowParticleEntry`. The subsequent class fragments are [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md) position 10, [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) position 20, [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) position 30, and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md) position 40; the last fragment owns the size checks and single closing guard.

The source declaration intentionally omits an explicit three-byte tail-padding field. Natural alignment after `unsigned char type` produces the binary-proven `0x14` stride, preserving human-written source shape while the final typedef contract verifies the size.

| Rain array family | Exact declaration shape | Consumer |
| --- | --- | --- |
| `s_targetRainStreaks` | `RainStreak[3][24]` | `RainingLayerPane::DrawRainOnTarget` |
| `s_targetRainSmallSplashes`, `s_targetRainLargeSplashes` | `RainSplash[3][7]` each | `RainingLayerPane::DrawRainOnTarget` |
| `s_rainStreaks` | `RainStreak[3][24]` | `RainingLayerPane::OnPaint` |
| `s_rainSmallSplashes`, `s_rainLargeSplashes` | `RainSplash[3][7]` each | `RainingLayerPane::OnPaint` |

All six arrays are writable internal-linkage objects. Corresponding target/main arrays are byte-identical but physically distinct. The three four-byte zero spans between selected arrays are compiler alignment, not `RainSplash` records or source padding declarations.

| Snow array family | Exact declaration shape | Consumer and layout contract |
| --- | --- | --- |
| `s_targetSnowTypeThresholds` | `unsigned char[4]` = `{0,50,100,0}` | UID0003O2 addresses element 1 and performs unsigned interval tests; element 0 is the lower sentinel. |
| `s_targetSnowSizes` | `unsigned char[4]` = `{4,3,0,0}` | UID0003O2 uses `movzx` and adds the selected extent to left/top. |
| `s_targetSnowPatterns` | `unsigned char[2][16]` | UID0003O3 builds 4x4 and 3x3 descriptors from two fixed 16-byte slots. |
| `s_snowTypeThresholds` | `unsigned char[4]` = `{0,50,100,0}` | UID0003O1 main-view threshold family; element-1 xref with element-0 sentinel. |
| `s_snowSizes` | `unsigned char[4]` = `{4,3,0,0}` | UID0003O1 main-view particle extent lookup. |
| `s_snowPatterns` | `unsigned char[2][16]` | UID0003O1 main-view descriptor patterns; second slot ends at exact `0x006707d4`. |

Each target/main snow family is exactly 40 bytes and has SHA256 `4AD9D94FB72E08C575D44FC9CF0966944ABBD44377BDB5DB30BD6D1D1F73169E`; the complete pair is 80 bytes with SHA256 `2E9032C5A4CD7ED60F52C87263E091B59932A0B848BF69350DE157207FE565F4`. The duplicate families remain distinct because their consumers and storage addresses are distinct. The arrays are writable `.data`, not `const`, and UID0001OO owns their exact source initializers; no public `SnowPatternTables` type or header declaration is needed.

## Evidence Notes

- `RainingLayerPane::OnPaint` at `0x005c1460` indexes streak tables as three 16-bit values and splash tables as x/y 16-bit pairs.
- `RainingLayerPane::DrawRainOnTarget` at `0x005c1810` uses the same layouts against the alternate target-port coordinate tables. The supplied target has no minimap-specific caller, string, field, or data route, so the older minimap label is historical rather than current.
- 2026-05-24 IDA refs for rain tables: main-view tables `0x00670528`, `0x006706d8`, and `0x00670730` are referenced from `0x005c1460`; target-port tables `0x006702c8`, `0x00670478`, and `0x006704d0` are referenced from `0x005c1810`.
- `SnowingLayerPane` methods advance snow particle entries by 20 bytes, with four integer rectangle fields followed by a one-byte type/pattern index.
- Snow descriptor initialization walks two records by `10` dwords each, matching a 40-byte descriptor with a pattern pointer, frame count, and source rect.
- 2026-05-24 IDA refs for snow tables: threshold/size/pattern data are at `0x00670785`, `0x00670788`, `0x0067078c`, `0x0067079c`, `0x006707ad`, `0x006707b0`, `0x006707b4`, and `0x006707c4`; descriptor/guard storage is at `0x0069bf98`, `0x0069bfe8`, `0x0069bff0`, and `0x0069c040`.
- Historical 2026-05-25 byte-range review correctly established the first sentinel/interior-pointer behavior but used the old `0x006707d0` endpoint. UID0001OO now proves the exact range continues through `0x006707d4`; the former four-byte padding completes the second 16-byte main-view pattern slot.
- 2026-05-31 IDA MCP recheck:
  - `lookup_funcs` confirms modeled weather users at `0x005c1460`, `0x005c1810`, `0x005c1c80`, `0x005c1f50`, and `0x005c20e0`, while table/storage addresses are data, not functions.
  - `xrefs_to` confirms the six rain table starts are referenced only from the main-view and target-port rain drawing functions listed above.
  - `decompile` shows the rain streak index as `3 * (i + 24 * frame)` over signed 16-bit words and splash indices as `2 * (i + 7 * frame)`, matching `RainStreak` and `RainSplash`.
  - `decompile` shows snow particle entries advanced by 20 bytes, with four dword rectangle fields followed by the one-byte type/pattern index at offset `+16`.
  - `decompile` shows snow descriptor arrays initialized as two records advanced by 10 dwords each, matching 40-byte `SnowPatternDescriptor` records.
  - Historical `get_bytes` sampled only `0x00670784-0x006707d0`; the sample remains valid as a prefix, but the exact unrelated `Bogus message code %d` string begins at `0x006707d4` after four additional snow-pattern zeros.
- 2026-06-14 live IDA MCP `lookup_funcs` reconfirmed weather users: rain main draw `0x005c1460` size `0x3ac`, rain target draw `0x005c1810` size `0x3b7`, snow update/render `0x005c1c80` size `0x2cc`, snow randomize `0x005c1f50` size `0x184`, and snow render `0x005c20e0` size `0x148`.
- 2026-06-14 `xrefs_to` reconfirmed the table/user split: main rain tables `0x00670528`, `0x006706d8`, and `0x00670730` are referenced only by `0x005c1460`; target-port rain tables `0x006702c8`, `0x00670478`, and `0x006704d0` are referenced only by `0x005c1810`; snow threshold/size/pattern bytes at `0x00670785`, `0x00670788`, `0x0067078c`, `0x0067079c`, `0x006707ad`, `0x006707b0`, `0x006707b4`, and `0x006707c4` are referenced only by the snow randomize/update/render functions; descriptor and guard storage at `0x0069bf98`, `0x0069bfe8`, `0x0069bff0`, and `0x0069c040` remains confined to the two snow render paths.
- 2026-06-14 decompilation reconfirmed rain streak indexing as three 16-bit values with `18` visible streaks and `24`-slot frame stride, splash indexing as x/y 16-bit pairs with `7` entries per frame, snow particle records advanced by `20` bytes with type byte at record offset `+16`, and snow descriptor initialization as two `40`-byte records behind local static guards.
- 2026-07-22 B005 live MCP source-closure evidence proves that both rain consumers load every table word with signed extension: each method contains `23` `movsx` instructions and no `movzx` table load. The exact implementation records are therefore `RainStreak { short x; short y; short length; }` and `RainSplash { short x; short y; }`, not unsigned or raw coordinate-word arrays.
- Each `RainStreak[3][24]` frame has `18` records consumed by the draw loop followed by six real all-zero initializer records. Each `RainSplash[3][7]` frame has seven consumed records. The six-zero tail is source data inside the 24-record stride, not compiler padding.
- Pairwise target/main objects are physically distinct but byte-identical: the two streak bodies share SHA256 `93B2AE3B44CC63D2DA850BC54EA31D8EA8D8C03B72700113399F720E37BE1B5D`, the two small-splash bodies share `B17FEE48FDD44F299D88E1F1AC08C7B3AC2C88B49B1DAEA8AA96CB24D0FE2F34`, and the two large-splash bodies share `BFA5DA7310A56BE0C520666EFB8036B0F735D62F8C4FB92F8E32B583DF3EA4CA`.
- The accepted callback compiled the ordinary six declarations with locally available x86 MSVC `cl 19.44.35226.0` using `/O2 /MT /EHsc /Zp8 /Gy- /Gw-`. COFF `.data` was exactly `0x4bc` bytes with starts `+0x000/+0x1b0/+0x208/+0x260/+0x410/+0x468`, sizes `0x1b0/0x54/0x54/0x1b0/0x54/0x54`, three symbol-free four-byte zero alignment gaps, and SHA256 `DA60AF6D0283C03613FE2DA0BF0A7AD89BF4E571BFC17E7C424544D6FC8511C4`, exactly matching the executable range. The target executable records linker `14.16`; this available-toolchain test validates the required declaration-layout behavior without `__declspec(align(8))` or source padding objects.
- 2026-06-28 B009 MCP session `b009_0001Q4_20260628` resolved the descriptor helper shape for [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md). `sub_457A60` at `0x00457a60` is the descriptor default constructor: it sets dword `+0x00` to `1`, clears `+0x04`, `+0x08`, and `+0x0c`, calls `sub_4B7C50(this+4,0,0,0,0)` for the embedded rectangle, clears `+0x20` and `+0x24`, and returns `this`. `sub_4B7C50` at `0x004b7c50` writes a four-dword rectangle as left/top/right/bottom. The storage users advance descriptors by `0x28` / 40 bytes (Verified with int_convert.py), so `SnowPatternDescriptor` remains the correct descriptive layout name even though original source spelling is still unproven.

## SnowPatternDescriptor Constructor Evidence

The 2026-06-28 B009 pass strengthens the existing layout hypothesis but does not make the name final source C++. `sub_457A60` initializes each descriptor to a default state before the SnowingLayerPane methods assign the pattern pointer, frame count, and source rectangle each call. That supports this field interpretation:

- dword `+0x00`: default flag/state initialized to `1`.
- dword `+0x04`: pattern pointer, cleared by the constructor and later assigned to pattern bytes such as `0x0067078c`, `0x0067079c`, `0x006707b4`, or `0x006707c4`.
- dword `+0x08`: reserved/cleared field.
- dword `+0x0c`: frame count, cleared by the constructor and later assigned `4` or `3`.
- dwords `+0x10..+0x1f`: embedded source rectangle written by `sub_4B7C50`.
- dwords `+0x20` and `+0x24`: reserved/cleared trailing fields.

Keep the declaration in this page as a layout hypothesis. The descriptor type may be shared outside snow effects, and final header placement remains under the broader weather-layer source-family decision.

## SnowParticleEntry Target-Specific Evidence

2026-06-23 B003 first established the particle offsets from [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) in MCP session `b880584f`. That pass treated the declaration as a hypothesis because its constructor, complete object extent, and current header route were not yet closed. UID0003O0 now promotes the record to a source-ready private constructor dependency while preserving the original lexical spelling as inferred:

- MCP `lookup_funcs`, `decompile`, and `disasm` confirm target range `0x005c1f50-0x005c20d4`, length `0x184`, with MCP `get_bytes` SHA256 prefix `501c485e42127a02`.
- Adjacent padding around the randomize method confirms exact method boundaries: MCP `get_bytes` shows `0x005c1f4c-0x005c1f50` is four `0xcc` bytes and `0x005c20d4-0x005c20e0` is twelve `0xcc` bytes.
- MCP disassembly shows the method's first pass starts at `this+0x10c`, advances records by `0x14` / 20 bytes (Verified with int_convert.py), and loops `0xc8` times / 200 records (Verified with int_convert.py), confirming a 200-entry particle table.
- In the 20-entry leading refresh path, the loop tracks the type byte at `this+0x11c`, which is `this+0x10c + 0x10`.
- The refresh stores rectangle fields at record offsets `+0x00`, `+0x04`, `+0x08`, and `+0x0c`, then stores the selected one-byte type at `+0x10`; the stride leaves `+0x11..+0x13` as padding/unused bytes.
- `memmove(this+0x29c, this+0x10c, 0xe10)` shifts records 0..179 into records 20..199; `0xe10` is 3600 bytes (Verified with int_convert.py), matching 180 records at 20 bytes each. This resolves the prior possible interpretation of `this+0x29c` as a separate buffer: it is entry 20 of the same array because `0x29c - 0x10c = 0x190` / 400 bytes (Verified with int_convert.py), or `20 * 0x14`.
- The selected type indexes [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md)'s first size table at `0x00670788`; the resulting byte is added to left/top to form right/bottom, supporting `left/top/right/bottom/type` rather than separate x/y/size fields.
- Historical Snowing-pass checkpoint: the object fields at `this+0xf8`, `this+0xfc`, `this+0x100`, `this+0x104`, and `this+0x108` were then left as field-level open questions. UID0003PJ and UID0003PG later proved these offsets are inherited Weather state: byte/byte/short animation fields at `+0xf8..+0xfb` and `RectBounds m_weatherBounds` at `+0xfc..+0x10b`. UID0003O2 keeps its own C++ blank for target-specific Snowing-body reasons, not because the inherited Weather tail remains unnamed.

## 2026-07-24 UID0003O0 Snow Particle And Object Closure

- [UID:0003O0][0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor](by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md) proves a `0x10c`-byte `WeatherLayerPane` prefix followed immediately by `SnowParticleEntry m_snowParticles[200]` at `+0x10c`. The `0xfa0`-byte inline array ends at exact caller allocation and complete-object size `0x10ac`; there is no heap table or unexplained trailing storage.
- Every `0x14`-byte record contains `RectBounds bounds` at `+0x00` and one-byte `unsigned char type` at `+0x10`. The constructor calls `InitRectBounds(&entry.bounds, 0, 800, 8, 808)` and writes `entry.type = 0` for all 200 records. It does not write `+0x11..+0x13`, so those three bytes are natural tail padding rather than authored fields and must not be zeroed through value initialization or `memset`.
- The surrounding source-ready object declaration is `WeatherLayerPane : public Pane` at size `0x10c`, then `SnowingLayerPane : public WeatherLayerPane` with the one inline particle array at size `0x10ac`. Its constructor also assigns inherited `m_currentFrame = 4`, `m_frameCount = 5`, `m_timerInterval = 200`, and `m_drawOnTarget = true`; none of those fields belong inside `SnowParticleEntry`.
- Current canonical declaration/definition placement is `WeatherLayerPane.h` plus `WeatherLayerPane.cpp`. A historical dedicated `SnowingLayerPane.cpp` remains provenance only and does not block this source-ready layout. Exact private lexical spelling remains a confidence cap, not permission to retain raw offsets or omit the declaration.
- `SnowPatternDescriptor` is independent of this closure. Its wider sharing and exact original spelling remain open, so the descriptor row and constructor evidence retain hypothesis status.

## Score Rationale

Completion is `93` because the page records the exact signed rain types/declarations, exact unsigned snow threshold/size elements and paired 16-byte pattern slots, exclusive target/main consumers, physical duplication and hashes, corrected 80-byte endpoint, compiler alignment distinctions, exact object-layout acceptance evidence, selected `WeatherLayerPane.cpp` placement, source-ready `SnowParticleEntry[200]`, and exact `0x10ac` Snow object extent. Confidence is `94`: Weather/Rain declarations, the snow-array shapes, and the Snow particle/object layout are source-ready; private lexical spelling, the independent descriptor's wider sharing, and final whole-program codegen validation remain bounded caveats.

## Open Questions

- Historical rain question resolved by B005: each 24-record streak frame contains 18 drawn records followed by six explicit all-zero initializer records. They are neither inter-array padding nor an unknown larger live draw count.
- Whether `SnowPatternDescriptor` is a shared render descriptor type also used outside snow effects.
- Final names for the active-map byte at `g_activeMapPane + 0x3f0`; weather code treats it as render suppression, while other input paths also test the same byte.

## Cross-References

- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md)
- [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md)
- [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)
- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md)
- [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md)
- [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)

## 2026-07-23 UID0003PJ Weather And Rain Object Closure

- The exact inherited object tail is now source-ready as:

| Offset | Source declaration | Evidence and use |
| --- | --- | --- |
| `+0xf8` | `signed char m_currentFrame` | Weather timer signed-load/increment/reset behavior and repeated signed loads in Rain `OnPaint`; selects one of three accepted rain frames. |
| `+0xf9` | `signed char m_frameCount` | Rain constructor writes `3`; timer compares the next signed frame against this count. Historical wording that treated this as a 120-frame maximum is rejected. |
| `+0xfa` | `short m_timerInterval` | Rain constructor writes `120`; timer reschedules through the accepted timer manager. This is a millisecond interval, not a frame count or frame step. |
| `+0xfc` | `RectBounds m_weatherBounds` | Exact 16-byte rectangle written by the Weather constructor and consumed by Weather/Rain drawing contracts. |

- [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md) begins with the complete inherited `Pane` subobject and has exact extent `0x10c`. [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) derives from it, has the same `0x10c` extent, and adds no instance storage. Its constructor changes vtable state and initializes the inherited animation fields only.
- [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) proves `m_currentFrame` must remain signed and must be read at each callback argument construction. Its streak and splash table records are signed shorts; preserving signed promotion, operation order, division, and truncation is part of the layout contract.
- MapPane offset `+0x3f0` is closed as public `m_waitingForLocalPlayerStatus`, not the historical/inverted `m_hasRenderableMap` interpretation. Producers set it while local-player status is pending and clear it when status arrives; UID0003PJ fills its bounds first, then returns when this byte is nonzero.
- The accepted private implementation records remain `RainStreak` and `RainSplash`, emitted with the six exact UID0001ON arrays. The three main-view arrays are `s_rainStreaks[3][24]`, `s_rainSmallSplashes[3][7]`, and `s_rainLargeSplashes[3][7]`; target-port arrays remain physically and semantically separate under UID0003PK.
- Final source declaration order is a canonical complete `Pane.h`, then `WeatherLayerPane.h` declaring `WeatherLayerPane : public Pane` with the four fields above and `RainingLayerPane : public WeatherLayerPane` without new fields. This page does not claim that the current validator emits those headers; its formal remains a routing comment because UID0001ON owns the exact private rain record/array definitions.
- Existing Snow descriptor/particle caveats and all other weather-layout history remain unchanged. The score increase to `91/93` reflects the closed Weather/Rain tail, class extents, signed types, and MapPane gate; it does not promote unresolved Snow layouts.

## 2026-07-24 UID0003PG Constructor Layout Confirmation

Current live IDA session `supervisor_gate2b_0002OT_20260723` independently confirms that [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md) writes the exact Weather tail rather than an opaque integer block. The 257-byte constructor has SHA256 `86BF00A162D9935D3FA52F922F1E862D93E040760746D83CC7C36CE5EB0B8E09`, calls the `0xf8`-byte Pane constructor, and is called only by Rain, Snow, and Swallow constructors.

Constructor stores and cross-method consumers close the layout as follows:

| Offset/range | Source type/name | Constructor behavior | Independent confirmation |
| --- | --- | --- | --- |
| `+0xf8` | `signed char m_currentFrame` | zero | UID0003PH signed increment/wrap and Rain signed frame selection |
| `+0xf9` | `signed char m_frameCount` | zero | Rain constructor writes `3`; timer signed compare |
| `+0xfa..+0xfb` | `short m_timerInterval` | zero | Rain constructor writes `120`; timer sign-extends delay |
| `+0xfc..+0x10b` | `RectBounds m_weatherBounds` | EPF `(0,0,15*w,17*h)` or legacy `(12,14,15*w+12,17*h+14)` | exact IDA `RectBounds` four-int type and Weather/Rain consumers |

The binary coalesces the first three zero assignments into one dword store at `+0xf8`; source must retain three members because later code accesses them at their distinct signed widths. A single `int` member is rejected. The final bounds byte at `+0x10b`, exact Rain allocation `0x10c`, and Snow/Swallow first derived storage at `+0x10c` independently prove `sizeof(WeatherLayerPane)==0x10c` and `sizeof(RainingLayerPane)==0x10c`.

The source-facing constructor uses explicit bounds member assignments rather than a fabricated rectangle helper call, and inherited `ScheduleTimer(0, 0, 0, 0)` rather than a raw TimerHandler offset cast. Vptr writes at `+0`, `+0xa0`, and `+0xa4`, EH/cookie state, cleanup funclet, and returned `this` are compiler mechanics and do not alter this source layout. No separate struct block is emitted by this support page; canonical `WeatherLayerPane.h` owns the class declaration and UID0003PG owns the qualified constructor body.

## 2026-07-24 UID0003PI Inherited Direct-Target Mode Closure

[UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md) closes one inherited Pane field immediately before the Weather-owned tail without changing either class extent:

- `Pane+0xf6` is inherited bool `m_drawOnTarget`, still inside the exact `0xf8`-byte Pane prefix. It is not a Weather or Rain-added member and must not be inserted into the `+0xf8..+0x10b` Weather tail.
- `Pane::Pane` clears the byte by the word store at `0x0054454f`. Rain, Snow, and Swallow constructors are the only bounded byte-store matches and set it at `0x005c144e`, `0x005c1c63`, and `0x005c2327` respectively.
- `Layer_UpdateDirtyRegionsRecursive` at `0x004f16b2` is the unique bounded byte-read/compare match. Zero permits primary virtual `OnPaint`; nonzero bypasses generic paint for concrete weather panes that provide direct-target rendering. Separate Pane byte `+0xb4` remains visibility.
- The preferred positive source name is `m_drawOnTarget`; `m_usesDirectTargetDrawing` is a descriptive alias. Historical reserved, visibility, readiness, and raw-offset interpretations are superseded by the exact writer/reader family.
- The Rain constructor remains storage-free at `0x10c` and source-ready as three inherited assignments: `m_timerInterval = 120`, `m_frameCount = 3`, and `m_drawOnTarget = true`. Weather default construction and Rain vptr transitions are implicit compiler work rather than added source fields.

At the UID0003PI checkpoint metadata remained `91/93`. UID0003O0 subsequently closes the Snow particle declaration, exact object extent, and current header route and raises this support page to `92/93`; only private lexical provenance and the separate descriptor question remain.

## Changes

- 2026-07-26 B002 UID0001OO snow-layout callback:
  - Raised `92/93` to `93/94`, retained UID0000P8 ownership/emission, and updated the formal support marker so UID0001OO owns the exact private snow arrays without a duplicate public struct or header block.
  - Added the six unsigned array shapes, exact values, target/main consumers, fixed 16-byte pattern slots, writable linkage, 40/80-byte hashes, and corrected the historical `0x006707d0` endpoint to exact `0x006707d4`.
  - Preserved `SnowParticleEntry` as source-ready and `SnowPatternDescriptor` as a separate bounded layout hypothesis; this table closure does not over-promote the descriptor's original spelling or wider ownership.
- 2026-07-24 Agent-B005 UID0003O0 Snow layout callback:
  - Raised `COMPLETION` from `91` to `92`; preserved `CONFIDENCE:93`, owner/emitter UID0000P8, reconstructable state, and the no-duplicate-struct formal marker.
  - Promoted `SnowParticleEntry` from a layout hypothesis to a source-ready private Weather-layer declaration with exact `RectBounds` plus byte type layout, natural tail padding, 200-record inline array, constructor initialization contract, `0x10c` base prefix, and exact `0x10ac` complete Snow object extent.
  - Selected the current `WeatherLayerPane.h`/`.cpp` route while retaining the dedicated Snow file as historical provenance and preserving `SnowPatternDescriptor` as a separate unresolved hypothesis.
- 2026-07-24 Agent-B003 UID0003PI support sync:
  - Added exact inherited `Pane+0xf6` direct-target paint semantics, writer/reader addresses, preferred source naming, rejected historical alternatives, and the explicit rule that this byte is not part of the Weather tail or Rain-added storage.
  - Recorded the source-ready three-assignment Rain constructor and preserved `91/93`, the existing owner/emitter route, the private rain-array formal, and all Snow layout research.
- 2026-07-24 B001 UID0003PG source-quality callback:
  - Metadata remains current `91/93`, owner/emitter UID0000P8, reconstructable true, and no-duplicate-struct formal.
  - Corrected the stale internal `88/91` Score Rationale to current `91/93` and historicalized the pre-closure claim that inherited Weather offsets remained unnamed.
  - Added constructor-specific exact hash/caller/store evidence, full tail initialization, optimized-zero interpretation, independent `0x10c` extent proof, source-shape constraints, and ownership separation between canonical header, type support, and exact method child.

- 2026-07-22 B005 UID0001ON source-closure callback:
  - Metadata changed `85/89 -> 88/91`; owner/emitter remains [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md).
  - Replaced provisional `RainStreakCoord`/`RainSplashCoord` and out-of-header rain C++ with exact non-code field/declaration tables plus managed formal R2, while retaining all snow evidence and unresolved snow names.
  - Added signed-load proof, exact `3x24`/`3x7` dimensions, 18-plus-6 streak initializer shape, seven-entry splash frames, pairwise physical-duplication hashes, target-port naming evidence, three compiler-alignment gaps, and the accepted six-object x86 MSVC COFF layout/hash test.
- 2026-06-14 A002 Goal 2 score refresh:
  - What existed before: `80/88`, with strong weather data evidence but completion still capped at the old attachment threshold.
  - Changed to: `85/89`.
  - Historical checkpoint summary/evidence: live IDA MCP reconfirmed rain/snow user sizes, all rain table xrefs, all snow byte/descriptor xrefs, 3-word rain streak entries, 2-word splash entries, 20-byte snow particle records with type byte at `+16`, and 40-byte snow descriptor records. C++ was blank then because final type names, source split, and render callback ownership were not source-quality; the 2026-07-22 callback later resolved the rain-only type/source questions and applied R2 while retaining the snow caveats.
- 2026-06-06: Attached the weather data layouts to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md). Scores remain `80/88`; the file-level parent covers the rain/snow descriptor families and shared weather globals better than one pane class.
- 2026-05-31 IDA-verified scoring:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and useful but ungraded layout hypotheses.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `decompile`, and `get_bytes` verified the rain table strides, snow particle entry stride, snow descriptor stride, snow byte-table boundary, and table users. Scores remain below final-source level because original type names, header placement, and a few table naming/stride questions are still open.
- 2026-06-23 B003 SnowParticleEntry MCP-backed target sync:
  - Metadata unchanged.
  - Summary/evidence: incorporated [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md)'s accepted MCP session `b880584f` evidence for `this+0x10c` as record zero, `this+0x29c` as entry 20, `0xe10` as a 3600-byte / 180-record shift size (Verified with int_convert.py), and the `+0x00/+0x04/+0x08/+0x0c/+0x10` field writes.
- 2026-06-28 B009 SnowPatternDescriptor constructor sync:
  - Metadata unchanged.
  - Summary/evidence: added accepted [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) MCP session `b009_0001Q4_20260628` evidence for descriptor constructor `sub_457A60`, rectangle setter `sub_4B7C50`, 40-byte descriptor stride, default-cleared fields, pattern pointer/frame-count/source-rectangle assignments, and the reason `SnowPatternDescriptor` remains descriptive rather than final source spelling.
- 2026-07-01 B008 WeatherLayerPane empty-emitter family callback:
  - Metadata unchanged.
  - Summary/evidence: inserted the formal no-duplicate-struct-block marker. `SnowParticleEntry` and `SnowPatternDescriptor` remain descriptive support layouts consumed by newly emitting [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md) and [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md) first-draft C++, but this type page does not emit a standalone provisional struct block until final names and header placement are resolved.
