*** UID:000066 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00054J | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../ui/core/Pane.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class Event;

class HistoryViewingPane : public Pane,
                           public Singleton<HistoryViewingPane>
{
public:
    explicit HistoryViewingPane(const wchar_t *resourceName);

protected:
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void AdvancePage();

    int m_frameIndex;
    int m_lastFrameIndex;
    unsigned int m_pageDelayMs;
    mystr::StringBase<wchar_t> m_resourceName;
};

typedef char HistoryViewingPaneSizeMustBe264[
    sizeof(HistoryViewingPane) == 0x108 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HistoryViewingPane

## UID00029O Status-Layer Dependency - 2026-07-21

The complete constructor/input/paint/implicit-destruction class inventory is preserved. Its constructor attaches full-screen bounds through independent [UID:0004VF][g_pStatusPaneLayer](by-global/g_pStatusPaneLayer.md), backed by the first UID00029O child; Singleton publication, EPF entry-count/resource storage, Pane ordering, TimerHandler scheduling, page progression, callers, vtables, and padding are closed. `g_pMainUiLayer` is retained only as a superseded historical alias.

## Status

- Confidence: strong for class behavior and main-menu caller reachability.
- Likely source file: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- Core address range: [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- Support ranges: [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md), [UID:0001A7][0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md), [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md), [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md)
- Current reconstructed source route: validator-owned `auto-generated/NexusTK/login/HistoryViewingPane.cpp` and `.h`, assembled from owning by-* formal CPP/H blocks and never edited directly.

## Class Purpose

`HistoryViewingPane` is a full-screen pre-login story/history frame viewer. It is constructed from [UID:00007O][MainMenuPane](by-class/MainMenuPane.md) with either `STORY.EPF`/`STORY.EPD` or `HISTORY.EPF`/`HISTORY.EPD`, stores the resource name in `mystr::StringBase<wchar_t>`, queries `ImageLib::GetEntryCount`, and renders the current frame through `EPFTileContext`, `LookupLayoutEntry`, and `RenderTileFrame` using `NPAL4.PAL`.

Input handling is simple: Enter, Escape, Space, or mouse down/up advances the current page/frame while more content remains, then marks the pane/session for deletion at the end.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| [UID:0001A0][0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage](by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md) | `0x004ffd40-0x004ffd79` | Private `AdvancePage` helper that advances/clamps `m_frameIndex`, compares inclusive-last `m_lastFrameIndex`, and calls `InvalidateRect(&m_visibleBounds)`; called by `HandleKeyOrTextEvent`, with equivalent pointer-path logic optimized inline. |
| Constructor | `0x004ffd80-0x004ffec9` | Builds the Pane/Singleton object, initializes `m_frameIndex`, `m_lastFrameIndex`, `m_pageDelayMs`, and `m_resourceName`, attaches through `g_pStatusPaneLayer`, orders against `g_pScreenPane`, and schedules the first TimerHandler event. Publication/clear follows the direct Singleton base rather than authored constructor assignments. |
| Constructor cleanup island | `0x004ffed0-0x004fff0a` | Nonfunction compiler/EH support inside UID0001A1: restores vtables, releases `m_resourceName`, clears `g_pHistoryViewingPane`, and jumps to `Pane` cleanup. Documented as support, not emitted as a separate source method. |
| `HandleKeyOrTextEvent` | `0x004fff10-0x004fff84` | EventHandler override: handles key-down events, translates Enter/Escape/Space through EventMan, advances while pages remain, removes pending timers, reschedules, or marks the pane for deletion. |
| `OnTimer` | `0x004fff90-0x004fff95` | TimerHandler override with exact three-int ABI and a true return; no additional page action is invented. |
| `HandlePointerOrMouseEvent` | `0x004fffa0-0x0050001a` | EventHandler override: handles left/right button-up events, closes when exhausted, otherwise advances, invalidates, removes pending timers, and reschedules. |
| `OnPaint` | `0x00500020-0x0050008b` | Pane paint override: resolves `m_resourceName`/`m_frameIndex` with `LookupLayoutEntry` into `EPFTileContext` and calls `RenderTileFrame` with `NPAL4.PAL`. |
| Singleton clear helper | [UID:0001A7][0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md) | Real `0xb` constructor EH cleanup helper that clears `g_pHistoryViewingPane`; documented in [UID:0000VN][-ignored](by-memory/-ignored.md), and currently omitted from active generated output. |
| Adjustor thunks | [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md) | Two real destructor adjustor thunks documented in [UID:0000VN][-ignored](by-memory/-ignored.md). Disabled output marks `0x005024c1` as missing code, but IDA confirms the thunk. |
| Scalar deleting destructor | [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md) | Compiler-generated wrapper caused by the implicit virtual destructor. Automatic `StringBase`, direct `Singleton<HistoryViewingPane>`, and Pane destruction regenerate member cleanup, singleton clear, vtable restoration, adjustors, delete flags, and optional free; no authored destructor body emits. |

## Layout Notes

- Singleton: [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md) at `0x0069b494`.
- Current size evidence: `264` bytes.
- Base evidence: generated struct starts with `Pane` at offset `0`.
- Exact fields after the `0xf8` Pane base: `m_frameIndex +0xf8`, inclusive-last `m_lastFrameIndex +0xfc`, `m_pageDelayMs +0x100`, and `mystr::StringBase<wchar_t> m_resourceName +0x104`; total class size is `0x108`.
- UID0001A0 confirms that inherited `GrafPort::m_visibleBounds` at `+0x44` is the exact invalidation argument for `AdvancePage`.
- Vtable evidence: three vtable writes in the constructor, matching a pane plus secondary interface/update subobjects.

## Evidence Notes

- IDA MCP confirms real function starts for all listed methods and thunks.
- IDA MCP on 2026-05-26 confirms `0x004ffd40-0x004ffd79` as the private advance helper; its only direct caller is the physical key-handler body at `0x004fff52`, represented in source as `HistoryViewingPane::HandleKeyOrTextEvent`.
- Agent-B006 2026-07-04 MCP session `eb7ce28b` reconfirmed UID0001A0 as `sub_4FFD40`, size `0x39` / 57 bytes, with exact bytes, padding, one code xref, no data/pointer routes, and no ordinary callees. `HandleKeyOrTextEvent` calls the helper; `HandlePointerOrMouseEvent` has byte-equivalent advance logic that the reconstructed human source expresses through the helper.
- IDA MCP `callers 0x004ffd80` reports four direct call sites in `MainMenuPane::ActivateMenuItem` at `0x004f7b8d`, `0x004f7bc3`, `0x004f7c07`, and `0x004f7c3d`, plus two helper call sites at `0x004f912b` and `0x004f91ab`.
- The helper call sites belong to [UID:0000TE][OpenStoryViewingPane_4F90C0](by-global/OpenStoryViewingPane_4F90C0.md) and [UID:0000TC][OpenHistoryViewingPane_4F9140](by-global/OpenHistoryViewingPane_4F9140.md), both real functions with unresolved live reachability.
- `MainMenuPane::ActivateMenuItem` selects `STORY.EPF` or `STORY.EPD` for menu item `3`, and `HISTORY.EPF` or `HISTORY.EPD` for menu item `4`.
- IDA MCP `xrefs_to 0x0069b494` shows constructor writes, main-menu cleanup reads, singleton clear helper `0x005023b0`, and destructor clear.
- Agent-B007 2026-07-04 MCP session `eb7ce28b` proves UID0001AG's exact scalar-wrapper range, vtable/adjustor refs, member cleanup, singleton clear, Pane cleanup, and delete mechanics. The later class-wide analysis supersedes only the old authored-destructor interpretation: automatic member/base destruction explains every effect.
- Agent-B001 2026-07-06 MCP session `supervisor_recovery_20260705` proves the exact constructor and four virtual ranges, cleanup island, padding, six constructor refs, virtual-slot refs, singleton refs, and historical empty marker. The stripped labels from that session map to the current source names in the Method Notes table rather than remaining active source API.
- IDA MCP `xrefs_to 0x005024b6` and `xrefs_to 0x005024c1` show secondary vtable data refs at `0x0061da1c` and `0x0061da4c`, proving both destructor thunks are real.
- 2026-05-26 recheck: `0x005023b0` and `0x005024b6-0x005024cc` are compiler-generated cleanup/thunk spans; exact current pages UID0001A7 and UID0001AB replace the old generic ignored-ledger treatment.
- Historical `source-3/simroot_v2/class_ChattingColorPane.cpp` output routed the physical key-handler body under the wrong owner. Dedicated HistoryViewingPane evidence rejects that route.

## Source Layout Decision

Place the declaration in `login/HistoryViewingPane.h` and authored definitions in `login/HistoryViewingPane.cpp`, beside but independent from [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). UID0001A0 and UID0001A1 emit authored methods; UID0000R3 emits the singleton definition/specializations. UID0001A7, UID0001AB, UID0001AG, the constructor cleanup island, vtables, COLs, and RTTI remain compiler-only evidence with blank source.

## Historical Superseded Assumptions

- `SimpleUString` was an early generic interpretation of the four-byte resource member. Constructor/destructor helper families and the mature utility declaration identify `mystr::StringBase<wchar_t>` instead.
- `m_totalFrames`, `m_delayTimer`, and `m_bounds` reflected raw offset semantics. Inclusive-last constructor storage and shared Pane layout replace them with `m_lastFrameIndex`, `m_pageDelayMs`, and inherited `m_visibleBounds`.
- `OnKeyDown`, `IsInteractive`, `OnMouseEvent`, and `OnDraw` were behavior-derived names before full EventHandler/TimerHandler facet mapping. Exact slots and shared APIs replace them with `HandleKeyOrTextEvent`, `OnTimer`, `HandlePointerOrMouseEvent`, and `OnPaint`.
- The explicit destructor draft appeared plausible because the wrapper visibly destroys the string and clears the singleton. The accepted direct Singleton base and automatic member/base destruction prove those statements are compiler-generated, so no explicit destructor body remains.
- Historical ChattingColor output was a generator-routing defect, not ownership evidence; dedicated class RTTI/vtables/layout/singleton/callers contradict it.

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

## Historical Change Log

- 2026-08-16 UID0000JW accepted whole-file callback: raised this class to `93/95`, routed it at position `10` through file-shell [UID:00054J][HistoryViewingPaneFileShell](by-item/HistoryViewingPaneFileShell.md), and installed the complete period-compatible CPP child shell and H declaration. The declaration records direct `Pane` plus empty `Singleton<HistoryViewingPane>` inheritance, the exact `0x108` layout (`m_frameIndex +0xf8`, `m_lastFrameIndex +0xfc`, `m_pageDelayMs +0x100`, `m_resourceName +0x104`), four virtual overrides, private `AdvancePage`, and the size assertion. Physical vtable/COL bytes are documented by [UID:00054H][0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData](by-memory/0x0061d9cc-0x0061da54.HistoryViewingPaneVtableData.md), with semantic slots/RTTI in [UID:00054I][HistoryViewingPaneVtables](by-type/by-vtable/HistoryViewingPaneVtables.md). Earlier `SimpleUString`, `m_totalFrames`, `m_delayTimer`, `OnKeyDown`, `IsInteractive`, `OnMouseEvent`, `OnDraw`, and explicit-destructor descriptions below are retained only as superseded historical reconstruction stages; the formal CPP/H and this callback note are current.

- Completion/confidence score update: existed before as `0/0`; changed to `88/86`. Summary: main-menu story/history viewer behavior, input handling, constructor/destructor/support thunks, singleton, layout fields, resource usage, caller reachability, source placement, and owner-pollution caveat are documented in depth. Evidence: `HistoryViewingPaneCore`, `HistoryViewingPaneAdvancePage`, singleton/global pages, resource pages, `MainMenuPane` caller evidence, and ignored cleanup/thunk notes.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the main-menu story/history viewer unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000JW`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004ffd40`, `0x004ffd80`, `0x004fff10`, `0x004fff90`, `0x004fffa0`, `0x00500020`, and `0x00502760`; constructor callers remain the four `MainMenuPane` sites plus story/history helper wrappers. The class score `88/86` and parent score `84/80` meet the 80/80 attachment gate.
- 2026-07-04 Agent-B006 UID0001A0 source-quality sync:
  - Summary/evidence: accepted B006 report `0001A0-HistoryViewingPaneAdvancePage-source-quality.md` and MCP session `eb7ce28b` make the advance helper source-ready at `88/91` with formal `HistoryViewingPane::AdvancePage()` C++ on its exact by-memory page. This class page keeps the broader class metadata unchanged and records the caller split: `OnKeyDown` calls UID0001A0, while `OnMouseEvent` inlines equivalent advance logic.
- 2026-07-04 Agent-B007 UID0001AG source-quality implementation callback:
  - Summary/evidence: accepted report `0001AG-HistoryViewingPaneDestructor-source-quality.md` and MCP session `eb7ce28b` make the scalar deleting destructor wrapper source-ready at `88/91` with formal `HistoryViewingPane::~HistoryViewingPane()` C++ on its exact by-memory page. The source-facing body releases `m_resourceName` and clears `g_pHistoryViewingPane`; vtable restoration, inherited `Pane` cleanup, scalar-delete flags, guard path, and delete helper are documented as compiler-generated mechanics. Class metadata remains unchanged because the owner/emitter route through [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) was already correct.
- 2026-07-06 Agent-B001 UID0001A1 source-quality implementation callback:
  - Summary/evidence: accepted report `0001A1-HistoryViewingPaneCore-source-quality.md` and MCP session `supervisor_recovery_20260705` make the constructor/input/draw core source-ready at `89/91` with formal first-draft C++ on the exact by-memory page. The class page records the cleanup island/no-code support split, exact child no-duplication policy for UID0001A0 and UID0001AG, virtual slot refs, singleton lifecycle refs, constructor caller inventory, generated empty-marker repair expectation, and remaining confidence caps for inferred helper/member/event names.
