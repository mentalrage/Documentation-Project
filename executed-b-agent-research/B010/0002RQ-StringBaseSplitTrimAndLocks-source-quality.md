** TARGET-REPORT-UID:0002RQ **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002RQ StringBase Split Trim And Locks Source-Quality Research

Agent: B010
Assignment id: `B010-report-0002RQ-stringbase-replace-trim-and-locks-20260625`
Mode: report-only research first
Target: [UID:0002RQ] `by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md`
Required report path: `tools/leaser/Agents/Agent-B010/research/0002RQ-StringBaseSplitTrimAndLocks-source-quality.md`

## Executive Recommendation

Keep the existing UID and physical by-memory path for implementation stability, but correct the source-facing interpretation from "replace" to "split/tokenize":

- `CANONICAL_OWNER:0000OA`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OA`
- blank `EMITTER_POSITION_OPTIONAL`
- raise from `COMPLETION:86`, `CONFIDENCE:89` to `COMPLETION:90`, `CONFIDENCE:91`
- populate first-draft formal `RECONSTRUCTION_CPP CODE`

Recommended Item Summary:

`StringBase UTF-16 slice, delimiter split, trim-left/right, and ANSI/UTF-16 writable-buffer lock helpers over the 12-byte ref-counted buffer header; current MCP evidence corrects stale replace/search-helper wording and supports formal first-draft C++ through StringBase.`

Recommended display heading:

`# 0x00583970-0x00584052 StringBase Split Trim And Locks`

Do not rename the by-memory file during the first implementation callback unless the supervisor explicitly accepts a path migration. Generated/manual default rows already reference the existing `StringBaseReplaceTrimAndLocks` path at stale `76/84`, so a path rename is a separate registry/default synchronization risk. The body, title, summary, and support docs should state that the filename's `Replace` segment is stale.

The target clears the current code-entry gate: it is reconstructable, has a valid emitter route through [UID:0000OA] `StringBase`, and its current average score is already greater than `85`. The old blank-C++ rationale relies on stale `90/90+`/`95+` gate wording and unresolved names. Current MCP resolves the behavior and source-facing names enough for first-draft formal C++.

## Current Target State

Current source target header:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000OA`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OA`
- blank `EMITTER_POSITION_OPTIONAL`
- formal `RECONSTRUCTION_CPP CODE` block blank
- Item Summary: `UTF-16 mid/replace/trim and writable-buffer lock helpers over ref-counted string storage.`

Current source-quality issues:

- `0x005839c0` is documented as a wide replace worker, but current decompilation and callers show a delimiter split/tokenization helper that fills a `SimpleUStringVector`.
- The adjacent search-helper docs invert several source-facing names: `0x00584720` is first-not-of, `0x005847a0` is first-of, and `0x00584820` is last-not-of. This target proves the correction because trim-left uses `0x00584720`, split uses `0x005847a0` followed by `0x00584720`, and trim-right uses `0x00584820`.
- The target says formal C++ remains blank because the group is below an old code-entry gate. That is stale under the current by-structure rule.
- The target title/path includes stale `Replace` wording. The report recommends correcting the display title and all body prose now, while leaving path rename to a separate supervisor-approved migration if desired.

Generated/default state checked read-only:

- `auto-generated/NexusTK/util/StringBase.cpp` still has [UID:0002RQ] as `Completion:76 | Confidence:84 | Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` lists [UID:0002RQ] as `76/84`.
- `auto-generated/-ag-coverage-report-by-memory.md` lists [UID:0002RQ] as `emits_code:false`, stale `76%`, and the old replace summary.
- Supervisor-owned/manual `by-memory/-coverage-report.md` also has the stale `76%` row and old summary.

B010 did not edit generated files, project-level files, manual coverage/default reports, validator state/cache, or IDA DB in this report-only pass.

## Live MCP Provenance

IDA MCP was mandatory and was available.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp` version `1.0.0`
- Active database/session: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health` command id `12`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`
- No IDA DB edits were made.

MCP commands used for this report:

- `lookup_funcs` id `101`
- `entity_query` id `104`
- `get_bytes` id `106`
- `analyze_component` id `107`
- `analyze_function` ids `108` through `113`
- `decompile` id `114` for the full `0x005839c0` body
- dependency `analyze_function` ids `115` through `120`
- `xrefs_to` id `121`
- `xref_query` id `122`
- caller `decompile` ids `123` through `125`

## Boundary Evidence

Current MCP `lookup_funcs` id `101` and `entity_query` id `104` confirm the exact in-range functions and successor:

| Range | IDA name | Size | Current source-facing role |
| --- | --- | ---: | --- |
| `0x00583970-0x005839be` | `sub_583970` | `0x4e` | `SliceWideRange` / range-style wide substring wrapper |
| `0x005839c0-0x00583e65` | `sub_5839C0` | `0x4a5` | `SplitWideBySet` / delimiter split into `SimpleUStringVector` |
| `0x00583e70-0x00583f69` | `sub_583E70` | `0xf9` | `TrimLeftWide` |
| `0x00583f70-0x00584018` | `sub_583F70` | `0xa8` | `TrimRightWide` |
| `0x00584020-0x00584032` | `sub_584020` | `0x12` | `LockAnsiBuffer` |
| `0x00584040-0x00584052` | `sub_584040` | `0x12` | `LockWideBuffer` |
| `0x00584060-0x005840ea` | `sub_584060` | `0x8a` | successor byte/range comparator, outside target |

`lookup_funcs` also reports no modeled function at `0x00583968` or `0x00584052`.

`get_bytes` id `106` confirms all immediate boundary gaps are alignment `0xcc`:

- `0x00583968-0x00583970`: eight `0xcc` bytes before the target.
- `0x005839be-0x005839c0`: two `0xcc` bytes.
- `0x00583e65-0x00583e70`: eleven `0xcc` bytes.
- `0x00583f69-0x00583f70`: seven `0xcc` bytes.
- `0x00584018-0x00584020`: eight `0xcc` bytes.
- `0x00584032-0x00584040`: fourteen `0xcc` bytes.
- `0x00584052-0x00584060`: fourteen `0xcc` bytes before successor `0x00584060`.

Representative entry bytes from `get_bytes` id `106`:

- `0x00584020`: `8b 01 39 05 90 02 67 00 74 07 c7 40 f4 01 00 00 00 c3`, comparing against ANSI sentinel `0x00670290`, writing `data[-3] = 1`, and returning.
- `0x00584040`: `8b 01 39 05 78 02 67 00 74 07 c7 40 f4 01 00 00 00 c3`, comparing against wide sentinel `0x00670278`, writing `data[-3] = 1`, and returning.

No split or hidden function is needed inside the target. The page covers six whole source-authored StringBase helper bodies separated by ordinary alignment padding.

## Function Behavior From Current MCP

`analyze_component` id `107` reports the six functions as interface functions with no internal call-graph edges. Shared globals are the wide empty sentinel `0x00670278` and the security cookie `0x00672f24`; `0x00670290` appears in the ANSI lock helper through xrefs. The security-cookie references are compiler EH/frame protection for the stack-protected split/trim helpers, not source-level logic.

### `0x00583970` / `SliceWideRange`

`analyze_function` id `108` shows a range-style wide substring wrapper:

- Reads source length from `m_data[-2]`.
- Normalizes a negative first index as `length + start`; otherwise uses `start`.
- Normalizes a non-positive second index as `length + end`; otherwise uses `end`.
- If `end > start`, delegates to `0x00584d00` with `(start, end - start)`.
- Otherwise stores the wide empty sentinel `0x00670278` in the output object.

Direct callers are `0x004b1d50` and `0x004b3090`. This is not an ordinary `(start, count)` wrapper; the second argument is best treated as an end bound under current evidence. Use `SliceWideRange` or `MidRangeWide` wording rather than generic `Mid(start,count)` prose.

### `0x005839c0` / `SplitWideBySet`

`decompile` id `114` resolves the stale "replace" label. The function:

- Clears the caller-provided vector by releasing every existing wide string handle and resetting vector `end` to `begin`.
- Reads source length from `m_data[-2]` and returns immediately for an empty source.
- Uses `0x005847a0` to find the first delimiter character from the caller-provided delimiter set.
- Pushes the text segment preceding each delimiter run into the vector.
- Uses `0x00584720` to find the next non-delimiter character after a delimiter run.
- If the fourth argument byte is nonzero, also pushes delimiter-run segments into the vector.
- Releases every temporary wide handle after `SimpleUStringVector::PushBack`.
- Uses `0x00584910` `SimpleUStringVector::PushBack` and `0x0049cc40` `SimpleUStringVector::GrowAndInsert` as vector dependencies.

Current callers prove split/tokenization semantics:

- Caller `0x004b2730` passes `L"\\/"` and a zero flag, then iterates the resulting vector as path components. This is path delimiter splitting, not replacement.
- Caller `0x00577140` passes `L" \t"` and a zero flag while parsing a text list into at least two fields. This is whitespace/tab tokenization, not replacement.

The fourth argument is best named `keepDelimiters` or `includeDelimiters`. Both observed callers pass `0`, so the production call sites discard delimiter runs.

### `0x00583e70` / `TrimLeftWide`

`analyze_function` id `110` shows trim-left behavior:

- If the wide buffer is shared (`refCount > 1`), allocates a same-length wide buffer through `0x00582e30`, copies `2 * length` bytes, and releases the old buffer through `0x005833a0`.
- Calls `0x00584720` with the caller-provided trim set. Current decompilation of `0x00584720` proves this is first-not-of, which is exactly the operation needed for trim-left.
- If every character is in the trim set, releases the whole wide buffer through `0x005833a0`.
- Otherwise shifts the remaining UTF-16 tail left with `memmove_0`, writes the terminator, and updates `m_data[-2]` to the new length.

Direct callers are `0x004918e0`, `0x0053f830`, `0x00570c80`, and `0x00588800`.

### `0x00583f70` / `TrimRightWide`

`analyze_function` id `111` shows trim-right behavior:

- Performs the same detach-if-shared copy/release path as trim-left.
- Calls `0x00584820` with start index `0xffffffff`. Current decompilation proves this callee is last-not-of, not last-of.
- Calls `0x00584600` remove/erase helper with `(lastNonTrim + 1, 0xffffffff)`, removing the trailing trim span.

Direct callers are the same four trim caller groups as trim-left.

### `0x00584020` / `LockAnsiBuffer`

`analyze_function` id `112` shows an 18-byte ANSI lock helper:

- Returns `m_data`.
- If `m_data` is not the ANSI empty sentinel `0x00670290`, writes `m_data[-3] = 1`.
- It does not allocate, grow, detach, or update length/capacity.

Direct caller: `0x004b12a0`.

### `0x00584040` / `LockWideBuffer`

`analyze_function` id `113` shows the UTF-16 twin:

- Returns `m_data`.
- If `m_data` is not the wide empty sentinel `0x00670278`, writes `m_data[-3] = 1`.
- It does not allocate, grow, detach, or update length/capacity.

Direct callers: `0x004f95b0` twice, `0x005063e0`, and `0x0058e3e0`.

## Search-Helper Correction Evidence

The current target exposes a source-facing naming error in sibling [UID:0003NL] search-helper docs.

`analyze_function` id `115` for `0x00584720`:

- Iterates forward from a start index.
- Skips characters that are present in the caller-provided set.
- Returns the first index whose character is not in the set.
- Direct callers are `0x005839c0` and trim-left `0x00583e70`.

Recommended role: `FindFirstNotOf`, not first-of.

`analyze_function` id `116` for `0x005847a0`:

- Iterates forward from a start index.
- Skips characters that are not present in the set.
- Returns the first index whose character is present in the set.
- Direct callers are `0x004918e0` and split helper `0x005839c0`.

Recommended role: `FindFirstOf`, not first-not-of.

`analyze_function` id `117` for `0x00584820`:

- Iterates backward from a bounded start index.
- Skips characters that are present in the set.
- Returns the last index whose character is not in the set.
- Direct callers are `0x0056c0e0` and trim-right `0x00583f70`.

Recommended role: `FindLastNotOf`, not last-of.

By symmetry and existing [UID:0003NL] grouping, `0x005848a0` should be checked and renamed to `FindLastOf` during implementation support sync if current decompilation confirms the complementary behavior.

## Caller, Callee, And Xref Evidence

`xrefs_to` id `121` reports direct code xrefs:

| Function | Direct code xrefs |
| --- | --- |
| `0x00583970` | 2, from `0x004b1d50` and `0x004b3090` |
| `0x005839c0` | 2, from `0x004b2730` and `0x00577140` |
| `0x00583e70` | 4, from `0x004918e0`, `0x0053f830`, `0x00570c80`, `0x00588800` |
| `0x00583f70` | 4, from the same four caller groups |
| `0x00584020` | 1, from `0x004b12a0` |
| `0x00584040` | 4, from `0x004f95b0`, `0x005063e0`, `0x0058e3e0` |

`xref_query` id `122` reports zero data xrefs to all six function starts. That is useful negative evidence against vtable/table-driven ownership, but not a liveness blocker because every function has direct code callers.

Sentinel and trim pointer refs from `xrefs_to` id `121`:

- `0x00670278` wide empty sentinel: 23 refs total. Target-relevant refs are `0x00583999`, four sites inside `0x005839c0`, and `0x00584042`.
- `0x00670290` ANSI empty sentinel: 16 refs total. Target-relevant ref is `0x00584022`.
- `0x0067027c` trim whitespace pointer: 8 refs in four two-use caller groups. Each group passes the same pointer to trim-left and trim-right behavior.

Dependency checks:

- `0x00584600` (`analyze_function` id `118`) is the remove/erase helper used by trim-right.
- `0x00584d00` (`analyze_function` id `119`) is the bounded substring helper called by `SliceWideRange`.
- `0x00584910` (`analyze_function` id `120`) is the `SimpleUStringVector::PushBack` dependency called twice by the split helper.

## Ownership And Source-Placement Analysis

Ranked candidates:

1. [UID:0000OA] `StringBase` as direct canonical owner and emitter route.
   - Strongest candidate. Five of the six bodies directly operate on `StringBase` UTF-16/ANSI storage and the 12-byte header; the split helper is also a `StringBase` method that fills an external vector with segments.
   - Existing sibling [UID:0002RS] uses [UID:0000OA] for concrete append/accessor/compare helpers, and [UID:0002RM] uses [UID:0000OA] for mixed concrete StringBase methods plus file-local shims.
   - Generated output route is already `auto-generated/NexusTK/util/StringBase.cpp`.

2. [UID:0001WS] `StringBaseTemplate` as type/header support.
   - Strong type evidence and declaration context. It should gain method inventory notes for `SliceWideRange`, `SplitWideBySet`, `TrimLeftWide`, `TrimRightWide`, and lock helpers.
   - Not the best whole-target canonical owner because this target is a concrete UTF-16-heavy helper group with an external `SimpleUStringVector` dependency, not a pure template primitive group like [UID:0002RT].

3. [UID:0000DA] `SimpleUStringVector` as dependency owner only.
   - The split helper calls [UID:0001J4] `SimpleUStringVector::PushBack`, but the vector method is outside this range. Caller dependency does not transfer ownership.

4. [UID:0000OB] `StringUtil`, [UID:0000D9] `SimpleUString`, [UID:0000KV] `LObject`, and caller modules.
   - Rejected as direct owners. `StringUtil` and `SimpleUString` remain facade/utility context; `LObject` is stale generated pollution; callers are consumers.

Recommended direct metadata therefore keeps [UID:0000OA] for both `CANONICAL_OWNER` and `EMITTER_UIDS`.

## Heuristic / Inference Reanalysis

### Replace Worker Rejected

Reject `ReplaceWide` / replace-worker wording for `0x005839c0`.

Evidence:

- No replacement text argument exists. Parameters are source string, output vector, delimiter character set, and a byte flag.
- Both current callers pass delimiter sets: `L"\\/"` for path splitting and `L" \t"` for whitespace/tab splitting.
- The body calls a vector push-back method and grows/inserts into a vector; it does not write replacement text back into the source string.
- The body can optionally include delimiter runs when the fourth argument byte is nonzero.

Best current role: `SplitWideBySet`, `SplitWide`, or `TokenizeWideBySet`. This report uses `SplitWideBySet` in formal code because it states the character-set behavior.

### Search Helper Names Corrected

The current target requires the support correction:

- `0x00584720` -> `FindFirstNotOf`
- `0x005847a0` -> `FindFirstOf`
- `0x00584820` -> `FindLastNotOf`
- likely `0x005848a0` -> `FindLastOf`, pending implementation recheck

This is not cosmetic. Trim-left uses first-not-of, trim-right uses last-not-of, and split/tokenization alternates first-of and first-not-of.

### Slice Wrapper Naming

`0x00583970` is better documented as `SliceWideRange` or `MidRangeWide` than as a generic `Mid(start,count)` helper. The binary normalizes the first and second arguments as start and end bounds, then calls the lower-level substring helper with computed count.

### Lock Helpers

`0x00584020` and `0x00584040` should remain lock helpers, not grow/detach helpers. They only mark non-sentinel buffers with `refCount = 1` and return the data pointer. This is compatible with source-facing names `LockAnsiBuffer` and `LockWideBuffer`.

## Formal RECONSTRUCTION_CPP CODE Recommendation

Populate the target formal block with this exact first-draft insertion text. The code uses inferred source-facing names and helper declarations from adjacent accepted StringBase pages. It is not final audited source.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace mystr {

namespace {

template <class CharT>
static unsigned int StoredLength(const CharT *data)
{
    return static_cast<unsigned int>(reinterpret_cast<const int *>(data)[-2]);
}

template <class CharT>
static int StoredRefCount(const CharT *data)
{
    return reinterpret_cast<const int *>(data)[-3];
}

template <class CharT>
static void SetStoredRefCount(CharT *data, int refCount)
{
    reinterpret_cast<int *>(data)[-3] = refCount;
}

template <class CharT>
static void SetStoredLength(CharT *data, unsigned int length)
{
    reinterpret_cast<int *>(data)[-2] = static_cast<int>(length);
}

static void DetachWideIfShared(
    StringBase<wchar_t, mychar_traits<wchar_t> > &value)
{
    wchar_t *oldData = value.m_data;
    if (StoredRefCount(oldData) <= 1) {
        return;
    }

    const unsigned int length = StoredLength(oldData);
    value.AllocateWideBuffer(length);
    memmove(value.m_data, oldData, length * sizeof(wchar_t));

    StringBase<wchar_t, mychar_traits<wchar_t> > oldValue;
    oldValue.m_data = oldData;
    oldValue.ReleaseWideBuffer();
}

static void BuildWideSegment(
    StringBase<wchar_t, mychar_traits<wchar_t> > &out,
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source,
    unsigned int start,
    unsigned int count)
{
    const unsigned int length = StoredLength(source.m_data);
    unsigned int clampedStart = start;
    if (length < clampedStart) {
        clampedStart = length;
    }

    unsigned int clampedEnd = length;
    if (count != 0xffffffffU) {
        clampedEnd = clampedStart + count;
        if (length < clampedEnd) {
            clampedEnd = length;
        }
    }

    const unsigned int segmentLength = clampedEnd - clampedStart;
    if (clampedStart == 0 && count == 0xffffffffU) {
        out.CopyOrShareWide(source);
        return;
    }

    out.AllocateWideBuffer(segmentLength);
    memmove(out.m_data,
            source.m_data + clampedStart,
            segmentLength * sizeof(wchar_t));
}

static void PushWideSegment(
    SimpleUStringVector &parts,
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source,
    unsigned int start,
    unsigned int count)
{
    StringBase<wchar_t, mychar_traits<wchar_t> > part;
    BuildWideSegment(part, source, start, count);
    parts.PushBack(part);
    part.ReleaseWideBuffer();
}

} // namespace

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::SliceWideRange(
    StringBase<wchar_t, mychar_traits<wchar_t> > &out,
    int start,
    int end) const
{
    const int length = static_cast<int>(StoredLength(m_data));
    const int first = start < 0 ? length + start : start;
    const int last = end > 0 ? end : length + end;

    if (last > first) {
        SubstringWide(out, static_cast<unsigned int>(first),
                      static_cast<unsigned int>(last - first));
    } else {
        out.m_data = g_emptyWideString;
    }

    return out;
}

template <>
void
StringBase<wchar_t, mychar_traits<wchar_t> >::SplitWideBySet(
    SimpleUStringVector &parts,
    const wchar_t *delimiters,
    bool keepDelimiters) const
{
    parts.Clear();

    const unsigned int length = StoredLength(m_data);
    if (length == 0) {
        return;
    }

    const unsigned int delimiterCount =
        static_cast<unsigned int>(wcslen(delimiters));
    unsigned int cursor = 0;

    for (;;) {
        const int delimiterIndex =
            FindFirstOf(delimiters, cursor, delimiterCount);
        if (delimiterIndex == -1) {
            PushWideSegment(parts, *this, cursor, 0xffffffffU);
            return;
        }

        PushWideSegment(parts,
                        *this,
                        cursor,
                        static_cast<unsigned int>(delimiterIndex) - cursor);

        const int nextTextIndex = FindFirstNotOf(
            delimiters,
            static_cast<unsigned int>(delimiterIndex),
            delimiterCount);
        if (nextTextIndex == -1) {
            if (keepDelimiters) {
                PushWideSegment(parts,
                                *this,
                                static_cast<unsigned int>(delimiterIndex),
                                0xffffffffU);
            }
            return;
        }

        if (keepDelimiters) {
            PushWideSegment(
                parts,
                *this,
                static_cast<unsigned int>(delimiterIndex),
                static_cast<unsigned int>(nextTextIndex - delimiterIndex));
        }

        cursor = static_cast<unsigned int>(nextTextIndex);
        if (cursor >= length) {
            return;
        }
    }
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::TrimLeftWide(
    const wchar_t *trimChars)
{
    DetachWideIfShared(*this);

    const unsigned int length = StoredLength(m_data);
    const int firstText = FindFirstNotOf(
        trimChars,
        0,
        static_cast<unsigned int>(wcslen(trimChars)));
    unsigned int trimCount = static_cast<unsigned int>(firstText);
    if (trimCount >= length) {
        trimCount = length;
    }

    if (trimCount == 0) {
        return *this;
    }

    if (trimCount == length) {
        ReleaseWideBuffer();
        return *this;
    }

    MakeExclusiveWide();
    const unsigned int newLength = length - trimCount;
    memmove(m_data, m_data + trimCount, newLength * sizeof(wchar_t));
    m_data[newLength] = L'\0';
    SetStoredLength(m_data, newLength);
    return *this;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::TrimRightWide(
    const wchar_t *trimChars)
{
    DetachWideIfShared(*this);

    const int lastText = FindLastNotOf(
        trimChars,
        0xffffffffU,
        static_cast<unsigned int>(wcslen(trimChars)));
    RemoveWideRange(static_cast<unsigned int>(lastText + 1), 0xffffffffU);
    return *this;
}

template <>
char *
StringBase<char, mychar_traits<char> >::LockAnsiBuffer()
{
    if (m_data != g_emptyAnsiString) {
        SetStoredRefCount(m_data, 1);
    }

    return m_data;
}

template <>
wchar_t *
StringBase<wchar_t, mychar_traits<wchar_t> >::LockWideBuffer()
{
    if (m_data != g_emptyWideString) {
        SetStoredRefCount(m_data, 1);
    }

    return m_data;
}

} // namespace mystr
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Formal C++ caveats:

- `SplitWideBySet`, `SliceWideRange`, `TrimLeftWide`, `TrimRightWide`, `LockAnsiBuffer`, and `LockWideBuffer` are inferred source-facing names, not symbol-proven original names.
- `SimpleUStringVector::Clear`, `SimpleUStringVector::PushBack`, `FindFirstOf`, `FindFirstNotOf`, `FindLastNotOf`, `SubstringWide`, `RemoveWideRange`, `AllocateWideBuffer`, `ReleaseWideBuffer`, `CopyOrShareWide`, and `MakeExclusiveWide` are adjacent helper names inferred from current support pages. If implementation uses a slightly different local helper spelling, document the exact replacement.
- The split helper formal code intentionally preserves delimiter-token behavior and the optional delimiter-retention flag. Both observed callers pass `false`.
- The source form uses helper functions for repeated temporary segment construction; the binary expands that logic in the `0x005839c0` body with stack temporaries, vector push-back, grow/insert, refcount increments, and releases.

## Score Recommendation

Recommended `90/91`:

- Completion rises because current MCP evidence now covers live session provenance, exact function inventory, padding, caller/callee groups, sentinel/whitespace xrefs, zero data xrefs to starts, dependency helper behavior, stale replace-label correction, search-helper role correction, and formal first-draft C++ readiness.
- Confidence rises because caller decompilation independently proves split/tokenization semantics (`L"\\/"` path splitting and `L" \t"` whitespace/tab splitting), while trim and lock helpers are direct and simple.
- Score remains below final audit because exact original method names, exact public/private API spelling, `StringBase` versus `SimpleUString` facade names, vector element type spelling, and whether the by-memory file path should be renamed remain not symbol-proven.

Do not raise this target to `95+` without a broad StringBase/StringUtil API declaration audit and source-path/path-rename decision.

## Target Documentation Implementation Requirements

When supervisor accepts this report, update [UID:0002RQ] with report-level detail:

- Set metadata to `COMPLETION:90`, `CONFIDENCE:91`, retaining `CANONICAL_OWNER:0000OA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`, and blank `EMITTER_POSITION_OPTIONAL`.
- Replace the Item Summary with the recommended exact summary.
- Change the display heading to `StringBase Split Trim And Locks`; keep the physical file path unchanged unless supervisor explicitly accepts a path migration.
- Replace stale `replace worker` wording with `SplitWideBySet` / delimiter split/tokenization wording.
- Correct the slice wrapper from generic `Mid(start,count)` to a range/end-bound substring wrapper.
- Replace stale blank-C++ gate wording with the current by-structure code-entry rule and insert the formal C++ block above.
- Record current MCP session `80de0a67` with command ids and evidence categories from this report.
- Document the caller proof from `0x004b2730` and `0x00577140`.
- Document zero data xrefs to the six starts and the direct code xref counts.
- Keep raw `sub_*` names only in evidence/provenance tables, not as source-facing names.

## Support Documentation Implementation Requirements

Required support updates if this report is accepted:

1. `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md`
   - Update the [UID:0002RQ] child row from replace/trim/locks to slice/split/trim/locks.
   - Update covered-range rows for `0x005839c0` to `SplitWideBySet`.
   - Update search-helper role rows: `0x00584720` first-not-of, `0x005847a0` first-of, `0x00584820` last-not-of, and after rechecking `0x005848a0`, likely last-of.
   - Keep the aggregate non-emitting/contextual.

2. `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md`
   - Correct the source-facing search helper names listed above.
   - Note that [UID:0002RQ] trim/split behavior is current-session proof for those corrections.
   - Recheck `0x005848a0` during implementation before writing the final complementary last-of wording.

3. `by-file/StringBase.md`
   - Add [UID:0002RQ] as the formal-code owner for UTF-16 range slicing, delimiter split/tokenization, trim-left/right, and ANSI/UTF-16 lock helpers.
   - Note that B010 supersedes the old replace-worker and blank-C++ gate wording.
   - Preserve `StringBase.cpp` as direct source root and [UID:0000OB] `StringUtil` as broad context only.

4. `by-type/by-template/StringBaseTemplate.md`
   - Add the [UID:0002RQ] method inventory: `SliceWideRange`, `SplitWideBySet`, `TrimLeftWide`, `TrimRightWide`, `LockAnsiBuffer`, and `LockWideBuffer`.
   - Preserve final API/facade spelling caveats and keep the template page's own full-declaration C++ blank.

5. `by-type/by-struct/RefCountedStringBufferHeader.md`
   - Add current [UID:0002RQ] evidence that trim helpers read `refCount` and `length`, and lock helpers set `refCount = 1` for non-sentinel buffers.
   - Preserve the interpretation of negative refcount as non-shareable/private state.

6. `by-global/StringBufferSentinelsAndPools.md`
   - Add current session evidence tying the trim whitespace pointer `0x0067027c` to the four two-call trim-left/right caller groups and tying ANSI/wide sentinels to lock helpers.

7. `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md` and `by-class/SimpleUStringVector.md`
   - Replace direct "StringBase replace worker" caller wording with "StringBase split/tokenization helper" or "StringBase delimiter split helper" wording for the two `0x005839c0` caller sites.
   - Keep direct vector ownership under [UID:0000DA].

Check-only unless direct contradiction appears during implementation:

- [UID:0003NM] `StringBaseSpliceGrowAndSubstring`: still supplies the substring helper at `0x00584d00`; no routine edit required except optional caller wording.
- [UID:0002RO] `StringBaseAllocationGrowAndCow`: allocation/grow helpers are already sufficiently documented.
- [UID:0002RS] `StringBaseAppendAndFind`: no direct contradiction; its append/accessor/compare roles stay accepted.
- [UID:0000OB] `StringUtil`: keep as broad utility-string context, not direct owner for this target.

## Rejected Alternatives And Negative Evidence

- Do not keep `ReplaceWide` / replace-worker as the source-facing role for `0x005839c0`; current callers and decompilation prove split/tokenization.
- Do not route the target to `SimpleUStringVector`; vector methods are external dependencies/callees, not the owner of this StringBase method.
- Do not route to `StringUtil`, `SimpleUString`, `LObject`, or caller modules as direct owner.
- Do not split the six target functions into new child pages. They are complete sibling helpers in one contiguous StringBase helper group, with ordinary padding and one shared owner/emitter.
- Do not leave formal C++ blank solely because exact original API names remain inferred. That uncertainty caps score below final audit but does not block first-draft reconstruction.
- Do not treat security-cookie/EH frame artifacts in `0x005839c0`, `0x00583e70`, or `0x00583f70` as source logic.
- Do not treat lock helpers as grow/detach helpers; they only set `refCount = 1` on non-sentinel buffers.
- Do not edit generated/manual coverage/default files as B010 during implementation unless supervisor explicitly overrides the standard restriction.

## Validator And Generated-State Risk

No validators were run in this report-only pass.

Implementation validator commands after accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002RQ-StringBaseSplitTrimAndLocks-source-quality-removed.md](0002RQ-StringBaseSplitTrimAndLocks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After target validation with `--wait-generated`, re-read:

- target by-memory header, Item Summary, display heading, and formal C++ block
- `auto-generated/NexusTK/util/StringBase.cpp`
- generated tracker/coverage rows if validator reports generated refresh

If normal validation reverts [UID:0002RQ] to stale `76/84`, stale replace summary, or an empty marker because of supervisor-owned manual/default rows, stop and report `PAUSED_VALIDATOR_METADATA_CONFLICT` with the command proof and active header text. Do not use UID-only workarounds or edit `by-memory/-coverage-report.md` unless the supervisor explicitly owns that correction.

## Implementation Tracking Checklist

- [x] Target `by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md`: metadata updated to `COMPLETION:90`, `CONFIDENCE:91`, owner/emitter [UID:0000OA][StringBase](by-file/StringBase.md) preserved, reconstructable true preserved, blank optional position preserved. Proof: post-validator readback shows those header fields unchanged.
- [x] Target Item Summary replaced exactly with the recommended summary. Proof: post-validator `rg` readback shows the accepted summary text at the target Item Summary header.
- [x] Target display heading changed to `StringBase Split Trim And Locks`; physical file path left unchanged unless supervisor explicitly accepts a path migration. Proof: target heading is `# 0x00583970-0x00584052 StringBase Split Trim And Locks`, and the path remains `by-memory/0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md`.
- [x] Target prose updated with current MCP session `80de0a67` evidence: function inventory, padding, component analysis, per-helper behavior, caller decompilation, xrefs, sentinel/whitespace refs, zero data xrefs, and dependency helpers. Proof: target now records the six-function inventory, padding bytes, MCP ids `101`-`125`, implementation recheck ids `203`/`205`, caller tables, sentinel/whitespace refs, zero data xrefs, and dependency helper analysis.
- [x] Target stale replace-worker wording removed or explicitly marked stale; `0x005839c0` documented as `SplitWideBySet`. Proof: target role row and per-helper section name `0x005839c0` as `SplitWideBySet`; old replace wording appears only in historical/stale/rejected-assumption context.
- [x] Target stale blank-C++/old-gate wording replaced by the current reconstructable/nonblank-emitter/average-score gate. Proof: target formal C++ block is populated and the scoring/change rationale records current gate eligibility through [UID:0000OA][StringBase](by-file/StringBase.md).
- [x] Target formal `RECONSTRUCTION_CPP CODE` populated with the exact block in this report, or any deviation documented with concrete reason. Proof: target readback shows the formal block begins after `RECONSTRUCTION_CPP CODE:BEGIN`, contains `SliceWideRange`, `SplitWideBySet`, `TrimLeftWide`, `TrimRightWide`, `LockAnsiBuffer`, and `LockWideBuffer`, and ends at the formal `END` marker.
- [x] Target source-facing names applied; raw `sub_*` labels confined to evidence/provenance. Proof: target final source/body text uses `SliceWideRange`, `SplitWideBySet`, `TrimLeftWide`, `TrimRightWide`, `LockAnsiBuffer`, `LockWideBuffer`, and leaves `sub_*` only in the IDA-function inventory/provenance notes.
- [x] Target rejected alternatives/negative evidence incorporated: reject replace role, vector direct owner, StringUtil/LObject/caller ownership, split/new-child creation, security-cookie source logic, and lock-as-grow interpretation. Proof: target rejected-alternatives section records each rejection and the score/source-placement rationale.
- [x] `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md` synchronized for [UID:0002RQ] split/tokenization and corrected search-helper role rows while remaining non-emitting. Proof: support page now lists `SliceWideRange`, `SplitWideBySet`, corrected lock behavior, and search roles `FindFirstNotOf`, `FindFirstOf`, `FindLastNotOf`, `FindLastOf`; validator `000000001823` returned exit code 0 and `ok: 1`.
- [x] `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md` corrected for first-of/not-of and last-of/not-of names after rechecking `0x005848a0`. Proof: implementation recheck on MCP session `80de0a67` used `analyze_function` id `203` and `decompile` id `205`; support page now maps `0x005848a0` to `FindLastOf`; validator `000000001824` returned exit code 0 and `ok: 1`.
- [x] `by-file/StringBase.md` synchronized with [UID:0002RQ] as a first-draft-emitting slice/split/trim/lock helper group. Proof: the likely-contents table, evidence bullets, cross-reference list, and change log now mention [UID:0002RQ] and supersede old replace-worker/blank-C++ gate wording; validator `000000001825` returned exit code 0 and `ok: 1`.
- [x] `by-type/by-template/StringBaseTemplate.md` method inventory updated; full template declaration C++ remains blank. Proof: method inventory and direct-helper table now include `SliceWideRange`, `SplitWideBySet`, `TrimLeftWide`, `TrimRightWide`, `LockAnsiBuffer`, and `LockWideBuffer`; formal template C++ remains empty; validator `000000001826` returned exit code 0 and `ok: 1`.
- [x] `by-type/by-struct/RefCountedStringBufferHeader.md` updated with trim/refcount/lock evidence if accepted in callback scope. Proof: evidence, IDA notes, cross-reference list, and change log now record trim helpers reading `refCount`/`length` and lock helpers setting non-sentinel `refCount = 1` while preserving negative-refcount private-state interpretation; validator `000000001827` returned exit code 0 and `ok: 1`.
- [x] `by-global/StringBufferSentinelsAndPools.md` updated with trim whitespace pointer and lock sentinel evidence if accepted in callback scope. Proof: allocation/users, evidence, cross-reference list, and change log now tie `0x0067027c` to the four trim-left/right caller groups and `0x00670278`/`0x00670290` to lock helpers; validator `000000001828` returned exit code 0 and `ok: 1`.
- [x] `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md` and `by-class/SimpleUStringVector.md` caller wording changed from replace worker to split/tokenization helper if accepted in callback scope. Proof: both pages now describe the two `0x005839c0` caller sites as StringBase delimiter split/tokenization helper sites while keeping [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md) direct ownership; validators `000000001829` and `000000001830` returned exit code 0 and `ok: 1`.
- [x] Checked [UID:0003NM], [UID:0002RO], [UID:0002RS], and [UID:0000OB] for contradictions; edit only if accepted scope includes them or implementation introduces a direct contradiction. Proof: `rg` contradiction pass found no needed edits for [UID:0003NM], [UID:0002RO], or [UID:0002RS]; [UID:0000OB][StringUtil](by-file/StringUtil.md) had one stale `StringBase replace worker` line, changed to `StringBase split/tokenization helper`, and validator `000000001831` returned exit code 0 and `ok: 1`.
- [x] Scoped validators run for every changed by-* file from `E:\NTK\GhidraBridge\source-3\project-documentation`; record exact command, command id, timestamp, exit code, ok count, and generated-refresh state. Proof: target command `python .\tools\validator.py --mode file --file by-memory\0x00583970-0x00584052.StringBaseReplaceTrimAndLocks.md --apply --queue-timeout 240 --wait-generated` -> command `000000001821`, timestamp `2026-06-25T17:20:23-04:00`, exit 0, `ok: 1`, generated refresh completed. Support commands without `--wait-generated`: `0x005832f0...` -> `000000001823` / `2026-06-25T17:20:55-04:00`; `0x005845f0...` -> `000000001824` / `2026-06-25T17:20:56-04:00`; `StringBase.md` -> `000000001825` / `2026-06-25T17:20:58-04:00`; `StringBaseTemplate.md` -> `000000001826` / `2026-06-25T17:20:59-04:00`; `RefCountedStringBufferHeader.md` -> `000000001827` / `2026-06-25T17:21:01-04:00`; `StringBufferSentinelsAndPools.md` -> `000000001828` / `2026-06-25T17:21:02-04:00`; `SimpleUStringVectorPushBack.md` -> `000000001829` / `2026-06-25T17:21:12-04:00`; `SimpleUStringVector.md` -> `000000001830` / `2026-06-25T17:21:21-04:00`; `StringUtil.md` -> `000000001831` / `2026-06-25T17:21:23-04:00`. Each support validator returned exit 0, `ok: 1`, generated refresh deferred. Known stale/missing-reference diagnostics only: `0003NT`/`0003NL`, `00040Q`, `0003MS`, and `0003X8`.
- [x] Re-read target and generated `auto-generated/NexusTK/util/StringBase.cpp` after validation to confirm metadata, summary, formal C++ body, owner/emitter route, and generated output survived. Proof: target readback shows `COMPLETION:90`, `CONFIDENCE:91`, accepted Item Summary, heading, and nonblank formal C++; generated `StringBase.cpp` header is `validator-command-id: 000000001828`, `validator-refreshed-at: 2026-06-25T17:21:02-04:00`, newer than target command `000000001821`, and includes [UID:0002RQ] at `Completion:90 | Confidence:91` with `SplitWideBySet`, `LockAnsiBuffer`, and `LockWideBuffer`. Queue status command `000000001835` at `2026-06-25T17:25:02-04:00` reported no queued or processing generated-refresh jobs.
- [x] If normal validator path reverts to stale `76/84`, stale replace wording, or empty marker, return `PAUSED_VALIDATOR_METADATA_CONFLICT` instead of editing coverage/default/generated files. Proof: not triggered; readback did not show stale `76/84`, stale replace summary, or [UID:0002RQ] empty-emitter marker.
- [x] Leases released immediately after the accepted edit/validator batch. Proof: B010 leased the ten edited/validated by-* files for the batch and released them with `leaser.py B010 unlease ...`; `current_leases.md` afterward had no active B010 leases, only unrelated other-agent leases.

## Report-Only Compliance (Pre-Callback)

This section describes the original report-only pass before supervisor acceptance. The implementation callback proof is recorded in the checked implementation checklist above.

- No leases taken.
- No target/support by-* docs edited.
- No generated files edited.
- No project-level files edited.
- No coverage reports edited.
- No validator state/cache edited.
- No IDA DB edits made.
- No subagents spawned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0002RQ-StringBaseSplitTrimAndLocks-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002RQ-StringBaseSplitTrimAndLocks-source-quality.md","timestamp":"2026-06-25T17:26:29","uid":"0002RQ"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002RQ-StringBaseSplitTrimAndLocks-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0002RQ-StringBaseSplitTrimAndLocks-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002RQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
