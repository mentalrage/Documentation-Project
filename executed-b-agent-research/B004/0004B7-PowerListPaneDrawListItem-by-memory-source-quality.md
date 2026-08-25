** TARGET-REPORT-UID:0004B7 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# Source-quality report: UID 0004B7

Target: `by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md`  
Assignment: `B004-report-0004B7-PowerListPaneDrawListItem-by-memory-20260702`  
Mode: report-only research; no target/support/generated/coverage/tool-state edits.

## Current target state

- Target header currently records `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000AQ`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- The target is already an exact split child of [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md), with source placement through [UID:0000AQ][PowerListPane](by-class/PowerListPane.md) into [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md).
- The current no-code rationale says formal C++ is pending final renderer/text helper declarations. This pass treats that as the assigned blocker, not as a final reason to stay blank.
- Current generated `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp` header is `validator-command-id: 000000004200`, `validator-refreshed-at: 2026-07-02T04:34:58-04:00`. It contains `PowerEntryRecord` and the formal constructor from UID0001F5, but no UID0004B7 marker/body; [UID:0000AQ][PowerListPane](by-class/PowerListPane.md) appears only as an Empty Emitter Marker.

## Evidence checked

### Existing-report searches

Searched current reports and executed reports with the required terms:

- `0004B7`
- `0x0054b220`
- `0x0054b34b`
- `PowerListPaneDrawListItem`
- `PowerListPane::DrawListItem`
- `PowerListPane`
- `PowerEntryRecord`
- `FillColorRect`
- `displayColor`
- `PowerDialogPane-empty-emitter`

Relevant matches opened or used:

- `executed-b-agent-research/B002/0001F6-PowerDialogPane-empty-emitter-source-quality.md`
  - Created UID0004B7 as an exact child.
  - Recorded `0x0054b220` as `sub_54B220`, size `0x12b`.
  - Left this child blank only because the broad split callback was not the child-specific source-quality pass.
- `executed-b-agent-research/B003/0001F5-PowerDialogPaneConstructor-empty-emitter-source-quality.md`
  - Formalized `PowerEntryRecord` as the constructor/list row layout: 528 bytes / `0x210` (Verified with `int_convert.py`), `entryId +0x000`, padded `listColumn +0x004`, `amount +0x008`, `label[256] +0x00c`, and `displayColor +0x20c` / decimal `524` (Verified with `int_convert.py`).
  - Established `PowerListPane` as a feature-private class in `PowerDialogPane.cpp` and accepted source-facing helper names such as `AddEntry`, `Sort`, `ComparePowerEntries`, and `PowerEntryRecord`.
- `tools/leaser/Agents/Agent-B006/goal.md`
  - Shows parallel current research is assigned for UID0004B6 `PowerListPane::OnMouseEvent`; this report does not depend on that result and does not edit shared docs.

### Target and support docs checked

- `by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md`
- `by-class/PowerListPane.md`
- `by-file/PowerDialogPane.md`
- `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md`
- `by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md`
- `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md`
- `by-class/ListPane.md`
- `by-memory/0x006221f0-0x006222b4.PowerListPaneVtableData.md`
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- generated `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp`
- generated tracker/coverage rows for UID0004B7

### IDA MCP evidence

IDA MCP was available and used through JSON-RPC after `initialize` and `tools/list`.

- Active session: `supervisor_resume_20260629`
- Active database: `NexusTK.exe.i64`
- `server_health`: `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, strings cache ready.
- MCP tools used narrowly: `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`.
- Local numeric conversions were verified with `tools/int_convert.py` for `528`, `0x20c`, `0x88`, `0x8f`, and `0x25`.

## Positive evidence

### Exact range and vtable reachability

MCP `lookup_funcs`:

- `0x0054b220` resolves to `sub_54B220`, size `0x12b`.
- `0x0054b34b` is not a function start.
- `0x0054b350` resolves to `sub_54B350`, size `0x1a0`.
- `0x0054b210` is not a function start.

MCP `get_bytes`:

- `0x0054b34b-0x0054b350` is five `0xcc` padding bytes before UID0004B8.
- `0x00622274` contains bytes `20 b2 54 00`, the little-endian vtable pointer to `0x0054b220`.

MCP `xrefs_to`:

- `0x0054b220` has one data xref at `0x00622274`.
- `0x0054b350` has one code xref at `0x0054b2d7` inside this target.

`by-memory/0x006221f0-0x006222b4.PowerListPaneVtableData.md` records `0x00622274` in the PowerListPane primary vtable region. This is normal virtual draw-item reachability, not dead/no-route evidence.

### Current decompilation

MCP `decompile 0x0054b220`:

```cpp
void __thiscall sub_54B220(int this, int a2, int a3, __int128 *a4)
{
  *(_BYTE *)(this + 136) = 1;
  if ( sub_4F3F00((_DWORD **)this, a2) )
  {
    sub_4B9660((_DWORD *)this, 143);
    sub_4BA450(this, a4);
  }
  v5 = *(_DWORD *)(a3 + 524);
  v10 = (v5 + 4) / 256;
  ...
  if ( v10 )
    sub_54B350(this, &v11, v10, v5 % 256);
  else
  {
    sub_4B9660((_DWORD *)this, v5);
    unk_69B3FC(this, &v11);
  }
  sub_4B9680((_DWORD *)this, 37);
  v7 = sub_4BAA70((__int16 *)this, (const unsigned __int16 *)(a3 + 12));
  sub_4B9600((_DWORD *)this, *((_DWORD *)a4 + 2) - v7,
             (*((_DWORD *)a4 + 1) + *((_DWORD *)a4 + 3)) / 2 + 6);
  ...
  sub_4BAB70(this, a3 + 12, ((int)v8 - a3 - 14) >> 1);
}
```

Key body facts:

- The function writes inherited byte `this+0x88` / decimal `136` (Verified with `int_convert.py`) to `1` before drawing.
- It checks row selection through `ListPane::IsItemSelected` at `0x004f3f00`; [UID:00007A][ListPane](by-class/ListPane.md) already owns that helper.
- Selected rows set draw color `143` / `0x8f` (Verified with `int_convert.py`) and call `0x004ba450`, documented as `GrafPortDrawRectFrame`.
- The row pointer argument is a `PowerEntryRecord *`; the body reads `displayColor` at `row+0x20c` / decimal `524` and the UTF-16 label at `row+0x0c`.
- The swatch rectangle is local stack rect `{ left + 5, top + 1, left + 15, bottom - 1 }`.
- If `(displayColor + 4) / 256` is nonzero, it calls UID0004B8 at `0x0054b2d7` with the swatch rect, palette page, and low color byte.
- If the page value is zero, it sets draw color to the raw display color and dispatches the shared surface fill callback `0x0069b3fc` over the swatch rect.
- It sets text color `37` / `0x25` (Verified with `int_convert.py`), measures the UTF-16 label with `0x004baa70`, moves the draw position to `rowBounds->right - textWidth` and vertical midpoint `((top + bottom) / 2) + 6`, scans the UTF-16 NUL-terminated label, and draws it with `0x004bab70`.

### Callees and helper ownership

MCP `callees` for `0x0054b220` reports:

- `0x004f3f00`: [UID:00007A][ListPane](by-class/ListPane.md) `IsItemSelected`.
- `0x004b9660`: `GrafPort::SetDrawColor` / draw-color setter family.
- `0x004ba450`: [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md).
- `0x0069b3fc`: [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot 7, shared fill/invalidation/presentation callback.
- `0x0054b350`: [UID:0004B8][PowerListPaneFillColorRect](by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md), sole direct caller is this target.
- `0x004b9680`: accepted GrafPort text/background color setter family; at this call site it is the text color setup before measuring/drawing text.
- `0x004baa70`: accepted GrafPort UTF-16 text width helper.
- `0x004b9600`: accepted GrafPort `MoveTo`.
- `0x004bab70`: accepted GrafPort wide-text drawing helper.
- `@__security_check_cookie@4`: compiler stack-cookie epilogue, not source behavior.

UID0004B8 remains a separate exact child. The target should call it as `FillColorRect(...)`; it should not inline the fill implementation.

## Negative evidence and rejected alternatives

### No-code / non-emitting rejected

The blank-emitter state is now a stale staging artifact from the broad UID0001F6 split. Current MCP proves this is a real source-authored virtual row-draw method:

- It has an exact function object at `0x0054b220`, size `0x12b`.
- It is reached from the PowerListPane primary vtable slot `0x00622274`.
- It performs semantic row rendering: selection frame, swatch fill, and right-aligned label text.
- It reads the constructor-accepted `PowerEntryRecord` fields.
- It has a single local helper callee UID0004B8 for swatch fill.

### Direct file or aggregate ownership rejected

[UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md) is the correct source file route, and [UID:0001F6][PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md) is the correct containing range, but neither is the direct semantic owner. The vtable slot, row-draw role, inherited `ListPane` method shape, and sibling list methods all point to [UID:0000AQ][PowerListPane](by-class/PowerListPane.md).

### ListPane ownership rejected

The method uses reusable `ListPane` helpers, but it is not generic list-control code. The row layout is `PowerEntryRecord`, the swatch logic uses power `displayColor`, and the class/file docs tie this list to the power dialog. Generic [UID:00007A][ListPane](by-class/ListPane.md) owns `IsItemSelected` and the virtual dispatch framework, not this override body.

### FillColorRect merge rejected

UID0004B8 is a separate function at `0x0054b350`, size `0x1a0`, and this target has the only direct code xref to it at `0x0054b2d7`. The source should keep `PowerListPane::DrawListItem` and `PowerListPane::FillColorRect` as separate methods, matching the binary call edge. The target C++ may call `FillColorRect`; UID0004B8 needs its own later source-quality pass for the full clipping/palette fill body.

### Raw renderer/text helper uncertainty no longer blocks this target

The assigned blocker is resolved enough for target-level code:

- Shared draw/text helpers already have accepted project-wide roles (`SetDrawColor`, `DrawRectFrame`, `SetTextColor`, `GetTextWidth`, `MoveTo`, `DrawWideText`).
- The render callback `0x0069b3fc` is documented as shared Surface/GrafPort fill/invalidation infrastructure and is only needed for the zero-page swatch fill branch.
- The target's exact behavior can be expressed using established helper names without inventing a new low-level renderer API.
- Remaining exact original helper spellings are confidence caveats, not a reason to leave UID0004B7 non-emitting.

## Heuristic / inference reanalysis and validation

The best source-facing signature is:

```cpp
void PowerListPane::DrawListItem(int rowIndex,
                                 const PowerEntryRecord *entry,
                                 const RectBounds *rowBounds)
```

Reasoning:

- The function is a `thiscall` virtual with three explicit arguments and `retn 0Ch`, matching the `ListPane` row-draw virtual pattern.
- The first explicit argument is passed to `ListPane::IsItemSelected`, so it is the row/item index.
- The second explicit argument is dereferenced at `+0x20c` and `+0x0c`, matching `PowerEntryRecord::displayColor` and `PowerEntryRecord::label`.
- The third explicit argument is a four-int rectangle: `left`, `top`, `right`, `bottom`.
- Existing vtable data gives the class route and the constructor report gives the row type.

Recommended source-facing helper names:

| Binary fact | Recommended source name | Confidence |
| --- | --- | --- |
| `a2` into `0x004f3f00` | `rowIndex`; `IsItemSelected(rowIndex)` | High; ListPane docs own helper role. |
| `a3 + 0x20c` | `entry->displayColor` | High; constructor and class docs agree. |
| `a3 + 0x0c` | `entry->label` | High; constructor and class docs agree. |
| `a4` | `rowBounds` / `const RectBounds *` | High; four-int rect use and GrafPort calls. |
| `this+0x88 = 1` | inherited draw/text mode enable field | Medium-high; exact field write is proven, final inherited field spelling remains inferred. |
| `0x0054b350` | `FillColorRect` | High; target and support docs already name the child this way. |
| `0x0069b3fc` branch | `FillRect(&swatchBounds)` or equivalent shared fill callback | Medium-high; project docs reject stale `g_pfnLockSurface` naming and use fill/presentation wording. |

The exact body includes a slightly unusual `(displayColor + 4) / 256` split. Current power constructor encodes colors as `52 + 8 * threshold`, so ordinary values likely stay in page zero, but the binary supports nonzero palette pages. The formal C++ should preserve that branch instead of simplifying to a single direct fill.

## Owner and source placement disposition

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000AQ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000AQ`
- `EMITTER_POSITION_OPTIONAL:` blank

Recommended source route:

`[UID:0004B7] -> [UID:0000AQ][PowerListPane] -> [UID:0000MO][PowerDialogPane] -> NexusTK/ui/dialogs/PowerDialogPane.cpp`

Support requirement: [UID:0000AQ][PowerListPane](by-class/PowerListPane.md) should stop being only an Empty Emitter Marker and should carry a private class declaration shell with `[[CHILDREN]]` so UID0004B7 and later sibling methods can emit through it.

## Formal C++ recommendation

Recommended exact target `RECONSTRUCTION_CPP CODE` insertion:

```cpp
void PowerListPane::DrawListItem(int rowIndex,
                                 const PowerEntryRecord *entry,
                                 const RectBounds *rowBounds)
{
    m_textDrawEnabled = true;

    if (IsItemSelected(rowIndex)) {
        SetDrawColor(143);
        DrawRectFrame(rowBounds);
    }

    const int displayColor = entry->displayColor;
    const int palettePage = (displayColor + 4) / 256;
    RectBounds swatchBounds = MakeRect(rowBounds->left + 5,
                                       rowBounds->top + 1,
                                       rowBounds->left + 15,
                                       rowBounds->bottom - 1);

    if (palettePage != 0) {
        FillColorRect(&swatchBounds, palettePage, displayColor % 256);
    } else {
        SetDrawColor(displayColor);
        FillRect(&swatchBounds);
    }

    SetTextColor(37);
    const wchar_t *label = entry->label;
    const int labelWidth = GetTextWidth(label);
    MoveTo(rowBounds->right - labelWidth,
           ((rowBounds->top + rowBounds->bottom) / 2) + 6);
    DrawWideText(label, wcslen(label));
}
```

Notes for supervisor review:

- `m_textDrawEnabled` is the recommended source-facing name for the exact inherited byte write at `this+0x88`. If the project has a standardized inherited GrafPort/Pane field name for this byte, use that standardized spelling during implementation.
- `FillRect(&swatchBounds)` is the source-facing call for the proven zero-page branch `SetDrawColor(displayColor); dword_69B3FC(this, &swatchBounds)`. If the project standardizes a more precise helper such as `FillColorRectDirect` or `FillCurrentColorRect`, use the established helper name but keep the same behavior.
- The C++ intentionally calls UID0004B8 `FillColorRect` instead of inlining the palette conversion and clipped 16-bit fill loops.
- `wcslen(label)` is the source-level spelling for the target's explicit UTF-16 NUL scan before `DrawWideText`.

No-code disposition: rejected for UID0004B7.

## Recommended target/support doc changes

### Target doc

File: `by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md`

Apply:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000AQ`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:0000AQ`.
- Insert the formal C++ body above.
- Update `Item Summary` and prose to say blank-emitter/no-code is rejected after B004 current MCP evidence.
- Add evidence for:
  - exact `0x12b` range;
  - vtable data xref `0x00622274 -> 0x0054b220`;
  - five-byte successor padding `0x0054b34b-0x0054b350`;
  - `this+0x88` draw/text mode byte;
  - `ListPane::IsItemSelected(rowIndex)`;
  - selected frame color `143` and `DrawRectFrame`;
  - `PowerEntryRecord::displayColor +0x20c`;
  - swatch bounds `{left+5, top+1, left+15, bottom-1}`;
  - direct zero-page fill branch through `0x0069b3fc`;
  - UID0004B8 call at `0x0054b2d7` for nonzero palette page;
  - text color `37`, label at `+0x0c`, width measurement, right-aligned `MoveTo`, UTF-16 length scan, and `DrawWideText`.

### Class support doc

File: `by-class/PowerListPane.md`

Apply:

- Add a formal private class shell with `[[CHILDREN]]` if not already present by callback time. Minimal source shape should include:
  - `class PowerListPane : public ListPane`;
  - `virtual void DrawListItem(int rowIndex, const PowerEntryRecord *entry, const RectBounds *rowBounds);`
  - `void FillColorRect(const RectBounds *bounds, int palettePage, int colorIndex);`
  - the already-documented destructor/mouse/fill/scalar roles as method notes, but do not emit compiler wrappers as handwritten source.
- Update the UID0004B7 method row to `88/91`, emitting formal C++.
- Update evidence to record `0x00622274 -> 0x0054b220`, target C++ route, helper names, row swatch geometry, and rejected no-code/renderer-blocker disposition.
- No class score change is strictly required by this report, but a small class completion increase may be justified if the class shell is added.

### File support doc

File: `by-file/PowerDialogPane.md`

Apply:

- In Proposed Contents / generated split notes, change UID0004B7 from a blank private `PowerListPane` child to an accepted emitting `PowerListPane::DrawListItem` child routed through [UID:0000AQ].
- Preserve that `PowerListPane` remains feature-private in `PowerDialogPane.cpp`; do not split it to a standalone file.
- Record generated expectation: after target/class validation, `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp` should contain UID0004B7 and `PowerListPane::DrawListItem`, and should not contain a UID0004B7 empty/non-emitting marker.

### Aggregate support doc

File: `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md`

Apply:

- Update the UID0004B7 covered-range row and source-module partition row from blank-emitter to formal emitting child `88/91`.
- Preserve this aggregate as `RECONSTRUCTABLE:FALSE` and blank C++; do not paste child C++ into the aggregate.
- Record exact MCP proof: `0x0054b220` size `0x12b`, vtable data xref `0x00622274`, UID0004B8 call at `0x0054b2d7`, displayColor/label offsets, and successor padding before UID0004B8.

### Already sufficient or no edit required

- `by-memory/0x00549c20-0x0054a472.PowerDialogPaneConstructor.md` already formalizes `PowerEntryRecord` and the 528-byte row layout.
- `by-class/ListPane.md` already owns `IsItemSelected` and reusable list-control roles.
- `by-memory/0x006221f0-0x006222b4.PowerListPaneVtableData.md` already records the PowerListPane vtable family; it may receive a support note only if the supervisor wants the exact UID0004B7 slot incorporated there.
- `by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md` remains blank-emitter pending its own child-specific report; no edit is required for UID0004B7 beyond caller evidence unless the supervisor wants a caller note.

## Expected validators after implementation callback

Run after accepted by-* edits, not during this report-only pass:

> Executable block R001 was removed from this report and preserved verbatim in [0004B7-PowerListPaneDrawListItem-by-memory-source-quality-removed.md](0004B7-PowerListPaneDrawListItem-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated freshness check after validation:

- Inspect `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp`.
- Confirm generated header command/timestamp is equal to or newer than the final scoped validator command.
- Confirm UID0004B7 and `PowerListPane::DrawListItem` are present.
- Confirm there is no UID0004B7 empty/non-emitting marker.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Incorporation target | Verification state |
| --- | --- | --- | --- | --- |
| B7-001 | Current UID0004B7 is `84/88`, owner `0000AQ`, reconstructable, blank emitter/body. | Target header reviewed. | Target metadata and Changes history. | applied - target header now records `88/91`, owner `0000AQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AQ`, blank position, formal C++; target Changes records the callback raise from the former blank-emitter state. |
| B7-002 | IDA MCP was available and healthy for this pass. | `idb_list`; `server_health status: ok`, Hex-Rays ready. | Report evidence basis; target evidence can cite B004 current MCP proof. | already-present - report `Evidence checked` preserves the MCP health/session proof; target/class/file/aggregate cite B004 MCP evidence rather than inventing fallback evidence. |
| B7-003 | Target range is exact `0x0054b220-0x0054b34b`, size `0x12b`. | MCP `lookup_funcs`. | Target evidence and aggregate row. | applied - target Evidence records `lookup_funcs 0x0054b220` size `0x12b`; aggregate Covered Range and Changes rows record the exact `88/91` child. |
| B7-004 | Successor padding before UID0004B8 is five `0xcc` bytes. | MCP `get_bytes 0x0054b34b`. | Target evidence and aggregate row. | applied - target Evidence now records `0x0054b34b-0x0054b350` as five `0xcc` bytes; aggregate B004 evidence/Changes records the same padding before UID0004B8. |
| B7-005 | Target is vtable-reached through PowerListPane slot `0x00622274 -> 0x0054b220`. | MCP `xrefs_to`; MCP `get_bytes`; PowerListPane vtable data doc. | Target/class/aggregate evidence. | applied - target Evidence, class Evidence Notes, file Evidence Notes, and aggregate IDA MCP Evidence all record slot `0x00622274 -> 0x0054b220`. |
| B7-006 | First explicit argument is row index. | Passed to `0x004f3f00`; ListPane doc owns `IsItemSelected`. | Formal C++ signature and target behavior. | applied - formal C++ signature uses `int rowIndex`; target Behavior/Evidence records `IsItemSelected(rowIndex)`. |
| B7-007 | Second explicit argument is `const PowerEntryRecord *entry`. | Reads `+0x20c` displayColor and `+0x0c` label; constructor report formalizes row layout. | Formal C++ signature and target/class evidence. | applied - formal C++ signature uses `const PowerEntryRecord *entry`; target/class/file/aggregate record `displayColor +0x20c` and `label +0x0c`. |
| B7-008 | Third explicit argument is row bounds rectangle. | Four dword rect reads create swatch bounds and text position. | Formal C++ signature and target evidence. | applied - formal C++ signature uses `const RectBounds *rowBounds`; target Behavior/Evidence records frame, swatch, and text coordinate use. |
| B7-009 | Target writes inherited byte `this+0x88` to `1`. | MCP decompile/disasm; `0x88` decimal 136 verified with `int_convert.py`. | Target C++ and evidence; class caveat for final field spelling. | applied - target C++ uses `m_textDrawEnabled = true`; target Evidence records exact `this+0x88` / decimal `136` write and field-spelling caveat. |
| B7-010 | Selected rows draw a frame using color `143` and `DrawRectFrame`. | MCP disasm/decompile calls `0x004b9660(143)` and `0x004ba450`. | Target C++ and support notes. | applied - target C++/Behavior/Evidence record `SetDrawColor(143)` and `DrawRectFrame(rowBounds)`; class/file/aggregate support notes preserve selected-frame evidence. |
| B7-011 | Swatch rectangle is `{left+5, top+1, left+15, bottom-1}`. | MCP decompile/disasm stack rect construction. | Target C++ and evidence. | applied - formal C++ constructs `swatchBounds` from those four offsets; target/class/file/aggregate evidence records the geometry. |
| B7-012 | `displayColor` controls direct fill vs UID0004B8 palette-page fill. | MCP branch on `(displayColor + 4) / 256`, zero branch uses `0x0069b3fc`, nonzero branch calls `0x0054b350`. | Target C++ and UID0004B8 caller evidence. | applied - target C++ preserves `(displayColor + 4) / 256`, UID0004B8 call, and zero-page `FillRect`; target and aggregate evidence record `0x0069b3fc` and `0x0054b2d7`. |
| B7-013 | UID0004B8 is separate and should not be inlined. | MCP `xrefs_to 0x0054b350` only from this target; `lookup_funcs` size `0x1a0`. | Target reconstruction notes; support docs. | applied - target C++ calls `FillColorRect` rather than inlining; target/class/file/aggregate notes keep UID0004B8 as a separate helper and leave its page unedited. |
| B7-014 | Text is color `37`, right-aligned to `rowBounds->right - GetTextWidth(label)`, and vertically placed at midpoint plus 6. | MCP disasm/decompile `0x004b9680(37)`, `0x004baa70`, `0x004b9600`. | Formal C++ and evidence. | applied - formal C++ and target/class/file/aggregate evidence record `SetTextColor(37)`, `GetTextWidth`, right alignment, and midpoint `+ 6`. |
| B7-015 | The label is a NUL-terminated UTF-16 string at `entry+0x0c`, drawn with explicit length. | MCP UTF-16 scan loop and `0x004bab70`; constructor row layout. | Formal C++ and target/class notes. | applied - formal C++ uses `const wchar_t *label = entry->label` and `DrawWideText(label, wcslen(label))`; target/class/file/aggregate notes record label `+0x0c` and explicit UTF-16 length scan. |
| B7-016 | No-code/non-emitting is rejected. | Exact semantic body, vtable slot, formal row layout, helper names resolved enough. | Set target `EMITTER_UIDS:0000AQ` and insert C++. | applied - target header has `EMITTER_UIDS:0000AQ` and formal C++; target/class/file/aggregate Changes record no-code/blank-emitter rejection. |
| B7-017 | Class support must provide a PowerListPane declaration shell with `[[CHILDREN]]` or equivalent generated route. | Current generated output shows PowerListPane Empty Emitter Marker only. | `by-class/PowerListPane.md`; generated expectation. | already-present - by-class/PowerListPane.md contains the private class shell with `OnMouseEvent`, `DrawListItem`, `FillColorRect`, and `[[CHILDREN]]`; validator `000000004225` passed. |
| B7-018 | File route remains `PowerDialogPane.cpp`. | by-file/source-module docs and feature-private list evidence. | File support doc and target source route. | applied - by-file/PowerDialogPane.md routes UID0004B7 through [UID:0000AQ] into `NexusTK/ui/dialogs/PowerDialogPane.cpp`; generated `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp` header is current for validator `000000004227` and contains UID0004B7. |

## Implementation Tracking Checklist

- [x] applied - Updated target `by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md`: metadata is `88/91`, `EMITTER_UIDS:0000AQ`, formal C++ body is present, evidence now includes exact range, five-byte successor padding, vtable slot, `this+0x88`, row fields, swatch/text behavior, UID0004B8 separation, zero-page callback `0x0069b3fc`, rejected no-code, score rationale, and generated-output expectation.
- [x] already-present - `by-class/PowerListPane.md` already contained the private class shell with `[[CHILDREN]]`, UID0004B7 method row at `88/91`, vtable slot/evidence, row geometry, helper mapping, and no-code rejection; validator `000000004225` confirmed the file.
- [x] already-present - `by-file/PowerDialogPane.md` already marked UID0004B7 as an emitting private `PowerListPane::DrawListItem` child routed through [UID:0000AQ] into `NexusTK/ui/dialogs/PowerDialogPane.cpp`, including proposed contents, generated split, evidence, migration note, and Changes proof; validator `000000004226` confirmed the file.
- [x] applied - Updated `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md`: UID0004B7 covered-range/source-partition rows now show formal emitting child `88/91`, aggregate remains `RECONSTRUCTABLE:FALSE` with blank emitter/C++, and B004 evidence/Changes record range, vtable, padding, row fields, swatch/text behavior, and no-code rejection.
- [x] excluded-with-reason - Left `by-memory/0x0054b350-0x0054b4f0.PowerListPaneFillColorRect.md`, `by-class/ListPane.md`, constructor row-layout docs, and PowerListPane vtable data unedited. Reason: no direct contradiction was found; current docs already provide UID0004B8 separation, `IsItemSelected`, `PowerEntryRecord` row layout, and vtable slot support needed for UID0004B7, and the callback explicitly excluded those support items unless contradiction existed.
- [x] applied - Ran scoped validators from `source-3/project-documentation` with `--wait-generated`:
  - `python .\tools\validator.py --mode file --file by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md --apply --wait-generated --queue-timeout 240` -> command_id `000000004224`, timestamp `2026-07-02T05:16:49-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000004224`.
  - `python .\tools\validator.py --mode file --file by-class/PowerListPane.md --apply --wait-generated --queue-timeout 240` -> command_id `000000004225`, timestamp `2026-07-02T05:17:06-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000004225`.
  - `python .\tools\validator.py --mode file --file by-file/PowerDialogPane.md --apply --wait-generated --queue-timeout 240` -> command_id `000000004226`, timestamp `2026-07-02T05:17:21-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000004226`.
  - `python .\tools\validator.py --mode file --file by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md --apply --wait-generated --queue-timeout 240` -> command_id `000000004227`, timestamp `2026-07-02T05:17:38-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, generated_refresh_command_id `000000004227`.
- [x] applied - Inspected generated `auto-generated/NexusTK/ui/dialogs/PowerDialogPane.cpp`: final observed header `validator-command-id: 000000004229`, `validator-refreshed-at: 2026-07-02T05:20:19-04:00`, newer than final scoped validator command `000000004227`; UID0004B7 marker appears at generated line 471 and `PowerListPane::DrawListItem` at line 472; no UID0004B7 empty/non-emitting marker is present.
- [x] applied - Lease status: stale pre-existing B004 leases were present for the four by-* files, expiring too soon; `unlease` succeeded for all four, then `lease` succeeded for all four at `2026-07-02T09:12:14Z` with expiration `2026-07-02T09:17:14Z`. Post-validator `unlease` returned `Rejected[No active lease]` for each path because the lease window had expired during the validator batch; `tools/leaser/Agents/current_leases.md` was then checked and had no active B004 lease rows.
- [x] applied - Updated this report's Claim And Incorporation Ledger and checklist with applied/already-present/excluded proof during implementation callback.

## Unresolved issues

- Exact original source spelling for inherited `this+0x88` is not symbol-proven. The report recommends `m_textDrawEnabled` for the formal body because the write precedes text/list row drawing; if a project-wide inherited GrafPort/Pane name exists by implementation time, use that standardized field name.
- Exact source helper spelling for the zero-page `0x0069b3fc` swatch fill is not recovered. The behavior is exact: after `SetDrawColor(displayColor)`, fill/present the swatch rectangle through the shared slot-7 callback. The formal body uses `FillRect(&swatchBounds)` as the source-facing name, consistent with project fill/invalidation wording.
- UID0004B8 `PowerListPane::FillColorRect` still needs its own child-specific source-quality pass before its body emits. That does not block UID0004B7, because the binary keeps the helper separate and this target can call it.
- The class-level `PowerListPane` formal declaration is still blank in current docs/generated output. This report supplies exact implementation-ready class-shell requirements for callback; until those are applied, generated output may still show the class as an Empty Emitter Marker.

## Report-only edit confirmation

This report-only pass created only:

- `tools/leaser/Agents/Agent-B004/research/0004B7-PowerListPaneDrawListItem-by-memory-source-quality.md`

No target docs, support by-* docs, generated files, coverage reports, project-level generated reports, validator/tool state, supervisor ledgers, queues, locks, archives, or IDA DB state were edited by this pass.

## Callback implementation confirmation

Implementation callback edits applied or verified accepted details in:

- `by-memory/0x0054b220-0x0054b34b.PowerListPaneDrawListItem.md`
- `by-class/PowerListPane.md`
- `by-file/PowerDialogPane.md`
- `by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md`

No manual edits were made to generated files, coverage reports, project-level generated reports, validator/tool state, archives, queues, locks, IDA DB, or by-project-structure. Scoped validators with `--wait-generated` performed the validator-owned generated refreshes recorded in the checklist above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004235","destination_path":"executed-b-agent-research/B004/0004B7-PowerListPaneDrawListItem-by-memory-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0004B7-PowerListPaneDrawListItem-by-memory-source-quality.md","timestamp":"2026-07-02T05:21:35-04:00","uid":"0004B7"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0004B7-PowerListPaneDrawListItem-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0004B7-PowerListPaneDrawListItem-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0004B7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
