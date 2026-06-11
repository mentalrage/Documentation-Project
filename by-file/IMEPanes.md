*** UID:0000K5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# IMEPanes

## Status

- Confidence: strong for pane family ownership, source boundary, and direct IMEStatusPane routing; medium-high for exact original file name and remaining field/message names.
- Proposed source path: `input/IMEPanes.cpp`
- Proposed header path: `input/IMEPanes.h`
- Primary contents: `IMEPane`, `IMEStatusPane`, `IMECompositionPane`, `IMECandidatePane`, candidate-string deque support, and IME helper methods.
- Evidence basis: IDA MCP boundary/xref/decompile checks.

## File Role

This module owns the pane-side IME UI: the hidden/root IME pane singleton, mode status label, composition string popup, candidate list popup, and the candidate-string container used by candidate rendering.

Keep this separate from [UID:0000K6][InputMan](by-file/InputMan.md). `InputMan` owns the Win32/IMM window-message bridge and emits IME events, while `IMEPanes.cpp` owns the visible pane reactions to those events and the focus-pane list used by text-entry controls.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md) | `0x004e70f0-0x004e737b`, exact scalar destructor [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md), adjustor wrappers in [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md) | Bottom-right ENG/IME status label and mode-change handler. |
| [UID:00006G][IMECompositionPane](by-class/IMECompositionPane.md) | `0x004e7380-0x004e7912`, exact helper [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md), exact scalar destructor [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md) | Composition text popup, drag behavior, commit/update, and paint. |
| [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md) | exact helper [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md), exact ordinary destructor [UID:00031F][0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor](by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md), exact scalar destructor [UID:00031I][0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor](by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md) | Candidate list sizing, positioning, string copy, message handling, and paint. |
| [UID:00006H][IMEPane](by-class/IMEPane.md) | `0x004e7f20-0x004e8433`, exact focus-anchor helper [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md), singleton clear helper [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md), exact scalar destructor [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md) | Singleton root pane, child popup lifetime, focus-pane list, and IME event dispatch. |
| [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md) / [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) | `0x004e8450-0x004e8ae6`, `0x004e9710-0x004e97a3` | STL `std::deque<std::wstring>` helper materialization. Final source should express a normal candidate-string container member/local, not a handwritten product class file. |
| [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md) | [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md) | Active IME pane singleton and focus-list owner. |

## Evidence Notes

- IDA MCP confirms a contiguous IME pane/source neighborhood from `0x004e70f0` through `0x004e8ae6`, followed by [UID:0000K6][InputMan](by-file/InputMan.md) at `0x004e8af0`.
- IDA MCP confirms `CandidateStringQueue::AppendOwnedString` at `0x004e9710`; its direct callers are inside `InputMan::HandleWindowMessage` at `0x004e91a6` and `0x004e9234`.
- 2026-05-26 IDA MCP string/xref/decompile checks identify the `CandidateStringQueue` helpers as MSVC/Dinkumware `std::deque<std::wstring>` support: `ReserveAdditional` calls the shared `deque<T> too long` overflow helper, entries are 0x18-byte SSO-7 wide strings, and the deque object has the expected proxy/map/head/count fields.
- IDA MCP confirms `IMEPane` construction at `0x004e7f20` is called from the application startup path at `0x004f639e`.
- `g_pIMEPane` at `0x0069b458` is written by `IMEPane::IMEPane`, cleared by `IMEPane` destruction helpers, and read by composition, candidate, text-edit, text-box, and self-save paths.
- `IMEPane::SetFocusPane` at `0x004e80a0` has direct callers in text-edit and self-save text input paths, which supports keeping it in the IME pane file rather than the caller classes.
- `SetCompositionString` at [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) and `ShowCandidateList` at [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) are currently emitted in `class_FittingRoomDownloadControlPane.cpp`, but IDA places them in the IME cluster and their callers/data flow are IME-specific.
- 2026-05-26 IDA MCP recheck confirms `0x004e7470` is directly called by `IMECompositionPane::OnKeyEvent` at `0x004e782d`, `0x004e7930` is directly called by `IMECandidatePane::HandleIMEMessage` at `0x004e7d13`, and [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md) is a 4-byte `.data` pointer with 17 data references.
- 2026-06-07 Batch 090 live IDA MCP reconfirmed [UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md) as a direct child of this source file: its six methods occupy `0x004e70f0-0x004e737b` plus scalar deleting destructor `0x004e8800-0x004e8855`, `SetText` is only called by the status constructor and mode-change handler, vtable refs target `0x0061c364`/`0x0061c3b0`/`0x0061c3e0`, and the scalar deleting destructor is reached from the two IME adjustor thunks and vtable data inside the documented IME destructor island.
- 2026-06-08 A001 Batch131 split the remaining raw/product cleanup pieces into exact pages under this source family: [UID:00031F][0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor](by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md), [UID:00031G][0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper](by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md), [UID:00031H][0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper](by-memory/0x004e85b0-0x004e85bb.IMEPaneSingletonClearHelper.md), and scalar deleting destructors [UID:00031I][0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor](by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md)(by-memory/0x004e8640-0x004e86bf.IMECandidatePaneScalarDeletingDestructor.md), [UID:00031J][0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor](by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md)(by-memory/0x004e86c0-0x004e8715.IMECompositionPaneScalarDeletingDestructor.md), [UID:00031K][0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor](by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md)(by-memory/0x004e8720-0x004e87f9.IMEPaneScalarDeletingDestructor.md), and [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md)(by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md).

## Migration Caveats

- Some source views place `0x004e7470` and `0x004e7930` under fitting-room download controls. Treat both as IME pane helpers before migration.
- IME scalar-destructor code paths can label base teardown as `TextButtonExControlPane::~Pane`. Treat this as base-owner pollution until the pane inheritance graph is cleaned.
- Disabled thunk files omit at least `0x004e85e7` and `0x004e8629`, even though IDA confirms both as real 0xb adjustor thunks. Treat [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md) as compiler-generated layout evidence rather than handwritten source.
- `CandidateStringQueue` names are useful behaviorally but should be treated as STL template support before committing a public header name. Do not migrate it as original product source unless later evidence finds handwritten behavior outside the STL helper ranges.

## Parent Gate Rationale

- Completion rises to `89`: the pane-family source root, status/composition/candidate/root pane contents, `g_pIMEPane` singleton, exact helper children, raw focus/destructor bodies, split cleanup/destructor children, destructor/thunk island, generated-owner pollution closures, and InputMan boundary are now documented.
- Confidence rises to `86`: live IDA confirms the raw-body split, product cleanup/destructor ranges, status-pane vtable/destructor/caller evidence, and the direct source parent for the aggregate IME pane family. Exact original filename, inherited pane field names, candidate-string STL expression, and message-payload names still cap confidence below higher final-audit levels.

## Cross-References

- [UID:0000K6][InputMan](by-file/InputMan.md)
- [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md)
- [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md)
- [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md)

## Changes

- 2026-06-08 A001 Batch131 source-family refresh:
  - Before: score was `88/85`.
  - Changed to: score `89/86`.
  - Summary/evidence: live IDA MCP reconfirmed the IME family, raw focus/destructor helper bodies, product cleanup/destructor ranges, and `InputMan` boundary; exact child pages [UID:00031F][0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor](by-memory/0x004e7cb0-0x004e7cfc.IMECandidatePaneOrdinaryDestructor.md) through [UID:00031L][0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor](by-memory/0x004e8800-0x004e8855.IMEStatusPaneScalarDeletingDestructor.md) now cover the remaining raw/product cleanup pieces used by the Batch131 memory targets.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: IME pane family ownership, composition/candidate/status roles, singleton, owner pollution, STL candidate-string support, and InputMan boundary are well documented; confidence is capped by exact original file name and base-owner/thunk caveats.
- 2026-06-05 reconstruction path classification:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file row in error.
  - Changed to: `NexusTK/input/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `IMEPanes.cpp` under `NexusTK/input/`, and live IDA MCP xrefs/decompilation confirm `0x004e7f20`, `0x004e85b0`, and `0x004e8720` write/clear `dword_69B458` inside the IME pane lifecycle island.
- 2026-06-07 A006 Batch 090 parent-gate refresh:
  - Before: score was `88/82`, below the corrected confidence gate for assigning [UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md).
  - Changed to: score `88/85`; documented the status-pane method bounds, `SetText` caller closure, vtable refs, scalar-destructor thunk refs, and destructor-island relationship.
  - Summary/evidence: live IDA MCP confirms `IMEStatusPane` is part of the pane-side IME UI cluster owned here, while `InputMan` remains the neighboring Win32/IMM bridge. Remaining source-name and field/message-structure gaps keep final C++ blank.
