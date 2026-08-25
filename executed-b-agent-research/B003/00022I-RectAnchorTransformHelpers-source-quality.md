** TARGET-REPORT-UID:00022I **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022I RectAnchorTransformHelpers Source-Quality Research

Assignment: `B003-report-00022I-rect-anchor-transform-helpers-20260625`  
Agent: `B003`  
Target: [UID:00022I] `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`  
Mode: report-only research first. No by-* implementation edits were made.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022I] as reconstructable file-level/static `RectBounds.cpp` helper code owned and emitted by [UID:0000N2] `RectBounds`.
- Final disposition: first-draft formal C++ is supportable now for [UID:00022I] and should be paired with [UID:00022L] `RectAnchorAxisAdjustHelper` C++ in the same implementation callback, because the transform helpers call the axis primitive four times.
- Required action: after supervisor validation, update the target and support docs at report-level detail, replace the blank C++ blocks for [UID:00022I] and [UID:00022L], then run scoped validators. Do not manually edit generated tracker/coverage files.
- Confidence: high for behavior, range, padding, xrefs, owner/emitter route, and C++ readiness; medium-high for exact original helper spellings because names are behavior-derived rather than symbol-proven.

## Target

- Target UID: `00022I`
- Target path: `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`
- Required report path: `tools/leaser/Agents/Agent-B003/research/00022I-RectAnchorTransformHelpers-source-quality.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` still has the stale old path `by-memory/0x004b7f90-0x004b8198.RectAnchorTransformHelpers.md` and stale `76/82` metadata. The live source page is `0x004b7f90-0x004b8194`, `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000N2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N2`, blank formal C++.
- Supervisor classification: source-quality/C++ readiness and stale generated tracker/filename context target, not a generated-report edit task.

## Current Target State

- Existing metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000N2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N2`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP CODE`.
- Current owner/emitter route: [UID:0000N2] `by-file/RectBounds.md`, emitted as `NexusTK/ui/core/RectBounds.cpp`.
- Existing behavior summary: three raw helper-shaped starts at `0x004b7f90`, `0x004b8010`, and `0x004b80d0`; first helper transposes a 3x3 anchor index; the second and third copy two `RectBounds` records, adjust left/right edges, transpose the anchor, then adjust top/bottom edges through [UID:00022L] `0x004b8290`.
- Existing blockers: no modeled IDA functions at the three raw starts, no direct xrefs to those starts, inferred helper names, and blank formal C++.
- Related docs checked: [UID:00022L], [UID:0000N2], [UID:0000BU], [UID:0001VP], [UID:00015S], executed B001 `0000BU` and `00022H` report excerpts, generated `RectBounds.cpp`, generated tracker and by-memory auto coverage rows, proposed source tree.

## Supervisor Active Recheck

- Current user instruction explicitly requires the project-level `ntk-b-agent-workflow` skill, report-only output, no subagents, and mandatory IDA MCP. These requirements were followed.
- No split execution was authorized. No leases were needed or taken because this pass created only a report in B003's own `research/` folder.
- The live target already has the corrected half-open range. No child creation or filename edit is recommended during report validation; a later implementation callback should update the source page and let validator-owned generated reports refresh.

## IDA MCP Session And Evidence Checked

MCP was available and used. The active IDB session was `80de0a67`.

- `initialize`: HTTP 200, server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `tools/list`: HTTP 200; read-only tools used included `server_health`, `lookup_funcs`, `xref_query`, `callees`, `analyze_function`, `insn_query`, `find_bytes`, `find`, and `get_bytes`.
- `idb_list`: one active worker session, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `26892`.
- `server_health`: status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready.

MCP facts from this pass:

- `lookup_funcs` reports `0x004b7f90`, `0x004b8010`, `0x004b80d0`, `0x004b8194`, `0x004b8198`, `0x004b81a0`, `0x004b83ae`, and `0x004b83c5` are not modeled functions.
- `lookup_funcs 0x004b8290` reports `sub_4B8290`, size `0x11e`; `lookup_funcs 0x004b83d0` reports successor `sub_4B83D0`, size `0x1ae`.
- `xref_query` to `0x004b7f90`, `0x004b8010`, and `0x004b80d0` returns zero xrefs.
- `xref_query` to `0x004b8290` returns exactly four code refs: `0x004b803e`, `0x004b809f`, `0x004b80ff`, and `0x004b8161`; all four are inside [UID:00022I].
- `callees 0x004b8290` returns no callees.
- `analyze_function 0x004b8290` decompiles a six-argument cdecl helper with anchor/index, offset, first low/high edge pointers, second low/high edge pointers, switch cases `0..8`, no strings, no constants, no callees, and the same four xrefs.
- `get_bytes` confirms padding bytes: `0x004b7f87-0x004b7f90`, `0x004b8004-0x004b8010`, `0x004b8194-0x004b81a0`, `0x004b8284-0x004b8290`, and `0x004b83c5-0x004b83d0` are `0xcc`.
- `get_bytes 0x004b83ae-0x004b83c5` confirms the axis helper's local switch/table bytes, not executable source code after `0x004b83ad`.

Negative and false-hit checks:

- `find_bytes` for VA byte patterns `90 7F 4B 00`, `10 80 4B 00`, `D0 80 4B 00`, and `90 82 4B 00` returns no matches.
- `find_bytes` for RVA byte pattern `10 80 0B 00` returns one match at `0x0050f77c`; the same search for `0x004b7f90`, `0x004b80d0`, and `0x004b8290` RVAs returns none.
- `insn_query 0x0050f760-0x0050f790` shows the `0x0050f77c` hit is the rel32 operand of `call unknown_libname_19` at `0x0050f77b`, after `lea ecx, [esi+1]` and `push ecx`; it is not a pointer table or source-use route to `0x004b8010`.
- `get_bytes 0x0050f77b` returns `e8 10 80 0b 00`, confirming the apparent RVA bytes are part of a call instruction.
- `find immediate`, `find data_ref`, and `find code_ref` return no immediate/data/code refs for the three raw starts; `find code_ref 0x004b8290` returns only the four internal calls above.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct parent | Current score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b7f90-0x004b8004` | part of [UID:00022I] | 3x3 anchor transpose helper plus table at `0x004b7fe0-0x004b8004` | true | [UID:0000N2] | 86/88 | raw, no direct xrefs, C++ ready |
| `0x004b8004-0x004b8010` | padding | `0xcc` alignment | false | n/a | n/a | confirmed padding |
| `0x004b8010-0x004b80d0` | part of [UID:00022I] | rectangle-pair anchor adjuster, zero offsets | true | [UID:0000N2] | 86/88 | raw, no direct start xrefs, C++ ready |
| `0x004b80d0-0x004b8194` | part of [UID:00022I] | rectangle-pair anchor adjuster, caller-provided x/y offsets | true | [UID:0000N2] | 86/88 | raw, no direct start xrefs, C++ ready |
| `0x004b8194-0x004b81a0` | padding | `0xcc` alignment before `WideStringHashHelper` | false | n/a | n/a | confirms live end `0x004b8194` |
| `0x004b8290-0x004b83c5` | [UID:00022L] | anchor-axis edge-slot adjuster plus local switch data | true | [UID:0000N2] | 86/88 | modeled function, only called by [UID:00022I], paired C++ ready |

## Raw Instruction Semantics

`0x004b7f90` reads `[ebp+8]`, rejects only values above `8`, and returns the input unchanged on the default path. The table at `0x004b7fe0-0x004b8004` maps the 3x3 row-major anchor order as:

| Input | Output |
| ---: | ---: |
| 0 | 0 |
| 1 | 3 |
| 2 | 6 |
| 3 | 1 |
| 4 | 4 |
| 5 | 7 |
| 6 | 2 |
| 7 | 5 |
| 8 | 8 |

`0x004b8010` uses stack order:

```text
[0x08] const RectBounds *firstBounds
[0x0c] const RectBounds *secondBounds
[0x10] int anchor
[0x14] RectBounds *outFirstBounds
[0x18] RectBounds *outSecondBounds
```

It copies both input records with `movups`, calls `0x004b8290(anchor, 0, &outFirst.left, &outFirst.right, &outSecond.left, &outSecond.right)`, remaps the anchor through the same transpose table, then calls `0x004b8290(transposedAnchor, 0, &outFirst.top, &outFirst.bottom, &outSecond.top, &outSecond.bottom)`.

`0x004b80d0` uses stack order:

```text
[0x08] const RectBounds *firstBounds
[0x0c] const RectBounds *secondBounds
[0x10] int anchor
[0x14] int horizontalOffset
[0x18] int verticalOffset
[0x1c] RectBounds *outFirstBounds
[0x20] RectBounds *outSecondBounds
```

It has the same copy and two-axis structure, passing `[ebp+0x14]` to the horizontal axis call and `[ebp+0x18]` to the vertical axis call.

`0x004b8290` should be source-facing `void AdjustRectAnchorAxis(...)`, not an `int *` returning API. Hex-Rays names the first parameter `int *a1` because of the incidental `eax` value on some returns, but all four known callers ignore the return value. The source-relevant behavior is in-place edge mutation.

## Heuristic / Inference Reanalysis And Validation

### Raw helper starts

- Evidence checked: MCP `lookup_funcs`, `insn_query`, `get_bytes`, target/support docs, generated coverage rows, and B001/B008 report excerpts.
- Decision: keep `0x004b7f90`, `0x004b8010`, and `0x004b80d0` as raw function-shaped source helpers inside [UID:00022I]. Lack of IDA function objects is a modeling limitation, not proof of padding or generated data.
- Rejected alternatives: padding/data-only, compiler glue, CRT/runtime, unrelated hash/file/path helpers. The prologues, stack arguments, switch tables, `movups` rectangle copies, and four calls to `0x004b8290` make these source-authored geometry helpers.

### No external xrefs

- Evidence checked: MCP `xref_query`, `find code_ref`, `find data_ref`, `find immediate`, `find_bytes` for VA/RVA encodings, and disassembly around the sole RVA-like byte hit.
- Decision: no direct external route is currently proven for the three raw transform starts. This caps liveness confidence but does not block C++ because the helpers are source-shaped, bounded, owner-routed, and internally complete.
- Rejected alternatives: treating the `0x0050f77c` byte match as pointer/liveness evidence. It is the rel32 operand of `call unknown_libname_19`.

### Source placement

- Evidence checked: [UID:0000N2] `RectBounds`, [UID:0000BU] `RectBounds`, [UID:0001VP] `RectBoundsLayout`, predecessor [UID:00015S] `RectGeometryHelpers`, proposed source tree, generated `RectBounds.cpp`, and current MCP evidence.
- Decision: keep [UID:00022I] and [UID:00022L] as file-level/static helpers in `NexusTK/ui/core/RectBounds.cpp` through [UID:0000N2].
- Rejected alternatives: [UID:0000BU] class methods, `Region.cpp`, feature-local UI/layout modules, render-only ownership, `WideStringHash`, `FileExists`, `BuildFieldMapPath`, and `GeneralPurposePanel`. The helpers operate on rectangle pairs, anchor indices, offsets, and edge-slot pointers; they have no single `RectBounds` receiver and their only direct callee/caller relation is the RectBounds-layout axis helper pair.

### Source-facing names and signatures

- Evidence checked: stack order from `insn_query`, prior B001 names, target docs, and axis-helper decompilation.
- Decision:
  - `Transpose3x3AnchorIndex(int anchor)` for `0x004b7f90`.
  - `AdjustRectPairForAnchor(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, RectBounds *outFirstBounds, RectBounds *outSecondBounds)` for `0x004b8010`.
  - `AdjustRectPairForAnchorWithOffsets(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, int horizontalOffset, int verticalOffset, RectBounds *outFirstBounds, RectBounds *outSecondBounds)` for `0x004b80d0`.
  - `AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)` for [UID:00022L].
- Rejected alternatives: keeping raw names, using anchor-first parameter order for the transform helpers, or declaring the transform helpers as `RectBounds` member methods. The body-level stack order resolves the earlier "exact parameter order" caveat in favor of input rectangles first, anchor/offsets next, output rectangles last.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:00022I] live range is `0x004b7f90-0x004b8194` | Confirmed | MCP `get_bytes` shows `0xcc` at `0x004b8194-0x004b81a0`; switch table starts `0x004b8170` and occupies 36 bytes | Stale generated rows still say `0x004b8198`; `lookup_funcs 0x004b8198` is not a function | Validator refresh should update generated tracker, not manual generated edits |
| Raw starts are source-authored helpers | Strong | Prologues, stack args, switch tables, `movups` copies, calls to `0x004b8290` | No direct start xrefs; no IDA function objects | Liveness remains capped, but source reconstruction is supportable |
| Owner/emitter should stay [UID:0000N2] | Strong | RectBounds layout, current by-file/class/type docs, proposed source tree, axis-helper caller set | Region/feature/render/hash/file/path/general-panel alternatives checked and rejected | Exact original folder spelling below final-audit proof |
| Target C++ is ready | Strong | Current scores clear gate, emitter route exists, body-level parameter order and dependency are now MCP-backed | No original names; raw starts unmodeled | Use inferred names and keep scores below final-audit range |
| [UID:00022L] should receive paired C++ | Strong | Target calls it four times; modeled `0x004b8290` has no other callers/callees | Return type is incidental in Hex-Rays | Source-facing return should be `void`; exact original name inferred |

## Ranked Ownership Analysis

### 1. [UID:0000N2] RectBounds file-level/static helpers

- Evidence for: four-int `RectBounds` records copied and adjusted; axis helper only called by the transform cluster; by-file route already emits to `NexusTK/ui/core/RectBounds.cpp`; predecessor free geometry helpers and layout docs place this helper family in RectBounds source infrastructure.
- Evidence against: no external xrefs to transform starts and no original symbol spellings.
- Decision: accepted. Keep `CANONICAL_OWNER:0000N2`, `EMITTER_UIDS:0000N2`.

### 2. [UID:0000BU] RectBounds class methods

- Evidence for: same value type and class page cross-reference.
- Evidence against: no `ecx` receiver; helpers operate on two rectangles, anchor selector, offset values, and edge-pointer slots. [UID:0000BU] already classifies them as file-local/static helpers, not member methods.
- Decision: rejected as direct owner. Keep class doc as support/cross-reference only.

### 3. Region, feature module, render-only, or adjacent unrelated helpers

- Evidence for: address neighborhood includes unrelated helpers after this cluster, and unknown future consumers may exist.
- Evidence against: no xrefs tie the target to `Region`, `WideStringHash`, `FileExists`, `BuildFieldMapPath`, `GeneralPurposePanel`, or a feature module; the only direct callee route is RectBounds axis geometry.
- Decision: rejected.

### 4. No-owner/non-emitting

- Evidence for: raw starts lack direct external xrefs.
- Evidence against: source-authored behavior, existing valid owner/emitter, source-family support docs, and C++ gate are strong enough.
- Decision: rejected. The no-xref state is a confidence cap, not a no-code proof.

## Range / Split / Padding / Reclassification Analysis

No split is recommended. The live target range is already correct:

- `0x004b7f87-0x004b7f90`: 9 bytes `0xcc` padding before target.
- `0x004b7f90-0x004b8004`: transpose helper and its local table.
- `0x004b8004-0x004b8010`: 12 bytes `0xcc` internal padding.
- `0x004b8010-0x004b80d0`: no-offset pair transform helper and local table at `0x004b80ac-0x004b80d0`.
- `0x004b80d0-0x004b8194`: offset pair transform helper and local table at `0x004b8170-0x004b8194`.
- `0x004b8194-0x004b81a0`: 12 bytes `0xcc` padding before [UID:00022J] `WideStringHashHelper`.

The stale generated `0x004b8198` end should be fixed by validator refresh after source doc implementation. B003 should not edit generated reports manually.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested in this report-only pass. If a later IDA annotation pass is separately authorized, safe source-facing comments would be:

| Address | Recommended source-facing role | Confidence |
| --- | --- | --- |
| `0x004b7f90` | `Transpose3x3AnchorIndex(int anchor)` | high |
| `0x004b8010` | `AdjustRectPairForAnchor(...)` | high for behavior, medium-high for original name |
| `0x004b80d0` | `AdjustRectPairForAnchorWithOffsets(...)` | high for behavior, medium-high for original name |
| `0x004b8290` | `AdjustRectAnchorAxis(...)` | high for behavior, medium-high for original name |

The helper names are inferred/descriptive, not original-symbol proof.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

- [UID:00022I] is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:0000N2`, and current score average is `(86 + 88) / 2 = 87 > 85`.
- [UID:00022L] is also `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:0000N2`, and current score average is `(86 + 88) / 2 = 87 > 85`.
- The body-level MCP pass resolved the parameter order and branch behavior enough for first-draft source.
- The C++ uses inferred source-facing names and local/project style from `RectBounds.cpp`; no IDA labels or decompiler temporaries appear in final code.

For [UID:00022I], replace the blank formal `RECONSTRUCTION_CPP CODE` block with exactly:

```cpp
static void AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh);

static int Transpose3x3AnchorIndex(int anchor)
{
    switch (anchor) {
    case 0:
        return 0;
    case 1:
        return 3;
    case 2:
        return 6;
    case 3:
        return 1;
    case 4:
        return 4;
    case 5:
        return 7;
    case 6:
        return 2;
    case 7:
        return 5;
    case 8:
        return 8;
    default:
        return anchor;
    }
}

static void AdjustRectPairForAnchor(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, RectBounds *outFirstBounds, RectBounds *outSecondBounds)
{
    *outFirstBounds = *firstBounds;
    *outSecondBounds = *secondBounds;

    AdjustRectAnchorAxis(anchor, 0, &outFirstBounds->left, &outFirstBounds->right, &outSecondBounds->left, &outSecondBounds->right);

    const int transposedAnchor = Transpose3x3AnchorIndex(anchor);
    AdjustRectAnchorAxis(transposedAnchor, 0, &outFirstBounds->top, &outFirstBounds->bottom, &outSecondBounds->top, &outSecondBounds->bottom);
}

static void AdjustRectPairForAnchorWithOffsets(const RectBounds *firstBounds, const RectBounds *secondBounds, int anchor, int horizontalOffset, int verticalOffset, RectBounds *outFirstBounds, RectBounds *outSecondBounds)
{
    *outFirstBounds = *firstBounds;
    *outSecondBounds = *secondBounds;

    AdjustRectAnchorAxis(anchor, horizontalOffset, &outFirstBounds->left, &outFirstBounds->right, &outSecondBounds->left, &outSecondBounds->right);

    const int transposedAnchor = Transpose3x3AnchorIndex(anchor);
    AdjustRectAnchorAxis(transposedAnchor, verticalOffset, &outFirstBounds->top, &outFirstBounds->bottom, &outSecondBounds->top, &outSecondBounds->bottom);
}
```

For [UID:00022L], replace the blank formal `RECONSTRUCTION_CPP CODE` block with exactly:

```cpp
static void AdjustRectAnchorAxis(int anchor, int offset, int *firstLow, int *firstHigh, int *secondLow, int *secondHigh)
{
    const int originalSecondLow = *secondLow;
    const int originalSecondHigh = *secondHigh;
    const int secondSpan = originalSecondHigh - originalSecondLow;
    const int originalFirstLow = *firstLow;
    const int firstSpan = *firstHigh - originalFirstLow;
    const int spanDelta = firstSpan - secondSpan;

    int anchorOffset;
    switch (anchor) {
    case 0:
    case 3:
    case 6:
        anchorOffset = 0;
        break;
    case 1:
    case 4:
    case 7:
        anchorOffset = spanDelta / 2;
        break;
    case 2:
    case 5:
    case 8:
        anchorOffset = spanDelta;
        break;
    default:
        return;
    }

    if (offset < anchorOffset - firstSpan) {
        *firstLow = *firstHigh;
        *secondHigh -= secondSpan;
        return;
    }

    if (spanDelta <= 0) {
        if (offset < anchorOffset) {
            *firstLow = anchorOffset + originalFirstLow - offset;
            *secondHigh += offset + spanDelta - anchorOffset;
            return;
        }

        if (offset < anchorOffset - spanDelta) {
            *secondLow = offset + originalSecondLow - anchorOffset;
            *secondHigh += offset + spanDelta - anchorOffset;
            return;
        }
    } else {
        if (offset < anchorOffset - spanDelta) {
            *firstLow = anchorOffset + originalFirstLow - offset;
            *secondHigh += offset + spanDelta - anchorOffset;
            return;
        }

        if (offset < anchorOffset) {
            *firstLow = anchorOffset + originalFirstLow - offset;
            *firstHigh += anchorOffset - spanDelta - offset;
            return;
        }
    }

    if (offset >= anchorOffset + secondSpan) {
        *secondLow = originalSecondHigh;
        *firstHigh -= firstSpan;
    } else {
        *secondLow = offset + originalSecondLow - anchorOffset;
        *firstHigh += anchorOffset - spanDelta - offset;
    }
}
```

Reason this preserves behavior:

- The transform helper argument order follows the observed stack layout from `0x004b8010` and `0x004b80d0`.
- The one-line `AdjustRectAnchorAxis` prototype in the [UID:00022I] block is a dependency declaration for the paired [UID:00022L] support body, not a request to duplicate the axis helper body inside the target range.
- Struct assignment represents the two 16-byte `movups` rectangle copies.
- The two axis calls preserve the observed horizontal-first, transpose-anchor, vertical-second operation order.
- Invalid anchors preserve the target behavior: `Transpose3x3AnchorIndex` returns the original anchor, while `AdjustRectAnchorAxis` default returns without mutation.
- The axis helper branches follow the Hex-Rays/decompiled instruction order from `0x004b8290`.

Reason this is plausible original source:

- Names match the accepted RectBounds source-family naming direction and remove raw address suffixes.
- Static file-level helpers fit the no-external-xref state and the existing by-file/class split.
- The switch statements represent source control flow while letting the compiler regenerate local jump tables.
- The code does not hand-port table bytes as explicit data and does not introduce decompiler temporaries.

## Score And Metadata Recommendation

For [UID:00022I]:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | 86 | 89 | The pass resolves the body-level parameter order, validates table/padding boundaries with MCP, closes false pointer/immediate routes, and supplies formal C++. Keep below 95 because original symbol spellings and external reachability remain inferred. |
| `CONFIDENCE` | 88 | 90 | Current MCP reconfirms behavior, xrefs, bytes, and owner route. Keep at 90, not higher, because the starts are still not IDA functions and no direct external xrefs to the starts are known. |
| `CANONICAL_OWNER` | `0000N2` | `0000N2` | Keep RectBounds file owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored geometry helper code. |
| `EMITTER_UIDS` | `0000N2` | `0000N2` | Existing route reaches `NexusTK/ui/core/RectBounds.cpp`. |
| `RECONSTRUCTION_CPP CODE` | blank | nonblank | Insert exact target code above. |

For [UID:00022L]:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | 86 | 89 | Axis branch semantics and source-facing `void` contract are now implementation-ready. |
| `CONFIDENCE` | 88 | 90 | Modeled function, no callees, and only [UID:00022I] callers are MCP-backed. |
| `CANONICAL_OWNER` | `0000N2` | `0000N2` | Keep RectBounds file owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored axis helper. |
| `EMITTER_UIDS` | `0000N2` | `0000N2` | Required support body for [UID:00022I]. |
| `RECONSTRUCTION_CPP CODE` | blank | nonblank | Insert exact support code above. |

No owner/emitter changes are recommended for [UID:0000N2], [UID:0000BU], [UID:0001VP], or [UID:00015S].

## Open Questions With Attempted Resolution

1. Are the raw starts real functions despite IDA not modeling them?
   - Evidence checked: `lookup_funcs`, `insn_query`, padding bytes, switch tables, xrefs, and adjacent docs.
   - Resolution: yes, they are source-authored raw helper bodies. IDA function absence remains a tooling/modeling caveat, not a no-code blocker.

2. Is there any external route to `0x004b7f90`, `0x004b8010`, or `0x004b80d0`?
   - Evidence checked: `xref_query`, `find code_ref`, `find data_ref`, `find immediate`, VA/RVA `find_bytes`, and disassembly around the sole RVA-like hit.
   - Resolution: no current direct route. This caps score below final-audit confidence but does not block C++.

3. Should [UID:00022I] be moved to class [UID:0000BU]?
   - Evidence checked: stack parameter shape and support docs.
   - Resolution: no. These are file-local/static helpers, not class methods.

4. Should `0x004b8010` use anchor-first source order from the older B001 provisional note?
   - Evidence checked: raw stack order from `insn_query`.
   - Resolution: no. Use binary stack order: input rectangles, anchor, output rectangles. The offset variant uses input rectangles, anchor, horizontal offset, vertical offset, output rectangles.

5. Should formal C++ remain blank because names are inferred?
   - Evidence checked: workflow C++ gate, by-structure policy, MCP behavior, and existing source-family docs.
   - Resolution: no. Exact original spellings are not available, but source-facing inferred names are supportable and preferable to blank C++ or raw labels.

## Recommended Target Doc Changes

Target path: `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`

If the supervisor accepts this report:

- Update `COMPLETION:89`, `CONFIDENCE:90`; keep owner/emitter/reconstructable unchanged.
- Replace the blank formal C++ block with the [UID:00022I] code above.
- Add current MCP evidence: session `80de0a67`, raw starts not functions, exact four xrefs to `0x004b8290`, no xrefs to raw starts, padding bytes, table bytes, and false `0x004b8010` RVA hit at `0x0050f77c`.
- Update helper semantics to record exact stack parameter order for `0x004b8010` and `0x004b80d0`.
- Preserve rejected alternatives: class method, Region/feature/render owner, unrelated adjacent helpers, no-owner/no-code, and false pointer route.
- Update score rationale and change log to state that B003 supplied first-draft body-level C++ under supervisor validation.

## Recommended Support Doc Changes

Support path: `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`

- Update `COMPLETION:89`, `CONFIDENCE:90`; keep owner/emitter/reconstructable unchanged.
- Replace the blank formal C++ block with the [UID:00022L] code above.
- Document source-facing return as `void`, with Hex-Rays `int *` return rejected as incidental/ignored.
- Preserve exact four-caller set and no-callee state.

Support path: `by-file/RectBounds.md`

- Update the proposed contents/generated-output caveat to state that [UID:00022I] and [UID:00022L] have B003 body-level first-draft C++ ready/applied after callback, still as file-level/static helpers.
- Preserve stale/generated tracker context and the false `0x004b8010` RVA-hit explanation.
- No score or owner/path change required.

Support path: `by-class/RectBounds.md`

- Add or update one sentence in the class-versus-file-local helper notes: [UID:00022I] and [UID:00022L] now have body-level RectBounds.cpp helper C++, but they remain file-local/static helpers and not `RectBounds` methods.
- No class C++ or metadata change required.

Support path: `by-type/by-struct/RectBoundsLayout.md`

- Confirm the page already records the edge-slot role for [UID:00022I]/[UID:00022L]. Add a short B003 support note only if the supervisor wants the formal C++ evidence preserved there too.
- No metadata change required.

No edit is recommended for [UID:00015S] `RectGeometryHelpers`; it already records [UID:00022I] as the following raw helper island and its predecessor relationship is current.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or generated-tracker text should be edited by B003.

- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` are stale inputs. They should refresh through validator/report execution after accepted source-page implementation.
- If the old `0x004b7f90-0x004b8198` generated row or `file_missing` diagnostic remains after scoped validation, use the documented validator lifecycle/refresh path; do not hand-edit generated Markdown or validator state.

## Validator Results

Implementation callback validators, run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00022I-RectAnchorTransformHelpers-source-quality-removed.md](00022I-RectAnchorTransformHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000002073`
- `command_timestamp`: `2026-06-26T01:35:58-04:00`
- `ok`: `1`
- Generated refresh: `deferred`, `generated_refresh_command_id:000000002073`, `generated_refresh_timestamp:2026-06-26T01:35:58-04:00`
- Notable validator-owned side effects: recorded [UID:00022I] `COMPLETION:89`, `CONFIDENCE:90`, owner/emitter/hash updates, stale path update from `0x004b8198` to `0x004b8194`, `project-level/-auto-completion-stats.md` projected stats update, and a validator UID-link refresh in `by-memory/-coverage-report.md`. Existing broad missing-reference diagnostics remain unrelated to this target.

> Executable block R002 was removed from this report and preserved verbatim in [00022I-RectAnchorTransformHelpers-source-quality-removed.md](00022I-RectAnchorTransformHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000002076`
- `command_timestamp`: `2026-06-26T01:36:33-04:00`
- `ok`: `1`
- Generated refresh: `deferred`, `generated_refresh_command_id:000000002076`, `generated_refresh_timestamp:2026-06-26T01:36:33-04:00`
- Notable validator-owned side effects: recorded [UID:00022L] `COMPLETION:89`, `CONFIDENCE:90`, owner/emitter/hash updates, and projected stats update.

> Executable block R003 was removed from this report and preserved verbatim in [00022I-RectAnchorTransformHelpers-source-quality-removed.md](00022I-RectAnchorTransformHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000002077`
- `command_timestamp`: `2026-06-26T01:36:41-04:00`
- `ok`: `1`
- Generated refresh: `deferred`, `generated_refresh_command_id:000000002077`, `generated_refresh_timestamp:2026-06-26T01:36:41-04:00`
- Notable validator-owned side effects: recorded [UID:0000N2] canonical owner/path state and projected stats update. Existing unrelated `missing_ref_uid 00040U` diagnostics remain.

> Executable block R004 was removed from this report and preserved verbatim in [00022I-RectAnchorTransformHelpers-source-quality-removed.md](00022I-RectAnchorTransformHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000002078`
- `command_timestamp`: `2026-06-26T01:36:50-04:00`
- `ok`: `1`
- Generated refresh: `deferred`, `generated_refresh_command_id:000000002078`, `generated_refresh_timestamp:2026-06-26T01:36:50-04:00`
- Notable validator-owned side effects: recorded [UID:0000BU] score/owner/emitter/hash state and projected stats update.

`by-type\by-struct\RectBoundsLayout.md` was read and confirmed already to preserve the edge-slot role for [UID:00022I]/[UID:00022L] at sufficient detail, so it was not edited and no scoped validator was required for that page.

Queue status after validators:

> Executable block R005 was removed from this report and preserved verbatim in [00022I-RectAnchorTransformHelpers-source-quality-removed.md](00022I-RectAnchorTransformHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000002087`
- `command_timestamp`: `2026-06-26T01:39:07-04:00`
- Queue state: worker running, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/00022I-RectAnchorTransformHelpers-source-quality.md` during the original report-only pass.
- Modified by-* docs during implementation: `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`, `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`, `by-file/RectBounds.md`, and `by-class/RectBounds.md`.
- Confirmed but not modified: `by-type/by-struct/RectBoundsLayout.md`.
- Report checklist updated: `tools/leaser/Agents/Agent-B003/research/00022I-RectAnchorTransformHelpers-source-quality.md`.
- Manual generated/project-level/coverage/tool-state/IDA DB edits: none. Validator-owned side effects are reported above; no IDA DB changes were made.
- Leases used: B003 leased the four edited by-* files immediately before the edit/validator batch, released/reacquired the same four locks when the first lease window reached expiry, and released all B003 leases immediately after the validators completed.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback assignment `B003-implement-00022I-rect-anchor-transform-helpers-20260626` accepted this report for implementation.
- [x] Target doc to update: `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md`. Proof: metadata, formal C++, MCP evidence, semantics, score rationale, and change log updated.
- [x] Support docs to update or confirm: `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md`, `by-file/RectBounds.md`, `by-class/RectBounds.md`, and optionally `by-type/by-struct/RectBoundsLayout.md` only if the supervisor wants the new formal-code evidence duplicated there. Proof: first three support docs updated; `RectBoundsLayout.md` read and confirmed already documents the edge-slot role, so no edit was needed.
- [x] Current target state and actual evidence checked recorded, including MCP session `80de0a67`, `server_health`, `lookup_funcs`, `xref_query`, `insn_query`, `analyze_function`, `find`, `find_bytes`, and `get_bytes`. Proof: [UID:00022I] and [UID:00022L] now record B003 session `80de0a67`, server health, raw start/function status, xrefs, false RVA hit, padding/table bytes, caller/callee state, and analyze/decompile facts.
- [x] Metadata changes to apply: [UID:00022I] `86/88 -> 89/90`; [UID:00022L] `86/88 -> 89/90`; keep `CANONICAL_OWNER:0000N2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N2`. Proof: validators `000000002073` and `000000002076` recorded the updated scores and preserved owner/emitter metadata.
- [x] Score-limiting blockers researched: raw starts, absent IDA functions, no external xrefs, false RVA hit, parameter order, source placement, and C++ readiness. Proof: both target pages preserve those blockers as resolved or score-capping evidence rather than no-code blockers.
- [x] Owner/emitter changes: none; preserve [UID:0000N2]. Proof: both by-memory validators recorded `canonical_owner_update ... 0000N2` and emitter registry updates to [UID:0000N2].
- [x] Split/rename/new-child changes: none; keep live `0x004b8194` end and let validator refresh stale generated rows. Proof: no child/split docs were created; validator `000000002073` recorded the stale path update from `0x004b8198` to `0x004b8194`.
- [x] Source-placement and range/padding facts to apply: file-level/static `RectBounds.cpp` helpers, not `RectBounds` class methods; `0x004b8004-0x004b8010` and `0x004b8194-0x004b81a0` padding; local switch tables at `0x004b7fe0`, `0x004b80ac`, and `0x004b8170`. Proof: [UID:00022I], [UID:00022L], [UID:0000N2], and [UID:0000BU] now carry the static-helper route and range/padding/table details.
- [x] First-draft C++ to apply: exact formal [UID:00022I] and [UID:00022L] code blocks from this report. Proof: both `RECONSTRUCTION_CPP CODE` blocks are populated; validators recorded autogen registry hash updates from blank to block.
- [x] Historical/stale assumptions to preserve/reject: stale generated `0x004b8198` row; old anchor-first provisional parameter order; false `0x004b8010` RVA hit; class-method/no-owner alternatives. Proof: target/support pages document these as stale/rejected and leave generated rows to validator refresh.
- [x] Open questions to close or document: original helper names remain inferred; no external xrefs remain a liveness confidence cap, not a code blocker. Proof: score rationale on both by-memory pages states names are inferred and no-xref/raw-start status caps confidence without blocking first-draft C++.
- [x] Validators to run: scoped file validators for changed target/support docs from `source-3/project-documentation`. Proof: validator commands `000000002073`, `000000002076`, `000000002077`, and `000000002078` all exited `0` with `ok:1`.
- [x] Generated report refresh expectation: validator/report execution should refresh generated tracker/coverage/C++ state; B003 must not manually edit generated reports or any `-coverage-report.md`. Proof: no manual generated/coverage/tool-state edits were made. Validator-owned side effects and deferred generated refresh states are recorded under `Validator Results`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` mode is implementation callback after supervisor report validation for this report.
- [x] Lease only the exact by-* files being edited immediately; release leases immediately after edit/validator batch. Proof: B003 leased exactly the four edited by-* files, released/reacquired the same set when the first lease window reached expiry, and released all B003 leases after validators completed.
- [x] Apply [UID:00022I] metadata/C++/evidence/score/change-log updates at report-level detail. Proof: `by-memory/0x004b7f90-0x004b8194.RectAnchorTransformHelpers.md` updated; validator `000000002073` passed.
- [x] Apply [UID:00022L] metadata/C++/evidence/score/change-log updates at report-level detail. Proof: `by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md` updated; validator `000000002076` passed.
- [x] Apply or confirm support updates in [UID:0000N2], [UID:0000BU], and optional [UID:0001VP]. Proof: `by-file/RectBounds.md` and `by-class/RectBounds.md` updated and validated with commands `000000002077` and `000000002078`; `by-type/by-struct/RectBoundsLayout.md` already preserved the edge-slot role and was left unedited.
- [x] Preserve negative evidence, rejected alternatives, and stale generated tracker context. Proof: target/support docs preserve raw/no-function starts, no external xrefs, false RVA hit, class-method/no-owner/source-placement rejections, stale generated path/metadata context, and validator-owned refresh expectations.
- [x] Run scoped validators and record command, `command_id`, `command_timestamp`, exit code, ok count, and generated refresh state. Proof: see `Validator Results` above; queue status `000000002087` later showed no queued or processing generated refresh jobs.
- [x] Leave generated reports, project-level generated files, validator state/cache, IDA DB, and all `-coverage-report.md` files unedited. Proof: no manual edits were made to those files and no IDA DB changes were made; validator-owned side effects from required scoped validation are reported above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00022I-RectAnchorTransformHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00022I-RectAnchorTransformHelpers-source-quality.md","timestamp":"2026-06-26T01:40:50","uid":"00022I"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022I-RectAnchorTransformHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00022I-RectAnchorTransformHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
