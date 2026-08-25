** TARGET-REPORT-UID:0002GA **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002GA ChattingColorListPaneFindIndexByColorValue Source-Quality Research

Status: FINISHED
Agent: B014
Date: 2026-06-19
Assignment: report-only source-quality pass. No by-* documentation file and no `by-memory/-coverage-report.md` file were edited.

## Final Recommendation

Keep [UID:0002GA] as a source-authored `ChattingColorListPane` helper method owned and emitted by [UID:00001S] `ChattingColorListPane`, with current file route through [UID:0000I5] `Chatting` / `auto-generated/NexusTK/social/Chatting.cpp`.

Recommended source-facing signature:

```cpp
int ChattingColorListPane::FindIndexByColorValue(int colorValue)
```

Recommended metadata after implementation:

```text
COMPLETION:87
CONFIDENCE:92
CANONICAL_OWNER:00001S
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001S
```

Recommended disposition: first-draft C++ ready. The current target's blank-C++ explanation is stale because it relies on the old below-95/95 source-emission gate. Under current by-structure rules, the page is already eligible by average score and emitter route, and this pass resolves the remaining helper/type/source-shape questions enough for a source-quality first draft.

## Target And Current State

- Target UID: [UID:0002GA]
- Target path: `by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md`
- Required B014 report path: `tools/leaser/Agents/Agent-B014/research/0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality.md`
- Current score: `84/90`
- Current owner/emitter: [UID:00001S] `ChattingColorListPane`
- Current source file route: [UID:0000I5] `Chatting`, generated as `auto-generated/NexusTK/social/Chatting.cpp`
- Current generated state: `auto-generated/-ag-memory-coverage.md` reports `has cpp` as `no`, and `auto-generated/NexusTK/social/Chatting.cpp` contains an empty emitter marker for `0002GA`.
- Current by-memory coverage row:

```text
        - [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) 0x00483270-0x004832b9 | class method | ChattingColorListPaneFindIndexByColorValue : reconstructable : 84% : strong : Live IDA verifies exact bounds, callers from the select-current helper, count/item accessor callees, color-value comparison at item offset `+0x04`, zero fallback, and padding.
```

## Evidence Checked

Policy and workflow inputs:

- `tools/leaser/Agents/Supervisor.md`, including current B-agent report-only workflow, Rule 24/26/27 requirements, and the temporary `by-memory/-coverage-report.md` edit ban.
- `.codex/AGENTS.md` as provided in the workspace.
- `tools/leaser/Agents/Agent-B014/goal.md` and `tools/leaser/Agents/Agent-B014/notes.md`.
- `by-structure.md` current C++ gate: `RECONSTRUCTABLE:TRUE`, confirmed nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85` are minimum eligibility, with names/source shape still requiring evidence.

Target and support documentation:

- `by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md`
- `by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md`
- `by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md`
- `by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md`
- `by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md`
- `by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md`
- `by-class/ChattingColorListPane.md`
- `by-class/ChattingColorPane.md`
- `by-class/ChattingColorSelectPane.md`
- `by-file/Chatting.md`
- `by-class/ListPane.md`
- `by-file/ListPane.md`
- `by-memory/0x004f3a50-0x004f4a77.ListPane.md`
- `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
- `by-memory/0x00615460-0x00615560.ChattingColorTableConstants.md`

Generated/report state:

- `by-memory/-coverage-report.md`, read only for the current row text.
- `auto-generated/-ag-memory-coverage.md`, read only for emitter/has-cpp state.
- `auto-generated/NexusTK/social/Chatting.cpp`, read only for the empty emitter marker.
- `project-level/-auto-completion-stats.md`, read only for current target average `87.0`.

Prior B-agent reports used as leads and then rechecked:

- `tools/leaser/Agents/Agent-B007/research/0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality.md`
- `tools/leaser/Agents/Agent-B005/research/0002G8-ChattingColorListPaneSelectCurrentColor-source-quality.md`
- `tools/leaser/Agents/Agent-B011/research/0002F9-0002G8-0002GA-0002GE-0002GF-0002GG-ChattingPaintColorMessage-source-quality.md`

Current-session binary validation:

- Local PE: `E:\NTK\Resources\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- Sections checked:
  - `.text`: `0x00401000-0x0060c600`
  - `.rdata`: `0x0060d000-0x0066c200`
  - `.data`: `0x0066d000-0x0069ce24`
  - `.rsrc`: `0x0069d000-0x006b2e00`

No live IDA/MCP tool was available in this Codex tool context. Existing by-* docs contain prior live-IDA evidence; this pass independently rechecked the relevant range, helper bytes, padding, direct rel32 calls, and lack of absolute VA/RVA pointer references using a section-mapped PE scan.

## Binary Recheck

### Range And Padding

Fresh local PE bytes for `0x0048325b-0x004832c0` confirm the current split:

- `0x0048325b-0x00483260`: five `0xcc` alignment bytes after [UID:0002G8].
- `0x00483260-0x0048326f`: raw selected-color accessor [UID:0002G9].
- `0x0048326f-0x00483270`: one `0xcc` alignment byte.
- `0x00483270-0x004832b9`: target body, `0x49` bytes.
- `0x004832b9-0x004832c0`: seven `0xcc` alignment bytes before [UID:0002GB].

No split, merge, or range repair is recommended. The target is exactly one modeled helper bounded by padding and adjacent color-list helpers.

### Target Bytes And Control Flow

Fresh local PE bytes for `0x00483270-0x004832b9`:

```text
55 8b ec 56 57 8b f9 33 f6 e8 52 09 07 00 85 c0 7e 2f
53 8b 5d 08 56 8b cf e8 32 0b 07 00 3b 58 04 74 15 8b
cf 46 e8 35 09 07 00 3b f0 7c e7 5b 5f 33 c0 5e 5d c2
04 00 5b 5f 8b c6 5e 5d c2 04 00 5f 33 c0 5e 5d c2 04 00
```

Manual decode:

- Saves frame, `esi`, and `edi`.
- Stores receiver `this` in `edi`.
- Initializes `esi` to row index `0`.
- Calls `0x004f3bd0` at `0x00483279`.
- If the count is `<= 0`, returns `0`.
- Loads the one 32-bit argument from `[ebp+0x08]`; this is the searched color/palette value.
- Pushes the current row index and calls `0x004f3dc0` at `0x00483289`.
- Compares the searched value against `[item + 0x04]`.
- If equal, returns the current row index.
- If not equal, increments the row index and calls `0x004f3bd0` again at `0x00483299`.
- Loops while `row < GetItemCount()`.
- Returns `0` on empty list and no-match paths.
- Uses `ret 4`, confirming one 32-bit explicit argument after the `this` receiver.

The repeated call to `0x004f3bd0` after each increment is source-shaped for `for (int row = 0; row < GetItemCount(); ++row)` rather than a cached-count local.

### Caller And Callee Facts

Direct rel32 scan to `0x00483270` found exactly two inbound calls:

- `0x00483236 call 0x00483270`
- `0x0048324d call 0x00483270`

Both call sites are inside [UID:0002G8] `ChattingColorListPaneSelectCurrentColor`. There were no absolute VA or RVA pointer references to `0x00483270` in the mapped PE sections. This target is a directly called helper, not a vtable slot or pointer-table dispatch target.

Direct callees from the target bytes:

- `0x004f3bd0` at `0x00483279`.
- `0x004f3dc0` at `0x00483289`.
- `0x004f3bd0` again at `0x00483299`.

The PE scan found broad project-wide rel32 use of the shared ListPane helpers: 69 direct refs to `0x004f3bd0` and 98 direct refs to `0x004f3dc0`, matching reusable ListPane helper ownership rather than chat-only ownership.

### Shared Helper Byte Checks

Fresh bytes for `0x004f3bd0-0x004f3bdf`:

```text
8b 81 30 01 00 00 85 c0 75 01 c3 8b 40 0c c3
```

Role: `ListPane::GetItemCount()`. It reads the primary list pointer at `ListPane + 0x130`; if null it returns `0`, otherwise it returns the primary list count at offset `+0x0c`.

Fresh bytes for `0x004f3dc0-0x004f3dcf`:

```text
55 8b ec 8b 89 30 01 00 00 8b 01 5d ff 60 10
```

Role: indexed primary-list item getter. It loads the primary list pointer at `this+0x130`, loads that list's vtable, restores `ebp`, and tail-jumps through primary-list vtable slot `+0x10`. The caller-supplied index argument remains on the stack for the tail-dispatched list getter.

This byte shape rejects the current selected-entry-only wording in some support docs. Selected-entry callers are selected-entry-like only because they push `this+0x134` before calling the same indexed helper. [UID:0002GA] pushes its explicit loop row.

## Heuristic / Inference Reanalysis And Validation

### Source-Facing Method Name And Signature

Best source-facing name: `ChattingColorListPane::FindIndexByColorValue`.

Best source-facing signature:

```cpp
int ChattingColorListPane::FindIndexByColorValue(int colorValue)
```

Evidence:

- `ecx` is the receiver, preserved as `edi`, so this is a `__thiscall` class method.
- The function ends with `ret 4`, so it has one explicit 32-bit argument.
- The function returns row indices in `eax`, including `0` fallback and the current row on match.
- Both callers are inside `ChattingColorListPane::SelectCurrentColor` and pass foreground/background working color values from the owning color dialog.
- The method compares the passed value against `ChattingColorSwatchItem::colorValue` at item `+0x04`.

Rejected alternatives:

- `FindColorIndex`: plausible and shorter, but no evidence justifies renaming away from the current stable cross-reference name. `FindIndexByColorValue` is descriptive and precise.
- `GetColorIndex`: weaker because the method searches and can return fallback row `0`, not a direct field.
- `FindIndexByPaletteId`: possible if final headers define a palette-id typedef, but current docs consistently use color value/color swatch terminology.
- `COLORREF` or RGB-specific argument type: rejected for now. The values are 32-bit working palette/color slots backed by byte-sized persisted palette ids and UI palette constants, not proven Win32 RGB `COLORREF` values.
- `unsigned int`: possible at machine level, but the surrounding list/category code uses `int` row and color values in first-draft docs. `int colorValue` is the least disruptive source-level first draft.
- `const` method: not recommended for first draft because the inherited `GetItemCount()` and `GetItem(row)` helper declarations are not final const-qualified project APIs.
- Free helper/global helper: rejected. The method uses a class receiver and inherited `ListPane` storage, and its only direct callers are class-local color-list selection code.

### List Count Helper `0x004f3bd0`

Best source-facing name: `ListPane::GetItemCount()`.

Evidence:

- Bytes read `this+0x130`, return zero if the primary list pointer is null, otherwise return list offset `+0x0c`.
- `by-class/ListPane.md` already documents it as `GetItemCount`.
- Broad caller fanout across unrelated list subclasses supports reusable `ListPane` ownership.
- [UID:0002GA] calls it before the first iteration and after each row increment, exactly as a simple `GetItemCount()` loop would compile.

Rejected alternatives:

- Chat-specific count helper: rejected by broad caller fanout and the `ListPane +0x130` primary-list field.
- `GetSelectedCount`: rejected because selection state is not read here.
- Raw `sub_4F3BD0`: should not appear in final source prose or C++ except as evidence.

### Item Accessor Helper `0x004f3dc0`

Best source-facing role: indexed `ListPane::GetItem(int row)` / `ListPane::GetEntryAt(int row)`.

Recommended first-draft spelling in this target: `GetItem(row)`, because the neighboring color-list draw/selection pages describe list records as items and use `ChattingColorSwatchItem`.

Evidence:

- The helper tail-dispatches primary-list vtable slot `+0x10` with the caller's index argument preserved.
- [UID:0002GA] pushes explicit loop row `esi`; it is not pushing the selected-index field.
- [UID:0002G9] pushes `this+0x134` and therefore behaves like a selected-entry accessor only at that call site.
- [UID:0002GC] also uses the helper after selection state has been updated, validating the selected-item route without changing the helper's generic indexed role.

Rejected alternatives:

- Final helper name `GetSelectedEntry`: rejected as caller-biased. It is accurate for wrappers that pass `selectedIndex`, but false for this target's loop-row use.
- Chat-color-specific item getter: rejected. It reads only inherited `ListPane +0x130` and has 98 broad refs.
- Folding this helper into [UID:0002GA] C++ as raw primary-list access: rejected. Source-quality output should use the inherited `ListPane` API, not raw `this+0x130` vtable dispatch.

Support impact: `by-class/ListPane.md`, `by-file/ListPane.md`, `by-memory/0x004f3a50-0x004f4a77.ListPane.md`, and `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md` should update the selected-entry-only wording.

### Item Type And `+0x04` Field

Best item type: `ChattingColorSwatchItem`.

Acceptable fallback if final header naming chooses a less specific type: `ChattingColorListItem`.

Best field name: `colorValue` at item offset `+0x04`.

Evidence:

- [UID:0002GA] compares `[item + 0x04]` to the requested color value.
- [UID:0002G9] returns `[item + 0x04]` from the currently selected item.
- [UID:0002GB] first-draft C++ and behavior notes use `item->colorValue` for swatch fill and zero/default rendering.
- [UID:0002GC] first-draft C++ writes `item->colorValue` into the owner foreground/background color arrays.
- [UID:0002G7] populates 80 color entries from the chat color table constants and zeroes index `0` only for the secondary/background list.
- `by-class/ChattingColorListPane.md` records B002's accepted inference that item offset `+0x04` is `ChattingColorSwatchItem::colorValue`.

Rejected alternatives:

- `index` at `+0x04`: rejected because the target searches by requested color value; [UID:0002GB] draws with this value; [UID:0002GC] writes it to color arrays.
- Raw RGB `COLORREF`: rejected for now because constants and persisted data behave like palette/color ids, not proven RGB triples.
- Naming item `+0x00`: not supported by this target. The target only reads `+0x04`; item `+0x00` should remain unnamed or historically noted until constructor/allocation evidence proves it.

### Zero Fallback Semantics

Binary fact: all empty-list and no-match exits return row index `0`, not `-1`.

Source-facing meaning: row zero is the default/first-swatch fallback. [UID:0002G8] immediately passes the returned row to the inherited selection/update virtual with notification flag `false`; it does not range-check or branch on failure. The behavior must be preserved as source logic.

Interaction with neighboring docs:

- In the background/secondary list, [UID:0002G7] zeroes swatch index `0`, so fallback row `0` is also the empty/default background color choice.
- In the foreground list, row `0` is still the first color-table swatch. The same source fallback applies even though that row is not zeroed.

Rejected alternatives:

- Return `-1` on no match: rejected by exact return paths.
- Treat the zero return as a boolean failure code: rejected because the caller uses it as a selected row index.
- Add explicit null/list guards in C++: the binary only relies on `GetItemCount()` and the inherited getter; it does not null-check returned item pointers before `[item+0x04]`.

### Caller, Reachability, And Neighbor Relationship

Direct callers:

- `0x00483236` inside [UID:0002G8] foreground path.
- `0x0048324d` inside [UID:0002G8] background path.

No absolute VA or RVA pointer references to `0x00483270` were found in the mapped PE sections, and no vtable route is needed for this helper. The target is directly reachable from the color-list current-color synchronization path.

Sibling relationship:

- [UID:0002G8] `SelectCurrentColor` is the direct caller. It reads `m_pColorPane`, `m_isForegroundList`, `m_selectedChatColorCategory`, and one of the owner foreground/background arrays, then maps that color value through this target.
- [UID:0002G9] `GetSelectedColorValueRaw` is adjacent and validates the same item field/accessor, but it remains an unmodeled no-route raw helper. Its no-code status does not block [UID:0002GA].
- [UID:0002GB] `DrawItem` validates the item field by drawing swatches from `item->colorValue` and treating zero as a special default swatch branch.
- [UID:0002GC] `OnItemSelected` validates the item field and owner field model by writing `item->colorValue` to the active foreground/background array.
- [UID:0002G7] constructor validates the 80-row swatch list and the background row-zero behavior.

Reachability conclusion: [UID:0002GA] is source-authored reachable code, not a retained no-route raw island, padding, vtable thunk, or compiler artifact.

### Ownership And Source Placement

Accepted direct owner: [UID:00001S] `ChattingColorListPane`.

Evidence:

- The receiver is the color-list pane.
- Direct callers are inside the same color-list class helper [UID:0002G8].
- The method scans the color-list pane's inherited list entries.
- Sibling draw and selection virtuals in the same class use the same item type/field.
- `by-class/ChattingColorListPane.md` already owns the exact local `0x00482fb0-0x00483490` cluster.

Accepted file route: [UID:0000I5] `Chatting`.

Evidence:

- Current class owner [UID:00001S] emits through [UID:0000I5].
- Generated `Chatting.cpp` contains the empty marker for [UID:0002GA].
- `by-file/Chatting.md` covers the chat color pane/select/list family and keeps the broader color dialog split as a possible future cleanup only.

Rejected owners/source placements:

- [UID:00001T] `ChattingColorPane`: rejected as direct owner. It owns the color arrays and constructs the list children, but the receiver and row lookup behavior are in the color-list pane.
- [UID:00001U] `ChattingColorSelectPane`: rejected. It triggers list refresh through other helpers but does not own color swatch lookup.
- [UID:00007A]/[UID:0000KT] `ListPane`: rejected as target owner. ListPane owns `GetItemCount()` and indexed `GetItem(row)`, but [UID:0002GA] is chat-color-specific matching over `ChattingColorSwatchItem::colorValue`.
- New `social/ChatColorDialog.cpp` split: plausible for a broader future color-dialog source cleanup, but no current evidence requires moving this one helper. A split would need to cover `ChattingColorPane`, `ChattingColorSelectPane`, `ChattingColorListPane`, and color table constants together, not this target alone.

### Split, Range, And Container Decisions

No child split is needed for [UID:0002GA]. The body is a compact exact method at `0x00483270-0x004832b9` with no embedded data, no switch table, no compiler thunk tail, and no unrelated owner subrange.

No merge is recommended:

- [UID:0002G9] remains a separate raw selected-color accessor at `0x00483260-0x0048326f`.
- [UID:0002GB] begins after seven `0xcc` bytes at `0x004832c0`.
- The one-byte leading padding at `0x0048326f-0x00483270` and seven-byte trailing padding at `0x004832b9-0x004832c0` should stay as ignored coverage rows/padding, not be folded into the target.

### First-Draft C++ Readiness

No-code proof is not applicable. The target is not compiler glue, not a scalar deleting destructor, not an adjustor thunk, not padding, not raw no-route retained code, and not a broad aggregate.

The active code-entry gate is satisfied:

- `RECONSTRUCTABLE:TRUE`.
- Nonblank `EMITTER_UIDS:00001S`.
- Valid generated route through `auto-generated/NexusTK/social/Chatting.cpp`.
- Current average is already `(84 + 90) / 2 = 87`, above `85`.
- Recommended score `87/92` strengthens the gate and reflects resolved helper/type/source-shape issues.

Remaining uncertainties are nonblocking:

- Exact original spelling of `FindIndexByColorValue`, `GetItem`, and `ChattingColorSwatchItem` is not recovered.
- A final palette-id typedef may later refine `int colorValue`.
- Item `+0x00` remains unnamed.

These uncertainties cap the score below final-audit quality, but they do not justify leaving formal C++ blank.

## First-Draft C++ Recommendation

Place this block between the target's `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` markers if the supervisor accepts this report:

```cpp
int ChattingColorListPane::FindIndexByColorValue(int colorValue)
{
    for (int row = 0; row < GetItemCount(); ++row) {
        ChattingColorSwatchItem *item =
            static_cast<ChattingColorSwatchItem *>(GetItem(row));
        if (item->colorValue == colorValue)
            return row;
    }

    return 0;
}
```

Implementation notes:

- `GetItemCount()` is the source-facing wrapper for `0x004f3bd0`.
- `GetItem(row)` is the source-facing wrapper for `0x004f3dc0`; if the final ListPane header standardizes on `GetEntryAt(row)`, update only this helper spelling.
- Do not cache `GetItemCount()` in the first draft. The binary calls the count helper before the first iteration and again after each increment, matching a simple loop condition call.
- Do not add a null guard around `item`; the binary immediately reads `[item+0x04]`.
- Do not return `-1`; the binary's no-match and empty-list return is row `0`.
- Use `int colorValue` for this first draft. A later support pass may introduce a project typedef for palette/color ids.

## Score And Metadata Recommendation

Recommended target score: `87/92`.

Completion rationale:

- Raise from `84` to `87` because the report resolves the stale first-C++ blocker, confirms exact executable bytes, confirms direct callers/callees, resolves helper roles, corrects `0x004f3dc0` from selected-entry-only to indexed item access, validates `ChattingColorSwatchItem::colorValue`, closes zero-fallback semantics, keeps owner/emitter/source placement stable, and supplies first-draft C++.

Confidence rationale:

- Raise from `90` to `92` because current-session PE evidence independently corroborates the prior live-IDA-backed docs, including boundary padding, direct call sites, helper calls, helper byte roles, no pointer/vtable route to the target, and sibling item-field validation.
- Do not raise to `95+` because exact original source spellings and final class/header declarations remain descriptive/inferred.

Owner/emitter:

- Keep `CANONICAL_OWNER:00001S`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00001S`.
- Keep source route through [UID:0000I5] `Chatting`; do not move to a new source file in this callback.

## Open-Question Closure

Closed:

- Final source-facing name/signature: use `int ChattingColorListPane::FindIndexByColorValue(int colorValue)`.
- Item field at `+0x04`: use `ChattingColorSwatchItem::colorValue`.
- Helper `0x004f3bd0`: `ListPane::GetItemCount()`.
- Helper `0x004f3dc0`: indexed `ListPane::GetItem(row)` / `GetEntryAt(row)`, not selected-entry-only.
- Zero fallback: source-authored row `0` fallback for empty/no-match; never rewrite as `-1`.
- Caller route: only direct callers are [UID:0002G8] call sites `0x00483236` and `0x0048324d`; target also participates in reachable color-list refresh through [UID:0002G1]/[UID:0002G6] via [UID:0002G8].
- Owner/source placement: direct owner/emitter [UID:00001S], file route [UID:0000I5].
- Split/range: no split or merge needed.
- C++ readiness: first-draft C++ is recommended.

Remaining nonblocking:

- Exact original spelling of the target method, item type, and list getter is not recovered. The recommended names are descriptive, high-probability, and already consistent with surrounding docs.
- Item offset `+0x00` remains unnamed because this target does not read it and the checked neighboring docs do not prove a safe name.
- A future source-tree split to `social/ChatColorDialog.cpp` remains plausible but needs a broader class-family/source-layout pass, not a one-method move.

## Rejected Alternatives Summary

- Leave final C++ blank due to old 95/95 language: rejected by current by-structure C++ gate and resolved source-shape evidence.
- Treat this as raw/no-route/no-code: rejected by modeled function boundary and direct callers.
- Move direct ownership to `ChattingColorPane`: rejected because the receiver and list scan are `ChattingColorListPane`.
- Move direct ownership to `ListPane`: rejected because only generic helpers are ListPane-owned; the target is chat-color-specific.
- Return `-1` or add an error branch for no match: rejected by binary return paths and caller usage.
- Name `0x004f3dc0` `GetSelectedEntry` in final source: rejected because [UID:0002GA] passes an explicit loop row.
- Add null item guard in C++: rejected because the binary has no such guard.
- Rename to `FindColorIndex` now: rejected as unnecessary churn without stronger original-name evidence.

## Exact Target Implementation Checklist

Target file for later implementation callback:

- `by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md`

Required target edits if accepted:

- Change metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Keep:

```text
*** CANONICAL_OWNER:00001S | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00001S | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Insert the first-draft C++ block from this report.
- Add `Rebuild handling: source-authored` and `First-draft C++ readiness: ready under the active combined-score/emitter gate` to status/source-shape prose.
- Replace the stale sentence:

```text
Final C++ remains blank because the final list item type and helper names are below the 95/95 source-emission gate.
```

with:

```text
First-draft C++ is now appropriate. The final source-facing shape is `int ChattingColorListPane::FindIndexByColorValue(int colorValue)`: iterate rows from `0` while `row < GetItemCount()`, fetch each `ChattingColorSwatchItem` through indexed `ListPane::GetItem(row)` at `0x004f3dc0`, compare `item->colorValue` at item offset `+0x04`, return the first matching row, and return row `0` as the default/first-swatch fallback when the list is empty or the color is not found.
```

- Add a B014 2026-06-19 source-quality section carrying:
  - local PE path and MD5,
  - exact `0x00483270-0x004832b9` bytes or byte-summary,
  - one-byte leading and seven-byte trailing padding,
  - direct caller sites `0x00483236` and `0x0048324d`,
  - target helper call sites `0x00483279`, `0x00483289`, `0x00483299`,
  - `0x004f3bd0` as `ListPane::GetItemCount()`,
  - `0x004f3dc0` as indexed `ListPane::GetItem(row)`,
  - `ChattingColorSwatchItem::colorValue` at `+0x04`,
  - row-zero fallback semantics,
  - rejected no-code/`-1`/selected-entry-only alternatives.
- Replace score rationale with the `87/92` rationale from this report.
- Add a change entry:

```text
- 2026-06-19 B014 source-quality report: recommends `87/92`, first-draft `FindIndexByColorValue` C++, `ListPane::GetItemCount` / indexed `ListPane::GetItem` helper naming, `ChattingColorSwatchItem::colorValue` field wording, row-zero fallback semantics, and removal of stale below-95 blank-C++ gate text. No owner/emitter/source-route change.
```

## Support Documentation Checklist

These are report-only recommendations. Do not apply until a supervisor implementation callback accepts the report.

### `by-class/ChattingColorListPane.md`

Add or update data/evidence notes:

```text
- [UID:0002GA] is first-draft C++ ready as `int FindIndexByColorValue(int colorValue)`. It uses `ListPane::GetItemCount()` and the indexed `ListPane::GetItem(row)` helper to scan `ChattingColorSwatchItem::colorValue` at item offset `+0x04`, returning the first matching row or row `0` as the default/fallback row.
- `0x004f3dc0` should not be described as selected-entry-only in color-list docs. It tail-dispatches the primary list's indexed getter; callers decide whether the index is the selected row or an explicit loop row.
```

No class score change is required from this one support update.

### `by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md`

Add a support/source-quality note:

```text
B014 2026-06-19 reanalysis of [UID:0002GA] resolves the callee as source-ready `FindIndexByColorValue(int colorValue)`. This caller reads the current category from the owner dialog, chooses `m_chatColorForeground` when `m_isForegroundList` is nonzero and `m_chatColorBackground` when zero, then selects the returned row. A missing/unlisted current color intentionally selects row `0`; do not rewrite the source shape to use `-1` or an error branch.
```

If [UID:0002G8] receives its own accepted first-draft C++ callback, coordinate the wording so it calls `FindIndexByColorValue(colorValue)` and does not duplicate contradictory helper names.

### `by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md`

Add a support note:

```text
B014 2026-06-19 reanalysis of [UID:0002GA] clarifies that the shared `0x004f3dc0` helper is an indexed primary-list getter. This raw selected-color helper is selected-entry-like because it pushes `this+0x134` before calling that indexed getter; the same helper is used by [UID:0002GA] with an explicit loop row. The best item field remains `ChattingColorSwatchItem::colorValue` at `+0x04`.
```

Do not add formal C++ to [UID:0002G9] from this report. It remains a no-route raw helper unless a caller/signature route is found.

### `by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md`

No required score/C++ change. If updating support prose, add:

```text
[UID:0002GA] independently validates `ChattingColorSwatchItem::colorValue` at item `+0x04` by scanning list rows for a requested color value before [UID:0002G8] selects the matching row.
```

### `by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md`

No required score/C++ change. If updating support prose, add:

```text
[UID:0002GA] uses the same `ChattingColorSwatchItem::colorValue` field that this selection handler writes back to `m_chatColorForeground` or `m_chatColorBackground`.
```

### `by-class/ListPane.md`

Replace or revise the `0x004f3dc0` method row so it no longer says selected-entry-only:

```markdown
| `GetItem` / indexed entry accessor | `0x004f3dc0-0x004f3dcf` | Tail-dispatches the primary list vtable slot `+0x10` with the caller-supplied index argument still on the stack. Some callers pass `selectedIndex`, but [UID:0002GA] passes an explicit loop row, so previous `GetSelectedEntry` wording was caller-biased. Currently emitted under `ChattingColorListPane` and used by many list subclasses. |
```

No `ListPane` score change is required.

### `by-file/ListPane.md`

In `Current Source-Output Split`, replace or revise the row for chat-color emitted helpers:

```markdown
| `class_ChattingColorListPane.cpp` | `0x004f3c50`, `0x004f3dc0`, `0x004f3f00` | Move to `ListPane.cpp`; `0x004f3dc0` is an indexed primary-list getter (`GetItem`/`GetEntryAt`), not a chat-color or selected-entry-only helper. Current chat-color owner is caller pollution. |
```

Add an evidence/migration note:

```text
B014 2026-06-19 target [UID:0002GA] reanalysis confirmed from local PE bytes that `0x004f3dc0` preserves the caller-supplied index for the primary list vtable slot `+0x10`; selected-entry wording should be retained only as a historical/generated alias for callers that pass `selectedIndex`.
```

No `ListPane` file score change is required.

### `by-memory/0x004f3a50-0x004f4a77.ListPane.md`

Replace the function map row:

```markdown
| `0x004f3dc0` | `0x0f` | `ListPane::GetSelectedEntry` | Emitted under `ChattingColorListPane`. |
```

with:

```markdown
| `0x004f3dc0` | `0x0f` | `ListPane::GetItem` / indexed entry accessor | Tail-dispatches the primary list vtable slot `+0x10` with the caller-supplied index argument; the older `GetSelectedEntry` spelling is selected-index caller bias. Emitted under `ChattingColorListPane`. |
```

### `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`

Replace the inventory row:

```markdown
| `0x004f3dc0-0x004f3dcf` | modeled `sub_4F3DC0` | Fetches selected entry through the primary list. |
```

with:

```markdown
| `0x004f3dc0-0x004f3dcf` | modeled `sub_4F3DC0` | Indexed primary-list getter; tail-dispatches the primary list vtable slot `+0x10` using the caller-supplied index argument. Selected-entry callers pass `this+0x134`, but [UID:0002GA] passes an explicit loop row. |
```

### `by-file/Chatting.md`

No route change is recommended. If adding a support note:

```text
B014 2026-06-19 reanalysis of [UID:0002GA] keeps `ChattingColorListPane::FindIndexByColorValue` under the current `social/Chatting.cpp` route. The target is first-draft C++ ready; a future `social/ChatColorDialog.cpp` split remains a broader source-tree cleanup question, not a blocker for this method.
```

## Exact Supervisor-Owned Coverage Row Text

`by-memory/-coverage-report.md` is supervisor-owned under the active ban. B014 did not edit it.

Replace the current [UID:0002GA] row with:

```text
        - [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) 0x00483270-0x004832b9 | class method | ChattingColorListPaneFindIndexByColorValue : reconstructable : 87% : very strong : B014 2026-06-19 source-quality reanalysis verifies exact local PE bytes and padding, direct callers `0x00483236`/`0x0048324d` from `SelectCurrentColor`, two `ListPane::GetItemCount` calls at `0x00483279`/`0x00483299`, indexed `ListPane::GetItem` call at `0x00483289`, zero-based swatch scan, `ChattingColorSwatchItem::colorValue` at item `+0x04`, row-zero fallback for empty/no-match, current `Chatting.cpp` emitter route, and first-draft C++ readiness under the active combined-score/emitter gate.
```

## Validator Baseline

Scoped validator was run on the untouched target as a report-only baseline:

> Executable block R001 was removed from this report and preserved verbatim in [0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality-removed.md](0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Working directory: `E:\NTK\GhidraBridge\source-3\project-documentation`
- Exit code: `0`
- `apply: False`
- `scanned markdown files: 1`
- `ok: 1`
- Target result: `ok 0002GA by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md UID header exists`
- Dry-run generated state: `auto-generated/NexusTK/social/Chatting.cpp unchanged`; `auto-generated/-ag-memory-coverage.md unchanged`; project stats skipped because `--apply` was not used.

Expected validator/generator impact after implementation:

- Run target/support validators with `--apply` for every edited by-* file.
- `auto-generated/-ag-memory-coverage.md` should change [UID:0002GA] from `has cpp` `no` to `yes`.
- `auto-generated/NexusTK/social/Chatting.cpp` should replace the [UID:0002GA] empty emitter marker with the accepted `FindIndexByColorValue` body.
- If the supervisor applies the coverage replacement row, validate `by-memory/-coverage-report.md` separately.

Recommended implementation-time validator commands:

> Executable block R002 was removed from this report and preserved verbatim in [0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality-removed.md](0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run support validators for support files actually touched.

## IDA Name/Comment Recommendations

No IDA database edits were made. If a later IDA cleanup pass is permitted:

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x00483270` | `ChattingColorListPane::FindIndexByColorValue` or IDA-safe `ChattingColorListPane_FindIndexByColorValue` | high/descriptive |
| `0x004f3bd0` | `ListPane::GetItemCount` | high/descriptive |
| `0x004f3dc0` | `ListPane::GetItem` or `ListPane::GetEntryAt`; document that selected-entry callers pass selected index explicitly | high for role, medium for exact spelling |
| `ChattingColorListPane +0x14c` | `m_pColorPane` | high, already supported by constructor/select/selection docs |
| `ChattingColorListPane +0x150` | `m_isForegroundList` | high, foreground/background writeback evidence |
| `ChattingColorSwatchItem +0x04` | `colorValue` | high |
| `ChattingColorSwatchItem +0x00` | leave unnamed until stronger evidence | open/nonblocking |

Suggested comment at `0x00483270`:

```text
Scans ChattingColorSwatchItem rows for item+0x04 == requested color value; returns first row or row 0 fallback. Calls ListPane::GetItemCount and indexed ListPane::GetItem(row).
```

Suggested comment at `0x004f3dc0`:

```text
ListPane indexed item getter wrapper. Tail-jumps to primary list vtable slot +0x10 with caller-supplied index still on stack; selected-entry callers pass selectedIndex explicitly.
```

## Files Created Or Edited

Created:

- `tools/leaser/Agents/Agent-B014/research/0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality.md`

Not edited:

- No by-* documentation files were edited.
- `by-memory/-coverage-report.md` was not edited.
- No generated files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0002GA"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0002GA-ChattingColorListPaneFindIndexByColorValue-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002GA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
