*** UID:0000N7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RightButtonMenuPane

## Status

- Confidence: strong for right-click target menu ownership and IDA boundaries.
- Proposed module folder: `ui/menu/`
- Candidate file: `ui/menu/RightButtonMenuPane.cpp`
- Current generated source: `class_RightButtonMenuPane.cpp`
- Evidence basis: Wave3 class inspection, generated source, IDA MCP boundary checks, and caller evidence from the compact-display/menu open path.

## Hypothesis

`RightButtonMenuPane` is a standalone gameplay context menu for right-clicking another visible player or target. It draws a small SUBWIN-styled menu, tracks selected rows, opens look/whisper/group/info actions, sends trade/group-related packets, and clears highlighted object state on teardown.

Likely structure:

```text
ui/menu/RightButtonMenuPane.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `RightButtonMenuPane` core | `0x00554b40-0x0055577b` | `class_RightButtonMenuPane.cpp`, helper currently under `class_BulletinSession.cpp` | Right-click target context menu and five-row hit-test helper. |
| packet helpers | `0x00555780-0x005558c2` | raw helper island | Packet builders adjacent to the right-click menu core; no direct caller xrefs yet, but behavior and placement match right-click menu action support. |
| destructor thunks | `0x00556212-0x00556228` | disabled `class_RightButtonMenuPane.cpp` | Compiler-generated secondary-base deleting-destructor adjustor thunks; track for vtable layout but ignore as handwritten source. |
| scalar deleting destructor | `0x00556240-0x00556314` | `class_RightButtonMenuPane.cpp` | Destructor wrapper and optional delete. |

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
- `0x00555780-0x005558c2` raw packet helper island; IDA does not model the starts as functions, but disassembly confirms packet construction through `dword_67A7EC`, with a six-byte `0xcc` internal alignment span at `0x005557da-0x005557e0`.
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

## Cross-References

- [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md)
- [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md)
- [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md)
- [UID:0001G0][0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks](by-memory/0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks.md)
- [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `86`.
  - Evidence: document contains IDA-confirmed method boundaries, proposed source owner, ownership exclusions against neighboring popup/menu classes, generated-owner pollution notes, destructor thunk handling, and cross-references; confidence is high because the role and boundaries are strongly verified.
- 2026-06-01: Added the adjacent raw packet helper island and set proposed reconstruction path to `NexusTK/ui/menu/`.
  - Evidence: IDA MCP confirms `0x00555780-0x005558c2` as packet-building raw bytes with no direct function model, plus an internal `0xcc` alignment gap; placement between the right-click core and vote menu keeps it with this file until caller evidence proves another owner.
