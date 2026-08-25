*** UID:00001R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChattingBackPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingBackPane.cpp`
- Autogen handling: attached to [UID:0000I5][Chatting](by-file/Chatting.md) after the exact constructor/destructor/update child pages and singleton/vtable evidence brought the class above the 80/80 attachment gate. Class-level declaration C++ remains blank, but exact child bodies now include first-draft C++ for the constructor, destructor, viewport-line-count, and UID0002F3 `UpdateVisibility`.

## Class Purpose

`ChattingBackPane` is the translucent background behind the chat display. It follows `ChattingHandlePane` mode/secondary-chat state, adjusts visibility, alpha, and active draw color, and refreshes inherited pane bounds when the handle state changes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingBackPane` | [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md) | First-draft C++ ready as `ChattingBackPane::ChattingBackPane() : Pane(2), Singleton<ChattingBackPane>() { m_alpha = 0.6f; }`; the singleton publish resolves `g_pChattingBackPane`, while vtable stores are compiler output. |
| `~ChattingBackPane` | [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) | Source-authored destructor body clears `g_pChattingBackPane`; compiler restores vtables and implicitly chains to `Pane::~Pane()` at `0x00544580`. |
| `SetChatViewportLineCount` | [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) | Applies the chat viewport rectangle `(9, 700 - 13*n, 816, 720)` for the selected visible-line count and invalidates the back pane. |
| `UpdateVisibility` | [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) | First-draft C++ ready at `88/92`; reads `g_pChattingHandlePane->m_chatHandleModeIndex` and `m_secondaryChatEnabled`, writes `m_alpha` as `0.7f` or `0.3f` when active, applies `Pane::SetMode(2/1)` and `SetGrafPortColorState(0x80/0)`, then refreshes inherited `m_rect`. |
| `ScalarDeletingDestructor` | `0x00483aa0` | Compiler-generated deleting wrapper for `ChattingBackPane::~ChattingBackPane`; mirrors vtable restores and singleton clear, calls `Pane::~Pane()`, and optionally deletes. |

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md) | Exact constructor child records the single `InitializeMainUiGraph` allocation/call site, source `Pane(2)` base construction, `Singleton<ChattingBackPane>` publish route for `g_pChattingBackPane`, three compiler-generated vtable writes, `m_alpha = 0.6f`, and closed `0xcc` padding. |
| [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) | Exact ordinary destructor child records source-authored `g_pChattingBackPane` clear, compiler vtable restores, implicit base `Pane::~Pane()` tail jump at `0x00544580`, mirrored scalar-deleting wrapper evidence, and no direct compact-body xrefs. |
| [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) | Receiver-style BackPane method called by the resize handle; confirms `GetBounds`, chat viewport rectangle math, `SetBounds`, and inherited-rect invalidation. |
| [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) | Exact virtual-method child records the vtable-only slot `0x00614dd4`, no direct PE rel32/RVA/raw route, `g_pChattingHandlePane->m_chatHandleModeIndex` at `+0x114`, `m_secondaryChatEnabled` at `+0x118`, `m_alpha` at `this+0x90` with `0.7f`/`0.3f` choices, `Pane::SetMode(2/1)`, `SetGrafPortColorState(0x80/0)`, `g_surfaceRenderCallbacks->RefreshPaneRegion(this,&m_rect)`, and first-draft formal C++ readiness. |
| [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md) | Identifies the adjacent UI/chat singleton slot that this class writes, reads through consumers, and clears during teardown. |

## Evidence Notes

- IDA MCP confirms exact ranges for the constructor, destructor body, viewport helper, and update virtual in the `0x00480640-0x004807aa` cluster.
- `xrefs_to 0x00480740` reports a vtable data xref at `0x00614dd4`, supporting the update method as a `ChattingBackPane` virtual.
- The update method reads chat handle/global state at `g_pChattingHandlePane +0x114/+0x118`; current `ChattingHandlePane` support resolves those fields as `m_chatHandleModeIndex` and `m_secondaryChatEnabled`, so the stale field-name blocker is closed for UID0002F3.
- 2026-06-16 A001 live IDA reconfirmed the constructor/destructor/update boundaries, `g_pChattingBackPane` lifecycle refs, `g_pChattingHandlePane` state reads, `this+0x90` alpha writes, mode/color/refresh helper calls, and vtable-only reachability for the update virtual. A corrected section-mapped PE scan found no direct `E8`/`E9` branch hits to the update virtual and only the vtable absolute-VA hit at `0x00614dd4`.
- 2026-06-17 B001 source-quality execution moved [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) from `ChattingModifyHeightPane` to this class because the receiver is `g_pChattingBackPane`, the body reads/mutates only BackPane geometry, and the resize pane is only the caller. The method now emits first-draft `ChattingBackPane::SetChatViewportLineCount` C++ through this class.
- 2026-06-18 B005 source-quality execution resolved [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) as first-draft C++ ready. The source destructor body is the unconditional `g_pChattingBackPane = NULL;` statement; vtable restores, the implicit base `Pane::~Pane()` chain at `0x00544580`, the scalar deleting destructor at `0x00483aa0`, adjustor thunks, and optional delete are compiler-generated from the destructor and inheritance layout.
- 2026-06-29 B007 source-quality implementation resolves [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) as first-draft C++ ready. Current MCP session `B006_0002F1_20260629` and local PE scan reconfirm exact `0x6a` bounds, seven-byte prepad, six-byte postpad, vtable-only route through `0x00614dd4`, zero direct rel32/RVA/raw-offset route, accepted handle fields, active/inactive mode/color branches, and shared Surface refresh. `this+0x90` is the class alpha/scalar field initialized by the constructor to `0.6f` and updated here; source uses `m_alpha` while exact original spelling remains inferred.
- 2026-06-29 B006 constructor implementation resolves [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md) as first-draft C++ ready at `90/93`. Accepted MCP session `B006_0002F1_20260629` plus restored database `d4d50b81` reconfirm exact `0x54` bounds, one caller/allocation at `0x004f7e89` after `sub_4F4AA0(0xf8)`, sole base constructor callee `0x00544460` as source `Pane(2)`, `g_pChattingBackPane` eight-xref lifecycle, singleton base-subobject `this+0xf8-0xf8` publish route, compiler-generated vtable stores, `m_alpha = 0.6f`, and twelve-byte `0xcc` postpad. Constructor source uses `Singleton<ChattingBackPane>()`; raw `dword_67ADD0` / `unk_67ADD0` remain evidence aliases only.

## Score Rationale

- Completion is raised to `88` because the class now has exact constructor, destructor-body, viewport-line-count, and update-virtual support; documented singleton lifecycle; vtable evidence; source-file ownership through [UID:0000I5][Chatting](by-file/Chatting.md); current reachability checks; and first-draft C++ for the constructor, destructor, viewport-line-count, and update-visibility children.
- Confidence is raised to `91` because live IDA, PE evidence, and B001/B006/B007 receiver-ownership reanalysis agree on the class identity, singleton/vtable routing, handle-state dependency, viewport update behavior, constructor `Pane(2)` / `Singleton<ChattingBackPane>()` / `m_alpha = 0.6f` shape, update-visibility mode/color/alpha behavior, and resize-handle caller. The base destructor helper is resolved as ordinary `Pane::~Pane()` at `0x00544580`; `+0x114/+0x118` are accepted as `m_chatHandleModeIndex` and `m_secondaryChatEnabled`; `+0x90` is first-draft `m_alpha`. Remaining class-level final-source caveats are the exact `PaneMode` enum spelling, exact original `m_alpha` spelling, and original update virtual name.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md)
- [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md)
- [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md)
- [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)

## Changes

- What existed before: the page documented purpose, methods, and chat-module ownership, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/86`.
- Summary and evidence: constructor, update, destructor, and chat globals are clear; detailed fields and final header/code form are still light.
- 2026-05-31: Updated completion/confidence from `70/86` to `76/88` after creating exact by-memory pages for the constructor, destructor body, and update virtual and linking the existing viewport helper. Evidence: IDA MCP function iteration, decompilation, xrefs, vtable data audit, and raw byte audit.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor, destructor body, update virtual, and scalar deleting destructor starts at `0x00480640`, `0x004806a0`, `0x00480740`, and `0x00483aa0`, and `callers` shows construction from main chat UI initialization. `AUTOGEN_PARENT_UID` remains blank even though [UID:0000I5][Chatting](by-file/Chatting.md) is the likely owner because the class completion score is still below the 80+ attachment gate.
- 2026-06-07 A004: Completion changed from `76` to `82`, confidence remains `88`, and `AUTOGEN_PARENT_UID` was set to [UID:0000I5][Chatting](by-file/Chatting.md).
  - Summary/evidence: added an evidence map for the exact constructor/destructor/update children, singleton slot, and vtable/update behavior; the class now clears the 80/80 attachment gate while final source C++ remains blank.
  - Remaining blockers: source-quality names for the base pane helpers, chat-handle state fields, alpha member, and update virtual remain unresolved.
- 2026-06-16 A001 class-completion refresh: raised `82/88` to `86/89` after refreshing [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) to `85/89` and reconfirming constructor/destructor/update boundaries, `g_pChattingBackPane` lifecycle, handle-state reads, alpha/mode/color/refresh behavior, vtable-only update reachability, and negative direct-branch evidence. Owner/emitter stay [UID:0000I5][Chatting](by-file/Chatting.md); final C++ remains blank pending final member/helper/virtual names.
- 2026-06-17 B001 source-quality execution: raised `86/89` to `87/90`, added [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) as `SetChatViewportLineCount`, and recorded the receiver-based ownership correction from `ChattingModifyHeightPane` to `ChattingBackPane`.
- 2026-06-18 B005 destructor source-quality execution: kept class score `87/90` but resolved the destructor-specific blocker for [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md). The ordinary destructor now emits first-draft `ChattingBackPane::~ChattingBackPane()` C++; `0x00544580` is ordinary `Pane::~Pane()` and no longer a base-helper naming blocker for this destructor.
- 2026-06-29 B007 UID0002F3 implementation callback: kept class score `87/90` while resolving the update-visibility child as first-draft C++ ready at `88/92`. Evidence incorporated: current MCP session `B006_0002F1_20260629`, exact `0x00480740-0x004807aa` range and padding, sole vtable xref/PE absolute pointer `0x00614dd4`, no direct call/RVA/raw route, accepted `ChattingHandlePane` fields `m_chatHandleModeIndex` and `m_secondaryChatEnabled`, `m_alpha` writes of `0.7f` or `0.3f`, active `SetMode(2)` / `SetGrafPortColorState(0x80)`, inactive `SetMode(1)` / `SetGrafPortColorState(0)`, and `RefreshPaneRegion(this,&m_rect)`. Rejected owner/source moves to `Pane`, `GrafPort`, `Surface`, `ChattingHandlePane`, file-level `Chatting`, or the aggregate `ChattingUI`.
- 2026-06-29 B006 UID0002F1 implementation callback: raised class score `87/90` to `88/91` after the constructor child was populated with first-draft formal C++. Evidence incorporated: accepted report session `B006_0002F1_20260629`, restored database `d4d50b81`, exact constructor bounds and padding, one allocation/call site, sole `Pane(2)` base callee, `Singleton<ChattingBackPane>` publish route for `g_pChattingBackPane`, compiler-generated vtable stores, `m_alpha = 0.6f`, and rejection of raw global/pointer-arithmetic/vtable/decompiler source output. Class-level declaration C++ remains blank because broader declaration spelling and virtual-name polish are still class-wide work.
