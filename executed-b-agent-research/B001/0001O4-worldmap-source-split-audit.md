** TARGET-REPORT-UID:0001O4 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 WorldMapPane Source-Split Audit

Assignment: `B001-goal2-memory-tool-worldmap-source-split-0001O4-20260616`  
Target: [UID:0001O4] `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md`

## Current State Checked

- Target metadata is `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000PB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PB`, with blank final C++.
- Current shared row says the range is a reconstructable `WorldMapPane` executable aggregate attached to [UID:0000PB] `WorldMapPane.cpp`.
- Support pages checked:
  - [UID:0000PB] `by-file/WorldMapPane.md`: `90/86`, proposed `NexusTK/map/WorldMapPane.cpp`, with private `WorldMapNodeEntryVector` and `WorldMapReachabilityBitSet`.
  - [UID:0000G9] `by-class/WorldMapPane.md`: `86/88`, source owner [UID:0000PB].
  - [UID:0000G8] `by-class/WorldMapNodeEntryVector.md`: `84/88`, below the child-owner completion gate only because exact executable children are missing.
  - [UID:0000GA] `by-class/WorldMapReachabilityBitSet.md`: `84/88`, below the child-owner completion gate only because exact executable children are missing.
  - [UID:000271] `WorldMapReadOnlyData` and exact vtable/resource/constant children [UID:00035H]-[UID:00035J].
  - [UID:00029E] `g_pWorldMapPane`, current singleton lifecycle evidence.
  - [UID:0003IZ] `VectorBoolTooLongRuntimeString`, exact non-reconstructable STL diagnostic string referenced by `0x005c58b0`.
- Existing by-memory children inside `0x005c2ac0-0x005c5c87`: none. The current page is still one large executable leaf in the refreshed memory tool report.

## Final Recommendation

Reclassify [UID:0001O4] from a reconstructable emitter to a non-emitting source-family split index after creating exact child pages for every modeled function or compiler/runtime helper in the span.

Recommended target metadata after children exist:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000PB
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE: blank
```

Reason: this physical range is not one source-emittable unit. It mixes `WorldMapPane` methods, private node-entry vector helpers, private reachability-bitset helpers, singleton cleanup/compiler glue, destructor adjustor thunks, and an STL `vector<bool>` throw helper. Source ownership is still strongly [UID:0000PB] `WorldMapPane.cpp` for the source-bearing methods, but the aggregate itself should become the migration index and stop emitting.

No final C++ should be added. The split gives source-quality placement, but final method names, packet field names, and private helper original type names still fall below the active code-entry bar.

## Evidence Checked

### Live IDA/MCP

Live IDA function inventory for `0x005c2ac0-0x005c5c87` reports 37 function starts and the successor import thunk at `0x005c5c87`:

```text
0x005c2ac0-0x005c32aa sub_5C2AC0
0x005c32b0-0x005c341e sub_5C32B0
0x005c3420-0x005c346d sub_5C3420
0x005c34c0-0x005c3508 sub_5C34C0
0x005c3540-0x005c3627 sub_5C3540
0x005c3630-0x005c36c8 sub_5C3630
0x005c36d0-0x005c37d6 sub_5C36D0
0x005c37e0-0x005c38fd sub_5C37E0
0x005c3950-0x005c3e41 sub_5C3950
0x005c3e50-0x005c402b sub_5C3E50
0x005c40c0-0x005c4245 sub_5C40C0
0x005c4250-0x005c46e9 sub_5C4250
0x005c46f0-0x005c4733 sub_5C46F0
0x005c4740-0x005c484b sub_5C4740
0x005c48b0-0x005c4bd0 sub_5C48B0
0x005c4bd0-0x005c5075 sub_5C4BD0
0x005c5080-0x005c50e6 sub_5C5080
0x005c50f0-0x005c5156 sub_5C50F0
0x005c5160-0x005c519c sub_5C5160
0x005c51a0-0x005c51fb sub_5C51A0
0x005c5200-0x005c53d0 sub_5C5200
0x005c53d0-0x005c54f3 sub_5C53D0
0x005c5500-0x005c550b sub_5C5500
0x005c5510-0x005c557a sub_5C5510
0x005c5580-0x005c55d7 sub_5C5580
0x005c55e0-0x005c563c sub_5C55E0
0x005c563c-0x005c5647 sub_5C563C
0x005c5647-0x005c5652 sub_5C5647
0x005c5652-0x005c565d sub_5C5652
0x005c5660-0x005c569b sub_5C5660
0x005c56a0-0x005c584b sub_5C56A0
0x005c5850-0x005c58a9 sub_5C5850
0x005c58b0-0x005c58ba sub_5C58B0
0x005c58c0-0x005c5a8f sub_5C58C0
0x005c5a90-0x005c5aca sub_5C5A90
0x005c5ad0-0x005c5b18 sub_5C5AD0
0x005c5b20-0x005c5c87 sub_5C5B20
0x005c5c87 DirectDrawCreate
```

Representative behavior checked by decompilation:

- `0x005c2ac0` constructs the pane, stores WorldMap vtables, writes `g_pWorldMapPane`, initializes node-vector and bitset state, calls `0x005c58c0`, `0x005c4bd0`, and `0x005c4740`.
- `0x005c32b0` is the non-deleting destructor body; it restores/destructs subobjects, clears `g_pWorldMapPane`, and calls node-vector cleanup `0x005c5510`.
- `0x005c3420`, `0x005c34c0`, `0x005c3540`, `0x005c3630`, `0x005c36d0`, `0x005c37e0`, and `0x005c4740` are view/navigation/hit-test helpers.
- `0x005c3950` is the draw path and calls clip setup `0x005c36d0` and marker draw `0x005c48b0`.
- `0x005c3e50`, `0x005c40c0`, `0x005c4250`, and `0x005c46f0` are key/mouse/frame/timer handlers.
- `0x005c4bd0` builds reachability and calls bitset helpers at `0x005c5b20` and `0x005c56a0`.
- `0x005c5510`, `0x005c58c0`, and `0x005c5a90` are the private 0x94-byte node-entry vector destructor/assign/free helpers.
- `0x005c53d0`, `0x005c5580`, `0x005c55e0`, `0x005c56a0`, `0x005c5850`, `0x005c5ad0`, and `0x005c5b20` are the private reachability-bitset reserve/iterator/insert/shrink/move helpers.
- `0x005c563c`, `0x005c5647`, and `0x005c5652` are 0xb-byte adjustor thunks into scalar deleting destructor `0x005c5660`.
- `0x005c58b0` calls the runtime/STL throw path with [UID:0003IZ] `vector<bool> too long`.

Xrefs checked:

- Constructor `0x005c2ac0` has callers at `0x0050f2fa` and `0x005126f9`; these remain creation routes, not ownership routes into `MapPane.cpp`.
- Vtable-only method slots point to `0x005c3950`, `0x005c3e50`, `0x005c40c0`, `0x005c4250`, `0x005c46f0`, `0x005c563c`, `0x005c5647`, `0x005c5652`, and `0x005c5660`.
- Internal helper xrefs match the split model: `0x005c4bd0 -> 0x005c56a0/0x005c5b20`, `0x005c56a0 -> 0x005c53d0/0x005c5580/0x005c5ad0`, `0x005c5b20 -> 0x005c55e0/0x005c5850`, `0x005c58c0 -> 0x005c5a90`.
- Singleton helper `0x005c5500` has a jump xref from SEH/cleanup funclet code and writes [UID:00029E] `g_pWorldMapPane`; it is not a normal source method.

### Local PE Scan

Local scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirmed:

- Image base `0x00400000`.
- `.text` raw map: rva `0x1000`, raw `0x400`, size `0x20b600`.
- No RVA dword hits for any WorldMap function start.
- Absolute dword hits occur only where expected for vtable slots:
  - `0x00631444 -> 0x005c3950`
  - `0x00631454 -> 0x005c3e50`
  - `0x00631450 -> 0x005c40c0`
  - `0x0063148c -> 0x005c4250`
  - `0x00631480 -> 0x005c46f0`
  - `0x0063144c -> 0x005c563c`
  - `0x0063147c -> 0x005c5647`
  - `0x00631488 -> 0x005c5652`
  - `0x00631400 -> 0x005c5660`
- Relative call/jump hits match IDA xrefs. The successor `0x005c5c87` has only external import-thunk callers at `0x00463ca8`, `0x004670ef`, and `0x004a1bcb`, confirming it is not part of the WorldMap source span.

This resolves the boundary/reachability question: the range is fully modeled code, but it is structurally mixed and should not remain one source-emitting page.

## Source-Placement Decisions

| Question | Decision | Evidence and reason |
| --- | --- | --- |
| One source-emitting aggregate? | No. | The span mixes main `WorldMapPane` methods, two private helper classes, adjustor thunks, singleton cleanup glue, and STL support. One C++ block would either duplicate compiler output or obscure source owners. |
| Direct owner [UID:0000PB] `WorldMapPane.cpp`? | Yes, for the split index and all source-bearing children. | Proposed source tree, by-file page, constructor/draw/input/reachability evidence, read-only-data ownership, and singleton lifecycle all route to `map/WorldMapPane.cpp`. |
| Should `MapPane` own this because it calls the constructor? | No. | `MapPane` creates/shows the world-map UI, but vtables, resources, singleton, methods, and private helper classes belong to `WorldMapPane`. Constructor callers are creation routes, not implementation ownership. |
| Should private helper classes emit through separate files? | No current evidence. | `WorldMapNodeEntryVector` and `WorldMapReachabilityBitSet` are tightly local to `WorldMapPane`, lack independent source/path evidence, and the by-file page already models them as private helpers in `WorldMapPane.cpp`. |
| Should `0x005c5500` be source-emitting? | No. | It is a compact clear helper reached from SEH/cleanup funclet code and only clears the singleton. Source-level lifecycle belongs in constructor/destructor cleanup, not a handwritten standalone method. |
| Should adjustor thunks be reconstructable? | No. | Three 0xb-byte ABI thunks adjust `this` by `-0xa0`, `-0xa4`, and `-0xf8`, then jump to scalar deleting destructor. This matches existing non-emitting adjustor-thunk precedent. |
| Should `0x005c58b0` be WorldMap source? | No. | The body is the STL/vector too-long throw helper and references [UID:0003IZ] `vector<bool> too long`, already documented as non-reconstructable runtime support. It is physically pulled into the WorldMap bitset neighborhood but should not emit handwritten NexusTK source. |
| IDA DB repair? | No. | IDA already has all function starts and boundaries in this span. Names are still descriptive rather than proven original names, so no safe DB rename is recommended. |

## Exact Child Split Recommendation

Use allocated real UIDs in place of `NEW-O4-*`. All reconstruction C++ blocks should remain blank.

| Placeholder | Range | File name | Owner | Reconstructable | Score | Evidence summary |
| --- | --- | --- | --- | --- | --- | --- |
| `NEW-O4-01` | `0x005c2ac0-0x005c32aa` | `0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md` | `0000G9`, emitter `0000PB` | TRUE | `86/90` | Constructor, vtable stores, singleton publish/clear, resource loads, node vector assign, reachability build. |
| `NEW-O4-02` | `0x005c32b0-0x005c341e` | `0x005c32b0-0x005c341e.WorldMapPaneNonDeletingDestructor.md` | `0000G9`, emitter `0000PB` | TRUE | `86/90` | Destructor body, singleton clear, helper cleanup, scalar destructor caller. |
| `NEW-O4-03` | `0x005c3420-0x005c346d` | `0x005c3420-0x005c346d.WorldMapPaneSetViewPosition.md` | `0000G9`, emitter `0000PB` | TRUE | `85/89` | Sets viewport fields, clamps through `0x005c4740`, invalidates/redraws. |
| `NEW-O4-04` | `0x005c34c0-0x005c3508` | `0x005c34c0-0x005c3508.WorldMapPaneStartViewAnimation.md` | `0000G9`, emitter `0000PB` | TRUE | `85/89` | Sets target view fields, clamps, schedules frame callback. |
| `NEW-O4-05` | `0x005c3540-0x005c3627` | `0x005c3540-0x005c3627.WorldMapPaneStartTravelToNode.md` | `0000G9`, emitter `0000PB` | TRUE | `86/89` | Starts travel/navigation or sends immediately when already at destination. |
| `NEW-O4-06` | `0x005c3630-0x005c36c8` | `0x005c3630-0x005c36c8.WorldMapPaneSendTravelPacket.md` | `0000G9`, emitter `0000PB` | TRUE | `85/89` | Builds compact travel packet from node-entry fields and sends seven bytes. Packet enum name remains blocked. |
| `NEW-O4-07` | `0x005c36d0-0x005c37d6` | `0x005c36d0-0x005c37d6.WorldMapPaneApplyVisibleClipRect.md` | `0000G9`, emitter `0000PB` | TRUE | `85/90` | Applies visible/clip rectangle using screen-mode constants. |
| `NEW-O4-08` | `0x005c37e0-0x005c38fd` | `0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode.md` | `0000G9`, emitter `0000PB` | TRUE | `86/90` | Iterates 0x94-byte node entries and returns hit node index or -1. |
| `NEW-O4-09` | `0x005c3950-0x005c3e41` | `0x005c3950-0x005c3e41.WorldMapPaneOnDraw.md` | `0000G9`, emitter `0000PB` | TRUE | `86/90` | Vtable draw method; renders map, nodes, labels, reachability, player marker. |
| `NEW-O4-10` | `0x005c3e50-0x005c402b` | `0x005c3e50-0x005c402b.WorldMapPaneHandleKeyEvent.md` | `0000G9`, emitter `0000PB` | TRUE | `85/89` | Vtable key handler for enter/space/escape/arrows and navigation helpers. |
| `NEW-O4-11` | `0x005c40c0-0x005c4245` | `0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md` | `0000G9`, emitter `0000PB` | TRUE | `85/89` | Mouse/input handler, hover helpers, set-view and travel calls. |
| `NEW-O4-12` | `0x005c4250-0x005c46e9` | `0x005c4250-0x005c46e9.WorldMapPaneOnFrameUpdate.md` | `0000G9`, emitter `0000PB` | TRUE | `86/89` | Frame animation/travel update; schedules/removes frame callback. |
| `NEW-O4-13` | `0x005c46f0-0x005c4733` | `0x005c46f0-0x005c4733.WorldMapPaneOnTimerTick.md` | `0000G9`, emitter `0000PB` | TRUE | `85/89` | Vtable slot increments marker/timer state and invalidates display. |
| `NEW-O4-14` | `0x005c4740-0x005c484b` | `0x005c4740-0x005c484b.WorldMapPaneClampViewPosition.md` | `0000G9`, emitter `0000PB` | TRUE | `86/90` | Clamps view position to map bounds using mode-specific constants. |
| `NEW-O4-15` | `0x005c48b0-0x005c4bd0` | `0x005c48b0-0x005c4bd0.WorldMapPaneDrawPlayerMarker.md` | `0000G9`, emitter `0000PB` | TRUE | `85/89` | Draws player/boat marker and uses special-region helper. |
| `NEW-O4-16` | `0x005c4bd0-0x005c5075` | `0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md` | `0000G9`, emitter `0000PB` | TRUE | `86/90` | Builds reachability using temporary vectors and bitset helpers. |
| `NEW-O4-17` | `0x005c5080-0x005c50e6` | `0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md` | `0000G9`, emitter `0000PB` | TRUE | `85/88` | Calls mouse-position helper and node hit-test; exact source name unresolved. |
| `NEW-O4-18` | `0x005c50f0-0x005c5156` | `0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md` | `0000G9`, emitter `0000PB` | TRUE | `85/88` | Second hover/update variant; exact distinction from `0x005c5080` unresolved. |
| `NEW-O4-19` | `0x005c5160-0x005c519c` | `0x005c5160-0x005c519c.WorldMapPaneFindPredecessorNode.md` | `0000G9`, emitter `0000PB` | TRUE | `85/88` | Small route/helper used by frame/travel paths; final source name unresolved. |
| `NEW-O4-20` | `0x005c51a0-0x005c51fb` | `0x005c51a0-0x005c51fb.WorldMapPaneScreenPointHelper.md` | `0000G9`, emitter `0000PB` | TRUE | `85/88` | Small point/coordinate helper used by mouse handling; final source name unresolved. |
| `NEW-O4-21` | `0x005c5200-0x005c53d0` | `0x005c5200-0x005c53d0.WorldMapPaneHitTestSpecialRegions.md` | `0000G9`, emitter `0000PB` | TRUE | `86/90` | Special region/name hit-test path; relates to `WM2`/world-map strings and draw helper callers. |
| `NEW-O4-22` | `0x005c53d0-0x005c54f3` | `0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits.md` | `0000GA`, emitter `0000PB` | TRUE | `85/89` | Bitset reserve/grow helper called by insert. |
| `NEW-O4-23` | `0x005c5500-0x005c550b` | `0x005c5500-0x005c550b.WorldMapPaneSingletonClearCleanupThunk.md` | `NONE`, blank emitter | FALSE | `85/90` | Compiler/EH cleanup helper clearing `g_pWorldMapPane`; non-emitting. |
| `NEW-O4-24` | `0x005c5510-0x005c557a` | `0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor.md` | `0000G8`, emitter `0000PB` | TRUE | `86/90` | Node-entry vector destructor and large-allocation free policy. |
| `NEW-O4-25` | `0x005c5580-0x005c55d7` | `0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper.md` | `0000GA`, emitter `0000PB` | TRUE | `85/89` | Bitset iterator/position support helper called by insert. |
| `NEW-O4-26` | `0x005c55e0-0x005c563c` | `0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator.md` | `0000GA`, emitter `0000PB` | TRUE | `85/89` | Bit iterator resolver called by range move. |
| `NEW-O4-27` | `0x005c563c-0x005c565d` | `0x005c563c-0x005c565d.WorldMapPaneAdjustorThunks.md` | `NONE`, blank emitter | FALSE | `86/91` | Three destructor adjustor thunks; ABI glue only. |
| `NEW-O4-28` | `0x005c5660-0x005c569b` | `0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor.md` | `0000G9`, emitter `0000PB` | TRUE | `87/91` | Scalar deleting destructor referenced by primary vtable and adjustor thunks. |
| `NEW-O4-29` | `0x005c56a0-0x005c584b` | `0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits.md` | `0000GA`, emitter `0000PB` | TRUE | `86/90` | Inserts bit runs, grows storage, uses iterator/end helpers and `bts`/`btr`. |
| `NEW-O4-30` | `0x005c5850-0x005c58a9` | `0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount.md` | `0000GA`, emitter `0000PB` | TRUE | `85/89` | Shrink helper called by range move and too-long path. |
| `NEW-O4-31` | `0x005c58b0-0x005c58ba` | `0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0.md` | `NONE`, blank emitter | FALSE | `86/91` | Runtime/STL throw helper for [UID:0003IZ] `vector<bool> too long`; non-emitting. |
| `NEW-O4-32` | `0x005c58c0-0x005c5a8f` | `0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign.md` | `0000G8`, emitter `0000PB` | TRUE | `86/90` | Assign/grow helper for 0x94-byte node entries; two constructor call sites. |
| `NEW-O4-33` | `0x005c5a90-0x005c5aca` | `0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation.md` | `0000G8`, emitter `0000PB` | TRUE | `85/90` | Node-entry vector allocation free helper called by assign. |
| `NEW-O4-34` | `0x005c5ad0-0x005c5b18` | `0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator.md` | `0000GA`, emitter `0000PB` | TRUE | `85/90` | Computes bitset end iterator from bit count. |
| `NEW-O4-35` | `0x005c5b20-0x005c5c87` | `0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md` | `0000GA`, emitter `0000PB` | TRUE | `86/90` | Moves bit ranges and shrinks to copied tail; ends exactly before runtime import thunk. |

## Support Page Actions

Apply these only if the exact child pages above are created.

1. Update [UID:0001O4] `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md`:
   - `COMPLETION:86 -> 88`
   - `CONFIDENCE:88 -> 91`
   - `RECONSTRUCTABLE:TRUE -> FALSE`
   - `EMITTER_UIDS:0000PB ->` blank
   - Revise status to "non-emitting source-family split index over exact WorldMapPane, private node-vector, private bitset, compiler thunk, and STL helper children."
   - Keep `CANONICAL_OWNER:0000PB` as the source-family/file context.
   - Keep final C++ blank.
2. Update [UID:0000G9] `by-class/WorldMapPane.md`:
   - `COMPLETION:86 -> 88`
   - `CONFIDENCE:88 -> 90`
   - Add links to the new WorldMapPane method children `NEW-O4-01` through `NEW-O4-21` and `NEW-O4-28`.
   - Add non-emitting compiler-glue notes for `NEW-O4-23` and `NEW-O4-27`.
3. Update [UID:0000G8] `by-class/WorldMapNodeEntryVector.md`:
   - `COMPLETION:84 -> 86`
   - `CONFIDENCE:88 -> 89`
   - Add exact child links `NEW-O4-24`, `NEW-O4-32`, and `NEW-O4-33`.
4. Update [UID:0000GA] `by-class/WorldMapReachabilityBitSet.md`:
   - `COMPLETION:84 -> 86`
   - `CONFIDENCE:88 -> 89`
   - Add exact child links `NEW-O4-22`, `NEW-O4-25`, `NEW-O4-26`, `NEW-O4-29`, `NEW-O4-30`, `NEW-O4-34`, and `NEW-O4-35`.
   - Add `NEW-O4-31` as non-emitting STL throw-helper context, not as a class method.
5. Update [UID:0000PB] `by-file/WorldMapPane.md`:
   - Keep `COMPLETION:90`.
   - Raise `CONFIDENCE:86 -> 89`.
   - Replace the broad proposed contents range wording with links to the exact child method/helper pages.
   - Preserve the open question that original private helper type names remain descriptive.
6. Add cross-links from [UID:00029E] `g_pWorldMapPane` to `NEW-O4-23` if the clear-cleanup thunk page is created. No score or metadata change is needed for [UID:00029E].
7. Add a cross-link from [UID:0003IZ] `VectorBoolTooLongRuntimeString` to `NEW-O4-31` if the throw-helper page is created. No score or metadata change is needed for [UID:0003IZ].

## Shared Coverage Row Replacement

Do not edit directly as B001. Supervisor should replace the single current [UID:0001O4] row at `by-memory/-coverage-report.md` between:

```text
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005c2ab5-0x005c2ac0 ...
```

and:

```text
    - [UID:00024B][0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport](by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md) ...
```

with this block after allocating real UIDs for `NEW-O4-*`:

```text
    - [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) 0x005c2ac0-0x005c5c87 | source-family split index | WorldMapPane : not_reconstructable : 88% : very-strong : Non-emitting split index over exact WorldMapPane lifecycle/view/draw/input/reachability children, private node-entry vector children, private reachability-bitset children, singleton cleanup/compiler glue, destructor adjustor thunks, and STL vector<bool> throw helper; B001 2026-06-16 live IDA and local PE scans confirm 37 in-range function starts, exact `DirectDrawCreate` successor at `0x005c5c87`, vtable/data refs, internal call graph, singleton/read-only-data links, and source-family routing to [UID:0000PB] WorldMapPane.cpp while final C++ remains blank pending final method names/private helper type names/packet fields.
        - [UID:NEW-O4-01][0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup](by-memory/0x005c2ac0-0x005c32aa.WorldMapPaneConstructorAndNodeSetup.md) 0x005c2ac0-0x005c32aa | constructor | WorldMapPaneConstructorAndNodeSetup : reconstructable : 86% : strong : Exact constructor/node setup child attached to [UID:0000G9] WorldMapPane; live IDA confirms constructor callers, vtable stores, singleton publish/fallback clear, node vector assignment, reachability build, and resource/init paths.
        - [UID:NEW-O4-02][0x005c32b0-0x005c341e.WorldMapPaneNonDeletingDestructor](by-memory/0x005c32b0-0x005c341e.WorldMapPaneNonDeletingDestructor.md) 0x005c32b0-0x005c341e | destructor | WorldMapPaneNonDeletingDestructor : reconstructable : 86% : strong : Exact destructor child attached to [UID:0000G9] WorldMapPane; live IDA confirms singleton clear, vtable restoration, helper cleanup, and scalar-destructor caller.
        - [UID:NEW-O4-03][0x005c3420-0x005c346d.WorldMapPaneSetViewPosition](by-memory/0x005c3420-0x005c346d.WorldMapPaneSetViewPosition.md) 0x005c3420-0x005c346d | method | WorldMapPaneSetViewPosition : reconstructable : 85% : strong : Sets viewport fields, clamps through `0x005c4740`, and invalidates/redraws; final field names remain open.
        - [UID:NEW-O4-04][0x005c34c0-0x005c3508.WorldMapPaneStartViewAnimation](by-memory/0x005c34c0-0x005c3508.WorldMapPaneStartViewAnimation.md) 0x005c34c0-0x005c3508 | method | WorldMapPaneStartViewAnimation : reconstructable : 85% : strong : Exact view animation helper attached to WorldMapPane; clamps target view and schedules frame callback.
        - [UID:NEW-O4-05][0x005c3540-0x005c3627.WorldMapPaneStartTravelToNode](by-memory/0x005c3540-0x005c3627.WorldMapPaneStartTravelToNode.md) 0x005c3540-0x005c3627 | method | WorldMapPaneStartTravelToNode : reconstructable : 86% : strong : Navigation/travel helper attached to WorldMapPane; direct calls to packet sender and frame scheduling confirmed.
        - [UID:NEW-O4-06][0x005c3630-0x005c36c8.WorldMapPaneSendTravelPacket](by-memory/0x005c3630-0x005c36c8.WorldMapPaneSendTravelPacket.md) 0x005c3630-0x005c36c8 | method | WorldMapPaneSendTravelPacket : reconstructable : 85% : strong : Compact travel packet sender attached to WorldMapPane; reads selected node-entry fields and sends seven bytes, with final packet enum/name still blocked.
        - [UID:NEW-O4-07][0x005c36d0-0x005c37d6.WorldMapPaneApplyVisibleClipRect](by-memory/0x005c36d0-0x005c37d6.WorldMapPaneApplyVisibleClipRect.md) 0x005c36d0-0x005c37d6 | method | WorldMapPaneApplyVisibleClipRect : reconstructable : 85% : strong : Screen-mode/constant-backed visible rectangle helper attached to WorldMapPane.
        - [UID:NEW-O4-08][0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode](by-memory/0x005c37e0-0x005c38fd.WorldMapPaneHitTestNode.md) 0x005c37e0-0x005c38fd | method | WorldMapPaneHitTestNode : reconstructable : 86% : strong : Iterates 0x94-byte node entries and returns hit node index or `-1`; caller xrefs from hover helpers confirmed.
        - [UID:NEW-O4-09][0x005c3950-0x005c3e41.WorldMapPaneOnDraw](by-memory/0x005c3950-0x005c3e41.WorldMapPaneOnDraw.md) 0x005c3950-0x005c3e41 | virtual method | WorldMapPaneOnDraw : reconstructable : 86% : strong : Vtable draw child attached to WorldMapPane; renders map, nodes, labels, reachability, clip rect, and player marker.
        - [UID:NEW-O4-10][0x005c3e50-0x005c402b.WorldMapPaneHandleKeyEvent](by-memory/0x005c3e50-0x005c402b.WorldMapPaneHandleKeyEvent.md) 0x005c3e50-0x005c402b | virtual method | WorldMapPaneHandleKeyEvent : reconstructable : 85% : strong : Vtable key handler attached to WorldMapPane; handles enter/space/escape/arrow navigation with final input enum names open.
        - [UID:NEW-O4-11][0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent](by-memory/0x005c40c0-0x005c4245.WorldMapPaneHandleMouseEvent.md) 0x005c40c0-0x005c4245 | virtual method | WorldMapPaneHandleMouseEvent : reconstructable : 85% : strong : Vtable mouse/input handler attached to WorldMapPane; hover, view movement, and travel-helper calls confirmed.
        - [UID:NEW-O4-12][0x005c4250-0x005c46e9.WorldMapPaneOnFrameUpdate](by-memory/0x005c4250-0x005c46e9.WorldMapPaneOnFrameUpdate.md) 0x005c4250-0x005c46e9 | virtual method | WorldMapPaneOnFrameUpdate : reconstructable : 86% : strong : Frame animation child attached to WorldMapPane; trigonometric motion, frame scheduling/removal, travel state, and invalidation paths confirmed.
        - [UID:NEW-O4-13][0x005c46f0-0x005c4733.WorldMapPaneOnTimerTick](by-memory/0x005c46f0-0x005c4733.WorldMapPaneOnTimerTick.md) 0x005c46f0-0x005c4733 | virtual method | WorldMapPaneOnTimerTick : reconstructable : 85% : strong : Small timer/marker-state virtual child attached to WorldMapPane.
        - [UID:NEW-O4-14][0x005c4740-0x005c484b.WorldMapPaneClampViewPosition](by-memory/0x005c4740-0x005c484b.WorldMapPaneClampViewPosition.md) 0x005c4740-0x005c484b | method | WorldMapPaneClampViewPosition : reconstructable : 86% : strong : View clamp helper attached to WorldMapPane; local PE scan and live IDA confirm nine internal callers.
        - [UID:NEW-O4-15][0x005c48b0-0x005c4bd0.WorldMapPaneDrawPlayerMarker](by-memory/0x005c48b0-0x005c4bd0.WorldMapPaneDrawPlayerMarker.md) 0x005c48b0-0x005c4bd0 | method | WorldMapPaneDrawPlayerMarker : reconstructable : 85% : strong : Marker/boat drawing helper attached to WorldMapPane; draw-path caller and special-region helper calls confirmed.
        - [UID:NEW-O4-16][0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData](by-memory/0x005c4bd0-0x005c5075.WorldMapPaneBuildReachabilityData.md) 0x005c4bd0-0x005c5075 | method | WorldMapPaneBuildReachabilityData : reconstructable : 86% : strong : Reachability builder attached to WorldMapPane; calls private bitset move/insert helpers and temporary vector/list helpers.
        - [UID:NEW-O4-17][0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse](by-memory/0x005c5080-0x005c50e6.WorldMapPaneUpdateHoverFromMouse.md) 0x005c5080-0x005c50e6 | method | WorldMapPaneUpdateHoverFromMouse : reconstructable : 85% : strong : Hover update helper attached to WorldMapPane; mouse-position and node-hit-test calls confirmed, final source name open.
        - [UID:NEW-O4-18][0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict](by-memory/0x005c50f0-0x005c5156.WorldMapPaneUpdateHoverFromMouseStrict.md) 0x005c50f0-0x005c5156 | method | WorldMapPaneUpdateHoverFromMouseStrict : reconstructable : 85% : strong : Second hover update helper attached to WorldMapPane; final distinction/name open.
        - [UID:NEW-O4-19][0x005c5160-0x005c519c.WorldMapPaneFindPredecessorNode](by-memory/0x005c5160-0x005c519c.WorldMapPaneFindPredecessorNode.md) 0x005c5160-0x005c519c | method | WorldMapPaneFindPredecessorNode : reconstructable : 85% : strong : Small route/predecessor helper attached to WorldMapPane; frame/travel callers confirmed, final name open.
        - [UID:NEW-O4-20][0x005c51a0-0x005c51fb.WorldMapPaneScreenPointHelper](by-memory/0x005c51a0-0x005c51fb.WorldMapPaneScreenPointHelper.md) 0x005c51a0-0x005c51fb | method | WorldMapPaneScreenPointHelper : reconstructable : 85% : strong : Small mouse/screen-point helper attached to WorldMapPane; final field/helper names open.
        - [UID:NEW-O4-21][0x005c5200-0x005c53d0.WorldMapPaneHitTestSpecialRegions](by-memory/0x005c5200-0x005c53d0.WorldMapPaneHitTestSpecialRegions.md) 0x005c5200-0x005c53d0 | method | WorldMapPaneHitTestSpecialRegions : reconstructable : 86% : strong : Special-region hit-test helper attached to WorldMapPane; marker-draw callers and world-map string linkage confirmed.
        - [UID:NEW-O4-22][0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits](by-memory/0x005c53d0-0x005c54f3.WorldMapReachabilityBitSetReserveBits.md) 0x005c53d0-0x005c54f3 | private helper method | WorldMapReachabilityBitSetReserveBits : reconstructable : 85% : strong : Reachability bitset reserve/grow helper attached to [UID:0000GA]; caller from insert helper confirmed.
        - [UID:NEW-O4-23][0x005c5500-0x005c550b.WorldMapPaneSingletonClearCleanupThunk](by-memory/0x005c5500-0x005c550b.WorldMapPaneSingletonClearCleanupThunk.md) 0x005c5500-0x005c550b | compiler cleanup thunk | WorldMapPaneSingletonClearCleanupThunk : ignored : 85% : strong : Non-emitting cleanup helper that clears [UID:00029E] g_pWorldMapPane; reached from SEH/cleanup funclet code, not handwritten source.
        - [UID:NEW-O4-24][0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor](by-memory/0x005c5510-0x005c557a.WorldMapNodeEntryVectorDestructor.md) 0x005c5510-0x005c557a | private helper destructor | WorldMapNodeEntryVectorDestructor : reconstructable : 86% : strong : Private 0x94-byte node-entry vector destructor attached to [UID:0000G8]; destructor and cleanup funclet callers confirmed.
        - [UID:NEW-O4-25][0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper](by-memory/0x005c5580-0x005c55d7.WorldMapReachabilityBitSetPositionHelper.md) 0x005c5580-0x005c55d7 | private helper method | WorldMapReachabilityBitSetPositionHelper : reconstructable : 85% : strong : Bitset iterator/position helper attached to [UID:0000GA]; insert-helper caller confirmed.
        - [UID:NEW-O4-26][0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator](by-memory/0x005c55e0-0x005c563c.WorldMapReachabilityBitSetResolveIterator.md) 0x005c55e0-0x005c563c | private helper method | WorldMapReachabilityBitSetResolveIterator : reconstructable : 85% : strong : Bit iterator resolver attached to [UID:0000GA]; range-move callers confirmed.
        - [UID:NEW-O4-27][0x005c563c-0x005c565d.WorldMapPaneAdjustorThunks](by-memory/0x005c563c-0x005c565d.WorldMapPaneAdjustorThunks.md) 0x005c563c-0x005c565d | compiler-generated adjustor thunks | WorldMapPaneAdjustorThunks : ignored : 86% : very-strong : Three 0xb-byte destructor adjustor thunks into `0x005c5660`; vtable-only refs and this-adjust offsets prove ABI glue.
        - [UID:NEW-O4-28][0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor](by-memory/0x005c5660-0x005c569b.WorldMapPaneScalarDeletingDestructor.md) 0x005c5660-0x005c569b | scalar deleting destructor | WorldMapPaneScalarDeletingDestructor : reconstructable : 87% : very-strong : Exact scalar deleting destructor attached to [UID:0000G9]; primary vtable and adjustor-thunk refs confirmed.
        - [UID:NEW-O4-29][0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits](by-memory/0x005c56a0-0x005c584b.WorldMapReachabilityBitSetInsertBits.md) 0x005c56a0-0x005c584b | private helper method | WorldMapReachabilityBitSetInsertBits : reconstructable : 86% : strong : Private reachability-bitset insert helper attached to [UID:0000GA]; growth, end-iterator, bit copy, and builder caller confirmed.
        - [UID:NEW-O4-30][0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount](by-memory/0x005c5850-0x005c58a9.WorldMapReachabilityBitSetShrinkToBitCount.md) 0x005c5850-0x005c58a9 | private helper method | WorldMapReachabilityBitSetShrinkToBitCount : reconstructable : 85% : strong : Private bitset shrink helper attached to [UID:0000GA]; range-move caller and too-long guard path confirmed.
        - [UID:NEW-O4-31][0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0](by-memory/0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0.md) 0x005c58b0-0x005c58ba | runtime throw helper | VectorBoolTooLongThrowHelper_5C58B0 : ignored : 86% : very-strong : Non-emitting STL/vector helper that references [UID:0003IZ] `vector<bool> too long`; source should express owning bitset operations, not this helper.
        - [UID:NEW-O4-32][0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign](by-memory/0x005c58c0-0x005c5a8f.WorldMapNodeEntryVectorAssign.md) 0x005c58c0-0x005c5a8f | private helper method | WorldMapNodeEntryVectorAssign : reconstructable : 86% : strong : Private node-entry vector assign/grow helper attached to [UID:0000G8]; 0x94-byte stride and constructor callers confirmed.
        - [UID:NEW-O4-33][0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation](by-memory/0x005c5a90-0x005c5aca.WorldMapNodeEntryVectorFreeAllocation.md) 0x005c5a90-0x005c5aca | private helper method | WorldMapNodeEntryVectorFreeAllocation : reconstructable : 85% : strong : Private node-entry vector free helper attached to [UID:0000G8]; assign-helper caller and large-allocation handling confirmed.
        - [UID:NEW-O4-34][0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator](by-memory/0x005c5ad0-0x005c5b18.WorldMapReachabilityBitSetEndIterator.md) 0x005c5ad0-0x005c5b18 | private helper method | WorldMapReachabilityBitSetEndIterator : reconstructable : 85% : strong : Private bitset end-iterator helper attached to [UID:0000GA]; insert-helper callers confirmed.
        - [UID:NEW-O4-35][0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange](by-memory/0x005c5b20-0x005c5c87.WorldMapReachabilityBitSetMoveBitRange.md) 0x005c5b20-0x005c5c87 | private helper method | WorldMapReachabilityBitSetMoveBitRange : reconstructable : 86% : strong : Private reachability-bitset range-move helper attached to [UID:0000GA]; builder caller, iterator resolver, shrink helper, and exact runtime successor at `0x005c5c87` confirmed.
```

## Ignored Ledger Additions

If the non-reconstructable child pages are created, add these exact entries to `by-memory/-ignored.md` near other text-section compiler/runtime helper entries. Use allocated UIDs in place of the placeholders.

```text
- [UID:NEW-O4-23][0x005c5500-0x005c550b.WorldMapPaneSingletonClearCleanupThunk](by-memory/0x005c5500-0x005c550b.WorldMapPaneSingletonClearCleanupThunk.md) - WorldMapPane singleton clear cleanup thunk.
  - Why ignored: compiler/EH cleanup helper that only clears [UID:00029E][0x0069b454-0x0069b458.g_pWorldMapPane](by-memory/0x0069b454-0x0069b458.g_pWorldMapPane.md). Source-level singleton lifecycle belongs to the constructor/destructor children, not a standalone handwritten helper.
  - Evidence: B001 2026-06-16 live IDA and local PE scan confirm exact `0x0b` body, jump xref from SEH/cleanup funclet code at `0x0060beff`, data/write relationship to `g_pWorldMapPane`, and no normal source caller.
  - Replacement/procurement: reconstruct singleton lifecycle through [UID:NEW-O4-01] `WorldMapPaneConstructorAndNodeSetup`, [UID:NEW-O4-02] `WorldMapPaneNonDeletingDestructor`, and [UID:00029E] `g_pWorldMapPane`.

- [UID:NEW-O4-27][0x005c563c-0x005c565d.WorldMapPaneAdjustorThunks](by-memory/0x005c563c-0x005c565d.WorldMapPaneAdjustorThunks.md) - WorldMapPane destructor adjustor thunks.
  - Why ignored: compiler-generated ABI glue for secondary/tertiary/fourth vtable views, not handwritten NexusTK source.
  - Evidence: B001 2026-06-16 live IDA and local PE scan confirm three 0xb-byte functions at `0x005c563c`, `0x005c5647`, and `0x005c5652`; vtable slots at `0x0063144c`, `0x0063147c`, and `0x00631488`; and jumps to scalar deleting destructor `0x005c5660` after this-pointer adjustment by `-0xa0`, `-0xa4`, and `-0xf8`.
  - Replacement/procurement: reconstruct the normal `WorldMapPane` destructor and inheritance/layout declaration so the compiler regenerates equivalent thunks.

- [UID:NEW-O4-31][0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0](by-memory/0x005c58b0-0x005c58ba.VectorBoolTooLongThrowHelper_5C58B0.md) - MSVC STL `vector<bool>` too-long throw helper.
  - Why ignored: compiler/runtime STL support helper physically adjacent to the private WorldMap bitset code; not handwritten NexusTK source.
  - Evidence: B001 2026-06-16 live IDA confirms `0x005c58b0` calls the runtime throw path with [UID:0003IZ][0x0061eaa8-0x0061eac0.VectorBoolTooLongRuntimeString](by-memory/0x0061eaa8-0x0061eac0.VectorBoolTooLongRuntimeString.md) `vector<bool> too long`; callers are only the bitset growth/insert paths that should be expressed as source-level bitset/vector operations.
  - Replacement/procurement: rebuild source-level reachability bitset operations through [UID:0000GA][WorldMapReachabilityBitSet](by-class/WorldMapReachabilityBitSet.md) children and link/procure STL/runtime support separately.
```

## Remaining Blockers

| Blocker | Evidence checked | Disposition |
| --- | --- | --- |
| Original private helper type names | Checked by-file/class docs, read-only-data, vtable data, function inventory, xrefs, proposed source tree. No debug/string symbol gives original names beyond descriptive `WorldMapNodeEntryVector` and `WorldMapReachabilityBitSet`. | Not blocking split. Keep descriptive names, cap support class confidence below final-source quality, and keep final C++ blank. |
| Final method names for small helpers `0x005c5080`, `0x005c50f0`, `0x005c5160`, `0x005c51a0` | Checked direct callers/callees and sampled decompilation. Behavior is sufficient for child ownership but not exact original names. | Child pages can clear 85/85 as evidence pages; final C++ remains blank. |
| Packet opcode/enum for `0x005c3630` | Checked decompilation and existing docs. Existing support docs mention travel packet `0x6E`, while the sampled packet builder call passes decimal `63`/`0x3f` before sending seven bytes. Without packet helper semantics, this cannot be safely normalized. | Keep `WorldMapPaneSendTravelPacket` as behavior name, score `85/89`, and leave final packet enum/source name unresolved. |
| Source file versus private helper files | Checked proposed source tree and owner docs. No independent source-path evidence exists for helper files; helper classes are only used by WorldMapPane. | Keep all source-bearing children emitting through [UID:0000PB] `WorldMapPane.cpp`. |
| IDA repair | Checked live IDA function inventory and local PE refs. All boundaries are modeled; names are not proven original. | No IDA DB edit recommended. |

## Validation Order

Recommended supervisor sequence:

1. Allocate UIDs and create the 35 child pages with the metadata and evidence above. Leave all final C++ blocks blank.
2. Raise/update support pages in this order: [UID:0000G8], [UID:0000GA], [UID:0000G9], [UID:0000PB], then [UID:0001O4].
3. Add cross-links to [UID:00029E] and [UID:0003IZ] without score changes.
4. Add ignored-ledger entries for `NEW-O4-23`, `NEW-O4-27`, and `NEW-O4-31`.
5. Replace the [UID:0001O4] shared coverage row with the block above using allocated UIDs.
6. Validate changed docs:
   - `python tools/validator.py --mode file --file by-memory/<new child>.md --apply` for each new child, or run documented/full validation if batching is easier.
   - `python tools/validator.py --mode file --file by-class/WorldMapPane.md --apply`
   - `python tools/validator.py --mode file --file by-class/WorldMapNodeEntryVector.md --apply`
   - `python tools/validator.py --mode file --file by-class/WorldMapReachabilityBitSet.md --apply`
   - `python tools/validator.py --mode file --file by-file/WorldMapPane.md --apply`
   - `python tools/validator.py --mode file --file by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md --apply`
   - `python tools/validator.py --mode file --file by-memory/-coverage-report.md --apply`
   - `python tools/validator.py --mode file --file by-memory/-ignored.md --apply`
7. Refresh the memory tool report:
   - `cd tools`
   - `python memory_ranges.py report`
   - `python memory_ranges.py report -advanced-scan`
8. Confirm [UID:0001O4] is no longer listed as a largest reconstructable leaf, and confirm no Barrier/General/Filename/Advanced errors were introduced.

## Direct Edit Confirmation

B001 made no direct edits to by-* documentation, generated reports, IDA DB, or `by-memory/-coverage-report.md` for this assignment. This report is the only created file.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001O4-worldmap-source-split-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001O4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
