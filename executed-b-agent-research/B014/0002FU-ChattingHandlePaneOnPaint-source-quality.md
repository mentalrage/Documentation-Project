** TARGET-REPORT-UID:0002FU **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B014 Report - [UID:0002FU] ChattingHandlePane::OnPaint Source Quality

Status: FINISHED_REPORT

Assignment: `B014-report-0002FU-ChattingHandlePaneOnPaint-source-quality-20260628`

Report time: `2026-06-28T21:57:31-04:00`

Required report path: `tools/leaser/Agents/Agent-B014/research/0002FU-ChattingHandlePaneOnPaint-source-quality.md`

## Scope

This is a report-only pass for [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](../../../../../by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md). I did not lease or edit by-* pages, generated reports, generated C++ files, manual coverage reports, tool state, validator state, or the IDA database. No subagents were spawned.

The current target already clears the Rule 26 C++ gate:

- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00001V`
- current score `86/90`, average `88`
- current owner [UID:00001V][ChattingHandlePane](../../../../../by-class/ChattingHandlePane.md)
- current file route [UID:0000I5][Chatting](../../../../../by-file/Chatting.md)

This report recommends formal first-draft C++ for the target.

## Current MCP State

Read-only MCP was available for this run.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active database/session used in all calls: `agent_b009_0002my_20260628`
- `server_health`: `status:"ok"`, `idb_path:"E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64"`, module `NexusTK.exe`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`
- `tools/list` exposed the read-only tools used below. The `callers` method was not exposed by this MCP instance during this run, so inbound references were checked through `analyze_function`, `xrefs_to`, and `xrefs_to` on vtable/string/global targets.

## Evidence Checked

Current documentation checked:

- Target page [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](../../../../../by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md)
- [UID:00001V][ChattingHandlePane](../../../../../by-class/ChattingHandlePane.md)
- [UID:0000I5][Chatting](../../../../../by-file/Chatting.md)
- [UID:000104][ChattingUI](../../../../../by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002FT][ChattingHandlePaneOnMouseEvent](../../../../../by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) and executed B003 report for the same field map
- [UID:0002FR][ChattingHandlePaneConstructor](../../../../../by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md)
- [UID:0002FP][ChattingHandlePaneRenderStateCompareHelperRaw](../../../../../by-memory/0x00481b60-0x00481bb9.ChattingHandlePaneRenderStateCompareHelperRaw.md)
- [UID:0002FQ][ChattingHandlePaneRenderStateSnapshotHelperRaw](../../../../../by-memory/0x00481bc0-0x00481c05.ChattingHandlePaneRenderStateSnapshotHelperRaw.md)
- [UID:0002FW][GetChatButtonRectRaw](../../../../../by-memory/0x00482310-0x00482400.GetChatButtonRectRaw.md)
- [UID:000107][GetChatButtonAtPoint](../../../../../by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md)
- [UID:0000XY][EPFTileContext](../../../../../by-memory/0x00457a60-0x00458610.EPFTileContext.md)
- [UID:0002KP][ResourceLayoutTableLookupLayoutEntry](../../../../../by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md)
- [UID:000165][SurfacePaintHelpers](../../../../../by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md)
- [UID:000162][GrafPortDrawStateAccessors](../../../../../by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:00015S][RectGeometryHelpers](../../../../../by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md)
- [UID:0000QU][g_pEPFLib](../../../../../by-global/g_pEPFLib.md) and [UID:0001OQ][0x0067a744-0x0067a748.g_pEPFLib](../../../../../by-memory/0x0067a744-0x0067a748.g_pEPFLib.md)
- [UID:00028Q][g_pConfig](../../../../../by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md)
- [UID:0003AU][ChattingStringResourceData](../../../../../by-memory/0x00615284-0x00615460.ChattingStringResourceData.md)
- Read-only generated context: `auto-generated/NexusTK/social/Chatting.cpp` only to confirm UID `0002FT` already emits `ChatHandleButtonPaintState` before UID `0002FU`'s empty marker.

Fresh MCP calls used:

- `server_health`
- `lookup_funcs` on `0x00482150`, `0x004822f6`, `0x00482300`, `0x004d02f0`, `0x004b9980`, `0x004b9670`, `0x004b7c50`, `0x00457a60`, `0x00481d60`, `0x00481c10`
- `analyze_function`, `decompile`, and `disasm` on `0x00482150`
- `xrefs_to` on `0x00482150`, `0x00615000`, `0x006153b4`, `0x006153d0`, `0x0067a744`, `0x004d02f0`, `0x004b9980`, `0x004b9670`, `0x00457a60`, `0x00482300`
- `get_bytes` for target padding, vtable bytes, `CHATBUTT` strings, and `g_pEPFLib` storage
- `get_string` for `0x006153b4` and `0x006153d0`
- `make_signature_for_range` for `0x00482150-0x004822f6`
- helper decompiles for `0x004b9980`, `0x004d02f0`, `0x004b9670`, `0x004b7c50`, and `0x00457a60`

## Current Target State

Current metadata on the target page:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00001V`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00001V`
- formal C++ block blank

Current prose already has the right target identity: `ChattingHandlePane::OnPaint`, vtable-owned, source route through `social/Chatting.cpp`, exact range `0x00482150-0x004822f6`, three `CHATBUTT.EPF` button draws, and snapshot writes at `+0x0f8..+0x10c`.

The remaining source-quality blocker was not behavior. It was finalizing source-facing field/helper names and deciding whether the current render helper vocabulary is enough for formal C++. The answer is yes.

## Fresh Binary Findings

`lookup_funcs` confirms:

- `0x00482150`: `sub_482150`, size `0x1a6`
- `0x004822f6`: not a function
- `0x00482300`: `sub_482300`, size `0xa`, successor method reached by vtable data at `0x00615004`
- `0x004d02f0`: `sub_4D02F0`, size `0xae`
- `0x004b9980`: `sub_4B9980`, size `0x31`
- `0x004b9670`: `sub_4B9670`, size `0xd`
- `0x004b7c50`: `sub_4B7C50`, size `0x1f`
- `0x00457a60`: `sub_457A60`, size `0x44`
- sibling evidence: `0x00481d60` and `0x00481c10` still resolve as the OnMouseEvent and constructor bodies.

`analyze_function 0x00482150` reports prototype `int __thiscall(int this)` only because the last snapshot field remains in `eax`; source should be `void ChattingHandlePane::OnPaint()`, matching paint-slot convention and sibling paint pages.

Direct callees:

- `0x00457a60` / `EPFTileContext::Initialize`
- `0x004b9670` / accepted `SetPaneDrawMode(0)` style wrapper for this helper family
- `0x004b7c50` / `InitRectBounds`
- `0x004d02f0` / `g_pEPFLib->LookupLayoutEntry`
- `0x004b9980` / `RenderTileFrame`
- `@__security_check_cookie@4`

Inbound evidence:

- `xrefs_to 0x00482150`: one data xref from `0x00615000`, the ChattingHandlePane virtual slot.
- `analyze_function` callers list is empty.
- No ordinary code caller was found in current MCP evidence.
- `xrefs_to 0x00482300`: one data xref from `0x00615004`, proving `0x00482300` is the next vtable method and not part of this range.

Boundary evidence:

- Target instruction count: 127.
- Return at `0x004822f5`; `get_bytes 0x004822f6 size 16` begins with ten `0xcc` bytes before the successor method bytes at `0x00482300`.
- Vtable bytes at `0x00615000` begin `50 21 48 00 00 23 48 00`, matching pointers to `0x00482150` and `0x00482300`.
- `make_signature_for_range 0x00482150-0x004822f6` returned a unique IDA-format signature.

Resource/string evidence:

- `get_string 0x006153b4`: `CHATBUTT.EPF`
- `get_string 0x006153d0`: `CHATBUTT.PAL`
- `xrefs_to 0x006153b4`: exactly three refs from `0x004821a8`, `0x0048220b`, `0x00482270`
- `xrefs_to 0x006153d0`: exactly three refs from `0x004821b4`, `0x00482217`, `0x0048227c`
- `get_bytes 0x006153b4 size 56` shows the adjacent UTF-16 strings `CHATBUTT.EPF` and `CHATBUTT.PAL`.

Global/helper evidence:

- `xrefs_to 0x0067a744` with wider limit includes this target's three loads at `0x0048219c`, `0x004821fc`, and `0x0048225f`; this remains consumer evidence only, not ownership transfer from ChattingHandlePane to ImageLib/ResourceLayoutTable.
- `decompile 0x004d02f0` shows the lookup method resolving/loading a resource by name, bounds-checking frame index, and filling the caller's EPF tile context fields. On invalid lookup it clears the output through `InitRectBounds(..., 0,0,0,0)` and zeroes context payload fields.
- `decompile 0x004b9980` shows a six-argument shared wrapper that resolves the palette through `sub_543D70(dword_67A7E0, Source)` and forwards to `unk_69B3E8`. Use accepted source-facing `RenderTileFrame`.
- `decompile 0x004b9670` stores the argument into `this + 0x78` and returns it. Existing accepted paint C++ uses `SetPaneDrawMode(...)` for this helper family; use `SetPaneDrawMode(0)` here.
- `decompile 0x00457a60` initializes the 0x28-byte tile context, clears pointers/stride/mask fields, and calls `InitRectBounds(this + 4, 0, 0, 0, 0)`.

## Behavior Reconstruction

The body initializes one stack `EPFTileContext` and one local destination `RectBounds`. Hex-Rays splits the tile local into `v8[4]` at `ebp-0x3c` and `v9[24]` at `ebp-0x2c`; these are the same 0x28-byte context. The second argument to `RenderTileFrame` is therefore `&tile.m_bounds` / `tile + 0x10`, not a separate draw record.

The paint flow is:

1. Initialize `EPFTileContext tile`.
2. Set pane draw mode/state to `0`.
3. Draw the left button into rect `(0,4,19,21)`.
4. Draw the mode button into rect `(630,4,649,21)`.
5. Draw the secondary button into rect `(649,4,668,21)`.
6. Copy the live button/state fields into `m_renderStateSnapshot` and mark it valid.

Exact frame formulas:

- Left button:
  - base `3 * m_leftButtonPaintState`
  - add `9` when `m_chatTargetPending` is false
  - no add when `m_chatTargetPending` is true
- Mode button:
  - base `3 * m_modeButtonPaintState`
  - add `1` when `m_chatHandleModeIndex` is nonzero
  - add `10` when `m_chatHandleModeIndex` is zero
- Secondary button:
  - base `3 * m_secondaryButtonPaintState`
  - add `2` when `m_secondaryChatEnabled` is true
  - add `11` when `m_secondaryChatEnabled` is false

Snapshot writes:

- `+0x0f8`: `m_renderStateSnapshot.valid = true`
- `+0x0f9`: `m_renderStateSnapshot.chatTargetPending = m_chatTargetPending`
- `+0x0fc`: `m_renderStateSnapshot.chatHandleModeIndex = m_chatHandleModeIndex`
- `+0x100`: `m_renderStateSnapshot.secondaryChatEnabled = m_secondaryChatEnabled`
- `+0x104`: `m_renderStateSnapshot.leftButtonPaintState = m_leftButtonPaintState`
- `+0x108`: `m_renderStateSnapshot.modeButtonPaintState = m_modeButtonPaintState`
- `+0x10c`: `m_renderStateSnapshot.secondaryButtonPaintState = m_secondaryButtonPaintState`

No `ReleaseBuffers` or cleanup helper is called in this range.

## Source-Quality Name Decisions

Use these names in the target update:

| Binary item | Source-facing name |
| --- | --- |
| `sub_482150` | `ChattingHandlePane::OnPaint()` |
| `sub_457A60` | `EPFTileContext::Initialize()` / `tile.Initialize()` |
| `sub_4B9670(this, 0)` | `SetPaneDrawMode(0)` |
| `sub_4B7C50` | `InitRectBounds` |
| `dword_67A744` | `g_pEPFLib` |
| `sub_4D02F0(g_pEPFLib, resource, frame, &tile)` | `g_pEPFLib->LookupLayoutEntry(...)` |
| `sub_4B9980(&tile, &tile+0x10, &rect, 0, palette, 0)` | `RenderTileFrame(&tile, &tile.m_bounds, &rect, 0, palette, 0)` |
| `aChatbuttEpf` | `L"CHATBUTT.EPF"` |
| `aChatbuttPal` | `L"CHATBUTT.PAL"` |
| `+0x111` | `m_chatTargetPending` |
| `+0x114` | `m_chatHandleModeIndex` |
| `+0x118` | `m_secondaryChatEnabled` |
| `+0x11c/+0x120/+0x124` | `m_leftButtonPaintState`, `m_modeButtonPaintState`, `m_secondaryButtonPaintState` |
| `+0x0f8..+0x10c` | `m_renderStateSnapshot` |

These field names are already synchronized by the B003 OnMouseEvent implementation and the constructor/config support pages. Do not reintroduce generated names such as generic `chatBubble` fields or owner-polluted helper methods.

## Ownership And Rejected Alternatives

Ranked ownership decision:

1. [UID:00001V][ChattingHandlePane](../../../../../by-class/ChattingHandlePane.md) is the direct semantic owner. The only inbound route is the ChattingHandlePane vtable slot at `0x00615000`, sibling constructor/mouse-event pages establish the field layout, and the body reads/writes only receiver state plus shared render helpers.
2. [UID:0000I5][Chatting](../../../../../by-file/Chatting.md) remains the source file/emitter route through `NexusTK/social/Chatting.cpp`.
3. [UID:000104][ChattingUI](../../../../../by-memory/0x0047efb0-0x00483ef7.ChattingUI.md) is a parent aggregate only.

Rejected owner moves:

- `ResourceLayoutTable`, `ImageLib`, and `g_pEPFLib`: provide shared resource lookup. The target is one of many consumers.
- `SurfacePaintHelpers` / `RenderTileFrame`: provides shared draw dispatch and palette lookup. Broad fan-in and support docs reject feature-local ownership.
- `GrafPortDrawStateAccessors`: owns the `0x004b9670` state setter, not this paint method.
- `EPFTileContext`: owns the stack context initializer and context layout, not this paint method.
- `ChattingStringResourceData`: owns the string storage range for `CHATBUTT.EPF/PAL`, not this method.
- `GetChatButtonRectRaw`: not called by this target. It remains a no-route raw helper and should not be invented into the OnPaint source.
- `GetChatButtonAtPoint`: called by OnMouseEvent only. OnPaint uses literal rect setup and does not perform hit testing.
- `UserPane`, `ScrollWidget`, `ChattingBackPane`, `ChattingDisplayPane`, and `ChattingModifyHeightPane`: sibling mouse-event dependencies, not OnPaint ownership.

## Heuristic Reanalysis

The earlier blank-C++ blocker is now stale. The current page had strong behavior but still used raw-helper labels in parts of the source-quality discussion. Current helper pages and accepted sibling paint C++ provide enough stable vocabulary for a first-draft method body:

- `EPFTileContext tile; tile.Initialize();`
- `g_pEPFLib->LookupLayoutEntry(...)`
- `RenderTileFrame(&tile, &tile.m_bounds, &rect, 0, ..., 0)`
- `SetPaneDrawMode(0)`
- `InitRectBounds(...)`

The remaining unresolved items are final header spelling and exact original member names, not blockers for source reconstruction:

- Final public type of `g_pEPFLib` remains open between `ImageLib`, `ResourceLayoutTable`, or a resource-layout facet. Existing source-quality pages already permit call-site use of `g_pEPFLib->LookupLayoutEntry`.
- Exact original names for `m_renderStateSnapshot` and the chat handle fields remain inferred, but they are synchronized across constructor, OnMouseEvent, raw snapshot helpers, `g_pConfig`, class, and file pages.
- Exact shared render declarations remain support-level work, but `ChattingModifyHeightPane::OnPaint` already emits an equivalent `RenderTileFrame(&tile, &tile.m_bounds, ..., 0, palette, 0)` call at `88/92`.

Negative evidence that should be preserved in implementation:

- Do not route or call `GetChatButtonRectRaw`.
- Do not model the `v9` local as a second independent render record.
- Do not retain `sub_4D02F0`, `sub_4B9980`, `dword_67A744`, `aChatbuttEpf`, or `aChatbuttPal` in formal C++.
- Do not duplicate `ChatHandleButtonPaintState` if the implementation target remains in current generated order after [UID:0002FT]; the enum is already emitted before UID `0002FU`.
- Do not raise confidence above the low 90s until the shared render header/type spellings and exact original class field spellings are final.

## Formal C++ Recommendation

Insert this exact source text into [UID:0002FU]'s `RECONSTRUCTION_CPP CODE` block. It assumes the existing `ChatHandleButtonPaintState` enum from [UID:0002FT] remains available before this method in `Chatting.cpp`.

```cpp
void ChattingHandlePane::OnPaint()
{
    EPFTileContext tile;
    RectBounds drawRect;

    tile.Initialize();
    SetPaneDrawMode(0);

    InitRectBounds(&drawRect, 0, 4, 19, 21);
    int frameIndex = 3 * m_leftButtonPaintState;
    if (!m_chatTargetPending)
        frameIndex += 9;
    g_pEPFLib->LookupLayoutEntry(L"CHATBUTT.EPF", frameIndex, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &drawRect, 0, L"CHATBUTT.PAL", 0);

    InitRectBounds(&drawRect, 630, 4, 649, 21);
    frameIndex = 3 * m_modeButtonPaintState;
    if (m_chatHandleModeIndex)
        frameIndex += 1;
    else
        frameIndex += 10;
    g_pEPFLib->LookupLayoutEntry(L"CHATBUTT.EPF", frameIndex, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &drawRect, 0, L"CHATBUTT.PAL", 0);

    InitRectBounds(&drawRect, 649, 4, 668, 21);
    frameIndex = 3 * m_secondaryButtonPaintState;
    if (m_secondaryChatEnabled)
        frameIndex += 2;
    else
        frameIndex += 11;
    g_pEPFLib->LookupLayoutEntry(L"CHATBUTT.EPF", frameIndex, &tile);
    RenderTileFrame(&tile, &tile.m_bounds, &drawRect, 0, L"CHATBUTT.PAL", 0);

    m_renderStateSnapshot.valid = true;
    m_renderStateSnapshot.chatTargetPending = m_chatTargetPending;
    m_renderStateSnapshot.chatHandleModeIndex = m_chatHandleModeIndex;
    m_renderStateSnapshot.secondaryChatEnabled = m_secondaryChatEnabled;
    m_renderStateSnapshot.leftButtonPaintState = m_leftButtonPaintState;
    m_renderStateSnapshot.modeButtonPaintState = m_modeButtonPaintState;
    m_renderStateSnapshot.secondaryButtonPaintState = m_secondaryButtonPaintState;
}
```

No-code proof is not applicable. The target is code-gate eligible and the remaining uncertainties are header/source spelling polish rather than behavioral blockers.

## Score And Metadata Recommendation

Recommended target metadata after Rule 26 incorporation:

- `COMPLETION:89`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00001V`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00001V`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank
- populate formal C++ block with the code above

Rationale:

- Completion should rise from `86` to `89` because the target now has current MCP evidence, exact boundary/padding, exact resource strings/xrefs, exact frame formulas, exact snapshot writes, accepted source-facing helper names, and formal first-draft C++.
- Confidence should rise from `90` to `91` because the new MCP evidence independently confirms the current page and resolves the helper spelling enough for C++.
- Do not raise higher yet. Exact original class member spellings and final shared render/header types remain inferred.

## Implementation Checklist

Completed during B014 implementation callback on 2026-06-28:

- [x] Target page `by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md`
  - [x] Changed score to `89/91`, inserted the formal C++ block, updated summary/status, added current MCP evidence, recorded `CHATBUTT.EPF/PAL` string addresses and xrefs, replaced helper wording with source-facing helper names, preserved rejected alternatives, and added support cross-references.
  - [x] Validator proof: `command_id 000000000044`, `command_timestamp 2026-06-28T22:09:38-04:00`, exit `0`, `ok: 1`, `completion_update 0002FU 89`, `confidence_update 0002FU 91`, `autogen_cpp_update: 1`, `reference_index_add` for support refs, `generated_refresh: completed`.
- [x] Class page `by-class/ChattingHandlePane.md`
  - [x] Updated the `OnPaint` row to first-draft C++ ready at `89/91`, mentioned exact frame formulas and snapshot writes, and added B014 evidence/change text with no owner change.
  - [x] Validator proof: `command_id 000000000037`, `command_timestamp 2026-06-28T22:08:56-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] File page `by-file/Chatting.md`
  - [x] Updated the `ChattingHandlePane` row and source-quality note to say UID `0002FU` has formal first-draft C++, emits through [UID:00001V], and remains under `NexusTK/social/Chatting.cpp`; preserved B003 field/support decisions.
  - [x] Validator proof: `command_id 000000000040`, `command_timestamp 2026-06-28T22:09:22-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Aggregate page `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
  - [x] Updated the UID `0002FU` row to first-draft C++ ready with the three button rects, `CHATBUTT.EPF/PAL`, frame formulas, and snapshot state; added B014 change text.
  - [x] Validator proof: `command_id 000000000042`, `command_timestamp 2026-06-28T22:09:31-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Support pages
  - [x] `ChattingStringResourceData` required no edit. Proof: existing lines record `CHATBUTT.EPF` at `0x006153b4` with xrefs `0x004821a8`, `0x0048220b`, `0x00482270`, and `CHATBUTT.PAL` at `0x006153d0` with xrefs `0x004821b4`, `0x00482217`, `0x0048227c`.
  - [x] `g_pEPFLib`, `ResourceLayoutTableLookupLayoutEntry`, `SurfacePaintHelpers`, `GrafPortDrawStateAccessors`, `RectGeometryHelpers`, and `EPFTileContext` had no score/metadata changes; the target page now links the relevant support UIDs.
- [x] Generated outputs
  - [x] No generated files, project-level generated files, manual coverage reports, validator/tool state, generated C++ files, or IDA DB were hand-edited.
  - [x] Generated check proof: `auto-generated/NexusTK/social/Chatting.cpp` contains `UID:0002FU` at line `446` and `void ChattingHandlePane::OnPaint()` at line `447`; explicit marker check returned `uid0002fu_empty_marker=absent`.
- [x] Leases
  - [x] Proof: final `unlease` attempt for the four edited by-* paths returned `Rejected[No active lease]` because the short leases had already expired/cleared; shared `tools/leaser/Agents/current_leases.md` then reported `No active leases.`

## Residual Risk

Residual risk is low and localized to final source spellings:

- `m_chatTargetPending`, `m_chatHandleModeIndex`, `m_secondaryChatEnabled`, the paint-state fields, and `m_renderStateSnapshot` are source-facing inferred names. They are now consistent across constructor, OnMouseEvent, snapshot helpers, config support, class page, and file page, but exact original names are still not proven.
- `g_pEPFLib->LookupLayoutEntry` is source-ready as a call role, but the exact public type of `g_pEPFLib` remains unresolved in ImageLib/ResourceLayout support pages.
- `RenderTileFrame` and `SetPaneDrawMode` are accepted source-facing helper roles, but final shared render header declarations are broader support work.

These are not blockers for [UID:0002FU] implementation under the current Rule 26 standard.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002FU-ChattingHandlePaneOnPaint-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0002FU-ChattingHandlePaneOnPaint-source-quality.md","timestamp":"2026-06-28T22:19:33","uid":"0002FU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
