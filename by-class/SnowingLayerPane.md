*** UID:0000DC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SnowingLayerPane class-owned methods, descriptor consumers, and vtable support emit on exact child pages; no duplicate broad class body is emitted here.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SnowingLayerPane : public WeatherLayerPane
{
public:
    SnowingLayerPane();
    virtual void UpdateAndRenderSnowParticles();
    virtual void RenderSnowParticles(GrafPort *target,
                                     int arg0,
                                     int arg1,
                                     int arg2);

protected:
    virtual void OnFrameChanged();

private:
    SnowParticleEntry m_snowParticles[200];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SnowingLayerPane

## Status

- Confidence: very strong for behavior, exact `0x10ac` object layout, source-ready constructor, inherited Weather state, 200-record particle storage, vtables, snow static storage, and current weather-layer source-family ownership; medium-high only for original private spellings and historical standalone-versus-umbrella disk placement.
- Current canonical source/header route: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), `NexusTK/map/WeatherLayerPane.cpp` and `WeatherLayerPane.h`.
- Historical source candidate: [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md) records a possible dedicated `SnowingLayerPane.cpp`, but no source-path/PDB evidence currently overrides the canonical route.
- Address docs: [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) and [UID:0001O0][0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex](by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md)
- Documentation basis: IDA-confirmed class ranges plus the by-file and by-memory Snowing docs below.

## Class Purpose

`SnowingLayerPane` is a weather layer pane for snow animation. It initializes a particle table, randomizes snow particle positions/types, performs thread-safe lookup-table initialization, and renders 200 snow particles through global render callbacks.

The class derives from the exact `0x10c`-byte `WeatherLayerPane` and owns one inline `SnowParticleEntry m_snowParticles[200]` array at complete offset `+0x10c`. Each entry is `0x14` bytes, so the array occupies `0xfa0` bytes and closes `sizeof(SnowingLayerPane)` at exactly `0x10ac`. There is no heap particle table or unexplained trailing instance storage.

The independent H channel emits that complete declaration at combined-header position 30, after both `SnowParticleEntry` and the complete Weather base. Natural tail padding stays implicit in `SnowParticleEntry`; no reverse-engineered padding member is introduced.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SnowingLayerPane` | `0x005c1bd0-0x005c1c7d` | Initializes pane state and 200 particle rectangle entries. |
| `UpdateAndRenderSnowParticles` | `0x005c1c80-0x005c1f4b` | Updates weather state, randomizes particles, and renders snow. |
| `OnFrameChanged` (`RandomizeSnowParticles` physical behavior) | `0x005c1f50-0x005c20d4` | Overrides the weather-layer `+0x4c` frame-change hook; after the inherited timer advances the frame, applies a 200-entry particle pass, optionally shifts 180 records by 20 entries, and creates 20 new leading particles from the first snow threshold/size tables. |
| `RenderSnowParticles` | `0x005c20e0-0x005c2227` | Initializes lookup tables and renders particle rectangles. |
| destructor thunks | `0x005c29ec-0x005c2a01` | Excluded compiler/vtable thunks that forward to the scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x005c2a20-0x005c2a5a` | Calls base destruction and optionally deletes storage. |

## 2026-07-24 UID0003O0 Constructor And Class Layout Closure

[UID:0003O0][0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor](by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md) now owns the exact source-ready no-argument constructor. The exact target is 174 bytes with SHA256 `F328CB6C86DA1506F441912CEDA6919E2DD1374623CAC3397E94F60D7953D01D`, has one MapPane setup caller at `0x0050dc17`, and is paired with a caller allocation of exactly `0x10ac` bytes.

The complete class layout is:

| Complete offset/range | Declaration/role | Evidence |
| --- | --- | --- |
| `+0x000..+0x0f7` | inherited `Pane` prefix | exact Pane extent; inherited `m_drawOnTarget` at `+0xf6` |
| `+0x0f8` | inherited `signed char m_currentFrame` | constructor writes `4`; Weather timer and Snow frame hook consume it at signed width |
| `+0x0f9` | inherited `signed char m_frameCount` | constructor writes `5`; Weather timer uses it as signed wrap count |
| `+0x0fa..+0x0fb` | inherited `short m_timerInterval` | constructor writes `200` ms; Weather timer sign-extends it |
| `+0x0fc..+0x10b` | inherited `RectBounds m_weatherBounds` | exact Weather tail and Snow update/render consumer |
| `+0x10c..+0x10ab` | `SnowParticleEntry m_snowParticles[200]` | 200 records at `0x14` stride; exact caller allocation closes the object |

`SnowParticleEntry` is source-ready for this class dependency: `RectBounds bounds` at record `+0x00`, one-byte `unsigned char type` at `+0x10`, and three bytes of natural tail padding. The constructor calls current shared helper `InitRectBounds` with `(0,800,8,808)` for every entry and sets only `type = 0`; the padding remains untouched and must not become an authored semantic member or be zeroed through `memset`/value initialization.

The constructor's optimized dword `0x00c80504` is three inherited assignments, not a packed Snow member: `m_currentFrame = 4`, `m_frameCount = 5`, and `m_timerInterval = 200`. After the 200-entry loop it sets inherited Pane `m_drawOnTarget = true`, distinct from visibility at `+0xb4`.

Primary and adjusted vptr stores to `0x006312b0`, `0x00631304`, and `0x00631334`, the implicit Weather base call, constructor EAX return, EH/cookie state, and failed-construction cleanup are compiler lowering. The exact UID0003O0 child emits the body; this class page remains a comment-plus-`[[CHILDREN]]` router and must not duplicate that method or a partial class declaration.

Header/source declaration order is a complete `RectBounds` and `InitRectBounds` declaration, `SnowParticleEntry`, `WeatherLayerPane : public Pane`, then `SnowingLayerPane : public WeatherLayerPane`. The accepted current route is `WeatherLayerPane.h` plus `WeatherLayerPane.cpp`. A dedicated historical `SnowingLayerPane.cpp` remains recorded, but physical-file uncertainty no longer blocks the constructor or class layout.

Rejected class-level alternatives are an opaque packed state integer, pointer/heap particle storage, explicit source padding, explicit vptr writes, MapPane ownership, vtable/index ownership, and hand-authored compiler cleanup. Original private lexical spellings and exact historical disk partition remain confidence limits rather than reasons to expose raw offsets or decompiler labels.

## Evidence Notes

- IDA MCP confirms the constructor, update/render methods, and scalar deleting destructor as real functions.
- IDA MCP also confirms excluded thunk starts at `0x005c29ec` and `0x005c29f7`.
- 2026-05-24 IDA recheck ties constructor call-in to `MapPane::SetMapState` at `0x0050dc17` and vtable refs to `0x006312f4`, `0x006312fc`, `0x006312c0`, and `0x006312b0`.
- The excluded thunk starts overflow the compact class-method aggregate and remain ownership caveats rather than reasons to widen the Snowing method range.
- The broad legacy range crosses [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md) code beginning at `0x005c2230`; migrate from the shared island by per-method ownership.
- `MapPane::SetMapState` calls into weather-layer construction/destruction behavior when snow weather is selected.
- High-blast globals around `DAT_0067a764`, `DAT_0069b3e8`, and `DAT_0069b3fc` remain unresolved aliases and should be named with a broader render/global pass.
- Exact snow declarations are tracked in [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md) and emitted by [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md): target-port thresholds/sizes/patterns at `0x00670784-0x006707ac` and main-view counterparts at `0x006707ac-0x006707d4`. Descriptor tables remain at `0x0069bf98`/`0x0069bff0`, with guards at `0x0069bfe8`/`0x0069c040`, under UID0001Q4.
- The base and sibling weather layers are documented as [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md), [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md).
- Provisional helper/base aliases such as `InitializeSnowLookupDescriptor` and `TextButtonExControlPane::~TextButtonExControlPane` should not drive ownership decisions; keep ownership anchored to IDA function ranges and weather-layer field behavior.

## RandomizeSnowParticles Source-Quality Notes

2026-06-23 B003 incorporated the accepted MCP-backed source-quality recheck for [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md). The final evidence pass used MCP session `b880584f` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The method remains an exact [UID:0000DC] class-owned virtual method and is not a class-level C++ emitter on this page.

Accepted class-level facts:

- MCP function/range: `lookup_funcs 0x005c1f50` returns `sub_5C1F50`, size `0x184`; `disasm` reports 126 instructions and ends at `0x5c20d3`; `decompile` confirms refs to `dword_67A764`, `_rand`, `sub_4B7E10`, `_memmove_0`, `unk_670785`, and `byte_670788`.
- Route: MCP `xrefs_to 0x005c1f50` confirms the Snowing primary-vtable `+0x4c` data xref at `0x006312fc -> 0x005c1f50`. This is the `SnowingLayerPane::OnFrameChanged()` override called virtually by shared [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md) after it advances the frame and invalidates the visible bounds. Sibling Snowing vtable cells are `0x006312f4 -> 0x005c1c80` for update/render and `0x006312c0 -> 0x005c20e0` for render. MCP `func_profile` reports `caller_count:0` and `callers:[]`, so the absence of a direct code xref is expected virtual-dispatch behavior.
- Boundaries: target range is `0x005c1f50-0x005c20d4`, length `0x184`, with MCP `get_bytes` SHA256 prefix `501c485e42127a02`. Preceding padding `0x005c1f4c-0x005c1f50` is four `0xcc` bytes with SHA256 prefix `8843b54d2df63ca2`; following padding `0x005c20d4-0x005c20e0` is twelve `0xcc` bytes with SHA256 prefix `a0d08a155aa4e9aa`.
- Active-map gate: the method loads [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) at `0x0067a764` and returns early when byte `+0x3f0` is nonzero. Treat generated `g_pWeatherState` as a stale alias, not a separate Snowing global.
- Particle array: record zero begins at `this+0x10c`, the stride is `0x14` / 20 bytes (Verified with int_convert.py), and the first pass walks `0xc8` records / 200 records (Verified with int_convert.py). `this+0x29c` is entry 20 in the same array because `0x29c - 0x10c = 0x190` / 400 bytes (Verified with int_convert.py), or `20 * 0x14`.
- Rolling refresh: byte `this+0xf8` gates the refresh after the 200-entry helper pass. When clear, MCP disassembly shows `_memmove_0(this+0x29c, this+0x10c, 0xe10)` shifts 180 records because `0xe10` is 3600 bytes (Verified with int_convert.py), and the method creates 20 new leading records.
- Record layout: [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md) now carries the supported `SnowParticleEntry` interpretation: `+0x00 left`, `+0x04 top`, `+0x08 right`, `+0x0c bottom`, `+0x10 type`, `+0x11..+0x13` padding.
- Type tables: MCP `xrefs_to` confirms this method uses `s_targetSnowTypeThresholds + 1` at `0x00670785` and `s_targetSnowSizes` at `0x00670788`; values are unsigned `{0,50,100,0}` and `{4,3,0,0}`. The main-view `s_snowTypeThresholds + 1`/`s_snowSizes` group at `0x006707ad`/`0x006707b0` belongs to sibling UID0003O1.
- Historical no-code checkpoint: the 2026-06-23 pass kept UID0003O2 blank because helper `0x004b7e10`, inherited fields, table declarations, and source placement were unresolved. UID0003O0/UID0003PG close `m_currentFrame`, `m_weatherBounds`, helper shape, and current route; UID0001OO closes the exact target threshold/size declarations. The remaining blank UID0003O2 formal is now only its separately owned operation-order/body callback, not a table or class-layout blocker.
- Rejected alternatives: do not reassign this method to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) as canonical owner, [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md) as forced method owner, globals/tables, MapPane, helper owners, aggregate indexes, or no-owner/non-emitting status. These are source-family/support contexts or rejected interpretations, while the class vtable route keeps [UID:0000DC] as the owner/emitter.

## 2026-07-24 UID0003PH Inherited Timer And Frame Hook

- The base `WeatherLayerPane` constructor initializes the timer-facing state, and the Snowing constructor overwrites the packed bytes with current frame `4`, frame count `5`, and interval `200` milliseconds (`04 05 c8 00`).
- `SnowingLayerPane` inherits `WeatherLayerPane::OnTimer(int timerId, int, int)` through adjusted TimerHandler vtable cell `0x00631338 -> 0x005c13b0`. For timer ID zero, that body computes `(4 + 1) % 5`, invalidates the visible rectangle, invokes the primary-vtable `+0x4c` frame-change hook, and rearms timer zero for 200 milliseconds.
- Snowing overrides that `+0x4c` hook through `0x006312fc -> 0x005c1f50`; the supported source-facing role is `SnowingLayerPane::OnFrameChanged()`. Weather and Raining retain the inherited no-op hook, while Swallow uses a separate timer override.
- This class page records inheritance, override shape, lifecycle state, and source ordering only. It does not duplicate the `WeatherLayerPane::OnTimer` formal body or the exact Snow particle body; those remain owned by [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md) and [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md).
- Metadata and the class router formal remain unchanged at `86/88`, owner/emitter [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), with `[[CHILDREN]]`; the class page is not a duplicate method-body emitter.

## 2026-07-01 B008 Snowing Method Emitter Sync

The formal C++ block on this class page is a route marker plus `[[CHILDREN]]`, so the class page does not duplicate broad source bodies while exact child pages still assemble through the WeatherLayerPane source-family route. Exact Snowing children now own source emission: [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md) and [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md) now carry first-draft formal C++ at `88/89`; [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) remains the earlier B003 blank-C++ scope.

Accepted descriptive helper mapping for the new exact-method bodies is `BeginWeatherDraw -> 0x0069b3fc`, `RenderSnowParticle -> 0x0069b3e8`, `SetDrawColor -> 0x004b9660`, `OffsetRect -> 0x004b7e10`, and `SetRect -> 0x004b7c50`. These names are source-facing first-draft names for confirmed callees, not proof of final shared callback/type/header placement.

## 2026-07-26 UID0001OO Exact Snow Data Dependency

- UID0001OO proves one exact 80-byte mutable table formed by two byte-identical 40-byte families. Each family is an unsigned four-byte threshold array, unsigned four-byte size array, and two fixed 16-byte patterns for 4x4 and 3x3 descriptors.
- The target-port family supplies UID0003O2 threshold/size selection and UID0003O3 descriptor patterns. The main-view family supplies UID0003O1 threshold/size selection and descriptor patterns. These are dependencies of the class methods, not class-static members.
- The final four zero bytes through `0x006707d3` belong to `s_snowPatterns[1]`; they are not compiler padding. Libjpeg data begins exactly at `0x006707d4`.
- UID0001OO emits the arrays once through current UID0000P8 `WeatherLayerPane.cpp` at position 1. This class page keeps its route marker plus `[[CHILDREN]]` and does not duplicate data or method bodies.
- Historical dedicated UID0000NR file placement and raw `g_snow...`/A-D aliases remain preserved only as rejected provenance. Exact original private spellings and disk partition remain bounded confidence limits.

## 2026-06-10 Parent-Gate Evidence

B001-037 live IDA MCP reconfirmed the Snowing constructor as `0x005c1bd0-0x005c1c7e`, snow update/render methods as `0x005c1c80-0x005c1f4c`, `0x005c1f50-0x005c20d4`, and `0x005c20e0-0x005c2228`, destructor thunks as `0x005c29ec-0x005c29f7` and `0x005c29f7-0x005c2a02`, and the scalar deleting destructor as `0x005c2a20-0x005c2a5b`. The constructor is called from `MapPane::SetMapState` at `0x0050dc17`, calls the base weather constructor at `0x005c1bfb`, and stores the Snowing vtable views at `0x006312b0`, `0x00631304`, and `0x00631334` from `0x005c1c0d`, `0x005c1c18`, and `0x005c1c22`. Vtable slots point to snow method bodies at `0x006312c0`, `0x006312f4`, `0x006312fc`, and the shared timer slot at `0x00631338`.

This historical checkpoint raised the class above the strict direct-parent gate. The current formal is a route marker plus `[[CHILDREN]]`, not a blank emitter. Exact data now emits through UID0001OO and exact methods through their children; historical disk placement and shared render aliases remain confidence limits rather than empty-emitter blockers.

## Cross-References

- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md)
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0001O0][0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex](by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md)
- [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## Changes

- 2026-07-26 B002 UID0001OO class-support callback:
  - Raised `90/92` to `91/93`, retained UID0000P8 owner/emitter and the route-marker/`[[CHILDREN]]` formal, and added the exact six-array target/main dependency contract.
  - Closed the historical UID0003O2 table-declaration blocker, corrected the final pattern tail through `0x006707d4`, and separated exact array emission from class/member/method emission.
  - Preserved historical file-placement, provisional-alias, and descriptor/render-helper caveats without letting them contradict the current source-ready data route.
- 2026-07-24 Agent-B005 UID0003O0 constructor/class closure:
  - Raised `86/88 -> 90/92` while preserving owner/emitter [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), reconstructability, blank position, and the comment-plus-children router formal.
  - Added exact `0x10ac` extent, `0x10c` Weather prefix, 200-entry inline particle array, source-ready particle declaration, inherited 4/5/200-ms state, direct-target field, constructor/helper/compiler contract, dependency order, current canonical route, historical file candidate, and rejected alternatives.
  - Preserved all earlier randomize/render/vtable/table research. Older statements that field names or the file split alone require this constructor to remain blank are historical checkpoints superseded by UID0003O0; separately owned Snow methods retain their own C++ dispositions.
- 2026-07-24 B002 UID0003PH implementation callback:
  - Metadata and the class router formal are unchanged.
  - Documented inherited timer state `4/5/200`, adjusted TimerHandler route `0x00631338 -> 0x005c13b0`, `SnowingLayerPane::OnFrameChanged()` at primary-vtable `+0x4c` (`0x006312fc -> 0x005c1f50`), timer-to-hook source ordering, and the no-body-duplication boundary.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents the weather-layer role, method ranges, constructor caller, vtable refs, sibling split, globals/table cross-references, and thunk ownership caveat; confidence remains capped by unresolved render/global aliases and final source-owner placement.
- 2026-06-02 IDA/source-family refresh:
  - Changed to: completion `86`, confidence `82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000P8`.
  - Evidence: refreshed IDA confirms constructor caller `0x0050dc17`, vtable refs, Snowing-exclusive method ends, destructor thunks, and table/descriptor storage references. C++ remains blank because the class is below the 95+ final-source threshold.
- 2026-06-06 provenance cleanup:
  - Scores unchanged.
  - Evidence: removed stale generated-output framing and restated ownership cautions in terms of IDA ranges, thunk overflow, unresolved alias status, and by-* table/storage cross-references.
- 2026-06-10 B001-037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; parent unchanged.
  - Summary/evidence: live IDA MCP reconfirmed Snowing constructor/render/destructor ranges, `MapPane` caller, base-constructor call, vtable stores, method slots, adjusted thunks, and scalar-deleting destructor linkage. The class now clears the direct-parent gate for exact snow vtable data.
- 2026-06-23 B003 randomize MCP-backed source-quality incorporation:
  - Metadata unchanged.
  - Summary/evidence: incorporated [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md)'s target score lift, accepted MCP session `b880584f` range/padding proof, vtable-only route, no direct caller/direct code-xref evidence, active-map gate, 200-entry pass, 180-record shift, 20-entry leading refresh, particle record layout, first threshold/size table roles, helper/no-code blockers, and blank-C++ policy.
- 2026-07-01 B008 WeatherLayerPane empty-emitter family callback:
  - Metadata unchanged.
  - Summary/evidence: inserted a formal comment marker plus `[[CHILDREN]]` so exact child method bodies can assemble while the broad class page emits no duplicate body. Synced the class page to [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md) and [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md) first-draft formal C++ at `88/89`, preserved accepted helper-address mappings, and kept [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) as the previous blank-C++ randomize scope rather than duplicating any child body on this class page.
