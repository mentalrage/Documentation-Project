*** UID:0000R3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00054J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
HistoryViewingPane *g_pHistoryViewingPane = NULL;

template <>
Singleton<HistoryViewingPane>::Singleton()
{
    g_pHistoryViewingPane = static_cast<HistoryViewingPane *>(this);
}

template <>
Singleton<HistoryViewingPane>::~Singleton()
{
    g_pHistoryViewingPane = NULL;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern HistoryViewingPane *g_pHistoryViewingPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pHistoryViewingPane

## Status

- Confidence: strong for singleton address and class owner.
- Address: `0x0069b494`
- Primary memory doc: [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md)
- Owner class: [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- Likely owner source: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)

## Symbol Role

`g_pHistoryViewingPane` stores the active full-screen story/history viewer opened from the pre-login main menu. The constructor writes it, the main-menu singleton cleanup helper checks it and marks the viewer for deletion, the tiny helper at `0x005023b0` clears it, and the scalar deleting destructor clears it during teardown.

## Evidence Notes

- IDA MCP `xrefs_to 0x0069b494` reports constructor writes at `0x004ffdd6` and `0x004ffddd`, a main-menu cleanup read at `0x004f69dd`, singleton clear at `0x005023b0`, and destructor clear at `0x0050278d`.
- 2026-06-13 live IDA MCP session `a002_batch_clear_timer` reconfirmed the same six direct refs: cleanup read `0x004f69dd`, constructor publish/fallback writes `0x004ffdd6` and `0x004ffddd`, constructor-adjacent cleanup write `0x004ffefa`, helper clear `0x005023b0`, and destructor clear `0x0050278d`.
- 2026-06-13 `lookup_funcs` reconfirmed the owner lifecycle functions that touch the slot: `HistoryViewingPane` constructor `0x004ffd80` size `0x149`, constructor-EH clear helper `0x005023b0` size `0xb`, and scalar deleting destructor `0x00502760` size `0x6c`.
- 2026-05-26 recheck classifies `0x005023b0` as compiler-generated constructor EH cleanup and records it in [UID:0000VN][-ignored](by-memory/-ignored.md), while keeping `g_pHistoryViewingPane` itself reconstructable project data.
- `CloseMainMenuDialogSingletons_004F69A0` marks this singleton for deletion when a main-menu cleanup pass runs.
- IDA also reports a data xref at `0x004ffefa` outside a named function; treat this as constructor-adjacent unwind/support data until reviewed more deeply.
- 2026-06-16 C001 live IDA MCP saved `g_pHistoryViewingPane`, `HistoryViewingPane_Constructor`, `ClearHistoryViewingPaneSingleton`, `HistoryViewingPane_ScalarDeletingDestructor`, `CloseMainMenuDialogSingletons`, `OpenStoryViewingPane`, and `OpenHistoryViewingPane`. Current `get_bytes 0x0069b490 size 0x10` returns zero-filled storage, correcting the older `0xffffffff` initial-value wording in the exact memory child. `xrefs_to 0x0069b494` still reports the same six lifecycle refs. Fresh decompilation confirms constructor publish/fallback clear, the compact clear helper, scalar deleting destructor clear, and main-menu cleanup read/schedule behavior.
- The retained launch wrappers were actively rechecked: `xrefs_to 0x004f90c0` and `xrefs_to 0x004f9140` still return zero refs, but both functions decompile cleanly and allocate a 264-byte `HistoryViewingPane` with `STORY.*` or `HISTORY.*` resource names based on `g_useEpfAssets`. This makes them real retained wrappers with no current static callers, not evidence for moving ownership away from `HistoryViewingPane`.

## Open Questions

- Whether the retained launch wrappers at `0x004f90c0` and `0x004f9140` are live callback targets or dead retained helpers; 2026-06-16 direct xref lookup still reports none, while decompilation proves they are real story/history viewer allocation wrappers.
- The singleton source route is resolved: this page emits the NULL-initialized definition and `Singleton<HistoryViewingPane>` specializations in CPP plus the extern declaration in H, ordered after the class through [UID:00054J][HistoryViewingPaneFileShell](by-item/HistoryViewingPaneFileShell.md). No source-placement blocker remains.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | Covers current storage bytes, six-ref lifecycle, compiler-lowered publication/clear behavior, retained-wrapper reachability, exact definition/extern/specialization source, owner, and emitter order. |
| Confidence | 94 | Storage, owner, lifecycle, source spelling, and CPP/H placement are strongly supported. Only the retained wrappers' original reachability remains unresolved, without affecting singleton reconstruction. |

## Cross-References

- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)

## Historical Superseded Assumptions

- Earlier revisions left the singleton declaration spelling and source placement unresolved and therefore emitted no C++. That was appropriate before the class, file shell, compiler cleanup, and physical storage routes were reconciled. The accepted source now uses `g_pHistoryViewingPane`, a NULL-initialized CPP definition, H extern declaration, and `Singleton<HistoryViewingPane>` constructor/destructor specializations through UID00054J.
- Earlier drafts treated constructor/destructor writes as authored assignments. The complete lifecycle shows those writes are compiler-lowered empty-base `Singleton<HistoryViewingPane>` construction/destruction; retaining them in the specializations reproduces the behavior without decompiler-shaped class methods.

## Historical Change Log

- 2026-08-16 UID0000JW accepted whole-file callback: raised to `92/94`, routed after the class at file-shell position `20`, and installed the exact NULL-initialized global plus `Singleton<HistoryViewingPane>` publication/clear specializations and extern declaration. This source shape explains the constructor, unwind, normal destruction, and consumer lifecycle writes without duplicating manual singleton assignments in class methods.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, memory doc, owner, full-screen viewer singleton role, constructor/main-menu cleanup/clear/destructor xrefs, EH cleanup classification, and open launch-wrapper question.
- 2026-06-05: Marked reconstructable under [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md). Evidence: live IDA MCP reports six xrefs to `0x0069b494`; decompilation confirms constructor `0x004ffd80`, cleanup helper `0x005023b0`, and scalar deleting destructor `0x00502760` write/clear `dword_69B494`.
- 2026-06-13 Agent-A001 Goal 2 gate repair:
  - Before: `86/84`, attached to [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) but one point below the strict direct-child confidence gate.
  - After: `87/86`, parent unchanged.
  - Summary/evidence: live IDA MCP reconfirmed all six direct singleton refs plus the constructor/helper/destructor function identities and sizes. Confidence now clears `85` because the slot's storage, owner, lifecycle, and direct parent are all supported by exact memory evidence; final source declaration spelling and retained launcher reachability remain non-final caveats.
- 2026-06-16 C001 safe IDA refresh:
  - Before: `87/86`, with stale exact-memory initial-value wording and unresolved retained launcher evidence.
  - Changed to: `88/89`; saved singleton/lifecycle/launcher labels in IDA.
  - Summary/evidence: live IDA confirmed current zero-filled storage, six singleton refs, constructor/helper/destructor/main-menu cleanup behavior, and zero xrefs to retained launch wrappers while proving both wrappers still construct story/history viewers. No prototypes, types, members, raw functions, or final C++ were changed.
