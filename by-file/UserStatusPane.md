*** UID:0000P2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# UserStatusPane

## Status

- Current source-quality state: `93/94`; direct `ui/panels/UserStatusPane.cpp` ownership, complete declarations and exact body order for all three variants, retained no-entry source helpers, resources/globals, and compiler boundaries are resolved without loss.
- Proposed module: `ui/panels/UserStatusPane.cpp`
- Proposed header: `ui/panels/UserStatusPane.h`
- Current generated leads: `source-3/simroot_v2/class_UserStatusPane.cpp`, `class_UserStatusPane2.cpp`, and historical `class_OldUserStatusPane.cpp` output. Treat generated output as lead material only.

## File Role

`UserStatusPane.cpp` should own the local player status HUD panes. The code supports both the newer/high-resolution layout and the older compact/legacy layout selected through [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`; some generated code emitted this same global as `g_uiLayoutMode`.

The strongest source-layout evidence is `InitializeMainUiGraph` at `0x004f7d10`: in the newer layout it constructs both `UserStatusPane` and `UserStatusPane2`; in the older layout it constructs `OldUserStatusPane`. All three load the same `9X11FONT.BIN` numeric glyph table and share status-field update patterns, icon ids, resource families, and destructor thunk layout.

For the corrected parent gate, this file remains strong enough to act as the direct parent for [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md), [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md), and [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md). This file score is unchanged by the B002 split because the file-level grouping was already documented; the split improves the OldUserStatusPane aggregate and child body routing.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) | [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md) plus shared tail helpers | Newer status summary pane: name/title text, nation/totem/class icons, status numbers, bars, tooltips, and status-packet application. |
| [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md) | [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md) non-emitting index, exact UID0004TG-UID0004TR children, and shared tail helpers | Complete `0x120` compact pane: three bars, four grouped numbers, two coordinates, Event routing, four retained no-entry helpers, payload updates, and exact class/vtable/compiler split. |
| [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) | [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md) plus exact child body pages and shared tail helpers | Legacy status panel: `USERSTAT.EPD`, old hover help zones, old icon/bars, retained no-entry packet helpers, and old status-packet application. |
| [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md) | [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md) accessors | Field-layout slice currently emitted as generated [UID:0000I4][CharacterSummaryRecord](by-file/CharacterSummaryRecord.md); fold into `UserStatusPane`, not a separate source file. |
| [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) | [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md) | Newer status-pane singleton; also read by local inventory/user-pane consumers for fields such as the inventory slot count at pointee offset `+0x284`. |
| [UID:0000SN][g_pUserStatusPane2](by-global/g_pUserStatusPane2.md) | `0x0069b4e4` | Compact status-meter singleton. |
| [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) | `0x0069b4ec` | Legacy status-pane singleton. |
| [UID:0001RS][user-status-resources](by-resource/user-status-resources.md) | resource strings in paint/load paths | `USERSTAT`, `NATION`, `TOTEM`, `CLASS`, `BAR`, `COMMA`, palette, and font assets. |
| [UID:0003JC][0x00630edc-0x00630f8c.UserStatusPaneResourceStrings](by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md) | status literal tail in `.rdata` | Shared status HUD resource filenames and numeric formats used by `UserStatusPane`, `UserStatusPane2`, and `OldUserStatusPane`. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Main UI construction | `0x004f837a`, `0x004f83ea`, `0x004f8951` | `InitializeMainUiGraph` constructs the new pair or the old pane depending on layout mode. |
| Newer status pane | `0x005b83b0`, `0x005b8700`, `0x005ba4a0` | Construction, packet routing, field updates, and totem-frame invalidation/creation. |
| Compact meter pane | `0x005bab00-0x005bc60c`, UID0004TG-UID0004TR | Twelve ordered source bodies: construction/destruction, two Event virtuals, paint, invalidation/geometry/glyph helpers, three retained legacy helpers, and compact payload application. |
| Legacy status pane | `0x005bda40`, `0x005bdcb0`, `0x005bf110`, `0x005bf490`, `0x005bf520`, `0x005bf670`, `0x005bf7c0` | Construction, legacy packet routing, retained no-entry helper bodies, cursor-based status field updates, and totem-frame invalidation/creation. |
| Destructor/adjustor tail | [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md) | Shared compiler-generated tail containing singleton clear helpers, adjustor thunks, scalar deleting destructors, and one reusable vector helper. |

## Exact Three-Variant Source Union

The complete no-loss source order is retained rather than replacing one pane family with another:

- **UserStatusPane:** fifteen ordered source bodies remain constructor [UID:0003A8][0x005b83b0-0x005b8526.UserStatusPaneConstructor](by-memory/0x005b83b0-0x005b8526.UserStatusPaneConstructor.md) (10), ordinary destructor [UID:0003A9][0x005b8530-0x005b85ad.UserStatusPaneDestructor](by-memory/0x005b8530-0x005b85ad.UserStatusPaneDestructor.md) (20), accessor island [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md) (30), signed getter [UID:0004T3][0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue](by-memory/0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue.md) (40), setter [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) (50), packet virtual [UID:0003AA][0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent](by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md) (60), pointer virtual [UID:0003AC][0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent](by-memory/0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent.md) (70), paint [UID:0003AE][0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint](by-memory/0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint.md) (80), invalidator [UID:0004T4][0x005b9d70-0x005b9dab.UserStatusPaneInvalidateStatusFieldRect](by-memory/0x005b9d70-0x005b9dab.UserStatusPaneInvalidateStatusFieldRect.md) (90), rect member [UID:0003AD][0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect](by-memory/0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect.md) (100), glyph member [UID:0003AF][0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString](by-memory/0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString.md) (110), legacy position [UID:0004T5][0x005ba100-0x005ba19c.UserStatusPaneApplyLegacyPositionPacket](by-memory/0x005ba100-0x005ba19c.UserStatusPaneApplyLegacyPositionPacket.md) (120), legacy movement [UID:0004T6][0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep](by-memory/0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md) (130), alternate legacy movement [UID:0004T7][0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt](by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md) (140), and payload parser [UID:0003AB][0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload](by-memory/0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload.md) (150). The five retained no-entry helpers are exactly [UID:0004T3][0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue](by-memory/0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue.md) through [UID:0004T7][0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt](by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md); their zero-entry/pointer evidence and inline/source-factorization rationale remain intact.
- **UserStatusPane2:** twelve ordered bodies are [UID:0004TG][0x005bab00-0x005babf7.UserStatusPane2Constructor](by-memory/0x005bab00-0x005babf7.UserStatusPane2Constructor.md) constructor (10), [UID:0004TH][0x005bac00-0x005bac7d.UserStatusPane2Destructor](by-memory/0x005bac00-0x005bac7d.UserStatusPane2Destructor.md) ordinary destructor (20), [UID:0004TI][0x005bac80-0x005baf64.UserStatusPane2HandlePacketEvent](by-memory/0x005bac80-0x005baf64.UserStatusPane2HandlePacketEvent.md) packet Event virtual (30), [UID:0004TJ][0x005baf70-0x005baf75.UserStatusPane2HandlePointerOrMouseEvent](by-memory/0x005baf70-0x005baf75.UserStatusPane2HandlePointerOrMouseEvent.md) pointer/mouse Event virtual (40), [UID:0004TK][0x005baf80-0x005bbe15.UserStatusPane2OnPaint](by-memory/0x005baf80-0x005bbe15.UserStatusPane2OnPaint.md) OnPaint (50), [UID:0004TL][0x005bbe20-0x005bbe5b.UserStatusPane2InvalidateStatusFieldRect](by-memory/0x005bbe20-0x005bbe5b.UserStatusPane2InvalidateStatusFieldRect.md) invalidator (60), [UID:0004TM][0x005bbe60-0x005bc008.UserStatusPane2GetStatusFieldRect](by-memory/0x005bbe60-0x005bc008.UserStatusPane2GetStatusFieldRect.md) rectangle member (70), [UID:0004TN][0x005bc010-0x005bc0e1.UserStatusPane2DrawNumberGlyphString](by-memory/0x005bc010-0x005bc0e1.UserStatusPane2DrawNumberGlyphString.md) number-glyph renderer (80), [UID:0004TO][0x005bc0f0-0x005bc177.UserStatusPane2ApplyLegacyPositionPacket](by-memory/0x005bc0f0-0x005bc177.UserStatusPane2ApplyLegacyPositionPacket.md) legacy position (90), [UID:0004TP][0x005bc180-0x005bc2cc.UserStatusPane2ApplyLegacyMovementStep](by-memory/0x005bc180-0x005bc2cc.UserStatusPane2ApplyLegacyMovementStep.md) legacy movement (100), [UID:0004TQ][0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt](by-memory/0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt.md) alternate legacy movement (110), and [UID:0004TR][0x005bc420-0x005bc60c.UserStatusPane2ApplyStatusPayload](by-memory/0x005bc420-0x005bc60c.UserStatusPane2ApplyStatusPayload.md) status payload (120). The four retained no-entry helpers are [UID:0004TL][0x005bbe20-0x005bbe5b.UserStatusPane2InvalidateStatusFieldRect](by-memory/0x005bbe20-0x005bbe5b.UserStatusPane2InvalidateStatusFieldRect.md) and [UID:0004TO][0x005bc0f0-0x005bc177.UserStatusPane2ApplyLegacyPositionPacket](by-memory/0x005bc0f0-0x005bc177.UserStatusPane2ApplyLegacyPositionPacket.md)-[UID:0004TQ][0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt](by-memory/0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt.md); complete bodies and exact live factorized/inline equivalents preserve them as source despite zero entry xrefs.
- **OldUserStatusPane:** the complete B002/B004/B011 exact child union, `USERSTAT.EPD` behavior, legacy packet/paint paths, retained helpers, singleton/resource/Totem interactions, and shared destructor-tail boundary remain unchanged and are not summarized away by the compact-pane addition. B005 direct target evidence now closes UID000498 as the exact 138-byte retained private legacy-position helper: signed BE16 x/y at packet `+1/+3`, changed-only `m_positionX/m_positionY` updates, field-12 invalidation, constant false result, zero direct entry/pointer route, and source retention through exact opcode-4 inline parity plus both sibling-class analogs.

UserStatusPane2 exact behavior includes packet data at Event `+0x0c`, opcodes `4/8/0x0b/0x26`, three BAR frame groups `0/1/2`, `3/4/5`, `6/7/8`, grouped values and coordinates, MapPane movement bounds, Config option equality to 1, exact flag/cursor payload order, and byte-only percent updates without invalidation. Tables stay in exact children; eleven `0xcc` spans stay parent-only. No class emits handwritten vtables, RTTI, vptr writes, cookies, EH scaffolding, destructor adjustors, deleting flags, or explicit base destruction.

## Source-Layout Notes

- Keep [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) separate. It is address-adjacent between `UserStatusPane2` and `OldUserStatusPane`, but it owns the in-game menu button and selector, not local status rendering.
- [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md) now emits through exact child pages under an aggregate `[[CHILDREN]]` route. The child helpers cover the raw invalidate wrapper, rect lookup switch, numeric glyph renderer, retained legacy position/movement helpers, and live status payload applicator.
- [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md) is now a blank-formal non-emitting split index. Exact source bodies route through UID0004TG-UID0004TR under the complete [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md) declaration.
- The raw OldUserStatusPane helper bodies have no external entry refs, but accepted MCP evidence shows they are valid retained source-shaped code in this file family. They should stay in `UserStatusPane.cpp`, not be moved to MenuVariety or the shared destructor/thunk tail.
- The shared destructor/thunk tail starts at `0x005bfbd0`. Do not assign the first clear helper or compiler adjustor thunks to the OldUserStatusPane source body; keep them under [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md) unless a later report changes the shared-tail disposition.
- Keep [UID:0000OV][TotemFrame](by-file/TotemFrame.md) adjacent or private to this feature area. `UserStatusPane` and `OldUserStatusPane` update handlers create or invalidate `g_pTotemFrame`, while `TotemFrame::OnPaint` asks `OldUserStatusPane::GetSpiritId` for the frame index.
- A plausible original layout is one `UserStatusPane.cpp` containing all three variants plus small static helpers, with `TotemFrame.cpp` either adjacent or folded in after final source grouping review.

## Data Caveats

- Active generated output has historically omitted important IDA-confirmed functions in all three classes, especially packet/update helpers and destructor clear/thunk helpers.
- Historical B002-era generated output for `OldUserStatusPane` was marker-only/stale immediately after the split. Before the B004 UID00049B and B011 UID00049A callbacks, generated `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` header `validator-command-id: 000000007773`, `validator-refreshed-at: 2026-07-07T01:56:42-04:00`, included UID000495-UID00049B method bodies. That pre-callback generated file still carried stale UID00049B status-payload C++ and still listed UID00049A at `86/89` despite the corrected movement-helper body. Treat generated output as lead material, not proof, and use the latest validator-generated header for post-callback freshness.
- Historical generated `class_OldUserStatusPane.cpp` text containing literal `` `n`n`` in the constructor body is stale generated pollution. It should not be used as source evidence or as a reason to block the current split; the accepted B002 report replaced it with current MCP-backed range and helper evidence.
- Active generated output also emits `source-3/simroot_v2/class_CharacterSummaryRecord.cpp` as a standalone recovered class. Treat that file as a generated split of `UserStatusPane` accessors over `g_activeUserStatusPane`, not as an original source module.
- 2026-06-20 B004 rechecked `class_CharacterSummaryRecord.cpp` against the local PE and confirms it is a reviewed alias folded into this file route, not a candidate companion source file.
- Generated destructor bodies label the pane base cleanup as `TextButtonExControlPane::~Pane`; IDA behavior indicates shared pane-base cleanup, so treat that generated base name as suspect.
- Some item/inventory generated output still aliases `0x0069ae0c` as `g_pEffectObjImageLib`, `g_pLocalPlayer`, or raw `DAT_0069ae0c`. IDA evidence keeps the storage with [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md); consumer docs should describe the accessed field rather than adopting the wrong global owner.
- A 2026-05-27 IDA xref audit counted 67 direct xrefs to `dword_69AE0C` across 44 containing-function buckets. This breadth is expected because the active status-pane object exposes local player/status fields, including the inventory slot count at `+0x284`, to multiple UI and item-command subsystems.
- 2026-06-07 A005 Batch 059 parent-gate recheck used the already documented class and memory evidence to raise confidence from `80` to `85`.

## 2026-06-30 B009 Empty-Emitter Family Resolution

B009 reviewed the current generated `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` output for this source file. The file-family row had 27 markers, with 9 filled and 18 empty. The empty markers are not one class of missing code; they divide into class shells, broad aggregate markers, exact method bodies, vtable/storage markers, globals, layout support, and source-use literals.

MCP provenance for the accepted report was current and responsive: `initialize` and `tools/list` succeeded against `ida-pro-mcp 1.0.0`, IDB session `supervisor_resume_20260629`, active worker PID `17592`, auto-analysis ready, Hex-Rays ready, module `NexusTK.exe`, image base `0x400000`, and strings cache ready. The accepted evidence used narrow `lookup_funcs`, `get_bytes`, `xrefs_to`, `entity_query`, and `decompile` calls.

Accepted implementation disposition:

| UID | Entity | Disposition |
| --- | --- | --- |
| [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) | newer status class | Emits a formal class declaration shell with inferred field/helper names and `[[CHILDREN]]`; exact child pages own bodies. |
| [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md) | broad aggregate | Emits a marker-only no-standalone block. Exact pages [UID:0003A8][0x005b83b0-0x005b8526.UserStatusPaneConstructor](by-memory/0x005b83b0-0x005b8526.UserStatusPaneConstructor.md)-[UID:0003AF][0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString](by-memory/0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString.md), [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md), and [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) own bodies. |
| [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md) | exact accessor island | Emits first-draft `UserStatusPane` accessor/setter C++ based on current MCP decompile and B004 source-routing evidence. |
| [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) | exact setter | Emits first-draft `SetStatusIconId` C++. |
| [UID:0002YZ][0x00630c2c-0x00630cb4.UserStatusPaneVtableData](by-memory/0x00630c2c-0x00630cb4.UserStatusPaneVtableData.md) | vtable data | Emits a covered-by marker for [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md). |
| [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md) | field layout slice | Converted to non-reconstructable layout support; `CharacterSummaryRecord` remains rejected as a standalone source type. |
| [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md) | compact status class | Current callback replaces the historical incomplete shell with the exact `0x120` R13 declaration and twelve source children; class closes before `[[CHILDREN]]`. |
| [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md) | compact split index | Historical B009 marker-only/excluded-split state is superseded; current page is `92/94`, false, blank emitter/position/formal with UID0004TG-UID0004TR and eleven parent-only pads. |
| [UID:0002Z0][0x00630cb4-0x00630d3c.UserStatusPane2VtableData](by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md) | vtable data | Remains source-declared/generated-binary with owner/emitter UID0000FT and one covered-by R14 comment; primary/secondary/tertiary cells and `0x00630d3c` MenuVariety boundary are exact. |
| [UID:0002Z3][0x00630e58-0x00630edc.OldUserStatusPaneVtableData](by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md) | vtable data | Emits a covered-by marker for [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md). OldUserStatusPane method bodies remain under accepted B002 exact child routing. |
| [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) | newer status singleton | Emits `UserStatusPane *g_activeUserStatusPane = NULL;`. |
| [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md) | exact singleton storage | Re-routed to [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) and emits a covered-by storage marker. |
| [UID:0000SN][g_pUserStatusPane2](by-global/g_pUserStatusPane2.md) | compact status singleton | Emits `UserStatusPane2 *g_pUserStatusPane2 = NULL;`; stale `ff ff ff ff` initializer language is historicalized because current MCP bytes are zero. |
| [UID:0002WE][0x0069b4e4-0x0069b4e8.g_pUserStatusPane2](by-memory/0x0069b4e4-0x0069b4e8.g_pUserStatusPane2.md) | exact singleton storage | Emits a covered-by storage marker for [UID:0000SN][g_pUserStatusPane2](by-global/g_pUserStatusPane2.md) and records current-zero bytes. |
| [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) | legacy status singleton | Emits `OldUserStatusPane *g_pOldUserStatusPane = NULL;`; stale `ff ff ff ff` initializer language is historicalized because current MCP bytes are zero. |
| [UID:0002WG][0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane](by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md) | exact singleton storage | Emits a covered-by storage marker for [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) and preserves current-zero supersession evidence. |
| [UID:0003JC][0x00630edc-0x00630f8c.UserStatusPaneResourceStrings](by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md) | status resource literals | Keeps formal C++ blank under the accepted source-use literal standard; source-use emission belongs inside consuming method bodies. |
| [UID:00044W][0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString](by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md) | shared `NPAL5.PAL` literal | Already has B014 no-standalone proof with multiple source-use emitters; no edit or comment emitter is required. |

Current MCP storage bytes supersede older initializer notes for the status singleton slots: `0x0069ae0c`, `0x0069b4e4`, and `0x0069b4ec` all read `00 00 00 00`. The accepted xref evidence is 67 direct xrefs for `g_activeUserStatusPane`, 6 for `g_pUserStatusPane2`, and 9 for `g_pOldUserStatusPane`.

Boundary evidence preserved by the callback:

- `0x005baafe` is not a function and the two bytes before `UserStatusPane2` are `0xcc` padding.
- `0x005bc60c` is not a function and `0x005bc610` starts `MenuVarietyPane`, so the compact aggregate does not absorb menu code.
- `0x00630d3c` begins the `MenuVarietyPane` vtable band, so `UserStatusPane2` vtable data ends there.
- `0x00630edc` starts the full UTF-16 `USERSTAT.EPF` literal; IDA's interior `aErstatEpf` label is not a range start.
- `0x00630f8c` starts the MenuVariety literal run, and the status resource child stops before it.

Rejected alternatives:

- Do not paste decompiler-derived monolithic bodies into [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md) or [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md).
- Do not recreate `CharacterSummaryRecord` as a source class.
- Do not add comment-only emitters to [UID:00044W][0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString](by-memory/0x00610fd0-0x00610fe8.SharedNpal5PaletteResourceString.md) or fabricate standalone string-data C++ for [UID:0003JC][0x00630edc-0x00630f8c.UserStatusPaneResourceStrings](by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md).
- Do not move OldUserStatusPane exact bodies out of the accepted B002 child route.
- Do not treat generated aliases such as `g_pEffectObjImageLib`, `g_pLocalPlayer`, or `DAT_0069ae0c` as owners of `0x0069ae0c`.

## 2026-07-20 UID000498 Source-Order And Retention Evidence

- [UID:000498][0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket](by-memory/0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket.md) remains in exact OldUserStatusPane child order between the fifteen-byte pad after UID000497 and the six-byte pad before UID000499. Its body is `[0x005bf490,0x005bf51a)`, 138 bytes, SHA256 `9827B350A771D2CFFFBCF86FDD7A9C7F2661CA0B36DEA51DAE971570E02DC7BD`.
- The private helper reads signed big-endian x/y from packet `+1/+3`, updates OldUserStatusPane int fields `+0x15c/+0x160` only when either changes, lowers field id `12` to rectangle `(101,82,192,94)`, invokes inherited invalidation, and returns `false` on every path.
- The raw start has no entry, code, data, immediate, VA-pointer, or RVA-pointer route. It remains source-bearing because live Old router opcode `0x04` contains exact inline behavior, UID000495 retains the source-level field-id invalidation wrapper, and both other status-pane classes retain matching no-entry position-helper bodies with their class-specific gates/rectangles.
- This evidence strengthens the existing source-family placement without changing file ownership, score, reconstruction path, method counts, class unions, resources, globals, compiler boundaries, or any sibling body. UID000498 alone rises to `92/94`; the file remains `93/94`.
- Historical clarification: B002's split correctly placed the child and emitted its body at `86/90`; the later direct B005 pass supersedes only the earlier limited target evidence, not the B002/B004/B011 union.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | The file preserves the full three-variant union: fifteen ordered UserStatusPane bodies/five retained no-entry helpers, twelve ordered UserStatusPane2 bodies/four retained no-entry helpers, and the complete OldUserStatusPane union with resources, globals, Totem/inventory interactions, exact source order, and compiler boundaries. |
| Confidence | 94 | Construction branches, contiguous address order, singleton/resource ownership, exact class layouts, vtable routes, caller/callee graphs, packet/paint behavior, generated emission, and shared compiler-tail boundaries converge on this source file; only stripped private lexical spellings cap confidence below final audit. |

## Cross-References

- [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- [UID:0000FT][UserStatusPane2](by-class/UserStatusPane2.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000I4][CharacterSummaryRecord](by-file/CharacterSummaryRecord.md)
- [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)
- [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:0003JC][0x00630edc-0x00630f8c.UserStatusPaneResourceStrings](by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md)
- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0004TG][0x005bab00-0x005babf7.UserStatusPane2Constructor](by-memory/0x005bab00-0x005babf7.UserStatusPane2Constructor.md) through [UID:0004TR][0x005bc420-0x005bc60c.UserStatusPane2ApplyStatusPayload](by-memory/0x005bc420-0x005bc60c.UserStatusPane2ApplyStatusPayload.md), the complete UserStatusPane2 source-child sequence.

## Changes

- 2026-07-20 B005 UID000498 implementation callback:
  - Scores and reconstruction path remain `93/94` and `NexusTK/ui/panels/`; no formal C++ or unrelated family content changed.
  - Added the bounded UID000498 source-order and source-retention breadcrumb while preserving the complete fifteen-body UserStatusPane, twelve-body UserStatusPane2, and OldUserStatusPane unions.
- 2026-07-20 B003 UID0001NO accepted callback: raised `92/93` to `93/94`; preserved the existing fifteen-body/five-no-entry UserStatusPane order and complete OldUserStatusPane union while adding the exact twelve-body/four-no-entry UserStatusPane2 order, R13 class route, compact packet/paint/MapPane/Config behavior, vtable/compiler exclusions, eleven parent-only pads, and current generated source expectations.

- 2026-07-20 B001 UID0001NM callback:
  - Raised this file to `92/93` and synchronized the complete newer UserStatusPane source order: UID0003A8 constructor (10), UID0003A9 ordinary destructor (20), UID0001NN accessors (30), UID0004T3 signed getter (40), UID0002LP setter (50), UID0003AA packet virtual (60), UID0003AC pointer virtual (70), UID0003AE paint (80), UID0004T4 invalidator (90), UID0003AD rect member (100), UID0003AF glyph member (110), UID0004T5 position helper (120), UID0004T6 movement helper (130), UID0004T7 alternate movement helper (140), and UID0003AB payload parser (150).
  - Preserved the complete UserStatusPane2, OldUserStatusPane, MenuVariety boundary, resource/global, and shared-tail union. Historical aggregate/comment-only omissions and `CharacterSummaryRecord` source ownership remain explicitly rejected rather than deleted.
- 2026-07-07 B004 UID00049B implementation callback:
  - Scores remain `90/87`.
  - Summary/evidence: updated generated-state caveat and legacy status-pane wording for accepted UID00049B repair. Current generated `UserStatusPane.cpp` header `000000007773` had the stale status-payload body before this callback; source route remains `NexusTK/ui/panels/UserStatusPane.cpp`, and scoped callback validation refreshed generated output rather than manual generated edits.
- 2026-06-30 B009 implementation callback:
  - Changed scores from `88/85` to `90/87`.
  - Summary/evidence: incorporated the accepted empty-emitter-family report for current generated `UserStatusPane.cpp` markers, including MCP provenance, class-shell and aggregate marker dispositions, exact accessor/setter C++ readiness, vtable/storage/global handling, current-zero singleton bytes, `CharacterSummaryRecord` rejection, no-standalone string-literal policy, and generated-boundary negative evidence.
- 2026-07-07 B007 accepted implementation callback:
  - Scores remain `90/87`.
  - Summary/evidence: historicalized the old marker-only OldUserStatusPane generated-output caveat and recorded that generated `UserStatusPane.cpp` header `000000007740` included UID000495-UID00049B method bodies while remaining lead material only. Later B004/B011 pre-callback rechecks superseded that stale-current header wording with `000000007773`.
- 2026-06-28 B002 accepted implementation callback:
  - Scores remain `88/85`.
  - Summary/evidence: added the accepted OldUserStatusPane split/source-layout details, retained no-entry helper disposition, stale generated-output correction, and aggregate child-emission route under [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md). This improves the [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) class/aggregate route but does not independently raise the whole source-file score.
- 2026-06-12 C001 Batch C001-019 related split update:
  - Scores remain `88/85`.
  - Summary/evidence: added [UID:0003JC][0x00630edc-0x00630f8c.UserStatusPaneResourceStrings](by-memory/0x00630edc-0x00630f8c.UserStatusPaneResourceStrings.md) as the exact status HUD literal child.
- 2026-06-07 A005 Batch 059 parent-gate repair:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`.
  - After: `COMPLETION:88`, `CONFIDENCE:85`.
- 2026-06-07 A008 alias cleanup: normalized the layout-mode `byte_66DA97` / `g_uiLayoutMode` wording to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-05-31: Assigned validator reconstruction path `NexusTK/ui/panels/`.
