*** UID:0000U7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000021 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact evidence-only by-item facet for CheckBoxControlPane::SetVisualState at 0x00499ec0-0x00499f0e; the inherited slot, +0x103 visual-state byte, value-20 transition, and invalidation behavior resolve the old StateTypeHelper alias while UID00011S emits the source body once. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CheckBoxControlPane SetVisualState 00499EC0

## Status

- Entity kind: evidence-only by-item facet for a source-authored virtual method already emitted by the exact containing memory page.
- Exact function: `[0x00499ec0,0x00499f0e)`, size `0x4E` / 78 bytes.
- Semantic owner: [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md).
- Exact source body: [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md), source position `20`.
- Exact vtable evidence: [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md), primary slot `0x00618520`.
- Source disposition: this page is false/non-emitting with blank CPP/H so the method definition and declaration appear exactly once through UID00011S and UID000021.

## Resolved Source Identity

`0x00499ec0` is `CheckBoxControlPane::SetVisualState(unsigned char visualState)`, not a generic state/type helper.

- [UID:000038][ControlPane](by-class/ControlPane.md) declares protected virtual `SetVisualState(unsigned char)` at the same primary-table slot.
- The function reads and writes inherited byte `+0x103`, accepted as `m_visualState` in the base layout.
- The special value `20` is the CheckBox hit-test/visual part state consumed by this override; it is not proof that the function returns a control type.
- The calls through the inherited invalidation slot match `InvalidateRect(0)` for the value-20 transition and `InvalidateRect(&m_bounds)` after storing a changed visual state.
- One primary-vtable xref and no direct code callers are expected for a virtual override and do not make the function dead or compiler-generated.

## Exact Behavior

- If `m_visualState` already equals the requested value, the method makes no change.
- If the value differs and the new value is `20`, it first invalidates through the inherited virtual with a null rectangle.
- If the value still differs, it stores the new byte in inherited `m_visualState` and invalidates the control bounds at complete-object offset `+0x44`.
- The body ends at `0x00499f0e`; the successor function starts at `0x00499f10` after two bytes of `0xCC` alignment.
- It has no direct callee record because both invalidations dispatch indirectly through the inherited vtable slot.

## Evidence

- Live MCP passes on 2026-05-26, 2026-06-14, 2026-06-16, and the accepted UID0002M9 reanalysis agree on the exact `0x4E` range, sole slot xref `0x00618520`, no ordinary direct callers, inherited byte `+0x103`, constant `20`, indirect slot `+0x20`, and bounds pointer `this+0x44`.
- The 2026-06-14 byte/decompile pass verified the function begins immediately after `OnPaint`, returns with `retn 4`, and is followed by alignment before `0x00499f10`.
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md) and UID0002M9 place it at primary slot index 18, between `OnPaint` and inherited Enable/Disable methods.
- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md) fixes the complete object and inherited facet offsets. No private CheckBox field at `+0x103` is invented.
- UID00011S's accepted formal source reproduces the transition/invalidation behavior with human source names rather than raw offsets or saved IDA aliases.

## Source And Emission Decision

- Keep this page because it records the UID-stable item history and the evidence that corrected a misleading generated name.
- Do not emit a duplicate method or comment-only marker. The ordinary definition belongs to UID00011S and the declaration belongs to UID000021 H.
- Do not route this item through [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md). That page remains related family context, while [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md) is the settled standalone source route.
- The current human name is mandatory for reconstruction even though stripped original spelling cannot be proven. Retaining `StateTypeHelper`, `sub_499EC0`, or an unresolved placeholder would preserve reverse-engineering artifacts after semantics are known.

## Negative Evidence And Historical Correction

- No direct code caller exists; this does not support deletion because the primary vtable is the live route.
- No source evidence supports a standalone helper, global function, type-id query, or ButtonControlPane-owned implementation.
- The saved historical IDA label `CheckBoxControlPane_StateTypeHelper` documented a prior best guess, not original-symbol proof. Its body and inherited slot now supersede that guess.
- Earlier statements that the inherited slot, field name, source group, and final method name remained unresolved are preserved in dated Changes below. They are no longer current blockers.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | Exact range, vtable route, inherited slot, field/bounds offsets, transition behavior, source owner, no-duplicate disposition, negative evidence, and historical alias correction are complete. |
| Confidence | 95 | Repeated live evidence plus accepted base-slot and layout documentation resolve the method. Only stripped original spelling remains unavailable, so the accepted human source name is inferred rather than symbol-proven. |
| Reconstructable | false | This page is an evidence facet. UID00011S emits the one authored definition and UID000021 H emits the one declaration. |

## Cross-References

- [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md)
- [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000038][ControlPane](by-class/ControlPane.md)
- [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md)
- [UID:0002M9][0x006184d4-0x00618578.CheckBoxControlPaneVtableData](by-memory/0x006184d4-0x00618578.CheckBoxControlPaneVtableData.md)
- [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md)
- [UID:0001TX][CheckBoxControlPaneLayout](by-type/by-struct/CheckBoxControlPaneLayout.md)

## Changes

- 2026-07-26 B002 UID0002M9 source-quality implementation:
  - UID-preserving rename from `CheckBoxControlPaneStateTypeHelper_00499EC0` to `CheckBoxControlPaneSetVisualState_00499EC0`.
  - Changed `86/90 -> 92/95`, semantic owner `0000I7 -> 000021`, and reconstructable/emitter state to false/non-emitting with blank CPP/H.
  - Resolved the method from same-slot ControlPane declaration plus exact body behavior: inherited `m_visualState` at `+0x103`, value-20 transition, null/bounds invalidation, and sole primary-vtable xref.
  - Preserved all previous MCP evidence and stale StateTypeHelper assumptions below as historical provenance; UID00011S remains the single source body.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md), and generated-omission wording was removed from the evidence basis.
  - Before: the vtable-only helper was unclassified and had stale generated-source caveat wording.
  - After: it is marked as source-level checkbox virtual/helper behavior under the validated CheckBoxControlPane split-candidate file root; C++ remains blank because the inherited slot name and final file split are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_499EC0` at `0x00499ec0`, size `0x4e`, no direct code callers, and vtable ownership already documented through [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md).

- 2026-05-30: Grading changed from `0/0` to `74/82`.
  - Before: page documented the vtable-only helper behavior, ownership, generated-source omission, and rewrite guidance but remained unevaluated.
  - After: score reflects documented state-byte/refresh behavior and vtable ownership, with lower completion/confidence because the inherited slot and final method name are still unresolved.
  - Evidence: IDA notes confirm the function size, single vtable data xref, and no direct callers.

- 2026-06-07 A009 evidence-link pass:
  - Before: score remained `74/82` and the page did not link the exact vtable-data child, checkbox layout, or destructor/type-id range.
  - After: score is `78/86`, with explicit links to the containing checkbox core, exact vtable-data child, layout, and destructor/control-type documentation.
  - Evidence: existing by-memory and by-type pages now cross-confirm the helper's primary vtable slot, containing range boundary, vtable-only dispatch surface, and type id `20` relationship while final method naming remains open.

- 2026-06-14 C001 live-evidence refresh:
  - Before: score was `78/86`; supporting links existed, but the item page lacked current decompilation, byte-boundary, no-callee, and int_convert-verified offset evidence.
  - After: score is `85/89`; owner, emitter route, and blank reconstruction C++ are unchanged.
  - Evidence: live IDA MCP session `b001_0002bd` reconfirmed `0x00499ec0` size `0x4e` / 78 bytes (Verified with int_convert.py), the single vtable slot xref `0x00618520`, no direct callees, byte boundary through `0x00499f0e`, successor prologue at `0x00499f10`, and decompiled state-byte behavior at `this+0x103` / 259 with special type id `0x14` / 20, vtable slot `+0x20` / 32, and rectangle argument `this+0x44` / 68 (all Verified with int_convert.py). No IDA DB change or final C++ was made because final source names remain provisional.

- 2026-06-16 C001 item/IDA refresh:
  - Before: score was `85/89`; live behavior was documented, but the page still showed the pre-label `sub_499EC0` evidence state.
  - After: score is `86/90`; owner/emitter route and blank reconstruction C++ are unchanged.
  - Evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reports saved label `CheckBoxControlPane_StateTypeHelper`, unchanged `0x4e` size, the sole vtable data xref from `0x00618520`, no ordinary refs to the slot, and the same state-byte/type-20 refresh body. IDA DB edit skipped because the label already existed; final field/virtual-slot names remain unsafe.
- 2026-07-05 B009 source-quality implementation:
  - Scores and owner/emitter metadata unchanged.
  - Added a formal no-standalone marker so this evidence page does not duplicate the helper body now emitted by [UID:00011S][0x00499d40-0x00499f0e.CheckBoxControlPaneCore](by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md).
  - Evidence: B009 live MCP session `supervisor_recovery_20260705` reconfirmed `0x00499ec0` as the source-authored state/type helper in the exact checkbox core, with primary vtable slot `0x00618520`, inherited state byte `+0x103`, special type id `20`, and refresh virtual slot `+0x20`.
