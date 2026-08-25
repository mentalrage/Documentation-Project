** TARGET-REPORT-UID:000150 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B006 Research Report: [UID:000150] FieldMapRectHelper Source Quality

Report-only assignment: `B006-report-000150-FieldMapRectHelper-source-quality-20260627`

Target: `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md`

Generated on: 2026-06-27

## Executive Recommendation

Return this target for implementation. The current raw/no-function/no-xref
blocker is now bounded well enough to stop leaving the target C++ blank.

Recommended target state:

- `COMPLETION`: raise from `85` to `88`.
- `CONFIDENCE`: raise from `88` to `90`.
- `CANONICAL_OWNER`: keep `0000JA`.
- `RECONSTRUCTABLE`: keep `TRUE`.
- `EMITTER_UIDS`: keep `0000JA`.
- Add first-draft formal C++ as
  `FieldMapPane::CalculateFieldItemRect(short entryIndex, RectBounds *outRect)`.
- Keep the no-live-caller caveat explicit: current binary evidence has no
  direct caller, xref, VA pointer, RVA pointer, or direct `call`/`jmp` edge to
  `0x004b1130`. Do not claim mouse/render call this helper.

The correct disposition is source-authored retained FieldMapPane helper, not
padding, not fitting-room code, not generic GrafPort or RectBounds ownership,
and not a proven live method. A no-code proof is not justified because the
owner, boundary, helper dependencies, field layout, output type, and source
body are now strong enough for first-draft source.

## Live IDA MCP Session

MCP was available and used. No fallback-only research was used.

- MCP endpoint used: `http://127.0.0.1:13337/mcp`
- Active database session: `398b87c1`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path reported by server: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- `server_health`: `status=ok`
- Auto-analysis ready: true
- Hex-Rays ready: true
- Strings cache ready: true

Initial required checks were performed with `idb_list` and `server_health`.
The server returned only session `398b87c1`, active, not analyzing, and healthy.

## Supervisor Active Recheck

The supervisor repaired the stale validator/generated path with scoped command
`000000004314`. This report uses the real target path:

- `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md`

No by-* docs, generated files, project-level files, coverage reports, validator
state, tool state, or IDA database state were edited during this report-only
pass.

Active recheck results:

- Target file exists at the corrected path.
- Current target metadata is `85/88`, owner/emitter [UID:0000JA],
  `RECONSTRUCTABLE:TRUE`, C++ blank.
- Current support docs already route FieldMapPane under
  `NexusTK/map/FieldMapPane.cpp`.
- FieldMap request helper [UID:000151] is now implemented and resolves the
  FieldMap entry request field names. That removes the packet-field blocker as
  a reason to keep this rectangle helper blank.
- GrafPort text support [UID:00016C] has formal C++ and source-facing names for
  `GrafPort::GetTextWidth(const wchar_t *)` and `GrafPort::GetLineHeight()`.
- RectBounds layout [UID:0001VP] fixes the output field order as
  `left/top/right/bottom`.

## Heuristic And Inference Reanalysis

The previous blocker mixed two separate facts:

- `0x004b1130` is not a modeled IDA function and has no incoming refs.
- The body is nevertheless a complete, unique, source-shaped helper with a
  stable FieldMapPane object layout and source-quality dependencies.

The first fact blocks claims of liveness. It does not, by itself, prove the
body should remain no-code. Current evidence supports a retained source helper:

- The body has a normal frame prologue, callee-saved register saves, two stack
  arguments, `ecx` receiver use, and `ret 8`.
- It indexes `this + 0x1f8 + entryIndex * 0x94`, the same FieldMap entry table
  documented by constructor, mouse, render, and request helper evidence.
- It measures the entry label at `+0x08` through established GrafPort text
  helpers.
- It writes a `RectBounds` output record in the accepted
  `left/top/right/bottom` layout.
- Modeled mouse and render functions inline the same lookup/measurement/math
  pattern, which strengthens source-family identity without proving a direct
  call.

Best inference: source-authored private FieldMapPane helper retained in the
binary but not reached by current direct-call/xref evidence.

## Blocker Disposition

### 1. No modeled IDA function

Decision: bounded; not a C++ blocker.

Live MCP `lookup_funcs` results:

| Address | Result |
| --- | --- |
| `0x004b112a` | not a function |
| `0x004b1130` | not a function |
| `0x004b119a` | not a function |
| `0x004b119d` | not a function |
| `0x004b11a0` | `sub_4B11A0`, size `0xa2` |
| `0x004b0d30` | `sub_4B0D30`, size `0x120` |
| `0x004b0fb0` | `sub_4B0FB0`, size `0x17a` |
| `0x004baa70` | `sub_4BAA70`, size `0x2e` |
| `0x004baaa0` | `sub_4BAAA0`, size `0x25` |

The absence of an IDA function object should remain documented, but it should
not force a blank C++ block because the raw body is exact and non-mutating MCP
byte reads plus local decode recover its complete source shape.

### 2. No incoming xrefs / liveness

Decision: no live caller is proven; keep that caveat, but do not use it as a
no-code proof.

Live MCP xref evidence:

- `xrefs_to 0x004b1130`: `0` refs.
- `xrefs_to 0x004b119a`: only internal fallthrough from `0x004b1199` to the
  `ret 8`.
- `xrefs_to 0x004b119d`: `0` refs.
- `xref_query 0x004b1130 direction=to`: no refs.

PE-aware local scan over executable section `.text` from
`0x00401000-0x0060c600`:

- Direct `call` to `0x004b1130`: `0` hits.
- Direct `jmp` to `0x004b1130`: `0` hits.
- Little-endian VA pointer to `0x004b1130`: `0` hits.
- Little-endian RVA pointer to `0x004b1130`: `0` hits.

Contrast evidence:

- The same scan finds three direct calls to the now-implemented request helper
  `0x004b11a0` at `0x004b0dfe`, `0x004b0ea7`, and `0x004b0f0e`.

Conclusion: `0x004b1130` must not be described as live-called by FieldMapPane
mouse/render paths. It should be described as an exact retained helper whose
formula is duplicated inline by live siblings.

### 3. Boundary and byte uniqueness

Decision: resolved.

MCP `get_bytes` confirms:

- `0x004b112a-0x004b112f`: six `0xcc` padding bytes before the helper.
- `0x004b1130`: helper prologue `55 8B EC ...`.
- `0x004b119a-0x004b119c`: final `C2 08 00` / `ret 8`.
- `0x004b119d-0x004b119f`: `0xcc` padding before `sub_4B11A0`.
- `0x004b11a0`: next modeled function starts with its own prologue.

MCP `make_signature_for_range(0x004b1130, 0x004b119d)` with concrete operands
returned `unique=true` for the full target range.

### 4. Source-facing helper name

Decision: use `FieldMapPane::CalculateFieldItemRect`.

Reasoning:

- Existing FieldMapPane support docs already use `CalculateFieldItemRect` as
  the candidate role.
- The body computes a dynamic text-derived rectangle, not a constant row
  rectangle, so `Calculate...Rect` is acceptable local style.
- `GetFieldEntryRect` is plausible but would introduce churn without stronger
  evidence.
- Do not use the file/page label `FieldMapRectHelper` as a source symbol.
- Do not use an address-suffixed helper name.

Recommended signature:

```cpp
void FieldMapPane::CalculateFieldItemRect(short entryIndex, RectBounds *outRect)
```

### 5. Field and dependency names

Decision: names are now strong enough for first-draft C++.

Use these FieldMapEntry fields already supported by FieldMapPane docs and the
accepted request-helper implementation:

| Offset | Name | Role |
| --- | --- | --- |
| `+0x00` | `centerY` | display/hit rectangle center Y |
| `+0x04` | `centerX` | display/hit rectangle center X |
| `+0x08` | `label` | UTF-16 label measured by GrafPort |
| `+0x8a` | `requestFieldId` | request helper packet field |
| `+0x8c` | `requestY` | request helper packet Y |
| `+0x90` | `requestX` | request helper packet X |

Use existing support names:

- `GetTextWidth(entry.label)` / `GrafPort::GetTextWidth(const wchar_t *)`
- `GetLineHeight()` / `GrafPort::GetLineHeight()`
- `RectBounds *outRect`, with fields `left`, `top`, `right`, `bottom`
- `m_fieldEntries` for the `this+0x1f8` entry table, stride `0x94`

No GrafPort, RectBounds, or request-helper support doc needs to change before
this target can carry first-draft C++.

## Target Function Facts

### Raw body decode

MCP `get_bytes` for `0x004b1130-0x004b119d`, decoded locally without creating
an IDA function, shows:

```asm
0x004b1130: push   ebp
0x004b1131: mov    ebp, esp
0x004b1133: movsx  eax, word ptr [ebp + 8]
0x004b113a: imul   edi, eax, 0x94
0x004b1140: mov    esi, ecx
0x004b1142: add    edi, 0x1f8
0x004b1148: add    edi, esi
0x004b114d: lea    eax, [edi + 8]
0x004b1151: call   0x4baa70
0x004b115b: add    ebx, 0xc
0x004b115e: call   0x4baaa0
0x004b1163: mov    ecx, dword ptr [edi]
0x004b1176: mov    dword ptr [edi + 4], ecx
0x004b117f: mov    dword ptr [edi + 0xc], eax
0x004b1187: mov    ecx, dword ptr [ecx + 4]
0x004b118e: mov    dword ptr [edi], ecx
0x004b1193: mov    dword ptr [edi + 8], eax
0x004b119a: ret    8
```

The abbreviated snippet above omits register-save/restore and signed divide by
two scaffolding; the complete decoded body confirms the exact assignments
described below.

### Effective behavior

The helper has `thiscall` shape with two explicit stack arguments:

- `[ebp+8]`: signed 16-bit `entryIndex`
- `[ebp+0xc]`: `RectBounds *outRect`
- `ecx`: `FieldMapPane *this`
- return: `ret 8`, no meaningful source return value

Computed entry pointer:

```text
entry = this + 0x1f8 + entryIndex * 0x94
```

Computed extents:

```text
textExtent = GetTextWidth(entry->label) + 12
verticalExtent = GetLineHeight() * 2
```

Output rectangle writes:

```text
outRect->top    = entry->centerY - verticalExtent / 2
outRect->bottom = outRect->top + verticalExtent
outRect->left   = entry->centerX - textExtent / 2
outRect->right  = outRect->left + textExtent
```

Because `verticalExtent` is `GetLineHeight() * 2`, the visible shorthand is
`top = centerY - lineHeight` and `bottom = centerY + lineHeight`. The C++ should
keep the full-extent form because it mirrors the binary and matches the inline
mouse/render rectangle formula.

## Sibling Relationship Evidence

### GrafPort text helper xrefs

Live MCP `xrefs_to` confirms the same text measurement pair appears in the raw
helper and FieldMapPane siblings:

| Target | Total refs | FieldMap-local refs |
| --- | ---: | --- |
| `0x004baa70` / `GrafPort::GetTextWidth(const wchar_t *)` | 64 | `0x4b0d8a`, `0x4b1037`, `0x4b1151` |
| `0x004baaa0` / `GrafPort::GetLineHeight()` | 67 | `0x4b0d97`, `0x4b1044`, `0x4b115e` |

The raw helper refs at `0x4b1151` and `0x4b115e` have `fn:null`, matching the
no-modeled-function state. The mouse/render refs have containing functions:

- `0x4b0d8a` and `0x4b0d97`: `sub_4B0D30`, size `0x120`
- `0x4b1037` and `0x4b1044`: `sub_4B0FB0`, size `0x17a`

### Mouse sibling

Decoded bytes from `sub_4B0D30` around `0x004b0d71` show the same pattern:

- Sign-extend the entry index.
- Multiply by stride `0x94`.
- Add table base `this+0x1f8`.
- Measure label at `entry+0x08`.
- Add horizontal padding `0x0c`.
- Read line height and build a two-line-height vertical extent.
- Write a local `RectBounds` and call `PointInRect`.

This is behavioral duplication, not a caller relationship.

### Render sibling

Decoded bytes from `sub_4B0FB0` around `0x004b1020` show the same pattern:

- Entry stride `0x94`.
- Label pointer at `entry+0x08` through an equivalent `ebx+0x200` address.
- Calls to `0x004baa70` and `0x004baaa0`.
- `centerY` read at entry `+0x00`, `centerX` read at entry `+0x04`.
- Local `RectBounds` construction before render color/text operations.

This supports FieldMapPane source-family ownership and the recommended helper
name, but it must not be turned into "render calls `CalculateFieldItemRect`" in
the target doc.

## Ownership Analysis

### Candidate 1: FieldMapPane / [UID:0000JA] `NexusTK/map/FieldMapPane.cpp`

Verdict: accept.

Positive evidence:

- The body uses the exact FieldMapPane entry table base and stride.
- It uses display fields `centerY`, `centerX`, and `label`, not request-only
  packet fields.
- Mouse and render siblings inline the same formula using the same table and
  text helpers.
- FieldMapPane class/file/aggregate docs already route the address neighborhood
  through [UID:0000JA].
- Request helper [UID:000151] is now also resolved under the same owner,
  strengthening the source family around `0x004b1130-0x004b1242`.

### Candidate 2: FittingRoomDownloadControlPane

Verdict: reject.

No direct caller, layout field, vtable route, or source route ties the body to
fitting-room. Existing fitting-room docs already mark `0x004b1130` as
FieldMap-adjacent boundary debt and warn against generated owner pollution.

### Candidate 3: GrafPort/Text helper ownership

Verdict: reject as canonical owner.

The body calls GrafPort text helpers, but it indexes FieldMapPane-specific
entry records and writes a caller-provided rectangle. GrafPort is a dependency,
not the source owner.

### Candidate 4: RectBounds helper ownership

Verdict: reject as canonical owner.

The output type is `RectBounds`, but the helper does not implement generic
rectangle primitives. It computes a FieldMap item rectangle from FieldMap entry
state.

### Candidate 5: dead/padding/no-code

Verdict: reject.

The bytes are not padding or data. They form a unique, complete, source-shaped
thiscall body with a valid return and supportable C++ body. The no-live-caller
fact caps confidence and should stay documented, but it is not enough to
justify blank formal C++.

## Source Placement

Recommended source placement remains:

- by-file owner: [UID:0000JA] `NexusTK/map/FieldMapPane.cpp`
- class: `FieldMapPane`
- method/helper name: `CalculateFieldItemRect`

Recommended source signature:

```cpp
void FieldMapPane::CalculateFieldItemRect(short entryIndex, RectBounds *outRect)
```

This should be treated as a private retained helper or private member helper in
the FieldMapPane source family. It should not be put in a generic rectangle
source file, a GrafPort file, fitting-room, or an address-suffixed global page.

## Recommended First-Draft C++

Add this formal C++ to the target after supervisor validation and implementation
callback:

```cpp
void FieldMapPane::CalculateFieldItemRect(short entryIndex, RectBounds *outRect)
{
    const FieldMapEntry &entry = m_fieldEntries[entryIndex];
    const int textExtent = GetTextWidth(entry.label) + 12;
    const int verticalExtent = GetLineHeight() * 2;

    outRect->top = entry.centerY - verticalExtent / 2;
    outRect->bottom = outRect->top + verticalExtent;
    outRect->left = entry.centerX - textExtent / 2;
    outRect->right = outRect->left + textExtent;
}
```

Notes for implementation:

- Keep this body in UID 000150, not the aggregate UID 00014Z, to avoid duplicate
  child/aggregate emission.
- Use inherited `GetTextWidth` and `GetLineHeight` call style, consistent with
  other GrafPort-derived pane C++ docs.
- Keep `RectBounds` field order `left/top/right/bottom`.
- Do not add a caller relationship from mouse/render unless later evidence
  proves one.
- Do not create or modify IDA function boundaries as part of documentation
  implementation.

## Recommended Target Doc Edits

For `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md`:

- Raise metadata to `COMPLETION:88`, `CONFIDENCE:90`.
- Keep owner/emitter [UID:0000JA].
- Replace the current blank-C++ blocker with the bounded conclusion:
  source-authored retained FieldMapPane rectangle helper, no live caller proven.
- Add live MCP session `398b87c1` evidence for:
  - no function object at `0x004b1130`, `0x004b119a`, or `0x004b119d`;
  - no incoming xrefs to `0x004b1130`;
  - exact padding/prologue/ret/padding boundaries;
  - unique concrete range signature;
  - text-helper xref relationship to mouse/render/raw sites;
  - PE-aware no direct edge/pointer hits.
- Add the formal C++ body above.
- Preserve wording that mouse/render duplicate the formula inline rather than
  calling this helper.

## Recommended Support Doc Edits

These are scoped support updates for a later implementation callback.

1. `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`
   - Update the raw helper note to say UID 000150 is first-draft C++ ready as a
     retained private FieldMapPane helper.
   - Keep aggregate formal C++ blank if needed to avoid duplicate child
     emission.
   - Explicitly say mouse/render duplicate the formula and do not currently
     call `0x004b1130`.

2. `by-class/FieldMapPane.md`
   - Add or update a private helper row:
     `CalculateFieldItemRect(short entryIndex, RectBounds *outRect)`.
   - Record that the helper uses `centerY`, `centerX`, `label`, `GetTextWidth`,
     `GetLineHeight`, and `RectBounds`.
   - Preserve the no-live-caller caveat.

3. `by-file/FieldMapPane.md`
   - Replace the open question that says `0x004b1130` still needs a boundary
     decision with the bounded conclusion: exact retained child helper, no live
     caller proven, body emitted from UID 000150 if accepted.
   - Keep the broader possible field-dialog source-split caveat only as a
     final-source placement cap, not a target C++ blocker.

4. `by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md`
   - No required edit for this target. The accepted request helper already
     supplies useful FieldMapEntry field names and contrast evidence.

5. GrafPort text and RectBounds support docs
   - No required edits. Their current source-facing names and layout notes are
     sufficient for UID 000150.

Do not edit project-level `proposed-source-tree.md` in the implementation
callback unless the supervisor explicitly broadens scope; it is project-level
documentation outside this report's scoped by-* support set.

## Generated-State Notes

Do not manually edit generated reports or generated C++.

The supervisor already repaired the stale validator/generated target path with
scoped command `000000004314`. This report does not attempt to solve the old
registry mismatch and does not recommend manual generated-file edits. After
accepted by-* edits, use scoped validators and let validator-owned generated
refresh handle derived output.

## Inference Claim Ledger

| Claim | Evidence type | Confidence | Notes |
| --- | --- | ---: | --- |
| Body starts at `0x004b1130` and ends at `0x004b119d` exclusive | MCP bytes, signature | High | Padding before and after is exact. |
| No IDA function object exists | MCP `lookup_funcs` | High | Start, ret, and padding addresses all report not a function. |
| No current live caller is proven | MCP xrefs plus PE scan | High | No xrefs, direct edges, VA pointers, or RVA pointers to start. |
| Owner/source family is FieldMapPane | layout, sibling functions, support docs | High | Uses `this+0x1f8` entry table and FieldMap-only fields. |
| Output type is `RectBounds` | RectBounds layout docs plus field writes | High | Writes `left/top/right/bottom` offsets `0/4/8/0xc`. |
| `centerY/centerX/label` names are usable | sibling render/mouse/request support | High | Same offsets used throughout FieldMapPane docs. |
| Helper name `CalculateFieldItemRect` is source-quality enough | existing support term plus behavior | Medium-high | Exact original spelling remains unproven. |
| First-draft C++ is safe | all above | High | Must preserve no-live-caller caveat. |

## Validator Results For Implementation Callback

Validators were run from `source-3/project-documentation` after the scoped
by-* edits.

> Executable block R001 was removed from this report and preserved verbatim in [000150-FieldMapRectHelper-source-quality-removed.md](000150-FieldMapRectHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000004352`
- `command_timestamp`: `2026-06-27T13:16:26-04:00`
- Result: `ok: 1`
- Generated refresh: `deferred`; `generated_refresh_command_id: 000000004352`;
  `generated_refresh_timestamp: 2026-06-27T13:16:26-04:00`
- Validator-owned side effects: `completion_update 000150 -> 88`,
  `confidence_update 000150 -> 90`, autogen registry updated from blank to
  block, and projected path completion section updated.

Post-correction target wording revalidation:

> Executable block R002 was removed from this report and preserved verbatim in [000150-FieldMapRectHelper-source-quality-removed.md](000150-FieldMapRectHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000004358`
- `command_timestamp`: `2026-06-27T13:18:36-04:00`
- Result: `ok: 1`
- Generated refresh: `deferred`; `generated_refresh_command_id: 000000004358`;
  `generated_refresh_timestamp: 2026-06-27T13:18:36-04:00`
- Validator-owned side effects: projected path completion section updated.

> Executable block R003 was removed from this report and preserved verbatim in [000150-FieldMapRectHelper-source-quality-removed.md](000150-FieldMapRectHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000004353`
- `command_timestamp`: `2026-06-27T13:16:34-04:00`
- Result: `ok: 1`
- Generated refresh: `deferred`; `generated_refresh_command_id: 000000004353`;
  `generated_refresh_timestamp: 2026-06-27T13:16:34-04:00`
- Existing warnings reported by validator: missing ref UID `0003P9`; missing
  ref target `00025B` at
  `by-memory/0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData.md`.
- Validator-owned side effects: projected path completion section updated.

> Executable block R004 was removed from this report and preserved verbatim in [000150-FieldMapRectHelper-source-quality-removed.md](000150-FieldMapRectHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000004355`
- `command_timestamp`: `2026-06-27T13:16:44-04:00`
- Result: `ok: 1`
- Generated refresh: `deferred`; `generated_refresh_command_id: 000000004355`;
  `generated_refresh_timestamp: 2026-06-27T13:16:44-04:00`
- Existing warnings reported by validator: missing ref target `00025B` twice at
  `by-memory/0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData.md`.
- Validator-owned side effects: projected path completion section updated.

> Executable block R005 was removed from this report and preserved verbatim in [000150-FieldMapRectHelper-source-quality-removed.md](000150-FieldMapRectHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`
- `command_id`: `000000004356`
- `command_timestamp`: `2026-06-27T13:16:56-04:00`
- Result: `ok: 1`
- Generated refresh: `deferred`; `generated_refresh_command_id: 000000004356`;
  `generated_refresh_timestamp: 2026-06-27T13:16:56-04:00`
- Existing warning reported by validator: missing ref target `00025B` at
  `by-memory/0x0061a3c8-0x0061a45c.FieldMapPaneReadOnlyData.md`.
- Validator-owned side effects: projected path completion section updated.

Generated output was not manually inspected or edited; generated refresh was
reported as deferred on all four scoped validator runs, and current generated
output was not required for this callback. Later queue status command
`000000004367` at `2026-06-27T13:20:12-04:00` showed `queued generated refresh
jobs: 0` and `processing generated refresh jobs: 0`; other non-generated
validator jobs were active in the shared queue. A read-only spot check of
`auto-generated/NexusTK/map/FieldMapPane.cpp` then showed
`validator-command-id: 000000004371`, refreshed at
`2026-06-27T13:20:31-04:00`, with the UID 000150
`FieldMapPane::CalculateFieldItemRect` body present. Final queue status command
`000000004375` at `2026-06-27T13:20:59-04:00` showed other shared validator
work processing and three generated refresh jobs queued after that spot check.

## Changed Files

Implementation callback modified:

- `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md`
- `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`
- `by-class/FieldMapPane.md`
- `by-file/FieldMapPane.md`
- `tools/leaser/Agents/Agent-B006/research/000150-FieldMapRectHelper-source-quality.md`

No generated files, project-level generated reports, manual coverage reports,
validator/tool state files, IDA database files, or unrelated docs were manually
edited. Validator-owned generated/stat side effects are listed above.

## Lease Status

Leased for the immediate edit/validator batch:

- `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md`
- `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`
- `by-class/FieldMapPane.md`
- `by-file/FieldMapPane.md`

Lease command returned `Success` for all four files. After validators, cleanup
with `python .\tools\leaser\leaser.py B006 unlease ...` returned
`Rejected[No active lease]` for each file, and the current lease report showed
no B006 rows. Only old expired Supervisor rows from 2026-06-18 remained.

A final target wording correction was followed by a second short lease on
`by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md`, target validator
command `000000004358`, and successful unlease. The final current lease report
again showed no B006 rows.

## Implementation Tracking Checklist

- [x] Lease only the target/support docs needed for the implementation
      callback: target UID 000150 plus scoped FieldMapPane aggregate/class/file
      support docs. Proof: B006 lease command returned `Success` for the four
      by-* docs listed under Lease Status.
- [x] Update UID 000150 metadata to `COMPLETION:88` and `CONFIDENCE:90`.
      Proof: target header updated and validator command `000000004352`
      reported `completion_update 000150 ... 88` and
      `confidence_update 000150 ... 90`; final target revalidation
      `000000004358` returned `ok: 1`.
- [x] Replace the raw/no-xref/no-C++ blocker with the bounded retained-helper
      conclusion and no-live-caller caveat. Proof:
      `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md` now records
      retained private helper status, no function object, no incoming xrefs,
      no PE direct edge/pointer hits, and no mouse/render caller claim.
- [x] Add formal C++ for
      `FieldMapPane::CalculateFieldItemRect(short entryIndex, RectBounds *outRect)`.
      Proof: target managed `RECONSTRUCTION_CPP CODE:BEGIN/END` block now
      contains that exact function body; validator command `000000004352`
      recorded autogen registry `blank -> block`.
- [x] Use `GetTextWidth`, `GetLineHeight`, `FieldMapEntry::centerY`,
      `FieldMapEntry::centerX`, `FieldMapEntry::label`, and `RectBounds`
      `left/top/right/bottom`. Proof: the target C++ uses these names, and the
      target/class/file support text records the accepted field/dependency
      meanings and RectBounds order.
- [x] Reject stale `FittingRoomDownloadControlPane`, generic GrafPort, and
      generic RectBounds ownership in the target ownership notes. Proof: target
      `2026-06-27 B006 Source-Quality Callback` and `Ownership Decision`
      sections reject fitting-room, GrafPort, RectBounds, padding, and no-code
      ownership alternatives.
- [x] Update `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md` to say UID
      000150 can emit child C++ while the aggregate may remain blank to avoid
      duplicate emission. Proof: aggregate reconstruction note, covered range
      row, `B006 Rectangle-Helper Source-Quality Update`, review-only draft
      note, and changes section now state that UID 000150 carries child C++
      while aggregate C++ remains blank.
- [x] Update `by-class/FieldMapPane.md` with the private retained helper role
      and the no-live-caller caveat. Proof: class method row now lists
      `CalculateFieldItemRect(short entryIndex, RectBounds *outRect)` and the
      live/no-function/no-edge caveat; class evidence and changes sections cite
      session `398b87c1`.
- [x] Update `by-file/FieldMapPane.md` so `0x004b1130` is no longer an
      unresolved boundary/import blocker, while preserving final-source
      placement caveats. Proof: method summary, live evidence, boundary
      cautions, open questions, score rationale, and changes section now treat
      `0x004b1130` as an exact retained child helper with no-live-caller caveat
      while keeping standalone-vs-larger-dialog placement open.
- [x] Do not edit `by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md`,
      GrafPort text docs, RectBounds docs, generated files, project-level docs,
      or coverage reports unless the implementation callback explicitly expands
      scope. Proof: no such manual edits were made; changed files are listed
      above.
- [x] Run scoped validators with `--apply --queue-timeout 240`, record command
      IDs, and inspect validator-owned generated refresh if queued. Proof:
      commands `000000004352`, `000000004353`, `000000004355`, and
      `000000004356` all exited `0` with `ok: 1`; final target revalidation
      `000000004358` also exited `0` with `ok: 1`; each reported
      `generated_refresh: deferred`.
- [x] Release leases immediately after the edit/validator batch and confirm no
      active B006 lease rows remain. Proof: cleanup command found no active
      lease rows after the first batch; a second short target lease for final
      wording revalidation was successfully unleased; the final current lease
      report contained no B006 entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/000150-FieldMapRectHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/000150-FieldMapRectHelper-source-quality.md","timestamp":"2026-06-27T13:23:25","uid":"000150"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000150-FieldMapRectHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/000150-FieldMapRectHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000150"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
