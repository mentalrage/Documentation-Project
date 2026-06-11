*** UID:0000IH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CopyWindow

## Status

- Confidence: strong for the small dedicated dialog source and raw constructor/callback island; medium-high for exact folder because the class is still a tiny alert-derived dialog.
- Proposed module: `ui/dialogs/CopyWindow.cpp`
- Main address doc: [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- Related constructor side path: [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)

## File Role

`CopyWindow.cpp` likely owns a tiny `AlertPane`-derived confirmation dialog connected to [UID:0000ON][TextEditPane](by-file/TextEditPane.md). The dialog uses a localized title/string id `0xf1`, the button table at `off_622f44`, and the shared alert base at `0x0049feb0`.

Current IDA evidence is narrow and concrete: the accept callback calls `TextEditPane::SelectAll` (`0x00590520`) through [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md) / `dword_69BE00`, then clears that global.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `CopyWindow` constructor body | `0x005544c0-0x00554513`; IDA does not currently model it as a function | Builds an `AlertPane`, installs the three `CopyWindow` vtables. |
| `CopyWindow::OnAccept` | `0x00554520-0x00554536` | Calls `TextEditPane::SelectAll` on the active editor and clears the active-editor pointer. |
| `CopyWindow::OnCancel` | `0x00554540-0x0055454b` | Clears the active-editor pointer without selecting. |
| connection-closed init side path | `0x00553e60-0x00553f36`; IDA has a stale/bogus symbol name | Lives with [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) / `ConnectionClosedDialog` init flow but can allocate and initialize a `CopyWindow` when an active text edit pane has eligible state. |

## Ownership Decision

Keep `CopyWindow` as a dedicated dialog source for now, not folded into [UID:0000HE][AlertPanes](by-file/AlertPanes.md). It derives from `AlertPane`, but its behavior and state are specific to [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and existing source-tree documentation already places `CopyWindow.cpp` under `ui/dialogs/`.

Do not move it into `TextEditPane.cpp` yet. `TextEditPane` owns the active-editor global and editor methods, but `CopyWindow` is a dialog class with its own vtable and alert button callbacks.

Do not migrate the helper at `0x00553e60` into `CopyWindow.cpp` by default. A 2026-05-25 IDA caller check shows it is called from `ConnectionClosedDialog` construction paths and `ReconnectDialog::OnButtonClick`; it only constructs `CopyWindow` as a conditional side path.

## Parent-Gate Support

This page is the direct parent for [UID:000039][CopyWindow](by-class/CopyWindow.md). Batch 082 raises this file to `86/86` because the page now has enough current IDA evidence for the exact raw constructor/callback island, vtable ownership, active-editor global, and reconnect-flow side-path exclusion. The class child can attach here under the corrected 85/85 gate; final C++ still remains blank on the child because the constructor is not modeled as an IDA function and source-facing names are not final-audit quality.

## Evidence Notes

- Older recovered-output caveat: a generated `CopyWindow` view used the stale `g_pCopyWindowTextEditPane` alias, while current project documentation owns the same address as canonical [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md).
- IDA MCP confirms `0x00554520` and `0x00554540` as real functions and data xrefs from the `CopyWindow` vtable at `0x00622e7c`.
- IDA MCP currently reports `0x005544c0` as "Not a function", but disassembly at `0x005544c0-0x00554512` is a valid constructor-shaped body that calls `AlertPane::AlertPane` and installs the `CopyWindow` vtables.
- 2026-06-01 IDA MCP byte review corrects the constructor end-exclusive address to `0x00554513`, `OnAccept` to `0x00554536`, and `OnCancel` to `0x0055454b`; the old `0x0055454a` range omitted the final `retn` byte.
- 2026-06-07 A008 Batch 082 IDA MCP refresh reconfirmed the same constructor/callback bounds, copied the raw constructor byte shape, found thirteen `0xcc` bytes after the constructor, confirmed `0x00554520` calls `TextEditPane::SelectAll`, confirmed `0x00554540` has no callees, and reconfirmed the reconnect-flow inline constructor helper at `0x00553e60-0x00553f36` with three callers.
- IDA decompilation of `0x00553e60` inlines the same `AlertPane` construction and writes `CopyWindow::vftable`; this proves live construction even though the standalone constructor has no direct IDA caller xrefs.
- IDA `callers` on 2026-05-25 reports `0x00553e60` is reached from `ConnectionClosedDialog` constructor/init paths and `ReconnectDialog::OnButtonClick`, not from `CopyWindow` callbacks.
- 2026-05-26 IDA MCP recheck reports the same three callers for `0x00553e60`: `0x00553ca8`, `0x00553d55`, and `0x005543bb`.
- `dword_69BE00` is broader than the generated `g_pCopyWindowTextEditPane` alias. It is set/cleared by [UID:0000ON][TextEditPane](by-file/TextEditPane.md) construction/destruction and consumed by `CopyWindow` callbacks.

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
