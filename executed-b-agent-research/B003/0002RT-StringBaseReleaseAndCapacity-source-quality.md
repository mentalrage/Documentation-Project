** TARGET-REPORT-UID:0002RT **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Report - [UID:0002RT] StringBaseReleaseAndCapacity

Report-only assignment: [UID:0002RT] `by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md`

Report path: `tools/leaser/Agents/Agent-B003/research/0002RT-StringBaseReleaseAndCapacity-source-quality.md`

Status: report-only research complete. No target/support by-* docs, generated reports, project-level files, coverage reports, validator state/cache, or IDA database state were edited. No leases were taken.

## Current Recommendation

Update [UID:0002RT] from the current source header state `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`, blank formal C++ to:

- `COMPLETION:91`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0001WS`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0001WS`
- blank `EMITTER_POSITION_OPTIONAL`
- populate first-draft formal `RECONSTRUCTION_CPP CODE`

Recommended Item Summary:

`StringBaseTemplate release/capacity helper group: releases ANSI/wide ref-counted buffers to empty sentinels, fixed 64/128/256/512 pools, or heap; shares/copies wide buffers; sets ANSI/wide lengths with detach-on-share; makes wide storage exclusive; and forwards wide varargs formatting.`

Reason: current live MCP evidence resolves the exact eight-function helper group and makes the template/type owner [UID:0001WS] stronger than the previous file-only [UID:0000OA] route. [UID:0001WS] already emits through [UID:0000OA] `StringBase`, so generated output still lands in `auto-generated/NexusTK/util/StringBase.cpp`.

## Current Target State

Target page read during this report:

- Path: `by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md`
- Header: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`
- Current Item Summary: `ANSI/wide release, copy-init, capacity, and detach helpers with sentinel/pool evidence.`
- Stale target issue: it still says C++ is blank because final names/API shape remain below a "95% gate". The current project gate is not a simple 95+ rule; this target now has enough boundary, source route, helper role, and source-facing name evidence for first-draft target C++ while remaining below final audit.

Generated/manual state checked:

- `auto-generated/NexusTK/util/StringBase.cpp` was refreshed by validator command `000000000889` at `2026-06-25T01:33:25-04:00`, but still lists [UID:0002RT] as `Completion:74 | Confidence:84 | Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` also lists [UID:0002RT] as `74/84`.
- `auto-generated/-ag-coverage-report-by-memory.md` lists [UID:0002RT] as `74%`, `emits_code:false`, and the stale summary.
- Supervisor-owned `by-memory/-coverage-report.md` still has the stale [UID:0002RT] row at `74%` with the stale summary. This is not editable by B003 during report-only research or implementation callback unless a supervisor explicitly owns that update. Normal validator implementation may need this row corrected first, or the target metadata/C++ can be restored to stale generated defaults.

## Live MCP Provenance

IDA MCP was available and responsive. Current session:

- Session/database id: `80de0a67`
- `server_health` command id `34`: status `ok`, module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, auto analysis ready, Hex-Rays ready, strings cache ready.
- Earlier session enumeration during this assignment reported the same active session id `80de0a67`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, and `is_analyzing:false`.

MCP commands used for this report:

- `lookup_funcs` id `5`
- `entity_query` id `6`
- `analyze_component` id `13`
- `get_bytes` id `15`
- `analyze_function` ids `16` through `23`
- `xrefs_to` id `24`
- `analyze_function` dependency refresh ids `35`, `36`, `37`
- `list_globals` id `38`
- `xrefs_to` function-entry refresh id `39`
- `get_bytes` entry-byte refresh id `40`

## Boundary Evidence

Live MCP `lookup_funcs` id `5` confirms the exact target function inventory:

| Function | IDA name | Size | Decimal size | Role |
| --- | --- | ---: | ---: | --- |
| `0x005832f0-0x00583392` | `sub_5832F0` | `0xa2` | 162 | ANSI release helper |
| `0x005833a0-0x00583442` | `sub_5833A0` | `0xa2` | 162 | wide release helper |
| `0x00583450-0x00583456` | `sub_583450` | `0x6` | 6 | buffer-header accessor |
| `0x00583460-0x005834b7` | `sub_583460` | `0x57` | 87 | wide copy/share helper |
| `0x005834c0-0x005835b3` | `sub_5834C0` | `0xf3` | 243 | ANSI set-length and detach helper |
| `0x005835c0-0x00583660` | `sub_5835C0` | `0xa0` | 160 | wide set-length and detach helper |
| `0x00583660-0x005836f7` | `sub_583660` | `0x97` | 151 | wide make-exclusive helper |
| `0x00583700-0x00583714` | `sub_583700` | `0x14` | 20 | wide varargs forwarder to [UID:0002LM] |

`lookup_funcs` also confirms no modeled function at the internal padding starts `0x005832e3`, `0x00583392`, `0x00583442`, `0x00583456`, `0x005834b7`, `0x005835b3`, `0x005836f7`, or at the target end `0x00583714`; successor `0x00583720` starts [UID:0002LL] `StringBaseAnsiVFormatWorker`.

`entity_query` id `6` over `0x005832f0-0x00583720` returns the eight target starts plus successor `0x00583720`, confirming the half-open target end at `0x00583714` followed by padding and the next real worker at `0x00583720`.

`get_bytes` id `15` confirms boundary padding:

- `0x005832e3-0x005832f0`: thirteen `0xcc` bytes before the target.
- `0x00583392-0x005833a0`: fourteen `0xcc` bytes.
- `0x00583442-0x00583450`: fourteen `0xcc` bytes.
- `0x00583456-0x00583460`: ten `0xcc` bytes.
- `0x005834b7-0x005834c0`: nine `0xcc` bytes.
- `0x005835b3-0x005835c0`: thirteen `0xcc` bytes.
- `0x005836f7-0x00583700`: nine `0xcc` bytes.
- `0x00583714-0x00583720`: twelve `0xcc` bytes before successor `0x00583720`.

`get_bytes` id `40` confirms representative entry bytes:

- `0x005832f0`: `56 8b f1 8b 06 39 05 90 02 67 00 0f 84 8f 00 00`, which compares the current ANSI data pointer against the ANSI empty sentinel `0x00670290`.
- `0x005833a0`: `56 8b f1 8b 06 39 05 78 02 67 00 0f 84 8f 00 00`, which compares the current wide data pointer against the wide empty sentinel `0x00670278`.
- `0x00583700`: `55 8b ec 8b 4d 08 8d 45 10 50 ff 75 0c e8 2e 01 00 00 5d c3`, a tiny varargs setup and call to `0x00583840`.

## Behavior Evidence

`analyze_component` id `13` over the eight target starts reports all eight as interface functions and records three internal edges:

- `0x005834c0 -> 0x005832f0`
- `0x005835c0 -> 0x005833a0`
- `0x00583660 -> 0x005833a0`

Shared globals in that component are the wide sentinel `0x00670278` (`Src`), the ANSI sentinel `0x00670290` (`off_670290`), and the security cookie `0x00672f24`. The security-cookie references occur in stack-protected detach/set-length helpers and should be documented as compiler frame protection, not source logic.

Per-function evidence:

- `0x005832f0` / `ReleaseAnsiBuffer`: `analyze_function` id `16` compares `*this` to `0x00670290`; if non-sentinel, it decrements the refcount at `data - 0x0c` with `InterlockedDecrement`. When the count reaches zero, it selects pool return by `capacity` at `data - 0x04`: 64 -> `0x0069bb6c`, 128 -> `0x0069bb94`, 256 -> `0x0069bbbc`, 512 -> `0x0069bbe4`, otherwise heap-frees the 12-byte header pointer. It resets `*this` to the ANSI empty sentinel.
- `0x005833a0` / `ReleaseWideBuffer`: `analyze_function` id `17` mirrors the ANSI release path for wide storage. It ignores the wide sentinel `0x00670278`, decrements `data - 0x0c`, returns capacities 64/128/256/512 to `0x0069bacc`, `0x0069baf4`, `0x0069bb1c`, and `0x0069bb44`, otherwise heap-frees, and resets `*this` to the wide empty sentinel.
- `0x00583450` / `GetBufferHeader`: `analyze_function` id `18` is a six-byte `thiscall` helper returning `*this - 12`. It is the source-level accessor for [UID:0001VQ] `RefCountedStringBufferHeader`, not an independent algorithm.
- `0x00583460` / `CopyOrShareWide`: `analyze_function` id `19` starts from the wide sentinel, reads the source data pointer, and if the source refcount is non-negative it shares that source, incrementing the refcount for non-empty sources. If the source refcount is negative/non-shareable and the source is not the wide sentinel, it ensures destination wide capacity through `0x00584ba0` and copies `2 * sourceLength` bytes with `memmove`.
- `0x005834c0` / `SetLengthAnsiAndDetach`: `analyze_function` id `20` handles ANSI length/capacity and copy-on-write. If the requested length exceeds capacity, it preserves the old pointer in a stack temporary, allocates through `0x00582d80` for `max(requestedLength, oldLength)`, copies old bytes, NUL terminates, restores length, and releases the temporary through `0x005832f0`. It then writes the requested terminator/length. If the buffer is shared (`refCount > 1`), it allocates a private same-length ANSI buffer, copies, releases the old buffer, and marks the resulting buffer non-shareable with refcount `-1`.
- `0x005835c0` / `SetLengthWideAndDetach`: `analyze_function` id `21` does the wide equivalent. It ensures capacity through `0x00584ba0`, writes a UTF-16 terminator and length, detaches if shared by allocating through `0x00582e30`, copies `2 * length` bytes, releases through `0x005833a0`, and marks the resulting buffer refcount `-1`.
- `0x00583660` / `MakeExclusiveWide`: `analyze_function` id `22` checks `refCount <= 1`; if already unshared, it marks the current wide buffer `-1`. If shared, it allocates a same-length wide buffer through `0x00582e30`, copies `2 * length` bytes, releases the old buffer through `0x005833a0`, and marks the new buffer `-1`.
- `0x00583700` / `FormatWide`: `analyze_function` id `23` is a 20-byte varargs forwarder. It starts a `va_list` at the first vararg and forwards `(this, format, va_list)` to [UID:0002LM] `0x00583840` / `StringBaseWideVFormatWorker`.

Dependency helpers rechecked:

- `0x00584ba0` (`analyze_function` id `35`) is the wide ensure-capacity helper. It only grows when requested capacity is greater than `data[-1]`, allocates through `0x00582e30`, copies `2 * oldLength`, writes a terminator and old length, and releases the old pointer through `0x005833a0`.
- `0x00582d80` (`analyze_function` id `36`) is ANSI allocation. Empty length stores `0x00670290`. Non-empty allocation chooses ANSI pools for thresholds 64/128/256/512 or heap-allocates `requested + 13`, writes `refCount=1`, NUL terminator, length, capacity, and stores `header + 0x0c` in the receiver.
- `0x00582e30` (`analyze_function` id `37`) is wide allocation. Empty length stores `0x00670278`. Non-empty allocation chooses wide pools for thresholds 64/128/256/512 or heap-allocates `2 * requested + 14`, writes `refCount=1`, NUL terminator, length, capacity, and stores `header + 0x0c`.

Function-entry xrefs from MCP id `39`:

- `0x005832f0`: 12 xrefs, including release wrappers, ANSI assignment/grow/detach, ANSI set-length, ANSI vformat, and ANSI capacity helper consumers.
- `0x005833a0`: 23 xrefs, including wide release wrappers, wide assignment/grow/detach, target internal helpers, wide vformat, replace/trim helpers, and ensure-wide-capacity cleanup.
- `0x00583450`: 65 xrefs, a broad header-accessor fan-out. This supports a common source-facing `GetBufferHeader`/header-prefix helper rather than a target-local one-off.
- `0x00583460`: 3 xrefs, from wide replace and substring-related helpers.
- `0x005834c0`: 1 xref, from `0x004b12a0` virtual readable/string helper consumer.
- `0x005835c0`: 3 xrefs, from UI/consumer helpers at `0x004f95b0` and `0x0058e3e0`.
- `0x00583660`: 1 xref, from `0x005063e0`.
- `0x00583700`: 7 xrefs, from `0x004f95b0`, `0x005063e0`, and `0x0050aba0`, all consumers of wide varargs formatting.

## Sentinel, Pool, And Header Evidence

`xrefs_to` id `24` confirms the sentinel and pool model used by this target:

- `0x00670278` wide empty sentinel: 23 direct refs. Relevant target refs include release entry comparison and reset stores in `0x005833a0`, copy/share initialization in `0x00583460`, wide set-length handling in `0x005835c0`, and wide vformat comparison in `0x00583840`.
- `0x00670290` ANSI empty sentinel: 16 direct refs. Relevant target refs include release entry comparison and reset stores in `0x005832f0`, ANSI set-length handling in `0x005834c0`, and ANSI vformat comparison in `0x00583720`.
- Each of the eight pool globals has exactly four refs: one static constructor, one allocator use, one release use, and one cleanup wrapper.

Pool mapping:

- Wide 64/128/256/512: `0x0069bacc`, `0x0069baf4`, `0x0069bb1c`, `0x0069bb44`; allocation through `0x00582e30`, release through `0x005833a0`.
- ANSI 64/128/256/512: `0x0069bb6c`, `0x0069bb94`, `0x0069bbbc`, `0x0069bbe4`; allocation through `0x00582d80`, release through `0x005832f0`.

[UID:0001VQ] `RefCountedStringBufferHeader` remains the correct source-facing field model:

- data-relative `-0x0c`: `refCount`
- data-relative `-0x08`: `length`
- data-relative `-0x04`: `capacity`
- data-relative `0x00`: character data

The target strengthens this support page because all eight in-range helpers read or write these three header fields directly or through the six-byte header accessor.

`int_convert.py` verification used for sizes and constants:

- `0xa2` = 162
- `0x57` = 87
- `0xf3` = 243
- `0xa0` = 160
- `0x97` = 151
- `0x14` = 20
- capacity constants 64/128/256/512 correspond to `0x40`/`0x80`/`0x100`/`0x200`

## Owner And Emitter Reanalysis

The old A003 implementation retained [UID:0000OA] `StringBase` as the target's direct owner/emitter. That was valid enough to escape low-completion status, but current support docs and sibling behavior make the type/template page [UID:0001WS] the better direct route.

Evidence for [UID:0001WS] as direct owner/emitter:

- [UID:0001WS] records preserved compiler metadata for `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>`.
- MCP `list_globals` id `38` currently returns `*StringBase*` / `*mystr*` vtables and RTTI entries, including `0x0061fcd4`, `0x0061fcec`, `0x0061ff70`, `0x0062004c`, `0x00620094`, `0x00622cf4`, and RTTI records beginning at `0x0064c610`.
- The target's receiver is the `StringBase` data pointer and its 12-byte header; `0x00583450` has 65 current xrefs as a common type helper.
- [UID:0002RO] `StringBaseAllocationGrowAndCow`, [UID:0002LL] `StringBaseAnsiVFormatWorker`, and [UID:0002LM] `StringBaseWideVFormatWorker` already route through [UID:0001WS] for the same template/type-family reason.
- [UID:0001WS] itself emits through [UID:0000OA] `StringBase`, keeping the actual generated source root `NexusTK/util/StringBase.cpp`.

Rejected direct owners:

- [UID:0000OA] as direct child owner only: still the source-file root, but too coarse for this target after sibling pages moved comparable helper groups to [UID:0001WS].
- [UID:0001J3] `StringBaseReleaseFormatAndMutation`: non-emitting aggregate/container; it should map children and not own emitted source.
- [UID:0001J2] `StringBaseFormatConstructors`: non-emitting constructor aggregate ending before `0x005832f0`.
- [UID:0000OB] `StringUtil`: broad utility-string coordinator, not the direct ref-counted pointer-backed buffer implementation.
- [UID:0000D9] `SimpleUString`: possible public facade/typedef context, but current compiler metadata and helper family point to `mystr::StringBase`.
- [UID:0000KV] `LObject`: stale generated/recovery pollution. The true `LObject` shell is separate from the `0x00582500+` string-buffer family.
- [UID:0000MM] `PoolAllocator`: owns allocator mechanics, not string-specific helper source logic or string pool declarations.
- Caller modules such as File, UI dialogs, LanguageMan, Application, and packet/UI helpers: consumers only.

## Source-Facing Names

Apply these names or document why a placeholder must remain:

| Address | Preferred source-facing name | Notes |
| --- | --- | --- |
| `0x005832f0` | `ReleaseAnsiBuffer` | Replaces `sub_5832F0`; releases ANSI data to sentinel/pool/heap. |
| `0x005833a0` | `ReleaseWideBuffer` | Replaces `sub_5833A0`; releases wide data to sentinel/pool/heap. |
| `0x00583450` | `GetBufferHeader` | Replaces `sub_583450`; source-level header accessor for `m_data - 0x0c`. |
| `0x00583460` | `CopyOrShareWide` | Replaces `sub_583460`; shares positive-refcount wide storage or copies non-shareable storage. |
| `0x005834c0` | `SetLengthAnsiAndDetach` | Replaces `sub_5834C0`; ANSI length/capacity update and COW detach. |
| `0x005835c0` | `SetLengthWideAndDetach` | Replaces `sub_5835C0`; wide length/capacity update and COW detach. |
| `0x00583660` | `MakeExclusiveWide` | Replaces `sub_583660`; marks wide storage unique or copies from shared storage. |
| `0x00583700` | `FormatWide` | Replaces `sub_583700`; thin varargs wrapper to `WideVFormat` at [UID:0002LM]. |

Support names:

- `AllocateAnsiBuffer` for `0x00582d80`
- `AllocateWideBuffer` for `0x00582e30`
- `EnsureWideCapacity` for `0x00584ba0`
- `WideVFormat` for `0x00583840`
- `g_emptyAnsiString` / `g_emptyWideString`
- `g_ansiPool64/128/256/512`
- `g_widePool64/128/256/512`
- `RefCountedStringBufferHeader`

Raw `sub_`, `off_`, and `unk_` names may remain only in MCP evidence/provenance text or when quoting current IDA names. Source-facing prose should use the names above.

## Formal C++ Recommendation

The target is eligible for first-draft C++ because it is reconstructable, has a nonblank emitter route through [UID:0001WS] to [UID:0000OA], clears the current code-entry gate after this report's score recommendation, and the current blockers are source-name/API caveats rather than unknown control flow. This is not final audited source; it is the best-supported first draft.

Populate the target formal block with the following exact insertion text:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace mystr {

namespace {

static RefCountedStringBufferHeader *HeaderFromData(void *data)
{
    return reinterpret_cast<RefCountedStringBufferHeader *>(
        static_cast<char *>(data) - sizeof(RefCountedStringBufferHeader));
}

static const RefCountedStringBufferHeader *HeaderFromData(const void *data)
{
    return reinterpret_cast<const RefCountedStringBufferHeader *>(
        static_cast<const char *>(data) - sizeof(RefCountedStringBufferHeader));
}

static void ReturnAnsiHeader(RefCountedStringBufferHeader *header)
{
    switch (header->capacity) {
    case 64:
        g_ansiPool64.Free(header);
        break;
    case 128:
        g_ansiPool128.Free(header);
        break;
    case 256:
        g_ansiPool256.Free(header);
        break;
    case 512:
        g_ansiPool512.Free(header);
        break;
    default:
        free(header);
        break;
    }
}

static void ReturnWideHeader(RefCountedStringBufferHeader *header)
{
    switch (header->capacity) {
    case 64:
        g_widePool64.Free(header);
        break;
    case 128:
        g_widePool128.Free(header);
        break;
    case 256:
        g_widePool256.Free(header);
        break;
    case 512:
        g_widePool512.Free(header);
        break;
    default:
        free(header);
        break;
    }
}

} // namespace

template <>
void StringBase<char, mychar_traits<char> >::ReleaseAnsiBuffer()
{
    char *data = m_data;
    if (data != g_emptyAnsiString) {
        RefCountedStringBufferHeader *header = HeaderFromData(data);
        if (InterlockedDecrement(&header->refCount) <= 0) {
            ReturnAnsiHeader(header);
        }
    }

    m_data = g_emptyAnsiString;
}

template <>
void StringBase<wchar_t, mychar_traits<wchar_t> >::ReleaseWideBuffer()
{
    wchar_t *data = m_data;
    if (data != g_emptyWideString) {
        RefCountedStringBufferHeader *header = HeaderFromData(data);
        if (InterlockedDecrement(&header->refCount) <= 0) {
            ReturnWideHeader(header);
        }
    }

    m_data = g_emptyWideString;
}

template <class CharT, class Traits>
RefCountedStringBufferHeader *
StringBase<CharT, Traits>::GetBufferHeader() const
{
    return HeaderFromData(m_data);
}

template <>
void StringBase<wchar_t, mychar_traits<wchar_t> >::CopyOrShareWide(
    const StringBase<wchar_t, mychar_traits<wchar_t> > &source)
{
    wchar_t *sourceData = source.m_data;
    const RefCountedStringBufferHeader *sourceHeader = HeaderFromData(sourceData);

    if (sourceHeader->refCount >= 0) {
        if (sourceData != g_emptyWideString) {
            InterlockedIncrement(
                const_cast<LONG *>(&sourceHeader->refCount));
        }
        m_data = sourceData;
        return;
    }

    m_data = g_emptyWideString;
    if (sourceData != g_emptyWideString) {
        EnsureWideCapacity(sourceHeader->length);
        memmove(m_data, sourceData, sourceHeader->length * sizeof(wchar_t));
    }
}

template <>
char *StringBase<char, mychar_traits<char> >::SetLengthAnsiAndDetach(
    unsigned int length)
{
    if (length == 0 && m_data == g_emptyAnsiString) {
        return m_data;
    }

    RefCountedStringBufferHeader *header = HeaderFromData(m_data);
    if (length > header->capacity) {
        char *oldData = m_data;
        unsigned int oldLength = header->length;
        unsigned int preserveLength = oldLength;
        if (preserveLength < length) {
            preserveLength = length;
        }

        AllocateAnsiBuffer(preserveLength);
        memmove(m_data, oldData, oldLength);
        m_data[oldLength] = '\0';
        HeaderFromData(m_data)->length = oldLength;

        StringBase<char, mychar_traits<char> > oldString;
        oldString.m_data = oldData;
        oldString.ReleaseAnsiBuffer();
        header = HeaderFromData(m_data);
    }

    m_data[length] = '\0';
    header->length = length;

    if (header->refCount > 1) {
        char *oldData = m_data;
        unsigned int copyLength = header->length;
        AllocateAnsiBuffer(copyLength);
        memmove(m_data, oldData, copyLength);

        StringBase<char, mychar_traits<char> > oldString;
        oldString.m_data = oldData;
        oldString.ReleaseAnsiBuffer();
        header = HeaderFromData(m_data);
    }

    header->refCount = -1;
    return m_data;
}

template <>
wchar_t *StringBase<wchar_t, mychar_traits<wchar_t> >::SetLengthWideAndDetach(
    unsigned int length)
{
    if (length == 0 && m_data == g_emptyWideString) {
        return m_data;
    }

    EnsureWideCapacity(length);
    m_data[length] = L'\0';

    RefCountedStringBufferHeader *header = HeaderFromData(m_data);
    header->length = length;

    if (header->refCount > 1) {
        wchar_t *oldData = m_data;
        unsigned int copyLength = header->length;
        AllocateWideBuffer(copyLength);
        memmove(m_data, oldData, copyLength * sizeof(wchar_t));

        StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
        oldString.m_data = oldData;
        oldString.ReleaseWideBuffer();
        header = HeaderFromData(m_data);
    }

    header->refCount = -1;
    return m_data;
}

template <>
wchar_t *StringBase<wchar_t, mychar_traits<wchar_t> >::MakeExclusiveWide()
{
    RefCountedStringBufferHeader *header = HeaderFromData(m_data);
    if (header->refCount <= 1) {
        header->refCount = -1;
        return m_data;
    }

    wchar_t *oldData = m_data;
    unsigned int length = header->length;
    AllocateWideBuffer(length);
    memmove(m_data, oldData, length * sizeof(wchar_t));

    StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
    oldString.m_data = oldData;
    oldString.ReleaseWideBuffer();

    HeaderFromData(m_data)->refCount = -1;
    return m_data;
}

template <>
int StringBase<wchar_t, mychar_traits<wchar_t> >::FormatWide(
    const wchar_t *format, ...)
{
    va_list args;
    va_start(args, format);
    int result = WideVFormat(format, args);
    va_end(args);
    return result;
}

} // namespace mystr
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

C++ caveats:

- The body is first-draft reconstruction. It captures the control flow, data flow, sentinel/pool behavior, refcount semantics, detach policy, and wide varargs forwarding. It does not prove the exact original public method names.
- `PoolAllocator::Free`, `AllocateAnsiBuffer`, `AllocateWideBuffer`, `EnsureWideCapacity`, and `WideVFormat` are source-facing names inferred from current support docs and direct MCP behavior. If implementation cannot bind those exact helper names locally, the target doc should state the applied replacement and why.
- `va_end` is present in source form even though x86/MSVC emits no substantive work for this call shape.

## Score Rationale

Recommended `91/92`:

- Completion rises because all in-range function boundaries, padding spans, exact helper roles, internal edges, sentinel/pool/header data flow, and source route are now rechecked against live session `80de0a67`.
- Completion rises above the first-draft code gate because the target no longer has unresolved behavior or owner blockers. Remaining caveats are final API spelling and support declaration polish, not missing target logic.
- Confidence rises because MCP decompilation, component analysis, xrefs, bytes, dependency helper analysis, and current compiler metadata all converge on the same StringBase template/source route.
- Score stays below final audit because exact original method spelling, exact public/private header/API split, exact pool/global public symbol names, and the `StringBase` vs `SimpleUString` facade relationship remain support-level caveats.

Do not raise this target to `95+` without a full string-family API audit and final declaration proof.

## Target Documentation Implementation Requirements

When supervisor accepts this report, update `by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md` with report-level detail:

- Set metadata to `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:0001WS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001WS`, blank `EMITTER_POSITION_OPTIONAL`.
- Replace the Item Summary with the recommended exact summary above.
- Replace stale "below 95%" / blank-C++ reasoning with the current gate result and the formal C++ block above.
- Replace raw placeholder names in prose with the source-facing names listed above; keep raw `sub_` names only in evidence tables or MCP provenance.
- Document live MCP session `80de0a67` with command ids and evidence categories from this report.
- Document exact flag/security-cookie correction: the cookie in set-length helpers is compiler frame protection and should not become source logic.
- Document the target as a method/helper group under [UID:0001WS] that surfaces through [UID:0000OA] `StringBase.cpp`.
- Preserve unresolved caveats: exact original method spelling is not source-file proven; exact public header/API shape remains unresolved; exact sentinel/pool public names remain support-level; relationship to `SimpleUString` remains a facade/typedef caveat.

## Support Documentation Implementation Requirements

Recommended support docs to update if this report is accepted:

1. `by-type/by-template/StringBaseTemplate.md`
   - Add [UID:0002RT] as a direct StringBaseTemplate helper group.
   - Record the live `80de0a67` target evidence and the reason [UID:0002RT] now routes through the template/type page, matching [UID:0002RO], [UID:0002LL], and [UID:0002LM].
   - Keep the template page formal C++ blank because the full template declaration and public API split remain unresolved.

2. `by-file/StringBase.md`
   - Add [UID:0002RT] to the Likely Contents table as the release/capacity/detach helper group now emitting first-draft source through [UID:0001WS].
   - Note generated output should appear in `auto-generated/NexusTK/util/StringBase.cpp` because [UID:0001WS] emits through [UID:0000OA].
   - Preserve the `StringBase.cpp` vs `StringUtil.cpp`/header spelling caveat.

3. `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md`
   - Update the child row/status for [UID:0002RT] from file-only owner and blank-C++/final-gate wording to template-owner and first-draft target C++.
   - Keep the aggregate non-emitting with `CANONICAL_OWNER:NONE` and `RECONSTRUCTABLE:FALSE`.

4. `by-type/by-struct/RefCountedStringBufferHeader.md`
   - Add current [UID:0002RT] evidence that `0x00583450` returns `data - 0x0c`, release helpers decrement `refCount`, set-length/make-exclusive write `refCount=-1`, and length/capacity fields drive allocation/detach.
   - Preserve the negative/non-shareable static interpretation for negative refcounts.

5. `by-global/StringBufferSentinelsAndPools.md`
   - Add current session `80de0a67` target evidence for release/allocate use of `0x00670278`, `0x00670290`, and the eight 64/128/256/512 pool globals.
   - Preserve direct ownership under [UID:0000OA] for global declarations and allocator-mechanics ownership under [UID:0000MM].

Checked support docs with no required edit unless supervisor expands scope:

- [UID:0002RO] `StringBaseAllocationGrowAndCow` already routes through [UID:0001WS] and documents allocation dependencies used by this target.
- [UID:0002LL] and [UID:0002LM] already route through [UID:0001WS]. Their old "95+ gate" wording is stale but not a direct contradiction to this target because they remain only `85/90` and can keep blank C++ for their own score/API reasons.
- [UID:0002RN] and [UID:0002RQ] remain file-owned in current docs. This report does not require rerouting them, but future string-family cleanup may consider whether similar template/type routing should be applied.

## Rejected Alternatives And Negative Evidence

- Do not classify the target as a non-emitting aggregate. The eight functions are modeled exact source-bearing helpers, not a broad container.
- Do not keep [UID:0001J3] or [UID:0001J2] as direct emitters. Both are non-emitting aggregate maps.
- Do not leave first-draft C++ blank solely because the target is below a historic 95+ threshold. The current blockers were investigated; target behavior and route are now sufficiently resolved for first-draft C++.
- Do not rename this as `LObject` code. The receiver is a string data pointer with a 12-byte ref-counted header, not an `LObject` vtable object.
- Do not make `PoolAllocator` the owner. The target calls allocator mechanics and string pools, but source logic is the StringBase buffer core.
- Do not promote caller modules as owners. File, UI, Application, LanguageMan, and packet/UI helpers consume these helpers; they do not define them.
- Do not turn security-cookie artifacts into source logic.
- Do not collapse ANSI and wide sentinels or pools. They are separate globals and separate alloc/release paths.
- Do not infer that negative refcount means a leaked/shared object. Current target behavior uses negative refcount as non-shareable/exclusive/static-private state.

## Validator And Generated-State Risk

No validators were run in this report-only pass.

Implementation validator commands to run after accepted edits:

- `python .\tools\validator.py --mode file --file by-memory\0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md --apply --queue-timeout 240 --wait-generated`
- Same scoped file-validator pattern for every changed support doc.

Implementation callback status: supervisor corrected the manual `by-memory/-coverage-report.md` row before callback and validated it with command `000000000897` at `2026-06-25T01:49:14-04:00`, exit `0`, `ok:1`. B003 did not edit coverage reports or validator state. Normal target validator command `000000000914` at `2026-06-25T01:58:21-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`, preserved accepted `91/92` metadata and emitted C++ body, but re-read found the target Item Summary reverted to the shorter manual/default text. B003 reapplied the accepted Item Summary under a fresh target-only lease and reran the normal target validator as command `000000000919` at `2026-06-25T02:01:19-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`; re-read again showed the Item Summary reverted to `ANSI/wide release, copy-init, capacity, and detach helpers with sentinel/pool evidence.` Supervisor then restored the accepted source Item Summary and validated the source page with narrow UID-only command `000000000935` at `2026-06-25T02:06:53-04:00`, exit `0`, `ok:1`, `generated_refresh: skipped`, `generated_refresh_detail: disabled by --uid-only`. B003 final readback confirms the source target now has accepted `91/92`, owner/emitter [UID:0001WS], accepted long Item Summary, and first-draft formal C++; generated `auto-generated/NexusTK/util/StringBase.cpp` still contains the emitted [UID:0002RT] code from prior validation. Normal generated refresh was intentionally not rerun because it is the known source of stale coverage wording.

After successful implementation validation, re-read:

- target by-memory header and formal C++ block
- `auto-generated/NexusTK/util/StringBase.cpp`
- generated tracker/coverage rows if the validator reports generated refresh

Expected generated result: [UID:0002RT] no longer appears as an empty emitter marker and the emitted first-draft block is present under `NexusTK/util/StringBase.cpp`.

## Implementation Tracking Checklist For Callback

- [x] Target `by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md`: metadata updated to `91/92`, owner/emitter route changed to [UID:0001WS], reconstructable true preserved, blank optional position preserved. Proof: target header re-read after command `000000000914` shows `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:0001WS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001WS`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Target Item Summary replaced exactly with the recommended summary. Proof: supervisor restored the accepted source Item Summary and validated it with UID-only command `000000000935` at `2026-06-25T02:06:53-04:00`, exit `0`, `ok:1`, `generated_refresh: skipped`; B003 final source readback confirms the exact long StringBaseTemplate release/capacity helper-group summary is present.
- [x] Target prose updated with current MCP session `80de0a67` evidence: boundary/bytes, lookup/function inventory, component analysis, decompile behavior, entry xrefs, sentinel/pool xrefs, dependency helper analysis, compiler metadata, and int conversions. Proof: target sections `Current IDA MCP Evidence`, `Behavior Evidence`, `Dependency Evidence`, `Sentinel, Pool, And Header Model`, and `Covered Range` contain the session and command-id evidence.
- [x] Target stale blank-C++/95-gate wording removed or rewritten to the current first-draft code-entry rule. Proof: target `C++ Reconstruction Rationale` states the current reconstructable/nonblank-emitter/average-score gate and removes the blank-emitter gate.
- [x] Target formal `RECONSTRUCTION_CPP CODE` populated with the exact block from this report. Proof: target formal block re-read after validation contains `ReleaseAnsiBuffer`, `ReleaseWideBuffer`, `GetBufferHeader`, `CopyOrShareWide`, `SetLengthAnsiAndDetach`, `SetLengthWideAndDetach`, `MakeExclusiveWide`, and `FormatWide`.
- [x] Target source-facing names applied or every remaining placeholder name justified as raw evidence only. Proof: formal C++ uses source-facing names; raw `sub_`, `off_`, and `unk_` labels are confined to evidence/provenance text.
- [x] Target negative evidence/rejected alternatives incorporated: reject LObject, StringUtil direct owner, PoolAllocator owner, caller-module owners, aggregate/non-emitter classification, security-cookie source logic, and collapsed sentinel/pool interpretations. Proof: target `Rejected Alternatives And Negative Evidence` records each rejected owner/interpretation and the security-cookie caveat.
- [x] `by-type/by-template/StringBaseTemplate.md` synchronized with [UID:0002RT] as a direct template/type helper group and target-specific first-draft C++ route; formal template C++ remains blank. Proof: `Direct Helper Groups` row for [UID:0002RT] and updated rebuild notes; validator `000000000908` at `2026-06-25T01:57:41-04:00`, exit `0`, `ok:1`, `generated_refresh: deferred`.
- [x] `by-file/StringBase.md` synchronized with [UID:0002RT] as a first-draft-emitting StringBaseTemplate helper group that surfaces through `NexusTK/util/StringBase.cpp`; source/header caveats preserved. Proof: likely-contents/evidence/cross-reference text updated; validator `000000000909` at `2026-06-25T01:57:48-04:00`, exit `0`, `ok:1`, `generated_refresh: deferred`.
- [x] `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md` child row/status synchronized while aggregate remains non-emitting. Proof: child split and ownership notes now route [UID:0002RT] directly to [UID:0001WS] while retaining aggregate non-emitter status; validator `000000000910` at `2026-06-25T01:57:53-04:00`, exit `0`, `ok:1`, `generated_refresh: deferred`.
- [x] `by-type/by-struct/RefCountedStringBufferHeader.md` updated with current [UID:0002RT] header/refcount/length/capacity evidence if accepted in callback scope. Proof: IDA verification notes now cite [UID:0002RT] header-from-data, refcount, length, capacity, and `-1` private-state behavior; validator `000000000912` at `2026-06-25T01:58:06-04:00`, exit `0`, `ok:1`, `generated_refresh: deferred`.
- [x] `by-global/StringBufferSentinelsAndPools.md` updated with current [UID:0002RT] sentinel/pool evidence if accepted in callback scope. Proof: evidence notes now cite ANSI/wide sentinel addresses, pool addresses, xref counts, and release-path behavior; validator `000000000913` at `2026-06-25T01:58:13-04:00`, exit `0`, `ok:1`, `generated_refresh: deferred`.
- [x] Checked [UID:0002RO], [UID:0002LL], [UID:0002LM], [UID:0002RN], and [UID:0002RQ] for contradictions; edit only if callback scope explicitly includes them or a direct contradiction is introduced. Proof: checked `StringBaseAllocationGrowAndCow`, ANSI/wide vformat workers, share/access, and replace/trim docs before editing; no direct contradictions required out-of-scope edits.
- [x] Scoped validators run for every changed by-* file from `E:\NTK\GhidraBridge\source-3\project-documentation`; record exact command, command id, timestamp, exit code, ok count, and generated-refresh state. Proof: support validators `000000000908`, `000000000909`, `000000000910`, `000000000912`, `000000000913` all exited `0` with `ok:1`; target validator `python .\tools\validator.py --mode file --file by-memory\0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md --apply --queue-timeout 240 --wait-generated`, command `000000000914`, timestamp `2026-06-25T01:58:21-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`; retry after accepted-summary reapply, same command pattern, command `000000000919`, timestamp `2026-06-25T02:01:19-04:00`, exit `0`, `ok:1`, `generated_refresh: completed`.
- [x] Re-read target and `auto-generated/NexusTK/util/StringBase.cpp` after validation to confirm metadata, summary, formal C++ body, owner/emitter route, and generated output survived. Proof: after supervisor UID-only command `000000000935`, B003 final source readback confirms `COMPLETION:91`, `CONFIDENCE:92`, `CANONICAL_OWNER:0001WS`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001WS`, blank optional position, accepted long Item Summary, and formal C++ methods `ReleaseAnsiBuffer`, `ReleaseWideBuffer`, `GetBufferHeader`, `CopyOrShareWide`, `SetLengthAnsiAndDetach`, `SetLengthWideAndDetach`, `MakeExclusiveWide`, and `FormatWide`; generated `auto-generated/NexusTK/util/StringBase.cpp` readback confirms `// UID:0002RT ... Completion:91 | Confidence:92` and the emitted method set remains present.
- [x] If normal validator path reverts to stale `74/84` or empty marker due manual coverage/default row, return `PAUSED_VALIDATOR_METADATA_CONFLICT` instead of using `--uid-only` or manually editing coverage rows. Proof: normal validator path did not revert to `74/84` or empty marker after supervisor command `000000000897`, but it did revert the accepted Item Summary on command `000000000919`; B003 reported `PAUSED_VALIDATOR_METADATA_CONFLICT`, the supervisor resolved the source-page summary with UID-only command `000000000935`, and B003 did not run the normal target validator again or edit coverage/validator state.
- [x] Leases released or expired after the edit/validator batch. Proof: B003 leased the six edited by-* files, `unlease` later reported `Rejected[No active lease]` for all six after validation, then B003 took a fresh target-only lease for the summary retry and released it successfully after command `000000000919`.

## Report-Only Compliance

- No leases taken.
- No by-* target/support docs edited.
- No generated files edited.
- No project-level files edited.
- No coverage reports edited.
- No validator state/cache edited.
- No IDA DB edits made.
- No subagents spawned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002RT-StringBaseReleaseAndCapacity-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002RT-StringBaseReleaseAndCapacity-source-quality.md","timestamp":"2026-06-25T02:09:15","uid":"0002RT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
