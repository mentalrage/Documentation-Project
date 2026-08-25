** TARGET-REPORT-UID:00023P **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00023P] WordRefCountHelpers Current No-Owner Research

## Final Recommendation

Keep `00023P` unchanged as a reconstructable but currently non-emitting no-owner memory item:

```text
UID:00023P
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
```

No canonical owner, emitter route, split, merge, reclassification, IDA-safe name repair, or by-memory documentation edit is justified by the current evidence.

The range is source-shaped code and should remain `RECONSTRUCTABLE:TRUE`, but it has no proven source-use route. Under the current code-entry gate, C++ must stay blank because the item has blank `EMITTER_UIDS`; despite the 90 average score, it cannot surface to valid generated source without an emitter.

## Target And Scope

- Target: `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`
- UID: `00023P`
- Current generated state: `no-owner`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Current score: `COMPLETION:88`, `CONFIDENCE:92`
- Current category: reconstructable function cluster with no generated source route
- Current tracker source: Goal 2 no-owner memory sweep

This pass treats existing by-memory text and prior B-agent reports as leads only. The recommendation below is based on current generated rows, current project documentation, live IDA MCP evidence, and a local generated-source/simroot reference check.

## Evidence Standards Applied

The ownership test used here follows the current by-structure owner/emitter model:

- `CANONICAL_OWNER` requires source-quality semantic ownership, not adjacency.
- `EMITTER_UIDS` requires a proven generated output route, not just a plausible file family.
- Shared or helper code can remain `CANONICAL_OWNER:NONE` when no single source owner is defensible.
- Reconstructable source-shaped code may remain `RECONSTRUCTABLE:TRUE` even when owner/emitter routing is unresolved.
- C++ entry requires `RECONSTRUCTABLE:TRUE`, confirmed nonblank `EMITTER_UIDS` that surface to valid generated source without a dead end, and a sufficient score. This target fails the emitter requirement.

## Current Header State

The target page currently records:

```text
UID:00023P
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
```

The body describes three small 16-bit intrusive reference-count helpers:

- `0x00554640-0x0055464b`: modeled initializer, stores word count `1`, returns `this`.
- `0x00554650-0x00554654`: raw increment helper, `inc word ptr [ecx]; ret`.
- `0x00554660-0x00554675`: raw release helper, decrements word count and frees `ecx` through `sub_5C7526` when the signed count is not positive.

The target page already warns that no direct owner/emitter is proven and that a narrow utility family is only a best-if-forced hypothesis.

## Current Generated Coverage Rows

`auto-generated/-ag-memory-coverage.md` currently lists the main row as:

```markdown
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |
```

The no-owner/non-emitting section currently lists:

```markdown
| [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) | no-owner | `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md` |  |  |  |
```

These rows match the current evidence and do not need supervisor replacement.

## Live IDA MCP Evidence

IDA MCP was checked against `NexusTK.exe` from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; the local MD5 is `4247E04E20B65D6414C7238AA8FF5515`.

Function recognition and range boundaries:

- `0x00554640` is recognized as `sub_554640`, size `0x0b`.
- `0x00554650` is not recognized as a function start by IDA, but the bytes form a complete raw helper.
- `0x00554660` is not recognized as a function start by IDA, but the bytes form a complete raw helper.
- `0x00554635` is not a function start; the previous documented function ends there.
- `0x00554680` is `sub_554680`, the next recognized function after the target and padding.

Bytes around the range confirm exact padding-separated boundaries:

```text
0x00554635-0x0055463f: cc cc cc cc cc cc cc cc cc cc cc
0x00554640-0x0055464a: b8 01 00 00 00 66 89 01 8b c1 c3
0x0055464b-0x0055464f: cc cc cc cc cc
0x00554650-0x00554653: 66 ff 01 c3
0x00554654-0x0055465f: cc cc cc cc cc cc cc cc cc cc cc cc
0x00554660-0x00554674: 66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3
0x00554675-0x0055467f: cc cc cc cc cc cc cc cc cc cc cc
```

Hex-Rays decompilation for `0x00554640`:

```c
_WORD *__thiscall sub_554640(_WORD *this)
{
  *this = 1;
  return this;
}
```

Hex-Rays decompilation for `sub_5C7526`:

```c
void __cdecl sub_5C7526(void *Block)
{
  j_j___free_base(Block);
}
```

The release helper tail is therefore a direct free-wrapper route, not a higher-level object owner:

```text
dec word ptr [ecx]
cmp word ptr [ecx], 0
jg  short return
push 2
push ecx
call sub_5C7526
add esp, 8
ret
```

## Xref And Signature Evidence

Current IDA MCP xref checks show:

- `xrefs_to(0x00554640)`: zero.
- `xrefs_to(0x00554650)`: zero.
- `xrefs_to(0x00554660)`: zero.
- `xrefs_to(0x00554675)`: zero.
- `find_xref_signatures` for all three helper starts and the end address returned no xref signatures.

Current byte/signature searches show the helper island is unique in the loaded image:

- Initializer bytes `b8 01 00 00 00 66 89 01 8b c1 c3`: one match at `0x00554640`.
- Increment bytes `66 ff 01 c3`: one match at `0x00554650`.
- Release bytes `66 ff 09 66 83 39 00 7f 0b 6a 02 51 e8 b5 2e 07 00 83 c4 08 c3`: one match at `0x00554660`.
- Full island signature including internal padding is unique at `0x00554640`.
- Absolute VA dword searches for `0x00554640`, `0x00554650`, `0x00554660`, and `0x00554675` found no pointer table entries.
- RVA dword searches for the same targets found no pointer table entries.
- `push`-immediate searches for those target addresses found no source-use call/data route.

Name/string metadata checks:

- No local names were found in `0x00554600-0x00554700`.
- No `refcount`, `reference count`, `intrusive`, `WordRef`, or related PDB/source strings were found by IDA MCP string queries.

This is strong evidence for a coherent helper island, but not for a canonical source owner or generated emitter.

## Generated-Source And Documentation Reference Check

A local `rg` check for `WordRefCount`, `0x00554640`, `0x00554650`, `0x00554660`, and decimal-address variants under `source-3/project-documentation/auto-generated` and `source-3/simroot_v2` found only generated coverage-table rows. It did not find a generated source file, source output route, or existing simroot reference that could act as an emitter.

The current `by-memory/-coverage-report.md` row is consistent with the target page: it treats the island as a unique three-helper 16-bit intrusive refcount cluster, rejects several adjacent or superficial owners, and leaves the best-if-forced utility family unassigned.

## Neighbor And Candidate Owner Analysis

### Preceding Reconnect/CopyWindow Region

The preceding documented region `0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md` ends before this target. Its exact child `0x00554550-0x00554635.ConnectionReconnectDialogCleanupAndDestructorThunks.md` has its own dialog cleanup/destructor/vtable evidence and stops at `0x00554635`.

The current bytes show `0x00554635-0x0055463f` is all `0xcc` padding before `sub_554640`. There are no current xrefs from the reconnect/copy-window region to `0x00554640`, `0x00554650`, or `0x00554660`.

Conclusion: adjacency to the reconnect/copy-window cluster is weak evidence and is rejected as an owner/emitter route.

### Following Region/Motion Geometry Island

The following region `0x00554680-0x00554b38.RegionAndMotionRect.md` starts after `0x00554675-0x0055467f` padding. Current IDA recognizes `0x00554680` as `sub_554680`, and xrefs to `0x00554680` are broad while xrefs to this target are zero.

Region/Motion child docs have rectangle, vtable, and geometry-helper evidence. This target instead uses a single word at `this` and direct free-wrapper release. No field layout, caller, or table connects it to Region or Motion.

Conclusion: Region/Motion is rejected as an owner/emitter route.

### StringBase/StringUtil/RefCounted String Candidates

The behavior superficially resembles a reference counter, but the known string families use different layouts and idioms: string buffer headers, wider counters, interlocked/string sentinel logic, and string-specific allocator paths. This target has only a 16-bit word at object offset `0`, raw `ecx` helpers, and direct free-wrapper release.

Conclusion: StringBase/StringUtil/RefCountedStringBuffer ownership is rejected as behavior-only and layout-incompatible.

### LinkedList, PoolAllocator, LObject, CRT, And MiniMap Candidates

LinkedList and PoolAllocator candidates are rejected because the target has no list links, sentinels, pool block state, critical section state, or allocator table route.

LObject is rejected because the target has no vptr, RTTI use, or object shell pattern.

The CRT/free-wrapper candidate is rejected because `sub_5C7526` is only a callee. A broad free wrapper does not own every helper that eventually frees memory.

MiniMapVersionManager is useful only as a negative control. Current IDA decompilation of `0x00456480` and `0x00457480` shows their cleanup/destructor loops also pass delete mode `2` to `sub_5C7526`, but those functions have MiniMap-specific vtable/global/list evidence. They do not xref or table-reference `0x00554640`, `0x00554650`, or `0x00554660`.

Conclusion: these are rejected as owners/emitter routes.

### Best-If-Forced Utility Family

The narrowest plausible source family is something like `WordRefCountHelpers`, `IntrusiveWordRefCount`, or another tiny utility implementation for a 16-bit intrusive count. That hypothesis fits the behavior and the three-helper grouping, but it is still synthetic:

- No caller is known.
- No file/class/type metadata is known.
- No pointer table or import/export route is known.
- No source output path is known.
- No neighboring documented owner has a hard reference to the island.

Conclusion: this hypothesis is worth preserving in prose, but it does not clear `CANONICAL_OWNER` or `EMITTER_UIDS`.

## Split, Merge, Reclassify, And Rename Analysis

Split:

- Rejected. The three code snippets are separated by padding but form one coherent helper family: initializer, increment, release/free.
- Splitting would create three even smaller no-owner/non-emitting docs and would not improve source routing.

Merge:

- Rejected. The preceding and following ranges are separated by `0xcc` padding and have different evidence families.
- The preceding region has dialog cleanup/destructor evidence; the following region has Region/Motion geometry evidence.

Reclassify:

- Rejected. The target is source-shaped code, not arbitrary bytes, data, padding, or mixed resources.
- It should remain `RECONSTRUCTABLE:TRUE` while owner/emitter evidence remains unresolved.

Rename:

- No IDA-safe name repair is recommended. `WordRefCountHelpers` is descriptive and appropriately cautious.
- A stronger name such as `IntrusiveWordRefCount` would still be inferred from behavior only and would not improve ownership.

## Code-Entry And Score Implications

Before score:

```text
COMPLETION:88
CONFIDENCE:92
Average:90
```

After this pass:

```text
COMPLETION:88
CONFIDENCE:92
Average:90
```

No score change is recommended. The current score accurately reflects high confidence in the range behavior and low confidence in source ownership/routing.

C++ should remain blank. The active code-entry gate is not met because `EMITTER_UIDS` is blank and no valid generated-source output route is proven.

## Exact Required Edits

No by-memory, by-file, by-class, by-type, or generated documentation edits are required from this pass.

The target metadata should remain:

```text
UID:00023P
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
```

The target should retain blank:

```text
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_SOURCE:
RECONSTRUCTION:
RECONSTRUCTION_NOTES:
RECONSTRUCTION_CPP:
```

## Supervisor-Owned Shared-Report Text

No `by-memory/-coverage-report.md` edit is required. Do not edit it directly.

If the supervisor wants a provenance refresh only, the existing row can be replaced with this equivalent current-pass row:

```markdown
    - [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md) 0x00554640-0x00554675 | function cluster | WordRefCountHelpers : reconstructable : 88% : strong : B001 current no-owner recheck reconfirmed a coherent, unique three-helper 16-bit intrusive refcount island with modeled initializer `0x00554640-0x0055464b`, raw increment helper `0x00554650-0x00554654`, raw release/free helper `0x00554660-0x00554675`, exact surrounding/internal `0xcc` padding, zero xrefs/xref signatures to all three helper starts and the range end, zero absolute-VA/RVA/push-immediate references, unique exact helper signatures, unique full-range signature, no local names in `0x00554600-0x00554700`, no refcount/intrusive/source metadata strings, and no generated-source/simroot route. ReconnectDialog/CopyWindow predecessor, Region/Motion successor, StringBase/StringUtil/refcounted-string, LinkedList, PoolAllocator, LObject, MiniMapVersionManager, and CRT/free-wrapper ownership are rejected; a narrow utility family such as `WordRefCountHelpers` remains the best-if-forced source hypothesis but does not clear owner or emitter assignment without caller, table, type, source, or object-file evidence.
```

This is optional only; the current shared row is already substantively correct.

## Validation

No validator was run because this pass does not edit any by-memory, by-file, by-class, by-type, or shared coverage documentation. No dry runs were used.

Current generated-source/simroot reference check:

_Executable command block removed from the research report; preserved in [00023P-WordRefCountHelpers-current-no-owner-research-removed.md](00023P-WordRefCountHelpers-current-no-owner-research-removed.md)._

## Lease State

No leases were acquired. This pass created only this final report in Agent-B001's own research folder and did not edit shared by-* documentation.

## Changed Files

- `tools/leaser/Agents/Agent-B001/research/00023P-WordRefCountHelpers-current-no-owner-research.md`

## Confidence

Recommendation confidence: high for preserving the current no-owner/non-emitting state.

Completion impact: no coverage score movement. This pass strengthens the audit trail for why `00023P` remains a high-confidence reconstructable helper island with no current canonical owner or emitter route.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00023P-WordRefCountHelpers-current-no-owner-research.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00023P"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00023P-WordRefCountHelpers-current-no-owner-research-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00023P-WordRefCountHelpers-current-no-owner-research.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00023P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
