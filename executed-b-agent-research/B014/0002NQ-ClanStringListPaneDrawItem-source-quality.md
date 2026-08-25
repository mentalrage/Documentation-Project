** TARGET-REPORT-UID:0002NQ **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002NQ ClanStringListPaneDrawItem Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: update [UID:0002NQ] `0x004887d0-0x004888c1.ClanStringListPaneDrawItem` to source-facing `ClanStringListPane::DrawItem`.
- Final disposition: keep as reconstructable source-authored method, canonical owner [UID:00002L] `ClanStringListPane`, emitter [UID:00002L], generated through [UID:0000I8] `Clan` / `auto-generated/NexusTK/social/Clan.cpp`.
- Required action after supervisor acceptance: target/support by-* documentation update plus first-draft C++ insertion. Do not split; do not reroute to `ClanJoinListPane`, `ClanEnlistListPane`, `ListPane`, `GrafPort`, or `Surface`.
- Score recommendation: raise target from `COMPLETION:84`, `CONFIDENCE:90` to `COMPLETION:87`, `CONFIDENCE:91`.
- C++ recommendation: populate the target's formal `RECONSTRUCTION_CPP CODE` block. The active combined-score/emitter gate is met: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002L`, and current average `(84 + 90) / 2 = 87`; the recommended score strengthens this to `89`. The old below-95/no-code wording is stale.
- Confidence: high for range, behavior, owner/emitter, vtable route, and first-draft source shape; medium-high for exact original spellings of draw-state helpers and callback typedefs.

## Target

- Target UID: `0002NQ`
- Target path: `source-3/project-documentation/by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0002NQ-ClanStringListPaneDrawItem-source-quality.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00002L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002L`, `EMITTER_POSITION_OPTIONAL:` blank, formal C++ blank.
- Current issue state: strong existing behavior/vtable evidence, but source-facing method signature, helper names, callback name, stale 95/95 no-code language, exact coverage row, and first-draft C++ recommendation still need incorporation.

## Evidence Checked

- Required instruction docs:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B014/goal.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
- Target/support docs:
  - `by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md`
  - `by-class/ClanStringListPane.md`
  - `by-class/ClanJoinListPane.md`
  - `by-class/ClanEnlistListPane.md`
  - `by-file/Clan.md`
  - `by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md`
  - `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md`
  - `by-memory/0x004f3a50-0x004f4a77.ListPane.md`
  - `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
  - `by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md`
  - `by-class/ListPane.md`
  - `by-file/ListPane.md`
  - `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
  - `by-class/EPFTileContext.md`
  - `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
  - `by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`
  - `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
  - `by-class/GrafPort.md`
  - `by-file/GrafPort.md`
  - `by-type/by-struct/RectBoundsLayout.md`
  - `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
  - `by-global/SurfaceRenderCallbackTable.md`
  - `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
  - `by-global/g_pfnLockSurface.md`
  - `by-memory/-coverage-report.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/NexusTK/social/Clan.cpp`
- Prior report lead:
  - `tools/leaser/Agents/Agent-B001/research/0002NQ-ClanStringListPaneDrawItem-source-quality.md`
  - I rechecked it as a lead only. Its conclusion is mostly correct; this B014 pass adds direct local PE/Capstone evidence because B001 recorded live IDA MCP unavailable.
- Direct binary evidence:
  - PE file: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5: `4247e04e20b65d6414c7238aa8ff5515`
  - SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
  - Image base: `0x00400000`
  - Local Capstone disassembly and PE reference scan performed by B014.
- IDA MCP status:
  - JSON-RPC `tools/list` request to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`.
  - Report confidence therefore separates local PE/Capstone facts from existing live-IDA-backed documentation evidence.
- Numeric conversions:
  - Used `tools/int_convert.py` for `0xf1 = 241`, `0x100 = 256`, `0x32 = 50`, `0x80 = 128`, `0x8f = 143`, `0x88 = 136`, `0x22c = 556`, `0x28 = 40`, `0x0c = 12`, `0x7c = 124`, and `0x6c = 108`.

## Direct PE / Capstone Facts

### Boundary And Padding

- Target bytes are a complete modeled function at `0x004887d0-0x004888c1`, length `0xf1` / 241 bytes (Verified with `int_convert.py`).
- Function prologue and epilogue:
  - Starts `push ebp; mov ebp, esp; sub esp, 0x22c`.
  - Stack frame size is `0x22c` / 556 bytes (Verified with `int_convert.py`), matching the 0x28-byte EPFTileContext local plus 256-wide-character text buffer and security cookie/local state.
  - Ends with `ret 0x0c`; explicit cleanup is `0x0c` / 12 bytes (Verified with `int_convert.py`), exactly three stack arguments after `this`.
- Previous body ends before the target and padding begins at `0x004887c7`. The bytes `0x004887c7-0x004887d0` are `cc` padding.
- Post-target padding `0x004888c1-0x004888d0` is fifteen `cc` bytes before [UID:0002NR] `ClanJoinListPaneSelectedRowAction` at `0x004888d0`.
- The next function at `0x004888d0-0x004888f1` is the join-list selected-row action and is outside this target. No merge with the target is justified.

### Instruction-Level Behavior

Observed instruction sequence:

```text
0x004887ee: lea ecx, [ebp-0x22c]; call 0x00457a60
+ Initializes a local 0x28-byte EPFTileContext / frame draw context.

0x004887f9: push [ebp+8]; mov ecx, edi; call 0x004f3f00
+ Calls ListPane::IsItemSelected(rowIndex).

0x00488807-0x00488816 selected branch:
+ push 0x80; call 0x004b9660; push rowBounds; call dword ptr [0x0069b3fc].
+ Sets draw/fill color 128 and fills/invalidates the selected row rectangle through Surface callback slot 7.

0x0048881c: push 0x8f; call 0x004b9680
+ Sets primary text/foreground color 143.

0x00488828-0x00488833:
+ push 0; mov byte ptr [this+0x88], 1; call 0x004b9690.
+ Sets GrafPort text draw/background mode byte and clears secondary/back text color.

0x00488838-0x00488845:
+ wcscpy_s(localText, 0x100, rowText).

0x0048884a-0x00488874:
+ y = ((rowBounds->bottom + rowBounds->top) / 2) + 6.
+ maxPixelWidth = rowBounds->right - 0x32.
+ Calls GrafPort::FitTextAndAppendSuffix(localText, 0x100, L"...", maxPixelWidth).

0x0048887c-0x00488881:
+ MoveTo(0x32, y).

0x00488886-0x004888a9:
+ Local wcslen loop, then GrafPort::DrawWideText(localText, length).
```

The fixed constants are:

- `0x100` / 256 wide-character local buffer (Verified with `int_convert.py`).
- `0x32` / 50 pixel left text offset and reserved gutter width (Verified with `int_convert.py`).
- `0x80` / 128 selected-row fill/draw palette index (Verified with `int_convert.py`).
- `0x8f` / 143 normal text/foreground palette index (Verified with `int_convert.py`).
- `this+0x88` / byte offset 136 for GrafPort text draw/background mode (Verified with `int_convert.py`).

The local string literal at `0x0061066c` is UTF-16LE bytes `2e 00 2e 00 2e 00 00 00`, i.e. `L"..."`.

### Xrefs And Vtable Route

Local PE reference scan results:

- `0x004887d0` has exactly three absolute VA dword hits and no RVA dword hits or direct `E8/E9` rel32 call/jump hits.
- Those three hits are vtable slots:
  - `0x0061572c -> 0x004887d0`, `ClanStringListPane` primary vtable offset `+0x80`.
  - `0x006157f0 -> 0x004887d0`, `ClanJoinListPane` primary vtable offset `+0x80`.
  - `0x006158b4 -> 0x004887d0`, `ClanEnlistListPane` primary vtable offset `+0x80`.
- Adjacent vtable evidence:
  - `ClanJoinListPane` slot `0x006157ec` / `+0x7c` points to `0x004888d0`, the selected-row action.
  - `ClanJoinListPane` slot `0x006157d4` / `+0x64` points to `0x00488900`, its key/input handler.
  - `ClanEnlistListPane` slot `0x006158b0` / `+0x7c` points to `0x00488970`, its selected-row action.
  - `ClanEnlistListPane` slot `0x00615898` / `+0x64` points to `0x004889a0`, its key/input handler.
- Conclusion: the function is vtable-only code, not direct-call helper code. That is normal for a `ListPane` row-draw virtual.

### Callee / Helper Facts

Local PE direct-call/reference counts and role resolution:

| Address | Target-local role | Source-facing recommendation | Evidence / confidence |
| --- | --- | --- | --- |
| `0x00457a60` | Initializes a local 0x28-byte context. | `EPFTileContext::InitTileContext` or `EPFTileContext::Init` local setup. | Direct disasm writes mode `1`, clears pointers/stride, initializes embedded bounds through `0x004b7c50`; `EPFTileContext` docs record 337 direct callers and this exact initializer. High for EPFTileContext role; medium for exact historic method spelling. |
| `0x004f3f00` | Tests selected row. | `ListPane::IsItemSelected(rowIndex)`. | Direct disasm reads `this+0x138` selection list and returns selected flag; ListPane docs use this name. High. |
| `0x004b9660` | Sets selected-row fill/draw color to `128`. | `GrafPort::SetDrawColor` / active draw-fill color setter. | Direct disasm stores argument to `this+0x74`; `GrafPortDrawStateAccessors` documents draw/fill color state. Medium-high. |
| `0x0069b3fc` | Fills/invalidates selected row rectangle. | `g_pfnFillOrInvalidateRect` or `FillRect` wrapper via `SurfaceRenderCallbackTable` slot 7. | Global docs reject `g_pfnLockSurface` as callsite-biased; slot has 206 xrefs and selected control paint/fill uses. Medium-high for role; exact typedef/name open. |
| `0x004b9680` | Sets text foreground color to `143`. | `GrafPort::SetTextColor` / primary text color setter. | Direct disasm stores to `this+0x7c`; GrafPort text-run docs identify `+0x7c` as `m_textColor`. High for field role; medium-high for method spelling. |
| `0x004b9690` | Clears secondary/back text color to `0`. | `GrafPort::SetTextBackColor` / secondary text color setter. | Direct disasm stores to `this+0x80`; GrafPort text-run docs identify `+0x80` as `m_textBackColor`. High for role; medium for exact name. |
| `0x004ba820` | Fits/truncates text with suffix. | `GrafPort::FitTextAndAppendSuffix`. | Helper page has first-draft C++ and broad UI fan-in; target call passes local text, capacity 256, `L"..."`, and `rowBounds->right - 50`. High. |
| `0x004b9600` | Moves draw cursor to `(50, y)`. | `GrafPort::MoveTo`. | Direct disasm stores x to `this+0x6c` and y to `this+0x68`. High. |
| `0x004bab70` | Draws the fitted text. | `GrafPort::DrawWideText`. | Helper page has first-draft C++; target computes `wcslen` then calls it. High. |
| `0x005cd657` | CRT secure copy. | `wcscpy_s`. | Import/CRT behavior and decompile agree. High. |
| `0x005c772f` | Stack cookie check. | compiler-generated security cookie. | Epilogue support only, not source-authored body. High. |

Direct rel32 caller counts from the local PE scan support broad shared-helper ownership:

- `0x00457a60`: 337 direct calls.
- `0x004f3f00`: 26 direct calls.
- `0x004b9660`: 319 direct calls.
- `0x004b9680`: 258 direct calls.
- `0x004b9690`: 40 direct calls.
- `0x004ba820`: 21 direct calls.
- `0x004b9600`: 218 direct calls.
- `0x004bab70`: 188 direct calls.
- `0x0069b3fc`: 206 absolute call-through refs.

These counts reject feature-local ownership for these helpers. They are `ListPane`, `GrafPort`, `EPFTileContext`, and `SurfaceRenderCallbackTable` dependencies.

## Source-Facing Method Name And Signature

Best source-facing method:

```cpp
ClanStringListPane::DrawItem
```

Recommended target signature:

```cpp
void ClanStringListPane::DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)
```

Evidence:

- `ListPane::OnPaint` at `0x004f43e0` iterates row indexes, calls vtable slot `+0x74` to compute a row rectangle, fetches row payload from the primary list at `this+0x130`, then calls vtable slot `+0x80` with:
  - `rowIndex` in the first stack argument,
  - row payload pointer in the second stack argument,
  - row rectangle pointer in the third stack argument.
- The target reads:
  - first explicit argument only through `ListPane::IsItemSelected(rowIndex)`;
  - second explicit argument only as a UTF-16 source string for `wcscpy_s`;
  - third explicit argument as `RectBounds`, reading `top` at `+0x04`, `right` at `+0x08`, and `bottom` at `+0x0c`.
- `RectBoundsLayout.md` confirms the field order as `left`, `top`, `right`, `bottom`.
- Existing `ListPane` docs describe the `+0x80` slot as derived row drawing, and `ClanPaneListVtableData.md` places this function in that slot for all three clan string-list-like panes.

Base-virtual caveat:

- The original `ListPane` base declaration may have used a generic item payload pointer such as `void *itemData` because other derived list panes draw non-string payloads. If final class declarations require exact C++ override compatibility, the method declaration can be written as `void DrawItem(int rowIndex, const void *rowData, const RectBounds *rowBounds)` and immediately cast `rowData` to `const wchar_t *`.
- For this target by-memory page, the strongest source-quality body shape is the typed derived implementation above, because the actual row payload consumed by this method is a UTF-16 string.

Rejected method/signature alternatives:

- `ClanStringListPaneDrawItem`: documentation slug, not a plausible C++ method spelling.
- `sub_4887D0`, `virt_meth_0x4887d0`, `FUN_004887d0`: generated/raw labels only.
- `ClanJoinListPane::DrawItem` or `ClanEnlistListPane::DrawItem`: those classes reuse the same inherited/shared slot pointer; they do not own separate implementations.
- `ListPane::DrawItem`: `ListPane` owns the dispatcher and base virtual slot, but this function is class-specific row-content drawing.
- `GrafPort` or `Surface` helper: all drawing calls are dependencies on the receiver's inherited render state, not ownership of the row renderer.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported direction | Rejected alternatives / remaining caveat |
| --- | --- | --- | --- |
| Exact range and split | Local PE bytes and support docs. Target is `0x004887d0-0x004888c1`; previous `0x004887c7-0x004887d0` and next `0x004888c1-0x004888d0` are padding; `0x004888d0` is separate join action. | Keep one method page; no split/merge. | Do not merge with [UID:0002NR] or aggregate [UID:00010I]. |
| Vtable-only reachability | Local VA scan found only three dword refs: `0x0061572c`, `0x006157f0`, `0x006158b4`; no direct rel32 callers. | Virtual `DrawItem` implementation. | Direct free helper route rejected. Vtable-only is positive virtual-method evidence, not a reachability blocker. |
| Owner/emitter | ClanStringListPane vtable owns the implementation; join/enlist vtables reuse it; class and file docs place all three in `social/Clan.cpp`. | Keep `CANONICAL_OWNER:00002L`, `EMITTER_UIDS:00002L`, blank emitter position. | File-only [UID:0000I8] owner is less direct. Join/enlist ownership rejected by shared inherited implementation. |
| Method name | `ListPane::OnPaint` dispatches row drawing through slot `+0x80`; related docs already call row-draw methods `DrawItem`; prior B001 report and generated leads agree. | `ClanStringListPane::DrawItem`. | `OnPaint`, `DrawRow`, `RenderItem`, and raw generated names remain less supported. |
| Parameter names | `rowIndex` drives `IsItemSelected`; `rowText` is UTF-16 copied into local buffer; `rowBounds` supplies top/right/bottom. | Use `rowIndex`, `rowText`, `rowBounds`. | Generic `a2`, `Source`, `a4`, `param_1..3` should be evidence-only. |
| `+0x88` field | GrafPort text-run docs resolve `+0x88` as text draw/background mode; target sets it to `1`. | Document as `m_textDrawMode` / text draw-background mode byte. | Old "byte flag" wording is too vague; "dirty flag" is wrong. |
| Color helpers | `0x004b9660` stores `+0x74`, `0x004b9680` stores `+0x7c`, `0x004b9690` stores `+0x80`; GrafPort docs resolve `+0x7c/+0x80` as text/back colors. | `SetDrawColor(128)`, `SetTextColor(143)`, `SetTextBackColor(0)`. | Exact historic spellings may differ; raw `sub_*` names should not remain in source prose. |
| Selected fill callback | Slot `0x0069b3fc` has 206 refs and is documented as Surface render callback slot 7; `g_pfnLockSurface` is a stale generated alias. | Use descriptive `g_pfnFillOrInvalidateRect` / `FillRect` wording in C++ comments/prose; preserve raw slot in evidence. | Exact typedef/name remains open, so do not claim original name. |
| Local `0x00457a60` context | Direct disasm initializes 0x28 bytes before the text buffer. EPFTileContext docs identify `0x00457a60` as the initializer. Target does not subsequently read this local. | Include an initialized local `EPFTileContext drawContext; drawContext.InitTileContext();` or equivalent in first-draft C++. Mark exact reason for unused local as legacy/source-shape caveat. | Dropping it would lose a real call. Claiming it is clan-owned is wrong. Exact historic source spelling open. |
| Text fitting | Target copies into a 256-wide-char local buffer and calls `GrafPort::FitTextAndAppendSuffix(text, 256, L"...", rowBounds->right - 50)`. | Keep helper name from [UID:00016B]; no target-local helper. | Old `TextFitAndSuffixHelpers` aggregate name is support-page title, not method name. |
| Final draw | Target computes `wcslen` manually and calls `0x004bab70`; [UID:00016C] emits `GrafPort::DrawWideText`. | `DrawWideText(text, static_cast<int>(wcslen(text)))`. | Do not model as generic `DrawText` without length unless wrapper introduced outside the range. |
| Old no-code blocker | Current by-structure gate allows C++ when reconstructable, nonblank emitter route, and average score > 85. Current average already 87. | Populate first-draft C++; keep below final-audit score because helper spellings/callback typedef remain descriptive. | Old "no C++ until 95/95" language is stale. |
| Shared use by three classes | Vtable data proves all three primary vtables use the same pointer at slot `+0x80`. | Document "shared/inherited ClanStringListPane implementation reused by ClanJoinListPane and ClanEnlistListPane." | Do not duplicate code into three class pages. |
| Support-doc score impact | Target source-quality improves; support docs already mostly encode route. | Target score `87/91`; optionally raise `ClanStringListPane` `86/90 -> 87/90` if implementation incorporates full draw method details. Other support scores can remain unchanged. | No support score should be raised merely because a target child gets code. |

No unresolved issue blocks target first-draft C++. Remaining uncertainties are exact historic spellings for helper methods, callback typedef/global name, and whether the base `ListPane` declaration used `void *` for row data. These cap the score below final-source levels but do not affect behavior, owner/emitter, range, or C++ readiness.

## First-Draft C++ Recommendation

Recommended formal C++ for the target:

```cpp
void ClanStringListPane::DrawItem(int rowIndex,
                                  const wchar_t *rowText,
                                  const RectBounds *rowBounds)
{
    EPFTileContext drawContext;
    wchar_t text[256];

    drawContext.InitTileContext();

    if (IsItemSelected(rowIndex)) {
        SetDrawColor(128);
        g_pfnFillOrInvalidateRect(this, rowBounds);
    }

    SetTextColor(143);
    m_textDrawMode = 1;
    SetTextBackColor(0);

    wcscpy_s(text, _countof(text), rowText);

    const int y = ((rowBounds->top + rowBounds->bottom) / 2) + 6;
    FitTextAndAppendSuffix(text, _countof(text), L"...", rowBounds->right - 50);
    MoveTo(50, y);
    DrawWideText(text, static_cast<int>(wcslen(text)));
}
```

Implementation notes for the callback:

- If the accepted `EPFTileContext` API uses `Init()` or a free `InitTileContext(&drawContext)` helper rather than a member `InitTileContext()`, adjust that one line. Do not drop the local initialization call unless a later compiler/source-shape pass proves it is dead generated artifact outside this function's source.
- If the accepted `ListPane` base declaration uses `const void *rowData`, use this compatible variant:

```cpp
void ClanStringListPane::DrawItem(int rowIndex,
                                  const void *rowData,
                                  const RectBounds *rowBounds)
{
    const wchar_t *rowText = static_cast<const wchar_t *>(rowData);
    EPFTileContext drawContext;
    wchar_t text[256];

    drawContext.InitTileContext();

    if (IsItemSelected(rowIndex)) {
        SetDrawColor(128);
        g_pfnFillOrInvalidateRect(this, rowBounds);
    }

    SetTextColor(143);
    m_textDrawMode = 1;
    SetTextBackColor(0);

    wcscpy_s(text, _countof(text), rowText);

    const int y = ((rowBounds->top + rowBounds->bottom) / 2) + 6;
    FitTextAndAppendSuffix(text, _countof(text), L"...", rowBounds->right - 50);
    MoveTo(50, y);
    DrawWideText(text, static_cast<int>(wcslen(text)));
}
```

I recommend the typed `const wchar_t *rowText` form for this target's by-memory C++ unless a simultaneous `ListPane` declaration callback forces the generic payload signature. The typed form is clearer and matches the proven row payload consumed in this exact body.

## Ranked Ownership Analysis

### 1. `ClanStringListPane` [UID:00002L] - accepted

- Evidence for:
  - Primary vtable slot `0x0061572c` points to target at offset `+0x80`.
  - Class docs list this as the shared string-list renderer.
  - The body expects row payload as a wide string, matching `ClanStringListPane` row storage helpers [UID:00035D], [UID:00035E], and [UID:00035F].
  - Parent class and file both clear 85/85 gate.
- Evidence against:
  - Method is also reused by two derived/sibling clan list panes.
- Decision:
  - Accept. Shared reuse does not override the implementation owner. `ClanStringListPane` is the narrowest semantic owner.

### 2. `ClanJoinListPane` [UID:00002H] / `ClanEnlistListPane` [UID:00002C] - rejected as owners, keep as reuse contexts

- Evidence for:
  - Their primary vtables point to this function at slots `0x006157f0` and `0x006158b4`.
  - They are live construction/reuse contexts in `ClanStatusPane`.
- Evidence against:
  - No separate draw body exists for either class.
  - Their class-specific action and input handlers live at adjacent addresses and separate vtable slots, not here.
- Decision:
  - Document reuse; do not duplicate owner/emitter or code.

### 3. `ListPane` [UID:00007A]/[UID:0000KT] - rejected as direct owner

- Evidence for:
  - `ListPane::OnPaint` dispatches the virtual slot and defines the call shape.
  - `ListPane::IsItemSelected` is a direct dependency.
- Evidence against:
  - This body draws a clan string row, uses a wide-string payload, and belongs to a derived vtable slot.
- Decision:
  - `ListPane` is support/dispatcher evidence only.

### 4. `GrafPort` [UID:00005V]/[UID:0000JR] and `SurfaceRenderCallbackTable` [UID:0000TN] - rejected as direct owners

- Evidence for:
  - Most drawing helpers are inherited/shared `GrafPort` and render callback calls.
- Evidence against:
  - Those helpers have broad fan-in and are documented as shared render infrastructure; they do not own the clan row semantics.
- Decision:
  - Dependencies only.

### 5. File-level `Clan` [UID:0000I8] - source root, not direct canonical owner

- Evidence for:
  - `Clan.cpp` is the generated source root and feature module for this class family.
- Evidence against:
  - `ClanStringListPane` is a narrower semantic class owner and clears the gate.
- Decision:
  - Keep file route through class emitter chain; do not make the target file-owned.

## Documentation Evidence And Current Generated State

- Target doc already records most behavior, vtable-only refs, and owner route, but it still has stale "no C++ until 95/95" language.
- `ClanStringListPane.md` already owns the method but should use `DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)` and mention first-draft readiness.
- `ClanJoinListPane.md` and `ClanEnlistListPane.md` already identify the shared row renderer. They should clarify that the slot reuses `ClanStringListPane::DrawItem`; no separate C++ body is expected on those class pages.
- `ClanListPaneVirtuals.md` already lists this as a child; update the child row/status from no-code/stale source gate to first-draft-ready method child.
- `ClanPaneListVtableData.md` already proves the three slot refs; keep it no-code/generated-binary support. It should not emit handwritten vtable arrays.
- `auto-generated/-ag-memory-coverage.md` currently lists `0002NQ` as `emits` with `coded: no`, and `auto-generated/NexusTK/social/Clan.cpp` has only an empty emitter marker:

```text
// UID:0002NQ | by-memory\0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md | Completion:84 | Confidence:90 | Empty Emitter Marker
```

After accepted implementation and autogen, this row should become coded/yes and the generated source should contain the first-draft method body.

## Recommended Target Doc Changes

Target: `source-3/project-documentation/by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md`

1. Metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:00002L
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00002L
EMITTER_POSITION_OPTIONAL:
```

2. Replace source-facing name and status:
   - Use `ClanStringListPane::DrawItem`.
   - State that `ClanJoinListPane` and `ClanEnlistListPane` reuse this same function through their draw slots.
   - Preserve raw title/slug only as page identity/evidence, not source method spelling.

3. Add signature:

```cpp
void ClanStringListPane::DrawItem(int rowIndex,
                                  const wchar_t *rowText,
                                  const RectBounds *rowBounds);
```

4. Add first-draft C++ from this report.

5. Replace stale no-code gate language with:

```text
The function is first-draft C++ ready under the active reconstruction gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:00002L`, and `(COMPLETION + CONFIDENCE) / 2 > 85`. Remaining uncertainty is limited to helper spelling/callback typedef details, not range, owner, emitter route, or behavior.
```

6. Add PE/Capstone evidence:
   - local executable identity and hash;
   - exact `0xf1` / 241-byte function size (Verified with `int_convert.py`);
   - pre/post padding spans;
   - `ret 0x0c` / 12-byte cleanup (Verified with `int_convert.py`);
   - no direct rel32 callers;
   - exact vtable refs `0x0061572c`, `0x006157f0`, `0x006158b4`;
   - `0x0061066c` UTF-16 `L"..."` literal.

7. Update behavior text with source-quality names:
   - `EPFTileContext::InitTileContext` local setup at `0x00457a60`;
   - `ListPane::IsItemSelected(rowIndex)`;
   - `SetDrawColor(128)` for selected fill;
   - `SurfaceRenderCallbackTable` slot `0x0069b3fc` as fill/invalidation callback, not `g_pfnLockSurface` in source-facing text;
   - `SetTextColor(143)`;
   - `m_textDrawMode = 1`;
   - `SetTextBackColor(0)`;
   - `wchar_t text[256]`;
   - `FitTextAndAppendSuffix(text, 256, L"...", rowBounds->right - 50)`;
   - `MoveTo(50, ((top + bottom) / 2) + 6)`;
   - `DrawWideText(text, wcslen(text))`.

8. Add rejected alternatives:
   - not a free Clan helper;
   - not owned by `ClanJoinListPane`/`ClanEnlistListPane`;
   - not owned by `ListPane`, `GrafPort`, `Surface`, or the callback table;
   - not no-code under old 95/95 gate;
   - not `g_pfnLockSurface` as source-facing callback name.

## Recommended Support Doc Changes

- `by-class/ClanStringListPane.md`
  - Update method row to `DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)`.
  - Add that the target child is first-draft C++ ready and should emit through this class to `Clan.cpp`.
  - Add helper/source-quality details at report level: selected fill, `128`/`143` palette values, `m_textDrawMode`, 256-wide-character local, `L"..."` suffix, fixed x `50`, and three-vtable reuse.
  - Optional score change if edited materially: `86/90 -> 87/90`. This is justified by resolving the class's draw method source-quality blocker. Do not raise confidence above `90` because raw constructor/clear/find helper caveats remain class-level blockers.

- `by-class/ClanJoinListPane.md`
  - Clarify that the draw slot reuses `ClanStringListPane::DrawItem`; no duplicate `ClanJoinListPane::DrawItem` body should be emitted.
  - No score change required.

- `by-class/ClanEnlistListPane.md`
  - Same clarification for reuse through `0x006158b4`.
  - No score change required.

- `by-file/Clan.md`
  - In the `ClanStringListPane` and join/enlist rows, replace no-code/source-quality caveats for the shared draw child with first-draft-ready wording.
  - State that the function remains class-owned (`ClanStringListPane`) but emitted through `social/Clan.cpp`.
  - No score change required (`90/85` can stay; file confidence is capped by broader raw constructor/file-split questions).

- `by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md`
  - Update the `0002NQ` child row to say first-draft C++ ready under the active gate.
  - Keep the aggregate `RECONSTRUCTABLE:FALSE`; exact children remain source-bearing units.
  - No score change required.

- `by-memory/0x00615570-0x006158f4.ClanPaneListVtableData.md`
  - Add or update a short note that `ClanStringListPane`, `ClanJoinListPane`, and `ClanEnlistListPane` share slot `+0x80 -> 0x004887d0`, with the method body emitted by the `ClanStringListPane` child.
  - Preserve no-code/generated-binary vtable policy.
  - No score change required.

- `by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md`
  - Optional support note: `ListPane::OnPaint` dispatches row drawing through slot `+0x80` with `(rowIndex, rowPayload, rowBounds)`, supporting typed derived draw signatures.
  - No score change required unless the page receives a broader source-quality pass.

- `by-global/SurfaceRenderCallbackTable.md` and `by-global/g_pfnLockSurface.md`
  - No required target-driven score changes.
  - If touched later, use this target as one more evidence consumer for slot `0x0069b3fc` as a rectangle fill/invalidation callback and preserve rejection of `g_pfnLockSurface` as final source-facing name.

- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`, `by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`, `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`, and `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
  - No required changes; they already provide sufficient helper ownership/name evidence.
  - Optional cross-reference from helper pages to `0002NQ` is not necessary unless a broader helper fan-in cleanup is underway.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` during this report pass. Supervisor-owned replacement row:

Placement context: replace the existing `0002NQ` row under the `0x004887c7-0x004887d0` ignored padding row and before the following clan list-pane rows.

```text
        - [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) 0x004887d0-0x004888c1 | method | ClanStringListPane::DrawItem : reconstructable : 87% : very strong : B014 2026-06-19 source-quality reanalysis confirms the exact 0xf1-byte / 241-byte row renderer, `ret 0x0c` three-argument thiscall cleanup, `0x004887c7-0x004887d0` and `0x004888c1-0x004888d0` padding boundaries, vtable-only refs for ClanStringListPane/ClanJoinListPane/ClanEnlistListPane draw slot `+0x80` at `0x0061572c`, `0x006157f0`, and `0x006158b4`, no direct rel32 callers or RVA hits to the function start, inherited `ListPane` draw-call shape `(rowIndex, rowPayload, rowBounds)`, selected-row check through `ListPane::IsItemSelected`, selected fill palette `128`, text palette `143`, GrafPort text draw/background mode byte at `this+0x88`, 256-wide-character local copy, truncation through `GrafPort::FitTextAndAppendSuffix(..., L"...", rowBounds->right - 50)`, fixed text x `50`, vertical position `((top + bottom) / 2) + 6`, final `GrafPort::DrawWideText`, stable `ClanStringListPane` owner/emitter route through `Clan.cpp`, and first-draft C++ readiness under the active >85 combined-score gate.
```

Expected generated memory coverage after implementation/autogen:

- `auto-generated/-ag-memory-coverage.md` row for [UID:0002NQ] should move from `emits` / `coded no` to `coded` / `yes` once the formal C++ is populated and autogen is refreshed.

## Validator Commands For Implementation Callback

Run from `source-3/project-documentation` after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002NQ-ClanStringListPaneDrawItem-source-quality-removed.md](0002NQ-ClanStringListPaneDrawItem-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If implementation only touches the target and `ClanStringListPane.md`, run only those file validators plus autogen. If any optional support page is not edited, its validator command can be skipped.

## IDA Rename / Type / Comment Recommendations

Do not perform IDA DB edits during this report pass. Recommended if an IDA naming callback is later requested:

- Function rename:
  - `sub_4887D0` -> `ClanStringListPane__DrawItem` or `ClanStringListPane::DrawItem`.
  - Confidence: high.
- Prototype:
  - `void __thiscall ClanStringListPane::DrawItem(ClanStringListPane *this, int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds);`
  - If maintaining generic base signature in IDA, use `const void *rowData` and comment that this implementation treats it as `const wchar_t *`.
  - Confidence: high for three arguments and role; medium-high for typed payload spelling.
- Stack/local names:
  - `[ebp+8]` -> `rowIndex`
  - `[ebp+0xc]` -> `rowText`
  - `[ebp+0x10]` -> `rowBounds`
  - `[ebp-0x22c]` -> `drawContext` / `tileContext`
  - `[ebp-0x204]` -> `text[256]`
  - `esi` after `0x00488874` -> `textY`
  - Confidence: high.
- Comments:
  - At `0x004887f4`: `EPFTileContext local init; retained source local, not clan-owned helper`.
  - At `0x004887fe`: `ListPane::IsItemSelected(rowIndex)`.
  - At `0x00488816`: `SurfaceRenderCallbackTable slot 7; selected row fill/invalidate, not g_pfnLockSurface source name`.
  - At `0x00488877`: `GrafPort::FitTextAndAppendSuffix(text, 256, L"...", rowBounds->right - 50)`.
  - At `0x00488881`: `GrafPort::MoveTo(50, textY)`.
  - At `0x004888a9`: `GrafPort::DrawWideText(text, wcslen(text))`.
- Vtable data comments:
  - `0x0061572c`, `0x006157f0`, `0x006158b4`: `DrawItem slot reused by ClanStringListPane/ClanJoinListPane/ClanEnlistListPane; implementation owner ClanStringListPane`.

## Rejected Alternatives Summary

- Reject "blank C++ because below 95/95": active policy allows first-draft C++ above the >85 combined-score/emitter gate, and this target qualifies.
- Reject "blank C++ because vtable-only": vtable-only is expected for virtual row renderers and is positive source evidence here.
- Reject "make the aggregate [UID:00010I] emit the body": aggregate is correctly non-reconstructable split/index; exact child emits.
- Reject `ClanJoinListPane`/`ClanEnlistListPane` body duplication: vtables reuse the same pointer; no distinct bodies exist.
- Reject `ListPane` direct ownership: `ListPane` owns dispatch and selection helpers, not string-row content rendering.
- Reject `GrafPort`, `EPFTileContext`, or `Surface` direct ownership: these are helper/dependency owners with broad fan-in.
- Reject `g_pfnLockSurface` in final source text: support docs prove it is a callsite-biased alias for `SurfaceRenderCallbackTable` slot `0x0069b3fc`.
- Reject generic `byte flag +0x88`: support docs resolve it as GrafPort text draw/background mode.
- Reject leaving raw names (`sub_4B9660`, `sub_4B9680`, `sub_4B9690`, `sub_4BA820`, `sub_4BAB70`) in source-facing prose except as evidence aliases.

## Implementation Checklist For Callback

1. Edit target `by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md`.
2. Raise target metadata to `87/91`; keep owner/emitter/reconstructable unchanged.
3. Add the first-draft C++ block from this report.
4. Replace stale no-code/95-gate wording with active-gate readiness wording.
5. Add PE/Capstone evidence and helper name table at report-level detail.
6. Add rejected alternatives and open-question closure from this report.
7. Update `by-class/ClanStringListPane.md` method row and source-quality details; optionally raise to `87/90`.
8. Update `by-class/ClanJoinListPane.md` and `by-class/ClanEnlistListPane.md` to clarify shared draw-slot reuse, no duplicate body.
9. Update `by-file/Clan.md`, `ClanListPaneVirtuals.md`, and `ClanPaneListVtableData.md` with concise first-draft-ready/shared-slot notes.
10. Do not edit `by-memory/-coverage-report.md`; keep the exact pending replacement row above for supervisor.
11. Run scoped validators and autogen as listed.

## Validator Results For This Report Pass

- No by-* validators were run because this is report-only and no by-* docs were edited.
- Report file creation should be verified by filesystem check before FINISHED.

## Changed Files

- Created:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0002NQ-ClanStringListPaneDrawItem-source-quality.md`
- Modified:
  - none outside this report.
- Not edited:
  - target/support by-* docs;
  - generated reports;
  - IDA DB;
  - generated source;
  - project-level reports;
  - `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002NQ-ClanStringListPaneDrawItem-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0002NQ"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002NQ-ClanStringListPaneDrawItem-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0002NQ-ClanStringListPaneDrawItem-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002NQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
