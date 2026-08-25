** TARGET-REPORT-UID:000188 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000188] AUTOBUFUnsignedCharResize Source-Quality Report

Agent: `Agent-B007`  
Assignment: `B007-report-000188-AUTOBUFUnsignedCharResize-source-quality-20260627`  
Mode: report-only research  
Target: `by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md`

## Report-Only Scope

No by-* documentation, generated C++ output, generated reports, coverage reports, validator/tool state, or IDA DB state was edited during this pass. No leases were acquired because this pass only creates the B007 research report in the assigned agent folder.

## Recommendation

Implement the target as a formal emitting method body. The current blank-C++ blocker is no longer justified for this child. Live IDA MCP confirms the exact function boundary, two callsites, callee pair, field offsets, return value, and padding fence; existing accepted AUTOBUF class/template evidence closes the concrete source type and field names.

Recommended target metadata:

| Field | Current | Recommended |
|---|---:|---:|
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `90` | `91` |
| `RECONSTRUCTABLE` | `TRUE` | unchanged |
| `CANONICAL_OWNER` | `00000P` | unchanged |
| `EMITTER_UIDS` | `00000P` | unchanged |

The confidence is capped at `91` rather than higher because the runtime symbols expose the allocation leg as the MSVC scalar `operator new(size_t)` thunk and the release leg as the CRT free-base thunk. The source-facing recommendation still uses high-level byte-array allocation/release because this is a concrete `_AUTOBUF<unsigned char>` storage buffer, the element type is trivial, the destructor uses the same free-base route for the same field, and existing project precedent for the same runtime allocation/free pair reconstructs source containers as array allocation/release rather than raw `unknown_libname_*` calls.

## Exact RECONSTRUCTION_CPP CODE

Insert this exact content in the target formal reconstruction block:

```cpp
template <>
unsigned char *_AUTOBUF<unsigned char>::Resize(unsigned int byteCount)
{
    delete [] m_data;

    unsigned char *data = new unsigned char[byteCount];
    m_count = byteCount;
    m_data = data;
    return data;
}
```

## Current Target State

Target page state before implementation:

| Property | Value |
|---|---|
| UID | `000188` |
| Range | `0x004e6ab0-0x004e6ad7` |
| Current summary | `_AUTOBUF<unsigned char>` resize helper; frees old pointer, allocates requested byte count, updates pointer/count; two callers in `UserLookPane` parsing |
| Current formal C++ | blank |
| Current stated blocker | full template/header contract and naming audit |
| Generated route | `000188 -> 00000P -> 0000HM -> auto-generated/NexusTK/util/AUTOBUF.cpp` |
| Generated output state | stale empty emitter marker for UID `000188`; generated metadata still shows older `78/88` even though the target header is `85/90` |

The target is above the active formal-code gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:00000P`, valid generated source route, and `(85 + 90) / 2 = 87.5`.

## IDA MCP Availability

IDA MCP was available and used. This is not a fallback-only report.

| Field | Value |
|---|---|
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp` version `1.0.0` |
| Protocol | `2025-06-18` |
| Active database | session `80de0a67` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module | `NexusTK.exe` |
| Input path | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Imagebase | `0x400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |
| Strings cache | ready |

Fresh 2026-06-27 JSON-RPC calls used `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `get_bytes`, and `callees` with no IDA-side mutation.

## Live IDA Evidence

Function boundary and neighboring range:

| Address | MCP result |
|---|---|
| `0x004e6ab0` | function `sub_4E6AB0`, size `0x27` |
| `0x004e6ad7` | not a function |
| `0x004e6ae0` | next function `sub_4E6AE0`, size `0x16c` |
| `0x004e62a0` | AUTOBUF deleting-destructor path, size `0x4b` |
| `0x005c7790` | `unknown_libname_19`, size `0x9` |
| `0x005c7799` | `j_j_j___free_base`, size `0x5` |

Boundary bytes: the first `0x27` bytes at `0x004e6ab0` decode as the method body, ending in `retn 4` at `0x004e6ad4`; `0x004e6ad7-0x004e6ae0` is nine `0xcc` bytes. This proves the target range is exact and not merged with the next function.

Decompile/disassembly behavior:

| Step | Binary evidence |
|---|---|
| `this` register | `ecx` is copied into `edi`; the method is a `__thiscall` instance method. |
| Old storage release | `push dword ptr [edi+4]` then call `j_j_j___free_base` at `0x004e6aba`. |
| Size argument | stack argument is loaded into `esi` from `[ebp+arg_0]`. |
| Allocation | `push esi` then call `unknown_libname_19` at `0x004e6ac3`; that thunk returns `operator new(size_t)` through `0x005c74f6`. |
| Store order | `m_count`/`+0x08` is assigned from `esi` at `0x004e6acb`, then `m_data`/`+0x04` is assigned from `eax` at `0x004e6ace`. |
| Return value | `eax` is preserved as the returned new pointer. |
| Stack cleanup | `add esp, 8` after both cdecl helper calls; method returns with `retn 4`. |

Callee set is exactly the runtime free-base thunk and runtime operator-new thunk:

| Callee | Meaning for source reconstruction |
|---|---|
| `0x005c7799 j_j_j___free_base` | CRT free-base thunk; also used by the AUTOBUF destructor for the same `+0x04` storage field. |
| `0x005c7790 unknown_libname_19` | MSVC runtime allocation thunk; Hex-Rays renders it as returning `operator new(a1)`. |

The method does not call project `MemoryMan` wrappers `0x004f4aa0`/`0x004f4ac0` and does not call `MemoryMan::AllocateBufferMemory`/`MemoryMan::FreeBufferMemory` at `0x00516050`/`0x00516170`. Do not reconstruct this method with `MemoryMan`.

Inbound xrefs:

| Caller | Context |
|---|---|
| `0x0059ffc1` in `sub_59F610` | `UserLookPane` profile/look parser; `ecx = esi + 0x0b8c`, size from word at `esi + 0x0b88`; immediately copies source bytes to `dword ptr [esi+0x0b90]` with `_memmove` and calls image/decode logic. |
| `0x0059fffe` in `sub_59F610` | Same parser branch after the `"JPF"` check; same size source and same destination pointer at `esi + 0x0b90`, then calls `sub_516220` and image/path validation. |

The xref query returns exactly two code refs and `more:false`. These are consumers, not ownership evidence for moving the method into `UserLookPane`.

Destructor corroboration:

| Address | Evidence |
|---|---|
| `0x004e62a0` | AUTOBUF deleting-destructor path writes vtable `??_7?$_AUTOBUF@E@@6B@`, frees `Block[1]`/`+0x04` through `j_j_j___free_base`, calls base teardown, and only then optionally releases the object itself through the project delete wrapper. |

This closes the field role: `+0x04` is the owned byte-buffer pointer and `+0x08` is the byte count. It also supports source-level release syntax for the owned array/buffer, not a caller-owned or borrowed pointer.

## Source-Quality Blocker Resolution

### Type and method name

Use `_AUTOBUF<unsigned char>::Resize`. The concrete `_AUTOBUF<unsigned char>` spelling is backed by the decorated vtable and RTTI symbols `??_7?$_AUTOBUF@E@@6B@` and `??_R4?$_AUTOBUF@E@@6B@`, the accepted AUTOBUF constructor target, and the current by-class/by-template docs. The undecorated `AUTOBUF<unsigned char>` spelling is a page/file shorthand, not the exact source type for this method.

Reject these alternatives for the target formal C++: `AUTOBUF<unsigned char>`, `AutoBuf`, `AutoBuffer`, `class_AUTOBUF_unsigned_char`, a `UserLookPane` method, and a free function wrapper. They are weaker than the decorated symbol and class/template evidence.

### Field names and layout

Use `m_data` for offset `+0x04` and `m_count` for offset `+0x08`. B004's accepted AUTOBUF pass already closed these names from the constructor, vtable, and destructor evidence; this pass independently rechecked that resize writes exactly those two offsets and that caller code reads the embedded object's `+0x04` destination pointer after the resize call.

Reject `m_buffer`, `m_byteCount`, `m_capacity`, and IDA-style names. No capacity field exists in this concrete three-field layout; the method stores the requested byte count directly to `+0x08`.

### Signature and return type

Use `unsigned char *Resize(unsigned int byteCount)`. Evidence:

- The method returns the allocator result in `eax`.
- The stored pointer is used as a byte destination by `_memmove`/decode consumers.
- The argument is a 32-bit byte count; the caller zero-extends a 16-bit packet length before passing it.
- The body returns a pointer, not `void` or `bool`.

`uint32_t` is acceptable in prose for the storage semantics, but the formal block should use `unsigned int` to avoid adding a new include dependency and to match the plain C++ style used by nearby reconstructed code.

### Allocator and release source shape

Use high-level byte-array storage in the formal block: `delete [] m_data` followed by `new unsigned char[byteCount]`.

Reasoning:

- The binary releases existing `m_data` before allocation and does not guard null or zero-size cases.
- The allocation callee is the MSVC runtime operator-new thunk, not the project `MemoryMan` allocator.
- The element type is `unsigned char`, so no element constructors/destructors or array-cookie behavior are required for the payload itself.
- Existing accepted project precedent for a same-pattern runtime allocation/free resize helper reconstructs source containers as source-level array allocation/release rather than calling runtime thunk names.
- Naming the runtime thunk or free-base helper in source would leak compiler/runtime artifacts into a utility template method and would be less plausible original source than the high-level array syntax.

Retain the confidence cap because MCP symbol searches did not expose a separate recovered `operator new[]` / `operator delete[]` symbol for this exact trivial-byte case. That caveat affects confidence, not code readiness.

### Ownership and source placement

Keep `CANONICAL_OWNER:00000P` and `EMITTER_UIDS:00000P`. The method is a concrete child of `_AUTOBUF<unsigned char>` and emits through the AUTOBUF class/page into `by-file/AUTOBUF.md` / `auto-generated/NexusTK/util/AUTOBUF.cpp`. The two parser callsites only prove use from `UserLookPane`; they do not override the template utility owner. Vtable xrefs are broad across image, startup media, map/look/profile, and utility contexts, which rejects a pane-local owner.

## Support Documentation To Update If Accepted

### Target: `by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md`

Apply these target-level changes:

- Raise `COMPLETION` to `90` and `CONFIDENCE` to `91`.
- Insert the exact formal C++ block from this report.
- Replace the stale blank-C++ blocker with the resolved source-quality decision: exact `_AUTOBUF<unsigned char>` type, `m_data`/`m_count` fields, pointer-returning `Resize(unsigned int byteCount)` signature, runtime operator-new/free lowering, and no `MemoryMan` route.
- Update the function row to `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount)` and state that it returns the new `unsigned char *`.
- Add live MCP proof: session `80de0a67`, function size `0x27`, nine-byte `0xcc` fence to `0x004e6ae0`, callee set, two xrefs, caller embedded-object offsets, and destructor corroboration.
- Add rejected alternatives: no split/merge, no UserLookPane ownership, no MemoryMan, no capacity field, no blank formal C++.
- Add a change-log entry for the accepted report.

### Support: `by-class/AUTOBUF_unsigned_char.md`

Apply these support-level changes:

- Update the resize method row to show formal code is now ready for the concrete child and signature `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount) -> unsigned char *`.
- Record that `m_data`/`m_count` were reconfirmed by resize stores and destructor release.
- Keep the aggregate class declaration/formal block blank if the broader generic template/header/destructor questions remain open; do not let that aggregate caveat suppress the child method's formal C++.
- Recommended score movement: `COMPLETION 87 -> 88`, `CONFIDENCE 91 -> 92`, because the two concrete `_AUTOBUF<unsigned char>` method children now have formal code and the field contract has fresh caller/destructor proof.

### Support: `by-type/by-template/AUTOBUF_unsigned_char.md`

Apply these support-level changes:

- Mark the concrete resize API as resolved: pointer-returning `Resize(unsigned int byteCount)`, release old `m_data`, allocate `byteCount` bytes, update `m_count` then `m_data`.
- Keep the wider template declaration/header caveat local to the aggregate/template page; it is no longer a blocker for UID `000188`.
- Recommended score movement: `COMPLETION 87 -> 88`, `CONFIDENCE 91 -> 92`, for the concrete instantiation evidence.

### Support: `by-file/AUTOBUF.md`

Apply these support-level changes:

- Add the live UID `000188` source-shape evidence under the resize/helper method discussion: exact range, two UserLookPane parser callsites, runtime operator-new/free-base lowering, no MemoryMan, destructor same-field release, and formal high-level array allocation/release decision.
- Update generated-output expectation: after validators with `--wait-generated`, `auto-generated/NexusTK/util/AUTOBUF.cpp` should contain both the accepted constructor [UID:00019E] and the resize block [UID:000188], and should no longer show an empty emitter marker for UID `000188`.
- Recommended score movement: `COMPLETION 87 -> 88`, `CONFIDENCE 90 -> 91`.

### Support Already Sufficient

No required edit is needed to `by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md`; it already contains the accepted constructor formal C++ and the same concrete type spelling.

No required edit is needed to `by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md`; it already records the vtable/RTTI data that supports the concrete `_AUTOBUF<unsigned char>` identity. If the implementation callback chooses to add a cross-reference note there, keep it informational and do not change its no-code disposition.

Do not edit generated `auto-generated/NexusTK/util/AUTOBUF.cpp` or `auto-generated/-ag-*` files manually. Refresh them only through validators after source docs are updated.

## Negative Evidence And Rejected Paths

- No split or range repair is needed. The modeled function is exactly `0x27` bytes and the next nine bytes are padding before the next function.
- No extra callers were found beyond `0x0059ffc1` and `0x0059fffe`.
- No data xref/vtable evidence supports moving this method under `UserLookPane`; the parser callsites are consumers of an embedded AUTOBUF member.
- No `MemoryMan` allocator/free path participates in this method.
- No `capacity` field participates in the concrete layout. The method updates only the pointer and count fields after the inherited/vtable slot.
- No formal C++ blanking remains necessary for this child. The wider aggregate/template declaration can stay conservative without blocking the method body.
- No IDA-side names, types, comments, or database state were changed.

## Validator Plan For Implementation Callback

After accepted by-* edits, run scoped validators with generated output current. Required commands:

- `python .\tools\validator.py --mode file --file by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-class/AUTOBUF_unsigned_char.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-type/by-template/AUTOBUF_unsigned_char.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-file/AUTOBUF.md --apply --queue-timeout 240 --wait-generated`

Implementation should record each validator exit code, `command_id`, `command_timestamp`, and `ok` count, then compare generated `auto-generated/NexusTK/util/AUTOBUF.cpp` headers against the latest validator metadata to prove the resize block regenerated.

## Implementation Tracking Checklist

Checked during implementation callback `B007-implement-000188-AUTOBUFUnsignedCharResize-source-quality-20260627`:

- [x] Lease only the immediate implementation files, then update `by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md` with metadata `90/91`, exact formal C++ block, resolved source-quality notes, function row/signature, MCP evidence, rejected alternatives, and change log.
  - Proof: B007 leased the four editable by-* files before editing. Target header is now `COMPLETION:90`, `CONFIDENCE:91`, with owner `00000P`, emitter `00000P`, reconstructable `TRUE`, and blank emitter position unchanged. The formal block now contains the accepted `template <> unsigned char *_AUTOBUF<unsigned char>::Resize(unsigned int byteCount)` body. The target page records session `80de0a67`, `0x27` size, nine-byte `0xcc` fence, callee set, two `UserLookPane` parser callsites, `m_data`/`m_count`, returned pointer, destructor same-field release, no `MemoryMan`, and rejected split/UserLookPane/capacity/raw-thunk/blank-C++ alternatives.
- [x] Update `by-class/AUTOBUF_unsigned_char.md` with the accepted resize method signature/body decision, field proof, aggregate-C++ caveat separation, and recommended score movement to `88/92` if accepted by supervisor.
  - Proof: class header is now `88/92`. The method row names `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount) -> unsigned char *` and links UID `000188` as formal first-draft C++. A new B007 section records the `0x27` range, nine-byte padding, runtime operator-new/free-base lowering, no `MemoryMan`, two parser callsites, destructor same-field release, accepted field proof, rejected alternatives, and explicitly separates the aggregate class no-code caveat from child constructor/resize emission.
- [x] Update `by-type/by-template/AUTOBUF_unsigned_char.md` with the concrete resize API/return/storage decision, aggregate-template caveat separation, and recommended score movement to `88/92` if accepted by supervisor.
  - Proof: type/template header is now `88/92`. The instantiation evidence row and B007 source-shape section record `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount) -> unsigned char *`, release old `m_data`, allocate `new unsigned char[byteCount]`, update `m_count` then `m_data`, return the new pointer, no `MemoryMan`, and rejected UserLookPane/raw-thunk/capacity/split/blank-C++ alternatives. The reconstruction notes say constructor and resize children emit while the aggregate remains blank pending the generic declaration/destructor/header pass.
- [x] Update `by-file/AUTOBUF.md` with UID `000188` source-shape evidence, allocator/free route, no-`MemoryMan` note, generated-output expectation for `AUTOBUF.cpp`, and recommended score movement to `88/91` if accepted by supervisor.
  - Proof: file header is now `88/91`. The known-code row for `0x004e6ab0-0x004e6ad7` now names the formal resize signature and source shape. The source-structure/live-evidence sections record runtime `operator new(size_t)` / free-base lowering, no `MemoryMan`, two `UserLookPane` parser consumers, destructor same-field release, rejected alternatives, and generated-output expectation that `AUTOBUF.cpp` contains both UID `000188` resize and UID `00019E` constructor blocks.
- [x] Confirm constructor and vtable by-memory support pages already contain same-or-greater supporting facts, or add only narrow cross-reference notes if the supervisor explicitly wants them.
  - Proof: no edits needed. `by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md` already contains formal constructor C++, `_AUTOBUF<unsigned char>` spelling, `m_data`/`m_count`, B004 session `80de0a67`, and ownership/emitter proof. `by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md` already records the decorated RTTI/vtable names, 21 xrefs, source-declared/generated-binary rebuild handling, and a strict blank-C++ no-code proof.
- [x] Run all scoped validators listed above with `--wait-generated`; record exit code, `command_id`, `command_timestamp`, and `ok` count for each.
  - Proof:
    - `python .\tools\validator.py --mode file --file by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md --apply --queue-timeout 240 --wait-generated` from `source-3/project-documentation`: exit `0`, `command_id:000000004101`, `command_timestamp:2026-06-27T10:28:04-04:00`, `ok:1`, `generated_refresh:completed`.
    - `python .\tools\validator.py --mode file --file by-class/AUTOBUF_unsigned_char.md --apply --queue-timeout 240 --wait-generated`: exit `0`, `command_id:000000004103`, `command_timestamp:2026-06-27T10:28:32-04:00`, `ok:1`, `generated_refresh:completed`.
    - `python .\tools\validator.py --mode file --file by-type/by-template/AUTOBUF_unsigned_char.md --apply --queue-timeout 240 --wait-generated`: exit `0`, `command_id:000000004104`, `command_timestamp:2026-06-27T10:28:53-04:00`, `ok:1`, `generated_refresh:completed`.
    - `python .\tools\validator.py --mode file --file by-file/AUTOBUF.md --apply --queue-timeout 240 --wait-generated`: exit `0`, `command_id:000000004105`, `command_timestamp:2026-06-27T10:29:08-04:00`, `ok:1`, `generated_refresh:completed`.
  - Validator notes: all four scoped runs passed. They also reported broad pre-existing `autogen_registry_stale` / `memory_coverage_metadata_missing_file` diagnostics and, on the by-file run, pre-existing `missing_ref_uid 0003OY` references already present in `by-file/AUTOBUF.md`; these were not created by this B007 edit and are outside the accepted UID `000188` callback.
- [x] Inspect generated `auto-generated/NexusTK/util/AUTOBUF.cpp` after validators and record that UID `000188` now emits the accepted resize block and no longer has an empty emitter marker.
  - Proof: generated header is `validator-command-id: 000000004105`, `validator-refreshed-at: 2026-06-27T10:29:08-04:00`, equal to the latest by-file validator command. The file contains UID `000188` with `Completion:90 | Confidence:91` and the accepted `_AUTOBUF<unsigned char>::Resize(unsigned int byteCount)` block. UID `000188` is not an empty emitter marker. The file also contains UID `00019E` constructor C++; remaining empty markers are aggregate/source-declared support items (`00000P`, `0002MR`, `0001WN`) as expected.
- [x] Do not manually edit generated C++, generated reports, project-level generated files, coverage reports, validator/tool state, or IDA DB.
  - Proof: manual edits were limited to the four by-* docs and this B007 report checklist. Generated/project-level/validator-owned files were changed only by scoped validator commands with `--wait-generated`; no IDA MCP write tools or IDA DB edits were used.
- [x] Release all implementation leases immediately after the edit/validator batch and record release/expiry proof in the callback result.
  - Proof: B007 released all four by-* leases with `python .\leaser.py B007 unlease ...` after the validators completed. `tools/leaser/Agents/current_leases.md` was checked afterward and contains no active B007 entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/000188-AUTOBUFUnsignedCharResize-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/000188-AUTOBUFUnsignedCharResize-source-quality.md","timestamp":"2026-06-27T10:38:05","uid":"000188"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
