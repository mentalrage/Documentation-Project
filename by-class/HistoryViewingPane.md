*** UID:000066 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# HistoryViewingPane

## Status

- Confidence: strong for class behavior and main-menu caller reachability.
- Likely source file: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- Core address range: [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- Support ranges: [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md), [UID:0001A7][0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md), [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md), [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md)
- Current recovered source: `source-3/simroot_v2/class_HistoryViewingPane.cpp`

## Class Purpose

`HistoryViewingPane` is a full-screen pre-login story/history frame viewer. It is constructed from [UID:00007O][MainMenuPane](by-class/MainMenuPane.md) with either `STORY.EPF`/`STORY.EPD` or `HISTORY.EPF`/`HISTORY.EPD`, stores the resource name in a `SimpleUString`, queries the EPF library for the frame count, and renders the current frame using `NPAL4.PAL`.

Input handling is simple: Enter, Escape, Space, or mouse down/up advances the current page/frame while more content remains, then marks the pane/session for deletion at the end.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md) | `0x004ffd40-0x004ffd79` | Private helper that advances/clamps the current frame/page and invalidates the pane; called by `OnKeyDown`. |
| Constructor | `0x004ffd80-0x004ffec8` | Builds the pane, writes `g_pHistoryViewingPane`, stores the resource name, sets full-screen bounds, and schedules updates. |
| `OnKeyDown` | `0x004fff10-0x004fff83` | Handles Enter, Escape, and Space to advance or close. |
| `IsInteractive` | `0x004fff90-0x004fff94` | Returns true. |
| `OnMouseEvent` | `0x004fffa0-0x00500019` | Handles mouse down/up to advance or close. |
| `OnDraw` | `0x00500020-0x0050008b` | Loads current frame data from `g_pEPFLib` and renders it with `NPAL4.PAL`. |
| Singleton clear helper | [UID:0001A7][0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md) | Real `0xb` constructor EH cleanup helper that clears `g_pHistoryViewingPane`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md), and currently omitted from active generated output. |
| Adjustor thunks | [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md) | Two real destructor adjustor thunks documented in [UID:0000VN][-ignored](by-memory/-ignored.md). Disabled output marks `0x005024c1` as missing code, but IDA confirms the thunk. |
| Scalar deleting destructor | [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md) | Destroys `m_resourceName`, clears singleton, chains to pane cleanup, and optionally deletes. |

## Layout Notes

- Singleton: [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md) at `0x0069b494`.
- Current size evidence: `264` bytes.
- Base evidence: generated struct starts with `Pane` at offset `0`.
- Important fields from generated metadata: `m_frameIndex` at `+0xf8`, `m_totalFrames` at `+0xfc`, `m_delayTimer` at `+0x100`, and `m_resourceName` at `+0x104`.
- Vtable evidence: three vtable writes in the constructor, matching a pane plus secondary interface/update subobjects.

## Evidence Notes

- IDA MCP confirms real function starts for all listed methods and thunks.
- IDA MCP on 2026-05-26 confirms `0x004ffd40-0x004ffd79` as the private advance helper; its only direct caller is `HistoryViewingPane::OnKeyDown` at `0x004fff52`.
- IDA MCP `callers 0x004ffd80` reports four direct call sites in `MainMenuPane::ActivateMenuItem` at `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, and `0x004f7c3d`, plus two helper call sites at `0x004f912b` and `0x004f91ab`.
- The helper call sites belong to [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md) and [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md), both real functions with unresolved live reachability.
- `MainMenuPane::ActivateMenuItem` selects `STORY.EPF` or `STORY.EPD` for menu item `3`, and `HISTORY.EPF` or `HISTORY.EPD` for menu item `4`.
- IDA MCP `xrefs_to 0x0069b494` shows constructor writes, main-menu cleanup reads, singleton clear helper `0x005023b0`, and destructor clear.
- IDA MCP `xrefs_to 0x005024b6` and `xrefs_to 0x005024c1` show secondary vtable data refs at `0x0061da1c` and `0x0061da4c`, proving both destructor thunks are real.
- 2026-05-26 recheck: `0x005023b0` and `0x005024b6-0x005024cc` are compiler-generated cleanup/thunk spans, now listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- `source-3/simroot_v2/class_ChattingColorPane.cpp` also emits `HistoryViewingPane::OnKeyDown`; treat that as generated owner pollution.

## Source Layout Decision

Place this in `login/HistoryViewingPane.cpp` next to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). It is a main-menu content viewer, not chat history UI, even though current metadata summaries use broad "chat or action history" language.

## Cross-References

- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md)
- [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md)
- [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md)
- [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `88/86`. Summary: main-menu story/history viewer behavior, input handling, constructor/destructor/support thunks, singleton, layout fields, resource usage, caller reachability, source placement, and owner-pollution caveat are documented in depth. Evidence: `HistoryViewingPaneCore`, `HistoryViewingPaneAdvancePage`, singleton/global pages, resource pages, `MainMenuPane` caller evidence, and ignored cleanup/thunk notes.
