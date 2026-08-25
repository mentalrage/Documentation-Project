*** UID:0000MR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/profile/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ProfileDialog

## UID0004E0 Source-Ready Constructor Topology - 2026-08-01

- `NexusTK/profile/ProfileDialog.cpp` remains the exact physical source root. [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md) emits one fieldless `DialogPane`-derived declaration through H and a class CPP `[[CHILDREN]]` route; exact source definitions stay on their method children.
- [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) now emits the exact constructor. Two independent callers allocate `0x26c`, exactly the `DialogPane` size; three ProfileDialog vptr views and absence of derived storage establish the fieldless class shape.
- Source topology is one-definition and ordered by responsibility: class declaration; exact constructor child; exact ordinary destructor child; exact action-handler child when independently completed; retained file-local `RefreshProfileData` helper at deterministic position 40. The broad UID0001DT page remains a non-emitting index, and scalar deleting/thunk/vptr machinery remains compiler-only.
- Constructor dependencies are explicit and do not change ownership: `g_useEpfAssets` selects current `DLGPROFL.EPF`/`.PAL` versus legacy `PR`/`NP`; DialogPane supplies control and create/show/slide APIs; ControlPane supplies Enter forwarding; TextEditControlPane/TextEditPane supply the exact selected-text insertion path; Config supplies `m_selectedProfileName`; MainUi/BackPane globals supply final placement contexts.
- Persistence remains in `ProfileStorage.cpp`; profile refresh implementation remains `MapPane::RefreshSelectedProfileData()` in `MapPane.cpp`. `ProfileDialog.cpp` owns the dialog, selected-text commit trigger, and its narrow retained forwarding helper, not those dependent implementations.
- Historical UID0001DT/B008 source routing and B005 refresh-helper findings remain valid. Their constructor no-code/helper/field uncertainty is superseded by the accepted UID0004E0 source and support APIs rather than removed from history.

## UID0001DU Retained Refresh Helper Source Route - 2026-07-28

- `NexusTK/profile/ProfileDialog.cpp` owns exactly one [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) file-local definition at deterministic position 40:

```cpp
namespace {

void RefreshProfileData()
{
    g_activeMapPane->RefreshSelectedProfileData();
}

} // namespace
```

- UID0001DU's H block is blank because the helper has internal linkage. It is not a partial ProfileDialog declaration and does not duplicate class source.
- Exact body bytes are `8b 0d 64 a7 67 00 e9 45 65 fc ff`; exact fences are nine `0xcc` bytes before and five after. No incoming code/data/immediate/pointer/vtable route survives.
- The active pointer is established [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), type `MapPane *`. The full callee is [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) as `MapPane::RefreshSelectedProfileData()` in `NexusTK/map/MapPane.cpp`.
- All three callee sites prepare a MapPane receiver; the callee's incoming `this` is optimized unused. The action child contains the same direct call after accepted text commit, supporting the inlined-helper source cause.
- One-definition topology: ProfileDialog.cpp emits only the narrow UID0001DU helper; MapPane.cpp emits the complete UID0001AS member/table/literals; ProfileStorage.cpp retains profile persistence but emits no sidecar refresh duplicate.
- The former ProfileStorage/free-cdecl wrapper assignment is retained only as historical B003/B008 evidence superseded by unanimous receiver and physical source-placement facts.

## Status

- Confidence: very strong for module placement, exact child split, fieldless class declaration, source-ready constructor, retained refresh helper, active MapPane route, and one-definition boundary; strong for inferred constructor spellings and the still-independent action callback.
- Proposed module: `profile/ProfileDialog.cpp`.
- Generated source route: class [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md) and exact method children emit through this file root under `NexusTK/profile/`.
- Current split state: [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md) is a non-emitting split/index parent; exact method children carry source reconstruction.
- Formal route: class H owns the declaration, class CPP is `[[CHILDREN]]`, UID0004E0 owns the constructor body, UID0004E1 owns the ordinary destructor body, and UID0001DU owns the internal-linkage refresh helper. No duplicate class/method/helper definition is emitted.

## File Role

`ProfileDialog.cpp` owns the editable/viewable profile dialog shown from profile/social UI paths. It builds the `Profile` dialog, selects compact or legacy profile resources through `g_useEpfAssets`, displays `g_pConfig->m_selectedProfileName`, accepts/cancels profile text selection, updates that selected-profile storage, invokes `g_activeMapPane->RefreshSelectedProfileData()` after accept, and notifies the surrounding dialog/session UI.

This source should live under `profile/` near `ProfileStorage.cpp`, but it does not own the profile file serializer or full sidecar refresh body. Persistence helpers remain in [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md); the sidecar refresh member belongs to [UID:0000L3][MapPane](by-file/MapPane.md). This file owns the dialog layer, selected-text commit, and narrow retained forward helper.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md) | class route | Profile dialog class owner. |
| [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md) | `0x0053f940-0x0053fe87` | Non-emitting parent/index for constructor, ordinary destructor, and action handler. |
| [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) | `0x0053f940-0x0053fd95` | Exact source-ready constructor: fieldless 0x26c layout, compact/legacy controls/resources, guarded selected-profile preload, and common create/show/slide lifecycle. |
| [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md) | `0x0053fda0-0x0053fdbf` | Ordinary source destructor; formal C++ is empty. |
| [UID:0004E2][0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction](by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md) | `0x0053fdc0-0x0053fe87` | Accept/cancel handler and selected-profile text commit path. |
| [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) | `0x005429a0-0x005429f5` | Compiler scalar-wrapper coverage for source destructor [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md). |
| [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) | `0x0053fe90-0x0053fe9b` | Source-ready file-local `RefreshProfileData`; loads `g_activeMapPane` and tail-forwards to `MapPane::RefreshSelectedProfileData`. |

## Split Notes

`ProfilePane` is a separate profile view pane under the user-look/profile-display UI, not the same dialog source. It appears near `UserLookPane` methods around `0x005a1df0` and should be reviewed with that feature cluster rather than forced into `ProfileDialog.cpp`.

The old `[UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md)` aggregate is no longer the source-emitting body. It remains a semantic ProfileDialog split/index parent with `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank C++ because exact child pages carry constructor, destructor, and action-handler reconstruction.

## Evidence Notes

- B006 live read-only MCP session `b3b2bf88` on 2026-08-01 reconfirmed UID0004E0's exact `0x455` range, eleven-byte successor fence, two `0x26c` allocation callers, three ProfileDialog vptr views, current base/support UDTs, exact literals/arguments, and source-ready constructor contracts.
- B008 2026-07-02 MCP evidence used session `b010_0002r7_20260702`; the canonical NexusTK IDB was healthy, auto-analysis-ready, and Hex-Rays-ready.
- Function map: constructor `0x0053f940-0x0053fd95`, ordinary destructor `0x0053fda0-0x0053fdbf`, action handler `0x0053fdc0-0x0053fe87`, and refresh wrapper `0x0053fe90-0x0053fe9b`.
- Padding map: `0x0053fd95-0x0053fda0`, `0x0053fdbf-0x0053fdc0`, `0x0053fe87-0x0053fe90`, and `0x0053fe9b-0x0053fea0` are `CC` alignment bytes.
- Constructor xrefs are `0x0053e139` and `0x005bd273`, and both callers allocate exactly `0x26c`; action-handler vtable/data ref is `0x00620fc8`.
- Constructor source preserves the exact branch duplication, resources, control order/ids, rectangles, 250-character/16-line limits, guarded `InsertTextRange`, selected hover/focus/pending/background state, and final `OnCreate`/`OnShow`/`SlideOpenVertical` order.
- Constructor/action callees preserve the dialog/storage split: the action handler uses text read `0x00498c10`, sanitizer `0x005957c0`, `_wcscpy_s`, dialog apply/close `0x0049eb90`, refresh `0x005063e0`, and dispatcher notify `0x00469180`.
- The helper `0x0053fe90` is exactly `mov ecx, g_activeMapPane; jmp 0x005063e0`; exhaustive no-route evidence is preserved, and it emits independently as file-local source rather than being folded into the action child or callee body.
- `0x0053fda0`, [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md), and [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) both restore ProfileDialog vtables before shared base teardown. Generated boost/exception/base labels are source-owner pollution.

## Cross-References

- [UID:0000AU][ProfileDialog](by-class/ProfileDialog.md)
- [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md)
- [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md)
- [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md)
- [UID:0004E2][0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction](by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md)
- [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md)
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md)
- [UID:0000V9][ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90](by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)
- [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md)

## Changes

- 2026-08-01 B006 UID0004E0 accepted implementation callback:
  - Raised `90/92 -> 91/93` while preserving `NexusTK/profile/`, `CANONICAL_OWNER:FILE`, exact child split, retained helper, ProfileStorage/MapPane boundaries, and all unrelated evidence/history.
  - Added the exact class-H/method-child one-definition topology, fieldless `0x26c` constructor source route, source ordering, complete constructor dependency boundary, live caller/vptr/layout evidence, and compiler-only exclusions.
  - Historicalized the earlier constructor no-code/helper/field blockers as superseded by UID0004E0 without pruning valid B008 split or B005 refresh-helper research.

- 2026-07-28 B005 UID0001DU callback: raised from `86/86` to `90/92`; added exact file-local helper CPP and deterministic position, corrected `g_activeMapPane` and `MapPane::RefreshSelectedProfileData` dependencies, documented inlined-equivalent action behavior and one-definition output, and historicalized the old ProfileStorage/free-cdecl route without pruning sidecar behavior.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Summary/evidence: the page documents dialog role, proposed contents, split notes, IDA evidence, helper/destructor caveats, storage relationship, and cross-references; confidence remains capped by one short unmodeled helper and base-owner pollution.
- 2026-06-01: Changed `PROPOSED_RECONSTRUCTION_PATH` from blank to `NexusTK/profile/`, raised completion/confidence from `82/78` to `84/82`, and added current IDA xref/callee/boundary evidence.
  - Before: the page had a proposed module name but no validator path and parent confidence was below the child-attachment threshold.
  - After: the source path is explicit and confidence is high enough for child pages to attach to this file while keeping final C++ reconstruction deferred.
- 2026-06-10: Raised completion/confidence from `84/82` to `86/86`.
  - Before: the file parent still sat below the current strict `85/85` child-assignment gate even though its child pages already contained endpoint, xref, callee, vtable, padding, and storage-split evidence.
  - After: the file parent clears the gate for the ProfileDialog class, core memory range, destructor/helper index, and refresh wrapper. Final source emission remains blank because field/helper names and destructor/thunk source shape are not yet final.
- 2026-07-02 B008 accepted split implementation:
  - Added exact child inventory for [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md), [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md), [UID:0004E2][0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction](by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md), and [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md), recorded that [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md) is a non-emitting split/index parent, and preserved the ProfileStorage boundary.
