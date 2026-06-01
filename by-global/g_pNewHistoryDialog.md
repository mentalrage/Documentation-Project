*** UID:0000RS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pNewHistoryDialog

## Status

- Confidence: strong for singleton address and class owner.
- Address: `0x0069b49c`
- Primary memory doc: [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- Owner class: [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- Likely owner source: [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)

## Symbol Role

`g_pNewHistoryDialog` stores the active full-screen `HISTORYN.EPF` / `MADEBY` history-credits dialog. The constructor writes it, the singleton clear helper at `0x005023e0` clears it, the scalar deleting destructor clears it, and [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md) closes it when the credits text finishes scrolling.

## Evidence Notes

- IDA MCP `xrefs_to 0x0069b49c` reports a `ScrolledTextControlPaneForMadeBy::OnTimerEvent` close reference at `0x004ff6eb`, constructor writes at `0x00500465` and `0x0050046c`, singleton clear at `0x005023e0`, and destructor clear at `0x00502926`.
- IDA MCP confirms constructor/destructor references and the `0x005023e0` singleton clear helper; generated output should not be used as proof for this singleton.
- The existing scrolled-text docs previously described this as a generic active-dialog close path. Current IDA xrefs tie this address specifically to `g_pNewHistoryDialog`.
- IDA MCP `xrefs_to 0x005023e0` reports a constructor-context xref at `0x00601f62`, consistent with small cleanup/unwind support rather than an independent feature entry point.
- 2026-05-26 recheck classifies `0x005023e0` as compiler-generated constructor EH cleanup and records it in [UID:0000VN][-ignored](by-memory/-ignored.md), while keeping `g_pNewHistoryDialog` itself reconstructable project data.

## Open Questions

- Whether the constructor has an indirect menu-command caller not represented in IDA's direct caller list.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069b49c` is `dword_69B49C`, size `4`, in `.data`, with 5 data xrefs.
- Live IDA xrefs confirm the documented constructor writes at `0x00500465` and `0x0050046c` in `sub_500410`, singleton clear at `0x005023e0` in `sub_5023E0`, destructor clear at `0x00502926` in `sub_502920`, and scrolled-text consumer at `0x004ff6eb` in `sub_4FF6C0`.
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) remains the canonical memory page for this slot and matches the live IDA check.
- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md) and [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md) document the dialog resources, constructor/event/destructor ranges, ignored compiler cleanup/thunk spans, and unresolved direct-caller question.
- The unresolved indirect constructor caller remains an open question because this pass verified the singleton storage and xrefs, not the menu/menu-command path that creates the dialog.

## Cross-References

- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)
- [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `80`, confidence `82`.
- Summary/evidence: the page now consolidates exact storage, owner class/file, constructor/destructor writes, live IDA MCP xrefs, scrolled-text consumer behavior, and ignored compiler thunk/EH cleanup handling. Confidence remains capped by the unresolved indirect constructor caller.
