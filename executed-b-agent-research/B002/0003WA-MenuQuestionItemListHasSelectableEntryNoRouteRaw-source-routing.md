** TARGET-REPORT-UID:0003WA **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003WA **
# Agent-B002 Report: [UID:0003WA] MenuQuestionItemListHasSelectableEntryNoRouteRaw

## Scope

- Assignment: `B002` report-only source-routing/source-quality pass.
- Target: [UID:0003WA] `by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md`.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0003WA-MenuQuestionItemListHasSelectableEntryNoRouteRaw-source-routing.md`.
- Rules observed: report-only; no target/support by-* docs edited; `by-memory/-coverage-report.md` not edited.

## Recommendation

Keep [UID:0003WA] as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.

Raise target metadata from `COMPLETION:85 | CONFIDENCE:86` to `COMPLETION:86 | CONFIDENCE:88` after implementation. The source shape and helper names are now better resolved, and the no-route proof is stronger than the current page. Do not assign [UID:00007Z] `MenuQuestionItemList` as owner unless a later route appears.

Best source-facing role if this helper were live:

```cpp
// no emitted C++; descriptive only
uint8_t MenuQuestionItemList::GetSelectedOptionId() const;
```

The byte returned is the first byte of the selected menu-question row payload. Constructor/action docs describe menu-question rows as a one-byte option id followed by row text consumed at `itemData + 2`; therefore the best field name is `optionId` / `selectionValue` at row offset `+0x00`. `HasSelectableEntry` is a useful behavior title for the no-route page, but it is not the best source name: the body does not count/selectability-test the list. It fetches the selected row and returns row byte `+0`.

## Byte And Boundary Evidence

Read-only PE checked:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- image base `0x00400000`
- `.text` VA `0x00401000-0x0060c600`, raw `0x000400-0x20ba00`
- `.rdata` VA `0x0060d000-0x0066c200`, raw `0x20ba00-0x26ac00`

Exact [UID:0003WA] body:

```asm
00550e20  ff b1 34 01 00 00    push dword ptr [ecx+0x134]
00550e26  e8 95 2f fa ff       call 0x004f3dc0
00550e2b  8a 00                mov  al, byte ptr [eax]
00550e2d  c3                   ret
```

Raw bytes: `ff b1 34 01 00 00 e8 95 2f fa ff 8a 00 c3`.

Boundary:

- `0x00550e16-0x00550e20`: ten `0xcc` bytes after [UID:0003W9] raw add-row helper.
- `0x00550e20-0x00550e2e`: 14-byte source-shaped body.
- `0x00550e2e-0x00550e30`: two `0xcc` bytes.
- `0x00550e30`: [UID:0003WB] live vtable method starts with `mov ecx,[ecx+0x14c]; jmp 0x0049de70`.

This corrects the current target/coverage wording: the helper does not "load `[ecx+0x134]`"; it pushes `ListPane +0x134` as the explicit index argument to the shared row accessor.

## Helper And Field Inference

`[ecx+0x134]`:

- Defensible source role: inherited `ListPane::m_selectedIndex`.
- Evidence: [UID:00007A] `ListPane`, [UID:0000KT] `ListPane`, and [UID:0003U0] `ListPaneItemSelectionStorageHelpers` document `+0x130` as primary list, `+0x134` as selected index, `+0x138` as selection flag list, and `+0x13c` as selection/multi-select mode byte.
- Counter-evidence checked: `MenuQuestionItemList` constructor stores owner/dialog pointer at `+0x14c`; the raw helper uses `+0x134`, so this is not the owner pointer or child-control field.

`0x004f3dc0`:

- Current docs often call it `ListPane::GetSelectedEntry`.
- Best source-quality name for this report: `ListPane::GetEntryAt(int index)` or `ListPane::GetItemData(int index)`, with `GetSelectedEntry` kept as an alias where callers push `m_selectedIndex`.
- Evidence: exact disassembly is:

```asm
004f3dc0  push ebp
004f3dc1  mov  ebp, esp
004f3dc3  mov  ecx, [ecx+0x130]
004f3dc9  mov  eax, [ecx]
004f3dcb  pop  ebp
004f3dcc  jmp  dword ptr [eax+0x10]
```

This helper does not read `+0x134` itself; it forwards the caller-supplied index to the primary list object's virtual slot `+0x10`. For [UID:0003WA], the caller-supplied index is `m_selectedIndex`.

Returned byte:

- Best field: `MenuQuestionItemEntry::optionId` / `selectionValue` at entry offset `+0x00`.
- Evidence: `MenuQuestionDialog` constructor docs say row insertion uses a one-byte one-based option id and that draw reads the UTF-16 label at `itemData + 2`. [UID:0003WC] draws text from `itemData+2`. The selected-row byte at `+0` is the row's option/submission byte, not a boolean selected flag.
- Uncertainty: row byte `+1` is not resolved. The report should not invent a full struct beyond `{ uint8_t optionId; uint8_t unknownOrPadding; wchar_t label[]; }`.

`0x004f3e20` relationship:

- Live confirm-button update methods [UID:0003W2] and [UID:0003W6] call `0x004f3e20`, not [UID:0003WA].
- Exact normal updater call sequence fetches child id `1` then child id `5`, loads the embedded list from control offset `+0x108`, calls `0x004f3e20`, and dispatches button slot `+0x4c` when count/state is positive or `+0x50` otherwise.
- `0x004f3e20` source role is `ListPane::GetSelectionCount()` / `HasSelection()` depending selection mode. In single-selection mode it returns `selectedIndex >= 0`; in multi-select mode it counts nonzero bytes in the selection flag list.
- Therefore [UID:0003WA] is not the live confirm-button selectability probe. It is a selected-row option-id helper that would be useful to a selection submission path.

## Route And Liveness Checks

Read-only PE scans performed in this pass:

- `rel32` call/jump scan over executable sections for target `0x00550e20`: `0` hits.
- short relative branch scan (`jmp rel8`, `jcc rel8`, loop/jecxz style) for target `0x00550e20`: `0` hits.
- absolute VA dword scan for `0x00550e20`: `0` hits.
- RVA dword scan for `0x00150e20`: `0` hits.
- raw file-offset dword scan for `0x00150220`: `0` hits.
- same scan shape for larger sibling [UID:0003WF] `0x00550f80`: no hits.

Positive controls:

- [UID:0003WB] `0x00550e30` has a VA dword vtable hit at `.rdata` VA `0x006227b0`.
- [UID:0003WC] `0x00550e40` has a VA dword vtable hit at `.rdata` VA `0x006227b4`.
- [UID:0003WG] `0x00550f90` has a VA dword vtable hit at `.rdata` VA `0x00622874`.
- [UID:0003WH] `0x00550fa0` has a VA dword vtable hit at `.rdata` VA `0x00622878`.
- Shared accessor `0x004f3dc0` has 98 `rel32` call hits.
- Shared selection-count helper `0x004f3e20` has 14 `rel32` call hits, including updater calls at `0x0054fa48` and `0x00550c68`.

The positive controls show the scan finds ordinary vtable/data routes and direct call routes in this binary. The lack of any equivalent route to `0x00550e20` is meaningful, not a tooling blind spot in this pass.

## Sibling And Pattern Evidence

The exact selected-row payload helper byte pattern:

```text
ff b1 34 01 00 00 e8 ?? ?? ?? ?? 8a 00 c3
```

appears four times in `.text`:

| VA | Call target | Known role |
| --- | --- | --- |
| `0x0048b090` | `0x004f3dc0` | Clan item-list selected slot raw island; no-route per [UID:00010Q]. |
| `0x004aec80` | `0x004f3dc0` | [UID:0002JP] live `MyItemListPane::GetSelectedSlotIndex`, modeled IDA function with two direct callers. |
| `0x00550e20` | `0x004f3dc0` | [UID:0003WA] normal menu-question selected option-id no-route island. |
| `0x00550f80` | `0x004f3dc0` | [UID:0003WF] larger menu-question selected option-id no-route island. |

This pattern argues against "random compiler/linkage artifact." It is source-shaped UI helper logic. It also argues against assigning ownership from byte shape alone: [UID:0002JP] is reconstructable because it has callers; [UID:00010Q], [UID:0003WA], and [UID:0003WF] remain no-route/blank-C++ despite similar behavior.

## Ownership Alternatives Checked

### [UID:00007Z] MenuQuestionItemList

Evidence for:

- Helper lies between [UID:0003W9] normal raw add-row and [UID:0003WB]/[UID:0003WC] normal live list methods.
- It uses inherited `ListPane +0x134` and the row payload produced by the normal menu-question list constructor/add-row path.
- Larger sibling [UID:0003WF] sits in the equivalent larger list position.

Evidence against assigning:

- No IDA function object.
- No xrefs, no branch route, no VA/RVA/raw-offset pointer route.
- Not present in [UID:0003D6] vtable; vtable positive controls route only [UID:0003WB] and [UID:0003WC].
- Live confirm updater uses `ListPane::GetSelectionCount()` instead of this helper.

Decision: keep as semantic context for [UID:00007Z], but not owner/emitter.

### [UID:00007X] MenuQuestionDialog / [UID:0000LA] MessageDialogs

Evidence for:

- Dialog constructors create the menu-question lists and row payloads.
- Action handlers submit selected menu values with opcode `0x3a`.
- The source file family is `MessageDialogs.cpp`.

Evidence against assigning:

- Receiver is a `ListPane`-derived list object (`this+0x134` selected index), not the dialog.
- No direct call from [UID:0003W1] action handler or [UID:0003W2] updater to this entry.
- Assigning this raw no-route island to [UID:0000LA] would create an emitted source function without a proven call/vtable surface.

Decision: mention the family relationship in support docs; do not assign owner.

### [UID:0000KT] ListPane

Evidence for:

- The body uses inherited `ListPane` fields and the shared list-entry accessor.

Evidence against assigning:

- The returned byte is menu-question row payload semantics, not generic list control behavior.
- Generic `ListPane` already supplies the actual reusable helpers at `0x004f3dc0` and `0x004f3e20`.

Decision: ListPane is a dependency only.

### Compiler/linker retention or dead method

Evidence for:

- The helper is small, source-shaped, duplicated in normal/larger menu-question lists, and separated by `0xcc` alignment.
- No modeled function/xref/pointer route found.
- Equivalent live behavior can be reached through surrounding action/updater paths without using this entry.

Decision: best current explanation is retained unused private helper or missed source method whose address is not referenced in this binary. Treat as no-owner/non-emitting until a route appears.

## No-Code Proof

Formal C++ should remain blank for [UID:0003WA].

Target-specific proof:

- `RECONSTRUCTABLE:FALSE` by current and recommended metadata.
- No canonical owner/emitter route.
- No IDA function object at `0x00550e20`.
- No vtable cell or ordinary code caller.
- No `rel32`, short-branch, VA, RVA, or raw-offset pointer route to the entry in this PE scan.
- Live source-bearing siblings are already represented by [UID:0003WB] and [UID:0003WC]; [UID:0003WA] is not needed for the known vtable/list behavior.
- The only plausible C++ would be a private selected-option helper, but emitting it would invent a source call surface.

Do not add a first-draft C++ block unless future evidence finds a real call/pointer/vtable route.

## Recommended Target Doc Changes

Update `by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md`:

1. Set metadata:
   - `COMPLETION:86`
   - `CONFIDENCE:88`
   - keep `CANONICAL_OWNER:NONE`
   - keep `RECONSTRUCTABLE:FALSE`
   - keep blank `EMITTER_UIDS`
   - keep blank C++.

2. Replace the behavior text with:
   - exact bytes `ff b1 34 01 00 00 e8 95 2f fa ff 8a 00 c3`;
   - exact disassembly shown above;
   - "pushes inherited `ListPane::m_selectedIndex` at `this+0x134`" instead of "loads `[ecx+0x134]`";
   - calls shared `ListPane` entry accessor `0x004f3dc0`, best named `ListPane::GetEntryAt(int index)` / current-doc alias `GetSelectedEntry`;
   - returns selected row byte `+0x00`, best inferred as `MenuQuestionItemEntry::optionId` / `selectionValue`.

3. Add boundary/padding:
   - `0x00550e16-0x00550e20`: ten `0xcc`;
   - `0x00550e2e-0x00550e30`: two `0xcc`;
   - successor [UID:0003WB] starts at `0x00550e30` and is vtable-routed through `0x006227b0`.

4. Add route proof:
   - no IDA function object;
   - no xrefs;
   - no `rel32`, short-branch, VA, RVA, or raw-offset route in B002 PE scan;
   - positive controls found adjacent vtable entries for `0x00550e30`/`0x00550e40` and direct call fanout to `0x004f3dc0`/`0x004f3e20`.

5. Add confirm-button relationship:
   - [UID:0003W2] and [UID:0003W6] use `0x004f3e20` `ListPane::GetSelectionCount` / `HasSelection`, not this helper;
   - this helper would return the selected option id for a selected row, so `HasSelectableEntry` is a behavior title rather than a proven source method name.

6. Add sibling/pattern note:
   - compare [UID:0003WF] at `0x00550f80`;
   - compare live [UID:0002JP] and no-route [UID:00010Q] selected-slot helper pattern;
   - conclude retained/orphaned source-shaped helper is the best current explanation.

## Recommended Support Doc Changes

If supervisor accepts implementation, update with report-level detail:

- `by-class/MenuQuestionItemList.md`
  - Keep raw helper [UID:0003WA] non-emitting.
  - Add that its exact role is "selected option-id payload helper" rather than actual live selectability/count test.
  - Record `+0x134` as inherited selected index and row byte `+0` as option id / selection value.

- `by-class/MenuQuestionItemListLarger.md`
  - Mirror note for [UID:0003WF] if supervisor wants sibling consistency, or at least cross-reference this B002 analysis as applying to both copies.

- `by-class/MenuQuestionDialog.md`
  - Confirm-button updater [UID:0003W2] should say it calls `ListPane::GetSelectionCount()` / `HasSelection` at `0x004f3e20`, not the raw selected-option helper.
  - Action/constructor notes may keep row payload `{ optionId, unknown/padding, UTF-16 label at +2 }`.

- `by-class/MenuQuestionDialogLarger.md`
  - Same updater note for [UID:0003W6].

- `by-file/MessageDialogs.md`
  - Keep [UID:0003WA]/[UID:0003WF] listed as non-emitting raw helper evidence.
  - Clarify no owner/emitter despite `MessageDialogs` family context because no route exists.

- `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`
  - Update the [UID:0003WA] row with exact `push [ecx+0x134]` wording, row byte `+0` option-id role, and PE route proof.
  - Optionally update [UID:0003WF] row similarly for parity.

- `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
  - Optional source-quality cleanup: clarify `0x004f3dc0` takes an explicit index and is better described as `ListPane::GetEntryAt(int index)` / `GetItemData(int index)`. Keep `GetSelectedEntry` as a call-site alias until broader ListPane API names are finalized.

- `by-memory/0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md`
  - Add exact updater disassembly summary if desired: child id `1`, child id `5`, embedded list at control `+0x108`, `0x004f3e20`, button slots `+0x4c/+0x50`.

- `by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md`
  - Same exact updater summary for larger dialog.

No generated/autogen refresh is needed because [UID:0003WA] remains non-emitting and has no C++ block.

## Exact Coverage Replacement Row

Do not edit `by-memory/-coverage-report.md` during report-only work. Supervisor-owned replacement row for [UID:0003WA]:

```md
        - [UID:0003WA][0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw](by-memory/0x00550e20-0x00550e2e.MenuQuestionItemListHasSelectableEntryNoRouteRaw.md) 0x00550e20-0x00550e2e | no-route raw selected-option helper | MenuQuestionItemListHasSelectableEntryNoRouteRaw : ignored/non-emitting : 86% : strong : B002 2026-06-19 PE/source-routing recheck confirms exact 14-byte body `push [ecx+0x134]; call 0x004f3dc0; mov al,[eax]; ret`, where `+0x134` is inherited `ListPane::m_selectedIndex`, `0x004f3dc0` is the shared explicit-index entry accessor (`GetEntryAt` / current `GetSelectedEntry` alias), and row byte `+0` is best inferred as the menu-question option id/selection value. No IDA function, no xrefs, no rel32/short-branch/VA/RVA/raw-offset route to `0x00550e20`; adjacent positive controls still find vtable refs to `0x00550e30`/`0x00550e40` and 98/14 direct call hits to the shared ListPane helpers. Keep no-owner/non-emitting/blank C++ unless a real caller or pointer route appears.
```

If supervisor also wants sibling parity later, [UID:0003WF] should receive the same wording with address `0x00550f80`, sibling class [UID:000080], and positive controls `0x00550f90`/`0x00550fa0`.

## Validator Commands For Implementation Callback

Run from `source-3/project-documentation` after any accepted doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0003WA-MenuQuestionItemListHasSelectableEntryNoRouteRaw-source-routing-removed.md](0003WA-MenuQuestionItemListHasSelectableEntryNoRouteRaw-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If sibling or ListPane support edits are included, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0003WA-MenuQuestionItemListHasSelectableEntryNoRouteRaw-source-routing-removed.md](0003WA-MenuQuestionItemListHasSelectableEntryNoRouteRaw-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

No autogen/rescore command is expected for [UID:0003WA] alone because there is no C++ emission.

## IDA Rename/Type/Comment Recommendations

Do not force names in IDA for [UID:0003WA] unless the database supports naming no-function code islands safely. Recommended comments if later applied:

- At `0x00550e20`: `orphan raw helper: push ListPane::m_selectedIndex; GetEntryAt(index); return MenuQuestionItemEntry.optionId`.
- At `0x00550f80`: same larger-list sibling comment.
- At `0x004f3dc0`: consider alias/comment `ListPane::GetEntryAt(int index)`; note current docs alias `GetSelectedEntry` because most callers pass `m_selectedIndex`.
- At row struct notes: provisional `struct MenuQuestionItemEntry { uint8_t optionId; uint8_t unknownOrPadding; wchar_t label[]; };`.

Confidence:

- `ListPane +0x134` selected index: high.
- `0x004f3dc0` explicit-index entry accessor: high for mechanics, medium for original name.
- row byte `+0` option id/selection value: high.
- [UID:0003WA] no-owner/non-emitting: high for current binary, medium-high overall because a runtime route could still be found only by evidence outside this scan.

## Evidence Checked

- Target doc [UID:0003WA].
- Sibling docs [UID:0003W9], [UID:0003WB], [UID:0003WC], [UID:0003WE], [UID:0003WF], [UID:0003WG], [UID:0003WH].
- Class/file docs: `MenuQuestionItemList`, `MenuQuestionItemListLarger`, `MenuQuestionDialog`, `MenuQuestionDialogLarger`, `MessageDialogs`.
- Split index [UID:0001FH] `NpcMessageAndMenuQuestionDialogs`.
- Vtable data [UID:0003D6] `MenuQuestionItemListVtableData`.
- ListPane docs [UID:00007A], [UID:0000KT], [UID:000194], [UID:0003U0].
- Positive/negative route comparisons: [UID:0002JP] `MyItemListPaneGetSelectedSlotIndex`, [UID:00010Q] `ClanItemListPane`, [UID:0002G9] `ChattingColorListPaneGetSelectedColorValueRaw`.
- `by-memory/-coverage-report.md` current rows around [UID:0003WA]/[UID:0003WF].
- Read-only PE byte/disassembly/route scans against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Open Questions Closed Or Left Explicit

- Is [UID:0003WA] the live confirm-button selectability test? No. Updaters call `0x004f3e20`; [UID:0003WA] returns selected row byte `+0`.
- Is `[ecx+0x134]` a child pointer? No. It is inherited `ListPane::m_selectedIndex`; owner/paired pointer is `+0x14c`.
- Should `sub_4F3DC0` remain an unresolved raw name? No. Best current source name is explicit-index `ListPane::GetEntryAt(int index)` / `GetItemData(int index)`, with `GetSelectedEntry` retained as an alias until broader docs are cleaned.
- Is this compiler-generated glue? No high-probability. It is source-shaped UI helper logic duplicated across list subclasses. It is nevertheless no-route retained/orphaned code for this target.
- Should first-draft C++ be emitted? No, because there is no owner/emitter route and target remains `RECONSTRUCTABLE:FALSE`.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003WA","source_path":"executed-b-agent-research/B002/0003WA-MenuQuestionItemListHasSelectableEntryNoRouteRaw-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
