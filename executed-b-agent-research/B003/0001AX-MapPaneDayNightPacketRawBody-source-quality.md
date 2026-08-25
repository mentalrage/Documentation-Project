** TARGET-REPORT-UID:0001AX **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Source-Quality Report: [UID:0001AX] MapPaneDayNightPacketRawBody

Assignment: `B003-goal2-mappane-day-night-packet-raw-body-source-quality-0001AX-20260618`

Primary target: [UID:0001AX] `by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md`

Current target metadata:

```text
COMPLETION:84
CONFIDENCE:88
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000L3
EMITTER_UIDS:0000L3
Formal C++: blank
```

## Current Recommendation

Keep [UID:0001AX] as a reconstructable retained raw duplicate evidence page, owned by [UID:0000L3] `MapPane.cpp`, with formal C++ intentionally blank. Raise target metadata to `COMPLETION:86`, `CONFIDENCE:90`, keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:0000L3`, and keep `EMITTER_UIDS:0000L3`.

The no-code policy is target-specific, not score-gate based: `0x00510400` is a complete source-shaped body, but the current binary has no modeled function, no caller/xref route, and no hidden PE pointer/branch route to that raw start. The same behavior is present in the live `MapPane::HandlePacket` dispatcher case for opcode `0x20` at `0x00507e45-0x00507f04`, which is the evidence-backed source route. Populating standalone C++ on [UID:0001AX] would duplicate the live dispatcher branch and would falsely imply an independent source method such as stale generated `MapPane::HandleWeatherPacket`.

Recommended source-facing behavior names:

| Binary item | Best descriptive name | Confidence | Reason |
| --- | --- | ---: | --- |
| `dword_66DD78` | `s_dayNightBrightnessByHour[24]` / `kDayNightBrightnessByHour` | high | 24 float entries indexed by an hour byte in range `0..23`; values form a dim-night/full-day/mirrored-evening lighting curve. Use `s_` for file-static source text or `k` for declaration-only const data. |
| packet byte `packet[1]` | `dayNightHour` / `hour` | high | Read through byte helper, validated `< 24`, stored at `MapPane +0x40f`, and used as the table index. |
| packet byte `packet[2]` | `minuteOfHour` | medium-high | Read through byte helper and multiplied by `60`; the check `minute * 60 < 3600` is equivalent to `< 60`. The body does not store or pass the value after validation. |
| `MapPane +0x40f` | `m_dayNightHour` | high | Written from the validated hour byte by the raw body and live dispatcher branch, then reread by the modeled effect/map-state handler at `0x005107fe` before indexing the same table. |
| `MapPane +0x3e4` | `m_dayNightBrightnessScale` | high | Effect packet handler writes `1.0f` or a computed lighting scale; day/night formula multiplies `(table[hour] - 0.5f)` by this field. |
| `MapPane +0x3e8` | `m_dayNightBrightnessBias` | high | Effect packet handler writes zero or computed offset; day/night formula adds it after restoring the `0.5f` center. |
| `MapPane +0x3b8` | `m_currentDayNightBrightness` | high | Constructor seeds `0.60000002f`; target/helper subtracts this field from the new clamped target to compute a transition delta. |
| `MapPane +0x3c8` | `m_dayNightDurationCurveScale` | medium-high | Constructor seeds `-1.56250024f`; transition duration is `scale * delta * delta + base`. The sign is negative in current bytes, so avoid generic "speed" naming. |
| `MapPane +0x3cc` | `m_dayNightDurationBase` | medium-high | Constructor seeds `0.89999998f`; added after the quadratic term to produce the duration argument. |
| `0x0050a840-0x0050a8ad` | `MapPane::ComputeDayNightBrightnessAndDuration(...)` | medium-high | Source-shaped helper takes hour, scale, bias, and two output pointers; no current caller route, but its dataflow exactly computes target brightness and transition duration. |
| `0x0050a8b0-0x0050a932` | `MapPane::SetDayNightFadeTarget(float targetBrightness, float transitionDuration)` | high | Member helper (`ecx=this`, `ret 8`) compares/stores target and duration at `+0x3dc/+0x3d0`, seeds interpolation constants at `+0x3d4/+0x3d8`, updates palette/filter state when enabled, calls the lighting redraw helper, and invalidates through vtable slot `+0x20`. |

Rejected source-facing names:

- `MapPane::HandleWeatherPacket` for [UID:0001AX] is stale generated output. The byte body is day/night opcode `0x20`, not the opcode `0x1f` weather selector and not the modeled opcode `0x15` effect/map-state handler.
- `MapPane::HandleDayNightPacket` is a plausible behavior label but should not be emitted for this raw target until an actual source route exists. If the dispatcher is split later, it may be used for a live dispatcher child, not for this no-route duplicate.
- `m_timeOfDay` for `+0x40f` is weaker than `m_dayNightHour` because `MapPane::SetMapState` uses nearby `+0x40d` and `+0x410` for weather/time-state pairing. `+0x40f` is specifically the day/night brightness-table hour used by opcode `0x20` and the effect handler.
- `durationSeconds` for `packet[2]` is rejected. The code computes `packet[2] * 60` only to validate `< 3600`; it never stores or passes the product.
- `Effects.cpp`, WeatherLayer, packet-reader helpers, and [UID:0001SO] `MapServerPacketOpcode` are not owners. They are dependencies/indexes. The body mutates `MapPane` lighting/fade fields and belongs with `MapPane.cpp` dispatcher behavior.

## Evidence Checked

Read and compared:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B003/goal.md` and `notes.md`; both still referenced the previous KeySpeedMgr assignment, so this report follows the newest supervisor message as the active assignment.
- `by-structure.md`
- `inference_research.md`
- [UID:0001AX] `by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md`
- [UID:00037T] `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md`
- [UID:00027Q] `by-memory/0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable.md`
- [UID:0003TK] `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md`
- [UID:00037W] `by-memory/0x0050a500-0x0050ab95.MapPanePaintLightingCore.md`
- [UID:0001AW] `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
- [UID:0001AT] `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`
- [UID:00007Q] `by-class/MapPane.md`
- [UID:0000L3] `by-file/MapPane.md`
- [UID:0001SO] `by-type/by-enum/MapServerPacketOpcode.md`
- [UID:0001QG] `by-meta/client_map_system.md`
- [UID:0002I7] `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`
- [UID:0001AP] `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- [UID:0002I4] `by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md`
- Current `by-memory/-coverage-report.md`, `project-level/-auto-completion-stats.md`, generated coverage tables, and current generated `project-documentation/auto-generated/NexusTK/map/MapPane.cpp`
- Prior B reports:
  - `Agent-B002/research/executed/00007Q-MapPane-class-source-quality.md`
  - `Agent-B001/research/executed/older/0001AW-mappane-packet-source-split-audit.md`
  - `Agent-B001/research/executed/older/0001AW-mappane-packet-source-split-continuation-batch6.md`
  - `Agent-B001/research/executed/older/0001AW-mappane-packet-source-split-continuation-batch9.md`

Tooling and raw state checked:

- MCP resources: `list_mcp_resources` returned `[]`, so no live IDA MCP resource was available in this session. This is not a blocker because the existing docs contain IDA-backed facts and the raw PE checks below independently verify the disputed boundary/route questions.
- Raw PE source: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- PE SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Sections:
  - `.text` VA `0x00401000`, raw `0x400`, raw size `0x20b600`
  - `.rdata` VA `0x0060d000`, raw `0x20ba00`, raw size `0x5f200`
  - `.data` VA `0x0066d000`, raw `0x26ac00`, raw size `0xd800`
  - `.rsrc` VA `0x0069d000`, raw `0x278400`, raw size `0x15e00`
- Disassembly was generated with Capstone from the current executable bytes.
- Constant conversions were checked with `tools/int_convert.py`: `0x18 = 24`, `0x3c = 60`, `0xe10 = 3600`, `0x20 = 32`, `0xc7 = 199`, `0x1176 = 4470`, `0x68 = 104`.

Raw bytes and boundaries:

```text
0x005103fd-0x00510400: cc cc cc
0x00510400-0x005104c7: 0xc7 / 199 bytes, complete prologue/body/ret 4
0x005104c7-0x005104d0: cc cc cc cc cc cc cc cc cc
0x005104d0: successor modeled effect/map-state packet handler start in existing IDA-backed docs
```

Target byte sequence:

```text
00510400: 55 8b ec 53 56 57 8b 7d 08 8b f1 47 57 e8 5e 50
00510410: 06 00 8a d8 83 c4 04 80 fb 18 0f 83 9e 00 00 00
00510420: 8d 4f 01 51 e8 47 50 06 00 0f b6 c8 83 c4 04 8b
00510430: c1 c1 e0 04 2b c1 c1 e0 02 3d 10 0e 00 00 73 7e
00510440: 0f b6 c3 0f 57 d2 88 9e 0f 04 00 00 f3 0f 10 0c
00510450: 85 78 dd 66 00 f3 0f 5c 0d b0 04 61 00 f3 0f 59
00510460: 8e e4 03 00 00 f3 0f 58 0d b0 04 61 00 f3 0f 58
00510470: 8e e8 03 00 00 0f 2f d1 77 0c f3 0f 10 15 b4 04
00510480: 61 00 f3 0f 5d d1 f3 0f 10 8e c8 03 00 00 0f 28
00510490: c2 f3 0f 5c 86 b8 03 00 00 83 ec 08 8b ce f3 0f
005104a0: 59 c8 f3 0f 59 c8 f3 0f 58 8e cc 03 00 00 f3 0f
005104b0: 11 4c 24 04 f3 0f 11 14 24 e8 f2 a3 ff ff 5f 5e
005104c0: b0 01 5b 5d c2 04 00
```

Key target instructions:

```text
00510406  mov    edi, [ebp+8]          ; packet pointer
00510409  mov    esi, ecx              ; MapPane this
0051040b  inc    edi
0051040d  call   0x00575470            ; byte reader for packet[1]
00510417  cmp    bl, 0x18              ; hour < 24
00510420  lea    ecx, [edi+1]
00510424  call   0x00575470            ; byte reader for packet[2]
00510431  shl    eax, 4
00510434  sub    eax, ecx
00510436  shl    eax, 2                ; minute * 60
00510439  cmp    eax, 0xe10            ; minute * 60 < 3600
00510446  mov    [esi+0x40f], bl       ; day/night hour
0051044c  movss  xmm1, [eax*4+0x66dd78]
00510455  subss  xmm1, [0x6104b0]      ; 0.5f
0051045d  mulss  xmm1, [esi+0x3e4]     ; brightness scale
00510465  addss  xmm1, [0x6104b0]      ; +0.5f
0051046d  addss  xmm1, [esi+0x3e8]     ; brightness bias
00510475  comiss xmm2, xmm1            ; lower clamp against 0.0f
0051047a  movss  xmm2, [0x6104b4]      ; upper clamp source 1.0f
00510482  minss  xmm2, xmm1            ; clamp to <= 1.0f
00510486  movss  xmm1, [esi+0x3c8]     ; duration quadratic coefficient
00510491  subss  xmm0, [esi+0x3b8]     ; target-current delta
0051049e  mulss  xmm1, xmm0
005104a2  mulss  xmm1, xmm0
005104a6  addss  xmm1, [esi+0x3cc]     ; duration base
005104b9  call   0x0050a8b0
005104c0  mov    al, 1
005104c4  ret    4
```

Route scan results from the current PE:

```text
REL_TO 0x00510400: none
REL_TO 0x005104c0: none
REL_TO 0x005104c7: none
REL_TO 0x005104d0: 0x00507f10 e8 rel32
REL_TO 0x0050a8b0: 0x00506f17, 0x00507efd, 0x005104b9, 0x00510865
REL_TO 0x0066dd78: none as branch/call target, as expected for data
DWORD_SCAN VA 0x00510400: none
DWORD_SCAN RVA 0x00110400: none
DWORD_SCAN raw offset 0x0010f800: none
DWORD_SCAN VA 0x005104c7: one unrelated text immediate at 0x00415ffc inside a conditional branch displacement; not a pointer/route to this target
DWORD_SCAN VA 0x005104d0: none
DWORD_SCAN VA 0x0050a8b0: none
DWORD_SCAN VA 0x0066dd78: operand hits in code at the known table-ref instructions
DWORD_SCAN RVA/raw offset for 0x0066dd78: none
```

The `0x005104c7` dword-pattern hit is not a route. Disassembly at `0x00415ffc` is `0f 87 0d ff ff ff`, a relative conditional branch whose displacement bytes happen to include the value; the target is `0x00415f0f`, not `0x005104c7`.

Live dispatcher duplicate checked from current PE:

```text
0x00507e45-0x00507f04: opcode 0x20 / decimal 32 branch
00507e4d call 0x00575470             ; reads payload[1]
00507e57 cmp  bl, 0x18               ; hour < 24
00507e64 call 0x00575470             ; reads payload[2]
00507e79 cmp  eax, 0xe10             ; minute * 60 < 3600
00507e8a mov  byte ptr [esi+0x40f], bl
00507e90 movss xmm1, [eax*4+0x66dd78]
00507ea1 mulss xmm1, [esi+0x3e4]
00507eb1 addss xmm1, [esi+0x3e8]
00507eca movss xmm1, [esi+0x3c8]
00507ed5 subss xmm0, [esi+0x3b8]
00507eea addss xmm1, [esi+0x3cc]
00507efd call 0x0050a8b0
00507f02 mov  al, 1
00507f04 jmp  dispatcher epilogue
```

The dispatcher branch and raw target differ only in dispatcher-local setup/exit mechanics. The day/night logic, table reference, constants, MapPane field offsets, and helper call are equivalent.

Day/night table checked from current PE:

```text
0x0066dd78-0x0066ddd8, 24 floats:
0.34999999, 0.34999999, 0.34999999, 0.40000001,
0.44999999, 0.55000001, 0.64999998, 0.85000002,
0.89999998, 0.94999999, 1.0, 1.0,
1.0, 1.0, 1.0, 0.94999999,
0.89999998, 0.85000002, 0.64999998, 0.55000001,
0.44999999, 0.40000001, 0.34999999, 0.34999999
```

Relevant constants:

```text
0x006104b0 = 00 00 00 3f = 0.5f
0x006104b4 = 00 00 80 3f = 1.0f
constructor writes MapPane +0x3b8 = 0x3f19999a = 0.60000002f
constructor writes MapPane +0x3bc = 0x3f800000 = 1.0f
constructor writes MapPane +0x3c0 = 0x3f666666 = 0.89999998f
constructor writes MapPane +0x3c4 = 0x3f266666 = 0.64999998f
constructor writes MapPane +0x3c8 = 0xbfc80002 = -1.56250024f
constructor writes MapPane +0x3cc = 0x3f666666 = 0.89999998f
0x0050a8b0 writes MapPane +0x3d4 = 0x40000000 = 2.0f
0x0050a8b0 writes MapPane +0x3d8 = 0x3f4ccccd = 0.80000001f
```

Helper split:

```text
0x0050a840-0x0050a8ad:
  byte hour argument at [ebp+8]
  float scale at [ebp+0xc]
  float bias at [ebp+0x10]
  float *outBrightness at [ebp+0x14]
  float *outDuration at [ebp+0x18]
  ecx = MapPane this for +0x3b8/+0x3c8/+0x3cc
  ret 0x14

0x0050a8b0-0x0050a932:
  ecx = MapPane this
  [ebp+8] = target brightness
  [ebp+0xc] = transition duration
  compares against +0x3dc and +0x3d0
  stores +0x3dc target brightness and +0x3d0 transition duration
  writes +0x3d4 = 2.0f and +0x3d8 = 0.8f
  conditionally calls 0x00543f80 and then 0x0050d840
  invalidates through vtable slot +0x20
  ret 8
```

Generated output state:

- `project-documentation/auto-generated/NexusTK/map/MapPane.cpp` currently contains no emitted [UID:0001AX] body.
- Older `source-3/simroot_v2/class_MapPane.cpp` contains both:
  - an inline day/night branch inside `MapPane::HandlePacket` case `0x20`, and
  - a stale standalone generated `MapPane::HandleWeatherPacket` at `0x00510400`.
- The standalone generated body is not a defensible final source route because it contradicts the current no-caller/no-pointer evidence and duplicates the live dispatcher case.

## Heuristic / Inference Reanalysis And Validation

### Raw no-function/no-caller status

Validated. Existing docs say `0x00510400` is not an IDA function, has no callers/xrefs, and ends at `0x005104c7`. Current-session PE evidence independently verifies the raw-body bytes, `ret 4` endpoint at `0x005104c4-0x005104c6`, nine bytes of `0xcc` padding after the body, and absence of PE route hits to the raw start.

Rejected alternative: create an IDA function or source child at `0x00510400` and emit it as a method. The bytes are source-shaped, but there is no evidence of an executable route to this body. The proven route is the dispatcher case at `0x00507e45`.

Score/C++ impact: raise completion because the route question is now resolved as no-code proof rather than an open blocker. Do not populate target formal C++.

### Hidden rel32/VA/RVA/raw-offset/pointer-table/vtable routes

Validated negative. Current PE scan found no direct branch/call to `0x00510400`, no `0x00510400` VA literal, no `0x00110400` RVA literal, and no raw-offset literal for the target. No vtable/pointer route is supported by loaded bytes. Positive controls found the expected direct call to `0x005104d0` at `0x00507f10` and calls to `0x0050a8b0` at `0x00506f17`, `0x00507efd`, `0x005104b9`, and `0x00510865`, so the scan was capable of finding normal routes.

Rejected alternative: hidden callback/table call into the raw start. No pointer-like evidence exists. The nearby `0x005104c7` dword-pattern collision is a branch displacement inside unrelated `.text`, not a pointer.

Score/C++ impact: route uncertainty no longer justifies `84`; recommend `86/90`.

### Dispatcher duplicate and source route

Validated. The live `MapPane::HandlePacket` opcode `0x20` branch at `0x00507e45-0x00507f04` performs the same payload reads, range checks, `+0x40f` store, table lookup, clamping, duration computation, and `0x0050a8b0` call as [UID:0001AX].

Best inference: source behavior should be represented in [UID:00037T] `MapPanePacketDispatcher`, preferably as a source-shaped case block for `kMapServerDayNightCycle` or as a future exact dispatcher-case child if the dispatcher is split. [UID:0001AX] should stay as retained raw evidence and should not emit a duplicate helper.

Rejected alternatives:

- Merge [UID:0001AX] into [UID:00037T] and delete/reclassify it: rejected because the raw bytes are real, source-shaped, and have their own exact padding boundaries. Keeping a retained evidence page preserves the binary anomaly without polluting final source.
- Reclassify as ignored padding/dead junk: rejected because the body is not padding and exactly duplicates meaningful project behavior.
- Emit standalone `MapPane::HandleWeatherPacket`: rejected as stale generated output and wrong behavior label.

Score/C++ impact: leave reconstructable true, but target C++ blank with exact no-code proof.

### Packet byte roles

Best inference: `packet[1]` is a day/night hour byte and `packet[2]` is a minute-of-hour byte.

Evidence:

- `packet[1]` is validated against `0x18` / 24 and stored at `MapPane +0x40f`.
- `packet[1]` indexes the 24-entry day/night brightness table.
- `packet[2]` is multiplied by 60 through `(x << 4) - x` then `<< 2`, and checked against `0xe10` / 3600. This is exactly `minute < 60`.
- `packet[2]` does not participate in the fade computation after validation, so its source role is validation/synchronization only in this body.

Rejected alternatives:

- `packet[1]` as generic mode: valid but weaker because table size and value curve are hour-shaped.
- `packet[2]` as duration: rejected because the computed seconds value is not stored or passed.
- `packet[2]` as seconds directly: rejected because the code multiplies by 60 first.

Score/C++ impact: packet-role names are good enough for support docs and dispatcher draft snippets; original protocol struct name remains unproven, so do not raise above 90 confidence.

### Day/night table naming

Best inference: `s_dayNightBrightnessByHour` or `kDayNightBrightnessByHour`.

Evidence:

- 24 entries, all `float`.
- Index range exactly `0..23`.
- Values form a night-to-day brightness curve: three dim night slots at `0.35`, a morning ramp through `0.4/0.45/0.55/0.65/0.85/0.90/0.95`, a five-hour full-day plateau at `1.0`, then a mirrored evening fade.
- Table xrefs occur in the dispatcher case, the raw duplicate, the modeled effect/map-state handler, and the unmodeled compute helper.

Rejected alternatives:

- `dword_66DD78`: historical raw label only.
- `g_timeOfDayBrightnessTable`: useful generated label but less precise about MapPane/static ownership. Use it only as a legacy alias if needed.
- Weather-intensity table: weaker because weather state is a separate byte field and this table is keyed by hour.

Score/C++ impact: support docs can use `s_dayNightBrightnessByHour` while noting original symbol spelling is not proven. The table support page [UID:00027Q] should be raised/kept at `85/90` and should no longer call final symbol naming an unresolved blocker at target level.

### MapPane field roles

Best field inferences:

```text
+0x3b8  float m_currentDayNightBrightness
+0x3c8  float m_dayNightDurationCurveScale
+0x3cc  float m_dayNightDurationBase
+0x3d0  float m_dayNightTransitionDuration       ; written by 0x0050a8b0
+0x3d4  float m_dayNightTransitionCurveValueA    ; helper writes 2.0f
+0x3d8  float m_dayNightTransitionCurveValueB    ; helper writes 0.8f
+0x3dc  float m_dayNightTargetBrightness         ; written by 0x0050a8b0
+0x3e4  float m_dayNightBrightnessScale
+0x3e8  float m_dayNightBrightnessBias
+0x40f  unsigned char m_dayNightHour
```

Evidence:

- Constructor writes initial day/night brightness and transition constants at `+0x3b8`, `+0x3bc`, `+0x3c0`, `+0x3c4`, `+0x3c8`, and `+0x3cc`.
- Target, dispatcher, effect handler, and `0x0050a840` compute `target = clamp01((table[hour] - 0.5f) * scale + 0.5f + bias)`.
- Target, dispatcher, effect handler, and `0x0050a840` compute `duration = +0x3c8 * (target - +0x3b8)^2 + +0x3cc`.
- `0x0050a8b0` writes incoming target/duration to `+0x3dc/+0x3d0` only when they differ, then updates rendering.
- Effect handler writes `+0x3e4` to either `1.0f` or a computed lighting scale and writes `+0x3e8` to either zero or a computed lighting bias before recomputing the target brightness from `+0x40f`.

Rejected alternatives:

- `+0x3c8` as `m_transitionSpeed`: rejected as too generic and potentially misleading because current default is a negative quadratic coefficient.
- `+0x3cc` as `m_transitionOffset`: acceptable generated wording, but `m_dayNightDurationBase` better describes the value added to the transition duration calculation.
- `+0x3e4/+0x3e8` as integers: rejected. Current instructions use `movss`/`mulss`/`addss`, and effect handler writes float bit patterns.
- `+0x40f` as weather state: rejected; `MapPane::SetMapState` uses nearby `+0x410` for weather and `+0x40d` for map-state time-of-day, while `+0x40f` is table-hour state.

Score/C++ impact: field roles are now strong enough for support-doc field glossary text and dispatcher branch draft code. The exact original member spelling is still inferred, so confidence stays at 90 rather than final-source 95+.

### Helper names and signatures

Recommended helper signatures:

```cpp
// Raw helper-shaped body at 0x0050a840-0x0050a8ad.
// No current caller route; document as evidence, not necessarily emitted.
void MapPane::ComputeDayNightBrightnessAndDuration(
    unsigned char hour,
    float brightnessScale,
    float brightnessBias,
    float *outTargetBrightness,
    float *outTransitionDuration) const;

// Modeled/apply helper at 0x0050a8b0-0x0050a932.
void MapPane::SetDayNightFadeTarget(float targetBrightness, float transitionDuration);
```

Evidence:

- `0x0050a840` reads byte `[ebp+8]`, floats `[ebp+0xc]` and `[ebp+0x10]`, output pointers `[ebp+0x14]` and `[ebp+0x18]`, and returns with `ret 0x14`.
- `0x0050a840` uses `ecx` as MapPane this for current brightness and duration constants.
- `0x0050a8b0` reads two float stack arguments, uses `ecx` as MapPane this, returns `ret 8`, and invalidates/render-updates when the target/duration changed.

Rejected alternatives:

- `SetDayNightCycle`: too broad and inherited from generated source. The helper begins or updates a fade target; it does not parse packets or own table lookup.
- `ApplyLighting`: too broad; callers specifically pass day/night target brightness and transition duration.
- Free function signatures: weaker than member signatures because both helpers depend on `ecx=this` MapPane fields.

Score/C++ impact: source-facing helper names are good support names. They do not prove a standalone [UID:0001AX] source route.

### Existing documentation validation/contradiction

Validated current docs:

- [UID:0001AX] correctly records the exact range, raw no-function state, no direct caller/xref status, dispatcher equivalence, table use, helper call, touched fields, MapPane ownership, and blank C++.
- [UID:00007Q] and [UID:0000L3] correctly state that `0x00510400` is retained raw duplicate evidence and should not become an independent `MapPane::HandleWeatherPacket`.
- [UID:0001SO] correctly indexes opcode `0x20` as day/night cycle and notes the raw duplicate caveat.
- [UID:0001AW] correctly keeps [UID:0001AX] as a child of the packet-handler aggregate.

Stale or incomplete wording to replace:

- Any "final C++ gate remains blank" or "below 95/95" wording is stale. The reason is target-specific no-code proof, not a threshold.
- [UID:0001AW] open question "Reconcile the `0x00510400` weather-handler boundary before source migration" should be closed. The boundary has been reconciled as retained no-route duplicate evidence.
- Support pages should stop using standalone generated `HandleWeatherPacket` as a possible final method name for [UID:0001AX].
- Field names should move from generic `mode byte`, `scale`, `bias`, and `fade curve` wording to the descriptive day/night field names above.

## Recommended Metadata And Score Changes

For [UID:0001AX]:

```text
COMPLETION:86
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000L3
EMITTER_UIDS:0000L3
RECONSTRUCTION_CPP: blank
```

Rationale:

- Completion rises from 84 to 86 because the raw boundary, successor padding, no-route proof, dispatcher duplicate proof, field roles, table name, packet byte roles, helper signatures, source owner, and no-code policy are all resolved at source-quality level.
- Confidence rises from 88 to 90 because current executable bytes independently validate the earlier IDA-backed facts. It remains below final-source quality because original member/helper symbol spellings and original compilation reason for the retained duplicate are not provable from current evidence.
- Owner remains [UID:0000L3] `MapPane.cpp` because this is file-level raw evidence for MapPane packet behavior, not an independently source-routed class method body. The live source route is [UID:00037T] `MapPane::HandlePacket`.
- Emitter remains [UID:0000L3] only as source-file attachment context. Formal target C++ remains blank.

For [UID:00027Q] support table page:

```text
Keep or restore COMPLETION:85, CONFIDENCE:90.
Recommended support name: s_dayNightBrightnessByHour[24] / kDayNightBrightnessByHour.
Formal C++ can remain blank unless the supervisor decides static const data declarations are ready for MapPane.cpp; [UID:0001AX] does not require table emission to resolve this target.
```

## First-Draft C++ Recommendation

Do not populate formal C++ on [UID:0001AX].

Target-specific no-code proof:

1. `0x00510400` has a complete function-shaped body but no modeled function object in current IDA-backed docs.
2. Current PE scans found no direct call/branch, no VA literal, no RVA literal, and no raw-offset literal to `0x00510400`.
3. The same behavior is already present inside the live dispatcher case at `0x00507e45-0x00507f04`.
4. The current generated `project-documentation/auto-generated/NexusTK/map/MapPane.cpp` emits no [UID:0001AX] body.
5. Emitting a standalone target body would create a duplicate source behavior path and would preserve the stale `HandleWeatherPacket` boundary that current evidence rejects.

Where behavior should be represented:

- Primary source location: [UID:00037T] `MapPane::HandlePacket` case `0x20` / [UID:0001SO] `MapServerPacketOpcode` working value `day/night cycle`.
- If the dispatcher is later split into exact case children, emit this case as the source-bearing child for the live dispatcher branch, not as [UID:0001AX].

Recommended source-shaped dispatcher case snippet for supervisor/reference use only:

```cpp
case kMapServerDayNightCycle: {
    const unsigned char hour = ReadPacketByte(payload + 1);
    const unsigned char minuteOfHour = ReadPacketByte(payload + 2);

    if (hour < 24 && minuteOfHour < 60) {
        m_dayNightHour = hour;

        const float mappedBrightness =
            ((s_dayNightBrightnessByHour[hour] - 0.5f) *
             m_dayNightBrightnessScale) +
            0.5f +
            m_dayNightBrightnessBias;

        float targetBrightness = 0.0f;
        if (mappedBrightness >= 0.0f) {
            targetBrightness = (mappedBrightness <= 1.0f)
                ? mappedBrightness
                : 1.0f;
        }

        const float delta = targetBrightness - m_currentDayNightBrightness;
        SetDayNightFadeTarget(
            targetBrightness,
            (m_dayNightDurationCurveScale * delta * delta) +
                m_dayNightDurationBase);
    }

    return true;
}
```

This snippet is intentionally scoped to the live dispatcher branch. It should not be copied into [UID:0001AX] formal C++ unless new route evidence proves `0x00510400` is source-emitted independently.

Optional support declarations for a future MapPane class/header pass:

```cpp
static const float s_dayNightBrightnessByHour[24];

float m_currentDayNightBrightness;      // +0x3b8
float m_dayNightDurationCurveScale;     // +0x3c8
float m_dayNightDurationBase;           // +0x3cc
float m_dayNightTransitionDuration;     // +0x3d0
float m_dayNightTargetBrightness;       // +0x3dc
float m_dayNightBrightnessScale;        // +0x3e4
float m_dayNightBrightnessBias;         // +0x3e8
unsigned char m_dayNightHour;           // +0x40f

void SetDayNightFadeTarget(float targetBrightness, float transitionDuration);
```

## Exact Supervisor Changes Required

### Target [UID:0001AX]

Update metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the existing C++/reconstruction note with:

```text
Formal C++ intentionally remains blank for this target. This is a target-specific no-code decision, not a score-gate deferral: current IDA-backed docs and the 2026-06-18 B003 raw PE scan confirm no modeled function, no direct caller/xref, and no rel32/VA/RVA/raw-offset route to `0x00510400`. The live source route is the equivalent `MapPane::HandlePacket` opcode `0x20` branch at `0x00507e45-0x00507f04`; emitting this target as a standalone `MapPane::HandleWeatherPacket` or `MapPane::HandleDayNightPacket` would duplicate dispatcher behavior and preserve a stale generated boundary.
```

Replace the current behavior paragraph that starts "When valid, it stores the mode byte..." with:

```text
When valid, the body stores the validated hour byte at `MapPane +0x40f` (`m_dayNightHour`), looks up `s_dayNightBrightnessByHour[hour]` / `dword_66DD78[hour]`, applies `MapPane +0x3e4` (`m_dayNightBrightnessScale`) and `MapPane +0x3e8` (`m_dayNightBrightnessBias`) around the `0.5f` midpoint, clamps the result to `[0.0f, 1.0f]`, computes a transition duration as `MapPane +0x3c8` (`m_dayNightDurationCurveScale`) times the square of `(target - MapPane +0x3b8 / m_currentDayNightBrightness)` plus `MapPane +0x3cc` (`m_dayNightDurationBase`), then calls `0x0050a8b0` / inferred `MapPane::SetDayNightFadeTarget(float targetBrightness, float transitionDuration)`. The return value is always true, including invalid-payload paths.
```

Replace or add the packet/field table with:

```text
| Item | Source-facing name | Evidence |
| --- | --- | --- |
| `packet[1]` | `dayNightHour` / `hour` | Read through `0x00575470`, validated `< 24`, stored at `MapPane +0x40f`, and used as the 24-entry table index. |
| `packet[2]` | `minuteOfHour` | Read through `0x00575470`; `(value * 60) < 3600` is equivalent to `< 60`. The value is validation-only in this body. |
| `dword_66DD78` | `s_dayNightBrightnessByHour[24]` / `kDayNightBrightnessByHour` | 24 float values forming a night/day/evening brightness curve; xrefs from live dispatcher case, this raw duplicate, effect/map-state handler, and compute helper. |
| `MapPane +0x40f` | `m_dayNightHour` | Written by opcode `0x20`; reread by `0x005104d0` effect/map-state handler before the same table lookup. |
| `MapPane +0x3e4` | `m_dayNightBrightnessScale` | Multiplies `(table[hour] - 0.5f)`; effect/map-state handler writes the current lighting scale. |
| `MapPane +0x3e8` | `m_dayNightBrightnessBias` | Added after midpoint restoration; effect/map-state handler writes the current lighting bias/offset. |
| `MapPane +0x3b8` | `m_currentDayNightBrightness` | Constructor seeds `0.60000002f`; target subtracts it from the clamped brightness target. |
| `MapPane +0x3c8` | `m_dayNightDurationCurveScale` | Constructor seeds `-1.56250024f`; used as the quadratic coefficient for transition duration. |
| `MapPane +0x3cc` | `m_dayNightDurationBase` | Constructor seeds `0.89999998f`; added as the duration base term. |
| `0x0050a8b0` | `MapPane::SetDayNightFadeTarget(float targetBrightness, float transitionDuration)` | Member helper stores target/duration when changed, updates palette/filter state, calls redraw helper, and invalidates through Pane vslot `+0x20`. |
```

Add a "Rejected alternatives" note if absent:

```text
Rejected alternatives: `MapPane::HandleWeatherPacket` is stale generated output and wrong for opcode `0x20`; a standalone `MapPane::HandleDayNightPacket` remains unproven because no route reaches `0x00510400`; weather layer/effect classes and packet reader helpers are dependencies, not owners. Keep this page as retained raw duplicate evidence until new route evidence appears.
```

### [UID:0001AW] `MapPanePacketHandlers`

Replace the open question:

```text
- Reconcile the `0x00510400` weather-handler boundary before source migration.
```

with:

```text
- Resolved by 2026-06-18 B003 source-quality pass: [UID:0001AX] `0x00510400-0x005104c7` is retained raw duplicate evidence for live dispatcher opcode `0x20`, not an independent migrated `MapPane::HandleWeatherPacket` method. Current raw PE scans confirm no direct caller/xref, no rel32/VA/RVA/raw-offset route to the raw start, exact `ret 4` endpoint, and equivalence with the `0x00507e45-0x00507f04` dispatcher case. Source behavior should emit through [UID:00037T] `MapPane::HandlePacket` or a future exact dispatcher-case child.
```

### [UID:0000L3] `by-file/MapPane.md`

In the Weather and effects row, replace:

```text
Treat the generated `HandleWeatherPacket` as a boundary duplicate until the dispatcher split is repaired.
```

with:

```text
Treat generated `HandleWeatherPacket` as a stale boundary duplicate: [UID:0001AX] has no current route to `0x00510400`, and the source-bearing day/night behavior belongs to the live `MapPane::HandlePacket` opcode `0x20` branch or a future exact dispatcher-case child.
```

Replace the 2026-05-24/2026-05-25 caveat pair or append after it:

```text
2026-06-18 B003 source-quality recheck: raw PE disassembly and route scans confirm the earlier IDA-backed conclusion. `0x00510400-0x005104c7` is a retained no-route duplicate of dispatcher case `0x20`, not a source-emitting standalone method. The day/night payload bytes are best documented as `dayNightHour` (`packet[1]`, `<24`) and `minuteOfHour` (`packet[2]`, `<60` validation-only). The brightness curve table should be named descriptively as `s_dayNightBrightnessByHour[24]`, and `0x0050a8b0` is best described as `MapPane::SetDayNightFadeTarget(float targetBrightness, float transitionDuration)`.
```

### [UID:00007Q] `by-class/MapPane.md`

The current class-level disposition is already correct. Add this field-glossary support text near the MapPane field notes if the supervisor is updating the class page:

```text
Day/night lighting fields from the opcode `0x20` dispatcher branch and [UID:0001AX]: `+0x40f` is best described as `m_dayNightHour`; `+0x3e4` / `+0x3e8` are `m_dayNightBrightnessScale` / `m_dayNightBrightnessBias`; `+0x3b8` is `m_currentDayNightBrightness`; `+0x3c8` / `+0x3cc` are `m_dayNightDurationCurveScale` / `m_dayNightDurationBase`; `+0x3dc` / `+0x3d0` are the target brightness and transition duration written by `0x0050a8b0` / `MapPane::SetDayNightFadeTarget`.
```

### [UID:0001SO] `MapServerPacketOpcode`

Optional opcode row replacement:

```text
| `0x20` | day/night cycle | Inline dispatcher body at `0x00507e45-0x00507f04`: validates `packet[1]` as `dayNightHour < 24` and `packet[2]` as `minuteOfHour < 60`, stores the hour at `MapPane +0x40f`, computes a clamped brightness target from `s_dayNightBrightnessByHour[hour]`, `MapPane +0x3e4` scale, and `MapPane +0x3e8` bias, derives a quadratic transition duration from `+0x3b8/+0x3c8/+0x3cc`, and calls `0x0050a8b0` / `MapPane::SetDayNightFadeTarget`. Raw `0x00510400-0x005104c7` remains no-route duplicate evidence, not the source owner. |
```

### [UID:00027Q] `MapPaneDayNightFloatTable`

Optional support wording replacement:

```text
Recommended source-facing name: `s_dayNightBrightnessByHour[24]` or `kDayNightBrightnessByHour`. The original symbol spelling is not proven, but the table role is no longer just a generic `dword_66DD78`: current evidence proves a 24-hour day/night brightness curve consumed by the dispatcher opcode `0x20`, the raw duplicate [UID:0001AX], the modeled effect/map-state handler, and the unmodeled compute helper.
```

## Coverage Report Replacement Text

Replace the current [UID:0001AX] row in `by-memory/-coverage-report.md` under [UID:0001AW] with:

```text
        - [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) 0x00510400-0x005104c7 | raw duplicate packet-handler body | MapPaneDayNightPacketRawBody : reconstructable : 86% : strong : Retained raw MapPane opcode `0x20` day/night body; 2026-06-18 B003 raw PE scan confirms exact `0xc7`-byte body ending at `retn 4`, `0xcc` padding before/after, no modeled-function/no-caller/no-xref route to `0x00510400`, no rel32/VA/RVA/raw-offset pointer route to the raw start, live dispatcher case `32` equivalence at `0x00507e45-0x00507f04`, `s_dayNightBrightnessByHour[24]` table use, `MapPane::SetDayNightFadeTarget` helper call, and MapPane day/night hour, brightness scale/bias, current brightness, and transition-duration fields. Formal C++ remains blank because emitted source belongs to the live dispatcher route, not this no-route duplicate.
```

If the supervisor also updates [UID:00027Q] support coverage to match the current metadata/name:

```text
    - [UID:00027Q][0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable](by-memory/0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable.md) 0x0066dd78-0x0066ddd8 | float lookup table | MapPaneDayNightFloatTable : reconstructable : 85% : strong : 24-float MapPane day/night brightness-by-hour curve; current PE confirms exact bit patterns, dispatcher/raw-body/modeled-handler/unmodeled-compute-helper table refs, no pointer-table route, and best descriptive source name `s_dayNightBrightnessByHour[24]` / `kDayNightBrightnessByHour`.
```

No parent [UID:0001AW] row change is required unless the supervisor wants to close the stale open-question wording there. If changed, keep [UID:0001AW] `85/88` unless a broader packet-handler pass changes other children.

## Remaining Blockers

No blocker remains that should keep [UID:0001AX] below `85/85`.

Residual nonblocking uncertainties:

- Original symbol spellings for `s_dayNightBrightnessByHour`, `m_dayNightHour`, `m_dayNightBrightnessScale`, `m_dayNightBrightnessBias`, `m_currentDayNightBrightness`, `m_dayNightDurationCurveScale`, `m_dayNightDurationBase`, and `MapPane::SetDayNightFadeTarget` are inferred/descriptive, not recovered from symbols.
- The original compilation/linker reason for retaining a no-route duplicate body at `0x00510400` cannot be proven from current evidence. Possibilities include stale unreferenced source method, function-level dead retention, or generated/raw boundary artifact. This uncertainty affects only duplicate-source policy, not behavior recovery.
- IDA MCP was not available in this session (`list_mcp_resources` returned no resources). Existing IDA-backed docs plus current PE byte/route checks are sufficient for this assignment. A future supervisor run can re-run IDA `lookup_funcs`, `xrefs_to`, and `callers` for audit parity, but no current conclusion depends on unavailable live MCP output.

Impact:

- Score: recommend `86/90`.
- Owner/emitter: unchanged [UID:0000L3].
- Source placement: behavior belongs to `MapPane.cpp`, specifically live `MapPane::HandlePacket` opcode `0x20`; [UID:0001AX] remains retained evidence only.
- C++ readiness: target formal C++ should stay blank with no-code proof. Dispatcher case snippet is ready for a dispatcher-child/source-route pass.

## Validation Commands For Supervisor

After applying documentation changes, run:

> Executable block R001 was removed from this report and preserved verbatim in [0001AX-MapPaneDayNightPacketRawBody-source-quality-removed.md](0001AX-MapPaneDayNightPacketRawBody-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended optional PE spot-check:

> Executable block R002 was removed from this report and preserved verbatim in [0001AX-MapPaneDayNightPacketRawBody-source-quality-removed.md](0001AX-MapPaneDayNightPacketRawBody-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected SHA256:

```text
9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001AX-MapPaneDayNightPacketRawBody-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001AX"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001AX-MapPaneDayNightPacketRawBody-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001AX-MapPaneDayNightPacketRawBody-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001AX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
