** TARGET-REPORT-UID:0001D4 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001D4 ObjectListScalarDeletingDestructor Source-Quality Research

Assignment: Agent-B003 report-only source-quality / heuristic research for [UID:0001D4] `ObjectListScalarDeletingDestructor`.

Target: [UID:0001D4] `source-3/project-documentation/by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md`

Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0001D4-ObjectListScalarDeletingDestructor-source-quality.md`

This is report-only research. I did not edit the target, support `by-*` docs, generated reports, generated source, IDA database, or `by-memory/-coverage-report.md`.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0001D4] reconstructable, but treat it as a class-owned source-declared/generated-binary MSVC scalar deleting destructor wrapper. Route it through [UID:00009Q][ObjectList](by-class/ObjectList.md), not directly through the by-file page.
- Final disposition: class-owned reconstructable wrapper marker, not non-emitting ignored glue and not a hand-authored source method.
- Required action: update metadata from `84/90`, owner/emitter `0000M4` to `86/92`, owner/emitter `00009Q`; replace stale old-gate and direct-file route wording; add target-specific no-code proof; correct the flag-4 helper wording to `0x0041b6a0` one-byte guard/no-op helper; add a comment-only C++ marker.
- Confidence: high. Raw PE/Capstone recheck, existing IDA-backed docs, vtable data, constructor/destructor stores, and generated coverage all agree.

Recommended target header:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:00009Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00009Q
EMITTER_POSITION_OPTIONAL:
```

Recommended formal C++ block:

```cpp
// Compiler-generated ObjectList scalar deleting destructor wrapper; source is ObjectList::~ObjectList().
```

This is intentionally a no-code/comment marker, not executable wrapper C++. It satisfies the current special-emitter marker policy while keeping source faithful: the real source is the ordinary `ObjectList` destructor declaration/body, and MSVC regenerates this deleting wrapper.

## Target

- Target UID: `0001D4`
- Target path: `by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md`
- Current scores and route: `84/90`, `CANONICAL_OWNER:0000M4`, `EMITTER_UIDS:0000M4`, `RECONSTRUCTABLE:TRUE`, blank formal C++.
- Current generated route: `auto-generated/-ag-memory-coverage.md` shows `emits`, owner/emitter `0000M4`, destination `auto-generated/NexusTK/map/ObjectList.cpp`, code `no`.
- Current coverage row: `by-memory/-coverage-report.md` lists this as `84% : strong` and says final C++ remains blank.

## Executive Recommendation

The best direct owner is [UID:00009Q][ObjectList](by-class/ObjectList.md). [UID:0000M4][ObjectList](by-file/ObjectList.md) remains the source-file route (`NexusTK/map/ObjectList.cpp`) but should not be the direct owner/emitter for this class ABI artifact. The object-list class page, vtable page, vtable-data child, lifecycle aggregate, constructor, destructor, and layout docs all now clear the strict parent side and already route class-owned vtable/data children through [UID:00009Q].

Do not reclassify [UID:0001D4] as `RECONSTRUCTABLE:FALSE`. The wrapper body is compiler-generated, but the rebuilt source must still declare and define `ObjectList` destructor semantics so the class vtable slot and deleting wrapper exist. The best policy is the same class-owned wrapper-marker policy used by current vtable data pages: reconstructable source-declared/generated-binary output, class owner/emitter, with no handwritten wrapper body.

Do not populate decompiler-shaped C++. The wrapper contains ABI-only delete flags, direct vtable/destructor glue, `operator delete`, and the guard/no-op size path. Those are compiler output, not human source.

## Evidence Checked

Documentation read:

- Target [UID:0001D4] `0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md`.
- [UID:00009Q] `by-class/ObjectList.md`.
- [UID:0000M4] `by-file/ObjectList.md`.
- [UID:0001D1] `0x00530ee0-0x00531473.ObjectListLifecycle.md`.
- [UID:0002JS] `0x00530ee0-0x0053125d.ObjectListConstructor.md`.
- [UID:0002JT] `0x00531260-0x00531473.ObjectListDestructor.md`.
- [UID:0001VG] `by-type/by-struct/ObjectListLayout.md`.
- [UID:0001YB] `by-type/by-vtable/ObjectList_vtable.md`.
- [UID:0002OF] `0x00620284-0x00620294.ObjectListVtableData.md`.
- [UID:000260] `0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`.
- [UID:00023F] `0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md`.
- [UID:0002BC] `0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md`.
- [UID:000197] `0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`.
- [UID:0000WM] `0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md` and [UID:0000WL] `0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md` for the adjacent `0x0041b6a0` guard/no-op helper context.
- Prior executed B003 scalar-wrapper policy report for [UID:0002JF] `MenuItemScalarDeletingDestructor`.

Generated/read-only reports checked:

- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- `project-level/-unresolved.md`
- `project-level/-resolved.md`
- `auto-generated/NexusTK/map/ObjectList.cpp`

Local binary evidence checked:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- `.text`: RVA `0x1000`, raw `0x400`, raw size `0x20b600`
- `.rdata`: RVA `0x20d000`, raw `0x20ba00`, raw size `0x5f200`
- Direct Capstone disassembly of `0x00537290-0x005372c8`
- Vtable dword reads at `0x00620280-0x00620294`
- Padding byte reads around the target and lifecycle
- Whole `.text` rel32 `call`/`jmp` scan for target, ordinary destructor, delete helper, vtable, and sibling helper
- Whole-file dword scan for target VA, ObjectList vtable VA, and key helper VAs

Live IDA MCP was not available as a direct tool in this session. The report therefore uses existing IDA-backed documentation plus direct read-only PE checks. This limits final-audit scoring, but does not weaken the main policy recommendation.

## IDA / PE Facts

### Function Body

Capstone disassembly of `0x00537290-0x005372c8`:

```asm
00537290  push   ebp
00537291  mov    ebp, esp
00537293  push   esi
00537294  mov    esi, ecx
00537296  call   0x00531260
0053729b  mov    eax, dword ptr [ebp+8]
0053729e  test   al, 1
005372a0  je     0x005372c1
005372a2  test   al, 4
005372a4  jne    0x005372b6
005372a6  push   esi
005372a7  call   0x004f4ac0
005372ac  add    esp, 4
005372af  mov    eax, esi
005372b1  pop    esi
005372b2  pop    ebp
005372b3  ret    4
005372b6  push   0x44
005372b8  push   esi
005372b9  call   0x0041b6a0
005372be  add    esp, 8
005372c1  mov    eax, esi
005372c3  pop    esi
005372c4  pop    ebp
005372c5  ret    4
```

Facts:

- Exact body size: `0x38` / 56 bytes.
- Receiver: `ObjectList* this` in `ecx`, saved in `esi`.
- Stack argument: MSVC deleting-destructor flags at `[ebp+8]`.
- First action: calls ordinary [UID:0002JT] `ObjectList::~ObjectList` at `0x00531260`.
- Normal delete path: if `(flags & 1) != 0 && (flags & 4) == 0`, calls [UID:000197] `OperatorDeleteWrapper` at `0x004f4ac0`.
- Flag-4 path: if `(flags & 1) != 0 && (flags & 4) != 0`, pushes object size `0x44` / 68 and `this`, then calls `0x0041b6a0`.
- Return: always returns original `this` in `eax` with `ret 4`.

The target's current "calls `_guard_check_icall_nop@4`" wording is directionally right as compiler guard/no-op support, but imprecise: the raw call target is `0x0041b6a0`, whose body is one byte `C3` / `ret`, followed by padding. The caller cleans up the two pushed arguments with `add esp, 8`. Existing [UID:0000WM] docs identify neighbor context as the MSVC CFG guard-check nop helper return before the `0x0041b6b0` and `0x0041b6c0` tiny default virtual stubs.

### Boundary Facts

Raw bytes:

- `0x0053728e-0x00537290`: `cc cc`
- `0x00537290-0x005372c8`: target body
- `0x005372c8-0x005372d0`: `cc cc cc cc cc cc cc cc`
- `0x0053125d-0x00531260`: `cc cc cc`
- `0x00531473-0x00531480`: thirteen `cc` bytes

This agrees with [UID:00023F] ending at `0x0053728e`, the two-byte padding, the target wrapper, and [UID:0001D5]/ObjectPane successor beginning at `0x005372d0`.

### Vtable And Xref Facts

Raw dwords:

```text
0x00620280 -> 0x00000044
0x00620284 -> 0x0064ccb4   ObjectList RTTI/COL pointer
0x00620288 -> 0x00537290   ObjectList vtable slot 0
0x0062028c -> 0x004f4b10   inherited LObject runtime/type helper
0x00620290 -> 0x0041b6c0   inherited LObject/default no-op virtual
0x00620294 -> 0x0064ce90   ObjectPane RTTI/COL pointer
```

Direct scan results:

- Target VA `0x00537290`: one whole-file dword hit, `.rdata:0x00620288`.
- No `.text` rel32 direct `call` or `jmp` to `0x00537290`.
- `ObjectList` vtable VA `0x00620288`: two whole-file dword hits, both in `.text` vptr-store instructions:
  - constructor instruction at `0x00530f19` (`mov dword ptr [edi], 0x00620288`)
  - ordinary destructor instruction at `0x00531288` (`mov dword ptr [esi], 0x00620288`)
- Ordinary destructor `0x00531260`: one direct `.text` call hit, at `0x00537296` inside this wrapper.
- `OperatorDeleteWrapper` `0x004f4ac0`: 2,129 direct `.text` rel32 call hits, matching its project-wide delete-helper role.
- The sibling live helper `0x00537210` has a direct call from `0x005320d6`; this remains inside [UID:0002BC] and is separated from this target by the `0x0053728e-0x00537290` padding.

## Ordinary Destructor Relationship

[UID:0002JT] `0x00531260-0x00531473.ObjectListDestructor` is the source-authored non-deleting destructor. It restores the `ObjectList` vtable, releases row-list arrays and global list tiers, conditionally cleans `+0x34` under `byte_66DA97`, and calls the `LObject` destructor body at `0x004f4a90`.

[UID:0001D4] has no independent ObjectList cleanup semantics. It delegates to [UID:0002JT] and then applies compiler delete-flag behavior. Therefore:

- Source destructor placement belongs in [UID:0002JT]/[UID:0001D1]/[UID:00009Q], not in [UID:0001D4].
- [UID:0001D4] is evidence that `ObjectList` has virtual destructor semantics and a vtable slot.
- The final source should contain `virtual ~ObjectList();` and the ordinary destructor body, not a method named `ObjectListScalarDeletingDestructor`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best-supported direction | Evidence checked | Rejected alternatives | Score / C++ impact |
| --- | --- | --- | --- | --- |
| Wrapper policy | Class-owned reconstructable wrapper marker. | Vtable-only target, exact scalar-delete flag pattern, ordinary destructor delegation, source-declared/generated-binary policy in `by-structure.md`, analogous [UID:0002JF] policy. | `RECONSTRUCTABLE:FALSE` ignored glue; handwritten source method. | Raise to `86/92`; no handwritten C++. |
| Direct owner | [UID:00009Q] `ObjectList`. | Class page `85/88`; file page `85/88`; vtable and vtable-data children already class-routed; constructor/destructor stores. | Direct by-file owner `0000M4`; `ObjectPane`; preceding helper island; MemoryMan. | Change owner/emitter to `00009Q`. |
| Source file route | [UID:0000M4] `NexusTK/map/ObjectList.cpp` through class owner. | ObjectList file inventory, MapPane constructor callers, helper island ownership. | `util/List.cpp`; `MapPane.cpp`; `ObjectPane.cpp`. | Document file as route, not direct owner. |
| Ordinary destructor | [UID:0002JT] is the real source destructor body. | Only direct call into `0x00531260` is this wrapper; destructor page has cleanup details. | Put cleanup source in wrapper page. | Wrapper formal C++ should not duplicate destructor body. |
| Vtable slot `0x00620288` | Slot 0 points to this wrapper. | Raw dwords, [UID:0001YB], [UID:0002OF], constructor/destructor vptr-store immediates. | Treat as normal direct-call helper. | Supports class ownership. |
| Object size `0x44` | 68-byte ObjectList size. | Flag-4 push immediate `0x44`; [UID:0001VG] layout; constructor allocation/field range. | Helper constant unrelated to class size. | Supports wrapper/class relationship, not source field naming. |
| Delete helper | [UID:000197] `OperatorDeleteWrapper`, MemoryMan-backed global `operator delete`. | Target call at `0x005372a7`; operator-delete doc; 2,129 direct-call PE count. | ObjectList-owned free helper; CRT-only external call. | Link as dependency; do not emit explicit call in source wrapper. |
| Guard/no-op branch | `0x0041b6a0` one-byte MSVC guard-check nop helper path, called with `this` and object size. | Target disasm; local disasm of `0x0041b6a0`; [UID:0000WM]/[UID:0000WL] neighbor docs. | `0x0041b6c0` inherited vtable no-op; ObjectList source helper; second free path. | Correct target prose; no target blocker. |
| Formal C++ blank vs marker | Use comment-only no-code marker. | Current Rule 28 special-emitter marker guidance; active autogen reports `Empty Emitter Marker`; target has valid emitter route and combined score above code-entry minimum. | Full pseudocode wrapper; leaving blank only due stale `95/95` gate. | Insert one comment if implementation callback accepts. |
| Final field/helper names | Not needed for wrapper C++; ordinary destructor/source body still depends on ObjectList tier names. | Layout, constructor, destructor, B001 tier report. | Treat broader field-name uncertainty as blocking wrapper route. | Field names cap ordinary destructor/class final C++, not wrapper policy. |

### Compiler-Generated / Raw Names

- `sub_537290`: keep as old IDA search alias only. Source-facing name should be `ObjectList` scalar deleting destructor wrapper in prose, not a source method.
- `sub_531260`: source-facing [UID:0002JT] `ObjectList::~ObjectList`.
- `sub_4F4AC0`: [UID:000197] MemoryMan-backed global `operator delete` / `OperatorDeleteWrapper`.
- `0x0041b6a0`: compiler-generated `@_guard_check_icall_nop@4`/guard-check nop helper return; exact one-byte helper has no source ownership under `ObjectList`.
- `0x0041b6c0`: inherited `LObject::VirtualNoop(int, int)` vtable slot, not called by this wrapper.

## Ranked Ownership Analysis

### 1. [UID:00009Q] ObjectList - Accepted

Evidence for:

- The wrapper is the first `ObjectList` vtable slot at `0x00620288`.
- The `ObjectList` constructor writes vptr `0x00620288` at `0x00530f19`.
- The ordinary destructor restores vptr `0x00620288` at `0x00531288`.
- The wrapper calls the ordinary `ObjectList` destructor body at `0x00531260`.
- [UID:00009Q], [UID:0001YB], [UID:0002OF], [UID:0001VG], [UID:0001D1], [UID:0002JS], and [UID:0002JT] all agree on ObjectList class ownership.
- The class and file parents now clear the strict gate.

Evidence against:

- The exact wrapper body is compiler-generated and not a human-authored class method body.

Decision: accepted as direct canonical owner/emitter because class declaration/destructor semantics are the narrowest source cause for this wrapper and vtable slot.

### 2. [UID:0000M4] ObjectList File - Rejected As Direct Owner, Kept As Source Route

Evidence for:

- The source file is `NexusTK/map/ObjectList.cpp`.
- The current target metadata routes directly here.
- The generated output destination is already `auto-generated/NexusTK/map/ObjectList.cpp`.

Evidence against:

- Direct file ownership bypasses the class even though this is a class vtable destructor slot.
- Class-owned vtable data and layout children now route through [UID:00009Q].
- The by-file page explicitly says class-owned children should attach to the class first.

Decision: keep as source-root route only. Direct owner/emitter should be [UID:00009Q].

### 3. `RECONSTRUCTABLE:FALSE` Compiler Glue - Rejected

Evidence for:

- The exact body is ABI/compiler output, not ordinary handwritten C++.
- A hand-written wrapper would be source-polluting.

Evidence against:

- Rebuilt source must still cause the destructor slot and deleting wrapper to exist.
- `by-structure.md` distinguishes source-declared/generated-binary items from pure disposable compiler/linker artifacts.
- Current vtable-data docs use `RECONSTRUCTABLE:TRUE` for source-declared/generated-binary class artifacts.
- Existing scalar wrapper policy for [UID:0002JF] keeps wrapper pages reconstructable with no target C++ body.

Decision: reject. Keep reconstructable, with no handwritten wrapper body.

### 4. MemoryMan / OperatorDeleteWrapper - Rejected

Evidence for:

- The wrapper calls [UID:000197] on the ordinary delete path.

Evidence against:

- `OperatorDeleteWrapper` is a callee used by thousands of cleanup paths; it does not own callers.
- The wrapper's vtable slot, `this`, and ordinary destructor call are all ObjectList-specific.

Decision: reject; dependency only.

### 5. ObjectPane / Read-Only Data Aggregate / Preceding Helper Island - Rejected

Evidence for:

- The next `.rdata` dword after the ObjectList vtable is `ObjectPane` RTTI at `0x00620294`.
- The wrapper is adjacent to the extended ObjectList helper island and precedes ObjectPane code.

Evidence against:

- The target pointer appears at `0x00620288`, before the `ObjectPane` RTTI boundary.
- [UID:00023F]/[UID:0002BC] end at `0x0053728e`, and `0x0053728e-0x00537290` is padding before this distinct modeled function.
- ObjectPane constructor starts after post-target padding at `0x005372d0`.

Decision: reject.

## First-Draft C++ / No-Code Proof

Do not emit a source function body equivalent to this pseudocode:

```cpp
// Descriptive only. Do not emit as target C++.
void* ObjectList::scalar_deleting_destructor(unsigned int flags)
{
    this->~ObjectList();
    if ((flags & 1) != 0) {
        if ((flags & 4) != 0) {
            compiler_guard_noop(this, 0x44);
        } else {
            operator delete(this);
        }
    }
    return this;
}
```

Why this should not be formal source:

- It encodes MSVC ABI delete flags and `ret 4` calling convention details.
- It hard-codes the class object size and compiler no-op guard helper.
- It calls the project delete wrapper directly even though a source `delete` expression / virtual destructor declaration should make the compiler emit this.
- It would duplicate ordinary destructor semantics from [UID:0002JT].
- It would make the rebuilt source less like mid-2000s C++ and more like a decompiler transcription.

Recommended target formal block is a comment-only marker:

```cpp
// Compiler-generated ObjectList scalar deleting destructor wrapper; source is ObjectList::~ObjectList().
```

Recommended class/source-level shape belongs in support docs and future class/source reconstruction, not in [UID:0001D4]:

```cpp
class ObjectList : public LObject {
public:
    virtual ~ObjectList();
};

ObjectList::~ObjectList()
{
    // Real cleanup semantics belong to UID 0002JT.
}
```

## Recommended Target Changes

Apply these changes to [UID:0001D4] if the supervisor accepts this report.

Header:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00009Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00009Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Status section:

- Replace the direct file attachment wording with: direct owner/emitter [UID:00009Q] `ObjectList`; source route [UID:0000M4] `ObjectList` / `NexusTK/map/ObjectList.cpp`.
- Replace old `80/80` and stale `95/95` gate wording with current combined-score/emitter policy plus target-specific no-code proof.
- State rebuild handling as `source-declared/generated-binary`: the source declaration/body is `ObjectList::~ObjectList`; this wrapper is generated.

Behavior section:

- Keep the ordinary destructor, flag bit, and delete-helper explanation.
- Correct guard/no-delete branch:
  - Old: calls `_guard_check_icall_nop@4`.
  - Recommended: pushes object size `0x44` / 68 and `this`, calls one-byte `0x0041b6a0` guard-check nop helper, then caller cleans 8 bytes. This is compiler-generated flag-4/sized-delete support, not `ObjectList` source logic.

Evidence section:

- Add local raw PE/Capstone facts from this report.
- Add target VA pointer scan: only `.rdata:0x00620288`.
- Add no direct `.text` rel32 caller/jumper to target.
- Add ObjectList vtable VA dword hits only in constructor/destructor vptr-store immediates.
- Add ordinary destructor direct-call scan: only `0x00537296`.

Reconstruction/no-code section:

- Replace old "blank because below 95/95" with a target-specific no-code proof.
- Add the comment-only marker as formal C++ if the supervisor wants emitted special-case marker behavior.

Score rationale:

- Before: `84/90`.
- After: `86/92`.
- Completion rises because direct class routing, guard/no-op helper identity, generated-wrapper policy, no-code marker policy, raw PE caller/pointer scan, and current active code-entry policy are resolved.
- Confidence rises because local bytes and support docs align exactly. It remains below `95` because live IDA MCP was not available in this session and broader final ObjectList field/source spelling remains below final-audit quality.

## Recommended Support-Doc Changes

### [UID:00009Q] `by-class/ObjectList.md`

Recommended addition to method family row or evidence notes:

```md
[UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) is a class-owned MSVC scalar deleting destructor wrapper generated from `ObjectList::~ObjectList`, not a handwritten source method. The direct owner/emitter should be this class; [UID:0000M4][ObjectList](by-file/ObjectList.md) remains the source-file route. Formal target C++ should be a comment-only no-code marker or blank under the established wrapper convention; real cleanup source belongs to [UID:0002JT].
```

No score change required for the class; it already clears `85/88`.

### [UID:0000M4] `by-file/ObjectList.md`

Recommended update to the lifecycle proposed-contents row:

```md
The discontiguous scalar deleting destructor [UID:0001D4] is class-owned compiler-generated wrapper output for `ObjectList::~ObjectList`. It should route through [UID:00009Q][ObjectList](by-class/ObjectList.md) into `NexusTK/map/ObjectList.cpp`; the by-file page is the source root, not the direct owner.
```

No score change required.

### [UID:0002JT] `ObjectListDestructor`

Recommended addition:

```md
The only direct code caller of this ordinary destructor remains [UID:0001D4] at `0x00537296`. [UID:0001D4] is the MSVC scalar deleting destructor wrapper and should not duplicate this body's source. Reconstructed source for cleanup belongs here as `ObjectList::~ObjectList`; the deleting-wrapper flag checks, `OperatorDeleteWrapper` call, and `0x0041b6a0` flag-4 no-op path are compiler-generated around this body.
```

No score change required unless the implementation pass also adds first-draft ordinary destructor C++ later.

### [UID:0001D1] `ObjectListLifecycle`

Recommended addition:

```md
The discontiguous [UID:0001D4] scalar deleting destructor should be documented as a generated wrapper marker for the lifecycle destructor, not as an additional source-authored lifecycle method body. The lifecycle aggregate remains the constructor/destructor source pair; [UID:0001D4] belongs directly to the class/vtable route.
```

### [UID:0001YB] `ObjectList_vtable`

Recommended update:

```md
Slot 0 at `0x00620288` points to [UID:0001D4], the class-owned compiler-generated scalar deleting destructor wrapper for `ObjectList::~ObjectList`. The wrapper has no direct code callers, calls [UID:0002JT], and should not be reconstructed as a handwritten method.
```

### [UID:0002OF] `ObjectListVtableData`

Recommended update:

```md
The slot target [UID:0001D4] now follows the same direct class owner/emitter route as this vtable data: [UID:00009Q][ObjectList](by-class/ObjectList.md). The source declaration/ordinary destructor body regenerates both the vtable slot and the deleting wrapper; do not hand-author the vtable array or wrapper body.
```

### [UID:000260] `ObjectPaneReadOnlyData`

This aggregate's exact child table still says [UID:0002OF] parent decision is blank/ObjectList parents remain `84/88`. That is stale after the ObjectList class/file refresh.

Recommended child-table row replacement:

```md
| [UID:0002OF][0x00620284-0x00620294.ObjectListVtableData](by-memory/0x00620284-0x00620294.ObjectListVtableData.md) | `0x00620284-0x00620294` | `ObjectList` RTTI/vtable | assigned to [UID:00009Q][ObjectList](by-class/ObjectList.md) |
```

### [UID:00023F] `ObjectListExtendedTypeLookupHelpers`

Recommended addition to boundary/evidence:

```md
The successor [UID:0001D4] at `0x00537290-0x005372c8` is not part of this helper island. The two bytes `0x0053728e-0x00537290` are alignment, and [UID:0001D4] is the class-owned scalar deleting destructor wrapper for `ObjectList::~ObjectList`.
```

### [UID:0002BC] `ObjectListTierInsertRemoveHelpers`

No change required. It already proves the predecessor boundary and states `0x0053728e-0x00537290` is padding before [UID:0001D4]. If touched, optionally add that [UID:0001D4] routes through the class as a compiler wrapper marker.

### [UID:000197] `OperatorDeleteWrapper`

No metadata change required. Optional note:

```md
[UID:0001D4] is one of the scalar deleting destructor wrappers that reaches this MemoryMan-backed global `operator delete` only when `(flags & 1) != 0 && (flags & 4) == 0`.
```

### `0x0041b6a0` Guard No-Op Helper Gap

No target blocker. The exact `0x0041b6a0-0x0041b6a1` helper currently lacks its own by-memory page, but [UID:0000WM] and [UID:0000WL] neighbor docs mention it. If the supervisor wants cleanup, create a tiny ignored/compiler-generated support page or add an ignored-ledger entry for `0x0041b6a0-0x0041b6a1` as the MSVC CFG guard-check nop helper. This should be separate from the ObjectList assignment.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` from B003. Supervisor-owned replacement row:

Placement: replace the existing [UID:0001D4] row under the ObjectList helper/lifecycle region, between the `0x0053728e-0x00537290` padding row and the `0x005372c8-0x005372d0` padding row.

```md
    - [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) 0x00537290-0x005372c8 | compiler-generated destructor wrapper | ObjectListScalarDeletingDestructor : reconstructable : 86% : very-strong : B003 2026-06-19 source-quality recheck classifies this as the MSVC scalar deleting destructor wrapper generated from source-level `ObjectList::~ObjectList`; raw PE/Capstone confirms the exact `0x38` / 56-byte body, `0x0053728e-0x00537290` two-byte prepad, `0x005372c8-0x005372d0` eight-byte postpad, sole ordinary-destructor call at `0x00537296 -> 0x00531260`, [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) call at `0x005372a7` only for `flags & 1` with `flags & 4` clear, flag-4 path through one-byte `0x0041b6a0` no-op/guard helper with object size `0x44` / 68, target VA pointer hit only in the `ObjectList` vtable slot `0x00620288`, no `.text` rel32 direct callers, vptr-store immediates only in constructor `0x00530f19` and ordinary destructor `0x00531288`, direct owner/emitter route through [UID:00009Q][ObjectList](by-class/ObjectList.md) into [UID:0000M4][ObjectList](by-file/ObjectList.md), and formal target C++ should be a comment-only no-code marker because source should declare/define the ordinary `ObjectList` destructor and let MSVC regenerate the wrapper.
```

Expected validator-owned `auto-generated/-ag-memory-coverage.md` row after accepted metadata/comment refresh:

```md
| [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md) | coded | `00009Q` | `00009Q` |  | yes | `auto-generated/NexusTK/map/ObjectList.cpp` | `by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md` |  |
```

If the supervisor rejects the comment-marker approach and preserves the established older blank-wrapper convention, the expected generated row would remain `emits` / code `no`, but the target must still explain that this is an intentional no-formal-C++ wrapper policy, not a missing-code blocker. My recommendation is the comment marker because current supervisor Rule 28 asks special emitters to emit `//`.

## Validator Needs

Report-only pass: no validator run.

Implementation callback validation commands:

> Executable block R001 was removed from this report and preserved verbatim in [0001D4-ObjectListScalarDeletingDestructor-source-quality-removed.md](0001D4-ObjectListScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited, run file-mode validation for each edited support file:

> Executable block R002 was removed from this report and preserved verbatim in [0001D4-ObjectListScalarDeletingDestructor-source-quality-removed.md](0001D4-ObjectListScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After target/support validation, refresh/check generated route:

> Executable block R003 was removed from this report and preserved verbatim in [0001D4-ObjectListScalarDeletingDestructor-source-quality-removed.md](0001D4-ObjectListScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Supervisor-owned manual coverage update remains required for `by-memory/-coverage-report.md` while the edit ban is active.

## Open Questions

Closed by this report:

- Direct owner/emitter route: [UID:00009Q] `ObjectList`.
- Source-file route: [UID:0000M4] `ObjectList.cpp`.
- Wrapper policy: reconstructable source-declared/generated-binary wrapper marker, not ignored compiler glue.
- Ordinary destructor relationship: [UID:0002JT] is the source body; [UID:0001D4] is wrapper only.
- Vtable slot: `0x00620288` is the only target pointer hit.
- Object size: flag-4 immediate `0x44` matches [UID:0001VG] 68-byte layout.
- Delete helper: [UID:000197] MemoryMan-backed global `operator delete`.
- Guard branch: `0x0041b6a0` one-byte guard/no-op helper, not ObjectList logic and not the inherited `0x0041b6c0` vtable no-op.
- Formal C++ readiness: use a comment-only no-code marker; do not emit pseudocode.

Still external:

- Final source-facing names for all ObjectList row/global tier fields and helper methods remain broader ObjectList reconstruction work. They block high-final ordinary destructor C++, but they do not block [UID:0001D4] wrapper policy.
- Exact original spelling of the `ObjectList` destructor declaration cannot be proven from the stripped binary. `virtual ~ObjectList();` is the source-faithful representation.
- If desired, a separate tiny page/ignored entry for `0x0041b6a0-0x0041b6a1` would clean up the guard helper family, but this is not an ObjectList blocker.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0001D4-ObjectListScalarDeletingDestructor-source-quality.md`
- Modified: none
- Target/support docs edited: none
- Generated/coverage docs edited: none
- Prior reports preserved: `0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality.md` was not modified.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001D4-ObjectListScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001D4"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001D4-ObjectListScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001D4-ObjectListScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001D4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
