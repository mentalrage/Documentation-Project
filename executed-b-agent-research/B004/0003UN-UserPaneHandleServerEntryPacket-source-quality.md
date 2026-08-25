** TARGET-REPORT-UID:0003UN **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0003UN UserPaneHandleServerEntryPacket Source-Quality Report

## Finalized Report / Current Recommendation

- [UID:0003UN] is now one source-authored `UserPane` member over exact modeled range `[0x005aac80,0x005aafe3)` at `92/94`, with retained `CANONICAL_OWNER:0000FQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FQ`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Destination 1 is applied exactly as `bool UserPane::HandleServerEntryPacket(const unsigned char *packet)`. The current emitted body preserves duplicated EPF/legacy branches, two branch-local `0x400` buffers, SelfLook/NewSystem SpelledPane refresh, packet-sender re-enable, transfer-overlay repaint/deferred deletion, object/facing/status state, MapPane bounds refresh, and block/listen replay; the rejected main-window/loading/receive-reset/CollectionData/server-address body remains historical evidence only.
- [UID:0003QH] retained its UID through the validator-aware rename to `SelfLookPaneRefreshSpelledPane`; exact child `[0x00588d50,0x00588d6e)` was serially registered as [UID:0004R2] `NewSystemMessagePaneRefreshSpelledPane`. Both exact wrappers emit `m_spelledPane->RefreshScrollState()` once.
- The exact seven-byte prefix and thirteen-byte suffix `0xcc` spans are recorded in [UID:0000VN] `by-memory/-ignored.md`; all target, wrapper, class/file/index, dispatcher, and direct reverse-link support changes are applied at report-level detail.
- Supervisor ordering assigned B004 the shared UserPane lane first. B003/B001/B002 were held behind B004, so their accepted reports were reread as preservation input but their target work was not pre-implemented here; their later callbacks must rebase this completed UID0003UN union. B005's terminal callback was reread from its supervisor-executed artifact.
- Commands `000000012860` through `000000012896` listed under Validator Results validate every changed ordinary page and the final generated state. All B004 leases were released. B004 performed no report execution, lifecycle, count/probe, move, or archive command and did not manually edit coverage or generated output.

## Supporting Research

The research pass used concrete searches, not a generic prior-report assertion. Terms included `UID0003UN`, `0003UN`, `0x005aac80`, `0x005aafe3`, `UserPaneHandleServerEntryPacket`, `HandleServerEntryPacket`, `sub_5AAC80`, `UID0001KM`, `UID0003VB`, `RefreshWorldMapPane`, `RefreshSpelledPane`, `SelfLookPane`, `NewSystemMessagePane`, `TransferServerDialogPane`, `blockListenNames`, `PacketBufferAppendAnsiString8`, and UserPane/server-entry/source-family terms.

- `tools/leaser/Agents/**`: 117 Markdown files were enumerated during the original evidence pass. The broad exact-term search produced 18 matches. The bounded coordination repair then opened every current UserPane workstream goal and every report artifact that existed:
  - B005 UID0003UL: the supervisor-executed artifact is `executed-b-agent-research/B005/0003UL-UserPaneParsePlayerSettingsPacket-source-quality.md`, callback body SHA256 `270F5C30DD094FB985C6848DF813DBC47B682CF0F31EEE9A726EB98C6220021F` when reread. Its terminal ordinary state supplied the exact `m_playerSettingsState[8]` versus `m_movementState[5]` distinction and ordered config stores preserved by B004.
  - B002 UID0003UW: `tools/leaser/Agents/Agent-B002/research/0003UW-UserPaneParseLinkedObjectsPacket-source-quality.md`, Gate-1-accepted SHA256 `FA88588B48F3C0CAE7753E8B4171E64E083E5370BDBE0D8EBE9747CE0EFC1132`. Its accepted group-list work was reread before B004's shared edits. Under the supervisor ordering override B002 is callback-last and must preserve this UID0003UN union; B004 did not edit B002-owned target/helper pages.
  - B003 UID0003V9: `tools/leaser/Agents/Agent-B003/research/0003V9-UserPaneHandleKeyEvent-source-quality.md`, Gate-1-accepted SHA256 `27F8A66148AD58196826C6CEE73257F0BA82C82E0CCAFDC9DD198CFB89ACF351`, working callback SHA256 `4360B72748FCEBC77A53670A853F36DDB6B8DA72EC4DE611E26A895C6598896D` when reread. Its accepted event/helper/layout/linkage/compiler-exclusion facts were preservation input. The supervisor held B003 behind B004's shared lane; B004 did not edit B003-owned target/helper pages or install its later class formal.
  - B001 current staged work was likewise held behind B004 by the supervisor. Current B001 signed-direction/table/event-20 facts already on disk were preserved, and no B001-owned target page was edited.
  - B004 UID0003UN: this same report now records the completed callback; no second target or report artifact was created.
  - No separate active direct UID0003UN report was found. Goal/audit/notes matches were administrative and were not used as binary proof.
- `executed-b-agent-research/**`: 2,216 Markdown files were enumerated. Relevant matches were opened and classified:
  - `B001/0003U8-UserPaneStartDirectionalAnimation-source-quality.md`, current executed artifact SHA256 `4937108A56AF541AFB4FCFF385265D02571B64ADC40FF715996E26CB73F1085D`: accepted `StartDirectionalAnimation(char direction)`, signed-duration/table, event-20, and branch-order facts already present in the shared UserPane baseline.
  - `B001/0002QY-MotionAnimationTimerTick-empty-emitter-source-quality.md`, SHA256 `08B58B97B76635467AC02E1FB182BCDF56C01FE1B7AB754941AA3233A408782A`: direct historical UID0003UN incorporation lead. It established UserPane ownership and inserted the then-current body, but that destination body was not a target-specific reanalysis and is superseded by the live facts in this report.
  - `B001/0001H7-selflookpane-source-split-audit.md`, SHA256 `626E82F1BA42B23E804070197ADF6050CCFC1FD59B67F863E3F14B2D1B697470`: historical SelfLookPane split/name lead; the `RefreshWorldMapPane` name remained provisional.
  - `B002/0003UO-LivingObjectPaneRawMovementCorrectionPacketHelper-source-quality.md`, SHA256 `68BA45CB3C0DEB45F9509C6B35E14D99A192AAC37852EF6E0692CF8C88119DB3`: successor/dispatcher-table boundary corroboration, not a substitute for UID0003UN.
  - `B003/0003QZ-SelfLookPane2OnDraw-source-quality.md`, SHA256 `69DA958CD0DB4651F30859E0662E21B51493BDF2E09FDB396ECC5494A532FC4E`: accepted source abstraction proof. Its lines 110, 221, 511, and 521 tie FrameHandler remove-then-schedule behavior on a SpelledPane handler view to human source `SpelledPane::RefreshScrollState()`.
  - `B004/0003UM-UserPaneParseInventorySlotUpdatePacket-source-quality.md`, SHA256 `3ED435EE6680006F2ED713E568E9AE4630A1E18F07E836A3BE8C792E117C182A`: completed predecessor UserPane union. The user states UID0003UM is supervisor-executed and archived; the current disk fields/opcode inventory are protected baseline facts.
  - `B011/0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md`, SHA256 `28BBBC98023C5EAB25B766D356A2DB0DFFF515DEACBD5C2F6774F75BB1A1CC44`: class/file split and constructor/vtable lead. Its `RefreshWorldMapPane` wording is superseded by the direct field and FrameHandler evidence.
  - `B011/00015W-GeneralPurposePanelChildAccessors-source-quality.md`, SHA256 `F1FA20C0D40A5BCA8DB7CF0E33D8DA185C429B571A3A176D922E171665E6CD52`: accessor contract lead for child index zero.
- `tools/leaser/Agents/Older-Research/**`: three Markdown files, zero exact-term matches.
- `tools/leaser/Agents/SpecialReports/**`: five Markdown files, zero exact-term matches.
- Actual project archive root `project-documentation/archived/**`: zero Markdown files and zero matches. No missing `tools/leaser/Agents/archived` root was claimed.

Prior reports were treated as leads. Every target behavior, boundary, route, helper identity, branch difference, and rejected abstraction below was revalidated against current ordinary docs and live IDA MCP.

## Target

- UID: `0003UN`
- Current path: `by-memory/0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md`
- Assigned report artifact: `tools/leaser/Agents/Agent-B004/research/0003UN-UserPaneHandleServerEntryPacket-source-quality.md`
- Exact modeled range: `[0x005aac80,0x005aafe3)`, `0x363` / 867 bytes.
- Current IDA identity: `sub_5AAC80`.
- Best source identity: `bool UserPane::HandleServerEntryPacket(const unsigned char *packet)`.
- Current route: owner [UID:0000FQ] `UserPane`; emitter [UID:0000P1] `UserPane`; generated route `NexusTK/ui/panels/UserPane.cpp`.

## Current Target State

- Current metadata is `92/94`, owner/emitter `0000FQ`, reconstructable true, blank position, `Nested:0`. Current target SHA256 is `ABE9BBB346E300C44EDAFADC851B2807BE3212EE0969EF7F8B56E87E2A0FD326`, 16,149 bytes.
- Destination 1 is the current managed body and equals the report block after newline normalization. The former contradictory source-ready/unresolved prose and invented body are retained only as historical/rejected evidence.
- Final waited generated `auto-generated/NexusTK/ui/panels/UserPane.cpp` is validator command `000000012896`, refreshed `2026-07-15T05:38:06-04:00`, SHA256 `441537C0A55B55DDEAA7BBE4996507D43F802FA7AFE1C9A7569EBDEC85779226`, 89,852 bytes, 2,636 lines. The UID0003UN segment has one marker/definition, zero empty markers, two `unsigned char request[0x400]` declarations, two sender-enable calls, two deferred-delete calls, two block/listen references, one terminal `return true`, and zero rejected target spellings.
- Current shared destinations after B004's first-lane rebase are `by-class/UserPane.md` SHA256 `E4AA6D4FFA4A0BC257CA671E8EDFEF06B8D36BD41465A6DB2FD75C14A6B05291` (verify-only), `by-file/UserPane.md` SHA256 `8DB6D7C19E62307B98644404FFFAED610B94B96F875EB5A3DFF653632DEA2E4D`, UID0001KM SHA256 `1E53B83F744B364D5769316D0FAEC19B558A9410E37D3BB4327AF48AD5F7396A`, and UID0003VB SHA256 `CBA235435FF71EF9DA524C2963D96AC517B184239B67AB74E97BCB9A8EC113D0`.
- `by-class/UserPane.md` contains exactly one `bool HandleServerEntryPacket(const unsigned char *packet);`, one `[[CHILDREN]]`, and the complete size-guarded class union. B004 did not edit it. B004's three shared edits are additive UID0003UN prose/index synchronization and preserve the complete current B001/B004/B005 union; supervisor-held B003/B001/B002 callbacks must rebase these current bytes later.
- UID0003QH and UID0004R2 are each unique, the old UID0003QH path is absent, no temporary UID token remains, all four managed destination blocks equal their current ordinary destinations, and no B004 lease remains.

## Executive Recommendation

Implemented disposition: Destination 1 replaced the target's invented body; Destinations 2-3 renamed and implemented the exact SelfLookPane wrapper; Destination 4 registered and implemented the exact NewSystemMessagePane wrapper; the bounded source-family pages and both alignment gaps are synchronized. No target split is warranted. The target is `92/94`: all binary behavior and source route are closed, while exact original lexical spellings for the block/listen vector API and two refresh wrappers remain inferred but strongly triangulated.

## Supervisor Active Recheck

- Historical pre-callback state: at `2026-07-15T04:36:11-04:00`, B005 was active, B002 was report-only, and B003 was repairing Gate 1. Those facts explain the accepted staged guard but are not current callback status.
- Callback-time recheck found B005 Gate 2 complete and later supervisor-executed; B002 and B003 had exact Gate-1-accepted artifacts. Their reports, current goals, shared destinations, and global lease report were reread. No shared ordinary lease was active before B004's shared phase.
- The supervisor then explicitly assigned B004 the shared UserPane lane first and held B003/B001/B002 behind it. That current ordering override superseded the earlier reciprocal wait while retaining the same no-loss rule: B004 applied only UID0003UN additions, did not pre-implement downstream targets, and left their owned pages untouched. B003/B001/B002 must rebase this current union when their held callbacks resume.
- `by-class/UserPane.md` was reread and remained verify-only because its exact declaration was already present once. Each writable shared page was leased alone, reread after lease acquisition, changed additively, scoped-validated, and immediately released: UID0000P1 command `12893`, UID0001KM command `12894`, UID0003VB command `12895`.
- Final waited command `12896` refreshed all three generated routes. The four shared destinations and generated outputs were reread afterward; they retain current B001/B004/B005 facts, B004's exact UID0003UN additions, and no duplicate declaration/body. No B004 lease remains.

## Inference Research Guidance Check

- Human-source names are selected only after receiver/field/caller triangulation. Raw `sub_*` labels are retained as IDA provenance, not emitted names.
- Decompiler branch shape is not blindly normalized. The two 0x400-byte branch-local buffers, duplicated conversion cleanup, and duplicated block/listen loops support two source branches rather than a common synthesized tail.
- Compiler artifacts are excluded: SEH state, security-cookie setup/check, temporary StringBase cleanup state, `std::_Narrow_char_traits::to_char_type` lowering, and alignment bytes do not appear as handwritten source.
- No score is raised merely because a body exists. The increase follows exact target hash/range, one caller, opcode route, complete branch/callee mapping, exact offsets, source module, helper wrappers, negative evidence, and an implementation-ready formal body.
- Prior names `RefreshWorldMapPane`, `serverMode`, and `ServerAddressList` were treated as hypotheses and rejected where the receiver/dataflow contradicted them.

## Heuristic / Inference Reanalysis And Validation

| Question / prior hypothesis | Reanalysis | Decision |
| --- | --- | --- |
| Is this only vaguely source-ready? | Live target decompile, CFG, xrefs, bytes, dispatcher, globals, helper docs, and generated body were compared instruction by instruction. | Source-ready; the pre-callback body was rejected and Destination 1 is now current. |
| UserPane or LivingObjectPane owner? | Caller adjusts the dispatcher receiver by `-0xa0`; callee writes UserPane-only `m_mapPane` at `+0x1340f8` and reads Config block/listen state. Current class/file route already declares the method. | UserPane owner/emitter `0000FQ`; LivingObjectPane is inherited layout context only. |
| One member or multiple source children? | One modeled `0x363` function, one prologue/epilogue, one caller, one `retn 4`, one boolean result, and branch-local EH state. | One member; do not split branch tails, compiler cleanup, or loops. |
| `RefreshWorldMapPane`? | Both wrappers load the embedded SpelledPane pointer, address its FrameHandler view at `+0x174`, remove then schedule. Accepted SelfLookPane2 source names this abstraction `RefreshScrollState()`. | Rename both wrappers `RefreshSpelledPane`. |
| UI close/reset/delete lifecycle? | Live callee set contains no MainWindow, LoginDialog, LoadingPane, receive-reset, direct delete, or singleton-clear helper. | Reject the current invented lifecycle. |
| Transfer overlay behavior? | Exact calls are `ResetOpacityAndRepaint` and BlackHole `QueuePaneForDeferredDeletion` on the same nonnull pointer. | Preserve repaint/reset plus deferred queue; do not clear or directly delete the global. |
| Packet byte 9 meaning? | Value is bounded `<=4` then passed to active or old UserStatusPane `SetStatusIconId`. | Name `statusIconId`; reject server mode. |
| Map call? | Exact callee `0x00506980` is `MapPane::UpdateObjectPaneScreenBounds(ObjectPane *)`. | Use `m_mapPane->UpdateObjectPaneScreenBounds(this)`; reject `InvalidateObject`. |
| Server list or block/listen list? | Config range is exact `+0x2918fc/+0x291900`; sibling add/delete paths name it `m_blockListenNames`; emitted packet is `0x0d,0x02,len,name`. | Replay block/listen add requests; reject server-address model. |
| Vector count clamp? | Binary executes loop only when size is strictly less than `0xff`; it neither truncates nor clamps. | Preserve exact `size() < 0xff` guard. |
| Empty string behavior? | `0x005845f0` checks pointer-backed StringBase length and empty entries are skipped. | Use `!it->empty()`; do not use an `active` flag. |
| Buffer declaration? | Each branch reserves an independent `0x400` packet buffer; no zero-fill occurs. | `unsigned char request[0x400];`, uninitialized except appended bytes. |
| String conversion? | `0x005825a0` converts a pointer-backed UTF-16 StringBase to a narrow StringBase, then `c_str`, ANSI length-prefix append, temporary release. | Use branch-local narrow StringBase construction and `PacketBufferAppendAnsiString8`. |
| Container source API? | Direct storage is a 4-byte pointer-backed string-handle vector. Accepted BlockListen source already uses `SimpleUStringVector::iterator`, `begin/end/size`; current class shell omits those inline facade declarations. | Use the established human container API in the target; record broader class-shell incompleteness as an existing support caveat, not raw-offset target code. |
| Should common code be factored? | Binary duplicates all state, iteration, two 0x400-byte buffers, conversion temporaries, and cleanup paths between EPF/legacy branches. | Preserve duplicated source branches. A new shared helper would be unsupported compression. |
| Return type? | Every normal path sets `AL=1`; caller consumes the boolean route. | `bool`, always `true`. |

## Evidence Standards Used

- **Direct fact:** current MCP bytes, modeled function/range, decompile, basic blocks, xrefs, callsites, fields, globals, branch predicates, packet constants, and current file contents/hashes.
- **Triangulated fact:** semantic helper identity supported by exact callee body plus accepted class/file/global docs and caller behavior.
- **High-probability inference:** original lexical names and high-level container syntax that reproduce direct dataflow without raw offsets.
- **Historical lead:** older reports and recovered names used only to identify checks; a lead is rejected when live evidence conflicts.
- **Negative evidence:** absence claims are bounded to exact current callee/xref/byte/document searches and paired with positive controls.
- **Lifecycle boundary:** report validation, execution, counting, path movement, and archive state are external supervisor/validator-owned facts and are not asserted by this artifact.

## Evidence Checked

### Live MCP

- Fresh `idb_list` returned one active adopted NexusTK database, `01f84d61`, worker PID `18448`.
- Fresh `server_health(database=01f84d61)` returned `status=ok`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, cache size 2,067.
- Fresh bounded `lookup_funcs` resolved target `0x005aac80` as `sub_5AAC80`, size `0x363`; wrappers `0x005671c0` and `0x00588d50` as exact `0x1e` functions. `0x005aaff0` is not an IDA function, consistent with UID0003UO retained raw/no-direct-route status.
- Fresh bounded `get_bytes` returned real target prologue bytes and exact boundary/wrapper bytes. Corrected call used the current `regions[{addr,size}]` schema. Two earlier client-side schema mistakes returned parameter errors and supplied no evidence; the listener/worker did not disappear and all corrected real calls succeeded.
- `decompile`: target, `0x005825a0`, `0x005845f0`, both refresh wrappers, their FrameHandler callees, both GeneralPurposePanel accessors, and relevant constructors.
- `basic_blocks`: 26 total blocks including compiler EH funclets; 21 main-body blocks; cyclomatic complexity 12.
- `xrefs_to`: target sole direct call, wrapper callsites, globals/storage, and helper routes.
- Bounded byte/hash pass: full target and the four alignment/wrapper spans.

### Current documentation and generated evidence

- Target, UID0001KM, UID0003VB, UID0000FQ, UID0000P1, UID0003QH, SelfLookPane class/file, NewSystemMessagePane class, SystemMessagePanes file/aggregate, SpelledPane/FrameHandler support, TransferServerDialogPane/BlackHole/MapPane/UserStatusPane/Socket/Config/PacketBuffer/StringBase/SimpleUStringVector support, exact globals/storage, adjacent UID0003UM/UID0003UO, and [UID:0000VN] `by-memory/-ignored.md`.
- Current generated UserPane output and target marker/body counts were read-only checks.
- Manual `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md` rows were read without modification.
- Current B001/B004 on-disk facts, B005's supervisor-executed UID0003UL artifact, B002's Gate-1-accepted UID0003UW report, B003's Gate-1-accepted UID0003V9 report/current callback revision, all shared destination hashes, final generated outputs, and all prior-report paths listed in Supporting Research were opened rather than inferred from filenames. The supervisor's B004-first lane override was applied without importing downstream target implementations.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C3UN-001 | Target is exact modeled `[0x005aac80,0x005aafe3)`, 867 bytes, SHA256 `4B658CF3F99E9145A8AEB8B87F5F291081B8E092431DB3D906BA0F364924807B`. | very strong | lookup/bytes/hash | UID0003UN boundary/evidence | incorporate | applied |
| C3UN-002 | Main body has 21 blocks; total graph has 26 including EH funclets; complexity 12. | very strong | basic_blocks/decompile | UID0003UN CFG | incorporate | applied |
| C3UN-003 | Sole direct caller is dispatcher callsite `0x005a797f`. | very strong | xrefs_to/caller disassembly | UID0003UN; UID0003VB | incorporate | applied |
| C3UN-004 | Dispatcher selector is live server opcode `0x05`. | very strong | switch route/callsite | UID0003UN; UID0003VB; UID0001KM | incorporate | applied |
| C3UN-005 | ABI is `__thiscall`, one packet pointer, `retn 4`, boolean true on every path. | very strong | prologue/epilogue/caller | UID0003UN | incorporate | applied |
| C3UN-006 | Caller receiver adjustment and UserPane-only state prove UserPane ownership. | very strong | `lea ecx,[ebx-0xa0]`; `+0x1340f8` | UID0003UN owner/source | already-present | already-present |
| C3UN-007 | EPF branch is selected only by `g_useEpfAssets == 1`. | very strong | branch bytes/decompile | UID0003UN formal/evidence | incorporate | applied |
| C3UN-008 | Both branches refresh GeneralPurposePanel child-zero SelfLookPane. | very strong | calls `4B85F0 -> 5671C0` twice | UID0003UN; UID0003QH | incorporate | applied |
| C3UN-009 | EPF branch alone refreshes GeneralPurposePanel2 child-zero NewSystemMessagePane. | very strong | calls `4B8950 -> 588D50` | UID0003UN; new child | incorporate | applied |
| C3UN-010 | UID0003QH is `SelfLookPane::RefreshSpelledPane`, not world-map refresh. | strong | receiver `+0xfc`, FrameHandler `+0x174`, accepted abstraction | UID0003QH path/title/formal | incorporate | applied |
| C3UN-011 | Exact `[0x00588d50,0x00588d6e)` is `NewSystemMessagePane::RefreshSpelledPane`. | strong | receiver `+0xf8`, identical wrapper bytes/behavior | new exact child | incorporate | applied |
| C3UN-012 | Both wrappers lower to `m_spelledPane->RefreshScrollState()`. | strong | remove/schedule callees plus UID0003QZ accepted source | wrapper formals/classes/files | incorporate | applied |
| C3UN-013 | Both branches call `g_packetSender->SetSendDisabled(false)`. | very strong | `0x00574ce0` calls | UID0003UN | incorporate | applied |
| C3UN-014 | Nonnull transfer overlay receives `ResetOpacityAndRepaint()`. | very strong | global test and UID0004MX call | UID0003UN | incorporate | applied |
| C3UN-015 | Same transfer pointer is queued through BlackHole for deferred deletion; no clear/direct delete. | very strong | `0x00469180`, global `0x0067a74c` | UID0003UN | incorporate | applied |
| C3UN-016 | `packet+1` is big-endian object id written to `m_objectId +0xfc`. | very strong | `5754C0`, store offset | UID0003UN | incorporate | applied |
| C3UN-017 | `packet[8]` is facing written to `m_facing +0x1c5`. | very strong | byte load/store | UID0003UN | incorporate | applied |
| C3UN-018 | `packet[9]` is status icon id; values 0..4 are forwarded. | very strong | bound and setter calls | UID0003UN | incorporate | applied |
| C3UN-019 | EPF uses active UserStatusPane; legacy uses OldUserStatusPane. | very strong | distinct globals/callees | UID0003UN | incorporate | applied |
| C3UN-020 | Map effect is `UpdateObjectPaneScreenBounds(this)`, not invalidation. | very strong | `0x00506980` accepted identity | UID0003UN | incorporate | applied |
| C3UN-021 | Config vector at `+0x2918fc/+0x291900` is `m_blockListenNames`. | strong | sibling block/listen docs/layout | UID0003UN; UserPane file | incorporate | applied |
| C3UN-022 | Replay runs only when vector size is strictly less than 255. | very strong | pointer difference/compare | UID0003UN | incorporate | applied |
| C3UN-023 | Every nonempty vector entry is replayed; empty entries are skipped. | very strong | loop and `StringBase::empty` | UID0003UN | incorporate | applied |
| C3UN-024 | Each branch owns a separate uninitialized 0x400-byte request buffer and cursor. | very strong | `sub esp,0x814`, local layout | UID0003UN | incorporate | applied |
| C3UN-025 | Request starts with opcode `0x0d`, subcommand `0x02`. | very strong | two value-first append calls | UID0003UN | incorporate | applied |
| C3UN-026 | Each UTF-16 name converts to branch-local narrow StringBase and appends as ANSI length-8 text. | very strong | `5825A0/584540/5757D0/582B30` | UID0003UN | incorporate | applied |
| C3UN-027 | Send uses current cursor narrowed to the Socket short-length contract; no clamp. | strong | `574BB0`, UID0001HU | UID0003UN | incorporate | applied |
| C3UN-028 | EPF and legacy tails must remain duplicated; factoring is unsupported compression. | strong | duplicated buffers/loops/EH temporaries | UID0003UN formal | incorporate | applied |
| C3UN-029 | Binary performs no null checks for panels, child panes, status panes, map pane, Config, or packet sender. | very strong | complete CFG/decompile | UID0003UN negative/formal | incorporate | applied |
| C3UN-030 | Packet bytes 5..7 are unused by this body; no names or semantics should be invented. | very strong | complete packet-read audit | UID0003UN negative | incorporate | applied |
| C3UN-031 | Prefix `[0x005aac79,0x005aac80)` is seven CC alignment bytes, SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`. | very strong | bounded bytes/hash | UID0000VN | incorporate | applied |
| C3UN-032 | Suffix `[0x005aafe3,0x005aaff0)` is thirteen CC alignment bytes, SHA256 `0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE`. | very strong | bounded bytes/hash | UID0000VN | incorporate | applied |
| C3UN-033 | Target requires no source split and retains `Nested:0`. | very strong | one modeled member/boundaries | UID0003UN metadata | already-present | already-present |
| C3UN-034 | Owner/emitter, reconstructable flag, blank position, and UserPane.cpp route remain correct. | very strong | receiver/class/file/generated route | UID0003UN metadata | already-present | already-present |
| C3UN-035 | Target moves `86/88 -> 92/94`. | strong | closed behavior plus lexical caps | UID0003UN metadata | incorporate | applied |
| C3UN-036 | Current main-window/loading/receive-reset/CollectionData/server-list body is rejected and historicalized. | very strong | complete callee/dataflow mismatch | UID0003UN history/formal | historicalize | applied |
| C3UN-037 | Destination 1 is the exact replacement managed target block. | strong | all target evidence | UID0003UN formal | incorporate | applied |
| C3UN-038 | Dispatcher records opcode 0x05, adjusted receiver, true-return route, and exact target effects without changing its score/formal. | strong | dispatcher/target relation | UID0003VB prose | incorporate | applied |
| C3UN-039 | UID0001KM keeps non-emitting metadata/blank formal and receives the exact target plus padding inventory. | strong | source-family index | UID0001KM inventory | incorporate | applied |
| C3UN-040 | At callback time, UID0000P1 keeps the complete current union: settled B001/B004 facts, accepted B005 facts, every B002/B003 fact accepted before the edit, and all unrelated content; under the supervisor's B004-first override, B004 rereads/rebases and adds only exact UID0003UN source behavior while B003/B001/B002 remain held behind this lane. | very strong | current file + all active-work goals/reports + callback-time state gate | UID0000P1 | incorporate | applied |
| C3UN-041 | SelfLookPane class/file and UID0003QH receive no-loss refresh identity/body synchronization. | strong | wrapper/accepted Spelled API | UID0000CU/0000NL/0003QH | incorporate | applied |
| C3UN-042 | NewSystemMessagePane class/file/aggregate receive the real registered child and exact helper identity while their scores/formal shell stay bounded. | strong | wrapper/class/aggregate evidence | UID00009C/0000OE/0001J6/new child | incorporate | applied |
| C3UN-043 | New child was serially registered first as UID0004R2; every temporary UID token is replaced before dependent cross-linking. | very strong | validator command 000000012860 serial registration | report/destinations/coverage handoff | incorporate | applied |
| C3UN-044 | Manual target, helper, parent, class, file, dispatcher, and padding rows require exact union-preserving supervisor text; UID0001KM/UID0000FQ rows remain true. | very strong | read-only manual row comparison | manual coverage handoff | incorporate | applied |
| C3UN-045 | Final generated state is one corrected UID0003UN body, one SelfLook helper, one real-UID NewSystem helper, and zero target stale tokens/empty markers/duplicates. | strong | emitter routes/current generated readback | generated verification | incorporate | applied |
| C3UN-046 | B001/B004/B005 are the protected current baseline; the supervisor's B004-first override holds B003/B001/B002 behind this lane, so B004 rereads their accepted artifacts as preservation input, edits each shared page under one short lease, rebases without loss, and rereads the union after final generation; downstream callbacks must preserve these completed B004 bytes. | very strong | current goals/artifacts/hashes/shared paths/lease state + supervisor ordering override | callback ordering/checklist | incorporate | applied |

### Callback Destination Proof

| Claims | Terminal destination proof |
| --- | --- |
| C3UN-001..005, 007, 013..030, 033, 035..037 | UID0003UN current SHA256 `ABE9BBB346E300C44EDAFADC851B2807BE3212EE0969EF7F8B56E87E2A0FD326`; `92/94`; exact Destination 1; report-level boundary/CFG/ABI/caller/branch/packet/container/negative/history evidence; scoped command `000000012867`; final waited command `000000012896`. |
| C3UN-006, 034 | Owner/emitter/reconstructable/blank-position/UserPane.cpp route and exact declaration were already present. Verify-only UID0000FQ current SHA256 `E4AA6D4FFA4A0BC257CA671E8EDFEF06B8D36BD41465A6DB2FD75C14A6B05291` contains exactly one declaration and was not edited by B004. |
| C3UN-008, 010, 012, 041 | UID0003QH validator-aware rename is complete; old path absent; current SHA256 `706C9D2505473A3131C9952C4BE9521E8D0297B2EEC819412AA2D37CAEB02767`; exact Destination 2; commands `12862`/`12864`. SelfLook class/file current hashes are `EDE793D4...D244`/`0E517799...DC87`, commands `12868`/`12871`; direct aggregate reverse-link dependency current hash `243E4057...EB9E`, command `12883`. |
| C3UN-009, 011, 012, 042, 043 | New child was serially registered first as UID0004R2 by command `12860`, relinked by `12864`, and is unique at SHA256 `7DCF8D72...C347`; exact Destination 4. NewSystem class, SystemMessage file, and UID0001J6 hashes are `8DB000E7...E30E`, `C4BAB512...C1EF4`, and `C387B4BF...0E5`, commands `12875`, `12878`, and `12879`. Zero temporary UID token remains. |
| C3UN-031, 032 | `by-memory/-ignored.md` SHA256 `73F01BE7C8859539FCEB8CC515A7A0D615D52470DE4DD25DE1B03C7E5B144ED4` contains exactly the accepted seven- and thirteen-byte alignment entries; command `12880`. |
| C3UN-038 | UID0003VB SHA256 `CBA235435FF71EF9DA524C2963D96AC517B184239B67AB74E97BCB9A8EC113D0` records opcode `0x05`, call `0x005a797f`, complete-UserPane receiver adjustment, true result, and full bounded effect summary without changing `87/89` or its formal; command `12895`. |
| C3UN-039 | UID0001KM SHA256 `1E53B83F744B364D5769316D0FAEC19B558A9410E37D3BB4327AF48AD5F7396A` retains `90/92`, NONE/FALSE/blank formal and complete current inventory while replacing the stale target row and adding both padding spans; command `12894`. |
| C3UN-040 | UID0000P1 SHA256 `8DB6D7C19E62307B98644404FFFAED610B94B96F875EB5A3DFF653632DEA2E4D` preserves current B001/B004/B005 content and adds only complete UID0003UN source behavior/history/dependency/no-split facts; command `12893`. Accepted B003/B002 reports were reread; the supervisor B004-first override holds their implementation behind this current union. |
| C3UN-044 | Exact manual memory/class/file handoff text remains in this report with real UID0004R2 and current B004-first union wording. B004 did not edit manual coverage; supervisor-owned coverage/lifecycle state remains external. |
| C3UN-045 | Final waited command `12896`; UserPane generated SHA256 `441537C0...226`, SelfLookPane `FFD1972F...A80`, SystemMessagePanes `A8E35194...DD2`; one target and each wrapper definition, zero target/helper empty markers, zero stale wrapper name, zero temporary token, and exact branch/body assertions. |
| C3UN-046 | Supervisor explicitly assigned B004 the shared lane first and held B003/B001/B002 behind it. B004 reread accepted reports/current destinations, leased only one file at a time, performed additive changes, released every lease, and reread after command `12896`; downstream callbacks must preserve this completed union. |

## Positive Evidence Summary

- Exact target range, full target hash, stable one-function model, one direct dispatcher caller, opcode 0x05, `retn 4`, and unconditional true result are direct.
- UserPane ownership is supported simultaneously by receiver adjustment, UserPane-only high-offset state, current class declaration, file route, aggregate placement, and generated ownership.
- Both branches are behavior-closed through all 20 callees. There are no unresolved call targets in the main source body.
- The two refresh wrappers are exceptionally strong semantic twins: same 30-byte shape, same FrameHandler operations, only the embedded SpelledPane offset differs (`+0xfc` versus `+0xf8`).
- Transfer-overlay behavior is supported by exact class/global/helper pages, not a generic UI inference.
- Status icon and map update roles are direct accepted helper contracts.
- Block/listen vector identity is triangulated from exact Config offsets, sibling add/delete handlers, vector layout, opcode/subcommand, and per-entry conversion.
- Source placement is coherent: target in UserPane.cpp, SelfLook wrapper in SelfLookPane.cpp, NewSystem wrapper in SystemMessagePanes.cpp.

## IDA MCP Facts

- Database: `01f84d61`, NexusTK.exe.i64, adopted active worker PID `18448`.
- Health at fresh pass: `ok`; analysis, Hex-Rays, and string cache ready.
- Target start/end/size: `0x005aac80`, `0x005aafe3`, `0x363`.
- Target SHA256: `4B658CF3F99E9145A8AEB8B87F5F291081B8E092431DB3D906BA0F364924807B`.
- Prologue begins `55 8b ec 6a ff 68 96 ae 60 00 64 a1 00 00 00 00`.
- Epilogue at the end includes `8b e5 5d c2 04 00`; padding begins immediately at `0x005aafe3`.
- Stack allocation is `0x814`, covering two independent `0x400` arrays, cursors, temporary narrow StringBase handles, and compiler EH state.
- Main-body branches: EPF and legacy. Total blocks 26 including EH funclets; main body 21; complexity 12.
- Sole target call: dispatcher `0x005a797f`; receiver is adjusted by `-0xa0`.
- Wrapper hashes:
  - `0x005671c0-0x005671de`: SHA256 `8A6D7C4F31908097F9F7579236303740DEBF5B44FE030C47E882DDB204B3841C`; exactly two target callsites, one per branch.
  - `0x00588d50-0x00588d6e`: SHA256 `38BE83D274E61C5A74872233AE56A79F2FD40085C3D3BD430602384D735AEEF4`; exactly one target callsite, EPF branch only.

### Complete main-body callee map

| Address | Source role |
| --- | --- |
| `0x004b85f0` | `GeneralPurposePanel::GetChildPaneByIndex(0)` |
| `0x005671c0` | `SelfLookPane::RefreshSpelledPane()` |
| `0x004b8950` | `GeneralPurposePanel2::GetChildPaneByIndex(0)` |
| `0x00588d50` | `NewSystemMessagePane::RefreshSpelledPane()` |
| `0x00574ce0` | `Socket::SetSendDisabled(false)` |
| `0x00599250` | `TransferServerDialogPane::ResetOpacityAndRepaint()` |
| `0x00469180` | `BlackHole::QueuePaneForDeferredDeletion(Pane *)` |
| `0x005754c0` | `PacketBufferReadUInt32BE` |
| `0x00575470` | compiler/inlined narrow byte conversion |
| `0x005b86e0` | active `UserStatusPane::SetStatusIconId` |
| `0x005bdc70` | old `UserStatusPane::SetStatusIconId` equivalent |
| `0x00506980` | `MapPane::UpdateObjectPaneScreenBounds(ObjectPane *)` |
| `0x005845f0` | pointer-backed wide StringBase `empty()` |
| `0x00575650` | value-first `PacketBufferAppendUInt8` |
| `0x005825a0` | wide StringBase to narrow StringBase conversion |
| `0x00584540` | narrow StringBase `c_str()` |
| `0x005757d0` | text-first `PacketBufferAppendAnsiString8` |
| `0x00582b30` | narrow temporary release |
| `0x00574bb0` | `Socket::QueueAndSendPacket` |
| security cookie | compiler support, not handwritten source |

## Function / Child Inventory

| Range | Current identity | Disposition | Metadata / notes |
| --- | --- | --- | --- |
| `[0x005aac79,0x005aac80)` | UID0000VN alignment | ignored/non-emitting | seven CC bytes; exact hash above |
| `[0x005aac80,0x005aafe3)` | UID0003UN `UserPane::HandleServerEntryPacket` | one source member | `92/94`, owner/emitter 0000FQ, true, blank position, Nested 0 |
| `[0x005aafe3,0x005aaff0)` | UID0000VN alignment | ignored/non-emitting | thirteen CC bytes; exact hash above |
| `[0x005aaff0,0x005ab084)` | UID0003UO retained raw warp body | unchanged/verify-only | no IDA function at start; inline dispatcher equivalent remains separate |
| `[0x005671c0,0x005671de)` | UID0003QH `SelfLookPane::RefreshSpelledPane` | source member rename | `85/89 -> 89/92`, owner/emitter 0000CU, Nested 0 |
| `[0x00588d50,0x00588d6e)` | UID0004R2 `NewSystemMessagePane::RefreshSpelledPane` | new source member | registered first by validator command 000000012860; `89/92`, owner 00009C, emitter 0000OE, Nested 0 |

The new child was serially created and scoped-validated before dependent cross-linking. Validator command `000000012860` assigned UID0004R2; every temporary token was then replaced in this report, all ordinary destinations, and the supervisor-owned manual-row handoff.

## Direct Xref / Caller Inventory

| Target | Direct route result | Interpretation |
| --- | --- | --- |
| `0x005aac80` | one call, `0x005a797f` inside UID0003VB | live opcode-0x05 UserPane dispatcher child |
| `0x005671c0` | calls `0x005aacd5`, `0x005aae5c` | refreshes SelfLookPane in both target branches |
| `0x00588d50` | call `0x005aace9` | refreshes NewSystemMessagePane only in EPF branch |
| `0x005aaff0` | no IDA function/start route | adjacent retained raw UID0003UO; not target fallthrough |
| transfer overlay global `0x0069b4b0` | target tests/uses in both branches | optional overlay consumer; no ownership transfer |
| Config global `0x0067a7c8` | target reads vector begin/end in both branches | block/listen replay source |

## Documentation Evidence And IDA Status

- IDA was healthy when the recorded evidence was collected. This statement does not assert indefinite session availability.
- Historical pre-callback target state had the correct directional title/signature/owner but stale body and source prose. The current target has the accepted body and report-level evidence at `92/94`.
- Historical pre-callback UID0003VB gave only a generic server-entry/login-state description. Its current page records exact opcode `0x05`, callsite `0x005a797f`, adjusted receiver, true result, and bounded target effects.
- Historical pre-callback UID0001KM listed UID0003UN generically and lacked both adjacent padding rows. Its current inventory contains the exact target and both gaps.
- Historical pre-callback UID0003QH used `RefreshWorldMapPane`, blank formal C++, and provisional field/helper names. Its current UID-preserving path, title, evidence, and Destination 2 resolve all three defects.
- Historical pre-callback NewSystemMessagePane class, SystemMessagePanes file, and aggregate used the stale `RefreshWorldMapPane` identity and lacked an exact child page at `0x00588d50`. Their current pages cross-reference registered UID0004R2 and preserve unrelated family content.
- Historical pre-callback generated UserPane output proved routing but contained the rejected abstractions. Final waited command `12896` emits the accepted target body once with no target empty marker or rejected token.
- The current SimpleUStringVector class shell omits iterator/size facade methods even though accepted BlockListen source already uses them. This remains a broader declaration-shell limitation; the target now uses the accepted human container syntax rather than raw `g_pConfig` byte offsets.

## Ranked Ownership Analysis

1. **UserPane member, UserPane.cpp emitter - accepted.** Receiver adjustment, UserPane-only map field, current declaration, source-family position, dispatcher route, and generated file all agree.
2. **LivingObjectPane member - rejected.** The body needs derived UserPane state far beyond the `0x20c` LivingObjectPane object and is declared/routed as UserPane.
3. **Dispatcher-inline-only body - rejected.** The dispatcher makes one direct out-of-line call to exact modeled function `0x005aac80`.
4. **File-local/static UserPane.cpp helper - rejected.** The body consumes a real receiver and current class declaration/vtable family treats the signature as a member.
5. **TransferServerDialogPane, Config, Socket, MapPane, or UserStatusPane owner - rejected.** Those classes/globals are callees/data dependencies; none owns the receiver or full body.

Wrapper ownership is separately exact:

- `0x005671c0` is a SelfLookPane member emitted through SelfLookPane.cpp.
- `0x00588d50` is a NewSystemMessagePane member emitted through SystemMessagePanes.cpp.
- FrameHandler and SpelledPane are implementation dependencies; neither owns the wrappers.

## Source Placement

- Target lexical source: `NexusTK/ui/panels/UserPane.cpp`, through [UID:0000P1].
- Target declaration: [UID:0000FQ] `UserPane`; declaration already exactly matches and is verify-only.
- SelfLook wrapper: `NexusTK/ui/panels/SelfLookPane.cpp`, through [UID:0000NL].
- NewSystem wrapper: `NexusTK/social/SystemMessagePanes.cpp`, through [UID:0000OE]. Current generated partition caveats do not transfer source ownership.
- Config, StringBase/StringUtil, Socket, BlackHole, TransferServerDialogPane, MapPane, and UserStatusPane remain verify-only dependency sources. Their declarations/bodies were neither moved nor duplicated.

## Range / Split / Padding / Reclassification Analysis

- `0x005aac80` is a modeled function start; size `0x363` gives exact exclusive end `0x005aafe3`.
- The final `retn 4` ends before thirteen CC bytes. UID0003UO begins at `0x005aaff0`; there is no fallthrough.
- Seven CC bytes immediately precede the prologue. Both gaps are linker/compiler alignment, not source statements.
- The target has one entry, one receiver, one explicit parameter, one boolean result, and branch-local compiler cleanup. No internal block has an independent xref, callable prologue, pointer route, or separate source signature.
- EPF/legacy branch duplication is source control flow inside the member, not a split.
- Temporary StringBase conversion/destruction and security-cookie/EH blocks are compiler lowering, not children.
- UID0003QH was correctly handled as a UID-preserving rename rather than a new UID.
- `0x00588d50` was serially validator-registered as UID0004R2 before cross-linking. It is nested at the same exact-child level under UID0001J6; current `Nested:0` keeps the relative level after the preceding exact row.

## Negative Evidence Summary

- No MainWindow, LoginDialogPane, LoadingPane, Application delete, Socket receive-reset, CollectionData, legacy CollectionData, or server-address-list callee/data route exists in the target.
- No global clear follows transfer-overlay queueing.
- No direct `delete` or scalar deleting destructor is called for the transfer overlay.
- No map invalidation call exists; the actual map call is bounds recomputation.
- No server-mode field is written; packet byte 9 goes only to status-icon setters after a `<=4` test.
- No `active` element flag exists in the vector loop; emptiness is tested on the string handle itself.
- No packet buffer is 256 bytes. Each branch reserves 1,024 bytes.
- No zero-fill, buffer-capacity guard, string-length clamp, list truncation, or send retry exists.
- No null guards exist for the required panels/children/status/config/map/socket objects.
- No target reads packet bytes 5, 6, or 7.
- No evidence supports factoring a new common replay helper or rewriting the two branches as one shared tail.
- No evidence supports preserving `RefreshWorldMapPane`; both wrapper receivers are SpelledPane children.

## IDA Rename / Type / Comment Recommendations

No IDA mutation was performed during research or callback. If a separate supervisor-authorized IDA naming pass is later performed:

- Rename `sub_5AAC80` to `UserPane__HandleServerEntryPacket`; type as `bool __thiscall(UserPane *, const unsigned char *)`.
- Rename `sub_5671C0` to `SelfLookPane__RefreshSpelledPane`.
- Rename `sub_588D50` to `NewSystemMessagePane__RefreshSpelledPane`.
- Type Config `+0x2918fc/+0x291900/+0x291904` as the `SimpleUStringVector m_blockListenNames` begin/end/capacity triplet.
- Type target receiver fields `+0xfc` as `unsigned int m_objectId`, `+0x1c5` as `unsigned char m_facing`, and `+0x1340f8` as `MapPane *m_mapPane`.
- Comment `packet[1..4]` object id, `packet[8]` facing, `packet[9]` status icon id, and opcode `0x0d` subcommand `0x02` as block/listen add replay.
- Mark `[0x005aac79,0x005aac80)` and `[0x005aafe3,0x005aaff0)` as alignment, not code.

## First-Draft C++ Recommendation

All accepted C++ appears only inside literal managed destination blocks. Destinations 1-4 are applied exactly and compare equal to their current ordinary destinations after newline normalization; they are not examples.

### Destination 1 - UID0003UN target

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::HandleServerEntryPacket(const unsigned char *packet)
{
    if (g_useEpfAssets == 1)
    {
        SelfLookPane *selfLookPane = static_cast<SelfLookPane *>(
            g_pGeneralPurposePanel->GetChildPaneByIndex(0));
        selfLookPane->RefreshSpelledPane();

        NewSystemMessagePane *systemMessagePane =
            static_cast<NewSystemMessagePane *>(
                g_pGeneralPurposePanel2->GetChildPaneByIndex(0));
        systemMessagePane->RefreshSpelledPane();

        g_packetSender->SetSendDisabled(false);
        if (g_pTransferServerDialog != 0)
        {
            g_pTransferServerDialog->ResetOpacityAndRepaint();
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(
                g_pTransferServerDialog);
        }

        m_objectId = PacketBufferReadUInt32BE(packet + 1);
        m_facing = packet[8];
        const unsigned char statusIconId = packet[9];
        if (statusIconId <= 4)
            g_activeUserStatusPane->SetStatusIconId(statusIconId);

        m_mapPane->UpdateObjectPaneScreenBounds(this);

        SimpleUStringVector &blockedNames = g_pConfig->m_blockListenNames;
        if (blockedNames.size() < 0xff)
        {
            for (SimpleUStringVector::const_iterator it = blockedNames.begin();
                 it != blockedNames.end(); ++it)
            {
                if (!it->empty())
                {
                    unsigned char request[0x400];
                    int requestSize = 0;
                    PacketBufferAppendUInt8(0x0d, request, &requestSize);
                    PacketBufferAppendUInt8(0x02, request, &requestSize);

                    StringBase<char, mychar_traits<char> > narrowName(*it);
                    PacketBufferAppendAnsiString8(
                        narrowName.c_str(), request, &requestSize);
                    g_packetSender->QueueAndSendPacket(
                        request, static_cast<short>(requestSize));
                }
            }
        }
    }
    else
    {
        SelfLookPane *selfLookPane = static_cast<SelfLookPane *>(
            g_pGeneralPurposePanel->GetChildPaneByIndex(0));
        selfLookPane->RefreshSpelledPane();

        g_packetSender->SetSendDisabled(false);
        if (g_pTransferServerDialog != 0)
        {
            g_pTransferServerDialog->ResetOpacityAndRepaint();
            g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(
                g_pTransferServerDialog);
        }

        m_objectId = PacketBufferReadUInt32BE(packet + 1);
        m_facing = packet[8];
        const unsigned char statusIconId = packet[9];
        if (statusIconId <= 4)
            g_pOldUserStatusPane->SetStatusIconId(statusIconId);

        m_mapPane->UpdateObjectPaneScreenBounds(this);

        SimpleUStringVector &blockedNames = g_pConfig->m_blockListenNames;
        if (blockedNames.size() < 0xff)
        {
            for (SimpleUStringVector::const_iterator it = blockedNames.begin();
                 it != blockedNames.end(); ++it)
            {
                if (!it->empty())
                {
                    unsigned char request[0x400];
                    int requestSize = 0;
                    PacketBufferAppendUInt8(0x0d, request, &requestSize);
                    PacketBufferAppendUInt8(0x02, request, &requestSize);

                    StringBase<char, mychar_traits<char> > narrowName(*it);
                    PacketBufferAppendAnsiString8(
                        narrowName.c_str(), request, &requestSize);
                    g_packetSender->QueueAndSendPacket(
                        request, static_cast<short>(requestSize));
                }
            }
        }
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 2 - UID0003QH renamed exact child

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void SelfLookPane::RefreshSpelledPane()
{
    m_spelledPane->RefreshScrollState();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 3 - complete by-class/SelfLookPane.md rebase

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// First-draft declaration skeleton. Method bodies are documented on exact child pages.
class SelfLookPane : public PanelPane {
public:
    bool OnMouseClick(const PanelMouseEvent *event);
    bool OnPacketEvent(const PanelPacketEvent *event);

    bool SendSelfLookOptionRequest(unsigned char optionSubtype);
    bool ApplySelfLookRectRecord(const unsigned char *packet);
    bool ApplySelfLookRectStateRecord(const unsigned char *packet);
    bool ApplyEquipmentSlotRecord(const unsigned char *packet);
    bool ClearEquipmentSlotRecord(const unsigned char *packet);
    bool ApplySelfLookSummaryRecord(const unsigned char *packet);
    bool DispatchSpelledText(const unsigned char *packet);
    void ToggleSelfLookViewCache();
    void RefreshSpelledPane();

private:
    enum EquipmentSlotId {
        SelfLookEquipmentSlot_FaceAccessory1 = 7,
        SelfLookEquipmentSlot_Head = 8,
        SelfLookEquipmentSlot_HeadAccessory2 = 9,
        SelfLookEquipmentSlot_RightHand = 10,
        SelfLookEquipmentSlot_Body = 11,
        SelfLookEquipmentSlot_LeftHand = 12,
        SelfLookEquipmentSlot_RightAccessory = 13,
        SelfLookEquipmentSlot_Mantle = 14,
        SelfLookEquipmentSlot_LeftAccessory = 15,
        SelfLookEquipmentSlot_LeftSubAccessory = 16,
        SelfLookEquipmentSlot_Coat = 17,
        SelfLookEquipmentSlot_RightSubAccessory = 18,
        SelfLookEquipmentSlot_Necklace = 19,
        SelfLookEquipmentSlot_Foot = 20
    };

    SpelledPane *m_spelledPane;
    LegendPane *m_legendPane;
    ObjectStatusBlob m_selfLookObjectStatus;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### Destination 4 - registered [UID0004R2] NewSystemMessagePane exact child

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewSystemMessagePane::RefreshSpelledPane()
{
    m_spelledPane->RefreshScrollState();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

## Final Recommendation

All four formal destinations and the bounded support plan are implemented. The target emits one exact source body; UID0003QH retained its UID through the validator-aware rename; UID0004R2 was serially registered before cross-linking; parent/index pages remain non-emitting. The invented former target body remains documented only as rejected historical source.

Shared incorporation followed the supervisor's B004-first ordering override. B004 reread the terminal B005 artifact, accepted B003/B002 artifacts, complete current destinations, and leases; then leased/reread/edited/validated/released each shared page separately and applied only UID0003UN additions. B003/B001/B002 are held behind this lane and must rebase this completed union rather than being pre-implemented here. Final command `12896` and readback prove the B004 lane is complete with no lease or implementation item remaining. Report validation/execution/archive/count state is external supervisor/validator-owned.

## Recommended Target Doc Changes

For `by-memory/0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md`, the callback applied:

- Current `COMPLETION:92`, `CONFIDENCE:94`; preserved UID, owner/emitter 0000FQ, reconstructable true, blank position, and `Nested:0`.
- Exact Destination 1 in the managed formal block; current SHA256 `ABE9BBB346E300C44EDAFADC851B2807BE3212EE0969EF7F8B56E87E2A0FD326`; scoped validator `12867`; final waited validator `12896`.
- Exact Item Summary:
  `Exact opcode-0x05 UserPane server-entry handler with one dispatcher caller, duplicated EPF/legacy branches, SelfLook/NewSystem SpelledPane refresh, packet-sender re-enable, transfer-overlay repaint/deferred deletion, object-id/facing/status-icon application, MapPane bounds refresh, block/listen add replay through two 0x400-byte branch-local packets, exact unchecked behavior, and complete source-ready C++.`
- The full range/hash/CFG/ABI/caller/callee/field/global/packet/vector/string/padding/source/negative/rejected/history evidence is incorporated at report-level detail.
- The former authoritative/source-ready invented body and final-C++-blank/unresolved contradiction are historicalized together; neither remains current.

## Recommended Support Doc Changes

Supervisor assigned B004 the shared lane first and held B003/B001/B002 behind it. The accepted reports and complete current destinations were reread; B004 preserved the full current union, applied only UID0003UN additions under one-file leases, and verified it again after final generation. Downstream target implementations remain owned by their agents and must rebase B004's current bytes.

1. [UID:0003VB] score/formal remain unchanged; opcode `0x05`, callsite `0x005a797f`, adjusted receiver, true result, and complete target effects are applied at SHA256 `CBA23543...13D0`, validator `12895`.
2. [UID:0001KM] retains `90/92`, owner NONE, false, blank emitter/formal and complete inventory; its stale generic target row and both padding gaps are corrected at SHA256 `1E53B83F...396A`, validator `12894`.
3. [UID:0000P1] retains `91/92` and the complete current B001/B004/B005 union; exact opcode-`0x05` source/effects/dependency/rejected-history/no-split facts are added at SHA256 `8DB6D7C1...E4D`, validator `12893`.
4. [UID:0000FQ] remained verify-only and unedited. SHA256 `E4AA6D4F...5291` contains exactly one target declaration and preserves the current complete class union.
5. [UID:0003QH] retained its UID through the accepted path rename, is `89/92`, and contains exact Destination 2/evidence at SHA256 `706C9D25...2767`; validators `12862`/`12864`.
6. [UID:0000CU] remains `89/91`; Destination 3 and exact caller/source proof are current at SHA256 `EDE793D4...D244`, validator `12868`.
7. [UID:0000NL] remains `92/94`; exact SpelledPane wrapper/source placement is current at SHA256 `0E517799...DC87`, validator `12871`.
8. [UID:0004R2] was registered first, is `89/92`, owner 00009C/emitter 0000OE/true/blank position/`Nested:0`, and contains Destination 4 plus complete 30-byte evidence at SHA256 `7DCF8D72...C347`; validators `12860`/`12864`.
9. [UID:00009C] remains `85/86` with its bounded shell; real child link and exact helper proof are current at SHA256 `8DB000E7...E30E`, validator `12875`.
10. [UID:0000OE] remains `89/86`; real child and corrected identity are current at SHA256 `C4BAB512...C1EF4`, validator `12878`.
11. [UID:0001J6] remains `88/92`, NONE/FALSE/blank formal/`Nested:0`; real child inventory and family exclusions are current at SHA256 `C387B4BF...0E5`, validator `12879`.
12. [UID:0000VN] contains exactly both accepted alignment entries at SHA256 `73F01BE7...4ED4`, validator `12880`.
13. `SimpleUStringVector`, Config/block-list helpers, Socket, TransferServerDialogPane, BlackHole, MapPane, UserStatusPane, SpelledPane, FrameHandler, and associated globals/storage remained verify-only; no score/formal was inflated.

## Score And Metadata Recommendation

| Destination | Pre-callback | Current | Rationale |
| --- | ---: | ---: | --- |
| UID0003UN | `86/88` | `92/94` | Exact range/hash/CFG/ABI/caller/opcode, complete branch/callee/field/vector/source closure, rejected pre-callback body, and complete formal C++; lexical container/wrapper names remain inferred caps. |
| UID0003QH | `85/89` | `89/92` | Exact 30-byte body/hash, two direct target callers, receiver field, exact FrameHandler order, and accepted source abstraction resolve the blank/name blockers. |
| UID0004R2 `0x00588d50` child | absent | `89/92` | Exact modeled 30-byte body/hash, one direct target caller, receiver field, identical proven wrapper, and source route; original lexical name remains inferred. |
| UID0003VB | `87/89` | unchanged | Bounded opcode-route prose only; no dispatcher body/formal reanalysis. |
| UID0001KM | `90/92` | unchanged | Exact non-emitting index already strong; target inventory/padding detail does not justify index inflation. |
| UID0000CU | `89/91` | unchanged | One declaration/helper correction; broad class remains bounded by unrelated shell/field caveats. |
| UID0000NL | `92/94` | unchanged | File union already strong; bounded helper correction only. |
| UID00009C | `85/86` | unchanged | Helper resolved, but broader class declaration/member/vtable shell remains intentionally incomplete. |
| UID0000OE | `89/86` | unchanged | Exact helper child improves detail but not the existing family-partition confidence cap. |
| UID0001J6 | `88/92` | unchanged | Non-emitting index; one child addition does not change aggregate disposition. |

## Open Questions With Attempted Resolution

| Question | Checks performed | Resolution |
| --- | --- | --- |
| Exact target signature? | caller ABI, stack cleanup, packet reads, return use, current declaration | `bool UserPane::HandleServerEntryPacket(const unsigned char *packet)`. |
| Exact opcode? | dispatcher selector table and sole callsite | `0x05`. |
| Is byte 9 server mode? | bound and both status setter callees | No; `statusIconId`. |
| What are bytes 5..7? | complete packet read audit | Unused here; no names assigned. |
| Does server entry close UI? | complete callee/global audit | No; reject all invented login/loading close/reset calls. |
| What list is replayed? | Config offsets, sibling block/listen handlers, opcode/subcommand | `m_blockListenNames`, not server addresses. |
| What helper name fits wrappers? | fields, identical bodies, accepted SpelledPane source API | `RefreshSpelledPane`; method calls `RefreshScrollState`. |
| Is a new NewSystem child necessary? | exact modeled range and registration result | Yes; it was serially registered as UID0004R2 before cross-linking. |
| Is raw vector access necessary? | current layout and accepted BlockListen source API | No. Use human iterator/size API; preserve broader shell caveat. |
| Can branches be merged? | duplicated locals/EH/loops and branch-specific calls | No; preserve duplicate source. |
| Is confidence 95+ justified? | lexical/source API review | No. Original helper and container spellings remain inferred; cap at 94. |
| Is implementation order deferred or unresolved? | Current B001/B004/B005 state, Gate-1-accepted B002/B003 artifacts, shared paths/leases, and supervisor callback-order override | Resolved and applied. Supervisor assigned B004 the shared lane first and held B003/B001/B002 behind it. B004 reread accepted artifacts/current destinations, applied only additive UID0003UN facts under short leases, and verified after generation. Downstream callbacks must rebase this current union. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

These rows are a read-only handoff. B004 did not edit manual coverage. Existing UID0001KM and UID0000FQ rows were inspected and remain true for the completed B004 lane; no replacement is proposed for them. UID0004R2 is the registered real UID, so no placeholder/template row remains. External supervisor application must reread current manual rows and account for any later downstream B003/B001/B002 callback before replacing a complete union row.

### by-memory/-coverage-report.md

Replace current UID0003UN row with:

        - [UID:0003UN][0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket](by-memory/0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md) 0x005aac80-0x005aafe3 | UserPane member | UserPaneHandleServerEntryPacket : reconstructable : 92% : very-strong : Exact opcode-0x05 UserPane server-entry handler with one dispatcher caller, duplicated EPF/legacy branches, SelfLook/NewSystem SpelledPane refresh, packet-sender re-enable, transfer-overlay repaint/deferred deletion, object-id/facing/status-icon application, MapPane bounds refresh, block/listen add replay through two 0x400-byte branch-local packets, exact unchecked behavior, and complete source-ready C++.

Add immediately before and after that row:

        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005aac79-0x005aac80 | compiler/linker alignment | UserPane pre-server-entry alignment : ignored : 100% : strong : Seven all-0xcc bytes immediately before UID0003UN; SHA256 F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D; no source-body role.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005aafe3-0x005aaff0 | compiler/linker alignment | UserPane server-entry to retained warp-body alignment : ignored : 100% : strong : Thirteen all-0xcc bytes between UID0003UN and UID0003UO; SHA256 0D0BB866505BC0E2D4276FCDEE1AFDC8887662D04CCE9E4BBB4C10FBA6D0F1CE; no source-body role.

Add exact UID0003VB row at its address-sorted UserPane dispatcher position:

        - [UID:0003VB][0x005a76c0-0x005a82bd.UserPaneHandleServerMessage](by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md) 0x005a76c0-0x005a82bd | UserPane server-message dispatcher | UserPaneHandleServerMessage : reconstructable : 87% : strong : Exact vtable-routed UserPane dispatcher with current selector/jump-table map, adjusted receiver contracts, opcode-0x05 direct UID0003UN server-entry call at 0x005a797f, preserved inline/retained packet-body distinctions, and bounded dependency ownership.

Add UID0003QH replacement/addition at `0x005671c0`:

        - [UID:0003QH][0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane](by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane.md) 0x005671c0-0x005671de | SelfLookPane member | SelfLookPaneRefreshSpelledPane : reconstructable : 89% : very-strong : Exact 30-byte SelfLookPane SpelledPane refresh wrapper with receiver field +0xfc, FrameHandler remove-then-schedule behavior represented by RefreshScrollState, two UID0003UN branch callers, exact SHA256, and complete source C++.

Add the exact registered UID0004R2 row:

        - [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md) 0x00588d50-0x00588d6e | NewSystemMessagePane member | NewSystemMessagePaneRefreshSpelledPane : reconstructable : 89% : very-strong : Exact 30-byte NewSystemMessagePane SpelledPane refresh wrapper with receiver field +0xf8, FrameHandler remove-then-schedule behavior represented by RefreshScrollState, one EPF UID0003UN caller, exact SHA256, and complete source C++.

Replace stale UID0001J6 row with:

    - [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) 0x00584ea0-0x0058af3b | non-emitting SystemMessagePanes split index | SystemMessagePanes : not_reconstructable : 88% : very-strong : Exact non-emitting index over the SystemMessagePane/NewSystemMessagePane/OldSystemMessagePane executable family, interleaved ForcedInformMessageDialog islands and compiler support, including real-UID NewSystemMessagePane RefreshSpelledPane exact child; owner-specific pages carry source while this parent remains blank.

### by-class/-coverage-report.md

Replace UID0000CU row with:

- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md) : reconstructable : 89% : very-strong : Self-look panel declaration and exact method family with ObjectStatusBlob/equipment/spelled/legend state, packet/view/input helpers, corrected RefreshSpelledPane declaration and two server-entry callers, retained raw-source/compiler distinctions, and SelfLookPane.cpp route.

Replace UID00009C row with:

- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md) : reconstructable : 85% : strong : New system-message wrapper with constructor/singleton/vtable/child-pane evidence, OnActivate rebuild path, exact real-UID RefreshSpelledPane child at 0x00588d50, OnPaint/destructor support, preserved generated partition caveat, and intentionally bounded declaration shell.

UID0000FQ requires no replacement: its current 92% row already covers the complete UserPane declaration and remains true after a target body correction.

### by-file/-coverage-report.md

Replace UID0000NL row with:

- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/SelfLookPane.cpp source grouping with complete SelfLookPane/SelfLookPane2 split inventories, ObjectStatusBlob m_objectStatus, source-ready draw/input/packet children, corrected UID0003QH RefreshSpelledPane wrapper with two UID0003UN callers, exact packet-update methods, resources, retained raw/compiler/padding distinctions, shared child panes, and filename confidence caps.

Replace UID0000OE row with:

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md) : reconstructable : 89% : strong : System-message pane family with exact class/method/vtable/resource/singleton partitions, corrected real-UID NewSystemMessagePane RefreshSpelledPane source child at 0x00588d50, ForcedInform exclusions, generated mispartition caveats, Chatting split, and exact g_pChattingViewport ownership.

The UID0000P1 text below is the exact completed B004-first current union: settled B001/B004/B005 facts plus UID0003UN. B002 UID0003UW and B003 UID0003V9 are accepted downstream callback plans, not yet-applied target facts; the supervisor explicitly held them behind B004. Their later callbacks and any later manual coverage application must start from and preserve this row, then add their independently implemented source facts rather than treating this as an overwrite of future state:

- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 91% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, signed plain-char StartDirectionalAnimation(char direction), source-ready opcode-0x0f ParseInventorySlotUpdatePacket with exact 508-byte record fields and ACP conversions, supervisor-finalized opcode-0x08 settings parsing with exact state/config/sound/active-panel effects, and source-ready opcode-0x05 HandleServerEntryPacket with duplicated EPF/legacy SpelledPane refresh, sender re-enable, transfer-overlay deferred deletion, object/facing/status application, MapPane bounds refresh, and block/listen add replay; all raw/helper/compiler and adjacent-padding distinctions remain preserved.

No tracker or manual coverage row was changed by B004. External supervisor-owned coverage/lifecycle state is not asserted by this artifact.

## Follow-Up Actions

- Report validation, execution, count, current path, movement, and archive state are external supervisor/validator-owned and authoritative only in their external state/history. This artifact neither performs nor directs those lifecycle actions.
- UID0003UN implementation, shared synchronization, validators, generated verification, report ledger, and checklist are complete; no B004 implementation item remains.
- Supervisor ordering holds B003/B001/B002 behind this completed shared lane. Their separate callbacks own their targets and must reread/rebase the current B004 union; this report neither pre-implements nor directs their lifecycle.
- Manual coverage remains external supervisor-owned. The handoff above contains real UID0004R2 and the current B004-first union; downstream callback additions must be merged before any later complete-union row is treated as current.
- Remaining uncertainty is bounded lexical confidence, not deferred behavioral research.

## Confidence

- Target boundary/hash/ABI/caller/opcode/control flow: **very strong**.
- Packet fields, globals, helper effects, branch differences, vector guard/iteration, and return behavior: **very strong**.
- UserPane owner and UserPane.cpp placement: **very strong**.
- `RefreshSpelledPane` and `RefreshScrollState` source identities: **strong**, based on exact fields/twin wrappers/accepted source abstraction.
- `m_blockListenNames` and human iterator API: **strong** for semantic field/container role, **medium-high** for exact original lexical spelling.
- Current target `92/94` intentionally remains below 95 because original symbols are absent and the SimpleUStringVector declaration shell is broader than this target.

## Validator Results

- All commands ran from `source-3/project-documentation` in scoped file mode with `--apply --queue-timeout 240`; command `12896` additionally used `--wait-generated`. Every command exited 0 with `ok:1`.

| Command | Timestamp | Scoped path / purpose | Result and diagnostics |
| --- | --- | --- | --- |
| `000000012860` | `2026-07-15T04:52:53-04:00` | serial registration of new `0x00588d50` child | exit 0, `ok:1`; assigned UID0004R2; initial old UID0003QH-link warning was corrected by the subsequent rename/relink pass. |
| `000000012862` | `2026-07-15T04:54:45-04:00` | final renamed UID0003QH path | exit 0, `ok:1`; validator preserved UID and updated the path; no target warning. |
| `000000012864` | `2026-07-15T04:55:17-04:00` | UID0004R2 relink after UID0003QH rename | exit 0, `ok:1`; stale-link warning cleared. |
| `000000012867` | `2026-07-15T04:57:30-04:00` | UID0003UN target | exit 0, `ok:1`; target metadata/body/evidence accepted; generated refresh deferred to final command. |
| `000000012868` | `2026-07-15T04:58:19-04:00` | `by-class/SelfLookPane.md` | exit 0, `ok:1`; four UID0003UT links normalized; 26 pre-existing missing-reference diagnostics remained unrelated. |
| `000000012871` | `2026-07-15T04:59:46-04:00` | `by-file/SelfLookPane.md` | exit 0, `ok:1`; 26 pre-existing missing-reference diagnostics, none target-specific. |
| `000000012875` | `2026-07-15T05:01:43-04:00` | `by-class/NewSystemMessagePane.md` | exit 0, `ok:1`; child link normalized; eight pre-existing UID0003GN diagnostics remained. |
| `000000012878` | `2026-07-15T05:03:19-04:00` | `by-file/SystemMessagePanes.md` | exit 0, `ok:1`; link index inserted/updated; ten pre-existing missing-reference diagnostics remained. |
| `000000012879` | `2026-07-15T05:03:58-04:00` | UID0001J6 aggregate | exit 0, `ok:1`; UID0003UD links normalized; four pre-existing missing-reference diagnostics remained. |
| `000000012880` | `2026-07-15T05:04:39-04:00` | `by-memory/-ignored.md` | exit 0, `ok:1`; exact two alignment rows accepted; 279 broad pre-existing missing-reference diagnostics were unrelated. |
| `000000012883` | `2026-07-15T05:12:12-04:00` | direct reverse-link dependency UID0001H7 SelfLookPane aggregate | exit 0, `ok:1`; one stale UID0003QH path corrected; 24 pre-existing missing-reference diagnostics remained. |
| `000000012893` | `2026-07-15T05:36:09-04:00` | shared `by-file/UserPane.md` | exit 0, `ok:1`; three target/helper reference-index additions; 18 pre-existing missing-reference diagnostics; projected stats refresh tool-owned. |
| `000000012894` | `2026-07-15T05:36:55-04:00` | shared UID0001KM | exit 0, `ok:1`; two helper reference-index additions; nine pre-existing missing-reference diagnostics; projected stats refresh tool-owned. |
| `000000012895` | `2026-07-15T05:37:31-04:00` | shared UID0003VB | exit 0, `ok:1`; UID0003UN reference-index addition; six pre-existing UID0003VC diagnostics; projected stats refresh tool-owned. |
| `000000012896` | `2026-07-15T05:38:06-04:00` | final waited UID0003UN refresh | exit 0, `ok:1`; generation completed; registry rebuilt at 4,968 nodes/4,004 edges; generated metadata, projected stats, and research tracker refreshed by validator. Broad diagnostics were 14 child fallback inserts, 86 missing child-marker notices, and 170 emitter-no-code notices, none target-specific. |

- Final generated readback: `UserPane.cpp` SHA256 `441537C0A55B55DDEAA7BBE4996507D43F802FA7AFE1C9A7569EBDEC85779226`, 89,852 bytes/2,636 lines; `SelfLookPane.cpp` SHA256 `FFD1972FE740053BF0815E9F4A61E394BF11B4441BE191D96F30BDDB4AAF6A80`, 62,663 bytes/1,806 lines; `SystemMessagePanes.cpp` SHA256 `A8E35194D790B60E9C8A4F72D24182D44A215E3D0D7A3AF3DB0FDF79F5267DD2`, 7,539 bytes/116 lines. All three carry command `12896` and refresh timestamp `2026-07-15T05:38:06-04:00`.
- Assertions: one UID0003UN marker/definition, one UID0003QH marker/definition, one UID0004R2 marker/definition; zero target/helper empty markers; zero stale `RefreshWorldMapPane`; target segment has two 0x400 buffers, three branch-appropriate refresh calls, two sender-enable calls, two deferred-delete calls, two block/listen references, one true return, and zero rejected main-window/loading/server-address/receive-reset/server-mode spellings. The five unrelated SelfLookPane Empty Emitter Markers remain outside the UID0003QH segment.
- B004 ran no `execute_report`, report lifecycle, count/probe, move, or archive command and manually edited no generated output.

## Changed Files

- Renamed once, UID-preserving: `by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshWorldMapPane.md` -> `by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane.md`; old path absent; UID0003QH unique.
- Created/registered once: `by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md`; real UID0004R2 unique.

| Current ordinary path | Current SHA256 | Validator(s) |
| --- | --- | --- |
| `by-memory/0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md` | `ABE9BBB346E300C44EDAFADC851B2807BE3212EE0969EF7F8B56E87E2A0FD326` | `12867`, final `12896` |
| `by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane.md` | `706C9D2505473A3131C9952C4BE9521E8D0297B2EEC819412AA2D37CAEB02767` | `12862`, `12864` |
| `by-class/SelfLookPane.md` | `EDE793D4F136A511D06F487C586C04241607A604323E8E263E09011029ADD244` | `12868` |
| `by-file/SelfLookPane.md` | `0E5177997D7E2C761A1328882740E9B47EC47CC120EF0CA776D1993E8890DC87` | `12871` |
| `by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md` | `7DCF8D720C33A473C71C8DB95CBED48285E3FC218238FAA1D93352D41CE9C347` | `12860`, `12864` |
| `by-class/NewSystemMessagePane.md` | `8DB000E75FC2F051006A6BFCC76985931F5A322A6D600F009FAE3EC4E65AE30E` | `12875` |
| `by-file/SystemMessagePanes.md` | `C4BAB51217C0C948292F67AF497A2A585F41FA6B20261E0B10C585CB5C3C1EF4` | `12878` |
| `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md` | `C387B4BFEAD0C96367DA7622705BA435E0B06A8F62DA7BAAB3581675453E50E5` | `12879` |
| `by-memory/-ignored.md` | `73F01BE7C8859539FCEB8CC515A7A0D615D52470DE4DD25DE1B03C7E5B144ED4` | `12880` |
| `by-memory/0x00565610-0x0056a373.SelfLookPane.md` direct reverse-link dependency | `243E40578E87B62F01EAE8F128B93C375D9943C773AD348722475A3133A7EB9E` | `12883` |
| `by-file/UserPane.md` | `8DB6D7C19E62307B98644404FFFAED610B94B96F875EB5A3DFF653632DEA2E4D` | `12893` |
| `by-memory/0x005a2de0-0x005ad441.UserPaneLocalPlayerExtensions.md` | `1E53B83F744B364D5769316D0FAEC19B558A9410E37D3BB4327AF48AD5F7396A` | `12894` |
| `by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md` | `CBA235435FF71EF9DA524C2963D96AC517B184239B67AB74E97BCB9A8EC113D0` | `12895` |

- Verify-only and unedited: `by-class/UserPane.md`, current SHA256 `E4AA6D4FFA4A0BC257CA671E8EDFEF06B8D36BD41465A6DB2FD75C14A6B05291`.
- Validator-owned side effects were generated C++/metadata, projected stats, reference indexes, tracker refresh, and validator registry synchronization. B004 manually changed none of those files and did not edit manual coverage, audit/supervisor, lifecycle/archive, IDA, queue, lock, or validator-state files.
- The same report was reconciled in place; no agent-local note was created. Every ordinary-file lease was released immediately after its edit/validator window, and the final global lease report is empty.

## Implementation Tracking Checklist

### Report-only / Gate 1 phase

- [x] Historical report-only artifact SHA256 `A5C72E77B2F4206EE0A41E2AD3E5203031ACAEDEE9F3336754456B94FAA2F83D` and its provenance headers passed exact-artifact supervisor Gate 1 at `2026-07-15T04:41:10-04:00`.
- [x] Historical Gate 1 verified every literal required heading as present and substantive; this callback revision retains those headings and research sections.
- [x] Historical Gate 1 verified C3UN-001 through C3UN-046 claim by claim; the callback ledger now records legal terminal states and destination proof.
- [x] All four complete managed destination blocks remain under First-Draft C++ Recommendation and equal their current ordinary destinations after newline normalization.
- [x] Every implementation item was unperformed in the historical report-only revision; all accepted items are now implemented and separately proved below.
- [x] The report-only coordination inventory captured the then-current B001/B004/B005/B002/B003 states; callback-time rereads and the later supervisor B004-first override are recorded under Supporting Research and Supervisor Active Recheck.
- [x] No B002/B003 target proposal was pre-implemented. Their accepted artifacts were used only as preservation input, and their owned target/helper pages remained unedited by B004.
- [x] The historical manual handoff correctly labeled its new-child row as pre-registration; callback command `12860` allocated UID0004R2, and the current handoff contains the real UID plus the completed B004-first UID0000P1 union.

### Implementation callback phase

- [x] No callback binary uncertainty required a new MCP conclusion; all implementation decisions used the accepted live-MCP evidence, and no fallback-only finding was introduced.
- [x] Callback-time B001/B002/B003/B004/B005 goals, exact artifacts, acceptance states, shared destinations, and leases were inventoried before the shared edits.
- [x] The original wait guard was obeyed until the supervisor explicitly assigned B004 the first shared lane and held B003/B001/B002 behind it; no file was edited through another lease, and B005's terminal artifact was used as the settled baseline.
- [x] Gate-1-accepted B002/B003 artifacts and the terminal B005 artifact were reread. B002/B003 target proposals were preserved as downstream ownership rather than imported as B004 implementation.
- [x] Complete current `by-class/UserPane.md`, `by-file/UserPane.md`, UID0001KM, and UID0003VB were reread before shared edits; each writable destination was reread again under its one-file lease.
- [x] The rebase preserves B001 `StartDirectionalAnimation(char direction)`/signed duration/table facts, B004 UID0003UM fields/opcode-`0x0f` facts, terminal B005 opcode-`0x08` settings facts, accepted B002/B003 preservation constraints, and unrelated UserPane content.
- [x] UID0003UN is `92/94` with preserved owner/emitter/reconstructable/blank-position/`Nested:0`, exact Destination 1, and complete C3UN evidence/history; validators `12867` and `12896`.
- [x] UID0003QH retained its UID through the validator-aware rename to `SelfLookPaneRefreshSpelledPane.md`, is `89/92`, and contains exact Destination 2/evidence; validators `12862` and `12864`.
- [x] `by-class/SelfLookPane.md` was rebased from current bytes and contains Destination 3 without deleting unrelated declarations; validator `12868`.
- [x] `by-file/SelfLookPane.md` carries the corrected helper identity and both target callers; validator `12871`.
- [x] Exact child `0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md` was created and scoped-validated before dependent cross-references; command `12860` assigned UID0004R2.
- [x] Every former NewSystem helper UID placeholder was replaced by UID0004R2 in the report, ordinary destinations, and manual-row handoff before cross-linking.
- [x] Registered UID0004R2 contains exact Destination 4 and complete metadata/evidence; validators `12860` and `12864`.
- [x] NewSystemMessagePane class, SystemMessagePanes file, and UID0001J6 were synchronized while preserving scores, formal shell, and unrelated family content; validators `12875`, `12878`, and `12879`.
- [x] UID0003VB, UID0001KM, and `by-file/UserPane.md` were reread/rebased under the B004-first shared-lane override and scoped-validated by commands `12895`, `12894`, and `12893`.
- [x] `by-class/UserPane.md` remained exact and unedited; current SHA256 `E4AA6D4FFA4A0BC257CA671E8EDFEF06B8D36BD41465A6DB2FD75C14A6B05291` contains one target declaration and one `[[CHILDREN]]` marker.
- [x] `by-memory/-ignored.md` received only the exact seven-byte prefix and thirteen-byte suffix alignment entries; validator `12880`.
- [x] All verify-only dependency pages, metadata, scores, and formal blocks were preserved; only the direct renamed-path reverse-link dependency UID0001H7 required validator-backed synchronization (`12883`).
- [x] Every ordinary edit used one short lease, one scoped validation window, and immediate release; Validator Results records command IDs, timestamps, exits, `ok`, diagnostics, and side effects.
- [x] Old UID0003QH path is absent, the renamed path exists, UID0003QH is unique, and direct reverse links are current.
- [x] UID0004R2 is unique and no temporary helper UID token remains in the report or accepted ordinary destinations.
- [x] Final authorized waited UID0003UN validation completed as command `000000012896`, exit 0, `ok:1`, at `2026-07-15T05:38:06-04:00`.
- [x] Generated UserPane.cpp, SelfLookPane.cpp, and SystemMessagePanes.cpp were read back without manual edits; hashes and command headers are recorded under Validator Results.
- [x] After final generation, all four shared UserPane destinations were reread. The B004-first union remained intact; B003/B001/B002 were supervisor-held behind this lane and must rebase these bytes when resumed.
- [x] Generated output contains exactly one UID0003UN definition, one UID0003QH definition, and one UID0004R2 definition, with no duplicates.
- [x] Generated output contains zero UID0003UN/helper Empty Emitter Markers and zero rejected stale target/helper tokens within the three accepted segments.
- [x] Generated UID0003UN preserves duplicated branches, two `0x400` buffers, exact status/global split, sender/overlay/map effects, and block/listen replay.
- [x] C3UN-001 through C3UN-046 use legal terminal actions/states and have claim-by-claim destination/validator/generated proof.
- [x] Validator Results and Changed Files contain the exact callback commands, timestamps, diagnostics, hashes, side effects, and verify-only boundary.
- [x] Current-state wording is archive-neutral: report validation/execution/count/path/move/archive state remains external supervisor/validator-owned.
- [x] B004 manually edited no manual coverage, generated, tracker, audit/supervisor, validator-state, lifecycle, archive, queue, lock, or IDA file and ran no forbidden command.
- [x] Every B004 lease is released; the global lease report is empty and no accepted implementation item remains.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000012901","destination_path":"executed-b-agent-research/B004/0003UN-UserPaneHandleServerEntryPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0003UN-UserPaneHandleServerEntryPacket-source-quality.md","timestamp":"2026-07-15T06:07:28-04:00","uid":"0003UN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
