** TARGET-REPORT-UID:0002G8 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002G8] ChattingColorListPaneSelectCurrentColor Source-Quality Reanalysis

Agent: B008  
Assignment: B008 report-only source-quality pass  
Target: `by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md`  
Report path: `tools/leaser/Agents/Agent-B008/research/0002G8-ChattingColorListPaneSelectCurrentColor-source-quality.md`  
Date: 2026-06-19

## Report-Only Guard

This is a research/report-only pass. No `by-*` documentation files were edited. `by-memory/-coverage-report.md` was not edited.

Current target state:

```text
UID: 0002G8
COMPLETION: 84
CONFIDENCE: 90
CANONICAL_OWNER: 00001S
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 00001S
Formal C++: blank
```

Recommended target state after an accepted implementation callback:

```text
COMPLETION: 87
CONFIDENCE: 92
CANONICAL_OWNER: 00001S
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 00001S
```

Recommended source-facing method:

```cpp
void ChattingColorListPane::SelectCurrentColor();
```

Recommended disposition: keep [UID:0002G8] as a source-authored `ChattingColorListPane` class method emitted through [UID:00001S] and current source file route [UID:0000I5] `social/Chatting.cpp`. The stale blocker saying final C++ must remain blank until a `95/95` source gate is no longer valid under the current combined score/emitter gate and the current field/helper evidence.

## Evidence Checked

Governing and workflow evidence:

- `tools/leaser/Agents/Supervisor.md`, especially the report-only B-agent workflow, temporary `by-memory/-coverage-report.md` edit ban, and source-quality Rules 23, 24, 26, 27, 29, and 30.
- `.codex/AGENTS.md`, especially the requirement that accepted B-report detail later be incorporated without arbitrary detail loss.
- `tools/leaser/Agents/Agent-B008/goal.md` and `tools/leaser/Agents/Agent-B008/notes.md`.
- `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md` as source-quality/source-placement rules and read-only source-tree guidance.

Target and support docs:

- `by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md`
- `by-memory/0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListsToCategoryRaw.md`
- `by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md`
- `by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md`
- `by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md`
- `by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md`
- `by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md`
- `by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md`
- `by-class/ChattingColorListPane.md`
- `by-class/ChattingColorPane.md`
- `by-class/ChattingColorSelectPane.md`
- `by-file/Chatting.md`
- `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
- `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`
- `by-class/ListPane.md`
- `by-file/ListPane.md`
- `by-memory/0x004f3a50-0x004f4a77.ListPane.md`
- `by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`

Prior B-agent reports checked as leads and revalidated against current evidence:

- `tools/leaser/Agents/Agent-B005/research/0002G8-ChattingColorListPaneSelectCurrentColor-source-quality.md`
- `tools/leaser/Agents/Agent-B007/research/0002G8-ChattingColorListPaneSelectCurrentColor-source-quality.md`
- `tools/leaser/Agents/Agent-B011/research/0002F9-0002G8-0002GA-0002GE-0002GF-0002GG-ChattingPaintColorMessage-source-quality.md`
- `tools/leaser/Agents/Agent-B002/research/executed/0002FX-0002GB-0002GC-chatting-color-pane-source-quality.md`
- `tools/leaser/Agents/Agent-B002/research/executed/older/0002FP-0002G9-chatting-ui-raw-helper-source-quality.md`

Current-session binary evidence:

- Local PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247E04E20B65D6414C7238AA8FF5515`
- Image base: `0x00400000`
- Relevant sections:
  - `.text`: `0x00401000`, virtual size `0x20b4ac`, raw size `0x20b600`
  - `.rdata`: `0x0060d000`, virtual size `0x5f0be`, raw size `0x5f200`
  - `.data`: `0x0066d000`, virtual size `0x2fe24`, raw size `0xd800`
- Method: PE section mapping, Capstone x86-32 disassembly, local rel32 scan, local VA/RVA dword scan, and current by-* IDA-backed docs.
- Live IDA MCP was not available in this session, so local PE facts are separated from earlier live-IDA facts already recorded in the project docs.

## Exact Range, Padding, And Function Status

Current PE bytes confirm the target half-open range is exact:

```text
0x00483206-0x00483210: cc cc cc cc cc cc cc cc cc cc
0x00483210-0x0048325b: target body, 0x4b bytes
0x0048325b-0x00483260: cc cc cc cc cc
```

The target begins after ten alignment bytes that follow [UID:0002G7] `ChattingColorListPaneConstructor` and ends before five alignment bytes preceding [UID:0002G9] `ChattingColorListPaneGetSelectedColorValueRaw`. The body has two ordinary return paths and no fall-through into the padding or adjacent raw accessor.

Disassembly:

```asm
00483210  push   esi
00483211  mov    esi, ecx
00483213  push   edi
00483214  push   0
00483216  cmp    byte ptr [esi+0x150], 0
0048321d  mov    eax, dword ptr [esi+0x14c]
00483223  mov    edi, dword ptr [esi]
00483225  mov    ecx, dword ptr [eax+0x2a8]
0048322b  je     0x00483244
0048322d  push   dword ptr [eax+ecx*4+0x278]
00483234  mov    ecx, esi
00483236  call   0x00483270
0048323b  push   eax
0048323c  mov    ecx, esi
0048323e  call   dword ptr [edi+0x78]
00483241  pop    edi
00483242  pop    esi
00483243  ret
00483244  push   dword ptr [eax+ecx*4+0x290]
0048324b  mov    ecx, esi
0048324d  call   0x00483270
00483252  push   eax
00483253  mov    ecx, esi
00483255  call   dword ptr [edi+0x78]
00483258  pop    edi
00483259  pop    esi
0048325a  ret
```

Range conclusion: no split, merge, or no-function reclassification is needed. This is a complete modeled helper method.

## Caller And Reachability Evidence

Direct rel32 references to `0x00483210` found by local PE scan:

| Address | Transfer | Source |
| ---:|---|---|
| `0x00482c8c` | `call` | [UID:0002G1] `ChattingColorPaneSyncColorListsToCategoryRaw`, first color-list pointer |
| `0x00482c98` | `jmp` | [UID:0002G1] tail transfer after loading the second color-list pointer |
| `0x00482f90` | `call` | [UID:0002G6] `ChattingColorSelectPaneOnSelectionChanged`, first color-list pointer |
| `0x00482f9b` | `call` | [UID:0002G6] second color-list pointer |

No VA or RVA dword pointer references to `0x00483210` were found. This target is not a vtable slot or data-referenced callback. It is a directly called helper reached from the raw owner-side sync helper and the modeled/vtable-owned selector selection handler.

[UID:0002G1] raw sync helper relationship:

```asm
00482c60  push   esi
00482c61  mov    esi, ecx
00482c63  mov    eax, dword ptr [esi+0x26c]
00482c69  test   eax, eax
00482c6b  je     0x00482c9d
00482c6d  mov    ecx, dword ptr [esi+0x270]
00482c73  mov    eax, dword ptr [eax+0x134]
00482c79  mov    dword ptr [esi+0x2a8], eax
00482c7f  test   ecx, ecx
00482c81  je     0x00482c9d
00482c83  cmp    dword ptr [esi+0x274], 0
00482c8a  je     0x00482c9d
00482c8c  call   0x00483210
00482c91  mov    ecx, dword ptr [esi+0x274]
00482c97  pop    esi
00482c98  jmp    0x00483210
```

[UID:0002G6] modeled selector handler relationship:

```asm
00482f5c  call   0x004f45b0
00482f61  mov    esi, dword ptr [esi+0x14c]
00482f67  mov    eax, dword ptr [esi+0x26c]
00482f71  mov    ecx, dword ptr [esi+0x270]
00482f77  mov    eax, dword ptr [eax+0x134]
00482f7d  mov    dword ptr [esi+0x2a8], eax
00482f90  call   0x00483210
00482f95  mov    ecx, dword ptr [esi+0x274]
00482f9b  call   0x00483210
```

These caller paths prove normal feature reachability. [UID:0002G1] remains a raw/no-route retained helper, but [UID:0002G6] gives an ordinary virtual UI route into this target after category selection.

## Body Behavior

The method selects the row in this color swatch list that matches the owner dialog's current category color.

Exact behavior:

1. Save `this` in `esi`.
2. Push `0` as the second argument for the later selection virtual call.
3. Read `m_isForegroundList` at `this+0x150`.
4. Read owner pointer `m_pColorPane` at `this+0x14c`.
5. Read this object's vtable pointer into `edi`.
6. Read owner selected/current category at `owner+0x2a8`.
7. If `m_isForegroundList` is nonzero, push the foreground color value from `owner+0x278 + category*4`.
8. If `m_isForegroundList` is zero, push the background color value from `owner+0x290 + category*4`.
9. Call [UID:0002GA] `0x00483270` to map the color value to a row index.
10. Push the returned row index and call this object's vtable slot `+0x78` with the already-pushed `0` flag.

The function does not write the owner color tables directly. It reads the owner table value, finds the matching row, and invokes the inherited selection-change operation. The writeback to owner tables is in [UID:0002GC] `ChattingColorListPaneOnItemSelected`.

Source-shape summary:

```cpp
void ChattingColorListPane::SelectCurrentColor()
{
    ChattingColorPane *owner = m_pColorPane;
    const int category = owner->m_selectedChatColorCategory;
    const int colorValue = m_isForegroundList
        ? owner->m_chatColorForeground[category]
        : owner->m_chatColorBackground[category];

    OnItemSelected(FindIndexByColorValue(colorValue), 0);
}
```

`OnItemSelected(row, 0)` is the most directly evidenced name in current derived-class docs for slot `+0x78`. If the ListPane API is later standardized as `SetSelectedIndex(row, false)` or `SelectItem(row, false)`, only the final call spelling should change; the target behavior and C++ eligibility do not change.

## Field, Type, Helper, And Slot Recommendations

| Address / offset | Best source-facing name | Evidence | Confidence / caveat |
| --- | --- | --- | --- |
| `0x00483210` | `ChattingColorListPane::SelectCurrentColor()` | Page title, direct callers after category changes, body selects current table color row. | Strong. Exact original symbol not externally proven, but source-facing name is best-supported. |
| `this+0x14c` | `m_pColorPane` | Constructor stores owner pointer; target reads owner fields through it; class page uses this name. | Strong. |
| `this+0x150` | `m_isForegroundList` | Constructor passes nonzero for first list and zero for second; target nonzero path reads `+0x278`; [UID:0002GC] nonzero path writes `+0x278`. | Strong. Replaces older `primary/secondary` wording. |
| `owner+0x26c` | `m_pCategorySelector` | [UID:0002G1]/[UID:0002G6] read selector pointer and selected row. | Strong support field, not directly read by target. |
| `owner+0x270` | `m_pForegroundColorList` | First list constructed with nonzero mode and refreshed first by [UID:0002G1]/[UID:0002G6]. | Strong. |
| `owner+0x274` | `m_pBackgroundColorList` | Second list constructed with zero mode and refreshed second. | Strong. |
| `owner+0x278..+0x28c` | `m_chatColorForeground[ChatColorCategory_Count]` | Target nonzero path reads it; [UID:0002GC] nonzero path writes it; constructor/config docs map first persisted byte to foreground. | Strong. |
| `owner+0x290..+0x2a4` | `m_chatColorBackground[ChatColorCategory_Count]` | Target zero path reads it; [UID:0002GC] zero path writes it; constructor/config docs map second persisted byte to background. | Strong. |
| `owner+0x2a8` | `m_selectedChatColorCategory` | [UID:0002G1]/[UID:0002G6] copy selector `+0x134` into this field before calling target; target indexes arrays with it. | Strong. |
| `0x00483270` | `ChattingColorListPane::FindIndexByColorValue(int colorValue)` | Target's only direct callee; helper loops rows and compares `ChattingColorSwatchItem::colorValue`. | Strong. |
| item `+0x04` | `ChattingColorSwatchItem::colorValue` | [UID:0002G9], [UID:0002GA], [UID:0002GB], and [UID:0002GC] all use it as color value. | Strong descriptive/source-facing name. |
| vtable slot `+0x78` | `OnItemSelected(row, notify)` / selection update slot | `ChattingColorListPane` primary vtable `0x006151a8+0x78 -> 0x00483420`; `ListPane` docs map slot to selection update. | Behavior strong. Exact public API spelling remains integration caveat. |

## Relationship To Requested Siblings

### [UID:0002G1] `ChattingColorPaneSyncColorListsToCategoryRaw`

[UID:0002G1] is an owner-side raw helper that mirrors the modeled selector handler. It reads the category selector child at owner `+0x26c`, copies selector selected row `+0x134` to owner `m_selectedChatColorCategory` at `+0x2a8`, then refreshes `m_pForegroundColorList` and `m_pBackgroundColorList` by calling or tail-jumping to this target.

It should keep its own raw/no-route C++ policy unless separately accepted because no inbound route to `0x00482c60` is proven. That no-route status does not block [UID:0002G8], because [UID:0002G8] has ordinary inbound calls from [UID:0002G6].

Support-doc impact: [UID:0002G1] should stop using `primary/secondary` as the best field wording and should name the two transfers as `ChattingColorListPane::SelectCurrentColor()` calls.

### [UID:0002G9] `ChattingColorListPaneGetSelectedColorValueRaw`

[UID:0002G9] is adjacent and validates the row-item model. It reads selected row index `this+0x134`, calls the shared item accessor, and returns item `+0x04`.

It is not a caller or callee of this target. Its no-route status remains local to [UID:0002G9] and should not be used as a blank-C++ blocker for [UID:0002G8].

Support-doc impact: add a cross-validation note that [UID:0002G9] confirms the `ChattingColorSwatchItem::colorValue` field used by [UID:0002GA] and selected by [UID:0002G8].

### [UID:0002GA] `ChattingColorListPaneFindIndexByColorValue`

[UID:0002GA] is the target's only direct internal callee:

```text
0x00483236 -> 0x00483270
0x0048324d -> 0x00483270
```

Local disassembly confirms it:

- starts row index at `0`,
- calls `0x004f3bd0` to get the row count,
- calls `0x004f3dc0` with the current row index,
- compares item `+0x04` with the requested color value,
- returns the matching row index,
- and returns `0` for empty/no-match fallback.

The target should call it as `FindIndexByColorValue(colorValue)`. If [UID:0002GA] is also implemented later, it should receive its own first-draft C++ and likely move above its current `84/90`, but [UID:0002G8]'s implementation does not need to edit [UID:0002GA] beyond support notes unless the supervisor callback says so.

### ListPane virtual slot `+0x78`

The target's final operation is:

```asm
push row
mov  ecx, this
call dword ptr [this->vtable + 0x78]
```

The `0` flag was pushed before the branch, so the slot receives `(row, 0)`. Current vtable evidence:

- `ChattingColorListPane` primary vtable base `0x006151a8`.
- `0x006151a8 + 0x78 = 0x00615220`.
- `0x00615220 -> 0x00483420`, [UID:0002GC] `ChattingColorListPaneOnItemSelected`.
- `0x006151a8 + 0x80 = 0x00615228`.
- `0x00615228 -> 0x004832c0`, [UID:0002GB] `ChattingColorListPaneDrawItem`.
- `ListPaneSelectionNavigationRawClampHelpers.md` also documents slot `+0x78` as the selection notify/update slot.

Best report wording: slot `+0x78` is the inherited selection update/change virtual. Derived pages currently use `OnItemSelected` or `OnSelectionChanged` for override bodies. Caller-side source could also be standardized later as `SetSelectedIndex(row, notify)` or `SelectItem(row, notify)`. For this target, the role is resolved enough for first-draft C++; exact original API spelling should not keep formal C++ blank.

## Heuristic / Inference Reanalysis And Validation

### Generated / Placeholder Names

Raw/generated labels checked:

- `sub_483210`: generated IDA name for the target.
- `ChattingColorListPaneSelectCurrentColor`: filename/documentation slug.
- `sub_483270`: generated IDA name for the direct find helper.
- `sub_4F45B0`: generated IDA name for the base ListPane selection update slot implementation.

Best replacements:

- `sub_483210` -> `ChattingColorListPane::SelectCurrentColor()`.
- `sub_483270` -> `ChattingColorListPane::FindIndexByColorValue(int colorValue)`.
- `sub_4F45B0` -> base `ListPane` selection update/change virtual; current derived target-side spelling should be `OnItemSelected(row, notify)` until a ListPane naming pass standardizes `SetSelectedIndex` or `SelectItem`.

Rejected route: leave `sub_` names in target behavior or C++. These names are compiler/generated placeholders and the surrounding class docs now provide better source-facing names.

### Method Name And Signature

Best name/signature:

```cpp
void ChattingColorListPane::SelectCurrentColor();
```

Evidence:

- no stack arguments are read,
- the method returns by side effect through selection dispatch,
- callers do not consume a return value,
- page title and prior reports already converge on `SelectCurrentColor`,
- caller contexts use it after category changes to synchronize row selection with owner state.

Rejected alternatives:

- `ChattingColorPane::SelectCurrentColor`: wrong receiver; owner pointer is read from `this+0x14c`.
- `ChattingColorListPane::OnItemSelected`: that name belongs to [UID:0002GC] slot body, not the helper that chooses which row to select.
- `RefreshSelectedColor`: too vague and collides with selector/list refresh wording.
- `SelectCurrentColour`: lower support; project docs use American `Color`.
- non-void return: return register is just the virtual call return and no caller uses it.

### Field Names And Table Roles

Best field model:

- `m_pColorPane` at list `+0x14c`.
- `m_isForegroundList` at list `+0x150`.
- `m_chatColorForeground` at owner `+0x278`.
- `m_chatColorBackground` at owner `+0x290`.
- `m_selectedChatColorCategory` at owner `+0x2a8`.

Evidence:

- constructor passes `1` for the first list stored at owner `+0x270` and `0` for the second list stored at owner `+0x274`;
- target nonzero mode reads `owner+0x278`;
- target zero mode reads `owner+0x290`;
- [UID:0002GC] nonzero mode writes `owner+0x278`;
- [UID:0002GC] zero mode writes `owner+0x290`;
- `ChattingColorPane` constructor/config docs map `+0x278..+0x28c` and `+0x290..+0x2a4` to foreground/background working palette IDs;
- [UID:0002G1]/[UID:0002G6] copy selector selected value into `owner+0x2a8` immediately before refreshing these lists.

Rejected alternatives:

- `m_primaryColorList` / `m_secondaryColorList` as final names: historically useful, but now superseded by foreground/background evidence.
- `m_currentColorCategory` as final name: acceptable role wording, but `m_selectedChatColorCategory` better captures that the value comes from the category selector selected row.
- treating `+0x278/+0x290` as raw byte config storage: target uses dword array entries; config byte import/save is handled by the owner constructor/button handler.

### Item Type And Color Field

Best item type/field:

```cpp
struct ChattingColorSwatchItem {
    // ...
    int colorValue; // +0x04
};
```

Evidence:

- [UID:0002GA] compares item `+0x04` to a requested color;
- [UID:0002G9] returns item `+0x04` from selected row;
- [UID:0002GB] draws swatches using item `+0x04`;
- [UID:0002GC] writes item `+0x04` into foreground/background owner arrays.

Remaining caveat: exact original struct/header spelling is not proven. `ChattingColorSwatchItem` is a strong descriptive/source-facing name and should be used consistently in draft C++ and support docs.

### ListPane Slot `+0x78`

Best role: selection update / selected-item changed virtual.

Evidence:

- target pushes row and zero flag then calls `[vtable+0x78]`;
- `ChattingColorListPane` vtable slot points to [UID:0002GC], which calls base `0x004f45b0` and writes owner color state;
- `ChattingColorSelectPane` slot at the same offset points to [UID:0002G6], which calls base `0x004f45b0` and refreshes color lists;
- [UID:0003U4] documents ListPane raw navigation code dispatching slot `+0x78` after clamping selection.

Recommended wording: use `OnItemSelected(row, 0)` in the target first draft if staying aligned with current derived-page naming. If the project performs a ListPane API naming cleanup, `SetSelectedIndex(row, false)` or `SelectItem(row, false)` is an equivalent source-facing wrapper.

Rejected alternatives:

- raw `[vtable+0x78]` in formal C++: not source-quality.
- `sub_4F45B0` in target C++: bypasses the virtual behavior and would miss derived writeback/refresh behavior.
- no-C++ blocker due exact spelling: behavior, arguments, receiver, and side effects are fully understood.

### Owner And Source Placement

Best direct owner: [UID:00001S] `ChattingColorListPane`.

Evidence:

- `ecx`/`esi` is the color-list receiver;
- method reads list-owned fields `+0x14c/+0x150`;
- method calls another color-list method [UID:0002GA];
- method dispatches this list's virtual slot `+0x78`;
- [UID:00001S] is already `86/88`, reconstructable, and attached to [UID:0000I5].

Best source file route: [UID:0000I5] `social/Chatting.cpp`.

Rejected placements:

- [UID:00001T] `ChattingColorPane`: owner supplies data, but target receiver and row-selection behavior belong to the list pane.
- [UID:00001U] `ChattingColorSelectPane`: selector triggers refresh, not owner of row lookup/selection.
- [UID:00007A]/[UID:0000KT] `ListPane`: inherited selection slot is dependency only; target is chat-color-specific.
- new `social/ChatColorDialog.cpp` as required current route: plausible future split for the color-dialog family, but current project docs and generated route are `social/Chatting.cpp`, and there is no target-level file-boundary proof requiring a move now.

### First-Draft C++ Eligibility

Eligibility is met:

- target is `RECONSTRUCTABLE:TRUE`;
- owner/emitter are nonblank and valid: [UID:00001S];
- current combined score `(84 + 90) / 2 = 87` is already above the entry gate;
- current reanalysis supports raising to `87/92`;
- exact range, padding, callers, callees, field roles, and source behavior are known;
- the only remaining caveat is exact public spelling of the inherited selection slot, not behavior or ownership.

Conclusion: first-draft C++ should be emitted during implementation. There is no no-code proof for this target.

## First-Draft C++ Recommendation

Preferred first draft, aligned to current derived-slot naming:

```cpp
void ChattingColorListPane::SelectCurrentColor()
{
    ChattingColorPane *owner = m_pColorPane;
    const int category = owner->m_selectedChatColorCategory;
    const int colorValue = m_isForegroundList
        ? owner->m_chatColorForeground[category]
        : owner->m_chatColorBackground[category];

    OnItemSelected(FindIndexByColorValue(colorValue), 0);
}
```

Acceptable alternate final line if ListPane support docs standardize a setter-style name before implementation:

```cpp
    SetSelectedIndex(FindIndexByColorValue(colorValue), false);
```

Do not emit:

```cpp
    (*(this->vtable + 0x78))(this, ...);
    sub_483270(...);
    sub_4F45B0(...);
```

Those forms preserve generated/reverse-engineering artifacts rather than plausible mid-2000s C++.

## Score And Metadata Recommendation

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:92
CANONICAL_OWNER:00001S
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001S
```

Score rationale:

- Raise completion from `84` to `87` because the prior open issues are now closed enough for implementation: source name/signature, owner pointer, mode byte, selected category field, foreground/background arrays, direct find helper, slot `+0x78` role, and first-draft C++ readiness.
- Raise confidence from `90` to `92` because the local PE recheck independently confirms exact bytes, padding, direct inbound transfer set, no target pointer refs, direct callee refs, and vtable slot support already recorded in IDA-backed docs.
- Do not raise to `95+` because exact original spelling of the ListPane selection API and possible future `ChatColorDialog.cpp` source split remain final-source polish issues.

## Exact Implementation Checklist

Apply only after supervisor acceptance. Do not edit `by-memory/-coverage-report.md`; use the supervisor-owned row below.

### Target

`by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md`

- Update metadata to `COMPLETION:87` and `CONFIDENCE:92`; keep owner/emitter unchanged.
- Add first-draft C++ from this report.
- Replace the stale "Final C++ remains blank because ... below the 95/95 source-emission gate" wording.
- Add current reanalysis evidence:
  - local PE path and MD5,
  - exact padding `0x00483206-0x00483210` and `0x0048325b-0x00483260`,
  - target disassembly summary,
  - four inbound rel32 transfers at `0x00482c8c`, `0x00482c98`, `0x00482f90`, and `0x00482f9b`,
  - no VA/RVA pointer refs to `0x00483210`,
  - direct callee refs to [UID:0002GA] at `0x00483236` and `0x0048324d`,
  - `m_pColorPane`, `m_isForegroundList`, `m_selectedChatColorCategory`, `m_chatColorForeground`, `m_chatColorBackground`, and `FindIndexByColorValue` names,
  - slot `+0x78` selection-update role and exact-spelling caveat.
- Add rejected alternatives: `ChattingColorPane` owner, `ChattingColorSelectPane` owner, `ListPane` owner, raw/no-code treatment, and stale `primary/secondary` final naming.

### Support Docs

`by-class/ChattingColorListPane.md`

- Add that [UID:0002G8] is first-draft-ready as `SelectCurrentColor()`.
- Record target status recommendation `87/92`.
- Add that `m_pColorPane +0x14c` and `m_isForegroundList +0x150` are now best-supported source-facing names.
- Add that slot `+0x78` is the inherited selection update/change virtual; current derived slot spelling is `OnItemSelected`, with `SetSelectedIndex`/`SelectItem` as possible later ListPane API naming.

`by-class/ChattingColorPane.md`

- Ensure the field model uses:
  - `+0x26c`: `m_pCategorySelector`
  - `+0x270`: `m_pForegroundColorList`
  - `+0x274`: `m_pBackgroundColorList`
  - `+0x278..+0x28c`: `m_chatColorForeground[ChatColorCategory_Count]`
  - `+0x290..+0x2a4`: `m_chatColorBackground[ChatColorCategory_Count]`
  - `+0x2a8`: `m_selectedChatColorCategory`
- Add that [UID:0002G8] refreshes row selection after the selected category changes.

`by-class/ChattingColorSelectPane.md`

- Close the stale owner/list field-name question for [UID:0002G6]: it refreshes `m_pForegroundColorList` and `m_pBackgroundColorList` through `ChattingColorListPane::SelectCurrentColor()` after copying selector selected row to `m_selectedChatColorCategory`.

`by-file/Chatting.md`

- Add that [UID:0002G8] is first-draft C++ ready under the current `social/Chatting.cpp` route.
- Preserve that `social/ChatColorDialog.cpp` remains a plausible future split, not a current blocker.

`by-memory/0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListsToCategoryRaw.md`

- Update relationship wording to `m_pForegroundColorList`/`m_pBackgroundColorList`.
- Name the two target transfers as `ChattingColorListPane::SelectCurrentColor()`.
- Keep [UID:0002G1] no-route/blank-C++ unless separately accepted.

`by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md`

- Update source-shape notes with foreground/background list names and `SelectCurrentColor()` call names.
- Leave exact inherited ListPane helper spelling as a final integration caveat only.

`by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md`

- Add that [UID:0002G9] validates [UID:0002G8]/[UID:0002GA]'s `ChattingColorSwatchItem::colorValue` model.
- State that [UID:0002G9]'s no-route status does not block [UID:0002G8].

`by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md`

- Add target relationship: [UID:0002G8] calls this helper to map foreground/background owner color values to row indices.
- Document zero fallback as selecting row `0`, not an error or `-1` sentinel.
- If implementation scope includes [UID:0002GA] code readiness, use its own accepted report/checklist for score/C++ changes rather than silently folding it into this target.

`by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md`

- Add or preserve that `item->colorValue` is the same 32-bit swatch value searched by [UID:0002GA] and selected by [UID:0002G8].

`by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md`

- Add or preserve that its writeback behavior cross-validates [UID:0002G8]'s mode byte: nonzero `m_isForegroundList` writes foreground and zero writes background.

ListPane support, if edited:

- `by-class/ListPane.md`
- `by-file/ListPane.md`
- `by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md`

Add clarification that slot `+0x78` is the selection update/change virtual. Derived docs currently use `OnItemSelected`/`OnSelectionChanged` for override bodies; caller-side source may later standardize as `SetSelectedIndex(row, notify)` or `SelectItem(row, notify)`. This is a naming-polish caveat, not a behavior blocker for [UID:0002G8].

## Exact Supervisor-Owned Coverage Row

Current row in `by-memory/-coverage-report.md` is stale at `84% : strong`. Replace it under [UID:000104] `ChattingUI` with:

```text
        - [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md) 0x00483210-0x0048325b | class method | ChattingColorListPane::SelectCurrentColor : reconstructable : 87% : very strong : B008 2026-06-19 source-quality reanalysis resolves the stale blank-C++/95-gate blocker and recommends first-draft `void ChattingColorListPane::SelectCurrentColor()`; local PE/Capstone recheck against `NexusTK.exe` MD5 `4247E04E20B65D6414C7238AA8FF5515` confirms ten-byte leading padding `0x00483206-0x00483210`, exact `0x4b` target body `0x00483210-0x0048325b`, five-byte trailing padding `0x0048325b-0x00483260`, four direct inbound transfers from [UID:0002G1] at `0x00482c8c`/`0x00482c98` and [UID:0002G6] at `0x00482f90`/`0x00482f9b`, no VA/RVA pointer refs to the target start, direct calls to [UID:0002GA] `FindIndexByColorValue` at `0x00483236`/`0x0048324d`, owner pointer `m_pColorPane` at list `+0x14c`, mode byte `m_isForegroundList` at list `+0x150`, owner selected category `m_selectedChatColorCategory` at `+0x2a8`, foreground/background color arrays `m_chatColorForeground`/`m_chatColorBackground` at `+0x278/+0x290`, and final inherited ListPane selection dispatch through vtable slot `+0x78` with notify flag `0`.
```

No `by-class/-coverage-report.md` or `by-file/-coverage-report.md` row is required unless the accepted implementation changes class/file scores.

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002G8-ChattingColorListPaneSelectCurrentColor-source-quality-removed.md](0002G8-ChattingColorListPaneSelectCurrentColor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
Exit code: 0
mode: file
scanned markdown files: 1
ok: 1
ok 0002G8 by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md UID header exists
```

The validator was run without `--apply`, so it was a dry-run scoped baseline. It did not edit by-* docs or coverage files.

## Report-Only Integrity

Created report:

```text
tools/leaser/Agents/Agent-B008/research/0002G8-ChattingColorListPaneSelectCurrentColor-source-quality.md
```

No target/support `by-*` docs were edited. `by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002G8-ChattingColorListPaneSelectCurrentColor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0002G8"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002G8-ChattingColorListPaneSelectCurrentColor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0002G8-ChattingColorListPaneSelectCurrentColor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002G8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
