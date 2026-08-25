** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023P WordRefCountHelpers Ownership Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](../../../../../by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) as one coherent reconstructable helper island, not split.
- Final disposition now applied to the page: `RECONSTRUCTABLE:TRUE`, `COMPLETION:87`, `CONFIDENCE:91`, blank `AUTOGEN_PARENT_UID`, blank C++.
- Required supervisor action: do not assign this row to `ReconnectDialog`, `CopyWindow`, `Region`, `Motion`, `LObject`, `StringBase`, or `StringUtil`. The best actionable owner inference is a new narrow utility owner such as `WordRefCountHelpers` / `IntrusiveWordRefCount` under `NexusTK/util/`; create/validate that owner first, then assign this by-memory row to the new owner UID if the supervisor accepts that source model.
- Confidence: high for the binary facts and the rejection of existing candidate parents; medium for the exact original source filename because the current binary has no caller, pointer, source metadata, or type name for this island.

This is not a recommendation to do nothing. It is an executable structural recommendation: either create the narrow utility owner and route the row there, or keep the row parent-blank until that owner exists. Existing owners are weaker than the narrow new-owner inference.

## Exact by-memory/-coverage-report.md Replacement Row

Replace only the current `00023P` row between the existing padding row `0x00554635-0x00554640` and the existing padding row `0x00554675-0x00554680`. Do not edit `by-memory/-coverage-report.md` directly from B001.

```markdown
    - [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) 0x00554640-0x00554675 | function cluster | WordRefCountHelpers : reconstructable : 87% : strong : B001-050 live IDA found a coherent, unique three-helper 16-bit intrusive refcount island with exact init/increment/release bytes, all surrounding `0xcc` padding, zero code/data xrefs, zero loaded-segment pointer entries, zero direct rel32 calls/jumps, no `refcount`/`referencecount` metadata, and no direct existing owner. Adjacent ReconnectDialog/CopyWindow/Region/Motion and thematic LObject/StringBase/StringUtil owners are rejected; supervisor action is to create or accept a narrow utility owner such as `WordRefCountHelpers` before setting `AUTOGEN_PARENT_UID`.
```

## Supporting Research

## Target

- Target UID: `00023P`
- Target path: `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`
- Source row: `Supervisor_notes.md`, B001-050, status `reviewed-85-but-ownership-unknown-under-review`
- Prior state: A002 Batch 178 raised `82/88 -> 85/90`, parent blank.
- Current state after B001-050: `85/90 -> 87/91`, parent blank, no split children created.

## Executive Recommendation

The assigned range does not need a split. It contains three related function-shaped helpers separated by alignment padding:

| Range | Role | Status |
| --- | --- | --- |
| `0x00554640-0x0055464b` | initializes `word [this] = 1` and returns `this` | IDA-modeled function |
| `0x00554650-0x00554654` | increments `word [this]` and returns | raw function-shaped bytes |
| `0x00554660-0x00554675` | decrements `word [this]`, frees `this` when count is not positive | raw function-shaped bytes |

The correct current representation is a source-authored/reconstructable helper island with no existing parent. The best source placement is a new narrow `util` owner, not a forced attachment to one of the neighboring or string/base owners. Parent attachment should wait until the new owner page exists and clears `85/85`.

## Supervisor Active Recheck

The supervisor assigned this target because A002 found no callers, data refs, pointer-table entries, vtable refs, or adjacent-source ownership evidence proving a direct owner. B001 rechecked that same hard evidence and expanded it to:

- loaded-segment dword pointer scans,
- direct `call`/`jmp` rel32 scans,
- exact byte-pattern uniqueness,
- `sub_5C7526` caller-shape comparison,
- existing documentation and proposed source tree review,
- StringBase/LObject/Region/Reconnect/CopyWindow metadata/name/string checks.

No source-bearing child below the target remains unresearched. No split was created because the item is homogeneous: all real bytes are the same word-refcount helper family.

## Inference Research Guidance Check

`inference_research.md` warns that adjacency alone is weak and that a final source owner may need to be inferred probabilistically when debug/source metadata is absent. Here, address adjacency is rejected as ownership proof. The recommendation separates:

- IDA fact: exact bytes, boundaries, no refs, unique pattern hits.
- Documentation evidence: surrounding pages and source-tree notes.
- Inference: a narrow utility owner is more defensible than adjacent feature ownership.

Existing docs were treated as leads, not authority. The StringBase/LObject split is especially important because recovered output previously mixed true `LObject` and ref-counted string behavior.

## Evidence Standards Used

Evidence collected or rechecked:

- IDA MCP `tools/list`, `py_eval`, and `decompile`.
- IDA APIs for `CodeRefsTo`, `DataRefsTo`, function boundaries, bytes, segment scans, direct rel32 calls/jumps, and byte patterns.
- Existing docs for `ReconnectDialog`, `CopyWindow`, `Region`, `Motion`, `LObject`, `StringBase`, `StringUtil`, `LinkedList`, and `MiniMapVersionManager`.
- Negative evidence is treated as meaningful only after multiple independent scans agreed.

## IDA MCP Facts

- IDB path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Segment: `.text`, executable.
- Previous modeled function: `0x005545f0-0x00554635`.
- Current modeled function: `0x00554640-0x0055464b`, `sub_554640`.
- Raw helpers: `0x00554650-0x00554654` and `0x00554660-0x00554675`.
- Next modeled function: `0x00554680-0x005546e1`, `sub_554680`.
- Bytes from `0x00554635-0x00554680`: `0xcc` padding, init helper, padding, increment helper, padding, release helper, trailing `0xcc` padding.
- Incoming xrefs: zero code refs and zero data refs to `0x00554640`, `0x00554650`, and `0x00554660`.
- Loaded-segment pointer hits: zero dword pointer hits for all three helper starts.
- Direct rel32 hits: zero direct `call`/`jmp` encodings to all three helper starts.
- Exact pattern hits:
  - initializer sequence: one hit at `0x00554640`,
  - `inc word ptr [ecx]; retn`: one hit at `0x00554650`,
  - release sequence: one hit at `0x00554660`,
  - `push 2; push ecx; call sub_5C7526; add esp, 8; retn`: one hit at `0x00554669`.
- `sub_5C7526` has 617 direct code refs in the IDB. Only three use the `push 2; push <arg>; call sub_5C7526` shape: two `MiniMapVersionManager` destructor payload frees and this raw helper.
- IDA name/string scans found no `refcount` or `referencecount` symbols/strings.
- `StringBase`/`mystr` RTTI/name evidence exists elsewhere, but none of it references the target starts or the target byte pattern.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00554640` | no code refs, no data refs, no pointer hits, no direct rel32 hits | no direct owner recovered |
| `0x00554650` | no code refs, no data refs, no pointer hits, no direct rel32 hits | raw increment helper is not statically referenced |
| `0x00554660` | no code refs, no data refs, no pointer hits, no direct rel32 hits | raw release helper is not statically referenced |
| `0x0055466c -> 0x005c7526` | outgoing free-wrapper call | only external code edge from the island |

## Documentation Evidence And IDA Status

- [UID:0001FT] `ConnectionClosedReconnectDialogs` ends at `0x00554635` and is a mixed non-emitting reconnect/copy-window map. IDA confirms separation by padding and no references from that range to the target.
- [UID:0001FW] `RegionAndMotionRect` begins at `0x00554680`. IDA confirms separation by padding and the following owner uses `Region`/`Motion` rectangle/vtable state, not a word counter.
- [UID:0000OA] `StringBase` is the correct owner for the large ref-counted string-buffer family, but its buffer header uses 32-bit interlocked refcounts at `data - 0x0c`, sentinels, and pools. IDA contradicts using it as the direct parent for this 16-bit object-head counter.
- [UID:0000KV] / [UID:00007D] `LObject` is a vtable/runtime-class shell. IDA contradicts direct `LObject` ownership because this target has no vtable/runtime-class state or refs.
- `proposed-source-tree.md` already has `util/` owners for `LObject`, `StringBase`, `StringUtil`, `LinkedList`, and pool/container utilities. It does not currently model a word-refcount utility, which is why the owner should be created/accepted before assignment.

## Ranked Ownership Analysis

### 1. New narrow `util/WordRefCountHelpers` / `IntrusiveWordRefCount`

- Evidence for: the three helper bodies form a complete init/addref/release helper family; all exact patterns are unique; no existing parent has positive xrefs; the behavior is generic utility lifetime code.
- Evidence against: no source filename, type name, PDB, linker map, caller, or table entry proves the literal original name.
- Decision: best actionable source-placement inference. Create or accept this narrow owner before assigning `00023P`.

### 2. `StringBase` / `StringUtil`

- Evidence for: broad string docs include ref-counted buffer semantics, and the target is also a refcount helper in abstract terms.
- Evidence against: StringBase uses 32-bit `InterlockedDecrement`, a 12-byte header, sentinel pointers, and pool/heap selection. The target uses a 16-bit counter at `this`, direct heap free, no sentinel, and no StringBase metadata/xrefs.
- Decision: rejected as direct parent.

### 3. `LObject`

- Evidence for: utility/base-object area has recovered-owner pollution around string code.
- Evidence against: true `LObject` is vtable/runtime-class code; target has no vtable write, no runtime-class refs, and no relation to `LObject` RTTI.
- Decision: rejected as direct parent.

### 4. `Region` / `Motion`

- Evidence for: target physically precedes the Region/Motion rectangle island.
- Evidence against: only adjacency supports it. IDA shows padding separation, no refs, and incompatible following object layout.
- Decision: rejected.

### 5. `ReconnectDialog` / `ConnectionClosedDialog` / `CopyWindow`

- Evidence for: target physically follows the reconnect/copy-window aggregate.
- Evidence against: only adjacency supports it. IDA shows padding separation, no refs, and unrelated UI/vtable/global patterns.
- Decision: rejected.

### 6. MiniMapVersionManager / LinkedList / free-wrapper families

- Evidence for: two MiniMapVersionManager destructor bodies share the `push 2; push <arg>; call sub_5C7526` call shape.
- Evidence against: decompilation shows those free list-node payload strings and object/list storage inside MiniMapVersionManager teardown; they do not use word counters or target starts.
- Decision: useful negative control only; rejected.

## Negative Evidence Summary

Checked and rejected:

- incoming code/data xrefs,
- loaded-segment dword pointer entries,
- direct rel32 `call`/`jmp` encodings,
- exact duplicate helper byte patterns,
- `refcount`/`referencecount` symbols/strings,
- StringBase/mystr metadata tie-ins,
- adjacent owner boundaries,
- free-wrapper call-shape ownership.

The remaining uncertainty is not a missing easy lead. The current binary evidence is exhausted enough to reject existing parents and recommend a narrow utility owner.

## Final Recommendation

Applied:

- Updated [UID:00023P] from `85/90` to `87/91`.
- Kept `RECONSTRUCTABLE:TRUE`.
- Kept `AUTOGEN_PARENT_UID` blank.
- Kept C++ blank.
- Did not split the range.
- Did not edit `by-memory/-coverage-report.md`.

Recommended supervisor action:

- Apply the exact replacement row above to `by-memory/-coverage-report.md`.
- Create or accept a new narrow source owner, preferably `by-file/WordRefCountHelpers.md` projected to `NexusTK/util/`, if the project wants this row assigned.
- After that owner exists and clears `85/85`, set `00023P` `AUTOGEN_PARENT_UID` to the new owner UID and validate the target page again.
- Do not route this helper through existing adjacent or string/base parents.

## Confidence

- Binary range/bytes confidence: `96/100`.
- No-reference/no-pointer/no-direct-call confidence: `94/100`.
- Existing-parent rejection confidence: `88/100`.
- New narrow utility-owner recommendation confidence: `76/100`.
- Literal original filename/name confidence: `35/100`.

## Validator Results

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

- `python tools\validator.py --mode file --file by-memory\0x00554640-0x00554675.WordRefCountHelpers.md --apply --queue-timeout 120`

Result:

- exit code `0`
- `ok: 1`
- `completion_update 00023P ... 87`
- `confidence_update 00023P ... 91`
- `autogen_report_noop ... auto-generated/-ag-memory-coverage.md unchanged`

Validator also printed many existing `autogen_cpp_noop` lines and one `autogen_parent_has_no_code 00000D by-class/Application.md emitting children only`; these were not failures from the edited target page.

## Changed Files

- Modified: [UID:00023P] `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`
- Created: `tools/leaser/Agents/Agent-B001/research/00023P-WordRefCountHelpers.md`
- Direct coverage-report edits: none
- Validator-managed side effects reported: `project-level/-auto-completion-stats.md` projected path completion section updated; validator registry rebuilt; generated `-ag-*` coverage reports unchanged.
- Split children created: none
- Leases used: B001 leased `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` before editing and released it after validation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00023P-WordRefCountHelpers.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
