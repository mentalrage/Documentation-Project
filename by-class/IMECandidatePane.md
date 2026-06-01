*** UID:00006F | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IMECandidatePane

## Status

- Likely source file: [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- Address range: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), with queue/destructor support in [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- Current recovered files: `source-3/simroot_v2/class_IMECandidatePane.cpp`; `ShowCandidateList` is currently emitted in `class_FittingRoomDownloadControlPane.cpp`
- Confidence: strong for behavior and ownership.

## Class Purpose

`IMECandidatePane` displays the IME candidate list. It owns popup geometry, selected index, a candidate-string container currently emitted as [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md), candidate message dispatch, and painting of selected/unselected candidate rows.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ShowCandidateList` | [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md) | Measures candidate strings, positions/clamps popup, copies visible candidate range into local queue, stores selected index, and invalidates. |
| `IMECandidatePane` | `0x004e7b70-0x004e7cae` | Constructs base pane, initializes candidate queue/list state, attaches to root pane, chooses initial position from active IME input control. |
| `HandleIMEMessage` | `0x004e7d00-0x004e7d24` | Accepts candidate-list message type `15` and forwards to candidate handling. |
| `OnPaint` | `0x004e7d30-0x004e7f1a` | Paints candidate popup frame/background and draws visible candidate rows with selected-row highlighting. |
| `ScalarDeletingDestructor` | `0x004e8640-0x004e86bf` | Clears candidate queue, destroys base pane, and optionally deletes storage. |

## Evidence Notes

- IDA MCP confirms all listed function starts and sizes.
- 2026-05-26 IDA MCP recheck shows `0x004e7930` is directly called by `IMECandidatePane::HandleIMEMessage` at `0x004e7d13`.
- Current generated source owns `0x004e7930` through `FittingRoomDownloadControlPane`; the function copies IMM candidate strings into `CandidateStringQueue` and updates candidate pane geometry, so it should be treated as IME candidate ownership.
- 2026-05-26 IDA MCP follow-up identifies the generated `CandidateStringQueue` helper bodies as MSVC/Dinkumware [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) support. Source reconstruction should keep the member as a normal candidate-string container, likely `std::deque<std::wstring>`, not a handwritten product queue.
- `class_IMECandidatePane.cpp.disabled` omits adjustor thunk `0x004e85e7`; IDA confirms it delegates to the scalar deleting destructor with a secondary-subobject adjustment.
- The exact [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md), [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md), and [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md) pages should be preferred over generated fitting-room owner names.

## Cross-References

- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md)
- [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)
- [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/86`. Summary: candidate-list pane purpose, geometry/candidate queue behavior, methods, generated-owner correction, deque-template support, adjustor thunk caveat, singleton relationship, and exact memory pages are documented with strong confidence. Evidence: `IMEPaneFamily`, `IMECandidateShowCandidateList`, `IMECandidateQueueAndDestructors`, `IMEAdjustorThunks`, `g_pIMEPane`, and `CandidateStringDequeTemplate`.
