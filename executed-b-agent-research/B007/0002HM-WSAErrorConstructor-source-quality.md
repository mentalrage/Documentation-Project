** TARGET-REPORT-UID:0002HM **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Report: [UID:0002HM] WSAErrorConstructor Source Quality

Assignment id: `B007-report-0002HM-WSAErrorConstructor-source-quality-20260627`

Target: [UID:0002HM] `by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md`

Mode: report-only research. No by-* docs were edited in this pass.

## Executive Recommendation

Promote [UID:0002HM] to source-ready exact constructor status, preserve owner/emitter route [UID:0000GB] `by-class/WSAError.md` -> [UID:0000J5] `by-file/Error.md` / `util/Error.cpp`, raise the target from `85/89` to `90/92`, and insert formal constructor C++:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WSAError::WSAError()
    : m_errorCode(WSAGetLastError())
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This target clears the active formal-code gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:0000GB`, confirmed class/file route, current average score `87`, exact range/padding proof, and current MCP/source-shape evidence. The old "blank C++ pending `90/90+` gate" rationale is stale and should be replaced. The broader Error hierarchy declaration and WSA formatter remain open, but they do not block this one-field exact constructor.

## Supervisor Active Recheck

The supervisor assigned Agent-B007 to produce a report-only research file for [UID:0002HM], using live IDA MCP and current by-structure rules, without editing by-* docs.

No split repair is required before implementation. The target already exists as an exact by-memory child with a real IDA function record at `0x004a64a0` and end-exclusive boundary `0x004a64c5`. The only implementation repair is source-quality incorporation: C++ block, stale score rationale, target/support synchronization, and generated-output refresh by validator after supervisor acceptance.

Every source-bearing child in direct scope has a precise disposition:

- [UID:0002HM] constructor: source-ready exact child, emit formal constructor C++.
- `0x004a64d0-0x004a6549` formatter: out of target scope and still aggregate-only/exact-child future work.
- [UID:00013X] broad aggregate: remains blank broad C++ because it mixes many classes, raw constructor-shaped starts, formatter slots, and ABI destructor helpers.

## Inference Research Guidance Check

I used the project-level `ntk-b-agent-workflow` skill and current `by-structure.md` code-entry rule. The current rule is average score greater than `85` plus reconstructable and nonblank emitter route, not the old `90/90+` or `95/95` gate.

Stale assumptions treated as uncertain and rechecked:

- Target page says final C++ is blank because the hierarchy is below a `90/90+` gate.
- WSA class page says class-level C++ is blank until the shared declaration clears `90/90+`.
- Generated `auto-generated/NexusTK/util/Error.cpp` still shows an empty marker and stale `78/88` for [UID:0002HM].
- Generated tracker rows still show stale `78/88` or `78/84` values for WSA pages.

IDA facts are separated below from documentation evidence and source-shape inference. Wave3/generated one-class files and generated `char *` formatter signatures were treated as stale lead material only; they were not used as authority.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best current conclusion | Evidence used | Disposition |
| --- | --- | --- | --- |
| Constructor signature | `WSAError::WSAError()` | No explicit stack argument, `retn`, decompile `_DWORD *__thiscall(_DWORD *this)`, sibling Win32 no-arg status-code constructor | Accepted source-facing signature |
| Stored field | `int m_errorCode` at byte offset `+0x04` | `WSAGetLastError` returns Winsock int error code; disasm stores `eax` to `[esi+4]`; aggregate already lists WSA as `int m_errorCode`; Win32/DDError accepted sibling field `m_errorCode` | Accepted inferred source-facing field/type |
| Source body shape | Initializer list `: m_errorCode(WSAGetLastError())` | Sibling accepted constructor pages use initializer-list member initialization; body has only status-code capture after compiler base/vtable setup | Accepted formal C++ |
| Base setup | Ordinary inherited `LObject`/Error construction | `sub_4F4A80` decompiles to `LObject::vftable` store and return; sibling constructors treat it as implicit base construction | Do not emit raw helper call |
| Vtable store | Compiler constructor effect | Constructor writes `??_7WSAError@@6B@` after base setup; vtable page maps table to WSAError | Do not emit explicit vtable assignment |
| Caller ownership | Socket is consumer only | Sole caller constructs object after `gethostbyname` failure and throws with `__TI4PAVWSAError@@`; implementation is in compact Error wrapper cluster | Reject Socket ownership |
| Aggregate ownership | Broad aggregate is evidence, not emitter | [UID:00013X] still contains many unrelated/range-mixed bodies and raw starts | Reject aggregate C++ for this constructor |
| Formatter dependency | Separate future child | `0x004a64d0` is separate `0x79` function and vtable slot | Does not block constructor C++ |
| Generated output | Stale lead only | Generated `Error.cpp` still has empty marker and stale scores | Do not rely on generated output |

Rejected alternatives:

- Blank C++ because full Error hierarchy declaration is unresolved: rejected for this exact constructor; current gate and sibling policy allow exact child C++.
- Decompiler-shaped source with `_DWORD *`, `this[1]`, `sub_4A64A0`, `sub_4F4A80`, `return this`, or explicit vtable stores: rejected as compiler/decompiler artifacts.
- `DWORD m_errorCode`: rejected for WSA because `WSAGetLastError` returns `int`; `DWORD` is appropriate for Win32Error's `GetLastError`.
- `m_lastError`, `field_4`, `dword_4`, `this[1]`: rejected because current status-code wrapper docs use `m_errorCode` and sibling exact pages intentionally avoid local naming drift.
- Socket/transport source placement: rejected because the socket caller is a throw/use-site.
- Merge constructor with `0x004a64d0` formatter: rejected by function boundary and `0xcc` padding.

Remaining unresolved issues do not block this target's constructor C++:

- Exact original member spelling is not symbol-proven. `m_errorCode` is accepted as the lowest-churn recovered source-facing name, matching recent Win32/DDError policy.
- The hierarchy-wide `+0x0c` virtual declaration and WSA formatter body still need exact source-quality work. That is formatter/class-header scope, not constructor scope.

## Evidence Standards Used

Evidence used: live IDA MCP function lookup, decompile, disassembly, xrefs, callees, imports, raw bytes, vtable bytes, caller context, sibling accepted constructor pages, current by-class/by-file/by-memory/by-type support docs, generated-output stale-state checks, and negative boundary checks.

The evidence is strong enough because the constructor is one basic block, has one source-authored side effect (`m_errorCode` initialization), has clean function boundaries, has a single caller with C++ EH throw type, and matches the accepted source pattern for sibling exact status-code constructors.

Limits: IDA MCP cannot prove original member spelling or header declaration text. Confidence therefore remains below final-audit range, but that limitation no longer justifies blank target C++.

## Evidence Checked

IDA MCP checks performed:

- JSON-RPC `initialize` id `700`: server `ida-pro-mcp` version `1.0.0`.
- `tools/list` id `701` and focused schema check id `703`: current server requires explicit `database` and uses single-address `decompile`/`disasm`.
- `idb_list` id `702`: active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, not analyzing, backend worker.
- `server_health` batch id `704`: `status:"ok"`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- `lookup_funcs` id `705`: target and adjacent boundaries.
- `decompile` id `706`: target constructor pseudocode.
- `disasm` id `707`: target constructor instructions.
- `xrefs_to` id `708`: constructor, vtable, import, and formatter-slot routes.
- `callees` id `709`: constructor, formatter, and socket caller callees.
- `get_bytes` id `710`: bytes around constructor, WSA vtable bytes, and import thunk address.
- `imports_query` id `711`: `WSAGetLastError`, `FormatMessageW`, and `GetLastError`.
- `disasm`/`decompile` caller ids `712`/`713`: socket caller throw path.
- `decompile`/`disasm` base helper ids `714`/`715`: `sub_4F4A80` is `LObject` base setup.
- `xrefs_to` id `716`, `decompile` id `717`, `get_bytes` id `718`: vtable/formatter/string support.

Docs checked:

- Target [UID:0002HM].
- [UID:0000GB] `by-class/WSAError.md`.
- [UID:0000J5] `by-file/Error.md`.
- [UID:00013X] `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`.
- [UID:0001UE] `by-type/by-struct/ErrorObjectLayouts.md`.
- [UID:0001XI] `by-type/by-vtable/ErrorHierarchyVtables.md`.
- Sibling accepted pages for Win32Error, DDError, FileError, and current class pages.
- `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/NexusTK/util/Error.cpp` as stale lead material only.
- B013 aggregate report for generated signature rejection and status-code family naming leads.

Negative checks performed:

- `lookup_funcs 0x004a649f` and `lookup_funcs 0x004a64c5` report not a function.
- `xrefs_to 0x006193e8` and vtable interior slot addresses are not code ownership.
- `xrefs_to 0x006193f8` itself has zero xrefs; the formatter route is `xrefs_to 0x004a64d0 -> data at 0x006193f8`.
- Generated output still stale; not used as proof.
- No IDA DB write/rename/type/comment operation was made.

Failed or skipped checks:

- No fallback-only path was used; MCP was available.
- No manual PE disassembly was needed beyond MCP byte reads.
- No validators were run on by-* docs because this assignment is report-only and no by-* files were edited.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `[0x004a64a0,0x004a64c5)` is the exact constructor range | High | `lookup_funcs` size `0x25`; `0x004a64c5` not a function; bytes show padding after `retn` | Adjacent formatter starts at `0x004a64d0`; no in-range formatter bytes | None for range |
| Source signature is `WSAError::WSAError()` | High | Thiscall-only constructor, no stack args, `retn`, sibling no-arg Win32 status constructor | No explicit args in disasm/decompile | Exact original header spelling not recovered, but class name is RTTI/vtable-backed |
| Field is `int m_errorCode` | High for type/role, medium-high for original spelling | `WSAGetLastError` import; store to `[esi+4]`; aggregate says `int m_errorCode`; sibling policy accepts `m_errorCode` | `DWORD` checked and rejected for WSA; `m_lastError` checked and rejected as local drift | Original member spelling remains inferred |
| Owner/emitter route stays WSAError -> Error.cpp | High | by-class/by-file support, compact Error wrapper cluster, vtable page, caller is throw-site | Socket/transport ownership rejected | None |
| Formal C++ should emit now | High | Active gate cleared and sibling Win32/DDError accepted same shape | Old `90/90+` wording checked as stale | Supervisor acceptance required |
| Class-level WSAError C++ should remain blank | Medium-high | Formatter/header/declaration still not standardized | Constructor-specific blocker resolved | Future hierarchy declaration pass |

## Positive Evidence Summary

Direct facts supporting the recommendation:

- `lookup_funcs` reports `sub_4A64A0` at `0x004a64a0`, size `0x25`.
- Decompilation is exactly `sub_4F4A80(this)`, WSAError vtable assignment, `this[1] = WSAGetLastError()`, return `this`.
- Disassembly stores `this` in `esi`, calls `sub_4F4A80`, writes `0x006193ec`, calls import `0x0060d534` `WSAGetLastError`, stores `eax` to `[esi+4]`, and returns.
- Callees are only `sub_4F4A80` and external `WSAGetLastError`.
- `imports_query` resolves `WSAGetLastError` as WSOCK32 import at `0x0060d534`.
- Caller path allocates eight bytes, calls `sub_4A64A0`, and throws with `__TI4PAVWSAError@@` after `gethostbyname` fails.
- Raw bytes prove `0xcc` padding before and after the function.

Corroborating documentation:

- [UID:00013X] already lists `WSAError::WSAError()` and `int m_errorCode` from `WSAGetLastError()`.
- [UID:0001UE] lists WSA in the stored status-code family.
- [UID:0001XI] maps WSA vtable `0x006193ec`, destructor `0x004a68a0`, formatter `0x004a64d0`, name slot `0x004a6a70`.
- Win32Error and DDError exact constructor pages now emit initializer-list source using `m_errorCode`.

Strongest inference chain:

The binary behavior is a one-field constructor. The only source-authored state is the result of `WSAGetLastError()` stored at `+0x04`; base setup and vtable store are compiler lowering. Existing layout docs and sibling source-ready constructor pages converge on `m_errorCode`. Therefore the most faithful recovered source is a no-arg constructor with an initializer list for `m_errorCode`.

## IDA MCP Facts

Function/range facts:

- `0x004a649f`: not a function.
- `0x004a64a0`: `sub_4A64A0`, size `0x25`.
- `0x004a64c4`: inside `sub_4A64A0`.
- `0x004a64c5`: not a function.
- `0x004a64d0`: `sub_4A64D0`, size `0x79`, separate formatter.
- `0x004f4a80`: `sub_4F4A80`, size `0x9`, writes `LObject::vftable` and returns `this`.
- `0x00577890`: `sub_577890`, size `0x1bc`; `0x00577a28` is inside it.

Data/table/padding facts:

- Bytes at `0x004a6490` show predecessor tail, `0xcc` padding from `0x004a6499-0x004a649f`, constructor bytes from `0x004a64a0-0x004a64c4`, and `0xcc` padding from `0x004a64c5-0x004a64cf` before formatter start.
- Bytes at `0x006193e8` decode WSAError RTTI/vtable run: RTTI `0x00646db0`, vtable base `0x006193ec`, destructor `0x004a68a0`, inherited runtime `0x004f4b10`, no-op `0x0041b6c0`, message slot `0x004a64d0`, name slot `0x004a6a70`.
- UTF-16 formatter strings at `0x006195a4` and `0x006195c0` are `WSAError: %s` and `WSAError: 0x%p`, corroborating the stored Winsock code role.

Xref facts:

- `xrefs_to 0x004a64a0`: one code ref at `0x00577a28` inside `sub_577890`.
- `xrefs_to 0x006193ec`: one data ref at `0x004a64af` inside constructor.
- `xrefs_to 0x0060d534`: includes constructor call at `0x004a64b5`; another unrelated site exists at `0x0048f652`.
- `xrefs_to 0x004a64d0`: one data ref at `0x006193f8`, the WSA formatter vtable slot.

Vtable/global/type facts:

- `imports_query WSAGetLastError`: `0x0060d534`, module `WSOCK32`.
- `imports_query FormatMessageW`: `0x0060d23c`, module `KERNEL32`.
- `imports_query GetLastError`: separate KERNEL32 import `0x0060d11c`, supporting different Win32Error type choice.
- Caller disassembly throws `__TI4PAVWSAError@@` at `0x00577a3d`, proving the allocated object is a WSAError exception.

Negative IDA facts:

- No function begins at the end-exclusive boundary `0x004a64c5`.
- No evidence supports merging the formatter into the constructor.
- No IDA evidence supports Socket as source owner.
- No IDA DB edit was performed or requested.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a64a0-0x004a64c5` | [UID:0002HM] `by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md` | `WSAError::WSAError()` | TRUE | [UID:0000GB] WSAError | Current `85/89`; recommend `90/92` | Source-ready exact constructor |
| `0x004a64d0-0x004a6549` | aggregate-only in [UID:00013X] `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` | `WSAError::FormatErrorMessage` | TRUE in aggregate | [UID:0000GB] / [UID:0000J5] | Aggregate `87/89` | Future exact child, not this target |
| `WSAError` class | [UID:0000GB] `by-class/WSAError.md` | Concrete Winsock error wrapper | TRUE | [UID:0000J5] Error | Current `85/86`; recommend `87/88` | Class C++ stays blank; child emits |
| Error wrappers aggregate | [UID:00013X] `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` | Broad executable evidence cluster | TRUE | [UID:0000J5] Error | `87/89` unchanged | Add WSA source-ready child notes |
| Error layouts | [UID:0001UE] `by-type/by-struct/ErrorObjectLayouts.md` | Error object layout family | TRUE | [UID:0000J5] Error | `86/88` unchanged | Add WSA `int m_errorCode` resolution |
| Error vtables | [UID:0001XI] `by-type/by-vtable/ErrorHierarchyVtables.md` | Vtable/slot evidence | TRUE | [UID:0000J5] Error | `86/90` unchanged | Add WSA constructor source-ready sync |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00577a28 -> 0x004a64a0` | One direct constructor call | Socket/network caller constructs WSAError on `gethostbyname` failure |
| `0x00577a10 -> sub_4F4AA0(8)` | Allocation before constructor | Object size eight bytes: vptr plus `+0x04` code |
| `0x00577a3d` | Throws `__TI4PAVWSAError@@` | Confirms class identity and consumer-only caller role |
| `0x004a64aa -> 0x004f4a80` | Base setup callee | Compiler lowering of inherited base construction |
| `0x004a64af -> 0x006193ec` | WSAError vtable store | Confirms class vtable route |
| `0x004a64b5 -> 0x0060d534` | WSOCK32 `WSAGetLastError` import call | Source-authored error capture |
| `0x006193f8 -> 0x004a64d0` | Vtable data slot | Formatter is separate WSA virtual method |

## Documentation Evidence And IDA Status

Existing docs supporting the conclusion:

- Target page already records exact range, behavior, sole caller, and padding.
- [UID:00013X] already identifies `WSAError::WSAError()` and `int m_errorCode`.
- [UID:0001UE] includes WSA in stored status-code family.
- [UID:0001XI] maps the WSA vtable row and constructor vtable store.
- Win32/DDError exact pages establish accepted sibling policy for source-ready one-field status-code constructors.

Stale/incomplete/contradicted docs:

- Target Reconstruction Notes and Score Rationale still cite the old `90/90+` C++ gate and broader hierarchy naming as a target-local blocker.
- [UID:0000GB] Autogen Status still says C++ blank until active `90/90+` gate; that is stale for the exact constructor child.
- [UID:00013X] row for [UID:0002HM] says only "Exact child; captures `WSAGetLastError`" instead of source-ready child with formal C++.
- [UID:0001UE] open question still lists Winsock field spelling unresolved; after this target it should only remain as exact-original-spelling caveat, not target-local C++ blocker.
- Generated tracker and generated `Error.cpp` are stale; they should refresh from source after accepted implementation/validator execution.

Generated/coverage state:

- `auto-generated/NexusTK/util/Error.cpp` still contains empty markers for [UID:0000GB] and [UID:0002HM] with stale scores.
- `auto-generated/-ag-research-tracker.md` lists [UID:0002HM] as `78/88` although the current target page is `85/89`.
- `auto-generated/-ag-memory-coverage.md` marks [UID:0002HM] as `emits` but `emits_code:false`, consistent with the current blank formal block.
- Do not manually edit generated files or coverage reports; validator-owned refresh should follow accepted by-* edits.

## Ranked Ownership Analysis

### 1. [UID:0000GB] WSAError under [UID:0000J5] Error

Evidence for:

- RTTI/vtable name `??_7WSAError@@6B@` at `0x006193ec`.
- Throw type `__TI4PAVWSAError@@` in sole caller.
- Error file and aggregate group WSA with the compact error wrapper cluster.
- Formatter and message strings are in the Error hierarchy run.

Evidence against:

- The only direct constructor caller is socket/network code.

Decision: accepted. Socket is a consumer; implementation belongs to WSAError/Error.cpp.

### 2. [UID:0000DD] Socket / transport

Evidence for:

- Sole direct call is inside a network/gethostbyname parsing function.

Evidence against:

- Caller allocates and throws an Error hierarchy object; it does not define the class.
- Vtable, strings, destructor, and formatter live in Error hierarchy documentation.
- Sibling platform wrappers are owned by Error.cpp even when their callers are feature-specific.

Decision: rejected as source owner.

### 3. [UID:00013X] ErrorWrappers aggregate

Evidence for:

- The constructor sits inside the aggregate range.
- Aggregate documents the contiguous executable cluster and source-facing family.

Evidence against:

- The aggregate is broad and intentionally non-emitting.
- Exact constructor child has its own class owner/emitter route.

Decision: use as support/container evidence only; do not emit constructor C++ from the aggregate.

### Proposed new file/grouping, if applicable

No new file or child is needed. Placement remains `NexusTK/util/Error.cpp` with declarations in `util/Error.h`.

## Source Placement

Recommended placement: `WSAError::WSAError()` under the `WSAError` class, emitted through [UID:0000GB] to [UID:0000J5] `NexusTK/util/Error.cpp`.

This placement fits the source tree because the compact `0x004a60d0-0x004a6a76` cluster contains Win32, DirectX, file, WSA, WinINet, message, destructor, and name-helper code for one small Error hierarchy. Feature modules construct these errors but do not own their class implementation.

Rejected placements: Socket/network caller, WSOCK32 import thunk, generated `class_WSAError.cpp` one-class file, and broad aggregate-only emission.

Remaining placement uncertainty: final `Error.h` declaration ordering and exact original member spelling remain inferred, but owner/file/source route is stable.

## Range / Split / Padding / Reclassification Analysis

Exact range facts:

- Target half-open range is `0x004a64a0-0x004a64c5`.
- Function size is `0x25`.
- `0x004a64c4` is the `retn`.
- `0x004a64c5` is outside the function.
- `0x004a64d0` is the separate formatter function, size `0x79`.

Padding/table/data/code distinctions:

- Bytes show `0xcc` padding from `0x004a6499-0x004a649f` before the constructor.
- Bytes show `0xcc` padding from `0x004a64c5-0x004a64cf` before the formatter.
- `0x006193ec` is data/vtable, not code.
- `0x006193f8` is the formatter slot data address, not a code xref target.

Children/subranges:

- No split/merge/new child needed for the constructor.
- Future exact child should cover WSA formatter `0x004a64d0-0x004a6549`.

Parent/container impact:

- The target remains a class-owned exact child.
- The aggregate should be synchronized but remain non-emitting.

## Negative Evidence Summary

Checked and rejected:

- Blank target C++ under old `90/90+`: stale by-structure policy.
- Socket source ownership: sole caller is a throw-site and uses WSAError RTTI.
- Decompiler names/types: `_DWORD *`, `this[1]`, `sub_4A64A0`, and `sub_4F4A80` are not source-quality names.
- Explicit vtable or base helper statements in source: compiler lowering.
- `DWORD m_errorCode`: mismatches `WSAGetLastError` return type and current aggregate `int` type.
- Formatter merge: separate function record and padding.
- Generated output as authority: stale scores and empty marker.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are safe or requested in this report-only pass.

Source-facing names/types recommended for documentation and final source:

- Constructor: `WSAError::WSAError()`.
- Member: `int m_errorCode`.
- Field role: Winsock last-error/status code stored at byte offset `+0x04`.
- Formatter spelling remains future/shared: `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` is the current best common label, but the formatter is outside this target.

Items intentionally left unchanged:

- IDA name `sub_4A64A0`.
- IDA type information.
- IDA comments.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Recommended code, exact formal insertion text:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WSAError::WSAError()
    : m_errorCode(WSAGetLastError())
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior:

- Implicit base construction lowers to `sub_4F4A80`.
- Compiler constructor setup installs the WSAError vtable.
- `WSAGetLastError()` call returns the current Winsock last-error code and initializes the only data field at `+0x04`.
- No explicit destructor, heap, strings, or extra state are present in the target.

Reason it matches plausible original source:

- It is the Winsock analog of the accepted Win32 and DirectDraw one-field error constructors.
- Initializer-list member initialization is the local accepted style for recent source-ready status-code constructors.
- It avoids raw reverse-engineering scaffolding and decompiler temporaries.

Inferred names/types/fields:

- `m_errorCode` is inferred but accepted as the recovered status-code family member name.
- `int` is selected for WSA because `WSAGetLastError` returns `int`.

Reason code should remain blank: not applicable for the constructor. Class-level and aggregate C++ remain blank for separate reasons.

Exact no-code proof: not applicable.

## Final Recommendation

Recommended changes:

- Update target [UID:0002HM] to `90/92`.
- Insert formal constructor C++ exactly as above.
- Preserve `CANONICAL_OWNER:0000GB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000GB`, and blank emitter position.
- Replace stale `90/90+` target-local blocker wording with current gate/source-ready rationale.
- Synchronize WSA class, Error file, ErrorWrappers aggregate, ErrorObjectLayouts, and ErrorHierarchyVtables.

Items left no-owner/non-emitting: none in this target.

Future work outside this assignment:

- Create/source-quality exact child for WSA formatter `0x004a64d0-0x004a6549`.
- Standardize the Error hierarchy `+0x0c` virtual declaration and class/header layout.
- Refresh generated output after accepted by-* implementation.

## Recommended Target Doc Changes

Target path: `by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md`.

Exact facts to incorporate:

- MCP session `80de0a67`, server `ida-pro-mcp`, health ok, IDB `NexusTK.exe.i64`, imagebase `0x400000`.
- `lookup_funcs`: exact `0x25` function, no function at `0x004a64c5`, separate formatter at `0x004a64d0`.
- Decompile/disasm: `sub_4F4A80`, vtable `0x006193ec`, `WSAGetLastError`, `[esi+4]`.
- Caller: sole `0x00577a28` call inside `sub_577890`; allocation size `8`; throw type `__TI4PAVWSAError@@`.
- Bytes: padding before and after; no formatter merge.
- Vtable bytes: WSA row and formatter/name slots.
- Field/type/name decision: `int m_errorCode`.
- Rejected alternatives listed above.

Metadata/code changes:

- `COMPLETION:90`
- `CONFIDENCE:92`
- owner/emitter/reconstructable unchanged.
- Insert formal C++ block:

```cpp
WSAError::WSAError()
    : m_errorCode(WSAGetLastError())
{
}
```

Historical/stale assumptions to preserve as superseded:

- Old `90/90+` gate was the reason blank C++ stayed in the page; current by-structure rule supersedes it.
- Broader formatter/header work remains open but does not block this constructor.

## Recommended Support Doc Changes

Support path: `by-class/WSAError.md`.

- Recommend score `85/86 -> 87/88`, owner/emitter unchanged.
- Update method row for `0x004a64a0` to `WSAError::WSAError()` source-ready exact child, with `int m_errorCode(WSAGetLastError())`.
- Add 2026-06-27 B007 MCP source-ready paragraph with range, vtable store, import, sole socket throw-site, padding, and field decision.
- Replace class Autogen Status stale `90/90+` wording with: class-level C++ remains blank pending formatter/header declaration, but child [UID:0002HM] now emits formal constructor C++.
- Keep formatter `0x004a64d0` unresolved as exact child work.

Support path: `by-file/Error.md`.

- Score unchanged `87/85`.
- Add B007 WSA source-ready sync near Win32/DDError constructor sync entries.
- State [UID:0002HM] now emits `WSAError::WSAError()` with `int m_errorCode` initialized from `WSAGetLastError()`.
- Preserve caveat that this targeted constructor update does not make the whole Error file ready for broad C++.

Support path: `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`.

- Score unchanged `87/89`.
- Update Covered Range row for [UID:0002HM] from "Exact child; captures `WSAGetLastError`" to source-ready exact child with formal C++ and MCP evidence.
- Add evidence bullet for B007 session `80de0a67`.
- Add aggregate coverage bullet that [UID:0002HM] is now source-ready, without making the aggregate source-ready.
- Update source-facing names table to say `int m_errorCode` is now accepted for [UID:0002HM].

Support path: `by-type/by-struct/ErrorObjectLayouts.md`.

- Score unchanged `86/88`.
- Update Stored status code row to include WSA's accepted exact-constructor field `int m_errorCode`.
- Add B007 change/evidence paragraph.
- Narrow open question from "DirectInput, DirectSound, and Winsock" to DirectInput/DirectSound plus exact-original-spelling caveat.

Support path: `by-type/by-vtable/ErrorHierarchyVtables.md`.

- Score unchanged `86/90`.
- Add WSA source-ready constructor sync near Win32/DDError constructor paragraphs.
- Add live constructor-side evidence: constructor at `0x004a64a0`, base setup, WSA vtable store at `0x004a64af`, `WSAGetLastError`, `+0x04 m_errorCode`, one socket caller, vtable bytes with formatter slot `0x004a64d0`.
- Preserve statement that formatter `0x004a64d0` and `+0x0c` declaration remain separate future work.

Sibling constructor docs:

- No edit required. Win32Error and DDError already contain the policy this WSA report follows. They should not be changed.

## Score And Metadata Recommendation

Current target state:

- `COMPLETION:85`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000GB`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000GB`
- blank C++ block

Recommended target state:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000GB` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:0000GB` unchanged
- blank emitter position unchanged
- formal C++ inserted

Reason not higher:

- Exact original field spelling and complete class header are still inferred.
- WSA formatter exact child and shared `+0x0c` declaration are unresolved.
- Generated output is stale until implementation validator refresh.

Score-improvement blockers researched:

- Formal C++ gate: current by-structure gate checked; target clears it.
- Field name/type: checked target/support/sibling docs and live MCP; resolved to `int m_errorCode`.
- Owner/source placement: checked caller, class, file, aggregate, vtable docs; resolved to WSAError/Error.cpp.
- Range/split: checked lookup and bytes; no split/merge needed.
- Caller/xref route: checked sole caller and throw type; Socket rejected as owner.
- Broader hierarchy declaration: researched and narrowed to class-level/formatter future work, not target blocker.

## Open Questions With Attempted Resolution

Open question: exact original member spelling.

- Evidence checked: target, layout, aggregate, Win32/DDError accepted pages, generated output, live MCP.
- Best resolution: use `m_errorCode` as accepted source-facing recovered name.
- Remaining uncertainty: exact source symbol not recovered. Confidence capped below final-audit; no C++ blocker.

Open question: class-level declaration and `+0x0c` virtual spelling.

- Evidence checked: WSA class, Error file, aggregate, vtable page, formatter decompile/string evidence, B013 wide-buffer policy.
- Best resolution: keep class-level C++ blank; child constructor emits.
- Remaining uncertainty: future formatter/header pass required; no constructor score blocker.

Open question: generated output stale.

- Evidence checked: generated `Error.cpp`, generated research tracker, generated memory coverage.
- Best resolution: do not edit generated files manually; refresh through validator after accepted implementation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. No explicit manual coverage-report or supervisor tracker edit was assigned. The stale generated `-ag-*` rows and generated `Error.cpp` should be refreshed by validator-owned generated output after the accepted source docs are updated. Do not manually edit generated reports, generated C++, project-level generated files, manual coverage reports, validator/tool state, or IDA DB.

## Follow-Up Actions

Supervisor actions:

- Validate this report.
- If accepted, send implementation callback allowing target/support by-* edits and leases.
- Execute/move report through the validator lifecycle after acceptance.

A-agent actions: none.

B-agent future research actions:

- Exact/source-quality pass for WSA formatter `0x004a64d0-0x004a6549`.
- Hierarchy-wide declaration pass for `FormatErrorMessage` / `CopyErrorMessage` naming and return type.
- DirectInput/DirectSound raw constructor exact/raw-child pass.

## Confidence

Recommendation confidence: high.

Score confidence: high for `90/92`, with confidence intentionally below `95` because original member/header spelling is inferred.

Remaining uncertainty: class-level declaration and formatter source shape, not constructor behavior.

## Validator Results

Commands run:

- `python source-3/project-documentation/tools/validator.py --help` from workspace root returned command id `000000004007`. This was mode inspection only, not a target validator run.

Results:

- No by-* docs were edited, so no scoped file validator was required in this report-only pass.
- No generated refresh was run.

Validators to run if accepted for implementation:

- From `source-3/project-documentation`, run scoped file validators after the edit batch:
  - `python .\tools\validator.py --mode file --file by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md --apply --lock-timeout -1`
  - `python .\tools\validator.py --mode file --file by-class/WSAError.md --apply --lock-timeout -1`
  - `python .\tools\validator.py --mode file --file by-file/Error.md --apply --lock-timeout -1`
  - `python .\tools\validator.py --mode file --file by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md --apply --lock-timeout -1`
  - `python .\tools\validator.py --mode file --file by-type/by-struct/ErrorObjectLayouts.md --apply --lock-timeout -1`
  - `python .\tools\validator.py --mode file --file by-type/by-vtable/ErrorHierarchyVtables.md --apply --lock-timeout -1`
- Run one scoped generated refresh/check after target C++ insertion, normally by adding `--wait-generated` to the target file validator or by supervisor-approved `--mode autogen --apply`.

Unresolved validator warnings/errors: none from this report-only pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B007/research/0002HM-WSAErrorConstructor-source-quality.md`
- Modified: none outside Agent-B007 report folder.
- Renamed: none.
- Report execution: pending supervisor validation.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted this report for implementation under assignment `B007-implement-0002HM-WSAErrorConstructor-source-quality-20260627`.
- [x] Target/support docs to update: `by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md`, `by-class/WSAError.md`, `by-file/Error.md`, `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`, `by-type/by-struct/ErrorObjectLayouts.md`, and `by-type/by-vtable/ErrorHierarchyVtables.md`. Proof: all six files were edited in the implementation callback and validated with command IDs `000000004044` through `000000004049`.
- [x] Current target state and actual evidence checked recorded: target was `85/89`, owner/emitter [UID:0000GB], blank C++; live MCP session `80de0a67` confirmed exact `0x25` constructor, decompile/disasm, sole socket throw-site, WSA vtable, import, bytes, and padding. Proof: target doc now has a `2026-06-27 B007 MCP Source-Quality Implementation Evidence` section preserving those facts.
- [x] Metadata/score changes to apply: target [UID:0002HM] `85/89 -> 90/92`; [UID:0000GB] `85/86 -> 87/88`; Error file, aggregate, layout, and vtable support scores unchanged. Proof: target header is `COMPLETION:90` and `CONFIDENCE:92`; `by-class/WSAError.md` header is `87/88`; other support docs received evidence-only updates.
- [x] Score-limiting blockers researched to resolution: old `90/90+` gate superseded; field/type resolved to `int m_errorCode`; owner/source route resolved to WSAError/Error.cpp; formatter/header work narrowed to future class-level scope. Proof: target, class, file, aggregate, struct, and vtable docs all state constructor-local C++ is now source-ready while WSA formatter/header declaration remains separate future scope.
- [x] Owner/emitter/reconstructable changes to apply: keep target `CANONICAL_OWNER:0000GB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000GB`, and blank emitter position unchanged. Proof: scoped validator `000000004044` preserved owner/emitter state and refreshed generated rows showing owner/emitter `0000GB`.
- [x] Split/rename/new-child changes to apply: no split/rename/new child for constructor; document future exact child need for WSA formatter `0x004a64d0-0x004a6549`. Proof: no new by-* files were created; WSA formatter separation is documented in target/class/file/vtable support docs.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: document exact padding `0x004a6499-0x004a649f` and `0x004a64c5-0x004a64cf`; no IDA DB changes. Proof: target evidence and support sync preserve padding/range facts; no IDA DB write action was performed.
- [x] First-draft C++ to apply: insert exact formal `WSAError::WSAError() : m_errorCode(WSAGetLastError()) {}` block supplied in this report. Proof: target formal `RECONSTRUCTION_CPP CODE` block contains:
  ```cpp
  WSAError::WSAError()
      : m_errorCode(WSAGetLastError())
  {
  }
  ```
- [x] Third-party import directive to apply or confirm not applicable: not applicable; no `third_party_embeds/...` import, multiline C++ block contains the constructor body. Proof: validator accepted the target C++ block with `ok: 1` and no import directive was added.
- [x] Exact target/support doc facts incorporated at report-level detail: MCP server/session health, lookup/decompile/disasm/xrefs/callees/imports/bytes/caller/vtable facts, source-shape decisions, and rejected alternatives. Proof: target contains the full implementation evidence block; each support doc received WSA-specific sync text for its scope.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: old `90/90+` gate superseded, generated output stale, raw/decompiler code rejected, Socket ownership rejected, formatter merge rejected, `DWORD`/`m_lastError`/`field_4` rejected. Proof: target and support docs preserve these as superseded/rejected alternatives rather than deleting the history.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated one-class files and generated `char *` formatter signatures are lead material only and must not drive final source. Proof: support docs state generated output is lead material and keep class-level/formatter work separate from constructor emission.
- [x] Open questions to close or document as evidence-backed unresolved: original member spelling remains inferred; WSA formatter and shared Error declaration remain future work but not constructor blockers. Proof: unresolved items are documented as class/formatter scope only; constructor-local score/C++ no longer depends on them.
- [x] Validators to run: scoped file validators listed in `Validator Results`; generated refresh/check after target C++ insertion. Proof: final audited validator batch ran from `source-3/project-documentation` with `--wait-generated` and exit code `0` for every changed by-* file.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator-owned generated `Error.cpp`, generated memory coverage, and generated research tracker refreshed; no manual coverage/tracker text supplied. Proof: generated headers for `auto-generated/NexusTK/util/Error.cpp`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-memory-coverage.md` all show `validator-command-id: 000000004049` and `validator-refreshed-at: 2026-06-27T08:55:20-04:00`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback instruction targeted this accepted report and required implementation for [UID:0002HM].
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: edited target plus five support docs named above; no accepted report fact was intentionally omitted.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: target `90/92`, class `87/88`, preserved owner/emitter/reconstructable state, no split/rename/new child, formal constructor C++ inserted.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs record the superseded blank-C++ gate and rejected `DWORD`, `m_lastError`, raw/decompiler, Socket-ownership, and formatter-merge alternatives.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: constructor blockers are closed; WSA formatter/header declaration remains explicitly future class/formatter scope.
- [x] Validators run and results recorded. Proof: final audited scoped validator batch:
  - `python .\tools\validator.py --mode file --file by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004044`, `command_timestamp: 2026-06-27T08:54:29-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-class/WSAError.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004045`, `command_timestamp: 2026-06-27T08:54:39-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-file/Error.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004046`, `command_timestamp: 2026-06-27T08:54:49-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004047`, `command_timestamp: 2026-06-27T08:55:00-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-type/by-struct/ErrorObjectLayouts.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004048`, `command_timestamp: 2026-06-27T08:55:09-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-type/by-vtable/ErrorHierarchyVtables.md --apply --queue-timeout 240 --wait-generated` -> `command_id: 000000004049`, `command_timestamp: 2026-06-27T08:55:20-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. Proof: `auto-generated/NexusTK/util/Error.cpp` header is `validator-command-id: 000000004049`, `validator-refreshed-at: 2026-06-27T08:55:20-04:00`, and contains `// UID:0002HM ... Completion:90 | Confidence:92` plus the emitted `WSAError::WSAError()` / `m_errorCode(WSAGetLastError())` constructor. `auto-generated/-ag-coverage-report-by-memory.md` has the same header and row [UID:0002HM] at `90% : very-strong`; `auto-generated/-ag-research-tracker.md` has the same header and row `90/92`; `auto-generated/-ag-memory-coverage.md` has the same header and row `coded | 0000GB | 0000GB | ... Error.cpp`.
- [x] Leases used and released. Proof: first B007 edit lease batch for the six by-* files succeeded before resume and had no active B007 lease by the resume check. For the final validator batch, B007 reacquired all six leases at `2026-06-27T12:52:19Z`, released all six successfully immediately after validators, and the post-release `current_leases.md` check showed no B007 rows.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none; all accepted details are applied or documented as not applicable/future non-blocking scope, with no remaining implementation blocker.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002HM-WSAErrorConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002HM-WSAErrorConstructor-source-quality.md","timestamp":"2026-06-27T08:59:57","uid":"0002HM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
