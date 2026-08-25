** TARGET-REPORT-UID:0003V9 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0003V9 UserPane HandleKeyOrTextEvent Ownership / Split Research


## Finalized Report / Current Recommendation

- Implemented target: validator-preserving rename [UID:0003V9] to `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md`, retained [UID:0000FQ][UserPane] owner/emitter, and exact complete `bool UserPane::HandleKeyOrTextEvent(Event *event)` Destination R1 at `92/94`.
- Implemented disposition: the exact `0x1852`-byte function remains whole; [UID:0003VA] retained its UID through the rename to `UserPaneHandleKeyOrTextEventSwitchTables`, is compiler-only/non-emitting at `90/94`, and has blank R3 rather than handwritten switch data.
- C01-C20, R0-R12, six registered children UID0004R3-UID0004R8, Event/interface and UserPane layout corrections, target-selection linkage corrections, class/file/parent/vtable synchronization, manual coverage handoff, validators, and generated readback are complete. The shared pass rebased on the supervisor-executed B001/B004/B005 union and preserved current B002-owned UID0004R9 without editing it.
- Confidence: very strong for boundary, ABI, virtual slot, return behavior, switch topology, packet bytes, class/file ownership, and compiler-data disposition; strong for descriptive helper/field spellings whose behavior and type are proved but whose original symbols are absent.
- Callback state: B003 ordinary implementation and scoped/waited validation are complete; no B003 implementation item or lease remains. B003 manually edited no generated/manual-coverage/tracker/audit/supervisor/validator-state/lifecycle/archive file and ran no report execution, probe, count, move, archive, or other lifecycle command. Report validation/execution/count/path/movement/archive state remains external supervisor/validator-owned and is not asserted or directed by this artifact.

## Supporting Research

- Fresh mandatory MCP evidence was collected from database `01f84d61` after `idb_list`; `server_health` returned `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and a 2,067-entry strings cache. A final bounded read returned the target prologue `55 8b ec 6a ff 68 1c a9 60 00 64 a1 00 00 00 00`.
- The supervisor-reported busy timeout is not used as evidence. The retained pass completed 63 successful bounded IDB-backed requests across function lookup, bytes, xrefs, decompilation, helper lookup, and health/list checks. One malformed local `get_bytes` request omitted the schema-required `regions` field; it was a client argument error, was immediately corrected, and is not treated as an MCP or IDB failure.
- Exact historical-report search terms: `0003V9`, `0x005a5bd0`, `5A5BD0`, `UserPaneHandleKeyEvent`, `UserPaneOnKeyEvent`, `OnKeyEvent`, `HandleKeyOrTextEvent`, `PaneKeyEvent`, `0003VA`, `0x005a7422`, `0x005acf10`, `5ACF10`, `UserPane`, and `TargetSelectionInputPanes`.
- `executed-b-agent-research/**`: B004 UID0001KL is historical split/support evidence and explicitly deferred the direct body; it is not a substitute for this report. B001 UID0003U6 supports the complete UserPane receiver and movement helper. B014 UID0003UD supports the action-call boundary. B009 UID0002A9 supports the two mode bytes but its `static` linkage is contradicted by this target's cross-TU writes. UID0002A2 similarly proves the active SelectObject singleton slot but its first `static` declaration is contradicted by the target read. B009 UID0002RX/UID0001MC support say/chat helpers. B003 UID0003ZQ supports QuitPromptLauncher. B003 UID0004BT and UID0004FS support MixItemDialog and BulletinSession construction. B001 UID0003VB is the successor server-event sibling only. B005 UID0001LD/UID0001LE support target-selection behavior and helper semantics.
- `tools/leaser/Agents/**`: no active matching UID0003V9 report or goal was found. B004 UID0003UM and B001 UID0003U8 are current broad UserPane sibling leads, not target-body substitutes. Goal/audit/notes matches were administrative and were not used as technical proof.
- `source-3/project-documentation/archived/**`: the exact terms produced no relevant target-specific source-quality report.
- `tools/leaser/Agents/Older-Research/**`: the exact terms produced no relevant target-specific report.
- `tools/leaser/Agents/SpecialReports/**`: the exact terms produced no relevant target-specific report.
- Wave2/Wave3 traces were found only as stale/generated leads. They were ignored unless independently confirmed by current IDA and current ordinary docs.

### Shared UserPane Collision Inventory

| Workstream | Evidence-time status and artifact | Shared destination/generated/manual impact | Mandatory no-loss disposition |
| --- | --- | --- | --- |
| B001 UID0003U8 | Supervisor-executed artifact `executed-b-agent-research/B001/0003U8-UserPaneStartDirectionalAnimation-source-quality.md`, current read-only SHA256 `4937108A56AF541AFB4FCFF385265D02571B64ADC40FF715996E26CB73F1085D`. | Accepted class/file/UID0001KM facts are already on disk and affect `UserPane.cpp` plus the UID0000FQ/UID0000P1 manual union. | Preserve `StartDirectionalAnimation(char direction)`, signed `short frameDuration`, MonsterObject image-table/group/frame selection, signed non-monster scaled-delay arithmetic, event-20 scheduling, branch-specific ordering, and branch-local MapPane bounds refresh. |
| B004 UID0003UM | Supervisor-executed artifact `executed-b-agent-research/B004/0003UM-UserPaneParseInventorySlotUpdatePacket-source-quality.md`, current read-only SHA256 `3ED435EE6680006F2ED713E568E9AE4630A1E18F07E836A3BE8C792E117C182A`. | Accepted class/file/UID0001KM facts are already on disk and affect `UserPane.cpp` plus the UID0000FQ/UID0000P1 manual union. | Preserve opcode `0x0f`, signed one-based slot validation, three ACP conversions, exact 508-byte record and write order, `itemMetaKey`, `ownerName`, `currentDurability`, `protectionCount`, active-slot bound, invalid-slot full consumption, and always-false return. |
| B005 UID0003UL | Supervisor-executed artifact `executed-b-agent-research/B005/0003UL-UserPaneParsePlayerSettingsPacket-source-quality.md`, SHA256 `270F5C30DD094FB985C6848DF813DBC47B682CF0F31EEE9A726EB98C6220021F`. | Its settled class/file/UID0001KM/UID0003VB facts and generated source were the callback baseline. | Preserved opcode `0x08`, offsets 2/31, state indices 0/2/3/4/5/6, pending-reply index 3 versus direction-delay index 4, blindness invalidation, movement/TryStepForward, config/sound/active-panel order, and all B001/B004 union facts. |
| B004 UID0003UN | Supervisor-executed artifact `executed-b-agent-research/B004/0003UN-UserPaneHandleServerEntryPacket-source-quality.md`, SHA256 `CE1F38082E7EF69EBD35C6D163F8FF1534ECA45EAD6B70EC9A002B410F7FA8A6`; manual coverage validators 12898-12900 and execute command 12901 are external supervisor history. | Its B004-first UID0000P1/UID0001KM/UID0003VB union and read-only UID0000FQ baseline were reread before B003 shared edits. | Preserved exact opcode `0x05` server-entry branches, SelfLook/NewSystem refreshes, packet-sender/overlay/object/status/map/block-list behavior, helper routes, padding, negatives, and current support links. |
| B002 UID0003UW / UID0004R9 | Gate-1-accepted B002 report `tools/leaser/Agents/Agent-B002/research/0003UW-UserPaneParseLinkedObjectsPacket-source-quality.md`, SHA256 `FA88588B48F3C0CAE7753E8B4171E64E083E5370BDBE0D8EBE9747CE0EFC1132`; current disjoint [UID:0004R9] is registered at `0x005adbe0-0x005adc15`. | UID0004R9 is present once in generated UserPane output; B002 retains ownership of its broader parser/class/file callback lane. | Preserved UID0004R9 and current validator-managed UID0003UW links without leasing, editing, validating, or absorbing B002's owned target/helper. B003 did not pre-implement B002's broader shared declaration changes. |
| B003 UID0003V9 | This callback applied R0/R2, UID0000P1/UID0001KM prose, six registered children, generated checks, and complete UID0000FQ/UID0000P1 manual replacement text. | Shared edits were made only after B004/B005 execution and the B004-first lane release; each destination was reread under one short lease. | Applied only B003's dispatcher/helper/layout/linkage/compiler-exclusion/score delta on the settled union, preserving all concurrent and unrelated content. |

Historical evidence-time shared baselines were UID0000FQ `A0364680...B950B6B`, UID0000P1 `B1CDF3C9...BD957`, and UID0001KM `F866B1B8...B0629`. Callback-time B004-first baselines were UID0000FQ `E4AA6D4F...05291`, UID0000P1 `8DB6D7C1...E4D`, UID0001KM `1E53B83F...7396A`, and UID0003VB `CBA23543...13D0`. Current post-B003 hashes are recorded under Changed Files; historical hashes are retained only as no-loss rebase evidence.

The callback followed the required order: leases were checked; executed B001/B004/B005 and accepted B002/B003 artifacts were reread; B004's first lane and B005's settled state were used as the baseline; each shared destination was reread under its one-file lease; the complete unrelated/current union was preserved; R0/R2 were checked against their destinations; each page was scoped-validated and released; and final waited command 12921 verified the generated union. The temporary MCP outage caused an immediate pause; the held but unedited UID0001KL lease was released without validation, and work resumed only after fresh `idb_list`, healthy `server_health`, and a successful bounded read on session `4ef1c645`.

## Target

- Target UID: `0003V9`.
- Implemented target path: `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md`.
- Historical source queue/report row before this callback: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`; tracker/count state after the callback is external and is not asserted by this artifact.
- Implemented classification: direct source-quality empty-emitter repair with complete human C++ and preserved UserPane owner/emitter route.
- Implemented scores and parent state: target `92/94`, `CANONICAL_OWNER:0000FQ`, `EMITTER_UIDS:0000FQ`, `RECONSTRUCTABLE:TRUE`, blank optional position, exact R1, `Nested:0`; broad parent [UID0001KL] is `91/93`, non-synthetic, and remains a source-family index.

## Current Target State

- The historical pre-callback metadata identified the exact range and UserPane route but used the unresolved title `HandleKeyEvent`, repeated `OnKeyEvent`/`PaneKeyEvent` alternatives, and left the formal C++ blank. The validator-preserving rename and R1 application removed those current defects while retaining UID0003V9 and the range.
- Owner/emitter/reconstructable state remains [UID0000FQ] UserPane emitted through [UID0000P1] `NexusTK/ui/panels/UserPane.cpp`; scoped validation and final waited command 12921 prove that route.
- All identified blockers are resolved and documented: receiver adjustment, Event type/layout, return type, method name, primary switch arms, packet lengths/bytes, helper call roles, relevant class members, attached table, retained helper bodies, target-selection linkage, and source placement.
- Stale `PaneKeyEvent`/`OnKeyEvent` and unresolved-field/helper conclusions are retained only as historical provenance. Current class/file/target pages use `HandleKeyOrTextEvent(Event *)`, complete source, externally linked mode flags, and the externally linked active SelectObject singleton pointer.
- Related target/support docs checked: UID0001KL, UID0001KM, UID0000FQ, UID0000P1, UID0002YU, UID0003VA, UID0003U6, UID0003UD, UID0003UB, UID0003V0, UID0001KP, UID0002A9, UID0002A2, UID0000OH, Event/EventHandler, MapPane, GeneralPurposePanel, TimerMgr, packet sender, option strings, input panes, singleton globals, generated UserPane output, and manual coverage rows.
- Artifact boundary: this path is the historical B003 research/implementation-callback artifact location before any external supervisor lifecycle handling. B003 implementation and scoped/waited validation are complete; later validation, execution, count, path, movement, archival, and manual coverage state are external supervisor/validator-owned and are not asserted or directed here.

## Executive Recommendation

- Implemented source name: `HandleKeyOrTextEvent(Event *event)`. The exact EventHandler declaration and the target's `AL` handled result supersede provisional `OnKeyEvent(const PaneKeyEvent *)` wording.
- Implemented whole-range disposition: its four successor table runs remain compiler lowering on non-emitting UID0003VA; no source-authored executable child was split from the target range.
- Implemented scores: target `92/94`, class `93/94`, file `92/93`, parent `91/93`, switch table `90/94`, and exact vtable data `90/94` with compiler-only no-code metadata.
- Registered exact source helper children: UID0004R7 and UID0004R8 for the two UserPane slot-range methods, UID0004R3 for the UserPane.cpp opcode-7 sender, and UID0004R4/UID0004R5/UID0004R6 for the three TargetSelectionInputPanes.cpp helpers.
- Implemented external-linkage `g_selectObjectTargetModeActive` and `g_targetObjectTargetModeActive` definitions because UserPane.cpp directly writes both. Behavior is unchanged; only the impossible historical source linkage was corrected.
- No blocker remains for exact R1/R2/R4-R7/R9-R12 source. UID0003VA and UID0002YU remain non-source compiler artifacts with blank R3/R8 bodies.
- Shared-destination ordering was satisfied as a no-loss precondition: R0/R2 and UserPane class/file/aggregate changes were rebased on the settled B004-first/B005/B001 union, while current B002-owned UID0004R9 was preserved read-only.

## Supervisor Active Recheck

- This work responded to the UID0003V9 direct source-quality assignment and the supervisor instruction to retry bounded MCP calls after a transient busy period.
- Split repair was required only for associated source helpers that currently lack exact pages. The target is not itself a split container.
- Every source-bearing child triggered by this direct pass has its implemented path, validator-issued UID, exact range, owner/emitter, score, metadata disposition, and formal destination. Compiler table/vtable artifacts retain exact no-code proof.
- Callback ordering was completed: B004 UID0003UN and B005 UID0003UL were settled, accepted/executed artifacts and current destinations were reread, shared leases were clear, and B003 rebased R0/R2 plus UID0000FQ/UID0000P1/UID0001KL/UID0001KM without loss. B002's disjoint UID0004R9 remains preserved and unedited.

## Inference Research Guidance Check

- `by-structure.md` and the workflow evidence ladder were applied: exact bytes/function bounds and vtable/data xrefs first, accepted interface/type docs second, behavior-derived names third, and old generated/report labels only as leads.
- Existing assumptions treated as uncertain were `HandleKeyEvent`, `OnKeyEvent`, `PaneKeyEvent`, the complete-receiver offset basis, broad raw field labels, helper ownership, target-selection `static` linkage, and the blank/no-code conclusion.
- IDA facts are stated as addresses, bytes, xrefs, control flow, field displacements, packet stores, and calls. Documentation evidence supplies accepted project types and names. Inferences are explicitly capped where original symbols are absent.
- Wave2/Wave3 names and generated projections were not accepted without fresh confirmation.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Basis / classification |
| --- | --- | --- |
| Method name | `UserPane::HandleKeyOrTextEvent` | Original project interface proof from EventHandler plus exact virtual ABI; `OnKeyEvent` and `HandleKeyEvent` are rejected stale aliases. |
| Argument type | mutable `Event *` | Accepted Event/EventHandler declarations and reads at Event `+0x4/+0x8/+0x10a/+0x10c`; `PaneKeyEvent` is rejected. |
| Receiver | complete UserPane | Entry receives EventHandler facet at complete object `+0xa0`; decompiler `this-0xa0` calls are normalization, not a different owner. |
| Return | `bool` | Every route produces handled/unhandled in `AL`; no status enum or `char` source contract is needed. |
| Switch data | compiler-only UID0003VA | 81 dword targets all return into UID0003V9; selector maps and padding have no independent source declaration. |
| Opcode-7 helper | `SendOpcode7Command(unsigned char)` | Exact two target calls and complete `{7,command}` length-2 body; descriptive spelling, source behavior proved. |
| Target-selection helpers | three file-level TargetSelectionInputPanes functions | Complete bodies, target calls, shared map-selection state, and surrounding target-pane family establish source placement; source spellings are descriptive. |
| Target-selection global linkage | external `g_` mode definitions and active SelectObject pointer | Direct mode writes and the active-pointer read occur in UserPane.cpp while definitions/constructors live in TargetSelectionInputPanes.cpp. Current `static` declarations cannot represent the observed cross-TU source. The unused-by-UserPane TargetObject pointer remains static. |
| Class fields | split exact known members | Complete-object displacement normalization proves `m_currentSayMode`, two debounce ticks, collection-panel sound flag, input lock, action mode, map pointer, spell readiness, and player-setting state. Unknown surrounding bytes remain arrays. |
| Packets | local byte arrays with exact send lengths | Store order, opcodes, payload bytes, local terminators, and QueueAndSendPacket lengths are direct IDA facts. No speculative packet classes were introduced. |
| Inline constructors | ordinary `new Type(...)` expressions | Allocation plus constructor/vtable sequences are source-level `new`; EH/vptr lowering is omitted. Singleton guards are retained only where the binary has them. |
| Source placement | `UserPane.cpp` target/opcode helper; `TargetSelectionInputPanes.cpp` selection helpers/flags | File routes follow class ownership, direct global families, and current source tree; callee class files do not own the dispatcher. |

Exact receiver/type normalization used by R1/R2:

| Source object / offset | Type and source-facing role | Direct use in target |
| --- | --- | --- |
| Event `+0x04` | event type dword/enum | rejects type `10` text input |
| Event `+0x08` | raw key byte in key payload | input to `TranslateEventKey` |
| Event `+0x10a` | modifier byte | control/alternate/extended modifier partition |
| Event `+0x10c` | `unsigned int m_messageTime` | saved after opcode `0x2d` send |
| inherited UserPane `+0x1d1` | `bool m_nameVisible` | restricts accepted keys and Escape/V behavior |
| UserPane `+0x3eb4` | `int m_currentSayMode` | exact dword stores `0/1/2`; byte modeling rejected |
| UserPane `+0x3eba` | `bool m_collectionPanelSoundEnabled` | conditional collection-panel sound |
| UserPane `+0x1340c9` | collection metadata-loaded byte | panel-versus-opcode-39 branch |
| UserPane `+0x1340f8` | `MapPane *m_mapPane` | map input/selection/movement state |
| UserPane `+0x1340fc` | `m_playerSettingsState[0]` | uppercase-P request gate |
| UserPane `+0x13ead4` | `bool m_spellCommandSlotsReady` | uppercase-Z gate |
| UserPane `+0x13eaf8` | `unsigned int m_lastActionTick` | exact 100-tick space-key condition |
| UserPane `+0x13eafc` | `unsigned int m_lastMapCommandTick` | lowercase-o 1000-tick debounce |
| UserPane `+0x13eb00` | `unsigned int m_lastGroundItemCommandTick` | comma 1000-tick debounce |
| UserPane `+0x13eb1d` | `bool m_inputLocked` | first gate returns handled `true` |
| UserPane `+0x13eb3c` | `unsigned char m_actionMode` | name-visible arrows and space action/selector decision |
| MapPane `+0x3f0` | waiting-for-local-player-status bool | second gate returns `false` |
| MapPane `+0x108/+0x10c/+0x110` | selected-object active/pane/direction | target navigation/cancel state |

Config field resolutions used by R1 are exact displacement facts: `+0x28de59 m_sayWithEnter`, `+0x28de5d m_legacyOption14Flag` (descriptive spelling), `+0x28de63 m_tabVSwap`, `+0x28de64 m_showDamage`, `+0x28de6d m_f1Swap`, `+0x28de75 m_mapMovementStatusOption`, `+0x28de8e m_clickMoveEnabled`, `+0x28de8f m_clickLookEnabled`, `+0x28de94..+0x28de9b m_powerDialogThresholdDefaults[4]`, and `+0x291908 m_musicSourceMode`. The source types are bool bytes except the four little-endian threshold words and music mode field established by their existing support docs.

The source-visible say-mode values are `0` normal, `1` shout, `2` whisper, `3` group, and `4` clan. Only `0/1/2` are written in this target. The target's dword stores prove an `int`/enum-sized member at `+0x3eb4`; R2 preserves natural adjacent bytes and total class size rather than forcing a byte field.

- Rejected `LivingObjectPane::HandleKeyOrTextEvent`: inherited state/calls do not override the UserPane vtable cell, complete receiver, or UserPane-only fields.
- Rejected one child per switch or key: source switches are one cohesive virtual; the binary has no separately callable in-range bodies.
- Rejected hand-authored jump tables/vtable arrays: both are compiler-generated consequences of the declaration/body.
- Rejected opaque packet-builder types and decompiler labels: local arrays preserve exact source-visible writes without inventing a protocol abstraction.
- Rejected leaving the class formal unchanged: an `OnKeyEvent(PaneKeyEvent const *)` declaration cannot naturally emit the accepted target signature.
- Remaining uncertainty is lexical only for several private field/helper names and one legacy config flag at `+0x28de5d`; behavior, widths, ownership, access requirements, and emitted source shape are resolved. These caps explain scores below 95 rather than block C++.

## Evidence Standards Used

- Evidence types: fresh MCP health/list, function lookup, bounded bytes, complete Hex-Rays body, disassembly/CFG, xrefs, vtable pointer cell, call inventory, data/table target scan, adjacent padding, current by-* metadata/formals, accepted Event/interface/layout docs, prior executed reports, read-only generated output, and manual coverage rows.
- Strength: exact range/hash, sole vtable route, complete control flow, exact packet stores, and accepted type contracts independently converge. Descriptive private names are isolated from direct facts and confidence-capped.
- Binary context: x86 MSVC `__thiscall` and EventHandler secondary-facet lowering explain the adjusted receiver and compiler EH/cookie blocks. Those artifacts are deliberately excluded from human C++.
- Tool limitation: no original debug symbols/source were available. This limits lexical certainty, not behavior or reconstructability.

## Evidence Checked

- IDA MCP/manual checks: live IDB `01f84d61`; server health; target/helper lookups; 13 bounded target reads and three bounded table reads; complete target and helper decompiles; function/xref/callee inventories; raw target/table hashes; vtable cell; predecessor/successor padding; no exclusive-end function.
- Current docs: target, switch child, UserPane parent/class/file/vtable, Event/EventHandler, MapPane, target-selection classes/file/globals, packet sender, TimerMgr, option strings, input/dialog constructors, singleton globals, and current generated UserPane.cpp.
- Historical searches: exact terms and roots listed under Supporting Research, with each relevant match classified there.
- Shared-collision checks: accepted B002 UID0003UW/current UID0004R9, executed B005 UID0003UL, executed B004 UID0003UN/UID0003UM, executed B001 UID0003U8, current UID0000FQ/UID0000P1/UID0001KM, generated UserPane output, and current manual class/file rows were read and classified in the collision inventory. Gate-1-failed B005 UID0003UB was excluded from the settled union.
- Negative checks: no direct call to the virtual body; no independent in-range function; no table target outside the method; no source reason for raw tables/vptr/RTTI/cookie/EH; no plausible LivingObjectPane, Event, packet, dialog, MapPane, or generic input file ownership.
- Failed/unavailable checks: none after retry. The transient busy timeout and malformed local `get_bytes` argument are excluded from evidence; the corrected bounded read succeeded.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | IDB `01f84d61` was healthy during evidence collection and all retained bounded calls succeeded. | 99 | idb_list, server_health, bounded bytes/decompiles | UID0003V9 Evidence/Changes; report IDA MCP Facts | incorporate | applied |
| C02 | Target is exact `[0x005a5bd0,0x005a7422)`, size `0x1852`/6226, SHA256 `6692BF...091`. | 99 | lookup, 13 bounded reads, hash | UID0003V9 range/evidence | incorporate | applied |
| C03 | Source signature is `bool UserPane::HandleKeyOrTextEvent(Event *event)`. | 98 | EventHandler interface, Event layout, vtable ABI | UID0003V9 title/formal; UID0000FQ declaration | reject-stale | applied |
| C04 | The only code route is UserPane vtable cell `0x0062ef98`; there are no direct callers. | 99 | xrefs/pointer scan | UID0003V9; UID0002YU | incorporate | applied |
| C05 | UID0003VA is exact compiler switch/selector data with 81 in-target dword entries and no source body. | 99 | table bytes/targets | UID0003VA R3 | incorporate | applied |
| C06 | Entry gates and every return route implement a handled/unhandled bool contract. | 97 | complete decompile/CFG | UID0003V9 behavior/R1 | incorporate | applied |
| C07 | Control and alternate modifier dispatch, target-selection behavior, attacks, hotkeys, and packets are exact. | 96 | switch CFG/calls/stores | UID0003V9 behavior/R1 | incorporate | applied |
| C08 | Unmodified key dispatch, pane construction, option toggles, panels, movement, and function keys are exact. | 96 | switch CFG/calls/stores | UID0003V9 behavior/R1 | incorporate | applied |
| C09 | All reported packet opcodes, payload bytes, terminators, and send lengths preserve machine order. | 98 | instruction-level packet stores/calls | UID0003V9 packet table/R1 | incorporate | applied |
| C10 | Allocation/vtable/EH sequences normalize to ordinary source `new` expressions and helper calls. | 94 | constructor calls, current class docs | UID0003V9 source-shape evidence/R1 | historicalize | applied |
| C11 | UserPane field split resolves say mode, two debounce ticks, collection sound, input lock, and exact size. | 96 | normalized displacements, current 0x13eb84 layout | UID0000FQ R2 | incorporate | applied |
| C12 | Two slot-range methods and the opcode-7 sender are exact UserPane source and are registered as UID0004R3/UID0004R7/UID0004R8. | 96 | complete bodies, hashes, target calls, class fields | children R4/R10/R11; UID0001KM/UID0000FQ/UID0000P1 | incorporate | applied |
| C13 | Three exact target-selection helpers belong to TargetSelectionInputPanes.cpp; mode flags and active SelectObject pointer require external linkage. | 94 | full helper bodies, global accesses, cross-TU target writes/read | UID0004R4/UID0004R5/UID0004R6 R5-R7; UID0002A9 R9; UID0002A2 R12; UID0000OH | reject-invalid | applied |
| C14 | UID0000FQ/UID0000P1 remain target owner/emitter/source route. | 99 | vtable, receiver, class fields, source tree | target/class/file | already-present | already-present |
| C15 | Target stays whole; predecessor nine-byte pad and successor table/pad disposition are exact. | 99 | bytes/functions/table scan | UID0003V9/UID0003VA/UID0001KL | incorporate | applied |
| C16 | Full UserPane declaration R2 closes every target compile-time type/member/access blocker and keeps class closed before children. | 94 | accepted class formal plus bounded corrections | UID0000FQ R2 | incorporate | applied |
| C17 | UID0002YU vtable and UID0003VA tables are compiler-generated, non-reconstructable as handwritten source, blank formal. | 99 | RTTI/vtable/table origin | UID0002YU R8; UID0003VA R3 | reject-invalid | applied |
| C18 | Score/metadata changes reflect exhaustive blocker closure without claiming original private spellings. | 94 | complete evidence and residual caps | all recommended destinations | incorporate | applied |
| C19 | Generated UserPane.cpp emits one R1 and its helpers, no old declaration/marker, and no raw compiler arrays. | 98 | read-only command-12769 baseline plus emitter model | UID0000P1/generated verification | incorporate | applied |
| C20 | Exact manual supervisor-owned coverage replacements/additions are supplied for every B003-changed row. | 99 | current coverage rows read-only | three manual coverage files | incorporate | applied |

### C01-C20 Callback Implementation Proof

| Claim | Implementation proof |
| --- | --- |
| C01 | The evidence-time `01f84d61` health/request facts remain historical evidence. After the callback outage, fresh `idb_list` selected `4ef1c645`; `server_health` was `ok` with analysis/Hex-Rays/strings ready, and bounded `get_bytes(0x005a3ae0,7)` returned `55 8b ec 81 ec 34 02` before work resumed. |
| C02 | UID0003V9 retained `[0x005a5bd0,0x005a7422)`, explicit `0x1852`/6226 size, full hash, boundary evidence, and range metadata; scoped rename/body validation command `000000012861` exited 0/ok 1. |
| C03 | Validator-preserving UID0003V9 rename installed R1, and UID0000FQ R2 now declares `bool HandleKeyOrTextEvent(Event *event);`; commands `12861`, `12913`, `12919`, and waited `12921` prove the target/class/generated route with no stale `OnKeyEvent` or `PaneKeyEvent`. |
| C04 | UID0003V9 and compiler-only UID0002YU retain the sole vtable cell `0x0062ef98`, no-direct-caller evidence, and exact route; vtable command `12865` exited 0/ok 1. |
| C05 | Validator-preserving UID0003VA rename retained all 81 entries, boundaries, selector runs, compiler-only state, and blank R3; command `12863` exited 0/ok 1. |
| C06 | UID0003V9 R1 and behavior tables preserve every handled/unhandled return path; command `12861` validated the page and command `12921` emitted one definition. |
| C07 | UID0003V9 R1 retains exact control/alternate dispatch, target selection, attacks, hotkeys, and packet calls; target command `12861` and generated count checks after `12921` prove incorporation. |
| C08 | UID0003V9 R1 retains exact unmodified-key, pane, option, movement, and function-key behavior; target command `12861` and waited generated command `12921` prove incorporation. |
| C09 | UID0003V9 packet evidence/R1 retains every accepted opcode, store, terminator, and send length; command `12861` exited 0/ok 1. |
| C10 | UID0003V9 source-shape prose and R1 historicalize decompiler allocation/vptr/EH lowering into ordinary source expressions without emitting compiler machinery; command `12861` and no-compiler-array check under `12921` prove the disposition. |
| C11 | UID0000FQ R2 contains the exact say-mode, debounce, collection-sound, input-lock, and `0x13eb84` layout union on top of B001/B004/B005/B004-UN content; exact-formal validator command `12913` exited 0/ok 1. |
| C12 | Validator registration issued UID0004R3/UID0004R7/UID0004R8; commands `12870`, `12876`, and `12877` each exited 0/ok 1. UID0001KL/UID0001KM/UID0000FQ/UID0000P1 links were validated by `12905`, `12907`, `12913`, and `12903`. |
| C13 | Validator registration issued UID0004R4/UID0004R5/UID0004R6; commands `12872`-`12874` exited 0/ok 1. UID0002A9, UID0002A2, and UID0000OH were validated by `12866`, `12869`, and `12881`; waited `12921` emitted R5-R7/R9/R12 once with corrected linkage. |
| C14 | Existing owner/emitter route UID0000FQ/UID0000P1 was preserved through target `12861`, class `12913`/`12919`, file `12903`/`12920`, and final generated command `12921`. |
| C15 | UID0003V9, UID0003VA, and UID0001KL retain the whole target plus exact predecessor/successor table/padding dispositions; commands `12861`, `12863`, and `12905` exited 0/ok 1. |
| C16 | UID0000FQ R2 is byte-for-byte equal to the accepted report block, closes the class before `[[CHILDREN]]`, and was scoped-validated by `12913`/`12919`; command `12921` places all qualified definitions after the class close. |
| C17 | UID0003VA R3 and UID0002YU R8 remain blank, non-reconstructable compiler artifacts; commands `12863`/`12865` passed and command `12921` emitted no handwritten switch/vtable/RTTI arrays. |
| C18 | All accepted scores/metadata are present on the 16 changed ordinary destinations; the per-file command table and hashes below prove each applied value while retaining lexical confidence caps. |
| C19 | Final waited command `000000012921` at `2026-07-15T06:42:50-04:00` produced UserPane.cpp SHA256 `FE250BD4A142E035D768DAD8741658E28171134B46F5A1C93B1A7FE11C3A8044` and TargetSelectionInputPanes.cpp SHA256 `6D61F670C087ED62D1854BFE11F1FEE45CA1A5F6535D3778E25DA5B16619CF3B`; exact generated assertions are recorded below. |
| C20 | The Exact Manual Supervisor-Owned Coverage Or Tracker Text section retains destination-specific replacement/addition text for every B003-changed row and the complete B001/B004/B005/B004-UN union. B003 did not edit coverage; its later application/state is external. |

## Positive Evidence Summary

- Exact function/range/hash, sole vtable cell, complete decompile, full switch target map, accepted EventHandler interface, and normalized receiver all independently support one UserPane virtual.
- Every table target returns into this body; every ordinary call leaves the body for an established subsystem dependency. The body reads UserPane fields far beyond the LivingObjectPane base and uses UserPane-only globals/children.
- Packet writes and constructor calls cover all source-C++ blockers without requiring guessed raw layouts. Four repeated or independently complete helper bodies have exact source destinations.
- The strongest inference chain is: EventHandler slot -> complete UserPane facet -> exact Event reads/bool return -> accepted class/file route -> source switch body -> compiler-generated table/vtable. No competing owner explains all facts.

## IDA MCP Facts

- Function: `sub_5A5BD0`, exact size `0x1852`, `[0x005a5bd0,0x005a7422)`, 1,670 instructions and 248 Hex-Rays/disassembly blocks including compiler EH, 60 callees, 36,238-character/993-line decompile.
- Target SHA256: `6692BF892563581EFE52C132D30B07F01F63AC0426E567BE359951AC77923091`.
- Table: `[0x005a7422,0x005a76c0)`, `0x29e`/670 bytes, SHA256 `63A34744173877F1990153D4D8FBB1BA436D20E4F9DDD0571F8BA475E55BC826`.
- Table layout: `66 90`; 5 dwords at `0x5a7424`; selector bytes; 10 dwords at `0x5a7484`; selector bytes; 62 dwords at `0x5a7528`; selector bytes; 4 dwords at `0x5a76ac`; four `cc` bytes at `0x5a76bc`. All 81 targets fall inside UID0003V9 (`0x5a5cc2..0x5a73a5`).
- Padding: predecessor `[0x005a5bc7,0x005a5bd0)` is nine `cc`; no function begins at exclusive end; successor function begins at `0x005a76c0` after table tail pad.
- Xrefs: one data xref at UserPane vtable cell `0x0062ef98`; zero ordinary direct calls.
- Helper `0x005acf10-0x005acf5f`: size `0x4f`/79, SHA256 `6F35B65887B00D535D7D52A2ECF9A728220117164BC57BCCDC8C8E3ED1E035E`, two target calls, exact `{7,command}` length-2 send, `cc` at both adjacent one-byte boundaries.
- Target-selection helpers: `0x005ad450-0x005ad4ff` size `0xaf`; `0x005ad500-0x005ad660` size `0x160`; `0x005ad660-0x005ad719` size `0xb9`; all decompiled completely under the live session.
- Negative IDA facts: no debug source symbols for the target/private helpers; no separate function inside target; no out-of-target table entry; no evidence for source-level vtable/table arrays or explicit EH/cookie code.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005a5bd0-0x005a7422` | UID0003V9 `...UserPaneHandleKeyOrTextEvent.md` | complete UserPane virtual | true | UID0000FQ | `92/94` | rename/update |
| `0x005a7422-0x005a76c0` | UID0003VA `...UserPaneHandleKeyOrTextEventSwitchTables.md` | compiler tables/selectors/pad | false | none | `90/94` | rename/update |
| `0x005acf10-0x005acf5f` | UID0004R3 `...UserPaneSendOpcode7Command.md` | UserPane.cpp file helper | true | UID0000P1 | `90/93` | implemented/validated `12870` |
| `0x005a40d0-0x005a430c` | UID0004R7 `...UserPaneBuildInventorySlotRangeText.md` | UserPane member | true | UID0000FQ | `90/93` | implemented/validated `12876` |
| `0x005a4310-0x005a4523` | UID0004R8 `...UserPaneBuildSpellSlotRangeText.md` | UserPane member | true | UID0000FQ | `90/93` | implemented/validated `12877` |
| `0x005ad450-0x005ad4ff` | UID0004R4 `...ToggleTargetSelectionPane.md` | TargetSelectionInputPanes file helper | true | UID0000OH | `90/93` | implemented/validated `12872` |
| `0x005ad500-0x005ad660` | UID0004R5 `...NavigateTargetSelection.md` | TargetSelectionInputPanes file helper | true | UID0000OH | `90/93` | implemented/validated `12873` |
| `0x005ad660-0x005ad719` | UID0004R6 `...ReverseTargetSelectionDirection.md` | TargetSelectionInputPanes file helper | true | UID0000OH | `90/93` | implemented/validated `12874` |
| UserPane declaration | UID0000FQ `by-class/UserPane.md` | class/layout/declarations | true | UID0000P1 | `93/94` | update |
| UserPane source | UID0000P1 `by-file/UserPane.md` | source root/inventory | true | current route | `92/93` | update |
| UserPane broad range | UID0001KL `...UserPane.md` | non-synthetic source-family index | false | UID0000P1 | `91/93` | update prose/score |
| UserPane vtable | UID0002YU `...UserPaneVtableData.md` | compiler vtable/RTTI data | false | UID0000FQ semantic | `90/94` | reclassify/update |
| mode flags | UID0002A9 `...TargetSelectionModeFlags.md` | two live external-linkage bools plus no-source bytes | true | UID0000OH | `91/93` | linkage/formal update |
| keyboard-pane singletons | UID0002A2 `...TargetSelectionKeyboardPaneSingletonSlots.md` | external SelectObject pointer plus static TargetObject pointer | true | UID0000OH | `90/92` | bounded linkage/formal update |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062ef98` | dword pointer to `0x005a5bd0` | sole target xref; EventHandler virtual slot on UserPane |
| `0x005a5e2c`, `0x005a6413` | calls `0x005acf10` | compact opcode-7 helper with commands 3 and 1 |
| `0x005a5e9a..0x005a5eb9` | reads target mode and calls `0x005ad660` or `0x005ad500` | alternate target navigation decision |
| `0x005a5f56..0x005a5f75` | allocates/constructs SelectObjectWithKeyboardPane | space-key target pane path |
| `0x005a5f3a` | reads UID0002A2 first pointer at `0x0069bf60` | cross-TU active SelectObject singleton guard; first declaration cannot be static |
| `0x005a5f87` | calls UID0003UD `TryPerformAction` with complete receiver | action fallback; return ignored, target returns true |
| `0x005a6f6f`, `0x005a6f76` | clears `0x0069bed9/da` | proves UserPane cross-TU access to both target-mode flags |
| `0x005a6e95/b1/cd/e9` | calls UID0003U6 with directions `1/2/3/0` | arrow-key movement dispatch |
| `0x005a5e40..0x005a5e7c` | UID0003V0 attack helper actions `0/2/3/1` | alternate-arrow attack dispatch |
| `0x005a7424/7484/7528/76ac` | 81 table dwords | all target source switch lowering |
| 60 distinct callees | UserPane, packet, UI, map, target, sound, chat, and compiler support | dependency fanout, not alternate ownership |

## Documentation Evidence And IDA Status

- Supporting current docs establish Event/EventHandler ABI, UserPane complete size/fields, class/file route, target vtable cell, movement/action helpers, packet sender ABI, target-selection state, option strings, and dialog/input constructors.
- Stale/incomplete current docs are UID0003V9's unresolved name/type/no-C++ text, UID0003VA's old title, UID0000FQ's `PaneKeyEvent`/`OnKeyEvent` declaration and unsplit fields, UID0002YU's reconstructable/comment-emitter treatment, UID0002A9's impossible `static` linkage, and UID0002A2's impossible first-pointer `static` linkage.
- Read-only generated checkpoint: validator header command `000000012769`, refreshed `2026-07-15T03:30:25-04:00`; file timestamp `2026-07-15T03:30:32.2749110-04:00`; SHA256 `32763D8E3B3FBCA4F3DA631D8C2ECBA034F3D8227237F0DE77B7D05A288EE464`; 65,690 bytes. It contains stale `virtual bool OnKeyEvent(const PaneKeyEvent *event);` and one UID0003V9 Empty Emitter Marker. This is explicitly a research-time pre-callback observation, not an indefinite generated-state assertion.
- Historical pre-callback manual coverage omitted UID0003V9, UID0003VA, UID0002YU, and all six helpers; carried stale UID0002A9 `75%`, stale UID0002A2 `85%`, and lower parent/class/file rows. Exact supervisor-owned replacement/addition text is supplied below; this artifact does not assert its later application state.

## Ranked Ownership Analysis

### 1. UserPane / UserPane.cpp

- Evidence for: exact UserPane vtable cell, EventHandler facet normalization, UserPane-only fields, source-family neighbors, current class/file route, and complete local-player dispatch behavior.
- Evidence against: none material; some calls delegate into inherited LivingObjectPane or other modules.
- Decision: direct target owner UID0000FQ and emitter/source UID0000P1.

### 2. LivingObjectPane

- Evidence for: inheritance supplies action/movement fields and helper methods; several calls normalize to the complete/base receiver.
- Evidence against: no LivingObjectPane slot points here; body reads UserPane-only 0x13ebxx state and opens UserPane-specific UI; current target cell is in UserPane vtable.
- Decision: dependency/base class, rejected as owner.

### 3. Input/dialog/packet/MapPane families

- Evidence for: many constructed panes and callees; MapPane stores active target state; packet sender transmits command arrays.
- Evidence against: they are consumers/dependencies and do not own the caller virtual, receiver, or source order.
- Decision: reject all as target owner. Exact complete file helpers route separately to UserPane.cpp or TargetSelectionInputPanes.cpp.

### Proposed new file/grouping, if applicable

- No new file root. UID0004R3 belongs to existing UserPane.cpp. UID0004R4/UID0004R5/UID0004R6 belong to existing TargetSelectionInputPanes.cpp.
- Candidate related items included: exact helper bodies and the two mode-flag declarations needed by their call graph.
- Candidate related items rejected: selector-map/vtable arrays, dialog constructors, MapPane methods, packet sender, and Event translation.
- This is narrow exact-child registration inside two established source roots, not a new broad grouping.

## Source Placement

- Target and `SendOpcode7Command`: `NexusTK/ui/panels/UserPane.cpp` through UID0000P1.
- Target-selection helper definitions, mode flags, and active singleton pointer: existing TargetSelectionInputPanes.cpp through UID0000OH; declarations required by UserPane.cpp belong in the corresponding shared header/declaration surface.
- This placement matches virtual owner, neighboring UserPane methods, absolute-data producer/consumer families, and project source tree.
- Rejected placements: LivingObjectPane.cpp, MapPane.cpp, Event.cpp, Packet.cpp, generic InputPanes.cpp, dialog class files, and a new protocol file.
- Remaining uncertainty: exact original private helper spelling and whether declarations lived in a narrow header or a broader UI header. This does not affect definitions, ABI, owner, or formal body.

## Range / Split / Padding / Reclassification Analysis

- Target exact range is `[0x005a5bd0,0x005a7422)`, 6226 bytes. Keep it one source method.
- Predecessor `[0x005a5bc7,0x005a5bd0)` is nine-byte `cc` alignment and remains parent-only ignored padding.
- Successor UID0003VA remains exact `[0x005a7422,0x005a76c0)`: two-byte align, four target-table runs, interleaved selector maps, and terminal four-byte `cc` pad. Rename only; no source emission.
- UID0004R3 exact body `[0x005acf10,0x005acf5f)` is bounded by one-byte `cc` at `0x005acf0f` and `0x005acf5f`; it is a standalone file helper, not target child by containment.
- UID0004R7 exact body `[0x005a40d0,0x005a430c)` is `0x23c`/572 bytes, SHA256 `1B218CA010C92D8A38AE6E3BC4B4EB37F6FBC1D2DBB4C7FFA50FE31B446081D1`; UID0004R8 exact body `[0x005a4310,0x005a4523)` is `0x213`/531 bytes, SHA256 `A3458C0E5E503B4CD3EFFBACE35E0127CF0291B47538A0DC539C78FD5BF1169C`. The four-byte gap `[0x005a430c,0x005a4310)` and successor gap `[0x005a4523,0x005a4530)` remain parent-only alignment.
- UID0004R4/UID0004R5/UID0004R6 are adjacent complete helper functions with exact ends `0x005ad4ff`, `0x005ad660`, and `0x005ad719`. They are source siblings in TargetSelectionInputPanes.cpp, not subranges of UID0003V9.
- Parent UID0001KL remains a non-synthetic source-family inventory. Its relative `Nested:0` and target UID0003V9 `Nested:0` do not change.
- UID0002YU remains exact vtable data, `Nested:8` unchanged as the address-sorted relative delta; reclassify only reconstructable/emitter/formal disposition.

## Negative Evidence Summary

- No direct call does not mean dead code: the exact vtable cell is the expected route for an override.
- No target split is supported: table targets land in the one function, and no independent prologue/function object exists inside it.
- Nearby helper addresses do not transfer ownership: the opcode helper's only target calls place it in UserPane.cpp, while three target-selection helpers share TargetSelectionInputPanes state and classes.
- Existing generated `OnKeyEvent(PaneKeyEvent const *)` is output from stale documentation, not original source proof.
- Absolute mode-byte accesses disprove class fields; cross-TU access disproves `static` file linkage in the current formal.
- Raw vtable/table cells, explicit vptr stores, EH cleanup, security cookies, allocation failure branches produced by lowering, and direct base calls are not handwritten source.
- No exact original symbols were found for private helpers/fields, so descriptive names are confidence-capped rather than falsely presented as original proof.

## IDA Rename / Type / Comment Recommendations

- Validator-preserving path/title rename UID0003V9 to `UserPaneHandleKeyOrTextEvent` is complete; the docs use source type `bool __thiscall UserPane::HandleKeyOrTextEvent(Event *)`. No IDA mutation was requested or made.
- Validator-preserving path/title rename UID0003VA to `UserPaneHandleKeyOrTextEventSwitchTables` is complete.
- Source-facing helper names: `SendOpcode7Command`, `ToggleTargetSelectionPane`, `NavigateTargetSelection`, and `ReverseTargetSelectionDirection`; all are descriptive, behavior-complete names.
- Field names: `m_currentSayMode`, `m_collectionPanelSoundEnabled`, `m_lastMapCommandTick`, `m_lastGroundItemCommandTick`, `m_inputLocked`, `m_selectedObjectActive`, `m_selectedObjectPane`, and `m_selectedObjectDirection`; types/offsets are direct, exact original spellings are inferred.
- Preserve historical labels `sub_5A5BD0`, `HandleKeyEvent`, `OnKeyEvent`, `PaneKeyEvent`, `sub_5ACF10`, `sub_5AD450`, `sub_5AD500`, `sub_5AD660`, `byte_69BED9`, and `byte_69BEDA` in provenance only.
- IDA DB edits are not requested and were not made.

## Formal Destination Overview

- Implemented source C++ destinations are UID0003V9, UID0000FQ, UID0004R3/UID0004R4/UID0004R5/UID0004R6/UID0004R7/UID0004R8, UID0002A9, and UID0002A2. UID0001KL retains its exact broad non-synthetic marker. UID0003VA and UID0002YU retain blank managed bodies under exact compiler-generated no-code proof.
- The R0-R12 blocks in the exact `First-Draft C++ Recommendation` section are destination text, not illustrative snippets. Each block includes the literal managed lines required at its destination.
- Behavior preservation: R1 retains every entry gate, modifier partition, key route, packet store/length, constructor guard, debounce comparison, return value, target-selection state transition, panel/sound action, option string, and movement mapping. It omits only compiler lowering.
- Source-era shape: ordinary switches, stack byte arrays, direct singleton/member calls, and `new` expressions match the accepted mid-2000s project style. No lambdas, modern containers, synthetic packet classes, raw addresses, IDA labels, vptr stores, explicit base teardown, EH/cookie code, or handwritten compiler tables appear.
- Inferred names are the source-facing names justified above; exact private lexical spellings remain the stated confidence cap.
- Shared-destination result: R0 and R2 were applied only after accepted B004/B005 work and leases cleared and all settled reports/destinations were reread. Their current destinations preserve B001/B004/B005/B004-UN, current B002 UID0004R9, and unrelated content; neither block was applied from the older evidence-time snapshot.

## First-Draft C++ Recommendation

- The exact managed destination set is R0-R12 below. The ordering follows dependency grouping rather than numeric label order; each label occurs once in this section.

### R0 - [UID0001KL] `by-memory/0x005a2530-0x005b8395.UserPane.md`

R0 is the exact implemented B003 aggregate disposition. The completed wait/reread/rebase pass proved current UID0001KL preserves settled B001/B004/B005/B004-UN facts and current B002 UID0004R9 while adding the renamed target and six issued children without deleting unrelated inventory.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Broad UserPane executable aggregate. Formal source is emitted by exact
// children such as UserPane methods, file-scope globals, and layout pages.
// The aggregate is documented through its exact source children; do not emit a synthetic body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R3 - [UID0003VA] renamed `by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyOrTextEventSwitchTables.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R4 - UID0004R3 `by-memory/0x005acf10-0x005acf5f.UserPaneSendOpcode7Command.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void SendOpcode7Command(unsigned char command)
{
    unsigned char packet[3];
    packet[0] = 7;
    packet[1] = command;
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R5 - UID0004R4 `by-memory/0x005ad450-0x005ad4ff.ToggleTargetSelectionPane.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ToggleTargetSelectionPane(bool)
{
    if (!g_activeMapPane->m_selectedObjectActive)
    {
        new SelectObjectWithKeyboardPane();
        return;
    }

    g_activeMapPane->m_selectedObjectActive = false;
    if (g_activeMapPane->m_selectedObjectPane != NULL)
        g_activeMapPane->m_selectedObjectPane->SetTargetHighlight(false);
    g_activeMapPane->m_selectedObjectPane = NULL;
    g_activeMapPane->m_selectedObjectDirection = -1;
    g_selectObjectTargetModeActive = false;
    g_targetObjectTargetModeActive = false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R6 - UID0004R5 `by-memory/0x005ad500-0x005ad660.NavigateTargetSelection.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NavigateTargetSelection(bool previous, bool chooseLocalPlayer)
{
    if (g_pConfig->m_targetSelectionSuppressed)
        return;

    if (g_activeMapPane->m_selectedObjectActive)
    {
        if (g_selectObjectTargetModeActive)
        {
            g_activeMapPane->m_selectedObjectActive = false;
            if (g_activeMapPane->m_selectedObjectPane != NULL)
                g_activeMapPane->m_selectedObjectPane
                    ->SetTargetHighlight(false);
            g_activeMapPane->m_selectedObjectPane = NULL;
            g_selectObjectTargetModeActive = false;
            g_targetObjectTargetModeActive = false;
            return;
        }

        LivingObjectPane *oldSelection =
            g_activeMapPane->m_selectedObjectPane;
        LivingObjectPane *newSelection = previous
            ? g_activeMapPane->FindPreviousLivingTarget(
                oldSelection, g_activeMapPane->m_selectedObjectDirection)
            : g_activeMapPane->FindNextLivingTarget(
                oldSelection, g_activeMapPane->m_selectedObjectDirection);

        if (oldSelection != NULL)
            oldSelection->SetTargetHighlight(false);
        if (newSelection != NULL)
            newSelection->SetTargetHighlight(true);
        g_activeMapPane->m_selectedObjectPane = newSelection;
        s_targetObjectTargetId =
            newSelection != NULL ? newSelection->m_objectId : 0;
        return;
    }

    LivingObjectPane *selection = g_pUserPane;
    int direction = 0;
    if (!chooseLocalPlayer)
    {
        LivingObjectPane *candidate =
            g_activeMapPane->FindNextLivingTarget(g_pUserPane, 1);
        if (candidate != NULL && candidate != g_pUserPane)
        {
            selection = candidate;
            direction = 1;
        }
    }

    if (selection != NULL)
        selection->SetTargetHighlight(true);
    g_activeMapPane->m_selectedObjectActive = true;
    g_activeMapPane->m_selectedObjectPane = selection;
    g_activeMapPane->m_selectedObjectDirection = direction;
    g_targetObjectTargetModeActive = true;
    s_targetObjectPreviousTargetId = -1;
    s_targetObjectTargetId = selection != NULL ? selection->m_objectId : 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R7 - UID0004R6 `by-memory/0x005ad660-0x005ad719.ReverseTargetSelectionDirection.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ReverseTargetSelectionDirection()
{
    if (g_selectObjectTargetModeActive ||
        g_activeMapPane->m_selectedObjectDirection == -1)
    {
        return;
    }

    g_activeMapPane->m_selectedObjectDirection =
        !g_activeMapPane->m_selectedObjectDirection;
    LivingObjectPane *oldSelection =
        g_activeMapPane->m_selectedObjectPane;
    if (oldSelection == NULL)
        return;

    LivingObjectPane *newSelection;
    if (s_targetObjectPreviousTargetId != -1)
    {
        newSelection = g_activeMapPane->FindObjectPaneById(
            s_targetObjectPreviousTargetId);
    }
    else
    {
        newSelection = g_activeMapPane->FindNextLivingTarget(
            oldSelection, g_activeMapPane->m_selectedObjectDirection);
    }

    oldSelection->SetTargetHighlight(false);
    if (newSelection != NULL)
        newSelection->SetTargetHighlight(true);
    g_activeMapPane->m_selectedObjectPane = newSelection;
    s_targetObjectPreviousTargetId =
        newSelection != NULL ? (int)oldSelection->m_objectId : -1;
    s_targetObjectTargetId =
        newSelection != NULL ? newSelection->m_objectId : 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R8 - [UID0002YU] `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R9 - [UID0002A9] `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool g_selectObjectTargetModeActive = false;
bool g_targetObjectTargetModeActive = false;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R12 - [UID0002A2] `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SelectObjectWithKeyboardPane *g_activeSelectObjectWithKeyboardPane = NULL;
static TargetObjectWithKeyboardPane *s_activeTargetObjectWithKeyboardPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R10 - UID0004R7 `by-memory/0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::BuildInventorySlotRangeText(wchar_t *outText) const
{
    wchar_t *out = outText;
    int runStart = 0;
    const int slotCount = g_activeUserStatusPane->m_inventorySlotCount;

    for (int slot = 1; slot <= slotCount + 1; ++slot)
    {
        const bool active =
            slot <= slotCount && m_inventorySlots[slot - 1].active != 0;
        if (active)
        {
            if (runStart == 0)
            {
                runStart = slot;
                *out++ = slot <= 26
                    ? (wchar_t)(L'a' + slot - 1)
                    : (slot <= 52
                        ? (wchar_t)(L'A' + slot - 27) : L' ');
            }
            continue;
        }

        if (runStart == 0)
            continue;

        const int runEnd = slot - 1;
        if (runEnd - runStart + 1 <= 3)
        {
            for (int item = runStart + 1; item <= runEnd; ++item)
            {
                *out++ = item <= 26
                    ? (wchar_t)(L'a' + item - 1)
                    : (item <= 52
                        ? (wchar_t)(L'A' + item - 27) : L' ');
            }
        }
        else
        {
            *out++ = L'-';
            *out++ = runEnd <= 26
                ? (wchar_t)(L'a' + runEnd - 1)
                : (runEnd <= 52
                    ? (wchar_t)(L'A' + runEnd - 27) : L' ');
        }
        runStart = 0;
    }

    *out = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R11 - UID0004R8 `by-memory/0x005a4310-0x005a4523.UserPaneBuildSpellSlotRangeText.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserPane::BuildSpellSlotRangeText(wchar_t *outText) const
{
    wchar_t *out = outText;
    int runStart = 0;

    for (int slot = 1; slot <= 53; ++slot)
    {
        const bool active =
            slot <= 52 && m_spellCommandSlots[slot - 1].active != 0;
        if (active)
        {
            if (runStart == 0)
            {
                runStart = slot;
                *out++ = slot <= 26
                    ? (wchar_t)(L'a' + slot - 1)
                    : (wchar_t)(L'A' + slot - 27);
            }
            continue;
        }

        if (runStart == 0)
            continue;

        const int runEnd = slot - 1;
        if (runEnd - runStart + 1 <= 3)
        {
            for (int item = runStart + 1; item <= runEnd; ++item)
            {
                *out++ = item <= 26
                    ? (wchar_t)(L'a' + item - 1)
                    : (wchar_t)(L'A' + item - 27);
            }
        }
        else
        {
            *out++ = L'-';
            *out++ = runEnd <= 26
                ? (wchar_t)(L'a' + runEnd - 1)
                : (wchar_t)(L'A' + runEnd - 27);
        }
        runStart = 0;
    }

    *out = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable; every destination is project source or compiler-generated output, not a third-party embed.
- R3/R8 remain blank because their bytes are regenerated from R1/R2. A comment body would itself emit source text for artifacts that have no handwritten declaration.

### R2 - [UID0000FQ] `by-class/UserPane.md`

R2 is the complete evidence-time UserPane class destination and already preserves B001's `StartDirectionalAnimation(char direction)` plus B004's `itemMetaKey`, `ownerName`, `currentDurability`, and `protectionCount`. B005's accepted callback requires the class formal to remain byte-for-byte complete while adding settings prose. R2 must not be pasted over a newer class snapshot: after all accepted shared callbacks/leases clear, reread the accepted reports and leased UID0000FQ, preserve every concurrent declaration/field/layout fact, and rebase this report's R2 before application if B002 UID0003UW, B004 UID0003UN, B005 UID0003UL, or unrelated current work changed the complete formal. The rebased result must still contain B003's exact Event override, six declarations, field splits, class close, and `[[CHILDREN]]` order.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class MapPane;
class SelectObjectWithKeyboardPane;
struct MapPoint;
struct ServerMessageEvent;

MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction);
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size);

void ToggleTargetSelectionPane(bool alternateMode);
void NavigateTargetSelection(bool previous, bool chooseLocalPlayer);
void ReverseTargetSelectionDirection();
extern bool g_selectObjectTargetModeActive;
extern bool g_targetObjectTargetModeActive;
extern SelectObjectWithKeyboardPane *g_activeSelectObjectWithKeyboardPane;

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void SendDirectionPacket(unsigned char direction);
static void SendOpcode7Command(unsigned char command);

struct LinkedPlayerRecord
{
    unsigned int objectId;
    wchar_t name[128];
    bool active;
    unsigned char reserved105;
    unsigned short field106;
    unsigned char state108[7];
    unsigned char reserved10f;
    unsigned short field110;
    unsigned char field112;
    unsigned char reserved113;
    unsigned short field114;
    unsigned char field116;
    unsigned char reserved117;
    unsigned short field118;
    unsigned char field11a;
    unsigned char reserved11b;
    unsigned int value11c;
    unsigned int value120;
    unsigned int value124;
    unsigned int value128;
};

struct LocalInventorySlotRecord
{
    unsigned char active;
    unsigned char reserved001;
    unsigned short itemId;
    unsigned char iconStyle;
    unsigned char reserved005;
    wchar_t displayName[80];
    wchar_t itemMetaKey[80];
    wchar_t ownerName[80];
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;
    unsigned char quantityPromptFlag;
    unsigned char reserved1ed[3];
    unsigned int currentDurability;
    unsigned int protectionCount;
    unsigned char targetMode;
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;
    unsigned char reserved001[3];
    int inputKind;
    unsigned char reserved008[0xa0];
    wchar_t prompt[80];
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnAnimationStep(int message, int frameOrDirection, int aux);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        unsigned short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseLinkedObjectsPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(unsigned char action);
    void BuildInventorySlotRangeText(wchar_t *outText) const;
    void BuildSpellSlotRangeText(wchar_t *outText) const;

private:
    friend class MapPane;

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementHistoryToken()
    {
        m_movementState[2] = 0;
        m_movementState[3] = 0;
    }

    void SetMovementReplyState()
    {
        m_movementState[1] = 1;
        m_movementState[2] = 1;
    }

    bool IsDirectionDelayActive() const
    {
        return m_movementState[4] != 0;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_movementState[4] = active ? 1 : 0;
    }

    unsigned char m_userPaneBaseTail[0x0c];
    LinkedPlayerRecord m_linkedPlayers[50];
    signed char m_linkedPlayerCount;
    unsigned char m_preCollectionState[0x203];
    int m_currentSayMode;
    unsigned char m_preCollectionCommandState[2];
    bool m_collectionPanelSoundEnabled;
    unsigned char m_postCollectionCommandState[9];
    int m_localPlayerHitRadius;
    CollectionPlayerDataView m_collectionData;
    int m_screenX;
    int m_screenY;
    unsigned int m_screenState;
    RectBounds m_screenHitBounds;
    RectBounds m_screenLowerHitBounds;
    MapPane *m_mapPane;
    unsigned char m_playerSettingsState[8];
    LocalInventorySlotRecord m_inventorySlots[52];
    SpellCommandSlotRecord m_spellCommandSlots[52];
    bool m_spellCommandSlotsReady;
    unsigned char m_preViewportState[3];
    int m_viewportColumn;
    int m_viewportRow;
    int m_viewportHalfColumns;
    int m_viewportHalfRows;
    int m_viewportRemainingColumns;
    int m_viewportRemainingRows;
    unsigned char m_movementState[5];
    unsigned char m_preActionTickState[3];
    unsigned int m_lastActionTick;
    unsigned int m_lastMapCommandTick;
    unsigned int m_lastGroundItemCommandTick;
    List *m_whisperHistoryOther;
    List *m_outgoingWhisperRecipientHistory;
    List *m_incomingWhisperSenderHistory;
    unsigned char m_whisperHistorySource;
    unsigned char m_preMovementHistory[3];
    LocalMovementHistoryRecord *m_movementHistoryRecords;
    int m_movementHistoryCapacity;
    unsigned char m_movementHistoryWriteIndex;
    bool m_inputLocked;
    unsigned char m_movementHistoryState[2];
    unsigned char *m_deferredUserListPacket;
    size_t m_deferredUserListPacketSize;
    int m_deferredUserListCount;
    unsigned int m_deferredUserListDeadline;
    bool m_deferredUserListActive;
    unsigned char m_preMovementTicks[3];
    unsigned int m_lastMovementSendTick;
    unsigned int m_lastMovementInputTick;
    unsigned char m_actionMode;
    unsigned char m_userPaneTrailingState0;
    bool m_includeAdjacentMovementTargets;
    unsigned char m_userPaneTrailingState2[0x45];
};

typedef char LinkedPlayerRecordSizeMustBe300[
    sizeof(LinkedPlayerRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### R1 - [UID0003V9] renamed target `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md`

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::HandleKeyOrTextEvent(Event *event)
{
    if (m_inputLocked)
        return true;
    if (m_mapPane->m_waitingForLocalPlayerStatus)
        return false;
    if (g_pTransferServerDialog != NULL)
        return false;
    if (event->m_type == kEventTextInput)
        return false;

    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    const unsigned char modifiers = event->m_payload.m_key.m_modifiers;

    if (m_nameVisible &&
        key != 0x1b && key != 0x09 && key != 'v' &&
        (m_actionMode != 2 ||
         (key != 0x80 && key != 0x81 &&
          key != 0x82 && key != 0x83)))
    {
        return false;
    }

    if ((modifiers & 3) == 1)
    {
        if (key >= '0' && key <= '9')
        {
            ExecuteHotkeyAction((short)(key - 28));
            return true;
        }

        switch (key)
        {
        case 'c':
            if (g_pChatInputPane == NULL)
                new ChatInputPane(L">");
            return true;

        case 't':
            g_pConfig->m_legacyOption14Flag =
                !g_pConfig->m_legacyOption14Flag;
            return true;

        case 'x':
            OpenQuitPrompt();
            return true;

        default:
            return false;
        }
    }

    if ((modifiers & 1) == 0 && (modifiers & 2) != 0)
    {
        if (key >= '0' && key <= '9')
        {
            ExecuteHotkeyAction((short)(key - 38));
            return true;
        }

        switch (key)
        {
        case 0x09:
            if (g_pConfig->m_tabVSwap)
                return true;
            if (g_targetObjectTargetModeActive)
                ReverseTargetSelectionDirection();
            else
                NavigateTargetSelection(false, true);
            return true;

        case 'v':
            if (!g_pConfig->m_tabVSwap)
                return true;
            if (g_targetObjectTargetModeActive)
                ReverseTargetSelectionDirection();
            else
                NavigateTargetSelection(false, true);
            return true;

        case ',':
            SendOpcode7Command(3);
            return true;

        case 'w':
        {
            g_gameServerNationTable->RequestNationEntries();
            if (m_deferredUserListDeadline >= g_pTimerMgr->m_currentTick)
            {
                m_deferredUserListActive = true;
                DispatchCopiedEventPayload(
                    m_deferredUserListPacket,
                    m_deferredUserListPacketSize);
            }
            else
            {
                unsigned char packet[2] = { 0x18, 0 };
                g_packetSender->QueueAndSendPacket(packet, 1);
            }
            return true;
        }

        case 0x80:
            SendAttackTargetPacket(3);
            return true;
        case 0x81:
            SendAttackTargetPacket(0);
            return true;
        case 0x82:
            SendAttackTargetPacket(1);
            return true;
        case 0x83:
            SendAttackTargetPacket(2);
            return true;

        default:
            return false;
        }
    }

    if ((modifiers & 3) != 0)
        return false;

    switch (key)
    {
    case 0x09:
    case 0x0d:
        if (!g_pConfig->m_sayWithEnter)
            return true;
        m_currentSayMode = 0;
        OpenDefaultSayPane();
        return true;

    case 0x1b:
        if (m_nameVisible)
        {
            SendMovementPacket(1);
            return false;
        }
        if (!m_mapPane->m_selectedObjectActive)
            return false;
        m_mapPane->m_selectedObjectActive = false;
        if (m_mapPane->m_selectedObjectPane != NULL)
            m_mapPane->m_selectedObjectPane->SetTargetHighlight(false);
        m_mapPane->m_selectedObjectPane = NULL;
        m_mapPane->m_selectedObjectDirection = -1;
        g_selectObjectTargetModeActive = false;
        g_targetObjectTargetModeActive = false;
        return true;

    case 0x20:
        if (m_actionMode == 0 ||
            g_pTimerMgr->m_currentTick - m_lastActionTick <= 100 ||
            m_actionMode != 1 ||
            g_activeSelectObjectWithKeyboardPane != NULL ||
            m_mapPane->m_selectedObjectActive)
        {
            TryPerformAction();
        }
        else
        {
            new SelectObjectWithKeyboardPane();
        }
        return true;

    case '!':
        m_currentSayMode = 1;
        CreateShoutInputPane();
        return true;

    case '"':
        m_currentSayMode = 2;
        new SayToUserNameInputPane();
        return true;

    case '\'':
        OpenInputPaneForCurrentSayMode();
        return true;

    case '*':
        return true;

    case '+':
        g_pGeneralPurposePanel->SwitchActiveTab(3, NULL);
        g_pSoundManager->PlaySoundEffect(0x198, 100);
        return true;

    case ',':
        if (g_pTimerMgr->m_currentTick - m_lastGroundItemCommandTick > 1000)
        {
            unsigned char packet[3] = { 7, 0, 0 };
            g_packetSender->QueueAndSendPacket(packet, 2);
            m_lastGroundItemCommandTick = g_pTimerMgr->m_currentTick;
        }
        return true;

    case '/':
        m_currentSayMode = 0;
        new SayInputPane(L"/");
        return true;

    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        ExecuteHotkeyAction((short)(key - '0'));
        return true;

    case ':':
        new EmotionInputPane();
        return true;

    case ';':
    {
        unsigned char packet[2] = { 9, 0 };
        g_packetSender->QueueAndSendPacket(packet, 1);
        return true;
    }

    case '<':
        SendOpcode7Command(1);
        return true;

    case 'C':
        new ChangeSpellSlotInputPane(
            g_pStringTable->GetString(45));
        return true;

    case 'D':
    {
        DropAllInputPane *pane = new DropAllInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(8), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'E':
        if (g_pGeneralPurposePanel->m_activeChildIndex == 1)
        {
            unsigned char packet[5] = { 27, 1, 8, 0, 0 };
            g_packetSender->QueueAndSendPacket(packet, 4);
        }
        else
        {
            ((SelfLookPane *)g_pGeneralPurposePanel->GetActiveChildPane())
                ->SendToggleLook();
        }
        return true;

    case 'F':
    {
        unsigned char packet[5] = { 27, 1, 10, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 'G':
        if (g_pGeneralPurposePanel->m_activeChildIndex == 1)
        {
            unsigned char packet[5] = { 27, 1, 2, 0, 0 };
            g_packetSender->QueueAndSendPacket(packet, 4);
        }
        else
        {
            ((SelfLookPane *)g_pGeneralPurposePanel->GetActiveChildPane())
                ->SendToggleEquip();
        }
        return true;

    case 'H':
    {
        GiveAllInputPane *pane = new GiveAllInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(44), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'I':
        if (g_pMixItemDialog == NULL)
            new MixItemDialog();
        return true;

    case 'M':
        if (g_pBulletinSession == NULL)
            new BulletinSession(1, 0, true);
        return true;

    case 'P':
        if (!m_playerSettingsState[0])
            return true;
        {
            unsigned char packet[8] = {
                76, 1, 4,
                (unsigned char)g_pConfig->m_powerDialogThresholdDefaults[0],
                (unsigned char)g_pConfig->m_powerDialogThresholdDefaults[1],
                (unsigned char)g_pConfig->m_powerDialogThresholdDefaults[2],
                (unsigned char)g_pConfig->m_powerDialogThresholdDefaults[3],
                0
            };
            g_packetSender->QueueAndSendPacket(packet, 7);
        }
        return true;

    case 'Q':
        OpenQuitPrompt();
        return true;

    case 'R':
        g_pConfig->m_clickLookEnabled = !g_pConfig->m_clickLookEnabled;
        g_pChattingViewport->AppendColoredText(
            g_pConfig->m_clickLookEnabled
                ? L"Right click look :ON" : L"Right click look :OFF",
            132, 36);
        return true;

    case 'T':
        new TakeOffInputPane();
        return true;

    case 'V':
    case 'v':
        if (m_nameVisible)
        {
            SendMovementPacket(1);
            return false;
        }
        ToggleTargetSelectionPane((modifiers & 4) != 0);
        return true;

    case 'W':
    {
        WearInputPane *pane = new WearInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(33), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'Z':
        if (m_spellCommandSlotsReady)
        {
            SpellSpellInputPane *pane = new SpellSpellInputPane(0);
            wchar_t slots[36];
            wchar_t prompt[128];
            BuildSpellSlotRangeText(slots);
            swprintf_s(prompt, 128, g_pStringTable->GetString(36), slots);
            pane->SetPrompt(prompt);
        }
        return true;

    case 'b':
        EnsureNormalBulletinSession();
        return true;

    case 'c':
        new ChangeItemSlotInputPane(
            g_pStringTable->GetString(46));
        return true;

    case 'd':
    {
        DropInputPane *pane = new DropInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(6), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'e':
    {
        EatInputPane *pane = new EatInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(12), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'f':
        g_pGeneralPurposePanel->SwitchActiveTab(4, NULL);
        g_pSoundManager->PlaySoundEffect(0x198, 100);
        return true;

    case 'g':
        new GroupInputPane(g_pStringTable->GetString(47));
        return true;

    case 'h':
    {
        GiveInputPane *pane = new GiveInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(42), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'i':
        g_pGeneralPurposePanel->SwitchActiveTab(2, NULL);
        g_pSoundManager->PlaySoundEffect(0x198, 100);
        return true;

    case 'm':
        if (g_pMiniMapDialog != NULL)
        {
            g_pMiniMapDialog->Show(1);
        }
        else
        {
            m_mapPane->GetCurrentMapId();
            unsigned char packet[2] = { 124, 0 };
            g_packetSender->QueueAndSendPacket(packet, 1);
        }
        return true;

    case 'o':
        if (g_pTimerMgr->m_currentTick - m_lastMapCommandTick > 1000)
        {
            unsigned char packet[2] = { 32, 0 };
            g_packetSender->QueueAndSendPacket(packet, 1);
            m_lastMapCommandTick = g_pTimerMgr->m_currentTick;
        }
        return true;

    case 'p':
    {
        PostInputPane *pane = new PostInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(11), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'r':
    {
        unsigned char packet[5] = { 27, 1, 0, 1, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 's':
    {
        unsigned char packet[3] = { 45, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 2);
        if (g_useEpfAssets)
            g_opcode2dEpfCommandExtraValue = event->m_messageTime;
        else
            g_opcode2dLegacyCommandExtraValue = event->m_messageTime;
        return true;
    }

    case 't':
    {
        ThrowInputPane *pane = new ThrowInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(35), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'u':
    {
        UseInputPane *pane = new UseInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(9), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'w':
    {
        WieldInputPane *pane = new WieldInputPane(0);
        wchar_t slots[36];
        wchar_t prompt[128];
        BuildInventorySlotRangeText(slots);
        swprintf_s(prompt, 128, g_pStringTable->GetString(13), slots);
        pane->SetPrompt(prompt);
        return true;
    }

    case 'z':
        if (m_collectionData.metadataLoaded)
        {
            if (m_collectionPanelSoundEnabled)
                g_pSoundManager->PlaySoundEffect(0x198, 100);
            g_pGeneralPurposePanel->SwitchActiveTab(5, NULL);
        }
        else
        {
            unsigned char packet[4] = { 39, 0, 0, 0 };
            g_packetSender->QueueAndSendPacket(packet, 3);
        }
        return true;

    case 0x80:
        ProcessMovement(3);
        return true;
    case 0x81:
        ProcessMovement(0);
        return true;
    case 0x82:
        ProcessMovement(1);
        return true;
    case 0x83:
        ProcessMovement(2);
        return true;

    case 0x85:
        if (((modifiers & 4) != 0) == g_pConfig->m_f1Swap)
        {
            if (g_pActiveBrowserWindow == NULL)
                new BrowserDialog(0, L"help.nexustk.com/wiki", 900, 650);
        }
        else
        {
            SendOpcode43MinusOneRequest();
        }
        return true;

    case 0x86:
    {
        unsigned char packet[11] = {
            67, 1, 0xff, 0xff, 0xff, 0xfe,
            0, 0, 0, 4, 0
        };
        g_packetSender->QueueAndSendPacket(packet, 10);
        return true;
    }

    case 0x87:
        new FriendListDialog();
        return true;

    case 0x88:
    {
        unsigned char packet[5] = { 27, 1, 7, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 0x89:
    {
        unsigned char packet[5] = { 27, 1, 1, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 0x8a:
    {
        unsigned char packet[5] = { 27, 1, 3, 0, 0 };
        g_packetSender->QueueAndSendPacket(packet, 4);
        return true;
    }

    case 0x8b:
        if (g_pSoundManager->IsSoundEffectsEnabled())
        {
            g_pSoundManager->DisableSoundEffects();
            g_pSoundManager->MuteMusic();
        }
        else
        {
            g_pSoundManager->EnableSoundEffects();
            g_pSoundManager->UnmuteMusic();
        }
        return true;

    case 0x8c:
        new MusicControlDialog();
        return true;

    case 0x8d:
        if ((modifiers & 4) != 0)
        {
            if (g_pFittingRoomDialog == NULL)
                new FittingRoomDialog();
        }
        else
        {
            new BlockListenInputPane();
        }
        return true;

    case 0x8e:
        if ((modifiers & 4) != 0)
        {
            g_pConfig->m_showDamage = !g_pConfig->m_showDamage;
            g_pChattingViewport->AppendColoredText(
                g_pConfig->m_showDamage
                    ? L"Show Damage      :ON" : L"Show Damage      :OFF",
                132, 36);
        }
        else
        {
            g_pGeneralPurposePanel->SwitchActiveTab(6, NULL);
            g_pSoundManager->PlaySoundEffect(0x198, 100);
        }
        return true;

    case 0x8f:
        if ((modifiers & 4) != 0)
        {
            g_pConfig->m_tabVSwap = !g_pConfig->m_tabVSwap;
            g_pChattingViewport->AppendColoredText(
                g_pConfig->m_tabVSwap
                    ? L"Tab V Swap       :ON" : L"Tab V Swap       :OFF",
                132, 36);
        }
        else
        {
            new IntegrateMacroDialog();
        }
        return true;

    case 0x90:
        if ((modifiers & 4) != 0)
        {
            g_pConfig->m_clickMoveEnabled = !g_pConfig->m_clickMoveEnabled;
            g_pChattingViewport->AppendColoredText(
                g_pConfig->m_clickMoveEnabled
                    ? L"Click to move    :ON" : L"Click to move    :OFF",
                132, 36);
        }
        else
        {
            g_pConfig->m_mapMovementStatusOption =
                !g_pConfig->m_mapMovementStatusOption;
            unsigned char packet[4] = { 27, 1, 9, 0 };
            g_packetSender->QueueAndSendPacket(packet, 3);
        }
        return true;

    case 0x92:
        g_pSoundManager->m_advanceTrackRequested = true;
        if (g_pConfig->m_musicSourceMode == 1)
            g_pSoundManager->PlayNextTrack();
        else if (g_pConfig->m_musicSourceMode == 2)
            g_pSoundManager->AdvanceRedbookTrack();
        return false;

    default:
        return false;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

- UID0003V9 and UID0003VA were renamed through the validator-preserving workflow; neither page was manually moved.
- UID0003V9 now has exact metadata `92/94`, owner/emitter UID0000FQ, reconstructable true, blank optional position, `Nested:0`, and R1.
- UID0003VA now retains owner `NONE`, reconstructable false, blank emitters/position/R3, `Nested:0`, and `90/94` after its validator-preserving rename.
- UID0000FQ now contains exact rebased R2 at `93/94`, preserving UID0000P1 owner/emitter, position 10, complete 0x13eb84 size, the B001/B004/B005/B004-UN declaration/layout union, current B002 UID0004R9, all unrelated content, class close, and trailing `[[CHILDREN]]`.
- Validator registration issued UID0004R3/UID0004R7/UID0004R8 under UserPane source/class routes and UID0004R4/UID0004R5/UID0004R6 under TargetSelectionInputPanes; no NEW-3V9 placeholder remains.
- R9 external-linkage mode flags and R12's external active SelectObject pointer are applied, and UID0000OH declarations/inventory are synchronized. Zero-xref surrounding bytes and the TargetObject pointer's still-valid internal linkage remain preserved.
- UID0002YU is reclassified as compiler-generated/non-reconstructable source data: semantic owner UID0000FQ, blank emitter/position/R8, `Nested:8`, no raw array.
- UID0001KL, UID0001KM, UID0000P1, UID0000OH, option-string/packet/global support, and all current links are synchronized at report-level detail from the rebased union. Shared UserPane edits preserve B001 signed-direction/duration/table behavior, B004 opcode-`0x0f` parser/record/write order, B005 opcode-`0x08` settings/index/order behavior, B004-UN server-entry behavior, current B002 UID0004R9, and all unrelated content. Event/EventHandler and established dialog/API dependencies remained verify-only because no direct contradiction appeared.
- Exact items left non-emitting: UID0003VA switch/selector bytes, UID0002YU vtable/RTTI bytes, predecessor/inter-function padding, and unreferenced mode-flag allocation bytes.
- No future target research is required to make R1 compile conceptually. Only original private lexical spellings remain unavailable and are already score-capped.

## Recommended Target Doc Changes

- Implemented target path: validator-preserving rename to `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md` while preserving UID0003V9 and the exact range.
- Exact metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000FQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FQ`, blank optional position, `Nested:0`, R1 exact.
- Exact Item Summary: `Complete bool UserPane EventHandler key/text override with exact entry gates, modifier partitions, handled returns, movement/action/hotkey/chat/target/panel/dialog dispatch, packet byte order and lengths, debounce fields, option toggles, attached compiler switch tables, vtable-only route, and source-quality Event/class/helper resolution.`
- Incorporate exact range/size/hash, prologue, predecessor pad, sole vtable cell, no direct callers, 60-callee inventory, complete switch topology, table relationship, receiver normalization, Event fields, bool return, key/modifier behavior, packets, constructors, helpers, fields/globals, source placement, positives, negatives, rejected alternatives, and score rationale from this report.
- Preserve historical `sub_5A5BD0`, `HandleKeyEvent`, `OnKeyEvent`, and `PaneKeyEvent` as explicitly superseded provenance. Remove current/future statements that final fields/helpers remain unresolved or that C++ must remain blank.
- Cross-links use renamed UID0003VA and issued UIDs UID0004R3-UID0004R8 for all six implemented children.

## Recommended Support Doc Changes

- `by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyOrTextEventSwitchTables.md`: UID0003VA was validator-preserving renamed and now has `90/94`, none/false/blank emitters/position/R3, Nested0, exact table runs, selector regions, 81 in-target entries, terminal pad, successor, and no-source proof.
- `by-class/UserPane.md` UID0000FQ: after the shared callbacks/leases cleared, the complete class was reread/rebased and exact R2 applied at `93/94`. It preserves B001 `StartDirectionalAnimation(char direction)` and signed duration/table contract, B004 `itemMetaKey`/`ownerName`/`currentDurability`/`protectionCount`, B005 settings-state indices and index-3/index-4 distinction, B004-UN server-entry declarations, current B002 UID0004R9, and every unrelated declaration/record/field/size guard/owner/emitter/position. Only stale `PaneKeyEvent`/`OnKeyEvent` was replaced; B003's six declarations and external mode/pointer declarations were added, B003 fields were split without changing 0x13eb84, and the class closes before `[[CHILDREN]]`.
- `by-file/UserPane.md` UID0000P1: after the same reread/rebase pass, `92/93` was applied while preserving complete B001 ProcessMovement and `StartDirectionalAnimation` MonsterObject table/signed-duration/non-monster signed-delay/event-20/map-refresh facts, B004 opcode-`0x0f` exact 508-byte inventory record/fields/write order and invalid-slot/return facts, B005 opcode-`0x08` state/index/offset/blindness/movement/config/sound/active-panel order plus index-3/index-4 distinction, B004-UN server-entry source facts, current B002 UID0004R9, and all unrelated source families. The renamed B003 target, R1, UID0004R3/UID0004R7/UID0004R8 inventory, exact source order, target-selection cross-TU declarations, compiler table/vtable exclusions, negatives/history, and generated route are present.
- `by-memory/0x005a2530-0x005b8395.UserPane.md` UID0001KL retains owner/emitter UID0000P1, reconstructable true, blank position, Nested0, and exact R0 at `91/93`; its complete settled sibling inventory now includes the renamed target/all issued children plus exact table/padding/source facts.
- `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` UID0001KM keeps scores/route unchanged, preserves settled B001/B004/B005/B004-UN/current B002 inventory/detail plus every unrelated raw/no-route candidate, and replaces only deferred `0x005acf10`, `0x005a40d0`, and `0x005a4310` wording with issued exact B003 children.
- UID0004R3: exact path/range/title above, `90/93`, owner/emitter UID0000P1, true, blank optional position, Nested0, R4, exact two callers/hash/padding and packet proof.
- UID0004R7: exact path/range/title above, `90/93`, owner/emitter UID0000FQ, true, blank optional position, Nested0, R10, exact hash/dynamic inventory-count/range-compression/slot-label behavior and alignment.
- UID0004R8: exact path/range/title above, `90/93`, owner/emitter UID0000FQ, true, blank optional position, Nested0, R11, exact hash/52-slot/range-compression/slot-label behavior and alignment.
- UID0004R4/UID0004R5/UID0004R6: exact paths/ranges above, each `90/93`, owner/emitter UID0000OH, true, blank optional position, Nested0, respective R5/R6/R7, exact map highlight/mode/saved-target/constructor behavior and caller evidence.
- `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md` UID0002A9: `91/93`; preserve exact eight-byte range, zero bytes, xref/no-xref counts, mode distinction, no-split decision, owner/emitter UID0000OH, true, blank position, Nested0; apply R9 and historicalize the former `static s_` declarations.
- `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md` UID0002A2: `90/92`; preserve exact range/zero bytes/xrefs/constructor-destructor lifecycle/no-split route and second pointer's static declaration; apply R12 and historicalize only the first pointer's impossible static linkage/name.
- `by-file/TargetSelectionInputPanes.md` UID0000OH: scores/route unchanged; add UID0004R4/UID0004R5/UID0004R6, externally linked flag definitions and active SelectObject pointer, UserPane caller boundary, helper prototypes, exact source order, and rejected first-pointer/mode-flag static-linkage history while preserving existing classes/globals/helpers and the still-static TargetObject pointer.
- `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` UID0002YU: `90/94`, semantic owner UID0000FQ, `RECONSTRUCTABLE:FALSE`, blank emitters/position/R8, `Nested:8`; retain exact primary table/RTTI/slot/constructor/destructor evidence and state that R2/R1 regenerate the bytes.
- `by-memory/0x006307ec-0x006309d0.UserPaneOptionStatusStrings.md`, Event/EventHandler, MapPane, GeneralPurposePanel, TimerMgr, packet sender, dialog/input class/global pages: verify-only. Update only rename-managed links or an exact current contradiction; do not broaden source-quality debt.

## Score And Metadata Recommendation

| Destination | Historical pre-callback | Implemented | Rationale / cap |
| --- | --- | --- | --- |
| UID0003V9 target | `86/88`, true, FQ/FQ, blank | `92/94`, true, FQ/FQ, R1 | all behavior/type/helper/source blockers closed; private lexical names not symbol-proven |
| UID0003VA table | `86/90`, none/false/blank | `90/94`, same route, R3 blank | exact bytes/table runs/owner method/compiler cause; no source body |
| UID0000FQ class | `92/93` | `93/94`, R2 | exact interface and field splits added; full class already strong |
| UID0000P1 file | `91/92` | `92/93` | direct target and six helper source destinations resolved |
| UID0001KL parent | `90/92` | `91/93` | complete inventory/range/table/helper closure; still broad aggregate |
| UID0002YU vtable | `88/91`, true/emitting comment | `90/94`, false/blank | exact compiler-only generation and slot route; no raw source |
| UID0002A9 flags | `90/91` | `91/93` | cross-TU linkage blocker closed; exact original spelling still inferred |
| UID0002A2 singleton slots | `88/90` | `90/92`, R12 | active SelectObject cross-TU read closes linkage; exact spellings remain inferred |
| six registered children UID0004R3-UID0004R8 | absent | each `90/93` | complete exact body/range/source route; private spellings inferred |
| UID0000OH file | prior score/route | unchanged | bounded helper/linkage sync does not justify broad file inflation |

- Score-improvement attempt: whole-function decompile/CFG, table target scan, Event/interface lookup, receiver normalization, every key route, packet stores, 60 callees, helper decompiles, two slot-range hashes, target-selection call/global analysis, class layout arithmetic, old-report search, generated readback, and coverage-row inspection were all completed.
- Removed blockers: method/type/return, receiver, fields used by target, packet layouts, source constructors, helper bodies/routes, flag linkage, table/vtable treatment, source placement, and formal declaration.
- Remaining caps: no original private symbols, one legacy option spelling, descriptive helper/MapPane private field names, and no recovered source header split. None prevents coherent C++ or owner/emitter routing.
- Metadata unchanged unless stated: target Nested0/blank position; table Nested0; parent Nested0; vtable Nested8; owner/file routes above.

## Open Questions With Attempted Resolution

- Was the original virtual named `OnKeyEvent`? Rejected after checking EventHandler's accepted `HandleKeyOrTextEvent(Event *)` contract, Event fields, vtable ABI, and sibling usage. The interface spelling is the defensible source name.
- Is the event const? Rejected. The governing interface uses mutable `Event *`; target reads message-time payload and matches that ABI.
- Are mode flags file-static? Rejected. Exact UserPane writes at `0x005a6f6f/76` and TargetSelectionInputPanes accesses cannot be represented by two different translation units sharing `static` definitions.
- Is the active SelectObject singleton pointer file-static? Rejected for the first UID0002A2 dword because UID0003V9 directly reads it from UserPane.cpp. The adjacent TargetObject pointer has no target cross-TU use and remains static under current evidence.
- Should the switch table or vtable emit comments? No. Both are compiler-generated and R3/R8 stay literally blank; documentation carries the proof.
- Should target-selection helpers be UserPane members? No. They do not use a UserPane receiver, share TargetSelectionInputPanes state/classes, and have complete file-helper source shape.
- Should slot-range helpers remain unnamed/deferred? No. Their exact bodies, hashes, object-relative inventory/spell tables, dynamic/52 bounds, label mapping, range compression, and target calls support descriptive UserPane member names and R10/R11 now.
- Are packet classes required? No. Exact local byte arrays preserve observed source semantics more conservatively than invented protocol wrappers.
- Remaining unresolved question: exact original private lexical spellings and header split. Exhausted routes were IDB names, strings, decompile, current docs, generated source, all historical roots, xrefs, and caller families. This only caps confidence at 93/94 and does not alter code behavior.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-callback read-only inspection found `by-memory/-coverage-report.md` UID0001KL at line 3221, UID0002A9 at line 4016, UID0002A2 at line 4023, and no UID0003V9/UID0003VA/UID0002YU/six-child rows; `by-class/-coverage-report.md` UID0000FQ at line 586; and `by-file/-coverage-report.md` UID0000OH/UID0000P1 at lines 278/297. Evidence-time hashes were `AE64427CF5F99D4C0830412CA72BD7B36D6D6BB256CE4486457C642EADB26E40` for class coverage and `F9C2ED6B468DBAE4DA9576119350B1D5F1D50D6BC402970B202D8CCCA42822D7` for file coverage. Later manual-row state is external and not asserted here.
- The UID0000FQ/UID0000P1 replacements below are the callback-time full union: they preserve B001 movement, B004 UID0003UM inventory, B005 UID0003UL settings, executed B004 UID0003UN server-entry facts, current B002-owned UID0004R9, and every B003 addition without deleting accepted phrases. They are exact supervisor-owned handoff text, not an instruction or assertion about later application.
- File/placement handoff: `by-memory/-coverage-report.md` replacements for UID0001KL, UID0001KM, UID0002A9, and UID0002A2 plus address-sorted UID0003V9/UID0003VA/UID0002YU/UID0004R3-UID0004R8 additions. All six UIDs are validator-issued; no placeholder remains. This text is additive to existing B004 UID0003UN and B002 UID0004R9 rows and does not supersede or duplicate them.

```text
    - [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md) 0x005a2530-0x005b8395 | broad reconstructable UserPane aggregate | UserPane : reconstructable : 91% : very-strong : Complete UserPane executable/source-family index with exact constructor/destructor/vtables, complete EventHandler key/text dispatcher, six source-ready B003 helper children, source-ready opcode-0x0f inventory/opcode-0x08 settings/opcode-0x05 server-entry members, current B002 UID0004R9 preservation, attached compiler switch data, exact 0x20c base and 0x13eb84 object boundary, corrected member/file-local routing, retained raw/inline-equivalent history, exact padding, and no synthetic aggregate body.
    - [UID:0001KM][0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md) 0x005a2de0-0x005ad441 | non-emitting UserPane source-family index | UserPaneLocalPlayerExtensions : not_reconstructable : 90% : very-strong : Exact mixed index for UserPane members, UserPane.cpp file-local helpers, retained raw bodies, inline-equivalent routes, and internal padding; preserves B001 movement, B004 opcode-0x0f inventory, B005 opcode-0x08 settings, B004 opcode-0x05 server-entry, and current B002 group-list path facts, and now routes exact UID0004R3 opcode-7 plus UID0004R7/UID0004R8 slot-range children while owner NONE/blank emitter/formal C++ remain index-only.
        - [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md) 0x005a5bd0-0x005a7422 | method | UserPaneHandleKeyOrTextEvent : reconstructable : 92% : very-strong : Complete bool UserPane EventHandler override with exact entry gates, modifier and key switches, handled returns, target/action/movement/chat/panel/dialog paths, packet bytes and lengths, debounce/state fields, sole vtable route, exact hash, and complete human C++.
        - [UID:0003VA][0x005a7422-0x005a76c0.UserPaneHandleKeyOrTextEventSwitchTables](by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyOrTextEventSwitchTables.md) 0x005a7422-0x005a76c0 | compiler switch/selector data | UserPaneHandleKeyOrTextEventSwitchTables : ignored : 90% : very-strong : Exact four table runs with 81 dword targets all inside UID0003V9, interleaved selector maps, two-byte lead alignment, four-byte successor pad, and compiler-regenerated no-code disposition.
        - [UID:0004R7][0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText](by-memory/0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText.md) 0x005a40d0-0x005a430c | method | UserPaneBuildInventorySlotRangeText : reconstructable : 90% : very-strong : Exact inventory-active-slot label/range formatter with dynamic slot count, lower/upper labels, three-item expansion versus hyphen compression, exact hash/boundaries, target caller, and complete C++.
        - [UID:0004R8][0x005a4310-0x005a4523.UserPaneBuildSpellSlotRangeText](by-memory/0x005a4310-0x005a4523.UserPaneBuildSpellSlotRangeText.md) 0x005a4310-0x005a4523 | method | UserPaneBuildSpellSlotRangeText : reconstructable : 90% : very-strong : Exact 52-slot spell-command label/range formatter with lower/upper labels, three-item expansion versus hyphen compression, exact hash/boundaries, target caller, and complete C++.
        - [UID:0004R3][0x005acf10-0x005acf5f.UserPaneSendOpcode7Command](by-memory/0x005acf10-0x005acf5f.UserPaneSendOpcode7Command.md) 0x005acf10-0x005acf5f | file helper | UserPaneSendOpcode7Command : reconstructable : 90% : very-strong : Exact two-byte opcode-7 command sender with two UID0003V9 callers, complete packet body, hash, boundaries, UserPane.cpp source route, and complete C++.
        - [UID:0004R4][0x005ad450-0x005ad4ff.ToggleTargetSelectionPane](by-memory/0x005ad450-0x005ad4ff.ToggleTargetSelectionPane.md) 0x005ad450-0x005ad4ff | file helper | ToggleTargetSelectionPane : reconstructable : 90% : very-strong : Complete active-map target cancel-or-open helper with highlight, map state, both mode flags, constructor behavior, exact range, and TargetSelectionInputPanes.cpp source route.
        - [UID:0004R5][0x005ad500-0x005ad660.NavigateTargetSelection](by-memory/0x005ad500-0x005ad660.NavigateTargetSelection.md) 0x005ad500-0x005ad660 | file helper | NavigateTargetSelection : reconstructable : 90% : very-strong : Complete previous/next/local target-selection helper with config gate, highlight transitions, MapPane lookup calls, direction/filter state, saved target ids, mode flags, exact range, and complete C++.
        - [UID:0004R6][0x005ad660-0x005ad719.ReverseTargetSelectionDirection](by-memory/0x005ad660-0x005ad719.ReverseTargetSelectionDirection.md) 0x005ad660-0x005ad719 | file helper | ReverseTargetSelectionDirection : reconstructable : 90% : very-strong : Complete target-direction reversal helper with mode gate, saved-id lookup/fallback traversal, highlight transitions, saved target updates, exact range, and complete C++.
        - [UID:0002YU][0x0062ef0c-0x0062efcc.UserPaneVtableData](by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md) 0x0062ef0c-0x0062efcc | compiler vtable/RTTI data | UserPaneVtableData : ignored : 90% : very-strong : Exact UserPane vtable family with constructor/destructor references, EventHandler key/text slot 0x0062ef98, sibling virtual slots, compiler-generation proof, and blank no-raw-array formal disposition.
    - [UID:0002A9][0x0069bed8-0x0069bee0.TargetSelectionModeFlags](by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md) 0x0069bed8-0x0069bee0 | global-data flag cluster | TargetSelectionModeFlags : reconstructable : 91% : very-strong : Two externally linked TargetSelectionInputPanes mode bools with exact per-byte xrefs, UserPane cross-TU clears, SelectObject/TargetObject set-clear roles, zero allocation-byte negatives, next-object boundary, no-split decision, and complete declarations.
    - [UID:0002A2][0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots](by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md) 0x0069bf60-0x0069bf68 | global-data cluster | TargetSelectionKeyboardPaneSingletonSlots : reconstructable : 90% : strong : Exact zero-initialized SelectObject/TargetObject active singleton slots with constructor/destructor/cleanup xrefs, direct UserPane cross-TU read requiring external linkage for the first pointer, retained static second pointer, no-split boundaries, and complete declarations.
```

- File/placement: `by-class/-coverage-report.md`, replace UID0000FQ.

```text
- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 93% : very-strong : Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, external ProcessMovement and event helper declarations, corrected viewport half/remaining column/row fields, movement-history records, corrected opcode-0x13 movement-target sender, signed plain-char StartDirectionalAnimation(char direction) with signed-short frame-duration/MonsterObject image-table and signed non-monster scaled-delay contracts, 52 exact 508-byte inventory records with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, exact player-settings semantics comprising state[0] feature/UI mode, state[2] viewport-threshold mode, state[3] direction mode, state[4] MapPane-render blindness with bounds invalidation, and state[5]/[6] chat display/send restriction levels, the distinct movement-state index-3 pending-reply flag versus index-4 direction-delay state, source-ready opcode-0x05 HandleServerEntryPacket declaration, exact EventHandler HandleKeyOrTextEvent(Event *) override, six resolved B003 target/helper declarations, preserved current B002 UID0004R9 child, int say-mode/collection-panel-sound/three-debounce/input-lock field splits, exact 0x20c base boundary, class closure before child definitions, exact records/size guards, and preserved full unrelated field/record/layout/source surface.
```

- File/placement: `by-file/-coverage-report.md`, replace UID0000P1 and UID0000OH.

```text
- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, corrected helper declarations, signed plain-char StartDirectionalAnimation(char direction) with signed-short MonsterObject frame-duration image-table/group/frame path, signed non-monster scaled-delay arithmetic, event-20 scheduling, branch-specific ordering, and branch-local MapPane refresh, corrected opcode-0x13 movement-target sender using MapPane collect/sort with exact count-versus-nine cap/local terminator behavior, preserved action/adjacent-target fields, packet ABI, movement-history, server, target, and caller evidence, source-ready opcode-0x0f ParseInventorySlotUpdatePacket using signed one-based slots, three explicit ACP text conversions, the exact 508-byte inventory record with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, active UserStatusPane slot-count bound, exact write order, and preserved invalid-slot/always-false behavior, source-ready opcode-0x08 settings parsing with exact state indices, 2/31 offset arithmetic, packet cursor/store order, blindness invalidation, movement-state/TryStepForward order, ten ordered direct config stores, SoundManager enable/mirror order, active GeneralPurposePanel child-6 OnActivate refresh, and adjacent movement-reply index-3 versus index-4 corrections, source-ready opcode-0x05 HandleServerEntryPacket with duplicated EPF/legacy SpelledPane refresh, sender re-enable, transfer-overlay deferred deletion, object/facing/status application, MapPane bounds refresh, and block/listen replay, plus exact HandleKeyOrTextEvent(Event *) entry gates/modifier and key switches/handled returns/packet order and source body, two slot-range methods, opcode-7 sender, current B002 UID0004R9 preservation, target-selection cross-TU declarations, compiler switch/vtable exclusions, retained raw/inline-equivalent history, exact source order, and no UID0003V9 empty emitter or duplicate body.
- [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) : reconstructable : 90% : strong : Target-selection source root with spell/item/object panes, three exact shared selection helpers, two externally linked mode bools and active SelectObject pointer required by UserPane, retained static TargetObject pointer, five saved-target definitions, exact MapPane highlight/traversal behavior, source/compiler distinctions, producer/consumer ownership, and historical static-linkage correction.
```

- Boundary: these are manual supervisor-owned coverage files. B003 did not edit them; generated refresh does not apply these rows, and any external application/validation/lifecycle state is not asserted or directed by this artifact.

## Follow-Up Actions

- External boundary: report validation, execution, count, path, movement, archival, and manual-coverage state are supervisor/validator-owned and are neither asserted nor directed by this artifact.
- A-agent actions: none requested.
- B003 actions: none remain. The accepted callback, serial registration, no-loss shared rebase, ordinary validation, final generated readback, report reconciliation, and lease cleanup are complete; B005 UID0003UB is Gate-1-failed and did not enter this settled union, while B002 broader shared work remains externally ordered after this callback.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: `94/100` for target/table/vtable, `93/100` for descriptive helper/flag names.
- Remaining uncertainty: original private lexical spellings, exact header split, and one legacy config field name; no behavior, range, owner, emitter, source-placement, type, return, packet, split, or formal-C++ blocker remains.

## Validator Results

- Every changed ordinary page received a scoped `--mode file --apply --queue-timeout 240` validation with `exit 0` and `ok:1`; each lease was released immediately after that page's edit/validator. Validator-managed projected-stat, registry, generated-C++, and generated-metadata effects are side effects, not manual B003 edits.

| Command ID | Timestamp | Scoped destination / purpose | Exit / ok | Result and side effects |
| --- | --- | --- | --- | --- |
| `000000012861` | `2026-07-15T04:53:57-04:00` | UID0003V9 validator-preserving rename/body | `0 / 1` | Preserved UID/range, applied R1 and metadata; generated refresh deferred. |
| `000000012863` | `2026-07-15T04:54:52-04:00` | UID0003VA validator-preserving rename/no-code | `0 / 1` | Preserved UID/range, applied compiler-only R3/metadata; generated refresh deferred. |
| `000000012865` | `2026-07-15T04:55:49-04:00` | UID0002YU vtable disposition | `0 / 1` | Applied R8 blank/non-reconstructable compiler disposition; generated refresh deferred. |
| `000000012866` | `2026-07-15T04:56:54-04:00` | UID0002A9 mode flags | `0 / 1` | Applied R9/linkage/score evidence; generated refresh deferred. |
| `000000012869` | `2026-07-15T04:58:30-04:00` | UID0002A2 singleton slots | `0 / 1` | Applied R12 and bounded linkage correction; generated refresh deferred. |
| `000000012870` | `2026-07-15T04:59:38-04:00` | register UID0004R3 / R4 | `0 / 1` | Validator issued UID0004R3 and registered the source child; generated refresh deferred. |
| `000000012872` | `2026-07-15T05:00:14-04:00` | register UID0004R4 / R5 | `0 / 1` | Validator issued UID0004R4 and registered the source child; generated refresh deferred. |
| `000000012873` | `2026-07-15T05:00:56-04:00` | register UID0004R5 / R6 | `0 / 1` | Validator issued UID0004R5 and registered the source child; generated refresh deferred. |
| `000000012874` | `2026-07-15T05:01:36-04:00` | register UID0004R6 / R7 | `0 / 1` | Validator issued UID0004R6 and registered the source child; generated refresh deferred. |
| `000000012876` | `2026-07-15T05:02:17-04:00` | register UID0004R7 / R10 | `0 / 1` | Validator issued UID0004R7 and registered the source child; generated refresh deferred. |
| `000000012877` | `2026-07-15T05:02:57-04:00` | register UID0004R8 / R11 | `0 / 1` | Validator issued UID0004R8 and registered the source child; generated refresh deferred. |
| `000000012881` | `2026-07-15T05:05:04-04:00` | UID0000OH TargetSelectionInputPanes file | `0 / 1` | Applied bounded helper/linkage/source-order union; generated refresh deferred. |
| `000000012902` | `2026-07-15T06:16:07-04:00` | UID0000FQ initial shared class rebase | `0 / 1` | Preserved settled B001/B004/B005/B004-UN union and current UID0004R9; generated refresh deferred. |
| `000000012903` | `2026-07-15T06:17:15-04:00` | UID0000P1 shared file rebase | `0 / 1` | Applied B003 source/inventory prose on the settled union; generated refresh deferred. |
| `000000012905` | `2026-07-15T06:23:48-04:00` | UID0001KL parent R0/inventory | `0 / 1` | Applied exact R0, child/table/padding/source inventory; generated refresh deferred. |
| `000000012907` | `2026-07-15T06:26:04-04:00` | UID0001KM helper inventory | `0 / 1` | Replaced only B003 deferred-helper rows and preserved current B002/B004/B005/B001 content; generated refresh deferred. |
| `000000012909` | `2026-07-15T06:26:35-04:00` | intermediate waited UserPane checkpoint | `0 / 1` | Validator-owned generated readback before final R2 normalization; superseded by later exact checkpoints. |
| `000000012913` | `2026-07-15T06:31:02-04:00` | UID0000FQ exact R2 normalization | `0 / 1` | Exact R2 equality restored; incremental side effects included registry `4970/4006`, UserPane.cpp update, and generated metadata refresh. |
| `000000012914` | `2026-07-15T06:31:16-04:00` | historical waited settled-union checkpoint | `0 / 1` | Produced the prior valid generated snapshot; superseded only by bounded stale-prose repairs below. |
| `000000012919` | `2026-07-15T06:41:41-04:00` | UID0000FQ stale method-table repair | `0 / 1` | Replaced current blank/old-name claims with exact UID0003V9/R10/R11 state; five pre-existing missing-ref diagnostics, generated refresh deferred. |
| `000000012920` | `2026-07-15T06:42:37-04:00` | UID0000P1 stale policy/name repair | `0 / 1` | Historicalized blank/old-name policy and corrected current method references; 18 pre-existing missing-ref diagnostics, generated refresh deferred. |
| `000000012921` | `2026-07-15T06:42:50-04:00` | final waited `by-file/UserPane.md` refresh | `0 / 1` | Completed foreground refresh; registry `4970/4006`, 281 generated-metadata refreshes, projected stats update, 14 fallback/86 marker-missing/170 emitter-no-code broad diagnostics, and the same 18 legacy missing refs. None is UID0003V9/R0-R12-specific. |

- Final UserPane.cpp: command/header `12921` at `2026-07-15T06:42:50-04:00`, SHA256 `FE250BD4A142E035D768DAD8741658E28171134B46F5A1C93B1A7FE11C3A8044`, 2,691 lines, 89,918 bytes. `class UserPane` starts at line 128 and closes at line 278; B003 definitions begin later. UID0003V9 marker and `bool UserPane::HandleKeyOrTextEvent(Event *)` definition each occur once; UID0003V9 Empty Emitter Marker, `OnKeyEvent`, and `PaneKeyEvent` occur zero times. R10/R11 each define once; R4 has one prototype, one definition, and two calls. B001 `ProcessMovement`/`StartDirectionalAnimation`, B004 `ParseInventorySlotUpdatePacket`, B005 `ParsePlayerSettingsPacket`, B004-UN `HandleServerEntryPacket`, and current B002 UID0004R9 `FindGroupMemberById` each define once. All Empty Emitter Markers and handwritten switch/vtable/RTTI/cookie artifacts occur zero times.
- Final TargetSelectionInputPanes.cpp: command/header `12921` at `2026-07-15T06:42:50-04:00`, SHA256 `6D61F670C087ED62D1854BFE11F1FEE45CA1A5F6535D3778E25DA5B16619CF3B`, 1,273 lines, 46,165 bytes. R5/R6/R7 definitions each occur once; `g_selectObjectTargetModeActive`, `g_targetObjectTargetModeActive`, externally linked `g_activeSelectObjectWithKeyboardPane`, and static `s_activeTargetObjectWithKeyboardPane` definitions each occur once; Empty Emitter Markers occur zero times.
- Exact formal readback: R0-R12 each compare byte-for-byte equal between this report and the current destination managed block. Old UID0003V9/UID0003VA paths are absent, all six issued UIDs are linked, and no NEW-3V9 placeholder remains.

## Changed Files

- Assigned report updated in place: `tools/leaser/Agents/Agent-B003/research/0003V9-UserPaneHandleKeyEvent-source-quality.md`; its path is the historical B003 research/callback artifact location before external lifecycle handling.
- Validator-preserving renames: UID0003V9 to `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md` SHA256 `A05B897DEA2D8EC7FB0380BF09F88287477E0EDE22DCFF69D2D541D50B238824`; UID0003VA to `by-memory/0x005a7422-0x005a76c0.UserPaneHandleKeyOrTextEventSwitchTables.md` SHA256 `8365E55F34229632BCCD5A10E401D406380F4B77D8BD43E488F3BEC59F962F95`.
- Registered children: UID0004R3 `by-memory/0x005acf10-0x005acf5f.UserPaneSendOpcode7Command.md` SHA256 `C75ECC472F93544B3E65F07DDB1953FCF108A5331DBFC9ED24DF6DD94CB384DB`; UID0004R4 `...ToggleTargetSelectionPane.md` SHA256 `ECA780A1A97FD7E3A0402437F495CE6E6A87F3D8550251EC68C78279A090CDB6`; UID0004R5 `...NavigateTargetSelection.md` SHA256 `7674A1058C5CC777F259436CCF926C3D44E60D7E99AAF6CB5E65A61F3D1AD85C`; UID0004R6 `...ReverseTargetSelectionDirection.md` SHA256 `B2DA3D4C686605C56BED94AA11F0D18BA3CB146A1E6F863EED24C17383776B7E`; UID0004R7 `...UserPaneBuildInventorySlotRangeText.md` SHA256 `A3CB72F23F7E6642A8FF45740BC37CDF677A4ECD6BEAAD72D3E50ABF038953E1`; UID0004R8 `...UserPaneBuildSpellSlotRangeText.md` SHA256 `77B35C4334EE0812F43E66A879049472ADBC18E8C9C6CF28A24F37698C2EE9B7`.
- Modified metadata/support: `by-class/UserPane.md` SHA256 `240D351E5E52A53D186F179FD64F7A77F0FFA6826A221E5B7DD2455CC46A8C4E`; `by-file/UserPane.md` SHA256 `9339CE74F00516F841998035E2E037E0D97D63AAD6939D1DFD07AFEC9E6CC2B4`; `by-memory/0x005a2530-0x005b8395.UserPane.md` SHA256 `B33B0A0D428550542B60862B1C41777AD065937CDC023AB123DCDB8F3AB5094F`; `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` SHA256 `3D605188CC09FF1E2DA2A5F46FFA067028729D14614530A6CE84663A3451CD89`; `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md` SHA256 `CBB9852C20247DEB55B3386859C4514C63494B92E097702F32283035B2DE72BC`; `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md` SHA256 `DAE88037C85DCACCCEA259E82B56032E9B747D858C21383E18F171B571FDE9EA`; `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md` SHA256 `F2895916A2D8D68E4CB6047B5165CE394BBDABCFD91102F6AE13FA1664B5BABA`; `by-file/TargetSelectionInputPanes.md` SHA256 `63C25BD40ED121DC66BD2761828003DD6FD07404FE6796BF8AF20212E4032B50`.
- Verify-only/read-only current union: UID0003VB SHA256 `CBA235435FF71EF9DA524C2963D96AC517B184239B67AB74E97BCB9A8EC113D0`; B002-owned UID0004R9 SHA256 `B235402B414AB2345F09A46F7C637AE35B285AB4FB0139445653562599BD1092`. Neither was edited or validated by B003.
- Restricted/read-only files changed: none.
- Validator-owned side effects only: generated C++, generated metadata/tracker projections, registry, and projected stats changed through authorized validator commands; B003 did not edit those files manually.
- Leases: short serial leases were used only for the ordinary page being edited and were released after its scoped validator. The MCP-pause UID0001KL lease held no edit and was released without validation. Final `tools/leaser/Agents/current_leases.md` has zero B003 entries.
- Report execution: not run. No execute/probe/count/revalidation/lifecycle/move/archive command was run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 validation preceded implementation.
- [x] Target/support destinations updated: UID0003V9, UID0003VA, UID0000FQ, UID0000P1, UID0001KL, UID0001KM, UID0002YU, UID0002A9, UID0002A2, UID0000OH, and six validator-registered children.
- [x] Historical and implemented target states plus actual evidence are recorded.
- [x] Claim And Incorporation Ledger has legal terminal action/state enums and claim-specific proof for C01-C20.
- [x] Metadata/scores applied: target `92/94`, table/vtable `90/94`, class `93/94`, file `92/93`, parent `91/93`, flags `91/93`, six children `90/93`, UID0000OH unchanged.
- [x] Score-limiting blockers were researched to resolution; remaining private lexical uncertainty is explicitly capped.
- [x] Owner/emitter/reconstructable dispositions applied: target FQ/FQ/true; compiler table none/blank/false; vtable semantic FQ/blank/false; children/routes exactly as reported.
- [x] Split/rename/new-child work completed: two UID-preserving renames and six serial validator registrations UID0004R3-UID0004R8.
- [x] Source placement, range/split/padding/reclassification, and IDA rename/type/comment recommendations are applied or documented not applicable.
- [x] R0-R12 are applied exactly and current managed blocks compare byte-for-byte equal to this report.
- [x] Third-party import directive is not applicable; no `third_party_embeds/...` path is involved and every body follows its source/no-code disposition.
- [x] Exact target/support facts are incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence remain preserved.
- [x] Wave2/Wave3 mentions remain ignored/rejected unless independently revalidated.
- [x] Open questions are closed or bounded to evidence-backed lexical uncertainty.
- [x] Every changed/new ordinary page received scoped validation and final waited command 12921 completed.
- [x] Generated readback and exact manual supervisor-owned coverage handoff text are recorded.
- [x] Collision inventory reread executed B001 UID0003U8, B004 UID0003UM/UID0003UN, B005 UID0003UL, accepted B002 UID0003UW/current UID0004R9, shared destinations, generated routes, and manual overlaps; failed B005 UID0003UB was excluded.
- [x] Shared callbacks/leases cleared before R0/R2 edits; every shared report/destination was reread before its one-file lease/edit.
- [x] Full B001 signed-char/signed-duration/table/event-20/map-refresh, B004 opcode-0x0f record/write-order and opcode-0x05 server-entry, B005 opcode-0x08 settings/index/order, current B002 UID0004R9, and unrelated current content are preserved.
- [x] R0/R2 and UID0000FQ/UID0000P1/UID0001KL/UID0001KM were rebased rather than applied from stale snapshots.
- [x] Full-union UID0000FQ/UID0000P1 manual coverage text was rebased after the executed B004-UN artifact/current rows were reread; B003 did not edit coverage.
- [x] Callback proof records C01-C20 destinations, command IDs/timestamps/exits/ok/side effects, generated headers/hashes, and lease release.

Implementation callback pass:
- [x] Exact report SHA `27F8A66148AD58196826C6CEE73257F0BA82C82E0CCAFDC9DD198CFB89ACF351` was accepted by the supervisor before implementation.
- [x] Shared gate cleared and accepted/executed B001/B002/B004/B005 artifact state was recorded before shared edits; failed B005 UID0003UB did not block or enter the union.
- [x] R0/R2 and each shared UserPane class/file/aggregate destination were reread under lease and rebased without loss.
- [x] All accepted target/support details are incorporated at report-level depth.
- [x] C01-C20 each has a legal terminal state plus exact implementation proof.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes are applied exactly; verify-only exclusions have reasons.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Open questions are resolved or retain exact evidence-backed lexical caps.
- [x] UID0004R3-UID0004R8 replaced every NEW-3V9 placeholder before dependent validation.
- [x] Validator IDs/timestamps/exits/ok/warnings/side effects are recorded through final command 12921.
- [x] Generated refresh completed with exact source order/count/no-marker/no-raw-compiler assertions.
- [x] Final waited command 12921 proves B001/B004/B005/B004-UN/current B002 UID0004R9 and B003 definitions each once where expected.
- [x] Manual supervisor-owned coverage text is retained as an external handoff; B003 edited no coverage file.
- [x] Every edit lease was released immediately after validation; final lease ledger has zero B003 entries.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000012933","destination_path":"executed-b-agent-research/B003/0003V9-UserPaneHandleKeyEvent-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003V9-UserPaneHandleKeyEvent-source-quality.md","timestamp":"2026-07-15T07:06:51-04:00","uid":"0003V9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
