** TARGET-REPORT-UID:0002E3 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0002E3] SimpleUStringAssignWideCount Source-Quality Report

Assignment: `B003-report-0002E3-simple-ustring-assign-wide-count-20260624`

Agent: B003

Report path: `tools/leaser/Agents/Agent-B003/research/0002E3-SimpleUStringAssignWideCount-source-quality.md`

Target: [UID:0002E3] `by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md`

Status: implementation callback completed on 2026-06-24. Target/support by-* docs were updated and validated; no manual `-coverage-report.md` edits were made; no generated/project-level files, validator state, queue/lock files, or IDA DB state were edited manually.

## Finalized Report / Current Recommendation

Current recommendation after implementation: accepted and applied. The existing exact range and direct owner/emitter route were preserved, the target was raised from `85/88` to `88/90`, and the previously prose-only C++ candidate was replaced by the accepted formal reconstruction block with corrected source-facing signature and return behavior.

Final disposition: [UID:0002E3] is a source-authored `SimpleUString` SSO-7 counted UTF-16 assignment method. Current MCP session `80de0a67` confirms the exact modeled body `0x00421590-0x004216cb`, twelve bytes of `0xcc` predecessor padding at `0x00421584-0x00421590`, five bytes of `0xcc` successor padding at `0x004216cb-0x004216d0`, 74 code xrefs, no data/VA/RVA pointer route, SSO-7 field access, allocator/free/string-too-long callees, and `this` returned in `EAX`.

Implementation result: updated the target and directly affected support docs at report-level detail; kept `CANONICAL_OWNER:0000D9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D9`, blank emitter position, no split/rename, and inserted first-draft formal C++ as `SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)`.

Confidence: very strong for range, behavior, owner/emitter, SSO-7 layout, callees, and first-draft source shape; not final-audit confidence because original source spelling for `Assign`, `ThrowStringTooLong`, `FreeMemory`, and the complete `SimpleUString`/`StringBase` public API split remains inferred.

## Target

- Target UID: `0002E3`
- Target path: `by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md`
- Pre-implementation source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, `85/88`, score `86.5`, reconstructable, not-covered.
- Pre-implementation generated memory row: `auto-generated/-ag-coverage-report-by-memory.md` showed `emits_code:false` because the formal C++ block was blank.
- Manual coverage row before supervisor action: `by-memory/-coverage-report.md` recorded the target as `85% : strong` and did not mention formal C++ readiness. B003 did not edit that manual coverage row.
- Pre-implementation metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000D9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D9`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`.
- Implemented metadata: `COMPLETION:88`, `CONFIDENCE:90`, same owner/emitter/reconstructable route, blank emitter position, and nonblank formal `RECONSTRUCTION_CPP CODE`.

## Pre-Implementation Target State

The target already has the correct exact half-open range, owner, reconstructable state, and emitter route. It documents the main SSO-7 behavior: capacity at `this+0x14`, length at `this+0x10`, inline threshold `8`, inline capacity `7`, counted UTF-16 copy, terminator write, growth through `length | 7` plus a 1.5x check, allocation of `(capacity + 1) * sizeof(wchar_t)`, old heap release, and the string-too-long / invalid-parameter hard-fail paths.

Before this implementation callback, the remaining source-quality problem was the prose-only `Reconstructed C++ Candidate` section. Under the current formal-C++ rule, code cannot stay in a side section. If it is valid, it must be supplied as exact formal `RECONSTRUCTION_CPP CODE` content; if it is not valid, the page needs a target-specific no-code proof. Current MCP evidence showed the code was close but stale in two important ways:

- the old candidate has `void SimpleUString::Assign(...)`, while the assembly returns `this` on both normal exits and IDA's current prototype is `void **__thiscall(void **this, void *Src, unsigned int)`;
- the old candidate uses helper names and source shape without recording the current MCP byte/hash/xref/pointer-negative evidence needed to justify formal insertion.

Related docs checked:

- `by-class/SimpleUString.md`
- `by-file/StringUtil.md`
- `by-type/by-struct/SimpleUStringSso7Layout.md`
- `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md`
- `by-memory/0x00421310-0x00421362.SimpleUStringClear.md`
- `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`
- `by-memory/0x00421520-0x00421584.AllocateAlignedDwordArray.md`
- `by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md`
- `by-memory/0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers.md`
- `by-memory/-ignored.md`
- `by-project-structure/proposed-source-tree.md`
- `auto-generated/NexusTK/util/StringUtil.cpp`
- current generated tracker/coverage and central executed reports named in the evidence section.

No Wave2/Wave3 material was used as authority. `simroot_v2` and generated output were searched only as lead material; current generated output only shows [UID:0002E3] as an empty marker.

## Executive Recommendation

Implemented [UID:0002E3] as a first-draft source method:

- target metadata after implementation: `COMPLETION:88`, `CONFIDENCE:90`;
- owner/emitter unchanged: direct owner [UID:0000D9] `SimpleUString`, emitter [UID:0000D9] through [UID:0000OB] `StringUtil`;
- no split or rename: the target range is one complete function with exact padding on both sides;
- first-draft C++ ready: inserted the exact formal block below in the target header and removed/superseded the prose-only candidate section.

The best source-facing method name is `Assign`, not the documentation-shaped `AssignWideCount`, because the function is a counted wide-buffer assignment over an existing string object and returns `*this`, matching the usual C++ assignment-style method shape. The filename can remain `SimpleUStringAssignWideCount` as a descriptive by-memory page name.

Rejected implementation alternatives:

- keep blank formal C++: rejected because the target has a valid emitter route, `(85 + 88) / 2 > 85`, now has current MCP-backed behavior/name/layout evidence, and the old no-code blocker is only unresolved exact original spelling, not unsafe behavior;
- keep `void SimpleUString::Assign(...)`: rejected because the function explicitly returns `this` on both normal exits (`mov eax, edi` before `retn 8`);
- name the method `AssignWideCount`: rejected as documentation/decompiler-shaped final source wording, though it remains useful in the page title;
- treat it as a constructor: rejected because the function reads/frees prior heap storage and assigns into an already initialized object;
- route directly to `StringUtil` as owner: rejected because `SimpleUString` is the narrower semantic owner; `StringUtil` remains the source file root;
- route to `StringBase`: rejected because this body uses the SSO-7 inline object at `+0x00/+0x10/+0x14`, not the later pointer-backed/refcounted `StringBase` layout;
- route to FittingRoom, StartupWindow, MetaMan, ItemHelpPane, ProfileStorage, or another high-volume caller: rejected because caller spread is consumer evidence for a shared utility method, not ownership;
- route to runtime/MSVC helpers: rejected because runtime callees implement allocation/free/error paths, while this body is project string-object logic over project fields.

## Supervisor Active Recheck

The original report-only pass followed the 2026-06-24 assignment in `Agent-B003/goal.md`: report-only research for [UID:0002E3], no by-* implementation edits, IDA MCP mandatory, score blockers treated as current-scope work, and any C++ supplied only as exact formal block insertion text. The later supervisor callback accepted the report and this file now records the completed implementation.

The assigned item does not require split execution before supervisor validation. Current MCP confirms a single modeled function `sub_421590` at `0x00421590` with size `0x13b` and no interior child/padding/table split. Predecessor and successor bytes are padding outside the half-open target. The related aggregate [UID:0000WT] is already a non-emitting mixed container; no new child pages are needed for this target.

## Inference Research Guidance Check

The report treats existing docs and generated output as leads, not proof. The direct facts are MCP-backed range, disassembly, decompilation, xrefs, caller windows, bytes, and negative pointer scans. Documentation evidence is used for the accepted SSO-7 member names and owner/file route. Inference is limited to source-facing method/helper spelling and formal C++ source shape.

The current `by-structure.md` code-entry gate is met: the target is reconstructable, has `EMITTER_UIDS:0000D9`, and its current combined score is already above `85`. The remaining question is not eligibility but source quality. The old body-only C++ section must either become formal block text or be replaced by no-code proof; this report recommends formal block insertion with corrected return type.

## IDA MCP Evidence

MCP provenance:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active database/session: `80de0a67`
- `idb_list`: one active owned worker for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, not analyzing.
- `server_health`: `status:ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Tool schema rechecked with `tools/list`; current `decompile`/`disasm` use `addr`, `get_bytes` uses `regions`, and `func_profile` uses a `queries` object.

Function and boundary facts:

- `lookup_funcs`:
  - `0x00421590` -> `sub_421590`, size `0x13b`.
  - `0x00421584` -> not a function.
  - `0x004216cb` -> not a function.
  - `0x00421520` -> `sub_421520`, size `0x64`, confirming predecessor function ends at `0x00421584`.
  - `0x00421310` -> `sub_421310`, size `0x52`, sibling `SimpleUString::Clear()`.
  - `0x00423060` -> `sub_423060`, size `0x1a4`, sibling narrow-to-wide SSO appender.
- `get_bytes`:
  - `0x00421584-0x00421590`: twelve `0xcc` bytes.
  - `0x00421590-0x004216cb`: 315-byte body, SHA-256 `2e2b7de08fe03fe5ca0eeab53609fa357612dc145abf5aad4749f4742ccdbeb2`, SHA16 `2e2b7de08fe03fe5`.
  - First 16 target bytes: `55 8b ec 51 8b 45 0c 53 56 57 8b f9 8b 4f 14 89`.
  - Last 16 target bytes: `8b e5 5d c2 08 00 e8 41 bf 1a 00 e8 05 a0 ff ff`.
  - `0x004216cb-0x004216d0`: five `0xcc` bytes.
- `int_convert.py` checks:
  - `0x13b` -> decimal `315` (Verified with `int_convert.py`).
  - `0x23` -> decimal `35` (Verified with `int_convert.py`).
  - `0x1f` -> decimal `31` (Verified with `int_convert.py`).
  - `0x1000` -> decimal `4096` (Verified with `int_convert.py`).
  - `0x7ffffffe` -> decimal `2147483646` (Verified with `int_convert.py`).

Function profile and callees:

- `func_profile 0x00421590` reports 119 instructions, 26 basic blocks, 15 unique modeled caller functions, 7 callees including self-reported target metadata, 0 string references, 25 constants, and prototype `void **__thiscall(void **this, void *Src, unsigned int)`.
- `callees 0x00421590` reports:
  - `_memmove_0` at `0x005c9b30`
  - `operator new(uint)` at `0x005c74f6`
  - `_memmove` at `0x005c95b0`
  - free wrapper `sub_5C7526` at `0x005c7526`
  - `__invalid_parameter_noinfo_noreturn` at `0x005cd607`
  - `sub_41B6D0` at `0x0041b6d0`, documented by [UID:0000WN] as the `"string too long"` runtime helper

Xrefs and caller inventory:

- `xrefs_to 0x00421590` returns 74 code xrefs, `more:false`, `xref_count:74`.
- Grouped by caller function:

| Caller function | Direct refs | Call sites |
| --- | ---: | --- |
| `0x004ccca0 sub_4CCCA0` | 17 | `0x4ccdf7`, `0x4cce43`, `0x4cce85`, `0x4ccfd7`, `0x4cd023`, `0x4cd065`, `0x4cd197`, `0x4cd1e3`, `0x4cd225`, `0x4cd3fd`, `0x4cd4a8`, `0x4cd4f4`, `0x4cd536`, `0x4cd7c7`, `0x4cd813`, `0x4cde77`, `0x4cdec3` |
| `0x005bc970 sub_5BC970` | 10 | `0x5bca31`, `0x5bcacc`, `0x5bcb67`, `0x5bcc02`, `0x5bcc9d`, `0x5bcd38`, `0x5bcdd3`, `0x5bce6e`, `0x5bcee0`, `0x5bcf1e` |
| `0x005ad820 sub_5AD820` | 9 | `0x5ad96a`, `0x5ad98a`, `0x5ad9aa`, `0x5ad9cb`, `0x5ad9ec`, `0x5ada0d`, `0x5ada2e`, `0x5ada4f`, `0x5ada70` |
| `0x004d1fa0 sub_4D1FA0` | 9 | `0x4d20ad`, `0x4d20e0`, `0x4d2122`, `0x4d21ad`, `0x4d21e0`, `0x4d2222`, `0x4d22ad`, `0x4d22e0`, `0x4d2322` |
| `0x0056f810 sub_56F810` | 5 | `0x56f8bc`, `0x56f8df`, `0x56f915`, `0x56f979`, `0x56f9af` |
| `0x00456a90 sub_456A90` | 4 | `0x456c39`, `0x456d3c`, `0x456ea4`, `0x456f77` |
| `0x0056edc0 sub_56EDC0` | 4 | `0x56f03d`, `0x56f070`, `0x56f0b2`, `0x56f1b4` |
| `0x005adad0 sub_5ADAD0` | 3 | `0x5adb28`, `0x5adb54`, `0x5adb80` |
| `0x00522960 sub_522960` | 3 | `0x522afd`, `0x522c9d`, `0x522e8d` |
| `NO_FN` | 2 | `0x45776a`, `0x457779` |
| `0x00457620 sub_457620` | 2 | `0x45767f`, `0x45768e` |
| `0x0056ea30 sub_56EA30` | 2 | `0x56ea93`, `0x56eafb` |
| `0x00419f20 sub_419F20` | 1 | `0x419f2c` |
| `0x00419ff0 sub_419FF0` | 1 | `0x419ffc` |
| `0x0041f2b0 sub_41F2B0` | 1 | `0x41f8f2` |
| `0x00523470 sub_523470` | 1 | `0x523611` |

Representative caller windows:

- `0x00419f20` initializes [UID:0000PW] `g_emptySimpleUString`: pushes length `0`, pushes `word_60DB20`, sets `ecx` to `dword_66DAEC`, calls `sub_421590`, then registers cleanup with `_atexit`; `EAX` is not consumed.
- `0x00419ff0` initializes [UID:0001OL] `g_metaAliasTableName`: same zero-length source pattern, `ecx = dword_66DE18`, then `_atexit`; `EAX` is not consumed.
- `0x0041f8d8-0x0041f910` in `sub_41F2B0` computes a UTF-16 length from a local `Src`, pushes that count and source, sets `ecx` to a local SSO-7 object, calls `sub_421590`, then branches on the destination capacity and tokenizes the local string; this is assignment into an initialized local object.
- `0x004ccde8-0x004cce50` has repeated local-string construction calls. At `0x004ccdf7` and `0x004cce43`, the caller pushes counted UTF-16 sources into local SSO-7 objects, then continues with local state setup; `EAX` is not consumed as a source-level return.
- `0x00522af0-0x00522b20` in `sub_522960` pushes a counted wide source into a local SSO-7 object at `0x00522afd`, then immediately reads destination string/capacity state from the object, not the return register.

Negative evidence:

- `xrefs_to 0x00421590` reports code xrefs only. No data xref appears in the result.
- `find_bytes` for little-endian absolute VA `90 15 42 00` returned zero matches.
- `find_bytes` for little-endian RVA `90 15 02 00` returned zero matches.
- A broad `insn_query` operand scan for calls to `0x421590` scanned 200000 instructions, returned no matches, and truncated before completion; it was not used as proof because the operand filter did not match IDA's call operand representation. The authoritative route is the successful `xrefs_to` result and targeted caller-window checks.

## Decompilation And Disassembly Interpretation

IDA decompilation:

- reads `this[5]` as capacity (`m_capacity`);
- stores old capacity in a stack local;
- if requested length fits, chooses `this` as inline storage when capacity is below `8`, otherwise chooses `*this` as heap storage;
- writes `this[4]` as length (`m_length`);
- calls `_memmove_0(storage, source, 2 * length)`;
- writes a UTF-16 terminator at `storage[length]`;
- returns `this`;
- if requested length does not fit, rejects `length > 0x7ffffffe` through `sub_41B6D0`;
- computes new capacity from `length | 7`, saturates at `0x7ffffffe`, and considers a 1.5x old-capacity growth candidate;
- allocates `(newCapacity + 1) * 2` bytes, with the `0x1000` large-allocation threshold, `+0x23` over-allocation, 32-byte alignment mask, and saved raw pointer at `aligned[-1]`;
- writes new capacity/length before copying into the new storage;
- copies with `_memmove`, writes the terminator, frees the old heap storage if old capacity was at least `8`, validates the old large-allocation header if needed, stores the new heap pointer, and returns `this`.

Disassembly confirms the source-shape details that matter for C++:

- `42159c mov ecx, [edi+14h]`: capacity read at `+0x14`.
- `4215b2 mov [edi+10h], eax`: length write at `+0x10`.
- `4215ba call _memmove_0`: fit path copy.
- `4215d0 retn 8`: two stack arguments with `this` in `ecx`.
- `4215d3 cmp eax, 7FFFFFFEh` and `4216c6 call sub_41B6D0`: oversized string hard fail.
- `4215e0 or esi, 7`: SSO-7 growth floor.
- `421608 lea eax, [edx+ecx]` plus `42160d cmovb esi, eax`: 1.5x old-capacity growth check.
- `421622 cmp ecx, 1000h`, `42162a lea eax, [ecx+23h]`, `421645 and ebx, 0FFFFFFE0h`, `421648 mov [ebx-4], eax`: large-allocation aligned-storage path.
- `421663 mov [edi+14h], esi`, `421666 mov [edi+10h], eax`, `421671 call _memmove`: update/copy new storage.
- `421687 lea ecx, ds:2[eax*2]`, `421698 mov edx, [eax-4]`, `4216a3 cmp eax, 1Fh`: old large-allocation free-size and raw-pointer validation.
- `4216ac call sub_5C7526`: shared free wrapper.
- `4216b4 mov [edi], ebx`, `4216b6 mov eax, edi`, `4216be retn 8`: store new heap pointer and return `this`.

## Heuristic / Inference Reanalysis And Validation

### Method Name And Signature

Best source-facing signature:

`SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)`

Evidence:

- The body assigns counted UTF-16 data into an already-initialized string object; it is not a constructor because it frees/replaces prior heap storage.
- The machine code returns `this` on both normal paths. A `void` method is less source-faithful than a reference-returning assignment method.
- The target is a full function with `retn 8`, matching a `thiscall` method with two stack arguments.
- Callers currently ignore `EAX`, but ignored return values are normal for assignment-style methods.
- `AssignWideCount` is accurate for the documentation filename but too decompiler/documentation-shaped for final source.

Rejected names:

- `AssignWideCount`: descriptive page title, not preferred final method spelling.
- `CopyWideCount`: weaker because the function also frees/reallocates old storage and returns the assigned object.
- `Construct` / constructor spelling: rejected because the function operates on an initialized object and may release old heap state.
- `_Tidy`, `Release`, or `Clear`: rejected because this function assigns new data; [UID:0002DV] already owns `Clear()`.
- `StringBase::Assign`: rejected because this exact body uses SSO-7 inline storage, not pointer-backed `StringBase` state.

### Field And Helper Names

Use the accepted SSO-7 names from [UID:0002DV] and [UID:0001W5]:

- `m_heapBuffer` / `m_inlineBuffer` for the union at `+0x00`;
- `m_length` for `+0x10`;
- `m_capacity` for `+0x14`;
- `FreeMemory(storage, allocationSize)` for the shared free wrapper, preserving the caller-side size computation even though the wrapper itself forwards only the pointer to CRT free;
- `ThrowStringTooLong()` for `0x0041b6d0`, a source-facing name for the documented runtime `"string too long"` helper.

These names are inferred source-facing names, not original-symbol proof. They are stable enough for first-draft C++ because [UID:0002DV] already emits compatible formal C++ through the same class/file route and [UID:0001W5] documents the layout.

### Source Placement

Recommended source placement remains `SimpleUString` under `NexusTK/util/StringUtil.cpp`. This target is a class method, while [UID:0000OB] `StringUtil` remains the broad file/source root.

Rejected placements:

- `FittingRoom.cpp`: one caller family uses local fitting-room strings, but direct caller spread covers startup, resource/UI, profile/help, metadata/static strings, and other consumers.
- `StringBase.cpp`: later pointer-backed string families have `StringBase` evidence; this range uses a 24-byte SSO-7 inline object.
- `EarlySimpleUStringAndAdjacentHelperIsland.cpp`: rejected because [UID:0000WT] is a mixed non-emitting address aggregate over string, fitting-room, pane, checkbox, thunk, and runtime spans.
- runtime/MSVC source: allocation/free/error callees are runtime dependencies, but the function's field accesses and class route are project string-object logic.

### Range / Split / Padding

No split is recommended. MCP confirms:

- predecessor child [UID:0002E2] ends at `0x00421584`;
- `0x00421584-0x00421590` is twelve bytes of `0xcc` padding already covered in `by-memory/-ignored.md`;
- [UID:0002E3] is exact `0x00421590-0x004216cb`, one modeled function, 315 bytes;
- `0x004216cb-0x004216d0` is five bytes of `0xcc` padding before [UID:00041Q] `FittingRoomItemEntryVectorStorageFree`;
- no interior xref, table, jump island, or data pocket was found.

### C++ Readiness

The target is now first-draft formal-C++ ready. The old blocker was exact public API spelling, but the source-quality rule does not require original symbol proof when behavior, fields, route, and naming inference are strong. The correct implementation action is to replace the prose-only candidate with formal block text and preserve the remaining original-spelling caveat as a confidence cap.

## Evidence Standards Used

Evidence ladder applied:

- direct IDA MCP function inventory, disassembly, decompilation, bytes, xrefs, callees, caller windows, and negative pointer scans;
- current by-* docs for the accepted `SimpleUString`/`StringUtil` route and SSO-7 member names;
- generated tracker/coverage output only for current score/not-covered state;
- executed B reports only as leads or accepted context, rechecked against current MCP where the conclusion affects this target.

IDA MCP cannot prove original symbol spelling or the final public header split between `SimpleUString` and `StringBase`; those remain confidence caps. It can prove the behavior and route strongly enough for first-draft source.

## Evidence Checked

MCP/tool evidence checked:

- `initialize`
- `tools/list`
- `idb_list`
- `server_health`
- `lookup_funcs` for `0x00421590`, `0x00421584`, `0x004216cb`, `0x00421520`, `0x00421310`, `0x00423060`
- `func_profile` for `0x00421590`
- `callees` for `0x00421590`
- `xrefs_to` for `0x00421590`
- `decompile 0x00421590`
- `disasm 0x00421590`
- `get_bytes` for `0x00421584-0x00421590`, `0x00421590-0x004216cb`, `0x004216cb-0x004216d0`
- `find_bytes` for little-endian VA/RVA pointer patterns `90 15 42 00` and `90 15 02 00`
- targeted `insn_query` caller windows around `0x0041f8f2`, `0x004ccdf7`, `0x004cce43`, and `0x00522afd`
- `disasm` for static initializer callers `0x00419f20` and `0x00419ff0`
- `int_convert.py` for constants listed above.

Docs/reports checked:

- target and direct support docs listed in `Current Target State`;
- `executed-b-agent-research/B001/0000WT-EarlySimpleUStringAndAdjacentHelperIsland.md`;
- `executed-b-agent-research/B005/0002DV-SimpleUStringClear-source-quality.md`;
- `executed-b-agent-research/B003/0000WR-FittingRoomUiCore-source-quality.md`;
- active B002 lead report `tools/leaser/Agents/Agent-B002/research/00030X-WideFormatWrapper128-source-quality.md` only for the fitting-room caller context;
- `tools/leaser/Agents/b-agent-rule26-incorporation-tracker.md` only as evidence that earlier aggregate claims were incorporated;
- `by-project-structure/proposed-source-tree.md`;
- current generated research tracker, generated memory coverage, manual `by-memory/-coverage-report.md`, and generated `auto-generated/NexusTK/util/StringUtil.cpp`.

Skipped or not used as proof:

- During the original report-only evidence pass, no by-* validators were run because no by-* docs were edited. Implementation validators were run later and are recorded in `Validator Results`.
- The broad `insn_query` operand scan was not used as proof because it truncated and the operand filter did not match the target call representation. `xrefs_to` and targeted caller windows supersede it.
- No IDA DB edits, rename/type/comment tools, or process-control operations were used.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x00421590-0x004216cb` is one exact modeled function. | Confirmed | `lookup_funcs` size `0x13b`, `disasm` 119 instructions, body SHA, `get_bytes` padding on both sides. | Probes at `0x00421584` and `0x004216cb` are not functions; no interior split evidence. | None for report scope. |
| The body is a `SimpleUString` SSO-7 counted wide assignment method. | Very strong | Field accesses `+0x00/+0x10/+0x14`, inline threshold `8`, capacity floor `|7`, terminator writes, sibling layout docs. | Rejected `StringBase`, FittingRoom, runtime, aggregate ownership. | Original method spelling still inferred. |
| Formal C++ should return `SimpleUString&`. | Strong | Both normal exits load `this` into `EAX`; decompiler prototype returns `void **`; assignment-style method source shape. | Representative callers ignore the return, so usage does not prove return type; however ignored assignment returns are normal. | Exact original header spelling unavailable. |
| `Assign` is the best source-facing method name. | Strong inference | Behavior is standard counted assignment into existing object; existing docs already use `Assign` in side candidate; `AssignWideCount` is page-descriptive. | Constructor, copy, `_Tidy`, `StringBase` names rejected. | Original symbol proof unavailable. |
| Owner/emitter should stay [UID:0000D9]. | Very strong | Current route already assigned; target is class method; [UID:0000D9] and [UID:0000OB] clear gate; generated output reaches `StringUtil.cpp`. | Direct file owner, caller owners, `StringBase`, runtime, and mixed aggregate rejected. | None for current implementation. |

## Positive Evidence Summary

- Exact modeled range, padding, body bytes, and SHA are current-MCP-backed.
- Decompilation and disassembly agree on counted UTF-16 assignment, SSO-7 fields, growth policy, allocation/free policy, and return-this behavior.
- The target has 74 direct code xrefs across 15 modeled caller functions plus two no-function refs in the xref inventory; this is live shared utility code.
- The direct class owner and source file route are already present and valid: [UID:0000D9] `SimpleUString` emits through [UID:0000OB] `StringUtil`.
- [UID:0002DV] already emits compatible `SimpleUString::Clear()` C++ with the same field names and free helper style.
- `find_bytes` found no absolute VA/RVA pointer route that would imply vtable/callback/table ownership outside the class method interpretation.

## Negative Evidence Summary

- No split is supported: no function at `0x00421584` or `0x004216cb`, and all side bytes are `0xcc` padding.
- No data-pointer route was found: `xrefs_to` is code-only, and VA/RVA byte patterns do not appear.
- FittingRoom physical adjacency is not source ownership: the aggregate is mixed and the caller set is broad.
- `StringBase` is not the direct owner: this function uses SSO-7 inline fields, not pointer-backed refcounted storage.
- Runtime/helper callees are dependencies, not owners: `operator new`, `sub_5C7526`, `_memmove`, and `sub_41B6D0` do not make this compiler/runtime-only code.
- The old `void` candidate does not preserve the function's return-this source shape.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00421584-0x00421590` | `by-memory/-ignored.md` | predecessor `0xcc` padding | false | none | ignored | already present |
| `0x00421590-0x004216cb` | [UID:0002E3] target | counted UTF-16 SSO-7 assignment/grow method | true | [UID:0000D9] | current `85/88`, recommend `88/90` | update target/formal C++ |
| `0x004216cb-0x004216d0` | `by-memory/-ignored.md` | successor `0xcc` padding | false | none | ignored | already present |
| `0x00421310-0x00421362` | [UID:0002DV] `SimpleUStringClear` | sibling SSO-7 clear/tidy method | true | [UID:0000D9] | `88/91` | already formal-C++-ready |
| `0x00423060-0x00423204` | [UID:0002U5] `SharedNarrowRangeToWideSsoAppendHelper` | sibling SSO-7 narrow-to-wide append/grow helper | true | [UID:0000D9] | `85/88` | no direct edit needed |

## Ranked Ownership Analysis

### 1. [UID:0000D9] SimpleUString

Evidence for:

- The target is a `thiscall` method over the SSO-7 object fields documented by [UID:0001W5].
- It shares field names and allocator/free policy with [UID:0002DV] and [UID:0002U5].
- [UID:0000D9] already clears the parent gate and emits through [UID:0000OB].
- The target's current metadata already uses this route.

Evidence against:

- Exact original method name is not recoverable from IDA MCP.
- The broader `SimpleUString` versus `StringBase` public API split is still documented as open at the class level.

Decision: keep as direct owner/emitter; uncertainty caps score below final audit but no longer blocks formal C++.

### 2. [UID:0000OB] StringUtil

Evidence for:

- `StringUtil.cpp` is the accepted generated source root for `SimpleUString`.
- The generated output already surfaces [UID:0002E3] as an empty marker under `auto-generated/NexusTK/util/StringUtil.cpp`.

Evidence against:

- Direct semantic owner is the class method, not a file-level free helper.

Decision: keep as source file route through [UID:0000D9], not direct canonical owner.

### 3. [UID:0000OA] StringBase

Evidence for:

- Broader string-family docs acknowledge pointer-backed helpers and historical naming overlap.

Evidence against:

- Target uses SSO-7 inline storage and `+0x10/+0x14` fields, not pointer-backed `StringBase` header/state.
- `SimpleUStringSso7Layout` explicitly rejects `StringBase` for this layout.

Decision: reject for this target.

### 4. FittingRoom / StartupWindow / MetaMan / other caller owners

Evidence for:

- Some callers are feature-specific consumers.

Evidence against:

- Caller spread is broad and includes static string initialization, fitting-room local strings, help/metadata/resource-style functions, and other utility consumers.
- The body has no feature globals, protocol fields, UI state, or resource-specific logic.

Decision: reject all caller-local owners.

### 5. Runtime / MSVC / aggregate owners

Evidence for:

- The function uses runtime allocation, free, invalid-parameter, memmove, and string-too-long helper callees.
- It is physically near runtime/vector support in the mixed aggregate.

Evidence against:

- The function operates on a project string class layout and is routed as a class method.
- [UID:0000WT] is explicitly mixed and non-emitting; runtime helper pages around it are separate.

Decision: reject.

## Source Placement

Recommended placement: method body in `NexusTK/util/StringUtil.cpp` under class [UID:0000D9] `SimpleUString`, with declarations eventually in `util/StringUtil.h` or the final string utility header selected by the broader string-family audit.

This placement matches current `by-project-structure/proposed-source-tree.md`, which lists `util/StringUtil.cpp` and says the `0x00421310-0x004216cb` endpoint helpers are `SimpleUString` UTF-16 small-string construction/clear helpers. It also matches current generated output, where [UID:0002DV] already emits `SimpleUString::Clear()` in `auto-generated/NexusTK/util/StringUtil.cpp` and [UID:0002E3] appears as an empty marker waiting for formal code.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Reason it preserves original behavior:

- uses the same SSO-7 fields and thresholds as the disassembly;
- preserves fit-path copy, grow-path allocation, `length | 7`, 1.5x growth, `0x7ffffffe` cap, `0x1000` large-allocation threshold, `+0x23` aligned-overallocation, `0x1f` header validation, size-aware free call, terminator write, and return of `*this`;
- uses the same source-facing helper style already accepted for `SimpleUString::Clear()`.

Reason it matches likely source shape:

- a reference-returning `Assign` method is normal human-written C++ for a string-like class;
- `AssignWideCount` remains a descriptive documentation title rather than final source spelling;
- field/helper names follow the accepted local `SimpleUString::Clear()` and `SimpleUStringSso7Layout` convention.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0002E3]:

```cpp
SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)
{
    unsigned int oldCapacity = m_capacity;
    wchar_t *oldStorage = oldCapacity >= 8 ? m_heapBuffer : m_inlineBuffer;

    if (length <= oldCapacity) {
        m_length = length;
        memmove(oldStorage, source, length * sizeof(wchar_t));
        oldStorage[length] = L'\0';
        return *this;
    }

    if (length > 0x7ffffffe) {
        ThrowStringTooLong();
    }

    unsigned int newCapacity = length | 7;
    if (newCapacity > 0x7ffffffe) {
        newCapacity = 0x7ffffffe;
    } else {
        unsigned int halfCapacity = oldCapacity >> 1;

        if (oldCapacity > 0x7ffffffe - halfCapacity) {
            newCapacity = 0x7ffffffe;
        } else {
            unsigned int grownCapacity = oldCapacity + halfCapacity;
            if (newCapacity < grownCapacity) {
                newCapacity = grownCapacity;
            }
        }
    }

    unsigned int allocationSize = (newCapacity + 1) * sizeof(wchar_t);
    wchar_t *newStorage = NULL;

    if (allocationSize >= 0x1000) {
        unsigned int requestSize = allocationSize + 0x23;
        if (requestSize < allocationSize) {
            requestSize = 0xffffffff;
        }

        void *rawStorage = operator new(requestSize);
        if (rawStorage == NULL) {
            _invalid_parameter_noinfo_noreturn();
        }

        newStorage = reinterpret_cast<wchar_t *>(
            (reinterpret_cast<unsigned int>(rawStorage) + 0x23) & 0xffffffe0);
        reinterpret_cast<void **>(newStorage)[-1] = rawStorage;
    } else if (allocationSize != 0) {
        newStorage = static_cast<wchar_t *>(operator new(allocationSize));
    }

    m_capacity = newCapacity;
    m_length = length;
    memmove(newStorage, source, length * sizeof(wchar_t));
    newStorage[length] = L'\0';

    if (oldCapacity >= 8) {
        unsigned int oldAllocationSize = (oldCapacity + 1) * sizeof(wchar_t);
        void *freeStorage = oldStorage;

        if (oldAllocationSize >= 0x1000) {
            void *rawStorage = reinterpret_cast<void **>(freeStorage)[-1];
            oldAllocationSize += 0x23;

            if (static_cast<unsigned char *>(freeStorage) -
                    static_cast<unsigned char *>(rawStorage) - sizeof(void *) > 0x1f) {
                _invalid_parameter_noinfo_noreturn();
            }

            freeStorage = rawStorage;
        }

        FreeMemory(freeStorage, oldAllocationSize);
    }

    m_heapBuffer = newStorage;
    return *this;
}
```

Score/C++ caveat: the helper names `ThrowStringTooLong` and `FreeMemory` and method spelling `Assign` are source-facing inferences. They should be documented as confidence caps, not blockers. Do not leave the old body-only candidate section after formal insertion.

## Final Recommendation

Recommended target state:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000D9`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000D9`
- blank `EMITTER_POSITION_OPTIONAL`
- formal C++ block exactly as supplied above.

Recommended support state:

- update [UID:0000D9] `SimpleUString` to record [UID:0002E3] as first-draft-C++-ready `SimpleUString& Assign(const wchar_t *source, unsigned int length)`;
- update [UID:0000OB] `StringUtil` to record that both SSO endpoint helpers [UID:0002DV] and [UID:0002E3] now emit formal C++ through the class route;
- update [UID:0001W5] `SimpleUStringSso7Layout` to note that [UID:0002E3] is now a formal `Assign` proof for `m_length`, `m_capacity`, inline/heap union, and old-heap release;
- update [UID:0000WT] aggregate row for [UID:0002E3] from `85/88` blank-C++ wording to `88/90` formal-C++-ready wording;
- leave `by-memory/-ignored.md` padding rows unchanged unless the supervisor wants a current-session evidence refresh, because the current padding facts are already present at sufficient detail.

## Recommended Target Doc Changes

Target path: `by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md`

Exact changes:

- set `COMPLETION:88`;
- set `CONFIDENCE:90`;
- keep `CANONICAL_OWNER:0000D9`;
- keep `RECONSTRUCTABLE:TRUE`;
- keep `EMITTER_UIDS:0000D9`;
- keep blank `EMITTER_POSITION_OPTIONAL`;
- insert the exact formal C++ block from this report;
- replace the prose-only `Reconstructed C++ Candidate` section with current evidence and a formal-C++ explanation;
- update `Item Summary` to mention MCP session `80de0a67`, exact 315-byte body/SHA16, return-this assignment shape, and formal C++ readiness;
- preserve current behavior facts, allocator/free/string-too-long callee evidence, exact padding, 74 xrefs, and rejected source placements;
- correct stale wording that says the final name/API split blocks C++. It remains a confidence cap, not a no-code blocker.

## Recommended Support Doc Changes

Support path: `by-class/SimpleUString.md`

- Add [UID:0002E3] as now-formal `SimpleUString& Assign(const wchar_t *source, unsigned int length)`.
- Preserve the broader class-level C++ block as blank because the whole class declaration/API split is still broader than this one method.
- Record that the method returns `*this`, uses SSO-7 fields and `FreeMemory`/`ThrowStringTooLong`, and that original spelling remains inferred.

Support path: `by-file/StringUtil.md`

- Update the SSO-7 UTF-16 helper list and ownership map so [UID:0002E3] joins [UID:0002DV] as a formal-C++-ready method emitted through [UID:0000D9].
- Preserve `StringBase`, FittingRoom, runtime, fixed-wide-format-wrapper, and aggregate rejections.
- No source split change: still `NexusTK/util/StringUtil.cpp`.

Support path: `by-type/by-struct/SimpleUStringSso7Layout.md`

- Add current [UID:0002E3] proof that the formal `Assign` method uses the union at `+0x00`, length `+0x10`, capacity `+0x14`, inline threshold `8`, inline capacity `7`, capacity growth by `|7` and 1.5x, and old heap release through the size-aware `FreeMemory` path.
- Preserve the caveat that member names are inferred source-facing names, not original symbols.

Support path: `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md`

- Update the [UID:0002E3] row / B001-006 audit wording to `88/90` and formal `SimpleUString::Assign(...)` readiness.
- Preserve the aggregate's `RECONSTRUCTABLE:FALSE`, blank owner/emitter/C++, exact mixed child inventory, and no-single-owner rationale.

Support path: `by-memory/-ignored.md`

- No required edit. Current rows already record `0x00421584-0x00421590` and `0x004216cb-0x004216d0` padding. If supervisor wants current-session refresh during implementation, add MCP session `80de0a67` byte evidence, but this is not necessary for correctness.

No required changes:

- `by-memory/0x00421310-0x00421362.SimpleUStringClear.md`: already records [UID:0002E3] as sibling SSO-7 assign/grow helper and supplies the accepted field/free-helper style.
- `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`: already records [UID:0002DV] and [UID:0002E3] as same-family SSO-7 helpers; its own no-code blockers remain target-specific.
- `by-memory/0x00421520-0x00421584.AllocateAlignedDwordArray.md` and `by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md`: no change; they are runtime/vector support and remain rejected as source owners.

## Score And Metadata Recommendation

Pre-implementation metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000D9`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000D9`
- blank emitter position
- blank formal C++

Implemented metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000D9`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000D9`
- blank emitter position
- nonblank formal C++ block as above.

Score rationale:

- Completion rises to `88` because this pass supplies current MCP session/provenance, exact bytes and SHA, corrected first-draft formal C++ block, return-this source-shape decision, pointer-route negatives, caller windows, and support-doc implementation package. It is not higher because exact original method/helper spelling and the complete class declaration remain inferred.
- Confidence rises to `90` because decompilation, disassembly, caller windows, SSO-7 layout docs, sibling formal `Clear()` code, xrefs, callees, and negative data/pointer evidence all agree. It is not higher because IDA MCP cannot prove original names or the broader `SimpleUString`/`StringBase` API split.

Score-improvement blockers researched:

- Old C++ blocker: resolved by formal block with corrected return type and exact helper/field names.
- Exact method name blocker: researched through behavior, return value, callers, sibling docs, generated output, and source conventions; resolved to inferred `Assign` with confidence cap.
- Owner/source-placement blocker: researched through xrefs, support docs, proposed tree, generated output, and rejected alternatives; owner/emitter remain correct.
- Range/padding blocker: researched with current `lookup_funcs` and `get_bytes`; no split required.
- Pointer/vtable/data-route blocker: researched with `xrefs_to` and `find_bytes`; no hidden route found.

## Open Questions With Attempted Resolution

Open question: exact original method spelling.

- Evidence checked: target behavior, return-this assembly, existing page name, current side candidate, sibling `Clear()` style, generated output, and support docs.
- Resolution: use source-facing `Assign` in the formal block. Original spelling is not proven, but `Assign` is the best human source shape and `AssignWideCount` is too documentation-shaped.
- Score/C++ impact: confidence cap only; not a no-code blocker.

Open question: exact helper spelling for `ThrowStringTooLong` and `FreeMemory`.

- Evidence checked: callee docs, [UID:0000WN] string-too-long helper, [UID:0002DV] accepted `FreeMemory(storage, allocationSize)` formal code, current decompilation/callees.
- Resolution: use those source-facing names, and document them as inferred helper names.
- Score/C++ impact: confidence cap only.

Open question: complete `SimpleUString` versus `StringBase` public API split.

- Evidence checked: `SimpleUString`, `StringUtil`, `StringBase`, SSO-7 layout, pointer-backed layout, generated source, proposed tree.
- Resolution: keep this exact method under `SimpleUString` / `StringUtil`; do not solve the whole class declaration here.
- Score/C++ impact: class-level C++ remains blank, but exact child C++ is safe.

No unresolved split, owner, liveness, or C++ blocker remains for [UID:0002E3].

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Do not edit `by-memory/-coverage-report.md` during implementation. The normal generated coverage row should update from source metadata and validators. If the supervisor chooses to keep the manual `by-memory/-coverage-report.md` synchronized, replace only the [UID:0002E3] row with:

```markdown
            - [UID:0002E3][0x00421590-0x004216cb.SimpleUStringAssignWideCount](by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md) 0x00421590-0x004216cb | method | SimpleUStringAssignWideCount : reconstructable : 88% : very strong : B003 2026-06-24 MCP session 80de0a67 raises the SSO-7 counted UTF-16 assignment helper to 88/90 and recommends exact formal `SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)` C++; IDA confirms `sub_421590` size 0x13b / 315 bytes (Verified with `int_convert.py`), SHA16 `2e2b7de08fe03fe5`, capacity at +0x14, length at +0x10, inline threshold 8, growth by `length | 7` plus 1.5x old-capacity check, `0x7ffffffe` cap, `(capacity + 1) * sizeof(wchar_t)` allocation, large-allocation `+0x23` / `0x1f` header validation, `_memmove`/`_memmove_0`, `operator new`, `sub_5C7526`, `sub_41B6D0` string-too-long support, `__invalid_parameter_noinfo_noreturn`, 74 code xrefs, no VA/RVA pointer bytes, twelve-byte predecessor padding, five-byte successor padding, and direct [UID:0000D9][SimpleUString](by-class/SimpleUString.md) ownership through [UID:0000OB][StringUtil](by-file/StringUtil.md).
```

No manual tracker text is required for validator-owned `auto-generated/-ag-research-tracker.md`; the supervisor should execute the report through the validator after implementation verification.

## Follow-Up Actions

Supervisor actions:

- Verify this implementation claim by claim against the accepted report/checklist.
- Execute the report through the validator after verification.
- Apply or skip the manual coverage replacement above according to current supervisor coverage policy.

A-agent actions: none.

B003 future action: none unless the supervisor requests a correction.

## Confidence

Recommendation confidence: high.

Score confidence: high for `88/90`.

Remaining uncertainty: original source spelling for `Assign`, helper spelling for `ThrowStringTooLong` / `FreeMemory`, and the complete `SimpleUString` header/API split. These do not block this exact target's formal C++ because behavior, range, fields, owner/emitter route, and source shape are strong.

## Validator Results

Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation` during the implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [0002E3-SimpleUStringAssignWideCount-source-quality-removed.md](0002E3-SimpleUStringAssignWideCount-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated-refresh check:

> Executable block R002 was removed from this report and preserved verbatim in [0002E3-SimpleUStringAssignWideCount-source-quality-removed.md](0002E3-SimpleUStringAssignWideCount-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

`auto-generated/NexusTK/util/StringUtil.cpp` was not manually edited. It refreshed through validator deferred-generated-refresh with header `validator-command-id: 000000000409`, `validator-refreshed-at: 2026-06-24T14:38:35-04:00`, and includes the generated [UID:0002E3] `SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)` block at completion/confidence `88/90`. The generated header is newer than target validator command `000000000406` and file validator command `000000000408`, so it reflects the accepted target/file changes for this callback.

## Changed Files

Changed by B003 in this callback:

- `by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md`
- `by-class/SimpleUString.md`
- `by-file/StringUtil.md`
- `by-type/by-struct/SimpleUStringSso7Layout.md`
- `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md`
- `tools/leaser/Agents/Agent-B003/research/0002E3-SimpleUStringAssignWideCount-source-quality.md`

Validator-owned side effects observed and not manually edited by B003:

- `auto-generated/NexusTK/util/StringUtil.cpp` refreshed to include the new formal [UID:0002E3] emitter.
- `project-level/-auto-completion-stats.md` projected stats/stat rows updated by scoped validators.
- `tools/validator.ini` registry/completion/confidence/autogen entries updated by scoped validators.

No edits were made to any manual `-coverage-report.md` file. `by-memory/-ignored.md` was not edited because its padding rows were already present at sufficient detail.

Leases: B003 took a short lease for the five by-* docs immediately before editing. After validation, `python .\tools\leaser\leaser.py B003 unlease ...` returned `Rejected[No active lease]` for each path, and `tools/leaser/Agents/current_leases.md` shows no active leases. Treat this as released/expired before cleanup; no active B003 lease remains.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted the report and issued callback assignment `B003-implement-0002E3-simple-ustring-assign-wide-count-20260624`.
- [x] Update `by-memory/0x00421590-0x004216cb.SimpleUStringAssignWideCount.md`: set metadata to `88/90`, preserve owner/emitter/reconstructable state, insert exact formal `SimpleUString& SimpleUString::Assign(const wchar_t *source, unsigned int length)` block, replace/remove prose-only candidate code, and incorporate current MCP session `80de0a67` facts, SHA16 `2e2b7de08fe03fe5`, exact padding, 74 xrefs, caller windows, return-this proof, callees, pointer-route negatives, rejected alternatives, and score rationale. Proof: target metadata/header/body updated; stale side-section candidate removed; validator `000000000406` exited `0`, `ok: 1`, and registered blank -> block plus `88/90`.
- [x] Update `by-class/SimpleUString.md`: record [UID:0002E3] as formal-C++-ready counted wide assignment method, preserve class-level blank C++ policy, and keep `SimpleUString`/`StringBase` split caveat as a confidence cap. Proof: method-family/evidence/changes sections updated; class-level formal block remains blank; validator `000000000407` exited `0`, `ok: 1`.
- [x] Update `by-file/StringUtil.md`: record [UID:0002E3] as formal-C++-ready through [UID:0000D9], keep `StringUtil.cpp` source root, and preserve rejected `StringBase`, FittingRoom/caller, runtime, and mixed-aggregate alternatives. Proof: likely contents/ownership map/evidence/changes sections updated; validator `000000000408` exited `0`, `ok: 1`.
- [x] Update `by-type/by-struct/SimpleUStringSso7Layout.md`: add [UID:0002E3] as current formal `Assign` proof for `+0x00`, `+0x10`, `+0x14`, inline threshold/capacity, growth, allocation/free, and field-name confidence caveat. Proof: evidence/operational model/changes sections updated; validator `000000000409` exited `0`, `ok: 1`.
- [x] Update `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md`: refresh the [UID:0002E3] child row/support wording to `88/90` formal C++ ready while preserving aggregate `RECONSTRUCTABLE:FALSE`, blank owner/emitter/C++, exact child inventory, padding, and mixed-owner rejection. Proof: covered-range row, evidence, split-gate audit, and changes sections updated; validator `000000000410` exited `0`, `ok: 1`.
- [x] Leave `by-memory/-ignored.md` unchanged unless the implementation callback explicitly asks for current-session padding refresh; current padding rows are already present at sufficient detail. Proof: no edit made; not validated because unchanged.
- [x] Leave `by-memory/0x00421310-0x00421362.SimpleUStringClear.md`, `by-memory/0x00423060-0x00423204.SharedNarrowRangeToWideSsoAppendHelper.md`, `by-memory/0x00421520-0x00421584.AllocateAlignedDwordArray.md`, and `by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md` unchanged unless stale contradictions are found during implementation; current pass found no required edits. Proof: no stale contradiction requiring edits was found; these files were not touched.
- [x] Do not edit any `-coverage-report.md`; if supervisor wants manual coverage sync, use the exact [UID:0002E3] replacement row in this report. Proof: no manual coverage file edited; supervisor-owned row remains in `Exact Manual Supervisor-Owned Coverage Or Tracker Text`.
- [x] Run validators listed in `Validator Results` for every changed by-* doc and record command, command_id, command_timestamp, exit code, ok count, warnings, side effects, and generated-refresh state. Proof: validators `000000000406` through `000000000410` all exited `0` with `ok: 1`; generated refresh state recorded above.
- [x] Update this checklist during implementation with checked items and proof paths/sections/validator results. Proof: this checked checklist section was updated after validators.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: callback received and `goal.md` read before editing.
- [x] Leases taken only for immediate edit/validator batch and released immediately afterward. Proof: B003 lease command succeeded for the five by-* docs before editing; post-validator unlease found no active lease; `current_leases.md` shows no active leases.
- [x] All accepted target/support details incorporated at report-level detail or marked already present with proof. Proof: five accepted docs updated; unchanged optional docs and `-ignored.md` marked not applicable/already sufficient above.
- [x] Metadata/C++ changes applied exactly or blocked with concrete reason. Proof: [UID:0002E3] target is `88/90` with the accepted formal C++ block exactly in the header; no accepted metadata/C++ item blocked.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve no data/pointer route, no split, no aggregate owner, rejected `StringBase`, caller-local, runtime/MSVC, constructor, `void`, and documentation-shaped final name alternatives.
- [x] Validators run and results recorded. Proof: command IDs `000000000406`-`000000000410`, timestamps, exit codes, `ok` counts, and side effects recorded above.
- [x] Manual coverage edits left supervisor-owned. Proof: no `-coverage-report.md` edited; exact manual row remains in this report.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: no accepted items remain unapplied; no blockers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002E3-SimpleUStringAssignWideCount-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-24T14:41:56","uid":"0002E3"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002E3-SimpleUStringAssignWideCount-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002E3-SimpleUStringAssignWideCount-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002E3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
