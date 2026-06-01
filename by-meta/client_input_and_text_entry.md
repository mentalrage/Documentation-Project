*** UID:0001QD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Input And Text Entry

## Status

- Scope: Win32 input bridge, IME event routing, pane-side IME UI, and text-entry controls.
- Confidence: medium-strong for InputMan/IME/TextEdit ownership; lower for final header splits and helper type names.

## Current Findings

- [UID:0000K6][InputMan](by-file/InputMan.md) owns the Win32/IMM message bridge, custom IME context, input-target tracking, and `g_pInputMan`.
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) owns Windows keyboard repeat delay/speed preservation and restoration. It is input-adjacent startup/platform state, separate from `InputMan`.
- 2026-05-24 IDA recheck confirms `KeySpeedMgr` is live in startup and shutdown paths: constructor/load/fast-repeat calls come from the application initialization/deactivation family, and restore is called from cleanup, deactivation, `TopLevelExceptionFilter`, and `_WinMain@16`.
- 2026-05-26 recheck keeps exact `KeySpeedMgr` helper anchors at [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md), [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md), and [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md). Active `simroot_v2/class_KeySpeedMgr.cpp` still omits restore and the fast-repeat helper.
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md) owns the pane-side IME UI: [UID:00006H][IMEPane](by-class/IMEPane.md), [UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md), [UID:00006G][IMECompositionPane](by-class/IMECompositionPane.md), [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md), the source-level candidate-string container currently emitted as [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md), and [UID:0000R7][g_pIMEPane](by-global/g_pIMEPane.md).
- 2026-05-26 IME recheck records exact helper/storage anchors: [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md), [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md), [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md), and [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md). Current `simroot_v2` still emits the two helper bodies under `FittingRoomDownloadControlPane`; treat that as owner pollution.
- 2026-05-26 follow-up identifies [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md) as generated MSVC/Dinkumware `std::deque<std::wstring>` template support, documented in [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md). The source still needs candidate-list container fields/locals in IME/InputMan code, but the helper implementation should not become a handwritten NexusTK class file.
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md), [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md), and [UID:0000OJ][TextBoxPane](by-file/TextBoxPane.md) are the main text-entry/control consumers of `g_pIMEPane->SetFocusPane`.
- [UID:0000JI][FontStyle](by-file/FontStyle.md) is the compact text-style descriptor shared by static labels and help panes. It belongs with UI text-control support, not with the minimap or mail callers that currently construct local style objects.
- Current generated source has owner pollution around `0x004e7470` and `0x004e7930`; treat those as IME pane helpers, not fitting-room code.

## Open Questions

- Determine the final source-facing alias/member name for the candidate-string container after the IME pane and InputMan code is rewritten. The current binary helper identity is now strong as STL `std::deque<std::wstring>`-style support rather than a private handwritten class.
- Normalize `DAT_0069b458` / `dword_69B458` references to `g_pIMEPane` where the dataflow clearly targets the IME singleton.
- Decide final placement for `KeySpeedMgr`: current tree proposal uses `input/KeySpeedMgr.cpp`, but `platform/KeySpeedMgr.cpp` remains plausible because it is a thin `SystemParametersInfoW` wrapper.

## Cross-References

- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:00018E][0x004e8af0-0x004e970c.InputMan](by-memory/0x004e8af0-0x004e970c.InputMan.md)
- [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md)
- [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md)
- [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md)
- [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md)
- [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md)
- [UID:00018A][0x004e7470-0x004e763c.IMECompositionSetCompositionString](by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md)
- [UID:00018B][0x004e7930-0x004e7b6c.IMECandidateShowCandidateList](by-memory/0x004e7930-0x004e7b6c.IMECandidateShowCandidateList.md)
- [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md)
- [UID:0001PS][0x0069b458-0x0069b45c.g_pIMEPane](by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md)
- [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md)
- [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md)
- [UID:0001JM][0x0058dce0-0x005917c8.TextEditPaneCore](by-memory/0x0058dce0-0x005917c8.TextEditPaneCore.md)
