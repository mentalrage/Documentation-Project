** TARGET-REPORT-UID:0002V8 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002V8 NewHumanImageLibCalculateCompositionBounds Source-Quality Report

Agent: Agent-B014  
Assignment: report-only first pass for [UID:0002V8] `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md`  
Required target: `tools/leaser/Agents/Agent-B014/research/0002V8-NewHumanImageLibCalculateCompositionBounds-source-quality.md`  
Status: report complete; no by-* implementation edits made.

## Recommendation

Improvement is available. This is not a no-improvement case.

Recommended target page outcome:

| Field | Current | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | `86` | `89` |
| `CONFIDENCE` | `87` | `90` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `CANONICAL_OWNER` | `0000LR` | `000092` |
| `EMITTER_UIDS` | `0000LR` | `000092` |

Rationale: the target is a real `NewHumanImageLib` member-style function with `this` in `ecx`, exactly two modeled NewHuman wrappers, no non-NewHuman callers, repeated access to the NewHuman part-entry vector through `this[1]`, and a validated class route through [UID:000092] `NewHumanImageLib` to file [UID:0000LR] `NexusTK/render/NewHumanImageLib.cpp`. Keeping [UID:0000LR] as the source-file cross-reference is still correct, but the direct owner/emitter should be the class for this formal member body, consistent with the repaired constructor route.

Recommended `Item Summary` replacement:

`Exact NewHumanImageLib composition-bounds member; live IDA confirms modeled range 0x004e31f0-0x004e3a2e, two wrapper callers, full 30-entry draw-order tag map, Part.tbl row offsets, riding/raw-rectangle helpers, GFACE/default/special-part paths, projection globals, and separate uncovered retained variant at 0x004e3a80-0x004e410d.`

The target range should stay `0x004e31f0-0x004e3a2e`. Do not extend it into the post-range gap.

## MCP Evidence

IDA MCP was available and used. No fallback-only report was produced.

Session and health:

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- `idb_list`: active session `80de0a67`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health(database=80de0a67)`: `status=ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, strings cache ready.
- Rework check on 2026-06-26: `idb_list` still reports active session `80de0a67` with `is_analyzing=false`; `server_health` still reports `status=ok`, Hex-Rays ready, and strings ready. `lookup_funcs` reconfirmed `0x004e31f0`, `0x004e4140`, and `0x004e4210` as modeled functions, while `0x004e3a80`, `0x004e410d`, `0x004e4205`, and `0x004e427c` are not functions. `xrefs_to` reconfirmed no xrefs to `0x004e3a80`, 31 refs to `0x004e4140`, and 18 refs to `0x004e4210`.

Function identity:

- `lookup_funcs`:
  - `0x004e31f0` -> `sub_4E31F0`, size `0x83e` / 2110 bytes. `0x83e == 2110` was checked with `tools/int_convert.py`.
  - `0x004e3a2d` remains inside `sub_4E31F0`; `0x004e3a2e` is not a function.
  - `0x004e4140` -> `sub_4E4140`, size `0xc5` / 197 bytes. `0xc5 == 197` was checked with `tools/int_convert.py`.
  - `0x004dca20` -> `sub_4DCA20`, size `0x23` / 35 bytes. `0x23 == 35` was checked with `tools/int_convert.py`.
  - `0x004e05d0` -> `sub_4E05D0`, size `0x60` / 96 bytes. `0x60 == 96` was checked with `tools/int_convert.py`.
  - `0x004e0630` -> `sub_4E0630`, size `0x29` / 41 bytes. `0x29 == 41` was checked with `tools/int_convert.py`.

Target decompile:

- `decompile 0x004e31f0` shows the exact current body:
  - Copies the 0x44-byte avatar/composition state into locals.
  - Checks `state+0x04` for the base-present gate.
  - Clears the primary bounds.
  - Handles mode byte `state+0x22 == 2` with default tile bounds.
  - Handles special part `state+0x1e != 0xffff` through `0x004e4140`, with riding overlay raw-rect union when mode is `3`.
  - Handles mode byte `state+0x22 == 1` through `GFACE.EPF`.
  - Otherwise loops 30 entries from the draw-order table and dispatches tags `0x32..0x3f`.
  - Centers final bounds by half tile width/height and optionally computes projected bounds through `g_activeMapPane` fields.

Call graph:

- `analyze_function 0x004e31f0`: callers are exactly `sub_4E09E0` and `sub_4E0B90`; callees include `sub_4E4140`, `sub_4D05A0`, `sub_4DCA20`, `sub_4E05D0`, `sub_4E0630`, `sub_4D17C0`, `sub_4D0120`, and RectBounds helpers.
- `decompile 0x004e09e0` and `decompile 0x004e0b90`: both wrappers normalize motion/frame state, call `sub_4E2110` to copy a 0x78-byte draw-order row, then call `sub_4E31F0` at `0x004e0b6e` / `0x004e0d01`.
- `decompile 0x004e2110`: clamps motion index against `(this[8] - this[7]) / 66`, clamps frame against motion row field `+0x36`, then copies `0x78` bytes from `motionRow+0x3e + 120*frame`. `0x78 == 120` was checked with `tools/int_convert.py`.

Helper evidence:

- `decompile 0x004e4140`: source-facing name `ResolveCompositionPartRect` is supported. The helper receives a 68-byte Part.tbl row base, clamps the part id to zero when out of range, selects a 32-byte frame/motion descriptor, obtains a raw rectangle from the shared descriptor table, clears the output when out of descriptor range, and applies a rectangle adjustment helper.
- `decompile 0x004dca20`: source-facing name `RidingImageLib::GetDefinitionOrDefault` is supported. It returns `this[1] + 12*index` when `this[2] > index`, otherwise returns the 12-byte zero default at `0x0069b430`.
- `decompile 0x004e05d0`: source-facing name `ClassifyHumanPartFiveBucket` is supported. It maps unsigned id ranges `0..9999`, `10000..19999`, `20000..29999`, `30000..39999`, `40000..49999` to buckets `1..5`, otherwise `0`.
- `decompile 0x004e0630`: source-facing name `ClassifyHumanPartTwoBucket` is supported. It maps `0..9999` to `1`, `10000..19999` to `2`, otherwise `0`.
- `xrefs_to 0x004d05a0`: two modeled calls inside the target (`0x004e33a4`, `0x004e394c`) and two no-function gap calls (`0x004e3cc9`, `0x004e4025`). This remains [UID:0002KT] `ResourceLayoutRawRecordGetEntryRect`, not NewHuman-owned code.

Boundary and gap evidence:

- `get_bytes 0x004e3a20 size 32`: target tail contains the security-cookie epilogue and `retn 1Ch` ending at exclusive `0x004e3a2e`, followed by `66 90` and target switch-table data.
- `xrefs_to 0x004e3a30`: one data xref from target switch at `0x004e34db`.
- `xrefs_to 0x004e3a64`: one data xref from target nested switch at `0x004e36c2`.
- `insn_query 0x004e3a2e-0x004e4140`: no modeled functions; it shows:
  - `0x004e3a2e-0x004e3a30`: alignment.
  - `0x004e3a30-0x004e3a74`: target switch tables.
  - `0x004e3a74-0x004e3a80`: `0xcc` alignment.
  - `0x004e3a80-0x004e410d`: complete unmodeled executable stack-cookie body ending in `retn 1Ch`.
  - `0x004e4110-0x004e413c`: jump table for the unmodeled body.
  - `0x004e413c-0x004e4140`: alignment before modeled `sub_4E4140`.
- `xrefs_to 0x004e3a80`: no IDA xrefs to the orphan entry.
- `0x004e3a80-0x004e410d` length is `0x68d` / 1677 bytes, checked with `tools/int_convert.py`.

Retained-variant route check performed in this rework:

- MCP `lookup_funcs` on 2026-06-26 in live session `80de0a67` reconfirmed `0x004e3a80`, `0x004e410d`, `0x004e4110`, `0x004e4205`, and `0x004e427c` are not function starts; `0x004e4140` remains `sub_4E4140` size `0xc5`, and `0x004e4210` remains `sub_4E4210` size `0x6c`.
- MCP `xrefs_to` / `xref_query` reconfirmed zero xrefs to `0x004e3a80` and zero xrefs to the retained body end/alignment at `0x004e410d`; the only xref to `0x004e4110` is a data xref from `0x004e3d6c`, the switch inside the retained body.
- MCP switch relationship check: `insn_query 0x004e3d40-0x004e3d78` shows `0x004e3d6c` as `jmp ds:jpt_4E3D6C[esi*4]; switch jump`; `insn_query 0x004e4100-0x004e4140` shows `retn 1Ch` at `0x004e410a`, alignment at `0x004e410d`, `dd offset loc_4E3D73` at `0x004e4110`, and alignment at `0x004e413c`.
- MCP bytes for `0x004e4110-0x004e413c` decode to eleven absolute in-range jump-table entries: `0x004e3d73`, `0x004e3db6`, `0x004e3e0d`, `0x004e3e5f`, `0x004e3eb6`, `0x004e402a`, `0x004e402a`, `0x004e3f4c`, `0x004e3f85`, `0x004e3fbb`, and `0x004e3feb`. This table is retained-body internal data, not an external entry route.
- Raw PE scan against `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` (image base `0x00400000`) found zero exact little-endian VA pointers to `0x004e3a80` and zero exact little-endian RVA pointers to `0x000e3a80`.
- The same raw scan found eleven full-range VA dwords into `0x004e3a80-0x004e410d`, all at `.text` addresses `0x004e4110-0x004e4138` and matching the retained body's jump table. It found thirteen full-range RVA dword byte coincidences in `.text`, but none is the exact entry RVA and no relocation/data-reference evidence promotes them to pointers.
- Direct PE code scan of executable sections for `E8`/`E9` rel32 calls/jumps and `0F 8*` rel32 conditional branches found 31 direct branches with targets inside `0x004e3a80-0x004e410d`; every one originates inside the retained body. The scan found zero direct outside-to-retained-range rel32 branches.
- PE relocation directory check found `IMAGE_DIRECTORY_ENTRY_BASERELOC` RVA `0x00000000`, size `0x0`; no relocation table is available, and therefore no relocation-backed pointer to `0x004e3a80` or the retained body exists in this image.

Constant/global evidence:

- `get_bytes 0x0066da9c size 8`: both tile dimensions are `0x30` (`word_66DA9C` and `word_66DAA0`), matching [UID:0000T7] `MapTilePixelDimensions`.
- `get_bytes 0x0061b648 size 32`: the first four 16-bit frame offsets are `{0, 1, 0, 2}`. This table is referenced by composition build, bounds, render, and the orphan gap; source-facing name should be `kNewHumanRidingFrameRectOffsets` or equivalent.
- `xrefs_to 0x0061b648`: refs from `0x004e2bb6`, target `0x004e3366`/`0x004e392d`, gap `0x004e3caa`/`0x004e4006`, and render `0x004e4423`/`0x004e4b2e`.
- `get_bytes 0x006104b4 size 4`: `1.0f` constant used in projected-bound top calculation.

## Avatar State Field Resolution

The exact original struct name is not proven, but the field roles are no longer blockers. Use a source-facing inferred type such as `NewHumanCompositionState`, with offset comments retained until original names are found.

| Offset | Width | Use in target | Recommended source-facing role |
| ---: | ---: | --- | --- |
| `+0x04` | word | Nonzero gate for the whole method; Part.tbl row 0 id for tag `0x32`; decremented by 200 for tag `0x33`. | `baseBodyPartId` / `basePartId` |
| `+0x06` | byte | Part.tbl row 5 id for tag `0x35`, sentinel `0xff`. | `facePartId` or `headDetailPartId` |
| `+0x0a` | word | Classified by `ClassifyHumanPartFiveBucket`; selects Part.tbl rows 8-11, or row 18 for bucket 5 under tag `0x3e`. | `primaryEquipmentId` |
| `+0x0c` | word | Classified by `ClassifyHumanPartTwoBucket`; selects Part.tbl row 12 or row 13. | `secondaryEquipmentId` |
| `+0x0e` | byte | First-pass tag `0x36` Part.tbl row 6 id, sentinel `0xff`. | `accessoryLowPartId` |
| `+0x10` | word | Tag `0x34` Part.tbl row 4 id, gated by `acc2drw` flag 0. | `acc2drwPart0Id` |
| `+0x12` | word | `acc2drw` selector; also second-pass tag `0x36` Part.tbl row 7 id. | `acc2drwSelector` |
| `+0x16` | word | Tag `0x39` Part.tbl row 14 id. | `capeOrBackPartId` |
| `+0x18` | word | Tag `0x3b` Part.tbl row 16 id. | `overlayPartIdB` |
| `+0x1a` | word | Tag `0x3a` Part.tbl row 15 id. | `overlayPartIdA` |
| `+0x1c` | word | Alternate body id for tag `0x32`; chooses Part.tbl row 1 when not `0xffff`. | `alternateBodyPartId` |
| `+0x1e` | word | Special-part path; chooses Part.tbl row 17 when not `0xffff`. | `specialCompositionPartId` |
| `+0x22` | byte | Mode selector: `1` = `GFACE.EPF`, `2` = default tile bounds, `3` = riding/special overlay offset enabled. | `compositionMode` |
| `+0x2c` | word | Riding definition index passed to `RidingImageLib::GetDefinitionOrDefault`. | `ridingDefinitionIndex` |
| `+0x30` | signed word | Y-offset used only when `compositionMode == 3`; passed into `ResolveCompositionPartRect`. | `ridingYOffset` |
| `+0x40` | dword | Copied into local storage but not consumed by this target body. | reserve as copied state tail |

`0x1e == 30`, `0x44 == 68`, `0x3d4 == 980`, and `0x3d8 == 984` were checked with `tools/int_convert.py`.

## Part.tbl Row Offsets And Draw Tags

Part selection uses the `m_partEntries` vector loaded from `Part.tbl`. The target's raw offsets are exact multiples of the 68-byte Part.tbl row size (`0x44 == 68` checked with `tools/int_convert.py`).

| Part.tbl byte offset | Row index | Target use |
| ---: | ---: | --- |
| `+0x000` | 0 | Tag `0x32` base body path when no alternate body id is present. |
| `+0x044` | 1 | Tag `0x32` alternate body path when `state+0x1c != 0xffff`. |
| `+0x088` | 2 | Tag `0x33` non-motion-range adjusted base id path. |
| `+0x0cc` | 3 | Tag `0x33` sequence range `0x26..0x36` adjusted base id path. |
| `+0x110` | 4 | Tag `0x34`, gated by `acc2drw` flag byte 0. |
| `+0x154` | 5 | Tag `0x35`, gated by `acc2drw` flag byte 1. |
| `+0x198` | 6 | Tag `0x36` first pass, gated by `acc2drw` flag byte 2. |
| `+0x1dc` | 7 | Tag `0x36` second pass. |
| `+0x220` | 8 | Tag `0x37`, five-bucket classifier result 1. |
| `+0x264` | 9 | Tag `0x37`, five-bucket classifier result 2, id minus 10000. |
| `+0x2a8` | 10 | Tag `0x37`, five-bucket classifier result 3, id minus 20000. |
| `+0x2ec` | 11 | Tag `0x37`, five-bucket classifier result 4, id minus 30000. |
| `+0x330` | 12 | Tag `0x38`, two-bucket classifier result 1. |
| `+0x374` | 13 | Tag `0x3e`, two-bucket classifier result 2, id minus 10000. |
| `+0x3b8` | 14 | Tag `0x39`. |
| `+0x3fc` | 15 | Tag `0x3a`. |
| `+0x440` | 16 | Tag `0x3b`. |
| `+0x484` | 17 | Special-part path before the normal draw-order loop. |
| `+0x4c8` | 18 | Tag `0x3e`, five-bucket classifier result 5, id minus 40000 via unsigned `+25536`. |

Draw-order tags:

| Tag | Behavior |
| ---: | --- |
| `0x32` | Base/alternate body. Uses row 1 when `state+0x1c` is present, otherwise row 0 with `state+0x04`. Uses normalized sequence for the row 1 path. |
| `0x33` | Adjusted base part. Subtracts 200 from the local base id, then uses row 3 for sequence `0x26..0x36`, otherwise row 2. |
| `0x34` | Row 4, using `state+0x10`; skips entirely if `state+0x12` is present and `acc2drw[3*selector+0] == 0`. |
| `0x35` | Row 5, using byte `state+0x06`; skips entirely if `state+0x12` is present and `acc2drw[3*selector+1] == 0`. |
| `0x36` | Two-pass tag. First pass decrements the loop index and may use row 6 with byte `state+0x0e`; second pass always reaches the union path and may use row 7 with `state+0x12`. |
| `0x37` | Primary equipment bucket. Rows 8-11 for five-bucket results 1-4. Result 5 is handled by tag `0x3e`. |
| `0x38` | Secondary equipment bucket 1, row 12. |
| `0x39` | Row 14, using `state+0x16` and normalized sequence. |
| `0x3a` | Row 15, using `state+0x1a` and normalized sequence. |
| `0x3b` | Row 16, using `state+0x18` and normalized sequence. |
| `0x3c` | Riding/raw overlay rectangle from `RidingImageLib::GetDefinitionOrDefault(state+0x2c)` and `ResourceLayoutRawRecordGetEntryRect`. |
| `0x3d` | Falls through the switch default path and unions the cleared temporary rect. No Part.tbl row is selected. |
| `0x3e` | Secondary equipment bucket 2 row 13, or primary-equipment bucket 5 row 18. |
| `0x3f` | Falls through the switch default path and unions the cleared temporary rect. No Part.tbl row is selected. |

Tags outside `0x32..0x3f` skip the union path for that loop iteration.

## Projection And Globals

The current page's projection-offset note should be corrected. Live decompile/disassembly shows the target uses `dword_67A764 + 0x3d4` and `dword_67A764 + 0x3d8`, not `+0x3d0/+0x3d4`.

Formula:

- `height = bounds[3] - bounds[1]`.
- `horizontal = *(float *)(g_activeMapPane + 0x3d8) * height`.
- `vertical = height / *(float *)(g_activeMapPane + 0x3d4)`.
- Projected right is `max(bounds.right, int(bounds.right + horizontal))`.
- Projected left is `min(bounds.left, int(bounds.left + horizontal))`.
- Projected top is `int(bounds.bottom - vertical - 1.0f)`.
- Projected bottom is `bounds.bottom`.

Dependencies:

- `dword_67A764` is [UID:0001OW] `ActiveMapPaneSingleton`; this target is a consumer, not owner.
- `word_66DA9C` and `word_66DAA0` are [UID:0000T7] map tile pixel dimensions. Their current memory bytes are both `0x30`.
- `dword_67A744` is [UID:0000QU] `g_pEPFLib`/ImageLib dependency used for `GFACE.EPF`; this target is a consumer.
- `unk_69B444` is [UID:0000TQ]/[UID:0001PL] riding-image global dependency; this target is a consumer.

## Orphan Gap Split

The post-target gap should be repaired as separate material, not folded into [UID:0002V8]. The accepted implementation callback should create or repair exactly these by-memory child pages; do not leave the split decision to the supervisor.

Structural split:

| Range | Kind | Action |
| --- | --- | --- |
| `0x004e3a2e-0x004e3a30` | alignment | Leave as boundary/alignment evidence for target. |
| `0x004e3a30-0x004e3a74` | target jump-table data | Document as switch data for [UID:0002V8], not executable code. |
| `0x004e3a74-0x004e3a80` | `0xcc` alignment | Padding before orphan body. |
| `0x004e3a80-0x004e410d` | unmodeled executable body | Create the retained-variant child page listed below. |
| `0x004e4110-0x004e413c` | orphan body jump table | Attach to the new `0x004e3a80` child page as data. |
| `0x004e413c-0x004e4140` | alignment | Padding before `ResolveCompositionPartRect`. |

Required child-page dispositions:

| Range | Exact path | Page title | Metadata/disposition |
| --- | --- | --- | --- |
| `0x004e3a80-0x004e410d` | `by-memory/0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant.md` | `0x004e3a80-0x004e410d NewHumanImageLib CalculateCompositionBounds RetainedVariant` | New UID assigned by validator; `COMPLETION:86`; `CONFIDENCE:88`; `CANONICAL_OWNER:000092`; `RECONSTRUCTABLE:TRUE`; blank `EMITTER_UIDS`; blank formal C++ with the rare no-code proof below; `Nested:0`. |
| `0x004e4140-0x004e4205` | `by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md` | `0x004e4140-0x004e4205 NewHumanImageLib ResolveCompositionPartRect` | New UID assigned by validator; `COMPLETION:88`; `CONFIDENCE:90`; `CANONICAL_OWNER:000092`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:000092`; first-draft formal C++ required; `Nested:0`. |
| `0x004e4210-0x004e427c` | `by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md` | `0x004e4210-0x004e427c NewHumanImageLib ResolveCompositionPartFrame` | New UID assigned by validator; `COMPLETION:87`; `CONFIDENCE:89`; `CANONICAL_OWNER:000092`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:000092`; first-draft formal C++ required; `Nested:0`. |

Retained-variant no-code proof for `0x004e3a80-0x004e410d`:

- Live MCP `lookup_funcs` says `0x004e3a80` and `0x004e410d` are not functions, while `insn_query` shows a full stack-cookie body from `0x004e3a80` through `retn 1Ch` at `0x004e410a`.
- Live MCP `xrefs_to 0x004e3a80` reports zero xrefs. The body is source-shaped and reconstructable, but no modeled code, switch table, vtable slot, or data xref currently proves an executable entry route.
- The body duplicates the [UID:0002V8] bounds algorithm shape using a different entry layout: it handles default bounds, `GFACE.EPF`, special riding overlay, draw-order dispatch, `ResolveCompositionPartRect`, and projected bounds. It should be documented so generated coverage no longer treats the gap as unknown executable material.
- The route pass requested by the supervisor is now complete. MCP xrefs, raw VA/RVA pointer scans, direct rel32 branch scans, switch/jump-table checks, and relocation inspection all failed to find an external route into `0x004e3a80` or any outside branch into `0x004e3a80-0x004e410d`. The only absolute pointers into the retained body are its own jump-table entries at `0x004e4110-0x004e4138`.
- Decision: create the retained-variant page as source-authored/reconstructable evidence under `NewHumanImageLib`, but leave `EMITTER_UIDS` blank and leave the formal C++ block empty under this rare no-code proof. Do not insert formal C++, and do not insert a covered-by comment pointing to [UID:0002V8], because the retained body is separate executable code with distinct prologue, locals, switch table, and no proven emitted-source relationship to the active wrapper-called function.

Exact blank formal block for the retained-variant page:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Required `Item Summary` text for new child pages:

- `0x004e3a80-0x004e410d`: `Unmodeled retained NewHuman composition-bounds variant in the post-0002V8 gap; MCP confirms no function/xrefs, full stack-cookie body ending in retn 1Ch, internal jump table at 0x004e4110, shared GFACE/special/riding/draw-order/projection logic, and raw PE scan finds no external VA/RVA/rel32/reloc route.`
- `0x004e4140-0x004e4205`: `NewHumanImageLib helper resolving a Part.tbl part/frame rectangle; clamps part index, reads per-sequence frame mapping, copies or clears the raw ResourceLayout rectangle, then applies the passed x/y adjustment.`
- `0x004e4210-0x004e427c`: `NewHumanImageLib helper resolving a Part.tbl frame draw record for rendering; clamps part index, loads the draw record through ResourceLayout frame data, then adjusts the embedded bounds rectangle.`

Support helper formal-C++ disposition:

- `0x004e4140-0x004e4205` should receive a first-draft C++ block as `int __stdcall NewHumanImageLib::ResolveCompositionPartRect(NewHumanPartEntry *part, unsigned short partId, int sequence, int frame, int yOffset, int xOffset, RectBounds *outBounds)`. The exact nested descriptor field names are inferred, but the behavior is small and MCP-proven enough for source-shaped code.
- `0x004e4210-0x004e427c` should receive a first-draft C++ block as `int __stdcall NewHumanImageLib::ResolveCompositionPartFrame(NewHumanPartEntry *part, unsigned short partId, int sequence, int frame, int yOffset, int xOffset, NewHumanDrawRecord *outRecord)`. The C++ should call the existing frame draw-record loader abstraction and adjust `outRecord->bounds`.
- These helper pages are in-scope for the accepted callback because they are direct dependencies of the target/source-quality repair. They should not be deferred, and they should not be represented only as prose in [UID:0002V8].

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for `by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int __stdcall NewHumanImageLib::ResolveCompositionPartRect(
    NewHumanPartEntry *part,
    unsigned short partId,
    int sequence,
    int frame,
    int yOffset,
    int xOffset,
    RectBounds *outBounds)
{
    int partCount = part->descriptorCount;
    if (partCount != 0) {
        int selectedPart = 0;
        if (partCount > partId)
            selectedPart = partId;

        NewHumanPartFrameDescriptor *descriptor = &part->frameDescriptors[selectedPart];
        NewHumanSequenceFrameTable *sequenceFrames = descriptor->sequenceFrames[sequence];
        if (sequenceFrames != NULL) {
            int rectIndex = sequenceFrames->frames[frame].recordIndex +
                descriptor->drawIndexBase;

            if (rectIndex >= part->rawRecords->recordCount)
                RectBoundsSet(outBounds, 0, 0, 0, 0);
            else
                *outBounds = part->rawRecords->records[rectIndex].rect;

            return RectBoundsAdjust(outBounds, xOffset, yOffset);
        }
    }

    return partCount;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for `by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int __stdcall NewHumanImageLib::ResolveCompositionPartFrame(
    NewHumanPartEntry *part,
    unsigned short partId,
    int sequence,
    int frame,
    int yOffset,
    int xOffset,
    NewHumanDrawRecord *outRecord)
{
    int selectedPart = 0;
    if (part->descriptorCount > partId)
        selectedPart = partId;

    NewHumanPartFrameDescriptor *descriptor = &part->frameDescriptors[selectedPart];
    NewHumanSequenceFrameTable *sequenceFrames = descriptor->sequenceFrames[sequence];
    if (sequenceFrames != NULL) {
        LoadFrameDrawRecord(
            part->rawRecords,
            sequenceFrames->frames[frame].recordIndex + descriptor->drawIndexBase,
            outRecord);
        return RectBoundsAdjust(&outRecord->bounds, xOffset, yOffset);
    }

    return 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Source Placement

Target [UID:0002V8] should be source-placed as a `NewHumanImageLib` private/member helper in `NexusTK/render/NewHumanImageLib.cpp`.

Recommended downstream updates on implementation callback:

- Target page: owner/emitter [UID:000092], file cross-reference [UID:0000LR].
- [UID:000092] `NewHumanImageLib`: add `CalculateCompositionBounds`, `ResolveCompositionPartRect`, classifier helper usage, and gap/retained variant notes.
- [UID:0000LR] `NewHumanImageLib`: preserve file route and add the target's resolved tag/Part.tbl map.
- [UID:00017R] local cluster: replace the broad "gap contains orphan code" note with the exact split above.
- [UID:0001VF] layout: no major field-layout change required, but link this target's Part.tbl row-index use as consumer evidence.

## Rejected Alternatives

- Extend [UID:0002V8] to `0x004e4140`: rejected. MCP proves `sub_4E31F0` ends at exclusive `0x004e3a2e`; the next modeled function starts at `0x004e4140`; the material between includes target jump tables, alignment, and a separate orphan body.
- Treat `0x004e3a80-0x004e410d` as padding or generated junk: rejected. MCP disassembly shows a full stack-cookie function body with NewHuman-specific calls and `retn 1Ch`.
- Assign `0x004d05a0` to NewHuman: rejected. It is already [UID:0002KT] `ResourceLayoutRawRecordGetEntryRect`, with ResourceLayout and multiple non-target raw callers.
- Leave `0x004e4140`, `0x004dca20`, `0x004e05d0`, and `0x004e0630` as unresolved raw helpers: rejected. Live decompilation resolves their behavior enough for stable source-facing names.
- Claim original spelling for avatar-state fields: rejected. The offsets and behavior are resolved; exact original field names are not. Use descriptive inferred names with offset evidence.
- Keep the old projection note `+0x3d0/+0x3d4`: rejected. Current MCP decompile/disassembly uses `+0x3d8` and `+0x3d4`.

## First-Draft C++ Readiness

The target now clears the reconstruction-code gate: reconstructable, valid class/file emitter route, average recommended score above 85, and enough helper/field resolution for source-shaped code. The formal target C++ should use inferred names and offset-backed state fields; do not use `sub_` names, decompiler temporaries, or raw labels.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0002V8] `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int NewHumanImageLib::CalculateCompositionBounds(
    const int *drawOrder,
    const NewHumanCompositionState &inputState,
    int sequence,
    int frame,
    RectBounds *bounds,
    RectBounds *projectedBounds,
    char direction)
{
    NewHumanCompositionState state = inputState;
    RectBounds partBounds;
    const RidingDefinition *ridingDefinition;
    int ridingYOffset;
    int normalizedSequence;
    int drawIndex;
    int tag;
    int bucket;
    int height;
    int projectedLeft;
    int projectedRight;
    float horizontalOffset;
    float verticalOffset;
    bool secondAccessoryPass;
    bool mergePart;
    int result = 0;

    ridingYOffset = 0;
    if (state.compositionMode == 3)
        ridingYOffset = state.ridingYOffset;

    if (state.baseBodyPartId == 0)
        return result;

    RectBoundsClear(bounds, 0, 0, 0, 0);

    if (state.compositionMode == 2) {
        result = RectBoundsSet(bounds, 0, 0, g_mapTilePixelHeight, g_mapTilePixelWidth);
        goto FinishBounds;
    }

    if (state.specialCompositionPartId != 0xffff) {
        ResolveCompositionPartRect(
            &m_partEntries[17],
            state.specialCompositionPartId,
            sequence,
            frame,
            ridingYOffset,
            0,
            &partBounds);
        RectBoundsUnion(bounds, &partBounds);

        if (state.compositionMode == 3) {
            ridingDefinition =
                g_pRidingImageLib->GetDefinitionOrDefault(state.ridingDefinitionIndex);
            ResourceLayoutRawRecordGetEntryRect(
                g_pRidingImageLib->m_rawRecordTable,
                ridingDefinition->baseRectIndex + 3 * sequence +
                    kNewHumanRidingFrameRectOffsets[frame] - 24,
                &partBounds);
        }

        RectBoundsUnion(bounds, &partBounds);
        result = RectBoundsOffset(bounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
        goto FinishBounds;
    }

    if (state.compositionMode == 1) {
        int gfaceIndex = g_pEPFLib->FindResourceIndex(L"GFACE.EPF");
        if (gfaceIndex == -1)
            gfaceIndex = g_pEPFLib->LoadResourceIndex(L"GFACE.EPF");

        const ResourceLayoutRecord *gface = g_pEPFLib->GetResourceLayout(gfaceIndex);
        if (gface->entryCount != 0 && gface->entries != NULL)
            *bounds = gface->entries[0].rect;
        else
            RectBoundsSet(bounds, 0, 0, 0, 0);

        result = RectBoundsOffset(bounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
        goto FinishBounds;
    }

    normalizedSequence = sequence;
    if (sequence >= 38 && sequence <= 50 && sequence != 47 && sequence != 49)
        normalizedSequence = direction + 55;

    secondAccessoryPass = false;
    for (drawIndex = 0; drawIndex < 30; ++drawIndex) {
        tag = drawOrder[drawIndex];
        mergePart = false;
        RectBoundsClear(&partBounds, 0, 0, 0, 0);

        switch (tag) {
        case 0x32:
            if (state.alternateBodyPartId == 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[0], state.baseBodyPartId, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            else
                ResolveCompositionPartRect(
                    &m_partEntries[1], state.alternateBodyPartId, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x33:
            state.baseBodyPartId = (unsigned short)(state.baseBodyPartId - 200);
            if (sequence >= 38 && sequence <= 54)
                ResolveCompositionPartRect(
                    &m_partEntries[3], state.baseBodyPartId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            else
                ResolveCompositionPartRect(
                    &m_partEntries[2], state.baseBodyPartId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x34:
            if (state.acc2drwSelector != 0xffff &&
                !m_acc2drwEntries[state.acc2drwSelector].enabled[0])
                break;
            if (state.acc2drwPart0Id != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[4], state.acc2drwPart0Id, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x35:
            if (state.acc2drwSelector != 0xffff &&
                !m_acc2drwEntries[state.acc2drwSelector].enabled[1])
                break;
            if (state.facePartId != 0xff)
                ResolveCompositionPartRect(
                    &m_partEntries[5], state.facePartId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x36:
            if (secondAccessoryPass) {
                if (state.acc2drwSelector != 0xffff)
                    ResolveCompositionPartRect(
                        &m_partEntries[7], state.acc2drwSelector, sequence,
                        frame, ridingYOffset, 0, &partBounds);
                mergePart = true;
            } else {
                --drawIndex;
                secondAccessoryPass = true;
                if (state.acc2drwSelector == 0xffff ||
                    m_acc2drwEntries[state.acc2drwSelector].enabled[2]) {
                    if (state.accessoryLowPartId != 0xff)
                        ResolveCompositionPartRect(
                            &m_partEntries[6], state.accessoryLowPartId, sequence,
                            frame, ridingYOffset, 0, &partBounds);
                    mergePart = true;
                }
            }
            break;

        case 0x37:
            bucket = ClassifyHumanPartFiveBucket(state.primaryEquipmentId);
            switch (bucket) {
            case 1:
                ResolveCompositionPartRect(
                    &m_partEntries[8], state.primaryEquipmentId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            case 2:
                ResolveCompositionPartRect(
                    &m_partEntries[9], state.primaryEquipmentId - 10000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            case 3:
                ResolveCompositionPartRect(
                    &m_partEntries[10], state.primaryEquipmentId - 20000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            case 4:
                ResolveCompositionPartRect(
                    &m_partEntries[11], state.primaryEquipmentId - 30000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
                break;
            default:
                break;
            }
            mergePart = true;
            break;

        case 0x38:
            if (ClassifyHumanPartTwoBucket(state.secondaryEquipmentId) == 1)
                ResolveCompositionPartRect(
                    &m_partEntries[12], state.secondaryEquipmentId, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x39:
            if (state.capeOrBackPartId != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[14], state.capeOrBackPartId, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x3a:
            if (state.overlayPartIdA != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[15], state.overlayPartIdA, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x3b:
            if (state.overlayPartIdB != 0xffff)
                ResolveCompositionPartRect(
                    &m_partEntries[16], state.overlayPartIdB, normalizedSequence,
                    frame, ridingYOffset, 0, &partBounds);
            mergePart = true;
            break;

        case 0x3c: {
            ridingDefinition =
                g_pRidingImageLib->GetDefinitionOrDefault(state.ridingDefinitionIndex);
            ResourceLayoutRawRecordGetEntryRect(
                g_pRidingImageLib->m_rawRecordTable,
                ridingDefinition->baseRectIndex + 3 * sequence - 24 +
                    kNewHumanRidingFrameRectOffsets[frame],
                &partBounds);
            mergePart = true;
            break;
        }

        case 0x3e:
            if (ClassifyHumanPartTwoBucket(state.secondaryEquipmentId) == 2) {
                ResolveCompositionPartRect(
                    &m_partEntries[13], state.secondaryEquipmentId - 10000, sequence,
                    frame, ridingYOffset, 0, &partBounds);
            } else if (ClassifyHumanPartFiveBucket(state.primaryEquipmentId) == 5) {
                ResolveCompositionPartRect(
                    &m_partEntries[18],
                    (unsigned short)(state.primaryEquipmentId + 25536),
                    sequence,
                    frame,
                    ridingYOffset,
                    0,
                    &partBounds);
            }
            mergePart = true;
            break;

        case 0x3d:
        case 0x3f:
            mergePart = true;
            break;

        default:
            break;
        }

        if (mergePart)
            RectBoundsUnion(bounds, &partBounds);
    }

    result = RectBoundsOffset(bounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);

FinishBounds:
    if (projectedBounds != NULL) {
        height = bounds->bottom - bounds->top;
        horizontalOffset = g_activeMapPane->m_newHumanProjectionShear * (float)height;
        verticalOffset = (float)height / g_activeMapPane->m_newHumanProjectionDivisor;

        projectedRight = bounds->right;
        if (projectedRight <= (int)((float)projectedRight + horizontalOffset))
            projectedRight = (int)((float)bounds->right + horizontalOffset);

        projectedLeft = (int)((float)bounds->left + horizontalOffset);
        if (bounds->left <= projectedLeft)
            projectedLeft = bounds->left;

        return RectBoundsSet(
            projectedBounds,
            projectedLeft,
            (int)((float)bounds->bottom - verticalOffset - 1.0f),
            projectedRight,
            bounds->bottom);
    }

    return result;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Notes for implementation:

- The code uses `g_activeMapPane->m_newHumanProjectionDivisor` for `+0x3d4` and `m_newHumanProjectionShear` for `+0x3d8`; exact final field names remain inferred and should be documented as such.
- The `m_acc2drwEntries[...] .enabled` expression stands for the raw byte flags loaded from `acc2drw.tbl`; if the current reconstructed type is `unsigned char *`, implement as raw byte indexing.
- `ResourceLayoutRecord`, `RidingDefinition`, and `NewHumanCompositionState` names are source-facing inferred names. If support pages choose different names, keep this method's control flow and offset evidence intact.

## Implementation Checklist

Do this only after supervisor validation and implementation callback.

- [x] Lease these existing by-* files before editing: `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md`, `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`, `by-class/NewHumanImageLib.md`, `by-file/NewHumanImageLib.md`, and `by-type/by-struct/NewHumanImageLibLayout.md`. Release leases immediately after edits and scoped validators finish.
  - Proof: B014 acquired the edit batch leases and reacquired them after the initial validator wrapper timed out/leases expired; no other active lease blocked the edit batch. Release proof: `python .\leaser.py B014 unlease` from `tools/leaser` returned `B014: No active leases` after validation, and `tools/leaser/Agents/Agent-B014/current_leases.md` had no B014 rows.
- [x] Update [UID:0002V8] `by-memory/0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md`: set `COMPLETION:89`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, keep `Nested:0`, replace the `Item Summary` with the recommended text in this report, replace stale projection text with `+0x3d4/+0x3d8`, add the avatar-state field table, add the exact Part.tbl row/draw-tag table, preserve ResourceLayout/Riding/GFACE/global evidence, add the exact orphan-gap split table, and insert the target formal C++ block from this report.
  - Proof: header metadata now matches `89/90`, owner/emitter [UID:000092], and reconstructable TRUE; body sections now include `Avatar State Field Resolution`, Part.tbl row offsets/tags, `Projection And Globals` with [UID:0001OW] `+0x3d4/+0x3d8`, `Orphan Gap Split`, updated support/crossrefs, and the formal `NewHumanImageLib::CalculateCompositionBounds` C++ block.
- [x] Create `by-memory/0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant.md` with validator-assigned UID, `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++, `Nested:0`, the exact `Item Summary` from this report, the no-code proof from this report, and the split statement that `0x004e4110-0x004e413c` is its jump table while `0x004e413c-0x004e4140` is alignment.
  - Proof: validator assigned [UID:000436]; header has `86/88`, owner [UID:000092], reconstructable TRUE, blank emitter/formal C++; body records zero external xrefs/routes, retained stack-cookie variant proof, `0x004e4110-0x004e413c` jump table, and `0x004e413c-0x004e4140` alignment.
- [x] Create `by-memory/0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md` with validator-assigned UID, `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, `Nested:0`, the exact `Item Summary` from this report, helper evidence from live MCP, and the formal C++ block for `ResolveCompositionPartRect` from this report.
  - Proof: validator assigned [UID:000437]; header has `88/90`, owner/emitter [UID:000092], reconstructable TRUE; body includes the exact helper summary/evidence and the formal `NewHumanImageLib::ResolveCompositionPartRect` C++ block.
- [x] Create `by-memory/0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md` with validator-assigned UID, `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:000092`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000092`, `Nested:0`, the exact `Item Summary` from this report, helper evidence from live MCP, and the formal C++ block for `ResolveCompositionPartFrame` from this report.
  - Proof: validator assigned [UID:000438]; header has `87/89`, owner/emitter [UID:000092], reconstructable TRUE; body includes the exact helper summary/evidence and the formal `NewHumanImageLib::ResolveCompositionPartFrame` C++ block.
- [x] Update [UID:00017R] `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`: add child rows for the three exact new pages, replace the broad `0x004e3a2e-0x004e4140` orphan-gap note with the exact split table from this report, and keep `0x004e3a30-0x004e3a74` identified as [UID:0002V8] switch-table data.
  - Proof: `Active Function And Helper Ranges` now lists [UID:000436], [UID:000437], and [UID:000438]; `2026-06-26 Composition Bounds Split` records the exact gap/switch-table/retained-variant/jump-table/alignment split and keeps `0x004e3a30-0x004e3a74` assigned to [UID:0002V8].
- [x] Update [UID:000092] `by-class/NewHumanImageLib.md`: record `CalculateCompositionBounds` as a class-owned member with the resolved helper names, add the direct class emitter route for [UID:0002V8] and the two helper child pages, record the retained-variant child page as class-owned but intentionally non-emitting with the rare no-code proof, and add the Part.tbl row-index/draw-tag map as consumer evidence for the layout.
  - Proof: method family inventory now lists [UID:0002V8], [UID:000436], [UID:000437], and [UID:000438]; `2026-06-26 Composition Bounds Source-Quality Sync` records the class-owned emitter route, the retained non-emitting proof, helper child names, and Part.tbl row-index/draw-tag layout evidence.
- [x] Update [UID:0000LR] `by-file/NewHumanImageLib.md`: add [UID:0002V8] and the three new child ranges to the NewHuman composition/bounds/render helper inventory, preserve the source route `NexusTK/render/NewHumanImageLib.cpp`, and state that ResourceLayout/Riding/ImageLib globals are dependencies rather than ownership changes.
  - Proof: the `NewHumanImageLib.cpp` file inventory now names [UID:0002V8], [UID:000436], [UID:000437], and [UID:000438], keeps the source route as `NexusTK/render/NewHumanImageLib.cpp`, and records ResourceLayout/Riding/ImageLib globals as dependencies instead of ownership changes.
- [x] Update [UID:0001VF] `by-type/by-struct/NewHumanImageLibLayout.md`: add this target's exact Part.tbl row-index consumer evidence, confirm `Acc2DrwEntry` is a 3-byte row consumed as `enabled[3]`, and add the inferred names `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, and `NewHumanCompositionState` as implementation-ready support names with original-spelling caveats.
  - Proof: `2026-06-26 Composition Bounds Consumer Evidence` records Part.tbl row-index consumer evidence, confirms `Acc2DrwEntry` as 3 byte flags consumed as `enabled[3]`, and adds `NewHumanPartFrameDescriptor`, `NewHumanSequenceFrameTable`, `NewHumanDrawRecord`, and `NewHumanCompositionState` with original-spelling caveats.
- [x] Run validators from `E:\NTK\GhidraBridge\source-3\project-documentation` and record command id, timestamp, exit code, and `ok` count for each command:
  - `python .\tools\validator.py --mode file --file by-memory\0x004e31f0-0x004e3a2e.NewHumanImageLibCalculateCompositionBounds.md --apply --queue-timeout 240` -> command_id `000000002317`, timestamp `2026-06-26T04:19:05-04:00`, exit 0, ok 1, generated_refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory\0x004e3a80-0x004e410d.NewHumanImageLibCalculateCompositionBoundsRetainedVariant.md --apply --queue-timeout 240` -> command_id `000000002318`, timestamp `2026-06-26T04:19:12-04:00`, exit 0, ok 1, generated_refresh deferred, assigned [UID:000436].
  - `python .\tools\validator.py --mode file --file by-memory\0x004e4140-0x004e4205.NewHumanImageLibResolveCompositionPartRect.md --apply --queue-timeout 240` -> command_id `000000002319`, timestamp `2026-06-26T04:19:23-04:00`, exit 0, ok 4, generated_refresh deferred, assigned [UID:000437].
  - `python .\tools\validator.py --mode file --file by-memory\0x004e4210-0x004e427c.NewHumanImageLibResolveCompositionPartFrame.md --apply --queue-timeout 240` -> command_id `000000002320`, timestamp `2026-06-26T04:19:35-04:00`, exit 0, ok 4, generated_refresh deferred, assigned [UID:000438].
  - `python .\tools\validator.py --mode file --file by-memory\0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240` -> command_id `000000002321`, timestamp `2026-06-26T04:19:46-04:00`, exit 0, ok 1, generated_refresh deferred; existing unrelated diagnostics reported `missing_ref_uid 0003UD`.
  - `python .\tools\validator.py --mode file --file by-class\NewHumanImageLib.md --apply --queue-timeout 240` -> command_id `000000002323`, timestamp `2026-06-26T04:20:00-04:00`, exit 0, ok 1, generated_refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file\NewHumanImageLib.md --apply --queue-timeout 240` -> command_id `000000002324`, timestamp `2026-06-26T04:20:07-04:00`, exit 0, ok 1, generated_refresh deferred.
  - `python .\tools\validator.py --mode file --file by-type\by-struct\NewHumanImageLibLayout.md --apply --queue-timeout 240` -> command_id `000000002326`, timestamp `2026-06-26T04:20:18-04:00`, exit 0, ok 5, generated_refresh deferred.
  - Follow-up checks: `rg -n "TMP:"` over all changed by-* files returned no matches; `python .\tools\validator.py --queue-status` command_id `000000002342`, timestamp `2026-06-26T04:22:35-04:00`, showed generated refresh queue drained (`queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`) while the validator worker remained running.
- [x] Do not manually edit `auto-generated/*`, `project-level/*`, `by-memory/-coverage-report.md`, any other `-coverage-report.md`, validator state/cache, lease state, or tool-state files. Generated tracker/coverage refresh is validator-owned after the scoped file validators and later report execution.
  - Proof: manual edits were limited to the accepted by-* docs and this Agent-B014 research report checklist. Generated/project-level/coverage/validator-state/tool-state files were not manually edited; any generated/projected refresh was validator-owned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002V8-NewHumanImageLibCalculateCompositionBounds-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0002V8-NewHumanImageLibCalculateCompositionBounds-source-quality.md","timestamp":"2026-06-26T04:26:14","uid":"0002V8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
