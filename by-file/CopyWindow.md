*** UID:0000IH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CopyWindow

## Status

- Disposition: reviewed historical/non-emitting source index. No standalone `CopyWindow.cpp` or `CopyWindow.h` is reconstructed.
- Confidence: very strong for the complete class/code/data inventory, exact callback behavior, label/global routing, and source placement in [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md).
- Current source module: `NexusTK/network/ReconnectDialog.cpp`, where [UID:000039][CopyWindow](by-class/CopyWindow.md) is emitted as a private file-local class at position `20`.
- Main address doc: [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- Related constructor side path: [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)

## File Role

This page indexes a tiny `AlertPane`-derived confirmation dialog connected to [UID:0000ON][TextEditPane](by-file/TextEditPane.md). The source-authored class belongs in the `ReconnectDialog.cpp` translation unit because its only live construction is in the file's private `ConnectionClosedDialog::InitializeConnectionState()` helper and no external consumer requires the complete type. The dialog uses localized title/string id `0xf1` through [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md), UTF-16 labels `L"Yes"` and `L"No"`, and the shared alert base constructor at `0x0049feb0`.

Current evidence is narrow and concrete: the primary callback calls `TextEditPane::CopyAllToClipboard` (`0x00590520`) through [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md), then clears that global without a null guard. The secondary callback only clears the global.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `CopyWindow` constructor body | Current canonical function `[0x005544c0,0x00554513)` named `CopyWindow__CopyWindow`, with persisted public type `CopyWindow *__thiscall(CopyWindow *this)`. Historical pre-Gate-2B checkpoint (`2026-08-22`): IDA did not then model this start as a function. Zero inbound xrefs remain, while the complete retained body and live inline duplicate preserve source liveness. | Builds an `AlertPane` as `AlertPane(g_pLanguageMan->GetLocalizedString(0xf1), g_pBackPane, L"Yes", L"No")` and installs the three `CopyWindow` vtables. |
| `CopyWindow::OnPrimaryButton` / accept/yes alias | `0x00554520-0x00554536` | Calls `TextEditPane::CopyAllToClipboard` on the active editor and clears the active-editor pointer. |
| `CopyWindow::OnSecondaryButton` / cancel/no alias | `0x00554540-0x0055454b` | Clears the active-editor pointer without selecting. |
| connection-closed init side path | `0x00553e60-0x00553f36`; IDA has a stale/bogus symbol name | Lives with [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) / `ConnectionClosedDialog` init flow but can allocate and initialize a `CopyWindow` when an active text edit pane has eligible state. |

## Ownership Decision

Emit the source-authored class as a private file-local class in [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), not in a dedicated file and not in [UID:0000HE][AlertPanes](by-file/AlertPanes.md) or `TextEditPane.cpp`. TextEditPane owns the active-editor global and clipboard method, AlertPanes owns the generic base/shared compiler family, and ReconnectDialog owns the sole live construction context.

Do not migrate the helper at `0x00553e60` into `CopyWindow.cpp` by default. A 2026-05-25 IDA caller check shows machine xrefs from both out-of-line `ConnectionClosedDialog` construction paths and from `0x005543bb`; current byte/decompile comparison classifies the third site as part of a compiler-inlined default-constructor mirror in the reconnect replacement path, not a direct source-level private-helper call from `ReconnectDialog::OnButtonClick`. The helper only constructs `CopyWindow` as a conditional side path.

## Parent-Gate Support

This page remains a `FILE`-owned historical index at `96/96`, but it is no longer an emitter or direct source parent. [UID:000039][CopyWindow](by-class/CopyWindow.md) emits the complete file-local class through UID0000N0; exact executable, vtable, and literal children route through the class. This preserves discovery and evidence without manufacturing a standalone translation unit.

## Current Whole-File Closure

- Source inventory: one retained constructor `[0x005544c0,0x00554513)`, primary callback `[0x00554520,0x00554536)`, secondary callback `[0x00554540,0x0055454b)`, three inherited-facet vtables/RTTI, two pooled UTF-16 labels, one TextEditPane-owned active-editor global, and the live ConnectionClosedDialog helper that contains the inlined construction.
- Exact constructor SHA256 is `F60A271C1E5608BA4A23E356AC4EC665E197F58198F960E6EF18E45DAE51B5A`; it has no direct call, jump, data, immediate, or pointer route. Its source liveness is nevertheless proved by the complete retained body and live inlined duplicate in the helper.
- Exact callback SHA256 values are `0F320B7C42E472261185E1CCB80D5367E478714179AB71BB43D1A0258B88642F` and `6C4EE44F24614EB481044283CB6DFB6FC686F039BBF263DED1FB65E8E93FC6AF`. Primary calls `CopyAllToClipboard` and then clears the global; secondary only clears it.
- Exact compiler/data children are [UID:0003CV][0x00622e78-0x00622f1c.CopyWindowVtableData](by-memory/0x00622e78-0x00622f1c.CopyWindowVtableData.md), [UID:0003G5][0x00622f3c-0x00622f44.CopyWindowNoButtonWideString](by-memory/0x00622f3c-0x00622f44.CopyWindowNoButtonWideString.md), and [UID:0003G6][0x00622f44-0x00622f4c.CopyWindowYesButtonWideString](by-memory/0x00622f44-0x00622f4c.CopyWindowYesButtonWideString.md). They emit covered-by comments through the class rather than duplicate source definitions.
- Exact padding stays non-source: thirteen `CC` bytes at `[0x00554513,0x00554520)`, ten at `[0x00554536,0x00554540)`, and five at `[0x0055454b,0x00554550)`. The function at `0x00554550` is excluded.
- No standalone header is required: there is no external complete-type consumer, no independent module API, and no header artifact. The needed cross-unit dependency is instead `extern TextEditPane *g_pActiveTextEditPane;` in TextEditPane's H route.
- Expected generated closure is one complete private class in `network/ReconnectDialog.cpp` before helper use, current TextEditPane declaration/API support, and no standalone `CopyWindow.cpp` or `CopyWindow.h`.
- The prior dedicated `ui/dialogs/CopyWindow.cpp` conclusion was plausible from physical class/vtable evidence and older generated/source-tree leads, but it is superseded by live inlining, zero direct constructor routes, no external type consumer, and compilation-unit closure.

## Evidence Notes

- Older recovered-output caveat: a generated `CopyWindow` view used the stale `g_pCopyWindowTextEditPane` alias, while current project documentation owns the same address as canonical [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md).
- IDA MCP confirms `0x00554520` and `0x00554540` as real functions and data xrefs from the `CopyWindow` vtable at `0x00622e7c`.
- Historical pre-Gate-2B checkpoint (`2026-08-22`): IDA MCP then reported `0x005544c0` as "Not a function". Current canonical state models `[0x005544c0,0x00554513)` as function `CopyWindow__CopyWindow` with persisted public type `CopyWindow *__thiscall(CopyWindow *this)`. Its 83-byte body still calls `AlertPane::AlertPane` and installs the `CopyWindow` vtables; zero inbound xrefs remain, while the complete retained body and live inline duplicate preserve source liveness.
- 2026-06-01 IDA MCP byte review corrects the constructor end-exclusive address to `0x00554513`, `OnAccept` to `0x00554536`, and `OnCancel` to `0x0055454b`; the old `0x0055454a` range omitted the final `retn` byte.
- 2026-06-07 A008 Batch 082 IDA MCP refresh reconfirmed the same constructor/callback bounds, copied the raw constructor byte shape, found thirteen `0xcc` bytes after the constructor, confirmed the call at `0x00554520`, confirmed `0x00554540` has no callees, and reconfirmed the reconnect-flow inline constructor helper at `0x00553e60-0x00553f36` with three callers. The then-used `SelectAll` source interpretation is superseded by current `CopyAllToClipboard` evidence.
- IDA decompilation of `0x00553e60` inlines the same `AlertPane` construction and writes `CopyWindow::vftable`; this proves live construction even though the standalone constructor has no direct IDA caller xrefs.
- B014 PE scanning found zero rel32 call/jump refs and zero absolute VA/RVA dword hits for the standalone `0x005544c0` constructor, but preserved it as source-authored because the byte body is complete, returns `this`, calls the base constructor, installs the class vtables, and is duplicated inline by the reconnect helper.
- B014 resolves the formal callback names as `OnPrimaryButton()` and `OnSecondaryButton()` to match [UID:00000B][AlertPane](by-class/AlertPane.md). `OnAccept`/`OnCancel` remain behavior aliases only.
- B014 correctly resolved source semantics: bytes at `0x00622f44` are UTF-16 `L"Yes"`, not a source-level pointer table. Current canonical IDA state is one eight-byte `[0x00622f44,0x00622f4c)` item named `aYes`, public type `const wchar_t`, with exact bytes decoding as UTF-16LE `Yes`, head refs `{0x00553ec0,0x005544ca}`, zero interior refs, and the accepted repeatable comment. Public `get_string` currently returns `Y/e/s` per code-unit address and is not the whole-item semantic authority. The former four-byte `off_622F44` item, four undefined tail bytes, and two-call handoff are historical pre-Gate-2B evidence only. `L"No"` is at `0x00622f3c`; `dword_67A750` is `g_pLanguageMan`; `dword_67A740` is `g_pBackPane`; and `dword_69BE00` is the broader `g_pActiveTextEditPane` global, not CopyWindow-owned state.
- B014 identifies the `0x0058efa0` call inside the reconnect helper as a `TextEditPane::GetTextLength()` / `GetCharCount()`-style query because it returns `word ptr [[this+0x134]+0x0c]`. It remains a reconnect-helper support dependency, not a CopyWindow method.
- IDA `callers` on 2026-05-25 reports exact machine xrefs to `0x00553e60` at `0x00553ca8`, `0x00553d55`, and `0x005543bb`. The first two are direct calls from the out-of-line `ConnectionClosedDialog` constructors; the third lies inside their compiler-inlined default-constructor mirror in the reconnect replacement path and is not a direct source-level private-helper call from `ReconnectDialog::OnButtonClick`. No xref comes from a `CopyWindow` callback.
- 2026-05-26 IDA MCP recheck reports the same three callers for `0x00553e60`: `0x00553ca8`, `0x00553d55`, and `0x005543bb`.
- `dword_69BE00` is broader than the generated `g_pCopyWindowTextEditPane` alias. It is set/cleared by [UID:0000ON][TextEditPane](by-file/TextEditPane.md) construction/destruction and consumed by `CopyWindow` callbacks.

## Historical / Superseded Caller Theory

- Historical/superseded 2026-05-25 interpretation: this page previously treated machine xref `0x005543bb` as a direct source-level call from `ReconnectDialog::OnButtonClick` to the private helper at `0x00553e60`. That theory is rejected because byte/decompile comparison shows the surrounding reconnect replacement path reproduces the default `ConnectionClosedDialog` constructor's AlertPane arguments, Singleton publication, and three facet stores before the helper call. The machine xref remains valid evidence, but its source-level interpretation is a compiler-inlined default-constructor mirror that preserves private helper access.

## Cross-References

- [UID:000039][CopyWindow](by-class/CopyWindow.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md)

## Changes

- 2026-08-22 B008 C-IH-013 current-truth callback: Historicalized the former split/two-call UID0003G6 prestate and recorded the completed persisted one-item `aYes` endpoint; no file ownership, score, range, source semantics, or emission changed.
- Historical/superseded pre-Gate-2B checkpoint - 2026-08-22 B008 C-IH-013 callback: This callback qualified source-level `L"Yes"` against the then-canonical four-byte `off_622F44` plus undefined-tail itemization and routed the then-pending deterministic item repair to UID0003G6; no file ownership, score, range, or emission changed. Completed supervisor Gate 2B later persisted one eight-byte `[0x00622f44,0x00622f4c)` item named `aYes` with public type `const wchar_t` through one `make_data` call, so the split/pending-repair statement is historical evidence only and is not current authority.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: dialog role, constructor/callback behavior, active text-edit global ownership, connection-closed side path, and fold/not-fold ownership decisions are documented; confidence is capped because the constructor is raw/non-IDA and exact folder placement remains medium.
- 2026-06-01: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/` and raised completion/confidence from `80/76` to `84/82`.
  - Evidence: refreshed IDA MCP review of [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md) confirms the exact constructor/callback byte ranges, vtable stores, active text-edit global behavior, and dialog source ownership. Confidence remains below final-source level because the constructor is still a raw not-a-function start.
- 2026-06-07 A008 Batch 082 parent-gate refresh:
  - Before: `84/82`, which blocked [UID:000039][CopyWindow](by-class/CopyWindow.md) under the corrected 85/85 gate.
  - After: `86/86`.
  - Evidence: current IDA MCP reconfirmed exact class island bounds, raw constructor bytes, accept/cancel callback bodies, `CopyWindow` vtable slots, active text-edit global use, and the reconnect-flow helper exclusion.
- 2026-06-22 B014 Rule 26 incorporation:
  - Before: `86/86`, no formal C++ emission on the class or exact method island.
  - After: `88/89`.
  - Evidence: report-level source-quality pass keeps `NexusTK/ui/dialogs/CopyWindow.cpp`, routes class declaration and method bodies through this file, corrects button-label/global aliases, names the inherited primary/secondary callback overrides, keeps the reconnect helper under [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md), and leaves vtable/string children as no-code generated/source-use support.
- 2026-08-18 B008 UID0000IH implementation callback:
  - Reclassified this page to a `96/96`, path `NONE`, non-emitting historical index and moved source emission to the private [UID:000039][CopyWindow](by-class/CopyWindow.md) class inside UID0000N0.
  - Incorporated the complete function/data/compiler/padding/global/helper inventory, exact hashes and routes, `GetLocalizedString`/`CopyAllToClipboard` API corrections, no-header proof, generated-output contract, rejected owners, and the historical dedicated-file rationale without pruning earlier evidence.
