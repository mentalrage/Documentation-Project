** TARGET-REPORT-UID:00041F **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Agent-B011 Report: [UID:00041F] VectorGrowLayer Source Quality

Date: 2026-06-30
Assignment: `B011-report-00041F-VectorGrowLayer-direct-research-20260630`
Mode: report-first research only
Target: `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md`

## Final Recommendation

Promote `[UID:00041F]` from below-gate `NONE`/non-emitting support to a NewHumanImageLib file-owned source-disposition marker:

- `COMPLETION:87`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000LR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LR`
- formal C++: comment marker only, not a standalone vector-grow body

The direct function is a compiler-emitted vector growth/insert slow path for `NewHumanLayerEntry` rows. Its source behavior is already expressed by the accepted constructor and `LoadLayerTable` source as `m_layerEntries.push_back(layer)`. A standalone helper body would encode STL/template allocation lowering and runtime helpers rather than product source. The target should still emit enough source-disposition text to resolve the current empty-emitter/no-owner state.

## Current Target State

Current target header:

- UID: `00041F`
- completion/confidence: `84/86`
- owner/emitter: `NONE` / blank
- reconstructable: `TRUE`
- formal C++: blank
- item summary: exact below-gate child support page for inferred `VectorGrowLayer`

The current page correctly captures the range, the two known callers, and the rejected standalone-helper direction. It is now conservative below the current evidence level because this pass rechecked IDA and current support docs and found a narrow file-owned marker route.

## Evidence Checked

MCP was available and used. No fallback-only path was taken.

IDA MCP state:

- MCP initialize returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- Active database: `supervisor_resume_20260629`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Imagebase: `0x400000`.
- Health: `status=ok`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`.
- Worker process reported by `idb_list`: `pid=17592`, active, not analyzing.
- MCP tools used read-only: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xref_query`.
- MCP write/mutation tools used: none.

Local documentation and report evidence checked:

- `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md`
- `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md`
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
- `by-file/NewHumanImageLib.md`
- `by-class/NewHumanImageLib.md`
- `by-type/by-struct/NewHumanImageLibLayout.md`
- `by-resource/new-human-motion-tables.md`
- `by-file/VectorHelpers.md`
- sibling helper pages `VectorGrowAcc2Drw`, `VectorGrowMotion`, and `VectorGrowPart`
- marker precedents `UInt32VectorConstructor` and `RecordVectorInsert`
- executed B011 constructor report and B006 `LoadLayerTable` report
- auto-generated tracker, memory coverage, and completion stats rows, read-only

Searches covered `00041F`, `004e50a0`, `0x004e50a0`, `004e523e`, `0x004e523e`, `VectorGrowLayer`, `VectorGrow`, `LoadLayerTable`, `NewHumanImageLibLoadLayerTable`, and adjacent helper names across active agent research, executed research, archived research, and by-* docs.

Numeric conversions used `tools/int_convert.py` for documented decimal equivalents:

- `0x20` = `32`
- `0x19e` = `414`
- `0x23` = `35`
- `0x1000` = `4096`
- `0x7ffffff` = `134217727`

## Claim And Incorporation Ledger

| Claim | Evidence | Disposition |
| --- | --- | --- |
| Target range is exact for a real function at `0x004e50a0`. | MCP `lookup_funcs` reports `sub_4E50A0`, size `0x19e` (`414`), and no function at `0x004e523e`; next sibling function is `0x004e5240`. | Incorporate in target. |
| The body is a vector growth/insert slow path over `0x20` (`32`) byte rows. | MCP decompile/disassembly show `(pos - begin) >> 5`, `(end - begin) >> 5`, `shl ..., 5`, two 16-byte row copies, and prefix/suffix loops advancing by `0x20`. | Incorporate in behavior and score rationale. |
| The row type is `NewHumanLayerEntry`. | Caller pages and layout page define layer entries as 32-byte records; constructor and `LoadLayerTable` build those rows and pass their vector header to this helper on capacity-full paths. | Incorporate. |
| The only code callers are the constructor and `LoadLayerTable`. | MCP `analyze_function` and `xref_query` report two incoming callsites: `0x004dffb2` from `sub_4DFD10` and `0x004e1171` from `sub_4E1040`. | Incorporate. |
| Direct canonical owner should be `NewHumanImageLib.md` (`0000LR`). | The helper receives the vector triplet, not a `NewHumanImageLib *`; accepted source callers are in NewHumanImageLib source and file-level ownership is the narrow source route. | Recommend metadata change. |
| Class owner `000092` is not the best direct owner. | Class page owns semantic methods, but MCP call setup passes `ecx` as the vector header or `this+0x10`, not the class object itself. | Reject for direct target metadata. |
| `VectorHelpers.md` (`0000P3`) should not be the direct canonical owner. | This helper is source-adjacent to NewHuman layer entries and has only local NewHuman callers; VectorHelpers is appropriate as fallback compatibility template support. | Reject as direct owner, keep as fallback mention. |
| A standalone C++ helper body is inappropriate. | The body is STL/template allocation and move/copy lowering, including allocator alignment and free checks; product source is `m_layerEntries.push_back(layer)` in callers. | Recommend comment marker only. |
| TimerMgr UID hits are unrelated. | Search found stale/colliding `00041F` references in TimerMgr address context `0x00597b80`, not this target range; prior NewHuman report also rejected TimerMgr cleanup from this scope. | Exclude from this report except as a known UID-collision risk. |

### Callback Verification Update - 2026-06-30

| Claim | Verification state | Proof |
| --- | --- | --- |
| Exact target range/function facts. | applied | `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md` now records raw `sub_4E50A0`, size `0x19e` (`414`, Verified with int_convert.py), no function at `0x004e523e`, successor `sub_4E5240`, and exact caller sites. Target validators `000000002102` and `000000002111` passed. |
| `0x20` / `32` byte `NewHumanLayerEntry` grow/insert behavior. | applied | Target, `by-file/NewHumanImageLib.md`, `by-class/NewHumanImageLib.md`, and `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` describe the layer-vector receiver, row size, allocation/relocation/free, begin/end/capacity update, and typed source route. |
| Constructor and UID00041A are the only code callers. | applied | Target and support docs record caller sites `0x004dffb2` and `0x004e1171`, with constructor and `LoadLayerTable` source represented as `m_layerEntries.push_back(layer)`. |
| Direct canonical owner/emitter should be `0000LR`. | applied | Target metadata is `CANONICAL_OWNER:0000LR`, `EMITTER_UIDS:0000LR`, `RECONSTRUCTABLE:TRUE`, `COMPLETION:87`, `CONFIDENCE:89`, and blank optional position. File/class/cluster support docs record file-local marker ownership. |
| Class owner `000092` rejected for direct metadata. | applied | Target and class/cluster support docs state the receiver is the layer vector header / `this+0x10`, not a `NewHumanImageLib *` method receiver. |
| Direct `VectorHelpers` ownership rejected, fallback retained. | applied | Target, `by-file/VectorHelpers.md`, file/class/cluster support docs record VectorHelpers only as a compatibility-template fallback if typed NewHuman source cannot regenerate the helper. |
| No standalone helper body; formal marker only. | applied | Target formal block contains the exact accepted marker and no standalone `VectorGrowLayer` body. Generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp` contains the exact marker in the current header state. |
| TimerMgr UID-collision exclusion. | applied | Target and support docs reject unrelated TimerMgr UID-collision cleanup for this callback; no TimerMgr docs were edited. |
| Constructor support refresh. | already-present | `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md` already recorded the constructor callsite, `m_layerEntries.push_back(layer)`, and UID00041F source behavior; no edit was needed. |
| LoadLayerTable support refresh. | applied | `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md` was updated and validated by `000000002112`; its C++ remains unchanged. |
| NewHumanImageLib file/class/cluster support sync. | applied | `by-file/NewHumanImageLib.md`, `by-class/NewHumanImageLib.md`, and `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` were updated and validated by `000000002140`, `000000002141`, and `000000002142`. |
| Layout/resource support edits. | excluded-with-reason | Layout/resource pages already had the needed row/table evidence and were outside the accepted callback edit scope. |

## IDA MCP Function Facts

`lookup_funcs`:

- `0x004e50a0`: function `sub_4E50A0`, size `0x19e` (`414`)
- `0x004e523e`: no function
- `0x004e5240`: next sibling function `sub_4E5240`
- `0x004e4f10`: previous sibling `sub_4E4F10`

`analyze_function 0x004e50a0`:

- name: `sub_4E50A0`
- prototype: `int __thiscall(_DWORD *this, _OWORD *, _OWORD *)`
- size: `414`
- instructions: `152`
- basic blocks: `32`
- cyclomatic complexity: `15`
- callees: `__invalid_parameter_noinfo_noreturn`, `sub_421500`, `sub_5C7526`, `operator new`
- callers: `sub_4DFD10`, `sub_4E1040`
- xrefs-to: `0x004dffb2`, `0x004e1171`

`decompile 0x004e50a0` confirms:

- insertion index is `((a2 - begin) >> 5)`.
- current size is `((end - begin) >> 5)`.
- max-size guard compares against `0x7ffffff` (`134217727`) records.
- growth capacity uses old capacity plus half, clamped to required size.
- allocation byte count is `newCapacity * 0x20`.
- large allocation path overallocates by `0x23` (`35`), aligns to a 32-byte boundary, and stores the raw pointer immediately before the aligned block.
- inserted row copy writes two 16-byte chunks from the source row.
- prefix and suffix row loops copy records in `0x20` increments.
- old storage is freed through `sub_5C7526`; large allocations validate the alignment cookie and can call `__invalid_parameter_noinfo_noreturn`.
- vector header fields are updated to new begin, end, and capacity.

`disasm 0x004e50a0` key instructions:

- `0x004e50ae`: `mov edi, ecx`, receiver is the vector header.
- `0x004e50b4`: `sar eax, 5`, insertion index by 32-byte row.
- `0x004e50bf`: `sar eax, 5`, current row count.
- `0x004e50c2`: `cmp eax, 7FFFFFFh`, max-size guard.
- `0x004e50f8`: `shl ecx, 5`, allocation size by 32-byte rows.
- `0x004e5112`: `lea eax, [ecx+23h]`, large allocation overhead.
- `0x004e5131`: `and ebx, 0FFFFFFE0h`, 32-byte alignment.
- `0x004e515e` through `0x004e5168`: two 16-byte writes copy the new row.
- `0x004e51a0` through `0x004e51b7`: prefix copy loop.
- `0x004e51c6` through `0x004e51dd`: suffix copy loop.
- `0x004e5209`: call to `sub_5C7526` frees old storage.
- `0x004e5219`, `0x004e521b`, `0x004e5223`: update vector begin/end/capacity.
- `0x004e5231`: `retn 8`.

## Caller Evidence

Constructor callsite `0x004dffb2`:

- In `sub_4DFD10`, the fast path compares current end and capacity, copies a 32-byte row from stack local `var_150`, and increments the vector end by `0x20`.
- On capacity full, it calls:
  - `lea ecx, [ebp+var_150]`
  - `push ecx`
  - `push eax`
  - `mov ecx, edi`
  - `call sub_4E50A0`
- The accepted constructor page already expresses the source behavior as a layer row append, not a helper call.

`LoadLayerTable` callsite `0x004e1171`:

- In `sub_4E1040`, the fast path uses `[edi+0x14]` as current end and `[edi+0x18]` as capacity for the vector at `[edi+0x10]`.
- It copies the 32-byte stack row to the current end and increments `[edi+0x14]` by `0x20`.
- On capacity full, it calls:
  - `lea ecx, [ebp+var_48]`
  - `push ecx`
  - `push eax`
  - `lea ecx, [edi+0x10]`
  - `call sub_4E50A0`
- This proves the helper receiver is `&this->m_layerEntries`, not `this`.

MCP `xref_query` found exactly two code xrefs to the target and no additional external callers in this pass.

## Current Documentation Evidence

`by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md`:

- Already promoted to owner/emitter `000092` at `88/90`.
- Emits `void NewHumanImageLib::LoadLayerTable(const wchar_t *tableName)`.
- Source appends `NewHumanLayerEntry` with `m_layerEntries.push_back(layer)`.
- Correctly treats UID00041F as the capacity-path vector helper dependency.

`by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`:

- Owner/emitter `000092`, score `91/92`.
- Constructor inline `Layer.tbl` loop appends layer entries.
- Calls UID00041F only on capacity-full path.
- C++ already expresses append semantics.

`by-file/NewHumanImageLib.md`:

- Owner file `0000LR`, score `87/85`.
- Projects to `NexusTK/render/`.
- Already recognizes UID00041F as the NewHumanImageLib layer vector helper.
- This is the best direct canonical owner for a source-adjacent helper marker.

`by-class/NewHumanImageLib.md`:

- Class UID `000092`, owner/emitter `0000LR`.
- Lists UID00041F as a below-gate support page called from constructor and `LoadLayerTable`.
- Should be synchronized to show that the helper remains non-method source support, now routed through the file owner.

`by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`:

- Non-emitting container, score `85/89`.
- Lists UID00041F as below-gate/no-owner support.
- Should remain a container but update the child row if this target is promoted.

`by-type/by-struct/NewHumanImageLibLayout.md`:

- Defines `NewHumanLayerEntry` as a 32-byte structure:

```cpp
struct NewHumanLayerEntry
{
    int layerId;
    char name[20];
    int childCount;
    int *childIndexes;
};
```

- Defines the layer vector triplet at `this+0x10`, `this+0x14`, and `this+0x18`.

`by-resource/new-human-motion-tables.md`:

- Establishes `Layer.tbl` as a resource table payload with `LayerInformation`, count `13`, and row size `32`.
- Supports the layer-entry semantics but should not own this helper.

`by-file/VectorHelpers.md`:

- Provides the generic vector/template helper fallback family.
- Useful as fallback support in the marker, but too broad as direct canonical owner for this local NewHuman helper.

## Ownership Analysis

Ranked disposition:

1. `0000LR` `by-file/NewHumanImageLib.md`: best direct owner. The function serves only NewHumanImageLib layer-entry vector appends, the semantic callers are in this file, and file-level ownership avoids incorrectly making a vector-header helper into a class method.
2. `000092` `by-class/NewHumanImageLib.md`: correct semantic class context, but not the direct owner. MCP call setup proves `ecx` is a vector header or `this+0x10`, not a `NewHumanImageLib *`.
3. `0000P3` `by-file/VectorHelpers.md`: valid compatibility fallback for the emitted marker if the recovered source cannot regenerate the out-of-line helper. It is not the narrow direct owner because this instance is tied to NewHuman layer rows and has no cross-module callers.
4. `00017R` local method cluster: useful context only. It is a non-emitting container and should not become the helper owner.
5. `NONE`: no longer the best disposition. The exact function and callers are understood, and a source-safe marker route exists.

## Source Placement And C++ Recommendation

The target should not receive a decompiler-shaped function body. The formal C++ block should be a source-disposition marker routed through `0000LR`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this NewHumanLayerEntry vector-growth slow path is covered by [UID:0002JR]
// and [UID:00041A] m_layerEntries.push_back(layer) source, or by a
// [UID:0000P3] VectorHelpers compatibility template if the recovered typed
// source cannot regenerate this out-of-line helper.
// Do not emit a standalone decompiler-shaped VectorGrowLayer helper body here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Rationale:

- The source-level expression is already present in accepted caller source: `m_layerEntries.push_back(layer)`.
- The target body is allocator/vector slow-path lowering, including max-size guard, allocation alignment, relocation, and free checks.
- A marker is consistent with existing accepted vector-helper precedent for `UInt32VectorConstructor` and `RecordVectorInsert`.
- The marker gives the validator and generated source a non-empty disposition without inventing product source that was not authored as a named helper.

Implementation note for callback: validator reference expansion may rewrite `[UID:...]` comments into markdown links inside the formal block. If that occurs, restore the exact marker text above and rerun a scoped UID-only validator pass for the target, matching prior vector-helper marker practice.

## Negative Evidence And Rejected Alternatives

Rejected: leave target unchanged at `84/86`, `NONE`, blank emitter.

- Current no-owner/no-emitter status was reasonable when this page was first created as a below-gate support page.
- Current MCP and support docs now provide exact range, exact callsites, element size, source caller semantics, and a file-owner marker route.
- The no-improvement exception does not apply because a concrete improvement exists.

Rejected: make `000092` the direct canonical owner.

- The function is not a member method over `NewHumanImageLib *`.
- It receives the vector header directly in `ecx`.
- The class should remain semantic context and support sync, not direct owner metadata.

Rejected: make `0000P3` `VectorHelpers.md` the direct canonical owner.

- The generic vector-helper file is a fallback compatibility route.
- The helper is only observed in NewHuman layer-entry append paths.

Rejected: emit a standalone `VectorGrowLayer` C++ function body.

- That would reconstruct compiler/library lowering rather than authored source.
- It would force raw allocation/free helper names or invented template internals into source.
- It would duplicate behavior already represented by caller `push_back` source.

Rejected: paste the helper body into constructor or `LoadLayerTable`.

- Both caller pages are already higher-confidence semantic source pages.
- Their `push_back` expressions are the correct high-level representation.

Rejected: act on TimerMgr UID hits.

- Search found unrelated `00041F` hits under TimerMgr address context `0x00597b80-0x00597c99`.
- This assignment is for `0x004e50a0-0x004e523e.VectorGrowLayer.md`.
- Any duplicate/stale UID collision is supervisor/validator-owned cleanup and outside this target-specific callback.

## Score Recommendation

Recommended target metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LR | OPTIONAL - set UID of owning file/class/resource/etc, blank if none ***
*** RECONSTRUCTABLE:TRUE | OPTIONAL - TRUE if enough evidence exists to implement code, FALSE otherwise ***
*** EMITTER_UIDS:0000LR | OPTIONAL - comma-separated UIDs that should include this code in their generated output ***
```

Why `87/89`:

- Exact IDA function, range, callers, row size, and low-level behavior are now reverified.
- Accepted NewHumanImageLib caller source and layout docs supply the source-level row semantics.
- File-owner route and marker precedent resolve the empty formal/emitter problem.
- Remaining uncertainty is naming/source-policy only: `VectorGrowLayer` is still an inferred descriptive helper name, and final generated compatibility-template mechanics belong to the implementation callback.

## Recommended Target Doc Changes

If assigned for implementation, update `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md`:

- Promote metadata to `87/89`, owner/emitter `0000LR`, reconstructable true.
- Replace "below-gate/no-owner/non-emitting" wording with "file-owned source-disposition marker".
- Add current MCP facts from this report:
  - exact size `0x19e` (`414`)
  - exact two callsites `0x004dffb2` and `0x004e1171`
  - vector receiver/caller setup
  - row width `0x20` (`32`)
  - max-size and allocation/relocation behavior
- Insert the formal C++ marker shown above.
- Keep rejection of standalone helper body.
- Keep explicit note that source behavior is `m_layerEntries.push_back(layer)` in constructor and `LoadLayerTable`.

## Recommended Support Doc Changes

Support sync should be narrow and should not change semantic C++ in the already-promoted callers:

- `by-file/NewHumanImageLib.md`: update UID00041F from below-gate support to file-owned marker/emitter support at `87/89`; note direct owner `0000LR` and no standalone helper body.
- `by-class/NewHumanImageLib.md`: update helper/method inventory to say UID00041F remains non-method vector-header support but is now file-owned marker-emitting support.
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`: update the active child row/status for UID00041F; cluster remains non-emitting.
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`: only refresh support note if needed; constructor C++ should remain unchanged.
- `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md`: only refresh support note if needed; `LoadLayerTable` C++ should remain unchanged.
- `by-file/VectorHelpers.md`: add or adjust only a short support note that UID00041F uses a NewHumanImageLib file-owned marker with VectorHelpers as compatibility fallback, not direct owner.

The layout and resource pages already contain the necessary row-size and table evidence. They do not need edits unless an implementation callback adds a consistency note.

## Validator Plan For Implementation Callback

Report-only note superseded by accepted implementation callback on 2026-06-30. Scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command id | Timestamp | Exit / ok | Generated refresh | Notes |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md` | `000000002102` | `2026-06-30T02:58:10-04:00` | exit `0`, `ok: 1` | completed | Normal target validator after metadata/marker insertion; generated C++ refreshed. |
| `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md` | `000000002111` | `2026-06-30T03:05:05-04:00` | exit `0`, `ok: 1` | skipped by `--uid-only` | Reran after restoring exact formal marker text that normal reference expansion had rewritten. |
| `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md` | `000000002112` | `2026-06-30T03:05:27-04:00` | exit `0`, `ok: 1` | completed | Support note updated; C++ unchanged. |
| `by-file/VectorHelpers.md` | `000000002113` | `2026-06-30T03:05:27-04:00` | exit `0`, `ok: 1` | completed | Added compatibility-fallback/direct-owner rejection note; unrelated existing `missing_ref_uid` warnings for `0003TP`, `0003SR`, and `0003SC`. |
| `by-file/NewHumanImageLib.md` | `000000002140` | `2026-06-30T03:34:51-04:00` | exit `0`, `ok: 1` | completed | Support text updated; generated refresh completed. |
| `by-class/NewHumanImageLib.md` | `000000002141` | `2026-06-30T03:35:16-04:00` | exit `0`, `ok: 1` | completed | Support text updated; generated refresh completed. |
| `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` | `000000002142` | `2026-06-30T03:35:49-04:00` | exit `0`, `ok: 1` | completed | Support text updated; unrelated existing `missing_ref_uid 0003UD` warning. |

Generated freshness: B011's last relevant generated refresh was `000000002142` at `2026-06-30T03:35:49-04:00`. A later concurrent refresh advanced `auto-generated/NexusTK/render/NewHumanImageLib.cpp` to header `validator-command-id: 000000002145`, `validator-refreshed-at: 2026-06-30T03:38:55-04:00`; the file still contains the exact UID00041F marker at generated lines `849-854`. The source target still has the exact formal marker text after the support validators.

Recommended callback validation after edits:

> Executable block R001 was removed from this report and preserved verbatim in [00041F-VectorGrowLayer-source-quality-removed.md](00041F-VectorGrowLayer-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add scoped validator runs for constructor, `LoadLayerTable`, and `VectorHelpers.md` only if those files are edited. If formal marker comments are expanded by reference normalization, restore the exact marker and rerun the target with `--uid-only`.

## Open Questions With Attempted Resolution

Open: exact original source spelling for this helper.

- Resolution: non-blocking. The name `VectorGrowLayer` remains an inferred documentation name. The recommended marker avoids depending on an authored helper name.

Open: whether final generated source should rely entirely on caller `push_back` or also on a VectorHelpers compatibility template.

- Resolution: non-blocking for this target. The marker allows both routes and assigns the direct owner to `NewHumanImageLib.md`.

Open: duplicate/stale `00041F` references in TimerMgr docs.

- Resolution: out of scope. This report documents the collision and excludes it. Do not repair unrelated TimerMgr docs under this target assignment.

## Changed Files In This Report Pass

- Created: `tools/leaser/Agents/Agent-B011/research/00041F-VectorGrowLayer-source-quality.md`

Callback changed by-* files:

- `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md`
- `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md`
- `by-file/VectorHelpers.md`
- `by-file/NewHumanImageLib.md`
- `by-class/NewHumanImageLib.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`

Callback deliberately did not edit generated files, coverage reports, validator/tool state, IDA databases, supervisor ledgers, executed archives, or lock files. Generated C++ and generated reports were refreshed only by validator commands.

## Implementation Tracking Checklist

Report-only status:

- [x] Read B-agent workflow and Agent-B011 goal.
- [x] Confirm MCP availability and capture current IDB/server state.
- [x] Recheck target function and caller evidence with schema-current MCP calls.
- [x] Check current target/support docs and executed reports.
- [x] Produce Agent-B011 research report.

Callback implementation status:

- [x] Updated target metadata to `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000LR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LR`, and blank optional position; proof: `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md`, validator `000000002102`.
- [x] Inserted exact formal source-disposition marker and no standalone helper body; proof: source target lines `10-14`, UID-only validator `000000002111`, generated `NewHumanImageLib.cpp` lines `849-854`.
- [x] Preserved MCP facts: exact `0x19e`/`414` size, no function at `0x004e523e`, successor `sub_4E5240`, caller sites `0x004dffb2` and `0x004e1171`, vector receiver/caller setup, `0x20`/`32` byte `NewHumanLayerEntry` row behavior, allocation/relocation/free behavior, rejected owner/body alternatives, score rationale, and TimerMgr UID-collision exclusion.
- [x] Preserved source behavior as `m_layerEntries.push_back(layer)` in constructor and UID00041A; proof: target, `LoadLayerTable`, file/class/cluster support docs, and generated lines `46` and `271`.
- [x] Refreshed `by-memory/0x004e1040-0x004e11af.NewHumanImageLibLoadLayerTable.md` support only; proof: validator `000000002112`; formal C++ unchanged.
- [x] Refreshed `by-file/VectorHelpers.md` fallback note only; proof: validator `000000002113`; direct owner remains rejected.
- [x] Refreshed `by-file/NewHumanImageLib.md`, `by-class/NewHumanImageLib.md`, and `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`; proof: validators `000000002140`, `000000002141`, and `000000002142`.
- [x] Left constructor page unchanged as already present; proof: it already records constructor callsite `0x004dffb2`, UID00041A callsite context, and `m_layerEntries.push_back(layer)`.
- [x] Excluded layout/resource page edits with reason: existing row/table evidence was sufficient and accepted callback did not require those pages.
- [x] Used and released/cleared leases as far as possible. Target/early support leases were released successfully; final shared-doc lease batch succeeded, but the 5-minute B011 leases expired during the validator batch and B008 acquired the same shared docs at `2026-06-30T07:35:48Z`, so B011 unlease rejected as `Lease owned by B008`. Current lease report therefore shows no active B011 leases.
- [x] Ran all scoped validators listed above and checked generated freshness. Unrelated validator warnings: VectorHelpers existing `missing_ref_uid` rows for `0003TP`, `0003SR`, `0003SC`; local-cluster existing `missing_ref_uid 0003UD`.
- [ ] Supervisor-only executed-report lifecycle remains pending. The supervisor should run `execute_report` only after verifying this callback; B011 did not mark implementation complete or move the report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00041F-VectorGrowLayer-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/00041F-VectorGrowLayer-source-quality.md","timestamp":"2026-06-30T03:40:40","uid":"00041F"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00041F-VectorGrowLayer-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00041F-VectorGrowLayer-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00041F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
