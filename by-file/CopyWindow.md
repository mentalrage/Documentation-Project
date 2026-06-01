*** UID:0000IH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CopyWindow

## Status

- Confidence: medium-high for a small dedicated dialog source; medium for exact folder.
- Proposed module: `ui/dialogs/CopyWindow.cpp`
- Current generated source: `source-3/simroot_v2/class_CopyWindow.cpp`
- Main address doc: [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- Related constructor side path: [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)

## File Role

`CopyWindow.cpp` likely owns a tiny `AlertPane`-derived confirmation dialog connected to [UID:0000ON][TextEditPane](by-file/TextEditPane.md). The dialog uses a localized title/string id `0xf1`, the button table at `off_622f44`, and the shared alert base at `0x0049feb0`.

The generated class summary says this is a utility window for clipboard copy operations. Current IDA evidence is narrower: the accept callback calls `TextEditPane::SelectAll` (`0x00590520`) through [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md) / `dword_69BE00`, then clears that global.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `CopyWindow` constructor body | `0x005544c0-0x00554513`; IDA does not currently model it as a function | Builds an `AlertPane`, installs the three `CopyWindow` vtables. |
| `CopyWindow::OnAccept` | `0x00554520-0x00554536` | Calls `TextEditPane::SelectAll` on the active editor and clears the active-editor pointer. |
| `CopyWindow::OnCancel` | `0x00554540-0x0055454b` | Clears the active-editor pointer without selecting. |
| connection-closed init side path | `0x00553e60-0x00553f36`; IDA has a stale/bogus symbol name | Lives with [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) / `ConnectionClosedDialog` init flow but can allocate and initialize a `CopyWindow` when an active text edit pane has eligible state. |

## Ownership Decision

Keep `CopyWindow` as a dedicated dialog source for now, not folded into [UID:0000HE][AlertPanes](by-file/AlertPanes.md). It derives from `AlertPane`, but its behavior and state are specific to [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and Wave2 metadata names `CopyWindow.cpp` as the import source.

Do not move it into `TextEditPane.cpp` yet. `TextEditPane` owns the active-editor global and editor methods, but `CopyWindow` is a dialog class with its own vtable and alert button callbacks.

Do not migrate the helper at `0x00553e60` into `CopyWindow.cpp` by default. A 2026-05-25 IDA caller check shows it is called from `ConnectionClosedDialog` construction paths and `ReconnectDialog::OnButtonClick`; it only constructs `CopyWindow` as a conditional side path.

## Evidence Notes

- `source-3/simroot_v2/class_CopyWindow.cpp` emits constructor `0x005544c0`, accept callback `0x00554520`, and cancel callback `0x00554540`.
- 2026-05-26 `simroot_v2` recheck: `class_CopyWindow.cpp` still emits `g_pCopyWindowTextEditPane`, while `class_TextEditPane.cpp` owns the canonical `g_pActiveTextEditPane` global-data record at the same address.
- IDA MCP confirms `0x00554520` and `0x00554540` as real functions and data xrefs from the `CopyWindow` vtable at `0x00622e7c`.
- IDA MCP currently reports `0x005544c0` as "Not a function", but disassembly at `0x005544c0-0x00554512` is a valid constructor-shaped body that calls `AlertPane::AlertPane` and installs the `CopyWindow` vtables.
- 2026-06-01 IDA MCP byte review corrects the constructor end-exclusive address to `0x00554513`, `OnAccept` to `0x00554536`, and `OnCancel` to `0x0055454b`; the old `0x0055454a` range omitted the final `retn` byte.
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
