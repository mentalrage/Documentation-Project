** TARGET-REPORT-UID:000127 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B009 Source-Quality Report: [UID:000127] TextEditControlPaneDestructor

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/000127-TextEditControlPaneDestructor-source-quality.md`  
Target path: `source-3/project-documentation/by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md`  
Assignment: `B009-goal2-text-edit-control-pane-destructor-source-quality-000127-20260619`  
Status: FINISHED report-only research. No by-* documentation, generated output, IDA database, project-level reports, or `by-memory/-coverage-report.md` were edited.

## Target Summary

[UID:000127] covers `0x0049b6c0-0x0049b731`, currently documented as `TextEditControlPaneDestructor` with `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000EM`, and `EMITTER_UIDS:0000EM`.

The target range is not a human-authored destructor body that should emit formal C++ directly. It is the MSVC scalar deleting destructor wrapper for `TextEditControlPane`. The source-facing destructor is the ordinary class destructor shape already mirrored by the non-deleting helper at `0x00498b90-0x00498bcf`: restore class vtables as compiler lowering, delete the owned `TextEditPane *` at `this+0x10c`, null the pointer, and let the compiler chain the base `Pane::~Pane()`. The exact target wrapper adds the compiler deleting-destructor flags parameter and conditional object-free branch. It should stay a blank formal C++ target with explicit no-code proof, while support docs should carry the ordinary source destructor draft.

Recommended metadata for [UID:000127]:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:0000EM
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000EM
```

The score should rise from `84/90` to `86/92` because the current evidence resolves the stale threshold-only/no-code reasoning, confirms the exact wrapper/body relationship, identifies the owned `TextEditPane` pointer field at `+0x10c`, resolves the base teardown callee as ordinary `Pane::~Pane()`, and reconciles the StaticTextControlPane vtable caveat as inherited TextEditControlPane destructor slots rather than mixed source ownership. Completion should not rise higher because this exact by-memory row remains compiler-generated wrapper glue and live IDA MCP was not available in this pass to refresh database names/comments in place.

## Evidence Checked

Primary target:

- `source-3/project-documentation/by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md`
- Local IDA JSON export: `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x0049b6c0.json`
- Local IDA JSON export: `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x0049b02f.json`
- Local IDA JSON export: `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x0049b03a.json`

Ordinary destructor and source placement:

- `source-3/project-documentation/by-class/TextEditControlPane.md`
- `source-3/project-documentation/by-file/TextEditControlPane.md`
- `source-3/project-documentation/by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md`
- Local IDA JSON export: `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00498b90.json`

Base and child destructor support:

- `source-3/project-documentation/by-class/Pane.md`
- `source-3/project-documentation/by-file/Pane.md`
- `source-3/project-documentation/by-memory/0x00544460-0x00545086.PaneCore.md`
- Local IDA JSON export: `hooks-generation/tests/function_data/raw_ida_export_data/functions/0x00544580.json`
- `source-3/project-documentation/by-class/TextEditPane.md`
- `source-3/project-documentation/by-memory/0x0058e140-0x0058e228.TextEditPaneDestructor.md`
- `source-3/project-documentation/by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`
- `source-3/project-documentation/by-memory/-ignored.md`

Vtable, inheritance, and neighboring-range support:

- `source-3/project-documentation/by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md`
- `source-3/project-documentation/by-class/StaticTextControlPane.md`
- `source-3/project-documentation/by-class/ExchangeMoneyEditControlPane.md`
- `source-3/project-documentation/by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md`
- `source-3/project-documentation/by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md`
- `source-3/project-documentation/by-memory/-coverage-report.md` was read only for pending replacement-row text.
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md` and `source-3/project-documentation/auto-generated/NexusTK/ui/controls/TextEditControlPane.cpp` were read only to confirm current generated-output state.

## Heuristic / Inference Reanalysis And Validation

### Exact target range and wrapper behavior

The local IDA export for `0x0049b6c0` decompiles this target as:

```cpp
_DWORD *__thiscall sub_49B6C0(_DWORD *Block, char a2)
{
  void (__thiscall ***v3)(_DWORD, int); // ecx

  v3 = (void (__thiscall ***)(_DWORD, int))Block[67];
  *Block = &TextEditControlPane::`vftable';
  Block[40] = &TextEditControlPane::`vftable';
  Block[41] = &TextEditControlPane::`vftable';
  if ( v3 )
  {
    (**v3)(v3, 1);
    Block[67] = 0;
  }
  sub_544580(Block);
  if ( (a2 & 1) == 0 || (a2 & 4) != 0 )
    return Block;
  sub_4F4AC0(Block);
  return Block;
}
```

This is the scalar deleting destructor form: `this` plus a compiler flags byte, derived vtable restoration, derived object cleanup, base destructor call, and conditional object-free. The target range is `0x0049b6c0-0x0049b731`, size `0x71` / 113 bytes. The target page already records four-byte `0xcc` prepad at `0x0049b6bc-0x0049b6c0` and fifteen-byte `0xcc` postpad at `0x0049b731-0x0049b740`; no neighboring function should be merged into this row.

The exact deleting behavior is:

- Restore three TextEditControlPane vtable pointers:
  - primary object vptr at `this+0x00`,
  - secondary subobject vptr at `this+0xa0` (`Block[40]`),
  - tertiary subobject vptr at `this+0xa4` (`Block[41]`).
- Load `Block[67]`, which is `this+0x10c`, as the owned embedded editor pointer.
- If the embedded editor pointer is non-null, call its virtual deleting destructor with deleting flag `1`, then clear `this+0x10c` to null.
- Call `0x00544580`, resolved through Pane docs and local IDA export as ordinary `Pane::~Pane()` body, not an unknown helper and not GrafPort cleanup directly.
- Return `this` without freeing if `(flags & 1) == 0`.
- Return `this` without freeing if `(flags & 4) != 0`; the current binary path includes the compiler runtime guard/no-op helper `0x0041b6a0`, which `by-memory/-ignored.md` identifies as `@_guard_check_icall_nop@4`.
- Call `0x004f4ac0` / [UID:000197] `OperatorDeleteWrapper` only when `(flags & 1) != 0 && (flags & 4) == 0`.

The wrapper returns `this`. That return value is part of MSVC scalar deleting destructor ABI shape and should not be treated as source-authored class logic.

### Ordinary destructor source shape

The non-deleting helper at `0x00498b90-0x00498bcf` in [UID:00011H] has the same source-authored cleanup without the deleting flags/object-free tail:

```cpp
void __thiscall sub_498B90(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))this[67];
  *this = &TextEditControlPane::`vftable';
  this[40] = &TextEditControlPane::`vftable';
  this[41] = &TextEditControlPane::`vftable';
  if ( v2 )
  {
    (**v2)(v2, 1);
    this[67] = 0;
  }
  sub_544580(this);
}
```

This is strong evidence that the source-facing destructor body is ordinary `TextEditControlPane::~TextEditControlPane()`, with compiler-emitted vptr resets and base destructor call around a small handwritten cleanup. The plausible mid-2000s source body is:

```cpp
TextEditControlPane::~TextEditControlPane()
{
    delete m_textEditPane;
    m_textEditPane = NULL;
}
```

This C++ is appropriate for support documentation and for any future ordinary-destructor child row, but not for the formal C++ block of [UID:000127]. If emitted at [UID:000127], it would incorrectly claim the scalar deleting wrapper and flag handling were handwritten source.

The source should not explicitly call `Pane::~Pane()`; the compiler emits the base destructor call after the derived destructor body. The source should not explicitly write vtable pointers; those are also compiler lowering artifacts. The source should not call `OperatorDeleteWrapper`; `delete obj` or virtual destructor invocation causes MSVC to generate the scalar deleting destructor wrapper and allocator-free path.

### Field at `this+0x10c`

The field at `+0x10c` should be documented as an owned embedded editor pointer:

```cpp
TextEditPane *m_textEditPane;
```

Confidence is high for type and ownership, medium-high for exact original spelling. Evidence:

- `TextEditControlPane` constructor support in [UID:00011H] and [UID:0000EM] records allocation of a 372-byte `TextEditPane`, constructor call at `0x0058dce0`, and store to `this+0x10c`.
- The destructor target loads `this+0x10c`, invokes the pointee's virtual deleting destructor with flag `1`, and clears the field to zero.
- [UID:0000EO] `TextEditPane` and [UID:0002ZZ] `TextEditPaneDestructor` establish this as a separate editor widget object, not an inline subobject and not a generic pane pointer.
- Current class docs already use the phrase "embedded TextEditPane" and list `+0x10c embedded TextEditPane*`.

Rejected alternatives:

- `m_editor`: plausible but too generic; the project already distinguishes `TextEditPane` from `TextEditControlPane`, and the constructor/destructor evidence supports a type-bearing field name.
- `m_textPane`: less precise because `TextEditPane` is the source class and `TextEditControlPane` is a wrapper.
- Inline member object: rejected because constructor allocates a 372-byte child object and stores a pointer, and destructor calls a virtual deleting destructor through the pointer.

### Base teardown callee

The callee at `0x00544580` should be named and cross-linked as ordinary `Pane::~Pane()`:

- [UID:0001EA] `PaneCore` documents `0x00544580-0x00544687` as the ordinary `Pane` destructor body.
- The local IDA JSON export for `0x00544580` shows it writing `Pane` vtables and cleaning Pane-owned focus, handler, region, and GrafPort state.
- `0x004b8d20` is the lower-level GrafPort cleanup invoked from the Pane teardown path; it is not the direct target callee and should not be named as the base destructor.

Recommended support wording: "`0x00544580` is the ordinary `Pane::~Pane()` base destructor body. In source, `TextEditControlPane::~TextEditControlPane()` should not explicitly call it; the compiler emits the base chain."

### Deleting destructor flag policy

The target's flag handling is standard MSVC scalar deleting destructor ABI behavior:

- `flags & 1`: object storage should be released after destructor body.
- `flags & 4`: suppress or route the free through the compiler guard/no-op path. The target page should preserve the exact behavior: the object-free call to [UID:000197] happens only when `(flags & 1) != 0 && (flags & 4) == 0`.
- The flag-4 path reaches `0x0041b6a0`, already documented in `by-memory/-ignored.md` as `@_guard_check_icall_nop@4`, a one-byte compiler/runtime no-op helper. It is not product source logic and should not become an emitted helper.

The target should explicitly distinguish the wrapper's delete flag ABI from source `TextEditControlPane::~TextEditControlPane()`. The formal target C++ block should remain blank, with no-code proof tied to this exact wrapper behavior.

### Adjustor thunk evidence

Two short compiler adjustor thunks jump to this wrapper:

- `0x0049b02f-0x0049b03a`, local export `sub_49B02F`, decompiles as `return sub_49B6C0(this - 40, a2);`.
- `0x0049b03a-0x0049b045`, local export `sub_49B03A`, decompiles as `return sub_49B6C0(this - 41, a2);`.

The offsets are:

- `this - 40 dwords` = `-0xa0`, matching a secondary subobject vptr at `this+0xa0`.
- `this - 41 dwords` = `-0xa4`, matching a tertiary subobject vptr at `this+0xa4`.

These are compiler-generated deleting-destructor adjustor thunks for secondary/tertiary base views, not source methods and not evidence for separate C++ destructors. They should remain no-code compiler glue in [UID:00011Y] and support vtable docs. The class layout/source declarations should preserve the multiple-inheritance/base subobject arrangement that causes vptrs at `+0xa0` and `+0xa4`; MSVC will regenerate these adjustors from class declarations and virtual destructor relationships.

### Vtable cells and StaticTextControlPane caveat

The earlier target wording treated `StaticTextControlPane` vtable use as a medium-confidence caveat. Current support evidence in [UID:0003LQ] resolves the main concern:

- `0x00618100`, `0x00618168`, and `0x00618198` are TextEditControlPane vtable cells for the primary and adjusted destructor slots.
- `0x006181a4`, `0x0061820c`, and `0x0061823c` are StaticTextControlPane vtable cells.
- [UID:0003LQ] records current B003 Goal 2 IDA MCP evidence that `StaticTextControlPane` RTTI class hierarchy descriptors list `TextEditControlPane` as the next base after the derived descriptor.
- Therefore the StaticText cells are inherited TextEditControlPane destructor slots/code reuse, not an independent source ownership claim.

The target VA `0x0049b6c0` has vtable refs from `0x00618100` and `0x006181a4`, plus thunk refs from `0x0049b02f` and `0x0049b03a`. The adjustor thunks are referenced by TextEdit and StaticText vtable cells:

- `0x0049b02f` from `0x00618168` and, through support docs, inherited StaticText cell `0x0061820c`.
- `0x0049b03a` from `0x00618198` and, through support docs, inherited StaticText cell `0x0061823c`.

Recommended interpretation:

- [UID:000127] remains owned by `TextEditControlPane`.
- `StaticTextControlPane` consumes/inherits the base destructor implementation because it derives through `TextEditControlPane`.
- The vtable caveat should be downgraded from an uncertainty/blocker to an explicit inherited-base-slot note.
- No split child for a StaticText destructor is warranted from this evidence. If future evidence finds a StaticText-specific non-empty destructor, it should live under StaticText, but the current vtable reuse alone does not support that.

### Source placement and ownership

Recommended source route:

```text
CANONICAL_OWNER:0000EM
EMITTER_UIDS:0000EM
Source file: by-file/TextEditControlPane.md / NexusTK/ui/controls/TextEditControlPane.cpp
```

Rejected owner/source alternatives:

- `TextEditPane` ([UID:0000EO]): rejected. `TextEditPane` is the owned child type at `+0x10c`; this target is the wrapper/control destructor that deletes the child.
- `StaticTextControlPane` ([UID:0000E3]): rejected as canonical owner. StaticText vtable refs are inherited TextEditControlPane base slots by RTTI hierarchy evidence.
- `ButtonChoiceControlDestructors` aggregate ([UID:00011Y]): rejected as emitter. It is an index/aggregate documenting nearby destructors and thunks, not a source owner.
- `Pane` ([UID:0000A2]): rejected as owner. `Pane::~Pane()` is the base callee, not the derived target.
- No-owner/non-emitting route: rejected. The ordinary `TextEditControlPane` destructor is source-reconstructable and belongs in the TextEditControlPane class/file; only this scalar deleting wrapper row should remain no formal C++.

### Boundary and neighboring functions

The target should remain exactly `0x0049b6c0-0x0049b731`. Neighboring functions are already excluded correctly:

- `0x0049b5f0-0x0049b6bc`: StaticTextControlPane2 destructor / neighboring range; ends before the four-byte prepad.
- `0x0049b6bc-0x0049b6c0`: four `0xcc` bytes, not code.
- `0x0049b6c0-0x0049b731`: this target wrapper.
- `0x0049b731-0x0049b740`: fifteen `0xcc` bytes, not code.
- `0x0049b740-0x0049b795`: TargetOptionEditControlPane destructor, separate function.

No merge or split is needed for the target wrapper. If the project wants a formal C++ row for the ordinary destructor body, the right future split is not inside [UID:000127]; it is a child or refined entry around `0x00498b90-0x00498bcf` in [UID:00011H].

### First-draft C++ readiness

[UID:000127] itself should not emit formal C++. The target-specific no-code proof is:

- The function takes an MSVC deleting-destructor flags byte (`a2`), not a source-authored destructor parameter.
- The function conditionally calls `OperatorDeleteWrapper` only when `(flags & 1) != 0 && (flags & 4) == 0`, which is compiler deleting-destructor wrapper behavior.
- The flag-4 path reaches `@_guard_check_icall_nop@4`, compiler/runtime glue.
- It is reached through vtable destructor slots and compiler adjustor thunks, with no evidence of a direct source call that would require a named helper.
- The ordinary destructor body already exists as the non-deleting helper at `0x00498b90-0x00498bcf`, which lacks the flag/free ABI tail.

Support docs can carry this first-draft ordinary destructor C++:

```cpp
TextEditControlPane::~TextEditControlPane()
{
    delete m_textEditPane;
    m_textEditPane = NULL;
}
```

Do not place that block in the formal C++ field of [UID:000127]. Place it in `by-class/TextEditControlPane.md`, `by-file/TextEditControlPane.md`, and/or a future refined ordinary-destructor child row for `0x00498b90-0x00498bcf`. If a future implementation callback requests generated source for [UID:0000EM], the generated C++ should define the ordinary destructor once and rely on the compiler to regenerate this wrapper and the two adjustor thunks.

## Open Questions Rechecked

### Is this a source-authored destructor or a scalar deleting wrapper?

Resolved. It is the scalar deleting destructor wrapper for `TextEditControlPane`. The ordinary source destructor shape is reconstructable, but this exact row should remain no formal C++.

### What is the `this+0x10c` field?

Resolved to high confidence as `TextEditPane *m_textEditPane`, owned by the wrapper/control pane. Constructor evidence allocates/stores a `TextEditPane`; destructor evidence deletes and nulls it.

### What is `0x00544580`?

Resolved as ordinary `Pane::~Pane()` body, not a generic unknown helper. The target source should not manually call it.

### Are StaticTextControlPane vtable cells a blocker?

Resolved as an inherited-base-slot caveat, not a blocker. StaticText derives through TextEditControlPane per RTTI support in [UID:0003LQ], so the shared cells are expected MSVC vtable/destructor reuse.

### Should adjustor thunks be emitted as code?

Resolved no. `0x0049b02f` and `0x0049b03a` are compiler-generated deleting-destructor adjustors for `+0xa0` and `+0xa4` subobject views. Preserve the class layout and virtual destructor declarations; do not write source wrappers.

### Does the target need a split/merge?

No split or merge for [UID:000127]. The range is exact and isolated by `0xcc` padding. A future ordinary destructor child row for `0x00498b90-0x00498bcf` may be useful if the project wants formal C++ at the by-memory level, but that is separate from this target.

## Recommended Target Doc Changes

Update `source-3/project-documentation/by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md` as follows:

1. Change metadata:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:0000EM
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000EM
```

2. Keep the formal target C++ block blank.

3. Replace stale below-95/gate wording with a target-specific no-code proof:

```text
This exact range is MSVC scalar deleting destructor wrapper glue generated from the ordinary `TextEditControlPane::~TextEditControlPane()` source destructor. It takes the compiler deleting-destructor flags byte, restores compiler vptrs, runs the ordinary destructor body, chains `Pane::~Pane()`, and conditionally releases object storage. Do not emit a formal C++ function for this by-memory row; source should define the ordinary destructor and let MSVC regenerate this wrapper.
```

4. Add precise behavior:

- Restores three `TextEditControlPane` vtable pointers at `this+0x00`, `this+0xa0`, and `this+0xa4`.
- Loads `TextEditPane *m_textEditPane` from `this+0x10c`.
- If non-null, calls the child `TextEditPane` virtual deleting destructor with flag `1`, then clears `this+0x10c`.
- Calls ordinary `Pane::~Pane()` at `0x00544580`.
- Reads deleting flags and calls [UID:000197] `OperatorDeleteWrapper` at `0x004f4ac0` only when `(flags & 1) != 0 && (flags & 4) == 0`.
- Takes the flag-4 no-free path through `0x0041b6a0` / `@_guard_check_icall_nop@4`.
- Returns `this`.

5. Add raw/range evidence:

- Body: `0x0049b6c0-0x0049b731`, size `0x71` / 113 bytes.
- Prepad: `0x0049b6bc-0x0049b6c0`, four `0xcc` bytes.
- Postpad: `0x0049b731-0x0049b740`, fifteen `0xcc` bytes.
- Local IDA export names current raw function as `sub_49B6C0(_DWORD *Block, char a2)` and confirms `Block[67] == this+0x10c`, `Block[40] == this+0xa0`, `Block[41] == this+0xa4`.
- Callees: `0x00544580` (`Pane::~Pane()`), `0x0041b6a0` (`@_guard_check_icall_nop@4`), and `0x004f4ac0` ([UID:000197] `OperatorDeleteWrapper`).

6. Reconcile reachability/vtables:

- Primary TextEditControlPane vtable cell: `0x00618100 -> 0x0049b6c0`.
- Inherited StaticTextControlPane primary vtable cell: `0x006181a4 -> 0x0049b6c0`.
- Adjustor thunk `0x0049b02f` subtracts `0xa0` and jumps to this wrapper; it is referenced by TextEdit/StaticText secondary destructor slots.
- Adjustor thunk `0x0049b03a` subtracts `0xa4` and jumps to this wrapper; it is referenced by TextEdit/StaticText tertiary destructor slots.
- StaticTextControlPane vtable refs are inherited TextEditControlPane base slots per RTTI hierarchy evidence, not separate source ownership.

7. Add score rationale:

```text
Score changes from `84/90` to `86/92`: exact body/padding, local IDA export shape, ordinary-helper parity, child field type/offset, base destructor identity, delete flag order, operator-delete callee, guard/no-op path, vtable-only route, adjustor thunk offsets, and StaticText inherited-slot caveat are now resolved. Completion remains below the high-confidence source-body band because the target row is compiler-generated wrapper glue and formal C++ remains intentionally blank; confidence is capped below 95 because live IDA MCP was unavailable and exact original member spelling remains inferred.
```

## Recommended Support Doc Changes

### `by-class/TextEditControlPane.md` [UID:0000EM]

Add or refine a destructor/source-policy section:

```text
Destructor/source policy:
- `TextEditControlPane` owns an embedded `TextEditPane *m_textEditPane` at `+0x10c`.
- The ordinary destructor body deletes `m_textEditPane` and clears the field. The compiler then chains `Pane::~Pane()`.
- [UID:000127] `0x0049b6c0-0x0049b731` is the scalar deleting destructor wrapper for that ordinary destructor and should remain no formal C++.
- The non-deleting helper shape at `0x00498b90-0x00498bcf` in [UID:00011H] is the best by-memory evidence for the source destructor body.
- Compiler vptr stores at `+0x00/+0xa0/+0xa4`, the deleting-destructor flags byte, the flag-4 guard path, and the conditional `OperatorDeleteWrapper` call are generated code, not handwritten source.
```

Recommended draft source snippet for class docs:

```cpp
TextEditControlPane::~TextEditControlPane()
{
    delete m_textEditPane;
    m_textEditPane = NULL;
}
```

### `by-file/TextEditControlPane.md` [UID:0000OM]

Add matching source-file guidance:

```text
The file should emit the ordinary `TextEditControlPane::~TextEditControlPane()` source body, not the scalar deleting wrapper at [UID:000127] and not the adjustor thunks at `0x0049b02f/0x0049b03a`. The compiler regenerates wrapper glue from the virtual destructor declaration and class layout.
```

### `by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md` [UID:00011H]

Refine the `0x00498b90-0x00498bcf` destructor-helper row:

```text
`0x00498b90-0x00498bcf` is the non-deleting ordinary `TextEditControlPane::~TextEditControlPane()` body as lowered by MSVC: restore class vptrs, delete owned `TextEditPane *m_textEditPane` at `+0x10c`, clear it, and tail into ordinary `Pane::~Pane()` at `0x00544580`. The corresponding scalar deleting wrapper is [UID:000127].
```

If support docs need C++, place the first-draft ordinary destructor snippet here or in the class doc, not in [UID:000127].

### `by-memory/0x00498dd0-0x00499021.TextControlSharedStateAndBorderHelpers.md` [UID:0003LQ]

No urgent change if current RTTI evidence already appears. If touched, preserve or add the destructor-specific implication:

```text
The StaticTextControlPane vtable cells pointing at [UID:000127] and its adjustor thunks are inherited TextEditControlPane base destructor slots according to the RTTI hierarchy (`StaticTextControlPane` -> `TextEditControlPane` -> ...). They are not independent StaticText source destructor ownership.
```

### `by-class/StaticTextControlPane.md` [UID:0000E3]

Add a caveat or refine existing destructor/vtable wording:

```text
StaticTextControlPane uses inherited TextEditControlPane destructor slots in its vtables (`0x006181a4`, `0x0061820c`, `0x0061823c`). Current evidence does not require a separate StaticText destructor body for the shared TextEditControlPane cleanup; [UID:000127] remains owned by TextEditControlPane.
```

### `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md` [UID:00011Y]

Refine aggregate rows for this region:

```text
`0x0049b02f-0x0049b045` are compiler-generated TextEditControlPane deleting-destructor adjustor thunks for `+0xa0/+0xa4` subobject views, also referenced by inherited StaticTextControlPane vtable slots.
`0x0049b6c0-0x0049b731` is [UID:000127], the TextEditControlPane scalar deleting destructor wrapper; StaticTextControlPane vtable refs are inherited base-slot reuse, not mixed source ownership.
```

No support doc should emit the adjustor thunks as handwritten C++.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` in the B-agent pass. Supervisor-owned replacement row recommendation:

```text
    - [UID:000127][0x0049b6c0-0x0049b731.TextEditControlPaneDestructor](by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md) 0x0049b6c0-0x0049b731 | compiler-generated destructor wrapper | TextEditControlPaneDestructor : reconstructable : 86% : very-strong : B009 source-quality recheck classifies this exact range as the MSVC scalar deleting destructor wrapper generated from `TextEditControlPane::~TextEditControlPane()`: local IDA export confirms exact `0x71` / 113-byte body, four-byte prepad, fifteen-byte postpad, three TextEditControlPane vtable restores, owned `TextEditPane *m_textEditPane` at `+0x10c` deleted through its virtual deleting destructor and nulled, base teardown through ordinary `Pane::~Pane()` at `0x00544580`, `OperatorDeleteWrapper` only for `(flags & 1) != 0 && (flags & 4) == 0`, flag-4 path through `@_guard_check_icall_nop@4`, vtable-only reachability from TextEdit primary slot `0x00618100`, inherited StaticText primary slot `0x006181a4`, and secondary/tertiary adjustor thunks `0x0049b02f/0x0049b03a` for `+0xa0/+0xa4`; formal target C++ should remain blank because source should express the ordinary destructor and let MSVC regenerate wrapper/thunks.
```

## IDA Rename, Type, And Comment Recommendations

High-confidence renames/comments:

- `sub_49B6C0` -> `TextEditControlPane_scalar_deleting_destructor` or IDA/MSVC style ``TextEditControlPane::`scalar deleting destructor'``.
- Add comment at `0x0049b6c0`: "Compiler-generated scalar deleting destructor wrapper for `TextEditControlPane::~TextEditControlPane()`; formal source should define ordinary destructor only."
- `sub_498B90` -> `TextEditControlPane_ordinary_destructor_body` or `TextEditControlPane__dtor`.
- Field at `TextEditControlPane+0x10c` -> `TextEditPane *m_textEditPane`.
- `sub_544580` -> `Pane__dtor` / ``Pane::~Pane`` ordinary destructor body.
- `sub_4F4AC0` should remain linked to [UID:000197] `OperatorDeleteWrapper`.
- `sub_49B02F` -> `TextEditControlPane_dtor_adjustor_a0` or ``TextEditControlPane::`scalar deleting destructor' adjustor +0xa0``; comment as compiler-generated no-code thunk.
- `sub_49B03A` -> `TextEditControlPane_dtor_adjustor_a4` or ``TextEditControlPane::`scalar deleting destructor' adjustor +0xa4``; comment as compiler-generated no-code thunk.
- `0x0041b6a0` comment should reference `@_guard_check_icall_nop@4`, one-byte runtime no-op helper.

Vtable comments:

- `0x00618100`: TextEditControlPane primary scalar deleting destructor slot -> `0x0049b6c0`.
- `0x00618168`: TextEditControlPane secondary adjusted destructor slot -> `0x0049b02f`.
- `0x00618198`: TextEditControlPane tertiary adjusted destructor slot -> `0x0049b03a`.
- `0x006181a4`: StaticTextControlPane inherited TextEditControlPane primary destructor slot -> `0x0049b6c0`.
- `0x0061820c`: StaticTextControlPane inherited TextEditControlPane secondary adjusted destructor slot -> `0x0049b02f`.
- `0x0061823c`: StaticTextControlPane inherited TextEditControlPane tertiary adjusted destructor slot -> `0x0049b03a`.

Confidence notes:

- Type/offset `TextEditPane *m_textEditPane` at `+0x10c`: high confidence for type and ownership, medium-high for exact original member spelling.
- Adjustor thunk purpose and offsets: high confidence.
- StaticText inherited-slot explanation: high confidence from current support RTTI documentation; exact vtable label spelling still depends on IDA naming state.

## Validation Commands For Supervisor Callback

Run only for files actually edited during implementation, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [000127-TextEditControlPaneDestructor-source-quality-removed.md](000127-TextEditControlPaneDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: validator completes without schema/metadata errors after scoped docs are edited. This report pass did not run these validators because it did not edit by-* docs.

## Implementation Instructions For Supervisor Callback

1. Lease all target/support docs before editing. Do not edit `by-memory/-coverage-report.md`; use the replacement row above in supervisor-owned coverage work.

2. Update target [UID:000127] `by-memory/0x0049b6c0-0x0049b731.TextEditControlPaneDestructor.md`:
   - Change `COMPLETION` to `86`.
   - Change `CONFIDENCE` to `92`.
   - Keep `CANONICAL_OWNER:0000EM`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000EM`.
   - Keep formal C++ blank.
   - Replace stale gate/no-code wording with the target-specific scalar deleting destructor no-code proof.
   - Add the exact field/callee/flag behavior listed in this report.
   - Add exact body/padding and local IDA export evidence.
   - Reframe StaticTextControlPane vtable use as inherited TextEditControlPane base-slot reuse.
   - Add score rationale `84/90 -> 86/92`.

3. Update [UID:0000EM] `by-class/TextEditControlPane.md`:
   - Add destructor source policy.
   - Confirm `TextEditPane *m_textEditPane` at `+0x10c`.
   - Include or reference first-draft ordinary destructor C++:
     ```cpp
     TextEditControlPane::~TextEditControlPane()
     {
         delete m_textEditPane;
         m_textEditPane = NULL;
     }
     ```
   - State that [UID:000127] and `0x0049b02f/0x0049b03a` are compiler-generated no-code wrapper/thunks.

4. Update [UID:0000OM] `by-file/TextEditControlPane.md`:
   - Record that the file should emit ordinary `TextEditControlPane::~TextEditControlPane()` only; compiler regenerates scalar deleting wrapper and adjustors.

5. Update [UID:00011H] `by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md` if accepted:
   - Refine `0x00498b90-0x00498bcf` as the non-deleting ordinary destructor body.
   - Cross-link [UID:000127] as the scalar deleting wrapper.

6. Update [UID:0003LQ] and/or [UID:0000E3] only if current wording remains ambiguous:
   - Preserve RTTI proof that StaticTextControlPane derives through TextEditControlPane.
   - Clarify that StaticText destructor vtable refs to [UID:000127] are inherited base-slot reuse.

7. Update [UID:00011Y] aggregate row only if touched:
   - Change ambiguous "TextEditControlPane / StaticTextControlPane shared scalar deleting destructor" wording to "TextEditControlPane scalar deleting destructor wrapper, referenced by inherited StaticTextControlPane vtable slots."
   - Keep adjustor thunks no-code.

8. Run scoped validators for edited files using the commands above. Record validation results in `Agent-B009/notes.md` if implementation callback requires notes.

9. Record the pending coverage row exactly as provided above in notes/report. Do not apply it unless supervisor explicitly owns or delegates coverage-report editing.

## Final Recommendation

[UID:000127] is implementation-ready as a documentation update, not as a formal target C++ emission. The correct source strategy is:

- Emit/document the ordinary `TextEditControlPane::~TextEditControlPane()` body at class/file or ordinary-helper support level.
- Keep the scalar deleting destructor wrapper [UID:000127] blank formal C++ with no-code proof.
- Keep adjustor thunks blank/no-code.
- Preserve owner/emitter [UID:0000EM].
- Raise score to `86/92`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/000127-TextEditControlPaneDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"000127"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000127-TextEditControlPaneDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/000127-TextEditControlPaneDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000127"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
