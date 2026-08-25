** TARGET-REPORT-UID:00034K **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00034K FolderTreePaneScalarDeletingDestructor Empty-Emitter Source-Quality Report

## Assignment

- Agent: `Agent-B001`
- Assignment id: `B001-report-00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality-20260628`
- Mode: report-only research first.
- Target: [UID:00034K][0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor](by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md)
- Queue source: `auto-generated/-ag-research-tracker.md` `Files With Empty Emitters`.
- Generated symptom: `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` line 219 currently emits `UID:00034K ... Empty Emitter Marker`.
- Hard exclusions observed: no by-* docs, generated files, coverage reports, validator/tool state, or IDA database were edited. The pending `00036K-FolderTreeVtableData-empty-emitter-source-quality.md` report was not modified.

## Executive Disposition

[UID:00034K] is not a source-authored destructor body and should not receive formal destructor C++. It is MSVC scalar-deleting destructor glue generated from [UID:00005A][FolderTreePane](by-class/FolderTreePane.md)'s `virtual ~FolderTreePane();` declaration, class layout, embedded `Tree` / `TreeItor` members, and delete expressions.

Implementation-ready disposition:

| UID | Range/title | Owner | Emitter route | Reconstructable | Score | Formal C++ disposition |
| --- | --- | --- | --- | --- | --- | --- |
| `00034K` | `0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor` | `00005A` | blank `EMITTER_UIDS:` | `TRUE` | `88/92` | blank formal C++; no comment marker |

This is a source-declared/generated-binary, non-emitting metadata child. The empty-emitter fix is to clear `EMITTER_UIDS:` on [UID:00034K] while keeping `CANONICAL_OWNER:00005A`, `RECONSTRUCTABLE:TRUE`, and a blank `RECONSTRUCTION_CPP CODE` block. The source representation stays in [UID:00005A]'s existing class shell:

```cpp
virtual ~FolderTreePane();
```

No target-level formal marker should be emitted. Recent scalar-deleting-destructor policy in [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) and [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) guidance distinguishes invoke-wrapper comment markers from scalar deleting destructor glue: scalar deleting destructor pages should use blank formal C++ plus blank `EMITTER_UIDS:` unless a supervisor explicitly approves a nonblank marker. Current evidence does not justify an exception.

Exact target formal C++ content after implementation:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended target item summary:

```text
Source-declared/generated-binary FolderTreePane scalar deleting destructor glue; source coverage is the [UID:00005A] virtual destructor/class declaration, with no standalone C++ emitter.
```

## Current Target State

Current [UID:00034K] metadata:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00005A`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00005A`
- blank formal C++ block
- item summary blank

This combination is the empty-emitter source of the generated marker: the child is routed into [UID:00005A] output but has no formal C++. The prose already says source should model the real destructor and not the scalar-deleting wrapper, but the metadata still asks the generator to emit this exact by-memory child.

## Evidence Checked

Local docs and generated state:

- Target page [UID:00034K] `by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md`.
- Generated output `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`, UID00034K empty-emitter marker.
- Queue row in `auto-generated/-ag-research-tracker.md`, direct zero-report row for UID00034K.
- Auto coverage row in `auto-generated/-ag-coverage-report-by-memory.md`, `emits_code:false`, reconstructable, `86%`.
- [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), current class shell includes `virtual ~FolderTreePane();` and `[[CHILDREN]]`.
- [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), current no-code policy: do not hand-port scalar deleting destructor glue.
- [UID:00036N][FolderTreePaneClassVtables](by-type/by-vtable/FolderTreePaneClassVtables.md) and [UID:00036O][0x0061a514-0x0061a5c4.FolderTreePaneVtableData](by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md), current vtable slot proof.
- [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md), existing non-reconstructable adjustor-thunk treatment.
- Sibling scalar deleting destructor pages [UID:00034I] and [UID:00034J] for `Tree` and `TreeItor` precedent.
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md), current local template/destructor support policy.

Prior executed B reports used as leads, not substitutes:

- `executed-b-agent-research/B001/000157-FolderTreePaneTreeAndSortHelpers.md`: split inventory records UID00034K as the exact `0x004b5a70-0x004b5af4` `FolderTreePane` scalar deleting destructor and says vtable-only refs to scalar deleting destructors prove destructor support, not standalone handwritten methods.
- `executed-b-agent-research/B008/00005A-FolderTreePane-class-source-quality.md`: accepted class-level source model emits a declaration shell for UID00005A and explicitly rejects standalone C++ for vtable bytes, adjustor thunks, and compiler-generated destructor glue.
- `executed-b-agent-research/B014/0000FB-FolderTreePaneTreeIterator-class-source-quality.md`: accepted iterator precedent keeps scalar deleting destructor support source-declared/generated-binary and lets the virtual destructor declaration regenerate it.

## Fresh MCP Evidence

MCP was live and used. Session details:

- `idb_list`: active session `supervisor_20260628_resume`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker pid `5124`.
- `server_health(database='supervisor_20260628_resume')`: status `ok`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

Live function lookup:

| Query | Result |
| --- | --- |
| `0x004b5a70` | `sub_4B5A70`, size `0x84`, exact end `0x004b5af4` |
| `0x004b59d5` | `sub_4B59D5`, size `0x0b`, secondary adjustor thunk |
| `0x004b59e0` | `sub_4B59E0`, size `0x0b`, tertiary adjustor thunk |
| `0x004b59f0` | `sub_4B59F0`, size `0x48`, sibling `Tree` scalar deleting destructor |
| `0x004b5a40` | `sub_4B5A40`, size `0x24`, sibling `TreeItor` scalar deleting destructor |
| `0x004b5b00` | `sub_4B5B00`, size `0xae`, next reset/root helper |
| `0x004b56e0` | `sub_4B56E0`, size `0x7f`, tree storage destructor |
| `0x004f4a90` | `sub_4F4A90`, size `0x7`, `LObject`-style teardown |
| `0x004f4ac0` | `sub_4F4AC0`, size `0x40`, scalar free path |
| `0x0055e780` | `sub_55E780`, size `0x59`, outer pane/base cleanup |

Live xrefs:

- `xrefs_to 0x004b5a70`: code refs from `0x004b59db` and `0x004b59e6` inside the two adjustor thunks, plus data ref from primary vtable slot `0x0061a518`. No ordinary source-call site exists.
- `xrefs_to 0x004b59d5`: one data ref from secondary vtable slot `0x0061a58c`.
- `xrefs_to 0x004b59e0`: one data ref from tertiary vtable slot `0x0061a5bc`.
- `xrefs_to 0x0061a518`: constructor store `0x004b1bd5`, cleanup store `0x004b1cf4`, destructor store `0x004b5a77`.
- `xrefs_to 0x0061a58c`: constructor store `0x004b1bdb`, cleanup store `0x004b1d00`, destructor store `0x004b5a83`.
- `xrefs_to 0x0061a5bc`: constructor store `0x004b1be5`, cleanup store `0x004b1d0a`, destructor store `0x004b5a8d`.
- `xrefs_to 0x0061a500`: tree vtable refs include constructor/cleanup/destructor stores and the outer destructor store at `0x004b5aa1`.
- `xrefs_to 0x0061a510`: iterator vtable refs include constructor/traversal/cleanup stores, the `TreeItor` scalar destructor store at `0x004b5a4a`, and the outer destructor store at `0x004b5a97`.

Live vtable dwords:

| Address | Dword | Meaning |
| --- | --- | --- |
| `0x0061a514` | `0x00647894` | primary COL/RTTI locator |
| `0x0061a518` | `0x004b5a70` | primary scalar deleting destructor slot |
| `0x0061a588` | `0x006478f4` | secondary COL/RTTI locator |
| `0x0061a58c` | `0x004b59d5` | secondary adjustor thunk slot |
| `0x0061a5b8` | `0x00647908` | tertiary COL/RTTI locator |
| `0x0061a5bc` | `0x004b59e0` | tertiary adjustor thunk slot |
| `0x0061a5c0` | `0x00544e90` | tertiary second virtual slot |
| `0x0061a4fc` | `0x0064791c` | `Tree<FolderTreePane::TreeElem>` COL/RTTI locator |
| `0x0061a500` | `0x004b59f0` | `Tree` scalar deleting destructor slot |
| `0x0061a50c` | `0x00647968` | `TreeItor<FolderTreePane::TreeElem>` COL/RTTI locator |
| `0x0061a510` | `0x004b5a40` | `TreeItor` scalar deleting destructor slot |

Live disassembly and decompilation:

- `0x004b5a77`: stores primary `FolderTreePane` vtable `0x0061a518`.
- `0x004b5a83`: stores secondary `FolderTreePane` vtable `0x0061a58c` at `this+0xa0`.
- `0x004b5a8d`: stores tertiary `FolderTreePane` vtable `0x0061a5bc` at `this+0xa4`.
- `0x004b5a97`: stores `TreeItor<FolderTreePane::TreeElem>` vtable `0x0061a510` at `this+0x170`.
- `0x004b5aa1`: stores `Tree<FolderTreePane::TreeElem>` vtable `0x0061a500` at `this+0x130`.
- `0x004b5aab`: calls `0x004b56e0` on `this+0x134`, the tree storage destructor.
- `0x004b5ab6`: calls `0x004f4a90` on `this+0x130`, `LObject`/tree base teardown.
- `0x004b5abd`: calls `0x0055e780` on `this`, the outer pane/base cleanup.
- `0x004b5ac2-0x004b5af1`: scalar deleting flag handling, normal free through `0x004f4ac0`, or guard-delete path with size `0x17c`.

Live bytes:

- `get_bytes 0x004b5a70 size 0x84` exactly covers the function.
- `get_bytes 0x004b5af4 size 0x0c` returns twelve `0xcc` bytes, confirming padding after the target and before the next helper at `0x004b5b00`.

Live callee set:

- `0x004b56e0`
- `0x004f4a90`
- `0x0055e780`
- `0x004f4ac0`
- `0x0041b6a0` / `@_guard_check_icall_nop@4`

This is exactly destructor/delete glue. There is no direct handwritten call graph route to this target.

## Source-Quality Analysis

Positive evidence for current ownership:

- The primary `FolderTreePane` vtable slot points directly at `0x004b5a70`; secondary and tertiary views point at two tiny adjustor thunks that jump into the same function.
- The body restores all three `FolderTreePane` vptr views and tears down the embedded `TreeItor` / `Tree` members in the order expected from the class layout documented on [UID:00005A].
- The direct class owner [UID:00005A] already emits a declaration-level class shell with `virtual ~FolderTreePane();`.
- The direct file owner [UID:0000JG] already says scalar deleting destructor glue should not be hand-ported.

Negative evidence against standalone C++:

- The target's only non-data code refs are adjustor thunks; it is not called like a source method.
- The body is scalar-deleting ABI glue with vptr stores, member/base teardown, flag-gated free, and a guard-delete size path. A source-authored `FolderTreePane::~FolderTreePane()` body would not explicitly hand-write these vptr stores or the scalar-deleting flags.
- The class declaration route is already present. Emitting a decompiler-shaped function body here would duplicate compiler output rather than reconstruct original project source.

Heuristic / inference closure:

| Issue | Current conclusion | Rejected alternative |
| --- | --- | --- |
| Is this handwritten destructor source? | No. It is compiler-generated scalar deleting destructor glue. | Hand-porting vptr stores, `a2` flag checks, and delete calls as formal source. |
| Should it be `RECONSTRUCTABLE:FALSE`? | No. Equivalent bytes must be regenerated from the reconstructable `FolderTreePane` class declaration and destructor semantics. | Treating it like [UID:000159] adjustor thunks, which are pure non-source glue and correctly `RECONSTRUCTABLE:FALSE`. |
| Should it keep `EMITTER_UIDS:00005A` with blank C++? | No. That is the current empty-emitter bug. | Leaving the generated `Empty Emitter Marker` in `FolderTreePane.cpp`. |
| Should it use a comment-only marker? | No for this scalar deleting destructor. The current no-code policy uses comment markers for proven invoke wrappers or selected data/storage coverage, but scalar deleting destructor glue should have blank formal C++ and blank emitter unless a supervisor explicitly approves otherwise. | Emitting `// covered by UID00005A` as target formal C++ under [UID:00005A]. |
| Does it need a split/container repair? | No. MCP confirms the exact function is `0x004b5a70-0x004b5af4`, followed by `CC` padding and the next helper at `0x004b5b00`. | Splitting the body or merging it into the next `FolderTreeResetToSingleRoot` helper. |

## Required Implementation Changes

Target page [UID:00034K] `by-memory/0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md`:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:00005A`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Change `EMITTER_UIDS:00005A` to blank `EMITTER_UIDS:`.
- Leave `RECONSTRUCTION_CPP CODE` blank; do not add a comment marker.
- Set item summary to the exact text in the Executive Disposition.
- Update Status, IDA Evidence, Reconstruction Notes, and Score Rationale to say this is non-emitting source-declared/generated-binary scalar deleting destructor glue covered by [UID:00005A]'s class declaration and `virtual ~FolderTreePane();`.
- Preserve the exact live MCP evidence from this report: session, range, xrefs, vtable dwords, disassembly/decompilation behavior, padding, and rejected alternatives.

Support page [UID:00005A] `by-class/FolderTreePane.md`:

- Keep `88/89`, owner/emitter [UID:0000JG], and the existing class shell.
- Add a source-quality sync note under the vtables/destructors boundary: [UID:00034K] is non-emitting scalar deleting destructor glue, and its source representation is the class declaration `virtual ~FolderTreePane();`.
- State explicitly that [UID:00034K] should have blank `EMITTER_UIDS:` and blank formal C++, not a comment marker or decompiler-shaped destructor body.

Support page [UID:0000JG] `by-file/FolderTreePane.md`:

- Keep `89/85` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`.
- Add a generated-output/no-code policy sync: UID00034K's exact child remains attached to the class but non-emitting; the file should emit the `FolderTreePane` declaration and real method children, not scalar deleting destructor glue.
- Mention that clearing UID00034K's emitter removes the generated empty marker without moving ownership to `FolderSelectDialog`, template support, or the vtable-data pages.

Support page [UID:00036N] `by-type/by-vtable/FolderTreePaneClassVtables.md`:

- Keep current owner/emitter [UID:00005A].
- Add a note that the `+0x00` primary slot `0x004b5a70` is represented through [UID:00005A]'s virtual destructor declaration; [UID:00034K] is non-emitting metadata with blank emitter/formal C++.

Support page [UID:00036O] `by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md`:

- Keep current owner/emitter [UID:00005A].
- Add the same slot/source-route note so the vtable-data page does not imply UID00034K should emit standalone code.

Optional support page [UID:0001XL] `by-type/by-vtable/FolderTreePaneVtables.md`:

- If touched during implementation, add one sentence mirroring [UID:00036N]/[UID:00036O]: scalar deleting destructor slots are generated from the class declaration, and [UID:00034K] is non-emitting metadata.
- This optional support sync is not required to resolve the empty marker if [UID:00036N] and [UID:00036O] receive the exact note.

No change required:

- [UID:000159] adjustor thunks already have the correct `RECONSTRUCTABLE:FALSE`, blank emitter, no-code disposition.
- [UID:00034I] and [UID:00034J] sibling scalar deleting destructor pages are analogous older empty-emitter candidates, but they are outside this assignment and should not be batch-edited without supervisor callback.
- Pending [UID:00036K] report remains separate and must not be implemented by this UID00034K callback.

## Validator Plan For Implementation Callback

Do not run `execute_report`; supervisor owns that.

After applying the accepted implementation edits, run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation\tools`:

> Executable block R001 was removed from this report and preserved verbatim in [00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality-removed.md](00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:0001XL] is edited:

> Executable block R002 was removed from this report and preserved verbatim in [00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality-removed.md](00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated-output freshness check after validators:

> Executable block R003 was removed from this report and preserved verbatim in [00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality-removed.md](00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: no UID00034K `Empty Emitter Marker`. Existing sibling empty markers in the same generated file are out of scope unless the supervisor assigns them separately.

## Implementation Tracking Checklist

- [x] Leased only active implementation files for the edit/validator batch. No active leases remained after cleanup, and the focused final revalidation lease was released immediately.
- [x] Edited [UID:00034K] metadata to `88/92`, owner `00005A`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS:`, and blank formal C++ with no comment marker.
- [x] Added target prose preserving live MCP evidence, padding span `0x004b5af4-0x004b5b00`, primary/secondary/tertiary vtable restores, embedded tree/iterator teardown route, optional delete flag handling, and rejected formal-C++/comment-marker/no-owner/false-reconstructable alternatives.
- [x] Updated [UID:00005A] `by-class/FolderTreePane.md` support note tying UID00034K to `virtual ~FolderTreePane();` and blank-emitter non-emitting metadata.
- [x] Updated [UID:0000JG] `by-file/FolderTreePane.md` file-level no-code policy note for UID00034K.
- [x] Updated [UID:00036N] `by-type/by-vtable/FolderTreePaneClassVtables.md` vtable support note for the `0x004b5a70` primary slot.
- [x] Updated [UID:00036O] `by-memory/0x0061a514-0x0061a5c4.FolderTreePaneVtableData.md` vtable-data support note for the same slot/source route.
- [x] Updated optional [UID:0001XL] `by-type/by-vtable/FolderTreePaneVtables.md` because the combined callback already touched the broader vtable page for UID00036K support.
- [x] Scoped validators with `--wait-generated`: target `by-memory\0x004b5a70-0x004b5af4.FolderTreePaneScalarDeletingDestructor.md` command `000000005347`, timestamp `2026-06-28T20:01:22-04:00`, exit `0`, `ok:1`; [UID:00005A] command `000000005353`, timestamp `2026-06-28T20:02:13-04:00`, exit `0`, `ok:1`; [UID:0000JG] command `000000005355`, timestamp `2026-06-28T20:02:31-04:00`, exit `0`, `ok:1`; [UID:00036N] command `000000005357`, timestamp `2026-06-28T20:02:51-04:00`, exit `0`, `ok:1`; [UID:00036O] command `000000005360`, timestamp `2026-06-28T20:03:11-04:00`, exit `0`, `ok:1`; [UID:0001XL] command `000000005364`, timestamp `2026-06-28T20:03:41-04:00`, exit `0`, `ok:1`. Each reported generated refresh completed.
- [x] Generated `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp` refreshed to validator command `000000005384` at `2026-06-28T20:08:00-04:00`; UID00034K no longer appears as an `Empty Emitter Marker`.
- [x] Confirmed no generated/project/coverage/tool-state/IDA DB files were manually edited and `execute_report` was not run.
- [x] Released short leases after validation; shared lease report showed no active leases after cleanup.

## Report-Only Status

This report resolves the empty-emitter disposition and provides implementation-ready target/support changes. No by-* docs or generated files were edited in this report-only pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality.md","timestamp":"2026-06-28T21:46:33","uid":"00034K"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00034K-FolderTreePaneScalarDeletingDestructor-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00034K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
