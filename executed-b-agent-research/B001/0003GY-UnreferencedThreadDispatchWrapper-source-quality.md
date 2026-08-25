** TARGET-REPORT-UID:0003GY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003GY **
# B001 Research Report: 0003GY UnreferencedThreadDispatchWrapper Source Quality

Assignment id: `B001-redo-unreferenced-thread-dispatch-wrapper-source-quality-0003GY-mcp-20260623`

Agent: `Agent-B001`

Target: [UID:0003GY] `source-3/project-documentation/by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`

Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-source-quality.md`

Task type: report-only B-agent source-quality redo. No by-* docs, generated/project-level files, IDA DB, tool state, or `-coverage-report.md` files were edited.

## Executive Recommendation

Keep [UID:0003GY] metadata and source-output disposition unchanged:

```text
COMPLETION:86
CONFIDENCE:86
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

Current MCP session `ff68e691` confirms that `0x0041b2d0-0x0041b2e4` is a real 20-byte source-side queue wrapper, not padding and not CRT/filesystem code. It preserves `ecx`, pushes literal `0`, forwards two stack arguments, calls `0x00596960`, and returns with `retn 8`.

The best forced semantic family remains `Thread` because `0x00596960` is the base `Thread::DispatchRequest` queue-post primitive. That remains a dependency relationship only. MCP finds no caller, pointer, vtable/table route, data ref, immediate ref, branch/call target, import/string route, source-neighbor proof, or receiver-origin evidence for this exact wrapper. FileDownloader adjacency, derived-worker wrapper patterns, runtime/filesystem naming, and a new one-function source group all remain weaker than the current no-owner/non-emitting retained-helper disposition.

Recommended implementation if accepted:

- Keep score/metadata/owner/emitter/range/C++ unchanged.
- Add a narrow target-page provenance correction only if the supervisor wants by-* docs to reflect this current MCP-backed redo and to supersede the older report-only fallback wording.
- No support by-* docs need new behavior detail; the current support pages already carry the valid facts at same-or-greater detail.
- Supervisor should add the missing manual coverage rows for `0x0041b2c9-0x0041b2f0` in `by-memory/-coverage-report.md`; exact text is below. B001 must not apply it directly.

## Scope And Inputs

- Current goal read: `tools/leaser/Agents/Agent-B001/goal.md`.
- Active supervisor override: use MCP session `ff68e691`; this supersedes stale `goal.md` session `261fb29b`.
- Skill references read: `ntk-b-agent-workflow/SKILL.md`, `references/b-agent-research-and-implementation-workflow.md`, `by-structure.md` MCP notes, and `tools/int_convert_readme.md`.
- Target page read: `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`.
- Support docs checked:
  - `by-class/Thread.md`
  - `by-file/Thread.md`
  - `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`
  - `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`
  - `by-class/FileDownloader.md`
  - `by-file/FileDownloader.md`
  - `by-memory/-ignored.md`
- Coverage/generated checks:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `by-memory/-coverage-report.md`
- Archived/old B-agent reports were treated only as leads. Current MCP evidence is the authority for this redo.

## MCP Session Health

MCP endpoint: `http://127.0.0.1:13337/mcp`

Active database: `ff68e691`

Health evidence:

- `idb_list`: session `ff68e691`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, `is_active:true`, `is_analyzing:false`, PID/worker PID `14256`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `lookup_funcs 0x004651c0` was supervisor-verified before assignment resume; B001 also verified target-specific lookups below.

One optional broad `search_text` call for `___std_fs_create_symbolic_link` over `.text` timed out after 60 seconds. Follow-up `server_health` was still `ok`, and the same stale-name route was covered by focused `entity_query`, `find_regex`, `imports_query`, `xrefs_to`, and `find` calls. This was not treated as MCP unavailability.

## Current Target State

Current metadata:

| Field | Current value |
| --- | --- |
| UID | `0003GY` |
| Range | `0x0041b2d0-0x0041b2e4` |
| Completion | `86` |
| Confidence | `86` |
| Canonical owner | `NONE` |
| Reconstructable | `TRUE` |
| Emitters | blank |
| Reconstruction C++ | blank |

Current target docs already include the valid behavior facts: exact bytes, disassembly/decompile shape, surrounding `0xcc` padding, stale-name rejection, no direct xrefs/routes, duplicate same-shape wrapper, `0x00596960` queue-post semantics, ranked owner rejections, and no-code proof.

Two current doc-state issues remain implementation candidates:

- The active target page still has a historical 2026-06-18 section that says the B001 pass used local PE fallback because MCP was unreachable. That historical statement can remain, but it should be explicitly superseded by a 2026-06-23 MCP-backed `ff68e691` redo note if the supervisor wants current provenance in by-* docs.
- The target page's Rule 26 coverage paragraph says the manual `by-memory/-coverage-report.md` row already matched. Current `rg` found generated `auto-generated/-ag-memory-coverage.md` rows for `0003GY`, but no standalone `0003GY` row in `by-memory/-coverage-report.md`; the manual report only mentions adjacent real code inside the `0000WK` row. This report supplies supervisor-owned coverage insertion/replacement text.

## MCP Function And Boundary Evidence

`lookup_funcs` results:

| Query | MCP result |
| --- | --- |
| `0x0041b2c9` | not a function |
| `0x0041b2d0` | function `___std_fs_create_symbolic_link@8`, size `0x14` |
| `0x0041b2e0` | inside `___std_fs_create_symbolic_link@8`, size `0x14` |
| `0x0041b2e4` | not a function |
| `0x0041b2f0` | function `sub_41B2F0`, size `0x0b` |
| `0x00596960` | function `sub_596960`, size `0x50` |
| `0x0058ea60` | function `___std_fs_create_symbolic_link@8_0`, size `0x14` |
| `0x0058f690` | function `sub_58F690`, size `0xa6` |

`entity_query` over `0x0041b250-0x0041b310` found four modeled functions: `0x0041b270`, `0x0041b2d0`, `0x0041b2f0`, and `0x0041b300`. This confirms the target is an exact function island between modeled neighbors, not a merge candidate.

`get_bytes` around `0x0041b2c0-0x0041b300`:

```text
9c b6 17 00 5e 8b e5 5d c3 cc cc cc cc cc cc cc
55 8b ec 6a 00 ff 75 0c ff 75 08 e8 80 b6 17 00 5d c2 08 00
cc cc cc cc cc cc cc cc cc cc cc cc
c7 05 38 a7 67 00 00 00 00 00 c3 cc cc cc cc cc
```

Exact subranges:

| Range | MCP byte result |
| --- | --- |
| `0x0041b2c9-0x0041b2d0` | seven `0xcc` bytes |
| `0x0041b2d0-0x0041b2e4` | `55 8b ec 6a 00 ff 75 0c ff 75 08 e8 80 b6 17 00 5d c2 08 00` |
| `0x0041b2e4-0x0041b2f0` | twelve `0xcc` bytes |
| `0x0041b2f0-0x0041b300` | `c7 05 38 a7 67 00 00 00 00 00 c3` plus five `0xcc` bytes |

`make_signature_for_range 0x0041b2d0-0x0041b2e4` with operands not wildcarded returned the same 20-byte signature and marked it unique:

```text
55 8B EC 6A 00 FF 75 0C FF 75 08 E8 80 B6 17 00 5D C2 08 00
```

MCP `int_convert` verified `0x14` is decimal `20` and `0x0c` is decimal `12`.

## MCP Body Evidence

MCP `disasm 0x0041b2d0`:

```asm
0041b2d0  push ebp
0041b2d1  mov ebp, esp
0041b2d3  push 0
0041b2d5  push [ebp+arg_4]
0041b2d8  push [ebp+arg_0]
0041b2db  call sub_596960
0041b2e0  pop ebp
0041b2e1  retn 8
```

MCP stack frame for the target has two explicit dword stack arguments at `+0x8` and `+0x0c`. MCP decompiler renders:

```cpp
BOOL __thiscall __std_fs_create_symbolic_link(void *this, int a2, int a3)
{
  return sub_596960((int)this, a2, a3, 0);
}
```

The `BOOL`, `void *`, and symbolic-link spelling are IDA type/name pollution. The machine-code facts are stable:

- `ecx` is preserved as receiver.
- Stack argument at `+0x8` is forwarded as the first queue argument.
- Stack argument at `+0x0c` is forwarded as the second queue argument.
- Literal `0` is supplied as the third queue argument.
- The function returns with `retn 8`, consuming the two explicit stack arguments.

`analyze_function 0x0041b2d0`:

- name `___std_fs_create_symbolic_link@8`
- prototype `BOOL __thiscall(void *this, int, int)`
- size `20`
- one basic block, cyclomatic complexity `1`
- strings: none
- constants: none
- callees: `sub_596960`
- callers: none
- inbound xrefs: none

## Thread Queue Callee Evidence

MCP `analyze_function 0x00596960` confirms the callee behavior documented in Thread support pages:

```cpp
BOOL __thiscall sub_596960(int this, int a2, int a3, int a4)
{
  int v5;
  _DWORD Src[6];

  Src[0] = a2;
  Src[1] = a3;
  Src[2] = a4;
  v5 = *(_DWORD *)(this + 76);
  memset(&Src[3], 0, 12);
  sub_556580(v5, Src);
  return ReleaseSemaphore(*(HANDLE *)(this + 12), 1, 0);
}
```

Disassembly details:

- Copies the three explicit arguments into a six-dword local `ThreadMessage`-like record.
- Zeros the final three dwords at offsets `[3..5]`.
- Loads queue pointer from receiver offset `+0x4c` / decimal `76`.
- Calls queue insertion helper `0x00556580`.
- Calls `ReleaseSemaphore` on receiver offset `+0x0c` / decimal `12`.
- Returns with `retn 0Ch`.

MCP `xrefs_to 0x00596960` and `find type=code_ref` both found 22 code references:

```text
0x0041b1e8
0x0041b253
0x0041b2aa
0x0041b2bf
0x0041b2db
0x00453a92
0x005282ed
0x0052838e
0x005283cb
0x00574aed
0x00574b0d
0x00574b26
0x00574b5d
0x00574b7a
0x00574b9b
0x00574c05
0x00574c2c
0x00574c94
0x00574cbc
0x00574d31
0x00574e2e
0x005752af
```

This broad fan-in supports base Thread ownership for `0x00596960`. It does not prove direct ownership for the unreferenced caller wrapper at `0x0041b2d0`.

## Direct Route And No-Route Evidence

MCP route checks:

| Check | Result |
| --- | --- |
| `xrefs_to 0x0041b2d0` | zero xrefs |
| `xrefs_to 0x0041b2e4` | zero xrefs |
| `trace_data_flow backward 0x0041b2d0` | start node only, no incoming edge |
| `find code_ref 0x0041b2d0` | zero matches |
| `find code_ref 0x0041b2d1` | zero matches |
| `find code_ref 0x0041b2d3` | zero matches |
| `find code_ref 0x0041b2e4` | zero matches |
| `find data_ref 0x0041b2d0` | zero matches |
| `find data_ref 0x0041b2e4` | zero matches |
| `find immediate 0x0041b2d0` | zero matches |
| `find immediate 0x0041b2e4` | zero matches |
| `find_bytes D0 B2 41 00` | zero VA-pointer byte matches for target start |
| `find_bytes D0 B2 01 00` | zero RVA-pointer byte matches for target start |
| `find_bytes E4 B2 41 00` / `E4 B2 01 00` | zero endpoint VA/RVA byte matches |
| `find_bytes 68 D0 B2 41 00` | zero `push 0x0041b2d0` byte matches |

Positive controls from the same MCP pass:

- `find code_ref 0x0041b2f0`: one match at `0x005f670e`.
- `xrefs_to 0x0041b2f0`: one code xref from `0x005f670e` inside `sub_41A670`.
- `xrefs_to 0x0067a738`: nine data refs, including `0x0041b2f0`, `0x0041c215`, `0x0041cd09`, `0x00451cf8`, and `0x00464a98`.
- `xrefs_to 0x00596960`: 22 code refs.
- `find data_ref 0x00634034` and `find immediate 0x00634034`: one match at `0x005c710c`.

The controls prove the route tools can find nearby real FileDownloader/global/string/callee routes. The absence of a target-start route is meaningful.

## Stale Name And Runtime/String Evidence

Current IDA name `___std_fs_create_symbolic_link@8` remains stale and misleading.

MCP evidence:

- `imports_query` for `*CreateSymbolicLink*`, `*Symbolic*`, and `*std_fs*`: no imports.
- `find_regex CreateSymbolicLink|std_fs|Symbolic`: two strings only:
  - `0x00633d98`: `too many symbolic link levels`
  - `0x00634034`: `CreateSymbolicLinkW`
- `xrefs_to 0x00633d98`: zero xrefs.
- `trace_data_flow backward 0x00633d98`: no incoming edges.
- `xrefs_to 0x00634034`: one data ref at `0x005c710c`.
- `trace_data_flow backward 0x00634034`: route sits in `?initialize_pointers@@YAHXZ`; it pushes the API-name string, calls `GetProcAddress`, and stores the result near `unk_69C214`.
- `entity_query names/functions` for symbolic/std_fs names found only:
  - target function `0x0041b2d0` named `___std_fs_create_symbolic_link@8`
  - duplicate same-shape function `0x0058ea60` named `___std_fs_create_symbolic_link@8_0`
  - string name `aCreatesymbolic` at `0x00634034`

Correct statement:

- The binary does contain a `CreateSymbolicLinkW` API-name string and an unrelated symbolic-link error string.
- Neither string has a route to `0x0041b2d0`.
- The target body has no path arguments, filesystem API call, error translation, import/IAT relation, or CRT/STL filesystem behavior.

## Duplicate Same-Shape Wrapper Evidence

MCP `find_bytes` for the exact target body found one match:

```text
0x0041b2d0
```

MCP `find_bytes` for broader wrapper shape:

```text
55 8B EC 6A 00 FF 75 ?? FF 75 ?? E8 ?? ?? ?? ?? 5D C2 08 00
```

found two matches:

```text
0x0041b2d0 -> 0x00596960
0x0058ea60 -> 0x0058f690
```

MCP `disasm 0x0058ea60`:

```asm
0058ea60  push ebp
0058ea61  mov ebp, esp
0058ea63  push 0
0058ea65  push [ebp+arg_4]
0058ea68  push [ebp+arg_0]
0058ea6b  call sub_58F690
0058ea70  pop ebp
0058ea71  retn 8
```

MCP `decompile 0x0058ea60` renders another stale symbolic-link-style wrapper over `0x0058f690`. MCP `xrefs_to 0x0058ea60` finds zero inbound xrefs; `xrefs_to 0x0058f690` finds fourteen inbound xrefs from other UI/text-edit neighborhood code.

This weakens any owner/source-name argument based on either the stale IDA name or the tiny default-argument wrapper shape. The shape is a generic retained wrapper idiom, not a filesystem proof and not unique to this FileDownloader/Thread neighborhood.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct parent | Score | Current decision |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0041b2d0-0x0041b2e4` | [UID:0003GY] target page | Retained wrapper over `0x00596960` | TRUE | `NONE` | `86/86` | Keep unchanged |
| `0x0041a670-0x0041b69f` | [UID:0000WI] FileDownloaderDispatch | Mixed surrounding inventory | FALSE | `NONE` | `88/90` | Correct non-emitting container |
| `0x0041b270-0x0041b2c9` | [UID:0002CL] FileDownloaderSubmitCashShopVersionRequest | Neighbor FileDownloader submit helper | TRUE | FileDownloader | `82/strong` in manual coverage | Contrast only |
| `0x0041b2c9-0x0041b2d0` | [UID:0000VN] ignored padding | Seven `0xcc` bytes | FALSE | ignored | `100/strong` in ignored docs | Manual coverage row missing |
| `0x0041b2e4-0x0041b2f0` | [UID:0000VN] ignored padding | Twelve `0xcc` bytes | FALSE | ignored | `100/strong` in ignored docs | Manual coverage row missing |
| `0x0041b2f0-0x0041b2fb` | [UID:0000WK] ClearFileDownloaderRequestGlobal | Neighbor FileDownloader unwind/global clear | TRUE | FileDownloader | `85/92` target metadata | Positive route contrast |
| `0x00596960-0x005969b0` | [UID:0001JY] / [UID:0000OR] | Base `Thread::DispatchRequest` queue post | TRUE | Thread | support-owned | Sole callee, not wrapper owner proof |
| `0x0058ea60-0x0058ea74` | no current target page found | Duplicate same-shape stale-name wrapper over `0x0058f690` | likely retained code | unresolved | not scored here | Negative stale-name/shape evidence |

## Documentation Evidence Cross-Check

Current support docs already contain the behavior and ownership conclusions needed for this target:

- `by-file/Thread.md` records [UID:0003GY] as a dependency-only semantic wrapper around `0x00596960`, not emitted Thread output.
- `by-class/Thread.md` records that the wrapper forwards `(this, messageId, payload, 0)` to `0x00596960` but has no caller, vtable/data pointer, source-neighbor, or declaration route proving a direct `Thread` method.
- `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md` documents `0x00596960` as `BOOL Thread::DispatchRequest(int messageId, int arg1, int arg2)`, packing a 24-byte message into `m_messageQueue` at `this+0x4c` and releasing the primary semaphore at `this+0x0c`; it also records the 22-call fan-in.
- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md` keeps `0003GY` as real parent-blank code inside a mixed inventory, not absorbed into FileDownloader output.
- `by-memory/-ignored.md` already lists both adjacent padding spans `0x0041b2c9-0x0041b2d0` and `0x0041b2e4-0x0041b2f0`.
- `auto-generated/-ag-memory-coverage.md` lists [UID:0003GY] as no-owner, owner `NONE`, blank emitters, no generated destination, and no C++.
- `project-level/-auto-completion-stats.md` lists [UID:0003GY] at `86/86`.

Current manual coverage mismatch:

- `by-memory/-coverage-report.md` has no standalone `0003GY` row.
- The manual coverage block currently jumps from [UID:0002CL] at `0x0041b270-0x0041b2c9` to [UID:0000WK] at `0x0041b2f0-0x0041b2fb`.
- Exact supervisor-owned coverage text is supplied below.

## Positive Evidence Summary

- Real executable function island: MCP confirms a modeled function at `0x0041b2d0`, size `0x14`, with an exclusive end at `0x0041b2e4`.
- Exact bytes are unique for this body.
- Surrounding boundaries are clean: seven `0xcc` bytes before and twelve `0xcc` bytes after.
- The body is source-authored or source-declared project helper behavior: it calls internal `0x00596960`, not an import thunk, EH helper, RTTI helper, or CRT filesystem routine.
- `0x00596960` directly enqueues a six-dword message through receiver offset `+0x4c` and releases receiver semaphore `+0x0c`.
- The same MCP pass found the successor route, FileDownloader global routes, `CreateSymbolicLinkW` runtime route, and 22 `0x00596960` callers as positive controls.

## Negative Evidence Summary

Checked and rejected by current MCP:

- Direct ordinary xrefs to `0x0041b2d0`.
- Direct ordinary xrefs to endpoint `0x0041b2e4`.
- Backward data-flow route into `0x0041b2d0`.
- Code refs to `0x0041b2d0`, `0x0041b2d1`, `0x0041b2d3`, or `0x0041b2e4`.
- Data refs to `0x0041b2d0` or `0x0041b2e4`.
- Immediate refs to `0x0041b2d0` or `0x0041b2e4`.
- Raw VA/RVA pointer bytes to target start or endpoint.
- `push 0x0041b2d0` bytes.
- Vtable/table/global pointer route to the function start.
- FileDownloader global `dword_67A738` access inside target.
- FileDownloader message ids or payload setup inside target.
- Socket receiver/global/dispatcher route.
- MiscWorkThread/CashShopRequest/derived-worker caller route.
- ProtocolSend/Session source root route.
- Import/IAT route for `CreateSymbolicLink*`, `Symbolic`, or `std_fs`.
- String/source route from `CreateSymbolicLinkW` or `too many symbolic link levels` to the target.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| The exact target body is a `0x14` byte / decimal 20 function. | Confirmed | MCP `lookup_funcs`, `get_bytes`, `make_signature_for_range`, `disasm`, `int_convert`. | `0x0041b2c9` and `0x0041b2e4` are not function starts; adjacent padding is `0xcc`. | None for boundary. |
| The wrapper posts through `0x00596960` with a literal zero third queue argument. | Confirmed for machine behavior | MCP disassembly/decompile and `callees`; body pushes `0`, `[ebp+arg_4]`, `[ebp+arg_0]`, calls `sub_596960`. | Stale decompiler name/type contradicted by body. | Exact original parameter names remain unknown. |
| `0x00596960` is base `Thread::DispatchRequest` infrastructure. | Strong | MCP callee decompile plus Thread support docs: six-dword message, queue `this+0x4c`, semaphore `this+0x0c`, broad 22-call fan-in. | Derived wrappers have separate caller/receiver/dispatcher proof; callee ownership alone does not own this wrapper. | No blocker for callee; wrapper owner unresolved. |
| Thread is the best forced semantic family for this wrapper. | Medium | Sole callee is a Thread queue primitive; wrapper shape resembles default-argument forwarding. | No caller, vtable slot, source-neighbor, declaration, pointer, table, or receiver-origin proof. | Revisit only if a direct route to the wrapper start appears. |
| FileDownloader is not the direct owner. | Strong | No `dword_67A738`, no downloader message id, no caller passing singleton, no fields, no vtable/data route; adjacent helpers have those proofs. | Physical adjacency and mixed inventory checked. | None unless new caller/global route appears. |
| Runtime/filesystem ownership is stale/misapplied. | Strong | Target body calls NexusTK queue primitive; imports absent; symbolic-link strings route nowhere or to runtime `GetProcAddress`, not target; duplicate stale wrapper exists. | Stale IDA label and strings checked. | Optional IDA rename/comment cleanup only; not documentation ownership proof. |
| No formal C++ should be emitted. | Strong | Blank `EMITTER_UIDS`; no owner/source route; code-entry gate requires nonblank emitter route. | Body is mechanically reconstructable but source placement is not. | Revisit if owner/emitter route is proven. |
| Score should remain `86/86`. | Strong | Exact boundary/body/no-route evidence is strong, but source owner/emitter/C++ remain unresolved. | Lower score would understate current MCP evidence; higher score would overstate source-placement certainty. | None for this pass. |

## Ranked Ownership And Source-Placement Analysis

### 1. No-owner / non-emitting retained helper - accepted

Evidence for:

- Current MCP finds no ordinary xrefs, callers, code refs, data refs, immediates, raw VA/RVA pointer bytes, endpoint route, string/import route, vtable/table route, or source-neighbor route to the function start.
- The function is real project code, so `RECONSTRUCTABLE:TRUE` remains correct.
- Current by-structure rules allow reconstructable source code to remain no-owner/non-emitting while source placement is unproven.

Evidence against:

- The wrapper almost certainly came from some source-level construct, and Thread remains a plausible semantic family.

Decision:

- Accept no-owner/non-emitting. This is the only state that preserves behavior evidence without inventing source placement.

### 2. Thread / `Thread.cpp` - strongest forced semantic candidate, rejected as direct owner/emitter

Evidence for:

- Sole callee is base `Thread::DispatchRequest`.
- The body looks like an out-of-line default-argument or convenience wrapper around queue posting.
- Thread support docs already own the callee and its queue/message layout.

Evidence against:

- The wrapper sits outside the Thread/ThreadMan memory island.
- No caller, vtable slot, constructor route, source-neighbor route, pointer/table route, receiver-origin proof, or declaration evidence ties this exact wrapper to `Thread.cpp`.
- Other wrappers over `0x00596960` belong to derived/source-specific owners when their callers, receivers, command consumers, or globals prove it.

Decision:

- Do not set `CANONICAL_OWNER:0000EV` or `EMITTER_UIDS:0000OR`. Mention Thread only as dependency and best forced candidate.

### 3. FileDownloader / CashShop request island - rejected

Evidence for:

- The target is physically between FileDownloader-family helper `0x0041b270-0x0041b2c9` and FileDownloader unwind helper `0x0041b2f0-0x0041b2fb`, inside the broader `FileDownloaderDispatch` mixed inventory.

Evidence against:

- The target is separated from neighbors by `0xcc` padding.
- It has no `dword_67A738` read/write.
- It has no downloader message id `10000`, `10001`, or `10002`.
- It performs no request payload allocation.
- It has no FileDownloader field access, caller route, vtable route, or singleton receiver evidence.

Decision:

- Reject as owner/emitter. Adjacency remains weak address-neighborhood evidence only.

### 4. Derived-worker wrappers - rejected

Evidence for:

- MiscWorkThread, Socket, CashShopRequest, FileDownloader submit helpers, and packet-send helpers all use `0x00596960`.

Evidence against:

- Those wrappers have independent proof such as singleton receivers, caller windows, vtables, command IDs, dispatcher consumers, field access, or source-neighbor families.
- This target has none of those route proofs.

Decision:

- Reject MiscWorkThread, Socket, CashShopRequest, ProtocolSend-like request sender, and FileDownloader submit ownership. Their evidence threshold is useful only as contrast.

### 5. Runtime / filesystem / stale `std_fs` name - rejected

Evidence for:

- Stale IDA label resembles a `std::filesystem` symbolic-link helper.
- `.rdata` contains symbolic-link-related strings.

Evidence against:

- No parsed import matching `CreateSymbolicLink`, `Symbolic`, or `std_fs`.
- No target body filesystem behavior.
- No path/string/error translation in the target.
- `CreateSymbolicLinkW` routes through `?initialize_pointers@@YAHXZ` and `GetProcAddress`, not through this wrapper.
- A duplicate same-shape stale-named wrapper exists at `0x0058ea60` and calls unrelated `0x0058f690`.

Decision:

- Reject runtime/filesystem classification and reject filesystem source-facing names.

### 6. New one-function source group - rejected

Evidence for:

- A source helper existed somewhere if this function was emitted.

Evidence against:

- No source path, debug breadcrumb, table, caller cluster, coherent related item set, declaration family, or consumer route proves a source file.
- A standalone `ThreadDispatchWrapper.cpp` would be a reconstruction artifact.

Decision:

- Reject.

### 7. `RECONSTRUCTABLE:FALSE` / ignored artifact - rejected

Evidence for:

- The function has no inbound refs and a tiny wrapper shape.

Evidence against:

- It is executable project code calling internal Thread infrastructure.
- It is not padding, import glue, EH/RTTI, scalar deleting destructor glue, or proven CRT/STL/library body.

Decision:

- Keep `RECONSTRUCTABLE:TRUE`.

### 8. `CANONICAL_OWNER:NONE` with emitters - rejected

Evidence for:

- The metadata model can represent shared/no-canonical-owner source data with emitters in other cases.

Evidence against:

- This is a function with zero proven source-use contexts. Multiple emitters would guess where an unreferenced helper may have appeared.

Decision:

- Keep `EMITTER_UIDS` blank.

## Source-Facing Names And Signature

Safe documentation name:

- `UnreferencedThreadDispatchWrapper`

Safe descriptive behavior name:

- `ThreadDispatchRequestDefaultParamWrapper`

Not safe as a formal source signature:

- `Thread::DispatchRequest(...)` overload spelling, because direct Thread declaration/source route is unproven.
- FileDownloader, CashShopRequest, Socket, ProtocolSend, or Session method names.
- `___std_fs_create_symbolic_link@8`, `create_symbolic_link`, or any filesystem/path helper name.

Parameter guidance:

- Receiver: describe only as `Thread`-like or queue-owner-like in prose.
- First explicit argument: message/request id or dispatch code.
- Second explicit argument: payload/context pointer.
- Supplied third queue argument: literal `0`.

Behavior-only pseudocode remains useful but must not be placed in formal `RECONSTRUCTION_CPP`:

```cpp
// Descriptive only. Do not use as formal RECONSTRUCTION_CPP without a proven emitter.
bool ThreadDispatchRequestDefaultParamWrapper(Thread *thread, unsigned int messageId, void *payload) {
    return thread->DispatchRequest(messageId, payload, 0);
}
```

## Score And Metadata Recommendation

Current score/metadata:

```text
COMPLETION:86
CONFIDENCE:86
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

Recommended score/metadata: unchanged.

Score rationale:

- Completion should not rise because unresolved owner/source placement, blank emitters, and blank formal C++ remain material reconstruction blockers.
- Confidence should not rise because the no-owner conclusion is strong but still negative; original declaration/source placement remains unknown.
- Score should not fall because current MCP now directly confirms exact boundary, body, padding, callee semantics, route-negative matrix, stale-name rejection, and support-doc consistency.
- `RECONSTRUCTABLE:TRUE` remains correct because this is executable NexusTK project helper code.
- `CANONICAL_OWNER:NONE` remains correct because no candidate clears the direct semantic ownership gate.
- Blank `EMITTER_UIDS` remains correct because no source-use context or source-output route is proven.

## First-Draft C++ Recommendation

Eligible for draft C++: no.

Reason code should remain blank:

- The average score is above the numeric minimum, but the current code-entry gate also requires a confirmed nonblank `EMITTER_UIDS` route to generated source.
- `EMITTER_UIDS` is blank by design.
- No owner/source placement is proven.
- Thread owns the callee, not this wrapper.
- FileDownloader owns adjacent helpers, not this wrapper.
- Runtime/filesystem is contradicted.
- A new one-function source group would be artificial.

Exact no-code proof:

```text
The function body is mechanically reconstructable, but current MCP finds no caller, pointer, vtable slot, table entry, branch target, endpoint route, import/string route, source-neighbor route, receiver-origin path, generated source path, or declaration evidence identifying a valid emitter. Formal C++ would require choosing Thread, FileDownloader, a derived worker, runtime/filesystem, ProtocolSend/Session, or a new helper file without source-route proof. That would create polluted pseudo-source. Keep RECONSTRUCTABLE:TRUE, CANONICAL_OWNER:NONE, blank EMITTER_UIDS, and blank RECONSTRUCTION_CPP until a real source route appears.
```

## Recommended Target Doc Changes If Accepted

Target path: `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`

Required behavior/metadata changes: none.

Recommended narrow provenance and coverage-state correction:

- Add a 2026-06-23 B001 MCP-backed redo note using session `ff68e691`.
- State that the current MCP pass supersedes the old active report's MCP-unavailable/manual-fallback evidence as the current acceptance evidence.
- Preserve the historical 2026-06-18 fallback section as history if desired, but do not leave it as the latest current evidence.
- Correct or supersede the Rule 26 sentence saying the manual `by-memory/-coverage-report.md` row already matched. Current manual coverage lacks a standalone `0003GY` row; generated coverage has it. The report supplies supervisor-owned coverage insertion text.
- Keep all target metadata unchanged at `86/86`, `CANONICAL_OWNER:NONE`, blank emitters, `RECONSTRUCTABLE:TRUE`, and blank formal C++.

Suggested target-doc text, if the supervisor wants exact insertion:

```text
## 2026-06-23 B001 MCP-Backed Redo

B001 redid the source-quality pass with active MCP session `ff68e691` after the older active report was rejected for MCP-unavailable fallback evidence. MCP `server_health` was `ok` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `analyze_function`, `xrefs_to`, `find`, `find_bytes`, `imports_query`, `find_regex`, `entity_query`, and `trace_data_flow` reconfirmed the existing no-owner/no-emitter result. The function is exactly `0x14` bytes at `0x0041b2d0`, bounded by seven `0xcc` bytes at `0x0041b2c9-0x0041b2d0` and twelve `0xcc` bytes at `0x0041b2e4-0x0041b2f0`; it forwards `ecx`, two stack arguments, and literal `0` to `0x00596960` / Thread queue dispatch, and it has no start/endpoint xrefs, code/data/immediate refs, VA/RVA byte pointer route, import/string route, vtable/table route, FileDownloader-global route, or source-placement route. Keep `86/86`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`, and blank formal C++.

Coverage note: generated memory coverage lists [UID:0003GY] as no-owner/non-emitting, but current manual `by-memory/-coverage-report.md` did not contain a standalone `0003GY` row as of this redo. B001 supplied exact supervisor-owned coverage insertion text in the report; B001 did not edit coverage directly.
```

## Recommended Support Doc Changes If Accepted

Required support by-* doc changes: none.

The following support docs already contain same-or-greater detail for the accepted facts:

- `by-class/Thread.md`
- `by-file/Thread.md`
- `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`
- `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`
- `by-class/FileDownloader.md`
- `by-file/FileDownloader.md`
- `by-memory/-ignored.md`

No support doc should be edited unless the supervisor wants a provenance-only sync. If a later implementation callback changes any support by-* doc, run a scoped validator only for that changed file.

## Exact Supervisor-Owned Coverage Text

B001 must not edit `by-memory/-coverage-report.md`. Current manual coverage is missing the standalone target row and the two adjacent padding rows. If accepted, supervisor should update `by-memory/-coverage-report.md` around the current block after [UID:0002CL] `0x0041b270-0x0041b2c9` and before [UID:0000WK] `0x0041b2f0-0x0041b2fb`.

Insert these rows after the current [UID:0002CL] row:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041b2c9-0x0041b2d0 | padding | Version submit to unreferenced Thread dispatch wrapper alignment : ignored : 100% : strong : MCP session `ff68e691` byte check shows seven `0xcc` bytes between [UID:0002CL][0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest](by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md) and [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md).
        - [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) 0x0041b2d0-0x0041b2e4 | function | UnreferencedThreadDispatchWrapper : reconstructable/no-owner : 86% : strong : MCP session `ff68e691` confirms stale-named `___std_fs_create_symbolic_link@8` is a 20-byte wrapper that preserves `ecx`, pushes literal `0`, forwards its two stack arguments, calls `0x00596960` / Thread queue dispatch, and returns `retn 8`; `xrefs_to`, code/data/immediate refs, VA/RVA byte-route checks, import/string checks, and FileDownloader-global controls find no caller, pointer, vtable/table, branch, endpoint, filesystem, FileDownloader, or source-placement route, so keep no-owner/non-emitting with blank formal C++.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0041b2e4-0x0041b2f0 | padding | Unreferenced Thread dispatch wrapper to FileDownloader global clear alignment : ignored : 100% : strong : MCP session `ff68e691` byte check shows twelve `0xcc` bytes between [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) and [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md).
```

Replace the current [UID:0000WK] row sentence that says adjacent `0x0041b2d0` real code remains outside the padding ledger with this row text:

```text
        - [UID:0000WK][0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal](by-memory/0x0041b2f0-0x0041b2fb.ClearFileDownloaderRequestGlobal.md) 0x0041b2f0-0x0041b2fb | function | ClearFileDownloaderRequestGlobal : reconstructable : 85% : strong : Tiny constructor-unwind cleanup helper that clears `dword_67A738`; MCP session `ff68e691` confirms the incoming jump at `0x005f670e` targets this successor helper, while adjacent [UID:0003GY][0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper](by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md) remains separate no-owner queue-wrapper code.
```

## Open Questions With Attempted Resolution

- Was this an original `Thread` overload?
  - Evidence checked: Thread callee ownership, callee body, route scans, target xrefs, duplicate wrapper shape, support docs.
  - Resolution: plausible but unproven; not enough for owner/emitter.
- Was this a FileDownloader helper?
  - Evidence checked: surrounding functions, `dword_67A738`, message ids, caller windows, padding, support pages, MCP xrefs.
  - Resolution: rejected. Adjacency only.
- Is the stale filesystem name valid?
  - Evidence checked: imports, strings, duplicate stale wrapper, runtime string routes, target body.
  - Resolution: rejected. Symbolic-link strings are runtime/error strings with no target route.
- Is `0x0058ea60` proof of a wrapper family?
  - Evidence checked: wrapper-shape scan, MCP disasm/decompile, xrefs.
  - Resolution: it proves the stale-name/wrapper idiom is not unique; it does not prove target ownership.
- Can a source-facing helper name be inferred?
  - Resolution: descriptive names can be used in prose; no formal original source name is inferred above gate.
- Is first-draft C++ ready?
  - Resolution: no. Missing emitter/source route blocks formal C++.

## Validator Expectations

Validators run during report-only pass: none.

Reason: no by-* docs, generated files, project-level files, tool state, IDA DB, or coverage reports were edited.

Expected validators after an accepted implementation callback:

- If only the target provenance/coverage-state note is added:

> Executable block R001 was removed from this report and preserved verbatim in [0003GY-UnreferencedThreadDispatchWrapper-source-quality-removed.md](0003GY-UnreferencedThreadDispatchWrapper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- If the supervisor requests any support by-* provenance sync, run the same scoped validator for each changed support file only.
- B agents do not edit `by-memory/-coverage-report.md`; supervisor-owned coverage application should be validated by the supervisor's normal coverage process.

## Changed Files

- Modified during implementation callback: `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`
- Modified during implementation callback: `tools/leaser/Agents/Agent-B001/research/0003GY-UnreferencedThreadDispatchWrapper-source-quality.md`
- Validator-owned side effects reported by the scoped validator: `project-level/-auto-completion-stats.md` projected stats/three `0003GY` row updates, and `tools/validator.ini` registry rebuild.

No support by-* docs, IDA DB, or `-coverage-report.md` files were edited by B001.

## Confidence

- Recommendation confidence: strong.
- Boundary confidence: confirmed by current MCP.
- Behavior confidence: confirmed by current MCP.
- No-owner/non-emitting confidence: strong under current evidence.
- Remaining uncertainty: exact original source declaration, original helper name, and source file are unknown.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: supervisor accepted the report and issued callback `B001-implement-unreferenced-thread-dispatch-wrapper-source-quality-0003GY-mcp-20260623`.
- [x] Target metadata changes to apply: none; after implementation the target still has `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP`.
- [x] Target by-* doc edit if accepted: added `## 2026-06-23 B001 MCP-Backed Redo` to `by-memory/0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`, making MCP session `ff68e691` the current accepted evidence while preserving the 2026-06-18 MCP-unavailable/manual-fallback pass as historical.
- [x] Target by-* doc stale coverage-state correction if accepted: updated `Current Metadata And Coverage State` to supersede the old "manual coverage row already matched" wording and state that current manual `by-memory/-coverage-report.md` lacked a standalone `0003GY` row before this pass.
- [x] Support by-* docs to update: none required; `by-class/Thread.md`, `by-file/Thread.md`, `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`, `by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md`, `by-class/FileDownloader.md`, `by-file/FileDownloader.md`, and `by-memory/-ignored.md` were not edited because they already contain same-or-greater valid behavior/detail and no direct stale contradiction was found.
- [x] Owner/emitter/reconstructable changes to apply: none; target remains no-owner/non-emitting retained helper and `RECONSTRUCTABLE:TRUE`.
- [x] Split/rename/new-child changes to apply: none; exact range remains `0x0041b2d0-0x0041b2e4`.
- [x] Source-placement/range/padding/reclassification/IDA rename/type/comment changes to apply: no source placement; no split/reclass; no IDA edits requested or made; safe descriptive names remain prose-only.
- [x] First-draft C++ or no-code proof to apply: no formal C++; target section now restates the target-specific no-code proof that helper-only C++ would create polluted pseudo-source without an emitter route.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: target section preserves stale `___std_fs_create_symbolic_link@8`, runtime `CreateSymbolicLinkW` route correction, Thread/FileDownloader/derived-worker/runtime/new-file rejections, no caller/no pointer/no branch/no vtable/table/no source route, and the historical fallback pass.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: no Wave2/Wave3 route accepted as authority; no by-* implementation edit needed.
- [x] Open questions to close or document as evidence-backed unresolved: original source owner/name remains unresolved with score/C++ impact documented in the target section and report.
- [x] Validators to run after accepted by-* implementation: ran the scoped target validator; command/result recorded below.
- [x] Supervisor-owned coverage-report/tracker text to apply: exact `by-memory/-coverage-report.md` insertion/replacement text remains in this report for supervisor-owned application; B001 did not edit coverage.
- [x] Remaining blockers to implementation: none for accepted non-coverage scope; coverage application remains supervisor-owned by project rule.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: accepted callback received for `0003GY`; scope limited to target non-coverage edits and report checklist update.
- [x] All accepted target/support doc details incorporated at report-level detail or marked already present at same-or-greater detail: target doc now includes the `ff68e691` redo note with health/session, exact function, padding, call body, no-route matrix, stale-name rejection, rejected owner/source alternatives, unchanged no-owner/no-emitter score, and no-code proof; support docs were already sufficient and were not edited.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: no metadata/source-output changes accepted; target verified unchanged at `86/86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, exact range, and blank formal C++.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: historical 2026-06-18 MCP-unavailable/local PE pass remains as history; new text makes `ff68e691` current accepted evidence and preserves stale symbolic-link, Thread/FileDownloader/runtime/new-file rejection, and negative-route evidence.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: exact source owner/name/emitter remains unresolved; target now documents why that keeps C++ blank and score unchanged.
- [x] Validators run and results recorded: `python .\tools\validator.py --mode file --file by-memory\0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md --apply --queue-timeout 240` from `source-3/project-documentation`; exit code `0`; `ok: 1`; side effects reported by validator: `project-level/-auto-completion-stats.md` projected stats update plus three `0003GY` row updates, `tools/validator.ini` registry rebuild, generated reports unchanged/noop.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: coverage text remains supplied above; no `-coverage-report.md` file edited by B001.
- [x] Remaining unapplied accepted items listed with exact blocker: none; accepted non-coverage items complete. Lease proof: B001 leased only `by-memory\0x0041b2d0-0x0041b2e4.UnreferencedThreadDispatchWrapper.md`, released it immediately after edit/validator batch, and current lease report shows no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003GY","source_path":"executed-b-agent-research/B001/0003GY-UnreferencedThreadDispatchWrapper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
