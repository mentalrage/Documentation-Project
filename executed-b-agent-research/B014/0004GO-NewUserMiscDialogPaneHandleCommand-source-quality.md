** TARGET-REPORT-UID:0004GO **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004GO - NewUserMiscDialogPane HandleCommand Source-Quality Report

## Finalized Report / Current Recommendation

Final disposition: source-ready first-draft implementation applied for [UID:0004GO][by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md].

Implemented action: the target child page now emits `NewUserMiscDialogPane::HandleCommand(int commandId, int notifyCode)` through [UID:00009F][by-class/NewUserMiscDialogPane.md], metadata is `COMPLETION:90` / `CONFIDENCE:92`, and the class/file/parent support pages are synchronized with current callback MCP session `ba171fe4`, switch-table, generated-output, and raw-helper evidence.

Confidence: high for ownership, range, virtual route, command cases, packet bytes, and source placement. Remaining uncertainty is limited to exact original source spellings for the virtual method alias, a few control helper names, and the two packet descriptor member names read from the render parameter structure; these are confidence caps, not blockers to first-draft source-shaped C++.

## Supporting Research

Historical report-only context: the initial UID0004GO report was produced without editing target/support by-* docs. Current callback state: B014 edited only the accepted target/support by-* docs, ran scoped file validators, and updated this same report ledger/checklist. B014 did not manually edit generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers. B014 did not run `execute_report`, dry-run/probe execution, or any report lifecycle/archive command.

The Gate 1 report used IDA MCP evidence from then-active session `cbc24146`; after the supervisor MCP incident/resume, callback implementation refreshed bounded route/boundary proof with active IDB-backed session `ba171fe4`. The target is historically entangled with adjacent NewUserMiscDialogPane split pages, so every claim below remains bound to the exact path and range `by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md`.

Prior support context checked:
- B013 split work for UID0002Q7 established that `0x004fc010-0x004fc57e` is an exact child command handler inside the NewUserMiscDialogPane aggregate, while `0x004fca20` and `0x004fcac0` are raw no-xref helper islands and not callable source helpers.
- UID0004GL, UID0004GQ, and UID0004GR already provide source-ready constructor, key-down, and help-handler siblings through owner [UID:00009F].
- Historical pre-callback generated lead: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` was read only and did not yet contain UID0004GO; current post-callback generated output is recorded under `Validator Results`.

## Target

- Target UID: `0004GO`
- Target path: [by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md](../../../../../by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md)
- Exact binary range under review: `0x004fc010-0x004fc57e`
- Source owner recommended: [UID:00009F][by-class/NewUserMiscDialogPane.md]
- Source file recommended: [UID:0000LX][by-file/NewUserMiscDialogPane.md], under the broader create-user/login dialog source route
- Current target role: virtual command handler for accept/cancel/gender/shape/style controls in `NewUserMiscDialogPane`

## Current Target State

Current target metadata after callback:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `90` |
| `CONFIDENCE` | `92` |
| `CANONICAL_OWNER` | `00009F` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00009F` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Formal C++ | inserted, `NewUserMiscDialogPane::HandleCommand(int commandId, int notifyCode)` |

The target now records the right owner/emitter, exact MCP size, vtable-only data xref, inline opcode `4` and opcode `21` packet sends, raw-helper rejection, callback MCP session `ba171fe4`, attached command-switch material at `0x004fc57e-0x004fc5c0`, local PE route scan facts, generated-output freshness, and source-facing support names for the packet/control behavior.

## Executive Recommendation

UID0004GO has been promoted from a blank-C++ command-handler note to a source-ready child emitter.

Applied target changes:
- Set `COMPLETION:90`.
- Set `CONFIDENCE:92`.
- Preserved `CANONICAL_OWNER:00009F`.
- Preserved `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:00009F`.
- Kept the emitter position blank.
- Inserted the exact formal `RECONSTRUCTION_CPP CODE` block from this report.

The implementation should model the command handler directly, not by migrating behavior into raw sender helpers at `0x004fca20` or `0x004fcac0`. The current MCP and local route evidence shows the live source route is the virtual handler slot at `0x0061d46c`, with packet construction inlined into the handler.

## Supervisor Active Recheck

Callback MCP-backed recheck was performed through the active IDB session after the supervisor MCP incident/resume:

| Check | Result |
| --- | --- |
| HTTP MCP client session | `7748e482-b62a-4bdf-9177-db6e819b5b97` |
| Active IDB worker session | `ba171fe4` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Input binary | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| `idb_list` | one active NexusTK worker, owned/adopted true, worker pid `12196` |
| `server_health` | `ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready |

Read-only local process/listener checks showed `idalib-mcp` running and the active Python worker process present. No IDB open/close, process management, rename/type mutation, or database mutation was performed.

## Inference Research Guidance Check

The source-quality question is not whether every original name is already recovered. It is whether the current behavior, range, owner, field/slot evidence, and support helpers are strong enough to infer a realistic first-draft source body. For UID0004GO, they are.

Inference decisions:
- Use `NewUserMiscDialogPane::HandleCommand(int commandId, int notifyCode)` because the target, class page, and current project documentation use `HandleCommand` for this virtual command route. A future class-declaration cleanup may rename the method to a project-wide `OnCommand` convention, but that is not a blocker to emitting this exact child body.
- Use source-facing control variables by constructor-assigned IDs: gender buttons `3/4`, shape controls `5/6/7/8`, direction buttons `9/10`, gender select boxes `11/12`, and style select boxes `13/14/15/16`.
- Use `PacketBufferWriteUInt8` and `g_packetSender->QueueAndSendPacket(...)` instead of raw `sub_575380`, `dword_67A7EC`, or `sub_574BB0`.
- Use inferred packet descriptor member names `shape` and `direction` for the two bytes read from the preview/render parameter structure. MCP proves the source bytes; exact original member spelling remains an open confidence cap.
- Use source-facing selection helpers such as `Select`, `ClearSelection`, and `SetSelected(false)` rather than emitting direct writes to control state bytes.

Rejected inference shortcuts:
- Do not leave the formal C++ blank solely because no local IDB UDT named `NewUserMiscDialogPane` or exact recovered method symbol exists.
- Do not model the raw helper islands as separate callable source helpers without route proof.
- Do not transfer ownership to `CashShopRequest`, `Socket`, `UserShapeSelectControlPane`, `SelectBoxControlPane`, or the broad create-user aggregate.

## Heuristic / Inference Reanalysis And Validation

Range and split: `lookup_funcs` reports `sub_4FC010` at `0x004fc010` with size `0x56e`, ending exactly at `0x004fc57e`. The next bytes are not ordinary padding for this child; they are attached switch material: `66 90` at `0x004fc57e-0x004fc580`, followed by sixteen dword destinations at `0x004fc580-0x004fc5c0`. The successor modeled function starts at `0x004fc5c0`. The target page's exact range is still correct, but support docs should stop describing `0x004fc57e-0x004fc5c0` as simple function-tail padding.

Source body decision: the decompile is an ordinary virtual command dispatcher. It fetches controls from the dialog control manager, switches on the command ID, queues create/cancel packets inline, changes gender/shape/style control state, and dismisses the dialog on cancel. These are source-level UI actions, not compiler artifacts.

Child-body decision: this target should emit only the command handler body. It should not duplicate constructor UID0004GL, key-down UID0004GQ, help UID0004GR, raw sender islands UID0004GT/UID0004GV, packet wrapper UID0004GP, or reply handler UID0004GX.

Remaining caps:
- Exact original name may be `OnCommand` instead of `HandleCommand`; the current target-facing documentation uses `HandleCommand`.
- Exact class declarations for several control helpers are not recovered in the IDB.
- The packet parameter bytes at preview offsets `+0x04` and `+0x21` are behavior-proven but source member names are inferred.
- The function is reached through a vtable pointer and has no direct code callers, so runtime route confidence is high but not a direct-call proof.

## Evidence Standards Used

Evidence ladder applied for this report:

| Standard | How it was used |
| --- | --- |
| Current IDA MCP function evidence | Gate 1 used full behavior evidence from session `cbc24146`; callback implementation refreshed bounded health, function, xref, byte, and pointer-pattern proof from active session `ba171fe4` after the supervisor MCP incident. |
| Boundary proof | Function start/size, predecessor byte, endpoint bytes, switch-table bytes, successor lookup, and xrefs to target/end/successor were checked before recommending a body. |
| Route proof | Vtable/data xref, zero direct code xrefs, local PE VA/RVA pointer scan, and rel32 branch scan were separated so vtable-only reachability remains a confidence cap rather than a no-code blocker. |
| Source-quality inference | Existing support docs for packet sending, controls, dialog close helpers, and sibling NewUserMisc handlers were preferred over raw IDA names. |
| Negative evidence | No local UDT/source method symbols and zero route to raw helpers were recorded explicitly, not silently ignored. |
| Callback discipline | B014 applied accepted target/support by-* edits, ran scoped file validators only, updated this report, and did not run report execution/archive/lifecycle commands. |

## Evidence Checked

Accepted Gate 1 behavior evidence was gathered from MCP session `cbc24146`. After the supervisor MCP incident, B014 did not rely on that stale session for callback liveness; bounded callback recheck used active MCP session `ba171fe4` and reconfirmed the implementation-critical route/boundary facts.

Callback MCP session `ba171fe4` checks:

| Command family | Evidence |
| --- | --- |
| `idb_list` | One active NexusTK worker, session `ba171fe4`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active true, analyzing false, worker pid `12196`. |
| `server_health` | `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready. |
| `lookup_funcs` | `0x004fc010` is `sub_4FC010`, size `0x56e`; `0x004fc57e` is not a function; `0x004fc5c0` is `sub_4FC5C0`, size `0x26`; raw helper starts `0x004fca20` and `0x004fcac0` are not functions. |
| `xrefs_to` | `0x004fc010` has one data xref at `0x0061d46c`; `0x004fc57e`, `0x004fca20`, and `0x004fcac0` have zero xrefs. |
| `xref_query` | Code xrefs to `0x004fc010` are zero; data xref is only `0x0061d46c -> 0x004fc010`; raw helper starts have zero backward xrefs. |
| `get_bytes` | Bytes from `0x004fc560` reconfirm the function epilogue, `c2 08 00`, `66 90` alignment at `0x004fc57e`, and sixteen command-switch dwords through `0x004fc5bc`; vtable slot bytes at `0x0061d46c` are `10 c0 4f 00`. |
| `find_bytes` | Target VA pattern `10 c0 4f 00` appears only at `0x0061d46c`; raw helper VA patterns `20 ca 4f 00` and `c0 ca 4f 00` have zero hits; target-end VA pattern `7e c5 4f 00` has zero hits. |

Accepted Gate 1 behavior evidence retained from the original report:

| Command family | Evidence |
| --- | --- |
| `callees` | Target calls `0x004fcfc0`, `0x00575380`, `0x00574bb0`, `0x004f4aa0`, `0x00559b90`, `0x0049eb90`, `0x0049dad0`, `0x004fd030`, `0x004fd050`, `0x004fd0d0`, `0x004fd070`, `0x004fd140`, `0x004fcd80`, and `@__security_check_cookie@4`. |
| `decompile` | Confirms `__thiscall` command handler shape, `ret 8`, unused second argument, control fetches by IDs `3..16`, command cases `1..16`, inline opcode `4` length `5`, opcode `21` length `1`, dialog close calls, gender/shape/style state changes, and step-forward/step-backward edge behavior. |
| `disasm` | Confirms switch through `jpt_4FC191`, packet writes at `0x004fc232`, `0x004fc246`, `0x004fc25a`, `0x004fc273`, `0x004fc280`, send at `0x004fc29e`, cancel send at `0x004fc300`, close calls at `0x004fc30b` and `0x004fc316`, and selection/invalidation stores for controls. |
| `entity_query` / `type_query` | No source-quality saved function name, no local recovered `NewUserMisc*` UDT, and no local recovered `ControlPane` UDT records were found; these remain confidence caps only. |

Read-only local PE route scan:

| Pattern | Result |
| --- | --- |
| Target VA dword `0x004fc010` | one hit at raw `0x21be6c`, VA `0x0061d46c`, in `.rdata` |
| Target RVA dword `0x000fc010` | zero hits |
| Raw helper VA/RVA dwords for `0x004fca20`, `0x004fcac0` | zero hits |
| End VA/RVA dwords for `0x004fc57e` | zero hits |
| Exact rel32 call/jump to target or raw helper starts | zero hits |

Generated output check:
- Historical pre-callback generated lead: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` command `000000006520`, refreshed `2026-07-04T19:37:20-04:00`, did not contain UID0004GO.
- Current post-callback generated output: command `000000006602`, refreshed `2026-07-04T20:53:54-04:00`, contains one UID0004GO block at `Completion:90` / `Confidence:92` and one `NewUserMiscDialogPane::HandleCommand(int commandId, int notifyCode)` body.
- Current generated output has zero references to raw-helper bodies/pages `NewUserMiscDialogPaneRawCreateRequestSender`, `NewUserMiscDialogPaneRawCancelRequestSender`, `0x004fca20`, or `0x004fcac0`.

## Positive Evidence Summary

- Exact modeled function exists at `0x004fc010`, size `0x56e`, matching the target page range.
- The only inbound pointer is the class vtable slot at `0x0061d46c`, which matches a virtual command-handler route.
- The handler fetches the same controls created by the NewUserMiscDialogPane constructor: gender buttons, shape selectors, direction buttons, gender select boxes, and style select boxes.
- Command case `1` builds the create/misc request packet inline: opcode `4`, two descriptor bytes from the selected shape preview params, a gender byte, a style byte, and length `5`.
- Command case `2` builds the cancel packet inline: opcode `21`, length `1`, then slide-closes and closes the dialog.
- Command cases `3/4` switch the four shape selectors between male/female banks and update the two gender buttons.
- Command cases `5/6/7/8` maintain single-selection behavior for the four shape selector panes.
- Command cases `9/10` step backward/forward through available shapes and maintain direction-button edge state.
- Command cases `11/12` maintain single-selection behavior for the gender select boxes.
- Command cases `13/14/15/16` maintain single-selection behavior for the four style select boxes.
- Existing support pages identify source-facing packet and dialog helper dependencies: `PacketBufferWriteUInt8`, `Socket::QueueAndSendPacket`, `DialogPane::SlideCloseVertical`, and `DialogPane::CloseDialog`.

## Negative Evidence Summary

- There are no direct code callers to `0x004fc010`; reachability is vtable-only.
- No local IDB source-quality function name or `NewUserMiscDialogPane` UDT is recovered for this method.
- No local `ControlPane` UDT was recovered by MCP type queries.
- Raw sender starts `0x004fca20` and `0x004fcac0` are not IDA functions and have zero direct xrefs.
- Local PE scan found no VA/RVA/rel32 route to the raw sender starts.
- The bytes at `0x004fc57e-0x004fc5c0` are attached switch data, not a source body and not plain tail padding.
- The handler's exact original method name may be `OnCommand` in source even though the target path and current documentation use `HandleCommand`.

## Range / Split / Padding / Reclassification Analysis

The exact function range remains `0x004fc010-0x004fc57e`. The byte before the function is `0xcc`, and the function ends with the expected epilogue and `retn 8`.

Attached material immediately after the function:

| Address | Bytes / dword | Interpretation |
| --- | --- | --- |
| `0x004fc57e-0x004fc580` | `66 90` | two-byte alignment before switch table |
| `0x004fc580` | `0x004fc198` | command-switch destination |
| `0x004fc584` | `0x004fc2d9` | command-switch destination |
| `0x004fc588` | `0x004fc320` | command-switch destination |
| `0x004fc58c` | `0x004fc385` | command-switch destination |
| `0x004fc590` | `0x004fc488` | command-switch destination |
| `0x004fc594` | `0x004fc4ac` | command-switch destination |
| `0x004fc598` | `0x004fc4b0` | command-switch destination |
| `0x004fc59c` | `0x004fc4bd` | command-switch destination |
| `0x004fc5a0` | `0x004fc3cd` | command-switch destination |
| `0x004fc5a4` | `0x004fc437` | command-switch destination |
| `0x004fc5a8` | `0x004fc4dd` | command-switch destination |
| `0x004fc5ac` | `0x004fc4e5` | command-switch destination |
| `0x004fc5b0` | `0x004fc4ed` | command-switch destination |
| `0x004fc5b4` | `0x004fc50f` | command-switch destination |
| `0x004fc5b8` | `0x004fc517` | command-switch destination |
| `0x004fc5bc` | `0x004fc539` | command-switch destination |

Recommendation: keep target `0x004fc010-0x004fc57e` as the source body, but update parent/support docs to identify `0x004fc57e-0x004fc5c0` as attached switch/alignment material rather than generic tail padding.

## Function / Child Inventory

| Range | Current role | UID / status |
| --- | --- | --- |
| `0x004fb630-0x004fbfcf` | constructor | UID0004GL, source-ready sibling |
| `0x004fbfcf-0x004fbfd0` | one-byte constructor padding | UID0004GM |
| `0x004fbfd0-0x004fc00f` | raw cleanup island | UID0004GN, no-function/no-route |
| `0x004fc010-0x004fc57e` | command handler under review | UID0004GO, recommend source-ready |
| `0x004fc57e-0x004fc5c0` | alignment plus command switch table | support correction recommended |
| `0x004fc5c0-0x004fc5e6` | packet wrapper | UID0004GP |
| `0x004fc5e6-0x004fc5f0` | wrapper padding | local padding |
| `0x004fc5f0-0x004fc77c` | key-down handler | UID0004GQ, source-ready sibling |
| `0x004fc780-0x004fc9e7` | control-help handler | UID0004GR, source-ready sibling |
| `0x004fc9e8-0x004fca20` | help switch table | UID0004GS |
| `0x004fca20-0x004fcab8` | raw create request sender | UID0004GT, no-function/no-route |
| `0x004fcab8-0x004fcac0` | packet helper padding | UID0004GU |
| `0x004fcac0-0x004fcb04` | raw cancel request sender | UID0004GV, no-function/no-route |
| `0x004fcb04-0x004fcb10` | reply padding | UID0004GW |
| `0x004fcb10-0x004fccee` | create-character reply handler | UID0004GX |

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Rationale |
| ---: | --- | --- | --- |
| 1 | [UID:00009F][by-class/NewUserMiscDialogPane.md] | Accept | The target is reached through the NewUserMiscDialogPane vtable slot, consumes constructor-created NewUserMisc controls, and belongs with existing source-ready siblings UID0004GL/GQ/GR. |
| 2 | [UID:0000LX][by-file/NewUserMiscDialogPane.md] | Accept as file route | The file already owns this class route and generated source for sibling bodies. |
| 3 | [UID:0000IK][by-file/CreateUserDialogs.md] | Reject as direct emitter | It is an umbrella route only; the exact child body belongs to NewUserMiscDialogPane. |
| 4 | CashShop/request/socket code | Reject | Packet send helpers are dependencies; the handler owns the UI decisions and packet payload construction. |
| 5 | UserShapeSelectControlPane / SelectBoxControlPane / DirectionButtonControlPane | Reject | Their methods are dependencies and controls are consumers here, not owner transfer. |
| 6 | Raw helper islands `0x004fca20` / `0x004fcac0` | Reject | No IDA functions, no direct xrefs, no VA/RVA/rel32 route. They should not replace this source handler. |
| 7 | No-owner/no-code | Reject | The behavior is complete source-level UI code with a class vtable route. Missing exact UDTs/names are confidence caps only. |

## Source Placement

Place the emitted body in the `NewUserMiscDialogPane` source route:

- Class owner: [UID:00009F][by-class/NewUserMiscDialogPane.md]
- File owner: [UID:0000LX][by-file/NewUserMiscDialogPane.md]
- Likely source path: `NexusTK/login/NewUserMiscDialogPane.cpp`
- Emitter for target: `00009F`

The target page title and current docs call the method `HandleCommand`; the first-draft C++ keeps that source-facing name. If a later class-declaration pass standardizes virtual dialog command handlers as `OnCommand`, that should be treated as a spelling/layout cleanup, not a reason to leave UID0004GO blank now.

## IDA Rename / Type / Comment Recommendations

Future IDA/database annotation recommendations remain informational only:

| Address / entity | Recommendation | Reason |
| --- | --- | --- |
| `0x004fc010` | Rename from `sub_4FC010` to `NewUserMiscDialogPane_HandleCommand` or equivalent IDA-safe name | Current MCP behavior proves the virtual command handler role. |
| `0x0061d46c` | Comment as NewUserMiscDialogPane command-handler vtable slot | It is the only inbound pointer to the function. |
| `0x004fc57e-0x004fc5c0` | Comment as command switch alignment/table for `0x004fc010` | Prevents future stale "tail padding" classification. |
| `0x004fca20` / `0x004fcac0` | Keep no-function/no-route comments | They remain raw sender islands with no callable route proof. |
| Preview parameter bytes `+0x04` and `+0x21` | Add source comment if type recovery is attempted | They become packet descriptor bytes in opcode `4`. |

No IDA rename, type, comment, or database mutation was performed during the report-only pass or implementation callback.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0004GO should be promoted to `COMPLETION:90`, `CONFIDENCE:92`. | High | Complete command behavior, exact range, source dependencies, and vtable route are MCP-backed; unresolved names are only caps. | Target metadata | incorporate | applied: target metadata now `90/92`; validator `000000006602` recorded completion/confidence updates. |
| C02 | Preserve owner `00009F`, reconstructable true, and set emitter to `00009F`. | High | Vtable slot, class controls, and sibling generated route all point to NewUserMiscDialogPane. | Target metadata | incorporate | applied: owner/reconstructable preserved and `EMITTER_UIDS:00009F`; validator `000000006602` updated emitter registry. |
| C03 | Insert formal source body for `NewUserMiscDialogPane::HandleCommand(int,int)`. | High | Decompile/disasm prove all command cases and packet sends. | Target `RECONSTRUCTION_CPP CODE` block | incorporate | applied: exact formal block inserted in target and generated output contains one `HandleCommand` body. |
| C04 | Record current callback MCP session `ba171fe4` and health/session evidence after stale `cbc24146` was discarded. | High | `idb_list` and `server_health` returned active IDB, Hex-Rays ready, strings cache ready. | Target evidence and support notes | incorporate | applied: target/class/file/parent and report now cite callback session `ba171fe4`. |
| C05 | Record exact range `0x004fc010-0x004fc57e`, size `0x56e`. | High | `lookup_funcs 0x004fc010`. | Target evidence | incorporate | applied: target and support docs record exact range/size. |
| C06 | Record attached switch material `0x004fc57e-0x004fc5c0`. | High | `get_bytes` shows `66 90` plus sixteen dword destinations. | Target evidence; parent aggregate row | incorporate | applied: target table and parent aggregate row/bytes note added. |
| C07 | Historicalize generic tail-padding wording for `0x004fc57e-0x004fc5c0`. | High | Current bytes are switch data, not `0xcc` padding. | Parent aggregate/support docs | historicalize | applied: parent now says attached command switch material supersedes generic tail-padding wording. |
| C08 | Record vtable-only xref `0x0061d46c` and no direct code callers. | High | `xrefs_to`, `xref_query`, local PE route scan. | Target evidence; class/file support | incorporate | applied: target/class/file/parent record vtable-only slot and zero direct callers. |
| C09 | Record local PE route facts: one target VA dword at vtable slot, no RVA/direct rel32, no raw-helper route. | High | Read-only PE scan and callback `find_bytes`. | Target and support evidence | incorporate | applied: target and support docs record pointer-pattern/no-route facts. |
| C10 | Preserve raw helper rejection for `0x004fca20` and `0x004fcac0`. | High | Not functions, zero xrefs, zero route hits. | Target helper-route caveat; parent rows; raw sender pages | reject-invalid | applied: target/class/file/parent preserve rejection; raw sender pages already present at same-or-greater detail and were not edited. |
| C11 | Record command case `1` opcode `4`, length `5`, selected shape/gender/style bytes. | High | Decompile/disasm packet writes and send call. | Target behavior notes; C++ body | incorporate | applied: target evidence and C++ body include opcode `4` length `5` path. |
| C12 | Record command case `2` opcode `21`, length `1`, slide-close and close. | High | Decompile/disasm packet writes and close calls. | Target behavior notes; C++ body | incorporate | applied: target evidence and C++ body include opcode `21` / `0x15` length `1` path. |
| C13 | Record gender/shape/style control command behavior. | High | Decompile/disasm cases `3..16` and control IDs. | Target behavior notes; class/file support | incorporate | applied: target C++ and support rows record cases `3..16` at report-level detail. |
| C14 | Record no recovered local source-quality UDT/name for `NewUserMiscDialogPane` or control types. | Medium-high | `entity_query` and `type_query`. | Target evidence/open questions | incorporate | applied: target evidence and report open questions retain type/name limitations. |
| C15 | Keep exact method-name spelling as confidence cap, not blocker. | Medium-high | Existing docs use `HandleCommand`; broader dialog convention may use `OnCommand`. | Target notes; open questions | incorporate | applied: target status/open caveat preserves spelling cap while emitting body. |
| C16 | Update by-class and by-file rows so UID0004GO is source-ready. | High | Target C++ recommendation and sibling emission route. | `by-class/NewUserMiscDialogPane.md`, `by-file/NewUserMiscDialogPane.md` | incorporate | applied: class/file rows and changes sections updated; validators `000000006599` and `000000006600` passed. |
| C17 | Update parent aggregate to preserve child-body split and correct switch-table boundary. | High | Parent needed source-ready child row and switch-material row. | `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | incorporate | applied: parent row and switch material added; validator `000000006601` passed. |
| C18 | Do not manually edit generated/coverage/validator/lifecycle files during callback except validator-owned refresh side effects. | High | Project workflow rule and user instruction. | Implementation checklist | not-applicable | applied: B014 manually edited only by-* docs and this report; validator-owned generated/tracker/coverage/state side effects are reported. |

## First-Draft C++ Recommendation

The following exact formal block was inserted into the target page. The body is source-shaped; it intentionally avoids raw `sub_`, `dword_`, `off_`, `unk_`, and decompiler-temporary names. The exact original spelling of `HandleCommand` versus `OnCommand`, and the exact packet descriptor member names, remain documented confidence caps.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
    enum NewUserMiscCommandId
    {
        kCommandAccept = 1,
        kCommandCancel = 2,
        kCommandMaleMode = 3,
        kCommandFemaleMode = 4,
        kCommandShape0 = 5,
        kCommandShape1 = 6,
        kCommandShape2 = 7,
        kCommandShape3 = 8,
        kCommandPreviousShape = 9,
        kCommandNextShape = 10,
        kCommandMaleBox = 11,
        kCommandFemaleBox = 12,
        kCommandStyle0 = 13,
        kCommandStyle1 = 14,
        kCommandStyle2 = 15,
        kCommandStyle3 = 16
    };

    const unsigned char kCreateMiscCharacterOpcode = 0x04;
    const unsigned char kCancelCreateCharacterOpcode = 0x15;
    const short kCreateMiscCharacterPacketSize = 5;
    const short kCancelCreateCharacterPacketSize = 1;
    const int kCreateMiscDimmerLevel = 5;
}

void NewUserMiscDialogPane::HandleCommand(int commandId, int notifyCode)
{
    (void)notifyCode;

    DirectionButtonControlPane *previousShapeButton =
        static_cast<DirectionButtonControlPane *>(m_controlManager->GetControl(9));
    DirectionButtonControlPane *nextShapeButton =
        static_cast<DirectionButtonControlPane *>(m_controlManager->GetControl(10));

    ControlPane *maleModeButton = m_controlManager->GetControl(3);
    ControlPane *femaleModeButton = m_controlManager->GetControl(4);

    UserShapeSelectControlPane *shape0 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(5));
    UserShapeSelectControlPane *shape1 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(6));
    UserShapeSelectControlPane *shape2 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(7));
    UserShapeSelectControlPane *shape3 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(8));

    SelectBoxControlPane *maleBox =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(11));
    SelectBoxControlPane *femaleBox =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(12));
    SelectBoxControlPane *style0 =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(13));
    SelectBoxControlPane *style1 =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(14));
    SelectBoxControlPane *style2 =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(15));
    SelectBoxControlPane *style3 =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(16));

    switch (commandId)
    {
    case kCommandAccept:
    {
        UserShapeSelectControlPane *selectedShape = shape3;
        if (shape0->IsSelected())
            selectedShape = shape0;
        else if (shape1->IsSelected())
            selectedShape = shape1;
        else if (shape2->IsSelected())
            selectedShape = shape2;

        HumanImageRenderParams previewParams;
        selectedShape->BuildPreviewParams(&previewParams);

        unsigned char gender = maleBox->IsSelected() ? 1 : 2;

        unsigned char style = 3;
        if (style0->IsSelected())
            style = 0;
        else if (style1->IsSelected())
            style = 1;
        else if (style2->IsSelected())
            style = 2;

        unsigned char packet[kCreateMiscCharacterPacketSize + 1];
        PacketBufferWriteUInt8(kCreateMiscCharacterOpcode, &packet[0]);
        PacketBufferWriteUInt8(previewParams.shape, &packet[1]);
        PacketBufferWriteUInt8(previewParams.direction, &packet[2]);
        PacketBufferWriteUInt8(gender, &packet[3]);
        PacketBufferWriteUInt8(style, &packet[4]);
        packet[kCreateMiscCharacterPacketSize] = 0;

        g_packetSender->QueueAndSendPacket(packet, kCreateMiscCharacterPacketSize);
        new ScreenDimmer(kCreateMiscDimmerLevel, g_pScreenPane);
        return;
    }

    case kCommandCancel:
    {
        unsigned char packet[kCancelCreateCharacterPacketSize + 1];
        PacketBufferWriteUInt8(kCancelCreateCharacterOpcode, &packet[0]);
        packet[kCancelCreateCharacterPacketSize] = 0;

        g_packetSender->QueueAndSendPacket(packet, kCancelCreateCharacterPacketSize);
        SlideCloseVertical();
        CloseDialog();
        return;
    }

    case kCommandMaleMode:
        shape0->SetMaleShapeBank();
        shape1->SetMaleShapeBank();
        shape2->SetMaleShapeBank();
        shape3->SetMaleShapeBank();
        maleModeButton->Select();
        femaleModeButton->ClearSelection();
        return;

    case kCommandFemaleMode:
        shape0->SetFemaleShapeBank();
        shape1->SetFemaleShapeBank();
        shape2->SetFemaleShapeBank();
        shape3->SetFemaleShapeBank();
        femaleModeButton->Select();
        maleModeButton->ClearSelection();
        return;

    case kCommandShape0:
        shape1->SetSelected(false);
        shape2->SetSelected(false);
        shape3->SetSelected(false);
        return;

    case kCommandShape1:
        shape0->SetSelected(false);
        shape2->SetSelected(false);
        shape3->SetSelected(false);
        return;

    case kCommandShape2:
        shape0->SetSelected(false);
        shape1->SetSelected(false);
        shape3->SetSelected(false);
        return;

    case kCommandShape3:
        shape0->SetSelected(false);
        shape1->SetSelected(false);
        shape2->SetSelected(false);
        return;

    case kCommandPreviousShape:
        if (shape0->StepShapeBackward() == -1)
        {
            shape1->StepShapeBackward();
            shape2->StepShapeBackward();
            shape3->StepShapeBackward();
            previousShapeButton->ClearSelection();
        }
        else
        {
            shape1->StepShapeBackward();
            shape2->StepShapeBackward();
            shape3->StepShapeBackward();
            if (!nextShapeButton->IsSelected())
                nextShapeButton->Select();
        }
        return;

    case kCommandNextShape:
        if (shape3->StepShapeForward() == -1)
        {
            shape0->StepShapeForward();
            shape1->StepShapeForward();
            shape2->StepShapeForward();
            nextShapeButton->ClearSelection();
        }
        else
        {
            shape0->StepShapeForward();
            shape1->StepShapeForward();
            shape2->StepShapeForward();
            if (!previousShapeButton->IsSelected())
                previousShapeButton->Select();
        }
        return;

    case kCommandMaleBox:
        femaleBox->SetSelected(false);
        return;

    case kCommandFemaleBox:
        maleBox->SetSelected(false);
        return;

    case kCommandStyle0:
        style1->SetSelected(false);
        style2->SetSelected(false);
        style3->SetSelected(false);
        return;

    case kCommandStyle1:
        style0->SetSelected(false);
        style2->SetSelected(false);
        style3->SetSelected(false);
        return;

    case kCommandStyle2:
        style0->SetSelected(false);
        style1->SetSelected(false);
        style3->SetSelected(false);
        return;

    case kCommandStyle3:
        style0->SetSelected(false);
        style1->SetSelected(false);
        style2->SetSelected(false);
        return;

    default:
        return;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Final Recommendation

UID0004GO is now implemented as source-ready at `90/92` with formal first-draft C++ inserted into the target child page. The strong evidence is the complete MCP-backed command switch, exact packet writes/sends, existing source-facing dependency pages, exact NewUserMiscDialogPane ownership, and one-slot vtable route. The remaining unknowns are documented as confidence caps rather than blank-C++ blockers.

## Recommended Target Doc Changes

Applied to [by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md](../../../../../by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md):

- Set `COMPLETION:90`.
- Set `CONFIDENCE:92`.
- Preserved `CANONICAL_OWNER:00009F`.
- Preserved `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:00009F`.
- Kept `EMITTER_POSITION_OPTIONAL` blank.
- Inserted the exact formal `RECONSTRUCTION_CPP CODE` block from this report.
- Added callback MCP session `ba171fe4` evidence, including exact range, vtable xref, no direct code xrefs, callee/helper names from the accepted report, no UDT/name recovery, local PE route results, and generated output state.
- Recorded `0x004fc57e-0x004fc5c0` as attached command switch material, including the exact bytes/dwords listed above.
- Preserved the raw-helper caveat: do not rewrite this handler as calls to `0x004fca20` or `0x004fcac0`.
- Documented that `HandleCommand` versus `OnCommand`, and the packet descriptor member spellings, are confidence caps only.

## Recommended Support Doc Changes

Applied support sync only where stale or incomplete:

| Support doc | Recommended update |
| --- | --- |
| [by-class/NewUserMiscDialogPane.md](../../../../../by-class/NewUserMiscDialogPane.md) | Applied: UID0004GO is source-ready through [UID:00009F], with inline opcode `4`/`21` packet sends, vtable-only route, callback MCP `ba171fe4`, and formal C++ now available. Raw helper no-route caveats for UID0004GT/GV are preserved. |
| [by-file/NewUserMiscDialogPane.md](../../../../../by-file/NewUserMiscDialogPane.md) | Applied: `NewUserMiscDialogPane.cpp` route now includes the UID0004GO command body after callback. Umbrella `CreateUserDialogs` caveat and sibling unresolved/raw islands are preserved. |
| [by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md](../../../../../by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) | Applied: UID0004GO row is source-ready and `0x004fc57e-0x004fc5c0` is now attached command switch alignment/table. The parent aggregate remains non-emitting. |
| [by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md](../../../../../by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md) | Already present at same-or-greater detail; not edited. It preserves no-function/no-route and notes UID0004GO owns the live inline opcode `4` send. |
| [by-memory/0x004fcac0-0x004fcb04.NewUserMiscDialogPaneRawCancelRequestSender.md](../../../../../by-memory/0x004fcac0-0x004fcb04.NewUserMiscDialogPaneRawCancelRequestSender.md) | Already present at same-or-greater detail; not edited. It preserves no-function/no-route and notes UID0004GO owns the live inline opcode `21` send. |
| Packet/control helper docs | Already present / not edited. No ownership migration to packet sender, screen dimmer, shape selector, direction button, gender button, or select-box classes. |

## Score And Metadata Recommendation

| Field | Before callback | Current | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `84` | `90` | Full command behavior, range, switch material, packet sends, support helpers, and source-shaped body are established. |
| `CONFIDENCE` | `91` | `92` | MCP/local evidence is strong and current; confidence remains capped by vtable-only reachability and exact source spelling/type recovery. |
| `CANONICAL_OWNER` | `00009F` | `00009F` | Vtable slot and control consumers prove NewUserMiscDialogPane ownership. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | This is source-authored UI command logic. |
| `EMITTER_UIDS` | blank | `00009F` | Child should emit through its class owner. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No special insertion order is needed beyond child emission. |

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Remaining impact | Future evidence needed |
| --- | --- | --- | --- |
| Was the original method called `HandleCommand` or `OnCommand`? | Compared target/class/file docs and sibling generated style. Existing docs use `HandleCommand`; broader dialog convention may use `OnCommand`. | Confidence cap only; target-facing first draft uses `HandleCommand`. | Future recovered source/header or class declaration pass. |
| What are the exact source member names for the two preview parameter bytes read at offsets `+0x04` and `+0x21`? | Decompile/disasm prove the bytes become packet payload bytes after `BuildPreviewParams`; sibling create-user code uses shape/direction-style packet fields. | Confidence cap only; first draft uses `shape` and `direction`. | Recovered `HumanImageRenderParams` declaration or broader renderer type pass. |
| Are `Select` / `ClearSelection` exact helper spellings for direction/gender controls? | Sibling key-down implementation and control-state vtable calls support source-facing selection helpers. | Confidence cap only; behavior and target offsets are clear. | Recovered control class declarations. |
| Should raw sender islands become callable source helpers? | MCP and PE route checks found no functions, no xrefs, and no pointer/branch route to `0x004fca20` or `0x004fcac0`. | Resolved against helper calls for this target. | Only a future source import could override the route evidence. |
| Is `0x004fc57e-0x004fc5c0` padding or switch data? | `get_bytes` proves two-byte alignment and sixteen destination dwords. | Resolved: support docs should call it attached switch material. | None needed for current callback. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or tracker text is recommended for B014 to edit. Coverage, tracker, and generated refresh state should remain validator/supervisor-owned. After an implementation callback, scoped file validators may update generated output; B014 should report those side effects but should not manually edit generated or coverage files.

## Validator Results

Scoped validators were run from `source-3/project-documentation` for every changed by-* doc:

| Command ID | Timestamp | Command | Exit | OK | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `000000006599` | `2026-07-04T20:53:30-04:00` | `python .\tools\validator.py --mode file --file by-class/NewUserMiscDialogPane.md --apply --queue-timeout 240` | 0 | 1 | Validator-owned registry/projected-stats refresh; generated refresh deferred. |
| `000000006600` | `2026-07-04T20:53:40-04:00` | `python .\tools\validator.py --mode file --file by-file/NewUserMiscDialogPane.md --apply --queue-timeout 240` | 0 | 1 | Validator-owned projected-stats refresh; generated refresh deferred. |
| `000000006601` | `2026-07-04T20:53:46-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md --apply --queue-timeout 240` | 0 | 1 | Validator-owned projected-stats refresh; generated refresh deferred. |
| `000000006602` | `2026-07-04T20:53:54-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md --apply --queue-timeout 240 --wait-generated` | 0 | 1 | Completion/confidence/emitter registry updates, generated refresh completed, `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` updated. |

Validator-owned side effects reported by command `000000006602`: `autogen_cpp_update` for `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp`, `research_tracker_update` for `auto-generated/-ag-research-tracker.md`, `memory_auto_coverage_update` for `auto-generated/-ag-coverage-report-by-memory.md`, generated metadata refreshes, `validator.ini` registry rebuild, and backup directories under `tools/validator_autogen_backup/`. These were tool-owned effects, not manual B014 edits. Non-target generated notes such as `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code` were pre-existing/broad generator diagnostics and did not block the scoped target.

Generated freshness: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` now has `validator-command-id: 000000006602` and `validator-refreshed-at: 2026-07-04T20:53:54-04:00`, matching the final target validator. Read-only check found one `UID:0004GO` block, one `NewUserMiscDialogPane::HandleCommand(int commandId, int notifyCode)` body, and zero raw-helper body/page references for `NewUserMiscDialogPaneRawCreateRequestSender`, `NewUserMiscDialogPaneRawCancelRequestSender`, `0x004fca20`, or `0x004fcac0`.

## Changed Files

Manual B014 edits:

- `by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md`
- `by-class/NewUserMiscDialogPane.md`
- `by-file/NewUserMiscDialogPane.md`
- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`
- `tools/leaser/Agents/Agent-B014/research/0004GO-NewUserMiscDialogPaneHandleCommand-source-quality.md`

Verification-only, not edited:

- `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md`
- `by-memory/0x004fcac0-0x004fcb04.NewUserMiscDialogPaneRawCancelRequestSender.md`
- Packet/control helper docs

Validator-owned side effects, not manually edited by B014:

- `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- generated coverage metadata reports
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`
- `tools/validator_autogen_backup/20260704-205404`, `20260704-205407`, `20260704-205410`

Forbidden lifecycle scope not run/touched manually: `execute_report`, dry-run/probe execution, lifecycle/archive commands, manual report moves, coverage-report edits, generated-file edits, validator-state edits, and supervisor-ledger edits.

Leases: B014 leased the four changed by-* docs for the edit/validator batch. The cleanup `unlease` command after validators returned `Rejected[No active lease]` for all four paths, and a read of `tools/leaser/Agents/current_leases.md` showed no active B014 leases remaining.

## Implementation Tracking Checklist

- [x] Update target metadata to `COMPLETION:90`, `CONFIDENCE:92`, owner `00009F`, `RECONSTRUCTABLE:TRUE`, emitter `00009F`, blank optional position. Applied in target; validator `000000006602` recorded completion/confidence/emitter updates.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report into the target page. Applied in target and generated output.
- [x] Add current callback MCP session `ba171fe4` evidence to the target: exact range/size, vtable-only xref, zero direct callers, accepted decompile/disasm behavior, callee/helper semantics, bytes, no recovered UDTs/names, and local PE route scan. Applied in target and support; historical `cbc24146` is no longer presented as the active callback session.
- [x] Document `0x004fc57e-0x004fc5c0` as attached command switch material with exact `66 90` alignment and sixteen dword destinations. Applied in target and parent aggregate.
- [x] Preserve raw helper rejection for `0x004fca20` and `0x004fcac0`. Applied in target/class/file/parent; raw sender pages were already present at same-or-greater detail and not edited.
- [x] Update `by-class/NewUserMiscDialogPane.md` so UID0004GO is source-ready through UID00009F while preserving unrelated raw-helper/destructor caveats. Applied; validator `000000006599` passed.
- [x] Update `by-file/NewUserMiscDialogPane.md` so generated/source route expectations include UID0004GO after callback. Applied; validator `000000006600` passed.
- [x] Update `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` if stale, especially the attached switch material and source-ready child row. Applied; validator `000000006601` passed.
- [x] Inspect raw create/cancel sender pages and edit only if they contradict the accepted no-route/inline-owner conclusion. Inspected; both already preserved no-function/no-route and UID0004GO inline-owner facts, so no edit was needed.
- [x] Run scoped validators for each changed by-* file and record command IDs, timestamps, exit codes, ok counts, and warnings. Completed with commands `000000006599` through `000000006602`, all exit 0 and `ok:1`.
- [x] Check validator-owned generated freshness for `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp`; expected post-callback state is one UID0004GO command-handler body and no duplicate raw-helper body. Confirmed command `000000006602`, one UID0004GO block, one `HandleCommand` body, zero raw-helper body/page references.
- [x] Update this report's ledger/checklist after callback with `applied`, `already-present`, `excluded-with-reason`, or `blocked` states and exact proof. Completed.
- [x] Do not edit generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers manually. Complied; validator-owned side effects are listed above.
- [x] Do not run `execute_report`, dry-run/probe execution variants, or lifecycle/archive commands. Complied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000006626","destination_path":"executed-b-agent-research/B014/0004GO-NewUserMiscDialogPaneHandleCommand-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0004GO-NewUserMiscDialogPaneHandleCommand-source-quality.md","timestamp":"2026-07-04T21:05:21-04:00","uid":"0004GO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
