** TARGET-REPORT-UID:0002UA **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B005 Source-Quality Report - [UID:0002UA] `WideFormatWrapper`

Assignment: `B005-report-0002UA-wide-format-wrapper-20260624`  
Mode: report-only research first. No by-* docs, generated/project-level files, validator state, IDA DB, leases, or `-coverage-report.md` files were edited.

## Target

- Target UID/path: [UID:0002UA] `by-memory/0x004236e0-0x00423710.WideFormatWrapper.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OB`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`.
- Current target summary: the page is still routed to [UID:0000OB] `StringUtil` as a fixed `0x104` wide-format wrapper, with a 2026-06-24 caveat from [UID:00030V] that same-family fixed-count CRT wrapper bodies can be MSVC/UCRT header support rather than direct `StringUtil` source.
- Current problem: the caveat is now stronger than the old metadata. Current MCP evidence and the already-executed [UID:00030V]/[UID:00030X] sibling corrections support a direct metadata/source-placement repair for [UID:0002UA], not a blank-but-reconstructable `StringUtil` emitter.

## MCP And File Provenance

- MCP endpoint used through JSON-RPC: `http://127.0.0.1:13337/mcp`
- MCP session/database: `80de0a67`
- `idb_list`: one active owned/adopted worker session, `session_id:"80de0a67"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker PID `26892`.
- `server_health database=80de0a67`: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- PE SHA-256 checked from `E:\NTK\Resources\NexusTK\NexusTK.exe`: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Local UCRT source-shape references checked as support evidence only: `corecrt_stdio_config.h` and `corecrt_wstdio.h` under `C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\ucrt\`.

## Current MCP Evidence Checked

Function/range:

- `lookup_funcs` reports `0x004236e0` as `sub_4236E0`, size `0x30`; `0x0042370f` is inside that same function; `0x00423710` starts successor `sub_423710`, size `0x67`.
- `0x004236d7` is not a function. `get_bytes 0x004236d0 size 0x50` shows the previous function ending at `0x004236d7`, then nine `0xcc` bytes at `0x004236d7-0x004236e0`, then the exact target body, then successor bytes beginning at `0x00423710`.
- `make_signature_for_range 0x004236e0-0x00423710` with operands not wildcarded returns a unique 48-byte signature:
  `55 8B EC 8D 45 10 50 6A 00 FF 75 0C 68 04 01 00 00 FF 75 08 E8 A7 82 FF FF FF 70 04 FF 30 E8 12 EC 1A 00 83 C9 FF 83 C4 1C 85 C0 0F 48 C1 5D C3`.
- `find_bytes` for that full body returns exactly one match at `0x4236e0`.

Body/decompile:

- `analyze_function 0x004236e0 include_asm=true` renders prototype `int(wchar_t *Buffer, wchar_t *Format, ...)`.
- Hex-Rays starts a `va_list` from the format argument, calls `sub_41B9A0`, calls `__stdio_common_vswprintf_s(*options, Buffer, 0x104u, Format, 0, va)`, and returns `-1` when the backend result is negative.
- Disassembly is a single basic block with 18 instructions: frame setup, `lea eax,[ebp+ArgList]`, pushes argument list, null locale, format, fixed count `0x104`, destination buffer, calls `sub_41B9A0`, pushes the two option dwords, calls `___stdio_common_vswprintf_s`, loads `-1`, fixes the stack, tests the result, uses `cmovs` for negative-result normalization, then returns.
- Strings/constants in the function are empty except the constants implied by instructions: null locale, fixed count `0x104`, stack cleanup `0x1c`, and `-1`.

Callees:

- Callee set is exactly [UID:0000WO] `0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue` `sub_41B9A0` and `___stdio_common_vswprintf_s`.
- `analyze_function 0x0041b9a0` confirms the accessor is a 6-byte runtime helper returning `&unk_67A730`. It has broad xrefs from other formatting helpers and `___scrt_initialize_default_local_stdio_options`.
- `imports_query` for `*stdio_common_vswprintf_s*` and `*vswprintf*` returns no import-table entries, which matches statically linked CRT/UCRT support rather than a Windows DLL import route.

Xrefs/callers:

- `xrefs_to 0x004236e0 limit=150` returns 48 code xrefs, no truncation. No data xrefs are reported by `xref_query 0x004236e0 direction=to xref_type=data`.
- The 48 code xrefs group as:

| Function/context | Call sites |
| --- | --- |
| `sub_422020` / [UID:0002E7] `FittingRoomDialogItemStateConstructor` | `0x42218c`, `0x4221c9`, `0x4221fd` |
| no-containing-function raw cache-path helper / [UID:0002EA] | `0x422966`, `0x4229a1`, `0x4229d9` |
| `sub_454150` | `0x454294`, `0x4542d1`, `0x45430c` |
| no-containing-function sites after `sub_454150` | `0x454ce8`, `0x454d25`, `0x454d60` |
| `sub_456540` | `0x45658a`, `0x4565cb`, `0x456606` |
| no-containing-function sites in the same map/minimap neighborhood | `0x4567ea`, `0x45682b`, `0x456866`, `0x4569ac`, `0x4569ed`, `0x456a24` |
| `sub_456A90` | `0x456b15`, `0x456b56`, `0x456b8d` |
| `sub_47CD80` | `0x47cdf1`, `0x47ce4d`, `0x47ce93` |
| `sub_4F95B0` / profile path neighborhood | `0x4f962b`, `0x4f966c` |
| `sub_504B90` / map load path | `0x504bee`, `0x504c2d`, `0x504c71` |
| `sub_504E00` / map save path | `0x504e73`, `0x504eb4`, `0x504ef7` |
| `sub_5063E0` | `0x506462`, `0x5064a3` |
| `sub_50ABA0` / save-user-settings path | `0x50ac0a`, `0x50ac4b` |
| no-containing-function screenshot sites | `0x557887`, `0x5578c8`, `0x55796d` |
| `sub_557AA0` / screenshot BMP path | `0x557ae7`, `0x557b28`, `0x557bcd` |
| `sub_557E80` / screenshot PNG/JPEG path | `0x557ecd`, `0x557f0e`, `0x557fb3` |

- `xrefs_to 0x00423710` returns two xrefs to the successor function, not to this target: `0x422415` in `sub_422330` and `0x423800` in the five-byte jump thunk. That supports the successor boundary and does not extend [UID:0002UA].
- `xrefs_to 0x004236d7` returns no xrefs to the predecessor padding start.

Pointer/route negatives:

- `find_bytes` for little-endian VA/RVA encodings `e0 36 42 00`, `e0 36 02 00`, `10 37 42 00`, and `10 37 02 00` returns zero matches. This rejects a table/static pointer route to the target or successor boundary.
- No data xrefs, no import-table symbol, no vtable/callback/global route, and no project state access appears in the function body.

Representative caller-local buffer evidence:

- `stack_frame 0x00422020` shows `pszPath` at stack offset `0x34` and `Buffer` at `0x23c`; those locals are separated by `0x208` bytes, i.e. 260 wide characters. The documented constructor path calls [UID:0002UA] at `0x0042218c`, `0x004221c9`, and `0x004221fd` for cache path formatting.
- `stack_frame 0x00504b90` shows `var_628`, `pszPath`, and `Buffer` at `0x30`, `0x238`, and `0x440`, again separated by `0x208` bytes. The disassembly calls [UID:0002UA] at `0x00504bee`, `0x00504c2d`, and `0x00504c71` for `NexusTK`, `NexusTK\Maps`, and final map file path construction.
- `stack_frame 0x00557aa0` shows wide locals separated by `0x208` bytes, including `var_90C`, `pszPath`, and `var_20C`. The disassembly calls [UID:0002UA] at `0x00557ae7`, `0x00557b28`, and `0x00557bcd`, while the same caller also uses [UID:0003X8] `WideFormatWrapper256` for a 256-character timestamp filename. This mixed use in one caller supports fixed-count CRT/header specializations selected by destination buffer size, not one hand-authored `StringUtil` policy helper.

Same-family wrapper evidence:

- Current MCP `analyze_batch` confirms [UID:00030V] `0x00421230-0x0042125d` fixed count `0x20`, [UID:00030X] `0x00421260-0x00421290` fixed count `0x80`, [UID:0002UA] fixed count `0x104`, and [UID:0003X8] `0x0045ef20-0x0045ef50` fixed count `0x100` all share the same body shape: local stdio options accessor, `___stdio_common_vswprintf_s`, null locale, fixed destination count, and negative-result normalization.
- [UID:00030V] is already corrected to `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/code as reviewed non-emitting MSVC/UCRT fixed-32 support.
- [UID:00030X] is already corrected to `90/91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/code as reviewed non-emitting MSVC/UCRT fixed-128 support.
- [UID:0003X8] still has stale `StringUtil` reconstructable metadata, but current MCP evidence is sufficient to reject it as a positive precedent for [UID:0002UA]. Its own metadata repair is implementation-ready as a separate target or supervisor-expanded sibling callback, but it is not a blocker for correcting [UID:0002UA].

UCRT/source-shape evidence:

- `corecrt_stdio_config.h` lines 89-92 define `__local_stdio_printf_options` as a noinline inline function returning static options storage; line 110 defines `_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS` through that accessor. This matches [UID:0000WO] `sub_41B9A0`.
- `corecrt_wstdio.h` lines 1017-1024 declare `__stdio_common_vswprintf_s` with options, destination buffer, destination count, format, locale, and `va_list`.
- `corecrt_wstdio.h` lines 1246-1262 define the locale-aware secure wide `va_list` wrapper through `__stdio_common_vswprintf_s` and normalize negative results to `-1`.
- `corecrt_wstdio.h` lines 1268-1279 route the non-locale secure wide `va_list` wrapper through the locale-aware helper with null locale.
- `corecrt_wstdio.h` lines 1493-1508 and 1515-1529 show the varargs wrappers building a `va_list`, forwarding through the secure `va_list` path, ending the list, and returning the result.
- I am not claiming that the local Windows Kit is the exact original compiler header version. It is source-shape evidence that fully explains the observed binary mechanics and matches the already-accepted [UID:00030V]/[UID:00030X] precedent.

## Heuristic And Inference Reanalysis

The old [UID:0000OB] `StringUtil` route was defensible when the strongest evidence was broad caller fan-in. It is no longer the best source-quality decision. The function body has no NexusTK state, no helper policy beyond the fixed destination count, no string utility layout access, no class/global/vtable route, and no unique project-side behavior. The fixed count now has direct caller-local evidence: representative callers allocate 260-wide stack destinations, and the target passes `0x104` as the secure formatter destination count.

The target is also not just "unresolved helper naming." Current evidence resolves the source shape as compiler/runtime/header support generated or retained for caller-local secure wide formatting. Treating it as a reconstructable `StringUtil` emitter would invent a project helper API and would make the source tree carry CRT/UCRT wrapper code that the rebuild should obtain from compatible toolchain support.

The broad caller fan-in remains useful, but its meaning changes. It rejects fitting-room-private ownership; it does not prove a human-authored shared helper. In the same-family evidence, broad fan-in is expected when identical CRT/header wrapper specializations are emitted or retained and then reused across translation units.

## Positive Evidence

- Exact target function is small, complete, unique, and fully modeled by MCP at `0x004236e0-0x00423710`.
- The entire body is explained by the CRT local options accessor plus secure wide `va_list` formatting wrapper.
- Fixed count `0x104` matches 260-wide-character caller-local path buffers in representative fitting-room, map, and screenshot callers.
- [UID:00030V] and [UID:00030X] establish accepted current-project precedent for reclassifying same-body fixed-count secure wide-format wrappers as non-emitting MSVC/UCRT support.
- The target has broad product caller fan-in, which supports "not owned by one product module" but does not support emitted `StringUtil` source.
- Boundary evidence is exact: nine leading `0xcc` bytes after the previous function and clean successor start at [UID:0002UB] `0x00423710`.

## Negative Evidence

- No data xrefs to the function start.
- No little-endian VA/RVA byte patterns for the target or successor boundary.
- No import-table entry for `__stdio_common_vswprintf_s`; the relevant support is statically linked CRT/UCRT code.
- No `StringUtil`, `SimpleUString`, `StringBase`, vector, item-state, map, screenshot, profile, or application state is read or written by this target.
- No source-visible helper name is proven by symbols, strings, RTTI, vtables, callback tables, or globals.
- Physical adjacency to [UID:0002EE] fitting-room category helpers is weak evidence because [UID:0002UA] has many non-fitting-room callers and its body is identical to other CRT fixed-count formatting support.

## Ranked Ownership And Source Placement

1. `NONE` / non-emitting MSVC/UCRT secure wide-format support: strongest. The body is entirely local-stdio-options plus `__stdio_common_vswprintf_s`; fixed `0x104` is a destination count; callers own the formatting expressions.
2. [UID:0000OB] `StringUtil`: rejected as the direct owner/emitter. It remains a historical/cross-reference page for the old family bucket, but emitting a `StringUtil` wrapper would invent a NexusTK API not proven by current evidence.
3. [UID:0000JE] `FittingRoom`, [UID:000051] `FittingRoomDialogItemState`, and [UID:0002EE] `FittingRoomCategoryStorageAndStringHelpers`: rejected. Fitting-room consumes the support in cache-path construction, but the target has broad map/profile/settings/screenshot callers and no fitting-room state.
4. MapPane, SurfacePresentation/Screenshot, Profile/legacy import, SaveUserSettings, minimap/map helpers: rejected. These are consumers with caller-local path buffers; none owns the support artifact.
5. [UID:0000WO] `CrtStdioCommonSprintfGlue`: dependency, not project owner. It proves runtime/CRT routing but should remain separate non-reconstructable support.
6. New `WideFormatWrapper`, `FormatWide260`, `StringFormatHelpers`, or caller-agnostic helper source file: rejected. These names describe the binary artifact, not a defended original NexusTK source abstraction.

## Score And Metadata Recommendation

Recommended target metadata for [UID:0002UA]:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `90` | Exact MCP function, body, bytes, unique signature, boundaries, full xref set, caller-local buffer evidence, negative route checks, sibling precedent, UCRT source-shape evidence, owner repair, and no-code proof are now documented. |
| `CONFIDENCE` | `88` | `92` | Current session `80de0a67` proves the binary facts and accepted sibling pages prove the project precedent. Confidence stays below final because the exact original compiler/header version and exact caller source text are unavailable. |
| `CANONICAL_OWNER` | `0000OB` | `NONE` | No NexusTK source owner should emit this CRT/header support helper. |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` | The range should be regenerated or supplied by compatible CRT/header/toolchain behavior, not reconstructed as handwritten NexusTK source. |
| `EMITTER_UIDS` | `0000OB` | blank | No project source file should emit this target. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No emitter route. |
| `RECONSTRUCTION_CPP CODE` | blank | blank | No formal C++ block should be inserted. |

## C++ / No-Code Disposition

No C++ is recommended. The formal `RECONSTRUCTION_CPP CODE` block should remain empty.

Target-specific no-code proof:

- The target is pure CRT/UCRT secure wide-format support: local printf-options accessor, common secure wide-format backend, null locale, destination count, `va_list`, and negative-result normalization.
- The fixed count `0x104` is explained by caller-local 260-wide-character buffers.
- The target has no NexusTK-owned state, policy, type layout, resource, packet, UI field, or virtual dispatch behavior.
- No data/pointer/callback route proves a source-visible project helper.
- The already-accepted [UID:00030V]/[UID:00030X] precedent says these same-body fixed-count wrappers should be rebuilt by expressing caller-local secure formatting and relying on CRT/header/toolchain support.

## Recommended Target And Support Doc Changes

Required if accepted:

- `by-memory/0x004236e0-0x00423710.WideFormatWrapper.md`
  - Change metadata to `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
  - Replace stale parent-gate/StringUtil assignment language with current MCP session `80de0a67` evidence: exact `sub_4236E0` size `0x30`, PE SHA-256, unique bytes, nine-byte predecessor padding, successor [UID:0002UB] boundary, 18-instruction body, two CRT callees, 48 code xrefs, zero data xrefs, no VA/RVA byte-route, caller-local 260-wide stack-buffer evidence, same-family [UID:00030V]/[UID:00030X] precedent, UCRT header source shape, owner rejections, score rationale, and no-code proof.

- `by-file/StringUtil.md`
  - Remove [UID:0002UA] from direct emitted `StringUtil` contents/routing and preserve it as superseded historical/cross-reference fixed-format support.
  - Keep `StringUtil` file metadata unless supervisor chooses a broader file score update; this target should no longer support `StringUtil` ownership.
  - Add that [UID:0002UA], like [UID:00030V] and [UID:00030X], is reviewed non-emitting MSVC/UCRT fixed-260 secure wide-format support. Mention [UID:0003X8] only as a stale sibling that should not be used as positive `StringUtil` precedent unless separately corrected.

- `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md`
  - Update [UID:0002UA] inventory/rebuild handling from "source-authored wrapper / runtime dependency" to "reviewed non-emitting CRT/UCRT fixed-260 secure-format support."
  - Preserve the aggregate's mixed/non-emitting status and use [UID:0002UA] as stronger evidence against forcing the island under FittingRoom or StringUtil wholesale.

- `by-meta/client_libraries.md`
  - Add [UID:0002UA] to the MSVC CRT/STL/UCRT support section beside [UID:00030V] and [UID:00030X], with current MCP session `80de0a67`, fixed count `0x104`, 48 code xrefs, caller-local 260-wide buffers, callee pair, negative-result normalization, and no standalone project source.

- `by-memory/-ignored.md`
  - Add or update an ignored-entry note for [UID:0002UA] as reviewed non-emitting MSVC/UCRT secure wide-format fixed-260 support.

Caller/support sync if accepted and stale wording remains:

- `by-memory/0x00422020-0x0042232a.FittingRoomDialogItemStateConstructor.md`
- `by-memory/0x00422920-0x004229ef.FittingRoomDialogItemStateBuildCacheFilePathRaw.md`
- `by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md`
- `by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md`
- `by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md`
- `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`
- `by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md`
- `by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md`

For those caller pages, keep caller behavior and format strings but describe [UID:0002UA] as non-emitting CRT/header fixed-260 secure formatting support consumed by caller-local path buffers, not as a source-owned `StringUtil` helper. If a caller page only says "formats fixed-size wide path buffers" without ownership claims, it can be marked already sufficient.

Explicit non-scope note:

- [UID:0003X8] `by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md` is a same-family stale sibling. Current MCP evidence supports a similar non-emitting repair, but this report's accepted implementation should not silently rewrite [UID:0003X8] metadata unless the supervisor expands scope. It should be recorded as a separate implementation-ready sibling repair, not a blocker for [UID:0002UA].

## Expected Validators After Implementation

Run validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for each changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0002UA-WideFormatWrapper-source-quality-removed.md](0002UA-WideFormatWrapper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also validate any caller support page changed during an accepted callback with the same scoped validator command shape.

## Supervisor-Owned Coverage Text

Do not edit any `-coverage-report.md` file. If accepted, supervisor can replace the [UID:0002UA] row in `by-memory/-coverage-report.md` with:

```markdown
            - [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md) 0x004236e0-0x00423710 | helper-function | WideFormatWrapper : ignored : 90% : very strong : B005 2026-06-24 current MCP session `80de0a67` resolves this as reviewed non-emitting MSVC/UCRT secure wide-format fixed-260 support consumed by fitting-room, map/minimap, profile/settings, and screenshot path-formatting callers. Evidence confirms exact `sub_4236E0` 0x30-byte body, fixed count `0x104`, callee pair [UID:0000WO][0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue](by-memory/0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue.md) and `___stdio_common_vswprintf_s`, negative-result normalization, unique body signature, nine-byte predecessor padding, successor boundary at [UID:0002UB][0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper](by-memory/0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md), 48 code xrefs across 12 modeled functions plus raw call sites, zero data xrefs, no VA/RVA pointer byte route, caller-local 260-wide stack-buffer evidence, and same-family UCRT/header source shape proven by [UID:00030V][0x00421230-0x0042125d.WideFormatWrapper32](by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md) and [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md). Rebuild caller methods with caller-local secure wide formatting and rely on CRT/header/toolchain support; no standalone NexusTK `StringUtil`, fitting-room, aggregate, or formal C++ helper body.
```

## Blockers

No MCP or evidence blocker remains for [UID:0002UA]. The only remaining uncertainty is the exact original compiler/header version and exact caller source spelling; that uncertainty does not block the recommended non-emitting metadata repair because the binary body and accepted same-family precedent already prove the no-project-emitter disposition.

The stale [UID:0003X8] sibling is not a blocker. It is a separate implementation-ready same-family repair if the supervisor wants the fixed-256 page corrected in a later callback.

## Implementation Tracking Checklist

Implementation state after accepted callback: checked. B005 edited only the accepted target/support docs and this report. No `-coverage-report.md` file was edited.

- [x] Updated [UID:0002UA] target metadata to `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/position, blank formal C++.
  - Proof: `by-memory/0x004236e0-0x00423710.WideFormatWrapper.md` header now has `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and empty formal `RECONSTRUCTION_CPP CODE`.

- [x] Rewrote [UID:0002UA] target prose with MCP session `80de0a67`, PE SHA-256, exact bytes/range/padding, function body, callers/xrefs, callees, caller-local buffer proof, pointer/data negatives, UCRT source-shape evidence, sibling precedent, owner rejections, score rationale, and no-code proof.
  - Proof: target sections `2026-06-24 B005 Reclassification`, `MCP And File Provenance`, `Function And Boundary Evidence`, `Body And Callee Evidence`, `Xrefs And Caller Buffer Evidence`, `Negative Route Evidence`, `Same-Family And UCRT Source-Shape Evidence`, `Ownership And Rejected Alternatives`, `Score Rationale`, and `No-Code Proof` now carry the accepted details. The stale generated `Item Summary` was corrected after the normal validator reintroduced the old parent-gate text.
  - Validator normal command: `python .\tools\validator.py --mode file --file by-memory\0x004236e0-0x00423710.WideFormatWrapper.md --apply --queue-timeout 240`; `command_id:000000000519`; `command_timestamp:2026-06-24T15:41:44-04:00`; exit `0`; `ok:1`; warnings: none printed; side effects: `completion_update`, `confidence_update`, `canonical_owner_update`, `autogen_registry_update`, UID link/reference-index updates, stats row removal from `by-memory_Reconstructable`, `projected_stats_update`, `generated_refresh: deferred`.
  - Corrective validator after initial summary repair: `python .\tools\validator.py --mode file --file by-memory\0x004236e0-0x00423710.WideFormatWrapper.md --apply --no-generated-refresh --queue-timeout 240`; `command_id:000000000532`; `command_timestamp:2026-06-24T15:46:05-04:00`; exit `0`; `ok:1`; warnings: none printed; side effects: UID link inserts, `stats_incremental_noop`, `projected_stats_update`, `generated_refresh: skipped`.
  - Generated-refresh flush after deferred jobs later reset the target/aggregate summaries: `python .\tools\validator.py --mode file --file by-memory\0x004236e0-0x00423710.WideFormatWrapper.md --apply --wait-generated --queue-timeout 240`; `command_id:000000000537`; `command_timestamp:2026-06-24T15:49:07-04:00`; exit `0`; `ok:1`; warnings/side effects included `missing_ref_uid` for excluded stale sibling [UID:0003X8], broad pre-existing `autogen_registry_stale` / `memory_coverage_metadata_missing_file` generated-refresh warnings, `memory_auto_coverage_update` for `auto-generated/-ag-coverage-report-by-memory.md`, and `generated_refresh: completed`.
  - Final target full validator after generated flush: `python .\tools\validator.py --mode file --file by-memory\0x004236e0-0x00423710.WideFormatWrapper.md --apply --no-generated-refresh --queue-timeout 240`; `command_id:000000000539`; `command_timestamp:2026-06-24T15:49:39-04:00`; exit `0`; `ok:1`; warnings: six `missing_ref_uid 0003X8` warnings because [UID:0003X8] is excluded/stale in this callback; side effects: `insert_header_blank`, `stats_incremental_noop`, `projected_stats_update`, `generated_refresh: skipped`. This full validator still used the stale coverage/default summary, so the final accepted Item Summary was restored afterward.
  - Final target reference-only validator preserving the accepted summary: `python .\tools\validator.py --mode file --file by-memory\0x004236e0-0x00423710.WideFormatWrapper.md --apply --reference-only --no-generated-refresh --queue-timeout 240`; `command_id:000000000543`; `command_timestamp:2026-06-24T15:50:34-04:00`; exit `0`; `uid phase:False`, `reference phase:True`; warnings: six `missing_ref_uid 0003X8` warnings; side effects: UID link inserts for [UID:00030V]/[UID:00030X], `generated_refresh: skipped`. Final source recheck confirmed the target Item Summary is the accepted non-emitting MSVC/UCRT summary.
  - Post-drain final target reference-only validator after confirming `tools/validator_queue/jobs` and `tools/validator_queue/processing` were empty: `python .\tools\validator.py --mode file --file by-memory\0x004236e0-0x00423710.WideFormatWrapper.md --apply --reference-only --no-generated-refresh --queue-timeout 240`; `command_id:000000000549`; `command_timestamp:2026-06-24T15:52:43-04:00`; exit `0`; `uid phase:False`, `reference phase:True`; warnings: six `missing_ref_uid 0003X8` warnings; side effects: UID link inserts for [UID:00030V]/[UID:00030X], `generated_refresh: skipped`. Five-second post-validation recheck showed `jobs=0 processing=0` and the target Item Summary still had the accepted non-emitting MSVC/UCRT wording.

- [x] Updated `by-file/StringUtil.md` to remove [UID:0002UA] from direct emitted contents and preserve it as superseded historical/cross-reference fixed-format support.
  - Proof: `Likely Contents`, `Current Ownership Map`, `Evidence`, `Scope Exclusions`, `Score Rationale`, and `Changes` now classify [UID:0002UA] with [UID:00030V]/[UID:00030X] as reviewed non-emitting MSVC/UCRT fixed-format support, and [UID:0003X8] is only a stale sibling note rather than positive `StringUtil` precedent.
  - Validator command: `python .\tools\validator.py --mode file --file by-file\StringUtil.md --apply --queue-timeout 240`; `command_id:000000000521`; `command_timestamp:2026-06-24T15:41:52-04:00`; exit `0`; `ok:1`; warnings: none printed; side effects: UID link inserts, reference-index additions, `stats_incremental_noop`, `projected_stats_update`, `generated_refresh: deferred`.

- [x] Updated `by-memory/0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md` so the [UID:0002UA] row is non-emitting CRT/UCRT support and strengthens the aggregate mixed-routing proof.
  - Proof: `Item Summary`, `Status`, `Rebuild Handling`, `Function Inventory`, `2026-06-08 Parent-Source Follow-Up`, new `2026-06-24 B005 [UID:0002UA] Source-Quality Sync`, `Reconstruction Notes`, and `Changes` now describe [UID:0002UA] as reviewed non-emitting fixed-260 CRT/UCRT support and keep the aggregate `85/87`, owner `NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/code.
  - Validator normal command: `python .\tools\validator.py --mode file --file by-memory\0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md --apply --queue-timeout 240`; `command_id:000000000527`; `command_timestamp:2026-06-24T15:44:06-04:00`; exit `0`; `ok:1`; warnings: none printed; side effects: UID link inserts, reference-index additions, stats row updates for `0002EE`, `projected_stats_update`, `generated_refresh: deferred`.
  - Summary retry normal validator: same command; `command_id:000000000529`; `command_timestamp:2026-06-24T15:44:50-04:00`; exit `0`; `ok:1`; warnings: none printed; side effects: `insert_header_blank`, UID link insert, stats row updates, `projected_stats_update`, `generated_refresh: deferred`. This normal run still regenerated the stale summary.
  - Corrective validator after initial durable summary repair: `python .\tools\validator.py --mode file --file by-memory\0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md --apply --no-generated-refresh --queue-timeout 240`; `command_id:000000000531`; `command_timestamp:2026-06-24T15:45:28-04:00`; exit `0`; `ok:1`; warnings: none printed; side effects: `insert_header_blank`, UID link insert, stats row updates, `projected_stats_update`, `generated_refresh: skipped`.
  - Final aggregate validator after generated flush and summary repair: `python .\tools\validator.py --mode file --file by-memory\0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md --apply --no-generated-refresh --queue-timeout 240`; `command_id:000000000540`; `command_timestamp:2026-06-24T15:49:48-04:00`; exit `0`; `ok:1`; warnings: pre-existing stale renamed child-link warnings for [UID:0002U5], [UID:0002U6], and [UID:0002U9], plus `missing_ref_uid 0003X8`; side effects: `insert_header_blank`, `canonical_owner_update`, `autogen_registry_update`, UID link insert, `stats_incremental_noop`, `projected_stats_update`, `generated_refresh: skipped`. Final source recheck confirmed the aggregate Item Summary is the accepted mixed/non-emitting summary.
  - Post-drain final aggregate reference-only validator after confirming the generated queue was empty: `python .\tools\validator.py --mode file --file by-memory\0x00423000-0x00423af4.FittingRoomCategoryStorageAndStringHelpers.md --apply --reference-only --no-generated-refresh --queue-timeout 240`; `command_id:000000000550`; `command_timestamp:2026-06-24T15:52:49-04:00`; exit `0`; `uid phase:False`, `reference phase:True`; warnings: pre-existing stale renamed child-link warnings for [UID:0002U5]/[UID:0002U6] plus `missing_ref_uid 0003X8`; side effects: UID link insert for [UID:0002UA], `generated_refresh: skipped`. Five-second post-validation recheck showed `jobs=0 processing=0` and the aggregate Item Summary still had the accepted mixed/non-emitting wording.

- [x] Updated `by-meta/client_libraries.md` with [UID:0002UA] fixed-260 CRT/UCRT support alongside [UID:00030V]/[UID:00030X].
  - Proof: the MSVC CRT/STL/Dinkumware support section now includes a B005 paragraph with session `80de0a67`, PE SHA-256, exact `sub_4236E0` size `0x30`, fixed count `0x104`, 48 code xrefs, caller-local 260-wide buffers, callee pair, negative-result normalization, no VA/RVA pointer-byte route, and no standalone project source.
  - Validator command: `python .\tools\validator.py --mode file --file by-meta\client_libraries.md --apply --queue-timeout 240`; `command_id:000000000522`; `command_timestamp:2026-06-24T15:42:05-04:00`; exit `0`; `ok:1`; warnings: none printed; side effects: reference-index additions, `stats_incremental_noop`, `projected_stats_update`, `generated_refresh: deferred`.

- [x] Updated `by-memory/-ignored.md` with [UID:0002UA] reviewed non-emitting fixed-260 support.
  - Proof: new ignored entry after [UID:00030X] records why the range is ignored, MCP/session/hash/body/boundary evidence, 48 code xrefs, zero data/pointer route, caller-local 260-wide stack buffers, sibling precedent, replacement/procurement path, and owner/support docs.
  - Validator command: `python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --queue-timeout 240`; `command_id:000000000523`; `command_timestamp:2026-06-24T15:42:15-04:00`; exit `0`; `ok:1`; warnings: none printed; side effects: reference-index additions, `stats_incremental_noop`, `projected_stats_update`, `generated_refresh: deferred`.

- [x] Checked listed caller support pages and updated only stale ownership/helper wording where accepted scope required it.
  - Proof: `rg -n "0002UA|WideFormatWrapper|StringUtil"` over the listed caller pages found behavior-only [UID:0002UA] formatting descriptions in `MapPaneLoadCompressedMapFile.md` and `MapPaneSaveCompressedMapFile.md`, and no StringUtil/project-owner claim in `FittingRoomDialogItemStateConstructor.md`, `FittingRoomDialogItemStateBuildCacheFilePathRaw.md`, `SaveUserSettings.md`, `ScreenshotJpegCapturePath.md`, or `ScreenshotCaptureAndProof.md`. `ProfileLoadAndLegacyImport.md` still has an existing source sketch shorthand `WideFormatWrapper(path, ...)`, but it does not carry a [UID:0002UA] owner route or `StringUtil` claim; changing another target's formal/source sketch code is outside this accepted callback. The target, `StringUtil`, aggregate, `client_libraries`, and `-ignored` pages now carry the authoritative non-emitting correction.

- [x] Did not edit `by-memory/-coverage-report.md`; the exact replacement row above remains supervisor-owned.
  - Proof: no coverage-report file was opened for editing. Validator-generated stats/projected side effects were produced only by scoped validators; no manual generated/project-level edits were made.

- [x] Ran scoped validators for every changed by-* doc from `source-3/project-documentation` and recorded command, exit code, ok count, warnings, generated side effects, command ID, and timestamp above.

- [x] Released/confirmed no B005 leases after implementation.
  - Proof: first batch lease command succeeded for target/StringUtil/client_libraries/-ignored; `unlease` after validation reported `Rejected[No active lease]`, so no B005 lease remained for those files. Aggregate lease retry succeeded after the initial conflict and was released successfully. Target summary correction lease was released successfully. Final `current_leases.md` showed no B005 rows; only expired 2026-06-18 Supervisor rows remain in the generated lease report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002UA-WideFormatWrapper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002UA-WideFormatWrapper-source-quality.md","timestamp":"2026-06-24T15:56:31","uid":"0002UA"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002UA-WideFormatWrapper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0002UA-WideFormatWrapper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002UA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
