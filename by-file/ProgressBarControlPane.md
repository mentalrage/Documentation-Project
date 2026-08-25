*** UID:0000MT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ProgressBarControlPane

## Status

- Confidence: very strong for class role, source placement, constructor/draw ownership, vtable-backed class identity, child helper boundaries, signed-short field roles, source-facing helper names, inherited invalidation semantics, and the corrected class-at-file-scope emission route. Raw helper no-direct-xref status remains a documented liveness caveat rather than a no-code condition.
- Proposed module: `NexusTK/ui/controls/ProgressBarControlPane.cpp`
- Final C++ status: the source declaration and exact child method bodies emit through the class page and child by-memory pages. The class formal closes with `};` before `[[CHILDREN]]`, so generated qualified method definitions are placed at file scope. This file is the source module parent for the class, not a duplicate body emitter.
- Main address ranges: `0x00494a90-0x00494b4b`, `0x00494b50-0x00494b77`, `0x00494c80-0x00494daa`, and `0x00494db0-0x00494eb0`
- Vtables: [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md) at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`

## File Role

`ProgressBarControlPane` is the reusable progress-bar UI control. It derives from [UID:0000IG][ControlPane](by-file/ControlPane.md), uses control type `22`, semantically interprets inherited protected `m_rangeStart` at `+0xf8`, `m_rangeCurrent` at `+0xfa`, and `m_rangeEnd` at `+0xfc` as minimum/current/maximum progress, and paints a filled segment, empty segment, and frame. It adds no derived storage beyond the proven `0x108` complete ControlPane size.

The only confirmed direct constructor caller in IDA during this pass is [UID:0000MH][PatchPane](by-file/PatchPane.md), which creates the progress bar for the `Auto Patch` dialog. That caller makes this a shared UI control consumed by patching code, not patch-module ownership.

`NexusTK/ui/controls/ProgressBarControlPane.cpp` emits the class declaration from [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md) followed by qualified child method definitions for the constructor, `SetMinValue`, `SetMaxValue`, `SetCurrentValue`, `AddCurrentValue`, and `DrawProgressBar`. The duplicate aggregate pages remain non-emitting inventories and must not produce a second copy of these methods.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue)` | [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) | Constructor; calls `ControlPane::ControlPane` with type `22`, installs generated progress vtables, clamps initial min/max to `0..30000`, synchronizes the current value, resets current to zero, and invalidates after state changes. |
| `DrawProgressBar()` | [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) | Paint virtual; computes the split from inherited `m_rangeStart/m_rangeCurrent/m_rangeEnd` over inherited `m_visibleBounds`, fills active/inactive rectangles through slot `0x0069b3fc`, and draws frame color `128`. |
| `SetMinValue(short minValue)` | [UID:000115][0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter](by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md) | Exact 87-byte retained source helper. It clamps a signed value to `0..30000`, returns with no side effects when unchanged, raises inherited `m_rangeCurrent +0xfa` when below the new minimum, writes inherited `m_rangeStart +0xf8`, and calls `InvalidateRect(&m_visibleBounds)` zero, one, or two times according to the path. |
| `SetMaxValue(short maxValue)` | [UID:000117][0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter](by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md) | Exact 91-byte symmetric retained source helper. It clamps a signed value to `0..30000`, returns when unchanged, lowers inherited `m_rangeCurrent +0xfa` when above the new maximum, writes inherited `m_rangeEnd +0xfc`, and calls `InvalidateRect(&m_visibleBounds)` zero, one, or two times. |
| `SetCurrentValue(short value)` | [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) | Modeled 39-byte function that writes inherited signed-short `m_rangeCurrent +0xfa` and tail-dispatches `InvalidateRect(&m_visibleBounds)` only when changed; PatchPane packet responses call it for percent progress updates and reset-to-zero. |
| `AddCurrentValue(short delta)` | [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) | Exact unique 46-byte retained source method, SHA-256 `D13A5B1018EA66A5752E53501A6F8E1EDFE0A50C53BA804A54BFA89AF328AA7C`, adds the signed delta to inherited `m_rangeCurrent +0xfa`, truncates modulo 16 bits, returns without side effects when the stored word is unchanged, and otherwise writes current before one `InvalidateRect(&m_visibleBounds)`. No external entry/pointer route survives; target score is `93/94`. |

## Field Map And Source Policy

| Offset | Source-facing name | Role |
| --- | --- | --- |
| inherited complete-object `+0x44` | `m_visibleBounds` / `RectBounds` | `GrafPort::m_visibleBounds`, passed to inherited `Pane::InvalidateRect` and copied by draw. The older local alias `m_bounds` is superseded. |
| inherited `+0x70` | `m_drawMode` | Draw/fill mode byte cleared before `DrawProgressBar` fill calls; exact original inherited field name remains unproven. |
| inherited `+0xf8` | `ControlPane::m_rangeStart` | Physical lower range field; ProgressBar semantic minimum. |
| inherited `+0xfa` | `ControlPane::m_rangeCurrent` | Physical current range field; ProgressBar semantic current value. |
| inherited `+0xfc` | `ControlPane::m_rangeEnd` | Physical upper range field; ProgressBar semantic maximum. |

The raw/no-xref caveat is retained for `SetMinValue`, `SetMaxValue`, and `AddCurrentValue`: current live MCP and PE route scans found no external instruction xref and no VA, RVA, or raw-file-offset pointer route to `0x00494a90`, `0x00494af0`, or `0x00494db0`. For `AddCurrentValue`, every decoded instruction head and external decoded branch/call target was also checked, the exact 46-byte body occurs once, and an apparent raw branch into the body was rejected as an operand byte inside the modeled draw function. This caveat caps historical liveness certainty but is not a no-code proof because the bodies are source-shaped thiscall mutators over the coherent `ProgressBarControlPane` field family, not compiler thunks, destructors, RTTI, or runtime/library glue.

## Ownership Decision

Keep this as its own `ui/controls/ProgressBarControlPane.cpp` module. It is too specific to fold into [UID:0000IG][ControlPane](by-file/ControlPane.md), but it is also not part of the button/choice-control family despite sitting in gaps around [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) and `RadioGroupControlPane` code.

`PatchPane` is only a consumer: `PatchPane::PatchPane` allocates `0x108` bytes and calls the constructor at `0x005472d7` with `bounds, 0, 100`; `PatchPanePacketResponseHandler` calls `SetCurrentValue` at `0x005476ed` for computed percent progress and `0x0054783f` for reset to zero. Do not migrate progress-bar implementation into PatchPane. `ControlPane` owns the base constructor, inherited invalidation slot `0x00617b54 -> 0x00544800`, neighboring state virtuals, and the physical protected range triplet at `+0xf8/+0xfa/+0xfc`; ProgressBar contributes semantic min/current/max use and methods, not duplicate storage. `SurfaceRenderCallbackTable`, `GrafPort`, duplicate aggregate pages, and the vtable-data page are dependencies or generated data, not source owners.

The inherited primary-vtable slot at cell `0x00617b54` contains `0x00544800`, documented by the Pane family as `Pane::InvalidateRect(const RectBounds *)`. The helper bodies form the argument with `lea ..., [this+0x44]`; current PaneLayout/GrafPort documentation resolves that complete-object offset as inherited `GrafPort::m_visibleBounds`. The historical `Invalidate` and `m_bounds` spellings were descriptive local aliases and are not retained in current formal source.

## Evidence Notes

- IDA MCP confirms real functions at `0x00494c80-0x00494daa` and `0x00494de0-0x00494eb0`.
- IDA MCP reports the only direct constructor caller as `0x005472d7` inside `PatchPane::PatchPane`.
- IDA MCP `xrefs_to` shows the draw routine referenced from the `ProgressBarControlPane` vtable area at `0x00617b78`.
- 2026-05-26 IDA MCP vtable pass confirms three class vtable bases at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`, installed by constructor stores at `0x00494cc5`, `0x00494ccb`, and `0x00494cd5`; current metadata reports `vtable_count: 0`.
- IDA MCP reports `0x00494a90`, `0x00494af0`, and `0x00494db0` as `Not a function`, but raw disassembly shows valid function-shaped code with prologues/returns and progress-field updates.
- Live IDA currently models the constructor, current setter, and draw virtual as functions. The two range setters and `AddCurrentValue` remain exact retained unmodeled source bodies; accepted descriptive names route source output through their exact child pages.
- 2026-05-26 recheck: IDA MCP still reports the three helper starts as `Not a function` and reports no direct xrefs to them. Keep them documented as projected private `ProgressBarControlPane` helper bytes; do not add them to ignored ranges because the bytes operate on progress-bar fields and remain plausible project code.
- 2026-06-01 IDA MCP byte review confirms the corrected range-setter aggregate boundary: `0x00494a90-0x00494ae7` and `0x00494af0-0x00494b4b` are complete helper bodies, while `0x00494ae7-0x00494af0` and `0x00494b4b-0x00494b50` are `0xcc` alignment.
- Historical 2026-06-03 cross-documentation review established this file as the stable source parent while exact helper children still had no emitted C++ bodies. That no-body state is superseded: [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md) now emits the class declaration here, exact source-bearing child pages emit six qualified definitions, [UID:0002OL][0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData](by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md) remains compiler-data evidence only, and duplicate aggregates remain non-emitting.
- 2026-06-05 live IDA refresh confirms the constructor is modeled at `0x00494c80` with size `0x12a`, the draw virtual is modeled at `0x00494de0` with size `0xd0`, and helper starts `0x00494a90`, `0x00494af0`, and `0x00494db0` remain unmodeled function-shaped code.
- 2026-06-05 `callers` reports the constructor call at `0x005472d7` in the PatchPane constructor and no ordinary direct callers for the draw virtual; `xrefs_to` reports no references to the three helper starts and the expected draw vtable data reference at `0x00617b78`.
- 2026-06-05 byte reads reconfirm `0x00494ae7-0x00494af0`, `0x00494b4b-0x00494b50`, and `0x00494dde-0x00494de0` are alignment gaps, and `0x00617b78` stores the draw virtual pointer `0x00494de0`.
- 2026-06-08 Batch 113 IDA MCP recheck reconfirms the source-root ownership evidence: raw helper starts `0x00494a90`, `0x00494af0`, and `0x00494db0` still have no IDA function objects or direct xrefs; the constructor remains `0x00494c80-0x00494daa` with the PatchPane constructor call at `0x005472d7`; the draw virtual remains `0x00494de0-0x00494eb0` with vtable data xref `0x00617b78`; and byte windows preserve the same helper bodies plus alignment gaps.
- 2026-06-10 B001-018 IDA MCP audit reconfirms the update/draw grouping: [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) is an unmodeled/no-xref 46-byte current-value helper, [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) is the modeled draw virtual with vtable data xref `0x00617b78`, and aggregate [UID:00011B][0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw](by-memory/0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw.md) is a non-emitting duplicate inventory, not a separate source owner.
- 2026-06-13 B002 split repair confirms [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) is a modeled progress current-value setter, not a `ControlPane`, `ButtonControlPane`, or `RadioGroupControlPane` helper. IDA reports two direct PatchPane progress-update callers, no vtable/data refs, and a write to the same `+0xfa` current field consumed by the constructor, current-value adder, and draw virtual.
- 2026-07-23 B003 UID00011A reanalysis confirms exact target SHA-256 `D13A5B1018EA66A5752E53501A6F8E1EDFE0A50C53BA804A54BFA89AF328AA7C`, unique full-body occurrence, complete instruction/ABI behavior, exhaustive no-external-entry/no-VA-RVA-raw-pointer route, signed modulo-16 addition, inherited source names, retained-source classification, and `93/94` target score.

## 2026-07-23 B002 Source-Quality Reanalysis

- Live IDA MCP session `9b0396a3` independently rederived the raw setter family. `0x00494a90-0x00494ae7` is an exact 87-byte body, SHA256 `492B0F418A63322765FED4BC638EC5F0C508C298A006820C1A41D40DB7358FFA`, RVA `0x00094a90`, raw offset `0x00093e90`, followed by nine `0xCC` bytes. `0x00494af0-0x00494b4b` is an exact 91-byte body, SHA256 `97E860E2BD72C33445F80E40C704E7DB7B8F1B8583D9AB2547639294CAFC882C`, RVA `0x00094af0`, raw offset `0x00093ef0`, followed by five `0xCC` bytes.
- Both raw setters use signed-short comparisons and the exact ceiling `30000`. `SetMinValue` has zero invalidations when unchanged, one when only the minimum changes, and two when it first raises current and then stores the minimum. `SetMaxValue` is symmetric and first lowers current when required. Collapsing either changed path to one invalidation would not reproduce the original call count.
- Every decoded target and sibling instruction was checked for inbound references. No external code/data xref, vtable cell, VA pointer, RVA pointer, or raw-offset pointer reaches either body or an alternate interior entry. This supports a retained unreferenced source-method classification; it does not justify dropping behavior-exact formal C++.
- The modeled `SetCurrentValue` at `0x00494b50` retains direct PatchPane calls at `0x005476ed` and `0x0054783f`; constructor `0x00494c80` retains caller `0x005472d7`. Together with the constructor and draw routine, those live routes establish one min/current/max source API even though the raw min/max/add helpers have no surviving static callers.
- [UID:000116][0x00494a90-0x00494b4b.ProgressBarRangeSetters](by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md) remains a non-reconstructable, non-emitting duplicate inventory. Exact child pages emit the two methods; aggregate emission would duplicate source.
- The source assembly route is class UID0000AW -> file UID0000MT. UID0000AW closes the class before `[[CHILDREN]]`; UID0003N1 is registered as an emitted child. Compiler/vtable data pages and duplicate aggregates remain non-emitting.
- Scores move from `88/90` to `90/92`. The increase reflects exact helper hashes/mappings, complete signed machine-flow and invalidation counts, exhaustive negative-route checks, current inherited API/layout names, corrected file-scope emission, and the restored current-setter route. The score remains below `95` because original lexical spellings and the historical header/source physical split do not survive.

## 2026-07-23 B003 Inherited-Storage Source Contract

- [UID:000038][ControlPane](by-class/ControlPane.md) `ControlPane` proves exact complete-object size `0x108` with protected range fields at `+0xf8/+0xfa/+0xfc`; PatchPane allocates exactly `0x108` for ProgressBarControlPane. The derived class therefore cannot physically redeclare `m_minValue/m_currentValue/m_maxValue`.
- The source module now assembles one storage-free `ProgressBarControlPane` declaration followed at file scope by exactly six qualified definitions: constructor, `SetMinValue`, `SetMaxValue`, `SetCurrentValue`, `AddCurrentValue`, and `DrawProgressBar`.
- All source methods use inherited `m_rangeStart/m_rangeCurrent/m_rangeEnd`, inherited `GrafPort::m_visibleBounds`, and `Pane::InvalidateRect`. Historical derived value aliases, `m_bounds`, generic `Invalidate`, raw vtable syntax, vptr/SEH scaffolding, and compiler data remain excluded from current source.
- The exact methods preserve their own machine behavior: zero/one/two invalidation paths for the min/max setters, direct no-clamp current setter, constructor mutation/reset order, 16-bit add/truncate semantics, and draw split/color/callback/frame order.
- Duplicate range/update aggregates and ProgressBar vtable/RTTI pages remain evidence-only and non-emitting; PatchPane remains a caller/consumer rather than source owner.
- Completion/confidence are `91/93`. Remaining uncertainty is limited to original lexical/access/header-split provenance, not executable behavior, physical layout, source ownership, or generated assembly order.

## 2026-07-23 B003 UID00011A Source-File Synchronization

`ProgressBarControlPane.cpp` remains the exact source root for [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md). The source unit keeps one storage-free `ProgressBarControlPane` declaration followed by six qualified child definitions; `AddCurrentValue` is one of those definitions and must not be duplicated by aggregate [UID:00011B][0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw](by-memory/0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw.md).

### Exact AddCurrentValue Evidence

- Range `[0x00494db0,0x00494dde)`, 46 bytes, RVA `0x00094db0`, raw offset `0x000941b0`.
- SHA-256 `D13A5B1018EA66A5752E53501A6F8E1EDFE0A50C53BA804A54BFA89AF328AA7C`.
- Six-byte `0xcc` prepad, two-byte `0xcc` postpad, then modeled `DrawProgressBar` at `0x00494de0`.
- Exact body occurs once in live MCP and independent whole-file scans.
- No IDA function object, start xref, caller, external alternate instruction entry, decoded external branch/call target, or VA/RVA/raw pointer route survives.
- The body reads inherited `m_rangeCurrent`, performs signed-short source addition with low-16-bit truncation, compares after truncation, returns unchanged with no side effects, and otherwise writes current before one inherited virtual invalidation.
- Primary slot `+0x20`, cell `0x00617b54 -> 0x00544800`, is `Pane::InvalidateRect`; `this+0x44` is inherited `GrafPort::m_visibleBounds`.

The source body remains:

```cpp
void ProgressBarControlPane::AddCurrentValue(short delta)
{
    short value = static_cast<short>(m_rangeCurrent + delta);
    if (m_rangeCurrent == value)
        return;

    m_rangeCurrent = value;
    InvalidateRect(&m_visibleBounds);
}
```

This code preserves target-MSVC integral promotion, modulo-`2^16` conversion, equality, mutation, and invalidation order without decompiler syntax. `AddCurrentValue`/`delta` are the strongest human API names. `IncrementCurrentValue`, `AddValue`, `SetCurrentValue`, `Step`, `AdvanceProgress`, and `AddProgress` are rejected as less accurate. Public access is the strongest family inference. Raw `sub_494DB0`, `_WORD`, direct vtable syntax, derived `m_currentValue`, `m_bounds`, and generic `Invalidate` remain historical evidence only.

### Source Ownership And Non-Emission Boundaries

- Keep class owner [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md), file owner [UID:0000MT], and target emitter UID0000AW.
- `ControlPane`, `Pane`, and `GrafPort` own inherited storage/helper dependencies, not the ProgressBar API.
- `PatchPane` is a constructor/current-setter consumer only.
- UID00011B remains ownerless, non-reconstructable, non-emitting, and blank-formal.
- Compiler vtable/RTTI/deleting-destructor/adjustor-thunk pages remain non-handwritten source.
- No split, merge, new source root, class layout, child ordering, IDA database, or direct generated-file edit is required.

File score remains `91/93`. The exact adder closure improves its child detail but does not remove file-level lexical/access/header-split uncertainty or justify a source-root score change.

## Cross-References

- [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md)
- [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md)
- [UID:000116][0x00494a90-0x00494b4b.ProgressBarRangeSetters](by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md)
- [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md)
- [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md)
- [UID:00011B][0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw](by-memory/0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000MH][PatchPane](by-file/PatchPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Summary/evidence: the page documents class role, proposed contents, ownership decision, IDA/vtable evidence, projected private helpers, constructor caller, and cross-references; confidence remains capped by private helper names and raw non-function helper treatment.
- 2026-06-01: Filled validator projected reconstruction path and corrected the range-setter aggregate reference.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and UID `000116` still pointed at the stale `0x00494b48` filename.
  - After: projected path is `NexusTK/ui/controls/`, and UID `000116` points at `0x00494a90-0x00494b4b.ProgressBarRangeSetters`.
  - Evidence: proposed source placement already identified a reusable UI control module; IDA MCP byte review proved the aggregate end is `0x00494b4b`, not `0x00494b48`.
- 2026-06-03 parent-threshold consistency pass:
  - Before: confidence remained `76` even though the class and exact helper children were already attached into this file's autogen tree.
  - After: completion/confidence are `84/80`, with the confidence raised only to the attachment threshold and final C++ still withheld at that time; this historical no-code state is superseded by the 2026-06-19 B005 implementation below.
  - Evidence: the exact constructor, draw virtual, vtable data, range-setter aggregate, update/draw aggregate, child helper pages, class page, and autogen reports all agree on `NexusTK/ui/controls/ProgressBarControlPane.cpp` as the stable source parent.
- 2026-06-05 live IDA refresh:
  - Changed from `84/80` to `86/84`.
  - Removed stale recovered-source and external-tool ownership wording.
  - Evidence: live `lookup_funcs`, `callers`, `xrefs_to`, and byte reads confirm the modeled constructor/draw functions, PatchPane constructor caller, vtable-only draw reachability, unmodeled/no-xref private helpers, alignment gaps, and draw vtable pointer.
- 2026-06-08 Batch 113 parent-gate refresh:
  - Changed from `86/84` to `86/85`.
  - Evidence: fresh IDA MCP read-only checks reconfirmed the module owns the constructor, draw virtual, vtable-backed class identity, projected private helper byte ranges, and PatchPane consumer relationship. The old 95/95 audit wording is historical; current source output is governed by the accepted 2026-06-19 B005 85/85+ emitter-gate implementation.
- 2026-06-13 B002 current-setter split repair:
  - Scores unchanged.
  - Added [UID:0003N1][0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue](by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md) to this file's proposed contents after live IDA evidence showed direct PatchPane percent/reset callers and `+0xfa` progress-current ownership.
- 2026-06-19 B005 accepted source-quality implementation:
  - Changed from `86/85` to `88/90`.
  - Mirrored the class source-shape recommendation for `NexusTK/ui/controls/ProgressBarControlPane.cpp`: class declaration through [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md) plus child method bodies for constructor, `SetMinValue`, `SetMaxValue`, `SetCurrentValue`, `AddCurrentValue`, and `DrawProgressBar`.
  - Added source-facing field map, raw no-xref caveat, PatchPane consumer-only route, inherited invalidation dependency, and owner rejection details while preserving this file as the emitter root.
- 2026-07-23 B002 accepted UID000115 implementation:
  - Changed from `88/90` to `90/92`.
  - Reconciled the exact min/max/current/add source family, inherited `Pane::InvalidateRect(&m_visibleBounds)` dependency, retained-source liveness decision, and non-emitting aggregate policy from healthy live MCP and current project layout authority.
  - Historicalized the local `m_bounds`/`Invalidate` aliases, documented exact raw hashes/mappings/padding and the zero/one/two invalidation matrix, and recorded that the class now closes before qualified child definitions while UID0003N1 routes into generated source.
- 2026-07-23 B003 inherited-storage callback:
  - Changed from `90/92` to `91/93`.
  - Replaced derived physical `m_minValue/m_currentValue/m_maxValue` ownership with inherited `ControlPane::m_rangeStart/m_rangeCurrent/m_rangeEnd`, synchronized every source-bearing child to `m_visibleBounds`/`InvalidateRect`, and documented the exact `0x108` no-derived-storage proof.
  - Preserved file ownership, PatchPane consumer routes, exact method behavior/liveness, class-before-child assembly, and compiler-data/duplicate-aggregate non-emission.
- 2026-07-23 B003 UID00011A support synchronization:
  - Score/path/owner remain `91/93`, `NexusTK/ui/controls/`, and `FILE`.
  - Expanded the AddCurrentValue inventory and source-root evidence with exact hash/range/padding/unique-body/no-route facts, modulo-16 signed behavior, write/invalidation ordering, human names, rejected alternatives, retained-source classification, unchanged target C++, current `93/94` child score, and exact duplicate/non-emitting boundaries.
  - Preserved all unrelated constructor/setter/draw/layout/vtable/PatchPane/generated-history evidence and the one-class/six-qualified-definition assembly route.
