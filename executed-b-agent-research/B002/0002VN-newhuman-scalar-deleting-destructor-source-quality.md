** TARGET-REPORT-UID:0002VN **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002VN NewHumanImageLib Scalar Deleting Destructor Source-Quality Report

## Executive Recommendation

[UID:0002VN] `0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor` should stay `RECONSTRUCTABLE:TRUE`, owned and emitted by [UID:000092] `NewHumanImageLib`, with formal `RECONSTRUCTION_CPP` left blank. This is a real rebuild-relevant class ABI artifact, but not a source-authored helper body. The source shape is `virtual ~NewHumanImageLib()` in the class declaration plus the ordinary destructor body at [UID:00017S] `0x004e0250-0x004e05c4`; the compiler should regenerate the scalar deleting wrapper and vtable slot.

Recommended target metadata:

| Field | Recommendation | Reason |
| --- | --- | --- |
| `COMPLETION` | `86` | Exact wrapper bytes/range, vtable-only reachability, delete-route semantics, padding, owner/emitter, and source policy are now independently validated. |
| `CONFIDENCE` | `91` | IDA MCP, raw PE pointer/rel32 scan, target/support docs, sibling scalar-destructor precedent, and generated-output review agree. |
| `CANONICAL_OWNER` | `000092` | The direct semantic owner is the `NewHumanImageLib` class; file routing is via [UID:0000LR] `NexusTK/render/NewHumanImageLib.cpp`. |
| `RECONSTRUCTABLE` | `TRUE` | The class destructor/vtable declaration must regenerate this wrapper in a rebuild. |
| `EMITTER_UIDS` | `000092` | The class is the correct direct emitter; the class page routes to `auto-generated/NexusTK/render/NewHumanImageLib.cpp`. |
| `RECONSTRUCTION_CPP` | keep blank | Do not hand-author the wrapper as source; emit the destructor declaration/body once and let the compiler produce the ABI glue. |

This clears the `85/85+` review gate: `(86 + 91) / 2 = 88.5`. The gate does not imply a formal code block should be populated here because the accepted source shape is generated-binary destructor glue.

## Live Wrapper Evidence

Live IDA session: `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, adopted MCP session `b003_00018a_ime_comp_20260617`.

`lookup_funcs` confirms:

| Query | Result |
| --- | --- |
| `0x004e6870` | `sub_4E6870`, size `0x38` |
| `0x004e68a7` | inside `sub_4E6870` |
| `0x004e68a8` | not a function |
| `0x004e68b0` | next function `sub_4E68B0`, size `0xd1` |
| `0x004e0250` | `NewHumanImageLib_Destructor`, size `0x374` |
| `0x004f4ac0` | operator delete wrapper candidate `sub_4F4AC0`, size `0x40` |
| `0x0041b6a0` | `@_guard_check_icall_nop@4`, size `0x1` |

Exact wrapper bytes from IDA and PE file offset `0x000e5c70`:

```text
55 8b ec 56 8b f1 e8 d5 99 ff ff 8b 45 08 a8 01 74 1f a8 04 75 10
56 e8 34 e2 00 00 83 c4 04 8b c6 5e 5d c2 04 00 6a 60 56 e8 02 4e
f3 ff 83 c4 08 8b c6 5e 5d c2 04 00
```

Boundary and padding:

| Range | Bytes / finding | Classification |
| --- | --- | --- |
| `0x004e6860-0x004e6870` | sixteen `0xcc` bytes | padding before this target, after the MonsterImageLib scalar wrapper |
| `0x004e6870-0x004e68a8` | 56-byte body above | exact scalar deleting destructor wrapper |
| `0x004e68a8-0x004e68b0` | eight `0xcc` bytes | post-wrapper alignment padding |
| `0x004e68b0` | `55 8b ec 6a ff ...` | next modeled function prologue |

`make_signature_for_range 0x004e6870-0x004e68a8` with operands not wildcarded returned `unique:true` and the same 56-byte signature.

## Behavior And Delete Route

IDA disassembly and decompile agree on this wrapper shape:

1. `0x004e6876` calls `NewHumanImageLib_Destructor` at `0x004e0250`.
2. The delete flag is read from stack argument byte `arg_0`.
3. If `(flags & 1) == 0`, the wrapper returns the original `this`.
4. If `(flags & 4) != 0`, it takes the guard-check-only branch at `0x004e6896`, calls `@_guard_check_icall_nop@4` with `this` and `0x60`, then returns `this`.
5. Only when `(flags & 1) != 0` and `(flags & 4) == 0`, `0x004e6887` calls `sub_4F4AC0` with `this`; this is the normal object delete route.
6. Both exits return the original object pointer and use `retn 4`.

IDA decompile:

```c
_DWORD *__thiscall sub_4E6870(_DWORD *Block, char a2)
{
  NewHumanImageLib_Destructor(Block); /*0x4e6876*/
  if ( (a2 & 1) == 0 || (a2 & 4) != 0 ) /*0x4e6884*/
    return Block; /*0x4e68a1*/
  sub_4F4AC0(Block); /*0x4e6887*/
  return Block; /*0x4e6891*/
}
```

Source-facing documentation name, if a synthetic name is needed, should be `NewHumanImageLib::ScalarDeletingDestructor(unsigned int flags)`. The recovered IDA prototype reads only a byte (`char a2`) because the body uses `al`, but MSVC deleting-destructor ABI flags are conventionally modeled as an unsigned integer. This is still not a source-authored method to emit.

## Reachability And Vtable Evidence

IDA xrefs:

| Target | Xrefs |
| --- | --- |
| `0x004e6870` | one data xref at `0x0061b76c`; no code callers |
| `0x004e0250` | one code xref at `0x004e6876` from `sub_4E6870` |
| `0x0061b76c` | constructor store at `0x004dfd78`; ordinary destructor restore/store at `0x004e027e` |
| `0x0067a760` | 52 singleton refs, including constructor publish/clear, destructor clear at `0x004e059e`, and `ClearNewHumanImageLibSingleton` at `0x004e5be0` |

Vtable/name evidence:

| Address | Live value/name |
| --- | --- |
| `0x0061b768` | `0x006490f4`, `??_R4NewHumanImageLib@@6B@` RTTI locator |
| `0x0061b76c` | `0x004e6870`, `??_7NewHumanImageLib@@6B@` slot `+0x00` |
| `0x0061b770` | `0x004f4b10`, inherited/shared virtual slot |
| `0x0061b774` | `0x0041b6c0`, `nullsub_18` |
| `0x0061b778` | next non-vtable data; the NewHumanImageLib primary table ends before this |

Raw PE evidence:

| Scan | Result |
| --- | --- |
| raw VA pointer to `0x004e6870` | one hit at file `0x21a16c`, VA `0x0061b76c` |
| raw RVA pointer to `0x000e6870` | zero hits |
| raw VA pointer to `0x0061b76c` | hits at VAs `0x004dfd7a` and `0x004e0280`, matching constructor/destructor vtable stores |
| raw VA pointer to `0x006490f4` | one hit at VA `0x0061b768`, the RTTI locator dword |
| rel32 call/jump to `0x004e6870` | zero hits |
| rel32 call/jump to `0x004e0250` | one `E8` hit at source `0x004e6876` |

This proves the live route is vtable-only into the scalar wrapper, then a direct call from the wrapper into the ordinary destructor.

## Existing Docs And Generated Output Recheck

Searches for `0002VN`, `0x004e6870`, and `NewHumanImageLibScalarDeletingDestructor` found no prior executed B002 report for this exact UID. Existing B-agent reports used as leads only:

- `Agent-B002/research/executed/older/0003M1-MonsterImageLibScalarDeletingDestructor.md`: sibling ImageLib-family precedent for class owner/emitter, `RECONSTRUCTABLE:TRUE`, generated-binary scalar wrapper, and blank formal C++.
- `Agent-B001/research/executed/older/0003M0-HumanImageLibScalarDeletingDestructor.md`: sibling precedent noting the same class-owned/generated-binary convention.

Existing target/support docs are mostly valid:

- [UID:0002VN] already has the correct owner/emitter, range, reconstructability, and blank formal C++ policy. It needs a score/evidence refresh and should retire the impression that the high-level source declaration is still a page-blocking open question.
- [UID:00017S] ordinary destructor page is valid: it owns the cleanup body, records the single scalar-wrapper caller at `0x004e6876`, and explains why final destructor C++ remains pending field/helper names.
- [UID:0001Y9] vtable page is valid: slot `+0x00 -> 0x004e6870`, exactly three slots, class parent, and no secondary NewHumanImageLib vtable in the neighborhood.
- [UID:000092] class page and [UID:0000LR] file page are valid for source placement under `NexusTK/render/NewHumanImageLib.cpp`.

Generated-output caveats:

- `project-documentation/auto-generated/NexusTK/render/NewHumanImageLib.cpp` currently exists but is zero bytes, so it cannot be used as source-quality evidence.
- `simroot_v2/class_NewHumanImageLib.cpp` contains a synthetic `NewHumanImageLib::ScalarDeletingDestructor(unsigned int flags)` with `NTK_ScopedVirtualInstall(ScalarDeletingDestructor, 0x004e6870)`. Treat it as a generated lead only. Its comment mentions the bit-2 no-delete condition, but its code deletes whenever `(flags & 1) != 0`; that does not match the live `flags & 4` branch. Do not copy this body into the formal target block.

## Heuristic / Inference Reanalysis And Validation

Best defensible source direction:

- The original source should declare a virtual `NewHumanImageLib` destructor and define the ordinary destructor cleanup body once in `NexusTK/render/NewHumanImageLib.cpp`.
- The `0x004e6870` function is source-declared/generated-binary output: a compiler-emitted MSVC scalar deleting destructor wrapper installed in the first vtable slot.
- The best documentation-only wrapper signature is `NewHumanImageLib *NewHumanImageLib::ScalarDeletingDestructor(unsigned int flags)`, but the source-facing declaration that should create it is `virtual ~NewHumanImageLib();`.
- The source owner/emitter should remain [UID:000092] `NewHumanImageLib`, with the final file route through [UID:0000LR] `NexusTK/render/NewHumanImageLib.cpp`.

Evidence checked:

- Live IDA MCP `lookup_funcs`, `disasm`, `decompile`, `analyze_function`, `xrefs_to`, `get_bytes`, `get_int`, `make_signature_for_range`, `entity_query`, and `list_globals`.
- Raw PE scan for exact wrapper bytes, VA/RVA pointer hits, vtable pointer stores, RTTI pointer, and rel32 call/jump edges.
- Target page, class page, file page, ordinary destructor page, local method cluster, vtable page, mixed image-library read-only data page, singleton global docs, and current manual/autogenerated coverage rows.
- Existing executed B reports for sibling scalar deleting destructors, used only as policy precedent after binary evidence matched.
- Generated `simroot_v2` and active `project-documentation/auto-generated` output, used only to detect pollution or non-authoritative generated bodies.

Rejected alternatives:

- Source-authored helper method: rejected. The body has the canonical deleting-destructor shape, is vtable-only, calls the ordinary destructor, conditionally calls operator delete, and has no direct source-style callers.
- Ordinary destructor duplicate: rejected. The real cleanup body is [UID:00017S] at `0x004e0250`; this wrapper delegates to it and adds delete-flag handling only.
- `RECONSTRUCTABLE:FALSE` or ignored/no-owner compiler artifact: rejected. Although the body is compiler-emitted, the class destructor declaration and vtable must regenerate it for binary-equivalent rebuilds. The vtable slot at `0x0061b76c` proves it is class ABI, not dead filler.
- File-level owner as direct owner: rejected for direct metadata. [UID:0000LR] is the source file route, but the narrow semantic owner is the class because this is a virtual destructor slot for `NewHumanImageLib`.
- Generic `ImageLib`, old `HumanImageLib`, `MonsterImageLib`, `RidingImageLib`, or adjacent ImageLib-family ownership: rejected by the named `??_7NewHumanImageLib@@6B@` vtable, NewHuman RTTI at `0x0061b768`, constructor/destructor vtable stores, and `g_pNewHumanImageLib` lifecycle refs.
- Split or merge with neighbors: rejected. IDA and PE bytes show an exact `0x38` body, sixteen `0xcc` bytes before it, eight `0xcc` bytes after it, and the next prologue at `0x004e68b0`.
- Formal C++ population with the generated `ScalarDeletingDestructor` body: rejected. The generated body is not source authority and misses the live `flags & 4` no-delete path; even a corrected ABI pseudocode body would duplicate compiler output.
- Vector deleting destructor / array-delete source interpretation: rejected as the source classification. The flag-4 branch exists, but it calls only the guard-check no-op and returns; there is no observed vector-delete loop or array-cookie route. The documented, vtable-installed artifact remains scalar deleting destructor wrapper glue.

Validation of existing docs:

- Existing [UID:0002VN] content is directionally correct and should not be reclassified. The source-authored ordinary destructor versus generated wrapper split is valid.
- The target's remaining "open question" about the high-level source declaration can be resolved to `virtual ~NewHumanImageLib();` plus the ordinary destructor definition. Exact original access specifier/header layout is class-page work, not a blocker for this wrapper's score or C++ policy.
- Support docs do not need ownership/source-placement changes. They may optionally receive a short cross-note after supervisor execution that B002 reconfirmed the wrapper with PE pointer evidence and rejected the generated simroot body.

Score/source-placement/final-C++ impact:

- Raise [UID:0002VN] to `86/91`.
- Keep class owner/emitter [UID:000092] and source route `NexusTK/render/NewHumanImageLib.cpp`.
- Keep `RECONSTRUCTABLE:TRUE` because the wrapper is rebuild-relevant class ABI output.
- Keep the formal C++ block blank. The accepted source implementation should come from the class destructor declaration and [UID:00017S] ordinary destructor work, not this wrapper page.

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP` block for [UID:0002VN].

Reason: this page describes a compiler-generated scalar deleting destructor wrapper. Hand-entering it as source would duplicate the ordinary destructor body/delete route and risks preserving generated artifact names. The current generated `simroot_v2` version is also semantically wrong for the `flags & 4` branch, so it must not be copied.

The source declaration that should produce the wrapper is class-level:

```cpp
class NewHumanImageLib : public LObject {
public:
    virtual ~NewHumanImageLib();
};
```

The destructor body belongs to [UID:00017S] `NewHumanImageLib::~NewHumanImageLib`, not this page. Documentation-only ABI pseudocode for review, not for the formal block:

```cpp
NewHumanImageLib *NewHumanImageLib::ScalarDeletingDestructor(unsigned int flags)
{
    this->~NewHumanImageLib();
    if ((flags & 1U) != 0U && (flags & 4U) == 0U) {
        operator delete(this);
    }
    return this;
}
```

## Supervisor-Owned Coverage Row

Replacement only; no insertion needed.

Placement context: replace the existing [UID:0002VN] row nested under [UID:00017R] `0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster`, after the [UID:0002V8] composition-bounds row and before the next top-level [UID:00017T] `VectorGrowMotion` row.

```markdown
        - [UID:0002VN][0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor](by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md) 0x004e6870-0x004e68a8 | scalar-deleting-destructor | NewHumanImageLib scalar deleting destructor : reconstructable : 86% : strong : B002 2026-06-17 source-quality audit confirms exact `0x38` MSVC scalar-deleting destructor wrapper bytes, vtable-only pointer `0x0061b76c -> 0x004e6870`, no direct rel32 callers, sole ordinary-destructor call `0x004e6876 -> 0x004e0250`, optional delete through `0x004f4ac0` only when `(flags & 1) && !(flags & 4)`, guard-check-only flag-4 branch, unique signature, `0x004e68a8-0x004e68b0` `0xcc` padding, class owner/emitter [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md), source-declared/generated-binary treatment, and formal C++ intentionally blank because `virtual ~NewHumanImageLib()` plus the ordinary destructor body should regenerate the wrapper.
```

## Support Docs To Update

Required target update:

- [UID:0002VN] `by-memory/0x004e6870-0x004e68a8.NewHumanImageLibScalarDeletingDestructor.md`: update score to `86/91`, add the 2026-06-17 live IDA and PE-scan evidence, clarify that the source declaration is `virtual ~NewHumanImageLib();`, explicitly reject copying generated `simroot_v2` scalar-wrapper code, and keep the formal C++ block blank.

Recommended no-score support notes, if supervisor wants provenance:

- [UID:000092] `by-class/NewHumanImageLib.md`: optional one-line change note that B002 2026-06-17 reconfirmed [UID:0002VN] as generated-binary scalar wrapper and not source-authored C++.
- [UID:0000LR] `by-file/NewHumanImageLib.md`: optional one-line generated-output caveat that active `auto-generated/NexusTK/render/NewHumanImageLib.cpp` is zero bytes and `simroot_v2` should not be copied for the wrapper.
- [UID:0001Y9] `by-type/by-vtable/NewHumanImageLibVtable.md`: no required change; current slot and xref facts match live evidence.
- [UID:00017S] ordinary destructor page: no required change; current caller/delete-route relationship is valid.

No support-doc score changes are required by this report.

## Validation Commands

Commands already run for research:

> Executable block R001 was removed from this report and preserved verbatim in [0002VN-newhuman-scalar-deleting-destructor-source-quality-removed.md](0002VN-newhuman-scalar-deleting-destructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended supervisor validation after applying target/support changes:

> Executable block R002 was removed from this report and preserved verbatim in [0002VN-newhuman-scalar-deleting-destructor-source-quality-removed.md](0002VN-newhuman-scalar-deleting-destructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor also applies the manual coverage row replacement:

> Executable block R003 was removed from this report and preserved verbatim in [0002VN-newhuman-scalar-deleting-destructor-source-quality-removed.md](0002VN-newhuman-scalar-deleting-destructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Report-Only Compliance

This report does not directly edit by-* docs, generated reports, generated source, the IDA database, or `by-memory/-coverage-report.md`. The only requested supervisor-owned manual coverage change is the exact replacement row above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002VN-newhuman-scalar-deleting-destructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002VN"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002VN-newhuman-scalar-deleting-destructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002VN-newhuman-scalar-deleting-destructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002VN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
