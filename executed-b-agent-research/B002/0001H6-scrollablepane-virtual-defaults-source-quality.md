** TARGET-REPORT-UID:0001H6 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002-goal2-scrollablepane-virtual-defaults-source-quality-0001H6-20260617

## Target And Recommendation

Primary target: [UID:0001H6] `by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md`.

Recommended metadata:

```yaml
COMPLETION: 87
CONFIDENCE: 90
CANONICAL_OWNER: 0000CF
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: [0000CF]
RECONSTRUCTION_CPP: blank; do not populate formal C++ for this aggregate target
```

The current range and padding treatment are correct, but the direct owner/emitter should be `ScrollablePane` [UID:0000CF], not the source-file parent `ScrollBar` [UID:0000NF]. `ScrollBar` remains the source-file grouping/ancestor under `NexusTK/ui/core`, but the functions are class virtuals and destructor machinery for `ScrollablePane`. The target can move above the `85/85` source-quality gate because the destructor helper calls, child fields, vtable slots, default contracts, and generated-output caveats are now defensible from bytes, vtable data, and derived-class overrides. Formal C++ should still remain blank because this is an aggregate island that mixes compiler adjustor thunks, a scalar deleting destructor wrapper, and multiple source-authored virtual default bodies.

## Evidence Reviewed

- Target doc: `by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md`.
- Direct support: `by-class/ScrollablePane.md`, `by-file/ScrollBar.md`, `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`, `by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md`, `by-memory/0x00623d58-0x00624184.ScrollPaneReadOnlyData.md`.
- Boundary support: `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`, `by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md`, `by-memory/0x00565610-0x0056a373.SelfLookPane.md`, `by-memory/-ignored.md`, `by-memory/-coverage-report.md`.
- Derived virtual-slot evidence: `by-memory/0x0047f520-0x0047f6df.ChattingPaneScrollMetricVirtuals.md`, `by-memory/0x004f3f20-0x004f41ce.ListPaneScrollMetricVirtuals.md`, generated `simroot_v2/class_TextEditPane.cpp`, generated `simroot_v2/class_ListPane.cpp`, generated `simroot_v2/class_ScrollablePane.cpp`.
- Existing executed reports searched: no previous B002 report for [UID:0001H6] was found. B001's executed `0001GL-scrollablepane-core-source-split-audit.md` was used as a lead and independently rechecked against bytes/vtables.
- PE-aware binary evidence from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`.

## Range, Bytes, And Vtable Evidence

The exact code island is `0x005654ec-0x00565608`.

- `0x005654ec-0x005654f7`: secondary-base destructor adjustor thunk. Bytes subtract `0xa0` from `this` and jump to `0x00565510`.
- `0x005654f7-0x00565502`: tertiary-base destructor adjustor thunk. Bytes subtract `0xa4` from `this` and jump to `0x00565510`.
- `0x00565502-0x00565510`: `0xcc` alignment padding. Keep ignored padding row separate.
- `0x00565510-0x0056559a`: scalar deleting destructor wrapper. It writes `ScrollablePane` primary/secondary/tertiary vtable pointers, deletes the child pointers at `this+0xf8` and `this+0xfc` through virtual slot 0 with delete flag `1`, zeroes both fields, chains the `Pane` destructor/cleanup at `0x00544580`, then handles scalar/vector delete flags.
- `0x0056559a-0x005655a0`: local alignment padding inside the aggregate island before the first tiny default.
- `0x005655a0-0x005655a4`: `xor eax,eax; ret 4`, shared by two primary vtable slots.
- `0x005655b0-0x005655b4`: `xor eax,eax; ret 8`.
- `0x005655c0-0x005655d6`: takes an out pointer, writes two zero dwords, returns the out pointer, `ret 0x10`.
- `0x005655e0-0x005655f6`: takes an out pointer, writes two zero dwords, returns the out pointer, `ret 4`.
- `0x00565600-0x00565608`: returns `1`, `ret 4`.
- `0x00565608-0x00565610`: `0xcc` alignment padding before `SelfLookPane`; keep ignored padding row separate.

PE pointer/edge evidence:

- The two adjustor thunks are referenced by the secondary/tertiary `ScrollablePane` vtables at `0x00623e58` and `0x00623e88`; their only code edge is the jump into `0x00565510`.
- The scalar deleting destructor is the primary destructor slot at `0x00623de4`, with rel32 jumps from the two adjustor thunks.
- `0x005655a0` appears in two primary vtable slots: `+0x48` and `+0x4c`.
- `0x00565600` appears at primary slot `+0x50`.
- `0x005655b0` appears at primary slot `+0x54`.
- `0x005655e0` appears at primary slot `+0x58`.
- `0x005655c0` appears at primary slot `+0x5c`.

This confirms the exact child boundaries and rejects moving any of `0x005654ec-0x00565608` into `ScrollVolumePane` or `SelfLookPane`. The predecessor ends exactly at `0x005654ec`; the successor begins at `0x00565610`.

## Source Shape, Names, And Field Directions

The current target doc validates the destructor/default-virtual island concept, exact boundary, and compiler-thunk handling, but several current function labels are not source-quality:

- Reject current no-arg `GetContentWidth` and `GetContentHeight` labels. The bytes are `ret 4` and `ret 8`, and the vtable slots align with scroll-metric virtuals, not no-argument content-width/content-height methods.
- Reject current `IsScrollable` label for `0x00565600`. Primary vtable slot `+0x50` matches derived `GetPageSize`/visible-page-count overrides, and the function has one argument. Returning `1` is the default page size, not a boolean scrollability predicate for this primary slot.
- Reject generated/source-map end `0x00565607`; the executable and target docs show the function endpoint as `0x00565608`, followed by padding.

Best defensible default virtual mapping:

| Range | Vtable slot | Source-facing name direction | ABI behavior |
|---|---:|---|---|
| `0x005655a0-0x005655a4` | `+0x48` | `ScrollablePane::GetScrollRange(char axis)` | returns `0`, pops one argument |
| `0x005655a0-0x005655a4` | `+0x4c` | `ScrollablePane::GetScrollPosition(char axis)` | same shared zero body, pops one argument |
| `0x00565600-0x00565608` | `+0x50` | `ScrollablePane::GetPageSize(char axis)` | returns `1`, pops one argument |
| `0x005655b0-0x005655b4` | `+0x54` | `ScrollablePane::ConvertScrollUnit(char axis, short units)` | returns `0`, pops two arguments |
| `0x005655e0-0x005655f6` | `+0x58` | `ScrollablePane::GetContentSize(int* outSize)` | writes `{0,0}`, returns `outSize` |
| `0x005655c0-0x005655d6` | `+0x5c` | `ScrollablePane::ConvertScrollDelta(int* outDelta, char axis, short currentPos, short previousPos)` | writes `{0,0}`, returns `outDelta` |

Name confidence details:

- `GetScrollRange`, `GetPageSize`, `GetContentSize`, and `ConvertScrollDelta` are directly supported by `TextEditPane`, `ListPane`, and `ChattingPane` slot-equivalent overrides.
- Slot `+0x4c` has class-local names in derived pages (`GetScrollPosition`, `GetOverflowCount`, and a ChattingPane page-step/current-position helper). The base contract is a one-axis current position/secondary scroll metric returning zero. `GetScrollPosition(char axis)` is the best source-facing base name because it matches the clearest generated derived declaration and the core sync path's use of this slot as the current scroll position/default.
- Slot `+0x54` is a scroll-unit-to-pixel or scroll-unit conversion helper. `ConvertScrollUnit(char axis, short units)` is the best base name; `GetScrollOffset(axis, units)` should remain an accepted class-local alias for ListPane-style derived code, not the base name.

Owned fields and destructor semantics:

- `this+0xf8`: horizontal `ScrollPane*` / `m_pHorizontalScrollPane`. Constructor evidence creates the child with orientation argument `1`, and layout/update code uses it as the horizontal scrollbar.
- `this+0xfc`: vertical `ScrollPane*` / `m_pVerticalScrollPane`. Constructor evidence creates the child with orientation argument `0`.
- The scalar deleting destructor wrapper deletes `+0xf8` first, then `+0xfc`, through each child's deleting destructor with flag `1`, then zeroes both fields.
- The source-authored destructor should be documented as ordinary `ScrollablePane::~ScrollablePane()` ownership cleanup. The scalar deleting destructor and adjustor thunks are MSVC-generated binary artifacts and should not be written as source methods.
- Nearby core fields should continue to use the established directions from [UID:0001GL]: scrollbar offsets around `+0x100/+0x104`, scrollbar enabled/visible bytes around `+0x10c/+0x10d`, content/viewport rectangles at `+0x110/+0x120`.

## Ownership, Emission, And Support Updates

Recommended owner/emitter change:

- Set direct owner/emitter to [UID:0000CF] `ScrollablePane`.
- Keep [UID:0000NF] `ScrollBar` as source-file ancestor/grouping only.

Reasoning:

- The target is entirely `ScrollablePane` destructor and virtual-slot machinery.
- [UID:0001GL] `ScrollablePaneCore` already emits through [UID:0000CF].
- [UID:0003CL] `ScrollablePaneVtableData` already has [UID:0000CF] as direct parent.
- `tools/validator.ini` already associates this target with [UID:0000CF].
- The current generated route through `auto-generated/NexusTK/ui/core/ScrollBar.cpp` is a file-route artifact, not evidence that `ScrollBar` should be the direct owner.

Support docs to update:

- `by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md`: update metadata, owner/emitter, function table names/signatures, default-contract notes, stale generated-output caveat, and formal C++ policy.
- `by-class/ScrollablePane.md`: add the six-slot default mapping above and record that the destructor deletes horizontal `+0xf8` then vertical `+0xfc` child scroll panes before chaining `Pane`.
- `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`: replace any remaining uncertainty that this target's default virtuals are content-width/content-height/no-arg methods; link the core scroll-sync calls to the `+0x48..+0x5c` slot mapping.
- `by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md`: list the exact primary scroll-metric slot addresses and the secondary/tertiary destructor thunk entries.
- `by-file/ScrollBar.md`: note that [UID:0001H6] should direct-own through `ScrollablePane` even though it remains in the ScrollBar source-file grouping.
- Generated/source-tree notes: flag `simroot_v2/class_ScrollablePane.cpp` no-arg `GetContentWidth`/`GetContentHeight`/`IsScrollable` names and `.source_map.json` endpoint `0x00565607` as stale generated labels, not source evidence.

No separate padding row changes are needed for `0x00565502-0x00565510` or `0x00565608-0x00565610`; the existing ignored padding rows remain correct.

## Heuristic / Inference Reanalysis And Validation

Best defensible inferences:

- The target is a `ScrollablePane` class virtual/destructor island, not a `ScrollBar` class body. `ScrollBar` is the file-level owner only.
- The two leading functions are compiler-generated `this`-adjustor thunks for secondary/tertiary vtable destructor slots. Their only meaningful source expression is the class destructor declaration and multiple-inheritance layout.
- `0x00565510` is a scalar deleting destructor wrapper around source destructor ownership cleanup. The source destructor deletes the horizontal and vertical owned `ScrollPane` children and chains `Pane`; the binary wrapper handles delete flags and vtable restoration.
- The source-authored default virtuals are the six scroll-metric hooks at primary vtable slots `+0x48..+0x5c`, not content-width/content-height/no-argument methods.
- The base defaults define an empty-but-scrollable contract: range/current position zero, page size one, scroll-unit conversion zero, content size `{0,0}`, and scroll delta `{0,0}`.

Evidence checked:

- PE bytes for every function body, padding byte ranges, and ret-stack sizes.
- PE dword references in `.rdata` and rel32 edges from thunks to the scalar deleting destructor.
- `ScrollablePane` primary/secondary/tertiary vtable data at `0x00623de0-0x00623e90`.
- Derived `ChattingPane`, `ListPane`, and `TextEditPane` vtable-equivalent overrides for slots `+0x48..+0x5c`.
- `ScrollablePaneCore` constructor/destructor/update docs for child field directions and virtual-slot usage.
- Adjacent `ScrollVolumePane` and `SelfLookPane` boundaries.
- Generated `simroot_v2` output and source-map data, treated only as leads because several generated names are contradicted by ABI/vtable evidence.

Rejected alternatives:

- Keep [UID:0000NF] as direct owner/emitter: rejected because the methods are class virtual/destructor entries for [UID:0000CF], and all class/vtable/core evidence points there.
- Treat the leading thunks as source-authored methods: rejected because they only adjust `this` and jump to the deleting destructor, with references solely from secondary/tertiary vtables.
- Ignore or delete the thunks from the target range: rejected because they are real vtable entries and explain the secondary/tertiary destructor slots; document them as compiler artifacts within the aggregate.
- Keep `GetContentWidth`, `GetContentHeight`, or no-argument signatures: rejected by `ret 4`/`ret 8`, vtable slot positions, and derived override names.
- Keep `0x00565600` as `IsScrollable`: rejected by primary slot `+0x50`, one-argument ABI, and derived page-size/visible-count overrides. A scrollability predicate may exist elsewhere in related panes, but this body is the default page-size slot.
- Split the aggregate immediately for formal C++ emission: not required for source-quality scoring. A future split could separate source default virtual bodies from compiler wrappers, but the current aggregate is coherent as a late virtual/destructor island.

Validation of current docs:

- Validated: exact outer range, predecessor/successor boundary, padding at `0x00565502-0x00565510` and `0x00565608-0x00565610`, destructor/default-virtual island treatment, and the need to distinguish source destructor semantics from compiler wrappers.
- Contradicted: direct `ScrollBar` owner/emitter, generated no-arg/content names, generated `IsScrollable` label, and source-map endpoint `0x00565607`.

Score/source-placement/final-C++ impact:

- The resolved slot map and owner route justify raising the target from `82/88` to `87/90`.
- The target should remain reconstructable and emitting through [UID:0000CF] for coverage/source-placement purposes.
- The formal `RECONSTRUCTION_CPP` block should remain blank because a single aggregate C++ block would either encode compiler-only thunks/deleting destructor wrappers as source or omit part of the binary island. The correct source representation belongs in the class declaration and ordinary destructor/default virtual bodies, while MSVC regenerates the deleting destructor and adjustor thunks.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP CODE` block for [UID:0001H6].

Reason: this target is a mixed aggregate containing two compiler-generated adjustor thunks, one compiler-generated scalar deleting destructor wrapper, and several small source-authored default virtual implementations. A formal block for the whole range would be misleading: writing `ScalarDeletingDestructor` and the thunks as methods would overfit compiler artifacts, while writing only the source virtual defaults would not cover the documented range. If the supervisor later creates exact child targets or class-level source snippets, the source-facing declarations should express:

- ordinary `ScrollablePane::~ScrollablePane()` ownership cleanup for `m_pHorizontalScrollPane` and `m_pVerticalScrollPane`;
- `GetScrollRange(char axis)` default returning `0`;
- `GetScrollPosition(char axis)` default returning `0`;
- `GetPageSize(char axis)` default returning `1`;
- `ConvertScrollUnit(char axis, short units)` default returning `0`;
- `GetContentSize(int* outSize)` default writing `{0,0}`;
- `ConvertScrollDelta(int* outDelta, char axis, short currentPos, short previousPos)` default writing `{0,0}`.

Because this section explicitly says not to populate formal C++, no first-draft code block should be entered into the target file.

## Supervisor-Owned Coverage Row

Replace the existing [UID:0001H6] row in `by-memory/-coverage-report.md` where it currently appears between [UID:0002LD] and the ignored padding rows. Keep the two existing ignored padding rows unchanged.

Replacement row:

```md
    - [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md) 0x005654ec-0x00565608 | destructor/default virtual cluster | ScrollablePaneVirtualDefaults : reconstructable : 87% : strong : B002 source-quality audit reroutes the late ScrollablePane destructor/default island to direct class owner [UID:0000CF]; PE-aware bytes and vtable dwords confirm secondary/tertiary destructor adjustor thunks at 0x005654ec/0x005654f7, scalar deleting destructor 0x00565510, padding 0x00565502-0x00565510 and 0x00565608-0x00565610, six primary scroll-metric default slots (+0x48/+0x4c zero range/position, +0x50 page-size one, +0x54 unit conversion zero, +0x58 content-size {0,0}, +0x5c scroll-delta {0,0}), owned horizontal/vertical ScrollPane cleanup at +0xf8/+0xfc, generated-output stale no-arg/content/IsScrollable labels rejected, and formal C++ held blank because the aggregate mixes compiler thunks/deleting wrapper with source virtual defaults.
```

## Validation Commands

Suggested supervisor validation after applying doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001H6-scrollablepane-virtual-defaults-source-quality-removed.md](0001H6-scrollablepane-virtual-defaults-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files, Leases, And Blockers

- Changed file: `tools/leaser/Agents/Agent-B002/research/0001H6-scrollablepane-virtual-defaults-source-quality.md`.
- Leases used: none; this was an allowed B-agent research report edit.
- Blockers: none for supervisor execution. The only remaining source-quality limitation is exact original source naming for slots `+0x4c` and `+0x54`; the recommended names are high-confidence base-contract names from derived vtable evidence, but derived classes use class-local aliases. This does not block `87/90` because the ABI, slot semantics, and default behavior are resolved.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001H6-scrollablepane-virtual-defaults-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001H6"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001H6-scrollablepane-virtual-defaults-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001H6-scrollablepane-virtual-defaults-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001H6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
