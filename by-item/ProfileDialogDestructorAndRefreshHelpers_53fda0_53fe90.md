*** UID:0000V9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90

## UID0001DU Source-Quality Closure - 2026-07-28

- This item remains an evidence/index page and emits no duplicate source. Exact children own source or compiler coverage.
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) is now the source-ready ProfileDialog.cpp file-local `RefreshProfileData` helper with exact body `g_activeMapPane->RefreshSelectedProfileData();`.
- `g_activeMapPane` is the established externally linked `MapPane *` at `0x0067a764`; [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) is a MapPane member, not a free ProfileStorage cdecl helper.
- All three callee sites prepare a MapPane receiver. UID0001DU itself has zero incoming code/data/immediate/pointer/vtable routes; the direct action-handler equivalent supports a retained/inlined trivial helper source cause.
- Preserve the exact nine-byte and five-byte padding fences, all destructor/vtable/base-teardown evidence, both adjustor thunks, scalar deleting wrapper behavior, and the separation between human destructor source and compiler ABI support.
- The former `ProfileStorage refresh wrapper` and `source-authored or compiler-emitted` uncertainty is retained only as superseded B003/B008 history.

## Status

- Confidence: very strong for helper behavior, destructor/wrapper split, exact source/compiler boundary, active MapPane route, and zero-route evidence; strong for the inferred original helper spelling.
- Proposed owner file: [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md), with the full refresh target body owned by [UID:00007Q][MapPane](by-class/MapPane.md) through [UID:0000L3][MapPane](by-file/MapPane.md).
- Current split state: ordinary destructor is now exact child [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md); scalar wrapper [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) covers that source destructor.
- Rebuild handling: index over destructor/thunk/refresh helper facts; formal C++ remains blank here to avoid duplicating child method source.

## Helper Summary

| Address range | Proposed role | Behavior |
| --- | --- | --- |
| [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md) | ordinary/non-deleting destructor | Restores the three ProfileDialog vtables, then tail-jumps to shared base teardown; formal source C++ is empty destructor. |
| [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) | source-authored file-local `RefreshProfileData` | Loads `MapPane *g_activeMapPane` into `ecx` and tail-forwards to `MapPane::RefreshSelectedProfileData` at `0x005063e0`; exact source CPP is emitted by the child. |
| `0x00542639-0x00542644` | adjustor thunk | Adjusts `this` by `-0xa0` bytes and forwards to [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md); exact range is part of [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md). |
| `0x00542644-0x0054264f` | adjustor thunk | Adjusts `this` by `-0xa4` bytes and forwards to [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md); exact range is part of [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md). |
| [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) | scalar deleting destructor wrapper | Restores the three ProfileDialog vtables, calls shared base teardown, conditionally frees memory, and covers source destructor [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md). |

## IDA MCP Evidence

- 2026-07-02 B008 refreshed current MCP evidence in session `b010_0002r7_20260702`.
- `lookup_funcs` confirms `0x0053fda0-0x0053fdbf`, `0x0053fe90-0x0053fe9b`, `0x00542639`, `0x00542644`, and `0x005429a0-0x005429f5`.
- [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md) writes ProfileDialog vtables at `+0x0`, `+0xa0`, and `+0xa4`, then tail-jumps to shared base teardown at `0x0049d9f0`.
- IDA's boost/exception destructor name for the base teardown path is naming pollution; ProfileDialog vtable stores prove ProfileDialog source ownership.
- [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) mirrors the same vtable restore/base teardown and conditionally calls delete helper `0x004f4ac0`.
- `0x00542639` and `0x00542644` are adjustor thunk starts, both forwarding to `0x005429a0`, with data refs from secondary ProfileDialog vtables `0x00620fe0` and `0x00621010`.
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) tail-jumps to `0x005063e0`; it has no direct callers/xrefs in current evidence.
- `ProfileDialogHandleDialogAction` [UID:0004E2][0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction](by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md) calls `0x005063e0` directly after accepting and storing selected profile text, proving the refresh target is a dependency of ProfileDialog behavior rather than a ProfileDialog-owned body.
- Raw bytes confirm wrapper boundaries: `0x0053fe87-0x0053fe90` and `0x0053fe9b-0x0053fea0` are `CC` alignment padding.

## Ownership Decision

Keep the destructor/thunk facts with `ProfileDialog.cpp` while routing exact source through child pages. The ordinary destructor body is now [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md), and scalar wrapper [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) covers that destructor. The generated `TransferReplyAlert`/boost/base destructor spelling is rejected as base-owner pollution.

Keep real profile sidecar refresh work at `0x005063e0` with [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md). [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) remains a small dialog-neighborhood wrapper into that storage helper, not part of the old [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md) range.

## Current Cross-Document Split

| Evidence page | What it now owns | Why it matters for this item |
| --- | --- | --- |
| [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md) | Non-emitting split/index for exact ProfileDialog constructor, ordinary destructor, and action-handler children. | Records the aggregate split and padding boundaries without emitting duplicate source. |
| [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md) | Source-level ordinary destructor. | Carries the formal empty `ProfileDialog::~ProfileDialog()` C++. |
| [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) | Scalar deleting destructor wrapper coverage. | Documents compiler wrapper mechanics and points to [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md) for source destructor emission. |
| [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) | Tiny `mov ecx, dword_67A764; jmp 0x005063e0` wrapper. | Keeps the wrapper separate while making clear the refresh target is ProfileStorage behavior. |
| [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) | Selected-profile sidecar probing, optional FaceRipper launch, `.jpf` validation, and opcode `79` packet queueing. | Confirms the wrapper target is storage/profile-image logic and should not be folded into `ProfileDialog.cpp` beyond the local wrapper. |
| [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) and [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md) | Shared dialog adjustor thunk and scalar deleting destructor islands. | Preserve broader thunk/wrapper island context without pretending the islands have a single ProfileDialog-only source owner. |
| [UID:000261][0x00620c74-0x0062179c.OptionMacroProfileReadOnlyData](by-memory/0x00620c74-0x0062179c.OptionMacroProfileReadOnlyData.md) | Mixed option/macro/friend/profile `.rdata`, including ProfileDialog vtables. | Supports ProfileDialog vtable ownership and keeps profile storage/refresh as a dependency instead of a vtable-data owner. |

## Remaining Modeling Gaps

- The ordinary destructor source shape is resolved as an empty destructor on [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md).
- The scalar deleting destructor source duplication is resolved: [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) documents wrapper coverage and does not emit separate C++.
- The storage boundary is explicit: `0x0053fe90` belongs with the dialog neighborhood as a wrapper, while `0x005063e0` and sidecar extension logic stay with [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md).
- The refresh wrapper's exact source-authored versus compiler-emitted status remains below final quality, so this index page still keeps formal C++ blank.

## Cross-References

- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md)
- [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md)
- [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md)
- [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md)
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md)
- [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md)
- [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md)

## Changes

- 2026-07-28 B005 UID0001DU callback: raised from `85/90` to `89/93`; separated the retained file-local source helper from compiler destructor wrappers, corrected the global and MapPane member route, preserved exact thunk/destructor/padding/no-route evidence, and historicalized the old ProfileStorage/free-cdecl uncertainty.

- What existed before: the thunk and scalar deleting destructor ranges were documented one byte short.
- What it was changed to: the adjustor thunks now use `0x00542639-0x00542644` and `0x00542644-0x0054264f`; the scalar deleting destructor now uses `0x005429a0-0x005429f5`.
- Summary and evidence: IDA MCP review on 2026-05-28 resolved the shared thunk and scalar deleting destructor island endpoints.
- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 reconfirmed the destructor helper, adjustor thunk, scalar deleting destructor, and refresh wrapper behavior. The score remains below 95 because final emitted-source modeling and exact source placement across ProfileDialog/ProfileStorage/base-dialog teardown still need a full audit.
- 2026-06-01: Changed completion/confidence from `70/85` to `72/88`, attached parent [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md), and corrected the local helper endpoints to exclusive-end ranges.
  - Before: the helper table still used `0x0053fda0-0x0053fdbe` and `0x0053fe90-0x0053fe9a`, and parent attachment was blank.
  - After: current IDA MCP evidence records the exact helper ends, wrapper boundary padding, and vtable/destructor xrefs. C++ remains blank pending final emitted-source policy.
- 2026-06-07 A009: Raised completion from `72` to `76` while keeping confidence at `88`.
  - Before: the page listed helper behavior but did not summarize how the current ProfileDialog core, wrapper, ProfileStorage sidecar, dialog thunk islands, and mixed `.rdata` pages divide ownership.
  - After: added the cross-document split and remaining modeling gaps so future work can update the exact page that owns each unresolved destructor/wrapper/data question. No final C++ was emitted because the source-visible destructor/thunk shape and wrapper modeling remain below the 95/95 gate.
- 2026-06-10 A002: Raised completion/confidence from `76/88` to `85/90`.
  - Before: the helper index had enough endpoint, xref, vtable, split-ownership, and remaining-gap evidence to justify attachment, but its completion score still failed the current strict gate.
  - After: the page clears the gate to [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md) while keeping final C++ blank below the `95/95` source-quality bar.
- 2026-07-02 B008 accepted split implementation:
  - Updated the destructor side to point to [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md), recorded [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) as wrapper coverage for that child, and preserved [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) as the ProfileStorage refresh wrapper boundary.
