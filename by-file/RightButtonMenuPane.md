*** UID:0000N7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# RightButtonMenuPane

## Status

- Confidence: strong for right-click target menu ownership and IDA boundaries.
- Proposed module folder: `ui/menu/`
- Candidate file: `ui/menu/RightButtonMenuPane.cpp`
- Current generated source route: `auto-generated/NexusTK/ui/menu/RightButtonMenuPane.cpp`
- Evidence basis: current class/memory docs, generated source, live IDA MCP boundaries/callers/vtable/UDT evidence, and accepted Vote-menu source analogues. Stale Wave2/Wave3 workflow labels are not used as current proof.

## Hypothesis

`RightButtonMenuPane` is a standalone gameplay context menu for right-clicking another visible player or target. It draws a small SUBWIN-styled menu, tracks selected rows, opens look/whisper/group/info actions, sends trade/group-related packets, and clears highlighted object state on teardown.

Likely structure:

```text
ui/menu/RightButtonMenuPane.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `RightButtonMenuPane` core split container | [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md) | non-emitting reviewed container | B005 split container for the exact method/helper/jump-table children below; it should not emit aggregate C++. |
| `RightButtonMenuPane` constructor/destructor/event/cancel/paint helpers | [UID:0004F7][0x00554b40-0x00554b96.RightButtonMenuPaneConstructor](by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md), [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md), [UID:0004F9][0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent](by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md), [UID:0004FA][0x00554f59-0x00554f83.RightButtonMenuPaneOnEventJumpTables](by-memory/0x00554f59-0x00554f83.RightButtonMenuPaneOnEventJumpTables.md), [UID:0004FB][0x00554f90-0x00554fb3.RightButtonMenuPaneOnCancel](by-memory/0x00554f90-0x00554fb3.RightButtonMenuPaneOnCancel.md), [UID:0004FC][0x00554fc0-0x00555298.RightButtonMenuPaneOnPaint](by-memory/0x00554fc0-0x00555298.RightButtonMenuPaneOnPaint.md), [UID:0004FD][0x005552a0-0x005552ba.RightButtonMenuPaneCloseRightClickAndVoteMenus](by-memory/0x005552a0-0x005552ba.RightButtonMenuPaneCloseRightClickAndVoteMenus.md), [UID:0004FE][0x005552c0-0x005552e4.RightButtonMenuPaneSetTargetNameAndId](by-memory/0x005552c0-0x005552e4.RightButtonMenuPaneSetTargetNameAndId.md), [UID:0004FF][0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground](by-memory/0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md), [UID:0004FG][0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder](by-memory/0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md), [UID:0004FH][0x005556a0-0x005556ed.RightButtonMenuPaneGetMenuItemRect](by-memory/0x005556a0-0x005556ed.RightButtonMenuPaneGetMenuItemRect.md), [UID:0004FI][0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem](by-memory/0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem.md) | class children through UID0000C0, except direct-file UID0004FH/UID0004FI | Address-ordered source-authored methods include source-complete UID0004F9 OnEvent with `RequestObjectInfo(m_targetId)`, the ordinary destructor, cancel/close/setter, OnPaint/DrawBackground/DrawBorder, and receiver-free geometry helpers. The constructor remains a separate body target; jump tables remain compiler data. |
| packet helpers | [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md) | raw helper island / file-local static helpers | B015 resolves the island as two `static __stdcall` file-local helpers in `RightButtonMenuPane.cpp`, emitted through [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md): `SendRightButtonTargetActionPacket(int)` and `SendRightButtonNameCommandPacket(const wchar_t *)`. No direct caller refs are currently proven, but source placement stays in this file by right-click menu locality and target id/name semantics. |
| destructor thunks | `0x00556212-0x00556228` | disabled `class_RightButtonMenuPane.cpp` | Compiler-generated secondary-base deleting-destructor adjustor thunks; track for vtable layout but ignore as handwritten source. |
| scalar deleting destructor | [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md) | source-induced empty marker under `RightButtonMenuPane.cpp` | Compiler-generated MSVC scalar deleting destructor ABI wrapper for `RightButtonMenuPane::~RightButtonMenuPane()`. It duplicates the ordinary destructor cleanup from [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md), adds delete-flag/optional-free handling, and should keep a blank formal C++ block rather than a handwritten wrapper body. |
| [UID:00029Z][0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton](by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md) | `0x0069b4f0-0x0069b4f4` | source-declared singleton storage | Active right-button menu singleton pointer set by constructor, cleared by destructor/scalar-deleting destructor, and read by menu open/lifetime handlers. |

## Resolved Source Order And Literal Policy

The file-level reconstruction order is now explicit:

1. UID0000C0 emits `#include "RightButtonMenuPane.h"`, four file-static forward declarations, and then its address-ordered class children.
2. Class-method children include source-complete `OnEvent`, ordinary destructor, cancel/close/setter, `OnPaint`, `DrawBackground`, and `DrawBorder`; only the constructor remains a separately tracked body-completion target rather than a reason to keep the whole class blank.
3. Receiver-free UID0004FH `GetRightButtonMenuItemRect` and UID0004FI `HitTestRightButtonMenuItem` emit directly through this file, not through class ownership. The packet helpers remain direct-file statics with their documented liveness/name caveat.
4. `RightButtonMenuPane.h` receives the first-draft class declaration from UID0000C0, including direct `Pane` and empty `Singleton<RightButtonMenuPane>` bases, virtual interface, row enum, exact class-owned field widths, and singleton extern.

[UID:0003CZ][0x00623084-0x006230a8.RightButtonMenuCommandStrings](by-memory/0x00623084-0x006230a8.RightButtonMenuCommandStrings.md) is compiler/linker literal-pool support. Source contains direct `L"Look"`, `L"Trade"`, `L"Whisper"`, `L"Group"`, and `L"Info"` arguments in `OnPaint`; no string table, resource record, or standalone raw-data emitter belongs in this file. Shared pooling explains why Whisper/Group reside with Chatting literals. The exact runtime anomaly remains intentional in reconstruction: Info is drawn at y `117`, while the five generated hit rectangles span y `22..102` and the event switch still contains case `4`.

Expected generated closure is one nonempty class scaffold/header, one `OnPaint`, one `DrawBackground`, one `DrawBorder`, one direct-file rectangle helper, and one direct-file hit-test helper, with no UID0003CZ or UID0000C0 empty marker and no raw `sub_`/`dword_`/`off_` names in accepted source bodies.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x00554b40-0x00554b96` constructor.
- `0x00554ba0-0x00554c33` destructor.
- `0x00554c40-0x00554f59` event/action handler.
- `0x00554f90-0x00554fb3` cancel handler.
- `0x00554fc0-0x00555298` paint routine.
- `0x005552f0-0x00555361` background draw.
- `0x00555370-0x00555692` border draw.
- `0x005556a0-0x005556ed` menu-item rectangle helper.
- `0x005556f0-0x0055577b` five-row hit-test helper; current generated owner is `BulletinSession`, but IDA callers are only from `RightButtonMenuPane::OnEvent`.
- `0x00555780-0x005558c2` raw packet helper island; IDA does not model the starts as functions, but disassembly confirms packet construction through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC`, with a six-byte `0xcc` internal alignment span at `0x005557da-0x005557e0`.
- `0x00556212-0x00556228` destructor adjustor/thunk helpers.
- `0x00556240-0x00556314` scalar deleting destructor.

## Ownership Notes

- This is not the generic reusable `MenuPane` class. It hard-codes gameplay actions such as Look, Trade, Whisper, Group, and Info.
- It is also separate from `MenuVarietyPane`, which opens the global menu-variety selector for Userlook/Board/Mail/Friends/Profile/Ranking/Quit.
- It is adjacent to [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md), which owns the Promote/Demote vote popup at `0x005558d0+`. Do not use the old broad `0x00554b40-0x00556314` span as a single owner range; it crossed the vote-popup island.
- Current emitted source omits markers/bodies for `0x00556212` and `0x0055621d`; keep those in memory docs for migration.
- Active generated source labels several `0x0069ba38` references as `g_pBulletinSession`; IDA xrefs and [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md) show they are vote-popup singleton checks.
- 2026-05-26 recheck: current `class_RightButtonMenuPane.cpp` still calls the five-row helper through generated `BulletinSession::HitTestMenuItem`, and current `class_BulletinSession.cpp` still emits that helper body at `0x005556f0`.
- 2026-05-26 recheck: IDA decompiles `0x00556212` and `0x0055621d` as `this - 0xa0` / `this - 0xa4` adjustors that jump to `0x00556240`; these are now recorded in [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-06-01 recheck: IDA caller/pointer scans found no direct references to `0x00555780` or `0x005557e0`; keep the packet helper island under this file by adjacency and packet-helper behavior, not by proven direct calls.
- 2026-06-07 A010 parent-gate refresh: [UID:00029Z][0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton](by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md) now records the exact singleton storage, initialized bytes, ten direct xrefs, and neighboring singleton boundaries. This strengthens the source root enough to clear the corrected 85/85 gate for class/global storage routing while preserving the raw packet-helper caveat.
- 2026-06-12 A005 Batch245: live IDA rechecked [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md), confirming the two raw non-function starts, no direct xrefs, no pointer-pattern hits, exact sizes/padding, and packet-sender calls. The helper now attaches through [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md), while this file remains the source root.
- 2026-06-16 A002 file-root refresh: live IDA `entity_query` over `0x00554b40-0x005558d0` now records eleven `RightButtonMenuPane` core functions, including the previously omitted `0x005552a0` dismissal helper and `0x005552c0` target id/name setter. `xrefs_to(0x005552a0)` is the vote-popup mouse handler call at `0x00555a3d`; `xrefs_to(0x005552c0)` is the compact-display/menu-open caller at `0x00507707`.
- The same pass reconfirmed `0x00555780` and `0x005557e0` as raw no-function packet-helper starts with no `xrefs_to` entries and no little-endian pointer-pattern hits, and reconfirmed the scalar deleting destructor wrapper at `0x00556240` as class-owned. This resolves the direct-owner/file-shortcut blocker for the core and scalar wrapper while preserving packet-helper liveness and final helper-name caveats.
- 2026-06-19 B015 source-quality recheck resolves [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md) as first-draft C++ ready file-local right-click menu helpers. The target-id helper sends opcode `0x4a`, subcommand `0`, and a big-endian target id; the target-name helper sends a dot-prefixed CP_ACP name command. No direct caller refs are currently proven, so the file keeps neutral helper names and does not promote the second helper to a final `Whisper` name yet.
- 2026-07-03 B005 split implementation: [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md) is now a non-emitting container. Child pages `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI` emit first-draft formal C++ through [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md); child pages `0004F7`, `0004F8`, `0004F9`, `0004FC`, `0004FF`, and `0004FG` stay source-owned with blank emitters and child-specific no-code proof until class/API names are synchronized; `0004FA` remains non-emitting generated switch data. MCP session `1fc4a5a7` resolved Look/Trade/Whisper/Group/Info row labels, target field layout (`this+252` id, `this+256` `wchar_t[33]` name), event action mapping, `0x00554f59-0x00554f83` jump-table data, and packet-helper no-direct-xref evidence.
- 2026-07-05 B008 UID0001G2 callback: live MCP session `supervisor_recovery_20260705` confirmed the scalar deleting destructor as exact `0xd4` compiler-generated ABI glue reached by RightButtonMenuPane vtable slots and adjustor thunks, with no direct static callers. It restores the RightButtonMenuPane vtables, performs the same highlighted-target clear, Pane teardown, and singleton clear as the ordinary destructor, then handles MSVC delete flags, optional `OperatorDeleteWrapper`, and the flag-`4` guard/no-op size path. Keep the generated output treatment as an empty marker/no-code wrapper; do not emit a handwritten scalar deleting destructor body.
- 2026-07-22 B004 UID0004F8 source closure: the ordinary destructor now emits through [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md) at source position `30` in `NexusTK/ui/menu/RightButtonMenuPane.cpp`. Its handwritten source clears `g_activeMapPane->m_highlightedObjectPane` through `SetHighlightState(false)`, nulls the member, and calls `RemoveFromLayer()` plus `UnregisterEventHandler()`; vptr restores, direct Singleton clear, implicit Pane destruction, EH scaffolding, and scalar-delete behavior remain compiler lowering.

## Ordinary Destructor Source Placement

- [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md) is the source-authored ordinary non-deleting destructor for this file, not a raw helper or duplicate of the scalar wrapper.
- The exact source body belongs in `RightButtonMenuPane.cpp` through the class route [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md). It preserves the binary's unconditional `g_activeMapPane` dereference, conditional highlighted-object test, call-before-null order, and explicit Pane layer/event unregister calls.
- Direct `Singleton<RightButtonMenuPane>` and `Pane` base destruction explains the binary-only singleton clear and final base destructor call. Three vptr restores, SEH/security-cookie scaffolding, deleting-destructor flags, and operator delete are also excluded from handwritten source.
- The former 2026-07-03 statement that UID0004F8 required unresolved helper/API names is retained as historical split-state context but is superseded by live destructor-family evidence and current typed MapPane/LivingObjectPane/Pane support. Other blank children remain independently blocked and are not promoted by this closure.

## Cross-References

- [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md)
- [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md)
- [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md)
- [UID:0001G0][0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks](by-memory/0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks.md)
- [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)

## UID0004F9 OnEvent Source Closure - 2026-07-29

- UID0004F9 now emits the complete right-button target-menu event method through UID0000C0 at `92/94`. The Info row calls externally linked `RequestObjectInfo(m_targetId)` through the MapPane header; Trade and Group packet construction stays inline because raw helper starts `0x00555780/0x005557e0` have no call/xref route.
- `SetTargetNameAndId(int targetId, const wchar_t *targetName)` order, five-row hit test, vote-popup coordination, Look/Whisper construction, outside dismissal, and adjacent UID0004FA switch tables remain exact. Historical blank-emitter and raw `sub_50F4D0`/`MapPaneSendObjectAction43Packet` statements below describe superseded stages rather than current source readiness.

## Changes

- 2026-06-07: Replaced the raw `dword_67A7EC` right-click packet-helper reference with canonical [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) wording.
  - Before: the packet helper island evidence named only the historical generated sender global.
  - After: the page links the resolved packet sender while retaining the historical label and raw-helper caveat.
  - Evidence: the generated resolved-name report maps `dword_67A7EC` to `g_packetSender`, and this page's existing IDA disassembly note ties the raw helper island to packet construction adjacent to `RightButtonMenuPane`.

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `86`.
  - Evidence: document contains IDA-confirmed method boundaries, proposed source owner, ownership exclusions against neighboring popup/menu classes, generated-owner pollution notes, destructor thunk handling, and cross-references; confidence is high because the role and boundaries are strongly verified.
- 2026-06-01: Added the adjacent raw packet helper island and set proposed reconstruction path to `NexusTK/ui/menu/`.
  - Evidence: IDA MCP confirms `0x00555780-0x005558c2` as packet-building raw bytes with no direct function model, plus an internal `0xcc` alignment gap; placement between the right-click core and vote menu keeps it with this file until caller evidence proves another owner.
- 2026-06-07 A010 Batch044 parent-gate update:
  - Before: `84/86`; the file had strong method-boundary and packet-helper evidence but omitted the exact singleton storage as a proposed child.
  - After: `85/86`; added [UID:00029Z][0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton](by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md) to proposed contents and evidence notes, allowing the class and singleton storage chain to satisfy the corrected 85/85 gate. Final C++ remains blank.
- 2026-06-12 A005 Batch245:
  - Updated the packet-helper proposed-contents row after [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md) reached `85/86` and attached to the direct class parent. File score is unchanged because direct callers and final helper names are still unresolved.
- 2026-06-16 A002 file-root completion pass:
  - Before: `85/86`; the source root was strong but the core method inventory missed two modeled helpers and two class-owned memory children still used a file-parent shortcut.
  - After: `86/88`; refreshed the live IDA method inventory, added the dismissal and target metadata helpers through [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md), corrected direct class routing for the core and scalar wrapper support pages, and retained the raw packet-helper/no-caller blocker after fresh xref and `find_bytes` checks.
- 2026-06-19 B015 Rule 26 support sync:
  - Updated the packet-helper proposed-contents row and ownership notes after [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md) resolved source-quality helper names/signatures and first-draft C++ policy. The source root remains `NexusTK/ui/menu/RightButtonMenuPane.cpp`; direct row-specific action names remain inferred until caller/row mapping is recovered.
- 2026-07-03 B005 implementation callback:
  - Updated UID0001FX source-output treatment after split-first implementation and Gate 2 emitter repair. The aggregate no longer emits directly; exact child methods/helpers `0004FB`, `0004FD`, `0004FE`, `0004FH`, and `0004FI` carry first-draft formal C++ through [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md), while `0004F7`, `0004F8`, `0004F9`, `0004FC`, `0004FF`, and `0004FG` are source-owned no-code children with blank emitters and proof. The file keeps [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md) separate with its no-direct-caller caveat, while `OnEvent` child evidence now maps row actions and field offsets.
- 2026-07-05 B008 implementation callback:
  - Updated the UID0001G2 proposed-contents row and ownership notes to document it as compiler-generated scalar deleting destructor ABI evidence/no-code output. No file metadata changed; source-authored destructor cleanup remains with [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md), and the wrapper stays under [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md) through this source root.
- 2026-07-22 B004 accepted implementation callback:
  - Preserved file metadata at `86/88`, proposed path `NexusTK/ui/menu/`, packet-helper liveness caveats, VoteMenuPane boundary evidence, and generated-owner correction history.
  - Updated UID0004F8 from a helper-name-blocked blank child to the emitting ordinary destructor at class source position `30`, with exact handwritten-versus-compiler-lowered behavior.
  - Kept UID0001G2 blank as compiler-generated scalar deleting destructor evidence and left all other child emitter decisions unchanged.
- 2026-07-28 B001 UID0003CZ accepted implementation callback:
  - Raised `86/88 -> 90/93` and preserved `NexusTK/ui/menu/` as the source root.
  - Added exact class-scaffold, address-ordered class-child, direct-file geometry/helper, and header output topology; source-closed OnPaint/background/border and corrected UID0004FH/UID0004FI from member-method fiction to receiver-free file statics.
  - Reclassified UID0003CZ as compiler-literal support regenerated by direct consumer literals, retained pooled Whisper/Group evidence, preserved packet/singleton/vtable/scalar-wrapper exclusions, and recorded the exact Info y=`117` versus five-row hit-test anomaly.
