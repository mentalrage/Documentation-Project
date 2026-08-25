** TARGET-REPORT-UID:0003BG **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003BG FolderSelectDriveRootString Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: implementation callback is complete; UID0003BG now emits the accepted file-scope static wide-string declaration and is ready for supervisor Gate 2 / execute review.
- Final disposition: source-declared/generated-binary data, owned and emitted by [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), not a `FolderTreePane` table member, not a mutable buffer, and not a standalone global needing a new file.
- Required action now: supervisor verification. Target metadata is now `88/93`; `CANONICAL_OWNER:0000JF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, and blank emitter position were preserved; the formal block now contains `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`.
- Confidence: high. Live MCP session `43ccf853` confirmed the bytes, section/naming context, two constructor dword loads inside the target range, and the successor RTTI/vtable boundary; validators and generated output confirmed the accepted declaration.

## Supporting Research

- Assignment source: `Agent-B006/goal.md` names UID0003BG `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md` for implementation after supervisor Gate 1 accepted this report at SHA `E2F0BBDF9EB557A10B4385BAC55182EE06928025A574DAD588F651BCAE93D4F5`.
- Report lifecycle: initial report-only state is historical. Current artifact is post-callback: target/support by-* docs were updated, scoped validators `000000007944` through `000000007947` passed, leases were released, and no `execute_report`, lifecycle/archive/manual report move, generated edit, coverage edit, validator-state edit, supervisor-ledger edit, queue edit, or lock edit was run by B006.
- Historical generated output before callback: `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp` command `000000007832`, refreshed `2026-07-07T03:37:36-04:00`, reported UID0003BG as `Completion:85 | Confidence:91 | Empty Emitter Marker`.
- Current generated output after scoped validators: `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp` command `000000007947`, refreshed `2026-07-07T16:00:50-04:00`, reports UID0003BG as `Completion:88 | Confidence:93` and contains `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`; UID0003BG no longer has an empty emitter marker.
- Current target docs now contain the accepted source-facing name, formal declaration, `88/93` score, two constructor dword loads including `0x004b1748 -> 0x0061a4f8`, duplicate mutable-buffer caveat, and successor boundary.
- Old report search found no prior direct UID0003BG report. Relevant executed reports were source-family leads only: B014 `000059-FolderSelectDialog-class-source-quality.md`, B003 `000457-FolderSelectDialogConstructor-source-quality.md`, B013 `000154-FolderSelectDialog-source-quality.md`, and B010 `0003BF-FolderSelectDialogVtableData-empty-emitter-source-quality.md`.

## Target

- Target UID: `0003BG`.
- Target path: `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`.
- Address range: `0x0061a4f4-0x0061a4fc`.
- Current supervisor classification: post-callback by-memory source-quality target, exact read-only UTF-16 drive-root literal.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:0000JF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, blank emitter position.
- Current formal C++: `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`, emitted through `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` row for UID0003BG reports zero prior reports and reconstructable true.

## Current Target State

- Current metadata is correct: owner/emitter [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md), reconstructable true, source-declared/generated-binary data disposition, `COMPLETION:88`, and `CONFIDENCE:93`.
- Current source-facing role is correct: the target is the read-only wide literal `L"X:\\"`, emitted as `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`, consumed by the FolderSelectDialog constructor before mutable drive-root buffer setup.
- Current C++/emitter state is complete for this callback: generated `FolderSelectDialog.cpp` command `000000007947` contains the accepted declaration under UID0003BG and no longer reports UID0003BG as an empty emitter.
- Current evidence is synchronized: target/support docs record both constructor dword loads from `0x0061a4f4` and `0x0061a4f8`, at instructions `0x004b173a` and `0x004b1748`.
- Current boundary state is correct: `0x0061a4fc` is the successor Tree vtable RTTI locator dword `0x0064791c`; UID0003BG was not expanded into the Tree vtable child.
- Related docs checked: `by-file/FolderSelectDialog.md`, `by-class/FolderSelectDialog.md`, `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`, `by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md`, `by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md`, and `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`.

## Executive Recommendation

- Best direct owner: keep [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md).
- Best emitter route: keep `EMITTER_UIDS:0000JF` so the declaration appears in `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp`.
- Target disposition: repaired as an emitting source-level constant, not by changing owner, splitting, merging, or making it non-emitting.
- Exact condition now: supervisor Gate 2 verification and supervisor-owned report execution if accepted.

## Supervisor Active Recheck

- Current supervisor instruction: Gate 1 passed for this report; B006 was instructed to implement the accepted target/support details, update the report ledger/checklist, run scoped validators, release leases, check generated `FolderSelectDialog.cpp`, and stop at `READY_FOR_SUPERVISOR_EXECUTE`.
- Split repair required before final report: no. Existing exact child range `0x0061a4f4-0x0061a4fc` is correct and bounded by already-documented predecessor/successor children.
- Source-bearing children in scope: UID0003BG remained the only direct target. The mutable duplicate at `0x0066da88` stayed separate and was not edited.

## Inference Research Guidance Check

- IDA facts are treated as primary for bytes, xrefs, not-a-function checks, and boundaries.
- Current by-* docs and generated reports are treated as leads/current-state evidence, not proof when they conflict with live MCP.
- Source-shape inference is used only for naming and source placement: a local `static const wchar_t` literal in `FolderSelectDialog.cpp` is the most plausible C++ representation for read-only `.rdata` bytes used only by the FolderSelectDialog constructor.
- Stale Wave2/Wave3 material was not used. No current Wave2/Wave3 override was found for this target.

## Heuristic / Inference Reanalysis And Validation

- Empty-emitter blocker: UID0003BG is reconstructable, owned/emitted by UID0000JF, and currently generates only an empty emitter marker. Because the bytes represent a source-level read-only literal and the target page already proposes a source-facing symbol, a formal C++ declaration is safer than leaving the target blank.
- Source-facing name: `kDefaultDriveRootLiteral` is descriptive, already present in current target/support docs, and avoids IDA generated dword labels. It is inferred, not original-symbol proof.
- Literal spelling: `L"X:\\"` exactly represents the four UTF-16 code units observed at `0x0061a4f4-0x0061a4fc`: `0x0058`, `0x003a`, `0x005c`, `0x0000`.
- Storage duration and constness: `.rdata` placement, no writes to the address, and constructor-only reads support `static const wchar_t[]`.
- Constructor use: disassembly shows two dword loads from the literal into a stack buffer before `GetCurrentDirectoryA` overwrites the first character with the current drive letter. This is still evidence for a default `X:\` wide literal initializer.
- Duplicate pattern: MCP `find_bytes` finds the same byte pattern at `0x0061a4f4` and `0x0066da88`. The second address is the separate mutable buffer UID00027D and does not weaken UID0003BG's read-only/source-literal classification.
- Boundary: the dword at `0x0061a4fc` is `0x0064791c`, immediately followed by Tree vtable entries. This rejects any expansion of UID0003BG past `0x0061a4fc`.
- Rejected source shapes: a handwritten `char` buffer is wrong for the observed UTF-16 data; a mutable `wchar_t[]` for UID0003BG is wrong because the mutable buffer is the separate `.data` target UID00027D; a FolderTreePane owner is wrong because all in-range consumer evidence before `0x0061a4fc` is from the FolderSelectDialog constructor.

## Evidence Standards Used

- Live MCP evidence used: session/health, raw bytes, integer reads, strings/tool limitations, names/sections, xrefs, function lookup, constructor decompile/disassembly, byte-pattern search, and range signature.
- Documentation evidence used: current target/support by-* docs, current generated C++ header and UID row, generated tracker/coverage reports, and relevant executed B-agent reports.
- Evidence ladder: direct binary facts determine bytes/xrefs/range; by-* docs determine current intended ownership and source-family context; inference determines only source-facing declaration spelling and score movement.
- Confidence limitation: original symbol spelling is not proven by PDB/source. The accepted symbol is therefore a documented source-quality inference, not an original-name claim.

## Evidence Checked

- MCP availability: `idb_list` returned active session `43ccf853` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health(database=43ccf853)` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- MCP byte checks: `get_bytes(0x0061a4f4, 8)` returned `58 00 3a 00 5c 00 00 00`; surrounding bytes show predecessor vtable bytes through `0x0061a4ec-0x0061a4f3` and successor dwords beginning `1c 79 64 00` at `0x0061a4fc`.
- MCP integer checks: `get_int` returned UTF-16 code units `88`, `58`, `92`, `0` at `0x0061a4f4`, `0x0061a4f6`, `0x0061a4f8`, `0x0061a4fa`; `u32le(0x0061a4fc)` returned `6584604` (`0x0064791c`).
- MCP xref checks: `xrefs_to(0x0061a4f4)` returned one data xref at `0x004b173a` in `sub_4B1590`; `xrefs_to(0x0061a4f8)` returned one data xref at `0x004b1748` in the same function; `xrefs_to(0x0061a4fc)` returned zero xrefs to the successor boundary cell.
- MCP function checks: `lookup_funcs(0x0061a4f4)` and `lookup_funcs(0x0061a4fc)` returned `Not a function`; `0x004b1590`, `0x004b173a`, and `0x004b183f` resolve to constructor/helper function `sub_4B1590`, size `0x346`.
- MCP names/strings checks: `entity_query` over `0x0061a4e0-0x0061a510` returned `.rdata` names at `0x0061a4ec` for the FolderSelectDialog vtable and at `0x0061a500`/`0x0061a510` for Tree/TreeItor vtables; no IDA string entity exists for the exact target range. `get_string(0x0061a4f4)` returns only `X` because IDA string typing treats the first NUL as a terminator, so direct UTF-16 byte decoding is the authoritative text evidence.
- MCP constructor checks: `disasm(0x004b1590)` shows `mov eax, ds:dword_61A4F4` at `0x004b173a`, `mov eax, ds:dword_61A4F8` at `0x004b1748`, and later mutable buffer uses at `0x004b183f`/`0x004b185b`. `decompile(0x004b1590)` collapses the literal into stack dword constants `3801176` and `92` before passing the stack wide string to `sub_4B1B90`.
- MCP duplicate check: `find_bytes("58 00 3A 00 5C 00 00 00", limit=20)` returned exactly `0x61a4f4` and `0x66da88`. `make_signature_for_range(0x0061a4f4-0x0061a4fc)` returned the same signature and `unique:false`.
- Current docs checked: target path, `by-file/FolderSelectDialog.md`, `by-class/FolderSelectDialog.md`, constructor UID000457, containing aggregate UID00025C, successor UID00036K, and sibling mutable buffer UID00027D.
- Workflow/structure docs checked: active `Agent-B006/goal.md`, project `ntk-b-agent-workflow` skill, `references/b-agent-research-and-implementation-workflow.md`, `references/b-agent-report-template.md`, and `by-structure.md` by-memory/formal-reconstruction rules.
- Old-report search terms checked with `rg`: `0003BG`, `0x0061a4f4`, `0061a4f4`, `FolderSelectDriveRootString`, `kDefaultDriveRootLiteral`, `DriveRootString`, plus broader `FolderSelect`/drive-root terms. Relevant executed-report leads were B014 UID000059, B003 UID000457, B013 UID000154, and B010 UID0003BF. No old direct UID0003BG report was found.
- Report-only validators were intentionally skipped in the initial phase. Post-callback scoped validators were run for the four edited by-* docs: `000000007944`, `000000007945`, `000000007946`, and `000000007947`, all exit 0 with `ok: 1`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID0003BG is the exact 8-byte UTF-16 literal `L"X:\\"` at `0x0061a4f4-0x0061a4fc`. | High | MCP bytes and u16 reads; target/support docs. | Target evidence/current state. | incorporate | applied: target Evidence/Score/Changes plus by-file/by-class/constructor support notes. |
| C002 | The target is not code and should remain by-memory string/data, not a function. | High | `lookup_funcs` returned `Not a function`; `.rdata` names context. | Target metadata/evidence. | already-present | already-present: preserved target entity kind/disposition and added B006 not-a-function evidence. |
| C003 | The full target range has two constructor data loads, `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`. | High | MCP `xrefs_to`/`xref_query`; constructor disassembly. | Target evidence and constructor/support notes. | incorporate | applied: target, by-file, by-class, and constructor docs now name both dword loads. |
| C004 | `0x0061a4fc` is the successor Tree vtable RTTI locator boundary and must not be included in UID0003BG. | High | MCP surrounding bytes and `u32le(0x0061a4fc)=0x0064791c`; successor docs. | Target boundary section and aggregate/support docs. | already-present | already-present: target/successor/aggregate already preserved boundary; target Change entry refreshed B006 proof. |
| C005 | Best owner/emitter remains `0000JF` FolderSelectDialog; no new file or FolderTreePane/global owner is justified. | High | Constructor-only xrefs before boundary; existing file/class docs; rejected alternatives. | Target metadata and support source-placement notes. | already-present | already-present: owner/emitter preserved; by-file/by-class support rejects non-FolderSelectDialog ownership. |
| C006 | Formal C++ is `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`. | High | `.rdata` placement, exact bytes, no writes, existing source-name direction. | Target `RECONSTRUCTION_CPP CODE` block. | incorporate | applied: target formal block contains the exact declaration; generated command `000000007947` emits it. |
| C007 | Metadata moved from `85/91` to `88/93`; owner/emitter/reconstructable/position remained unchanged. | Medium-high | Evidence blocker removed by exact MCP and formal C++ plan; original symbol spelling remains inferred. | Target header. | incorporate | applied: target header is `88/93`; validator `000000007944` recorded completion/confidence updates. |
| C008 | Pre-callback generated `FolderSelectDialog.cpp` command `000000007832` marked UID0003BG as an empty emitter; post-callback command `000000007947` emits the declaration. | High | Read-only generated C++ checks before/after callback. | Report, target Changes, generated-refresh checklist. | historicalize | applied: historical state documented; current generated file is fresh at command `000000007947` and no empty marker remains for UID0003BG. |
| C009 | The duplicate byte pattern at `0x0066da88` is the mutable buffer UID00027D and should not be merged with this read-only literal. | High | MCP `find_bytes`; sibling target docs; mutable-buffer xrefs/writes. | Negative evidence/support notes. | incorporate | applied: target/by-file/by-class preserve the duplicate-pattern caveat and separate UID00027D state. |
| C010 | Callback ran only scoped file validators and avoided forbidden report lifecycle/archive/generated/coverage/supervisor-ledger/validator-state actions. | High | Current `goal.md`, validator output, lease report, generated read-only check. | Validator Results / Changed Files / checklist. | incorporate | applied: validators recorded; leases released; forbidden action confirmation updated. |

## Positive Evidence Summary

- Raw bytes exactly encode `L"X:\\"` as UTF-16 with terminator.
- Constructor `sub_4B1590` reads both dwords of the literal and immediately uses them to construct the initial folder tree/root item after replacing the drive letter with the current directory drive.
- Existing FolderSelectDialog file/class/constructor docs already identify this exact target as the read-only drive-root literal and give the same source-facing name direction.
- The target has a valid by-file owner/emitter, is reconstructable true, and now has the formal C++ declaration in the target block and generated output.
- The successor boundary is independently confirmed by MCP and existing UID00036K docs.

## IDA MCP Facts

- Function/range facts: `0x0061a4f4` and `0x0061a4fc` are not functions. Constructor/user `sub_4B1590` starts at `0x004b1590`, size `0x346`.
- Data facts: `0x0061a4f4-0x0061a4fc` bytes are `58 00 3a 00 5c 00 00 00`; code units are `X`, `:`, `\\`, NUL.
- Boundary facts: bytes at `0x0061a4fc` begin `1c 79 64 00`, i.e. `0x0064791c`, the Tree vtable RTTI locator documented by the successor child.
- Xref facts: data refs to the literal range are `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`; there are zero xrefs to the successor boundary cell `0x0061a4fc`.
- Duplicate facts: exact 8-byte signature occurs at `0x61a4f4` and `0x66da88`; the latter is the separate mutable drive-root buffer.
- Tool limitation: IDA `get_string` returns only `X` for the target because the bytes are UTF-16 and not typed as an IDA string entity; direct byte/u16 decoding resolves the full literal.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0061a4f4-0x0061a4fc` | UID0003BG target | Read-only UTF-16 `L"X:\\"` default drive-root literal | TRUE | UID0000JF FolderSelectDialog | 88/93 current | Exact child, formal C++ now emits `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";` |
| `0x004b1590-0x004b18d6` | UID000457 constructor | Constructor/user that reads UID0003BG then builds folder tree state | TRUE | UID000059 / UID0000JF | 86/91 | Support evidence synced to both dword loads; constructor marker/no-code block unchanged |
| `0x0061a45c-0x0061a5c4` | UID00025C aggregate | Mixed read-only data container | FALSE | NONE | 86/92 | Existing child index; no aggregate C++ |
| `0x0061a4fc-0x0061a50c` | UID00036K successor | Tree vtable data beginning at successor RTTI locator | TRUE | FolderTree/FolderTreePane docs | 88/93 | Boundary support; no change required |
| `0x0066da88-0x0066da90` | UID00027D sibling | Mutable drive-root buffer initialized to same text | TRUE | UID0000JF FolderSelectDialog | 87/92 | Separate target; contrast evidence only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b173a` | Data read from `0x0061a4f4` in `sub_4B1590` | Loads first dword of the wide literal into a stack buffer. |
| `0x004b1748` | Data read from `0x0061a4f8` in `sub_4B1590` | Loads second dword containing backslash and terminator into the same stack buffer. |
| `0x004b176b` | `LOWORD(v24[0]) = Buffer[0]` after `GetCurrentDirectoryA` | Replaces default drive letter with current drive while preserving `":\\"`. |
| `0x004b178b` | Call to `sub_4B1B90(v10, stack wide string)` | Constructs/initializes the folder tree/root item from the drive-root string. |
| `0x004b183f` / `0x004b185b` | Reads/writes UID00027D mutable buffer | Separate per-drive loop buffer; not ownership evidence against UID0003BG. |

## Documentation Evidence And IDA Status

- Target doc now states the correct address range, owner/emitter, source-facing literal name, formal declaration, two constructor dword loads, duplicate mutable-buffer caveat, and boundary at `0x0061a4fc`.
- `by-file/FolderSelectDialog.md` and `by-class/FolderSelectDialog.md` now list UID0003BG as the read-only `L"X:\\"` / `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";` child while keeping the declaration file-scoped, not class-body C++.
- Constructor doc now records the full two-dword literal evidence, `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`, while preserving the constructor marker/no-code block.
- Containing aggregate and successor docs already preserve the correct split: UID0003BG is the child before the Tree vtable data, not part of the Tree range. They were not edited.
- Current generated output is fresh: `FolderSelectDialog.cpp` command `000000007947` / `2026-07-07T16:00:50-04:00` contains the UID0003BG declaration and no UID0003BG empty marker.
- Historical `project-level/-unresolved.md` generated-name hit from target prose remains validator/project-level generated state and was not edited; by-* source-facing docs continue to reject generated dword labels as source names.

## Ranked Ownership Analysis

### 1. UID0000JF FolderSelectDialog by-file owner/emitter

- Evidence for: the only data xrefs to the literal range are in the FolderSelectDialog constructor; current file/class docs already identify the literal as part of dialog drive-root setup; the generated target currently routes to `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp`.
- Evidence against: original symbol spelling is not proven and the same byte pattern appears in the mutable buffer; neither issue weakens the file owner because both uses belong to FolderSelectDialog.
- Decision: keep as canonical owner and sole emitter.

### 2. UID000059 FolderSelectDialog class owner

- Evidence for: the literal is used by the class constructor and appears in class documentation.
- Evidence against: source-level file-static literal is more plausible than a class member or class formal block entry; current emitter route is the by-file page, and the class page should not carry file-scope data definitions.
- Decision: support doc only, not canonical owner/emitter for this data target.

### 3. FolderTreePane / Tree vtable ownership

- Evidence for: the successor data immediately after the literal belongs to Tree/FolderTreePane vtables, which could mislead a broad range analysis.
- Evidence against: MCP confirms `0x0061a4fc` is the successor boundary; there are no xrefs to `0x0061a4fc` as part of the string; the literal's consumer is the FolderSelectDialog constructor.
- Decision: rejected.

### 4. UID00027D mutable drive-root buffer

- Evidence for: it has identical initial bytes and is used in the same source file during drive-list population.
- Evidence against: it is a separate `.data` target with write xrefs, while UID0003BG is read-only `.rdata` with constructor-only reads.
- Decision: keep separate; do not merge or substitute its mutable declaration for UID0003BG.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: not applicable; no new file/grouping is justified.
- Likely full contents: not applicable.
- Candidate related items rejected: FolderTreePane vtables and UID00027D mutable buffer are related context but not part of this target's declaration.
- Standalone, narrow, or broad source-file inference: narrow file-static constant inside `FolderSelectDialog.cpp`.

## Source Placement

- Recommended source file/class/global/module placement: `NexusTK/ui/dialogs/FolderSelectDialog.cpp` through [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md).
- Why this placement fits: the literal is consumed by the FolderSelectDialog constructor, current source-family docs route FolderSelectDialog method/data children through UID0000JF, and the generated output already places the UID row in `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp`.
- Rejected placements: class declaration block, FolderTreePane source, global browser/application/global docs, and the mutable UID00027D buffer.
- Remaining uncertainty: exact original symbol spelling is inferred; placement itself is strong.

## Range / Split / Padding / Reclassification Analysis

- Exact range facts: target starts at `0x0061a4f4` and ends before `0x0061a4fc`; bytes are exactly 8 bytes / four UTF-16 code units.
- Predecessor boundary: nearby `.rdata` names show the preceding FolderSelectDialog vtable data at `0x0061a4ec`.
- Successor boundary: `0x0061a4fc` is `0x0064791c`, the RTTI locator dword for the Tree vtable child beginning at `0x0061a4fc`.
- Split/reclassification recommendation: no split, merge, child creation, or range expansion. Keep UID0003BG as a reconstructable string-data child.
- Parent/container impact: containing aggregate UID00025C remains a non-emitting mixed index; exact children own the source-bearing facts.

## Negative Evidence Summary

- No function ownership: the target and successor boundary are not functions.
- No FolderTreePane ownership: successor data starts at `0x0061a4fc`; UID0003BG's xrefs are only inside the FolderSelectDialog constructor.
- No mutable-buffer ownership: duplicate bytes at `0x0066da88` have write/use xrefs and their own UID; those are contrast evidence, not a reason to merge.
- No generated-name source shape: IDA dword labels are disassembly artifacts caused by two dword loads; source docs should use `kDefaultDriveRootLiteral` or `L"X:\\"` instead.
- No reason to leave blank: the target is reconstructable, assigned to an emitter, has exact bytes, and has a source-level declaration shape that preserves behavior.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing name: `kDefaultDriveRootLiteral`.
- Proposed source-facing type: `static const wchar_t[]`.
- Evidence: `.rdata` placement, direct UTF-16 byte decode, current docs already using the same name direction, and constructor's stack copy/use.
- Items intentionally left unchanged: no IDA DB rename/type/comment edits were requested or performed in this B-agent callback.
- Safety: if a future supervisor/A-agent wants IDA renames, the exact source-facing symbol is safe as documentation naming, but this report does not require database edits.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. UID0003BG is reconstructable, file-owned source data with exact initializer bytes and no behavior-bearing code body.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` block insertion for the target:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: the initializer emits the same four wide characters `X`, `:`, `\\`, NUL observed at `0x0061a4f4-0x0061a4fc`; the constructor can copy/use the constant before patching the drive letter.
- Reason it matches plausible original source shape: a file-local read-only constant in `FolderSelectDialog.cpp` is ordinary VC-era C++ for a dialog-specific default path literal.
- Inferred source-facing names/types used instead of IDA/decompiler labels: `kDefaultDriveRootLiteral` replaces generated dword labels and decompiler temporary stack constants.
- Naming/coding style convention: current FolderSelectDialog docs already use `kDefaultDriveRootLiteral` and `s_driveRootBuffer`, so a `k` read-only constant beside an `s` mutable static is coherent.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes applied: raised target to `COMPLETION:88`, `CONFIDENCE:93`; preserved owner/emitter/reconstructable/position; inserted the formal C++ declaration; added current MCP evidence for bytes, two dword xrefs, duplicate mutable-buffer contrast, and generated-output freshness.
- Exact parent assignments applied/preserved: UID0000JF remains canonical owner and emitter; the target was not reassigned to class-only, FolderTreePane, or UID00027D.
- Exact items left no-owner/non-emitting: none for this target.
- Exact future work outside scope: UID00027D may deserve its own formal mutable-buffer C++ repair in a separate assignment, but this report should not alter it.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`.
- Current implementation result: target now incorporates MCP session `43ccf853` health; bytes `58 00 3a 00 5c 00 00 00`; u16 decode to `L"X:\\"`; two constructor xrefs at `0x004b173a` and `0x004b1748`; not-a-function checks; `0x0061a4fc -> 0x0064791c` successor boundary; duplicate pattern at `0x0066da88` belongs to mutable buffer UID00027D; and historical generated command `000000007832` showed the pre-callback empty-emitter state.
- Metadata/score/owner/emitter/reconstructable/C++ changes applied: `COMPLETION:88`, `CONFIDENCE:93`; `CANONICAL_OWNER:0000JF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, and blank position preserved; exact formal block inserted.
- Historical/stale assumptions, rejected alternatives, and negative evidence preserved: generated dword labels are rejected as source-facing names; FolderTreePane ownership and merging with UID00027D are rejected.

## Recommended Support Doc Changes

- Support path: `by-file/FolderSelectDialog.md`.
- Current implementation result: synced UID0003BG row/prose to say the read-only literal now has target formal declaration `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`, included the two constructor load addresses, and preserved broader file split and mutable-buffer distinction.
- Metadata/link/score/coverage/source-placement changes: no score change required; preserve UID0000JF placement and source path.

- Support path: `by-class/FolderSelectDialog.md`.
- Current implementation result: synced the data inventory/source-quality notes to treat UID0003BG as a file-scope read-only literal declaration, not class-body code, and included the two constructor dword loads.
- Metadata/link/score/coverage/source-placement changes: no score change applied; no class formal C++ change was made.

- Support path: `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`.
- Current implementation result: updated the drive literal reference from only `0x004b173a` / `0x004b173b` to the full two-dword evidence `0x004b173a -> 0x0061a4f4` and `0x004b1748 -> 0x0061a4f8`; preserved the constructor formal marker/no-code disposition.
- Metadata/link/score/coverage/source-placement changes: no score or formal C++ change required.

- Support path: `by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md`.
- Callback disposition: already-present/excluded-with-reason. This aggregate already has the correct child range and owner split at same-or-greater detail for this callback; no edit was needed.
- Metadata/link/score/coverage/source-placement changes: no score or formal C++ change required.

- Support path: `by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md`.
- Callback disposition: already-present. The successor-boundary page already records `0x0061a4f4-0x0061a4fc` as the UTF-16 `X:\` predecessor and `0x0061a4fc` as Tree RTTI/vtable data; no edit was needed.
- Metadata/link/score/coverage/source-placement changes: no score or formal C++ change required.

- Support path: `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md`.
- Callback disposition: excluded-with-reason. The mutable buffer page is contrast evidence only and contains no contradictory UID0003BG merge claim; no edit was needed.
- Metadata/link/score/coverage/source-placement changes: none for this report.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:88`, `CONFIDENCE:93`, owner/emitter UID0000JF, reconstructable true, formal C++ nonblank with the static const declaration.
- Historical pre-callback score/metadata: `COMPLETION:85`, `CONFIDENCE:91`, owner/emitter UID0000JF, reconstructable true, blank formal C++.
- Score rationale: completion improves because the last material source-quality blocker, the empty emitter, has a small exact formal C++ declaration with strong byte/xref evidence. Confidence improves because live MCP confirms the exact range, both constructor loads, and the successor boundary.
- Reason not higher: original symbol spelling is inferred. The constructor body itself is still a marker/no-code page, so this target should not be treated as proof of a final fully reconstructed constructor.
- Reason not lower: no ownership/range/open evidence blocker remains for this exact data child.
- Metadata fields to change: completion/confidence and formal C++ only.
- Metadata fields to leave unchanged: UID, owner, reconstructable, emitter UIDs, emitter position, address range, and by-file source placement.

## Open Questions With Attempted Resolution

- Open question: is `kDefaultDriveRootLiteral` original symbol spelling?
  - Evidence checked: current by-* docs, old reports, generated output, MCP names. No PDB/source evidence found.
  - Resolution: inferred source-facing name, not original-proof. It is still the best current documentation name because it is specific, already used in support docs, and avoids IDA labels.
- Open question: should the target emit a declaration or stay blank because the constructor could inline the literal?
  - Evidence checked: current generated output, formal block state, target metadata, constructor disassembly.
  - Resolution: emit a declaration. The target is reconstructable and assigned to an emitter; leaving it blank keeps a known empty emitter. If a future full constructor body inlines the literal, the target can later be converted to a coverage marker, but current docs and generator state are better served by the exact declaration.
- Open question: does the duplicate byte pattern at `0x0066da88` mean this should be mutable?
  - Evidence checked: MCP duplicate search and xrefs, UID00027D docs.
  - Resolution: no. UID00027D is a separate mutable buffer with write/use xrefs. UID0003BG is the read-only default literal.
- Open question: should any support doc score change with this target?
  - Evidence checked: file/class/constructor/aggregate/successor support docs.
  - Resolution: no score movement was applied to support docs. They were already strong and only needed synchronization facts for the accepted target update.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Applicable manual tracker/coverage text: none.
- Reason: `auto-generated/-ag-*` reports and generated C++ are validator-owned. The callback should update source by-* docs and run scoped validators for edited by-* files; B006 must not hand-edit generated coverage/tracker rows or manual coverage reports.

## Follow-Up Actions

- Supervisor actions: perform Gate 2 verification and execute the report if accepted.
- B006 callback actions: complete. Accepted target/support changes were applied or marked already-present/excluded, scoped validators ran, generated `FolderSelectDialog.cpp` freshness/content was verified, and this report ledger/checklist was updated.
- Future research action outside this report: consider a separate source-quality pass for UID00027D if the mutable drive-root buffer remains an empty emitter.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high for `88/93`.
- Remaining uncertainty: original symbol spelling and whether a future full constructor reconstruction would prefer an inline literal instead of a separate static declaration. This does not block the current empty-emitter repair.

## Validator Results

- Commands run:
  - `python .\tools\validator.py --mode file --file by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md --apply --queue-timeout 240` -> command `000000007944`, timestamp `2026-07-07T16:00:35-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file/FolderSelectDialog.md --apply --queue-timeout 240` -> command `000000007945`, timestamp `2026-07-07T16:00:37-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/FolderSelectDialog.md --apply --queue-timeout 240` -> command `000000007946`, timestamp `2026-07-07T16:00:39-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md --apply --queue-timeout 240` -> command `000000007947`, timestamp `2026-07-07T16:00:50-04:00`, exit `0`, `ok: 1`, generated refresh deferred.
- Results: all edited by-* file validators passed.
- Generated freshness/content check: `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp` header is `validator-command-id: 000000007947`, `validator-refreshed-at: 2026-07-07T16:00:50-04:00`, `validator-refresh-source: deferred-generated-refresh`; UID0003BG lines show `Completion:88 | Confidence:93` and `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`. UID0003BG no longer has an empty emitter marker.
- Validator side effects observed: validator-owned generated output refreshed; `project-level/-auto-completion-stats.md` projected path completion section was updated by scoped validators; generated/project-level state was not edited by B006.
- Forbidden lifecycle confirmation: no `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, validator lifecycle command, broad validator, generated edit, coverage edit, supervisor-ledger edit, validator-state edit, queue edit, or lock edit was run by B006.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B006/research/0003BG-FolderSelectDriveRootString-source-quality.md` during the initial report-only pass.
- Modified by B006 callback:
  - `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`
  - `by-file/FolderSelectDialog.md`
  - `by-class/FolderSelectDialog.md`
  - `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md`
  - `tools/leaser/Agents/Agent-B006/research/0003BG-FolderSelectDriveRootString-source-quality.md`
- Validator-owned generated refresh observed: `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp` refreshed to command `000000007947`; B006 did not edit generated files by hand.
- Renamed: none.
- Leases: acquired for the four edited by-* docs only during the edit/validator batch; released immediately after validators. Shared lease report shows no active leases.
- Report execution: not run. B006 must not run `execute_report`; supervisor executes only after independent Gate 2 verification.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor Gate 1 passed at SHA `E2F0BBDF9EB557A10B4385BAC55182EE06928025A574DAD588F651BCAE93D4F5` before callback.
- [x] Target doc to update: `by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md`. Proof: edited and validated by command `000000007944`.
- [x] Target metadata applied: `COMPLETION:88`, `CONFIDENCE:93`; UID, range, `CANONICAL_OWNER:0000JF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JF`, and blank emitter position preserved.
- [x] Target formal C++ applied: formal `RECONSTRUCTION_CPP CODE` block contains `static const wchar_t kDefaultDriveRootLiteral[] = L"X:\\";`.
- [x] Target evidence incorporated: MCP session `43ccf853` health, raw bytes, u16 decode, not-a-function status, two constructor dword xrefs (`0x004b173a` and `0x004b1748`), successor boundary `0x0061a4fc -> 0x0064791c`, duplicate mutable-buffer pattern at `0x0066da88`, and historical generated command `000000007832` empty-emitter state.
- [x] Support doc `by-file/FolderSelectDialog.md` synced UID0003BG as a file-scope read-only literal declaration and preserved UID0000JF source route. Proof: validator `000000007945`.
- [x] Support doc `by-class/FolderSelectDialog.md` synced data inventory/source-quality notes only; no file-scope data was added to the class formal C++ block. Proof: validator `000000007946`.
- [x] Support doc `by-memory/0x004b1590-0x004b18d6.FolderSelectDialogConstructor.md` synced drive-literal evidence to both dword loads while preserving the constructor marker/no-code block. Proof: validator `000000007947`.
- [x] Support doc `by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md` confirmed already-present/excluded-with-reason: child/range and owner-split facts are already at sufficient detail; no edit needed.
- [x] Support doc `by-memory/0x0061a4fc-0x0061a50c.FolderTreeVtableData.md` confirmed already-present: successor-boundary facts are already at sufficient detail; no edit needed.
- [x] Support doc `by-memory/0x0066da88-0x0066da90.FolderSelectDriveRootBuffer.md` excluded-with-reason: contrast evidence only and no contradictory merge claim found; no edit needed.
- [x] Claim And Incorporation Ledger updated with `applied`, `already-present`, `historicalize`, or `excluded-with-reason` states for C001-C010.
- [x] Historical/stale assumptions preserved/rejected: FolderTreePane ownership rejected, mutable-buffer merge rejected, IDA generated labels rejected as source-facing names, and duplicate-pattern caveat preserved.
- [x] Open questions preserved as evidence-backed unresolved: original symbol spelling remains inferred; future inline-literal constructor body is out of scope.
- [x] Validators run only for edited by-* files from `source-3/project-documentation`: commands `000000007944`, `000000007945`, `000000007946`, and `000000007947`.
- [x] Generated refresh verified: `auto-generated/NexusTK/ui/dialogs/FolderSelectDialog.cpp` refreshed to command `000000007947` / `2026-07-07T16:00:50-04:00` and replaced UID0003BG's empty emitter marker with the static const declaration under the UID row.
- [x] Generated/coverage/supervisor-ledger/validator-state/queue/archive/lifecycle files were not edited by B006.
- [x] Forbidden commands not run: `execute_report`, dry-run/probing execute variants, lifecycle/archive/manual report moves, registry commands, validator lifecycle commands, and broad validators.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail or marked already-present/excluded-with-reason.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/C++ changes applied; no split/rename/new-child changes were requested.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Scoped validators run for every edited by-* file and command IDs/timestamps/results recorded.
- [x] Generated `FolderSelectDialog.cpp` freshness checked after validation.
- [x] Leases acquired only for immediate edits and released immediately after the edit/validator batch. Proof: shared lease report shows no active leases.
- [x] Remaining unapplied accepted items: none. Already-present/excluded support pages are documented with reasons above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000007954","destination_path":"executed-b-agent-research/B006/0003BG-FolderSelectDriveRootString-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0003BG-FolderSelectDriveRootString-source-quality.md","timestamp":"2026-07-08T15:32:53-04:00","uid":"0003BG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
