** TARGET-REPORT-UID:000227 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000227 DATFileMgr FindEntry Forwarder Source-Quality Research

## Finalized Report / Current Recommendation

- Assignment id: `B001-report-000227-datfilemgr-find-entry-forwarder-source-quality-20260626`.
- Target: [UID:000227] `by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md`.
- Current recommendation: keep the target as a reconstructable public `DATFileMgr` method owned/emitted by [UID:00003I][DATFileMgr](by-class/DATFileMgr.md), raise the source-quality metadata to `COMPLETION:90`, `CONFIDENCE:91`, and populate the formal C++ block.
- Final disposition: source-authored raw/no-function public wrapper. The raw/no-xref state is real negative evidence for reachability, but current MCP and accepted support docs resolve the old final-C++ blockers: public method name, private target helper, output record type, `m_impl` field, and source route.
- Required action after supervisor acceptance: update the target by-memory page and the listed support docs at report-level detail, then run scoped validators. Do not edit generated reports or manual coverage reports.
- Confidence: high for exact bytes, boundaries, owner/emitter, output type, and source-facing C++ shape; capped below final-audit levels because IDA still has no modeled function object or direct entry xrefs/pointers to `0x0049bd20`, and original source spelling is inferred rather than symbol-proven.

## Target

- Target UID: [UID:000227].
- Target path: `by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; the generated row is stale at `78/88` while the live target page is `85/89`.
- Current supervisor classification: report-only source-quality cleanup for a reconstructable item already above the minimum gate.
- Current target metadata:
  - `COMPLETION:85`
  - `CONFIDENCE:89`
  - `CANONICAL_OWNER:00003I`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00003I`
  - formal `RECONSTRUCTION_CPP CODE` block blank

## Current Target State

The current target page correctly records the 12-byte raw wrapper body, public/private manager forwarding behavior, no IDA function object at `0x0049bd20`, no direct xrefs to the wrapper entry, and the tail jump into `_DATFileMgr::FindEntryByName` at `0x0049cad0`.

The stale part is the source-quality conclusion: it says C++ stays blank because the public method spelling and output record type remain provisional. Current accepted support docs have moved past that state:

- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) documents public wrapper layout as `vptr` plus `_DATFileMgr *m_impl` at `+0x04`.
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) declares `_DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)`.
- [UID:00043E][0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName](by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md) already emits formal C++ using `DATEntryLocation *outLocation`, `DATEntryNode::m_container`, and `DATEntryNode::m_entryIndex`.
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) already emits a call through `g_pDATFileMgr->FindEntryByName(entryName, 0)`, which corroborates the public wrapper spelling and source-facing API.
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) is the adjacent public wrapper pattern and already emits formal C++ through [UID:00003I].

## Supervisor Active Recheck

- Supervisor instruction: new report-only research for [UID:000227], with live IDA MCP mandatory and no by-* edits before validation.
- Split repair required: no. The target range is already exact and does not cross padding or another function. The only split/padding issue is confirming the adjacent ignored padding remains correct.
- Every source-bearing child in scope: the target is itself the exact source-bearing child. No new child pages are needed.

## Evidence Checked

### Live IDA MCP

Live MCP was available and responsive.

- JSON-RPC `b001-000227-init`: `initialize` succeeded; server `ida-pro-mcp`, protocol `2025-06-18`.
- JSON-RPC `b001-000227-tools`: `tools/list` succeeded; current schema uses `decompile addr`, `get_bytes regions`, and `find_bytes patterns`.
- JSON-RPC `b001-000227-idb-list`: active session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid=26892`, `is_active=true`, `is_analyzing=false`.
- JSON-RPC `b001-000227-health`: `server_health(database='80de0a67')` returned `status=ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`.
- JSON-RPC `b001-000227-lookup`: `lookup_funcs` reported `Not a function` for `0x0049bd19`, `0x0049bd20`, `0x0049bd27`, and `0x0049bd2c`; `0x0049bd30` is `sub_49BD30` size `0x111`; `0x0049be70` is `sub_49BE70` size `0x0c`; `0x0049cad0` is `sub_49CAD0` size `0xd5`; `0x0049cba5` is not a function.
- JSON-RPC `b001-000227-bytes2`: `get_bytes` over `0x0049bd19` shows seven `0xcc` bytes, then `55 8b ec 8b 49 04 5d e9 a4 0d 00 00`, then four `0xcc` bytes and the constructor prologue at `0x0049bd30`.
- JSON-RPC `b001-000227-insn-range`: `insn_query 0x0049bd19-0x0049bd30` rendered `align 10h` at `0x49bd19`, wrapper instructions at `0x49bd20` through `0x49bd27`, and `align 10h` at `0x49bd2c`, all with `fn:null`.
- JSON-RPC `b001-000227-sig`: `make_signature_for_range 0x0049bd19-0x0049bd30` returned `CC CC CC CC CC CC CC 55 8B EC 8B 49 04 5D E9 A4 0D 00 00 CC CC CC CC`, unique.
- JSON-RPC `b001-000227-xrefs-bd20` and `b001-000227-xrefq-bd20`: no cross-references to `0x0049bd20`.
- JSON-RPC `b001-000227-find-coderef-bd20`: no `code_ref` matches to `0x0049bd20`.
- JSON-RPC `b001-000227-find-dataref-bd20`: no `data_ref` matches to `0x0049bd20`.
- JSON-RPC `b001-000227-find-ptr-bd20-2`: byte search for little-endian pointer `20 bd 49 00` returned no matches.
- JSON-RPC `b001-000227-find-body-2`: byte search for the wrapper body found one match at `0x49bd20`.
- JSON-RPC `b001-000227-xrefs-cad0` and `b001-000227-xrefq-cad0`: four refs to `0x0049cad0`: raw jump at `0x49bd27`, `DATFile::Open` at `0x49c1b8`, `HasDATEntry` at `0x49c711`, and `_DATFileMgr::LoadDATFileIndex` at `0x49c9c0`.
- JSON-RPC `b001-000227-decomp-find2` and `b001-000227-analyze-find`: `0x0049cad0` decompiles as byte/char return, normalizes the string, calls `0x0049d5e0`, compares the returned node with `this[2]`, returns `0` on sentinel/no-hit, writes two dwords from node `+0x0c` and `+0x10` to the output pointer when non-null, and returns `1`.
- JSON-RPC `b001-000227-decomp-loadwrap2`: the adjacent public load wrapper at `0x0049be70` decompiles as the same `this[1]` public-to-private forwarder pattern into `0x0049c800`.
- JSON-RPC `b001-000227-decomp-datopen2` and `b001-000227-analyze-datopen`: `DATFile::Open` calls `0x0049cad0` with an output local, throws `FileError` on false, then uses the returned container pointer and entry index to derive the mapped DAT record and payload size.
- JSON-RPC `b001-000227-decomp-has2`: `HasDATEntry` reads `g_pDATFileMgr`, loads the inner pointer at `+0x04`, calls `0x0049cad0` with null output, and returns nonzero as boolean existence.
- JSON-RPC `b001-000227-decomp-loadindex`: `_DATFileMgr::LoadDATFileIndex` duplicate-check path calls `0x0049cad0` with null output before creating a `DATEntryNode`.
- JSON-RPC `b001-000227-callees-cad0`: callee list for `0x0049cad0` includes string normalization/destruction helpers plus `0x0049d5e0` resolver lookup.

Malformed first attempts with old parameter shapes were corrected after checking the live schema: `b001-000227-bytes`, `b001-000227-find-ptr-bd20`, `b001-000227-find-body`, `b001-000227-decomp-find`, and `b001-000227-decomp-loadwrap` returned schema errors only. They do not affect the evidence because the corrected calls above succeeded in the same session.

### Documentation And Generated Evidence

Checked current docs:

- Target [UID:000227].
- [UID:00003I] `by-class/DATFileMgr.md`.
- [UID:0000IO] `by-file/DATFileMgr.md`.
- [UID:00012B] `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md`.
- [UID:00043E] `by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md`.
- [UID:00012C] `by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md`.
- [UID:00012E] `by-memory/0x0049c700-0x0049c71d.HasDATEntry.md`.
- [UID:000004] `by-class/_DATFileMgr.md`.
- [UID:0000UC] `by-item/DATEntryRecord.md`.
- [UID:00043D] `by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md`.
- [UID:00043F] `by-memory/0x0049cbb0-0x0049cc39.CreateDATEntryNode.md`.
- [UID:00043I] `by-memory/0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md`.
- [UID:0000VN] `by-memory/-ignored.md`.
- `by-project-structure/proposed-source-tree.md` as read-only placement context.
- Generated tracker and generated C++ as read-only evidence only.
- Executed reports `executed-b-agent-research/B002/00012B-DATManagers-source-quality.md` and `executed-b-agent-research/B015/000004-_DATFileMgr-class-source-quality.md`.

Generated state is stale for this target: `auto-generated/-ag-research-tracker.md` still lists [UID:000227] as `78/88`, and `auto-generated/NexusTK/archive/DATFileMgr.cpp` still contains an empty emitter marker for [UID:000227]. This should be corrected through normal source by-* validation/executed-report lifecycle, not by manual generated edits.

## Heuristic / Inference Reanalysis And Validation

### Raw Wrapper Role

Confirmed fact: `0x0049bd20-0x0049bd2c` is raw source-shaped code, not padding. The body establishes a stack frame, loads `[ecx+4]`, pops `ebp`, and tail-jumps to `0x0049cad0`. This is the same public-wrapper-to-private-manager pattern as [UID:00012C], except IDA does not model this start as a function and no callers survived to the wrapper entry.

Best inference: the source method is `DATFileMgr::FindEntryByName`, not a free helper or generated thunk. Evidence is the `this`-relative `+0x04 m_impl` load, accepted class layout, adjacent public wrapper method pattern, and accepted `HasDATEntry` C++ already calling this public method name.

Rejected alternatives:

- `DATFileMgrFindEntryForwarder` or `ForwardFindEntryByName`: useful documentation/recovery aliases, but final C++ should not expose wrapper mechanics as a source API name.
- `sub_49BD20` or raw address-shaped names: rejected for formal C++ under source-quality rules.
- File-local helper ownership: rejected because the body consumes `ecx` as a public `DATFileMgr *` and dereferences a class member.
- `_DATFileMgr` ownership: rejected for this wrapper range because the wrapper's only operation is converting public `DATFileMgr *this` to inner `_DATFileMgr *m_impl`.

### Public Method Name

The best source-facing name is `DATFileMgr::FindEntryByName`. It mirrors `_DATFileMgr::FindEntryByName`, the target by-memory filename, by-file proposed contents, and the accepted `HasDATEntry` formal C++ call. Exact original spelling is not symbol-proven, but the absence of original symbol proof is no longer a reason to keep final C++ blank.

Rejected alternatives:

- `FindDATEntry`: plausible, but weaker than the accepted private helper and support-doc vocabulary.
- `Open` / `OpenEntry`: rejected because `DATFile::Open` is the consumer that opens streams after lookup; this wrapper only resolves location.
- `HasDATEntry`: rejected because that name belongs to [UID:00012E], which passes null output and only returns existence.

### Output Record And Parameter Type

The public wrapper preserves the caller's stack arguments unchanged while changing only `ecx`. Therefore its parameter layout is the same as `_DATFileMgr::FindEntryByName`.

`DATEntryLocation *outLocation` is now implementation-ready:

- [UID:00043E] writes node `+0x0c` and `+0x10` into the output record.
- B002 resolved those node fields as `m_container` and `m_entryIndex`.
- `DATFile::Open` consumes the two returned values as container plus entry index, then computes the record pointer and payload length.
- [UID:0000UC] separates the 17-byte mapped table row (`DATEntryRecord`) from this two-field output location, so the output type should not be named `DATEntryRecord`.

Rejected alternatives:

- `_DWORD *` or `void *`: decompiler artifacts, not source-facing final types.
- `DATEntryRecord *`: wrong level; the output contains container pointer and index, not the mapped on-disk row.
- `DATEntryNode *`: wrong ownership; the node is internal resolver storage, while the output is a reduced public/internal location record.

### Source Placement And Emitter Route

The direct semantic owner/emitter remains [UID:00003I][DATFileMgr](by-class/DATFileMgr.md). The file route remains [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) / `NexusTK/archive/DATFileMgr.cpp`.

This target should not move to [UID:0000IO] as direct owner merely because the generated file owns the translation unit. By-structure requires the narrowest true semantic owner; this is a public `DATFileMgr` method.

### No-Xref / No-Function Evidence

The no-function/no-xref state is confirmed, not ignored:

- IDA has no function object at `0x0049bd20`.
- `xrefs_to`, `xref_query`, `find code_ref`, `find data_ref`, and little-endian pointer byte search all found no route to the wrapper entry.
- The target callee `0x0049cad0` has four refs, and the raw wrapper jump is one of them.
- The wrapper byte pattern is unique.

Impact: this caps confidence and prevents a final-audit score, but it does not block source C++ because the exact body, class member route, private callee signature, and neighboring public-wrapper pattern are all resolved.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x0049bd20-0x0049bd2c` is executable wrapper code, not padding. | Confirmed | MCP bytes, `insn_query`, unique signature, tail jump to `0x0049cad0`. | Adjacent ignored padding checked before and after; IDA no-function state checked. | None for range classification. |
| The direct source owner is `DATFileMgr`. | Strong | Body reads `[ecx+4]`, accepted public wrapper layout says `m_impl` at `+0x04`, adjacent public load wrapper has same shape. | File-local, `_DATFileMgr`, `DATFile`, and generated-wrapper-only alternatives rejected. | Exact original source spelling is not symbol-proven. |
| The method name should be `DATFileMgr::FindEntryByName`. | Strong inference | Private helper and target docs use `FindEntryByName`; accepted `HasDATEntry` C++ calls `g_pDATFileMgr->FindEntryByName(entryName, 0)`. | `FindDATEntry`, `OpenEntry`, and address/recovery aliases rejected. | Original symbol proof unavailable; confidence capped, not C++-blocking. |
| The second parameter type is `DATEntryLocation *`. | Strong inference | Tail jump preserves stack args; private helper formal C++ and `_DATFileMgr` class declaration use `DATEntryLocation *`; output writes are container/index. | `_DWORD *`, `DATEntryRecord *`, and `DATEntryNode *` rejected. | Exact original typedef spelling remains inferred. |
| Formal C++ is now safe. | Strong | Target clears score/emitter gate, owner/emitter route is valid, exact range is one wrapper body, all old name/type blockers have accepted support-doc answers. | No-xref/no-function/pointer absence reviewed; does not contradict source-authored method body. | Keep below final-audit scores. |

## Positive Evidence Summary

- Exact bytes and disassembly show one coherent public wrapper body.
- The wrapper changes only `ecx` from public wrapper object to inner manager pointer and tail-jumps, preserving arguments and return.
- Private callee [UID:00043E] now has formal C++ with resolved `DATEntryLocation` output semantics.
- Public class layout [UID:00003I] now resolves `m_impl` at `+0x04`.
- The adjacent public load wrapper [UID:00012C] uses the same source pattern and already emits formal C++.
- `HasDATEntry` [UID:00012E] already uses `g_pDATFileMgr->FindEntryByName(entryName, 0)` in accepted formal C++.
- Existing file/source-tree docs place the manager family in `NexusTK/archive/DATFileMgr.cpp`.

## Negative Evidence Summary

- No IDA function object exists at `0x0049bd20`.
- No direct code/data xrefs, no `code_ref`, no `data_ref`, and no stored absolute pointer to `0x0049bd20` were found.
- No original symbol or source/header path proves the exact public method spelling.
- The generated tracker and generated C++ marker are stale for this target.

These negatives cap the score but do not justify leaving formal C++ blank.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049bd19-0x0049bd20` | [UID:0000VN] `by-memory/-ignored.md` | pre-wrapper alignment | false | ignored | -1/-1 | already documented, reconfirmed |
| `0x0049bd20-0x0049bd2c` | [UID:000227] target | public `DATFileMgr::FindEntryByName` wrapper | true | [UID:00003I] | recommend `90/91` | needs formal C++ |
| `0x0049bd2c-0x0049bd30` | [UID:0000VN] `by-memory/-ignored.md` | post-wrapper alignment | false | ignored | -1/-1 | already documented, reconfirmed |
| `0x0049bd30-0x0049be41` | [UID:000439] constructor child | public wrapper constructor | true | [UID:00003I] | 86/90 | support context |
| `0x0049be70-0x0049be7c` | [UID:00012C] load wrapper | public `DATFileMgr::LoadDATFile` wrapper | true | [UID:00003I] | 90/93 | analogous emitted wrapper |
| `0x0049cad0-0x0049cba5` | [UID:00043E] private lookup | `_DATFileMgr::FindEntryByName` | true | [UID:000004] | 88/91 | target callee with formal C++ |

## Ranked Ownership Analysis

### 1. [UID:00003I] `DATFileMgr` Class

- Evidence for: `ecx` is a public wrapper object, `[ecx+4]` is documented `m_impl`, the adjacent public load wrapper has identical owner/emitter routing, and accepted support docs already name this as a public method family.
- Evidence against: no direct xrefs to the wrapper entry and no IDA function object.
- Decision: keep as direct owner/emitter. Negative reachability evidence caps confidence but does not change ownership.

### 2. [UID:0000IO] `DATFileMgr` File

- Evidence for: the method belongs in `NexusTK/archive/DATFileMgr.cpp`, and the by-file page owns the manager source family.
- Evidence against: by-structure requires the direct semantic owner when a class method is clear; the file is the source route, not the narrow owner.
- Decision: keep as source-file route through the class, not direct canonical owner.

### 3. [UID:000004] `_DATFileMgr` Class

- Evidence for: the tail-jump target is an `_DATFileMgr` method.
- Evidence against: the wrapper body itself starts from `DATFileMgr *this` and only loads `m_impl`; `_DATFileMgr` owns the callee, not the public wrapper.
- Decision: rejected as target owner.

### 4. No-Owner / Non-Emitting

- Evidence for: no direct xrefs/pointers to wrapper entry.
- Evidence against: exact source-authored wrapper bytes and source placement are clear, and the final C++ can be expressed in one source-level method body.
- Decision: rejected. The target remains reconstructable/emitting.

## Range / Split / Padding / Reclassification Analysis

No split is needed.

- `0x0049bd19-0x0049bd20` is seven `0xcc` bytes before the wrapper.
- `0x0049bd20-0x0049bd2c` is the exact wrapper body.
- `0x0049bd2c-0x0049bd30` is four `0xcc` bytes before `DATFileMgr::DATFileMgr`.
- [UID:0000VN] already records the two padding spans around this target with owner docs. The target page should preserve the live 2026-06-26 MCP proof; `by-memory/-ignored.md` can be left unchanged as same-or-greater detail unless the supervisor wants the newer session id added there.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested.

Source-facing documentation names to use:

- Public wrapper: `DATFileMgr::FindEntryByName`.
- Private callee: `_DATFileMgr::FindEntryByName`.
- Public wrapper field: `m_impl` at `DATFileMgr +0x04`.
- Output record: `DATEntryLocation`.
- Output fields: `m_container` and `m_entryIndex`.

Keep raw labels such as `sub_49BD20`, `sub_49CAD0`, and `_DWORD *` only as evidence/provenance, not in final C++.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has a valid owner/emitter route, has an average score above the current gate, covers exactly one source method body, and current support docs resolve the names/types that previously blocked code entry.

Exact formal `RECONSTRUCTION_CPP CODE` insertion content:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)
{
    return m_impl->FindEntryByName(entryName, outLocation);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavior preservation:

- The body loads `m_impl` and calls the private helper with the same two arguments.
- It propagates the helper's boolean return.
- It does not inspect or modify the output record itself, matching the tail-jump wrapper semantics.
- It uses `0`-era compatible surrounding code conventions indirectly through support docs; this body does not need a null literal.

Most plausible source shape:

- A public wrapper method beside `DATFileMgr::LoadDATFile` is more plausible than a raw forwarder helper name.
- `DATEntryLocation` matches the current internal helper and consumer semantics.
- `m_impl` matches the accepted public wrapper layout and avoids decompiler-style `this[1]`.

## Score And Metadata Recommendation

Current metadata:

- `COMPLETION:85`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00003I`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00003I`
- blank formal C++

Recommended metadata:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00003I` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:00003I` unchanged
- `EMITTER_POSITION_OPTIONAL:` unchanged/blank
- formal C++ populated with the block above

Score rationale:

- Completion rises because the report resolves the stale name/type/C++ blockers, records live MCP boundary and negative reachability checks, and supplies exact formal code.
- Confidence rises because the wrapper bytes, private helper type, output record, owner route, and analogous load wrapper all agree.
- Confidence stays below the adjacent load wrapper's `93` because this target has no IDA function object and no direct entry refs/pointers, while [UID:00012C] has direct callers and a modeled function.
- Scores stay below `95+` because no original source symbol proves exact spelling, and the broader class/file declarations still carry some inferred helper/type names.

## Recommended Target Doc Changes

Target path: `by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md`.

Apply these changes if accepted:

- Change metadata to `COMPLETION:90`, `CONFIDENCE:91`, leaving owner/emitter/reconstructable fields unchanged.
- Replace the blank formal `RECONSTRUCTION_CPP CODE` block with the exact block in this report.
- Update Status/Signature/Reconstruction Notes to say final public method spelling and output type are now resolved enough for formal C++:
  - `DATFileMgr::FindEntryByName`
  - `_DATFileMgr::FindEntryByName`
  - `DATEntryLocation *outLocation`
  - `m_impl` at public wrapper offset `+0x04`
- Preserve negative evidence:
  - no IDA function at `0x0049bd20`;
  - no direct xrefs to the wrapper entry;
  - no code/data refs and no stored pointer bytes to the wrapper start;
  - raw jump to `0x0049cad0` is one of four refs to the private helper.
- Add the 2026-06-26 MCP session `80de0a67` proof: health, lookup, bytes, insn range, xrefs, pointer/body byte searches, private helper decompile, DATFile::Open/HasDATEntry/LoadDATFileIndex consumer checks, and adjacent load wrapper comparison.
- Update score rationale so "C++ remains blank" is removed as stale.
- Add cross-reference to [UID:00043E] private helper and [UID:00012E] `HasDATEntry` if not already present at enough detail.

## Recommended Support Doc Changes

Support paths to update or explicitly mark same-or-greater detail during implementation:

- `by-class/DATFileMgr.md` [UID:00003I]:
  - Add/confirm public method row for [UID:000227] as `DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)`.
  - Replace stale wording that final public method spelling is a blocker with "inferred but implementation-ready".
  - Record that [UID:000227] now carries formal C++ like [UID:00012C].
- `by-file/DATFileMgr.md` [UID:0000IO]:
  - Update the [UID:000227] proposed contents / manager range wording from candidate/blank to public wrapper method with formal child C++.
  - If editing this file, add [UID:000227] to the manager-owned child emission map as an adjacent public wrapper outside [UID:00012B]'s half-open parent range, routed through [UID:00003I].
  - Preserve source route `NexusTK/archive/DATFileMgr.cpp`; do not split to standalone `_DATFileMgr.cpp` or `DATFileResolver.cpp`.
- `by-memory/0x0049bd30-0x0049d6ed.DATManagers.md` [UID:00012B]:
  - Same-or-greater detail already present for the target as an outside adjacent public find forwarder and for `DATEntryLocation`; no edit is required unless the supervisor wants the new formal-C++ status reflected in the covered-range row.
- `by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md` [UID:00043E]:
  - Same-or-greater detail already present for private helper behavior and `DATEntryLocation`; no edit required.
- `by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md` [UID:00012C]:
  - Same-or-greater adjacent wrapper pattern already present; no edit required.
- `by-memory/0x0049c700-0x0049c71d.HasDATEntry.md` [UID:00012E]:
  - Same-or-greater public method call already present; optional cross-link to [UID:000227] if support docs are being touched.
- `by-class/_DATFileMgr.md` [UID:000004]:
  - Same-or-greater private helper declaration already present; no edit required.
- `by-memory/-ignored.md` [UID:0000VN]:
  - Same-or-greater padding ranges already present. If implementation chooses to refresh evidence, add only the current MCP proof for `0x0049bd19-0x0049bd20` and `0x0049bd2c-0x0049bd30`; no coverage-report edit.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` edit is requested. Do not edit `by-memory/-coverage-report.md`.

No manual generated tracker row text is supplied. `auto-generated/-ag-research-tracker.md` and `auto-generated/NexusTK/archive/DATFileMgr.cpp` are stale for this target and should refresh through normal validator/executed-report lifecycle after source docs are updated.

## Open Questions With Attempted Resolution

- Public method spelling: resolved to inferred implementation-ready `DATFileMgr::FindEntryByName`. Original symbol proof is unavailable, but accepted support docs and call-site source shape make this the best source-facing name.
- Output parameter type: resolved to inferred implementation-ready `DATEntryLocation *`. It is not a `DATEntryRecord *`, `DATEntryNode *`, or raw `_DWORD *`.
- Reachability/no-xref: resolved as true negative evidence. It caps confidence but does not block C++ because the body is exact, unique, source-shaped, and has a valid source owner.
- Padding boundaries: resolved. Existing ignored ranges are correct and live MCP reconfirmed them.
- Source placement: resolved to [UID:00003I] direct owner, [UID:0000IO] file route.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `90/91`; not high enough for `95+`.
- Remaining uncertainty: exact original source spelling and why no direct route to the public wrapper survived. Both are documented and do not block the recommended implementation.

## Validator Results

Implementation validators run from `source-3/project-documentation` after accepted edits:

- `python .\tools\validator.py --mode file --file by-memory\0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md --apply --queue-timeout 240`
  - Exit code: `0`
  - `command_id`: `000000003248`
  - `command_timestamp`: `2026-06-26T19:50:19-04:00`
  - `ok`: `1`
  - Side effects: completion/confidence/canonical-owner registry updates for [UID:000227], formal C++ block registry update from blank to block, UID link insert/update, reference index additions, projected stats update.
  - `generated_refresh`: `deferred`; `generated_refresh_command_id`: `000000003248`; `generated_refresh_timestamp`: `2026-06-26T19:50:19-04:00`.
- `python .\tools\validator.py --mode file --file by-class\DATFileMgr.md --apply --queue-timeout 240`
  - Exit code: `0`
  - `command_id`: `000000003250`
  - `command_timestamp`: `2026-06-26T19:50:35-04:00`
  - `ok`: `1`
  - Side effects: UID link inserts for [UID:000227]/[UID:00012C], reference index addition for [UID:000227], projected stats update.
  - `generated_refresh`: `deferred`; `generated_refresh_command_id`: `000000003250`; `generated_refresh_timestamp`: `2026-06-26T19:50:35-04:00`.
- `python .\tools\validator.py --mode file --file by-file\DATFileMgr.md --apply --queue-timeout 240`
  - Exit code: `0`
  - `command_id`: `000000003251`
  - `command_timestamp`: `2026-06-26T19:50:42-04:00`
  - `ok`: `1`
  - Side effects: UID link inserts for [UID:000227]/[UID:00012B], projected stats update.
  - `generated_refresh`: `deferred`; `generated_refresh_command_id`: `000000003251`; `generated_refresh_timestamp`: `2026-06-26T19:50:42-04:00`.

No optional support by-* files were edited, so no optional support validators were required. Generated/project-level/manual coverage files were not manually edited; validator-owned projected stats and registry side effects are recorded above.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/000227-DATFileMgrFindEntryForwarder-source-quality.md`.
- Modified by-* docs:
  - `by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md`
  - `by-class/DATFileMgr.md`
  - `by-file/DATFileMgr.md`
- Modified generated files: none.
- Modified project-level/generated state manually: none. The scoped validators reported projected stats/registry updates and deferred generated refresh.
- Modified manual coverage reports: none.
- Modified tool/validator state manually: none. The scoped validators updated their own registry/state as reported above.
- IDA DB edits: none.
- Leases: B001 leased the three modified by-* files immediately before editing, then released all three immediately after the validator batch. The post-release `current_leases.md` report shows no active B001 lease.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted this report and assigned implementation in `goal.md`.
- [x] Update target `by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md` metadata to `COMPLETION:90`, `CONFIDENCE:91`, with `CANONICAL_OWNER:00003I`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00003I` unchanged. Proof: target header now shows `90/91`, owner `00003I`, reconstructable true, emitter `00003I`, blank emitter position.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report into [UID:000227]. Proof: target formal block now contains `bool DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation) { return m_impl->FindEntryByName(entryName, outLocation); }`.
- [x] Preserve current live MCP evidence in the target: session `80de0a67`, health ok, lookup no-function at wrapper addresses, exact bytes/signature, disassembly, no wrapper xrefs/code refs/data refs/pointer bytes, unique body bytes, and four refs to `0x0049cad0`. Proof: target `Raw Code Evidence`, `Private Helper And Consumer Evidence`, and `Negative Evidence` sections record all listed facts.
- [x] Preserve private helper behavior evidence: string normalization, resolver lookup, sentinel/no-hit false return, optional two-dword `DATEntryLocation` output, and true return on hit. Proof: target `Private Helper And Consumer Evidence` records the corrected decompile/analyze facts.
- [x] Preserve source-quality resolution: public `DATFileMgr::FindEntryByName`, private `_DATFileMgr::FindEntryByName`, `m_impl`, `DATEntryLocation`, `m_container`, and `m_entryIndex`; keep raw/decompiler labels only as evidence. Proof: target `Source-Quality Resolution` records these names/types and the formal C++ uses source-facing names only.
- [x] Preserve rejected alternatives: raw `sub_49BD20`, recovery forwarder names as final source, file-local helper ownership, `_DATFileMgr` direct ownership for the wrapper, `DATEntryRecord *`, `DATEntryNode *`, and raw `_DWORD *` output type. Proof: target `Source-Quality Resolution` rejected-alternatives list records each item.
- [x] Update `by-class/DATFileMgr.md` [UID:00003I] with the resolved public find wrapper method and formal-C++ child route, or record same-or-greater-detail proof if already present. Proof: class method table now includes [UID:000227] as `FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)`, and ownership/data-issues notes record that [UID:000227] emits formal C++ like [UID:00012C].
- [x] Update `by-file/DATFileMgr.md` [UID:0000IO] with the resolved [UID:000227] child emission/source-route status, or record same-or-greater-detail proof if already present. Proof: file proposed contents, manager range row, file-level rationale, and manager-owned child emission map now list [UID:000227] as public `DATFileMgr::FindEntryByName` with formal child C++ routed through [UID:00003I] and `NexusTK/archive/DATFileMgr.cpp`.
- [x] Confirm [UID:00012B], [UID:00043E], [UID:00012C], [UID:00012E], [UID:000004], and [UID:0000VN] already carry same-or-greater support detail, or make only the targeted cross-link/evidence refreshes listed in this report. Proof: implementation recheck found [UID:00012B] already cross-links [UID:000227] and `DATEntryLocation`; [UID:00043E] already has formal `_DATFileMgr::FindEntryByName` C++ with `DATEntryLocation`/`m_container`/`m_entryIndex` and cross-links [UID:000227]; [UID:00012C] already documents the analogous `m_impl` wrapper and formal C++; [UID:00012E] already calls `g_pDATFileMgr->FindEntryByName(entryName, 0)`; [UID:000004] already declares `_DATFileMgr::FindEntryByName(..., DATEntryLocation *outLocation)`; [UID:0000VN] already records `0x0049bd19-0x0049bd20` and `0x0049bd2c-0x0049bd30` padding around [UID:000227]. No optional support edit was needed.
- [x] Do not edit generated files, project-level generated files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`. Proof: no manual edits were made outside the three by-* docs and this agent-owned report; validators reported their own registry/projected-stats side effects; no IDA DB or manual coverage file was touched.
- [x] Run scoped validators for every changed by-* file from `source-3/project-documentation` and record command id, timestamp, exit code, ok count, generated-refresh state, and warnings. Proof: validator results section above records commands `000000003248`, `000000003250`, and `000000003251`, all exit `0`, `ok: 1`, `generated_refresh: deferred`.
- [x] Expect generated tracker/C++ stale markers for [UID:000227] to refresh through validator/executed-report lifecycle only; do not supply or apply manual generated row text. Proof: no manual generated row text was supplied or applied; validator generated refresh was deferred for the scoped file commands.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` contains `B001-implement-000227-datfilemgr-find-entry-forwarder-source-quality-20260626`.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target page now records MCP session `80de0a67`, byte/range/xref/search/helper/consumer evidence, source-quality resolution, rejected alternatives, score rationale, and formal C++; class/file support pages record public method/source-route/emission-map details.
- [x] Metadata/score/C++ changes applied or explicitly not applied with reason. Proof: [UID:000227] changed from `85/89` to `90/91`; owner/emitter/reconstructable metadata stayed unchanged; formal C++ populated exactly.
- [x] Historical stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target `Changes`, `Negative Evidence`, and `Source-Quality Resolution` sections retain the old blank-C++ rationale as superseded and preserve no-function/no-xref/no-pointer evidence plus rejected name/type/owner alternatives.
- [x] Validators run and results recorded. Proof: commands `000000003248`, `000000003250`, `000000003251`; all exit `0`, `ok: 1`.
- [x] Generated report refresh handled by validator lifecycle; manual coverage/tracker edits excluded. Proof: generated refresh was reported deferred by the scoped validators; no manual generated/project-level/manual coverage edits were made.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none. All accepted items were applied or confirmed already present at same-or-greater detail.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000227-DATFileMgrFindEntryForwarder-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/000227-DATFileMgrFindEntryForwarder-source-quality.md","timestamp":"2026-06-26T19:57:26","uid":"000227"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
