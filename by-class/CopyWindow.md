*** UID:000039 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CopyWindow

## Status

- Confidence: strong for exact callback behavior, vtable slots, active-editor global use, and dialog source ownership; medium-high for raw constructor modeling.
- Likely source file: [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- Documentation basis: IDA-reviewed raw constructor/callback bytes, vtable references, active [UID:0000EO][TextEditPane](by-class/TextEditPane.md) global ownership, and reconnect-flow inline construction evidence.
- Recovered-output caveat: prior recovered class output still uses the stale `g_pCopyWindowTextEditPane` alias; the canonical global is [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md).

## Class Purpose

`CopyWindow` is a small [UID:00000B][AlertPane](by-class/AlertPane.md) subclass that coordinates a text-edit copy/select operation with the active [UID:0000EO][TextEditPane](by-class/TextEditPane.md). It presents a modal alert and, on accept, calls the active text editor's select-all helper before clearing the active-editor global.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005544c0-0x00554513` | Calls `AlertPane::AlertPane`, using localized string id `0xf1`, button table `off_622f44`, and installs three `CopyWindow` vtables. IDA currently does not model this start as a function. |
| `OnAccept` | `0x00554520-0x00554536` | Calls `TextEditPane::SelectAll` at `0x00590520` through [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md), then clears the global. |
| `OnCancel` | `0x00554540-0x0055454b` | Clears [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md). |

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000IH][CopyWindow](by-file/CopyWindow.md). This class is now scored `85/86`, and the refreshed direct source-file parent is scored `86/86`, so both sides satisfy the corrected 85/85 gate. The parent is direct because the file page exists specifically for this alert-derived dialog source, owns the raw constructor/callback island, and excludes the reconnect-flow inline construction helper from final `CopyWindow` ownership.

## Evidence Notes

- `CopyWindow` vtable data at `0x00622e7c` references `0x00554520` and `0x00554540` as callbacks.
- The constructor has no IDA caller xrefs, but the helper at `0x00553e60` allocates a 624-byte object, calls the same alert base constructor, and installs `CopyWindow` vtables inline.
- 2026-05-25 IDA caller checks show `0x00553e60` is a `ConnectionClosedDialog`/reconnect-flow init helper that conditionally constructs `CopyWindow`, not a CopyWindow-owned open method.
- 2026-05-26 IDA MCP recheck kept `0x005544c0` as not-a-function, kept `0x00554520`/`0x00554540` as vtable-only callback xrefs, and kept `0x00553e60` as a real `0xd6`-byte helper with reconnect-flow callers.
- 2026-06-01 IDA MCP byte review confirms the constructor-shaped raw body at `0x005544c0-0x00554513`, `OnAccept` at `0x00554520-0x00554536`, and `OnCancel` at `0x00554540-0x0055454b`; the previous callback end omitted the final `retn` byte.
- 2026-06-07 A008 Batch 082 IDA MCP refresh reconfirmed `OnAccept` as `0x00554520-0x00554536`, `OnCancel` as `0x00554540-0x0055454b`, the raw constructor byte range at `0x005544c0-0x00554513`, and thirteen `0xcc` padding bytes after the constructor.
- The same refresh reconfirmed the inline construction side path at `0x00553e60-0x00553f36` with three reconnect-flow callers, and `CopyWindow` vtable slots at `0x00622e7c` include the accept and cancel callbacks at `0x00554520` and `0x00554540`.
- The recovered-output global name `g_pCopyWindowTextEditPane` is too narrow; IDA xrefs show `dword_69BE00` is an active text-edit pointer set by `TextEditPane` construction and cleared by `TextEditPane` destruction.
- Existing TextEditPane/global docs use the canonical `g_pActiveTextEditPane` identity; any recovered class output that still uses the CopyWindow-specific alias should be treated as stale.

## Score Rationale

- Completion `85`: purpose, direct source parent, exact raw constructor and modeled callback ranges, active-editor global behavior, vtable slots, reconnect-flow construction evidence, stale alias caveat, and cross-references are documented.
- Confidence `86`: callback and vtable behavior are strong, and source ownership is now supported by the refreshed parent file; confidence remains below final-source quality because the constructor start is still raw/not modeled by IDA as a function.

## Cross-References

- [UID:0000IH][CopyWindow](by-file/CopyWindow.md)
- [UID:0001FV][0x005544c0-0x0055454b.CopyWindow](by-memory/0x005544c0-0x0055454b.CopyWindow.md)
- [UID:0001FU][0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper](by-memory/0x00553e60-0x00553f36.ConnectionClosedDialogInitHelper.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0000Q7][g_pActiveTextEditPane](by-global/g_pActiveTextEditPane.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `68/76`.
  - Summary/evidence: accept/cancel callbacks, vtable references, active text-edit global behavior, and reconnect-flow inline construction evidence are documented; remaining uncertainty is the constructor boundary and stale generated alias cleanup.
- 2026-06-01:
  - Before: method ranges used pre-byte-review endpoints and scores were capped at `68/76`.
  - After: corrected constructor/callback ranges and raised scores to `78/84`.
  - Summary/evidence: IDA MCP confirms exact raw bytes, vtable references, active-editor global access, and callback bodies. Completion remains below file-level because final source method names and constructor modeling remain open.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remains blank because the class completion score is below the 80% attachment gate.
  - Evidence: live IDA MCP reconfirms `0x005544c0` is raw constructor-shaped code rather than a modeled function, and confirms modeled callback starts at `0x00554520` and `0x00554540`; existing project docs place the dialog in [UID:0000IH][CopyWindow](by-file/CopyWindow.md).
- 2026-06-06 provenance cleanup:
  - Before: the status section cited a direct recovered-output file path and generated grade/coverage values, and the evidence notes referenced current recovered class output as though it were authoritative.
  - After: replaced those lines with the IDA-backed documentation basis and kept only a recovered-output alias caveat.
  - Evidence: the page already records raw constructor/callback byte review, vtable references, active text-edit global ownership, and reconnect-flow inline construction evidence. Scores, reconstructability, parent, and blank C++ gate remain unchanged.
- 2026-06-07 A008 Batch 082 class-coverage pass:
  - Before: `78/84`, `AUTOGEN_PARENT_UID:` blank.
  - After: `85/86`, `AUTOGEN_PARENT_UID:0000IH`.
  - Evidence: current IDA MCP reconfirmed raw constructor bytes, callback ranges, active-editor global behavior, vtable slots, and the reconnect-flow side-path exclusion; the direct source parent [UID:0000IH][CopyWindow](by-file/CopyWindow.md) was refreshed to `86/86`.
