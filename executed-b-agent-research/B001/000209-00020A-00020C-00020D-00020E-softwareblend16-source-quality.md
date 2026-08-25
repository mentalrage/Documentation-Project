** TARGET-REPORT-UID:000209 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000209 / 00020A / 00020C / 00020D / 00020E SoftwareBlend16 MMX And Byte-Span Source-Quality Research

## Finalized Report / Current Recommendation
- Current recommendation: keep all five targets as reconstructable, source-authored SoftwareBlend16 free/static render helpers owned and emitted by [UID:0000NT] `SoftwareBlend16`, raise each target from `82/90` to `86/91`, and keep formal `RECONSTRUCTION_CPP` blank for this pass.
- Final disposition: no split, no owner/emitter change, no non-emitting reclassification. The exact helper signatures, argument names, source placement, scratch/constant ownership, caller routes, and padding state are now defensible, but final C++ should wait for a SoftwareBlend16-wide MMX source-form pass.
- Required action: supervisor should update the five target docs with the source-facing names/signatures and first-draft policy below, refresh the five `by-memory/-coverage-report.md` rows, and leave generated C++ blank.
- Confidence: high for behavior/ownership/ranges/signatures; medium-high for exact original source spelling and final source form because no original symbols/source breadcrumbs survive and the MMX bodies strongly imply MSVC inline assembly.

## Supporting Research

## Target
- Assignment: `B001-goal2-softwareblend16-mmx-byte-span-source-quality-000209-00020A-00020C-00020D-00020E-20260617`.
- Primary targets:
  - [UID:000209] `by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md`
  - [UID:00020A] `by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md`
  - [UID:00020C] `by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md`
  - [UID:00020D] `by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md`
  - [UID:00020E] `by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md`
- Current state: all five are `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, with blank formal C++.
- Report-only constraints followed: no by-* docs, generated files, source files, IDA DB, or `by-memory/-coverage-report.md` were edited.

## Executive Recommendation
- Keep the target names as useful compact descriptive names:
  - `Rgb565TransparentAlphaBlendMmxBlocks`
  - `Rgb565AlphaMapMmxBlocks`
  - `ByteSpanCopyRows`
  - `ByteSpanAddRows`
  - `ByteSpanSubtractRows`
- Recommended signatures:

```cpp
static void __cdecl Rgb565TransparentAlphaBlendMmxBlocks(
    const uint16_t* sourcePixels,
    int sourcePitchBytes,
    uint16_t* destinationPixels,
    int destinationPitchBytes,
    uint8_t sourceWeight32,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl Rgb565AlphaMapMmxBlocks(
    uint16_t* rgb565Pixels,
    int rgb565PitchBytes,
    const uint8_t* alphaBytes,
    int alphaPitchBytes,
    int blockCount4Pixels,
    int rowCount);

static void __cdecl ByteSpanCopyRows(
    const uint8_t* sourceBytes,
    int sourcePitchBytes,
    uint8_t* destinationBytes,
    int destinationPitchBytes,
    int widthBytes,
    int rowCount);

static void __cdecl ByteSpanAddRows(
    const uint8_t* sourceBytes,
    int sourcePitchBytes,
    uint8_t* destinationBytes,
    int destinationPitchBytes,
    int widthBytes,
    int rowCount);

static void __cdecl ByteSpanSubtractRows(
    const uint8_t* sourceBytes,
    int sourcePitchBytes,
    uint8_t* destinationBytes,
    int destinationPitchBytes,
    int widthBytes,
    int rowCount);
```

- Return type should be `void` for all five despite Hex-Rays using `int` or pointer returns. Every caller discards the register result, and each body is a side-effect render helper.
- Source form: best inference is file-local/static MSVC x86 inline assembly or assembly-backed helpers, not plain compiler-generated intrinsics. The evidence is `pushaw`/`popaw`, explicit `emms`, MMX qword operations, scratch qword memory operands, and hand-managed register preservation.

## Supervisor Active Recheck
- The current task does not require creating children. All five targets are exact functions with known padding before/after.
- This report closes the stale open questions from the target pages: helper names/signatures, argument roles, ownership route, source shape, scratch/constant ownership, raw caller caveat, and active first-draft C++ policy.
- The only reason final C++ remains blank is source-form safety, not missing behavior evidence.

## Inference Research Guidance Check
- Existing docs were treated as leads. IDA MCP confirms their function bounds, xrefs, row/block behavior, constants, and padding.
- Existing docs are stale where they cite the older `95/95` final-C++ gate and where they leave helper signatures/source form open.
- Current by-structure policy allows C++ once the numerical/emitter gate clears, but this is a minimum gate. These targets still need a SoftwareBlend16-wide assembly/intrinsic style decision before final source can be safely inserted.

## Heuristic / Inference Reanalysis And Validation
- Helper names and source-facing roles:
  - [UID:000209] is best kept as `Rgb565TransparentAlphaBlendMmxBlocks`: the raw parent [UID:000207] calls it at `0x00460818` after computing `width / 4`; it receives a source-side weight (`32 - alpha32` from the parent), expands source/inverse weights into [UID:00028W] scratch qwords, blends four RGB565 pixels per qword, and preserves destination lanes when the source word is zero.
  - [UID:00020A] is best kept as `Rgb565AlphaMapMmxBlocks`: caller `sub_460410` at `0x0046043f` passes the RGB565 row, RGB565 pitch, alpha-byte row, alpha pitch, four-pixel block count, and row count. The helper unpacks four alpha bytes and multiplies/clamps RGB565 channels in place.
  - [UID:00020C]/[UID:00020D]/[UID:00020E] are row-level byte-span copy/add/subtract helpers. They split `widthBytes` into `width / 8` block calls and `width % 8` scalar tails, then step rows by source/destination pitches.
- Calling convention and prototypes:
  - All five are `__cdecl`; callers push arguments right-to-left and clean with `add esp, 18h` or equivalent.
  - The byte-span row helpers should use `uint8_t*`, not `__m64*`, in source. Hex-Rays uses `__m64*` because the block helpers operate on qwords, but the scalar tails are byte loops and `DrawFrameWithBlendMode` passes byte mask spans.
  - The two RGB565 helpers should use `uint16_t*` for pixel rows and `uint8_t*` for alpha rows/weight, with pitch values in bytes.
  - Rejected alternative: preserving Hex-Rays return types. No caller consumes them; source should be `void`.
- Source shape:
  - Best inference: MSVC inline assembly or assembly-backed file-local helpers. The MMX functions include `pushaw`/`popaw`, explicit `emms`, global scratch qwords, and MMX instructions that are unlikely to be emitted from ordinary portable C++.
  - Intrinsics-only source is possible for arithmetic but less likely as the exact original source because intrinsics would not naturally require the global scratch qword pattern or manual all-register save/restore. The decompiler's `_m_*` expressions are an analysis representation, not source proof.
  - Pure portable C++ is rejected for formal output now. It could be behavior-equivalent, but it would not be a defensible original-source representation for these optimized MMX paths.
- Ownership and source placement:
  - [UID:0000NT] `SoftwareBlend16` remains the best direct owner/emitter. The five helpers are stateless low-level span/block render math in the contiguous SoftwareBlend16 helper cluster and use SoftwareBlend16 constants/scratch data.
  - [UID:0000HF] `AlphaMaskSurface` is a plausible consumer-side alternative for [UID:00020C]/[UID:00020D]/[UID:00020E] because [UID:0000YN] `DrawFrameWithBlendMode` is their only direct caller, but it is weaker. The helpers do not access AlphaMaskSurface layout; they are generic byte-span primitives and are physically grouped with the SoftwareBlend16 byte block helpers.
  - `Surface`, `GrafPort`, and software-render callback families are rejected as direct owners. They own surfaces, render dispatch, or callback bodies that consume these primitives; they do not own this local arithmetic/helper cluster.
- Scratch/global and constants:
  - [UID:00028W] belongs with SoftwareBlend16. `qword_67A810`/`qword_67A818` are read/written only by [UID:000209] for source/inverse weight vectors.
  - [UID:0002OO] belongs with SoftwareBlend16. [UID:000209] uses RGB565 red/blue and green masks at `0x00610e98`/`0x00610ea0`; [UID:00020A] uses alpha-map masks at `0x00610ec8`/`0x00610ed0`.
  - A clean rebuilt source could compute these as local `__m64` temporaries, but the current binary shape records writable scratch globals; target docs should document both the binary fact and the source-form caveat.
- Raw caller/no-function caveat:
  - [UID:000209] has one code xref from raw [UID:000207] at `0x00460818`; `lookup_funcs 0x004607e0` reports `Not a function`, while `lookup_funcs 0x004609e0` reports a normal modeled function. Treat this as raw-parent evidence, not no-use evidence.
  - [UID:00020A] has a normal modeled caller from `sub_460410` at `0x0046043f`.
  - [UID:00020C]/[UID:00020D]/[UID:00020E] have normal modeled callers from [UID:0000YN] at `0x00462f03`, `0x00462eef`, and `0x00462edb`.
- Range and padding:
  - [UID:000209] exact `0x004609e0-0x00460af9`; `0x00460af9-0x00460b00` is `0xcc` alignment.
  - [UID:00020A] exact `0x00460c90-0x00460d51`; `0x00460d51-0x00460d60` is `0xcc` alignment.
  - [UID:00020C] exact `0x00460df0-0x00460e79`; padding exists before `0x00460df0` and after `0x00460e79`.
  - [UID:00020D] exact `0x00460e80-0x00460f09`; padding exists before `0x00460e80` and after `0x00460f09`.
  - [UID:00020E] exact `0x00460f10-0x00460f99`; padding exists before `0x00460f10` and after `0x00460f99`.
  - No split, merge, or ignored-row creation is needed.
- Generated output and first-C++ impact:
  - `auto-generated/-ag-memory-coverage.md` currently marks all five as `emits` through [UID:0000NT] but `no` code, and `auto-generated/NexusTK/render/SoftwareBlend16.cpp` is zero bytes.
  - This is acceptable until a coherent SoftwareBlend16 source-form pass populates MMX block helpers, constants, scratch policy, and row wrappers together.
  - Rejected alternative: inserting only the row-helper C++ now. [UID:00020C]/[UID:00020D]/[UID:00020E] call [UID:00020G]/[UID:00020H]/[UID:00020I], whose final C++ is also blank; emitting just wrappers would create incomplete generated source and would not solve the MMX source-style issue.

## Evidence Standards Used
- IDA MCP session `b003_00018a_ime_comp_20260617`; `server_health` reported `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- IDA facts used: `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, caller push windows, constant xrefs, and generated coverage/source state.
- Documentation evidence used: target pages, [UID:0000NT] SoftwareBlend16, [UID:000207] raw parent, [UID:0000YD] RGB555/RGB565 helpers, [UID:0000YN] DrawFrameWithBlendMode, [UID:00020G]/[UID:00020H]/[UID:00020I] block helpers, [UID:0002OO], [UID:00028W], `by-memory/-ignored.md`, and executed B001 SoftwareBlend16 reports for [UID:000206] and [UID:0000YG].

## IDA MCP Facts
- `lookup_funcs`:
  - `0x004607e0`: not a function.
  - `0x00460410`: `sub_460410`, size `0xe4`.
  - `0x004609e0`: `sub_4609E0`, size `0x119`.
  - `0x00460c90`: `sub_460C90`, size `0xc1`.
  - `0x00460df0`: `sub_460DF0`, size `0x89`.
  - `0x00460e80`: `sub_460E80`, size `0x89`.
  - `0x00460f10`: `sub_460F10`, size `0x89`.
  - `0x00461000`: `ByteSpanCopy8Blocks`, size `0x4b`.
  - `0x00461050`: `sub_461050`, size `0x4e`.
  - `0x004610a0`: `sub_4610A0`, size `0x4e`.
  - `0x00462e10`: `sub_462E10`, size `0x10e`.
- Xrefs:
  - [UID:000209] has one raw code xref from `0x00460818`, with no containing function.
  - [UID:00020A] has one modeled code xref from `0x0046043f` inside `sub_460410`.
  - [UID:00020C] has one modeled code xref from `0x00462f03`.
  - [UID:00020D] has one modeled code xref from `0x00462eef`.
  - [UID:00020E] has one modeled code xref from `0x00462edb`.
- Callees:
  - [UID:000209] and [UID:00020A] have no callees.
  - [UID:00020C] calls `ByteSpanCopy8Blocks` at `0x00460e1f`.
  - [UID:00020D] calls `sub_461050` at `0x00460eaf`.
  - [UID:00020E] calls `sub_4610A0` at `0x00460f3f`.
- Constant/scratch xrefs:
  - `0x0067a810` xrefs at `0x004609f3` and `0x00460a1a`; `0x0067a818` xrefs at `0x00460a0c` and `0x00460a21`.
  - `0x00610e98` xref at `0x00460a28`; `0x00610ea0` xref at `0x00460a2f`.
  - `0x00610ec8` xref at `0x00460ca4`; `0x00610ed0` xref at `0x00460cab`.
- Caller push-window facts:
  - `sub_460410` pushes row count, block count, alpha pitch, alpha pointer, RGB565 pitch, and RGB565 pointer before [UID:00020A].
  - [UID:0000YN] pushes height, width, destination pitch, destination pointer, source pitch, and source pointer before [UID:00020C]/[UID:00020D]/[UID:00020E].

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004609e0-0x00460af9` | [UID:000209] `Rgb565TransparentAlphaBlendMmxBlocks` | MMX transparent weighted RGB565 four-pixel block helper | `TRUE` | [UID:0000NT] | `86/91` | keep blank C++ |
| `0x00460c90-0x00460d51` | [UID:00020A] `Rgb565AlphaMapMmxBlocks` | MMX RGB565 alpha-byte map block helper | `TRUE` | [UID:0000NT] | `86/91` | keep blank C++ |
| `0x00460df0-0x00460e79` | [UID:00020C] `ByteSpanCopyRows` | strided byte-span copy row wrapper | `TRUE` | [UID:0000NT] | `86/91` | keep blank C++ |
| `0x00460e80-0x00460f09` | [UID:00020D] `ByteSpanAddRows` | strided byte-span wrapping add row wrapper | `TRUE` | [UID:0000NT] | `86/91` | keep blank C++ |
| `0x00460f10-0x00460f99` | [UID:00020E] `ByteSpanSubtractRows` | strided byte-span wrapping subtract row wrapper | `TRUE` | [UID:0000NT] | `86/91` | keep blank C++ |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00460818` | raw [UID:000207] -> [UID:000209] | Transparent weighted RGB565 span bulk path. |
| `0x0046043f` | `sub_460410` -> [UID:00020A] | RGB565 alpha-map bulk path before scalar tail. |
| `0x00462f03` | [UID:0000YN] mode `0` -> [UID:00020C] | Alpha-mask/frame byte copy mode. |
| `0x00462eef` | [UID:0000YN] mode `1` -> [UID:00020D] | Alpha-mask/frame wrapping add mode. |
| `0x00462edb` | [UID:0000YN] mode `2` -> [UID:00020E] | Alpha-mask/frame wrapping subtract mode. |
| `0x00460e1f` | [UID:00020C] -> [UID:00020G] | Eight-byte copy bulk helper. |
| `0x00460eaf` | [UID:00020D] -> [UID:00020H] | Eight-byte `paddb` bulk helper. |
| `0x00460f3f` | [UID:00020E] -> [UID:00020I] | Eight-byte `psubb` bulk helper. |

## Documentation Evidence And IDA Status
- Existing docs confirmed by IDA: target ranges, caller/callee sets, row/block splits, scalar tails, RGB565 constants, scratch qwords, and padding.
- Existing docs needing update: old wording says final C++ is blank under the old `95/95` gate. Replace with the current reason: the numerical/emitter gate is met after the proposed score bump, but formal output is unsafe until MMX inline-assembly/intrinsic source form is settled for the helper family.
- Generated state: all five route to `auto-generated/NexusTK/render/SoftwareBlend16.cpp` but have no code; the generated file is currently zero bytes.

## Ranked Ownership Analysis

### 1. [UID:0000NT] SoftwareBlend16
- Evidence for: contiguous low-level RGB555/RGB565/byte-span helper cluster; direct use of [UID:0002OO] and [UID:00028W]; no object state; SoftwareBlend16 already owns sibling span/block/pixel helpers and has valid `NexusTK/render/` output route.
- Evidence against: byte-span row helpers have sole direct caller [UID:0000YN] under AlphaMaskSurface.
- Decision: accept. The sole caller is consumer evidence; the helper bodies themselves are generic low-level span math.

### 2. [UID:0000HF] AlphaMaskSurface
- Evidence for: [UID:00020C]/[UID:00020D]/[UID:00020E] are called by [UID:0000YN] `DrawFrameWithBlendMode`, which clips and draws alpha-mask byte frames.
- Evidence against: helpers do not access AlphaMaskSurface layout, are physically located in the SoftwareBlend16 helper island, and share sibling byte block helpers with SoftwareBlend16.
- Decision: reject as direct owner for the target helpers. Keep AlphaMaskSurface as caller/consumer.

### 3. Surface, GrafPort, software-render callbacks
- Evidence for: these helpers are eventually consumed by render callbacks and surface update paths.
- Evidence against: no direct object/state dependency; targets are stateless primitive math; higher-level callback ownership is already documented separately.
- Decision: reject as direct owner.

## First-Draft C++ Recommendation
Do not populate formal `RECONSTRUCTION_CPP` for [UID:000209], [UID:00020A], [UID:00020C], [UID:00020D], or [UID:00020E] in this pass.

Precise reason:
- The five targets clear the numerical/emitter minimum after the recommended score update, but final source shape is still unsafe. The original code most likely used MSVC x86 `__asm` blocks or assembly-backed local helpers, based on explicit `pushaw`/`popaw`, `emms`, MMX instructions, and writable qword scratch operands.
- Behavior-equivalent portable C++ or Hex-Rays `_m_*` intrinsic code would not be a defensible original mid-2000s source representation for these optimized paths.
- [UID:00020C]/[UID:00020D]/[UID:00020E] depend on sibling block helpers [UID:00020G]/[UID:00020H]/[UID:00020I], which also have blank final C++. Emitting only wrappers would create incomplete generated source and would not resolve the MMX style issue.
- The right next source pass should populate a coherent `SoftwareBlend16.cpp` style covering MMX block helpers, byte block helpers, constants/scratch policy, and row wrappers together.

Documentation-only source direction:

```cpp
// Do not paste this into target RECONSTRUCTION_CPP blocks yet.
// Final pass should choose a consistent MSVC x86 inline-assembly or intrinsic style.
static void __cdecl ByteSpanAddRows(const uint8_t* src, int srcPitch,
                                    uint8_t* dst, int dstPitch,
                                    int widthBytes, int rows);
```

## Score And Metadata Recommendations
- [UID:000209]: `82/90 -> 86/91`; keep `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, blank formal C++.
- [UID:00020A]: `82/90 -> 86/91`; keep `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, blank formal C++.
- [UID:00020C]: `82/90 -> 86/91`; keep `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, blank formal C++.
- [UID:00020D]: `82/90 -> 86/91`; keep `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, blank formal C++.
- [UID:00020E]: `82/90 -> 86/91`; keep `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, blank formal C++.
- Rationale for completion `86`: exact behavior/range/caller/signature/source placement and first-C++ policy are now resolved, but final source body style is intentionally not populated.
- Rationale for confidence `91`: IDA MCP, existing docs, constants/scratch xrefs, caller windows, sibling helper docs, and generated state agree. Confidence stays below final audit because original helper names and exact inline-asm source spelling remain inferred.

## Support Docs To Update
- [UID:0000NT] `by-file/SoftwareBlend16.md`: add a body note that the current best source-form inference is MSVC x86 inline assembly or assembly-backed static helpers for the MMX block family, and that [UID:000209]/[UID:00020A]/[UID:00020C]/[UID:00020D]/[UID:00020E] remain blank formal C++ until a coherent SoftwareBlend16-wide source pass handles block helpers/constants/scratch together. No parent score change required.
- [UID:00028W] `MmxBlendWeightScratchData`: no metadata change; optionally add that [UID:000209]'s `sourceWeight32` and inverse weight qwords are binary scratch globals but may become local `__m64` temporaries in a clean final source if the MMX behavior is preserved.
- [UID:0002OO] `SoftwareBlend16ReadOnlyConstants`: no metadata change; optionally add source-facing constant name suggestions:
  - `kRgb565RedBlueLaneMaskQword` for `0x00610e98`
  - `kRgb565GreenLaneMaskQword` for `0x00610ea0`
  - `kRgb565AlphaMapRedBlueClampMaskQword` for `0x00610ec8`
  - `kRgb565AlphaMapGreenClampMaskQword` for `0x00610ed0`
- [UID:00020H]/[UID:00020I]: no required metadata change. Optional IDA rename candidates are `ByteSpanAdd8Blocks` and `ByteSpanSubtract8Blocks`, but do not apply IDA edits from this report-only task.
- [UID:0000YN] `DrawFrameWithBlendMode`: no metadata change; if edited later, cross-reference that the byte-span helpers are SoftwareBlend16-owned low-level primitives despite being called from AlphaMaskSurface mode dispatch.

## Supervisor-Owned Coverage Rows
Replace the existing five rows in `by-memory/-coverage-report.md` in the same address-order neighborhood with:

```markdown
    - [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md) 0x004609e0-0x00460af9 | function | Rgb565TransparentAlphaBlendMmxBlocks : reconstructable : 86% : very strong : B001 source-quality recheck confirms exact MMX transparent weighted RGB565 four-pixel block helper, raw parent call at 0x00460818, no callees, source/destination pointer and pitch order, sourceWeight32 argument from 32-alpha, blockCount4Pixels and rowCount semantics, qword scratch refs at 0x0067a810/0x0067a818, RGB565 masks at 0x00610e98/0x00610ea0, transparent-source destination preservation, SoftwareBlend16 ownership, and 0x00460af9-0x00460b00 padding; formal C++ remains blank because final MSVC inline-asm/intrinsic source form must be handled SoftwareBlend16-wide.
    - [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md) 0x00460c90-0x00460d51 | function | Rgb565AlphaMapMmxBlocks : reconstructable : 86% : very strong : B001 source-quality recheck confirms exact MMX RGB565 alpha-map four-pixel block helper, sole ApplyAlphaMap565 caller at 0x0046043f, no callees, in-place RGB565 row pointer/pitch plus alpha-byte row pointer/pitch signature, blockCount4Pixels and rowCount semantics, alpha-byte unpacking, mask refs at 0x00610ec8/0x00610ed0, SoftwareBlend16 ownership, and 0x00460d51-0x00460d60 padding; formal C++ remains blank pending SoftwareBlend16-wide MMX inline-asm/intrinsic source-form pass.
    - [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md) 0x00460df0-0x00460e79 | function | ByteSpanCopyRows : reconstructable : 86% : very strong : B001 source-quality recheck confirms exact strided byte-span copy row helper, sole DrawFrameWithBlendMode mode-0 caller at 0x00462f03, source/destination pointer and pitch signature, widthBytes/rowCount semantics, width/8 bulk split to ByteSpanCopy8Blocks at 0x00460e1f, scalar byte-copy tail, row stepping, SoftwareBlend16 ownership despite AlphaMaskSurface caller, and surrounding padding; formal C++ remains blank until sibling byte-block helpers and SoftwareBlend16 MMX source style are populated coherently.
    - [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md) 0x00460e80-0x00460f09 | function | ByteSpanAddRows : reconstructable : 86% : very strong : B001 source-quality recheck confirms exact strided byte-span wrapping-add row helper, sole DrawFrameWithBlendMode mode-1 caller at 0x00462eef, source/destination pointer and pitch signature, widthBytes/rowCount semantics, width/8 bulk split to ByteSpanAdd8Blocks at 0x00460eaf, scalar wrapping byte-add tail, row stepping, SoftwareBlend16 ownership despite AlphaMaskSurface caller, and surrounding padding; formal C++ remains blank until sibling byte-block helpers and SoftwareBlend16 MMX source style are populated coherently.
    - [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md) 0x00460f10-0x00460f99 | function | ByteSpanSubtractRows : reconstructable : 86% : very strong : B001 source-quality recheck confirms exact strided byte-span wrapping-subtract row helper, sole DrawFrameWithBlendMode mode-2 caller at 0x00462edb, source/destination pointer and pitch signature, widthBytes/rowCount semantics, width/8 bulk split to ByteSpanSubtract8Blocks at 0x00460f3f, scalar wrapping byte-subtract tail, row stepping, SoftwareBlend16 ownership despite AlphaMaskSurface caller, and surrounding padding; formal C++ remains blank until sibling byte-block helpers and SoftwareBlend16 MMX source style are populated coherently.
```

No `by-memory/-ignored.md` row change is needed. The existing SoftwareBlend16/render alignment entry already covers the relevant padding spans.

## Validation Commands For Supervisor
Run after applying target/support updates and coverage rows:

> Executable block R001 was removed from this report and preserved verbatim in [000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality-removed.md](000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-checks:

> Executable block R002 was removed from this report and preserved verbatim in [000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality-removed.md](000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected: five target scores update to `86/91`, autogen still routes them to `SoftwareBlend16.cpp`, and `SoftwareBlend16.cpp` remains empty until a deliberate final source pass populates the MMX helper family.

## Final Recommendation
- Exact changes recommended: update five target scores to `86/91`, add the source-facing signatures/argument names and source-form policy, replace five coverage rows, and add a SoftwareBlend16 support note.
- Exact parent assignments recommended: keep all five under [UID:0000NT] for both canonical owner and emitter.
- Exact items left without formal C++: all five, because final source must be coherent across the MMX/block helper family and should likely use MSVC x86 inline assembly or a consciously chosen intrinsic wrapper style.
- Future work outside this assignment: a SoftwareBlend16-wide final-C++ pass covering [UID:000208], [UID:000209], [UID:0000YF], [UID:0000YG], [UID:00020A], [UID:00020F]-[UID:00020I], [UID:0002OO], and [UID:00028W].

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality.md`.
- Modified: none outside the B001 research folder.
- Leases used: none required for creating a report in the Agent-B001 research folder.
- Validator commands run by B001: none; this was report-only and no by-* files were changed.

## Blockers / Next Useful Follow-Up
- No blocker to supervisor execution.
- Next useful follow-up: assign a focused SoftwareBlend16 final-source-form task that decides `__asm` versus intrinsics and populates the entire MMX helper family together, rather than adding isolated wrappers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"000209"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000209-00020A-00020C-00020D-00020E-softwareblend16-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000209"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
