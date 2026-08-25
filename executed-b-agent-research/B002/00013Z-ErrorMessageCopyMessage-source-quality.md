** TARGET-REPORT-UID:00013Z **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00013Z ErrorMessageCopyMessage Source-Quality Report

Status: FINISHED_IMPLEMENTATION_COMPLETE

## Assignment

- Agent: `Agent-B002`.
- Report assignment ID: `B002-report-error-message-copy-message-source-quality-00013Z-mcp-20260623`.
- Implementation callback ID: `B002-implement-error-message-copy-message-source-quality-00013Z-mcp-20260623`.
- Target: [UID:00013Z] `by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md`.
- Starting metadata: `COMPLETION:84`, `CONFIDENCE:91`, `CANONICAL_OWNER:00004K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004K`, blank formal C++.
- Required output: accepted MCP-backed source-quality implementation into target/support by-* docs, with report checklist proof.
- Report path: `tools/leaser/Agents/Agent-B002/research/00013Z-ErrorMessageCopyMessage-source-quality.md`.
- Files edited manually in implementation: [UID:00013Z] target, six support by-* docs, and this report checklist. No `-coverage-report.md`, IDA database state, or tool-state files were edited manually. Validator `--apply` produced the side effects recorded in the Validators section.

## Recommendation Summary

Raise [UID:00013Z] from `84/91` to `86/92`, keep `CANONICAL_OWNER:00004K`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00004K`, keep `EMITTER_POSITION_OPTIONAL` blank, and keep formal `RECONSTRUCTION_CPP` blank.

Implementation callback completed: the accepted target/support-doc facts from this report were applied at report-level detail, the target now carries `86/92`, formal C++ remains blank for the shared-interface standardization reason, scoped validators passed for every changed by-* doc, and B002 leases were released after the edit/validator batch.

The current MCP session proves this is an exact `0x19` / 25-byte vtable-selected `ErrorMessage` message-output helper. It has a one-block `_wcscpy_s` body, copies from the `ErrorMessage` inline wide buffer at byte offset `+0x04`, is pointed to by the `ErrorMessage` vtable slot at `0x006193c8`, and has no direct code callers. The no-direct-caller state is not a liveness blocker because this is a virtual slot body and the only direct data pointer to the function VA is the vtable slot.

Do not enter first-draft formal C++ yet. The body itself is source-reconstructable, but the final source-facing virtual method name and return spelling must be standardized across the whole Error hierarchy. Current MCP evidence shows the same `+0x0c` virtual slot family returns `int` for status-code formatters and `errno_t` for stored-message copy helpers. Those are ABI-compatible integer returns, but they do not prove whether final source should spell the interface as `int`, `errno_t`, or an existing project typedef. Use this page as exact method evidence; emit source later through the standardized `Error.h` / `Error.cpp` interface or a follow-up exact-child C++ pass.

## MCP Session And Health

MCP was available and used as the authoritative evidence source for this pass.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Session used: `b880584f`.
- `server_health`: `status=ok`, module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, strings cache size `2067`.
- `idb_list`: one active owned/adopted worker session, `session_id=b880584f`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active database session for this report.
- Tool schema checked through `tools/list`; target evidence used `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, `get_int`, `find_bytes`, `list_globals`, and `int_convert`.
- No MCP timeout, stale-session, connection-refused, or endpoint-unavailable condition occurred during the successful evidence pass.

## Evidence Checked

Project and workflow inputs:

- `tools/leaser/Agents/Agent-B002/goal.md`.
- `ntk-b-agent-workflow` skill and required B-agent workflow references.
- Target page [UID:00013Z] `by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md`.

Support docs checked:

- [UID:00013X] `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`.
- [UID:00004K] `by-class/ErrorMessage.md`.
- [UID:0000J5] `by-file/Error.md`.
- [UID:0001XI] `by-type/by-vtable/ErrorHierarchyVtables.md`.
- [UID:0001UE] `by-type/by-struct/ErrorObjectLayouts.md`.
- [UID:0002ND] `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`.
- Sibling exact helpers [UID:00013Y] `ErrorBaseCleanupHelper`, [UID:000140] `FileErrorCopyMessage`, and [UID:0002TV] `ErrorDestructorAndNameHelpers`.
- Current `by-memory/-coverage-report.md` row for [UID:00013Z] and generated `auto-generated/NexusTK/util/Error.cpp` marker output.

Leads checked but not accepted blindly:

- Older B003 queue entry for [UID:00013Z]: no `Agent-B003/research/00013Z-ErrorMessageCopyMessage-source-quality.md` report is present on disk.
- Archived B013 report `00013X-ErrorWrappers-source-quality.md`: used only as a hypothesis list because it explicitly recorded MCP unavailability and local PE/Capstone fallback evidence.
- Archived B002 report `0002TV-error-destructor-name-helpers-source-quality.md`: used as a support lead, then revalidated the `ErrorMessage` destructor size immediate through current MCP session `b880584f`.
- `source-3/simroot_v2/class_ErrorMessage.cpp`: generated output omits this copy helper and therefore is not source completeness proof.

Conversion checks:

- `python .\tools\int_convert.py 0x19` confirmed `0x19 = 25`.
- `python .\tools\int_convert.py 0x204` confirmed `0x204 = 516`.
- `python .\tools\int_convert.py 0x200` confirmed `0x200 = 512`.
- `python .\tools\int_convert.py 0x04` confirmed `0x04 = 4`.

## Current Target State

[UID:00013Z] is already correctly classified as reconstructable project code and already attached to [UID:00004K] `ErrorMessage`. The page's old core claims are mostly correct, but they need current MCP-backed provenance and a stronger source-signature/no-code rationale.

The current target page says:

- Exact range: `0x004a6410-0x004a6429`.
- IDA name: `sub_4A6410`.
- Behavior: copy inline wide-message storage from byte offset `+0x04` into caller buffer with `_wcscpy_s`.
- Direct vtable route: `0x006193c8 -> 0x004a6410`.
- No direct code callers.
- C++ blank because final virtual method name/signature needs hierarchy reconciliation.

Current MCP session `b880584f` confirms those facts and adds stronger pointer-route, raw-constructor, sibling-return, and current-session support.

## MCP Function And Range Facts

`lookup_funcs` results from session `b880584f`:

| Query | Result |
| --- | --- |
| `0x004a63e0` | Not a function. |
| `0x004a63fc` | Not a function. |
| `0x004a6400` | `sub_4A6400`, size `0x0b`. |
| `0x004a640b` | Not a function. |
| `0x004a6410` | `sub_4A6410`, size `0x19`. |
| `0x004a6429` | Not a function. |
| `0x004a6430` | `sub_4A6430`, size `0x3f`. |
| `0x004a6480` | `sub_4A6480`, size `0x19`. |
| `0x004a6920` | `sub_4A6920`, size `0x41`. |
| `0x004a6a70` | `sub_4A6A70`, size `0x6`. |
| `0x005ca28c` | `__purecall`, size `0x1b`. |
| `_wcscpy_s` | `_wcscpy_s`, address `0x005cd657`, size `0x64`. |

The target's exact half-open range is `0x004a6410-0x004a6429`. The next function begins at `0x004a6430`, and `0x004a6429-0x004a6430` is `0xcc` alignment padding.

## Bytes, Disassembly, And Decompilation

`get_bytes 0x004a6410 size 25` returns:

```text
55 8b ec 8d 41 04 50 ff 75 0c ff 75 08 e8 35 72 12 00 83 c4 0c 5d c2 08 00
```

Current MCP disassembly:

```asm
4a6410  push ebp
4a6411  mov ebp, esp
4a6413  lea eax, [ecx+4]
4a6416  push eax
4a6417  push [ebp+SizeInWords]
4a641a  push [ebp+Destination]
4a641d  call _wcscpy_s
4a6422  add esp, 0Ch
4a6425  pop ebp
4a6426  retn 8
```

Current MCP decompilation:

```c
errno_t __thiscall sub_4A6410(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)
{
  return wcscpy_s(Destination, SizeInWords, this + 2);
}
```

The `this + 2` expression is in `wchar_t *` units, so the byte offset is `+0x04`. The assembly confirms this as `lea eax, [ecx+4]`.

Padding and neighbor bytes:

- `get_bytes 0x004a6400 size 48` shows `sub_4A6400` bytes, five `0xcc` bytes at `0x004a640b-0x004a6410`, then the target body.
- `get_bytes 0x004a6429 size 7` returns seven `0xcc` bytes before the next function at `0x004a6430`.
- `get_bytes 0x004a63e0 size 32` shows the raw constructor-shaped body ending in `c3` followed by four `0xcc` bytes before `0x004a6400`.

## Caller, Callee, Vtable, And Pointer Routes

Direct callee evidence:

- `callees 0x004a6410` reports only `_wcscpy_s` at `0x005cd657`.
- `analyze_function 0x004a6410` reports one basic block, cyclomatic complexity 1, no strings, no constants, and no callers.

Direct caller evidence:

- `analyze_function 0x004a6410` reports `callers=[]`.
- `xrefs_to 0x004a6410` reports exactly one xref: data ref at `0x006193c8`.
- There are no direct code xrefs to the target start. This is expected for a vtable-only virtual helper and is not a dead-code proof.

Vtable evidence:

- `get_bytes 0x006193b8 size 24` returns:

```text
10 6d 64 00 20 69 4a 00 10 4b 4f 00 c0 b6 41 00 10 64 4a 00 70 6a 4a 00
```

Decoded as little-endian dwords:

| Address | Value | Role |
| --- | --- | --- |
| `0x006193b8` | `0x00646d10` | `ErrorMessage` RTTI/COL pointer. |
| `0x006193bc` | `0x004a6920` | `ErrorMessage` scalar deleting destructor slot. |
| `0x006193c0` | `0x004f4b10` | Inherited runtime/LObject slot. |
| `0x006193c4` | `0x0041b6c0` | No-op slot. |
| `0x006193c8` | `0x004a6410` | Message output slot, this target. |
| `0x006193cc` | `0x004a6a70` | Common name helper slot. |
| `0x006193d0` | `0x00646d60` | Successor `FileError` RTTI/COL pointer. |

Constructor/table route:

- `list_globals '*ErrorMessage*'` names `??_7ErrorMessage@@6B@` at `0x006193bc` and `??_R4ErrorMessage@@6B@` at `0x00646d10`.
- `xrefs_to 0x006193bc` reports the raw constructor-shaped vtable store at `0x004a63ef`.
- `disasm 0x004a63e0` confirms there is no IDA function wrapper there, but the bytes call `sub_4F4A80` and then execute `mov dword ptr [esi], offset ??_7ErrorMessage@@6B@` at `0x004a63ef`.
- `decompile 0x004a63e0` fails with "Decompilation failed at 0x4a63e0", matching the no-function status.
- `xrefs_to 0x004a63e0` reports no xrefs.

Pointer and table search evidence:

| Pattern | Meaning | MCP result |
| --- | --- | --- |
| `10 64 4A 00` | VA pointer to `0x004a6410` | One match at `0x006193c8`. |
| `10 64 0A 00` | RVA-style pointer to target | No matches. |
| `E0 63 4A 00` | VA pointer to raw constructor start `0x004a63e0` | No matches. |
| `E0 63 0A 00` | RVA-style pointer to raw constructor start | No matches. |
| `BC 93 61 00` | Vtable-base immediate `0x006193bc` | One match at `0x004a63f1`, inside the raw constructor-shaped store. |
| `C8 93 61 00` | Slot-address immediate `0x006193c8` | No matches. |

This proves the only raw pointer route to the target function start is the vtable slot itself. The vtable base is installed by the raw constructor-shaped code, but the slot address is not separately referenced.

## Layout And Field Roles

The target body proves the source buffer starts at byte offset `+0x04` from `this`. The current MCP destructor check for `sub_4A6920` proves this is the `ErrorMessage` scalar deleting destructor selected by the same vtable and contains the object-size immediate `0x204`.

`0x204` equals 516 bytes. Subtracting the 4-byte vtable pointer leaves `0x200` / 512 bytes of inline payload. For a wide-character message buffer, `0x200` bytes is `256` `wchar_t` elements. Therefore the best current layout remains:

```cpp
class ErrorMessage : public Error {
    wchar_t m_message[256]; // byte offset +0x04
};
```

This report does not recover the original member name. `m_message` is a descriptive documentation name already used by the support docs and is preferable to untyped byte arrays or generated overlay names.

## Hierarchy-Wide Slot Reanalysis

The target is one implementation of the Error hierarchy vtable `+0x0c` message-output slot. Current MCP `analyze_function` on sibling slot targets shows two behavior families:

| Slot target | Class/family | MCP prototype | Vtable xref |
| --- | --- | --- | --- |
| `0x004a6100` | `Win32Error` formatter | `int __thiscall(_DWORD *this, wchar_t *Buffer, size_t BufferCount)` | `0x00619368` |
| `0x004a61e0` | `DIError` formatter | `int __thiscall(_DWORD *this, wchar_t *Buffer, size_t BufferCount)` | `0x00619380` |
| `0x004a6290` | `DDError` formatter | `int __thiscall(_DWORD *this, wchar_t *Buffer, size_t BufferCount)` | `0x00619398` |
| `0x004a6360` | `DSError` formatter | `int __thiscall(_DWORD *this, wchar_t *Buffer, size_t BufferCount)` | `0x006193b0` |
| `0x004a6410` | `ErrorMessage` copy helper | `errno_t __thiscall(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)` | `0x006193c8` |
| `0x004a6480` | `FileError` copy helper | `errno_t __thiscall(const wchar_t *this, wchar_t *Destination, rsize_t SizeInWords)` | `0x006193e0` |
| `0x004a64d0` | `WSAError` formatter | `int __thiscall(_DWORD *this, wchar_t *Buffer, size_t BufferCount)` | `0x006193f8` |
| `0x004a6670` | `InternetError` stored-message helper | `errno_t __thiscall(int this, wchar_t *Destination, rsize_t SizeInWords)` | `0x00619410` |
| `0x004a6780` | `InternetConnectionError` stored-message helper | `errno_t __thiscall(int this, wchar_t *Destination, rsize_t SizeInWords)` | `0x00619428` |
| `0x004a6840` | `MyError` / `PasswordError` heap-message helper | `errno_t __thiscall(const wchar_t **this, wchar_t *Destination, rsize_t SizeInWords)` | `0x006125b4`, `0x00619440` |

This rejects a target-local final source declaration such as `errno_t ErrorMessage::CopyMessage(...)` as too narrow. The exact helper returns the `_wcscpy_s` status, so `errno_t` is accurate for the local decompiler type. The hierarchy-wide virtual slot, however, also contains formatter bodies returning `int` from formatting wrappers. The source interface should be standardized once across `Error.h`; `int FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` is the lowest-friction common ABI/source shape, while `CopyErrorMessage` remains an acceptable naming alternative if the supervisor standardizes it across every `+0x0c` slot.

Do not erase the return value as `void` in this target. The binary returns `eax` from `_wcscpy_s`, and sibling formatters also preserve integer results. A later final-source pass may ignore that return at call sites, but current MCP does not prove a `void` declaration.

## Positive Evidence Summary

- MCP session `b880584f` is live and tied to the correct IDB.
- `lookup_funcs` proves a real function at `0x004a6410`, size `0x19`, with exact end at `0x004a6429`.
- `get_bytes`, `disasm`, and `decompile` agree on a one-block `_wcscpy_s` helper.
- The source pointer is `[ecx+4]`, proving inline wide-message storage starts at byte offset `+0x04`.
- `xrefs_to 0x004a6410` reports the vtable data reference at `0x006193c8`.
- `get_int`/`get_bytes` decode the `ErrorMessage` vtable base at `0x006193bc` with the message slot at `+0x0c`.
- `xrefs_to 0x006193bc` reports the raw constructor-shaped vtable store at `0x004a63ef`.
- `find_bytes` finds the target VA only at `0x006193c8`; the RVA pattern is absent.
- The same vtable selects `0x004a6920` as `ErrorMessage` scalar deleting destructor; current disassembly shows object-size immediate `0x204`, supporting `wchar_t[256]` after the vptr.
- Support docs [UID:00013X], [UID:00004K], [UID:0001XI], [UID:0001UE], and [UID:0002ND] already align on the owner/source family and only need current-MCP/provenance/signature refinement.

## Negative Evidence Summary

- No direct code callers were found for `0x004a6410`.
- `xrefs_to 0x006193c8` reports no references to the slot address itself.
- `find_bytes 10 64 0A 00` found no RVA-style target pointer.
- `lookup_funcs 0x004a63e0` reports no IDA function at the raw `ErrorMessage` constructor-shaped start.
- `decompile 0x004a63e0` fails because it is not an IDA-modeled function.
- `xrefs_to 0x004a63e0` and `find_bytes` for its VA/RVA pointer patterns find no route to the raw constructor start.
- Generated `class_ErrorMessage.cpp` omits `0x004a6410`, so generated output is incomplete for this class.
- No source symbol, string, direct caller, or class declaration text recovers the original name of the `+0x0c` virtual.
- Sibling slot targets disagree in decompiler return spelling (`int` for formatters, `errno_t` for copy helpers), so the final source return spelling remains unresolved.

## Heuristic And Inference Ledger

| Claim | Evidence | Status |
| --- | --- | --- |
| This is live project code, not padding or runtime glue. | IDA function object, executable bytes, vtable data xref, project-owned `ErrorMessage` vtable. | Accepted. |
| Canonical owner should remain [UID:00004K] `ErrorMessage`. | Vtable base is `??_7ErrorMessage@@6B@`; slot belongs to the concrete class table; direct class and file parents clear route gates. | Accepted. |
| Source file route is [UID:0000J5] `Error` / `util/Error.cpp`. | Error hierarchy file and aggregate docs own the compact error wrapper cluster; generated autogen route already points to `auto-generated/NexusTK/util/Error.cpp`. | Accepted. |
| The helper copies from `+0x04`. | `lea eax, [ecx+4]`; decompiler `this + 2` in `wchar_t *` units. | Accepted. |
| `ErrorMessage` inline buffer is `wchar_t[256]`. | Same vtable destructor slot at `0x004a6920`; disassembly has object-size immediate `0x204`; vptr is 4 bytes; payload `0x200` bytes equals 256 wide chars. | Accepted as best current layout. |
| No direct callers means the helper is dead. | Direct callers are absent, but vtable slot pointer is present and raw constructor stores the vtable base. | Rejected. |
| The final virtual method should be uniquely named `CopyMessage`. | The target filename is descriptive; support docs show a shared `+0x0c` message-output slot with formatter and copy implementations. | Rejected as final source spelling. |
| The final return type should be target-local `errno_t`. | Local helper returns `_wcscpy_s`, but sibling formatter slots return `int`. | Cap; use hierarchy-wide integer interface decision. |
| Formal C++ should be emitted now. | Body is exact, but the shared Error hierarchy `+0x0c` source name/return convention is not final. The blank-C++ decision is based on interface standardization, not on a score-threshold blocker. | Rejected for this pass. |

## Rejected Alternatives

- `CANONICAL_OWNER:0000J5`: correct source file route, but too broad for this exact concrete virtual method. Keep [UID:00004K] as canonical owner and use [UID:0000J5] through the class/file route.
- `CANONICAL_OWNER:00013X`: `ErrorWrappers` is the aggregate context, not the exact class owner.
- `CANONICAL_OWNER:0001XI` or `0002ND`: vtable/type-data pages are support evidence and generated-binary rebuild context, not source method owners.
- `CANONICAL_OWNER:0001UE`: layout support page, not method implementation owner.
- Treating the helper as padding or generated-only ignored code: rejected by a real IDA function object and vtable pointer.
- Treating it as directly caller-owned by a consumer subsystem: rejected; there are no direct code callers, and the only route is the ErrorMessage vtable.
- Emitting an isolated `ErrorMessage::CopyMessage` method name: rejected until the project standardizes `FormatErrorMessage`, `CopyErrorMessage`, or another recovered source spelling across the hierarchy.
- Emitting `void`: rejected because MCP shows the function returns the `_wcscpy_s` value in `eax`, and sibling slot bodies also preserve integer return values.
- Relying on generated `class_ErrorMessage.cpp`: rejected because it omits this target and models only the raw constructor, scalar deleting destructor, and name helper.

## First-Draft C++ Recommendation

Formal `RECONSTRUCTION_CPP` should remain blank.

No-code proof:

1. The exact binary body is fully known, but final source requires the hierarchy-wide `+0x0c` virtual declaration.
2. Current MCP sibling-slot evidence shows `int` return for formatter implementations and `errno_t` return for stored-message copy implementations. Those are ABI-compatible but not source-name proof.
3. There are no direct callers to reveal whether callers use, discard, or normalize the return value.
4. The target has a concrete vtable route but no recovered source symbol for the virtual method name.
5. A formal C++ block with a guessed method name would force source declarations across [UID:00013X], [UID:0001XI], [UID:0001UE], [UID:0002ND], and [UID:0000J5] before the hierarchy is standardized.
6. The implemented score `86/92` clears the target source-quality raise, but formal C++ stays blank because the Error hierarchy `+0x0c` virtual name and return type must be standardized across all formatter/copy implementations before this body is emitted as source.

Review-only source shape, not for insertion into the formal block:

```cpp
int ErrorMessage::FormatErrorMessage(wchar_t *destination, size_t destinationChars) const
{
    return ::wcscpy_s(destination, destinationChars, m_message);
}
```

If the project standardizes on `CopyErrorMessage` instead of `FormatErrorMessage`, the same body can be used with that name. If the project standardizes the interface return as `errno_t`, that typedef must be applied consistently to formatter implementations or documented as an ABI-compatible `int` alias.

## Score And Metadata Implementation

Implemented target metadata:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:00004K
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004K
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Rationale:

- Completion can rise above 85 because current MCP confirms exact function bounds, exact bytes, padding, decompilation, callee, vtable slot, raw constructor store, pointer-search route, no-direct-caller caveat, inline-buffer layout, sibling slot return-type context, support-doc route, and no-code proof.
- Completion should stay below final because the final source-facing virtual method name, hierarchy-wide return spelling, and exact `Error.h` declaration are still unresolved.
- Confidence can rise to 92 because the binary/vtable/layout facts are current-session MCP backed and mutually consistent. Confidence should remain below final audit because original source symbols and direct caller declaration evidence remain absent.

## Implemented Target Doc Changes

Updated [UID:00013Z] `by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md`:

1. Change metadata to `COMPLETION:86`, `CONFIDENCE:92`; keep owner/emitter/reconstructable/C++ disposition unchanged.
2. Replace old `2026-06-06 Live IDA Refresh` provenance with a `2026-06-23 B002 MCP source-quality recheck` section using session `b880584f`.
3. Add MCP health/session identity: correct IDB path, module, imagebase, Hex-Rays readiness, and active session.
4. Add exact successful MCP facts: `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `callees`, `xrefs_to`, `get_bytes`, `get_int`, `find_bytes`, and `list_globals`.
5. Preserve and update the exact bytes and one-block disassembly.
6. Decode the `0x006193b8-0x006193d0` vtable bytes and identify `0x006193c8` as the `+0x0c` message-output slot.
7. Add the pointer-route findings: VA pointer to target found only at `0x006193c8`; target RVA pattern absent; raw constructor VA/RVA pointer patterns absent; vtable-base immediate found only in the raw constructor store; no slot-address pointer route.
8. Document the no-direct-caller result as expected for a vtable-only helper, not a liveness blocker.
9. Add the raw constructor status: `0x004a63e0` is not an IDA function, decompilation fails, disassembly stores `??_7ErrorMessage@@6B@` at `0x004a63ef`, and xrefs to the raw start are absent.
10. Add the hierarchy-wide return-type analysis: local helper returns `errno_t`, while status-code formatters return `int`; final source should use a shared integer-returning virtual interface after project standardization.
11. Add the target-specific formal no-code proof and keep formal C++ blank.
12. Keep the source route through [UID:00004K] `ErrorMessage` and [UID:0000J5] `Error.cpp`.

Validator run after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00013Z-ErrorMessageCopyMessage-source-quality-removed.md](00013Z-ErrorMessageCopyMessage-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implemented Support Doc Changes

[UID:00004K] `by-class/ErrorMessage.md`:

- Add a 2026-06-23 B002 MCP-backed note for session `b880584f`.
- Preserve the raw constructor caveat and update the copy-helper row to say the helper is exact, current-session verified, vtable-only, and source-name/return-type capped by the shared `+0x0c` virtual decision.
- Add the `wchar_t m_message[256]` support from target `+0x04` plus destructor object size `0x204`.

Validator run after implementation:

> Executable block R002 was removed from this report and preserved verbatim in [00013Z-ErrorMessageCopyMessage-source-quality-removed.md](00013Z-ErrorMessageCopyMessage-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

[UID:00013X] `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`:

- Add or adjust the [UID:00013Z] row to use `86/92` target evidence and current MCP provenance.
- Preserve the aggregate no-code proof and broad `util/Error.cpp` source placement.
- Keep `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` as the current best common source-name policy, with `CopyErrorMessage` retained only as a possible standardized alternative.
- Add the hierarchy-wide return-type caveat: status-code formatter slots decompile as `int`, stored-message copy slots as `errno_t`; do not force target-local `errno_t` as the final interface without a hierarchy decision.

Validator run after implementation:

> Executable block R003 was removed from this report and preserved verbatim in [00013Z-ErrorMessageCopyMessage-source-quality-removed.md](00013Z-ErrorMessageCopyMessage-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

[UID:0000J5] `by-file/Error.md`:

- Update the ErrorWrappers split/source policy to mention the MCP-backed [UID:00013Z] exact helper and the unresolved `+0x0c` virtual return/name standardization.
- Preserve `util/Error.cpp` as the source route and keep consumer modules rejected.

Validator run after implementation:

> Executable block R004 was removed from this report and preserved verbatim in [00013Z-ErrorMessageCopyMessage-source-quality-removed.md](00013Z-ErrorMessageCopyMessage-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

[UID:0001XI] `by-type/by-vtable/ErrorHierarchyVtables.md`:

- Keep the five-slot shape.
- Add current MCP support for `0x006193c8 -> 0x004a6410` and the return-type/naming caveat for the shared `+0x0c` virtual.

Validator run after implementation:

> Executable block R005 was removed from this report and preserved verbatim in [00013Z-ErrorMessageCopyMessage-source-quality-removed.md](00013Z-ErrorMessageCopyMessage-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

[UID:0001UE] `by-type/by-struct/ErrorObjectLayouts.md`:

- No ownership change.
- If not already present at equal detail, add current MCP support that [UID:00013Z] copies from byte offset `+0x04` and `sub_4A6920` uses object size `0x204`, supporting `wchar_t m_message[256]`.

Validator run after implementation:

> Executable block R006 was removed from this report and preserved verbatim in [00013Z-ErrorMessageCopyMessage-source-quality-removed.md](00013Z-ErrorMessageCopyMessage-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

[UID:0002ND] `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`:

- Preserve source-declared/generated-binary handling.
- Add current MCP evidence for `ErrorMessage` slot bytes if the supervisor wants provenance synchronized: `0x006193b8 -> 0x00646d10`, `0x006193bc -> 0x004a6920`, `0x006193c8 -> 0x004a6410`, `0x006193cc -> 0x004a6a70`.
- Keep blank formal C++; vtable bytes are compiler output.

Validator run after implementation:

> Executable block R007 was removed from this report and preserved verbatim in [00013Z-ErrorMessageCopyMessage-source-quality-removed.md](00013Z-ErrorMessageCopyMessage-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No support edit is required for [UID:000140] `FileErrorCopyMessage` unless the supervisor wants sibling-return-policy wording duplicated there. It was checked only to understand the shared `+0x0c` virtual return/name issue.

## Supervisor-Owned Coverage Text

For supervisor-owned coverage application, replace the current [UID:00013Z] nested row in `by-memory/-coverage-report.md` with:

```text
        - [UID:00013Z][0x004a6410-0x004a6429.ErrorMessageCopyMessage](by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md) 0x004a6410-0x004a6429 | method | ErrorMessageCopyMessage : reconstructable : 86% : strong : Attached to ErrorMessage/Error.cpp; MCP session b880584f confirms exact 0x19-byte vtable-slot helper, one-block wcscpy_s body copying from inline wide storage at byte offset +0x04, vtable slot 0x006193c8 inside ErrorMessage table 0x006193bc, raw constructor store at 0x004a63ef, unique VA pointer hit at 0x006193c8, no direct code callers, and blank formal C++ pending hierarchy-wide +0x0c virtual name/return-type standardization.
```

Coverage validation is supervisor-owned and should be run only after the coverage row is applied:

> Executable block R008 was removed from this report and preserved verbatim in [00013Z-ErrorMessageCopyMessage-source-quality-removed.md](00013Z-ErrorMessageCopyMessage-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename, Type, And Comment Recommendations

Do not rename or type the IDA database during this report-only pass.

High-confidence documentation names:

- `sub_4A6410`: `ErrorMessage::FormatErrorMessage` or `ErrorMessage::CopyErrorMessage`, depending on the hierarchy-wide `+0x0c` virtual decision.
- Vtable slot `0x006193c8`: `ErrorMessage` message-output slot.
- Field at byte offset `+0x04`: `wchar_t m_message[256]`, descriptive name only.

High-confidence comments if an IDA-edit pass is later authorized:

- At `0x004a6413`: source buffer is the inline `ErrorMessage` wide-message storage at `this+0x04`.
- At `0x006193c8`: `ErrorMessage` `+0x0c` message-output virtual slot, exact body [UID:00013Z].
- At `0x004a63ef`: raw constructor-shaped vtable store for `ErrorMessage`; do not treat `0x004a63e0` as a modeled IDA function without an explicit raw-function recovery pass.

Type recommendation:

- Prefer a shared declaration like `int FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` until final source evidence settles the name/return spelling.
- If `errno_t` is chosen, standardize it across all `+0x0c` implementations or document it as an `int` ABI alias. Do not apply a target-local method type that conflicts with sibling formatter returns.

## Validators

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted implementation edits.

| File | Command | Exit / `ok` | Relevant validator output |
| --- | --- | --- | --- |
| `by-memory\0x004a6410-0x004a6429.ErrorMessageCopyMessage.md` | `python .\tools\validator.py --mode file --file by-memory\0x004a6410-0x004a6429.ErrorMessageCopyMessage.md --apply --queue-timeout 240` | exit `0`, `ok: 1` | `completion_update 00013Z ... 86`; `confidence_update 00013Z ... 92`; `uid_link_update: 4`; `reference_index_add 0002ND`; `stats_row_remove 00013Z Low_Completion_Reconstructable`; `stats_rescore_recommended`; `projected_stats_update`; `autogen_registry_rebuild`; `autogen_cpp_update: 1`; `autogen_backup_create ... tools/validator_autogen_backup/20260623-073406 changed generated files backed up`. |
| `by-class\ErrorMessage.md` | `python .\tools\validator.py --mode file --file by-class\ErrorMessage.md --apply --queue-timeout 240` | exit `0`, `ok: 1` | `stats_row_update 00004K ... Low_Completion_Reconstructable`; `stats_row_update 00004K ... by-class_Reconstructable`; `projected_stats_update`; `autogen_registry_rebuild`. |
| `by-memory\0x004a60d0-0x004a6a76.ErrorWrappers.md` | `python .\tools\validator.py --mode file --file by-memory\0x004a60d0-0x004a6a76.ErrorWrappers.md --apply --queue-timeout 240` | exit `0`, `ok: 1` | `uid_link_insert: 6`; `stats_incremental_noop: 1`; `projected_stats_update`; `autogen_registry_rebuild`. |
| `by-file\Error.md` | `python .\tools\validator.py --mode file --file by-file\Error.md --apply --queue-timeout 240` | exit `0`, `ok: 1` | `uid_link_insert: 9`, including [UID:00013Z], [UID:00013X], [UID:0001XI], [UID:0001UE], and [UID:0002ND] links; `stats_row_update 0000J5 ... Low_Confidence_Not_Reconstructable`; `projected_stats_update`; `autogen_registry_rebuild`. |
| `by-type\by-vtable\ErrorHierarchyVtables.md` | `python .\tools\validator.py --mode file --file by-type\by-vtable\ErrorHierarchyVtables.md --apply --queue-timeout 240` | exit `0`, `ok: 1` | `uid_link_insert: 2` for [UID:00013Z]; `stats_row_update 0001XI ... by-type_Reconstructable`; `projected_stats_update`; `autogen_registry_rebuild`. |
| `by-type\by-struct\ErrorObjectLayouts.md` | `python .\tools\validator.py --mode file --file by-type\by-struct\ErrorObjectLayouts.md --apply --queue-timeout 240` | exit `0`, `ok: 1` | `uid_link_insert: 3` for [UID:00013Z]; `stats_row_update 0001UE ... by-type_Reconstructable`; `projected_stats_update`; `autogen_registry_rebuild`. |
| `by-memory\0x00619340-0x00619448.ErrorHierarchyVtableData.md` | `python .\tools\validator.py --mode file --file by-memory\0x00619340-0x00619448.ErrorHierarchyVtableData.md --apply --queue-timeout 240` | exit `0`, `ok: 1` | `uid_link_insert: 2` for [UID:00013Z]; `stats_incremental_noop: 1`; `projected_stats_update`; `autogen_registry_rebuild`. |

Recurring validator notices across the batch: `autogen_registry_stale` for missing registered files [UID:0003E6] `UserListDialogPaneVtableLeadInData` and [UID:00026U] `UserListReadOnlyData`; `autogen_cpp_conflict: 5` for existing non-sentinel generated files `FontImageLib.cpp`, `GeneralPurposePanel.cpp`, `HistoryViewingPane.cpp`, `HourPane.cpp`, and `IMEPanes.cpp`; `autogen_children_fallback_insert: 8` and `autogen_children_marker_missing: 8`. No validator command failed.

Validator `--apply` side effects recorded: validator registry rebuilds in `tools/validator.ini`, projected stats updates in `project-level/-auto-completion-stats.md`, UID auto-link insert/update changes in the validated by-* docs, and one generated-file update/backup for `auto-generated/NexusTK/util/Error.cpp` under `tools/validator_autogen_backup/20260623-073406`. No `-coverage-report.md` file was edited by B002; the coverage row above remains supervisor-owned.

## Follow-Up Actions

- Supervisor: verify the implemented target/support docs and this checklist against the accepted report.
- Supervisor: apply the exact `by-memory/-coverage-report.md` row above if choosing to update coverage now, then run the coverage validator.
- Supervisor: move this report to executed and reassign B002 after verification.
- B002: no further action is required for this report unless the supervisor requests a focused follow-up.

## Changed Files

Manual implementation edits:

- `tools/leaser/Agents/Agent-B002/research/00013Z-ErrorMessageCopyMessage-source-quality.md`
- `by-memory/0x004a6410-0x004a6429.ErrorMessageCopyMessage.md`
- `by-class/ErrorMessage.md`
- `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`
- `by-file/Error.md`
- `by-type/by-vtable/ErrorHierarchyVtables.md`
- `by-type/by-struct/ErrorObjectLayouts.md`
- `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`

Validator `--apply` side effects are recorded in the Validators section. No coverage report was manually edited.

## Implementation Tracking Checklist

Report-only research completed:

- [x] Read `Agent-B002/goal.md`; proof: current assignment matches `B002-report-error-message-copy-message-source-quality-00013Z-mcp-20260623`.
- [x] Used `ntk-b-agent-workflow`; proof: followed report-only restrictions, no subagents, no by-* edits, no coverage edits.
- [x] Verified MCP health/session; proof: `server_health` and `idb_list` on session `b880584f` reported active correct IDB, Hex-Rays ready, strings cache ready.
- [x] Verified exact target function/range; proof: `lookup_funcs 0x004a6410 -> sub_4A6410 size 0x19`, `lookup_funcs 0x004a6429 -> Not a function`.
- [x] Verified bytes/disassembly/decompile; proof: `get_bytes`, `disasm`, and `decompile` all show the one-block `_wcscpy_s` body copying from `[ecx+4]`.
- [x] Verified callee/caller state; proof: `callees` reports `_wcscpy_s` only; `analyze_function` reports no callers.
- [x] Verified vtable route; proof: `xrefs_to 0x004a6410` reports data xref `0x006193c8`; `get_int`/`get_bytes` decode the `ErrorMessage` vtable sequence.
- [x] Verified raw constructor relationship and caveat; proof: `lookup_funcs 0x004a63e0 -> Not a function`, `decompile 0x004a63e0` fails, `disasm 0x004a63e0` shows vtable store at `0x004a63ef`, `xrefs_to 0x004a63e0` reports none.
- [x] Verified pointer-route positives/negatives; proof: `find_bytes 10 64 4A 00 -> 0x006193c8`; `10 64 0A 00`, `E0 63 4A 00`, and `E0 63 0A 00` have no matches.
- [x] Verified layout support; proof: target uses `[ecx+4]`; `disasm 0x004a6920` has object-size immediate `204h`; `int_convert.py` confirms `0x204`, `0x200`, and `0x04`.
- [x] Rechecked source-signature issue with sibling slots; proof: MCP `analyze_function` shows formatter slots return `int` while stored-message copy slots return `errno_t`.
- [x] Checked existing leads without accepting them blindly; proof: B003 report absent, B013 report is fallback-only lead, B002 destructor report revalidated through current MCP, generated `class_ErrorMessage.cpp` omits the target.
- [x] Wrote this report only during the original report-only pass; proof: no by-* docs, generated files, IDA DB, tool state, support docs, or coverage reports were edited before supervisor acceptance.

Implementation callback completed:

- [x] Confirmed lease state before editing; proof: `current_leases.md` had no conflicting lease on the required Error docs, and B002 leased only the seven exact by-* files needed for the edit batch.
- [x] Updated [UID:00013Z] metadata to `86/92`; proof: target header now has `COMPLETION:86` and `CONFIDENCE:92`.
- [x] Updated [UID:00013Z] body with current MCP session `b880584f`, exact bytes/disassembly/decompile, vtable/pointer routes, raw constructor caveat, sibling return-type analysis, and no-code proof; proof: target sections `2026-06-23 B002 MCP Source-Quality Recheck`, `Layout And Source-Signature Findings`, `Source Reconstruction Notes`, `Rejected Alternatives`, and `Score Rationale`.
- [x] Kept [UID:00013Z] `CANONICAL_OWNER:00004K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004K`, blank emitter position, and blank formal C++; proof: target header remains owner/emitter/class routed and `RECONSTRUCTION_CPP` is empty.
- [x] Updated [UID:00004K] `ErrorMessage` with current MCP-backed helper and inline-buffer evidence; proof: `Important Methods`, `Ownership Notes`, `Autogen Status`, `Score Rationale`, and `Changes` now cite session `b880584f`, `0x006193c8`, `[ecx+4]`, destructor size `0x204`, and the shared `+0x0c` no-code caveat.
- [x] Updated [UID:00013X] `ErrorWrappers` with current MCP-backed [UID:00013Z] row/provenance and hierarchy-wide return/name caveat; proof: `Covered Range`, `Evidence`, `Source-Facing Names And Layout Decisions`, `Formatter And Copy Behavior`, `Data Caveats`, and `Changes`.
- [x] Updated [UID:0000J5] `Error` with the current helper/source-signature caveat; proof: `Evidence`, `ErrorWrappers Split Candidates`, `Open Questions`, and `Changes` now cite [UID:00013Z] MCP evidence and shared `+0x0c` name/return standardization.
- [x] Updated [UID:0001XI] `ErrorHierarchyVtables` with current `0x006193c8` evidence and shared `+0x0c` name/return caveat; proof: `Common Slot Shape`, `Live IDA Recheck`, `Data Caveats`, and `Changes`.
- [x] Updated [UID:0001UE] `ErrorObjectLayouts` with current `+0x04`/`0x204` support; proof: `Layout Families`, `Source-Layout Impact`, `Open Questions`, and `Changes`.
- [x] Updated [UID:0002ND] `ErrorHierarchyVtableData` with current `ErrorMessage` slot bytes/provenance; proof: `Table Sequence`, `Boundary Evidence`, `Reconstruction Notes`, and `Changes`.
- [x] Ran scoped validators for each changed by-* doc and recorded command, exit code, `ok` count, warnings, and side effects; proof: Validators section above records all seven commands with exit `0` and `ok: 1`.
- [x] Released B002 leases immediately after the edit/validator batch; proof: `leaser.py B002 unlease ...` returned `Success` for all seven files, and `current_leases.md` afterward showed no active B002 lease.
- [x] Left supervisor-owned coverage text in this report and did not edit `by-memory/-coverage-report.md`; proof: coverage text remains under `Supervisor-Owned Coverage Text`, and no coverage validator was run by B002.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00013Z-ErrorMessageCopyMessage-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"00013Z"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00013Z-ErrorMessageCopyMessage-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00013Z-ErrorMessageCopyMessage-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00013Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
