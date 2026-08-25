** TARGET-REPORT-UID:00030X **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Report - [UID:00030X] WideFormatWrapper128 Source Quality

Assignment ID: `B002-report-00030X-wide-format-wrapper128-20260624`

Target: `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md`

Required report path: `tools/leaser/Agents/Agent-B002/research/00030X-WideFormatWrapper128-source-quality.md`

Status: `FINISHED_REPORT_READY`

## Recommendation

Recommended target disposition:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000OB` (`StringUtil`) | `NONE` |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000OB` | blank |
| `RECONSTRUCTION_CPP` | blank | blank |
| Target path | `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md` | keep path/name for UID stability; retitle body as reviewed MSVC/UCRT fixed-128 secure wide-format support |

The target should be corrected from a source-emitting `StringUtil` helper to reviewed non-emitting MSVC/UCRT secure wide-format support for a 128-wide-character destination buffer. The source-level operation belongs in the single caller, [UID:0002DL] `FittingRoomListPane::OnPaint`, as normal secure wide formatting of its local `wchar_t Src[128]` buffer. The binary helper body itself is CRT/header/toolchain support and should not emit through `StringUtil.cpp`.

This is a score and metadata improvement, not an unchanged-score exception. The previous blockers were source-facing helper name/signature, StringUtil ownership, and blank C++ policy. Current MCP evidence plus local UCRT header evidence resolves those blockers for this target.

## Current Target State Checked

Current page `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md` records:

- UID: `00030X`
- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000OB`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000OB`
- blank formal `RECONSTRUCTION_CPP CODE`
- summary: fixed `0x80` wide-character CRT formatting wrapper, one fitting-room paint caller, assigned to `StringUtil`, with C++ blank until the wider `StringUtil` wrapper/source split is source-quality.

The page's binary facts are mostly correct. The source-quality conclusion is the stale part: this target is better modeled as non-emitting CRT/UCRT secure-format support, not a project-owned `StringUtil` source function.

## MCP Evidence

Mandatory IDA MCP evidence was refreshed with current session `80de0a67`; this report is not fallback-only.

MCP session status:

- `idb_list`: one active worker session, `80de0a67`, owned/adopted, `is_analyzing:false`.
- `server_health database=80de0a67`: `status:ok`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input binary recorded by MCP: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Module: `NexusTK.exe`.
- Imagebase: `0x400000`.
- Auto-analysis ready: true.
- Hex-Rays ready: true.
- Strings cache ready: true.

Boundary and function checks:

| Address | MCP result |
| --- | --- |
| `0x0042122b` | not a function |
| `0x00421230` | `sub_421230`, size `0x2d` |
| `0x0042125c` | inside `sub_421230` |
| `0x0042125d` | not a function |
| `0x00421260` | `sub_421260`, size `0x30` |
| `0x0042128f` | inside `sub_421260` |
| `0x00421290` | `sub_421290`, size `0x71` |

Target bytes for `0x00421260-0x00421290`:

```text
55 8b ec 8d 45 10 50 6a 00 ff 75 0c 68 80 00 00 00 ff 75 08 e8 27 a7 ff ff ff 70 04 ff 30 e8 92 10 1b 00 83 c9 ff 83 c4 1c 85 c0 0f 48 c1 5d c3
```

Adjacent bytes:

- `0x0042125d-0x00421260`: three bytes, all `0xcc`.
- `0x00421290` begins `sub_421290`; there is no trailing padding after `00030X`.
- `0x0042122b-0x00421230`: five bytes, all `0xcc`, preceding sibling [UID:00030V].

Disassembly semantics:

| Address | Instruction role |
| --- | --- |
| `0x00421263-0x00421266` | builds and pushes the varargs list from `[ebp+0x10]`. |
| `0x00421267` | pushes null locale. |
| `0x00421269` | pushes caller-provided format argument. |
| `0x0042126c` | pushes fixed destination count `0x80`. |
| `0x00421271` | pushes caller-provided destination buffer. |
| `0x00421274` | calls `sub_41B9A0`, the local stdio-options accessor. |
| `0x00421279-0x0042127c` | pushes the two option dwords from the returned storage. |
| `0x0042127e` | calls `___stdio_common_vswprintf_s`. |
| `0x00421283-0x0042128b` | loads `-1`, restores stack, tests formatter result, and conditionally selects `-1` for negative results. |
| `0x0042128e-0x0042128f` | plain epilogue and return. |

Hex-Rays cross-check:

- prototype shape: `int sub_421260(wchar_t *Buffer, wchar_t *Format, ...)`;
- starts a `va_list`;
- calls `sub_41B9A0`;
- calls `__stdio_common_vswprintf_s` with local options, `Buffer`, fixed count `0x80`, `Format`, null locale, and the `va_list`;
- returns `-1` when the common backend returns a negative result and otherwise returns the backend result.

Target callees:

- [UID:0000WO] `0x0041b9a0` / `sub_41B9A0`, documented CRT/UCRT local stdio option storage support.
- `___stdio_common_vswprintf_s` at `0x005d2315`.

Target xrefs:

| Call site | Containing function | Meaning |
| --- | --- | --- |
| `0x0041f89b` | [UID:0002DL] `0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint` | Formats/copies one item-name string into local `wchar_t Src[128]` before `SimpleUString` assignment, tokenization, and wrapped text drawing. |

Caller context from MCP decompilation of `0x0041f2b0`:

- local stack has `wchar_t Src[128]` and `wchar_t Buffer[32]`;
- call is `sub_421260(Src, L"%s", v20 + 10)` at `0x0041f89b`;
- result is immediately consumed by `sub_421590(..., Src, wcslen(Src))`;
- tokenization uses `wcstok`;
- the 32-wide sibling [UID:00030V] is used later for recombining one or two tokens into `Buffer[32]`.

Negative route checks:

- `xrefs_to 0x00421260`: exactly one code xref at `0x0041f89b`.
- `xref_query 0x00421260 type=data`: zero data xrefs.
- `find type=code_ref target 0x00421260`: exactly `0x0041f89b`.
- `find type=data_ref target 0x00421260`: zero matches.
- `find type=immediate` for VA `0x00421260`, interior/tail VAs, and RVA `0x00021260`: zero immediate matches.
- `find_bytes` for VA encodings `60 12 42 00`, `61 12 42 00`, `8f 12 42 00`, and `90 12 42 00`: zero matches.
- `find_bytes` for target full body: unique match at `0x00421260`.
- `find_bytes` for `cc cc cc` plus the target prefix: unique match at `0x0042125d`.
- `find_bytes` for RVA-style bytes `60 12 02 00`: one hit at `0x0049841c`; follow-up `lookup_funcs/get_bytes/disasm/xref_query` classifies it as the four-byte relative displacement of a `call` instruction inside `sub_498270`, not as a data pointer or table route to `0x00421260`. It has no xrefs of its own and computes a different call target.

## Wrapper Family Recheck

Current MCP rechecked the fixed wide-format family:

| UID / address | Fixed count | Current route | Current evidence from this pass |
| --- | ---: | --- | --- |
| [UID:00030V] `0x00421230-0x0042125d` | `0x20` | `StringUtil` in current docs | Same callee pair and negative-normalization body; four code xrefs from fitting-room and macro edit-control paint paths. |
| [UID:00030X] `0x00421260-0x00421290` | `0x80` | `StringUtil` in current docs | Same callee pair and fixed-count body; one code xref from fitting-room paint. |
| [UID:0002UA] `0x004236e0-0x00423710` | `0x104` | `StringUtil` in current docs | Same callee pair and fixed-count body; broad fitting-room/minimap/map/screenshot caller fan-in. |
| [UID:0003X8] `0x0045ef20-0x0045ef50` | `0x100` | `StringUtil` in current docs | Same callee pair and fixed-count body; ranking/screenshot/user-list caller spread. |

The body pattern alone does not prove project-authored `StringUtil` ownership. The project already classifies [UID:0000WO] `0x0041b9a0-0x0041b9de` as CRT/UCRT support and `by-memory/-ignored.md` also classifies `0x0045f950-0x0045f97d` as a fixed-`0x40` `__stdio_common_vswprintf_s` wrapper that should be procured from MSVC/UCRT behavior rather than handwritten product source. The current target is the same source-shape class: a fixed-buffer secure wide-format header/runtime artifact.

The sibling pages remain useful support evidence, but this report's implementation recommendation is target-specific for [UID:00030X]. Sibling metadata should not be changed unless the supervisor explicitly accepts sibling-specific repairs. Support text should, however, stop using the old `StringUtil` wrapper-family assumption as proof that [UID:00030X] emits through `StringUtil.cpp`.

## UCRT/Header Evidence

Local SDK headers were checked to resolve the previous source-facing API blocker:

- `C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\ucrt\corecrt_stdio_config.h`
- `C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\ucrt\corecrt_wstdio.h`
- `C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\ucrt\corecrt.h`

Relevant current-header facts:

- `corecrt_stdio_config.h:89-92` defines a noinline inline local printf-options accessor returning static option storage. This matches `sub_41B9A0`.
- `corecrt_stdio_config.h:110` defines the internal local printf-options macro through that accessor.
- `corecrt_wstdio.h:1017-1024` declares `__stdio_common_vswprintf_s` with options, destination buffer, destination count, format, locale, and `va_list`.
- `corecrt_wstdio.h:1246-1262` defines the locale-aware secure wide `va_list` path by calling the common backend with local options and returning `-1` on negative results.
- `corecrt_wstdio.h:1268-1279` routes the non-locale secure wide `va_list` path through the locale-aware helper with null locale.
- `corecrt_wstdio.h:1493-1508` and `1515-1529` show the varargs secure wide formatting wrappers building a `va_list`, forwarding through the secure `va_list` path, ending the list, and returning the result.

No exact original compiler/header version is asserted. These local headers are source-shape evidence for how the observed binary body is produced: local stdio options, `__stdio_common_vswprintf_s`, null locale, fixed destination count, and negative-result normalization are CRT/header mechanics rather than NexusTK policy.

## Prior Reports and Leads Checked

Checked as leads, not as primary proof:

- Current target page and support docs in `by-memory`, `by-file`, `by-class`, and `by-meta`.
- `auto-generated/-ag-research-tracker.md`, which lists [UID:00030X] as reconstructable `85/88` with direct report count `0`.
- Executed B001 aggregate report `executed-b-agent-research/B001/0002DR-FittingRoomSelectionVectorHelpers.md`, which originally recommended `StringUtil` for [UID:00030X] after the page cleared the old child gate.
- Active B001 sibling report `tools/leaser/Agents/Agent-B001/research/00030V-WideFormatWrapper32-source-quality.md`, treated only as an unaccepted clue. This B002 report independently rechecked [UID:00030X] through MCP and local headers.
- `by-memory/-ignored.md`, which already treats [UID:0000WO] and a fixed `0x40` secure-wide wrapper as CRT/UCRT support.
- Generated output `auto-generated/NexusTK/util/StringUtil.cpp`, which currently emits only empty markers for `00030V`, `00030X`, `0002UA`, and `0003X8`; generated output is not primary proof, but it confirms the current `StringUtil` route is not producing meaningful C++.

## Positive Evidence

- Exact function boundary `0x00421260-0x00421290` confirmed by MCP `lookup_funcs`.
- Target body has one basic block, 18 instructions, and no hidden branch or embedded child function.
- Raw bytes and unique full-body byte signature are confirmed.
- Leading internal padding `0x0042125d-0x00421260` is three `0xcc` bytes; successor `0x00421290` starts the next modeled function.
- Direct code xref set is exactly one call site at `0x0041f89b` inside [UID:0002DL].
- No data xrefs, no VA pointer bytes, no RVA data-pointer route, no vtable/callback route, and no interior/tail xrefs were found for the target.
- The single caller uses a stack `wchar_t Src[128]`, matching the fixed count `0x80`.
- Callee pair is only the CRT local stdio-options accessor and `___stdio_common_vswprintf_s`.
- Return behavior is the CRT secure-format convention: negative result becomes `-1`, nonnegative result passes through.
- Local UCRT header evidence explains the whole body, including local options, null locale, destination count, `va_list`, common backend, and negative-result normalization.
- Current project docs already classify the underlying stdio option/common-backend glue as non-emitting CRT/UCRT support.

## Negative Evidence and Rejected Alternatives

- No evidence supports a handwritten NexusTK source function named `WideFormatWrapper128`, `FormatWide128`, or `StringUtil::FormatWide128`. Those are descriptive reverse-engineering names.
- No non-fitting-room caller was found for [UID:00030X]. The single caller is fitting-room paint, but caller locality does not make the helper fitting-room-owned product logic.
- No fitting-room state, fields, globals, item-entry layout, vtables, or resource strings appear in the target body.
- No `StringUtil` state, `SimpleUString` layout, string pool, `StringBase`, vector, or iterator behavior appears in the target body.
- No pointer/data route supports a source-visible function object or callback.
- The one RVA-style byte hit was an unrelated call displacement inside `sub_498270`, not a pointer to [UID:00030X].
- The mixed [UID:0002DR] aggregate cannot own this target; it is already a non-emitting audit container over exact children with different source routes.
- The current `StringUtil` route was based on wrapper-family similarity and sibling routing, not on source-authoring proof. The header/runtime evidence now explains the wrapper-family similarity without a project `StringUtil` function.
- Emitting a formal `StringUtil` C++ helper would create an artificial project API and would duplicate CRT/header code that the source compiler/runtime should regenerate from ordinary secure formatting at the caller.

## Heuristic and Inference Reanalysis

The previous score cap came from unresolved source name/API and source placement. Current evidence resolves those blockers:

- Source-facing operation: secure wide formatting into the caller's fixed `wchar_t[128]` buffer.
- Binary helper role: MSVC/UCRT secure wide-format support generated from header/runtime formatting machinery.
- Fixed count: `0x80` is the destination element count for `Src[128]`, not a `StringUtil` policy constant and not a fitting-room field.
- `sub_41B9A0`: local CRT printf-options storage, already documented as runtime glue.
- `___stdio_common_vswprintf_s`: CRT backend, not NexusTK product library code.
- Return behavior: `-1` on negative runtime result.
- Final name: keep `WideFormatWrapper128` as a documentation/search label if needed, but do not promote it to a source function name.
- Source placement: [UID:0002DL] should represent the caller expression; [UID:00030X] should be a non-emitting helper artifact.
- Owner/emitter: `NONE` / blank emitters is stronger than [UID:0000OB] because the target itself has no product-owned logic.

This satisfies the stricter Rule 26 requirement: the report does not leave "source route unresolved" or "needs future StringUtil split" as a blocker. It resolves the target route now and gives an implementation-ready metadata repair.

## Ranked Ownership and Source Placement Candidates

1. Recommended: non-emitting MSVC/UCRT secure wide-format support, `CANONICAL_OWNER:NONE`, no emitters.

   For: exact body is local stdio options plus `__stdio_common_vswprintf_s`, fixed `0x80`, null locale, `va_list`, and negative normalization. UCRT headers explain the source shape. There is no product state or source-visible helper route. Source should be represented in the caller method and runtime/header behavior should regenerate the helper.

   Against: the function has a real executable range, and current docs route it through `StringUtil`. This is not enough to keep emission because the body is pure runtime/header support and current generated `StringUtil.cpp` only emits an empty marker.

2. Rejected as direct owner/emitter: [UID:0000OB] `StringUtil`.

   For: broad `StringUtil` docs currently group fixed-capacity wide-format wrappers, and sibling wrappers share the same body pattern.

   Against: the target has no `StringUtil` state or project string-layout behavior. Header evidence explains the body as secure CRT support. The old route was an inference from wrapper similarity and should be superseded for [UID:00030X].

3. Rejected as direct owner: [UID:000053] `FittingRoomListPane`.

   For: one direct caller at `FittingRoomListPane::OnPaint`, and the fixed count matches the caller's local buffer.

   Against: the target does not read/write the class, does not encode fitting-room policy, and is best represented as formatting support emitted for the caller expression. The class owns the source statement, not the emitted helper artifact.

4. Rejected as direct owner: [UID:0000JE] `FittingRoom`.

   For: feature context for the sole caller.

   Against: same as the class route, and weaker because it is only a broad file context. It should receive support text noting consumption, not direct target ownership.

5. Rejected: [UID:0002DR] `FittingRoomSelectionVectorHelpers` aggregate.

   For: physical containment in the old helper island.

   Against: the aggregate is a reviewed non-emitting container. It cannot own an exact child as product source, and the target's behavior is unrelated to the vector/list-entry children.

6. Rejected: new `FittingRoomFormattingHelpers` or new `StringFormatHelpers` source file.

   For: would group fixed-count formatting helpers by behavior.

   Against: it would create a new project source API from compiler/header artifacts. Existing runtime/header and caller-level source placement explains the target without inventing a file.

## C++ Disposition

Formal `RECONSTRUCTION_CPP CODE` disposition for [UID:00030X]: leave the block blank.

Exact formal block recommendation:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Target-specific no-code proof:

- The target is pure CRT/header secure-format support with no NexusTK-owned fields, state, resources, packet flow, UI policy, or string-container behavior.
- The fixed `0x80` count is explained by the caller's local `wchar_t Src[128]` destination.
- The only route is one direct call from [UID:0002DL]; there is no pointer/data route proving a project API.
- The underlying local-options helper [UID:0000WO] is already non-emitting CRT/UCRT support.
- Local UCRT headers explain the complete function body and return contract.
- Source reconstruction should express the formatting operation in the caller, while the compiler/runtime supplies equivalent helper code. Placing code in [UID:00030X] would hand-author a compiler/runtime artifact and reduce source fidelity.

No draft/example/sample C++ is provided in this report. There is no side-section body snippet to copy.

## Score Rationale

Recommended `90/91`:

- `COMPLETION` rises to `90` because the report resolves exact bounds, bytes, padding, caller set, callee set, fixed count, return behavior, source-shape class, owner/emitter repair, and no-code proof.
- `CONFIDENCE` rises to `91` because the current MCP facts and local header comparison explain the full body. It stays below higher-final levels because the exact original compiler/header version and family-wide sibling metadata repairs are not all accepted in this one target callback.

The target should leave the "Not-Covered Files - Reconstructable" queue after accepted implementation and generated refresh because it is no longer reconstructable NexusTK source.

## Exact Target and Support Doc Changes Recommended

Target page `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md`:

- Keep UID `00030X`.
- Keep the path/name unless the supervisor explicitly wants runtime naming; the primary recommendation is no rename for stable cross-links.
- Set `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
- Keep formal `RECONSTRUCTION_CPP CODE` blank with the exact blank block shown above.
- Rewrite summary/status to identify the page as reviewed non-emitting MSVC/UCRT fixed-128 secure wide-format support consumed by fitting-room paint.
- Add MCP session `80de0a67` evidence: server health, exact boundary, raw bytes, padding/next-function facts, disassembly semantics, decompile shape, one caller, callee pair, unique byte signature, no pointer/data/immediate route, and the unrelated RVA-style byte hit classification at `0x0049841c`.
- Add UCRT header evidence and target-specific no-code proof.
- Replace stale "final C++ waits for wider StringUtil split" wording with the resolved no-code/source-route proof.

Support page `by-file/StringUtil.md`:

- Remove [UID:00030X] from direct emitted `StringUtil` contents.
- Preserve a cross-reference note that [UID:00030X] was historically assigned here by wrapper-family inference, but current B002 evidence resolves it as non-emitting CRT/UCRT fixed-buffer formatting support.
- Add a caution that fixed-count `__stdio_common_vswprintf_s` wrapper similarity is not enough by itself to prove project-authored `StringUtil` source. Do not change sibling metadata for [UID:00030V], [UID:0002UA], or [UID:0003X8] unless separately accepted.

Support page `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md`:

- Update the [UID:00030X] child row from `StringUtil` helper to reviewed non-emitting MSVC/UCRT fixed-128 secure-format support consumed by [UID:0002DL].
- Keep aggregate metadata unchanged: mixed aggregate, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`.
- Preserve [UID:00030Q]/[UID:00030Z] `VectorHelpers`, [UID:00030R]/[UID:00030T] `FittingRoomListPane`, and current sibling facts unless separate reports are accepted.

Support page `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`:

- Update the fitting-room string-helper/callee note so [UID:00030X] is described as fixed-128 secure wide-format support for local `Src[128]`, not as `StringUtil` project source.
- Preserve the source-level paint method C++ and existing behavior summary.

Support page `by-class/FittingRoomListPane.md`:

- Update the `0002DR` boundary caution and method table prose: [UID:00030X] is consumed by `OnPaint` as non-emitting CRT/UCRT support, and this class still does not own the helper artifact.
- Preserve direct class ownership for [UID:00030R], [UID:00030T], [UID:00041Q], and [UID:00041R].

Support page `by-file/FittingRoom.md`:

- Update source-context text so fitting-room remains the caller/source-expression owner for the local formatting use, not the direct owner of [UID:00030X].
- Remove any implication that [UID:00030X] remains emitted through `StringUtil`.

Support page `by-memory/-ignored.md`:

- Add a reviewed non-emitting row for `0x00421260-0x00421290` / [UID:00030X] as MSVC/UCRT fixed-128 secure wide-format support.
- Update the existing [UID:0002DR] aggregate ignored row so it no longer says [UID:00030X] routes to `StringUtil`.
- Preserve padding rows at `0x0042125d-0x00421260` and the broader aggregate no-emitting rule.

Support page `by-meta/client_libraries.md`:

- Add a short MSVC CRT/STL support note that [UID:00030X] is now a confirmed non-emitting fixed-buffer secure wide-format helper in the same runtime/header family as [UID:0000WO].

Optional support-only caveat pages, if supervisor wants family consistency without sibling metadata changes:

- `by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md`
- `by-memory/0x004236e0-0x00423710.WideFormatWrapper.md`
- `by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md`

For these, add only a caution that [UID:00030X] has been resolved as CRT/UCRT support and that sibling body similarity is not standalone project-helper proof. Do not change their scores, owners, reconstructable flags, or C++ unless separately accepted.

No generated files, project-level generated reports, validator state, IDA DB, or `-coverage-report.md` files should be edited.

## Supervisor-Owned Coverage Text

Recommended generated/manual coverage replacement text for supervisor-owned application after accepted implementation:

`[UID:00030X] 0x00421260-0x00421290.WideFormatWrapper128.md: COMPLETION 90, CONFIDENCE 91, RECONSTRUCTABLE FALSE, CANONICAL_OWNER NONE, EMITTER_UIDS blank, emits_code false; reviewed non-emitting MSVC/UCRT secure wide-format fixed-128 support consumed by FittingRoomListPane::OnPaint local Src[128] formatting. Remove from Not-Covered Files - Reconstructable after generated refresh.`

Manual `-coverage-report.md` edit recommendation: none by B-agent.

## Validator Plan for Implementation Callback

Run each command from `E:\NTK\GhidraBridge\source-3\project-documentation` after accepted by-* edits:

- `python .\tools\validator.py --mode file --file by-memory/0x00421260-0x00421290.WideFormatWrapper128.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-file/StringUtil.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-class/FittingRoomListPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-file/FittingRoom.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-meta/client_libraries.md --apply --queue-timeout 240`

If optional sibling caveat pages are edited under supervisor acceptance, also validate those exact files with the same scoped validator command shape.

Implementation callback must record command id, command timestamp, exit code, ok count, warnings, generated-refresh side effects, and lease release/expiry state.

## Implementation Callback Addendum

Supervisor accepted this report for implementation under assignment `B002-implement-00030X-wide-format-wrapper128-20260624`. The accepted disposition was applied to the listed target/support docs without editing generated reports, project-level generated reports, manual `-coverage-report.md` files, validator state, queue state, lock files, IDA DB, or unrelated files.

### Per-File Incorporation Proof

- `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md`: metadata set to `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal `RECONSTRUCTION_CPP CODE`; body now records the MCP session `80de0a67` server/IDB provenance, exact boundaries, raw bytes, padding, disassembly/decompile semantics, caller/callee route, unique byte signature, no pointer/data/immediate route, unrelated `0x0049841c` rel32 classification, UCRT header route, no-code proof, rejected ownership/source-placement alternatives, and score rationale at report-level detail.
- `by-file/StringUtil.md`: [UID:00030X] was removed from direct emitted `StringUtil` contents and retained only as superseded/historical cross-reference context; the page now warns that fixed-count `__stdio_common_vswprintf_s` wrapper similarity alone does not prove project-authored `StringUtil` source. Sibling metadata was intentionally left untouched.
- `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md`: [UID:00030X] child/narrative now classifies the range as reviewed non-emitting MSVC/UCRT fixed-128 secure-format support consumed by [UID:0002DL]; aggregate mixed/non-emitting metadata is unchanged and child routing preserves [UID:00030Q]/[UID:00030Z] to `VectorHelpers`, [UID:00030R]/[UID:00030T] to `FittingRoomListPane`, and [UID:00030V]/[UID:00030X] as non-emitting runtime/header support.
- `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`: string-helper/callee narrative now treats [UID:00030X] as local fixed-128 secure wide-format support for `Src[128]`, reached at `0x0041f89b`, not direct `StringUtil` source.
- `by-class/FittingRoomListPane.md`: method/source-context row now states that `OnPaint` consumes the reviewed runtime/header helper while the class owns the source expression/caller context, not the helper artifact.
- `by-file/FittingRoom.md`: source-root/source-context text now keeps fitting-room ownership on the caller expression and removes the stale implication that [UID:00030X] is emitted through `StringUtil`.
- `by-memory/-ignored.md`: added the reviewed non-emitting row for `0x00421260-0x00421290` and updated the [UID:0002DR] aggregate ignored note so [UID:00030X] no longer routes to `StringUtil`; adjacent padding facts are preserved.
- `by-meta/client_libraries.md`: added the MSVC CRT/UCRT fixed-buffer secure-format support note tying [UID:00030X] to the same runtime/header family as [UID:0000WO].
- Optional sibling pages `by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md`, `by-memory/0x004236e0-0x00423710.WideFormatWrapper.md`, and `by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md` were intentionally excluded per goal because B001 had an active accepted callback for sibling-family context; no accepted B002 detail required editing them in this callback.

### Validator Results

All validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with exit code `0` and `ok:1`.

| File | Command | command_id | command_timestamp | Exit / ok | Warnings | Generated-refresh / side effects |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md` | `python .\tools\validator.py --mode file --file by-memory/0x00421260-0x00421290.WideFormatWrapper128.md --apply --queue-timeout 240` | `000000000314` | `2026-06-24T08:11:47-04:00` | `0 / ok:1` | none printed | `generated_refresh: deferred`; side effects: `autogen_registry_update:2`, `canonical_owner_update:1`, `completion_update:1`, `confidence_update:1`, `insert_header_blank:1`, `projected_stats_update:1`, `reference_index_add:5`, `reference_index_remove:1`, `stats_rescore_recommended:1`, `stats_row_remove:1`, `uid_link_insert:3`, `uid_link_update:3`. |
| `by-file/StringUtil.md` | `python .\tools\validator.py --mode file --file by-file/StringUtil.md --apply --queue-timeout 240` | `000000000315` | `2026-06-24T08:11:55-04:00` | `0 / ok:1` | none printed | `generated_refresh: deferred`; side effects: `projected_stats_update:1`, `stats_incremental_noop:1`. |
| `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md --apply --queue-timeout 240` | `000000000316` | `2026-06-24T08:12:10-04:00` | `0 / ok:1` | none printed | `generated_refresh: deferred`; side effects: `insert_header_blank:1`, `uid_link_update:2`, `projected_stats_update:1`, `stats_incremental_noop:1`; validator normalized [UID:00030R]/[UID:00030T] links to their renamed pages. |
| `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md` | `python .\tools\validator.py --mode file --file by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md --apply --queue-timeout 240` | `000000000317` | `2026-06-24T08:12:17-04:00` | `0 / ok:1` | none printed | `generated_refresh: deferred`; side effects: `insert_header_blank:1`, `uid_link_insert:1`, `reference_index_add:1`, `projected_stats_update:1`, `stats_incremental_noop:1`. |
| `by-class/FittingRoomListPane.md` | `python .\tools\validator.py --mode file --file by-class/FittingRoomListPane.md --apply --queue-timeout 240` | `000000000318` | `2026-06-24T08:12:29-04:00` | `0 / ok:1` | none printed | `generated_refresh: deferred`; side effects: `projected_stats_update:1`, `stats_incremental_noop:1`. |
| `by-file/FittingRoom.md` | `python .\tools\validator.py --mode file --file by-file/FittingRoom.md --apply --queue-timeout 240` | `000000000319` | `2026-06-24T08:12:42-04:00` | `0 / ok:1` | none printed | `generated_refresh: deferred`; side effects: `projected_stats_update:1`, `stats_incremental_noop:1`. |
| `by-memory/-ignored.md` | `python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240` | `000000000321` | `2026-06-24T08:12:52-04:00` | `0 / ok:1` | none printed | `generated_refresh: deferred`; side effects: `projected_stats_update:1`, `stats_incremental_noop:1`. |
| `by-meta/client_libraries.md` | `python .\tools\validator.py --mode file --file by-meta/client_libraries.md --apply --queue-timeout 240` | `000000000322` | `2026-06-24T08:13:00-04:00` | `0 / ok:1` | none printed | `generated_refresh: deferred`; side effects: `uid_link_update:1` for [UID:0000WO], `reference_index_add:2`, `projected_stats_update:1`, `stats_incremental_noop:1`. |

Validator-generated refresh was reported as deferred for every scoped file command. I did not manually edit generated/project-level files; the side effects above are validator-owned `--apply` results.

### Coverage / Default Summary Notes For Supervisor

No manual `-coverage-report.md` file was edited. During validation, the validator restored coverage/default-derived stale `Item Summary` text for the target and aggregate because supervisor-owned coverage/default text has not yet been applied. After validators completed, I corrected only the source by-memory `Item Summary` lines under B002 leases and left the supervisor-owned/default text below for application if needed. I did not rerun the scoped validators after the final two-line summary correction because command `000000000314`/`000000000316` had already succeeded and the validator was the source of the stale coverage-default restoration until supervisor-owned/default text is applied.

- Target/default replacement: `[UID:00030X] 0x00421260-0x00421290.WideFormatWrapper128.md: COMPLETION 90, CONFIDENCE 91, RECONSTRUCTABLE FALSE, CANONICAL_OWNER NONE, EMITTER_UIDS blank, emits_code false; reviewed non-emitting MSVC/UCRT secure wide-format fixed-128 support consumed by FittingRoomListPane::OnPaint local Src[128] formatting. Remove from Not-Covered Files - Reconstructable after generated refresh.`
- Aggregate/default replacement: `[UID:0002DR] 0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md: COMPLETION 88, CONFIDENCE 91, RECONSTRUCTABLE FALSE, CANONICAL_OWNER NONE, EMITTER_UIDS blank, emits_code false; mixed aggregate/audit container with 00030Q/00030Z to VectorHelpers, 00030R/00030T to FittingRoomListPane, and 00030V/00030X as non-emitting MSVC/UCRT secure wide-format support.`

### Lease Proof

- Initial lease check found active B004/B001 conflicts on overlapping support files, so conflicting by-* edits were delayed until those leases cleared.
- Final edit/validator batch lease: B002 leased all eight accepted editable files at `2026-06-24T12:11:39Z` with expiry `2026-06-24T12:16:39Z`.
- Release command after validation: `python .\tools\leaser\leaser.py B002 unlease by-memory/0x00421260-0x00421290.WideFormatWrapper128.md by-file/StringUtil.md by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md by-class/FittingRoomListPane.md by-file/FittingRoom.md by-memory/-ignored.md by-meta/client_libraries.md`.
- Release result: all eight files were released; `tools/leaser/Agents/current_leases.md` showed no active leases after release.
- Final two-file summary-correction lease: after final readback still showed stale coverage-derived `Item Summary` text in the target and aggregate headers, B002 leased only `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md` and `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md`, corrected those two header lines, and released both with `python .\tools\leaser\leaser.py B002 unlease by-memory/0x00421260-0x00421290.WideFormatWrapper128.md by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md`.

## Implementation Tracking Checklist

- [x] Lease only target/support files immediately before editing, and release the lease immediately after the edit/validator batch. Proof: final B002 validator lease batch covered the eight accepted files and was released after validators; the final two-file summary-correction lease was also released immediately.
- [x] Update `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md` metadata to `90/91`, owner `NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank formal C++. Proof: target metadata and formal block were updated and validator command `000000000314` returned exit `0`, `ok:1`.
- [x] Insert current MCP evidence into the target page: session `80de0a67`, server health, exact bytes, disassembly semantics, decompile shape, raw padding, unique signature, caller table, callee pair, and no pointer/data/immediate route. Proof: target evidence sections contain these details at report-level specificity.
- [x] Insert the refined RVA-style byte-hit classification for `0x0049841c` as an unrelated rel32 call displacement inside `sub_498270`. Proof: target negative-evidence section records this classification.
- [x] Insert UCRT header evidence into the target page: local stdio options accessor, common wide-format backend, null-locale secure path, and negative-result normalization. Proof: target UCRT section records the accepted header route.
- [x] Insert target-specific no-code proof and rejected ownership/source-placement alternatives into the target page. Proof: target no-code/source-placement and rejected-alternatives sections were updated; formal C++ remains blank.
- [x] Update `by-file/StringUtil.md` so [UID:00030X] is no longer direct emitted `StringUtil` content and the old route is preserved as superseded historical context. Proof: `StringUtil.md` now keeps [UID:00030X] only as historical/cross-reference context and validator command `000000000315` returned exit `0`, `ok:1`.
- [x] Update `by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md` child inventory and aggregate narrative for [UID:00030X] as non-emitting CRT/UCRT support. Proof: aggregate child routing and narrative were updated and validator command `000000000316` returned exit `0`, `ok:1`.
- [x] Update `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md` to describe [UID:00030X] as local fixed-128 secure wide-format support consumed by paint. Proof: OnPaint support narrative records `Src[128]` and `0x0041f89b`; validator command `000000000317` returned exit `0`, `ok:1`.
- [x] Update `by-class/FittingRoomListPane.md` and `by-file/FittingRoom.md` to describe [UID:00030X] as caller-consumed CRT/header support, not list-pane/fitting-room-owned source and not `StringUtil` emission. Proof: class/file source-context text was updated; validator commands `000000000318` and `000000000319` returned exit `0`, `ok:1`.
- [x] Update `by-memory/-ignored.md` with reviewed non-emitting support status for `0x00421260-0x00421290`, preserving adjacent padding entries. Proof: reviewed ignored row was added/updated and validator command `000000000321` returned exit `0`, `ok:1`.
- [x] Update `by-meta/client_libraries.md` with the MSVC/UCRT fixed-buffer secure-format support note. Proof: client-library runtime note was added and validator command `000000000322` returned exit `0`, `ok:1`.
- [x] If supervisor accepts optional family caveats, update sibling caveat pages without changing their metadata. Proof: intentionally excluded per current goal because B001 owns active accepted sibling-family callback; no sibling page was edited.
- [x] Run scoped validators for every changed by-* and by-meta support file from `source-3/project-documentation`. Proof: all eight scoped validator commands and metadata are recorded above with exit `0`, `ok:1`.
- [x] Confirm no generated files, project-level generated reports, validator state, IDA DB, or `-coverage-report.md` files were edited manually. Proof: only accepted by-* / by-meta files and this B002 report were manually edited; generated/project-level side effects were validator-owned `--apply` output.
- [x] Leave supervisor-owned coverage text unapplied. Proof: no manual `-coverage-report.md` file was edited; exact supervisor/default text is recorded above.
- [x] Report lease release/expiry state after implementation. Proof: lease proof above records final B002 lease creation, release command, and no-active-lease status.

## Original Report-Only Compliance

- No target/support by-* docs were edited during the original report-only pass.
- No generated files were edited during the original report-only pass.
- No project-level files were edited during the original report-only pass.
- No manual `-coverage-report.md` file was edited.
- No validator state was edited manually.
- IDA DB/tool state was not modified.
- No leases were taken during the report-only research pass.
- No subagents were spawned.
- MCP evidence was mandatory and available through current session `80de0a67`.
- No C++ reconstruction snippet was written outside a formal block; the formal recommendation and accepted implementation keep blank C++ with target-specific no-code proof.

## Supervisor Summary-Gate Resolution

After B002 paused on validator-restored stale `Item Summary` text, the supervisor confirmed the manual `by-memory/-coverage-report.md` rows were already corrected and that the stale text was being restored from validator-owned cached metadata. The supervisor then applied only the remaining source-header summary corrections and validated them with scoped UID-only checks that do not trigger generated-refresh restoration:

- `python .\tools\validator.py --mode file --file by-memory\0x00421260-0x00421290.WideFormatWrapper128.md --uid-only --no-generated-refresh --apply --queue-timeout 240`
  - command_id `000000000411`
  - command_timestamp `2026-06-24T14:39:00-04:00`
  - exit `0`, `ok:1`
  - final source header summary: reviewed non-emitting MSVC/UCRT fixed-128 secure wide-format support consumed by `FittingRoomListPane::OnPaint` caller-local `Src[128]`; no standalone `StringUtil`, fitting-room, aggregate, or formal C++ helper body.
- `python .\tools\validator.py --mode file --file by-memory\0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md --uid-only --no-generated-refresh --apply --queue-timeout 240`
  - command_id `000000000412`
  - command_timestamp `2026-06-24T14:39:06-04:00`
  - exit `0`, `ok:1`
  - final source header summary: mixed aggregate/audit container with exact child routing and [UID:00030V]/[UID:00030X] as non-emitting MSVC/UCRT secure wide-format support.

Supervisor reread after queue idle confirmed both source headers remained corrected. This resolves the summary-gate blocker for report execution without manual edits to validator cache/state, generated reports, or project-level generated files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00030X-WideFormatWrapper128-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-24T14:40:11","uid":"00030X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
