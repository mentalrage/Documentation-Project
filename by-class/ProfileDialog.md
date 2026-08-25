*** UID:0000AU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ProfileDialog : public DialogPane
{
public:
    ProfileDialog();
    virtual ~ProfileDialog();
    virtual void OnControlCommand(int controlIndex, int notifyCode);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ProfileDialog

## UID0004E0 Constructor And Class Closure - 2026-08-01

- [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) now carries the exact source-ready `ProfileDialog::ProfileDialog()` definition. This class H carries the declaration once; the class CPP contains only `[[CHILDREN]]` so exact method children own definitions without duplication.
- `ProfileDialog` is a fieldless `DialogPane` derivative with complete-object size `0x26c`. Independent callers at `0x0053e139` and `0x005bd273` each allocate exactly `0x26c`; current `DialogPane` is exactly `0x26c`; no constructor, action, or destructor access requires a derived data member.
- Constructor vptr views are installed at `+0`, `+0xa0`, and `+0xa4` from tables `0x00620f80`, `0x00620fe0`, and `0x00621010`. These are compiler layout effects of the class and inherited interfaces, not handwritten fields.
- The constructor selects exact compact/current `DLGPROFL.EPF` / `DLGPROFL.PAL` resources or exact legacy `PR` / `NP` literals through established `g_useEpfAssets`; constructs the background, text control, and one or two image buttons in deterministic id order; preloads nonempty `g_pConfig->m_selectedProfileName`; then calls `OnCreate`, `OnShow`, and `SlideOpenVertical` in order.
- Apparent `this+0x1fc` storage is inherited `DialogPane::m_controlManager`, not a ProfileDialog member. Source uses inherited control APIs, `ControlPane::SetHandlesEnterKey(bool)`, and `TextEditControlPane::GetTextEditPane() const`; no raw offset or illegal private access is needed.
- Historical UID0001DT/B008 correctly established class ownership, vtables, method split, callers, and source root but deferred source on helper/field uncertainty. That no-code conclusion is superseded by the current exact support contracts; the valid historical range and ownership evidence remains retained below.

## UID0001DU Refresh Helper Closure - 2026-07-28

- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) is the exact retained ProfileDialog.cpp file-local `RefreshProfileData` helper. It is associated with this class source but remains file-owned rather than a speculative class member.
- Exact source is `g_activeMapPane->RefreshSelectedProfileData();`. The established external global is [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), type `MapPane *`, storage [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md).
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) is `MapPane::RefreshSelectedProfileData()`, not a ProfileStorage cdecl helper. All three call sites prepare a MapPane receiver; optimized code simply does not read incoming `this`.
- The action handler performs the same direct active-MapPane member call after accepted text is committed. This supports an inlined trivial helper call while preserving UID0001DU as a separate exact body after the nine-byte padding fence.
- UID0001DU has exhaustive zero-route evidence and exact formal CPP. A nonvirtual ProfileDialog member remains a lower-ranked historical-source possibility, but the file-local form avoids inventing an incomplete ProfileDialog declaration or UDT.
- The class score is `88/90`: helper/global/callee source blockers are resolved, while independent constructor/action callback signatures and complete 0x26c class layout still cap the class page.

## Status

- Confidence: very strong for class behavior, file ownership, exact child split, fieldless layout, source-ready constructor, retained refresh helper, active MapPane route, and storage boundary; strong for inferred source spellings and the still-independent action callback.
- Likely source file: [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md).
- Split/index parent: [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md), now non-emitting.
- Current source-bearing method children: [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md), [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md), and [UID:0004E2][0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction](by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md).
- Formal source: exact class declaration in H; class CPP is `[[CHILDREN]]`; constructor and ordinary destructor definitions emit from exact method children. The action child remains independently blank pending its own callback-signature/source-body closure.

## Class Purpose

`ProfileDialog` is the fieldless `DialogPane`-derived profile UI dialog. It builds either the compact `DLGPROFL.EPF` layout or older `PR`/`NP` profile layout, displays `g_pConfig->m_selectedProfileName`, accepts or cancels profile text selection, writes accepted text back to that field, invokes `g_activeMapPane->RefreshSelectedProfileData()`, and notifies the dialog/session dispatcher when closed.

## Exact Class Layout And Source Contract

- Complete object size is `0x26c`, exactly equal to `DialogPane`; the class introduces no source data members.
- Primary, secondary, and tertiary ProfileDialog interface views begin at `+0`, `+0xa0`, and `+0xa4`. Their vptr stores and deleting wrappers remain compiler-generated and are excluded from handwritten source.
- Inherited `DialogPane::m_controlManager` at `+0x1fc` owns child-control indexing. The action handler's access to child id 1 does not establish a derived edit-control field.
- The declaration exposes the exact source constructor, virtual ordinary destructor, and `OnControlCommand(int controlIndex, int notifyCode)` override. The class declaration has no speculative fields, raw offsets, decompiler types, vtable members, or scalar-delete APIs.
- Class CPP remains only `[[CHILDREN]]`; exact children carry method definitions and maintain one-definition source topology.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md) | `0x0053f940-0x0053fd95` | Exact source-ready constructor: fieldless `0x26c` layout, current/legacy resources and geometry, deterministic controls, guarded selected-profile preload, and create/show/slide lifecycle. |
| [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md) | `0x0053fda0-0x0053fdbf` | Restores ProfileDialog vtables and tail-jumps to shared base teardown; source-level C++ is an empty `ProfileDialog::~ProfileDialog()`. |
| [UID:0004E2][0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction](by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md) | `0x0053fdc0-0x0053fe87` | On accept, reads/sanitizes selected profile text and copies it into `dword_67A7C8 + 0x2912b8`; on accept/cancel, applies close and dispatches notification. |
| [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) | `0x0053fe90-0x0053fe9b` | Retained ProfileDialog.cpp `RefreshProfileData` helper; loads `g_activeMapPane` and tail-forwards to `MapPane::RefreshSelectedProfileData`; exhaustive no-route result retained. |
| [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) | `0x005429a0-0x005429f5` | Compiler scalar-wrapper coverage for [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md). |

## Evidence Notes

- B006 live read-only MCP session `b3b2bf88` on 2026-08-01 reconfirmed the constructor range/complexity, exact padding successor, two `0x26c` callers, three vptr views, DialogPane/TextEditControlPane/Config layouts, helper contracts, string literals, and source-ready body.
- B008 2026-07-02 split review used fresh MCP session `b010_0002r7_20260702` after supervisor resume; the canonical IDB was healthy and Hex-Rays-ready.
- Function boundaries are exact: constructor `0x0053f940-0x0053fd95`, ordinary destructor `0x0053fda0-0x0053fdbf`, action handler `0x0053fdc0-0x0053fe87`, and adjacent refresh wrapper `0x0053fe90-0x0053fe9b`.
- Padding separates the exact methods: `0x0053fd95-0x0053fda0` is eleven `CC` bytes, `0x0053fdbf-0x0053fdc0` is one `CC` byte, and `0x0053fe87-0x0053fe90` is nine `CC` bytes.
- Constructor callers are `0x0053e139` and `0x005bd273`; each allocates exactly `0x26c`, proving the fieldless DialogPane-derived complete-object size.
- Action-handler vtable/data ref is `0x00620fc8`.
- Constructor, ordinary destructor, and scalar deleting destructor all write ProfileDialog vtables at `+0x0`, `+0xa0`, and `+0xa4`.
- Compact construction uses `DLGPROFL.EPF`/`DLGPROFL.PAL`; legacy construction preserves exact `PR`/`NP` literals. Both branches create the text control with identical limits, preload only nonempty `m_selectedProfileName`, and preserve the exact branch-local control ordering and common lifecycle tail.
- `0x00542639` and `0x00542644` are adjustor thunks into [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md), with vtable/data refs at `0x00620fe0` and `0x00621010`.
- The generated boost/exception/base destructor label at `0x0049d9f0` is base-owner pollution, not evidence against ProfileDialog ownership.
- `0x0053fe90` remains ProfileDialog.cpp source support, while `0x005063e0` is a MapPane member. ProfileDialog owns the trigger and selected-text commit path, not the full sidecar/JPF/opcode-79 implementation.

## Reconstruction Notes

- This class remains `RECONSTRUCTABLE:TRUE` and emits through [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md).
- The old memory parent [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md) is now `RECONSTRUCTABLE:FALSE` and blank-emitting because exact child pages carry the source methods.
- Formal H now contains the exact fieldless class declaration; formal class CPP contains only `[[CHILDREN]]`. The former complete-layout and constructor blockers are resolved.
- Exact constructor C++ emits from [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md), and the empty source destructor emits from [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md). [UID:0004E2][0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction](by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md) remains a separate source child whose independent action-body formal code is not claimed complete by this callback.
- The `+0x1fc` derived-field interpretation is historical and superseded: current source uses inherited DialogPane control management, so no derived data declaration is required.

## Score Rationale

- Completion `91`: exact fieldless layout, declaration, constructor body route, method-child topology, source/compiler split, resources, selected-profile flow, and retained refresh helper are documented. The independent action-body source and original lexical spellings retain the cap.
- Confidence `93`: two allocation callers, exact base size, vptr views, method siblings, current support UDTs/APIs, resources, and live decompile converge on the class/source shape. Remaining uncertainty is lexical rather than behavioral or structural.

## Cross-References

- [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md)
- [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md)
- [UID:0004E0][0x0053f940-0x0053fd95.ProfileDialogConstructor](by-memory/0x0053f940-0x0053fd95.ProfileDialogConstructor.md)
- [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md)
- [UID:0004E2][0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction](by-memory/0x0053fdc0-0x0053fe87.ProfileDialogHandleDialogAction.md)
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md)
- [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md)
- [UID:0000V9][ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90](by-item/ProfileDialogDestructorAndRefreshHelpers_53fda0_53fe90.md)
- [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md)

## Changes

- 2026-08-01 B006 UID0004E0 accepted implementation callback:
  - Raised `88/90 -> 91/93`; preserved owner/emitter UID0000MR, reconstructable state, blank position, exact child family, refresh helper, and all unrelated historical evidence.
  - Added exact fieldless `DialogPane`-derived `0x26c` declaration in H, class CPP `[[CHILDREN]]`, source-ready constructor route, two allocation callers, three vptr views, current/legacy resource behavior, selected-profile preload, inherited-control explanation, and score rationale.
  - Historicalized the prior constructor/helper/`+0x1fc`/complete-layout no-code blockers as superseded while retaining the valid B008 split and B005 refresh findings.

- 2026-07-28 B005 UID0001DU callback: raised from `85/86` to `88/90`; resolved the retained helper as file-local `RefreshProfileData`, corrected `dword_67A764` to `MapPane *g_activeMapPane`, corrected `sub_5063E0` to `MapPane::RefreshSelectedProfileData`, preserved exact zero-route/padding and B008 split evidence, and retained the former ProfileStorage/free-cdecl interpretation as superseded history.

- 2026-05-30: Changed completion/confidence from `0/0` to `78/78`.
  - Before: The page was unevaluated despite documenting purpose, primary methods, helper ownership, and destructor naming caveats.
  - After: Scored as moderately high completion with medium residual confidence around helper/destructor-owner cleanup.
  - Evidence: Existing method notes and IDA MCP evidence identify constructor/action/refresh/destructor helpers and explain generated base-owner pollution.
- 2026-06-01: Changed completion/confidence from `78/78` to `82/82`, marked reconstructable, and attached parent [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md).
  - Before: exact function endpoints, xref map, and parent confidence were not sufficient for attachment.
  - After: current IDA MCP evidence confirms spans, xrefs, callees, and byte boundaries; final C++ remains deferred.
- 2026-06-10: Raised completion/confidence from `82/82` to `85/86`.
  - Before: the class remained below the current strict `85/85` attachment gate even though the recorded IDA evidence already resolved ownership, function spans, vtable refs, caller/callee sets, and the storage-wrapper boundary.
  - After: the class clears the gate to [UID:0000MR][ProfileDialog](by-file/ProfileDialog.md). Final C++ remains deferred for source-quality field/helper/destructor names.
- 2026-07-02 B008 accepted split implementation:
  - Added exact constructor/destructor/action-handler child links, recorded that [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md) is now a non-emitting split/index parent, and clarified that the scalar deleting destructor [UID:00038G][0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor](by-memory/0x005429a0-0x005429f5.ProfileDialogScalarDeletingDestructor.md) covers source destructor [UID:0004E1][0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor](by-memory/0x0053fda0-0x0053fdbf.ProfileDialogNonDeletingDestructor.md).
