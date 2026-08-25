** TARGET-REPORT-UID:0002ND **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002ND ErrorHierarchyVtableData Empty-Emitter Source-Quality Research

## Finalized Report / Current Recommendation

- Target UID/path: [UID:0002ND] `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`
- Assignment id: `B012-report-0002ND-ErrorHierarchyVtableData-empty-emitter-source-quality-20260628`
- Current state: `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, blank formal `RECONSTRUCTION_CPP CODE`; generated `auto-generated/NexusTK/util/Error.cpp` still emits UID0002ND as an `Empty Emitter Marker`.
- Current recommendation: keep owner/emitter/reconstructable routing through [UID:0000J5][Error](../../../../../by-file/Error.md), do not split the range, do not emit raw vtable/RTTI dwords, and repair the empty-emitter state with a formal covered-by/no-raw-vtable marker in UID0002ND's multiline `RECONSTRUCTION_CPP CODE` block.
- Recommended metadata: raise UID0002ND to `COMPLETION:89`, `CONFIDENCE:92`; keep `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, and blank `EMITTER_POSITION_OPTIONAL`.
- Exact marker content to insert after supervisor validation:

```cpp
// Emitted source for this Error hierarchy RTTI/vtable run is covered by the Error.cpp class declarations and virtual method implementations tracked through [UID:0000J5][Error](by-file/Error.md) and [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md); this data page emits no raw vtable or RTTI dwords.
```

- Final disposition: source-declared/generated-binary compiler data with an intentional source-route marker, not a standalone raw-data source item.
- Confidence: high for the marker/no-raw-dword disposition; below final audit because original `Error.h` declaration spelling, the hierarchy-wide `+0x0c` virtual declaration, and three raw constructor-shaped starts remain unresolved outside this data page.

## Supporting Research

## Target

- Target UID: `0002ND`
- Target path: `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` lists UID0002ND at `87/91`, combined `89.0`, reconstructable `true`, direct reports `0`.
- Current supervisor classification: empty-emitter source-quality research for a high-empty [UID:0000J5] `Error.md` generated file.
- Current generated symptom: `auto-generated/NexusTK/util/Error.cpp`, validator command id `000000000074`, refreshed `2026-06-28T22:28:52-04:00`, lists `// UID:0002ND | by-memory\0x00619340-0x00619448.ErrorHierarchyVtableData.md | Completion:87 | Confidence:91 | Empty Emitter Marker`.

## Current Target State

- Existing metadata: `87/91`, owner/emitter [UID:0000J5], reconstructable true, blank C++.
- Existing owner/emitter/reconstructable state: current route is valid. [UID:0000J5] is the source-file route for `NexusTK/util/Error.cpp`; [UID:0001XI] is the supporting vtable-family page; [UID:00013X] is the executable wrapper aggregate.
- Existing C++/emitter state: blank formal block. The page body already says raw vtable bytes are compiler output, but the blank block leaves generated output looking like an accidental empty emitter.
- Existing open questions/blockers:
  - Whether the page should emit a formal marker, remain blank with prose-only no-code proof, split into class-local vtable children, route through class/type pages differently, or downgrade metadata.
  - Whether the `0x00619340` RTTI/COL prelude dwords and each class vtable base still match the documented sequence.
  - Whether constructor/destructor/message/name slot evidence still supports Error.cpp class declarations rather than raw table source.
  - Whether unresolved `+0x0c` virtual spelling and raw constructor-shaped starts block a target-level marker.
- Related target/support docs checked: target UID0002ND, [UID:0000J5] `by-file/Error.md`, [UID:0001XI] `by-type/by-vtable/ErrorHierarchyVtables.md`, [UID:0001UE] `by-type/by-struct/ErrorObjectLayouts.md`, parent [UID:000258] `by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md`, related class pages for `Error`, `Win32Error`, `DIError`, `DDError`, `DSError`, `ErrorMessage`, `FileError`, `WSAError`, `InternetError`, `InternetConnectionError`, `MyError`, and `PasswordError`, generated `Error.cpp`, generated research tracker, generated memory coverage, proposed source tree, and executed B reports used as leads.

## Executive Recommendation

Keep UID0002ND as one exact Error hierarchy vtable-data page. It covers eleven adjacent MSVC RTTI/COL-plus-five-slot table records, each `0x18` / 24 bytes (Verified with `int_convert.py`), for total range size `0x108` / 264 bytes (Verified with `int_convert.py`). The half-open range starts at the base `Error` complete-object-locator pointer at `0x00619340` and ends before the UTF-16 `Win32Error` literal bytes at `0x00619448`.

The correct emitted-source representation is not raw table data and not a handwritten `static void *` array. The correct source shape is class declarations plus virtual method/destructor declarations in the Error hierarchy. Because the target is reconstructable and has a valid emitter route, the blank block should be replaced by the formal marker above. This preserves the source route in generated `Error.cpp` while making clear that the compiler should regenerate the RTTI/vtable storage.

No split is recommended. Per-class vtable child pages would be smaller compiler-output pages with the same no-raw-dword policy and would not improve source correctness. The target is a coherent family-level support item under `util/Error.cpp`, and the class pages already carry class-local anchors for their constructor/destructor/method relationships.

## Supervisor Active Recheck

- Current user/supervisor instruction: report-only research for UID0002ND; do not edit target/support by-* docs until supervisor validation and implementation callback.
- Split repair required before final report: no. The current `0x00619340-0x00619448` range is exact, contiguous, and stops at a verified string boundary. No mixed Event/ExceptionHandler bytes are inside this target.
- Source-bearing child status: exact executable method children and class pages carry their own source-readiness state. This data page should become marker-covered, not a container with `[[CHILDREN]]`.

## Inference Research Guidance Check

The recommendation follows the project inference ladder:

- Direct IDA facts: current MCP `server_health`, `get_bytes`, `get_int`, `entity_query`, `xrefs_to`, `find_bytes`, `lookup_funcs`, and `decompile` prove the range bytes, RTTI pointer targets, vtable labels, constructor-store routes, slot-function inventory, and successor string boundary.
- Documentation evidence: current target/support docs already identify this as source-declared/generated-binary vtable data owned by [UID:0000J5]. Existing docs were treated as leads and rechecked where they affect marker/source disposition.
- Inference: final source should express class declarations and virtual methods, not raw vtable dwords. That inference is strong because the range is MSVC RTTI/vtable storage with constructor/destructor vtable stores and no evidence of product-authored table declarations.
- Wave2/Wave3: generated `Error.cpp` was used only as the current empty-emitter symptom and not as authority. No stale Wave2/Wave3 facts drive the recommendation.

## Heuristic / Inference Reanalysis And Validation

### Empty-emitter disposition

The target is reconstructable, owner-routed, and generated into `NexusTK/util/Error.cpp`, but its C++ block is empty. A prose-only no-code statement is not enough for this queue item because validator-generated output still records `Empty Emitter Marker`. The implementation-ready disposition is a formal marker comment, not raw data C++ and not blank output.

Rejected alternatives:

- Raw vtable dword C++: rejected. It would expose compiler-generated RTTI/vtable bytes as product source.
- Blank formal C++ with only body prose: rejected for this empty-emitter target because generated output remains ambiguous.
- Clearing `EMITTER_UIDS`: rejected because the Error.cpp route is correct and useful.
- `RECONSTRUCTABLE:FALSE`: rejected because the rebuilt source must recreate the hierarchy declarations and virtual layout even though the exact `.rdata` bytes are compiler output.
- `[[CHILDREN]]`: rejected because this is an exact data item, not a parent source container.

### RTTI/COL prelude dwords

Current MCP `get_int` confirms `0x00619340 -> 0x00646bbc`, and `entity_query names 0x00646b80-0x00646ed0` names that target as `??_R4Error@@6B@`. The following table-prelude dwords point to the expected MSVC RTTI/COL records: `Win32Error` `0x00646bd0`, `DIError` `0x00646c20`, `DDError` `0x00646c70`, `DSError` `0x00646cc0`, `ErrorMessage` `0x00646d10`, `FileError` `0x00646d60`, `WSAError` `0x00646db0`, `InternetError` `0x00646e00`, `InternetConnectionError` `0x00646e50`, and `MyError` `0x00646ea0`.

Current MCP `xrefs_to 0x00619340` reports zero xrefs, and `find_bytes "40 93 61 00"` finds zero matches. That negative evidence is normal for the base `Error` COL-pointer cell and does not argue for source-authored raw data.

### Vtable bases and constructor stores

Current MCP `entity_query names 0x00619330-0x00619460` names vtable bases from `??_7Error@@6B@` at `0x00619344` through `??_7MyError@@6B@` at `0x00619434`. Current `xrefs_to` and little-endian pointer searches confirm constructor/destructor store routes:

| Vtable base | Class | Current refs/search matches |
| --- | --- | --- |
| `0x00619344` | `Error` | Ten stores/restores at `0x004a6400`, `0x004a6470`, `0x004a6874`, `0x004a6890`, `0x004a68a6`, `0x004a68e6`, `0x004a6926`, `0x004a6976`, `0x004a69d0`, `0x004a6a27`; `find_bytes "44 93 61 00"` finds the same ten immediate sites. |
| `0x0061935c` | `Win32Error` | Constructor store at `0x004a60df`; byte match at `0x004a60e1`. |
| `0x00619374` | `DIError` | Raw constructor-shaped store at `0x004a61c7`; byte match at `0x004a61c9`; no IDA function object at `0x004a61b0`. |
| `0x0061938c` | `DDError` | Constructor store at `0x004a6277`; byte match at `0x004a6279`. |
| `0x006193a4` | `DSError` | Raw constructor-shaped store at `0x004a6347`; byte match at `0x004a6349`; no IDA function object at `0x004a6330`. |
| `0x006193bc` | `ErrorMessage` | Raw constructor-shaped store at `0x004a63ef`; byte match at `0x004a63f1`; no IDA function object at `0x004a63e0`. |
| `0x006193d4` | `FileError` | Constructor store at `0x004a6445`; byte match at `0x004a6447`. |
| `0x006193ec` | `WSAError` | Constructor store at `0x004a64af`; byte match at `0x004a64b1`. |
| `0x00619404` | `InternetError` | Constructor store at `0x004a65a2`; byte match at `0x004a65a4`. |
| `0x0061941c` | `InternetConnectionError` | Constructor store at `0x004a66da`; byte match at `0x004a66dc`. |
| `0x00619434` | `MyError` | Constructor/restores at `0x004a67da`, `0x004a6866`, and `0x004a6a19`; byte matches at `0x004a67dc`, `0x004a6868`, `0x004a6a1b`. |

This evidence supports the class declaration/source route and rejects raw table C++.

### Destructor, message, and name slots

Current MCP `lookup_funcs` confirms every non-RTTI slot target is a function or runtime/import target. Current `xrefs_to` confirms the table slot routes:

- Destructor slots: base `0x004a68e0` has one data xref from `0x00619344`; status-code destructor `0x004a68a0` has five xrefs from `0x0061935c`, `0x00619374`, `0x0061938c`, `0x006193a4`, `0x006193ec`; `ErrorMessage` destructor `0x004a6920` has one xref from `0x006193bc`; `FileError` destructor `0x004a6970` has one xref from `0x006193d4`; WinINet destructor `0x004a69c0` has xrefs from `0x00619404` and `0x0061941c`; `MyError` destructor wrapper `0x004a6a10` has one xref from `0x00619434`.
- Message slots: `0x004a6100`, `0x004a61e0`, `0x004a6290`, `0x004a6360`, `0x004a6410`, `0x004a6480`, `0x004a64d0`, `0x004a6670`, and `0x004a6780` each have one current data xref from their documented vtable slot. `0x004a6840` has two data xrefs, from PasswordError's separate vtable at `0x006125b4` and this target's MyError slot at `0x00619440`.
- Name slot: `0x004a6a70` has eleven data xrefs, exactly this target's `+0x10` slot across all eleven main-run tables. Current decompile returns `L"Error"`, matching the existing `Error::GetErrorName` source-facing interpretation.
- Shared inherited/runtime slots `0x004f4b10`, `0x0041b6c0`, and `__purecall` have many data xrefs across the binary; they are shared runtime/abstract-slot evidence and not declaration ownership for this page.

The pending source-quality work for some individual formatter/message functions does not require raw vtable emission from UID0002ND. It is a class/method declaration issue, not a vtable-data-page code issue.

### Boundary and split analysis

Current bytes at `0x00619430` show the final `MyError` RTTI/COL cell, five slots through `0x00619444 -> 0x004a6a70`, then UTF-16 `W i n 3 2 E r r...` at `0x00619448`. Current `get_int 0x00619448` returns decimal `6881367`, which is `0x00690057` in little-endian UTF-16 bytes (`W`, `i`). Current `get_bytes 0x00619448 size 32` decodes the start of `Win32Error`. Current `xrefs_to 0x00619448` reports two references from `sub_4A6100` at `0x004a6152` and `0x004a617b`. `entity_query strings 0x00619330-0x00619460` returns zero strings, so byte decoding remains the authoritative string-boundary evidence.

Current `xrefs_to 0x00619628` remains empty and `xrefs_to 0x0061962c` reports Event/handler-tree vtable users, which is consistent with the parent [UID:000258] split and not a reason to expand UID0002ND.

### Source placement

[UID:0000J5] `Error.md` and `by-project-structure/proposed-source-tree.md` both place the hierarchy in `NexusTK/util/Error.cpp`. Current MCP evidence agrees: every table in UID0002ND is part of the compact Error wrapper/class hierarchy, and constructor/store refs sit in the `0x004a60d0-0x004a6a76` Error wrapper/destructor cluster or the known raw constructor-shaped gaps inside that cluster. Feature modules are consumers of the wrapper classes, not owners of this table data.

## Evidence Standards Used

- IDA MCP was used for the active evidence pass. Current session/database: `agent_b009_0002my_20260628`.
- `server_health` returned `status:"ok"`, module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- Direct facts were separated from inferred source shape. Current binary facts prove the storage and references; source-level marker policy is an inference from C++ ABI/source-shape rules and project precedent.
- IDA limitations: MCP cannot prove original source filenames, original member names, or exact `Error.h` declaration spelling. That limits final-audit scoring but does not block a marker that avoids fabricating raw source.

## Evidence Checked

IDA MCP/manual checks performed:

- JSON-RPC `initialize`, `tools/list`, `idb_list`, and `server_health`.
- `get_bytes` at `0x00619340`, `0x00619430`, and `0x00619448`.
- `get_int u32le` for key RTTI/vtable/slot/boundary dwords from `0x00619340` through `0x00619448`.
- `entity_query names` for `0x00619330-0x00619460` and RTTI/COL target range `0x00646b80-0x00646ed0`.
- `entity_query strings 0x00619330-0x00619460` as negative string-cache evidence.
- `xrefs_to` for RTTI/COL cells, vtable bases, slot targets, `0x00619448`, `0x00619628`, and `0x0061962c`.
- `find_bytes` for all main-run vtable-base VA dwords plus `0x00619340` and `0x00619448`.
- `lookup_funcs` for constructor/message/destructor/name/helper targets and raw constructor-shaped starts.
- `decompile 0x004a6a70` and `decompile 0x004a6840`.
- `tools/int_convert.py` successful checks for `0x108 -> 264`, `0x18 -> 24`, `0x14 -> 20`, and `0x4 -> 4`. The first attempted combined invocation was invalid because the tool expects one number per invocation; the successful single-value invocations are the evidence used.

Documentation/generated evidence checked:

- Target UID0002ND, [UID:0000J5] `Error`, [UID:0001XI] `ErrorHierarchyVtables`, [UID:0001UE] `ErrorObjectLayouts`, [UID:000258] parent read-only-data container, related class pages, `by-project-structure/proposed-source-tree.md`, generated `Error.cpp`, generated research tracker, generated memory coverage, and executed reports for related empty-emitter/Error hierarchy work.

Negative checks:

- No xrefs to the base RTTI/COL cell `0x00619340`.
- No byte-pattern matches for VA `0x00619340`.
- `entity_query strings` does not classify the target/boundary as strings.
- No xrefs to `0x00619444` slot cell itself, while the dword value points to `0x004a6a70`.
- Per-class split found no source correctness gain; each subtable is compiler output covered by the same hierarchy declaration route.

Failed/unavailable checks:

- No MCP outage. MCP was available and responsive; no fallback-only evidence was used.
- The expected quality baseline path named in the workflow under `Agent-B001/research/executed` had moved; current copy found at `executed-b-agent-research/B001/0002CF-g_movementSubstepScale.md`.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| UID0002ND's range is exact `0x00619340-0x00619448`. | Confirmed | Current bytes/dwords, named vtable bases, `0x00619448` UTF-16 boundary, `xrefs_to 0x00619448`, parent [UID:000258]. | Checked `0x00619444`, `0x00619448`, `0x00619628`, `0x0061962c`; no evidence for extending or shrinking. | None for this target boundary. |
| The table run is source-declared/generated-binary vtable/RTTI data. | Confirmed as binary data, strongly inferred as source-generated | MSVC `??_7...` vtable names, `??_R4...` COL names, constructor/destructor vtable stores, slot-function xrefs. | Raw table source, standalone static array, and split-per-class raw emission rejected. | Original source declarations may refine class/method names, but not raw table policy. |
| Owner/emitter [UID:0000J5] should remain. | Strong | Error.cpp source-tree placement, Error file support docs, constructor/store cluster in Error wrapper range, valid generated route. | Type page, class pages, feature caller modules, and no-owner/non-emitting alternatives considered and rejected. | None required for marker. |
| Formal C++ should be a covered-by/no-raw-vtable marker. | Strong | Target is reconstructable and routed, generated output shows Empty Emitter Marker, raw dwords are compiler output, accepted empty-emitter precedents use markers for compiler/data route. | Blank block, clearing emitters, `FALSE`, raw dword source, and `[[CHILDREN]]` rejected. | Supervisor should approve exact marker text before implementation. |
| Score should rise to `89/92`, not final audit. | Strong | Current MCP pass adds active evidence, marker/no-code proof, rejected alternatives, and implementation-ready checklist. | `95+` rejected because original declarations/names and raw constructor-shaped starts remain unresolved. | Future broad Error.h/class declaration pass can raise class/type pages separately. |

## Positive Evidence Summary

- Direct binary facts support the current table sequence and boundary.
- Constructor/destructor xrefs and pointer searches support class declaration regeneration rather than product-authored raw table data.
- Generated/source-tree evidence supports `NexusTK/util/Error.cpp` as the route.
- Existing support docs already carry the Error hierarchy storage and slot context; this report adds the current marker/no-empty-emitter disposition for UID0002ND.

## IDA MCP Facts

- Session/database: `agent_b009_0002my_20260628`.
- Health: `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Names in target range: `??_7Error@@6B@` at `0x619344`, `??_7Win32Error@@6B@` at `0x61935c`, `??_7DIError@@6B@` at `0x619374`, `??_7DDError@@6B@` at `0x61938c`, `??_7DSError@@6B@` at `0x6193a4`, `??_7ErrorMessage@@6B@` at `0x6193bc`, `??_7FileError@@6B@` at `0x6193d4`, `??_7WSAError@@6B@` at `0x6193ec`, `??_7InternetError@@6B@` at `0x619404`, `??_7InternetConnectionError@@6B@` at `0x61941c`, and `??_7MyError@@6B@` at `0x619434`.
- Successor names: `aN32error` at `0x61944c` and `aSDS` at `0x619460`; these are string/interior labels after the UID0002ND range.
- Slot helper function inventory: `sub_4A6100` size `0xa3`, `sub_4A61E0` size `0x7b`, `sub_4A6260` size `0x24`, `sub_4A6290` size `0xa0`, `sub_4A6360` size `0x7b`, `sub_4A6410` size `0x19`, `sub_4A6430` size `0x3f`, `sub_4A6480` size `0x19`, `sub_4A64A0` size `0x25`, `sub_4A64D0` size `0x79`, `sub_4A6550` size `0x11a`, `sub_4A6670` size `0x1e`, `sub_4A6690` size `0xe2`, `sub_4A6780` size `0x1e`, `sub_4A67A0` size `0x9d`, `sub_4A6840` size `0x18`, `sub_4A68A0` size `0x3e`, `sub_4A68E0` size `0x3e`, `sub_4A6920` size `0x41`, `sub_4A6970` size `0x41`, `sub_4A69C0` size `0x48`, `sub_4A6A10` size `0x51`, `sub_4A6A70` size `0x6`, `sub_4F4B10` size `0x6`, `nullsub_18` size `0x3`, and `__purecall` size `0x1b`.
- Raw constructor-shaped starts still not IDA functions: `0x004a61b0`, `0x004a6330`, and `0x004a63e0` return `Not a function`.
- `decompile 0x004a6a70`: returns `L"Error"`.
- `decompile 0x004a6840`: returns `wcscpy_s(Destination, SizeInWords, this[1])`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00619340-0x00619448` | UID0002ND target | Main Error hierarchy RTTI/vtable run | TRUE | [UID:0000J5] | current `87/91`, recommend `89/92` | Needs formal marker |
| `0x00619448-0x00619628` | [UID:0003I4] `ErrorHierarchyMessageStrings` | Successor Error literal run | TRUE | [UID:0000J5] | `88/92` | Already marker-covered |
| `0x00619340-0x006196bc` | [UID:000258] parent | Mixed Error/Event read-only-data container | FALSE | NONE | `89/92` | No target edit required |
| `0x004a60d0-0x004a6a76` | [UID:00013X] `ErrorWrappers` | Executable Error wrapper aggregate | TRUE | [UID:0000J5] | `87/89` | Support context only |
| `ErrorHierarchyVtables` | [UID:0001XI] | Vtable-family support page | TRUE | [UID:0000J5] | `86/90` | Support sync recommended |
| `ErrorObjectLayouts` | [UID:0001UE] | Layout-family support page | TRUE | [UID:0000J5] | `86/88` | Check-only; no required marker edit |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00619344` | Ten data xrefs from cleanup/destructor family | Base `Error` vtable is restored in teardown/unwind, not raw source table code. |
| `0x0061935c` | `0x004a60df` | `Win32Error` constructor store. |
| `0x00619374` | `0x004a61c7`, no IDA function object | `DIError` raw constructor-shaped store. |
| `0x0061938c` | `0x004a6277` | `DDError` constructor store. |
| `0x006193a4` | `0x004a6347`, no IDA function object | `DSError` raw constructor-shaped store. |
| `0x006193bc` | `0x004a63ef`, no IDA function object | `ErrorMessage` raw constructor-shaped store. |
| `0x006193d4` | `0x004a6445` | `FileError` constructor store. |
| `0x006193ec` | `0x004a64af` | `WSAError` constructor store. |
| `0x00619404` | `0x004a65a2` | `InternetError` constructor store. |
| `0x0061941c` | `0x004a66da` | `InternetConnectionError` constructor store. |
| `0x00619434` | `0x004a67da`, `0x004a6866`, `0x004a6a19` | `MyError` constructor and cleanup/destructor restores. |
| `0x00619448` | `0x004a6152`, `0x004a617b` | Successor `Win32Error` UTF-16 literal run, not another vtable slot. |

## Documentation Evidence And IDA Status

- [UID:0002ND] already documents the correct range and table sequence; it lacks the formal marker and current evidence/rejected-alternative section needed to resolve the empty-emitter queue.
- [UID:0000J5] already identifies `Error.cpp` as the source module and lists UID0002ND as a main address doc; it should receive a short B012 marker-disposition sync after target update.
- [UID:0001XI] already records the five-slot table map; it should receive a short sync that UID0002ND is marker-covered/no raw dwords once implemented.
- [UID:0001UE] already records layout families and current unresolved declaration issues. It does not need target-specific marker text unless supervisor wants an extra support echo.
- [UID:000258] already treats this as an exact child and remains a non-emitting mixed container; no edit required.
- Related class pages already record class-level blank C++ blockers and exact source-ready children. This report should not force class-level C++ for them.

## Ranked Ownership Analysis

### 1. [UID:0000J5] Error / `NexusTK/util/Error.cpp`

- Evidence for: proposed source tree and [UID:0000J5] group all main Error hierarchy classes in `Error.cpp`; current MCP vtable stores and slot functions sit in the Error wrapper/destructor cluster; generated output routes UID0002ND through `Error.cpp`; direct parent clears the 85/85 gate.
- Evidence against: class declarations and exact original header names are not fully recovered; several class pages are still empty emitters.
- Decision: keep as canonical owner/emitter route for this family-level data page.

### 2. [UID:0001XI] ErrorHierarchyVtables as direct owner

- Evidence for: strongest support doc for the slot map.
- Evidence against: it is a by-type support/layout page, not the final source file or direct semantic owner for emitted C++. Assigning UID0002ND to the type page would not improve generated source placement.
- Decision: use as support documentation in marker text; do not make it the canonical owner.

### 3. Per-class owners or split children

- Evidence for: each `0x18` table belongs to a concrete class's vtable.
- Evidence against: the current page is an exact contiguous family run; splitting would create eleven tiny compiler-output pages with the same marker/no-raw-dword policy. Class pages already record their anchors and source blockers.
- Decision: reject split for this pass.

### 4. No-owner/non-emitting or `RECONSTRUCTABLE:FALSE`

- Evidence for: raw table bytes should not be handwritten.
- Evidence against: the source declarations must still be rebuilt and the current `Error.cpp` route is known. Clearing emission would discard useful source-route evidence and leave no generated trace for an intentional no-raw-data decision.
- Decision: reject. Keep reconstructable/routed and insert the marker.

### 5. Feature module consumers

- Evidence for: DirectInput, DirectDraw, DirectSound, Winsock, WinINet, and application startup code construct or consume wrapper classes.
- Evidence against: those are construction/use contexts, not declaration owners for the shared Error class hierarchy.
- Decision: reject as owners.

## Source Placement

Recommended placement remains `NexusTK/util/Error.cpp` with declarations in the corresponding `Error.h`/class declarations when that source surface is reconstructed. UID0002ND should not emit actual declarations itself because the page covers the compiled RTTI/vtable storage, not a source declaration range. The formal marker should point at [UID:0000J5] and [UID:0001XI] so generated output shows the intentional coverage route without inventing raw source.

## Range / Split / Padding / Reclassification Analysis

- Exact range: `0x00619340-0x00619448`.
- Unit size: eleven `0x18` / 24-byte table records, total `0x108` / 264 bytes (Verified with `int_convert.py`).
- Start boundary: `0x00619340` is the `Error` RTTI/COL pointer to `??_R4Error@@6B@`; preceding BinaryCodec/DAT data ends at this boundary.
- End boundary: `0x00619444` is the final `MyError` `+0x10` name slot pointing to `0x004a6a70`; `0x00619448` begins UTF-16 `Win32Error`.
- Split: rejected. No mixed owner exists inside the target; source ownership is shared Error hierarchy class declaration generation.
- Reclassification: reject `FALSE` and reject non-emitting. It remains `TRUE` because source declarations must regenerate the table.
- Padding: none inside target; successor bytes are string data.

## Negative Evidence Summary

- No direct original source metadata or PDB evidence proves exact original declaration spelling.
- No source-authored table declaration, standalone global, or pointer-array route is visible.
- No evidence supports treating vtable dwords as final C++.
- No evidence supports clearing emitter route; current generated route is valid.
- No evidence supports per-class split as a source-quality improvement.
- Raw constructor-shaped starts at `0x004a61b0`, `0x004a6330`, and `0x004a63e0` remain unresolved as IDA function objects, but they do not contradict this table's marker disposition.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested. The report only recommends source-facing documentation text and a formal marker.

Source-facing names:

- Keep `Error::GetErrorName` as the best current descriptive name for shared slot `0x004a6a70`, with `GetErrorDescriptor` only as a project-wide alternative if standardized consistently.
- Keep `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` as the current broad `+0x0c` virtual spelling candidate where exact method pages support it. Do not force that name into unresolved sibling exact pages through this data-page report.
- Do not expose IDA names such as `??_7...`, `sub_4A...`, or raw `off_` labels as final source declarations except as evidence/search aliases.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, in the limited form of a formal covered-by/no-raw-data marker. The target is `RECONSTRUCTABLE:TRUE`, has a valid `EMITTER_UIDS:0000J5` route, and has average score above the current code-entry gate. It is not eligible for handwritten raw table C++.
- Recommended formal `RECONSTRUCTION_CPP CODE` content:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted source for this Error hierarchy RTTI/vtable run is covered by the Error.cpp class declarations and virtual method implementations tracked through [UID:0000J5][Error](by-file/Error.md) and [UID:0001XI][ErrorHierarchyVtables](by-type/by-vtable/ErrorHierarchyVtables.md); this data page emits no raw vtable or RTTI dwords.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: the compiler/linker should regenerate RTTI/vtable bytes from class declarations and virtual methods. Hand-coding dwords would be less source-realistic and more fragile.
- Reason it matches plausible mid-2000s source shape: original developers would write class declarations/destructors/virtual methods, not explicit MSVC `??_7...` vtable arrays.
- Inferred source-facing names/types used: marker references `Error.cpp` and `ErrorHierarchyVtables`; it does not introduce new class/member/function names.
- Naming/coding style convention used: single C++ comment marker matching existing project marker style for covered compiler/data ranges.
- Exact no-code proof: current MCP proves the page is RTTI/vtable storage with constructor/destructor stores and vtable-only slot routes; raw table dwords are compiler output; the source declarations/method bodies belong to class/exact method pages.

## Final Recommendation

- Target UID0002ND: update target page with current MCP evidence, marker/no-raw-vtable no-code proof, rejected alternatives, and score rationale; insert formal marker; raise to `89/92`; keep owner/emitter/reconstructable unchanged.
- Support [UID:0000J5] `by-file/Error.md`: add a short synchronization note that UID0002ND now resolves its empty-emitter state with the formal marker while preserving Error.cpp source ownership and no raw vtable dword emission.
- Support [UID:0001XI] `by-type/by-vtable/ErrorHierarchyVtables.md`: add a short synchronization note in the main vtable/data caveat/change area that UID0002ND's exact table run is marker-covered by Error class declarations and emits no raw vtable dwords.
- Check-only support: [UID:0001UE], [UID:000258], and class pages already contain same-or-greater context for layout/source blockers; no required edit unless supervisor wants broader support echo.

## Recommended Target Doc Changes

Target path: `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`

Exact report facts to incorporate:

- Current MCP session/database `agent_b009_0002my_20260628`, server health, active IDB/module/imagebase readiness.
- Current bytes/dwords for start/end boundary.
- RTTI/COL names from `0x00646bbc` through `0x00646ea0`.
- Current vtable-base names from `0x00619344` through `0x00619434`.
- Constructor/store xref and `find_bytes` matrix.
- Slot target xref summary for destructors, message slots, `0x004a6840`, and `0x004a6a70`.
- Boundary proof at `0x00619448` and negative string-cache classification.
- Empty-emitter disposition: formal covered-by marker, no raw vtable/RTTI dwords.
- Rejected alternatives: raw dword source, blank/prose-only, clearing emitter, `FALSE`, `[[CHILDREN]]`, split per class, class/type owner changes.

Metadata/score/owner/emitter/reconstructable/C++ changes:

- `COMPLETION:87 -> 89`
- `CONFIDENCE:91 -> 92`
- Keep `CANONICAL_OWNER:0000J5`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000J5`
- Keep `EMITTER_POSITION_OPTIONAL:` blank
- Insert formal marker in multiline `RECONSTRUCTION_CPP CODE`; keep inline value blank.

Historical/stale assumptions to preserve:

- Raw vtable bytes remain compiler output.
- The broader hierarchy-wide `+0x0c` virtual declaration and raw constructor-shaped starts remain outside this page's marker decision.
- Do not convert IDA `??_7...`/`sub_...` names into final source API names.

## Recommended Support Doc Changes

Support path: `by-file/Error.md`

- Add a current B012 sync note that UID0002ND uses a formal covered-by/no-raw-vtable marker, stays routed through `Error.cpp`, and is source-declared/generated-binary vtable evidence for the class hierarchy rather than standalone table C++.
- Do not otherwise alter the file-level class C++ blockers for unresolved class declarations or other empty emitter rows.

Support path: `by-type/by-vtable/ErrorHierarchyVtables.md`

- Add a short sync note that the exact main vtable run UID0002ND is marker-covered by Error class declarations/virtual method implementations, with no raw vtable or RTTI dword emission.
- Preserve the current five-slot table map, `GetErrorName` caveat, raw constructor-shaped start caveats, and pending `+0x0c` declaration blockers.

Check-only support:

- `by-type/by-struct/ErrorObjectLayouts.md`: already records layout families and unresolved declaration/name issues; no target-specific marker edit required.
- `by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md`: already lists UID0002ND as exact child and parent remains non-emitting mixed container; no edit required.
- Related class pages: leave class-level C++ blank until separate class/empty-emitter passes approve declarations or markers.

## Score And Metadata Recommendation

- Current score/metadata: `87/91`, owner/emitter [UID:0000J5], reconstructable true, blank C++.
- Recommended score/metadata: `89/92`, owner/emitter unchanged, reconstructable true, formal marker.
- Score rationale:
  - Completion rises because the target gains current MCP-backed evidence, exact empty-emitter disposition, formal marker, rejected alternatives, and implementation-ready checklist.
  - Confidence rises because current MCP confirms bytes/dwords/xrefs/function inventory and generated route, and because the marker avoids unsupported raw-source claims.
  - Reason not higher: exact original `Error.h` declaration spelling is not recovered, class pages remain under separate class-level C++ blockers, `+0x0c` virtual naming/return type is not hierarchy-final, and raw constructor-shaped starts at `0x004a61b0`, `0x004a6330`, and `0x004a63e0` still lack IDA function objects.
- Score-improvement attempt:
  - Empty marker blocker: resolved with formal marker recommendation.
  - RTTI/COL prelude: current MCP names/dwords checked and resolved.
  - Constructor stores: current xrefs and pointer matches checked and resolved for this page.
  - Destructor/name/message slots: current function inventory/xrefs checked and resolved for data-page policy.
  - Source placement: Error.cpp route rechecked against docs/source tree/MCP and kept.
  - Split/class owner possibility: researched and rejected as no source-quality improvement.

## Open Questions With Attempted Resolution

- Original source spelling of the class declarations and virtual method names: unresolved, because MCP/IDA have no original source metadata. This blocks final-audit class/header C++ but not the data-page marker.
- `+0x0c` virtual common name/return type: partly resolved as `FormatErrorMessage(...)` candidate with target-specific accepted children, but not hierarchy-final. This does not require UID0002ND to stay empty.
- Raw constructor-shaped starts for `DIError`, `DSError`, and `ErrorMessage`: current `lookup_funcs` still says `Not a function`; the vtable-store bytes and xrefs are documented, but exact constructor source pages need separate work before final constructor C++. This limits score but does not contradict marker output.
- Class-level empty emitters in generated `Error.cpp`: related but outside this UID0002ND report. Do not use this report to bulk-fill class pages.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or validator-owned generated tracker text should be edited by B012. Generated research tracker/memory coverage/Error.cpp should refresh through scoped validators after implementation and later supervisor `execute_report`.

## Follow-Up Actions

- Supervisor: validate or reject this report and exact marker text.
- B012 implementation callback, if accepted: edit only the target plus accepted support docs under leases, insert marker, update checklist with proof, and run scoped validators.
- Supervisor after implementation verification: execute this report with `python .\tools\validator.py execute_report B012 0002ND-ErrorHierarchyVtableData-empty-emitter-source-quality.md 0002ND --apply`.
- Future separate work: class-level Error hierarchy declaration/source-quality passes for other empty emitter rows such as class pages and [UID:0001XI], if assigned.

## Confidence

- Recommendation confidence: high. Current MCP evidence and project source-shape rules support a marker.
- Score confidence: high for `89/92`; not final-audit.
- Remaining uncertainty: original source declarations and some sibling exact method/constructor source shape remain separate work.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

- `python .\tools\validator.py --mode file --file by-memory\0x00619340-0x00619448.ErrorHierarchyVtableData.md --apply --queue-timeout 240 --wait-generated`
  - Exit code: `0`
  - `command_id: 000000000111`
  - `command_timestamp: 2026-06-28T22:47:14-04:00`
  - `ok: 1`
  - Generated refresh: `completed`, `generated_refresh_command_id: 000000000111`, `generated_refresh_timestamp: 2026-06-28T22:47:14-04:00`
  - Target effects: `completion_update 0002ND ... 89`, `confidence_update 0002ND ... 92`, autogen registry changed UID0002ND from blank to block, generated metadata and memory auto coverage refreshed, research tracker updated.
  - Unresolved diagnostics: pre-existing/stale missing-ref/registry diagnostics remained, including UID000258's old missing path `by-memory/0x00619344-0x006196c0.ErrorEventReadOnlyData.md` and other missing registered files. No validator state was hand-edited.
- `python .\tools\validator.py --mode file --file by-file\Error.md --apply --queue-timeout 240 --wait-generated`
  - Exit code: `0`
  - `command_id: 000000000112`
  - `command_timestamp: 2026-06-28T22:47:35-04:00`
  - `ok: 1`
  - Generated refresh: `completed`, `generated_refresh_command_id: 000000000112`, `generated_refresh_timestamp: 2026-06-28T22:47:35-04:00`
  - Side effects: projected stats updated; broad stale registry/missing-file diagnostics remained unrelated.
- `python .\tools\validator.py --mode file --file by-type\by-vtable\ErrorHierarchyVtables.md --apply --queue-timeout 240`
  - Exit code: `0`
  - `command_id: 000000000113`
  - `command_timestamp: 2026-06-28T22:47:50-04:00`
  - `ok: 1`
  - Generated refresh: initially `deferred`, `generated_refresh_command_id: 000000000113`, `generated_refresh_timestamp: 2026-06-28T22:47:50-04:00`.
- `python .\tools\validator.py --queue-status`
  - Exit code: `0`
  - `command_id: 000000000114`
  - `command_timestamp: 2026-06-28T22:48:06-04:00`
  - Queue status: `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`.
- Final sanity `python .\tools\validator.py --queue-status`
  - Exit code: `0`
  - `command_id: 000000000133`
  - `command_timestamp: 2026-06-28T22:51:05-04:00`
  - Queue status: `worker running: True`, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`.

Generated output check:

- `auto-generated/NexusTK/util/Error.cpp` header now reports `validator-command-id: 000000000132`, `validator-refreshed-at: 2026-06-28T22:50:23-04:00`, and `validator-refresh-source: foreground-generated-refresh`.
- UID0002ND appears at lines 105-106 with `Completion:89 | Confidence:92` followed by the formal no-raw-vtable marker.
- UID0002ND no longer appears as `Empty Emitter Marker`.
- Other Error hierarchy class/type empty-emitter markers remain and are outside this implementation callback.

## Changed Files

- Created: none during implementation callback.
- Modified by B012 implementation:
  - `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`
  - `by-file/Error.md`
  - `by-type/by-vtable/ErrorHierarchyVtables.md`
  - `tools/leaser/Agents/Agent-B012/research/0002ND-ErrorHierarchyVtableData-empty-emitter-source-quality.md`
- Validator-generated side effects observed through normal validator commands only:
  - `auto-generated/NexusTK/util/Error.cpp`
  - `auto-generated/-ag-coverage-report-by-memory.md`
  - `auto-generated/-ag-research-tracker.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
  - `tools/validator_autogen_backup/20260628-224723`
  - `tools/validator_autogen_backup/20260628-224744`
- Renamed: none.
- Report execution: leave blank during B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` after verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: 2026-06-28 callback accepted this report and instructed B012 to implement it.
- [x] Lease only accepted editable by-* files immediately before the implementation edit batch; no leases are needed for report-only research. Proof: `leaser.py B012 lease` succeeded for the three accepted by-* files immediately before editing; post-validator `leaser.py B012 unlease ...` reported no active lease and current lease report shows no B012 entries.
- [x] Target doc to update: `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`. Proof: target metadata, formal marker, B012 evidence, reconstruction notes, and change log were updated.
- [x] Support docs to update if accepted: `by-file/Error.md` and `by-type/by-vtable/ErrorHierarchyVtables.md`; check-only support docs are `by-type/by-struct/ErrorObjectLayouts.md`, `by-memory/0x00619340-0x006196bc.ErrorEventReadOnlyData.md`, and related class pages. Proof: the two accepted support docs were updated; check-only docs were not edited because the accepted report marked them no-required-edit.
- [x] Current target state and actual evidence checked recorded. Proof: target now records current `agent_b009_0002my_20260628` MCP health, bytes, RTTI/COL targets, vtable labels, store/xref matrix, slot refs, boundary proof, generated-route reasoning, and score rationale.
- [x] Metadata/score changes to apply: target `COMPLETION:89`, `CONFIDENCE:92`; keep owner/emitter/reconstructable unchanged. Proof: target header is now `89/92` and preserves `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Score-limiting blockers researched to resolution or evidence-backed no-change rationale. Proof: target B012 section records the formal marker resolution, RTTI/COL evidence, constructor/store evidence, slot evidence, split/owner rejection, and remaining class-declaration/raw-constructor caveats as score caps rather than marker blockers.
- [x] Owner/emitter/reconstructable changes to apply: no changes. Proof: owner/emitter/reconstructable fields were preserved exactly.
- [x] Split/rename/new-child changes to apply: none. Proof: target B012 section explicitly rejects per-class split and range rename; no files were created or renamed.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable. Proof: target/support docs keep `Error.cpp` placement, reject reclassification, and state no IDA DB edits.
- [x] First-draft C++ or no-code proof to apply. Proof: exact formal no-raw-vtable marker inserted in UID0002ND multiline `RECONSTRUCTION_CPP CODE` block; no raw vtable/RTTI dwords emitted.
- [x] Third-party import directive to apply or confirm not applicable. Proof: not applicable; no import directive was added.
- [x] Exact target/support doc facts to incorporate at report-level detail. Proof: target has detailed B012 MCP/session/range/xref/slot/boundary/rejected-alternative evidence; `Error.md` and `ErrorHierarchyVtables.md` have support sync notes preserving route/no-raw-data facts.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve. Proof: target and support docs preserve raw-vtable compiler-output policy, no raw table source, no emitter clearing, no `FALSE`, no `[[CHILDREN]]`, no per-class split, and unresolved declaration caveats.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable. Proof: generated `Error.cpp` is documented only as the current empty-emitter symptom/output check, not as source authority.
- [x] Open questions to close or document as evidence-backed unresolved. Proof: target and support docs keep original `Error.h` spelling, hierarchy-wide `+0x0c` declaration, raw constructor-shaped starts, and separate class-level empty emitters as unresolved outside this marker callback.
- [x] Validators to run after implementation. Proof: commands `000000000111`, `000000000112`, and `000000000113` all exited `0` with `ok: 1`; queue-status commands `000000000114` and final sanity `000000000133` confirmed no pending generated refresh jobs.
- [x] Generated report refresh expected. Proof: generated `auto-generated/NexusTK/util/Error.cpp` is current at validator command `000000000132`, UID0002ND appears with the formal marker, and UID0002ND no longer has an empty-emitter marker. Generated files were not manually edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current callback accepted the report and requested implementation.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: target/support pages carry the accepted marker, MCP evidence, no-split/no-raw-dword reasoning, owner/emitter preservation, score rationale, and support sync facts.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: target is `89/92`, owner/emitter/reconstructable unchanged, no split/rename/new child, exact marker inserted.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: docs preserve raw-vtable rejection, blank/prose-only rejection, emitter-clearing rejection, `FALSE` rejection, `[[CHILDREN]]` rejection, per-class split rejection, feature-consumer-owner rejection, no-ref COL-prelude evidence, and remaining unresolved declaration caveats.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: UID0002ND empty-emitter question is resolved; broader original declaration/virtual-name/raw-constructor questions remain documented as outside this data-page marker.
- [x] Validators run and results recorded with command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state. Proof: see `Validator Results` above.
- [x] Generated `auto-generated/NexusTK/util/Error.cpp` checked for UID0002ND marker and absence of UID0002ND empty-emitter marker. Proof: generated lines 105-106 show UID0002ND followed by the marker, with no UID0002ND empty-emitter marker.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted implementation items remain unapplied; unresolved stale registry/missing-file diagnostics are validator/project-state issues outside this callback and were not hand-edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0002ND-ErrorHierarchyVtableData-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0002ND-ErrorHierarchyVtableData-empty-emitter-source-quality.md","timestamp":"2026-06-28T22:56:22","uid":"0002ND"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
