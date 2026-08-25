** TARGET-REPORT-UID:000046 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Source-Quality Report: [UID:000046] EarthquakeEffecter

Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\EarthquakeEffecter.md`

Report-only status: no by-* documentation file was edited for this pass, and `by-memory/-coverage-report.md` was not edited.

Required output path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007\research\000046-EarthquakeEffecter-class-source-quality.md`

## Summary Recommendation

Raise [UID:000046] from `COMPLETION:85`, `CONFIDENCE:86` to `COMPLETION:87`, `CONFIDENCE:88`. Keep `CANONICAL_OWNER:0000IZ`, `EMITTER_UIDS:0000IZ`, and `RECONSTRUCTABLE:TRUE`.

The previous `85/86` page was directionally correct on class identity, vtable identity, `render/Effects.cpp` placement, raw-constructor caveat, and broad behavior. The score is now slightly understated because the source-quality blockers named on the page can mostly be resolved from current binary/support evidence:

- the 20-byte object layout is now source-usable rather than just "timer/amplitude/state";
- the cadence fields are distinguishable: `+0x10` is the overwritten last-sample tick, not a constructor-only baseline;
- current offsets are stored as Y at `+0x08` and X at `+0x0c`;
- the camera-lock branch has a concrete local-player/global-state route and a concrete direction-to-tile-delta helper at `0x00505080`;
- the generated `class_EarthquakeEffecter.cpp` names are stale in several places and should not be copied;
- class-level declaration C++ is now eligible, while method bodies should remain deferred until exact child splits or accepted method-level bodies exist.

The score should not jump to 90+ yet. The raw constructor still has no static caller/pointer route in the local PE scan, IDA still does not model it as a function object in the existing docs, original spellings for the local-player camera-lock fields are inferred rather than proven, and the Earthquake method bodies remain embedded in the broad [UID:0001GE] `ScreenEffecterRuntimeCluster` instead of exact child pages.

## Evidence Checked

Primary target and owner docs:

- [UID:000046] `by-class/EarthquakeEffecter.md`
- [UID:0000IZ] `by-file/Effects.md`
- [UID:0000AI] `by-class/PixelEffecter.md`
- [UID:0001GE] `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`
- [UID:0002OR] `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`
- [UID:0001YO] `by-type/by-vtable/ScreenEffecterVtableFamily.md`
- [UID:0000VE] `by-item/ScreenEffecterSmallConstructorBoundaries.md`

Dependency/support docs:

- [UID:0000L3] `by-file/MapPane.md`
- [UID:0001AP] `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- [UID:0002I2] `by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md`
- [UID:0002I4] `by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md`
- [UID:0002I6] `by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md`
- [UID:0000OT] `by-file/TimerMgr.md`
- [UID:0000SI] `by-global/g_pTimerMgr.md`
- [UID:0000PR] `by-global/g_activeMapPane.md`
- [UID:0000QK] `by-global/g_pCollectionData.md`
- [UID:0000N2] `by-file/RectBounds.md`
- [UID:000167] `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`

Generated/source leads checked but not treated as authority:

- `source-3/simroot_v2/class_EarthquakeEffecter.cpp`
- `source-3/simroot_v2/class_XWaveEffecter.cpp`
- `source-3/simroot_v2/class_ScreenEffecter.cpp`
- `source-3/simroot_v2/class_EarthquakeEffecter.cpp.source_map.json`
- `source-3/core/data/readonly/wave2/classes/EarthquakeEffecter.json`

Raw binary evidence checked:

- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Capstone disassembly for `0x0055b110-0x0055b160`, `0x0055b160-0x0055b293`, `0x0055bb90-0x0055bbb4`, and helper `0x00505080-0x00505100`.
- Local pointer/rel32 scan for constructor/apply/destructor/vtable anchors. IDA MCP was not reachable in this session, so I used the prior target/support IDA MCP refreshes as documented evidence and verified the relevant executable bytes locally.

## Function Inventory, Ranges, And Padding

The target is a class page, not an exact by-memory child, but the implementation callback should update the class page with the following method inventory.

| Range | Source role | Current status |
| --- | --- | --- |
| `0x0055b110-0x0055b151` | `EarthquakeEffecter::EarthquakeEffecter(unsigned short xAmplitude, unsigned short yAmplitude)` | Raw constructor-shaped bytes. Prior IDA docs report no function object at the start; local PE confirms the body and `ret 8` at `0x0055b14e-0x0055b150`. |
| `0x0055b151-0x0055b160` | padding | Fifteen `0xcc` bytes before `ApplyEffect`. Keep this as alignment, not code. |
| `0x0055b160-0x0055b293` | `EarthquakeEffecter::ApplyEffect(...)` | Modeled virtual body. Prior docs describe size `0x133`; local disassembly confirms the body through `ret 0x0c` ending at `0x0055b292`. |
| `0x0055bb90-0x0055bbb4` | scalar deleting destructor thunk for `EarthquakeEffecter` | Modeled destructor-strip member. Source should expose a virtual destructor/destructor declaration, not an authored `ScalarDeletingDestructor` method. |

The existing target text uses `0x0055b160-0x0055b292` and `0x0055bb90-0x0055bbb3` in prose. For half-open range style these should be normalized to `0x0055b160-0x0055b293` and `0x0055bb90-0x0055bbb4` if the implementation updates exact ranges. If the page intentionally uses inclusive last-byte notation in prose, keep the existing notation but state that `ret 0x0c` occupies bytes through `0x0055b292` and destructor `ret 4` occupies bytes through `0x0055bbb3`.

## Raw Constructor Reanalysis

Local disassembly for `0x0055b110-0x0055b151`:

```asm
0055b110 push ebp
0055b111 mov ebp, esp
0055b113 push ecx
0055b114 mov dword ptr [ecx], 0x623be4
0055b11a mov eax, dword ptr [0x67ab80]
0055b11f mov [ebp-4], ecx
0055b122 mov eax, dword ptr [eax+0x18]
0055b125 sub eax, 0x3c
0055b128 mov dword ptr [ecx+0xc], 0
0055b12f mov dword ptr [ecx+0x10], eax
0055b132 mov ax, [ebp+8]
0055b136 mov [ecx+4], ax
0055b13a mov ax, [ebp+0xc]
0055b13e mov [ecx+6], ax
0055b142 mov eax, ecx
0055b144 mov dword ptr [ecx+8], 0
0055b14b mov esp, ebp
0055b14d pop ebp
0055b14e ret 8
```

Constructor conclusions:

- The constructor installs `??_7EarthquakeEffecter@@6B@` at `0x00623be4`.
- It reads `g_pTimerMgr` at `0x0067ab80`, then the timer field at `+0x18`.
- It stores `currentTick - 0x3c` at object offset `+0x10`.
- It stores the first 16-bit argument at `+0x04` and the second 16-bit argument at `+0x06`.
- It zeroes `+0x0c` before storing the tick and zeroes `+0x08` immediately before returning.
- Because `ApplyEffect` later overwrites `+0x10` on each new random sample, `+0x10` is best named `m_lastShakeTick` / `m_lastSampleTick`, not `m_startTick` or a permanent baseline.
- Because `ApplyEffect` stores the X offset at `+0x0c` and Y offset at `+0x08`, the constructor zero stores should be documented as `m_currentXOffset = 0` and `m_currentYOffset = 0`.
- The constructor seed is not "immediate first shake." With the update condition `currentTick - m_lastShakeTick > 0x50`, the `-0x3c` seed means an immediate first call sees a delta of 60 and reuses zero offsets; the first random sample becomes eligible after roughly 21 more tick units. This looks like a short initial grace interval, not a forced first update.

Reachability/modeling:

- The current docs' caveat that IDA does not model `0x0055b110` as a function object remains valid.
- Local PE scan found no VA pointer, RVA pointer, raw-offset pointer, rel32 call, rel32 jump, or rel32 conditional branch to `0x0055b110`.
- Positive controls were found where expected: the constructor contains a literal vtable store to `0x00623be4`, and the vtable contains the modeled `ApplyEffect` and destructor slots.
- This is still source-authored constructor-shaped code because it has a normal `thiscall` prologue, object initialization, vtable store, two stack arguments, and `ret 8`. The missing route should cap the score and block method-body emission, not erase the class or owner.

## Field Layout And Best-Supported Names

Recommended 20-byte layout:

| Offset | Size | Best-supported field | Evidence and rejected alternatives |
| --- | --- | --- | --- |
| `+0x00` | 4 | `PixelEffecter` / vptr | Vtable store `0x00623be4` in constructor; destructor resets to base `ScreenEffecter` vtable `0x006235a4`; vtable family places this under the pixel-effect branch. |
| `+0x04` | 2 | `m_xAmplitude` / `m_horizontalAmplitude` | Constructor stores arg1 as a word. `ApplyEffect` zero-extends this word, computes `rand() % (2 * amplitude + 1) - amplitude`, and uses the result as the X offset in `edi`. Prefer `unsigned short` storage because the method uses `movzx`, not `movsx`. |
| `+0x06` | 2 | `m_yAmplitude` / `m_verticalAmplitude` | Constructor stores arg2 as a word. `ApplyEffect` zero-extends this word, computes the same symmetric random range, and uses the result as the Y offset in `ebx`. |
| `+0x08` | 4 | `m_currentYOffset` | Constructor zeroes this field. On new samples `ApplyEffect` stores the Y offset here; inside the cooldown path it reloads this value into the Y register. Reject generated `m_elapsed` and vague `m_phase`. |
| `+0x0c` | 4 | `m_currentXOffset` | Constructor zeroes this field. On new samples `ApplyEffect` stores the X offset here; inside the cooldown path it reloads this value into the X register. Reject generated `m_phase`/`m_lastShakeY` swaps. |
| `+0x10` | 4 | `m_lastShakeTick` / `m_lastSampleTick` | Constructor stores `g_pTimerMgr->+0x18 - 0x3c`; `ApplyEffect` compares current tick minus this field against `0x50` and overwrites it when a new random sample is accepted. Reject generated `m_startTick` because the field is mutable cadence state, not constructor-only start time. |

Recommended field spellings for implementation:

```cpp
unsigned short m_xAmplitude;
unsigned short m_yAmplitude;
int m_currentYOffset;
int m_currentXOffset;
unsigned int m_lastShakeTick;
```

`m_horizontalAmplitude` / `m_verticalAmplitude` and `m_lastSampleTick` are acceptable if the Effects family later standardizes on longer names. The implementation should not keep raw `mbr_0x8`, `mbr_0xc`, `m_elapsed`, `m_phase`, or `m_startTick`.

## ApplyEffect Behavior

The modeled `ApplyEffect` body at `0x0055b160` has a stable source shape:

1. It reads the current tick from `g_pTimerMgr->+0x18`.
2. It generates an X offset with `_rand() % (2 * m_xAmplitude + 1) - m_xAmplitude`.
3. It generates a Y offset with `_rand() % (2 * m_yAmplitude + 1) - m_yAmplitude`.
4. If `currentTick - m_lastShakeTick <= 0x50`, it discards the fresh random values and reuses `m_currentXOffset` and `m_currentYOffset`.
5. Otherwise it accepts the fresh values, stores `m_lastShakeTick = currentTick`, `m_currentXOffset = xOffset`, and `m_currentYOffset = yOffset`, then calls the virtual at `g_activeMapPane` slot `+0x20` with argument `0`.
6. If local-player/UserPane camera-lock state is enabled, it passes the direction byte through helper `0x00505080` and suppresses one offset axis based on the returned tile delta.
7. It copies the source rectangle into a local temporary rectangle.
8. It calls `RectBounds::Offset` at `0x004b78f0` with the chosen X/Y offsets.
9. It calls `GrafPort::BlitSurface` at `0x004ba250`; the destination receiver is the first virtual argument, the source GrafPort-like argument is `g_activeMapPane`, the adjusted source rect is the local temp, the destination rect is the third virtual argument, and the mode byte is `*(g_activeMapPane + 0xb5)`.

The return register comes from `GrafPort::BlitSurface`, but the source-level virtual should still be documented as an apply/render side-effect method unless the base `ScreenEffecter` declaration later proves an integer return. The existing generated `void` return is acceptable as a high-probability class declaration, but method-body emission should preserve a note that the binary tail returns the blit helper's EAX.

## Camera-Lock And Map Helper Roles

The camera-lock branch reads `dword_67A748 + 0x1c4` and `dword_67A748 + 0x1c5`. Existing docs name the global broadly as [UID:0000QK] `g_pCollectionData`, but this use is better understood as local-player/UserPane camera state, not collection/list data:

- `+0x1c4`: best-supported source field is `m_cameraLockEnabled` or `m_cameraLockActive`.
- `+0x1c5`: best-supported source field is `m_cameraLockDirection`.

The helper at `0x00505080` is not a camera-specific helper. It is the MapPane/weather-coordinate direction helper already grouped in [UID:0001AP]. Local disassembly shows it takes an output pair and a direction byte, returns the output pair, and maps:

| Direction | Delta |
| --- | --- |
| `0` | `{-1, 0}` |
| `1` | `{0, 1}` |
| `2` | `{1, 0}` |
| `3` | `{0, -1}` |
| `4` or default | `{0, 0}` |

Recommended helper/source names:

- `MapPaneDirectionToTileDelta`
- `MapPane::GetDirectionTileDelta`
- `GetDirectionTileDelta`

The current aggregate name "direction-to-tile-offset helper" is behaviorally correct. Avoid generated `MapPane::GetCameraLockOffset` because the helper itself has no camera-state dependency and is reused by MapPane/LivingObjectPane/UserPane/object placement paths.

Axis suppression is literal:

- if returned `dy != 0`, the code zeroes the X shake offset;
- if returned `dx != 0`, the code zeroes the Y shake offset.

Do not rename fields or reorder offsets to make the branch look more intuitive. The cross-axis behavior is what the executable does.

## Destructor, Vtable, And Base Layout

Local destructor disassembly:

```asm
0055bb90 push ebp
0055bb91 mov ebp, esp
0055bb93 test byte ptr [ebp+8], 1
0055bb97 push esi
0055bb98 mov esi, ecx
0055bb9a mov dword ptr [esi], 0x6235a4
0055bba0 je 0x55bbad
0055bba2 push 0x14
0055bba4 push esi
0055bba5 call 0x5c7526
0055bbaa add esp, 8
0055bbad mov eax, esi
0055bbaf pop esi
0055bbb0 pop ebp
0055bbb1 ret 4
```

Conclusions:

- This is compiler scalar-deleting destructor glue with a source destructor body that only needs to restore/destruct the base state.
- The thunk writes the base `ScreenEffecter` vtable at `0x006235a4`.
- If `flags & 1`, it calls `0x005c7526(this, 0x14)`, matching the 20-byte class size.
- Do not emit `ScalarDeletingDestructor`, `operator_delete`, or `std::uint8_t` in source-facing C++ for the class page. Use a normal virtual destructor declaration and leave thunk implementation to generated/compiler-artifact handling.

Earthquake vtable entries verified from local PE and support docs:

| Address | Slot target | Role |
| --- | --- | --- |
| `0x00623be4` | `0x0055c1b0` | Folded true predicate for pixel-effect branch; class-level name remains `IsPixelEffecter()` or `UsesPrimaryEffectPass()`. |
| `0x00623be8` | `0x0055c1c0` | Folded false predicate/default. |
| `0x00623bec` | `0x0055c1c0` | Folded false predicate/default. |
| `0x00623bf0` | `0x0055c1d0` | `ScreenEffecter::AreAllEffectsComplete`-style aggregate predicate. |
| `0x00623bf4` | `0x0055a270` | Shared no-op/default slot. |
| `0x00623bf8` | `0x0055a280` | Shared no-op/default slot. |
| `0x00623bfc` | `0x0055bb90` | Earthquake scalar deleting destructor thunk. |
| `0x00623c00` | `0x0055b160` | Earthquake `ApplyEffect`. |

## Caller, Callee, And Reachability

Constructor:

- No direct rel32 call/jump/conditional branch to `0x0055b110` was found in the local PE scan.
- No VA/RVA/raw-offset pointer cell to `0x0055b110` was found.
- The constructor remains raw/non-modeled per existing target/runtime-cluster docs.
- The best explanation is "source constructor retained but construction route not currently recovered", not "standalone helper" or "data". It has a normal constructor prologue, vtable store, argument stores, and `ret 8`.

ApplyEffect:

- Vtable pointer cell at `0x00623c00` references `0x0055b160`.
- Callees and dependencies match support docs: `_rand`, `0x00505080`, `0x004b78f0`, `0x004ba250`, security-cookie checking, `g_pTimerMgr`, `g_activeMapPane`, and local-player/UserPane state at `dword_67A748`.
- The virtual is therefore live through the vtable even if no direct calls target the concrete body.

Destructor:

- Vtable pointer cell at `0x00623bfc` references `0x0055bb90`.
- It participates in the effecter destructor strip and calls `0x005c7526` for conditional deallocation.

MapPane/runtime ownership:

- MapPane owns the runtime `ScreenEffecter*` list fields at `+0xf8/+0xfc/+0x100` and the configuration/clear lifecycle, but the effecter classes remain under [UID:0000IZ] `Effects.cpp`.
- `EarthquakeEffecter` construction is not currently proven in `MapPaneConfigureEffectList`, whose documented modes construct WaterFilter/XWave/SolidColorFilter routes. That negative route is important: do not invent a MapPane construction caller for Earthquake until a packet/weather/effect route is found.

## Source Placement And Owner Decision

Keep `render/Effects.cpp` as the source module and [UID:0000IZ] as owner/emitter.

Reasons:

- [UID:0000IZ] groups `EarthquakeEffecter` with `ScreenEffecter`, `PixelEffecter`, overlay/filter effecters, XWave/YFlip/Lake, and runtime effecter support.
- [UID:0001YO] places the Earthquake vtable in the single-primary pixel-effect branch rather than MapPane, TimerMgr, or GrafPort.
- `ApplyEffect` depends on MapPane/TimerMgr/RectBounds/GrafPort helpers, but it owns no MapPane state except through globals and vtable calls.
- `0x004ba250` is already strongly routed to [UID:00005V] `GrafPort::BlitSurface`, and `0x004b78f0` is RectBounds offset logic; they are dependencies, not Earthquake-owned helpers.
- `0x00505080` belongs with MapPane/weather-coordinate helpers. Earthquake uses it for camera-lock axis suppression but does not own it.

Rejected source placements:

- `MapPane.cpp`: rejected because MapPane owns the active effect list and render context, not the concrete `EarthquakeEffecter` class. The vtable family and Effects file page already centralize runtime effecters.
- `TimerMgr.cpp`: rejected because TimerMgr only supplies the tick at `+0x18`.
- `GrafPort.cpp`: rejected because GrafPort only supplies the blit helper.
- One-class `class_EarthquakeEffecter.cpp`: rejected as recovered-output layout. It is a useful generated lead but support docs show the source owner is the shared `render/Effects.cpp`.

## Generated Output Corrections

The existing generated `source-3/simroot_v2/class_EarthquakeEffecter.cpp` is useful for rough behavior but should not be copied into target docs as source truth.

Corrections required:

- Replace generated `m_elapsed` with `m_currentYOffset`.
- Replace generated `m_phase` with `m_currentXOffset`.
- Replace generated `m_startTick` with `m_lastShakeTick`; the field is overwritten in `ApplyEffect`.
- Replace generated `m_lastShakeX`/`m_lastShakeY` if they are assigned to the wrong offsets; binary stores X at `+0x0c` and Y at `+0x08`.
- Replace `g_pTimer` with documented `g_pTimerMgr`.
- Replace `g_pMapPane`/`g_pParcelPane` with documented `g_activeMapPane` unless the Effects family later chooses a source spelling.
- Replace `g_pAppMan->m_isCameraLocked` and `g_pAppMan->m_cameraLockMode` with local-player/UserPane state through `dword_67A748 + 0x1c4/+0x1c5`; the exact global source name remains open but the generated owner is unsupported.
- Replace `MapPane::GetCameraLockOffset` with a direction-to-tile-delta helper name.
- Replace `OffsetRect` with `RectBounds::Offset`.
- Replace `GrafPort::BitBlt` with [UID:000167] `GrafPort::BlitSurface`.
- Do not emit `ScalarDeletingDestructor`, `operator_delete`, or modern fixed-width `std::uint8_t` in class-level source.

## Heuristic / Inference Reanalysis And Validation

Rule 26/source-quality blockers from the current page and their resolution:

| Blocker | Reanalysis result |
| --- | --- |
| Raw constructor promotion | Still raw/non-modeled and no direct route found. It is nevertheless a source constructor by shape and vtable store. Keep the caveat, but name it as `EarthquakeEffecter::EarthquakeEffecter` in behavior docs. |
| Final amplitude field names | Resolved to `m_xAmplitude` and `m_yAmplitude` or longer horizontal/vertical equivalents. `movzx` use supports unsigned 16-bit storage. |
| Current offset field names | Resolved to `m_currentYOffset` at `+0x08` and `m_currentXOffset` at `+0x0c`. The apparent non-source order is real and should be preserved. |
| Timer baseline/cadence state | Resolved to `m_lastShakeTick` / `m_lastSampleTick`; constructor seeds it with `currentTick - 60`, and `ApplyEffect` refreshes only when delta is greater than `0x50`. |
| Camera-lock state | High-probability local-player/UserPane fields at `dword_67A748 + 0x1c4/+0x1c5`, best named `m_cameraLockEnabled` and `m_cameraLockDirection`. Exact original spelling is not proven, so support docs should mark the names as inferred. |
| Map direction helper | Resolved behaviorally as direction-to-tile-delta helper at `0x00505080`. It is not camera-specific. |
| Map scroll/reset helper | Still not exact by name. Binary calls `g_activeMapPane` vslot `+0x20` with `0` after accepting a new sample. Best description is map scroll/visible invalidation/reset. Do not promote a final source name until MapPane vtable docs confirm slot `+0x20`. |
| ApplyEffect signature | High-probability class declaration can use `void ApplyEffect(GrafPort *destination, const RectBounds *sourceRect, const RectBounds *destinationRect)`. The binary tail returns the blit helper's EAX, so exact return type remains a method-body concern until the base declaration is finalized. |
| Destructor placement | Resolved as compiler scalar deleting destructor thunk for normal virtual destructor declaration. No source-authored `ScalarDeletingDestructor` method should be emitted. |
| Source owner/source file | Resolved to `render/Effects.cpp` under [UID:0000IZ]. Dependencies remain MapPane, TimerMgr, RectBounds, and GrafPort. |
| First-draft C++ | Declaration-only class C++ is now eligible. Method bodies should remain deferred until exact Earthquake method children or accepted method body pages exist. |

Open questions that remain after this pass:

1. Which route constructs `EarthquakeEffecter` at runtime?
   - Evidence checked: target class page, runtime cluster, MapPane configure/clear lifecycle, vtable data, local PE call/pointer scan for `0x0055b110`.
   - Negative evidence: no rel32 call/jump/conditional branch or pointer cell to `0x0055b110` was found locally; MapPane configure docs do not construct Earthquake.
   - Highest-probability direction: retained source constructor used by an effect/weather/packet route not yet split or not directly visible through a simple static call scan. This blocks method-body emission and keeps confidence below 90, but it does not block class declaration C++.

2. Exact original spellings for local-player camera-lock fields.
   - Evidence checked: target generated output, `g_pCollectionData` doc, ApplyEffect branch, direction helper behavior.
   - Negative evidence: no support doc currently names `+0x1c4/+0x1c5`; generated `g_pAppMan` spelling conflicts with documented global ownership.
   - Highest-probability direction: `m_cameraLockEnabled` / `m_cameraLockDirection` or `m_cameraLockActive` / `m_cameraLockDirection` under UserPane/local-player state. This is enough for behavior docs, but generated method C++ should avoid hard dependency on final spellings until support docs accept them.

3. Exact source name for the MapPane vslot `+0x20` call.
   - Evidence checked: local disassembly and existing MapPane file docs.
   - Negative evidence: current target/support docs describe it only as map scroll/reset. The vtable slot name is not proven by the docs checked for this pass.
   - Highest-probability direction: an invalidate/reset/scroll-update method taking a zero argument, called after a new shake sample to force redraw or reset map scroll state. Use descriptive prose until MapPane vtable/source docs resolve the slot.

## First-Draft C++ Recommendation

Emit a class-level declaration in [UID:000046] if the implementation callback accepts this report. Do not emit Earthquake method bodies yet.

Recommended declaration-only C++:

```cpp
class EarthquakeEffecter : public PixelEffecter
{
public:
    EarthquakeEffecter(unsigned short xAmplitude, unsigned short yAmplitude);
    virtual ~EarthquakeEffecter();

    virtual void ApplyEffect(GrafPort *destination,
                             const RectBounds *sourceRect,
                             const RectBounds *destinationRect);

private:
    unsigned short m_xAmplitude;
    unsigned short m_yAmplitude;
    int m_currentYOffset;
    int m_currentXOffset;
    unsigned int m_lastShakeTick;

    [[CHILDREN]]
};
```

Justification:

- Class identity, base class, owner, vtable, field layout, and method names are strong enough for a declaration.
- The class declaration removes stale "no code below 90/90 gate" language that no longer matches current B-agent practice.
- It avoids the unsafe parts of current generated output: raw constructor body, unresolved constructor route, camera-lock global spelling, unresolved MapPane vslot name, and scalar deleting destructor artifact.

Exact method-body defer proof:

- `0x0055b110` is constructor-shaped but still raw/non-modeled and has no direct caller/pointer route in the local PE scan.
- `ApplyEffect` has clear behavior but depends on accepted support names for local-player camera-lock fields and MapPane vslot `+0x20`.
- There are no exact by-memory children for Earthquake constructor/apply/destructor analogous to YFlip's exact split pages, so placing method bodies in the class page would mix source-quality declaration work with unsplit method reconstruction.

If the supervisor prefers no C++ until exact children exist, the strongest target-specific no-code proof is the three bullets above. My recommendation remains declaration-only C++ because the class-level facts are now stable and the method-body risks can be contained by `[[CHILDREN]]`.

## Score Recommendation

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:88
CANONICAL_OWNER:0000IZ
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IZ
```

Rationale:

- Completion improves from `85` to `87` because the field layout, cadence, camera-lock helper role, generated-output corrections, and declaration-only C++ route are now concrete.
- Confidence improves from `86` to `88` because local PE evidence agrees with prior IDA-backed docs for constructor bytes, vtable slots, destructor, and helper dependencies.
- Do not raise above `88` yet because constructor reachability, exact camera-lock field spellings, and exact Earthquake method children remain unresolved.

## Exact Implementation Checklist

Target [UID:000046] `by-class/EarthquakeEffecter.md`:

- Update metadata to `COMPLETION:87`, `CONFIDENCE:88`; keep owner/emitter [UID:0000IZ].
- Replace stale "below active `90/90+` code-entry gate" language with the current declaration-only recommendation and method-body defer proof.
- Add a field-layout table with offsets `+0x04`, `+0x06`, `+0x08`, `+0x0c`, `+0x10` and the names recommended above.
- Update constructor notes with exact half-open range `0x0055b110-0x0055b151`, `ret 8`, padding `0x0055b151-0x0055b160`, `g_pTimerMgr->+0x18 - 0x3c`, and the no-route proof.
- Update `ApplyEffect` notes with random offset generation, `0x50` cadence, reuse/current sample behavior, MapPane vslot `+0x20` call, camera-lock axis suppression, `RectBounds::Offset`, and `GrafPort::BlitSurface`.
- Update destructor notes with the scalar deleting thunk range, base vtable reset to `0x006235a4`, conditional `0x005c7526(this, 0x14)`, and source destructor declaration policy.
- Add a dedicated `## Heuristic / Inference Reanalysis And Validation` section using this report's blocker table.
- Insert the declaration-only `RECONSTRUCTION_CPP` block above, or document the exact no-code proof if supervisor declines class declaration emission.
- Add change history entry: B007 2026-06-19 source-quality pass resolving field/cadence/camera-lock/helper naming, raising score to `87/88`, and recommending declaration-only C++.

Support docs to synchronize if accepted:

- [UID:0000IZ] `by-file/Effects.md`: update Earthquake row/details with resolved 20-byte layout, cadence, camera-lock direction helper, declaration-only readiness, and generated-output caveats.
- [UID:0000AI] `by-class/PixelEffecter.md`: add/refresh subclass note that Earthquake is a pixel displacement subclass whose first vtable predicate participates in the pixel-effect branch; no owner change.
- [UID:0001GE] `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`: refine Earthquake support paragraph with exact offset names, constructor seed, `0x50` cadence, helper dependencies, and no constructor route.
- [UID:0002OR] `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`: add Earthquake slot details if not already explicit: scalar destructor at `0x0055bb90`, `ApplyEffect` at `0x0055b160`, constructor store at `0x0055b114`.
- [UID:0001YO] `by-type/by-vtable/ScreenEffecterVtableFamily.md`: preserve `IsPixelEffecter()` / `UsesPrimaryEffectPass()` as class-level names and add Earthquake-specific support only if the vtable family keeps per-class notes.
- [UID:0000VE] `by-item/ScreenEffecterSmallConstructorBoundaries.md`: update Earthquake row from "zeroed state" to `m_currentXOffset`, `m_currentYOffset`, and `m_lastShakeTick = g_pTimerMgr->currentTick - 60`.
- [UID:0001AP] `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`: update `0x00505080` to a source-facing `DirectionToTileDelta`/`GetDirectionTileDelta` helper with direction mapping and note that the jump table/data span through `0x00505100` belongs to the helper evidence.
- [UID:0000QK] `by-global/g_pCollectionData.md`: add a support note that offsets `+0x1c4/+0x1c5` are local-player/UserPane camera-lock enable/direction fields inferred from Earthquake's branch; avoid treating them as collection/list data.
- [UID:0000PR] `by-global/g_activeMapPane.md`: add Earthquake consumer note for `ApplyEffect` blit source and vslot `+0x20` redraw/reset call after new shake samples.
- [UID:0000OT] `by-file/TimerMgr.md` and [UID:0000SI] `by-global/g_pTimerMgr.md`: add Earthquake cadence consumer note for `+0x18` current tick if those docs keep consumer examples.
- [UID:0000N2] `by-file/RectBounds.md`: optionally add Earthquake caller note for `RectBounds::Offset`.
- [UID:000167] `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`: keep the existing GrafPort owner and Earthquake caller, and align naming in target docs to `GrafPort::BlitSurface`.
- Generated docs/output: if `auto-generated/NexusTK/render/Effects.cpp` is regenerated after target edits, ensure the emitted Earthquake contribution is declaration-only or otherwise does not import the stale `simroot_v2/class_EarthquakeEffecter.cpp` method bodies.

Suggested exact validators for implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [000046-EarthquakeEffecter-class-source-quality-removed.md](000046-EarthquakeEffecter-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add any optional support docs actually edited in the callback to the validator list. Do not edit `by-memory/-coverage-report.md` for this class-only target unless supervisor explicitly owns and applies a separate coverage change.

## Exact Supervisor-Owned Coverage Row Text

Recommended `by-class/-coverage-report.md` row:

```md
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) : reconstructable : 87% : strong : Runtime pixel displacement effecter under `render/Effects.cpp`; B007 2026-06-19 source-quality pass resolves the 20-byte layout as `PixelEffecter` plus X/Y amplitude shorts, current Y/X offsets at `+0x08/+0x0c`, and last-shake tick at `+0x10`, confirms `ApplyEffect`'s 80-tick random-offset cadence, first-sample constructor seed `g_pTimerMgr->currentTick - 60`, camera-lock axis suppression through local-player bytes `+0x1c4/+0x1c5` and MapPane direction-delta helper `0x00505080`, RectBounds offset and GrafPort blit dependencies, destructor/vtable slots, no direct raw-constructor caller/pointer route, and recommends declaration-only first-draft C++ while method bodies await exact child splits.
```

No direct `by-memory/-coverage-report.md` row change is required for this class-page score update. If the supervisor later chooses to synchronize the runtime-cluster row, the support detail should be applied as a separate supervisor-owned coverage update.

## Scoped Validator Baseline

Baseline command run before report edits:

> Executable block R002 was removed from this report and preserved verbatim in [000046-EarthquakeEffecter-class-source-quality-removed.md](000046-EarthquakeEffecter-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `ok: 1`
- Direct target check line: `ok 000046 by-class/EarthquakeEffecter.md UID header exists`
- Dry-run validator also reported registry/autogen noise and no by-* writes because `--apply` was not used.

## Final Report-Only Statement

This report was created as a report-only B-agent source-quality pass for [UID:000046] `by-class/EarthquakeEffecter.md`. No by-* documentation files were edited, and `by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/000046-EarthquakeEffecter-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"000046"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000046-EarthquakeEffecter-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/000046-EarthquakeEffecter-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000046"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
