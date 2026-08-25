** TARGET-REPORT-UID:000325 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000325 StringBaseAppendWideLiteral Source-Quality Research

Assignment: `B001 new report-only assignment, 2026-06-19`  
Agent: `Agent-B001`  
Date: `2026-06-19`  
Target: `[UID:000325] by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md`  
Requested mode: report-only. No by-* documentation edits. No `by-memory/-coverage-report.md` edit.

## Finalized Report / Current Recommendation

Keep the current source owner and emitter route:

```text
CANONICAL_OWNER: 0000OA
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000OA
```

Recommended metadata after a future implementation pass incorporates this report into the target/support docs:

```text
COMPLETION: 88
CONFIDENCE: 90
CANONICAL_OWNER: 0000OA
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000OA
RECONSTRUCTION_CPP CODE: first-draft C++ is safe
```

The current `85/87` state is defensible but shallow. It records the correct high-level behavior and owner, but it still leaves source-quality gaps around the exact range/padding, source-facing method role, counted callee semantics, generated name cleanup, and first-draft C++ eligibility. With this report incorporated, `88/90` is justified. I do not recommend a higher score because the exact original public spelling remains not symbol-proven: the binary behavior strongly supports a `StringBase<wchar_t>::operator+=(const wchar_t*)` style wrapper, while the current documentation name `StringBaseAppendWideLiteral` remains the safest descriptive/generated name.

Best source-quality role:

```text
pointer-backed UTF-16 StringBase append wrapper for a NUL-terminated wide literal/source string
```

Best binary ABI signature:

```cpp
StringBaseW *__thiscall StringBaseAppendWideLiteral(StringBaseW *self, const wchar_t *rhs);
```

Best source-facing method interpretation:

```cpp
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>&
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>::operator+=(const wchar_t* rhs);
```

Conservative source-facing fallback if the supervisor does not accept operator spelling yet:

```cpp
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>&
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>::AppendWideLiteral(const wchar_t* rhs);
```

Best counted-callee relationship:

```cpp
// 0x00584470
StringBaseW *__thiscall AppendWideLiteral(StringBaseW *self, const wchar_t *rhs, unsigned int maxCodeUnits);
```

`0x00584470` should no longer be surfaced as `sub_584470` in final prose except as a historical/search label. The older `AppendWideData` name is weaker than `AppendWideLiteral` because the callee itself scans the NUL-terminated UTF-16 source and clamps the requested count to the source length. It is not a raw byte-buffer append.

Recommended source placement:

```text
Direct source owner: [UID:0000OA] StringBase
Generated route: auto-generated/NexusTK/util/StringBase.cpp
Likely original declaration home: util/StringBase.h or util/StringUtil.h
Likely source/header role: template/member wrapper, possibly header-defined and emitted out-of-line through COMDAT/template instantiation
```

`Application::DetectOS` is only a consumer. `StringUtil` is only the broader utility umbrella. The physical neighborhood is a mixed linker/codegen island, not proof of `Application.cpp` ownership.

## Target

Target document:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004671b0-0x004671de.StringBaseAppendWideLiteral.md
```

Current metadata:

```text
UID: 000325
COMPLETION: 85
CONFIDENCE: 87
CANONICAL_OWNER: 0000OA
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000OA
RECONSTRUCTION_CPP CODE: blank
```

Current direct owner:

```text
[UID:0000OA] by-file/StringBase.md
```

Current generated route:

```text
auto-generated/NexusTK/util/StringBase.cpp
```

Current target summary is already directionally correct:

- receives a pointer-backed string object in `ecx`;
- receives a NUL-terminated UTF-16 source pointer at `[ebp+8]`;
- measures the source length with an inline `wcslen`-equivalent loop;
- forwards `(source, count)` to `0x00584470`;
- is called by `Application::DetectOS` for the `_32bit` / `_64bit` OS-label suffix;
- belongs to `StringBase`, not to `Application`.

The implementation callback should strengthen the page with the exact reanalysis below rather than changing the owner route.

## Assignment Requirements Check

- Followed `Supervisor.md` and `.codex/AGENTS.md` workflow: this is report-only research, not direct by-* incorporation.
- Did not edit by-* documentation.
- Did not edit `by-memory/-coverage-report.md`.
- Included this required section: `## Heuristic / Inference Reanalysis And Validation`.
- Rechecked exact range, padding, caller, callee, source placement, generated/compiler names, `sub_584470` relationship, UTF-16 length/count semantics, and C++ readiness.
- Included rejected alternatives, open-question closure, proposed metadata, exact support-doc checklist, exact supervisor-owned coverage row, and scoped validator baseline/result.
- Used current support docs as prior evidence and revalidated the critical facts with a local read-only PE byte/disassembly/call-reference scan because the live IDA MCP port was not reachable in this session.

## Inference Research Guidance Check

I treated existing documentation as prior evidence, not as authority. Accepted facts come from:

- current target/support docs that cite earlier live IDA MCP sessions;
- current `StringBase`, `StringUtil`, `StringBaseAppendAndFind`, `ApplicationFunctionObject0Callbacks`, and `ApplicationDetectOS` pages;
- current generated/manual coverage rows;
- local read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`;
- local Capstone disassembly and raw `E8 rel32` direct-call scan.

IDA MCP status for this report:

- Port check for `127.0.0.1:13337` returned `TcpTestSucceeded=False`.
- I do not claim fresh live-IDA MCP output for this pass.
- Earlier project docs already contain live IDA-backed findings for the same function family; this report labels local revalidation as local PE evidence.

## Heuristic / Inference Reanalysis And Validation

### What This Helper Is

The direct bytes prove a one-argument `thiscall` wrapper over the wide `StringBase` counted append helper:

```text
ECX          = pointer-backed wide StringBase object / this
[EBP + 0x08] = const wchar_t *rhs
return       = callee return, effectively self / this
callee       = 0x00584470 counted wide literal append helper
```

The target does not allocate, copy, grow, or mutate string-buffer storage directly. It computes the UTF-16 code-unit length of the incoming NUL-terminated source and delegates all mutation to `0x00584470`.

The wrapper body is source-authored or template/header-authored project code. It is not CRT code, not an SEH thunk, not a scalar deleting destructor, and not padding.

### Exact Local Disassembly

Read-only PE scan of `NexusTK.exe` confirms image base `0x00400000` and `.text` coverage over this address. Target bytes:

```text
0x004671b0-0x004671de:
55 8b ec 8b 55 08 8b c2 56 57 8b f1 8d 78 02
90 66 8b 08 83 c0 02 66 85 c9 75 f5 2b c7 8b
ce d1 f8 50 52 e8 98 d2 11 00 5f 5e 5d c2 04 00
```

Disassembly:

```text
0x004671b0: push    ebp
0x004671b1: mov     ebp, esp
0x004671b3: mov     edx, dword ptr [ebp + 8]
0x004671b6: mov     eax, edx
0x004671b8: push    esi
0x004671b9: push    edi
0x004671ba: mov     esi, ecx
0x004671bc: lea     edi, [eax + 2]
0x004671bf: nop
0x004671c0: mov     cx, word ptr [eax]
0x004671c3: add     eax, 2
0x004671c6: test    cx, cx
0x004671c9: jne     0x4671c0
0x004671cb: sub     eax, edi
0x004671cd: mov     ecx, esi
0x004671cf: sar     eax, 1
0x004671d1: push    eax
0x004671d2: push    edx
0x004671d3: call    0x584470
0x004671d8: pop     edi
0x004671d9: pop     esi
0x004671da: pop     ebp
0x004671db: ret     4
```

The `ret 4` confirms one stack argument and `thiscall` receiver in `ecx`. The callee at `0x00584470` receives arguments in this order after the pushes:

```text
[callee EBP + 0x08] = rhs/source pointer
[callee EBP + 0x0c] = computed UTF-16 code-unit count
```

### UTF-16 Length / Count Semantics

The loop is an inline `wcslen`-equivalent over 16-bit code units, not bytes and not Unicode scalar values.

Step-by-step:

```text
edx = rhs
eax = rhs
edi = rhs + 2

loop:
    cx = *(uint16_t *)eax
    eax += 2
    if (cx != 0) goto loop

countBytes = eax - (rhs + 2)
count = countBytes >> 1
```

For a source with `N` nonzero UTF-16 code units followed by a NUL word:

```text
eax after loop = rhs + 2 * (N + 1)
edi            = rhs + 2
eax - edi      = 2 * N
(eax - edi)>>1 = N
```

Therefore:

- the count excludes the NUL terminator;
- the count is in UTF-16 code units;
- surrogate pairs count as two code units;
- the helper does not check for `nullptr`;
- an empty string produces count `0`;
- `sar eax, 1` reflects signed pointer-difference code generation, but the computed value is nonnegative for a valid NUL-terminated source.

This target should not be described as appending a byte length, a terminator-inclusive count, or a UTF-8/ANSI string.

### Range And Padding Decisions

The exact range remains:

```text
0x004671b0-0x004671de
```

Local PE bytes around the target:

```text
0x004671a0-0x004671ad: previous helper body
0x004671ad-0x004671b0: cc cc cc
0x004671b0-0x004671de: target, 46 bytes, ends with c2 04 00
0x004671de-0x004671e6: successor Application destructor adjustor thunk
0x004671e6-0x004671f0: cc cc cc cc cc cc cc cc cc cc
```

Predecessor bytes/disassembly:

```text
0x004671a0: mov     eax, ecx
0x004671a2: mov     ecx, dword ptr [eax + 0x10]
0x004671a5: add     ecx, dword ptr [eax + 0xc]
0x004671a8: mov     eax, dword ptr [eax + 8]
0x004671ab: jmp     eax
0x004671ad: int3
0x004671ae: int3
0x004671af: int3
```

Successor bytes/disassembly:

```text
0x004671de: sub     ecx, 4
0x004671e1: jmp     0x467230
0x004671e6: int3
...
0x004671ef: int3
```

Closure:

- no split is needed inside `0x004671b0-0x004671de`;
- the target does not include the three `0xcc` bytes before it;
- the target does not include any post-body padding;
- successor starts immediately at `0x004671de`;
- the mixed parent aggregate's child boundary is correct.

### Caller / Reachability Evidence

Raw `E8 rel32` scan over `.text` found exactly one direct call to this target:

```text
to 0x004671b0: 1 direct call
0x0046509f -> 0x004671b0
```

Caller block:

```text
0x00465072: push    0x6128d4        ; L"Windows8"
0x00465077: jmp     0x46507e
0x00465079: push    0x6128a0        ; L"Windows7"
0x0046507e: lea     esi, [edi + 0x854]
0x00465084: mov     ecx, esi
0x00465086: call    0x582d20        ; assign base OS label
0x0046508b: cmp     byte ptr [edi + 0x18], 0
0x0046508f: mov     ecx, 0x6128c4   ; L"_32bit"
0x00465094: mov     eax, 0x6128b4   ; L"_64bit"
0x00465099: cmove   eax, ecx
0x0046509c: mov     ecx, esi
0x0046509e: push    eax
0x0046509f: call    0x4671b0
0x004650a4: jmp     0x4650fe
```

Decoded nearby UTF-16 literals from the same local scan:

```text
0x006128d4 -> L"Windows8"
0x006128a0 -> L"Windows7"
0x006128c4 -> L"_32bit"
0x006128b4 -> L"_64bit"
0x00612830 -> L"Windows2000"
```

This caller is inside `[UID:0002H5] ApplicationDetectOS`. It appends a bitness suffix to the OS label string at `Application + 0x854`. This explains the sole observed call without changing ownership: Application consumes a general wide string append wrapper.

### Callee Evidence And `sub_584470` Relationship

The target has exactly one direct call:

```text
0x004671d3 -> 0x00584470
```

Raw direct-call scan found seven direct calls to `0x00584470`:

```text
0x004671d3
0x00493d57
0x0056bfc9
0x005c2e05
0x005c2ebf
0x005c30d3
0x005c318d
```

This broad caller spread matches `[UID:0002RS] StringBaseAppendAndFind`, which currently documents `0x00584470-0x00584531` as `AppendWideLiteral` and records seven call sites from four functions. The local raw scan gives the exact call-site addresses; the support doc gives the function-level grouping.

Important `0x00584470` behavior from local disassembly and current support docs:

- reads the destination string data pointer through `*self`;
- reads the ref-counted header fields at data pointer `-0x0c`, `-0x08`, and `-0x04`;
- scans the incoming UTF-16 source to its NUL terminator;
- reads the requested count from `[ebp+0x0c]`;
- clamps to the NUL-terminated source length;
- uses fast in-place append when the buffer is writable and capacity is sufficient;
- otherwise calls `0x00582fa0` to grow/detach the wide buffer;
- copies `2 * count` bytes with `_memmove` at `0x005c95b0`;
- writes a wide NUL terminator and updates stored length;
- returns `self`.

The callee is therefore a counted, NUL-terminated wide-literal append helper. The older `AppendWideData` spelling should be rejected for final prose because true raw data append would not need to rescan/clamp a NUL-terminated source.

### Field / Type / Global Meaning

No target-local global is read or written. All durable state belongs to the destination `StringBase` object and is mutated by `0x00584470`.

Best recovered target-local roles:

| Binary item | Meaning |
| --- | --- |
| `ecx` at entry | `this`, pointer-backed wide `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` object |
| `[ebp+8]` / `edx` | `const wchar_t *rhs`, NUL-terminated UTF-16 source |
| `eax` in loop | scanning cursor advanced by two bytes per code unit |
| `cx` | current UTF-16 code unit |
| `edi` | `rhs + 2`, used to compensate for post-increment before computing length |
| pushed `eax` | source length in UTF-16 code units, excluding terminator |
| pushed `edx` | original source pointer |

Best recovered `StringBase` storage model from support docs:

| Data-relative offset | Meaning |
| --- | --- |
| `data - 0x0c` | `refCount` |
| `data - 0x08` | current character count, excluding terminator |
| `data - 0x04` | capacity |
| `data + 0x00` | ANSI or UTF-16 character data |

Relevant global/string-family context:

- wide empty sentinel `0x00670278`;
- ANSI empty sentinel `0x00670290`;
- small buffer pools under `0x0069bacc-0x0069bbe4`;
- preserved compiler metadata names for `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>`.

This target itself does not touch the sentinels or pools directly.

### Generated / Compiler Names Reanalysis

Names that should remain only as historical/search labels:

```text
sub_4671B0
sub_584470
sub_464F50
AppendWideData
ApplicationFunctionObject0Callbacks as a source owner
```

Names with current source-quality support:

```text
StringBaseAppendWideLiteral
AppendWideLiteral
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>
mystr::mychar_traits<wchar_t>
Application::DetectOS
StringBase
StringUtil as utility-string umbrella
```

The preserved compiler/type metadata supports the `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` type family. It does not prove the exact original method spelling at `0x004671b0`.

`operator+=(const wchar_t*)` is the strongest source-facing method inference because:

- the ABI is a member function with one `const wchar_t*` argument;
- the body appends the entire NUL-terminated source to `this`;
- the callee returns `self`, matching chaining-friendly string append/operator behavior;
- a non-authoritative tool-guide breadcrumb in the project mentions testing an `operator +=` method flag for `0x004671b0`.

However, since no symbol or RTTI string directly names this exact method, keep `StringBaseAppendWideLiteral` as the documentation/generated target name and describe `operator+=` as the best source-facing reconstruction rather than symbol-proven fact.

### Owner / Source Placement

Keep:

```text
CANONICAL_OWNER: 0000OA
EMITTER_UIDS: 0000OA
Generated output: auto-generated/NexusTK/util/StringBase.cpp
```

Owner ranking:

1. `[UID:0000OA] StringBase`: direct semantic owner. The target is a wrapper over the ref-counted pointer-backed wide string implementation, and the sole callee is the shared StringBase append helper.
2. `[UID:0000OB] StringUtil`: valid umbrella/coordinator only. Its own docs delegate the ref-counted ANSI/UTF-16 implementation to `StringBase`.
3. `[UID:00000D] Application`: consumer only. It passes its OS-label string and suffix literal but does not own the generic string append semantics.
4. `[UID:0000YU] ApplicationFunctionObject0Callbacks`: physical mixed aggregate only. It is not a source file and is already non-emitting.

The physical placement near Application callback/destructor glue is consistent with an out-of-line template/member wrapper being emitted in a mixed linker island. It is not stronger than the direct string-family behavior and callee evidence.

### First-Draft C++ Readiness

First-draft C++ is now safe for this target because:

- the function range is exact;
- the body is small and fully understood;
- all side effects are delegated to an already documented StringBase counted append helper;
- `this`, argument, count, return, and callee relationship are clear;
- the target clears the code-entry gate with current `85/87` average `86.0`, and the recommended `88/90` would strengthen that gate further;
- the direct owner/emitter route is valid and surfaces to `auto-generated/NexusTK/util/StringBase.cpp`.

Recommended first-draft body if operator spelling is accepted:

```cpp
namespace mystr {

template <>
StringBase<wchar_t, mychar_traits<wchar_t>>&
StringBase<wchar_t, mychar_traits<wchar_t>>::operator+=(const wchar_t* rhs)
{
    const wchar_t* end = rhs;
    while (*end != L'\0') {
        ++end;
    }

    return this->AppendWideLiteral(rhs, static_cast<unsigned int>(end - rhs));
}

}
```

Conservative equivalent if the implementation pass keeps the descriptive generated method name:

```cpp
namespace mystr {

template <>
StringBase<wchar_t, mychar_traits<wchar_t>>&
StringBase<wchar_t, mychar_traits<wchar_t>>::AppendWideLiteral(const wchar_t* rhs)
{
    const wchar_t* end = rhs;
    while (*end != L'\0') {
        ++end;
    }

    return this->AppendWideLiteral(rhs, static_cast<unsigned int>(end - rhs));
}

}
```

Implementation caveat:

- The count-taking helper declaration must exist or be introduced consistently. In prose, the callee can be described as `AppendWideLiteral(const wchar_t*, unsigned int maxCodeUnits)`.
- If overloading creates ambiguity in the final generated skeleton, use a lower-level reconstructed name for the counted helper, such as `AppendWideLiteralCounted` or `AppendWideLiteralBounded`, and document that this is an emitter convenience rather than proven original spelling.
- Do not emit a raw `return sub_584470(this, Src, wcslen(Src));` decompiler artifact.

### Rejected Alternatives

Rejected: `Application` direct ownership.

- Evidence for rejection: the only direct caller is Application, but the target performs generic string append/count work; its sole callee is a shared StringBase append routine with seven direct call sites across multiple functions. Application supplies `_32bit` / `_64bit` as data, not policy or storage semantics.

Rejected: `StringUtil` direct ownership.

- Evidence for rejection: `StringUtil` is the utility-string umbrella, but current `StringBase.md`, `StringBaseTemplate.md`, `RefCountedStringBufferHeader.md`, and `StringBaseAppendAndFind.md` all route the ref-counted ANSI/UTF-16 pointer-backed implementation to `StringBase`.

Rejected: `AppendWideData` as the best callee name.

- Evidence for rejection: `0x00584470` scans the source for NUL and clamps the requested count to `wcslen(src)`; a raw data append would not do this. `AppendWideLiteral` or `AppendWideLiteralCounted` is more accurate.

Rejected: byte-count semantics.

- Evidence for rejection: the target advances by two bytes per loop iteration, divides the byte difference by two, and the callee copies `2 * count` bytes. The parameter is a UTF-16 code-unit count.

Rejected: terminator-inclusive count.

- Evidence for rejection: `edi = rhs + 2` compensates for the loop's post-increment past the NUL. Empty string yields count zero, and `N` nonzero code units yield count `N`.

Rejected: direct CRT `wcslen` call in this wrapper.

- Evidence for rejection: there is no call to CRT `wcslen`; the body contains an inline NUL-scan loop. It is acceptable to describe it as `wcslen`-equivalent, but the target should not claim a direct import call.

Rejected: null-safe helper.

- Evidence for rejection: the first memory read is `word ptr [eax]` with `eax = rhs`; no null check appears before dereference.

Rejected: split/range change.

- Evidence for rejection: the target ends at `ret 4` at `0x004671db-0x004671de`; the successor thunk starts immediately at `0x004671de`; the only nearby gaps are `0xcc` padding before the target and after the successor thunk.

Rejected: compiler-generated destructor/thunk classification.

- Evidence for rejection: the target has a normal frame, scans a source string, calls a StringBase append helper, and returns with one argument popped. The adjacent `0x004671de` function is the destructor adjustor thunk; this target is not.

## Evidence Sources Rechecked

### Current Target Doc

`by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md` currently has:

```text
UID: 000325
COMPLETION: 85
CONFIDENCE: 87
CANONICAL_OWNER: 0000OA
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000OA
RECONSTRUCTION_CPP CODE: blank
```

Valid current claims:

- exact range `0x004671b0-0x004671de`;
- direct owner `StringBase`;
- `StringUtil` as related umbrella;
- parent aggregate `ApplicationFunctionObject0Callbacks`;
- inline wide length scan;
- call to `0x00584470`;
- sole known caller from `Application::DetectOS` at `0x0046509f`;
- Application OS-label suffix use.

Needed target improvements:

- add exact local disassembly and padding;
- replace `sub_584470` final prose with `AppendWideLiteral` / counted wide append helper;
- clarify `wcslen` as inline equivalent, not direct call;
- document code-unit count semantics;
- document direct call-site list for `0x00584470`;
- state C++ readiness and source-facing signature;
- add rejected alternatives and open-question closure;
- raise scores if accepted.

### StringBase

`by-file/StringBase.md` is the direct source-owner support page:

- current score `88/86`;
- proposed module `util/StringBase.cpp`;
- proposed header `util/StringBase.h` or `util/StringUtil.h`;
- records `StringBaseAppendWideLiteral` as a pointer-backed wide literal append wrapper;
- states that `Application` is only the observed consumer;
- documents the `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` compiler metadata and ref-counted string-buffer family.

No owner change is needed. A future implementation pass can add one sentence to the existing 2026-06-10 change note saying the 2026-06-19 B001 source-quality recheck resolved the wrapper's exact bytes, operator-style source-facing signature candidate, and counted-callee relationship. The file score can remain `88/86`; this target's score can rise independently.

### StringUtil

`by-file/StringUtil.md` remains a broader utility-string coordination page. It explicitly prefers `StringBase` / `util/StringBase.cpp` for the ref-counted ANSI/UTF-16 buffer implementation. No target ownership should move to `StringUtil`.

Recommended future edit: none required for this target unless the supervisor wants an additional cross-reference note.

### StringBaseAppendAndFind

`by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md` currently documents `0x00584470-0x00584531` as:

```text
AppendWideLiteral - Appends up to count UTF-16 code units from a NUL-terminated source pointer, clamping to wcslen(Src).
```

This is the correct support interpretation for `sub_584470`.

Recommended future edit:

- optionally add the exact local direct call-site list from this report:

```text
0x004671d3, 0x00493d57, 0x0056bfc9, 0x005c2e05, 0x005c2ebf, 0x005c30d3, 0x005c318d
```

- no score change is required unless the support page is also being refreshed.

### ApplicationFunctionObject0Callbacks

`by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md` is a non-emitting mixed physical island. It already lists:

```text
0x004671b0-0x004671de -> [UID:000325] pointer-backed UTF-16 append/count helper -> [UID:0000OA] StringBase
0x004671ad-0x004671b0 -> padding
0x004671de-0x004671e6 -> Application adjustor thunk
0x004671e6-0x004671f0 -> padding before next child
```

This report confirms that split. No owner or range change is needed.

Recommended future edit: optional change note only, not required.

### ApplicationDetectOS

`by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md` already records the caller relationship:

- `Application + 0x854` OS label string;
- `Application + 0x18` WOW64 byte;
- `_64bit` / `_32bit` suffix appended through `StringBaseAppendWideLiteral`;
- `Application` source owner for OS detection policy.

This report confirms the exact caller block at `0x00465072-0x004650a4` and the sole direct call at `0x0046509f`.

Recommended future edit: optional detail only. Do not move the string helper into Application.

### Type / Layout Support

Relevant support pages:

- `[UID:0001WS] StringBaseTemplate`;
- `[UID:0001VQ] RefCountedStringBufferHeader`;
- `[UID:0001W4] SimpleUStringPointerBackedLayout`.

They support these target statements:

- object field `0x00` is a character-data pointer;
- header lives at data pointer `-0x0c` through `-0x04`;
- `data[-2]` / `data - 0x08` is character count excluding terminator;
- direct owner is `StringBase`;
- `SimpleUString` is alias/facade context, not direct owner for this target;
- exact public API spelling remains below final confidence.

No type-page edits are required for this target.

## Open-Question Closure

| Question | Closure |
| --- | --- |
| Is the exact range correct? | Yes. Keep `0x004671b0-0x004671de`; 46 bytes; ends with `ret 4`; successor starts immediately at `0x004671de`. |
| Is there pre/post padding inside the target? | No. Pre-target `0x004671ad-0x004671b0` is three `0xcc` bytes. No post-target padding before successor. |
| Is this Application-owned because only Application calls it? | No. Application is the only direct caller of this wrapper but is only a consumer; StringBase owns the helper semantics. |
| Should this be owned by StringUtil? | No direct ownership. `StringUtil` remains umbrella; `StringBase` owns the ref-counted pointer-backed implementation. |
| What is `sub_584470`? | The counted wide literal append helper at `0x00584470`, currently best named `AppendWideLiteral` or `AppendWideLiteralCounted`, not a raw `AppendWideData` helper. |
| What does the target count? | UTF-16 code units excluding the NUL terminator. It does not count bytes, scalar values, or the terminator. |
| Is the target null-safe? | No evidence. It dereferences the source immediately. |
| Is first-draft C++ safe? | Yes, with a source-name caveat. The behavior is source-ready; exact operator vs named method spelling is still below final-symbol proof. |
| Should generated/compiler names be cleaned? | Yes. Future target prose should retain `sub_4671B0`/`sub_584470` only as historical labels and use `StringBaseAppendWideLiteral` / `AppendWideLiteral` for documentation. |
| Does this require changing `ApplicationFunctionObject0Callbacks` split? | No. The existing child split is correct. |

## Proposed Metadata / Score Rationale

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion `88`: exact bytes, boundaries, pre/successor padding, caller, callee, type/field roles, UTF-16 count semantics, owner ranking, generated-name cleanup, and C++ readiness are now all resolved to source-quality level.
- Confidence `90`: local PE evidence, prior IDA-backed docs, support pages, generated route, and caller/callee behavior all agree. Confidence remains below final because original method spelling (`operator+=` vs named append overload) and exact public header/facade split are not symbol-proven.

Do not raise to `95+` in this pass. This is first-draft source quality, not final original-source proof.

## Current Coverage / Generated Rows

Current generated coverage row observed in `auto-generated/-ag-memory-coverage.md`:

```text
| [UID:000325][0x004671b0-0x004671de.StringBaseAppendWideLiteral](by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md) | emits | `0000OA` | `0000OA` |  | no | `auto-generated/NexusTK/util/StringBase.cpp` | `by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md` |  |
```

This generated route is correct and should remain unchanged.

Current manual coverage row observed in `by-memory/-coverage-report.md`:

```text
        - [UID:000325][0x004671b0-0x004671de.StringBaseAppendWideLiteral](by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md) 0x004671b0-0x004671de | string helper | StringBaseAppendWideLiteral : reconstructable : 85% : strong : Exact UTF-16 literal append/count helper assigned to [UID:0000OA][StringBase](by-file/StringBase.md); IDA confirms `wcslen` plus shared append callee `0x00584470`, with Application setup as consumer.
```

## Exact Supervisor-Owned Coverage Row Text

Recommended replacement row for supervisor-owned `by-memory/-coverage-report.md`, at the same nested location, if the supervisor accepts the `88/90` target score and source-quality update:

```text
        - [UID:000325][0x004671b0-0x004671de.StringBaseAppendWideLiteral](by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md) 0x004671b0-0x004671de | string helper | StringBaseAppendWideLiteral : reconstructable : 88% : strong : B001 2026-06-19 source-quality reanalysis keeps StringBase (`0000OA`) as owner/emitter for this pointer-backed UTF-16 append wrapper. Local PE recheck confirms the exact 46-byte `0x004671b0-0x004671de` range, predecessor `0x004671ad-0x004671b0` `0xcc` padding, no post-target padding before the `0x004671de` Application destructor adjustor thunk, one direct caller at `0x0046509f` in `Application::DetectOS`, and the sole target call at `0x004671d3` to shared counted wide append helper `0x00584470`. The body is a thiscall wrapper over `mystr::StringBase<wchar_t,mystr::mychar_traits<wchar_t>>`: it scans the NUL-terminated wide source in UTF-16 code units, computes a count excluding the terminator, pushes `(source,count)`, and forwards to `AppendWideLiteral`/counted append. Application only appends `_32bit`/`_64bit` suffixes to its OS-label string; `StringUtil` remains an umbrella, not direct owner. First-draft C++ is safe as a `StringBase` wide literal append/operator-plus-equals wrapper once the counted helper declaration is available.
```

If the supervisor does not accept the score increase yet, keep `85%` but replace the row body with the same evidence summary adjusted to say the reanalysis keeps the current `85/87` metadata pending implementation.

## Target / Support Implementation Checklist

Future implementation callback checklist:

- Target `[UID:000325]`: update metadata to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000OA`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000OA`.
- Target `[UID:000325]`: keep range `0x004671b0-0x004671de`.
- Target `[UID:000325]`: add exact boundary/padding statement: `0x004671ad-0x004671b0` is three `0xcc` bytes; successor thunk starts at `0x004671de`; `0x004671e6-0x004671f0` is successor padding.
- Target `[UID:000325]`: document target disassembly or equivalent pseudocode showing `edx = [ebp+8]`, UTF-16 NUL scan, `(eax - (src + 2)) >> 1`, push count, push source, call `0x00584470`, `ret 4`.
- Target `[UID:000325]`: replace final prose `sub_4671B0` and `sub_584470` names with `StringBaseAppendWideLiteral` and `AppendWideLiteral` / counted wide append helper; retain `sub_*` only as historical labels in evidence.
- Target `[UID:000325]`: refine `wcslen` wording to "inline `wcslen`-equivalent loop" instead of direct CRT call.
- Target `[UID:000325]`: explicitly state the count is UTF-16 code units excluding the terminator, not bytes and not terminator-inclusive.
- Target `[UID:000325]`: add binary ABI signature `StringBaseW *__thiscall StringBaseAppendWideLiteral(StringBaseW *self, const wchar_t *rhs)`.
- Target `[UID:000325]`: add source-facing method inference: best `StringBase<wchar_t>::operator+=(const wchar_t*)`, conservative generated fallback `AppendWideLiteral(const wchar_t*)`.
- Target `[UID:000325]`: add `0x00584470` relationship: counted wide literal append helper, clamps to source `wcslen`, copies `2 * count` bytes, grows through `0x00582fa0`, returns self.
- Target `[UID:000325]`: add exact direct-call list: to target `0x0046509f`; from target `0x004671d3`; to counted helper `0x004671d3`, `0x00493d57`, `0x0056bfc9`, `0x005c2e05`, `0x005c2ebf`, `0x005c30d3`, `0x005c318d`.
- Target `[UID:000325]`: add caller context from `Application::DetectOS`: `Application + 0x854` OS label, `Application + 0x18` WOW64 flag, `_64bit`/`_32bit` literal selection.
- Target `[UID:000325]`: add first-draft C++ body if the implementation callback author accepts the operator or named-overload spelling and has a counted helper declaration in the generated parent.
- Target `[UID:000325]`: add rejected alternatives and open-question closure summarized above.
- Support `[UID:0000OA] StringBase`: optional change note only; keep score and route unless supervisor wants support-page update.
- Support `[UID:0000OB] StringUtil`: no required edit; do not make it direct owner.
- Support `[UID:0002RS] StringBaseAppendAndFind`: optional direct call-site refresh for `0x00584470`; no required score change.
- Support `[UID:0000YU] ApplicationFunctionObject0Callbacks`: no required edit; existing split/range is confirmed.
- Support `[UID:0002H5] ApplicationDetectOS`: no required edit; existing consumer relationship is confirmed.
- Supervisor coverage: replace the manual coverage row with the exact row above if accepting the score/evidence update.
- Validator after future implementation edits: run scoped file-mode validator with `--apply` on the target page, then run or inspect autogen for `StringBase.cpp` and generated memory coverage.

Suggested future validator commands if edits are applied:

> Executable block R001 was removed from this report and preserved verbatim in [000325-StringBaseAppendWideLiteral-source-quality-removed.md](000325-StringBaseAppendWideLiteral-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run support-page validators if those support pages are actually edited.

## Scoped Validator Baseline / Result

Command run without `--apply`:

> Executable block R002 was removed from this report and preserved verbatim in [000325-StringBaseAppendWideLiteral-source-quality-removed.md](000325-StringBaseAppendWideLiteral-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
exit code: 0
apply: False
scanned markdown files: 1
ok: 1
ok 000325 by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md UID header exists
dry run only; pass --apply to write changes
```

Relevant dry-run notes:

- `stats_incremental_skip` reported generated stats rows would need `--apply` to update.
- `auto-generated/NexusTK/util/StringBase.cpp` was reported unchanged in dry run.
- generated coverage reports were reported unchanged in dry run.
- unrelated existing warnings appeared, including missing registered `00039Y`, `autogen_cpp_conflict: 5`, and a few marker/fallback warnings; these are outside this target and were not changed.

No by-* or coverage file edit was made by this report-only pass.

## Local PE Scan Baseline

Executable scanned:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

Scanner environment:

```text
ImageBase: 0x00400000
.text VA: 0x00401000-0x0060c600
Capstone: 5.0.7
```

Key local findings:

```text
0x004671b0-0x004671de target bytes/disassembly confirmed
0x004671ad-0x004671b0 pre-target padding confirmed as cc cc cc
0x004671de successor thunk starts immediately after target
0x0046509f only direct call to target
0x004671d3 only direct call from target
0x00584470 has seven direct call sites in raw E8 scan
0x0046508f / 0x00465094 select L"_32bit" / L"_64bit"
```

This scan is read-only and did not write project documentation.

## Changed Files

Created this report only:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\000325-StringBaseAppendWideLiteral-source-quality.md
```

Files intentionally not edited:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004671b0-0x004671de.StringBaseAppendWideLiteral.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md
any by-* support document
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000325-StringBaseAppendWideLiteral-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:22","uid":"000325"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000325-StringBaseAppendWideLiteral-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000325-StringBaseAppendWideLiteral-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000325"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
