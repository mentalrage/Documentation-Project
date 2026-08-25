** TARGET-REPORT-UID:0001GG **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001GG SharedBooleanVirtualStubs Fresh No-Owner Pass

## Finalized Recommendation

Keep `UID:0001GG` unchanged:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:` blank
- `RECONSTRUCTABLE:TRUE`
- `COMPLETION:86`
- `CONFIDENCE:89`
- `RECONSTRUCTION_CPP:` blank

This item should stay a reconstructable no-owner/non-emitting memory page. The two tiny functions at `0x0055c1b0` and `0x0055c1c0` are real boolean-return virtual bodies, but the current evidence shows they are compiler-folded physical bodies shared by unrelated source families. They are referenced by both the effecter vtable family and the system-message vtables, plus additional runtime/read-only tables. No single canonical source owner is defensible, and no current emitter route can emit one source snippet without inventing an artificial helper or duplicating a physical address into unrelated files.

No split, merge, reclassification, IDA-safe name repair, or by-* documentation edit is recommended.

## Target And Scope

- Target: `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md`
- UID: `0001GG`
- Current generated source: `auto-generated/-ag-memory-coverage.md`
- Current generated state: no-owner, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`
- Prior report reviewed as historical evidence only: `tools/leaser/Agents/Agent-B003/research/executed/0001GG-SharedBooleanVirtualStubs-current-no-owner-research.md`

This pass independently rechecked the current by-memory page, current generated rows, related by-file/by-type/by-class documentation, raw PE bytes, and live IDA MCP evidence.

## Metadata Before And After

Before:

```text
UID:0001GG
COMPLETION:86
CONFIDENCE:89
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

After recommendation:

```text
UID:0001GG
COMPLETION:86
CONFIDENCE:89
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

Score impact: no score change. The current score is high enough to describe the stubs and their shared routing, but not enough to assign a source owner or source emitter.

## Evidence Standards Applied

- By-structure owner/emitter rules were applied: `CANONICAL_OWNER` must be the direct semantic source owner, while `EMITTER_UIDS` must be real source-output routes, not just files that contain a reference.
- Existing documentation and prior reports were treated as leads only.
- IDA names, xrefs, and raw PE pointer scans were cross-checked so IDA metadata did not become the only evidence.
- The current code-entry gate was applied: source C++ requires `RECONSTRUCTABLE:TRUE`, confirmed nonblank `EMITTER_UIDS` surfacing to valid generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`.

The combined score is `(86 + 89) / 2 = 87.5`, but the target fails the confirmed nonblank emitter requirement. C++ entry remains blocked.

## Current Documentation Evidence

The target page currently documents:

- `0x0055c1b0-0x0055c1b3`: `mov al, 1; ret`, a true-return stub.
- `0x0055c1c0-0x0055c1c3`: `xor al, al; ret`, a false-return stub.
- Padding/alignment between and around the two stubs.
- Shared use by system-message classes and effecter classes.
- Blank owner and emitters because the page describes folded physical code rather than a single recoverable source declaration.

Related docs checked:

- `by-file/SystemMessagePanes.md` (`UID:0000OE`) owns the system-message pane file root and references this boolean-stub page from Header/Footer/ColorString vtable evidence.
- `by-class/HeaderSystemMessage.md` (`UID:000061`) documents vtable slots using `0x0055c1b0` and `0x0055c1c0`.
- `by-class/FooterSystemMessage.md` (`UID:00005D`) documents the opposite true/false slot ordering.
- `by-class/ColorStringSystemMessage.md` (`UID:000030`) documents false-slot reuse.
- `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md` (`UID:00026M`) is a non-reconstructable mixed `.rdata` split index that records the system-message vtable children and links `0001GG`.
- `by-file/Effects.md` (`UID:0000IZ`) owns the effecter runtime source file root.
- `by-type/by-vtable/ScreenEffecterVtableFamily.md` (`UID:0001YO`) and `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md` (`UID:0002OR`) document many effecter vtable slots pointing at these same two stub bodies.
- `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md` (`UID:0001GE`) places `0001GG` inside the effecter runtime address cluster but explicitly notes cross-family reuse.
- `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md` (`UID:000246`) is a useful contrast: that default true helper is system-message-only and can be owned/emitted by `SystemMessagePanes`, unlike `0001GG`.

The docs are internally consistent with a shared physical-code page. They do not prove a single source file owner for `0001GG`.

## Live IDA MCP Evidence

IDA MCP session checked:

```text
session: a001_goal2_class_batch
input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
```

Function lookup:

```text
0x0055c1a0 -> inside sub_55C180, size 0x24
0x0055c1b0 -> sub_55C1B0, size 0x3
0x0055c1b3 -> no function
0x0055c1c0 -> sub_55C1C0, size 0x3
0x0055c1c3 -> no function
0x0055c1d0 -> sub_55C1D0, size 0x2f
```

Bytes at `0x0055c1a0`:

```text
5d c2 04 00
cc cc cc cc cc cc cc cc cc cc cc cc
b0 01 c3
cc cc cc cc cc cc cc cc cc cc cc cc cc
32 c0 c3
cc cc cc cc cc cc cc cc cc cc cc cc cc
56 8b f1 8b 06 8b 00 ff d0 ...
```

Disassembly and decompilation:

```text
0x0055c1b0: mov al, 1; retn
decompile: char sub_55C1B0() { return 1; }

0x0055c1c0: xor al, al; retn
decompile: char sub_55C1C0() { return 0; }
```

The start/end boundaries are exact. There are no functions or xrefs at `0x0055c1b3` or `0x0055c1c3`; those are the byte after each stub, not independent code/data starts.

### IDA Xrefs To The True Stub

`xrefs_to 0x0055c1b0` returned 25 IDA xrefs:

- one code xref at `0x005c8489` in `?pre_c_initialization@@YAHXZ`
- effecter `.rdata` vtable entries including `0x006235c4`, `0x006235e8`, `0x006235ec`, `0x00623694`, `0x00623698`, `0x00623740`, `0x00623744`, `0x006237ec`, `0x006237f0`, `0x00623898`, `0x0062389c`, `0x0062394c`, `0x006239f4`, `0x00623a9c`, `0x00623b44`, `0x00623be4`, `0x00623c08`, `0x00623c2c`, `0x00623c58`, `0x00623cf8`
- system-message `.rdata` entries `0x0062d6b8` and `0x0062d6e0`
- additional `.rdata` entries `0x00637548` and `0x0063754c`

### IDA Xrefs To The False Stub

`xrefs_to 0x0055c1c0` returned 32 IDA xrefs, all data xrefs:

- effecter `.rdata` entries including `0x006235a4`, `0x006235a8`, `0x006235ac`, `0x006235c8`, `0x006235cc`, `0x006235f0`, `0x0062369c`, `0x00623748`, `0x006237f4`, `0x006238a0`, `0x00623944`, `0x00623948`, `0x006239ec`, `0x006239f0`, `0x00623a94`, `0x00623a98`, `0x00623b3c`, `0x00623b40`, `0x00623be8`, `0x00623bec`, `0x00623c0c`, `0x00623c10`, `0x00623c30`, `0x00623c34`, `0x00623c50`, `0x00623c54`, `0x00623cfc`, `0x00623d00`
- system-message `.rdata` entries `0x0062d6bc`, `0x0062d6dc`, `0x0062d700`, `0x0062d704`

### Named Table Evidence

IDA names around the effecter `.rdata` block include:

```text
0x006235a4 ??_7ScreenEffecter@@6B@
0x006235c4 ??_7PixelEffecter@@6B@
0x006235e8 ??_7OverlayEffecter@@6B@
0x00623694 ??_7OverlayImageEffecter@@6B@
0x00623740 ??_7OverlayFrameImageEffecter@@6B@
0x006237ec ??_7OverlayImageOnPointEffecter@@6B@
0x00623898 ??_7OverlayMovingImageEffecter@@6B@
0x00623944 ??_7FilterEffecter@@6B@
0x006239ec ??_7SolidColorFilterEffecter@@6B@
0x00623a94 ??_7CloudFilterEffecter@@6B@
0x00623b3c ??_7StaticCloudFilterEffecter@@6B@
0x00623be4 ??_7EarthquakeEffecter@@6B@
0x00623c08 ??_7XWaveEffecter@@6B@
0x00623c2c ??_7YFlipEffecter@@6B@
0x00623c50 ??_7WaterFilterEffecter@@6B@
0x00623cf8 ??_7LakeEffecter@@6B@
```

IDA names around the system-message `.rdata` block include:

```text
0x0062d6a0 ??_7SystemMessagePane@@6B@_1
0x0062d6ac ??_7HeaderSystemMessage@@6B@
0x0062d6d0 ??_7FooterSystemMessage@@6B@
0x0062d6f4 ??_7ColorStringSystemMessage@@6B@
0x0062d718 ??_7ForcedInformMessageDialog@@6B@
```

Representative pointer values:

```text
0x006235a4, 0x006235a8, 0x006235ac -> 0x0055c1c0
0x006235c4 -> 0x0055c1b0
0x006235c8, 0x006235cc -> 0x0055c1c0
0x00623cf8 -> 0x0055c1b0
0x00623cfc -> 0x0055c1c0
0x0062d6b8 -> 0x0055c1b0
0x0062d6bc -> 0x0055c1c0
0x0062d6dc -> 0x0055c1c0
0x0062d6e0 -> 0x0055c1b0
0x0062d700 -> 0x0055c1c0
0x0062d704 -> 0x0055c1c0
```

This proves cross-family use: effecter classes and system-message classes both point directly at the same physical stub functions.

## PE / Raw Evidence

Raw PE scan used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

PE facts:

```text
imagebase: 0x400000
.text  rva=0x001000 raw=0x000400 size=0x20b600
.rdata rva=0x20d000 raw=0x20ba00 size=0x5f200
.data  rva=0x26d000 raw=0x26ac00 size=0x00d800
.rsrc  rva=0x29d000 raw=0x278400 size=0x015e00
```

Raw bytes at `0x0055c1a0` match IDA:

```text
5d c2 04 00 cc cc cc cc cc cc cc cc cc cc cc cc
b0 01 c3 cc cc cc cc cc cc cc cc cc cc cc cc cc
32 c0 c3 cc cc cc cc cc cc cc cc cc cc cc cc cc
56 8b f1 8b 06 8b 00 ff d0 ...
```

Absolute VA pointer scan:

```text
0x0055c1b0: 28 VA32 hits, all in .rdata
0x0055c1b3: 0 VA32 hits
0x0055c1c0: 32 VA32 hits, all in .rdata
0x0055c1c3: 0 VA32 hits
0x0055c1d0: 16 VA32 hits, all in .rdata
```

RVA pointer scan:

```text
0x0055c1b0: 0 RVA32 hits
0x0055c1b3: 0 RVA32 hits
0x0055c1c0: 0 RVA32 hits
0x0055c1c3: 0 RVA32 hits
0x0055c1d0: 0 RVA32 hits
```

Branch-target scan:

```text
0x0055c1b0: one E8 rel32 target at VA 0x005c8489 in .text
0x0055c1b3: 0 branch targets
0x0055c1c0: 0 branch targets
0x0055c1c3: 0 branch targets
0x0055c1d0: 0 branch targets
```

The raw scan independently confirms the stubs are physical function-pointer targets, mostly from `.rdata`, and that no pointer targets the byte after either 3-byte function. The extra direct call to the true stub is not enough to assign a game source owner because it is in CRT/static-initialization code and does not represent the owning source declaration for the shared virtual bodies.

## Function / Child Inventory

`0001GG` is a compact physical-code audit page, not a source family:

| Address range | Function | Evidence | Recommendation |
| --- | --- | --- | --- |
| `0x0055c1b0-0x0055c1b3` | `sub_55C1B0` | `mov al,1; ret`, returns true, 25 IDA xrefs and 28 raw VA pointer hits | Keep as part of shared-stub page |
| `0x0055c1b3-0x0055c1c0` | alignment | `0xcc` padding, no endpoint xrefs | Keep as padding context |
| `0x0055c1c0-0x0055c1c3` | `sub_55C1C0` | `xor al,al; ret`, returns false, 32 IDA/raw VA pointer hits | Keep as part of shared-stub page |
| `0x0055c1c3-0x0055c1d0` | alignment | `0xcc` padding, no endpoint xrefs | Keep as padding context |

No child split is recommended. Splitting the true and false stubs would produce two smaller ownerless physical-code pages and would not create a source owner or emitter route.

## Owner And Emitter Analysis

### Candidate: `SystemMessagePanes.md` / `UID:0000OE`

Rejected as canonical owner. The system-message docs prove real source-use through `HeaderSystemMessage`, `FooterSystemMessage`, and `ColorStringSystemMessage` vtables, but they do not cover the many effecter vtable references at `0x006235a4-0x00623d04`. Assigning `0000OE` would incorrectly claim a social/UI system-message file owns physical functions also used by render effecter classes.

Rejected as emitter for this memory page. SystemMessagePanes can emit per-class virtual method bodies for system-message classes when those methods are reconstructed, but it cannot emit a single `0001GG` source item without also accounting for effecter use.

### Candidate: `Effects.md` / `UID:0000IZ`

Rejected as canonical owner. Effects has the larger contiguous effecter table cluster and many direct vtable entries to both stubs, but the system-message vtables at `0x0062d6b8`, `0x0062d6bc`, `0x0062d6dc`, `0x0062d6e0`, `0x0062d700`, and `0x0062d704` are a separate semantic source family. Effecter adjacency is not ownership.

Rejected as emitter for this memory page. Effects can emit per-class effecter virtual overrides where needed, but that does not make the shared physical bodies an Effects source helper.

### Candidate: multiple emitters `0000IZ,0000OE`

Rejected for the current page. Multiple emitters are appropriate for shared source-use data such as pooled literals when the same memory object is legitimately referenced from multiple output routes. `0001GG` is executable code produced by identical/folded trivial virtual bodies, not a source-authored global data object. Emitting one shared helper into both files would invent a helper that the evidence does not show, and emitting the same function body twice under one memory UID would confuse physical address ownership with source method recovery.

The correct future source recovery route is likely per-class virtual method reconstruction in the owning class/file docs, not an emitter on this physical shared-stub page.

### Candidate: canonical owner under `ScreenEffecterVtableFamily` / `UID:0001YO`

Rejected. `0001YO` owns the effecter vtable family and its compiler-emitted table data, but `0001GG` is executable code reused by non-effecter vtables. A vtable-family owner would hide the system-message references and the CRT/runtime direct call.

### Candidate: new global helper source file

Rejected. The stubs have no evidence of a source-named helper such as `AlwaysTrue()` or `AlwaysFalse()`. The pattern is better explained by compiler folding of trivial virtual overrides. Creating a source helper would reduce fidelity.

### Candidate: reclassify to `RECONSTRUCTABLE:FALSE`

Rejected. The behavior is source-meaningful and easy to reconstruct as trivial boolean-return virtual bodies. The problem is not irrecoverability; it is that the physical folded address is not a single source-output route.

## Split / Merge / Rename / IDA Repair Analysis

- Split: not recommended. True and false functions are exact 3-byte bodies separated by alignment, but both halves have the same routing problem.
- Merge: not recommended. The predecessor `sub_55C180` ends before the padding, and successor `sub_55C1D0` starts at `0x0055c1d0` with separate effecter vtable references. Merging would hide real function boundaries.
- Reclassification: not recommended. Keep reconstructable because source behavior is recoverable, but keep non-emitting until source routes are represented as per-class methods.
- IDA-safe names: no required repair. Existing `sub_55C1B0` and `sub_55C1C0` are generic but accurate enough for a no-owner physical-stub page. A misleading semantic name such as `SystemMessageAlwaysTrue` or `EffecterAlwaysFalse` would overfit one reference family.
- Range: no repair needed. Endpoints `0x0055c1b3` and `0x0055c1c3` have zero pointer and branch hits; current range covers exactly the two 3-byte stubs plus relevant alignment context.

## Exact Required Edits

No by-* documentation edits are required.

No direct edit to `by-memory/-coverage-report.md` is required.

No `auto-generated/-ag-memory-coverage.md` source edit is required. The current generated rows should remain:

```markdown
| [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) | no-owner | `NONE` |  |  | no |  | `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md` |  |
```

```markdown
| [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) | no-owner | `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md` |  |  |  |
```

No replacement row/block is needed for supervisor application.

## C++ Entry Eligibility

Not eligible.

Reason:

- `RECONSTRUCTABLE:TRUE`: yes
- confirmed nonblank `EMITTER_UIDS`: no
- source route without dead-end: no
- `(COMPLETION + CONFIDENCE) / 2 > 85`: yes, 87.5

The active gate is not satisfied because the emitter route is blank by design. Do not add `RECONSTRUCTION_CPP` to this memory page.

## Validation

No validator was run because this pass only creates this Agent-B003 research report and recommends no by-* documentation changes. No dry runs were used.

## Lease State

No by-* files were edited. No lease was required for this Agent-B003 research report. `current_leases.md` showed no active leases during the pass.

## Changed Files

- `tools/leaser/Agents/Agent-B003/research/0001GG-SharedBooleanVirtualStubs-fresh-no-owner-pass.md`

## Confidence

Recommendation confidence: high.

The direct function bytes, IDA function boundaries, raw VA pointer scan, named vtable regions, and related docs all agree that this is a shared physical-code artifact used by multiple unrelated source families. The only unresolved future work is per-class method reconstruction in the owning class/file docs, not ownership or emitter assignment for this memory page.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001GG-SharedBooleanVirtualStubs-fresh-no-owner-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001GG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
