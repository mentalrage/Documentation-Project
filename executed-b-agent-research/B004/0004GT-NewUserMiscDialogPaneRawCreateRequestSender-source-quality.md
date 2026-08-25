** TARGET-REPORT-UID:0004GT **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0004GT NewUserMiscDialogPaneRawCreateRequestSender Source-Quality Report


## Finalized Report / Current Recommendation

UID0004GT (`by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md`) should remain documented as a byte-real, source-shaped raw opcode `0x04` request sender island owned by `NewUserMiscDialogPane` context but not emitted as a callable C++ helper in the current reconstruction.

The current IDA MCP session confirms a coherent helper-shaped body at `0x004fca20-0x004fcab8`: stack frame, security cookie, packet byte writes, `dword_67A7EC` sender use, `sub_574BB0(..., 5)`, and `retn 0Ch`. It also confirms the address is not an IDA function, has zero xrefs, has no VA/RVA pointer hits in current byte search, and is not referenced by generated `NewUserMiscDialogPane.cpp`. The source-ready route for opcode `0x04` remains UID0004GO `NewUserMiscDialogPane::HandleCommand(...)`, where the create request is constructed inline and sent through `g_packetSender->QueueAndSendPacket(...)`.

Implementation callback status, 2026-07-05: the accepted target metadata/prose/no-code proof and narrow support sync were applied. Target is now `COMPLETION:88` / `CONFIDENCE:92` with `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++ block, and `Nested:0` preserved.

## Supporting Research

Read-only support reviewed for this report-only pass:

- Target: `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md`.
- Class owner: `by-class/NewUserMiscDialogPane.md`.
- File owner: `by-file/NewUserMiscDialogPane.md`.
- Split parent: `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`.
- Aggregate parent: `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`.
- Adjacent raw/data pages: UID0004GN raw cleanup island, UID0004GS help switch table, UID0004GU padding, UID0004GV raw cancel request sender, UID0004GW reply padding.
- Source-ready sibling: `by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md`.
- Generated output: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp`.
- Packet/global support: `by-global/g_packetSender.md`, `by-file/CashShopRequest.md`, generated `auto-generated/NexusTK/network/Socket.cpp`.
- Executed B reports used as leads only: B014 UID0004GO, B013 UID0002Q7, B004 UID0004GR, B001 MEMTOOL `0x004fb630`.

No target/support by-* file was edited during this report-only pass.

## Target

- UID: `0004GT`.
- Path: `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md`.
- Current title: `NewUserMiscDialogPaneRawCreateRequestSender`.
- Current range: `0x004fca20-0x004fcab8`.
- Current tracker state at assignment: `85/90`, reconstructable `true`, reports `0`.
- Current owner metadata in target: `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, `Nested:0`.

## Current Target State

At Gate 1, the target identified UID0004GT as a raw no-function opcode `0x04` NewUserMisc create/misc request sender and kept its formal C++ blank. That core classification remains correct after implementation.

The pre-callback target was stale in detail, not in direction:

- It depends primarily on older session notes (`3a33af0b`) rather than the current IDA MCP session.
- It does not include the current exact body bytes/signature facts for `0x004fca20-0x004fcab8`.
- It does not record the current instruction-level packet field layout.
- It does not explicitly tie the no-code recommendation to the now-source-ready UID0004GO inline create request sender in generated `NewUserMiscDialogPane.cpp`.
- It does not include the current generated refresh observation: `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` has UID0004GO source code and no UID0004GT marker/body/reference.

Callback result: the target now carries the current MCP/session health, exact range, exact bytes/signature, packet layout, no-function/no-xref/no-pointer-route proof, separate padding/cancel sibling boundaries, generated omission, UID0004GO inline source route, and descriptive-slug/no-source-API caveat. The target's blank formal C++ remains correct because no route proves this body was a source-callable helper. Emitting it would duplicate behavior already represented inline in UID0004GO.

## Heuristic / Inference Reanalysis And Validation

The raw body is not random padding and not a switch table tail. It begins with a normal function prologue at `0x004fca20`, creates a `0x104` stack frame, saves a security cookie, writes a short packet buffer, calls the packet writer helper five times, sends exactly five bytes through the sender global, checks the cookie, and returns with `retn 0Ch`.

The body is also not currently source-emittable:

- IDA does not define a function at `0x004fca20`.
- `xrefs_to` finds zero references to `0x004fca20`.
- VA/RVA pointer byte searches for `0x004fca20`, `0x004fcab8`, and `0x004fcac0` find zero hits.
- Generated `NewUserMiscDialogPane.cpp` has no UID0004GT marker, no `0x004fca20` reference, and no raw create sender helper.
- UID0004GO already emits the active opcode `0x04` request path inline in `NewUserMiscDialogPane::HandleCommand(...)`.

The most likely source-quality interpretation is an orphaned or unreferenced out-of-line helper body whose behavior is source-equivalent to the inline sender inside UID0004GO. It should be documented as byte-real custom code and source-shaped evidence, but not emitted as a new helper until a call route, source import, symbol, or other owner/emitter proof is found.

## Evidence Standards Used

- Current IDA MCP was mandatory and available.
- MCP calls were narrow and address-specific, following `by-structure.md` IDA MCP Output Discipline.
- Executed reports were treated as leads and compared against current MCP, not accepted as proof by themselves.
- Generated C++ was inspected read-only to confirm actual current emission state.
- No validators, lifecycle commands, execute_report variants, archive commands, generated-file edits, coverage edits, or by-* edits were run/performed during this report-only pass.

## Evidence Checked

Current IDA MCP session:

- MCP database/session: `supervisor_recovery_20260705`.
- Active IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Health: `server_health` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`.
- Function inventory: `lookup_funcs` for the target and adjacent boundaries.
- Direct references: `xrefs_to` for target, endpoints, adjacent raw/data/function boundaries.
- Raw bytes: `get_bytes` around `0x004fca10` and exact target/padding regions.
- Function body comparison: `decompile`, `callees`, and `analyze_function` for UID0004GO `0x004fc010`.
- Pointer search: `find_bytes` for target start/end and adjacent raw cancel start VA/RVA byte patterns.
- Signatures: `make_signature_for_range` exact and wildcarded for `0x004fca20-0x004fcab8`.
- Instruction listing: `insn_query` for `0x004fca20-0x004fcab8`.
- Negative raw decompile/function checks: `decompile` and `analyze_function` at `0x004fca20`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|
| C01 | Target metadata should move from `85/90` to `88/92` while preserving owner, reconstructable, blank emitter, and `Nested:0`. | High (92) | Current MCP strengthens exact identity/no-route evidence; no C++ route/source name proof remains. | `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` :: metadata header | incorporate | applied |
| C02 | UID0004GT is a byte-real raw packet sender body, not padding or switch-table data. | High (93) | MCP `get_bytes`, exact unique signature, and `insn_query` show prologue, `0x104` stack frame, security cookie, five writer calls, sender call, and `retn 0Ch`. | `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` :: Item Summary / IDA MCP evidence prose | incorporate | applied |
| C03 | UID0004GT is not an IDA function in the current database. | High (94) | MCP `lookup_funcs` found no function at `0x004fca20`; `analyze_function 0x004fca20` returned no function; adjacent functions remain `0x004fc010`, `0x004fc5c0`, and `0x004fcb10`. | `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` :: Item Summary / IDA MCP evidence prose | incorporate | applied |
| C04 | UID0004GT has no proven caller or route. | High (92) | MCP `xrefs_to 0x004fca20` returned zero; searched VA/RVA patterns for `0x004fca20`, `0x004fcab8`, and `0x004fcac0` returned zero; generated output has no UID0004GT marker/reference. | `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` :: route/reachability prose | incorporate | applied |
| C05 | The formal C++ block for UID0004GT should remain blank. | High (91) | No function, no xrefs, no generated marker, and UID0004GO already emits the active opcode `0x04` behavior inline. | `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` :: `RECONSTRUCTION_CPP CODE` block | incorporate | applied |
| C06 | The exact packet lowering should be documented: opcode `4`, `[arg0+4]`, `[arg0+0x21]`, stack arg `0x0c`, stack arg `0x10`, then send length `5`. | High (92) | MCP `insn_query` at `0x004fca3e`, `0x004fca4c`, `0x004fca5d`, `0x004fca6e`, `0x004fca7f`, and `0x004fcaa2`. | `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` :: packet layout prose | incorporate | applied |
| C07 | The target range should remain exactly `0x004fca20-0x004fcab8`; `0x004fcab8-0x004fcac0` is separate `cc` padding. | High (94) | MCP bytes show UID0004GT body ends before eight `cc` bytes; UID0004GU already owns padding. | `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` :: range/split prose | incorporate | applied |
| C08 | The split parent should carry the refreshed UID0004GT child state: raw opcode `0x04` body, exact range, no function, no route, non-emitting. | High (91) | Current MCP facts plus existing UID0002Q7 child inventory; UID0004GT body is distinct from UID0004GS, UID0004GU, and UID0004GV. | `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` :: Child Inventory / UID0004GT row and Current MCP Evidence | incorporate | applied |
| C09 | The class doc should state UID0004GT is a non-emitting raw sender island and UID0004GO owns the emitted inline create request path. | High (90) | `by-class/NewUserMiscDialogPane.md` already names UID0004GT; current MCP and generated output refine the no-route/generated-omission state. | `by-class/NewUserMiscDialogPane.md` :: method/child table row for UID0004GT and raw-helper caveat prose | incorporate | applied |
| C10 | The file doc should state generated `NewUserMiscDialogPane.cpp` should keep UID0004GO inline sender code and omit UID0004GT. | High (90) | Generated `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` has UID0004GO inline packet sends and zero UID0004GT/raw-create references. | `by-file/NewUserMiscDialogPane.md` :: Proposed contents / raw helper caveat and generated freshness prose | incorporate | applied |
| C11 | UID0004GO `HandleCommand` already contains same-or-greater source-ready inline opcode `0x04` support and does not need a callback edit. | High (91) | UID0004GO docs and current decompile show inline `sub_575380(4, ...)` and `sub_574BB0(dword_67A7EC, ..., 5)`. | `by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md` :: helper-route caveat / source-ready packet send prose | already-present | already-present |
| C12 | `CreateRequestSender` and `SendCreateMiscRequest` should not be promoted as source API names; the slug is descriptive only. | High (89) | No symbol, source import, route, generated helper, or function object names the raw body; UID0004GO emits equivalent behavior inline. | `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` :: naming/source API caveat prose | historicalize | applied |
| C13 | `CashShopRequest` is not the owner for this packet path. | High (90) | `by-file/CashShopRequest.md` already rejects CashShopRequest ownership for this sender corridor. | `by-file/CashShopRequest.md` :: ownership caveat | already-present | already-present |
| C14 | `g_packetSender`/Socket sender support is already present as a dependency, not target ownership. | High (90) | `by-global/g_packetSender.md` and generated Socket support identify `dword_67A7EC` as `g_packetSender` and `sub_574BB0` as Socket send dependency. | `by-global/g_packetSender.md` :: global definition/support prose | already-present | already-present |
| C15 | Adjacent UID0004GV raw cancel sender remains a separate no-route sibling and does not require this callback edit. | High (90) | MCP bytes show cancel prologue at `0x004fcac0`; UID0004GV page already documents separate raw opcode `0x15` sender. | `by-memory/0x004fcac0-0x004fcb04.NewUserMiscDialogPaneRawCancelRequestSender.md` :: Item Summary | already-present | already-present |
| C16 | Adjacent UID0004GU padding remains separate and does not require this callback edit beyond target/parent cross-reference. | High (94) | MCP bytes show `0x004fcab8-0x004fcac0` as eight `cc` bytes; UID0004GU already owns that padding range. | `by-memory/0x004fcab8-0x004fcac0.NewUserMiscDialogPanePacketHelperPadding.md` :: Item Summary | already-present | already-present |
| C17 | Generated files must not be manually edited; post-callback validation should only inspect generated freshness. | High (95) | Current generated output has UID0004GO present and UID0004GT absent; workflow forbids manual generated edits. | `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` :: generated output header/body, read-only inspection only | not-applicable | excluded-with-reason |

## Positive Evidence Summary

Current MCP validates the exact raw-body identity:

- `lookup_funcs`:
  - `0x004fc010` is `sub_4FC010`, size `0x56e`.
  - `0x004fc57e` is not a function.
  - `0x004fc5c0` is `sub_4FC5C0`, size `0x26`.
  - `0x004fc9e8`, `0x004fca18`, `0x004fca20`, `0x004fcab8`, `0x004fcac0`, and `0x004fcb04` are not functions.
  - `0x004fcb10` is `sub_4FCB10`, size `0x1de`.
- `insn_query 0x004fca20-0x004fcab8` returned 46 instructions with no containing function for each instruction.
- Body starts at `0x004fca20` with `push ebp; mov ebp, esp; sub esp, 104h`.
- Body loads the first stack argument into `esi` from `[ebp+8]`.
- Packet writes:
  - `0x004fca3e`: push opcode `4`, call `sub_575380`.
  - `0x004fca4c`: load `word ptr [esi+4]`, call `sub_575380`.
  - `0x004fca5d`: load `byte ptr [esi+21h]`, call `sub_575380`.
  - `0x004fca6e`: load `byte ptr [ebp+0Ch]`, call `sub_575380`.
  - `0x004fca7f`: load `byte ptr [ebp+10h]`, call `sub_575380`.
- Sender call:
  - `0x004fca89`: load `dword_67A7EC`.
  - `0x004fca98`: write local terminator byte at `[ebp-0FFh]`.
  - `0x004fca9f`: push send length `5`.
  - `0x004fcaa2`: call `sub_574BB0`.
- Body ends with security cookie check and `0x004fcab5 retn 0Ch`.

Exact signature for `0x004fca20-0x004fcab8` is unique in current MCP:

```text
55 8B EC 81 EC 04 01 00 00 A1 24 2F 67 00 33 C5 89 45 FC 56 8B 75 08 8D 85 FC FE FF FF 50 6A 04 E8 3B 89 07 00 8D 85 FD FE FF FF 50 0F B7 46 04 50 E8 2A 89 07 00 8D 85 FE FE FF FF 50 0F B6 46 21 50 E8 19 89 07 00 8D 85 FF FE FF FF 50 0F B6 45 0C 50 E8 08 89 07 00 8D 85 00 FF FF FF 50 0F B6 45 10 50 E8 F7 88 07 00 8B 0D EC A7 67 00 8D 85 FC FE FF FF 83 C4 28 C6 85 01 FF FF FF 00 6A 05 50 E8 09 81 07 00 8B 4D FC 33 CD 5E E8 7D AC 0C 00 8B E5 5D C2 0C 00
```

Wildcarded signature generation also returned unique for the same range. The wildcarded form preserves the prologue, local stack layout, five writer-call shape, sender call shape, cookie epilogue, and `C2 0C 00` return.

## IDA MCP Facts

Current command facts to carry into target/support docs after callback:

- `lookup_funcs` command: confirms target start and adjacent raw starts are not IDA functions.
- `xrefs_to` command:
  - `0x004fc010` has one data xref from `0x0061d46c`.
  - `0x004fc9e8` has one internal switch-table xref from `0x004fc7eb`.
  - `0x004fca20` has zero xrefs.
  - `0x004fcab8` has zero xrefs.
  - `0x004fcac0` has zero xrefs.
  - `0x004fcb10` has a code xref from `0x004fc5e1`.
- `decompile 0x004fc010` confirms the live command handler constructs the opcode `0x04` packet inline and calls `sub_574BB0(dword_67A7EC, &Src, 5)`.
- `callees 0x004fc010` includes `sub_4FCFC0`, `sub_575380`, `sub_574BB0`, `sub_4F4AA0`, `sub_559B90`, `sub_49EB90`, `sub_49DAD0`, `sub_4FD030`, `sub_4FD050`, `sub_4FD0D0`, `sub_4FD070`, `sub_4FD140`, `sub_4FCD80`, and `@__security_check_cookie@4`.
- `find_bytes` for little-endian VA/RVA forms of `0x004fca20`, `0x004fcab8`, and `0x004fcac0` found zero matches.
- `decompile 0x004fca20` failed because no function exists there.
- `analyze_function 0x004fca20` failed because no function exists there.

## Function / Child Inventory

Relevant current inventory around the target:

| Range / Address | UID / Page | Current state | Source-quality effect |
|---|---|---|---|
| `0x004fc010-0x004fc57e` | UID0004GO | IDA function, source-ready command handler | Emits inline opcode `0x04` and `0x15` send logic; owns active source path. |
| `0x004fc57e-0x004fc5c0` | split gap / non-function | not function | Not the target. |
| `0x004fc5c0-0x004fc5e6` | small function | IDA function | Adjacent helper, not UID0004GT. |
| `0x004fc9e8-0x004fca20` | UID0004GS | switch table/data | Ends exactly before UID0004GT. |
| `0x004fca20-0x004fcab8` | UID0004GT | raw helper-shaped body, not function | Current target; no route, blank C++. |
| `0x004fcab8-0x004fcac0` | UID0004GU | eight `cc` bytes | Padding, not part of target body. |
| `0x004fcac0-0x004fcb04` | UID0004GV | raw cancel sender body, not function | Separate sibling for opcode `0x15`, not target. |
| `0x004fcb04-0x004fcb10` | UID0004GW | `cc` padding | Padding before reply handler. |
| `0x004fcb10-0x004fccee` | reply handler region | IDA function starts at `0x004fcb10` | Separate function/child. |

## Direct Xref / Caller Inventory

Current MCP direct route evidence:

- `xrefs_to 0x004fca20`: zero.
- `xrefs_to 0x004fcab8`: zero.
- `xrefs_to 0x004fcac0`: zero.
- `find_bytes` for `20 CA 4F 00`: zero.
- `find_bytes` for `20 CA 0F 00`: zero.
- `find_bytes` for `B8 CA 4F 00`: zero.
- `find_bytes` for `C0 CA 4F 00`: zero.
- `find_bytes` for `C0 CA 0F 00`: zero.
- Generated `NewUserMiscDialogPane.cpp` search: zero references to `0004GT`, `RawCreate`, `0x004fca20`, `0x004fcac0`, or a raw-create helper marker/body.

This proves no direct route under the evidence searched. It does not prove the body never existed in source, but it is enough to block formal C++ emission in the current documentation project.

## Documentation Evidence And IDA Status

Target page:

- Callback-applied state: now says raw no-function opcode `0x04` sender, keeps C++ blank, records current MCP evidence, exact body/signature, generated freshness, and UID0004GO source-ready support context.

Class page:

- `by-class/NewUserMiscDialogPane.md` already identifies UID0004GT as raw opcode `0x04` sender and says it must not be modeled as a callable helper without route proof.
- Callback-applied state: narrow support refresh now mentions the current MCP session, UID0004GT no-route/generated-omission state, and UID0004GO inline source-ready route.
- No score movement is required for class page.

File page:

- `by-file/NewUserMiscDialogPane.md` already says the source route is `NexusTK/login/NewUserMiscDialogPane.cpp` and raw starts are not callable helpers.
- Callback-applied state: narrow support refresh now ties UID0004GT to current generated output and UID0004GO.
- No score movement is required for file page.

Split parent:

- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` already documents raw starts and B014 context.
- Callback-applied state: narrow support refresh now carries UID0004GT exact body/signature/no-route facts.
- No score movement is required for the parent.

Source-ready sibling:

- UID0004GO already has stronger source-ready detail: inline opcode `0x04` packet construction and cancel opcode `0x15` packet construction, plus raw-helper no-route caveat.
- No edit is required unless supervisor wants a cross-reference sentence.

Generated output after callback:

- `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` was refreshed by validator command id `000000007127` at `2026-07-05T14:34:26-04:00`.
- Generated output includes UID0004GO `HandleCommand(...)` with inline packet sends.
- Generated output excludes UID0004GT, UID0004GV, and raw helper markers.
- This is the desired current state for UID0004GT unless future route proof appears.

## Ranked Ownership Analysis

1. `NewUserMiscDialogPane` / UID00009F remains the correct canonical owner context.
   - The raw sender lies inside the NewUserMiscDialogPane split region.
   - The source-ready opcode `0x04` behavior is in UID0004GO under the same class.
   - Adjacent docs and generated output route through `NexusTK/login/NewUserMiscDialogPane.cpp`.

2. `NewUserMiscDialogPane.cpp` / UID0000LX is the correct file context.
   - The generated file contains the active command handler.
   - The raw body is not emitted but belongs in the same file-family documentation as a non-emitting raw island.

3. `Socket` / `g_packetSender` is a dependency, not the owner.
   - `dword_67A7EC` is documented as `g_packetSender`.
   - `sub_574BB0` is the send method route, but that does not transfer ownership of the caller body.

4. `CashShopRequest` is rejected as owner.
   - Current docs identify CashShopRequest aliases as stale/search-only for this corridor.
   - Generated NewUserMisc code uses packet/global sender terminology, not CashShopRequest ownership.

5. A new helper owner/name such as `CreateRequestSender` is rejected as source API.
   - The target slug is useful as a documentation descriptor.
   - The evidence does not prove a callable source helper with that name or any name.

## Source Placement

The best source placement remains the `NexusTK/login/NewUserMiscDialogPane.cpp` family, but UID0004GT should not add a C++ body to that generated file. The emitted source path for create request sending is UID0004GO's inline command-handler branch.

If a future source import or call-route proof appears, a plausible placement would be a file-local/static helper near `NewUserMiscDialogPane::HandleCommand(...)`, not a public class method. That is not recommended now because there is no route proof and the current generated file already has the active behavior inline.

## Range / Split / Padding / Reclassification Analysis

The current split is correct:

- `0x004fc9e8-0x004fca20` is the help switch table and ends before the raw sender.
- `0x004fca20-0x004fcab8` is the exact UID0004GT raw body.
- `0x004fcab8-0x004fcac0` is eight bytes of `cc` padding and must remain separated from UID0004GT's exact body.
- `0x004fcac0-0x004fcb04` is the separate raw cancel sender body.

Do not merge UID0004GT into UID0004GO, UID0004GS, UID0004GU, or UID0004GV. Do not rename the target file or reclassify it as padding.

## Negative Evidence Summary

Evidence blocking formal C++ emission:

- No IDA function at `0x004fca20`.
- No xrefs to `0x004fca20`.
- No searched VA/RVA pointer hits for `0x004fca20`, `0x004fcab8`, or `0x004fcac0`.
- No generated `NewUserMiscDialogPane.cpp` marker/reference/body for UID0004GT.
- Current generated source already emits equivalent opcode `0x04` behavior inline in UID0004GO.
- No source import, symbol, vtable, dispatch table, or caller has been found that would name or route this helper.

Rejected stale or unsafe interpretations:

- Reject treating UID0004GT as active callable `NewUserMiscDialogPane::CreateRequestSender()`.
- Reject adding a duplicate helper body to generated C++ while UID0004GO already contains the inline source route.
- Reject assigning ownership to CashShopRequest.
- Reject extending target range into `cc` padding or adjacent UID0004GV cancel sender.

## IDA Rename / Type / Comment Recommendations

No IDA rename is required for this report-only pass.

If IDA comments are later allowed by a separate workflow, a useful non-invasive comment at `0x004fca20` would be:

```text
Raw NewUserMisc opcode 0x04 request sender body; no current xrefs/function. Active source emission is UID0004GO inline HandleCommand branch.
```

Do not apply an IDA function name such as `NewUserMiscDialogPane::CreateRequestSender` unless a route/source proof appears.

## First-Draft C++ Recommendation

Do not insert formal C++ for UID0004GT.

The formal C++ block in the target should remain exactly blank between the required markers:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason: the body is source-shaped, but no current route proves it should be emitted as a callable helper. The emitted source equivalent is already present in UID0004GO.

## Final Recommendation

Callback implementation applied a documentation-only evidence refresh for UID0004GT:

- Target score is now `COMPLETION:88`, `CONFIDENCE:92`.
- Target owner/emitter/reconstructable/nested metadata was preserved.
- Formal C++ remains blank.
- Current MCP evidence was added at report-level detail: no function, no xrefs, exact body bytes/signature, packet field lowering, sender call, padding separation, generated freshness, and UID0004GO inline source-ready support.
- Narrow support prose was added to class/file/split parent.
- Adjacent raw/cancel/padding pages were not edited because no direct contradiction was found.

## Recommended Target Doc Changes

Applied to `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md`:

- Changed `COMPLETION:85` to `COMPLETION:88`.
- Changed `CONFIDENCE:90` to `CONFIDENCE:92`.
- Kept `CANONICAL_OWNER:00009F`.
- Kept `RECONSTRUCTABLE:TRUE`.
- Kept `EMITTER_UIDS:` blank.
- Kept `Nested:0`.
- Kept the formal C++ block blank.
- Replaced older current-state prose with current MCP evidence:
  - Current IDB/session health.
  - No IDA function at `0x004fca20`.
  - Exact target range `0x004fca20-0x004fcab8`.
  - Padding starts at `0x004fcab8` and is separate UID0004GU.
  - UID0004GV starts at `0x004fcac0`.
  - Zero xrefs to `0x004fca20`.
  - Zero searched VA/RVA pointer hits for start/end/sibling start.
  - Exact body writes opcode `4`, `[arg0+4]`, `[arg0+0x21]`, stack arg at `0x0c`, stack arg at `0x10`, then sends length `5`.
  - `dword_67A7EC` is the sender global; `sub_574BB0` is the send route; `sub_575380` is the byte writer route.
  - UID0004GO `HandleCommand` is source-ready and emits the active opcode `0x04` packet inline.
  - Generated `NewUserMiscDialogPane.cpp` contains no UID0004GT marker/body/reference.
- Historicalized the descriptive `CreateRequestSender` slug as a documentation label, not a proven source API.

## Recommended Support Doc Changes

Applied after callback because support text did not yet carry same-or-greater UID0004GT detail:

- `by-class/NewUserMiscDialogPane.md`:
  - Added/refined UID0004GT row/prose to mention current MCP exact no-function/no-xref state, unique raw body, generated omission, and UID0004GO inline create request route.
  - Preserved existing class owner/emitter/source route.
  - No class score change recommended.

- `by-file/NewUserMiscDialogPane.md`:
  - Added/refined file-family prose to state UID0004GT is a non-emitting raw opcode `0x04` sender island under the NewUserMiscDialogPane file route.
  - Stated generated `NewUserMiscDialogPane.cpp` should continue to emit UID0004GO inline sender and omit UID0004GT.
  - No file score change recommended.

- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`:
  - Added/refined child inventory for UID0004GT with current `0x004fca20-0x004fcab8` exact evidence and no-route status.
  - Preserved non-emitting parent split status.
  - No parent score change recommended.

Already-present / no-change support:

- UID0004GO `HandleCommand` already contains same-or-greater source-ready inline sender evidence; no edit required.
- UID0004GN raw cleanup island, UID0004GV raw cancel sender, UID0004GU/UID0004GW padding pages do not need edits unless a contradiction is found during callback.
- `by-global/g_packetSender.md` and `by-file/CashShopRequest.md` already support Socket/global ownership and rejected CashShopRequest ownership; no edit required.

## Score And Metadata Recommendation

Target:

- Recommended `COMPLETION:88`.
- Recommended `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:00009F`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:` blank.
- Keep `Nested:0`.

Score rationale:

- Completion improves because current MCP now provides exact body/signature, instruction-level packet layout, range/padding separation, generated freshness, and stronger no-route proof.
- Confidence improves because current IDA evidence independently confirms the target identity and excludes common stale alternatives.
- Score remains below source-ready levels because no caller/source route/name proof exists and formal C++ must remain blank.

Support:

- No class score movement recommended.
- No file score movement recommended.
- No split-parent score movement recommended.
- Any support edits should be narrow prose alignment, not ownership/emitter changes.

## Open Questions With Attempted Resolution

Question: Is UID0004GT a source-callable helper?

Attempted resolution: Checked current MCP function inventory, xrefs, VA/RVA byte patterns, generated output, UID0004GO decompile, and executed reports as leads. No route was found. Resolution: treat as non-emitting raw source-shaped body.

Question: Does UID0004GT duplicate UID0004GO behavior?

Attempted resolution: Compared raw body writes against UID0004GO decompile/generated output. Both construct opcode `0x04` five-byte create/misc request and send through the same sender route. Resolution: UID0004GO is the source-ready emitted route; UID0004GT remains evidence-only.

Question: Should the range include `cc` bytes at `0x004fcab8`?

Attempted resolution: Checked bytes and adjacent padding page. The body ends at `0x004fcab8`; eight `cc` bytes belong to UID0004GU. Resolution: keep exact half-open range.

Question: Is the source-facing helper name recoverable?

Attempted resolution: Searched docs/generated output and checked MCP route evidence. No symbol/source import/route found. Resolution: keep descriptive slug, reject source API promotion.

Question: Is CashShopRequest the owner?

Attempted resolution: Checked CashShopRequest and `g_packetSender` support. Current docs reject CashShopRequest ownership for this corridor and route sender ownership through Socket/global sender. Resolution: owner remains NewUserMiscDialogPane context with Socket dependency.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No supervisor-owned coverage/tracker file should be manually edited by B004 for this report-only pass.

If the supervisor later wants manual tracker summary text, the proposed wording is:

```text
UID0004GT refreshed as a non-emitting raw NewUserMisc opcode 0x04 sender island: current MCP proves exact 0x004fca20-0x004fcab8 byte body, no IDA function, zero xrefs, separate padding/cancel sibling, and UID0004GO inline source-ready sender route. Target score proposed 88/92; formal C++ remains blank.
```

## Follow-Up Actions

Callback completion state:

1. Leased each by-* file immediately before editing.
2. Applied target metadata/prose/formal-block recommendations exactly.
3. Applied narrow support prose to class/file/split parent.
4. Released leases immediately after edit/validator batch; no B004 leases remain.
5. Ran scoped validators only for edited by-* files.
6. Inspected generated `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` read-only after validation and confirmed UID0004GO remains emitted while UID0004GT remains omitted.
7. Updated this report ledger/checklist with applied/already-present/excluded states, validator command metadata, generated freshness, changed files, and lease release confirmation.

## Confidence

Report confidence: high.

The byte identity, range, no-function status, no-xref status, generated omission, and UID0004GO inline source route are directly supported by current MCP plus read-only generated/docs review. The confidence cap is the absence of original source naming/call-route proof for the raw helper-shaped body.

## Validator Results

Callback validators were run from `source-3/project-documentation`; all exited `0` with `ok: 1`.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / side effects |
|---|---|---:|---|---:|---:|---|
| `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md --apply --queue-timeout 240` | `000000007120` | `2026-07-05T14:33:11-04:00` | 0 | 1 | No warnings. Applied completion/confidence updates, UID link normalization, reference index adds, projected stats update; generated refresh deferred. |
| `by-class/NewUserMiscDialogPane.md` | `python .\tools\validator.py --mode file --file by-class/NewUserMiscDialogPane.md --apply --queue-timeout 240` | `000000007122` | `2026-07-05T14:33:19-04:00` | 0 | 1 | No warnings. Initial class support validation; autogen registry and projected stats updated; generated refresh deferred. |
| `by-file/NewUserMiscDialogPane.md` | `python .\tools\validator.py --mode file --file by-file/NewUserMiscDialogPane.md --apply --queue-timeout 240` | `000000007123` | `2026-07-05T14:33:31-04:00` | 0 | 1 | No warnings. Projected stats updated; generated refresh deferred and then produced `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` header command id `000000007123`. |
| `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md --apply --queue-timeout 240` | `000000007124` | `2026-07-05T14:33:41-04:00` | 0 | 1 | No warnings. Projected stats update; generated refresh deferred. |
| `by-class/NewUserMiscDialogPane.md` | `python .\tools\validator.py --mode file --file by-class/NewUserMiscDialogPane.md --apply --queue-timeout 240` | `000000007127` | `2026-07-05T14:34:26-04:00` | 0 | 1 | No warnings. Follow-up class validation after removing a generated-output UID0004GT mention from the formal class comment; autogen registry/projected stats updated; generated refresh deferred and then refreshed generated C++ header to `000000007127`. |

Generated freshness check:

- `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` header after validation: `validator-command-id: 000000007127`, `validator-refreshed-at: 2026-07-05T14:34:26-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- UID0004GO remains emitted: generated file contains `// UID:0004GO`, `void NewUserMiscDialogPane::HandleCommand(int commandId, int notifyCode)`, `PacketBufferWriteUInt8(...)` packet writes, and `g_packetSender->QueueAndSendPacket(...)` for create/cancel sends.
- UID0004GT remains omitted as a raw helper: read-only search for `UID0004GT`, `UID:0004GT`, `0x004fca20`, `RawCreate`, and `CreateRequestSender` returned no generated matches.

## Changed Files

Manually edited by B004 during callback:

- `tools/leaser/Agents/Agent-B004/research/0004GT-NewUserMiscDialogPaneRawCreateRequestSender-source-quality.md`.
- `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md`.
- `by-class/NewUserMiscDialogPane.md`.
- `by-file/NewUserMiscDialogPane.md`.
- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`.

Validator-owned/generated side effects observed from scoped validators:

- `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` refreshed to validator command id `000000007127`.
- `project-level/-auto-completion-stats.md` received validator-owned projected stats updates.
- Validator output reported autogen registry/reference-index updates and UID link normalization as part of scoped validation. These were tool-owned side effects, not manual edits.

Not manually edited by B004:

- Generated files under `auto-generated/`.
- Coverage reports and `-coverage-report.md` files.
- Validator state, registry, queue, lock, or config files.
- Lifecycle/archive/report execution locations.
- Supervisor ledgers.
- UID0004GO, UID0004GN, UID0004GV, UID0004GU, CashShopRequest, and `g_packetSender` docs.

Commands not run:

- `execute_report` and dry-run/probing equivalents.
- Registry lifecycle commands.
- Manual report archive/move commands.

## Implementation Tracking Checklist

Report-only Gate 1:

- [x] Read refreshed `Agent-B004/goal.md`.
- [x] Used project-level `ntk-b-agent-workflow` skill.
- [x] Used current IDA MCP evidence with narrow address-specific calls.
- [x] Searched target/support docs, adjacent docs, generated output, active agent research, and executed B reports as leads.
- [x] Created this report in B004 `research/` path only.
- [x] Did not edit target/support by-* docs.
- [x] Did not edit generated files, coverage files, validator state, lifecycle/archive locations, or supervisor ledgers.
- [x] Did not run validators.
- [x] Did not run `execute_report`, lifecycle, registry, archive, or report-move commands.

Implementation callback:

- [x] Leased `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md`, `by-class/NewUserMiscDialogPane.md`, `by-file/NewUserMiscDialogPane.md`, and `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` immediately before the edit/validator batch. Lease command returned `Success` for all four files.
- [x] Updated target to `COMPLETION:88` and `CONFIDENCE:92`; validator `000000007120` confirmed completion/confidence updates.
- [x] Preserved target `CANONICAL_OWNER:00009F`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++ block, and `Nested:0`.
- [x] Added current MCP no-function/no-xref/exact-body/packet-layout/signature/generated-freshness evidence to target, including session health, exact range, padding/cancel sibling boundaries, zero searched VA/RVA pointer hits, and UID0004GO emitted inline route.
- [x] Historicalized `CreateRequestSender` as a descriptive slug, not proven source API, in target prose.
- [x] Updated `by-class/NewUserMiscDialogPane.md` with narrow accepted support prose and no score movement; validators `000000007122` and final `000000007127` both exited `0`, `ok: 1`.
- [x] Updated `by-file/NewUserMiscDialogPane.md` with narrow accepted support prose and no score movement; validator `000000007123` exited `0`, `ok: 1`.
- [x] Updated `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` with narrow accepted UID0004GT child/current-MCP support prose and no score movement; validator `000000007124` exited `0`, `ok: 1`.
- [x] Did not edit UID0004GO, UID0004GN, UID0004GV, padding pages, CashShopRequest, or `g_packetSender` docs; those rows are already-present/no-change in the ledger.
- [x] Released the four-file lease immediately after the first edit/validator batch; then took and released a short one-file class lease for the generated-output comment repair. `current_leases.md` read after release reported `No active leases`.
- [x] Ran scoped validator for each edited by-* file:
  - [x] `python .\tools\validator.py --mode file --file by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md --apply --queue-timeout 240` -> `000000007120`, `2026-07-05T14:33:11-04:00`, exit `0`, `ok: 1`.
  - [x] `python .\tools\validator.py --mode file --file by-class/NewUserMiscDialogPane.md --apply --queue-timeout 240` -> `000000007122`, `2026-07-05T14:33:19-04:00`, exit `0`, `ok: 1`; follow-up final class validator `000000007127`, `2026-07-05T14:34:26-04:00`, exit `0`, `ok: 1`.
  - [x] `python .\tools\validator.py --mode file --file by-file/NewUserMiscDialogPane.md --apply --queue-timeout 240` -> `000000007123`, `2026-07-05T14:33:31-04:00`, exit `0`, `ok: 1`.
  - [x] `python .\tools\validator.py --mode file --file by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md --apply --queue-timeout 240` -> `000000007124`, `2026-07-05T14:33:41-04:00`, exit `0`, `ok: 1`.
- [x] Inspected generated `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` read-only after validation. Header is `validator-command-id: 000000007127`; UID0004GO remains emitted and UID0004GT has no marker/body/reference.
- [x] Updated Claim And Incorporation Ledger verification states to `applied`, `already-present`, or `excluded-with-reason` as appropriate. No ledger row is blocked.
- [x] Updated Validator Results with command ids, timestamps, exit codes, `ok`, warnings, and generated freshness.
- [x] Updated Changed Files with manually edited docs, validator-owned generated side effects, and explicit not-manually-edited categories.
- [x] Confirmed no `execute_report`, lifecycle/archive, registry lifecycle, manual move, generated manual edit, coverage edit, or validator-state manual edit was performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000007135","destination_path":"executed-b-agent-research/B004/0004GT-NewUserMiscDialogPaneRawCreateRequestSender-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0004GT-NewUserMiscDialogPaneRawCreateRequestSender-source-quality.md","timestamp":"2026-07-05T14:40:23-04:00","uid":"0004GT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
