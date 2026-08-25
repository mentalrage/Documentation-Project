** TARGET-REPORT-UID:000216 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000216 BrowserWindow Release Adjustor Tail Thunks Source-Quality Research


## Finalized Report / Current Recommendation

Status: implementation callback complete after Gate 1 acceptance, with the original mandatory IDA MCP evidence from active session `supervisor_recovery_20260705` incorporated into target/support docs.

UID000216 should be treated as exact, non-emitting BrowserWindow compiler-generated COM adjustor tail thunks. The two functions at `0x004710b8` and `0x004710c2` only adjust the stack-passed `this` pointer by `0x10` or `0x0c` and tail-jump to canonical `BrowserWindow::Release` at `0x0046a0c0`. Their only direct inbound references are BrowserWindow vtable data slots at `0x006132dc` and `0x00613290`.

Recommended disposition after supervisor callback:

- Keep semantic owner as `CANONICAL_OWNER:00001B` because the vtable slices are named BrowserWindow and the thunks delegate to BrowserWindow Release.
- Change source-emission status to non-emitting: `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, and keep `RECONSTRUCTION_CPP` blank.
- Target body was updated to remove stale legacy parent-field wording and replace it with current canonical-owner / no-emitter language.
- Update support docs only to synchronize the no-code reason; do not add a C++ body or generated coverage/report rows manually.

## Supporting Research

Required prior-report search was performed over `executed-b-agent-research` and `tools/leaser/Agents` using terms including:

- `000216`
- `0x004710b8`
- `0x004710cc`
- `BrowserWindowReleaseAdjustorTailThunks`
- `BrowserWindow`
- `Release`
- `adjustor thunk`
- `tail thunk`
- `COM vtable`
- `BrowserOleLegacyAndHelpers`
- `BrowserOleAdjustorAndDelegationThunks`
- `empty emitter`

Relevant opened prior reports:

- `executed-b-agent-research/B002/0000HV-Browser-empty-emitter-family-source-quality.md`
  - Lists UID000216 as an empty-emitter row.
  - Prior conclusion: compiler adjustor thunks; comment coverage is appropriate after BrowserWindow COM base layout / Release route is accepted.
- `executed-b-agent-research/B001/0000ZF-BrowserOleLegacyAndHelpers.md`
  - Confirms adjacent aggregate `0x0046f010-0x004710b8` is half-open and ends before UID000216.
  - Treats in-range ABI/compiler thunk islands as non-emitting.

The prior reports are consistent with the current MCP evidence, except that UID000216 can now be made more precise: this target should not remain a source-emitting empty marker.

## Target

- Target UID: `000216`
- Target path: `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md`
- Assigned report path: `tools/leaser/Agents/Agent-B010/research/000216-BrowserWindowReleaseAdjustorTailThunks-source-quality.md`
- Scope: two BrowserWindow `Release` adjustor tail thunks, owner/source route, vtable evidence, COM/multiple-inheritance modeling, and source-emission decision.

## Current Target State

Current target metadata records:

- `COMPLETION:85`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00001B`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00001B`
- Blank `RECONSTRUCTION_CPP`

Before callback, the body correctly identified two exact Release adjustor thunks and vtable refs at `0x006132dc` and `0x00613290`, but still contained stale legacy parent-field wording. The implementation callback replaced that wording with current canonical-owner and no-emitter language.

The generated Browser output currently carries UID000216 as an empty emitter marker in `auto-generated/NexusTK/browser/Browser.cpp`; the tracker row marks it reconstructable with code count `0`. This is a symptom of the target being marked reconstructable even though the bytes are compiler ABI glue.

## Heuristic / Inference Reanalysis And Validation

The old heuristic risk was that blank C++ plus `RECONSTRUCTABLE:TRUE` could be interpreted as missing first-draft source. MCP validation removes that ambiguity.

The range is not an unimplemented source function. It is two compiler-generated adjustor thunks created for BrowserWindow COM interface views:

- `sub_4710B8`: `this -= 0x10`; tail-call `BrowserWindow::Release`.
- `sub_4710C2`: `this -= 0x0c`; tail-call `BrowserWindow::Release`.

No unique branch, state mutation, allocation, destructor, COM reference-count field, or user-authored behavior exists inside UID000216. The source-level obligation belongs to the BrowserWindow COM inheritance/base declaration and the canonical Release implementation, not to handwritten thunk functions.

## Evidence Standards Used

The research followed the project-level B-agent workflow and `by-structure.md` IDA MCP Output Discipline:

- Used the active MCP session `supervisor_recovery_20260705`.
- Used narrow exact-address MCP calls.
- Avoided broad/unbounded disassembly, callgraph, type, and batch-analysis calls.
- During the report-only pass, did not run validators, lifecycle commands, `execute_report`, dry-run/probing variants, generated-report edits, manual coverage edits, or report moves.
- During the accepted implementation callback, edited only the leased target/support by-* docs and ran scoped file validators. Did not manually edit generated reports, coverage files, validator state, lifecycle/archive files, or supervisor ledgers.

## Evidence Checked

Local documentation checked read-only:

- `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md`
- `by-class/BrowserWindow.md`
- `by-file/Browser.md`
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
- `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md`
- `by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md`
- `by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md`
- `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md`
- `by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md`
- `by-global/g_pActiveBrowserWindow.md`
- `by-memory/0x0067ab94-0x0067ab98.g_pActiveBrowserWindow.md`
- `auto-generated/NexusTK/browser/Browser.cpp`
- `auto-generated/-ag-research-tracker.md`

IDA MCP evidence checked:

- Server/session health.
- Exact function lookup around target, predecessor, successor, and canonical Release.
- Exact bytes for the thunk cluster and following padding.
- Exact disassembly and decompilation for both UID000216 functions.
- Exact bytes around BrowserWindow vtable slots.
- Direct xrefs to each thunk and to canonical Release.
- Narrow entity/name query for local function boundaries and vtable names.
- Narrow type query for recovered BrowserWindow type data.

## Claim And Incorporation Ledger

| Claim ID | Claim Text | Confidence | Evidence | Exact Destination Doc / Section | Action | Verification State |
| --- | --- | --- | --- | --- | --- | --- |
| CL-001 | UID000216 current metadata marks the target reconstructable with `EMITTER_UIDS:00001B` while the C++ block is blank, producing an empty-emitter condition. | High | Target header/body; generated Browser.cpp empty marker; tracker code count `0` | `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md` / header metadata and Autogen Status | incorporate by changing metadata to no-emitter state | applied - target now has `COMPLETION:88`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++ |
| CL-002 | Target body still used stale legacy parent-field wording that did not match current canonical-owner/emitter metadata. | High | Target Autogen Status and Assignment Gate prose | `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md` / Autogen Status, Assignment Gate, Item Summary | incorporate by replacing stale parent wording with `CANONICAL_OWNER:00001B` plus no-emitter wording | applied - target now uses canonical-owner/no-emitter wording and contains no legacy parent-field literal |
| CL-003 | The exact UID000216 range contains two 0xa-byte functions at `0x004710b8` and `0x004710c2`; `0x004710cc` is padding, not a child function. | High | MCP `lookup_funcs`, `entity_query`, bytes at `0x004710a4` size `44` | Target / Raw Code, Range/Boundary evidence; optional sync in `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md` | incorporate exact range and padding proof in target; optional adjacent cross-note when direct location exists | applied - target records two functions plus `0xcc` padding, and adjacent UID00033M page now notes UID000216 starts after the half-open endpoint as non-emitting compiler glue |
| CL-004 | Both target functions are adjusted-this Release tail thunks: `sub_4710B8` subtracts `0x10`; `sub_4710C2` subtracts `0x0c`; both tail-jump to `sub_46A0C0`. | High | MCP disasm, bytes, decompile facts | Target / Raw Code, No-Code Proof, Positive Evidence; `by-class/BrowserWindow.md` / COM adjustor-thunk note | incorporate as evidence, not source code | applied - target no-code proof and BrowserWindow evidence record both deltas and the tail jump |
| CL-005 | `sub_46A0C0` is the canonical BrowserWindow Release implementation in current docs and MCP shows it returns `1` with `retn 4`. | High | MCP disasm `mov eax, 1; retn 4`; BrowserWindow method list | Target / Delegation evidence; `by-class/BrowserWindow.md` / Release method evidence | incorporate or preserve at same detail | applied - target states `sub_46A0C0` is canonical Release and returns `1`; BrowserWindow still lists `0x0046a0c0 Release` |
| CL-006 | Target thunk starts are referenced only by BrowserWindow vtable data slots: `0x006132dc -> 0x004710b8` and `0x00613290 -> 0x004710c2`; no ordinary code callers were found. | High | MCP `xrefs_to`, `xref_query`, vtable bytes | Target / Vtable Xrefs and Direct Xref evidence; `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` / BrowserWindow vtable entries | incorporate exact vtable-only reachability | applied - target and vtable index both record `0x00613290 -> 0x004710c2` and `0x006132dc -> 0x004710b8` as vtable-only refs |
| CL-007 | BrowserWindow is the semantic owner because both slots are in named BrowserWindow vtable slices and the thunks delegate to BrowserWindow Release. | High | MCP vtable names `??_7BrowserWindow@@6B@_2` and `_3`; target Release tail-jumps | Target / header `CANONICAL_OWNER`; `by-class/BrowserWindow.md` / COM thunk inventory | incorporate by keeping `CANONICAL_OWNER:00001B` | applied - target keeps `CANONICAL_OWNER:00001B`, and BrowserWindow class note explains semantic/class-layout ownership rather than source emission |
| CL-008 | Browser remains the current practical source-root route for BrowserWindow, but UID000216 itself should not emit into Browser.cpp. | Medium-High | `by-file/Browser.md`; generated `auto-generated/NexusTK/browser/Browser.cpp` empty marker | `by-file/Browser.md` / BrowserWindow source-root note; target / Source Placement | incorporate as source-route/no-emitter distinction | applied - Browser file now states UID000216 should not emit a Browser.cpp body or empty marker; generated Browser.cpp refreshed without UID000216 |
| CL-009 | Adjacent thunk policy and prior reports support treating ABI/compiler thunk islands as non-emitting. | Medium-High | B002 UID000216 empty-emitter report; B001 BrowserOleLegacyAndHelpers report; UID00033M adjacent doc | Target / Supporting Research or Historical Context; adjacent UID00033M cross-note | incorporate as historical/policy support, not as primary MCP evidence | applied - target history is historicalized under current MCP facts, Browser retains B002 empty-emitter context, and UID00033M adjacent cross-note records non-emitting thunk glue |
| CL-010 | No recovered BrowserWindow UDT/type data was available from the narrow MCP type query, so exact COM base declaration remains a support-doc/source-layout open question. | Medium | MCP `type_query *BrowserWindow*` returned no recovered type/UDT data | Target / Open Questions With Attempted Resolution; `by-class/BrowserWindow.md` / Open Questions | incorporate unresolved layout blocker with score impact | applied - target and BrowserWindow keep final COM layout/source split as unresolved while no-emitter classification is complete |
| CL-011 | A handwritten first-draft C++ body is not required and would be misleading for this target. | High | CL-003 through CL-007; no local behavior beyond adjustment and tail jump | Target / `RECONSTRUCTION_CPP` header and block; Target / First-Draft C++ or no-code proof prose | reject stale source-body assumption; leave formal C++ insertion empty | applied - formal C++ remains blank and no illustrative C/C++ body was added to target/support docs |
| CL-012 | Manual edits to generated Browser.cpp, generated tracker/coverage files, manual coverage reports, validator state, or lifecycle files are excluded from B-agent implementation. | High | Assignment restrictions; project workflow | Explicit exclusion: generated files and coverage/tracker disposition are supervisor/validator-owned, not target/support destinations | not-applicable / exclude | excluded-with-reason - no manual generated, coverage, validator-state, lifecycle, or supervisor-ledger edits; generated/tracker/coverage changes were validator-owned refresh side effects |
| CL-013 | Scoped validators are required only after a supervisor-authorized implementation callback edits target/support by-* docs. | High | Assignment restrictions; workflow validator section | Report / Validator Results; callback validation notes | incorporate validator results after callback | applied - scoped validators ran for all five changed by-* docs, each exit code `0` with `ok: 1` |

## Positive Evidence Summary

- Exact bytes show two 0xa-byte target functions followed by `0xcc` padding at `0x004710cc`.
- Exact disassembly shows each target function has only `sub [esp+arg_0], imm` and `jmp sub_46A0C0`.
- Decompiler output matches the adjusted-this pattern:
  - `sub_4710B8(a1)` returns `sub_46A0C0(a1 - 16)`.
  - `sub_4710C2(a1)` returns `sub_46A0C0(a1 - 12)`.
- Vtable bytes show `0x004710c2` at `0x00613290` and `0x004710b8` at `0x006132dc`.
- Vtable names in the same range are BrowserWindow slices:
  - `0x00613288 ??_7BrowserWindow@@6B@_2`
  - `0x006132d4 ??_7BrowserWindow@@6B@_3`
- Direct xrefs to target thunk starts are data-only vtable references; there are no ordinary code callers to either thunk start.

## IDA MCP Facts

MCP session:

- Session: `supervisor_recovery_20260705`
- `idb_list`: count `1`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Auto-analysis ready: true
- Hex-Rays ready: true
- Strings cache ready: true
- Server health: OK

Function lookups:

| Address | Result |
| --- | --- |
| `0x004710a4` | `sub_4710A4`, size `0xa` |
| `0x004710ae` | `sub_4710AE`, size `0xa` |
| `0x004710b8` | `sub_4710B8`, size `0xa` |
| `0x004710c2` | `sub_4710C2`, size `0xa` |
| `0x004710cc` | not a function |
| `0x004710d0` | `sub_4710D0`, size `0xf` |
| `0x0046a0c0` | `sub_46A0C0`, size `0x8` |
| `0x00469f60` | `sub_469F60`, size `0x148` |

Bytes at `0x004710a4`, size `44`:

```text
83 6c 24 04 04 e9 12 90 ff ff
83 6c 24 04 08 e9 08 90 ff ff
83 6c 24 04 10 e9 fe 8f ff ff
83 6c 24 04 0c e9 f4 8f ff ff
cc cc cc cc
```

Target disassembly:

```asm
; sub_4710B8
004710b8  sub dword ptr [esp+arg_0], 10h
004710bd  jmp sub_46A0C0

; sub_4710C2
004710c2  sub dword ptr [esp+arg_0], 0Ch
004710c7  jmp sub_46A0C0
```

Canonical Release disassembly:

```asm
; sub_46A0C0
0046a0c0  mov eax, 1
0046a0c5  retn 4
```

Target decompilation facts:

- `sub_4710B8` is represented by Hex-Rays as a call-through to `sub_46A0C0` with the incoming argument adjusted by `-16`.
- `sub_4710C2` is represented by Hex-Rays as a call-through to `sub_46A0C0` with the incoming argument adjusted by `-12`.

BrowserWindow vtable bytes around `0x00613288` include:

| Slot | Value | Meaning |
| --- | --- | --- |
| `0x00613288` | `0x0047104a` | adjacent BrowserWindow thunk slot |
| `0x0061328c` | `0x004708bd` | adjacent BrowserWindow stub/slot |
| `0x00613290` | `0x004710c2` | UID000216 Release adjustor thunk |
| `0x006132dc` | `0x004710b8` | UID000216 Release adjustor thunk |

Narrow type query for `*BrowserWindow*` returned no recovered BrowserWindow UDT/source type data. That is negative evidence for deriving an exact source declaration solely from IDA type information in this pass.

## Function / Child Inventory

Narrow local entity query over `0x004710a4-0x004710d0` found:

| Function | Range | Relationship |
| --- | --- | --- |
| `sub_4710A4` | `0x004710a4-0x004710ae` | predecessor adjustor thunk, outside UID000216 |
| `sub_4710AE` | `0x004710ae-0x004710b8` | predecessor adjustor thunk, outside UID000216 |
| `sub_4710B8` | `0x004710b8-0x004710c2` | UID000216 target child |
| `sub_4710C2` | `0x004710c2-0x004710cc` | UID000216 target child |
| `sub_4710D0` | starts `0x004710d0` | successor BrowserPane/timer-cancel function, outside UID000216 |

No extra child function exists at `0x004710cc`; the bytes there are padding.

## Direct Xref / Caller Inventory

| Target | Direct xrefs | Interpretation |
| --- | --- | --- |
| `0x004710b8` | data xref from `0x006132dc` only | BrowserWindow vtable slot only |
| `0x004710c2` | data xref from `0x00613290` only | BrowserWindow vtable slot only |
| `0x0046a0c0` | code xrefs from `0x004710a9`, `0x004710b3`, `0x004710bd`, `0x004710c7`; data xref from `0x00613208` | canonical Release target for multiple vtable/interface views |
| `0x004710d0` | data xrefs from `0x00613350`, `0x00613400`, `0x00613640`, `0x006136f0` | separate successor family |

The target thunk starts have no direct code callers in MCP results. Runtime calls would arrive through COM/vtable dispatch, which is exactly the compiler-generated adjustor-thunk pattern.

## Documentation Evidence And IDA Status

| Document | Relevant evidence | Status |
| --- | --- | --- |
| `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md` | Already identifies Release adjustor thunks and vtable refs, but keeps reconstructable/emitter metadata | Needs metadata/body cleanup after callback |
| `by-class/BrowserWindow.md` | Lists `0x0046a0c0 Release` and `0x0047102c-0x004710cc` COM interface adjustor thunks | Should note UID000216 is non-emitting compiler glue |
| `by-file/Browser.md` | Current Browser source route and generated Browser.cpp context | Should stop treating UID000216 as an empty source emitter after metadata update |
| `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` | BrowserWindow vtable slots include refs to UID000216 | Evidence matches MCP; optional synchronization note |
| `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md` | Adjacent half-open predecessor range treats similar thunks as non-emitting | Supports same disposition for UID000216 |
| `by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md` | Ends exactly before UID000216; prior policy treats ABI thunk islands as non-emitting | Boundary and policy match |
| `by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md` | Records Browser COM GUID data used by BrowserWindow interface routing | Source-level support, not target emitter |

## Ranked Ownership Analysis

1. `BrowserWindow` class, UID00001B: strongest semantic owner. Both target thunks are in named BrowserWindow vtable slices and tail-jump to BrowserWindow Release.
2. `Browser` source-root/file, UID0000HV: practical generated source route today because BrowserWindow remains under the Browser source family. This route should own declarations/real methods, not synthetic target thunk bodies.
3. BrowserWindow vtable data range, UID0001OB: evidence owner for vtable slots and names only; not a code/source owner for UID000216.
4. Adjacent thunk cluster UID00033M / BrowserOle helper aggregate UID0000ZF: boundary and policy precedent only; neither owns UID000216 because the documented ranges are half-open and end at `0x004710b8`.
5. `CANONICAL_OWNER:NONE`: not recommended. Pure ABI glue is non-emitting, but the named BrowserWindow vtable slices provide enough semantic ownership to keep `CANONICAL_OWNER:00001B`.

## Source Placement

No C++ function body should be placed for UID000216.

The source-level representation belongs in:

- BrowserWindow COM/interface inheritance or equivalent source declaration.
- Canonical `BrowserWindow::Release` at `0x0046a0c0`.
- BrowserWindow support docs explaining that the compiler emits adjusted-this vtable thunks for COM interface views.

The current Browser source route can remain the source family until the project finalizes any `BrowserWindow.cpp` split. UID000216 itself should not emit into Browser.cpp as an empty marker.

## Range / Split / Padding / Reclassification Analysis

The exact target range `0x004710b8-0x004710cc` is well split:

- `0x004710b8-0x004710c2`: `sub_4710B8`, 10 bytes.
- `0x004710c2-0x004710cc`: `sub_4710C2`, 10 bytes.
- `0x004710cc-0x004710d0`: `0xcc` padding, outside the target body.
- `0x004710d0`: separate successor function.

The predecessor UID00033M ends at `0x004710b8`, so no range merge is recommended. The correct change is metadata reclassification from source-emitting reconstructable to non-emitting compiler-generated adjustor thunks.

## Negative Evidence Summary

- No recovered BrowserWindow UDT/type data was available from the narrow `type_query` result.
- No ordinary code callers directly target `0x004710b8` or `0x004710c2`.
- No local state change, reference-count storage, destructor path, QueryInterface logic, allocation, branch, or error path exists inside UID000216.
- No extra child function exists at `0x004710cc`; the following bytes are padding.
- No evidence supports a standalone handwritten C++ source body for either target function.

## First-Draft C++ Recommendation

Do not write first-draft C++ for UID000216.

Strict no-code proof:

- `sub_4710B8` contains only the stack argument adjustment by `0x10` and a tail jump to `sub_46A0C0`.
- `sub_4710C2` contains only the stack argument adjustment by `0x0c` and a tail jump to `sub_46A0C0`.
- `sub_46A0C0` is the canonical BrowserWindow Release target and returns `1`; UID000216 adds no Release logic of its own.
- The two thunk starts are reached only from BrowserWindow vtable data slots, not ordinary code callers.
- The adjusted-this deltas are compiler ABI artifacts of BrowserWindow COM/multiple-inheritance layout. The source-level obligation is the BrowserWindow COM base declaration and canonical Release method, not two handwritten thunk bodies.

Formal `RECONSTRUCTION_CPP CODE` insertion for UID000216: none. The target should instead be reclassified to `RECONSTRUCTABLE:FALSE`, with `EMITTER_UIDS` blank and the formal C++ header/block left blank.

If the project intentionally keeps this target reconstructable for coverage accounting, the only defensible output would be a formal no-code coverage comment. That is not the preferred recommendation because project precedent for adjacent thunk islands supports non-emitting metadata instead.

## Final Recommendation

Implement a report-backed target cleanup in a later supervisor-authorized callback:

- Reclassify UID000216 as non-emitting compiler-generated BrowserWindow Release adjustor tail thunks.
- Keep `CANONICAL_OWNER:00001B`.
- Change `RECONSTRUCTABLE` to `FALSE`.
- Clear `EMITTER_UIDS`.
- Keep `RECONSTRUCTION_CPP` blank.
- Remove stale legacy parent-field wording.
- Add the current MCP facts showing vtable-only reachability and exact thunk bytes.
- Synchronize support docs only enough to explain why no Browser.cpp code should be emitted for this range.

## Recommended Target Doc Changes

Recommended metadata after callback:

```yaml
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:00001B
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

Recommended target body updates:

- State that the range contains two exact 0xa-byte BrowserWindow Release adjustor tail thunks.
- Record MCP session `supervisor_recovery_20260705` evidence for `sub_4710B8`, `sub_4710C2`, `sub_46A0C0`, vtable refs, and padding.
- Replace legacy parent-field references with current canonical-owner / no-emitter language.
- Explain that BrowserWindow owns the source-level COM interface layout and Release method, while this exact range has no source-emitting C++ body.
- Preserve the exact disassembly and vtable-slot evidence already present, updating only stale wording and metadata.

## Recommended Support Doc Changes

Recommended later edits, if supervisor authorizes implementation:

- `by-class/BrowserWindow.md`: add a short note that UID000216 is class-owned semantic compiler glue, not a handwritten method body; source coverage is the COM inheritance/base layout and canonical Release.
- `by-file/Browser.md`: clarify that Browser.cpp should not carry UID000216 as an empty emitter once target metadata is cleaned up.
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`: optionally synchronize the current MCP vtable-slot facts for `0x00613290` and `0x006132dc`.
- `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md`: no required change; optional cross-note that the adjacent UID000216 follows the same non-emitting adjustor-thunk policy.

No manual generated tracker, generated Browser.cpp, manual coverage-report, validator-state, or lifecycle edits should be made.

## Score And Metadata Recommendation

Current target score: `85/90`.

Recommended score after target cleanup: `88/92`.

Reasoning:

- Completion can rise because the exact boundaries, vtable refs, function bytes, and no-code disposition are now MCP-confirmed.
- Confidence can rise because the direct xrefs are vtable-only and the thunk body pattern is unambiguous.
- Scores should not be pushed higher yet because exact final BrowserWindow COM base declaration/source split remains open at the support-doc/source level.

Recommended metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `88` |
| `CONFIDENCE` | `90` | `92` |
| `CANONICAL_OWNER` | `00001B` | `00001B` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `00001B` | blank |
| `RECONSTRUCTION_CPP` | blank | blank |

## Open Questions With Attempted Resolution

Open question: What is the exact BrowserWindow COM inheritance/base declaration?

Attempted resolution: MCP verified vtable slices, slot refs, thunk deltas, and lack of recovered BrowserWindow UDT data. The exact source declaration still belongs to BrowserWindow source reconstruction, but this does not block classifying UID000216 as non-emitting compiler glue.

Open question: Should BrowserWindow eventually split out of Browser.cpp?

Attempted resolution: Current docs still route BrowserWindow through the Browser source family. UID000216 does not force a split because it should not emit code in either file.

Open question: Should `CANONICAL_OWNER` be cleared because the target is compiler-generated?

Attempted resolution: No. `CANONICAL_OWNER:00001B` remains useful because both vtable slots are named BrowserWindow and the thunks tail-jump to BrowserWindow Release. The emission fields, not semantic ownership, are the incorrect part.

## Validator Results

Scoped validators were run after the supervisor-authorized implementation callback. No `execute_report`, lifecycle/archive command, dry-run/probing variant, registry lifecycle command, generated-file manual edit, or coverage-report manual edit was run.

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md` | `python .\tools\validator.py --mode file --file by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md --apply --queue-timeout 240` | `000000006735` | `2026-07-05T03:51:14-04:00` | 0 | 1 | Updated UID000216 completion `88`, confidence `92`, reconstructable `true -> false`, emitter `00001B -> blank`; generated refresh deferred. |
| `by-class/BrowserWindow.md` | `python .\tools\validator.py --mode file --file by-class/BrowserWindow.md --apply --queue-timeout 240` | `000000006737` | `2026-07-05T03:51:33-04:00` | 0 | 1 | Generated refresh deferred; projected stats updated. |
| `by-file/Browser.md` | `python .\tools\validator.py --mode file --file by-file/Browser.md --apply --queue-timeout 240` | `000000006738` | `2026-07-05T03:51:38-04:00` | 0 | 1 | Generated refresh deferred; existing support-doc diagnostics reported `missing_ref_uid: 15` for unrelated UID refs. |
| `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` | `python .\tools\validator.py --mode file --file by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md --apply --queue-timeout 240` | `000000006739` | `2026-07-05T03:51:47-04:00` | 0 | 1 | Generated refresh deferred; existing support-doc diagnostics reported `missing_ref_uid: 2` for UID000408 refs. |
| `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md` | `python .\tools\validator.py --mode file --file by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md --apply --queue-timeout 240` | `000000006746` | `2026-07-05T03:53:37-04:00` | 0 | 1 | Optional adjacent-boundary cross-note validator; generated refresh deferred. |

Generated-refresh checks:

- Queue status command `000000006747` at `2026-07-05T03:53:56-04:00` reported worker running, no queued jobs, no processing jobs, no queued generated refresh jobs, and no processing generated refresh jobs.
- `auto-generated/-ag-research-tracker.md` refreshed at command `000000006746` and records UID000216 as `88/92`, average `90.0`, reconstructable `false`, code count `0`.
- `auto-generated/-ag-memory-coverage.md` refreshed at command `000000006746` and records UID000216 as `not_reconstructable`, canonical owner `00001B`, no emitter.
- `auto-generated/NexusTK/browser/Browser.cpp` refreshed at command `000000006738` and no longer contains UID000216 or the `0x004710b8-0x004710cc` empty marker. Other unrelated empty markers remain.
- Validators reported projected stats updates and a UID000216 autogen registry update as validator-owned side effects.

## Changed Files

Manual edits made by B010:

- `tools/leaser/Agents/Agent-B010/research/000216-BrowserWindowReleaseAdjustorTailThunks-source-quality.md`
- `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md`
- `by-class/BrowserWindow.md`
- `by-file/Browser.md`
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
- `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md`

Validator-owned/generated side effects observed, not manually edited:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/browser/Browser.cpp`
- `project-level/-auto-completion-stats.md`
- Validator autogen registry updates reported by the scoped target validator.

No manual coverage reports, lifecycle/archive files, supervisor ledgers, generated files, or validator state files were edited by hand.

## Implementation Tracking Checklist

Report-repair checklist:

- [x] Confirmed the repaired artifact started from supervisor-audited hash `8E8E57C4A78F0F353896961306CC0F21F44DB77EBAFA230253B78E460D49728F`.
- [x] Replaced the generic claim ledger with claim IDs, confidence, evidence, exact destinations/exclusions, actions, and verification states.
- [x] Removed body-only C/C++ snippet text from the first-draft recommendation and replaced it with strict target-specific no-code proof.
- [x] Expanded this checklist into callback-verifiable work items linked to claim IDs and destination docs.
- [x] Did not edit by-* docs, generated files, coverage files, validator state, lifecycle files, or manual report locations during this Gate 1 repair.
- [x] Did not run validators or lifecycle commands during this Gate 1 repair.

Supervisor Gate 1 / callback entry:

- [x] Supervisor re-audited this exact report artifact and returned `GATE1_PASSED`.
- [x] Supervisor confirmed `Claim And Incorporation Ledger` rows CL-001 through CL-013 were destination-bound or explicitly excluded.
- [x] Supervisor confirmed the first-draft C++ section contained no C/C++ sample, illustrative body, or insertion text beyond the explicit no-code disposition.
- [x] Supervisor issued the UID000216 implementation callback naming the target/support docs and accepted disposition.

Implementation callback checklist:

| Item ID | Claim IDs | Destination | Required implementation | Callback verification state |
| --- | --- | --- | --- | --- |
| ITC-001 | CL-001, CL-007, CL-011 | `by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md` / header metadata | Set `COMPLETION:88`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:00001B`, set `RECONSTRUCTABLE:FALSE`, clear `EMITTER_UIDS`, clear `EMITTER_POSITION_OPTIONAL`, leave `RECONSTRUCTION_CPP` header/block blank | applied - target metadata/header matches accepted disposition and validator `000000006735` confirmed completion/confidence/reconstructable/emitter updates |
| ITC-002 | CL-002 | Target / Autogen Status, Assignment Gate, Item Summary | Remove legacy parent-field wording and replace with current canonical-owner/no-emitter wording | applied - target contains no legacy parent-field literal and uses canonical-owner/no-emitter language |
| ITC-003 | CL-003, CL-004 | Target / Raw Code, Range/Boundary, Positive Evidence | Preserve/add exact two-function split, deltas `0x10` and `0x0c`, tail jumps to `sub_46A0C0`, and `0xcc` padding at `0x004710cc` | applied - target no-code proof and evidence record two 0xa-byte thunks, deltas, tail jumps, and padding |
| ITC-004 | CL-004, CL-005, CL-006, CL-011 | Target / No-Code Proof or First-Draft C++ disposition | State no formal C++ insertion exists because the range is compiler ABI glue with no unique behavior; ensure no illustrative C/C++ body is added | applied - target remains blank formal C++ and no handwritten/illustrative body was added |
| ITC-005 | CL-005, CL-007, CL-010 | `by-class/BrowserWindow.md` / Release method, COM adjustor-thunk inventory, Open Questions | Note UID000216 is BrowserWindow semantic compiler glue; source responsibility is COM base layout plus canonical Release; keep exact COM layout as open if still unresolved | applied - BrowserWindow method/evidence/change notes now call UID000216 semantic compiler glue and retain COM layout/source split as open |
| ITC-006 | CL-008 | `by-file/Browser.md` / BrowserWindow source-root or empty-emitter family note | Clarify Browser remains current source-root route, but UID000216 should not emit a Browser.cpp body or empty marker after metadata refresh | applied - Browser file now states Browser remains the source-root route while UID000216 should not emit a Browser.cpp body or empty marker |
| ITC-007 | CL-006 | `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md` / BrowserWindow vtable entries | Preserve or synchronize slot facts `0x00613290 -> 0x004710c2` and `0x006132dc -> 0x004710b8` with vtable-only reachability | applied - vtable index table/evidence/change notes record both exact slot mappings and vtable-only reachability |
| ITC-008 | CL-003, CL-009 | Optional `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md` / adjacent boundary note | No required edit. If touched, only add an explicit cross-note that adjacent UID000216 follows the same non-emitting thunk policy and starts after the half-open predecessor range | applied - existing direct cross-note location was present, so the page was touched only to add non-emitting compiler-generated BrowserWindow Release thunk glue wording; validator `000000006746` passed |
| ITC-009 | CL-009, CL-010 | Target / Supporting Research and Open Questions | Label prior B001/B002 material as historical support; do not let old empty-emitter assumptions override current MCP no-emitter conclusion | applied - target current text supersedes old empty-emitter/reconstructable state with MCP-backed no-emitter classification while retaining historical change context |
| ITC-010 | CL-012 | Generated Browser.cpp, tracker, coverage reports, validator state, lifecycle files | Do not edit manually. Generated Browser.cpp empty marker and tracker/coverage rows are expected to refresh only through validator/project tooling after by-* metadata changes | applied - no manual generated/coverage/validator/lifecycle edits; generated files refreshed only through scoped validators |
| ITC-011 | CL-013 | Validator execution after callback | Run scoped validators only after authorized by-* edits. Minimum target validator plus validators for each support by-* doc actually edited | applied - validators `000000006735`, `000000006737`, `000000006738`, `000000006739`, and `000000006746` all exited `0` with `ok: 1` |
| ITC-012 | CL-001, CL-008, CL-012 | Generated-output freshness disposition | After validators, compare relevant generated headers/rows against returned validator command metadata if generated output matters. Supervisor owns any coverage/tracker disposition; B-agent must not manually edit generated rows or run `execute_report` | applied - queue idle at status `000000006747`; tracker and memory coverage refreshed to `000000006746`; Browser.cpp refreshed to `000000006738` and no longer contains UID000216 |
| ITC-013 | CL-001 through CL-013 | Final callback response | Report changed files, exact validators run, generated refresh state, remaining open COM-layout/source-split blockers, and `READY_FOR_SUPERVISOR_EXECUTE` only if callback work is complete and validators pass | applied - final response will report changed files, validators, generated freshness, lease cleanup, open blockers, and `READY_FOR_SUPERVISOR_EXECUTE` |

Lease checklist:

- [x] Leased initial edit batch as `B010`: target UID000216, `by-class/BrowserWindow.md`, `by-file/Browser.md`, and `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`.
- [x] Leased optional adjacent boundary file as `B010`: `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md`.
- [x] Release cleanup: optional adjacent lease released successfully; the first four leases had already expired before cleanup and `leaser.py` reported `Rejected[No active lease]`.
- [x] Current lease report recheck after cleanup shows no active B010 leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000006754","destination_path":"executed-b-agent-research/B010/000216-BrowserWindowReleaseAdjustorTailThunks-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/000216-BrowserWindowReleaseAdjustorTailThunks-source-quality.md","timestamp":"2026-07-05T04:00:32-04:00","uid":"000216"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
