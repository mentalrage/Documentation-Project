** TARGET-REPORT-UID:0002Q5 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0002Q5 SendLoginRequest Source Quality Research


## Finalized Report / Current Recommendation
- Implemented recommendation after supervisor Gate 1 callback: [UID:0002Q5][by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md](../../../../by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) is now source-ready as a file-local `static void __stdcall SendLoginRequest(const wchar_t* accountName, const wchar_t* password)` helper in [UID:0000KX][LoginDialogPane](../../../../by-file/LoginDialogPane.md) / `NexusTK/login/LoginDialogPane.cpp`.
- Applied disposition: kept `CANONICAL_OWNER:0000KX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KX`, blank optional position, and replaced the blank formal C++ with the first-draft block in this report.
- Callback action applied: set `COMPLETION:90`, `CONFIDENCE:92`; incorporated refreshed MCP session `6eab6bcb` evidence, source-ready packet behavior, rejected owners, range/padding proof, and support declarations/notes for inferred config and application-active fields.
- Confidence: strong for range, behavior, caller, source route, and C++ readiness; capped below final-audit only by inferred exact source spellings for the helper name and two config/login-challenge fields.

## Supporting Research
- Assignment source: `Agent-B005/goal.md` names UID0002Q5, target `by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md`, and report path `tools/leaser/Agents/Agent-B005/research/0002Q5-SendLoginRequest-source-quality.md`.
- Historical MCP pause: a stale/unusable session was observed before supervisor restoration. This report does not rely on fallback-only work. All target IDA evidence cited below was refreshed or reconfirmed against active MCP session `6eab6bcb`.
- Current MCP health: `idb_list` returned active session `6eab6bcb` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `12112`, not analyzing. `server_health(database=6eab6bcb)` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Current and archived report search: searched active/archived B reports and leaser ledgers for `0002Q5`, `SendLoginRequest`, `0x004fb2d0`, `LoginDialogPane.cpp`, login request, packet request, and `QueueAndSendPacket(g_packetSender)`. No prior UID0002Q5 report was found. Relevant prior source-family evidence came from B001 `00019L-EnsureLoginDialogPane-source-quality.md`, which places nearby private login helpers in `LoginDialogPane.cpp` and says the broader account-dialog split does not block exact helper emission.
- Current docs checked: target page; [UID:0000KX] `by-file/LoginDialogPane.md`; [UID:00007F] `by-class/LoginDialogPane.md`; [UID:0002Q4] `by-memory/0x004fa7a0-0x004fb2d0.LoginDialogPaneCore.md`; generated `auto-generated/NexusTK/login/LoginDialogPane.cpp`; packet/support docs for [UID:0003YJ] PacketBuffer scalar writers, [UID:0001HU] `QueueAndSendPacket`, [UID:0000Q5]/[UID:0001P0] `g_packetSender`, [UID:00028Q] `g_pConfig`, [UID:00028Z] `ApplicationLifecycleFlags`, [UID:0002VG] `SetProtectedPasswordToken`, [UID:0001BH] `MemoryMan::MemmoveWrapper`, and sibling password-change packet helpers [UID:0002QB]/[UID:0002QC].

## Target
- Target UID: `0002Q5`.
- Target path: `by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` by-memory not-covered reconstructable queue, as assigned in `Agent-B005/goal.md`.
- Supervisor classification at this artifact state: Gate 1 accepted, implementation callback applied by B005, and supervisor execution/lifecycle remains external to B005.
- Assignment-time scores and parent state: target is `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000KX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KX`, blank optional position, and blank formal C++. Parent [UID:0000KX] is the `NexusTK/login/` file page and already clears the parent gate at `88/86`.

## Current Target State
- Pre-callback metadata at report start: `86/88`, owner/emitter [UID:0000KX], reconstructable true, optional position blank.
- Post-callback metadata after B005 implementation: `90/92`, owner/emitter [UID:0000KX] unchanged, reconstructable true, optional position blank, formal `RECONSTRUCTION_CPP CODE` populated with `static void __stdcall SendLoginRequest(const wchar_t* accountName, const wchar_t* password)`.
- Pre-callback generated-output evidence: generated `auto-generated/NexusTK/login/LoginDialogPane.cpp` showed UID0002Q5 as an empty emitter marker under validator command `000000006061` / refresh `2026-07-04T04:14:42-04:00`. This is now historical defect evidence; callback validators reported generated refresh deferred, so B005 did not claim a fresh generated C++ file state.
- Resolved blocker: target text formerly said final packet field/global names were not source-quality enough for C++. The exact source names remain inferred, but current support docs and MCP evidence are strong enough for first-draft source with explicit descriptive field names and confidence caps.
- Existing correct facts to preserve: exact `0x35a` function size, one login-command caller at `0x004fadbd`, Win32/packet-writer callees, config/global dependencies, randomized login challenge construction, six-byte padding boundary, and file-local LoginDialogPane source route.
- Related docs updated or confirmed: [UID:0000KX] file page now routes `SendLoginRequest` as a private source-ready helper in `login/LoginDialogPane.cpp`; [UID:00007F] class page preserves that UID0002Q5 is not a class virtual/member method; [UID:0002Q4] command-handler page names the source-ready `SendLoginRequest(accountName, password)` handoff while preserving the shifted-buffer caveat.
- Artifact/lifecycle status: this document now records both the accepted research and B005 implementation callback. B005 ran only scoped file validators for edited by-* pages and did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, archive moves, or report lifecycle commands.

## Executive Recommendation
- Best owner/source route: [UID:0000KX] `LoginDialogPane` file page / `NexusTK/login/LoginDialogPane.cpp`.
- Best source shape: a private file-local helper, `static void __stdcall SendLoginRequest(const wchar_t* accountName, const wchar_t* password)`.
- Metadata action: raise target to `90/92`, preserve owner/emitter/reconstructable, and populate the formal C++ block.
- Support action: update LoginDialogPane file/class/core notes and config/application/global dependency notes so the formal code's helper/global names are coherent and marked inferred where not original-proof.
- Condition for any remaining uncertainty: exact original spellings for `SendLoginRequest`, `m_loginChallengeKey`, and `m_loginChallengeMask` would require original source/header/PDB evidence. That uncertainty limits score but no longer blocks source entry.

## Supervisor Active Recheck
- Supervisor assigned UID0002Q5 as xHigh report-only work and later restored MCP with active session `6eab6bcb`. This report uses that current session.
- Split repair is not required: MCP proves one modeled function at `0x004fb2d0` with end-exclusive `0x004fb62a` and padding through `0x004fb630`. There are no mixed child ranges inside UID0002Q5.
- Every source-bearing item in scope has a disposition: target is source-ready; padding remains outside the function; successor `0x004fb630` is a separate constructor.

## Inference Research Guidance Check
- Applied `by-structure.md` IDA MCP discipline: used exact-address `lookup_funcs`, `server_health`, `xrefs_to`, `callees`, `decompile`, paged `disasm`, `get_bytes`, bounded `find_bytes`, signature, and `int_convert` calls. No broad unbounded listing/callgraph/type/batch-analysis calls were used.
- Direct IDA facts: function range, xrefs, disassembly, decompilation, callees, bytes, signatures, and numeric conversions.
- Documentation evidence: current by-* support pages for `LoginDialogPane`, `g_pConfig`, `ApplicationLifecycleFlags`, `g_packetSender`, PacketBuffer writers, `QueueAndSendPacket`, `SetProtectedPasswordToken`, MemoryMan copy helper, and sibling packet helpers.
- Inference: source-facing helper/field names and `void` return type. These are reasoned from caller semantics, sibling source style, and tail-call behavior, not recovered symbols.
- Stale/generated evidence handling: generated source is used only as historical pre-callback empty-emitter evidence, not as authority for final names or source ownership. Callback validators reported `generated_refresh: deferred`.

## Heuristic / Inference Reanalysis And Validation
- Blank C++ blocker reanalysis: the old blocker said packet field/global names were below source quality. Current evidence resolves enough of the behavior and support vocabulary for first-draft code. `g_packetSender`, `QueueAndSendPacket`, PacketBuffer write helpers, `ApplicationActiveGate` / `g_applicationActiveGate`, `SetProtectedPasswordToken`, and `memmove` source style are supported by current docs. The two login-specific config fields remain inferred, but exact offsets and use are known and can be represented with descriptive names while capping score.
- Return type reanalysis: Hex-Rays emits `int __stdcall` because the body tail-calls `sub_4657D0(a2)` after `QueueAndSendPacket`. Sibling [UID:0002QC] uses `static void __stdcall` when the binary's apparent return is only a tail/helper value. UID0002Q5 has no caller use of a return value; `0x004fadbd` just invokes the request helper before login wait-pane flow. Source-level `void` is the best shape.
- `sub_516030` / `sub_516220` reanalysis: target binary calls `GetMemoryMan()` and the MemoryMan `MemmoveWrapper` for payload copies. Sibling packet send helpers represent that as source-level `memmove(...)`, so formal UID0002Q5 code should not expose `GetMemoryMan()` or raw MemoryMan copy calls.
- Packet writer reanalysis: existing [UID:0003YJ] names `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, and `PacketBufferWriteUInt32BE`, with value-first ABI and local spare-zero behavior. UID0002Q5 should use these names for opcode, field lengths, config/session dword, zero byte, OS token, display flag, dimensions, and challenge-mask bytes.
- Config field reanalysis: MCP decompile and disasm prove `g_pConfig + 0x28de34` dword and byte reads at `+0x28de39`, `+0x28de3a`, `+0x28de3d`, `+0x28de3f`, `+0x28de41`, `+0x28de43`, `+0x28de45`, and `+0x28de47` (all conversions verified through MCP `int_convert`). No current by-* support page provides final names for this cluster. Best source-facing recommendation is an inferred dword such as `m_loginChallengeKey` at `+0x28de34` and an inferred byte array/base such as `m_loginChallengeMask` at `+0x28de39`, with observed indices `0`, `1`, `4`, `6`, `8`, `10`, `12`, and `14`.
- Application active/display flag reanalysis: target reads `dword_67A93C == 0`. Current [UID:00028Z] `ApplicationLifecycleFlags` names this storage `g_applicationActiveGate` in formal C++ and documents its use by activation and ScreenPane restore paths. Use `g_applicationActiveGate == 0`, not a new fullscreen/windowed name.
- Source placement reanalysis: the single caller is `LoginDialogPane` command handling at `0x004fadbd`; by-file [UID:0000KX] already routes UID0002Q5 to the login source family. No `this` pointer, vtable slot, class method route, Socket ownership, PacketBuffer ownership, Config ownership, PasswordGuard ownership, MemoryMan ownership, or aggregate ownership is supported.
- No-code alternative reanalysis: no-code is rejected. This target is a modeled live function, has a direct caller, owner/emitter clears the gate, exact behavior is known, sibling packet helpers already use the same PacketBuffer/memmove/QueueAndSendPacket vocabulary, and unresolved exact original names are confidence caps rather than a hard no-code proof.

## Evidence Standards Used
- IDA MCP current-session evidence: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, `find_bytes`, `make_signature_for_function`, `make_signature_for_range`, and `int_convert`.
- Binary-context standard: function boundaries and call edges are direct MCP facts; source owner is inferred only after checking caller, adjacent source family, generated route, and rejected helper owners.
- Documentation standard: by-* docs and executed B reports are used as support only when current and corroborated; stale generated names such as `SendLoginRequest_004FB2D0` are historical aliases, not source names.
- Confidence limitation: no original PDB/source symbol proves exact helper and config field spellings; score remains below final despite first-draft readiness.

## Evidence Checked
- IDA MCP checks performed under `6eab6bcb`:
  - `idb_list`: active NexusTK IDB session `6eab6bcb`, worker PID `12112`, not analyzing.
  - `server_health`: status ok, Hex-Rays ready, strings cache ready.
  - `lookup_funcs`: target `0x004fb2d0` is `sub_4FB2D0`, size `0x35a`; `0x004fb62a` is not a function; successor `0x004fb630` is `sub_4FB630`, size `0x99f`; caller container `0x004fad00` is size `0x122`; support callees at `0x004657d0`, `0x00574bb0`, `0x00575380`, `0x005753a0`, and `0x005753f0` were resolved.
  - `xrefs_to`: exactly one code xref to target start at `0x004fadbd` in `sub_4FAD00`; no xrefs to `0x004fb62a` or `0x004fb629`; successor `0x004fb630` has its own caller at `0x004fa74e`; `SetProtectedPasswordToken` has one xref from target tail at `0x004fb60b`.
  - `callees`: `sub_516030`, `sub_516220`, `sub_5753F0`, `sub_575380`, `GetVersionExW`, `GetDesktopWindow`, `GetWindowRect`, `sub_5753A0`, `_rand`, `Sleep`, `sub_574BB0`, `sub_4657D0`, security cookie, and `___report_rangecheckfailure`.
  - `decompile`: shows opcode `3`, two `WideCharToMultiByte` fields, `>=0x100` guards, config dword/byte reads, OS version packing, desktop rectangle dimensions, 13-byte random challenge, eight XOR challenge bytes, `Sleep(rand()%400+200)`, `QueueAndSendPacket`, and tail call to password token helper.
  - `disasm`: first page shows stack frame `0x340`, opcode write, conversion loops, PacketBuffer writer calls; tail page shows final length guard, local terminator, sleep, `sub_574BB0(dword_67A7EC, packet, length)`, `sub_4657D0(password)`, `retn 8`, and rangecheck island.
  - `get_bytes`: start bytes begin `55 8b ec 81 ec 40 03 00 00`; tail bytes at `0x004fb620` show `retn 8`, rangecheck call, six `0xcc` bytes, and successor prologue; `0x004fb62a` begins six `0xcc` bytes then `0x004fb630` prologue.
  - `find_bytes`: raw VA patterns for `0x004fb2d0`, `0x004fb62a`, `0x004fb629`, and `0x004fb630` returned zero matches, so no pointer/immediate route overrides the ordinary code xref evidence.
  - Signatures: function-entry signature `55 8B EC 81 EC 40 03 00 00`; range `0x004fb2d0-0x004fb310` signature was unique.
  - `int_convert`: verified `0x35a` = 858, `0x114` = 276, `0x100` = 256, `0x0d` = 13, `0xc8` = 200, `0x190` = 400, and config decimal offsets `2678324..2678343` as `0x28de34`, `0x28de39`, `0x28de3a`, `0x28de3d`, `0x28de3f`, `0x28de41`, `0x28de43`, `0x28de45`, and `0x28de47`.
- Support/docs checked: target, LoginDialogPane class/file/core, generated `LoginDialogPane.cpp`, PacketBuffer writers, QueueAndSendPacket, g_packetSender global pages, g_pConfig, ApplicationLifecycleFlags, SetProtectedPasswordToken, MemoryMan copy helpers, sibling password-change packet helpers, active/archived B reports.
- Negative checks performed: endpoint xrefs, raw VA pointer/immediate byte search, class-method/vtable route review, helper-owner alternatives, aggregate/successor inclusion, no-code proof burden, and generated recovered-name reliance.
- Failed/skipped checks during the initial MCP evidence pass: initial MCP `initialize` without required client params and no-database tool calls returned schema errors; this was corrected by reading schema and retrying with `database=6eab6bcb`. No IDA mutation, process management, broad listings, validators, or lifecycle commands were run during research. Scoped validators were run later only after the implementation callback, as recorded below.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002Q5-001 | UID0002Q5 is one modeled function at `0x004fb2d0-0x004fb62a`, size `0x35a`, with six-byte padding before successor `0x004fb630`. | High | MCP `lookup_funcs`, `get_bytes`, `disasm`, xrefs to endpoints. | Target Covered Range / IDA MCP Evidence / Range section. | applied | Target page records MCP session `6eab6bcb`, exact range/size, successor padding, endpoint negatives, and validator `000000006126` exited `0` / `ok:1`. |
| C-0002Q5-002 | Direct source owner remains [UID:0000KX] `LoginDialogPane.cpp`; not class method or generated recovered standalone file. | High | Single caller `0x004fadbd` in LoginDialogPane command handler; by-file placement; no `this`/vtable route. | Target Status/Corrected Assignment Gate; by-file/by-class support. | applied | Target, by-file, and by-class pages route UID0002Q5 through [UID:0000KX] as a file-local helper and preserve no class-member route; validators `000000006126`, `000000006127`, and `000000006128` passed. |
| C-0002Q5-003 | Old blank-C++ blocker is stale; first-draft formal C++ is defensible with inferred config field names and confidence caps. | High | Current decompile/disasm behavior; sibling packet helper source style; support helper names. | Target Reconstruction Notes / formal C++ block. | applied/historicalized | Target formal C++ block is populated; old blank-C++/global-name blocker is explicitly historicalized with inferred config-name confidence caps. |
| C-0002Q5-004 | Formal source should be `static void __stdcall SendLoginRequest(const wchar_t* accountName, const wchar_t* password)`. | Medium-high | Binary ABI has two wide-string args; caller passes account/password buffers; return is unused tail helper value; sibling UID0002QC style. | Target formal C++; by-file LoginDialogPane row. | applied | Exact formal signature/body inserted in target; by-file and by-class rows name the same source-ready file-local helper. |
| C-0002Q5-005 | Packet behavior: opcode `0x03`, two length-prefixed multibyte fields, config dword, zero byte, OS token, active-gate flag, desktop width/height, 13-byte challenge, eight XOR mask bytes, random delay, queue send, password token update. | High | MCP decompile, disasm, callees, int_convert offsets/constants. | Target Behavior / IDA MCP Evidence / C++ block. | applied | Target behavior/evidence and formal C++ preserve the full observed packet layout, `Sleep(rand()%400+200)`, `QueueAndSendPacket`, and `SetProtectedPasswordToken`. |
| C-0002Q5-006 | Use `PacketBufferWriteUInt8/UInt16BE/UInt32BE`, `memmove`, `QueueAndSendPacket(g_packetSender, ...)`, `g_applicationActiveGate`, and `SetProtectedPasswordToken` support names. | High | Existing support docs and sibling packet sender pages. | Target helper table and support docs. | applied/already-present | Target code uses these names. PacketBuffer, QueueAndSendPacket, g_packetSender, ApplicationLifecycleFlags, MemoryMan memmove, and SetProtectedPasswordToken docs were inspected and already had same-or-greater support detail, so they were not edited. |
| C-0002Q5-007 | Config field names should be marked inferred: dword at `+0x28de34` and byte mask base at `+0x28de39` with observed sparse indices. | Medium | MCP decompile/disasm and int_convert; g_pConfig docs lack final field names. | Target notes; g_pConfig support doc. | applied | Target notes and [UID:00028Q] g_pConfig now document inferred `m_loginChallengeKey` and `m_loginChallengeMask` with sparse indices `0`, `1`, `4`, `6`, `8`, `10`, `12`, and `14`; validator `000000006130` passed with existing unrelated missing-ref UID warnings. |
| C-0002Q5-008 | Reject Socket, PacketBuffer, MemoryMan, PasswordGuard, Config, LoginDialogPane class, MainMenu aggregate, NewUser successor, and no-owner/no-code alternatives. | High | Callee/dependency roles, ownership docs, xrefs, range/padding, no-code reanalysis. | Target negative evidence; by-file/class notes. | applied | Target added explicit negative evidence/rejected owners; by-file/class support preserves file-local route and no class-member ownership. |
| C-0002Q5-009 | Generated empty-emitter marker is a pre-callback defect, not desired final state. | High | Generated `LoginDialogPane.cpp` header and target blank formal C++. | Target status/changes; by-file LoginDialogPane generated status. | historicalized/applied | Target/by-file report text now marks recovered `SendLoginRequest_004FB2D0` and old empty-emitter state as historical. Callback validators reported generated refresh deferred, so no fresh generated-output claim is made. |
| C-0002Q5-010 | Recommended score `90/92` with owner/emitter unchanged. | High | Resolved behavior/source route/C++ readiness; caps from original spellings and config field names. | Target metadata and score rationale. | applied | Target metadata is `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter [UID:0000KX] unchanged, reconstructable true, optional blank; validator `000000006126` applied completion/confidence updates. |

## Positive Evidence Summary
- Modeled function and exact range: MCP reports `sub_4FB2D0` at `0x004fb2d0`, size `0x35a`, and not-a-function at end `0x004fb62a`.
- Live caller: exactly one direct caller, `0x004fadbd` in `LoginDialogPane` command handler `0x004fad00`, matching target's login account/password submission role.
- Behavior: current decompile and disassembly agree on opcode `0x03`, two wide-to-multibyte fields, bounded local packet/conversion buffers, config/session value, OS/version/window metadata, random challenge and XOR mask, send through `g_packetSender`, and password token storage.
- Source-family support: [UID:0000KX] already owns LoginDialogPane file-local helpers and generated route `NexusTK/login/LoginDialogPane.cpp`; B001 EnsureLoginDialogPane evidence says nearby private login helpers belong in this file and broader account-dialog split is not a first-draft blocker.
- Helper support: PacketBuffer writers, QueueAndSendPacket, g_packetSender, ApplicationActiveGate, MemoryMan memmove wrapper, and SetProtectedPasswordToken pages already provide source-facing names or accepted descriptive roles.
- Strongest inference chain: a single live caller in LoginDialogPane command handling plus exact packet request behavior plus existing file parent route is stronger than raw recovered helper names, adjacency to successor dialogs, or shared callee ownership.

## IDA MCP Facts
- Function/range facts: `0x004fb2d0` is `sub_4FB2D0`, size `0x35a`; `0x004fb62a` is not a function; `0x004fb630` is a separate `0x99f` function.
- Data/table/padding facts: bytes at `0x004fb620` show final return/rangecheck island followed by six `0xcc` bytes before `0x004fb630`; bytes at `0x004fb62a` are `cc cc cc cc cc cc` then successor prologue.
- Xref facts: one code xref to target start from `0x004fadbd`; zero xrefs to end or last byte; one xref to `SetProtectedPasswordToken` from target tail; successor has unrelated caller `0x004fa74e`.
- Helper/global facts: target refs `dword_67A7C8` (`g_pConfig`), `dword_67A7EC` (`g_packetSender`), `unk_67A93C` (`g_applicationActiveGate` support name), PacketBuffer writers, MemoryMan copy helper, Win32 APIs, `rand`, `Sleep`, and protected password helper.
- Negative IDA facts: no raw VA pointer/immediate matches for target start/end/last byte/successor; no xrefs to padding endpoints; no vtable/name evidence for class-method routing; no extra child functions inside target range.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004fb2d0-0x004fb62a` | [UID:0002Q5] `by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md` | Login packet request builder/sender | `TRUE` | [UID:0000KX] `LoginDialogPane.cpp` | current `86/88`, recommended `90/92` | Source-ready first-draft C++ recommended. |
| `0x004fb62a-0x004fb630` | no UID; padding | Six `0xcc` bytes | N/A | N/A | N/A | Keep outside UID0002Q5 source body. |
| `0x004fb630-...` | successor `sub_4FB630` / separate NewUserMisc constructor target | Adjacent separate function | separate page | not UID0002Q5 | N/A | Exclude from UID0002Q5. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004fadbd -> 0x004fb2d0` | only code xref to target start, inside `sub_4FAD00` size `0x122` | LoginDialogPane command handler calls helper after gathering account/password controls. |
| `0x004fb60b -> 0x004657d0` | only xref to `SetProtectedPasswordToken` support target | Tail stores/protects the submitted password after queueing request. |
| `0x004fb605 -> 0x00574bb0` | `QueueAndSendPacket(g_packetSender, packet, length)` | Sends constructed packet through Socket-owned sender. |
| `0x004fb3f1`, `0x004fb42f` | `PacketBufferWriteUInt32BE` | Writes config challenge key and OS version token. |
| Multiple `0x004fb401..0x004fb5c8` | `PacketBufferWriteUInt8` / `PacketBufferWriteUInt16BE` | Writes zero byte, active gate flag, dimensions, and XOR challenge bytes. |
| `0x004fb630` | successor has caller `0x004fa74e` in `sub_4FA5B0` | Separate NewUserMisc constructor, not part of target. |

## Documentation Evidence And IDA Status
- Existing target page supports conclusion: it already names exact helper bounds, single caller, packet-writing behavior, config/global dependencies, randomized challenge, and LoginDialogPane file owner.
- Stale/incomplete target text: blank-C++ rationale says final packet field/global names are not source quality. That is now too conservative because support docs and this pass resolve source shape enough for first draft.
- by-file LoginDialogPane supports owner but is stale in proposed contents: it lists `SendLoginRequest` under `recovered/SendLoginRequest_004FB2D0.cpp`; after callback it should say source-ready private helper in `login/LoginDialogPane.cpp`.
- by-class LoginDialogPane is mostly correct: it states UID0002Q5 is file-local and not a virtual/member method. It should be updated only to source-ready helper status and to preserve no-class-member negative evidence.
- LoginDialogPaneCore supports caller semantics: command handler reads controls `3` and `4` into 15-character buffers, may pass shifted stack-buffer pointers under config/rand branches, calls UID0002Q5, copies account to `g_pMainUiGraph+252`, and opens wait pane.
- Generated output state at report-only time: `auto-generated/NexusTK/login/LoginDialogPane.cpp` showed UID0002Q5 as an empty emitter marker under command `000000006061`; this is historical pre-callback defect evidence, and callback validators later reported generated refresh deferred.

## Ranked Ownership Analysis

### 1. [UID:0000KX] LoginDialogPane file / `NexusTK/login/LoginDialogPane.cpp`
- Evidence for: one caller from LoginDialogPane command handling; target starts immediately after LoginDialogPane core; by-file page already routes helper to login family; generated route lands in `LoginDialogPane.cpp`; helper builds the login credential request, not a shared protocol primitive.
- Evidence against: exact original helper spelling is not symbol-proven; broader account-dialog split is still partly unresolved.
- Decision: best owner/emitter. Broader account-dialog split is a confidence cap, not a blocker for this exact file-local helper.

### 2. [UID:00007F] LoginDialogPane class
- Evidence for: direct caller belongs to LoginDialogPane command handling and passes account/password values from LoginDialogPane controls.
- Evidence against: helper has no `this` argument, no vtable slot, no class method dispatch, and class page already treats it as file-local.
- Decision: reject class direct owner. Update class notes only to identify it as a source-ready file-local helper used by the class.

### 3. Socket / PacketBuffer / MemoryMan / PasswordGuard / Config
- Evidence for: target calls `QueueAndSendPacket`, PacketBuffer writers, MemoryMan memmove wrapper, password token helper, and reads Config/application globals.
- Evidence against: each is a shared dependency. None chooses opcode `0x03`, login credential fields, OS/window metadata, challenge layout, or caller route.
- Decision: reject as owners; keep as support dependencies.

### 4. Broad MainMenuLoginAndAccountDialogs / NewUser successor / ChangePassword siblings
- Evidence for: address neighborhood contains login/account dialog family and sibling account packet helpers.
- Evidence against: UID0002Q5 has an exact function and direct file parent; successor `0x004fb630` has separate caller/range; ChangePassword packet helpers are siblings with their own file route.
- Decision: reject aggregate or successor ownership.

### 5. No-owner / no-code / recovered standalone global
- Evidence for: exact original source symbol not recovered and config field names remain inferred.
- Evidence against: modeled live function, direct caller, owner/emitter gate cleared, exact behavior known, sibling source style exists, and generated empty marker is a defect.
- Decision: reject. Use first-draft formal C++ with confidence caps.

## Source Placement
- Recommended placement: private/static helper in [UID:0000KX] `LoginDialogPane.cpp`, generated under `NexusTK/login/LoginDialogPane.cpp`.
- Why it fits: LoginDialogPane command handler is the only caller; the helper serializes exactly the login credential request; by-file [UID:0000KX] already includes UID0002Q5 as a proposed content item; B001 login helper precedent supports file-local login helper source in this file.
- Rejected placements: LoginDialogPane class method, Socket.cpp, PacketBuffer.cpp, MemoryMan.cpp, Config.cpp, PasswordGuard.cpp, MainMenu aggregate, NewUserDialogPane, ChangePasswordDialogPane, and a recovered standalone file.
- Remaining placement uncertainty: exact file split among `LoginDialogPane.cpp`, `NewUserDialogPane.cpp`, and `ChangePasswordDialogPane.cpp` is still partly unresolved at the family level. It does not dislodge UID0002Q5 because the sole caller and existing file route are LoginDialogPane-specific.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: start `0x004fb2d0`, end-exclusive `0x004fb62a`, size `0x35a`; `0x004fb62a-0x004fb630` is six bytes of `0xcc`; successor `0x004fb630` has separate function and caller.
- Children/subranges: none recommended. The target is one source function with internal rangecheck island at `0x004fb625`; this is still target code, not a separate child.
- Predecessor boundary: LoginDialogPane core ends at `0x004fb2d0` after local table/padding; no fallthrough into UID0002Q5.
- Parent/container impact: no split or parent conversion needed. This is an emitting child under [UID:0000KX].

## Negative Evidence Summary
- No class-member route: no `this`, no vtable ref, no method slot, and the class page already treats UID0002Q5 as a file-local helper.
- No Socket/PacketBuffer ownership: those helpers send/write bytes but do not own login opcode `0x03`, credential fields, challenge layout, or caller route.
- No MemoryMan ownership: MemoryMan helper evidence explains binary `memmove` lowering only; formal feature source should use `memmove(...)`.
- No PasswordGuard ownership: `SetProtectedPasswordToken` is only a tail dependency receiving the password after send.
- No Config/Application ownership: target reads config and active-gate fields; reader/consumer use does not own the login helper.
- No broad aggregate ownership: exact function and source-file route are known; aggregate pages are context.
- No padding/range extension: bytes and xrefs prove six-byte padding after `0x004fb62a`; successor at `0x004fb630` is separate.
- No fallback-only report: current MCP session `6eab6bcb` provides live evidence; historical MCP downtime is not used as a final basis.

## IDA Rename / Type / Comment Recommendations
- No IDA database edits were requested or made by B005 in either the report-only pass or the implementation callback.
- Source-facing names recommended for docs/C++:
  - `SendLoginRequest` for `0x004fb2d0`, inferred from target name, file route, and caller behavior.
  - `accountName` and `password` for the two arguments, inferred from LoginDialogPane command handler controls.
  - `g_applicationActiveGate` for `0x0067a93c`, already formalized by [UID:00028Z].
  - `m_loginChallengeKey` for `g_pConfig + 0x28de34` and `m_loginChallengeMask` for byte base `g_pConfig + 0x28de39`, both inferred/descriptive and not original-proof.
  - `SetProtectedPasswordToken` for `0x004657d0`, accepted descriptive support name in [UID:0002VG].
- Items intentionally left non-final: exact original helper/global/config field spellings and final Config struct layout. These are confidence caps, not code blockers.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The target is reconstructable, has nonblank emitter [UID:0000KX], clears the source route, has exact behavior, and no target-specific no-code proof survives the current evidence pass.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` insertion text for UID0002Q5:

```cpp
static void __stdcall SendLoginRequest(const wchar_t* accountName, const wchar_t* password)
{
    char packet[0x100];
    char converted[0x100];
    unsigned char challenge[13];
    OSVERSIONINFOW versionInfo;
    RECT desktopRect;

    short accountNameLength = static_cast<short>(wcslen(accountName));
    short passwordLength = static_cast<short>(wcslen(password));

    PacketBufferWriteUInt8(0x03, packet);

    int accountNameByteLength = WideCharToMultiByte(0, 0, accountName, accountNameLength, converted, 0x100, NULL, NULL);
    if (accountNameByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[accountNameByteLength] = 0;
    PacketBufferWriteUInt8(accountNameByteLength, packet + 1);
    memmove(packet + 2, converted, accountNameByteLength);

    int passwordByteLength = WideCharToMultiByte(0, 0, password, passwordLength, converted, 0x100, NULL, NULL);
    if (passwordByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[passwordByteLength] = 0;
    PacketBufferWriteUInt8(passwordByteLength, packet + accountNameByteLength + 2);
    memmove(packet + accountNameByteLength + 3, converted, passwordByteLength);

    unsigned int packetLength = static_cast<unsigned int>(accountNameByteLength + passwordByteLength + 3);

    PacketBufferWriteUInt32BE(g_pConfig->m_loginChallengeKey, packet + packetLength);
    packetLength += 4;

    PacketBufferWriteUInt8(0, packet + packetLength);
    ++packetLength;

    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    GetVersionExW(&versionInfo);

    unsigned int osVersion =
        static_cast<unsigned char>(versionInfo.dwMinorVersion) |
        (static_cast<unsigned char>(versionInfo.dwMajorVersion) << 8) |
        (static_cast<unsigned char>(versionInfo.dwPlatformId) << 16);
    PacketBufferWriteUInt32BE(osVersion, packet + packetLength);
    packetLength += 4;

    GetWindowRect(GetDesktopWindow(), &desktopRect);
    PacketBufferWriteUInt8(g_applicationActiveGate == 0, packet + packetLength);
    ++packetLength;

    PacketBufferWriteUInt16BE(static_cast<unsigned short>(desktopRect.right), packet + packetLength);
    packetLength += 2;
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(desktopRect.bottom), packet + packetLength);
    packetLength += 2;

    for (int i = 0; i < 13; ++i)
        challenge[i] = static_cast<unsigned char>(rand());

    memmove(packet + packetLength, challenge, 13);
    packetLength += 13;

    const unsigned char* challengeMask = g_pConfig->m_loginChallengeMask;
    PacketBufferWriteUInt8(challenge[8] ^ challengeMask[4], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[4] ^ challengeMask[1], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[7] ^ challengeMask[6], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[11] ^ challengeMask[12], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[3] ^ challengeMask[8], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[1] ^ challengeMask[10], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[9] ^ challengeMask[14], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[2] ^ challengeMask[0], packet + packetLength);
    ++packetLength;

    if (packetLength >= 0x100)
        __report_rangecheckfailure();

    packet[packetLength] = 0;
    Sleep(rand() % 400 + 200);
    QueueAndSendPacket(g_packetSender, packet, packetLength);
    SetProtectedPasswordToken(password);
}
```

- Reason it preserves exact original behavior: it keeps opcode `0x03`, `0x100` conversion/packet buffer limits, rangecheck failure paths, local terminators, exact field order, config offset mapping, OS token byte packing, `g_applicationActiveGate == 0`, desktop `right`/`bottom` low-16 writes, 13 random bytes, eight XOR writes in observed order, final local terminator, `Sleep(rand()%400+200)`, queue send length, and post-send password token write.
- Reason it matches plausible original source shape: it follows accepted sibling `SendPasswordChangeRequest` style, using file-local `static void __stdcall`, `PacketBufferWrite*`, `memmove`, and `QueueAndSendPacket(g_packetSender, ...)` rather than raw `sub_` names or decompiler temporaries.
- Inferred names/types used: `SendLoginRequest`, `accountName`, `password`, `m_loginChallengeKey`, `m_loginChallengeMask`, and `g_applicationActiveGate` are source-facing descriptive names; only support docs already establish some names. Exact original spellings remain unproven.
- Reason code should not remain blank: target has a modeled function, direct caller, exact owner/emitter, and support vocabulary. Remaining uncertainty is local naming, not behavior/source-route.

## Final Recommendation
- Apply target metadata: `COMPLETION:90`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000KX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KX`, and blank optional position.
- Insert the first-draft C++ block above into the target formal `RECONSTRUCTION_CPP CODE` block.
- Update target prose to historicalize the old blank-C++ blocker and generated `SendLoginRequest_004FB2D0` recovered-file language.
- Preserve exact MCP session `6eab6bcb` evidence, caller/callee/range bytes, config offset mapping, random challenge layout, support names, negative evidence, and rejected owners.
- Update support docs named below where stale; do not create child pages or split the target.
- Future work outside this assignment: original source/header proof for exact config field spellings and final Config layout. This should not block UID0002Q5 first-draft emission.

## Recommended Target Doc Changes
- Target path: `by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md`.
- Exact report facts to incorporate:
  - Current MCP session `6eab6bcb` health/session facts.
  - `lookup_funcs` range: `0x004fb2d0`, size `0x35a`, end `0x004fb62a`; `0x004fb62a` not a function; successor `0x004fb630` separate.
  - Single caller `0x004fadbd` in `0x004fad00`; no xrefs to end/last byte; no raw VA pointer/immediate matches for start/end/last/successor.
  - Callee/helper set and source-facing names.
  - Full packet layout and challenge-mask order.
  - Application/config/global field inference and confidence caps.
  - Rejected owner alternatives and no-code rejection.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:90`, `CONFIDENCE:92`.
  - Keep owner/emitter/reconstructable as `0000KX`/`0000KX`/`TRUE`.
  - Insert formal C++ exactly from this report.
- Historical/stale assumptions to preserve: old empty-emitter/no-code rationale was valid before config/helper/source-style reanalysis but is superseded; recovered `SendLoginRequest_004FB2D0` is a generated alias, not final source placement.

## Recommended Support Doc Changes
- `by-file/LoginDialogPane.md`:
  - Update UID0002Q5 row from `recovered/SendLoginRequest_004FB2D0.cpp` / blank-helper wording to private source-ready helper in `login/LoginDialogPane.cpp`.
  - Preserve broader account-dialog split caveat, but state it does not block this exact helper.
  - Suggested row text: `SendLoginRequest` | [UID:0002Q5][0x004fb2d0-0x004fb62a.SendLoginRequest](by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md) | private helper in `login/LoginDialogPane.cpp` | Source-ready login packet sender: serializes account/password, config login challenge key/mask bytes, OS/window metadata, randomized challenge, queues through `g_packetSender`, and updates the protected password token. Exact helper/config field names remain inferred.
- `by-class/LoginDialogPane.md`:
  - Keep no-class-member/no-virtual evidence.
  - Update related helper/method inventory note to say UID0002Q5 is a source-ready file-local helper used by LoginDialogPane command handling, not a class method.
  - Suggested note: `UID0002Q5 SendLoginRequest` is not a `LoginDialogPane` method; the command handler calls a file-local `static void __stdcall SendLoginRequest(const wchar_t* accountName, const wchar_t* password)` helper after reading the account/password controls. The helper emits through [UID:0000KX], not through the class UID.
- `by-memory/0x004fa7a0-0x004fb2d0.LoginDialogPaneCore.md`:
  - If stale, update the command-handler note so its handoff target is source-ready `SendLoginRequest(accountName, password)` and preserve the shifted-buffer caveat from the caller.
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`:
  - Add or update login challenge field notes for dword `+0x28de34` (`m_loginChallengeKey`, inferred) and byte mask base `+0x28de39` (`m_loginChallengeMask`, inferred) with observed indices `0`, `1`, `4`, `6`, `8`, `10`, `12`, `14`.
  - Suggested field table rows:
    - `g_pConfig + 0x28de34` / `m_loginChallengeKey` / `uint32_t`, inferred: UID0002Q5 writes this dword to the login request before the client environment block through `PacketBufferWriteUInt32BE`.
    - `g_pConfig + 0x28de39` / `m_loginChallengeMask` / byte mask base, inferred: UID0002Q5 XORs the 13-byte random login challenge against sparse indices `0`, `1`, `4`, `6`, `8`, `10`, `12`, and `14`; exact original array/field spelling remains unresolved.
- `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`:
  - Likely already present; if touched for sync, confirm UID0002Q5 consumes `g_applicationActiveGate == 0` as a packet byte but does not own the global.
- `by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md`:
  - Likely already sufficient; if touched for sync, record UID0002Q5 as direct caller and preserve that this helper's own declaration remains support-owned.
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`, `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`, `by-global/g_packetSender.md`, and MemoryMan memmove pages:
  - No edit required if current names and dependency facts remain same-or-greater detail. Use as already-present proof in callback ledger.

## Score And Metadata Recommendation
- Current score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, owner/emitter [UID:0000KX], reconstructable true, blank formal C++.
- Recommended score/metadata: `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter unchanged, reconstructable true, optional position blank, formal C++ populated.
- Score rationale: completion improves because the first-draft source, exact packet layout, config offsets, support helpers, caller route, range/padding, and rejected alternatives are now implementation-ready. Confidence improves because MCP session `6eab6bcb` reconfirmed live IDB facts and support docs resolve helper names. Completion is not higher because exact original spellings for the helper and config field names remain inferred and the final Config declaration is not fully mapped. Confidence is not higher because source-file family split among login/account dialogs still has some broader uncertainty, even though it does not displace this exact helper.
- Score-improvement attempt:
  - Function/range blocker: resolved by MCP `lookup_funcs`, `get_bytes`, disasm, and xrefs.
  - Caller/source-route blocker: resolved by single xref and LoginDialogPane file/class/core docs.
  - Helper-name blocker: resolved through PacketBuffer, QueueAndSendPacket, g_packetSender, ApplicationLifecycleFlags, MemoryMan, and password-token support pages.
  - Config-field blocker: converted into implementation-ready inferred names with exact offsets/indices and confidence cap.
  - No-code blocker: rejected after sibling packet helper comparison and no-code proof audit.
- Metadata fields to leave unchanged: `CANONICAL_OWNER:0000KX`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KX`, `EMITTER_POSITION_OPTIONAL:`.

## Open Questions With Attempted Resolution
- Exact original `SendLoginRequest` spelling:
  - Evidence checked: target name, generated alias, by-file row, B001 login helper report, caller behavior, archived reports.
  - Resolution: use `SendLoginRequest` as inferred source-facing name; do not keep address-suffixed recovered alias in source.
  - Remaining impact: confidence cap only.
- Exact config field names and declaration:
  - Evidence checked: MCP decompile/disasm offsets, `int_convert`, current `g_pConfig` doc, surrounding config docs.
  - Resolution: recommend inferred `m_loginChallengeKey` and `m_loginChallengeMask` with exact offsets and observed indices.
  - Remaining impact: caps completion below final; does not block first-draft code because behavior and offsets are exact.
- Meaning of `dword_67A93C` in this packet:
  - Evidence checked: current `ApplicationLifecycleFlags` support page and target decompile.
  - Resolution: use existing `g_applicationActiveGate == 0`; do not invent window/fullscreen-specific name.
  - Remaining impact: no C++ blocker, only semantic naming caveat.
- Source-level return type:
  - Evidence checked: decompile tail return, caller use, sibling UID0002QC style.
  - Resolution: `void`; tail helper return is not meaningful source output.
- Broader account-dialog source split:
  - Evidence checked: LoginDialogPane file page, B001 EnsureLoginDialogPane report, sibling ChangePassword/NewUser docs.
  - Resolution: not blocking; exact caller and file route support LoginDialogPane.cpp.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. No manual coverage report, supervisor-owned tracker, generated C++ file, lifecycle state, archive, or supervisor ledger was manually edited by B005. Scoped validators reported generated refresh deferred for the callback commands below.

## Follow-Up Actions
- Supervisor-owned execution/lifecycle is outside B005 scope. This artifact records the implemented callback and stops before `execute_report`.
- B005 callback actions completed: leased the five by-* pages that required edits, applied target/support updates at report-level detail, ran scoped validators for every changed by-* file, updated this report's ledger/checklist with applied/already-present/historicalized proof, and confirmed the current lease report shows no active leases.
- Remaining unapplied accepted items: none. Support docs for ApplicationLifecycleFlags, SetProtectedPasswordToken, PacketBuffer scalar writers, QueueAndSendPacket, g_packetSender, and MemoryMan memmove were inspected and excluded from editing because they already carried same-or-greater support detail.

## Confidence
- Recommendation confidence: high. The owner/emitter route, behavior, and first-draft C++ readiness are all supported by live MCP and current docs.
- Score confidence: high for `90/92`; a higher score would overstate exact original field/name certainty.
- Remaining uncertainty: exact helper spelling, final Config field declaration/name, and broader account-dialog file split. None changes the recommended target owner or first-draft C++ disposition.

## Validator Results
- `python .\tools\validator.py --mode file --file by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md --apply --queue-timeout 240`
  - `command_id: 000000006126`; `command_timestamp: 2026-07-04T05:18:06-04:00`; exit `0`; `ok: 1`; warnings/errors `0`.
  - Applied target completion/confidence to `90/92`, autogen registry hash/status updates, UID link inserts for [UID:0000KX]/[UID:00007F], reference-index adds for [UID:0000Q5]/[UID:00028Z]/[UID:0002VG], and validator-managed projected stats update.
  - `generated_refresh: deferred`; `generated_refresh_command_id: 000000006126`; `generated_refresh_timestamp: 2026-07-04T05:18:06-04:00`.
- `python .\tools\validator.py --mode file --file by-file/LoginDialogPane.md --apply --queue-timeout 240`
  - `command_id: 000000006127`; `command_timestamp: 2026-07-04T05:18:14-04:00`; exit `0`; `ok: 1`; warnings/errors `0`.
  - `generated_refresh: deferred`; `generated_refresh_command_id: 000000006127`; `generated_refresh_timestamp: 2026-07-04T05:18:14-04:00`.
- `python .\tools\validator.py --mode file --file by-class/LoginDialogPane.md --apply --queue-timeout 240`
  - `command_id: 000000006128`; `command_timestamp: 2026-07-04T05:18:24-04:00`; exit `0`; `ok: 1`; warnings/errors `0`.
  - Validator inserted two [UID:0000KX] links and reported `generated_refresh: deferred`; `generated_refresh_command_id: 000000006128`; `generated_refresh_timestamp: 2026-07-04T05:18:24-04:00`.
- `python .\tools\validator.py --mode file --file by-memory/0x004fa7a0-0x004fb2d0.LoginDialogPaneCore.md --apply --queue-timeout 240`
  - `command_id: 000000006129`; `command_timestamp: 2026-07-04T05:18:34-04:00`; exit `0`; `ok: 1`; warnings/errors `0`.
  - `generated_refresh: deferred`; `generated_refresh_command_id: 000000006129`; `generated_refresh_timestamp: 2026-07-04T05:18:34-04:00`.
  - Read-only generated freshness observation after validation: `auto-generated/NexusTK/login/LoginDialogPane.cpp` header shows `validator-command-id: 000000006129`, `validator-refreshed-at: 2026-07-04T05:18:34-04:00`, `validator-refresh-source: deferred-generated-refresh`, and now contains the UID0002Q5 `static void __stdcall SendLoginRequest(...)` block at `90/92`.
- `python .\tools\validator.py --mode file --file by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md --apply --queue-timeout 240`
  - `command_id: 000000006130`; `command_timestamp: 2026-07-04T05:18:47-04:00`; exit `0`; `ok: 1`; warnings `5` (`missing_ref_uid` for unrelated existing UID references `0003UJ` and `0003UA`); errors `0`.
  - Added reference index for [UID:0002Q5] and validator-managed projected stats update.
  - `generated_refresh: deferred`; `generated_refresh_command_id: 000000006130`; `generated_refresh_timestamp: 2026-07-04T05:18:47-04:00`.
- Lifecycle/report execution: not run. B005 did not run `execute_report`, dry-run/probing variants, archive moves, registry lifecycle commands, or validator state edits.

## Changed Files
- Modified by B005 callback:
  - `by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md`: set `90/92`, inserted formal `SendLoginRequest` C++, added MCP session `6eab6bcb` range/caller/callee/packet/challenge/padding evidence, rejected owners, and historical blank-emitter/recovered-alias wording.
  - `by-file/LoginDialogPane.md`: updated UID0002Q5 from recovered/blank-helper wording to private source-ready helper in `login/LoginDialogPane.cpp` and preserved the broader account-dialog split caveat as non-blocking.
  - `by-class/LoginDialogPane.md`: updated related helper evidence to source-ready file-local helper emitted through [UID:0000KX], not a class member/virtual.
  - `by-memory/0x004fa7a0-0x004fb2d0.LoginDialogPaneCore.md`: updated command-handler handoff to source-ready `SendLoginRequest(accountName, password)` while preserving shifted-buffer caveat.
  - `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`: added inferred `m_loginChallengeKey` and `m_loginChallengeMask` notes with sparse indices.
  - `tools/leaser/Agents/Agent-B005/research/0002Q5-SendLoginRequest-source-quality.md`: updated ledger, checklist, validator results, changed-files proof, and lifecycle-neutral callback status.
- Inspected but not edited because already same-or-greater detail: `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`, `by-memory/0x004657d0-0x00465827.SetProtectedPasswordToken.md`, `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`, `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`, `by-global/g_packetSender.md`, and MemoryMan memmove support docs.
- Lease status: B005 successfully leased the five edited by-* pages before editing. After validation, `leaser.py B005 unlease ...` returned `Rejected[No active lease]` for each path; final `current_leases.md` check shows `No active leases.`
- Generated/manual coverage/lifecycle: no manual generated C++ files, project-level generated reports, manual `-coverage-report.md` files, supervisor ledgers, lifecycle/archive files, or report moves were edited by B005. Scoped validators reported generated refresh deferred; the generated `auto-generated/NexusTK/login/LoginDialogPane.cpp` was observed after validation with header command `000000006129` / `deferred-generated-refresh` and UID0002Q5 emitted. Validator-managed projected stats/reference/registry updates are listed above.
- Renamed: none.
- Report execution: not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation.
- [x] Target/support docs to update: target UID0002Q5, LoginDialogPane file/class/core support, g_pConfig field cluster note, and optional already-present support confirmations for ApplicationLifecycleFlags, PacketBuffer, QueueAndSendPacket, g_packetSender, MemoryMan memmove, and SetProtectedPasswordToken.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply: `90/92`, owner/emitter unchanged, reconstructable true, optional blank.
- [x] Score-limiting blockers researched to resolution or implementation-ready plan: source route resolved, no-code rejected, helper names resolved, config names converted to inferred implementation-ready names with caps.
- [x] Owner/emitter/reconstructable changes to apply: keep owner/emitter/reconstructable unchanged.
- [x] Split/rename/new-child changes to apply: none; exact range and padding prove no split.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: source placement to `LoginDialogPane.cpp`; no IDA DB edits; no child pages.
- [x] First-draft C++ or no-code proof to apply: first-draft formal C++ supplied under `First-Draft C++ Recommendation`.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: recorded in target/support recommendation sections.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old empty-emitter/no-code rationale, generated recovered alias, no class-member route, dependency-owner rejections, no range extension.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale when unsupported: generated output and old recovered filename used only as leads/evidence of current defect.
- [x] Open questions closed or documented as evidence-backed unresolved with score/C++ impact.
- [x] Validators to run: none during report-only; scoped callback validators are now recorded below.
- [x] Generated report refresh expected or manual supervisor-owned coverage/tracker text: no manual coverage text; callback validators reported generated refresh deferred.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation; callback applied to UID0002Q5 target/support docs.
- [x] All accepted target/support doc details incorporated at report-level detail: target formal C++, MCP session `6eab6bcb`, packet/challenge behavior, source route, rejected owners, stale blank-emitter historicalization, LoginDialogPane file/class/core support, and g_pConfig inferred challenge fields.
- [x] Claim And Incorporation Ledger updated with `applied`, `already-present`, or `historicalized/applied` proof for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target is `90/92`, owner/emitter [UID:0000KX] unchanged, reconstructable true, optional blank, no split/rename/new child, formal C++ populated.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: old empty-emitter/recovered alias historicalized; no class-member route, no dependency-owner route, no aggregate/successor/range extension, and no no-code disposition recorded.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: exact helper/config field spellings remain inferred confidence caps only.
- [x] Validators run and results recorded: `000000006126` through `000000006130`, all exit `0` / `ok:1`; only g_pConfig reported five unrelated existing `missing_ref_uid` warnings for `0003UJ`/`0003UA`.
- [x] Generated report refresh status recorded: scoped validators reported `generated_refresh: deferred`; generated `auto-generated/NexusTK/login/LoginDialogPane.cpp` header now shows command `000000006129` / `deferred-generated-refresh` with UID0002Q5 emitted; no manual generated/coverage/lifecycle edits.
- [x] Leases used and final state recorded: five by-* files leased successfully before editing; final current lease report shows no active leases.
- [x] Remaining unapplied accepted items listed with exact blocker: none; optional support docs were excluded from editing because same-or-greater detail was already present.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000006133","destination_path":"executed-b-agent-research/B005/0002Q5-SendLoginRequest-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002Q5-SendLoginRequest-source-quality.md","timestamp":"2026-07-04T05:24:24-04:00","uid":"0002Q5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
