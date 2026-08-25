** TARGET-REPORT-UID:0003TT **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003TT MapPaneHandleObjectStatusPacket Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented recommendation: UID0003TT remains the ordinary private `MapPane::HandleObjectStatusPacket(const unsigned char *packet)` emitter in `NexusTK/map/MapPane.cpp`; Destination 1 is applied and the target is now `92/94`.
- Final disposition: the target is a source-authored opcode-`0x1d` packet method, not a non-emitting range, compiler helper, raw duplicate, aggregate parser, ObjectStatusBlob owner, LivingObjectPane owner, or ItemObjectPane owner.
- Implemented support action: Destination 2 is applied to UID0003HS `ItemObjectPane::UpdateItemStatus(const ObjectStatusBlob *status)` at `92/94`; UID0001AW, UID00037T, UID0001D7, UID0003TW, MapServerPacketOpcode, MapPane class/file, and ItemObjectPane class/file contain the accepted bounded no-loss synchronization with all unrelated metadata and detail preserved.
- Supervisor-owned manual handoff supplied by B005: the exact ten-row no-loss text for UID0003TT, UID0003HS, and eight support rows is retained below as immutable callback evidence. B005 did not edit manual coverage, and this report does not assert the later/current application state of those rows.
- Confidence: very strong for behavior, range, owner/emitter, packet layout, parser selection, object-type branches, field and helper identities, complete source shape, validator success, and generated output; remaining uncertainty is lexical only and caps confidence below `95`.
- Durable lifecycle provenance: B005 completed the accepted implementation callback with no blocked claim, scoped-validated eleven ordinary pages, captured evidence-time final waited generation proof under command `000000013720`, released every B005 lease, and supplied the exact supervisor-owned manual handoff without editing manual coverage. B005 did not run report execution, lifecycle, move, or archive commands and did not manually modify IDA database, tracker, audit, or supervisor files. Current execution, revalidation, invalidation, archive location, and supervisor coverage-application state are authoritative only in validator-owned headers/footers, registry, audit, and current files on disk.

Immutable callback-return marker, retained as historical agent handoff evidence and not as current lifecycle authority:

READY_FOR_SUPERVISOR_GATE2_REVIEW

## Supporting Research

- Exact prior-report search terms: `0003TT`, `0x00513310`, `MapPaneHandleObjectStatusPacket`, `ObjectStatusPacket`, `sub_513310`, `HandleObjectStatusPacket`, `MapPane`, `ObjectStatusBlob`, `ItemObjectPane`, `LivingObjectPane`, `MapPanePacketHandlers`, and `MapServerPacketOpcode`.
- Search roots actually checked:
  - `executed-b-agent-research`
  - every existing `tools/leaser/Agents/Agent-B*/research` directory
  - `tools/leaser/Agents/Older-Research`
  - `tools/leaser/Agents/SpecialReports`
  - `archived`
- Active B-agent research result: no current active report matched the target UID/address/name terms.
- Legacy/special/archive result: no matching report existed under `tools/leaser/Agents/Older-Research`, `tools/leaser/Agents/SpecialReports`, or `archived`.
- Matching executed reports opened and classified:

| Matching report | Direct/incidental finding | Current use |
| --- | --- | --- |
| `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-audit.md` | Direct split/boundary evidence; target report UID is `0001AW`, not `0003TT`. It identified the dispatcher-called `[0x00513310,0x0051367b)` child but did not reconstruct its complete source. | Historical split provenance; superseded for target source-quality conclusions. |
| `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch6.md` | Direct future-child lead: `sub_513310`, size `0x36b`, opcode `0x1d`, dispatcher call `0x005083b1`; explicitly deferred from that batch. | Historical boundary/caller support only. |
| `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch7.md` | Direct future-child lead with the same dispatcher route; explicitly left for a later split batch. | Historical boundary/caller support only. |
| `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch8.md` | Direct split creation for UID0003TT and the current filename range. It left the target body blank with provisional names. | Direct split provenance; current source-quality blockers are superseded by this report. |
| `executed-b-agent-research/B001/0001AW-mappane-packet-source-split-continuation-batch9.md` | Incidental helper/caller evidence for UID0003TW and UID0003TT. | Verify-only two-caller support. |
| `executed-b-agent-research/B001/0001DE-LivingObjectPaneCore-source-quality.md` | Incidental but useful branch proof: UID0003HS is called only from the type-zero item branch, not the type-three living branch. | Supports ItemObjectPane ownership for Destination 2. |
| `executed-b-agent-research/B001/0003TF-MapPaneCreateEffectObjectPane-source-quality.md` | Incidental current MapPane class declaration containing `HandleObjectStatusPacket`. | Verify-only declaration/source-order support. |
| `executed-b-agent-research/B002/00037W-MapPanePaintLightingCore-source-quality.md` | Incidental complete MapPane declaration and shared source union. | Verify-only class/file baseline. |
| `executed-b-agent-research/B002/0003TS-MapPaneHandleAnimationSoundPacket-source-quality.md` | Direct predecessor/alignment/source-order evidence; proves eleven `0xcc` bytes before UID0003TT. | Current predecessor and source-order support. |
| `executed-b-agent-research/B002/0003TX-MapPaneHandleObjectInfoPacket-source-quality.md` | Strong sibling evidence for full/partial ObjectStatusBlob parsing, bounded ACP names, ObjectInfo fields, and UID0003TW's two callers, one of which is UID0003TT. | Current sibling/helper/type support; not a substitute target report. |
| `executed-b-agent-research/B003/0003TJ-MapPaneRefreshStaticObjectTileRegion-source-quality.md` | Incidental generated MapPane union and historical UID0003TT Empty Emitter Marker evidence. | Generated/source-order comparison only. |
| `executed-b-agent-research/B004/0001AY-SelfSaveOKPaneFactory-source-quality.md` | Positive-control dispatcher call hit at `0x005083b1`. | Caller-route corroboration only. |
| `executed-b-agent-research/B004/0003TH-MapPaneCreateHitBarObjectPaneEventOverlay-source-quality.md` | Incidental complete MapPane declaration and ObjectStatusBlob status-kind use. | Verify-only type and class support. |
| `executed-b-agent-research/B004/0003TQ-MapPaneHandleActionPacket-source-quality.md` | Incidental current MapPane generated/source union and historical UID0003TT marker. | Generated baseline history only. |
| `executed-b-agent-research/B005/000179-ObjectStatusBlobParsers-source-quality.md` | Strong support for the exact 68-byte class, parser children, field aliases, return sizes, resources, and consumers; target report UID is `000179`. | Authoritative parser/layout support; not a direct UID0003TT report. |
| `executed-b-agent-research/B005/0003TE-MapPaneCoordinateEffectDescriptorDispatch-source-quality.md` | Incidental complete MapPane class declaration. | Verify-only class/source union. |
| `executed-b-agent-research/B009/0002CD-ObjectListFindByObjectId-source-quality.md` | Direct callee support: `ObjectList::FindByObjectId(int)` lists `sub_513310` among callers. | Authoritative lookup contract support. |

- Evidence-based prior-report conclusion: no prior dedicated UID0003TT target-specific source-quality report exists. The executed matches are split reports or support reports with different `TARGET-REPORT-UID` values. This report is the first direct complete UID0003TT source-quality artifact.
- No Wave2/Wave3 artifact was accepted as authority. Historical generated or Wave-era names were used only as search leads and were checked against current by-* documentation plus live IDA MCP.

## Target

- Target UID: `0003TT`.
- Target path: `by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md`.
- Historical queue basis: the pre-callback `auto-generated/-ag-research-tracker.md` row listed the target under `Not-Covered Files - Reconstructable` at `86/90` with an Empty Emitter Marker. Tracker/lifecycle state remains supervisor-owned and was not edited by B005.
- Callback-return classification at B005 handoff time: Gate-1-accepted implementation callback complete and ready for independent Gate 2 review. This evidence-time classification does not override later validator-owned lifecycle history.
- Current scores and parent state: target `92/94`, canonical owner/emitter UID00007Q MapPane, reconstructable true, blank emitter position, `Nested:0`; direct file route UID0000L3 MapPane remains `92/92`, and class UID00007Q remains `93/94`.

## Current Target State

- Current metadata remains exact: UID, path, title, range, owner/emitter UID00007Q, reconstructable true, blank position, and `Nested:0`; only the accepted target score changed to `92/94`.
- Current target C++ is the complete Destination 1 body. At B005 callback evidence time, generated `MapPane.cpp` command `000000013720` contained exactly one UID0003TT definition and no UID0003TT Empty Emitter Marker.
- Current target prose records the exact opcode route, packet layout, parser cursor, counted ACP name, list/null/miss behavior, object types, living/item branches, unsafe ObjectInfo order, two status snapshots, effects/sounds/send/timer/local-copy/update order, padding, source placement, negative evidence, and compiler exclusions.
- `0x0053bad0` is correctly documented as the pre-update `LivingObjectPane::RemoveSpecialEffect` call, distinct from UID0003TW's post-update `0x0053bab0` `RequestNameplateEffect` body.
- UID0003HS is now `92/94` with complete Destination 2, exact Item Summary, one-caller/type-zero/high-item gate, active MapPane refresh, source route, historical correction, and no-extra-guard behavior. At B005 callback evidence time, generated `ItemObjectPane.cpp` contained one definition and no UID0003HS marker.
- B005 post-callback ordinary destination baselines:

| Path | Callback SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md` | `3197AC75D0A8B89673FA6C4E93705FC80D309160A35C7FB635D1A513E53B9870` | 16,638 | 251 |
| `by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md` | `7166198D63C8C7212B19EC9EF41056CFC31B99BDF674C09E32997BD69CB4882F` | 7,873 | 82 |
| `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md` | `751FA2F965564A8BC2464F80297854EF740E21E925E8DCA09E1F450E1F9F622F` | 20,220 | 138 |
| `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` | `3C8BE666C9193995413503E931E36FCFE5B657E61BCB8817E2401C1165C72804` | 100,425 | 404 |
| `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md` | `04C2B85BE8B5BA40A2B76FB399A3AA9795F3FEFB4E65D06247375A800E124ED2` | 22,797 | 189 |
| `by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md` | `3E438234B3BE63B45E5DBC1B56A529F631056B2440261169903B150F908D5AFE` | 7,873 | 104 |
| `by-type/by-enum/MapServerPacketOpcode.md` | `C77CC92D330AD41F66DB5F32384155549D7EE099E9E064331AB106EDD234A4B4` | 42,840 | 310 |
| `by-class/MapPane.md` | `A27987F5C31E7C8EE79AB0D397B66EE9C2FAB2BD59F766E0D841D19F8284CCF0` | 181,325 | 996 |
| `by-file/MapPane.md` | `97A40EB495BEC5ABA1B0402EDD6C15A5CA369721C5725D47EB1092C50ED48F9B` | 183,783 | 760 |
| `by-class/ItemObjectPane.md` | `16D9889298ECD983726F2EBB434A561BCD977A57B4A6AEC658ECC3DA3210CB5D` | 23,672 | 181 |
| `by-file/ItemObjectPane.md` | `BCCD9E18A738B7CEA7F041BF4DA24B9C0DB1456DCEE59BFD3861E1575976EEC5` | 32,088 | 203 |

- Durable technical state: this report and the eleven authorized ordinary destinations record the complete B005 callback change set. Validator-owned generated/projected/registry side effects were produced only by authorized validators; B005 made no manual restricted-file edits. Later supervisor lifecycle state is not asserted by this report prose.

## Executive Recommendation

- Applied and verified: the exact target range and owner/emitter remain; Destination 1 is the ordinary private MapPane method in source order after `HandleAnimationSoundPacket` and before the later raw no-route body.
- Treat packet byte `+5` as a status-format selector: `0` selects the 43-byte full parser and `1` selects the five-byte partial parser; any other value returns true immediately.
- Treat the byte immediately after the parsed status as `objectInfoType`, followed by one-byte `nameLength` and exactly `nameLength` ACP bytes converted to a 33-wide local buffer with a 32-character conversion cap.
- Use the existing source-facing classes and fields: ObjectPane type enum/accessor, LivingObjectPane status/name/ObjectInfo/facing fields, UserPane settings/current appearance fields, ObjectStatusBlob aliases, ObjectInfoObjectPane methods, SoundManager, Socket, TimerHandler, and MapPane/ObjectList helpers.
- Applied and verified: UID0003HS Destination 2 uses its existing declaration, exact two field writes, one caller, active MapPane refresh, range, and owner route.
- Keep broad dispatcher, packet-handler parent, working packet enum, parser aggregate, class/file declarations, helper dependencies, globals, and ignored padding separate. No split, merge, child creation, owner move, enum emission, raw duplicate promotion, or source-file creation is needed.

## Supervisor Active Recheck

- The accepted supervisor callback required C01-C42, Destinations 1-2, eleven bounded ordinary destinations, one-file leases, scoped validators, final waited generation, exact manual handoff retention, and no report lifecycle/manual coverage edits; those B005 responsibilities are complete.
- Split repair is not required: the existing target `[0x00513310,0x0051367b)` is already the complete modeled function range, including the ordinary `retn 4` path and branch-only tail code through `0x0051367a`.
- Every source-bearing item triggered by this target is either complete or explicitly dispositioned:
  - UID0003TT received complete Destination 1.
  - UID0003HS received complete Destination 2.
  - UID0003TW and the bounded support pages were synchronized; UID0003Z6, ObjectStatusBlob parser children, and the remaining dependencies were verified same-or-greater detail.
  - UID00037T and MapServerPacketOpcode remain blank formals for their own broader unresolved case inventory; this target closes only their opcode-`0x1d` row and does not fabricate a full switch or enum.

## Inference Research Guidance Check

- IDA MCP facts are separated from documentation evidence and source-shape inference throughout this report.
- Existing documentation assumptions were treated as provisional where they said status subtype, packet blob, helper, and field names remained open. Those statements were rechecked rather than copied.
- Binary facts used directly: range, bytes, hash, instruction and CFG counts, xrefs, callee addresses, packet offsets, branch predicates, constants, field offsets, call order, return behavior, and padding.
- Documentation facts used after cross-check: complete ObjectStatusBlob/ObjectPane/LivingObjectPane/UserPane/ItemObjectPane/ObjectInfoObjectPane declarations, current helper names, global types, source routes, and sibling generated style.
- Inferences are intentionally descriptive where original symbols are stripped: `objectInfoType`, `nameLength`, `objectName`, `effectStatus`, `previousStatus`, and the method title. They correspond directly to producer/consumer behavior and do not introduce raw offsets or decompiler labels.
- Wave2/Wave3 material was ignored as authority. No current recommendation depends on a Wave-era owner, generated alias, or simulated source body.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Resolution |
| --- | --- | --- |
| Function boundary | MCP `lookup_funcs`, `analyze_function`, full bytes, tail bytes, successor bytes, current ignored page | Exact `[0x00513310,0x0051367b)` is correct. The `retn 4` at `0x0051364b` is followed by branch-only in-function code through the final range-check call at `0x00513676`; five `0xcc` bytes begin at the exclusive end. |
| Opcode route | Dispatcher lookup/decompile/docs and xref `0x005083b1` | Inbound MapPane opcode `0x1d` directly calls this method. Original enum spelling is not recovered, so the working enum stays blank while the method body is source-ready. |
| Packet status selector | Target decompile/disassembly plus parser children | Byte `+5` is a two-value format selector: `0` full, `1` partial, otherwise immediate true. It is not ObjectStatusBlob's tagged parser byte because the method directly selects ParseFullStatus/ParsePartialStatus. |
| Parsed status length | UID0004LL and UID0004LM exact returns plus target cursor arithmetic | Full consumes `43`; partial consumes `5`. These values determine the following object-info and name fields. |
| Post-status packet layout | Target direct byte loads and MultiByteToWideChar call | At `packet[6+statusBytes]`: object-info type byte. At `packet[7+statusBytes]`: ACP name length. At `packet+8+statusBytes`: exactly that many bytes. No NUL is consumed from the packet. |
| Name buffer shape | Conversion cap `32`, explicit terminator write, LivingObjectPane field size `33`, `wcscpy_s(...,33,...)` | Human source uses `wchar_t objectName[33]`. The compiler range-check helper is lowering for the indexed terminator write, not a handwritten source call. |
| Object lookup route | `m_objectList` offset, ObjectList declaration, UID0002CD, target branches | Parse/name conversion occurs before the list null test. Non-null list performs `FindByObjectId`. A miss sends an outbound object refresh; a null list does not send. |
| Object type names | Complete ObjectPaneType enum and target byte tests | Type `3` is `kObjectPaneTypeLiving`; type `0` is `kObjectPaneTypeItem`. All other object types are no-ops in this handler. |
| Living composition rewrite | Target direct fields, UserPane `m_playerSettingsState[0]`, local-player pointer, ObjectStatusBlob layout | Incoming Human status with composition mode `2` becomes `5` when local setting index `0` is nonzero or the updated object is the local player. The method assumes the local-player pointer exists on this path. |
| Name and ObjectInfo lifecycle | Living/ObjectInfo declarations and exact call order | Copy name to `m_nameBuffer`, store `m_objectInfoType`, call `SetPrimaryName` before checking the pointer, then null-guard only `SetSpriteAttribute(0)`. Do not "fix" the unsafe ordering. |
| Special-effect helper identity | Target call `0x0053bad0`, UID0003Z6 exact split, UID0003TW comparison | The pre-update status predicate calls `RemoveSpecialEffect`, which deletes first secondary effect ID `134`. It does not call `RequestNameplateEffect`; the post-update UID0003TW helper separately requests descriptor `135`. |
| Two status snapshots | Two distinct target calls to GetSpriteConfig | Preserve separate `effectStatus` and `previousStatus` locals. Do not collapse them even though both are pre-update copies. |
| Sound transitions | Exact compare branches and constants | Only incoming Human status triggers comparisons. Body change chooses sample `411` if the new body ID is `0` or `1`, else `410`. Weapon change chooses `411` if the old weapon is `0xffff`, else `410`. Shield/arrow change chooses `411` if the old ID is at least `0xff`, else `410`. All use volume `100`. |
| Two-byte outbound packet | Stack word `1043` little-endian, local zero byte, sender length `2` | On weapon change while `g_pUserPane->m_nameVisible`, send exactly bytes `{0x13,0x04}`. The local third zero byte is not transmitted. No sender null check or result handling is added. |
| Timer source shape | Direct target call to TimerMgr, accepted TimerHandler wrapper body, existing LivingObjectPane source pattern | Human source should call inherited `CancelPendingTimersExceptEvent(kLivingTimerRefresh)`. The tiny wrapper may inline to the observed direct manager call with the adjusted TimerHandler owner. This avoids raw TimerMgr layout and matches accepted project source style. |
| Local-player appearance copy | Direct 68-byte copy, UserPane tail declaration, MapPane friendship | If the updated pane is the local player and incoming kind is Human, copy the complete incoming status to `UserPane::m_currentAppearance` before applying it. |
| Final living update order | Direct calls and fields | Call `SetSpriteConfig(&status, m_facing)`, then file-static `RefreshObjectStatusOverlay(livingObjectPane)`. Ignore SetSpriteConfig's return. |
| Item branch | Type-zero test, incoming appearance threshold, UID0003HS decompile, complete class fields | Only item type with `m_appearanceId >= 0xc000` calls `UpdateItemStatus`. That helper copies appearance and palette aliases to `m_itemId`/`m_paletteFlags`, then calls active MapPane screen-bounds refresh. |
| Return and validation behavior | All exits and absent checks | Every path returns true. Do not add packet pointer/length, conversion, list content, object type, global, local-player, ObjectInfo, sender, sound, or timer checks absent from the binary. |
| Source placement | Dispatcher/class/file order, owner fields, callee ownership | Target remains a MapPane member in MapPane.cpp; UID0003HS remains an ItemObjectPane member in ItemObjectPane.cpp. Parser, object, timer, sound, socket, and overlay classes remain dependencies. |

Rejected alternatives:

- `MapPaneStatusPacketHandler`, `ProcessObjectStatePacket`, and generic `object record` remain historical/search aliases; `HandleObjectStatusPacket` best matches current sibling declarations and opcode behavior.
- A tagged ObjectStatusBlob parser is rejected because byte `+5` is consumed by explicit target control flow and the target calls full/partial members directly.
- A packet struct with an inline fixed 43-byte status union is rejected because the two parser lengths are runtime-selected and the following name fields move by that returned length.
- A 32-wide name array is rejected because the source writes a terminator at index `32`; the destination field and `wcscpy_s` capacity are `33`.
- Null-safe ObjectInfo code is rejected because `SetPrimaryName` occurs before the pointer test.
- `RequestNameplateEffect` at the `0x005134c0` call is rejected; exact address and helper split prove `RemoveSpecialEffect`.
- A direct handwritten `g_pTimerMgr->CancelPendingTimersExceptEvent(...)` call is less source-plausible than the accepted inherited TimerHandler wrapper and would expose an unnecessary manager dependency; the wrapper is the chosen source shape.
- Updating all ObjectPane types or all item IDs is rejected; only living type `3` and item type `0` with appearance at least `0xc000` are active.
- An explicit `__report_rangecheckfailure`, security-cookie handling, stack-object copies, register temporaries, raw object offsets, or raw vtable call is compiler/decompiler scaffolding and is excluded.

## Evidence Standards Used

- Highest tier: live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `xrefs_to`, and `callees`.
- Byte-level tier: exact full-target and helper byte reads, SHA256 calculations, prologue/tail/successor checks, and current ignored alignment records.
- Structural tier: complete current class formals, field offsets, inline accessors, friend routes, method declarations, parser bodies, globals, and generated output.
- Cross-report tier: only executed reports matching the target UID/address/name/source family were opened; each was classified as direct split evidence or incidental support.
- Negative tier: unsupported owner moves, split changes, raw duplicate ownership, tagged-parser interpretation, invented protocol enum spelling, added guards, effect-helper conflation, handwritten compiler lowering, and duplicate source bodies were explicitly checked and rejected.
- Confidence remains below `95` because exact original local spellings, exact original opcode enumerator spelling, and semantic names for samples `410/411` are not symbol-proven. Those lexical gaps do not block behavior-complete source.

## Evidence Checked

- Evidence-time MCP session: active IDB session `64c11373`, database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `21508`, active/adopted worker, `is_analyzing:false`.
- Evidence-time health: status `ok`; module `NexusTK.exe`; imagebase `0x400000`; auto-analysis ready; Hex-Rays ready; strings cache ready with `2067` entries.
- Fresh successful bounded MCP calls in this continuation:
  - `idb_list`
  - `server_health(database='64c11373')`
  - `lookup_funcs` for `0x00513310`, `0x00537bc0`, and dispatcher interior `0x005083b1`
  - `get_bytes` for target start, target tail, target successor, full 875-byte target, and full 41-byte UID0003HS
  - `analyze_function(0x00513310)`
  - `decompile(0x00513310)` and `decompile(0x00537bc0)`
  - `disasm(0x00513310, max_instructions=20, include_total=true)`
  - `xrefs_to` for target, UID0003TW, and UID0003HS
  - `callees` for target and UID0003HS
- Current documentation checked:
  - UID0003TT target, UID0001AW parent, UID00037T dispatcher, UID0003TW helper, UID0003TX sibling, UID0003HS item helper, UID0001D7 item/flying index
  - UID00009S and parser children UID0004LK/UID0004LL/UID0004LM
  - MapServerPacketOpcode
  - MapPane, ObjectPane, ObjectList, LivingObjectPane, UserPane, ItemObjectPane, ObjectInfoObjectPane, SoundManager, Socket, TimerHandler, and TimerMgr class/file/support pages
  - UID0003Z6 special-effect helpers, UID000231 missing-object request, UID0001HU queue/send, UID00041G cancel-except manager, and UID0004S7 SoundManager PlaySample
  - `by-memory/-ignored.md`
- Generated files checked read-only as evidence-time callback proof:
  - `auto-generated/NexusTK/map/MapPane.cpp`
  - `auto-generated/NexusTK/map/ItemObjectPane.cpp`
  - `auto-generated/NexusTK/map/LivingObjectPane.cpp`
  - `auto-generated/NexusTK/map/ObjectStatusBlob.cpp`
- Current manual coverage checked read-only:
  - `by-memory/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `by-type/by-enum/-coverage-report.md`
  - `by-type/by-struct/-coverage-report.md`
- Negative checks:
  - no active B-agent target report
  - no legacy/special/archive direct report
  - no target row currently in manual by-memory coverage
  - no UID0003HS row currently in manual by-memory coverage
  - no range extension beyond `0x0051367b`
  - no child split inside target
  - no target-specific data/table/vtable ownership
  - no safe source basis for a complete MapServerPacketOpcode enum
  - no reason to change ObjectStatusBlob, ObjectPane, LivingObjectPane, UserPane, ObjectInfoObjectPane, Socket, TimerHandler, TimerMgr, or SoundManager formals
- Failed/unavailable checks: none. No MCP request used for this completed pass failed or timed out.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Callback proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0003TT is exact `[0x00513310,0x0051367b)`, 875 bytes, SHA256 `FAE0C2DBEA6A86884A3E0BFDDB2D152D0713823B9CED49226940718201047F93`. | very strong | MCP lookup/get_bytes/hash | UID0003TT range/evidence | incorporate | applied | UID0003TT section plus validator `13696`; final generated command `13720`. |
| C02 | Target has 239 instructions, 54 basic blocks, cyclomatic complexity 32, and one direct caller. | very strong | MCP disasm/analyze/xrefs | UID0003TT evidence | incorporate | applied | UID0003TT source-ready contract; validator `13696`. |
| C03 | The sole caller is dispatcher call `0x005083b1` for inbound opcode `0x1d`. | very strong | MCP xref plus dispatcher docs | UID0003TT, UID00037T, UID0001SO | incorporate | applied | UID0003TT plus UID00037T `13707` and UID0001SO `13710`. |
| C04 | Existing half-open end is exact; five `0xcc` bytes `[0x0051367b,0x00513680)` remain ignored successor alignment. | very strong | MCP tail/successor bytes and ignored page | UID0003TT and UID0000VN reference | incorporate | applied | UID0003TT contract; ignored page verified unchanged; validator `13696`. |
| C05 | Packet bytes `+1..+4` are a BE32 object id read by `PacketBufferReadUInt32BE`. | very strong | decompile/callee contract | UID0003TT packet layout | incorporate | applied | Destination 1 and UID0003TT contract; validator `13696`. |
| C06 | Packet byte `+5` selects full status for `0`, partial status for `1`, and immediate true for every other value. | very strong | direct branch and parser calls | UID0003TT behavior/formal | incorporate | applied | Destination 1 and UID0003TT contract; validator `13696`. |
| C07 | Full status consumes 43 bytes; partial status consumes 5 bytes. | very strong | UID0004LL/UID0004LM bodies and target arithmetic | UID0003TT, parser links | already-present | already-present | Existing parser pages retained; exact cursor incorporated into UID0003TT under `13696`. |
| C08 | Byte `6+statusBytes` is object-info type; byte `7+statusBytes` is ACP name length; bytes at `8+statusBytes` are the counted name. | very strong | direct target loads/conversion call | UID0003TT packet layout | incorporate | applied | Destination 1 and UID0003TT contract; validator `13696`. |
| C09 | The local source buffer is 33 wide characters; conversion uses CP_ACP, no flags, exact counted input, output cap 32, then indexed NUL termination. | very strong | MultiByteToWideChar arguments, rangecheck, class field cap | UID0003TT behavior/formal | incorporate | applied | Destination 1 and UID0003TT contract; generated definition under `13720`. |
| C10 | Parsing and name conversion occur before the ObjectList null test. | very strong | machine order | UID0003TT behavior/negative evidence | incorporate | applied | Destination 1 exact order; validator `13696`. |
| C11 | Non-null ObjectList calls `FindByObjectId`; a miss sends the exact outbound object refresh request; null list does nothing. | very strong | branches and UID0002CD/UID000231 | UID0003TT behavior | incorporate | applied | UID0003TT contract and generated body `13720`. |
| C12 | Object type 3 is living, type 0 is item, and all other types are no-op. | very strong | direct type byte tests plus ObjectPaneType enum | UID0003TT behavior | incorporate | applied | Destination 1 and UID0003TT contract. |
| C13 | Incoming Human composition mode 2 is rewritten to 5 when local settings index 0 is set or the object is the local player. | very strong | direct fields and current UserPane/ObjectStatusBlob declarations | UID0003TT behavior | incorporate | applied | Destination 1, MapPane class/file support `13713`/`13715`. |
| C14 | Living update copies the converted name to `m_nameBuffer` with capacity 33 and stores packet object-info type in `m_objectInfoType`. | very strong | direct writes and complete LivingObjectPane declaration | UID0003TT behavior; Living class verify | incorporate | applied | UID0003TT contract; LivingObjectPane dependency verified unchanged. |
| C15 | `SetPrimaryName` is called before the ObjectInfo pointer null test; only `SetSpriteAttribute(0)` is null-guarded. | very strong | exact call/test order | UID0003TT behavior/negative evidence | incorporate | applied | Destination 1 exact unsafe order; validator `13696`. |
| C16 | First pre-update status snapshot gates `RemoveSpecialEffect` for Human shield IDs 13/14/15/16/27 or weapon IDs 146/161. | very strong | direct compare chain and UID0003Z6 | UID0003TT behavior | incorporate | applied | UID0003TT contract and generated body `13720`. |
| C17 | The target calls `RemoveSpecialEffect` at `0x0053bad0`, not `RequestNameplateEffect` at `0x0053bab0`. | very strong | exact callee address/helper split | UID0003TT and UID0003TW historical correction | historicalize | applied | UID0003TT `13696`; UID0003TW distinction and stale-prose correction `13708`. |
| C18 | A second distinct pre-update status snapshot drives sound, kind-change, and local-copy behavior. | very strong | second GetSpriteConfig call | UID0003TT behavior/formal | incorporate | applied | Destination 1 and generated body `13720`. |
| C19 | Incoming Human body change plays sample 411 for new body 0/1, else 410, at volume 100. | very strong | direct compares/constants | UID0003TT behavior/formal | incorporate | applied | Destination 1; validator `13696`. |
| C20 | Incoming Human weapon change plays sample 411 for old weapon `0xffff`, else 410, at volume 100. | very strong | direct compares/constants | UID0003TT behavior/formal | incorporate | applied | Destination 1; validator `13696`. |
| C21 | Weapon change plus visible local-player name sends exactly `{0x13,0x04}` length 2; the local third zero is unsent. | very strong | stack word 1043, local zero, QueueAndSendPacket length | UID0003TT behavior/formal | incorporate | applied | Destination 1 and generated body `13720`. |
| C22 | Incoming Human shield/arrow change plays sample 411 when old ID is at least `0xff`, else 410, at volume 100. | very strong | direct compares/constants | UID0003TT behavior/formal | incorporate | applied | Destination 1; validator `13696`. |
| C23 | Status-kind change cancels every pending living timer except `kLivingTimerRefresh`. | very strong | direct manager call, event constant, TimerHandler wrapper | UID0003TT behavior/formal | incorporate | applied | Destination 1 inherited wrapper source shape; generated body `13720`. |
| C24 | Human local-player update copies the complete incoming 68-byte status to `m_currentAppearance` before applying sprite config. | very strong | direct 68-byte copy and UserPane field | UID0003TT behavior/formal | incorporate | applied | Destination 1; UserPane dependency verified unchanged. |
| C25 | Final living order is `SetSpriteConfig(&status,m_facing)` then `RefreshObjectStatusOverlay(living)`, ignoring the setter result. | very strong | exact calls/order | UID0003TT behavior/formal | incorporate | applied | Destination 1; UID0003TW preserved; generated `13720`. |
| C26 | Item type calls UID0003HS only when incoming appearance ID is at least `0xc000`. | very strong | direct type/threshold branch | UID0003TT and UID0003HS | incorporate | applied | Both target/helper contracts; validators `13696`/`13699`. |
| C27 | UID0003HS is exact `[0x00537bc0,0x00537be9)`, 41 bytes, SHA256 `7B145A9792807D0647D01512FB8A89BBF5445077F24B0D3BA9B5B845C8D9852F`, with one caller `0x00513665`. | very strong | MCP lookup/get_bytes/hash/xrefs | UID0003HS evidence | incorporate | applied | UID0003HS source-ready contract; validator `13699`. |
| C28 | UID0003HS copies `m_appearanceId` to `m_itemId`, `m_variantOrPalette` to `m_paletteFlags`, then refreshes screen bounds through `g_activeMapPane`. | very strong | helper decompile and complete declarations | UID0003HS formal/body | incorporate | applied | Destination 2; Item class/file `13718`/`13719`; generated `13720`. |
| C29 | UID0003HS belongs to ItemObjectPane/ItemObjectPane.cpp; the old LivingObjectPane physical-adjacency statement is superseded. | very strong | caller type-zero branch, fields, class/file routes | UID0003HS, UID0001D7, Item class/file | historicalize | applied | UID0003HS/UID0001D7/Item class/file validators `13699`/`13702`/`13718`/`13719`. |
| C30 | Both methods always return/complete without new error reporting; target returns true on every path. | very strong | all exits | UID0003TT/UID0003HS behavior | incorporate | applied | Both managed blocks and generated command `13720`. |
| C31 | No packet length, null packet, conversion failure, local-player, ObjectInfo setter, sender, sound, timer, or helper-result guard may be added. | very strong | negative binary evidence | UID0003TT negative evidence/formal | reject-invalid | excluded-with-reason | Destination 1 preserves unsafe behavior; generated scan found zero added defensive/decompiler scaffolding. |
| C32 | UID0003TT remains owner/emitter UID00007Q, reconstructable true, blank position, `Nested:0`, and rises only to `92/94`. | very strong | class/file route and closed blockers | UID0003TT metadata | incorporate | applied | Header and validator `13696`; final SHA `3197AC75...B9870`. |
| C33 | UID0003HS remains owner/emitter UID00006V, reconstructable true, blank position, `Nested:0`, and rises only to `92/94`. | very strong | complete class/file route and exact body | UID0003HS metadata | incorporate | applied | Header and validator `13699`; final SHA `7166198D...4882F`. |
| C34 | UID0001AW stays false/non-emitting at `86/90`; exact child bodies remain child-owned. | very strong | current parent policy | UID0001AW prose/summary | already-present | already-present | State/formal preserved; bounded child sync validated by `13704`. |
| C35 | UID00037T stays `88/90` with blank dispatcher formal; only its opcode-`0x1d` row is resolved by this target. | very strong | unrelated case-group inventory remains open | UID00037T prose | already-present | already-present | State/table/formal preserved; opcode row validated by `13707`. |
| C36 | MapServerPacketOpcode stays `88/90` with blank formal because original enum spellings across the full switch remain unproven. | very strong | current enum scope and negative symbol evidence | UID0001SO prose/manual row | already-present | already-present | State/formal/inventory preserved; opcode row validated by `13710`. |
| C37 | UID0003TW remains the two-caller file-static post-update overlay helper and is not duplicated inside Destination 1. | very strong | exact two xrefs and current formal | UID0003TW bounded sync | already-present | already-present | Body retained; validator `13708`; generated command `13720` has one definition. |
| C38 | Parser class/file/children, ObjectPane, LivingObjectPane, UserPane, ObjectInfoObjectPane, ObjectList, Socket, TimerHandler, TimerMgr, and SoundManager formals remain unchanged. | very strong | current complete support docs | verify-only support matrix | already-present | already-present | Read-only dependency hashes rechecked; MapPane and ItemObjectPane class formal hashes preserved exactly. |
| C39 | Security-cookie, range-check, narrow-trait, register, vtable, and raw-offset lowering is compiler/decompiler output and excluded from both formals. | very strong | disassembly/decompile and source conventions | target/helper negative evidence | reject-invalid | excluded-with-reason | Both managed blocks exclude lowering; generated scan under `13720` found zero forbidden scaffolding hits. |
| C40 | No split, merge, rename, child creation, padding edit, generated edit, manual coverage edit, or IDA mutation is required in Gate 1. | very strong | exact range and current routes | implementation scope | not-applicable | excluded-with-reason | No such manual changes occurred; generated/projected/registry changes were validator-owned side effects only. |
| C41 | No third-party import applies; both bodies are NexusTK-owned ordinary source. | very strong | ownership and callgraph | target/helper formal policy | not-applicable | excluded-with-reason | Both exact ordinary managed bodies applied; no import directive added. |
| C42 | B005 supplied exact supervisor-owned manual coverage text for ten rows/placements and did not apply it. | very strong | callback-time manual coverage comparison | manual handoff section | incorporate | applied | Exact ten-row handoff and five evidence-time manual hashes are retained; B005 applied no manual row, while later/current application state remains validator/supervisor-owned. |

Ledger counts: `42` claims; Action counts remain `incorporate=30`, `already-present=6`, `historicalize=2`, `reject-stale=0`, `reject-invalid=2`, `not-applicable=2`; terminal Verification state counts are `applied=32`, `already-present=6`, `excluded-with-reason=4`, `blocked=0`.

## Positive Evidence Summary

- The target is a real modeled MapPane method with exact bytes, one live opcode dispatcher caller, complete decompilation, exact parser and helper callees, and no unresolved range or route.
- Existing current declarations expose every source type and field used by the body without raw offsets: ObjectPane type enum/accessor, ObjectStatusBlob layout/parsers, LivingObjectPane fields/methods/friendship, UserPane settings/current appearance, ObjectInfoObjectPane methods, ItemObjectPane fields/method declaration, Socket send, SoundManager playback, and TimerHandler cancellation wrapper.
- The packet cursor is fully reconstructable from parser return values and direct loads; no opaque packet struct or guessed fixed union is needed.
- UID0003HS has a complete source body and one exact target caller. Its former final-C++ blocker was stale because the complete ObjectStatusBlob and ItemObjectPane declarations now name every accessed field.
- The strongest inference chain is: dispatcher opcode route -> exact packet method -> explicit parser selection and returned cursor -> complete status/object class declarations -> exact living/item branches -> exact helper contracts -> source-clean method bodies. That chain is sufficient for `92/94` on both source-bearing pages.

## IDA MCP Facts

- Session: `64c11373`; database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; health `ok`; analysis/Hex-Rays/strings ready.
- Target function: `sub_513310`, start `0x00513310`, size `0x36b`, exclusive end `0x0051367b`.
- Target full bytes: 875 bytes; SHA256 `FAE0C2DBEA6A86884A3E0BFDDB2D152D0713823B9CED49226940718201047F93`.
- Target analysis: 239 instructions, 54 basic blocks, cyclomatic complexity 32.
- Target caller: one code xref at `0x005083b1` from `sub_507C90`.
- Target direct callees: `0x005754c0`, `0x004d1fa0`, `0x004d2640`, `MultiByteToWideChar`, `0x00532370`, `wcscpy_s`, `0x00539650`, `0x0053a8c0`, `0x0053bad0`, `0x0057a5c0`, `0x00574bb0`, `0x00597ca0`, `0x0053a900`, `0x0050fa90`, `0x00537bc0`, `0x00506380`, plus compiler/runtime narrow-trait, range-check, and security-cookie helpers.
- Target `retn 4` is at `0x0051364b`; branch-only item/miss/rangecheck blocks occupy the later addresses through the final call at `0x00513676`.
- Successor bytes at `0x0051367b` begin `cc cc cc cc cc`; the next raw body starts at `0x00513680`.
- UID0003TW xrefs: exactly `0x0050fe75` from UID0003TX and `0x00513634` from UID0003TT.
- UID0003HS: `sub_537BC0`, exact size `0x29`, range `[0x00537bc0,0x00537be9)`, SHA256 `7B145A9792807D0647D01512FB8A89BBF5445077F24B0D3BA9B5B845C8D9852F`, one caller at `0x00513665`.
- UID0003HS decompile writes `this+0x128` from status `+0x04`, `this+0x12a` from status `+0x06`, and tail-transfers to active MapPane `0x00506980`.
- Negative IDA facts: no target split, no target data/table owner, no alternate direct caller, no parser aggregate call, no ObjectInfo null guard before SetPrimaryName, and no source-level packet bounds checks.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00513305-0x00513310` | UID0000VN / `by-memory/-ignored.md` | predecessor alignment | false/ignored | none | `100/strong` | retain exactly |
| `0x00513310-0x0051367b` | UID0003TT target | private MapPane packet method | true | UID00007Q | `86/90 -> 92/94` | populate Destination 1 |
| `0x0051367b-0x00513680` | UID0000VN / `by-memory/-ignored.md` | successor alignment | false/ignored | none | `100/strong` | retain exactly |
| `0x00513680...` | existing no-route raw switch body | separate raw source-shaped evidence | separate scope | separate route | unchanged | do not absorb |
| `0x00537bc0-0x00537be9` | UID0003HS | ItemObjectPane status update | true | UID00006V | `86/90 -> 92/94` | populate Destination 2 |
| `0x00537b40-0x005380af` | UID0001D7 | non-emitting Item/Flying split index | false | none | `90/93` | prose/manual sync only |
| `0x0050fa90-0x0050faf4` | UID0003TW | file-static post-update overlay helper | true | UID0000L3 | `91/93` | verify body; historicalize stale blank prose |
| `0x004d1fa0-0x004d2637` | UID0004LL | full status parser | true | UID00009S | `91/93` | verify-only |
| `0x004d2640-0x004d2697` | UID0004LM | partial status parser | true | UID00009S | `92/94` | verify-only |
| `0x004d1f30-0x004d1f99` | UID0004LK | tagged parser, not called by target | true | UID00009S | unchanged | negative/contrast support |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005083b1` | dispatcher -> UID0003TT | sole live opcode-`0x1d` call |
| `0x00513336` | UID0003TT -> PacketBufferReadUInt32BE | object id |
| `0x00513354` | UID0003TT -> ParseFullStatus | selector 0, return 43 |
| `0x0051336d` | UID0003TT -> ParsePartialStatus | selector 1, return 5 |
| `0x005133af` | UID0003TT -> MultiByteToWideChar | counted ACP name |
| `0x005133d3` | UID0003TT -> ObjectList::FindByObjectId | target lookup |
| `0x0051344e` | UID0003TT -> ObjectInfoObjectPane::SetPrimaryName | unconditional pointer call |
| vslot `+0x20` at `0x0051345d` | ObjectInfoObjectPane::SetSpriteAttribute(0) | null-guarded clear |
| `0x00513470`, `0x005134d5` | two GetSpriteConfig calls | distinct pre-update snapshots |
| `0x005134c0` | UID0003TT -> LivingObjectPane::RemoveSpecialEffect | special effect ID 134 removal |
| `0x0051350a/11`, `0x0051353d/44`, `0x00513599/a0` | SoundManager::PlaySample | exact sample predicates |
| `0x0051356d` | Socket::QueueAndSendPacket | bytes `13 04`, length 2 |
| `0x005135c5` | inlined TimerHandler cancel-except route -> TimerMgr | preserve living refresh event |
| `0x0051362c` | LivingObjectPane::SetSpriteConfig | apply incoming status/facing |
| `0x00513634` | RefreshObjectStatusOverlay | post-update overlay request |
| `0x00513665` | ItemObjectPane::UpdateItemStatus | type-zero/high-item branch |
| `0x0051366f` | SendObjectRefreshRequest | non-null-list lookup miss |
| `0x00537be3` | UID0003HS -> UpdateObjectPaneScreenBounds | final item refresh |

## Documentation Evidence And IDA Status

- Current ObjectStatusBlob documentation is complete and directly supports every status field and parser used by the target.
- Current ObjectPane, LivingObjectPane, UserPane, ItemObjectPane, ObjectInfoObjectPane, ObjectList, Socket, SoundManager, TimerHandler, and MapPane declarations expose the source-facing API required by Destinations 1 and 2.
- UID0003Z6 proves the two special-effect methods are separate and settles the target's `0x0053bad0` call as `RemoveSpecialEffect`.
- UID0003TW retains its exact post-update helper C++ and now labels the older blank/provisional Status and Score prose historical/superseded. Its pre-update `RemoveSpecialEffect` versus post-update `RequestNameplateEffect` distinction is explicit.
- UID0001D7 ordinary documentation is a current `90/93`, false/non-emitting exact split index with source-ready UID0003HS. At callback comparison time its supervisor-owned manual row was stale, and the exact supplied handoff is retained below without asserting the row's later/current application state.
- B005's evidence-time generated callback proof comes from final waited command `000000013720`, refreshed `2026-07-16T09:42:15-04:00`; these hashes are callback evidence and are not asserted as the latest global project epoch after unrelated validators:

| Generated file | Validator header | Current SHA256 | Bytes / lines | Target assertion |
| --- | --- | --- | ---: | --- |
| `auto-generated/NexusTK/map/MapPane.cpp` | command `000000013720`, refreshed `2026-07-16T09:42:15-04:00` | `70307BF94F86B79E0E6D594C873555E0E19A91A952AD6BAB934A213978B67527` | 142,971 / 4,285 | one class declaration, exactly one UID0003TT definition, zero UID0003TT markers, one unchanged UID0003TW definition, zero forbidden compiler/decompiler scaffolding hits |
| `auto-generated/NexusTK/map/ItemObjectPane.cpp` | command `000000013720`, refreshed `2026-07-16T09:42:15-04:00` | `393FB0D6F5AF28B73BC2EE85C460D00E0AD842A28A9DC91B6EE5FE9CEBE4C549` | 3,736 / 82 | one class declaration, exactly one UID0003HS definition, zero UID0003HS markers; definition follows UID0003HR destructor before compiler/pool coverage |
| `auto-generated/NexusTK/map/LivingObjectPane.cpp` | command `000000013720`, refreshed `2026-07-16T09:42:15-04:00` | `B22C284AB966EE68D0D4A38144894A208DAA01B7B81399EA54835D0A0DF241BE` | 36,500 / 1,154 | accepted timer-wrapper source pattern and special-effect bodies remain present |
| `auto-generated/NexusTK/map/ObjectStatusBlob.cpp` | command `000000013720`, refreshed `2026-07-16T09:42:15-04:00` | `41067F18DCFBA8CDE0832AA3EB7E1499FBC1DD00CCBD4F9268D2C57656DB61E3` | 9,097 / 256 | complete class and parser definitions remain present |

- The following manual coverage snapshots were re-read after implementation and were byte-identical to the accepted report-only baseline at B005 callback time. Every target-scope row/placement was compared, and the exact handoff text was a no-loss union of those evidence-time rows plus the implemented UID0003TT/UID0003HS facts. These hashes and row states are callback evidence, not current lifecycle/application authority:

| Manual file | SHA256 | Bytes / lines | Callback evidence-time target-scope state |
| --- | --- | ---: | --- |
| `by-memory/-coverage-report.md` | `0F53BD71C344B862EA58BA12BE64ABAECE6D3579BBF13566A8197E506DCB1344` | 1,746,578 / 4,213 | At callback time UID0003TT and UID0003HS were absent, and UID00037T/UID0001AW/UID0001D7 required the supplied no-loss additions |
| `by-class/-coverage-report.md` | `E61DB3F079B38666072FDC89D71737BAB9CFBD85C00A3DC7A836D7DB6E34DCD5` | 225,165 / 622 | At callback time MapPane and ItemObjectPane rows retained newer cross-agent facts and required the bounded no-loss UID0003TT/UID0003HS additions supplied below |
| `by-file/-coverage-report.md` | `A1B73657FCC4F2A5F131C7E3F355E8D007538D0323397DFD7F026F64A59DF882` | 128,817 / 316 | At callback time MapPane and 91% ItemObjectPane rows retained newer cross-agent facts and required the bounded no-loss UID0003TT/UID0003HS additions supplied below |
| `by-type/by-enum/-coverage-report.md` | `205ECB50FD52B3A1112D03D856D53DC75646D46CB44C051A530B0C5F7FFCF504` | 5,558 / 33 | At callback time the MapServerPacketOpcode row required the supplied opcode-`0x1d` addition |
| `by-type/by-struct/-coverage-report.md` | `1CF4BE88435275FFEF80180E56425FFE5159AF89DF4E311991DE2B54EECD61F9` | 57,345 / 137 | verify-only; no layout row changes |

## Ranked Ownership Analysis

### 1. MapPane member in MapPane.cpp

- Evidence for: direct MapPane dispatcher caller, receiver fields `m_objectList` and `m_localPlayerObjectPane`, complete MapPane declaration, sibling packet-handler source order, file-static MapPane helper call, and current owner/emitter route.
- Evidence against: none material. Many callees belong to other modules, but they are dependencies.
- Decision: accepted owner/emitter and source placement for Destination 1.

### 2. ItemObjectPane member in ItemObjectPane.cpp

- Evidence for: UID0003HS receiver fields exactly match ItemObjectPane `m_itemId`/`m_paletteFlags`; only caller is target's type-zero branch; class declares `UpdateItemStatus`; active MapPane call refreshes this object.
- Evidence against: physical adjacency to LivingObjectPane consumers caused an old stale label, but direct branch and fields disprove that owner.
- Decision: accepted owner/emitter and source placement for Destination 2.

### 3. ObjectStatusBlob or LivingObjectPane ownership for target

- Evidence for: target heavily consumes their fields and methods.
- Evidence against: target receiver is MapPane, dispatcher route is MapPane, packet/object selection is MapPane policy, and these classes own only parsed data or updated objects.
- Decision: rejected as target owner; retain as dependencies.

### 4. Protocol/Socket or packet-enum ownership

- Evidence for: target parses inbound protocol bytes and sends one outbound packet.
- Evidence against: Socket only owns queue/send; MapServerPacketOpcode is a working numeric index; target mutates MapPane/object state and has a MapPane receiver.
- Decision: rejected.

### 5. Non-emitting/compiler/raw disposition

- Evidence for: target currently has an Empty Emitter Marker and contains compiler range/security lowering.
- Evidence against: real modeled function, sole live dispatcher call, complete ordinary behavior, class declaration, source siblings, exact dependencies, and source-clean bodies.
- Decision: rejected. Only compiler lowering is excluded.

## Source Placement

- Destination 1 belongs in `NexusTK/map/MapPane.cpp` through class UID00007Q and file UID0000L3.
- Existing source order is correct: after UID0003TS `HandleAnimationSoundPacket`, before the later raw no-route body and subsequent packet methods.
- Destination 2 belongs in `NexusTK/map/ItemObjectPane.cpp` through class UID00006V and file UID0000KG, after the ordinary destructor and before inherited bounds/render child bodies.
- Rejected placements:
  - `ObjectStatusBlob.cpp`: owns value parsing only.
  - `LivingObjectPane.cpp`: owns living state/effects, not MapPane packet dispatch.
  - `AttachedObjectPane.cpp`: owns ObjectInfo implementation, not caller policy.
  - `Socket.cpp`: owns transport/queue mechanics only.
  - a new protocol source file: no separate owner or shared body is proven.
- Remaining source placement uncertainty: none affecting emission. Exact historical header include layout is not symbol-proven but current class/file routes are compile-direction complete.

## Range / Split / Padding / Reclassification Analysis

- Target range remains `[0x00513310,0x0051367b)`.
- The apparent early `retn 4` does not shorten the target. Branch-only blocks for item update, missing-object refresh, and range-check failure remain in the same modeled function after that return address.
- Predecessor alignment `[0x00513305,0x00513310)` is eleven `0xcc` bytes and remains ignored.
- Successor alignment `[0x0051367b,0x00513680)` is five `0xcc` bytes and remains ignored.
- The raw body starting `0x00513680` is outside the target and is not absorbed or reclassified by this report.
- UID0003HS range `[0x00537bc0,0x00537be9)` is exact; no child split or padding repair is needed.
- UID0001D7 remains a false/non-emitting mixed address index with exact source-bearing children. It should receive only bounded current prose/manual synchronization.
- No UID allocation, path rename, range rename, parent nesting change, or ignored-row duplication was required or performed.

## Negative Evidence Summary

- No prior direct UID0003TT source-quality report exists.
- No second target caller, callback pointer, vtable slot, data table, or independent raw owner was found.
- No evidence supports extending the target past `0x0051367b`.
- No evidence supports treating byte `+5` as the tagged ObjectStatusBlob parser's tag.
- No evidence supports adding packet-size, pointer, conversion, global, helper-return, or object-state guards.
- No evidence supports replacing the unsafe ObjectInfo call order with null-safe code.
- No evidence supports calling `RequestNameplateEffect` at the target's pre-update special-effect site.
- No evidence supports a hand-authored range-check failure, security-cookie check, narrow-trait wrapper, raw vtable dispatch, raw offset access, or register-shaped temporary.
- No evidence supports a complete emitted MapServerPacketOpcode enum or an original enumerator spelling for opcode `0x1d`.
- No evidence supports moving UID0003HS out of ItemObjectPane or changing any support class layout.

## IDA Rename / Type / Comment Recommendations

- Source-facing target name: retain `MapPane::HandleObjectStatusPacket`.
- Source-facing target argument: `const unsigned char *packet`.
- Source-facing local names: `objectId`, `status`, `statusBytes`, `objectInfoType`, `nameLength`, `objectName`, `objectPane`, `livingObjectPane`, `objectInfoPane`, `effectStatus`, `previousStatus`, and `statusRefreshPacket`.
- Source-facing UID0003HS name: `ItemObjectPane::UpdateItemStatus`.
- Existing field/type names to use unchanged: `m_objectList`, `m_localPlayerObjectPane`, `m_playerSettingsState`, `m_currentAppearance`, `m_nameBuffer`, `m_objectInfoType`, `m_objectInfoObjectPane`, `m_nameVisible`, `m_facing`, `m_itemId`, `m_paletteFlags`, and all ObjectStatusBlob members used in the formals.
- Original-proof versus inference:
  - addresses, types, widths, offsets, constants, and behavior are direct.
  - method/local/field spellings are current source-facing inferred names corroborated by complete current declarations and sibling source.
  - sample meanings for IDs `410/411` are intentionally not named because no authoritative semantic label was recovered.
- IDA database changes are not requested and must not be made.

## First-Draft C++ Recommendation

- Eligible source-bearing destinations: exactly two.
- Both accepted/applied C++ destinations remain reproduced below exactly; no C++ exists outside their literal managed blocks.

Destination 1: `by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool MapPane::HandleObjectStatusPacket(const unsigned char *packet)
{
    const int objectId =
        static_cast<int>(PacketBufferReadUInt32BE(packet + 1));

    ObjectStatusBlob status;
    status.m_displayStatusByte = 80;

    int statusBytes;
    if (packet[5] == 0)
    {
        statusBytes = status.ParseFullStatus(packet + 6);
    }
    else if (packet[5] == 1)
    {
        statusBytes = status.ParsePartialStatus(packet + 6);
    }
    else
    {
        return true;
    }

    const unsigned char objectInfoType = packet[statusBytes + 6];
    const unsigned char nameLength = packet[statusBytes + 7];

    wchar_t objectName[33];
    const int objectNameLength =
        MultiByteToWideChar(
            CP_ACP,
            0,
            reinterpret_cast<const char *>(packet + statusBytes + 8),
            nameLength,
            objectName,
            32);
    objectName[objectNameLength] = L'\0';

    if (m_objectList == NULL)
        return true;

    ObjectPane *objectPane = m_objectList->FindByObjectId(objectId);
    if (objectPane == NULL)
    {
        SendObjectRefreshRequest(objectId);
        return true;
    }

    const unsigned char objectType = objectPane->GetObjectType();
    if (objectType == kObjectPaneTypeLiving)
    {
        LivingObjectPane *livingObjectPane =
            static_cast<LivingObjectPane *>(objectPane);
        UserPane *localPlayer =
            static_cast<UserPane *>(m_localPlayerObjectPane);

        if (status.m_statusKind == ObjectStatusBlob::HumanObject &&
            status.m_compositionMode == 2 &&
            (localPlayer->m_playerSettingsState[0] ||
             livingObjectPane == m_localPlayerObjectPane))
        {
            status.m_compositionMode = 5;
        }

        wcscpy_s(livingObjectPane->m_nameBuffer, 33, objectName);
        livingObjectPane->m_objectInfoType = objectInfoType;

        ObjectInfoObjectPane *objectInfoPane =
            livingObjectPane->m_objectInfoObjectPane;
        objectInfoPane->SetPrimaryName(objectName);
        if (objectInfoPane != NULL)
            objectInfoPane->SetSpriteAttribute(0);

        ObjectStatusBlob effectStatus;
        effectStatus.m_displayStatusByte = 80;
        livingObjectPane->GetSpriteConfig(&effectStatus);
        if (effectStatus.m_statusKind == ObjectStatusBlob::HumanObject &&
            (effectStatus.m_shieldOrArrowId == 13 ||
             effectStatus.m_shieldOrArrowId == 14 ||
             effectStatus.m_shieldOrArrowId == 15 ||
             effectStatus.m_shieldOrArrowId == 16 ||
             effectStatus.m_shieldOrArrowId == 27 ||
             effectStatus.m_weaponId == 146 ||
             effectStatus.m_weaponId == 161))
        {
            livingObjectPane->RemoveSpecialEffect();
        }

        ObjectStatusBlob previousStatus;
        previousStatus.m_displayStatusByte = 80;
        livingObjectPane->GetSpriteConfig(&previousStatus);

        if (status.m_statusKind == ObjectStatusBlob::HumanObject)
        {
            if (previousStatus.m_bodyId != status.m_bodyId)
            {
                g_pSoundManager->PlaySample(
                    status.m_bodyId <= 1 ? 411 : 410,
                    100);
            }

            if (previousStatus.m_weaponId != status.m_weaponId)
            {
                g_pSoundManager->PlaySample(
                    previousStatus.m_weaponId == 0xffff ? 411 : 410,
                    100);

                if (g_pUserPane->m_nameVisible)
                {
                    unsigned char statusRefreshPacket[3] =
                        { 0x13, 0x04, 0 };
                    g_packetSender->QueueAndSendPacket(
                        statusRefreshPacket,
                        2);
                }
            }

            if (previousStatus.m_shieldOrArrowId !=
                status.m_shieldOrArrowId)
            {
                g_pSoundManager->PlaySample(
                    previousStatus.m_shieldOrArrowId >= 0xff ? 411 : 410,
                    100);
            }
        }

        if (previousStatus.m_statusKind != status.m_statusKind)
        {
            livingObjectPane->CancelPendingTimersExceptEvent(
                LivingObjectPane::kLivingTimerRefresh);
        }

        if (livingObjectPane == m_localPlayerObjectPane &&
            status.m_statusKind == ObjectStatusBlob::HumanObject)
        {
            localPlayer->m_currentAppearance = status;
        }

        livingObjectPane->SetSpriteConfig(
            &status,
            livingObjectPane->m_facing);
        RefreshObjectStatusOverlay(livingObjectPane);
    }
    else if (objectType == kObjectPaneTypeItem &&
             status.m_appearanceId >= 0xc000)
    {
        static_cast<ItemObjectPane *>(objectPane)->UpdateItemStatus(&status);
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 2: `by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md`

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ItemObjectPane::UpdateItemStatus(const ObjectStatusBlob *status)
{
    m_itemId = status->m_appearanceId;
    m_paletteFlags = status->m_variantOrPalette;
    g_activeMapPane->UpdateObjectPaneScreenBounds(this);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Behavior preservation:
  - Destination 1 preserves packet cursor movement, unsupported-selector early success, parse-before-list ordering, unsafe ObjectInfo ordering, two separate status snapshots, all exact comparisons/constants, local-only terminator bytes, inlined timer-wrapper route, item threshold, ignored results, and unconditional success.
  - Destination 2 preserves exact two field writes and the final active MapPane refresh without a guard or extra return value.
- Source-shape rationale:
  - uses accepted project class APIs and fields rather than decompiler labels or raw offsets;
  - preserves ordinary member/static helper boundaries;
  - uses the accepted TimerHandler wrapper source style that can inline to the observed direct manager call;
  - excludes compiler range/security/narrow-trait lowering.
- Third-party import: not applicable. These are NexusTK project methods, not imported third-party source.

## Final Recommendation

- Destination 1 is applied to UID0003TT at `92/94`; Destination 2 is applied to UID0003HS at `92/94`.
- Both pages preserve their accepted owner/emitter/reconstructable/position/nesting/range/path metadata.
- Exact report-level behavior, history, negative evidence, and source/compiler boundaries are incorporated into both source-bearing pages.
- Bounded support prose is synchronized on UID0001AW, UID00037T, UID0001D7, UID0003TW, MapServerPacketOpcode, MapPane class/file, and ItemObjectPane class/file.
- UID0003TX, UID00009S, UID0004LK/LL/LM, ObjectPane, ObjectList, LivingObjectPane, UserPane, ObjectInfoObjectPane, Socket, TimerHandler, TimerMgr, SoundManager, globals, and ignored padding were verified same-or-greater detail with no contradiction requiring an edit.
- UID0001AW remains non-emitting, UID00037T formal remains blank, MapServerPacketOpcode formal remains blank, and all generated/manual coverage files remain supervisor/validator-owned.
- No B005 implementation item remains. Broader dispatcher case reconstruction and original protocol enum spelling remain separate independent targets, not blockers to this completed method.

## Recommended Target Doc Changes

Target: `by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md`

- Applied/verified callback status: every target change below is complete under scoped validator command `000000013696`; B005's evidence-time final generated proof is command `000000013720`.
- Scores: `86/90 -> 92/94`.
- Preserve:
  - UID/path/title/range
  - `CANONICAL_OWNER:00007Q`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00007Q`
  - blank emitter position
  - `Nested:0`
- Exact Item Summary:
  - `Source-ready opcode-0x1d MapPane object-status handler parses a BE32 object id, full/partial ObjectStatusBlob, object-info type, and counted ACP name; updates living name/ObjectInfo/effects/sounds/timers/local appearance/sprite/overlay or high-id item state, requests missing-object refresh, preserves trusted-buffer and unsafe pointer ordering, and returns true on every path.`
- The blank formal block was replaced with Destination 1 exactly.
- Incorporated at report-level detail:
  - exact bytes/hash/instruction/CFG/caller/range/padding
  - exact packet offsets and selector behavior
  - exact parser returns/cursor
  - exact name conversion and capacity
  - object-list null/miss behavior
  - living/item type branches
  - composition rewrite
  - ObjectInfo call order
  - two snapshots
  - RemoveSpecialEffect distinction
  - body/weapon/shield sound predicates
  - two-byte status refresh send
  - timer cancellation
  - local appearance copy
  - final update order
  - unsafe/no-check behavior
  - rejected alternatives and compiler exclusions
- The prior blank-C++/provisional-field/helper blocker wording is historicalized as superseded by the MCP-backed pass.

## Recommended Support Doc Changes

Applied/verified callback status: all ten bounded support changes below are complete under scoped validator commands `13699`, `13702`, `13704`, `13707`, `13708`, `13710`, `13713`, `13715`, `13718`, and `13719`; verify-only dependencies remained unchanged.

1. `by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md`
   - Raise `86/90 -> 92/94`.
   - Preserve UID/path/range, owner/emitter UID00006V, reconstructable true, blank position, `Nested:0`.
   - Exact Item Summary:
     - `Source-ready ItemObjectPane::UpdateItemStatus copies ObjectStatusBlob appearance and palette fields into ground-item state, then refreshes screen bounds through the active MapPane; exact one-caller/type-zero/high-item gate, range/hash, source route, and no-extra-guard behavior are preserved.`
   - Apply Destination 2 exactly.
   - Replace current final-C++ blocker wording; retain older LivingObjectPane misownership as explicitly superseded history.

2. `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md`
   - Preserve `90/93`, false/non-emitting, no owner/emitter, blank formal, and all FlyingObjectPane content.
   - Add UID0003HS source-ready body/score/hash/caller/current route.
   - Preserve UID0003HR and all current child inventory; historicalize the old manual below-gate/Living-adjacency state.

3. `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
   - Preserve `86/90`, false/non-emitting, owner UID00007Q, blank formal, `Nested:0`, and every current child.
   - Add UID0003TT as exact source-ready opcode-`0x1d` child with packet/object/status behavior and compiler exclusions.

4. `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md`
   - Preserve `88/90`, owner/emitter UID00007Q, exact table tail, blank formal, and unrelated 51-target plan.
   - Resolve only case target `0x005083aa` / opcode `0x1d` to direct true-return UID0003TT route and exact payload summary.

5. `by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md`
   - Preserve `91/93`, body, owner/emitter UID0000L3, position, range, and two callers.
   - Label its older blank-C++/provisional-name Status/Score prose historical/superseded; current source-ready formal remains authoritative.
   - Add explicit distinction: UID0003TT pre-update call is `RemoveSpecialEffect`; UID0003TW post-update call is `RequestNameplateEffect`.

6. `by-type/by-enum/MapServerPacketOpcode.md`
   - Preserve `88/90`, owner/emitter UID0000L3, blank formal, full current opcode inventory, and original-spelling caveat.
   - Replace generic opcode-`0x1d` `status packet` row with exact object-status route/payload/handler summary.
   - Mark opcode `0x1d` resolved at case-child level while retaining the broader enum no-code decision.

7. `by-class/MapPane.md`
   - Preserve `93/94` and the complete managed declaration byte-for-byte.
   - Add exact UID0003TT source-ready method behavior, dependencies, source order, unsafe checks, and compiler exclusions.

8. `by-file/MapPane.md`
   - Preserve `92/92`, path, all current shared content, and no by-file formal metadata.
   - Add exact UID0003TT source route after UID0003TS, target behavior, UID0003HS dependency, and no-duplicate/no-compiler-lowering policy.

9. `by-class/ItemObjectPane.md`
   - Preserve `92/94` and the complete managed declaration byte-for-byte.
   - Replace the generic record-state description with exact `UpdateItemStatus` body, target caller gate, active MapPane refresh, and source-ready child score.

10. `by-file/ItemObjectPane.md`
    - Preserve `91/93`, path, current class/pool/destructor/flying content, and no by-file formal metadata.
    - Add exact UID0003HS body/source order and reject the historical LivingObjectPane-adjacency interpretation as superseded.

11. Verify-only unless a callback reread finds a contradiction:
    - UID0003TX
    - UID00009S, UID0000M6, UID0004LK, UID0004LL, UID0004LM
    - ObjectPane/ObjectList/LivingObjectPane/UserPane/ObjectInfoObjectPane classes/files
    - UID0003Z6, UID000231, UID0002CD, UID0001HU, UID00041G, UID0004S7
    - related globals
    - `by-memory/-ignored.md`
    - generated files and every manual coverage report

## Score And Metadata Recommendation

- UID0003TT before callback: `86/90`, owner/emitter UID00007Q, reconstructable true, blank position, `Nested:0`, blank formal.
- UID0003TT current: `92/94`; all non-score metadata unchanged; Destination 1 populated and generated once.
- UID0003HS before callback: `86/90`, owner/emitter UID00006V, reconstructable true, blank position, `Nested:0`, blank formal.
- UID0003HS current: `92/94`; all non-score metadata unchanged; Destination 2 populated and generated once.
- No other score changed.
- Score-improvement blockers and closure:
  - provisional status subtype -> resolved as explicit full/partial selector values `0/1`
  - packet blob layout -> resolved exact cursor and post-status fields
  - optional text behavior -> resolved exact counted ACP conversion/cap/termination
  - object type tests -> resolved through complete ObjectPaneType
  - field names/types -> resolved through complete current class layouts
  - helper names -> resolved, including RemoveSpecialEffect distinction
  - timer source shape -> resolved through accepted inherited wrapper/inlining pattern
  - item helper body -> resolved exact two writes/refresh
  - range/padding -> exact
  - source placement -> exact current class/file routes
  - negative behavior -> recorded and preserved
- Why not higher:
  - no PDB/original source proves exact method/local names;
  - opcode enumerator spelling remains unknown;
  - samples `410/411` lack authoritative semantic names;
  - original header/include arrangement is inferred.
- Those are lexical/source-history caps, not behavioral or compile-shape blockers.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution and score/C++ impact |
| --- | --- | --- |
| Is packet byte `+5` a status tag? | target branches, parser calls, tagged parser child | No. It is a target-local full/partial selector. Closed. |
| What follows the parsed status? | direct loads and cursor arithmetic | object-info byte, one-byte ACP length, counted ACP name. Closed. |
| Is the name optional? | conversion always reached for selector 0/1; length may be zero | The field is always structurally present; zero length produces an empty name. Closed. |
| Does the target call nameplate creation or special-effect removal before update? | exact call address and UID0003Z6 split | RemoveSpecialEffect before update; UID0003TW may request nameplate after update. Closed. |
| Is TimerMgr called directly in original source? | target direct call, tiny TimerHandler wrapper, accepted LivingObjectPane source pattern | Highest-probability human source is inherited `CancelPendingTimersExceptEvent`, inlined to the direct manager call. Closed for source shape; lexical exactness remains a confidence cap only. |
| What do sample IDs 410 and 411 mean? | target predicates, SoundManager docs, broad searches | Exact semantic labels are not proven. Keep numeric IDs, preserving behavior without invented names. This caps confidence but not C++. |
| Is object-info type an enum? | packet byte store and ObjectInfo consumers | Exact values are not needed in this method; preserve `unsigned char objectInfoType` into existing unsigned field. No enum is invented. Closed. |
| Should UID0003HS return the MapPane helper result? | current class declaration, target call, decompile tail return propagation | Source-facing method is `void`; raw EAX propagation is lowering. Closed. |
| Does the target range end at the first return? | full function bytes/CFG/tail branches | No; later branch blocks remain in the same function. Existing end is exact. Closed. |
| Does a prior direct report exist? | complete current executed/active/legacy search | No. Closed. |

No target-scope question remains unresolved in a way that blocks C++, ownership, range, metadata, or the implemented score.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B005 performed the manual comparison read-only and repeated it during the final callback self-audit against the evidence-time hashes recorded above. B005 did not and must not edit these files. The exact instructions and no-loss rows below are retained verbatim as the supervisor handoff supplied at callback time; wording such as "current," "replace," "insert," and "after Gate 2" belongs to that immutable handoff and does not assert present application or lifecycle state. Current manual rows and their application history are authoritative only in the coverage files and validator/supervisor records.

1. File: `by-memory/-coverage-report.md`

Replace current UID00037T row:

`    - [UID:00037T][0x00507c90-0x00508f60.MapPanePacketDispatcher](by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md) 0x00507c90-0x00508f60 | virtual packet dispatcher | MapPanePacketDispatcher : reconstructable : 88% : strong : Exact MapPane inbound switch/attached-table envelope with opcode 0x15 direct bool-return route to source-ready UID0003TK and its resolved effect/map-state payload contract, plus opcode 0x1d direct bool-return route to source-ready UID0003TT; UID0003TT parses BE32 object id, full/partial ObjectStatusBlob, object-info byte, and counted ACP name, then performs exact living/item status refresh behavior while preserving unsafe trusted-buffer semantics. Preserved representative cases, every unrelated case group, raw-duplicate distinctions, compiler table tail, callee ownership, and the blank dispatcher formal remain pending their independent full case-group source audits.`

Replace current UID0001AW row:

`    - [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) 0x0050e4c0-0x00514920 | packet-handler split index | MapPanePacketHandlers : not_reconstructable : 86% : very-strong : Non-emitting MapPane packet-handler split/container with exact source-bearing children, including source-ready UID0003TI/UID0003TJ static-object creation and region reconciliation, source-ready UID0003TW shared status-overlay helper plus UID0003TX opcode-0x33 ObjectStatusBlob/name/ObjectInfo/status-refresh handling, source-ready UID0003TK opcode-0x15 map/effect-state parsing, source-ready UID0003TL opcode-0x06 map-info/tile-region parsing, source-ready UID0003TO opcode-0x29 trusted object/effect routing, source-ready UID0003TP opcode-0x2e world-map packet parsing/legacy coordinate overrides/WorldMapPane installation, source-ready UID0003TQ opcode-0x13 action-combat processing with exact UID0004SJ Bow setter, UID0004SK Damage constructor, UID0004SL UserPane movement tick, and UID0004SM UserPane group predicate support, retained file-local UID0004SN Pursuit message-dialog packet adapter with explicit zero-inbound-route history, source-ready UID0003TS opcode-0x19 SoundObject/zone-music/MIDI routing with exact framed records, zone/fallback/volume fields, typed SoundObjectPane construction/insertion/startup, malformed-packet trust, and compiler pool/EH exclusion, and source-ready UID0003TT opcode-0x1d object-status handling with exact full/partial ObjectStatusBlob, object-info byte, counted ACP name, living name/info/effect/sound/timer/local-appearance/sprite/overlay lifecycle, item refresh through UID0003HS, unsafe trusted-buffer behavior, and unconditional success; preserves every unrelated packet/helper disposition, live opcode-0x67 TimerPane flow, retained zero-route raw duplicates, exact padding, MapPane parsing ownership, compiler/runtime exclusions, and blank aggregate C++.`

Insert immediately after the current `0x00513305-0x00513310` padding row and before the next post-target item:

`        - [UID:0003TT][0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket](by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md) 0x00513310-0x0051367b | private packet method | MapPaneHandleObjectStatusPacket : reconstructable : 92% : very-strong : Exact source-ready opcode-0x1d MapPane handler over a trusted const-byte packet; reads BE32 object id, selects 43-byte full or five-byte partial ObjectStatusBlob from selector 0/1, consumes object-info type plus counted ACP name, resolves ObjectList state, preserves missing-object refresh and unsafe ObjectInfo pointer ordering, updates living composition/name/info/effects/sounds/timers/local appearance/sprite/overlay or high-id item state through UID0003HS, returns true on every path, and preserves exact range/hash/CFG/padding plus compiler range/security exclusions.`

Replace current UID0001D7 row:

`    - [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md) 0x00537b40-0x005380af | non-emitting class-method split index | ItemAndFlyingObjectPanes : not_reconstructable : 90% : very-strong : Exact address-sorted ItemObjectPane/FlyingObjectPane split index with constructor/destructor/status/bounds/render/flying children and confirmed internal alignment; UID0003HR emits the explicit empty ordinary ItemObjectPane destructor, source-ready UID0003HS emits the exact UpdateItemStatus body, scalar/vtable/pool lowering remains separate, and all exact source-bearing children retain direct class/file routes without aggregate duplicate source. Historical below-gate and LivingObjectPane-adjacency claims are superseded while all FlyingObjectPane evidence remains preserved.`

Insert as a child row immediately after the replacement UID0001D7 row and before the next aggregate successor:

`        - [UID:0003HS][0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate](by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md) 0x00537bc0-0x00537be9 | ItemObjectPane method | ItemObjectPaneUpdateItemStatus : reconstructable : 92% : very-strong : Exact source-ready void ItemObjectPane::UpdateItemStatus(const ObjectStatusBlob *); sole UID0003TT type-zero/high-item caller, copies appearance id to m_itemId and variant/palette to m_paletteFlags, then refreshes screen bounds through g_activeMapPane with no added guard; exact 41-byte range/hash and historical LivingObjectPane misownership correction preserved.`

2. File: `by-class/-coverage-report.md`

Replace UID00007Q row with this no-loss union:

`- [UID:00007Q][MapPane](by-class/MapPane.md) : reconstructable : 93% : very strong : Complete source-era MapPane declaration emitter at position 0 with exact 0x910 layout and current method union, preserving source-ready effect/HitBar/static-object UID0003TI/UID0003TJ work, opcode-0x15 UID0003TK map/effect-state parsing, opcode-0x06 UID0003TL map-info/tile-region parsing, opcode-0x29 UID0003TO object/effect routing, opcode-0x33 UID0003TX object-info handling with UID0003TW status-overlay helper and corrected by-value UID0002QN factory, source-ready opcode-0x13 UID0003TQ action-combat processing with exact UID0004SJ/UID0004SK/UID0004SL/UID0004SM owner-file dependencies, source-ready opcode-0x2e UID0003TP HandleObjectWorldMapCreationPacket trusted parsing with a local std::vector<bool> directed graph, exact whole-name legacy world-map coordinate overrides, WorldMapPane/Layer installation, cleanup and true return, source-ready opcode-0x19 UID0003TS HandleAnimationSoundPacket with SoundObject/zone-music/MIDI subtypes, exact framed records, corrected m_zoneMusicId/m_zoneMusicFallbackTrackIndex/m_zoneMusicVolumeScale fields, typed SoundObjectPane construction/insertion/startup, malformed-packet trust, and compiler pool/EH exclusion, and source-ready opcode-0x1d UID0003TT HandleObjectStatusPacket with exact full/partial ObjectStatusBlob, object-info/counted ACP name, living name/info/effect/sound/timer/local-appearance/sprite/overlay lifecycle and UID0003HS item update route; exact file-local UID0004SN Pursuit adapter remains MapPane.cpp-owned while creator/member implementation stays MessageDialogs-owned, and all unrelated methods/fields, class closure, size guard, children, unsafe trusted-buffer behavior, and compiler ABI exclusions remain preserved.`

Replace UID00006V row with this no-loss union:

`- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) : reconstructable : 92% : very-strong : Complete natural 0x12c ObjectPane-derived ground-item declaration with exact objectId/mapX/mapY/itemId/paletteFlags constructor fields and method declarations, m_itemId and m_paletteFlags storage, explicit empty ordinary destructor source, source-ready UpdateItemStatus copying ObjectStatusBlob appearance/variant to m_itemId/m_paletteFlags then refreshing active MapPane screen bounds, inherited ClearOutputRects and RenderFrame overrides, exact primary/EventHandler/TimerHandler vtable family, scalar-deleting/compiler separation, file-static 0x12c/8 pool definition, size guard, MapPane factory and UID0003TT update routes, item-image dispatch, exact child insertion/order and vtable child UID00034Y, destructor-island evidence, ItemObjectPane.cpp ownership, historical LivingObjectPane misownership rejection, and compiler vtable/scalar/pool exclusions.`

3. File: `by-file/-coverage-report.md`

Replace UID0000L3 row with this no-loss union:

`- [UID:0000L3][MapPane](by-file/MapPane.md) : reconstructable : 92% : very strong : NexusTK/map/MapPane.cpp source root with complete UID00007Q class-before-children route and the full current cross-agent effect/HitBar/static-object/map-state/map-info/object-move/object-info/action-combat union, including UID0003TI/UID0003TJ, UID0003TK, UID0003TL, UID0003TO, UID0003TQ with exact UID0004SJ-UID0004SM owner-file calls, UID0003TW/UID0003TX and corrected UID0002QN behavior; preserves source-ready UID0003TP opcode-0x2e trusted world-map parsing, exact whole-name legacy coordinate overrides, WorldMapPane/Layer installation, cleanup and true return, plus retained file-local UID0004SN Pursuit packet adapter with zero-route history and MessageDialogs creator/member boundary; preserves source-ready UID0003TS opcode-0x19 SoundObject/zone-music/MIDI routing with exact framed records, corrected zone/fallback/volume fields and replay contract, typed SoundObjectPane construction/insertion/startup, malformed-packet trust, and compiler pool/EH exclusion; and adds source-ready UID0003TT opcode-0x1d object-status handling in exact source order after UID0003TS with full/partial ObjectStatusBlob, object-info byte, counted ACP name, living name/info/effect/sound/timer/local-appearance/sprite/overlay lifecycle and ItemObjectPane UID0003HS dependency. All unrelated source families remain present; WorldMapPane, MessageDialogs, Layer, ScreenPane, PacketBuffer, MemoryMan, TimerMgr, SoundObjectPane, ObjectList, MidiPlayer, and SoundManager remain dependency/source owners; unsafe trusted-buffer behavior is retained; and compiler/runtime lowering plus by-file formal metadata remain excluded.`

Replace UID0000KG row with this no-loss union and current score:

`- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) : reconstructable : 91% : very-strong : NexusTK/map/ItemObjectPane.cpp source root with complete 0x12c ItemObjectPane declaration, exact objectId/mapX/mapY/itemId/paletteFlags constructor fields and route, explicit empty ordinary destructor, source-ready UID0003HS UpdateItemStatus copying ObjectStatusBlob appearance/variant to m_itemId/m_paletteFlags then refreshing active MapPane screen bounds, exact constructor/status/bounds/render child routes, inherited ClearOutputRects/RenderFrame source identities, class-generated vtable and scalar-wrapper coverage, separate item/flying static pools and exact pool-storage pages, preserved FlyingObjectPane companion union, ground-item MapPane factory and UID0003TT update routes, current ItemAndFlyingObjectPanes evidence, static/item/flying/attached vtable-data links, destructor-island support, historical LivingObjectPane-adjacency rejection, and compiler vtable/scalar/pool exclusions; no handwritten vptr/delete/pool-wrapper/RTTI duplication and no by-file reconstruction metadata are introduced.`

4. File: `by-type/by-enum/-coverage-report.md`

Replace UID0001SO row:

`- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) | observed inbound opcode index | MapServerPacketOpcode : reconstructable : 88% : very strong : MapPane inbound opcode index with exact opcode-0x15 direct bool dispatch to source-ready HandleEffectMapStatePacket and its map/dimension/flags/name/day-night/config payload, exact opcode-0x20 hour/minute validation and brightness-table mapping, corrected quadratic tint-not-duration semantics, SetDayNightFadeTarget route, retained UID0001AX raw duplicate evidence, and exact opcode-0x1d direct bool dispatch to source-ready HandleObjectStatusPacket with BE32 object id, full/partial ObjectStatusBlob, object-info byte, counted ACP name, living/item refresh behavior and unconditional success; blank formal enum remains correct because original constant spellings and unrelated case payloads remain unproven.`

5. Verify-only current manual rows with no replacement needed:

- by-class UID00009S ObjectStatusBlob
- by-file UID0000M6 ObjectStatusBlob
- by-class UID00007B LivingObjectPane
- by-file UID0000KU LivingObjectPane
- by-class UID00009R ObjectPane
- by-class UID00009P ObjectInfoObjectPane
- by-class UID00009Q ObjectList
- by-class/file Socket, SoundManager, TimerHandler, and TimerMgr
- by-memory UID0003TW, UID0003TX, UID0002CD, UID0003Z6, UID0001HU, UID0004S7
- by-struct rows because no layout metadata changes

Reason B005 must not apply these rows directly: manual coverage reports are supervisor-owned state. Validator-owned generated refresh does not update these manual rows.

## Follow-Up Actions

- B005 callback responsibilities are complete: C01-C42, Destinations 1-2, all eleven ordinary destinations, scoped validators, final waited generation, generated readback, report reconciliation, and lease closure are recorded.
- No B005 lifecycle follow-up remains. Gate review, manual-coverage application/validation, execution, revalidation/invalidation, movement, and archive state are external supervisor-owned facts whose current status is authoritative only in validator-owned headers/footers, registry, audit, and current files on disk.
- A-agent action: none required by this report.
- Future B-agent work outside scope: broader UID00037T dispatcher case reconstruction and complete original MapServerPacketOpcode spellings remain independent targets. They do not block UID0003TT.
- Archive-neutral lifecycle statement: B005 did not execute, move, archive, or delete this report. This statement records B005's actions only and makes no claim about later or current supervisor lifecycle actions.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: very strong for `92/94` on UID0003TT and UID0003HS.
- Range/owner/emitter confidence: very strong.
- C++ behavior confidence: very strong.
- Remaining uncertainty:
  - exact original method/local names;
  - original opcode enumerator spelling;
  - semantic names for samples `410/411`;
  - historical header/include organization.
- These uncertainties are explicitly represented by numeric constants, descriptive names, unchanged enum formal, and scores below `95`; none requires blank target/helper C++.

## Validator Results

- Every changed ordinary page was reread after acquiring its one-file lease, edited, scoped-validated while leased, and immediately released. All commands returned `exit 0`, `ok:1`.

| Command | Timestamp | Scoped page | Result | Warnings / side effects |
| --- | --- | --- | --- | --- |
| `000000013696` | `2026-07-16T09:35:17-04:00` | UID0003TT target | exit 0 / ok 1 | completion/confidence and blank-to-block registry update; projected stats; generated refresh deferred |
| `000000013699` | `2026-07-16T09:35:57-04:00` | UID0003HS helper | exit 0 / ok 1 | completion/confidence and blank-to-block registry update; projected stats; generated refresh deferred |
| `000000013702` | `2026-07-16T09:36:39-04:00` | UID0001D7 aggregate | exit 0 / ok 1 | nine pre-existing missing-reference warnings for unregistered FlyingObjectPane child UIDs; projected stats; generated refresh deferred |
| `000000013704` | `2026-07-16T09:37:24-04:00` | UID0001AW aggregate | exit 0 / ok 1 | thirty pre-existing missing-reference warnings, ten shown and twenty suppressed; projected stats; generated refresh deferred |
| `000000013707` | `2026-07-16T09:38:04-04:00` | UID00037T dispatcher | exit 0 / ok 1 | reference index addition for UID0003TT; projected stats; generated refresh deferred |
| `000000013708` | `2026-07-16T09:38:40-04:00` | UID0003TW helper | exit 0 / ok 1 | projected stats; generated refresh deferred |
| `000000013710` | `2026-07-16T09:39:04-04:00` | UID0001SO enum | exit 0 / ok 1 | two pre-existing UID0003TY missing-reference warnings; projected stats; generated refresh deferred |
| `000000013713` | `2026-07-16T09:39:36-04:00` | MapPane class | exit 0 / ok 1 | forty-five pre-existing missing-reference warnings; managed formal SHA remained `D9B6B1278074113FE6FD12E3458E905B361CE441BC698FF6E765221C6DEDFE7A`; generated refresh deferred |
| `000000013715` | `2026-07-16T09:40:39-04:00` | MapPane file | exit 0 / ok 1 | fifty-two pre-existing missing-reference warnings; projected stats; generated refresh deferred |
| `000000013718` | `2026-07-16T09:41:12-04:00` | ItemObjectPane class | exit 0 / ok 1 | managed formal SHA remained `7BB74F3D3CF2CD8F938B769C0CD709F0D84456427DC112284F1A13703081710B`; generated refresh deferred |
| `000000013719` | `2026-07-16T09:41:52-04:00` | ItemObjectPane file | exit 0 / ok 1 | two pre-existing UID0003HV missing-reference warnings; reference index addition; generated refresh deferred |
| `000000013720` | `2026-07-16T09:42:15-04:00` | final waited UID0003TT refresh | exit 0 / ok 1 | validator-owned registry rebuild, projected stats, generated metadata/report/C++ refresh, and pre-existing global autogen warnings; `generated_refresh:completed` |

- Validator-owned side effects included `project-level/-auto-completion-stats.md`, generated coverage/C++ metadata, `auto-generated/-ag-class-coverage.md`, and validator registry rebuilds. B005 did not edit those files manually.
- No target-specific validator error remains. Pre-existing missing-reference and global autogen marker warnings are recorded above and did not reduce any scoped command's `ok:1` result.
- B005's evidence-time generated callback proof is command `000000013720`; these hashes are not asserted as the latest global project epoch after unrelated validators:
  - `MapPane.cpp` SHA256 `70307BF94F86B79E0E6D594C873555E0E19A91A952AD6BAB934A213978B67527`, one UID0003TT definition, zero target markers, one class declaration, one UID0003TW definition, zero forbidden scaffolding hits.
  - `ItemObjectPane.cpp` SHA256 `393FB0D6F5AF28B73BC2EE85C460D00E0AD842A28A9DC91B6EE5FE9CEBE4C549`, one UID0003HS definition, zero helper markers, one class declaration, and correct destructor-then-update source order.
- Validator command rows and generated hashes in this section are immutable B005 callback evidence. They do not assert current execution, revalidation/invalidation, archive, or supervisor coverage-application state.

## Changed Files

- Updated callback artifact:
  - `tools/leaser/Agents/Agent-B005/research/0003TT-MapPaneHandleObjectStatusPacket-source-quality.md`
- Modified ordinary by-* files and final SHA256:
  - `by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md` - `3197AC75D0A8B89673FA6C4E93705FC80D309160A35C7FB635D1A513E53B9870`
  - `by-memory/0x00537bc0-0x00537be9.ItemObjectPaneRecordStateUpdate.md` - `7166198D63C8C7212B19EC9EF41056CFC31B99BDF674C09E32997BD69CB4882F`
  - `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md` - `751FA2F965564A8BC2464F80297854EF740E21E925E8DCA09E1F450E1F9F622F`
  - `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` - `3C8BE666C9193995413503E931E36FCFE5B657E61BCB8817E2401C1165C72804`
  - `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md` - `04C2B85BE8B5BA40A2B76FB399A3AA9795F3FEFB4E65D06247375A800E124ED2`
  - `by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md` - `3E438234B3BE63B45E5DBC1B56A529F631056B2440261169903B150F908D5AFE`
  - `by-type/by-enum/MapServerPacketOpcode.md` - `C77CC92D330AD41F66DB5F32384155549D7EE099E9E064331AB106EDD234A4B4`
  - `by-class/MapPane.md` - `A27987F5C31E7C8EE79AB0D397B66EE9C2FAB2BD59F766E0D841D19F8284CCF0`
  - `by-file/MapPane.md` - `97A40EB495BEC5ABA1B0402EDD6C15A5CA369721C5725D47EB1092C50ED48F9B`
  - `by-class/ItemObjectPane.md` - `16D9889298ECD983726F2EBB434A561BCD977A57B4A6AEC658ECC3DA3210CB5D`
  - `by-file/ItemObjectPane.md` - `BCCD9E18A738B7CEA7F041BF4DA24B9C0DB1456DCEE59BFD3861E1575976EEC5`
- Read-only validator-generated evidence-time callback outputs from command `000000013720` (not asserted as the latest global project epoch):
  - `auto-generated/NexusTK/map/MapPane.cpp` - `70307BF94F86B79E0E6D594C873555E0E19A91A952AD6BAB934A213978B67527`
  - `auto-generated/NexusTK/map/ItemObjectPane.cpp` - `393FB0D6F5AF28B73BC2EE85C460D00E0AD842A28A9DC91B6EE5FE9CEBE4C549`
  - `auto-generated/NexusTK/map/LivingObjectPane.cpp` - `B22C284AB966EE68D0D4A38144894A208DAA01B7B81399EA54835D0A0DF241BE`
  - `auto-generated/NexusTK/map/ObjectStatusBlob.cpp` - `41067F18DCFBA8CDE0832AA3EB7E1499FBC1DD00CCBD4F9268D2C57656DB61E3`
- Manual coverage hashes listed above are evidence-time callback baselines; no manual coverage row was edited by B005. Current coverage hashes and application state are authoritative only in the files and supervisor/validator records.
- B005-performed rename/move/archive actions: none. Later or current supervisor movement/archive state is authoritative only in validator-owned lifecycle history.
- IDA mutation: none.
- B005-performed report execution/lifecycle commands: none. Supervisor execution, revalidation/invalidation, and lifecycle state are not asserted here.
- Lease closure: every ordinary lease was released immediately after its validator; final shared lease report contains zero B005 leases.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact SHA `568A73F008D9915600950D3E76DB23E22745D1638562906B252AE2AEA365A29A`.
- [x] Re-read UID0003TT after acquiring its callback lease.
- [x] Applied target metadata `92/94` with all other metadata preserved.
- [x] Applied exact target Item Summary.
- [x] Applied Destination 1 byte-for-byte.
- [x] Incorporated complete target range/hash/instruction/CFG/caller evidence.
- [x] Incorporated exact packet selector, cursor, object-info, and counted ACP name layout.
- [x] Incorporated exact list/null/miss/type/living/item control flow.
- [x] Incorporated exact composition/name/ObjectInfo/effect/sound/timer/local-copy/sprite/overlay order.
- [x] Preserved unsafe/no-check behavior and all rejected alternatives.
- [x] Re-read UID0003HS after acquiring its callback lease.
- [x] Applied UID0003HS metadata `92/94` with all other metadata preserved.
- [x] Applied exact UID0003HS Item Summary.
- [x] Applied Destination 2 byte-for-byte.
- [x] Preserved one-caller/type-zero/high-item gate and historical misownership correction.
- [x] Re-read and synchronized UID0001D7 without losing FlyingObjectPane/destructor/pool/vtable content; validator `13702`.
- [x] Re-read and synchronized UID0001AW without losing any current packet child; validator `13704`.
- [x] Re-read and synchronized UID00037T without changing unrelated case groups or blank formal; validator `13707`.
- [x] Re-read and historicalized stale current-facing blank prose in UID0003TW without changing its formal; validator `13708`.
- [x] Re-read and synchronized MapServerPacketOpcode while preserving blank enum formal and every unrelated opcode; validator `13710`.
- [x] Re-read and synchronized MapPane class; managed formal SHA remained `D9B6B127...DFE7A`; validator `13713`.
- [x] Re-read and synchronized MapPane file without by-file formal metadata; validator `13715`.
- [x] Re-read and synchronized ItemObjectPane class; managed formal SHA remained `7BB74F3D...710B`; validator `13718`.
- [x] Re-read and synchronized ItemObjectPane file without by-file formal metadata; validator `13719`.
- [x] Verified UID0003TX, UID00009S, UID0000M6, UID0004LK/LL/LM, ObjectPane, ObjectList, LivingObjectPane, UserPane, ObjectInfoObjectPane, Socket, TimerHandler, TimerMgr, SoundManager, globals, and ignored padding same-or-greater detail; no contradiction required an edit.
- [x] Preserved exact predecessor and successor padding; created no child and changed no nesting.
- [x] Preserved owner/emitter/reconstructable/position/source routes outside the two accepted score changes.
- [x] Preserved all history, negative evidence, rejected alternatives, lexical confidence caps, and source/compiler boundaries.
- [x] Confirmed third-party import is not applicable.
- [x] Retained exact supervisor-owned manual coverage text and never edited manual coverage.
- [x] Acquired only one ordinary-file lease at a time during callback.
- [x] Ran one scoped file validator per changed ordinary by-* page while leased.
- [x] Released each lease immediately after its scoped validator.
- [x] Ran final authorized `--wait-generated` refresh command `13720`.
- [x] Verified generated MapPane.cpp has one target definition, no UID0003TT marker, unchanged class shell/one UID0003TW definition, and zero forbidden compiler/decompiler scaffolding hits.
- [x] Verified generated ItemObjectPane.cpp has one UID0003HS definition, no UID0003HS marker, unchanged class shell, and destructor-then-update source order.
- [x] Recorded validator command IDs, timestamps, exits, ok counts, warnings, side effects, generated headers/hashes/counts, changed files, and lease closure.
- [x] Updated C01-C42 to legal terminal callback states with destination-specific proof.
- [x] Updated this checklist only after each item was verified true.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support facts incorporated at report-level detail.
- [x] Both managed destinations applied exactly.
- [x] Every C01-C42 claim is applied, already present, or excluded with concrete reason.
- [x] No accepted claim is blocked.
- [x] Scoped validators completed and recorded.
- [x] Final waited generated refresh completed and read back.
- [x] Exact manual supervisor-owned text retained as immutable callback handoff evidence and not applied by B005; no claim is made here about later/current supervisor application.
- [x] All ordinary and manual hashes were reconciled at callback time; command `13720` generated hashes are retained as evidence-time callback proof rather than asserted as the latest global project epoch.
- [x] No B005 lease remains.
- [x] Report lifecycle wording treats the READY marker as historical callback-return evidence and defers current execution, revalidation/invalidation, archive, and coverage-application state to validator/supervisor-owned sources.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000013769","destination_path":"executed-b-agent-research/B005/0003TT-MapPaneHandleObjectStatusPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003TT-MapPaneHandleObjectStatusPacket-source-quality.md","timestamp":"2026-07-16T10:16:43-04:00","uid":"0003TT"} -->
<!-- {"agent":"B005","command_id":"000000013770","destination_path":"tools/leaser/Agents/Agent-B005/research/0003TT-MapPaneHandleObjectStatusPacket-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B005/0003TT-MapPaneHandleObjectStatusPacket-source-quality.md","timestamp":"2026-07-16T10:17:36-04:00","uid":"0003TT"} -->
<!-- {"agent":"B005","command_id":"000000013771","destination_path":"executed-b-agent-research/B005/0003TT-MapPaneHandleObjectStatusPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003TT-MapPaneHandleObjectStatusPacket-source-quality.md","timestamp":"2026-07-16T10:23:21-04:00","uid":"0003TT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
