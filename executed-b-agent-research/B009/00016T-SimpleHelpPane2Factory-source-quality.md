** TARGET-REPORT-UID:00016T **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B009 Source-Quality Report: 00016T SimpleHelpPane2Factory

## Assignment

- UID: `00016T`
- Target: `source-3/project-documentation/by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/00016T-SimpleHelpPane2Factory-source-quality.md`
- Scope: B-agent research/report only. I did not edit the target by-memory page, support by-* pages, generated files, or `by-memory/-coverage-report.md`.
- Prior B009 report preservation: `00012L-DescPaneDestructor-source-quality.md` and `00013H-EncoderWriteInt-source-quality.md` remain present and were not moved or overwritten.

## Recommendation Summary

`00016T` should remain a reconstructable HelpPanes helper routed through [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md), emitting to `NexusTK/ui/controls/HelpPanes.cpp`.

The current target text still says to leave C++ blank until final factory name/source visibility is proven. That is stale under the active source-entry gate. The page is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:0000JU`, reaches a valid generated source file, and its current `84/90` average is already `87 > 85`. The recommended `88/90` update makes the first-draft readiness explicit without claiming rare final-audit `95+` certainty.

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000JU
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JU
EMITTER_POSITION_OPTIONAL:
```

Recommended first-draft C++ readiness: ready after supervisor implementation callback. The best source shape is a file-local HelpPanes factory, best named `CreateSimpleHelpPane2` with `ShowSimpleHelpPane2` as a reasonable command-style alias. Exact historical symbol spelling, the style typedef name, and whether the original helper returned `SimpleHelpPane2 *` or `void` remain descriptive-source questions, but they do not block a source-faithful first draft.

## Evidence Checked

- Target `00016T` currently documents `sub_4C7680`, exact range `0x004c7680-0x004c77e0`, size `0x160`, one modeled caller at `0x0045213c`, and raw wrapper calls at `0x004c77fe` and `0x004c783b`.
- Current target behavior covers `g_pSimpleHelpPane2` reads/writes at `0x004c76ad`, `0x004c772a`, and `0x004c7731`; replacement guard byte `+0xf4`; `0x234` allocation; base [UID:000063][HelpPane](../../../../../by-class/HelpPane.md) construction; `SimpleHelpPane2` vtable stores; anchor rectangle copy/clear at `+0x224`; rectangle translation; and timer scheduling through `0x005975e0`.
- [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md) owns the HelpPane/SimpleHelpPane/SimpleHelpPane2 family and has proposed output path `NexusTK/ui/controls/`. Its generated `HelpPanes.cpp` currently contains only an empty emitter marker for `00016T`.
- [UID:0000D7][SimpleHelpPane2](../../../../../by-class/SimpleHelpPane2.md) documents the class side of this factory: `SimpleHelpPane2` derives from `HelpPane`, owns anchor/timer behavior, uses `g_pSimpleHelpPane2`, and has this factory plus adjacent helpers as its construction surface.
- [UID:000063][HelpPane](../../../../../by-class/HelpPane.md) documents the base constructor at `0x004c6960`, embedded text/geometry state, and vtable/subobject layout used by the factory.
- [UID:00016S][SimpleHelpPanes](../../../../../by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md) documents the preceding SimpleHelpPane/SimpleHelpPane2 method cluster and confirms that `0x004c7680` is the successor factory boundary.
- [UID:00022O][SimpleHelpPane2FactoryHelpers](../../../../../by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) documents the adjacent raw helper island. Two wrappers forward into this factory and prove the nine-argument source shape. The second wrapper computes `x = (left + right) / 2` and `y = top - 6` from an anchor rectangle.
- [UID:0001OY][g_pSimpleHelpPane2](../../../../../by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md) and [UID:0000SA][g_pSimpleHelpPane2](../../../../../by-global/g_pSimpleHelpPane2.md) confirm the singleton address `0x0067a7d4`, all project xrefs, and HelpPanes global ownership.
- [UID:0001K8][TimerHandlerScheduleRemoveWrappers](../../../../../by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) confirms `0x005975e0` as the generic timer schedule wrapper used by this factory.
- [UID:00008C][MiniMapDialog](../../../../../by-class/MiniMapDialog.md) and [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md) confirm the modeled caller is a minimap hover consumer only, not the implementation owner.
- Current generated `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` still reports `00016T` as an empty emitter marker.
- Current `auto-generated/-ag-memory-coverage.md` still shows `00016T` emitting through owner/emitter `0000JU` to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`.
- Current `project-level/-auto-completion-stats.md` reports `00016T | 84 | 90 | 87.0`.
- Current `by-memory/-coverage-report.md` row still reports `84%`.
- Current-session IDA MCP availability check failed with `Unable to connect to the remote server`, so this pass relies on the recorded live-IDA evidence already present in the by-* docs.

## Source Shape And Behavior

Best source-facing signature:

```cpp
static SimpleHelpPane2 *CreateSimpleHelpPane2(
    const wchar_t *text,
    Pane *owner,
    int x,
    int y,
    const RectBounds *anchorRect,
    int timeoutMs,
    int horizontalAlign,
    int verticalAlign,
    const HelpPaneStyle *style);
```

`ShowSimpleHelpPane2` is also defensible if the final source convention prefers command-style names for side-effect-only UI popup helpers. I recommend `CreateSimpleHelpPane2` for the first draft because both adjacent wrappers are construction forwarders and the helper allocates a new object when replacement is allowed.

The nine-argument order is resolved strongly enough for source drafting:

| Arg | Role | Evidence |
| --- | --- | --- |
| `text` | UTF-16 tooltip text | MiniMap caller builds a 1024-wide-character stack buffer; HelpPane family uses wide text. |
| `owner` | owning/relative `Pane` pointer | Factory computes owner/control geometry and constructs a HelpPane-derived popup. |
| `x` | text/popup anchor X | Direct caller and raw anchor-rect wrapper feed this into the factory. |
| `y` | text/popup anchor Y | Direct caller and raw anchor-rect wrapper feed this into the factory; wrapper uses `top - 6`. |
| `anchorRect` | optional stored anchor rectangle | Copied/cleared at object offset `+0x224`; raw wrapper preserves the rectangle pointer. |
| `timeoutMs` | auto-hide duration | MiniMap caller passes `5000`; factory schedules timer through `0x005975e0`. |
| `horizontalAlign` | horizontal text/popup style | MiniMap caller passes `2`. Exact enum name is not proven. |
| `verticalAlign` | vertical text/popup style | MiniMap caller passes `2`. Exact enum name is not proven. |
| `style` | HelpPane text/style state | MiniMap caller builds style state with two style runs. Exact typedef/class name is not proven. |

Resolved behavior:

- If `g_pSimpleHelpPane2` is non-null and byte `+0xf4` on the existing object is set, return without replacing the current tooltip.
- If an existing singleton is present and replacement is allowed, close/delete it through virtual slot `0` with deleting flag `1`. Source-level reconstruction should use `delete pane;`.
- Allocate `0x234` bytes for the full `SimpleHelpPane2` object. The binary shows allocator/null-handling details, but source-level first draft can express this as `new SimpleHelpPane2(...)`.
- The factory body contains an inlined construction sequence: base `HelpPane` constructor at `0x004c6960`, `SimpleHelpPane2` vtable installs at `+0x0`, `+0xa0`, and `+0xa4`, and singleton publication to `g_pSimpleHelpPane2`.
- If `anchorRect` is non-null, copy it into `this + 0x224` and translate it with `sub_4B7E10` using deltas derived from the measured pane bounds and caller origin.
- If `anchorRect` is null, clear the four rectangle dwords at `+0x224`.
- Schedule the auto-hide timer through the timer/event subobject at `+0xa4`.
- No evidence makes this a MiniMap-owned function. The MiniMap path is just one visible consumer.

## First-Draft C++ Candidate

Recommended code to enter in the target page after implementation authorization:

```cpp
static SimpleHelpPane2 *CreateSimpleHelpPane2(
    const wchar_t *text,
    Pane *owner,
    int x,
    int y,
    const RectBounds *anchorRect,
    int timeoutMs,
    int horizontalAlign,
    int verticalAlign,
    const HelpPaneStyle *style)
{
    SimpleHelpPane2 *pane = g_pSimpleHelpPane2;
    if (pane != 0)
    {
        if (pane->m_preventReplacement)
            return pane;

        delete pane;
    }

    new SimpleHelpPane2(text, owner, x, y, anchorRect, timeoutMs,
                        horizontalAlign, verticalAlign, style);
    return g_pSimpleHelpPane2;
}
```

Implementation notes:

- `m_preventReplacement` is the best descriptive name for byte `+0xf4`; exact original field name is not proven.
- `HelpPaneStyle` is a placeholder descriptive type for the style object passed by the MiniMap caller. If the coordinated HelpPane class work establishes a different style type, use that type without changing the argument role/order.
- A `void ShowSimpleHelpPane2(...)` form would also preserve all known caller behavior because the confirmed caller uses the singleton side effect. I still recommend pointer return for first draft because the raw wrappers forward through the call result and the protected-object branch naturally returns the existing singleton.
- Do not expand the source body into manual vtable stores. The stores are constructor semantics visible in the optimized/inlined binary, not a reason to write raw object-layout code in the source reconstruction.
- Keep [UID:00022O][SimpleHelpPane2FactoryHelpers](../../../../../by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) out of this target's C++ block. It owns the adjacent wrapper/predicate island.

## Owner And Emitter Routing

Keep:

```text
CANONICAL_OWNER:0000JU
EMITTER_UIDS:0000JU
```

Rationale:

- The factory constructs a `SimpleHelpPane2`, which is part of the HelpPane/SimpleHelpPane/SimpleHelpPane2 family already grouped under [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md).
- It mutates only `g_pSimpleHelpPane2` plus state inside the newly created HelpPane-derived object.
- [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md) is the current source-family owner and routes to `NexusTK/ui/controls/HelpPanes.cpp`.
- [UID:00008C][MiniMapDialog](../../../../../by-class/MiniMapDialog.md) and [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md) are consumer docs. The direct call at `0x0045213c` does not move ownership to MiniMap.
- [UID:0001K8][TimerHandlerScheduleRemoveWrappers](../../../../../by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md), rectangle helpers, and allocation helpers are dependencies, not owners.

## Compiler-Generated And Raw-Name Handling

Recommended names:

| Raw/generated name | Recommended documentation/source name | Action |
| --- | --- | --- |
| `sub_4C7680` | `CreateSimpleHelpPane2` / `ShowSimpleHelpPane2` | Exact target factory. Prefer `CreateSimpleHelpPane2` for first-draft C++. |
| `dword_67A7D4` | `g_pSimpleHelpPane2` | Already resolved singleton global; use this name consistently. |
| `sub_451C90` | `MiniMapDialog::OnTimerEvent` or minimap hover event handler | Caller only; do not route ownership through MiniMap. |
| `sub_4F4AA0` | project allocator / `operator new` equivalent | Dependency for `0x234` allocation. |
| `sub_4C6960` | `HelpPane::HelpPane` | Base constructor call in the inlined `SimpleHelpPane2` construction sequence. |
| `sub_5975E0` | `TimerHandler::ScheduleTimer` or schedule wrapper | Dependency for auto-hide timer scheduling. |
| `sub_5447C0` | pane/control screen offset helper | Geometry dependency; exact source name remains outside this target. |
| `sub_544B80` | pane/control bounds or measurement helper | Geometry dependency; exact source name remains outside this target. |
| `sub_4B7E10` | rectangle offset/translate helper | Used to shift stored anchor rectangle. |
| `0x004c77e0` / `0x004c7810` / `0x004c7850` | `CreateSimpleHelpPane2Forward`, `CreateSimpleHelpPane2FromAnchorRect`, `SimpleHelpPane2AnchorNeedsRefresh` | Adjacent raw helper bodies owned by `00022O`, not this C++ block. |

This function is source-authored UI helper logic, not compiler-only glue. The security-cookie call is compiler-generated epilogue support and should not appear in source. The vtable stores are constructor effects visible in the optimized factory body; they should be represented by `new SimpleHelpPane2(...)` or an equivalent constructor call, not by raw vtable writes.

## Open Questions

- Exact original helper spelling is not proven. `CreateSimpleHelpPane2` is the best construction-oriented name; `ShowSimpleHelpPane2` remains a plausible alias if later source naming favors popup commands.
- Exact original return type is not proven. `SimpleHelpPane2 *` is the best first-draft choice because the protected-object branch and wrappers can naturally forward a pointer; `void` is still behaviorally compatible with the confirmed MiniMap caller.
- Exact style parameter type/name is not proven. Keep the role/order but update `HelpPaneStyle` if the HelpPane text/style docs establish the real project type.
- Exact field name for byte `+0xf4` is not proven. `m_preventReplacement` is descriptive and source-usable.
- Geometry helper names for `sub_5447C0`, `sub_544B80`, and `sub_4B7E10` are not final-source quality, but the factory's own body can call the higher-level `SimpleHelpPane2` constructor and avoid exposing those raw helper names.
- Current-session IDA MCP was unavailable, so this report could not independently re-decompile the function. Existing by-* docs contain multiple prior live-IDA passes that agree on the target boundary and behavior.

No open question remains for owner/emitter route, singleton/global behavior, allocation size, anchor rectangle ownership, timer dependency, direct caller role, raw helper separation, or active reconstruction-gate eligibility.

## Recommended Exact Target Changes

Header changes:

```diff
- *** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
+ *** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
  *** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep these lines unchanged:

```text
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the stale confidence/status wording:

```markdown
- Confidence: strong for boundary, singleton replacement behavior, caller, callees, vtable stores, anchor/timer state, HelpPanes ownership, and file-local factory source shape. Exact historical helper spelling, return type, `+0xf4` field name, and style typedef remain descriptive-source questions, not code-entry blockers.
```

Replace the stale reconstruction-note bullet:

```markdown
- `AUTOGEN_PARENT_UID` is [UID:0000JU][HelpPanes](by-file/HelpPanes.md), whose confidence meets the attachment gate. This page now clears the active source-entry gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:0000JU`, valid generated source route to `NexusTK/ui/controls/HelpPanes.cpp`, and `(88 + 90) / 2 = 89 > 85`. The old below-95/no-code rule is obsolete; `95+` is reserved for rare final-audit quality.
```

Add or replace source-quality wording with:

```markdown
## Source-Quality Notes

This is an ordinary file-local HelpPanes factory/helper for `SimpleHelpPane2`, not compiler-only glue and not MiniMap-owned code. The source-facing body should delete the prior `g_pSimpleHelpPane2` unless byte `+0xf4` on the old object blocks replacement, then allocate/construct a new `SimpleHelpPane2` from wide tooltip text, owner pane, `x/y` anchor point, optional `RectBounds`, timeout milliseconds, horizontal/vertical alignment/style values, and style state.

The factory's manual base-constructor call, vtable stores, singleton write, anchor copy/clear, rectangle translation, and timer scheduling are the optimized/inlined construction sequence for `new SimpleHelpPane2(...)`. Do not write raw vtable stores in final source unless later class-source work proves the original used manual placement construction.
```

Enter the C++ candidate from the previous section between the target page's `RECONSTRUCTION_CPP CODE:BEGIN` and `END` lines.

Add a change-log entry:

```markdown
- 2026-06-19 B009 source-quality review:
  - Before: `84/90`, source behavior and HelpPanes owner were well documented, but C++ remained blank under stale final-name/source-visibility wording.
  - Changed to: recommended `88/90`, same owner/emitter route through [UID:0000JU][HelpPanes](by-file/HelpPanes.md), and first-draft file-local `CreateSimpleHelpPane2` C++ readiness under the active combined-score/emitter gate.
  - Evidence: current target, HelpPanes file, HelpPane/SimpleHelpPane2 class docs, preceding SimpleHelpPane2 method cluster, adjacent raw helper cluster, singleton global docs, timer wrapper docs, and MiniMap caller docs confirm exact range `0x004c7680-0x004c77e0`, `g_pSimpleHelpPane2` replacement behavior, `0x234` allocation, inlined HelpPane/SimpleHelpPane2 construction, optional anchor rectangle at `+0x224`, timer scheduling, raw wrapper separation, and HelpPanes ownership.
```

## Recommended Support-Doc Changes

If a later implementation callback allows support-doc cleanup, update [UID:00022O][SimpleHelpPane2FactoryHelpers](../../../../../by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) source sketch.

Replace `const char* text` with `const wchar_t *text` in both wrapper sketches. The MiniMap caller uses wide text and the HelpPane family is wide-text UI code.

Replace the generic tail arguments:

```cpp
int styleA,
int styleB,
int styleC
```

With:

```cpp
int horizontalAlign,
int verticalAlign,
const HelpPaneStyle *style
```

Or the final coordinated style type if that type has been settled by then.

Recommended helper wrapper source shape:

```cpp
static SimpleHelpPane2 *CreateSimpleHelpPane2Forward(
    const wchar_t *text,
    Pane *owner,
    int x,
    int y,
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
```

Do not edit that support doc during the report-only phase.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this B-agent report. If the supervisor later authorizes implementation, replace the current `00016T` row with:

```markdown
    - [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) 0x004c7680-0x004c77e0 | function | SimpleHelpPane2Factory : reconstructable : 88% : strong : Source-ready file-local HelpPanes factory, best named `CreateSimpleHelpPane2`/`ShowSimpleHelpPane2`; clears the active source-entry gate with `RECONSTRUCTABLE:TRUE`, emitter `0000JU`, and `88/90`; replaces or preserves `g_pSimpleHelpPane2`, closes the old pane unless byte `+0xf4` blocks replacement, allocates `0x234` and constructs a `SimpleHelpPane2` through `HelpPane`, installs vtables, copies/translates or clears anchor rect at `+0x224`, schedules the auto-hide timer through `0x005975e0`, is reached by MiniMapDialog plus raw wrappers, and emits through `HelpPanes.cpp`.
```

## Validator Needs

No validator was run because this assignment is report-only and no by-* or generated files were changed.

If implementation is authorized later:

> Executable block R001 was removed from this report and preserved verbatim in [00016T-SimpleHelpPane2Factory-source-quality-removed.md](00016T-SimpleHelpPane2Factory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected validator/autogen effect after implementation:

- `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` should contain the `00016T` factory body instead of the empty emitter marker for that UID.
- `auto-generated/-ag-memory-coverage.md` should still show `00016T` emitting through owner/emitter `0000JU` to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`.
- `project-level/-auto-completion-stats.md` should report `00016T | 88 | 90 | 89.0`.

## Changed Files

Only this report file was added:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/00016T-SimpleHelpPane2Factory-source-quality.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00016T-SimpleHelpPane2Factory-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"00016T"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016T-SimpleHelpPane2Factory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00016T-SimpleHelpPane2Factory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
