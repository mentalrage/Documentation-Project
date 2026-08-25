** TARGET-REPORT-UID:0002CF **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002CF g_movementSubstepScale Ownership Research

Revision: B001-001R / B001-004 audit / supervisor override active recheck / inference guidance review / finalized-top-format / low-confidence owner follow-up / continued ownership investigation, 2026-06-08

## Finalized Report / Current Recommendation

- Target UID/path: [UID:0002CF] `by-global/g_movementSubstepScale.md`; exact storage [UID:00027F] `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md`
- Best current ownership/source-file path: assign [UID:0002CF] to the existing `NexusTK/map/MapPane.cpp` source owner, specifically the MapPane coordinate/movement helper surface, after [UID:0000L3] `MapPane` is score/gate-repaired or after a MapPane-owned coordinate-helper subdocument is created. The prior standalone `MapMovementGlobals.cpp` hypothesis is rejected as the best path; IDA ties the byte to MapPane direction/coordinate helpers more strongly than to an independent config/global file.
- Recommended status/classification: source-authored map coordinate/movement scalar, reconstructable, current autogen-unassigned only because the current [UID:0000L3] `MapPane` file page is scored `88/80` and therefore fails the mechanical `85/85` parent gate even though the direct ownership inference is now strong.
- Confidence: `88/100` for MapPane coordinate/movement helper ownership; `93/100` for storage/value/boundary; `92/100` for behavior. This crosses the ownership inference threshold because IDA shows all 23 direct reads are movement/placement reads, every direct operand hit is a read rather than a write, all 14 scale-reader functions are MapPane coordinate helpers or callers/consumers of the MapPane direction-coordinate API, the only meaningful adjacent-global overlap is with MapPane tile dimensions, and the proposed source tree explicitly places coordinate conversion and MapTilePixelDimensions under `map/MapPane.cpp` without a separate map-movement globals file.
- Low-confidence facts resolved as far as current binary evidence allows: IDA does not preserve the literal original source spelling, so use `g_movementSubstepScale` as the recommended descriptive reconstruction name while retaining `byte_66DA96` as the IDA alias. The best declaration-file inference is `MapPane.cpp`; a private MapPane coordinate-helper translation unit or header/source companion remains possible but weaker because the current source tree has no such companion and the function cluster already sits inside MapPane coordinate ranges. [UID:0000L3] `MapPane` should be improved/raised and used as the parent; split a smaller MapPane coordinate-helper parent only if the supervisor wants a narrower documentation gate before attachment.
- Existing-owner gate answer: [UID:0000L3] `MapPane` is the best direct owner by evidence but is mechanically below gate at `88/80`. [UID:0000P1] `UserPane` (`89/85`) and [UID:0000HJ] `AttachedObjectPane` (`85/85`) meet numeric gate but are weaker because IDA shows them as partial consumers only. [UID:0000KU] `LivingObjectPane` (`88/80`) and [UID:0000JP] `GameServerConfig` (`86/80`) remain weaker and also fail confidence gate.
- Proposed owner contents/scope if a repair split is needed: do not create standalone `MapMovementGlobals.cpp`. Prefer a MapPane-owned coordinate/movement helper grouping containing [UID:0002CF]/[UID:00027F], [UID:0000T7] `MapTilePixelDimensions` with storage [UID:0001OJ]/[UID:0001OK], [UID:0000VC]/[UID:0001AQ] `ScaleDirectionOffsetToPixels_00505100`, unsplit helper `0x00505080` direction-to-offset, unsplit helper `0x00505130` viewport/tile-to-pixel conversion, and likely [UID:00027O] `MapObjectDirectionMasks`. Exclude screen dimensions, EPF mode, FPS flag, folder buffer, and [UID:00027I] coordinate/item clamp constants from this movement helper grouping unless separately proven.
- Concrete next action: A-agent/supervisor should repair [UID:0000L3] `MapPane` confidence to at least `85` using the IDA evidence in this report, then attach [UID:0002CF] and [UID:00027F] there. If the supervisor prefers a smaller parent before raising broad MapPane, create a MapPane-owned coordinate/movement helper subdocument rooted in `MapPane.cpp`, not a new independent source file.
- Report state: final for the revised B001 ownership recommendation; follow-up required by A-agent/supervisor to repair/apply the MapPane owner. Not blocked by lack of perfect source proof.

## Supporting Research

## Continued Investigation Result, 2026-06-08

The previous report left the proposed `MapMovementGlobals.cpp` owner below the action threshold. Continued IDA MCP work does not support keeping a standalone new source file as the primary recommendation. The stronger source-owner path is the existing `MapPane` coordinate/movement helper surface, with either direct attachment to [UID:0000L3] after score repair or a MapPane-owned coordinate-helper subdocument if the supervisor wants a narrower parent.

New IDA MCP evidence collected in this pass:

- `find_insn_operands` for operand value `0x0066da96` found exactly 23 instruction hits: `0x00468577`, `0x00468644`, `0x005055f7`, `0x00506a1e`, `0x0050b0f5`, `0x0050b11c`, `0x0053864f`, `0x00538744`, `0x0053875d`, `0x00539b6f`, `0x0053c773`, `0x0053c78f`, `0x0053c895`, `0x005a3725`, `0x005a3836`, `0x005a840e`, `0x005a846b`, `0x005a84cc`, `0x005a85fe`, `0x005a865b`, `0x005a86bc`, `0x005a8923`, and `0x005ab554`.
- Targeted byte-pattern searches for direct store encodings and raw little-endian address bytes found no additional target references and no direct write encodings: `96 DA 66 00`, `C6 05 96 DA 66 00 ??`, `A2 96 DA 66 00`, `88 0D 96 DA 66 00`, `88 15 96 DA 66 00`, and `C7 05 96 DA 66 00 ?? ?? ?? ??` all returned zero matches.
- Nearby-global xref matrix shows `byte_66DA96` has zero function overlap with the folder buffer at `0x0066da88`, screen width at `0x0066da94`, EPF mode at `0x0066da97`, and screen height at `0x0066da98`. Its only meaningful adjacent-global overlap is with tile width/height: scale and tile dimensions overlap in five functions, `0x00468520`, `0x005055e0`, `0x00506980`, `0x0050b080`, and `0x005a88d0`.
- IDA decompilation ties the scale to the MapPane coordinate helper API:
  - `0x005055e0` calls `0x00505080` and computes `v4 = 4 * byte_66DA96`, then divides tile-scaled offsets by `v4`.
  - `0x00506980` calls `0x00505080`, uses `word_66DA9C`/`word_66DAA0`, and applies `4 * byte_66DA96` while converting object movement offsets.
  - `0x0050b080` calls `0x00505080`, uses tile dimensions, and divides by `4 * byte_66DA96` in object screen-position logic.
  - `0x005a36f0` and `0x005a3770` are LivingObjectPane timer paths, but both call `0x00506980` after scheduling movement, so their scale use feeds back into MapPane object placement.
  - `0x005a83b0` uses `4 * byte_66DA96` as the movement subframe modulus and calls MapPane helpers `0x005055e0` and `0x005058b0`.
  - `0x005a88d0` calls `0x00505080`, `0x00505100`, and `0x00505130` and uses scale plus tile dimensions to compute local-player screen/hit bounds.
  - `0x005ab410` calls `0x00506980`, `0x005059d0`, and `0x00505080` in movement-correction paths.
- IDA `callees` confirms the helper coupling across the scale-reader set: direct readers call `0x00505080` in all major coordinate/placement families, call `0x00505100` in attached/anchor/screen-position scaling paths, call `0x00505130` in MapPane-relative coordinate conversions, or call higher-level MapPane placement helpers such as `0x00506980`, `0x005055e0`, `0x005058b0`, and `0x005059d0`.

Documentation evidence, treated as hypothesis and checked against IDA:

- [UID:0000VC] `ScaleDirectionOffsetToPixels_00505100` and [UID:0001AQ] `0x00505100-0x00505123.ScaleDirectionOffsetToPixels` document `0x00505100` as a small MapPane coordinate helper that reads `word_66DA9C` and `word_66DAA0`. IDA confirms the helper behavior and the seven direct callers.
- [UID:0001AP] `0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore` documents `0x00505080-0x0050571e` as coordinate/visible-bounds helpers inside MapPane and includes `0x00505080`, `0x00505100`, `0x00505130`, and `0x005055e0`. IDA confirms these function boundaries and calls.
- [UID:0002QL] `0x005058b0-0x0050593e.MapPaneScrollViewportByDirection` documents a MapPane method that remaps direction, calls `0x00505080`, uses tile dimensions, and is called by `UserPane::OnAnimationStep`. IDA confirms this is the same movement-coordinate surface touched by `byte_66DA96`.
- [UID:00027O] `0x0066dd50-0x0066dd60.MapObjectDirectionMasks` documents MapPane movement-direction masks consumed by `0x00505430` and related MapPane movement/occupancy helpers. IDA confirms this is nearby-in-concept movement-direction data, but not adjacent to `byte_66DA96`; include as a possible broader MapPane coordinate/movement constants sibling, not as proof by adjacency.

Revised ownership inference:

- `MapMovementGlobals.cpp` as a standalone new file falls away because no IDA writer, initializer, source metadata, or isolated global cluster supports an independent file. The byte is not merely a global; it is a parameter used by MapPane direction-to-pixel coordinate conversion and by MapPane-facing consumers.
- [UID:0000L3] `MapPane` becomes the best direct source-file owner despite its current `88/80` score. The evidence is stronger than the score suggests: the byte is consumed through MapPane coordinate helpers, tile dimensions, direction offset conversion, viewport conversion, object placement, and map scroll/recenter paths.
- A new top-level file would duplicate MapPane's existing coordinate-helper ownership. If a narrower owner is desired, it should be a MapPane-owned helper grouping, not a separate source file: `MapPaneCoordinateMovementHelpers` or `MapPaneMovementConstants`, with `NexusTK/map/MapPane.cpp` as the source module.

## Superseded Low-Confidence Hypothesis

The earlier `MapMovementGlobals.cpp`/`MapMovementConfig.cpp` recommendation is superseded by the continued investigation above. It was a reasonable interim hypothesis when only direct consumer distribution was considered, but additional IDA MCP decompilation and callee analysis tied the byte to the existing MapPane coordinate/movement helper surface strongly enough to make MapPane the current best ownership path.

The evidence that still matters from that interim pass is retained in the IDA facts below: exact storage, no direct writes, mixed adjacent data, tile-dimension overlap, and zero overlap with coordinate/item clamp constants. The ownership conclusion changed.

## Target

- Target UID: `0002CF`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-global\g_movementSubstepScale.md`
- Exact storage child: [UID:00027F] `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0066da96-0x0066da97.g_movementSubstepScale.md`
- Assigned source row: Batch 110 checkpoint, `86/88 -> 87/89`
- Current supervisor status: `reviewed-85-but-ownership-unknown-under-review`
- Source row context: left unassigned because evidence supported the semantic global and memory anchor, but no direct source-file owner was proven and generated coverage does not support by-global memory parenting.

## Revised Executive Recommendation

Best current inference: assign [UID:0002CF] `g_movementSubstepScale` to `NexusTK/map/MapPane.cpp`, specifically its coordinate/movement helper surface. If the project does not want to attach this directly to the broad [UID:0000L3] `MapPane` page until that page's score is repaired, create a MapPane-owned coordinate/movement helper parent first; do not create an independent `MapMovementGlobals.cpp` file.

If forced to choose today, I would choose [UID:0000L3] `MapPane` with `88/100` direct ownership inference confidence. The current `88/80` file-page score is a documentation/gate problem to repair, not evidence that another owner is stronger.

Do not assign this global to `UserPane`, `LivingObjectPane`, `AttachedObjectPane`, `AttachmentAnchorResolver`, `Application`, `FpsPane`, a standalone `MapMovementGlobals.cpp`, or neighboring display/EPF globals. They are either consumers, adjacent but semantically different globals, or hypotheses contradicted by the MapPane direction/coordinate helper evidence.

Operational recommendation: keep [UID:0002CF] and [UID:00027F] autogen-unassigned only as a temporary mechanical state until [UID:0000L3] `MapPane` is gate-repaired or a MapPane-owned coordinate/movement helper parent exists. This is not a recommendation to stop at "ownership unknown"; the actionable owner inference is MapPane coordinate/movement support.

## B001 Supervisor Override Active Recheck

Fresh read-only IDA MCP `py_eval` on 2026-06-08 reconfirmed the core ownership facts: `byte_66DA96` is a one-byte `.data` item with initial value `1`, exactly 23 direct xrefs across 14 functions, and every direct xref is a `movsx` read. The recheck found `0` non-`movsx` direct references and no store/initializer write. Nearby data remains mixed: `0x0066da90` has 4 xrefs/1 function, `0x0066da94` has 98 xrefs/49 functions, `0x0066da97` has 366 xrefs/249 functions, `0x0066da98` has 96 xrefs/48 functions, `0x0066da9c` has 89 xrefs/51 functions, and `0x0066daa0` has 94 xrefs/52 functions.

This override pass now strengthens the conclusion that the supervisor should route [UID:0002CF] through MapPane coordinate/movement support. The current blank parent is only a tooling/documentation staging state because the best inferred owner currently fails the mechanical parent confidence gate. It is not a recommendation to wait for impossible original declaration proof.

## Inference Research Guidance Check

Applied `Agent-B001\inference_research.md` on 2026-06-08. A read-only IDA MCP string/segment breadcrumb scan found no `.pdb`, `RSDS`, `NB10`, `.cpp`, or `.cxx` strings and no debug/PDB segment. It found `NexusTK` runtime/resource path strings and one CRT header string, but no project compilation-unit metadata. Therefore this report cannot claim confirmed original source-file ownership from debug symbols, PDB, linker map, or source paths.

Evidence ladder classification:

- Confirmed binary facts: `0x0066da96` is initialized writable `.data`, one byte, value `1`, with 23 direct read xrefs and no direct writes found; the instruction semantics use it as a movement/timing scale.
- Strongly inferred behavior: the global is a process-wide movement substep scale shared by map coordinate, attached-object, living-object, and user movement code.
- Strong source-owner inference: `NexusTK/map/MapPane.cpp` coordinate/movement helper support is the best current source grouping because IDA ties the byte to MapPane direction-to-offset, tile-to-pixel, viewport, object-placement, scroll, and recenter helpers. A standalone `MapMovementGlobals.cpp` is lower ranked because no writer, initializer, source metadata, or isolated global cluster supports it.
- Weak evidence deliberately limited: address adjacency to nearby `.data` globals is not treated as ownership proof; neighboring xref populations differ sharply and include unrelated display, EPF, FPS, and folder-selection state.

Counter-evidence checked: no write/initializer xref was found; no non-MapPane source file owns the coordinate helper surface; adjacent globals do not share a coherent xref cluster except tile dimensions; no debug/source metadata proves a different file. Next verification that would materially change confidence: a matching PDB/linker map, a discovered config/startup writer, or an IDA-backed MapPane split proving these helpers were compiled in a separate MapPane companion file rather than `MapPane.cpp`.

## Evidence Standards Used

- IDA MCP evidence is treated as ground truth for addresses, byte values, function boundaries, xrefs, instruction behavior, and negative write evidence.
- Existing documentation is treated as useful lead evidence only. For each important ownership conclusion below, I state whether IDA MCP confirms it, contradicts it, or leaves it uncertain.
- Consumer/read xrefs are not declaration proof, but their distribution is meaningful ownership evidence when no write or initializer is present.
- No by-* documentation, generated reports, project-level files, `Supervisor_notes.md`, or tool internals were edited for this revision.

## IDA MCP Facts

Live IDA MCP `py_eval` evidence from 2026-06-08:

- Data item address: `0x0066da96`
- IDA name: `byte_66DA96`
- Segment: `.data`, `0x0066d000-0x0069d000`
- Item head: `0x0066da96`
- Item size: `1`
- Initial byte value: `1`
- Direct xrefs to `0x0066da96`: 23 unique instruction addresses across 14 functions
- All direct xrefs observed in this pass are reads of the form `movsx <reg>, byte_66DA96`.
- No direct store, `mov byte_66DA96, ...`, config parser assignment, constructor assignment, or startup write was found among direct xrefs.

Nearby initialized data observed by IDA MCP:

| Address | IDA item | Value | Documentation lead |
| --- | --- | ---: | --- |
| `0x0066da88-0x0066da90` | wide buffer bytes for `X:\` | mixed | [UID:00027D] `FolderSelectDriveRootBuffer` |
| `0x0066da90-0x0066da94` | `dword_66DA90` | `1` | [UID:00027E] / [UID:0000PY] `g_fpsDebugActive` |
| `0x0066da94-0x0066da96` | `word_66DA94` | `1024` | [UID:0001OG] / [UID:0000SU] `g_screenWidth` |
| `0x0066da96-0x0066da97` | `byte_66DA96` | `1` | [UID:00027F] / [UID:0002CF] `g_movementSubstepScale` |
| `0x0066da97-0x0066da98` | `byte_66DA97` | `1` | [UID:0001OH] / [UID:0000SW] `g_useEpfAssets` |
| `0x0066da98-0x0066da9a` | `word_66DA98` | `768` | [UID:0001OI] / [UID:0000ST] `g_screenHeight` |
| `0x0066da9c-0x0066da9e` | `word_66DA9C` | `48` | [UID:0001OJ] / [UID:0000T7] map tile width |
| `0x0066daa0-0x0066daa2` | `word_66DAA0` | `48` | [UID:0001OK] / [UID:0000T7] map tile height |

Nearby xref counts from IDA MCP:

| Address | Xref count | Function count | Ownership implication |
| --- | ---: | ---: | --- |
| `0x0066da90` | 4 | 1 | localized FPS diagnostics flag; adjacency does not imply shared owner |
| `0x0066da94` | 98 | 49 | broad screen-width readers |
| `0x0066da96` | 23 | 14 | map movement/timing readers only |
| `0x0066da97` | 366 | 249 | broad EPF/render/layout mode readers |
| `0x0066da98` | 96 | 48 | broad screen-height readers |
| `0x0066da9c` | 89 | 51 | broad map tile-width readers |
| `0x0066daa0` | 94 | 52 | broad map tile-height readers |

Representative IDA disassembly confirms the semantic use:

- `0x00468577` in `sub_468520`: reads `byte_66DA96`, shifts left by 2, then divides an owner-relative offset by that `4 * scale` divisor.
- `0x005055f7` in `sub_5055E0`: reads `byte_66DA96`, shifts left by 2, multiplies by `word_66DA9C`/`word_66DAA0` tile dimensions, then divides by the scale for map object positioning.
- `0x0050b0f5` and `0x0050b11c` in `sub_50B080`: same `4 * scale` divisor pattern around tile dimension use and direction state.
- `0x0053864f` in `sub_538600`: reads the scale, shifts left by 2, and divides attached object offsets by the same divisor.
- `0x0053c773` and `0x0053c78f` in `sub_53C700`: reads the scale twice, shifts left by 2, and divides anchor offsets.
- `0x005a3725` in `sub_5A36F0`: reads the scale and divides a byte timer/delay by the scale directly.
- `0x005a840e` in `sub_5A83B0`: reads the scale, shifts left by 2, and uses it in movement subframe/modulus-style animation math.
- `0x005ab554` in `sub_5AB410`: reads the scale and divides a movement delay by it directly.

Inference from IDA: the variable is a process-wide movement substep/timing scale used by map object coordinate interpolation and actor/user movement timer scheduling. IDA confirms the current descriptive name's semantics, but IDA does not reveal the original source spelling or declaration file.

## Direct Xref Inventory

| Function start | Direct refs | Documentation owner lead | IDA-confirmed role |
| --- | --- | --- | --- |
| `0x00468520` | `0x00468577`, `0x00468644` | `BalloonObjectPane` / [UID:0000HJ] `AttachedObjectPane` | attached/balloon object position interpolation using `4 * scale` |
| `0x005055e0` | `0x005055f7` | [UID:0000L3] `MapPane` | map object coordinate helper using tile dimensions and `4 * scale` |
| `0x00506980` | `0x00506a1e` | [UID:0000L3] `MapPane` | map/object placement helper using movement offset divisor |
| `0x0050b080` | `0x0050b0f5`, `0x0050b11c` | [UID:0000L3] `MapPane` | object screen coordinate correction using tile dimensions and movement direction |
| `0x00538600` | `0x0053864f` | [UID:0000HJ] `AttachedObjectPane` | attached object position update using `4 * scale` |
| `0x005386c0` | `0x00538744`, `0x0053875d` | [UID:0000HJ] `AttachedObjectPane` | attached object screen-position helper |
| `0x00539b20` | `0x00539b6f` | [UID:0000HJ] `AttachedObjectPane` / object overlays | object label/overlay placement |
| `0x0053c700` | `0x0053c773`, `0x0053c78f` | [UID:0000HL] `AttachmentAnchorResolver` | anchor offset scaling using `4 * scale` |
| `0x0053c810` | `0x0053c895` | [UID:0000HL] `AttachmentAnchorResolver` | anchor/bounds helper using moving source offset |
| `0x005a36f0` | `0x005a3725` | [UID:0000KU] `LivingObjectPane` | movement animation/timer start, delay divided by scale |
| `0x005a3770` | `0x005a3836` | [UID:0000KU] `LivingObjectPane` | directional movement/timer start, delay divided by scale |
| `0x005a83b0` | `0x005a840e`, `0x005a846b`, `0x005a84cc`, `0x005a85fe`, `0x005a865b`, `0x005a86bc` | [UID:0000P1] `UserPane` | animation-step movement subframe/timer math |
| `0x005a88d0` | `0x005a8923` | [UID:0000KU] `LivingObjectPane` | local player screen/hit bounds update |
| `0x005ab410` | `0x005ab554` | [UID:0000KU] `LivingObjectPane` | movement packet/correction delay scheduling |

IDA confirms the functions read a shared global. Documentation leads map those functions into existing file/class families, but the documentation alone does not prove the declaration owner. The xref distribution cuts across those families.

## Documentation Evidence And IDA Status

- [UID:0002CF] `by-global/g_movementSubstepScale.md` documents `0x0066da96`, one byte, initial value `1`, `87/89`, `RECONSTRUCTABLE:TRUE`, blank parent, descriptive name, and unresolved source owner. IDA confirms the address, size, value, read xrefs, and semantics. IDA does not preserve literal source spelling; this report therefore treats `g_movementSubstepScale` as the recommended reconstructed name rather than a recovered symbol.
- [UID:00027F] `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md` documents the exact storage byte and notes generated by-global memory parenting is unsupported. IDA confirms exact storage. Generated coverage, not IDA, is the reason the by-memory child cannot simply parent to [UID:0002CF].
- [UID:0000L3] `by-file/MapPane.md` documents map-coordinate/object helper ownership and `NexusTK/map/` placement. IDA confirms several target consumers are map-coordinate helpers and that `word_66DA9C`/`word_66DAA0` are used beside `byte_66DA96`; IDA does not provide absolute declaration metadata, but the confirmed helper coupling makes `MapPane.cpp` the best current source-file inference.
- [UID:0000KU] `by-file/LivingObjectPane.md` documents movement/timer responsibilities. IDA confirms several important target consumers are living/local-player movement functions; IDA does not confirm global declaration ownership.
- [UID:0000P1] `by-file/UserPane.md` documents `UserPane::OnAnimationStep` and has a gate-clearing score. IDA confirms six reads in `0x005a83b0`; IDA contradicts any UserPane-only owner inference because most refs are outside UserPane.
- [UID:0000HJ] `by-file/AttachedObjectPane.md` and [UID:0000HL] `AttachmentAnchorResolver.md` document attached overlay positioning. IDA confirms multiple consumers there; IDA contradicts treating them as exclusive owners because target reads also appear in MapPane/LivingObjectPane/UserPane code.
- [UID:0000SU] `g_screenWidth`, [UID:0000ST] `g_screenHeight`, [UID:0000SW] `g_useEpfAssets`, and [UID:0000T7] `MapTilePixelDimensions` are useful neighboring-global leads. IDA confirms adjacency and broad xref patterns. IDA contradicts an undifferentiated "same owner because nearby" conclusion because each neighbor has distinct xref distribution and semantics.
- [UID:0000PY] `g_fpsDebugActive` is a useful negative control. IDA confirms it is adjacent but localized to one FPS diagnostics family; this contradicts address-cluster-only ownership for the whole initialized island.
- `by-project-structure/proposed-source-tree.md` lists `map/MapPane.cpp` as the primary live-world source module and explicitly says it owns map coordinate conversion, visible-bounds calculation, object-pane indexing, and map tile/rendering behavior. It also says [UID:0000T7] `MapTilePixelDimensions` are shared globals consumed by MapPane setup and coordinate helpers. The same proposed source tree lists separate map companions such as `AttachmentAnchorResolver.cpp`, `AttachedObjectPane.cpp`, `LivingObjectPane.cpp`, and `GameServerConfig.cpp`, but no `MapMovementGlobals.cpp`, `MapMovementConfig.cpp`, or MapPane coordinate-helper companion file. This is documentation/source-tree evidence only; IDA confirms the helper coupling that makes the MapPane path stronger than the absent standalone-global hypothesis.

## Ranked Ownership Analysis

### 1. Existing [UID:0000L3] `MapPane` / `NexusTK/map/MapPane.cpp`

Recommendation rank: best candidate and current recommended owner after score/gate repair.

Evidence for:

- IDA confirms direct target consumers in MapPane coordinate helpers: `0x005055e0`, `0x00506980`, and `0x0050b080`. These use `byte_66DA96` as a `4 * scale` movement divisor while converting map object offsets to screen coordinates.
- IDA confirms the byte is used beside map tile dimensions `word_66DA9C` and `word_66DAA0` in `0x005055e0`, `0x00506980`, `0x0050b080`, and `0x005a88d0`, and the separate helper `0x00505100` multiplies direction offsets by the same tile dimensions. This is the strongest sibling-data tie in the local `.data` neighborhood.
- IDA confirms all direct readers either are MapPane coordinate helpers or call/consume the MapPane direction-coordinate API: `0x00505080`, `0x00505100`, `0x00505130`, `0x005055e0`, `0x005058b0`, `0x005059d0`, and `0x00506980`.
- IDA found no direct writer, initializer function, config parser, or startup routine for `byte_66DA96`. With declaration metadata absent, the best ownership signal is the coherent MapPane coordinate-helper consumption surface rather than a write site.
- The proposed source tree explicitly defines `map/MapPane.cpp` as owning map coordinate conversion, visible-bounds calculation, object-pane indexing, map file load/save, rendering, packet handling, and MapTilePixelDimensions consumption. That documentation is not proof by itself, but IDA confirms the relevant coordinate/helper behavior.
- `MapPane.md` already includes [UID:0000VC] `ScaleDirectionOffsetToPixels_00505100`, [UID:0001AP] `0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore`, [UID:0002QL] `0x005058b0-0x0050593e.MapPaneScrollViewportByDirection`, and [UID:0001AT] `0x00506970-0x0050e320.MapPaneInputPacketRenderCore` as MapPane coordinate/placement surfaces. IDA confirms those are the same helper families used by `byte_66DA96`.

Evidence against:

- Literal declaration proof is absent: no debug/source strings, PDB markers, linker-map clues, symbol name, or source-file metadata were found in the earlier IDA MCP breadcrumb scan.
- Some reads occur in `AttachedObjectPane`, `AttachmentAnchorResolver`, `LivingObjectPane`, and `UserPane`. These prove the scalar is shared across map actors and overlays, but their callees route back through MapPane coordinate helpers and they are weaker as declaration owners.
- Current [UID:0000L3] is scored `88/80`, below the mechanical confidence gate. This is a documentation scoring problem: IDA evidence supports raising confidence, but B001 should not edit the by-file page directly.
- A private MapPane coordinate-helper translation unit or header/source companion remains possible, but no current source-tree entry or IDA boundary evidence supports one over `MapPane.cpp`.

Conclusion: choose `MapPane.cpp` as the current best source-file owner. Raise/improve [UID:0000L3] first, or create a narrower MapPane-owned coordinate/movement helper parent that still resolves to `MapPane.cpp`.

Confidence: `88/100`.

### 2. MapPane-owned coordinate/movement helper subdocument

Evidence for:

- This option handles the mechanical gate if the broad [UID:0000L3] `MapPane` confidence is not immediately repaired.
- It matches IDA better than a standalone globals file because the proposed contents are the actual direction/coordinate helper surface tied to the byte.
- It would give A-agents a narrow place to attach [UID:0002CF]/[UID:00027F] without implying that every MapPane child has already reached final confidence.

Evidence against:

- It is a documentation repair/split, not a proven original `.cpp` file. The original source most likely remains `MapPane.cpp` unless future evidence proves a companion file.
- Creating this as a new by-file would overstate the evidence. If created, it should be documented as a MapPane-owned helper grouping/subdocument, not `NexusTK/map/MapMovementGlobals.cpp`.

Likely contents if this split is used:

- [UID:0002CF] `by-global/g_movementSubstepScale.md` and exact storage [UID:00027F] `0x0066da96-0x0066da97.g_movementSubstepScale`.
- [UID:0000VC]/[UID:0001AQ] `ScaleDirectionOffsetToPixels_00505100`, confirmed by IDA as direction-offset-to-tile-pixels helper.
- Unsplit `0x00505080` direction-to-tile-offset helper and unsplit `0x00505130` MapPane tile/viewport-to-screen conversion helper.
- [UID:0001AP] coordinate-helper subset `0x00505080-0x0050571e`, especially `0x005055e0` where IDA reads `byte_66DA96`.
- [UID:0002QL] `0x005058b0-0x0050593e.MapPaneScrollViewportByDirection` and likely [UID:0002QM] `0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition` as adjacent MapPane direction/viewport helpers.
- [UID:0001AT] MapPane placement helpers `0x00506980` and `0x0050b080`, because both directly consume `byte_66DA96`.
- [UID:0000T7] `MapTilePixelDimensions` and storage [UID:0001OJ]/[UID:0001OK] should share the same MapPane coordinate-helper parent or stay visible as map/render layout globals. IDA supports inclusion in the helper grouping because the only meaningful scale-neighbor overlap is tile dimensions; however, tile dimensions have a broader consumer set, so they should not be renamed as movement-only globals.
- [UID:00027O] `MapObjectDirectionMasks` likely belongs as a MapPane movement/direction constants sibling, because IDA confirms direction-mask use in MapPane movement/occupancy helpers. It is conceptual sibling evidence, not address-adjacent proof.

Items to exclude from this helper split:

- [UID:00027D] `FolderSelectDriveRootBuffer`, [UID:0000PY]/[UID:00027E] `g_fpsDebugActive`, [UID:0000SU]/[UID:0001OG] `g_screenWidth`, [UID:0000SW]/[UID:0001OH] `g_useEpfAssets`, and [UID:0000ST]/[UID:0001OI] `g_screenHeight`: IDA confirms unrelated or much broader xref distributions.
- [UID:00027I] `MapPaneCoordinateClampConstants`: IDA confirms zero function overlap with scale readers and a mixed map-clamp/item-remap xref pattern. It should receive a separate constants review before any MapPane coordinate grouping decision.

Conclusion: acceptable fallback if broad MapPane cannot be gate-repaired immediately. The split should still be MapPane-owned and source-path-compatible with `MapPane.cpp`.

Confidence: `84/100` as a documentation repair path; lower than direct MapPane because it is a modeled grouping rather than a proven source file.

### 3. New standalone `NexusTK/map/MapMovementGlobals.cpp` or `MapMovementConfig.cpp`

Evidence for:

- `byte_66DA96` is writable initialized `.data`, value `1`, with no direct writer. A global declaration in some shared map configuration source is possible in abstract C++ terms.
- Consumers span MapPane, attached overlays, living-object movement, and user animation, so a shared declaration is plausible.

Evidence against:

- No IDA writer, initializer, source metadata, string, or isolated data cluster supports a separate file.
- The current proposed source tree has no `MapMovementGlobals.cpp`, `MapMovementConfig.cpp`, `MapConstants.cpp`, or private coordinate helper file. It instead places coordinate conversion and tile dimension use under `MapPane.cpp`.
- The byte is not used by arbitrary movement systems; its consumers are tied to MapPane direction/tile/pixel helpers. A standalone globals file would hide that stronger code-surface relationship.
- Nearby initialized data is mixed: FPS diagnostics, screen dimensions, EPF mode, tile dimensions, coordinate constants, and StringUtil empty string storage. Address adjacency alone would create a false broad owner.

Conclusion: rejected as the primary recommendation. Do not create this file unless future evidence finds source metadata or a writer/initializer proving a separate map-movement configuration unit.

Confidence: `42/100`.

### 4. Existing [UID:0000KU] `LivingObjectPane`

Evidence for:

- IDA confirms important movement/timer reads in `0x005a36f0`, `0x005a3770`, `0x005a88d0`, and `0x005ab410`.
- These functions use the byte for direct delay division and local movement/screen-position correction, which is semantically close to the proposed name.
- Documentation places `LivingObjectPane` under `NexusTK/map/` and describes actor movement/timer ownership.

Evidence against:

- IDA confirms direct coordinate/helper consumers outside `LivingObjectPane`, including `0x005055e0`, `0x00506980`, and `0x0050b080`.
- `0x005a36f0` and `0x005a3770` call back into `0x00506980` after scheduling movement, making MapPane placement the shared coordinate endpoint.
- No write/initializer evidence ties declaration ownership to `LivingObjectPane`.
- The current file confidence is below the direct-parent gate.

Conclusion: strong semantic consumer, but not the best declaration owner.

Confidence: `50/100`.

### 5. Existing [UID:0000P1] `UserPane`

Evidence for:

- IDA confirms six direct reads in `0x005a83b0`, the densest single function use.
- Documentation score is gate-clearing (`89/85`).
- The function uses both `4 * scale` movement subframes and delay scaling.

Evidence against:

- IDA confirms most xref functions are outside UserPane.
- `0x005a83b0` calls MapPane coordinate/movement helpers including `0x005055e0`, `0x005058b0`, and `0x00505080`.
- No writer or declaration clue exists in UserPane.

Conclusion: strongest gate-clearing consumer, but a bad owner. Assigning here would overfit one high-traffic method.

Confidence: `36/100`.

### 6. Existing [UID:0000HJ] `AttachedObjectPane` and [UID:0000HL] `AttachmentAnchorResolver`

Evidence for:

- IDA confirms direct reads in attached overlay and anchor placement functions.
- The `4 * scale` divisor is important to attached object position interpolation.
- [UID:0000HJ] currently clears `85/85`.

Evidence against:

- IDA confirms broad use outside attached overlays.
- AttachmentAnchorResolver is below the gate and has only a small subset of refs.
- Neither candidate owns local-player movement timers or MapPane object coordinate helpers.

Conclusion: confirmed consumers, too narrow for declaration ownership.

Confidence: `30/100` for AttachedObjectPane, `20/100` for AttachmentAnchorResolver.

### 7. Existing `Application`, `Config`, `RegistryConfig`, `StartupWindow`, or [UID:0000JP] `GameServerConfig`

Evidence for:

- A process-wide initialized `.data` scalar could have been declared in an app/config source file.
- Neighboring screen width/height and EPF mode globals have app/config/display flavor.
- Documentation leads mention application-level globals and StartupWindow writing `g_useEpfAssets`.
- `GameServerConfig` is map/gameplay adjacent and may have private MapPane helper status in source-tree notes.

Evidence against:

- IDA direct xrefs for `byte_66DA96` are movement/map consumers only; no direct reads or writes were observed in application/config/startup/config code.
- Neighboring `g_useEpfAssets` has a much broader and different xref distribution, and its documented exact write is not evidence for `byte_66DA96`.
- Treating all adjacent small globals as app/config-owned would contradict the localized `g_fpsDebugActive` case and the target's map-only use pattern.
- `GameServerConfig` has no direct scale reads in the current evidence; its tie is map initialization context, not movement substep math.

Conclusion: plausible original-source location in abstract C++ terms, but currently unsupported by IDA for this target.

Confidence: `25/100`.

### 8. Neighboring by-global or by-memory parents

Evidence for:

- `g_screenWidth`, `g_useEpfAssets`, `g_screenHeight`, `MapTilePixelDimensions`, and map coordinate constants sit in the same initialized island.
- `byte_66DA96` is used together with tile dimensions in some map-coordinate functions.

Evidence against:

- IDA item boundaries are separate: the target is its own one-byte data item.
- Xref populations differ sharply by neighbor.
- Generated coverage currently rejects by-global memory parenting as `autogen_parent_unknown`.
- A by-global page is a semantic storage anchor, not a source-file owner.

Conclusion: useful neighborhood evidence, not a direct owner. It supports MapPane coordinate/movement ownership only when combined with helper semantics.

Confidence: `20/100` as direct parent, higher as contextual evidence.

### 9. Existing [UID:0000JK] `FpsPane` or [UID:00027D] `FolderSelectDriveRootBuffer`

Evidence for:

- Physical adjacency only.

Evidence against:

- IDA xrefs for `g_fpsDebugActive` are localized to FPS diagnostics, while `byte_66DA96` xrefs are map movement/timing.
- The folder-select buffer bytes immediately before the FPS flag have unrelated dialog path semantics.
- No target refs enter FPS or folder selection code.

Conclusion: rejected.

Confidence: near zero.

## Negative Evidence Summary

- No direct writer/initializer/source declaration site for `0x0066da96` was found in IDA xrefs.
- No literal original source spelling was recovered. Earlier IDA MCP breadcrumb scanning found no debug/source metadata such as PDB markers or source path strings, so `g_movementSubstepScale` remains a reconstructed descriptive name.
- No direct IDA evidence proves a private MapPane coordinate-helper translation unit or header/source companion. The stronger inference is that the scalar belongs with the MapPane coordinate helper surface currently modeled under `MapPane.cpp`.
- No existing gate-clearing non-MapPane owner is stronger than MapPane. `UserPane` and `AttachedObjectPane` meet numeric gates but are contradicted by broad non-owner reads and MapPane helper calls.
- Immediate address adjacency is mixed and cannot be used as a sole owner argument.
- Existing documentation supports the MapPane coordinate/movement interpretation, but documentation is treated as hypothesis. The ownership recommendation rests on IDA-confirmed helper coupling plus source-tree fit.

## Final Recommendation

Assign [UID:0002CF] `g_movementSubstepScale` and exact storage [UID:00027F] `0x0066da96-0x0066da97.g_movementSubstepScale` to [UID:0000L3] `MapPane` / `NexusTK/map/MapPane.cpp` after repairing the MapPane confidence gate. The implementation recommendation is to improve [UID:0000L3] from `88/80` to an evidence-backed `>=85` confidence using this report's IDA facts, then apply the parent assignment.

If the supervisor wants a narrower parent before raising the broad MapPane file, create a MapPane-owned coordinate/movement helper subdocument, not a new independent source file. That helper grouping should resolve to `MapPane.cpp` and initially cover [UID:0002CF]/[UID:00027F], `0x00505080`, [UID:0000VC]/[UID:0001AQ] `ScaleDirectionOffsetToPixels_00505100`, `0x00505130`, `0x005055e0`, [UID:0002QL] `0x005058b0-0x0050593e`, likely [UID:0002QM] `0x005059d0-0x00505bf8`, the `0x00506980`/`0x0050b080` MapPane placement helpers, and map-direction/tile siblings where separately gate-ready.

Do not create or recommend `MapMovementGlobals.cpp` / `MapMovementConfig.cpp` as the primary owner. That path has been challenged and rejected: it has no IDA writer, no source metadata, no current source-tree model, no isolated data cluster, and weaker explanatory power than the MapPane coordinate-helper chain.

Name recommendation: use `g_movementSubstepScale` as the reconstructed source name. This is not a recovered original symbol. IDA confirms the semantics but not literal source spelling; no currently available binary evidence is likely to recover literal spelling without PDB/linker-map/source artifacts.

## Follow-Up Actions

- A-agent/supervisor: raise or otherwise repair [UID:0000L3] `MapPane` confidence to clear the `85/85` parent gate, citing the IDA-confirmed coordinate-helper evidence for `0x00505080`, `0x00505100`, `0x00505130`, `0x005055e0`, `0x005058b0`, `0x005059d0`, `0x00506980`, and `0x0050b080`.
- A-agent after MapPane repair: attach [UID:0002CF] to [UID:0000L3] `MapPane` and route [UID:00027F] exact storage to the same source owner or through the supported exact-storage model; do not rely on unsupported by-global memory parenting.
- Supervisor fallback: if broad MapPane cannot be raised immediately, create a MapPane-owned coordinate/movement helper parent under the MapPane source path and attach [UID:0002CF]/[UID:00027F] there.
- A-agent: separately audit [UID:0000T7] `MapTilePixelDimensions` for the same MapPane coordinate-helper parent. Current IDA evidence supports relatedness, but tile dimensions have a broader consumer set and should remain map/render layout globals rather than movement-only globals.
- A-agent: separately audit [UID:00027I] `MapPaneCoordinateClampConstants` as a mixed map-coordinate/item-image constants problem; do not add it to the movement helper grouping based on adjacency alone.
- Supervisor/tooling: keep by-global memory parenting limitation explicit; do not infer by-global parentage in generated coverage until the model supports it.
- A-agent: treat `g_movementSubstepScale` as a descriptive name until original spelling is recovered.

## Confidence

- Storage/value/boundary confidence: very high, `93/100`. IDA confirms one-byte item `0x0066da96`, initial value `1`, strict neighboring items, and 23 unique direct read refs.
- Behavior confidence: high, `92/100`. IDA disassembly confirms repeated use as `4 * byte_66DA96` for map/anchor offset interpolation and `delay / byte_66DA96` for movement timer scaling.
- MapPane source-owner confidence: high, `88/100`. This is above the action threshold because the direct read set is coherent with MapPane coordinate helpers, source-tree documentation places coordinate conversion and MapTilePixelDimensions under `MapPane.cpp`, and competing gate-clearing owners are only consumers.
- Rejection of standalone `MapMovementGlobals.cpp` / `MapMovementConfig.cpp`: high, `86/100`. No writer, metadata, source-tree entry, or isolated global cluster supports it, and the MapPane helper chain explains the data use better.
- Literal original spelling confidence: low, `30/100`. Use `g_movementSubstepScale` as the best reconstructed name, not a recovered symbol.
- Helper-subdocument fallback confidence: `84/100`. It is a practical gate repair if broad MapPane cannot be raised, but it should remain MapPane-owned rather than a separate source file.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002CF-g_movementSubstepScale.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002CF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
