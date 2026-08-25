** TARGET-REPORT-UID:00041G **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:00041G] VectorGrowPart By-Memory Source Quality Report

Assignment: `B007-report-00041G-VectorGrowPart-by-memory-20260701`; implementation callback `B007-implement-00041G-VectorGrowPart-by-memory-20260701` accepted and applied 2026-07-01.  
Mode: report-only research followed by accepted implementation callback. Target/support by-* docs listed below were edited under short B007 leases; generated files and coverage reports were not manually edited.

## Target

- Primary target: `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`
- Generated family context: `auto-generated/NexusTK/render/NewHumanImageLib.cpp`
- Current target state at investigation time:
  - `COMPLETION:84`
  - `CONFIDENCE:86`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:` blank
  - Formal `RECONSTRUCTION_CPP CODE` block blank
- Tracker row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, score `84/86`, combined `85.0`, reports `0`.

## Evidence Checked

### Project Documentation

- `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`
- `by-file/NewHumanImageLib.md`
- `by-class/NewHumanImageLib.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
- `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`
- `by-type/by-struct/NewHumanImageLibLayout.md`
- `by-file/VectorHelpers.md`
- Accepted sibling support pages:
  - `by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md`
  - `by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md`
  - `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/NexusTK/render/NewHumanImageLib.cpp`

### Existing Report Search

Searched active and executed report trees by `00041G`, `0x004e5420`, `0x004e55f6`, `VectorGrowPart`, `NewHumanImageLib`, `LoadPartTable`, `VectorGrowLayer`, `VectorGrowAcc2Drw`, `VectorGrowMotion`, `vector grow`, `vector insert`, and `VectorHelpers`.

Relevant executed reports opened:

- `executed-b-agent-research/B007/00041B-NewHumanImageLibLoadPartTable-source-quality.md`
  - This report preserved [UID:00041G] as a below-gate/no-owner support page only because the UID00041B callback was scoped to `LoadPartTable`.
  - It recorded exactly two xrefs to `0x004e5420`: constructor callsite `0x004e0148` and `LoadPartTable` callsite `0x004e1356`.
- `executed-b-agent-research/B010/00041E-VectorGrowAcc2Drw-source-quality.md`
  - Accepted the direct file-owner marker route for a NewHumanImageLib-local vector grow helper.
  - Rejected direct `VectorHelpers` ownership for NewHumanImageLib-local element types while preserving `VectorHelpers` as compatibility-template fallback.
- `executed-b-agent-research/B011/00041F-VectorGrowLayer-source-quality.md`
  - Accepted the same file-owner marker route for another NewHumanImageLib-local vector grow helper.
  - Established the durable marker-only formal C++ pattern for compiler/STL vector-growth slow paths.
- `executed-b-agent-research/B011/0000LR-NewHumanImageLib-empty-emitter-family-source-quality.md`
  - Resolved NewHumanImageLib empty markers then visible in the generated file; [UID:00041G] was not included because it had no emitter route.
- `executed-b-agent-research/B002/00012G-simple-ustring-vector-grow-insert-source-quality.md`
- `executed-b-agent-research/B001/0001J4-simple-ustring-vector-pushback-source-quality.md`
  - These are useful contrast reports for real vector-object source APIs. UID00041G is different because the receiver is a NewHumanImageLib member-vector header, not an independently documented vector API owner.

No completed report for [UID:00041G] itself was found.

### IDA MCP Provenance

IDA MCP was live and responsive during the investigation.

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp`
- IDB session: `supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Worker PID observed: `14860`
- `server_health`: `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`

MCP requests used included `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `analyze_function`, and `disasm`.

## MCP Findings

### Function Boundary And Size

- `lookup_funcs 0x004e5420`: `sub_4E5420`
- Function size: `0x1d6` bytes, 470 decimal.
- Target range `0x004e5420-0x004e55f6` matches the exact function body.
- Bytes immediately before `0x004e5420` are tail/padding from the preceding function.
- `0x004e55f6` begins padding; the next function starts at `0x004e5600`.
- `lookup_funcs 0x004e55f6`: no function, confirming it is not a separate body start.

### Direct Xrefs

`xrefs_to 0x004e5420` returned exactly two code callers:

- `0x004e0148` in `sub_4DFD10`, documented as `NewHumanImageLib` constructor.
- `0x004e1356` in `sub_4E11B0`, documented as `NewHumanImageLib::LoadPartTable`.

No xrefs were found to the end address `0x004e55f6`.

### Caller Argument Evidence

Constructor callsite:

```asm
0x004e013d lea eax, [ebp+WideCharStr]
0x004e0143 push eax
0x004e0144 push ecx
0x004e0145 lea ecx, [esi+4]
0x004e0148 call sub_4E5420
```

`LoadPartTable` callsite:

```asm
0x004e134b lea eax, [ebp+WideCharStr]
0x004e1351 push eax
0x004e1352 push ecx
0x004e1353 lea ecx, [edi+4]
0x004e1356 call sub_4E5420
```

Both callers pass the member vector header at object offset `+4`, the current end pointer, and the address of the local 68-byte `NewHumanPartEntry` row. The adjacent inlined fast paths advance the vector end by `0x44`, confirming the element stride is 68 bytes.

### Helper Body Shape

`analyze_function 0x004e5420` reported:

- Prototype shape: `int __thiscall(_DWORD *this, _BYTE *Src, int)`
- Basic blocks: 23
- Cyclomatic complexity: 9
- Callees:
  - `operator new`
  - `sub_5C7526`
  - `_memmove_0`
  - `sub_421500`
  - `__invalid_parameter_noinfo_noreturn`

The body computes insertion index and size from `(end - begin) / 68`, checks against max element count `0x03c3c3c3` (63161283), grows capacity by approximately 1.5x clamped to the required size, allocates `68 * newCapacity`, copies the inserted 68-byte row as four 16-byte chunks plus one dword, moves prefix and suffix ranges with `_memmove_0`, frees old storage through `sub_5C7526`, and updates the three vector header pointers. The large-allocation path uses the standard allocation alignment/back-pointer pattern and calls `__invalid_parameter_noinfo_noreturn` on invalid metadata.

This is a vector reallocation/insert slow path for `NewHumanPartEntry`, not a hand-authored domain method.

## Positive Evidence

- The exact body is reconstructable and has a precise function range.
- The helper has exactly two direct callers and both are in the NewHumanImageLib file-local method family.
- Both callers pass the same member-vector receiver at object offset `+4`.
- Both callers already have source-level typed behavior in accepted docs as `m_partEntries.push_back(part)` or equivalent row append behavior.
- The element size is exactly 68 bytes, matching the documented `NewHumanPartEntry` row.
- Accepted sibling pages [UID:00041E] and [UID:00041F] already use the direct `NewHumanImageLib` file-owner marker route for NewHumanImageLib-local vector-growth slow paths.
- `VectorHelpers` has accepted documentation that direct ownership should not be assigned to local NewHuman-specific element helpers when a file-local source call covers the behavior.

## Negative Evidence

- The receiver register is the vector header, not the enclosing `NewHumanImageLib *`, so this should not be treated as a `NewHumanImageLib` class method with an ordinary source member signature.
- The helper has no independent xrefs outside the constructor and `LoadPartTable`.
- No evidence supports a separate source-authored API named literally `VectorGrowPart` in project source.
- A standalone formal helper body would expose compiler/STL allocation, memmove, and invalid-parameter details rather than the source-level domain operation.
- Direct `VectorHelpers` ownership would be broader than the observed evidence because the helper is tied to `NewHumanPartEntry` and NewHumanImageLib storage offset `+4`.
- Keeping `CANONICAL_OWNER:NONE` now loses generated output even though the accepted sibling pages show an implementation-ready owner/emitter route.

## Heuristic And Inference Reanalysis

The current page's conservative no-owner state was valid while [UID:00041G] was only collateral evidence for constructor and `LoadPartTable` work. It is no longer the best current disposition now that the target itself is in scope.

The source-facing behavior should be centralized in the already accepted file-level source operations:

- Constructor inline `Part.tbl` loading appends a `NewHumanPartEntry` to `m_partEntries`.
- `NewHumanImageLib::LoadPartTable` appends a `NewHumanPartEntry` to `m_partEntries`.

UID00041G is the compiler-emitted full-capacity slow path behind those appends. It should therefore emit a non-empty formal marker through [UID:0000LR] `NewHumanImageLib`, parallel to [UID:00041E] `VectorGrowAcc2Drw`, [UID:00041F] `VectorGrowLayer`, and [UID:000419]/[UID:00041A]-related vector support. This improves generated output without inventing a decompiler-shaped helper body.

## Ranked Owner And Source Placement Disposition

1. **Accepted route: [UID:0000LR] `by-file/NewHumanImageLib.md` as canonical owner/emitter.**
   - Use `CANONICAL_OWNER:0000LR` and `EMITTER_UIDS:0000LR` on [UID:00041G].
   - The generated file should receive a non-empty marker in `auto-generated/NexusTK/render/NewHumanImageLib.cpp`.
   - This matches the accepted route for NewHumanImageLib-local vector-growth support pages.

2. **Reject class-method ownership by [UID:000092] `NewHumanImageLib`.**
   - The body's `this` is a vector header, not the class object.
   - Source class docs can mention the helper as support evidence, but should not claim a standalone class method body.

3. **Reject direct [UID:0000P3] `VectorHelpers` ownership.**
   - The helper is only referenced by NewHumanImageLib part loading and uses the 68-byte `NewHumanPartEntry` row.
   - `VectorHelpers` remains the compatibility-template fallback if the recovered typed source cannot regenerate this out-of-line helper.

4. **Reject continued `CANONICAL_OWNER:NONE`.**
   - The no-owner state is stale for this target-specific pass because the accepted sibling reports already establish a safe file-local marker route.

5. **Reject standalone first-draft helper body.**
   - A full function body would be an allocator/vector-internal lowering, not source-authored NexusTK domain code.

## Score And Metadata Recommendation

Recommended update for `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`:

- `COMPLETION:87`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000LR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LR`
- Keep `EMITTER_POSITION_OPTIONAL:` blank.

Rationale:

- Raise completion because owner/emitter route and non-empty generated-output remedy are now implementation-ready.
- Raise confidence because MCP confirms exact function size, body boundaries, two direct callers, receiver offset, 68-byte element stride, and sibling ownership precedent.
- Do not raise to final-audit territory because exact original helper spelling and final project-wide vector-template policy remain not fully recovered. Those are score caps, not implementation blockers.

## Formal C++ Disposition

Insert the following text into the formal `RECONSTRUCTION_CPP CODE` block for [UID:00041G]:

```cpp
// Emitted code for this NewHumanPartEntry vector-growth slow path is covered by [UID:0002JR]
// and [UID:00041B] m_partEntries.push_back(part) source, or by a
// [UID:0000P3] VectorHelpers compatibility template if the recovered typed
// source cannot regenerate this out-of-line helper.
// Do not emit a standalone decompiler-shaped VectorGrowPart helper body here.
```

This is intentionally a formal non-empty marker, not prose-only text. It preserves generated-output coverage while avoiding an invented standalone helper implementation.

## Implementation-Ready Target And Support Changes

### Primary Target: `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`

Recommended callback edits:

- Update metadata to `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000LR`, `EMITTER_UIDS:0000LR`.
- Preserve `RECONSTRUCTABLE:TRUE` and blank `EMITTER_POSITION_OPTIONAL`.
- Add the formal marker C++ block shown above.
- Replace stale below-gate/no-owner wording with:
  - exact function size `0x1d6`/470 bytes;
  - exact range `0x004e5420-0x004e55f6`;
  - padding before/after boundary proof;
  - exactly two callers `0x004e0148` and `0x004e1356`;
  - caller receiver proof `lea ecx, [esi+4]` and `lea ecx, [edi+4]`;
  - 68-byte `NewHumanPartEntry` stride;
  - body summary: max-size guard, 1.5x growth, allocation, inserted row copy, prefix/suffix memmove, old storage free, pointer updates, invalid-parameter guard;
  - source placement: constructor/[UID:0002JR] and [UID:00041B] carry source-level `m_partEntries.push_back(part)`;
  - rejected alternatives: class method body, direct `VectorHelpers` owner, no-owner state, standalone helper body.

### `by-file/NewHumanImageLib.md`

Recommended callback edits:

- Historicalize stale text that says [UID:00041G] remains below-gate/no-owner.
- Add [UID:00041G] to the file-local vector-growth marker-support discussion beside [UID:00041E] and [UID:00041F].
- State that UID00041G is owned/emitted by [UID:0000LR] as a marker-only support page for `m_partEntries.push_back(part)`.
- Include concise MCP proof: two direct callers, 68-byte element, receiver `this+4`, no outside xrefs.
- No formal source body change is needed in this file.
- No score change is required unless the maintainer wants to reflect the additional resolved support page; current file score is already high enough for this callback.

### `by-class/NewHumanImageLib.md`

Recommended callback edits:

- Update helper/method inventory so [UID:00041G] is no longer listed as below-gate/no-owner.
- State that it is file-local vector-growth support for `m_partEntries`, not a class method.
- Keep class-level formal output unchanged.

### `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`

Recommended callback edits:

- Update child range state for [UID:00041G] from below-gate/no-owner support to file-local marker support through [UID:0000LR].
- Preserve the cluster as non-emitting.
- Do not add a cluster formal C++ body.

### `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`

Recommended callback edits if touched:

- Historicalize any statement that UID00041G remains unresolved/below-gate.
- Preserve the existing constructor C++ body and `m_partEntries.push_back(part)` source.
- Add only a support note that UID00041G is the full-capacity vector slow path now covered by a file-local marker.

### `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`

Recommended callback edits if touched:

- Historicalize any statement that UID00041G remains unresolved/below-gate.
- Preserve the existing `LoadPartTable` C++ body and `m_partEntries.push_back(part)` source.
- Add only a support note that UID00041G is the full-capacity vector slow path now covered by a file-local marker.

### `by-type/by-struct/NewHumanImageLibLayout.md`

Recommended callback edits if touched:

- Update support wording for the 68-byte `NewHumanPartEntry` row so UID00041G is recognized as file-local marker support rather than unresolved capacity-helper dependency.
- Do not add formal source body text.

### `by-file/VectorHelpers.md`

Recommended callback edits if touched:

- Add UID00041G to the direct-owner rejection list with the same rationale as UID00041E and UID00041F:
  - only NewHumanImageLib callers;
  - 68-byte `NewHumanPartEntry` element;
  - source-level appends already belong to NewHumanImageLib constructor and `LoadPartTable`;
  - `VectorHelpers` remains compatibility-template fallback, not direct owner.

## Generated Output Expectation

Current generated header observed:

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp`
- `validator-command-id: 000000004059`
- `validator-refreshed-at: 2026-07-01T17:13:44-04:00`

After callback validation, the generated file should refresh at or after the callback validator metadata and contain a non-empty UID00041G marker in the NewHumanImageLib generated output. UID00041G should not appear as an empty marker. Existing sibling markers for UID00041E/UID00041F should remain intact.

## Suggested Scoped Validators For Callback

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [00041G-VectorGrowPart-by-memory-source-quality-removed.md](00041G-VectorGrowPart-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the callback edits optional support files, also validate each touched file:

> Executable block R002 was removed from this report and preserved verbatim in [00041G-VectorGrowPart-by-memory-source-quality-removed.md](00041G-VectorGrowPart-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the validator expands UID references in the formal marker block, restore the exact formal marker text and rerun the target validator as needed.

## Validator Results

Implementation callback validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` while B007 edit leases were active:

| Command | command_id | command_timestamp | Exit | ok | Notes |
|---|---|---:|---:|---:|---|
| `python .\tools\validator.py --mode file --file by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md --apply --queue-timeout 240 --wait-generated` | `000000004079` | `2026-07-01T17:36:08-04:00` | 0 | 1 | Applied UID00041G metadata/owner/emitter/code-state updates; generated refresh completed. |
| `python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | `000000004081` | `2026-07-01T17:36:28-04:00` | 0 | 1 | File-root support validation; generated refresh completed. |
| `python .\tools\validator.py --mode file --file by-class/NewHumanImageLib.md --apply --queue-timeout 240` | `000000004083` | `2026-07-01T17:36:45-04:00` | 0 | 1 | Class support validation; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 240` | `000000004084` | `2026-07-01T17:36:53-04:00` | 0 | 1 | Cluster support validation; pre-existing missing UID0003UD references reported twice. |
| `python .\tools\validator.py --mode file --file by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md --apply --queue-timeout 240` | `000000004085` | `2026-07-01T17:37:00-04:00` | 0 | 1 | Constructor support validation; reference index added for UID0000P3. |
| `python .\tools\validator.py --mode file --file by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md --apply --queue-timeout 240` | `000000004086` | `2026-07-01T17:37:11-04:00` | 0 | 1 | LoadPartTable support validation. |
| `python .\tools\validator.py --mode file --file by-type/by-struct/NewHumanImageLibLayout.md --apply --queue-timeout 240` | `000000004087` | `2026-07-01T17:37:21-04:00` | 0 | 1 | Layout support validation; stats row updated for UID0001VF. |
| `python .\tools\validator.py --mode file --file by-file/VectorHelpers.md --apply --queue-timeout 240` | `000000004088` | `2026-07-01T17:37:33-04:00` | 0 | 1 | VectorHelpers support validation; pre-existing missing UID0003TP/0003SR/0003SC references reported, reference index added for UID00041B and UID00041G. |
| `python .\tools\validator.py --mode file --file by-file/NewHumanImageLib.md --apply --queue-timeout 240 --wait-generated` | `000000004089` | `2026-07-01T17:37:47-04:00` | 0 | 1 | Final freshness pass after optional support validators; generated refresh completed. |

Validator-owned side effects included `validator.ini` autogen registry rebuild/update, generated coverage/report metadata refreshes, projected stats updates, research tracker update, by-memory auto coverage update, and generated C++ refresh. These were validator outputs only.

Generated-output inspection after validation:

- `auto-generated/NexusTK/render/NewHumanImageLib.cpp`
- Header: `validator-command-id: 000000004089`
- Header: `validator-refreshed-at: 2026-07-01T17:37:47-04:00`
- Freshness: equal to the final `--wait-generated` validator metadata and later than the first target/file-root wait validators.
- UID00041G state: present as a non-empty marker at generated lines around 205-210, with `Completion:87 | Confidence:90` and the formal `VectorGrowPart` marker text.
- UID00041G empty-marker state: no UID00041G empty marker remained.
- UID00041E and UID00041F markers remained present immediately before UID00017T/UID00041G.

## Unresolved Issues And Blockers

No exact implementation blocker remains.

Residual score caps:

- Exact original source helper spelling is not proven.
- Final project-wide decision on whether to centralize all vector-template compatibility bodies in `VectorHelpers` remains broader than this target.
- The precise original header/source declaration layout for the NewHumanImageLib part-entry vector is not fully recovered.

These do not block the recommended file-local marker disposition because source-level behavior is already represented by `m_partEntries.push_back(part)` in constructor and `LoadPartTable`, and the formal UID00041G output can be a non-empty marker.

## Claim And Incorporation Ledger

| Claim ID | Claim | Target/support doc action | Rule 26 action value | Verification state | Proof / callback instruction |
|---|---|---|---|---|---|
| C1 | [UID:00041G] exact body is `0x004e5420-0x004e55f6`, `0x1d6`/470 bytes. | Primary target | incorporate | applied | Incorporated in `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md` Evidence/Behavior/Changes; validator `000000004079` ok. |
| C2 | UID00041G has exactly two direct callers: constructor `0x004e0148` and `LoadPartTable` `0x004e1356`. | Primary target, NewHumanImageLib support docs | incorporate | applied | Incorporated in primary target, `by-file/NewHumanImageLib.md`, `by-class/NewHumanImageLib.md`, cluster, constructor, and LoadPartTable support notes; validators `000000004079`, `000000004081`, `000000004083`, `000000004084`, `000000004085`, `000000004086` ok. |
| C3 | Both callers pass the member part-vector header at object offset `+4`. | Primary target, constructor, LoadPartTable, layout support docs | incorporate | applied | Incorporated in primary target, file/class/cluster notes, constructor support sync, LoadPartTable support note, and layout support note; validators `000000004079`, `000000004085`, `000000004086`, `000000004087` ok. |
| C4 | Element stride is 68 bytes and matches `NewHumanPartEntry`. | Primary target, layout support docs | incorporate | applied | Incorporated in primary target, file/class/cluster notes, LoadPartTable, and layout `NewHumanPartEntry` support; validators `000000004079` and `000000004087` ok. |
| C5 | Source-level behavior is covered by constructor and [UID:00041B] `m_partEntries.push_back(part)`. | Primary target, constructor, LoadPartTable | already-present | already-present | Existing formal constructor and LoadPartTable C++ were preserved; support prose now states UID00041G is only full-capacity marker lowering. Validators `000000004085` and `000000004086` ok. |
| C6 | UID00041G should be promoted from no-owner to file-local owner/emitter [UID:0000LR]. | Primary target, NewHumanImageLib file/class/cluster support | incorporate | applied | Primary target metadata now `CANONICAL_OWNER:0000LR`, `EMITTER_UIDS:0000LR`; file/class/cluster docs historicalize the old no-owner state. Validator `000000004079` applied metadata, and final generated refresh `000000004089` emitted UID00041G. |
| C7 | Direct class-method ownership by [UID:000092] should be rejected. | Primary target, class support doc | reject-invalid | applied | Primary target, class, and cluster docs state receiver is the vector header and not a `NewHumanImageLib *` method receiver. Validators `000000004079`, `000000004083`, `000000004084` ok. |
| C8 | Direct `VectorHelpers` ownership should be rejected for this UID. | Primary target, VectorHelpers support doc | reject-invalid | applied | Primary target rejects direct VectorHelpers ownership; `by-file/VectorHelpers.md` now has `VectorGrowPart Direct-Owner Rejection`. Validator `000000004088` ok. |
| C9 | Continued `CANONICAL_OWNER:NONE` wording should be historicalized. | Primary target and stale support references | historicalize | applied | Target, file, class, cluster, constructor, LoadPartTable, and layout stale support wording is now current or explicitly historical. Validators `000000004079` through `000000004088` ok. |
| C10 | A standalone decompiler-shaped helper body should not be emitted. | Primary target formal block | reject-invalid | applied | Formal block is a marker only; primary target, file/class/cluster, constructor, LoadPartTable, and VectorHelpers reject standalone helper C++. Generated file contains marker, not helper body. |
| C11 | The formal C++ block should contain the non-empty marker text in this report. | Primary target | incorporate | applied | Formal block inserted; validator canonicalized UID references normally. Generated `NewHumanImageLib.cpp` contains non-empty UID00041G marker after `000000004089`. |
| C12 | Constructor and LoadPartTable source bodies do not need functional rewrites. | Constructor and LoadPartTable support docs | already-present | already-present | Formal source bodies were not changed; only support/history prose was updated. Validators `000000004085` and `000000004086` ok. |
| C13 | Current generated output is stale for UID00041G because it has no emitter route. | Generated-output expectation only | not-applicable | applied | Stale generated state resolved by validators. Final generated header is `validator-command-id: 000000004089`, refreshed `2026-07-01T17:37:47-04:00`, and UID00041G appears as a non-empty marker. |

## Changed Files In This Callback

Manual by-* edits:

- `by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md`
- `by-file/NewHumanImageLib.md`
- `by-class/NewHumanImageLib.md`
- `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`
- `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
- `by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md`
- `by-type/by-struct/NewHumanImageLibLayout.md`
- `by-file/VectorHelpers.md`
- `tools/leaser/Agents/Agent-B007/research/00041G-VectorGrowPart-by-memory-source-quality.md`

Validator-owned generated/state side effects were produced by scoped validators, including generated `auto-generated/NexusTK/render/NewHumanImageLib.cpp` refresh. No generated file, coverage report, validator state, queue file, archive, supervisor ledger, by-project-structure doc, or IDA DB was manually edited.

## Implementation Tracking Checklist

- [x] Update [UID:00041G] metadata to `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000LR`, `EMITTER_UIDS:0000LR`, preserving `RECONSTRUCTABLE:TRUE` and blank `EMITTER_POSITION_OPTIONAL`. Proof: target header updated; validator `000000004079` applied completion/confidence/canonical_owner/emitter registry updates.
- [x] Insert the formal UID00041G marker C++ block exactly as recommended. Proof: formal block inserted; validator canonicalized UID references in normal form; generated output contains non-empty UID00041G marker after `000000004089`.
- [x] Add MCP-backed function boundary, size, xref, receiver, stride, body-shape, and source-placement evidence to the UID00041G target page. Proof: target Evidence/Behavior/Source Placement/Changes sections updated; validator `000000004079` ok.
- [x] Historicalize stale no-owner/below-gate wording on UID00041G. Proof: target status now `0000LR`; old 2026-06-30 no-owner note is explicitly superseded by 2026-07-01 callback.
- [x] Update `by-file/NewHumanImageLib.md` so UID00041G is file-local vector-growth marker support, not unresolved no-owner support. Proof: file inventory and generated-output route updated; validators `000000004081` and final `000000004089` ok.
- [x] Update `by-class/NewHumanImageLib.md` so UID00041G is support evidence and not a class method. Proof: method table, helper sync, and new 2026-07-01 section updated; validator `000000004083` ok.
- [x] Update `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` so UID00041G is file-local marker support while the cluster remains non-emitting. Proof: active helper table, helper sync, evidence list, and change log updated; validator `000000004084` ok with pre-existing missing UID0003UD warnings.
- [x] If touched, update constructor, `LoadPartTable`, layout, and `VectorHelpers` support docs only to remove stale unresolved wording and preserve existing formal source bodies. Proof: constructor support sync added without C++ body changes (`000000004085`); LoadPartTable score cap support updated (`000000004086`); layout `NewHumanPartEntry` note updated (`000000004087`); VectorHelpers direct-owner rejection added (`000000004088`).
- [x] Run scoped validators for every edited target/support file, using `--wait-generated` on the primary target and by-file validator. Proof: validators `000000004079`, `000000004081`, `000000004083`, `000000004084`, `000000004085`, `000000004086`, `000000004087`, `000000004088`, plus final freshness pass `000000004089`; all exit 0 / ok 1.
- [x] Inspect `auto-generated/NexusTK/render/NewHumanImageLib.cpp` after validation for refresh at/after callback validator metadata and a non-empty UID00041G marker. Proof: generated header `000000004089`, `2026-07-01T17:37:47-04:00`; UID00041G marker present and non-empty; no UID00041G empty marker.
- [x] Update this report's Claim And Incorporation Ledger and checklist with applied/already-present/excluded-with-reason/blocker states and proof during the implementation callback. Proof: this section updated after validation; no unchecked blockers remain.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00041G-VectorGrowPart-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00041G-VectorGrowPart-by-memory-source-quality.md","timestamp":"2026-07-01T17:49:43","uid":"00041G"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00041G-VectorGrowPart-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/00041G-VectorGrowPart-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00041G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
