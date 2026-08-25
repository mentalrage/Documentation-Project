** TARGET-REPORT-UID:00022O **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B009 Source-Quality Report: 00022O SimpleHelpPane2FactoryHelpers

## Assignment

- UID: `00022O`
- Target: `source-3/project-documentation/by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/00022O-SimpleHelpPane2FactoryHelpers-source-quality.md`
- Mode: report-only research. I did not edit target/support by-* pages, generated files, project-level files, manual `-coverage-report.md` files, tool state, or the IDA database.
- Current target metadata in the by-memory header: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU`, blank formal C++.
- Queue/generator mismatch: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, and generated `HelpPanes.cpp` still show stale `78/86`/empty-emitter state for this UID. The target page itself is already `85/88`.

## Recommendation Summary

[UID:00022O] should remain a reconstructable HelpPanes helper cluster routed through [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md), but it should no longer keep formal C++ blank. Current IDA MCP session `80de0a67` reconfirms the exact raw bodies, no modeled function objects at the three raw starts, no direct xrefs or literal pointer routes to the raw starts, exact calls into the source-ready [UID:00016T][SimpleHelpPane2Factory](../../../../../by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md), and exact predicate dependencies on `g_pEventMan`, pane screen offset, `RectBounds::Offset`, `RectBounds::IsEmptyOrInvalid`, and `PointInRect`.

Recommended target metadata after implementation callback:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000JU
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JU
EMITTER_POSITION_OPTIONAL:
```

Reason not lower:

- The three executable helper bodies are exact and bounded: `0x004c77e0-0x004c7808`, `0x004c7810-0x004c7845`, and `0x004c7850-0x004c78db`.
- The adjacent factory is now source-ready and emits formal `CreateSimpleHelpPane2` C++ through [UID:0000JU].
- The first two helpers are ordinary file-local wrapper/adaptor bodies into that factory.
- The third helper is an ordinary `SimpleHelpPane2` cursor/anchor predicate over already documented `EventMan`, pane offset, and rectangle helper dependencies.
- The lack of direct raw-start xrefs has now been researched with current IDA xrefs, MCP `find_bytes`, and an independent static literal scan. It is a confidence cap, not a reason to omit source-shaped code.

Reason not higher:

- IDA still has no modeled function objects at `0x004c77e0`, `0x004c7810`, or `0x004c7850`.
- IDA and static scans still find no direct caller/data route to those raw starts.
- Original symbol spellings for the two wrapper names, predicate name, `HelpPaneStyle`, and the exact private member names remain inferred.
- The first wrapper's public call surface is not directly observed; current disassembly proves it swaps its incoming third/fourth stack values before the canonical factory call, but no caller proves the original parameter names.

## Evidence Checked

- Target page [UID:00022O][SimpleHelpPane2FactoryHelpers](../../../../../by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md).
- Parent source-family page [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md).
- Class page [UID:0000D7][SimpleHelpPane2](../../../../../by-class/SimpleHelpPane2.md).
- Adjacent source-ready factory [UID:00016T][SimpleHelpPane2Factory](../../../../../by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) and executed B009 report `executed-b-agent-research/B009/00016T-SimpleHelpPane2Factory-source-quality.md`.
- Singleton storage [UID:0001OY][g_pSimpleHelpPane2](../../../../../by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md).
- `g_pEventMan` storage [UID:00028L][0x0067a754-0x0067a758.g_pEventMan](../../../../../by-memory/0x0067a754-0x0067a758.g_pEventMan.md).
- Rectangle support pages [UID:00015Q][RectBoundsMethods](../../../../../by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md), [UID:00022G][RectBoundsPredicateAndCombinationMethods](../../../../../by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md), and [UID:00015S][RectGeometryHelpers](../../../../../by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md).
- Generated/tracker state for `00022O` in `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`, and `by-memory/-coverage-report.md`.

## IDA MCP Evidence

Session and health:

- MCP session `80de0a67`, active worker backend, `NexusTK.exe.i64`.
- `server_health` reports status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

Modeled function boundaries:

- `lookup_funcs` returns `sub_4C7680` at `0x004c7680`, size `0x160`.
- `lookup_funcs` returns no function for `0x004c77e0`, `0x004c7808`, `0x004c7810`, `0x004c7845`, `0x004c7850`, or `0x004c78db`.
- `lookup_funcs` returns the next modeled function `sub_4C78E0` at `0x004c78e0`, size `0x296`.
- `lookup_funcs` resolves predicate callees: `sub_4A9090` at `0x004a9090`, `sub_5447C0` at `0x005447c0`, `sub_4B78F0` at `0x004b78f0`, `sub_4B7670` at `0x004b7670`, `sub_4B7E80` at `0x004b7e80`, and the factory-side rectangle offset helper `sub_4B7E10` at `0x004b7e10`.

Xrefs and pointer-route checks:

- `xrefs_to` reports zero cross-references to `0x004c77e0`, `0x004c7810`, `0x004c7850`, and `0x004c78db`.
- `xrefs_to 0x004c7680` reports three refs: modeled caller `0x0045213c` in `sub_451C90`, raw wrapper call `0x004c77fe`, and raw wrapper call `0x004c783b`.
- `find_bytes` finds zero matches for little-endian VA patterns `E0 77 4C 00`, `10 78 4C 00`, `50 78 4C 00`, and `DB 78 4C 00`.
- Independent read-only static scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` finds zero VA, RVA, or raw-file-offset literal hits for `0x004c77e0`, `0x004c7808`, `0x004c7810`, `0x004c7845`, `0x004c7850`, `0x004c78db`, and `0x004c78e0`.
- Broad `search_text` over the full listing timed out inside the MCP. MCP health immediately afterwards remained `ok`; targeted xref/byte/function calls succeeded. This timeout does not invalidate the targeted evidence.

Raw bytes and instruction proof:

- `get_bytes 0x004c77e0 size 0x100` matches the three helper bodies and internal alignment bytes.
- `insn_query 0x004c77e0-0x004c7808` returns a 15-instruction wrapper that pushes nine arguments, calls `sub_4C7680` at `0x004c77fe`, cleans `0x24` stack bytes, and returns.
- `insn_query 0x004c7810-0x004c7845` returns a 23-instruction anchor-rect wrapper. It loads `anchorRect` from `[ebp+10h]`, computes `y = top - 6`, computes signed midpoint `x = (left + right) / 2` using `cdq/sub/sar`, preserves the rectangle pointer as the fifth factory argument, calls `sub_4C7680` at `0x004c783b`, cleans `0x24`, and returns.
- `insn_query 0x004c7850-0x004c78db` returns a 50-instruction thiscall predicate. It reads `dword_67A754`, calls `sub_4A9090`, calls `sub_5447C0`, copies `this + 0x224`, offsets the local copy through `sub_4B78F0`, tests the original stored rectangle through `sub_4B7670`, checks cursor containment through `sub_4B7E80`, and returns true at `0x004c78ce` or false by preserving `al == 0` from the containment call.

Callee decompilation used for names:

- `decompile 0x004a9090`: writes `this[1]` and `this[2]` into an output two-int point. In the documented EventMan context this is `EventMan::GetCursorPosition`.
- `decompile 0x005447c0`: returns a two-int screen offset into the caller-provided point, using parent/control state when present and zero otherwise. This supports `GetScreenOffset`.
- `decompile 0x004b78f0`: adds `dx`/`dy` to the four rectangle edges. This supports `RectBounds::Offset`.
- `decompile 0x004b7670`: returns `bottom <= top || right <= left`. This supports `RectBounds::IsEmptyOrInvalid`.
- `decompile 0x004b7e80`: returns half-open point containment with argument order `y, x, bounds`.
- `decompile 0x004b7e10`: cdecl rectangle-offset helper used by the adjacent factory; it is equivalent to offsetting a supplied `RectBounds *`.

## Positive Evidence

- The helper island is physically between the source-ready `CreateSimpleHelpPane2` factory and `WillBeChangedItemPane`, inside the HelpPanes family documented by [UID:0000JU].
- The two wrappers call only `sub_4C7680`, whose target already emits formal source-shaped `CreateSimpleHelpPane2` code.
- The second wrapper independently confirms the canonical factory argument roles: text, owner, `x`, `y`, optional anchor rectangle, timeout, horizontal alignment, vertical alignment, and style pointer.
- The first wrapper is not just a blind forwarder. Its live disassembly pushes `[ebp+10h]` before `[ebp+14h]`, so the canonical factory receives wrapper parameter 4 as `x` and wrapper parameter 3 as `y`. The implementation should document this as a coordinate-order adapter, not as same-order `x, y` forwarding.
- The predicate is ordinary source-authored logic: current cursor, screen offset, local copy of the stored anchor rectangle, offset to screen space, empty-anchor permissive case, and half-open point-in-rectangle test.
- `g_pEventMan` and `g_pSimpleHelpPane2` are resolved globals; the report does not need to leave `dword_67A754` or `dword_67A7D4` in source-facing prose.

## Negative Evidence And Resolution

- No IDA-modeled function objects exist at the raw starts. Resolution: keep the page below final-audit confidence, but do not omit source. The bodies are complete, prologue/epilogue-bounded, and source-shaped.
- No direct raw-start xrefs or literal pointer routes exist. Resolution: this likely reflects retained static/helper code, stale analysis boundaries, or source helpers whose visible caller was optimized away/removed. It does not make the bytes compiler-only glue, because the bodies contain ordinary wrapper/predicate semantics and are not ABI thunks, jump tables, or padding.
- Original names are not symbol-proven. Resolution: use descriptive, human source-facing names and record them as inferred. Do not use `sub_4C77E0`, `sub_4C7810`, `sub_4C7850`, `dword_67A754`, or `dword_67A7D4` in the formal C++.
- The predicate's call surface is not proven by xrefs. Resolution: the receiver is `ecx`, the state is `SimpleHelpPane2 + 0x224`, and support docs already place `+0x224` as the anchor rectangle. Emit it as a private/nonvirtual `SimpleHelpPane2` method in the HelpPanes source block.

## Heuristic And Inference Decisions

Recommended source-facing names:

| Raw start | Recommended name | Rationale |
| --- | --- | --- |
| `0x004c77e0` | `CreateSimpleHelpPane2Forward` | File-local adapter into the canonical factory. The formal signature should expose incoming `y, x` order because the body swaps those positions before calling `CreateSimpleHelpPane2(text, owner, x, y, ...)`. |
| `0x004c7810` | `CreateSimpleHelpPane2FromAnchorRect` | Computes an anchor point from the supplied rectangle and then calls the canonical factory. |
| `0x004c7850` | `SimpleHelpPane2::IsCursorInsideAnchorRect` | Uses current cursor and screen-adjusted stored anchor rectangle to decide whether the cursor remains inside the anchor area; an empty/invalid stored anchor returns true, meaning no anchor restriction is active. |

`CreateSimpleHelpPane2Forward` is descriptive rather than proven original spelling. A future project-wide naming pass may choose a better file-local adapter name, but the coordinate-order semantics and wrapper relationship should remain.

`IsCursorInsideAnchorRect` is the best current member-style name. The empty/invalid anchor behavior is intentionally permissive; if no valid anchor exists, the method returns true rather than treating the cursor as outside.

## By-Structure And Split Decision

No by-structure split is required before implementation. This page already has a precise executable range and all three bodies belong to the same HelpPanes/SimpleHelpPane2 helper neighborhood. The two wrappers are file-local factory adapters; the third body is a `SimpleHelpPane2` member predicate, but all three should emit through the same HelpPanes source file. A future child split is allowed if the supervisor wants method-level pages, but it is not required to make the current range source-ready.

Internal padding policy:

- Keep `0x004c7808-0x004c7810` and `0x004c7845-0x004c7850` documented as alignment, not formal C++.
- Keep trailing `0x004c78db-0x004c78e0` in [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md), not this page.

## Formal C++ Recommendation

Recommended exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:00022O]:

```cpp
static SimpleHelpPane2 *CreateSimpleHelpPane2Forward(
    const wchar_t *text,
    Pane *owner,
    int y,
    int x,
    const RectBounds *anchorRect,
    int timeoutMs,
    int horizontalAlign,
    int verticalAlign,
    const HelpPaneStyle *style)
{
    return CreateSimpleHelpPane2(text, owner, x, y, anchorRect, timeoutMs,
                                 horizontalAlign, verticalAlign, style);
}

static SimpleHelpPane2 *CreateSimpleHelpPane2FromAnchorRect(
    const wchar_t *text,
    Pane *owner,
    const RectBounds *anchorRect,
    int timeoutMs,
    int horizontalAlign,
    int verticalAlign,
    const HelpPaneStyle *style)
{
    const int x = (anchorRect->left + anchorRect->right) / 2;
    const int y = anchorRect->top - 6;

    return CreateSimpleHelpPane2(text, owner, x, y, anchorRect, timeoutMs,
                                 horizontalAlign, verticalAlign, style);
}

bool SimpleHelpPane2::IsCursorInsideAnchorRect()
{
    Point cursor;
    g_pEventMan->GetCursorPosition(&cursor);

    Point screenOffset;
    GetScreenOffset(&screenOffset);

    RectBounds anchorRect = m_anchorRect;
    anchorRect.Offset(screenOffset.x, screenOffset.y);

    if (m_anchorRect.IsEmptyOrInvalid())
        return true;

    return PointInRect(cursor.y, cursor.x, &anchorRect);
}
```

Formal C++ caveats:

- `HelpPaneStyle` is still the same descriptive placeholder accepted by [UID:00016T].
- `Point` is the existing project-style two-int point abstraction used by current sketches. If the project settles a different source name, keep the two-int cursor/offset roles.
- `m_anchorRect` is the source-facing name for the `this + 0x224` rectangle. If the class field naming pass settles `m_anchorBounds` or another name, update consistently.
- The first wrapper intentionally uses incoming `y, x` parameter order. Changing it to `x, y` would not match the observed stack forwarding.
- Security-cookie checks, vtable stores, and raw address labels must not be emitted in source.

## Recommended Target Changes For Implementation Callback

Header:

```diff
- *** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
- *** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
+ *** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
+ *** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep unchanged:

```text
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the current source sketch with the formal C++ above, and put the same code between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`.

Update the covered-range notes:

- `0x004c77e0-0x004c7808`: describe as a coordinate-order adapter forwarding to `CreateSimpleHelpPane2`; it passes incoming wrapper parameter 4 as canonical `x` and parameter 3 as canonical `y`.
- `0x004c7810-0x004c7845`: keep as anchor-rect wrapper computing `x = (left + right) / 2`, `y = top - 6`.
- `0x004c7850-0x004c78db`: rename source-facing role from vague refresh wording to `SimpleHelpPane2::IsCursorInsideAnchorRect` or equivalent private predicate; document true when stored anchor is empty/invalid or cursor is inside the screen-adjusted anchor rectangle.

Add current-session evidence:

- MCP session `80de0a67` health ready.
- `lookup_funcs` raw-start/no-function evidence.
- `xrefs_to` zero raw-start xrefs and three `0x004c7680` refs.
- `find_bytes` and static literal scan zero raw-start pointer-route evidence.
- `insn_query` exact wrapper/predicate instruction evidence.
- Predicate callee decompile names for cursor position, screen offset, rectangle offset, empty test, and point containment.

Add change-log entry:

```markdown
- 2026-06-26 B009 source-quality report:
  - Before: `85/88`, owner/emitter [UID:0000JU][HelpPanes](by-file/HelpPanes.md), reconstructable, but formal C++ blank and old prose treated raw-start/no-xref/name uncertainty as a source-code blocker.
  - Recommended after implementation: `88/90`, same owner/emitter route, formal C++ for the two `CreateSimpleHelpPane2` wrapper/adapters and the `SimpleHelpPane2::IsCursorInsideAnchorRect` predicate.
  - Evidence: live MCP session `80de0a67` reconfirms no modeled raw-start functions, zero direct raw-start xrefs, zero raw-start VA/RVA/raw-offset literal routes, exact wrapper calls at `0x004c77fe` and `0x004c783b`, coordinate-order swap in the first wrapper, anchor-rect midpoint/top-minus-six computation in the second wrapper, predicate reads of `g_pEventMan`, screen-offset and rectangle-helper calls, stored anchor rectangle at `+0x224`, and successor boundary `0x004c78e0`.
```

## Recommended Support-Doc Changes

[UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md):

- Update the SimpleHelpPane2 row/data caveat to state that [UID:00022O] is now recommended for first-draft formal C++ rather than blank C++.
- Record the first-wrapper coordinate-order adapter finding so future readers do not copy the stale same-order wrapper sketch.

[UID:0000D7][SimpleHelpPane2](../../../../../by-class/SimpleHelpPane2.md):

- Update the helper row to call the predicate `IsCursorInsideAnchorRect` or equivalent and note that no valid anchor means the predicate returns true.
- Keep the class formal C++ blank; the source body belongs on the by-memory child page.

[UID:0001OY][g_pSimpleHelpPane2](../../../../../by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md):

- Remove or soften the statement that [UID:00022O] still needs deeper reconstruction before the singleton can be graded near-complete. The helper page now has a current report and formal C++ recommendation; remaining uncertainty is direct raw-start reachability and original spelling, not behavior.

No support-doc edit should touch generated/project-level files or any manual `-coverage-report.md`.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` as B009. If the supervisor accepts and implementation succeeds, replace the current `00022O` row with:

```markdown
    - [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) 0x004c77e0-0x004c78db | raw-function-cluster | SimpleHelpPane2FactoryHelpers : reconstructable : 88% : strong : Source-ready HelpPanes helper cluster with two `CreateSimpleHelpPane2` wrapper/adapters and one `SimpleHelpPane2` cursor/anchor predicate; current MCP session `80de0a67` reconfirms no modeled raw-start functions, no direct raw-start xrefs, no VA/RVA/raw-offset pointer routes, exact wrapper calls into [UID:00016T], first-wrapper coordinate-order swap, anchor-rect midpoint/top-minus-six wrapper, stored anchor rectangle at `+0x224`, `g_pEventMan` cursor read, screen-offset/RectBounds offset/empty/PointInRect dependencies, owner/emitter [UID:0000JU], and formal first-draft C++ readiness while original helper spellings and direct raw-start reachability remain below final-audit certainty.
```

The generated `auto-generated/-ag-memory-coverage.md` row should move from empty-emitter marker/no C++ to coded/emitting after validators/autogen refresh if the formal block is inserted.

## Validator Needs

No validator was run for this report-only phase because no by-* files were changed.

If the supervisor sends an implementation callback, run scoped validators after edits from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00022O-SimpleHelpPane2FactoryHelpers-source-quality-removed.md](00022O-SimpleHelpPane2FactoryHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the manual coverage row, validate it separately:

> Executable block R002 was removed from this report and preserved verbatim in [00022O-SimpleHelpPane2FactoryHelpers-source-quality-removed.md](00022O-SimpleHelpPane2FactoryHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Checklist

Supervisor validation phase:

- [x] Supervisor verifies this report's current-session MCP evidence and accepts or rejects the `88/90` recommendation. Proof: 2026-06-26 supervisor callback accepted this report for implementation and explicitly accepted the raw-start/no-xref state as a confidence cap rather than a deferral.
- [x] Supervisor verifies the first-wrapper `y, x` formal signature and coordinate-order adapter wording before authorizing implementation. Proof: 2026-06-26 supervisor callback accepted the first-wrapper `y, x` formal signature/coordinate-order adapter wording.
- [x] Supervisor verifies the predicate name `IsCursorInsideAnchorRect` or selects an equivalent source-facing name before authorizing implementation. Proof: 2026-06-26 supervisor callback accepted `SimpleHelpPane2::IsCursorInsideAnchorRect` as the current best source-facing predicate name.

B009 implementation callback phase, only after supervisor acceptance:

- [x] Lease only immediate edit files, then release leases immediately after edits/validator batch. Proof: B009 leased exactly `by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md`, `by-file/HelpPanes.md`, `by-class/SimpleHelpPane2.md`, and `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md` at `2026-06-26T18:29:14Z` for the edit/validator batch. Explicit unlease after validation returned `Rejected[No active lease]` for all four paths because the short leases had already expired/cleared; `current_leases.md` then showed no B009 rows.
- [x] Update [UID:00022O] header to `88/90` and keep owner/emitter/reconstructable metadata unchanged. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU`, blank emitter position; validator command `000000002677` confirmed completion/confidence/canonical owner/autogen registry updates with `ok: 1`.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block in [UID:00022O]. Proof: target formal block now contains `CreateSimpleHelpPane2Forward`, `CreateSimpleHelpPane2FromAnchorRect`, and `SimpleHelpPane2::IsCursorInsideAnchorRect`; validator command `000000002677` reported `blank -> block` and `ok: 1`.
- [x] Update [UID:00022O] prose with coordinate-order adapter, current MCP evidence, no-pointer-route evidence, score rationale, and change-log entry. Proof: target now documents the `y, x` incoming adapter, MCP session `80de0a67`, raw-start/no-function evidence, zero xrefs/pointer routes, instruction/callee evidence, `88/90` rationale, and a 2026-06-26 change-log entry; validator command `000000002677` passed with `ok: 1`.
- [x] Update [UID:0000JU] support wording to remove stale blank-C++ language for [UID:00022O]. Proof: `by-file/HelpPanes.md` now says [UID:00022O] carries first-draft formal C++ and preserves the first-wrapper `y, x` coordinate-order adapter; validator command `000000002678` passed with `ok: 1`.
- [x] Update [UID:0000D7] helper row/predicate naming and keep class formal C++ blank. Proof: `by-class/SimpleHelpPane2.md` now uses `factory adapters / IsCursorInsideAnchorRect`, documents the empty/invalid-anchor true case, and keeps the class formal C++ block blank; validator command `000000002679` passed with `ok: 1`.
- [x] Update [UID:0001OY] stale "needs deeper reconstruction" wording for [UID:00022O]. Proof: `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md` now states the factory/helper behavior/source C++ is resolved at first-draft quality while raw-start reachability/original spellings/header placement remain confidence caps; validator command `000000002680` passed with `ok: 1`.
- [x] Do not edit generated/project-level files, tool state, IDA DB, or any `-coverage-report.md`. Proof: B009 manually edited only the four accepted by-* docs plus this report checklist. Validators reported expected generated/projected-stat/autogen-registry side effects, but B009 did not manually edit generated/project-level/tool/coverage files or IDA DB.
- [x] Run scoped validators for changed by-* files and record command/result proof in this report. Proof:
  - `python .\tools\validator.py --mode file --file by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md --apply --queue-timeout 240` -> command `000000002677`, timestamp `2026-06-26T14:33:37-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file/HelpPanes.md --apply --queue-timeout 240` -> command `000000002678`, timestamp `2026-06-26T14:33:45-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/SimpleHelpPane2.md --apply --queue-timeout 240` -> command `000000002679`, timestamp `2026-06-26T14:33:56-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md --apply --queue-timeout 240` -> command `000000002680`, timestamp `2026-06-26T14:34:04-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- [x] If any recommended item is already present, stale, or not applicable, record exact proof in this checklist before returning implementation. Proof: manual coverage-row text from the report was explicitly excluded by the supervisor callback; no coverage file was edited. Known validator diagnostics for missing older UID/target references in HelpPanes/SimpleHelpPane2/00014C were left untouched because they are pre-existing registry/reference issues outside this accepted callback.

Supervisor-only after implementation:

- [ ] Supervisor verifies implementation claim by claim.
- [ ] Supervisor moves the report to `research/executed/` only after verification.
- [ ] Supervisor applies the pending manual `by-memory/-coverage-report.md` row and validates it.

## Changed Files

Only this report file was created during report-only work:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/00022O-SimpleHelpPane2FactoryHelpers-source-quality.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00022O-SimpleHelpPane2FactoryHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00022O-SimpleHelpPane2FactoryHelpers-source-quality.md","timestamp":"2026-06-26T14:42:10","uid":"00022O"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022O-SimpleHelpPane2FactoryHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00022O-SimpleHelpPane2FactoryHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
