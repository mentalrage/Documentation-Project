** TARGET-REPORT-UID:00034Q **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00034Q] TabPaneRawRectangleBuilder Source-Quality Report

Agent: Agent-B005  
Task type: B-agent source-quality / heuristic research  
Target: `source-3/project-documentation/by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md`  
Required disposition: report-only. No target/support by-* docs edited. No `by-memory/-coverage-report.md` edit.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00034Q] as reconstructable, keep direct owner/emitter [UID:0000EB] `TabPane`, raise target metadata from `85/86` to `87/89`, and keep first-draft C++ populated with a corrected helper-body wording.
- Final disposition: source-authored retained `TabPane` rectangle-builder helper with a local switch table and no currently proven live entry route. It is not padding, not compiler-generated thunk/table-only data, and not owned by the broad mixed aggregate [UID:000170].
- Required action: update the target with direct PE evidence, close the passive reachability blocker, update the C++ block to use the canonical rectangle initializer name, and add support-doc notes that the live resolver duplicates/inlines the same rectangles rather than directly calling `0x004cfb20`.
- Confidence: very strong for bytes, table targets, padding, rectangle semantics, TabPane ownership, and negative route evidence; medium-high for exact original helper name/source spelling because no symbols or callers survive.

Recommended target metadata:

```yaml
COMPLETION: 87
CONFIDENCE: 89
CANONICAL_OWNER: 0000EB
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000EB
```

Recommended target C++:

```cpp
void TabPane::BuildTabActionRect(int actionCode, RectBounds *outRect) const
{
    switch (actionCode) {
    case 0:
        InitRectBounds(outRect, 2, 1, 20, 46);
        break;
    case 1:
        InitRectBounds(outRect, 2, 47, 20, 93);
        break;
    case 2:
        InitRectBounds(outRect, 2, 95, 20, 140);
        break;
    case 3:
        InitRectBounds(outRect, 2, 142, 20, 187);
        break;
    case 4:
        InitRectBounds(outRect, 2, 189, 20, 234);
        break;
    case 5:
        InitRectBounds(outRect, 2, 236, 20, 281);
        break;
    default:
        InitRectBounds(outRect, -1, -1, -1, -1);
        break;
    }
}
```

`BuildTabActionRect` is the best current source-facing name. It is descriptive, not original-proof. `GetTabActionRect` or `BuildTabRect` are acceptable alternates if a later TabPane naming sweep standardizes on `Get*Rect` for output-parameter geometry helpers.

The helper should be documented as a retained out-of-line private member/helper. The adjacent resolver [UID:00034R] currently emits C++ that calls `BuildTabActionRect`; that is acceptable only as a source-level de-duplication and compiler-inlining hypothesis. The executable `0x004cfc60` body does not call `0x004cfb20`; it builds the same rectangles inline and calls `InitRectBounds` / `PointInRect` directly.

## Supporting Research

## Target

- Target UID: `00034Q`
- Target path: `by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md`
- Required report path: `tools/leaser/Agents/Agent-B005/research/00034Q-TabPaneRawRectangleBuilder-source-quality.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000EB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EB`
- Current formal C++: populated as `TabPane::BuildTabActionRect(int actionCode, RectBounds *rect) const`, using `SetRect`.
- Current generated state: `auto-generated/NexusTK/ui/panels/TabPane.cpp` emits `BuildTabActionRect` and `ResolveTabActionCode`, with `ResolveTabActionCode` calling the helper.
- Manual coverage state: `by-memory/-coverage-report.md` currently has only the broad [UID:000170] row for the split inventory in this address region; no separate `00034Q` child row was found by `rg`.
- Generated coverage state: `auto-generated/-ag-memory-coverage.md` reports [UID:00034Q] as `coded`, owner/emitter `0000EB`, generating to `auto-generated/NexusTK/ui/panels/TabPane.cpp`.

## Supervisor Active Recheck

This report was triggered by the 2026-06-19 B005 assignment for [UID:00034Q]. The assignment required a B-only source-quality and heuristic pass. I did not coordinate with A/C agents and did not edit target/support by-* docs or `by-memory/-coverage-report.md`.

The required focus items were checked:

- exact bytes, raw/function status, switch table targets, padding, and no-xref evidence for `0x004cfb20-0x004cfc5c`;
- whether this is retained dead/duplicate helper, missed callable source helper, or part of `TabPane` action resolution;
- pointer/table/indirect route search;
- comparison to live `TabPane` resolver behavior;
- draft C++ name/signature and rectangle semantics;
- source placement and emitter route among `TabPane`, [UID:000170], child-only emission, or inline resolver handling;
- support-doc updates, score/metadata recommendation, coverage row text, validator commands, and IDA rename/type/comment recommendations.

## Evidence Checked

Instruction and rule evidence:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B005/goal.md`
- `by-structure.md`
- `inference_research.md`

Target and support documentation:

- `by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md`
- `by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md`
- `by-memory/0x004cfa10-0x004cfb0a.TabPaneHandleInputEvent.md`
- `by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md`
- `by-memory/0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable.md`
- `by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md`
- `by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md`
- `by-memory/0x004cfa00-0x004cfa01.TabPaneNullVirtual.md`
- `by-memory/0x004cfb10-0x004cfb15.TabPaneFalseReturnVirtual.md`
- `by-class/TabPane.md`
- `by-file/TabPane.md`
- `by-global/g_pTabPane.md`
- `by-memory/0x0061b4cc-0x0061b568.TabPaneVtableData.md`
- `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`
- `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-class/RectBounds.md`
- `by-file/RectBounds.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `by-project-structure/proposed-source-tree.md`
- `project-level/-resolved.md`
- `project-level/-unresolved.md`
- `auto-generated/NexusTK/ui/panels/TabPane.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `by-memory/-coverage-report.md`
- Prior B001 report: `tools/leaser/Agents/Agent-B001/research/executed/older/000170-TabPaneAndIconsPaneDestructorTail.md`
- Rule 26 tracker note: `tools/leaser/Agents/b-agent-rule26-incorporation-tracker.md`

Direct binary evidence:

- PE parsed from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Image base: `0x00400000`.
- `.text`: `0x00401000-0x0060c600`.
- Direct bytes, table dwords, padding, rel32/rel8 branch scans, VA/RVA dword scans, export directory check, and uniqueness scans were run locally against the PE.
- IDA MCP was attempted at `http://127.0.0.1:13337/mcp`; the endpoint returned `Unable to connect to the remote server`. Current report therefore uses existing IDA-backed docs plus direct PE scans. No IDA changes were made.

## Heuristic / Inference Reanalysis And Validation

### Raw/function status

Best inference: source-authored retained function-shaped helper, not compiler-only data and not padding.

Evidence:

- The range starts with a normal prologue `55 8b ec`.
- It has a local switch jump through `0x004cfc40`.
- It calls the shared rectangle initializer `0x004b7c50` in every live/default case.
- It ends each case with `5e 5d c2 08 00`, a callee-pop `ret 8` shape compatible with an MSVC `thiscall` member with two stack parameters.
- The body bytes are unique in the PE.
- The table bytes are unique in the PE.
- Leading and trailing bytes are clean `0xcc` padding, so the half-open range is stable.

Rejected alternatives:

- Padding: rejected by prologue, switch, calls, and returns.
- Jump-table-only artifact: rejected because the table is only the final `0x1c` / decimal `28` bytes (Verified with int_convert.py) and is used by a full body before it.
- Compiler-generated thunk: rejected because the function has real branching and application rectangle constants, not a simple `this` adjust/tail-jump pattern.
- Pure source-declared/generated-binary data: rejected because most of the range is executable instructions.

### Liveness and route search

Best inference: no direct live route is currently proven; treat the helper as retained source-shaped code, likely an out-of-line copy of a private helper or a dead duplicate of logic in the resolver.

Evidence checked:

- IDA-backed docs from 2026-06-10 report no IDA function object at `0x004cfb20`, no xrefs to the entrypoint, and no loaded-segment pointer hits.
- Direct PE rel32 scan found zero calls/jumps to:
  - `0x004cfb20` entry;
  - case labels `0x004cfb38`, `0x004cfb5e`, `0x004cfb84`, `0x004cfbaa`, `0x004cfbd2`, `0x004cfbfa`;
  - table `0x004cfc40`;
  - trailing padding `0x004cfc5c`.
- Direct PE rel8 scan found zero short branches to `0x004cfb20`, `0x004cfc40`, `0x004cfc5c`, or successor `0x004cfc60`.
- Direct PE absolute VA/RVA scan found zero dword hits for `0x004cfb20`.
- Direct PE absolute VA/RVA scan found the table address `0x004cfc40` only as the local switch operand at `0x004cfb34`.
- Direct PE dword scans found each raw case label only inside the local jump table at `0x004cfc40-0x004cfc5c`.
- Export directory is empty (`export_rva 0x0`, size `0x0`), so export reachability is ruled out.

Route conclusion:

- No direct call, branch, vtable, export, VA/RVA pointer, or non-local table route to `0x004cfb20` was found.
- This is a real negative finding, not an unresolved passive blocker. It caps final-source confidence, but it does not justify clearing owner/emitter or replacing the helper with padding/no-code. The code is source-shaped and TabPane-specific.

### Relationship to live resolver

Best inference: `0x004cfc60` is the live resolver and duplicates/inlines the same rectangle construction instead of calling `0x004cfb20`.

Evidence:

- [UID:00034R] has IDA function `sub_4CFC60` at `0x004cfc60-0x004cfd4d`, size `0xed` / decimal `237` (Verified with int_convert.py).
- Direct callers of `0x004cfc60` are `0x004cfa4c` and `0x004cfaae` inside `TabPane::HandleInputEvent`.
- Direct PE rel32 scan confirms exactly those two calls to `0x004cfc60`.
- Resolver bytes at `0x004cfc60` start with stack-cookie setup, then a loop over action codes, a local switch table at `0x004cfd50`, direct calls to `0x004b7c50`, and calls to `0x004b7e80`.
- The resolver's own switch table entries at `0x004cfd50` are `0x004cfcee`, `0x004cfc88`, `0x004cfc98`, `0x004cfca8`, `0x004cfcb8`, `0x004cfcca`, and `0x004cfcdc`.
- The resolver does not call `0x004cfb20`; there are zero rel32/rel8 routes from resolver to the raw helper.

Source-shape impact:

- Current generated `ResolveTabActionCode` calls `BuildTabActionRect`. This is not binary-literal, but it is plausible original-source factoring if the compiler inlined the helper and still retained an out-of-line copy.
- The support docs must explicitly say that the call in generated source is a source-level de-duplication/inlining hypothesis, not observed machine-code reachability.
- If a future final-source pass rejects the inlining hypothesis, then [UID:00034R] should inline the rectangle switch and [UID:00034Q] should remain as a retained dead private helper. It should not be moved to [UID:000170] or ignored as padding.

### Name and signature

Best current source-facing signature:

```cpp
void TabPane::BuildTabActionRect(int actionCode, RectBounds *outRect) const
```

Evidence:

- The helper takes two stack arguments and returns with `ret 8`.
- The first stack argument is read from `[ebp+8]`, incremented, range-checked, and used to select a rectangle.
- The second stack argument `[ebp+0xc]` is pushed as the output `RectBounds*` for `0x004b7c50`.
- `ecx` is unused, but the callee-pop two-argument shape fits MSVC member `thiscall` for a non-virtual `TabPane` method whose body does not read fields.
- A default internal C++ free function would normally be `cdecl` and end with plain `ret`, not `ret 8`.
- A free `__stdcall` helper is technically possible, but less likely in a private UI-pane source file than a member helper with an unused `this`.
- The physical source island sits between `TabPane` vtable methods and the live `TabPane` resolver.
- The rectangle set is exactly the `TabPane` six-region action surface.

Name ranking:

1. `BuildTabActionRect`: best current name. It matches output-parameter construction and the action-code role.
2. `GetTabActionRect`: acceptable if the project standardizes output-parameter helpers as `Get*Rect`.
3. `BuildTabRect` / `GetTabRect`: acceptable but slightly weaker because the input values are action codes, not necessarily final tab labels.
4. `RawRectangleBuilder`: reject as final source name; keep only as file-title/search history.
5. `SetRect` or `InitRectBounds`: reject as this helper name; those describe the callee `0x004b7c50`, not the TabPane wrapper.

### Rectangle semantics

The raw helper reads `actionCode`, increments it, and switches through seven table entries. Index `0` is the invalid/default rectangle, so `actionCode == -1` also produces invalid bounds. Values outside `0..5` also take the default path.

The valid rectangles are:

| `actionCode` | Rectangle |
| --- | --- |
| `0` | `(2, 1, 20, 46)` |
| `1` | `(2, 47, 20, 93)` |
| `2` | `(2, 95, 20, 140)` |
| `3` | `(2, 142, 20, 187)` |
| `4` | `(2, 189, 20, 234)` |
| `5` | `(2, 236, 20, 281)` |
| default / `-1` | `(-1, -1, -1, -1)` |

Number conversions rechecked with `tools/int_convert.py`:

- `0x14 == 20`
- `0x2e == 46`
- `0x5d == 93`
- `0x8c == 140`
- `0xbb == 187`
- `0xea == 234`
- `0x119 == 281`

The helper called for each rectangle is `0x004b7c50`, documented by [UID:00015S], [UID:0000N2], and `project-level/-resolved.md` as `InitRectBounds` / `RectBounds::SetLTRB`-style geometry support. The target C++ should use the canonical project helper spelling `InitRectBounds` unless a later RectBounds API pass standardizes on `outRect->SetLTRB(...)`.

### Switch table and padding

Direct PE bytes confirm:

- `0x004cfb15-0x004cfb20`: eleven `0xcc` bytes. `0x0b == 11` (Verified with int_convert.py).
- `0x004cfb20-0x004cfc5c`: `0x13c` / decimal `316` bytes (Verified with int_convert.py), including the local table.
- `0x004cfc40-0x004cfc5c`: seven dword table targets.
- `0x004cfc5c-0x004cfc60`: four `0xcc` bytes. `0x04 == 4` (Verified with int_convert.py).
- `0x004cfc60`: successor resolver starts cleanly.

Raw table dwords:

```text
0x004cfc40: 0x004cfc22
0x004cfc44: 0x004cfb38
0x004cfc48: 0x004cfb5e
0x004cfc4c: 0x004cfb84
0x004cfc50: 0x004cfbaa
0x004cfc54: 0x004cfbd2
0x004cfc58: 0x004cfbfa
```

The table is local to the raw helper. Direct PE dword scans found each table target only in this table.

Full raw body/table bytes from the direct PE scan:

```text
55 8b ec 8b 45 08 40 56 83 f8 06 0f 87 f1 00 00 00 ff 24 85 40 fc 4c 00 b8 02 00 00 00 be 2e 00 00 00 56 ba 14 00 00 00 52 8d 48 ff 51 50 ff 75 0c e8 fa 80 fe ff 83 c4 14 5e 5d c2 08 00 b8 02 00 00 00 be 5d 00 00 00 56 ba 14 00 00 00 52 8d 48 2d 51 50 ff 75 0c e8 d4 80 fe ff 83 c4 14 5e 5d c2 08 00 b8 02 00 00 00 be 8c 00 00 00 56 ba 14 00 00 00 52 8d 48 5d 51 50 ff 75 0c e8 ae 80 fe ff 83 c4 14 5e 5d c2 08 00 be bb 00 00 00 ba 14 00 00 00 56 52 b9 8e 00 00 00 b8 02 00 00 00 51 50 ff 75 0c e8 86 80 fe ff 83 c4 14 5e 5d c2 08 00 be ea 00 00 00 ba 14 00 00 00 56 52 b9 bd 00 00 00 b8 02 00 00 00 51 50 ff 75 0c e8 5e 80 fe ff 83 c4 14 5e 5d c2 08 00 be 19 01 00 00 ba 14 00 00 00 56 52 b9 ec 00 00 00 b8 02 00 00 00 51 50 ff 75 0c e8 36 80 fe ff 83 c4 14 5e 5d c2 08 00 83 c8 ff 0b f0 0b d0 56 52 0b c8 51 50 ff 75 0c e8 19 80 fe ff 83 c4 14 5e 5d c2 08 00 90 22 fc 4c 00 38 fb 4c 00 5e fb 4c 00 84 fb 4c 00 aa fb 4c 00 d2 fb 4c 00 fa fb 4c 00
```

## Direct Xref / Route Inventory

| Address / Item | Evidence | Meaning |
| --- | --- | --- |
| `0x004cfb20` | no rel32 calls/jumps, no rel8 branches, no VA/RVA dword hits, no exports; prior IDA docs report no function object/xrefs/pointer hits | No proven live entry route. |
| `0x004cfc40` | one VA hit at `0x004cfb34`, the helper's own indirect switch operand | Local table only. |
| case labels | each VA appears once, inside `0x004cfc40-0x004cfc5c` | Local table only. |
| `0x004cfc60` | rel32 calls from `0x004cfa4c` and `0x004cfaae` | Live resolver route from `TabPane::HandleInputEvent`. |
| `0x004b7c50` | direct PE rel32 scan found 1731 calls | Shared `InitRectBounds` / SetLTRB-style helper, not TabPane-owned. |
| `0x004b7e80` | direct PE rel32 scan found 270 calls | Shared `PointInRect`; used by resolver, not by `00034Q`. |

## Ranked Source Placement Analysis

### 1. `TabPane` class child, emitted through [UID:0000EB]

Evidence for:

- Rectangle geometry exactly matches the six `TabPane` action regions documented by [UID:00034O] and [UID:00034R].
- The raw helper is physically between `TabPane` virtual stubs and the live resolver.
- `ret 8` and two stack arguments fit a non-virtual member helper with unused `this`.
- [UID:0000EB] and [UID:0000OF] already clear the current source gate.
- Current generated output has a viable `TabPane.cpp` route through [UID:0000EB] to [UID:0000OF].

Evidence against:

- No direct call, branch, pointer, vtable, or export route reaches the helper.
- Exact original name is not proven.
- Resolver machine code duplicates/inlines the same rectangle logic and does not call this helper.

Decision:

- Keep this as the direct owner/emitter route. The negative route evidence is now a documented source-shape caveat, not a reason to deassign.

### 2. Inline all rectangle logic into [UID:00034R] and make [UID:00034Q] no-code

Evidence for:

- The live resolver body has its own switch table and direct rectangle initializer calls.
- No route to `0x004cfb20` has been found.
- The current generated `ResolveTabActionCode` call to `BuildTabActionRect` is not a direct machine-code fact.

Evidence against:

- `0x004cfb20` is a complete source-shaped helper, unique in the PE, with member-compatible calling convention.
- Clearing formal C++ would lose a reconstructable source body that likely came from original TabPane source, even if retained dead or inlined elsewhere.
- Active reconstruction policy allows first-draft C++ for eligible emitting targets when source shape is supported; caller proof is not required when the retained body itself is complete and ownership is well supported.

Decision:

- Reject as the primary recommendation. Do document the resolver's direct machine-code behavior and mark the generated helper call as an inlining/source-factoring hypothesis.

### 3. Parent aggregate [UID:000170]

Evidence for:

- [UID:000170] physically contains this range.
- [UID:000170] is the split-inventory context.

Evidence against:

- [UID:000170] is a mixed `TabPane` / `IconsPane` / thunk / table / padding inventory and is intentionally `RECONSTRUCTABLE:FALSE`.
- It is not a source owner or emitter.
- Exact children carry source ownership.

Decision:

- Reject as direct owner/emitter. Keep [UID:000170] as a context/parent inventory only.

### 4. `TabPane.cpp` file-level free/static helper

Evidence for:

- The body does not read `this`, so it could have been source-level static helper logic.
- Physical placement and proposed source file are `TabPane.cpp`.

Evidence against:

- MSVC default internal free/static C++ helpers would normally use `cdecl` and return with plain `ret`; this body uses `ret 8`.
- A free `__stdcall` helper is possible but less idiomatic for private UI geometry helper code.
- Existing class docs model `TabPane` methods around this island and current generated output already uses a member helper.

Decision:

- Weaker alternate. Mention in the target as an unlikely source-shape alternative, but keep class member helper as the first-draft.

### 5. `IconsPane` or shared old-HUD controls helper

Evidence for:

- `IconsPane` and `TabPane` are adjacent old-HUD panels and share action helper families.

Evidence against:

- Geometry is the six vertical `TabPane` region set, not the eight `IconsPane` icon slots.
- No `IconsPane` fields, vtables, singleton, resource strings, or eight-icon dispatch table are used.
- [UID:00022Q] separately documents the raw `IconsPane` action-dispatch duplicate.

Decision:

- Reject.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Best answer / impact |
| --- | --- | --- |
| Is `0x004cfb20` live? | IDA-backed no-function/no-xref docs; direct PE rel32, rel8, VA/RVA, export, and table scans | No live route proven. Treat as retained helper/dead duplicate. Confidence cap remains. |
| Is the helper compiler-generated? | Body shape, table contents, rectangle constants, calls to `InitRectBounds`, returns | No. It is source-authored or source-equivalent project code. |
| Should final source use `BuildTabActionRect`? | Member-compatible `ret 8`, physical TabPane island, resolver relationship, current generated output | Yes as first-draft descriptive name. Exact original spelling unproven. |
| Should resolver source call this helper? | Resolver bytes and rel32 scans show no binary call; current generated source calls helper | Accept as source-level inlining hypothesis only. Add support-doc caveat. |
| Are tab labels known? | TabPane docs, action helper docs, IconsPane comparison | Not safely. Geometry/action-code labels remain behavior-based and do not block this target. |
| Should parent aggregate own/emits? | [UID:000170] split inventory and metadata | No. It is a mixed non-emitting inventory. |
| Should `RectBounds` support docs change? | RectBounds file/class/layout/geometry helper docs already identify `InitRectBounds` and `PointInRect` | No required metadata change; target should use these names. |

## Exact Recommended Target Changes

Target: `by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md`

Recommended metadata:

- Change `COMPLETION:85` to `COMPLETION:87`.
- Change `CONFIDENCE:86` to `CONFIDENCE:89`.
- Keep `CANONICAL_OWNER:0000EB`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000EB`.

Recommended C++ replacement:

```cpp
void TabPane::BuildTabActionRect(int actionCode, RectBounds *outRect) const
{
    switch (actionCode) {
    case 0:
        InitRectBounds(outRect, 2, 1, 20, 46);
        break;
    case 1:
        InitRectBounds(outRect, 2, 47, 20, 93);
        break;
    case 2:
        InitRectBounds(outRect, 2, 95, 20, 140);
        break;
    case 3:
        InitRectBounds(outRect, 2, 142, 20, 187);
        break;
    case 4:
        InitRectBounds(outRect, 2, 189, 20, 234);
        break;
    case 5:
        InitRectBounds(outRect, 2, 236, 20, 281);
        break;
    default:
        InitRectBounds(outRect, -1, -1, -1, -1);
        break;
    }
}
```

Recommended prose additions/changes:

- Replace "reachability is still unproven" as a passive blocker with the concrete route-search result: no rel32 call/jump, no rel8 branch, no VA/RVA dword hit, no export, no non-local table, and prior IDA no-function/no-xref/no-pointer-hit evidence.
- Add that the helper body/table byte pattern is unique in the PE.
- Add exact table target mapping for `0x004cfc40`.
- Add the direct PE boundary facts for prepad/body/table/postpad/successor.
- Add the source-shape policy: retained private `TabPane` helper, likely out-of-line copy of an inlined source helper or dead duplicate; still reconstructable and source-authored.
- Replace `SetRect` wording with `InitRectBounds` / `RectBounds::SetLTRB`-style wording and link the helper to [UID:00015S] / [UID:0000N2] / [UID:0001VP].
- Record that `ecx` is unused, but `ret 8` supports member `thiscall` more than a default `cdecl` file helper.
- Keep caveat that exact original name is unproven.

## Exact Recommended Support-Doc Changes

### `by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md`

- Add a reconstruction note:
  - The binary resolver does not call `0x004cfb20`; it has its own local switch table at `0x004cfd50` and directly calls `InitRectBounds` / `PointInRect`.
  - The current source draft's `BuildTabActionRect` call is a source-level de-duplication/inlining hypothesis.
  - If a later final-source pass rejects that hypothesis, inline the six rectangle cases in this resolver while keeping [UID:00034Q] as retained dead/out-of-line helper code.
- Keep owner/emitter [UID:0000EB].
- No score change required, but raising confidence from `89` to `90` is defensible if the support note is incorporated because the binary-vs-source relationship becomes clearer.

### `by-class/TabPane.md`

- Update the [UID:00034Q] method row to say:
  - retained private `BuildTabActionRect` helper;
  - exact no-route PE scan found no rel32/rel8/VA/RVA/export route;
  - resolver duplicates/inlines the same rectangles;
  - first-draft C++ remains valid as source-level retained helper with inferred name.
- Update the open question "Determine whether raw `0x004cfb20` was source-authored, emitted from dead code, or artifact" to:
  - "Resolved as source-shaped retained TabPane helper/dead or inlined duplicate; no live entry route found."
- Keep final tab-label/action-helper naming as an open broader TabPane issue.
- Score change optional: `86/86 -> 87/87` if the report-level detail is incorporated. Do not raise above final-source confidence while tab labels/action helper names remain open.

### `by-file/TabPane.md`

- Update the raw rectangle-builder row to mirror the class note.
- Add that generated `TabPane.cpp` currently calls `BuildTabActionRect` from `ResolveTabActionCode`; that call is source-level/inlining shape, not a direct binary call.
- Keep `ui/panels/TabPane.cpp`; no file reroute to IconsPane or a new old-HUD source file is recommended.
- Score change optional: `86/85 -> 87/86` if incorporated.

### `by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md`

- Update child inventory score for [UID:00034Q] from `85/86` to `87/89`.
- Add a short child note that B005 direct PE scans confirmed unique body/table bytes and no direct entry route.
- Keep parent `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters/C++.

### `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, `by-file/RectBounds.md`, `by-type/by-struct/RectBoundsLayout.md`

- No required metadata changes.
- Optional cross-reference: add [UID:00034Q] / [UID:00034R] as further high-level users of `InitRectBounds` and `PointInRect` if support docs are being expanded.

### `by-project-structure/proposed-source-tree.md`

- No change recommended. Current `ui/panels/TabPane.cpp` placement remains correct.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this report-only pass.

Current manual coverage has the broad [UID:000170] row at the `0x004cf980-0x004cfe5f` address position but no separate [UID:00034Q] row. If supervisor wants manual coverage to expose the child detail, insert the following row immediately after the existing [UID:000170] row and before the `0x004cfe5f-0x004cfe60` padding row:

```text
        - [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md) 0x004cfb20-0x004cfc5c | retained TabPane rectangle helper | TabPaneRawRectangleBuilder : reconstructable : 87% : very strong : B005 source-quality recheck keeps owner/emitter [UID:0000EB][TabPane](by-class/TabPane.md) and resolves the raw range as a source-shaped retained private `TabPane::BuildTabActionRect(int, RectBounds*)` helper, not padding, thunk, or aggregate-owned table data. Direct PE scans confirm unique body/table bytes, `0x004cfb15-0x004cfb20` and `0x004cfc5c-0x004cfc60` `0xcc` padding, local jump table `0x004cfc40` with default plus six rectangle targets, no rel32/rel8/VA/RVA/export route to `0x004cfb20`, and the table targets referenced only by the local table. The helper writes the six `TabPane` action rectangles through shared `InitRectBounds` (`0x004b7c50`) and writes `(-1,-1,-1,-1)` for default/invalid action codes. The live resolver [UID:00034R] duplicates/inlines the same rectangles and does not call this raw helper, so generated `BuildTabActionRect` use is a source-level inlining/de-duplication hypothesis with confidence capped below final-audit quality.
```

If the supervisor prefers to keep only aggregate rows in manual coverage, update the [UID:000170] parent row summary to mention that [UID:00034Q] is now `87/89` with the no-route PE scan and retained-helper policy above.

## Validator Needs

No validators were run because this was report-only and no by-* docs were edited.

If implementation is accepted, run from `source-3/project-documentation` after edits:

> Executable block R001 was removed from this report and preserved verbatim in [00034Q-TabPaneRawRectangleBuilder-source-quality-removed.md](00034Q-TabPaneRawRectangleBuilder-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage insertion:

> Executable block R002 was removed from this report and preserved verbatim in [00034Q-TabPaneRawRectangleBuilder-source-quality-removed.md](00034Q-TabPaneRawRectangleBuilder-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated side effect if the target C++ body changes from `SetRect` to `InitRectBounds`: `auto-generated/NexusTK/ui/panels/TabPane.cpp` should refresh, but behavior should remain equivalent.

## IDA Rename / Type / Comment Recommendations

No IDA edits were made.

Recommended future IDA actions if an IDA edit pass is authorized:

- Create or force a function at `0x004cfb20` named `TabPane::BuildTabActionRect` or `TabPane_BuildTabActionRect`. Confidence high for behavior/owner, medium-high for exact original name.
- Assign type: `void __thiscall TabPane::BuildTabActionRect(int actionCode, RectBounds *outRect)`. Comment that `this` is unused in the body.
- Name the local table at `0x004cfc40` as `TabPane_BuildTabActionRect_jumpTable`.
- Apply/comment target labels:
  - `0x004cfc22`: default/invalid rectangle;
  - `0x004cfb38`: action `0`;
  - `0x004cfb5e`: action `1`;
  - `0x004cfb84`: action `2`;
  - `0x004cfbaa`: action `3`;
  - `0x004cfbd2`: action `4`;
  - `0x004cfbfa`: action `5`.
- Comment at `0x004cfb20`: "No direct xrefs/pointer/export route found as of B005 2026-06-19 PE scan; retained out-of-line TabPane rectangle helper or dead duplicate. Live resolver inlines same rectangles."
- Comment at `0x004cfc60`: "Does not call `0x004cfb20`; has own switch table at `0x004cfd50` and direct `InitRectBounds`/`PointInRect` calls."
- Keep `0x004b7c50` using canonical `InitRectBounds` / SetLTRB-style helper naming and `0x004b7e80` using `PointInRect` naming.

## Implementation Readiness

Ready for supervisor implementation callback.

Recommended implementation scope:

- Update target [UID:00034Q] metadata/prose/C++.
- Update [UID:00034R] resolver note so the helper-call source draft is not mistaken for a direct binary call.
- Update [UID:0000EB] and [UID:0000OF] support docs to close the raw-helper passive blocker and record current no-route evidence.
- Update [UID:000170] child inventory score/detail for [UID:00034Q].
- Do not edit `by-memory/-coverage-report.md`; use the exact pending insertion row above.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B005/research/00034Q-TabPaneRawRectangleBuilder-source-quality.md`

Modified:

- None outside this report.

Known concurrent worktree state observed before report creation:

- `by-class/TabPane.md`
- `by-file/TabPane.md`
- `by-memory/-coverage-report.md`
- `by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md`
- `by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md`
- `by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md`

Those files were already dirty in the shared worktree and were not edited or reverted by this pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00034Q-TabPaneRawRectangleBuilder-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00034Q"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00034Q-TabPaneRawRectangleBuilder-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00034Q-TabPaneRawRectangleBuilder-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00034Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
