** TARGET-REPORT-UID:00018U **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00018U LanguageManLookupAndSingletonHelpers Source-Quality Report

Assignment id: `B007-goal2-language-man-lookup-singleton-helpers-source-quality-00018U-20260619`

Target: [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](../../../../../by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md)

Report-only scope: this pass edits no by-* target/support docs, generated files, IDA state, shared coverage files, or project-level files. The only intended output is this B007 research report.

## Current Recommendation

Recommended disposition: split [UID:00018U] into exact child pages and convert the current aggregate into a reviewed, non-emitting split index.

Recommended aggregate metadata after the implementation callback, in the target's current header schema:

```text
*** COMPLETION:90 ***
*** CONFIDENCE:92 ***
*** RECONSTRUCTABLE:FALSE ***
*** AUTOGEN_PARENT_UID: ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: ***
```

Equivalent recommendation if the callback validator migrates the file to the newer by-memory header schema:

```text
*** COMPLETION:90 ***
*** CONFIDENCE:92 ***
*** CANONICAL_OWNER:NONE ***
*** RECONSTRUCTABLE:FALSE ***
*** EMITTER_UIDS: ***
```

Comparable non-emitting aggregate pages clear source ownership/emitter metadata rather than retaining an autogen parent. Keep `LanguageMan.cpp` family context in prose and child links. The aggregate itself should not emit C++ and should not remain the source-bearing owner for three separate function bodies plus internal `0xcc` alignment.

Exact child split to create during callback:

| Range | Recommended child name | Direct owner/emitter | Score | C++ disposition |
| --- | --- | --- | --- | --- |
| `0x004f0350-0x004f0372` | `LanguageManGetLocalizedString` | [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md) / [UID:0000KK][LanguageMan.cpp](../../../../../by-file/LanguageMan.md) | `90/93` | First-draft method C++ ready. |
| `0x004f0380-0x004f03bb` | `LanguageManCopyLocalizedString` | [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md) / [UID:0000KK][LanguageMan.cpp](../../../../../by-file/LanguageMan.md) | `88/91` | Behavior is reconstructable; final formal C++ should remain blank unless the callback accepts a project-wide `StringBase<wchar_t>` placeholder. |
| `0x004f03c0-0x004f03cb` | `LanguageManClearSingletonHelper` | [UID:0000KK][LanguageMan.cpp](../../../../../by-file/LanguageMan.md) | `88/93` | First-draft static helper C++ ready. |

The internal padding subranges `0x004f0372-0x004f0380`, `0x004f03bb-0x004f03c0`, and `0x004f03cb-0x004f03d0` remain ignored `0xcc` alignment. Do not fold those bytes into child functions.

## Evidence Rechecked

I rechecked current target/support docs as leads rather than authority:

- [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](../../../../../by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md)
- [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md)
- [UID:000072][LanguageManager](../../../../../by-class/LanguageManager.md)
- [UID:0000KK][LanguageMan](../../../../../by-file/LanguageMan.md)
- [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](../../../../../by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md)
- [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](../../../../../by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md)
- [UID:00018T][0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer](../../../../../by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md)
- [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](../../../../../by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md)
- [UID:0000RC][g_pLanguageMan](../../../../../by-global/g_pLanguageMan.md)
- [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](../../../../../by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md)
- [UID:0001RP][str-res-localized-strings](../../../../../by-resource/str-res-localized-strings.md)
- [UID:00025M][0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData](../../../../../by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md)
- [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](../../../../../by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md)
- [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](../../../../../by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md)
- [UID:0000OA][StringBase](../../../../../by-file/StringBase.md), [UID:0002RN][0x005829f0-0x00582d80.StringBaseShareAssignAndAccess](../../../../../by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md), and [UID:0001W4][SimpleUStringPointerBackedLayout](../../../../../by-type/by-struct/SimpleUStringPointerBackedLayout.md) for the copy-helper destination type caveat.
- Generated output: `auto-generated/NexusTK/localization/LanguageMan.cpp`, `source-3/simroot_v2/class_LanguageMan.cpp`, and `source-3/simroot_v2/class_LanguageManager.cpp`.
- Current generated coverage/stats: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `by-memory/-coverage-report.md`.
- Prior same-UID report lead: `tools/leaser/Agents/Agent-B013/research/00018U-LanguageManLookupAndSingletonHelpers-source-quality.md`. That report correctly preserved many behavioral observations, but I reject its aggregate-emission recommendation for the reasons below.

IDA MCP was unavailable during this pass:

> Executable block R001 was removed from this report and preserved verbatim in [00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md](00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Because live IDA was unavailable, I used exported JSON and a local PE byte/disassembly check against `E:\NTK\Resources\NexusTK\NexusTK.exe` to revalidate facts instead of relying on current docs alone.

Local PE identity:

```text
MD5:    4247e04e20b65d6414c7238aa8ff5515
SHA256: 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632
.text:  0x00401000-0x0060c600
.rdata: 0x0060d000-0x0066c200
.data:  0x0066d000-0x0069ce24
```

Function byte boundaries and hashes:

| Range | Length | SHA-256 | Boundary result |
| --- | ---: | --- | --- |
| `0x004f0350-0x004f0372` | `34` | `15f821f96d589ecfba02a0746c953a7be8bf9694d0756443d6238abb341ab4f9` | Function body. |
| `0x004f0372-0x004f0380` | `14` | not needed | All `0xcc` padding. |
| `0x004f0380-0x004f03bb` | `59` | `22c41606ac8b845dcf22fbef97b8a254bd40fc58ceb3d62097775803a41129f0` | Function body. |
| `0x004f03bb-0x004f03c0` | `5` | not needed | All `0xcc` padding. |
| `0x004f03c0-0x004f03cb` | `11` | `13fa58a990345190b0d6e9b481f79a984e498af41e81f0c81ca6cedfbf5f8ce1` | Function body. |
| `0x004f03cb-0x004f03d0` | `5` | not needed | All `0xcc` padding. |
| `0x004f0350-0x004f03cb` | `123` | `48627aea821035fdf9ba6a3f95857a1ea607b9d737cf97f1e382aa115f16a54c` | Current aggregate span. |

Exported JSON findings:

- `resources/exported_data/functions/0x004f0350.json`: size `0x22`, names `meth_0x4f0350` / `sub_4F0350`, signatures include `wchar_t * __thiscall(..., int)` and `const wchar_t *__thiscall(_DWORD *this, int)`, `351` direct callers, zero callees, and decompilation matching the signed lower-bound/upper-bound string-table lookup.
- `resources/exported_data/functions/0x004f0380.json`: size `0x3b`, names `FUN_004f0380` / `sub_4F0380`, signature shape `void * __thiscall(this, out, int)` / `void **__thiscall(_DWORD *this, void **, int)`, exactly two direct callers, one callee, and decompilation matching the same bounds check followed by `sub_582560(out, selectedOrFallback)`.
- `resources/exported_data/functions/0x004f03c0.json`: size `0xb`, names `FUN_004f03c0` / `sub_4F03C0`, no arguments, no callees, no ordinary call refs, one near-jump reference from `0x00600a64`, and body `dword_67A750 = 0`.
- `resources/exported_data/functions/0x00582560.json`: size `0x3f`, names polluted as `LObject` / `sub_582560`, signature takes a UTF-16 source pointer, computes `wcslen`, allocates or grows through `0x00582e30`, copies through `memmove`, and returns the destination object. Its behavior is StringBase/wide assignment, not evidence for true `LObject` ownership.

Direct reference counts from local PE scan:

- Direct rel32 calls to `0x004f0350`: `351`.
- Direct rel32 calls to `0x004f0380`: `2`, at `0x00530c27` and `0x005c08a2`.
- Direct rel32 calls to `0x004f03c0`: `0`.
- Near jumps to `0x004f03c0`: `1`, at `0x00600a64`.
- Raw immediate/address references to `0x0061ca20`: two target refs, matching the fallback literal loads at `0x004f0369/0x004f036a` and `0x004f03a9/0x004f03aa`.
- Raw dword occurrences for `0x0067a750`: `192`, matching the established `g_pLanguageMan` singleton fanout.

Relevant disassembly facts:

```asm
; 0x004f0350
mov     eax, dword ptr [ebp+8]     ; string id
test    eax, eax
jl      fallback
cmp     eax, dword ptr [ecx+8]     ; m_stringCount
jge     fallback
mov     eax, dword ptr [ecx+4]     ; m_strings
mov     eax, dword ptr [eax+edx*4] ; m_strings[stringId]
ret     4
fallback:
mov     eax, 0x0061ca20            ; L"Invalid String ID"
ret     4

; 0x004f0380
mov     eax, dword ptr [ebp+0xc]   ; string id
mov     esi, dword ptr [ebp+8]     ; output string object
test    eax, eax
jl      fallback
cmp     eax, dword ptr [ecx+8]
jge     fallback
mov     eax, dword ptr [ecx+4]
push    dword ptr [eax+edx*4]
push    esi
call    0x00582560
mov     eax, esi
ret     8
fallback:
push    0x0061ca20
push    esi
call    0x00582560
mov     eax, esi
ret     8

; 0x004f03c0
mov     dword ptr [0x0067a750], 0
ret
```

Copy-helper call-site validation:

```asm
; NumberInputDialog, call site at 0x00530c27
mov     ecx, dword ptr [0x0067a750]
lea     eax, [ebp-0x14]
push    0xd9
push    eax
call    0x004f0380
...
mov     ecx, eax
call    0x00584540

; VirusChecker-family caller, call site at 0x005c08a2
mov     ecx, dword ptr [0x0067a750]
lea     eax, [ebp-0x10]
push    0xdd
push    eax
call    0x004f0380
```

Constructor-cleanup reference validation:

```asm
00600a5b: mov ecx, dword ptr [ebp-0x1034]
00600a61: add ecx, 4
00600a64: jmp 0x004f03c0
00600a69: lea ecx, [ebp-0x1030]
```

The cleanup jump shape explains why `0x004f03c0` has no ordinary call refs. It is still executable source behavior, but it is not a public class method.

## Current Metadata Recommendation And Score Justification

Current target metadata is:

```text
*** UID:00018U ***
*** COMPLETION:84 ***
*** CONFIDENCE:90 ***
*** RECONSTRUCTABLE:TRUE ***
*** AUTOGEN_PARENT_UID:0000KK ***
```

Recommended aggregate metadata is `90/92`, `RECONSTRUCTABLE:FALSE`, and cleared parent/emitter routing. In the current target schema that means blank `AUTOGEN_PARENT_UID`; in the migrated schema that means `CANONICAL_OWNER:NONE` and empty `EMITTER_UIDS`.

This is not a downgrade in evidence quality. It is a source-shape correction:

- The aggregate covers three distinct functions plus three internal padding spans. It is not a single original C++ function and should not emit one combined code block.
- The first two executable spans are class methods/helpers on the concrete [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md) object. The third is best modeled as a file-local cleanup helper in [UID:0000KK][LanguageMan.cpp](../../../../../by-file/LanguageMan.md).
- Function boundaries, padding boundaries, literal fallback behavior, field offsets, direct call counts, and caller identities are all now strong enough for a high-quality split-index parent.
- Remaining uncertainty is about public API spelling and string object type naming, not about the machine behavior. That caps child copy-helper formal C++, but it does not prevent the parent from being a reviewed split index.

Why not keep the aggregate at `84/90`: the old page still contains stale final-C++/gate language, treats the cluster as source-bearing, and leaves `LanguageMan` versus `LanguageManager` more open than the current evidence supports. The evidence now supports a higher score for documentation completeness while simultaneously removing aggregate emission.

Why not score the aggregate `95+`: exact original public spelling for the copy-output helper, the final destination string type name, and the source-level name of the cleanup helper remain inferred. Those are source-facing name/API caveats even though behavior is resolved.

## Heuristic / Inference Reanalysis And Validation

### LanguageMan Versus LanguageManager

Resolution: use `LanguageMan` as the canonical source-facing class and `LanguageMan.cpp` as the owner file. Treat `LanguageManager` as a generated alias/view, not a second original class.

Evidence checked:

- [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md), [UID:0000KK][LanguageMan](../../../../../by-file/LanguageMan.md), and [UID:00018R][LanguageManLocalization](../../../../../by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md) all tie the constructor/parser/destructors, lookup helpers, `str.res` ownership, and `g_pLanguageMan` lifecycle to `LanguageMan`.
- [UID:000072][LanguageManager](../../../../../by-class/LanguageManager.md) is already `COMPLETION:-1`, `CONFIDENCE:-1`, `RECONSTRUCTABLE:FALSE`, and documents itself as an ignored generated alias/view.
- Current generated/simroot output still emits `class_LanguageManager.cpp` for `0x004f0350`, but that output reads the same concrete object layout as `LanguageMan`: string table at `this+0x4` and count at `this+0x8`.
- Existing docs and exported evidence preserve `LanguageMan` and `Singleton<LanguageMan>` RTTI/name strings. I found no counter-evidence proving a separate `LanguageManager` allocation or RTTI/name identity.
- The global name `g_pLanguageMan` at `0x0067a750` is a strong source-facing ownership signal, and all broad lookup callers route through that singleton.

Rejected alternative: keep `LanguageManager::GetLocalizedString` as the canonical source name. This would let generated output continue unchanged, but it conflicts with stronger class/global/RTTI/source-file evidence and would perpetuate an artificial split between the constructor/destructor object and its lookup method.

Callback impact: fold the generated `class_LanguageManager.cpp` view into `LanguageMan.cpp` output and update support docs so `LanguageManager` remains only an alias/search page.

### Direct Lookup Helper Name And Signature

Recommended source-facing name/signature:

```cpp
const wchar_t *LanguageMan::GetLocalizedString(int stringId) const;
```

Evidence:

- The body is a true `thiscall` on the localization object: it reads `this+0x4` and `this+0x8`, takes one stack `int` argument, returns a `wchar_t const *`, and has no callees.
- The helper performs a signed lower-bound check and an upper-bound check against `m_stringCount`.
- It returns `m_strings[stringId]` when `0 <= stringId < m_stringCount`; otherwise it returns the static UTF-16 fallback literal at `0x0061ca20`.
- Existing target/support docs and the user assignment already use `GetLocalizedString`. This is the least disruptive high-probability source-facing spelling.

Rejected/alternate spelling: `LanguageMan::GetString(int)` or `LanguageMan::GetText(int)` cannot be ruled out from machine code alone. They are lower-priority because no current by-* doc or generated support standardizes them for this target, while `GetLocalizedString` is already present in the target/support ecosystem.

Callback impact: use `GetLocalizedString` in the child page, class page, file page, resource page, and generated C++. If later original-source evidence standardizes `GetString`, change all callers consistently in a separate pass.

### Copy-Lookup Helper Name And Signature

Recommended documentation name: `LanguageMan::CopyLocalizedString`.

Recommended ABI/source-doc signature:

```cpp
StringBase<wchar_t> *LanguageMan::CopyLocalizedString(StringBase<wchar_t> *out, int stringId) const;
```

Use `StringLike *` instead of `StringBase<wchar_t> *` in the child page's prose if the callback wants to avoid asserting the final public type before the string-family API is settled.

Evidence:

- The body is `thiscall` on `LanguageMan`.
- Stack argument one is the caller-provided output string object; stack argument two is the string id.
- It applies the same bounds check as `GetLocalizedString`.
- It calls `0x00582560(out, selectedStringOrFallbackLiteral)` in both valid and fallback branches and returns `out` in `EAX`.
- The two direct callers are exactly the already documented NumberInputDialog invalid-number path (`id 0xd9` / decimal `217`) and VirusChecker path (`id 0xdd` / decimal `221`).
- [UID:0001CY][NumberInputDialogActionHandler](../../../../../by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md) already documents the naming ambiguity as `LanguageMan::CopyLocalizedString` / `GetLocalizedString(out, id)`.
- String support docs identify the callee family around `0x00582560` as ref-counted StringBase/wide string assignment behavior, and current docs warn that old `LObject` names are recovery pollution.

Unresolved final API type:

- `StringBase<wchar_t>` is the strongest current source-family candidate because [UID:0000OA][StringBase](../../../../../by-file/StringBase.md), [UID:0001W4][SimpleUStringPointerBackedLayout](../../../../../by-type/by-struct/SimpleUStringPointerBackedLayout.md), and preserved `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` metadata support that family for pointer-backed ref-counted wide strings.
- `SimpleUString`, `WideString`, or a typedef/facade over `StringBase<wchar_t>` remain plausible public API spellings.
- The output-helper ABI resembles an explicit out-parameter helper, but it could also be a compiler-lowered return-by-value/sret form if the original source exposed a string-returning accessor. This cannot be proven safely from the two call sites alone.
- A by-value `GetLocalizedString(int)` returning a string object would collide at the source level with the pointer-returning `GetLocalizedString(int)` unless one of the two had a different public name. Since the pointer-return helper is already the stronger `GetLocalizedString` candidate, `CopyLocalizedString(out, id)` is the safer documentation name for the output helper.

Rejected alternative: emit final formal C++ for the copy helper using `SimpleUString` or STL-like `std::wstring`. `std::wstring` is not supported by the documented project string family here. `SimpleUString` is an alias/facade lead, not final enough for this helper. `StringBase<wchar_t>` is the best current family, but the public API spelling is still below final-source confidence.

Callback impact: create the exact child page and mark it reconstructable under `LanguageMan`. Include first-draft pseudocode if helpful, but leave formal C++ blank unless the callback explicitly accepts a placeholder type and labels it first-draft:

```cpp
StringLike *LanguageMan::CopyLocalizedString(StringLike *out, int stringId) const
{
    const wchar_t *text = GetLocalizedString(stringId);
    WideString_Assign(out, text);
    return out;
}
```

The placeholder names `StringLike` and `WideString_Assign` must not be treated as final source names.

### Singleton Clear Helper Name And Signature

Recommended source-facing name/signature:

```cpp
static void ClearLanguageManSingleton();
```

Acceptable documentation alias: `LanguageMan_ClearSingletonHelper`.

Evidence:

- The body has no `this` use, no stack arguments, no callees, and only stores zero to `g_pLanguageMan` at `0x0067a750`.
- It has no ordinary call refs. It is reached by a near jump from constructor cleanup metadata/code at `0x00600a64`.
- The surrounding constructor/destructor docs already prove other lifecycle writes/clears for `g_pLanguageMan`; this helper is a small cleanup/unwind support function, not an ownership-bearing class method.

Rejected alternatives:

- `LanguageMan::ClearSingleton()` as a public/static class method: possible at source level but not supported by direct method-call evidence, and the jump reference looks like compiler cleanup plumbing.
- Destructor body: rejected because the actual cleanup destructor and scalar deleting destructor have separate pages at `0x004f0290` and `0x004f03d0`; this helper only clears the singleton.
- Generic `Singleton<LanguageMan>` helper ownership: rejected for direct page ownership because the only concrete operation is the `LanguageMan.cpp` global storage clear. It can be cross-linked to singleton docs, but it should emit with `LanguageMan.cpp` if emitted at all.

Callback impact: create a small exact child page under [UID:0000KK][LanguageMan.cpp](../../../../../by-file/LanguageMan.md), not under [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md) as a public method.

### Field Names And Layout

Recommended field names:

```cpp
const wchar_t **m_strings; // this + 0x4
int m_stringCount;         // this + 0x8
```

Evidence:

- The constructor/parser page fills the table from `str.res`.
- The cleanup destructor iterates the table using `this+0x8` as the release count and frees strings through `this+0x4`.
- Both lookup helpers use `this+0x8` as the upper-bound count and `this+0x4` as an indexed pointer table.
- The direct lookup returns `dword ptr [m_strings + 4 * stringId]`, proving a pointer-sized table of string pointers rather than an inline string array.

Type caveat: the target only reads table entries and returns/copies them as UTF-16 literal/string pointers. `const wchar_t **` is the best first-draft source type. If constructor evidence later proves mutable allocation ownership requires `wchar_t **`, update the class layout without changing lookup behavior.

### Fallback Literal

Resolution: out-of-range ids use the UTF-16 literal `L"Invalid String ID"` at `0x0061ca20`.

Evidence:

- Direct lookup loads `0x0061ca20` in its fallback branch.
- Copy helper pushes `0x0061ca20` before calling the wide assignment helper in its fallback branch.
- [UID:00025M][KeySpeedStringResourceReadOnlyData](../../../../../by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md) and [UID:0001RP][str-res-localized-strings](../../../../../by-resource/str-res-localized-strings.md) already identify the literal and its xrefs.

Callback impact: place the fallback literal in child docs and support docs. Do not describe it as a resource-table string id; it is a static diagnostic fallback literal adjacent to the `str.res` / `Too many strings` read-only strings.

### Caller And Reachability Recheck

Direct lookup:

- `0x004f0350` has `351` direct rel32 call refs in the local PE/exported data recheck.
- The caller set is intentionally broad: startup, UI prompts, bulletin/mail/inventory command panes, scanner paths, and other text consumers.
- This high fanout supports keeping the method central on `LanguageMan`, not a local helper owned by any one caller family.

Copy helper:

- `0x004f0380` has exactly two direct rel32 callers:
  - `0x00530c27` inside [UID:0001CY][NumberInputDialogActionHandler](../../../../../by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md), passing id `0xd9` / `217`.
  - `0x005c08a2` inside [UID:0001NV][VirusCheckerV3LoadAndScan](../../../../../by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md), passing id `0xdd` / `221`.
- No third copy-helper caller was found in exported JSON or local PE direct-call scan.

Singleton clear helper:

- `0x004f03c0` has no ordinary direct calls and one near jump from `0x00600a64`.
- This is compatible with constructor cleanup/unwind placement and does not reduce confidence in the function body.

### Owner And Source Placement

Recommended owner/source placement:

- `0x004f0350`: [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md) method emitted by [UID:0000KK][LanguageMan.cpp](../../../../../by-file/LanguageMan.md).
- `0x004f0380`: [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md) helper/method emitted by [UID:0000KK][LanguageMan.cpp](../../../../../by-file/LanguageMan.md).
- `0x004f03c0`: file-local helper emitted by [UID:0000KK][LanguageMan.cpp](../../../../../by-file/LanguageMan.md), not a public `LanguageMan` method.
- Current aggregate [UID:00018U]: no direct source owner; it becomes a documentation index over the three source-bearing child pages and internal padding.

Rejected placements:

- [UID:000072][LanguageManager](../../../../../by-class/LanguageManager.md): generated alias only.
- [UID:0000OA][StringBase](../../../../../by-file/StringBase.md): only owns the copy callee/string destination mechanics, not the localization helper itself.
- `str.res` resource page: owns content/source data context, not executable lookup method ownership.
- A generic singleton helper file: not supported by an actual source-module page here; `LanguageMan.cpp` owns the concrete storage/lifecycle.

### Current Generated Output And Stale Gate Wording

Current generated output is stale:

- `auto-generated/NexusTK/localization/LanguageMan.cpp` and `source-3/simroot_v2/class_LanguageMan.cpp` omit `0x004f0380` and `0x004f03c0`.
- `source-3/simroot_v2/class_LanguageManager.cpp` emits `0x004f0350` as a separate `LanguageManager::GetLocalizedString` view.
- The current target page still references old final-C++/gate wording. Current B Rule 26 interpretation is not "wait for 95"; the relevant question is whether the specific source item is ready to emit coherent first-draft C++ under a valid owner/emitter.

Callback impact: remove stale 95-gate language. The aggregate has no-code because it is a split parent, not because it fails an obsolete score gate.

## Split / C++ Readiness Decision

[UID:00018U] as currently ranged is not class-level or function-level first-draft C++ ready. It should not emit code.

No-code/split proof:

- The current range includes three executable functions with distinct source shapes and internal padding.
- A single aggregate C++ block would either duplicate child behavior or combine unrelated functions into a non-source construct.
- The direct lookup method can emit clean first-draft C++ as a `LanguageMan` method.
- The singleton clear helper can emit clean first-draft C++ as a file-local helper.
- The copy-output helper is behaviorally reconstructable, but final formal C++ remains type/API-capped by the unresolved string facade. It should still be split as an exact child so later same-agent callback can either leave formal C++ blank or add a clearly first-draft placeholder.

Recommended first-draft C++ for the direct lookup child:

```cpp
const wchar_t *LanguageMan::GetLocalizedString(int stringId) const
{
    if (stringId >= 0 && stringId < m_stringCount) {
        return m_strings[stringId];
    }

    return L"Invalid String ID";
}
```

Recommended first-draft C++ for the singleton clear child:

```cpp
static void ClearLanguageManSingleton()
{
    g_pLanguageMan = 0;
}
```

Recommended copy-helper prose/pseudocode for the child page, not final formal C++ unless the callback accepts placeholders:

```cpp
StringLike *LanguageMan::CopyLocalizedString(StringLike *out, int stringId) const
{
    const wchar_t *text = GetLocalizedString(stringId);
    WideString_Assign(out, text);
    return out;
}
```

`StringLike` and `WideString_Assign` are placeholders for the unresolved public string type and `0x00582560` wrapper name. Do not invent STL containers here.

## Exact Implementation Checklist For Supervisor Callback

### Parent Target [UID:00018U]

1. Change metadata to the recommended aggregate values:
   - `COMPLETION:90`
   - `CONFIDENCE:92`
   - `RECONSTRUCTABLE:FALSE`
   - current header schema: clear `AUTOGEN_PARENT_UID` and `AUTOGEN_PARENT_POSITION_OPTIONAL`
   - migrated header schema: `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:` empty
2. Retitle/rewrite the page as a split index for the exact children:
   - `0x004f0350-0x004f0372` direct lookup method.
   - `0x004f0380-0x004f03bb` copy-output lookup helper.
   - `0x004f03c0-0x004f03cb` singleton-clear cleanup helper.
   - internal `0xcc` padding spans.
3. Remove stale wording that says final C++ is blank because of an old `95%` gate. Replace with the target-specific no-code/split proof.
4. Preserve exact evidence:
   - `351` direct lookup callers.
   - `2` copy-helper callers at `0x00530c27` and `0x005c08a2`.
   - one cleanup jump to `0x004f03c0` at `0x00600a64`.
   - field offsets `this+0x4` / `this+0x8`.
   - fallback literal `0x0061ca20`.
   - `0x00582560` wide StringBase assignment callee from the copy helper.
5. Do not include formal aggregate C++.

### Child Page: `0x004f0350-0x004f0372.LanguageManGetLocalizedString.md`

1. Create exact child page and let the validator assign a new UID.
2. Recommended metadata:
   - `COMPLETION:90`
   - `CONFIDENCE:93`
   - `CANONICAL_OWNER:000071`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:000071`
3. Use `LanguageMan::GetLocalizedString(int stringId) const` as the source-facing name.
4. Document exact behavior:
   - signed lower-bound check.
   - upper-bound check against `m_stringCount`.
   - return `m_strings[stringId]` for in-range ids.
   - return `L"Invalid String ID"` for fallback.
   - no callees.
   - `351` direct callers.
5. Add the first-draft C++ shown in this report.

### Child Page: `0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md`

1. Create exact child page and let the validator assign a new UID.
2. Recommended metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:91`
   - `CANONICAL_OWNER:000071`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:000071` if the callback decides to emit placeholder first-draft C++; otherwise leave `EMITTER_UIDS:` empty and state C++ is deferred for final public string type/API spelling.
3. Use `LanguageMan::CopyLocalizedString` as the documentation name.
4. Document exact ABI:
   - `thiscall`.
   - `ECX = LanguageMan`.
   - first stack arg is output string object pointer.
   - second stack arg is `stringId`.
   - returns output pointer in `EAX`.
5. Document exact behavior:
   - same string-id bounds check as direct lookup.
   - calls `0x00582560(out, selectedStringOrFallbackLiteral)` in both branches.
   - fallback literal `0x0061ca20`.
   - direct callers at `0x00530c27` and `0x005c08a2`.
6. Document unresolved final type:
   - `StringBase<wchar_t>` is the strongest source-family candidate.
   - `SimpleUString`/`WideString`/typedef facade remains possible.
   - hidden sret/by-value return shape is possible but not safe to emit as final source.
7. Do not invent `std::wstring` or STL containers.

### Child Page: `0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md`

1. Create exact child page and let the validator assign a new UID.
2. Recommended metadata:
   - `COMPLETION:88`
   - `CONFIDENCE:93`
   - `CANONICAL_OWNER:0000KK`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:0000KK`
3. Use `ClearLanguageManSingleton` as the source-facing helper name, with `LanguageMan_ClearSingletonHelper` as a search/documentation alias if desired.
4. Document exact behavior:
   - no args.
   - no `this`.
   - no callees.
   - no ordinary direct call refs.
   - one constructor-cleanup near jump from `0x00600a64`.
   - stores zero to `g_pLanguageMan` at `0x0067a750`.
5. Add the first-draft static helper C++ shown in this report.

### Support Docs To Update

1. [UID:000071][LanguageMan](../../../../../by-class/LanguageMan.md):
   - Resolve naming note to say `LanguageMan` is canonical and `LanguageManager` is a generated alias/view.
   - Link the three new exact child pages.
   - Add layout names `m_strings` at `+0x4` and `m_stringCount` at `+0x8`.
   - Note direct lookup first-draft C++ readiness and copy-helper type caveat.
2. [UID:000072][LanguageManager](../../../../../by-class/LanguageManager.md):
   - Keep ignored alias disposition.
   - Update cross-reference from old aggregate-only target to new `LanguageManGetLocalizedString` child.
   - State that generated output should not keep a separate `LanguageManager.cpp` source body for the lookup.
3. [UID:0000KK][LanguageMan](../../../../../by-file/LanguageMan.md):
   - Replace old "final naming unresolved" wording with the current decision: canonical `LanguageMan`, `LanguageManager` alias.
   - Add new exact children and state the parent aggregate is non-emitting.
   - Record copy-helper type/API caveat and singleton-clear file-local placement.
4. [UID:00018R][LanguageManLocalization](../../../../../by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md):
   - Replace old aggregate-only reference with the three new exact child links.
   - Keep the broad constructor/destructor/localization-family map intact.
   - Remove any implication that `LanguageManager` remains equally plausible as canonical owner.
5. [UID:00018S][LanguageManCleanupDestructor](../../../../../by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md):
   - Cross-link `m_stringCount`/`m_strings` field names to the direct lookup child.
6. [UID:00018T][LocalizationAdjacentZeroInitializer](../../../../../by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md):
   - No behavior change required; optionally mention it is adjacent but not part of the lookup/singleton helper split.
7. [UID:00018V][LanguageManScalarDeletingDestructor](../../../../../by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md):
   - Cross-link the singleton clear child only as lifecycle context; do not fold it into the destructor.
8. [UID:0000RC][g_pLanguageMan](../../../../../by-global/g_pLanguageMan.md) and [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](../../../../../by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md):
   - Resolve the LanguageMan/LanguageManager caveat.
   - Replace old aggregate references with child links.
   - Record the constructor-cleanup jump behavior for `0x004f03c0`.
9. [UID:0001RP][str-res-localized-strings](../../../../../by-resource/str-res-localized-strings.md) and [UID:00025M][KeySpeedStringResourceReadOnlyData](../../../../../by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md):
   - Replace aggregate lookup helper references with the direct/copy child links.
   - Keep `L"Invalid String ID"` at `0x0061ca20` as a static fallback literal, not a regular resource id.
10. [UID:0001CY][NumberInputDialogActionHandler](../../../../../by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md):
    - Point the call at the new copy-helper child.
    - Preserve id `217` / `0xd9`.
    - Keep the existing source API ambiguity note if formal string type remains deferred.
11. [UID:0001NV][VirusCheckerV3LoadAndScan](../../../../../by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md):
    - Point the call at the new copy-helper child.
    - Preserve id `221` / `0xdd`.
12. [UID:0000OA][StringBase](../../../../../by-file/StringBase.md), [UID:0002RN][StringBaseShareAssignAndAccess](../../../../../by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md), and [UID:0001W4][SimpleUStringPointerBackedLayout](../../../../../by-type/by-struct/SimpleUStringPointerBackedLayout.md):
    - Only update if the callback names `0x00582560` in the copy-helper child. Keep ownership on StringBase for the string assignment callee and do not move the localization helper there.

### Generated Output Inspection After Callback

After implementation and validator/autogen:

1. Inspect `auto-generated/NexusTK/localization/LanguageMan.cpp`.
2. Confirm `LanguageMan::GetLocalizedString` emits from the new direct child, not from `class_LanguageManager.cpp`.
3. Confirm `ClearLanguageManSingleton` emits once if the child is emitter-enabled.
4. Confirm the copy helper either does not emit formal C++ because type/API is deferred or emits a clearly first-draft placeholder without STL containers.
5. Confirm the old parent aggregate [UID:00018U] does not emit duplicate code.

## Validator / Post-Implementation Commands

Scoped validator baseline already run during this report-only pass:

_Executable command block removed from the research report; preserved in [00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md](00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md)._

Result:

```text
Exit code: 0
apply: False
scanned markdown files: 1
last used UID: 0003ZT
autogen_children_fallback_insert: 2
autogen_children_marker_missing: 2
autogen_cpp_conflict: 5
autogen_cpp_noop: 271
autogen_emitter_has_no_code: 592
autogen_registry_rebuild: 1
autogen_report_noop: 7
ok: 1
stats_incremental_skip: 1
ok 00018U by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md UID header exists
stats_incremental_skip 00018U project-level/-auto-completion-stats.md dry run; pass --apply to update generated stats rows
dry run only; pass --apply to write changes
```

The dry run also emitted project-wide autogen/stats noise, but no target validation error for [UID:00018U].

Report-only side-effect note: after the dry-run command, `git status` showed validator side effects on the target header and `by-memory/-coverage-report.md` despite `apply: False`. I restored only those two unintended diffs before finishing this report. Final targeted status for those two files is clean; the report-only output remains this B007 research file.

Recommended callback validation commands:

_Executable command block removed from the research report; preserved in [00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md](00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md)._

If the callback touches StringBase support docs for the `0x00582560` callee reference, also run:

_Executable command block removed from the research report; preserved in [00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md](00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md)._

Then run the project autogen/update path used by this repository:

_Executable command block removed from the research report; preserved in [00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md](00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md)._

If the supervisor manually applies the coverage rows, validate the shared coverage file afterward:

_Executable command block removed from the research report; preserved in [00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md](00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md)._

## Exact Supervisor-Owned Coverage Text

Do not edit `by-memory/-coverage-report.md` during this report-only pass. Recommended parent row replacement:

```text
    - [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) 0x004f0350-0x004f03cb | split helper index | LanguageMan lookup/copy/clear helper split index : ignored : 90% : very strong : B007 source-quality pass reclassifies this as a reviewed non-emitting parent over three exact LanguageMan.cpp source helpers and internal `0xcc` padding; local PE/exported evidence confirms `0x004f0350-0x004f0372` direct `LanguageMan::GetLocalizedString` helper with 351 direct callers and `m_strings`/`m_stringCount` bounds/fallback behavior, `0x004f0380-0x004f03bb` copy-output helper with exactly two callers and `0x00582560` UTF-16 assign/copy calls, `0x004f03c0-0x004f03cb` file-local constructor-cleanup singleton clear reached by near jump from `0x00600a64`, fallback literal refs to `0x0061ca20`, 192 `g_pLanguageMan` refs, and `LanguageMan`/`Singleton<LanguageMan>` RTTI with no real `LanguageManager` class evidence; exact children carry source reconstruction, so the aggregate has no formal C++.
```

Existing internal-padding row can remain, or supervisor may replace it with this refreshed row:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f0372-0x004f0380, 0x004f03bb-0x004f03c0, and 0x004f03cb-0x004f03d0 | padding | LanguageMan lookup helper internal alignment : ignored : 100% : strong : Local PE check reconfirms `0xcc` alignment bytes between exact lookup/copy/clear helper bodies.
```

Child row templates after validator assigns new UIDs:

```text
    - [UID:<assigned>][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) 0x004f0350-0x004f0372 | method | LanguageMan::GetLocalizedString : reconstructable : 90% : very strong : Exact class method child split from [UID:00018U]; PE/exported evidence confirms 34-byte `thiscall` body, signed lower-bound and `m_stringCount` upper-bound check, `m_strings[stringId]` return, fallback `L"Invalid String ID"` at `0x0061ca20`, 351 direct callers, zero callees, direct class owner [UID:000071], and first-draft C++ readiness.
    - [UID:<assigned>][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) 0x004f0380-0x004f03bb | method/helper | LanguageMan copy-output localized string helper : reconstructable : 88% : strong : Exact class helper child split from [UID:00018U]; PE/exported evidence confirms 59-byte `thiscall` output-helper ABI, same string-id bounds check, two direct callers at `0x00530c27` and `0x005c08a2`, UTF-16 copy/assign calls to `0x00582560` at `0x004f0399` and `0x004f03ae`, fallback `L"Invalid String ID"`, direct class owner [UID:000071], and C++ deferred only for final public string type/API spelling.
    - [UID:<assigned>][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md) 0x004f03c0-0x004f03cb | helper | ClearLanguageManSingleton : reconstructable : 88% : very strong : Exact file-local cleanup helper child split from [UID:00018U]; PE/exported evidence confirms 11-byte body `g_pLanguageMan = 0`, no ordinary call refs or callees, one constructor-cleanup near jump from `0x00600a64`, direct file owner/emitter [UID:0000KK], and first-draft static helper C++ readiness.
```

## Open Questions And Remaining Caps

- Exact public type for the copy-helper destination remains unresolved. `StringBase<wchar_t>` is strongest, but `SimpleUString`, `WideString`, or a typedef/facade remain possible. This caps the copy child score and formal C++ readiness.
- Exact public name for the copy helper remains inferred. `CopyLocalizedString` is the best documentation/source-facing name because it avoids a return-type collision with the pointer-returning `GetLocalizedString(int)` and matches current caller docs.
- Exact original source spelling for `GetLocalizedString` versus a shorter `GetString` cannot be proven from binary alone. Existing target/support docs and assignment language favor `GetLocalizedString`.
- Exact source name of the cleanup helper is inferred. `ClearLanguageManSingleton` describes the body and placement, but compiler metadata gives no preserved helper symbol.
- IDA MCP was unavailable, so this pass revalidated with exported JSON and local PE bytes/disassembly. The callback should run live IDA checks if available, but the current evidence is sufficient for the split/no-code decision.

## Final Recommendation

Supervisor should accept this as a split/source-quality callback. The current aggregate [UID:00018U] should become a non-emitting split index at `90/92`, the direct lookup and singleton clear should get first-draft C++, and the copy helper should get an exact child page with behavior resolved but formal C++ deferred unless a project-wide placeholder string type is explicitly accepted.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00018U-LanguageManLookupAndSingletonHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00018U"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018U-LanguageManLookupAndSingletonHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/00018U-LanguageManLookupAndSingletonHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
