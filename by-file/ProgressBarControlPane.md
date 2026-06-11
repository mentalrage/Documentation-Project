*** UID:0000MT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ProgressBarControlPane

## Status

- Confidence: strong for class role, source placement, constructor/draw ownership, vtable-backed class identity, and current helper boundary status; medium for private helper names.
- Proposed module: `NexusTK/ui/controls/ProgressBarControlPane.cpp`
- Final C++ status: withheld until the projected private helper names and progress-field names are source-quality.
- Main address ranges: `0x00494a90-0x00494b4b`, `0x00494c80-0x00494daa`, and `0x00494db0-0x00494eb0`
- Vtables: [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md) at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`

## File Role

`ProgressBarControlPane` is the reusable progress-bar UI control. It derives from [UID:0000IG][ControlPane](by-file/ControlPane.md), uses control type `22`, stores a progress range/current triplet around offsets `0xf8`, `0xfa`, and `0xfc`, and paints a filled segment, empty segment, and frame.

The only confirmed direct constructor caller in IDA during this pass is [UID:0000MH][PatchPane](by-file/PatchPane.md), which creates the progress bar for the `Auto Patch` dialog. That caller makes this a shared UI control consumed by patching code, not patch-module ownership.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ProgressBarControlPane` | [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) | Constructor; calls `ControlPane::ControlPane` with type `22`, installs progress vtables, clamps initial min/max to `0..30000`, synchronizes the current value, and invalidates after state changes. |
| `DrawProgressBar` | [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) | Paint virtual; computes the split point from current/range fields, draws filled color `1`, empty color `143`, and frame color `128`. |
| projected range setter | [UID:000115][0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter](by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md) | Code-shaped helper that clamps a value to `0..30000`, writes the lower/range-start field at `0xf8`, raises current value `0xfa` if needed, and invalidates. |
| projected range-limit setter | [UID:000117][0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter](by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md) | Code-shaped helper that clamps a value to `0..30000`, writes the upper/range-end field at `0xfc`, lowers current value `0xfa` if needed, and invalidates. |
| projected current-value adder | [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) | Code-shaped helper that adds a 16-bit delta into current value field `0xfa` and invalidates if the value changed. |

## Ownership Decision

Keep this as its own `ui/controls/ProgressBarControlPane.cpp` module. It is too specific to fold into [UID:0000IG][ControlPane](by-file/ControlPane.md), but it is also not part of the button/choice-control family despite sitting in gaps around [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) and `RadioGroupControlPane` code.

The private helpers at `0x00494a90`, `0x00494af0`, and `0x00494db0` should be grouped here only as projected helper code until IDA models them as function objects. Do not migrate them as public imported methods yet.

## Evidence Notes

- IDA MCP confirms real functions at `0x00494c80-0x00494daa` and `0x00494de0-0x00494eb0`.
- IDA MCP reports the only direct constructor caller as `0x005472d7` inside `PatchPane::PatchPane`.
- IDA MCP `xrefs_to` shows the draw routine referenced from the `ProgressBarControlPane` vtable area at `0x00617b78`.
- 2026-05-26 IDA MCP vtable pass confirms three class vtable bases at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`, installed by constructor stores at `0x00494cc5`, `0x00494ccb`, and `0x00494cd5`; current metadata reports `vtable_count: 0`.
- IDA MCP reports `0x00494a90`, `0x00494af0`, and `0x00494db0` as `Not a function`, but raw disassembly shows valid function-shaped code with prologues/returns and progress-field updates.
- Live IDA currently models only the constructor and draw virtual as functions, so helper names remain provisional.
- 2026-05-26 recheck: IDA MCP still reports the three helper starts as `Not a function` and reports no direct xrefs to them. Keep them documented as projected private `ProgressBarControlPane` helper bytes; do not add them to ignored ranges because the bytes operate on progress-bar fields and remain plausible project code.
- 2026-06-01 IDA MCP byte review confirms the corrected range-setter aggregate boundary: `0x00494a90-0x00494ae7` and `0x00494af0-0x00494b4b` are complete helper bodies, while `0x00494ae7-0x00494af0` and `0x00494b4b-0x00494b50` are `0xcc` alignment.
- 2026-06-03 cross-documentation review confirms the file page is the stable source parent for the class and assigned helpers: [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md) is attached here, exact helper children are assigned through the class with no emitted C++ bodies, [UID:0002OL][0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData](by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md) proves the vtable data range, and [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) plus [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) prove the modeled constructor/draw core.
- 2026-06-05 live IDA refresh confirms the constructor is modeled at `0x00494c80` with size `0x12a`, the draw virtual is modeled at `0x00494de0` with size `0xd0`, and helper starts `0x00494a90`, `0x00494af0`, and `0x00494db0` remain unmodeled function-shaped code.
- 2026-06-05 `callers` reports the constructor call at `0x005472d7` in the PatchPane constructor and no ordinary direct callers for the draw virtual; `xrefs_to` reports no references to the three helper starts and the expected draw vtable data reference at `0x00617b78`.
- 2026-06-05 byte reads reconfirm `0x00494ae7-0x00494af0`, `0x00494b4b-0x00494b50`, and `0x00494dde-0x00494de0` are alignment gaps, and `0x00617b78` stores the draw virtual pointer `0x00494de0`.
- 2026-06-08 Batch 113 IDA MCP recheck reconfirms the source-root ownership evidence: raw helper starts `0x00494a90`, `0x00494af0`, and `0x00494db0` still have no IDA function objects or direct xrefs; the constructor remains `0x00494c80-0x00494daa` with the PatchPane constructor call at `0x005472d7`; the draw virtual remains `0x00494de0-0x00494eb0` with vtable data xref `0x00617b78`; and byte windows preserve the same helper bodies plus alignment gaps.
- 2026-06-10 B001-018 IDA MCP audit reconfirms the update/draw grouping: [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) is an unmodeled/no-xref 46-byte current-value helper, [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) is the modeled draw virtual with vtable data xref `0x00617b78`, and aggregate [UID:00011B][0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw](by-memory/0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw.md) is a non-emitting duplicate inventory, not a separate source owner.

## Cross-References

- [UID:0000AW][ProgressBarControlPane](by-class/ProgressBarControlPane.md)
- [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md)
- [UID:000116][0x00494a90-0x00494b4b.ProgressBarRangeSetters](by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md)
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
  - After: completion/confidence are `84/80`, with the confidence raised only to the attachment threshold and final C++ still withheld.
  - Evidence: the exact constructor, draw virtual, vtable data, range-setter aggregate, update/draw aggregate, child helper pages, class page, and autogen reports all agree on `NexusTK/ui/controls/ProgressBarControlPane.cpp` as the stable source parent.
- 2026-06-05 live IDA refresh:
  - Changed from `84/80` to `86/84`.
  - Removed stale recovered-source and external-tool ownership wording.
  - Evidence: live `lookup_funcs`, `callers`, `xrefs_to`, and byte reads confirm the modeled constructor/draw functions, PatchPane constructor caller, vtable-only draw reachability, unmodeled/no-xref private helpers, alignment gaps, and draw vtable pointer.
- 2026-06-08 Batch 113 parent-gate refresh:
  - Changed from `86/84` to `86/85`.
  - Evidence: fresh IDA MCP read-only checks reconfirm the module owns the constructor, draw virtual, vtable-backed class identity, projected private helper byte ranges, and PatchPane consumer relationship. Confidence remains capped below final-source levels because helper/field names and emitted C++ are not 95/95 audited.
