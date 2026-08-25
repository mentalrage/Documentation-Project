** TARGET-REPORT-UID:0003XX **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003XX ObjectPaneUpdateBounds Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: the accepted callback has replaced the blank UID0003XX formal body with complete source-facing `ObjectPane::SetBounds` and raised UID0003XX from `85/90` to `92/94`.
- Final disposition: source-bearing ordinary ObjectPane virtual method at primary vtable slot `+0x2c`, not an aggregate, inline-only fragment, raw helper, MapPane method, generic rectangle helper, or compiler-generated routine.
- Completed support action: UID0003XW now emits the actual `UpdateRenderRegion` slot, inherited `Point m_origin` and `GrafPort::m_visibleBounds` expressions are synchronized, the complete ObjectPane union is preserved, and the three accepted sibling bodies use the proven `Point { y, x }` component order.
- Metadata: preserve owner/emitter [UID:00009R], reconstructable true, blank optional position, `Nested:0`, exact path/title/range, and source route [UID:0000M5] `NexusTK/map/ObjectPane.cpp`.
- Confidence: very strong for range, bytes, CFG, ABI, slot identity, vtable liveness, field expressions, call order, fallback behavior, source placement, and source/compiler separation. Exact original lexical spelling is not symbol-proven and remains the confidence cap.
- Report state: this same artifact records the completed B005 implementation callback. Fifteen ordinary by-* pages were changed and scoped-validated; validator-owned generated output refreshed under command `000000013989`. B005 did not manually edit coverage, generated, tracker, audit, supervisor, validator-state, IDA, or lifecycle files.

## Supporting Research

### Prior-report search

The following exact direct-target terms were searched:

- `TARGET-REPORT-UID:0003XX`
- `0003XX`
- `0x00537760`
- `ObjectPaneUpdateBounds`
- `sub_537760`

The following source-family/support terms were also used to rank relevant evidence:

- `ObjectPaneSetBounds`
- `ObjectPane::SetBounds`
- `ObjectPane::UpdateRenderRegion`
- `paneBounds`
- `objectDataBounds`
- `PaneLayout`
- `m_origin`
- `m_visibleBounds`
- `GetScreenBounds`
- `RectsEquivalent`
- `InitPointPair`
- `RectBounds::Offset`
- `MapPaneUpdateObjectPaneScreenBounds`
- `FlyingParcelPane`
- `FittingRoomListPane`

Search roots actually checked:

- `executed-b-agent-research`
- active `tools/leaser/Agents/Agent-B001/research` through `Agent-B015/research`
- `tools/leaser/Agents/Older-Research`
- `tools/leaser/Agents/SpecialReports`
- `research/executed`

The direct terms produced no `TARGET-REPORT-UID:0003XX` artifact and no dedicated UID0003XX report filename. Every direct matching report was opened:

| Report | Classification | Finding |
| --- | --- | --- |
| `executed-b-agent-research/B001/0001D5-objectpane-core-source-quality.md` | Direct aggregate/incidental target evidence; executed; older semantics partly superseded | Preserves exact target range, split, padding, ObjectPane vtable liveness, and the original child creation. Its `SetBounds`/`UpdateBounds`, generic `Rect`, and clip/dirty names predate the current vtable and pane/object-data contract. |
| `executed-b-agent-research/B002/0001DJ-SoundObjectPaneCore-empty-emitter-source-quality.md` | Incidental but authoritative current class/vtable support; executed | Resolves `0x00537740` as primary `+0x0c` `UpdateRenderRegion` and `0x00537760` as primary `+0x2c` two-argument `SetBounds`; supplies the complete current ObjectPane declaration. |
| `executed-b-agent-research/B005/0003HT-ItemObjectPaneClearOutputRects-source-quality.md` | Incidental direct semantic support; executed | Establishes `paneBounds` and `objectDataBounds`, resolves the target's downstream slot `+0x54` as `SetObjectData`, and records the former inherited-field blocker. This report closes that narrower blocker rather than repeating it. |
| `executed-b-agent-research/B012/000350-AttachedObjectPaneVtableData-empty-emitter-source-quality.md` | Incidental vtable support; executed | Confirms an AttachedObjectPane-family primary vtable cell points to `0x00537760`, supporting inherited family-wide dispatch. |

Additional support reports opened after source-family screening:

- `executed-b-agent-research/B002/0001EA-PaneCore-source-quality.md`: Pane `GetScreenBounds` and base `SetBounds` source-shape support.
- Current executed B001/B002/B005 ObjectPane evidence is treated as a union. Older names are retained only as labeled history where current binary and vtable evidence supersede them.

Evidence-based conclusion: no prior dedicated direct UID0003XX report exists. The older B001 aggregate and later support reports are useful evidence leads, not substitutes for this target-specific report.

### Evidence-time artifact snapshots

These hashes are evidence-time snapshots, not lifecycle assertions:

| Artifact | SHA256 | Bytes | Physical lines |
| --- | --- | ---: | ---: |
| Target UID0003XX | `8F1D37BA5962EFCA8892E486CDEF59670CF9615DBBAC354FBE0F795F093BDCF2` | 5,063 | 57 |
| UID0003XW | `B079C35F4762D7AB14FE8456FCCF7466E12605E7E41D25196891D0603891429E` | 1,988 | 45 |
| UID0003XY | `C7C091A847CF17194E6E5353CB3B0FF16FFDB4E0884ECD6F5317F08AB82106A1` | 3,385 | 50 |
| UID0001D5 aggregate | `20A4B5DD6F870A2888D6D3BCA4379348631D6F6F6F6DE11AA1B3048F8772BD06` | 14,054 | 130 |
| by-class/ObjectPane.md | `3D2A9355915A847CED538C6BC3E8322DAB642430DCDC86D0B8CA197D812F3D4E` | 32,911 | 290 |
| by-file/ObjectPane.md | `4631FCDED98491D0E55FBB23B8FDDA44CD97CDDBDCB739A1CC477817529869E0` | 25,200 | 180 |
| PaneLayout | `7D3F8FD2C1E7EF07E647A17E07927990C3A79CE13D59390250E5E87FABB2F248` | 16,236 | 113 |
| by-class/Pane.md | `B9686C65CE4A1E868E8FD3B9AF8478F36EBB5F764F585A12BB0B3A58E7CCAC10` | 15,523 | 127 |
| by-file/Pane.md | `D087404E6777513AD89AC4C4A09681346ED43A4948C3B1D7E7E579D3C02727C5` | 19,115 | 140 |
| RectGeometryHelpers | `94449DADA6F3BF1278A7581214ADAA3026C6D71C62AD494C54B48E132A9A40EE` | 29,320 | 294 |
| by-class/RectBounds.md | `710057507F3BCBAC7528CFC299AC57C6652068EBB24F1CEF06D60C513BAF370E` | 34,575 | 187 |
| RectBoundsLayout | `3FC01A6E920DDECDB8A2223D34244A535BF0DAF1AE838A9B36F3A42AAEEEAC33` | 12,702 | 96 |
| by-class/GrafPort.md | `F1AD63407DAD2CCE4891E755A9F6271F259D3BEB40E9780A74A250A52B16053C` | 61,379 | 308 |
| by-file/GrafPort.md | `F1BC7F4AB313CA6CD07C66D75210C619BA9E382D4AF19ADE422EBE6DDD4F7E56` | 56,202 | 278 |
| UID0002DG FittingRoom SetBounds sibling | `A77FD1855B9C58BB27370CD61B08CC02D95E8905F29180D1C4E780B92A405C34` | 8,583 | 91 |
| by-class/FittingRoomListPane.md | `89194B143A6BBF98DA9D3F7654FD5A03637CF474D7CA0B9B3D3CA34E9F4AAC62` | 56,338 | 143 |
| by-file/FittingRoom.md | `E9FB13C2BFDC560A3408BD3EDFA7C8F13E8492C32C0CC7E428C48DC76B888F9A` | 155,333 | 319 |
| UID0002R6 FlyingParcel start | `FDDE5E7F61AE7A52A18EFA66EF8C08CAF9A7D65EC0C97B73CB149FDA089988E3` | 22,157 | 235 |
| UID0002KK FlyingParcel step | `66BF0699D783EA79FBD5B69A9A668B91268A9F35CDECE0BEF13F61C4EE938770` | 21,331 | 177 |
| by-class/FlyingParcelPane.md | `39F8B99206C6E53F76AC0B1F175B5F10BFC4A2977B670F9973171A089C7F8B3E` | 44,966 | 205 |
| by-file/ParcelPane.md | `8876774BE2A1F6525F032B909321107D5C1F63E2A144DC134279B3C32ADBE415` | 59,890 | 244 |
| MapPane caller UID0004DS | `D6401881C30586DDA61E5D77CF34763166BBA5F495212B22551341F3CA8E40C0` | 9,301 | 65 |
| PaneVtables | `98E764F053FAB723828D07405CD682AD25237F87A270F311F15C352AD3A30793` | 10,002 | 102 |

## Target

- Target UID: `0003XX`.
- Target path: `by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md`.
- Exact executable range: `[0x00537760, 0x005377f2)`, 146 bytes.
- Queue row: first current `Not-Covered Files - Reconstructable` by-memory row at report assignment time, `85/90`, reconstructable true, direct report count zero.
- Current owner/emitter: [UID:00009R] ObjectPane.
- Current source route: [UID:0000M5] `NexusTK/map/ObjectPane.cpp`.
- Current formal state: complete managed `ObjectPane::SetBounds` body; generated output contains one definition and no UID0003XX Empty Emitter Marker.

## Current Target State

- Existing metadata is structurally correct: UID, path, title, range, owner/emitter UID00009R, reconstructable true, blank optional position, and `Nested:0`.
- The current page correctly preserves the `paneBounds` / optional `objectDataBounds` contract and downstream `SetObjectData` identity from executed UID0003HT.
- The callback corrected the former three source-quality defects: current prose records the `GetScreenBounds` comparison, the body uses resolved inherited fields, and the physical `UpdateBounds` slug is explicitly historical while the source-facing method is `ObjectPane::SetBounds`.
- The adjacent UID0003XW page now identifies its primary `+0x0c` source method as `ObjectPane::UpdateRenderRegion`; its inverse physical slug is retained only as historical/search vocabulary.
- The inherited state is source-expressible:
  - `this+0x44` is `GrafPort::m_visibleBounds`, a 16-byte `RectBounds`;
  - `this+0xac` is `Point m_origin.y`;
  - `this+0xb0` is `Point m_origin.x`;
  - `Point` is already formally reconstructed as `{ int y; int x; }`;
  - `RectBounds::Offset(int dx, int dy)`, `InitPointPair(Point *, int y, int x)`, and `RectsEquivalent` are already source-facing support.
- The bounded sibling inconsistency is resolved: UID0002DG uses Y/X `InitPointPair` and X/Y `OffsetRect`, while UID0002R6 and UID0002KK use inherited `m_origin.y`; unrelated behavior and scores remain unchanged.
- Current generated ObjectPane evidence after the waited callback refresh:
  - validator command/header `000000013989`, refreshed `2026-07-16T12:45:15-04:00`;
  - SHA256 `8FEF554BFB8FD61275340B2BEAFFE4F40A4EFBC7116CCAFEE55A16C5D127317F`;
  - exactly one UID0003XW `UpdateRenderRegion` definition and one UID0003XX `SetBounds` definition;
  - zero UID0003XW/UID0003XX Empty Emitter Markers and no handwritten cookie/SIMD/vtable/thunk/decompiler mechanics.
- External Gate 1, callback, coverage application, execution, revalidation, tracker, movement, and archive state are authoritative only in current validator/supervisor-owned artifacts.

## Executive Recommendation

1. Keep the target UID/path/title for stable address and search vocabulary, but identify the source method as `ObjectPane::SetBounds`.
2. Raise UID0003XX to `92/94` and apply Destination 1.
3. Keep UID0003XW's path/title but identify its source method as `ObjectPane::UpdateRenderRegion`, raise it to `92/94`, and apply Destination 2.
4. Preserve the complete current ObjectPane declaration byte-for-byte; it already declares both correct virtual contracts.
5. Update ObjectPane aggregate/class/file prose so the two child roles are no longer inverted.
6. Record `Point m_origin` as Y-first/X-second and `GrafPort::m_visibleBounds` as the direct inherited fields used by the target.
7. Apply the exact bounded sibling formal corrections in Destinations 3 through 5. Keep their unrelated scores, owners, emitters, source routes, and evidence unchanged.
8. Do not split, merge, rename the physical target page, add an accessor, add raw-offset access, introduce a new class field, or hand-author security-cookie/SSE/vtable mechanics.

## Supervisor Active Recheck

- The assigned item began as a direct report-first audit for UID0003XX; the accepted same-report implementation callback is now applied and verified.
- Split repair is not required. IDA models one normal function exactly at the target range, with clean padding and no interior competing entry.
- Every accepted source-bearing body applied by this callback has a destination-specific complete managed block.
- UID0003XY remains verify-only: its exact `SetObjectData` role supports the target, but its independent attachment/MapPane source blockers are outside this bounded body repair.
- UID00020R and executed UID0003HT remain verify-only same-or-greater support.
- The historical report-first phase changed no ordinary or restricted file. The later accepted callback changed only the fifteen named ordinary destinations; restricted files were not manually edited.

## Inference Research Guidance Check

- Binary facts, current documentation, and inference are separated throughout this report.
- The original lexical names are stripped. Source-facing names are accepted when vtable slot identity, existing formal declarations, field layout, and multiple consumers agree.
- Current documentation was treated as a hypothesis:
  - the UID3XW/UID3XX slugs are historical labels, not proof of virtual slot identity;
  - inherited `+0xac` as X was rejected after checking the actual `Point` declaration and X/Y consumers;
  - direct visible-bounds comparison was rejected because the target first dispatches `GetScreenBounds`.
- Raw offsets, synthetic accessors, decompiler array indexing, and opaque layout placeholders were not accepted as source.
- Wave2/Wave3 references found in older support pages were ignored as authority.

## Heuristic / Inference Reanalysis And Validation

### Method identity

- IDA fact: the target is stored at primary ObjectPane-family vtable slot `+0x2c`.
- Documentation fact: PaneVtables identifies primary `+0x2c` as `Pane::SetBounds`; current ObjectPane formal declares the two-argument override.
- Decision: source-facing name is `ObjectPane::SetBounds`.
- Rejected: `UpdateBounds`, `UpdateClip`, `UpdateDirtyRect`, `OnMovePane`, and free helper ownership.

### Adjacent UID0003XW identity

- IDA fact: UID0003XW is stored at primary ObjectPane-family slot `+0x0c` and copies one 16-byte argument to `this+0x44`.
- Documentation fact: PaneVtables identifies `+0x0c` as `UpdateRenderRegion`.
- Decision: source-facing name is `ObjectPane::UpdateRenderRegion`.
- Rejected: physical slug `ObjectPaneSetBounds` as source method identity.

### First comparison source expression

- IDA fact: target dispatches primary slot `+0x28` into a local 16-byte rectangle, then calls `RectsEquivalent(local, paneBounds)`.
- Documentation fact: PaneVtables identifies `+0x28` as `GetScreenBounds`.
- Decision: use a local `RectBounds` filled by `GetScreenBounds`, then compare it to `paneBounds`.
- Rejected: direct `RectsEquivalent(&m_visibleBounds, paneBounds)`, because that omits the virtual screen-space conversion call.

### Origin field

- IDA fact: target calls `InitPointPair(this+0xac, paneBounds->top, paneBounds->left)`.
- Documentation fact: the accepted `Point` declaration is `int y; int x;`; Event mouse fields, LoginDialog drag code, IMEComposition release code, and MapPane coordinate layout all agree on Y at the lower address and X at the higher address.
- Decision: `Point m_origin`, with `m_origin.y` at `+0xac` and `m_origin.x` at `+0xb0`.
- Rejected: two unrelated scalar fields, X-first point layout, FlyingParcel-private altitude/countdown state, and raw `this+0xac` syntax.

### Visible/local bounds field

- IDA fact: target copies all 16 bytes from `paneBounds` to `this+0x44`, then calls `0x004b78f0` on `this+0x44` with negative left/top.
- Documentation fact: `+0x44` is inherited `GrafPort::m_visibleBounds`; `0x004b78f0` is `RectBounds::Offset(int dx, int dy)`.
- Decision: assign to `m_visibleBounds` and call its member `Offset`.
- Rejected: new ObjectPane field, `m_bounds` alias in this target, free `OffsetRect` at `0x004b7e10`, raw SIMD, or a synthetic localization accessor.

### Conditional update order

- IDA fact: origin and local visible bounds are changed only when `RectsEquivalent` returns false.
- IDA fact: the order is origin store, 16-byte rectangle copy, then local negative-left/negative-top offset.
- Decision: preserve this order exactly.
- Rejected: unconditional origin write, offset-before-copy, direct zeroing, or calling base `Pane::SetBounds`, which has a different update-hook path.

### Second-argument fallback

- IDA fact: `objectDataBounds` is only null-tested. Non-null copies `*objectDataBounds`; null copies `*paneBounds`.
- IDA fact: the selected 16-byte value is copied into a local and passed by pointer through primary slot `+0x54`.
- Documentation fact: ObjectPane slot `+0x54` is `SetObjectData`.
- Decision: local `RectBounds` copy followed by `SetObjectData`.
- Rejected: forwarding the original pointer directly, retaining it, modifying caller storage, interpreting it as clip/dirty state, or adding null guards for `paneBounds`.

### Return type

- IDA presents an incidental integer return because the final virtual call leaves EAX live.
- Vtable declaration and all source-facing use identify a void setter; callers do not consume a target return contract.
- Decision: `void`.
- Rejected: `int`, `bool`, or returning the `SetObjectData` expression.

### Sibling parity

- FittingRoom UID0002DG uses the same two `InitPointPair` calls as Pane base `SetBounds`. Its current formal swaps both the point copy and `OffsetRect` deltas and uses historical method/helper names.
- FlyingParcel UID0002R6 and UID0002KK access owner `+0xac`; this is `m_origin.y`, not `m_origin.x`.
- Decision: correct only the affected component/order and source-facing inherited method/helper names while preserving all unrelated source.

### Score blockers

- Exact original lexical spelling is absent, but no behavior, type, ownership, source-placement, layout, call-order, or C++ blocker remains for the target.
- The target remains below 95 because the names are high-probability reconstruction names rather than PDB/source proof.
- UID0003XW reaches the same `92/94` level because it is a complete leaf override with exact slot and field identity.
- Broader Pane, FlyingParcelPane, FittingRoomListPane, and file-level unresolved work remains outside these bounded corrections and prevents support score inflation.

## Evidence Standards Used

- Live IDA MCP: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `callees`, and xref/vtable evidence.
- Exact bytes and SHA256 over the target and adjacent body.
- Function boundary, padding, instruction count, stack frame, basic-block count, and cyclomatic complexity.
- Primary vtable slot comparison across Pane and 14 ObjectPane-derived tables.
- Direct caller decompilation for MapPane UID0004DS.
- Existing exact helper/type declarations and method bodies.
- Cross-class field consumers for X/Y order.
- Current generated source read-only inspection.
- Old-report exact-term search and current by-* hash baselines.
- Negative evidence used only to reject alternatives, never to claim absence of original source.

The evidence is strong because independent binary, vtable, layout, caller, helper, and current source-declaration routes all converge. Confidence is capped only by stripped lexical names.

## Evidence Checked

### Live MCP

- Fresh `idb_list` returned one active adopted worker:
  - database session `64c11373`;
  - IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`;
  - PID/worker PID `21508`;
  - `is_analyzing:false`.
- Valid `server_health` returned:
  - `status:ok`;
  - input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`;
  - image base `0x00400000`;
  - auto-analysis ready;
  - Hex-Rays ready;
  - strings cache ready with 2,067 entries.
- One initial local PowerShell request omitted the required database argument because `$args` was used as a reserved automatic variable. That was a client-payload error, not an MCP outage. The corrected bounded call succeeded immediately.
- Target and support calls remained bounded. No broad whole-image search was used.

### Binary and function checks

- `lookup_funcs`:
  - `0x00537740 -> sub_537740`, size `0x11`;
  - `0x00537760 -> sub_537760`, size `0x92`;
  - no function at exclusive end `0x005377f2`;
  - successor `0x00537800 -> sub_537800`, size `0x7a`.
- Target `analyze_function`:
  - size 146;
  - 6 basic blocks;
  - cyclomatic complexity 3;
  - no strings;
  - no semantic constants;
  - no direct code callers;
  - 14 data/vtable xrefs.
- Target disassembly:
  - 60 instructions;
  - local stack allocation `0x24` plus cookie/saved registers;
  - normal `__thiscall` receiver;
  - two 32-bit pointer arguments;
  - `retn 8`.
- Target bytes:

```text
55 8b ec 83 ec 24 a1 24 2f 67 00 33 c5 89 45 fc
53 8b 5d 0c 56 8b f1 8d 4d dc 57 8b 7d 08 51 8b
06 8b ce ff 50 28 8d 45 dc 57 50 e8 40 07 f8 ff
83 c4 08 84 c0 75 2d ff 37 8d 86 ac 00 00 00 ff
77 04 50 e8 88 04 f8 ff 0f 10 07 8d 4e 44 83 c4
0c 0f 11 01 8b 41 04 f7 d8 50 8b 01 f7 d8 50 e8
2c 01 f8 ff 85 db 75 05 0f 10 07 eb 03 0f 10 03
8b 06 8d 4d ec 51 8b ce 0f 11 45 ec ff 50 54 8b
4d fc 5f 5e 33 cd 5b e8 43 ff 08 00 8b e5 5d c2
08 00
```

- Target byte SHA256: `835BBF1FEF3191C1376D1F9028BC4D40F33DC668E82EDE60F62F0E84020D2534`.
- UID0003XW exact 17-byte SHA256: `24D2ABFA82A92994E75E5A99488A477AD44BEC610444CA3E032BCB21F18068BA`.
- Pre-target padding `[0x00537751,0x00537760)`:
  - 15 bytes, all `0xcc`;
  - SHA256 `54CC9DD9593316E80CCAF5D10856E6502A0D75F20473A92FA01D63228EF1624C`.
- Post-target padding `[0x005377f2,0x00537800)`:
  - 14 bytes, all `0xcc`;
  - SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.

### Helper and caller checks

- Target direct callees:
  - `0x004b7ed0` `RectsEquivalent`;
  - `0x004b7c30` `InitPointPair`;
  - `0x004b78f0` `RectBounds::Offset`;
  - `0x005c772f` security-cookie check.
- Virtual calls:
  - primary `+0x28` `GetScreenBounds`;
  - primary `+0x54` `SetObjectData`.
- MapPane UID0004DS decompilation at `0x00506980`:
  - first dispatches ObjectPane `+0x50` to fill `paneBounds` and `objectDataBounds`;
  - offsets both rectangles for map/tile position;
  - tail-dispatches ObjectPane `+0x2c` with both pointers;
  - has 44 code xrefs, proving ordinary runtime use of the target virtual contract.
- Pane support decompilation:
  - `0x00544b80` `GetScreenBounds` obtains a screen offset, copies inherited GrafPort bounds, and offsets them;
  - `0x00544bd0` base `SetBounds` stores top/left into `m_origin`, localizes a rectangle, and dispatches `UpdateRenderRegion`.
- FittingRoom UID0002DG decompilation at `0x0041ed90` repeats the same two point initializations and local rectangle offset.
- FlyingParcel UID0002KK decompilation confirms the timer facet receives `this == owner+0xa4` and decrements owner `+0xac`.

### Documentation and generated checks

- Target, adjacent siblings, aggregate, ObjectPane class/file, Pane class/file/layout/vtable, GrafPort, RectBounds, RectGeometryHelpers, MapPane caller, LoginDialog, IMEComposition, FittingRoom, FlyingParcel, ParcelPane, old reports, tracker, generated outputs, and manual coverage were read.
- Evidence-time generated snapshots:
  - `ObjectPane.cpp`: command `13940`, SHA256 `C3B91372FB2E4823FF5DE338F15E593BD5FA45B75910DE44FF15D9ECB2638A19`;
  - `FittingRoom.cpp`: command `13940`, SHA256 `94FCE8BF0551CF1D80C5CB4606D70F46C52E06F7D4F5D96151579251B59467ED`;
  - `ParcelPane.cpp`: command `13940`, SHA256 `ED3DC167F0AA17C86A2B7A6A16CD7D91CE1A6E59C5CBAF7E27439D0AD30806FA`.
- Historical report-only phase: B005 ran no implementation validator or generated refresh before Gate 1. The later accepted callback validator record is under Validator Results.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target is exactly `[0x00537760,0x005377f2)`, 146 bytes. | very strong | lookup/bytes/function boundary | UID0003XX | incorporate | applied |
| C02 | Target bytes hash to `835BBF...D2534`. | very strong | exact MCP byte read/SHA256 | UID0003XX | incorporate | applied |
| C03 | Target has 60 instructions, 6 blocks, complexity 3, and `retn 8`. | very strong | disasm/analyze | UID0003XX | incorporate | applied |
| C04 | Target is source-facing `ObjectPane::SetBounds`, primary slot `+0x2c`. | very strong | Pane/ObjectPane vtable comparison | UID0003XX/ObjectPane support | incorporate | applied |
| C05 | Physical UID0003XX path/title remain stable historical/search vocabulary. | strong | UID stability/current links | UID0003XX | already-present | already-present |
| C06 | First argument is non-null `paneBounds`. | very strong | binary loads/no guard/current declaration | UID0003XX | incorporate | applied |
| C07 | Second argument is optional `objectDataBounds`. | very strong | null branch/current declaration | UID0003XX | already-present | already-present |
| C08 | Target first obtains screen bounds through virtual slot `+0x28`. | very strong | target disasm/PaneVtables | UID0003XX | incorporate | applied |
| C09 | Comparison is `RectsEquivalent(screenBounds,paneBounds)`, not direct local-bounds equality. | very strong | target call order/helper body | UID0003XX | reject-stale | applied |
| C10 | Origin/local state changes only when rectangles are not equivalent. | very strong | CFG/conditional branch | UID0003XX | incorporate | applied |
| C11 | `+0xac/+0xb0` is `Point m_origin` with Y then X. | very strong | Point formal/layout/consumers | PaneLayout/Pane/ObjectPane support | incorporate | applied |
| C12 | Target initializes origin from `paneBounds->top` then `paneBounds->left`. | very strong | exact call arguments | UID0003XX | incorporate | applied |
| C13 | `+0x44` is inherited `GrafPort::m_visibleBounds`. | very strong | GrafPort/Pane layout/GetBounds consumers | PaneLayout/ObjectPane support | already-present | already-present |
| C14 | Target copies all 16 pane-bounds bytes into `m_visibleBounds`. | very strong | movups/field layout | UID0003XX | incorporate | applied |
| C15 | Target localizes `m_visibleBounds` with member `RectBounds::Offset(-left,-top)`. | very strong | call address/member body/argument order | UID0003XX | incorporate | applied |
| C16 | Calling base `Pane::SetBounds` is not behavior-identical. | very strong | base decompile differs in update-hook path | UID0003XX negative evidence | reject-invalid | excluded-with-reason |
| C17 | Null object-data input selects a local copy of `paneBounds`. | very strong | branch/movups | UID0003XX | incorporate | applied |
| C18 | Non-null object-data input selects a local copy of `*objectDataBounds`. | very strong | branch/movups | UID0003XX | incorporate | applied |
| C19 | Target always calls virtual `SetObjectData` with the selected local copy. | very strong | slot `+0x54`/current declaration | UID0003XX | incorporate | applied |
| C20 | Target source return type is void; IDA EAX is incidental. | very strong | vtable declaration/caller use | UID0003XX | incorporate | applied |
| C21 | Security-cookie operations are compiler-generated. | very strong | prologue/epilogue | UID0003XX | reject-invalid | excluded-with-reason |
| C22 | SIMD rectangle copies are compiler lowering, not handwritten intrinsics. | very strong | 16-byte POD assignments/current style | UID0003XX/UID0003XW | reject-invalid | excluded-with-reason |
| C23 | UID0003XW is `UpdateRenderRegion`, primary slot `+0x0c`. | very strong | vtable comparison | UID0003XW/ObjectPane support | reject-stale | applied |
| C24 | UID0003XW source body is one `m_visibleBounds` assignment. | very strong | exact 17-byte leaf | UID0003XW Destination 2 | incorporate | applied |
| C25 | UID0003XW rose `86/90 -> 92/94`. | strong | complete leaf/slot/field proof | UID0003XW | incorporate | applied |
| C26 | UID0003XX rose `85/90 -> 92/94`. | strong | all blockers closed/complete body | UID0003XX | incorporate | applied |
| C27 | UID0001D5 stays `88/91`, non-emitting split/index. | very strong | current aggregate structure | UID0001D5 | already-present | already-present |
| C28 | ObjectPane class stays `92/94`; complete formal declaration remains unchanged. | very strong | current class union | by-class/ObjectPane.md | already-present | already-present |
| C29 | ObjectPane file stays `91/92` and routes both bodies to `NexusTK/map/ObjectPane.cpp`. | very strong | current file/source island | by-file/ObjectPane.md | incorporate | applied |
| C30 | UID0003XY remains independent verify-only support. | very strong | current body/blockers | UID0003XY | not-applicable | excluded-with-reason |
| C31 | PaneLayout must state exact Y/X member order without score/formal change. | very strong | Point/helper/consumer union | PaneLayout | incorporate | applied |
| C32 | Pane class/file must record the exact inherited field/source-expression contract without broad formal replacement. | strong | current blank broad class rationale | Pane class/file | incorporate | applied |
| C33 | UID0002DG current formal swaps point members and offset deltas. | very strong | decompile/helper declaration | UID0002DG Destination 3 | reject-stale | applied |
| C34 | UID0002DG is source-facing `SetBounds` and calls `UpdateRenderRegion`. | very strong | Pane vtable slots/base parity | UID0002DG/Fitting support | incorporate | applied |
| C35 | UID0002DG stays `87/90`; correction does not resolve broader class lexemes. | strong | bounded support scope | UID0002DG | already-present | already-present |
| C36 | FlyingParcel owner `+0xac` is `m_origin.y`, not `.x`. | very strong | Point order/owner normalization | UID0002R6/UID0002KK/class/file | reject-stale | applied |
| C37 | FlyingParcel scores/metadata remain unchanged. | strong | behavior already otherwise complete | FlyingParcel support | already-present | already-present |
| C38 | No target split, merge, new UID, path rename, or source-route change is warranted. | very strong | exact function/padding/vtable | target/support | reject-invalid | excluded-with-reason |
| C39 | Exact manual coverage rows are required for affected stale/current descriptions. | very strong | read-only coverage comparison | manual handoff section | incorporate | applied |
| C40 | Generated callback assertions must prove target/adjacent definitions and absence of decompiler/compiler source pollution. | very strong | current generated marker/state | validator/generated plan | incorporate | applied |

Ledger note: callback verification states are terminal and limited to `applied`, `already-present`, `excluded-with-reason`, or `blocked`; no claim is blocked.

## Positive Evidence Summary

- One exact modeled function occupies the target range.
- Both adjacent padding spans are clean `0xcc`.
- Fourteen ObjectPane-family vtable cells point to the target at the same primary slot.
- PaneVtables resolves that slot as `SetBounds`.
- The existing complete ObjectPane declaration already exposes the exact two-argument contract.
- Target helper calls map cleanly to accepted `RectsEquivalent`, `InitPointPair`, and `RectBounds::Offset`.
- Existing layout/type docs expose `Point { y, x }` and `GrafPort::m_visibleBounds`.
- LoginDialog, IMEComposition, MapPane, Pane base, and FittingRoom binary behavior independently corroborate the field order.
- MapPane UID0004DS supplies both rectangles and tail-dispatches this exact slot from a helper with 44 code callers.
- UID0003XY supplies the downstream `SetObjectData` identity and object-data storage behavior.
- The resulting target body is complete, ordinary, source-era C++ without raw offsets or decompiler scaffolding.

## IDA MCP Facts

- Active database at evidence time: `64c11373`.
- Target:
  - start `0x00537760`;
  - exclusive end `0x005377f2`;
  - size `0x92`;
  - 60 instructions;
  - 6 basic blocks;
  - complexity 3;
  - stack local allocation `0x24`;
  - `retn 8`;
  - no strings/constants;
  - no direct code callers;
  - 14 data/vtable xrefs.
- Target xrefs:
  - `0x00613090`
  - `0x006202c4`
  - `0x00620370`
  - `0x0062041c`
  - `0x006204c8`
  - `0x00620574`
  - `0x00620628`
  - `0x00620764`
  - `0x00620818`
  - `0x006208cc`
  - `0x006209a8`
  - `0x00620a68`
  - `0x00620b14`
  - `0x0062ef38`
- These correspond to BalloonObjectPane, ObjectPane, StaticObjectPane, ItemObjectPane, FlyingObjectPane, AttachedObjectPane, EffectObjectPane, HitBarObjectPane, DamageNumberObjectPane, ObjectInfoObjectPane, LivingObjectPane, LightingObjectPane, SoundObjectPane, and UserPane primary vtables.
- BowGaugeObjectPane overrides this slot and therefore is not another target xref.
- Callees:
  - `RectsEquivalent`;
  - `InitPointPair`;
  - `RectBounds::Offset`;
  - security-cookie check.
- Virtual dispatches:
  - `GetScreenBounds` at `+0x28`;
  - `SetObjectData` at `+0x54`.
- No function exists at target end; no xref points to target end.

## Function / Child Inventory

| Range | UID/entity | Source-facing role | Disposition |
| --- | --- | --- | --- |
| `0x00537720-0x00537739` | UID0003XV | Object-data rectangle invalidation override | Verify-only support |
| `0x00537739-0x00537740` | padding | alignment | Preserve ignored |
| `0x00537740-0x00537751` | UID0003XW | `ObjectPane::UpdateRenderRegion` | Source body Destination 2; `92/94` |
| `0x00537751-0x00537760` | padding | 15 `0xcc` bytes | Preserve ignored |
| `0x00537760-0x005377f2` | UID0003XX | `ObjectPane::SetBounds` | Source body Destination 1; `92/94` |
| `0x005377f2-0x00537800` | padding | 14 `0xcc` bytes | Preserve ignored |
| `0x00537800-0x0053787a` | UID0003XY | `ObjectPane::SetObjectData` | Verify-only independent child |
| `0x0053787a-0x00537880` | padding | alignment | Preserve ignored |

No child creation, UID allocation, range shift, aggregate merge, or nesting change is required.

## Direct Xref / Caller Inventory

- Direct target code callers: none.
- Direct target data/vtable xrefs: 14, listed under IDA MCP Facts.
- Runtime caller route:
  - MapPane UID0004DS gets pane and object-data output rectangles through ObjectPane slot `+0x50`;
  - applies map/tile/movement offsets;
  - tail-calls ObjectPane slot `+0x2c` with both rectangles;
  - UID0004DS has 44 code xrefs from object creation, object refresh, packet/update, and local-player/living-object paths.
- This is ordinary virtual dispatch liveness. The absence of direct code xrefs to the target does not imply no original source.
- Vtable fanout proves the body is inherited by most ObjectPane-derived classes; a few classes replace the slot with a derived override.

## Documentation Evidence And IDA Status

- Current ObjectPane class declaration is already source-complete for this contract and must be preserved.
- Current UID0003HT evidence correctly established pane/object-data parameter roles and is not reopened.
- Current target prose's blank-body blocker is superseded by the combined current field/type/consumer evidence.
- Current UID0003XW prose is stale because the physical slug was treated as the source method name.
- Current PaneLayout is directionally correct but underspecified at `+0xac`; it must state exact `Point` member order.
- Current FlyingParcel and FittingRoom formals are behaviorally inconsistent with that exact order.
- Current generated ObjectPane output still has an empty target marker because the target formal is blank.
- Current FittingRoom generated output reproduces the stale swapped component/order.
- Current ParcelPane generated output does not currently emit UID0002R6/UID0002KK despite their existing formals; the ordinary docs remain the source-quality authority for the bounded component correction, and callback validation must record the resulting generated disposition rather than inventing duplicate source.
- MCP was healthy for all valid bounded requests used by this report.

## Ranked Ownership Analysis

1. **ObjectPane member method - accepted.**
   - Primary ObjectPane-family vtable slot.
   - Uses ObjectPane downstream `SetObjectData`.
   - Existing class declaration contains the exact override.
   - Located inside the ObjectPane method island.

2. **Pane base method - rejected as direct owner.**
   - Pane defines the inherited slot contract and fields, but the target is an ObjectPane override with extra object-data behavior.

3. **MapPane method - rejected.**
   - MapPane computes and supplies bounds, then calls the ObjectPane virtual. It is a consumer.

4. **GrafPort/RectBounds/geometry helper - rejected.**
   - They own the inherited field or helper operations, not this ObjectPane orchestration.

5. **Standalone raw/free helper - rejected.**
   - IDA models a normal member-shaped function and vtables supply the receiver route.

6. **Compiler-generated/no-source - rejected.**
   - The cookie and SIMD are generated details, but the control flow, virtual calls, branch, field updates, and fallback are ordinary source-authored behavior.

## Source Placement

- Primary source root: [UID0000M5] `NexusTK/map/ObjectPane.cpp`.
- Header contract: current reconstructed `ObjectPane.h` declaration in [UID00009R].
- Support dependencies:
  - Pane/GrafPort inherited state;
  - RectBounds;
  - Point and rectangle helpers.
- Rejected placements:
  - `Pane.cpp`, because ObjectPane adds object-data behavior;
  - `MapPane.cpp`, because MapPane is the caller;
  - `GrafPort.cpp` or geometry utility source, because helper calls do not transfer ownership;
  - inline-only header body, because the binary has one ordinary out-of-line function and vtable address.
- UID0003XW belongs to the same ObjectPane source root.
- FittingRoom and FlyingParcel corrections stay in their established source roots; they are support synchronization, not ownership migration.

## Range / Split / Padding / Reclassification Analysis

- Target start is a normal prologue at `0x00537760`.
- Target exclusive end is `0x005377f2`.
- No interior modeled entry, vtable pointer, or xref supports a split.
- No tail code extends into the following padding.
- Preceding UID0003XW ends at `0x00537751`.
- Fifteen `0xcc` bytes separate UID0003XW from the target.
- Fourteen `0xcc` bytes separate the target from UID0003XY.
- The target remains one exact child under UID0001D5.
- Reclassification is semantic only:
  - UID0003XW source role becomes `UpdateRenderRegion`;
  - UID0003XX source role becomes `SetBounds`;
  - physical page names remain unchanged.
- `Nested:0` remains correct for both exact children and the aggregate remains a non-emitting index.

## Negative Evidence Summary

- No original symbol or PDB spelling survives.
- No direct code xref points to the target start; liveness is virtual.
- No string or constant names the method.
- No evidence supports clip/dirty ownership for the second argument.
- No evidence supports a new ObjectPane origin or bounds field.
- No evidence supports X at `+0xac`.
- No evidence supports direct comparison with `m_visibleBounds`; the virtual `GetScreenBounds` call is explicit.
- No evidence supports direct forwarding of the second pointer; the body copies through a local.
- No evidence supports a return value contract.
- No evidence supports handwritten SSE, security-cookie, vtable, or thunk source.
- No evidence supports splitting, merging, renaming the physical page, or allocating a new UID.
- No evidence supports increasing broad Pane/FlyingParcel/FittingRoom class or file scores from this bounded work.

## IDA Rename / Type / Comment Recommendations

No IDA mutation is requested or permitted.

Read-only source-facing recommendations:

- `sub_537760` -> `ObjectPane::SetBounds`
- `sub_537740` -> `ObjectPane::UpdateRenderRegion`
- first argument -> `paneBounds`
- second argument -> `objectDataBounds`
- first local rectangle -> current/screen bounds
- second local rectangle -> selected object-data bounds
- `this+0xac` -> `m_origin.y`
- `this+0xb0` -> `m_origin.x`
- `this+0x44` -> `m_visibleBounds`

These are reconstruction recommendations, not claims that original symbols were recovered.

## First-Draft C++ Recommendation

Exactly five destination-specific managed blocks were accepted and applied. They are the only C++ body edits in this callback.

### Destination 1 - `by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ObjectPane::SetBounds(
    const RectBounds *paneBounds,
    const RectBounds *objectDataBounds)
{
    RectBounds currentBounds;
    GetScreenBounds(&currentBounds);

    if (!RectsEquivalent(&currentBounds, paneBounds)) {
        InitPointPair(&m_origin, paneBounds->top, paneBounds->left);
        m_visibleBounds = *paneBounds;
        m_visibleBounds.Offset(-m_visibleBounds.left,
                               -m_visibleBounds.top);
    }

    RectBounds newObjectDataBounds;
    if (objectDataBounds != NULL) {
        newObjectDataBounds = *objectDataBounds;
    } else {
        newObjectDataBounds = *paneBounds;
    }

    SetObjectData(&newObjectDataBounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2 - `by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ObjectPane::UpdateRenderRegion(const RectBounds *bounds)
{
    m_visibleBounds = *bounds;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - `by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomListPane::SetBounds(
    const RectBounds *bounds,
    const RectBounds *)
{
    Point origin;
    InitPointPair(&origin, bounds->top, bounds->left);
    InitPointPair(&m_origin, origin.y, origin.x);

    RectBounds localBounds = *bounds;
    OffsetRect(&localBounds, -origin.x, -origin.y);
    UpdateRenderRegion(&localBounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FlyingParcelPane::StartAnimation(unsigned char parcelCountOrState,
                                      unsigned char leftSlot,
                                      unsigned char rightSlot,
                                      bool isParcel)
{
    RectBounds animationRect;

    if (g_useEpfAssets == 1) {
        g_pSoundManager->PlaySample(200, 100);
        g_pScreenPane->SetLayerFrame(m_animationLayer, 0);

        m_leftSlot = leftSlot;
        m_rightSlot = rightSlot;
        m_parcelCountOrState = parcelCountOrState;
        m_isParcel = isParcel;
        m_animationFrame = 0;

        if (isParcel) {
            SetRect(&animationRect, 630, 730, 659, 755);
        } else {
            SetRect(&animationRect, 667, 730, 698, 747);
        }

        RemoveFromLayer();
        AddToLayer(&animationRect, 0, nullptr, m_animationLayer);
        m_origin.y += 30;
        InvalidateRect(&m_bounds);
        m_timerHandler.ScheduleTimer(0, 100, 0, 0);
        return;
    }

    g_pScreenPane->SetLayerFrame(m_animationLayer, 0);

    m_leftSlot = leftSlot;
    m_rightSlot = rightSlot;
    m_parcelCountOrState = parcelCountOrState;
    m_isParcel = isParcel;
    m_animationFrame = 0;

    const int displaySlot =
        parcelCountOrState <= 4 ? parcelCountOrState : 4;
    SetRect(&animationRect,
            397 + displaySlot * 11,
            4,
            419 + displaySlot * 11,
            26);

    RemoveFromLayer();
    AddToLayer(&animationRect, 0, nullptr, m_animationLayer);
    InvalidateRect(&m_bounds);
    m_timerHandler.ScheduleTimer(0, 10, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5 - `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool FlyingParcelPane::AnimateStep(int, int, int)
{
    if (m_animationFrame < 30) {
        --m_origin.y;
        InvalidateRect(&m_bounds);
        ++m_animationFrame;
        m_timerHandler.ScheduleTimer(0, 10, 0, 0);
        return true;
    }

    RemoveFromLayer();
    g_pScreenPane->RemoveLayer(m_animationLayer);
    g_pParcelPane->SetParcelSlotData(m_parcelCountOrState,
                                     m_leftSlot,
                                     m_rightSlot);
    g_pParcelPane->m_rightSlotActionEnabled = true;
    g_pParcelPane->InvalidateRect(&g_pParcelPane->m_bounds);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Destination 4 and Destination 5 preserve the complete existing accepted blocks and change only the proven origin component.

## Final Recommendation

- C01-C40 are implemented at report-level detail and Destinations 1 through 5 are applied exactly.
- The callback raised only:
  - UID0003XX `85/90 -> 92/94`;
  - UID0003XW `86/90 -> 92/94`.
- Preserve all other stated scores.
- Preserve UID0003XX and UID0003XW physical paths/titles for UID/search stability.
- Preserve ObjectPane owner/emitter UID00009R, source route UID0000M5, reconstructable true, blank optional positions, and `Nested:0`.
- Preserve UID0001D5 as `88/91`, owner none, reconstructable false, blank emitter/formal, non-emitting split/index.
- Preserve ObjectPane class formal byte-for-byte.
- Preserve UID0003XY metadata/formal and all unrelated attachment evidence.
- The exact inherited point order is corrected in Pane/FittingRoom/FlyingParcel support without broad class-layout invention.
- Do not add raw offsets, synthetic accessors, decompiler labels, SSE intrinsics, security cookies, vtable arrays, thunks, or handwritten ABI mechanics.
- No third-party import applies.

## Recommended Target Doc Changes

Applied and verified in the completed callback:

For `by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md`:

- Set `COMPLETION:92`.
- Set `CONFIDENCE:94`.
- Preserve UID, range, path/title, owner UID00009R, reconstructable true, emitter UID00009R, blank optional position, and `Nested:0`.
- Apply Destination 1.
- Replace the Item Summary with:

```text
*** Item Summary: Exact source-bearing ObjectPane SetBounds override at primary slot +0x2c: obtains current screen bounds, compares them with paneBounds, stores Point m_origin as top/Y then left/X and localizes inherited GrafPort::m_visibleBounds only when changed, then passes objectDataBounds or the paneBounds fallback through SetObjectData; the physical ObjectPaneUpdateBounds slug is historical/search vocabulary, and cookie/SIMD/vtable mechanics are compiler-generated. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Add all exact bytes/hash/range/padding/ABI/CFG/stack/vtable/xref/caller/callee/field/fallback/source-boundary evidence from this report.
- Historicalize the former direct-visible-bounds comparison and inherited-field blank-body blocker.
- Preserve the pane/object-data terminology and superseded clip/dirty history from UID0003HT.

## Recommended Support Doc Changes

All ordinary changes below are applied and scoped-validated; verify-only items remained unchanged after reread.

### Ordinary changes

1. `by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md`
   - Raise `86/90 -> 92/94`.
   - Preserve all metadata.
   - Apply Destination 2.
   - Identify primary slot `+0x0c` and source role `UpdateRenderRegion`.
   - Preserve the physical slug as historical/search vocabulary.
   - Add exact 17-byte hash and compiler-lowered SIMD assignment evidence.
   - Exact Item Summary:

```text
*** Item Summary: Exact source-bearing ObjectPane UpdateRenderRegion override at primary slot +0x0c; copies the 16-byte RectBounds argument into inherited GrafPort::m_visibleBounds, with the physical ObjectPaneSetBounds slug retained only as historical/search vocabulary and movups treated as compiler lowering. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. `by-memory/0x005372d0-0x005378fa.ObjectPane.md`
   - Keep `88/91`, owner none, reconstructable false, blank emitter/formal, and `Nested:0`.
   - Correct the UID0003XW child row to `UpdateRenderRegion`.
   - Correct the UID0003XX child row to `SetBounds` with exact source-ready behavior.
   - Preserve the complete child/padding inventory and all unrelated field/history evidence.

3. `by-class/ObjectPane.md`
   - Keep `92/94`, position, owner/emitter, complete declaration, fields, methods, defaults, friends, and `[[CHILDREN]]` byte-for-byte.
   - Correct the method inventory rows so UID0003XW is `UpdateRenderRegion` and UID0003XX is `SetBounds`.
   - Add exact target order, inherited field expressions, local object-data fallback, and compiler exclusions.

4. `by-file/ObjectPane.md`
   - Keep `91/92`, path, source inventory, and prose-only formal policy.
   - Record both source-ready bodies under `NexusTK/map/ObjectPane.cpp`.
   - Correct stale inverted child naming while preserving every concurrent ObjectPane fact.

5. `by-type/by-struct/PaneLayout.md`
   - Keep `85/88` and blank formal.
   - Refine `+0xac` to `Point m_origin`, with `m_origin.y` at `+0xac` and `m_origin.x` at `+0xb0`.
   - Retain `+0x44` as inherited `GrafPort::m_visibleBounds`.
   - Add target, Pane base, LoginDialog, IMEComposition, MapPane, FittingRoom, and FlyingParcel parity evidence.

6. `by-class/Pane.md`
   - Keep `90/91` and blank whole-class formal.
   - Add a bounded inherited-state note for `Point m_origin`, Y/X order, `GetScreenBounds`, base `SetBounds`, and `UpdateRenderRegion`.
   - Preserve all unrelated Pane methods/history.

7. `by-file/Pane.md`
   - Keep `90/91`, route, and blank class-formal policy.
   - Add the same bounded source-boundary note without duplicating target bodies.

8. `by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md`
   - Keep `87/90`, owner/emitter UID000053, reconstructable true, blank position, and current nesting.
   - Apply Destination 3.
   - Use source-facing `SetBounds`, `InitPointPair`, and `UpdateRenderRegion`.
   - Correct the origin copy and offset order.
   - Preserve the physical title and `OnMovePane`/`OnResize` labels as superseded historical vocabulary.

9. `by-class/FittingRoomListPane.md`
   - Keep current score/metadata and blank class formal.
   - Correct the UID0002DG method row to the exact SetBounds source role and Y/X localization behavior.
   - Preserve every unrelated current list/scroll/item/preview fact.

10. `by-file/FittingRoom.md`
    - Keep current score/path/source inventory.
    - Add the bounded UID0002DG correction and preserve every unrelated current source-family fact.

11. `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md`
    - Keep `90/90` and all metadata.
    - Apply Destination 4.
    - Replace current non-historical `m_origin.x` claims with `m_origin.y`.
    - Historicalize the old X claim as superseded by the accepted Point layout.
    - Preserve every raw-route, rectangle, timer, resource, payload, and negative-evidence fact.

12. `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md`
    - Keep `91/92` and all metadata.
    - Apply Destination 5.
    - Replace current non-historical `m_origin.x` claims with `m_origin.y`.
    - Preserve all callback-facet, timer, layer, parcel handoff, score, and negative evidence.

13. `by-class/FlyingParcelPane.md`
    - Keep `88/91` and blank class formal.
    - Correct current StartAnimation/AnimateStep origin component claims.
    - Preserve complete class method/layout/resource/history evidence.

14. `by-file/ParcelPane.md`
    - Keep `91/92`, route, and complete current source inventory.
    - Correct current StartAnimation/AnimateStep origin component claims.
    - Preserve all concurrent parcel class/global/vtable/resource facts.

### Verify-only, no change absent contradiction

- UID0003XY `ObjectPaneSetObjectData`.
- UID00020R `ObjectPaneClearOutputRects`.
- executed UID0003HT report.
- RectGeometryHelpers.
- RectBounds class/layout.
- GrafPort class/file.
- PaneVtables.
- LoginDialog pointer handler.
- IMEComposition mouse handler.
- MapPane UID0004DS and MapPane class/file.
- ParcelNotificationPaneLayouts.
- ignored padding rows.
- generated outputs.
- manual coverage files.
- tracker/audit/supervisor/lifecycle files.

## Score And Metadata Recommendation

| Destination | Current | Recommended | Metadata decision |
| --- | ---: | ---: | --- |
| UID0003XX | `85/90` | `92/94` | Preserve owner/emitter 00009R, true, blank position, Nested 0, path/title/range |
| UID0003XW | `86/90` | `92/94` | Preserve owner/emitter 00009R, true, blank position, Nested 0, path/title/range |
| UID0001D5 | `88/91` | unchanged | Preserve owner none, false, blank emitter/formal, Nested 0 |
| ObjectPane class | `92/94` | unchanged | Preserve complete formal byte-for-byte |
| ObjectPane file | `91/92` | unchanged | Preserve route/path |
| PaneLayout | `85/88` | unchanged | Prose precision only |
| Pane class/file | `90/91` | unchanged | Bounded inherited-state prose only |
| UID0002DG | `87/90` | unchanged | Correct body/signature, preserve metadata |
| FittingRoom class/file | current | unchanged | Bounded support prose |
| UID0002R6 | `90/90` | unchanged | Correct one component, preserve metadata |
| UID0002KK | `91/92` | unchanged | Correct one component, preserve metadata |
| FlyingParcel class | `88/91` | unchanged | Support prose only |
| ParcelPane file | `91/92` | unchanged | Support prose only |

Target completion rises because the exact body, field expressions, helper names, slot identities, and compiler boundary are now complete. Target confidence rises because exact bytes, vtable fanout, callers, layout, and multiple consumers independently agree. Scores remain below 95 because original lexical spelling is inferred.

## Open Questions With Attempted Resolution

1. **Is the target `SetBounds` or `UpdateBounds`?**
   - Resolved: primary slot `+0x2c` is `SetBounds`; current ObjectPane declaration agrees.

2. **Is UID0003XW `SetBounds`?**
   - Resolved: no. Primary slot `+0x0c` is `UpdateRenderRegion`.

3. **Does the target compare directly against local bounds?**
   - Resolved: no. It first dispatches `GetScreenBounds`.

4. **What is `+0xac`?**
   - Resolved: `m_origin.y`, the first member of `Point { y, x }`.

5. **What is `+0xb0`?**
   - Resolved: `m_origin.x`.

6. **What is `+0x44`?**
   - Resolved: inherited `GrafPort::m_visibleBounds`.

7. **Should target call free `OffsetRect` or member `RectBounds::Offset`?**
   - Resolved: target calls `0x004b78f0`, the accepted member `RectBounds::Offset`. Pane base/FittingRoom call the separate free helper at `0x004b7e10`.

8. **Can base `Pane::SetBounds` express the target?**
   - Resolved: no. The base dispatches an update hook and lacks ObjectPane's downstream object-data copy.

9. **Is second argument clip/dirty state?**
   - Resolved: no. It is object-data bounds, selected into a local passed to `SetObjectData`.

10. **Can the second pointer be forwarded directly?**
    - Resolved: no. Exact binary copies into a local first.

11. **Does target return the final virtual result?**
    - Resolved: no source return contract; setter is void.

12. **Are sibling X/Y contradictions ignorable history?**
    - Resolved: no. They are current formal/prose contradictions and have exact bounded corrections.

13. **Is a rare no-improvement disposition warranted?**
    - Resolved: no. All target blockers close with existing source-facing types, members, and helpers.

No in-scope question remains as a future investigation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The following is immutable handoff text supplied by B005. B005 does not edit manual coverage. External application/current lifecycle state is not asserted by this report.

### `by-memory/-coverage-report.md`

Replace the UID0001D5 row with:

```text
    - [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md) 0x005372d0-0x005378fa | class aggregate | ObjectPane : reconstructable : 88% : very-strong : Reviewed non-emitting ObjectPane split/index with exact constructor/destructor/accessor/attachment/sound/bounds/object-data/map-position children, complete padding inventory, scattered virtual linkage, field/type directions, subclass vtable/caller liveness, and source/class routing; exact children own source, including source-ready UID0003XW UpdateRenderRegion and UID0003XX SetBounds.
```

Insert after UID0003XU and before UID0003XX:

```text
        - [UID:0003XW][0x00537740-0x00537751.ObjectPaneSetBounds](by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md) 0x00537740-0x00537751 | ObjectPane virtual method | ObjectPaneSetBounds : reconstructable : 92% : very-strong : Exact source-bearing ObjectPane UpdateRenderRegion override at primary slot +0x0c; copies the 16-byte RectBounds argument into inherited GrafPort::m_visibleBounds, while the physical ObjectPaneSetBounds slug remains historical/search vocabulary and movups is compiler lowering.
```

Replace UID0003XX with:

```text
        - [UID:0003XX][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md) 0x00537760-0x005377f2 | ObjectPane virtual method | ObjectPaneUpdateBounds : reconstructable : 92% : very-strong : Exact source-bearing ObjectPane SetBounds override at primary slot +0x2c; obtains current screen bounds, compares them with paneBounds, stores Point m_origin as top/Y then left/X and localizes inherited GrafPort::m_visibleBounds only when changed, then passes objectDataBounds or the paneBounds fallback through SetObjectData; the physical slug is historical/search vocabulary and cookie/SIMD/vtable mechanics are compiler-generated.
```

Replace UID0002DG with:

```text
        - [UID:0002DG][0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane](by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md) 0x0041ed90-0x0041ee03 | method | FittingRoomListPaneOnMovePane : reconstructable : 87% : very-strong : Exact source-facing FittingRoomListPane SetBounds override; initializes Point origin from top/Y and left/X, copies it to inherited m_origin in Y/X order, localizes a RectBounds with dx=-x and dy=-y, and dispatches UpdateRenderRegion, while historical OnMovePane/OnResize labels remain search vocabulary.
```

Replace UID0002R6 with:

```text
        - [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) 0x00546bc0-0x00546d64 | raw class method | FlyingParcelPane start animation : reconstructable : 90% : strong : Source-ready StartAnimation configures parcel/letter payload, EPF/legacy rectangles, layer attachment, optional sample 200 at volume 100, inherited Pane m_origin.y adjustment by 30 in the EPF path, invalidation, and 10/100 ms timer scheduling while preserving raw-start no-direct-route evidence as a confidence cap.
```

Replace UID0002KK with:

```text
    - [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md) 0x00546d70-0x00546dee | class method | FlyingParcelPaneAnimateStep : reconstructable : 91% : very-strong : Source-ready tertiary timer callback decrements inherited Pane m_origin.y while frame is below 30, invalidates and reschedules at 10 ms, then removes the animation layer, forwards parcel slot data, enables the parcel action, and invalidates g_pParcelPane.
```

### `by-class/-coverage-report.md`

Replace UID00009R with:

```text
- [UID:00009R][ObjectPane](by-class/ObjectPane.md) : reconstructable : 92% : very-strong : Complete abstract 0x128 ObjectPane declaration over Pane with exact ObjectPaneType constants 0..11, inline public GetObjectType/GetObjectId accessors, ObjectList/MapPane friendship, exact map/bounds/attachment/sound/transient layout, established methods/default virtuals, exact paneBounds/objectDataBounds ClearOutputRects and SetBounds contracts, source-ready base ClearOutputRects, source-ready UpdateRenderRegion and SetBounds bodies using inherited GrafPort::m_visibleBounds and Point m_origin, downstream SetObjectData flow, implicit padding, and compiler-vtable coverage.
```

Replace UID0000A2 with:

```text
- [UID:0000A2][Pane](by-class/Pane.md) : reconstructable : 90% : very-strong : Base UI Pane with exact constructor/destructor/core child inventory, primary/secondary/tertiary vtable contracts, layer/event/timer/deferred-deletion relationships, inherited GrafPort m_visibleBounds, Point m_origin with y at +0xac and x at +0xb0, GetScreenBounds and SetBounds localization behavior, resolved SetMode/GetDescription/Collapse children, caller evidence, compiler exclusions, and a deliberately blank broad class formal pending unrelated whole-class declaration work.
```

Replace UID000058 with:

```text
- [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md) : reconstructable : 88% : very-strong : Parcel/letter flying-animation helper class with exact Pane-derived layout, secondary/tertiary callback normalization, payload/layer/timer fields, constructor/destructor/start/step/draw source children, resources/globals, raw-route negatives, and corrected inherited Pane m_origin.y use at owner +0xac while all derived payload begins at +0xf8.
```

### `by-file/-coverage-report.md`

Replace UID0000M5 with:

```text
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md) : reconstructable : 91% : very-strong : NexusTK/map/ObjectPane.cpp and reconstructed ObjectPane.h route for the complete 0x128 declaration, ObjectPaneType enum, ObjectList/MapPane friendship, exact child methods/layout/default virtuals, SoundObjectPane ownership, exact paneBounds/objectDataBounds ClearOutputRects and SetBounds contracts, source-ready ClearOutputRects, source-ready UpdateRenderRegion and SetBounds bodies using inherited Pane/GrafPort state, downstream SetObjectData object-data flow, and compiler-only vtables without by-file reconstruction metadata.
```

Replace UID0000MC with:

```text
- [UID:0000MC][Pane](by-file/Pane.md) : reconstructable : 90% : very-strong : NexusTK/ui/core Pane source route with exact core-method split, layout/vtable families, layer/EventHandler/TimerHandler/deferred-deletion relationships, inherited GrafPort m_visibleBounds, Point m_origin with y at +0xac and x at +0xb0, GetScreenBounds/SetBounds/UpdateRenderRegion contracts, source-ready SetMode/GetDescription/Collapse children, compiler-only wrappers/thunks, and a deliberately blank broad class formal for unrelated remaining whole-file reconstruction.
```

Replace UID0000MF with:

```text
- [UID:0000MF][ParcelPane](by-file/ParcelPane.md) : reconstructable : 91% : very-strong : Parcel notification UI source root with three-class grouping, complete Pane plus Singleton<ParcelIconPane> declaration and child route, corrected singleton lifecycle, source-authored method separation from compiler-generated scalar wrappers/thunks/EH support, exact globals/vtables/layout/resources and PatchPane boundary, source-ready FlyingParcel start/step/draw behavior with inherited Pane m_origin.y at +0xac, and bounded file-wide caveats for unrelated ParcelPane/FlyingParcelPane declaration and helper API spelling.
```

### `by-type/-coverage-report.md`

Replace UID0001VH with:

```text
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) : reconstructable : 85% : very-strong : Pane/GrafPort inherited layout through the +0xf8 derived boundary; +0x44 is GrafPort m_visibleBounds, +0xac/+0xb0 are Point m_origin.y/m_origin.x in the accepted y-then-x Point order, and GetScreenBounds/SetBounds plus ObjectPane, LoginDialog, IMEComposition, MapPane, FittingRoom, and FlyingParcel consumers prove the source expressions while all handler/layer/region/visibility/motion/deletion evidence remains intact.
```

### `by-type/by-struct/-coverage-report.md`

Replace UID0001VH with:

```text
- [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) : reconstructable : 85% : very-strong : Pane base layout attached to [UID:0000A2][Pane](by-class/Pane.md); exact inherited state includes GrafPort m_visibleBounds at +0x44 and Point m_origin with y at +0xac and x at +0xb0, corroborated by Pane SetBounds/GetScreenBounds and ObjectPane, LoginDialog, IMEComposition, MapPane, FittingRoom, and FlyingParcel consumers, while all vtable, handler, layer, region, visibility, mode, deletion, motion, derived-boundary, and remaining-name evidence is preserved.
```

### Verify-only manual rows

- FittingRoom class/file rows: current broad descriptions contain no conflicting X/Y assertion; verify-only.
- RectBounds, GrafPort, RectGeometryHelpers, MapPane, LoginDialog, and IME rows: no coverage replacement required for this bounded work.
- Tracker row is validator-generated and must not be edited manually.

## Follow-Up Actions

- B005's accepted implementation callback responsibilities are complete in this artifact.
- The durable return marker is `READY_FOR_SUPERVISOR_GATE2_REVIEW`.
- The exact supervisor-owned manual coverage handoff below remains available for external application; B005 did not edit coverage.
- External Gate 2, coverage application, execution, path movement, archive, tracker, and lifecycle state remain authoritative only in current validator/supervisor-owned artifacts.

## Confidence

- Target range/bytes/hash/padding: 99%.
- ABI/CFG/instruction behavior: 98%.
- ObjectPane ownership and source placement: 99%.
- Vtable slot identities: 98%.
- `paneBounds`/`objectDataBounds` contract: 99%.
- `m_visibleBounds` expression: 98%.
- `Point m_origin` Y/X order: 98%.
- Complete target source shape: 96%.
- Exact original lexical spellings: 88%.
- Recommended target score: `92/94`.

## Validator Results

- Historical report-only phase: no implementation validator ran before Gate 1.
- Completed callback scoped validators, all `exit 0`, `ok:1`, with each destination leased only for its edit/validation and released immediately afterward:

| Command | Timestamp | Ordinary destination | Result / notable side effects |
| --- | --- | --- | --- |
| `000000013967` | `2026-07-16T12:36:12-04:00` | UID0003XX | pass; autogen registry/reference/projected-stats updates; generated refresh deferred |
| `000000013969` | `2026-07-16T12:36:43-04:00` | UID0003XW | pass; existing UID registration/path mapping refreshed; generated deferred |
| `000000013970` | `2026-07-16T12:37:14-04:00` | UID0001D5 | pass; pre-existing missing-reference warnings; generated deferred |
| `000000013972` | `2026-07-16T12:37:48-04:00` | by-class/ObjectPane.md | pass; pre-existing older-child reference warnings; generated deferred |
| `000000013973` | `2026-07-16T12:38:18-04:00` | by-file/ObjectPane.md | pass; pre-existing older-child reference warnings; generated deferred |
| `000000013975` | `2026-07-16T12:38:50-04:00` | PaneLayout | pass; reference/stats refresh; generated deferred |
| `000000013977` | `2026-07-16T12:39:23-04:00` | by-class/Pane.md | pass; generated deferred |
| `000000013979` | `2026-07-16T12:39:51-04:00` | by-file/Pane.md | pass; two pre-existing UID0003CA warnings; generated deferred |
| `000000013982` | `2026-07-16T12:41:33-04:00` | UID0002DG | pass; registry/stats refresh; generated deferred |
| `000000013983` | `2026-07-16T12:42:11-04:00` | by-class/FittingRoomListPane.md | pass; generated deferred |
| `000000013984` | `2026-07-16T12:42:38-04:00` | by-file/FittingRoom.md | pass; four pre-existing UID0003AM warnings; generated deferred |
| `000000013985` | `2026-07-16T12:43:20-04:00` | UID0002R6 | pass; registry/stats refresh; generated deferred |
| `000000013986` | `2026-07-16T12:43:52-04:00` | UID0002KK | pass; one pre-existing UID0003A1 warning; generated deferred |
| `000000013987` | `2026-07-16T12:44:25-04:00` | by-class/FlyingParcelPane.md | pass; generated deferred |
| `000000013988` | `2026-07-16T12:45:06-04:00` | by-file/ParcelPane.md | pass; generated deferred |

- Final authorized waited refresh: command `000000013989`, timestamp `2026-07-16T12:45:15-04:00`, `exit 0`, `ok:1`, `generated_refresh: completed`. Validator-owned side effects included registry rebuild, generated metadata/coverage refresh, reference insertion, and projected stats; B005 did not edit those files manually.
- Generated readback at command/header `000000013989`:
  - `auto-generated/NexusTK/map/ObjectPane.cpp` SHA256 `8FEF554BFB8FD61275340B2BEAFFE4F40A4EFBC7116CCAFEE55A16C5D127317F`: one UID0003XW `UpdateRenderRegion`, one UID0003XX `SetBounds`, zero target empty markers, unchanged closed ObjectPane shell, and no cookie/SIMD/vtable/thunk/decompiler source.
  - `auto-generated/NexusTK/cashshop/FittingRoom.cpp` SHA256 `A1D5D2FB233FF0A0A6EADE7E78EEB2414722E9C1600030098379D19C0D61DE50`: one UID0002DG `SetBounds`, correct Y/X initialization and X/Y offset, no stale `OnMovePane` definition.
  - `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` SHA256 `1AE96AB438EBBF67559B6B407DB16378BA2CB01187976275566F471B8F8A094E`: UID0002R6 and UID0002KK remain non-emitting in current generation; no `m_origin.x` or conflicting target body is present.
- Five destination formals are balanced and match the accepted report blocks. The by-class/ObjectPane managed class declaration was not edited and generated class-shell readback remains correctly closed.
- No manual coverage, tracker, audit, supervisor, validator-state, queue, lock, IDA, or lifecycle file was manually changed. No B005 lease remains.

## Changed Files

Callback artifact updated:

- `tools/leaser/Agents/Agent-B005/research/0003XX-ObjectPaneUpdateBounds-source-quality.md`

Changed ordinary destinations and current SHA256:

| Path | SHA256 |
| --- | --- |
| `by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md` | `8940B28BDCE59C252165099F48B83B138360D92E680557EF7D461D3A2BF3B1D0` |
| `by-memory/0x00537740-0x00537751.ObjectPaneSetBounds.md` | `616122E0A80D2C862D4F2AF4E512F76A201511406D586CDF011AE70CB04D6A41` |
| `by-memory/0x005372d0-0x005378fa.ObjectPane.md` | `1EE9B42DD503E4E599D73AB34C70B1A62DA0C7B6D39C284BCAC4E70A1DF17A1D` |
| `by-class/ObjectPane.md` | `3F0696892D81218334EC401F25BB435FBF35AEEB8331D57D2755F4F58EE922A0` |
| `by-file/ObjectPane.md` | `A7119D0773D60321324DE82B52EAF2DC1CF8CFFBFDA6489B84BAC08BB6700D84` |
| `by-type/by-struct/PaneLayout.md` | `93749A6EEF74D1BBBDCACF0D4BAE1476C086105133C4D0E4A3429D9C928AFE89` |
| `by-class/Pane.md` | `066658E7129E4FF309627DFE26DFD7F79167187080FD21E534D3DD24645256EF` |
| `by-file/Pane.md` | `439E13ADADBB9385627BB195FE942479153C3C23A8F05478C42BACBC10045F54` |
| `by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md` | `0BF120038B09E83D949BA9AAA5D4269B4C230FA195EE239DC28312569224F2A9` |
| `by-class/FittingRoomListPane.md` | `CEE6363F91A1D5FA0A5B74D018ADE97301DC397EDA6A6B4FA2129DF4BA51029B` |
| `by-file/FittingRoom.md` | `1B7732AB9F25CAD96D8A33753E2E1CF68522949CEE6C7273B5AA63E573F74812` |
| `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md` | `4685034D78360DB4659CE04155A8E92E83634850A177DE7A531C1BE573119F78` |
| `by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md` | `03E8D9B1761AC29AF57F7A8FAAFAE4AC7DA7D43CEC56CEDCB9EFC9C9B649E29D` |
| `by-class/FlyingParcelPane.md` | `5E119DA9054EDB05BE4D34DFBBB91C967D3075328EE528F373EC847DF47EFCF3` |
| `by-file/ParcelPane.md` | `81F17923E3667DD105DBFC8BC7084B5C18E1CCCA0C9697451A6785598C8066BA` |

Verify-only paths listed under Recommended Support Doc Changes were reread and required no edit. Restricted/generated/manual artifacts were not manually changed; generated hashes above are validator-owned readback.

## Implementation Tracking Checklist

- [x] Re-read the accepted report and current target immediately before callback edits.
- [x] Re-read each ordinary destination immediately before acquiring its lease.
- [x] Acquire only one ordinary-file lease at a time.
- [x] Apply C01-C40 without compression.
- [x] Update UID0003XX to `92/94` and preserve all other metadata.
- [x] Apply Destination 1 exactly.
- [x] Apply the exact UID0003XX Item Summary.
- [x] Preserve target path/title/range and `Nested:0`.
- [x] Update UID0003XW to `92/94` and preserve all other metadata.
- [x] Apply Destination 2 exactly.
- [x] Apply the exact UID0003XW Item Summary.
- [x] Preserve UID0003XW physical slug as historical/search vocabulary.
- [x] Update UID0001D5 child rows without changing aggregate metadata/formal/nesting.
- [x] Rebase by-class/ObjectPane.md without changing its managed class block.
- [x] Rebase by-file/ObjectPane.md without losing concurrent ObjectPane detail.
- [x] Update PaneLayout with exact `Point m_origin` Y/X order and preserve score/formal.
- [x] Update Pane class with bounded inherited-state prose and preserve score/formal.
- [x] Update Pane file with bounded inherited-state prose and preserve score/route.
- [x] Apply Destination 3 exactly to UID0002DG.
- [x] Preserve UID0002DG score/metadata/path/title.
- [x] Rebase FittingRoomListPane class without losing unrelated list/scroll/item evidence.
- [x] Rebase FittingRoom file without losing unrelated source inventory.
- [x] Apply Destination 4 exactly to UID0002R6.
- [x] Preserve UID0002R6 score/metadata and all raw-route/resource/timer evidence.
- [x] Apply Destination 5 exactly to UID0002KK.
- [x] Preserve UID0002KK score/metadata and all callback/layer/parcel evidence.
- [x] Rebase FlyingParcelPane class without losing unrelated layout/method/history.
- [x] Rebase ParcelPane file without losing unrelated class/global/vtable/resource detail.
- [x] Verify UID0003XY remains unchanged.
- [x] Verify UID00020R and executed UID0003HT remain unchanged.
- [x] Verify RectGeometryHelpers, RectBounds, GrafPort, PaneVtables, LoginDialog, IMEComposition, MapPane, ParcelNotificationPaneLayouts, and ignored padding remain same-or-greater.
- [x] Run one scoped file validator for each changed ordinary page while its lease is held.
- [x] Record every validator command ID, timestamp, exit code, ok count, warnings, and side effects.
- [x] Release each lease immediately after its scoped validator.
- [x] Run one final authorized `--wait-generated` refresh after all ordinary edits validate.
- [x] Verify ObjectPane.cpp has exactly one UID0003XW `UpdateRenderRegion` definition.
- [x] Verify ObjectPane.cpp has exactly one UID0003XX `SetBounds` definition.
- [x] Verify ObjectPane.cpp has zero UID0003XW/UID0003XX empty markers and no cookie/SIMD/vtable/decompiler source.
- [x] Verify the ObjectPane class shell/declaration remains unchanged.
- [x] Verify FittingRoom.cpp has exactly one UID0002DG source-facing SetBounds definition with correct Y/X order and no stale OnMovePane body.
- [x] Verify ParcelPane generated disposition and record whether UID0002R6/UID0002KK remain non-emitting or become emitted; in either case verify no current `.x` claim/body survives for owner `+0xac`.
- [x] Record all changed ordinary hashes and final generated hashes/headers.
- [x] Preserve the exact manual coverage handoff text without editing coverage.
- [x] Update C01-C40 to legal callback final states with destination-specific proof.
- [x] Update Validator Results, Changed Files, Current Target State, Follow-Up Actions, and checklist to durable callback truth.
- [x] Confirm no brace token, placeholder UID, raw offset, decompiler label, synthetic accessor, or unresolved blocker remains.
- [x] Confirm no ordinary lease remains.
- [x] Do not edit generated, manual coverage, tracker, audit, supervisor, registry, queue, lock, or lifecycle files manually.
- [x] Do not mutate IDA.
- [x] Do not run or probe `execute_report`.
- [x] Do not run report move/archive/lifecycle commands.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000014040","destination_path":"executed-b-agent-research/B005/0003XX-ObjectPaneUpdateBounds-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003XX-ObjectPaneUpdateBounds-source-quality.md","timestamp":"2026-07-16T13:04:35-04:00","uid":"0003XX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
