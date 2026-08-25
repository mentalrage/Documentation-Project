*** UID:000052 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FittingRoomDownloadControlPane

## Status

- Confidence: strong for the local download-progress pane identity, medium for final field names and raw constructor/destructor reachability.
- Proposed source module: [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- Autogen status: reconstructable class under the fitting-room source module; the class container C++ remains blank, but [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md) is now source-ready as the formal constructor through this class emitter. The `OnPaint` child split is present as [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md), and class-level C++ is still capped by pane field names, render/resource helper declarations, and helper ownership exclusions.
- Evidence basis: live IDA MCP function lookup, xrefs, callees, decompilation, and raw-range disassembly checks on 2026-06-03.

## Role

Download progress control used by the fitting-room asset/catalog loading flow. The strongest local method is the progress-pane paint routine at `0x0041ba40`, which draws progress text/bar style state.

The small [UID:0001UI][FittingRoomDownloadProgressState](by-type/by-struct/FittingRoomDownloadProgressState.md) helper island at [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md) is now split into exact children. [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md) feeds progress percentages into the fitting-room action path before this pane is refreshed; the reset/no-op siblings remain non-emitting no-route children. Current generated `class_Region.cpp` ownership for the old aggregate helper was caller/name pollution.

## Strong Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md) | source-ready constructor body | B007 MCP session `2ec9c08f` confirms exact raw bytes, no function object/start-or-interior xrefs, no pointer/immediate route, `ControlPane` setup type `8`, three fitting-room download vtable writes, `+0x108` progress clear, vtable-family refs, and an inline UID0002CP construction sequence; emits as `FittingRoomDownloadControlPane(const RectBounds *bounds)` with raw-start reachability and field spelling retained as confidence caps. |
| [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md) | raw ordinary destructor evidence / no-code body | B008 MCP session `2ec9c08f` confirms exact `0x1f` body, no direct xrefs to `0x0041ba20`, vtable restores to `0x0060d9c4` / `0x0060da2c` / `0x0060da5c`, and tail jump to shared teardown `0x00544580`; owner route is class-attached, but formal C++ stays blank because the visible vtable destructor route is scalar wrapper UID0002EI and the raw body is compiler vptr restoration/shared teardown sequencing. |
| [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md) | `OnPaint` | Current B003 MCP session `80de0a67` confirms `sub_41BA40` size `0x38e`, vtable data xref `0x0060da08`, progress byte `this+0x108`, render/resource helper calls, SHA16 `a049034203d827aa`, and blank formal C++ until render/member declarations are source-quality. |
| [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md) | scalar deleting destructor wrapper | Confirmed compiler-generated wrapper that restores vtables, calls shared teardown, and conditionally deletes `this`. |

## Local Core Evidence

| Evidence | Meaning | Confidence impact |
| --- | --- | --- |
| Raw constructor body writes `FittingRoomDownloadControlPane` vtables at offsets `0x0`, `0xa0`, and `0xa4` | Confirms this is a distinct pane/control subclass, not just a file-level helper cluster. | Raises class identity confidence. |
| Raw constructor clears word `this + 0x108` | Identifies a local state field used by the download/progress pane. | Supports reconstruction, but field name remains unresolved. |
| `0x0041ba40-0x0041bdcd` draw routine follows the raw constructor/destructor island | Places the strongest behavior immediately after the pane lifecycle bodies. | Supports source-module ownership. |
| Deleting destructor `0x0041d580-0x0041d5d5` restores the same vtables and conditionally deletes `this` | Confirms compiler-generated lifecycle wrapper for the same class. | Raises confidence enough to attach to `FittingRoom`. |
| Progress percent child [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md) under parent [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md) feeds fitting-room action flow before pane refresh | Links the visible progress control to the fitting-room asset/catalog loading path without making this pane the helper owner. | Supports role description and rejects control-pane ownership of the helper receiver. |

## Batch100 Lifecycle Body Audit

The raw lifecycle body pages [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md) and [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md) are now assignment-ready under the corrected 85/85 target rule. The constructor and destructor-shaped bodies are complete adjacent lifecycle ranges, write or restore the same three `FittingRoomDownloadControlPane` vtables, bracket the vtable-referenced paint routine at primary vtable slot `17`, and are corroborated by the scalar deleting destructor wrapper at [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md).

The remaining no-function/no-direct-start-xref caveats remain real confidence caps, but B007's 2026-07-03 source-quality pass resolves UID0000WP more narrowly: the raw constructor now has formal source C++ through this class because MCP session `2ec9c08f` matched the raw body to the inline UID0002CP construction sequence at `0x0041c17c-0x0041c19b`. UID0000WQ remains blank under the destructor no-code policy below.

B008 2026-07-03 MCP session `2ec9c08f` resolves the UID0000WQ source-output policy more narrowly: [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md) is class-owned raw ordinary destructor evidence and remains blank formal C++. Current evidence reconfirms no direct xrefs to `0x0041ba20`, the same three vtable restores, the tail jump at `0x0041ba3a` to broad shared teardown `0x00544580`, constructor-return/padding/paint boundaries, and primary vtable slot route `0x0060d9c4 -> 0x0041d580`. [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md) remains the compiler-generated scalar deleting wrapper and visible destructor route; do not hand-port UID0000WQ's vptr restoration/shared teardown sequencing as source C++.

## IDA Evidence Snapshot

Live IDA MCP checks on 2026-06-03 confirm the local class core:

| Address | IDA result | Evidence |
| --- | --- | --- |
| `0x0041b9e0` | no IDA function record | Raw disassembly is a constructor-shaped body: pushes constructor argument and type/id `8`, calls `sub_4949E0`, writes the three `FittingRoomDownloadControlPane` vtables, clears `word ptr [this + 0x108]`, and returns with `retn 4`. B007 MCP session `2ec9c08f` also confirms no start/interior xrefs or pointer route, but the matching inline UID0002CP sequence makes the body source-ready as the class constructor with those no-route facts kept as confidence caps. |
| `0x0041ba20` | `sub_41BA20`, size `0x1f` | Raw ordinary destructor evidence; B008 MCP session `2ec9c08f` reconfirmed exact bytes, no direct xrefs, vtable restores to `0x0060d9c4` / `0x0060da2c` / `0x0060da5c`, and tail jump/call to broad shared teardown `sub_544580`. Formal C++ stays blank because the vtable-visible destructor route is `0x0041d580`. |
| `0x0041ba40` | `sub_41BA40`, size `0x38e` | Paint routine with a vtable data xref from `0x0060da08`; decompilation draws centered text, frame pieces, and a percentage-width progress fill using `MulDiv(..., byte[this + 0x108], 100)`. |
| `0x0041d580` | `sub_41D580`, size `0x55` | Scalar deleting destructor wrapper; vtable/data xref at `0x0060d9c4`, code xrefs from adjustor thunks `0x0041d471` and `0x0041d47c`, restores vtables, calls `sub_544580`, and conditionally calls `sub_4F4AC0`. |

2026-06-08 A001 IDA MCP recheck reconfirmed `0x0041b9e0` has no IDA function object and no start/interior xrefs at `0x0041b9e0`, `0x0041b9f2`, or `0x0041ba14`; `0x0041ba20` is still the exact `0x1f`-byte non-deleting body with no direct start xrefs; `0x0041ba40` is the exact `0x38e` paint routine; and `0x0041d580` is the exact `0x55` scalar deleting destructor wrapper. The same pass reconfirmed vtable-family refs from the raw constructor stores, the raw destructor restores, the dialog constructor at `0x0041bdd0`, and the deleting wrapper.

## Boundary Cautions

- IDA MCP reports `0x0041b9e0` is not a function start and has no direct xrefs. The bytes are documented as [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md): they call `ControlPane` setup with type `8`, install the `FittingRoomDownloadControlPane` vtables at offsets `0x0`, `0xa0`, and `0xa4`, clear the word at `0x108`, and return with `retn 4`. B007's callback keeps the raw-start no-route caveat but no longer treats it as a constructor blank-C++ blocker.
- The adjacent [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md) body restores the same vtables and calls shared teardown helper `0x00544580`; IDA has a function object for this start but currently no xrefs.
- The confirmed deleting destructor at [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md) restores the fitting-room download vtables, calls shared pane/control teardown helper `0x00544580`, and conditionally calls delete helper `0x004f4ac0`.
- Stale generated owner assignments place unrelated fitting-room dialog and generic rendering helpers under this class; current IDA evidence should drive ownership instead of those labels.
- Current attached helpers include field-map helpers (`0x004b1130`, `0x004b11a0`), generic draw/text helpers (`0x004b9600`, `0x004b9680`, `0x004ba9a0-0x004bad66`, `0x004bb5e0`, `0x00593b20+`), and IME/text-edit functions (`0x004e7470`, `0x004e7930`). `0x004b11a0` is now documented as a [UID:000151][0x004b11a0-0x004b1242.FieldMapRequestHelper](by-memory/0x004b11a0-0x004b1242.FieldMapRequestHelper.md), `0x004b1130` as a [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md), `0x004b9600` / `0x004b9680` as [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), `0x004ba9a0-0x004bad66` / `0x004bb5e0` as [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) and [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md), `0x00593c20` / `0x00593db0` under [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and the IME helpers under [UID:0000K5][IMEPanes](by-file/IMEPanes.md); treat these as owner-pollution candidates here.
- Current attached helpers also include `0x00541660` and `0x005416d0`. IDA MCP rechecked them on 2026-05-25 and found every direct caller inside `NewOptionPane::OnPaint`, not fitting-room code. Treat [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md) and [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md) as option-pane owner-pollution candidates.
- B003 2026-06-23 accepted split replaces the old aggregate-only OnPaint row with [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md). The child is reconstructable under this class but intentionally blank-C++; generated/GrafPort/render helpers remain dependencies, not class-owned methods, and direct-file/no-owner alternatives are rejected by the vtable xref and matching lifecycle evidence.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The class has current live IDA evidence for the source-ready UID0000WP constructor, non-deleting destructor, exact child [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md) vtable-referenced paint method, scalar deleting destructor, local progress field, progress-state linkage, parent source ownership, and Batch100 lifecycle-body assignment audit. Completion remains below final-audit range because render/resource helper declarations, several attached helper labels, and final member names are not source-quality enough for class-level C++. |
| Confidence `90` | Vtable writes, vtable restoration, vtable data xrefs, shared teardown, destructor thunk xrefs, B003 `80de0a67` OnPaint size/SHA evidence, B007 `2ec9c08f` constructor/inline-sequence evidence, and fitting-room parent evidence are direct and consistent. Confidence is not higher because the raw constructor still has no IDA function record/xrefs and final member names are not proven. |

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0001UI][FittingRoomDownloadProgressState](by-type/by-struct/FittingRoomDownloadProgressState.md)
- [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md)
- [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md)
- [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md)
- [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md)
- [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md)
- [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md)
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016I][0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md)
- [UID:0001DZ][0x00541660-0x005416d0.NewOptionPaneDrawBoldText](by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md)
- [UID:0001E0][0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem](by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md)

## Changes

- 2026-07-03 B007 UID0000WP implementation callback: Synced [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md) after supervisor-provided MCP session `2ec9c08f`. The target is now `88/90` and emits formal constructor C++ through this class with `ControlPane(8, bounds)` and `m_progressPercent(0)`. Current proof preserves exact bytes, predecessor padding, successor destructor, no function object/start-or-interior xrefs, no pointer/immediate route, vtable-family refs from raw constructor/raw destructor/dialog constructor/deleting wrapper, fixed ControlPane type `8`, and the `+0x108` progress clear. Raw-start reachability, exact progress field spelling/type, and child id `7` argument ambiguity remain confidence caps; UID0000WQ stays blank by the accepted B008 destructor no-code policy.
- 2026-07-03 B008 UID0000WQ implementation callback: Synced [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md) after MCP session `2ec9c08f`. The raw ordinary destructor evidence remains class-owned and blank-C++; current proof includes exact `0x1f` body, no direct xrefs to `0x0041ba20`, vtable restores at `+0/+0xa0/+0xa4`, shared teardown tail jump `0x0041ba3a -> 0x00544580`, constructor-return/padding/paint boundaries, broad shared-teardown caller evidence, and scalar deleting wrapper/vtable-slot route [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md). This rejects raw destructor C++ emission, generic Pane/ControlPane helper ownership, no-owner metadata, padding, and range extension into paint.
- 2026-07-03 B006 UID0000WG split sync: Updated the progress-state helper reference so this class remains a consumer, not the owner. The source-ready progress calculation now lives in [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md); reset/no-op siblings remain non-emitting no-route children under split/index parent [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md).
- 2026-06-23 B003 accepted split implementation: Raised from `85/89` to `86/90`, replaced the address-only OnPaint row with [UID:00041P][0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers](by-memory/0x00526570-0x0052664b.MidiPlayerCompilerCleanupHelpers.md), and recorded MCP `80de0a67` evidence: `0x38e` body, vtable xref `0x0060da08`, progress byte `this+0x108`, SHA16 `a049034203d827aa`, render/resource dependency boundary, and blank-C++ policy for the child.
- 2026-06-08 A001 Batch100 parent-gate audit:
  - Before: `COMPLETION:80`, `CONFIDENCE:88`.
  - After: `COMPLETION:85`, `CONFIDENCE:89`.
  - Evidence: live IDA MCP reconfirmed the raw constructor no-function/no-xref status, exact constructor bytes, exact `0x0041ba20-0x0041ba3f` destructor body, exact `0x0041ba40-0x0041bdce` paint routine, exact `0x0041d580-0x0041d5d5` scalar deleting wrapper, all three fitting-room download vtable store/restore/xref groups, and the primary vtable slot `17` paint entry. This raises the class over the strict direct-parent gate for [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md) and [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md), while keeping final C++ blank because function-start reachability and field names are not final-source quality.
- 2026-06-07 A001 supervisor correction audit:
  - What changed: replaced parent-readiness wording with a lifecycle-body audit and clarified that [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md) and [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md) remain unassigned because they do not meet the corrected 85/85 target assignment rule.
  - Reasoning: the class-level evidence remains useful and supports the `80/88` score, but the child pages still lack function-object/start-xref evidence and remain below 85 completion.
- 2026-06-07 A001 parent readiness update:
  - What changed: raised completion to `80`, kept confidence at `88`, and added a parent attachment readiness section for the raw constructor/destructor body pages.
  - Reasoning: existing live IDA evidence proves the class identity through matching vtable writes/restores, the adjacent lifecycle/paint layout, the scalar deleting destructor wrapper, and fitting-room file ownership. The class now clears the parent gate for [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md) and [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md); final C++ remains blank for the same OnPaint/member/helper-owner blockers.
- 2026-06-03: Raised completion/confidence to `78/88` after live IDA MCP reconfirmed the raw constructor bytes at `0x0041b9e0`, `sub_41BA20` size `0x1f`, `sub_41BA40` size `0x38e` with vtable data xref `0x0060da08`, and `sub_41D580` size `0x55` with adjustor-thunk and vtable xrefs. The update also removes generated-source evidence from the status/boundary sections. C++ stays blank because the `OnPaint` child split and final member/helper names are not source-quality yet.
- 2026-06-02: Raised the class page to 70/82, marked it reconstructable, and attached it to [UID:0000JE][FittingRoom](by-file/FittingRoom.md). Added local core evidence and score rationale while leaving C++ blank because field names, `OnPaint` child boundaries, and helper ownership are not final-source quality.
- 2026-05-30: Added a direct by-memory reference for the confirmed `0x0041d580-0x0041d5d5` deleting-destructor wrapper and scored the class page from 0/0 to 62/76. Evidence: IDA MCP confirms the wrapper's function size, vtable reference, adjacent adjustor-thunk callers, shared teardown call, and conditional delete-helper call.
- 2026-05-27: Existing boundary note treated `0x0041b9e0` mainly as a projected non-function start. Changed it to document the actual byte-level split: `0x0041b9e0-0x0041ba20` is a raw constructor-shaped body and `0x0041ba20-0x0041ba3f` is a raw destructor/body helper. Evidence: IDA MCP still reports no function/xrefs at `0x0041b9e0`, while manual IDA disassembly shows vtable installation, `this + 0x108` initialization, and adjacent vtable restore plus shared teardown before `OnPaint`.
