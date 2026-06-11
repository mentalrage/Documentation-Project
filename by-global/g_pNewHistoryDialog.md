*** UID:0000RS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- IDA MCP confirms constructor/destructor references and the `0x005023e0` singleton clear helper; live address evidence is the proof source for this singleton.
- The existing scrolled-text docs previously described this as a generic active-dialog close path. Current IDA xrefs tie this address specifically to `g_pNewHistoryDialog`.
- IDA MCP `xrefs_to 0x005023e0` reports a constructor-context xref at `0x00601f62`, consistent with small cleanup/unwind support rather than an independent feature entry point.
- 2026-05-26 recheck classifies `0x005023e0` as compiler-generated constructor EH cleanup and records it in [UID:0000VN][-ignored](by-memory/-ignored.md), while keeping `g_pNewHistoryDialog` itself reconstructable project data.

## Lifecycle Evidence

| Site | Access | Meaning |
| --- | --- | --- |
| `0x00500465` in `0x00500410-0x005005b4` | write `this` | `NewHistoryDialogPane` constructor publishes the active `HISTORYN.EPF` / `MADEBY` dialog. |
| `0x0050046c` in `0x00500410-0x005005b4` | write `0` | Constructor-family fallback clear if the adjusted pointer is null. |
| `0x004ff6eb` in `0x004ff6c0-0x004ff725` | read | `ScrolledTextControlPaneForMadeBy` closes the active dialog when credits scrolling reaches the end. |
| `0x005023e0-0x005023eb` | write `0` | `ClearNewHistoryDialogSingleton` compact constructor-cleanup helper clears the singleton. |
| `0x00502926` in `0x00502920-0x00502965` | write `0` | Scalar deleting destructor clears the singleton before base cleanup/free handling. |

## Open Questions

- Whether the constructor has an indirect menu-command caller not represented in IDA's direct caller list.
- Final source declaration spelling remains open; `g_pNewHistoryDialog` is a documentation name tied to the resolved `dword_69B49C` storage.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069b49c` is `dword_69B49C`, size `4`, in `.data`, with 5 data xrefs.
- Live IDA xrefs confirm the documented constructor writes at `0x00500465` and `0x0050046c` in `0x00500410`, singleton clear at `0x005023e0` in `ClearNewHistoryDialogSingleton`, destructor clear at `0x00502926` in `0x00502920`, and scrolled-text consumer at `0x004ff6eb` in `0x004ff6c0`.
- Live IDA decompilation on 2026-06-05 confirms `0x00500410` stores `this` into `dword_69B49C` and installs the `NewHistoryDialogPane` vtable; `0x005023e0` and `0x00502920` clear the singleton during cleanup/destruction.
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

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LQ`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b49c` and decompilation of `0x00500410`, `0x005023e0`, and `0x00502920` prove NexusTK-owned `NewHistoryDialogPane` singleton storage owned by [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-06: Raised grading from `80/82` to `84/88`.
  - Before: the page had the correct owner and xref summary but still carried older scoring and one unresolved raw helper token.
  - After: added a lifecycle table covering constructor publish/fallback clear, made-by scrolled-text close read, cleanup helper clear, and scalar deleting destructor clear; also normalized `sub_5023E0` to `ClearNewHistoryDialogSingleton`.
  - Evidence: [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) now records the exact slot at `86/90`, with five direct data refs and write/read-site tables; confidence remains below final-audit quality because direct constructor reachability and final declaration spelling remain open.
