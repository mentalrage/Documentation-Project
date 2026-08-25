** TARGET-REPORT-UID:0002QS **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002QS NewCreateUserDialogPaneCore Source-Quality Research


## Finalized Report / Current Recommendation

- Current implementation result: supervisor Gate 1 accepted this report at SHA `8D38B1164C0DF3323DF5F8454FD2BA6A4DF309C3EF86CBDB0CEBA8A9E01EE37A`; the callback has now applied the accepted [UID:0002QS] target repair to `88/91`, updated the formal C++ and boundary notes, and corrected the two accepted support-doc singleton contradictions.
- Final disposition: keep `CANONICAL_OWNER:00008Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008Z`, and blank optional emitter position. Do not collapse this target into `CreateUserDialogs`, `CreateUserDialogPane`, `NewUserDialogPane2`, or the vtable/global support pages.
- Required next action: supervisor Gate 2 review and `execute_report` if verification passes. B001 has run only scoped file validators and must not run `execute_report`.
- Confidence: high for owner, source placement, function map, packet/reply behavior, vtable/singleton evidence, and generated coded state; capped below final-audit confidence by no direct constructor route, inferred original field/helper names, and the deferred future range-rename/split decision.

## Supporting Research

- Assignment source: `tools/leaser/Agents/Agent-B001/goal.md`, current target [UID:0002QS] `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`.
- Lifecycle/status notes: initial pass was report-only. After supervisor Gate 1 approval, this callback edited only the accepted target/support by-* docs and this B001 report artifact, ran scoped file validators, released/confirmed no B001 leases remained, and stopped before supervisor execute. No generated files, coverage reports, validator state, lifecycle/archive files, queue files, supervisor ledgers, IDA DB files, or `execute_report` variants were manually edited or run by B001.
- Workflow read: project-level `ntk-b-agent-workflow`, `b-agent-research-and-implementation-workflow.md`, `b-agent-report-template.md`, `score-blocker-audit-standard.md`, and relevant `by-structure.md` MCP/source-quality rules.
- MCP availability proof: `idb_list` returned active session `9600ec5b` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` on `9600ec5b` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Prior reports reviewed as leads, not authority: B010 `0001CR` create-user split report, B008 `0002QT` old CreateUserDialogPane split report, B004 `0002QR` NewUserDialogPane2 split report, B001 `0002Q9` NewUserShapeSelectControlPane report, and B001 `0002SJ` NewCreateUserDialogPane vtable-data report.

## Target

- Target UID: `0002QS`.
- Target path: `source-3/project-documentation/by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`.
- Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002QS-NewCreateUserDialogPaneCore-source-quality.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` row `86/89`, combined `87.5`, reconstructable `true`, direct reports `0`.
- Current supervisor classification: reconstructable B-agent source-quality target under the create-user family.
- Current scores and parent state: target `86/89`, direct class owner/emitter [UID:00008Z], file route [UID:0000LP] `NewCreateUserDialogPane`, parent [UID:0001CR] create-user family split/index.

## Current Target State

- Pre-callback metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:00008Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008Z`, blank optional emitter position, `Nested:0`.
- Current post-callback metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00008Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008Z`, blank optional emitter position, `Nested:0`.
- Pre-callback C++/emitter state: formal C++ was populated and generated output was coded, but the C++ still used 32-wide password buffers, read create-user reply status from `packet[0]`, omitted the account-helper trailing zero byte, wrote selected option `+0x26c` without the observed `+1`, and abstracted descriptor serialization too broadly.
- Current C++/emitter state: formal C++ now uses 16-wide account/password/confirm buffers with max length `15`, writes the opcode `0x02` trailing zero, serializes the opcode `0x04` descriptor fields after `BuildPreviewParams`, writes `m_selectedGenderOrNation + 1`, writes the create-character trailing zero, and reads reply status/length/message from `packet[1]`/`packet[2]`/`packet+3`.
- Existing open questions/blockers: direct constructor reachability remains absent; exact original inherited control accessors, packet-buffer helper names, callback/dialog helper names, and class member spellings remain inferred. These are confidence caps, not reasons to leave the target blank.
- Related docs checked: `by-class/NewCreateUserDialogPane.md`, `by-file/NewCreateUserDialogPane.md`, `by-file/CreateUserDialogs.md`, `by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md`, `by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md`, `by-global/g_pNewCreateUserDialogPane.md`, `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md`, siblings `0002QR`, `0002QT`, and lifecycle child `0002QU`.
- Generated output state: before callback, `auto-generated/NexusTK/login/NewCreateUserDialogPane.cpp` was coded at command `000000007524`, and generated tracker/coverage command `000000007553` listed UID0002QS as `coded`. After the final scoped validator rerun, generated `NewCreateUserDialogPane.cpp`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md` all refreshed to command `000000007584` at `2026-07-06T13:32:14-04:00`. UID0002QS emits `88/91` source with the corrected C++ facts and tracker row `88/91`; empty generated markers remain only for UID0002X7/UID0002X8 singleton/global support pages, not UID0002QS.
- Current artifact/lifecycle status: implementation callback is complete and awaiting supervisor Gate 2/execute. B001 did not run `execute_report`.

## Heuristic / Inference Reanalysis And Validation

- Owner/emitter route: current MCP vtable stores, singleton lifecycle refs, selector construction, command/submit/reply edges, and support docs all support direct class owner [UID:00008Z] with file output [UID:0000LP]. Keeping owner/emitter `00008Z` is correct.
- Retained/no-direct-caller constructor: `xrefs_to 0x0052c360` returned zero xrefs. Current MCP `find_bytes` found zero absolute-VA pattern hits for `60 c3 52 00` and zero RVA pattern hits for `60 c3 12 00`. A fresh read-only PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` also found zero absolute VA hits, zero RVA hits, and zero direct `E8`/`E9` branch hits to `0x0052c360`. This remains real retained-code evidence, not an ownership blocker.
- Packet/reply correction: current decompile of `0x0052d9a0` proves the reply status byte is `packet[1]`, message length is `packet[2]`, and message data begins at `packet+3`. The current target C++ `packet[0]` read is stale and should be corrected.
- Submit buffers: decompile of `0x0052d3e0` reads edit controls 1, 2, and 3 into 16-wide buffers with length `15`. The current target C++ uses 32-wide password/confirmation buffers and length `32`, which is a source-quality bug.
- Account helper: decompile of `0x0052d5b0` writes opcode `0x02`, three length-prefixed MBCS strings, a trailing zero byte, then sends through `dword_67A7EC` / [UID:0000Q5] `g_packetSender`. The helper is file-local `__stdcall`-shaped source, best represented as a namespace helper inside `NewCreateUserDialogPane.cpp`.
- Create-character packet: decompile of `0x0052d7c0` reads child id `8`, computes selector `selectedSlot + 15 * page` from selector offsets `+0x116/+0x118`, calls `0x004fd610` `BuildPreviewParams`, writes opcode `0x04`, serializes descriptor `shapeIndex` and `isFemale`/mode byte, writes `m_selectedGenderOrNation + 1`, writes `m_selectedTotem`, appends the MBCS created-name string, writes a trailing zero, and sends through `g_packetSender`.
- Selector interaction: current decompile of `0x004fd610` confirms it builds a descriptor, not a packet. Current decompile of `0x0052d060`/`0x0052d0b0` confirms SelectMale/SelectFemale toggle controls 4/5 and tail-write selector body modes `2`/`6`.
- Boundary/split: current target endpoint `0x0052dcf5` is stale as an exclusive logical coverage boundary. Bytes `0x0052dcf8` begin the reply handler's switch table (`jpt_52DA2F`) with a data xref from `0x0052da2f`. Bytes `0x0052dd20-0x0052dd28` are an IDA-unmodeled no-xref code-shaped stub (`mov eax,[ecx]; push 8; call [eax+58h]; retn`) followed by padding to old dialog constructor `0x0052dd30`. The target should document or extend coverage through `0x0052dd30`; it should not keep saying the whole gap is padding.
- Split decision: a full child split analogous to B004/B008 was considered. For this pass, the accepted implementation repaired the single exact target and recorded the post-reply table/stub gap rather than creating many child pages immediately. The ordinary source methods share the direct class/file route. If the supervisor wants parity with B004/B008 later, the function inventory below is already suitable as a split seed.
- Resource evidence: current target-range rendered search re-proved constructor references to `DLGNEW.EPF`, `DIREC.EPF`, and `DLGNEW.PAL`. Current bounded searches did not re-prove exact `GENDER.EPF` or `NEWBUTT.PAL` strings, so those older support-doc strings should not be copied forward as current MCP-proven facts without a separate resource check.
- Generated-output state: UID0002QS current output is coded. Empty markers in `NewCreateUserDialogPane.cpp` are for UID0002X7/UID0002X8 singleton/global storage pages, not for UID0002QS.

## Evidence Standards Used

- Primary evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, `get_int`, `find_bytes`, `type_query`, `search_text`, and `entity_query` on session `9600ec5b`.
- Secondary evidence: current target/support by-* docs, current generated source and tracker/coverage rows, and executed B-agent reports used as leads.
- Negative evidence: zero constructor xrefs, zero constructor pointer-pattern hits, zero current local IDA UDT/type for `NewCreateUserDialogPane`, zero direct PE branch hits, and no xrefs/pointer-pattern hits for the `0x0052dd20` stub.
- Confidence limitation: exact original source names for UI helper functions, packet-buffer methods, dimmer global, callback/dialog classes, and class fields are not proven by symbols. The report uses descriptive source-facing names and keeps score below final-audit level.

## Evidence Checked

- MCP availability: `idb_list`; `server_health database=9600ec5b`.
- Function map: `lookup_funcs` for `0x0052c360`, `0x0052cef0`, `0x0052cf80`, `0x0052d050`, `0x0052d060`, `0x0052d0b0`, `0x0052d100`, `0x0052d1e0`, `0x0052d210`, `0x0052d2f0`, `0x0052d300`, `0x0052d330`, `0x0052d3e0`, `0x0052d5b0`, `0x0052d7c0`, `0x0052d9a0`, boundary/gap addresses, sibling `0x0052dd30`, selector helpers, and destructor helpers.
- Xrefs/callees: `xrefs_to` for constructor, singleton, vtable bases, selector constructor/build helper, account/payload/reply helpers, gap addresses; `callees` for constructor, command dispatcher, submit, account helper, payload builder, and reply handler.
- Decompilation/disassembly: decompiled submit, account helper, payload builder, reply handler, command dispatcher, SelectMale/SelectFemale, selector constructor/BuildPreviewParams, selection helpers, event bridges; disassembled constructor prologue/selector/tail and reply tail.
- Bytes/integers: boundary bytes at `0x0052bbbc`, `0x0052cd49`, `0x0052d5ac`, `0x0052dcf0`, `0x0052dd20`, `0x0052f94c`; vtable/global dwords; string bytes at `0x0060db20`, `0x0061e318`, and `0x0061ff48`.
- Generated/docs: target page, direct class/file/family pages, selector/vtable/global support, current generated `NewCreateUserDialogPane.cpp`, current generated memory coverage and research tracker rows, B010/B008/B004/B001 reports.
- Failed/unavailable/skipped: no MCP failure after supervisor restart. Validators and lifecycle commands were intentionally skipped because this is report-only and the goal forbids them.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002QS-01 | Current MCP session `9600ec5b` is IDB-backed and healthy. | High | `idb_list`; `server_health` ok with Hex-Rays/strings ready | Target `## IDA Evidence` | incorporate | applied: target evidence now names session `9600ec5b`, health state, module/imagebase readiness facts |
| C-0002QS-02 | Target owner/emitter should remain [UID:00008Z] `NewCreateUserDialogPane`; file route remains [UID:0000LP]. | High | vtable stores, singleton refs, class/file docs, generated coded output | Target metadata/status/source placement | incorporate | applied/already-present: owner/emitter/reconstructable/blank emitter position preserved; status and score rationale retain class/file route |
| C-0002QS-03 | Constructor `0x0052c360` remains no-direct-caller/retained: zero xrefs, zero VA/RVA pattern hits, zero direct PE branch hits. | High | MCP `xrefs_to`/`find_bytes`; read-only PE scan | Target `## IDA Evidence`, `## Score Rationale`, `## Changes` | incorporate | applied: target records current no-direct-caller and PE scan proof with retained-code caveat |
| C-0002QS-04 | Submit reads three 16-wide buffers with max length 15 and calls account helper on success. | High | Decompile `0x0052d3e0` | Target formal C++ and `## IDA Evidence` | incorporate | applied: formal C++ uses three 16-wide buffers and max `15`; evidence records submit decompile |
| C-0002QS-05 | File-local account helper writes opcode `0x02`, three length-prefixed MBCS strings, a trailing zero byte, then sends. | High | Decompile `0x0052d5b0` | Target formal C++ and packet evidence | incorporate | applied: formal C++ adds `packet.WriteByte(0)` and evidence records opcode `0x02` helper behavior |
| C-0002QS-06 | Payload builder computes `selectedSlot + 15 * page`, calls selector `BuildPreviewParams`, writes opcode `0x04`, descriptor bytes, `+0x26c + 1`, `+0x270`, name, trailing zero, and sends. | High | Decompile `0x0052d7c0`; selector decompile `0x004fd610` | Target formal C++ and selector evidence | incorporate | applied: formal C++ and IDA evidence record child id `8`, descriptor serialization, `m_selectedGenderOrNation + 1`, totem/name, and trailing zero |
| C-0002QS-07 | Reply status is `packet[1]`, message length is `packet[2]`, message data begins at `packet+3`; current `packet[0]` C++ is stale. | High | Decompile `0x0052d9a0`; B004/B008 sibling precedent | Target formal C++ and stale-assumption notes | incorporate | applied: formal C++ now reads `packet[1]`/`packet[2]`/`packet+3`; target change note historicalizes older `packet[0]` |
| C-0002QS-08 | `0x0052dcf5-0x0052dd30` is not all padding: it includes the reply switch table at `0x0052dcf8`, no-xref stub at `0x0052dd20`, and padding. | High | `get_bytes`, `xrefs_to 0x0052dcf8`, `search_text jpt_52DA2F`, `lookup_funcs` | Target `## Boundary Evidence`, Item Summary, `## Changes` | incorporate | applied: boundary section now records switch table, no-xref stub, final padding, and future rename/split note |
| C-0002QS-09 | Generated output was coded for UID0002QS under pre-callback command `000000007524`; after callback validators refreshed generated source/tracker/coverage output to final command `000000007584`. | High | generated source/header, generated coverage/tracker rows, scoped validator outputs | Target generated-output state; report validator results | incorporate | applied: target records pre-callback coded state and current generated command facts; generated source, memory coverage, by-memory coverage report, and tracker headers are `000000007584`; tracker row is `88/91` |
| C-0002QS-10 | `by-memory/0x0069b4a8-0x0069b4ac...` and `by-file/NewCreateUserDialogPane.md` contained stale `0xffffffff` singleton initializer wording, while current bytes/dword are zero. | High | support docs; MCP `get_int 0x0069b4a8 -> 0`; support body already says `0x00000000` | Support doc summaries/evidence notes | reject-stale | applied: singleton Item Summary now says `0x00000000` / `00 00 00 00`; file evidence note historicalizes stale `0xffffffff` wording |

## Positive Evidence Summary

- Constructor `0x0052c360` publishes/clears `g_pNewCreateUserDialogPane`, installs the three `NewCreateUserDialogPane` vtable views, constructs UI controls from the newer dialog resources, allocates a `0x11c` selector, seeds it with `rand()%15`, and registers child id `8`.
- Selector, command, submit, account, payload, and reply functions are internally coherent and all route through this class/file cluster.
- `xrefs_to 0x0069b4a8` reports the six singleton lifecycle refs already expected for this class: cleanup read, constructor publish/clear, constructor-adjacent cleanup, clear helper, and scalar deleting destructor clear.
- Vtable refs at `0x0061fda0`, `0x0061fe00`, and `0x0061fe30` have constructor and destructor support matching B001 UID0002SJ.
- Generated output already emits UID0002QS C++ through `auto-generated/NexusTK/login/NewCreateUserDialogPane.cpp`, proving the current route is live and not an empty-emitter state.

## IDA MCP Facts

- Function/range facts: `0x0052c360` size `0x9e9`; `0x0052d3e0` size `0x1cc`; `0x0052d5b0` size `0x205`; `0x0052d7c0` size `0x1df`; `0x0052d9a0` size `0x355`; sibling old dialog constructor begins at `0x0052dd30`.
- Constructor facts: `0x0052c3b8` writes `0x0069b4a8`, `0x0052c3bf` fallback-clears it, `0x0052c3d3/0x0052c3d9/0x0052c3e3` install vtables `0x0061fda0/0x0061fe00/0x0061fe30`, and `0x0052c7aa` calls selector constructor `0x004fd520`.
- Xref facts: `xrefs_to 0x0052c360` has zero refs; `xrefs_to 0x004fd610` has one caller `0x0052d85f`; `xrefs_to 0x0052d5b0` has caller `0x0052d5a2`; `xrefs_to 0x0052d7c0` has callers `0x0052d1bc`, `0x0052d202`, and `0x0052daf6`; `xrefs_to 0x0052d9a0` has caller `0x0052d321`.
- Boundary facts: `0x0052dcf8` has a data xref from `0x0052da2f` and renders as `jpt_52DA2F dd offset loc_52DA36`; `0x0052dd20` has bytes `8b 01 6a 08 ff 50 58 c3`, no xrefs, and zero VA/RVA pointer-pattern hits.
- Global/data facts: `get_int 0x0069b4a8 u32le` returned `0`; vtable dwords begin `0x0061fda0 -> 0x0052f870`, `0x0061fe00 -> 0x0052f751`, `0x0061fe30 -> 0x0052f75c`.
- Negative IDA facts: `type_query *NewCreateUserDialogPane*` returned no local types; current bounded string searches did not re-prove `GENDER.EPF` or `NEWBUTT.PAL`; constructor pointer and branch scans remain negative.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0052c360-0x0052cd49` | UID0002QS current target | Constructor-like full-screen newer dialog build | true | `00008Z` | current `86/89` | keep, add current evidence |
| `0x0052cef0-0x0052cf75` | UID0002QS current target | Two-way gender/nation selector helper | true | `00008Z` | current `86/89` | keep |
| `0x0052cf80-0x0052d042` | UID0002QS current target | Four-way totem/style selector helper | true | `00008Z` | current `86/89` | keep |
| `0x0052d060-0x0052d0ac` | UID0002QS current target | SelectMale; toggles controls and tail-writes selector mode `2` | true | `00008Z` | current `86/89` | keep |
| `0x0052d0b0-0x0052d0fc` | UID0002QS current target | SelectFemale; toggles controls and tail-writes selector mode `6` | true | `00008Z` | current `86/89` | keep |
| `0x0052d210-0x0052d2a7` | UID0002QS current target | OnCommand dispatcher | true | `00008Z` | current `86/89` | keep |
| `0x0052d3e0-0x0052d5ac` | UID0002QS current target | SubmitCreateUser | true | `00008Z` | current `86/89` | repair C++ buffer lengths |
| `0x0052d5b0-0x0052d7b5` | UID0002QS current target | File-local account request helper | true | class/file route | current `86/89` | repair C++ trailing zero |
| `0x0052d7c0-0x0052d99f` | UID0002QS current target | SendCreateCharacterRequest payload builder | true | `00008Z` | current `86/89` | repair descriptor/option serialization |
| `0x0052d9a0-0x0052dcf5` | UID0002QS current target | HandleCreateUserReply | true | `00008Z` | current `86/89` | repair `packet[1]` status |
| `0x0052dcf5-0x0052dd30` | currently outside target filename | reply switch table, no-xref stub, padding before old dialog | mixed/no-code support | UID0002QS boundary support | unscored | document or extend target boundary through `0x0052dd30` |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0052c360` | zero xrefs; zero PE branch/pointer hits | retained/no-direct-caller constructor caveat |
| `0x004fd520` | caller `0x0052c7aa` | constructor allocates/constructs shape selector child id `8` |
| `0x004fd610` | caller `0x0052d85f` | payload builder calls selector `BuildPreviewParams` |
| `0x0052d5b0` | caller `0x0052d5a2` | submit success calls account packet helper |
| `0x0052d7c0` | callers `0x0052d1bc`, `0x0052d202`, `0x0052daf6` | payload builder from event/callback and first-stage reply success |
| `0x0052d9a0` | caller `0x0052d321` | packet-event bridge calls reply handler |
| `0x0069b4a8` | six data refs | singleton lifecycle for `NewCreateUserDialogPane` |
| `0x0061fda0/0x0061fe00/0x0061fe30` | three refs each | class vtable views written by constructor/fallback/destructor |
| `0x0052dcf8` | data xref from `0x0052da2f` | reply switch table starts after current endpoint |
| `0x0052dd20` | zero xrefs and zero pointer hits | no-route code-shaped stub before old dialog constructor |

## Documentation Evidence And IDA Status

- Target page already has the correct owner/emitter route, shape selector route, and current generated coded state in broad form.
- Target page's formal C++ is stale in several behavior-affecting details and must be repaired before raising score.
- Target page's boundary evidence currently says the bytes after `0x0052dcf5` are padding before `0x0052dd30`; current MCP disproves that wording.
- `by-class/NewCreateUserDialogPane.md` and `by-file/NewCreateUserDialogPane.md` support the owner/source route and no-direct-caller caveat.
- `by-file/NewCreateUserDialogPane.md` and `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md` contain stale `0xffffffff` singleton initializer wording that conflicts with current zero-initialized storage.
- B004 and B008 sibling reports independently show that create-user reply handlers use `packet[1]` status and `packet[2]/packet+3` message fields; current MCP proves the same for UID0002QS.

## Ranked Ownership Analysis

### 1. [UID:00008Z] NewCreateUserDialogPane

- Evidence for: constructor vtable stores, singleton publish/clear, selector construction, method cluster, class declaration, generated coded output, and direct target metadata already match.
- Evidence against: no direct constructor xref and no local IDA UDT/type record.
- Decision: keep as direct owner and emitter. The negative evidence is a confidence cap only.

### 2. [UID:0000LP] NewCreateUserDialogPane file

- Evidence for: generated output root is `NexusTK/login/NewCreateUserDialogPane.cpp`; file-local account helper belongs naturally in this source file.
- Evidence against: direct semantic method owner remains the class, and target metadata already routes through the class.
- Decision: keep as file/source root context, not as direct replacement owner.

### 3. [UID:0000IK] CreateUserDialogs family/index

- Evidence for: broader create-user family context.
- Evidence against: already non-emitting family/index; class-specific singleton/vtable/method evidence is stronger.
- Decision: reject as direct owner/emitter.

### 4. Sibling classes `NewUserDialogPane2` / `CreateUserDialogPane`

- Evidence for: adjacent ranges and similar packet/reply patterns.
- Evidence against: sibling constructors, singleton slots, vtables, and source files are separate; old and alternate variants have their own direct callers.
- Decision: reject merge/collapse. Use siblings only as source-shape precedent.

## Source Placement

- Recommended source placement: `NexusTK/login/NewCreateUserDialogPane.cpp`, with class methods under `NewCreateUserDialogPane` and the opcode `0x02` account helper as a file-local namespace helper.
- Why this fits: constructor/resource usage, singleton, vtables, selector child, generated output, and create-user family docs all point to the newer create-user dialog source file.
- Rejected placements: umbrella `CreateUserDialogs.cpp`, old `CreateUserDialogPane.cpp`, alternate `NewUserDialogPane2.cpp`, selector source file, vtable data page, or singleton global page.
- Remaining uncertainty: exact original helper/member spellings and live construction route remain unresolved, but source placement is stable.

## Range / Split / Padding / Reclassification Analysis

- Current target physical source range `0x0052c360-0x0052dcf5` covers modeled source functions through reply handler end.
- Current exclusive endpoint `0x0052dcf5` should no longer be described as followed by only padding. The post-function range contains:
  - `0x0052dcf5-0x0052dcf8`: alignment bytes.
  - `0x0052dcf8-0x0052dd10`: reply switch table referenced from `sub_52D9A0+0x8f`.
  - `0x0052dd10-0x0052dd20`: data/zero/padding bytes.
  - `0x0052dd20-0x0052dd28`: no-route code-shaped stub, not an IDA function, no xrefs, no VA/RVA pointer hits.
  - `0x0052dd28-0x0052dd30`: `0xcc` padding before old `CreateUserDialogPane` constructor.
- Recommended implementation: update target boundary notes and Item Summary to say the UID0002QS cluster's logical boundary evidence extends through the switch-table/stub/padding gap before `0x0052dd30`. If the validator/supervisor allows a range rename, rename target to `0x0052c360-0x0052dd30.NewCreateUserDialogPaneCore.md`; otherwise record the gap as adjacent boundary support and add a follow-up exact child/support page if required.
- No immediate child split is required for this report callback, but the function inventory above should be preserved as split seed material if the supervisor later wants B004/B008-style child pages.

## Negative Evidence Summary

- No direct xrefs to constructor `0x0052c360` were found.
- No absolute VA or RVA byte-pattern hits to constructor `0x0052c360` were found in current MCP or the current input PE.
- No direct `E8`/`E9` branch/call hits to constructor `0x0052c360` were found in the current input PE.
- No local IDA UDT/type record for `NewCreateUserDialogPane` was found.
- No xrefs or VA/RVA pointer hits were found for the `0x0052dd20` no-route stub.
- Current exact MCP/resource searches did not re-prove older support claims for `GENDER.EPF` or `NEWBUTT.PAL`; do not label those strings as current MCP facts without a separate resource pass.
- Empty markers in current generated `NewCreateUserDialogPane.cpp` are for UID0002X7 and UID0002X8 singleton/global support pages, not UID0002QS.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID0002QS remains reconstructable and has a valid class/file emitter route.
- Recommended code: replace the existing formal `RECONSTRUCTION_CPP CODE` content with the block below after supervisor callback. The block intentionally keeps source-facing wrapper names descriptive and records exact behavior in the surrounding target prose.

```cpp
// First-draft source-shape implementation for the retained/newer
// NewCreateUserDialogPane create-user cluster. Exact inherited dialog
// accessors, selector-control class APIs, packet-buffer method names,
// screen-dimmer helper names, and callback/dialog class names remain inferred.
// Current MCP session 9600ec5b confirms the constructor/no-direct-caller
// status, selector flow, opcodes, packet byte layout, singleton, and reply
// behavior.

namespace
{
void SendCreateAccountRequest(const wchar_t *accountName,
                              const wchar_t *password,
                              const wchar_t *profileText)
{
    PacketBuffer packet;
    packet.WriteByte(0x02);
    packet.WriteLengthPrefixedMbcString(accountName);
    packet.WriteLengthPrefixedMbcString(password);
    packet.WriteLengthPrefixedMbcString(profileText);
    packet.WriteByte(0);
    g_packetSender->QueueAndSendPacket(packet.Data(), packet.Size());
}
}

void NewCreateUserDialogPane::SubmitCreateUser()
{
    wchar_t accountName[16];
    wchar_t password[16];
    wchar_t confirmPassword[16];

    GetDialogText(1, accountName, 15);
    GetDialogText(2, password, 15);
    GetDialogText(3, confirmPassword, 15);

    if (!PasswordContainsDigit(password)) {
        FocusDialogControl(2);
        ShowCreateUserAlert(kPasswordMustContainDigitText);
        return;
    }

    if (wcscmp(password, confirmPassword) != 0) {
        FocusDialogControl(2);
        ShowCreateUserAlert(g_pLanguageMan->GetString(90));
        return;
    }

    g_pScreenPane->CreateScreenDimmer();
    SendCreateAccountRequest(accountName, password, g_sharedEmptyWideStringLiteral);
}

void NewCreateUserDialogPane::SendCreateCharacterRequest()
{
    PacketBuffer packet;
    HumanImageRenderParams appearance;
    const unsigned char shapeIndex = static_cast<unsigned char>(
        m_shapeSelector->SelectedShapeSlot() + 15 * m_shapeSelector->ShapePage());

    if (!g_pScreenDimmer) {
        g_pScreenPane->CreateScreenDimmer();
    }

    m_shapeSelector->BuildPreviewParams(&appearance, shapeIndex);

    packet.WriteByte(0x04);
    packet.WriteByte(static_cast<unsigned char>(appearance.shapeIndex));
    packet.WriteByte(appearance.isFemale ? 1 : 0);
    packet.WriteByte(static_cast<unsigned char>(m_selectedGenderOrNation + 1));
    packet.WriteByte(static_cast<unsigned char>(m_selectedTotem));
    packet.WriteLengthPrefixedMbcString(m_createdUserName.c_str());
    packet.WriteByte(0);
    g_packetSender->QueueAndSendPacket(packet.Data(), packet.Size());
}

bool NewCreateUserDialogPane::HandleCreateUserReply(const unsigned char *packet)
{
    const unsigned char result = packet[1];
    const unsigned char messageLength = packet[2];
    wchar_t messageText[256];

    DecodeCreateUserReplyMessage(packet + 3, messageLength, messageText, 256);

    if (!m_waitingForCharacterReply) {
        if (result == 0) {
            wchar_t accountName[16];

            m_waitingForCharacterReply = 1;
            SendCreateCharacterRequest();
            GetDialogText(1, accountName, 15);
            g_createdAccountName.Assign(accountName);
            return true;
        }

        if (g_pScreenDimmer) {
            g_pScreenDimmer->Close(1);
        }

        if (IsCreateUserNameReplyError(result)) {
            FocusDialogControl(1);
        } else if (IsCreateUserPasswordReplyError(result)) {
            FocusDialogControl(2);
        }

        if (messageText[0] != 0) {
            ShowCreateUserAlert(messageText);
        }
        return true;
    }

    if (g_pScreenDimmer) {
        g_pScreenDimmer->Close(1);
    }

    if (result != 0) {
        if (messageText[0] != 0) {
            ShowCreateUserAlert(messageText);
        }
        return true;
    }

    if (messageText[0] != 0) {
        ShowCreateUserAlert(messageText);
    } else {
        ShowCreateUserAlert(kCreateUserFallbackReplyText);
    }

    CloseDialog();
    return true;
}
```

- Reason it preserves behavior: the block fixes the observed buffer lengths, account-helper terminator, payload option `+1`, descriptor route, and reply packet offsets from current MCP decompilation.
- Reason it matches plausible original source shape: it keeps ordinary class methods, a file-local helper, named packet-buffer operations, and descriptive member names rather than decompiler labels.
- Inferred names/types: `PacketBuffer`, `HumanImageRenderParams`, `g_pScreenDimmer`, `g_createdAccountName`, `DecodeCreateUserReplyMessage`, `IsCreateUserNameReplyError`, and related helper names are descriptive and should be documented as inferred.
- Reason code should not be higher confidence: the constructor body is still documented in prose rather than fully source-authored in this block, exact helper names are inferred, and direct construction route is absent.

## Final Recommendation

- Exact recommended target changes: set target score to `COMPLETION:88` and `CONFIDENCE:91`; keep owner/emitter/reconstructable metadata; replace formal C++ with the corrected block; update evidence and boundary prose with current MCP session `9600ec5b`; historicalize stale `packet[0]`, 32-wide buffer, padding-only, and current-empty-emitter assumptions.
- Exact parent assignments: keep [UID:00008Z] class owner and [UID:0000LP] file route; keep [UID:0001CR] and [UID:0000IK] as family/index context only.
- Exact items left no-owner/non-emitting: none inside current target metadata. The `0x0052dd20` adjacent stub should be documented as no-route/no-code boundary support unless a future range rename/split creates a dedicated no-code child.
- Exact future work outside this assignment: if the supervisor wants B004/B008 parity, use this function inventory as the seed for a later exact-child split. That is not required before applying the target repair recommended here.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`.
- Metadata changes: `COMPLETION:88`, `CONFIDENCE:91`; leave `CANONICAL_OWNER:00008Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00008Z`, and blank optional emitter position unchanged.
- Item Summary: replace with a concise summary that adds current MCP session `9600ec5b`, coded generated output, corrected packet/reply offsets, and boundary gap facts without repeating rendered UID/path/score fields.
- Formal C++: replace the current block with the recommended corrected formal block above.
- Evidence incorporated: current MCP health/session, exact function sizes, constructor/vtable/singleton refs, selector allocation/child id 8/`rand()%15`, command dispatcher cases, submit/account/payload/reply decompile facts, pre-callback coded generated state from commands `000000007524`/`000000007553`, final post-validator generated command `000000007584`, and PE no-direct-constructor scan.
- Boundary text: replace "padding between `0x0052dcf5` and `0x0052dd30`" with switch-table/stub/padding facts and an implementation note about possible range rename to `0x0052dd30` if supervisor/validator policy allows.
- Historical/stale assumptions to preserve as rejected: older broad support reports used `packet[0]`, selector-side packet-writing language, and padding-only wording; current MCP supersedes those.

## Recommended Support Doc Changes

- `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md`: correct the Item Summary phrase "initialized to `0xffffffff`" to current zero-initialized storage (`0x00000000` / `00 00 00 00`). Body already records the correct value; the summary contradicts it.
- `by-file/NewCreateUserDialogPane.md`: correct the evidence note saying the singleton storage is a clean `0xffffffff` item. Current support/global docs and current MCP `get_int` show `0x0069b4a8` initializes to `0x00000000`.
- No structural support-doc edit is otherwise required. `by-class/NewCreateUserDialogPane.md`, `by-file/CreateUserDialogs.md`, UID0002SJ vtable data, and UID0002Q9 selector docs already carry same-or-greater ownership/selector/vtable/source-placement detail, except for not yet having this report's current packet/boundary repair.

## Score And Metadata Recommendation

- Current score/metadata: `86/89`, owner/emitter `00008Z`, reconstructable true.
- Recommended score/metadata: `88/91`, owner/emitter unchanged.
- Score rationale: completion rises because the report resolves target-specific packet/reply offsets, helper roles, selector serialization, generated coded state, current MCP proof, PE no-caller proof, and boundary gap facts. Confidence rises because the current IDB corroborates the prior reports, but remains below final audit because constructor reachability is absent, exact helper/member names remain inferred, and a possible range rename/split decision needs supervisor implementation policy.
- Reason not higher: target still aggregates many methods, formal C++ remains first-draft, no direct constructor route exists, no local IDA UDT exists, and exact original source spellings are not symbol-proven.
- Score-improvement attempt: no-direct-caller was rechecked by MCP and PE scan; packet/reply flow was decompiled; selector route was decompiled; boundary bytes and xrefs were checked; generated state was checked; support contradictions were located. Each named blocker has either a repair recommendation or a documented confidence-cap result.

## Open Questions With Attempted Resolution

- Direct constructor caller: checked MCP xrefs, MCP pointer patterns, and PE direct-branch scan. No direct route exists. Best resolution: retained/newer or indirect/config path; confidence cap only.
- Exact original field/helper names: checked decompiler, current class/file docs, selector docs, and local type query. No local UDT/type record exists. Best resolution: use descriptive source names and record them as inferred.
- Boundary rename versus adjacent support note: current evidence proves `0x0052dcf5-0x0052dd30` is not pure padding. Best resolution: update target boundary notes now and let supervisor decide whether implementation should rename the by-memory path/range to `0x0052dd30` or create/follow up with a small no-code child.
- `GENDER.EPF`/`NEWBUTT.PAL` resource strings: older docs mention them, but current bounded MCP searches did not re-prove them. Best resolution: do not label them current MCP facts in this target update unless a separate resource pass proves them.
- Remaining unresolved items: exact callback/dialog class names and packet-buffer method names. These do not block first-draft C++ because the byte layout and behavior are documented.

## Validator Results

- Command: `python .\tools\validator.py --mode file --file by-memory\0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md --apply --queue-timeout 240`; working directory `source-3/project-documentation`; `command_id: 000000007576`; `command_timestamp: 2026-07-06T13:27:42-04:00`; exit code `0`; `ok: 1`; warnings/errors: none. Side effects: `autogen_registry_update: 1`, `completion_update: 1`, `confidence_update: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`, `generated_refresh_command_id: 000000007576`.
- Command: `python .\tools\validator.py --mode file --file by-memory\0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md --apply --queue-timeout 240`; working directory `source-3/project-documentation`; `command_id: 000000007577`; `command_timestamp: 2026-07-06T13:27:52-04:00`; exit code `0`; `ok: 1`; warnings/errors: none. Side effects: `projected_stats_update: 1`, `generated_refresh: deferred`, `generated_refresh_command_id: 000000007577`.
- Command: `python .\tools\validator.py --mode file --file by-file\NewCreateUserDialogPane.md --apply --queue-timeout 240`; working directory `source-3/project-documentation`; `command_id: 000000007578`; `command_timestamp: 2026-07-06T13:27:58-04:00`; exit code `0`; `ok: 1`; warnings/errors: none. Side effects: `projected_stats_update: 1`, `generated_refresh: deferred`, `generated_refresh_command_id: 000000007578`.
- Final target rerun after generated-state prose repair: `python .\tools\validator.py --mode file --file by-memory\0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md --apply --queue-timeout 240`; working directory `source-3/project-documentation`; `command_id: 000000007584`; `command_timestamp: 2026-07-06T13:32:14-04:00`; exit code `0`; `ok: 1`; warnings/errors: none. Side effects: `projected_stats_update: 1`, `generated_refresh: deferred`, `generated_refresh_command_id: 000000007584`.
- Generated freshness: `auto-generated/NexusTK/login/NewCreateUserDialogPane.cpp`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-research-tracker.md` all refreshed to `validator-command-id: 000000007584`, `validator-refreshed-at: 2026-07-06T13:32:14-04:00`. UID0002QS emits `88/91` code with the corrected buffer widths, terminator writes, `m_selectedGenderOrNation + 1`, and `packet[1]` reply offset; tracker row is `88/91`.
- Lease result: B001 leased the three edited by-* docs immediately before the first edit/validator batch. The explicit release command after validators returned `Rejected[No active lease]` for all three paths because those short leases had already expired; current lease reports showed no active B001 leases remaining. B001 then leased only the target for the generated-state prose repair and released that final target lease successfully.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0002QS-NewCreateUserDialogPaneCore-source-quality.md` during the initial report-only pass.
- Modified by callback: `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`; `by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md`; `by-file/NewCreateUserDialogPane.md`; `tools/leaser/Agents/Agent-B001/research/0002QS-NewCreateUserDialogPaneCore-source-quality.md`.
- Validator-generated side effects observed, not manually edited: generated `NewCreateUserDialogPane.cpp`, generated memory coverage, generated by-memory coverage report, generated research tracker, and projected stats refreshed through scoped validators.
- Renamed: none.
- Report execution: not run. B agents must never run `execute_report` or lifecycle/archive commands.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update: target UID0002QS; support singleton summary docs listed above if accepted.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: target `86/89 -> 88/91`, owner/emitter unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair, or exact evidence-backed confidence cap.
- [x] Owner/emitter/reconstructable changes to apply: none; preserve current route.
- [x] Split/rename/new-child changes to apply: no immediate child split; boundary repair through `0x0052dd30` documented for supervisor decision.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable.
- [x] First-draft C++ or no-code proof to apply: corrected formal C++ replacement supplied.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: older generated/Wave references treated only as leads; current MCP/docs control.
- [x] Open questions closed or documented as evidence-backed unresolved.
- [x] Validators to run: scoped file validator for target and any support docs edited during callback.
- [x] Generated report refresh expected: target validator should refresh generated `NewCreateUserDialogPane.cpp` and generated tracker/coverage rows; B001 should not edit generated files.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: callback named Gate 1 SHA `8D38B1164C0DF3323DF5F8454FD2BA6A4DF309C3EF86CBDB0CEBA8A9E01EE37A`.
- [x] All accepted target/support doc details incorporated at report-level detail: target metadata/C++/evidence/boundary updated; singleton Item Summary and file support evidence note corrected.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C-0002QS-01 through C-0002QS-10 now record `applied` or `applied/already-present` proof.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target is `88/91`; owner/emitter/reconstructable/blank emitter position preserved; no rename or child split applied; boundary future rename/split documented.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: target records historical `packet[0]`, 32-wide buffer, padding-only, selector-side packet-writing, and empty-emitter assumptions as superseded; no-direct-constructor and no-route stub remain confidence caps.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: direct constructor route and exact helper/member names remain unresolved with PE/MCP negative proof and score impact.
- [x] Validators run and results recorded: commands `000000007576`, `000000007577`, `000000007578`, and final target rerun `000000007584` all exited `0` with `ok: 1` and no warnings/errors.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: generated source, memory coverage, by-memory coverage report, and research tracker headers are all `000000007584`.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000007592","destination_path":"executed-b-agent-research/B001/0002QS-NewCreateUserDialogPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002QS-NewCreateUserDialogPaneCore-source-quality.md","timestamp":"2026-07-06T13:45:03-04:00","uid":"0002QS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
