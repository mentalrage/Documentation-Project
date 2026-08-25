# UID0000NR SnowingLayerPane Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000NR **
** TARGET-REPORT-ADDITIONAL-UIDS:0000DC,0001Q4,0001WJ,0002Z9,0003O1,0003O2,0003O3,0003O4 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

The active source route should remain the combined `NexusTK/map/WeatherLayerPane.cpp` and `WeatherLayerPane.h` translation unit owned by [UID:0000P8]. [UID:0000NR] should remain a non-emitting historical file hypothesis, but its active prose must stop presenting a dedicated Snowing file as an unresolved equal alternative. The combined route is supported by the contiguous Weather/Raining/Snowing/Swallow code island, contiguous RTTI/vtable island, contiguous rain/snow writable table island, shared base/layout/header dependencies, sibling virtual-slot equivalence, and the absence of any source/PDB filename evidence for a standalone Snowing unit.

The whole-file Snowing inventory is complete enough to raise [UID:0000NR] from `90/89` to `94/94`. The principal source corrections are:

- `0x005c1c80` is `SnowingLayerPane::OnPaint()`, not `UpdateAndRenderSnowParticles`.
- `0x005c1f50` is `SnowingLayerPane::OnFrameChanged()` and now has an exact formal CPP body.
- `0x005c20e0` is `SnowingLayerPane::DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)`, not a one-target-plus-three-int render helper.
- The two guarded 40-byte-record arrays are `EPFTileContext[2]`, not a new `SnowPatternDescriptor` type.
- `g_pfnFillRect`, `g_pfnBlitSprite`, `InitRectBounds`, and `NexusTK_OffsetRect` are the accepted shared interfaces; provisional wrappers such as `BeginWeatherDraw`, `RenderSnowParticle`, and `SetRect` must leave formal source.
- `0x005c2a20` and the `0x005c29ec`/`0x005c29f7` adjustor thunks are compiler output. They need exact documentation and IDA identities but no authored destructor body.

Every ordinary-documentation, coverage, validator, generated-output, and IDA action remains unchecked in this report-only phase.

## Supporting Research

Research used current by-file, by-class, by-memory, by-type, by-global, by-project-structure, generated CPP/H, manual coverage, and tracker evidence together with the live canonical IDA MCP session `supervisor_uid0000ms_canonical_final_20260825_2143`. Public runtime attestation at `2026-08-25T22:22:53Z` identified the expected canonical NexusTK IDB and active listener/worker. All IDA work for this report was read-only.

Current generated output command `000000028253` demonstrates the practical routing defect: `NexusTK/map/SnowingLayerPane.cpp` contains only the UID0000NR root and UID0001Q4 covered-by marker, while the real Snowing declarations and method children emit in `WeatherLayerPane.h/.cpp`. That generated snapshot is evidence, not permanent authority; callback verification must reread current generated headers after scoped validation.

No filename string matching `SnowingLayerPane`, `WeatherLayerPane`, `RainingLayerPane`, or `SwallowLayerPane` with a C/C++ source/header extension was found. This negative result prevents claiming exact historical disk filenames, but it does not make the active route ambiguous after the independent physical, ownership, and declaration-order evidence is combined.

## Target

- Primary: [UID:0000NR] `by-file/SnowingLayerPane.md`, current `90/89`, projected path `NexusTK/map/`, `CANONICAL_OWNER:FILE`.
- Declared class target: [UID:0000DC] `by-class/SnowingLayerPane.md`, current `91/93`.
- Declared exact method targets: [UID:0003O1], [UID:0003O2], [UID:0003O3], and compiler-only [UID:0003O4].
- Declared data/type/vtable targets: [UID:0001Q4], [UID:0001WJ], and [UID:0002Z9].
- Reconciled unchanged support: [UID:0000P8], [UID:0003O0], [UID:0001OO], [UID:0001O0], [UID:0001O1], [UID:0000TP], MapPane construction, Surface callback declarations, and proposed source tree.

The source-bearing Snowing body interval is not one contiguous file range. Exact Snowing methods occupy `[0x005c1bd0,0x005c2228)`, then Swallow code occupies `[0x005c2230,0x005c29ec)`, followed by Snowing destructor thunks and wrapper at `0x005c29ec`, `0x005c29f7`, and `[0x005c2a20,0x005c2a5b)`.

## Current Target State

| UID | Current state | Defect or retained fact |
| --- | --- | --- |
| `0000NR` | `90/89`, historical candidate | Correctly noncanonical, but still frames the standalone-vs-shared route as a live confidence blocker. |
| `0000DC` | `91/93`, owner/emitter `0000P8` | Exact object layout is strong; H still declares wrong method names/signatures. |
| `0003O0` | `92/94` | Exact constructor/body/layout route is already source-ready and should remain unchanged. |
| `0003O1` | `88/89` | Formal CPP uses wrong method/helper/field/type names and an added null guard. |
| `0003O2` | `89/91` | Exact behavior is documented but formal CPP is blank. |
| `0003O3` | `88/89` | Formal CPP discards the actual target and uses a wrong four-parameter projection. |
| `0003O4` | `85/88` | Compiler deleting wrapper is incorrectly reconstructable/emitting and lacks exact sibling-equivalent disposition. |
| `0001Q4` | `86/90` metadata; manual coverage says `80%` | Local-static storage is routed to historical `0000NR` and uses a provisional descriptor abstraction. |
| `0001WJ` | `93/94` | Exact `SnowParticleEntry` is correct; obsolete `SnowPatternDescriptor` hypothesis conflicts with existing `EPFTileContext`. |
| `0002Z9` | `88/92` | Vtable facts are strong but method identities and compiler-only destructor disposition need synchronization. |

## Executive Recommendation

Accept one combined Weather source-family reconstruction. Keep [UID:0000NR] as preserved historical provenance with no source emitter. Implement exact child CPP on [UID:0003O1], [UID:0003O2], and [UID:0003O3], exact class H on [UID:0000DC], and local-static covered-by routing on [UID:0001Q4]. Reclassify [UID:0003O4] and the two adjustor thunks as compiler-only. Do not create a handwritten destructor, standalone Snow descriptor struct, standalone Snowing translation unit, raw vtable source, or duplicate static arrays.

The resulting source should look like ordinary late-1990s/early-2000s C++: class overrides, file-static byte arrays, function-local static `EPFTileContext` arrays, natural structure padding, and shared callback globals. Runtime-sensitive random-call order, 200-entry loops, the 180-entry `memmove`, exact range arithmetic, direct map-state gate, and callback arguments must remain binary-faithful.

## Supervisor Active Recheck

The live canonical recheck established:

- IDB session: `supervisor_uid0000ms_canonical_final_20260825_2143`; expected canonical path and module identity passed runtime attestation.
- `0x005c1c80`: display label `sub_5C1C80`, current type `MapPane *__thiscall(GrafPort *this)`, no comments.
- `0x005c1f50`: registered `SnowingLayerPane__OnFrameChanged`, correct no-argument `__thiscall` type, existing role comment.
- `0x005c20e0`: display label `sub_5C20E0`, current type `MapPane *__thiscall(char *this, GrafPort *port, int, int)`, no comments.
- `0x005c2a20`: display label `sub_5C2A20`, current type `Pane *__thiscall(Pane *Block, char)`, no comments.
- `0x005c29ec` and `0x005c29f7`: autogenerated labels, adjusted-`this` thunk bodies, wrong generic types, and stale `Block`-style address comments.
- Anchored exact registered-name queries return zero registrations for each autogenerated `sub_...` spelling and zero for each proposed human name. Address/display lookup is therefore separate from registered-name proof.
- Current local-static storage at `0x0069bf98` and `0x0069bff0` is incompletely modeled: the first item shows an `EPFTileContext` head, the second has a `sourceContext` label and an interior `bounds` label, and guards remain broad integer items. Source evidence nevertheless proves two `EPFTileContext[2]` arrays plus two four-byte guards.

## Inference Research Guidance Check

This report does not preserve reverse-engineering labels as final source merely because original symbols are absent. The preferred names derive from exact sibling slot identities, accepted shared interfaces, object layout, call signatures, and project-wide source conventions. Where original spelling remains unknowable, the report selects the most realistic consistent human spelling rather than leaving `sub_`, `dword_`, opaque integer parameters, or invented one-call wrappers.

Execution fidelity has priority over stylistic uniformity. The chosen style follows existing accepted Weather/Pane/Surface declarations unless exact evidence requires otherwise. No Wave2/Wave3 material is used.

## Heuristic / Inference Reanalysis And Validation

### Method identities

Primary vtable slots align exactly across Weather-derived siblings. Snow slot `0x006312f4 -> 0x005c1c80` occupies the same semantic OnPaint position used by Raining and Swallow; Snow slot `0x006312fc -> 0x005c1f50` is the inherited frame-change hook; Snow slot `0x006312c0 -> 0x005c20e0` matches sibling `DrawOnTarget` implementations and the body returns with `retn 0Ch`. These relationships outweigh historical behavior-based names.

### Descriptor identity

The constructor at `0x00457a60` initializes exactly the accepted 40-byte `EPFTileContext` layout: format/state at `+0`, pixel pointer at `+4`, alpha pointer at `+8`, stride at `+0xc`, `RectBounds` at `+0x10`, and two tail fields at `+0x20/+0x24`. The Snow methods allocate two records at 40-byte stride and assign the pixel pointer, stride, and bounds. A separate `SnowPatternDescriptor` would duplicate an already exact shared type and is rejected.

### Source route

Ranked probability:

1. **Shared `WeatherLayerPane.cpp/.h` (high probability, selected):** contiguous family code, ordered constructors/overrides, contiguous RTTI/vtables, contiguous rain/snow file-static arrays, shared private types, current emitter graph, and no contrary filename proof.
2. **Separate class-per-file Weather/Rain/Snow/Swallow units (plausible historical alternative, rejected for current routing):** period style makes it possible, but no direct source/PDB evidence selects it and it requires splitting tightly clustered private storage and declaration order.
3. **Another effects/global unit (low probability, rejected):** no ownership, filename, caller, data, or header evidence supports it.

### Destructor source shape

The scalar deleting wrapper calls base destruction and conditionally frees the `0x10ac` object; adjusted entry points subtract `0xa0` or `0xa4` and tail-jump into it. This is standard MSVC compiler machinery. The human class needs no explicit destructor body because it owns no manually released resources.

## Evidence Standards Used

- Exact function starts/ends, bytes, disassembly, decompilation, stack cleanup, vtable cells, xrefs, callers, and data consumers outrank generated names.
- Repeated sibling slot signatures and accepted project declarations support source-facing inference where symbols were stripped.
- Section placement and physical adjacency support translation-unit ranking but do not alone prove a historical filename.
- Negative searches constrain claims; they are not converted into no-owner or no-code conclusions when positive ownership evidence exists.
- Formal C++ omits compiler artifacts and preserves behavior, call order, signedness, storage duration, physical duplication, and emitter boundaries.

## Evidence Checked

| Evidence family | Exact result |
| --- | --- |
| Function map | `0x005c1bd0` size `0xae`; `0x005c1c80` size `0x2cc`; `0x005c1f50` size `0x184`; `0x005c20e0` size `0x148`; `0x005c2a20` size `0x3b`. |
| Padding | `[0x005c1f4c,0x005c1f50)` four `0xcc`; `[0x005c20d4,0x005c20e0)` twelve `0xcc`; `[0x005c2228,0x005c2230)` eight `0xcc`; `[0x005c2a18,0x005c2a20)` alignment. |
| Constructor route | Sole direct constructor call at `0x0050dc17`, allocation `0x10ac`, selector `2`; Rain selector `1` allocates `0x10c`, Swallow selector `3` allocates `0x16c`. |
| Vtable route | `0x6312b0 -> 0x5c2a20`, `0x6312c0 -> 0x5c20e0`, `0x6312f4 -> 0x5c1c80`, `0x6312fc -> 0x5c1f50`, `0x631304 -> 0x5c29ec`, `0x631334 -> 0x5c29f7`, `0x631338 -> 0x5c13b0`. |
| Snow static bytes | Two distinct byte-identical 40-byte families at `[0x670784,0x6707ac)` and `[0x6707ac,0x6707d4)`; each SHA256 `4AD9D94F...`; combined SHA256 `2E9032C5...`. |
| Local statics | Target contexts `[0x69bf98,0x69bfe8)`, guard `[0x69bfe8,0x69bfec)`, padding `[0x69bfec,0x69bff0)`, main contexts `[0x69bff0,0x69c040)`, guard `[0x69c040,0x69c044)`. |
| Callback ABI | `g_pfnFillRect` is receiver plus bounds; `g_pfnBlitSprite` is target receiver plus context, source bounds, destination bounds, mode, palette, and options. |
| Source strings | No Snowing/Weather/Raining/Swallow LayerPane C/C++ filename string found. |
| Generated route | Current generated Snowing file is marker-only; current Weather CPP/H carries Snowing class and child output. |

## Claim And Incorporation Ledger

| ID | Actor | Action | Destination | Required content | Verification | Done |
| --- | --- | --- | --- | --- | --- | --- |
| C0000NR-001 | B005 | incorporate | `by-file/SnowingLayerPane.md` | Resolve shared Weather source route as current and preserve standalone Snowing only as a ranked historical alternative. | Physical code/data/vtable clustering and negative filename evidence are recorded. | [ ] |
| C0000NR-002 | B005 | incorporate | `by-file/SnowingLayerPane.md` | Replace representative method list with exhaustive authored/compiler/data inventory and exact source order. | Every row in Section 14 has a destination. | [ ] |
| C0000NR-003 | B005 | historicalize | `by-file/SnowingLayerPane.md` | Historicalize unresolved standalone-vs-shared wording without deleting prior evidence. | Active status no longer treats routes as equal. | [ ] |
| C0000NR-004 | B005 | incorporate | `by-file/WeatherLayerPane.md` | Add Snow whole-file closure, selected route evidence, and exact current Snow child identities. | Shared root names O1/O2/O3 correctly. | [ ] |
| C0000NR-005 | B005 | incorporate | `by-class/SnowingLayerPane.md` | Raise to `94/95`; correct class method inventory and compiler-only destructor disposition. | Metadata and prose agree. | [ ] |
| C0000NR-006 | B005 | incorporate | `by-class/SnowingLayerPane.md` formal H | Replace wrong declarations with `OnPaint`, `OnFrameChanged`, and exact `DrawOnTarget` signature; omit explicit destructor. | Generated H contains exact declaration once. | [ ] |
| C0000NR-007 | B005 | incorporate | UID0003O1 | Rename role to `OnPaint`, document exact flow, helpers, fields, random order, and local-static EPFTileContext family. | Target metadata/prose/formal agree at `94/95`. | [ ] |
| C0000NR-008 | B005 | incorporate | UID0003O1 formal CPP | Install exact human C++03 `SnowingLayerPane::OnPaint()` body from Section 22. | Generated CPP has no stale wrappers/null gate. | [ ] |
| C0000NR-009 | B005 | incorporate | UID0003O2 | Close operation order, table use, frame gate, rolling shift, and source route at `94/95`. | Body evidence and score rationale agree. | [ ] |
| C0000NR-010 | B005 | incorporate | UID0003O2 formal CPP | Install exact `SnowingLayerPane::OnFrameChanged()` body from Section 22. | Generated CPP contains a complete nonstub body. | [ ] |
| C0000NR-011 | B005 | incorporate | UID0003O3 | Rename role to exact `DrawOnTarget`, document target use and two ignored bounds arguments. | Metadata/prose/formal agree at `94/95`. | [ ] |
| C0000NR-012 | B005 | incorporate | UID0003O3 formal CPP | Install exact `DrawOnTarget` body using the supplied target and EPFTileContext. | Generated CPP uses target as callback receiver. | [ ] |
| C0000NR-013 | B005 | incorporate | UID0003O4 | Reclassify scalar deleting wrapper to `94/96`, class owner, `RECONSTRUCTABLE:FALSE`, blank emitter/CPP/H. | No handwritten destructor emits. | [ ] |
| C0000NR-014 | B005 | incorporate | new exact thunk page | Create `[0x005c29ec,0x005c2a02)` Snow destructor adjustor-thunk child, compiler-only and non-emitting. | Both thunk starts and offsets are documented. | [ ] |
| C0000NR-015 | B005 | incorporate | UID0001Q4 | Replace SnowPatternDescriptor with exact EPFTileContext[2] families and guards; reroute owner/emitter to `0000P8`. | Storage remains covered-by and marker-only. | [ ] |
| C0000NR-016 | B005 | incorporate | UID0001WJ | Historicalize SnowPatternDescriptor hypothesis and document exact EPFTileContext identity. | No duplicate descriptor type remains active. | [ ] |
| C0000NR-017 | B005 | incorporate | UID0002Z9 | Synchronize exact OnPaint/OnFrameChanged/DrawOnTarget/dtor/thunk vtable identities and score `93/95`. | All seven relevant cells match Section 13. | [ ] |
| C0000NR-018 | B005 | incorporate | UID0001O0 | Update non-emitting index inventory with exact method names and new thunk child. | Index emits no broad code. | [ ] |
| C0000NR-019 | B005 | incorporate | UID0001O1 | Update mixed-island index and preserve Snow/Swallow boundary/exclusions. | No owner bleed across `0x5c2230`. | [ ] |
| C0000NR-020 | B005 | already-present | UID0003O0 | Preserve exact constructor `92/94`, body, object layout, and current Weather route. | No constructor regression. | [ ] |
| C0000NR-021 | B005 | already-present | UID0001OO | Preserve six mutable arrays, values, hashes, owner `0000P8`, and emitter position 1. | No duplicate array formal. | [ ] |
| C0000NR-022 | B005 | incorporate | UID0000TP / callback support | Replace provisional Snow wrapper aliases with accepted Surface callback identities where Snow is discussed. | Existing callback ownership remains unchanged. | [ ] |
| C0000NR-023 | B005 | incorporate | MapPane support | Record selector/allocation/caller route as Snow construction evidence without transferring ownership. | `0x50dc17` and `0x10ac` remain exact. | [ ] |
| C0000NR-024 | B005 | incorporate | proposed source tree | Mark Snowing as class content in WeatherLayerPane CPP/H; retain dedicated file only as historical candidate. | Tree has one active source route. | [ ] |
| C0000NR-025 | B005 | incorporate | target/support Item Summaries | Preserve concise exact current roles after detailed prose is added. | Validator does not erase valid summaries. | [ ] |
| C0000NR-026 | B005 | incorporate | changed ordinary pages | Run one scoped validator per changed by-* page after callback. | Each command exits 0 with `ok:1`. | [ ] |
| C0000NR-027 | B005 | incorporate | generated WeatherLayerPane CPP/H | Physically reread current command metadata and all Snow declarations/bodies after validation. | No empty marker, stale method, or duplicate source remains. | [ ] |
| C0000NR-028 | B005 | incorporate | generated SnowingLayerPane.cpp | Confirm historical route stays marker-only and does not duplicate Weather output. | Generated file contains no authored Snow body. | [ ] |
| C0000NR-029 | B005 | incorporate | report callback receipts | Check only completed ordinary rows after physical reread and preserve exact evidence. | Ledger/checklist twins remain exact. | [ ] |
| C0000NR-030 | Supervisor | incorporate | `by-file/-coverage-report.md` | Apply exact UID0000NR replacement in Section 28. | Current row is `94% : very-strong`. | [ ] |
| C0000NR-031 | Supervisor | incorporate | `by-class/-coverage-report.md` | Apply exact UID0000DC replacement in Section 28. | Current row is `94% : very-strong`. | [ ] |
| C0000NR-032 | Supervisor | incorporate | `by-memory/-coverage-report.md` | Insert/replace exact UID0003O1/O2/O3/O4 rows from Section 28. | Four rows match target metadata. | [ ] |
| C0000NR-033 | Supervisor | incorporate | `by-memory/-coverage-report.md` | Replace exact UID0001Q4 and UID0002Z9 rows from Section 28. | Rows match current routing/scores. | [ ] |
| C0000NR-034 | Supervisor | incorporate | `by-memory/-coverage-report.md` | Insert exact new thunk-child row after UID0003O4. | Compiler-only child is represented once. | [ ] |
| C0000NR-035 | Supervisor | incorporate | IDA-A01 | Rename `0x005c1c80` to `SnowingLayerPane__OnPaint` after exact prestate/collision proof. | Exact desired registration and address readback. | [ ] |
| C0000NR-036 | Supervisor | incorporate | IDA-A02 | Set exact `void __thiscall SnowingLayerPane__OnPaint(SnowingLayerPane *this)` type. | Type/readback and bytes/xrefs unchanged. | [ ] |
| C0000NR-037 | Supervisor | incorporate | IDA-A03 | Set concise OnPaint behavior comment. | Exact comment readback. | [ ] |
| C0000NR-038 | Supervisor | incorporate | IDA-A04 | Rename `0x005c20e0` to `SnowingLayerPane__DrawOnTarget`. | Exact desired registration and address readback. | [ ] |
| C0000NR-039 | Supervisor | incorporate | IDA-A05 | Set exact DrawOnTarget `__thiscall` type with three stack arguments. | Stack cleanup and type readback agree. | [ ] |
| C0000NR-040 | Supervisor | incorporate | IDA-A06 | Set concise DrawOnTarget behavior comment. | Exact comment readback. | [ ] |
| C0000NR-041 | Supervisor | incorporate | IDA-A07 | Rename `0x005c2a20` to `SnowingLayerPane__ScalarDeletingDestructor`. | Exact desired registration and address readback. | [ ] |
| C0000NR-042 | Supervisor | incorporate | IDA-A08 | Set exact deleting-wrapper type with unsigned flags. | Type/readback and body unchanged. | [ ] |
| C0000NR-043 | Supervisor | incorporate | IDA-A09 | Set compiler-only deleting-wrapper comment. | Exact comment readback. | [ ] |
| C0000NR-044 | Supervisor | incorporate | IDA-A10 | Rename `0x005c29ec` to EventHandler adjusted deleting-destructor thunk name. | Desired registration at exact address. | [ ] |
| C0000NR-045 | Supervisor | incorporate | IDA-A11 | Replace stale thunk comment with exact `this-0xa0` tail-forward role. | Exact comment readback. | [ ] |
| C0000NR-046 | Supervisor | incorporate | IDA-A12 | Rename `0x005c29f7` to TimerHandler adjusted deleting-destructor thunk name. | Desired registration at exact address. | [ ] |
| C0000NR-047 | Supervisor | incorporate | IDA-A13 | Replace stale thunk comment with exact `this-0xa4` tail-forward role. | Exact comment readback. | [ ] |
| C0000NR-048 | Supervisor | incorporate | IDA-A14 | Set `0x0069bf98` to exact `EPFTileContext[2]` only after bounded item-boundary precheck. | Array extent ends at `0x69bfe8`. | [ ] |
| C0000NR-049 | Supervisor | incorporate | IDA-A15 | Set `0x0069bff0` to exact `EPFTileContext[2]` only after bounded item-boundary precheck. | Array extent ends at `0x69c040`. | [ ] |
| C0000NR-050 | Supervisor | incorporate | IDA-A16 | Set target-context regular comment at `0x0069bf98`. | Exact comment/readback, no boundary drift. | [ ] |
| C0000NR-051 | Supervisor | incorporate | IDA-A17 | Set main-context regular comment at `0x0069bff0`. | Exact comment/readback, no boundary drift. | [ ] |

Current report-only allocation is exactly 51 ordered claim twins: 29 B005 ordinary/callback verification rows and 22 supervisor-owned coverage/IDA rows. All 51 claims are unchecked in both tables.

## Positive Evidence Summary

- All authored Snow methods are modeled and owned through one class/vtable family.
- MapPane selector `2` allocates exactly `0x10ac` and calls the Snow constructor once.
- `WeatherLayerPane` is exactly `0x10c`; the 200 records at 20 bytes exactly close Snow at `0x10ac`.
- Sibling vtable positions prove source-facing virtual names and the three-argument DrawOnTarget signature.
- Shared callbacks and `EPFTileContext` already have exact accepted declarations elsewhere in the project.
- Static rain/snow arrays and local-static contexts have exact boundaries, consumers, and storage-duration evidence.
- The combined source route minimizes no evidence; it preserves every physical object while avoiding duplicate source.

## IDA MCP Facts

| Address | Exact role | Xref/caller evidence | Current IDA issue |
| --- | --- | --- | --- |
| `0x005c1bd0` | constructor | code caller `0x0050dc17` | Already named/typed/commented correctly. |
| `0x005c1c80` | `OnPaint()` | vtable cell `0x006312f4` | Autogenerated name and wrong prototype. |
| `0x005c1f50` | `OnFrameChanged()` | vtable cell `0x006312fc`; Weather timer dispatch | Already named/typed/commented correctly. |
| `0x005c20e0` | `DrawOnTarget(...)` | vtable cell `0x006312c0`; `retn 0Ch` | Autogenerated name and wrong prototype. |
| `0x005c29ec` | EventHandler adjusted dtor thunk | vtable cell `0x00631304`; code tail to dtor | Autogenerated name/stale comment. |
| `0x005c29f7` | TimerHandler adjusted dtor thunk | vtable cell `0x00631334`; code tail to dtor | Autogenerated name/stale comment. |
| `0x005c2a20` | scalar deleting destructor | vtable `0x006312b0`; calls from both thunks | Autogenerated name/type and no comment. |

The direct active-map gate loads global `g_activeMapPane` and tests byte `+0x3f0`, accepted elsewhere as `m_waitingForLocalPlayerStatus`. There is no null check in these bodies. Adding one would change fault behavior and generated control flow.

## Function / Child Inventory

| Source order | Range/entity | Disposition | Formal owner |
| ---: | --- | --- | --- |
| 1 | static rain arrays `[0x006702c8,0x00670784)` | Existing file-static Weather CPP content | UID0001ON, unchanged |
| 2 | static snow arrays `[0x00670784,0x006707d4)` | Existing six mutable arrays | UID0001OO, unchanged |
| 3 | `SnowingLayerPane::SnowingLayerPane()` `[0x005c1bd0,0x005c1c7e)` | Authored constructor | UID0003O0, unchanged |
| 4 | padding `[0x005c1c7e,0x005c1c80)` | Compiler alignment | no source |
| 5 | `SnowingLayerPane::OnPaint()` `[0x005c1c80,0x005c1f4c)` | Authored virtual body | UID0003O1 |
| 6 | padding `[0x005c1f4c,0x005c1f50)` | four `0xcc` bytes | no source |
| 7 | `SnowingLayerPane::OnFrameChanged()` `[0x005c1f50,0x005c20d4)` | Authored virtual body | UID0003O2 |
| 8 | padding `[0x005c20d4,0x005c20e0)` | twelve `0xcc` bytes | no source |
| 9 | `SnowingLayerPane::DrawOnTarget(...)` `[0x005c20e0,0x005c2228)` | Authored virtual body | UID0003O3 |
| 10 | padding `[0x005c2228,0x005c2230)` | eight `0xcc` bytes | no source |
| 11 | Swallow code `[0x005c2230,0x005c29ec)` | Explicitly excluded | Swallow children |
| 12 | Snow adjusted dtor thunks `[0x005c29ec,0x005c2a02)` | Compiler-only exact child | new non-emitting page |
| 13 | Swallow adjusted dtor thunks `[0x005c2a02,0x005c2a18)` | Explicitly excluded | Swallow support |
| 14 | padding `[0x005c2a18,0x005c2a20)` | compiler alignment | no source |
| 15 | Snow scalar deleting dtor `[0x005c2a20,0x005c2a5b)` | Compiler-only | UID0003O4 |
| 16 | Snow RTTI/vtables `[0x006312ac,0x0063133c)` | Source-declared/compiler-generated | UID0002Z9 marker only |
| 17 | target local contexts `[0x0069bf98,0x0069bfec)` | `static EPFTileContext[2]` plus guard | covered by UID0003O3 |
| 18 | padding `[0x0069bfec,0x0069bff0)` | compiler alignment | no source |
| 19 | main local contexts `[0x0069bff0,0x0069c044)` | `static EPFTileContext[2]` plus guard | covered by UID0003O1 |

No literal/resource string belongs uniquely to Snowing. Swallow’s `SWALLOW.EPF`/`SWALLOW.EPD` strings are explicitly outside scope.

## Direct Xref / Caller Inventory

- Constructor: one code xref from MapPane setup at `0x0050dc17`.
- OnPaint: one data xref from `0x006312f4`; no direct code caller, as expected for virtual dispatch.
- OnFrameChanged: one data xref from `0x006312fc`; Weather timer slot dispatch is the behavioral caller.
- DrawOnTarget: one data xref from `0x006312c0`; virtual target drawing owns the call route.
- Scalar deleting destructor: data xref from `0x006312b0` and code refs from both adjusted thunks.
- EventHandler/TimerHandler dtor thunks: one adjusted-vtable data xref each at `0x00631304` and `0x00631334`.
- Static arrays have exactly the eight current snow consumer refs documented by UID0001OO.
- Local-static target contexts/guard are confined to DrawOnTarget; main contexts/guard are confined to OnPaint.

## Documentation Evidence And IDA Status

Current docs already preserve extensive valid history. Callback work must add this closure, not prune prior evidence. Specifically preserve constructor hashes/layout, old route hypotheses, table bytes/hashes, previous MCP session receipts, and the reasons earlier first drafts were provisional. Incorrect current claims move into labeled historical-assumption sections with the evidence that disproved them.

IDA is read-only in this phase. Recommended mutations are separate supervisor actions in Section 21. The report does not claim they are applied, saved, promoted, or currently authoritative.

## Ranked Ownership Analysis

1. **Class owner [UID:0000DC]:** exact vtables, object layout, constructor, virtual methods, and destructor mechanics all establish Snowing class ownership.
2. **Current source-family owner [UID:0000P8]:** physical ordering, shared private data/types, inherited header dependencies, and current emitter graph establish the combined Weather translation unit.
3. **Historical file [UID:0000NR]:** useful provenance/root documentation only. It should neither emit nor own duplicate arrays/methods.
4. **Rejected owners:** MapPane is a selector/caller; UID0001O0/UID0001O1 are non-emitting indexes; vtable/data pages are evidence containers; Surface owns callback declarations; globals do not own methods.

## Source Placement

Recommended header order in `WeatherLayerPane.h`: shared includes/guard, `SnowParticleEntry`, `WeatherLayerPane`, `RainingLayerPane`, `SnowingLayerPane`, `SwallowLayerPane`, size checks, guard close. Snow class position remains 30.

Recommended CPP order in `WeatherLayerPane.cpp`: accepted rain arrays, accepted snow arrays, Weather methods, Raining methods, Snowing constructor/OnPaint/OnFrameChanged/DrawOnTarget, Swallow methods. Compiler thunks, vtables, RTTI, guards, and scalar deleting wrappers do not appear as authored source.

## Range / Split / Padding / Reclassification Analysis

- Keep exact method pages. Do not emit the broad `[0x5c1bd0,0x5c2a5b)` index because Swallow code interrupts it.
- Create a narrow compiler-only page for `[0x5c29ec,0x5c2a02)` because the two Snow adjustor thunks are separated from UID0003O4 by Swallow thunks and alignment; widening UID0003O4 would create a false contiguous range.
- Preserve all `0xcc`/alignment spans as non-source coverage.
- Keep UID0001Q4’s two arrays/guards under one storage page, but route source ownership to UID0000P8 and execution coverage to O1/O3.
- Keep UID0002Z9 marker-only. C++ vtable emission would duplicate compiler output.

## Negative Evidence Summary

- No source/PDB filename proves a dedicated or combined original file name.
- No direct code callers exist for virtual O1/O2/O3 bodies; vtable-only routing is positive virtual evidence, not unreachability.
- No registered names exist for the current autogenerated `sub_` display labels or proposed names before mutation.
- No evidence supports a separate SnowPatternDescriptor type, heap particle array, explicit source padding members, exported snow tables, or hand-authored deleting wrappers.
- No null check exists before the active-map field read.
- No evidence permits deduplicating the byte-identical target/main snow arrays.
- No Snow method or data route enters Swallow’s code or resource strings.

## IDA Rename / Type / Comment Recommendations

These are concise one-endpoint handoffs. The supervisor owns current runtime attestation, backups, mutation ordering, save/promotion, and fresh readback. Every action fails closed on address, range, bytes/xrefs, type/comment, or exact registered-name collision drift. Autogenerated display labels are not treated as registered old names.

| Action | Endpoint | Exact current prestate | Exact recommendation and required readback |
| --- | --- | --- | --- |
| IDA-A01 | rename `0x005c1c80` | address lookup displays `sub_5C1C80`; anchored old/desired registered-name totals `0/0` | Pure dry-run then rename by address to `SnowingLayerPane__OnPaint`; poststate desired registration exactly one at target, old total zero. |
| IDA-A02 | type `0x005c1c80` | current `MapPane *__thiscall(GrafPort *this)` | `void __thiscall SnowingLayerPane__OnPaint(SnowingLayerPane *this)`; exact type readback. |
| IDA-A03 | comment `0x005c1c80` | no regular/repeatable comment | Regular: `SnowingLayerPane::OnPaint updates 200 snow particles, refreshes 20 records on frame zero, and blits through the main-view contexts.` |
| IDA-A04 | rename `0x005c20e0` | address lookup displays `sub_5C20E0`; anchored old/desired totals `0/0` | Rename to `SnowingLayerPane__DrawOnTarget`; desired registration exactly one at target afterward. |
| IDA-A05 | type `0x005c20e0` | current `MapPane *__thiscall(char *this, GrafPort *port, int, int)`; `retn 0Ch` | `void __thiscall SnowingLayerPane__DrawOnTarget(SnowingLayerPane *this, GrafPort *target, const RectBounds *sourceBounds, const RectBounds *targetBounds)`; exact type/readback. |
| IDA-A06 | comment `0x005c20e0` | no comments | Regular: `SnowingLayerPane::DrawOnTarget blits 200 current particles to the supplied GrafPort using target snow contexts; the two bounds parameters are unused.` |
| IDA-A07 | rename `0x005c2a20` | address lookup displays `sub_5C2A20`; anchored old/desired totals `0/0` | Rename to `SnowingLayerPane__ScalarDeletingDestructor`; desired registration exactly one at target. |
| IDA-A08 | type `0x005c2a20` | current `Pane *__thiscall(Pane *Block, char)` | `SnowingLayerPane *__thiscall SnowingLayerPane__ScalarDeletingDestructor(SnowingLayerPane *this, unsigned int deletingFlags)`; exact readback. |
| IDA-A09 | comment `0x005c2a20` | no comments | Regular: `Compiler-generated scalar deleting destructor; destroys the Pane base and conditionally frees the 0x10ac-byte SnowingLayerPane object.` |
| IDA-A10 | rename `0x005c29ec` | autogenerated display `sub_5C29EC`; desired absent | `SnowingLayerPane__EventHandlerScalarDeletingDestructorThunk`; exact address registration. |
| IDA-A11 | comment `0x005c29ec` | stale generic Block/address wording | Regular: `Compiler-generated EventHandler adjusted-this thunk: subtracts 0xa0 and tail-forwards to the Snowing scalar deleting destructor.` |
| IDA-A12 | rename `0x005c29f7` | autogenerated display `sub_5C29F7`; desired absent | `SnowingLayerPane__TimerHandlerScalarDeletingDestructorThunk`; exact address registration. |
| IDA-A13 | comment `0x005c29f7` | stale generic Block/address wording | Regular: `Compiler-generated TimerHandler adjusted-this thunk: subtracts 0xa4 and tail-forwards to the Snowing scalar deleting destructor.` |
| IDA-A14 | type `0x0069bf98` | incomplete head-only context modeling; exact physical range known | Set `EPFTileContext[2]` only if current bounded item topology can be normalized without overlap; readback must span exactly `[0x69bf98,0x69bfe8)`. |
| IDA-A15 | type `0x0069bff0` | head item plus interior `bounds` label; exact physical range known | Set `EPFTileContext[2]` only if bounded topology can be normalized safely; readback exactly `[0x69bff0,0x69c040)`. |
| IDA-A16 | comment `0x0069bf98` | no authoritative array comment | Regular: `Function-local static target-port EPFTileContext[2] used by SnowingLayerPane::DrawOnTarget; guard at 0x69bfe8.` |
| IDA-A17 | comment `0x0069bff0` | stale single-context naming | Regular: `Function-local static main-view EPFTileContext[2] used by SnowingLayerPane::OnPaint; guard at 0x69c040.` |

For A14/A15, inability to normalize overlapping items safely does not invalidate the resolved source type; it means the data mutation itself must fail closed while ordinary documentation is still corrected. No action may undefine unrelated data outside the exact array ranges.

## First-Draft C++ Recommendation

The following is the formal CPP recommendation for exact method children. It is intentionally human-written C++03 shape and keeps the binary-sensitive call order. UID0001OO continues to own the six static byte arrays and UID0003O0 continues to own the constructor.

```cpp
void SnowingLayerPane::OnPaint()
{
    static EPFTileContext snowTiles[2];

    snowTiles[0].pixelData = s_snowPatterns[0];
    snowTiles[0].rowStridePixels = 4;
    InitRectBounds(&snowTiles[0].bounds, 0, 0, 4, 4);
    snowTiles[1].pixelData = s_snowPatterns[1];
    snowTiles[1].rowStridePixels = 3;
    InitRectBounds(&snowTiles[1].bounds, 0, 0, 3, 3);

    SetDrawColor(0);
    g_pfnFillRect(this, &m_visibleBounds);
    if (g_activeMapPane->m_waitingForLocalPlayerStatus)
        return;

    int i;
    for (i = 0; i < 200; ++i) {
        const int dy = 25 * rand() / RAND_MAX;
        const int dx = 8 * rand() / RAND_MAX - 4;
        NexusTK_OffsetRect(&m_snowParticles[i].bounds, dx, dy);
    }

    if (m_currentFrame == 0) {
        memmove(&m_snowParticles[20], &m_snowParticles[0],
                180 * sizeof(SnowParticleEntry));

        const int width = m_weatherBounds.right - m_weatherBounds.left;
        const int bandHeight =
            (m_weatherBounds.bottom - m_weatherBounds.top) / 10;

        for (i = 0; i < 20; ++i) {
            SnowParticleEntry &particle = m_snowParticles[i];
            particle.bounds.left = width * rand() / RAND_MAX;
            particle.bounds.top = bandHeight * rand() / RAND_MAX - bandHeight;

            const unsigned int roll = 100 * rand() / RAND_MAX;
            unsigned char type;
            for (type = 0; type < 2; ++type) {
                if (s_snowTypeThresholds[type] <= roll &&
                    roll < s_snowTypeThresholds[type + 1])
                    particle.type = type;
            }

            const int size = s_snowSizes[particle.type];
            particle.bounds.right = particle.bounds.left + size;
            particle.bounds.bottom = particle.bounds.top + size;
        }
    }

    for (i = 0; i < 200; ++i) {
        const SnowParticleEntry &particle = m_snowParticles[i];
        const EPFTileContext &tile = snowTiles[particle.type];
        g_pfnBlitSprite(this, &tile, &tile.bounds, &particle.bounds,
                       0, NULL, NULL);
    }
}

void SnowingLayerPane::OnFrameChanged()
{
    if (g_activeMapPane->m_waitingForLocalPlayerStatus)
        return;

    int i;
    for (i = 0; i < 200; ++i) {
        const int dy = 25 * rand() / RAND_MAX;
        const int dx = 8 * rand() / RAND_MAX - 4;
        NexusTK_OffsetRect(&m_snowParticles[i].bounds, dx, dy);
    }

    if (m_currentFrame == 0) {
        memmove(&m_snowParticles[20], &m_snowParticles[0],
                180 * sizeof(SnowParticleEntry));

        const int width = m_weatherBounds.right - m_weatherBounds.left;
        const int bandHeight =
            (m_weatherBounds.bottom - m_weatherBounds.top) / 10;

        for (i = 0; i < 20; ++i) {
            SnowParticleEntry &particle = m_snowParticles[i];
            particle.bounds.left = width * rand() / RAND_MAX;
            particle.bounds.top = bandHeight * rand() / RAND_MAX - bandHeight;

            const unsigned int roll = 100 * rand() / RAND_MAX;
            unsigned char type;
            for (type = 0; type < 2; ++type) {
                if (s_targetSnowTypeThresholds[type] <= roll &&
                    roll < s_targetSnowTypeThresholds[type + 1])
                    particle.type = type;
            }

            const int size = s_targetSnowSizes[particle.type];
            particle.bounds.right = particle.bounds.left + size;
            particle.bounds.bottom = particle.bounds.top + size;
        }
    }
}

void SnowingLayerPane::DrawOnTarget(GrafPort *target,
                                    const RectBounds *,
                                    const RectBounds *)
{
    static EPFTileContext snowTiles[2];

    snowTiles[0].pixelData = s_targetSnowPatterns[0];
    snowTiles[0].rowStridePixels = 4;
    InitRectBounds(&snowTiles[0].bounds, 0, 0, 4, 4);
    snowTiles[1].pixelData = s_targetSnowPatterns[1];
    snowTiles[1].rowStridePixels = 3;
    InitRectBounds(&snowTiles[1].bounds, 0, 0, 3, 3);

    if (g_activeMapPane->m_waitingForLocalPlayerStatus)
        return;

    for (int i = 0; i < 200; ++i) {
        const SnowParticleEntry &particle = m_snowParticles[i];
        const EPFTileContext &tile = snowTiles[particle.type];
        g_pfnBlitSprite(target, &tile, &tile.bounds, &particle.bounds,
                       0, NULL, NULL);
    }
}
```

The exact formal H recommendation for [UID:0000DC] is:

```cpp
class SnowingLayerPane : public WeatherLayerPane
{
public:
    SnowingLayerPane();
    virtual void DrawOnTarget(GrafPort *target,
                              const RectBounds *sourceBounds,
                              const RectBounds *targetBounds);
    virtual void OnPaint();

protected:
    virtual void OnFrameChanged();

private:
    SnowParticleEntry m_snowParticles[200];
};
```

[UID:0000NR], [UID:0001Q4], [UID:0002Z9], [UID:0003O4], and the new thunk child require blank formal CPP/H or a comment-only covered-by marker, not duplicate source.

## Final Recommendation

Gate 1 should accept this report only if the whole-file route, exact source channels, compiler exclusions, support changes, coverage payloads, and IDA handoff are all retained. After acceptance, B005 should implement the ordinary rows only. The supervisor should independently verify every row, apply manual coverage, perform any safe IDA actions, validate execution eligibility, and own report execution/lifecycle.

## Recommended Target Doc Changes

- Rewrite [UID:0000NR] active status/source placement as a resolved combined-route decision while preserving historical standalone evidence.
- Raise [UID:0000NR] to `94/94` and make its complete inventory/exclusions explicit.
- Correct [UID:0000DC] to `94/95` and replace H declarations.
- Raise O1/O2/O3 to `94/95` with exact complete formal CPP.
- Reclassify O4 to `94/96`, `RECONSTRUCTABLE:FALSE`, blank emitter/formal.

## Recommended Support Doc Changes

- UID0001Q4: `94/95`, owner/emitter `0000P8`, covered-by O1/O3, exact EPFTileContext arrays/guards.
- UID0001WJ: `94/95`, retain owner/emitter `0000P8`, remove active SnowPatternDescriptor hypothesis.
- UID0002Z9: `93/95`, exact method/thunk identities, marker-only.
- UID0001O0/UID0001O1: synchronize indexes and new thunk child without broad emission.
- UID0000P8 and proposed source tree: record the selected route and complete Snow source order.
- Create exact non-emitting thunk child `[0x005c29ec,0x005c2a02)`.

## Score And Metadata Recommendation

| UID | Current | Recommended | Metadata disposition |
| --- | ---: | ---: | --- |
| `0000NR` | `90/89` | `94/94` | Keep `FILE`, `NexusTK/map/`; no emitter. |
| `0000DC` | `91/93` | `94/95` | Keep owner/emitter `0000P8`, position 30, reconstructable true. |
| `0003O1` | `88/89` | `94/95` | Keep owner/emitter `0000DC`, formal CPP exact. |
| `0003O2` | `89/91` | `94/95` | Keep owner/emitter `0000DC`, formal CPP exact. |
| `0003O3` | `88/89` | `94/95` | Keep owner/emitter `0000DC`, formal CPP exact. |
| `0003O4` | `85/88` | `94/96` | Owner `0000DC`; set reconstructable false; blank emitter/formal. |
| `0001Q4` | `86/90` | `94/95` | Owner/emitter `0000P8`; marker-only covered-by O1/O3. |
| `0001WJ` | `93/94` | `94/95` | Keep owner/emitter `0000P8`; exact EPFTileContext closure. |
| `0002Z9` | `88/92` | `93/95` | Keep class ownership and marker-only compiler data. |

Scores remain below `95` completion for authored emitters until generated code is compiled/audited against exact runtime behavior. O4 confidence `96` is justified because its non-source compiler disposition and body semantics are exact.

## Open Questions With Attempted Resolution

- **Original physical filename:** searched source/PDB-like strings and reconciled all physical/code/data/header evidence. Exact historical spelling remains unknowable, but the current source route is resolved at high probability to WeatherLayerPane.cpp/.h and no longer blocks source.
- **Private lexical names:** no symbols survive. `snowTiles`, `m_snowParticles`, and accepted shared interface names are the highest-probability human forms. This does not justify raw names.
- **Unused DrawOnTarget bounds names:** sibling/base declarations establish their types and semantic positions; this body does not read them. Header names follow the shared contract while the definition omits names.
- **Local-static IDA topology:** source type is resolved. Persistent IDA data typing remains conditional on exact bounded overlap safety; a failed data mutation must not undo the ordinary-document correction.
- **Exact original use of `RAND_MAX` versus `0x7fff`:** the target CRT uses the conventional 15-bit `rand`; `RAND_MAX` is the normal human source spelling and preserves the constant in this toolchain.

No open question remains that justifies blank O1/O2/O3 source, stale helper names, or unresolved source placement.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Replace the current by-file row with:

`- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md) : reconstructable : 94% : very-strong : Exhaustive Snowing whole-file research selects the combined WeatherLayerPane.cpp/.h route from contiguous code, RTTI/vtables, writable snow tables, shared layout dependencies, and MapPane construction; exact OnPaint, OnFrameChanged, DrawOnTarget, EPFTileContext local statics, compiler destructor/thunks, exclusions, and rejected standalone-file history are documented without duplicate emission.`

Replace the current by-class row with:

`- [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) : reconstructable : 94% : very-strong : Exact 0x10ac Weather-derived Snow class with 200 SnowParticleEntry records, source-ready constructor, OnPaint, OnFrameChanged, DrawOnTarget, correct shared callbacks and EPFTileContext local statics, compiler-only destructor machinery, and canonical combined WeatherLayerPane.cpp/.h ownership.`

Under the UID0001O0 subtree, insert or replace:

`        - [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md) 0x005c1c80-0x005c1f4c | virtual method | SnowingLayerPaneOnPaint : reconstructable : 94% : very-strong : Exact SnowingLayerPane::OnPaint body with main-view EPFTileContext[2] local statics, fill-before-gate behavior, direct waiting-status gate, binary-ordered rand calls, 200-entry drift, frame-zero 180-record shift and 20-record refill, and 200 exact g_pfnBlitSprite calls.`

`        - [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) 0x005c1f50-0x005c20d4 | virtual method | SnowingLayerPaneOnFrameChanged : reconstructable : 94% : very-strong : Exact SnowingLayerPane::OnFrameChanged override with direct waiting-status gate, binary-ordered 200-entry drift, frame-zero 180-record shift, 20-entry target-table refill, exact unsigned threshold/size semantics, and complete formal C++ through the Snow class.`

`        - [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md) 0x005c20e0-0x005c2228 | virtual method | SnowingLayerPaneDrawOnTarget : reconstructable : 94% : very-strong : Exact three-stack-argument DrawOnTarget override using the supplied GrafPort, target EPFTileContext[2] local statics, direct waiting-status gate, 200 particle records, and exact g_pfnBlitSprite dispatch; the two RectBounds parameters are contractually present and unused.`

`        - [UID:0003O4][0x005c2a20-0x005c2a5b.SnowingLayerPaneScalarDeletingDestructor](by-memory/0x005c2a20-0x005c2a5b.SnowingLayerPaneScalarDeletingDestructor.md) 0x005c2a20-0x005c2a5b | compiler deleting wrapper | SnowingLayerPaneScalarDeletingDestructor : not_reconstructable : 94% : near-certain : Exact MSVC scalar deleting destructor wrapper with base destruction, deleting-flag behavior, 0x10ac object-size guard path, vtable route, and blank source/emitter disposition because no authored destructor body exists.`

`        - [UID:NEW][0x005c29ec-0x005c2a02.SnowingLayerPaneDestructorAdjustorThunks](by-memory/0x005c29ec-0x005c2a02.SnowingLayerPaneDestructorAdjustorThunks.md) 0x005c29ec-0x005c2a02 | compiler adjustor thunks | SnowingLayerPaneDestructorAdjustorThunks : not_reconstructable : 94% : near-certain : Exact EventHandler this-0xa0 and TimerHandler this-0xa4 scalar-deleting-destructor tail thunks, documented for vtable ownership with blank emitter and no authored C++.`

Replace the current UID0001Q4 row with:

`    - [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) 0x0069bf98-0x0069c044 | function-local static EPFTileContext storage | SnowLookupDescriptorStorage : reconstructable : 94% : very-strong : Exact target/main EPFTileContext[2] arrays, two local-static guards, one four-byte alignment gap, constructor/layout identity, exclusive OnPaint/DrawOnTarget consumers, canonical WeatherLayerPane route, and covered-by marker disposition with no standalone data C++.`

Replace the current UID0002Z9 row with:

`        - [UID:0002Z9][0x006312ac-0x0063133c.SnowingLayerPaneVtableData](by-memory/0x006312ac-0x0063133c.SnowingLayerPaneVtableData.md) 0x006312ac-0x0063133c | vtable-data | SnowingLayerPaneVtableData : reconstructable : 93% : very-strong : Exact primary/EventHandler/TimerHandler Snow vtable views with OnPaint, OnFrameChanged, DrawOnTarget, scalar deleting destructor, two adjusted destructor thunks, inherited Weather timer, exact class ownership, and source-declared/compiler-generated marker-only disposition.`

The `[UID:NEW]` token is a supervisor placeholder: the validator must allocate the real UID when the new ordinary page is created. Do not manually edit generated research tracker rows; the tracker refresh belongs to validator execution.

## Follow-Up Actions

1. Supervisor performs fresh Gate 1 against the exact report artifact.
2. On acceptance, B005 receives an ordinary callback for B005 rows only and updates full detail without touching manual coverage or IDA.
3. Supervisor verifies ordinary implementation claim by claim and applies exact manual coverage payloads.
4. Supervisor evaluates and applies only safe Section 21 IDA actions with fresh runtime/current-prestate evidence.
5. Supervisor runs lifecycle execution only after Gate 2A/2B and exact report mechanics pass.

## Confidence

Confidence is very strong for behavior, ranges, ownership, class layout, vtable identities, callback/type selection, static storage, and active route. Historical filename spelling and private lexical spellings remain inferred, but the report supplies ranked high-probability human source rather than exposing decompiler labels. The combined route is sufficiently supported to stop treating file placement as an active blocker.

## Validator Results

No validator was run in report-only research, as required. Proposed callback validators are one scoped file validation per changed ordinary by-* page using the documented command from `source-3/project-documentation`. Manual coverage and generated tracker updates remain supervisor/validator-owned. Generated output must be physically reread against the command metadata returned by the callback validators.

## Changed Files

- Created only `tools/leaser/Agents/Agent-B005/research/0000NR-SnowingLayerPane-file-source-quality.md`.
- No ordinary by-* file, manual coverage, generated/tracker/audit/lifecycle file, goal, registry, or IDA database was changed.

## Implementation Tracking Checklist

| ID | Actor | Action | Destination | Required content | Verification | Done |
| --- | --- | --- | --- | --- | --- | --- |
| C0000NR-001 | B005 | incorporate | `by-file/SnowingLayerPane.md` | Resolve shared Weather source route as current and preserve standalone Snowing only as a ranked historical alternative. | Physical code/data/vtable clustering and negative filename evidence are recorded. | [ ] |
| C0000NR-002 | B005 | incorporate | `by-file/SnowingLayerPane.md` | Replace representative method list with exhaustive authored/compiler/data inventory and exact source order. | Every row in Section 14 has a destination. | [ ] |
| C0000NR-003 | B005 | historicalize | `by-file/SnowingLayerPane.md` | Historicalize unresolved standalone-vs-shared wording without deleting prior evidence. | Active status no longer treats routes as equal. | [ ] |
| C0000NR-004 | B005 | incorporate | `by-file/WeatherLayerPane.md` | Add Snow whole-file closure, selected route evidence, and exact current Snow child identities. | Shared root names O1/O2/O3 correctly. | [ ] |
| C0000NR-005 | B005 | incorporate | `by-class/SnowingLayerPane.md` | Raise to `94/95`; correct class method inventory and compiler-only destructor disposition. | Metadata and prose agree. | [ ] |
| C0000NR-006 | B005 | incorporate | `by-class/SnowingLayerPane.md` formal H | Replace wrong declarations with `OnPaint`, `OnFrameChanged`, and exact `DrawOnTarget` signature; omit explicit destructor. | Generated H contains exact declaration once. | [ ] |
| C0000NR-007 | B005 | incorporate | UID0003O1 | Rename role to `OnPaint`, document exact flow, helpers, fields, random order, and local-static EPFTileContext family. | Target metadata/prose/formal agree at `94/95`. | [ ] |
| C0000NR-008 | B005 | incorporate | UID0003O1 formal CPP | Install exact human C++03 `SnowingLayerPane::OnPaint()` body from Section 22. | Generated CPP has no stale wrappers/null gate. | [ ] |
| C0000NR-009 | B005 | incorporate | UID0003O2 | Close operation order, table use, frame gate, rolling shift, and source route at `94/95`. | Body evidence and score rationale agree. | [ ] |
| C0000NR-010 | B005 | incorporate | UID0003O2 formal CPP | Install exact `SnowingLayerPane::OnFrameChanged()` body from Section 22. | Generated CPP contains a complete nonstub body. | [ ] |
| C0000NR-011 | B005 | incorporate | UID0003O3 | Rename role to exact `DrawOnTarget`, document target use and two ignored bounds arguments. | Metadata/prose/formal agree at `94/95`. | [ ] |
| C0000NR-012 | B005 | incorporate | UID0003O3 formal CPP | Install exact `DrawOnTarget` body using the supplied target and EPFTileContext. | Generated CPP uses target as callback receiver. | [ ] |
| C0000NR-013 | B005 | incorporate | UID0003O4 | Reclassify scalar deleting wrapper to `94/96`, class owner, `RECONSTRUCTABLE:FALSE`, blank emitter/CPP/H. | No handwritten destructor emits. | [ ] |
| C0000NR-014 | B005 | incorporate | new exact thunk page | Create `[0x005c29ec,0x005c2a02)` Snow destructor adjustor-thunk child, compiler-only and non-emitting. | Both thunk starts and offsets are documented. | [ ] |
| C0000NR-015 | B005 | incorporate | UID0001Q4 | Replace SnowPatternDescriptor with exact EPFTileContext[2] families and guards; reroute owner/emitter to `0000P8`. | Storage remains covered-by and marker-only. | [ ] |
| C0000NR-016 | B005 | incorporate | UID0001WJ | Historicalize SnowPatternDescriptor hypothesis and document exact EPFTileContext identity. | No duplicate descriptor type remains active. | [ ] |
| C0000NR-017 | B005 | incorporate | UID0002Z9 | Synchronize exact OnPaint/OnFrameChanged/DrawOnTarget/dtor/thunk vtable identities and score `93/95`. | All seven relevant cells match Section 13. | [ ] |
| C0000NR-018 | B005 | incorporate | UID0001O0 | Update non-emitting index inventory with exact method names and new thunk child. | Index emits no broad code. | [ ] |
| C0000NR-019 | B005 | incorporate | UID0001O1 | Update mixed-island index and preserve Snow/Swallow boundary/exclusions. | No owner bleed across `0x5c2230`. | [ ] |
| C0000NR-020 | B005 | already-present | UID0003O0 | Preserve exact constructor `92/94`, body, object layout, and current Weather route. | No constructor regression. | [ ] |
| C0000NR-021 | B005 | already-present | UID0001OO | Preserve six mutable arrays, values, hashes, owner `0000P8`, and emitter position 1. | No duplicate array formal. | [ ] |
| C0000NR-022 | B005 | incorporate | UID0000TP / callback support | Replace provisional Snow wrapper aliases with accepted Surface callback identities where Snow is discussed. | Existing callback ownership remains unchanged. | [ ] |
| C0000NR-023 | B005 | incorporate | MapPane support | Record selector/allocation/caller route as Snow construction evidence without transferring ownership. | `0x50dc17` and `0x10ac` remain exact. | [ ] |
| C0000NR-024 | B005 | incorporate | proposed source tree | Mark Snowing as class content in WeatherLayerPane CPP/H; retain dedicated file only as historical candidate. | Tree has one active source route. | [ ] |
| C0000NR-025 | B005 | incorporate | target/support Item Summaries | Preserve concise exact current roles after detailed prose is added. | Validator does not erase valid summaries. | [ ] |
| C0000NR-026 | B005 | incorporate | changed ordinary pages | Run one scoped validator per changed by-* page after callback. | Each command exits 0 with `ok:1`. | [ ] |
| C0000NR-027 | B005 | incorporate | generated WeatherLayerPane CPP/H | Physically reread current command metadata and all Snow declarations/bodies after validation. | No empty marker, stale method, or duplicate source remains. | [ ] |
| C0000NR-028 | B005 | incorporate | generated SnowingLayerPane.cpp | Confirm historical route stays marker-only and does not duplicate Weather output. | Generated file contains no authored Snow body. | [ ] |
| C0000NR-029 | B005 | incorporate | report callback receipts | Check only completed ordinary rows after physical reread and preserve exact evidence. | Ledger/checklist twins remain exact. | [ ] |
| C0000NR-030 | Supervisor | incorporate | `by-file/-coverage-report.md` | Apply exact UID0000NR replacement in Section 28. | Current row is `94% : very-strong`. | [ ] |
| C0000NR-031 | Supervisor | incorporate | `by-class/-coverage-report.md` | Apply exact UID0000DC replacement in Section 28. | Current row is `94% : very-strong`. | [ ] |
| C0000NR-032 | Supervisor | incorporate | `by-memory/-coverage-report.md` | Insert/replace exact UID0003O1/O2/O3/O4 rows from Section 28. | Four rows match target metadata. | [ ] |
| C0000NR-033 | Supervisor | incorporate | `by-memory/-coverage-report.md` | Replace exact UID0001Q4 and UID0002Z9 rows from Section 28. | Rows match current routing/scores. | [ ] |
| C0000NR-034 | Supervisor | incorporate | `by-memory/-coverage-report.md` | Insert exact new thunk-child row after UID0003O4. | Compiler-only child is represented once. | [ ] |
| C0000NR-035 | Supervisor | incorporate | IDA-A01 | Rename `0x005c1c80` to `SnowingLayerPane__OnPaint` after exact prestate/collision proof. | Exact desired registration and address readback. | [ ] |
| C0000NR-036 | Supervisor | incorporate | IDA-A02 | Set exact `void __thiscall SnowingLayerPane__OnPaint(SnowingLayerPane *this)` type. | Type/readback and bytes/xrefs unchanged. | [ ] |
| C0000NR-037 | Supervisor | incorporate | IDA-A03 | Set concise OnPaint behavior comment. | Exact comment readback. | [ ] |
| C0000NR-038 | Supervisor | incorporate | IDA-A04 | Rename `0x005c20e0` to `SnowingLayerPane__DrawOnTarget`. | Exact desired registration and address readback. | [ ] |
| C0000NR-039 | Supervisor | incorporate | IDA-A05 | Set exact DrawOnTarget `__thiscall` type with three stack arguments. | Stack cleanup and type readback agree. | [ ] |
| C0000NR-040 | Supervisor | incorporate | IDA-A06 | Set concise DrawOnTarget behavior comment. | Exact comment readback. | [ ] |
| C0000NR-041 | Supervisor | incorporate | IDA-A07 | Rename `0x005c2a20` to `SnowingLayerPane__ScalarDeletingDestructor`. | Exact desired registration and address readback. | [ ] |
| C0000NR-042 | Supervisor | incorporate | IDA-A08 | Set exact deleting-wrapper type with unsigned flags. | Type/readback and body unchanged. | [ ] |
| C0000NR-043 | Supervisor | incorporate | IDA-A09 | Set compiler-only deleting-wrapper comment. | Exact comment readback. | [ ] |
| C0000NR-044 | Supervisor | incorporate | IDA-A10 | Rename `0x005c29ec` to EventHandler adjusted deleting-destructor thunk name. | Desired registration at exact address. | [ ] |
| C0000NR-045 | Supervisor | incorporate | IDA-A11 | Replace stale thunk comment with exact `this-0xa0` tail-forward role. | Exact comment readback. | [ ] |
| C0000NR-046 | Supervisor | incorporate | IDA-A12 | Rename `0x005c29f7` to TimerHandler adjusted deleting-destructor thunk name. | Desired registration at exact address. | [ ] |
| C0000NR-047 | Supervisor | incorporate | IDA-A13 | Replace stale thunk comment with exact `this-0xa4` tail-forward role. | Exact comment readback. | [ ] |
| C0000NR-048 | Supervisor | incorporate | IDA-A14 | Set `0x0069bf98` to exact `EPFTileContext[2]` only after bounded item-boundary precheck. | Array extent ends at `0x69bfe8`. | [ ] |
| C0000NR-049 | Supervisor | incorporate | IDA-A15 | Set `0x0069bff0` to exact `EPFTileContext[2]` only after bounded item-boundary precheck. | Array extent ends at `0x69c040`. | [ ] |
| C0000NR-050 | Supervisor | incorporate | IDA-A16 | Set target-context regular comment at `0x0069bf98`. | Exact comment/readback, no boundary drift. | [ ] |
| C0000NR-051 | Supervisor | incorporate | IDA-A17 | Set main-context regular comment at `0x0069bff0`. | Exact comment/readback, no boundary drift. | [ ] |

Checklist allocation is exactly 29 B005 rows and 22 supervisor rows; all 51 remain unchecked in this report-only artifact.

READY_FOR_SUPERVISOR_EXECUTE
