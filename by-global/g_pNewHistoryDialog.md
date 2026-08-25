*** UID:0000RS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class NewHistoryDialogPane;

NewHistoryDialogPane *g_pNewHistoryDialog = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pNewHistoryDialog

## Status

- Confidence: very strong for singleton address/type, external linkage, sole definition, lifecycle, source route, and direct-Singleton cause.
- Address: `0x0069b49c`
- Primary memory doc: [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md)
- Owner class: [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md)
- Likely owner source: [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md)

## Symbol Role

`g_pNewHistoryDialog` stores the active full-screen `HISTORYN.EPF` / `MADEBY` history-credits dialog. The direct `Singleton<NewHistoryDialogPane>` base causes constructor publication/fallback and reverse-order cleanup; [UID:0000CJ][ScrolledTextControlPaneForMadeBy](by-class/ScrolledTextControlPaneForMadeBy.md) is the sole runtime reader and closes it when credits text finishes scrolling.

The cross-source scroller read proves external rather than file-static or class-static linkage. This page owns the sole definition `NewHistoryDialogPane *g_pNewHistoryDialog = 0;` at position 0 in [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md); [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md) carries the matching extern declaration. Physical page UID0001PV is false/non-emitting and cannot emit a duplicate.

## Evidence Notes

- IDA MCP `xrefs_to 0x0069b49c` reports a `ScrolledTextControlPaneForMadeBy::OnTimerEvent` close reference at `0x004ff6eb`, constructor writes at `0x00500465` and `0x0050046c`, singleton clear at `0x005023e0`, and destructor clear at `0x00502926`.
- IDA MCP confirms constructor/destructor references and the `0x005023e0` singleton clear helper; live address evidence is the proof source for this singleton.
- The existing scrolled-text docs previously described this as a generic active-dialog close path. Current IDA xrefs tie this address specifically to `g_pNewHistoryDialog`.
- IDA MCP `xrefs_to 0x005023e0` reports a constructor-context xref at `0x00601f62`, consistent with small cleanup/unwind support rather than an independent feature entry point.
- 2026-05-26 recheck classifies `0x005023e0` as compiler-generated constructor EH cleanup and records it in [UID:0000VN][-ignored](by-memory/-ignored.md), while keeping `g_pNewHistoryDialog` itself reconstructable project data.
- 2026-06-16 C001 live MCP refresh used session `c001_midiplayer_rdata_20260615` (`NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready, strings cache ready). `get_bytes 0x0069b490` returns a zeroed singleton-adjacent window, superseding older `0xffffffff` byte notes in the support page/report. `xrefs_to 0x0069b49c` reconfirmed exactly five references: made-by scrolled-text close read `0x004ff6eb`, constructor publish/fallback writes `0x00500465`/`0x0050046c`, clear helper `0x005023e0`, and scalar deleting destructor clear `0x00502926`.
- C001 saved the IDA function names `NewHistoryDialogPane_Constructor`, `NewHistoryDialogPane_ClearSingletonHelper`, and `NewHistoryDialogPane_ScalarDeletingDestructor` after a successful dry run. The data-slot rename to `g_pNewHistoryDialog` was skipped because the current MCP rename data path requires an existing global-name key and the slot is not exposed in the names/globals index; the documentation alias remains supported by the xref/storage evidence.
- `xrefs_to 0x00500410` still reports no direct constructor-start references, while `xrefs_to 0x005023e0` reports the constructor-context cleanup reference at `0x00601f62`. B003's 2026-06-17 raw PE pointer scan also found no absolute-VA pointer to `0x00500410`, so constructor reachability is now recorded as a source-history caveat instead of an ownership blocker for this singleton.

## Lifecycle Evidence

| Site | Access | Meaning |
| --- | --- | --- |
| `0x00500465` in `0x00500410-0x005005b4` | write `this` | `NewHistoryDialogPane` constructor publishes the active `HISTORYN.EPF` / `MADEBY` dialog. |
| `0x0050046c` in `0x00500410-0x005005b4` | write `0` | Constructor-family fallback clear if the adjusted pointer is null. |
| `0x004ff6eb` in `0x004ff6c0-0x004ff725` | read | `ScrolledTextControlPaneForMadeBy` closes the active dialog when credits scrolling reaches the end. |
| `0x005023e0-0x005023eb` | write `0` | `ClearNewHistoryDialogSingleton` compact constructor-cleanup helper clears the singleton. |
| `0x00502926` in `0x00502920-0x00502965` | write `0` | Scalar deleting destructor clears the singleton before base cleanup/free handling. |

## Open Questions

- The current executable still has no direct constructor-start xref and the bounded raw PE/VA/RVA/rel32 scans find no route to `0x00500410`; this is a retained-source launcher-history caveat, not an ownership or C++ blocker.
- Original symbol spelling is stripped. `g_pNewHistoryDialog` is retained as the strongest current project name because it is type-consistent across the owner class, physical slot, scroller consumer, and adjacent global conventions.

## Accepted Type, Linkage, And One-Definition Closure

- Exact type is `NewHistoryDialogPane *`; no `void *`, base pointer, handle, integer, or template-static duplicate fits the constructor/vtable/consumer evidence.
- The class-external scroller read requires external linkage. File-local `static`, private class-static, duplicate physical emission, and standalone template-member alternatives are rejected.
- C++03 zero spelling `0` is the highest-probability human initializer. UID0001PV's PE virtual-tail mapping proves loader zero and rejects historical `0xffffffff`.
- Emitter order is global position 0, class position 10, and method cluster position 20, producing declaration dependencies before definitions without duplicates.
- Exactly five storage refs remain: runtime read `0x004ff6eb`; constructor writes `0x00500465/0x0050046c`; constructor-EH direct-base clear `0x005023e0`; scalar-wrapper direct-base clear `0x00502926`.
- Constructor adjustment plus Singleton PMD `{0x26c,-1,0}` prove that the four writes are compiler/template lowering, not authored assignments. Human source contains only this definition and the direct Singleton base declaration.
- No direct constructor-start xref, absolute VA/RVA/raw pointer, direct rel32 route, second reader/writer, getter, guard, allocation, or direct delete survives.
- Physical evidence is [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md); compiler data is [UID:0004VL][0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData](by-memory/0x0061daf0-0x0061db8c.NewHistoryDialogPaneVtableData.md) and [UID:0004VM][NewHistoryDialogPaneVtables](by-type/by-vtable/NewHistoryDialogPaneVtables.md).

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069b49c` is `dword_69B49C`, size `4`, in `.data`, with 5 data xrefs.
- Live IDA xrefs confirm the documented constructor writes at `0x00500465` and `0x0050046c` in `0x00500410`, singleton clear at `0x005023e0` in `ClearNewHistoryDialogSingleton`, destructor clear at `0x00502926` in `0x00502920`, and scrolled-text consumer at `0x004ff6eb` in `0x004ff6c0`.
- Live IDA decompilation on 2026-06-05 confirms `0x00500410` stores `this` into `dword_69B49C` and installs the `NewHistoryDialogPane` vtable; `0x005023e0` and `0x00502920` clear the singleton during cleanup/destruction.
- [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) remains the canonical memory page for this slot and matches the live IDA check.
- [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md) and [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md) document the dialog resources, constructor/event/destructor ranges, ignored compiler cleanup/thunk spans, and unresolved direct-caller question.
- The unresolved indirect constructor caller remains a source-history caveat because this pass verified the singleton storage and xrefs, not the menu/menu-command path that creates the dialog.

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
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b49c` and decompilation of `0x00500410`, `0x005023e0`, and `0x00502920` prove NexusTK-owned `NewHistoryDialogPane` singleton storage owned by [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md). No singleton declaration C++ was added in that pass because final declaration/header placement was still open.
- 2026-06-06: Raised grading from `80/82` to `84/88`.
  - Before: the page had the correct owner and xref summary but still carried older scoring and one unresolved raw helper token.
  - After: added a lifecycle table covering constructor publish/fallback clear, made-by scrolled-text close read, cleanup helper clear, and scalar deleting destructor clear; also normalized `sub_5023E0` to `ClearNewHistoryDialogSingleton`.
  - Evidence: [UID:0001PV][0x0069b49c-0x0069b4a0.g_pNewHistoryDialog](by-memory/0x0069b49c-0x0069b4a0.g_pNewHistoryDialog.md) now records the exact slot at `86/90`, with five direct data refs and write/read-site tables; confidence remains below final-audit quality because direct constructor reachability and final declaration spelling remain open.
- 2026-06-16 C001 Goal 2 global/source-quality refresh:
  - Before: `84/88`, with exact singleton evidence but stale byte notes in support material and generated IDA function names.
  - Changed to: `85/90`; owner/emitter remain [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), and reconstruction C++ remains blank.
  - Summary/evidence: live MCP reconfirmed zeroed current storage bytes, the exact five singleton refs, no direct constructor xref, and constructor-context cleanup-helper reachability; C001 saved the three source-quality lifecycle function names. Remaining caveats are historic direct menu/constructor reachability and final declaration spelling.
- 2026-06-17 B003 source-quality support update: raw PE scanning found no absolute-VA pointer to constructor start `0x00500410`, while the related key/mouse/destructor vtable targets are represented; the no-caller result remains a documented launcher-path caveat, not a singleton ownership or [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md) C++ blocker.
- Historical 2026-06-19 B005 destructor source-quality support update emitted an authored destructor clear at that checkpoint. The 2026-07-21 direct-Singleton EBO analysis supersedes that interpretation and removes the explicit destructor body.
- 2026-07-21 B004 UID0001PV accepted callback: raised the semantic global to `92/94`, retained owner/emitter UID0000LQ, set position 0, installed the exact forward declaration and sole external zero definition, closed type/linkage/one-definition/source placement, preserved all five refs and the no-constructor-route caveat, separated compiler Singleton effects, and linked real vtable UIDs 0004VL/0004VM.
