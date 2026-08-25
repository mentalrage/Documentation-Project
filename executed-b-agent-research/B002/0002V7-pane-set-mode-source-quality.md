** TARGET-REPORT-UID:0002V7 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002V7 PaneSetMode Source-Quality Research

Assignment: `B002-goal2-pane-set-mode-source-quality-0002V7-20260617`

Primary target: [UID:0002V7] `by-memory/0x005446b0-0x005446d4.PaneSetMode.md`

Mode: report-only. I did not edit by-memory docs, by-class docs, by-file docs, generated reports, generated source, the IDA database, or `by-memory/-coverage-report.md`.

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0002V7] from `82/88` to `88/92`.
- Final disposition: keep `RECONSTRUCTABLE:TRUE`; change `CANONICAL_OWNER` and `EMITTER_UIDS` from [UID:0000MC] `Pane` by-file to [UID:0000A2] `Pane` by-class. The generated source route still resolves to [UID:0000MC] `NexusTK/ui/core/Pane.cpp`.
- Required action: update the target page with the resolved `InvalidateRect` virtual-slot evidence and populate the formal `RECONSTRUCTION_CPP CODE` block with the first-draft C++ in this report.
- Confidence: high for exact range, source signature direction, behavior, owner/emitter route, and first-draft C++; medium for original enum constant names.

## Target

- Target UID: [UID:0002V7]
- Target path: `by-memory/0x005446b0-0x005446d4.PaneSetMode.md`
- Current score/metadata: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000MC`, `EMITTER_UIDS:0000MC`.
- Current generated route: `auto-generated/NexusTK/ui/core/Pane.cpp`; the file currently exists but is zero bytes.
- Supporting parents: [UID:0000A2] `Pane` class is `88/86`; [UID:0000MC] `Pane` by-file is `88/86`; [UID:0001EA] `PaneCore` already routes through [UID:0000A2].

## Executive Recommendation

Treat `0x005446b0-0x005446d4` as a source-authored `Pane` class method:

```cpp
void Pane::SetMode(unsigned char mode)
```

The source body should compare the current mode byte at `Pane +0xb5`, update it only when changed, and invalidate the pane's local bounds through `Pane::InvalidateRect` using the rectangle at `Pane +0x44`.

The current `PaneSetMode` name is the best source-facing name. `SetVisible`, `SetEnabled`, and `SetStyle` are weaker because visibility is a separate byte at `+0xb4`, mode values participate in draw/opacity/static-text behavior, and callers use more than a binary enabled state.

The previous unresolved vtable-slot blocker can be closed. The `Pane` primary vtable at `0x006219e8` has slot `+0x20` at `0x00621a08`, and that dword is `0x00544800`, the documented `Pane::InvalidateRect` implementation. `PaneSetMode` tail-jumps through that slot with `this +0x44`, so the side effect is bounds invalidation/redraw scheduling after a mode change.

## IDA MCP Facts

Current live IDA session:

- Session: `b003_00018a_ime_comp_20260617`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Imagebase: `0x400000`
- Auto-analysis and Hex-Rays: ready.

Function/range facts:

- `lookup_funcs 0x005446b0` reports `sub_5446B0`, size `0x24`, exact half-open range `0x005446b0-0x005446d4`.
- Bytes at `0x005446b0` are:

```text
55 8b ec 8a 45 08 38 81 b5 00 00 00 74 12 8b 11
88 81 b5 00 00 00 8d 41 44 89 45 08 5d ff 62 20
5d c2 04 00 cc cc cc cc ...
```

- `0x005446d4-0x005446e0` is `0xcc` padding before `Pane::GetCurrentMotionRegion` at `0x005446e0`.
- The no-change path is `pop ebp; retn 4`.
- The changed path writes `this+0xb5`, replaces the stack argument with `this+0x44`, restores `ebp`, and tail-jumps to `[vtable+0x20]`.

Decompilation:

```c
char __thiscall sub_5446B0(_BYTE *this, char a2)
{
  char result = a2;
  if ( this[181] != a2 )
  {
    int vtable = *(_DWORD *)this;
    this[181] = a2;
    return (*(int (__stdcall **)(_BYTE *))(vtable + 32))(this + 68);
  }
  return result;
}
```

Return behavior:

- Binary no-change path leaves `AL` equal to the incoming mode and returns.
- Binary changed path tail-calls the virtual invalidation slot and therefore returns whatever `InvalidateRect` leaves in `EAX`.
- Source-facing return should be `void`. The observed "return" is incidental register state/tail-call behavior, and representative caller decompilations treat `PaneSetMode` as a statement.

Vtable slot facts:

- `get_int` over `0x006219e8` shows primary `Pane` slot `+0x20` at `0x00621a08` points to `0x00544800`.
- `lookup_funcs 0x00544800` reports `sub_544800`, size `0xac`.
- Decompilation/disassembly of `0x00544800` shows `Pane::InvalidateRect`: it builds/copies a rectangle, defaults null input to `this+0x44`, checks the pending dirty region, and unions the rect into `this+0xc4`.
- `xrefs_to 0x00544800` reports two code refs and `98` data refs, consistent with `InvalidateRect` being inherited in many pane-derived vtable slots.

Direct xrefs to `PaneSetMode`:

- `xrefs_to 0x005446b0` reports `100` direct code xrefs.
- Unique modeled caller families include chat UI, control-pane constructors, dialog/modeless input handlers, HelpPane constructors/raw helpers, login/dialog constructors, list panes, and multiple text/static control constructors.
- Raw/no-function caller addresses also include the HelpPane embedded text-state helper and HelpPane fade updater, matching their existing pages.

## Caller And Mode-Constant Reanalysis

An IDA byte sweep around all `100` direct xrefs found immediate call-site modes:

| Mode | Immediate xref count in sweep | Best role direction |
| --- | ---: | --- |
| `0` | `5` | temporary/suppressed counterpart used by dialog/modeless drag when saved mode is `2` |
| `1` | `56` | normal/default redraw-enabled pane mode |
| `2` | `1` | active/highlighted overlay mode; confirmed in `ChattingBackPaneUpdateVisibility` |
| `3` | `12` | alpha/fade/styled mode; confirmed in HelpPane opacity/fade paths |
| `4` | `4` | static/no-show-invalidate wrapper mode; `Pane::Show` suppresses redraw when mode is `4` |
| variable/saved | `22` | saved mode restore or constructor-provided mode argument |

The exact count is a call-site byte heuristic, not a semantic proof for every xref, but it confirms the mode field is not just visible/hidden or enabled/disabled. The safest documentation direction is `PaneMode` / `PaneDrawMode` byte with descriptive constants, while first-draft C++ should use `unsigned char` until enum names are agreed across Pane/Dialog/Control pages.

Representative caller evidence:

- [UID:0002F3] `ChattingBackPaneUpdateVisibility` calls `SetMode(2)` when the chat background is active and `SetMode(1)` otherwise, then updates draw color and refreshes `this+0x44`.
- [UID:00016R] `HelpPaneCore` raw embedded text helper calls `SetMode(1)` when opacity is not greater than zero and `SetMode(3)` when `0.0f < opacity <= 1.0f`.
- [UID:00022N] `HelpPaneFadeStateUpdate` repeats the same `1`/`3` mode transition for the base help pane and embedded child pane.
- `ModelessDialogPane::HandleMouseEvent` and the dialog handler at `0x0049e240` save the current pane mode during drag; if the saved mode is `2` they temporarily set `0`, and if saved mode is `3` they temporarily set `1`, then restore the saved byte on release.
- `StaticTextControlPane` constructs an embedded text provider pane, sets the child to mode `1`, then sets the owner/wrapper to mode `4`.
- `Pane::Show` uses the same `+0xb5` field and skips its redraw path when the mode byte is `4`, confirming that mode `4` is a redraw/show behavior state, not visibility itself.

Rejected caller interpretations:

- `visible/hidden`: rejected because `Pane +0xb4` is the visibility byte, `Show`/`Hide` own visibility, and mode values `3`/`4` are used for opacity/static redraw behavior.
- `enabled/disabled`: rejected because callers use more than two immediate values and modeless drag maps `2 -> 0` and `3 -> 1` as paired drawing/input states.
- feature-local style value: rejected because `SetMode` has 100 direct xrefs across Pane-derived UI families and belongs to the base `Pane` class.

## Ownership And Source Placement

Ranked ownership analysis:

1. [UID:0000A2] `Pane` class: accepted.
   Evidence: method uses only base `Pane` fields `+0xb5` and `+0x44`, dispatches the base primary vtable slot, has broad pane-derived caller fan-in, and sibling exact items [UID:0001EA] `PaneCore` and [UID:0003CA] `PaneVtableData` already route through the class UID.

2. [UID:0000MC] `Pane` by-file: accepted as final source file/root, rejected as the narrow canonical owner.
   Evidence: `Pane.cpp` is the correct generated source file, but by-structure direct ownership favors the class for a class method. [UID:0000A2] already emits through [UID:0000MC], so moving the target to [UID:0000A2] preserves the same generated source route.

3. Caller feature classes such as HelpPane, ChattingBackPane, StaticTextControlPane, and ModelessDialogPane: rejected.
   Evidence: those pages only consume the base setter. Their modes supply semantic context for constants, but the method is not feature-specific.

Recommended metadata:

```text
COMPLETION: 88
CONFIDENCE: 92
CANONICAL_OWNER: 0000A2
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000A2
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: populate with the first-draft C++ below
```

## Heuristic / Inference Reanalysis And Validation

Issues checked:

- Exact method range and bytes: IDA `lookup_funcs`, `disasm`, and `get_bytes` confirm the method is exactly `0x005446b0-0x005446d4`, followed by `0xcc` padding until `0x005446e0`.
- Source signature: decompiler says `char`, but the two return paths are not semantically consistent. Caller decompilations ignore the value. Best source signature is `void Pane::SetMode(unsigned char mode)`.
- Vtable slot `+0x20`: previous docs left it unresolved. Vtable dword `0x00621a08` resolves it to `0x00544800`; decompilation of that target confirms `Pane::InvalidateRect`. This blocker is solved.
- Mode byte semantics: caller families prove a draw/update mode byte, not a visibility byte. `1` is normal/default, `3` is opacity/fade, `4` suppresses show invalidation/static wrapper redraw, `2` is active/highlighted overlay in ChattingBackPane, and `0` is a temporary/suppressed counterpart during dialog/modeless drag. Final original enum constant names remain inferred and should not block this method's C++ because the method body does not need the enum.
- Owner/emitter route: direct file owner [UID:0000MC] is less precise than class owner [UID:0000A2]. The route through [UID:0000A2] still surfaces to `NexusTK/ui/core/Pane.cpp`, matching [UID:0001EA] and [UID:0003CA].
- Generated-output pollution/omission: `auto-generated/NexusTK/ui/core/Pane.cpp` is zero bytes even though the route is valid. Populating this target's formal C++ is useful and in scope for the single method.

Rejected alternatives:

- Keep the virtual slot name unresolved: rejected by direct vtable dword evidence and `InvalidateRect` behavior at `0x00544800`.
- Keep `char` return in source C++: rejected because the changed path tail-calls a different function, the no-change return is incidental, and callers ignore the result.
- Rename to `SetVisible` or `SetEnabled`: rejected because separate visibility state exists and caller modes are multi-state draw/update modes.
- Leave owner/emitter on [UID:0000MC]: rejected as less precise under the direct-owner rule, though [UID:0000MC] remains the file route.
- Refuse formal C++ due unknown enum names: rejected because a stable `unsigned char` parameter exactly represents the binary method and does not require unstable enum names.

Validation/contradiction of current docs:

- Current target docs are correct on range, `+0xb5`, `+0x44`, broad caller family, and reconstructability.
- Current target docs are stale on the unresolved `+0x20` virtual-slot name. It should be updated to `Pane::InvalidateRect` / dirty-rect invalidation.
- Current target docs are stale on the final-C++ gate. Under Supervisor rule 20 and the resolved slot/source-shape evidence, the method is ready for formal C++ entry.
- Current metadata is stale on owner/emitter narrowness. It should align with [UID:0001EA] `PaneCore` and [UID:0003CA] `PaneVtableData` by routing through [UID:0000A2].

Remaining uncertainty:

- Original enum constant names are not proven. This should cap the target below final-audit scores, but it does not block C++ because the target method can use an `unsigned char` argument and the named field `m_mode`/`m_paneMode`.

Score/source-placement/final-C++ impact:

- Score can rise to `88/92`.
- Source placement remains `NexusTK/ui/core/Pane.cpp`, but canonical owner/emitter should become [UID:0000A2].
- Formal C++ should be populated for [UID:0002V7].

## First-Draft C++ Recommendation

Populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:0002V7] with this target-method-only body:

```cpp
void Pane::SetMode(unsigned char mode)
{
    if (m_mode == mode)
        return;

    m_mode = mode;
    InvalidateRect(&m_bounds);
}
```

Source-shape notes for the supervisor:

- `m_mode` is `Pane +0xb5`; if the class page prefers `m_paneMode`, use that field spelling consistently.
- `m_bounds` is the local/bounds rectangle at `Pane +0x44`.
- `InvalidateRect` is the primary virtual slot `+0x20`, base target `0x00544800`.
- Do not add enum definitions inside this by-memory block. Enum or constant definitions should live in the Pane class/type support docs if added later.

## Supervisor-Owned Coverage Row

Replace the existing [UID:0002V7] child row under [UID:0001EA] `PaneCore` in `by-memory/-coverage-report.md` with:

```text
        - [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) 0x005446b0-0x005446d4 | method | PaneSetMode : reconstructable : 88% : very strong : B002 2026-06-17 source-quality reanalysis confirms the exact 0x24-byte Pane::SetMode body, 0x005446d4-0x005446e0 padding, source-facing void Pane::SetMode(unsigned char) signature, +0xb5 Pane mode byte, +0x44 local bounds rectangle, primary vtable slot +0x20 resolved through 0x00621a08 -> 0x00544800 Pane::InvalidateRect, no meaningful return value consumed by callers, 100 direct UI caller xrefs with mode values 0/1/2/3/4 and saved-byte restore paths, Pane class owner/emitter route via [UID:0000A2] to Pane.cpp, zero-byte generated output caveat, and accepted first-draft C++ ready for formal population.
```

No coverage insert/delete is recommended.

## Support Docs To Update

- [UID:0002V7] target page: update score/metadata, owner/emitter, return-behavior discussion, resolved `+0x20` slot name, caller-mode table, generated-output caveat, and formal C++ block.
- [UID:0001EA] `PaneCore`: update the child row description to say `PaneSetMode` calls `Pane::InvalidateRect` through primary vslot `+0x20`; no score change required.
- [UID:0001VH] `PaneLayout`: update `+0xb5` evidence to mention resolved `InvalidateRect` dispatch and the descriptive `PaneMode` / `PaneDrawMode` direction.
- [UID:0003JA] `PaneVtables` and [UID:0003CA] `PaneVtableData`: name the primary vtable slot `+0x20` as `Pane::InvalidateRect`.
- [UID:0000A2] `Pane` class and [UID:0000MC] `Pane` file: update the method-family row/source placement to reflect class-level owner/emitter for [UID:0002V7] while preserving the same `Pane.cpp` root.
- Caller pages can optionally replace "callback/refresh slot +0x20" wording with "virtual `InvalidateRect`" when they refer specifically to a Pane-derived object.

## Validation Commands

After supervisor-owned edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002V7-pane-set-mode-source-quality-removed.md](0002V7-pane-set-mode-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files, Leases, Blockers

Changed file:

- `tools/leaser/Agents/Agent-B002/research/0002V7-pane-set-mode-source-quality.md`

Leases used: none. A lease is not required for writing inside the B002 research folder.

Blockers: none for supervisor review. The only residual uncertainty is final original enum constant names; it does not block the target method's formal C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002V7-pane-set-mode-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002V7"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002V7-pane-set-mode-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002V7-pane-set-mode-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002V7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
