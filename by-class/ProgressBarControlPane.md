*** UID:0000AW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ProgressBarControlPane

## Status

- Confidence: strong for constructor, draw virtual, vtable-backed ownership, source placement, and current helper boundary status; medium for private helper names.
- Likely source file: [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- Final C++ status: withheld until the projected private helper names and progress-field names are source-quality.
- Vtables: [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md) at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`

## Class Purpose

`ProgressBarControlPane` is a `ControlPane`-derived progress indicator. It stores a lower bound, current value, and upper bound, clamps public range input to `0..30000`, invalidates the pane when state changes, and paints a horizontal filled/empty bar with a frame.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| projected range-start setter | [UID:000115][0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter](by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md) | Clamps the incoming value, writes field `0xf8`, raises current field `0xfa` if needed, and invalidates. IDA does not currently model this as a function. |
| projected range-end setter | [UID:000117][0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter](by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md) | Clamps the incoming value, writes field `0xfc`, lowers current field `0xfa` if needed, and invalidates. IDA does not currently model this as a function. |
| `ProgressBarControlPane` | [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) | Constructs the control with type `22`, installs progress-bar vtables, clamps initial range fields, and resets current value to `0`. |
| projected current-value adder | [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) | Adds a 16-bit delta into current field `0xfa` and invalidates if changed. IDA does not currently model this as a function. |
| `DrawProgressBar` | [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) | Computes the filled width from current/range fields and draws filled, empty, and frame regions. |

## Evidence Notes

- Live IDA currently models the constructor and draw virtual as functions while leaving the three private helpers as projected function-shaped bytes.
- IDA confirms `0x00494c80` has one direct caller, `PatchPane::PatchPane` at `0x005472d7`.
- IDA confirms the draw routine is a vtable target at `0x00617b78`.
- 2026-05-26 IDA MCP vtable pass confirms primary/secondary/tertiary vtables at `0x00617b34`, `0x00617b9c`, and `0x00617bcc`, installed by constructor stores at `0x00494cc5`, `0x00494ccb`, and `0x00494cd5`.
- The three projected helpers touch the same field triplet (`0xf8`, `0xfa`, `0xfc`) and use the same vtable `+0x20` invalidation pattern as the constructor.
- Current generated metadata records a stored constructor-name control-character issue; treat the active emitted source name as cleaned, but keep the data issue tracked.
- 2026-05-26 recheck: IDA MCP still reports `0x00494a90`, `0x00494af0`, and `0x00494db0` as `Not a function`, with no direct xrefs. Keep them as projected private helper bytes under this class, not ignored/runtime code.
- 2026-06-01 byte recheck confirms the two range-setter helper bodies end at `0x00494ae7` and `0x00494b4b`, with only `0xcc` alignment between/after them.
- 2026-06-03 cross-documentation review ties the class attachment tree together: [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) is at the parent-confidence threshold, the exact helper children are assigned here with blank C++ bodies, [UID:0002OL][0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData](by-memory/0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md) proves the vtable data range, and the constructor/draw pages prove the modeled class core.
- 2026-06-05 live IDA refresh confirms the constructor is modeled at `0x00494c80` with size `0x12a`, the draw virtual is modeled at `0x00494de0` with size `0xd0`, and helper starts `0x00494a90`, `0x00494af0`, and `0x00494db0` remain unmodeled function-shaped code.
- 2026-06-05 `callers` reports the constructor call at `0x005472d7` in the PatchPane constructor and no ordinary direct callers for the draw virtual; `xrefs_to` reports no references to the three helper starts and the expected draw vtable data reference at `0x00617b78`.
- 2026-06-05 byte reads reconfirm `0x00494ae7-0x00494af0`, `0x00494b4b-0x00494b50`, and `0x00494dde-0x00494de0` are alignment gaps, and `0x00617b78` stores the draw virtual pointer `0x00494de0`.
- 2026-06-08 Batch 113 IDA MCP recheck reconfirms the parent-gate evidence: `lookup_funcs` reports raw helper starts `0x00494a90`, `0x00494af0`, and `0x00494db0` are still not IDA functions; `0x00494c80-0x00494daa` remains the constructor with the `PatchPane` constructor caller at `0x005472d7`; `0x00494de0-0x00494eb0` remains the draw virtual with vtable data xref `0x00617b78`; and the helper/draw byte windows still show only `0xcc` alignment at `0x00494ae7-0x00494af0`, `0x00494b4b-0x00494b50`, and `0x00494dde-0x00494de0`.
- 2026-06-10 B001-018 IDA MCP audit reconfirms the update/draw grouping: [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md) is an unmodeled/no-xref 46-byte current-value helper, [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md) is the modeled draw virtual with vtable data xref `0x00617b78`, and aggregate [UID:00011B][0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw](by-memory/0x00494db0-0x00494eb0.ProgressBarControlPaneUpdateAndDraw.md) is a non-emitting duplicate inventory, not a separate source owner.

## Cross-References

- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:0001YH][ProgressBarControlPaneVtables](by-type/by-vtable/ProgressBarControlPaneVtables.md)
- [UID:000116][0x00494a90-0x00494b4b.ProgressBarRangeSetters](by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md)
- [UID:000119][0x00494c80-0x00494daa.ProgressBarControlPaneConstructor](by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md)
- [UID:00011A][0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder](by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md)
- [UID:00011C][0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar](by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:0000A9][PatchPane](by-class/PatchPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page was unevaluated despite documenting constructor, draw behavior, range fields, vtables, and helper caveats.
  - After: Scored as high completion with medium-high confidence because several helper byte ranges remain projected private helpers rather than IDA-modeled functions.
  - Evidence: Existing method notes, field descriptions, IDA MCP vtable pass, and function-boundary caveats document the class behavior and remaining uncertainty.
- 2026-06-01: Marked the class reconstructable and attached it to the `ProgressBarControlPane` source-file page.
  - Before: validator autogen metadata was blank.
  - After: `RECONSTRUCTABLE:TRUE`, parent UID `0000MT`, and position `10`; no C++ code is emitted.
  - Evidence: constructor, draw virtual, vtables, and projected helper bytes are all documented as NexusTK-owned progress-bar control code, but final-source code still requires higher confidence and completion.
- 2026-06-03 parent-threshold consistency pass:
  - Before: confidence remained `78` while exact helper children were already attached under this class.
  - After: completion/confidence are `84/80`, with confidence raised only to the attachment threshold and final C++ still withheld.
  - Evidence: the file page, constructor, draw virtual, vtable data, range-setter aggregate, update/draw aggregate, exact helper pages, and autogen reports agree on this class as the progress-bar control owner.
- 2026-06-05 live IDA refresh:
  - Changed from `84/80` to `86/84`.
  - Removed stale recovered-file wording and the old unavailable-IDA caveat.
  - Evidence: live `lookup_funcs`, `callers`, `xrefs_to`, and byte reads confirm the modeled constructor/draw functions, PatchPane constructor caller, vtable-only draw reachability, unmodeled/no-xref private helpers, alignment gaps, and draw vtable pointer.
- 2026-06-08 Batch 113 parent-gate refresh:
  - Changed from `86/84` to `86/85`.
  - Evidence: fresh IDA MCP read-only checks reconfirm the constructor/draw modeled boundaries, PatchPane constructor caller, draw vtable reference, no-xref raw helper starts, helper byte bodies, and alignment gaps. The confidence increase is limited to the corrected `85/85` parent gate; final C++ remains blank because private helper and field names are still provisional.
