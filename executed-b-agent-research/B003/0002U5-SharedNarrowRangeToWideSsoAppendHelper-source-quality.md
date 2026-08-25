** TARGET-REPORT-UID:0002U5 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0002U5] SharedNarrowRangeToWideSsoAppendHelper Source-Quality Report

Assignment: `B003-report-0002U5-shared-narrow-range-to-wide-sso-append-helper-20260624`

Agent: B003

Report path: `tools/leaser/Agents/Agent-B003/research/0002U5-SharedNarrowRangeToWideSsoAppendHelper-source-quality.md`

Target: [UID:0002U5] `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`

Status: accepted implementation callback completed. The target and required support by-* docs were updated and validated; manual coverage remains supervisor-owned.

## Finalized Report / Current Recommendation

Implementation result: [UID:0002U5] is raised from `85/88` to `87/90`, the exact range and direct owner/emitter route are unchanged, and the formal `RECONSTRUCTION_CPP CODE` block remains blank with a current target-specific no-code proof.

Metadata recommendation:

| Field | Before | Implemented |
| --- | --- | --- |
| `COMPLETION` | `85` | `87` |
| `CONFIDENCE` | `88` | `90` |
| `CANONICAL_OWNER` | `0000D9` | keep `0000D9` |
| `RECONSTRUCTABLE` | `TRUE` | keep `TRUE` |
| `EMITTER_UIDS` | `0000D9` | keep `0000D9` |
| `EMITTER_POSITION_OPTIONAL` | blank | keep blank |
| `RECONSTRUCTION_CPP CODE` | blank | keep blank |

Current MCP session `80de0a67` resolves the old score blockers enough to move above `85`: exact `0x1a4` / 420-byte function range, SHA16 `7cd41a67bc199b3f`, four-byte predecessor padding, twelve-byte successor padding, two direct code xrefs, no data xrefs, no absolute VA/RVA pointer route, exact caller sites, paired reserve helper behavior at `0x00423eb0`, allocation helper behavior at `0x00423d00`, cleanup/error callees, and the SSO-7 field model are all refreshed with live IDA MCP evidence.

The formal C++ block should remain blank. This is not a deferred blocker: the current pass investigated the signature/source-shape blocker and found that `0x00423060` is an internal range/tag append loop, not a stable standalone source-facing method. The binary ABI is `retn 0x0c`: two semantic source-range arguments plus a third stack argument that is never read. The two direct callers push different values for that unused third argument, which is consistent with a compiler/template helper or iterator-category/tag artifact, not a hand-authored public method signature. Emitting a formal source block for this exact target would harden a synthetic helper signature that is less source-faithful than the already documented higher-level source expressions such as `SimpleUString` ANSI/range assignment in the caller pages.

## Executive Result

The accepted documentation/source-quality lift has been applied:

- target metadata is `87/90`;
- owner/emitter [UID:0000D9] `SimpleUString`, reconstructable `TRUE`, blank emitter position, and blank formal C++ are preserved;
- stale pending-C++ wording in the target body is superseded by current MCP-backed no-code proof;
- directly affected support docs are synchronized;
- no child pages were created and no standalone C++ was emitted for [UID:0002U5];
- manual coverage application remains supervisor-owned.

The target now clears the score/source-quality blocker because current MCP evidence resolves range, liveness, xrefs, helper dependencies, owner/emitter, source placement, and rejected alternatives. It does not clear formal C++ readiness because the exact helper ABI is a compiler/template-like internal range/tag body with an unused third stack argument, not a stable public `SimpleUString` source method.

## Supervisor Active Recheck

I read `tools/leaser/Agents/Agent-B003/goal.md` and used the project-level `ntk-b-agent-workflow` skill. The accepted implementation callback is complete. B003 waited for the B005 aggregate lease to expire, leased the exact five by-* docs for the edit/validator batch, and final lease cleanup found no active leases because the short leases had expired; `current_leases.md` was empty afterward.

MCP was available throughout this pass. Session `80de0a67` was confirmed with `idb_list` and `server_health` before target-specific calls. The evidence pass used bounded `lookup_funcs`, `func_profile`, `xrefs_to`/`xref_query`, `callees`, `decompile`, `disasm`, `get_bytes`, `find_bytes`, and `int_convert` calls. No broad/heavy scan was needed after the targeted calls resolved the score blockers.

Current target state was re-read before implementation. The docs already contained the correct owner/emitter route and main behavior, but they presented C++ as pending because the target had not had an accepted pass. This implementation replaces that pending body text with an accepted state: raised score, preserved exact owner/range, and formal C++ kept blank with proof. The validator normalizes the top `Item Summary` from project summary state until supervisor-owned coverage is applied; the detailed target body and metadata carry the accepted implementation facts.

## Inference Research Guidance Check

Direct facts in this report are MCP-backed function/range, disassembly, decompilation, xrefs, caller windows, callee/helper behavior, byte hashes, padding, and negative pointer/data checks. Current by-* docs are used as support context for owner/emitter and source-family decisions, not as replacements for MCP evidence.

The report does not use lack of original symbols as an excuse to retain IDA labels. It chooses source-facing prose names around `SimpleUString`, SSO-7 storage, narrow-range append, reserve, and wide-storage allocation. It also rejects exact formal C++ because a human-source method body cannot be represented faithfully for this ABI without exposing a synthetic third unused argument or pretending the target contains a higher-level wrapper it does not contain.

Any C++ recommendation would have to be exact formal `RECONSTRUCTION_CPP CODE` insertion text. This report supplies no target C++ body and instead supplies exact blank formal block disposition plus target-specific no-code proof.

## Target State Before This Report

The target is already correctly split as the exact half-open range `0x00423060-0x00423204`. The current page records the main SSO-7 behavior, the direct [UID:0000D9] `SimpleUString` owner, broad [UID:0000OB] `StringUtil` source root, two callers, `0x00423eb0` pre-reserve use, `0x00423d00` allocation, `0x00421310` cleanup, and surrounding padding.

The stale part is the C++ disposition wording. The page says the formal block is blank because [UID:0002U5] has not had its own accepted pass and because its exact source signature/name still need target-specific acceptance. This report performs that pass. The result is a stronger blank-C++ policy, not a future-pending C++ question.

Current generated state:

- `auto-generated/-ag-research-tracker.md` lists [UID:0002U5] as `85/88`, reconstructable, not-covered.
- `auto-generated/-ag-coverage-report-by-memory.md` lists `emits_code:false`.
- `auto-generated/NexusTK/util/StringUtil.cpp` has an empty emitter marker for [UID:0002U5], while sibling SSO methods [UID:0002DV] `SimpleUString::Clear()` and [UID:0002E3] `SimpleUString::Assign(...)` emit formal C++.
- Manual `by-memory/-coverage-report.md` has the old `85% : strong` row.

## Documents Checked

Current by-* and support documents checked:

- `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`
- `by-class/SimpleUString.md`
- `by-file/StringUtil.md`
- `by-type/by-struct/SimpleUStringSso7Layout.md`
- `by-memory/0x00421310-0x00421362.SimpleUStringClear.md`
- `by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md`
- `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md`
- `by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md`
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
- `by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md`
- `by-memory/-ignored.md`
- `auto-generated/NexusTK/util/StringUtil.cpp`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-research-tracker.md`
- `by-memory/-coverage-report.md` read only
- executed reports for [UID:0002E3], [UID:0002DV], and [UID:0002EE] as history/leads only

No Wave2/Wave3 material or old generated rows were used as authority over current docs and current MCP evidence.

## IDA MCP Evidence

MCP provenance:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active database/session: `80de0a67`
- `idb_list`: one active owned worker for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, `is_analyzing:false`.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Tool schema rechecked with `tools/list`. Relevant active schemas: `lookup_funcs` uses `queries`, `decompile` and `disasm` use `addr`, `xrefs_to` uses `addrs`, `xref_query` uses `queries`, `callees` uses `addrs`, and `get_bytes` uses `regions`.

Function and boundary facts:

- `lookup_funcs`:
  - `0x00423060` -> `sub_423060`, size `0x1a4`.
  - `0x004231f6` -> inside `sub_423060`, same size.
  - `0x00423203` -> inside `sub_423060`, same size.
  - `0x00423204` -> not a function.
  - `0x00423210` -> `sub_423210`, size `0x1da`, confirming the next modeled helper begins after padding.
- `int_convert`:
  - `0x1a4` -> decimal `420` (Verified with `int_convert`).
  - `0x18` -> decimal `24` (Verified with `int_convert`).
  - `0x10` -> decimal `16` (Verified with `int_convert`).
  - `0x14` -> decimal `20` (Verified with `int_convert`).
  - `0x0c` -> decimal `12` (Verified with `int_convert`).
  - `0x7ffffffe` -> decimal `2147483646` (Verified with `int_convert`).
  - `0x1000` -> decimal `4096` (Verified with `int_convert`).
  - `0x23` -> decimal `35` (Verified with `int_convert`).
  - `0x1f` -> decimal `31` (Verified with `int_convert`).
- `get_bytes`:
  - `0x0042305c-0x00423060`: four `0xcc` bytes.
  - `0x00423060-0x00423204`: 420-byte function body, SHA-256 `7cd41a67bc199b3f2a6b3f087de5d5c9880670126a9526bf6394af34bd7661e1`, SHA16 `7cd41a67bc199b3f`.
  - First 32 target bytes: `55 8b ec 6a ff 68 90 6d 5f 00 64 a1 00 00 00 00 50 83 ec 18 53 56 57 a1 24 2f 67 00 33 c5 50 8d`.
  - Last 32 target bytes: `e5 5d c2 0c 00 e8 e2 84 ff ff e8 14 a4 1a 00 8b 4d dc e8 15 e1 ff ff 6a 00 6a 00 e8 06 70 1a 00`.
  - `0x00423204-0x00423210`: twelve `0xcc` bytes.

Function profile and call graph:

- `func_profile 0x00423060` reports:
  - 149 instructions.
  - 25 basic blocks.
  - 2 caller functions.
  - 10 profile callees including SEH/security-cookie support.
  - 0 string references.
  - prototype recovery `char *__thiscall(_DWORD *Src, char *, char *, int)`.
- Profile callers:
  - `0x00421a40 sub_421A40`
  - `0x00581cf0 sub_581CF0`
- Profile/callee evidence:
  - `0x00423d00 sub_423D00` allocation helper.
  - `_memmove`.
  - `0x005c7526 sub_5C7526` free wrapper.
  - `0x0041b6d0 sub_41B6D0` string-too-long/error helper.
  - `__invalid_parameter_noinfo_noreturn`.
  - `0x00421310 sub_421310` cleanup helper.
  - `__CxxThrowException@8`, `@__security_check_cookie@4`, and `___CxxFrameHandler3` as EH/security support.

Xref and negative-route evidence:

- `xref_query` to `0x00423060`:
  - code refs total `2`.
  - data refs total `0`.
- Code refs:
  - `0x00421bc5` in `0x00421a40 sub_421A40`, the fitting-room catalog entry parser.
  - `0x00581d22` in `0x00581cf0 sub_581CF0`, the startup ANSI-range to SSO-7 wide-string conversion helper.
- `find_bytes` for absolute VA pattern `60 30 42 00`: `0` matches.
- `find_bytes` for RVA pattern `60 30 02 00`: `0` matches.
- Interpretation: there is no data, vtable, callback-table, or pointer-table route for this exact helper. It is reached by two direct code calls and exists as a shared inline/template-style utility helper.

## Decompilation And Disassembly Interpretation

IDA decompilation for `0x00423060` shows the following semantic behavior:

- `ecx` is the SSO-7 destination object.
- Stack argument 0 is the narrow input cursor/begin pointer.
- Stack argument 1 is the narrow input end pointer.
- Stack argument 2 is present in the ABI but unused by the function body.
- The loop runs until begin equals end.
- Each input byte is read with `movsx ax, byte ptr [eax]`, so the source byte is sign-extended before being stored as a UTF-16 code unit.
- The method reads current length at `this + 0x10` and capacity at `this + 0x14`.
- If length is below capacity, it writes the widened code unit at `storage[length]`, writes the following UTF-16 NUL, increments length, and advances the input pointer.
- If length has reached capacity, it checks the `0x7ffffffe` maximum, computes `(length + 1) | 7`, applies a 1.5x old-capacity growth candidate, allocates a `(newCapacity + 1)` wide-character buffer through `0x00423d00`, copies old content with `_memmove`, appends the widened character and terminator, frees old heap storage when prior capacity was at least `8`, stores the new heap pointer, and advances the input pointer.
- The normal exit returns the final input pointer in `EAX` and uses `retn 0x0c`.

Disassembly anchors:

- `0x4230a0 cmp eax, [ebp+arg_4]` / `0x4230a3 jz loc_4231D5`: half-open begin/end loop.
- `0x4230a9 movsx ax, byte ptr [eax]`: sign-extend narrow byte into a 16-bit value.
- `0x4230ad mov ebx, [esi+10h]`: length at `+0x10`.
- `0x4230b0 mov ecx, [esi+14h]`: capacity at `+0x14`.
- `0x4230c6 mov [esi+10h], eax`: fit-path length increment.
- `0x4230cb cmp ecx, 8`: inline/heap threshold.
- `0x4230d4 mov [eax+ebx*2], dx` and `0x4230d8 mov [eax+ebx*2+2], cx`: append UTF-16 code unit and terminator.
- `0x4230e6-0x42312f`: string-too-long check, `| 7` capacity floor, 1.5x growth check, `0x7ffffffe` saturation, and allocation call.
- `0x42312f call sub_423D00`: allocation helper.
- `0x42313e mov [esi+10h], ecx` and `0x423141 mov [esi+14h], edi`: update length and capacity for grown storage.
- `0x423150 call _memmove`: heap old-content copy.
- `0x423179 cmp ..., 1000h`, `0x42317e add ..., 23h`, `0x423186 cmp ..., 1Fh`: large-allocation header validation.
- `0x42318f call sub_5C7526`: old heap release.
- `0x4231ae call _memmove`: inline old-content copy into newly allocated heap storage.
- `0x4231e6 retn 0Ch`: three stack arguments cleaned by the callee.
- `0x4231f6 call sub_421310`: cleanup helper on exception path.

The target is not a constructor and not a counted UTF-16 assignment method. It appends a narrow byte range into an existing SSO-7 object and widens one byte at a time. Because callers reserve and/or initialize the destination before invoking it, the source-level expression is better represented as an internal append/range-conversion helper under a higher-level `SimpleUString` ANSI/range assignment operation.

## Caller Evidence

### FittingRoom Catalog Parser Caller

`0x00421a40 sub_421A40` is documented by [UID:0002E4] as `FittingRoomCatalogEntry::LoadFromJson`. The current formal source already uses a higher-level `SimpleUString` ANSI/range assignment expression for the item name path.

The MCP caller window around the target call:

- `0x421b86-0x421baa`: chooses the `std::string`/small-string source storage and computes begin/end.
- `0x421b90`: initializes the temporary SSO-7 destination length to `0`.
- `0x421b9a`: initializes destination capacity to `7`.
- `0x421baf`: writes the destination inline UTF-16 NUL.
- `0x421bb7 push eax`, `0x421bb8 call sub_423EB0`: reserves the exact narrow source length.
- `0x421bbd push [ebp+var_4C]`: pushes the unused third stack argument. In this caller it is the Json value/context pointer.
- `0x421bc3 push esi` and `0x421bc4 push edi`: pushes source end and source begin.
- `0x421bc5 call sub_423060`: appends/converts the range.
- `0x421bce-0x421be3`: chooses inline/heap wide storage and copies it into the fixed `wchar_t name[0x50]` destination with `_wcscpy_s`.

Important source-shape implication: the third argument is not semantically consumed by the target. This caller pushes a value that belongs to the surrounding parser context, not a meaningful append parameter.

### Startup Conversion Helper Caller

`0x00581cf0 sub_581CF0` is the startup update-check ANSI-range-to-SSO-7-wide helper documented inside [UID:0001IO].

MCP disassembly/decompilation:

- `0x581d00`: writes destination length `0` at `+0x10`.
- `0x581d07`: writes destination capacity `7` at `+0x14`.
- `0x581d0e`: writes inline UTF-16 NUL.
- `0x581d13-0x581d16`: computes `end - begin` and calls `0x00423eb0` to reserve.
- `0x581d1b push [ebp+arg_4]`: pushes the unused third stack argument. In this caller it duplicates the end pointer.
- `0x581d20 push edi` and `0x581d21 push esi`: pushes source end and source begin.
- `0x581d22 call sub_423060`.
- `0x581d29 mov eax, ebx`, `0x581d2d retn 0Ch`: wrapper returns the destination object pointer.

The two callers use the same semantic begin/end range and same reserve helper but push different unused third values. That is the strongest current proof that the exact target's formal C++ block should not expose a normal three-argument source method.

## Connected Helper Investigation

This report does not leave the allocator/reserve helper issue as a future blocker. The connected helpers were investigated in this pass.

`0x00423d00` allocation helper:

- `lookup_funcs 0x00423d00` -> `sub_423D00`, size `0x60`.
- `decompile 0x00423d00`: takes a wide-character capacity/count argument, computes `2 * count`, calls `operator new`, uses the same large-allocation convention for sizes at or above `0x1000`, over-allocates by `0x23`, aligns to a 32-byte boundary, stores the raw pointer at `aligned[-1]`, and returns the aligned pointer.
- `callees 0x00423d00`: `operator new(uint)` and `__invalid_parameter_noinfo_noreturn`.
- `xref_query 0x00423d00`: 9 code callers, 0 data xrefs. Callers include this target at `0x42312f`, the reserve helper at `0x423f2b`, and seven other string/helper functions.
- Interpretation: this is shared SSO/string wide-storage allocation support. It is a dependency, not the direct owner of [UID:0002U5].

`0x00423eb0` reserve/capacity helper:

- `lookup_funcs 0x00423eb0` -> `sub_423EB0`, size `0x16f`.
- `func_profile 0x00423eb0`: 131 instructions, 24 basic blocks, 2 caller functions, 6 callees, 0 strings, prototype `void __thiscall(void **this, unsigned int)`.
- `xref_query 0x00423eb0`: two code refs, 0 data refs. The callers are the same two functions that call [UID:0002U5]: `0x421bb8` and `0x581d16`.
- `decompile 0x00423eb0`: reserves requested capacity for the same SSO-7 object, grows via `0x00423d00`, copies existing content, optionally moves heap content back to inline storage when requested capacity drops below `8`, and frees old heap storage through `0x005c7526` with large-allocation header validation.
- Interpretation: this is the reserve/capacity companion to [UID:0002U5]. It helps explain the source-level higher-level operation, but it also reinforces that [UID:0002U5] is only one compiler/helper half of a range-conversion sequence.

Adjacent helper-pocket inventory:

- `lookup_funcs` confirms additional uncovered modeled helpers in `0x00423c3d-0x00424020`: `0x00423c40` size `0xf`, `0x00423c50` size `0xa6`, `0x00423d00` size `0x60`, `0x00423e00` size `0x3d`, and `0x00423eb0` size `0x16f`, followed by `0x00424020`.
- This pocket is outside [UID:0002U5]'s exact target range. It should not be merged into [UID:0002U5] and is not required before applying the target score/no-code recommendation.
- Current [UID:0002U5] improvement is not blocked by the absence of exact child pages for those adjacent helpers because their behavior was directly checked with MCP here. Creating exact pages for the broader uncovered pocket would be a separate coverage-repair package, not a prerequisite for this target's source-quality disposition.

## Heuristic / Inference Reanalysis

### Owner And Emitter Route

Accepted owner/emitter route remains [UID:0000D9] `SimpleUString`, emitted through [UID:0000OB] `StringUtil`.

Evidence for [UID:0000D9]:

- The target operates on the 24-byte SSO-7 object layout: heap/inline union at `+0x00`, length at `+0x10`, capacity at `+0x14`, inline capacity `7`, heap threshold `8`.
- It uses the same capacity/growth/allocation/free policy as formal sibling [UID:0002E3] `SimpleUString::Assign(...)`.
- It calls formal sibling [UID:0002DV] `SimpleUString::Clear()` on the exception cleanup path.
- Its two callers are from unrelated feature modules, FittingRoom and StartupWindow, which rejects caller-local ownership.
- [UID:0000D9] is already the direct SSO-7 class/facade page and [UID:0000OB] is the current `NexusTK/util/StringUtil.cpp` source root.

Rejected owner/source alternatives:

- [UID:0000JE] `FittingRoom` / [UID:000051] `FittingRoomDialogItemState`: rejected because only one caller is fitting-room-local; the startup update-check helper also calls the target directly.
- [UID:0000O5] `StartupWindow`: rejected because startup is the second consumer, not the class owning the string fields and storage policy.
- [UID:0000OA] `StringBase`: rejected because this target uses the SSO-7 inline object, not the later pointer-backed/ref-counted `StringBase` layout.
- [UID:0002EE] fitting-room physical aggregate: rejected because the physical island is a mixed address container and current docs already treat it as non-emitting/mixed.
- Runtime/MSVC allocator/free/error helpers: rejected because `operator new`, `_memmove`, `0x005c7526`, `0x0041b6d0`, and invalid-parameter calls are dependencies, not semantic owner evidence.
- No-owner/non-emitting route: rejected for metadata because the body is a live shared string helper with exact direct callers and must be represented through the string utility source family. Accepted only for formal C++ block output, where the target-specific no-code proof applies.

### Source-Facing Names

Best documentation/source-facing role for the exact target: internal `SimpleUString` SSO-7 narrow-range append/grow helper. The existing page title `SharedNarrowRangeToWideSsoAppendHelper` remains acceptable as a by-memory descriptive filename.

Preferred prose names:

- `SimpleUString` SSO-7 narrow-to-wide append helper.
- narrow byte range to UTF-16 append/grow helper.
- internal append half of an ANSI/range assignment or conversion sequence.

Names rejected as final target-source names:

- `FittingRoomEntryPartVectorGrowCopy`: stale historical name; the body is string conversion and has a startup caller.
- `AssignAnsi`: too high-level for this exact target because the function does not initialize or reserve; the callers do those steps separately.
- `AppendAnsiRange` as a formal method block: plausible for prose, but unsafe as formal code because the exact ABI includes an unused third argument and `retn 0x0c`.
- `StringBase` or pointer-backed string names: wrong layout.
- `sub_423060`, `dword`/IDA labels, or synthetic argument names: not source-facing.

### Split / Range Decision

No split or rename is recommended for [UID:0002U5]. The target is exactly one modeled IDA function:

- half-open function range `0x00423060-0x00423204`;
- predecessor padding `0x0042305c-0x00423060`;
- successor padding `0x00423204-0x00423210`;
- no interior data pocket, padding, child function, jump table, or vtable cell.

The broader adjacent helper pocket after `0x00423c3d` has uncovered functions, but it is outside this target and should not be merged into this page.

## Formal C++ / No-Code Disposition

Recommended formal block: keep blank.

Exact target no-code proof:

1. The binary function has a three-stack-argument ABI (`retn 0x0c`), but only the first two stack arguments are read. The third argument is not part of the semantic append operation.
2. The two direct callers push different unused third values: the fitting-room caller pushes its surrounding Json/parser context pointer, while the startup helper pushes a duplicate end pointer. This is not a stable hand-authored source signature.
3. The function is only the append loop. It assumes the destination has already been initialized and usually pre-reserved by `0x00423eb0`; it does not represent a complete source-level `AssignAnsi` or constructor operation.
4. The source-faithful caller representation is a higher-level ANSI/range conversion operation on `SimpleUString`, already reflected in [UID:0002E4]'s formal caller code. Emitting a separate three-argument helper method would make the reconstructed source less human-authored and more decompiler-shaped.
5. The function contains compiler/EH/security-cookie scaffolding and an exception cleanup landing path through `SimpleUString::Clear()`. That cleanup relationship belongs in evidence/no-code proof, not in a hand-written standalone helper body.
6. The allocator/reserve blockers were investigated in this pass: `0x00423d00` and `0x00423eb0` are understood enough to support behavior, but they do not turn [UID:0002U5] into a stable public/source-facing method.

Formal target insertion text if accepted:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

No first-draft C++ body is supplied for [UID:0002U5]. Supplying a body would violate the current formal-C++ rule because the only honest implementation would expose a synthetic third parameter or hide the ABI mismatch behind a source wrapper that this exact target does not contain.

## Score Rationale

| Score | Recommendation | Rationale |
| --- | ---: | --- |
| Completion | `87` | Current MCP evidence resolves the old own-pass blocker: exact range, SHA16, padding, direct xrefs, no data/pointer route, caller windows, SSO-7 fields, sign-extended narrow-to-wide append behavior, paired reserve helper, allocator helper, cleanup/error/free callees, source route, rejected owners, and blank-C++ no-code proof are all documented. It stays below `88` because no formal C++ block is safe for this exact internal range/tag helper and the adjacent reserve/allocation helpers do not yet have exact by-memory support pages. |
| Confidence | `90` | Decompilation, disassembly, caller windows, xref queries, byte hashes, sibling formal SSO methods, and support docs agree on behavior and owner. Confidence remains below final because original source spelling for the internal helper/tag path is not recoverable and the exact source ABI should not be frozen as C++. |

This is a real improvement over `85/88`: the report closes the old C++/source-shape question and replaces "not yet accepted" with a durable no-code proof. The score does not rise higher because the target is intentionally not a source-facing formal method block.

## Applied Target Doc Changes

Applied to `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`:

- Set `COMPLETION:87`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000D9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D9`, blank emitter position, and blank formal C++ block.
- Replace stale "has not had its own accepted C++ pass" wording with current MCP session `80de0a67` evidence and the accepted blank-C++/no-code policy.
- Add exact byte/range facts: 420-byte body, SHA-256 `7cd41a67bc199b3f2a6b3f087de5d5c9880670126a9526bf6394af34bd7661e1`, SHA16 `7cd41a67bc199b3f`, first/last bytes, four-byte predecessor padding, twelve-byte successor padding.
- Add function profile facts: 149 instructions, 25 basic blocks, 2 callers, 0 strings, profile prototype with three stack args.
- Add current xref facts: code refs at `0x00421bc5` and `0x00581d22`, 0 data refs, no VA/RVA pointer patterns.
- Add decompilation/disassembly behavior at report-level detail: sign-extension of input byte, half-open range loop, `+0x10/+0x14` length/capacity, inline threshold `8`, inline capacity `7`, `0x7ffffffe` cap, `(length + 1) | 7` growth, 1.5x capacity check, `0x00423d00` allocation, `_memmove`, `0x1000`/`+0x23`/`0x1f` large-allocation validation, `0x005c7526` free, `0x00421310` cleanup path, `retn 0x0c`.
- Add caller-specific proof that the unused third stack argument is not source-facing.
- Preserve and update rejected alternatives: fitting-room/starter local owner, `StringBase`, runtime/MSVC, no-owner, aggregate owner, `AssignAnsi` formal target method, stale `FittingRoomEntryPartVectorGrowCopy`, and decompiler labels.

## Applied Support Doc Changes

Required support updates applied:

1. `by-class/SimpleUString.md`
   - Update the [UID:0002U5] method-family/evidence entry to current session `80de0a67`.
   - Record that [UID:0002U5] remains a direct SSO-7 `SimpleUString` child but is intentionally blank-C++ because it is an internal range/tag append helper with an unused third stack argument.
   - Preserve the sibling distinction: [UID:0002DV] and [UID:0002E3] emit formal child C++; [UID:0002U5] does not.
   - No class metadata score change was applied.

2. `by-file/StringUtil.md`
   - Update the SSO-7 helper entry to record [UID:0002U5] current MCP facts, source-root route through `NexusTK/util/StringUtil.cpp`, and the blank-C++ no-code policy.
   - Keep `StringUtil` as broad source root and reject direct `FittingRoom`, `StartupWindow`, `StringBase`, runtime/MSVC, or physical aggregate ownership.
   - No file metadata score change was applied.

3. `by-type/by-struct/SimpleUStringSso7Layout.md`
   - Add [UID:0002U5] as the current proof that the same `+0x00/+0x10/+0x14` SSO-7 layout supports narrow-byte to UTF-16 append/grow.
   - Record sign-extension of source bytes and the same allocator/free policy.
   - Note that formal code remains blank for the target because the exact helper has an internal unused tag/third-argument ABI.
   - No layout metadata score change was applied.

4. `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md`
   - Updated the [UID:0002U5] child row/change note from `85/88` to `87/90`.
   - Record the current MCP session facts and preserve the rejection of the mixed aggregate as direct owner.
   - No aggregate metadata score change was applied.

Already-present / no required support edit:

- `by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md` already represents the source-level caller operation as a higher-level `SimpleUString` ANSI assignment before `_wcscpy_s`; no edit was required.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` already identifies `0x00581cf0` as the startup ANSI-range to wide-string helper; no edit was required.
- `by-memory/-ignored.md` already records the two padding spans that border [UID:0002U5] inside the fitting-room helper island; no edit required.
- No child page creation is required for [UID:0002U5]. The connected `0x00423d00`/`0x00423eb0` helpers were investigated with MCP and should not be merged into this target. Exact pages for the broader `0x00423c3d-0x00424020` helper pocket would be a separate coverage-repair package, not a prerequisite for this target recommendation.

## Supervisor-Owned Coverage Text

B003 must not edit any `-coverage-report.md` file. After supervisor verifies this implementation, replace the existing [UID:0002U5] manual row in `by-memory/-coverage-report.md` with:

```text
            - [UID:0002U5][0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper](by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md) 0x00423060-0x00423204 | helper-function | SharedNarrowRangeToWideSsoAppendHelper : reconstructable : 87% : very-strong : B003 MCP session `80de0a67` confirms exact `0x1a4` / 420-byte body, SHA16 `7cd41a67bc199b3f`, four-byte predecessor and twelve-byte successor padding, two direct code xrefs at `0x00421bc5`/`0x00581d22`, no data/VA/RVA pointer route, SSO-7 `+0x10/+0x14` length/capacity, sign-extended narrow-byte to UTF-16 append/grow loop, paired reserve helper `0x00423eb0`, allocator `0x00423d00`, cleanup `0x00421310`, and accepted blank formal C++ / no-code policy because the exact body is an internal range/tag append helper rather than a stable standalone source method.
```

Generated coverage and research tracker rows should be refreshed by validators/executed-report tooling only. Do not manually edit `auto-generated/-ag-*` files.

## Validator Results

Scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc. All exited `0` with `ok: 1`.

| File | command_id | command_timestamp | Exit | ok | Warnings / side effects |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md` | `000000000470` | `2026-06-24T15:08:01-04:00` | `0` | `1` | `completion_update:1`, `confidence_update:1`, `insert_header_blank:1`, `reference_index_add:1`, `stats_row_remove:1`, `stats_rescore_recommended:1`, `projected_stats_update:1`, `generated_refresh: deferred`. |
| `by-class/SimpleUString.md` | `000000000471` | `2026-06-24T15:08:09-04:00` | `0` | `1` | `uid_link_insert:5`, `stats_row_update:4`, `projected_stats_update:1`, `generated_refresh: deferred`. |
| `by-file/StringUtil.md` | `000000000472` | `2026-06-24T15:08:20-04:00` | `0` | `1` | `uid_link_insert:2`, `stats_incremental_noop:1`, `projected_stats_update:1`, `generated_refresh: deferred`. |
| `by-type/by-struct/SimpleUStringSso7Layout.md` | `000000000473` | `2026-06-24T15:08:29-04:00` | `0` | `1` | `uid_link_insert:1`, `reference_index_add:1`, `stats_row_update:1`, `projected_stats_update:1`, `generated_refresh: deferred`. |
| `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md` | `000000000474` | `2026-06-24T15:08:36-04:00` | `0` | `1` | `uid_link_insert:4`, `stats_row_update:2`, `projected_stats_update:1`, `generated_refresh: deferred`. |
| `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md` final rerun after target wording correction | `000000000477` | `2026-06-24T15:09:32-04:00` | `0` | `1` | `insert_header_blank:1`, `stats_incremental_noop:1`, `projected_stats_update:1`, `generated_refresh: deferred`. |

Validator side effects were limited to normal `--apply` UID-link/reference/stat refreshes reported above. No manual `-coverage-report.md` edit was made; the exact supervisor-owned row remains in this report.

## Open Questions Closed Or Remaining

Closed in this report:

- Raw/helper liveness: [UID:0002U5] is a modeled function with two direct code callers, not a raw no-route island.
- Pointer/data route: current MCP found no data xrefs and no VA/RVA pointer bytes.
- Owner/emitter: direct [UID:0000D9] `SimpleUString` route remains strongest and clears the current gate.
- C++ readiness: formal C++ is not safe for this exact target; this is now a target-specific no-code proof, not a pending investigation.
- Helper blocker: `0x00423d00` and `0x00423eb0` were investigated with MCP and incorporated into the source-shape decision.

Evidence-backed remaining caveats:

- Exact original internal helper spelling is unrecoverable from current IDB evidence.
- The broader `0x00423c3d-0x00424020` helper pocket has uncovered modeled functions, but those functions are outside [UID:0002U5] and do not affect this target's accepted owner/range/no-code decision.
- The complete `SimpleUString` public API relationship to pointer-backed `StringBase` remains a class-level caveat; it does not block this target's direct SSO-7 owner route.

## Changed Files During Implementation

- `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`: updated to `87/90`, kept owner/emitter `0000D9`, blank emitter position, and blank formal C++; added current MCP evidence and target-specific no-code proof.
- `by-class/SimpleUString.md`: synchronized the [UID:0002U5] method-family/evidence text and blank-C++ policy; metadata unchanged.
- `by-file/StringUtil.md`: synchronized the SSO-7 helper/source-root route and rejected owner alternatives; metadata unchanged.
- `by-type/by-struct/SimpleUStringSso7Layout.md`: added [UID:0002U5] as current narrow-byte to UTF-16 append/grow layout proof; metadata unchanged.
- `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md`: updated [UID:0002U5] child inventory and mixed-aggregate routing notes to `87/90`; metadata unchanged.
- `tools/leaser/Agents/Agent-B003/research/0002U5-SharedNarrowRangeToWideSsoAppendHelper-source-quality.md`: updated implementation checklist, validator results, and lease status.

Optional caller pages `by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md` and `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` were read/checked but not edited. They already preserve the higher-level caller source operations needed for this target.

No manual coverage report edit was made. A pre-existing dirty worktree includes `by-memory/-coverage-report.md` and generated coverage state unrelated to this B003 manual edit; these were not touched by this report/implementation except for validator-reported normal stats/projected refresh side effects.

Lease status: initial `current_leases.md` showed B005 holding the overlapping aggregate until `2026-06-24T19:02:18Z`; B003 waited and rechecked at `2026-06-24T19:02:42Z`. B003 then leased the exact five changed by-* docs successfully. Final cleanup command `python .\tools\leaser\leaser.py Agent-B003 unlease ...` returned `Rejected[No active lease]` for each file because the short leases had already expired; `current_leases.md` was empty at that release check. A later final check showed only an unrelated B006 lease on sibling `by-memory/0x00423210-0x004233ea.FittingRoomEntryPartVectorGrowInsert.md`; there are no active B003 leases.

## Implementation Tracking Checklist

- [x] `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`: updated metadata to `COMPLETION:87`, `CONFIDENCE:90`; kept owner/emitter/reconstructable/blank emitter position and blank formal C++; added current MCP session `80de0a67`, range/bytes/SHA/padding, xref/no-data/no-pointer evidence, profile/decompile/disassembly facts, helper investigation, rejected alternatives, score rationale, and target-specific no-code proof. Final validator: `000000000477`, exit `0`, `ok:1`.
- [x] `by-class/SimpleUString.md`: updated [UID:0002U5] representation/method-family/evidence/change text with current MCP details and blank-C++ policy; metadata unchanged. Validator: `000000000471`, exit `0`, `ok:1`.
- [x] `by-file/StringUtil.md`: updated SSO-7 helper/source-root text for [UID:0002U5] with current MCP evidence, direct class route, broad file route, and rejected owner alternatives; metadata unchanged. Validator: `000000000472`, exit `0`, `ok:1`.
- [x] `by-type/by-struct/SimpleUStringSso7Layout.md`: added [UID:0002U5] current proof for narrow-byte to UTF-16 append/grow over the SSO-7 layout and target blank-C++ source-shape proof; metadata unchanged. Validator: `000000000473`, exit `0`, `ok:1`.
- [x] `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md`: updated the child inventory/change note for [UID:0002U5] to `87/90` and preserved mixed-aggregate/no-owner rejection; metadata unchanged. Validator: `000000000474`, exit `0`, `ok:1`.
- [x] Confirmed `by-memory/0x00421a40-0x00421fd8.FittingRoomCatalogEntryFromJson.md` already represents the caller operation as higher-level `SimpleUString` ANSI assignment before `_wcscpy_s`; no edit, no validator needed.
- [x] Confirmed `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` already identifies the startup ANSI-range to wide-string conversion helper; no edit, no validator needed.
- [x] Did not create or edit by-memory child pages for `0x00423d00`/`0x00423eb0`; current implementation treats them as investigated dependencies, not target split blockers.
- [x] Did not manually edit any `-coverage-report.md` file. Supervisor-owned manual row replacement text remains above.
- [x] Target validator command recorded: `python .\tools\validator.py --mode file --file by-memory\0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md --apply --queue-timeout 240`; command_ids `000000000470` and final `000000000477`, exit `0`, `ok:1`, side effects listed in Validator Results.
- [x] Class validator command recorded: `python .\tools\validator.py --mode file --file by-class\SimpleUString.md --apply --queue-timeout 240`; command_id `000000000471`, exit `0`, `ok:1`, side effects listed above.
- [x] File validator command recorded: `python .\tools\validator.py --mode file --file by-file\StringUtil.md --apply --queue-timeout 240`; command_id `000000000472`, exit `0`, `ok:1`, side effects listed above.
- [x] Layout validator command recorded: `python .\tools\validator.py --mode file --file by-type\by-struct\SimpleUStringSso7Layout.md --apply --queue-timeout 240`; command_id `000000000473`, exit `0`, `ok:1`, side effects listed above.
- [x] Aggregate validator command recorded: `python .\tools\validator.py --mode file --file by-memory\0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md --apply --queue-timeout 240`; command_id `000000000474`, exit `0`, `ok:1`, side effects listed above.
- [x] Optional caller support docs were not edited, so no optional scoped validators were required.
- [x] Lease proof recorded: waited for B005 aggregate lease expiry, acquired exact five B003 leases successfully, final unlease found no active leases because they had expired, and `current_leases.md` was empty afterward.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002U5-SharedNarrowRangeToWideSsoAppendHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-24T15:13:52","uid":"0002U5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
