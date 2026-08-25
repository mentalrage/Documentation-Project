** TARGET-REPORT-UID:0002RS **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002RS StringBaseAppendAndFind Source-Quality Research

Agent: B005  
Assignment id: `B005-report-0002RS-string-base-append-and-find-20260625`  
Mode: report-only research first  
Target: [UID:0002RS] `by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md`  
Required report path: `tools/leaser/Agents/Agent-B005/research/0002RS-StringBaseAppendAndFind-source-quality.md`

## Executive Recommendation

The target is already correctly routed to [UID:0000OA] `by-file/StringBase.md`, and current MCP evidence strengthens that route. Keep:

- `CANONICAL_OWNER:0000OA`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OA`
- blank `EMITTER_POSITION_OPTIONAL`

Raise the target from `COMPLETION:86`, `CONFIDENCE:89` to `COMPLETION:90`, `CONFIDENCE:91`.

The target is now eligible for formal reconstruction C++ under the current by-structure gate because it is reconstructable, has a valid emitter route, and its average score is already greater than `85`. The current target's blank C++ rationale depends on stale `95/95` final-source-gate wording. That rationale should be replaced with a formal first-draft C++ block for the eight source-authored StringBase helper bodies in this range.

The best current source-facing interpretation is:

- ANSI and UTF-16 append/fill helpers over the ref-counted 12-byte StringBase buffer header.
- A shared data-pointer accessor best represented in final source as `c_str` or a c_str-equivalent data accessor, not as an append/search helper.
- A bounded wide literal compare helper, not a true "find" helper.
- `0x00584470` is a counted wide literal append helper. Keep `AppendWideLiteral` / counted wide append wording and reject older `AppendWideData` wording because the helper scans a NUL-terminated source and clamps to `wcslen`.

## Current Target State

Current target header:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000OA`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OA`
- `EMITTER_POSITION_OPTIONAL:` blank
- formal `RECONSTRUCTION_CPP CODE` block blank
- Item Summary: `ANSI/UTF-16 append, fill, and simple wide-find helpers between the existing compare child splits.`

Current target quality issues:

- The page still cites stale MCP provenance from session `a002_batch_clear_timer` on 2026-06-12. This report rechecks the target with current project-stable MCP endpoint `http://127.0.0.1:13337/mcp` and active database/session `80de0a67`.
- The page uses old `AUTOGEN_PARENT_UID` terminology in the ownership gate. Current docs should use `CANONICAL_OWNER` for ownership and `EMITTER_UIDS` for output routing.
- The page says reconstruction C++ is intentionally blank because final names and the `StringBase` / `SimpleUString` facade split are below a `95/95` final-source gate. That is stale under current `by-structure.md`, which allows code entry when a reconstructable target has a valid emitter route and `(COMPLETION + CONFIDENCE) / 2 > 85`.
- The target summary says "simple wide-find helpers", while current MCP shows the tail helper at `0x00584550` is a bounded substring-versus-literal compare wrapper that returns `-1` when the start offset is past the stored length and otherwise forwards to [UID:0002LN] `WideRangeCompare`.
- The parent aggregate [UID:0001J3] still has stale child-row names for this target, including `AppendWideData` and `FindWide`.
- Generated state is stale: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `project-level/-auto-completion-stats.md`, and `auto-generated/NexusTK/util/StringBase.cpp` still report [UID:0002RS] as `74/84` / empty marker. The source by-memory page is already `86/89`. The manual coverage/default row at `by-memory/-coverage-report.md` also still has the stale `74%` summary. B005 must not edit coverage or generated files during this report-only pass; implementation should update source metadata and use validators, with supervisor-owned coverage/default repair only if the normal validator path reverts the source header.

## Current MCP Provenance

MCP was rechecked after the stale-port pause. The correct project-stable endpoint is `http://127.0.0.1:13337/mcp`; port `8750` was the wrong endpoint for this project state.

MCP status on this pass:

- JSON-RPC `initialize` succeeded against `http://127.0.0.1:13337/mcp`.
- Server info: `ida-pro-mcp` version `1.0.0`.
- `tools/list` succeeded and exposed current idalib-backed tools including `server_health`, `lookup_funcs`, `entity_query`, `analyze_batch`, `analyze_component`, `xref_query`, `get_bytes`, `decompile`, and `disasm`.
- `idb_list` returned active session `80de0a67`.
- Session path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Session created: `2026-06-24T06:15:52.461765`.
- Session last accessed during this pass: `2026-06-25T01:44:45.432557`.
- Backend: `worker`; owned/adopted session; `is_analyzing:false`.
- `server_health database=80de0a67` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

No IDA DB edits were made.

## Exact Range And Boundary Evidence

Current MCP `entity_query` over `0x00584140-0x005845f0` with `min_addr` / `max_addr` confirms these function starts:

| Address | IDA name | Size | Segment |
| --- | --- | --- | --- |
| `0x00584160` | `sub_584160` | `0x9c` | `.text` |
| `0x00584200` | `sub_584200` | `0x78` | `.text` |
| `0x00584280` | `sub_584280` | `0x9f` | `.text` |
| `0x00584320` | `sub_584320` | `0xa8` | `.text` |
| `0x005843d0` | `sub_5843D0` | `0x92` | `.text` |
| `0x00584470` | `sub_584470` | `0xc1` | `.text` |
| `0x00584540` | `sub_584540` | `0x3` | `.text` |
| `0x00584550` | `sub_584550` | `0x5f` | `.text` |
| `0x005845b0` | `sub_5845B0` | `0x3c` | `.text` |
| `0x005845f0` | `sub_5845F0` | `0xa` | `.text` |

The target range `0x00584160-0x005845af` exactly covers the eight functions through the exclusive end of `sub_584550`. The successor one-byte gap at `0x005845af-0x005845b0` is `0xcc` alignment before [UID:0002LO] `StringBaseCompareWideLiteral`.

Current MCP `get_bytes` confirms all boundary and internal padding bytes are `0xcc`:

| Span | Bytes |
| --- | --- |
| `0x0058415a-0x00584160` | six `0xcc` bytes after [UID:0002LN] |
| `0x005841fc-0x00584200` | four `0xcc` bytes |
| `0x00584278-0x00584280` | eight `0xcc` bytes |
| `0x0058431f-0x00584320` | one `0xcc` byte |
| `0x005843c8-0x005843d0` | eight `0xcc` bytes |
| `0x00584462-0x00584470` | fourteen `0xcc` bytes |
| `0x00584531-0x00584540` | fifteen `0xcc` bytes |
| `0x00584543-0x00584550` | thirteen `0xcc` bytes |
| `0x005845af-0x005845b0` | one `0xcc` byte before successor |
| `0x005845ec-0x005845f0` | four `0xcc` bytes after successor compare wrapper |

No split or range rename is recommended. The target is a contiguous source-authored helper group with ordinary function-level padding between sibling helpers.

## Function Behavior From Current MCP

`analyze_component` over the eight target functions reports no internal call-graph edges and no shared globals. These are sibling interface functions over the same pointer-backed StringBase representation; durable state is in the caller-owned string object and its 12-byte header.

| Function | Best current source-facing role | Current behavior |
| --- | --- | --- |
| `0x00584160` | `AppendAnsiSliceFromString` | Reads the source object's stored length from `sourceData[-0x08]`; if the source length is greater than the requested source offset, clamps append count to remaining source bytes, appends at the destination's current byte length, copies with `memmove`, writes the ANSI terminator, and updates destination length on the fast path. Slow path calls `0x00582ef0` before copying. |
| `0x00584200` | `AppendAnsiFill` | Computes `oldLength + Size`, checks whether the destination buffer is writable and has capacity, fills appended bytes with `_memset`, writes the ANSI terminator, and updates length on the fast path. Slow path calls `0x00582ef0(Size)` before filling the new tail. |
| `0x00584280` | `AppendAnsiLiteral` | Scans a NUL-terminated ANSI source, clamps requested `Size` to `strlen(Src)`, appends bytes with `memmove`, writes the ANSI terminator, and grows through `0x00582ef0` when in-place append is not allowed. |
| `0x00584320` | `AppendWideSliceFromString` | Wide sibling of `0x00584160`; reads source length, clamps by source offset and requested count, copies `2 * count` bytes from the source wide data pointer, writes a UTF-16 terminator, and uses `0x00582fa0` on the slow path. |
| `0x005843d0` | `AppendWideFill` | Appends repeated UTF-16 code units. The binary builds a 32-bit repeated-word value for paired stores, handles an odd trailing code unit, writes the UTF-16 terminator on the fast path, and calls `0x00582fa0` on the slow path. |
| `0x00584470` | `AppendWideLiteral` / counted wide append | Scans a NUL-terminated UTF-16 source, clamps requested count to `wcslen(Src)`, copies `2 * count` bytes with `memmove`, writes the UTF-16 terminator, and uses `0x00582fa0` when growth/detach is needed. This is not raw `AppendWideData`. |
| `0x00584540` | `c_str` / data-pointer accessor | Two-instruction accessor: `mov eax, [ecx]`; `retn`. It returns the object field at offset `0`, which is the data pointer. Its 171 code xrefs and 93 caller functions make it a shared string accessor, not a find/append operation. |
| `0x00584550` | `CompareWideSubstringWithLiteral` | Reads the stored wide length, returns `-1` if the requested start is past the stored length, clamps requested count to remaining characters, scans the NUL-terminated literal to its end, and calls [UID:0002LN] `WideRangeCompare` over the stored substring and literal ranges. This is bounded compare behavior, not a true search. |

The common fast-append condition is stable across the append helpers: the destination header's `refCount` at `data[-0x0c]` must be `1` or `-1`, and `oldLength + appendCount` must be no larger than `capacity` at `data[-0x04]`. Fast paths update the destination header `length` at `data[-0x08]` and write the appropriate terminator. Slow paths call the grow helper first; those grow helpers are documented in [UID:0002RO] `by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md`.

## Caller, Callee, And Xref Evidence

Current MCP caller/callee evidence:

| Function | Direct callees | Direct code xrefs / caller grouping |
| --- | --- | --- |
| `0x00584160` | `_memmove`, `0x00582ef0` | 2 code xrefs, both from `0x0057a890` |
| `0x00584200` | `_memset`, `0x00582ef0` | 2 code xrefs from `0x0049c3e0` and `0x005822d0` |
| `0x00584280` | `_memmove`, `0x00582ef0` | 5 code xrefs from `0x004b1d50` and `0x0057a890` |
| `0x00584320` | `_memmove`, `0x00582fa0` | 10 code xrefs from 7 functions: `0x004b1d50`, `0x004b3090`, `0x004b32d0`, `0x004e13b0`, `0x0056bea0`, `0x005a8a10`, `0x005b6900` |
| `0x005843d0` | `0x00582fa0` | 7 code xrefs from 6 functions: `0x004926a0`, `0x004b1d50`, `0x004b3090`, `0x0056bea0`, `0x005a8a10`, `0x005b6900` |
| `0x00584470` | `_memmove`, `0x00582fa0` | 7 code xrefs from 4 functions: `0x004671b0`, `0x004926a0`, `0x0056bea0`, `0x005c2ac0` |
| `0x00584540` | none | 171 code xrefs; current full MCP batch reports 93 caller functions |
| `0x00584550` | `0x005840f0` | 1 code xref from `0x005831c0` |

Current MCP `xref_query` for data xrefs to all eight function starts returned no data cross-references. That is not a liveness blocker here because the helpers are ordinary callable functions with direct code xrefs, except for the accessor's especially broad direct-call fan-in. It is useful negative evidence only against pointer-table/vtable ownership hypotheses.

The B001 executed report for [UID:000325] `StringBaseAppendWideLiteral` remains useful lead material but is superseded by the current MCP pass where the two overlap. B001 correctly identified `0x00584470` as the counted wide literal append helper, rejected `AppendWideData`, and inserted generated code that calls `this->AppendWideLiteral(rhs, count)`. Current MCP confirms the same callee behavior and seven direct code xrefs to `0x00584470`.

## Ownership And Source-Placement Analysis

Ranked candidates:

1. [UID:0000OA] `by-file/StringBase.md` as direct canonical owner and emitter route.
   - Strongest candidate. Every substantive helper manipulates the pointer-backed ref-counted StringBase storage model: object field at offset `0` is a data pointer, and the 12-byte header stores `refCount`, `length`, and `capacity`.
   - ANSI append slow paths call `0x00582ef0`; UTF-16 append slow paths call `0x00582fa0`. [UID:0002RO] documents those as StringBase allocation/grow/copy-on-write helpers.
   - The compare helper calls [UID:0002LN] `WideRangeCompare`, which is already routed to [UID:0000OA].
   - [UID:0001VQ] and [UID:0001W4] document the same header and one-pointer layout.
   - [UID:0001WS] preserves the `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>` type-family evidence, and [UID:0000OA] emits to `auto-generated/NexusTK/util/StringBase.cpp`.
   - Caller spread crosses UI, file/stream, application, and string-family code, which supports a shared string implementation rather than feature-local ownership.

2. [UID:0001WS] `StringBaseTemplate` as a type-level support owner.
   - Strong type evidence, especially for declarations and template-family shape. It is not the best direct owner for this exact by-memory target because current target metadata and generated output route already surface through [UID:0000OA], and target behavior is a file-level helper group in the StringBase implementation.
   - [UID:0002RO] routes through [UID:0001WS] because allocation/grow/COW helpers are more template-declaration-centric. For [UID:0002RS], direct [UID:0000OA] remains correct because the target already represents concrete implementation methods and generated output must land in `StringBase.cpp`.

3. [UID:0001W4] `SimpleUStringPointerBackedLayout` / [UID:0000D9] `SimpleUString` as facade/alias context.
   - Useful for public facade caveats. Older labels use `SimpleUString` for some wrappers, and the public API may have been a facade or typedef.
   - Not a better direct owner. Current compiler metadata and exact helper family evidence point to `mystr::StringBase`, while `SimpleUString` remains alias/facade context.

4. [UID:0000OB] `StringUtil` as broad utility-string context.
   - Rejected as direct owner. `StringUtil` coordinates utility-string surfaces, but this target directly mutates StringBase buffer internals and uses the StringBase grow/compare helpers.

5. [UID:0000KV] `LObject` or feature-local callers.
   - Rejected. The old `LObject` owner is generated pollution over a different true `LObject` runtime shell. Feature modules are consumers only.

Recommended metadata therefore keeps [UID:0000OA] as both canonical owner and emitter route.

## Heuristic / Inference Reanalysis

### Placeholder Names

IDA names `sub_584160`, `sub_584200`, `sub_584280`, `sub_584320`, `sub_5843D0`, `sub_584470`, `sub_584540`, and `sub_584550` should not remain as final source-facing names except in evidence/search context.

Best current names:

- `AppendAnsiSliceFromString`
- `AppendAnsiFill`
- `AppendAnsiLiteral`
- `AppendWideSliceFromString`
- `AppendWideFill`
- `AppendWideLiteral`
- `c_str` / data-pointer accessor
- `CompareWideSubstringWithLiteral`

These are inferred descriptive names, not symbol-proven original names. They are better than IDA placeholders and match observed behavior. If the final header/API pass later resolves overloaded original spellings, those declarations can be refined without changing the behavioral facts.

### AppendWideData Rejection

Reject `AppendWideData` for `0x00584470` as the best current name. Current MCP decompilation shows the helper scans the source for a NUL terminator and clamps the requested count to `wcslen(Src)`. A raw data append would not need to rescan or clamp a counted buffer to a NUL-terminated source. B001 reached the same conclusion from the [UID:000325] wrapper; current MCP now confirms it directly.

### FindWide Rejection

Reject `FindWide` for `0x00584550` as the current source-facing role. The helper does not search for a first occurrence. It clamps a substring range and delegates to [UID:0002LN] `WideRangeCompare`; it returns `-1` only when the requested start is past the stored length. The better role is bounded substring-versus-wide-literal compare.

### Data Accessor Interpretation

`0x00584540` is source-facing as a `c_str`-equivalent accessor. It has no callees, two instructions, and a very broad caller set. The current target table name `GetStringDataPointer` is acceptable as documentation wording, but final C++ should prefer the conventional `c_str` method already present in [UID:0001WS] `StringBaseTemplate` declaration hypothesis.

### Header Field Names And Types

The formal C++ should use `m_data` and the established 12-byte header interpretation from [UID:0001VQ]:

- `data[-0x0c]` / `reinterpret_cast<int*>(data)[-3]` as `refCount`.
- `data[-0x08]` / `reinterpret_cast<int*>(data)[-2]` as current character count.
- `data[-0x04]` / `reinterpret_cast<int*>(data)[-1]` as capacity.

The code should not invent a separate owner structure in this target. A later declaration pass may introduce a named header struct, but the binary behavior here is the pointer/header arithmetic itself.

### Current Gate And Blank C++ Rationale

The target's current no-code proof is stale. It cites final API uncertainty and a `95/95` final-source gate. Current `by-structure.md` says the code-entry gate is a valid emitter route plus average score greater than `85`; `95+` is a rare final-audit score, not a prerequisite for first-draft formal C++.

The remaining uncertainty is not severe enough to block formal C++:

- Original public API spelling is not symbol-proven, but source-facing inferred names are good enough for this stage.
- The `StringBase` / `SimpleUString` facade split remains a confidence cap, not a no-code blocker, because the direct emitter file is [UID:0000OA] and existing generated B001 code already depends on a counted `AppendWideLiteral` helper in this family.
- The target range contains whole function bodies, not a raw partial body, compiler-only artifact, or mixed-owner aggregate.

## Formal RECONSTRUCTION_CPP CODE Recommendation

Insert the following exact content into [UID:0002RS] `RECONSTRUCTION_CPP CODE`. This is the formal first-draft source representation for the target range, not an illustrative side sample.

```cpp
namespace mystr {

template <>
StringBase<char, mychar_traits<char>>&
StringBase<char, mychar_traits<char>>::AppendAnsiSliceFromString(
    const StringBase<char, mychar_traits<char>>& source,
    unsigned int sourceOffset,
    unsigned int maxCount)
{
    const unsigned int sourceLength =
        static_cast<unsigned int>(reinterpret_cast<const int*>(source.m_data)[-2]);

    if (sourceLength <= sourceOffset) {
        return *this;
    }

    unsigned int appendCount = sourceLength - sourceOffset;
    if (maxCount < appendCount) {
        appendCount = maxCount;
    }

    char* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + appendCount;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memmove(data + oldLength, source.m_data + sourceOffset, appendCount);
        m_data[newLength] = '\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowAnsiBuffer(appendCount);
        memmove(m_data + oldLength, source.m_data + sourceOffset, appendCount);
    }

    return *this;
}

template <>
StringBase<char, mychar_traits<char>>&
StringBase<char, mychar_traits<char>>::AppendAnsiFill(unsigned int count, char ch)
{
    char* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + count;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memset(data + oldLength, ch, count);
        m_data[newLength] = '\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowAnsiBuffer(count);
        memset(m_data + oldLength, ch, count);
    }

    return *this;
}

template <>
StringBase<char, mychar_traits<char>>&
StringBase<char, mychar_traits<char>>::AppendAnsiLiteral(const char* source,
                                                         unsigned int maxCount)
{
    unsigned int literalLength = 0;
    while (source[literalLength] != '\0') {
        ++literalLength;
    }

    unsigned int appendCount = maxCount;
    if (literalLength < appendCount) {
        appendCount = literalLength;
    }

    char* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + appendCount;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memmove(data + oldLength, source, appendCount);
        m_data[newLength] = '\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowAnsiBuffer(appendCount);
        memmove(m_data + oldLength, source, appendCount);
    }

    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t>>&
StringBase<wchar_t, mychar_traits<wchar_t>>::AppendWideSliceFromString(
    const StringBase<wchar_t, mychar_traits<wchar_t>>& source,
    unsigned int sourceOffset,
    unsigned int maxCount)
{
    const unsigned int sourceLength =
        static_cast<unsigned int>(reinterpret_cast<const int*>(source.m_data)[-2]);

    if (sourceLength <= sourceOffset) {
        return *this;
    }

    unsigned int appendCount = sourceLength - sourceOffset;
    if (maxCount < appendCount) {
        appendCount = maxCount;
    }

    wchar_t* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + appendCount;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memmove(data + oldLength, source.m_data + sourceOffset,
                appendCount * sizeof(wchar_t));
        m_data[newLength] = L'\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowWideBuffer(appendCount);
        memmove(m_data + oldLength, source.m_data + sourceOffset,
                appendCount * sizeof(wchar_t));
    }

    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t>>&
StringBase<wchar_t, mychar_traits<wchar_t>>::AppendWideFill(unsigned int count,
                                                           wchar_t ch)
{
    wchar_t* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + count;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        for (unsigned int i = 0; i < count; ++i) {
            data[oldLength + i] = ch;
        }
        m_data[newLength] = L'\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowWideBuffer(count);
        for (unsigned int i = 0; i < count; ++i) {
            m_data[oldLength + i] = ch;
        }
    }

    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t>>&
StringBase<wchar_t, mychar_traits<wchar_t>>::AppendWideLiteral(
    const wchar_t* source,
    unsigned int maxCount)
{
    unsigned int literalLength = 0;
    while (source[literalLength] != L'\0') {
        ++literalLength;
    }

    unsigned int appendCount = maxCount;
    if (literalLength < appendCount) {
        appendCount = literalLength;
    }

    wchar_t* data = m_data;
    int* header = reinterpret_cast<int*>(data);
    const unsigned int oldLength = static_cast<unsigned int>(header[-2]);
    const unsigned int newLength = oldLength + appendCount;

    if ((header[-3] == 1 || header[-3] == -1) &&
        newLength <= static_cast<unsigned int>(header[-1])) {
        memmove(data + oldLength, source, appendCount * sizeof(wchar_t));
        m_data[newLength] = L'\0';
        reinterpret_cast<int*>(m_data)[-2] = static_cast<int>(newLength);
    } else {
        GrowWideBuffer(appendCount);
        memmove(m_data + oldLength, source, appendCount * sizeof(wchar_t));
    }

    return *this;
}

template <class CharT, class Traits>
const CharT*
StringBase<CharT, Traits>::c_str() const
{
    return m_data;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t>>::CompareWideSubstringWithLiteral(
    unsigned int start,
    unsigned int maxCount,
    const wchar_t* literal) const
{
    const wchar_t* data = m_data;
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int*>(data)[-2]);

    if (length < start) {
        return -1;
    }

    unsigned int compareCount = length - start;
    if (maxCount < compareCount) {
        compareCount = maxCount;
    }

    const wchar_t* literalEnd = literal;
    while (*literalEnd != L'\0') {
        ++literalEnd;
    }

    return WideRangeCompare(data + start,
                            data + start + compareCount,
                            literal,
                            literalEnd);
}

}
```

Formal C++ caveats to document in the target/support pages:

- Method names are inferred source-facing names. They intentionally avoid IDA `sub_*` labels and preserve current project naming from the target and B001 reports.
- The code assumes declarations for `m_data`, `GrowAnsiBuffer`, `GrowWideBuffer`, and `WideRangeCompare` exist or will be added consistently by the StringBase declaration pass. Those helpers are represented by adjacent pages; this target should not duplicate their bodies.
- The slow path intentionally calls the grow helpers before copying/filling the appended tail, matching the binary's call/copy order.
- The accessor uses conventional `c_str` spelling because [UID:0001WS] already hypothesizes that API and the binary body is exactly the pointer return.

## Score Recommendation

Recommended target metadata:

| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `86` | `90` | Current report adds fresh MCP provenance, current boundary/padding evidence, data-xref negative evidence, formal C++ readiness, generated-state conflict analysis, stale-name cleanup, and implementation-ready support checklist. |
| `CONFIDENCE` | `89` | `91` | Behavior, range, callers/callees, header fields, grow-helper interaction, and owner/emitter route are strongly confirmed by current MCP and support docs. Confidence remains below final-audit level because exact original public API spelling and `StringBase` versus `SimpleUString` facade naming remain inferred. |
| `CANONICAL_OWNER` | `0000OA` | `0000OA` | Direct StringBase ownership remains strongest. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored helper bodies must be rebuilt. |
| `EMITTER_UIDS` | `0000OA` | `0000OA` | Generated output belongs in `auto-generated/NexusTK/util/StringBase.cpp`. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No special order requirement beyond existing emitter ordering. |

Reason not higher than `90/91`:

- No original symbols prove exact final method names.
- The public facade relationship among `StringBase<wchar_t>`, `SimpleUString`, `WideString`, or typedef/wrapper forms is still a confidence cap.
- The formal C++ depends on adjacent StringBase declarations/grow-helper declarations being kept consistent; those declarations are supported but not fully final-audit quality.

## Recommended Target Doc Changes

Update [UID:0002RS] `by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md`:

- Set `COMPLETION:90`, `CONFIDENCE:91`.
- Preserve `CANONICAL_OWNER:0000OA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`, and blank `EMITTER_POSITION_OPTIONAL`.
- Replace the Item Summary with a current concise summary that does not repeat metadata fields. Recommended summary:
  - `StringBase ANSI/UTF-16 append/fill helpers, shared c_str data accessor, and bounded wide literal compare over the 12-byte ref-counted buffer header; current MCP evidence supports formal first-draft C++ and rejects stale wide-find/AppendWideData wording.`
- Replace old MCP session `a002_batch_clear_timer` / 2026-06-12 evidence with current MCP session `80de0a67` and endpoint `127.0.0.1:13337`.
- Replace old `AUTOGEN_PARENT_UID` prose with current `CANONICAL_OWNER` / `EMITTER_UIDS` language.
- Replace stale "below the 95/95 final-source gate" no-code rationale with the current by-structure code-entry gate and the formal C++ block above.
- Keep support for final original-name uncertainty as a confidence cap, not as a blank-C++ blocker.
- Rename/prose-clean the helper roles:
  - `0x00584470` remains `AppendWideLiteral` / counted wide append; explicitly reject `AppendWideData`.
  - `0x00584540` should be documented as `c_str` / data-pointer accessor; keep `GetStringDataPointer` only as descriptive evidence wording if needed.
  - `0x00584550` should be documented as `CompareWideSubstringWithLiteral`; explicitly reject `FindWide`.
- Record the current code xref counts and caller groupings from MCP.
- Record that current MCP data-xref checks found zero data xrefs to the eight function starts.
- Preserve the exact padding table using current `80de0a67` evidence.
- Add a generated-state note: current generated tracker/output rows are stale at `74/84`; B005 does not edit generated or coverage files, and implementation must rely on source metadata plus scoped validator refresh.

## Recommended Support Doc Changes

Update [UID:0001J3] `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md`:

- Keep the aggregate non-emitting/contextual with `RECONSTRUCTABLE:FALSE`.
- Update the [UID:0002RS] child row and covered-range rows to current names:
  - `AppendAnsiSliceFromString`, not generic `AppendAnsiData`.
  - `AppendAnsiFill`.
  - `AppendAnsiLiteral`.
  - `AppendWideSliceFromString`.
  - `AppendWideFill`.
  - `AppendWideLiteral`, not `AppendWideData`.
  - `c_str` / data-pointer accessor.
  - `CompareWideSubstringWithLiteral`, not `FindWide`.
- Add that [UID:0002RS] now has formal first-draft C++ through [UID:0000OA] while this aggregate remains non-emitting.
- No score change is required for the aggregate.

Update [UID:0000OA] `by-file/StringBase.md`:

- Add [UID:0002RS] to the likely contents/source-placement notes as the concrete formal-code owner for ANSI/wide append/fill, c_str/data pointer, counted wide literal append, and bounded wide literal compare helpers.
- Record that B005 supersedes the old blank-C++/`95+` gate language for [UID:0002RS]; current code-entry is allowed by the combined-score/emitter gate.
- Preserve the `StringBase` direct source root and keep `StringUtil` as broader utility context only.
- Add that current generated `StringBase.cpp` already contains [UID:000325] `operator+=(const wchar_t*)` calling `AppendWideLiteral(rhs, count)`, and [UID:0002RS] should supply that counted helper in the same file.
- No file-level score change is required from this target-specific update.

Update [UID:0001WS] `by-type/by-template/StringBaseTemplate.md`:

- Update the declaration hypothesis or method inventory to include the inferred method family used by [UID:0002RS]: ANSI/wide slice append, fill append, literal append, `c_str`, and bounded wide literal compare.
- Keep exact public facade spelling caveats. Do not claim symbol proof for the inferred method names.
- Preserve [UID:0000OA] as direct owner/emitter route.
- No score change is required unless the implementation substantially broadens the declaration audit.

Update [UID:0002LN] `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md`:

- Correct the Item Summary and assignment gate wording that still says "left unassigned under parent gate." The metadata is already assigned to [UID:0000OA].
- Replace `AUTOGEN_PARENT_UID` wording with current `CANONICAL_OWNER` / `EMITTER_UIDS` wording.
- Add or confirm that [UID:0002RS] `CompareWideSubstringWithLiteral` is a caller/consumer.
- No score change is required.

Update [UID:0002LO] `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md`:

- Correct the Item Summary and gate wording that still says "no-parent gate documented." The metadata is already assigned to [UID:0000OA].
- Replace `AUTOGEN_PARENT_UID` wording with current `CANONICAL_OWNER` / `EMITTER_UIDS` wording.
- Keep it adjacent successor context for [UID:0002RS] and [UID:0002LN].
- No score change is required.

Check-only support docs unless direct contradiction is found during implementation:

- [UID:0002RO] `by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md`: already documents `0x00582ef0` / `0x00582fa0` grow helpers used by the target. No routine edit expected unless the target implementation needs a cross-link to the formal block.
- [UID:0001VQ] `by-type/by-struct/RefCountedStringBufferHeader.md`: already documents `refCount`, `length`, and `capacity` at the offsets this target uses. No routine edit expected.
- [UID:0001W4] `by-type/by-struct/SimpleUStringPointerBackedLayout.md`: already documents one-pointer `m_data` layout and facade caveat. Optional support update only if implementation wants to add [UID:0002RS] as another direct evidence row.
- [UID:0000TM] `by-global/StringBufferSentinelsAndPools.md`: already sufficient and not directly touched by target helpers except through grow/allocation support.
- [UID:0000OB] `by-file/StringUtil.md`: check for contradiction only; keep as broad coordinator, not direct owner.
- [UID:000325] `by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md`: already sufficient and already calls into `AppendWideLiteral`; no routine edit expected unless it still references `sub_584470` as final prose.

## Generated And Coverage State

Generated state is currently stale:

- `auto-generated/-ag-research-tracker.md` row for [UID:0002RS] still shows `74/84`.
- `auto-generated/-ag-coverage-report-by-memory.md` row for [UID:0002RS] still shows `74% : strong` and the stale "simple wide-find" summary.
- `project-level/-auto-completion-stats.md` still lists [UID:0002RS] under `74/84`.
- `auto-generated/NexusTK/util/StringBase.cpp` has [UID:0002RS] as an empty emitter marker at `74/84`.
- `by-memory/-coverage-report.md` has a supervisor-owned/manual row for [UID:0002RS] with `74% : strong` and the stale summary.

B005 must not edit generated files, project-level generated reports, validator state, or coverage reports. Implementation should:

- Update the source by-memory target metadata/summary.
- Run scoped validators for changed by-* docs.
- Use `--wait-generated` on the target validation if generated output freshness matters.
- Re-read the target and `auto-generated/NexusTK/util/StringBase.cpp` after validation to confirm [UID:0002RS] no longer remains an empty marker.
- If the normal validator path reverts the active target header to `74/84` or stale summary from `by-memory/-coverage-report.md`, stop and report a validator metadata/default conflict for supervisor-owned manual coverage/default correction. Do not edit `by-memory/-coverage-report.md` as B005 unless explicitly instructed.

Conditional supervisor-owned replacement row if the manual coverage/default row must be corrected before implementation can stick:

`        - [UID:0002RS][0x00584160-0x005845af.StringBaseAppendAndFind](by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md) | method/helper-group | StringBaseAppendAndFind : reconstructable : 90% : very-strong : StringBase ANSI/UTF-16 append/fill helpers, shared c_str data accessor, and bounded wide literal compare over the 12-byte ref-counted buffer header; current MCP evidence rejects stale simple wide-find/AppendWideData wording and supports formal first-draft C++ through StringBase.`

## Remaining Open Questions

The remaining questions are confidence caps, not implementation blockers:

- Exact original method names are not symbol-proven. The recommended names are inferred source-facing names based on behavior and existing project naming.
- Exact public facade spelling remains unresolved among `StringBase<wchar_t>`, `SimpleUString`, `WideString`, or a typedef/wrapper form. The direct implementation route through [UID:0000OA] remains strongest.
- The final declaration pass must keep `m_data`, `GrowAnsiBuffer`, `GrowWideBuffer`, `WideRangeCompare`, and the [UID:0002RS] method declarations consistent. This affects final source polish but not the target's behavior or owner/emitter route.

No unresolved question justifies leaving [UID:0002RS] blank in formal C++ under the current gate.

## Implementation Tracking Checklist

Implementation callback status:

- [x] [UID:0002RS] `by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md`
  - Metadata and formal C++ proof: active readback after the support-validator batch still shows `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000OA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`, and nonblank formal C++ beginning with `namespace mystr`; `AppendWideLiteral` and `CompareWideSubstringWithLiteral` are present in the formal block. Prior target normal validator was `000000000926` at `2026-06-25T02:03:24-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`; generated `auto-generated/NexusTK/util/StringBase.cpp` was refreshed by command `000000000928` at `2026-06-25T02:03:58-04:00` and contains [UID:0002RS] at `90/91`.
  - Supervisor correction proof: supervisor restored the accepted source `Item Summary` with UID-only command `000000000934` at `2026-06-25T02:06:53-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped`. After support validators rewrote it again, supervisor restored the accepted source summary a second time with UID-only command `000000000959` at `2026-06-25T02:23:46-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped`.

- [x] [UID:0001J3] `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md`
  - Incorporated support body details at report-level specificity: [UID:0002RS] covered-range rows now use `AppendAnsiSliceFromString`, `AppendAnsiFill`, `AppendAnsiLiteral`, `AppendWideSliceFromString`, `AppendWideFill`, `AppendWideLiteral` / counted wide append, `c_str` / data-pointer accessor, and `CompareWideSubstringWithLiteral`; the child split row records [UID:0002RS] as first-draft C++ through [UID:0000OA] while this aggregate remains non-emitting/contextual. Historical/generated-name caveat now explicitly supersedes stale `AppendWideData`/`FindWide`.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md --apply --queue-timeout 240`, command `000000000945`, timestamp `2026-06-25T02:15:45-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`. Known unrelated missing-ref diagnostics remain for stale split links/UIDs.

- [x] [UID:0000OA] `by-file/StringBase.md`
  - Incorporated support details: [UID:0002RS] is now in likely contents/source-placement notes as the formal-code owner for ANSI/wide append/fill, `c_str`, counted wide literal append, and bounded wide literal compare helpers; [UID:000325] is documented as already emitting the `operator+=(const wchar_t*)` style wrapper that calls `AppendWideLiteral(rhs, count)`; `StringBase` remains direct source root and `StringUtil` remains broad context only. Historical `95+` blank-C++ gate language is superseded for [UID:0002RS] under the current combined-score/emitter gate.
  - Validator: `python .\tools\validator.py --mode file --file by-file\StringBase.md --apply --queue-timeout 240`, command `000000000948`, timestamp `2026-06-25T02:16:11-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`. Known unrelated missing-ref diagnostics remain.

- [x] [UID:0001WS] `by-type/by-template/StringBaseTemplate.md`
  - Incorporated support details: declaration/method inventory now includes the [UID:0002RS] inferred method family used by the formal C++ block: ANSI/wide slice append, fill append, literal append, `c_str`/data-pointer accessor, counted wide literal append, and bounded wide literal compare. Public facade/original-name caveats are preserved, and page-level C++ remains blank only for the full template declaration, not as a target-specific blocker.
  - Validator: `python .\tools\validator.py --mode file --file by-type\by-template\StringBaseTemplate.md --apply --queue-timeout 240`, command `000000000949`, timestamp `2026-06-25T02:16:21-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`. Known unrelated missing-ref diagnostics remain.

- [x] [UID:0002LN] `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md`
  - Body incorporated: current ownership/emitter terminology is present in the assignment gate and changes section, and [UID:0002RS] `CompareWideSubstringWithLiteral` is documented as a bounded compare consumer rather than a find/search helper.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x005840f0-0x0058415a.WideRangeCompare.md --apply --queue-timeout 240`, command `000000000946`, timestamp `2026-06-25T02:15:52-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`.
  - Supervisor correction proof: after the normal support validator reverted the Item Summary to stale "left unassigned under parent gate" text, supervisor restored the current source summary and validated it with UID-only command `000000000960` at `2026-06-25T02:23:48-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped`.

- [x] [UID:0002LO] `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md`
  - Body incorporated: current ownership/emitter terminology is present in the assignment gate and changes section, and successor/compare-wrapper relationship to [UID:0002RS] and [UID:0002LN] is preserved.
  - Validator: `python .\tools\validator.py --mode file --file by-memory\0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md --apply --queue-timeout 240`, command `000000000947`, timestamp `2026-06-25T02:16:03-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`.
  - Supervisor correction proof: after the normal support validator reverted the Item Summary to stale "no-parent gate" text, supervisor restored the current source summary and validated it with UID-only command `000000000961` at `2026-06-25T02:23:49-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped`.

- [x] Check-only: [UID:0002RO] `by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md`
  - Checked as already sufficient. It documents `0x00582ef0` / `0x00582fa0` as ANSI/wide grow helpers preserving contents and records decompilation for `0x00582ef0` retaining/releasing/allocating/copying. No direct contradiction found; no edit made.

- [x] Check-only: [UID:0001VQ] `by-type/by-struct/RefCountedStringBufferHeader.md`
  - Checked as already sufficient. It documents the 12-byte header fields `refCount` at `-0x0c`, `length` at `-0x08`, and `capacity` at `-0x04`, plus append/copy-on-write semantics and StringBase ownership. No direct contradiction found; no edit made.

- [x] Check-only: [UID:0001W4] `by-type/by-struct/SimpleUStringPointerBackedLayout.md`
  - Checked as already sufficient. It documents one-pointer `m_data`, data-relative `refCount/length/capacity`, `StringBase` as current source owner, and `SimpleUString` as facade/search-alias context. No direct contradiction found; no edit made.

- [x] Check-only: [UID:0000TM] `by-global/StringBufferSentinelsAndPools.md`
  - Checked as already sufficient. It keeps sentinels/pools under [UID:0000OA] `StringBase`, keeps [UID:0000OB] `StringUtil` broad, and keeps allocator mechanics with `PoolAllocator`. No direct contradiction found; no edit made.

- [x] Check-only: [UID:0000OB] `by-file/StringUtil.md`
  - Checked as already sufficient. It treats [UID:0000OA] `StringBase` as the preferred companion/direct root for the ref-counted `mystr::StringBase` family rather than making `StringUtil` the direct owner of [UID:0002RS]. No direct contradiction found; no edit made.

- [x] Check-only: [UID:000325] `by-memory/0x004671b0-0x004671de.StringBaseAppendWideLiteral.md`
  - Checked as already sufficient. Formal C++ emits `operator+=(const wchar_t*)` and calls `AppendWideLiteral(rhs, count)`; `AppendWideData` and `sub_584470` remain only historical/search/rejected-alternative labels. No direct contradiction found; no edit made.

- [x] Generated/coverage handling
  - B005 did not edit `auto-generated/*`, `project-level/*`, `tools/validator.ini`, validator queue/state/cache, IDA DB, or any `-coverage-report.md` file.
  - Leases used/released for support edit batch: leased and released successfully for [UID:0001J3], [UID:0002LN], [UID:0002LO], [UID:0000OA], and [UID:0001WS].
  - Validator/default metadata conflict resolved by supervisor UID-only corrections for [UID:0002RS], [UID:0002LN], and [UID:0002LO] after the normal support validators had already passed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002RS-StringBaseAppendAndFind-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002RS-StringBaseAppendAndFind-source-quality.md","timestamp":"2026-06-25T02:24:28","uid":"0002RS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
