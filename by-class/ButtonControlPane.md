*** UID:00001E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ButtonControlPane

## Status

- Confidence: strong for constructor, vtable, destructor, selected-state, and key-activation roles; medium for source-quality field names and final class declaration.
- Likely source file: [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- Core memory: [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- Destructor/thunk memory: [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- Autogen status: class page remains unclassified because no source-quality class declaration or field map is ready; the file page is assigned to `NexusTK/ui/controls/ButtonControlPane.cpp`.

## Class Purpose

`ButtonControlPane` is the base clickable button control above `ControlPane`. It installs button-specific vtables, initializes pressed/selected flags, handles selected-state redraw, and contains key-activation evidence reused by derived button classes.

[UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) treats this as the generic button/choice-control module under `ui/controls`, grouping the base button with image/text/checkbox/radio/slider/selection helpers while keeping passive progress controls and unrelated visual controls split out.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ButtonControlPane` | `0x00494eb0-0x00494f38` | Constructs the base `ControlPane`, installs three button vtables, clears button state, and initializes the `0x0101` word at `+0xff`. |
| `SetControlSelected` | `0x00494f40-0x00494f64` | Updates byte `+0x108` and invalidates/redraws the `+0x44` rectangle only when the selected state changes. |
| `OnKeyPress` | `0x00494f70-0x0049500d` | Handles key events for the secondary `+0xa0` subobject, accepting Space/Enter and driving the pressed/activate visual sequence. |
| deleting destructor | `0x0049b0d0-0x0049b10b` | Calls the shared cleanup helper, applies deleting flags, and optionally frees a `0x10c`-byte object. |
| destructor adjustors | `0x0049af11-0x0049af27` | Secondary and tertiary vtable adjustors subtract `0xa0` and `0xa4`, then tail-call `0x0049b0d0`. |

## Ownership And Layout Evidence

| Evidence area | Source | Meaning |
| --- | --- | --- |
| source module | [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) | Places the class in `NexusTK/ui/controls/ButtonControlPane.cpp`, with possible later split only if original-source evidence proves it. |
| core neighborhood | [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md) | Confirms the base button methods sit inside the generic button/choice-control family, not a feature dialog. |
| vtable/read-only data | [UID:000252][0x00617a38-0x0061885c.ControlPaneReadOnlyData](by-memory/0x00617a38-0x0061885c.ControlPaneReadOnlyData.md) | Lists `ButtonControlPane` among the generic control-pane family vtables and records representative xrefs including `sub_494EB0`. |
| destructor/thunks | [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) | The destructor/thunk band maps `ButtonControlPane`, text/image/radio/slider/check controls, and exclusions through vtable ownership instead of decompiler owner labels. |
| derived fan-in | Live IDA xrefs to `0x00494eb0` and the vtable bases | Constructor callers include generic derived controls such as image, gender, direction, and pretty buttons. |

## Boundaries And Exclusions

- `ButtonControlPane` itself is bounded inside the larger choice-control aggregate at `0x00494eb0-0x0049500d`.
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md) is nearby but explicitly excluded: it owns the passive progress indicator at `0x00494c80-0x00494eaf` and should not be merged into this class just because of address locality.
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) and [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) are related button modules; they are not proof that base `ButtonControlPane` should absorb every text or pretty-button implementation.
- Some feature-specific callers reuse the base constructor, but current ownership is assigned by behavior, vtables, and broad constructor fan-in rather than caller context alone.

## Evidence Notes

- 2026-06-05 live IDA MCP audit reports method extents `sub_494EB0` `0x00494eb0-0x00494f38`, `sub_494F40` `0x00494f40-0x00494f64`, `sub_494F70` `0x00494f70-0x0049500d`, `sub_49B0D0` `0x0049b0d0-0x0049b10b`, `sub_49AF11` `0x0049af11-0x0049af1c`, and `sub_49AF1C` `0x0049af1c-0x0049af27`.
- Constructor `0x00494eb0` calls the `ControlPane` base constructor at `0x00494ede`, writes primary/secondary/tertiary `ButtonControlPane` vtables at `0x00494eee`, `0x00494ef4`, and `0x00494efe`, clears bytes at `+0x102` and `+0x108`, writes `0x0101` at `+0xff`, then calls `sub_5446B0`.
- Live IDA xrefs show 9 direct constructor calls to `0x00494eb0`: `0x004a220d`, four calls inside `sub_4FB630`, raw calls at `0x0050064d` and `0x005007ad`, plus calls from `sub_54B5E0` and `sub_54B8C0`.
- `SetControlSelected` compares the input byte with `[ecx+0x108]`, writes the byte only on change, then jumps through vtable slot `+0x20` with the rectangle/state region at `+0x44`.
- `OnKeyPress` narrows the event character through `dword_67A754`, requires event byte `[arg+4] == 8`, accepts Space or `0x0d`, adjusts from the secondary subobject by `-0xa0`, drives visual states `0x0b` and `0x0a`, refreshes through `dword_67A7CC`, sleeps `0x85` ms, then dispatches the activation through vtable slot `+0x48`.
- The ButtonControlPane vtable block has RTTI at `0x00617bd4`, primary destructor slot `0x00617bd8 -> sub_49B0D0`, secondary adjustor `0x00617c40 -> sub_49AF11`, key handler slot `0x00617c48 -> sub_494F70`, and tertiary adjustor `0x00617c70 -> sub_49AF1C`.
- The three vtable bases are written by the base constructor and by derived constructors at `sub_495040`, `sub_495450`, and `sub_495BF0`, supporting reuse during derived construction rather than assigning those derived owners to the base method.
- Xrefs to `sub_494F70` are vtable/data references at `0x0060e048`, `0x00617c48`, `0x00617cf0`, `0x00617d98`, `0x00617e3c`, `0x0061dc00`, `0x0061dca4`, `0x00622348`, and `0x006223ec`, showing the same key handler is shared by several button-derived vtables.
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md) records a 2026-06-01 boundary audit that keeps `0x00494eb0-0x0049500d` as the base button helper band.
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md) records destructor/thunk ownership by vtable data.
- [UID:000252][0x00617a38-0x0061885c.ControlPaneReadOnlyData](by-memory/0x00617a38-0x0061885c.ControlPaneReadOnlyData.md) records the broader control-family vtable island that includes `ButtonControlPane`.

## Open Questions

- Final field names for pressed/selected/key-activation state are not yet source-quality.
- The class declaration is still below the reconstruction-code gate because the exact inheritance/subobject view and destructor slot layout need a final class-layout pass.
- Final source split between base `ButtonControlPane.cpp` and separate text/pretty/specialized button modules remains partly provisional.

## Cross-References

- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:000252][0x00617a38-0x0061885c.ControlPaneReadOnlyData](by-memory/0x00617a38-0x0061885c.ControlPaneReadOnlyData.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md)
- [UID:0000MT][ProgressBarControlPane](by-file/ProgressBarControlPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- What existed before: the page documented the base button role, methods, and owner-pollution caveat, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `66/76`.
- Summary and evidence: constructor, selected-state update, key activation, and derived-constructor xrefs are covered; final helper names, event semantics, and class layout remain only partially documented.
- 2026-06-02 documentation expansion:
  - What existed before: the class page lagged the stronger file and memory pages, with only a compact method list and owner-pollution note.
  - Changed to: scores `72/82`, plus source-module placement, autogen status, ownership/layout evidence table, boundary/exclusion notes, vtable/read-only data evidence, destructor/thunk evidence, and explicit open questions.
  - Summary/evidence: existing documentation ties the base class to `NexusTK/ui/controls/ButtonControlPane.cpp`, the `ButtonChoiceControlCore` method neighborhood, the control-pane vtable island, and the destructor/thunk band. C++ and `RECONSTRUCTABLE` remain blank because the source-quality class declaration and exact field names are not final.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores and still relied on broad aggregate evidence, stale owner-pollution notes, and incomplete destructor-slot detail.
  - Changed to: scores `82/86`, exact live IDA method extents, constructor/vtable writes, selected-state and key-activation behavior, primary destructor and adjustor evidence, and vtable/data xrefs.
  - Summary/evidence: completion increased because the documented behavioral surface now covers constructor, state update, key activation, destructor, adjustors, vtable slots, and caller fan-in. Confidence increased because those claims are backed by live IDA MCP disassembly/xrefs rather than stale aggregate notes. C++ and `RECONSTRUCTABLE` remain blank because source-quality field names, inheritance declaration, and final source split are still below the reconstruction gate.
