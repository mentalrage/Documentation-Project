** TARGET-REPORT-UID:0001FQ **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001FQ QueueReadSlotRaw Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001FQ] `by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md` as reconstructable Queue class code, keep the direct class owner/emitter route through [UID:0000BF] `Queue`, and replace the blank formal C++ block with inferred source-facing `Queue::ReadSlot(void *slot)`.
- Final disposition: exact first-draft C++ is supported. `QueueReadSlotRaw` remains the documentation role/range name; `ReadSlot` is the best source-facing method spelling currently supported by behavior and the accepted sibling `Queue::WriteSlot(const void *slot)` disposition.
- Required action after supervisor validation: update the target and Queue support docs at report-level detail, then run scoped validators with generated output current. Do not edit by-* docs during this report-only pass.
- Confidence: strong for exact bytes, body semantics, Queue layout, owner/emitter route, and first-draft source shape; still capped below final audit because IDA has no function object or caller route for the raw start and no recovered original method symbol.

## Target

- Target UID: `0001FQ`.
- Target path: `by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md`.
- Assignment id: `B013-report-0001FQ-QueueReadSlotRaw-source-quality-20260627`.
- Required report path: `tools/leaser/Agents/Agent-B013/research/0001FQ-QueueReadSlotRaw-source-quality.md`.
- Source queue: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Generated tracker row observed: `auto-generated/-ag-research-tracker.md:1585` lists [UID:0001FQ] as not-covered reconstructable with stale `82/84` generated metadata. The source page itself is currently `85/88`; implementation validators should refresh generated state.

## Current Target State

Current source header in the target page:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `85` |
| `CONFIDENCE` | `88` |
| `CANONICAL_OWNER` | `0000BF` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000BF` |
| `EMITTER_POSITION_OPTIONAL` | `40` |
| Formal C++ | blank inline value and blank multiline block |

The current target text already records exact behavior, corrected `0x00553b10-0x00553b55` bounds, `retn 4` endpoint, no xrefs, no pointer-byte hits, the valid Queue owner/emitter route, and the final-source blocker. The stale part is the final source-quality decision: it says final C++ remains blank until a source-name/signature pass settles method spelling and raw-helper representation. This report performs that pass.

Support docs checked:

- `by-memory/0x005539e0-0x00553c07.Queue.md`
- `by-class/Queue.md`
- `by-file/Queue.md`
- `by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md`
- `by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md`
- `by-memory/0x005539e0-0x00553a5c.QueueConstructor.md`
- `by-memory/0x00553a60-0x00553ab9.QueueDestructor.md`
- `by-memory/0x00553b70-0x00553c07.QueueScalarDeletingDestructor.md`
- `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
- `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`
- `by-project-structure/proposed-source-tree.md`
- `auto-generated/NexusTK/util/Queue.cpp`
- `executed-b-agent-research/B013/0001FP-QueueWriteSlotRaw-source-quality.md`

No target/support by-* docs were edited during this report-only pass.

## IDA MCP Availability

IDA MCP was available and used. This report is not fallback-only.

| Field | Value |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp` version `1.0.0` |
| Protocol after initialize | `2025-06-18` |
| Active session | `b001_000241_20260627` |
| Backend | worker |
| Worker PID | `23132` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module | `NexusTK.exe` |
| Input path | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Imagebase | `0x400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |
| Strings cache | ready, size `2067` |

Read-only MCP calls used included `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `disasm`, `get_bytes`, `xrefs_to`, `callees`, `find_bytes`, `make_signature_for_range`, `entity_query`, `search_structs`, and `type_query`. No IDA DB edits were made.

One broad `search_text Queue` style request timed out during evidence gathering. Read-only status checks showed `127.0.0.1:13337` listening, `Test-NetConnection` succeeded, `idalib-mcp`/Python/IDA worker processes were present, and a retry after a short wait returned `server_health status: ok`. I narrowed the searches and completed the MCP-backed pass.

## Evidence Checked

IDA MCP evidence checked:

- `server_health(database=b001_000241_20260627)`.
- `lookup_funcs` for `0x005539e0`, `0x00553a60`, `0x00553ac0`, `0x00553b05`, `0x00553b10`, `0x00553b55`, `0x00553b60`, `0x00553b6a`, `0x00553b70`, `0x00553c07`, `0x00516030`, and `0x00516220`.
- `decompile 0x00553b10`, `disasm 0x00553b10`, `get_bytes` around `0x00553b05-0x00553b70`, `xrefs_to` for `0x00553b10`, `0x00553b55`, `0x00553b60`, and `0x00622d24`, `callees` for `0x00553b10`, and `make_signature_for_range 0x00553b10-0x00553b55`.
- `decompile 0x005539e0` to reconfirm Queue layout.
- `entity_query` for Queue and exact candidate names, plus `search_structs Queue` and `type_query *Queue*`.
- `find_bytes` for absolute and RVA pointer patterns to the read helper, and positive controls.

Supplemental local PE evidence checked:

- Read-only scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Imagebase `0x400000`; `.text` VA span `0x00401000-0x0060c600`.
- Dword VA pattern for `0x00553b10`: `10 3B 55 00`.
- Dword RVA pattern for `0x00153b10`: `10 3B 15 00`.
- Direct `E8`/`E9` call/jump targets in `.text` to `0x00553b10`.
- Positive control: scalar deleting destructor VA pattern `70 3B 55 00` found at file offset `0x221724`, VA `0x00622d24`, matching the Queue vtable slot.

Generated/read-only docs checked:

- `auto-generated/-ag-research-tracker.md` row for [UID:0001FQ] remains stale at `82/84`.
- `auto-generated/-ag-memory-coverage.md:1736` shows [UID:0001FQ] routed to `auto-generated/NexusTK/util/Queue.cpp` but not coded.
- `auto-generated/-ag-coverage-report-by-memory.md:1892` still shows [UID:0001FQ] as `emits_code:false`.
- `auto-generated/NexusTK/util/Queue.cpp` currently emits only [UID:0001FP] `Queue::WriteSlot` and a marker for [UID:0001FQ] with stale `82/84` metadata.
- Attempted local `source-3/simroot_v2/class_Queue.cpp` check found no such file at the expected workspace path, so simroot was not used as authority.

No stale Wave2/Wave3 material was used as proof. Existing docs and the executed [UID:0001FP] B013 report were used as leads and rechecked against current IDA MCP/manual evidence.

## IDA MCP Facts

Function model and boundary facts:

- `lookup_funcs` reports modeled Queue functions at `0x005539e0` (`sub_5539E0`, size `0x7c`), `0x00553a60` (`sub_553A60`, size `0x59`), and `0x00553b70` (`sub_553B70`, size `0x97`).
- `lookup_funcs` reports `0x00553ac0`, `0x00553b05`, `0x00553b10`, `0x00553b55`, `0x00553b60`, `0x00553b6a`, and `0x00553c07` as `Not a function`.
- `lookup_funcs` confirms the dependencies at `0x00516030` (`sub_516030`, size `0x6`) and `0x00516220` (`sub_516220`, size `0x18`).
- `decompile 0x00553b10` fails with `Decompilation failed at 0x553b10`, as expected for a raw not-a-function start.
- `get_bytes 0x00553b10 size 0x45` confirms the exact 69-byte body (`0x45` -> `69`, verified with `tools/int_convert.py`) ending with `c2 04 00` at `0x00553b52`.
- `get_bytes 0x00553b05 size 101` confirms eleven `0xcc` pre-padding bytes (`0x0b` -> `11`, verified with `tools/int_convert.py`) at `0x00553b05-0x00553b10`, the body at `0x00553b10-0x00553b55`, eleven post-padding bytes at `0x00553b55-0x00553b60`, and the following empty predicate at `0x00553b60-0x00553b6a`.
- `make_signature_for_range 0x00553b10-0x00553b55` with operand wildcarding disabled returned a unique exact-byte signature.

Current read-helper disassembly:

| Address | Instruction | Source interpretation |
| --- | --- | --- |
| `0x00553b10` | `push ebp` | raw method prologue |
| `0x00553b14` | `mov edi, ecx` | preserve `this` |
| `0x00553b16` | `call sub_516030` | `GetMemoryMan()` |
| `0x00553b1b` | `mov edx, [edi+10h]` | load `m_readIndex` |
| `0x00553b1e` | `mov ecx, eax` | `MemoryMan *` receiver |
| `0x00553b20` | `imul edx, [edi+4]` | compute `m_readIndex * m_slotSize` |
| `0x00553b24` | `push dword ptr [edi+4]` | copy size `m_slotSize` |
| `0x00553b27` | `add edx, [edi+0Ch]` | source `m_buffer + offset` |
| `0x00553b2a` | `push edx` | source argument |
| `0x00553b2b` | `push dword ptr [ebp+8]` | caller destination pointer |
| `0x00553b2e` | `call sub_516220` | `MemoryMan::MemmoveWrapper(destination, source, size)` |
| `0x00553b33` | `mov eax, [edi+8]` | load `m_slotCount` |
| `0x00553b36` | `mov ecx, [edi+10h]` | reload `m_readIndex` |
| `0x00553b39` | `dec eax` | last valid index `m_slotCount - 1` |
| `0x00553b3a` | `cmp eax, ecx` | compare last index to current read index |
| `0x00553b3c` | `jg short loc_553B4A` | increment when `m_readIndex < m_slotCount - 1` |
| `0x00553b3e` | `mov dword ptr [edi+10h], 0` | wrap `m_readIndex` to zero |
| `0x00553b47` | `retn 4` | one explicit stack argument |
| `0x00553b4a` | `lea eax, [ecx+1]` | compute next read index |
| `0x00553b4d` | `mov [edi+10h], eax` | store incremented `m_readIndex` |
| `0x00553b52` | `retn 4` | one explicit stack argument |

Queue layout support:

- `decompile 0x005539e0` stores `a2` at `this[1]`, stores `a3` at `this[2]`, allocates `a3 * a2` through `sub_5160D0`, and zeroes `this[4]` and `this[5]`.
- This reconfirms `+0x04` as `m_slotSize`, `+0x08` as `m_slotCount`, `+0x0c` as `m_buffer`, `+0x10` as `m_readIndex`, and `+0x14` as `m_writeIndex`.
- The accepted sibling [UID:0001FP] uses the same `m_slotSize`, `m_slotCount`, and `m_buffer` fields but advances `m_writeIndex`.
- [UID:0001FR] compares `m_readIndex` and `m_writeIndex`.

Xref and route facts:

- `xrefs_to 0x00553b10`, `xrefs_to 0x00553b55`, and `xrefs_to 0x00553b60` return zero incoming xrefs.
- `callees 0x00553b10` returns `No function found`; the raw bytes themselves contain internal calls to `0x00516030` and `0x00516220`.
- `xrefs_to 0x00622d24` returns Queue vtable writes at `0x00553a15`, `0x00553a88`, and `0x00553b9f`.
- `find_bytes` finds no absolute VA bytes `10 3B 55 00` and no RVA bytes `10 3B 15 00` for the raw read start.
- `find_bytes` positive controls find scalar deleting destructor pointer bytes `70 3B 55 00` at `0x00622d24` and Queue vtable bytes `24 2D 62 00` at `0x00553a17`, `0x00553a8a`, and `0x00553ba1`.
- The local PE scan finds no dword VA/RVA pointer route and no direct `E8`/`E9` call/jump route to `0x00553b10`.

Name/type facts:

- `entity_query` for `Queue|WriteSlot|ReadSlot|IsEmpty|Enqueue|Dequeue` returns only Queue RTTI/vtable names and the `Queue` string, not source method symbols.
- Exact `entity_query` for `ReadSlot|WriteSlot|IsEmpty|Enqueue|Dequeue` returns no names or strings.
- `search_structs Queue` returns no local structures.
- `type_query *Queue*` returns no local UDT/type record.

## Positive Evidence Summary

- The raw body is a coherent one-argument `thiscall` method body with stable prologue, `this` preservation, `GetMemoryMan()` call, `MemmoveWrapper` call, one explicit pointer argument, index update, and `retn 4`.
- Argument order proves copy-out behavior: `destination = [ebp+8]`, `source = m_buffer + (m_readIndex * m_slotSize)`, `size = m_slotSize`.
- The body advances `m_readIndex`, wrapping to zero at `m_slotCount - 1`, which is the exact read-side mirror of accepted [UID:0001FP] `Queue::WriteSlot`.
- Queue constructor and empty helper corroborate field meanings.
- [UID:0001BC] already emits `MemoryMan* GetMemoryMan()`, and [UID:0001BH] already emits `MemoryMan::MemmoveWrapper(void *destination, const void *source, size_t size)`, so final C++ should use those source-facing names rather than raw `sub_` labels.
- The target is already reconstructable, has a valid nonblank emitter route, and `(85 + 88) / 2 > 85`, so it is eligible for formal first-draft C++ under current by-structure rules.

## Negative / Counter-Evidence Summary

- IDA still has no function object at `0x00553b10`; decompilation fails for the raw start.
- There are no direct xrefs, callers, VA/RVA pointer hits, or direct local PE `E8/E9` routes to the raw start.
- No recovered symbol, string, UDT, source path, or comment proves the original method name.
- The raw no-route state remains a confidence cap, but it is not a no-code proof. The body is source-authored Queue behavior with a valid owner/emitter route and exact C++ shape.
- No evidence supports moving ownership away from the Queue class, merging this range with [UID:0001FP] or [UID:0001FR], or converting it to a no-code/compiler-generated range.

## Heuristic / Inference Reanalysis And Validation

### Raw helper role and liveness

Best decision: treat `0x00553b10-0x00553b55` as a source-authored Queue read-slot helper even though IDA does not model it as a function. The exact body, Queue layout, adjacent sibling helpers, and valid class/file route outweigh the raw-start artifact.

Rejected alternatives:

| Alternative | Reason rejected |
| --- | --- |
| Dead/unreachable no-code helper | No route is proven, but the body is not padding, compiler glue, or a stray thunk. It is a complete Queue method-shaped fixed-slot read body adjacent to the accepted write helper and empty predicate. |
| Compiler-generated helper | The body implements class-specific buffer/index semantics and calls project MemoryMan helpers; it is not EH, RTTI, vtable, security-cookie, import, or CRT glue. |
| Merge with [UID:0001FP] or [UID:0001FR] | Boundaries are separated by `0xcc` padding; each child has independent behavior and exact end-exclusive range. |
| Keep blank C++ solely because no caller/name proof exists | Current rules require a formal C++/no-code/metadata disposition for eligible routed reconstructable targets. The source body is exact enough for first-draft C++. |

### Source-facing name and signature

Accepted name/signature: `void Queue::ReadSlot(void *slot)`.

Reasoning:

- `ReadSlot` mirrors the accepted sibling `Queue::WriteSlot(const void *slot)`.
- The helper reads exactly one fixed-size slot from the circular buffer into a caller-provided destination pointer.
- The explicit argument is a destination buffer, so `void *slot` is the correct source-facing type. It is not `const void *` because the helper writes into that memory.
- The helper returns no value in source terms. The binary preserves no meaningful `MemmoveWrapper` result because the post-copy index update overwrites `eax`.
- `ReadSlot` is more precise than `Read` because it names the fixed-size slot abstraction already established by `WriteSlot` and avoids implying a stream/read-file operation.

Rejected names:

| Candidate | Reason rejected |
| --- | --- |
| `QueueReadSlotRaw` / `Queue::ReadSlotRaw` | `Raw` is documentation for the IDA boundary state, not plausible source API spelling. |
| `Queue::Read` | Plausible but less precise, and no symbol/caller proves the shorter spelling. |
| `Queue::Pop` | Implies a higher-level queue API and often returns or removes a typed value; this body only copies a caller-provided fixed-size slot and advances the read index. |
| `Queue::Dequeue` | Similar to `Pop`; plausible as a high-level concept, but no empty check or return status exists in this helper. |
| `Queue::Get` / `Queue::ReadBuffer` | Not supported by local naming, behavior, or sibling source shape. |
| `sub_553B10` or IDA/decompiler labels | Reverse-engineering label, not source-facing C++. |

### Field and helper naming

Accepted inferred field names for the formal body:

- `m_slotSize` for `+0x04`.
- `m_slotCount` for `+0x08`.
- `m_buffer` for `+0x0c`.
- `m_readIndex` for `+0x10`.

These match the class page and the accepted [UID:0001FP] source shape. They are inferred from access patterns, not recovered from a local Queue UDT. `search_structs Queue` and `type_query *Queue*` found no local UDT/type record.

### Source placement

Keep direct owner/emitter [UID:0000BF] `Queue`, routed to [UID:0000MW] `Queue` / `NexusTK/util/Queue.cpp`. The target is a class method, not a free helper or MemoryMan method. The MemoryMan calls are dependencies only.

### Generated-output pollution

The validator-generated `auto-generated/NexusTK/util/Queue.cpp` currently emits [UID:0001FP] and marker-only output for [UID:0001FQ]. The generated marker still carries stale `82/84` metadata even though the by-memory source page is `85/88`. That generated output is an input/lead only; implementation should refresh it through scoped validators with `--wait-generated`.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0001FQ] is a Queue class read-slot method body. | Strong | Raw disassembly, constructor layout, sibling write helper, empty predicate, direct class owner route. | No xrefs/callers/pointers/direct branch route; no UDT. | Active reachability remains unproven. |
| The source-facing method should be `Queue::ReadSlot(void *slot)`. | Strong inference | Copy-out body, one explicit destination pointer, accepted `WriteSlot` sibling, fixed-slot Queue abstraction. | No recovered source symbol; `Read`, `Pop`, `Dequeue` considered. | Exact original spelling remains unrecovered. |
| Formal first-draft C++ is safe to insert. | Strong | Eligible metadata/emitter gate, exact body, valid helper dependencies, exact boundaries. | Raw not-a-function/no-route state; no original name. | Final header factoring and active-use proof remain broader class/file work. |
| Owner/emitter metadata should stay [UID:0000BF]. | Strong | Queue class layout and vtable support, support docs at/above gate, by-structure direct semantic owner rule. | File-level direct owner and no-owner/no-emitter alternatives considered. | None for this child under current docs. |

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:0000BF`, routes to [UID:0000MW] `Queue.cpp`, and the current score average is above the code-entry gate.

Exact formal `RECONSTRUCTION_CPP CODE` content to insert after supervisor validation:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void Queue::ReadSlot(void *slot)
{
    GetMemoryMan()->MemmoveWrapper(
        slot,
        static_cast<unsigned char *>(m_buffer) + (m_readIndex * m_slotSize),
        m_slotSize);

    if (m_readIndex >= m_slotCount - 1) {
        m_readIndex = 0;
    } else {
        ++m_readIndex;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason this preserves exact behavior:

- Destination/source/size argument order matches the stack pushes at `0x00553b24-0x00553b2b` and the accepted `MemoryMan::MemmoveWrapper` signature.
- Pointer arithmetic matches `m_buffer + m_readIndex * m_slotSize`.
- The wrap branch exactly matches `cmp m_slotCount - 1, m_readIndex`; if the current index is at or beyond the last valid index, set zero; otherwise store `m_readIndex + 1`.
- The function has one explicit pointer argument and no meaningful return value.

Reason this matches plausible original source shape:

- It mirrors the already accepted `Queue::WriteSlot(const void *slot)` style and field names.
- It uses source-facing helper names `GetMemoryMan()` and `MemmoveWrapper`, not raw `sub_` labels.
- It is a concise mid-2000s utility class method, not decompiler-shaped scaffolding.

No third-party import directive applies.

## Ranked Ownership / Source Disposition

### 1. Keep direct owner/emitter [UID:0000BF] `Queue`

- Evidence for: target uses `this` fields from the Queue layout, mirrors accepted `WriteSlot`, shares vtable/class cluster, and is routed through class/file support that clears the active gate.
- Evidence against: no direct callers/xrefs and no local Queue UDT.
- Decision: accepted. Missing caller/UDT evidence is a confidence cap, not an ownership blocker.

### 2. Direct file owner [UID:0000MW] `Queue`

- Evidence for: final generated destination is `NexusTK/util/Queue.cpp`.
- Evidence against: by-structure requires the narrow semantic owner when a method belongs to a class and the class clears the gate.
- Decision: rejected as direct canonical owner/emitter for this child; [UID:0000MW] remains the source-file route through the Queue class.

### 3. No-code or metadata/emitter fallback

- Evidence for: raw start has no function object, no xrefs, and no proven original symbol.
- Evidence against: this is still exact source-authored Queue code with a valid route and a complete source body.
- Decision: rejected. Use formal first-draft C++ and preserve raw/no-route caveats.

## Range / Split / Padding / Reclassification Analysis

No split or range change is recommended.

| Range | Current interpretation | Evidence |
| --- | --- | --- |
| `0x00553b05-0x00553b10` | Eleven-byte pre-padding | MCP `get_bytes`, all `0xcc`; separates [UID:0001FP] from [UID:0001FQ]. |
| `0x00553b10-0x00553b55` | Complete read-slot body | MCP disassembly and `get_bytes`; unique exact-byte signature. |
| `0x00553b55-0x00553b60` | Eleven-byte post-padding | MCP `get_bytes`, all `0xcc`; separates [UID:0001FQ] from [UID:0001FR]. |
| `0x00553b60-0x00553b6a` | Sibling empty predicate | Existing [UID:0001FR] and MCP disassembly. |

## Score And Metadata Recommendation

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `87` |
| `CONFIDENCE` | `88` | `90` |
| `CANONICAL_OWNER` | `0000BF` | unchanged |
| `RECONSTRUCTABLE` | `TRUE` | unchanged |
| `EMITTER_UIDS` | `0000BF` | unchanged |
| `EMITTER_POSITION_OPTIONAL` | `40` | unchanged |
| Formal C++ | blank | insert exact `Queue::ReadSlot(void *slot)` block above |

Score rationale:

- Raise completion to `87` because this pass adds current MCP session provenance, exact instruction-level source mapping, unique signature, explicit negative route scan, candidate-name/type searches, rejected alternatives, and formal first-draft C++.
- Raise confidence to `90` to align with the accepted sibling [UID:0001FP] confidence level. The read body is equally exact and uses the same helper vocabulary/layout evidence.
- Do not raise above `90` because no function object, xrefs/callers, pointer route, direct branch route, local Queue UDT, or recovered original method spelling exists.

## Recommended Target Doc Changes

Target path: `by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md`.

Apply these report facts at implementation:

- Change `COMPLETION:85` to `COMPLETION:87`.
- Change `CONFIDENCE:88` to `CONFIDENCE:90`.
- Preserve `CANONICAL_OWNER:0000BF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BF`, and `EMITTER_POSITION_OPTIONAL:40`.
- Insert the exact formal `Queue::ReadSlot(void *slot)` C++ block from this report into the target's formal `RECONSTRUCTION_CPP CODE` block only.
- Update `Item Summary` to say the target now emits inferred `Queue::ReadSlot(void *slot)` C++, copies from `m_buffer + m_readIndex * m_slotSize` to the caller slot, wraps `m_readIndex`, and preserves raw not-a-function/no-route caveats.
- Update `Status` with source-facing method `Queue::ReadSlot(void *slot)`, explicitly marking `QueueReadSlotRaw` as documentation role name.
- Update `Behavior` to use `m_` field names consistent with [UID:0001FP].
- Add a current 2026-06-27/2026-06-28 B013 MCP evidence section with session `b001_000241_20260627`, health metadata, function/non-function lookup, decompile failure, disassembly instruction mapping, byte/padding facts, unique signature, xref/callee facts, pointer/direct-route negatives, Queue layout support, MemoryMan helper support, no local Queue UDT, and no recovered candidate method symbols.
- Replace the old source-quality decision that leaves final C++ blank with the decision to emit inferred `Queue::ReadSlot(void *slot)`.
- Preserve rejected alternatives: `QueueReadSlotRaw`, `Queue::Read`, `Queue::Pop`, `Queue::Dequeue`, `Queue::Get`, `sub_553B10`, no-code, metadata fallback, and owner/emitter fallback.
- Update score rationale and change log.

## Recommended Support Doc Changes

Support path: `by-memory/0x005539e0-0x00553c07.Queue.md`.

- Update status/confidence caveat so [UID:0001FQ] is resolved to first-draft C++ as inferred `Queue::ReadSlot(void *slot)`; [UID:0001FR] remains unresolved.
- Update the Functions row for `0x00553b10-0x00553b55` to mention the formal source method and copy-out/wrap behavior.
- Add B013 implementation evidence for read-slot current MCP facts and negative route checks.
- Update Reconstruction Notes to state [UID:0001FP] and [UID:0001FQ] now emit on child pages; aggregate C++ remains blank.
- Keep aggregate score `85/88` unless the supervisor decides the broader aggregate score should move; this report only requires the support text to stop treating FQ as unresolved.

Support path: `by-class/Queue.md`.

- Update Confidence/Remaining blockers text so [UID:0001FQ] is no longer part of the blanket raw-helper source-output blocker.
- Update the Methods row for `0x00553b10` to say it emits inferred `Queue::ReadSlot(void *slot)`.
- Preserve remaining caveats: [UID:0001FR] source-output decision, constructor/destructor/header factoring, and active-use proof.
- Keep class-level C++ blank; child method bodies emit on child pages.

Support path: `by-file/Queue.md`.

- Update File Role and Proposed Contents to say [UID:0001FQ] now contributes formal first-draft `Queue::ReadSlot(void *slot)` C++ through the Queue class route.
- Update generated-output/source-family caveat so only the broader constructor/destructor/header factoring and [UID:0001FR] remain unresolved for source-output decisions.
- Preserve source route `NexusTK/util/` and `CANONICAL_OWNER:FILE`; no by-file score change is required by this report.

No direct edits are recommended for [UID:0001FP] or [UID:0001FR] child pages during this callback except cross-references/caveats in the listed support docs. Do not edit manual `-coverage-report.md` files.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` text is required or permitted for this assignment. The relevant generated tracker/coverage rows should refresh from source docs through validator execution after implementation and supervisor verification. Do not manually edit `auto-generated/-ag-*` reports or `project-level/*` generated files.

## Expected Validation Commands After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after supervisor validation and implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0001FQ-QueueReadSlotRaw-source-quality-removed.md](0001FQ-QueueReadSlotRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The implementation result should report command id, timestamp, exit code, `ok`, generated-refresh state, and the generated `auto-generated/NexusTK/util/Queue.cpp` header showing UID `0001FQ` with the accepted `Queue::ReadSlot` body.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution / impact |
| --- | --- | --- |
| Is the raw helper a real source method despite no IDA function object? | MCP lookup/decompile/disasm/bytes/signature; adjacent padding; Queue layout; local PE route scan. | Yes. Raw/no-route remains a confidence cap but not a no-code blocker. |
| What is the best source-facing name? | Candidate symbol/string search; sibling accepted `WriteSlot`; behavior/call shape; rejected alternatives. | `Queue::ReadSlot(void *slot)` is the best supported inferred name/signature. |
| Should owner/emitter metadata change? | Queue class/file support docs, vtable/constructor layout, by-structure owner rule. | No. Keep direct class owner/emitter `0000BF`, position `40`. |
| Should C++ remain blank? | Current code-entry gate, exact body evidence, no-code alternatives. | No. Formal first-draft C++ should be inserted after supervisor approval. |
| Is exact original spelling proven? | MCP names/strings, type/struct searches, generated docs. | No. This remains a confidence cap; the emitted name is inferred. |

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `87/90`.
- Remaining uncertainty: active runtime reachability and exact original method spelling are still not proven. Final Queue header/source factoring is broader class/file work and should not block this child body.

## Changed Files In This Report-Only Pass

- Created: `tools/leaser/Agents/Agent-B013/research/0001FQ-QueueReadSlotRaw-source-quality.md`.
- Modified: none besides this report.
- Closeout scoped git status also showed modified `by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md`, `by-memory/0x005539e0-0x00553c07.Queue.md`, `by-class/Queue.md`, and `by-file/Queue.md` in the shared worktree; those by-* paths were not edited during this report-only pass.
- Target/support by-* docs edited: none.
- Generated/project-level files edited: none.
- Manual coverage reports edited: none.
- Validator/tool state edited: none.
- IDA DB edited: no.
- Leases taken: none; no lease is needed for report-only research in this agent folder.
- Validators run: none; validators are for the later implementation callback.
- `execute_report`: not run.
- Subagents spawned: none.

## Implementation Tracking Checklist

Implementation callback pass - checked after supervisor acceptance:

- [x] Supervisor validates this report and authorizes implementation for [UID:0001FQ]. Proof: `goal.md` assignment `B013-implement-0001FQ-QueueReadSlotRaw-source-quality-20260627` explicitly accepted this report and requested implementation.
- [x] Lease `by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md` only immediately before editing/validation. Proof: `python .\tools\leaser\leaser.py B013 lease ...` returned `Success` for the target immediately before the validator batch.
- [x] If support prose is edited in the same batch, lease `by-memory/0x005539e0-0x00553c07.Queue.md`, `by-class/Queue.md`, and `by-file/Queue.md` only immediately before editing/validation. Proof: the same B013 lease command returned `Success` for all three support docs.
- [x] Target metadata is changed to `COMPLETION:87`, `CONFIDENCE:90`. Proof: target header now contains `COMPLETION:87` and `CONFIDENCE:90`.
- [x] Target owner/emitter metadata remains `CANONICAL_OWNER:0000BF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BF`, `EMITTER_POSITION_OPTIONAL:40`. Proof: target header preserves those four values.
- [x] Target formal `RECONSTRUCTION_CPP CODE` block exactly contains the accepted `Queue::ReadSlot(void *slot)` C++ from this report and nothing outside the target range. Proof: target formal block contains only the accepted `Queue::ReadSlot(void *slot)` body; generated `auto-generated/NexusTK/util/Queue.cpp` also contains UID `0001FQ` with the same body.
- [x] Target text records current MCP session `b001_000241_20260627`, server health, IDB/input paths, and that no IDA DB edits were made. Proof: target `2026-06-27/2026-06-28 B013 accepted source-quality pass` evidence section records those details.
- [x] Target text records `lookup_funcs` not-a-function status for `0x00553b10`, decompile failure, exact raw disassembly, exact `0x45`/69-byte body, `c2 04 00` `retn 4`, eleven-byte pre/post padding, and unique range signature. Proof: target evidence and raw-bytes sections contain these facts.
- [x] Target text records `GetMemoryMan()->MemmoveWrapper(slot, m_buffer + m_readIndex * m_slotSize, m_slotSize)` as the source-facing copy-out path. Proof: target behavior/evidence/source-quality text and the formal C++ body record the copy-out path.
- [x] Target text records Queue layout support from constructor/write/read/empty evidence: `m_slotSize`, `m_slotCount`, `m_buffer`, `m_readIndex`, and `m_writeIndex`. Proof: target layout table and B013 evidence section record those field names and support.
- [x] Target text records no xrefs/callers, no modeled callees for the raw start, no VA/RVA pointer hits, no direct local PE `E8/E9` route, and positive vtable pointer controls. Proof: target B013 evidence section records all negative route checks plus the Queue vtable positive controls.
- [x] Target text records no recovered `ReadSlot`, `WriteSlot`, `IsEmpty`, `Enqueue`, or `Dequeue` source symbols and no local Queue UDT/type record. Proof: target B013 name/type search paragraph records the negative symbol/type results.
- [x] Target text rejects `QueueReadSlotRaw`, `Queue::Read`, `Queue::Pop`, `Queue::Dequeue`, `Queue::Get`, raw `sub_553B10`, no-code, metadata fallback, and owner/emitter fallback alternatives. Proof: target source-quality decision and change log record these rejected alternatives.
- [x] Queue aggregate support page is updated so [UID:0001FQ] is resolved to first-draft `Queue::ReadSlot(void *slot)` C++, while [UID:0001FR] remains unresolved. Proof: `by-memory/0x005539e0-0x00553c07.Queue.md` item summary, status/confidence caveat, functions row, reconstruction notes, score rationale, and change log now distinguish resolved [UID:0001FQ] from unresolved [UID:0001FR].
- [x] Queue class support page is updated so its raw-helper caveat distinguishes resolved [UID:0001FP]/[UID:0001FQ] from unresolved [UID:0001FR] and broader header/active-use work. Proof: `by-class/Queue.md` status, methods row, parent/score rationale, B013 evidence paragraph, and change log now record that distinction.
- [x] Queue file support page is updated so generated-output/source-family caveats reflect that [UID:0001FQ] contributes formal C++ through the Queue class route. Proof: `by-file/Queue.md` file role, proposed contents, source-structure decision, B013 evidence paragraph, and change log record the [UID:0001FQ] generated-output contribution and remaining file-level caveats.
- [x] No [UID:0001FP] or [UID:0001FR] child docs are edited unless the supervisor explicitly expands scope. Proof: only the target/support docs were in the callback scope; [UID:0001FP] and [UID:0001FR] child pages were not opened for edits.
- [x] No generated reports, project-level generated files, generated C++ files, manual `-coverage-report.md` files, validator/tool state, or IDA DB are manually edited. Proof: only by-* source docs and this report checklist were manually handled; generated/project-level/tool-state changes were validator-owned side effects, and no IDA DB edits were made.
- [x] Scoped validators listed in this report are run after the by-* edit batch with `--wait-generated`. Proof: all four validators exited `0` with `ok: 1` and `generated_refresh: completed`:
  - `python .\tools\validator.py --mode file --file by-memory\0x00553b10-0x00553b55.QueueReadSlotRaw.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004669`, `command_timestamp: 2026-06-27T22:36:43-04:00`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x005539e0-0x00553c07.Queue.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004670`, `command_timestamp: 2026-06-27T22:37:08-04:00`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-class\Queue.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004671`, `command_timestamp: 2026-06-27T22:37:22-04:00`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\Queue.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004672`, `command_timestamp: 2026-06-27T22:37:37-04:00`, `ok: 1`.
- [x] Generated output is checked after validators; `auto-generated/NexusTK/util/Queue.cpp` should show UID `0001FQ` with exact accepted `Queue::ReadSlot(void *slot)` body and equal/newer validator header metadata. Proof: generated header shows `validator-command-id: 000000004672` and `validator-refreshed-at: 2026-06-27T22:37:37-04:00`, equal to the final by-file validator and newer than the prior three; the file contains UID `0001FQ` with `Queue::ReadSlot(void *slot)` and `Completion:87 | Confidence:90`.
- [x] All leases taken for the implementation callback are released immediately after the edit/validator batch, and final lease state is reported. Proof: `python .\tools\leaser\leaser.py B013 unlease ...` returned `Success` for all four leased paths; `tools/leaser/Agents/Agent-B013/current_leases.md` readback shows no active B013 rows.

Validator side effects observed: the scoped validators refreshed validator-owned generated output/reports and projected stats, including `auto-generated/NexusTK/util/Queue.cpp`; they also repeated existing broad diagnostics such as `autogen_registry_stale` and `memory_coverage_metadata_missing_file` for unrelated missing registered files. No manual registry, generated report, generated C++, project-level, coverage-report, or IDA DB edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0001FQ-QueueReadSlotRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0001FQ-QueueReadSlotRaw-source-quality.md","timestamp":"2026-06-27T22:40:34","uid":"0001FQ"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001FQ-QueueReadSlotRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0001FQ-QueueReadSlotRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001FQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
