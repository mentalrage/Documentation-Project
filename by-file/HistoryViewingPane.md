*** UID:0000JW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# HistoryViewingPane

## UID00029O Status-Layer Dependency - 2026-07-21

`HistoryViewingPane.cpp` retains the complete source inventory and routing. The constructor's one external Layer dependency is `g_pStatusPaneLayer`; MainUiGraph.cpp owns that global, while this file only consumes it. Full-screen bounds, singleton and frame resources, input/draw/timer behavior, teardown, and generated order are unchanged, and the former `g_pMainUiLayer` spelling is superseded history.

## Status

- Confidence: strong for class contents, singleton ownership, direct routed children, and main-menu reachability.
- Proposed source path: `login/HistoryViewingPane.cpp`
- Proposed header path: `login/HistoryViewingPane.h`
- Main class: [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- Core address range: [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- Support ranges: [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md), [UID:0001A7][0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md), [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md), [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md), [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md)

## File Role

This module should own the full-screen story/history frame viewer opened from the pre-login main menu. It is a `Pane` subclass that displays EPF/EPD frame sequences directly rather than a modal `DialogPane` with controls.

[UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) selects the resource and allocates the viewer; this file owns viewer lifetime, input handling, frame rendering, and its singleton pointer.

## Current Accepted Contents

| Entity | Address | Role |
| --- | --- | --- |
| `HistoryViewingPane` | authored `0x004ffd40-0x0050008b`; compiler support `0x005023b0`, `0x005024b6-0x005024cc`, `0x00502760-0x005027cc` | Full-screen main-menu story/history frame viewer. Authored source is [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md) plus [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md). UID0001A7, UID0001AB, and UID0001AG document compiler-generated cleanup, adjustors, and scalar-deleting destruction caused by the implicit virtual destructor; they emit no handwritten source. |
| `g_pHistoryViewingPane` | [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md) | Active singleton pointer used by constructor, cleanup helper, destructor, and main-menu singleton cleanup. |
| Resource selector callers | `0x004f7a10`, `0x004f90c0`, `0x004f9140` | Main-menu/menu-helper code that allocates a 264-byte viewer and passes `STORY.*` or `HISTORY.*`. Keep these with `MainMenuPane.cpp` unless later evidence proves file-local wrappers. |

## Current Source-Layout Split

| Current owner evidence | Address | Corrected source-layout decision |
| --- | --- | --- |
| private helper | `0x004ffd40` | Emit private `HistoryViewingPane::AdvancePage`, called by the physical key-handler body and represented in source as `HandleKeyOrTextEvent`; the optimized pointer-handler path is equivalent. |
| authored core | `0x004ffd80`, `0x004fff10`, `0x004fff90`, `0x004fffa0`, `0x00500020` | Emit the constructor, `HandleKeyOrTextEvent`, `OnTimer`, `HandlePointerOrMouseEvent`, and `OnPaint` from UID0001A1. The mature Event/EventMan, TimerHandler, ImageLib/EPFTileContext, GrafPort, and Pane APIs replace the earlier synthetic interfaces. |
| constructor cleanup support | `0x004ffed0-0x004fff0a`, `0x005023b0-0x005023bb` | Preserve as compiler/EH evidence. UID0001A7 owns the exact clear-helper documentation; neither span emits a separate authored function. |
| destructor support | `0x005024b6-0x005024cc`, `0x00502760-0x005027cc` | UID0001AB owns the two adjustors and UID0001AG owns the scalar-deleting wrapper. Both are compiler-generated consequences of implicit class destruction and remain non-emitting. |
| historical `class_ChattingColorPane.cpp` route | `0x004fff10` | Rejected generated owner pollution. Class RTTI, vtables, fields, singleton, callers, and exact ranges place the body in standalone HistoryViewingPane source. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms the core functions and destructor support listed above.
- 2026-06-13 live IDA MCP session `a002_batch_clear_timer` reconfirmed the complete viewer function island: advance helper `0x004ffd40` size `0x39`, constructor `0x004ffd80` size `0x149`, key handler `0x004fff10` size `0x74`, true-return slot `0x004fff90` size `0x5`, mouse handler `0x004fffa0` size `0x7a`, draw handler `0x00500020` size `0x6b`, constructor-EH clear helper `0x005023b0` size `0xb`, two destructor adjustor thunks `0x005024b6`/`0x005024c1` size `0xb` each, and scalar deleting destructor `0x00502760` size `0x6c`.
- 2026-07-04 Agent-B006 MCP session `eb7ce28b` reconfirmed UID0001A0 `0x004ffd40` as a source-ready exact child: `sub_4FFD40`, size `0x39` / 57 bytes, exact bytes recorded on the target, three pre-padding `0xcc` bytes, seven post-padding `0xcc` bytes, one key-handler caller at `0x004fff52`, no data xrefs, zero saved address-pattern routes, empty ordinary callees, and explicit invalidation through the inherited bounds at `+0x44`.
- 2026-07-04 Agent-B007 MCP session `eb7ce28b` reconfirmed UID0001AG `0x00502760` as the exact `0x6c` scalar-deleting wrapper, including boundaries, primary-vtable and adjustor references, three-view constructor parity, singleton clear, automatic `StringBase` member destruction, Pane cleanup, delete flags, and guard mechanics. The later whole-file pass proved that these are compiler-generated effects of an implicit destructor, not an authored destructor body.
- 2026-07-06 Agent-B001 MCP session `supervisor_recovery_20260705` reconfirmed UID0001A1's physical functions and boundaries. The stripped/raw names used then map to current source names as follows: `0x004fff10` `HandleKeyOrTextEvent`, `0x004fff90` `OnTimer`, `0x004fffa0` `HandlePointerOrMouseEvent`, and `0x00500020` `OnPaint`. The same evidence confirms the cleanup island, successor padding, six constructor refs, virtual slots, singleton refs, and the historical pre-callback empty marker.
- 2026-06-13 `xrefs_to 0x004ffd80` reports exactly six constructor call sites: four active `MainMenuPane::ActivateMenuItem` calls at `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, and `0x004f7c3d`, plus retained launcher calls at `0x004f912b` and `0x004f91ab`.
- 2026-06-13 `xrefs_to 0x0069b494` reports six lifecycle refs: main-menu cleanup read at `0x004f69dd`, constructor publish/fallback writes at `0x004ffdd6` and `0x004ffddd`, constructor-adjacent cleanup write at `0x004ffefa`, singleton-clear helper write at `0x005023b0`, and destructor clear at `0x0050278d`.
- 2026-06-13 `analyze_function 0x004ffd80` confirms the constructor installs the three `HistoryViewingPane` vtables at offsets `+0x0`, `+0xa0`, and `+0xa4`, initializes `mystr::StringBase<wchar_t> m_resourceName`, sets `m_frameIndex`, stores inclusive-last `m_lastFrameIndex`, stores `m_pageDelayMs`, sizes the pane from `g_screenWidth`/`g_screenHeight`, and schedules the timer path.
- 2026-06-13 `analyze_function 0x00500020` confirms the draw path reads the current frame index, resolves the resource name, fetches EPF frame data, and blits with literal `NPAL4.PAL`.
- IDA MCP on 2026-05-26 confirms `0x004ffd40` as a real `0x39`-byte advance helper with the only caller at `0x004fff52` inside the physical key-handler body represented in source as `HistoryViewingPane::HandleKeyOrTextEvent`.
- IDA MCP `callers 0x004ffd80` confirms six constructor call sites: four inside `MainMenuPane::ActivateMenuItem` and two menu helper wrappers.
- The two wrapper functions are [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md) and [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md). IDA confirms both are real functions, but direct caller/xref lookup currently returns none.
- The direct main-menu branch uses `STORY.EPF`/`STORY.EPD` for menu item `3` and `HISTORY.EPF`/`HISTORY.EPD` for menu item `4`.
- IDA MCP `xrefs_to 0x0069b494` confirms constructor writes, cleanup-helper/destructor clears, and main-menu cleanup reads.
- IDA MCP `xrefs_to 0x005024b6` and `xrefs_to 0x005024c1` show vtable data refs at `0x0061da1c` and `0x0061da4c`; both thunks call the scalar deleting destructor with `this - 0xa0` or `this - 0xa4`.
- 2026-05-26 recheck confirms `0x005023b0` is constructor-unwind cleanup glue and `0x005024b6-0x005024cc` are adjustor thunks; these tiny compiler-generated spans are documented but should not become handwritten source methods.

## Current Reconstruction State

- The standalone `login/HistoryViewingPane.cpp/.h` route is applied through file shell UID00054J, class UID000066, method children UID0001A0/UID0001A1, and global UID0000R3.
- Exact compiler pages UID0001A7, UID0001AB, UID0001AG, and physical slot UID0001PU are documented and non-emitting; no `-ignored` placeholder is the current owner.
- Historical ChattingColor routing is removed from active ownership and retained only below as superseded generated history.

## Historical Superseded Assumptions

- The earlier `OnKeyDown`, `IsInteractive`, `OnMouseEvent`, and `OnDraw` names were plausible from local behavior before complete EventHandler/TimerHandler vtable mapping. Exact facet slots and mature shared APIs replace them with `HandleKeyOrTextEvent`, `OnTimer`, `HandlePointerOrMouseEvent`, and `OnPaint`.
- The earlier `m_totalFrames`, `m_delayTimer`, and generic bounds names came from raw offsets and decompiler use. Constructor semantics and the shared Pane layout replace them with inclusive-last `m_lastFrameIndex`, `m_pageDelayMs`, and inherited `m_visibleBounds`.
- The 2026-07 explicit `HistoryViewingPane::~HistoryViewingPane()` draft treated visible member/global cleanup as authored statements. Current `StringBase` and direct Singleton-base destruction prove the complete wrapper is compiler-generated; UID0001AG therefore has blank formal source.
- `class_ChattingColorPane.cpp` was once a generated destination, which made a chat owner superficially plausible. Dedicated HistoryViewingPane RTTI, three vtable views, singleton, fields, six constructors, and the standalone emitter route contradict that placement.

## Dated Generated-Output Audit

- Historical command `000000024879` at `2026-08-16T06:40:10-04:00` produced `auto-generated/NexusTK/login/HistoryViewingPane.cpp` SHA256 `6A13AFD5DE7F392418049C593FE3C0ECBD93AD86FEB00E34D00A1A54D46E7D13`, `3015` bytes and `105` physical lines, with no sibling `HistoryViewingPane.h`.
- That snapshot still contained three target-family empty-emitter defects: UID0001A7 singleton-clear support, UID0001AB destructor-adjustor support, and UID0001PU physical singleton storage. It also retained stale UID0001A1 source names/APIs and the explicit UID0001AG destructor draft.
- The accepted correction makes UID0001A7/UID0001AB/UID0001AG non-emitting compiler pages, makes UID0001PU a non-emitting physical child of source global UID0000R3, emits complete current UID0001A1 source, and creates the real sibling header. Generated snapshots remain dated validator evidence subordinate to fresh dynamic reread.

## Cross-References

- [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md)
- [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md)
- [UID:0001PU][0x0069b494-0x0069b498.g_pHistoryViewingPane](by-memory/0x0069b494-0x0069b498.g_pHistoryViewingPane.md)
- [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md)
- [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)

## Historical Change Log

- 2026-08-16 UID0000JW accepted whole-file callback: raised this standalone `NexusTK/login/HistoryViewingPane.cpp/.h` owner to `93/94` and closed its complete inventory. Validator-compatible file-shell [UID:00054J][HistoryViewingPaneFileShell](by-item/HistoryViewingPaneFileShell.md) carries the exact CPP include shell and H guard because by-file pages are structural owners rather than direct emitters; class [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md) follows at position `10`, with [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md) and [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md) at class positions `10/20`, then [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md) at file position `20`. Physical vtables/COL are [UID:00054H][0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData](by-memory/0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData.md); semantic slots/RTTI are [UID:00054I][HistoryViewingPaneVtables](by-type/by-vtable/HistoryViewingPaneVtables.md). The source-authored inventory is the class declaration, `AdvancePage`, constructor, key/mouse/timer/paint overrides, singleton definition, and Singleton specializations. The constructor-unwind island, clear helper, two adjustors, scalar-deleting wrapper, padding, vtables, COLs, and RTTI are compiler-covered and blank. Prior current-looking `OnKeyDown`/`IsInteractive`/`OnMouseEvent`/`OnDraw`, explicit destructor, `m_totalFrames`, `m_delayTimer`, old rendering APIs, and ChattingColor ownership below are superseded historical stages; the callback graph and formal child blocks are current.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: main-menu story/history viewer role, singleton ownership, resource selector wrappers, split corrections, IDA evidence, migration notes, and resource/menu cross-references are documented; confidence is capped by exact login path and ownership caveats.
- 2026-06-05 reconstruction path classification:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, leaving the file row in error.
  - Changed to: `NexusTK/login/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `HistoryViewingPane.cpp` under `NexusTK/login/`, and live IDA MCP xrefs/decompilation confirm `0x004ffd80`, `0x005023b0`, and `0x00502760` write/clear `dword_69B494` in the `HistoryViewingPane` lifecycle and cleanup island.
- 2026-06-13 Agent-A001 Goal 2 low-confidence pass:
  - What existed before: `COMPLETION:84` and `CONFIDENCE:80`; the class child was already `88/86`, but the direct file parent did not clear the active strict `85/85` gate and several routed memory children were still `84` completion.
  - Changed to: `COMPLETION:87` and `CONFIDENCE:87`.
  - Summary/evidence: live IDA MCP session `a002_batch_clear_timer` reconfirmed all HistoryViewingPane function starts/sizes, six constructor xrefs, six singleton lifecycle refs, constructor field/vtable/resource setup, draw-time `NPAL4.PAL` resource rendering, retained story/history launcher resource xrefs, and destructor/thunk vtable refs. The direct class child [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md), direct singleton global child [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md), and routed reconstructable memory children now clear the strict `85/85` gate. Scores stay below final-audit quality because final source C++ is intentionally blank and retained launcher reachability remains an open source-history question.
- 2026-07-04 Agent-B006 UID0001A0 source-quality sync:
  - Summary/evidence: UID0001A0 now emits formal `HistoryViewingPane::AdvancePage()` C++ through this file. The B006 pass preserves this file's `login/HistoryViewingPane.cpp` placement, keeps [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) as the story/history resource launch-decision owner, and preserves the `class_ChattingColorPane.cpp` owner-pollution caveat for `OnKeyDown`.
- 2026-07-04 Agent-B007 UID0001AG source-quality implementation callback:
  - Summary/evidence: UID0001AG now emits formal `HistoryViewingPane::~HistoryViewingPane()` C++ through this file. The accepted source body releases `m_resourceName` and clears `g_pHistoryViewingPane`; compiler output regenerates vtable restoration, inherited `Pane` cleanup, scalar-delete flags, guard path, and delete helper. This clears the previous UID0001AG Empty Emitter Marker/source-output blocker without changing this file's owner/path metadata.
- 2026-07-06 Agent-B001 UID0001A1 source-quality implementation callback:
  - Summary/evidence: UID0001A1 now emits formal first-draft C++ for the `HistoryViewingPane` constructor, `OnKeyDown`, `IsInteractive`, `OnMouseEvent`, and `OnDraw` through this file. The accepted report preserves UID0001A0 `AdvancePage` and UID0001AG destructor as exact child emissions, preserves UID0001A7 and UID0001AB as compiler support/no-code pages, and records the constructor-adjacent cleanup island `0x004ffed0-0x004fff0a` as compiler/EH support rather than a handwritten method. Remaining exact helper/member/event spelling uncertainty is a confidence cap, not a blank-C++ blocker.
