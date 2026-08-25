** TARGET-REPORT-UID:0004CF **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B009 Report - [UID:0004CF] ExchangeAlertPaneConstructor Source Quality

## Assignment

- Assignment ID: `B009-report-0004CF-ExchangeAlertPaneConstructor-by-memory-20260701`
- Mode: report-only research.
- Target: [UID:0004CF] `by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md`
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Report path: `tools/leaser/Agents/Agent-B009/research/0004CF-ExchangeAlertPaneConstructor-by-memory-source-quality.md`

No target/support `by-*` docs, generated files, coverage reports, validator state, supervisor ledgers, archives, by-project-structure docs, or IDA DB state were edited during this report-only pass.

## Current Target State

- Current metadata: `COMPLETION:84`, `CONFIDENCE:86`, `CANONICAL_OWNER:00004Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.
- Current formal C++ block is blank.
- Current item summary records proven range, callers, vtable stores, singleton setup, alert text/button construction, centering, and parent pointer storage, but still uses the older implicit non-emitting disposition that cited unresolved inherited helper/source-layout quality. This revision supersedes that broad blocker with the per-helper audit and target-specific no-code proof below.
- Tracker state: `auto-generated/-ag-research-tracker.md` lists [UID:0004CF] at `84/86`, combined `85.0`, reconstructable `true`, reports `0`.
- Coverage state: `auto-generated/-ag-memory-coverage.md` lists [UID:0004CF] as `non-emits` with owner `00004Q`.
- Current generated lead: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` is current to validator command `000000004072` at `2026-07-01T17:17:26-04:00`; it contains [UID:00004Q], [UID:0004CG], [UID:0004CH], [UID:00033Z], vtable comments, and `new ExchangeAlertPane(message, this, g_szDialogOk, 0)` call sites, but no [UID:0004CF] marker because the target has blank emitters.

## MCP Availability And Discipline

- Live MCP was available through JSON-RPC at `http://127.0.0.1:13337/mcp`.
- `idb_list` returned one active IDB session, `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, backend `worker`, pid/worker pid `14860`.
- `server_health(database=supervisor_resume_20260629)` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- MCP calls were narrow and paged: `lookup_funcs` for specific addresses, `decompile` for one function at a time, `disasm` paged by offsets, capped `xrefs_to`, capped `callees`, and one successful narrow `get_bytes` read.
- A parallel multi-region `get_bytes` request and a concurrent signature request timed out once. Immediate follow-up `server_health`, `idb_list`, and single-region `get_bytes(0x004b0819, 7)` succeeded, so this was not treated as MCP unavailable or a repeated MCP-dependent blocker.

## Evidence Checked

### Current by-* docs

- Target [UID:0004CF] `by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md`.
- Owner class [UID:00004Q] `by-class/ExchangeAlertPane.md`, currently `88/90`, declaration-only `class ExchangeAlertPane;` plus `[[CHILDREN]]`, method row saying constructor has no emitted body.
- Source file [UID:0000J9] `by-file/ExchangeDialog.md`, currently documenting the constructor child as blank/non-emitting and intentionally absent from generated output.
- Split inventory [UID:00033W] `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md`.
- Sibling emitting children [UID:0004CG] `ExchangeAlertPaneOnButtonClick` and [UID:0004CH] `ExchangeAlertPaneSingletonClearHelper`.
- Singleton docs [UID:0000QV] `by-global/g_pExchangeAlertPane.md` and [UID:0002VZ] `by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md`.
- Shared OK literal [UID:0001OC] `by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md`.
- Helper/support docs for DialogPane, ForcedInformMessageDialog, BackPane bounds, and current generated ExchangeDialog output.
- Revision support docs for the named blockers: [UID:00015S] `RectGeometryHelpers`, [UID:00011I] `StaticTextControlPaneConstructor`, `by-class/TextButtonControlPane.md`, `by-file/TextButtonControlPane.md`, [UID:00016C] `GrafPortTextRunHelpers`, [UID:000161] `BackPaneGetBounds`, [UID:0001BC] `GetMemoryMan`, [UID:0001TO] `AlertPaneLayout`, and active DialogPane helper pages.

### Existing and executed reports searched

Required search terms were used against `executed-b-agent-research` and `tools/leaser/Agents`: `0004CF`, `0x004b0490`, `0x004b0819`, `ExchangeAlertPaneConstructor`, `ExchangeAlertPane`, and `ExchangeDialog`.

Direct target/source-family matches reviewed as leads:

- `executed-b-agent-research/B011/0000J9-ExchangeDialog-empty-emitter-family-source-quality.md`
- `executed-b-agent-research/B015/00014L-ExchangeDialogPacketDispatcher-source-quality.md`
- `executed-b-agent-research/B002/00014O-exchange-dialog-cancel-alert-source-quality.md`
- `executed-b-agent-research/B002/00014P-exchange-dialog-ready-alert-source-quality.md`
- `executed-b-agent-research/B001/00014T-ItemExchangeMixDialogs.md`
- `executed-b-agent-research/B001/00014V-ExchangeDialogTail.md`

Broad `ExchangeDialog` matches also returned many sibling exchange/item-list reports. They were treated as source-family leads only; this report uses current docs and live MCP for the constructor disposition. The most relevant old report is B011's executed ExchangeDialog empty-emitter family report, which created [UID:0004CF] and kept it blank because helper/layout names were then below code gate.

## Live MCP Findings

### Function bounds and split

- `lookup_funcs`:
  - `0x004b0490` -> `sub_4B0490`, size `0x389`.
  - `0x004b0819` -> no function.
  - `0x004b0820` -> `sub_4B0820`, size `0x40`.
  - `0x004b0860` -> `sub_4B0860`, size `0xb`.
  - `0x004b086b` -> no function.
  - `0x004b0870` -> `sub_4B0870`, size `0xb`.
- Local `int_convert.py` confirms `0x389` is `905` bytes and `0x7` is `7` bytes.
- `get_bytes` at `0x004b0819`, size `7`, returned `0xcc 0xcc 0xcc 0xcc 0xcc 0xcc 0xcc`, confirming the constructor's exclusive end and the seven-byte padding before the sibling callback at `0x004b0820`.
- `disasm 0x004b0490` with `max_instructions=120`, paged offsets `0`, `120`, and `240`, reports `350` total instructions for the constructor body. The paged output shows the EH/security-cookie prologue/epilogue and the constructor body ending at `0x004b0816 retn 10h`, followed by padding.

### Constructor behavior

`decompile 0x004b0490` and the paged disassembly prove the constructor body is source-authored UI construction, not compiler-only code:

- Calls `sub_49D8A0` with `word_60DB20`, `-1`, and `0`, matching a `DialogPane` base constructor with an empty title/resource.
- Publishes or clears the active alert singleton at `0x0069b330` through the `this + 0x26c` test/add artifact. Local `int_convert.py` confirms `0x26c` is `620` decimal.
- Writes three ExchangeAlertPane vtables:
  - primary vtable `0x0061a1c0` at object offset `+0x0`;
  - secondary vtable `0x0061a228` at object offset `+0xa0`;
  - tertiary vtable `0x0061a258` at object offset `+0xa4`.
- Calls `sub_516030`, parent origin/offset helper `sub_5447C0`, parent bounds helper `sub_4B8E00`, message width helper `sub_4BAA70`, text height/wrap helper `sub_58EE90`, and rectangle construction helper `sub_4B7C50`.
- Measures/clamps message width with constants `0xf0` (`240`), `0xa0` (`160`), and `0x4a` (`74`) (verified with `tools/int_convert.py` during revision). The all-button/two-button, left-only, and no-button layout paths are visible. The raw disassembly confirms the right-button-only path (`leftButtonText == NULL && rightButtonText != NULL`) loads the low word of the saved `this`/EH local from `[ebp+var_64]` into the width before `sub_58EE90`; all four live ExchangeDialog call sites avoid that unsupported combination by passing an OK left button and null right button.
- Allocates `0x114` (`276`) bytes for the static message control, calls `sub_499030`, and attaches it with `sub_49DC10`.
- Allocates `0x110` (`272`) bytes for each optional button, calls `sub_495040`, and attaches each button with `sub_49DC10`.
- If the left button label exists, calls `sub_49DD80(this, 1)` to focus/select the first control.
- If the right button label exists, calls `sub_49DDD0(this, 2)`; otherwise, if the left label exists, calls `sub_49DDD0(this, 1)`.
- Computes a centered rectangle relative to the parent bounds, calls `sub_49DFD0(this, &rect, 0, 0, unk_69B36C)`, then `sub_49E190(this, 0, 0)` and `sub_49EAC0(this)`.
- Stores the parent pointer at primary object offset `+0x26c` near the end of the constructor.
- Compiler-only lowering present in the body includes the EH frame/security cookie, object cleanup entries, block frees through `sub_4F4AC0`, and cleanup references to the singleton-clear helper. Those should not be expressed as source statements.

### Callers and parameter shape

`xrefs_to 0x004b0490` returned exactly four code xrefs:

- `0x004ad656` in `sub_4AD320`
- `0x004ad775` in `sub_4AD320`
- `0x004ade18` in `sub_4ADD40`
- `0x004adf8d` in `sub_4ADE60`

Current MCP decompiles of the caller helpers prove the best call shape:

- Cancel alert helper `0x004ADD40` decodes packet text, closes the active alert if present, allocates `624` bytes, and calls `sub_4B0490(v4, WideCharStr, this, &off_613A18, 0)`.
- Ready alert helper `0x004ADE60` performs state checks, decodes packet text, closes the active alert through `sub_4B0B20`, allocates `624` bytes, and calls `sub_4B0490(v5, WideCharStr, (_DWORD *)this, &off_613A18, 0)`.
- Packet dispatcher `0x004AD320` has two inline duplicate cases that allocate `624` bytes and call `sub_4B0490(..., message, parent, &off_613A18, 0)`.
- All current call sites pass message text, parent dialog pane, the shared OK label at `0x00613a18`, and a null right-button label.

The best inferred source signature is:

```cpp
ExchangeAlertPane::ExchangeAlertPane(const wchar_t *messageText,
                                     Pane *parentPane,
                                     const wchar_t *leftButtonText,
                                     const wchar_t *rightButtonText);
```

This signature is useful evidence. The revision recheck resolves the named helper/source-layout blockers into source-facing names, but I still do not recommend inserting a constructor body because the binary's unexercised right-button-only branch would require either inventing sane source behavior or deliberately modeling an uninitialized/decompiler-shaped width value.

### Globals, literals, and vtables

- `xrefs_to 0x0069b330` returned the nine expected singleton refs: four alert close checks/read paths, constructor publish/clear at `0x004b04ff` and `0x004b0506`, clear helper `0x004b0860`, scalar deleting destructor clear `0x004b09d6`, and close-active read `0x004b0b20`.
- `xrefs_to` for vtables `0x0061a1c0`, `0x0061a228`, and `0x0061a258` returns only constructor stores at `0x004b0514`, `0x004b051a`, and `0x004b0524`, respectively. This supports constructor ownership and compiler-emitted vtable data, not literal vtable arrays.
- `0x00613a18` is a broad shared OK literal. Existing [UID:0001OC] already documents it as pooled UTF-16 `OK`; the constructor should reference it through call-site/source text, not own it as a new global.
- `0x0060db20` is the shared empty-string resource used by the DialogPane base constructor, not a constructor-local string.
- `0x0069b36c` is a broad shared layer/global context used by `DialogPane::OnCreate` callers, not constructor-owned storage.

## Heuristic / Inference Reanalysis And Validation

### Revision helper/source-layout blocker audit

The rejected report's broad helper/layout caveat is superseded. Current by-* docs plus live MCP resolve the named blockers as follows:

| Named item | Current evidence checked | Revised source-facing disposition |
| --- | --- | --- |
| `sub_5447C0` / `0x005447c0` | Live `lookup_funcs` reports size `0x33` / 51 bytes (verified with `tools/int_convert.py`). Live `decompile` reads the pane root/owner pointer at receiver `+0xa8`, calls the owner-relative conversion helper when present, otherwise writes `(0,0)`. Current docs in `by-class/FittingRoomScrollPane.md`, `by-class/ScrollNewGroupPane.md`, and emitted help-pane constructors use `GetScreenOffset` / `GetScreenOrigin`. | Resolved for this target as `layoutReference->GetScreenOffset(&layoutOffset)`. Not a blocker. |
| `sub_4B7C50` / `0x004b7c50` | Live `lookup_funcs` reports size `0x1f` / 31 bytes (verified with `tools/int_convert.py`). Live `decompile` writes four dwords to the output record in `left, top, right, bottom` order. [UID:00015S] `RectGeometryHelpers` names this cdecl helper `InitRectBounds`. | Resolved as `InitRectBounds(RectBounds *bounds, int left, int top, int right, int bottom)`. Not a blocker. |
| `sub_499030` / `0x00499030` | Live `lookup_funcs` reports size `0x1bc` / 444 bytes (verified with `tools/int_convert.py`). Live target disassembly pushes `0, 0, &textBounds, 0, 0x80, 1, messageText`, uses a `0x114` / 276-byte allocation (verified with `tools/int_convert.py`), then calls `sub_499030`. [UID:00011I] and `by-class/StaticTextControlPane.md` identify the callee as `StaticTextControlPane::StaticTextControlPane`. | Resolved as construction of a `StaticTextControlPane` for the message body. Not a blocker. |
| `sub_495040` / `0x00495040` | Live `lookup_funcs` reports size `0xef` / 239 bytes (verified with `tools/int_convert.py`). Live target disassembly uses `0x110` / 272-byte allocations (verified with `tools/int_convert.py`) and passes a label plus bounds pointer. `by-class/TextButtonControlPane.md`, `by-file/TextButtonControlPane.md`, and [UID:000118] identify the callee as `TextButtonControlPane::TextButtonControlPane`. | Resolved as `new TextButtonControlPane(labelText, &buttonBounds)`. Not a blocker. |
| `sub_4BAA70` / `0x004baa70` | Live `lookup_funcs` reports size `0x2e`; live `decompile` computes `wcslen(text)` and forwards to `0x004ba9a0`. [UID:00016C] `GrafPortTextRunHelpers` has populated formal C++ for `GrafPort::GetTextWidth(const wchar_t *text)` and the counted overload. | Resolved as `GetTextWidth(messageText)` / `GrafPort::GetTextWidth(const wchar_t *)`. Not a blocker. |
| `sub_58EE90` / `0x0058ee90` | Live `lookup_funcs` reports size `0xc7` / 199 bytes (verified with `tools/int_convert.py`). Live `xrefs_to` returns exactly three code callers: base `AlertPane`, this `ExchangeAlertPane`, and `BlueAlertPane`. Live `decompile` allocates a 372-byte text pane, constructs it with width/height arguments based on the supplied content width, sets the text, returns `bottom - top`, then deletes the temporary pane. Current active docs only mention wrapped-height behavior at class level; old `by-memory/-report.old.md` lead names it `MeasureAlertTextHeight_58EE90`. | Resolved as shared alert-family `MeasureAlertTextHeight(const wchar_t *text, int contentWidth)` / `MeasureWrappedAlertTextHeight`. Lack of an exact active helper page is a support-doc gap only; it no longer justifies generic no-code by itself. |
| `sub_4B8E00` / `0x004b8e00` | Live `lookup_funcs` reports size `0x11` / 17 bytes (verified with `tools/int_convert.py`). Live `decompile` copies the 16-byte rectangle at receiver `+0x44` into the caller output. [UID:000161] already emits `RectBounds *BackPane::GetBounds(RectBounds *outBounds) const`. | Resolved for this target as the layout reference bounds accessor, source-shaped as `layoutReference->GetBounds(&referenceBounds)` even though the physical helper page is `BackPane::GetBounds`. Not a blocker. |
| `sub_516030` / `0x00516030` | Live `lookup_funcs` reports size `0x6`; live `decompile` returns `unk_69B4FC`. `by-class/MemoryMan.md` and [UID:0001BC] identify it as file-level free helper `GetMemoryMan()`. | Resolved as `GetMemoryMan()`. The target's standalone call is a dependency/touch before heap construction, not an ownership blocker and not a reason to emit raw code. |
| `sub_49D8A0` / `0x0049d8a0` | Live `lookup_funcs` reports size `0x148` / 328 bytes (verified with `tools/int_convert.py`). Live `decompile` calls Pane/Dialog construction, installs `DialogPane` vtables, increments `g_activeDialogCount`, copies the title string, seeds control/default state, and stores the short style/control argument. [UID:00003T] / [UID:00012S] document the DialogPane constructor/helper family. | Resolved for this target as the base initializer `DialogPane(L"", -1, false)`. Not a blocker. |
| `+0x26c` member store | Live target decompile stores `layoutReference` at dword index `155`, byte offset `0x26c` / 620 (verified with `tools/int_convert.py`) after `SlideOpenVertical`. [UID:0001TO] `AlertPaneLayout` names the analogous alert-family field `m_layoutReference` and rejects owner/parent names because the pointer is used as a layout anchor/reference. `by-class/ExchangeAlertPane.md` currently keeps only a forward declaration and `[[CHILDREN]]`. | Resolved as `ExchangeAlertPane::m_layoutReference` / layout-anchor reference. Class declaration output may remain forward-only, but target prose and no-code proof should use this name instead of generic parent pointer. |
| right-button-only width path | Live target disassembly at `0x004b05b4-0x004b05d4` proves that the branch `leftButtonText == NULL && rightButtonText != NULL` loads `esi` from `[ebp+var_64]`, the saved `this`/EH local, then passes `static_cast<short>(esi)` as `contentWidth` to `sub_58EE90`. Base `AlertPane` disassembly shows the same family pattern at `0x0049ffce-0x0049ffe8`. Live constructor xrefs for [UID:0004CF] all pass left OK and null right, so the branch is currently unexercised in ExchangeDialog. | This is the remaining first-draft C++ blocker. Modeling it as sane one-button layout would change binary behavior for an accepted public constructor argument combination; modeling it literally would require decompiler-shaped/uninitialized local source. This is target-specific no-code proof, not a generic helper-name caveat. |

Additional DialogPane helpers are already source-facing in active docs: `sub_49DC10` is `DialogPane::AddControl(ControlPane *)`, `sub_49DD80` is `DialogPane::SetFocusedControl(int)`, `sub_49DDD0` is `DialogPane::SetPendingControl(int)`, `sub_49DFD0` is `DialogPane::OnCreate(const RectBounds *, int, Pane *, Layer *)`, `sub_49E190` is `DialogPane::OnShow(Pane *, Pane *)`, and `sub_49EAC0` is `DialogPane::SlideOpenVertical()`. These names are sufficient for target documentation. They do not remove the right-button-only branch blocker.

## Positive Evidence

- Exact owned function range is current: `0x004b0490-0x004b0819`, size `0x389` / 905 bytes (verified with `tools/int_convert.py`), seven `0xcc` bytes at `0x004b0819-0x004b0820`, then sibling [UID:0004CG] starts at `0x004b0820`.
- Direct owner remains [UID:00004Q] `ExchangeAlertPane`; source file route remains [UID:0000J9] `ExchangeDialog`.
- Constructor body is real source-authored UI construction: `DialogPane(L"", -1, false)`, singleton publication, vtable stores, text width and wrapped-height measurement, static text/button controls, control attachment, focus/pending control setup, centered create/show/open, and `m_layoutReference` storage.
- Four current callers all come from the ExchangeDialog packet/alert flow and agree on the call signature and current OK-only button usage.
- Sibling pages [UID:0004CG] and [UID:0004CH] already emit source-shaped bodies through [UID:00004Q], confirming the class/source route.
- Existing support docs now resolve all named helper/source-layout blockers except the exact right-button-only branch. The singleton, OK literal, vtable data, DialogPane helper names, `RectBounds`, `StaticTextControlPane`, `TextButtonControlPane`, `GrafPort::GetTextWidth`, `BackPane::GetBounds`, `GetMemoryMan`, and alert-family `m_layoutReference` are all documented or live-MCP validated.

## Negative Evidence And Rejected Alternatives

- Do not keep the current target as a silent blank emitter. The behavior and the no-code reason are now well enough investigated to deserve an explicit formal no-code marker routed through [UID:00004Q].
- Do not emit a full constructor body. The prior generic helper-name blocker is resolved, but the raw right-button-only branch is still unsafe to express as human source. A body would either invent corrected source for `leftButtonText == NULL && rightButtonText != NULL` or encode an uninitialized/saved-`this` local as width.
- Do not write call-site-specialized C++ that assumes only `leftButtonText=g_szDialogOk` and `rightButtonText=NULL`. That would match the four current ExchangeDialog call sites but under-document the constructor's formal fourth parameter and change behavior if the latent branch is used later.
- Do not move the constructor to [UID:0000J9] `ExchangeDialog` directly. [UID:0000J9] owns the source file route, but [UID:00004Q] is the class owner and already owns the sibling callback/clear children.
- Do not merge [UID:0004CF] back into [UID:00033W]. The live split has exact function starts at `0x004b0490`, `0x004b0820`, and `0x004b0860` with padding at `0x004b0819-0x004b081f`; the aggregate is correctly non-emitting.
- Do not create a constructor-local global for `OK`, the empty string, vtable addresses, layer context, or `g_pExchangeAlertPane`. Existing docs already own those storage/resource/data artifacts.
- Do not treat EH/security-cookie/deleting-destructor cleanup, vtable stores, or block-free cleanup thunks as source statements.

## Recommended Disposition

### Metadata

Recommended target metadata for [UID:0004CF]:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00004Q` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:00004Q`

Rationale: the revision raises the recommendation from the rejected `87/89` draft because every named helper/layout blocker has now been rechecked and either resolved or reduced to one exact target-specific no-code proof. The score should still stay below body-ready constructor quality because the right-button-only branch cannot be represented as plausible first-draft C++ without changing behavior or writing raw/uninitialized-source code.

### Formal RECONSTRUCTION_CPP CODE Insertion

Recommended exact formal block for [UID:0004CF]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ExchangeAlertPane::ExchangeAlertPane is source-authored, and the named helper
// routes are reconciled to DialogPane, RectBounds, GrafPort, StaticTextControlPane,
// TextButtonControlPane, BackPane/GetBounds, GetMemoryMan, and alert-layout helpers.
// This exact child intentionally emits no constructor body: the live binary has an
// unexercised right-button-only branch that uses the saved-this/EH local low word
// as the wrapped-text width. All live ExchangeDialog callers pass a left OK button
// and no right button. A plausible C++ body would either invent corrected behavior
// for that branch or transcribe an uninitialized/decompiler-shaped width value.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This replaces the implicit blank-emitter disposition with an explicit owner-routed no-code marker. It must not be expanded into a constructor body during this implementation callback unless the supervisor explicitly accepts a source-level policy for the right-button-only uninitialized-width branch.

### Generated Output Expectation

After implementation and validator refresh, `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` should include a [UID:0004CF] no-code comment marker routed through [UID:00004Q] before the sibling [UID:0004CG] body. It should not contain a constructor body and should not contain an `Empty Emitter Marker` for [UID:0004CF].

## Implementation-Ready Target And Support Changes

1. [UID:0004CF] `by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md`
   - Update metadata to `88/90`, owner unchanged, reconstructable unchanged, emitter `00004Q`.
   - Insert the exact formal no-code marker above.
   - Update status/C++ disposition from blank/non-emitting to explicit owner-routed no-code marker.
   - Preserve behavior details: exact range and padding, `DialogPane(L"", -1, false)`, active singleton publish/clear artifact, three vtable stores, `GetMemoryMan`, `GetScreenOffset`, `GetBounds`, `GetTextWidth`, `MeasureAlertTextHeight`, `InitRectBounds`, static text allocation `0x114` / 276, optional button allocation `0x110` / 272, `AddControl`, `SetFocusedControl`, `SetPendingControl`, centered `OnCreate`, `OnShow`, `SlideOpenVertical`, `m_layoutReference` store at `+0x26c`, and compiler-only EH/security-cookie/vtable/block-free lowering.
   - Preserve the resolved helper audit and the exact no-code proof: the unexercised right-button-only branch loads width from the saved `this`/EH local before `MeasureAlertTextHeight`, while all four live ExchangeDialog call sites pass left OK and null right.

2. [UID:00004Q] `by-class/ExchangeAlertPane.md`
   - Update the constructor method row and evidence notes from "no constructor body is emitted" to "explicit formal no-code marker emitted through [UID:00004Q] at `88/90`."
   - Record the best inferred constructor call shape and helper names, but note that no body is emitted because the right-button-only branch cannot be source-shaped safely.
   - Record root facts: four ExchangeDialog call sites, current OK/null-right usage, vtable stores, singleton publish, `m_layoutReference` storage, focus/pending control behavior, helper-name resolution, and no full class layout.
   - Keep the class declaration-only; do not invent a full member layout.

3. [UID:0000J9] `by-file/ExchangeDialog.md`
   - Update the ExchangeAlertPane row and evidence notes to say [UID:0004CF] is no longer a blank/absent emitter; it emits an explicit formal no-code marker through [UID:00004Q].
   - Keep the file route unchanged.
   - Update generated-state language: expected generated output should include a [UID:0004CF] no-code comment marker, not a constructor body and not an empty marker.
   - Preserve the call-site fact that generated callers currently use `new ExchangeAlertPane(message, this, g_szDialogOk, 0)`.

4. [UID:00033W] `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md`
   - Update the split/source-placement row for [UID:0004CF] with `88/90`, explicit no-code marker status, exact `0x004b0490-0x004b0819` range, `0x389` / 905-byte size, and seven-byte `0xcc` padding to [UID:0004CG].
   - Preserve that the aggregate itself remains non-emitting and must not merge constructor/callback/clear helper bodies.
   - Preserve the right-button-only branch caveat so the aggregate does not imply a constructor body is merely waiting on helper-name cleanup.

5. No direct support edits are required for current helper/storage pages during the implementation callback unless the supervisor chooses to widen scope:
   - `by-global/g_pExchangeAlertPane.md` and `by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md`: singleton ownership/storage is already sufficient.
   - `by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md`: shared OK literal disposition is already sufficient.
   - `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`, [UID:00011I] `StaticTextControlPaneConstructor`, `by-class/TextButtonControlPane.md`, [UID:00016C] `GrafPortTextRunHelpers`, [UID:000161] `BackPaneGetBounds`, [UID:0001BC] `GetMemoryMan`, [UID:0001TO] `AlertPaneLayout`, and DialogPane helper docs: already contain the source-facing names this report uses.
   - [UID:0004CG] and [UID:0004CH]: sibling source bodies are already populated and need no direct edit unless callback implementation discovers stale cross-reference wording.

## Implementation Callback Results - 2026-07-01

Changed by-* docs:

- `by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md`
- `by-class/ExchangeAlertPane.md`
- `by-file/ExchangeDialog.md`
- `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md`

Leases:

- Initial B009 lease command succeeded for all four by-* docs, then was released before validator refresh to avoid the short lease window expiring mid-batch.
- Refreshed B009 lease command succeeded for the same four by-* docs before validation.
- Final release command `python .\leaser.py B009 unlease` returned `Success` for all four paths.
- Post-release `tools/leaser/Agents/current_leases.md` showed no active B009 leases.

Validator results:

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md --apply --queue-timeout 240` | `000000004123` | `2026-07-01T18:05:42-04:00` | `0` | `1` | Final constructor validation after correcting stale report UID `0002GO` to actual OK literal UID `0001OC`; generated refresh deferred with same command metadata. Earlier superseded run `000000004122` also exited `0`/`ok:1` but exposed the stale UID via validator link rewrite. |
| `by-class/ExchangeAlertPane.md` | `python .\tools\validator.py --mode file --file by-class/ExchangeAlertPane.md --apply --queue-timeout 240` | `000000004125` | `2026-07-01T18:05:48-04:00` | `0` | `1` | Updated UID0001OC link label; generated refresh deferred with same command metadata. |
| `by-file/ExchangeDialog.md` | `python .\tools\validator.py --mode file --file by-file/ExchangeDialog.md --apply --wait-generated --queue-timeout 240` | `000000004126` | `2026-07-01T18:06:01-04:00` | `0` | `1` | `generated_refresh: completed`; generated C++ metadata refreshed. Known unrelated warning: `missing_ref_uid 0003U3` in `by-file/ExchangeDialog.md`. |
| `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md` | `python .\tools\validator.py --mode file --file by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md --apply --queue-timeout 240` | `000000004127` | `2026-07-01T18:06:19-04:00` | `0` | `1` | Generated refresh deferred with same command metadata. |

Generated output proof:

- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` initially refreshed with the B009 `--wait-generated` by-file validator `000000004126` at `2026-07-01T18:06:01-04:00`. Final inspection after later queued refresh activity shows a newer generated header, `validator-command-id: 000000004132`, `validator-refreshed-at: 2026-07-01T18:08:08-04:00`, `validator-refresh-source: foreground-generated-refresh`, so the generated file is current at or after the B009 validator metadata.
- The generated file contains the [UID:0004CF] no-code comment marker immediately after [UID:00004Q] class marker, with `Completion:88 | Confidence:90` and the accepted saved-this/EH-local right-button-only proof.
- The generated file does not contain a UID0004CF constructor body and does not contain a UID0004CF `Empty Emitter Marker`.
- Generated files were inspected only; they were not manually edited.

Optional support docs:

- No optional helper/storage support docs were edited. Current pages for `g_pExchangeAlertPane`, `0x0069b330`, [UID:0001OC] Dialog OK literal, RectGeometryHelpers, StaticTextControlPaneConstructor, TextButtonControlPane, GrafPortTextRunHelpers, BackPaneGetBounds, GetMemoryMan, AlertPaneLayout, DialogPane helper docs, and sibling [UID:0004CG]/[UID:0004CH] were treated as already sufficient or unchanged support evidence.

## Unresolved Issues

- No MCP availability blocker remains. The revision used live `server_health`, `idb_list`, schema-current `lookup_funcs`, one-function `decompile`, capped `xrefs_to`, capped `callees`, and paged `disasm` calls.
- No source-owner blocker remains. [UID:00004Q] remains the direct class owner and [UID:0000J9] remains the source file route.
- No named helper/source-layout blocker remains unreconciled. Each helper named in the rejection has a source-facing role or an exact support-doc already-present reason.
- The only first-draft C++ blocker is target-specific: the right-button-only branch is present in live target disassembly, is unexercised by all four current ExchangeDialog callers, appears in the base AlertPane family too, and cannot be source-shaped safely without changing latent behavior or writing uninitialized/decompiler-shaped source.

## Claim And Incorporation Ledger

| Claim ID | Report fact | Destination / proof | Action | Verification state |
| --- | --- | --- | --- | --- |
| C1 | [UID:0004CF] exact range is `0x004b0490-0x004b0819`, size `0x389` / 905 bytes, followed by seven `0xcc` bytes before [UID:0004CG]. | Applied in [UID:0004CF] `Item Summary`, `Status`, `MCP Evidence`, `Score Rationale`, and `Changes`; applied in [UID:00033W] `Item Summary`, `Covered Ranges`, `IDA Evidence`, and `Changes`. | incorporate | applied |
| C2 | Current metadata `84/86` blank emitter is too implicit for a not-covered reconstructable row; raise to `88/90` and route explicit no-code marker via [UID:00004Q]. | Applied in [UID:0004CF] metadata header and formal no-code block; class/file/aggregate notes updated in [UID:00004Q] `Method Notes`/`Evidence Notes`, [UID:0000J9] B009 generated-state notes, and [UID:00033W] split notes. | incorporate | applied |
| C3 | Direct owner remains [UID:00004Q] `ExchangeAlertPane`; source file route remains [UID:0000J9] `ExchangeDialog`. | Applied in [UID:0004CF] `Status`/`Ownership Decision`, [UID:00004Q] status/method notes, and [UID:0000J9] ExchangeAlertPane file-route notes. | incorporate | applied |
| C4 | Constructor body is source-authored UI construction: DialogPane base construction, singleton publish, vtable stores, message measurement/clamping, text/button controls, focus/pending control, centered create/show/open, and `m_layoutReference` storage. | Applied in [UID:0004CF] `Behavior`, `Resolved Helper And Layout Audit`, and `Source-Quality No-Code Proof`; summarized in [UID:00004Q] method/evidence notes and [UID:0000J9] B009 change entry. | incorporate | applied |
| C5 | Four live code xrefs call the constructor: `0x004ad656`, `0x004ad775`, `0x004ade18`, `0x004adf8d`. | Applied in [UID:0004CF] `MCP Evidence`, [UID:00004Q] `Evidence Notes`, and [UID:00033W] `IDA Evidence`; preserved in [UID:0000J9] generated-state/change notes. | incorporate | applied |
| C6 | Current call sites pass message, layout reference/parent dialog, shared OK label, and null right button; best inferred signature is `ExchangeAlertPane::ExchangeAlertPane(const wchar_t *, Pane *, const wchar_t *, const wchar_t *)`. | Applied in [UID:0004CF] `Behavior` and `MCP Evidence`; applied in [UID:00004Q] `Evidence Notes`; applied in [UID:0000J9] B009 change entry. Stale OK UID corrected from `0002GO` to actual [UID:0001OC]. | incorporate | applied |
| C7 | Vtable stores at `0x0061a1c0`, `0x0061a228`, and `0x0061a258` are constructor stores; vtable data remains compiler output, not source arrays. | Applied in [UID:0004CF] `MCP Evidence` and `Rejected Alternatives`; class/file/aggregate notes preserve the vtable store facts and no-literal-vtable disposition. | incorporate | applied |
| C8 | Singleton refs to `0x0069b330` match active alert lifecycle and do not require new storage docs. | Applied in [UID:0004CF] `Behavior`, `MCP Evidence`, and `Rejected Alternatives`; support storage pages left unchanged as already sufficient. | incorporate | applied |
| C9 | Shared OK literal `0x00613a18`, empty string `0x0060db20`, and layer/global context `0x0069b36c` are not constructor-owned globals. | Applied in [UID:0004CF] `MCP Evidence` and `Rejected Alternatives`; no direct literal/global support edits needed. OK literal UID corrected to [UID:0001OC]. | incorporate | applied |
| C10 | EH/security-cookie cleanup, deleting-destructor cleanup, vtable stores, and block-free cleanup are compiler lowering and must not be source statements. | Applied in [UID:0004CF] `Source-Quality No-Code Proof`, `Score Rationale`, and `Changes`; referenced in [UID:00004Q] evidence notes. | incorporate | applied |
| C11 | Helper audit resolves `GetScreenOffset`, `InitRectBounds`, `StaticTextControlPane`, `TextButtonControlPane`, `GrafPort::GetTextWidth`, `MeasureAlertTextHeight`, `GetBounds`, `GetMemoryMan`, `DialogPane(L"", -1, false)`, and `m_layoutReference`. | Applied in [UID:0004CF] `Resolved Helper And Layout Audit`; summarized in [UID:00004Q] evidence notes, [UID:0000J9] B009 change entry, and [UID:00033W] IDA evidence/change notes. | incorporate | applied |
| C12 | Active helper/storage docs already contain sufficient durable support for RectBounds, StaticText, TextButton, GrafPort text width, BackPane bounds, GetMemoryMan, DialogPane helpers, singleton, vtables, and OK literal; no direct support edits are required unless callback finds stale wording. | Confirmed already present; no optional helper/storage pages were edited, and no optional validators were required. Stale report UID for OK literal was corrected to [UID:0001OC] in this report and changed docs. | already-present | already-present |
| C13 | The remaining no-code proof is target-specific: the `leftButtonText == NULL && rightButtonText != NULL` branch loads width from the saved `this`/EH local before `MeasureAlertTextHeight`, while all live target callers avoid that combination. | Applied in [UID:0004CF] formal `RECONSTRUCTION_CPP CODE`, `Source-Quality No-Code Proof`, and `Score Rationale`; summarized in [UID:00004Q], [UID:0000J9], and [UID:00033W]. | incorporate | applied |
| C14 | Insert the exact formal no-code marker in [UID:0004CF], with `EMITTER_UIDS:00004Q`, instead of leaving the formal block blank. | Applied in [UID:0004CF] metadata and formal `RECONSTRUCTION_CPP CODE` block; validator `000000004123` recorded `ok:1`. | incorporate | applied |
| C15 | Generated output should include a [UID:0004CF] no-code marker after validator refresh, not a constructor body and not an empty marker. | Applied in [UID:0000J9] generated-state note and verified in `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`; B009 refresh was `validator-command-id: 000000004126`, `validator-refreshed-at: 2026-07-01T18:06:01-04:00`, and final header inspection shows newer command `000000004132` at `2026-07-01T18:08:08-04:00`. UID0004CF no-code marker present, no constructor body/empty marker. | incorporate | applied |
| C16 | [UID:00033W] remains a non-emitting split inventory and must not merge constructor/callback/clear helper bodies. | Applied in [UID:00033W] `Item Summary`, `Ownership Decision`, `Score Rationale`, and `Changes`; metadata remains `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS`. | incorporate | applied |

## Implementation Tracking Checklist

- [x] Update [UID:0004CF] metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00004Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004Q`. Proof: [UID:0004CF] metadata header updated and validator `000000004123` exited `0`, `ok:1`.
- [x] Insert the exact formal [UID:0004CF] no-code proof marker in the `RECONSTRUCTION_CPP CODE` block; do not insert a constructor body. Proof: [UID:0004CF] formal block contains the accepted comment-only marker; generated `ExchangeDialog.cpp` command `000000004126` contains the comment marker and no constructor body.
- [x] Update [UID:0004CF] status, behavior, MCP evidence, helper audit, source-quality proof, score rationale, and rejected alternatives with the report facts: live MCP session, `0x389` size, seven-byte padding, four callers, vtable stores, singleton refs, resolved helper names, control/layout flow, compiler-only lowering, `m_layoutReference`, and the exact right-button-only no-body rationale. Proof: [UID:0004CF] sections `Status`, `Behavior`, `MCP Evidence`, `Resolved Helper And Layout Audit`, `Source-Quality No-Code Proof`, `Score Rationale`, `Rejected Alternatives`, and `Changes`.
- [x] Update [UID:00004Q] `by-class/ExchangeAlertPane.md` constructor method/evidence notes to show [UID:0004CF] at `88/90`, explicit owner-routed no-code marker, best inferred call shape, resolved helper names, no full class layout, and no constructor body because of the right-button-only branch. Proof: `Method Notes`, `Evidence Notes`, and `Changes`; validator `000000004125` exited `0`, `ok:1`.
- [x] Update [UID:0000J9] `by-file/ExchangeDialog.md` Proposed Contents/Changes/Evidence to say [UID:0004CF] is no longer blank/absent, emits an explicit formal no-code marker through [UID:00004Q], preserves current `new ExchangeAlertPane(message, this, g_szDialogOk, 0)` call-site evidence, and should generate a comment marker rather than a constructor body or empty marker. Proof: top disposition paragraph, ExchangeAlertPane table row, B011/B009 repair bullets, and `Changes`; validator `000000004126` exited `0`, `ok:1`.
- [x] Update [UID:00033W] `by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md` split row/evidence for [UID:0004CF] with `88/90`, explicit no-code marker, exact range, `0x389` size, seven-byte padding, resolved helper audit, right-button-only caveat, and aggregate non-emitting caveat. Proof: `Item Summary`, `Covered Ranges`, `IDA Evidence`, `Ownership Decision`, `Score Rationale`, and `Changes`; validator `000000004127` exited `0`, `ok:1`.
- [x] Confirm no direct edits are needed for `g_pExchangeAlertPane`, the exact singleton storage page, Dialog OK literal page, RectGeometryHelpers, StaticTextControlPaneConstructor, TextButtonControlPane, GrafPortTextRunHelpers, BackPaneGetBounds, GetMemoryMan, AlertPaneLayout, DialogPane helper docs, or sibling [UID:0004CG]/[UID:0004CH] pages unless callback implementation discovers stale support text. Proof: no optional support docs edited; stale OK-literal UID in report-derived text corrected to actual [UID:0001OC].
- [x] Run scoped validator: `python .\tools\validator.py --mode file --file by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md --apply --queue-timeout 240`. Proof: final run `command_id:000000004123`, `command_timestamp:2026-07-01T18:05:42-04:00`, exit `0`, `ok:1`.
- [x] Run scoped validator: `python .\tools\validator.py --mode file --file by-class/ExchangeAlertPane.md --apply --queue-timeout 240`. Proof: `command_id:000000004125`, `command_timestamp:2026-07-01T18:05:48-04:00`, exit `0`, `ok:1`.
- [x] Run scoped validator with generated refresh: `python .\tools\validator.py --mode file --file by-file/ExchangeDialog.md --apply --wait-generated --queue-timeout 240`. Proof: `command_id:000000004126`, `command_timestamp:2026-07-01T18:06:01-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`.
- [x] Run scoped validator: `python .\tools\validator.py --mode file --file by-memory/0x004b0490-0x004b086b.ExchangeAlertPaneCore.md --apply --queue-timeout 240`. Proof: `command_id:000000004127`, `command_timestamp:2026-07-01T18:06:19-04:00`, exit `0`, `ok:1`.
- [x] Run validators for any optional support docs actually edited. Proof: no optional support docs were edited, so no optional validators were required.
- [x] Inspect generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` after `--wait-generated`; record validator command id/timestamp, generated header freshness, [UID:0004CF] no-code marker presence, and absence of [UID:0004CF] empty marker/constructor body. Proof: B009 `--wait-generated` command `000000004126` refreshed the file at `2026-07-01T18:06:01-04:00`; final header inspection shows newer `validator-command-id:000000004132`, `validator-refreshed-at:2026-07-01T18:08:08-04:00`, source `foreground-generated-refresh`; UID0004CF no-code marker present; no UID0004CF constructor body or empty marker.
- [x] During implementation callback, update this ledger/checklist with `applied`, `already-present`, `excluded-with-reason`, or exact blocker states and path/section proof. Proof: Claim And Incorporation Ledger now marks accepted rows `applied` or `already-present` with destination/section proof; no unchecked implementation blockers remain.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0004CF-ExchangeAlertPaneConstructor-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0004CF-ExchangeAlertPaneConstructor-by-memory-source-quality.md","timestamp":"2026-07-01T18:17:38","uid":"0004CF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
