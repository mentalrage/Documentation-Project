** TARGET-REPORT-UID:0004BW **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0004BW] IMEStatusPaneSetText Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: convert [UID:0004BW] `IMEStatusPane::SetText` from an exact split child with blank emitter/code into an emitting [UID:00006I] `IMEStatusPane` method child routed through [UID:0000K5] `IMEPanes`.
- Final disposition: source-authored `IMEStatusPane` method, not an aggregate, no-code marker, GrafPort helper, ScreenPane helper, read-only-data owner, or InputMan event bridge.
- Required action after supervisor validation: update the target metadata to `89/91`, set `EMITTER_UIDS:00006I`, keep owner/reconstructable unchanged, keep position blank, and insert the formal C++ block below. Sync only concise support rows/notes in the class/file/aggregate docs; helper/read-only pages already contain sufficient support evidence.
- Confidence: high for body, range, caller closure, helper roles, owner route, and first-draft source shape; capped below final audit because inherited helper spellings remain descriptive source-facing names rather than recovered PDB names.

## Target

- Target UID: [UID:0004BW]
- Target path: `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md`
- Assignment: `B009-report-0004BW-IMEStatusPaneSetText-20260630`
- Source queue row: `auto-generated/-ag-research-tracker.md` lists [UID:0004BW] as `82/88`, combined `85.0`, reconstructable `true`, reports `0`.
- Current generated coverage row: `auto-generated/-ag-coverage-report-by-memory.md` lists [UID:0004BW] as `emits_code:false`, `reconstructable`, `82%`, `strong`, updated `2026-06-30 14:17:12`.
- Current generated C++ lead: `auto-generated/NexusTK/input/IMEPanes.cpp` currently has [UID:000189] aggregate text with `[[No Children Attached]]`; [UID:0004BW] does not emit because the target has blank `EMITTER_UIDS` and blank formal C++.

## Current Target State

Target metadata now:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `82` |
| `CONFIDENCE` | `88` |
| `CANONICAL_OWNER` | `00006I` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | blank |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Formal C++ | blank |

Current target text correctly identifies the class owner, source-file route, `statusText[256]` at `this+0xf8`, measured status text, lower-right placement, bounds update, copy, explicit trailing nul, and invalidation. The score/source-quality blocker is the stale wording that formal C++ must remain blank for a later child-specific pass. Current MCP resolves that blocker.

Related docs checked:

- `by-class/IMEStatusPane.md` [UID:00006I]
- `by-file/IMEPanes.md` [UID:0000K5]
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` [UID:000189]
- `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md` [UID:0004BX]
- `by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md` [UID:0004BZ]
- `by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md` [UID:0004C0]
- `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` [UID:00025J]
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md` [UID:00016C]
- `by-global/g_pScreenPane.md` [UID:0000S7]
- `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md` [UID:0001G7]
- `by-class/Pane.md` [UID:0000A2], `by-file/Pane.md` [UID:0000MC], `by-memory/0x00544460-0x00545086.PaneCore.md` [UID:0001EA], `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md` [UID:0003CA], and `by-type/by-struct/RectBoundsLayout.md` [UID:0001VP].

## Evidence Checked

IDA MCP was available and used. No fallback-only evidence was used.

MCP availability and schema:

- JSON-RPC `initialize` id `1`: server `ida-pro-mcp`, protocol `2025-06-18`.
- `tools/list` id `2`: 65 tools available. Current schemas use `queries`, `addr`, `addrs`, and `regions`, not the older `address`/`start` argument names.
- `idb_list` id `3`: one active worker session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, PID/worker PID `24256`.
- `server_health` id `4`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Initial schema-mismatch calls ids `10`-`17` failed with missing `queries`/`addr`/`addrs`/`regions`; this is recorded only to show the active schema was rechecked before relying on MCP. The corrected calls below succeeded.

Target MCP evidence:

- `lookup_funcs` id `40`: `0x004e70f0 -> sub_4E70F0`, size `0xcc`; `0x004e71bc` is not a function; successor `0x004e71c0 -> sub_4E71C0`, size `0xca`; predecessor `0x004e70e9` is not a function.
- `analyze_function` id `41`: prototype-shaped as `int __thiscall(int this, wchar_t *Source, int)`, size 204, callees `_wcsncpy_s`, `sub_4BA9A0`, `sub_4BAAA0`, `sub_557450`, `sub_557460`, security-cookie check; callers `sub_4E71C0` and `sub_4E72B0`.
- `decompile` id `42`: clamps only `length > 255` to `255`, measures width through `0x004ba9a0`, gets line height through `0x004baaa0`, reads `dword_67A7CC` screen width/height through `0x00557450` and `0x00557460`, builds a four-int stack rectangle, calls inherited vtable slot `+0x2c`, copies with `wcsncpy_s((wchar_t *)(this+248), 0x100, Source, MaxCount)`, writes `*(WORD *)(this + 2*MaxCount + 248) = 0`, and calls inherited vtable slot `+0x20` with `this+0x44`.
- `disasm` id `43`: 74 instructions; `cmovg eax, 0xff` implements only the upper clamp; stack locals from `ebp-0x14` through `ebp-0x8` are the `RectBounds` left/top/right/bottom; call at `0x004e7178` is vtable `+0x2c`; `_wcsncpy_s` call at `0x004e718c`; explicit nul at `0x004e7196`; vtable `+0x20` invalidation at `0x004e71a6`; returns at `0x004e71b9`.
- `xrefs_to` id `44`: exactly two code xrefs to `0x004e70f0`: constructor caller `0x004e7249` inside `sub_4E71C0` and mode-change caller `0x004e72ec` inside `sub_4E72B0`. No data/vtable xrefs were reported, matching a non-virtual class helper.
- `callees` id `45`: direct callees are `0x004ba9a0`, `0x004baaa0`, `0x00557450`, `0x00557460`, `_wcsncpy_s`, and the security-cookie check.
- `get_bytes` id `46`: predecessor bytes `0x004e70e9-0x004e70ef` are seven `0xcc` bytes; successor bytes `0x004e71bc-0x004e71bf` are four `0xcc` bytes.

Helper/caller MCP evidence:

- `lookup_funcs` id `60`: helper sizes `0x004ba9a0` size `0xc7`, `0x004baaa0` size `0x25`, `0x00557450` size `0x8`, `0x00557460` size `0x8`, `0x00544bd0` size `0x73`, and `0x00544800` size `0xac`; `0x0061c580`, `0x0061c590`, and `0x0061c598` are not functions.
- `decompile 0x004e71c0` id `61`: constructor installs the three `IMEStatusPane` vtable views, zeroes `this+0xf8` for `0x200` bytes, calls `sub_4E70F0(this, L"Closed", 6)`, then attaches/registers the pane.
- `decompile 0x004e72b0` id `62`: event handler checks Event type `11`, chooses `L"IME"` or `L"ENG"` from Event `+0x08`, adjusts secondary `this` by `-0xa0`, and calls `sub_4E70F0` with length `4` for `IME` or `6` for `ENG`.
- `decompile 0x004ba9a0` id `63`: constructs a text iterator over `(text, charCount)` and accumulates glyph advances through the FontImageLib route. Current support names the source-facing role as `GrafPort::GetTextWidth`; accepted IME-family C++ uses the compatible descriptive wrapper name `MeasureTextWidth`.
- `decompile 0x004baaa0` id `64`: obtains the current font metrics line height through the FontImageLib route; current support names this `GrafPort::GetLineHeight()`.
- `decompile 0x00557450` id `65` and `0x00557460` id `66`: return `this[137]` and `this[138]`, the cached screen width and height fields documented in `g_pScreenPane` / `ScreenCursorHelpers`.
- `decompile 0x00544bd0` id `67`: inherited `Pane::SetBounds`, storing origin and translating local bounds.
- `decompile 0x00544800` id `68`: inherited `Pane::InvalidateRect`.
- `get_string` id `69`: `0x0061c580` decodes `Closed`, `0x0061c590` decodes `IME`, and `0x0061c598` decodes `ENG`.

Old/current report search:

- Search terms included `0004BW`, `004e70f0`, `IMEStatusPaneSetText`, `IMEStatusPane::SetText`, `IMEStatusPane`, `IMEPaneFamily`, `sub_4E70F0`, `sub_4BA9A0`, `sub_4BAAA0`, `sub_557450`, `sub_557460`, and `dword_67A7CC`.
- Relevant prior reports opened as leads and revalidated against current docs/MCP:
  - `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`, which created [UID:0004BW] as an exact split child but explicitly left child-specific body C++ out of that split callback.
  - `executed-b-agent-research/B007/0004C0-IMEStatusPaneOnPaintFrame-source-quality.md`, which establishes accepted status-pane helper naming style and the [UID:00006I] -> [UID:0000K5] emitter route.
  - Existing/current IME sibling pages [UID:00018A], [UID:00018B], [UID:0004C3], and [UID:0004C5], which provide accepted `RectBounds`, `SetBounds`, `Invalidate`, `MeasureTextWidth`, `GetLineHeight`, `g_pScreenPane`, and `m_bounds` style leads.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:0004BW] is one complete function `0x004e70f0-0x004e71bc`, size `0xcc`, with `0xcc` padding before and after. | High | MCP ids `40`, `43`, `46`; current aggregate row. | Target `Evidence`, `Direct Xref / Caller Inventory`, `Reconstruction Notes`, `Score Rationale`; aggregate covered-range/source-placement row. | incorporate | applied - target and aggregate now record size/range/padding; validators `000000003199` and `000000003203` exited `0`, `ok:1`. |
| C02 | The only direct callers are the `IMEStatusPane` constructor at `0x004e7249` and mode-change handler at `0x004e72ec`; there are no data/vtable xrefs because this is a non-virtual class helper. | High | MCP id `44`; caller decompiles ids `61`, `62`; class method inventory. | Target `Evidence` and caller inventory; class/file/aggregate evidence notes. | incorporate | applied - target, class, file, and aggregate now preserve constructor/mode-change caller closure; validators `000000003199`, `000000003201`, `000000003202`, `000000003203` all exited `0`, `ok:1`. |
| C03 | Direct semantic owner remains [UID:00006I] `IMEStatusPane`; source route is [UID:00006I] -> [UID:0000K5] `IMEPanes`; aggregate support is [UID:000189]. | High | Target/class/file/aggregate docs; MCP caller closure and `statusText[256]` field use. | Target metadata/status; class/file/aggregate support rows. | incorporate | applied - target `EMITTER_UIDS:00006I`; class/file/aggregate route rows updated; generated `IMEPanes.cpp` header command `000000003203` emits UID0004BW through [UID:00006I]. |
| C04 | The body clamps only upper bound `length > 255`, does not lower-clamp negative values, measures the clamped count, copies into `statusText[256]` at `this+0xf8`, and writes an explicit trailing UTF-16 nul. | High | MCP decompile/disasm ids `42`, `43`; class field [UID:00006I]; constructor zeroing id `61`. | Target `Behavior`, `Evidence`, formal C++; class/file/aggregate evidence notes. | incorporate | applied - target behavior and formal C++ preserve upper-only clamp/copy/terminator; class/file/aggregate support rows updated; validator `000000003199` generated UID0004BW body. |
| C05 | Text width and line height use GrafPort text helpers at `0x004ba9a0` and `0x004baaa0`; accepted IME-family source-facing code may use `MeasureTextWidth`/`GetLineHeight`, with support noting formal GrafPort name `GetTextWidth`. | Medium-high | MCP ids `45`, `60`, `63`, `64`; [UID:00016C]; sibling [UID:00018A]/[UID:00018B] formal C++. | Target helper/source-shape notes and formal C++; helper support already present. | incorporate | applied - target `Behavior`/`Reconstruction Notes` and formal C++ preserve helper mapping; [UID:00016C] was already sufficient and left unchanged by design. |
| C06 | The status rectangle is lower-right screen anchored: `right=screenWidth`, `bottom=screenHeight`, `top=screenHeight-lineHeight-4`, and `left=screenWidth-(textWidth+4)` only when measured width is positive, otherwise `left=screenWidth`. | High | MCP decompile/disasm ids `42`, `43`; screen helpers ids `65`, `66`; [UID:0000S7]/[UID:0001G7]. | Target `Behavior`, formal C++; class/file/aggregate summaries. | incorporate | applied - target behavior/formal C++ and support rows preserve exact lower-right rectangle math; generated body lines under UID0004BW contain the accepted math. |
| C07 | The inherited vtable `+0x2c` call is `Pane::SetBounds`; the inherited vtable `+0x20` call is `Pane::InvalidateRect` with local bounds at `this+0x44` / `m_bounds`. | High | MCP decompiles ids `67`, `68`; PaneCore [UID:0001EA], PaneVtableData [UID:0003CA], PaneLayout [UID:0001VH]. | Target `Evidence`, `Reconstruction Notes`, formal C++; Pane support already present. | incorporate | applied - target and class/file/aggregate notes record inherited slots and formal C++ uses `SetBounds(&statusRect, 0)` and `Invalidate(&m_bounds)`; Pane support docs were already sufficient and left unchanged. |
| C08 | `Closed`, `IME`, and `ENG` are caller/context literals in [UID:00025J], not target-owned strings; SetText itself receives caller-provided text. | High | MCP caller decompiles ids `61`, `62`; `get_string` id `69`; [UID:00025J]. | Target caller inventory; read-only-data support plan. | already-present | already-present - target caller inventory now preserves constructor/mode caller literal context, and [UID:00025J] already decoded the three literals; no read-only-data edit was required. |
| C09 | Formal C++ should be `void IMEStatusPane::SetText(const wchar_t *text, int length)` with the exact source behavior below; the decompiler integer return is only the tail invalidation artifact and the callers ignore it. | High | Class shell declares `void SetText`; MCP ids `41`-`44`; sibling [UID:00018B] source-shape precedent for ignored invalidate return. | Target formal `RECONSTRUCTION_CPP CODE`; class method row. | incorporate | applied - target formal block contains only the method body (no marker lines pasted) and generated `IMEPanes.cpp` contains `void IMEStatusPane::SetText(const wchar_t *text, int length)`. |
| C10 | Target metadata should move from `82/88`, blank emitter, to `89/91`, `EMITTER_UIDS:00006I`, owner/reconstructable unchanged, position blank. | High | Score blocker resolved by current MCP, support docs, and formal C++ readiness. | Target metadata and score rationale. | incorporate | applied - target metadata now `89/91`, owner `00006I`, reconstructable `TRUE`, emitter `00006I`, optional position blank; validator `000000003199` recorded completion/confidence and registry updates. |
| C11 | Rejected alternatives: no split/new UID, no no-code marker, no direct file bucket emitter, no GrafPort/ScreenPane/RectBounds/InputMan/read-only-data ownership, and no manual raw vtable/string source. | High | MCP exact range/callers/callees; by-structure owner/emitter rules; helper/read-only support docs. | Target `Reconstruction Notes`; support docs where concise. | incorporate | applied - target `Reconstruction Notes` and aggregate/source-route notes now preserve rejected alternatives; no split/new UID or direct file-bucket emitter was created. |
| C12 | Support docs need only concise synchronization: class method row, file evidence note, and aggregate child row/source-placement row. Constructor/mode/read-only/helper docs are already sufficient unless supervisor requests caller-sync wording. | Medium-high | Current docs checked; target can carry full proof. | `by-class/IMEStatusPane.md`, `by-file/IMEPanes.md`, `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`; others marked already-present/excluded. | incorporate | applied - class, file, and aggregate were updated and validated; constructor/mode/paint/read-only/helper/global/Pane/RectBounds docs were intentionally left unchanged as already-present support, with no contradiction found. |

## Positive Evidence Summary

- The exact range is stable: one 204-byte function at `0x004e70f0`, no function at `0x004e71bc`, successor constructor at `0x004e71c0`, and `0xcc` padding on both sides.
- The only callers are status-pane local: constructor sets initial `Closed`, and mode-change switches to `IME`/`ENG`. That caller closure supports a private class helper, not a shared text utility.
- The body reads/writes `IMEStatusPane` state: `statusText[256]` at `this+0xf8`, inherited bounds at `this+0x44`, inherited Pane/GrafPort text metrics, and inherited Pane bounds/invalidation virtuals.
- Existing class/file/aggregate docs already establish [UID:00006I] `IMEStatusPane` and [UID:0000K5] `IMEPanes` as the correct owner/source route. This report only resolves the child-body C++ blocker for [UID:0004BW].

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x004e7249` | Code xref from `sub_4E71C0` constructor to `0x004e70f0` | Initial status label is set to `Closed` with length `6`; constructor also zeroes `statusText[256]`. |
| `0x004e72ec` | Code xref from `sub_4E72B0` mode-change handler to `0x004e70f0` | Event type `11` switches status label between `IME` length `4` and `ENG` length `6`. |
| `0x004ba9a0` | Callee | Text-width measurement helper over counted UTF-16 text. |
| `0x004baaa0` | Callee | Current line-height helper. |
| `0x00557450` / `0x00557460` | Callees on `dword_67A7CC` / `g_pScreenPane` | Screen width and screen height. |
| `0x00544bd0` | Inherited vtable slot `+0x2c` target | `Pane::SetBounds`. |
| `0x00544800` | Inherited vtable slot `+0x20` target | `Pane::InvalidateRect`. |

## Ranked Ownership Analysis

### 1. [UID:00006I] IMEStatusPane

- Evidence for: class page declares `void SetText(const wchar_t *text, int length)` and `statusText[256]`; target writes `this+0xf8`; only callers are `IMEStatusPane` constructor and mode-change; source route already emits through [UID:0000K5].
- Evidence against: no PDB/original symbol exists. This is only a spelling confidence cap; behavior and class route are strong.
- Decision: recommended direct owner and emitter.

### 2. [UID:0000K5] IMEPanes direct file bucket

- Evidence for: source-file route owns the full pane-side IME family and will receive generated output.
- Evidence against: by-structure requires the narrow semantic owner when a class method is supported; direct file emitter would bypass [UID:00006I].
- Decision: keep as transitive source file route only.

### 3. GrafPort / ScreenPane / RectBounds / Pane helper owners

- Evidence for: target calls helper methods from those subsystems.
- Evidence against: helpers are dependencies; target state/callers are `IMEStatusPane`-specific. The function does not own text metrics, screen dimensions, rectangle layout, or Pane virtual infrastructure.
- Decision: rejected as direct owners.

### 4. InputMan / Event / read-only data

- Evidence for: caller mode-change consumes an event and caller literals live in [UID:00025J].
- Evidence against: SetText receives already-chosen text and count; no Win32/IMM bridge or event construction occurs in this body; vtable/string island is source-declared/generated-binary support.
- Decision: rejected as direct owner.

## Heuristic / Inference Reanalysis And Validation

The prior blocker "method-body C++ remains for a child-specific pass" is now resolved. Current MCP gives enough detail for first-draft source C++:

- Field inference: `statusText[256]` at `this+0xf8` is already documented by class, constructor, paint, and this body. No additional field names are required.
- Helper inference: `MeasureTextWidth` is accepted IME-family source-facing wording for the counted width call to `0x004ba9a0`, while the GrafPort support page records the stricter formal helper as `GrafPort::GetTextWidth`. This is a naming/style cap, not a behavior blocker.
- Geometry inference: IDA's decompiler splits the four-int rectangle across `_DWORD v12[2]`, `v13`, and `v14`, but disassembly proves those four contiguous stack locals are passed as the `RectBounds` pointer to vtable slot `+0x2c`.
- Return inference: Hex-Rays returns the result of `InvalidateRect`, but both direct callers ignore it and the class shell declares `void SetText`. Source C++ should be `void`, matching accepted sibling IME helper style.
- Length inference: the binary only upper-clamps. Do not add a lower clamp, null pointer guard, or `min/max` wrapper; constructor/mode callers supply small positive counts.
- Source placement: this belongs beside the status-pane constructor, mode-change, and paint child under [UID:00006I], not in global helper modules.

Rejected alternatives:

- Leaving C++ blank is rejected because the owner route, range, calls, field, helper names, geometry, and copy behavior are now resolved above the current code-entry gate.
- Adding a split is rejected because MCP proves one complete function with `0xcc` padding before and after.
- Emitting through [UID:0000K5] directly is rejected because [UID:00006I] is the class owner and already has `[[CHILDREN]]`.
- Adding lower-bound or null checks is rejected because no such checks exist in the binary.
- Replacing `SetBounds` with raw vtable syntax, or `MeasureTextWidth` with `sub_4BA9A0`, is rejected as decompiler-shaped output.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, the direct owner/emitter route is known, recommended scores clear the current `(COMPLETION + CONFIDENCE) / 2 > 85` code-entry gate, the method body is exact and bounded, and all material helper/field names have source-facing support.

Exact formal insertion text for [UID:0004BW]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IMEStatusPane::SetText(const wchar_t *text, int length)
{
    if (length > 255) {
        length = 255;
    }

    const int textWidth = MeasureTextWidth(text, length);
    const int lineHeight = GetLineHeight();
    const int screenWidth = g_pScreenPane->GetScreenWidth();
    const int screenHeight = g_pScreenPane->GetScreenHeight();

    RectBounds statusRect;
    statusRect.right = screenWidth;
    statusRect.bottom = screenHeight;
    statusRect.left = screenWidth;
    if (textWidth > 0) {
        statusRect.left -= textWidth + 4;
    }
    statusRect.top = screenHeight - lineHeight - 4;

    SetBounds(&statusRect, 0);

    wcsncpy_s(statusText, 256, text, length);
    statusText[length] = L'\0';

    Invalidate(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves behavior:

- `length > 255` is the exact `cmovg` upper clamp.
- Text measurement and line height are performed before geometry/copy, matching call order.
- Screen width/height are read from `g_pScreenPane` helpers at `0x00557450/0x00557460`.
- `right` and `bottom` stay at screen width/height; `left` only subtracts `textWidth + 4` when `textWidth > 0`; `top` subtracts `lineHeight + 4`.
- Text is copied after `SetBounds`, using 256 wide-character capacity, then the method writes an explicit trailing nul and invalidates the pane's current bounds.

Reason it matches source shape:

- It uses the same IME-family source-facing names as accepted sibling C++: `RectBounds`, `MeasureTextWidth`, `GetLineHeight`, `g_pScreenPane`, `SetBounds`, and `Invalidate`.
- It keeps `statusText` as the class-owned buffer and avoids raw offsets, raw vtable calls, and generated `sub_` names.
- It uses `void` because the class declaration and direct callers treat this as a side-effecting setter.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md`

Apply these edits after supervisor validation:

- Set `COMPLETION:89`.
- Set `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00006I`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:00006I`.
- Keep `EMITTER_POSITION_OPTIONAL` blank.
- Insert the exact formal C++ block above.
- Replace stale wording that says formal C++ stays blank for a later child-specific pass.
- Add MCP evidence ids `40`-`46`, `60`-`69`: session health/schema state, exact function size, caller closure, padding, callee list, helper decompiles, caller literal context, and string decode.
- Preserve the exact behavior details: upper-only clamp, `statusText[256]` copy at `+0xf8`, explicit trailing nul, four-int `RectBounds` stack local, lower-right screen placement, `SetBounds` vtable `+0x2c`, and `InvalidateRect` vtable `+0x20` with local bounds.
- Preserve negative evidence: no split, no no-code marker, no direct file bucket, no GrafPort/ScreenPane/RectBounds/InputMan/read-only-data ownership, no lower clamp or null guard.

## Recommended Support Doc Changes

Mandatory concise support sync if supervisor accepts:

- `by-class/IMEStatusPane.md` [UID:00006I]:
  - Update the `SetText` method row to link [UID:0004BW], note `89/91`, formal C++ populated, upper-only 255 clamp, `statusText[256]` copy, lower-right screen placement, and invalidation.
  - Add one evidence note that current B009 MCP confirmed `sub_4E70F0` size `0xcc`, two direct class-local callers, `statusText[256]`, and `SetBounds`/`Invalidate` inherited helper route.
  - No score/metadata change is required unless the supervisor wants class score movement; the class already clears `88/90`, and constructor/mode/destructor children still remain below individual formal-body review.
- `by-file/IMEPanes.md` [UID:0000K5]:
  - Add one evidence/change note that [UID:0004BW] now has formal `IMEStatusPane::SetText` C++ and emits through [UID:00006I], preserving this file as the `NexusTK/input/IMEPanes.cpp` route.
  - No metadata/score change required; [UID:0000K5] already owns the broader source family at `90/88`.
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` [UID:000189]:
  - Update the covered-range/source-placement row for `0x004e70f0-0x004e71bc` from generic "measures, positions, copies, and invalidates" wording to mention [UID:0004BW] `89/91`, formal C++ populated, lower-right `RectBounds`, upper-only clamp, and emitter route [UID:00006I] -> [UID:0000K5].
  - No aggregate score change required; many sibling split children remain child-body pending.

Already-present or optional/no-edit support:

- `by-memory/0x004e71c0-0x004e728a.IMEStatusPaneConstructor.md` [UID:0004BX] already records the `Closed` call, zeroing, and class route. Optional caller-sync wording can mention [UID:0004BW] if supervisor wants, but it is not required for this target implementation.
- `by-memory/0x004e72b0-0x004e72f8.IMEStatusPaneOnIMEModeChange.md` [UID:0004BZ] already records Event type `11` and `IME`/`ENG` SetText calls. Optional caller-sync wording can mention [UID:0004BW] if supervisor wants, but it is not required.
- `by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md` [UID:0004C0] already uses the same `statusText[256]` field and `m_bounds` paint style; no edit required.
- `by-memory/0x0061c360-0x0061c5a0.IMEPaneReadOnlyData.md` [UID:00025J] already decodes `Closed`, `IME`, and `ENG`; no edit required.
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`, `by-global/g_pScreenPane.md`, `by-memory/0x00557380-0x00557467.ScreenCursorHelpers.md`, Pane docs, and `RectBoundsLayout.md` already support helper names/layout; no edit required.

## Score And Metadata Recommendation

Target [UID:0004BW]:

| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `82` | `89` | Current MCP resolves the exact body, callers, padding, upper-only clamp, rectangle construction, inherited helper slots, text copy, invalidation, support route, rejected alternatives, and first-draft formal C++. Keep below final audit because exact original helper/member spellings are inferred and several sibling status-pane methods remain pending. |
| `CONFIDENCE` | `88` | `91` | Current MCP and support docs strongly agree on body behavior, owner route, and helpers. Confidence remains below absolute certainty because original source names are stripped and `MeasureTextWidth` is a source-facing alias over the current GrafPort support name. |
| `CANONICAL_OWNER` | `00006I` | `00006I` | Correct narrow class owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Live NexusTK UI source code. |
| `EMITTER_UIDS` | blank | `00006I` | Emit through the owning class shell into [UID:0000K5]. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | Existing class child scan/source order is sufficient. |

Score-improvement audit:

- C++ blocker: resolved with current MCP and formal insertion text.
- Helper-name blocker: resolved enough for first-draft C++; helper docs and accepted IME siblings support the names.
- Source-placement blocker: resolved to [UID:00006I] -> [UID:0000K5].
- Range/split blocker: resolved; no split needed.
- Negative evidence blocker: resolved; helper/global/read-only consumers are dependencies, not owners.

## Open Questions With Attempted Resolution

- Exact original spelling of `MeasureTextWidth` versus `GetTextWidth`: support page [UID:00016C] uses `GrafPort::GetTextWidth`, while accepted IME-family method bodies use `MeasureTextWidth`. Use `MeasureTextWidth` in [UID:0004BW] for local consistency, and document the `0x004ba9a0` mapping. This is a confidence cap, not a blocker.
- Exact inherited member spelling for `m_bounds`: accepted status/composition paint children now use `m_bounds`; older IME helper bodies still contain `Invalidate(&bounds)`. Use `Invalidate(&m_bounds)` in this target because [UID:0004C0] is the same class and uses `m_bounds` already. This is a source-spelling cap only.
- Negative length behavior: current binary does not lower-clamp. Do not "fix" this; direct callers supply valid positive lengths. Adding a guard would be behavior drift.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. The by-memory generated coverage/tracker rows are validator-owned. If the report is accepted, update source by-* docs and run scoped validators; do not manually edit generated coverage or tracker files.

## Validator And Generated Freshness Expectations

Report-only pass: no validators were run before supervisor acceptance.

Expected implementation callback validators from `source-3/project-documentation`:

- `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md --apply --wait-generated --queue-timeout 240`
- If class support is edited: `python .\tools\validator.py --mode file --file by-class/IMEStatusPane.md --apply --wait-generated --queue-timeout 240`
- If file support is edited: `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240`
- If aggregate support is edited: `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --wait-generated --queue-timeout 240`

Generated freshness check after implementation:

- Inspect `auto-generated/NexusTK/input/IMEPanes.cpp` after the final `--wait-generated` validator.
- Confirm the generated header `validator-command-id`/`validator-refreshed-at` is equal/newer than the final relevant validator command.
- Confirm a `// UID:0004BW | by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md` marker appears and contains `void IMEStatusPane::SetText(const wchar_t *text, int length)`.
- Confirm no [UID:0004BW] empty-emitter marker remains.

Callback validator results:

| File | Command | command_id | command_timestamp | Exit | ok | generated_refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md --apply --wait-generated --queue-timeout 240` | `000000003199` | `2026-06-30T16:34:31-04:00` | `0` | `1` | completed |
| `by-class/IMEStatusPane.md` | `python .\tools\validator.py --mode file --file by-class/IMEStatusPane.md --apply --wait-generated --queue-timeout 240` | `000000003201` | `2026-06-30T16:34:47-04:00` | `0` | `1` | completed |
| `by-file/IMEPanes.md` | `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240` | `000000003202` | `2026-06-30T16:36:22-04:00` | `0` | `1` | completed |
| `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` | `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --wait-generated --queue-timeout 240` | `000000003203` | `2026-06-30T16:36:39-04:00` | `0` | `1` | completed |

Generated freshness after callback:

- `auto-generated/NexusTK/input/IMEPanes.cpp` header is `validator-command-id: 000000003203` and `validator-refreshed-at: 2026-06-30T16:36:39-04:00`, equal to the final aggregate validator command.
- Generated output contains `// UID:0004BW | by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md | Completion:89 | Confidence:91` followed by `void IMEStatusPane::SetText(const wchar_t *text, int length)`.
- No UID0004BW empty-emitter marker remains. The remaining `[[No Children Attached]]` hit is the [UID:000189] aggregate marker, not the UID0004BW target.
- Generated reports/C++ and validator state were changed only by validator-owned side effects from the scoped commands; no generated or coverage file was manually edited.

## Changed Files

- `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md`: metadata `82/88` -> `89/91`, `EMITTER_UIDS:00006I`, formal `IMEStatusPane::SetText` body inserted, evidence/behavior/rejected alternatives/score rationale updated at report-level detail.
- `by-class/IMEStatusPane.md`: SetText method row and evidence/change notes updated; class metadata unchanged.
- `by-file/IMEPanes.md`: UID0004BW source-route evidence/change notes added; file metadata unchanged. Current B010 support text was preserved.
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`: UID0004BW covered-range and split/source-placement rows plus evidence/change notes updated; aggregate metadata unchanged. Current B010 support text was preserved.
- `tools/leaser/Agents/Agent-B009/research/0004BW-IMEStatusPaneSetText-source-quality.md`: callback ledger/checklist/proof updated.
- No generated files, generated reports, manual coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, or lock files were manually edited.
- Validator-owned side effects occurred during scoped validators: generated metadata/report refreshes, `auto-generated/NexusTK/input/IMEPanes.cpp` refresh, and validator registry rebuilds reported by validator output.

Leases used/released:

- Initial edit batch: B009 leased `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md` and `by-class/IMEStatusPane.md` successfully; `by-file/IMEPanes.md` and the aggregate were initially rejected because B010 held active leases until `2026-06-30T20:35:15Z`.
- Target/class release: B009 released the target and class leases successfully after validators `000000003199` and `000000003201`.
- Shared support batch: after the B010 leases expired and the files were re-read, B009 leased `by-file/IMEPanes.md` and `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, applied only UID0004BW support sync, validated them with `000000003202` and `000000003203`, and released both leases successfully.
- Final lease report shows no active leases.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: callback received 2026-06-30; implementation performed after accepted report.
- [x] Target metadata: update [UID:0004BW] `by-memory/0x004e70f0-0x004e71bc.IMEStatusPaneSetText.md` from `82/88`, blank emitter to `89/91`, `EMITTER_UIDS:00006I`, owner unchanged `00006I`, reconstructable unchanged `TRUE`, optional position blank. Proof: target metadata updated; validator `000000003199` recorded completion/confidence and registry updates, exit `0`, `ok:1`.
- [x] Target formal C++: insert the exact formal `IMEStatusPane::SetText` block from this report into the target `RECONSTRUCTION_CPP CODE` block. Proof: inserted only the method body, not report marker lines; generated `IMEPanes.cpp` contains UID0004BW marker/body.
- [x] Target behavior/evidence: preserve current MCP ids `40`-`46` and `60`-`69`, including active session health, schema-current call shape, exact range/size, padding, caller closure, helper/callee list, caller literals, and string decode. Proof: target `Evidence` records ids `1`-`4`, `40`-`46`, and `60`-`69`; validator `000000003199` passed.
- [x] Target length/copy facts: document upper-only `255` clamp, no lower clamp, `wcsncpy_s(statusText,256,text,length)`, explicit `statusText[length]=L'\0'`, and caller-supplied valid positive lengths. Proof: target `Behavior`, `Reconstruction Notes`, and formal C++ updated.
- [x] Target geometry facts: document `MeasureTextWidth`, `GetLineHeight`, `g_pScreenPane->GetScreenWidth/Height`, exact lower-right rectangle math, inherited `SetBounds`, and inherited `Invalidate(&m_bounds)`. Proof: target behavior/formal C++ updated and generated body contains the accepted math.
- [x] Target score rationale: replace stale "child-specific C++ later" rationale with the score-blocker resolution and reason not higher/lower. Proof: target score rationale now `89/91` with resolved C++/range/helper/source-placement rationale.
- [x] Target rejected alternatives: preserve no split, no no-code marker, no direct [UID:0000K5] emitter, no GrafPort/ScreenPane/RectBounds/InputMan/read-only-data ownership, no raw helper names, and no added guards. Proof: target `Reconstruction Notes` and aggregate support preserve rejected alternatives.
- [x] `by-class/IMEStatusPane.md`: update the SetText method row/evidence note with [UID:0004BW] `89/91`, formal C++ populated, upper-only clamp, lower-right geometry, `statusText[256]`, and current MCP caller closure; no class metadata change unless supervisor directs otherwise. Proof: row/evidence/change note updated; validator `000000003201` exit `0`, `ok:1`; class metadata unchanged.
- [x] `by-file/IMEPanes.md`: add concise support/change note that [UID:0004BW] now emits formal `IMEStatusPane::SetText` through [UID:00006I] into `NexusTK/input/IMEPanes.cpp`; no file metadata change. Proof: Proposed Contents/Evidence/Changes updated; validator `000000003202` exit `0`, `ok:1`; file metadata unchanged.
- [x] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`: update the [UID:0004BW] covered-range/source-placement row to say formal C++ populated, exact lower-right geometry/copy behavior, and route [UID:00006I] -> [UID:0000K5]; no aggregate metadata change. Proof: covered-range, evidence, split/source-placement, and change sections updated; validator `000000003203` exit `0`, `ok:1`; aggregate metadata unchanged.
- [x] Already-present support docs: leave [UID:0004BX], [UID:0004BZ], [UID:0004C0], [UID:00025J], [UID:00016C], [UID:0000S7], [UID:0001G7], Pane docs, and RectBounds docs unchanged unless callback/supervisor explicitly asks for caller-sync wording; record as already-present or excluded-with-reason during callback. Proof: these docs were not edited; target/class/file/aggregate now reference the already-present support without contradiction.
- [x] Claim And Incorporation Ledger: update every row from `proposed` to `applied`, `already-present`, `excluded-with-reason`, or `blocked` with proof during callback. Proof: ledger rows C01-C12 updated above; no blocked rows.
- [x] Validators: run scoped validators listed above for each changed by-* file, using `--wait-generated`. Proof: commands `000000003199`, `000000003201`, `000000003202`, `000000003203`; all exit `0`, `ok:1`, generated refresh completed.
- [x] Generated freshness: inspect `auto-generated/NexusTK/input/IMEPanes.cpp` after validator completion for current header, [UID:0004BW] marker/body, and no [UID:0004BW] empty-emitter marker. Proof: header command `000000003203`, refreshed `2026-06-30T16:36:39-04:00`; UID0004BW marker/body present; no UID0004BW empty marker.
- [x] No manual generated/coverage/validator-state edits: confirm implementation changed only accepted by-* docs and this report, with validator-owned side effects only. Proof: no generated/coverage/tool-state files were manually edited; validator output reports generated metadata/report refresh and registry rebuild side effects.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback goal `B009-implement-0004BW-IMEStatusPaneSetText-20260630`.
- [x] All accepted target/support doc details incorporated at report-level detail or explicitly excluded with reason. Proof: target/class/file/aggregate changed as listed; already-present support docs left unchanged with reason.
- [x] Ledger and checklist updated with applied/already-present/excluded/blocked proof. Proof: this section and C01-C12 ledger updated; no blockers.
- [x] Leases, if callback occurs, used only for immediate edit/validator batches and released immediately. Proof: target/class batch released after validation; file/aggregate batch leased after B010 expiration/re-read and released after validation; final lease report has no active leases.
- [x] Validator command ids, timestamps, exits, ok counts, generated-refresh state, changed files, and any blockers recorded. Proof: callback validator table, changed-file list, generated freshness, and lease proof recorded above; no unresolved blockers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0004BW-IMEStatusPaneSetText-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0004BW-IMEStatusPaneSetText-source-quality.md","timestamp":"2026-06-30T16:43:58","uid":"0004BW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
