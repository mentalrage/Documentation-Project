** TARGET-REPORT-UID:00037S **
** TARGET-REPORT-ADDITIONAL-UIDS:0004YB,0004YC **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00037S MapPane Mouse Event Core Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:00037S] as the complete source definition of `bool MapPane::HandlePointerOrMouseEvent(Event *event)` in `MapPane.cpp`, owned and emitted through [UID:00007Q] `MapPane` and source root [UID:0000L3] `MapPane`.
- Final disposition: keep the exact page range `0x00507150-0x00507c90`; the source method body ends at `0x00507c72`, while `0x00507c72-0x00507c74` is compiler alignment and `0x00507c74-0x00507c90` is the seven-entry compiler switch table. Neither tail subrange is a separate handwritten source item.
- Applied callback state: supervisor Gate 1 passed exact report SHA `BBD037DC063727153D41FF193DD36B0563C99A5387545C67DFCA4FC8DC052AF3`; B009 populated the target formal CPP, retained blank target H, raised `85/89 -> 93/94`, registered additional targets UID0004YB then UID0004YC, applied all accepted ordinary support/formal/API/history claims, and validated every changed ordinary document serially with generated refresh disabled. The first supervisor Gate 2B attempt failed closed because packed declarations shrank MapPane/Event; that unsaved session was discarded. The retry from restored session/database `1da2b2ae` completed under supervisor catalog entry `0355`: all six function name/type/FR/FP actions, both MapPane regions, Event byte/gap layout, both request-time globals, and every protected no-change readback were applied or verified, then the IDB was saved. The supervisor subsequently applied the 30 staged manual-coverage decisions and ran generated closure command `19152`; that command exposed duplicate `RequestObjectInfo(unsigned int objectId);` declarations in generated `MapPane.h` at lines 58 and 369. B009 repaired the single ownership defect by retaining the declaration in UID00007Q H, blanking UID0003TU H, and validating UID0003TU with command `19154` while generated refresh remained disabled. The supervisor then applied the exact UID0003TU corrective manual row and command `19201` closed generated output with one UID00007Q header declaration, no UID0003TU header emission, one UID0003TU CPP definition, all three primary/additional formal outputs current, and no target empty marker. Ordinary implementation, catalog-`0355` Gate 2B, manual coverage, and generated topology are complete. The body intentionally makes no current Gate 1, Gate 2A, execution, or archive claim; the report's current path plus validator-owned `VALIDATOR-REPORT-HISTORY` and status metadata are authoritative. Commands `19226` and `19227` are retained only as historical repair-cycle facts: `19226` executed the then-current artifact, and `19227` immediately invalidated/de-executed it after archived-artifact review found stale lifecycle prose.
- Exact ledger identity: the current Claim And Incorporation Ledger contains 85 actual atomic claim rows and 85 unique claim IDs. This count excludes the ledger header/separator and every unrelated table, including Validator Results; the C19 data correction replaced two prior rows with four independently verifiable rows, and the manual-coverage preflight changed C38K from no-change to replacement plus added C38Y/C38Z for the two newly proved stale RightButtonMenu rows.
- Confidence: very strong for behavior, event values, ABI normalization, owner, range, tail, helper roles, and field offsets; strong for the inferred human source lexemes used where original symbols were stripped.

## Supporting Research

- This artifact began as the report-only pass, passed Gate 1 at the exact SHA above, and then received the accepted same-B ordinary implementation callback. It records ordinary document creation/implementation and scoped validation. B009 performed no IDA mutation. The supervisor discarded the first packed-UDT attempt unsaved, then completed the corrected Gate 2B transaction under catalog entry `0355` and saved the IDB. The supervisor later applied manual coverage and ran generated command `19152`; B009 did not edit coverage or generated output. Command `19152` is retained as the failed-closure diagnostic that exposed the duplicate UID0003TU/UID00007Q header declaration. After the UID0003TU repair, supervisor command `19201` supplied the successful generated-closure checkpoint, and the current manual UID0003TU row is literal-equal to the staged corrective payload. Historical commands `19226`/`19227` record one execution followed by immediate invalidation/de-execution for this body repair; they do not establish current lifecycle state. The body deliberately defers current execution/archive truth to the report path and validator-owned history/status metadata.
- Live IDA MCP database session `5a570ede` was available and used read-only against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; the retained session reported analysis idle. The earlier exact-artifact self-audit used MCP transport session `cc8ba0cd-510a-4bf5-93a9-a56cc00f775d`; bounded function, entity, xref, byte, decompile, table, type, comment, and neighboring-range checks succeeded. The additive data-prestate repair used read-only transport `d9cafb48-5a00-485a-b61e-4b20a3afee10`. Restored session/database `1da2b2ae` supplied the clean retry base and remains the saved poststate database identity. Supervisor catalog entry `0355` records backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B009-UID00037S-retry-20260729-091024.i64` SHA256 `6D20767D448CC568508E462790D05678838216C6CFEE77E3CFF5C4B5905244AB`; saved IDB SHA256 is `C302B5A83E41917EA7517D3783E428804F05DEED797CFC842D6DAEAB27EED0F9`, size `143190470`, last write `2026-07-29T09:22:18.9918289-04:00`.
- The research reconciles the current target, [UID:00007Q] `MapPane`, [UID:0000L3] `MapPane`, [UID:00009S] `ObjectStatusBlob`, [UID:00007B] `LivingObjectPane`, [UID:00009P] `ObjectInfoObjectPane`, [UID:0000C0] `RightButtonMenuPane`, [UID:0004F9] `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md`, [UID:0000N7] `RightButtonMenuPane`, [UID:0000CB] `ScreenPane`, [UID:00042I], [UID:00042F], [UID:0003ZS], [UID:0003TK], [UID:0003TL], [UID:0003TU], [UID:0003TV], [UID:00039X], the accepted Event declaration, map dimension globals, generated MapPane output, the research tracker, and the current manual by-memory coverage rows.
- Earlier report-only repair states are superseded by this exact artifact; they made no ordinary documentation, validator, coverage, generated, IDA, execution, or archive change. Any older target text saying constants, fields, or tail shape remain unresolved is historical input to this research, not the current report conclusion.

## Target

- Target UID: `00037S`.
- Additional target UIDs: [UID:0004YB] `by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md` and [UID:0004YC] `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md`, allocated by serial scoped validator commands `18866` and `18867` in that exact order and read from each validated first line.
- Declared-target inventory: primary [UID:00037S] exact MapPane virtual pointer/mouse callback plus compiler support tail; additional [UID:0004YB] exact MapPane item-object hit test; additional [UID:0004YC] exact externally linked UserPane.cpp local-player status request helper. The report header, inventory, ledger, checklist, and staged manual rows now use those actual UIDs.
- Target path: `source-3/project-documentation/by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md`.
- Source queue/report row: dated report-time `auto-generated/-ag-research-tracker.md` state was target `85/89`, reconstructable, zero direct B reports. It is historical because generated refresh was intentionally disabled during this callback.
- Current ordinary classification: source-complete reconstructable by-memory implementation at `93/94`; command `19201` closed the generated/formal topology. Direct-report lifecycle classification is intentionally omitted from the body and is authoritative only from the current report path plus validator-owned history/status metadata.
- Current scores and parent state: `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, populated CPP and blank H. Additional UIDs 0004YB/0004YC are each `92/94` with their validated owner/emitter routes.

## Current Target State

- Existing metadata correctly identifies the class owner, emitter route, reconstructability, and attachability. No owner or emitter transfer is needed.
- Existing prose correctly identifies a large MapPane mouse-event core, the EventHandler secondary-facet receiver, and four calls to [UID:00042I], but it stops before resolving the full source state machine.
- The target formal CPP now contains the dependency-closed method body and source-local `RequestLookAtMapPosition` declaration; target H remains blank because UID00007Q owns the one virtual declaration. Generated command `19152` confirmed real UID00037S/UID0004YB/UID0004YC bodies but also exposed duplicate `RequestObjectInfo` declarations in `MapPane.h`; UID0003TU now has a blank H channel and UID00007Q remains the sole declaration owner. Command `19201` then proved the repaired topology: one UID00007Q global declaration, zero UID0003TU header markers/declarations, one UID0003TU CPP definition, current primary/additional formal outputs, and no target empty markers. Later generated commands may advance physical headers/hashes; lifecycle-time readback remains authoritative.
- Historical blockers now resolved: exact EventType values and pointer payload layout; cursor resource values and their compile-visible declaration; `LivingObjectPane::m_terminalAnimation`; established `SetHighlightState(bool)`; exact `RightButtonMenuPane::SetTargetNameAndId(int,const wchar_t *)` argument order; selection, hover, action, and tracking fields; living/item hit-result types; EventHandler-facet normalization; all four UID00042I paths; UID0003TK/TL queued-input cleanup; UID0003TU/TV and `0x005a4f70` source/API migrations; UID0004F9's stale object-info alias and blank formal route; the compile-visible `RequestObjectInfo` route from `RightButtonMenuPane.cpp`; method/tail boundary; jump-table entries; owner/source placement; and dependency-complete CPP/H disposition.
- Current report artifact state: the earlier Gate 1 pass authorized the completed ordinary callback. Two children were created/registered, all accepted ordinary target/support changes were applied, and serial scoped validation passed. The failed packed-UDT attempt remains historical unsaved evidence only. Supervisor catalog entry `0355` applied and saved the corrected IDA poststate from session/database `1da2b2ae`, including exact gap-guarded MapPane/Event layouts, all six function actions, both semantic globals, protected-entity readback, and bounded frame-display normalization. B009 reconciled the five ordinary pages that still described historical IDA prestates and validated them serially as commands `19039`-`19043` with generated refresh disabled. The supervisor applied the original 30-decision manual-coverage plan; generated command `19152` then exposed the one duplicate header declaration. UID0003TU now emits only its CPP definition, UID00007Q emits the sole `MapPane.h` declaration, and command `19154` validates the repaired ordinary page with generated refresh disabled. The exact UID0003TU corrective manual row is now applied, and command `19201` completed generated closure. Gate 2B mutation, all authorized ordinary edits, manual coverage, and generated closure are complete. The body intentionally asserts neither pending nor completed status for current Gate 1, Gate 2A, execution, or archive lifecycle; the current path and validator-owned history/status metadata control that truth.

## Executive Recommendation

- Name the method `MapPane::HandlePointerOrMouseEvent(Event *event)`. It occupies the MapPane EventHandler mouse-family slot and receives the EventHandler facet at complete-object offset `+0xa0`; the source signature uses a normal `MapPane *this`, not explicit subtraction.
- Preserve direct parent [UID:00007Q], source owner [UID:0000L3], and the single exact range. Do not split the NOP or jump table into source emitters.
- Replace raw values with existing `EventType` values, shared ScreenPane cursor constants, and a MapPane action-state enum. Replace stale aggregate field labels with the exact input/action fields established by the target and timer consumer.
- Enter the method body in the target CPP block. Keep the target H block blank because the class H emitter already declares this virtual. Place required shared/private enum, helper declarations, and field-layout corrections in [UID:00007Q], not in the target H block.

## Supervisor Active Recheck

- The active assignment requires a report-only source-quality investigation of UID00037S, use of live IDA MCP, the literal 33-section template, and resolution rather than repetition of all named blockers.
- Split repair is not required. The source body is one modeled function; its retained tail is compiler support for that same source switch and must remain in the coverage envelope without becoming a second source item.
- The only source-bearing item in the assigned range is the method at `0x00507150-0x00507c72`. The two-byte alignment and seven-dword table are completely classified and require no child creation.
- During report-only research no project file was edited. During the accepted callback B009 edited only the ordinary by-* destinations listed under Changed Files and this same report; it did not edit generated, coverage, supervisor/audit/catalog/lifecycle, IDA, or executed-archive state. The supervisor, not B009, later performed and saved catalog-`0355` IDA work.
- The earlier exact-artifact Gate 1 self-audit rechecked all 33 required/triggered sections and repaired only this report before acceptance. The callback then preserved those conclusions while applying the ordinary portion of the ledger. The data-prestate correction atomized the two data actions into four independently verifiable rows, bringing the ledger to 83 rows. The read-only manual-coverage preflight then converted C38K to the correct UID00034O replacement and added C38Y/C38Z for UID0000C0/UID0000N7, bringing the ledger to 85 rows. Catalog `0355` closes every supervisor-owned IDA row. Generated command `19152` supplied the final narrow declaration-ownership defect; C10A/C10D/C38D express the single-owner repair without changing the 85-row count. The corrective C38D row and command `19201` generated closure are applied. Commands `19226`/`19227` form a historical execute-then-invalidate repair cycle; current gate and lifecycle state is deliberately not inferred from that history or asserted in this body.

## Inference Research Guidance Check

- Binary facts, documentation facts, and source inference are kept distinct. Addresses, values, offsets, control flow, calls, table entries, and xrefs are direct IDA facts. Existing class names and accepted APIs are documentation facts. Stripped lexical names are explicitly described as best source-facing inference.
- Existing target uncertainty was not treated as authoritative. Each listed blocker was rechecked against live decompilation/disassembly, helper bodies, callers, related class layouts, Event producers, timer behavior, and adjacent ranges.
- `by-structure.md` principles require exact coverage boundaries while excluding compiler alignment/table material from handwritten code. They also require method definitions on the exact by-memory child and declarations/layout on the class emitter.
- Any Wave2/Wave3 terminology encountered in older documentation is stale and was ignored. No recommendation depends on those workflows.
- Inferred names avoid `sub_`, `dword_`, raw offsets, shifted-pointer syntax, opcode-only names in the target body, or decompiler temporaries. Behavior takes priority over lexical consistency; human-looking source and project-wide naming consistency follow.

## Heuristic / Inference Reanalysis And Validation

| Issue | Resolution | Basis | Classification |
| --- | --- | --- | --- |
| Method identity | `bool MapPane::HandlePointerOrMouseEvent(Event *event)` | MapPane vtable slot, adjacent MapPane event methods, existing class declaration, complete-object offset `+0xa0` | Direct plus established documentation |
| Event constants | Cursor move `0`, left down/double/up `1/2/3`, right down/double/up `4/5/6`, wheel `7` | Accepted `EventType`; seven-entry switch indexes `0..6`; default handles double-click and wheel as false | Direct |
| Event payload | byte `m_type`; `m_y`, `m_x`, `m_modifiers`, `m_detail`, `m_messageTime` | Accepted source `Event` has `unsigned char m_type +4` with natural alignment to payload `+8`; accepted `EventPointerPayload` offsets are `+8/+c/+10/+14/+18`; live target reads the discriminator as one byte | Direct |
| Cursor values | normal/select/view/put/attack = `7/8/9/10/11` | UID00039X loader order and ScreenPane 12-handle cursor array | Direct values; shared enum placement inferred |
| Living hit helper | `FindObjectAtMapPoint(int y, int x)` returns `LivingObjectPane *` | `0x50c470` row-bucket reverse scan, bounds test, existing MapPane declaration | Direct role and accepted name |
| Item hit helper | `FindItemObjectAtMapPoint(int y, int x)` returns `ObjectPane *` | `0x50c550` reverse item-list scan, target-only callers | Direct role; inferred source name |
| Object action state | values `5`, `6`, `11`, `12`, `14`, `15` become `MapActionState` constants | `ObjectStatusBlob::m_actionState` branches and timer consumption | Direct values; inferred human lexemes |
| Hover field | `+0x3ec` is `m_hoveredObjectId` | Compared with hit object's `m_objectId`, used for ObjectList lookup and old nameplate clearing | Direct role; inferred lexeme |
| Pointer snapshot | `+0x3a0..+0x3b7` are Y/X/modifier/detail/time/byte-type fields with natural alignment gaps `+0x3a9..+0x3ab` and `+0x3b5..+0x3b7` | Repeated byte/dword copies from the Event pointer payload and later input/timer consumption | Direct layout; inferred lexemes |
| Action fields | `+0x8e8..+0x90f` are right/left tracking, map row/column, pixel target/start points, state, id, modifier | Exact writes in mouse callback and exact reads/clears in UID0003ZS and `0x510960` | Direct layout; inferred lexemes |
| `+0x90c/+0x90e` stale meaning | right/left button tracking, not deferred rendering flags | This method sets/clears them as button state; `0x510960` clears each around input-state reset | Direct contradiction of stale docs |
| Object packet helper | `void __stdcall RequestObjectInfo(objectId)` | `0x50f4d0` emits `{0x43,1,BE32 id}`; MapPane action paths and RightButtonMenu `Info` case 4 are the complete three-callsite set; terminal `retn 4` proves callee cleanup | Direct behavior, ABI, and UI intent; source name inferred with high probability |
| Coordinate packet helper | `static void __stdcall RequestLookAtMapPosition(column,row)` | `0x50f9c0` emits `{0x0a,BE16 column,BE16 row}`; both callers are inside the click-look right-button path after object/item map-position resolution; terminal `retn 8` proves callee cleanup | Direct behavior, ABI, and call-path intent; source name inferred with high probability |
| Shared opcode-2d helper | `void __stdcall RequestLocalPlayerStatus(requestTime)` | `0x5a4f70` emits `{0x2d,0}`, then stores the request time in the active EPF/legacy slot; Icons action 2 passes zero, retained raw Icons action 2 passes zero, Tab action 0 passes the exact `EventKeyPayload::m_messageTime` overlay at `event+0x10c`, MapPane local-player look passes `EventPointerPayload::m_messageTime` at `event+0x18`, and UserPane key `s` contains the inline equivalent; terminal `retn 4` proves callee cleanup | Direct packet/storage behavior and ABI plus four independent UI intents; source/API migration accepted with high probability; the two Event overlay offsets must not be normalized to one another |
| Opcode-2d storage | `g_epfLocalPlayerStatusRequestTime` and `g_legacyLocalPlayerStatusRequestTime` | `0x69bf6c/0x69bf70` receive only the helper/inline request-time writes selected by `g_useEpfAssets` | Direct write partition; source names inferred from resolved request semantics |
| Living selection API | `SetHighlightState(bool)` and `m_terminalAnimation` | current LivingObjectPane declaration and live type layout; target checks complete-object `+0x1d0` before status use | Established API/type, replacing nonexistent `SetSelected` and false `m_objectStatus.m_invisible` |
| Right-menu target/API closure | `SetTargetNameAndId(objectId, name)` plus external `RequestObjectInfo(targetId)` in UID0004F9 | current setter declaration/call order, exact Info call at `0x00554ee3`, UID0003TU's three-caller external ABI, and stale `sub_50F4D0`/`MapPaneSendObjectAction43Packet` aliases in UID0000C0 and UID0004F9 | Established setter declaration and direct call order; deterministic support migration with a compile-visible `../../map/MapPane.h` include in `RightButtonMenuPane.cpp` |
| Right-click menu | Reuse or construct singleton, detach/unregister, attach/register, then set target name/id | Exact call order, existing class methods, global and layer-context docs | Direct behavior |
| Tail | two-byte `66 90` alignment plus seven-dword jump table | Item boundaries, table targets, next function at `0x507c90` | Direct compiler support |

Rejected alternatives:

- TimerHandler ownership is rejected: the raw receiver is the `MapPane+0xa0` EventHandler facet, while TimerHandler is another inherited facet used only by timer helper calls.
- `HitTestObjectAtPoint` as the `0x50c550` name is rejected because the established `FindObjectAtMapPoint` is the living-object scan and the second helper specifically scans item objects.
- `m_pendingMovementState`, `m_pendingMapStateToken`, `m_pendingActionModeActive`, `m_pendingActionTileX/Y`, `m_pendingActionState[20]`, and `m_deferred*SurfaceDirty` are rejected as current field meanings for this method. Exact complete-object replacements are `m_pointerEventY/X/modifiers/detail/messageTime/type` at `+0x3a0/+0x3a4/+0x3a8/+0x3ac/+0x3b0/+0x3b4`, with byte `m_pointerEventType` and compiler-natural gaps rather than named padding; `m_hoveredObjectId` at `+0x3ec`; `m_rightButtonMovePending` at `+0x8e8`; row/column at `+0x8ec/+0x8f0`; pixel Y/X at `+0x8f4/+0x8f8`; action-start Y/X at `+0x8fc/+0x900`; state/id/modifier at `+0x904/+0x908/+0x90d`; and right/left tracking at `+0x90c/+0x90e` with implicit tail padding at `+0x90f`.
- `SendObjectActionPacket`, `SendMapCoordinateActionPacket`, `SendLocalPlayerCommandRequest`, `SendOpcode2DAndStoreExtra`, and the two `g_opcode2d*` labels remain historical/search aliases only. They are rejected from accepted formal source because live caller intent now supports the semantic APIs and request-time globals above.
- Separate source items for the NOP or jump table are rejected because neither has a source-level address route or independent semantics.
- Raw opcode-bearing names are retained only as historical search aliases in support docs. The target body uses human semantic names.
- Explicit `this - 0xa0`, manual vtable calls, raw object offsets, or assembly labels are rejected from formal source.

## Evidence Standards Used

- Highest-weight evidence: live IDA MCP function boundaries, decompilation, disassembly, bytes, code/data items, xrefs, vtable entries, helper bodies, and adjacent modeled functions.
- Corroborating evidence: accepted Event/ObjectStatusBlob/MapPane/ObjectList/ScreenPane/RightButtonMenu/ObjectInfo docs, exact by-memory helper pages, generated output, manual coverage, and tracker state.
- Negative evidence: no ordinary direct caller besides the vtable data reference; no independent tail route; no start pointer outside the MapPane vtable; no source need for a shifted receiver; no source declaration need in the child H block.
- The evidence is sufficient for `93/94`, but not a `95/95+` final-audit score because stripped private lexemes remain inference-backed rather than symbol-proven, the full MapPane tail cannot yet be represented transactionally in IDA, and implementation/compile validation belongs to the later callback.

## Evidence Checked

- IDA MCP/manual checks: `idb_list`; target/function entity lookup and analysis; target decompilation/disassembly; xrefs to `0x507150`, target interior calls, tail start, jump table, and successor; bytes and item boundaries at `0x507c71-0x507c90`; vtable cells around `0x61e76c`; helper analyses for `0x505cc0`, `0x50c470`, `0x50c550`, `0x50f4d0`, `0x50f9c0`, `0x5a4f70`, `0x53a8c0`, and `0x510960`; current function/type/comment prestate; MapPane UDT members.
- Documentation checks: target; MapPane class/file; Event; ObjectStatusBlob; LivingObjectPane; ObjectInfoObjectPane; ObjectList and UID0001D2; RightButtonMenuPane class UID0000C0; RightButtonMenuPane file UID0000N7; exact OnEvent child UID0004F9 at `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md`; ScreenPane; Config; MainUiLayerSlots; map tile dimensions; UID00039X; UID00042F; UID00042I; UID0003ZS; UID0003TK; UID0003TL; UID0003TU; UID0003TV; UID00030A; Icons UID0002T2/UID00022Q; TabPane UID00034O; UserPane UID0003V9; and the exact current UID00037Y/UID0001KO/manual-coverage rows.
- Prior-report search: searched central executed and archived B-report stores with `00037S`, `[UID:00037S]`, exact range `0x00507150-0x00507c90`, `MapPaneMouseEventCore`, `sub_507150`, and `HandlePointerOrMouseEvent`. No earlier direct UID00037S target report exists. The relevant executed matches were B005 `00042I-MapPaneClearPendingActionPoll-source-quality.md`, which supplied the historical four-callsite/`85/89` support state, and B001 `B001-MEMTOOL-00506970-MapPaneInputPacketRenderCore.md`, which supplied aggregate route/emitter context; both were treated as leads and revalidated against live IDA/current docs rather than copied as current authority.
- Generated/state checks: `auto-generated/NexusTK/map/MapPane.cpp`, `MapPane.h`, `auto-generated/-ag-research-tracker.md`, and current manual `by-memory/-coverage-report.md` row.
- Negative checks: target has one vtable data xref and no ordinary start caller; `0x507c72` is not code; `0x507c74` is a compiler jump table; `0x507c90` is a separate packet callback; target H declaration is already supplied once by the class emitter.
- Failed/unavailable checks: none. Original PDB/source symbols do not exist in the current evidence set; this is loss of lexical proof, not an uninvestigated behavior blocker.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 00037S | Replace the working role with exact source method `MapPane::HandlePointerOrMouseEvent(Event *)` and add the complete body | Very strong | vtable, type, class declaration, body | target Status/Behavior/CPP | incorporate | applied |
| C02 | 00037S | Document compiler normalization of the raw MapPane EventHandler facet receiver at `+0xa0` to an ordinary complete-object member call | Very strong | shifted sibling type, repeated `this-160`, vtable | target ABI section | incorporate | applied |
| C03 | 00037S | Incorporate EventType cases `0..7`, with 2/5/7 following the exact default-false path | Very strong | Event enum and jump table | target event matrix | incorporate | applied |
| C04 | 00037S | Incorporate exact unsigned-byte Event and MapPane pointer-snapshot discriminators, payload fields, and natural source alignment without source-visible padding members; class/IDA transactions remain independently owned by C24A and C40A, whose IDA-only declarations require explicit filler arrays to prevent parser packing | Very strong | accepted Event source, live byte reads/writes, exact offsets, failed packed-UDT attempt and restored session `1da2b2ae` | UID00037S target layout/CPP | incorporate | applied |
| C05 | 0000CB | Insert exactly one shared ScreenPane `CursorIndex` enum for normal/select/view/put/attack values `7..11`; this row is the sole active cursor-declaration claim formerly duplicated by C21/C31 | Very strong | UID00039X load order, ScreenPane storage, target writes | `by-class/ScreenPane.md` formal H/evidence | incorporate | applied |
| C06 | 00037S | Document the behavioral distinction between living scan `0x50c470` and item scan `0x50c550`; helper creation/declaration is tracked only by C17A/C17B | Very strong | both helper bodies and disjoint caller/result uses | target behavior/evidence | incorporate | applied |
| C07A | 00037S | Historicalize the stale aggregate `m_pendingMovementState[6]` and token interpretation in the target without duplicating C24A/C24B | Very strong | exact reads/writes and lookup | UID00037S historical assumptions | historicalize | applied |
| C07B | 00007Q | Historicalize the same stale aggregate/token interpretation in the MapPane class while C24A/C24B own the replacement members | Very strong | exact target writes and class layout | `by-class/MapPane.md` historical assumptions | historicalize | applied |
| C08A | 00037S | Historicalize the stale deferred-surface interpretation of the target tail without duplicating C24C | Very strong | target plus UID0003ZS/0x510960 | UID00037S historical assumptions | historicalize | applied |
| C08B | 00007Q | Historicalize the stale deferred-surface field interpretation in MapPane while C24C owns the replacement fields | Very strong | target plus UID0003ZS/0x510960 | `by-class/MapPane.md` historical assumptions | historicalize | applied |
| C08C | 0003ZS | Historicalize the stale deferred-surface interpretation in the timer child while C26 owns its field-name synchronization | Very strong | UID0003ZS/0x510960 consumers | UID0003ZS historical assumptions | historicalize | applied |
| C09 | 00037S | Preserve and expand the four UID00042I call paths at `0x507529/545/586/95b` | Very strong | direct call xrefs and decompile | target call-path section | incorporate | applied |
| C10A | 0003TU | Convert the exact helper to external `void __stdcall RequestObjectInfo(unsigned int objectId)`, preserve `{0x43,1,BE32 id}`, insert its sole CPP definition, keep this child H blank with explicit covered-by UID00007Q class-header reasoning, retain exact range/padding/history, and raise `86/89 -> 90/92` | Very strong | helper body, terminal `retn 4`, complete caller set, command `19152` duplicate generated declaration and command `19154` blank-H validation | UID0003TU CPP/blank-H/prose/metadata/history | incorporate | applied |
| C10B | 00037S | Migrate exactly the two target action callsites to `RequestObjectInfo(objectId)` without changing surrounding action behavior | Very strong | calls `0x5074ca/0x50750d` and helper ABI | target CPP/behavior | incorporate | applied |
| C10C | 0004F9 | Replace the exact stale Info-case alias at `0x00554ee3` with `RequestObjectInfo(m_targetId)` in `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md`, add the complete formal CPP payload below, blank H disposition, `EMITTER_UIDS:0000C0`, and `88/90 -> 92/94` while preserving every non-Info event/action path | Very strong | third cross-TU callsite, exact case-4 behavior, full child range, and resolved support APIs | UID0004F9 CPP/prose/metadata/history | incorporate | applied |
| C10D | 00007Q | Retain exactly one global-scope `MapPane.h` declaration for external `RequestObjectInfo` in UID00007Q H; do not make it a MapPane member, duplicate it from UID0003TU H, or duplicate the CPP definition | Very strong | cross-translation-unit caller set and command `19152` generated duplicate at lines 58/369 | `by-class/MapPane.md` H plus MapPane source-root declaration evidence | incorporate | applied |
| C11 | 00037S | Incorporate exact hover/nameplate sequence and right-menu lifecycle into behavior and formal CPP | Strong | target body and class methods | target behavior/CPP | incorporate | applied |
| C12 | 00037S | Reject unresolved-tail wording and document exact alignment plus seven-entry jump table | Very strong | bytes/items/targets | target range/history section | reject-stale | applied |
| C13 | 00037S | Retain existing owner/emitter 00007Q and source file 0000L3 without transfer | Very strong | class vtable, cluster, declaration | metadata/source placement | already-present | already-present |
| C14 | 00037S | Populate target CPP with the complete dependency-closed method body and retain blank target H because UID00007Q already declares the override; the one source-local helper declaration is owned only by C16B | Very strong | exact body and existing class declaration | target formal CPP/H blocks | incorporate | applied |
| C15 | 00037S | Update only target metadata from `85/89` to evidence-justified `93/94`; the corresponding manual-row action is tracked solely by C38A | Strong | all named semantic/formal blockers closed; remaining lexical/implementation cap | target metadata | incorporate | applied |
| C16A | 0003TV | Convert the exact helper to file-local `static void __stdcall RequestLookAtMapPosition(unsigned short column,unsigned short row)`, preserve `{0x0a,BE16 column,BE16 row}`, insert its sole later CPP definition with blank H, retain range/padding/history, and raise `86/89 -> 90/92` | Very strong | helper body, terminal `retn 8`, target-only caller set | UID0003TV CPP/prose/metadata/history | incorporate | applied |
| C16B | 00037S | Insert exactly one matching source-local prototype before UID00037S and migrate both click-look callsites to `RequestLookAtMapPosition(column,row)` | Very strong | calls `0x507765/0x5077a9`, emission order, static linkage | target CPP/behavior | incorporate | applied |
| C17A | [UID:0004YB] | Create the exact registration-ready `92/94` child payload below with complete CPP, blank H, direct MapPane owner/emitter, reverse `ObjectList::GetPrimaryCellList()` traversal, and validator-assigned UID | Very strong | exact helper body, UID0001D2 accessor, three target callers | `by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md` | incorporate | applied |
| C17B | 00007Q | Add exactly one `FindItemObjectAtMapPoint(int y,int x)` MapPane declaration and route the target's three calls through the child; do not duplicate the child body in the class page | Very strong | helper ABI/callers and class ownership | `by-class/MapPane.md` formal H/evidence | incorporate | applied |
| C17C | 0004PZ | Change only `Nested:4 -> 0` after the earlier-address item-hit child becomes the first exact child of UID00037Y; preserve all AllocateTileBuffer source, metadata, evidence, and manual-row text | Very strong | address order inside UID00037Y and current first-child nesting | UID0004PZ metadata/history | incorporate | applied |
| C17D | 00037Y | Add the validated item-hit child as the first exact source-bearing child in the MapPane tile/object-grid split index without changing the index's own metadata or emitter disposition | Very strong | exact containment and address order | UID00037Y child inventory/source disposition | incorporate | applied |
| C18A | [UID:0004YC] | Create the exact registration-ready `92/94` child payload below under UserPane source ownership with complete CPP/global-scope H, `{0x2d,0}` packet, EPF/legacy request-time write, full caller evidence, and validator-assigned UID | Very strong | packet/storage body, terminal `retn 4`, caller family | `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md` | incorporate | applied |
| C18B | 00037S | Migrate only the MapPane local-player-look call to `RequestLocalPlayerStatus(event->m_payload.m_pointer.m_messageTime)` from `event+0x18` while preserving surrounding hit/selection behavior | Very strong | target call `0x507721`, pointer-payload offset, helper ABI | target CPP/behavior | incorporate | applied |
| C18C | 0004US | Change only `Nested:4 -> 0` after the earlier-address RequestLocalPlayerStatus child becomes the first exact child of UID0001KO; preserve all EnsureNormalBulletinSession source, metadata, evidence, and manual-row text | Very strong | address order inside UID0001KO and current first-child nesting | UID0004US metadata/history | incorporate | applied |
| C18D | 0001KO | Add the validated RequestLocalPlayerStatus child as the first exact non-say source-bearing child in the mixed helper index without changing the index's NONE/FALSE/non-emitting disposition | Very strong | exact containment, address order, and UserPane source exclusion from say ownership | UID0001KO child inventory/source disposition | incorporate | applied |
| C19A1 | 00030A | Supervisor Gate2B materialization at `0x0069bf6c`: replace exactly the four undefined one-byte items headed by historical `unk_69BF6C` over `[0x69bf6c,0x69bf70)` with exactly one anonymous four-byte unsigned-int data item; apply no semantic rename or comments until the intermediate item/bytes/xrefs/fences readback succeeds | Very strong | historical `inspect_items` prestate, eight zero bytes, exact EPF-selected writes at `0x5a4fba/0x5a686f`, absent comments/named global; catalog `0355` intermediate/final readback | supervisor Gate2B materialization `0x0069bf6c` | incorporate | applied |
| C19A2 | 00030A | After C19A1 independently verified the new item, apply exact declaration/name `unsigned int g_epfLocalPlayerStatusRequestTime` and the exact regular/repeatable comments below; verify final type/name/comments without changing bytes, xrefs, `[0x69bf68,0x69bf6c)` lower fence, or the `0x69bf70` neighbor boundary | Very strong | exact helper/inline true-EPF write partition, zero initializer, historical proposed-name collision miss, successful C19A1 prerequisite, catalog `0355` final readback | supervisor Gate2B semantic data action `0x0069bf6c` | incorporate | applied |
| C19B1 | 00030A | Supervisor Gate2B materialization at `0x0069bf70`: replace exactly the four undefined one-byte items headed by historical `unk_69BF70` over `[0x69bf70,0x69bf74)` with exactly one anonymous four-byte unsigned-int data item; apply no semantic rename or comments until the intermediate item/bytes/xrefs/fences readback succeeds | Very strong | historical `inspect_items` prestate, eight zero bytes, exact legacy-selected writes at `0x5a4fff/0x5a68a4`, absent comments/named global; catalog `0355` intermediate/final readback | supervisor Gate2B materialization `0x0069bf70` | incorporate | applied |
| C19B2 | 00030A | After C19B1 independently verified the new item, apply exact declaration/name `unsigned int g_legacyLocalPlayerStatusRequestTime` and the exact regular/repeatable comments below; verify final type/name/comments without changing bytes, xrefs, the new `0x69bf6c` neighbor, or `g_lastFunctionKeyTick` at `0x69bf74` | Very strong | exact helper/inline false-EPF write partition, zero initializer, historical proposed-name collision miss, successful C19B1 prerequisite, catalog `0355` final readback | supervisor Gate2B semantic data action `0x0069bf70` | incorporate | applied |
| C20A | 0003TK | Replace only the stale UID0003TK two-stage/deferred-surface tail with the two exact EPF queued-input cleanup branches, retain `92/94`, and preserve the rejected interpretation as history | Very strong | exact `0x5108d0..0x510927` disassembly | UID0003TK CPP/prose/history | reject-stale | applied |
| C20B | 0003TL | Replace only the nonexistent deferred-surface helper/fields with exact waiting/status/tracking cleanup, retain `90/90`, and preserve the rejected interpretation as history | Very strong | exact `0x510e2d..0x510e84` disassembly | UID0003TL CPP/prose/history | reject-invalid | applied |
| C22 | 00037S | Replace invalid `SetSelected`/invisible target interpretations with established `SetHighlightState(bool)` and `m_terminalAnimation`; C37A independently records the LivingObjectPane no-change proof | Very strong | established declaration and live LivingObjectPane type | UID00037S behavior/CPP/history | reject-invalid | applied |
| C23 | 00037S | Correct the target's invalid right-menu argument order to `SetTargetNameAndId(objectId,name)`; C37B independently records the required RightButtonMenuPane alias/include migration | Very strong | current declaration and call ABI | UID00037S behavior/CPP/history | reject-invalid | applied |
| C24A | 00007Q | Replace only historical `m_pendingMovementState[6]` with the six exact source fields at `+0x3a0/+0x3a4/+0x3a8/+0x3ac/+0x3b0/+0x3b4`; preserve source-natural gaps `+0x3a9..+0x3ab` and `+0x3b5..+0x3b7`, with IDA-only `_gap3A9[3]`/`_gap3B5[3]` members preventing parser packing | Very strong | target byte/dword copies, 24-byte footprint, failed packed offsets `+0x3aa/+0x3ae/+0x3b2`, restored retry base and catalog `0355` exact 69-member/0x910 readback | `by-class/MapPane.md` declaration/evidence plus supervisor Gate2B poststate | incorporate | applied |
| C24B | 00007Q | Rename only historical `m_pendingMapStateToken +0x3ec` to `m_hoveredObjectId` with unchanged unsigned-dword width after C24A proves the member remains at `+0x3ec`, never the failed packed offset `+0x3e8` | Very strong | object-id compare/lookup/clear lifecycle and catalog `0355` exact `+0x3ec`/0x910 readback | `by-class/MapPane.md` declaration/evidence plus supervisor Gate2B poststate | incorporate | applied |
| C24C | 00007Q | Replace only the provisional `+0x8e8..+0x90f` source fields with the exact action/tracking fields and natural padding from the formal H payload | Very strong | target plus UID0003ZS/0x510960 reads/writes | `by-class/MapPane.md` declaration/evidence | incorporate | applied |
| C24D | 00007Q | Insert the exact `MapActionState` source enum values `5/6/11/12/14/15` once in the MapPane declaration | Very strong | target state writes/switch comparisons and timer consumers | `by-class/MapPane.md` formal H | incorporate | applied |
| C24E | 00007Q | Insert the exact item-hit member declaration once; implementation ownership remains solely C17A | Very strong | helper ABI and three target callers | `by-class/MapPane.md` formal H | incorporate | applied |
| C24F | 00007Q | Preserve MapPane size `0x910`, the existing override, and every unrelated declaration/member while applying C24A-E; abort and discard the unsaved transaction if any readback shows size `0x90c`, shifted `+0x3aa/+0x3ae/+0x3b2/+0x3e8` members, or any other offset drift | Very strong | current class layout, bounded target scope, failed packed attempt, restored session `1da2b2ae` | `by-class/MapPane.md` layout/history | already-present | already-present |
| C26 | 0003ZS | Synchronize UID0003ZS to the same exact action/tracking field names while retaining independently justified `89/91` | Very strong | timer body and target writes | UID0003ZS fields/prose/formal | incorporate | applied |
| C34A | 0002T2 | Migrate only the IconsPane action-2 call to `RequestLocalPlayerStatus(0)`, preserving `89/91` and all unrelated icon actions | Very strong | exact action case and shared helper body | UID0002T2 formal/prose/history | incorporate | applied |
| C34B | 00022Q | Migrate only the retained raw old-HUD action-2 call to `RequestLocalPlayerStatus(0)`, preserving `88/90`, raw-body status, and all unrelated cases | Very strong | exact action case and shared helper body | UID00022Q formal/prose/history | incorporate | applied |
| C34C | 00034O | Migrate only the TabPane action-0 call to `RequestLocalPlayerStatus(event->m_payload.m_key.m_messageTime)` using the exact `event+0x10c` overlay, never zero and never the pointer payload at `+0x18`; preserve `92/94` and all unrelated tab actions | Very strong | exact `0x4cfa61` call argument load from `+0x10c`, current UID00034O formal, shared helper ABI | UID00034O formal/prose/history | incorporate | applied |
| C35A | 0003V9 | Replace opcode-derived request-time names with the semantic EPF/legacy names in UID0003V9 while preserving raw aliases, `92/94`, and the intentionally inline key-`s` packet/store body rather than replacing it with a helper call | Very strong | inline packet/store duplicate and exact key-event message-time source | UID0003V9 formal/prose/history | incorporate | applied |
| C35B | 0000FQ | Synchronize UserPane class support to `RequestLocalPlayerStatus` and the semantic globals without changing `94/95` or unrelated class contracts | Very strong | helper/caller/global ownership | `by-class/UserPane.md` formal/prose/history | incorporate | applied |
| C35C | 0000P1 | Synchronize UserPane file support to the helper/global source contract without changing `93/94` or unrelated file families | Very strong | UserPane.cpp ownership and cross-file callers | `by-file/UserPane.md` prose/history | incorporate | applied |
| C35D | 00030A | Replace both ordinary UID00030A CPP declarations with the exact unsigned semantic globals, preserve zero initialization, old labels as historical aliases, owner/emitter UID0000P1, and `88/90` | Very strong | exact four writes, `g_useEpfAssets` partition, zero-filled storage | UID00030A CPP/prose/metadata/history | incorporate | applied |
| C36 | 0000L3 | Add bounded MapPane source-root summary for target and exact helper/source contracts while retaining `92/92` and unrelated families | Very strong | owner/emitter and file cluster | `by-file/MapPane.md` source-contract prose | incorporate | applied |
| C37A | 00007B | LivingObjectPane already has exact `m_terminalAnimation` and `SetHighlightState(bool)` source declarations; record no-change and do not duplicate them | Very strong | current ordinary docs and live type | LivingObjectPane class support readback | already-present | already-present |
| C37B | 0000C0 | Preserve exact `SetTargetNameAndId(int,const wchar_t *)`, replace the stale row-4 `sub_50F4D0`/`MapPaneSendObjectAction43Packet` aliases with `RequestObjectInfo`, and add exactly one `#include "../../map/MapPane.h"` after `RightButtonMenuPane.h` so `RightButtonMenuPane.cpp` sees the external declaration without duplicating a definition | Very strong | current declaration/fields, historical stale class action row, cross-TU helper contract, and applied support readback | `by-class/RightButtonMenuPane.md` CPP scaffold/prose/history | incorporate | applied |
| C38A | 00037S | Replace the stale UID00037S manual by-memory row with the exact `93%` payload below | Very strong | historical stale row, accepted target recommendation, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38B | 0003TK | Replace the stale UID0003TK manual row with the exact queued-input-cleanup payload below | Very strong | historical stale row, C20A, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38C | 0003TL | Replace the stale UID0003TL manual row with the exact waiting/tracking-cleanup payload below | Very strong | historical stale row, C20B, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38D | 0003TU | Current manual row records complete formal CPP with blank child H covered by the sole UID00007Q `MapPane.h` declaration, not complete formal CPP/H | Very strong | current literal-equal row at line 2439, C10A/C10D, command `19152` duplicate proof, command `19154` ordinary blank-H validation, and command `19201` generated closure | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38E | 0003TV | Insert the exact UID0003TV manual row after UID0003TU and before UID0003TW | Very strong | historical row absence, exact address order, C16A, command 18871, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38F | 00030A | Replace the stale UID00030A manual row with the exact semantic-global payload below | Very strong | historical stale row, C19A1/C19A2/C19B1/C19B2, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38G | 0002T2 | Replace the stale UID0002T2 manual row with the exact action-2 API payload below | Very strong | historical stale row, C34A, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38H | 00022Q | Replace the stale UID00022Q manual row with the exact retained-raw action-2 payload below | Very strong | historical stale row, C34B, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38I | 00037Y | Preserve the exact current UID00037Y `87%` manual row quoted below unchanged while adding only actual child UID0004YB beneath it | Very strong | fresh exact manual-row inspection, child anchor, command 18866 UID readback | supervisor manual coverage no-change parent readback | already-present | already-present |
| C38J | 0001KO | Preserve the exact current UID0001KO `86%` manual row quoted below unchanged while adding only actual child UID0004YC beneath it | Very strong | fresh exact manual-row inspection, child anchor, command 18867 UID readback | supervisor manual coverage no-change parent readback | already-present | already-present |
| C38K | 00034O | Replace the stale UID00034O manual by-memory row in place with the exact `92%` payload below, correcting `preserved +0x10c overlay read` to the proved `event->m_payload.m_key.m_messageTime` argument passed to `RequestLocalPlayerStatus` for action 0 | Very strong | historical row between UID00034N/UID00034P, exact `0x4cfa61` load from `event+0x10c`, applied C34C formal, callback command 18875, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38L | 0003V9 | Preserve the inspected score-aligned UID0003V9 manual row unchanged | Very strong | fresh manual-row inspection | supervisor manual coverage no-change readback | already-present | already-present |
| C38M | 00042F | Preserve the inspected score-aligned UID00042F manual row unchanged | Very strong | fresh manual-row inspection | supervisor manual coverage no-change readback | already-present | already-present |
| C38N | 00042I | Preserve the inspected score-aligned UID00042I manual row unchanged | Very strong | fresh manual-row inspection | supervisor manual coverage no-change readback | already-present | already-present |
| C38O | 00007Q | Preserve the broad score-aligned MapPane class manual row unchanged | Very strong | fresh class manual-row inspection | supervisor class coverage no-change readback | already-present | already-present |
| C38P | 0000CB | Preserve the broad score-aligned ScreenPane class manual row unchanged | Very strong | fresh class manual-row inspection | supervisor class coverage no-change readback | already-present | already-present |
| C38Q | 00007B | Preserve the broad score-aligned LivingObjectPane class manual row unchanged | Very strong | fresh class manual-row inspection | supervisor class coverage no-change readback | already-present | already-present |
| C38R | 0004F9 | Insert the exact UID0004F9 `92%` manual by-memory row below after UID0004F8 and before the parent-closing ignored row | Very strong | historical row absence, exact parent anchors, C10C, command 18888, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38S | 00004L | Preserve the broad score-aligned Event class manual row unchanged | Very strong | fresh class manual-row inspection | supervisor class coverage no-change readback | already-present | already-present |
| C38T | 0000FQ | Preserve the broad score-aligned UserPane class manual row unchanged | Very strong | fresh class manual-row inspection | supervisor class coverage no-change readback | already-present | already-present |
| C38U | 0000L3 | Preserve the broad score-aligned MapPane file manual row unchanged | Very strong | fresh file manual-row inspection | supervisor file coverage no-change readback | already-present | already-present |
| C38V | 0000P1 | Preserve the broad score-aligned UserPane file manual row unchanged | Very strong | fresh file manual-row inspection | supervisor file coverage no-change readback | already-present | already-present |
| C38W | [UID:0004YB] | Actual UID `0004YB` was read from the validated child; insert the exact `92%` manual row described below | Very strong | exact child payload, command `18866`, historical row absence, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38X | [UID:0004YC] | Actual UID `0004YC` was read from the validated child; insert the exact `92%` manual row described below | Very strong | exact child payload, command `18867`, historical row absence, and current applied row | supervisor `by-memory/-coverage-report.md` | incorporate | applied |
| C38Y | 0000C0 | Replace the stale UID0000C0 class manual row in place with the exact `90%` payload below, preserving the class score/layout/source route while replacing the false `remaining constructor/OnEvent body work` statement with source-ready UID0004F9 OnEvent and constructor-only remaining body work | Very strong | historical class row between UID0000BZ/UID0000C1, applied UID0004F9/UID0000C0 callback, command 18889, and current applied row | supervisor `by-class/-coverage-report.md` | incorporate | applied |
| C38Z | 0000N7 | Replace the stale UID0000N7 file manual row in place with the exact `90%` payload below, preserving the file score/source union while replacing the false `remaining constructor/OnEvent body work` statement with source-complete UID0004F9 OnEvent and constructor-only remaining body work | Very strong | historical file row between UID0000N6/UID0000N8, applied UID0004F9/UID0000N7 callback, command 18890, and current applied row | supervisor `by-file/-coverage-report.md` | incorporate | applied |
| C39 | 00042F | Existing `ClearQueuedMapStateRefresh` CPP/declaration already matches exact target calls; preserve ordinary source without duplicate edit, while the separate manual-row no-change disposition remains solely C38M | Very strong | current UID00042F CPP/prose, MapPane declaration, live `0x505cc0` caller set | UID00042F ordinary no-change readback | already-present | already-present |
| C40A | 00004L | Reject historical IDA four-byte `EventType m_type`; transactionally install byte `m_type +0x4` plus IDA-only `_gap5[3] +0x5` so payload remains `+0x8` and UDT remains `0x110`; the failed packed payload `+0x6`/size `0x10e` remains rejected history | Very strong | accepted Event declaration, live target byte load, Event producers/classifiers, failed packed attempt, and catalog `0355` exact byte/gap/payload/0x110 readback | supervisor Gate2B Event UDT action | reject-stale | applied |
| C40B | 00004L | Preserve the already-correct ordinary Event source declaration and class metadata without duplicate edits | Very strong | current `by-class/Event.md` source and layout | `by-class/Event.md` ordinary no-change readback | already-present | already-present |

Deduplication is explicit: former C10/C29 is represented once by C10A-D; C16/C30 by C16A-B; C17/C25 by C17A-D; C18/C32 by C18A-D; former broad C19/C33 is atomized into per-address materialization/semantic IDA actions C19A1/C19A2/C19B1/C19B2 plus ordinary UID00030A source claim C35D; and C05/C21/C31 is represented once by C05. Former C27/C28 are folded into C20A/C20B. C04 is target-only while C24A and C40A own the class/IDA transactions; C07A-B and C08A-C each historicalize one destination; C22/C23 are target-only while C37A preserves LivingObjectPane and C37B owns the bounded RightButtonMenu ordinary migration; C38K owns only UID00034O manual coverage, C38Y owns only UID0000C0 class coverage, and C38Z owns only UID0000N7 file coverage; C40A/B separate IDA action from ordinary-doc no-change. C34 and C35 contain one independently verifiable destination per row rather than repeating C18/C19. No removed claim pair remains as a second active implementation claim.

Ledger vocabulary is literal. `applied` means either B009 implemented and validated the accepted ordinary destination during callback, the supervisor completed the specifically identified catalog-`0355` IDA destination, or the supervisor applied the exact manual-coverage destination; each row names its actor/destination. No ledger row remains `proposed`: the final C38D corrective row is literal-equal to current manual coverage. `already-present` means the current owner/API/source/coverage/protected state was independently inspected and required no edit. All implementation details remain in Claim, Evidence, Destination, formal-source, support-change, IDA, manual-coverage, and checklist sections.

The current ledger contains exactly 85 atomic claim rows and 85 unique claim IDs. The recount includes only `| C... |` data rows between this section's table header and the next H2 heading; it excludes the ledger header/separator and every unrelated table such as Validator Results. Every row has one real UID, one destination, one allowed Action value, and one allowed Verification state. Child-family rows use actual validator-assigned UIDs 0004YB and 0004YC; registration did not duplicate either child claim. Relative to the earlier 81-row state, the C19 atomization added two rows and the coverage-preflight C38Y/C38Z additions added two rows; C38K changed disposition in place rather than adding a duplicate UID00034O claim.

## Positive Evidence Summary

- `0x507150` is one 2850-byte MapPane virtual method with 146 basic blocks and cyclomatic complexity 91; the body is a complete pointer-event state machine rather than a helper fragment.
- The sole inbound route is MapPane vtable cell `0x61e76c`. Neighboring MapPane vtable slots and `MapPane::HandleSystemOrControlEvent` independently establish EventHandler facet normalization.
- Every handled event value agrees with the accepted Event enum and the seven-entry switch table.
- Exact helper bodies distinguish living-object hit testing, item hit testing, object-action packet transmission, coordinate-action packet transmission, status snapshot access, and input-state reset.
- The target and UID0003ZS together close every input/action field consumed across mouse and timer behavior.
- The four UID00042I calls map precisely to left-up mismatch/common cleanup, right-down entry, and right-up cleanup.
- The tail item boundaries and branch destinations explain every byte through the successor start.

## IDA MCP Facts

- Historical research database session: `5a570ede`; input IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; analysis was idle during bounded read-only queries. Exact-artifact audit transport `cc8ba0cd-510a-4bf5-93a9-a56cc00f775d` independently re-read the target/helper prototypes, comments, and xrefs without mutation; corrective transport `d9cafb48-5a00-485a-b61e-4b20a3afee10` independently re-read the two data ranges, neighboring boundaries, bytes, xrefs, comments, globals/names, and proposed-name collisions without mutation. Session/database `1da2b2ae` was the restored retry base after the failed packed-UDT attempt and is the current saved poststate under catalog entry `0355`.
- Current target function: `MapPane__HandlePointerOrMouseEvent`, `[0x00507150,0x00507c72)`, size `0xb22` / 2850 bytes, 146 blocks, complexity 91, function-body SHA256 `D8C23C1527E9DD2EFB9FD56D2B2EEC37D1442B372F8B2938991019E1D3AD5630`. Historical pre-Gate2B name was `sub_507150`.
- Full target bytes `[0x00507150,0x00507c90)` SHA256: `7038EA102C01227D930FC212983C28D27AA55E59EAA8C686E136F6301611FFF3`.
- Current target type is `bool __thiscall MapPane__HandlePointerOrMouseEvent(MapPane *__shifted(MapPane,0xA0) this, Event *event)`. Current FR is `MapPane EventHandler-facet pointer/mouse override; raw ECX is complete MapPane+0xA0. Handles cursor movement and left/right button down/up; double-click and wheel events return false.` Current FP is `Source: bool MapPane::HandlePointerOrMouseEvent(Event *event); 0x507C72-0x507C90 is compiler alignment/jump-table support.` Address regular/repeatable comments at `0x507150` remain absent/absent. Historical pre-Gate2B type/comments were `char __thiscall(int this, int)` and absent/absent.
- Current helper ABI readback: `0x50f4d0` is `void __stdcall RequestObjectInfo(unsigned int objectId)` and still ends in `retn 4`; `0x50f9c0` is `void __stdcall RequestLookAtMapPosition(unsigned __int16 column, unsigned __int16 row)` and still ends in `retn 8`; `0x5a4f70` is `void __stdcall RequestLocalPlayerStatus(unsigned int requestTime)` and still ends in `retn 4`. The exact report-listed FR/FP channels persist on each function; all address comments remain absent. Historical raw names/types remain in the action tables below as prestate evidence.
- Historical corrected data prestate from transport `d9cafb48-5a00-485a-b61e-4b20a3afee10` was four undefined one-byte items per range, headed by `unk_69BF6C` and `unk_69BF70`, with no global/entity/type/comments. Catalog `0355` now models `[0x69bf6c,0x69bf70)` as one four-byte `unsigned int g_epfLocalPlayerStatusRequestTime` item and `[0x69bf70,0x69bf74)` as one four-byte `unsigned int g_legacyLocalPlayerStatusRequestTime` item, with the exact ER/EP channels from the action table. All eight bytes remain zero. Xrefs remain exactly `0x5a4fba/0x5a686f -> 0x69bf6c` and `0x5a4fff/0x5a68a4 -> 0x69bf70`; the lower `0x69bf68` item, shared `0x69bf70` boundary, and upper `g_lastFunctionKeyTick` fence at `0x69bf74` remain intact.
- Current type readback: MapPane is exactly size `0x910` with 69 members, semantic pointer-event fields and IDA-only `_gap3A9[3]`/`_gap3B5[3]` at the report-listed offsets, and `m_hoveredObjectId +0x3ec`; Event is exactly size `0x110` with byte `m_type +0x4`, IDA-only `_gap5[3] +0x5`, and payload `+0x8`. The four-byte `EventType m_type`, 62-member MapPane aggregate, and failed packed MapPane `0x90c`/Event `0x10e` layouts are historical prestates or discarded-attempt evidence, not current IDA state.
- Catalog `0355` also preserved all six function bounds/bytes/xrefs and all protected tail/compiler/prerequisite entities. Prototype application caused only three bounded frame-display normalizations: `0x507150 +0xe8` is now `event : Event *` (historical `arg_0`), `0x50f9c0 +0x20` is now `row : unsigned __int16` (historical `arg_4`), and `0x5a4f70 +0x1c` is now `requestTime : unsigned int` (historical `arg_0`). Offsets, widths, nonargument locals, saved registers, return addresses, ABI, bytes, and ranges are unchanged.
- Sole inbound xref to target start: data xref `0x0061e76c -> 0x00507150`. A little-endian VA pointer occurs at `0x0061e76c`; no RVA-pointer route was found.
- Exact bounded vtable neighborhood readback: preceding cell `0x61e760 -> 0x50a500` (`MapPane_OnPaint`); `0x61e764 -> 0x64b20c` is the non-function RTTI locator immediately before this vftable; vftable cells are `0x61e768 -> 0x514d1e` (`sub_514D1E`, size `0xb`), `0x61e76c -> 0x507150` (target), `0x61e770 -> 0x506df0`, `0x61e774 -> 0x544dd0`, `0x61e778 -> 0x507c90`, `0x61e77c -> 0x508f60`, and `0x61e780 -> 0x544e00`. This corrects the superseded transcription that assigned `0x50a500` to `0x61e768` and omitted `0x61e774`.
- `0x508f60` has typed signature `bool __thiscall(MapPane *__shifted(MapPane,0xA0) this, Event *event)`, corroborating the same facet used by this target.
- Last code item ends exactly at `0x507c72`. Bytes `66 90` at `0x507c72-0x507c74` form one two-byte alignment/data item. No function, source caller, or independent semantic item begins there.
- `0x507c74-0x507c90` is one 28-byte item named `jpt_5071E8`, with regular comment exactly `jump table for switch statement` and no repeatable comment.
- Jump entries: case 0 -> `0x50796f`; 1 -> `0x5071ef`; 2 -> `0x507c28` default; 3 -> `0x507436`; 4 -> `0x507559`; 5 -> `0x507c28` default; 6 -> `0x5078fe`.
- Successor `sub_507C90` begins exactly at `0x507c90`, size `0x1176`, and is separately routed by vtable cell `0x61e778`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00507150-0x00507c72` | UID00037S `by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md` | `MapPane::HandlePointerOrMouseEvent` | true | UID00007Q | current `93/94` | implemented and validator-confirmed source-bearing method |
| `0x00507c72-0x00507c74` | UID00037S `by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md` | two-byte compiler alignment retained in target envelope | no independent source | UID00037S envelope | n/a | no child/no code |
| `0x00507c74-0x00507c90` | UID00037S `by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md` | compiler switch table retained in target envelope | no independent source | UID00037S envelope | n/a | no child/no code |
| `0x00507c90-0x00508f60` | UID00037T `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md` | next MapPane packet callback | true | UID00007Q | exact current `88/90` | protected successor/no change |
| `0x00505cc0-0x00505cf9` | UID00042F `by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md` | existing `MapPane::ClearQueuedMapStateRefresh` dependency | true | UID00007Q | exact current `90/92` | inspected source-ready/no change |
| `0x0050c550-0x0050c5d2` | [UID:0004YB] `by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md` | MapPane item-object hit-test method | true | UID00007Q | current `92/94` | created first, validator command 18866 assigned/read back UID0004YB |
| `0x0050f4d0-0x0050f52a` | UID0003TU `by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md` | external `RequestObjectInfo` helper | true | UID0000L3 source route | current `90/92` | semantic/formal migration applied; command 18870 validated the initial callback and command 19154 validates sole CPP plus blank child H covered by UID00007Q |
| `0x00554c40-0x00554f59` | UID0004F9 `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md` | `RightButtonMenuPane::OnEvent` consumer of external `RequestObjectInfo` | true | UID0000C0 / UID0000N7 | current `92/94` | formal/emitter/alias migration applied and validated by command 18888; support only, not an additional report target |
| `0x0050f9c0-0x0050fa1b` | UID0003TV `by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md` | static `RequestLookAtMapPosition` helper | true | UID0000L3 source route | current `90/92` | semantic/formal migration applied and validated by command 18871 |
| `0x005a4f70-0x005a500f` | [UID:0004YC] `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md` | externally callable UserPane.cpp helper | true | UID0000P1 | current `92/94` | created second, validator command 18867 assigned/read back UID0004YC |

The two child registrations were completed deterministically in the accepted callback:

1. UID0004YB was created from the dequoted item-hit payload with no hand-authored UID; command 18866 inserted/read back the literal first-line UID and passed.
2. UID0004YC was then created from the dequoted status-request payload with no hand-authored UID; command 18867 inserted/read back the literal first-line UID and passed.
3. The report header now declares `TARGET-REPORT-ADDITIONAL-UIDS:0004YB,0004YC` in path order; Target, inventory, ledger, support table, checklist, and manual-row staging use those actual identities.
4. Final callback searches require no unresolved child identity placeholders; the exact zero-count proof is recorded under Validator Results.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061e76c` | data xref to `0x507150` | sole target entry route; MapPane EventHandler virtual slot |
| `0x00507529` | call UID00042I | left-up mismatch cleanup after complete-object recovery |
| `0x00507545` | call UID00042I | common left-up cleanup |
| `0x00507586` | call UID00042I | right-down entry cleanup |
| `0x0050795b` | call UID00042I | right-up cleanup |
| `0x0050726d/0x50747c/0x5075e3/0x5079d9/0x507a72` | calls `0x50c470` | living-object hit tests |
| `0x005072f3/0x507789/0x507ace` | calls `0x50c550` | item-object hit tests |
| `0x005074ca/0x50750d` | calls `0x50f4d0` | object action packet with selected object id |
| `0x00507765/0x5077a9` | calls `0x50f9c0` | map-coordinate action packet |
| `0x00507721` | calls `0x5a4f70` | local-player command request with message time |
| `0x00507218/0x50757b/0x507954/0x507c4d` | calls `0x505cc0` / UID00042F | exact queued Map-state drain sites in the target; the same modeled helper also serves the sibling MapPane callback/timer/packet paths |

## Documentation Evidence And IDA Status

- Supporting current docs: Event provides exact constants/payload; ObjectStatusBlob provides `StatusKind`, `HumanObject`, and `m_actionState`; MapPane already declares the virtual and accepted `FindObjectAtMapPoint`; ObjectList provides `FindByObjectId`; ScreenPane provides the cursor loader/active-cursor method; RightButtonMenuPane provides the exact setter/class fields; ObjectInfoObjectPane and UserPane provide required source APIs.
- Historical pre-callback stale-doc inventory: UID00037S said constants, fields, and tail were unresolved; MapPane H used aggregate/provisional action fields; UID0003TK/TL and MapPane prose called `+0x90c/+0x90e` deferred surface flags; UID0003ZS retained provisional action-array naming; UID0003TU/TV retained opcode-bearing working names and blank C++; UID00030A and its callers retained opcode-derived helper/storage names; UID0000C0's Info row and UID0004F9 exposed `sub_50F4D0`/`MapPaneSendObjectAction43Packet`; and the RightButtonMenuPane scaffold lacked the MapPane header. The accepted ordinary callback corrected that inventory. This reconciliation additionally updates only ordinary pages that still described historical IDA raw names/prestates as current after catalog `0355`.
- Dated command `18812` generated semantic checkpoint, not lifecycle-current authority: `auto-generated/NexusTK/map/MapPane.cpp` SHA256 `F139F7B18B7720B09CDDC1DB8196C9D6AA83D0B76BCF37E5FD6A74D4663AA752` contains exactly one UID00037S `85/89` empty-emitter marker; `auto-generated/NexusTK/map/MapPane.h` SHA256 `9B5D5AAA411A61DDEB9BE26B05E4688FB743F848F480FE6EAF70530A3AF15BAF` contains exactly one `virtual bool HandlePointerOrMouseEvent(Event *event);` declaration and no `RequestObjectInfo` declaration yet.
- Dated command `18822` tracker semantic checkpoint, not lifecycle-current authority: `auto-generated/-ag-research-tracker.md` SHA256 `13A764FCA60C60A0285EC682ED6D94ECF63E74EAB71B5DD3B4C9DA1106FB87F8` records UID00037S `85/89` with zero direct/additional reports at this report-only stage.
- Supervisor generated command `19201` (`2026-07-29T10:58:40-04:00`) is the successful post-repair closure checkpoint: `MapPane.cpp` SHA256 `3BA114902CF015134888ED8837F10EB6F69A8A6F29A17FFF8E853C4EBC2CCB0F`, 159443 bytes/4776 lines; `MapPane.h` SHA256 `06859EF0EF51A8F9F4922FAD5F66249403052C43FD51E3EAEB9511BBB1F43A82`, 12857 bytes/366 lines; `UserPane.cpp` SHA256 `993F15DA0945A609AE15F3E439CA5EE40369718AF53E123C60A2471C16BAC537`, 92655 bytes/2801 lines; `UserPane.h` SHA256 `81D2D98A088D149ED10A78C3B5BE428C086CAF1616CA349B006D62612AF42999`, 482 bytes/8 lines; tracker SHA256 `3B57476E224BD2D353C4D3C6868C90C27AE79D368D3111453DB2D78E69902183`, 1675376 bytes/6629 lines. It contains exactly one UID00007Q `RequestObjectInfo` declaration and no UID0003TU header marker/declaration, exactly one UID0003TU CPP definition, exactly one primary UID00037S and each additional UID0004YB/UID0004YC formal output, and zero target empty markers or temporary identities.
- Generated artifacts advanced after that checkpoint. Audit-time command `19221` (`2026-07-29T11:05:07-04:00`) preserves the same target semantics while advancing physical headers/hashes: `MapPane.cpp` SHA256 `B46F993DDE61A2ACED7443D830EEEFD22459C852E1B45BFD542584DC3722EC58`, 159443 bytes/4776 lines; `MapPane.h` SHA256 `B2404563C11233E20A42639A0107F9F8D0491834FAC273535FD9576E00E0DE2F`, 12857 bytes/366 lines; `UserPane.cpp` SHA256 `27215200C33CA25DB01DC89281207F792436B33BA570063CFE57E4DC8F200A7B`, 92655 bytes/2801 lines; `UserPane.h` SHA256 `8C31D4FE6C420A22C8825068BD983E8CA0168FD546EC1B4D4C473A6DE2ABA5C1`, 482 bytes/8 lines; tracker SHA256 `2E18D81FCA6DBFCAF8794D63066546A147437CCFD78AE812C9D9485CA4598A31`, 1675820 bytes/6631 lines. Later supervisor validators may advance physical freshness again; final lifecycle-time generated readback is authoritative, while `19201` remains the exact successful closure checkpoint requested here.

## Ranked Ownership Analysis

### 1. MapPane class through MapPane.cpp

- Evidence for: MapPane vtable-only entry, EventHandler facet, direct MapPane fields, MapPane hit tests and coordinate conversion, adjacency to MapPane input/packet callbacks, existing exact class declaration and source root.
- Evidence against: none.
- Decision: accepted. Parent/emitter UID00007Q, source owner UID0000L3.

### 2. EventHandler or TimerHandler base

- Evidence for: incoming receiver is a secondary EventHandler facet; method schedules/cancels timers.
- Evidence against: every state field and helper belongs to complete MapPane; compiler subtracts `0xa0`; TimerHandler calls use another inherited facet.
- Decision: rejected as source owner; both are inherited dependencies.

### 3. ScreenPane, RightButtonMenuPane, or ObjectList

- Evidence for: target calls their cursor/menu/lookup APIs.
- Evidence against: none owns target receiver, vtable entry, state machine, or range neighborhood.
- Decision: rejected; dependency owners only.

### Proposed new file/grouping, if applicable

- Not applicable. The accepted `NexusTK/map/MapPane.cpp` source root already exists and is the narrow historical placement.
- UID0003TU and UID0003TV remain MapPane.cpp-owned rather than becoming new source files: UID0003TU has external linkage because UID0004F9 in `RightButtonMenuPane.cpp` also calls it, while UID0003TV is `static`/file-local because both callers are in MapPane.cpp. `RightButtonMenuPane.cpp` gains compile visibility by adding `#include "../../map/MapPane.h"` immediately after its own header include; it does not duplicate the helper definition or create a second declaration. The shared local-player-status request helper remains UserPane.cpp-owned and externally declared because multiple pane source files call it.

## Source Placement

- Recommended placement: member definition in `NexusTK/map/MapPane.cpp`; declaration and private supporting enum/fields/helpers in the existing `MapPane` class header emitter.
- The method's vtable slot, complete-object state, neighboring MapPane functions, and direct use of MapPane-private helpers make class/file placement conclusive.
- Event.cpp, ScreenPane.cpp, ObjectList.cpp, RightButtonMenuPane.cpp, and UserPane.cpp are rejected as target owners. Their code supplies types or called functions only.
- No remaining source-placement uncertainty affects owner, emitter, or C++ eligibility.

## Range / Split / Padding / Reclassification Analysis

- Exact target envelope: `[0x00507150,0x00507c90)`. Exact source code: `[0x00507150,0x00507c72)`.
- `0x00507c72-0x00507c74` is `66 90`, one compiler alignment item. It receives no source-facing name, declaration, or emitted code.
- `0x00507c74-0x00507c90` is the seven-dword switch table for the source `switch (event->m_type)`. Its duplicate default targets for cases 2 and 5 are compiler lowering, not duplicate source handlers.
- `0x00507c90` is the exact successor function start and must not be absorbed.
- Keep one UID/page and one method emitter. Do not create padding/table children, do not shrink the target envelope, and do not emit raw tail bytes.

## Negative Evidence Summary

- No ordinary direct caller or separate exported entry exists; vtable-only reachability is expected for an override and is not a liveness blocker.
- No evidence supports a free function, static callback, TimerHandler member, or ScreenPane member.
- The item scan helper does not return a generic targeting result object; it returns an `ObjectPane *` selected from the item list.
- Values `2`, `5`, and `7` have no handwritten case body in this method. Inventing double-click or wheel handling would change behavior.
- The initial input-locked and waiting-for-local-status gates do not justify null checks that are absent in the binary.
- The target's right-button fallback and right-button-up paths return false; treating every in-bounds event as handled would change behavior.
- No source body belongs to the alignment bytes, jump table, vtable cell, or successor.

## IDA Rename / Type / Comment Recommendations

`FR/FP/ER/EP` below means function-regular, function-repeatable, effective-address regular, and effective-address repeatable comment channels. Function/protected-item research was captured in database session `5a570ede` through transport `cc8ba0cd-510a-4bf5-93a9-a56cc00f775d`, and the corrected `0x0069bf6c/0x0069bf70` data prestates were re-read through transport `d9cafb48-5a00-485a-b61e-4b20a3afee10`. Session/database `1da2b2ae` is now the saved catalog-`0355` poststate. `absent` means the channel contains the empty string/no comment, and `n/a` means the item has no function-comment channels.

| Entity | Historical literal pre-Gate2B name/type/declaration | Historical FR / FP / ER / EP prestate | Catalog 0355 applied action | Evidence / safety | Current saved readback | Classification |
| --- | --- | --- | --- | --- | --- | --- |
| function `0x00507150`, `[0x507150,0x507c72)` | `sub_507150`; `char __thiscall(int this, int)`; size `0xb22`; proposed-name query `MapPane__HandlePointerOrMouseEvent` -> `fn:null`, `error:"Not found"` | absent / absent / absent / absent | Renamed/typed/commented exactly as proposed; preserved bounds/xrefs/bytes; accepted prototype-driven `arg_0 +0xe8 -> event : Event *` frame-display normalization | vtable, sibling shifted signature, exact Event type, source declaration; full literal prestate retained below | `MapPane__HandlePointerOrMouseEvent`; `bool __thiscall MapPane__HandlePointerOrMouseEvent(MapPane *__shifted(MapPane,0xA0) this, Event *event)`; exact report-listed FR/FP; ER/EP absent; `[0x507150,0x507c72)`, bytes and sole `0x61e76c` xref unchanged; only `+0xe8` frame display normalized | already present |
| function `0x0050c550`, `[0x50c550,0x50c5d2)` | `sub_50C550`; `int __thiscall(_DWORD **this, int, int)`; size `0x82`; proposed-name query `MapPane__FindItemObjectAtMapPoint` -> `fn:null`, `error:"Not found"` | absent / absent / absent / absent | Renamed/typed/commented exactly as proposed | exact reverse `GetPrimaryCellList` scan, three target callers, `GetBounds`, `PointInRect`; full literal prestate retained below | `MapPane__FindItemObjectAtMapPoint`; `ObjectPane *__thiscall MapPane__FindItemObjectAtMapPoint(MapPane *this, int y, int x)`; exact report-listed FR/FP; ER/EP absent; range, bytes, three callers, and full frame unchanged | already present |
| function `0x0050f4d0`, `[0x50f4d0,0x50f52a)` | `sub_50F4D0`; `void __stdcall(unsigned int value)`; size `0x5a`; terminal `retn 4`; proposed-name query `RequestObjectInfo` -> `fn:null`, `error:"Not found"` | absent / absent / absent / absent | Renamed/typed/commented exactly as proposed | exact body and three callsites in two modeled caller functions; file/source ownership remains MapPane route | `RequestObjectInfo`; `void __stdcall RequestObjectInfo(unsigned int objectId)`; exact report-listed FR/FP; ER/EP absent; range, bytes, `retn 4`, all callers, and full frame unchanged | already present |
| function `0x0050f9c0`, `[0x50f9c0,0x50fa1b)` | `sub_50F9C0`; `void __stdcall(unsigned __int16 value, unsigned __int16)`; size `0x5b`; terminal `retn 8`; proposed-name query `RequestLookAtMapPosition` -> `fn:null`, `error:"Not found"` | absent / absent / absent / absent | Renamed/typed/commented exactly as proposed; accepted prototype-driven `arg_4 +0x20 -> row : unsigned __int16` frame-display normalization | exact body and two target-only click-look callers; full literal prestate retained below | `RequestLookAtMapPosition`; `void __stdcall RequestLookAtMapPosition(unsigned __int16 column, unsigned __int16 row)`; exact report-listed FR/FP; ER/EP absent; range, bytes, `retn 8`, callers unchanged; only `+0x20` frame display normalized | already present |
| function `0x005a4f70`, `[0x5a4f70,0x5a500f)` | `sub_5A4F70`; `int __stdcall(int)`; size `0x9f`; terminal `retn 4`; proposed-name query `RequestLocalPlayerStatus` -> `fn:null`, `error:"Not found"` | absent / absent / absent / absent | Renamed/typed/commented exactly as proposed; accepted prototype-driven `arg_0 +0x1c -> requestTime : unsigned int` frame-display normalization | exact packet/storage body, three modeled caller functions, inline UserPane equivalent; callers ignore residual EAX | `RequestLocalPlayerStatus`; `void __stdcall RequestLocalPlayerStatus(unsigned int requestTime)`; exact report-listed FR/FP; ER/EP absent; range, bytes, `retn 4`, callers/storage xrefs unchanged; only `+0x1c` frame display normalized | already present |
| function `0x00505cc0`, `[0x505cc0,0x505cf9)` | `sub_505CC0`; `void __thiscall(TimerHandler *this)`; size `0x39`; proposed-name query `MapPane__ClearQueuedMapStateRefresh` -> `fn:null`, `error:"Not found"` | absent / absent / absent / absent | Renamed/typed/commented exactly as proposed | UID00042F/MapPane state and target/TK/TL callers; full literal prestate retained below | `MapPane__ClearQueuedMapStateRefresh`; `void __thiscall MapPane__ClearQueuedMapStateRefresh(MapPane *this)`; exact report-listed FR/FP; ER/EP absent; range, bytes, caller/xref set, and sole frame entry unchanged | already present |

Exact collision and full literal stack-frame/local prestates, preserved as historical pre-Gate2B evidence from database `5a570ede`:

| Function action | Exact proposed-name collision result | Full literal `stack_frame` prestate |
| --- | --- | --- |
| `0x00507150` | `MapPane__HandlePointerOrMouseEvent` -> `fn:null`, `error:"Not found"` | `var_D4 +0xc size 0x24 _BYTE[36]`; `var_B0 +0x30 size 0x4 _DWORD`; `var_AC +0x34 size 0x1 _BYTE`; `var_90 +0x50 size 0x1 _BYTE`; `var_6C +0x74 size 0x4 _DWORD`; `var_68 +0x78 size 0x1 _BYTE`; `position +0x94 size 0x8 MapPoint`; `var_44 +0x9c size 0x4 _DWORD`; `var_40 +0xa0 size 0x4 ObjectPane *`; `var_3C +0xa4 size 0x4 _DWORD`; `row +0xa8 size 0x4 int`; `var_31 +0xaf size 0x1 _BYTE`; `bounds +0xb0 size 0x10 struct RectBounds`; `var_20 +0xc0 size 0x10 MapRect`; `var_10 +0xd0 size 0x4 _DWORD`; `var_C +0xd4 size 0x4 _DWORD`; `var_4 +0xdc size 0x4 _DWORD`; `__saved_registers +0xe0 size 0x4 _DWORD`; `__return_address +0xe4 size 0x4 _UNKNOWN *`; `arg_0 +0xe8 size 0x4 _DWORD`; `arg_4 +0xec size 0x4 _DWORD` |
| `0x0050c550` | `MapPane__FindItemObjectAtMapPoint` -> `fn:null`, `error:"Not found"` | `bounds +0xc size 0x10 MapRect`; `var_4 +0x1c size 0x4 _DWORD`; `__saved_registers +0x20 size 0x4 _DWORD`; `__return_address +0x24 size 0x4 _UNKNOWN *`; `row +0x28 size 0x4 int`; `column +0x2c size 0x4 int` |
| `0x0050f4d0` | `RequestObjectInfo` -> `fn:null`, `error:"Not found"` | `Src +0x0 size 0x1 _BYTE`; `destination +0x1 size 0x1 unsigned __int8`; `var_52 +0x2 size 0x1 unsigned __int8`; `var_4E +0x6 size 0x1 _BYTE`; `var_4 +0x50 size 0x4 _DWORD`; `__saved_registers +0x54 size 0x4 _DWORD`; `__return_address +0x58 size 0x4 _UNKNOWN *`; `value +0x5c size 0x4 unsigned int` |
| `0x0050f9c0` | `RequestLookAtMapPosition` -> `fn:null`, `error:"Not found"` | `Src +0x0 size 0x1 _BYTE`; `destination +0x1 size 0x2 unsigned __int8[2]`; `var_11 +0x3 size 0x1 unsigned __int8`; `var_F +0x5 size 0x1 _BYTE`; `var_4 +0x10 size 0x4 _DWORD`; `__saved_registers +0x14 size 0x4 _DWORD`; `__return_address +0x18 size 0x4 _UNKNOWN *`; `value +0x1c size 0x2 unsigned __int16`; `arg_4 +0x20 size 0x2 unsigned __int16` |
| `0x005a4f70` | `RequestLocalPlayerStatus` -> `fn:null`, `error:"Not found"` | `Src +0x0 size 0x1 _BYTE`; `destination +0x1 size 0x1 unsigned __int8`; `var_12 +0x2 size 0x1 _BYTE`; `var_4 +0x10 size 0x4 _DWORD`; `__saved_registers +0x14 size 0x4 _DWORD`; `__return_address +0x18 size 0x4 _UNKNOWN *`; `arg_0 +0x1c size 0x4 _DWORD` |
| `0x00505cc0` | `MapPane__ClearQueuedMapStateRefresh` -> `fn:null`, `error:"Not found"` | `__return_address +0x4 size 0x4 _UNKNOWN *` |

Catalog `0355` frame-display reconciliation is deliberately bounded. At `0x00507150`, only historical `arg_0 +0xe8 size 0x4 _DWORD` now displays as `event +0xe8 size 0x4 Event *`; historical `arg_4 +0xec` and every nonargument entry remain unchanged. At `0x0050f9c0`, only historical `arg_4 +0x20 size 0x2 unsigned __int16` now displays as `row +0x20 size 0x2 unsigned __int16`. At `0x005a4f70`, only historical `arg_0 +0x1c size 0x4 _DWORD` now displays as `requestTime +0x1c size 0x4 unsigned int`. These are accepted prototype-driven analysis-presentation normalizations, not byte, ABI, range, offset, width, saved-register, return-address, or local-variable drift.

Exact UDT, data, protected-item, and prerequisite action rows:

| Entity | Historical pre-action or protected-state declaration | FR / FP / ER / EP prestate | Catalog 0355 action/disposition | Evidence / safety | Catalog 0355 current saved readback | Classification |
| --- | --- | --- | --- | --- | --- | --- |
| `MapPane` UDT region `+0x3a0..+0x3b7` | restored retry base `1da2b2ae`: type `MapPane`, size `0x910`, 62 members; literal lower boundary is `int m_deferredMotionRecordCount +0x398`, `unsigned __int8 m_deferMotionMessages +0x39c`, `bool m_queuedMapStateRefresh +0x39d`, `unsigned __int8 m_pendingActionPoll +0x39e`, `unsigned __int8 m_deferredStatePadding +0x39f`; transaction target was one `int m_pendingMovementState[6] +0x3a0` size `0x18`; literal upper neighbor was `float m_currentDayNightBrightness +0x3b8`. Historical failed unsaved declaration packed MapPane to `0x90c` and moved detail/time/type to `+0x3aa/+0x3ae/+0x3b2` | member comments absent; function channels n/a | Replaced transactionally with the literal IDA-only fragment below: semantic members at `+0x3a0/+0x3a4/+0x3a8/+0x3ac/+0x3b0/+0x3b4`, explicit three-byte `_gap3A9` and `_gap3B5` filler arrays at `+0x3a9/+0x3b5`, and unchanged upper neighbor at `+0x3b8`. The filler arrays are IDA-only layout guards and were not copied into ordinary source | exact byte/dword event copies, accepted byte Event discriminator, 24-byte footprint, failed packed offsets, and restored original layout | exact readback: `m_pointerEventY +0x3a0`, `m_pointerEventX +0x3a4`, `m_pointerEventModifiers +0x3a8`, `_gap3A9[3] +0x3a9..+0x3ab`, `m_pointerEventDetail +0x3ac`, `m_pointerEventMessageTime +0x3b0`, `m_pointerEventType +0x3b4`, `_gap3B5[3] +0x3b5..+0x3b7`, upper `m_currentDayNightBrightness +0x3b8`, size `0x910`, member count `69`; all literal lower-bound and unlisted members unchanged. Packed `0x90c/+0x3aa/+0x3ae/+0x3b2` readback remains rejected history | already present |
| `MapPane` UDT member `+0x3ec` | restored retry base `1da2b2ae`: type `MapPane`, size `0x910`, 62 members; literal lower neighbor `float m_dayNightBrightnessBias +0x3e8`; target was `unsigned int m_pendingMapStateToken +0x3ec`; literal upper neighbor `unsigned __int8 m_waitingForLocalPlayerStatus +0x3f0`. Historical failed unsaved packed declaration moved this target to `+0x3e8` | member comment absent; function channels n/a | After the preceding region read back size `0x910` and exact gaps/offsets, renamed this same-width target to `unsigned int m_hoveredObjectId` | direct object-id comparison/lookup/clear lifecycle and restored original layout | one renamed same-width member at exactly `+0x3ec`; lower `m_dayNightBrightnessBias +0x3e8`, upper `m_waitingForLocalPlayerStatus +0x3f0`, size `0x910`, and all other members unchanged; `m_hoveredObjectId +0x3e8` remains rejected history | already present |
| data range `0x0069bf6c`, `[0x69bf6c,0x69bf70)` | `unk_69BF6C` was the undefined one-byte head followed by three unnamed undefined one-byte heads; all had empty type and `is_code:false/is_data:false`; no global/entity existed; proposed-name query returned no entity | FR n/a / FP n/a / ER absent / EP absent | Phase A materialized exactly one anonymous four-byte unsigned-int item; after intermediate readback, Phase B applied `unsigned int g_epfLocalPlayerStatusRequestTime`, ER `Most recent local-player status request time for the EPF asset path.`, and EP `Source: static unsigned int g_epfLocalPlayerStatusRequestTime = 0;` | only writes are `0x5a4fba` and `0x5a686f` under true `g_useEpfAssets`; four zero bytes; separate lower `0x69bf68` fence | exactly one named unsigned-int item `[0x69bf6c,0x69bf70)`, exact ER/EP, FR/FP n/a, four zero bytes, same two xrefs, lower fence unchanged, and exact upper neighbor boundary at the second four-byte item | already present |
| data range `0x0069bf70`, `[0x69bf70,0x69bf74)` | `unk_69BF70` was the undefined one-byte head followed by three unnamed undefined one-byte heads; all had empty type and `is_code:false/is_data:false`; no global/entity existed; proposed-name query returned no entity | FR n/a / FP n/a / ER absent / EP absent | Phase A materialized exactly one anonymous four-byte unsigned-int item; after intermediate readback, Phase B applied `unsigned int g_legacyLocalPlayerStatusRequestTime`, ER `Most recent local-player status request time for the legacy asset path.`, and EP `Source: static unsigned int g_legacyLocalPlayerStatusRequestTime = 0;` | only writes are `0x5a4fff` and `0x5a68a4` under false `g_useEpfAssets`; four zero bytes; upper `g_lastFunctionKeyTick` fence | exactly one named unsigned-int item `[0x69bf70,0x69bf74)`, exact ER/EP, FR/FP n/a, four zero bytes, same two xrefs, exact lower-neighbor boundary, unchanged upper fence, and no item crossing either boundary | already present |
| `MapPane` UDT tail `+0x8e8..+0x90f` | contained in `unsigned __int8 _mapPaneAfterZoneMusic[1076]` at `+0x4dc`; no independent members | member comments absent; function channels n/a | no IDA mutation in this handoff; docs/H receive exact fields while IDA keeps the broad tail | piecemeal carve would disturb unresolved `+0x4dc..+0x8e7`; semantics are nevertheless closed; protect the full opaque item | unchanged opaque tail; no false deferred-surface members | no change recommended |
| data/alignment `0x00507c72-0x00507c74` | name absent; explicit type absent; one 2-byte data item | n/a / n/a / absent / absent | leave unchanged | exact `66 90` compiler alignment, no independent route; protect the item boundary | name/type/comments remain absent; exact 2-byte item and `66 90` bytes remain unchanged | no change recommended |
| jump table `0x00507c74-0x00507c90` | `jpt_5071E8`; explicit type absent; 28-byte data item | n/a / n/a / `jump table for switch statement` / absent | leave unchanged | exact seven-entry compiler support; protect current name/comment/table bounds | exact name, 28-byte item, regular comment, seven target dwords, and absent repeatable comment remain unchanged | no change recommended |
| successor function `0x00507c90`, `[0x507c90,0x508e06)` | `sub_507C90`; `char __thiscall(int this, int)`; size `0x1176` | absent / absent / absent / absent | leave unchanged in this target action | separate packet callback, vtable cell `0x61e778`; protected from this transaction | exact current name/type/range and absent FR/FP/ER/EP remain unchanged; `0x61e778` still points to it | no change recommended |
| vtable cell `0x0061e76c` | name absent; explicit type absent; 4-byte data item containing `0x00507150` | n/a / n/a / absent / absent | leave unchanged | sole target xref and compiler-generated slot; protected from rename/retype/comment actions | name/type/comments remain absent; 4-byte value remains `0x00507150`; sole data xref remains intact | no change recommended |
| prerequisite type `MapPane` | restored retry base: UDT size `0x910`, 62 members; action details are the two MapPane rows above | type/member comments outside function channels | preserve base declaration, size, and all unlisted members while applying the explicit gap-guarded rows above | exact shifted receiver, source owner, failed packed attempt, restored prestate | current UDT size `0x910`, 69 members, exact six semantic fields and both IDA-only gaps, `m_hoveredObjectId +0x3ec`, and all unlisted members unchanged | already present |
| prerequisite type `Event` | restored retry base: UDT size `0x110`; `vftable +0`, four-byte `EventType m_type +4`, `EventPayload m_payload +8`; failed unsaved declaration produced size `0x10e` and payload `+0x6` | type/member comments outside function channels; no address-comment action | replaced only `+0x4..+0x7` with `unsigned __int8 m_type` plus IDA-only `unsigned __int8 _gap5[3]`; preserved payload, size, vftable, and every payload member | accepted UID00004L source declaration, direct byte loads/stores, failed packed attempt, restored retry base | `Event` size `0x110`; `unsigned __int8 m_type +0x4`; `_gap5[3] +0x5..+0x7`; payload `+0x8`; all unrelated members unchanged; packed `0x10e/+0x6` state rejected | already present |
| prerequisite type `EventType` | exists; enum; size `4` | n/a | preserve unchanged | exact switch discriminator constants; protected prerequisite | same declaration | no change recommended |
| prerequisite type `LivingObjectPane` | exists; UDT; size `0x20c`; `bool m_terminalAnimation +0x1d0` | n/a | preserve unchanged | closes false invisible-field interpretation; protected prerequisite | same member/type | no change recommended |
| prerequisite type `RightButtonMenuPane` | exists; UDT; size `0x144`; `int m_targetId +0xfc`, `wchar_t m_targetName[33] +0x100` | n/a | preserve unchanged | supports id/name setter declaration and call order; protected prerequisite | same type | no change recommended |
| prerequisite type `ScreenPane` | exists; UDT; size `0x5b4`; `HCURSOR m_cursorHandles[12] +0x550` | n/a | preserve UDT; cursor enum is a source-header-only declaration | constants do not change object layout; protected prerequisite | same UDT size/members | no change recommended |

Literal IDA-only declaration fragments used by the successful catalog-`0355` retry follow. These are member sequences at the stated existing offsets, not standalone nested types and not ordinary-source declarations. The `_gap*` members are mandatory IDA layout guards because the prior declaration parser packed both UDTs; ordinary source continues to use natural unnamed alignment and must not receive these names.

```cpp
// MapPane: replace only the existing 0x18-byte member at +0x3a0.
int m_pointerEventY;                       // +0x3a0
int m_pointerEventX;                       // +0x3a4
unsigned __int8 m_pointerEventModifiers;  // +0x3a8
unsigned __int8 _gap3A9[3];               // +0x3a9..+0x3ab, IDA only
int m_pointerEventDetail;                  // +0x3ac
unsigned int m_pointerEventMessageTime;   // +0x3b0
unsigned __int8 m_pointerEventType;       // +0x3b4
unsigned __int8 _gap3B5[3];               // +0x3b5..+0x3b7, IDA only
// Existing float m_currentDayNightBrightness must remain +0x3b8.
```

```cpp
// Event: preserve the existing vftable member at +0x0 and replace only +0x4..+0x7.
unsigned __int8 m_type;       // +0x4
unsigned __int8 _gap5[3];     // +0x5..+0x7, IDA only
EventPayload m_payload;       // existing member must remain +0x8
// Event must remain size 0x110.
```

Catalog `0355` followed the literal transaction order: restored session/database `1da2b2ae`; MapPane `+0x3a0..+0x3b7` with all eight members, upper `+0x3b8`, size `0x910`, and member count `69`; then same-width `+0x3ec`; then Event `+0x4..+0x7` with payload `+0x8` and size `0x110`; then every function/data/protected readback; then IDB save. The packed MapPane/Event offsets and sizes remain failed unsaved history and must fail any future revalidation.

Negative constraints preserved by catalog `0355`: no function at `0x507c72` or `0x507c74`; no rename of `jpt_5071E8`; no source globals for table entries; no unshifted-MapPane raw ECX type; no protected successor/vtable mutation; no four-byte modeling of either byte discriminator; no IDA-only `_gap*` names copied into ordinary source; no automatic declaration-alignment dependence; and no piecemeal carve of the large opaque MapPane tail.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. This report resolves the behavior, owner, source signature, event values, fields, helper contracts, and compiler tail.
- CPP block disposition: replace the blank target CPP block with the following formal insertion text.
- H block disposition: leave the target H block blank. [UID:00007Q] already emits `virtual bool HandlePointerOrMouseEvent(Event *event);`; adding it here would duplicate a class declaration. Required private enum/field/helper declaration corrections belong in the complete MapPane class H block.
- Source-local declaration disposition: emit the following `static` prototype immediately before the target method in the same target CPP block. UID0003TV owns the sole later definition; this declaration closes compile visibility without adding a public H declaration or duplicate body.

```cpp
static void __stdcall RequestLookAtMapPosition(
    unsigned short column,
    unsigned short row);

bool MapPane::HandlePointerOrMouseEvent(Event *event)
{
    bool clearQueuedState = true;
    bool handled = false;
    MapRect pointerBounds = m_bounds;
    LivingObjectPane *livingObject;
    ObjectPane *itemObject;
    ObjectStatusBlob objectStatus;
    MapPoint point;

    if (m_localPlayerObjectPane->m_inputLocked)
        return false;

    pointerBounds.right -= g_mapTilePixelWidth;
    pointerBounds.bottom -= g_mapTilePixelHeight;

    if (m_waitingForLocalPlayerStatus)
        return false;

    const EventPointerPayload &pointer = event->m_payload.m_pointer;
    const bool insideMap = PointInRect(
        pointer.m_y,
        pointer.m_x,
        &pointerBounds) != 0;

    switch (event->m_type) {
    case kEventCursorMove:
        m_pointerEventY = pointer.m_y;
        m_pointerEventX = pointer.m_x;
        m_pointerEventModifiers = pointer.m_modifiers;
        m_pointerEventDetail = pointer.m_detail;
        m_pointerEventMessageTime = pointer.m_messageTime;
        m_pointerEventType = event->m_type;

        if (m_leftButtonTrackingActive && insideMap) {
            livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (livingObject != m_highlightedObjectPane) {
                if (m_highlightedObjectPane != NULL &&
                    !m_selectedObjectActive) {
                    m_highlightedObjectPane->SetHighlightState(false);
                }
                m_highlightedObjectPane = livingObject;
                if (livingObject != NULL)
                    livingObject->SetHighlightState(true);
            }
        }

        if (g_pConfig->m_autoMoveEnabled && m_queuedMapStateRefresh) {
            if (m_rightButtonTrackingActive) {
                point.row = pointer.m_y;
                point.column = pointer.m_x;
                ScreenToMapCoords(&point);
                m_pendingActionRow = point.row;
                m_pendingActionColumn = point.column;
            }
            clearQueuedState = false;
        }

        if (!insideMap)
            return false;

        livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
        if (livingObject != NULL && !livingObject->m_terminalAnimation) {
            livingObject->GetSpriteConfig(&objectStatus);
            switch (objectStatus.m_actionState) {
            case kMapActionView:
                g_pScreenPane->SetActiveCursor(
                    ScreenPane::kCursorView,
                    false);
                break;
            case kMapActionSelect:
            case kMapActionInteract:
                g_pScreenPane->SetActiveCursor(
                    ScreenPane::kCursorSelect,
                    false);
                break;
            default:
                g_pScreenPane->SetActiveCursor(
                    ScreenPane::kCursorAttack,
                    false);
                break;
            }
        } else {
            itemObject = FindItemObjectAtMapPoint(pointer.m_y, pointer.m_x);
            g_pScreenPane->SetActiveCursor(
                itemObject != NULL
                    ? ScreenPane::kCursorPut
                    : ScreenPane::kCursorNormal,
                false);
        }

        if (livingObject == NULL ||
            livingObject->m_objectId != m_hoveredObjectId) {
            if (m_hoveredObjectId != 0) {
                LivingObjectPane *oldObject = static_cast<LivingObjectPane *>(
                    m_objectList->FindByObjectId(m_hoveredObjectId));
                if (oldObject != NULL &&
                    oldObject->m_objectInfoObjectPane != NULL &&
                    oldObject->m_objectInfoObjectPane->m_tracksSelectedName) {
                    oldObject->m_objectInfoObjectPane->InvalidateRect(NULL);
                    oldObject->m_objectInfoObjectPane->SetSelectedName(L"");
                    oldObject->m_objectInfoObjectPane->UpdatePosition();
                    oldObject->m_objectInfoObjectPane->InvalidateRect(NULL);
                }
                m_hoveredObjectId = 0;
            }

            if (livingObject != NULL &&
                livingObject->m_objectStatus.m_statusKind ==
                    ObjectStatusBlob::HumanObject &&
                livingObject->m_objectInfoObjectPane != NULL &&
                livingObject->m_objectInfoObjectPane->m_tracksSelectedName) {
                ObjectInfoObjectPane *objectInfo =
                    livingObject->m_objectInfoObjectPane;
                objectInfo->InvalidateRect(NULL);
                objectInfo->SetSelectedName(livingObject->m_name);
                objectInfo->UpdatePosition();
                objectInfo->InvalidateRect(NULL);
                m_hoveredObjectId = livingObject->m_objectId;
            }
        }
        return true;

    case kEventLeftButtonDown:
        if (g_pUserPane->m_nameVisible)
            return true;

        m_leftButtonTrackingActive = true;
        if (m_queuedMapStateRefresh)
            ClearQueuedMapStateRefresh();
        m_pendingActionState = 0;

        if (!insideMap)
            return false;

        if (m_highlightedObjectPane != NULL &&
            !m_selectedObjectActive) {
            m_highlightedObjectPane->SetHighlightState(false);
        }

        livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
        if (livingObject != NULL && !livingObject->m_terminalAnimation) {
            livingObject->GetSpriteConfig(&objectStatus);
            m_pendingActionState = objectStatus.m_actionState;

            if (m_pendingActionState == kMapActionView ||
                m_pendingActionState == kMapActionSelect ||
                m_pendingActionState == kMapActionInteract) {
                if (livingObject != m_selectedObjectPane) {
                    livingObject->SetHighlightState(true);
                    m_highlightedObjectPane = livingObject;
                }
                return true;
            }

            m_highlightedObjectPane = NULL;
            m_pendingActionTargetObjectId = livingObject->m_objectId;
        } else {
            itemObject = FindItemObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (itemObject != NULL) {
                m_pendingActionModifiers = pointer.m_modifiers;
                m_pendingActionState = kMapActionGroundItem;
                m_pendingActionTargetObjectId = itemObject->m_objectId;
            }
        }

        m_actionStartY = pointer.m_y;
        m_actionStartX = pointer.m_x;

        if (g_pConfig->m_clickMoveEnabled) {
            point.row = pointer.m_y;
            point.column = pointer.m_x;
            if (livingObject != NULL &&
                (m_pendingActionState == kMapActionMoveTo ||
                 m_pendingActionState == kMapActionMoveAndUse)) {
                livingObject->GetMapPosition(&point);
                MapToScreenCoords(&point);
            }

            m_pendingActionY = point.row;
            m_pendingActionX = point.column;
            ScreenToMapCoords(&point);
            m_pendingActionRow = point.row;
            m_pendingActionColumn = point.column;

            Sleep(100);
            if (!m_queuedMapStateRefresh && g_pInputBlockerPane == NULL) {
                m_queuedMapStateRefresh = true;
                TimerHandler::ScheduleTimer(8, 44, 0, 0);
                CaptureMouse();
            }
        }
        return false;

    case kEventLeftButtonUp:
        if (insideMap) {
            if (m_highlightedObjectPane != NULL &&
                !m_selectedObjectActive) {
                m_highlightedObjectPane->SetHighlightState(false);
            }

            livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (livingObject != NULL &&
                livingObject->m_objectId == m_pendingActionTargetObjectId) {
                if (m_pendingActionState == kMapActionView &&
                    !m_objectInteractionTimerActive) {
                    m_objectInteractionTimerActive = true;
                    RequestObjectInfo(livingObject->m_objectId);
                    TimerHandler::ScheduleTimer(5, 4000, 0, 0);
                    handled = true;
                } else if (m_pendingActionState == kMapActionSelect ||
                           m_pendingActionState == kMapActionInteract) {
                    g_pScreenPane->SetActiveCursor(
                        ScreenPane::kCursorNormal,
                        false);
                    RequestObjectInfo(livingObject->m_objectId);
                    handled = true;
                }
            } else {
                clearQueuedState = false;
                m_leftButtonTrackingActive = false;
                ClearPendingActionPoll();
            }

            m_highlightedObjectPane = NULL;
            ClearPendingActionPoll();
            m_leftButtonTrackingActive = false;
            handled = true;
        }
        break;

    case kEventRightButtonDown:
        if (g_pUserPane->m_nameVisible)
            return true;

        if (m_queuedMapStateRefresh)
            ClearQueuedMapStateRefresh();
        ClearPendingActionPoll();

        if (g_pConfig->m_clickLookEnabled && insideMap) {
            if (m_highlightedObjectPane != NULL &&
                !m_selectedObjectActive) {
                m_highlightedObjectPane->SetHighlightState(false);
            }

            livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (livingObject != NULL &&
                !livingObject->m_terminalAnimation) {
                livingObject->GetSpriteConfig(&objectStatus);
                if (objectStatus.m_actionState == kMapActionView) {
                    if (livingObject == m_localPlayerObjectPane) {
                        RequestLocalPlayerStatus(pointer.m_messageTime);
                        m_highlightedObjectPane = NULL;
                        return true;
                    }
                    if (livingObject == m_selectedObjectPane)
                        return true;

                    livingObject->SetHighlightState(true);
                    m_highlightedObjectPane = livingObject;

                    if (g_pRightButtonMenuPane == NULL)
                        new RightButtonMenuPane;

                    g_pRightButtonMenuPane->RemoveFromLayer();
                    g_pRightButtonMenuPane->UnregisterEventHandler();

                    RectBounds menuBounds;
                    InitRectBounds(
                        &menuBounds,
                        pointer.m_x - 50,
                        pointer.m_y - 50,
                        pointer.m_x + 29,
                        pointer.m_y + 76);
                    g_pRightButtonMenuPane->AddToLayer(
                        &menuBounds,
                        0,
                        NULL,
                        g_mainUiLayerSlots.effectPaneLayerContext);
                    g_pRightButtonMenuPane->RegisterEventHandler(0, 0);
                    g_pRightButtonMenuPane->SetTargetNameAndId(
                        livingObject->m_objectId,
                        livingObject->m_name);
                    return true;
                }

                if (objectStatus.m_actionState == kMapActionSelect ||
                    objectStatus.m_actionState == kMapActionInteract ||
                    objectStatus.m_actionState == kMapActionMoveTo ||
                    objectStatus.m_actionState == kMapActionMoveAndUse) {
                    livingObject->GetMapPosition(&point);
                    RequestLookAtMapPosition(
                        static_cast<unsigned short>(point.column),
                        static_cast<unsigned short>(point.row));
                    m_highlightedObjectPane = NULL;
                    return true;
                }
            }

            itemObject = FindItemObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (itemObject != NULL) {
                itemObject->GetMapPosition(&point);
                RequestLookAtMapPosition(
                    static_cast<unsigned short>(point.column),
                    static_cast<unsigned short>(point.row));
                return true;
            }
        }

        if (insideMap) {
            m_pointerEventY = pointer.m_y;
            m_pointerEventX = pointer.m_x;
            m_pointerEventModifiers = pointer.m_modifiers;
            m_pointerEventDetail = pointer.m_detail;
            m_pointerEventMessageTime = pointer.m_messageTime;
            m_pointerEventType = event->m_type;
            m_rightButtonMovePending = true;

            if (g_useEpfAssets && g_pConfig->m_autoMoveEnabled) {
                point.row = pointer.m_y;
                point.column = pointer.m_x;
                ScreenToMapCoords(&point);
                m_pendingActionRow = point.row;
                m_pendingActionColumn = point.column;
                Sleep(100);
                if (!m_queuedMapStateRefresh &&
                    g_pInputBlockerPane == NULL) {
                    m_queuedMapStateRefresh = true;
                    TimerHandler::ScheduleTimer(6, 44, 0, 0);
                    CaptureMouse();
                }
            }
        }
        m_rightButtonTrackingActive = true;
        break;

    case kEventRightButtonUp:
        m_pointerEventY = pointer.m_y;
        m_pointerEventX = pointer.m_x;
        m_pointerEventModifiers = pointer.m_modifiers;
        m_pointerEventDetail = pointer.m_detail;
        m_pointerEventMessageTime = pointer.m_messageTime;
        m_pointerEventType = event->m_type;

        if (g_pConfig->m_autoMoveEnabled) {
            m_rightButtonMovePending = false;
            clearQueuedState = false;
        } else {
            ClearQueuedMapStateRefresh();
        }
        ClearPendingActionPoll();
        m_rightButtonTrackingActive = false;
        break;

    case kEventLeftButtonDoubleClick:
    case kEventRightButtonDoubleClick:
    case kEventMouseWheel:
    default:
        break;
    }

    if (g_pConfig->m_autoMoveEnabled &&
        clearQueuedState &&
        m_queuedMapStateRefresh) {
        ClearQueuedMapStateRefresh();
    }
    return handled;
}
```

Dependency-complete support formal insertion text follows. These blocks are part of this recommendation and are not deferred investigations.

`by-class/MapPane.md`, inside `class MapPane` before the field declarations:

```cpp
private:
    enum MapActionState
    {
        kMapActionMoveTo = 5,
        kMapActionMoveAndUse = 6,
        kMapActionView = 11,
        kMapActionSelect = 12,
        kMapActionInteract = 14,
        kMapActionGroundItem = 15
    };

    ObjectPane *FindItemObjectAtMapPoint(int y, int x);
```

The same MapPane H callback must replace the provisional field blocks with these exact source fields while preserving every later offset and `sizeof(MapPane) == 0x910`:

```cpp
    int m_pointerEventY;                         // +0x3a0
    int m_pointerEventX;                         // +0x3a4
    unsigned char m_pointerEventModifiers;       // +0x3a8
    int m_pointerEventDetail;                    // +0x3ac
    unsigned int m_pointerEventMessageTime;      // +0x3b0
    unsigned char m_pointerEventType;            // +0x3b4
    // Existing +0x3b8..+0x3eb members remain unchanged.
    unsigned int m_hoveredObjectId;              // +0x3ec
    // Existing +0x3f0..+0x8e7 members remain unchanged.
    bool m_rightButtonMovePending;               // +0x8e8
    int m_pendingActionRow;                      // +0x8ec
    int m_pendingActionColumn;                   // +0x8f0
    int m_pendingActionY;                        // +0x8f4
    int m_pendingActionX;                        // +0x8f8
    int m_actionStartY;                          // +0x8fc
    int m_actionStartX;                          // +0x900
    int m_pendingActionState;                    // +0x904
    unsigned int m_pendingActionTargetObjectId;  // +0x908
    bool m_rightButtonTrackingActive;            // +0x90c
    unsigned char m_pendingActionModifiers;       // +0x90d
    bool m_leftButtonTrackingActive;             // +0x90e
```

The omitted bytes at `+0x3a9..+0x3ab`, `+0x3b5..+0x3b7`, `+0x8e9..+0x8eb`, and `+0x90f` are compiler-natural alignment/tail padding, not handwritten members. Under 32-bit MSVC layout, the following `int`/existing dword-aligned member and final `sizeof(MapPane) == 0x910` preserve every listed offset without exposing reverse-engineered padding arrays in source.

New exact MapPane helper child `[0x0050c550,0x0050c5d2)` CPP insertion; its H remains blank because the class declaration above owns the declaration:

```cpp
ObjectPane *MapPane::FindItemObjectAtMapPoint(int y, int x)
{
    List *itemObjects = m_objectList->GetPrimaryCellList();
    for (int index = itemObjects->GetCount() - 1; index >= 0; --index) {
        ObjectPane *itemObject =
            *static_cast<ObjectPane **>(itemObjects->GetElementAt(index));
        RectBounds bounds;
        itemObject->GetBounds(&bounds);
        if (PointInRect(y, x, &bounds))
            return itemObject;
    }
    return NULL;
}
```

UID0003TU CPP insertion and blank-H disposition; external linkage is required because MapPane and RightButtonMenuPane source files both call it. The child owns the sole CPP definition below. Its H block must remain blank because UID00007Q already emits the one global-scope declaration in `MapPane.h` before `class MapPane`; command `19152` proved that emitting the same declaration from both channels duplicates it in generated `MapPane.h`.

```cpp
void __stdcall RequestObjectInfo(unsigned int objectId)
{
    unsigned char packet[7];
    PacketBufferWriteUInt8(0x43, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt32BE(objectId, packet + 2);
    packet[6] = 0;
    g_packetSender->QueueAndSendPacket(packet, 6);
}
```

UID0003TU exact H insertion text is therefore empty. The one covered-by class-header declaration remains:

```cpp
// by-class/MapPane.md, global scope before class MapPane
void __stdcall RequestObjectInfo(unsigned int objectId);
```

UID0000C0 `by-class/RightButtonMenuPane.md` exact CPP-scaffold prefix replacement. Replace only the current single include line with these two lines; retain the four existing file-static declarations and `[[CHILDREN]]` byte-for-byte afterward. This is the compile-visible cross-TU route for UID0004F9 and does not duplicate the UID0003TU definition:

```cpp
#include "RightButtonMenuPane.h"
#include "../../map/MapPane.h"
```

UID0004F9 `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md` exact CPP replacement payload. Its H remains blank because UID0000C0 already declares `virtual bool OnEvent(const PaneEvent *event);`. The ordinary callback must set `EMITTER_UIDS:0000C0`, replace the blank CPP block with this complete body, update `88/90 -> 92/94`, and preserve the immediately following UID0004FA compiler jump tables as non-source data:

```cpp
bool RightButtonMenuPane::OnEvent(const PaneEvent *event)
{
    const int y = event->m_y;
    const int x = event->m_x;
    signed char menuItem;

    switch (event->m_type)
    {
    case kEventCursorMove:
        menuItem = HitTestRightButtonMenuItem(y, x);
        if (menuItem != m_highlightedMenuItem)
        {
            m_highlightedMenuItem = menuItem;
            Invalidate();
        }
        if (menuItem != kNoMenuItem && g_pVoteMenuPane != NULL)
            g_pVoteMenuPane->MarkForDeletion();
        return menuItem != kNoMenuItem;

    case kEventLeftButtonDown:
        menuItem = HitTestRightButtonMenuItem(y, x);
        if (menuItem == kNoMenuItem)
            return false;
        m_menuItemPressed = true;
        m_highlightedMenuItem = menuItem;
        Invalidate();
        return true;

    case kEventLeftButtonUp:
        if (!m_menuItemPressed)
            return false;

        menuItem = HitTestRightButtonMenuItem(y, x);
        m_menuItemPressed = false;
        m_highlightedMenuItem = kNoMenuItem;
        Invalidate();

        switch (menuItem)
        {
        case kLookMenuItem:
            if (g_pWebBoardDialog == NULL)
                new WebBoardDialog(4, m_targetName, 0, 0);
            {
                LivingObjectPane *target = static_cast<LivingObjectPane *>(
                    g_activeMapPane->FindObjectPaneById(m_targetId));
                if (target != NULL)
                    target->SetHighlightState(false);
            }
            break;

        case kTradeMenuItem:
            {
                unsigned char packet[7];
                PacketBufferWriteByte(0x4a, packet);
                PacketBufferWriteByte(0, packet + 1);
                PacketBufferWriteUInt32BE(m_targetId, packet + 2);
                packet[6] = 0;
                g_packetSender->QueueAndSendPacket(packet, 6);
            }
            break;

        case kWhisperMenuItem:
            new NewSayToUserMessageInputPane(m_targetName);
            break;

        case kGroupMenuItem:
            {
                char convertedName[0x100];
                unsigned char packet[0x12c];
                PacketBufferWriteByte('.', packet);
                const short wideLength = static_cast<short>(wcslen(m_targetName));
                const int convertedLength = WideCharToMultiByte(
                    CP_ACP,
                    0,
                    m_targetName,
                    wideLength,
                    convertedName,
                    sizeof(convertedName),
                    NULL,
                    NULL);
                convertedName[convertedLength] = '\0';
                PacketBufferWriteByte(
                    static_cast<unsigned char>(convertedLength),
                    packet + 1);
                memmove(packet + 2, convertedName, convertedLength);
                const int packetLength = convertedLength + 2;
                packet[packetLength] = 0;
                g_packetSender->QueueAndSendPacket(
                    packet,
                    static_cast<short>(packetLength));
            }
            break;

        case kInfoMenuItem:
            RequestObjectInfo(m_targetId);
            break;
        }

        CloseRightClickAndVoteMenus();
        return true;

    case kEventRightButtonDown:
        if (!PointInRect(y, x, &m_visibleBounds))
        {
            CloseRightClickAndVoteMenus();
            return true;
        }
        break;
    }

    return false;
}
```

The UID0004F9 body deliberately keeps the observed Trade and Group packet construction inline: live evidence reports no calls/xrefs to the retained raw packet-helper starts at `0x00555780/0x005557e0`. Only the external Info helper becomes `RequestObjectInfo`; replacing the inline packet bodies with those no-route raw helpers would falsify the call graph.

UID0003TV CPP insertion; its H remains blank because the helper is MapPane.cpp-local. The matching source-local prototype already shown at the start of the UID00037S CPP block must precede the target definition; UID0003TV emits only this sole later definition:

```cpp
static void __stdcall RequestLookAtMapPosition(
    unsigned short column,
    unsigned short row)
{
    unsigned char packet[6];
    PacketBufferWriteUInt8(0x0a, packet);
    PacketBufferWriteUInt16BE(column, packet + 1);
    PacketBufferWriteUInt16BE(row, packet + 3);
    packet[5] = 0;
    g_packetSender->QueueAndSendPacket(packet, 5);
}
```

New exact UserPane-owned helper child `[0x005a4f70,0x005a500f)` CPP and H insertions. Emit the definition in `UserPane.cpp` and the declaration at global scope in `UserPane.h` before `class UserPane`, not as a class member:

```cpp
void __stdcall RequestLocalPlayerStatus(unsigned int requestTime)
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x2d, packet);
    PacketBufferWriteUInt8(0, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);

    if (g_useEpfAssets)
        g_epfLocalPlayerStatusRequestTime = requestTime;
    else
        g_legacyLocalPlayerStatusRequestTime = requestTime;
}
```

```cpp
void __stdcall RequestLocalPlayerStatus(unsigned int requestTime);
```

Applied registration payload for [UID:0004YB] at `by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md`. The Markdown quote marker `>` preserves the exact pre-registration payload; command 18866 created the literal first-line UID, and the ordinary page now contains this content:

> *** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
> ObjectPane *MapPane::FindItemObjectAtMapPoint(int y, int x)
> {
>     List *itemObjects = m_objectList->GetPrimaryCellList();
>     for (int index = itemObjects->GetCount() - 1; index >= 0; --index) {
>         ObjectPane *itemObject =
>             *static_cast<ObjectPane **>(itemObjects->GetElementAt(index));
>         RectBounds bounds;
>         itemObject->GetBounds(&bounds);
>         if (PointInRect(y, x, &bounds))
>             return itemObject;
>     }
>     return NULL;
> }
> *** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
> *** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
> *** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
> *** Item Summary: Exact private MapPane item-object hit test that reverse-scans ObjectList primary item storage, obtains each ObjectPane bounds, and returns the topmost item containing the Y-first map point; three direct pointer-event callers, exact thiscall ABI, and class declaration/source route are resolved. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** Nested:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
>
> # 0x0050c550-0x0050c5d2 MapPane Find Item Object At Map Point
>
> ## Status And Source Placement
>
> - Exact half-open range: `0x0050c550-0x0050c5d2`, size `0x82` / 130 bytes.
> - Source entity: private `ObjectPane *MapPane::FindItemObjectAtMapPoint(int y, int x)` method.
> - Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); source root [UID:0000L3][MapPane](by-file/MapPane.md) `MapPane.cpp`.
> - Declaration placement: exactly once in the private MapPane declaration. This child H block is blank because [UID:00007Q] owns that declaration.
> - Address indexes: [UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) is the direct address-sorted split index inside [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md); neither index owns or duplicates this method body.
> - This earlier-address child becomes the first exact child under UID00037Y with `Nested:4`; existing [UID:0004PZ][0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer](by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md) changes only `Nested:4 -> 0`.
>
> ## Exact Behavior And ABI
>
> The method obtains `m_objectList->GetPrimaryCellList()`, iterates from the final list element toward index zero, reads each stored `ObjectPane *`, obtains its `RectBounds`, and returns the first pane for which `PointInRect(y,x,&bounds)` succeeds. Reverse traversal preserves topmost-first item selection. It returns `NULL` when no item contains the point. The source arguments are Y first and X second, matching all three direct callers and the established MapPane point-test convention.
>
> ## Caller And Reachability Evidence
>
> - Direct calls at `0x005072f3`, `0x00507789`, and `0x00507ace` all originate in [UID:00037S][0x00507150-0x00507c90.MapPaneMouseEventCore](by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md).
> - The three paths use the result as an item `ObjectPane`, distinct from living-object helper `0x0050c470`.
> - Live IDA prestate is `sub_50C550`, `int __thiscall(_DWORD **this,int,int)`, exact size `0x82`; the supervisor Gate2B handoff in the B009 report supplies the complete proposed name/type/comments and literal frame/local prestate.
>
> ## Ownership, Naming, And Rejected Alternatives
>
> `MapPane` is the direct semantic and emitted owner because the helper consumes `m_objectList`, follows the MapPane item-hit family, and is called only by the MapPane pointer callback. `FindItemObjectAtMapPoint` is preferred over `HitTestObjectAtPoint` because sibling `FindObjectAtMapPoint` covers living objects while this body specifically scans primary item objects. ObjectList is a dependency, not the source owner; the broad UID0001AT address index is non-authoritative for method ownership.
>
> ## Range And Compiler Boundaries
>
> IDA models one function exactly over `[0x0050c550,0x0050c5d2)`. Bytes outside that interval remain outside this child and with the existing MapPane aggregate/padding classifications. No jump table, shared tail, compiler thunk, or data island is included in the method source.
>
> ## Positive And Negative Evidence
>
> - Positive: exact modeled range, three direct callers, reverse primary-list traversal, typed ObjectPane result use, GetBounds/PointInRect calls, and direct MapPane field access.
> - Negative: no evidence supports a free helper, LivingObjectPane owner, ObjectList member, X-first ABI, forward traversal, or separate H-emitting declaration.
> - Historical raw labels such as `sub_50C550` remain search aliases only and must not appear in final source.
>
> ## Score Rationale
>
> `92/94` is justified by exact behavior, ABI, range, caller set, owner/emitter, human source name, formal CPP, and declaration route. Scores remain below 95 because the original private lexeme is stripped and final callback/compile/generated verification has not yet occurred.
>
> ## Cross-References
>
> - [UID:00037S][0x00507150-0x00507c90.MapPaneMouseEventCore](by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md)
> - [UID:00007Q][MapPane](by-class/MapPane.md)
> - [UID:0000L3][MapPane](by-file/MapPane.md)
> - [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md)
>
> ## Changes
>
> - 2026-07-29 B009 registration payload: split the live item-hit helper into its exact source-bearing child with complete behavior, source placement, score, CPP, and blank-H disposition. Validator allocation supplies the UID; no UID is hand-authored.

Applied registration payload for [UID:0004YC] at `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md`. The Markdown quote marker `>` preserves the exact pre-registration payload; command 18867 created the literal first-line UID, and the ordinary page now contains this content:

> *** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** CANONICAL_OWNER:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** EMITTER_UIDS:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
> void __stdcall RequestLocalPlayerStatus(unsigned int requestTime)
> {
>     unsigned char packet[3];
>     PacketBufferWriteUInt8(0x2d, packet);
>     PacketBufferWriteUInt8(0, packet + 1);
>     packet[2] = 0;
>     g_packetSender->QueueAndSendPacket(packet, 2);
>
>     if (g_useEpfAssets)
>         g_epfLocalPlayerStatusRequestTime = requestTime;
>     else
>         g_legacyLocalPlayerStatusRequestTime = requestTime;
> }
> *** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
> *** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
> void __stdcall RequestLocalPlayerStatus(unsigned int requestTime);
> *** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***
> *** Item Summary: Exact externally linked UserPane.cpp status-request helper that sends opcode 0x2d subtype 0 as two bytes and records the request time in the EPF or legacy slot selected by g_useEpfAssets; MapPane, IconsPane, raw old-HUD, and TabPane callers plus the inline UserPane equivalent establish source role and linkage. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
> *** Nested:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
>
> # 0x005a4f70-0x005a500f Request Local Player Status
>
> ## Status And Source Placement
>
> - Exact half-open range: `0x005a4f70-0x005a500f`, size `0x9f` / 159 bytes.
> - Source entity: externally linked `void __stdcall RequestLocalPlayerStatus(unsigned int requestTime)`.
> - Direct owner/emitter: [UID:0000P1][UserPane](by-file/UserPane.md), emitted in `UserPane.cpp`; its global-scope declaration belongs in `UserPane.h` before `class UserPane`.
> - Address indexes: [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md) and [UID:0001KM][0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md) contain the address but do not emit this helper.
> - This earlier-address child becomes the first exact child under UID0001KO with `Nested:4`; existing [UID:0004US][0x005a50a0-0x005a5103.EnsureNormalBulletinSession](by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md) changes only `Nested:4 -> 0`.
>
> ## Exact Behavior And ABI
>
> The helper serializes opcode `0x2d` and subtype `0`, queues exactly two bytes through `g_packetSender`, and stores `requestTime` to `g_epfLocalPlayerStatusRequestTime` when `g_useEpfAssets` is true or `g_legacyLocalPlayerStatusRequestTime` otherwise. The terminal `retn 4` proves one callee-cleaned argument. Callers ignore residual EAX, so the human source return is `void` while preserving `__stdcall`.
>
> ## Caller, Storage, And Inline-Equivalent Evidence
>
> - [UID:00037S] calls the helper with the pointer event message time on local-player click-look.
> - [UID:0002T2] IconsPane action 2 and retained raw [UID:00022Q] old-HUD action 2 call the same helper with zero; [UID:00034O] TabPane action 0 passes the exact `event->m_payload.m_key.m_messageTime` overlay at `event+0x10c`, never zero.
> - [UID:0003V9] UserPane key `s` contains the accepted inline-equivalent packet/store sequence; it remains inline rather than being rewritten into a helper call.
> - The only request-time storage destinations are [UID:00030A]'s EPF/legacy dwords at `0x0069bf6c/0x0069bf70`, selected by `g_useEpfAssets`.
> - Live IDA prestate is `sub_5A4F70`, `int __stdcall(int)`, exact size `0x9f`, terminal `retn 4`; the supervisor Gate2B handoff in the B009 report supplies the complete proposed name/type/comments and literal frame/local prestate.
>
> ## Ownership, Naming, And Rejected Alternatives
>
> UserPane.cpp is the strongest source owner because the helper and both request-time globals belong to the local-player UI/status family, and cross-source MapPane/IconsPane/TabPane callers require external linkage. `RequestLocalPlayerStatus` is preferred over `SendOpcode2DAndStoreExtra` or other opcode-derived names because four UI intents and the inline UserPane equivalent identify a local-player status request and request-time tracking. SayInputPanes, MapPane, IconsPane, TabPane, transport code, and the mixed UID0001KO index are dependencies/consumers, not the physical owner.
>
> ## Range And Compiler Boundaries
>
> IDA models one function exactly over `[0x005a4f70,0x005a500f)`. The preceding modeled helper ends at `0x005a4f62`; `[0x005a4f62,0x005a4f70)` remains separate compiler alignment. The following modeled helper begins at `0x005a5010`; the one-byte `[0x005a500f,0x005a5010)` boundary remains outside this child. No packet table, shared tail, or compiler wrapper is included in the source body.
>
> ## Positive And Negative Evidence
>
> - Positive: exact packet bytes/length, terminal cleanup, complete direct-caller family, inline UserPane equivalent, exclusive EPF/legacy storage writes, and coherent UserPane source route.
> - Negative: no evidence supports a UserPane member receiver, a return-value contract, opcode-derived final source name, SayInputPanes ownership, MapPane-local linkage, or a synthetic packet module.
> - Historical `sub_5A4F70`, `SendOpcode2DAndStoreExtra`, and `g_opcode2d*` names remain search aliases only and must not survive in formal source.
>
> ## Score Rationale
>
> `92/94` is justified by exact behavior, packet format, ABI, range, caller/storage family, source owner/linkage, semantic names, and complete CPP/H. Scores remain below 95 because the original helper/global spellings are inference-backed and final callback/compile/generated verification has not yet occurred.
>
> ## Cross-References
>
> - [UID:00037S][0x00507150-0x00507c90.MapPaneMouseEventCore](by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md)
> - [UID:00030A][0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots](by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md)
> - [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md)
> - [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md)
> - [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md)
> - [UID:0003V9][0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md)
> - [UID:0000P1][UserPane](by-file/UserPane.md)
>
> ## Changes
>
> - 2026-07-29 B009 registration payload: split the live status-request helper into its exact source-bearing child with complete packet/storage behavior, caller family, source placement, score, CPP/H, and UID0001KO nesting reconciliation. Validator allocation supplies the UID; no UID is hand-authored.

UID00030A CPP replacement and UID0003V9 inline-write synchronization:

```cpp
static unsigned int g_epfLocalPlayerStatusRequestTime = 0;
static unsigned int g_legacyLocalPlayerStatusRequestTime = 0;
```

Exact support formal replacements are bounded transactions, not prose-only examples:

- UID0002T2 `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md`: in the existing formal CPP block, replace the sole exact line `SendOpcode2DAndStoreExtra(0);` with `RequestLocalPlayerStatus(0);`. Preserve every other line and keep the existing H block blank.
- UID00022Q `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md`: in the existing formal CPP block, replace the sole exact line `SendOpcode2DAndStoreExtra(0);` with `RequestLocalPlayerStatus(0);`. Preserve every other line, the retained-raw/no-route disposition, `88/90`, and the blank H block.
- UID00034O `by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md`: in the existing formal CPP block, replace the sole exact line `SendOpcode2DAndStoreExtra(event->m_payload.m_key.m_messageTime);` with `RequestLocalPlayerStatus(event->m_payload.m_key.m_messageTime);`. This is the exact `event+0x10c` key-payload overlay observed at `0x004cfa61`; replacing the argument with zero or `event->m_payload.m_pointer.m_messageTime` at `+0x18` is forbidden. Preserve every other line, `92/94`, and the blank H block.
- UID0003V9 `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md`: in the existing formal CPP block's key-`s` inline packet branch, replace exactly `g_opcode2dEpfCommandExtraValue = event->m_messageTime;` with `g_epfLocalPlayerStatusRequestTime = event->m_payload.m_key.m_messageTime;` and exactly `g_opcode2dLegacyCommandExtraValue = event->m_messageTime;` with `g_legacyLocalPlayerStatusRequestTime = event->m_payload.m_key.m_messageTime;`. Preserve the inline two-byte packet send, branch condition, return, every unrelated key path, `92/94`, and the blank H block; do not replace this inline duplicate with a helper call.
- UID0004F9 `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md`: replace its blank formal CPP block with the complete `RightButtonMenuPane::OnEvent` payload above, keep H blank, set emitter UID0000C0, and use the `RequestObjectInfo(m_targetId)` Info case exactly once. UID0000C0's two-include prefix above is required in the same callback so that call is declared in `RightButtonMenuPane.cpp`.

These exact transactions supersede every later broad instruction that formerly said UID00034O should pass zero. UID0002T2 and UID00022Q pass zero; UID00034O passes the `+0x10c` message-time overlay; UID00037S passes the pointer payload's `+0x18` message time; UID0003V9 keeps its inline key-payload write.

UID0003TK exact tail replacement, preserving the binary's two independent `g_useEpfAssets` tests:

```cpp
    if (g_useEpfAssets &&
        g_pConfig->m_autoMoveEnabled &&
        m_queuedMapStateRefresh) {
        m_rightButtonTrackingActive = false;
        ClearQueuedMapStateRefresh();
    }
    if (g_useEpfAssets &&
        !m_rightButtonTrackingActive &&
        m_queuedMapStateRefresh) {
        m_leftButtonTrackingActive = false;
        ClearQueuedMapStateRefresh();
    }
```

UID0003TL exact EPF-branch tail replacement; there is no `RefreshDeferredMapSurfacesForTileRegion` source helper:

```cpp
        if (g_pConfig->m_autoMoveEnabled &&
            m_waitingForLocalPlayerStatus &&
            m_queuedMapStateRefresh) {
            m_rightButtonTrackingActive = false;
            ClearQueuedMapStateRefresh();
        }
        if (!m_rightButtonTrackingActive &&
            m_waitingForLocalPlayerStatus &&
            m_queuedMapStateRefresh) {
            m_leftButtonTrackingActive = false;
            ClearQueuedMapStateRefresh();
        }
```

`by-class/ScreenPane.md`, public source-header insertion before `SetActiveCursor`:

```cpp
    enum CursorIndex
    {
        kCursorNormal = 7,
        kCursorSelect = 8,
        kCursorView = 9,
        kCursorPut = 10,
        kCursorAttack = 11
    };
```

Source/API migration callback scope is exact: replace `SendOpcode2DAndStoreExtra(0)` with `RequestLocalPlayerStatus(0)` in UID0002T2 and UID00022Q; replace UID00034O's existing call with `RequestLocalPlayerStatus(event->m_payload.m_key.m_messageTime)` from `+0x10c`; replace the two `g_opcode2d*` source globals with the two status-request-time names in UID00030A, UID0003V9, and UserPane support docs; replace stale object-info aliases in UID0000C0 and UID0004F9 and add the exact compile-visible include/formal route above; preserve all old labels in historical/search-alias prose. No affected code-emitting page may retain the old API after callback.

- Behavior preservation: the code retains all early returns, event-case asymmetries, click-move/click-look gates, Sleep/timer/capture ordering, double-click/wheel default behavior, four pending-poll clears, and final conditional queued-state drain.
- Source shape: ordinary C++ member code, class fields, enums, ABI-correct `__stdcall` free helpers, helper calls, and RAII-free C++03-era control flow match the likely precompiled game source. No decompiler locals, raw offsets, or compiler tables appear.
- Naming convention: project-established `m_` members, `g_` globals, PascalCase methods, and `k` constants. Inferred names are selected by behavior and cross-consumer consistency, not left as IDA labels.
- Third-party import directive: not applicable; this is first-party NexusTK MapPane source.

## Final Recommendation

- UID00037S is updated with the complete behavior/state-machine evidence, exact method and tail boundaries, event/cursor/action fields, caller/helper inventory, formal CPP body, blank-H proof, and `93/94` score.
- Preserve `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00007Q`.
- UID00007Q's private fields/helper/enum are synchronized without duplicate virtual declarations. Exact children UID0004YB and UID0004YC were created in order from the accepted payloads, validated, and declared as additional targets.
- UID00037Y/UID0001KO inventories include those children, and displaced first children UID0004PZ/UID0004US now use `Nested:0` with all prior source/history preserved.
- UID0003ZS/UID0003TK/UID0003TL and MapPane use exact input/action/tracking fields; movement-array/token/deferred-surface/nonexistent-helper interpretations are historicalized.
- UID0003TU `RequestObjectInfo` and UID0003TV `RequestLookAtMapPosition` are complete `90/92` source items with exact linkage dispositions: UID0003TU owns the sole CPP definition and has a blank child H covered by UID00007Q's one class-header declaration; UID0003TV owns its static CPP definition with blank H.
- Every affected status-request caller and both request-time globals now use `RequestLocalPlayerStatus`, `g_epfLocalPlayerStatusRequestTime`, and `g_legacyLocalPlayerStatusRequestTime`; UID0002T2/UID00022Q pass zero, UID00034O passes key message time from `+0x10c`, UID00037S passes pointer message time from `+0x18`, and UID0003V9 remains intentionally inline.
- The RightButtonMenu support route is closed: UID0004F9 emits complete `92/94` CPP with `RequestObjectInfo(m_targetId)`, and UID0000C0 has the exact MapPane include while preserving setter/layout/score and file history.
- Catalog entry `0355` has applied or explicitly dispositioned every item-specific IDA row from restored session/database `1da2b2ae`, using the literal IDA-only gap guards and preserving the compiler tail, vtable cell, successor, prerequisite types, opaque MapPane tail, bytes, ranges, xrefs, and boundaries. The saved IDB identity is recorded under IDA MCP Facts and Changed Files.
- Non-blocking exclusion: this report recommends no whole-MapPane-tail IDA carve. The target semantics at `+0x8e8..+0x90f` are closed for documentation and source, but IDA's single opaque member begins at `+0x4dc`; a target-only carve would disturb unrelated unresolved bytes through `+0x8e7`. The exact safe current action is therefore the explicit no-change row above, not deferred target research.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md`.
- Replace the unresolved summary with: exact `MapPane::HandlePointerOrMouseEvent(Event *)` source method; EventHandler-facet receiver normalization; full event case matrix; event snapshot/action/tracking fields; living/item hit results; hover/nameplate behavior; cursor constants; click-move/click-look/right-menu/timer/packet behavior; four UID00042I calls; exact NOP/table tail; formal source.
- Metadata: `85/89 -> 93/94`; owner/emitter/reconstructable unchanged; CPP becomes the exact source-local `RequestLookAtMapPosition` prototype plus method body above; H remains blank with no-duplicate explanation; Item Summary should describe the resolved source method without repeating generated metadata fields.
- Preserve historical assumptions in a clearly labeled superseded section: unresolved constants/fields/tail, provisional helper/opcode names, and old field aliases. Preserve the negative proof against split/table emission and explicit shifted-pointer source.

## Recommended Support Doc Changes

All ordinary rows in this table were applied and validated during the accepted callback unless the row explicitly says no ordinary edit or supervisor-owned manual/IDA work. The table remains as the claim-level specification used for verification.

| Support path | Required incorporation |
| --- | --- |
| `by-class/MapPane.md` | Replace `m_pendingMovementState[6]` and `m_pendingMapStateToken`; use byte `m_pointerEventType` and compiler-natural unnamed alignment rather than `EventType` or explicit padding arrays; replace `+0x8e8..+0x90f` provisional fields with the exact source fields and natural padding in this report; add `MapActionState` values `5/6/11/12/14/15` and `FindItemObjectAtMapPoint`; retain the existing virtual once; document UID00037S, UID0003TU, and UID0003TV source contracts. Keep class `93/94`. |
| [UID:0004YB] `by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md` | Created/validated by command 18866 from the complete `92/94` payload, read back actual UID0004YB, and declared it as an additional report target. Reverse primary-item-list traversal, topmost-first hit semantics, exact range, three UID00037S callers, direct UID00007Q owner/emitter, complete CPP, blank H, and first-child `Nested:4` are preserved. |
| `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md` (UID00037Y) | Add the validated item-hit child to the exact function/child inventory as the first address-sorted source-bearing child, linked by its actual assigned UID. Preserve UID00037Y's existing `87/89`, owner/emitter state, aggregate source/no-source distinctions, every unrelated helper, and its own formal disposition. |
| `by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md` (UID0004PZ) | After the earlier-address item-hit child validates, change only `Nested:4 -> 0` so address-sorted child nesting under UID00037Y remains correct. Preserve UID0004PZ `92/94`, owner/emitter UID00007Q, formal CPP/blank H, source role, evidence, history, and manual-row wording exactly. |
| `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` (UID0003ZS) | Synchronize exact row/column, pixel target, action start, action state, target id, modifier, and left/right tracking names. Preserve timer behavior and current `89/91`; its current manual row is already broad enough and needs no replacement. |
| `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` (UID0003TK) | Replace the stale two-stage EPF refresh tail with the exact two independent `g_useEpfAssets` branches and mouse-tracking/queued-state clears above. Preserve `92/94`; replace its stale manual row text. |
| `by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md` (UID0003TL) | Replace the nonexistent `RefreshDeferredMapSurfacesForTileRegion` interpretation and formal tail with the exact waiting/status, tracking, and queued-state cleanup above. Historicalize the rejected deferred-surface interpretation; preserve `90/90`; replace its stale manual row text. |
| `by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md` (UID0003TU) | Rename the source item to `RequestObjectInfo`, preserve external linkage for MapPane and RightButtonMenu callers, retain the exact sole CPP definition, blank the child H with explicit covered-by UID00007Q class-header reasoning, retain `{0x43,1,BE32 id}`, migrate all calls, and keep `90/92`. Command `19154` validates this correction; the current manual row is literal-equal to the corrective single-owner payload, and command `19201` proves the generated declaration/definition topology. |
| `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md` (UID0004F9) | Replace every historical `sub_50F4D0`/`MapPaneSendObjectAction43Packet` alias with historical evidence plus current `RequestObjectInfo`; populate the former blank CPP block with the complete formal body above, keep H blank, set `EMITTER_UIDS:0000C0`, change `88/90 -> 92/94`, preserve exact range/event/action/vtable/no-route packet-helper facts, and validate independently. The formerly absent manual row is now inserted at the exact staged anchor. |
| `by-class/RightButtonMenuPane.md` (UID0000C0) and `by-file/RightButtonMenuPane.md` (UID0000N7) | Preserve `SetTargetNameAndId(int,const wchar_t *)`, class layout, unrelated children, and current scores. In UID0000C0 replace the one-line CPP prefix with the exact two-include prefix above so `RightButtonMenuPane.cpp` sees `RequestObjectInfo`; replace the stale Info-row aliases with the semantic helper and record UID0004F9 as source-ready. In UID0000N7 replace only stale constructor/OnEvent-pending prose with the accepted UID0004F9 route and preserve every unrelated file family. Their exact C38Y/C38Z manual class/file replacements are applied. |
| `by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md` (UID0003TV) | Rename the source item to static `RequestLookAtMapPosition`, insert the exact sole CPP definition above with blank H, retain the matching source-local prototype before UID00037S, retain `{0x0a,BE16 column,BE16 row}`, migrate both click-look calls, and raise `86/89 -> 90/92`. The formerly absent manual row is now inserted at the exact address-sorted anchor. |
| `by-class/ScreenPane.md` and UID00039X cursor loader | Add one public `CursorIndex` enum for values `7..11` before `SetActiveCursor`; retain the loader order as direct evidence and preserve ScreenPane layout. UID00039X remains `90/91` and its broad current manual row requires no replacement. |
| [UID:0004YC] `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md` | Created/validated by command 18867 from the complete `92/94` payload, read back actual UID0004YC, and declared it as an additional report target. External UserPane.cpp owner/emitter UID0000P1, complete CPP/global H, `{0x2d,0}`, two-byte send, request-time write, caller set, and first-child `Nested:4` are preserved. |
| `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` (UID0001KO) | Add the validated status-request child to the exact function/child inventory as the first address-sorted non-say child, linked by its actual assigned UID and explicitly owned/emitted by UserPane.cpp rather than this mixed index. Preserve UID0001KO `86/88`, owner NONE, reconstructable false, blank emitter/formals, every say/non-say split fact, and all other child rows. |
| `by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md` (UID0004US) | After the earlier-address RequestLocalPlayerStatus child validates, change only `Nested:4 -> 0` so address-sorted child nesting under UID0001KO remains correct. Preserve UID0004US `90/93`, owner/emitter UID0000P1, formal CPP/blank H, source role, evidence, history, and manual-row wording exactly. |
| `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md` (UID00030A) | Replace opcode-derived source globals with `g_epfLocalPlayerStatusRequestTime` and `g_legacyLocalPlayerStatusRequestTime`, retain zero initialization and old labels as history, keep `88/90`, and replace the stale `84%` manual row. |
| UID0002T2, UID00022Q, and UID00034O | Apply the exact formal transactions above: UID0002T2 and UID00022Q use `RequestLocalPlayerStatus(0)`, while UID00034O must use `RequestLocalPlayerStatus(event->m_payload.m_key.m_messageTime)` from `+0x10c`, never zero. Preserve all unrelated event/action logic and current scores `89/91`, `88/90`, and `92/94`. All three formerly stale manual rows were replaced; UID00034O now records the proved message-time argument rather than the historical `preserved +0x10c overlay read` wording. |
| UID0003V9 plus UserPane class/file support | Replace the inline opcode-derived request-time global names with the semantic EPF/legacy names; document equivalence to the new helper without rewriting the intentionally inline key-`s` packet path. Preserve UID0003V9 `92/94`; its broad current row requires no replacement. |
| `by-file/MapPane.md` | Add a bounded source-contract summary linking UID00037S, the exact item-hit helper child, and UID0003TU/TV; preserve all existing MapPane source families and keep `92/92`. |
| LivingObjectPane support | No ordinary edit is required: current declarations already provide `m_terminalAnimation` and `SetHighlightState(bool)`. Record inspected no-change proof rather than duplicating declarations. RightButtonMenuPane is not no-change; its exact UID0000C0/UID0004F9/UID0000N7 edits are listed separately above. |
| UID00042F `by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md` | No ordinary source change is required: current formal CPP already defines `MapPane::ClearQueuedMapStateRefresh`, the MapPane class already declares it once, and current `90/92` behavior covers the exact flag clear, timer 6/8 cancellation, and mouse-capture release used by this target. Record callback readback and preserve its current manual row. |
| UID00004L `by-class/Event.md` | No ordinary edit is required: current source already declares `unsigned char m_type` and natural alignment before `EventPayload`. Catalog `0355` corrected only the stale four-byte IDA member to byte `m_type +0x4` plus IDA-only `_gap5[3] +0x5`, preserving payload `+0x8`, size `0x110`, the source doc, class score `94/95`, and all unrelated Event evidence. |

## Score And Metadata Recommendation

- Historical pre-callback state: `85/89`, owner/emitter `00007Q`, reconstructable true, blank CPP/H.
- Current implemented state: `93/94`, owner/emitter `00007Q`, reconstructable true, populated CPP, blank H.
- Reason not lower: complete live-MCP method and tail boundaries, full state machine, exact event values/payload, direct field use, helper bodies, vtable ownership, xrefs, formal human source, support closure, and negative split proof.
- Reason not higher: original private field/action-enum lexical spellings are stripped, semantic helper/global names are high-probability inference rather than recovered symbols, and the broad unrelated MapPane IDA tail remains opaque. Catalog `0355` closes the bounded IDA work, the current manual row closes C38D, and command `19201` closes generated topology; none is a remaining score blocker. Report gate/execution status is independent of this score and is intentionally deferred to the current path plus validator-owned history/status metadata; project policy reserves `95/95+` for substantially final code.
- Score-improvement attempt: every target-stated blocker was investigated through its supporting callers, helpers, types, fields, and source routes. Constants, cursor declarations, byte discriminator widths, natural padding, fields, hit results, receiver normalization, UID00042I routes, exact tail, owner, source placement, UID0003TK/TL corrections, UID0003TU/TV source APIs, opcode-2d status-request migration, and dependency-complete formal code all moved from open to implemented ordinary-source state or explicit supervisor Gate 2 action. No associated investigation is deferred.
- Support metadata after callback: UID00007Q remains `93/94`, UID0000L3 `92/92`, UID0003ZS `89/91`, UID0003TK `92/94`, UID0003TL `90/90`, UID00039X `90/91`, UID00030A `88/90`, UID0002T2 `89/91`, UID00022Q `88/90`, UID00034O `92/94`, UID0003V9 `92/94`, UID0000FQ UserPane class `94/95`, UID0000P1 UserPane file `93/94`, UID0000C0 RightButtonMenuPane class `90/94`, UID0000N7 RightButtonMenuPane file `90/93`, UID0004PZ `92/94`, and UID0004US `90/93`. UID0003TU and UID0003TV are now `90/92`; UID0004F9 is now `92/94`; actual children UID0004YB and UID0004YC are each `92/94`. UID0004PZ and UID0004US now use `Nested:0` because each new earlier-address child became its index's first child.

## Open Questions With Attempted Resolution

- Original lexical names for private action states, fields, helpers, and request-time globals: original symbols are absent, but behavior, offsets, wire formats, and cross-consumers identify each role. The report resolves this with the highest-probability project-style names rather than leaving compiler labels. This limits lexical confidence only, not C++ eligibility.
- Shared cursor declaration location: UID00039X proves values and order; ScreenPane owns storage and selection. A shared ScreenPane header enum is the strongest compile-visible placement. A MapPane-local numeric enum was considered and rejected as unnecessary duplication.
- `0x50f4d0`, `0x50f9c0`, and `0x5a4f70` names: exhaustive body/caller evidence resolves them as `RequestObjectInfo`, `RequestLookAtMapPosition`, and `RequestLocalPlayerStatus`. Exact original lexemes remain unknowable without symbols, but opcode-only or decompiler labels must not survive in accepted source.
- `RequestObjectInfo` header ownership: generated command `19152` disproved the initial two-channel declaration plan by producing identical declarations at `MapPane.h` lines 58 and 369. The closed source-quality disposition is one UID00007Q global declaration, one UID0003TU CPP definition, and a blank UID0003TU H channel with explicit covered-by reasoning; scoped command `19154` validates the ordinary correction. This is resolved, not deferred.
- Large MapPane IDA tail: target semantics are resolved. Because the existing opaque member begins at `+0x4dc`, carving only `+0x8e8..+0x90f` would transactionally disturb unrelated bytes through `+0x8e7`; the evidence-backed current decision is explicitly no IDA mutation while the ordinary class/source documents receive the exact fields. This is a closed safety disposition, not an open question or score blocker.
- UID0003TK/TL and shared opcode-2d migrations: exact formal replacements, caller-specific zero/`+0x10c`/`+0x18` arguments, storage names, and destination documents are implemented and validated. Catalog `0355` also completed both two-phase IDA data-global transactions with exact names/types/comments/bytes/xrefs/fences, so no IDA data action remains pending.
- RightButtonMenu support: UID0000C0 and UID0004F9 were re-read and found stale rather than accepted as no-change. The exact child path, external helper call, complete formal body, emitter/score disposition, compile-visible include, file/class prose migration, validator, and absent-manual-row insertion are now deterministic. The no-route raw packet-helper bodies remain inline by negative xref proof. No associated RightButtonMenu investigation is deferred.
- No behavior, owner, split, dependency, score-gate, or formal-C++ question remains open for UID00037S or its required source/API support closure.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical pre-coverage Gate 1 inspection found UID00037S stale at `85%` and saying constants, fields, and tail remained below formal-C++ quality. The supervisor subsequently applied the complete 30-decision plan; the literal payloads and anchors below are retained as implementation history and verification evidence.
- Exact inspected no-change parent anchor for UID00037Y; this literal current row remains unchanged. The later child insertion is placed beneath it and does not rewrite the parent row:

```text
    - [UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) 0x0050bce0-0x0050e320 | class aggregate | MapPaneTileObjectGridRenderCore : reconstructable : 87% : very strong : Comment-only MapPane method-cluster aggregate with exact helper inventory, field/type evidence, internal route-negative wrapper/padding disposition, and independently registered source children including the exact tile-buffer allocator.
```

- Exact inspected no-change parent anchor for UID0001KO; this literal current row remains unchanged. The later child insertion is placed beneath it and does not rewrite the parent row:

```text
    - [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md) 0x005a4b60-0x005a5791 | non-emitting mixed helper index | SayModeHelpers : not_reconstructable : 86% : strong : Mixed say-mode and adjacent UI action helper neighborhood with nineteen modeled functions, exact source-ready UID0002RX say-mode child, exact UserPane-owned UID0004US EnsureNormalBulletinSession child, boundary padding, caller/source-family distinctions, non-say ownership exclusions, and no synthetic aggregate source body.
```

- Exact UID0004F9 audit: `rg` over the current manual by-memory report returns no UID0004F9/`RightButtonMenuPaneOnEvent` row. The containing UID0001FX row exists, and UID0004F8 is the last current exact child row before the parent-closing ignored `0x0055577b-0x00555780` row. After UID0004F9 ordinary validation, insert immediately after UID0004F8 and before that ignored row exactly:

```text
        - [UID:0004F9][0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent](by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md) 0x00554c40-0x00554f59 | primary virtual event method | RightButtonMenuPane::OnEvent : reconstructable : 92% : very-strong : Exact source-ready right-click target-menu event handler for hover, press, release/action, outside dismissal, vote-popup coordination, Look/Trade/Whisper/Group/Info dispatch, inline Trade/Group packet construction preserved by no-route packet-helper evidence, and external RequestObjectInfo(m_targetId) Info routing through MapPane.h, with complete formal CPP, blank child H, direct UID0000C0 owner/emitter, exact range/vtable/jump-table boundaries, and stale sub_50F4D0/MapPaneSendObjectAction43Packet aliases retained only as history.
```

- File/placement: replace the existing UID00037S row in the nested MapPane section with exactly:

```text
        - [UID:00037S][0x00507150-0x00507c90.MapPaneMouseEventCore](by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md) 0x00507150-0x00507c90 | virtual pointer/mouse event method plus compiler switch support | MapPane::HandlePointerOrMouseEvent : reconstructable : 93% : very-strong : Exact EventHandler-facet MapPane override for cursor move and left/right button down/up, with resolved EventType/pointer payload, cursor resources, LivingObjectPane terminal-animation/highlight API, living/item hit tests, hover/nameplate state, click-move/click-look/action/timer paths, four UID00042I calls, exact RightButtonMenu target API, corrected input-state fields, dependency-complete human C++, and exact 0x507c72 NOP plus seven-entry jump-table tail.
```

- Replace the current stale UID0003TK row with exactly:

```text
        - [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) 0x005104d0-0x00510958 | method | MapPaneHandleEffectMapStatePacket : reconstructable : 92% : very strong : Source-ready opcode-0x15 MapPane effect/map-state packet handler with exact 1,160-byte body and direct dispatcher bool return; parses map id/dimensions, flags, counted ANSI map name, packed day/night adjustment, and target-selection byte; conditionally saves/rebuilds/loads map and ObjectList state; updates weather, movement, day/night, waiting/config, transient pane/layer, and exact EPF queued-input cleanup through m_rightButtonTrackingActive/m_leftButtonTrackingActive and ClearQueuedMapStateRefresh; preserves malformed-packet trust, ignored map-name conversion, and compiler exclusions; and emits complete human C++.
```

- Replace the current stale UID0003TL row with exactly:

```text
        - [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) 0x00510960-0x00511347 | packet method | MapPaneHandleMapInfoTileRegionPacket : reconstructable : 90% : very strong : Complete source-ready opcode-0x06 map-info/tile-region parser with exact flags, strings, resource mode, rectangle clipping, canonical m_mapWidth/m_mapHeight/m_tileBuffer fields, six-byte MapPaneTileRecord updates, redraw/static-object reconciliation, exact EPF auto-move/input-tracking queued-state cleanup through m_rightButtonTrackingActive/m_leftButtonTrackingActive and ClearQueuedMapStateRefresh, preserved malformed-packet trust semantics, and corrected m_waitingForLocalPlayerStatus gate semantics.
```

- Historical pre-coverage state: UID0003TU and UID0003TV had no manual rows, and the accepted 30-decision plan inserted them between UID0003TJ and UID0003TW. Generated command `19152` then proved that the first applied UID0003TU wording `complete formal CPP/H` was stale because the child H channel must be blank and UID00007Q owns the sole `MapPane.h` declaration. The supervisor applied the corrective replacement; the exact current UID0003TU row at line 2439, immediately before UID0003TV, is literal-equal to:

```text
        - [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md) 0x0050f4d0-0x0050f52a | file-level outbound request helper | RequestObjectInfo : reconstructable : 90% : very-strong : Exact MapPane.cpp-owned external helper sending opcode 0x43 subtype 1 plus big-endian object id in six bytes, with two MapPane action callers and the RightButtonMenu Info caller, complete formal CPP, blank child H covered by the sole global RequestObjectInfo declaration in UID00007Q MapPane.h, exact range/padding, and historical opcode-bearing names retained only as aliases.
```

The current UID0003TV row immediately below it is already exact and remains unchanged:

```text
        - [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md) 0x0050f9c0-0x0050fa1b | file-local outbound look request helper | RequestLookAtMapPosition : reconstructable : 90% : very-strong : Exact static MapPane.cpp helper sending opcode 0x0a plus big-endian column/row in five bytes from two click-look callers, with complete formal CPP, exact range/padding, and no duplicate H declaration.
```

- Replace the stale UID00030A, UID0002T2, and UID00022Q rows with exactly:

```text
    - [UID:00030A][0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots](by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md) 0x0069bf6c-0x0069bf74 | paired local-player status request-time globals | LocalPlayerStatusRequestTimeSlots : reconstructable : 88% : very-strong : Exact zero-initialized EPF/legacy unsigned request-time dwords emitted in UserPane.cpp, selected by g_useEpfAssets and written only by RequestLocalPlayerStatus plus the inline UserPane key-s path; historical opcode-derived names and stale 0xffffffff/withheld-owner wording are superseded.
      - [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md) 0x004cf3e0-0x004cf74b | method | IconsPaneOnMouseEvent : reconstructable : 89% : very-strong : Source-ready IconsPane pointer/mouse handler with exact bounds, vtable slot, virtual reachability, capture/release flow, hit-test/highlight and tooltip behavior, input-lock gate, and exact RequestLocalPlayerStatus(0) action-2 call while preserving direct class ownership and all unrelated icon actions.
    - [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) 0x004cf8e0-0x004cf974 | retained raw old-HUD action dispatcher | IconsPaneActionDispatchRawBody : reconstructable : 88% : very-strong : Exact eight-case retained raw action dispatcher with local jump table, exact RequestLocalPlayerStatus(0) action-2 route and remaining downstream helper roles, live no-function/no-direct-xref/no-entry-pointer proof, and no standalone source-emitter route.
```

- Replace the unique current UID00034O row in place between UID00034N `TabPane::OnPaint` and UID00034P `TabPane::HandleKeyOrTextEvent`. Preserve its `92%` score, exact path/range, and surrounding indentation. Replace exactly with:

```text
        - [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md) 0x004cfa10-0x004cfb0a | virtual method | TabPane::HandlePointerOrMouseEvent : reconstructable : 92% : very-strong : Exact EventHandler +0x04 override with Event pointer signature, left-down/double-click action restrictions, canonical m_y/m_x resolver order, signed action code, exact action-0 RequestLocalPlayerStatus(event->m_payload.m_key.m_messageTime) call using the key-payload message time at object +0x10c, preserved unrelated action dispatch, exact helper ABI classes, and sole vtable reachability.
```

- Replace the unique current UID0000C0 row in `by-class/-coverage-report.md` in place between UID0000BZ `RidingImageLib` and UID0000C1 `RingBuffer`. Preserve its `90%` score and indentation. Replace exactly with:

```text
- [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md) : reconstructable : 90% : very-strong : Right-click target-menu class routed to RightButtonMenuPane.cpp with exact first-draft CPP/H scaffold, direct Pane plus empty Singleton<RightButtonMenuPane> inheritance, 0x144 layout, selected/pressed row and target fields, virtual declarations and class-child insertion, source-ready UID0004F9 OnEvent for hover, press, release/action, outside dismissal, vote-popup coordination, Look/Trade/Whisper/Group/Info dispatch, inline Trade/Group packet construction, and external RequestObjectInfo(m_targetId) through MapPane.h, source-ready OnPaint/DrawBackground/DrawBorder, direct-file geometry helper interfaces, direct Look/Trade/Whisper/Group/Info literal policy, exact Info layout anomaly, packet-helper caveat, singleton/vtable/compiler-wrapper boundaries, and remaining constructor body work explicitly separated.
```

- Replace the unique current UID0000N7 row in `by-file/-coverage-report.md` in place between UID0000N6 `RidingImageLib` and UID0000N8 `RingBuffer`. Preserve its `90%` score and indentation. Replace exactly with:

```text
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md) : reconstructable : 90% : very-strong : NexusTK/ui/menu/RightButtonMenuPane.cpp source root with exact class scaffold then address-ordered class methods and direct-file helpers, source-complete UID0004F9 OnEvent with hover/press/release/outside-dismissal and Look/Trade/Whisper/Group/Info dispatch through external RequestObjectInfo(m_targetId), destructor/cancel/close/setter/paint/background/border/geometry/packet-helper source order, direct consumer literals replacing the former command-string empty emitter, receiver-free stdcall row helpers owned/emitted by this file, complete literal-pool and VoteMenu boundary handling, singleton/vtable/compiler exclusions, and remaining constructor body work tracked separately.
```

- Historical read-only preflight identities before supervisor application were: `by-memory/-coverage-report.md` SHA256 `50898C21EC4D1BE43CC3B64B18BD38327F98A4267A7CB87507D22CDB5BCC4890`; `by-class/-coverage-report.md` SHA256 `4E9E3B9E547CACC02628EFC594377C2C54DC9F334C43F782C5D5FA8587DAAAE8`; `by-file/-coverage-report.md` SHA256 `4155A445A4DB826A717D9BFA16DE892388E8D5954297A121E645F08207CF95F4`; `by-global/-coverage-report.md` SHA256 `C8402BC1CF8E639E7A9F75BC94BD9A7F0F17010E1E4FB363775C643440A32D89`. Audit-time current post-application identities are `by-memory/-coverage-report.md` SHA256 `4590B3D98DBA30CB219E064E793186C941E766EE4B539856B3D6ADAD16DFC8FE`, 2082208 bytes/4722 lines; `by-class/-coverage-report.md` SHA256 `91E531941902D7EB9D4C3BCBB9CC58B7385F223C1E82B17C70FE7069FBA99354`, 270961 bytes/625 lines; `by-file/-coverage-report.md` SHA256 `7ED5B1C29EDB238363AE743F78AF63871102F8B5AC6E0D688D397A2A00E3D511`, 162827 bytes/317 lines; and unchanged `by-global/-coverage-report.md` SHA256 `C8402BC1CF8E639E7A9F75BC94BD9A7F0F17010E1E4FB363775C643440A32D89`, 100801 bytes/218 lines. The by-global report has no UID00030A or separate semantic request-time-global row and no callback-owned by-global document changed, so no by-global manual operation is applicable.
- Manual-coverage closure count: the supervisor applied all 30 originally staged semantic decisions comprising nine replacements, five insertions, and sixteen no-ops, then applied one corrective in-place UID0003TU replacement after command `19152` exposed the header-ownership defect. The correction is not a 31st semantic target decision; it is a second lifecycle operation on C38D. The current by-memory coverage row is literal-equal to the single-owner payload below, so no manual coverage operation remains pending.
- Historical pre-application no-change proof: the manual rows for UID00037Y (`87%`) and UID0001KO (`86%`) quoted above remained unchanged as parent anchors; UID0003ZS (`89%`), UID00039X (`90%`), UID0003V9 (`92%`), UID00042F (`90%`), and UID00042I (`94%`) were broad, score-aligned no-ops. UID0004PZ (`92%`) and UID0004US (`90%`) preserved their row text while new earlier-address children were inserted above them. UID00034O used the exact replacement above, and UID0004F9 used the exact insertion rather than a false no-change claim. All dispositions are now applied/current.
- Historical pre-application class/file proof: `by-class/-coverage-report.md` had broad rows for MapPane (`93%`), ScreenPane (`93%`), LivingObjectPane (`92%`), Event (`94%`), and UserPane (`94%`) that remained no-ops; `by-file/-coverage-report.md` had broad MapPane (`92%`) and UserPane (`93%`) no-op rows. UID0000C0 and UID0000N7 were not no-ops because their old rows retained false OnEvent body-work debt; their exact class/file replacements and UID0004F9's independent by-memory insertion are now applied.
- Both exact helper children now exist and validate at `92/94`; their supervisor-owned manual rows are applied. The exact rows below remain the authoritative child payloads and require no change from this declaration-ownership repair:

```text
        - [UID:0004YB][0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint](by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md) 0x0050c550-0x0050c5d2 | private MapPane item-object hit test | MapPane::FindItemObjectAtMapPoint : reconstructable : 92% : very-strong : Exact Y-first private MapPane method reverse-scanning ObjectList primary item storage, returning the topmost ObjectPane whose bounds contain the point, with three UID00037S callers, exact thiscall ABI/range, direct UID00007Q owner/emitter, complete CPP, and blank child H because the class owns the declaration.
        - [UID:0004YC][0x005a4f70-0x005a500f.RequestLocalPlayerStatus](by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md) 0x005a4f70-0x005a500f | externally linked local-player status request helper | RequestLocalPlayerStatus : reconstructable : 92% : very-strong : Exact UserPane.cpp helper sending opcode 0x2d subtype 0 as two bytes and storing request time in the g_useEpfAssets-selected EPF/legacy slot, with MapPane/IconsPane/raw-old-HUD/TabPane callers, inline UserPane equivalent, exact stdcall ABI/range, complete CPP/H, and semantic names replacing opcode-derived aliases.
```

- Historical placement plan was deterministic: add UID0004YB immediately under UID00037Y before UID0004PZ and UID0004YC immediately under UID0001KO before UID0004US. The supervisor applied both rows; UID0004PZ and UID0004US retained their manual row text, while their ordinary `Nested` metadata is `0` because each ceased to be the first child. B009 did not edit the coverage files.
- The B agent must not apply these rows because all `-coverage-report.md` files are supervisor-owned collision surfaces. Generated tracker/coverage files must be refreshed by normal supervisor validator flow, not edited manually.

### Historical Report-Only Follow-Up Actions

The following lines preserve the accepted pre-callback plan as implementation history. They are superseded by the current `Follow-Up Actions` section below.

- Supervisor: perform mechanical Gate 1 review of this exact report; reject any claim or formal-source discrepancy before callback.
- Supervisor after acceptance: send B009 a same-report implementation callback covering every target/support row above, both exact child creations from the complete dequoted payloads, UID0004PZ/UID0004US nesting reconciliation, all source/API migrations, metadata/formal insertions, history preservation, and serial scoped validators, excluding IDA and coverage.
- B009 during callback: create and validate the two child pages in the exact sequence in `Function / Child Inventory`; read both actual first-line UIDs; replace every pre-registration child identity; add the two actual `TARGET-REPORT-ADDITIONAL-UIDS`; reconcile Target/inventory/ledger/checklist/manual-row staging; and prove no child identity placeholder remains before returning for Gate 2. Do not fabricate a UID or leave the report with path-only additional targets.
- Supervisor Gate 2B closure: catalog `0355` began from restored session/database `1da2b2ae`, applied/read back each accepted IDA row separately, preserved prerequisite/protected/no-change rows, and saved/hashed the IDB only after every transaction passed. MapPane now has IDA-only `_gap3A9[3]`/`_gap3B5[3]`, exact semantic offsets `+0x3a0/+0x3a4/+0x3a8/+0x3ac/+0x3b0/+0x3b4`, upper `+0x3b8`, hovered id `+0x3ec`, 69 members, and size `0x910`. Event now has IDA-only `_gap5[3]`, byte type `+0x4`, payload `+0x8`, and size `0x110`. The documented packed offsets/sizes remain rejected unsaved history.
- Supervisor after B009 implementation verification: verify both additional UID declarations and the absence of unresolved temporary child identities, apply every exact manual replacement/insertion above using literal assigned UIDs, validate changed ordinary by-* files and coverage serially, and perform final lifecycle-time generated MapPane/header/tracker readback.
- Historical supervisor-only boundary at that report-only checkpoint: the report execution lifecycle would run only after claim-by-claim ordinary, IDA, coverage, and generated verification. B009 was never permitted to invoke `execute_report`.
- B009: no further research target until this report is accepted, repaired, or superseded. During callback, update this same report rather than creating a replacement.

### Historical Report-Only Confidence

- Recommendation confidence: very strong.
- Score confidence: strong for `93/94`; all semantic, source-placement, support-API, and formal dependency blockers are closed, with only stripped original lexemes and later implementation/compile verification limiting the score.
- Remaining uncertainty: original private lexical spellings and exact historical header grouping only. Runtime logic, values, offsets, types, ownership, range, compiler tail, method signature, required support APIs, and callback destinations are resolved.

### Historical Report-Only Validator Results

- Commands run: none.
- Results: not applicable during this explicit report-only assignment.
- Unresolved validator warnings/errors: none observed because validators were intentionally not run. Required implementation validators are listed in the checklist for the later callback.

### Historical Report-Only Changed Files

- Created: none during this exact-artifact Gate 1 self-audit; the report was created during the initial report-only pass.
- Modified: `tools/leaser/Agents/Agent-B009/research/00037S-MapPaneMouseEventCore-source-quality.md` only, additively/in place.
- Renamed/moved: none.
- Historical report-only checkpoint: report execution had not been run, and B009 had performed no `execute_report`, dry-run/probe, lifecycle/archive command, manual move, validator, generated edit, coverage edit, or IDA mutation at that checkpoint.

### Historical Accepted Gate 1 Implementation Tracking Checklist

This unchecked checklist is the accepted pre-callback plan retained as history. The final `Implementation Tracking Checklist` below records durable applied work and lifecycle-neutral authority boundaries rather than current pending/completed lifecycle truth.

Initial report-only pass:

- [ ] Supervisor validation required before implementation.
- [ ] Update UID00037S target and all support destinations with every accepted atomized ledger row; use the explicit deduplication map and do not reintroduce former duplicate C10/C29, C16/C30, C17/C25, C18/C32, C19/C33, C05/C21/C31, C27/C20A, or C28/C20B claims.
- [ ] Update target metadata `85/89 -> 93/94`; retain owner `00007Q`, emitter `00007Q`, reconstructable true.
- [ ] Insert the exact source-local `RequestLookAtMapPosition` prototype followed by the formal method body from this report into the target CPP block; keep target H blank because UID00007Q already declares the override.
- [ ] Update UID00007Q MapPane class fields at `+0x3a0..+0x3b7`, `+0x3ec`, and `+0x8e8..+0x90f`; use byte `m_pointerEventType` and implicit natural padding rather than named padding members; add the exact `MapActionState` enum and item-hit helper declaration; preserve all unrelated class content and `0x910` size.
- [ ] Create [UID:0004YB] from the complete dequoted `92/94`, owner/emitter `00007Q`, `Nested:4`, formal-CPP/blank-H payload with no UID line; validate it, then read and record its literal assigned UID rather than inferring one.
- [ ] Add the actual validated item-hit UID/path/role to UID00037Y's child inventory while preserving UID00037Y metadata, aggregate disposition, unrelated helper evidence, and formal state.
- [ ] After the item-hit child validates, change only UID0004PZ `Nested:4 -> 0`; preserve its `92/94`, owner/emitter, formal source, evidence, history, and manual-row text.
- [ ] Synchronize UID0003ZS timer field names claim by claim without copying target ownership or changing `89/91` without independent evidence.
- [ ] Replace UID0003TK's stale two-stage EPF tail with the two exact `g_useEpfAssets` cleanup branches; preserve `92/94` and rejected history.
- [ ] Replace UID0003TL's deferred-surface helper/field interpretation and formal tail with the exact waiting/status/tracking cleanup; preserve `90/90` and rejected history.
- [x] Historical accepted callback converted UID0003TU to external `RequestObjectInfo`, inserted its exact CPP definition, migrated all three callsites, updated `86/89 -> 90/92`, and preserved opcode-bearing aliases only as history. The callback's initial child-H declaration was superseded by command `19152`; current UID0003TU H is blank and UID00007Q owns the sole `MapPane.h` declaration.
- [ ] Update UID0004F9 at exact path `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md`: replace stale helper aliases, insert the complete formal CPP payload above, retain blank H, set emitter UID0000C0, change `88/90 -> 92/94`, preserve non-Info actions and inline Trade/Group packet bodies, and record exact range/vtable/jump-table history.
- [ ] Update UID0000C0 RightButtonMenuPane: preserve `SetTargetNameAndId(int,const wchar_t *)` and all unrelated class content, replace its single include with the exact two-include prefix so `RightButtonMenuPane.cpp` sees `RequestObjectInfo`, replace stale Info aliases, and keep `90/94`; synchronize only corresponding source-readiness/alias prose in UID0000N7 while keeping `90/93`.
- [ ] Convert UID0003TV to static `RequestLookAtMapPosition`, insert its exact sole CPP definition with blank H, retain the matching source-local prototype before UID00037S, migrate both target calls, update `86/89 -> 90/92`, and preserve opcode-bearing aliases only as history.
- [ ] Add the ScreenPane compile-visible `CursorIndex` values `7..11`; keep UID00039X `90/91`, cursor storage, loader order, and class layout unchanged.
- [ ] Create [UID:0004YC] from the complete dequoted `92/94`, owner/emitter `0000P1`, `Nested:4`, formal-CPP/H payload with no UID line; validate it, then read and record its literal assigned UID rather than inferring one.
- [ ] Add the actual validated status-request UID/path/role to UID0001KO's child/function inventory while preserving UID0001KO NONE/FALSE/non-emitting metadata, every say/non-say split fact, unrelated child, and blank formals.
- [ ] After the status-request child validates, change only UID0004US `Nested:4 -> 0`; preserve its `90/93`, owner/emitter, formal source, evidence, history, and manual-row text.
- [ ] After both child UIDs are read back, replace every pre-registration child identity with the matching actual UID, add `TARGET-REPORT-ADDITIONAL-UIDS` in item-hit/status-request path order, and reconcile Target/declared inventory, ledger, Function/Child Inventory, support changes, score metadata, manual-row staging, and this checklist before Gate 2.
- [ ] Run an unresolved-identity audit after reconciliation: no child identity placeholder tokens, exactly two actual additional UIDs, and one independent evidence/recommendation/ledger/validator/manual-row disposition for each additional target.
- [ ] Replace UID00030A's two source globals with `g_epfLocalPlayerStatusRequestTime` and `g_legacyLocalPlayerStatusRequestTime`; preserve zero initialization, UserPane ownership, `88/90`, and historical aliases.
- [ ] Apply the exact support formal replacements: UID0002T2 and UID00022Q call `RequestLocalPlayerStatus(0)`; UID00034O calls `RequestLocalPlayerStatus(event->m_payload.m_key.m_messageTime)` from `+0x10c` and never zero; preserve current scores and every unrelated action.
- [ ] Synchronize UID0003V9 and UserPane class/file support to the semantic request-time globals using the exact key-payload message-time expressions above while preserving the intentionally inline key-`s` packet path and current scores; preserve the inspected broad UserPane class/file manual rows at `94%`/`93%` unless later validation independently changes those scores.
- [ ] Update by-file MapPane source-contract prose for UID00037S, the new item-hit helper, and UID0003TU/TV without changing `92/92` or pruning unrelated families.
- [ ] Record inspected no-change proof for LivingObjectPane `m_terminalAnimation`/`SetHighlightState(bool)` and UID00042F `MapPane::ClearQueuedMapStateRefresh`; for RightButtonMenuPane preserve the already-correct setter but apply the separately listed UID0000C0/UID0004F9/UID0000N7 alias/include/formal changes rather than claiming the support family is no-change.
- [ ] Preserve the one-method range and do not split or emit `0x507c72-0x507c90` compiler support.
- [ ] Preserve historical/stale assumptions and rejected alternatives in labeled sections rather than deleting them.
- [ ] Supervisor Gate 2B function `0x507150`: re-read `sub_507150`, `char __thiscall(int this,int)`, size `0xb22`, `MapPane__HandlePointerOrMouseEvent -> fn:null/error:"Not found"`, absent FR/FP/ER/EP, and the complete 21-entry frame/local prestate above; apply the exact shifted-MapPane bool signature, name, FR, and FP; read back those exact values while preserving ER/EP absence, frame/locals, range, bytes, sole `0x61e76c` xref, and interior comments.
- [ ] Supervisor Gate 2B function `0x50c550`: re-read `sub_50C550`, `int __thiscall(_DWORD **this,int,int)`, size `0x82`, `MapPane__FindItemObjectAtMapPoint -> fn:null/error:"Not found"`, absent FR/FP/ER/EP, and the complete six-entry frame/local prestate above; apply the exact MapPane member name/type/FR/FP; read back those values while preserving ER/EP absence, frame/locals, range, bytes, and three target callers.
- [ ] Supervisor Gate 2B function `0x50f4d0`: re-read `sub_50F4D0`, `void __stdcall(unsigned int value)`, size `0x5a`, `retn 4`, `RequestObjectInfo -> fn:null/error:"Not found"`, absent FR/FP/ER/EP, and the complete eight-entry frame/local prestate above; apply exact name/type/FR/FP; read back those values while preserving ER/EP absence, frame/locals, range, bytes, cleanup, and all three callsites.
- [ ] Supervisor Gate 2B function `0x50f9c0`: re-read `sub_50F9C0`, `void __stdcall(unsigned __int16 value,unsigned __int16)`, size `0x5b`, `retn 8`, `RequestLookAtMapPosition -> fn:null/error:"Not found"`, absent FR/FP/ER/EP, and the complete nine-entry frame/local prestate above; apply exact name/type/FR/FP; read back those values while preserving ER/EP absence, frame/locals, range, bytes, cleanup, and both target callers.
- [ ] Supervisor Gate 2B function `0x5a4f70`: re-read `sub_5A4F70`, `int __stdcall(int)`, size `0x9f`, `retn 4`, `RequestLocalPlayerStatus -> fn:null/error:"Not found"`, absent FR/FP/ER/EP, and the complete seven-entry frame/local prestate above; apply exact void name/type/FR/FP; read back those values while preserving ER/EP absence, frame/locals, range, bytes, cleanup, caller family, and both storage xrefs.
- [ ] Supervisor Gate 2B materialization `0x69bf6c`: re-read named undefined one-byte head `unk_69BF6C` plus unnamed undefined one-byte heads `0x69bf6d/0x69bf6e/0x69bf6f`, all empty type and not data/code; confirm no global/entity, four zero bytes, absent comments, proposed-name collision miss, xrefs `0x5a4fba/0x5a686f`, and separate fences at `[0x69bf68,0x69bf6c)` and `0x69bf70`; replace only those four undefined items with one anonymous four-byte unsigned-int item `[0x69bf6c,0x69bf70)` and independently read back item/bytes/xrefs/fences before any semantic name/comment action.
- [ ] Supervisor Gate 2B semantic data action `0x69bf6c`: only after the preceding materialization readback succeeds, apply exact `unsigned int g_epfLocalPlayerStatusRequestTime` plus ER/EP; read back exact name/type/comments while preserving zeros, the two xrefs, the lower `unk_69BF68` fence, and the `0x69bf70` boundary/new-neighbor state.
- [ ] Supervisor Gate 2B materialization `0x69bf70`: re-read named undefined one-byte head `unk_69BF70` plus unnamed undefined one-byte heads `0x69bf71/0x69bf72/0x69bf73`, all empty type and not data/code; confirm no global/entity, four zero bytes, absent comments, proposed-name collision miss, xrefs `0x5a4fff/0x5a68a4`, and separate fences at `0x69bf6c` and named `g_lastFunctionKeyTick` at `0x69bf74`; replace only those four undefined items with one anonymous four-byte unsigned-int item `[0x69bf70,0x69bf74)` and independently read back item/bytes/xrefs/fences before any semantic name/comment action.
- [ ] Supervisor Gate 2B semantic data action `0x69bf70`: only after the preceding materialization readback succeeds, apply exact `unsigned int g_legacyLocalPlayerStatusRequestTime` plus ER/EP; read back exact name/type/comments while preserving zeros, the two xrefs, the new `0x69bf6c` item boundary, and `g_lastFunctionKeyTick` at `0x69bf74`.
- [ ] Supervisor Gate 2B function `0x505cc0`: re-read `sub_505CC0`, `void __thiscall(TimerHandler *this)`, size `0x39`, `MapPane__ClearQueuedMapStateRefresh -> fn:null/error:"Not found"`, absent FR/FP/ER/EP, and sole `__return_address +0x4 size 0x4 _UNKNOWN *` frame entry; apply exact MapPane member name/type/FR/FP; read back those values while preserving ER/EP absence, frame, range, bytes, and full caller/xref set.
- [ ] Supervisor Gate 2B MapPane UDT `+0x3a0..+0x3b7`: in fresh restored session `1da2b2ae`, re-read size `0x910`/62 members, exact lower boundary members `+0x398/+0x39c/+0x39d/+0x39e/+0x39f`, target `int m_pendingMovementState[6] +0x3a0`, and upper `float m_currentDayNightBrightness +0x3b8`; replace only that `0x18`-byte member with the literal eight-member IDA fragment using `_gap3A9[3]` and `_gap3B5[3]`; independently read back semantic offsets `+0x3a0/+0x3a4/+0x3a8/+0x3ac/+0x3b0/+0x3b4`, filler spans `+0x3a9..+0x3ab/+0x3b5..+0x3b7`, upper `+0x3b8`, size `0x910`, and member count `69`. If size is `0x90c` or any failed offset recurs, stop, do not save, and discard the session.
- [ ] Supervisor Gate 2B MapPane UDT `+0x3ec`: only after the preceding exact readback, re-read lower `float m_dayNightBrightnessBias +0x3e8`, target `unsigned int m_pendingMapStateToken +0x3ec`, and upper `unsigned __int8 m_waitingForLocalPlayerStatus +0x3f0`; rename only the same-width target to `m_hoveredObjectId`; read back `m_hoveredObjectId +0x3ec`, all three exact members, and size `0x910`. A `+0x3e8` hovered-id readback is a hard packed-layout failure and must not be saved.
- [ ] Supervisor Gate 2B Event UDT `+0x4`: in fresh restored session `1da2b2ae`, re-read size `0x110`, `vftable +0x0`, four-byte `EventType m_type +0x4`, and `EventPayload m_payload +0x8`; replace only `+0x4..+0x7` with literal IDA members `unsigned __int8 m_type +0x4` and `unsigned __int8 _gap5[3] +0x5`; read back payload `+0x8`, size `0x110`, and all unrelated members. Size `0x10e` or payload `+0x6` is a hard failure: stop, do not save, and discard the session.
- [ ] Supervisor Gate 2B: verify and record no-change readback for the opaque MapPane tail, `0x507c72` alignment, `jpt_5071E8`, successor `0x507c90`, vtable cell `0x61e76c`, and MapPane/EventType/LivingObjectPane/RightButtonMenuPane/ScreenPane prerequisites.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-class/MapPane.md --apply --queue-timeout 240`.
- [ ] After creating the exact child, run serially: `python .\tools\validator.py --mode file --file by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md --apply --queue-timeout 240`.
- [ ] After adding the assigned child reference, run serially: `python .\tools\validator.py --mode file --file by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md --apply --queue-timeout 240`.
- [ ] After changing its nesting metadata, run serially: `python .\tools\validator.py --mode file --file by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-class/RightButtonMenuPane.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-file/RightButtonMenuPane.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-class/ScreenPane.md --apply --queue-timeout 240`.
- [ ] After creating the exact child, run serially: `python .\tools\validator.py --mode file --file by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md --apply --queue-timeout 240`.
- [ ] After adding the assigned child reference, run serially: `python .\tools\validator.py --mode file --file by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md --apply --queue-timeout 240`.
- [ ] After changing its nesting metadata, run serially: `python .\tools\validator.py --mode file --file by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-class/UserPane.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-file/UserPane.md --apply --queue-timeout 240`.
- [ ] If changed, run serially: `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240`.
- [ ] Historical pre-preflight plan: preserve the exact quoted UID00037Y and UID0001KO parent manual rows; replace exact UID00037S, UID0003TK, UID0003TL, UID00030A, UID0002T2, and UID00022Q rows; insert UID0003TU/TV and validated UID0004F9 rows at their exact anchors; insert the exact literal-UID `92%` child rows beneath UID00037Y/UID0001KO; preserve UID0004PZ/UID0004US manual row text; validate `by-memory/-coverage-report.md`. The later read-only preflight supersedes this incomplete operation list with the 30-decision plan in the current exact manual-coverage section and final checklist, including replacements for UID00034O, UID0000C0, and UID0000N7.
- [ ] Supervisor verify refreshed generated MapPane.cpp contains one UID00037S `93/94` definition and no target empty marker; verify MapPane.h has one declaration plus dependency-complete support declarations; verify UserPane/caller outputs use only the accepted semantic API/global names.
- [ ] Historical supervisor plan: verify lifecycle-time tracker state and generated hashes after all ordinary/coverage validators; command18812 MapPane CPP/H hashes and command18822 tracker hash in `Documentation Evidence And IDA Status` were dated Gate 1 semantic checkpoints only.
- [ ] Confirm third-party import directive is not applicable.
- [ ] Confirm no Wave2/Wave3 artifact was used.

Implementation callback pass:

- [ ] Report accepted by supervisor for implementation.
- [ ] Both new child pages validated independently, their literal UIDs read back, and those exact UIDs added to `TARGET-REPORT-ADDITIONAL-UIDS` without guessing.
- [ ] Target/inventory/ledger/checklist/manual staging reconciled to the two actual child UIDs; absence of all child identity placeholders proven before Gate 2.
- [ ] Primary UID00037S and both actual additional UIDs independently verified against their own ledger rows, destination docs, formal CPP/H dispositions, metadata, scoped validator results, and manual-coverage staging.
- [ ] All accepted target/support details incorporated at report-level detail.
- [ ] Claim ledger updated from pending to exact destination/verification state.
- [ ] Metadata, CPP/H, class layout, helper, and semantic corrections applied or exact non-application reason recorded.
- [ ] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [ ] Every changed ordinary by-* file validated serially and command results recorded.
- [ ] Historical pre-Gate2B callback-return statement, retained only as chronology and not as current work: supervisor-owned IDA, coverage, generated verification, and execution were all pending at that earlier checkpoint and were not performed by B009. At that historical checkpoint, one coverage-row correction, fresh generated closure, and execution still remained pending after command `19152` failed on the duplicate declaration. Catalog `0355` IDA, all manual coverage including C38D, and commands `19201`/`19221` generated closure later superseded the first two items. Current gate/execution/archive truth is not asserted by this historical row and is authoritative only from the report path plus validator-owned history/status metadata.
- [ ] Historical readiness plan: after callback completion and a fresh exact-artifact Gate 1 audit, the artifact would have advanced to a later supervisor execution-readiness stage. The sole marker in this repaired body is a supervisor-review handoff required by the workflow, not a claim that Gate 1, Gate 2A, execution, or archive is currently pending or complete.

## Follow-Up Actions

- Current durable follow-up boundary: the exact C38D manual row is applied and literal-equal to the staged payload, and generated command `19201` proves exactly one `RequestObjectInfo(unsigned int objectId);` declaration, no UID0003TU header emission, one UID0003TU CPP definition, current primary/additional formal outputs, and no target/additional-target empty markers. Any supervisor Gate 1/Gate 2A review or report lifecycle action is governed by the artifact's current path and validator-owned history/status metadata; this body intentionally claims neither pending nor completed lifecycle state. Later physical refreshes are dated currentness snapshots, not reasons to reopen the closed source topology.
- Catalog `0355` Gate 2B remains complete and unchanged. Command `19154` validates the UID0003TU ordinary single-owner repair with generated refresh disabled. Command `19152` is retained only as the failed generated-closure diagnostic that exposed the duplicate declarations at generated `MapPane.h` lines 58 and 369; command `19201` is the successful closure checkpoint.
- The next four bullets are preserved as historical pre-command-`19152` follow-up state. Their broad 30-operation coverage and first generated-closure instructions are superseded by the current authoritative follow-up above.

- Historical plan: supervisor Gate 2A would verify each applied C01-C39-family ordinary claim against the changed documents, the exact formal CPP/H payloads, metadata, history, actual child UIDs, and serial validator results below.
- Supervisor Gate 2B is complete under catalog entry `0355`: restored session/database `1da2b2ae` applied and independently read back every accepted action, preserved every protected/no-change row, recorded the three bounded frame-display normalizations, and saved the IDB at the exact identity above. The earlier packed UDT attempt is failed historical evidence only and was discarded unsaved. B009 did not mutate IDA.
- Historical plan: supervisor manual coverage would apply all 30 exact decisions above. It would replace UID00037S/0003TK/0003TL/00030A/0002T2/00022Q/00034O in `by-memory/-coverage-report.md`, replace UID0000C0 in `by-class/-coverage-report.md`, and replace UID0000N7 in `by-file/-coverage-report.md`; insert UID0003TU/0003TV/0004F9/0004YB/0004YC at their exact anchors; preserve the sixteen proved no-op rows, including the quoted UID00037Y/0001KO anchors and UID0004PZ/0004US row text; and validate each changed coverage report serially.
- Historical plan: supervisor generated closure would run only after Gate 2A, Gate 2B, and manual coverage closure, then verify MapPane.cpp/MapPane.h/UserPane outputs and the research tracker at lifecycle time. Earlier generated command identities remain dated semantic checkpoints only.
- Durable supervisor-only lifecycle rule: B009 must not run or probe `execute_report`. Whether supervisor review or lifecycle movement is pending or complete is intentionally not stated here; the current path and validator-owned history/status metadata are authoritative.

## Confidence

- Current ordinary-document recommendation: `93/94` for UID00037S, `92/94` for each actual additional child UID0004YB and UID0004YC, and the exact support scores recorded above.
- Callback confidence: very strong. Both child identities were validator-assigned in the reported order; all accepted ordinary source, metadata, formal, history, support, and nesting changes are applied and serially validated.
- Confidence is independent of report lifecycle placement. Scoped commands `19039`-`19043` validated the five ordinary current-state prose updates, command `19154` validated the UID0003TU blank-H/single-owner correction, current manual coverage closes C38D, command `19201` closes generated topology, and Gate 2B IDA mutation/readback/save is complete. The body intentionally makes no current Gate 1, Gate 2A, execution, or archive claim; validator-owned path/history/status state is authoritative.

## Validator Results

- All scoped validators ran serially from `source-3/project-documentation` with `--apply --queue-timeout 240 --no-generated-refresh`; every command exited `0` with `ok: 1`.
- Post-catalog-`0355` ordinary current-state reconciliation validators also ran serially with the same flags; commands `19039`-`19043` each exited `0` with `ok: 1`. Each reported `generated_refresh: skipped` and validator-owned projected-stats bookkeeping for the scoped UID; no generated CPP/H or coverage refresh ran.
- Generated command `19152` was supervisor-owned and is retained as a failed-closure diagnostic checkpoint: `MapPane.cpp` SHA256 `32898DF491B747C600219C65981A58207B83F73876C53BC970EF9AEE12D8641B`, 159443 bytes/4776 lines; `MapPane.h` SHA256 `85A115EA688B04C699B55221F43706EC7F576464DD75E7CE1D19E7D0193D3510`, 13030 bytes/369 lines, with duplicate `RequestObjectInfo(unsigned int objectId);` declarations at lines 58 and 369; `UserPane.cpp` SHA256 `F58158A2E34762DDD1347986DD8D1AEBD83716E05C08F15FC9CF7E9AC24E6667`, 92655 bytes/2801 lines; `UserPane.h` SHA256 `E8DC44568B3CDDE6F60E7B5CD38F9500B3C862034F4EE2B7FDFBFEA71F29970D`, 482 bytes/8 lines. Deferred tracker command `19153` produced SHA256 `1FE96D5A171A10D8E2BBF53F8553B94DCCF2D7E529B078EDBAC9BACF4024CB6A`, 1675372 bytes/6629 lines. These physical identities predate the UID0003TU blank-H repair and are not final generated authority.
- B009 command `19154` (`2026-07-29T10:46:41-04:00`) validated only UID0003TU after blanking its H channel and documenting UID00007Q as the sole header declaration owner; exit `0`, `ok: 1`, prior H block hash `A249F3158EE395BBD4BEA2A904FD3B65B90A1EDC3E6919869B45862A3CF594C2 -> blank`, and `generated_refresh: skipped`.
- Supervisor generated command `19201` (`2026-07-29T10:58:40-04:00`) passed closure with exact identities recorded under `Documentation Evidence And IDA Status`: MapPane H has one global UID00007Q `RequestObjectInfo` declaration and no UID0003TU header emission; MapPane CPP has one UID0003TU definition; UID00037S/UID0004YB/UID0004YC formal outputs each occur once in their expected CPP/H channels; no target empty marker, unresolved placeholder, or stale temporary UID appears.
- Audit-time generated command `19221` (`2026-07-29T11:05:07-04:00`) advanced physical freshness but preserved every command-`19201` target count and formal topology. Its exact hashes/sizes/line counts are recorded under `Documentation Evidence And IDA Status`; lifecycle-time generated readback remains authoritative if physical headers advance again.
- Historical lifecycle-repair cycle: supervisor command `19226` executed the then-current report into the central archive; exact archived-artifact review found stale body prose claiming execution remained pending, and command `19227` immediately invalidated/de-executed the report back to active research for this narrow repair. These dated events explain the lifecycle-neutral wording and do not establish current lifecycle status; only the current path and validator-owned `VALIDATOR-REPORT-HISTORY`/status metadata do.

| Command | Relative file | Result |
|---|---|---|
| `18866` | `by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md` | created/registered UID0004YB; pass |
| `18867` | `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md` | created/registered UID0004YC; pass |
| `18868` | `by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md` | pass |
| `18869` | `by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md` | pass |
| `18870` | `by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md` | pass |
| `18871` | `by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md` | pass |
| `18872` | `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md` | pass |
| `18873` | `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md` | pass |
| `18874` | `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md` | pass |
| `18875` | `by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md` | pass |
| `18876` | `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md` | pass |
| `18877` | `by-class/ScreenPane.md` | pass |
| `18881` | `by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md` | pass |
| `18882` | `by-class/MapPane.md` | initial callback pass |
| `18883` | `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md` | pass |
| `18884` | `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` | pass |
| `18885` | `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` | pass |
| `18886` | `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` | pass |
| `18887` | `by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md` | pass |
| `18888` | `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md` | pass |
| `18889` | `by-class/RightButtonMenuPane.md` | pass |
| `18890` | `by-file/RightButtonMenuPane.md` | pass |
| `18891` | `by-file/MapPane.md` | pass |
| `18892` | `by-class/UserPane.md` | pass |
| `18893` | `by-file/UserPane.md` | pass |
| `18894` | `by-class/MapPane.md` | final stale-prose correction pass |
| `19039` (`2026-07-29T09:34:58-04:00`) | `by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md` | post-IDA current-state reconciliation; exit 0, `ok: 1`; generated refresh skipped |
| `19040` (`2026-07-29T09:35:06-04:00`) | `by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md` | post-IDA current-state reconciliation; exit 0, `ok: 1`; generated refresh skipped |
| `19041` (`2026-07-29T09:35:12-04:00`) | `by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md` | post-IDA current-state/frame-display reconciliation; exit 0, `ok: 1`; generated refresh skipped |
| `19042` (`2026-07-29T09:35:18-04:00`) | `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md` | post-IDA current-state/frame-display reconciliation; exit 0, `ok: 1`; generated refresh skipped |
| `19043` (`2026-07-29T09:35:24-04:00`) | `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md` | post-IDA data-item/name/comment reconciliation; exit 0, `ok: 1`; generated refresh skipped |
| `19154` (`2026-07-29T10:46:41-04:00`) | `by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md` | generated-closure single-owner repair; exit 0, `ok: 1`; UID0003TU H blank; generated refresh skipped |

- Validator diagnostics for MapPane/UserPane support and UID0003TL were limited to pre-existing `missing_ref_uid` warnings already present before this callback; no callback change failed validation.
- B009 ran no generated refresh, coverage validator, report lifecycle command, or `execute_report` command. The supervisor applied coverage and ran commands `19152` and `19201`; later command `19221` advanced generated physical freshness, and historical commands `19226`/`19227` performed the execute-then-invalidate repair cycle recorded above. B009 only repaired/validated UID0003TU with generated refresh disabled and performed read-only generated/currentness checks. The validator frontend reported its normal projected-stats bookkeeping side effect; B009 did not manually edit generated/project-level state. This action history is not a body-level assertion of current report lifecycle status.
- Final identity scan: no unresolved child identity placeholders, two actual additional UIDs, and no fabricated UID.

## Changed Files

- Created ordinary child pages: UID0004YB `by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md`; UID0004YC `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md`.
- Modified ordinary docs: UID0004PZ, UID0004US, UID0003TU, UID0003TV, UID00030A, UID0002T2, UID00022Q, UID00034O, UID0003V9, UID00037S, UID00037Y, UID0001KO, UID0003ZS, UID0003TK, UID0003TL, UID0004F9, `by-class/ScreenPane.md`, `by-class/MapPane.md`, `by-class/RightButtonMenuPane.md`, `by-file/RightButtonMenuPane.md`, `by-file/MapPane.md`, `by-class/UserPane.md`, and `by-file/UserPane.md`.
- Post-catalog-`0355` ordinary reconciliation modified only UID0004YB, UID0003TU, UID0003TV, UID0004YC, and UID00030A, replacing stale current-prestate prose with explicit historical prestate plus the exact saved catalog poststate; no unrelated content was removed.
- Generated-closure repair modified only UID0003TU after the earlier callback: its CPP definition/metadata/range remain unchanged, its H channel is blank, its covered-by/class-header reasoning identifies UID00007Q as the sole declaration owner, and command `19154` passed with generated refresh disabled.
- Modified report: this same UID00037S report, additively, to record actual child identities, applied ordinary states, exact validator commands, the fresh read-only correction from false four-byte data prestates to two independent undefined-byte materialization/semantic transactions at `0x0069bf6c/0x0069bf70`, the failed-closed packed-UDT history, the successful catalog-`0355` gap-guarded MapPane/Event retry, the six persisted function actions, the two persisted semantic globals, the three bounded prototype-driven frame-display normalizations, the applied 30-decision manual-coverage plan, command `19152` duplicate-declaration evidence, the UID0003TU single-owner correction, the applied C38D corrective row, command `19201` generated closure, and lifecycle-neutral body wording after the historical `19226`/`19227` repair cycle.
- Not changed by B009: IDA/IDB, any `-coverage-report.md`, any generated file, supervisor audit/catalog/lifecycle state, validator lifecycle state, goals/notes, or report location. The supervisor-owned catalog `0355`, manual coverage, and commands `19152`/`19201` generated output are recorded as external authority; command `19221` is a later read-only physical-currentness snapshot. Commands `19226`/`19227` are historical supervisor lifecycle actions, while current location/status truth is deferred to the actual path and validator-owned history/status metadata. Scoped validators performed only their reported projected-stats bookkeeping side effect; B009 did not manually edit project-level or generated state.

Current post-validator ordinary-file identities:

| File | SHA256 | Bytes |
|---|---|---:|
| `by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md` | `ECA23E08508E4128679DCD36A8BAFF37B30CCEB297A29FA3A3282E4DF838B11D` | 6731 |
| `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md` | `81D0AAAD685AA5B9B478D1F4C9A4B99DE99E74C522EF7F9EA51CF27C75C1122D` | 8518 |
| `by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md` | `C1A8DD54CA60113F620FA9DC3152B47E44E6B045220D0CD30DC07D44B7B382C3` | 9691 |
| `by-memory/0x005a50a0-0x005a5103.EnsureNormalBulletinSession.md` | `F58D248BBEA0F2A1A1BA1DA2A2FC5C85EC4370BFF97003F6AD431D5F0BB26D7D` | 8529 |
| `by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md` | `A55C12FC85E664E5E3C4DDD3EE325983DD09AC906FE539E61AEEF61BE09ECEFC` | 7401 |
| `by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md` | `CCB032AAA0D47E00357D534720735AB05073440AEA87188F4BE4791ED92770B6` | 6280 |
| `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md` | `3B839BD762ABB589EC0C0DA5150BF48CA703DFA39295967AEFB9EF0667C15258` | 15598 |
| `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md` | `657099CD838270E1977A2090504D9F9ABD32B0CB1F6380E5030D4FDDFDCCF6F4` | 23378 |
| `by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md` | `E18F0F5160FC02BD99166524454CC492770A3DD519252C2B18ACFA750D3A5D59` | 21731 |
| `by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md` | `39C34D2806BDE3879635173166982B0CA97DA2CF1C1BE620F278798CA5AE1D8C` | 12627 |
| `by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyOrTextEvent.md` | `7BD886274FDF933BFA72757E8416DA59D38BAFD674B71EB6C660C04EAB850E3F` | 37599 |
| `by-class/ScreenPane.md` | `D002161F61491F7BCD39CC83E0FCA170CFAE5DAE7028EA3282CC3155132B7297` | 62833 |
| `by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md` | `E765653024280926254A8C13382D87ACFB09F7CC2F18A1AFCE2B438F7BF049A9` | 21993 |
| `by-class/MapPane.md` | `9734E8CA063E68276E07FD2C72FDFD026C395E141A3F3CDE6B35BFAD9288CDB5` | 195430 |
| `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md` | `810ADDB046B1E38F8721AC515983978678F5234296AD5DED9EE92D909857D00E` | 38104 |
| `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md` | `32EDF45086FAAC83166E19E5EEC39EFAC8F32086BD995881AFF861AB9E3150B8` | 18672 |
| `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` | `9ABB073BB5087C7F9BBFEA6E58E284848CE4ED12280C9486A2EBE04C639AEBA8` | 29926 |
| `by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md` | `A886A0A638571C1397C1E254772EE04FFC8A424A481F2677B98905DD6EE09E43` | 27416 |
| `by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md` | `24FAF245A61EFDC9CA3715CC34BDAD94A140B2431A50B60CE1DA548D5A829E3B` | 22766 |
| `by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md` | `B2D06921A84F95AEEF322F2A1FE5417A14BF6621F7D31177B8E4C3DFBFDD4617` | 10873 |
| `by-class/RightButtonMenuPane.md` | `C7DBCA620E6A677701EC8AA69A998E8C7775178DD9DE3F3E03F7FFFD7C0C637E` | 27396 |
| `by-file/RightButtonMenuPane.md` | `13255CED84A8DA9E210578971EC2D12CAE12A66AD38963D486738938F25736E5` | 23626 |
| `by-file/MapPane.md` | `E2627BBF6FA44D37AA48816CEDBA172D17A5A6632FBA596BC69983E449832939` | 203180 |
| `by-class/UserPane.md` | `1ECD11678A39EABED11033D82F5B2A1BD12EF2E2A9682E2A1C2EC9022F74DEEA` | 100000 |
| `by-file/UserPane.md` | `4171E336C19C2D90171B272100CB824D519292A2F93789E44A999677F2C94F66` | 113756 |

## Implementation Tracking Checklist

- [x] Supervisor accepted exact Gate 1 artifact SHA256 `BBD037DC063727153D41FF193DD36B0563C99A5387545C67DFCA4FC8DC052AF3` for same-B implementation.
- [x] Created UID0004YB first, validated it with command `18866`, read the literal first-line UID, and incorporated it as the first UID00037Y child.
- [x] Created UID0004YC second, validated it with command `18867`, read the literal first-line UID, and incorporated it as the first non-say UID0001KO child.
- [x] Added `TARGET-REPORT-ADDITIONAL-UIDS:0004YB,0004YC` in child-registration order and reconciled Target, inventory, ledger, support plans, manual staging, and this checklist to the actual UIDs.
- [x] Proved there are no unresolved child identity placeholders and no fabricated UID.
- [x] Applied UID0004PZ and UID0004US `Nested:4 -> 0` while preserving their scores, ownership/emitter routes, formal source, evidence, history, and manual-row text.
- [x] Applied UID00037S `85/89 -> 93/94`, exact formal CPP, blank H disposition, source-local helper prototype, semantic fields/helpers, owner/emitter route, compiler-tail exclusions, and historical assumptions.
- [x] Applied MapPane and ScreenPane class declarations/layout/constants without changing MapPane size or inventing named padding; preserved the opaque IDA tail as an explicit no-mutation disposition.
- [x] Applied UID00037Y/UID0004YB inventory and UID0001KO/UID0004YC inventory without changing parent aggregate/non-emitting dispositions.
- [x] Applied UID0003ZS, UID0003TK, and UID0003TL field/cleanup/formal reconciliations while preserving their independent scores and historical assumptions.
- [x] Applied UID0003TU `RequestObjectInfo` as the sole CPP definition with blank child H covered by UID00007Q's one global `MapPane.h` declaration; applied UID0003TV `RequestLookAtMapPosition`, UID0004F9 `RightButtonMenuPane::OnEvent`, and RightButtonMenu class/file source/API closure with their exact formal dispositions and historical aliases.
- [x] Applied UID00030A semantic request-time globals and exact UID0002T2/UID00022Q/UID00034O/UID0003V9 caller behavior, including UID00034O's `event->m_payload.m_key.m_messageTime` argument from `+0x10c`.
- [x] Applied UserPane class/file declarations and source placement while preserving the intentionally inline key-`s` path and existing ownership/score context.
- [x] Applied by-file MapPane source-route closure and retained the inspected no-change evidence for LivingObjectPane, UID00042F, Event, and protected compiler structures.
- [x] Preserved relevant positive/negative evidence, rejected alternatives, exact manual coverage payloads, formal CPP/H reasoning, source placement, range boundaries, and implementation history.
- [x] Ran every changed ordinary by-* validator serially with `--no-generated-refresh`; commands `18866`-`18877` and `18881`-`18894` all exited `0` with `ok: 1`.
- [x] Mechanically recounted only the current claim-ledger data rows: exactly 85 rows, exactly 85 unique IDs, zero malformed eight-cell rows, and zero duplicate IDs; unrelated table headers and Validator Results rows were excluded. C38K is the sole UID00034O coverage-replacement claim, C38Y is the sole UID0000C0 coverage-replacement claim, and C38Z is the sole UID0000N7 coverage-replacement claim.
- [x] Recorded the failed-closed supervisor UDT attempt exactly: packed MapPane `0x90c` with detail/time/type/hover at `+0x3aa/+0x3ae/+0x3b2/+0x3e8`; packed Event `0x10e` with payload `+0x6`; no other mutation; unsaved session discarded; fresh session `1da2b2ae` restored original MapPane `0x910` and Event `0x110` prestates.
- [x] Documented a lifecycle-neutral Gate boundary: the body makes no current Gate 1 or Gate 2A disposition claim, and any such disposition is authoritative only from supervisor audit/lifecycle metadata matched to this exact artifact. The sole readiness marker is a supervisor-review handoff, not a lifecycle-state assertion.
- [x] Preserved all 85 applied ordinary claim rows, actual child identities, exact hashes, formals, metadata, history, and validator evidence without using their body text to assert whether current Gate 2A review is pending or complete.
- [x] Supervisor catalog `0355` Gate 2B function `0x507150`: persisted the exact MapPane event-method name/type/FR/FP with address comments absent and preserved range, bytes, sole xref, ABI, nonargument frame entries, and locals; prototype-driven frame presentation normalized only `+0xe8` from historical `arg_0` to `event : Event *`.
- [x] Supervisor catalog `0355` Gate 2B function `0x50c550`: persisted the exact item-hit member name/type/FR/FP with address comments absent and preserved frame, locals, range, bytes, ABI, and three target callers.
- [x] Supervisor catalog `0355` Gate 2B function `0x50f4d0`: persisted `RequestObjectInfo`, exact stdcall type, FR, and FP with address comments absent while preserving stack cleanup, frame, range, bytes, ABI, and all three callsites.
- [x] Supervisor catalog `0355` Gate 2B function `0x50f9c0`: persisted `RequestLookAtMapPosition`, exact stdcall type, FR, and FP with address comments absent while preserving cleanup, range, bytes, ABI, nonargument frame entries, and both callers; prototype-driven frame presentation normalized only `+0x20` from historical `arg_4` to `row : unsigned __int16`.
- [x] Supervisor catalog `0355` Gate 2B function `0x5a4f70`: persisted `RequestLocalPlayerStatus`, exact void stdcall type, FR, and FP with address comments absent while preserving cleanup, caller family, storage xrefs, range, bytes, ABI, and nonargument frame entries; prototype-driven frame presentation normalized only `+0x1c` from historical `arg_0` to `requestTime : unsigned int`.
- [x] Supervisor catalog `0355` Gate 2B function `0x505cc0`: persisted `MapPane::ClearQueuedMapStateRefresh`, exact member type, FR, and FP with address comments absent while preserving frame, bytes, range, ABI, and callers.
- [x] Supervisor catalog `0355` Gate 2B materialization `0x69bf6c`: replaced the historical `unk_69BF6C` plus three unnamed undefined one-byte heads with exactly one four-byte unsigned-int item over `[0x69bf6c,0x69bf70)` after independently preserving four zero bytes, exact two xrefs, lower fence, and neighbor boundary.
- [x] Supervisor catalog `0355` Gate 2B semantic data action `0x69bf6c`: persisted exact `unsigned int g_epfLocalPlayerStatusRequestTime` plus report-exact ER/EP while preserving zero bytes, exact xrefs, lower fence, and neighbor boundary.
- [x] Supervisor catalog `0355` Gate 2B materialization `0x69bf70`: replaced the historical `unk_69BF70` plus three unnamed undefined one-byte heads with exactly one four-byte unsigned-int item over `[0x69bf70,0x69bf74)` after independently preserving four zero bytes, exact two xrefs, the new lower neighbor, and `g_lastFunctionKeyTick` at `0x69bf74`.
- [x] Supervisor catalog `0355` Gate 2B semantic data action `0x69bf70`: persisted exact `unsigned int g_legacyLocalPlayerStatusRequestTime` plus report-exact ER/EP while preserving zero bytes, exact xrefs, both item boundaries, and the `0x69bf74` named fence.
- [x] Supervisor catalog `0355` Gate 2B MapPane UDT `+0x3a0..+0x3b7`: applied the literal eight-member IDA fragment with `_gap3A9[3]` and `_gap3B5[3]`; readback preserved semantic fields at `+0x3a0/+0x3a4/+0x3a8/+0x3ac/+0x3b0/+0x3b4`, both exact gap spans, upper field `+0x3b8`, size `0x910`, and 69 members.
- [x] Supervisor catalog `0355` Gate 2B MapPane UDT `+0x3ec`: persisted same-width `m_hoveredObjectId` at exactly `+0x3ec`, preserved `+0x3e8/+0x3f0` neighbors, and retained size `0x910`; the failed packed `+0x3e8` result remains historical unsaved evidence.
- [x] Supervisor catalog `0355` Gate 2B Event UDT `+0x4`: persisted `unsigned __int8 m_type +0x4`, IDA-only `_gap5[3] +0x5`, payload `+0x8`, and size `0x110`; the failed packed payload `+0x6`/size `0x10e` remains historical unsaved evidence.
- [x] Supervisor catalog `0355` recorded exact no-change readback for the opaque MapPane tail, alignment, jump table, successor, vtable cell, and protected prerequisite types/entities, then saved IDB SHA256 `C302B5A83E41917EA7517D3783E428804F05DEED797CFC842D6DAEAB27EED0F9`, 143190470 bytes, last write `2026-07-29T09:22:18.9918289-04:00`.
- [x] Reconciled stale current-IDA prose in UID0004YB, UID0003TU, UID0003TV, UID0004YC, and UID00030A without removing historical prestates; serial commands `19039`-`19043` all exited `0` with `ok: 1` and generated refresh skipped.
- [x] Acquired ordinary-document leases only immediately before the five reconciliation edits; explicit release attempts found those leases already absent, and the shared lease report confirmed no active B009 lease remained.
- [x] Supervisor applied the original 30 manual-coverage decisions: nine replacements, five insertions, and sixteen no-ops, including exact UID00034O/UID0000C0/UID0000N7 wording and literal UID0003TU/UID0003TV/UID0004F9/UID0004YB/UID0004YC rows.
- [x] Supervisor generated command `19152` exposed duplicate `RequestObjectInfo(unsigned int objectId);` declarations at generated `MapPane.h` lines 58 and 369; it is recorded as a failed-closure diagnostic, not a successful final generated state.
- [x] B009 leased only UID0003TU for the immediate repair, blanked the child H while preserving its sole CPP definition and UID00007Q declaration route, ran scoped command `19154` with exit `0`/`ok: 1`/generated refresh skipped, and released the lease successfully.
- [x] Supervisor applied the existing UID0003TU manual-row correction at its UID0003TJ/UID0003TV anchor; current text says complete formal CPP, blank child H, and sole UID00007Q global declaration and is literal-equal to C38D.
- [x] Supervisor generated command `19201` proved one MapPane-header declaration from UID00007Q, zero UID0003TU header emission, one UID0003TU CPP definition, one current formal output for UID00037S/UID0004YB/UID0004YC, no target empty marker, and current tracker topology; audit-time command `19221` preserved the same semantics while advancing physical freshness.
- [x] Documented the supervisor-only lifecycle boundary: B009 must not run or probe `execute_report`; ordinary work, catalog-`0355` Gate 2B, manual coverage, and generated topology are complete; current execution/archive truth is intentionally deferred to the report path plus validator-owned `VALIDATOR-REPORT-HISTORY`/status metadata. Historical commands `19226`/`19227` explain this repair without defining current state.
- [x] Third-party import directive is not applicable; no Wave2/Wave3 evidence was used.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"additional_uids":["0004YB","0004YC"],"agent":"B009","command_id":"000000019226","destination_path":"executed-b-agent-research/B009/00037S-MapPaneMouseEventCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00037S-MapPaneMouseEventCore-source-quality.md","timestamp":"2026-07-29T11:21:07-04:00","uid":"00037S"} -->
<!-- {"additional_uids":["0004YB","0004YC"],"agent":"B009","command_id":"000000019227","destination_path":"tools/leaser/Agents/Agent-B009/research/00037S-MapPaneMouseEventCore-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B009/00037S-MapPaneMouseEventCore-source-quality.md","timestamp":"2026-07-29T11:21:54-04:00","uid":"00037S"} -->
<!-- {"additional_uids":["0004YB","0004YC"],"agent":"B009","command_id":"000000019228","destination_path":"executed-b-agent-research/B009/00037S-MapPaneMouseEventCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00037S-MapPaneMouseEventCore-source-quality.md","timestamp":"2026-07-29T11:35:05-04:00","uid":"00037S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
