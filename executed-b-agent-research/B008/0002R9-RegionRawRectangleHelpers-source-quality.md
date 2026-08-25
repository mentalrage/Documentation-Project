** TARGET-REPORT-UID:0002R9 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002R9 Region Raw Rectangle Helpers Source-Quality Research


Assignment: `B008-report-0002R9-region-raw-rectangle-helpers-20260626`  
Agent: `Agent-B008`  
Mode: report-only research first; no by-* target/support edits, generated edits, coverage edits, validator state/cache edits, or IDA database edits performed.  
Target: [UID:0002R9] `by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md`  
Required report path: `tools/leaser/Agents/Agent-B008/research/0002R9-RegionRawRectangleHelpers-source-quality.md`

## Executive Conclusion

The current page is a real source-authored dirty-rectangle helper pocket, but it should not remain an emitting aggregate. It mixes four independent source methods plus three internal `0xcc` alignment spans. The implementation callback should convert [UID:0002R9] into a non-emitting split index and create four exact child by-memory pages with formal C++:

| Child range | Proposed page | Source-facing method | Owner/emitter | Position | Score |
| --- | --- | --- | --- | ---: | --- |
| `0x00554a20-0x00554a3c` | `by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md` | `Motion::Intersects` | [UID:0000N3] `Region` / `Region.cpp` | `70` | `87/90` |
| `0x00554a40-0x00554a56` | `by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md` | `Motion::ContainsRect` | [UID:0000N3] `Region` / `Region.cpp` | `71` | `88/90` |
| `0x00554a60-0x00554a9b` | `by-memory/0x00554a60-0x00554a9b.MotionContains.md` | `Motion::Contains` | [UID:0000N3] `Region` / `Region.cpp` | `72` | `89/91` |
| `0x00554aa0-0x00554adb` | `by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md` | `Motion::HasSameBoundsAs` | [UID:0000N3] `Region` / `Region.cpp` | `73` | `87/90` |

Recommended parent [UID:0002R9] metadata after split:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `88` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000N3` | `NONE` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000N3` | blank |
| `EMITTER_POSITION_OPTIONAL` | blank | blank |
| C++ | blank | blank |
| `Nested` | `4` | `4` |

Parent no-code proof: the parent is a split index over four source methods and internal padding. Emitting C++ on the parent would duplicate the child bodies and combine non-source alignment bytes with source functions. Exact source-unit boundaries are the child method pages; the parent should only preserve the range evidence, padding map, rejected routes, and child index.

The old blocker "Region/Motion names and lower-level helper names are not final" is resolved enough for first-draft C++. Current live IDA MCP confirms the behavior, accepted support docs already use `Motion &last` and `Region incoming` in `MapPane::QueueMotionMessage`, and support docs can be repaired in the same implementation callback to state that `Region.cpp` owns a dirty-region `Motion` helper/record family distinct from the timer-driven animation `Motion` bucket.

## Current Target State

[UID:0002R9] currently has:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000N3`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N3`
- blank formal C++
- `Nested:4`

The existing row table correctly identifies the raw starts and internal padding, but the `0x00554a40` behavior wording is directionally wrong. Live primitive decompilation proves `RectContainsRect` receives the tested inner rectangle first and the containing outer rectangle second. Therefore `0x00554a40` tests whether this dirty-region object contains the supplied raw rectangle, not whether an external rectangle contains this object.

## Evidence Read

Direct target and support docs read or rechecked:

| Item | Use |
| --- | --- |
| `tools/leaser/Agents/Agent-B008/goal.md` | Current assignment, report-only mode, MCP requirement, no-edit rules, source-quality blockers. |
| `by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md` | Current target metadata, row table, existing raw/no-function evidence, blank-C++ blocker. |
| `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` | Aggregate Region/Motion dirty-rectangle island, layout, predecessor/successor context, lower-level callees, current mixed naming caveat. |
| `by-file/Region.md` and `by-class/Region.md` | Current [UID:0000N3] owner route, Region constructor/destructor/dirty-region role, existing Motion-named helper note. |
| `by-file/Motion.md` and `by-class/Motion.md` | Split-owner guard: timer-driven animation `Motion` remains in `NexusTK/render/Motion.cpp`; dirty-rectangle helpers belong with `Region.cpp`. |
| `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` | Lower-level `IntersectRects`, `RectsEquivalent`, and `RectContainsRect` free helper roles. |
| `by-file/RectBounds.md`, `by-class/RectBounds.md`, `by-type/by-struct/RectBoundsLayout.md` | `RectBounds` four-int layout, class/free-helper split, `left/top/right/bottom` field names, shared geometry source route. |
| `by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md` | Accepted first-draft C++ using `Region incoming`, `Motion &last`, `last.Contains(incoming)`, `incoming.Contains(last)`, and `CopyRectFrom`. |
| `by-class/MapPane.md` | Deferred motion record fields at `+0x118`, `+0x398`, and `+0x39c`; confirms `Motion` dirty-record usage. |
| `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md` | Generated rows are stale and must be refreshed by validators/executed-report flow, not hand-edited. |

Generated/read-only files were read only. No generated report, coverage report, project-level generated file, validator cache/state, or IDA database file was edited.

## Live IDA MCP Session

IDA MCP was available and used. This is not a fallback-only report.

| Evidence | Result |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Port check | `Test-NetConnection 127.0.0.1:13337` returned `TcpTestSucceeded: True` |
| Tool schema check | `tools/list` returned `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, and `get_bytes`; no `py_eval` or `callers` tool was exposed in this session, so xref/callee queries were used instead. |
| Active database | `idb_list` session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active, worker PID `26892`, not analyzing |
| Health | `server_health` at `2026-06-26T01:21:05` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, auto-analysis ready, Hex-Rays ready, strings cache ready |

The report uses only successful read-only MCP calls. No IDA-side rename, type edit, comment edit, or database mutation was performed.

## Function Map, Padding, And Boundary Evidence

Live `lookup_funcs` against session `80de0a67`:

| Query | IDA result |
| --- | --- |
| `0x00554a18` | not a function |
| `0x00554a20` | not a function |
| `0x00554a3c` | not a function |
| `0x00554a40` | not a function |
| `0x00554a56` | not a function |
| `0x00554a60` | `sub_554A60`, size `0x3b`, exact range `0x00554a60-0x00554a9b` |
| `0x00554a9b` | not a function |
| `0x00554aa0` | not a function |
| `0x00554adb` | not a function |
| `0x00554ae0` | `sub_554AE0`, size `0x11`, exact range `0x00554ae0-0x00554af1` |
| `0x00554b00` | `sub_554B00`, size `0x38`, exact range `0x00554b00-0x00554b38` |
| `0x00554b38` | not a function |

Live `get_bytes 0x00554a18 size 200` confirms:

- `0x00554a18-0x00554a20`: eight `0xcc` bytes before the target.
- `0x00554a20-0x00554a3c`: raw prologue/body ending with `c2 04 00`.
- `0x00554a3c-0x00554a40`: four `0xcc` bytes.
- `0x00554a40-0x00554a56`: raw prologue/body ending with `c2 04 00`.
- `0x00554a56-0x00554a60`: ten `0xcc` bytes.
- `0x00554a60-0x00554a9b`: modeled stack-copy containment wrapper ending with `c2 04 00`.
- `0x00554a9b-0x00554aa0`: five `0xcc` bytes.
- `0x00554aa0-0x00554adb`: raw stack-copy equivalence wrapper ending with `c2 04 00`.
- `0x00554adb-0x00554ae0`: five `0xcc` bytes before successor `Motion::GetRect` at `0x00554ae0`.

Implementation should preserve parent child rows as exact half-open ranges plus internal padding rows:

| Parent row | Disposition |
| --- | --- |
| `0x00554a20-0x00554a3c` | child `MotionIntersectsRaw` |
| `0x00554a3c-0x00554a40` | internal `0xcc` alignment padding |
| `0x00554a40-0x00554a56` | child `MotionContainsRectRaw` |
| `0x00554a56-0x00554a60` | internal `0xcc` alignment padding |
| `0x00554a60-0x00554a9b` | child `MotionContains` |
| `0x00554a9b-0x00554aa0` | internal `0xcc` alignment padding |
| `0x00554aa0-0x00554adb` | child `MotionHasSameBoundsAsRaw` |

Do not create a separate parent row for `0x00554adb-0x00554ae0`; it is successor alignment outside [UID:0002R9] and should be documented as the post-target padding before `0x00554ae0`.

## Disassembly And Behavior

Live `disasm 0x00554a20` shows:

| Range | Instruction-level behavior |
| --- | --- |
| `0x00554a20-0x00554a3c` | `ecx+4` and `[arg]+4` are passed to `sub_4B7CC0`; third output argument is zero; function returns with `retn 4`. |
| `0x00554a40-0x00554a56` | pushes `ecx+4` as the second argument and the stack argument as the first argument to `sub_4B7F30`; returns with `retn 4`. |
| `0x00554a60-0x00554a9b` | copies `*(arg+4)` to a 16-byte stack local, passes local first and `ecx+4` second to `sub_4B7F30`, checks the security cookie, and returns with `retn 4`. |
| `0x00554aa0-0x00554adb` | copies `*(arg+4)` to a 16-byte stack local, passes local first and `ecx+4` second to `sub_4B7ED0`, checks the security cookie, and returns with `retn 4`. |

Live `decompile 0x00554a60`:

```c
bool __thiscall sub_554A60(_DWORD *this, int a2)
{
  __int128 v3; // [esp+0h] [ebp-14h] BYREF

  v3 = *(_OWORD *)(a2 + 4); /*0x554a7f*/
  return sub_4B7F30(&v3, this + 1); /*0x554a8e*/
}
```

The stack copy in `0x00554a60` and `0x00554aa0` should be represented as a local `RectBounds bounds = motion.m_bounds;`. It is source-safe because it matches the compiler materialization and avoids taking a pointer directly into another object when the binary used a stack record.

## Xrefs And Reachability

Live `xrefs_to` at `2026-06-26T01:21:29`:

| Address | Xrefs | Interpretation |
| --- | ---: | --- |
| `0x00554a20` | 0 | raw retained helper, no direct current route |
| `0x00554a40` | 0 | raw retained helper, no direct current route |
| `0x00554a60` | 4 | live modeled `Motion::Contains` helper |
| `0x00554aa0` | 0 | raw retained helper, no direct current route |
| `0x00554ae0` | 10 | successor `Motion::GetRect`, outside target, proves boundary and broader dirty-region fanout |
| `0x004b7ed0` | 7 | includes raw target call at `0x554ac3` |
| `0x004b7f30` | 2 | exactly the raw target call at `0x554a4a` and modeled target call at `0x554a83` |

The four `0x00554a60` code xrefs are:

- `0x504763` in `sub_5046D0`, [UID:0002QG] `MapPane::QueueMotionMessage`
- `0x504770` in `sub_5046D0`, [UID:0002QG] `MapPane::QueueMotionMessage`
- `0x54486f` in `sub_544800`, Pane dirty/motion immediate handling route
- `0x54495c` in `sub_544940`, Pane dirty/motion notification/update route

Raw starts with zero direct xrefs are not no-code proof. They are normal source-shaped bodies between alignment spans, share the same receiver layout and primitive helper family as the live `0x00554a60` method, and sit inside the Region/Motion dirty-rectangle island. Zero xrefs cap liveness confidence but do not justify leaving exact source-owned child bodies blank.

## Lower-Level Rectangle Helper Roles

Live MCP decompilation resolves the lower-level helper semantics enough for formal C++:

| Helper | Live behavior | Source-facing support decision |
| --- | --- | --- |
| `0x004b7cc0` / `sub_4B7CC0` | Rejects empty inputs, writes intersection to output if output is non-null, clears optional output on failure, returns success. | `IntersectRects(const RectBounds *a, const RectBounds *b, RectBounds *outBounds)`; `outBounds` may be `NULL`. |
| `0x004b7ed0` / `sub_4B7ED0` | Treats two empty/invalid rectangles as equivalent; otherwise compares all four edges. | `RectsEquivalent(const RectBounds *a, const RectBounds *b)`. |
| `0x004b7f30` / `sub_4B7F30` | If first argument is empty, returns true. Otherwise requires the second argument to be non-empty and to contain the first argument. | `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)`. |

The last point repairs the prior target wording: `0x00554a40` calls `RectContainsRect(bounds, &m_bounds)`, so it asks whether this object's stored bounds contain the supplied raw rectangle. `0x00554a60` calls `RectContainsRect(&bounds, &m_bounds)`, so it asks whether this object contains the other Motion/Region-style object.

## Ownership And Source Placement

Keep source ownership with [UID:0000N3] `Region` / `NexusTK/ui/core/Region.cpp`, not [UID:0000LL] `Motion` / `NexusTK/render/Motion.cpp`.

Positive ownership evidence:

- The target lies inside [UID:0001FW] `RegionAndMotionRect`, the contiguous `0x00554680-0x00554b38` Region/Motion dirty-rectangle island.
- The receiver layout is the Region/Motion dirty-region layout: object header or vptr/base at `+0x00`, `RectBounds` storage at `+0x04`.
- `by-file/Region.md` already owns this dirty-rectangle helper island and rejects lower-level `RectBounds` ownership for wrapper methods.
- [UID:0002QG] `MapPane::QueueMotionMessage` accepted formal C++ uses `Region incoming`, `Motion &last`, `last.Contains(incoming)`, and `incoming.Contains(last)`, proving source-facing dirty-rectangle `Motion` names are accepted enough for first-draft code.
- `by-file/Motion.md` and `by-class/Motion.md` already split timer-driven animation `Motion` from Region dirty-rectangle helpers and explicitly warn not to migrate every historical `Motion` label into the animation file.

Rejected alternatives:

| Alternative | Reason rejected |
| --- | --- |
| Timer-driven animation `Motion` owner [UID:0000LL]/[UID:00008R] | The animation class has distinct constructor/timer/destructor ranges, vtable/pool evidence, and render/timer callees. This target is in the Region dirty-rectangle island and is used by Pane/MapPane dirty-region paths. |
| `RectBounds.cpp` owner [UID:0000N2] | The child methods are object wrappers over a stored dirty-region `RectBounds` at receiver `+4`; `RectBounds.cpp` owns the primitive value type and free helpers, not the Region/Motion object wrapper methods. |
| Pane or MapPane feature ownership | Pane/MapPane are callers/consumers. The helper storage layout and adjacent method family are Region.cpp dirty-region infrastructure. |
| No-owner/non-emitting raw helper | Raw child bodies are source-shaped, bounded by `0xcc` alignment, call documented project helpers, and match the live modeled `Motion::Contains` family. |

## Region Versus Motion Naming Repair

The Region/Motion naming split is no longer a reason to leave C++ blank. The implementation callback should repair support docs as follows:

- In `by-file/Region.md`, add a dirty-region `Motion` helper/record note under the existing `Motion rectangle helpers` row. State that `Region.cpp` owns the Region construction/destruction plus Motion-prefixed dirty-rectangle methods over object offset `+0x04` `RectBounds m_bounds`.
- In `by-class/Region.md`, add that Region is layout-compatible with the dirty-region Motion helper family used by accepted `MapPane::QueueMotionMessage`; `Region incoming` can call `SetRect`, `Contains`, and `CopyRectFrom` through the same Region.cpp helper family.
- In `by-file/Motion.md` and `by-class/Motion.md`, preserve the animation source bucket but add a short non-conflict note: the `Motion::Intersects`, `Motion::ContainsRect`, `Motion::Contains`, and `Motion::HasSameBoundsAs` methods from [UID:0002R9] are dirty-region helper names owned/emitted by `Region.cpp`, not by the timer-driven animation `Motion` page.
- In `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md`, replace the single [UID:0002R9] raw-helper-cluster row with the split-child index after UIDs are assigned, and correct the `0x00554a40` containment direction.
- In `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, and optionally `by-class/RectBounds.md` / `by-file/RectBounds.md`, add the exact argument order `RectContainsRect(innerBounds, outerBounds)` and state that [UID:0002R9] supplies the only two current `RectContainsRect` refs at `0x554a4a` and `0x554a83`.

No new dirty-region class page is required for this implementation. The current repository already uses Region/Motion support pages to carry the split. Creating a new class page would be a broader declaration-normalization step and is not necessary to make these exact child bodies source-safe.

## Split Recommendation

Recommended parent [UID:0002R9] after implementation:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- blank `EMITTER_UIDS`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal C++
- retain `Nested:4`
- item summary: non-emitting split index for four Region.cpp dirty-region Motion rectangle helper children plus internal `0xcc` alignment padding.

The parent should preserve:

- current and new live MCP evidence;
- raw/no-function starts and `sub_554A60` modeled status;
- rejected Text/Pane/MapPane feature ownership routes;
- rejected timer-driven `Motion.cpp` route;
- rejected lower-level `RectBounds.cpp` route for object wrappers;
- raw start no-xref evidence;
- exact internal padding rows;
- successor `0x00554adb-0x00554ae0` alignment before `Motion::GetRect`.

## Exact Formal RECONSTRUCTION_CPP CODE Insertion Text

The following are exact formal insertion texts for the proposed child pages. They are not examples.

### `by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md`

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000N3`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N3`
- `EMITTER_POSITION_OPTIONAL:70`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool Motion::Intersects(const Motion &motion) const
{
    return IntersectRects(&m_bounds, &motion.m_bounds, NULL);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Disposition proof: formal C++ is ready. The raw body passes `this+4`, `arg+4`, and `0` to `IntersectRects` and returns its boolean/char result. The raw start has no direct xrefs, but it is a complete function-shaped source helper inside the dirty-region method family and has no compiler-only shape.

### `by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000N3`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N3`
- `EMITTER_POSITION_OPTIONAL:71`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool Motion::ContainsRect(const RectBounds *bounds) const
{
    return RectContainsRect(bounds, &m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Disposition proof: formal C++ is ready. The raw body pushes the stack argument first and `this+4` second to `RectContainsRect`. Live decompilation of `0x004b7f30` proves first argument is `innerBounds` and second argument is `outerBounds`, so this wrapper tests whether this object contains a supplied raw bounds record.

### `by-memory/0x00554a60-0x00554a9b.MotionContains.md`

Recommended metadata:

- `COMPLETION:89`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000N3`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N3`
- `EMITTER_POSITION_OPTIONAL:72`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool Motion::Contains(const Motion &motion) const
{
    RectBounds bounds = motion.m_bounds;
    return RectContainsRect(&bounds, &m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Disposition proof: formal C++ is ready. This is the one modeled child and has four live code xrefs, including two accepted calls in `MapPane::QueueMotionMessage`. The stack local is not decompiler noise: the binary copies the other object's 16-byte bounds into a stack record before calling `RectContainsRect`.

### `by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md`

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000N3`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N3`
- `EMITTER_POSITION_OPTIONAL:73`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool Motion::HasSameBoundsAs(const Motion &motion) const
{
    RectBounds bounds = motion.m_bounds;
    return RectsEquivalent(&bounds, &m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Disposition proof: formal C++ is ready. The raw body copies the other object's 16-byte bounds into a stack local, then calls `RectsEquivalent(local, this+4)`. `HasSameBoundsAs` is inferred source-facing spelling, but the behavior, type shape, ownership, and helper role are solved.

## Source-Quality Blockers Resolved

| Blocker named in assignment | Resolution |
| --- | --- |
| Raw/no-function starts | Live MCP reconfirmed `0x00554a20`, `0x00554a40`, and `0x00554aa0` are not IDA functions but are complete function-shaped source helpers between `0xcc` padding. Split into exact child pages with C++. |
| Modeled helper | `0x00554a60-0x00554a9b` is live `Motion::Contains`, with four code xrefs and accepted MapPane source usage. Child page gets formal C++. |
| Exact internal padding | Parent rows should preserve `0x00554a3c-0x00554a40`, `0x00554a56-0x00554a60`, and `0x00554a9b-0x00554aa0`; post-target `0x00554adb-0x00554ae0` is successor padding before `Motion::GetRect`. |
| Caller/reachability | Raw starts have zero direct xrefs; modeled child has four. Zero-xref raw bodies remain source-owned because byte shape, adjacency, and helper semantics prove retained source methods. |
| Lower-level rectangle helper roles | Live decompilation resolves `IntersectRects`, `RectsEquivalent`, and `RectContainsRect(inner, outer)`. Support update required for `RectContainsRect` argument order. |
| Source-facing names | Use `Motion::Intersects`, `Motion::ContainsRect`, `Motion::Contains`, and `Motion::HasSameBoundsAs`. Names are inferred but source-safe and match accepted dirty-region Motion naming style. |
| Region versus Motion split | Owner/emitter remains [UID:0000N3] `Region.cpp`; support docs should distinguish dirty-region `Motion` helper methods from timer-driven animation `Motion.cpp`. |
| Owner/emitter support | Parent becomes non-emitting; all four children emit through [UID:0000N3] at exact positions `70` through `73`. |
| Formal C++ readiness | All exact source-owned children have formal first-draft C++ above. No child is intentionally blank. |

## Generated State

Generated rows are stale and must not be hand-edited:

- `auto-generated/-ag-research-tracker.md` still shows [UID:0002R9] as `78/84`.
- `auto-generated/-ag-memory-coverage.md` shows [UID:0002R9] as emitting to `auto-generated/NexusTK/ui/core/Region.cpp`.
- `auto-generated/-ag-coverage-report-by-memory.md` shows stale `78%` text for [UID:0002R9].

Expected generated refresh after accepted implementation and validators:

- parent [UID:0002R9] should become non-emitting with four nested child pages;
- generated `Region.cpp` should receive child bodies from the four new exact child pages, not from the parent;
- research tracker/coverage rows should refresh through validator/executed-report/autogen flow only.

## Implementation Checklist For Callback

Implementation callback completed on 2026-06-26. All accepted by-* target/support details were applied at report-level detail, validators passed with generated refresh complete, and no accepted item remains blocked.

| Step | Result / proof |
| --- | --- |
| [x] Lease immediate edit files | Leased the parent, four child paths, and six support docs before by-* edits/validator application; all 11 lease requests returned `Success`. After validators, unlease returned `Rejected[No active lease]` for all B008 paths because the lease had already expired. The immediate post-release check of `tools/leaser/Agents/current_leases.md` showed `No active leases`; a later final check showed only unrelated B006 leases and no B008 lease entries. |
| [x] Update parent [UID:0002R9] | `by-memory/0x00554a20-0x00554adb.RegionRawRectangleHelpers.md` now has `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank C++, and `Nested:4`. The page is a non-emitting split index with exact half-open child rows and padding rows; live MCP evidence, raw no-xref facts, rejected owner routes, lower-helper evidence, and successor `0x00554adb-0x00554ae0` padding note are preserved. |
| [x] Create child 1 | Created [UID:00042Q] `by-memory/0x00554a20-0x00554a3c.MotionIntersectsRaw.md`, metadata `87/90`, owner/emitter `0000N3`, position `70`, report-level behavior/evidence/range/no-xref/source-route rationale, and formal C++ for `Motion::Intersects`. |
| [x] Create child 2 | Created [UID:00042R] `by-memory/0x00554a40-0x00554a56.MotionContainsRectRaw.md`, metadata `88/90`, owner/emitter `0000N3`, position `71`, report-level behavior/evidence/range/no-xref/source-route rationale, corrected containment direction, and formal C++ for `Motion::ContainsRect`. |
| [x] Create child 3 | Created [UID:00042S] `by-memory/0x00554a60-0x00554a9b.MotionContains.md`, metadata `89/91`, owner/emitter `0000N3`, position `72`, modeled function evidence, four xrefs, accepted MapPane route, stack-copy rationale, and formal C++ for `Motion::Contains`. |
| [x] Create child 4 | Created [UID:00042T] `by-memory/0x00554aa0-0x00554adb.MotionHasSameBoundsAsRaw.md`, metadata `87/90`, owner/emitter `0000N3`, position `73`, report-level behavior/evidence/range/no-xref/source-route rationale, and formal C++ for `Motion::HasSameBoundsAs`. |
| [x] Update `by-file/Region.md` | Added dirty-region `Motion` helper/record support, receiver `+0x04` `RectBounds m_bounds`, child method inventory with UIDs `00042Q` through `00042T`, MapPane queue compatibility, corrected `RectContainsRect(innerBounds, outerBounds)` note, and the guard that these methods remain Region.cpp-owned rather than animation `Motion.cpp`-owned. |
| [x] Update `by-class/Region.md` | Added Region/Motion dirty-rectangle layout compatibility, `SetRect`/`Contains`/`CopyRectFrom` compatibility notes, four child helper references, MapPane queue evidence, and updated the remaining-blocker row so the former raw pocket is no longer deferred future work. Existing constructor/destructor/vtable notes are preserved. |
| [x] Update `by-file/Motion.md` | Preserved timer-driven animation ownership and added a non-conflict note that [UID:0002R9] children `Motion::Intersects`, `Motion::ContainsRect`, `Motion::Contains`, and `Motion::HasSameBoundsAs` are Region.cpp dirty-rectangle helpers and should not migrate to animation `Motion.cpp`. |
| [x] Update `by-class/Motion.md` | Preserved animation class owner/emitter, added a dirty-rectangle non-conflict section with the four child UIDs, and documented that the [UID:0002R9] helper bodies emit through Region.cpp, not [UID:00008R]. |
| [x] Update aggregate `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md` | Replaced the single raw-helper pocket row with exact child and padding rows, linked UIDs `00042Q` through `00042T`, corrected `0x00554a40` containment direction, preserved aggregate blank C++ and Region.cpp route, and documented `0x00554adb-0x00554ae0` successor padding before `Motion::GetRect`. |
| [x] Update rectangle helper support | Updated `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` with `RectContainsRect(const RectBounds *innerBounds, const RectBounds *outerBounds)` and the two current direct containment-wrapper refs at `0x554a4a` ([UID:00042R]) and `0x554a83` ([UID:00042S]). `by-class/RectBounds.md` and `by-file/RectBounds.md` were not edited because they contain only generic `RectContainsRect` inventory/count references and no conflicting argument-order statement. |
| [x] Do not hand-edit generated files | No generated reports, project-level generated files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md` file was manually edited. Generated files were changed only by validator `--apply --wait-generated`; generated `auto-generated/NexusTK/ui/core/Region.cpp` now has validator-command-id `000000002113` and contains the four child C++ blocks. |
| [x] Run parent validator | Passed: `python .\tools\validator.py --mode file --file by-memory\0x00554a20-0x00554adb.RegionRawRectangleHelpers.md --apply --queue-timeout 240 --wait-generated`; command_id `000000002107`; timestamp `2026-06-26T01:53:54-04:00`; exit `0`; scanned markdown files `1`; generated_refresh `completed`. Validator frontend did not emit a separate ok-count field. |
| [x] Run child validators | Passed for all four child pages with `--apply --queue-timeout 240 --wait-generated`. UID assignment bootstrap: command_id `000000002102` assigned [UID:00042Q] and [UID:00042R]; command_id `000000002103` assigned [UID:00042S]; command_id `000000002104` assigned [UID:00042T]. Final child validators: [UID:00042Q] command_id `000000002106`, timestamp `2026-06-26T01:53:35-04:00`, exit `0`, generated_refresh `completed`; [UID:00042R] command_id `000000002103`, timestamp `2026-06-26T01:52:43-04:00`, exit `0`, generated_refresh `completed`; [UID:00042S] command_id `000000002104`, timestamp `2026-06-26T01:53:01-04:00`, exit `0`, generated_refresh `completed`; [UID:00042T] command_id `000000002105`, timestamp `2026-06-26T01:53:19-04:00`, exit `0`, generated_refresh `completed`. Each scanned `1` markdown file; validator frontend did not emit a separate ok-count field. |
| [x] Run support validators | Passed: `by-file\Region.md` command_id `000000002108`, timestamp `2026-06-26T01:54:10-04:00`, exit `0`, generated_refresh `completed`; `by-class\Region.md` command_id `000000002109`, timestamp `2026-06-26T01:54:27-04:00`, exit `0`, generated_refresh `completed`; `by-file\Motion.md` command_id `000000002110`, timestamp `2026-06-26T01:54:44-04:00`, exit `0`, generated_refresh `completed`; `by-class\Motion.md` command_id `000000002111`, timestamp `2026-06-26T01:55:00-04:00`, exit `0`, generated_refresh `completed`; `by-memory\0x00554680-0x00554b38.RegionAndMotionRect.md` command_id `000000002112`, timestamp `2026-06-26T01:55:18-04:00`, exit `0`, generated_refresh `completed`; `by-memory\0x004b7c30-0x004b7f87.RectGeometryHelpers.md` command_id `000000002113`, timestamp `2026-06-26T01:55:42-04:00`, exit `0`, generated_refresh `completed`. Each scanned `1` markdown file; validator frontend did not emit a separate ok-count field. |
| [x] Record validator proof | Recorded commands, command_ids, timestamps, exit codes, generated-refresh state, assigned child UIDs, generated `Region.cpp` refresh proof, queue state, diagnostics, files changed, optional RectBounds exclusion, and lease expiry proof in this checklist. |

Validator queue proof: final `python .\tools\validator.py --queue-status` returned command_id `000000002123`, timestamp `2026-06-26T01:59:27-04:00`, `worker running: True`, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, and `processing generated refresh jobs: 0`.

Validator diagnostics: all required validators returned exit code `0`. Repeated non-fatal generated-refresh diagnostics were limited to pre-existing/non-target registry and coverage metadata messages such as `autogen_registry_stale 0002ND`, `autogen_registry_stale 000258`, `autogen_emitter_has_no_code` for unrelated Error class emitters, and `memory_coverage_metadata_missing_file 000258/0002ND`. No `ERROR`, `Traceback`, or target-specific validation failure was reported.

Post-validation proof:

- `rg "\[TMP:"` over the parent, four child pages, and six support docs returned no matches.
- Child UIDs are [UID:00042Q], [UID:00042R], [UID:00042S], and [UID:00042T].
- `auto-generated/NexusTK/ui/core/Region.cpp` was validator-refreshed by command_id `000000002113` at `2026-06-26T01:55:42-04:00` and contains formal C++ for `Motion::Intersects`, `Motion::ContainsRect`, `Motion::Contains`, and `Motion::HasSameBoundsAs`.

## Residual Risks

- Raw children `0x00554a20`, `0x00554a40`, and `0x00554aa0` have zero direct incoming xrefs. This is a confidence cap only. It is not a no-code blocker because the bodies are source-shaped, byte-bounded, and semantically integrated with the live `Motion::Contains` helper.
- `Motion::HasSameBoundsAs` is inferred source-facing spelling. The exact original spelling is not recovered, but behavior and ownership are strong enough for first-draft C++.
- The repository currently uses `Motion` for both a timer-driven animation class bucket and Region dirty-rectangle helper names. The implementation must preserve that split explicitly in support docs to avoid attaching these child bodies to the animation `Motion` owner.
- Generated tracker/coverage/source output was refreshed only by validators. B008 did not manually edit generated reports, project-level generated files, coverage reports, validator state/cache, or generated C++.

## Implementation Callback Status

Implementation callback complete. Accepted target/support by-* documentation was edited and validated as recorded above. No generated/project-level/coverage/validator-state file was manually edited, and no IDA database changes were made. Generated output refresh was performed only by scoped validator commands with `--apply --wait-generated`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002R9-RegionRawRectangleHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002R9-RegionRawRectangleHelpers-source-quality.md","timestamp":"2026-06-26T02:06:10","uid":"0002R9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
