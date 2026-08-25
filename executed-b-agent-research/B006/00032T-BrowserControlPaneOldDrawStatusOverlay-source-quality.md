** TARGET-REPORT-UID:00032T **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 00032T BrowserControlPaneOldDrawStatusOverlay Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00032T] owned by [UID:000016] `BrowserControlPaneOld`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:000016`, and promote the exact method to first-draft C++ under the existing Browser source route.
- Final disposition: the old blank-C++ blocker is now resolved enough for a first draft. The helper names that previously blocked the page are supported by accepted LanguageMan and GrafPort docs: `LanguageMan::GetLocalizedString`, `GrafPort::GetTextWidth`, `GrafPort::GetLineHeight`, `GrafPort::MoveTo`, `GrafPort::SetTextColor`, and `GrafPort::DrawWideText`.
- Required action if accepted: update [UID:00032T] with current MCP evidence, source-facing method/body notes, the formal C++ block below, and a score increase to `88/90`; add small support sync notes to [UID:000016], [UID:0000HV], and [UID:0001SM]. No split, rename, owner change, or manual coverage edit is required.
- Confidence: high for function range, vtable owner, emitter route, callee/helper roles, exact coordinate arithmetic, resource id, and overlay centering behavior; medium-high for exact original source spelling of `Browser +0x222` and the browser overlay constants.

## Target

- Target UID: `00032T`
- Target path: `by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, Not-Covered Files - Reconstructable, `85/88`, reports `0`.
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:000016`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000016`, blank formal C++.
- Current generated coverage state: `auto-generated/-ag-coverage-report-by-memory.md` lists `emits_code:false` for [UID:00032T].

## Current Target State

[UID:00032T] already has the correct exact range, owner, parent inventory, Browser field read, shared global consumer caveat, and main callee list. The page is still a non-emitting target only because the formal C++ block is blank. The current item summary says final C++ remains blank until overlay string/style names and drawing helper names are finalized.

That blocker is stale after the current support docs:

- [UID:00040P] emits `LanguageMan::GetLocalizedString(int stringId) const` for `0x004f0350`.
- [UID:00016C] emits GrafPort text helpers including `GetTextWidth`, `GetLineHeight`, and `DrawWideText`.
- [UID:000162] documents `0x004b9600` as `MoveTo` and `0x004b9680` as the primary text color setter at `GrafPort +0x7c`.
- [UID:0001SM] still treats `236` and `128` as provisional constants, not a proven enum, but that does not block method-body C++ if the values remain local named constants or documented numeric constants.

## Evidence Checked

- Required instructions: Agent-B006 `goal.md`, `ntk-b-agent-workflow`, `b-agent-research-and-implementation-workflow.md`, `score-blocker-audit-standard.md`, `b-agent-report-template.md`, and relevant `by-structure.md` owner/emitter/C++ gate text.
- Target/support docs: [UID:00032T], [UID:000016] `BrowserControlPaneOld`, [UID:0000ZF] `BrowserOleLegacyAndHelpers`, [UID:0001SM] `BrowserOverlayStyle`, [UID:000013] `Browser`, [UID:0000HV] `Browser`, [UID:000162] `GrafPortDrawStateAccessors`, [UID:00016C] `GrafPortTextRunHelpers`, [UID:00040P] `LanguageManGetLocalizedString`, [UID:0000RC] `g_pLanguageMan`, and [UID:0000S7] `g_pScreenPane`.
- Generated/tracker docs: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `project-level/-auto-completion-stats.md`.
- Existing report searches performed with `rg` terms: `00032T`, `0x0046f220`, `46f220`, `BrowserControlPaneOldDrawStatusOverlay`, `DrawStatusOverlay`, `BrowserControlPaneOld`, `BrowserOleLegacyAndHelpers`, `BrowserOverlayStyle`, `0x006137c4`, `0x004f0350`, `0x004baa70`, `0x004baaa0`, `0x004b9600`, `0x004b9680`, `0x004bab70`, `67A750`, and `67A7CC`.
- Relevant report leads opened: B002 Browser empty-emitter family report, B001 Browser/OLE split report, B001 GrafPort text-helper report, and B002 [UID:00032U] old-pane `DispatchMessage` report.
- Fresh 2026-07-02 IDA MCP evidence from `supervisor_resume_20260629`: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, bounded `disasm`, bounded `entity_query`, and `int_convert`. Final accepted calls were schema-current and narrow: exact addresses `0x0046f220`, `0x0046f30f`, `0x0046f310`; vtable-name window `0x00613780-0x00613830` with `count=50`; disassembly capped at `max_instructions=120`; numeric conversion inputs explicitly sized to two bytes. No broad search, batch analysis, callgraph, IDB write, or report execution was run.
- Resource evidence: read-only extraction of the documented `STR.RES` span in `E:\2026\Resources\Read_Only\NexusTK\Data\baram.dat` at offset `11,268,984`, size `7,058`, confirming zero-based id `236` / `0xec` as current text `Please wait for a while...`; this is resource-owned payload evidence and should not be hard-coded in source.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID00032T is an eligible source-bearing method: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000016`, valid route through `BrowserControlPaneOld` to Browser source root, and `(85 + 88) / 2 = 86.5 > 85`. | High | Target metadata, [UID:000016], [UID:0000HV], by-structure C++ gate. | UID00032T metadata/reconstruction notes | incorporate | applied: UID00032T remains reconstructable with owner/emitter [UID:000016] and formal C++ populated. |
| C02 | The function range is exactly `0x0046f220-0x0046f30f`, `0xef` / 239 bytes (Verified with int_convert.py), followed by non-function boundary at `0x0046f30f` and next function at `0x0046f310`. | High | MCP `lookup_funcs`, `disasm`, current target and parent docs. | UID00032T IDA Evidence | incorporate | applied: target IDA Evidence records range, size, boundary, and next function. |
| C03 | Incoming reachability is a BrowserControlPaneOld vtable/data xref at `0x006137c4`; there are no direct code callers in `analyze_function`. | High | MCP `analyze_function` xrefs and bounded `entity_query` over `0x00613780-0x00613830`. | UID00032T ownership/vtable notes; UID000016 method row | incorporate | applied: target records no direct code callers and vtable slices; UID000016 method row marks exact child source-ready. |
| C04 | The method gates drawing on `m_browser` at outer `+0x110` / 272 (Verified with int_convert.py), then Browser byte `+0x222` / 546 (Verified with int_convert.py). | High for offsets; medium-high for final field name | MCP disasm and Browser class docs. | UID00032T behavior; UID000016 layout notes | incorporate | applied: target evidence/reconstruction notes record both offsets and retain field-name caveat. |
| C05 | The overlay text id is `0xec` / 236 (Verified with int_convert.py), fetched through `g_pLanguageMan->GetLocalizedString(236)`; current `STR.RES` payload text for id 236 is `Please wait for a while...`. | High | MCP disasm/decompile; [UID:00040P]; [UID:0000RC]; [UID:0001SM]; read-only `baram.dat` STR.RES extraction. | UID00032T behavior; UID0001SM value map; UID0001RP high-value id table | incorporate | applied: target, UID0001SM, and UID0001RP high-value id table record the resource evidence and preserve lookup-not-hardcoded policy. |
| C06 | The method measures the localized string and line height through `g_pScreenPane` as a GrafPort/ScreenPane receiver, computes pane-center X/Y from this pane's `this+0x44` rectangle fields, then calls `this->MoveTo(x, y)`. | High | MCP disasm/decompile; [UID:00016C]; [UID:000162]; [UID:0000S7]. | UID00032T behavior/C++ | incorporate | applied: target C++ and evidence use `g_pScreenPane`, centered `m_bounds`, and `MoveTo`. |
| C07 | The style/color immediate is `0x80` / 128 (Verified with int_convert.py) passed to `0x004b9680`, now best documented as `GrafPort::SetTextColor` / primary text-color setter, not a Browser-owned draw-state helper. | Medium-high | MCP disasm; [UID:000162]; [UID:0001SM]. | UID00032T behavior; UID0001SM declaration boundary | incorporate | applied: target C++ uses `SetTextColor(128)`; UID0001SM preserves provisional constant classification. |
| C08 | Final drawing is `GrafPort::DrawWideText(statusText, wcslen(statusText))`; the body computes UTF-16 length inline before calling `0x004bab70`. | High | MCP disasm/decompile; [UID:00016C]. | UID00032T behavior/C++ | incorporate | applied: target C++ calls `DrawWideText(statusText, static_cast<int>(wcslen(statusText)))`. |
| C09 | Owner/emitter route remains [UID:000016] `BrowserControlPaneOld`; [UID:0000ZF] remains parent-blank/non-emitting split inventory; [UID:0000HV] remains the source root. | High | Current target, parent, class, and file docs; B001/B002 report leads. | UID00032T metadata; UID000016/UID0000HV support notes | incorporate | applied: owner/emitter unchanged; UID000016 and UID0000HV synchronized. |
| C10 | Recommended score after implementation is `88/90`, not higher, because behavior/helper names are now source-ready but final original names for `Browser +0x222`, `kBrowserStatusStringId`, `kBrowserOverlayTextColor`, and exact `RectBounds` member spelling remain inferred. | Medium-high | Score blocker audit, current docs, live MCP evidence. | UID00032T score rationale | incorporate | applied: target score is `88/90` and score rationale preserves the limiting caveats. |

## Positive Evidence Summary

- MCP `server_health` was `ok` for `supervisor_resume_20260629`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. `idb_list` showed one active adopted worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` with worker PID `14860`.
- MCP `lookup_funcs` reports `sub_46F220` at `0x0046f220`, size `0xef` / 239 bytes (Verified with int_convert.py); `0x0046f30f` is not a function, and the next function starts at `0x0046f310`.
- MCP `analyze_function 0x0046f220` reports prototype `void __thiscall(int this)`, size `239`, five basic blocks, cyclomatic complexity `3`, callees `0x004f0350`, `0x004baa70`, `0x004baaa0`, `0x004b9600`, `0x004b9680`, and `0x004bab70`, no direct code callers, and a data xref from `0x006137c4`.
- Bounded `entity_query` over `0x00613780-0x00613830` lists BrowserControlPaneOld vtable slices at `0x00613780`, `0x006137e8`, `0x00613818`, and `0x00613824`, followed by Browser vtable data at `0x00613830`, confirming the vtable neighborhood.
- Disassembly confirms the exact behavior: load `m_browser` from `this+0x110`, compare byte `[m_browser+0x222]` to zero, load `g_pLanguageMan` and `g_pScreenPane`, push `0xec`, call `GetLocalizedString`, copy rectangle bytes from `this+0x44`, measure string width and line height through `g_pScreenPane`, compute signed centered X/Y as `(left + right) / 2 - textWidth / 2` and `(top + bottom) / 2 - lineHeight / 2`, call `this->MoveTo`, set this pane's text color/style `0x80`, compute `wcslen`, and call `this->DrawWideText`.
- Read-only resource extraction confirms the current payload row for zero-based id `236` / `0xec` is `Please wait for a while...`; the source should keep a string-id lookup such as `kBrowserStatusStringId`/`236`, not embed that English text.

## IDA MCP Facts

- Function/range facts: `sub_46F220`, range `0x0046f220-0x0046f30f`, size `0xef` / 239 bytes (Verified with int_convert.py), 84 instructions in MCP disassembly.
- Data/vtable facts: incoming xref to the function is data at `0x006137c4`, inside BrowserControlPaneOld vtable data.
- Global facts: the function reads `dword_67A750` / `g_pLanguageMan` at `0x0046f23f` and `dword_67A7CC` / `g_pScreenPane` at `0x0046f246`.
- Field facts: `this+0x110` / 272 (Verified with int_convert.py) is the `Browser *m_browser` pointer already documented on [UID:000016]; Browser `+0x222` / 546 (Verified with int_convert.py) is the display/status byte currently documented on [UID:000013].
- Literal facts: `0xec` / 236 (Verified with int_convert.py) is the localized string id; `0x80` / 128 (Verified with int_convert.py) is the text-style/color argument.
- Negative MCP facts: `analyze_function` reports no direct code callers; `lookup_funcs` says `0x0046f30f` is not a function. No current MCP listener/process failure occurred during the accepted evidence pass.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046f220-0x0046f30f` | [UID:00032T] `by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md` | Old-pane overlay draw method | true | [UID:000016] `BrowserControlPaneOld` | current `85/88`; recommend `88/90` | exact method; first-draft C++ recommended |
| `0x0046f30f-0x0046f310` | covered by [UID:0000ZF] parent inventory | one-byte boundary/padding before next old-pane method | false | none | parent inventory `91/92` | no source emission |
| `0x0046f310-0x0046f47b` | [UID:00032U] `BrowserControlPaneOldHandleBrowserMessage` | next old-pane message method/table | true | [UID:000016] | current implemented `88/91` | separate emitted child |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006137c4` | data xref to `0x0046f220` | BrowserControlPaneOld vtable slot; supports class-method ownership. |
| `0x004f0350` | callee | [UID:00040P] `LanguageMan::GetLocalizedString(int stringId) const`. |
| `0x004baa70` | callee | [UID:00016C] `GrafPort::GetTextWidth(const wchar_t *text)`. |
| `0x004baaa0` | callee | [UID:00016C] `GrafPort::GetLineHeight()`. |
| `0x004b9600` | callee | [UID:000162] `GrafPort::MoveTo(int x, int y)`. |
| `0x004b9680` | callee | [UID:000162] primary text-color setter; use `SetTextColor(128)` or documented equivalent. |
| `0x004bab70` | callee | [UID:00016C] `GrafPort::DrawWideText(const wchar_t *text, int charCount)`. |

## Ranked Ownership Analysis

### 1. [UID:000016] BrowserControlPaneOld

- Evidence for: vtable data xref at `0x006137c4`; [UID:000016] class layout has `m_browser` at `+0x110`; sibling old-pane methods [UID:00032S] and [UID:00032U] are already BrowserControlPaneOld children; the body uses the pane receiver rectangle and GrafPort inherited drawing state.
- Evidence against: it consumes Browser object state and shared UI globals/helpers, but those are dependencies rather than direct ownership.
- Decision: accepted direct owner and emitter.

### 2. [UID:000013] Browser

- Evidence for: the gate byte is inside the embedded Browser object at `+0x222`; [UID:000013] names this as `m_showBrowserAfterLoad`.
- Evidence against: the executing receiver is the pane; the vtable slot is BrowserControlPaneOld; Browser does not own this pane draw method.
- Decision: reject as direct owner; keep Browser as state dependency.

### 3. [UID:0000HV] Browser file root

- Evidence for: Browser source root owns the broader browser subsystem and receives generated output through [UID:000016].
- Evidence against: file root is the emitter root, not the narrow semantic owner.
- Decision: keep as source-file route only.

### 4. [UID:00005V]/[UID:0000JR] GrafPort

- Evidence for: all draw/layout callees are GrafPort helpers and the method uses inherited GrafPort/pane drawing state.
- Evidence against: the method is not a shared GrafPort helper; it is a BrowserControlPaneOld vtable method that calls GrafPort.
- Decision: reject as owner; preserve as callee/dependency support.

## Source Placement

Recommended placement remains [UID:000016] `BrowserControlPaneOld` emitted under [UID:0000HV] `Browser` / `NexusTK/browser/Browser.cpp`. The broader one-file `Browser.cpp` versus possible `BrowserLegacy.cpp`/`BrowserOld.cpp` split remains a file-level caveat, but it does not block this exact method because [UID:00032S] and [UID:00032U] already emit through the same old-pane class/source route.

Rejected placements:

- [UID:0000ZF] parent aggregate: rejected because it is an intentional parent-blank non-emitting split inventory.
- `render/GrafPort.cpp`: rejected because GrafPort owns the helpers, not the BrowserControlPaneOld method.
- `LanguageMan.cpp`: rejected because language lookup is only a callee.

## Heuristic / Inference Reanalysis And Validation

- Helper/string names: resolved enough for formal C++. `LanguageMan::GetLocalizedString` and the relevant GrafPort text helpers have accepted source-facing names and, for [UID:00040P]/[UID:00016C], formal C++ already exists.
- Overlay constants: `236` should remain a localized status-string id, preferably `kBrowserStatusStringId` or an equivalent local constant; `128` should remain a draw text-color/style value, preferably `kBrowserOverlayTextColor` or documented numeric `128`. Do not promote [UID:0001SM] into a final enum declaration solely from this method.
- Browser field `+0x222`: source-facing name is still medium-high confidence, not final original spelling. Current Browser docs use `m_showBrowserAfterLoad`, and `Browser::Invoke` uses it after download-complete handling to show the hosted browser. This old-pane method proves the same byte also gates the visible waiting/status overlay before the hosted page appears. The target should document this as the existing `m_showBrowserAfterLoad` / status-overlay-visible byte rather than inventing a new separate field.
- String id/resource name: `0xec` / 236 (Verified with int_convert.py) is now tied to current `STR.RES` text `Please wait for a while...` by read-only package extraction. The source-facing name should be a browser status/wait string id such as `kBrowserStatusStringId`; the English text remains resource-owned and should not appear as a hard-coded string literal in C++.
- Coordinate arithmetic: the SSE copy from `this+0x44` supplies `left`, `top`, `right`, and `bottom`. The signed divide-by-two sequences implement ordinary C++ integer center math, so the source body should use `((left + right) / 2) - (textWidth / 2)` and `((top + bottom) / 2) - (textHeight / 2)`. No alternate bottom/right exclusive correction is supported by the current body.
- Rectangle fields: MCP copies a 16-byte rectangle at `this+0x44`; the calculation uses left+right and top+bottom halves. The target can use the established pane bounds/member wording, but the report should not require final original `RectBounds` member spelling beyond `left/top/right/bottom`.
- Shared globals: `g_pLanguageMan` and `g_pScreenPane` are consumers/dependencies only. The method does not own their storage.
- Wave2/Wave3 artifacts: generated owner names and old `SetBkColor` wording were treated as leads only. Current GrafPort docs reject stale background-color-only naming for this call route.

## Negative Evidence Summary

- No direct code caller was reported by MCP `analyze_function`; the method is reached by vtable dispatch.
- `Browser` ownership is not supported by the vtable slot, even though Browser state is read.
- `BrowserOverlayStyle` is not yet proven to be a true original enum; the source should not emit a broad enum declaration from this method alone.
- `g_pScreenPane` is not owned by Browser or BrowserControlPaneOld; it remains ScreenPane-owned shared UI state.
- Current schema-corrected MCP calls did not leave an operational blocker. Earlier wrong-argument `entity_query`/`int_convert` attempts were corrected against `tools/list` and retried narrowly; the accepted evidence pass succeeded.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, has a valid emitter route, average score is above the current gate, and the callee names/source route are now strong enough.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:00032T] after supervisor acceptance. If the supervisor prefers to avoid magic numbers, `236` can be replaced by an existing browser-local `kBrowserStatusStringId` and `128` by `kBrowserOverlayTextColor`; this report does not require adding new declarations before the method emits.

```cpp
void BrowserControlPaneOld::DrawBrowserStatusOverlay()
{
    if (!m_browser->m_showBrowserAfterLoad) {
        return;
    }

    const wchar_t *statusText = g_pLanguageMan->GetLocalizedString(236);

    const int textWidth = g_pScreenPane->GetTextWidth(statusText);
    const int textHeight = g_pScreenPane->GetLineHeight();

    const int x = ((m_bounds.left + m_bounds.right) / 2) - (textWidth / 2);
    const int y = ((m_bounds.top + m_bounds.bottom) / 2) - (textHeight / 2);

    MoveTo(x, y);
    SetTextColor(128);
    DrawWideText(statusText, static_cast<int>(wcslen(statusText)));
}
```

- Reason it preserves behavior: the code matches the MCP disassembly order and data flow: `+0x222` gate, localized id `236` whose current resource text is `Please wait for a while...`, width and line-height measurement through `g_pScreenPane`, signed centered coordinate math, `this->MoveTo`, this pane's color/style `128`, UTF-16 length scan, and `this->DrawWideText`.
- Reason it matches plausible original source: it is a short class method in the browser pane source, calling established shared `GrafPort` and `LanguageMan` helpers instead of decompiler labels or raw function names.
- Inferred names used: `DrawBrowserStatusOverlay`, `m_browser`, `m_showBrowserAfterLoad`, `m_bounds`, `g_pScreenPane->GetTextWidth`, `g_pScreenPane->GetLineHeight`, `MoveTo`, `SetTextColor`, and `DrawWideText`. `m_browser` is strong; `m_showBrowserAfterLoad` and `m_bounds` are medium-high existing support names. `SetTextColor(128)` should be documented as a source-facing GrafPort text-color/style call, not proof of an original named constant.
- Reason code should not remain blank: the previous blockers named in the current page have been researched. Helper names are no longer raw/provisional enough to block first-draft C++; the remaining names can be documented as inferred caveats without changing behavior.

## Recommended Target Doc Changes

Target path: `by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md`

- Change score to `COMPLETION:88`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:000016`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000016`, and blank emitter position.
- Replace the blank formal C++ block with the first-draft `BrowserControlPaneOld::DrawBrowserStatusOverlay()` text above.
- Add current MCP evidence: session `supervisor_resume_20260629`, `server_health` ok, active adopted worker PID `14860`, `lookup_funcs` size `0xef`, no function at `0x0046f30f`, next function `0x0046f310`, data xref `0x006137c4`, and 84-instruction disassembly sequence.
- Update reconstruction notes: the old "C++ remains blank until overlay string/style names and drawing helper names are finalized" is superseded. Preserve caveats that `236`/`128` are still provisional constants and `Browser +0x222` final member name remains inferred.
- Add negative evidence: no direct code callers; the method consumes `g_pLanguageMan`, `g_pScreenPane`, and GrafPort helpers but does not own them.
- Add a resource note that current `STR.RES` zero-based id `236` / `0xec` decodes as `Please wait for a while...`, but source must keep the localized string lookup instead of hard-coding that text.

## Recommended Support Doc Changes

### [UID:000016] `by-class/BrowserControlPaneOld.md`

- Update the [UID:00032T] method row to say first-draft C++ is now recommended/ready for `DrawBrowserStatusOverlay`.
- Replace any class-level implication that draw helper names block [UID:00032T] with the narrower caveat: `Browser +0x222` and overlay constant names remain inferred, but helper calls are source-ready.

### [UID:0000HV] `by-file/Browser.md`

- Add a short source-quality sync note that [UID:00032T] should emit the old-pane status overlay draw method under the existing Browser source root.
- Preserve the broader `Browser.cpp` versus possible legacy split caveat as nonblocking for this exact child.

### [UID:0001SM] `by-type/by-enum/BrowserOverlayStyle.md`

- Add a note that the [UID:00032T] reanalysis keeps `236` as a localized status-string id and `128` as a text-color/style immediate. It does not prove a final enum; C++ can use local constants or numeric arguments with documented caveats.

### [UID:0001RP] `by-resource/str-res-localized-strings.md`

- Optional support sync if the supervisor wants the high-value id table extended: add zero-based id `236` / `0xec` as current text `Please wait for a while...`, proven by [UID:00032T]'s `LanguageMan::GetLocalizedString(236)` call and the documented `baram.dat` `STR.RES` payload extraction. This is not required for target C++ emission because the resource page already documents the loader/payload contract.

No support doc change is required for [UID:000162], [UID:00016C], [UID:00040P], [UID:0000RC], or [UID:0000S7] unless the supervisor wants a back-reference to this target; current detail is already same-or-greater for their helper/global roles.

## Score And Metadata Recommendation

- Current score/metadata: `85/88`, owner [UID:000016], reconstructable true, emitter [UID:000016], blank C++.
- Recommended score/metadata: `88/90`, owner/emitter unchanged, formal C++ populated.
- Score rationale: completion can rise because the page can now document exact current MCP behavior, resolved helper names, the formal C++ block, and implementation-ready support sync. Confidence can rise because vtable ownership, range, callee roles, constants, and centered draw behavior are confirmed. Do not raise above `90` because original constant names, exact `Browser +0x222` field name, and exact pane rectangle member spelling remain inferred.
- Score-limiting blockers researched:
  - Overlay helper names: resolved with [UID:000162], [UID:00016C], and [UID:00040P].
- String/style constants: resolved to safe local/browser-use constants, but true enum proof remains unavailable; not a C++ blocker.
- Browser field semantics: resolved to existing `m_showBrowserAfterLoad` / status-overlay-visible byte caveat; not a C++ blocker if documented.
- Owner/emitter route: confirmed unchanged through [UID:000016] and [UID:0000HV].

## Open Questions With Attempted Resolution

- Is `BrowserOverlayStyle` a true enum? Current evidence says no. Use local constants or documented numeric values until a broader resource/style audit proves a declaration.
- What is the exact original name of Browser byte `+0x222`? Current Browser docs use `m_showBrowserAfterLoad`; this method proves overlay/status draw gating for the same byte. Keep that name with a status-overlay caveat rather than inventing a second field.
- Is the final source file exactly `Browser.cpp` or a legacy-browser split? Current file-level docs keep `Browser.cpp` as the source root and treat `BrowserLegacy.cpp`/`BrowserOld.cpp` as plausible but unproven. This does not affect the exact child route.
- Does id `236` have a current resource text? Yes: the documented `STR.RES` payload row decodes to `Please wait for a while...`. The source should still use `GetLocalizedString(236)` or an equivalent named id constant rather than hard-coding the text.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory\0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md --apply --queue-timeout 240 --wait-generated`
  - command_id `000000004349`, timestamp `2026-07-02T06:31:59-04:00`, exit `0`, `ok: 1`, generated refresh completed. Validator refreshed registry/autogen state and projected stats.
- `python .\tools\validator.py --mode file --file by-class\BrowserControlPaneOld.md --apply --queue-timeout 240`
  - command_id `000000004354`, timestamp `2026-07-02T06:32:22-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-file\Browser.md --apply --queue-timeout 240`
  - command_id `000000004359`, timestamp `2026-07-02T06:32:36-04:00`, exit `0`, `ok: 1`, generated refresh deferred. The validator reported pre-existing `missing_ref_uid` warnings for unrelated Browser rows such as `000408`, `00040B`, `0003OH`, `000407`, `000409`, `00040A`, and `00040C`; no UID00032T-specific failure.
- `python .\tools\validator.py --mode file --file by-type\by-enum\BrowserOverlayStyle.md --apply --queue-timeout 240`
  - command_id `000000004361`, timestamp `2026-07-02T06:32:49-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- `python .\tools\validator.py --mode file --file by-resource\str-res-localized-strings.md --apply --queue-timeout 240`
  - command_id `000000004362`, timestamp `2026-07-02T06:32:58-04:00`, exit `0`, `ok: 1`, generated refresh deferred. The validator reported pre-existing `missing_ref_uid` warnings for UID `0003O5`; no UID00032T-specific failure, and it added a reference index entry from the resource page to UID00032T.
- Generated freshness check: `auto-generated/NexusTK/browser/Browser.cpp` header reports validator command id `000000004355` and refreshed-at `2026-07-02T06:32:31-04:00`, newer than the target validator command timestamp. UID00032T appears at generated lines 425-426 as `void BrowserControlPaneOld::DrawBrowserStatusOverlay()` with `Completion:88 | Confidence:90`, not an empty-emitter marker.
- No `execute_report`, dry-run report lifecycle variant, registry lifecycle command, archive/move command, generated-file manual edit, IDA DB write, or MCP restart/kill command was run.

## Changed Files

- Modified: `tools/leaser/Agents/Agent-B006/research/00032T-BrowserControlPaneOldDrawStatusOverlay-source-quality.md`
- Modified: `by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md`
- Modified: `by-class/BrowserControlPaneOld.md`
- Modified: `by-file/Browser.md`
- Modified: `by-type/by-enum/BrowserOverlayStyle.md`
- Modified: `by-resource/str-res-localized-strings.md`
- Validator-owned generated/tool-state files were changed only by scoped validators; no manual generated edits were made.
- Leases: B006 leased the five by-* target/support docs before editing, including the resource file. Final cleanup found no active B006 leases; the read-only `current_leases.md` report shows only stale Supervisor rows from 2026-06-18 and no B006 entries.
- Report execution: not performed. B agents must not run `tools/validator.py execute_report ... --apply`.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Accepted by supervisor callback on 2026-07-02.
- [x] Update target doc `by-memory/0x0046f220-0x0046f30f.BrowserControlPaneOldDrawStatusOverlay.md`.
- [x] Change UID00032T metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep owner [UID:000016], reconstructable true, emitter [UID:000016], and blank emitter position.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block for `BrowserControlPaneOld::DrawBrowserStatusOverlay()` from this report.
- [x] Add current MCP evidence: healthy session, active adopted worker PID `14860`, function size/range, vtable xref `0x006137c4`, no code callers, disassembly behavior, constants, globals, callees, and schema-current final-call success.
- [x] Replace stale blank-C++ blocker text with the resolved helper-name state and remaining caveats for constants/field names.
- [x] Add resource evidence that `STR.RES` zero-based id `236` / `0xec` currently decodes to `Please wait for a while...`, while preserving that the C++ must call `GetLocalizedString(236)` or a named id constant rather than hard-code the text.
- [x] Preserve negative evidence: no direct code callers; Browser/GrafPort/LanguageMan/ScreenPane are dependencies, not direct owners.
- [x] Update [UID:000016] `BrowserControlPaneOld.md` method/source-quality notes for UID00032T first-draft readiness.
- [x] Update [UID:0000HV] `Browser.md` with a short source-quality sync for UID00032T under the Browser source root.
- [x] Update [UID:0001SM] `BrowserOverlayStyle.md` to preserve `236` as localized status-string id and `128` as text-color/style immediate without promoting a final enum.
- [x] Update [UID:0001RP] `str-res-localized-strings.md` high-value id table with id `236` / `0xec` -> `Please wait for a while...`. Proof: resource file existed and now records UID00032T provenance plus lookup-not-hardcoded policy.
- [x] Confirm no support changes are required for [UID:000162], [UID:00016C], [UID:00040P], [UID:0000RC], or [UID:0000S7] because same-or-greater helper/global detail is already present.
- [x] Run scoped validators after callback edits: target `000000004349`, class `000000004354`, file `000000004359`, enum `000000004361`, and resource `000000004362`.
- [x] Inspect generated `auto-generated/NexusTK/browser/Browser.cpp` freshness after the target validator; header `000000004355` / `2026-07-02T06:32:31-04:00` is newer than target validator timestamp, and UID00032T emits under the BrowserControlPaneOld section.
- [x] No manual edits to generated reports, manual `-coverage-report.md` files, validator/tool state, archives, queue files, lock files, or IDA DB.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated Browser.cpp freshness checked and recorded.
- [x] Remaining unapplied accepted items listed with exact blocker: no accepted required target/support item remains unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004365","destination_path":"executed-b-agent-research/B006/00032T-BrowserControlPaneOldDrawStatusOverlay-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00032T-BrowserControlPaneOldDrawStatusOverlay-source-quality.md","timestamp":"2026-07-02T06:35:36-04:00","uid":"00032T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
