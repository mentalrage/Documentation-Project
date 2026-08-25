** TARGET-REPORT-UID:00011K **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00011K TargetOptionEditControlPane Source-Quality Research

Assignment: `B002-goal2-target-option-edit-control-pane-source-quality-00011K-20260616`

Primary target: [UID:00011K] `by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md`

## Final Recommendation

Raise [UID:00011K] from `82/88` to `86/90`.

Also raise the direct class parent [UID:0000EF] `by-class/TargetOptionEditControlPane.md` from `84/88` to `86/90`, because the target's source-quality evidence now clears the strict parent route and the class page should not remain the limiting score.

Optionally raise the paired dialog method page [UID:0001E2] `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md` from `82/88` to `86/90` after refreshing the config-field language. That page is not the primary target, but the same live evidence proves the dialog-side construction and save flow more precisely than its current prose.

Keep final C++ blank for all three pages. The numeric score/emitter route can clear the current minimum code-entry eligibility check after the recommended score change, but the final source spellings for inherited virtual slots, event structures, draw/helper APIs, and original field names remain below final-audit quality. The existing `95/95` prose is stale and should be replaced with a source-quality blocker note rather than a numeric-only explanation.

## Materials Reviewed

- Required supervisor and agent instructions:
  - `tools/leaser/Agents/Supervisor.md`
  - `tools/leaser/Agents/Supervisor_notes.md`
  - `tools/leaser/Agents/SupervisorAssignments.md`
  - `tools/leaser/Agents/Agent-B002/goal.md`
  - `tools/leaser/Agents/Agent-B002/notes.md`
- Primary/support docs:
  - `by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md`
  - `by-class/TargetOptionEditControlPane.md`
  - `by-file/TargetOptionDialog.md`
  - `by-class/TargetOptionDialog.md`
  - `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md`
  - `by-memory/0x00542a60-0x00542ab5.TargetOptionDialogScalarDeletingDestructor.md`
  - `by-memory/0x006211c8-0x00621264.TargetOptionDialogVtableData.md`
  - `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md`
  - `by-memory/0x00617a38-0x00618858.ControlPaneReadOnlyData.md`
  - `by-class/ControlPane.md`
  - `by-file/ControlPane.md`
  - `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`
  - `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
  - `by-class/Config.md`
  - `by-file/Config.md`
  - `by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md`
  - `by-memory/-coverage-report.md`
  - `project-level/-auto-completion-stats.md`
  - `auto-generated/by-memory-tool-report.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`
- Project/source placement docs:
  - `by-structure.md`
  - `inference_research.md`
  - `by-project-structure/proposed-source-tree.md`

## Live Evidence Checked

Live IDA MCP was available through the existing NexusTK database session `b002_00011G_scrollable_control_20260616`. I used `lookup_funcs`, `decompile`, `disasm`, `insn_query`, `get_bytes`, `get_int`, `get_string`, `xrefs_to`, and `analyze_component` style checks from that session. Hex-Rays and auto-analysis were ready.

IDA function inventory confirms:

| Address | Size | Role |
| --- | ---: | --- |
| `0x004993b0` | `0x52` | `TargetOptionEditControlPane` constructor |
| `0x00499410` | `0x1f` | non-deleting destructor helper |
| `0x00499430` | `0x224` | paint/draw method |
| `0x00499660` | `0x5` | fixed false-return virtual slot |
| `0x00499670` | `0xfd` | mouse-event handler |
| `0x00499770` | `0x9d` | two-button hit-test helper |
| `0x0049b045`, `0x0049b050` | `0xb` each | adjustor thunks into scalar deleting destructor |
| `0x0049b740` | `0x55` | scalar deleting destructor wrapper |
| `0x004b9640` | `0x18` | shared font-id/font-mode setter |
| `0x00542270` | `0x21e` | `TargetOptionDialog` constructor |
| `0x00542490` | `0x1f` | `TargetOptionDialog` non-deleting destructor helper |
| `0x005424b0` | `0x84` | `TargetOptionDialog` confirm/apply handler |
| `0x00542540` | no IDA function | raw save helper body, 32 instructions by `insn_query` |

Key xref and vtable checks:

- `0x004993b0` has one ordinary code caller at `0x005423dc` inside `TargetOptionDialog::TargetOptionDialog`.
- `0x00499430`, `0x00499670`, `0x00499660`, and `0x00499770` are vtable-only through cells `0x00618330`, `0x00618358`, `0x0061835c`, and `0x0061834c`.
- `0x00499410` has no direct xrefs. Its body still restores the three `TargetOptionEditControlPane` vtable views and tail-calls the shared pane teardown, so it is class-owned destructor support.
- `0x0049b740` is referenced by the primary vtable and by adjustor thunks `0x0049b045` and `0x0049b050`.
- Constructor, non-deleting destructor, and scalar deleting destructor all write the three `TargetOptionEditControlPane` vtable bases.
- `0x004b9640` has broad caller fan-in, including the target paint method and eight other UI/control call sites. It is not a `TargetOptionEditControlPane`-local source method.

Raw byte/string checks:

- `0x00618818`: UTF-16LE `ARROW`.
- `0x00618824`: UTF-16LE `SHIFT+ARROW`.
- `0x0061883c`: UTF-16LE `USER`.
- `0x00618848`: UTF-16LE `MONSTER`.
- `0x006105f4`: UTF-16LE `ON` style/resource key used for the selected/unselected button style lookups.
- `0x0060ddf8`: raw bytes begin with UTF-16LE `BUTT...`; the paint helper passes this pointer to the button-art draw helper. The exact original resource spelling is still safest as a descriptive `button art/resource key` unless the full neighboring literal owner is refreshed.

Verified decimal/hex offset conversions:

- `0x2911dc` = `2691548`
- `0x2911de` = `2691550`
- `0x108` = `264`
- `0x10c` = `268`
- `0x10d` = `269`
- `0x1fc` = `508`
- `0x110` = `272`
- `0xa0` = `160`
- `0xa4` = `164`

## Heuristic / Inference Reanalysis And Validation

### Method And Signature Names

Best defensible source-facing names:

| Address | Recommended source-facing role | Evidence | Rejected alternatives |
| --- | --- | --- | --- |
| `0x004993b0` | `TargetOptionEditControlPane::TargetOptionEditControlPane(int optionMode, uint8_t userTargetEnabled, uint8_t monsterTargetEnabled, const Rect *bounds)` | Calls `ControlPane` constructor with kind `8`, stores `optionMode` at `+0x108`, two bytes at `+0x10c/+0x10d`, and receives bounds from the dialog constructor. | Do not model the two bytes as inherited `SelectionControlPane` fields; they are byte flags in this class, not a 4-byte selected-value field. |
| `0x00499410` | non-deleting destructor helper for `TargetOptionEditControlPane` | Restores all three class vtable views and tail-calls shared pane teardown. | Not an independent source function and not a shared base destructor. |
| `0x00499430` | `TargetOptionEditControlPane::OnPaint` or `DrawTargetOptions` | Vtable-only paint slot, draws labels and button art from object state. | Do not name it only from IDA's generic `sub_` or from the resource labels; it is the control paint method. |
| `0x00499660` | false-return virtual hook for an unused secondary event/slot | Five bytes, returns `0` through `retn 4`, vtable-only at `0x0061835c`. | Not an adjustor thunk, destructor, or delete helper. Exact inherited slot name remains unproven. |
| `0x00499670` | `TargetOptionEditControlPane::OnMouseEvent(const MouseEvent *event)` | Checks event byte `+4 == 1`, consumes coordinates at `+8/+12`, toggles selection bytes, invalidates view. | Exact original event type and enum name are not proven; do not hard-code a final API spelling. |
| `0x00499770` | `HitTestTargetOptionButton(int x, int y)` | Tests the same local rectangles and returns `0`, `1`, or `-1`; no object state is read. | It should not be merged into the mouse handler; the vtable has a distinct slot. |
| `0x0049b740` | compiler-emitted scalar deleting destructor wrapper for the class destructor | Primary vtable points here; adjustor thunks jump here; body does normal teardown and conditional delete. | Do not hand-port this as a normal source-authored method body. Source should declare/destruct the class and let compiler ABI emit wrappers/thunks. |

Impact: these names are strong enough for `86/90`, but the inherited virtual slot spellings and final event/draw helper types are not final-source quality. This blocks final C++.

### Field Layout And Types

Best defensible field names/types:

| Offset | Type | Recommended descriptive name | Meaning |
| --- | --- | --- | --- |
| `+0x108` | `int` or 32-bit enum-like value | `m_targetOptionMode` | `0` selects the `ARROW` row; nonzero selects the `SHIFT+ARROW` row. The dialog constructor passes `0` then `1`. |
| `+0x10c` | `uint8_t` / serialized bool byte | `m_userTargetEnabled` | Toggled by the first rectangle; saved to the row's first config byte. |
| `+0x10d` | `uint8_t` / serialized bool byte | `m_monsterTargetEnabled` | Toggled by the second rectangle; saved to the row's second config byte. |

Rejected alternative: `SelectionControlPaneSelectedValue_0x10c` is only an offset coincidence. That support page documents a 4-byte selected value for another class. Here the constructor writes bytes, the mouse handler toggles bytes, and the dialog save helper reads bytes.

Impact: this clears the main field/type blocker for the target and direct class page. It should cap below final C++ because original source field names are descriptive rather than recovered.

### Config Offsets And Semantic Names

Best defensible config model:

| Config offset | Decimal | Dialog row | Byte 0 | Byte 1 |
| --- | ---: | --- | --- | --- |
| `g_pConfig + 0x2911dc` | `2691548` | row 0, `ARROW` | user target enabled | monster target enabled |
| `g_pConfig + 0x2911de` | `2691550` | row 1, `SHIFT+ARROW` | user target enabled | monster target enabled |

Recommended descriptive names if the project wants scalar fields:

- `targetOptionArrowUserEnabled`
- `targetOptionArrowMonsterEnabled`
- `targetOptionShiftArrowUserEnabled`
- `targetOptionShiftArrowMonsterEnabled`

Recommended grouped shape if the project prefers structure:

```cpp
struct TargetOptionConfigRow {
    uint8_t userEnabled;
    uint8_t monsterEnabled;
};
TargetOptionConfigRow targetOptions[2]; // row 0 ARROW, row 1 SHIFT+ARROW
```

Evidence: `TargetOptionDialog` constructor loops over config offsets `0x2911dc` and `0x2911de`, constructs two edit controls with modes `0` and `1`, and seeds each control from `[offset]` and `[offset+1]`. The confirm path and raw save helper read controls 2 and 3 and write `+0x10c/+0x10d` back to the same config offsets.

Rejected alternative: the current broad phrase `Target-option dialog bytes` is true but too vague for source quality. A single flat `uint32_t` is not supported because the code treats four independent bytes.

Impact: supports raising target and dialog memory page; final C++ still blocked until the original Config member spelling and declaration style are settled.

### Paint Resources, Styles, And Rectangles

Paint behavior is now source-describable:

- Loads `ON` style/resource entries `0` and `1` and uses them as unselected/selected button visual states.
- Draws the row caption as `ARROW` for mode `0`, otherwise `SHIFT+ARROW`.
- Draws column labels `USER` and `MONSTER`.
- Uses two local target-button rectangles relative to the control origin:
  - user: `(left=110, top=0, right=130, bottom=20)`
  - monster: `(left=200, top=0, right=220, bottom=20)`
- Passes a `BUTT...` resource/string pointer to the button-art draw helper; final literal spelling should remain descriptive until the shared resource-literal owner is refreshed.

Rejected alternatives:

- Do not trust IDA's one-character string labels for these UTF-16 strings. Raw bytes prove the full labels.
- Do not call the rectangles generic layout padding. They are reused by paint, mouse handling, and hit test, so they are semantic hit/draw boxes.

Impact: enough for `86/90`; final render helper type names and exact resource identifier spelling are still not final C++ quality.

### Mouse Event Kind And Hit Test

Best defensible interpretation:

- The mouse handler only handles event kind byte `1`.
- The best descriptive name is `click` or `button-down`, but the original enum name is not proven.
- Coordinates are read from event offsets `+8` and `+12`.
- Hit `0` toggles `m_userTargetEnabled`; hit `1` toggles `m_monsterTargetEnabled`.
- The hit-test helper returns `0` for user, `1` for monster, and `-1` outside both rectangles.
- The mouse handler calls the inherited invalidation path after processing the event path.

Rejected alternatives:

- Do not call event kind `1` definitively `MouseUp` or `MouseDown` without shared event enum evidence.
- Do not collapse the hit-test helper into paint or mouse source. It has an independent vtable slot and source role.

Impact: source behavior is strong enough for the score raise, but final C++ should avoid exact enum/API spelling.

### Fixed-Return Hook

`0x00499660` is a vtable-only function that returns `0` and pops one argument. It does not read `this`, so the compiler could emit it as a tiny static/stdcall-like body for a virtual slot whose implementation is source-authored as "false/no handling." It is not ABI glue like an adjustor thunk, because the vtable cell points directly to it and the body is semantic false-return behavior.

Rejected alternatives:

- Not a destructor or scalar deleting destructor.
- Not a thunk into another function.
- Not class-local unreachable padding, because the vtable references it.

Impact: the fixed false-return body should stay in the target documentation, but the inherited slot name remains a final C++ blocker.

### Destructor And Thunk Ownership

Ownership split:

- `0x00499410` belongs to `TargetOptionEditControlPane` as non-deleting destructor support despite no direct xrefs in IDA metadata.
- `0x0049b740` is the class scalar deleting destructor wrapper. It is source-declared/generated-binary ABI output and should be documented with the class, not hand-authored as ordinary C++.
- `0x0049b045` and `0x0049b050` are compiler-generated adjustor thunks. They should remain in the destructor/thunk support aggregate and be cross-referenced from this target.

Rejected alternatives:

- Do not move the scalar deleting destructor to the broad `ButtonChoiceControlDestructors` aggregate as its only owner; that aggregate is an index, while this class is the direct source owner.
- Do not emit adjustor thunk bodies in final C++.

Impact: ownership is strong and supports `86/90`.

### Shared Font Setter Ownership

`0x004b9640` writes a font id/font mode field only when the argument is `0` or `1`. It is called by the target paint method and at least eight other UI/control methods. It should be treated as a shared control/text helper, not as a member uniquely owned by `TargetOptionEditControlPane`.

Best descriptive names:

- `SetControlFontModeIfValid`
- `SetFontIdIfValid`

Rejected alternative: keeping it as a class-local method on `TargetOptionEditControlPane` overstates ownership and would pollute final source placement.

Impact: support docs should say "paint calls shared font setter" rather than listing it as a class-local source method. This reduces final C++ risk but does not block the target score raise.

### Caller, Vtable, And Source Placement

Best source placement remains:

```text
NexusTK/ui/dialogs/TargetOptionDialog.cpp
```

Ownership route:

1. [UID:00011K] target memory page
2. [UID:0000EF] `TargetOptionEditControlPane`
3. [UID:0000OG] `TargetOptionDialog` file root
4. `auto-generated/NexusTK/ui/dialogs/TargetOptionDialog.cpp`

Evidence:

- The edit control constructor is only called by `TargetOptionDialog::TargetOptionDialog` at `0x005423dc`.
- The dialog constructor creates two edit controls, modes `0` and `1`, with bounds matching the two visual rows.
- The dialog confirm/save path reads the same control bytes and writes the same config fields.
- The `by-file/TargetOptionDialog.md` page already places this dialog family in `ui/dialogs/TargetOptionDialog.cpp`.
- `OptionPane` and `ControlPane` are only neighboring/base-control contexts for this target, not better source owners.

Rejected alternatives:

- `OptionPane.cpp`: no direct constructor caller or save-path owner; only neighboring option UI vocabulary.
- `ControlPane.cpp`: owns inherited construction/paint helpers but not this row control behavior.
- No owner/non-emitting: contradicted by constructor caller, vtables, source file page, and dialog save flow.

Impact: source placement is strong and supports raising both target and class parent.

### Final C++ Eligibility

After raising [UID:00011K] and [UID:0000EF] to `86/90`, the pages have a nonblank emitter route and clear the minimum numeric average. I still do not recommend entering final C++ in this pass.

Remaining final-source blockers:

- original inherited virtual slot names for the fixed-return hook and hit-test slot;
- exact mouse event type and event-kind enum spelling;
- final shared draw/font helper type names;
- final `Rect`/style/resource wrapper type names;
- original Config field declaration style and names;
- no exact `TargetOptionEditControlPane` vtable-data child page split from the broader `ControlPaneReadOnlyData` aggregate.

Score impact: these blockers should cap the target around `86/90`, not keep it below `85/85`. The unresolved issues are final-code polish and exact source spelling, not ownership, behavior, field layout, or source-placement blockers.

## Recommended Metadata

Primary target:

```text
*** UID:00011K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Direct class parent:

```text
*** UID:0000EF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Optional paired dialog method page:

```text
*** UID:0001E2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000EE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No metadata change is required for [UID:0000OG] `by-file/TargetOptionDialog.md` or [UID:0000EE] `by-class/TargetOptionDialog.md`.

## Exact Support-Doc Text

Suggested replacement/addition for [UID:00011K] `by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md`:

```markdown
## Source-Quality Reanalysis

- Source placement: `TargetOptionEditControlPane` is the two-row target option edit control owned by [UID:0000EF][TargetOptionEditControlPane](by-class/TargetOptionEditControlPane.md) and emitted through [UID:0000OG][TargetOptionDialog](by-file/TargetOptionDialog.md). The constructor's only ordinary code caller is `TargetOptionDialog::TargetOptionDialog` at `0x005423dc`; the paint, mouse, fixed-return, and hit-test bodies are reached through the TargetOption vtables.
- Field layout: `+0x108` is a 32-bit option-mode value (`0 = ARROW`, `1 = SHIFT+ARROW` as supplied by the dialog constructor), `+0x10c` is the user-target enabled byte, and `+0x10d` is the monster-target enabled byte. These are not `SelectionControlPane` selected-value fields; the target control reads/writes bytes.
- Config mapping: dialog row 0 loads/saves `g_pConfig + 0x2911dc` as ARROW user/monster bytes; row 1 loads/saves `g_pConfig + 0x2911de` as SHIFT+ARROW user/monster bytes.
- Paint resources: raw UTF-16 bytes verify `ARROW`, `SHIFT+ARROW`, `USER`, `MONSTER`, and the `ON` style key. The button-art helper receives a `BUTT...` resource/string pointer; keep the exact resource label descriptive until the shared resource owner is refreshed.
- Rectangles: the first option button uses local rectangle `(110,0)-(130,20)` and maps to user target; the second uses `(200,0)-(220,20)` and maps to monster target. Paint, mouse handling, and hit testing all use the same two boxes.
- Mouse behavior: event kind byte `1` is the handled click/button event. Coordinates at event offsets `+8/+12` are hit-tested; hit `0` toggles the user byte, hit `1` toggles the monster byte, and misses return false.
- Compiler/ABI support: `0x00499410` is the class non-deleting destructor helper; `0x0049b740` is the scalar deleting destructor wrapper; `0x0049b045` and `0x0049b050` are adjustor thunks. Do not hand-port the scalar wrapper or adjustor thunk bodies as normal source.
- Shared helper exclusion: `0x004b9640` is a shared UI font-id/font-mode setter with broad caller fan-in. `TargetOptionEditControlPane::OnPaint` calls it, but this target should not claim it as a class-local method.
- Final C++ remains blank because inherited virtual slot names, event/draw helper types, resource wrapper names, and original Config field names are still below final-source quality even though ownership, behavior, and source placement are strong.
```

Suggested replacement/addition for [UID:0000EF] `by-class/TargetOptionEditControlPane.md`:

```markdown
## Source-Quality Reanalysis

`TargetOptionEditControlPane` is a row control in `TargetOptionDialog.cpp`. The dialog constructs two instances: mode `0` for `ARROW` and mode `1` for `SHIFT+ARROW`. Each instance stores `m_targetOptionMode` at `+0x108`, `m_userTargetEnabled` at byte `+0x10c`, and `m_monsterTargetEnabled` at byte `+0x10d`.

The class owns the constructor, non-deleting destructor helper, paint method, mouse-event handler, two-button hit-test helper, and scalar deleting destructor ABI wrapper. The fixed false-return body at `0x00499660` is a real vtable slot implementation, but the inherited slot name is not recovered. The adjustor thunks at `0x0049b045` and `0x0049b050` are compiler-generated ABI support and should not be emitted as handwritten source.

Paint uses verified UTF-16 labels `ARROW`, `SHIFT+ARROW`, `USER`, and `MONSTER`, style key `ON`, and two local rectangles `(110,0)-(130,20)` and `(200,0)-(220,20)`. Mouse handling accepts only event kind byte `1`, tests those same rectangles, toggles the matching byte, and invalidates the inherited control view.

Final C++ remains blank because exact inherited virtual names, event/helper types, resource wrapper names, and original field names remain provisional.
```

Suggested replacement/addition for [UID:0001E2] `by-memory/0x00542270-0x0054259f.TargetOptionDialog.md` if applying the optional score raise:

```markdown
## Target Option Config Mapping

The constructor builds two `TargetOptionEditControlPane` children. Row 0 passes mode `0` and seeds user/monster bytes from `g_pConfig + 0x2911dc` and `g_pConfig + 0x2911dd`; row 1 passes mode `1` and seeds user/monster bytes from `g_pConfig + 0x2911de` and `g_pConfig + 0x2911df`. The row labels drawn by the child control are `ARROW` and `SHIFT+ARROW`.

The confirm path and raw helper at `0x00542540` read child controls 2 and 3 from the dialog child-list storage at `this + 0x1fc`, then copy each child's byte fields `+0x10c` and `+0x10d` back to the same config row. The raw helper is source behavior for `TargetOptionDialog`, not part of the following destructor/thunk island.

Final C++ remains blank because exact source names for the confirm/save helper and inherited dialog APIs remain below final-source quality.
```

Suggested replacement for the relevant `g_pConfig` known-field prose in [UID:00028Q] `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`:

```markdown
| `+0x2911dc..+0x2911df` | Target-option config rows. Row 0 at `+0x2911dc` stores ARROW user/monster enabled bytes; row 1 at `+0x2911de` stores SHIFT+ARROW user/monster enabled bytes. Names are descriptive/inferred from `TargetOptionDialog` and `TargetOptionEditControlPane`; exact original Config member spelling is not recovered. |
```

Suggested text refresh for [UID:0000OG] `by-file/TargetOptionDialog.md`:

```markdown
`TargetOptionDialog.cpp` owns both `TargetOptionDialog` and the nested `TargetOptionEditControlPane` row control. The dialog creates two edit-control rows from `g_pConfig + 0x2911dc..+0x2911df`: row 0 is `ARROW` user/monster target bytes and row 1 is `SHIFT+ARROW` user/monster target bytes. Confirm/save copies child-control bytes `+0x10c/+0x10d` back to those config rows. `OptionPane` and `ControlPane` are support contexts only; they are not better source owners for this dialog-specific row control.
```

## Supervisor-Owned Coverage Row Replacement

Replace the [UID:00011K] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:00011K][0x004993b0-0x0049980c.TargetOptionEditControlPane](by-memory/0x004993b0-0x0049980c.TargetOptionEditControlPane.md) : reconstructable : 86% : strong : TargetOptionEditControlPane row-control methods with IDA-confirmed constructor/dialog caller, vtable-only paint/mouse/fixed-return/hit-test slots, source-facing field names at +0x108/+0x10c/+0x10d, ARROW/SHIFT+ARROW USER/MONSTER label bytes, ON/BUTT button-art draw state, two local option rectangles, click-kind toggle flow, class-owned destructor wrapper/adjustor evidence, shared font-setter exclusion, and TargetOptionDialog.cpp source placement documented.
```

If applying the optional [UID:0001E2] raise, replace its row with:

```text
    - [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md) : reconstructable : 86% : strong : TargetOptionDialog constructor/confirm/helper cluster with IDA-confirmed DLGSETUP setup, two TargetOptionEditControlPane rows seeded from g_pConfig +0x2911dc/+0x2911de, child-list save flow through controls 2 and 3, selected user/monster byte writes, TargetOptionDialog vtables/destructor support, and TargetOptionDialog.cpp source placement documented.
```

## Score And Source-Placement Impact

- [UID:00011K] can safely move above `85/85`: behavior, field layout, config mapping, caller, vtable reachability, destructor ABI support, and source placement are all proven enough for `86/90`.
- [UID:0000EF] should also move above `85/85` so the direct class parent is not stale relative to the target.
- [UID:0001E2] can optionally move above `85/85`; the constructor and save flow are now strongly tied to exact config rows and child fields.
- [UID:0000OG] remains the correct file root. No split to `OptionPane.cpp`, `ControlPane.cpp`, generated helper files, or no-owner state is justified.
- Final C++ remains blocked by exact source spelling and inherited API names, not by ownership or behavior.

## Validation Commands

After the supervisor applies the recommended documentation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00011K-target-option-edit-control-pane-source-quality-removed.md](00011K-target-option-edit-control-pane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Files Changed By This Report

Only this report file was created:

- `tools/leaser/Agents/Agent-B002/research/00011K-target-option-edit-control-pane-source-quality.md`

No by-memory docs, by-class docs, by-file docs, generated reports, IDA databases, source files, or supervisor-owned coverage files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00011K-target-option-edit-control-pane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00011K"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00011K-target-option-edit-control-pane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00011K-target-option-edit-control-pane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00011K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
