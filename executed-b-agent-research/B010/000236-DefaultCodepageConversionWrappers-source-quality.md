** TARGET-REPORT-UID:000236 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000236 DefaultCodepageConversionWrappers Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](../../../../../by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md) reconstructable and owned/emitted by [UID:0000OA][StringBase](../../../../../by-file/StringBase.md), resolve the StringBase/StringUtil split in favor of `StringBase.cpp`, and populate first-draft C++.
- Final disposition: source-authored, file-local StringBase conversion wrappers; not import thunks, not CRT runtime, not PlatformApi, and not MD5-adjacent ownership.
- Required action after supervisor acceptance: update the target doc with exact source-facing names/signatures and C++, update StringBase/StringUtil/caller support prose, and apply the pending coverage row through supervisor-owned coverage maintenance.
- Recommended score/metadata: `84/90 -> 88/91`, `CANONICAL_OWNER:0000OA` unchanged, `RECONSTRUCTABLE:TRUE` unchanged, `EMITTER_UIDS:0000OA` unchanged.
- Confidence: high for behavior, owner/emitter, and source readiness; medium-high for exact original symbol spelling because no original PDB/source symbols are available and live IDA MCP is unavailable in this session.

## Target

- Target UID: `000236`
- Primary doc: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\000236-DefaultCodepageConversionWrappers-source-quality.md`
- Current target state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000OA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`, blank C++.
- Current generated route: `auto-generated/-ag-memory-coverage.md` emits this UID through `0000OA` into `auto-generated/NexusTK/util/StringBase.cpp`.
- Current generated output symptom: `auto-generated/NexusTK/util/StringBase.cpp` contains only an empty marker for `000236`, not source code.

## Supervisor Active Recheck

- The user assigned this as a B010 report-only source-quality task. I did not edit the target, support docs, generated files, project-level files, or `by-memory/-coverage-report.md`.
- No split repair is needed before the report checkpoint. The range contains two tiny sibling wrappers with the same owner/emitter and a five-byte internal `0xcc` gap already recorded in [UID:0000VN][by-memory/-ignored.md](../../../../../by-memory/-ignored.md).
- Live IDA MCP check attempted through `http://127.0.0.1:13337/mcp` and failed with `IDA_MCP_ERROR: Unable to connect to the remote server`. This report therefore relies on current docs that record the 2026-06-06 live IDA MCP pass, generated coverage, the historical report row, unresolved-name reports, and source-tree evidence.
- Prior executed B001/B002/B010 research search found no report dedicated to `000236`; historical `by-memory/-report.old.md` contains the older Wave2/missing-ref review for these exact two wrappers.

## Executive Recommendation

These wrappers should emit as two `static` helpers in `util/StringBase.cpp`:

```cpp
static int MultiByteToWideDefaultCp(wchar_t *dst,
                                    int dstCount,
                                    const char *src,
                                    int srcCount)
{
    return MultiByteToWideChar(CP_ACP, 0, src, srcCount, dst, dstCount);
}

static int WideCharToMultiByteDefaultCp(char *dst,
                                        int dstCount,
                                        const wchar_t *src,
                                        int srcCount)
{
    return WideCharToMultiByte(CP_ACP, 0, src, srcCount, dst, dstCount, NULL, NULL);
}
```

The old historical "keep non-reconstructable" decision should be superseded. It was correct under the older missing-ref review policy, but current project rules treat source-authored project-facing wrappers as reconstructable when they have a valid owner/emitter route and meet the combined-score gate. This target already meets the gate: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OA`, and `(84 + 90) / 2 = 87`.

## Heuristic / Inference Reanalysis And Validation

### 1. Exact Wrapper Names

- Evidence checked: target page, `by-memory/-report.old.md`, `project-level/-unresolved.md`, `by-memory/-ignored.md`, StringBase/StringUtil docs, and generated output.
- Historical names: `MultiByteToWideDefaultCp_5151B0` and `WideCharToMultiByteDefaultCp_5151D0`.
- Best source-facing names: `MultiByteToWideDefaultCp` and `WideCharToMultiByteDefaultCp`, dropping the address suffix while preserving the old source-role wording.
- Why not `AnsiToWide` / `WideToAnsi`: `CP_ACP` means the effective conversion is ANSI/default process code page, but the wrappers mirror the Win32 API names and accept explicit byte/char counts. The old names already capture the exact API direction with less ambiguity.
- Why not `DefaultCodepage` spelling: acceptable as a documentation alias, but the historical names use `DefaultCp`, and the target title already supplies the spelled-out concept. The implementation should use one naming style consistently; I recommend `DefaultCp` for function names and `default code page / CP_ACP` in prose.
- Confidence: high for descriptive names, medium for original exact spelling.

### 2. Exact Signatures

- `0x005151b0`: IDA decompiles output-first arguments and forwards them to `MultiByteToWideChar`.
  - Source signature: `static int MultiByteToWideDefaultCp(wchar_t *dst, int dstCount, const char *src, int srcCount)`.
  - IDA type signature: `int __cdecl MultiByteToWideDefaultCp(LPWSTR dst, int dstCount, LPCCH src, int srcCount)`.
  - Semantics: `dstCount` is destination wide-character capacity; `srcCount` is input byte count. The return value is the converted wide-character count from Win32.
- `0x005151d0`: IDA decompiles output-first arguments and forwards them to `WideCharToMultiByte`.
  - Source signature: `static int WideCharToMultiByteDefaultCp(char *dst, int dstCount, const wchar_t *src, int srcCount)`.
  - IDA type signature: `int __cdecl WideCharToMultiByteDefaultCp(LPSTR dst, int dstCount, LPCWCH src, int srcCount)`.
  - Semantics: `dstCount` is destination byte capacity; `srcCount` is input UTF-16 character count. The return value is the converted byte count from Win32.
- Rejected signature alternatives:
  - Allocating helpers: rejected because neither wrapper allocates or frees; all buffers are caller-supplied.
  - NUL-terminated only helpers: rejected because explicit lengths are forwarded. Callers handle length measurement and terminator writes.
  - `bool`/void return: rejected because the Win32 conversion count is returned directly and caller docs rely on the count to update string header lengths.

### 3. CP_ACP / Default-Codepage Interpretation

- Evidence checked: decompiled calls pass code page `0` and flags `0`; PlatformApi and many caller docs use the same convention as `CP_ACP`.
- Best interpretation: use `CP_ACP` in C++ and prose while noting the binary literal is `0`.
- Rejected alternative: UTF-8. There is no `CP_UTF8` value, no `MB_ERR_INVALID_CHARS`, no resource-specific code page, and no fallback/default-character pointers beyond the required `NULL, NULL` pair in `WideCharToMultiByte`.
- Source impact: the wrapper names should preserve default-codepage behavior because this is source-significant for Korean/Windows ANSI client text.

### 4. StringBase Versus StringUtil Source Split

- Evidence for StringBase:
  - `auto-generated/-ag-memory-coverage.md` already routes `000236` through `0000OA` to `auto-generated/NexusTK/util/StringBase.cpp`.
  - [UID:0000OA][StringBase](../../../../../by-file/StringBase.md) lists `000236` as thin default-codepage wrappers consumed by string constructors/converters.
  - [UID:0002RM][StringBaseConversionAndCrtShims](../../../../../by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md) documents all direct callers inside the `0x00582500+` ref-counted string conversion constructor cluster.
  - Proposed source tree explicitly says `StringBase.cpp` is preferred for the large ref-counted ANSI/UTF-16 buffer family at `0x00582500-0x00584d7d`.
- Evidence for StringUtil:
  - [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md) is the broad utility-string coordinator and also lists `000236`.
  - `StringUtil.cpp` owns fixed wide-format wrappers and SimpleUString/SSO/vector support.
- Decision: keep direct owner/emitter on StringBase. StringUtil should cross-reference this as coordination context only.
- Rejected alternative: move to StringUtil. It is weaker because every direct caller is in StringBase conversion code, not the fixed-format/SimpleUString utility wrapper family.
- Rejected alternative: attach to PlatformApi. PlatformApi has a separate helper island [UID:000249] for heap-allocating default-codepage platform/MAPI helpers; `000236` is caller-buffer StringBase conversion glue with no heap or dispatch-table behavior.

### 5. Caller / Reachability

Direct callers recorded by the target doc:

| Wrapper | Direct caller | Best descriptive caller role |
| --- | --- | --- |
| `0x005151b0` | `0x00582534` in `sub_582500` | `StringBaseWideFromAnsi` / constructs a wide `StringBase` from counted ANSI input. |
| `0x005151b0` | `0x0058286e` in `sub_582830` | `StringBaseWideFromAnsiString` / converts stored ANSI string data into a wide output object. |
| `0x005151d0` | `0x005825e6` in `sub_5825A0` | `StringBaseAnsiFromWide` / converts stored wide data into ANSI storage. |
| `0x005151d0` | `0x005826e6` in `sub_582680` | `StringBaseWideToAnsiValueShim` / temporary ANSI conversion before calling the value/object conversion helper at `0x005e1b76`. |
| `0x005151d0` | `0x005827b4` in `sub_582770` | `StringBaseAnsiFromWideRaw` / converts raw UTF-16 input into ANSI storage. |

- No direct callers outside the `StringBase` conversion cluster are recorded in the current target doc.
- The old historical row named caller context as `LObject::LObjectFromAnsiToWide`, `LObject::ToWideString`, `LObject::ToAnsiString`, and `Region::Region`; current docs supersede that owner pollution by separating true `LObject` from ref-counted `StringBase`.
- Caller names above are descriptive recommendations for support docs/IDA comments. They should not be treated as recovered original public API names until the full `StringBase` method family receives a source-quality C++ pass.

### 6. Import / Win32 API Wrapper Policy

- The imported APIs remain external dependencies:
  - `MultiByteToWideChar` through import address `0x0060d120`.
  - `WideCharToMultiByte` through import address `0x0060d170`.
- These two wrappers are not import thunks. Each is an executable project helper with its own callers, argument order, and source role.
- These wrappers are not CRT/runtime code. They are source-authored compatibility helpers over Win32 API calls, analogous to the already populated [UID:000249][PlatformStringConversionHelpers](../../../../../by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), but with caller-supplied buffers and StringBase ownership.
- Rejected alternative: leave as non-reconstructable because they are thin wrappers. Thin wrappers still need reconstruction when project source called the wrapper and generated output currently has only an empty marker.

### 7. Range / Split / Merge

- Current half-open target range is correct: `0x005151b0-0x005151ef`.
- Function bodies:
  - `0x005151b0-0x005151cb`, size `0x1b`.
  - `0x005151d0-0x005151ef`, size `0x1f`.
- Internal padding `0x005151cb-0x005151d0` and trailing padding `0x005151ef-0x005151f0` are already recorded in `by-memory/-ignored.md`.
- No child split is recommended. Both wrappers share the same direct owner, source file, purpose, naming policy, and first-draft C++ block. Splitting would add documentation overhead without improving ownership or emission.
- No merge with MD5 is recommended. [UID:0001B6][MD5HashHelpers](../../../../../by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md) explicitly excludes `000236`; adjacency is layout-only.
- No merge with [UID:000235][MapPathDequeSupport](../../../../../by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md) is recommended. That range is non-reconstructable STL/deque support and ends before alignment padding preceding this target.

### 8. C++ Readiness

- Current gate: eligible. `RECONSTRUCTABLE:TRUE`, nonblank emitter `0000OA`, and combined score `87`.
- Names/signatures/source placement are now sufficiently resolved for first-draft C++.
- The C++ should be populated in the target's formal block on implementation callback unless the supervisor chooses different exact names. There is no target-specific no-code proof.

## Evidence Checked

- Primary target doc `by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md`.
- [UID:0000OA][StringBase](../../../../../by-file/StringBase.md), including direct source-root evidence for the ref-counted ANSI/UTF-16 `StringBase` family.
- [UID:0000OB][StringUtil](../../../../../by-file/StringUtil.md), including broad utility-string coordination and the explicit split that delegates ref-counted `StringBase` to `StringBase.cpp`.
- [UID:0002RM][StringBaseConversionAndCrtShims](../../../../../by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md), including caller roles for all five direct wrapper call sites.
- [UID:0001WS][StringBaseTemplate](../../../../../by-type/by-template/StringBaseTemplate.md) and [UID:0001VQ][RefCountedStringBufferHeader](../../../../../by-type/by-struct/RefCountedStringBufferHeader.md).
- `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-file-coverage.md`, confirming valid emission to `StringBase.cpp`.
- `auto-generated/NexusTK/util/StringBase.cpp`, confirming the current target is only an empty emitter marker.
- `by-project-structure/proposed-source-tree.md`, confirming `StringBase.cpp` and `StringUtil.cpp` are both intended utility files and `StringBase.cpp` is preferred for the ref-counted string-buffer family.
- `by-memory/-report.old.md`, confirming the historical descriptive names and stale non-reconstructable conclusion.
- `project-level/-unresolved.md`, confirming unresolved `sub_5151B0`/`sub_5151D0` occurrences are now mostly the target and historical/ignored references.
- [UID:000249][PlatformStringConversionHelpers](../../../../../by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md) and [UID:0000ML][PlatformApi](../../../../../by-file/PlatformApi.md), used to reject PlatformApi ownership for this target and align default-codepage naming policy.
- [UID:0001B6][MD5HashHelpers](../../../../../by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md) and [UID:000235][MapPathDequeSupport](../../../../../by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md), used to reject adjacency-based merge/ownership alternatives.

## Recommended Target Changes

### Metadata

- `COMPLETION:84 -> 88`
- `CONFIDENCE:90 -> 91`
- Keep `CANONICAL_OWNER:0000OA`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000OA`

### Target Prose

- Replace raw `sub_5151B0` / `sub_5151D0` as primary names with `MultiByteToWideDefaultCp` / `WideCharToMultiByteDefaultCp`; keep raw names only as historical IDA aliases.
- Replace "C++ remains blank because final source spelling and the StringBase/StringUtil split are below the 95/95 final-source gate" with the current active-gate statement and accepted first-draft C++ readiness.
- Add explicit rejected alternatives:
  - not `StringUtil` direct ownership;
  - not `PlatformApi`;
  - not MD5 adjacency;
  - not import thunks / CRT runtime;
  - not UTF-8 conversion.
- Add the output-first signature semantics and "caller writes terminator/header length" rule.

### Formal C++

Populate `RECONSTRUCTION_CPP CODE` with:

```cpp
static int MultiByteToWideDefaultCp(wchar_t *dst,
                                    int dstCount,
                                    const char *src,
                                    int srcCount)
{
    return MultiByteToWideChar(CP_ACP, 0, src, srcCount, dst, dstCount);
}

static int WideCharToMultiByteDefaultCp(char *dst,
                                        int dstCount,
                                        const wchar_t *src,
                                        int srcCount)
{
    return WideCharToMultiByte(CP_ACP, 0, src, srcCount, dst, dstCount, NULL, NULL);
}
```

This code intentionally excludes allocation, NUL termination, and header length updates; those belong to the `0x00582500+` StringBase callers.

## Recommended Support Doc Changes

- `by-file/StringBase.md`: update the `000236` row to list exact names/signatures and note that it now emits first-draft source into `StringBase.cpp`.
- `by-file/StringUtil.md`: keep `000236` as a cross-reference in the utility-string family, but explicitly state that direct ownership remains with `StringBase` because every observed caller is in the ref-counted conversion constructor cluster.
- `by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md`: replace raw caller labels near this target with descriptive roles from the caller table above and link `MultiByteToWideDefaultCp` / `WideCharToMultiByteDefaultCp`.
- `by-memory/-ignored.md`: optional support cleanup if leased in an implementation callback. Replace the lowercase raw names in the padding evidence line with `MultiByteToWideDefaultCp` / `WideCharToMultiByteDefaultCp` and keep the raw addresses.
- `project-level/-unresolved.md`: do not edit directly; it should refresh after target/support validation and unresolved-report generation.

## IDA Rename / Type / Comment Recommendations

| Address | Recommendation | Confidence | Notes |
| --- | --- | ---: | --- |
| `0x005151b0` | Rename to `MultiByteToWideDefaultCp` or `StringBase_MultiByteToWideDefaultCp` if a file-prefix convention is preferred. | High descriptive / medium original | Historical name supports this direction; drop `_5151B0` suffix in source docs. |
| `0x005151d0` | Rename to `WideCharToMultiByteDefaultCp` or `StringBase_WideCharToMultiByteDefaultCp`. | High descriptive / medium original | Historical name supports this direction; drop `_5151D0` suffix in source docs. |
| `0x0060d120` | Keep/import-name as `MultiByteToWideChar`. | Very high | Imported Win32 API dependency, not a project helper. |
| `0x0060d170` | Keep/import-name as `WideCharToMultiByte`. | Very high | Imported Win32 API dependency, not a project helper. |
| `0x00582500` | Descriptive caller comment/name: `StringBaseWideFromAnsi` or `StringBaseConstructWideFromAnsi`. | Medium | Caller method final API still belongs to a broader StringBase pass. |
| `0x005825a0` | Descriptive caller comment/name: `StringBaseAnsiFromWide`. | Medium | Uses `WideCharToMultiByteDefaultCp`. |
| `0x00582680` | Descriptive caller comment/name: `StringBaseWideToAnsiValueShim`. | Low-medium | Role is clear; public/source name remains uncertain because it calls `0x005e1b76`. |
| `0x00582770` | Descriptive caller comment/name: `StringBaseAnsiFromWideRaw`. | Medium | Converts raw UTF-16 input into ANSI storage. |
| `0x00582830` | Descriptive caller comment/name: `StringBaseWideFromAnsiString`. | Medium | Converts stored ANSI string to a wide output object. |

IDA type suggestions:

```c
int __cdecl MultiByteToWideDefaultCp(LPWSTR dst, int dstCount, LPCCH src, int srcCount);
int __cdecl WideCharToMultiByteDefaultCp(LPSTR dst, int dstCount, LPCWCH src, int srcCount);
```

IDA comments:

- At `0x005151b0`: `StringBase helper: caller-supplied ANSI/default-codepage bytes -> caller-supplied UTF-16 buffer; CP_ACP (0), flags 0; no allocation or terminator write.`
- At `0x005151d0`: `StringBase helper: caller-supplied UTF-16 span -> caller-supplied ANSI/default-codepage buffer; CP_ACP (0), flags 0, NULL default-char args; no allocation or terminator write.`

## Exact Pending `by-memory/-coverage-report.md` Replacement Row

Replace the existing `000236` row with:

```text
    - [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md) 0x005151b0-0x005151ef | global helpers | DefaultCodepageConversionWrappers : reconstructable : 88% : strong : B010 source-quality reanalysis keeps these two source-authored StringBase-local default-codepage wrappers under [UID:0000OA] StringBase with first-draft C++ readiness: `MultiByteToWideDefaultCp(wchar_t *dst, int dstCount, const char *src, int srcCount)` forwards to `MultiByteToWideChar(CP_ACP, 0, src, srcCount, dst, dstCount)` and `WideCharToMultiByteDefaultCp(char *dst, int dstCount, const wchar_t *src, int srcCount)` forwards to `WideCharToMultiByte(CP_ACP, 0, src, srcCount, dst, dstCount, NULL, NULL)`. Evidence confirms exact `0x1b`/`0x1f` helper bodies, five total direct callers in the StringBase conversion constructor cluster, one Win32 import callee per helper, internal/endpoint padding in `-ignored`, no heap/global state, MD5 adjacency only, and rejected StringUtil/PlatformApi/non-reconstructable-import-thunk alternatives.
```

## Validation Commands Needed After Implementation Callback

Run from `source-3/project-documentation` for every file actually touched:

> Executable block R001 was removed from this report and preserved verbatim in [000236-DefaultCodepageConversionWrappers-source-quality-removed.md](000236-DefaultCodepageConversionWrappers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not run the `by-memory/-ignored.md` command unless that support file is actually edited. Do not edit `by-memory/-coverage-report.md`; supervisor applies the row above.

## Open Questions And Resolution Attempts

- Original exact symbol spelling: not recoverable from current docs or generated output. Historical missing-ref names and wrapper behavior support `MultiByteToWideDefaultCp` / `WideCharToMultiByteDefaultCp` as the best descriptive names. This does not block first-draft C++.
- `StringBase.cpp` versus `StringUtil.cpp`: resolved for this target in favor of StringBase. StringUtil remains broad coordination only.
- Imported API wrapper policy: resolved. The Win32 APIs are imported dependencies; the two wrappers are project-facing source helpers and should emit.
- Caller helper final public names: not fully solved by this target because it belongs to the larger StringBase conversion/COW island. The report provides descriptive caller names and says support docs should use them as roles, not as proven original API names.
- Fresh live IDA: unavailable in this session; current docs already contain the decisive 2026-06-06 IDA evidence. This caps final-audit confidence but does not block implementation.

## Validator Results

- Commands run: none. This was report-only and no target/support docs were edited.
- Expected implementation side effects: `auto-generated/NexusTK/util/StringBase.cpp` should replace the `000236` empty marker with the two static helper functions after target validation/autogen refresh. Generated/project-level files may change as normal validator side effects; implementation should report whether `project-level/-auto-completion-stats.md`, `tools/validator.ini`, or generated files changed.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/000236-DefaultCodepageConversionWrappers-source-quality.md`
- Modified: none
- Renamed: none
- Moved to executed: none
- Leases used: none; no lease is required for B010 research-folder report creation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/000236-DefaultCodepageConversionWrappers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"000236"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000236-DefaultCodepageConversionWrappers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/000236-DefaultCodepageConversionWrappers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000236"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
