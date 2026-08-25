** TARGET-REPORT-UID:0003MA **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003MA **
# Agent-B002 source-routing report: [UID:0003MA] ObjectImageButtonPaneScalarDeletingDestructor

## Report-only status

- Assignment: B002 report-only source-routing / source-quality pass.
- Target: `source-3/project-documentation/by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing.md`
- Report created: 2026-06-19.
- Direct by-* edits made: none.
- `by-memory/-coverage-report.md` edits made: none.

## Executive recommendation

Keep [UID:0003MA] as non-reconstructable compiler-generated C++ ABI glue with no emitted source body:

```yaml
COMPLETION: 86
CONFIDENCE: 92
CANONICAL_OWNER: NONE
RECONSTRUCTABLE: FALSE
EMITTER_UIDS:
```

The semantic class/source family is `ObjectImageButtonPane`, routed through [UID:0000M3] `ObjectImageControlPane` / `NexusTK/ui/controls/ObjectImageControlPane.cpp`, but the exact `0x00520c60-0x00520c9b` bytes are a Microsoft C++ scalar deleting destructor wrapper. They should not emit first-draft C++ from this by-memory target.

The source-facing declaration implication is: `ObjectImageButtonPane` has an implicit/default virtual destructor through its base class. If the reconstructed headers explicitly list destructors for pane subclasses, the source-level declaration may contain an empty/default `virtual ~ObjectImageButtonPane();`, but this target itself remains no-code compiler glue.

## Evidence checked

### Required project instructions

- Read `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`.
- Read `.codex/AGENTS.md`.
- Read `source-3/project-documentation/tools/leaser/Agents/Agent-B002/goal.md`.
- Read `source-3/project-documentation/by-structure.md`.
- Read `source-3/project-documentation/inference_research.md`.
- Per B-agent rules, did not use Wave3/simroot source as evidence.

### Primary and support docs checked

- `by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md`
- `by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md`
- `by-class/ObjectImageButtonPane.md`
- `by-class/ObjectImageControlPane.md`
- `by-file/ObjectImageControlPane.md`
- `by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md`
- `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
- `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`
- `by-file/SpecializedButtonPanes.md`
- `by-type/by-vtable/SpecializedButtonPaneVtables.md`
- `tools/leaser/Agents/Agent-B008/research/0001BU-ObjectImageControlPane-source-quality.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `by-class/-coverage-report.md`

### Local binary evidence

Binary used for byte/disassembly checks:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- Relevant sections:
  - `.text`: `0x00401000-0x0060c600`, raw `0x00000400-0x0020ba00`
  - `.rdata`: `0x0060d000-0x0066c200`, raw `0x0020ba00-0x0026ac00`

IDA MCP at `127.0.0.1:13337` was unavailable during this pass, so the report relies on local PE bytes plus existing live-IDA-backed documentation. This does not block the target recommendation because the wrapper bytes, vtable pointers, immediate references, and relative-branch evidence are all directly recoverable from the local executable.

## Exact wrapper bytes and boundaries

Target range:

- Start: `0x00520c60`
- End: `0x00520c9b` half-open
- Size: `0x3b` / 59 bytes
- Following padding: `0x00520c9b-0x00520ca0`, five `0xcc` bytes

Bytes:

```text
55 8b ec 56 8b f1 e8 15 39 02 00 8b 45 08 a8 01 74 22
a8 04 75 10 56 e8 44 3e fd ff 83 c4 04 8b c6 5e 5d c2
04 00 68 50 01 00 00 56 e8 0f aa ef ff 83 c4 08 8b c6
5e 5d c2 04 00
```

Disassembly:

```asm
00520c60  push ebp
00520c61  mov  ebp, esp
00520c63  push esi
00520c64  mov  esi, ecx
00520c66  call 0x00544580
00520c6b  mov  eax, [ebp+0x08]
00520c6e  test al, 0x01
00520c70  je   0x00520c94
00520c72  test al, 0x04
00520c74  jne  0x00520c86
00520c76  push esi
00520c77  call 0x004f4ac0
00520c7c  add  esp, 0x04
00520c7f  mov  eax, esi
00520c81  pop  esi
00520c82  pop  ebp
00520c83  ret  0x04
00520c86  push 0x150
00520c8b  push esi
00520c8c  call 0x0041b6a0
00520c91  add  esp, 0x08
00520c94  mov  eax, esi
00520c96  pop  esi
00520c97  pop  ebp
00520c98  ret  0x04
```

Source-facing ABI shape:

```cpp
// Compiler-generated ABI wrapper only; do not emit in source docs.
ObjectImageButtonPane *__thiscall
ObjectImageButtonPane::`scalar deleting destructor'(unsigned int flags);
```

The wrapper returns `this` in `eax` on all paths and consumes the `flags` argument with `ret 4`, matching the MSVC scalar deleting destructor ABI.

## Flag semantics and delete-helper roles

Resolved behavior:

- `0x00544580`: inherited pane/control teardown called before optional storage deletion. Existing decompiler labels that route this through unrelated `TextButtonExControlPane` or generic `Pane` names are generated-name/owner pollution. The best source-facing role is shared inherited `Pane`/`ControlPane` teardown.
- `flags & 1`: storage deletion requested. If absent, the wrapper only runs teardown and returns `this`.
- `flags & 4`: guarded/sized/vector-delete ABI branch. This path pushes `0x150` and `this` before calling `0x0041b6a0`.
- `0x004f4ac0`: ordinary MemoryMan-backed `operator delete` / free wrapper used by the common scalar-delete path.
- `0x0041b6a0`: guarded sized/vector-delete helper used when `flags & 4` is set; not a source-level `ObjectImageButtonPane` method.
- `0x150`: object size in the guarded delete path, i.e. 336 decimal.

The `0x150` size is important class-layout evidence. The sibling plain `ObjectImageControlPane` scalar deleting destructor at `0x00520ca0-0x00520cdb` uses the same wrapper shape with size `0x14c`; this target uses `0x150`, matching a button subclass that extends the base preview control by at least the highlight/overlay state byte at `+0x14c` with alignment.

## Vtable and thunk route

`ObjectImageButtonPane` vtable evidence in `.rdata`:

- Primary RTTI/COL pointer: `0x0061f760 -> 0x0064c0b0`
- Primary vtable head: `0x0061f764`
- Primary destructor slot: `0x0061f764 -> 0x00520c60`
- Paint slot observed in this family: `0x0061f7a8 -> 0x00520910`
- Type-code slot observed in this family: `0x0061f7c4 -> 0x004242f0`
- Secondary vtable head: `0x0061f7cc`
- Secondary destructor adjustor slot: `0x0061f7cc -> 0x00520ae7`
- `OnKeyPress` slot observed in this family: `0x0061f7d4 -> 0x00520870`
- Tertiary vtable head: `0x0061f7fc`
- Tertiary destructor adjustor slot: `0x0061f7fc -> 0x00520af2`

Constructor stores confirm these vtable heads:

- `0x0061f764` pointer stored from `0x00520837`
- `0x0061f7cc` pointer stored from `0x00520843`
- `0x0061f7fc` pointer stored from `0x0052084d`

Direct pointer hits for this target:

- `0x00520c60` has one direct VA pointer hit: `0x0061f764`.
- `0x00520ae7` has one direct VA pointer hit: `0x0061f7cc`.
- `0x00520af2` has one direct VA pointer hit: `0x0061f7fc`.

Relative-branch hits to this target:

- `0x00520aed`: jump from first adjustor thunk to `0x00520c60`.
- `0x00520af8`: jump from second adjustor thunk to `0x00520c60`.

[UID:0003M9] exact thunk bytes:

```asm
; 0x00520ae7-0x00520af2, size 0x0b / 11
00520ae7  sub ecx, 0x0a0
00520aed  jmp 0x00520c60

; 0x00520af2-0x00520afd, size 0x0b / 11
00520af2  sub ecx, 0x0a4
00520af8  jmp 0x00520c60
```

This establishes that [UID:0003MA] is the primary scalar deleting destructor target, while [UID:0003M9] contains secondary/tertiary `this`-adjustor thunk entries that feed the same wrapper.

## Relationship to ObjectImageControlPane sibling wrapper

Sibling plain-control wrapper:

- `ObjectImageControlPane` scalar deleting destructor: `0x00520ca0-0x00520cdb`
- Size: `0x3b` / 59 bytes
- Same structure:
  - call `0x00544580`
  - check `flags & 1`
  - ordinary free through `0x004f4ac0`
  - guarded path through `0x0041b6a0`
- Key difference: guarded size immediate is `0x14c`, not `0x150`.

This sibling comparison supports these inferences:

- `0x00544580` is shared base pane/control teardown, not a target-specific destructor body.
- `0x004f4ac0` and `0x0041b6a0` are allocator/delete helpers, not source methods on either object-image class.
- `ObjectImageButtonPane` is a true derived class with a larger runtime size than `ObjectImageControlPane`.
- Both wrappers are compiler-generated from the source class declarations under the object-image control source family.

## Source owner and placement

Best source-family route:

- Source class: `ObjectImageButtonPane`
- Class page: `by-class/ObjectImageButtonPane.md`
- Source file owner/emitter family: [UID:0000M3] `ObjectImageControlPane`
- Source path: `NexusTK/ui/controls/ObjectImageControlPane.cpp`

Rejected alternatives:

- `SpecializedButtonPanes.cpp`: rejected as primary owner. The file has historical/provisional references to the object-image button range, but the stronger evidence is immediate derivation from `ObjectImageControlPane`, adjacent construction/destruction, object-status image descriptor dependency, and the current `by-file/ObjectImageControlPane.md` routing.
- `Effects` / runtime cluster / no-family: rejected. The target is a pane destructor wrapper tied directly to object-image pane vtables and constructor stores, not an effect/runtime helper.
- `MenuDialogDestructorThunks` as source owner: rejected for source emission. [UID:0001BX] is only the mixed physical compiler-generated destructor/thunk island that surrounds this exact child range.
- Target-level owner/emitter assignment: rejected. Although the semantic class is known, the exact by-memory page is no-code compiler ABI glue, so `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS` remain the cleanest metadata.

## No-code proof

Do not emit first-draft C++ for [UID:0003MA].

Proof:

- The function has exact scalar deleting destructor signature shape: `this` in `ecx`, `flags` at `[ebp+8]`, returns `this`, `ret 4`.
- There is no source-facing logic beyond inherited teardown plus optional allocator helper calls selected by compiler ABI flags.
- The only direct data reference to `0x00520c60` is the primary `ObjectImageButtonPane` vtable slot at `0x0061f764`.
- The only direct code references to `0x00520c60` are the two generated adjustor thunks at `0x00520ae7` and `0x00520af2`.
- The `flags & 4` branch is an ABI delete-helper branch with object size `0x150`, not user-authored class logic.
- A source reconstruction should regenerate this wrapper from the class declaration and destructor/vtable layout, not from handwritten source under this target.

The valid source-facing note is class-level only:

```cpp
// Class-level declaration/source-shape implication only.
// This should live with ObjectImageButtonPane, not in the scalar wrapper target.
class ObjectImageButtonPane : public ObjectImageControlPane {
    // Implicit/default virtual destructor is sufficient if local source style allows it.
    // If pane subclasses explicitly declare destructors, use an empty/default destructor declaration.
};
```

For VC-era source style without `= default`, an explicitly declared empty destructor would still be a class/source-file decision, not target C++ for [UID:0003MA].

## Heuristic issues resolved

| Issue | Resolution |
| --- | --- |
| Exact wrapper boundary | Resolved: `0x00520c60-0x00520c9b`, size `0x3b`; followed by five `0xcc` bytes through `0x00520ca0`. |
| Compiler-generated name pollution | Resolved: use `ObjectImageButtonPane::scalar deleting destructor` only as ABI label; do not preserve raw `sub_520C60` in source-facing docs except as evidence. |
| Base teardown helper | Resolved high-confidence: `0x00544580` is shared inherited Pane/ControlPane teardown. Avoid unrelated `TextButtonExControlPane` owner labels. |
| Ordinary free helper | Resolved high-confidence: `0x004f4ac0` is MemoryMan/operator-delete style free wrapper. |
| `flags & 4` helper | Resolved high-confidence: `0x0041b6a0(this, 0x150)` is guarded sized/vector-delete helper path generated by compiler ABI. |
| Source owner | Resolved: semantic source family is `ObjectImageButtonPane` under [UID:0000M3] `ObjectImageControlPane.cpp`; target metadata stays ownerless/non-emitting. |
| Relationship to [UID:0003M9] | Resolved: [UID:0003M9] holds two 11-byte `this`-adjustor thunks subtracting `0xa0` and `0xa4` before tail-jumping to this scalar wrapper. |
| Class destructor implication | Resolved: no handwritten target body; class may rely on implicit/default virtual destructor or explicit empty destructor if local header style demands declarations. |
| Object size | Resolved: button wrapper uses `0x150` bytes, four bytes larger than sibling plain control wrapper size `0x14c`. |
| Support-doc routing | Resolved: update target plus [UID:0003M9], `ObjectImageButtonPane`, `ObjectImageControlPane`, object-image file doc, and vtable/read-only-data docs as support; do not route source to `SpecializedButtonPanes`. |

## Remaining uncertainty

No blocker remains for target routing or no-code proof.

Only two implementation-time uncertainties remain:

- The exact local source name for `0x00544580` may vary across support docs. Recommended wording is role-based unless/until the broader Pane/ControlPane destructor docs assign a canonical helper name.
- The exact source declaration style for empty/default virtual destructors should follow the local reconstructed header style once `ObjectImageButtonPane` source is emitted. This does not affect [UID:0003MA] because the by-memory wrapper remains no-code.

## Recommended target doc changes

Update `by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md`:

1. Change score metadata:

```text
COMPLETION:86
CONFIDENCE:92
```

2. Keep source metadata:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

3. Replace the current thin summary with exact no-code language:

- `0x00520c60-0x00520c9b` is the 59-byte MSVC scalar deleting destructor wrapper for `ObjectImageButtonPane`.
- It is reached from primary vtable slot `0x0061f764` and from the two [UID:0003M9] adjustor thunks.
- It calls inherited pane/control teardown `0x00544580`.
- It checks `flags & 1` for storage deletion.
- Ordinary free path calls `0x004f4ac0(this)`.
- `flags & 4` path calls `0x0041b6a0(this, 0x150)`.
- It returns `this` on all paths.
- It is source-generated from class destructor/vtable layout and should not contain formal target C++.

4. Add exact bytes/disassembly section from this report.

5. Add vtable route section:

- `0x0061f764 -> 0x00520c60`
- `0x0061f7cc -> 0x00520ae7 -> 0x00520c60`
- `0x0061f7fc -> 0x00520af2 -> 0x00520c60`

6. Add generated-name cleanup note:

- Prefer `ObjectImageButtonPane::scalar deleting destructor` / `ObjectImageButtonPaneScalarDeletingDestructor`.
- Do not promote raw `sub_520C60`.
- Do not let `TextButtonExControlPane` or generic decompiler owner labels take ownership of `0x00544580`.

7. Leave `RECONSTRUCTION_CPP` blank with explicit proof that this is no-code compiler glue.

## Recommended support-doc changes

### `by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md`

Add the exact thunk evidence:

- First thunk `0x00520ae7-0x00520af2`, 11 bytes: `sub ecx, 0xa0; jmp 0x00520c60`.
- Second thunk `0x00520af2-0x00520afd`, 11 bytes: `sub ecx, 0xa4; jmp 0x00520c60`.
- Vtable cells: `0x0061f7cc` and `0x0061f7fc`.
- These are secondary/tertiary destructor adjustors for `ObjectImageButtonPane`, not source methods.
- Recommended score: `COMPLETION:86`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, owner/emitter blank.

### `by-class/ObjectImageButtonPane.md`

Add or refresh a source-routing/destructor section:

- The class destructor is represented in binary by generated glue:
  - [UID:0003M9] adjustor thunks at `0x00520ae7-0x00520afd`.
  - [UID:0003MA] scalar deleting destructor at `0x00520c60-0x00520c9b`.
- The wrapper uses object size `0x150`, confirming the button subclass is larger than plain `ObjectImageControlPane` size `0x14c`.
- The derived class has no observed source-authored destructor body; implicit/default virtual destructor is sufficient unless local header style explicitly lists destructors.
- Keep source family routed through [UID:0000M3] `ObjectImageControlPane`, not `SpecializedButtonPanes`.
- Preserve core methods:
  - `GetPaneTypeCode` at `0x004242f0-0x004242f4`, returns `11`.
  - Constructor/key/paint/highlight core at [UID:0001BV] `0x00520820-0x00520a90`.
- Do not add target-level C++ for [UID:0003MA].

Optional score if these details and the B008 descriptor findings are incorporated: raise class confidence to `85/88` or `86/88`. If only the destructor routing note is added, keeping `85/86` is also defensible.

### `by-class/ObjectImageControlPane.md`

Add sibling comparison:

- Plain control scalar deleting destructor at `0x00520ca0-0x00520cdb` mirrors [UID:0003MA] but uses size `0x14c`.
- Button scalar deleting destructor uses size `0x150`, matching subclass extension.
- Both wrappers share teardown `0x00544580` and delete helpers `0x004f4ac0` / `0x0041b6a0`.

### `by-file/ObjectImageControlPane.md`

Refresh file/source routing:

- `ObjectImageButtonPane` belongs in `NexusTK/ui/controls/ObjectImageControlPane.cpp` beside the reusable object-image preview control.
- The exact generated destructor ranges are support/no-code only:
  - [UID:0003M9] `0x00520ae7-0x00520afd`
  - [UID:0003MA] `0x00520c60-0x00520c9b`
- Do not create a `SpecializedButtonPanes.cpp` or `ObjectImageButtonPane.cpp` split solely for this destructor wrapper.

### `by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md`

Add/refresh the split note:

- The source-bearing button core ends at `0x00520a90`.
- Destructor adjustors/scalar wrapper are exact compiler-generated child pages, not part of the source-bearing method cluster:
  - [UID:0003M9] `0x00520ae7-0x00520afd`
  - [UID:0003MA] `0x00520c60-0x00520c9b`
- The old broad `0x00520820-0x00520c9a` range should stay retired because it crossed mixed menu/dialog destructor glue.

### `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`

Add a child-boundary note if not already explicit:

- [UID:0003M9] and [UID:0003MA] are exact object-image button child pages inside/adjacent to the physical destructor island.
- They are not menu-dialog source methods and should not be emitted from the mixed island.

### `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`

Add the exact object-image button vtable route if not already present:

- `0x0061f760 -> 0x0064c0b0` RTTI/COL pointer.
- `0x0061f764 -> 0x00520c60` primary scalar deleting destructor slot.
- `0x0061f7cc -> 0x00520ae7` secondary destructor adjustor slot.
- `0x0061f7fc -> 0x00520af2` tertiary destructor adjustor slot.
- These vtables should regenerate from `ObjectImageButtonPane` class declaration/source family [UID:0000M3], not from the read-only-data aggregate.

### `by-file/SpecializedButtonPanes.md`

If this file still lists the object-image button family as an owned/source row, downgrade that wording to historical/provisional cross-reference:

- `ObjectImageButtonPane` source family is [UID:0000M3] `ObjectImageControlPane`.
- `SpecializedButtonPanes` may mention the range only as an adjacent/historical route that was superseded by object-image inheritance and vtable evidence.
- If it references the scalar destructor endpoint, use half-open `0x00520c60-0x00520c9b`.

### `by-memory/-ignored.md`

If the ignored ledger requires exact compiler-glue entries, add or refresh:

- `0x00520ae7-0x00520afd`: `ObjectImageButtonPane` secondary/tertiary destructor adjustor thunks; subtract `0xa0`/`0xa4`, tail-jump to [UID:0003MA].
- `0x00520c60-0x00520c9b`: `ObjectImageButtonPane` scalar deleting destructor wrapper; calls inherited teardown and optional delete helpers; no source body.

## IDA rename/type/comment recommendations

### Function names

- `0x00520c60`: `ObjectImageButtonPane_scalar_deleting_destructor` or `ObjectImageButtonPane::`scalar deleting destructor''`.
  - Confidence: high.
  - Source-facing note: ABI/generated name only; do not emit as handwritten source.
- `0x00520ae7`: `ObjectImageButtonPane_dtor_adjustor_a0`.
  - Confidence: high.
- `0x00520af2`: `ObjectImageButtonPane_dtor_adjustor_a4`.
  - Confidence: high.
- `0x00544580`: `Pane_or_ControlPane_teardown` until broader base destructor docs assign a canonical name.
  - Confidence: medium-high for role, low for exact final source name.
- `0x004f4ac0`: `operator_delete_or_MemoryMan_free`.
  - Confidence: medium-high for role, medium for exact final source name.
- `0x0041b6a0`: `guarded_sized_vector_delete_helper`.
  - Confidence: medium-high for role, medium for exact final source name.

### Type/signature suggestions

```cpp
ObjectImageButtonPane *__thiscall
ObjectImageButtonPane_scalar_deleting_destructor(ObjectImageButtonPane *this, unsigned int flags);
```

```cpp
void __thiscall Pane_or_ControlPane_teardown(void *this);
```

```cpp
void __cdecl operator_delete_or_MemoryMan_free(void *ptr);
```

```cpp
void __cdecl guarded_sized_vector_delete_helper(void *ptr, unsigned int objectSize);
```

### Comments

Suggested comment at `0x00520c60`:

```text
MSVC scalar deleting destructor for ObjectImageButtonPane. Primary vtable slot 0x0061f764; secondary adjustor thunks at 0x00520ae7/0x00520af2. Calls inherited Pane/ControlPane teardown 0x00544580, then optional delete helpers based on flags. flags&4 path passes size 0x150. Compiler glue; no source body.
```

Suggested comment at `0x00520ae7`:

```text
ObjectImageButtonPane destructor adjustor thunk: subtracts 0xa0 from secondary-base this pointer, then jumps to scalar deleting destructor 0x00520c60.
```

Suggested comment at `0x00520af2`:

```text
ObjectImageButtonPane destructor adjustor thunk: subtracts 0xa4 from tertiary-base this pointer, then jumps to scalar deleting destructor 0x00520c60.
```

## Exact implementation checklist

If supervisor accepts this report, implement in this order:

1. Update target page `by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md`.
   - Set `COMPLETION:86`, `CONFIDENCE:92`.
   - Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
   - Add exact bytes/disassembly.
   - Add flag/delete-helper behavior.
   - Add vtable/thunk route.
   - Add explicit no-code proof.

2. Update [UID:0003M9] `by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md`.
   - Add exact 11-byte thunk disassembly and vtable cells.
   - Record subtract amounts `0xa0` and `0xa4`.
   - Keep no-code compiler-generated status.

3. Update support docs:
   - `by-class/ObjectImageButtonPane.md`
   - `by-class/ObjectImageControlPane.md`
   - `by-file/ObjectImageControlPane.md`
   - `by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md`
   - `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
   - `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`
   - `by-file/SpecializedButtonPanes.md` only if it still implies primary ownership.
   - `by-memory/-ignored.md` only if the ignored ledger is maintained for exact compiler glue.

4. Do not add formal C++ for [UID:0003MA].

5. Do not run autogen for this target unless an accepted implementation also changes reconstructable C++ blocks elsewhere. The scalar wrapper itself is no-code and should not generate source.

6. Do not edit `by-memory/-coverage-report.md`; supervisor applies exact pending rows from this report.

## Exact pending coverage text

Do not apply directly in this B-agent report-only pass.

### Minimal required target row

```text
    - [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md) 0x00520c60-0x00520c9b | compiler-generated scalar deleting destructor | ObjectImageButtonPaneScalarDeletingDestructor : ignored : 86% : very-strong : B002 local PE byte audit confirms exact 0x3b/59-byte MSVC scalar deleting destructor; primary vtable slot 0x0061f764, adjustor thunk branches from 0x00520ae7/0x00520af2, inherited Pane/ControlPane teardown call 0x00544580, flags&1/flags&4 optional delete paths through 0x004f4ac0 or 0x0041b6a0(this, 0x150), returns this, and is no-code compiler glue generated from ObjectImageButtonPane class layout under the ObjectImageControlPane source family.
```

### Adjacent recommended memory coverage rows

```text
    - [UID:0001BV][0x00520820-0x00520a90.ObjectImageButtonPaneCore](by-memory/0x00520820-0x00520a90.ObjectImageButtonPaneCore.md) 0x00520820-0x00520a90 | class-method-cluster | ObjectImageButtonPaneCore : reconstructable : 85% : strong : Source-bearing ObjectImageButtonPane constructor, OnKeyPress, OnPaint, and highlight setter core under [UID:0000M3] ObjectImageControlPane; old broad 0x00520820-0x00520c9a range retired because destructor adjustors/scalar wrappers are split into exact compiler-generated child pages [UID:0003M9] and [UID:0003MA].
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00520a90-0x00520aa5 | padding | ObjectImageButtonPaneCore-to-dialog-destructor-thunk alignment : ignored : 100% : strong : Confirmed alignment gap after the ObjectImageButtonPane source-bearing core and before shared dialog destructor thunk glue.
    - [UID:0003M9][0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks](by-memory/0x00520ae7-0x00520afd.ObjectImageButtonPaneDestructorThunks.md) 0x00520ae7-0x00520afd | compiler-generated destructor adjustor thunks | ObjectImageButtonPaneDestructorThunks : ignored : 86% : very-strong : B002 local PE byte audit confirms two 0x0b/11-byte adjustor thunks; vtable cells 0x0061f7cc and 0x0061f7fc subtract 0xa0/0xa4 from ecx and tail-jump to [UID:0003MA] 0x00520c60; no source C++.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00520c5b-0x00520c60 | padding | shared-list scalar destructor to ObjectImageButtonPane scalar deleting destructor alignment : ignored : 100% : strong : Confirmed five 0xcc bytes immediately before [UID:0003MA].
    - [UID:0003MA][0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor](by-memory/0x00520c60-0x00520c9b.ObjectImageButtonPaneScalarDeletingDestructor.md) 0x00520c60-0x00520c9b | compiler-generated scalar deleting destructor | ObjectImageButtonPaneScalarDeletingDestructor : ignored : 86% : very-strong : B002 local PE byte audit confirms exact 0x3b/59-byte MSVC scalar deleting destructor; primary vtable slot 0x0061f764, adjustor thunk branches from 0x00520ae7/0x00520af2, inherited Pane/ControlPane teardown call 0x00544580, flags&1/flags&4 optional delete paths through 0x004f4ac0 or 0x0041b6a0(this, 0x150), returns this, and is no-code compiler glue generated from ObjectImageButtonPane class layout under the ObjectImageControlPane source family.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00520c9b-0x00520ca0 | padding | ObjectImageButtonPane scalar deleting destructor to ObjectImageControlPane scalar deleting destructor alignment : ignored : 100% : strong : Confirmed five 0xcc bytes immediately after [UID:0003MA].
```

### Optional class coverage replacement row

If `by-class/ObjectImageButtonPane.md` is updated with this routing evidence, replace the stale class coverage row with:

```text
- [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) : reconstructable : 85% : strong : ObjectImageButtonPane source-family child under [UID:0000M3] ObjectImageControlPane; source-bearing core is [UID:0001BV], generated destructor adjustors/scalar wrapper are split into [UID:0003M9]/[UID:0003MA], object size evidence is 0x150 versus 0x14c for the base preview control, and no destructor wrapper C++ should be emitted.
```

## Validation commands for accepted implementation

Run from `source-3/project-documentation` after any accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing-removed.md](0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Autogen/rescore:

- Not required for this target alone because [UID:0003MA] remains `RECONSTRUCTABLE:FALSE` with blank C++.
- If an accepted follow-up also adds source C++ to [UID:0001BV] or class-level docs that feed generated source, run the local autogen/rescore workflow for [UID:0000M3] `ObjectImageControlPane`.

## First-draft C++ readiness

For [UID:0003MA] specifically: no first-draft C++ should be emitted.

Readiness status: implementation-ready as a no-code compiler-glue page. The report resolves boundaries, vtable route, flag semantics, helper roles, source-family routing, and exact support updates. The target is ready for documentation implementation if supervisor accepts the no-code/scalar-wrapper recommendation.

FINISHED `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003MA","source_path":"executed-b-agent-research/B002/0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
