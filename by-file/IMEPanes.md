*** UID:0000K5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# IMEPanes

## Status

- Confidence: strong for pane family ownership; medium for exact original file name.
- Proposed source path: `input/IMEPanes.cpp`
- Proposed header path: `input/IMEPanes.h`
- Current recovered sources: `class_IMEPane.cpp`, `class_IMEStatusPane.cpp`, `class_IMECompositionPane.cpp`, `class_IMECandidatePane.cpp`, generated STL helper materialization `class_CandidateStringQueue.cpp`, plus two IME helper methods currently emitted in `class_FittingRoomDownloadControlPane.cpp`.
- Evidence basis: `simroot_v2` generated source and IDA MCP boundary/xref/decompile checks on 2026-05-24. Wave3 was not executed for this pass.

## File Role

This module owns the pane-side IME UI: the hidden/root IME pane singleton, mode status label, composition string popup, candidate list popup, and the candidate-string container used by candidate rendering.

Keep this separate from [UID:0000K6][InputMan](by-file/InputMan.md). `InputMan` owns the Win32/IMM window-message bridge and emits IME events, while `IMEPanes.cpp` owns the visible pane reactions to those events and the focus-pane list used by text-entry controls.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md) | `0x004e70f0-0x004e737b`, destructor wrappers in `0x004e861e-0x004e8855` | `class_IMEStatusPane.cpp` | Bottom-right ENG/IME status label and mode-change handler. |
| [UID:00006G][IMECompositionPane](by-class/IMECompositionPane.md) | `0x004e7380-0x004e7912`, exact helper [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md), destructor wrappers in `0x004e85f2-0x004e8715` | `class_IMECompositionPane.cpp`, polluted helper in `class_FittingRoomDownloadControlPane.cpp` | Composition text popup, drag behavior, commit/update, and paint. |
| [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md) | exact helper [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md), class body `0x004e7b70-0x004e7f1a`, destructor wrappers in `0x004e85dc-0x004e86bf` | `class_IMECandidatePane.cpp`, polluted helper in `class_FittingRoomDownloadControlPane.cpp` | Candidate list sizing, positioning, string copy, message handling, and paint. |
| [UID:00006H][IMEPane](by-class/IMEPane.md) | `0x004e7f20-0x004e8433`, destructor wrappers in `0x004e85b0-0x004e87f9` | `class_IMEPane.cpp` | Singleton root pane, child popup lifetime, focus-pane list, and IME event dispatch. |
| [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md) / [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) | `0x004e8450-0x004e8ae6`, `0x004e9710-0x004e97a3` | `class_CandidateStringQueue.cpp` | Generated STL `std::deque<std::wstring>` helper materialization. Final source should express a normal candidate-string container member/local, not a handwritten product class file. |
| [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md) | [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md) | global data | Active IME pane singleton and focus-list owner. |

## Evidence Notes

- IDA MCP confirms a contiguous IME pane/source neighborhood from `0x004e70f0` through `0x004e8ae6`, followed by [UID:0000K6][InputMan](by-file/InputMan.md) at `0x004e8af0`.
- IDA MCP confirms `CandidateStringQueue::AppendOwnedString` at `0x004e9710`; its direct callers are inside `InputMan::HandleWindowMessage` at `0x004e91a6` and `0x004e9234`.
- 2026-05-26 IDA MCP string/xref/decompile checks identify the generated `CandidateStringQueue` helpers as MSVC/Dinkumware `std::deque<std::wstring>` support: `ReserveAdditional` calls the shared `deque<T> too long` overflow helper, entries are 0x18-byte SSO-7 wide strings, and the deque object has the expected proxy/map/head/count fields.
- IDA MCP confirms `IMEPane` construction at `0x004e7f20` is called from the application startup path at `0x004f639e`.
- `g_pIMEPane` at `0x0069b458` is written by `IMEPane::IMEPane`, cleared by `IMEPane` destruction helpers, and read by composition, candidate, text-edit, text-box, and self-save paths.
- `IMEPane::SetFocusPane` at `0x004e80a0` has direct callers in text-edit and self-save text input paths, which supports keeping it in the IME pane file rather than the caller classes.
- `SetCompositionString` at [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md) and `ShowCandidateList` at [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) are currently emitted in `class_FittingRoomDownloadControlPane.cpp`, but IDA places them in the IME cluster and their callers/data flow are IME-specific.
- 2026-05-26 IDA MCP recheck confirms `0x004e7470` is directly called by `IMECompositionPane::OnKeyEvent` at `0x004e782d`, `0x004e7930` is directly called by `IMECandidatePane::HandleIMEMessage` at `0x004e7d13`, and [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md) is a 4-byte `.data` pointer with 17 data references.

## Data Caveats

- `class_FittingRoomDownloadControlPane.cpp` owns `0x004e7470` and `0x004e7930` in current generated output. Treat both as IME pane helpers before migration.
- IME scalar-destructor code paths label base teardown as `TextButtonExControlPane::~Pane` in current generated source. Treat this as base-owner pollution until the pane inheritance graph is cleaned.
- Disabled thunk files omit at least `0x004e85e7` and `0x004e8629`, even though IDA confirms both as real 0xb adjustor thunks. Treat [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md) as compiler-generated layout evidence rather than handwritten source.
- Generated names for `CandidateStringQueue` are useful behaviorally but should be treated as STL template support before committing a public header name. Do not migrate `class_CandidateStringQueue.cpp` as original product source unless later evidence finds handwritten behavior outside the STL helper ranges.

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
- [UID:00018E][0x004e8af0-0x004e970c.InputMan](by-memory/0x004e8af0-0x004e970c.InputMan.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: IME pane family ownership, composition/candidate/status roles, singleton, generated owner pollution, STL candidate-string support, and InputMan boundary are well documented; confidence is capped by exact original file name and generated base-owner/thunk caveats.
