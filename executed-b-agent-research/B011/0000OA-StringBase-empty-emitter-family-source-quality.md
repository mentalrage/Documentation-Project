** TARGET-REPORT-UID:0000OA **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B011 Report: UID 0000OA StringBase Empty-Emitter Family Source-Quality Audit

## Assignment

- Agent: B011
- Assignment: report-only research for `[UID:0000OA] by-file/StringBase.md`
- Queue family: Files With Empty Emitters
- Target by-* doc: `by-file/StringBase.md`
- Generated output under review: `auto-generated/NexusTK/util/StringBase.cpp`
- Report path: `tools/leaser/Agents/Agent-B011/research/0000OA-StringBase-empty-emitter-family-source-quality.md`
- Report-only constraints honored: no by-* edits, no generated edits, no coverage/report-state edits, no leases, no validators, no subagents.

## Executive Recommendation

`[UID:0000OA] StringBase` is implementation-ready after this pass.

The empty-emitter family is not a no-owner/no-code family. Current generated output contains fifteen empty marker blocks, but current docs, generated routing, prior executed child reports, and current IDA MCP evidence support converting nearly all of them into exact or near-exact first-draft source. The recommended implementation is:

- Raise target file confidence to `COMPLETION:91` and `CONFIDENCE:90`.
- Preserve target ownership as `CANONICAL_OWNER:FILE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`.
- Add formal source bodies or declarations for StringBase sentinels, ref-counted header layout, suffix checks, format constructors/workers, wide range comparison, wide literal comparison, wide search helpers, wide splice/grow/substring helpers, and the byte-range comparator support dependency.
- Keep only layout/type aggregate pages as explicit no-standalone-code marker comments where the exact source is already represented by more precise children and a declaration shell would invent unresolved public API shape.
- Refresh support aggregates so the implementation does not leave stale "below threshold" or "blank pending reconciliation" claims after accepted bodies are inserted.

Implementation should be applied at report-level detail, not as a short summary. The current empty markers are close enough to source behavior that generic "unknown API/name" comments would lose useful recoverable behavior.

## Current Generated State

Current generated file header in `auto-generated/NexusTK/util/StringBase.cpp`:

- `validator-command-id: 000000002660`
- `validator-refreshed-at: 2026-06-30T07:03:51-04:00`
- Source by-file UID: `0000OA`

The generated file has 24 total emitters for `StringBase`, with 15 empty markers. The project tracker row currently reports:

`[UID:0000OA] StringBase | 24 | 9 | 15 | 37.5% | auto-generated/NexusTK/util/StringBase.cpp | by-file/StringBase.md`

The empty markers found in generated output are:

| UID | Target page | Current generated disposition | Recommended disposition |
|---|---|---:|---|
| `0000TM` | `by-global/StringBufferSentinelsAndPools.md` | empty marker | formal global data/storage declarations |
| `0002AN` | `by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md` | empty marker | marker comment routed through `0000TM`; refresh zero-filled storage evidence |
| `0002RP` | `by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md` | empty marker | formal ANSI/wide suffix helpers |
| `0002LK` | `by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md` | empty marker | formal wide varargs format constructor route |
| `0002LN` | `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md` | empty marker | formal wide range comparator |
| `0002LO` | `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md` | empty marker | formal wide literal comparator |
| `0003NL` | `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md` | empty marker | formal wide search/removal helper group |
| `0003NM` | `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md` | empty marker | formal splice/grow/substring helper group |
| `000289` | `by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md` | empty marker | marker comment routed through `0000TM` |
| `0001VQ` | `by-type/by-struct/RefCountedStringBufferHeader.md` | empty marker | formal struct declaration |
| `0001W4` | `by-type/by-struct/SimpleUStringPointerBackedLayout.md` | empty marker | marker comment, layout-only view covered by `0001WS` plus child bodies |
| `0001WS` | `by-type/by-template/StringBaseTemplate.md` | empty marker | marker comment plus child inventory refresh, no unsafe full template shell |
| `0002LJ` | `by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md` | empty marker | formal ANSI varargs format constructor route |
| `0002LL` | `by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md` | empty marker | formal ANSI VFormat worker |
| `0002LM` | `by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md` | empty marker | formal wide VFormat worker |

Important support dependency not present as a current generated empty marker:

| UID | Target page | Reason to include |
|---|---|---|
| `0003NT` | `by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md` | direct dependency of suffix checks; exact helper is source-reconstructable and should be routed by `StringBase.md` support coverage even though it is not one of the 15 generated empty markers today |

## MCP Provenance

IDA MCP was available and used. The restored active session is:

- Session: `supervisor_resume_20260629`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Server health: `ok`
- Auto-analysis: ready
- Hex-Rays: available
- Worker PID: `24256`

MCP command evidence used:

- `idb_list` confirmed one active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health` confirmed module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, Hex-Rays available, strings cache ready.
- `lookup_funcs` confirmed exact function sizes:
  - `0x00583140 sub_583140 size 0x79`
  - `0x005831c0 sub_5831C0 size 0x46`
  - `0x00583210 sub_583210 size 0x63`
  - `0x00583280 sub_583280 size 0x63`
  - `0x00583720 sub_583720 size 0x112`
  - `0x00583840 sub_583840 size 0x128`
  - `0x00584060 sub_584060 size 0x8a`
  - `0x005840f0 sub_5840F0 size 0x6a`
  - `0x005845b0 sub_5845B0 size 0x3c`
  - `0x005845f0 sub_5845F0 size 0x0a`
  - `0x00584990 sub_584990 size 0x179`
  - `0x00670268` and `0x0069bacc` are data, not functions.
- `entity_query` over `0x00583140-0x00584d90` confirmed dense StringBase helper coverage through `0x00584d80`.
- `get_bytes` checked post-function gaps as `0xcc` padding around the audited exact helper ranges.
- `analyze_component` and `decompile` were used for all audited helper groups.
- `xrefs_to` confirmed source-facing liveness and helper fan-in.
- `get_bytes` at `0x00670268`, `0x00670278`, `0x00670290`, `0x0067027c`, `0x0062d5d8`, and `0x0069bacc` confirmed sentinel/header/whitespace/pool storage bytes.

## Prior Reports And Local Evidence Checked

Searched/opened executed B-agent reports as leads and verified against current docs/MCP/generated output:

- `executed-b-agent-research/B008/0002RR-StringBaseSearchSpliceAndSubstring-source-quality.md`
- `executed-b-agent-research/B003/0002RT-StringBaseReleaseAndCapacity-source-quality.md`
- `executed-b-agent-research/B010/0002RQ-StringBaseSplitTrimAndLocks-source-quality.md`
- Search hits also checked for `0002RM`, `0002RS`, `0002RO`, `0002RN`, and `000325` StringBase reports.

Search terms used included:

- `0000OA`, `StringBase`, `CStringBase`, `NexusTK/util/StringBase`, `NexusTK\\util\\StringBase`
- `0000TM`, `0002AN`, `0002RP`, `0002LJ`, `0002LK`, `0002LL`, `0002LM`, `0002LN`, `0002LO`, `0003NL`, `0003NM`, `000289`, `0001VQ`, `0001W4`, `0001WS`
- `StringBuffer`, `SuffixChecks`, `FormatCtor`, `VFormatWorker`, `WideRangeCompare`, `CompareWideLiteral`, `WideSearch`, `SpliceGrow`

Current docs read for this report:

- `by-file/StringBase.md`
- `by-global/StringBufferSentinelsAndPools.md`
- `by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md`
- `by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md`
- `by-type/by-struct/RefCountedStringBufferHeader.md`
- `by-type/by-struct/SimpleUStringPointerBackedLayout.md`
- `by-type/by-template/StringBaseTemplate.md`
- `by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md`
- `by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md`
- `by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md`
- `by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md`
- `by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md`
- `by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md`
- `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md`
- `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md`
- `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md`
- `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md`
- `by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md`
- `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md`
- `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md`
- `by-memory/0x005845f0-0x00584d7e.StringBaseSearchSpliceAndSubstring.md`
- `by-file/StringUtil.md`

## Function And Data Evidence

### Suffix Checks: `0002RP`

MCP facts:

- `0x00583140 sub_583140 size 0x79`
- `0x005831c0 sub_5831C0 size 0x46`
- `0x005831b9-0x005831bf` and `0x00583206-0x0058320f` are padding after the function bodies.
- Xrefs:
  - `0x00583140`: `0x004b1f85`, `0x0057abce`
  - `0x005831c0`: `0x004b1e65`, `0x004b3139`

Decompile summary:

- ANSI suffix check computes `strlen(suffix)`, reads stored length from `data[-8]`, rejects if suffix longer than the stored string, then calls `sub_584060(data + length - suffixLength, data + length, suffix, suffix + suffixLength)` and tests for equality.
- Wide suffix check computes `wcslen(suffix)`, reads stored length, rejects if suffix longer than the stored string, then calls the existing bounded wide compare helper at `0x00584550` with start index and suffix length.

Disposition:

- Source behavior is exact enough for formal C++.
- `0003NT` must be formalized as a support dependency because ANSI suffix code calls the byte-range comparator directly.

### Format Constructors And Workers: `0002LJ`, `0002LK`, `0002LL`, `0002LM`

MCP facts:

- `0x00583210 sub_583210 size 0x63`
- `0x00583280 sub_583280 size 0x63`
- `0x00583720 sub_583720 size 0x112`
- `0x00583840 sub_583840 size 0x128`
- Post-function bytes at `0x00583273`, `0x005832e3`, `0x00583832`, and `0x00583968` are padding.
- Xrefs:
  - `0x00583210`: 3 xrefs
  - `0x00583280`: 33 xrefs
  - `0x00583720`: 1 xref from the ANSI constructor
  - `0x00583840`: 2 xrefs from the wide constructor and another StringBase route

Decompile summary:

- ANSI constructor sets the receiver to the ANSI empty sentinel at `off_670290`, starts a `va_list`, calls the ANSI VFormat worker, and returns the receiver.
- Wide constructor sets the receiver to the wide empty sentinel, starts a `va_list`, calls the wide VFormat worker, and returns the receiver.
- ANSI VFormat worker uses `strlen(format) + 64` as the initial requested capacity, allocates or detaches when the current buffer is shared or too small, calls the CRT secure common `vsnprintf_s` route, doubles capacity on `-1`, and after success refreshes stored length with `strlen`.
- Wide VFormat worker mirrors the ANSI worker with `wcslen(format) + 64`, wide allocation/release helpers, secure common `vsnwprintf_s`, and final stored length from `wcslen`.

Disposition:

- These are not generic compiler helpers. They are source-facing StringBase methods.
- `0002LK` should be rerouted to `CANONICAL_OWNER:0001WS` and `EMITTER_UIDS:0001WS` to match the ANSI constructor and template ownership.
- Current "below threshold" wording in older pages is stale. The functions are reconstructable at first-draft source quality.

### Range And Literal Comparators: `0003NT`, `0002LN`, `0002LO`

MCP facts:

- `0x00584060 sub_584060 size 0x8a`, sole direct xref from ANSI suffix at `0x005831a5`.
- `0x005840f0 sub_5840F0 size 0x6a`, 29 xrefs.
- `0x005845b0 sub_5845B0 size 0x3c`, 3 xrefs.

Decompile summary:

- Byte-range comparator compares two half-open byte ranges, using optimized dword chunks plus tail bytes, then returns `-1`, `0`, or `1` with a length tie-break.
- Wide range comparator compares two half-open UTF-16 ranges and returns `-1`, `0`, or `1` with a length tie-break.
- Wide literal comparator reads the receiver length, computes literal length with `wcslen`, and calls the wide range comparator over receiver data and the literal.

Disposition:

- `0003NT` is a required support implementation for `0002RP`.
- `0002LN` and `0002LO` are formal source helpers.
- Source spelling can use simple range loops rather than reproducing the compiler's dword optimization, because the optimized loop is not source-significant.

### Wide Search Helpers: `0003NL`

MCP facts:

- `0x005845f0 size 0x0a`: empty predicate, no callees.
- `0x00584600 size 0x79`: remove wide range, callees `sub_5833A0`, `_memmove_0`, `sub_5830C0`.
- `0x00584680 size 0xa0`: forward substring search, no callees.
- `0x00584720 size 0x79`: find first not-of, no callees.
- `0x005847a0 size 0x75`: find first of, no callees.
- `0x00584820 size 0x72`: find last not-of, no callees.
- `0x005848a0 size 0x6f`: find last of, no callees.
- Xrefs exist for all helper starts, including 12 xrefs to the empty predicate.

Decompile summary:

- `0x005845f0` returns `length == 0`.
- `0x00584600` removes a bounded range, clamps count, releases entire string for full removal, otherwise detaches shared wide data, moves the tail, writes the null terminator, and updates stored length.
- `0x00584680` scans forward for a bounded substring.
- `0x00584720` and `0x005847a0` scan forward against a character set for first not-of and first of.
- `0x00584820` and `0x005848a0` scan backward against a character set for last not-of and last of.

Disposition:

- The group is suitable for formal C++.
- Existing B008/B010 reports already support the family-level names and semantics, and current MCP confirms them.

### Splice, Grow, Length, Substring: `0003NM`

MCP facts:

- `0x00584990 size 0x179`: wide splice/replace, callees `_memmove`, `sub_5833A0`, `sub_582E30`, `_memmove_0`.
- `0x00584b10 size 0x83`: ANSI ensure-capacity, callees `_memmove`, `sub_5832F0`, `sub_582D80`.
- `0x00584ba0 size 0x91`: wide ensure-capacity, callees `_memmove`, `sub_582E30`, `sub_5833A0`.
- `0x00584c40 size 0xa6`: reverse substring search, no callees.
- `0x00584cf0 size 0x06`: length accessor, no callees.
- `0x00584d00 size 0x7e`: wide substring, callees `sub_583460`, `_memmove`, `sub_582E30`.
- Xrefs exist for all helper starts.

Decompile summary:

- `0x00584990` clamps removal and insertion lengths, performs in-place replacement if the buffer is writable and capacity is enough, otherwise allocates/copies prefix, replacement, and suffix, then releases the old buffer.
- `0x00584b10` and `0x00584ba0` grow ANSI/wide capacity only when requested capacity exceeds current capacity, preserving old length and content.
- `0x00584c40` performs reverse bounded substring search with defined zero-length needle behavior.
- `0x00584cf0` reads stored length from the buffer header.
- `0x00584d00` creates a wide substring, using the copy/share route for full-string `count == 0xffffffff` from start 0 and allocation/copy for slices.

Disposition:

- The group is suitable for formal C++.
- Local helper names remain first-draft, but behavior, ownership, and source placement are no longer blockers.

### Sentinel And Pool Data: `0000TM`, `0002AN`, `000289`

MCP facts:

- `0x00670268-0x00670294` contains both empty string sentinel headers and exported pointers:
  - wide empty sentinel header: refcount `-1`, length `0`, capacity `0`, null wide character
  - wide empty pointer at `0x00670278` points to data at `0x00670274`
  - whitespace pointer at `0x0067027c` points to `0x0062d5d8`
  - ANSI empty sentinel header and self pointer around `0x00670280-0x00670290`
- `0x0062d5d8` bytes decode as UTF-16 `" \t\n\r\0"`.
- `0x0069bacc-0x0069bc0c` currently reads as zero-filled static storage, not all-`0xff` bytes.
- Each of the eight pool globals has references from static constructor, allocator, release, and cleanup paths.
- Static constructor wrapper starts at `0x0041a180`, `0x0041a1a0`, `0x0041a1c0`, `0x0041a1e0`, `0x0041a200`, `0x0041a220`, `0x0041a240`, and `0x0041a260`.
- Cleanup wrappers include the `0x0060c3c0` through `0x0060c430` area.

Disposition:

- `0000TM` should emit the formal source-level globals.
- `0002AN` should not emit a second duplicate body. It should be a marker comment saying the exact pool storage declarations are emitted by `0000TM`, and its evidence must be corrected from stale sampled `0xff` bytes to current zero-filled static storage before constructors run.
- `000289` should not duplicate `0000TM`; it should be a marker comment saying sentinel declarations and whitespace pointer are emitted by `0000TM`.

### Struct And Template Type Pages: `0001VQ`, `0001W4`, `0001WS`

MCP/doc facts:

- All audited StringBase helpers use a single data pointer receiver whose header is accessed immediately before the character data.
- Header offsets are stable:
  - `data[-12]`: refcount
  - `data[-8]`: length
  - `data[-4]`: capacity
- Empty sentinels use refcount `-1`, length `0`, capacity `0`.
- Format, allocation, release, split/trim, append, search, splice, and substring helpers all agree on this layout.

Disposition:

- `0001VQ` should emit a formal struct declaration. It is exact and directly backed by every StringBase helper family.
- `0001W4` should remain a layout-only marker comment. A standalone declaration would duplicate the one-pointer layout of `0001WS` without proving the public facade name or class boundary.
- `0001WS` should not emit a full template declaration in this pass. Exact child methods are already independently representable, but a class shell would still guess:
  - public/private ordering,
  - facade typedefs and names,
  - overload membership across `StringBase`, `SimpleUString`, and companion utilities,
  - constructor/destructor declarations not covered by this empty-emitter family.

This is the rare no-improvement exception for the template aggregate: adding a partial class shell would be less source-quality than emitting exact child method bodies and a precise marker comment.

## Rejected Alternatives

| Alternative | Rejected because |
|---|---|
| Keep all 15 markers as no-code comments | Current MCP proves exact behavior for most helpers; keeping comments would violate no-loss standards. |
| Treat all helper bodies as generic compiler/library code | Xrefs and receiver/header use show these are StringBase methods/helpers, not CRT or compiler thunks. |
| Move format workers to `StringUtil.md` | Workers operate on StringBase receivers and share StringBase allocation/release/sentinel state. |
| Emit pool storage separately in `0002AN` and again in `0000TM` | Would duplicate source declarations. `0000TM` is the source-level global owner; `0002AN` is exact storage evidence. |
| Emit sentinels separately in `000289` and again in `0000TM` | Would duplicate source declarations. `000289` is exact memory evidence for the global page. |
| Emit a standalone full `StringBase` template class in `0001WS` | Still requires guessing facade names, access order, overload inventory, and header boundaries. Exact child pages are safer and more useful. |
| Ignore `0003NT` because it is not one of the 15 generated empty markers | `0002RP` calls it directly; implementation of suffix checks should not leave a direct dependency blank. |

## Recommended Metadata

Apply these metadata changes during implementation if current file state still matches this audit.

| UID | File | Completion | Confidence | Owner | Emitter | Reconstructable | Notes |
|---|---|---:|---:|---|---|---|---|
| `0000OA` | `by-file/StringBase.md` | `91` | `90` | `FILE` | `0000OA` | `TRUE` | target file root |
| `0000TM` | `by-global/StringBufferSentinelsAndPools.md` | `93` | `91` | `0000OA` | `0000OA` | `TRUE` | formal global declarations |
| `0002AN` | `by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md` | `91` | `91` | `0000TM` | `0000TM` | `TRUE` | marker comment via `0000TM`, zero-filled storage refresh |
| `0002RP` | `by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md` | `88` | `90` | `0000OA` | `0000OA` | `TRUE` | formal suffix helpers |
| `0002LK` | `by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md` | `88` | `91` | `0001WS` | `0001WS` | `TRUE` | formal wide format constructor |
| `0002LN` | `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md` | `89` | `92` | `0000OA` | `0000OA` | `TRUE` | formal wide range comparator |
| `0002LO` | `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md` | `88` | `91` | `0000OA` | `0000OA` | `TRUE` | formal literal comparator |
| `0003NL` | `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md` | `89` | `91` | `0000OA` | `0000OA` | `TRUE` | formal search/removal group |
| `0003NM` | `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md` | `89` | `91` | `0000OA` | `0000OA` | `TRUE` | formal splice/grow/substring group |
| `000289` | `by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md` | `90` | `92` | `0000OA` | `0000OA` | `TRUE` | marker comment via `0000TM` |
| `0001VQ` | `by-type/by-struct/RefCountedStringBufferHeader.md` | `90` | `91` | `0000OA` | `0000OA` | `TRUE` | formal struct declaration |
| `0001W4` | `by-type/by-struct/SimpleUStringPointerBackedLayout.md` | `87` | `89` | `0000OA` | `0000OA` | `TRUE` | layout marker only |
| `0001WS` | `by-type/by-template/StringBaseTemplate.md` | `88` | `91` | `0000OA` | `0000OA` | `TRUE` | template owner marker and inventory refresh |
| `0002LJ` | `by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md` | `88` | `91` | `0001WS` | `0001WS` | `TRUE` | formal ANSI format constructor |
| `0002LL` | `by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md` | `88` | `91` | `0001WS` | `0001WS` | `TRUE` | formal ANSI VFormat |
| `0002LM` | `by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md` | `88` | `91` | `0001WS` | `0001WS` | `TRUE` | formal wide VFormat |
| `0003NT` | `by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md` | `88` | `90` | `0000OA` | `0000OA` | `TRUE` | support dependency for `0002RP` |

Support aggregate refreshes:

| UID | File | Recommended refresh |
|---|---|---|
| `0001J1` | `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md` | update `0002RP` row from blank to formal suffix helpers and add `0003NT` comparator dependency proof |
| `0001J2` | `by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md` | update stale blank/below-threshold text for `0002LJ` and `0002LK`; keep aggregate non-emitting |
| `0001J3` | `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md` | update stale blank/below-threshold text for `0002LL`, `0002LM`, `0002LN`, `0002LO`, `0003NL`, `0003NM`, and `0003NT` |
| `0002RR` | `by-memory/0x005845f0-0x00584d7e.StringBaseSearchSpliceAndSubstring.md` | check only; edit only if still states child C++ is blank after implementation |
| `0000OB` | `by-file/StringUtil.md` | check only; no edit expected unless current text contradicts StringBase ownership |

## Formal Source Details To Implement

The following is the implementation-level detail accepted report callback should apply. Function and helper names are first-draft source names but the control flow, ownership, and data behavior must be preserved.

### `0000TM` Global Data

Insert formal C++ for the global source owner of sentinel and pool state:

```cpp
namespace mystr {

struct StringBaseAnsiEmptySentinelStorage {
    RefCountedStringBufferHeader header;
    char data[1];
};

struct StringBaseWideEmptySentinelStorage {
    RefCountedStringBufferHeader header;
    wchar_t data[1];
};

static StringBaseWideEmptySentinelStorage g_emptyWideStringStorage = {
    { -1, 0, 0 },
    { L'\0' }
};

static StringBaseAnsiEmptySentinelStorage g_emptyAnsiStringStorage = {
    { -1, 0, 0 },
    { '\0' }
};

wchar_t *g_emptyWideString = g_emptyWideStringStorage.data;
char *g_emptyAnsiString = g_emptyAnsiStringStorage.data;

static const wchar_t g_wideTrimWhitespaceChars[] = L" \t\n\r";

PoolAllocator g_widePool64(sizeof(RefCountedStringBufferHeader) +
                           (64 + 1) * sizeof(wchar_t));
PoolAllocator g_widePool128(sizeof(RefCountedStringBufferHeader) +
                            (128 + 1) * sizeof(wchar_t));
PoolAllocator g_widePool256(sizeof(RefCountedStringBufferHeader) +
                            (256 + 1) * sizeof(wchar_t));
PoolAllocator g_widePool512(sizeof(RefCountedStringBufferHeader) +
                            (512 + 1) * sizeof(wchar_t));

PoolAllocator g_ansiPool64(sizeof(RefCountedStringBufferHeader) +
                           (64 + 1) * sizeof(char));
PoolAllocator g_ansiPool128(sizeof(RefCountedStringBufferHeader) +
                            (128 + 1) * sizeof(char));
PoolAllocator g_ansiPool256(sizeof(RefCountedStringBufferHeader) +
                            (256 + 1) * sizeof(char));
PoolAllocator g_ansiPool512(sizeof(RefCountedStringBufferHeader) +
                            (512 + 1) * sizeof(char));

} // namespace mystr
```

Also update text to record that current MCP reads `0x0069bacc-0x0069bc0c` as zero-filled static storage before constructors, replacing older sampled all-`0xff` wording.

### `0002AN` Pool Storage Marker

Do not duplicate the pool definitions. Insert exact marker comment:

```cpp
// Source declarations for this exact string-buffer pool storage are emitted by [UID:0000TM].
```

### `000289` Sentinel Marker

Do not duplicate sentinel definitions. Insert exact marker comment:

```cpp
// Source declarations for these empty-sentinel headers and the trim whitespace pointer are emitted by [UID:0000TM].
```

### `0001VQ` Ref-Counted Header

Insert formal struct declaration:

```cpp
namespace mystr {

struct RefCountedStringBufferHeader {
    volatile LONG refCount;
    unsigned int length;
    unsigned int capacity;
};

} // namespace mystr
```

### `0001W4` Layout-Only Marker

Insert exact marker comment:

```cpp
// Layout-only view: the one-pointer StringBase receiver layout is represented by [UID:0001WS] and exact StringBase child helper bodies; this page owns no standalone C++ declaration.
```

### `0001WS` Template Owner Marker

Insert exact marker comment and refresh the child inventory:

```cpp
// StringBaseTemplate is the declaration/type owner for exact child method bodies emitted through this file; a standalone full template declaration is deferred until the project-wide StringBase/SimpleUString header API is finalized.
```

The inventory should identify at least these formal child routes after implementation:

- `0002LJ` ANSI format constructor
- `0002LK` wide format constructor
- `0002LL` ANSI VFormat worker
- `0002LM` wide VFormat worker
- `0002RP` ANSI/wide suffix checks
- `0003NL` wide search/removal helpers
- `0003NM` wide splice/grow/substring helpers

### `0003NT` Byte Range Comparator

Insert formal support helper:

```cpp
namespace mystr {

int CompareAnsiRange(const char *lhsBegin,
                     const char *lhsEnd,
                     const char *rhsBegin,
                     const char *rhsEnd)
{
    const char *lhs = lhsBegin;
    const char *rhs = rhsBegin;

    while (lhs != lhsEnd && rhs != rhsEnd) {
        const unsigned char lhsChar = static_cast<unsigned char>(*lhs);
        const unsigned char rhsChar = static_cast<unsigned char>(*rhs);
        if (lhsChar != rhsChar) {
            return lhsChar < rhsChar ? -1 : 1;
        }
        ++lhs;
        ++rhs;
    }

    const unsigned int lhsLength =
        static_cast<unsigned int>(lhsEnd - lhsBegin);
    const unsigned int rhsLength =
        static_cast<unsigned int>(rhsEnd - rhsBegin);
    if (lhsLength == rhsLength) {
        return 0;
    }
    return lhsLength < rhsLength ? -1 : 1;
}

} // namespace mystr
```

### `0002RP` Suffix Checks

Insert formal suffix helpers:

```cpp
namespace mystr {

template <>
bool
StringBase<char, mychar_traits<char> >::EndsWithAnsi(
    const char *suffix) const
{
    const unsigned int suffixLength =
        static_cast<unsigned int>(strlen(suffix));
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);

    return length >= suffixLength &&
           CompareAnsiRange(m_data + length - suffixLength,
                            m_data + length,
                            suffix,
                            suffix + suffixLength) == 0;
}

template <>
bool
StringBase<wchar_t, mychar_traits<wchar_t> >::EndsWithWide(
    const wchar_t *suffix) const
{
    const unsigned int suffixLength =
        static_cast<unsigned int>(wcslen(suffix));
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);

    return length >= suffixLength &&
           CompareWideSubstringWithLiteral(length - suffixLength,
                                           suffixLength,
                                           suffix) == 0;
}

} // namespace mystr
```

### `0002LJ` ANSI Format Constructor

Insert formal method:

```cpp
namespace mystr {

template <>
StringBase<char, mychar_traits<char> > &
StringBase<char, mychar_traits<char> >::InitializeAnsiFormat(
    const char *format,
    ...)
{
    m_data = g_emptyAnsiString;

    va_list args;
    va_start(args, format);
    AnsiVFormat(format, args);
    va_end(args);
    return *this;
}

} // namespace mystr
```

### `0002LK` Wide Format Constructor

Insert formal method and change owner/emitter to `0001WS`:

```cpp
namespace mystr {

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::InitializeWideFormat(
    const wchar_t *format,
    ...)
{
    m_data = g_emptyWideString;

    va_list args;
    va_start(args, format);
    WideVFormat(format, args);
    va_end(args);
    return *this;
}

} // namespace mystr
```

### `0002LL` ANSI VFormat Worker

Insert formal method:

```cpp
namespace mystr {

template <>
int
StringBase<char, mychar_traits<char> >::AnsiVFormat(const char *format,
                                                    va_list args)
{
    unsigned int requested = static_cast<unsigned int>(strlen(format)) + 64;
    int result = -1;

    for (;;) {
        RefCountedStringBufferHeader *header =
            reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        if (header->refCount > 1 || header->capacity < requested) {
            ReleaseAnsiBuffer();
            AllocateAnsiBuffer(requested);
            header =
                reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        }

        const unsigned int capacity = header->capacity;
        m_data[capacity] = '\0';
        header->length = capacity;

        result = StringBaseVsnprintf(m_data,
                                     capacity,
                                     capacity,
                                     format,
                                     args);
        if (result != -1) {
            break;
        }

        requested = capacity * 2;
    }

    if (m_data != g_emptyAnsiString) {
        RefCountedStringBufferHeader *header =
            reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        if (header->refCount > 1) {
            char *oldData = m_data;
            const unsigned int length = header->length;
            AllocateAnsiBuffer(length);
            memmove(m_data, oldData, length);

            StringBase<char, mychar_traits<char> > oldString;
            oldString.m_data = oldData;
            oldString.ReleaseAnsiBuffer();
            header =
                reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        }

        header->length = static_cast<unsigned int>(strlen(m_data));
    }

    return result;
}

} // namespace mystr
```

### `0002LM` Wide VFormat Worker

Insert formal method:

```cpp
namespace mystr {

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::WideVFormat(
    const wchar_t *format,
    va_list args)
{
    unsigned int requested = static_cast<unsigned int>(wcslen(format)) + 64;
    int result = -1;

    for (;;) {
        RefCountedStringBufferHeader *header =
            reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        if (header->refCount > 1 || header->capacity < requested) {
            ReleaseWideBuffer();
            AllocateWideBuffer(requested);
            header =
                reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        }

        const unsigned int capacity = header->capacity;
        m_data[capacity] = L'\0';
        header->length = capacity;

        result = StringBaseVsnwprintf(m_data,
                                      capacity,
                                      capacity,
                                      format,
                                      args);
        if (result != -1) {
            break;
        }

        requested = capacity * 2;
    }

    if (m_data != g_emptyWideString) {
        RefCountedStringBufferHeader *header =
            reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        if (header->refCount > 1) {
            wchar_t *oldData = m_data;
            const unsigned int length = header->length;
            AllocateWideBuffer(length);
            memmove(m_data, oldData, length * sizeof(wchar_t));

            StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
            oldString.m_data = oldData;
            oldString.ReleaseWideBuffer();
            header =
                reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
        }

        header->length = static_cast<unsigned int>(wcslen(m_data));
    }

    return result;
}

} // namespace mystr
```

### `0002LN` Wide Range Comparator

Insert formal helper:

```cpp
namespace mystr {

int WideRangeCompare(const wchar_t *lhsBegin,
                     const wchar_t *lhsEnd,
                     const wchar_t *rhsBegin,
                     const wchar_t *rhsEnd)
{
    const wchar_t *lhs = lhsBegin;
    const wchar_t *rhs = rhsBegin;

    while (lhs != lhsEnd && rhs != rhsEnd) {
        if (*lhs != *rhs) {
            return *lhs < *rhs ? -1 : 1;
        }
        ++lhs;
        ++rhs;
    }

    const unsigned int lhsLength =
        static_cast<unsigned int>(lhsEnd - lhsBegin);
    const unsigned int rhsLength =
        static_cast<unsigned int>(rhsEnd - rhsBegin);
    if (lhsLength == rhsLength) {
        return 0;
    }
    return lhsLength < rhsLength ? -1 : 1;
}

} // namespace mystr
```

### `0002LO` Wide Literal Comparator

Insert formal method:

```cpp
namespace mystr {

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::CompareWideLiteral(
    const wchar_t *literal) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    const wchar_t *literalEnd = literal;
    while (*literalEnd != L'\0') {
        ++literalEnd;
    }

    return WideRangeCompare(m_data, m_data + length, literal, literalEnd);
}

} // namespace mystr
```

### `0003NL` Wide Search And Removal Helpers

Insert formal helper group:

```cpp
namespace mystr {

namespace {

bool StringBaseWideCharInSet(wchar_t ch,
                             const wchar_t *set,
                             unsigned int setLength)
{
    for (unsigned int i = 0; i < setLength; ++i) {
        if (set[i] == ch) {
            return true;
        }
    }
    return false;
}

}

template <>
bool
StringBase<wchar_t, mychar_traits<wchar_t> >::empty() const
{
    return reinterpret_cast<const int *>(m_data)[-2] == 0;
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::RemoveWideRange(
    unsigned int start,
    unsigned int count)
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length <= start) {
        return *this;
    }

    unsigned int removeCount = length - start;
    if (count < removeCount) {
        removeCount = count;
    }
    if (removeCount == 0) {
        return *this;
    }

    if (start == 0 && removeCount == length) {
        ReleaseWideBuffer();
        return *this;
    }

    DetachWideIfShared();
    const unsigned int newLength = length - removeCount;
    memmove(m_data + start,
            m_data + start + removeCount,
            (newLength - start) * sizeof(wchar_t));
    m_data[newLength] = L'\0';
    reinterpret_cast<int *>(m_data)[-2] = static_cast<int>(newLength);
    return *this;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindSubstring(
    const wchar_t *needle,
    unsigned int start,
    unsigned int needleLength) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length < start + needleLength) {
        return -1;
    }

    for (unsigned int index = start;
         index + needleLength <= length;
         ++index) {
        unsigned int matched = 0;
        while (matched < needleLength &&
               m_data[index + matched] == needle[matched]) {
            ++matched;
        }
        if (matched == needleLength) {
            return index == length ? -1 : static_cast<int>(index);
        }
    }

    return -1;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindFirstNotOf(
    const wchar_t *chars,
    unsigned int start,
    unsigned int charCount) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length < start) {
        return -1;
    }

    for (unsigned int index = start; index < length; ++index) {
        if (!StringBaseWideCharInSet(m_data[index], chars, charCount)) {
            return static_cast<int>(index);
        }
    }

    return -1;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindFirstOf(
    const wchar_t *chars,
    unsigned int start,
    unsigned int charCount) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length < start) {
        return -1;
    }

    for (unsigned int index = start; index < length; ++index) {
        if (StringBaseWideCharInSet(m_data[index], chars, charCount)) {
            return static_cast<int>(index);
        }
    }

    return -1;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindLastNotOf(
    const wchar_t *chars,
    unsigned int start,
    unsigned int charCount) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length == 0) {
        return -1;
    }

    unsigned int index = start;
    if (length - 1 < index) {
        index = length - 1;
    }

    for (;;) {
        if (!StringBaseWideCharInSet(m_data[index], chars, charCount)) {
            return static_cast<int>(index);
        }
        if (index == 0) {
            break;
        }
        --index;
    }

    return -1;
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindLastOf(
    const wchar_t *chars,
    unsigned int start,
    unsigned int charCount) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length == 0) {
        return -1;
    }

    unsigned int index = start;
    if (length - 1 < index) {
        index = length - 1;
    }

    for (;;) {
        if (StringBaseWideCharInSet(m_data[index], chars, charCount)) {
            return static_cast<int>(index);
        }
        if (index == 0) {
            break;
        }
        --index;
    }

    return -1;
}

} // namespace mystr
```

### `0003NM` Splice, Grow, Length, Substring Helpers

Insert formal helper group:

```cpp
namespace mystr {

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::SpliceWide(
    unsigned int start,
    unsigned int removeMax,
    const wchar_t *insertText,
    unsigned int insertMax)
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length <= start) {
        return *this;
    }

    unsigned int removeCount = length - start;
    if (removeMax < removeCount) {
        removeCount = removeMax;
    }

    unsigned int insertLength = 0;
    while (insertText[insertLength] != L'\0') {
        ++insertLength;
    }
    if (insertMax < insertLength) {
        insertLength = insertMax;
    }

    const unsigned int newLength = length + insertLength - removeCount;
    RefCountedStringBufferHeader *header =
        reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;

    if ((header->refCount == 1 || header->refCount == -1) &&
        newLength <= header->capacity) {
        if (removeCount != insertLength) {
            memmove(m_data + start + insertLength,
                    m_data + start + removeCount,
                    (length - removeCount - start) * sizeof(wchar_t));
        }
        memmove(m_data + start, insertText, insertLength * sizeof(wchar_t));
        m_data[newLength] = L'\0';
        header->length = newLength;
        return *this;
    }

    wchar_t *oldData = m_data;
    if (header->refCount > 1 || header->capacity < newLength) {
        ReleaseWideBuffer();
        AllocateWideBuffer(newLength);
    }

    memmove(m_data, oldData, start * sizeof(wchar_t));
    memmove(m_data + start, insertText, insertLength * sizeof(wchar_t));
    memmove(m_data + start + insertLength,
            oldData + start + removeCount,
            (length - removeCount - start) * sizeof(wchar_t));

    StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
    oldString.m_data = oldData;
    oldString.ReleaseWideBuffer();
    return *this;
}

template <>
void
StringBase<char, mychar_traits<char> >::EnsureAnsiCapacity(
    unsigned int capacity)
{
    RefCountedStringBufferHeader *header =
        reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
    if (capacity <= header->capacity) {
        return;
    }

    char *oldData = m_data;
    const unsigned int oldLength = header->length;
    unsigned int allocationLength = capacity;
    if (allocationLength < oldLength) {
        allocationLength = oldLength;
    }

    AllocateAnsiBuffer(allocationLength);
    memmove(m_data, oldData, oldLength);
    m_data[oldLength] = '\0';
    reinterpret_cast<RefCountedStringBufferHeader *>(m_data)[-1].length =
        oldLength;

    StringBase<char, mychar_traits<char> > oldString;
    oldString.m_data = oldData;
    oldString.ReleaseAnsiBuffer();
}

template <>
void
StringBase<wchar_t, mychar_traits<wchar_t> >::EnsureWideCapacity(
    unsigned int capacity)
{
    RefCountedStringBufferHeader *header =
        reinterpret_cast<RefCountedStringBufferHeader *>(m_data) - 1;
    if (capacity <= header->capacity) {
        return;
    }

    wchar_t *oldData = m_data;
    const unsigned int oldLength = header->length;
    unsigned int allocationLength = capacity;
    if (allocationLength < oldLength) {
        allocationLength = oldLength;
    }

    AllocateWideBuffer(allocationLength);
    memmove(m_data, oldData, oldLength * sizeof(wchar_t));
    m_data[oldLength] = L'\0';
    reinterpret_cast<RefCountedStringBufferHeader *>(m_data)[-1].length =
        oldLength;

    StringBase<wchar_t, mychar_traits<wchar_t> > oldString;
    oldString.m_data = oldData;
    oldString.ReleaseWideBuffer();
}

template <>
int
StringBase<wchar_t, mychar_traits<wchar_t> >::FindLastSubstring(
    const wchar_t *needle,
    unsigned int start,
    unsigned int needleLength) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    if (length < needleLength) {
        return -1;
    }

    unsigned int index = start;
    if (needleLength == 0) {
        return length < index ? static_cast<int>(length)
                              : static_cast<int>(index);
    }

    const unsigned int lastPossible = length - needleLength;
    if (lastPossible < index) {
        index = lastPossible;
    }

    for (;;) {
        unsigned int matched = 0;
        while (matched < needleLength &&
               m_data[index + matched] == needle[matched]) {
            ++matched;
        }
        if (matched == needleLength) {
            return static_cast<int>(index);
        }
        if (index == 0) {
            break;
        }
        --index;
    }

    return -1;
}

template <class CharT, class Traits>
unsigned int
StringBase<CharT, Traits>::length() const
{
    return static_cast<unsigned int>(
        reinterpret_cast<const int *>(m_data)[-2]);
}

template <>
StringBase<wchar_t, mychar_traits<wchar_t> > &
StringBase<wchar_t, mychar_traits<wchar_t> >::SubstringWide(
    StringBase<wchar_t, mychar_traits<wchar_t> > &out,
    unsigned int start,
    unsigned int count) const
{
    const unsigned int length =
        static_cast<unsigned int>(reinterpret_cast<const int *>(m_data)[-2]);
    unsigned int first = start;
    if (length < first) {
        first = length;
    }

    if (first == 0 && count == 0xffffffffU) {
        out.CopyOrShareWide(*this);
        return out;
    }

    unsigned int last = length;
    if (count != 0xffffffffU) {
        last = first + count;
        if (length < last) {
            last = length;
        }
    }

    const unsigned int resultLength = last - first;
    out.AllocateWideBuffer(resultLength);
    memmove(out.m_data, m_data + first, resultLength * sizeof(wchar_t));
    return out;
}

} // namespace mystr
```

## Target And Support Doc Implementation Plan

After supervisor acceptance, implementation should edit only current by-* docs needed for these accepted claims and should re-read each file and leases immediately before editing.

Required target edit:

- `by-file/StringBase.md`
  - Raise metadata to `91/90`.
  - Add a concise empty-emitter-family resolution section with the above UID dispositions.
  - Add or update target support rows so all formalized child pages are visible from the file root.
  - Add support dependency `0003NT` if it is still missing from generated routing.

Required child/support edits:

- `by-global/StringBufferSentinelsAndPools.md`
- `by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md`
- `by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md`
- `by-type/by-struct/RefCountedStringBufferHeader.md`
- `by-type/by-struct/SimpleUStringPointerBackedLayout.md`
- `by-type/by-template/StringBaseTemplate.md`
- `by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md`
- `by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md`
- `by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md`
- `by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md`
- `by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md`
- `by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md`
- `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md`
- `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md`
- `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md`
- `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md`

Support aggregate refreshes, edit only if current text remains stale after re-read:

- `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md`
- `by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md`
- `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md`
- `by-memory/0x005845f0-0x00584d7e.StringBaseSearchSpliceAndSubstring.md`
- `by-file/StringUtil.md`

## Validator Plan For Implementation Callback

Run validators from `E:/NTK/GhidraBridge/source-3/project-documentation`.

Use scoped file validation for each changed by-* file. Use `--wait-generated` for the target by-file validator and for any batch where generated `NexusTK/util/StringBase.cpp` freshness is required.

Expected commands include:

> Executable block R001 was removed from this report and preserved verbatim in [0000OA-StringBase-empty-emitter-family-source-quality-removed.md](0000OA-StringBase-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If aggregate support docs are changed, run scoped validators for those changed files as well.

Expected generated freshness after implementation:

- `auto-generated/NexusTK/util/StringBase.cpp` refreshed after validator run.
- No remaining empty marker blocks for the 15 queue markers.
- `0003NT` appears in generated output or is otherwise confirmed as routed through the target/support dependency that emits its formal comparator.

## Claim And Incorporation Ledger

| Claim | Evidence | Implementation action after acceptance | Status |
|---|---|---|---|
| Target family has 15 empty markers in current generated output | Current `auto-generated/NexusTK/util/StringBase.cpp` and tracker row | Update target/support docs so markers emit formal code or explicit route comments | `applied` - `by-file/StringBase.md` now records the full family disposition and target score `91/90`. Generated `auto-generated/NexusTK/util/StringBase.cpp` current header is `validator-command-id:000000002926`, `validator-refreshed-at:2026-06-30T14:28:17-04:00`, newer than the route-fix validator command, with no searched `empty marker` / `No reconstruction` / `TODO` marker text for this queue family. |
| IDA MCP is current and available | `server_health ok`, active `supervisor_resume_20260629`, function lookups/decompiles completed | Cite MCP facts in touched docs as needed | `applied` - touched target/support docs cite `supervisor_resume_20260629`, exact sizes, bytes, xrefs, padding, and rejected route alternatives where the accepted report required them. No fallback-only implementation evidence was used. |
| `0000TM` owns source-level sentinel/pool globals | MCP bytes, xrefs, current docs, global page ownership | Insert formal globals and score `93/91` | `applied` - `by-global/StringBufferSentinelsAndPools.md` is `93/91`, emits sentinel storage, exported sentinel pointers, trim whitespace literal, and eight StringBase pool declarations. Generated `StringBase.cpp` includes UID `0000TM` at line 7 under current generated header `000000002926`. |
| `0002AN` is exact storage evidence, not separate source owner | Current pool bytes zero-filled; constructors initialize pool objects | Insert route marker via `0000TM`, correct stale byte wording | `applied` - `by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md` is `91/91`, routes through `0000TM`, and replaces stale all-`ff`/`0xff` wording with zero-filled loader storage before constructors. It is covered in generated source by the `0000TM` declarations, not a duplicate UID block. |
| `000289` is exact memory evidence for sentinels/whitespace pointer | MCP bytes at `0x00670268` and `0x0062d5d8` | Insert route marker via `0000TM` | `applied` - `by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md` is `90/92`, routes through `0000TM`, and records sentinel/whitespace byte evidence. It is covered in generated source by the `0000TM` declarations, not a duplicate UID block. |
| `0001VQ` is exact source struct | Stable header access across all StringBase helpers | Insert `RefCountedStringBufferHeader` declaration | `applied` - `by-type/by-struct/RefCountedStringBufferHeader.md` is `90/91` and its formal block emits the 12-byte `refCount`/`length`/`capacity` header declaration. Generated `StringBase.cpp` includes UID `0001VQ`. |
| `0001W4` is layout-only | Single pointer receiver is represented by `0001WS` and child bodies | Insert no-standalone-code layout marker | `applied` - `by-type/by-struct/SimpleUStringPointerBackedLayout.md` is `87/89` and emits only the accepted layout/no-standalone marker; generated `StringBase.cpp` includes UID `0001W4` as a route/layout comment. |
| `0001WS` should not emit a full template shell | Exact methods known, public full class/facade API not fully proven | Insert template owner marker and child inventory | `applied` - `by-type/by-template/StringBaseTemplate.md` is `88/91`, keeps the no-full-template-shell marker, expands the child inventory, and now includes `[[CHILDREN]]` so accepted template-owned child bodies emit without inventing a class shell. The extra `[[CHILDREN]]` insertion point was required by by-structure emitter routing and proven by generated output: before it, `0002LJ`/`0002LK`/`0002LL`/`0002LM` formal blocks stayed out of `StringBase.cpp`; after validator `000000002912` and current generated header `000000002926`, all four appear under UID `0001WS`. |
| `0002RP` suffix checks are reconstructable | Decompile at `0x00583140` and `0x005831c0` | Insert ANSI/wide suffix methods; depend on `0003NT` | `applied` - `by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md` is `88/90`, emits `EndsWithAnsi`/`EndsWithWide`, and records the `0003NT` byte comparator dependency. Generated `StringBase.cpp` includes UID `0002RP`. |
| `0003NT` is needed support | Sole direct xref from ANSI suffix | Insert byte range comparator and route from target/support | `applied` - `by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md` is `88/90` and emits `CompareAnsiRange`; `by-file/StringBase.md`, `StringBaseTemplate.md`, and support aggregates link it. Generated `StringBase.cpp` includes UID `0003NT`. |
| `0002LJ`/`0002LK` constructors are reconstructable | Decompile at `0x00583210`/`0x00583280` | Insert ANSI/wide varargs constructor routes | `applied` - both constructor pages are `88/91` with `CANONICAL_OWNER:0001WS`; `0002LK` was rerouted to match `0001WS` ownership. Formal `InitializeAnsiFormat` and `InitializeWideFormat` C++ is present in each child and appears in generated `StringBase.cpp` after the `0001WS [[CHILDREN]]` route fix. |
| `0002LL`/`0002LM` workers are reconstructable | Decompile at `0x00583720`/`0x00583840` | Insert ANSI/wide VFormat workers | `applied` - both worker pages are `88/91` with formal `AnsiVFormat`/`WideVFormat` C++ and current MCP caller/callee/sentinel/header evidence. Generated `StringBase.cpp` includes UIDs `0002LL` and `0002LM` after the `0001WS [[CHILDREN]]` route fix. |
| `0002LN`/`0002LO` comparators are reconstructable | Decompile at `0x005840f0`/`0x005845b0` | Insert range and literal comparators | `applied` - `WideRangeCompare.md` is `89/92`, `StringBaseCompareWideLiteral.md` is `88/91`, both emit formal comparator C++, and generated `StringBase.cpp` includes UIDs `0002LN` and `0002LO`. |
| `0003NL` wide search group is reconstructable | MCP component/decompile at `0x005845f0-0x0058490f` | Insert formal wide search/removal methods | `applied` - `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md` is `89/91`, emits the accepted wide search/removal group, and generated `StringBase.cpp` includes UID `0003NL`. |
| `0003NM` splice/grow/substring group is reconstructable | MCP component/decompile at `0x00584990-0x00584d7e` | Insert formal splice/grow/length/substring methods | `applied` - `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md` is `89/91`, emits the accepted splice/grow/reverse-search/length/substring group, and generated `StringBase.cpp` includes UID `0003NM`. |
| Support aggregates contain stale blank/below-threshold wording | Current aggregate docs and prior reports | Refresh only still-stale support text | `applied/already-present` - stale aggregate wording was refreshed in `StringBaseConstructionAndCow.md`, `StringBaseFormatConstructors.md`, `StringBaseReleaseFormatAndMutation.md`, and `StringUtil.md`; `StringBaseSearchSpliceAndSubstring.md` was rechecked and left unedited because its `90/92` mixed-container no-code proof already matched the accepted child split. |

## Implementation Tracking Checklist

Callback implementation state:

- [x] Re-read `Agent-B011/goal.md` and current leases immediately before implementation. Proof: goal file re-read during callback; lease report checked before the validation batch and after release.
- [x] Take leases only for files about to be edited immediately. Proof: B011 leased the changed by-* file set before the main edit/validator batch; the first cleanup attempt after validation reported `Rejected[No active lease]` for each file because the batch lease had already expired. A second single-file lease was taken only for `by-type/by-template/StringBaseTemplate.md` route repair and was released successfully.
- [x] Re-read each target/support file before editing to avoid overwriting concurrent edits. Proof: each listed target/support file was read in the implementation pass; the mixed `StringBaseSearchSpliceAndSubstring.md` page was read and left unedited because its no-code split proof was already current.
- [x] Update `by-file/StringBase.md` metadata to `91/90` and add family-resolution details. Proof: header now has `COMPLETION:91`, `CONFIDENCE:90`, `CANONICAL_OWNER:FILE`; status/change notes list accepted family UIDs, `0003NT`, route/layout marker decisions, rejected alternatives, and MCP provenance.
- [x] Update `by-global/StringBufferSentinelsAndPools.md` with `0000TM` formal globals and current MCP evidence. Proof: page is `93/91`, formal block emits sentinel storage, sentinel pointers, whitespace literal, and eight pool declarations; change log cites current MCP bytes/xrefs and storage.
- [x] Update `by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md` with zero-filled storage evidence and `0000TM` route marker. Proof: page is `91/91`, routes through `0000TM`, and replaces stale byte wording.
- [x] Update `by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md` with `0000TM` route marker. Proof: page is `90/92`, routes through `0000TM`, and records sentinel/whitespace pointer evidence.
- [x] Update `by-type/by-struct/RefCountedStringBufferHeader.md` with formal struct declaration. Proof: page is `90/91` and generated `StringBase.cpp` includes UID `0001VQ`.
- [x] Update `by-type/by-struct/SimpleUStringPointerBackedLayout.md` with layout-only marker and no-improvement proof. Proof: page is `87/89`, formal block is marker-only, and generated `StringBase.cpp` includes UID `0001W4`.
- [x] Update `by-type/by-template/StringBaseTemplate.md` with template owner marker, score, and formal child inventory. Proof: page is `88/91`; marker block now includes `[[CHILDREN]]` so `0001WS` remains no full template shell while exact `0001WS` children surface in generated `StringBase.cpp`.
- [x] Update `by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md` with formal suffix helpers and `0003NT` dependency. Proof: page is `88/90`, formal `EndsWithAnsi`/`EndsWithWide` block populated, generated UID `0002RP` present.
- [x] Update `by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md` with formal ANSI format constructor. Proof: page is `88/91`, formal `InitializeAnsiFormat` populated, generated UID `0002LJ` present after `0001WS [[CHILDREN]]` route fix.
- [x] Update `by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md` with formal wide format constructor and owner/emitter `0001WS`. Proof: page is `88/91`, `CANONICAL_OWNER:0001WS`, `EMITTER_UIDS:0001WS`, formal `InitializeWideFormat` populated, generated UID `0002LK` present after route fix.
- [x] Update `by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md` with formal ANSI VFormat worker. Proof: page is `88/91`, formal `AnsiVFormat` populated, generated UID `0002LL` present after route fix.
- [x] Update `by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md` with formal wide VFormat worker. Proof: page is `88/91`, formal `WideVFormat` populated, generated UID `0002LM` present after route fix.
- [x] Update `by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md` with formal byte range comparator. Proof: page is `88/90`, formal `CompareAnsiRange` populated, generated UID `0003NT` present.
- [x] Update `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md` with formal wide range comparator. Proof: page is `89/92`, formal `WideRangeCompare` populated, generated UID `0002LN` present.
- [x] Update `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md` with formal wide literal comparator. Proof: page is `88/91`, formal `CompareWideLiteral` populated, generated UID `0002LO` present.
- [x] Update `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md` with formal wide search/removal helper group. Proof: page is `89/91`, formal wide search/removal group populated, generated UID `0003NL` present.
- [x] Update `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md` with formal splice/grow/length/substring helper group. Proof: page is `89/91`, formal splice/grow/reverse-search/length/substring group populated, generated UID `0003NM` present.
- [x] Refresh `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md` if it still has stale `0002RP`/`0003NT` text. Proof: page refreshed as non-emitting aggregate with `0002RP` formal C++ and `0003NT` dependency noted.
- [x] Refresh `by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md` if it still has stale `0002LJ`/`0002LK` blank text. Proof: page refreshed as non-emitting aggregate with formal `0002LJ`/`0002LK` constructor children.
- [x] Refresh `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md` if it still has stale child blank text. Proof: page refreshed as non-emitting map with `0002LL`, `0002LM`, `0003NT`, `0002LN`, `0002LO`, `0003NL`, and `0003NM` formal child states.
- [x] Check `by-memory/0x005845f0-0x00584d7e.StringBaseSearchSpliceAndSubstring.md`; edit only if it contradicts accepted child formal bodies. Proof: already-present state kept; page remains `90/92`, `RECONSTRUCTABLE:FALSE`, blank emitters, and points to exact child C++ pages.
- [x] Check `by-file/StringUtil.md`; edit only if it contradicts StringBase ownership. Proof: refreshed cross-reference-only pointer-backed StringBase wording and preserved `StringUtil` as broad utility-string context.
- [x] Run scoped validators for every changed by-* file from `source-3/project-documentation`. Proof: validator table below; all changed by-* files exited `0` with `ok: 1`.
- [x] Use `--wait-generated` on target/file validators where generated `NexusTK/util/StringBase.cpp` freshness matters. Proof: initial final target wait command `000000002826` completed, then route-fix validator `000000002912` completed with foreground generated refresh and explicitly refreshed UID `0000OA` `auto-generated/NexusTK/util/StringBase.cpp`.
- [x] Confirm generated freshness and absence of the 15 empty markers in `auto-generated/NexusTK/util/StringBase.cpp`. Proof: generated header is `validator-command-id: 000000002926`, `validator-refreshed-at: 2026-06-30T14:28:17-04:00`, which is newer than route-fix validator `000000002912`; grep confirms accepted generated UIDs `0000TM`, `0001VQ`, `0001W4`, `0001WS`, `0002RP`, `0002LJ`, `0002LK`, `0002LL`, `0002LM`, `0003NT`, `0002LN`, `0002LO`, `0003NL`, and `0003NM`. `0002AN` and `000289` are intentionally covered by `0000TM` declarations rather than duplicate generated UID blocks.
- [x] Release all leases immediately after edit/validator batch. Proof: main batch unlease attempt found no active lease because the lease had expired before cleanup; route-fix `StringBaseTemplate.md` lease released successfully. Final lease report shows no active B011 leases.
- [x] Update this report's Claim And Incorporation Ledger and Implementation Tracking Checklist with applied/already-present/excluded proof. Proof: this section updated during callback after generated route/freshness verification.
- [x] Return implementation checkpoint with changed files, leases used/released, validator command IDs/timestamps/exit codes/ok counts, generated freshness, and unchecked/deferred items.

## Validator Results From Callback

Working directory for all commands: `E:/NTK/GhidraBridge/source-3/project-documentation`.

| File | Command id | Timestamp | Exit | OK | Generated state |
|---|---|---|---:|---:|---|
| `by-file/StringBase.md` | `000000002771` | `2026-06-30T14:11:52-04:00` | 0 | 1 | deferred |
| `by-global/StringBufferSentinelsAndPools.md` | `000000002773` | `2026-06-30T14:11:57-04:00` | 0 | 1 | deferred |
| `by-memory/0x0069bacc-0x0069bc0c.StringBufferPoolStaticStorage.md` | `000000002776` | `2026-06-30T14:12:07-04:00` | 0 | 1 | deferred |
| `by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md` | `000000002780` | `2026-06-30T14:12:20-04:00` | 0 | 1 | deferred |
| `by-type/by-struct/RefCountedStringBufferHeader.md` | `000000002783` | `2026-06-30T14:12:33-04:00` | 0 | 1 | deferred |
| `by-type/by-struct/SimpleUStringPointerBackedLayout.md` | `000000002786` | `2026-06-30T14:12:47-04:00` | 0 | 1 | deferred |
| `by-type/by-template/StringBaseTemplate.md` | `000000002789` | `2026-06-30T14:12:59-04:00` | 0 | 1 | deferred |
| `by-memory/0x00583140-0x00583206.StringBaseSuffixChecks.md` | `000000002792` | `2026-06-30T14:13:13-04:00` | 0 | 1 | deferred |
| `by-memory/0x00583210-0x00583273.StringBaseAnsiFormatCtor.md` | `000000002795` | `2026-06-30T14:13:26-04:00` | 0 | 1 | deferred |
| `by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md` | `000000002798` | `2026-06-30T14:13:40-04:00` | 0 | 1 | deferred |
| `by-memory/0x00583720-0x00583832.StringBaseAnsiVFormatWorker.md` | `000000002801` | `2026-06-30T14:13:53-04:00` | 0 | 1 | deferred |
| `by-memory/0x00583840-0x00583968.StringBaseWideVFormatWorker.md` | `000000002804` | `2026-06-30T14:14:06-04:00` | 0 | 1 | deferred |
| `by-memory/0x00584060-0x005840ea.StringBaseByteRangeCompare.md` | `000000002807` | `2026-06-30T14:14:19-04:00` | 0 | 1 | deferred |
| `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md` | `000000002810` | `2026-06-30T14:14:31-04:00` | 0 | 1 | deferred |
| `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md` | `000000002813` | `2026-06-30T14:14:46-04:00` | 0 | 1 | deferred |
| `by-memory/0x005845f0-0x0058490f.StringBaseWideSearchHelpers.md` | `000000002816` | `2026-06-30T14:15:00-04:00` | 0 | 1 | deferred |
| `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md` | `000000002819` | `2026-06-30T14:15:12-04:00` | 0 | 1 | deferred |
| `by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md` | `000000002821` | `2026-06-30T14:15:26-04:00` | 0 | 1 | deferred |
| `by-memory/0x00583210-0x005832f0.StringBaseFormatConstructors.md` | `000000002823` | `2026-06-30T14:15:28-04:00` | 0 | 1 | deferred |
| `by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md` | `000000002824` | `2026-06-30T14:15:42-04:00` | 0 | 1 | deferred |
| `by-file/StringUtil.md` | `000000002825` | `2026-06-30T14:15:45-04:00` | 0 | 1 | deferred |
| `by-file/StringBase.md --wait-generated` | `000000002826` | `2026-06-30T14:15:47-04:00` | 0 | 1 | completed; exposed that `0001WS` needed `[[CHILDREN]]` for child bodies |
| `by-type/by-template/StringBaseTemplate.md --wait-generated` | `000000002912` | `2026-06-30T14:25:13-04:00` | 0 | 1 | completed; generated `StringBase.cpp` refreshed foreground |

Relevant validator warnings/side effects:

- Initial scoped file validators reported `projected_stats_update` and deferred generated refreshes.
- The `000000002826` target wait command completed generated refresh and reported unrelated existing autogen warnings for `DDError`, `ErrorMessage`, `FileError`, `InternetError`, `MyError`, `PasswordError`, `WSAError`, `Win32Error`, `PhoneBookListPane`, `SelfLookPane`, and `SelfSaveOKPane`.
- The `000000002912` route-fix wait command rebuilt autogen registry state, refreshed generated C++ metadata for many source roots including `0000OA`, and created validator-owned autogen backups under `tools/validator_autogen_backup/20260630-142525`, `20260630-142528`, and `20260630-142530`. These were validator side effects, not manual edits.

## Callback Closeout

Implementation is complete for supervisor verification. No generated files, generated reports, coverage reports, validator state, IDA DB, executed archives, supervisor ledgers, or lock files were manually edited. No unchecked implementation blockers remain.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0000OA-StringBase-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0000OA-StringBase-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T14:31:51","uid":"0000OA"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000OA-StringBase-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0000OA-StringBase-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000OA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
