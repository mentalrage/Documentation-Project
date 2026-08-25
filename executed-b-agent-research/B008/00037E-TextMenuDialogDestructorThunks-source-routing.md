** TARGET-REPORT-UID:00037E **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 00037E **
# B008 Source-Routing Report: [UID:00037E] TextMenuDialogDestructorThunks

Date: 2026-06-19  
Agent: B008  
Target: `source-3/project-documentation/by-memory/0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks.md`  
Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/00037E-TextMenuDialogDestructorThunks-source-routing.md`  
Status: report-only; no by-* docs or `by-memory/-coverage-report.md` edited

## Summary Recommendation

[UID:00037E] should remain a non-emitting, non-reconstructable compiler-thunk page, but the target doc should be expanded from the current compact parent-reference form to a byte-level no-code proof.

Recommended target metadata:

```text
COMPLETION:85
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: blank
```

Source responsibility belongs to [UID:0000ES] `TextMenuDialog` in [UID:0000OP] `TextMenuDialogs`, but this range itself should not be a class-owned emitter. The original source shape is an ordinary virtual `TextMenuDialog::~TextMenuDialog()` / class declaration with the existing multiple-view pane layout; MSVC emits the secondary and tertiary deleting-destructor adjustor thunks from that layout.

## Evidence Checked

- Target page [UID:00037E] currently records the range as compiler-generated destructor adjustor thunks with owner context `TextMenuDialog`, parent aggregate [UID:0001BX], scalar deleting target `0x00520da0`, vtable refs `0x0061ed0c` and `0x0061ed3c`, `RECONSTRUCTABLE:FALSE`, and blank C++.
- Parent aggregate [UID:0001BX] records every menu destructor thunk in the island as an `0x0b` IDA function, including `0x00520b3f` and `0x00520b4a`, and records `0x00520da0` as the `0x48`-byte scalar deleting destructor for `TextMenuDialog`.
- Local PE check against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, confirms the exact target bytes and disassembly.
- Fresh IDA MCP check was attempted on `127.0.0.1:13337/mcp`; the server was unavailable: `Unable to connect to the remote server`. This report relies on local PE/Capstone checks plus existing live IDA evidence already recorded in the by-* docs.
- Support docs checked: `TextMenuDialog.md`, `TextMenuDialogs.md`, `TextMenuDialogVtables.md`, `MerchantMenuDialogVtableFamily.md`, `MerchantMenuDialogReadOnlyData.md`, `TextMenuDialogScalarDeletingDestructor.md`, `DialogPane.md`, `OperatorDeleteWrapper.md`, `-ignored.md`, manual/generated coverage, and the stale temporary coverage snapshot.

## Exact Bytes, Bounds, And Xrefs

The filename uses the inclusive final byte `0x00520b54`. The actual half-open byte coverage is `0x00520b3f-0x00520b55`: two adjacent `0x0b` thunk functions with no internal padding.

| Function | Bytes | Disassembly | Accepted refs |
| --- | --- | --- | --- |
| `0x00520b3f-0x00520b4a` | `81 e9 a0 00 00 00 e9 56 02 00 00` | `sub ecx, 0xa0; jmp 0x00520da0` | vtable slot `0x0061ed0c -> 0x00520b3f` |
| `0x00520b4a-0x00520b55` | `81 e9 a4 00 00 00 e9 4b 02 00 00` | `sub ecx, 0xa4; jmp 0x00520da0` | vtable slot `0x0061ed3c -> 0x00520b4a` |

Neighboring bytes prove the boundaries:

- `0x00520b29-0x00520b3f` is the preceding `TextInputMenuDialog` pair, forwarding to `0x00520d50`.
- `0x00520b55-0x00520b6b` is the following `TextMenuItemList` pair, forwarding to `0x00520df0`.
- The target has no padding between the two thunks and no byte gap before the following thunk pair.

Vtable and constructor-route evidence:

- Primary `TextMenuDialog` table `0x0061ecac` points directly to scalar deleting destructor `0x00520da0`.
- Secondary table `0x0061ed0c` points to the `this - 0xa0` thunk.
- Tertiary table `0x0061ed3c` points to the `this - 0xa4` thunk.
- Constructor `0x00517f30` stores the three table addresses through immediates at raw PE addresses `0x00517fa2`, `0x00517fac`, and `0x00517fb6`.

## Scalar Deleting Destructor Flow

The target thunks tail-jump to sibling [UID:00037F] `0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor`.

Local disassembly of `0x00520da0-0x00520de8`:

```asm
00520da0  push ebp
00520da1  mov  ebp, esp
00520da3  push esi
00520da4  mov  esi, ecx
00520da6  lea  ecx, [esi+0x27c]
00520dac  call 0x00582b30
00520db1  mov  ecx, esi
00520db3  call 0x0049d9f0
00520db8  mov  eax, [ebp+8]
00520dbb  test al, 1
00520dbd  je   0x00520de1
00520dbf  test al, 4
00520dc1  jne  0x00520dd3
00520dc3  push esi
00520dc4  call 0x004f4ac0
00520dd3  push 0x28c
00520dd8  push esi
00520dd9  call 0x0041b6a0
00520de1  mov  eax, esi
00520de5  ret  4
```

Interpretation:

- `0x00582b30` tears down the owned `TextMenuDialog + 0x27c` text/object field. Existing class docs call this field `LObject`; resolved helper notes elsewhere call `0x00582b30` a release wrapper. The safest support-doc wording is "owned text/string/LObject-backed field at `+0x27c`" until the class source-quality pass finalizes the exact member type.
- `0x0049d9f0` is the shared [UID:00012R] `DialogPane` cleanup / non-deleting destructor body, despite stale IDA name pollution in some docs.
- `0x004f4ac0` is the [UID:000197] MemoryMan-backed global `operator delete` wrapper, used only for scalar-delete flags `(flags & 1) != 0 && (flags & 4) == 0`.
- The `flags & 4` path pushes size `0x28c` and the object pointer into compiler guarded-delete support `0x0041b6a0`; this is compiler/runtime support, not a source call.
- `0x28c` is strong complete-object size evidence for `TextMenuDialog` in this destructor path.

## Source Shape And Ownership

Best source-facing model:

```cpp
class TextMenuDialog : public MerchantDialogPane {
public:
    virtual ~TextMenuDialog();
    // constructor, paint, action, and scroll-button methods live in TextMenuDialogs.cpp
};
```

The destructor source body, if/when emitted through the class/file docs, should express normal member cleanup and base destruction only. It should not include:

- `TextMenuDialogDestructorThunks` functions.
- manual `this -= 0xa0` or `this -= 0xa4` code.
- a handwritten `scalar deleting destructor`.
- a direct source call to `operator delete` from the ordinary destructor.
- a source call to the guarded-size helper.

The `+0xa0` and `+0xa4` adjustments are the same primary/secondary/tertiary pane-view ABI shape documented in [UID:00031Y] `TextMenuDialogVtables` and [UID:0001Y5] `MerchantMenuDialogVtableFamily`. They correspond to deleting through the secondary and tertiary vtable views; the thunks recover the complete object pointer before entering the primary scalar deleting destructor.

## Rejected Alternatives

- Handwritten `TextMenuDialogDestructorThunks` source methods: rejected. The two bodies are exact MSVC ABI adjusted-this thunks and contain no product logic.
- Assigning [UID:00037E] to [UID:0000ES] as a reconstructable emitter: rejected. `TextMenuDialog` is the semantic source context, but this child range is compiler glue with no source body.
- Treating the target range as part of a handwritten mixed island method: rejected. Parent [UID:0001BX] proves this strip is interleaved destructor glue across argumented, text, item/spell, server-item, object-image, and shared dialog families.
- Merging with [UID:00037F] for source emission: rejected for this target. [UID:00037F] is a sibling scalar deleting wrapper and also compiler-generated; both should be described but not emitted.
- Treating the `0x00520b54` path endpoint as half-open: rejected. The second thunk's last byte is at `0x00520b54`; half-open coverage ends at `0x00520b55`.

## Recommended Target Doc Changes

Update [UID:00037E] as follows:

- Change score to `COMPLETION:85`, `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- Add the half-open/inclusive endpoint note: documented path end `0x00520b54` is the final byte; actual byte coverage is `0x00520b3f-0x00520b55`.
- Add the two-thunk table with exact bytes, disassembly, vtable refs, and scalar target:
  - `0x00520b3f-0x00520b4a`: `sub ecx, 0xa0; jmp 0x00520da0`; `0x0061ed0c`.
  - `0x00520b4a-0x00520b55`: `sub ecx, 0xa4; jmp 0x00520da0`; `0x0061ed3c`.
- Add source-policy text:

```text
No standalone C++ should be emitted for this range. These are compiler-generated secondary/tertiary deleting-destructor adjustor thunks produced from the TextMenuDialog class declaration, its virtual destructor, and the inherited pane/event/timer view layout. Source reconstruction should model TextMenuDialog's ordinary destructor and class layout; MSVC regenerates these vtable entries and adjusted-this thunks.
```

- Add a scalar-flow summary pointing to [UID:00037F]: the scalar wrapper destroys `this+0x27c`, calls `DialogPane` cleanup `0x0049d9f0`, conditionally calls MemoryMan-backed `operator delete` `0x004f4ac0`, and has a compiler guarded-size path with size `0x28c`.
- Add change-log entry:

```text
- 2026-06-19 B008 source-routing report: local PE/Capstone rechecked exact bytes for the two 0x0b thunks, confirmed half-open coverage `0x00520b3f-0x00520b55`, vtable refs `0x0061ed0c/0x0061ed3c`, primary scalar target `0x00520da0`, constructor vtable-store refs, neighboring thunk boundaries, and no-code source policy. Recommended score `85/92`, owner/emitter blank, and formal C++ blank.
```

## Recommended Support-Doc Changes

- [UID:0001BX] `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
  - Keep `87/90`, `RECONSTRUCTABLE:FALSE`, owner/emitter blank.
  - Update the [UID:00037E] row/notes to include exact byte pair, half-open coverage, and no-code source-policy detail.
  - Keep the parent as a mixed compiler-generated routing ledger, not a source owner.
- [UID:00037F] `by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md`
  - Add the local disassembly-level flow summarized above: `+0x27c` member cleanup, `DialogPane` cleanup at `0x0049d9f0`, scalar-delete flag tests, `operator delete` wrapper `0x004f4ac0`, guarded-size path `0x28c`.
  - Keep `RECONSTRUCTABLE:FALSE` and formal C++ blank. Consider `85/92` if the full flow is incorporated, but do not emit C++.
- [UID:0000ES] `by-class/TextMenuDialog.md`
  - Add a destructor-shape note: source destructor belongs to `TextMenuDialog` and should clean the `+0x27c` owned text/object field before base dialog cleanup; exact compiler scalar/thunk wrappers remain non-emitting [UID:00037E]/[UID:00037F].
  - Replace stale "95/95 reconstruction-code bar" wording with current gate wording if touched; the reason the thunk child is blank is `RECONSTRUCTABLE:FALSE`, not a score-only hold.
  - Keep the `+0x27c` member type provisional until the text/string/LObject distinction is resolved in a class source-quality pass.
- [UID:0000OP] `by-file/TextMenuDialogs.md`
  - Add a no-code destructor-glue note beside the `TextMenuDialog` destructor island.
  - Fix the unqualified `[TextMenuDialogVtables]` cross-reference to [UID:00031Y] if editing this file anyway.
- [UID:00031Y] `by-type/by-vtable/TextMenuDialogVtables.md`
  - Optional discoverability update only: annotate `0x0061ed0c` and `0x0061ed3c` as the secondary/tertiary destructor entries pointing to [UID:00037E].
- `by-memory/-ignored.md`
  - Update the existing `0x00520b13-0x00520b6b` ignored entry with the exact [UID:00037E] byte/vtable evidence. The current broad entry is directionally correct but too compact for the accepted B-agent standard.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` in this B pass. If accepted, replace the stale current [UID:0001BX] row and insert the child rows directly below it, before the existing [UID:0000VN] ignored summary rows:

```text
    - [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) 0x00520abb-0x00520e2b | destructor/thunk island | MenuDialogDestructorThunks : ignored : 87% : strong : Reviewed mixed compiler-generated destructor/thunk container; exact child pages document owner-specific ArgumentedMenuMenuItemList/TextInputMenuDialog/TextMenuDialog/TextMenuItemList wrappers, live IDA and local PE evidence confirm thunk/destructor boundaries and endpoint padding, and the aggregate remains parent-blank because no single reconstructable source parent owns the mixed island.
        - [UID:00037A][0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks](by-memory/0x00520abb-0x00520ad0.ArgumentedMenuMenuItemListDestructorThunks.md) 0x00520abb-0x00520ad0 | destructor adjustor thunks | ArgumentedMenuMenuItemListDestructorThunks : ignored : 83% : strong : Compiler-generated vtable adjustor thunk pair forwarding to the `ArgumentedMenuMenuItemList` destructor, including adjusted-`this` variant.
        - [UID:00037C][0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks](by-memory/0x00520b29-0x00520b3e.TextInputMenuDialogDestructorThunks.md) 0x00520b29-0x00520b3e | destructor adjustor thunks | TextInputMenuDialogDestructorThunks : ignored : 83% : strong : Compiler-generated vtable adjustor thunk pair forwarding to the `TextInputMenuDialog` destructor, including adjusted-`this` variant.
        - [UID:00037E][0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks](by-memory/0x00520b3f-0x00520b54.TextMenuDialogDestructorThunks.md) 0x00520b3f-0x00520b54 | destructor adjustor thunks | TextMenuDialogDestructorThunks : ignored : 85% : strong : B008 2026-06-19 source-routing recheck classifies the target as exact non-emitting compiler glue: the documented end byte `0x00520b54` is the final byte of half-open coverage `0x00520b3f-0x00520b55`; bytes are `81 e9 a0 00 00 00 e9 56 02 00 00` and `81 e9 a4 00 00 00 e9 4b 02 00 00`; the thunks subtract `0xa0`/`0xa4` and tail-jump to [UID:00037F][0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor](by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md), vtable slots `0x0061ed0c/0x0061ed3c` are the dispatch route, primary destructor slot `0x0061ecac` points directly to `0x00520da0`, constructor stores the three table views, and source should regenerate this from the ordinary `TextMenuDialog` destructor/class layout rather than handwritten C++.
        - [UID:00037G][0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks](by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md) 0x00520b55-0x00520b6a | destructor adjustor thunks | TextMenuItemListDestructorThunks : ignored : 83% : strong : Compiler-generated vtable adjustor thunk pair forwarding to the `TextMenuItemList` destructor, including adjusted-`this` variant.
        - [UID:00037B][0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor](by-memory/0x00520bb0-0x00520c17.ArgumentedMenuMenuItemListScalarDeletingDestructor.md) 0x00520bb0-0x00520c17 | scalar deleting destructor | ArgumentedMenuMenuItemListScalarDeletingDestructor : ignored : 84% : strong : Compiler-generated scalar deleting destructor wrapper for `ArgumentedMenuMenuItemList`; source responsibility stays on the class/file docs.
        - [UID:00037D][0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor](by-memory/0x00520d50-0x00520d98.TextInputMenuDialogScalarDeletingDestructor.md) 0x00520d50-0x00520d98 | scalar deleting destructor | TextInputMenuDialogScalarDeletingDestructor : ignored : 84% : strong : Compiler-generated scalar deleting destructor wrapper for `TextInputMenuDialog`; source responsibility stays on the class/file docs.
        - [UID:00037F][0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor](by-memory/0x00520da0-0x00520de8.TextMenuDialogScalarDeletingDestructor.md) 0x00520da0-0x00520de8 | scalar deleting destructor | TextMenuDialogScalarDeletingDestructor : ignored : 84% : strong : Compiler-generated scalar deleting destructor wrapper for `TextMenuDialog`; source responsibility stays on the class/file docs.
        - [UID:00037H][0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor](by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md) 0x00520df0-0x00520e2b | scalar deleting destructor | TextMenuItemListScalarDeletingDestructor : ignored : 84% : strong : Compiler-generated scalar deleting destructor wrapper for `TextMenuItemList` through the final `retn 4` operand byte; source responsibility stays on the class/file docs.
```

## Validator Needs

Suggested implementation-callback validators from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00037E-TextMenuDialogDestructorThunks-source-routing-removed.md](00037E-TextMenuDialogDestructorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Only if the supervisor applies the coverage text:

> Executable block R002 was removed from this report and preserved verbatim in [00037E-TextMenuDialogDestructorThunks-source-routing-removed.md](00037E-TextMenuDialogDestructorThunks-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

These are IDA/documentation convenience names only, not source names:

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x00520b3f` | Name/comment as `TextMenuDialog_destructor_adjustor_this_minus_0xA0`; prototype may be treated as adjusted `this` plus deleting-destructor flags, tail-jumping to `TextMenuDialog_scalar_deleting_destructor`. | High |
| `0x00520b4a` | Name/comment as `TextMenuDialog_destructor_adjustor_this_minus_0xA4`. | High |
| `0x00520da0` | Name/comment as `TextMenuDialog_scalar_deleting_destructor`; keep no source emission. | High |
| `0x0061ed0c` | Comment as `TextMenuDialog secondary-view destructor slot -> this-0xa0 thunk`. | High |
| `0x0061ed3c` | Comment as `TextMenuDialog tertiary-view destructor slot -> this-0xa4 thunk`. | High |
| `0x0061ecac` | Comment as `TextMenuDialog primary scalar deleting destructor slot`. | High |

Avoid applying source-like names such as `TextMenuDialog::DestructorThunkA0()` or `TextMenuDialog::ScalarDeletingDestructor()` in emitted C++.

## Implementation Readiness

Ready for documentation implementation. This is a no-code target:

- Target doc can be upgraded to `85/92` with exact byte/boundary/vtable/source-policy detail.
- Formal C++ must remain blank because `RECONSTRUCTABLE:FALSE`.
- Support docs should carry the source-side destructor/class-layout responsibility without creating standalone thunk methods.
- Coverage change is supervisor-owned only.

Open issue retained outside this target: the exact source member type/name for `TextMenuDialog + 0x27c` should be finalized in a class/source-quality pass. It does not block the [UID:00037E] no-code decision because the target thunks only adjust `this` and jump to [UID:00037F].

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 00037E","source_path":"executed-b-agent-research/B008/00037E-TextMenuDialogDestructorThunks-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
