** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# 0003GY UnreferencedThreadDispatchWrapper Post-Migration Owner/Emitter Research

Revision: B001-0003GY-post-migration, 2026-06-13

## Finalized Recommendation

- Target: [UID:0003GY] `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`
- Recommendation: keep the current no-owner/non-emitting reconstructable state.
- Exact metadata recommendation:
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:`
  - `EMITTER_POSITION_OPTIONAL:`
  - `RECONSTRUCTION_CPP CODE` remains blank.
- Score recommendation: keep `COMPLETION:86` and `CONFIDENCE:86`. The post-migration pass strengthens the negative evidence but does not add owner/emitter proof or final-source naming.
- Coverage-report recommendation: no `by-memory/-coverage-report.md` change is required. Retain the current row:

```text
        - [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable : 86% : strong : Real unreferenced queue wrapper that forwards two arguments plus zero to generic Thread dispatch helper `0x00596960`; parent remains blank because no caller/vtable/source-island evidence proves the direct owner.
```

This is a valid current-model state. `by-structure.md` separates ownership from emission and explicitly permits `RECONSTRUCTABLE:TRUE` items to remain `no-owner` and `non-emits` when IDA proves NexusTK source code but the owner, emitter route, or final source shape is not ready. For this item, blank `EMITTER_UIDS` is not an invalid dead route because there is no emitted C++ block and no proven source-use context. Filling `Thread`, `FileDownloader`, `Socket`, or multiple emitters would invent a route from dependency or adjacency evidence.

No split, merge, parent repair, or reclassification is recommended. The function is exact, 20 bytes, bounded by alignment, and remains source-authored project helper code rather than CRT/runtime, compiler-only glue, or padding.

## Supporting Research

## Target State

Current target header:

```text
*** UID:0003GY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Current `auto-generated/-ag-memory-coverage.md` row:

```text
| [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md` |  |
```

The prior executed B001 report for [UID:0000WI] split this function out of the broad FileDownloader dispatch inventory and left it reconstructable, no-owner, and non-emitting. This post-migration recheck tested whether the new separate `CANONICAL_OWNER` / `EMITTER_UIDS` model changes that decision.

## Rule Evidence Applied

Facts from `by-structure.md`:

| Rule area | Applied result |
| --- | --- |
| `CANONICAL_OWNER` | Must be the correct direct semantic owner, not the nearest file root or final generated `.cpp`. |
| `EMITTER_UIDS` | Output routing, not ownership; should only be filled for proven emitted source contexts. |
| `CANONICAL_OWNER:NONE` plus emitters | Appropriate for pooled/shared items when proven source-use contexts exist. That model does not apply here because this is a function with zero source-use refs, not pooled data. |
| Reconstructable no-owner/non-emits | Acceptable while research continues when IDA proves NexusTK-owned source but owner/emitter route is not ready. Do not fill owner, emitters, or C++ merely because plausible. |
| Compiler/runtime classification | Use for pure compiler/linker artifacts, CRT/STL/runtime, padding, import glue, thunks, etc. The target body calls a NexusTK thread queue primitive and is not compiler-only glue. |

## IDA MCP Evidence

Live IDA MCP session: `b001_0003gy`, opened with `idb_open` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`. Health reported imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.

Target facts:

| Check | Result |
| --- | --- |
| `lookup_funcs 0x0041b2d0` | Function `___std_fs_create_symbolic_link@8`, size `0x14`. |
| `lookup_funcs 0x0041b2e4` | Not a function, confirming the exclusive end. |
| `disasm 0x0041b2d0` | `push ebp; mov ebp, esp; push 0; push [ebp+arg_4]; push [ebp+arg_0]; call sub_596960; pop ebp; retn 8`. |
| `decompile 0x0041b2d0` | `return sub_596960(this, a2, a3, 0);` under IDA's stale typed name. |
| `callees 0x0041b2d0` | Only `0x00596960` / `sub_596960`. |
| `xrefs_to 0x0041b2d0` | `0` cross-references. |
| `get_bytes 0x0041b2c0` | Confirms the body bytes and `0xcc` alignment around the target; next function starts at `0x0041b2f0`. |
| `make_signature_for_range 0x0041b2d0-0x0041b2e4` | Pattern `55 8B EC 6A 00 FF 75 ? FF 75 ? E8 ? ? ? ? 5D C2 08 00`, not unique because the same wrapper shape exists elsewhere. |
| `find_bytes D0 B2 41 00` and `D0 B2 01 00` | No absolute VA or RVA byte matches for the target start. |
| Raw PE scan | No relative `call`, `jmp`, near conditional, short branch, absolute VA, or RVA encodings target `0x0041b2d0`. |

Thread queue primitive evidence:

| Check | Result |
| --- | --- |
| `lookup_funcs 0x00596960` | Function `sub_596960`, size `0x50`. |
| `decompile 0x00596960` | Builds a six-dword request record from `(a2, a3, a4, 0, 0, 0)`, queues it through `sub_556580`, and calls `ReleaseSemaphore(this[3], 1, 0)`. |
| `callees 0x00596960` | `sub_556580` and `ReleaseSemaphore`. |
| `xrefs_to 0x00596960` | 22 code refs, including FileDownloader submit helpers, the target wrapper, Socket command wrappers, packet queue/send helpers, and other network/request families. |

Representative caller contrast:

| Address | IDA decompile summary | Ownership implication |
| --- | --- | --- |
| `0x0041b180` | Allocates minimap payload and calls `sub_596960(this, 10000, payload, 0)`. | Documented FileDownloader submit helper has direct command/payload semantics and caller context. |
| `0x0041b200` | Allocates CashShopRequest payload, posts command `10001`, and stores payload on fitting-room state. | Documented FileDownloader helper; direct source-use evidence exists. |
| `0x0041b270` | Allocates CashShopVersionRequest payload or null, posts command `10002`. | Documented FileDownloader helper; immediately precedes target but does not call it. |
| `0x0041b2f0` | Clears `dword_67A738`. | FileDownloader global cleanup after target-alignment gap; not evidence for the target. |
| `0x00574b90` | `return sub_596960(this, 7, a2, a3);` | Documented Socket wrapper because callers and Socket dispatcher consume command `7`. |
| `0x00574bb0` | Copies packet buffer, then posts command `8`. | Documented Socket queue/send helper due `g_packetSender` and Socket dispatcher evidence. |
| `0x00574c20` | `return sub_596960(this, 9, a2, 0);` | Documented Socket wrapper with source-use context. |

Stale-name check:

| Check | Result |
| --- | --- |
| `func_query *std_fs*` | Found the target and a second 20-byte function at `0x0058ea60`, both named like `___std_fs_create_symbolic_link`. |
| `decompile 0x0058ea60` | Same two-argument-plus-zero wrapper shape, but calling `0x0058f690`; zero xrefs to that start. |
| Documentation search | `0x0058f690` is a TextEditPane coordinate/navigation helper in existing docs. |
| Import query | No `CreateSymbolicLink` / symbolic-link import found; only semaphore imports were relevant to the Thread queue primitive. |

Inference: the `___std_fs_create_symbolic_link@8` label is a stale/misapplied IDA name on small unreferenced wrapper-shaped functions. It is not reliable source ownership evidence and does not justify CRT/filesystem reclassification.

## Facts vs Inference

Confirmed facts:

- The target is exactly `0x0041b2d0-0x0041b2e4`, one basic block, 20 bytes.
- The only callee is `0x00596960`, the documented base Thread async queue-post helper.
- The target pushes explicit zero as the third queue payload argument and forwards two stack arguments plus the receiver.
- IDA reports zero xrefs to the target start.
- Raw byte scans found no branch or pointer encodings to the target start.
- The adjacent FileDownloader submit helpers call `0x00596960` directly and do not route through this wrapper.
- The wrapper's IDA filesystem-like name is contradicted by the body and by absence of filesystem API behavior.

Inference:

- The body is likely a source-authored convenience overload or local helper over the base Thread queue primitive.
- The best semantic family is Thread queue dispatch support, but the exact declaration owner is not proven.
- Because no source-use context exists, there is no justified emitter route. An emitted wrapper in `Thread.cpp`, `FileDownloader.cpp`, `Socket.cpp`, or multiple files would be speculative.

## Ranked Candidate Owners and Routes

### 1. Thread / `NexusTK/util/Thread.cpp` ([UID:0000EV], [UID:0000OR])

Evidence for:

- The target calls only `0x00596960`, documented as the base async Thread queue-post helper.
- The body has a `this` receiver and exactly supplies an optional zero payload, matching a plausible overload over `Thread::DispatchRequest`.
- [UID:0000EV] `Thread` and [UID:0000OR] `Thread` file now clear the owner/emitter numeric gate.

Evidence against:

- No caller, vtable slot, data pointer, constructor, RTTI, receiver-origin, or direct source-island evidence ties this exact wrapper to `Thread`.
- The target is physically in the FileDownloader/CashShop request neighborhood, not in the `0x00596250-0x0059756e` Thread/ThreadMan island.
- `0x00596960` is a shared inherited primitive with FileDownloader and Socket callers. A callee dependency proves behavior, not direct ownership.
- Existing Socket wrappers demonstrate the correct pattern: wrappers over `0x00596960` attach to the command owner when caller/dispatcher evidence exists, not to Thread merely because the queue primitive is the callee.

Decision: strongest semantic candidate, but do not attach. Do not set `CANONICAL_OWNER:0000EV` or `EMITTER_UIDS:0000EV/0000OR` without source-use evidence.

### 2. FileDownloader / `NexusTK/network/FileDownloader.cpp` ([UID:00004W], [UID:0000JC])

Evidence for:

- The target sits immediately after FileDownloader request-submit helpers in the former [UID:0000WI] address inventory.
- The three preceding FileDownloader helpers all post into the same Thread queue primitive.

Evidence against:

- The target has no FileDownloader global access, no `dword_67A738` access, no downloader message constants, no request allocation, and no caller through the FileDownloader singleton.
- FileDownloader helpers at `0x0041b180`, `0x0041b200`, and `0x0041b270` call `0x00596960` directly.
- Physical adjacency is mixed; the broad inventory was already converted to a non-reconstructable mixed map because adjacent children belong to different owners/runtime classes.

Decision: reject as owner/emitter. Do not set `CANONICAL_OWNER:00004W` or `EMITTER_UIDS:00004W/0000JC`.

### 3. Socket / network command wrapper family ([UID:0000DD], [UID:0000NS])

Evidence for:

- Socket has several documented tiny wrappers over `0x00596960` with command IDs.
- The `0x00574a*` and `0x00574b*` docs show how direct callers and dispatcher command cases can prove a wrapper owner even when the callee is Thread.

Evidence against:

- The target is not in the Socket island, has no known command ID, and has no callers through `g_packetSender`.
- No Socket dispatcher case or command consumer can be tied to this exact wrapper because there is no xref/use site.
- The target's forwarded arguments are generic and do not reveal Socket-specific state.

Decision: reject as direct owner/emitter. Socket is useful comparison evidence, not an ownership lead for this target.

### 4. TextEditPane-style duplicate stale wrapper

Evidence for:

- IDA has a second stale `___std_fs_create_symbolic_link@8_0` at `0x0058ea60`, also 20 bytes, also zero xrefs, also a two-argument wrapper supplying zero to a local helper.
- Existing docs tie its callee `0x0058f690` to TextEditPane navigation/coordinate conversion, not filesystem code.

Evidence against:

- This duplicate calls a different helper and belongs in a different address island. It does not prove ownership of `0x0041b2d0`.

Decision: use only as negative evidence against trusting the stale IDA filesystem name and as evidence that unreferenced overload wrappers can survive without a current source-use route.

### 5. CRT/STL/filesystem runtime

Evidence for:

- IDA names the target `___std_fs_create_symbolic_link@8`.

Evidence against:

- The function does not call filesystem APIs, path handling, error translation, CRT/STL filesystem helpers, or imports.
- Its only callee is a NexusTK Thread queue primitive.
- Import query found no symbolic-link import lead.
- The duplicate stale-name wrapper at `0x0058ea60` also contradicts treating the name as authoritative.

Decision: reject runtime reclassification. Keep source-authored NexusTK behavior.

### 6. Compiler/linker-generated or ignored

Evidence for:

- The target is unreferenced and wrapper-shaped.

Evidence against:

- It is not a scalar deleting destructor, adjustor thunk, EH/RTTI helper, import thunk, padding, or alignment.
- It contains project-specific queue-post semantics and a direct internal project callee.
- The exact wrapper shape is plausible source-authored overload/local helper code.

Decision: do not reclassify to `RECONSTRUCTABLE:FALSE`. Keep `RECONSTRUCTABLE:TRUE`.

### 7. Multiple emitters with `CANONICAL_OWNER:NONE`

Evidence for:

- `by-structure.md` allows no canonical owner plus multiple emitters for pooled/shared items when independent source-use contexts are proven.

Evidence against:

- This is not pooled data, a string literal, or a shared constant.
- There are zero xrefs/use sites to establish even one source-use context.
- Multiple emitters would only reflect plausible source families, not proven emitted use.

Decision: leave `EMITTER_UIDS` blank. No emitter is justified.

## Negative Evidence Summary

- No IDA xrefs to `0x0041b2d0`.
- No raw relative branch or pointer encodings to `0x0041b2d0`.
- No vtable/data pointer evidence.
- No FileDownloader singleton/global access or direct FileDownloader caller.
- No Socket receiver/global/dispatcher evidence.
- No Thread island/source-layout evidence for this exact wrapper.
- No filesystem/runtime API behavior despite the stale IDA name.
- No final-source name, signature, or source declaration location recovered.

## Score and Coverage Effects

Keep scores unchanged:

| Field | Before | After recommendation | Reason |
| --- | ---: | ---: | --- |
| `COMPLETION` | `86` | `86` | The function boundary, behavior, and negative evidence are strong, but source owner/name are unresolved. |
| `CONFIDENCE` | `86` | `86` | Confidence is strong for no-current-route; not enough for 95+ final-source or owner assignment. |
| `CANONICAL_OWNER` | `NONE` | `NONE` | No direct semantic owner clears evidence threshold. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Real NexusTK project helper code. |
| `EMITTER_UIDS` | blank | blank | No source-use context and no emitted C++ block. |

No by-memory coverage-report edits are required. If the supervisor wants a note update anyway, the current row text above is still accurate and should be retained.

## Commands and Validation

Leases:

- Checked current leaser context as part of the B001 workflow. No lease was required because the only file created is in `tools/leaser/Agents/Agent-B001/research`.

IDA MCP commands/results used:

- `idb_open` with session `b001_0003gy`: success, Hex-Rays ready.
- `server_health`: ok, imagebase `0x400000`.
- `lookup_funcs` for `0x0041b2d0`, `0x0041b2e4`, `0x00596960`, and adjacent functions: confirmed target size/end and neighboring starts.
- `disasm`, `decompile`, `callees`, `xrefs_to`, `get_bytes`, `make_signature_for_range`, and `analyze_function` for `0x0041b2d0`: confirmed body, callee, zero callers, bytes, and one-block shape.
- `xrefs_to 0x00596960`: confirmed broad caller set including FileDownloader, Socket, packet-send, and the target.
- `decompile` for representative FileDownloader and Socket wrappers: confirmed other wrappers have source-use context that the target lacks.
- `find_bytes` for target VA/RVA and exact bytes: no target pointer hits; exact byte pattern only at target when call displacement is fixed.
- Raw PE branch/pointer scan: no branch or pointer encodings to `0x0041b2d0`.
- `func_query` / `imports_query`: found duplicate stale `___std_fs_create_symbolic_link` wrapper at `0x0058ea60`; found no symbolic-link import lead.

One broad IDA rendered-list text search timed out and was replaced with narrower function/import queries. This did not block the result because direct xref, byte, import, function, and decompile evidence already covered the ownership question.

Project validation:

- No by-memory, by-class, by-file, generated, or coverage-report documentation was edited.
- No validator was run because there were no validator-managed by-* edits to apply. No dry-run validator mode was used.

## Changed Files

- Created `tools/leaser/Agents/Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-post-migration.md`.

## Blockers

No blocker prevents this recommendation. Future evidence that could change it would need to identify a real source-use context: a recovered caller, vtable/data pointer, PDB/linker/source symbol, matching source declaration, or dispatcher/case evidence tying this exact wrapper to a class or file.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B001/0003GY-UnreferencedThreadDispatchWrapper-post-migration.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
