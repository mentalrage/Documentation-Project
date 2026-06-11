*** UID:0000DU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SpellStringInputPane

## Status

- Confidence: strong for behavior and IDA boundaries; medium for exact source split.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md), plus shared prompt helper [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md).
- Parent attachment: attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md) after the file page (`88/80`) and this class (`84/82`) both cleared the 80/80 gate.
- Reconstruction block: intentionally blank; final class declaration still needs the direct destructor split, confirm-handler dependency audit, and source-quality field names before C++ should be emitted.

## Class Purpose

`SpellStringInputPane` is the string-argument spell prompt. It builds a [UID:000077][LineInputPane](by-class/LineInputPane.md), displays the spell name/prompt, reads the entered text, converts it to the outbound client character form, and sends opcode `0x0f` with the spell index and string payload.

## Method Notes

| Method/helper | Address | Role |
| --- | --- | --- |
| `SetPromptText` | [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md) | Shared spell prompt layout/text helper used by multiple spell input panes. |
| constructor | [UID:0001KU][0x005adf40-0x005adfcd.SpellStringInputPaneConstructor](by-memory/0x005adf40-0x005adfcd.SpellStringInputPaneConstructor.md) | Builds the line-input base, installs vtables, sets spell prompt text from player spell data, and stores the spell slot index. |
| `OnConfirmInput` | [UID:0001KW][0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput](by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md) | Reads input text, converts it, builds opcode `0x0f`, and queues the string spell packet. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b7e90`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NH][0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor](by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md) | Restores panel state, runs base cleanup, and optionally frees `this`. |

## Evidence Notes

- [UID:0001KU][0x005adf40-0x005adfcd.SpellStringInputPaneConstructor](by-memory/0x005adf40-0x005adfcd.SpellStringInputPaneConstructor.md) records live IDA evidence for exact constructor bounds, base `LineInputPane` construction, three vtable stores, spell-record prompt lookup through [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md), the `this + 0x108` stored spell slot, and three spell-cast callers.
- [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md) records the contiguous constructor/direct-destructor/confirm map and the remaining direct-destructor split at `0x005adfd0-0x005ae053`.
- [UID:0001NH][0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor](by-memory/0x005b7e90-0x005b7f54.SpellStringInputPaneScalarDeletingDestructor.md) records live IDA evidence for the scalar deleting destructor, including vtable restores, state-helper selection, shared input-pane cleanup, scalar-delete flag handling, thunk refs, and vtable data refs.
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) records the secondary and tertiary destructor adjustor thunks at `0x005b78ba` and `0x005b78c5`; they are compiler-generated wrappers and remain excluded from source reconstruction.
- `SetPromptText` is shared with spell target/slot/selection prompts, so it is source-owned by spell input UI, not a one-method utility source.

## Open Questions

- [UID:0001KW][0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput](by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md) still needs a fresh IDA caller/callee/disassembly pass; recent MCP `tools/call` attempts timed out.
- The direct destructor at `0x005adfd0-0x005ae053` is known from byte-boundary evidence but still needs its own exact by-memory split before this class can approach final-source completeness.
- Source-quality names are still needed for the spell-table owner, the stored slot field at `this + 0x108`, and any confirm-handler packet-buffer locals.

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001KV][0x005adf40-0x005ae1a4.SpellStringInputPane](by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md)
- [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md)
- [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md)
- [UID:0000DT][SpellSpellInputPane](by-class/SpellSpellInputPane.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents line-input behavior, shared prompt helper, constructor/confirm/destructor/thunk memory docs, opcode/string packet behavior, and ignored adjustor-thunk handling; confidence is capped by exact source split and shared helper ownership.
- 2026-06-05: Marked reconstructable and left unassigned.
- Evidence: live IDA MCP `lookup_funcs` confirms the shared prompt helper, constructor, confirm handler, scalar deleting destructor, and adjustor thunks at `0x004f20a0`, `0x005adf40`, `0x005ae060`, `0x005b7e90`, `0x005b78ba`, and `0x005b78c5`. The likely parent file meets 80/80, but this class confidence is `78`, so the parent UID stays blank.
- 2026-06-06: Raised confidence from `78` to `82`, attached the class to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md), removed generated-source provenance wording, and replaced the thin evidence note with child-page-backed evidence for constructor, aggregate, scalar destructor, and adjustor thunks.
  - Before: the page still treated the exact source split as a confidence blocker and did not attach to the file parent.
  - After: the source split is still a caveat, but the class/file relationship now clears the documented 80/80 attachment gate; final C++ remains blank because the direct destructor split, confirm-handler evidence, and source-quality field/local names are still incomplete.
